#include <arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>

bool ledstate;

ISR(INT1_vect) //create ISR for INT1 (pin 3)
{
  ledstate = HIGH;
  digitalWrite(LED_BUILTIN, ledstate);
}
ISR(INT0_vect){ //create ISR for INT0 (pin 2)
  ledstate = LOW;
  digitalWrite(LED_BUILTIN, ledstate);
}

int main(void)
{
pinMode(LED_BUILTIN, OUTPUT);
pinMode(2, INPUT_PULLUP);
pinMode(3, INPUT_PULLUP);

  // Enable Pin Change Mask for arduino pin 2 and 3
  EICRA |= (1<< ISC11); //falling edge detection (alternatief: EICRA |= B00000100)
  EIMSK |= (1<< INT1); //enable INT0 (pin 2)

  EICRA |= (1<< ISC01); //falling edge detection (alternatief: EICRA |= B00000001)
  EIMSK |= (1<< INT0); //enable INT1 (pin 3)

  sei(); //enable global interrupts
  while (1)
  {
    // do nothing
  }
  return 0;
}