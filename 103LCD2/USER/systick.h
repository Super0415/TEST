#ifndef __SYSTICK_H
#define __SYSTICK_H 
   
#include "stm32f10x.h"


void SysTick_Init(void);
void Delay_us(__IO u32 nTime);//��λ10us
#define  delay_ms(x)	Delay_us( 100*x)   


#endif



























