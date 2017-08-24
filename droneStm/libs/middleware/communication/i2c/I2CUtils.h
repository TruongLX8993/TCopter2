#ifndef I2CUTILS_H_
#define I2CUTILS_H_

#include "I2C.h"

//@ ok
#define I2C_UTILS_ERR_NONE 1

#define I2C_UTILS_ERR_TIME_OUT -1



int i2c_utils_write_bytes_to_register(int i2cName,u8 addr,u8 reg,u8 *data,int length,u32 timeout_milis);

int i2c_utils_read_bytes_from_register(int i2cName,u8 addr,u8 reg,u8 *data,int length,u32 timeout_milis);

int i2c_utils_write_byte_to_register(int i2cName,u8 addr,u8 reg,u8 *data,int length,u32 timeout_milis);

int i2c_utils_read_byte_from_register(int i2cName,u8 addr,u8 reg,u8 *data,int length,u32 timeout_milis);

#endif

