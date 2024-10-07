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
  pinMode(ddr, OUTPUT);

  while (1)
  {
    /*toggle led on*/
    /* PORTB = (1 << PB5) | PORTB;*/
    digitalWrite(ior, HIGH);
    /*sleep*/
    _delay_ms(1000);
    /*toggle led off*/
    digitalWrite(ior, LOW);
    /*PORTB = PORTB & ~(1 << PB5);*/
    /*foute lijn, verandert waarden aan register: PORTB = (0 << PB5) | PORTB;*/
    /*sleep*/
    _delay_ms(1000);
  }
}