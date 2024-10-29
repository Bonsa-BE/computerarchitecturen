#include <avr/io.h>
#include <avr/interrupt.h>

// 8-bit timer
volatile uint16_t counter = 0; // counter for overflows
ISR(TIMER0_OVF_vect)
{
  counter++;
  if (counter >= 976)
  {                      // every 976 overflows, toggle LED
    PORTB ^= (1 << PB2); // LED toggle
    counter = 0;         // Reset counter
  }
}

int main(void)
{
  cli();                               // disable global interrupts
  DDRB |= (1 << PB2);                  // dramco uno builtin led as output
  TCCR0A = 0;                          // set WGM01 and WGM00 as 0 for normal mode
  TCCR0B |= (1 << WGM02);              // set WGM02 as 0 for normal mode
  TCCR0B |= (1 << CS01) | (1 << CS00); // Set prescaler 64
  TIMSK0 |= (1 << TOIE0);              // Set Timer0 overflow interrrupt
  sei();                               // Schakel globale interrupts in
  
  // formule: #klokken per overflow = (max_timer − TCNT0) * prescaler / f_cpu
  // ingevuld: 1 = (256 - TCNT0) * 64 / 16000000
  // TCNT0 = 249744 => 976 * 256 -> let overflow 976 times before taking action
  TCNT0 = 0;

  while (1)
  {
    // do nothing
  }
}

/* 10bit timer
// Interrupt Service Routine (ISR) voor Timer1 overflow
ISR(TIMER1_OVF_vect)
{
  PORTB ^= (1 << PB2); // toggle LED
  TCNT1 = 49910; //reset TCNT1
}
int main(void) {
//1. timer in normal mode -> WGM10, WGM11, WGM12 en WGM13 op 0 (2 verschillende registers!)
 TCCR1A &= ~(1<< WGM10);
 TCCR1A &= ~(1<< WGM11);
 TCCR1B &= ~(1<< WGM13);
 TCCR1B &= ~(1<< WGM12);
 //2. Stel prescaler op 1024: -> '101' voor prescaler in TCCR1B
 TCCR1B |= (1 << CS12) | (1 << CS10);
 //3. enable interrupt op overflow:
 TIMSK1 |= (1 << TOIE1);
 //4. voorzie TCNT0 zodat elke seconde de led getoggled wordt
 //formule: #klokken per overflow = (max_timer − TCNT1) * prescaler / f_cpu
 //ingevuld: 1 = (65535 - TCNT1) * 1024 / 16000000
 //TCNT1 = 49910
 TCNT1 = 49910;
 while(1){
 //do nothing
  }
 }*/