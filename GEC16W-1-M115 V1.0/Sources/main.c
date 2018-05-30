
#include "PublicShare.h"
#include "xgate.h"
#include "ao.h"
#include "clock.h"
#include "dido.h"
#include "logic.h"
#include "eee.h"
#include "MSCAN12.h"
 uchar timidx;
 PRIVATE uchar cnt_5ms   = 1;
PRIVATE uchar cnt_10ms  = 2;
PRIVATE uchar cnt_20ms  = 4;
PRIVATE uchar cnt_50ms  = 6;
PRIVATE uchar cnt_100ms = 8;
PRIVATE uchar cnt_200ms = 10;
PRIVATE uchar cnt_500ms;
PRIVATE uchar cnt_1s;

#define MASK_5MS          5
#define MASK_10MS         10
#define MASK_20MS         20
#define MASK_50MS         50
#define MASK_100MS        100
#define MASK_200MS        200
unsigned char test=0; 
unsigned char CANTEST=0;


#pragma push

/* this variable definition is to demonstrate how to share data between XGATE and S12X */
#pragma DATA_SEG SHARED_DATA
//volatile int shared_counter; /* volatile because both cores are accessing it. */

/* Two stacks in XGATE core3 */ 
#pragma DATA_SEG XGATE_STK_L
word XGATE_STACK_L[1]; 
#pragma DATA_SEG XGATE_STK_H
word XGATE_STACK_H[1];

#pragma pop

#define ROUTE_INTERRUPT(vec_adr, cfdata)                \
  INT_CFADDR= (vec_adr) & 0xF0;                         \
  INT_CFDATA_ARR[((vec_adr) & 0x0F) >> 1]= (cfdata)

#define SOFTWARETRIGGER0_VEC  0x72 /* vector address= 2 * channel id */

static void SetupXGATE(void) {
  /* initialize the XGATE vector block and
     set the XGVBR register to its start address */
  XGVBR= (unsigned int)(void*__far)(XGATE_VectorTable - XGATE_VECTOR_OFFSET);

  /* switch software trigger 0 interrupt to XGATE */
  ROUTE_INTERRUPT(SOFTWARETRIGGER0_VEC, 0x81); /* RQST=1 and PRIO=1 */
  //ROUTE_INTERRUPT(PIT0_VEC, 0x81); /* RQST=1 and PRIO=1 */
  ROUTE_INTERRUPT(PIT2_VEC, 0x87); /* RQST=1 and PRIO=1 */
  ROUTE_INTERRUPT(SCI0_VEC, 0X81);
  ROUTE_INTERRUPT(SCI1_VEC, 0X81);
  ROUTE_INTERRUPT(SCI4_VEC, 0x81); /* RQST=1 and PRIO=1 */
  ROUTE_INTERRUPT(IOC0_VEC, 0x81); /* RQST=1 and PRIO=1 */
  ROUTE_INTERRUPT(IOC2_VEC, 0x81); /* RQST=1 and PRIO=1 */
  ROUTE_INTERRUPT(IOC3_VEC, 0x81); /* RQST=1 and PRIO=1 */
  ROUTE_INTERRUPT(OVF_VEC,  0x85); /* RQST=1 and PRIO=1 */
	ROUTE_INTERRUPT(PIT1_VEC, 0x81); /* RQST=1 and PRIO=1 */
	ROUTE_INTERRUPT(ATD0_VEC, 0x81); /* RQST=1 and PRIO=1 */

  /* when changing your derivative to non-core3 one please remove next five lines */
 // XGISPSEL= 1;
 // XGISP31= (unsigned int)(void*__far)(XGATE_STACK_L + 1);
 // XGISPSEL= 2;
 // XGISP74= (unsigned int)(void*__far)(XGATE_STACK_H + 1);
 // XGISPSEL= 0;

  /* enable XGATE mode and interrupts */
  XGMCTL= 0xFBC1; /* XGE | XGFRZ | XGIE */

  /* force execution of software trigger 0 handler */
  XGSWT= 0x0101;
}
#pragma push
#pragma CODE_SEG __NEAR_SEG  NON_BANKED

void interrupt 38 CAN_RECEIVE (void)             //CAN1接受中断
{
    INT8U *addr;                //接收帧首地址
    INT8U i;
    addr = (INT8U *) &CAN0RXIDR0;

    for (i = 0; i < 12; i++)
    {
        CANBUFF[CANRNUM*13+i] = * (addr + i);
    }

    CANBUFF[CANRNUM*13+12] = CAN0RXDLR & 0x0F;
    CanTimeOut = 0;

    if (CANRNUM < 10)
    {
        CANRNUM++;
    }

    CAN0RFLG |= 0x01;
}
                                                //CAN2接受中断
void interrupt 42 CAN1_RECEIVE (void)
{
    INT8U *addr;                //接收帧首地址
    INT8U i;
    addr = (INT8U *) &CAN1RXIDR0;

    for (i = 0; i < 12; i++)
    {
        CANBUFF2[CANRNUM2*13+i] = * (addr + i);
    }

    CANBUFF2[CANRNUM2*13+12] = CAN1RXDLR & 0x0F;

    //CanTimeOut=0;
    if (CANRNUM2 < 10)
    {
        CANRNUM2++;
    }

    CAN1RFLG |= 0x01;
}

void interrupt 54 CAN4_RECEIVE (void)           //CAN3接受中断
{
    INT8U *addr;                //接收帧首地址
    INT8U i;
    addr = (INT8U *) &CAN4RXIDR0;

    for (i = 0; i < 12; i++)
    {
        CANBUFF3[CANRNUM3*13+i] = * (addr + i);
    }

    CANBUFF3[CANRNUM3*13+12] = CAN4RXDLR & 0x0F;

    //CanTimeOut=0;
    if (CANRNUM3 < 10)
    {
        CANRNUM3++;
    }

    CAN4RFLG |= 0x01;
}


void interrupt 26 DC_OVERFLOW (void) //递减中断（用于转速计算）
{
    ECT_MCFLG_MCZF = 1;
    FREQSET++;
    ECT_MCCNT = 25000;

    if (FREQSET >= 80 && FREQCOMP < 5)
    {
        ECT_PBCTL = 0x00;

        if (FREQCOMP == 0)
        {
            FREQCOUNT = 0;
        }      
        FREQCOUNT += ECT_PACN10;
        ECT_PBCTL = 0x40;
        ECT_PACN10 = 0;
        FREQSET = 0;
        FREQCOMP++;
    }

    ECT_MCCTL_MCEN = 1;
}

void interrupt 119 ERR(void)
{
    CANTEST=1;
}

void interrupt 66 PIT0 (void)
{
 
   
  PITTF_PTF0=1;
  cnt_5ms++;
  cnt_10ms++;
  cnt_20ms++;
  cnt_50ms++;
  cnt_100ms++;
  cnt_200ms++;
 // BUZ  ^= 1;
  if(cnt_5ms  >= MASK_5MS)
  {
    schedule_5ms = 1;
    cnt_5ms   = 0;
  }
  if(cnt_10ms >= MASK_10MS)
  {
    schedule_10ms    = 1;
    cnt_10ms  = 0; 
  }
  if(cnt_20ms >= MASK_20MS)
  {
    schedule_20ms    = 1;
    cnt_20ms  = 0; 
  }
  if(cnt_50ms >= MASK_50MS)
  {
    schedule_50ms    = 1;
    cnt_50ms  = 0; 
  }
  if(cnt_100ms >= MASK_100MS)
  {
  
    schedule_100ms   = 1;
    
   
    
    
     for (timidx = 0; timidx < TMRNUM; timidx++)   //对定时器数组进行累加计算
    {
        if (TimerEnArr[timidx] == 1)
        {
            //如果定时器使能
            if(!(TimerMode[timidx]==0 && TimerTrig[timidx]))
            {              
                TimerValue[timidx]++;
            }
            if (TimerValue[timidx] >= TimerSet[timidx])
            {
                if (TimerMode[timidx] <= 1)
                {
                    TimerValue[timidx] = 0;
                    TimerEnArr[timidx] = TimerMode[timidx];
                }
                else
                {
                    TimerEnArr[timidx] = 0;
                }

                TimerTrig[timidx] = 1;
            }
        }
        else
        {
            if(TimerMode[timidx]!=2)
            {          
                TimerValue[timidx] = 0;
            }
        }
    }

    cnt_100ms = 0; 
    cnt_500ms++;
   
   
   
   
    if(cnt_500ms >= 5)
    {
      schedule_500ms  = 1;
      cnt_500ms       = 1;      
    }
  }
  if(cnt_200ms >= MASK_200MS)
  {
    schedule_200ms   = 1;
    cnt_1s++;
    if(cnt_1s >= 5)
    {
      schedule_1s  = 1;
      cnt_1s = 0;
    }
    cnt_200ms = 0; 
  }
}




#pragma pop

void main(void) 
{
  /* put your own code here */
 
SetupXGATE();
MCU_init(); 
 
EnableInterrupts;


  for(;;)
  {
   // _FEED_COP(); /* feeds the dog */        
    //if(COMMTYPE==0)
    {      
        SCI_Modbus(SYS_ADDR);    
    }
    StatusCheck(); 
    DES_STARTSTOP();
    Protection(); 
    RecProcess();
    EEPROM_PROCESS();
    CANRCVPROCESS();
    MCB_GCB_LOGIC();
    ADJUST_SPEED();    
    #if FEIERTE_MODE
    FET_BATT_PROTECTION();
    FET_BATT_MANAGEMENT();
    
      
    #endif

    #if GEC16P_MODE
    PS_LUBOILMAINTAIN();
    #endif
          
   	if(sftEVENT(schedule_5ms))
   	{
   		sftRESET_EVENT(schedule_5ms);		
      refreshdido();
      UpdateIO();
      ButtonProcess();	
      TRANSMIT_CAN_DATA_PARAM();		
   	}
    if(sftEVENT(schedule_10ms))
    {
        sftRESET_EVENT(schedule_10ms);
      
       

       
       sci_check(); 
       TransValue();
       #if FEIERTE_MODE                          
       if(FET_WORKMODE==0 && FET_LOADMODE==0)
        {        
            ao_output();
        }       
       ECU6800_SENDLOAD (KWALL100);
       FET_PID_CONTROL();            
       #endif  
       
    }
    if(sftEVENT(schedule_20ms))
    {
      sftRESET_EVENT(schedule_20ms);
      //if(CANTEST)
      //{        
      TRANSMIT_CAN_DATA();
      //}
    }
    if(sftEVENT(schedule_50ms))
    { 
      if(test==0)
      {
        
      ai_check();
      }
      sftRESET_EVENT(schedule_50ms);
      EXTEND_SEND();
    }
    if(sftEVENT(schedule_100ms))
    {
      sftRESET_EVENT(schedule_100ms);      
        
			  LoadRecordSets();
			  if (SYS_SET_DEFAULT_PARAM)
        {
            SetDefaultParam();
            SYS_SET_DEFAULT_PARAM = 0;
        }
    }
    if(sftEVENT(schedule_200ms))
    {
      sftRESET_EVENT(schedule_200ms);
		
    }
    if(sftEVENT(schedule_500ms))
    {
      if(CHECKDELAY<10)
      {
      CHECKDELAY++;
      }
      
      sftRESET_EVENT(schedule_500ms);
      
          if (SPLASH_500ms)
          {
              SPLASH_500ms = 0;
          }
          else
          {
              SPLASH_500ms = 1;
          }		

          if(COMMTYPE)
          {
              BroadcastSend();
          }
	
			
			      if (EnWriteTime == 1)
            {
                IIC_write_time (TIMESET_YEAR, TIMESET_MONTH, TIMESET_DATE, TIMESET_HOUR, TIMESET_MINUTE);
                EnWriteTime = 0;
            }
            else
            {
                TIMESET_SECOND = DATEVALUE[0];
                TIMESET_MINUTE = DATEVALUE[1];
                TIMESET_HOUR   = DATEVALUE[2];
                TIMESET_DATE   = DATEVALUE[4];
                TIMESET_MONTH  = DATEVALUE[5];
                TIMESET_YEAR   = DATEVALUE[6];
            }
            
            if (EnWriteTime == 0)
            {
                IIC_read_time (DATEVALUE); //读时钟芯片日期时间
            }
            
			
    }
    if(sftEVENT(schedule_1s))
    {
      sftRESET_EVENT(schedule_1s);
      #if FEIERTE_MODE	
      FET_BATTCAP_CAL();
      #endif
      CanTimeOut++;
      if(CanTimeOut>1)
      {
          if(SAFESYSTEM_COMMALARM)
          {
            
              ALA_CANFAIL=1;
          }
          else
          {
              ALA_CANFAIL=0;
          }
          EXTERNINPUT.Byte=0;
          SpeedError2=0;
          SpeedHigh2=0;
          OilPressureLow2=0;
      }
      else
      {
          ALA_CANFAIL=0;
      }
      AccumulationCalc();
      Timer_Management();
    }  
    
    
  
  } /* loop forever */
  /* please make sure that you never leave main */
}
