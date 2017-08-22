/*


*/

#ifndef MIDDLEEULERCALCULATOR_H_
#define MIDDLEEULERCALCULATOR_H_

#include "Data.h"


#define EULER_CAL_OPTION_AHRS 1

typedef void (*middle_euler_cal_init)(void *configData);

typedef void (*middle_euler_cal_update)(float *accel,float *gyro,float *magnet);

typedef void (*middle_euler_cal_getValues)(float *out);

typedef int (*middle_euler_cal_getState)(void);

typedef struct EulerCal{

	middle_euler_cal_init 		init;
	middle_euler_cal_update 	update;
	middle_euler_cal_getValues getValues;
	middle_euler_cal_getState 	getState;
}EulerCal;



EulerCal middle_euler_getEulerCal(int option);



#endif

