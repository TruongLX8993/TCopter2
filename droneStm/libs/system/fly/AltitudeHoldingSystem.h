#ifndef ALTITUDEHOLDINGSYSTEM_H_
#define ALTITUDEHOLDINGSYSTEM_H_




void 	altitude_holding_system_init(void);

float altitude_holding_system_update(float altitude,float *accel,float *euler);

void 	altitude_holding_reset(void);




#endif
