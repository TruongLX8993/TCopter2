#ifndef CALIBRATE_H_
#define CALIBRATE_H_



#define CALIBARATE_FULL_SAMPLE 1


typedef struct GyroOffSetCal{
	void *data;
}GyroOffSetCal;



void gyro_offset_cal_init(int sample);

int gyro_offset_cal_init(int sample);





typedef struct AltitudeOffSetCal{

}AltitudeOffSetCal;


#endif