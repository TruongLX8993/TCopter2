#ifndef MIDDLESENSOR_H_
#define MIDDLESENSOR_H_

#include "stm32f4xx.h"
#include "SensorData.h"



/* using mpu 9250*/
#define MIDDLE_IMU_SENSOR_OPTION 1


typedef void  (*imusensor_Init)(void);

typedef void  (*imusensor_Update)(int fAccel,int fGyro,int fMagnet);

typedef SensorData  (*imusensor_ReadAccel)(void);

typedef SensorData (*imusensor_ReadGyro)(void);

typedef SensorData (*imusensor_ReadMagnet)(void);


typedef struct ImuSensor{
	
	imusensor_Init _init;
	imusensor_Update _update;
	imusensor_ReadAccel _readAccel;
	imusensor_ReadGyro _readGyro;
	imusensor_ReadMagnet _readMagnet;
	
}ImuSensor;
	
	

/* using ms5611-ba*/
#define MIDDLE_BARO_OPTION_1 1



typedef void 	(*barosensor_Init)(void);

typedef void 	(*barosensor_Update)(void);

typedef int 	(*barosensor_AvailableData)(void);

typedef float 	(*barosensor_ReadBaro)(void);

typedef float 	(*barosensor_ReadTemp)(void);

typedef void 	(*barosensor_Free)(void);

typedef struct BaroSensor{
	
	barosensor_Init _init;
	barosensor_Update _update;
	barosensor_AvailableData _available;
	barosensor_ReadBaro _readBaro;
	barosensor_ReadTemp _readTemp;
}BaroSensor;






/* using ubloc neo m8n*/
#define GPS_SENSOR_OPTION_1 1



typedef void (*gpssensor_Init)();

typedef void (*gpssensor_Update)();

PositionData gpssensor_ReadPosition();


typedef struct GpsSensor{
	
	gpssensor_Init _init;
	gpssensor_Update _update;
}GpsSensor;


void imusensor_getInstance(int option);

void barosensor_getInstance(int option);

void gpssensor_getInstance(int option);

#endif
