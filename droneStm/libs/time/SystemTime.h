#ifndef MTIME_H_
#define MTIME_H_



#include "stm32f4xx.h"



#define STIME_SENSI_MIL 0

#define STIME_SENSI_MIC 1




void stime_init(int timeSensi);

u32 stime_get_millis(void);

u32 stime_get_micros(void);

#endif
