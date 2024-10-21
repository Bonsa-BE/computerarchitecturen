#include <arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(PCINT2_vect) // create ISR for PCINT1 (PCINT8-PCINT14)
{
  if (digitalRead(PD5) == LOW)
  {
    digitalWrite(PB2, HIGH);
  }
  else if (digitalRead(PD7) == LOW)
  {
    digitalWrite(PB2, LOW);
  }
}

int main()
{
  pinMode(PB2, OUTPUT); // pin gpio10
  pinMode(PD7, INPUT_PULLUP);   // pin gpio7
  pinMode(PD5, INPUT_PULLUP);   // pin gpio5

  digitalWrite(PB2, HIGH);

  PCICR |= (1 << PCIE2);  // enable logic change detection for INT2 vector
  PCMSK2 |= (1 << PCINT21) | (1 << PCINT23);  // enable interrupt on pcint21 (pin 5) and pcint23 (pin 7)

  sei(); // enable global interrupts

  while (1)
  {
    // do nothing
  }
  return 0;
}
