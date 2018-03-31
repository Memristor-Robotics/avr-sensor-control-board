#ifndef _VACUUM_TEST_H_
#define _VACUUM_TEST_H_

#include <avr/io.h>
#include <stdint.h>

void Init_Pumps(void);
void Start_All_Pumps(void);
void Start_Pump(uint8_t selectPump);
void Stop_All_Pumps(void);
void Stop_Pump(uint8_t selectPump);


void Init_Vacuume_Switches(void);
void Open_All_Vacuume_Switches(void);
void Open_Vacuume_Switch(uint8_t selectSwitch);
void Close_All_Vacuume_Switches(void);
void Close_Vacuume_Switch(uint8_t selectSwitch);

#endif
