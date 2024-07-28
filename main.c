/*
 * main.c
 *
 * Created: 7/25/2024 10:24:05 PM
 *  Author: hp
 */ 
#include <util/delay.h>
#include <stdint.h>
#include <avr/io.h>
// #include <xc.h>

//PORTB
#define  BaseADDR	0x25
#define  PinADDR	0x23
#define  DrrADDR	0x24
#define	 PinNumber	5

//PORTC
// #define  BaseADDRC	0x28
// #define  PinADDRC	0x26
// #define  DrrADDRC	0x27
// #define	 PinNumberC	4
#define  PinPress   0
void Delay(unsigned int count);
int main(void)
{
	uint8_t *ledport = (uint8_t*)BaseADDR;
	uint8_t *ledpin = (uint8_t*)PinADDR;
	uint8_t *leddrr = (uint8_t*)DrrADDR;
	/*
	uint8_t *ledportC = (uint8_t*)BaseADDRC;
	uint8_t *ledpinC = (uint8_t*)PinADDRC;
	uint8_t *leddrrC = (uint8_t*)DrrADDRC;
	*/
	
	*ledport	|=	(1<<PinNumber);
	*ledport	|=	(1<<PinPress);
	*ledpin		|=	(1<<PinNumber);
	*ledpin		&=  ~(1<<PinPress);
	*leddrr		&=  ~(1<<PinPress);
	*leddrr		|=  (1<<PinNumber);
	
	
	
	// press button
	
/*
// 	*ledport	|=	(1<<PinNumber);
// 	*ledpin		|=	(1<<PinNumber);
// 	*leddrr		|=  (1<<PinNumber);
*/
	
	uint8_t var = 0x00000001;
    while(1)
    {
        //TODO:: Please write your application code 
// 		if (var & (*ledpin |= (1<<PinPress)))
// 		{
// 			_delay_ms(100);
// 			*ledpin		|=	(1<<PinNumber);
// 		}
	/*	*ledpin		&=	~(1<<PinNumber);*/
	*ledpin		|=	(1<<PinNumber);
	Delay(1000);
	*ledpin		&=	~(1<<PinNumber);
	Delay(1000);
	
	
    }
}
void Delay(unsigned int count)
{
	while (count--)
	{
		for (volatile unsigned int i = 0; i < count; i++) {
			// Busy-wait loop
			}
		
	}
}
