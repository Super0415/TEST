/* ******************************************************************** */
/*                     MODBUS protocol Version 1.0                      */
/*                       Header File SCI3Cortex.h                       */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _SCI3CORTEX_H

#define _SCI3CORTEX_H

#ifdef   SCI3_GLOBALS

#define  SCI3_EXT  

#else

#define  SCI3_EXT extern

#endif

/* ******************************************************************** */
/*  SCI3_VERSION  = 10xx: VEC1000 Application                           */
/*  SCI3_VERSION  = 40xx: VEC4000 Application                           */
/*  SCI3_VERSION  = 68xx: VEC6800 Application                           */
/*  SCI3_VERSION  = 69xx: VEC6900 Application                           */
/*  SCI3_VERSION  = 760x: GEC7600-Main Application                      */
/*  SCI3_VERSION  = 761x: GEC7600-Display Application                   */
/*  SCI3_VERSION  = 780x: GEC7800-Main Application                      */
/*  SCI3_VERSION  = 781x: GEC7800-Display Application                   */
/*  SCI3_VERSION  = 80xx: VEC8000 Application                           */
/*  SCI3_VERSION  = 90xx: VEC9000 Application                           */
/*  SCI3_VERSION  = 96xx: VEC9600 Application                           */
/* ******************************************************************** */

#define SCI3_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define SCI3_1000_COMMON_ON       0
#define SCI3_4000_COMMON_ON       0
#define SCI3_6800_COMMON_ON       0
#define SCI3_6900_COMMON_ON       0
#define SCI3_7600_COMMON_ON       0
#define SCI3_7600_MAIN_CHIP_ON    0
#define SCI3_7600_AUX_CHIP_ON     0
#define SCI3_7800_COMMON_ON       0
#define SCI3_7800_MAIN_CHIP_ON    0
#define SCI3_7800_AUX_CHIP_ON     0
#define SCI3_8000_COMMON_ON       0
#define SCI3_9000_COMMON_ON       0
#define SCI3_9600_COMMON_ON       0
#if   ((SCI3_VERSION / 100)   == 10)
#undef  SCI3_1000_COMMON_ON
#define SCI3_1000_COMMON_ON       1
#endif
#if   ((SCI3_VERSION / 100)   == 40)
#undef  SCI3_4000_COMMON_ON
#define SCI3_4000_COMMON_ON       1
#endif
#if   ((SCI3_VERSION / 100)   == 68)
#undef  SCI3_6800_COMMON_ON
#define SCI3_6800_COMMON_ON       1
#endif
#if   ((SCI3_VERSION / 100)   == 69)
#undef  SCI3_6900_COMMON_ON
#define SCI3_6900_COMMON_ON       1
#endif
#if   ((SCI3_VERSION / 100)   == 76)
#undef  SCI3_7600_COMMON_ON
#define SCI3_7600_COMMON_ON       1
#endif
#if   ((SCI3_VERSION / 10)   == 760)
#undef  SCI3_7600_MAIN_CHIP_ON
#define SCI3_7600_MAIN_CHIP_ON    1
#endif
#if   ((SCI3_VERSION / 10)   == 761)
#undef  SCI3_7600_AUX_CHIP_ON
#define SCI3_7600_AUX_CHIP_ON     1
#endif
#if   ((SCI3_VERSION / 100)   == 78)
#undef  SCI3_7800_COMMON_ON
#define SCI3_7800_COMMON_ON       1
#endif
#if   ((SCI3_VERSION / 10)   == 780)
#undef  SCI3_7800_MAIN_CHIP_ON
#define SCI3_7800_MAIN_CHIP_ON    1
#endif
#if   ((SCI3_VERSION / 10)   == 781)
#undef  SCI3_7800_AUX_CHIP_ON
#define SCI3_7800_AUX_CHIP_ON     1
#endif
#if   ((SCI3_VERSION / 100)   == 80)
#undef  SCI3_8000_COMMON_ON
#define SCI3_8000_COMMON_ON       1
#endif
#if   ((SCI3_VERSION / 100)   == 90)
#undef  SCI3_9000_COMMON_ON
#define SCI3_9000_COMMON_ON       1
#endif
#if   ((SCI3_VERSION / 100)   == 96)
#undef  SCI3_9600_COMMON_ON
#define SCI3_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define SCI3_FUNCTION_ON          1
#define SCI3_FULL_DUPLEX_ON       0
#define SCI3_CPU_9S12_ON          0
#define SCI3_CPU_POWERPC_ON       0
#define SCI3_CPU_STM32F1_ON       0
#define SCI3_CPU_STM32F103_ON     0
#define SCI3_CPU_STM32F105_ON     0
#if    (SCI3_1000_COMMON_ON    == 1)
#undef  SCI3_CPU_9S12_ON
#define SCI3_CPU_9S12_ON          1
#endif
#if    (SCI3_4000_COMMON_ON    == 1)
#undef  SCI3_CPU_9S12_ON
#define SCI3_CPU_9S12_ON          1
#endif
#if    (SCI3_6800_COMMON_ON    == 1)
#undef  SCI3_CPU_9S12_ON
#define SCI3_CPU_9S12_ON          1
#endif
#if    (SCI3_6900_COMMON_ON    == 1)
#undef  SCI3_CPU_POWERPC_ON
#define SCI3_CPU_POWERPC_ON       1
#endif
#if    (SCI3_7600_COMMON_ON    == 1)
#undef  SCI3_CPU_STM32F1_ON
#define SCI3_CPU_STM32F1_ON       1
#endif
#if    (SCI3_7600_MAIN_CHIP_ON == 1)
#undef  SCI3_CPU_STM32F105_ON
#define SCI3_CPU_STM32F105_ON     1
#endif
#if    (SCI3_7600_AUX_CHIP_ON  == 1)
#undef  SCI3_CPU_STM32F103_ON
#define SCI3_CPU_STM32F103_ON     1
#endif
#if    (SCI3_7800_COMMON_ON    == 1)
#undef  SCI3_CPU_STM32F1_ON
#define SCI3_CPU_STM32F1_ON       1
#endif
#if    (SCI3_7800_MAIN_CHIP_ON == 1)
#undef  SCI3_CPU_STM32F105_ON
#define SCI3_CPU_STM32F105_ON     1
#endif
#if    (SCI3_7800_AUX_CHIP_ON  == 1)
#undef  SCI3_CPU_STM32F103_ON
#define SCI3_CPU_STM32F103_ON     1
#endif
#if    (SCI3_8000_COMMON_ON    == 1)
#undef  SCI3_CPU_POWERPC_ON
#define SCI3_CPU_POWERPC_ON       1
#endif
#if    (SCI3_9000_COMMON_ON    == 1)
#undef  SCI3_CPU_POWERPC_ON
#define SCI3_CPU_POWERPC_ON       1
#endif
#if    (SCI3_9600_COMMON_ON    == 1)
#undef  SCI3_CPU_POWERPC_ON
#define SCI3_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                 F105 USART3 RX And TX Pin Definition                 */
/*    (Default: PB10 & PB11, Partial: PC10 & PC11, Full: PD8 & PD9)     */
/* ******************************************************************** */
#define SCI3_AFIO_REMAP1        0
#define SCI3_AFIO_REMAP2        0
#define SCI3_GPO_PT_SCITX       PB10
#define SCI3_GPI_PT_SCIRX       PB11
#define SCI3_GPO_PT_RE          PE15
#define SCI3_TX_PT              GPIOB
#define SCI3_TX_BT              10
#define SCI3_RX_PT              GPIOB
#define SCI3_RX_BT              11
#define SCI3_RE_PT              GPIOE
#define SCI3_RE_BT              15
#define SCI3_RE_BT_SET()        SCI3_RE_PT->BSRR = (INT32U)1 << SCI3_RE_BT
#define SCI3_RE_BT_CLR()        SCI3_RE_PT->BRR  = (INT32U)1 << SCI3_RE_BT

/* ******************************************************************** */
/*                           Hardware Difference                        */
/* ******************************************************************** */
#if    (SCI3_CPU_STM32F1_ON == 1)
#define SCI3_FRQ_CLK           (INT32U)72000000     /* PCLK1 for USART3 */
#define SCI3_SCI_RX_EN()        USART3->CR1 |=  USART_CR1_RE
#define SCI3_SCI_RX_DIS()       USART3->CR1 &= ~USART_CR1_RE
#define SCI3_SCI_RX_INT_EN()    USART3->CR1 |=  USART_CR1_RXNEIE
#define SCI3_SCI_RX_INT_DIS()   USART3->CR1 &= ~USART_CR1_RXNEIE
#define SCI3_SCI_TX_EN()        USART3->CR1 |=  USART_CR1_TE
#define SCI3_SCI_TX_DIS()       USART3->CR1 &= ~USART_CR1_TE
#define SCI3_SCI_TC_INT_EN()    USART3->CR1 |=  USART_CR1_TCIE
#define SCI3_SCI_TC_INT_DIS()   USART3->CR1 &= ~USART_CR1_TCIE
#define SCI3_SCI_TX_INT_EN()    USART3->CR1 |=  USART_CR1_TXEIE
#define SCI3_SCI_TX_INT_DIS()   USART3->CR1 &= ~USART_CR1_TXEIE
#define SCI3_SCI_SR_TC_CLR()    USART3->SR  &= ~USART_SR_TC
#define SCI3_SCI_TXDMA_EN()     USART3->CR3 |=  USART_CR3_DMAT
#define SCI3_SCI_TXDMA_DIS()    USART3->CR3 &= ~USART_CR3_DMAT
#define SCI3_SCI_RXDMA_EN()     USART3->CR3 |=  USART_CR3_DMAR
#define SCI3_SCI_RXDMA_DIS()    USART3->CR3 &= ~USART_CR3_DMAR
#define SCI3_TX_DMA_CHANNEL     DMA1->Channel2
#define SCI3_RX_DMA_CHANNEL     DMA1->Channel3
#define SCI3_SCI_TX_DMA_ON      1
#define SCI3_SCI_RX_DMA_ON      0
#define SCI3_TX_DMA_TCINT_ON    1
#define SCI3_RX_DMA_TCINT_ON    0
#endif

/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define SCI3_TRUE               1
#define SCI3_FALSE              0
#define SCI3_NO_ERR             0
#define SCI3_ERR_EVENT_TYPE     1
#define SCI3_ERR_PEND_ISR       2
#define SCI3_ERR_BAD_CH         3
#define SCI3_ERR_RX_EMPTY       4
#define SCI3_ERR_TX_FULL        5
#define SCI3_ERR_TX_EMPTY       6
#define SCI3_ERR_RX_TIMEOUT     7
#define SCI3_ERR_TX_TIMEOUT     8
#define SCI3_STS_NORMAL        (INT32U)0x00000000
#define SCI3_STS_RESET         (INT32U)0x00000001
#define SCI3_STS_WARNING       (INT32U)0x00000002
#define SCI3_STS_BUS_OFF       (INT32U)0x00000004
#define SCI3_STS_SLEEPING      (INT32U)0x00000008
#define SCI3_STS_OVERRUN       (INT32U)0x00000010
#define SCI3_STS_ERR_TX        (INT32U)0x00000020
#define SCI3_STS_ERR_RX        (INT32U)0x00000040
#define SCI3_STS_ERR_ADDR      (INT32U)0x00000080
#define SCI3_STS_ERR_LOGIC     (INT32U)0x00000100
#define SCI3_STS_TO_1P5_ON     (INT32U)0x00000200
#define SCI3_STS_TO_2P5_ON     (INT32U)0x00000400
#define SCI3_STS_GET_BIT(m)    (uiSCI3Status & (m))
#define SCI3_STS_CLR_BIT(m)     uiSCI3Status &= ~(m)
#define SCI3_STS_SET_BIT(m)     uiSCI3Status |= (m)
#define SCI3_STEP_INIT         (INT08U)0
#define SCI3_STEP_IDLE         (INT08U)1
#define SCI3_STEP_RX_ING       (INT08U)2
#define SCI3_STEP_RX_WAIT      (INT08U)3
#define SCI3_STEP_TX_ING       (INT08U)4
#define SCI3_STEP_TX_WAIT      (INT08U)5

/* ******************************************************************** */
/*                          Control Definition                          */
/* ******************************************************************** */
#define SCI3_OVERTIME_TIMER     TIM2->CCR3
#define SCI3_MY_ADDRESS_DEF     1
#define SCI3_BAUDRATE_DEF       9600

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)

SCI3_EXT INT32U uiSCI3Status;
SCI3_EXT INT08U ucSCI3CtrlStep;
SCI3_EXT INT08U ucSCI3RxByteCnt;
SCI3_EXT INT08U ucSCI3TxByteCnt;
SCI3_EXT INT16U usSCI3OverTime1P5;
SCI3_EXT INT16U usSCI3OverTime2P0;
SCI3_EXT INT16U usSCI3OverTime2P5;
SCI3_EXT INT16U usSCI3OverTime4P0;
SCI3_EXT INT16U usSCI3OverTime4P5;
SCI3_EXT INT32U uiSCI3BaudRate;
SCI3_EXT MODBUS_MSG sSCI3ModbusMsg;

#endif
/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)

SCI3_EXT void   SCI3Init(void);
SCI3_EXT void   SCI3Start(void);
SCI3_EXT void   SCI3TaskLoop(void);
SCI3_EXT void   SCI3TxRxIntHook(void);
SCI3_EXT void   SCI3OverTimerHook(void);
SCI3_EXT void   SCI3Dma1Ch2IntHook(void);
SCI3_EXT void   SCI3Dma1Ch3IntHook(void);
SCI3_EXT void   SCI3SetOverTimer(INT16U usDelay);
SCI3_EXT void   SCI3InitOverTimer(void);
SCI3_EXT void   SCI3HardInit(INT32U uiBaud);
#if (SCI3_SCI_TX_DMA_ON == 1)
SCI3_EXT void   SCI3InitTxDma(void);
SCI3_EXT void   SCI3SetupTxDma(INT08U *pAddr, INT16U usSize);
#endif
#if (SCI3_SCI_RX_DMA_ON == 1)
SCI3_EXT void   SCI3InitRxDma(void);
SCI3_EXT void   SCI3SetupRxDma(INT08U *pAddr, INT16U usSize);
#endif

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */