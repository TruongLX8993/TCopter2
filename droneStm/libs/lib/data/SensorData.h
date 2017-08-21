#ifndef SENSORDATA_H_
#define SENSORDATA_H_


#include "stm32f4xx.h"

#define X_INDEX 0

#define Y_INDEX 1

#define Z_INDEX 2


typedef struct SensorData{
	float x,y,z;
	u16 rawX,rawY,rawZ;
}SensorData;

typedef struct PositionData{
	
	float lat,lon;
}PositionData;

void sensordata_getRawArray(SensorData ,u16 *raw);
#endif

