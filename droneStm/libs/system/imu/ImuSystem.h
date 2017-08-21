#ifndef IMUSYSTEM_H_
#define IMUSYSTEM_H_

#include "stm32f4xx.h"

#include "SensorData.h"


void imusystem_init(void);

void imusystem_startCalibrate(void);

void imusystem_saveAccelOffset(u16 *offset);

void imusystem_saveGyroOffset(u16 *offset);

void imusystem_saveMagnetoffset(float matrix[3][3],float *vector);

void imusystem_update(void);


SensorData imusystem_getAccel(void);

SensorData imusystem_getMagnet(void);

SensorData imusystem_getGyro(void);

#endif


