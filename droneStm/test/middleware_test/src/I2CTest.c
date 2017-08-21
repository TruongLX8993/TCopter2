#include "I2CUtils.h"
#include "I2CTest.h"

#define I2C_TEST_ADDR 0x68<<1

#define I2C_TEST_REG 117

#define I2C_TEST_OUT 0x71

int i2cTest_readRegister(void){

	u8 buffer;
	i2c_Init(MI2C_2);
	i2cUtils_ReadBytesFromRegiter(MI2C_2,I2C_TEST_ADDR,I2C_TEST_REG,&buffer,1);
	return I2C_TEST_OUT==buffer;
}

int i2cTest_writeRegister(void){

	return 0;
}
