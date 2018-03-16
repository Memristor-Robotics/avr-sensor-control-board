#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "CanBus.h"
#include "uart0.h"
#include "Pin.h"
#include "BinarySensor.h"
#include "PwmBrushless.h"
#include "ADC.h"
#include "Config.h"



/*void HBridge_Add(Pin* inA, Pin* inB, Pin* inH, PinFrequency frequency) {

	Pin_SetMode(inA, PIN_OUTPUT);
	Pin_SetMode(inB, PIN_OUTPUT);
	Pin_SetMode(inH, PIN_OUTPUT);

	Pin_EnableAnalog(inA, frequency);
}
*/
int main() {

	char uart_char;

	sei();

	/* CANbus Initialisation */
	CANbus_Init();

	/* UART0 for DEBUG Initialisation */
  USART0_init(57600);

	/* Brushless EDF Initialisation on pin*/
  Brushless_Init(&Pin_B5);


  USART0_transmit('k');

  while(1) {

		if (can_check_message()) {
			can_t msg;

			if (can_get_message(&msg)) {

				Brushless_Update(&msg);

			}
		}
  }

  return 0;
}
