#include "_main.h"
#include "string.h"
#include "BalancingSystem.h"
#include "PositionHoldingSystem.h"


void control_center_power(int isOn,float *pwms){
	
	if(isOn)
		pwms[0]=pwms[1]=pwms[2]=pwms[3]=controller_system_getThr();
	else
		pwms[0]=pwms[1]=pwms[2]=pwms[3]=1000;
}


void control_center_takeoff(float *pwms){
	
	float gyroData[3];
	float eulerData[3];
	float ctr[3];
	
	ctr[0]=controller_system_get_roll();
	ctr[1]=controller_system_get_pitch();
	ctr[2]=controller_system_get_yaw();
	
	imu_system_getGyro(gyroData);
	euler_system_getEulerData(eulerData);
	
	balancing_system_update(ctr,eulerData,gyroData,pwms);
		
}

void control_center_land(float *pwms){
	
	control_center_power(1,pwms);
}

void control_hold_position(int isHolding){
	
	float sp[3];
	float eulerData[3],positionData[2],accelData[3],gyroData[3];
	
	
	euler_system_getEulerData(eulerData);

		
	if(isHolding){
		
		position_holding_system_update(positionData,eulerData,accelData,sp);
		sp[2]=controller_system_getYaw();
		balancing_system_update(sp,eulerData,gyroData,pwms);
	}
}

void control_hold_altitude(){

}

void control_hold(){

}
