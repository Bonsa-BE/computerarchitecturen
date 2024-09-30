#include "../include/avr/io.h"
#include "../include/util/delay.h"

int main(void)
{
  DDRB = (1 >> DDB5) | DDRB;
  while (1)
  {
    /*toggle led on*/
    PORTB = (1 << PB5) | PORTB;
    /*sleep*/
    _delay_ms(1000);
    /*toggle led off*/
    PORTB = PORTB & ~(1 << PB5);
    /*foute lijn, verandert waarden aan register: PORTB = (0 << PB5) | PORTB;*/
    /*sleep*/
    _delay_ms(1000);
  }
}

/*The DDxn bit in the DDRx register selects the direction of this pin. If DDxn is written logic one, Pxn is configured as an output
pin. If DDxn is written logic zero, Pxn is configured as an input pin.
If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is activated. To switch the
pull-up resistor off, PORTxn has to be written logic zero or the pin has to be configured as an output pin. The port pins are
tri-stated when reset condition becomes active, even if no clocks are running.
If PORTxn is written logic one when the pin is configured as an output pin, the port pin is driven high (one). If PORTxn is
written logic zero when the pin is configured as an output pin, the port pin is driven low (zero).*/