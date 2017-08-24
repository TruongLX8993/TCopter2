#include "ControllerSystem.h"
#include "MiddleReceiver.h"



#define CONTROLLER_SYS_ROLL_CHANNEL 	0

#define CONTROLLER_SYS_PITCH_CHANNEL 	1

#define CONTROLLER_SYS_YAW_CHANNEL 		3

#define CONTROLLER_SYS_THR_CHANNEL 		2

#define CONTROLLER_SYS_ALT_CHANNEL 		4

#define CONTROLLER_SYS_POS_CHANNEL 		5



float controller_system_map_to_angle_control(int val);

typedef struct ControllerSystemData{
	
	MiddleReceiver receiver;
}ControllerSystemData;


typedef struct ControllerState{

	int holdPos;
	int holdAlt;
	int power;
	int take_off;
	int land;
	
}ControllerState;



#define CONTROLLER_SYSTEM_NUMBER_PROCESS 3






typedef int (*controller_signal_check)();

typedef void (*controller_action)();

typedef struct ControllerSignalProcess{

	controller_signal_check check;
	controller_action action;
}ControllerSignalProcess;



//
ControllerSignalProcess controllerSystemSignalsProcess[CONTROLLER_SYSTEM_NUMBER_PROCESS];
//
ControllerSystemData mControllerSystemData;




int controller_system_init(void){

	return 0;
}

int controller_system_update(void){

	
	
	
	if(!mControllerSystemData.receiver.update())
		return CONTROLLER_SYS_ERR_LOST;
	
	for(int i=0;i<CONTROLLER_SYSTEM_NUMBER_PROCESS;i++){
		if(controllerSystemSignalsProcess[i].check()){
			controllerSystemSignalsProcess[i].action();
			break;
		}
	}
	
	return CONTROLLER_SYS_ERR_NONE;
}

float controller_system_get_roll(void){
	
	return controller_system_map_to_angle_control(mControllerSystemData.receiver.getChannel(CONTROLLER_SYS_ROLL_CHANNEL));
}

float controller_system_get_pitch(void){

	return controller_system_map_to_angle_control(mControllerSystemData.receiver.getChannel(CONTROLLER_SYS_PITCH_CHANNEL));
}

float controller_system_get_yaw(void){

	return controller_system_map_to_angle_control(mControllerSystemData.receiver.getChannel(CONTROLLER_SYS_THR_CHANNEL));
}


float controller_system_get_thr(void){

	return controller_system_map_to_angle_control(mControllerSystemData.receiver.getChannel(CONTROLLER_SYS_YAW_CHANNEL));
}

int controller_system_isTurnOnHoldAlt(void){
	
	return 0;
}

int controller_system_isTurnOnHoldPos(void){
	
	return 0;
}


/*-----------------------------               process impl        ------------------------------------------*/



int control_signal_check_starting(){

	return 1;
}


void control_signal_action_start(){

	
}


int control_signal_check_takeoff(){

	return 1;
}


int control_signal_check_hold_alt(){
	
	return 1;
}

int control_signal_check_land(){
	
	return 1;
}


/*-----------------------------------                                       ----------------------------------------------*/


float controller_system_map_to_angle_control(int val){
	
	return 0;
}







