#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "uart0.h"
#include "Pin.h"
#include "BinarySensor.h"
#include "PwmBrushless.h"
#include "ADC.h"
#include "Config.h"

void HBridge_Add(Pin* inA, Pin* inB, Pin* inH, PinFrequency frequency) {

	Pin_SetMode(inA, PIN_OUTPUT);
	Pin_SetMode(inB, PIN_OUTPUT);
	Pin_SetMode(inH, PIN_OUTPUT);

	Pin_EnableAnalog(inA, frequency);
}

int main() {

	char uart_char;

	//HBridge_Add(&Pin_B5, &Pin_B2, &Pin_E2, PIN_20KHz);
  USART0_init(57600);

	//Pin_WriteAnalog(&Pin_B5, 50);
  Brushless_Init(&Pin_B5);

	_delay_ms(1000);

  //Pin_WriteDigital(&Pin_E2, PIN_HIGH);
	//Pin_WriteDigital(&Pin_E3, PIN_HIGH);

  USART0_transmit('k');

  while(1) {

		uart_char = USART0_receive();
    Brushless_Update(uart_char);
      USART0_transmit(uart_char);
      _delay_ms(1000);
/*
	Pin_WriteDigital(&Pin_B2, PIN_LOW);
	_delay_ms(2000);

	Pin_WriteDigital(&Pin_B2, PIN_HIGH);
	_delay_ms(2000);
*/

  }

  return 0;
}
