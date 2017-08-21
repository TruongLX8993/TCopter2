/*
@author: truonglx
#des: Impl TcTime. Count time by systemtick.
*/


#include "TcTime.h"
#include "SystemTick.h"

#define TIME_PERIOD 4294967295
#define TIME_TIM TIM2 
#define TIME_FREQUENCE 1000000


//SystemTickSubcriber counterTimeSubcriber;
//int flagInitCounterTime=0;

//void initCounterTime(void){
//	counterTimeSubcriber.available=1;
//	counterTimeSubcriber.current=0;
//	counterTimeSubcriber.unit=1;
//	if(!flagInitCounterTime)
//		registerSystemTickSubcriber(&counterTimeSubcriber);
//	flagInitCounterTime=1;
//}


//void checkAndInitCounterTime(void){
//	if(!flagInitCounterTime)
//		initCounterTime();
//}


//uint32_t getCurrentTime(void){
//	checkAndInitCounterTime();
//	return counterTimeSubcriber.current;
//}


void initCounterTimeMain(){
	
	
	static int flagInit=0;
	if(flagInit)
		return ;
	flagInit=1;
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_TimeBaseStructure.TIM_Prescaler = ((SystemCoreClock)/2/TIME_FREQUENCE)-1;
	TIM_TimeBaseStructure.TIM_Period = TIME_PERIOD;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIME_TIM, &TIM_TimeBaseStructure);
	TIM_Cmd(TIME_TIM, ENABLE);

}
u32 getCurrentTime(){
	static u32 timeScale=0;
	initCounterTimeMain();
	if(TIM_GetFlagStatus(TIME_TIM,TIM_IT_Update)){
		timeScale++;
		TIM_ClearFlag(TIME_TIM,TIM_IT_Update);
	}
	
	return timeScale*(TIME_PERIOD+1)+TIM_GetCounter(TIME_TIM);
}


