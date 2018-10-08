/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File LCDCortex.c                        */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   LCD_GLOBALS
#include "TYPCortex.h"
#include "lcd_drive.h"
#include "TestShow.h"


/* ******************************************************************** */
/*                              LCDInit ()                              */
/* ******************************************************************** */
#if (LCD_FUNCTION_ON == 1)
void LCDInit (void)
{
    uiLCDStatus = 0;
    GUI_Init(); 
	  KEY_LEDInit();
	
	  NowPage_Num[0] = 0xFF;
	  NowPage_Num[1] = 0xFF;
}
#endif

/* ******************************************************************** */
/*                              LCDStart ()                             */
/* ******************************************************************** */
#if (LCD_FUNCTION_ON == 1)
void LCDStart (void)
{
  Screen_Intro();
}
#endif

/* ******************************************************************** */
/*                            LCDTaskLoop ()                            */
/* ******************************************************************** */
#if (LCD_FUNCTION_ON == 1)
void LCDTaskLoop (void)
{
	TestShowTask();
}
#endif




void Screen_Intro(void)
{
    GUI_SetBkColor(GUI_RED);
    GUI_SetColor(GUI_WHITE);
	  GUI_SetFont(&GUI_Font13HB_1);
    GUI_Clear();

    GUI_DispStringHCenterAt("RS485 AND CAN TEST DEVICE", LCD_GET_XSIZE()/ 2,100);
	  GUI_DispStringHCenterAt("DATA:2018-9-16           ", LCD_GET_XSIZE()/ 2,130);
}






/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
