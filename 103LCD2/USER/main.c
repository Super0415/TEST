/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * 文件名  ：main.c
 * 描述    ：用3.5.0版本建的工程模板。         
 * 实验平台：野火STM32开发板
 * 库版本  ：ST3.5.0
 *
 * 作者    ：wildfire team 
 * 论坛    ：www.ourdev.cn/bbs/bbs_list.jsp?bbs_id=1008
 * 淘宝    ：http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "lcd.h" 
#include "systick.h" 
#include "Touch.h"				

#include "GUI.h"
#include "lcd_gui.h"
#include "stdio.h"
extern volatile unsigned char touch_flag;


void delay_main(u32 times)
{
	int i;
	for(i = times;i>0;i--);
}

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 */
int TESTZCNUM[10];
int main(void) 
{	
	char tmp[100] = {'0'}; 
	SysTick_Init();                         /*systick 初始化*/
	GUI_Init();
		
    while (1)	
    {	
			 //StartShow();
	//		GUI_SetColor(GUI_BLUE);
	//			delay_ms(1000);	
	//      GUI_Clear();
			  delay_ms(1000);	
			LCD_Str_R(100,100,"1233",14,0x0000,0xFFFF);
			sprintf(tmp, "%ld", (long)TESTZCNUM[0]); 
			GUI_DispStringAt(tmp,200,200);
			TESTZCNUM[1]++;
			GUI_GotoXY(100,150); GUI_DispDecSpace(TESTZCNUM[1],6);
			
			LCD_Str_O(150, 100, tmp, 0);
    }    
}

   

/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/


