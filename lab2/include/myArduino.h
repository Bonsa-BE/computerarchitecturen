#ifndef myArduino_h
#define myArduino_h
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include <avr/pgmspace.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define HIGH 0x1
#define LOW 0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

void pinMode(volatile uint8_t *pin, uint8_t mode)
{
    if (mode == OUTPUT)
    {
        *pin = *pin | (1 << 5); /*hardcoded for internal led*/
    }

    else if (mode == INPUT)
    {
        *pin = *pin & ~(1 << 5); /*hardcoded for internal led*/
    }
    else if (mode == INPUT_PULLUP) /*hardcoded for button on PB4*/
    {
        *pin = *pin & ~(1 << 4);
        
        //*pin |= (1 << 4); // Optional: Enable internal pull-up resistor on PB4
        
    }

}

void digitalWrite(volatile uint8_t *pin, uint8_t val)
{
    if (val == HIGH)
    {
        *pin = *pin | (1 << 5);
    }

    else if (val == LOW)
    {
        *pin = *pin & ~(1 << 5);
    }
}
int digitalRead(volatile uint8_t *reg, volatile uint8_t *port, int pin)
{
    return (*reg & (1 << pin)) ? HIGH : LOW;
}
#endif