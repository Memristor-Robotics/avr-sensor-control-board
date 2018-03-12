#include "PwmBrushless.h"

static void PWM_SetDuty(uint16_t promil);

void Brushless_Init(void) {

  Pin_SetMode(&Pin_B5, PIN_OUTPUT);

  TCCR1A = (1 << COM1A1) | (1 << WGM11);
  TCCR1B = (1 << WGM13);
  ICR1 = MAX_OCR;
  TCCR1B |= (1 << CS11);


  PWM_SetDuty(50);
  _delay_ms(2000);

}
// duty cycle (0 pr-1000 pr)
void PWM_SetDuty(uint16_t promil) {

  if(promil > 100) {
    promil = 100;
  } else if(promil < 50) {
    promil = 50;
  }

  uint16_t duty = 20 * promil;

  OCR1A = duty;

}

// speed (50 pr - 100 pr)
void Brushless_Update(uint8_t speed) {

  size_t i = 0;

  //NewSpeed = speed;

  if(speed > CurrentSpeed) {
      for(i = CurrentSpeed; i < speed; i++) {
          PWM_SetDuty((uint16_t)(50 + (50.0 / 255.0) * i + 0.5));
          _delay_ms(20);
        }
  } else if(speed < CurrentSpeed) {
      for(i = CurrentSpeed; i > speed; i--) {
        PWM_SetDuty((uint16_t)(50 + (50.0 / 255) * i));
        _delay_ms(20);
      }
  } else {
    PWM_SetDuty((uint16_t)(50 + (50.0 / 255) * speed));
  }

  CurrentSpeed = speed;

}
