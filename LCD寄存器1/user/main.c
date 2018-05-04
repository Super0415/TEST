#include <stm32f10x.h>
#include "system.h"
#include "lcd.h"
/****************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
#define Delay_ms(time)               SYSTICK_Delay1ms(time)   	/*延时定义*/	
int main(void)
{  
	int num=0;
    /* 初始化 */
   SYSTEM_SetClock(72);        
	 LCD_Init1();
   LCD_Str_O(320-8*6, 239-16, "Runing",RED); 
	while(1)
	{
		num++;
	//	TFT_ClearScreen(GRED);
		TFT_ClearSpecailScreen(200,20,100,20,GRED);
		Delay_ms(100);
	//	LCD_Line(10,10+num*10, 100, 150);
//		LCD_Line(20,10+num*10, 100, 150);
	//	LCD_Line(30,10+num*10, 100, 150);
		LCD_Line(100,200, 300, 200);
		LCD_Line(100,210, 300, 210);
		LCD_Line(100,220, 300, 220);
		LCD_Line(100,230, 300, 230);
		LCD_Line(100,235, 300, 235);

	}                         
}

