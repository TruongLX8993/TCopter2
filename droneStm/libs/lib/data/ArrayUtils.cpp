#include "ArrayUtils.h"

void arrayutils_scale(u16 *in,int length,float gain,float *out){
	
	for(int i=0;i<length;i++)
		out[i]=in[i]*gain;
	
}


