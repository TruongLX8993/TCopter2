#include "main.h"
#include "Ublox.h"
#include "Printer.h"
#include "BarometerMs5611.h"
#include <math.h>
#include <stdlib.h>
#include "UbxSender.h"
#include "UbloxConfig.h"
#include "Filter.h"
#include "String.h"
#include "UbloxConfig.h"
#include "UbxReceiver.h"






void startCalibrate(void){
	disableController();
	initGyroCalibrationProgram();
	startGyroCalibrationProgram();
	if(isInitAltitudeBlock()){
		initAltitudeCalibraionProgram();
		startAltitudeCalibrationProgram();
	}
	enableController();
}



int checkAndStartCalibrate(){
	if(!isRunCalibrateProgram())
		return 0;
	startCalibrate();
	return 1;
}

void reset(){
	resetController();
	resetImuBlock();
	initDeltaTimeChecker(&timeCheckerMainLoop,FREQUENCE_TO_MICROS(FREQUENCE_UPDATE_MAIN));
}


void setUp(void){
//	initI2C();
//	initImuBlock();
//	initEulerBlock();
//	initFlyControlBlock();
//	initMotorControlBlock();
//	initDeltaTimeChecker(&timeCheckerMainLoop,FREQUENCE_TO_MICROS(FREQUENCE_UPDATE_MAIN));
	initDroneController();
	delayMilis(1000);
}


void callFunctionEvadeInterrupt(void){
	disableController();
	updateImuBlock();
	enableController();
}


int loop(void){
	
//	static float pwms[4];
//	while(!checkDeltaTimeChecker(&timeCheckerMainLoop));
	updateDroneController();
//	callFunctionEvadeInterrupt();
//	if(checkAndStartCalibrate())
//		return 0;
//	updateEulerBlock();
//	updateFlyControlBlock(pwms);	
//	updateMotorControlBlock(pwms[0],pwms[1],pwms[2],pwms[3]);
	return 1;
}



int main(void){
	
	
	setUp();
	while(1){
		while(loop()){};
	 	reset();
	}
}







