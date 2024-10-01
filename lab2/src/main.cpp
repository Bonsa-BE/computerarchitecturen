#include <avr/io.h>
#include <util/delay.h>
#include <myArduino.h>
/*
portB data register: 0x24 (hoog/laag)
portB DDR : 0x25 (input/output)
portB input register : 0x23 (uitlezen waarde)
*/
int main(void)
{
  pinMode(0x25, (1 << DDB5) | DDRB);
  while (1)
  {
    /*toggle led on*/
    /* PORTB = (1 << PB5) | PORTB;*/
    digitalWrite(0x24, (1 << PB5) | PORTB);
    /*sleep*/
    _delay_ms(1000);
    /*toggle led off*/
    digitalWrite(0x24, PORTB & ~(1 << PB5));
    /*PORTB = PORTB & ~(1 << PB5);*/
    /*foute lijn, verandert waarden aan register: PORTB = (0 << PB5) | PORTB;*/
    /*sleep*/
    _delay_ms(1000);
  }
}