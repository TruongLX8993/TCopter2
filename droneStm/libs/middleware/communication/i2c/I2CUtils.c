
#include "I2CUtils.h"



int i2cUtils_WriteBytesToRegister(int i2cName,u8 addr,u8 reg,u8 *data,int length){
	
	i2c_Start(i2cName,addr,MI2C_TRANSMISTER);
	i2c_WriteBytes(&reg,1,i2cName);
	i2c_WriteBytes(data,length,i2cName);
	i2c_Stop(i2cName);
	return 1;
}

int i2cUtils_ReadBytesFromRegiter(int i2cName,u8 addr,u8 reg,u8 *data,int length){
	
	i2c_Start(i2cName,addr,MI2C_TRANSMISTER);
	i2c_WriteBytes(&reg,1,i2cName);
	i2c_Stop(i2cName);
	i2c_Start(i2cName,addr,MI2C_RECEIVER);
	return i2c_ReadBytes(data,length,i2cName);
}

int i2cUtils_WriteByte(int i2cName,u8 addr,u8 *data,int length){
	
	i2c_Start(i2cName,addr,MI2C_TRANSMISTER);
	i2c_WriteBytes(data,length,i2cName);
	i2c_Stop(i2cName);
	return 1;
}

int i2cUtils_ReadByte(int i2cName,u8 addr,u8 *data,int length){
	
	i2c_Start(i2cName,addr,MI2C_RECEIVER);
	return i2c_ReadBytes(data,length,i2cName);
}



