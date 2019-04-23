/*
 * REMDHA.c
 *
 * Created: 12.04.2019 15:55:21
 * Author : nbarben
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/twi.h>
#include <stdbool.h>
#include "i2c_master.h"
#include "sensor.h"
int pressed = 0;
int volume = 0;
int volumedelay = 0;

ISR (TIMER0_COMPA_vect)    // Timer1 ISR (5ms)
{
	read_gesture();
	if (((PORTD & 0x01)||(PORTD & 0x02)||(PORTC & 0x02)||(PORTC & 0x04)||(PORTC & 0x08)) == 1)
	{
		pressed++;
	}
	if (pressed == 40)		//200ms
	{
		PORTC &= ~0x0E;
		PORTD &= ~0x03;
		pressed = 0;	
	}
	if(volumedelay == 40)
	{
		volume = encoder(volume);
		volumedelay = 0;
	}
	else
	{
		volumedelay++;
	}
}

int main(void)
{
	init();
	DDRD = 0xC7;		//set Data Direction Register for output pins
	DDRC = 0x0F;
	
    while (1) 
    {
    }
}

