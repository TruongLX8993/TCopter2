#include "ImuSystem.h"
#include "MiddleSensor.h"

#define IMU_SY_CONF_ACCEL_GYRO_UPDATE_FREQ 250  //hz

#define IMU_SY_CONF_MAGNET_UPDATE_FREQ 50  //hz

ImuSensor imusy_sensor;



void imusystem_init(void){
	
	
}

void imusystem_startCalibrate(void){
	
	
	 
}

void imusystem_saveAccelOffset(u16 *offset){

}

void imusystem_saveGyroOffset(u16 *offset){

}

void imusystem_saveMagnetoffset(float matrix[3][3],float *vector){

}

void imusystem_update(void){
	
}


SensorData imusystem_getAccel(void){
	
	SensorData ret;
	return ret;
}

SensorData imusystem_getMagnet(void){
	
	SensorData ret;
	return ret;
}

SensorData imusystem_getGyro(void){

	SensorData ret;
	return ret;
}