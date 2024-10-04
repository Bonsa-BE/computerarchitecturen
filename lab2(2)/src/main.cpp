#include <avr/io.h>
#include <util/delay.h>
#include "myArduino.h"
/*
portB data register: 0x24 (hoog/laag)
portB DDR : 0x25 (input/output)
portB input register : 0x23 (uitlezen waarde)
*/
int main(void)
{
  volatile uint8_t *ddr = (volatile uint8_t *)0x24; // location of data direction register B
  volatile uint8_t *ior = (volatile uint8_t *)0x25; // location of output register B
  volatile uint8_t *pb = (volatile uint8_t *)0x23; // location of input register B
  pinMode(ddr, INPUT_PULLUP);
  digitalRead(pb, 4)
  while (1)
  {
    digitalWrite(ior, digitalRead(pb, 4)); 
  }
}