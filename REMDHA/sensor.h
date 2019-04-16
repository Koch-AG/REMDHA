/*
 * sensor.h
 *
 * Created: 12.04.2019 16:11:17
 *  Author: nbarben
 */ 


#ifndef SENSOR_H_
#define SENSOR_H_

#define MGC3130_ID			0x42						//I2C ID MGC3130
#define MGC3130_ID_READ		(MGC3130_ID << 1) + 1
#define MGC3130_ID_WRITE	(MGC3130_ID << 1) + 0

#define PAJ7620_ID			0x73						//I2C ID PAJ7620
#define PAJ7620_ID_READ		(PAJ7620_ID << 1) + 1
#define PAJ7620_ID_WRITE	(PAJ7620_ID << 1) + 0

//MGC3130//////////////////////////////////////////////////////////////////////////////////////////
bool MGC3130Init(void);									//initialize MGC3130
bool MGC3130ReadGesture(void);							//read gesture from MGC3130


	
	
//PAJ7620//////////////////////////////////////////////////////////////////////////////////////////
void PAJ7620Init(void);									//initialize PAJ7620
void PAJ7620ReadGesture (void);							//read gesture




#endif /* SENSOR_H_ */