#include <avr/io.h>
#include <avr/interrupt.h>

// Interrupt Service Routine (ISR) voor Timer1 Compare Match A
ISR(TIMER1_COMPA_vect)
{
  PORTB ^= (1 << PB2); //toggle LED
}

int main()
{
  cli();
  DDRB |= (1 << PB2);//internal led Dramco UNO (D10) as OUTPUT
  // 1. Stel Timer1 in op CTC-modus (Clear Timer on Compare Match)
  // Schrijf '0100' in WGM12 (CTC-mode) door WGM12-bit te zetten in TCCR1B-register.
  TCCR1B |= (1 << WGM12);

  // 2. Stel de klokprescaler in op 1024
  // Schrijf '101' in de bits CS12, CS11, CS10 in het TCCR1B-register.
  TCCR1B |= (1 << CS12) | (1 << CS10); // CS12 en CS10 zetten

  // 3. Bereken de waarde voor de output compare (OCR1A) register
  // oorspronkelijke formule: F_out = F_CPU / (prescaler * (1 + OCR1A))
  // omgevormde formule: OCR1A = (F_CPU / (prescaler * gewenste_frequentie)) - 1
  // Voor een 1 seconde timer (frequentie = 1 Hz) en F_CPU = 16MHz:
  // OCR1A = (16000000 / (1024 * 1)) - 1 = 15624
  OCR1A = 15624; // Output compare waarde voor 1Hz (1 seconde)

  // 4. Sta de interrupt toe bij een output compare match (OCIE1A)
  // Activeer de output compare interrupt door OCIE1A te zetten in het TIMSK1-register.
  TIMSK1 |= (1 << OCIE1A);
  sei(); // enable global interrupts
  while (1)
  {
    // do nothing
  }
  return 0;
}
