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

ISR (TIMER0_COMPA_vect)    // Timer1 ISR
{
	read_gesture();
}

int main(void)
{
	init();
    while (1) 
    {
    }
}

