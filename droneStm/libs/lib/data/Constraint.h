#ifndef CONSTRAINT_H_
#define CONSTRAINT_H_


float constraint_range(float value,float min,float max);

float constraint_range(float value,float max);

float constraint_range(float *values,int length,float max);

float constraint_range(float *values,int lengtth,float min,float max);

#endif
