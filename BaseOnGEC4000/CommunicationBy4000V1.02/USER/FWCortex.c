/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File FWCortex.c                         */
/*                            By: Wu Xuekui                             */
/*                             2017-04-18                               */
/* ******************************************************************** */

#define   FW_GLOBALS
#include "TYPCortex.h"
// 0 - LCD   1 - XIO  2 - CAN1  4 - SCI1  7 - DB
int TESTZCnum[50];
int TESTZC[20];
/* ******************************************************************** */
/*                                main()                                */
/* ******************************************************************** */
int main (void)
{ 
  OS_INT_DIS();                            /* Disable interrupts      */
    (void)FWInitRCC();                       /* initialize the RCC      */
    (void)FWInitClkHSI();                    /* initialize the HSI Clk  */
    (void)FWInitPMC();                       /* initialize the PMC      */
    (void)FWInitFLASH();                     /* initialize the FLASH    */
    (void)OSInit();                          /* Initialize OS  Model    */
    (void)FWInit();                          /* initialize Frame Work   */
    #ifdef FW_TASK_PRIO_DB
    (void)DBInit();                          /* Initialize Database     */
    #endif
//    //(void)SFInit();                          /* Initialize Standard Fun */
//    #ifdef FW_TASK_PRIO_CAN1
//    (void)CAN1Init();                        /* Initialize CAN1 Model   *///CAN1硬件初始化干扰屏幕
//    #endif
//    #ifdef FW_TASK_PRIO_CAN2
//    (void)CAN2Init();                        /* Initialize CAN2 Model   */
//    #endif
    #ifdef FW_TASK_PRIO_SCI1
//    (void)SCI1Init();                        /* Initialize SCI1 Model   */
    USART485_Init();
	  USART485_DataInit();
    USART485_Tim2_Init();	
    #endif
//    #ifdef FW_TASK_PRIO_SCI2
//    (void)SCI2Init();                        /* Initialize SCI2 Model   */
//    #endif
//    #ifdef FW_TASK_PRIO_SCI3
//    (void)SCI3Init();                        /* Initialize SCI3 Model   */
//    #endif
//    #ifdef FW_TASK_PRIO_FFT
//    (void)FFTInit();                         /* Initialize FFT Model    */
//    #endif
//    #ifdef FW_TASK_PRIO_XIO
////    (void)XIOInit();                         /* Initialize XIO Model    */
//    #endif
//    #ifdef FW_TASK_PRIO_SDIO
//    (void)SDIOInit();                        /* Initialize SDIO Model   */
//    #endif

    #ifdef FW_TASK_PRIO_LCD
//    (void)LCDInit();                         /* Initialize LCD Model    */
    LCD_Init1();
    #endif

    (void)OSInitTimer();                     /* initialize the Decremen */
    (void)OSStart();                         /* Start Operation Systems */
    return 0;
}

/* ******************************************************************** */
/*                                FWInit()                              */
/* ******************************************************************** */
void FWInit (void)
{   usFWTimer          = 0;
    usFWStatus         = 0;
    usFWSynchro        = 0;
    usFW100msTimer     = 0;
   #ifdef FW_TASK_PRIO_XIO
    usFWXioStackUsage  = 0;
   #endif
   #ifdef FW_TASK_PRIO_CAN1
    usFWCan1StackUsage = 0;
   #endif
   #ifdef FW_TASK_PRIO_CAN2
    usFWCan2StackUsage = 0;
   #endif
   #ifdef FW_TASK_PRIO_SCI1
    usFWSci1StackUsage = 0;
   #endif
   #ifdef FW_TASK_PRIO_SCI2
    usFWSci2StackUsage = 0;
   #endif
   #ifdef FW_TASK_PRIO_SCI3
    usFWSci3StackUsage = 0;
   #endif
   #ifdef FW_TASK_PRIO_DB
    usFWDbStackUsage = 0;
   #endif
   #ifdef FW_TASK_PRIO_FFT
    usFWFftStackUsage = 0;
   #endif
   #ifdef FW_TASK_PRIO_STAT
    usOSStatStackUsage = 0;
   #endif
   #ifdef FW_TASK_PRIO_IDLE
    usOSIdleStackUsage = 0;
   #endif
   #ifdef FW_TASK_PRIO_SDIO
    usFWSdioStackUsage = 0;
   #endif
   #ifdef FW_TASK_PRIO_LCD
    usFWLcdStackUsage = 0;
   #endif
}

/* ******************************************************************** */
/*                              FWInitRCC()                             */
/* ******************************************************************** */
#if (FW_CPU_STM32F1_ON == 1)
void FWInitRCC (void)
{
}
#endif

/* ******************************************************************** */
/*                            FWInitClkHSI()                            */
/* ******************************************************************** */
#if (FW_CPU_STM32F1_ON == 1)
void FWInitClkHSI (void)
{
}
#endif

/* ******************************************************************** */
/*                            FWInitClkHSE()                            */
/* ******************************************************************** */
#if (FW_CPU_STM32F1_ON == 1)
void FWInitClkHSE (void)
{
}
#endif

/* ******************************************************************** */
/*                             FWInitPMC()                              */
/* ******************************************************************** */
#if (FW_CPU_STM32F1_ON == 1)
void FWInitPMC (void)
{   
}
#endif

/* ******************************************************************** */
/*                             FWInitFLASH()                            */
/* ******************************************************************** */
#if (FW_CPU_STM32F1_ON == 1)
void FWInitFLASH (void)
{ /*  INT32U uiTemp;
    uiTemp     =  FLASH->ACR;
    uiTemp    &= ~FLASH_ACR_LATENCY;
    uiTemp    |=  FLASH_ACR_LATENCY_1
              |   FLASH_ACR_PRFTBE;
    FLASH->ACR =  uiTemp; */
}
#endif

/* ******************************************************************** */
/*                             IOIrqEnable()                            */
/* ******************************************************************** */
#if (FW_CPU_STM32F1_ON == 1)
void FWIrqEnable (INT08U ucChan, INT08U ucPrio)
{   NVIC->IP[ucChan] = ucPrio;
    NVIC->ISER[ucChan >> 5] = (INT32U)0x01 << (ucChan & (INT08U)0x1F);
}
#endif

/* ******************************************************************** */
/*                             IOIrqDisable()                           */
/* ******************************************************************** */
#if (FW_CPU_STM32F1_ON == 1)
void FWIrqDisable (INT08U ucChan)
{   NVIC->ICER[ucChan >> 5] = (INT32U)0x01 << (ucChan & (INT08U)0x1F);
}
#endif

/* ******************************************************************** */
/*                           FWWatchdogInit()                           */
/* ******************************************************************** */
#if (FW_CPU_STM32F1_ON == 1)
void FWWatchdogInit (void)
{   IWDG->KR    =  0x5555;   /* WriteAccess Enable                      */
    IWDG->PR    =  0x03;     /* clk = 40kHz / 32 = 1250Hz               */
    IWDG->RLR   =  312;      /* 312 * 1000 / 1250 = 249ms;              */
    IWDG->KR    =  0xAAAA;   /* The IWDG_RLR value is reloaded          */
    IWDG->KR    =  0xCCCC;   /* Watchdog started by writing 0xCCCC      */
}
#endif

/* ******************************************************************** */
/*                           FWWatchdogStop()                           */
/* ******************************************************************** */
#if (FW_CPU_STM32F1_ON == 1)
void FWWatchdogStop (void)
{
}
#endif

/* ******************************************************************** */
/*                           FWWatchdogFeed()                           */
/* ******************************************************************** */
#if (FW_CPU_STM32F1_ON == 1)
void FWWatchdogFeed (void)
{   IWDG->KR    =  0xAAAA;   /* The IWDG_RLR value is reloaded          */
}
#endif

/* ******************************************************************** */
/*                           FWTimerHook()                              */
/* ******************************************************************** */
void FWTimerHook (void)  // 5ms
{   static INT32U uiCounter = OS_TICKS_PER_SEC / 10;
    if ((--uiCounter) == 0)
    {   uiCounter = OS_TICKS_PER_SEC / 10;
        usFW100msTimer++;
    }
    usFWTimer++;
				
//    usSFTimer++;
    /*
    usSAETimer++;
    usMODTimer++;
    usCCPTimer++;
    usSCI2Timer++;
    usSCI3Timer++;
    usXIOTimer++;
    usCAN1Timer++;
    usCAN2Timer++;
    usSCI1Timer++;
    usSCI2Timer++;
    usSCI3Timer++;
    usDBTimer++;
    */
}

/* ******************************************************************** */
/*                          FWWaitTaskSynchro()                         */
/* ******************************************************************** */
void FWWaitTaskSynchro (INT16U mask, INT16U total)
{   usFWSynchro |= mask;
    while ((usFWSynchro & total) != total)
    {   OSTimeDly(2);
    }
}

/* ******************************************************************** */
/*                          XIO Task ( Prio = 4 )                       */
/* ******************************************************************** */
#ifdef FW_TASK_PRIO_XIO
void FWXioTask (void)
{
  (void)FWWaitTaskSynchro(FW_SYN_MASK_XIO,FW_SYN_MASK_ALL);
//    (void)XIOStart();
    while (1)
    {  TESTZCnum[1]++;
//			(void)XIOTaskLoop();
			OSTimeDly(2);
    }
}
#endif

/* ******************************************************************** */
/*                         CAN1 Task ( Prio = 6 )                       */
/* ******************************************************************** */
#ifdef FW_TASK_PRIO_CAN1
void FWCan1Task (void)
{   (void)FWWaitTaskSynchro(FW_SYN_MASK_CAN1,FW_SYN_MASK_ALL);
//    (void)CAN1Start();
    while (1)
    { TESTZCnum[2]++;
//			(void)CAN1TaskLoop();
			OSTimeDly(2);
    }
}
#endif

/* ******************************************************************** */
/*                         CAN2 Task ( Prio = 7 )                       */
/* ******************************************************************** */
#ifdef FW_TASK_PRIO_CAN2
void FWCan2Task (void)
{   (void)FWWaitTaskSynchro(FW_SYN_MASK_CAN2,FW_SYN_MASK_ALL);
//    (void)CAN2Start();
    while (1)
    { TESTZCnum[3]++;
//			(void)CAN2TaskLoop();
			OSTimeDly(2);
    }
}
#endif

/* ******************************************************************** */
/*                         SCI1 Task ( Prio = 8 )                       */
/* ******************************************************************** */
#ifdef FW_TASK_PRIO_SCI1
void FWSci1Task (void)
{ 
	(void)FWWaitTaskSynchro(FW_SYN_MASK_SCI1,FW_SYN_MASK_ALL);
//    (void)SCI1Start();
    while (1)
    { 
			(void)SCI1TaskLoop();
			
			OSTimeDly(2); //后期删除
    }
}
#endif

/* ******************************************************************** */
/*                         SCI2 Task ( Prio = 9 )                       */
/* ******************************************************************** */
#ifdef FW_TASK_PRIO_SCI2
void FWSci2Task (void)
{   (void)FWWaitTaskSynchro(FW_SYN_MASK_SCI2,FW_SYN_MASK_ALL);
//    (void)SCI2Start();
    while (1)
    { TESTZCnum[5]++;
//			(void)SCI2TaskLoop();
			OSTimeDly(2);
    }
}
#endif

/* ******************************************************************** */
/*                         SCI3 Task ( Prio = 10 )                      */
/* ******************************************************************** */
#ifdef FW_TASK_PRIO_SCI3
void FWSci3Task (void)
{   (void)FWWaitTaskSynchro(FW_SYN_MASK_SCI3,FW_SYN_MASK_ALL);
//    (void)SCI3Start();
    while (1)
    {  TESTZCnum[6]++;
//			(void)SCI3TaskLoop();
			OSTimeDly(2);
    }
}
#endif

/* ******************************************************************** */
/*                           DB Task ( Prio = 11 )                      */
/* ******************************************************************** */
#ifdef FW_TASK_PRIO_DB
void FWDbTask (void)
{   (void)FWWaitTaskSynchro(FW_SYN_MASK_DB,FW_SYN_MASK_ALL);
//    (void)DBStart();
    while (1)
    {  TESTZCnum[7]++;
			(void)DBTaskLoop();
			OSTimeDly(2);
    }
}
#endif

/* ******************************************************************** */
/*                          FFT Task ( Prio = 2 )                       */
/* ******************************************************************** */
#ifdef FW_TASK_PRIO_FFT
void FWFftTask (void)
{   (void)FWWaitTaskSynchro(FW_SYN_MASK_FFT,FW_SYN_MASK_ALL);
//    (void)FFTStart();
    while (1)
    { TESTZCnum[8]++;
//			(void)FFTTaskLoop();
			OSTimeDly(2);
    }
}
#endif

/* ******************************************************************** */
/*                          SDIO Task ( Prio = 2 )                      */
/* ******************************************************************** */
#ifdef FW_TASK_PRIO_SDIO
void FWSdioTask (void)
{   (void)FWWaitTaskSynchro(FW_SYN_MASK_SDIO,FW_SYN_MASK_ALL);
    (void)SDIOStart();
    while (1)
    {   (void)SDIOTaskLoop();
			OSTimeDly(2);
    }
}
#endif

/* ******************************************************************** */
/*                          LCD Task ( Prio = 2 )                       */
/* ******************************************************************** */
#ifdef FW_TASK_PRIO_LCD
void FWLcdTask (void)
{   (void)FWWaitTaskSynchro(FW_SYN_MASK_LCD,FW_SYN_MASK_ALL);
//    (void)LCDStart();
    while (1)
    { TESTZCnum[0]++;
//			(void)LCDTaskLoop();
			
			LCD_Line(10,10, 100, 150);
			LCD_Line(10,10, 100, 10);
			LCD_Line(10,10, 10, 150);
			
			OSTimeDly(2);
    }
}
#endif

/* ******************************************************************** */
/*                       Statistic Task ( Prio = 14 )                   */
/* ******************************************************************** */
#ifdef FW_TASK_PRIO_STAT
void OSTaskStat (void)
{   INT32U uiRun;
    (void)OSStatInit();
	TESTZCnum[10]++;
    #ifdef FW_TASK_PRIO_XIO
    (void)OSTaskCreate(FWXioTask,
                      &FWXioTaskStk[0],
                      &FWXioTaskStk[FW_TASK_STK_SIZE_XIO],
                       FW_TASK_PRIO_XIO);     //优先级2
    #endif
	TESTZCnum[11]++;
    #ifdef FW_TASK_PRIO_CAN1
    (void)OSTaskCreate(FWCan1Task,
                      &FWCan1TaskStk[0],
                      &FWCan1TaskStk[FW_TASK_STK_SIZE_CAN1],
                       FW_TASK_PRIO_CAN1);     //优先级4
    #endif
	TESTZCnum[12]++;	
    #ifdef FW_TASK_PRIO_CAN2
    (void)OSTaskCreate(FWCan2Task,
                      &FWCan2TaskStk[0],
                      &FWCan2TaskStk[FW_TASK_STK_SIZE_CAN2],
                       FW_TASK_PRIO_CAN2);     //优先级5
    #endif
	TESTZCnum[13]++;	
    #ifdef FW_TASK_PRIO_SCI1
    (void)OSTaskCreate(FWSci1Task,
                      &FWSci1TaskStk[0],
                      &FWSci1TaskStk[FW_TASK_STK_SIZE_SCI1],
                       FW_TASK_PRIO_SCI1);     //优先级7
    #endif
	TESTZCnum[14]++;	
    #ifdef FW_TASK_PRIO_SCI2
    (void)OSTaskCreate(FWSci2Task,
                      &FWSci2TaskStk[0],
                      &FWSci2TaskStk[FW_TASK_STK_SIZE_SCI2],
                       FW_TASK_PRIO_SCI2);     //优先级8
    #endif
	TESTZCnum[15]++;	
    #ifdef FW_TASK_PRIO_SCI3
    (void)OSTaskCreate(FWSci3Task,
                      &FWSci3TaskStk[0],
                      &FWSci3TaskStk[FW_TASK_STK_SIZE_SCI3],
                       FW_TASK_PRIO_SCI3);     //优先级9
    #endif
	TESTZCnum[16]++;	
    #ifdef FW_TASK_PRIO_DB
    (void)OSTaskCreate(FWDbTask,
                      &FWDbTaskStk[0],
                      &FWDbTaskStk[FW_TASK_STK_SIZE_DB],
                       FW_TASK_PRIO_DB);     //优先级11
    #endif
	TESTZCnum[17]++;	
    #ifdef FW_TASK_PRIO_FFT
    (void)OSTaskCreate(FWFftTask,
                      &FWFftTaskStk[0],
                      &FWFftTaskStk[FW_TASK_STK_SIZE_FFT],
                       FW_TASK_PRIO_FFT);     //优先级13
    #endif
	TESTZCnum[18]++;	
    #ifdef FW_TASK_PRIO_SDIO
    (void)OSTaskCreate(FWSdioTask,
                      &FWSdioTaskStk[0],
                      &FWSdioTaskStk[FW_TASK_STK_SIZE_SDIO],
                       FW_TASK_PRIO_SDIO);
    #endif
	TESTZCnum[19]++;	
    #ifdef FW_TASK_PRIO_LCD
    (void)OSTaskCreate(FWLcdTask,
                      &FWLcdTaskStk[0],
                      &FWLcdTaskStk[FW_TASK_STK_SIZE_LCD],
                       FW_TASK_PRIO_LCD);     //优先级12
    #endif
    (void)FWWaitTaskSynchro(0,FW_SYN_MASK_ALL);
    while (1)
    {   uiOSIdleCtr        = 0;
        OSTimeDly (OS_TICKS_PER_SEC);
        uiRun              = uiOSIdleCtr;
        if ((uiOSIdleCtrMax > uiRun) && (uiRun > 1024))
        {   uiRun          = uiOSIdleCtrMax - uiRun;
            usOSCPUUsage   = (INT16U)(uiRun / (uiOSIdleCtrMax / 1024));
        }   else
        {   usOSCPUUsage   = 0;
        }
        if (usOSCPUUsage  >= 700)
        {   usFWStatus |= FW_STS_USAGE_WARN;
        }
       #ifdef FW_TASK_PRIO_XIO
        usFWXioStackUsage  = OSCheckStack(FWXioTaskStk,  FW_TASK_STK_SIZE_XIO);
       #endif
       #ifdef FW_TASK_PRIO_CAN1
        usFWCan1StackUsage = OSCheckStack(FWCan1TaskStk, FW_TASK_STK_SIZE_CAN1);
       #endif
       #ifdef FW_TASK_PRIO_CAN2
        usFWCan2StackUsage = OSCheckStack(FWCan2TaskStk, FW_TASK_STK_SIZE_CAN2);
       #endif
       #ifdef FW_TASK_PRIO_SCI1
        usFWSci1StackUsage = OSCheckStack(FWSci1TaskStk, FW_TASK_STK_SIZE_SCI1);
       #endif
       #ifdef FW_TASK_PRIO_SCI2
        usFWSci2StackUsage = OSCheckStack(FWSci2TaskStk, FW_TASK_STK_SIZE_SCI2);
       #endif
       #ifdef FW_TASK_PRIO_SCI3
        usFWSci3StackUsage = OSCheckStack(FWSci3TaskStk, FW_TASK_STK_SIZE_SCI3);
       #endif
       #ifdef FW_TASK_PRIO_DB
        usFWDbStackUsage   = OSCheckStack(FWDbTaskStk,   FW_TASK_STK_SIZE_DB);
       #endif
       #ifdef FW_TASK_PRIO_FFT
        usFWFftStackUsage  = OSCheckStack(FWFftTaskStk,  FW_TASK_STK_SIZE_FFT);
       #endif
       #ifdef FW_TASK_PRIO_SDIO
        usFWSdioStackUsage = OSCheckStack(FWSdioTaskStk, FW_TASK_STK_SIZE_SDIO);
       #endif
       #ifdef FW_TASK_PRIO_LCD
        usFWLcdStackUsage  = OSCheckStack(FWLcdTaskStk,  FW_TASK_STK_SIZE_LCD);
       #endif        
        usOSStatStackUsage = OSCheckStack(OSStatTaskStk, FW_TASK_STK_SIZE_STAT);
        usOSIdleStackUsage = OSCheckStack(OSIdleTaskStk, FW_TASK_STK_SIZE_IDLE);
        if((usOSStatStackUsage >= 85) ||
          #ifdef FW_TASK_PRIO_XIO
           (usFWXioStackUsage  >= 85) ||
          #endif
          #ifdef FW_TASK_PRIO_CAN1
           (usFWCan1StackUsage >= 85) ||
          #endif
          #ifdef FW_TASK_PRIO_CAN2
           (usFWCan2StackUsage >= 85) ||
          #endif
          #ifdef FW_TASK_PRIO_SCI1
           (usFWSci1StackUsage >= 85) ||
          #endif
          #ifdef FW_TASK_PRIO_SCI2
           (usFWSci2StackUsage >= 85) ||
          #endif
          #ifdef FW_TASK_PRIO_SCI3
           (usFWSci3StackUsage >= 85) ||
          #endif
          #ifdef FW_TASK_PRIO_DB
           (usFWDbStackUsage   >= 85) ||
          #endif
          #ifdef FW_TASK_PRIO_FFT
           (usFWFftStackUsage  >= 85) ||
          #endif
          #ifdef FW_TASK_PRIO_SDIO
           (usFWSdioStackUsage >= 85) ||
          #endif
          #ifdef FW_TASK_PRIO_LCD
           (usFWLcdStackUsage  >= 85) ||
          #endif
           (usOSIdleStackUsage >= 85) )
        {   usFWStatus |= FW_STS_STACK_WARN;
        }
    }
}
#endif

/* ******************************************************************** */
/*                          STM32F105 Interrupts                        */
/* ******************************************************************** */
#if (FW_CPU_STM32F105_ON == 1)
void SVC_Handler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void SysTick_Handler (void)
{   (void)OSIntEnter();
    (void)FWTimerHook();
    (void)OSTimeTick();
    (void)OSIntExit();
}
void WWDG_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void PVD_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TAMPER_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void RTC_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void RTC_Alarm_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void FLASH_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void RCC_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void OTG_FS_WKUP_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void OTG_FS_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void ADC1_2_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
#endif

/* ******************************************************************** */
/*                         EXTI 0-15 Interrupts                         */
/* ******************************************************************** */
#if (FW_CPU_STM32F105_ON == 1)
void EXTI0_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void EXTI1_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void EXTI2_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void EXTI3_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void EXTI4_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void EXTI9_5_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void EXTI15_10_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
#endif

/* ******************************************************************** */
/*                    DMA1_C1-7, DMA2_C1-5 Interrupts                   */
/* ******************************************************************** */
#if (FW_CPU_STM32F105_ON == 1)
void DMA1_Channel1_IRQHandler (void)
{   (void)OSIntEnter();
//    (void)XIODma1Ch1IntHook();
    (void)OSIntExit();
}
void DMA1_Channel2_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA1_Channel3_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA1_Channel4_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA1_Channel5_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA1_Channel6_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA1_Channel7_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA2_Channel1_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA2_Channel2_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA2_Channel3_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA2_Channel4_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA2_Channel5_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
#endif

/* ******************************************************************** */
/*                         CAN1, CAN2 Interrupts                        */
/* ******************************************************************** */
#if (FW_CPU_STM32F105_ON == 1)
void CAN1_TX_IRQHandler (void)
{   (void)OSIntEnter();
//    (void)CAN1TxIntHook();
    (void)OSIntExit();
}
void CAN1_RX0_IRQHandler (void)
{   (void)OSIntEnter();
//    (void)CAN1Rx0IntHook();
    (void)OSIntExit();
}
void CAN1_RX1_IRQHandler (void)
{   (void)OSIntEnter();
//    (void)CAN1Rx1IntHook();
    (void)OSIntExit();
}
void CAN1_SCE_IRQHandler (void)
{   (void)OSIntEnter();
//    (void)CAN1SceIntHook();
    (void)OSIntExit();
}
void CAN2_TX_IRQHandler (void)
{   (void)OSIntEnter();
//    (void)CAN2TxIntHook();
    (void)OSIntExit();
}
void CAN2_RX0_IRQHandler (void)
{   (void)OSIntEnter();
//    (void)CAN2Rx0IntHook();
    (void)OSIntExit();
}
void CAN2_RX1_IRQHandler (void)
{   (void)OSIntEnter();
//    (void)CAN2Rx1IntHook();
    (void)OSIntExit();
}
void CAN2_SCE_IRQHandler (void)
{   (void)OSIntEnter();
//    (void)CAN2SceIntHook();
    (void)OSIntExit();
}
#endif

/* ******************************************************************** */
/*                           TIM1-7 Interrupts                          */
/* ******************************************************************** */
#if (FW_CPU_STM32F105_ON == 1)
void TIM1_BRK_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM1_UP_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM1_TRG_COM_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM1_CC_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
/* ************************ TIM2_IRQHandler() ************************* */
void TIM2_IRQHandler (void)
{  
	Tim2IntHook();
}
/* ************************ TIM3_IRQHandler() ************************* */
void TIM3_IRQHandler (void)
{   (void)OSIntEnter();
//    (void)XIOTim3IntHook();
    (void)OSIntExit();
}
/* ************************ TIM4_IRQHandler() ************************* */
void TIM4_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM5_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM6_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM7_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
#endif

/* ******************************************************************** */
/*                           I2C1-2 Interrupts                          */
/* ******************************************************************** */
#if (FW_CPU_STM32F105_ON == 1)
void I2C1_EV_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void I2C1_ER_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void I2C2_EV_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void I2C2_ER_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
#endif

/* ******************************************************************** */
/*                           SPI1-3 Interrupts                          */
/* ******************************************************************** */
#if (FW_CPU_STM32F105_ON == 1)
void SPI1_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void SPI2_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void SPI3_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
#endif

/* ******************************************************************** */
/*                           USART1-5 Interrupts                        */
/* ******************************************************************** */
#if (FW_CPU_STM32F105_ON == 1)
void USART1_IRQHandler (void)
{
    (void)OSIntEnter();
    (void)SCI1RxIntHook();
    (void)OSIntExit();
}
void USART2_IRQHandler (void)
{   (void)OSIntEnter();
//    (void)SCI2TxRxIntHook();
    (void)OSIntExit();
}
void USART3_IRQHandler (void)
{   (void)OSIntEnter();
    FW_STS_SET_BIT(FW_STS_INTERRUPT);
    (void)OSIntExit();
}
void UART4_IRQHandler (void)
{   (void)OSIntEnter();
    FW_STS_SET_BIT(FW_STS_INTERRUPT);
    (void)OSIntExit();
}
void UART5_IRQHandler (void)
{   (void)OSIntEnter();
//    (void)SCI3TxRxIntHook();
    (void)OSIntExit();
}
#endif

/* ******************************************************************** */
/*                          STM32F103 Interrupts                        */
/* ******************************************************************** */
#if (FW_CPU_STM32F103_ON == 1)
void SVC_Handler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void SysTick_Handler (void)
{   (void)OSIntEnter();
    (void)FWTimerHook();
    (void)OSTimeTick();
    (void)OSIntExit();
}
void WWDG_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void PVD_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TAMPER_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void RTC_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void RTC_Alarm_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void FLASH_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void RCC_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void ADC1_2_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void ADC3_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void FSMC_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void SDIO_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}

#endif
/* ******************************************************************** */
/*                         EXTI 0-15 Interrupts                         */
/* ******************************************************************** */
#if (FW_CPU_STM32F103_ON == 1)
void EXTI0_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void EXTI1_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void EXTI2_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void EXTI3_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void EXTI4_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void EXTI9_5_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void EXTI15_10_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}

#endif
/* ******************************************************************** */
/*                    DMA1_C1-7, DMA2_C1-5 Interrupts                   */
/* ******************************************************************** */
#if (FW_CPU_STM32F103_ON == 1)
void DMA1_Channel1_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA1_Channel2_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA1_Channel3_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA1_Channel4_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA1_Channel5_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA1_Channel6_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA1_Channel7_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA2_Channel1_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA2_Channel2_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA2_Channel3_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void DMA2_Channel4_5_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}

#endif
/* ******************************************************************** */
/*                         CAN1, USB Interrupts                         */
/* ******************************************************************** */
#if (FW_CPU_STM32F103_ON == 1)
void USB_HP_CAN1_TX_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void USB_LP_CAN1_RX0_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void CAN1_RX1_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void CAN1_SCE_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void USBWakeUp_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}

#endif
/* ******************************************************************** */
/*                           TIM1-14 Interrupts                         */
/* ******************************************************************** */
#if (FW_CPU_STM32F103_ON == 1)
void TIM1_BRK_TIM9_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM1_UP_TIM10_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM1_TRG_COM_TIM11_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM1_CC_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM2_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM3_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM4_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM5_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM6_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM7_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM8_BRK_TIM12_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM8_UP_TIM13_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM8_TRG_COM_TIM14_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void TIM8_CC_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}

#endif
/* ******************************************************************** */
/*                           I2C1-2 Interrupts                          */
/* ******************************************************************** */
#if (FW_CPU_STM32F103_ON == 1)
void I2C1_EV_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void I2C1_ER_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void I2C2_EV_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void I2C2_ER_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}

#endif
/* ******************************************************************** */
/*                           SPI1-3 Interrupts                          */
/* ******************************************************************** */
#if (FW_CPU_STM32F103_ON == 1)
void SPI1_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void SPI2_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void SPI3_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}

#endif
/* ******************************************************************** */
/*                           USART1-5 Interrupts                        */
/* ******************************************************************** */
#if (FW_CPU_STM32F103_ON == 1)
void USART1_IRQHandler (void)
{   (void)OSIntEnter();
//    (void)SCI1TxRxIntHook();
    (void)OSIntExit();
}
void USART2_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void USART3_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void UART4_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void UART5_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}

#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
