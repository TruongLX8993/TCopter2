#include "Timeout.h"
#include "SystemTime.h"

void timeout_init_millis(Timeout *timeout,u32 duration){

	timeout_init_micros(timeout,duration*1000);
}


void timeout_init_micros(Timeout *timeout,u32 duration){
	
	timeout->duration=duration;
}
void timeout_start(Timeout *timeout){

	timeout->startingTime=stime_get_millis();
}

int timeout_isTimeOut(Timeout *timeout){
	
	u32 endingTime=stime_get_micros();
	if(timeout->startingTime<endingTime){
	
	}
		
	
	return 0;
}
