/*
Altitude System

*/



#ifndef ALTITUDESYSTEM_H_

#define ALTITUDESYSTEM_H_

#define ALT_SYSTEM_ERR_NONE 1


int altitude_system_init(void);

int altitude_system_update(void);

float altitude_system_getAltitude(void);

#endif 


