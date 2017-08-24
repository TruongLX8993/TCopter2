#include "MiddleReceiver.h"


MiddleReceiver middle_receiver_getRD9ReceiverInstance(void);


MiddleReceiver middle_receiver_getInstance(int option){
	
	MiddleReceiver ret;	
	if(option==MIDDLE_RECEIVER_R9DS_OPTION)
		ret = middle_receiver_getRD9ReceiverInstance();
	return ret;
}



/*-------------------------------create r9ds instance ------------------------------------------------*/

MiddleReceiver middle_receiver_getRD9ReceiverInstance(){
	
	
	MiddleReceiver ret;
	return ret;
}



void middle_receiver_r9d_init(void){

}

int middle_receiver_r9d_update(void){
	
	return 0;
}

int middle_receiver_r9d_get_data_channels(int **channels){

	return 0;
}


void middle_receiver_r9d_free(void){

}

/*-------------------------------end r9ds instance ------------------------------------------------*/


