#include <arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>

bool ledstate;

ISR(INT1_vect) //create ISR for INT1 (pin 3)
{
  ledstate = HIGH;
  digitalWrite(LED_BUILTIN, ledstate);
}
ISR(INT0_vect){ //creaet ISR for PCINT0 (pin 2)
  ledstate = LOW;
  digitalWrite(LED_BUILTIN, ledstate);
}

int main(void)
{
pinMode(LED_BUILTIN, OUTPUT);
pinMode(2, INPUT_PULLUP);
pinMode(3, INPUT_PULLUP);

  // Enable Pin Change Mask for arduino pin 2 and 3
  EICRA |= (1 << ISC11);
  EIMSK |= (1<< INT0);

  EICRA |= (1<< ISC01);
  EIMSK |= (1<< INT1);
  sei();
  while (1)
  {
    // do nothing
  }
  return 0;
}