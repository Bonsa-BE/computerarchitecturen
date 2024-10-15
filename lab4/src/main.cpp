#include <arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(PCINT2_vect) // create ISR for PCINT1 (PCINT8-PCINT14)
{
  if (digitalRead(PD5) == LOW)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else if (digitalRead(PD7) == LOW)
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
}

int main()
{
  pinMode(LED_BUILTIN, OUTPUT); // pin gpio13
  pinMode(PD7, INPUT_PULLUP);   // pin gpio7
  pinMode(PD5, INPUT_PULLUP);   // pin gpio5

  digitalWrite(LED_BUILTIN, HIGH);

  PCICR |= (1 << PCIE2);  // enable logic change detection for INT2 vector
  PCMSK2 |= (1 << PCINT21) | (1 << PCINT23);  // enable interrupt on pcint21 (pin 5) and pcint23 (pin 7)

  sei(); // enable global interrupts

  while (1)
  {
    // do nothing
  }
  return 0;
}
