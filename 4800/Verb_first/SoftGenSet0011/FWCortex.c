/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File FWCortex.c                         */
/*                            By: Wu Xuekui                             */
/*                             2017-04-18                               */
/* ******************************************************************** */

#define   FW_GLOBALS
#include "TYPCortex.h"

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
    (void)DBInit();                          /* Initialize Database     */
    (void)SFInit();                          /* Initialize Standard Fun */
    (void)CAN1Init();                        /* Initialize CAN1 Model   */
    (void)CAN2Init();                        /* Initialize CAN2 Model   */
    (void)SCI1Init();                        /* Initialize SCI1 Model   */
    (void)SCI2Init();                        /* Initialize SCI2 Model   */
    (void)SCI3Init();                        /* Initialize SCI3 Model   */
    (void)FFTInit();                         /* Initialize FFT Model    */
    (void)XIOInit();                         /* Initialize XIO Model    */
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
    usFWFftStackUsage  = 0;
    usFWXioStackUsage  = 0;
    usFWCan1StackUsage = 0;
    usFWCan2StackUsage = 0;
    usFWSci1StackUsage = 0;
    usFWSci2StackUsage = 0;
    usFWSci3StackUsage = 0;
    usFWDbStackUsage   = 0;
    usOSStatStackUsage = 0;
    usOSIdleStackUsage = 0;
}

/* ******************************************************************** */
/*                              FWInitRCC()                             */
/* ******************************************************************** */
#if (FW_CPU_STM32F1_ON == 1)
void FWInitRCC (void)
{ //  RCC->CR    |=  RCC_CR_HSION;      /* Internal High Speed clock En   */
}
#endif

/* ******************************************************************** */
/*                            FWInitClkHSI()                            */
/* ******************************************************************** */
#if (FW_CPU_STM32F1_ON == 1)
void FWInitClkHSI (void)
{ //  RCC->CR    |=  RCC_CR_HSION;             /* Internal High clock En  */
}
#endif

/* ******************************************************************** */
/*                            FWInitClkHSE()                            */
/* ******************************************************************** */
#if (FW_CPU_STM32F1_ON == 1)
void FWInitClkHSE (void)
{ //  RCC->CR    |=  RCC_CR_HSEON;             /* 1: HSE oscillator ON    */
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
void FWTimerHook (void)
{   static INT32U uiCounter = OS_TICKS_PER_SEC / 10;    //os时钟节拍数200，uiCounter临界值为20
    if ((--uiCounter) == 0)
    {   uiCounter = OS_TICKS_PER_SEC / 10;
        usFW100msTimer++;
    }
    usFWTimer++;
    usDBTimer++;
    usSFTimer++;
    usXIOTimer++;
    usSAETimer++;
    usCCPTimer++;
    usCAN1Timer++;
    usCAN2Timer++;
    usSCI1Timer++;
    usSCI2Timer++;
    usSCI3Timer++;
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

void FWXioTask (void)
{   (void)FWWaitTaskSynchro(FW_SYN_MASK_XIO,FW_SYN_MASK_ALL);
    (void)XIOStart();
    while (1)
    {
      (void)XIOTaskLoop();
    
    }
}

/* ******************************************************************** */
/*                         CAN1 Task ( Prio = 6 )                       */
/* ******************************************************************** */
void FWCan1Task (void)
{   (void)FWWaitTaskSynchro(FW_SYN_MASK_CAN1,FW_SYN_MASK_ALL);
    (void)CAN1Start();
    while (1)
    {
      (void)CAN1TaskLoop();
    }
}

/* ******************************************************************** */
/*                         CAN2 Task ( Prio = 7 )                       */
/* ******************************************************************** */
void FWCan2Task (void)
{   (void)FWWaitTaskSynchro(FW_SYN_MASK_CAN2,FW_SYN_MASK_ALL);
    (void)CAN2Start();
    while (1)
    {   (void)CAN2TaskLoop();
    }
}

/* ******************************************************************** */
/*                         SCI1 Task ( Prio = 8 )                       */
/* ******************************************************************** */
void FWSci1Task (void)
{   (void)FWWaitTaskSynchro(FW_SYN_MASK_SCI1,FW_SYN_MASK_ALL);
    (void)SCI1Start();
    while (1)
    {   (void)SCI1TaskLoop();
    }
}

/* ******************************************************************** */
/*                         SCI2 Task ( Prio = 9 )                       */
/* ******************************************************************** */
void FWSci2Task (void)
{   (void)FWWaitTaskSynchro(FW_SYN_MASK_SCI2,FW_SYN_MASK_ALL);
    (void)SCI2Start();
    while (1)
    {   (void)SCI2TaskLoop();
    }
}

/* ******************************************************************** */
/*                         SCI3 Task ( Prio = 10 )                      */
/* ******************************************************************** */
void FWSci3Task (void)
{   (void)FWWaitTaskSynchro(FW_SYN_MASK_SCI3,FW_SYN_MASK_ALL);
    (void)SCI3Start();
    while (1)
    {   (void)SCI3TaskLoop();
    }
}

/* ******************************************************************** */
/*                           DB Task ( Prio = 11 )                      */
/* ******************************************************************** */
void FWDbTask (void)
{   (void)FWWaitTaskSynchro(FW_SYN_MASK_DB,FW_SYN_MASK_ALL);
    (void)DBStart();
    while (1)
    {
      (void)DBTaskLoop();
    }
}

/* ******************************************************************** */
/*                          FFT Task ( Prio = 2 )                       */
/* ******************************************************************** */
void FWFftTask (void)
{   (void)FWWaitTaskSynchro(FW_SYN_MASK_FFT,FW_SYN_MASK_ALL);
    (void)FFTStart();
    while (1)
    {   (void)FFTTaskLoop();
    }
}

/* ******************************************************************** */
/*                       Statistic Task ( Prio = 14 )                   */
/* ******************************************************************** */
void OSTaskStat (void)
{   INT32U uiRun;
    (void)OSStatInit();
    (void)OSTaskCreate(FWXioTask,
                      &FWXioTaskStk[0],
                      &FWXioTaskStk[FW_TASK_STK_SIZE_XIO],
                       FW_TASK_PRIO_XIO);
    (void)OSTaskCreate(FWCan1Task,
                      &FWCan1TaskStk[0],
                      &FWCan1TaskStk[FW_TASK_STK_SIZE_CAN1],
                       FW_TASK_PRIO_CAN1);
    (void)OSTaskCreate(FWCan2Task,
                      &FWCan2TaskStk[0],
                      &FWCan2TaskStk[FW_TASK_STK_SIZE_CAN2],
                       FW_TASK_PRIO_CAN2);
    (void)OSTaskCreate(FWSci1Task,
                      &FWSci1TaskStk[0],
                      &FWSci1TaskStk[FW_TASK_STK_SIZE_SCI1],
                       FW_TASK_PRIO_SCI1);
    (void)OSTaskCreate(FWSci2Task,
                      &FWSci2TaskStk[0],
                      &FWSci2TaskStk[FW_TASK_STK_SIZE_SCI2],
                       FW_TASK_PRIO_SCI2);
    (void)OSTaskCreate(FWSci3Task,
                      &FWSci3TaskStk[0],
                      &FWSci3TaskStk[FW_TASK_STK_SIZE_SCI3],
                       FW_TASK_PRIO_SCI3);
    (void)OSTaskCreate(FWDbTask,
                      &FWDbTaskStk[0],
                      &FWDbTaskStk[FW_TASK_STK_SIZE_DB],
                       FW_TASK_PRIO_DB);
    (void)OSTaskCreate(FWFftTask,
                      &FWFftTaskStk[0],
                      &FWFftTaskStk[FW_TASK_STK_SIZE_FFT],
                       FW_TASK_PRIO_FFT);
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
        usFWXioStackUsage  = OSCheckStack(FWXioTaskStk,  FW_TASK_STK_SIZE_XIO);
        usFWCan1StackUsage = OSCheckStack(FWCan1TaskStk, FW_TASK_STK_SIZE_CAN1);
        usFWCan2StackUsage = OSCheckStack(FWCan2TaskStk, FW_TASK_STK_SIZE_CAN2);
        usFWSci1StackUsage = OSCheckStack(FWSci1TaskStk, FW_TASK_STK_SIZE_SCI1);
        usFWSci2StackUsage = OSCheckStack(FWSci2TaskStk, FW_TASK_STK_SIZE_SCI2);
        usFWSci3StackUsage = OSCheckStack(FWSci3TaskStk, FW_TASK_STK_SIZE_SCI3);
        usFWDbStackUsage   = OSCheckStack(FWDbTaskStk,   FW_TASK_STK_SIZE_DB);
        usFWFftStackUsage  = OSCheckStack(FWFftTaskStk,  FW_TASK_STK_SIZE_FFT);
        usOSStatStackUsage = OSCheckStack(OSStatTaskStk, FW_TASK_STK_SIZE_STAT);
        usOSIdleStackUsage = OSCheckStack(OSIdleTaskStk, FW_TASK_STK_SIZE_IDLE);
        if((usFWXioStackUsage  >= 85) ||
           (usFWCan1StackUsage >= 85) ||
           (usFWCan2StackUsage >= 85) ||
           (usFWSci1StackUsage >= 85) ||
           (usFWSci2StackUsage >= 85) ||
           (usFWSci3StackUsage >= 85) ||
           (usFWDbStackUsage   >= 85) ||
           (usFWFftStackUsage  >= 85) ||
           (usOSStatStackUsage >= 85) ||
           (usOSIdleStackUsage >= 85) )
        {   usFWStatus |= FW_STS_STACK_WARN;
        }
    }
}

/* ******************************************************************** */
/*                          STM32F0 Interrupts                          */
/* ******************************************************************** */
#if (FW_CPU_STM32F1_ON == 1)

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

/* ******************************************************************** */
/*                         EXTI 0-15 Interrupts                         */
/* ******************************************************************** */
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

/* ******************************************************************** */
/*                    DMA1_C1-7, DMA2_C1-5 Interrupts                   */
/* ******************************************************************** */
void DMA1_Channel1_IRQHandler (void)
{   (void)OSIntEnter();
    (void)XIODma1Ch1IntHook();
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

/* ******************************************************************** */
/*                         CAN1, CAN2 Interrupts                        */
/* ******************************************************************** */
void CAN1_TX_IRQHandler (void)
{   (void)OSIntEnter();
    (void)CAN1TxIntHook();
    (void)OSIntExit();
}
void CAN1_RX0_IRQHandler (void)
{   (void)OSIntEnter();
    (void)CAN1Rx0IntHook();
    (void)OSIntExit();
}
void CAN1_RX1_IRQHandler (void)
{   (void)OSIntEnter();
    (void)CAN1Rx1IntHook();
    (void)OSIntExit();
}
void CAN1_SCE_IRQHandler (void)
{   (void)OSIntEnter();
    (void)CAN1SceIntHook();
    (void)OSIntExit();
}
void CAN2_TX_IRQHandler (void)
{   (void)OSIntEnter();
    (void)CAN2TxIntHook();
    (void)OSIntExit();
}
void CAN2_RX0_IRQHandler (void)
{   (void)OSIntEnter();
    (void)CAN2Rx0IntHook();
    (void)OSIntExit();
}
void CAN2_RX1_IRQHandler (void)
{   (void)OSIntEnter();
    (void)CAN2Rx1IntHook();
    (void)OSIntExit();
}
void CAN2_SCE_IRQHandler (void)
{   (void)OSIntEnter();
    (void)CAN2SceIntHook();
    (void)OSIntExit();
}

/* ******************************************************************** */
/*                           TIM1-7 Interrupts                          */
/* ******************************************************************** */
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
{   INT16U usTimSr;
    (void)OSIntEnter();
    usTimSr = TIM2->SR;
    if ((usTimSr & TIM_SR_CC4IF) != 0)
    {   TIM2->SR &= ~TIM_SR_CC4IF;
        TIM2->DIER &= ~TIM_DIER_CC4IE;
        MODOverTimerHook();
    }
    else if ((usTimSr & TIM_SR_CC1IF) != 0)
    {   TIM2->SR &= ~TIM_SR_CC1IF;
        SFHardPrdPutTime(TIM2->CCR1, &sXIOHardPeriod0);
    }
    else if ((usTimSr & TIM_SR_CC2IF) != 0)
    {   TIM2->SR &= ~TIM_SR_CC2IF;
        SFHardPrdPutTime(TIM2->CCR2, &sXIOHardPeriod1);
    }
    (void)OSIntExit();
}
/* ************************ TIM3_IRQHandler() ************************* */
void TIM3_IRQHandler (void)
{   INT16U usTimSr;
    (void)OSIntEnter();
    usTimSr = TIM3->SR;
    if ((usTimSr & TIM_SR_CC1IF) != 0)
    {   TIM3->SR &= ~TIM_SR_CC1IF;
        SFSpdPulsePutTime(TIM3->CCR1, &sXIOSpdPulse0);
    }
    else if ((usTimSr & TIM_SR_CC2IF) != 0)
    {   TIM3->SR &= ~TIM_SR_CC2IF;
        SFSpdPulsePutTime(TIM3->CCR2, &sXIOSpdPulse1);
    }
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

/* ******************************************************************** */
/*                           I2C1-2 Interrupts                          */
/* ******************************************************************** */
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

/* ******************************************************************** */
/*                           SPI1-3 Interrupts                          */
/* ******************************************************************** */
void SPI1_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void SPI2_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}
void SPI3_IRQHandler (void)
{   FW_STS_SET_BIT(FW_STS_INTERRUPT);
}

/* ******************************************************************** */
/*                           USART1-5 Interrupts                        */
/* ******************************************************************** */
void USART1_IRQHandler (void)
{   (void)OSIntEnter();
    (void)SCI1TxRxIntHook();
    (void)OSIntExit();
}
void USART2_IRQHandler (void)
{   (void)OSIntEnter();
    (void)SCI2TxRxIntHook();
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
    (void)SCI3TxRxIntHook();
    (void)OSIntExit();
}

#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */