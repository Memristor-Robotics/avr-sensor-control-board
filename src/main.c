#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "uart0.h"
#include "Pin.h"
#include "BinarySensor.h"
#include "PwmBrushless.h"
#include "ADC.h"
#include "Config.h"


int main() {

  size_t i;

  USART0_init(57600);

  Brushless_Init();

  USART0_transmit('k');

  while(1) {

      Brushless_Update(USART0_receive());
      USART0_transmit('s');
      _delay_ms(1000);

  }

  return 0;
}
