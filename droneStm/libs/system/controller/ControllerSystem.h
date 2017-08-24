
#ifndef CONTROLLERSYSTEM_H_
#define CONTROLLERSYSTEM_H_

#define CONTROLLER_SYS_ERR_NONE 1

#define CONTROLLER_SYS_ERR_LOST -1


int 	controller_system_init(void);

int 	controller_system_update(void);

float controller_system_get_roll(void);

float controller_system_get_pitch(void);

float controller_system_get_yaw(void);

float controller_system_get_thr(void);

#endif
