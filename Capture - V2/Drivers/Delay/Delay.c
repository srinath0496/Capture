#include "Delay.h"
void delay_ms (uint16_t ms)
{
 uint16_t delay;
 volatile uint32_t i;
 for (delay = ms; delay >0 ; delay--)
//1ms loop with -Os optimisation
  {
  for (i=3500; i >0;i--){};
  }
}