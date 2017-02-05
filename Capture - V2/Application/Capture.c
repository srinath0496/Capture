/***************************************************************************************************
                                   ECG Capture    
 ****************************************************************************************************
 * File:   capture.c
 * Version: 0.0
 * Author: Srinath Adipudi
 * Website: 
 * Description: File contains the Main function
 **************************************************************************************************/
/* Includes*/
#include "Capture.h"

/*Global Variable*/

/*Extern Variable*/


int main()
{
		char option;
		uint8_t wr_buffer[2];
		SystemInit();
		init_ADS1298_IO();
		init_status_led(LED1);
	  init_status_led(LED2);
		init_status_led(LED3);
		init_status_led(LED4);

		UART0_Init(9600); 
 	UART0_Printf("Welcome to Ram ECG Capture\r");
	while(1)
	{
		
		UART0_Printf("1. Set CS\r2. Clear CS\r3. Reset\r");
		option=UART0_RxChar();
		switch(option)
		{
			case '1' : UART0_Printf("Setting the CS\r");
								 Set_ADS1292_Chip_Enable();
								 //GPIO_PinWrite(P0_16,1);
								 break;
			case '2' : UART0_Printf("Clearing the CS\r");
							   Clear_ADS1292_Chip_Enable();
								 //GPIO_PinWrite(P0_16,0);
								 break;
			case '3' : UART0_Printf("Hard Reset ADS1298\r");
								 Hard_Start_ReStart_ADS1x9x();
								 break;
			case '4' : UART0_Printf("Init ADS1298 SPI Driver\r");
							   SSP0Init();
								 break;
			case '5' : UART0_Printf("Write to ADS1298\r");
								 wr_buffer[0]=0xff;
								 SSPSend(0,wr_buffer,2);
		}
		GPIO_PinToggle(LED1);
		GPIO_PinToggle(LED2);
		GPIO_PinToggle(LED3);
		GPIO_PinToggle(LED4);
	}
}

