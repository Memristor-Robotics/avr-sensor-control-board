#include <avr/io.h>
#include <util/delay.h>
#include "CanBus.h"
#include "Uart.h"
#include "Pin.h"
#include "Config.h"


int main() {


#ifdef DEBUG
	char uart_char1, uart_char2;

	/* UART0 for DEBUG Initialisation */
	USART0_init(57600);
#endif

	sei();

	/*	Binary Sensors Initalisation	*/
	BinarySensor_Add(_pin_, 1);
	BinarySensor_Add(_pin_, 2);
	BinarySensor_Add(_pin_, 3);
	BinarySensor_Add(_pin_, 4);
	BinarySensor_Add(_pin_, 5);
	BinarySensor_Add(_pin_, 6);

	/* CANbus Initialisation */
	CANbus_Init();

  while(1) {

		BinarySensor_UpdateAll();

		if (can_check_message()) {
			can_t msg;

			if (can_get_message(&msg)) {



			}
		}
  }

  return 0;
}
