#ifndef BINARY_SENSOR_H_
#define BINARY_SENSOR_H_

#include <stdint.h>
#include <stdbool.h>
#include "Config.h"
#include "Pin.h"

void BinarySensor_Add(Pin* pin);

bool ifSensorDetected(Pin* pin);

#endif
