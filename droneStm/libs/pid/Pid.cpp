#include "Pid.h"
#include "Constraint.h"


float pid_cal_e(PID *pid,float trueValues);

float pid_cal_p(PID *pid,float err);

float pid_cal_i(PID *pid,float err);

float pid_cal_d(PID *pid,float err);

float pid_cal_sum(PID *pid,float p,float i,float d);

void pid_init(PID *pid, PIDConfig info){
	
	pid->config = info;
	pid->isReset=1;
}

void pid_init(PID *pid,float kp,float ki,float kd,float maxE,float maxKp,float maxKi,float maxKd,float maxOut){
	

	PIDConfig config;
	config.kp=kp;
	config.ki=ki;
	config.kd=kd;
	config.maxE=maxE;
	config.maxP=maxKp;
	config.maxI=maxKi;
	
	config.maxD=maxKd;
	config.maxOut=maxOut;
	pid_init(pid,config);
}






void pid_enable(PID *pid){
	
	pid->isReset=1;
}
float updateErrorPID(PID *pid, float err){
	
	float p,i,d;	
	err=constraint_range(err,pid->config.maxE);
	p=pid_cal_p(pid,err);
	i=pid_cal_i(pid,err);
	d=pid_cal_d(pid,err);
	return pid_cal_sum(pid,p,i,d);
}

float pid_update(PID *pid, float value)
{
	pid->isReset=0;
	float error = pid_cal_e(pid,value);
	return updateErrorPID(pid, error);
}


void pid_reset(PID *pid){
	pid->setPoint	=	0;
	pid->integral  = 	0;
	pid->prevError = 	0;
	pid->isReset 	= 	1;
}

void pid_reset(PID *pid,float sp){
	
	pid_reset(pid);
	pid->setPoint=sp;
}

int pid_is_reseted(PID pid)
{
	return pid.isReset;
}


void pid_change_set_point(PID *pid, float sp){
	
	pid->setPoint = sp;
}


float pid_get_set_point(PID pid){
	
	return pid.setPoint;
}


/*===================================================*/



float pid_cal_e(PID *pid,float value){
	
	return 	constraint_range(pid->setPoint-value,pid->config.maxE);
}

float pid_cal_p(PID *pid,float error){
	
	float res=pid->config.kp*error;
	return constraint_range(res,pid->config.maxP);
	
}


float pid_cal_i(PID *pid,float error){
	
	float res=pid->config.ki*error+pid->integral;
	return pid->integral=constraint_range(res,pid->config.maxI);
}


float pid_cal_d(PID *pid,float error){
	
	float res=(error-pid->prevError)*pid->config.kd;
	res=constraint_range(res,pid->config.maxD);
	pid->prevError=error;
	return res;
}


float pid_cal_sum(PID *pid,float p,float i,float d){
	
	float res=p+i+d;
	return constraint_range(res,pid->config.maxOut);
}
