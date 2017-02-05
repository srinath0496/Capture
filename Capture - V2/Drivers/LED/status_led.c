#include "gpio.h"
#include "status_led.h"

void init_status_led(uint8_t ledno)
{
	GPIO_PinDirection(ledno,OUTPUT);
}
