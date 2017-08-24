
#include "I2CUtils.h"
#include "Timeout.h"


int i2c_utils_map_to_err(int err){
	
	return I2C_UTILS_ERR_TIME_OUT;
}

int i2c_utils_write_bytes_to_register(int i2cName,u8 addr,u8 reg,u8 *data,int length,u32 millis_timeout){
	
	
	int ret;
	Timeout timeout;

	
	timeout_init_micros(&timeout,millis_timeout);
	timeout_start(&timeout);
	
	ret=i2c_Start(i2cName,addr,MI2C_TRANSMISTER,timeout);
	if(ret!=MI2C_ERR_NONE)
		return i2c_utils_map_to_err(ret);
	
	ret=i2c_WriteBytes(&reg,1,i2cName,timeout);
	if(ret!=MI2C_ERR_NONE)
		return i2c_utils_map_to_err(ret);
	
	ret=i2c_WriteBytes(data,length,i2cName,timeout);
	if(ret!=MI2C_ERR_NONE)
		return i2c_utils_map_to_err(ret);
	
	ret=i2c_Stop(i2cName,timeout);
	if(ret!=MI2C_ERR_NONE)
		return i2c_utils_map_to_err(ret);
	return I2C_UTILS_ERR_NONE;
}

int i2c_utils_read_bytes_from_register(int i2cName,u8 addr,u8 reg,u8 *data,int length,u32 millis_timeout){
	
	int ret;
	Timeout timeout;
	
	timeout_init_micros(&timeout,millis_timeout);
	timeout_start(&timeout);
	
	ret=i2c_Start(i2cName,addr,MI2C_TRANSMISTER,timeout);
	if(ret!=MI2C_ERR_NONE)
		return i2c_utils_map_to_err(ret);
	
	ret=i2c_WriteBytes(&reg,1,i2cName,timeout);	
	if(ret!=MI2C_ERR_NONE)
		return i2c_utils_map_to_err(ret);
	
	
	ret=i2c_Stop(i2cName,timeout);
	if(ret!=MI2C_ERR_NONE)
		return i2c_utils_map_to_err(ret);
	
	ret=i2c_Start(i2cName,addr,MI2C_RECEIVER,timeout);
	if(ret!=MI2C_ERR_NONE)
		return i2c_utils_map_to_err(ret);
	
	ret=i2c_ReadBytes(data,length,i2cName,timeout);
	if(ret!=MI2C_ERR_NONE)
		return i2c_utils_map_to_err(ret);
	return I2C_UTILS_ERR_NONE;
}


int i2c_utils_write_byte_to_register(int i2cName,u8 addr,u8 reg,u8 *data,int length,u32 millis_timeout){
	
	
	int ret;
	Timeout timeout;
	
	timeout_init_micros(&timeout,millis_timeout);
	timeout_start(&timeout);
	
	ret=i2c_Start(i2cName,addr,MI2C_TRANSMISTER,timeout);
	if(ret!=MI2C_ERR_NONE)
		return i2c_utils_map_to_err(ret);
	
	
	ret=i2c_WriteBytes(&addr,1,i2cName,timeout);
	if(ret!=MI2C_ERR_NONE)
		return i2c_utils_map_to_err(ret);
	
	ret=i2c_WriteBytes(data,length,i2cName,timeout);
	if(ret!=MI2C_ERR_NONE)
		return i2c_utils_map_to_err(ret);
	
	ret=i2c_Stop(i2cName,timeout);
	if(ret!=MI2C_ERR_NONE)
		return i2c_utils_map_to_err(ret);
	return I2C_UTILS_ERR_NONE;
}

int i2c_utils_read_byte_from_register(int i2cName,u8 addr,u8 reg,u8 *data,int length,u32 millis_timeout){
	
	int ret;
	Timeout timeout;
	
	timeout_init_micros(&timeout,millis_timeout);
	timeout_start(&timeout);
	
	ret=i2c_Start(i2cName,addr,MI2C_RECEIVER,timeout);
	if(ret!=MI2C_ERR_NONE)
		return i2c_utils_map_to_err(ret);
	
	ret=i2c_WriteBytes(&addr,1,i2cName,timeout);
	if(ret!=MI2C_ERR_NONE)
		return i2c_utils_map_to_err(ret);
	
	ret=i2c_ReadBytes(data,length,i2cName,timeout);
	if(ret!=MI2C_ERR_NONE)
		return i2c_utils_map_to_err(ret);
			
	return I2C_UTILS_ERR_NONE;
}



