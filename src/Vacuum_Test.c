#include "Vacuum_Test.h"


void Init_Pumps(void){

	DDRC = 0xFF;

}

void Start_All_Pumps(void){

	PORTC = 0x3E;

}

void Start_Pump(uint8_t selectPump){

  PORTC |= (1 << selectPump);

}

void Stop_All_Pumps(void){

	PORTC = 0x00;

}

void Stop_Pump(uint8_t selectPump) {

	PORTC &= ~(1 << selectPump);

}


void Init_Vacuume_Switches(void){

	DDRA = 0xFF;

}

void Open_All_Vacuume_Switches(void){

	PORTB = 0xFF;
	PORTA = 0xFF;

}

// PORTA 6 4 2 1 PORTB 4

const uint8_t vacuum_switches[] = {0x24, 1, 2, 4, 6};
void Open_Vacuume_Switch(uint8_t selectSwitch){

	uint8_t v = vacuum_switches[selectSwitch-1];

	if(v > 0x20) {
		v &= 0x0f;
		PORTB |= (1<<v);
	} else {
		PORTA |= (1<<v);
	}

}

void Close_All_Vacuume_Switches(void){

	PORTA = 0x00;
	PORTB = 0x00;

}

void Close_Vacuume_Switch(uint8_t selectSwitch){

	uint8_t v = vacuum_switches[selectSwitch-1];

	if(v > 0x20) {
		v &= 0x0f;
		PORTB &= ~(1<<v);
	} else {
		PORTA &= ~(1<<v);
	}

}
