/* ******************************************************************** */
/*                     MODBUS protocol Version 1.0                      */
/*                       Header File SCI2Cortex.h                       */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _SCI2CORTEX_H

#define _SCI2CORTEX_H

#ifdef   SCI2_GLOBALS

#define  SCI2_EXT  

#else

#define  SCI2_EXT extern

#endif

/* ******************************************************************** */
/*  SCI2_VERSION  = 10xx: VEC1000 Application                           */
/*  SCI2_VERSION  = 40xx: VEC4000 Application                           */
/*  SCI2_VERSION  = 68xx: VEC6800 Application                           */
/*  SCI2_VERSION  = 69xx: VEC6900 Application                           */
/*  SCI2_VERSION  = 760x: GEC7600-Main Application                      */
/*  SCI2_VERSION  = 761x: GEC7600-Display Application                   */
/*  SCI2_VERSION  = 780x: GEC7800-Main Application                      */
/*  SCI2_VERSION  = 781x: GEC7800-Display Application                   */
/*  SCI2_VERSION  = 80xx: VEC8000 Application                           */
/*  SCI2_VERSION  = 90xx: VEC9000 Application                           */
/*  SCI2_VERSION  = 96xx: VEC9600 Application                           */
/* ******************************************************************** */

#define SCI2_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define SCI2_1000_COMMON_ON       0
#define SCI2_4000_COMMON_ON       0
#define SCI2_6800_COMMON_ON       0
#define SCI2_6900_COMMON_ON       0
#define SCI2_7600_COMMON_ON       0
#define SCI2_7600_MAIN_CHIP_ON    0
#define SCI2_7600_AUX_CHIP_ON     0
#define SCI2_7800_COMMON_ON       0
#define SCI2_7800_MAIN_CHIP_ON    0
#define SCI2_7800_AUX_CHIP_ON     0
#define SCI2_8000_COMMON_ON       0
#define SCI2_9000_COMMON_ON       0
#define SCI2_9600_COMMON_ON       0
#if   ((SCI2_VERSION / 100)   == 10)
#undef  SCI2_1000_COMMON_ON
#define SCI2_1000_COMMON_ON       1
#endif
#if   ((SCI2_VERSION / 100)   == 40)
#undef  SCI2_4000_COMMON_ON
#define SCI2_4000_COMMON_ON       1
#endif
#if   ((SCI2_VERSION / 100)   == 68)
#undef  SCI2_6800_COMMON_ON
#define SCI2_6800_COMMON_ON       1
#endif
#if   ((SCI2_VERSION / 100)   == 69)
#undef  SCI2_6900_COMMON_ON
#define SCI2_6900_COMMON_ON       1
#endif
#if   ((SCI2_VERSION / 100)   == 76)
#undef  SCI2_7600_COMMON_ON
#define SCI2_7600_COMMON_ON       1
#endif
#if   ((SCI2_VERSION / 10)   == 760)
#undef  SCI2_7600_MAIN_CHIP_ON
#define SCI2_7600_MAIN_CHIP_ON    1
#endif
#if   ((SCI2_VERSION / 10)   == 761)
#undef  SCI2_7600_AUX_CHIP_ON
#define SCI2_7600_AUX_CHIP_ON     1
#endif
#if   ((SCI2_VERSION / 100)   == 78)
#undef  SCI2_7800_COMMON_ON
#define SCI2_7800_COMMON_ON       1
#endif
#if   ((SCI2_VERSION / 10)   == 780)
#undef  SCI2_7800_MAIN_CHIP_ON
#define SCI2_7800_MAIN_CHIP_ON    1
#endif
#if   ((SCI2_VERSION / 10)   == 781)
#undef  SCI2_7800_AUX_CHIP_ON
#define SCI2_7800_AUX_CHIP_ON     1
#endif
#if   ((SCI2_VERSION / 100)   == 80)
#undef  SCI2_8000_COMMON_ON
#define SCI2_8000_COMMON_ON       1
#endif
#if   ((SCI2_VERSION / 100)   == 90)
#undef  SCI2_9000_COMMON_ON
#define SCI2_9000_COMMON_ON       1
#endif
#if   ((SCI2_VERSION / 100)   == 96)
#undef  SCI2_9600_COMMON_ON
#define SCI2_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define SCI2_FUNCTION_ON          1
#define SCI2_FULL_DUPLEX_ON       0
#define SCI2_CPU_9S12_ON          0
#define SCI2_CPU_POWERPC_ON       0
#define SCI2_CPU_STM32F1_ON       0
#define SCI2_CPU_STM32F103_ON     0
#define SCI2_CPU_STM32F105_ON     0
#if    (SCI2_1000_COMMON_ON    == 1)
#undef  SCI2_CPU_9S12_ON
#define SCI2_CPU_9S12_ON          1
#endif
#if    (SCI2_4000_COMMON_ON    == 1)
#undef  SCI2_CPU_9S12_ON
#define SCI2_CPU_9S12_ON          1
#endif
#if    (SCI2_6800_COMMON_ON    == 1)
#undef  SCI2_CPU_9S12_ON
#define SCI2_CPU_9S12_ON          1
#endif
#if    (SCI2_6900_COMMON_ON    == 1)
#undef  SCI2_CPU_POWERPC_ON
#define SCI2_CPU_POWERPC_ON       1
#endif
#if    (SCI2_7600_COMMON_ON    == 1)
#undef  SCI2_CPU_STM32F1_ON
#define SCI2_CPU_STM32F1_ON       1
#endif
#if    (SCI2_7600_MAIN_CHIP_ON == 1)
#undef  SCI2_CPU_STM32F105_ON
#define SCI2_CPU_STM32F105_ON     1
#endif
#if    (SCI2_7600_AUX_CHIP_ON  == 1)
#undef  SCI2_CPU_STM32F103_ON
#define SCI2_CPU_STM32F103_ON     1
#endif
#if    (SCI2_7800_COMMON_ON    == 1)
#undef  SCI2_CPU_STM32F1_ON
#define SCI2_CPU_STM32F1_ON       1
#endif
#if    (SCI2_7800_MAIN_CHIP_ON == 1)
#undef  SCI2_CPU_STM32F105_ON
#define SCI2_CPU_STM32F105_ON     1
#endif
#if    (SCI2_7800_AUX_CHIP_ON  == 1)
#undef  SCI2_CPU_STM32F103_ON
#define SCI2_CPU_STM32F103_ON     1
#endif
#if    (SCI2_8000_COMMON_ON    == 1)
#undef  SCI2_CPU_POWERPC_ON
#define SCI2_CPU_POWERPC_ON       1
#endif
#if    (SCI2_9000_COMMON_ON    == 1)
#undef  SCI2_CPU_POWERPC_ON
#define SCI2_CPU_POWERPC_ON       1
#endif
#if    (SCI2_9600_COMMON_ON    == 1)
#undef  SCI2_CPU_POWERPC_ON
#define SCI2_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                 F105 USART2 RX And TX Pin Definition                 */
/*                (Default: PA2 & PA3, Remap: PD5 & PD6)                */
/* ******************************************************************** */
#define SCI2_AFIO_REMAP1        AFIO_MAPR_USART2_REMAP
#define SCI2_AFIO_REMAP2        0
#define SCI2_GPO_PT_SCITX       PD5
#define SCI2_GPI_PT_SCIRX       PD6
#define SCI2_TX_PT              GPIOD
#define SCI2_TX_BT              5
#define SCI2_RX_PT              GPIOD
#define SCI2_RX_BT              6

/* ******************************************************************** */
/*                           Hardware Difference                        */
/* ******************************************************************** */
#if    (SCI2_CPU_STM32F1_ON == 1)
#define SCI2_FRQ_CLK           (INT32U)72000000     /* PCLK1 for USART2 */
#define SCI2_SCI_RX_EN()        USART2->CR1 |=  USART_CR1_RE
#define SCI2_SCI_RX_DIS()       USART2->CR1 &= ~USART_CR1_RE
#define SCI2_SCI_RX_INT_EN()    USART2->CR1 |=  USART_CR1_RXNEIE
#define SCI2_SCI_RX_INT_DIS()   USART2->CR1 &= ~USART_CR1_RXNEIE
#define SCI2_SCI_TX_EN()        USART2->CR1 |=  USART_CR1_TE
#define SCI2_SCI_TX_DIS()       USART2->CR1 &= ~USART_CR1_TE
#define SCI2_SCI_TC_INT_EN()    USART2->CR1 |=  USART_CR1_TCIE
#define SCI2_SCI_TC_INT_DIS()   USART2->CR1 &= ~USART_CR1_TCIE
#define SCI2_SCI_TX_INT_EN()    USART2->CR1 |=  USART_CR1_TXEIE
#define SCI2_SCI_TX_INT_DIS()   USART2->CR1 &= ~USART_CR1_TXEIE
#define SCI2_SCI_SR_TC_CLR()    USART2->SR  &= ~USART_SR_TC
#define SCI2_SCI_TXDMA_EN()     USART2->CR3 |=  USART_CR3_DMAT
#define SCI2_SCI_TXDMA_DIS()    USART2->CR3 &= ~USART_CR3_DMAT
#define SCI2_SCI_RXDMA_EN()     USART2->CR3 |=  USART_CR3_DMAR
#define SCI2_SCI_RXDMA_DIS()    USART2->CR3 &= ~USART_CR3_DMAR
#define SCI2_TX_DMA_CHANNEL     DMA1->Channel7
#define SCI2_RX_DMA_CHANNEL     DMA1->Channel6
#define SCI2_SCI_TX_DMA_ON      0
#define SCI2_SCI_RX_DMA_ON      0
#define SCI2_TX_DMA_TCINT_ON    0
#define SCI2_RX_DMA_TCINT_ON    0
#endif

/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define SCI2_TRUE               1
#define SCI2_FALSE              0
#define SCI2_NO_ERR             0
#define SCI2_ERR_EVENT_TYPE     1
#define SCI2_ERR_PEND_ISR       2
#define SCI2_ERR_BAD_CH         3
#define SCI2_ERR_RX_EMPTY       4
#define SCI2_ERR_TX_FULL        5
#define SCI2_ERR_TX_EMPTY       6
#define SCI2_ERR_RX_TIMEOUT     7
#define SCI2_ERR_TX_TIMEOUT     8
#define SCI2_STS_NORMAL        (INT32U)0x00000000
#define SCI2_STS_RESET         (INT32U)0x00000001
#define SCI2_STS_WARNING       (INT32U)0x00000002
#define SCI2_STS_BUS_OFF       (INT32U)0x00000004
#define SCI2_STS_SLEEPING      (INT32U)0x00000008
#define SCI2_STS_OVERRUN       (INT32U)0x00000010
#define SCI2_STS_TX_ERR        (INT32U)0x00000020
#define SCI2_STS_RX_ERR        (INT32U)0x00000040
#define SCI2_STS_GET_BIT(m)    (uiSCI2Status & (m))
#define SCI2_STS_CLR_BIT(m)     uiSCI2Status &= ~(m)
#define SCI2_STS_SET_BIT(m)     uiSCI2Status |= (m)
#define SCI2_SCI_DO_MASK       (INT08U)0xC0
#define SCI2_SCI_IS_MASK       (INT08U)0x30
#define SCI2_SCI_H4_MASK       (INT08U)0x0F
#define SCI2_SCI_DO_QUERY      (INT08U)0x40
#define SCI2_SCI_DO_MODIFY     (INT08U)0x80
#define SCI2_SCI_DO_SAVE       (INT08U)0xC0
#define SCI2_SCI_IS_PARAM      (INT08U)0x00
#define SCI2_SCI_IS_MEASU      (INT08U)0x10
#define SCI2_SCI_IS_FUNCT      (INT08U)0x20
#define SCI2_SCI_IS_CURVE      (INT08U)0x30

/* ******************************************************************** */
/*                          Control Definition                          */
/* ******************************************************************** */
#define SCI2_BAUDRATE_DEF       9600
#define SCI2_RX_BUF_SIZE        8
#define SCI2_TX_BUF_SIZE        8
#define SCI2_RX_TO_TICKS        10
#define SCI2_TX_TO_TICKS        10

/* ******************************************************************** */
/*                           Type Definition                            */
/* ******************************************************************** */
typedef struct
{   INT16U      usRingBufRxCtr;
    OS_EVENT   *pRingBufRxSem;
    INT08U     *pRingBufRxInPtr;
    INT08U     *pRingBufRxOutPtr;
    INT08U      ucRingBufRx[SCI2_RX_BUF_SIZE];
    INT16U      usRingBufTxCtr;
    OS_EVENT   *pRingBufTxSem;
    INT08U     *pRingBufTxInPtr;
    INT08U     *pRingBufTxOutPtr;
    INT08U      ucRingBufTx[SCI2_TX_BUF_SIZE];
}   SCI2_RING_STR;

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
#if (SCI2_FUNCTION_ON == 1)

SCI2_EXT INT32U uiSCI2Status;
SCI2_EXT SCI2_RING_STR sSCI2RingBuf;

#endif
/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (SCI2_FUNCTION_ON == 1)

SCI2_EXT void   SCI2Init(void);
SCI2_EXT void   SCI2Start(void);
SCI2_EXT void   SCI2TaskLoop(void);
SCI2_EXT void   SCI2TxRxIntHook(void);
SCI2_EXT void   SCI2OverTimerHook(void);
SCI2_EXT void   SCI2Dma1Ch7IntHook(void);
SCI2_EXT void   SCI2Dma1Ch6IntHook(void);
SCI2_EXT void   SCI2BufInit(void);
SCI2_EXT void   SCI2PutRxChar(INT08U c);
SCI2_EXT INT08U SCI2GetTxChar(INT08U *err);
SCI2_EXT INT08U SCI2GetChar(INT16U to, INT08U *err);
SCI2_EXT INT08U SCI2PutChar(INT16U to, INT08U c);
SCI2_EXT void   SCI2HardInit(INT32U uiBaud);
#if (SCI2_SCI_TX_DMA_ON == 1)
SCI2_EXT void   SCI2InitTxDma(void);
SCI2_EXT void   SCI2SetupTxDma(INT08U *pAddr, INT16U usSize);
#endif
#if (SCI2_SCI_RX_DMA_ON == 1)
SCI2_EXT void   SCI2InitRxDma(void);
SCI2_EXT void   SCI2SetupRxDma(INT08U *pAddr, INT16U usSize);
#endif

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */