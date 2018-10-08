/* ******************************************************************** */
/*                     MODBUS protocol Version 1.0                      */
/*                       Header File SCI1Cortex.h                       */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _SCI1CORTEX_H

#define _SCI1CORTEX_H

#ifdef   SCI1_GLOBALS

#define  SCI1_EXT  

#else

#define  SCI1_EXT extern

#endif

/* ******************************************************************** */
/*  SCI1_VERSION  = 10xx: VEC1000 Application                           */
/*  SCI1_VERSION  = 40xx: VEC4000 Application                           */
/*  SCI1_VERSION  = 68xx: VEC6800 Application                           */
/*  SCI1_VERSION  = 69xx: VEC6900 Application                           */
/*  SCI1_VERSION  = 760x: GEC7600-Main Application                      */
/*  SCI1_VERSION  = 761x: GEC7600-Display Application                   */
/*  SCI1_VERSION  = 780x: GEC7800-Main Application                      */
/*  SCI1_VERSION  = 781x: GEC7800-Display Application                   */
/*  SCI1_VERSION  = 80xx: VEC8000 Application                           */
/*  SCI1_VERSION  = 90xx: VEC9000 Application                           */
/*  SCI1_VERSION  = 96xx: VEC9600 Application                           */
/* ******************************************************************** */

#define SCI1_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define SCI1_1000_COMMON_ON       0
#define SCI1_4000_COMMON_ON       0
#define SCI1_6800_COMMON_ON       0
#define SCI1_6900_COMMON_ON       0
#define SCI1_7600_COMMON_ON       0
#define SCI1_7600_MAIN_CHIP_ON    0
#define SCI1_7600_AUX_CHIP_ON     0
#define SCI1_7800_COMMON_ON       0
#define SCI1_7800_MAIN_CHIP_ON    0
#define SCI1_7800_AUX_CHIP_ON     0
#define SCI1_8000_COMMON_ON       0
#define SCI1_9000_COMMON_ON       0
#define SCI1_9600_COMMON_ON       0
#if   ((SCI1_VERSION / 100)   == 10)
#undef  SCI1_1000_COMMON_ON
#define SCI1_1000_COMMON_ON       1
#endif
#if   ((SCI1_VERSION / 100)   == 40)
#undef  SCI1_4000_COMMON_ON
#define SCI1_4000_COMMON_ON       1
#endif
#if   ((SCI1_VERSION / 100)   == 68)
#undef  SCI1_6800_COMMON_ON
#define SCI1_6800_COMMON_ON       1
#endif
#if   ((SCI1_VERSION / 100)   == 69)
#undef  SCI1_6900_COMMON_ON
#define SCI1_6900_COMMON_ON       1
#endif
#if   ((SCI1_VERSION / 100)   == 76)
#undef  SCI1_7600_COMMON_ON
#define SCI1_7600_COMMON_ON       1
#endif
#if   ((SCI1_VERSION / 10)   == 760)
#undef  SCI1_7600_MAIN_CHIP_ON
#define SCI1_7600_MAIN_CHIP_ON    1
#endif
#if   ((SCI1_VERSION / 10)   == 761)
#undef  SCI1_7600_AUX_CHIP_ON
#define SCI1_7600_AUX_CHIP_ON     1
#endif
#if   ((SCI1_VERSION / 100)   == 78)
#undef  SCI1_7800_COMMON_ON
#define SCI1_7800_COMMON_ON       1
#endif
#if   ((SCI1_VERSION / 10)   == 780)
#undef  SCI1_7800_MAIN_CHIP_ON
#define SCI1_7800_MAIN_CHIP_ON    1
#endif
#if   ((SCI1_VERSION / 10)   == 781)
#undef  SCI1_7800_AUX_CHIP_ON
#define SCI1_7800_AUX_CHIP_ON     1
#endif
#if   ((SCI1_VERSION / 100)   == 80)
#undef  SCI1_8000_COMMON_ON
#define SCI1_8000_COMMON_ON       1
#endif
#if   ((SCI1_VERSION / 100)   == 90)
#undef  SCI1_9000_COMMON_ON
#define SCI1_9000_COMMON_ON       1
#endif
#if   ((SCI1_VERSION / 100)   == 96)
#undef  SCI1_9600_COMMON_ON
#define SCI1_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define SCI1_FUNCTION_ON          1
#define SCI1_FULL_DUPLEX_ON       0
#define SCI1_CPU_9S12_ON          0
#define SCI1_CPU_POWERPC_ON       0
#define SCI1_CPU_STM32F1_ON       0
#define SCI1_CPU_STM32F103_ON     0
#define SCI1_CPU_STM32F105_ON     0
#if    (SCI1_1000_COMMON_ON    == 1)
#undef  SCI1_CPU_9S12_ON
#define SCI1_CPU_9S12_ON          1
#endif
#if    (SCI1_4000_COMMON_ON    == 1)
#undef  SCI1_CPU_9S12_ON
#define SCI1_CPU_9S12_ON          1
#endif
#if    (SCI1_6800_COMMON_ON    == 1)
#undef  SCI1_CPU_9S12_ON
#define SCI1_CPU_9S12_ON          1
#endif
#if    (SCI1_6900_COMMON_ON    == 1)
#undef  SCI1_CPU_POWERPC_ON
#define SCI1_CPU_POWERPC_ON       1
#endif
#if    (SCI1_7600_COMMON_ON    == 1)
#undef  SCI1_CPU_STM32F1_ON
#define SCI1_CPU_STM32F1_ON       1
#endif
#if    (SCI1_7600_MAIN_CHIP_ON == 1)
#undef  SCI1_CPU_STM32F105_ON
#define SCI1_CPU_STM32F105_ON     1
#endif
#if    (SCI1_7600_AUX_CHIP_ON  == 1)
#undef  SCI1_CPU_STM32F103_ON
#define SCI1_CPU_STM32F103_ON     1
#endif
#if    (SCI1_7800_COMMON_ON    == 1)
#undef  SCI1_CPU_STM32F1_ON
#define SCI1_CPU_STM32F1_ON       1
#endif
#if    (SCI1_7800_MAIN_CHIP_ON == 1)
#undef  SCI1_CPU_STM32F105_ON
#define SCI1_CPU_STM32F105_ON     1
#endif
#if    (SCI1_7800_AUX_CHIP_ON  == 1)
#undef  SCI1_CPU_STM32F103_ON
#define SCI1_CPU_STM32F103_ON     1
#endif
#if    (SCI1_8000_COMMON_ON    == 1)
#undef  SCI1_CPU_POWERPC_ON
#define SCI1_CPU_POWERPC_ON       1
#endif
#if    (SCI1_9000_COMMON_ON    == 1)
#undef  SCI1_CPU_POWERPC_ON
#define SCI1_CPU_POWERPC_ON       1
#endif
#if    (SCI1_9600_COMMON_ON    == 1)
#undef  SCI1_CPU_POWERPC_ON
#define SCI1_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                 F105 USART1 RX And TX Pin Definition                 */
/*                (Default: PA9 & PA10, Remap: PB6 & PB7)               */
/* ******************************************************************** */
#define SCI1_AFIO_REMAP1        0
#define SCI1_AFIO_REMAP2        0
#define SCI1_GPO_PT_SCITX       PA9
#define SCI1_GPI_PT_SCIRX       PA10
#define SCI1_GPO_PT_RELOAD      PB9
#define SCI1_TX_PT              GPIOA
#define SCI1_TX_BT              9
#define SCI1_RX_PT              GPIOA
#define SCI1_RX_BT              10
#define SCI1_RELOAD_PT          GPIOB
#define SCI1_RELOAD_BT          9
#define SCI1_SET_RELOAD()       SCI1_RELOAD_PT->BSRR = 1<<SCI1_RELOAD_BT
#define SCI1_CLR_RELOAD()       SCI1_RELOAD_PT->BRR  = 1<<SCI1_RELOAD_BT

/* ******************************************************************** */
/*                           Hardware Difference                        */
/* ******************************************************************** */
#if    (SCI1_CPU_STM32F1_ON == 1)
#define SCI1_FRQ_CLK           (INT32U)72000000     /* PCLK2 for USART1 */
#define SCI1_SCI_RX_EN()        USART1->CR1 |=  USART_CR1_RE
#define SCI1_SCI_RX_DIS()       USART1->CR1 &= ~USART_CR1_RE
#define SCI1_SCI_RX_INT_EN()    USART1->CR1 |=  USART_CR1_RXNEIE
#define SCI1_SCI_RX_INT_DIS()   USART1->CR1 &= ~USART_CR1_RXNEIE
#define SCI1_SCI_TX_EN()        USART1->CR1 |=  USART_CR1_TE
#define SCI1_SCI_TX_DIS()       USART1->CR1 &= ~USART_CR1_TE
#define SCI1_SCI_TC_INT_EN()    USART1->CR1 |=  USART_CR1_TCIE
#define SCI1_SCI_TC_INT_DIS()   USART1->CR1 &= ~USART_CR1_TCIE
#define SCI1_SCI_TX_INT_EN()    USART1->CR1 |=  USART_CR1_TXEIE
#define SCI1_SCI_TX_INT_DIS()   USART1->CR1 &= ~USART_CR1_TXEIE
#define SCI1_SCI_SR_TC_CLR()    USART1->SR  &= ~USART_SR_TC
#define SCI1_SCI_TXDMA_EN()     USART1->CR3 |=  USART_CR3_DMAT
#define SCI1_SCI_TXDMA_DIS()    USART1->CR3 &= ~USART_CR3_DMAT
#define SCI1_SCI_RXDMA_EN()     USART1->CR3 |=  USART_CR3_DMAR
#define SCI1_SCI_RXDMA_DIS()    USART1->CR3 &= ~USART_CR3_DMAR
#define SCI1_TX_DMA_CHANNEL     DMA1->Channel4
#define SCI1_RX_DMA_CHANNEL     DMA1->Channel5
#define SCI1_SCI_TX_DMA_ON      0
#define SCI1_SCI_RX_DMA_ON      0
#define SCI1_TX_DMA_TCINT_ON    0
#define SCI1_RX_DMA_TCINT_ON    0
#endif

/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define SCI1_TRUE               1
#define SCI1_FALSE              0
#define SCI1_NO_ERR             0
#define SCI1_ERR_EVENT_TYPE     1
#define SCI1_ERR_PEND_ISR       2
#define SCI1_ERR_BAD_CH         3
#define SCI1_ERR_RX_EMPTY       4
#define SCI1_ERR_TX_FULL        5
#define SCI1_ERR_TX_EMPTY       6
#define SCI1_ERR_RX_TIMEOUT     7
#define SCI1_ERR_TX_TIMEOUT     8
#define SCI1_STS_NORMAL        (INT32U)0x00000000
#define SCI1_STS_RESET         (INT32U)0x00000001
#define SCI1_STS_WARNING       (INT32U)0x00000002
#define SCI1_STS_BUS_OFF       (INT32U)0x00000004
#define SCI1_STS_SLEEPING      (INT32U)0x00000008
#define SCI1_STS_OVERRUN       (INT32U)0x00000010
#define SCI1_STS_ERR_TX        (INT32U)0x00000020
#define SCI1_STS_ERR_RX        (INT32U)0x00000040
#define SCI1_STS_ERR_ADDR      (INT32U)0x00000080
#define SCI1_STS_ERR_LOGIC     (INT32U)0x00000100
#define SCI1_STS_TO_1P5_ON     (INT32U)0x00000200
#define SCI1_STS_TO_2P5_ON     (INT32U)0x00000400
#define SCI1_STS_GET_BIT(m)    (uiSCI1Status & (m))
#define SCI1_STS_CLR_BIT(m)     uiSCI1Status &= ~(m)
#define SCI1_STS_SET_BIT(m)     uiSCI1Status |= (m)
#define SCI1_STEP_INIT         (INT08U)0
#define SCI1_STEP_IDLE         (INT08U)1
#define SCI1_STEP_RX_ING       (INT08U)2
#define SCI1_STEP_RX_WAIT      (INT08U)3
#define SCI1_STEP_TX_ING       (INT08U)4
#define SCI1_STEP_TX_WAIT      (INT08U)5

/* ******************************************************************** */
/*                          Control Definition                          */
/* ******************************************************************** */
#define SCI1_OVERTIME_TIMER     TIM2->CCR1
#define SCI1_MY_ADDRESS_DEF     1
#define SCI1_BAUDRATE_DEF       9600

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)

SCI1_EXT INT32U uiSCI1Status;
SCI1_EXT INT08U ucSCI1CtrlStep;
SCI1_EXT INT08U ucSCI1RxByteCnt;
SCI1_EXT INT08U ucSCI1TxByteCnt;
SCI1_EXT INT16U usSCI1OverTime1P5;
SCI1_EXT INT16U usSCI1OverTime2P0;
SCI1_EXT INT16U usSCI1OverTime2P5;
SCI1_EXT INT16U usSCI1OverTime4P0;
SCI1_EXT INT16U usSCI1OverTime4P5;
SCI1_EXT INT32U uiSCI1BaudRate;
SCI1_EXT MODBUS_MSG sSCI1ModbusMsg;

#endif
/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)

SCI1_EXT void   SCI1Init(void);
SCI1_EXT void   SCI1Start(void);
SCI1_EXT void   SCI1TaskLoop(void);
SCI1_EXT void   SCI1TxRxIntHook(void);
SCI1_EXT void   SCI1OverTimerHook(void);
SCI1_EXT void   SCI1Dma1Ch4IntHook(void);
SCI1_EXT void   SCI1Dma1Ch5IntHook(void);
SCI1_EXT void   SCI1SetOverTimer(INT16U usDelay);
SCI1_EXT void   SCI1InitOverTimer(void);
SCI1_EXT void   SCI1HardInit(INT32U uiBaud);
#if (SCI1_SCI_TX_DMA_ON == 1)
SCI1_EXT void   SCI1InitTxDma(void);
SCI1_EXT void   SCI1SetupTxDma(INT08U *pAddr, INT16U usSize);
#endif
#if (SCI1_SCI_RX_DMA_ON == 1)
SCI1_EXT void   SCI1InitRxDma(void);
SCI1_EXT void   SCI1SetupRxDma(INT08U *pAddr, INT16U usSize);
#endif

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */