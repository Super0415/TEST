/* ******************************************************************** */
/*                     MODBUS protocol Version 1.0                      */
/*                       Header File SCI5Cortex.h                       */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _SCI5CORTEX_H

#define _SCI5CORTEX_H

#ifdef   SCI5_GLOBALS

#define  SCI5_EXT  

#else

#define  SCI5_EXT extern

#endif

/* ******************************************************************** */
/*  SCI5_VERSION  = 10xx: VEC1000 Application                           */
/*  SCI5_VERSION  = 40xx: VEC4000 Application                           */
/*  SCI5_VERSION  = 68xx: VEC6800 Application                           */
/*  SCI5_VERSION  = 69xx: VEC6900 Application                           */
/*  SCI5_VERSION  = 760x: GEC7600-Main Application                      */
/*  SCI5_VERSION  = 761x: GEC7600-Display Application                   */
/*  SCI5_VERSION  = 780x: GEC7800-Main Application                      */
/*  SCI5_VERSION  = 781x: GEC7800-Display Application                   */
/*  SCI5_VERSION  = 80xx: VEC8000 Application                           */
/*  SCI5_VERSION  = 90xx: VEC9000 Application                           */
/*  SCI5_VERSION  = 96xx: VEC9600 Application                           */
/* ******************************************************************** */

#define SCI5_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define SCI5_1000_COMMON_ON       0
#define SCI5_4000_COMMON_ON       0
#define SCI5_6800_COMMON_ON       0
#define SCI5_6900_COMMON_ON       0
#define SCI5_7600_COMMON_ON       0
#define SCI5_7600_MAIN_CHIP_ON    0
#define SCI5_7600_AUX_CHIP_ON     0
#define SCI5_7800_COMMON_ON       0
#define SCI5_7800_MAIN_CHIP_ON    0
#define SCI5_7800_AUX_CHIP_ON     0
#define SCI5_8000_COMMON_ON       0
#define SCI5_9000_COMMON_ON       0
#define SCI5_9600_COMMON_ON       0
#if   ((SCI5_VERSION / 100)   == 10)
#undef  SCI5_1000_COMMON_ON
#define SCI5_1000_COMMON_ON       1
#endif
#if   ((SCI5_VERSION / 100)   == 40)
#undef  SCI5_4000_COMMON_ON
#define SCI5_4000_COMMON_ON       1
#endif
#if   ((SCI5_VERSION / 100)   == 68)
#undef  SCI5_6800_COMMON_ON
#define SCI5_6800_COMMON_ON       1
#endif
#if   ((SCI5_VERSION / 100)   == 69)
#undef  SCI5_6900_COMMON_ON
#define SCI5_6900_COMMON_ON       1
#endif
#if   ((SCI5_VERSION / 100)   == 76)
#undef  SCI5_7600_COMMON_ON
#define SCI5_7600_COMMON_ON       1
#endif
#if   ((SCI5_VERSION / 10)   == 760)
#undef  SCI5_7600_MAIN_CHIP_ON
#define SCI5_7600_MAIN_CHIP_ON    1
#endif
#if   ((SCI5_VERSION / 10)   == 761)
#undef  SCI5_7600_AUX_CHIP_ON
#define SCI5_7600_AUX_CHIP_ON     1
#endif
#if   ((SCI5_VERSION / 100)   == 78)
#undef  SCI5_7800_COMMON_ON
#define SCI5_7800_COMMON_ON       1
#endif
#if   ((SCI5_VERSION / 10)   == 780)
#undef  SCI5_7800_MAIN_CHIP_ON
#define SCI5_7800_MAIN_CHIP_ON    1
#endif
#if   ((SCI5_VERSION / 10)   == 781)
#undef  SCI5_7800_AUX_CHIP_ON
#define SCI5_7800_AUX_CHIP_ON     1
#endif
#if   ((SCI5_VERSION / 100)   == 80)
#undef  SCI5_8000_COMMON_ON
#define SCI5_8000_COMMON_ON       1
#endif
#if   ((SCI5_VERSION / 100)   == 90)
#undef  SCI5_9000_COMMON_ON
#define SCI5_9000_COMMON_ON       1
#endif
#if   ((SCI5_VERSION / 100)   == 96)
#undef  SCI5_9600_COMMON_ON
#define SCI5_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define SCI5_FUNCTION_ON          0
#define SCI5_FULL_DUPLEX_ON       0
#define SCI5_CPU_9S12_ON          0
#define SCI5_CPU_POWERPC_ON       0
#define SCI5_CPU_STM32F1_ON       0
#define SCI5_CPU_STM32F103_ON     0
#define SCI5_CPU_STM32F105_ON     0
#if    (SCI5_1000_COMMON_ON    == 1)
#undef  SCI5_CPU_9S12_ON
#define SCI5_CPU_9S12_ON          1
#endif
#if    (SCI5_4000_COMMON_ON    == 1)
#undef  SCI5_CPU_9S12_ON
#define SCI5_CPU_9S12_ON          1
#endif
#if    (SCI5_6800_COMMON_ON    == 1)
#undef  SCI5_CPU_9S12_ON
#define SCI5_CPU_9S12_ON          1
#endif
#if    (SCI5_6900_COMMON_ON    == 1)
#undef  SCI5_CPU_POWERPC_ON
#define SCI5_CPU_POWERPC_ON       1
#endif
#if    (SCI5_7600_COMMON_ON    == 1)
#undef  SCI5_CPU_STM32F1_ON
#define SCI5_CPU_STM32F1_ON       1
#endif
#if    (SCI5_7600_MAIN_CHIP_ON == 1)
#undef  SCI5_CPU_STM32F105_ON
#define SCI5_CPU_STM32F105_ON     1
#endif
#if    (SCI5_7600_AUX_CHIP_ON  == 1)
#undef  SCI5_CPU_STM32F103_ON
#define SCI5_CPU_STM32F103_ON     1
#endif
#if    (SCI5_7800_COMMON_ON    == 1)
#undef  SCI5_CPU_STM32F1_ON
#define SCI5_CPU_STM32F1_ON       1
#endif
#if    (SCI5_7800_MAIN_CHIP_ON == 1)
#undef  SCI5_CPU_STM32F105_ON
#define SCI5_CPU_STM32F105_ON     1
#endif
#if    (SCI5_7800_AUX_CHIP_ON  == 1)
#undef  SCI5_CPU_STM32F103_ON
#define SCI5_CPU_STM32F103_ON     1
#endif
#if    (SCI5_8000_COMMON_ON    == 1)
#undef  SCI5_CPU_POWERPC_ON
#define SCI5_CPU_POWERPC_ON       1
#endif
#if    (SCI5_9000_COMMON_ON    == 1)
#undef  SCI5_CPU_POWERPC_ON
#define SCI5_CPU_POWERPC_ON       1
#endif
#if    (SCI5_9600_COMMON_ON    == 1)
#undef  SCI5_CPU_POWERPC_ON
#define SCI5_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                 F105 USART5 RX And TX Pin Definition                 */
/*                   (Default: PC12 & PD2, No Remap)                    */
/* ******************************************************************** */
#define SCI5_AFIO_REMAP1        0
#define SCI5_AFIO_REMAP2        0
#define SCI5_GPO_PT_SCITX       PC12
#define SCI5_GPI_PT_SCIRX       PD2
#define SCI5_TX_PT              GPIOC
#define SCI5_TX_BT              12
#define SCI5_RX_PT              GPIOD
#define SCI5_RX_BT              2

/* ******************************************************************** */
/*                           Hardware Difference                        */
/* ******************************************************************** */
#if    (SCI5_CPU_STM32F1_ON == 1)
#define SCI5_FRQ_CLK           (INT32U)36000000     /* PCLK1 for USART5 */
#define SCI5_SCI_RX_EN()        UART5->CR1 |=  USART_CR1_RE
#define SCI5_SCI_RX_DIS()       UART5->CR1 &= ~USART_CR1_RE
#define SCI5_SCI_RX_INT_EN()    UART5->CR1 |=  USART_CR1_RXNEIE
#define SCI5_SCI_RX_INT_DIS()   UART5->CR1 &= ~USART_CR1_RXNEIE
#define SCI5_SCI_TX_EN()        UART5->CR1 |=  USART_CR1_TE
#define SCI5_SCI_TX_DIS()       UART5->CR1 &= ~USART_CR1_TE
#define SCI5_SCI_TC_INT_EN()    UART5->CR1 |=  USART_CR1_TCIE
#define SCI5_SCI_TC_INT_DIS()   UART5->CR1 &= ~USART_CR1_TCIE
#define SCI5_SCI_TX_INT_EN()    UART5->CR1 |=  USART_CR1_TXEIE
#define SCI5_SCI_TX_INT_DIS()   UART5->CR1 &= ~USART_CR1_TXEIE
#define SCI5_SCI_SR_TC_CLR()    UART5->SR  &= ~USART_SR_TC
#define SCI5_SCI_TXDMA_EN()     UART5->CR3 |=  USART_CR3_DMAT
#define SCI5_SCI_TXDMA_DIS()    UART5->CR3 &= ~USART_CR3_DMAT
#define SCI5_SCI_RXDMA_EN()     UART5->CR3 |=  USART_CR3_DMAR
#define SCI5_SCI_RXDMA_DIS()    UART5->CR3 &= ~USART_CR3_DMAR
#define SCI5_TX_DMA_CHANNEL     NULL
#define SCI5_RX_DMA_CHANNEL     NULL
#define SCI5_SCI_TX_DMA_ON      0
#define SCI5_SCI_RX_DMA_ON      0
#define SCI5_TX_DMA_TCINT_ON    0
#define SCI5_RX_DMA_TCINT_ON    0
#endif

/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define SCI5_TRUE               1
#define SCI5_FALSE              0
#define SCI5_NO_ERR             0
#define SCI5_ERR_EVENT_TYPE     1
#define SCI5_ERR_PEND_ISR       2
#define SCI5_ERR_BAD_CH         3
#define SCI5_ERR_RX_EMPTY       4
#define SCI5_ERR_TX_FULL        5
#define SCI5_ERR_TX_EMPTY       6
#define SCI5_ERR_RX_TIMEOUT     7
#define SCI5_ERR_TX_TIMEOUT     8
#define SCI5_STS_NORMAL        (INT32U)0x00000000
#define SCI5_STS_RESET         (INT32U)0x00000001
#define SCI5_STS_WARNING       (INT32U)0x00000002
#define SCI5_STS_BUS_OFF       (INT32U)0x00000004
#define SCI5_STS_SLEEPING      (INT32U)0x00000008
#define SCI5_STS_OVERRUN       (INT32U)0x00000010
#define SCI5_STS_TX_ERR        (INT32U)0x00000020
#define SCI5_STS_RX_ERR        (INT32U)0x00000040
#define SCI5_STS_GET_BIT(m)    (uiSCI5Status & (m))
#define SCI5_STS_CLR_BIT(m)     uiSCI5Status &= ~(m)
#define SCI5_STS_SET_BIT(m)     uiSCI5Status |= (m)
#define SCI5_SCI_DO_MASK       (INT08U)0xC0
#define SCI5_SCI_IS_MASK       (INT08U)0x30
#define SCI5_SCI_H4_MASK       (INT08U)0x0F
#define SCI5_SCI_DO_QUERY      (INT08U)0x40
#define SCI5_SCI_DO_MODIFY     (INT08U)0x80
#define SCI5_SCI_DO_SAVE       (INT08U)0xC0
#define SCI5_SCI_IS_PARAM      (INT08U)0x00
#define SCI5_SCI_IS_MEASU      (INT08U)0x10
#define SCI5_SCI_IS_FUNCT      (INT08U)0x20
#define SCI5_SCI_IS_CURVE      (INT08U)0x30

/* ******************************************************************** */
/*                          Control Definition                          */
/* ******************************************************************** */
#define SCI5_BAUDRATE_DEF       9600
#define SCI5_RX_BUF_SIZE        8
#define SCI5_TX_BUF_SIZE        8
#define SCI5_RX_TO_TICKS        10
#define SCI5_TX_TO_TICKS        10

/* ******************************************************************** */
/*                           Type Definition                            */
/* ******************************************************************** */
typedef struct
{   INT16U      usRingBufRxCtr;
    OS_EVENT   *pRingBufRxSem;
    INT08U     *pRingBufRxInPtr;
    INT08U     *pRingBufRxOutPtr;
    INT08U      ucRingBufRx[SCI5_RX_BUF_SIZE];
    INT16U      usRingBufTxCtr;
    OS_EVENT   *pRingBufTxSem;
    INT08U     *pRingBufTxInPtr;
    INT08U     *pRingBufTxOutPtr;
    INT08U      ucRingBufTx[SCI5_TX_BUF_SIZE];
}   SCI5_RING_STR;

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
#if (SCI5_FUNCTION_ON == 1)

SCI5_EXT INT32U uiSCI5Status;
SCI5_EXT SCI5_RING_STR sSCI5RingBuf;

#endif
/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (SCI5_FUNCTION_ON == 1)

SCI5_EXT void   SCI5Init(void);
SCI5_EXT void   SCI5Start(void);
SCI5_EXT void   SCI5TaskLoop(void);
SCI5_EXT void   SCI5TxRxIntHook(void);
SCI5_EXT void   SCI5BufInit(void);
SCI5_EXT void   SCI5PutRxChar(INT08U c);
SCI5_EXT INT08U SCI5GetTxChar(INT08U *err);
SCI5_EXT INT08U SCI5GetChar(INT16U to, INT08U *err);
SCI5_EXT INT08U SCI5PutChar(INT16U to, INT08U c);
SCI5_EXT void   SCI5HardInit(INT32U uiBaud);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */