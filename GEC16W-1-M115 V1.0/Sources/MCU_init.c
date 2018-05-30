#include "PublicShare.h"


//#include "hidef.h"      /* common defines and macros */
//#include "MC9S12XET256.h"     /* derivative information */
//#include "pinout.h"
//#include "string.h"
//#include "extern.h"
//#include "defs.h"
#include "btn.h"
#include "ai.h" 
#include "ao.h"
#include "sci.h"
//#include "xgate.h" 
//#include "main.h"
//#include "math.h"
#include "dido.h"
#include "eee.h"
#include "buz.h"
#include "eeprom.h"
#include "io.h"
//#include "share.h"
#include "lcd.h"
#include "warn.h"
#include "logic.h"
//#include "alloc.h"
#include "MSCAN12.h"
#include "MCU_init.h"


#pragma CODE_SEG DEFAULT
#pragma DATA_SEG DEFAULT

void InitI2C(void)
{
    IIC0_IBCR_IBEN = 1;
    IIC0_IBFD = 0x2A;
    IIC0_IBSR_IBAL = 1;
}
//************************************************************************************
//函数名称：  SCI_init()
//功能描述：  初始化串口
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void SCI_init() 
{
	//SCI4BD 			= 130;   // baudrate = 9600: baudrate = busfreq/sci0bd/16 
	//SCI4CR2_TE 	= 1;		// Enable transmitter
	//SCI4CR2_RE 	= 1;		// Enable receiver
	//SCI4CR2_RIE = 1;		// Enable the SCI Rx interrupt
} 
//************************************************************************************
//函数名称：  CAN_init()
//功能描述：  初始化CAN
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void CAN_init() 
{
}
//************************************************************************************
//函数名称：  PIT_init()
//功能描述：  initial periodic interrupt timer as 1ms,channel 0
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void schedule_init() 
{
  PITCFLMT_PITE=0; //disable PIT
  PITCE_PCE0= 1;    //enable PIT channel 0
  PITCE_PCE1= 1;    //enable PIT channel 1
  PITCE_PCE2= 1;
  PITMTLD0  = 2-1;  //micro timer 0 equals 2 bus clock , 10MHz
  PITLD0    = 10000-1; //time base 0 equeals 10000 micro timer 0
  PITLD1 		= 3125;
  
  PITMTLD1 = 0; 
  
  //PITMTLD0 = 125 - 1; //8位定时器0初值设定。250分频，在40MHzBusClock下，为0.16MHz
  //PITMTLD1 = 0;  //8位定时器1初值设定。0分频，40MHzBusClock下，为40MHz
  PITMUX_PMUX2 = 1;
  PITLD2 = 6250;
  
  PITINTE_PINTE0 = 1;  //enable PIT channel 0 inttrupt
  PITINTE_PINTE1 = 1;  //enable PIT channel 0 inttrupt
  PITINTE_PINTE2 = 1;
  PITCFLMT_PITE  = 1;  //enable PIT    
  
  
  
}
//************************************************************************************
//函数名称：  ECT_init()
//功能描述：  初始化ECT
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void ECT_init() 
{
	ECT_TSCR1   = 0x88;   //enable timer function, enable the presion timer
	ECT_PTPSR   = 0x01;   //clock = fBUS / 2 = 10MHz
	ECT_TSCR2   = 0x80;   //hardveare inerrupt requested when TOF flag set
	ECT_ICSYS   = 0x02;   //BUFFEN = 1, enable input capture holding register
	ECT_TIOS    = 0;
	ECT_ICOVW   = 0xFF;   //prevent holding register was overwritten
	ECT_TCTL4   = 0xA2;   //channel 0 MP, channel 2 freq, channel 3 freq, falling edge capture    
  ECT_DLYCT   = 0xFF;   //delay 64 bus clock cycles     
  ECT_TFLG1   = 0XFF;
  //ECT_PBCTL   = 0x40; 
  //ECT_MCCTL   = 0x83;
  ECT_MCCNT   = 50000;  
	
  ECT_TIE     = 0X0D;   //enable channel 0, 2,3 intterupt    
} 

PRIVATE void InitECT (void)
{
    ECT_TSCR1 = 0x88;
    ECT_PTPSR = 0x03;
    ECT_TSCR2 = 0x80;
    ECT_ICSYS = 0x02;
    ECT_TIOS  = 0;
    ECT_ICOVW = 0xFF;
    ECT_TCTL4 = 0xA2;
   // ECT_DLYCT = 0x0F;
    ECT_DLYCT = 0xFF;
    ECT_TFLG1 = 0XFF;
    ECT_PBCTL = 0x40;
    ECT_MCCTL = 0x83;
    ECT_MCCNT = 25000;
   // ECT_TIE   = 0X0D;   //enable channel 0, 2,3 intterupt    
    ECT_TIE=0X0D;
}

//************************************************************************************
//函数名称：  CLOCK_init()
//功能描述：  初始化时钟osc frequency is 8MHz,fBUS = 20MHz， fPLL = 40MHz
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void CLOCK_init()
{
    CLKSEL=0X00;		// disengage PLL to system
    PLLCTL_PLLON=1;		// turn on PLL
    SYNR=0x40 | 0x04; 	// VCOFRQ[7:6];SYNDIV[5:0]
                        // fVCO= 2*fOSC*(SYNDIV + 1)/(REFDIV + 1)
                        // fPLL= fVCO/(2 × POSTDIV) 
                        // fBUS= fPLL/2 
                        // VCOCLK Frequency Ranges  VCOFRQ[7:6]
                        // 32MHz <= fVCO <= 48MHz    00
                        // 48MHz <  fVCO <= 80MHz    01
                        // Reserved                  10
                        // 80MHz <  fVCO <= 120MHz   11				
    REFDV=0x80 | 0x00;  // REFFRQ[7:6];REFDIV[5:0]
                        // fREF=fOSC/(REFDIV + 1)
                        // REFCLK Frequency Ranges  REFFRQ[7:6]
                        // 1MHz <= fREF <=  2MHz       00
                        // 2MHz <  fREF <=  6MHz       01
                        // 6MHz <  fREF <= 12MHz       10
                        // fREF >  12MHz               11                         
                        // fVCO=2*osc*(1+SYNR)/(1+REFDV)=80MHz;
    POSTDIV=0x01;       // 4:0, fPLL= fVCO/(2xPOSTDIV)  = 40MHz
                        // If POSTDIV = $00 then fPLL is identical to fVCO (divide by one).
    nop();          // BUS CLOCK=20M
    nop();
    while(!(CRGFLG_LOCK==1));	  //when pll is steady ,then use it;
    CLKSEL_PLLSEL =1;		        //engage PLL to system; 
    FCLKDIV = 0X07;
		
}

PRIVATE VAR_init(void)
{
uchar i;
STRFLG32 TMP;
EN_DES_PROTECT_WT=1;
EN_DES_PROTECT_SPEED=1;

for(i=0;i<AI_NUM;i++)
{  
    ADJUST[i]=1.0;
}

    PID_PARAM.usGain=20;
    PID_PARAM.usStability=500;
    PID_PARAM.usDerivative=20;
    PID_PARAM.usInputOld=0;    
    PID_PARAM.uiCtrlOld=0; 
    PID_PARAM.uiCtrlMin=0;
    PID_PARAM.uiCtrlMax=161280;
    NowMode=MODESAVE;
    
    lastmode=NowMode;
    ForceMode(NowMode);        
    TimerMode[TMR_GEN_GCB_DELAY] =1;

    TimerMode[TMR_SECOND] = 1;
    STA_DES_STOP=1;


}

//************************************************************************************
//函数名称：  MCU_init()
//功能描述：  initial MCU peripheral device
//输入参数：
//输出参数：
//************************************************************************************  



PUBLIC void MCU_init(void) 
{
  CLOCK_init();
	eee_load_par();
  schedule_init();
  //ECT_init();
  CANInit();
  InitECT();
  InitI2C();
  VAR_init();
  //SCI_init();
  	
	hrdadc_init();
	#if FEIERTE_MODE
	hrdao_init();
	#endif
	hrddido_init();
	#if PCB16DW
	PERJ_PERJ0=0;
	PERJ_PERJ1=0;
	PUCR_PUPKE=0;
	#endif
	SCIOpenCommunication(0);
	SCIOpenCommunication(1);
	
	//hrdbuz_init();
	//hrdbtn_init();	
	
//	hrddido_init();
//	hrdeeprom_init();
//	hrdio_init();


// hrdlcd_init();
//	hrdlogic_init();
//	hrdwarn_init();
//	FLAG.Byte = 0;
}
  
  
