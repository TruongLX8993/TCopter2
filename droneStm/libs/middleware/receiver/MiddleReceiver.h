#ifndef MiddleReceiver_h_
#define MiddleReceiver_h_

#include "stm32f4xx.h"



#define RECEIVER_OPTION_R9DS 1

typedef void (middle_receiver_init)(void);


/*
@ret =1 : ok
@ret =0 : no new data.
*/

typedef int (middle_receiver_update)(void);

/*

@ret: numble channel
@out: data channel.
*/
typedef int (middle_receiver_getChannel)(int *channels);


typedef struct Receiver{
	
	middle_receiver_init init;
	middle_receiver_update update;
	middle_receiver_getChannel getChannel; 
}Receiver;

#endif