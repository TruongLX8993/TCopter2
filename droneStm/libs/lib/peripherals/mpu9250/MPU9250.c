#include "MPU9250.h"
#include "I2CUtils.h"


#define ADDR_DEFAULT 					0x68<<1
#define ADDR_MAG_DEFAULT 				0x0C<<1

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






int mpu9250_configAccelGyro(Mpu9250 *sensor);

int mpu9250_configMagnet(Mpu9250 *sensor);

int mpu9250_updateAccelAndGyro(Mpu9250 *sensor);

int mpu9250_updateMagnet(Mpu9250 *sensor);


int mpu9250_Init(Mpu9250 *sensor,int i2cName){

	
	mpu9250_configAccelGyro(sensor);
	mpu9250_configMagnet(sensor);
	
	return 1;
}

int mpu9250_Update(Mpu9250 *sensor,int accel,int gyro,int magnet){

	int ret;
	if(accel||gyro){
		
		ret=mpu9250_updateAccelAndGyro(sensor);
		if(ret!=MPU_9250_ERR_TIME_OUT)
			return ret;
	}
	if(magnet)
		ret=mpu9250_updateMagnet(sensor);
	return ret;
			
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

SensorData mpu9250_Utils_createDataWithRawGyro(s16 *gyroData){

	SensorData ret;
	
	ret.rawX=gyroData[0];
	ret.rawY=gyroData[1];
	ret.rawZ=gyroData[2];
	
	ret.x=gyroData[0]*GYRO_GAIN;
	ret.y=gyroData[1]*GYRO_GAIN;
	ret.z=gyroData[2]*GYRO_GAIN;
	return ret;
	
}

SensorData mpu9250_Utils_createDataWithRawAccel(s16 *accelRawData){
	
	SensorData ret;
	
	ret.rawX=accelRawData[0];
	ret.rawY=accelRawData[1];
	ret.rawZ=accelRawData[2];
	
	ret.x=accelRawData[0]*ACCEL_GAIN;
	ret.y=accelRawData[1]*ACCEL_GAIN;
	ret.z=accelRawData[2]*ACCEL_GAIN;
	return ret;
}

SensorData mpu9250_Utils_createDataWithRawMagnet(s16 *magnetRawData){
	
	SensorData ret;
	
	return ret;
}
/*----------------------------------------------*/


Mpu9250_Data* mpu_9250_get_data(Mpu9250 *sensor){
	
	return (Mpu9250_Data*)(&sensor->data);
}

int mpu9250_configAccelGyro(Mpu9250 *sensor){
	
	return 0;
	
}

int mpu9250_configMagnet(Mpu9250 *sensor){

	return 1;
}

int mpu9250_updateAccelAndGyro(Mpu9250 *sensor){

	Mpu9250_Data* data=mpu_9250_get_data(sensor);
	u8 buffer[14];
	s16 accelRawData[3];
	s16 gyroRawData[3];
	
	
	int ret=i2c_utils_read_bytes_from_register(data->i2cName,ADDR_DEFAULT,DATA_REGISTER_ACCEL_GYRO,buffer,14,2);
	if(ret!=I2C_UTILS_ERR_NONE)
		return MPU_9250_ERR_TIME_OUT;
	
	accelRawData[0]=((s16)buffer[0]<<8)|buffer[1];
	accelRawData[1]=((s16)buffer[2]<<8)|buffer[3];
	accelRawData[2]=((s16)buffer[4]<<8)|buffer[5];
	
	gyroRawData[0]=((s16)buffer[8]<<8)|buffer[9];
	gyroRawData[1]=((s16)buffer[10]<<8)|buffer[11];
	gyroRawData[2]=((s16)buffer[12]<<8)|buffer[13];
	
	data->accelData=mpu9250_Utils_createDataWithRawAccel(accelRawData);
	data->gyroData=mpu9250_Utils_createDataWithRawGyro(gyroRawData);
	
	return MPU_9250_ERR_NONE;
}

int mpu9250_updateMagnet(Mpu9250 *sensor){
	
	
	Mpu9250_Data* data=mpu_9250_get_data(sensor);
	u8 buffer[7];
	s16 magnetRawData[3];
	
	
	int ret=i2c_utils_read_bytes_from_register(data->i2cName,ADDR_MAG_DEFAULT,DATA_REGISTER_MAG,buffer,7,2);
	if(ret!=I2C_UTILS_ERR_NONE)
		return MPU_9250_ERR_TIME_OUT;
	
	magnetRawData[0]=((s16)buffer[1]<<8)|buffer[0];
	magnetRawData[1]=((s16)buffer[3]<<8)|buffer[2];
	magnetRawData[2]=((s16)buffer[5]<<5)|buffer[4];
	data->magnetData=mpu9250_Utils_createDataWithRawMagnet(magnetRawData);
	
	return MPU_9250_ERR_NONE;
}

