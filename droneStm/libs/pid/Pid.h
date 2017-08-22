#ifndef Pid_h_
#define Pid_h_

typedef struct PIDConfig{
	float 	kp,ki,kd;
	float   maxP,maxI,maxD,maxE,maxOut;
}PIDConfig;

typedef struct PID{
	PIDConfig 	config;	
	float 		setPoint;
	float 		prevError;
	float 		integral;
	int 			isReset;
}PID;

void    	pid_init(PID *pid,float kp,float ki,float kd,float maxE,float maxKp,float maxKi,float maxKd,float maxOut);

void 		pid_init(PID *pid,PIDConfig config);

float 	pid_update_error(PID *pid, float error);

float 	pid_update(PID *pid, float trueValue);

void 		pid_reset(PID *pid);

void 		pid_reset(PID *pid,float newSp);

void 		pid_change_set_point(PID *pid,float sp);

float 	pid_get_get_point(PID pid);

int 		pid_is_reseted(PID pid);


#endif
