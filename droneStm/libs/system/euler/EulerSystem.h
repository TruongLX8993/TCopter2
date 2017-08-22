#ifndef EULERSYSTEM_H_
#define EULERSYSTEM_H_


#include "Data.h"


#define EULER_SYSTEM_STARTING_STATE 1

#define EULER_SYSTEM_READLLY_STATE 2


void euler_system_init(void);

/*

@in accel  : not null  m/s
@in gyro   : not null. deg/s
@in magnet : can null. 
*/
void euler_system_update(float *accelData,float *gyroData,float *magnetData);


void euler_system_getEulerData(float *euler);

int euler_system_getState(void);


#endif

