#ifndef __GPIO_H
#define __GPIO_H

#include <stdint.h>
#include <ch32v00x.h>
#include "debug.h" // Includes standard WCH UART and System definitions

#define BLINKY_GPIO_PORT GPIOD
#define BLINKY_GPIO_PIN GPIO_Pin_6
#define BLINKY_CLOCK_ENABLE RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE)

void GPIO_Config(void);
void Toggle_LED(void);

#endif /* __GPIO_H */