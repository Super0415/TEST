#include "lcd_gui.h"
#include "GUI.h"



void StartShow(void)
{

	GUI_SetColor(GUI_BLUE);
	GUI_DispStringAt("ucGUI Success again", 60, 10);
	
	delay_ms(1000);	
	
	GUI_Clear();

	delay_ms(1000);
	
	GUI_SetColor(GUI_RED);
	//GUI_Font();
	GUI_SetFont(GUI_ASCII_FONT);
	GUI_DispStringAt("ucGUI Success again", 60, 40);

	delay_ms(1000);
}






