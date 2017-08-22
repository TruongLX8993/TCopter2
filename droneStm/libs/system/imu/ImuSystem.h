#ifndef IMUSYSTEM_H_
#define IMUSYSTEM_H_

#include "stm32f4xx.h"

#include "Data.h"

#define IMU_SYS_ERR_NONE 1 // no error.

int imu_system_init(void);

void imu_system_startCalibrate(void);

void imu_system_saveAccelOffset(u16 *offset);

void imu_system_saveGyroOffset(u16 *offset);

void imu_system_saveMagnetoffset(float matrix[3][3],float *vector);

int imu_system_update(void);




SensorData imu_system_getAccel(void);

SensorData imu_system_getMagnet(void);

SensorData imu_system_getGyro(void);

void imu_system_getAccel(float *out);

void imu_system_getGyro(float *out);

void imu_system_getMagnet(float *out);

#endif


