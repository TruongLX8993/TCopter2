#ifndef MiddleReceiver_h_
#define MiddleReceiver_h_

#include "stm32f4xx.h"



#define MIDDLE_RECEIVER_R9DS_OPTION 1


/*
 
*/
typedef void (*middle_receiver_init)(u32 timeout_millis);


/*
@ret =1 : ok
@ret =0 : no new data.
*/

typedef int (*middle_receiver_update)(void);

/*

@ret: numble channel
@out: data channel.
*/
typedef int (*middle_receiver_get_data_channels)(int **channels);

typedef int (*middle_receiver_get_data_channel)(int channelId);

typedef void (*middle_receiver_free)(int *channels);


typedef struct MiddleReceiver{
	
	middle_receiver_init init;
	middle_receiver_update update;
	middle_receiver_get_data_channels getChannels; 
	middle_receiver_get_data_channel getChannel;
	middle_receiver_free free;
}MiddleReceiver;



MiddleReceiver middle_receiver_getInstance(int option);

#endif

