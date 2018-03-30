#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "CanBus.h"
#include "uart0.h"
#include "Pin.h"
#include "BinarySensor.h"
#include "PwmBrushless.h"
#include "VacuumPumps.h"
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

	char uart_char1, uart_char2;

	sei();

DDRB = 0xFF;
PORTB = 0x00;

	/* CANbus Initialisation */
	//CANbus_Init();

	/* UART0 for DEBUG Initialisation */
	USART0_init(57600);

	Init_Pumps();

	Init_Vacuume_Switches();
	/* Brushless EDF Initialisation on pin */
	//Brushless_Init(&Pin_B5);


	/* ALL Initialisations Passed and UART sends 'k' */
	USART0_transmit('k');

  while(1) {

		uart_char1 = USART0_receive();

		if (uart_char1 == 'c') {
			Stop_All_Pumps();
		} else if(uart_char1 == 'C') {
			Start_All_Pumps();
		} else if(uart_char1 == 'n') {
			Close_All_Vacuume_Switches();
		}	else if(uart_char1 == 'N') {
			Open_All_Vacuume_Switches();
		}

		//if (uart_char1 != 's' && uart_char1 != 'q') continue;
		if(!strchr("sqvV", uart_char1)) continue;

		uart_char2 = USART0_receive();

		if(uart_char2 >= '1' && uart_char2 <= '5') {

			uart_char2 -= 48;
			switch(uart_char1) {
				case 's':
						Start_Pump(uart_char2);
						break;
				case 'q':
						Stop_Pump(uart_char2);
						Open_Vacuume_Switch(uart_char2);
						_delay_ms(100);
						Close_Vacuume_Switch(uart_char2);
						break;
				case 'V':
						Open_Vacuume_Switch(uart_char2);
						break;
				case 'v':
						Close_Vacuume_Switch(uart_char2);
						break;
			}
			/*
			if(uart_char1 == 's') {
				//Open_Vacuume_Switch(uart_char2);

			} else if(uart_char2 ) {
				//Close_Vacuume_Switch(uart_char2);

				Open_Vacuume_Switch(uart_char2);
				_delay_ms(100);
				Close_Vacuume_Switch(uart_char2);
			}
			*/


		}

		/*

		if (can_check_message()) {
			can_t msg;

			if (can_get_message(&msg)) {

				Brushless_Update(&msg);

			}
		}*/
  }

  return 0;
}
