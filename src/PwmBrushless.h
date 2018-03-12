#ifndef _PWM_BRUSHLESS_H_
#define _PWM_BRUSHLESS_H_

#define MAX_OCR 20000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Pin.h"

static uint8_t CurrentSpeed = 0;

void Brushless_Init(void);

void Brushless_Update(uint8_t speed);

#endif
