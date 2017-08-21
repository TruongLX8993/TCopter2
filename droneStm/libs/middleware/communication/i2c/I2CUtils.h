#ifndef I2CUTILS_H_
#define I2CUTILS_H_

#include "I2C.h"


int i2cUtils_WriteBytesToRegister(int i2cName,u8 addr,u8 reg,u8 *data,int length);

int i2cUtils_ReadBytesFromRegiter(int i2cName,u8 addr,u8 reg,u8 *data,int length);

int i2cUtils_WriteByte(int i2cName,u8 addr,u8 *data,int length);

int i2cUtils_ReadByte(int i2cName,u8 addr,u8 *data,int length);

#endif

