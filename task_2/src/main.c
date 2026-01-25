#include "uart.h"
#include "gpio.h"
#include "stdio.h"

/* --- Configuration Definitions --- */
#define BOARD_NAME       "VSDSquadron Mini"
#define MCU_TYPE         "CH32V003F4U6"
#define FIRMWARE_VERSION "v1.0.0"
#define BUILD_DATE       __DATE__  
#define BUILD_TIME       __TIME__  

/* Function to print system details */
void Print_Boot_Info(void)
{
    char buffer[128];
    USART1_SendString("\r\n");
    USART1_SendString("****************************************\r\n");
    USART1_SendString("* SYSTEM BOOT SUCCESSFUL        *\r\n");
    USART1_SendString("****************************************\r\n");
    // Format and send Board Name
    sprintf(buffer, " Board Details    : %s\r\n", BOARD_NAME);
    USART1_SendString(buffer);

    // Format and send MCU Type
    sprintf(buffer, " MCU Model        : %s\r\n", MCU_TYPE);
    USART1_SendString(buffer);

    // Format and send Firmware Version
    sprintf(buffer, " Firmware Version : %s\r\n", FIRMWARE_VERSION);
    USART1_SendString(buffer);

    // Format and send Build Date/Time (Macros from compiler)
    sprintf(buffer, " Build Date/Time  : %s %s\r\n", __DATE__, __TIME__);
    USART1_SendString(buffer);

    USART1_SendString("----------------------------------------\r\n");

    // Format and send System Clock (Integer conversion)
    sprintf(buffer, " System Clock     : %d MHz\r\n", (int)(SystemCoreClock / 1000000));
    USART1_SendString(buffer);

    USART1_SendString(" Device Interface : UART1 (PD5/TX) @ 115200 bps\r\n");
    USART1_SendString("****************************************\r\n\r\n");
}

// Main function
int main(void)
{
    // Initialize System Clock
    SystemCoreClockUpdate();

    // Initialize GPIO
    GPIO_Config();

    // Initialize USART1 with baudrate 115200
    USART_Print_Init(115200);
    // Print boot information
    Print_Boot_Info();
    
    char buffer[10]; // Buffer to hold the converted number string
    Delay_Init();
    // 2. Loop from 1 to 10
    for(int i = 1; i <= 10; i++)
    {
        // Convert the integer 'i' into a string stored in 'buffer'
        sprintf(buffer, "%d", i);

        // Send the number string
        USART1_SendString(buffer);

        // Send a newline manually
        USART1_SendString("\r\n");

        // Delay to make it readable
        Delay_Ms(500);
        
    }
    Toggle_LED();
    USART1_SendString("Done!\r\n");

    // while(1) // Infinite Loop: Never leave this!
    // {
    //     // 1. Constantly ask: "Is the button pressed?"
    //     if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_0) == 0)
    //     {
    //         // 2. Button was pressed! Do the work.
    //         USART1_SendString("Button Pressed!\r\n");
    //         Toggle_LED();

    //         // // 3. WAIT for the user to let go of the button
    //         // while(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_0) == 0)
    //         // {
    //         //     // Do nothing, just wait for release
    //         // }

    //         // // 4. Slight delay to handle mechanical bounce (Debounce)
    //         // Delay_Ms(50);
    //     }
    //}
}
