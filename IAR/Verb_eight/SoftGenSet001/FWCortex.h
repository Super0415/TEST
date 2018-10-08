/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File FWCortex.h                         */
/*                            By: Wu Xuekui                             */
/*                              2017-04-18                              */
/* ******************************************************************** */

#ifndef _FWCORTEX_H

#define _FWCORTEX_H

#ifdef   FW_GLOBALS

#define  FW_EXT  

#else

#define  FW_EXT extern

#endif

/* ******************************************************************** */
/*  FW_VERSION  = 10xx: VEC1000 Application                             */
/*  FW_VERSION  = 40xx: VEC4000 Application                             */
/*  FW_VERSION  = 68xx: VEC6800 Application                             */
/*  FW_VERSION  = 69xx: VEC6900 Application                             */
/*  FW_VERSION  = 760x: GEC7600-Main Application                        */
/*  FW_VERSION  = 761x: GEC7600-Display Application                     */
/*  FW_VERSION  = 780x: GEC7800-Main Application                        */
/*  FW_VERSION  = 781x: GEC7800-Display Application                     */
/*  FW_VERSION  = 80xx: VEC8000 Application                             */
/*  FW_VERSION  = 90xx: VEC9000 Application                             */
/*  FW_VERSION  = 96xx: VEC9600 Application                             */
/* ******************************************************************** */

#define FW_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define FW_1000_COMMON_ON       0
#define FW_4000_COMMON_ON       0
#define FW_6800_COMMON_ON       0
#define FW_6900_COMMON_ON       0
#define FW_7600_COMMON_ON       0
#define FW_7600_MAIN_CHIP_ON    0
#define FW_7600_AUX_CHIP_ON     0
#define FW_7800_COMMON_ON       0
#define FW_7800_MAIN_CHIP_ON    0
#define FW_7800_AUX_CHIP_ON     0
#define FW_8000_COMMON_ON       0
#define FW_9000_COMMON_ON       0
#define FW_9600_COMMON_ON       0
#if   ((FW_VERSION / 100)   == 10)
#undef  FW_1000_COMMON_ON
#define FW_1000_COMMON_ON       1
#endif
#if   ((FW_VERSION / 100)   == 40)
#undef  FW_4000_COMMON_ON
#define FW_4000_COMMON_ON       1
#endif
#if   ((FW_VERSION / 100)   == 68)
#undef  FW_6800_COMMON_ON
#define FW_6800_COMMON_ON       1
#endif
#if   ((FW_VERSION / 100)   == 69)
#undef  FW_6900_COMMON_ON
#define FW_6900_COMMON_ON       1
#endif
#if   ((FW_VERSION / 100)   == 76)
#undef  FW_7600_COMMON_ON
#define FW_7600_COMMON_ON       1
#endif
#if   ((FW_VERSION / 10)   == 760)
#undef  FW_7600_MAIN_CHIP_ON
#define FW_7600_MAIN_CHIP_ON    1
#endif
#if   ((FW_VERSION / 10)   == 761)
#undef  FW_7600_AUX_CHIP_ON
#define FW_7600_AUX_CHIP_ON     1
#endif
#if   ((FW_VERSION / 100)   == 78)
#undef  FW_7800_COMMON_ON
#define FW_7800_COMMON_ON       1
#endif
#if   ((FW_VERSION / 10)   == 780)
#undef  FW_7800_MAIN_CHIP_ON
#define FW_7800_MAIN_CHIP_ON    1
#endif
#if   ((FW_VERSION / 10)   == 781)
#undef  FW_7800_AUX_CHIP_ON
#define FW_7800_AUX_CHIP_ON     1
#endif
#if   ((FW_VERSION / 100)   == 80)
#undef  FW_8000_COMMON_ON
#define FW_8000_COMMON_ON       1
#endif
#if   ((FW_VERSION / 100)   == 90)
#undef  FW_9000_COMMON_ON
#define FW_9000_COMMON_ON       1
#endif
#if   ((FW_VERSION / 100)   == 96)
#undef  FW_9600_COMMON_ON
#define FW_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define FW_CPU_9S12_ON          0
#define FW_CPU_POWERPC_ON       0
#define FW_CPU_STM32F1_ON       0
#define FW_CPU_STM32F103_ON     0
#define FW_CPU_STM32F105_ON     0
#if    (FW_1000_COMMON_ON    == 1)
#undef  FW_CPU_9S12_ON
#define FW_CPU_9S12_ON          1
#endif
#if    (FW_4000_COMMON_ON    == 1)
#undef  FW_CPU_9S12_ON
#define FW_CPU_9S12_ON          1
#endif
#if    (FW_6800_COMMON_ON    == 1)
#undef  FW_CPU_9S12_ON
#define FW_CPU_9S12_ON          1
#endif
#if    (FW_6900_COMMON_ON    == 1)
#undef  FW_CPU_POWERPC_ON
#define FW_CPU_POWERPC_ON       1
#endif
#if    (FW_7600_COMMON_ON    == 1)
#undef  FW_CPU_STM32F1_ON
#define FW_CPU_STM32F1_ON       1
#endif
#if    (FW_7600_MAIN_CHIP_ON == 1)
#undef  FW_CPU_STM32F105_ON
#define FW_CPU_STM32F105_ON     1
#endif
#if    (FW_7600_AUX_CHIP_ON  == 1)
#undef  FW_CPU_STM32F103_ON
#define FW_CPU_STM32F103_ON     1
#endif
#if    (FW_7800_COMMON_ON    == 1)
#undef  FW_CPU_STM32F1_ON
#define FW_CPU_STM32F1_ON       1
#endif
#if    (FW_7800_MAIN_CHIP_ON == 1)
#undef  FW_CPU_STM32F105_ON
#define FW_CPU_STM32F105_ON     1
#endif
#if    (FW_7800_AUX_CHIP_ON  == 1)
#undef  FW_CPU_STM32F103_ON
#define FW_CPU_STM32F103_ON     1
#endif
#if    (FW_8000_COMMON_ON    == 1)
#undef  FW_CPU_POWERPC_ON
#define FW_CPU_POWERPC_ON       1
#endif
#if    (FW_9000_COMMON_ON    == 1)
#undef  FW_CPU_POWERPC_ON
#define FW_CPU_POWERPC_ON       1
#endif
#if    (FW_9600_COMMON_ON    == 1)
#undef  FW_CPU_POWERPC_ON
#define FW_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                       GEC7600 Basis Definition                       */
/* ******************************************************************** */
#if    (FW_CPU_STM32F1_ON == 1)
#define FW_FRQ_CRY             (INT32U)8000000
#define FW_FRQ_SYS             (INT32U)72000000
#define FW_FRQ_BUS             (INT32U)72000000
#define FW_GET_FREE_TIMER()    (TIM2->CNT)
#define FW_IRQ_PRIO_HIGH       (INT08U)0x00
#define FW_IRQ_PRIO_MID        (INT08U)0xA0
#define FW_IRQ_PRIO_LOW        (INT08U)0xF0
#endif

/* ******************************************************************** */
/*                           Basis Definition                           */
/* ******************************************************************** */
#define FW_TRUE                 1
#define FW_FALSE                0
#define FW_STS_NORMAL          (INT32U)0x00000000
#define FW_STS_INTERRUPT       (INT32U)0x00000001
#define FW_STS_USAGE_WARN      (INT32U)0x00000002
#define FW_STS_STACK_WARN      (INT32U)0x00000004
#define FW_STS_RST_WATCHDOG    (INT32U)0x00000008
#define FW_STS_RST_CLOCK       (INT32U)0x00000010
#define FW_STS_RST_ILLEGAL     (INT32U)0x00000020
#define FW_STS_GET_BIT(m)      (uiFWStatus & (m))
#define FW_STS_CLR_BIT(m)       uiFWStatus &= ~(m)
#define FW_STS_SET_BIT(m)       uiFWStatus |= (m)

/* ******************************************************************** */
/*                           Different Versions                         */
/* ******************************************************************** */
#if    (FW_7800_MAIN_CHIP_ON == 1)
#define FW_SYN_MASK_XIO        (INT32U)0x00000001
#define FW_SYN_MASK_CAN1       (INT32U)0x00000002
#define FW_SYN_MASK_CAN2       (INT32U)0x00000004
#define FW_SYN_MASK_SCI1       (INT32U)0x00000008
#define FW_SYN_MASK_SCI2       (INT32U)0x00000010
#define FW_SYN_MASK_SCI3       (INT32U)0x00000020
#define FW_SYN_MASK_SCI4       (INT32U)0x00000040
#define FW_SYN_MASK_DB         (INT32U)0x00000100
#define FW_SYN_MASK_FFT        (INT32U)0x00000200
#define FW_SYN_MASK_ALL        (INT32U)0x0000037F
#define FW_TASK_STK_SIZE_XIO    128
#define FW_TASK_STK_SIZE_CAN1   128
#define FW_TASK_STK_SIZE_CAN2   128
#define FW_TASK_STK_SIZE_SCI1   128
#define FW_TASK_STK_SIZE_SCI2   128
#define FW_TASK_STK_SIZE_SCI3   128
#define FW_TASK_STK_SIZE_SCI4   128
#define FW_TASK_STK_SIZE_DB     128
#define FW_TASK_STK_SIZE_FFT    256
#define FW_TASK_STK_SIZE_STAT   128
#define FW_TASK_STK_SIZE_IDLE   128
#define FW_TASK_PRIO_XIO        1
#define FW_TASK_PRIO_CAN1       3
#define FW_TASK_PRIO_CAN2       4
#define FW_TASK_PRIO_SCI1       9
#define FW_TASK_PRIO_SCI2       6
#define FW_TASK_PRIO_SCI3       7
#define FW_TASK_PRIO_SCI4       8
#define FW_TASK_PRIO_DB         11
#define FW_TASK_PRIO_FFT        12
#define FW_TASK_PRIO_STAT       OS_STAT_PRIO
#define FW_TASK_PRIO_IDLE       OS_IDLE_PRIO
#endif

#if    (FW_7800_AUX_CHIP_ON  == 1)
#define FW_SYN_MASK_XIO        (INT32U)0x00000001
#define FW_SYN_MASK_SCI1       (INT32U)0x00000002
#define FW_SYN_MASK_SCI2       (INT32U)0x00000004
#define FW_SYN_MASK_DB         (INT32U)0x00000008
#define FW_SYN_MASK_SDIO       (INT32U)0x00000010
#define FW_SYN_MASK_LCD        (INT32U)0x00000020
#define FW_SYN_MASK_ALL        (INT32U)0x0000003F
#define FW_TASK_STK_SIZE_XIO    128
#define FW_TASK_STK_SIZE_SCI1   128
#define FW_TASK_STK_SIZE_SCI2   128
#define FW_TASK_STK_SIZE_DB     128
#define FW_TASK_STK_SIZE_SDIO   128
#define FW_TASK_STK_SIZE_LCD    128
#define FW_TASK_STK_SIZE_STAT   128
#define FW_TASK_STK_SIZE_IDLE   128
#define FW_TASK_PRIO_XIO        2
#define FW_TASK_PRIO_SCI1       4
#define FW_TASK_PRIO_SCI2       6
#define FW_TASK_PRIO_DB         8
#define FW_TASK_PRIO_SDIO       10
#define FW_TASK_PRIO_LCD        12
#define FW_TASK_PRIO_STAT       OS_STAT_PRIO
#define FW_TASK_PRIO_IDLE       OS_IDLE_PRIO
#endif

/* ******************************************************************** */
/*                          Variable Definitions                        */
/* ******************************************************************** */
FW_EXT INT32U  uiFWStatus;
FW_EXT INT32U  uiFWSynchro;
FW_EXT INT16U  usFW5msTimer;
FW_EXT INT16U  usFW100msTimer;

#ifdef FW_TASK_PRIO_XIO
FW_EXT INT16U  usFWXioStackUsage;
FW_EXT OS_STK  FWXioTaskStk[FW_TASK_STK_SIZE_XIO];
FW_EXT void    FWXioTask(void);
#endif

#ifdef FW_TASK_PRIO_CAN1
FW_EXT INT16U  usFWCan1StackUsage;
FW_EXT OS_STK  FWCan1TaskStk[FW_TASK_STK_SIZE_CAN1];
FW_EXT void    FWCan1Task(void);
#endif

#ifdef FW_TASK_PRIO_CAN2
FW_EXT INT16U  usFWCan2StackUsage;
FW_EXT OS_STK  FWCan2TaskStk[FW_TASK_STK_SIZE_CAN2];
FW_EXT void    FWCan2Task(void);
#endif

#ifdef FW_TASK_PRIO_SCI1
FW_EXT INT16U  usFWSci1StackUsage;
FW_EXT OS_STK  FWSci1TaskStk[FW_TASK_STK_SIZE_SCI1];
FW_EXT void    FWSci1Task(void);
#endif

#ifdef FW_TASK_PRIO_SCI2
FW_EXT INT16U  usFWSci2StackUsage;
FW_EXT OS_STK  FWSci2TaskStk[FW_TASK_STK_SIZE_SCI2];
FW_EXT void    FWSci2Task(void);
#endif

#ifdef FW_TASK_PRIO_SCI3
FW_EXT INT16U  usFWSci3StackUsage;
FW_EXT OS_STK  FWSci3TaskStk[FW_TASK_STK_SIZE_SCI3];
FW_EXT void    FWSci3Task(void);
#endif

#ifdef FW_TASK_PRIO_SCI4
FW_EXT INT16U  usFWSci4StackUsage;
FW_EXT OS_STK  FWSci4TaskStk[FW_TASK_STK_SIZE_SCI4];
FW_EXT void    FWSci4Task(void);
#endif

#ifdef FW_TASK_PRIO_SCI5
FW_EXT INT16U  usFWSci5StackUsage;
FW_EXT OS_STK  FWSci5TaskStk[FW_TASK_STK_SIZE_SCI5];
FW_EXT void    FWSci5Task(void);
#endif

#ifdef FW_TASK_PRIO_SPI1
FW_EXT INT16U  usFWSpi1StackUsage;
FW_EXT OS_STK  FWSpi1TaskStk[FW_TASK_STK_SIZE_SPI1];
FW_EXT void    FWSpi1Task(void);
#endif

#ifdef FW_TASK_PRIO_SPI2
FW_EXT INT16U  usFWSpi2StackUsage;
FW_EXT OS_STK  FWSpi2TaskStk[FW_TASK_STK_SIZE_SPI2];
FW_EXT void    FWSpi2Task(void);
#endif

#ifdef FW_TASK_PRIO_SPI3
FW_EXT INT16U  usFWSpi3StackUsage;
FW_EXT OS_STK  FWSpi3TaskStk[FW_TASK_STK_SIZE_SPI3];
FW_EXT void    FWSpi3Task(void);
#endif

#ifdef FW_TASK_PRIO_DB
FW_EXT INT16U  usFWDbStackUsage;
FW_EXT OS_STK  FWDbTaskStk[FW_TASK_STK_SIZE_DB];
FW_EXT void    FWDbTask(void);
#endif

#ifdef FW_TASK_PRIO_FFT
FW_EXT INT16U  usFWFftStackUsage;
FW_EXT OS_STK  FWFftTaskStk[FW_TASK_STK_SIZE_FFT];
FW_EXT void    FWFftTask(void);
#endif

#ifdef FW_TASK_PRIO_STAT
FW_EXT INT16U  usOSStatStackUsage;
FW_EXT OS_STK  OSStatTaskStk[FW_TASK_STK_SIZE_STAT];
FW_EXT void    OSTaskStat(void);
#endif

#ifdef FW_TASK_PRIO_IDLE
FW_EXT INT16U  usOSIdleStackUsage;
FW_EXT OS_STK  OSIdleTaskStk[FW_TASK_STK_SIZE_IDLE];
#endif

#ifdef FW_TASK_PRIO_SDIO
FW_EXT INT16U  usFWSdioStackUsage;
FW_EXT OS_STK  FWSdioTaskStk[FW_TASK_STK_SIZE_SDIO];
FW_EXT void    FWSdioTask(void);
#endif

#ifdef FW_TASK_PRIO_LCD
FW_EXT INT16U  usFWLcdStackUsage;
FW_EXT OS_STK  FWLcdTaskStk[FW_TASK_STK_SIZE_LCD];
FW_EXT void    FWLcdTask(void);
#endif

/* ******************************************************************** */
/*                           Function Definition                        */
/* ******************************************************************** */
FW_EXT int     main(void);
FW_EXT void    FWInit(void);
FW_EXT void    FWInitPLL(void);
FW_EXT void    FWInitFLASH(void);
FW_EXT void    FWWatchdogInit(void);
FW_EXT void    FWWatchdogStop(void);
FW_EXT void    FWWatchdogFeed(void);
FW_EXT void    FWInitRCC(void);
FW_EXT void    FWInitClkHSI(void);
FW_EXT void    FWInitClkHSE(void);
FW_EXT void    FWInitPMC(void);
FW_EXT void    FWIrqEnable(INT08U ucChan, INT08U ucPrio);
FW_EXT void    FWIrqDisable(INT08U ucChan);
FW_EXT void    FWWaitTaskSynchro(INT32U mask, INT32U total);

/* ******************************************************************** */
/*                      Interrupt Hooks For STM32F1                     */
/* ******************************************************************** */
#if   (FW_CPU_STM32F1_ON == 1)
FW_EXT void    Reset_Handler(void);
FW_EXT void    NMI_Handler(void);
FW_EXT void    HardFault_Handler(void);
FW_EXT void    MemManage_Handler(void);
FW_EXT void    BusFault_Handler(void);
FW_EXT void    UsageFault_Handler(void);
FW_EXT void    SVC_Handler(void);
FW_EXT void    DebugMon_Handler(void);
FW_EXT void    PendSV_Handler(void);
FW_EXT void    SysTick_Handler(void);
FW_EXT void    WWDG_IRQHandler(void);
FW_EXT void    PVD_IRQHandler(void);
FW_EXT void    TAMPER_IRQHandler(void);
FW_EXT void    RTC_IRQHandler(void);
FW_EXT void    FLASH_IRQHandler(void);
FW_EXT void    RCC_IRQHandler(void);
FW_EXT void    EXTI0_IRQHandler(void);
FW_EXT void    EXTI1_IRQHandler(void);
FW_EXT void    EXTI2_IRQHandler(void);
FW_EXT void    EXTI3_IRQHandler(void);
FW_EXT void    EXTI4_IRQHandler(void);
FW_EXT void    DMA1_Channel1_IRQHandler(void);
FW_EXT void    DMA1_Channel2_IRQHandler(void);
FW_EXT void    DMA1_Channel3_IRQHandler(void);
FW_EXT void    DMA1_Channel4_IRQHandler(void);
FW_EXT void    DMA1_Channel5_IRQHandler(void);
FW_EXT void    DMA1_Channel6_IRQHandler(void);
FW_EXT void    DMA1_Channel7_IRQHandler(void);
#endif

#if   (FW_CPU_STM32F105_ON == 1)
FW_EXT void    ADC1_2_IRQHandler(void);
FW_EXT void    CAN1_TX_IRQHandler(void);
FW_EXT void    CAN1_RX0_IRQHandler(void);
FW_EXT void    CAN1_RX1_IRQHandler(void);
FW_EXT void    CAN1_SCE_IRQHandler(void);
FW_EXT void    EXTI9_5_IRQHandler(void);
FW_EXT void    TIM1_BRK_IRQHandler(void);
FW_EXT void    TIM1_UP_IRQHandler(void);
FW_EXT void    TIM1_TRG_COM_IRQHandler(void);
FW_EXT void    TIM1_CC_IRQHandler(void);
FW_EXT void    TIM2_IRQHandler(void);
FW_EXT void    TIM3_IRQHandler(void);
FW_EXT void    TIM4_IRQHandler(void);
FW_EXT void    I2C1_EV_IRQHandler(void);
FW_EXT void    I2C1_ER_IRQHandler(void);
FW_EXT void    I2C2_EV_IRQHandler(void);
FW_EXT void    I2C2_ER_IRQHandler(void);
FW_EXT void    SPI1_IRQHandler(void);
FW_EXT void    SPI2_IRQHandler(void);
FW_EXT void    USART1_IRQHandler(void);
FW_EXT void    USART2_IRQHandler(void);
FW_EXT void    USART3_IRQHandler(void);
FW_EXT void    EXTI15_10_IRQHandler(void);
FW_EXT void    RTC_Alarm_IRQHandler(void);
FW_EXT void    OTG_FS_WKUP_IRQHandler(void);
FW_EXT void    TIM5_IRQHandler(void);
FW_EXT void    SPI3_IRQHandler(void);
FW_EXT void    UART4_IRQHandler(void);
FW_EXT void    UART5_IRQHandler(void);
FW_EXT void    TIM6_IRQHandler(void);
FW_EXT void    TIM7_IRQHandler(void);
FW_EXT void    DMA2_Channel1_IRQHandler(void);
FW_EXT void    DMA2_Channel2_IRQHandler(void);
FW_EXT void    DMA2_Channel3_IRQHandler(void);
FW_EXT void    DMA2_Channel4_IRQHandler(void);
FW_EXT void    DMA2_Channel5_IRQHandler(void);
FW_EXT void    CAN2_TX_IRQHandler(void);
FW_EXT void    CAN2_RX0_IRQHandler(void);
FW_EXT void    CAN2_RX1_IRQHandler(void);
FW_EXT void    CAN2_SCE_IRQHandler(void);
FW_EXT void    OTG_FS_IRQHandler(void);
#endif

#if   (FW_CPU_STM32F103_ON == 1)
FW_EXT void    ADC1_2_IRQHandler(void);
FW_EXT void    USB_HP_CAN1_TX_IRQHandler(void);
FW_EXT void    USB_LP_CAN1_RX0_IRQHandler(void);
FW_EXT void    CAN1_RX1_IRQHandler(void);
FW_EXT void    CAN1_SCE_IRQHandler(void);
FW_EXT void    EXTI9_5_IRQHandler(void);
FW_EXT void    TIM1_BRK_TIM9_IRQHandler(void);
FW_EXT void    TIM1_UP_TIM10_IRQHandler(void);
FW_EXT void    TIM1_TRG_COM_TIM11_IRQHandler(void);
FW_EXT void    TIM1_CC_IRQHandler(void);
FW_EXT void    TIM2_IRQHandler(void);
FW_EXT void    TIM3_IRQHandler(void);
FW_EXT void    TIM4_IRQHandler(void);
FW_EXT void    I2C1_EV_IRQHandler(void);
FW_EXT void    I2C1_ER_IRQHandler(void);
FW_EXT void    I2C2_EV_IRQHandler(void);
FW_EXT void    I2C2_ER_IRQHandler(void);
FW_EXT void    SPI1_IRQHandler(void);
FW_EXT void    SPI2_IRQHandler(void);
FW_EXT void    USART1_IRQHandler(void);
FW_EXT void    USART2_IRQHandler(void);
FW_EXT void    USART3_IRQHandler(void);
FW_EXT void    EXTI15_10_IRQHandler(void);
FW_EXT void    RTCAlarm_IRQHandler(void);
FW_EXT void    USBWakeUp_IRQHandler(void);
FW_EXT void    TIM8_BRK_TIM12_IRQHandler(void);
FW_EXT void    TIM8_UP_TIM13_IRQHandler(void);
FW_EXT void    TIM8_TRG_COM_TIM14_IRQHandler(void);
FW_EXT void    TIM8_CC_IRQHandler(void);
FW_EXT void    ADC3_IRQHandler(void);
FW_EXT void    FSMC_IRQHandler(void);
FW_EXT void    SDIO_IRQHandler(void);
FW_EXT void    TIM5_IRQHandler(void);
FW_EXT void    SPI3_IRQHandler(void);
FW_EXT void    UART4_IRQHandler(void);
FW_EXT void    UART5_IRQHandler(void);
FW_EXT void    TIM6_IRQHandler(void);
FW_EXT void    TIM7_IRQHandler(void);
FW_EXT void    DMA2_Channel1_IRQHandler(void);
FW_EXT void    DMA2_Channel2_IRQHandler(void);
FW_EXT void    DMA2_Channel3_IRQHandler(void);
FW_EXT void    DMA2_Channel4_5_IRQHandler(void);
#endif

/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
