/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��main.c
 * ����    ����3.5.0�汾���Ĺ���ģ�塣         
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��www.ourdev.cn/bbs/bbs_list.jsp?bbs_id=1008
 * �Ա�    ��http://firestm32.taobao.com
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
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 */
int TESTZCNUM[10];
int main(void) 
{	
	char tmp[100] = {'0'}; 
	SysTick_Init();                         /*systick ��ʼ��*/
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


