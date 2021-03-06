#include "ADS1298.h"


void init_ADS1298_IO ()
{
	GPIO_PinDirection(ADS1298_CS,OUTPUT);
	GPIO_PinDirection(ADS1298_RESETB,OUTPUT);
	GPIO_PinDirection(ADS1298_START,OUTPUT);
	GPIO_PinDirection(ADS1298_GPIO1,OUTPUT);
	GPIO_PinDirection(ADS1298_GPIO2,OUTPUT);
	GPIO_PinDirection(ADS1298_DRDY,INPUT);
	GPIO_PinFunction(ADS1298_CS,PINSEL_FUNC_0);
	GPIO_PinFunction(ADS1298_RESETB,PINSEL_FUNC_0);
	GPIO_PinFunction(ADS1298_START,PINSEL_FUNC_0);
	GPIO_PinFunction(ADS1298_GPIO1,PINSEL_FUNC_0);
	GPIO_PinFunction(ADS1298_GPIO2,PINSEL_FUNC_0);
	GPIO_PinFunction(ADS1298_DRDY,PINSEL_FUNC_0);
	GPIO_PinFunction(ADS1298_SCK,PINSEL_FUNC_2);
	GPIO_PinFunction(ADS1298_MISO,PINSEL_FUNC_2);
	GPIO_PinFunction(ADS1298_MOSI,PINSEL_FUNC_2);
	Clear_ADS1292_Chip_Enable();
	GPIO_PinWrite(ADS1298_RESETB,1);
}

void Set_ADS1292_Chip_Enable (void)
{
	GPIO_PinWrite(ADS1298_CS,LOW);
}
void Clear_ADS1292_Chip_Enable (void)
{
	GPIO_PinWrite(ADS1298_CS,HIGH);
}

void Hard_Start_ReStart_ADS1x9x()
{
		GPIO_PinWrite(ADS1298_RESETB,LOW);
		delay_ms(2000);
		GPIO_PinWrite(ADS1298_RESETB,HIGH);
}		
