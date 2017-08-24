#include "_main.h"


float gAccelData[3],gEulerData[3],gMagnetData[3],gGyroData[3];
float gPositionData[2];



int setup(void){

	if(controller_system_init()!=CONTROLLER_SYS_ERR_NONE)
		error_handler_init_controller();
	if(imu_system_init()!=IMU_SYS_ERR_NONE)
		error_handler_init_imu();
	if(altitude_system_init()!=ALT_SYSTEM_ERR_NONE)
		error_handler_init_alt();
	euler_system_init();
	return 1;
}


int loop(){

	
	int ret;

	
	
	
	
	
	
	ret=imu_system_update();
	if(ret!=IMU_SYS_ERR_NONE)
		error_handler_update_imu();
	
	else{
		imu_system_getAccel(gAccelData);
		imu_system_getGyro(gGyroData);
		imu_system_getMagnet(gMagnetData);
	}
	
	euler_system_update(gAccelData,gGyroData,gMagnetData);
	
	ret=controller_system_update();
	if(ret!=CONTROLLER_SYS_ERR_NONE)
		error_handler_update_controller();
	
	return 1;
}

int main(){
	
	
	
}

