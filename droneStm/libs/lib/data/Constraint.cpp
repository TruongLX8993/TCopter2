#include "Constraint.h"
#include <math.h>

float constraint_range(float value,float min,float max){
	
	
	if(value>max)
		return max;
	if(value<min)
		return min;
	return value;
}

float constraint_range(float value,float max){
	
	return constraint_range(value,-fabs(max),fabs(max));	
}

void constraint_range(float *in,int length,float max,float *out){
	
	for(int i=0;i<length;i++)
		out[i]=constraint_range(in[i],max);
}

