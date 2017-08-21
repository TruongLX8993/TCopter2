
#ifndef CONTROLLER_H_
#define CONTROLLER_H_


void controller_init(void);

void controller_update(void);

float controller_getRoll(void);

float controller_getPitch(void);

float controller_getYaw(void);

int controller_isTurnOnHoldAlt(void);

int controller_isTurnOnHoldPos(void);


#endif