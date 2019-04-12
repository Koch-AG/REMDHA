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