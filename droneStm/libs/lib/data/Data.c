#include "Data.h"

void sensordata_getRawArray(SensorData in,u16 *raw){
	
	raw[X_INDEX]=in.rawX;
	raw[Y_INDEX]=in.rawY;
	raw[Z_INDEX ]=in.rawZ;
}





