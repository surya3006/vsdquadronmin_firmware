#ifndef __UART_H
#define __UART_H

#include <stdint.h>
#include <ch32v00x.h>
#include "debug.h"
#include <stdio.h>

void USART_Print_Init(uint32_t baudrate);
void USART1_SendChar(char c);
void USART1_SendString(const char *s);

#endif /* __UART_H */