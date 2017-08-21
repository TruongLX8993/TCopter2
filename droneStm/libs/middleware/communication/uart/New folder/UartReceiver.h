#ifndef UartReceiver_h_
#define UartReceiver_h_
#include "stm32f4xx.h"


u8 readByteViaUart4(void);
u8 readByteViaUart6(void);
u8 readByteViaUart7(void);
u8 readByteViaUart(int uart);

void readBytesViaUart4(u8 *out,int length);
void readBytesViaUart6(u8 *out,int length);
void readBytesViaUart7(u8 *out,int length);
void readBytesViaUart(int uart,u8 *out,int length);




u32 readBytesViaUart4WithTimeout(u8 *out,int length,u32 timeout);
u32 readBytesViaUart6WithTimeout(u8 *out,int length,u32 timeout);
u32 readBytesViaUart7WithTimeout(u8 *out,int length,u32 timeout);
u32 readBytesViaUartWithTimeout(int uart,u8 *out,int length,u32 timeout);
#endif
