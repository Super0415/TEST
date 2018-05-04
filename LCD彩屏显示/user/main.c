#include <stm32f10x.h>
#include "system.h"
#include "led.h"
#include "gui.h"
#include "usart.h"

/****************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

int main(void)
{
    uint8_t ledState = 0;
    uint8_t num = 5;
    uint32_t i;
    
    /* ≥ı ºªØ */
    SYSTEM_SetClock(72);        
    TFT_Init();
    LED_Config();

	while(1)
	{
        i++;
        if(i > 0xFFFFF)
        {
            i = 0;
            if(ledState == 0xFE)
            {
                ledState = 0xFF;
            }
            else
            {
                ledState = 0xFE;
            }
            LED_SetState(ledState);

            num++;
            if(num == 21)
            {
                num = 0;
            }
            /* ∆¡œ‘ æ */
            switch(num)
            {
                case(0):
                    GUI_Box(0, 0, TFT_XMAX, 49, WHITE);
                    GUI_Box(0,  50, TFT_XMAX, 99, BLACK);
                    GUI_Box(0,  100, TFT_XMAX, 149, BLUE);
                    GUI_Box(0,  150, TFT_XMAX, 199, RED);
                    GUI_Box(0,  200, TFT_XMAX, 249, MAGENTA);
                    GUI_Box(0,  250, TFT_XMAX, 299, GREEN);
                    GUI_Box(0,  300, TFT_XMAX, 349, CYAN);
                    GUI_Box(0,  350, TFT_XMAX, 399, YELLOW);
                    break;
                case(6):                    
                    TFT_ClearScreen(BLACK);
                    GUI_Show12ASCII(90, 0, "PERCHIN", RED, BLACK);
                    GUI_Show12ASCII(0, 16, "welcome to the world of STM32!", RED, BLACK);
                    break;
                case(13):
                    GUI_Box(0, 0, 29, TFT_YMAX, WHITE);
                    GUI_Box(30,  0, 59, TFT_YMAX, BLACK);
                    GUI_Box(60,  0, 89, TFT_YMAX, BLUE);
                    GUI_Box(90,  0, 119, TFT_YMAX, RED);
                    GUI_Box(120,  0, 149, TFT_YMAX, MAGENTA);
                    GUI_Box(150,  0, 179, TFT_YMAX, GREEN);
                    GUI_Box(180,  0, 209, TFT_YMAX, CYAN);
                    GUI_Box(210,  0, 239, TFT_YMAX, YELLOW);
                    break;
                default:
                    break;
            }
        }
	}                         
}

