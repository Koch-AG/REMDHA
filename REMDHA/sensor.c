/*
 * sensor.c
 *
 * Created: 12.04.2019 16:11:33
 *  Author: nbarben
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "sensor.h"
#include "i2c_master.h"


unsigned char MGC3130read[] = {};					//array for received data from MGC3130



bool MGC3130Init(void)
{
	DDRB = 0x00;
	PORTB = 0x04;
	int32_t i = 0;
	while (((PINB >> 2) & 1) == 0)
	{
		i++;
		if(i>=1000) 
		{
			return false;
		}
	}
	return true;
}

bool MGC3130Read(void)
{
	if(((PINB >> 2) & 1) == 0)
	{
		DDRB = 0x04;
		PORTB = 0x00;
		i2c_start(MGC3130_ID_READ);
		MGC3130read[0] = i2c_read_ack();
		
		for(uint16_t i = 1; i < (MGC3130read[0]-1); i++)
		{
			MGC3130read[i] = i2c_read_ack();
		}
		MGC3130read[(MGC3130read[0]-1)] = i2c_read_nack();
		
		i2c_stop();
		DDRB = 0x00;
		PORTB = 0x04;
		int32_t i = 0;
		while (((PINB >> 2) & 1) == 0)
		{
			i++;
			if(i>=1000) 
			{
				return false;
			}
		}
		return true;
	} 
	else 
	{
		return false;
	}
}