#include "extern.h"
#include "hidef.h"      /* common defines and macros */
#include <MC9S12XS128.h>
#include "string.h"
#include "defs.h"
#include "btn.h"
#include "lcd.h"
#include "main.h"
#include "alloc.h"
#include "MCU_init.h"
#include "lcdfont.h"

PRIVATE void clock_init(void)
{
    CLKSEL=0X00;		// disengage PLL to system
    PLLCTL_PLLON=1;		// turn on PLL
    SYNR=0x40 | 0x09; 	// VCOFRQ[7:6];SYNDIV[5:0]
                        // fVCO= 2*fOSC*(SYNDIV + 1)/(REFDIV + 1)
                        // fPLL= fVCO/(2 × POSTDIV) 
                        // fBUS= fPLL/2 
                        // VCOCLK Frequency Ranges  VCOFRQ[7:6]
                        // 32MHz <= fVCO <= 48MHz    00
                        // 48MHz <  fVCO <= 80MHz    01
                        // Reserved                  10
                        // 80MHz <  fVCO <= 120MHz   11				
    REFDV=0x40 | 0x01;  // REFFRQ[7:6];REFDIV[5:0]
                        // fREF=fOSC/(REFDIV + 1)
                        // REFCLK Frequency Ranges  REFFRQ[7:6]
                        // 1MHz <= fREF <=  2MHz       00
                        // 2MHz <  fREF <=  6MHz       01
                        // 6MHz <  fREF <= 12MHz       10
                        // fREF >  12MHz               11                         
                        // fVCO=2*osc*(1+SYNR)/(1+REFDV)=80MHz;
    POSTDIV=0x00;       // 4:0, fPLL= fVCO/(2xPOSTDIV)  = 40MHz
                        // If POSTDIV = $00 then fPLL is identical to fVCO (divide by one).
    nop();          // BUS CLOCK=20M
    nop();
    while(!(CRGFLG_LOCK==1));	  //when pll is steady ,then use it;
    CLKSEL_PLLSEL =1;		        //engage PLL to system; 
    //FCLKDIV = 0X07;
/*
  CLKSEL=0x00;//时钟选择外部时钟
  PLLCTL_PLLON=0;
  SYNR=0;
	REFDV=0;
  PLLCTL_PLLON=1;//锁相环控制使能
  while(!(CRGFLG_LOCK==1));
  CLKSEL_PLLSEL=1;//选定锁相环时钟
  COPCTL=0;
	ARMCOP=0;//看门狗控制,看门狗复位
  RTICTL=0x6f;
  CYCLE_TIME=((RTICTL&0x0F)+1)*2^(((RTICTL&0xF0)>>4)+9)/BUS_FRE/2;
  CRGINT_RTIE=1;
*/
}
//初始化输入捕捉与定时PIT--------------------------------------
PRIVATE void ic7_init(void)
{
  PACTL=0x50; //PAI使能,事件计数,脉冲输入(PT7/PAI),预分频肘钟,禁溢出和输入中断
  PITCE_PCE0=1;//The corresponding PIT channel is enabled
  PITMTLD0=127;//相当于分频数
  PITLD0=43200;//计数初值重载于PITCNT
  PITFLT_PFLT0=1;//PIT Force Load Timer Register
  PITINTE_PINTE0=1;//Interrupt of the corresponding PIT channel is enabled.
  PITCFLMT_PITE=1;//PIT is enabled
  PITCFLMT_PFLMT0=1;
}
PRIVATE void io_init(void)
{		
	//按键IO口初始化
	//DDR0AD0=0X00;
  //PT0AD0=0XFF;
//#if 0
	DDR_BTN_ON_OFF_EN	 = 0;
	DDR_BTN_ON_OFF_GE	 = 0;
	DDR_BTN_PAGE_UP		 = 0;
	DDR_BTN_PAGE			 = 0;
	DDR_BTN_PAGE_DOWN	 = 0;
	DDR_BTN_START			 = 0;	
	DDR_BTN_FALT_RESET = 0;
	DDR_BTN_STOP			 = 0;	
//#endif
	DDR_ENTER					 = 0;	
	DDR_HORN_RESET		 = 0;	
	DDR_MODE_LEFT			 = 0;	
	DDR_MODE_RIGHT		 = 0;
	
	#if LCDMODE
	//LCD控制与数据口初始化
	

	
 	DDR_LCD_LED				 = 1;	     	
 	DDR_LCD_CS1     	 = 1;
 	DDR_LCD_RST        = 1;	
 	DDR_LCD_WR      	 = 1;
 	DDR_LCD_A0      	 = 1;
	DDR_LCD_RD				 = 1;
 	DDR_LCD_DATA_BIT0  = 1;
 	DDR_LCD_DATA_BIT1	 = 1;
 	DDR_LCD_DATA_BIT2	 = 1;
 	DDR_LCD_DATA_BIT3	 = 1;
 	DDR_LCD_DATA_BIT4	 = 1;
 	DDR_LCD_DATA_BIT5	 = 1;
 	DDR_LCD_DATA_BIT6	 = 1;
 	DDR_LCD_DATA_BIT7	 = 1;
 	
 	LCD_LED            = 1;	
	LCD_CS1            = 0;
	LCD_RST            = 0;
	LCD_WR						 = 0;
	LCD_A0						 = 0;
	LCD_RD					   = 1;
	LCD_DATA_BIT0			 = 0;
	LCD_DATA_BIT1			 = 0;
	LCD_DATA_BIT2			 = 0;
	LCD_DATA_BIT3			 = 0;
	LCD_DATA_BIT4			 = 0;
	LCD_DATA_BIT5			 = 0;
	LCD_DATA_BIT6			 = 0;
	LCD_DATA_BIT7			 = 0;	
 	
 	
 	
 	
 #endif	
 	
 #if VFDMODE	
 
 
 	DDR_VFD_POWER      = 1;
  DDR_VFD_PBUSY      = 0;
 	DDR_VFD_RS         = 0;
  DDR_VFD_RD	       = 1;
  DDR_VFD_WR         = 1;
  DDR_VFD_DATA_BIT0  = 1;
  DDR_VFD_DATA_BIT1  = 1;
  DDR_VFD_DATA_BIT2  = 1;
  DDR_VFD_DATA_BIT3  = 1;
  DDR_VFD_DATA_BIT4  = 1;
  DDR_VFD_DATA_BIT5  = 1;
  DDR_VFD_DATA_BIT6  = 1;
  DDR_VFD_DATA_BIT7  = 1; 
 
 
 	VFD_RS             = 0;
 	VFD_RD             = 0;
 	VFD_WR             = 0;
 	
 	LCD_DATA_BIT0      = 0;
 	LCD_DATA_BIT1      = 0;
 	LCD_DATA_BIT2      = 0;
 	LCD_DATA_BIT3      = 0;
 	LCD_DATA_BIT4      = 0;
 	LCD_DATA_BIT5      = 0;
 	LCD_DATA_BIT6      = 0;
 	LCD_DATA_BIT7      = 0;
 	

  
  VFD_POWER=1;
  #endif
  
  
	//LED端口初始化
	LED1 = 1;
	LED2 = 1;
	LED3 = 1;
	LED4 = 1;
	LED5 = 1;
	LED6 = 1;
	DDR_LED1 = 1;
	DDR_LED2 = 1;
	DDR_LED3 = 1;
	DDR_LED4 = 1;
	DDR_LED5 = 1;
	DDR_LED6 = 1;
//	ATD0CTL0=0x07;
//	ATD0CTL3_DJM=1;
	
	ATD0DIENL=0xFF;
  //PER0AD0=0xFF;
  DDR0AD0=0x00;
  //ATD0CTL5_SCAN=1;
  
}
//************************************************************************************
//函数名称：  PIT_init()
//功能描述：  initial periodic interrupt timer as 1ms,channel 0
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void PIT_init() 
{
  PITCFLMT_PITE=0; //disable PIT
  PITCE_PCE0= 1;    //enable PIT channel 0
  //PITCE_PCE1= 1;    //enable PIT channel 1
  
  //PITMTLD0  = 2-1;  //micro timer 0 equals 2 bus clock , 10MHz
  //PITLD0    = 10000-1; //time base 0 equeals 10000 micro timer 0
  PITMTLD0=250;
  PITLD0=160-1;
  PITINTE_PINTE0 = 1;  //enable PIT channel 0 inttrupt
  PITCFLMT_PITE  = 1;  //enable PIT    
}
PRIVATE void ram_init(void)
{
	F_CLR_LCD			= 1;
	lcd_state = lcd_display;
	
}

PRIVATE void VAR_init(void)
{
   uchar i;
   lcd_disp_cursor_setup=1;
   lcd_disp_point_setup=1;
   lcd_disp_cursor_submenu=1;
   lcd_disp_point_submenu=1;
   lcd_disp_ParamMode=0;
   PowerPercent=0;
   lcd_rec_cursor=3;
   NowPage=20;
   lcd_disp_ParamConfirm=0;
   CHECKFLAG=1;
   RETURNFLAG=0;
   for(i=0;i<10;i++)
   {
   ALACONFIRM[i]=1;
   }

   EnREC=0;
   

   
   PASSWORD=0;
 
 
 #if B_MODE

  PageShow.Pages[1]->Disable=1;
  PageShow.Pages[2]->Disable=1;
  
  if(SHOWCOIL==0)
  {  
      PageShow.Pages[3]->Disable=1;
  }
  
  
  PageShow.Pages[5]->Disable=1;
  //PageShow.Pages[10]->Disable=1;
  //PageShow.Pages[11]->Disable=1;
  
 #endif


}

PUBLIC void MCU_init(void)
{
	clock_init();
	ic7_init();
	PIT_init();
	io_init();
	ram_init();
	#if LCDMODE
	lcd_initial();
	#endif
	VAR_init();
	// PT0AD0_PT0AD00
  
}

