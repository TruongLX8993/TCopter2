#ifndef MPU9250_H_
#define MPU9250_H_
#include "Data.h"



typedef struct Mpu9250{
	void *data;
}Mpu9250;

#define MPU_9250_ERR_TIME_OUT -1

#define MPU_9250_ERR_NONE 1


int mpu9250_Init(Mpu9250 *mpu,int i2cName);

int mpu9250_Update(Mpu9250 *sensor,int accel,int gyro,int magnet);

void mpu9259_Free(Mpu9250 *sensor);

SensorData mpu9250_getAccel(Mpu9250 sensor);

SensorData mpu9250_getGyro(Mpu9250 sensor);

SensorData mpu9250_getMagnet(Mpu9250 sensor);

SensorData mpu9250_Utils_createDataWithRawGyro(s16 *rawData);

SensorData mpu9250_Utils_createDataWithRawAccel(s16 *rawData);

SensorData mpu9250_Utils_createDataWithRawMagnet(s16 *rawData);

#endif
