#include "MiddleReceiver.h"


Receiver middle_receiver_getRD9ReceiverInstance(void);


Receiver middle_receiver_getInstance(int option){
	
	Receiver ret;	
	if(option==MIDDLE_RECEIVER_R9DS_OPTION)
		ret = middle_receiver_getRD9ReceiverInstance();
	return ret;
}



/*-------------------------------create r9ds instance ------------------------------------------------*/

Receiver middle_receiver_getRD9ReceiverInstance(){
	
	
	Receiver ret;
	return ret;
}



void middle_receiver_r9d_init(void){

}

int middle_receiver_r9d_update(void){
	
	return 0;
}

int middle_receiver_r9d_getChannel(int **channels){

	return 0;
}


void middle_receiver_r9d_free(void){

}

/*-------------------------------end r9ds instance ------------------------------------------------*/


