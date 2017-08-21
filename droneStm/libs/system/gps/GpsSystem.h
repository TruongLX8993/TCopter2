#ifndef GPSSYSTEM_H_
#define GPSSYSTEM_H_

#include "SensorData.h"

void gps_system_Init(void);

void gps_system_Update(void);

PositionData gps_system_GetPosition(void);

#endif