#ifndef TIMEOUT_H_
#define TIMEOUT_H_

#include "stm32f4xx.h"

typedef struct Timeout{
	
	u32 startingTime;
	u32 duration;
	int timeoutFlag;
}Timeout;


void timeout_init(Timeout *timeout,u32 duration);

void timeout_start(Timeout *timeout);

int timeout_isTimeOut(Timeout timeout);


#endif
