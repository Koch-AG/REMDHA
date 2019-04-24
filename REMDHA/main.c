/*
 * REMDHA.c
 *
 * Created: 12.04.2019 15:55:21
 * Author : nbarben
 */ 

#include <avr/io.h>							//include libraries
#include <avr/interrupt.h>
#include <util/twi.h>
#include <stdbool.h>
#include "i2c_master.h"
#include "sensor.h"

int pressed = 0;							//define variables
int volume = 0;
int volumedelay = 0;

ISR (TIMER0_COMPA_vect)						//Timer0 Output Compare Register A interrupt (5ms)
{
	read_gesture();
	if (((PORTD & 0x01)||(PORTD & 0x02)||(PORTC & 0x02)||(PORTC & 0x04)||(PORTC & 0x08)) == 1)	//if any output for a button is activated
	{
		pressed++;
	}
	if (pressed == 40)						//200ms
	{
		PORTC &= ~0x0E;						//reset all outputs for buttons
		PORTD &= ~0x03;
		pressed = 0;	
	}
	inputdelay();							//delay for detecting circle gestures more accurately
	if(volumedelay == 40)					//delay for setting volume
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
	DDRD = 0xC7;							//set Data Direction Register for output pins
	DDRC = 0x0F;
	#if SENSOR_SELECT == PAJ7620			//set LED to indicate sensor selection	
		LED2_ON;
	#elif SENSOR_SELECT == MGC3130 
		LED1_ON;
	#endif
	
    while (1) 
    {
		switch (process_gesture())
		{
			case CLOCKWISE:					//clockwise --> volume up
				volume = 1;
				break;
			case COUNTERCLOCKWISE:			//counterclockwise --> volume down
				volume = 2;
				break;
			case UP:						//up --> sonderfunktion
				FUNKTION;
				break;
			case DOWN:						//down --> Ruf-Aus
				RUFTON;
				break;
			case LEFT:						//left --> Licht
				LICHT;
				break;
			case RIGHT:						//right --> Gespräch
				SPRECHEN;
				break;
			case HOLD:						//hold/forward --> Türöffner
			case FORWARD:
				TOE;
				break;
		}
    }
}

