#ifndef ALTITUDEHOLDINGSYSTEM_H_
#define ALTITUDEHOLDINGSYSTEM_H_


typedef struct AltitudeHoldingSystemData{

}AltitudeHoldingSystemData;


void 	altitude_holding_system_init();

float altitude_holding_system_update(float altitude,float *accel,float *euler);

void 	altitude_holding_reset();




#endif