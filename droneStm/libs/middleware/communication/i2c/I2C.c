#include "I2C.h"
#include "stdio.h"
#include "delay.h"
#include "GpioUtils.h"





/*   I2C General Param Configuration */

#define I2C_DUTY I2C_DutyCycle_2
#define I2C_CLOCK 400000



/*   I2C_2 Param Configuration */

#define I2C2_RCC_GPIO 				RCC_AHB1Periph_GPIOB
#define I2C2_RCC_I2C  				RCC_APB1Periph_I2C2

#define I2C2_SDA_PIN  				GPIO_Pin_11
#define I2C2_SCL_PIN  				GPIO_Pin_10

#define I2C2_SDA_PIN_SOURCE 		GPIO_PinSource11
#define I2C2_SCL_PIN_SOURCE 		GPIO_PinSource10

#define I2C2_I2CGPIO 				GPIOB 
#define I2C2_GPIO_AF 				GPIO_AF_I2C2








const u32 I2C_RCC_GPIOS[]={RCC_AHB1Periph_GPIOB};

const u32 I2C_RCC_I2C[]={RCC_APB1Periph_I2C2};

const u32 I2C_RCC_I2CS[]={RCC_APB1Periph_I2C2};

const u16 MI2C_SDA_PIN_S[]={I2C2_SDA_PIN};

const u16 MI2C_SCL_PIN_S[]={I2C2_SCL_PIN};

const u8 MI2C_SDA_PIN_SOURCES[]={I2C2_SDA_PIN_SOURCE};

const u8 MI2C_SCL_PIN_SOURCES[]={I2C2_SCL_PIN_SOURCE};

const u8 MI2C_AFS[]={GPIO_AF_I2C2};


GPIO_TypeDef* MI2C_GPIOS[]={GPIOB};

const u8 MI2C_GPIO_AFS={I2C2_GPIO_AF};

I2C_TypeDef* MI2C_POITERS[]={I2C2};

void enableI2CMode(void);

int mapI2CNameToI2CIndex(int name);

	
I2C_TypeDef* getI2C(int name);


void i2c_Init(int i2cName){
	
	int index=mapI2CNameToI2CIndex(i2cName);
	I2C_InitTypeDef i2cConfig;
	GPIO_InitTypeDef gpioConfig;
	enableI2CMode();

	
	RCC_AHB1PeriphClockCmd(I2C_RCC_GPIOS[index], ENABLE);
	gpioConfig.GPIO_Pin=MI2C_SCL_PIN_S[index]|MI2C_SDA_PIN_S[index];
	gpioConfig.GPIO_Mode=GPIO_Mode_AF;
	gpioConfig.GPIO_OType=GPIO_OType_OD;
	gpioConfig.GPIO_PuPd = GPIO_PuPd_UP;
	gpioConfig.GPIO_Speed = GPIO_Speed_100MHz;  
	GPIO_Init(MI2C_GPIOS[index], &gpioConfig);
	GPIO_PinAFConfig(MI2C_GPIOS[index],MI2C_SDA_PIN_SOURCES[index],MI2C_AFS[index]);
	GPIO_PinAFConfig(MI2C_GPIOS[index],MI2C_SCL_PIN_SOURCES[index],MI2C_AFS[index]);
	
	
	
	RCC_APB1PeriphClockCmd(I2C_RCC_I2C[index], ENABLE);
	I2C_DeInit(MI2C_POITERS[index]);
	i2cConfig.I2C_Mode 	= I2C_Mode_I2C;
	i2cConfig.I2C_Ack 	= I2C_Ack_Enable;
	i2cConfig.I2C_ClockSpeed = I2C_CLOCK;
	i2cConfig.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_Init(MI2C_POITERS[index], &i2cConfig);	
	I2C_Cmd(MI2C_POITERS[index], ENABLE); 
	
	
//	gpioConfig.GPIO_Pin=GPIO_Pin_10|GPIO_Pin_11;
//	gpioConfig.GPIO_Mode=GPIO_Mode_AF;
//	gpioConfig.GPIO_OType=GPIO_OType_OD;
//	gpioConfig.GPIO_PuPd = GPIO_PuPd_UP;
//	gpioConfig.GPIO_Speed = GPIO_Speed_100MHz;  
//	GPIO_Init(GPIOB, &gpioConfig);

//	GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_I2C2);
//	GPIO_PinAFConfig(GPIOB,GPIO_PinSource11,GPIO_AF_I2C2);
	
	
}

int i2c_Start(int i2cName,u8 addr,u32 dir){

	I2C_TypeDef* i2cPointer=getI2C(i2cName);
	
	
	while(I2C_GetFlagStatus(i2cPointer, I2C_FLAG_BUSY));
	I2C_GenerateSTART(i2cPointer, ENABLE);
	
	while(!I2C_CheckEvent(i2cPointer, I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(i2cPointer, addr, dir);
	if(dir == I2C_Direction_Transmitter)
		while(!I2C_CheckEvent(i2cPointer, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	else if(dir == I2C_Direction_Receiver)
		while(!I2C_CheckEvent(i2cPointer, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
	else
		return 0;
	
	return 1;
}

int i2c_Stop(int i2cName){

	I2C_GenerateSTOP(getI2C(i2cName), ENABLE);
	return 1;
}

int i2c_WriteBytes(u8* data,int length,int i2cName){
	
	
	
	int i;
	I2C_TypeDef* i2cPointer=getI2C(i2cName);
	for(i=0;i<length;i++){
		 I2C_SendData(i2cPointer, data[i]);
		 while(!I2C_CheckEvent(i2cPointer, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	}
	return 1;
}

int i2c_ReadBytes(u8 *dataout,int length,int i2cName){

	I2C_TypeDef* i2cPointer=getI2C(i2cName);
	
	
	I2C_AcknowledgeConfig(i2cPointer, ENABLE);
	for(int i=0;i<length;i++){
		
		if(i==length-1){
			I2C_AcknowledgeConfig(i2cPointer, DISABLE);
			i2c_Stop(i2cName);
		}
		while(!I2C_CheckEvent(i2cPointer, I2C_EVENT_MASTER_BYTE_RECEIVED));
		dataout[i]=I2C_ReceiveData(i2cPointer);
	}	
	return 1;
}



/*----------------------------------------------------------------------------------------------------------*/

int mapI2CNameToI2CIndex(int name){
	
	if(name==MI2C_2)
		return 0;
	return -1;
}

I2C_TypeDef* getI2C(int i2cName){

	return MI2C_POITERS[mapI2CNameToI2CIndex(i2cName)];
}

void enableI2CMode(void){
	
	
	initGPIO(GPIOD,GPIO_Pin_10,GPIO_Mode_OUT,GPIO_OType_PP,GPIO_High_Speed,GPIO_PuPd_UP);
	initGPIO(GPIOA,GPIO_Pin_6,GPIO_Mode_OUT,GPIO_OType_PP,GPIO_High_Speed,GPIO_PuPd_UP);
	initGPIO(GPIOC,GPIO_Pin_2,GPIO_Mode_OUT,GPIO_OType_PP,GPIO_High_Speed,GPIO_PuPd_UP);
	setPinHight(GPIOD, GPIO_Pin_10);
	setPinLow(GPIOA, GPIO_Pin_6);
	setPinHight(GPIOC, GPIO_Pin_2);
}

