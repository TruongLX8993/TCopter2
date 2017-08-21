#ifndef MTIME_H_
#define MTIME_H_



#include "stm32f4xx.h"



#define TIME_SENSI_MIL 0

#define TIME_SENSI_MIC 1




void initTime(int timeSensi);

u32 getMillis(void);

u32 getMicros(void);

#endif
