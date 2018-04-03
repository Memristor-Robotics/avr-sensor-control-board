#ifndef _BINARY_SENSOR_H_
#define _BINARY_SENSOR_H_

#include <stdint.h>
#include <can/can.h>
#include <can/can_wrapper.h>
#include "Utils.h"
#include "Pin.h"
#include "Config.h"

#ifndef BINARY_SENSOR_CONFIG_MAX
#define BINARY_SENSOR_CONFIG_MAX 10
#warning "Maximal number of binary sensors is not overriden"
#endif

typedef struct _BinarySensor {
    Pin* pin;
    uint16_t canId;
    uint8_t state;
} BinarySensor;


/**
 * Instance a new binary sensor and put it to binary sensor collection.
 * @example uint8_t sensorId = BinarySensor_Add(&PinC6, 0x8000);
 */ 
void BinarySensor_Add(Pin* pin, uint16_t canId);

/**
 * Check state of all binary sensors. Call this function in loop.
 * @example while (1) { BinarySensor_UpdateAll(); }
 */
void BinarySensor_UpdateAll(void);

#endif
