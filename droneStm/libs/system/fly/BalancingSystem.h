


#ifndef BALANCINGSYSTEM_H_
#define BALANCINGSYSTEM_H_

void balancing_system_init(void);

void balancing_system_update(float *controls,float *euler,float *gyro,float *pwms);

void balancing_system_reset(void);

int balancing_system_is_reseted(void);
#endif