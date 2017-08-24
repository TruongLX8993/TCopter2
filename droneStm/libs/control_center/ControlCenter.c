#include "_main.h"
#include "string.h"
#include "BalancingSystem.h"
#include "PositionHoldingSystem.h"
#include "AltitudeHoldingSystem.h"


void control_center_cal_pwm(float thr,float *err,float *pwms);

void control_center_power(int isOn,float *pwms){
	
	if(isOn)
		pwms[0]=pwms[1]=pwms[2]=pwms[3]=controller_system_get_thr();
	else
		pwms[0]=pwms[1]=pwms[2]=pwms[3]=1000;
}


void control_center_takeoff(float *pwms){
	
	float gyroData[3];
	float eulerData[3];
	float ctr[3];
	float err[3];
	
	memset(err,0,sizeof(float)*3);
	
	
	ctr[0]=controller_system_get_roll();
	ctr[1]=controller_system_get_pitch();
	ctr[2]=controller_system_get_yaw();
	
	imu_system_getGyro(gyroData);
	euler_system_getEulerData(eulerData);
	
	balancing_system_update(ctr,eulerData,gyroData,err);
	control_center_cal_pwm(controller_system_get_thr(),err,pwms);
}

void control_center_land(float *pwms){
	
	control_center_power(1,pwms);
}

void control_hold_position(int isHolding,float *pwms){
	
	float sp[3];
	float eulerData[3];
	float positionData[2];
	float accelData[3];
	float gyroData[3];
	float err[3];
	
	
	
	euler_system_getEulerData(eulerData);
	imu_system_getGyro(gyroData);
	
		
	if(isHolding){
		
		position_holding_system_update(positionData,eulerData,accelData,sp);
		sp[2]=controller_system_get_yaw();
		balancing_system_update(sp,eulerData,gyroData,err);
		control_center_cal_pwm(controller_system_get_thr(),err,pwms);
		
	}
	else{
		
		position_holding_system_reset();
		sp[0]=controller_system_get_pitch();
		sp[1]=controller_system_get_roll();
		sp[2]=controller_system_get_yaw();
		balancing_system_update(sp,eulerData,gyroData,err);
		control_center_cal_pwm(controller_system_get_thr(),err,pwms);
	}
}

void control_hold_altitude(int isHolding,float *pwms){
	
	float ctr[3];
	float eulerData[3];
	float gyroData[3];
	float err[3];
	//float accelData[3];
	float newThr;
	

	
	
	imu_system_getGyro(gyroData);
	euler_system_getEulerData(eulerData);
	newThr = controller_system_get_thr()+altitude_system_getAltitude();
	
	
	ctr[0]=controller_system_get_roll();
	ctr[1]=controller_system_get_pitch();
	ctr[2]=controller_system_get_yaw();
	
	
	if(isHolding)
		newThr = controller_system_get_thr()+altitude_system_getAltitude();
	else
		newThr = controller_system_get_thr();
	
	balancing_system_update(ctr,eulerData,gyroData,err);
	control_center_cal_pwm(newThr,err,pwms);

	
}

void control_hold(){

}


/*-------------------------------------------------------*/


void control_center_cal_pwm(float thr,float *err,float *pwms){


}
