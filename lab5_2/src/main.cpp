#include <avr/io.h>
#include <avr/interrupt.h>
static int counter = 0;
ISR(TIMER0_COMPA_vect)
{
  counter ++;
  if(counter == 100){
    counter = 0;
    PORTB ^= (1 << PB2); // toggle LED
  }
  
}

int main(){
  cli();
  DDRB |= (1 << PB2); // internal led Dramco UNO (D10) as OUTPUT
  // 1. Timer 0 als CTC -> '0100' in TTCR0B
  TCCR0A |= (1 << WGM01);
  // 2. Stel prescaler op 1024: -> '101' voor prescaler in TCCR0B
  TCCR0B |= (1 << CS02) | (1 << CS00);
  //3. zoek waarde voor OCRA0
  // oorspronkelijke formule: F_out = F_CPU / (prescaler * (1 + OCR0A))
  // omgevormde formule: OCR0A = (F_CPU / (prescaler * gewenste_frequentie)) - 1
  // OCR0A = (16000000 / (1024 * 1)) - 1 = 15624
  OCR0A = 156; //ongeveer 1/100e van benodigde freq
  //4. stel interrupt in: zorg dat mask overeenkomt
  TIMSK0 |= (1 << OCIE0A);
  sei();
  while(1){
    //do nothing
  }
  return 0;
}

/* vb met 16bit timer
  DDRB |= (1 << PB2);//internal led Dramco UNO (D10) as OUTPUT
  // 1. Stel Timer1 in op CTC-modus -> maak WGM12 '1' in TCCR1B-register.
  TCCR1B |= (1 << WGM12);
  // 2. Stel de klokprescaler in op 1024 -> '101' voor CS12, CS11, CS10 in TCCR1B
  TCCR1B |= (1 << CS12) | (1 << CS10);
  // 3. Bereken de waarde voor de output compare (OCR1A) register
  // oorspronkelijke formule: F_out = F_CPU / (prescaler * (1 + OCR1A))
  // omgevormde formule: OCR1A = (F_CPU / (prescaler * gewenste_frequentie)) - 1
  // OCR1A = (16000000 / (1024 * 1)) - 1 = 15624
  OCR1A = 15624; // Output compare waarde voor 1Hz (1 seconde)
  // 4. gooi interrupt bij output compare match -> OCIE1A in TIMSK1
  TIMSK1 |= (1 << OCIE1A);
  */