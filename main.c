/*
 * GccApplication2.c
 *
 * Created: 28-07-2024 10.27.43 AM
 * Author : Speedyboy
 */ 
#define F_CPU 16000000UL // Define CPU frequency as 16 MHz

#include <avr/io.h>
#include <util/delay.h>

#define LedPin 4
#define ButtonPin 0
int main(void)
{
    DDRB |= (1<<LedPin); //led pin direction as an output
	DDRB &= ~(1<<ButtonPin); //Button pin direction as an input 
	
	PORTB |= (1<<ButtonPin);
	
    while (1) 
    {
		if (!(PINB & (1<<ButtonPin)))
		{
			
			PORTB &= ~(1<<LedPin);
		}
		else
		{
			PORTB |= (1<<LedPin);
		}
    }
	return 0;
}

