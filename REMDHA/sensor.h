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

bool MGC3130Init(void);									//initialize MGC3130
bool MGC3130Read(void);									//read gesture from MGC3130



#endif /* SENSOR_H_ */