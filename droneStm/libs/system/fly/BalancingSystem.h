


#ifndef BALANCINGSYSTEM_H_
#define BALANCINGSYSTEM_H_

void balancing_system_init(void);

void balancing_system_update(float *ctr,float *euler,float *gyro,float *err);

void balancing_system_reset(void);

int balancing_system_is_available(void);

#endif
