#ifndef CONTROLLERSYSTEMCALLBACK_H_
#define CONTROLLERSYSMTECALLBACK_H_

typedef void (*controller_system_cb_power)(int isOn,float *pwms);

typedef void (*controller_system_cb_take_off)(float *pwms);

typedef void (*controller_system_cb_hold_alt)(int isHolding);

typedef void (*controller_system_cb_hold_pos)(int isHolding);

typedef void (*controller_system_cb_hold)(int isHolding);



typedef struct controller_system_cb{
	
	controller_system_cb_power power;
	controller_system_cb_take_off takeoff;
	controller_system_cb_hold_alt holdAlt;
	controller_system_cb_hold_pos holdpost;
	controller_system_cb_hold hold;
}controller_system_cb;

#endif