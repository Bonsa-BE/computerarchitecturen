#include <avr/io.h>
#include <util/delay.h>
#include "../include/myArduino.h"

int main(void)
{
 pinMode(13, OUTPUT);
  while (1)
  {
    digitalWrite(13, HIGH);
    _delay_ms(1000);
    digitalWrite(13, LOW);
    _delay_ms(1000);
  }
}