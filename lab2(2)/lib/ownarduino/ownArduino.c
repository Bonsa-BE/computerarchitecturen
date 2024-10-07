#include <stdint.h>
#include <avr/io.h>

#define DDRB (*(volatile uint8_t*)0x24)
#define INPUT  0
#define OUTPUT 1
#define INPUT_PULLUP 2

//#define volatile uint8_t* ddrB = (volatile uint8_t*) 0x24 // DDRB     niet globaal aanmaken maar in pinmode
//#define volatile uint8_t* portB = (volatile uint8_t*) 0x25 // PORTB

void ownPinMode(uint8_t pin, uint8_t mode){
    volatile uint8_t* ddrB;
    volatile uint8_t* portB;
   
    ddrB = (volatile uint8_t*)0x24;
    portB = (volatile uint8_t*)0x25; 
    switch (mode) {
            case INPUT:
                /*DDRB &= ~(1 << pin);   // Zet de bit in DDRB naar 0 (input)
                PORTB &= ~(1 << pin);  // Zet de pull-up uit*/
                *ddrB &= ~(1 << pin);
                *portB &= ~(1 << pin);
                break;
            case OUTPUT:
                //DDRB |= (1 << pin);    // Zet de bit in DDRB naar 1 (output)
                *ddrB |= (1 << pin);
                break;
            case INPUT_PULLUP:
                /*DDRB &= ~(1 << pin);   // Zet de bit in DDRB naar 0 (input)
                PORTB |= (1 << pin);   // Zet de pull-up aan*/
                *ddrB &= ~(1 << pin);
                *portB |= (1 << pin);
                break;
        }
}

void ownDigitalWrite(uint8_t pin, uint8_t value){
    volatile uint8_t* portB;
    portB = (volatile uint8_t*)0x25;
    if (value) {
        *portB |= (1 << pin);   // Zet de pin hoog (1)
    } else {
        *portB &= ~(1 << pin);  // Zet de pin laag (0)
    }
}

uint8_t ownDigitalRead(uint8_t pin){
    volatile uint8_t* statusB = (volatile uint8_t*)0x23;
    return (*statusB & (1 << pin)) ? 1 : 0;
}