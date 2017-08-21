#include "MiddleReceiver.h"


Receiver middle_receiver_getRD9ReceiverInstance();


Receiver middle_receiver_getInstance(int option){
		middle_receiver_getRD9ReceiverInstance();
}



/*-------------------------------create r9ds instance ------------------------------------------------*/


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