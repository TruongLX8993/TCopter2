#ifndef I2C_H_
#define I2C_H_
#include "stm32f4xx.h"





#define MI2C_2 0

#define  MI2C_TRANSMISTER I2C_Direction_Transmitter

#define  MI2C_RECEIVER I2C_Direction_Receiver





void i2c_Init(int i2cName);

int i2c_Start(int i2cName,u8 addr,u32 dir);

int i2c_Stop(int i2cName);

int i2c_WriteBytes(u8* data,int length,int i2cName);

int i2c_ReadBytes(u8* dataOut,int length,int i2cName);



#endif

