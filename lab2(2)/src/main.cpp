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
  volatile uint8_t *ddr = (volatile uint8_t *)0x24;
  volatile uint8_t *ior = (volatile uint8_t *)0x25;
  pinMode(ddr, INPUT_PULLUP);
  while (1)
  {
    if 
  }
}