#include "BinarySensor.h"

void BinarySensor_Add(Pin* pin) {
  Pin_SetMode(pin, PIN_INPUT);
}

bool ifSensorDetected(Pin* pin) {
  if (bit_is_set(*(pin->PINx), pin->Pxn)) {
    return true;
  } else {
    return false;
  }
}
