#ifndef MPU9250_H_
#define MPU9250_H_
#include "SensorData.h"



typedef struct Mpu9250{
	void *data;
}Mpu9250;




void mpu9250_Init(Mpu9250 *mpu,int i2cName);

void mpu9250_Update(Mpu9250 *sensor,int accel,int gyro,int magnet);

void mpu9259_Free(Mpu9250 *sensor);

SensorData mpu9250_getAccel(Mpu9250 sensor);

SensorData mpu9250_getGyro(Mpu9250 sensor);

SensorData mpu9250_getMagnet(Mpu9250 sensor);

SensorData mpu9250_Utils_createDataWithRawGyro(u16 roll,u16 pitch,u16 yaw);

SensorData mpu9250_Utils_createDataWithRawAccel(u16 roll,u16 pitch,u16 yaw);



#endif
