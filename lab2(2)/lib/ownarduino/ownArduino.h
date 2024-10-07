#ifndef OWNARDUINO_H
#define OWNARDUINO_H
#include <stdint.h>
#include <ownArduino.c>

/*#ifdef cplusplus
extern "C" {
#endif*/

void ownPinMode(uint8_t pin, uint8_t mode);
void ownDigitalWrite(uint8_t pin, uint8_t value);
uint8_t ownDigitalRead(uint8_t pin);

/*#ifdef cplusplus
}
#endif*/

#endif