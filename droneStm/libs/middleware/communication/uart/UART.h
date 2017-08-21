#ifndef UART_H_
#define UART_H_

#define UART_4 4

#define UART_7 7

#include "stm32f4xx.h"


typedef void (uart_Callback)(int uartName,void *data,u8 c);


void uart_Init(int uartName,int baudrate);

void uart_Init(int uartName,int baudrate,uart_Callback c,void *data);

void uart_free(int uartName);

void uart_send(int uartname);

#endif

