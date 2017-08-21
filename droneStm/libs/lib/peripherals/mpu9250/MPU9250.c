#include "MPU9250.h"
#include "I2C.h"


#define REG_DEFAULT 						0x68<<1
#define MAG_DEFAULT 						0x0C<<1

#define GYROSENSI500_VALUE_REG 		0x08
#define GYROSENSI_REGISTER 		 	0x1B

#define ACCELSENSI_REGISTER    		0x1C
#define ACCELSENSI_VALUE_REG   		0x00

#define SAMPLE_RATE_VALUE_REG  		0x00
#define SAMPLE_RATE_REGISTER   		0x19


#define FILTER_VALUE_REG      		0x03
#define FILTER_REGISTER					0x1A

#define DATA_REGISTER_ACCEL_GYRO    0x3B
#define DATA_GYRO_ACCEL_LENGTH      14

#define DATA_REGISTER_MAG				0x03
#define DATA_MAG_LENGTH					7
#define DATA_MAG_STATUS_RE          0x02

#define PWM_MGMT_1           			0x6B
#define PWM_MGMT_2           			0x6C
#define GYRO_GAIN 						1.0f/65.5f
#define ACCEL_GAIN 						2.0f*9.8f/32768.0f

#define SMPLRT_DIV          			0x19
#define FILTER_REG             		0x1A
#define GYRO_CONFIG_REGISTER 			0x1B
#define ACCEL_CONFIG_REGISTER_1     0x1C
#define ACCEL_CONFIG_REGISTER_2     0x1D
#define INT_PIN_CFG         			0x37
#define INT_ENABLE          			0x38



typedef struct Mpu9250_Data{
	
	SensorData accelData,gyroData,magnetData;
	int i2cName;
}Mpu9250_Data;






void mpu9250_configAccelGyro(Mpu9250 *sensor);

void mpu9250_configMagnet(Mpu9250 *sensor);

void mpu9250_updateAccelAndGyro(Mpu9250 *sensor);

void mpu9250_updateMagnet(Mpu9250 *sensor);


void mpu9250_Init(Mpu9250 *sensor,int i2cName){

	mpu9250_configAccelGyro(sensor);
	mpu9250_configMagnet(sensor);
}

void mpu9250_Update(Mpu9250 *sensor,int accel,int gyro,int magnet){

	
}


SensorData mpu9250_getAccel(Mpu9250 sensor){

	
	return ((Mpu9250_Data*)(sensor.data))->accelData;
}

SensorData mpu9250_getGyro(Mpu9250 sensor){

	return ((Mpu9250_Data*)(sensor.data))->gyroData;
}

SensorData mpu9250_getMagnet(Mpu9250 sensor){

	return ((Mpu9250_Data*)(sensor.data))->magnetData;
}

SensorData mpu9250_Utils_createDataWithRawGyro(u16 roll,u16 pitch,u16 yaw){

	SensorData ret;
	return ret;
}

SensorData mpu9250_Utils_createDataWithRawAccel(u16 roll,u16 pitch,u16 yaw){
	
	SensorData ret;
	return ret;
}
/*----------------------------------------------*/




void mpu9250_configAccelGyro(Mpu9250 *sensor){

}

void mpu9250_configMagnet(Mpu9250 *sensor){

}

void mpu9250_updateAccelAndGyro(Mpu9250 *sensor){

}

void mpu9250_updateMagnet(Mpu9250 *sensor){

}

