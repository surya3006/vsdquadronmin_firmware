#include "gpio.h"
#include "uart.h"

void GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    // 1. Enable Clock for Port D (For LED, Button, and UART TX) [cite: 253, 254]
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_USART1, ENABLE);

    // 2. Configure PD4 as Push-Pull Output (LED)
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    // 3. Configure PD0 as Input with Pull-Up (Button)
    // We use Pull-Up so the pin is HIGH by default, and goes LOW when pressed (connected to GND).
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    
    // 4. Configure PD5 as Multiplexed Push-Pull Output (UART TX) [cite: 582]
    // Note: UART init function below usually handles the peripheral enable, 
    // but the pin mode must be AF_PP.
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    // Configure Blinky LED Pin
    BLINKY_CLOCK_ENABLE;
	GPIO_InitStructure.GPIO_Pin = BLINKY_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(BLINKY_GPIO_PORT, &GPIO_InitStructure);
}

// TO write to the GPIO pin to set it high
void gpio_set(void){
    GPIO_SetBits(BLINKY_GPIO_PORT, BLINKY_GPIO_PIN);
}

// To write to the GPIO pin to set it low
void gpio_reset(void){
    GPIO_ResetBits(BLINKY_GPIO_PORT, BLINKY_GPIO_PIN);
}
void Toggle_LED(void)
{
    while (1)
	{
		gpio_set();
        USART1_SendString("LED ON\r\n");
		Delay_Ms(500);

        gpio_reset();
        USART1_SendString("LED OFF\r\n");
        Delay_Ms(500);
	}
}