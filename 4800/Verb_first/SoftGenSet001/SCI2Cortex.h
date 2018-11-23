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
/*  SCI2_VERSION  = 76xx: GEC7600 Application                           */
/*  SCI2_VERSION  = 78xx: GEC7800 Application                           */
/*  SCI2_VERSION  = 80xx: VEC8000 Application                           */
/*  SCI2_VERSION  = 90xx: VEC9000 Application                           */
/*  SCI2_VERSION  = 96xx: VEC9600 Application                           */
/* ******************************************************************** */

#define SCI2_VERSION         7600

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define SCI2_1000_COMMON_ON     0
#define SCI2_4000_COMMON_ON     0
#define SCI2_6800_COMMON_ON     0
#define SCI2_6900_COMMON_ON     0
#define SCI2_7600_COMMON_ON     0
#define SCI2_7800_COMMON_ON     0
#define SCI2_8000_COMMON_ON     0
#define SCI2_9000_COMMON_ON     0
#define SCI2_9600_COMMON_ON     0
#if   ((SCI2_VERSION / 100) == 10)
#undef  SCI2_1000_COMMON_ON
#define SCI2_1000_COMMON_ON     1
#endif
#if   ((SCI2_VERSION / 100) == 40)
#undef  SCI2_4000_COMMON_ON
#define SCI2_4000_COMMON_ON     1
#endif
#if   ((SCI2_VERSION / 100) == 68)
#undef  SCI2_6800_COMMON_ON
#define SCI2_6800_COMMON_ON     1
#endif
#if   ((SCI2_VERSION / 100) == 69)
#undef  SCI2_6900_COMMON_ON
#define SCI2_6900_COMMON_ON     1
#endif
#if   ((SCI2_VERSION / 100) == 76)
#undef  SCI2_7600_COMMON_ON
#define SCI2_7600_COMMON_ON     1
#endif
#if   ((SCI2_VERSION / 100) == 78)
#undef  SCI2_7800_COMMON_ON
#define SCI2_7800_COMMON_ON     1
#endif
#if   ((SCI2_VERSION / 100) == 80)
#undef  SCI2_8000_COMMON_ON
#define SCI2_8000_COMMON_ON     1
#endif
#if   ((SCI2_VERSION / 100) == 90)
#undef  SCI2_9000_COMMON_ON
#define SCI2_9000_COMMON_ON     1
#endif
#if   ((SCI2_VERSION / 100) == 96)
#undef  SCI2_9600_COMMON_ON
#define SCI2_9600_COMMON_ON     1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define SCI2_FUNCTION_ON        1
#define SCI2_CPU_9S12_ON        0
#define SCI2_CPU_POWERPC_ON     0
#define SCI2_CPU_STM32F1_ON     0
#if    (SCI2_1000_COMMON_ON  == 1)
#undef  SCI2_CPU_9S12_ON
#define SCI2_CPU_9S12_ON        1
#endif
#if    (SCI2_4000_COMMON_ON  == 1)
#undef  SCI2_CPU_9S12_ON
#define SCI2_CPU_9S12_ON        1
#endif
#if    (SCI2_6800_COMMON_ON  == 1)
#undef  SCI2_CPU_9S12_ON
#define SCI2_CPU_9S12_ON        1
#endif
#if    (SCI2_6900_COMMON_ON  == 1)
#undef  SCI2_CPU_POWERPC_ON
#define SCI2_CPU_POWERPC_ON     1
#endif
#if    (SCI2_7600_COMMON_ON  == 1)
#undef  SCI2_CPU_STM32F1_ON
#define SCI2_CPU_STM32F1_ON     1
#endif
#if    (SCI2_7800_COMMON_ON  == 1)
#undef  SCI2_CPU_STM32F1_ON
#define SCI2_CPU_STM32F1_ON     1
#endif
#if    (SCI2_8000_COMMON_ON  == 1)
#undef  SCI2_CPU_POWERPC_ON
#define SCI2_CPU_POWERPC_ON     1
#endif
#if    (SCI2_9000_COMMON_ON  == 1)
#undef  SCI2_CPU_POWERPC_ON
#define SCI2_CPU_POWERPC_ON     1
#endif
#if    (SCI2_9600_COMMON_ON  == 1)
#undef  SCI2_CPU_POWERPC_ON
#define SCI2_CPU_POWERPC_ON     1
#endif

/* ******************************************************************** */
/*                           Hardware Difference                        */
/* ******************************************************************** */
#if    (SCI2_CPU_9S12_ON == 1)
#define SCI2_SCI_RX_EN()        SCI0CR2_RE    = 1
#define SCI2_SCI_RX_DIS()       SCI0CR2_RE    = 0
#define SCI2_SCI_RX_INT_EN()    SCI0CR2_RIE   = 1
#define SCI2_SCI_RX_INT_DIS()   SCI0CR2_RIE   = 0
#define SCI2_SCI_TX_EN()        SCI0CR2_TE    = 1
#define SCI2_SCI_TX_DIS()       SCI0CR2_TE    = 0
#define SCI2_SCI_TC_INT_EN()    SCI0CR2_TCIE  = 1
#define SCI2_SCI_TC_INT_DIS()   SCI0CR2_TCIE  = 0
#define SCI2_SCI_TX_INT_EN()    SCI0CR2_SCTIE = 1
#define SCI2_SCI_TX_INT_DIS()   SCI0CR2_SCTIE = 0
#endif
#if    (OS_CPU_POWERPC_ON == 1)
#define SCI2_SCI_RX_EN()        ESCI_A.CR1.B.RE   = 1
#define SCI2_SCI_RX_DIS()       ESCI_A.CR1.B.RE   = 0
#define SCI2_SCI_RX_INT_EN()    ESCI_A.CR1.B.RIE  = 1
#define SCI2_SCI_RX_INT_DIS()   ESCI_A.CR1.B.RIE  = 0
#define SCI2_SCI_TX_EN()        ESCI_A.CR1.B.TE   = 1
#define SCI2_SCI_TX_DIS()       ESCI_A.CR1.B.TE   = 0
#define SCI2_SCI_TC_INT_EN()    ESCI_A.CR1.B.TCIE = 1
#define SCI2_SCI_TC_INT_DIS()   ESCI_A.CR1.B.TCIE = 0
#define SCI2_SCI_TX_INT_EN()    ESCI_A.CR1.B.TIE  = 1
#define SCI2_SCI_TX_INT_DIS()   ESCI_A.CR1.B.TIE  = 0
#endif
#if    (SCI2_CPU_STM32F1_ON == 1)
#define SCI2_FRQ_CLK           (INT32U)72000000     /* PCLK1 for USART2 */
#define SCI2_BAUD_DEFAULT       9600
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
#define SCI2_STS_NORMAL         0
#define SCI2_STS_RESET          1
#define SCI2_STS_WARNING        2
#define SCI2_STS_BUS_OFF        4
#define SCI2_STS_SLEEPING       8
#define SCI2_STS_OVERRUN        16
#define SCI2_STS_TX_ERR         32
#define SCI2_STS_RX_ERR         64
#define SCI2_STS_GET_BIT(m)    (usSCI2Status & (m))
#define SCI2_STS_CLR_BIT(m)     usSCI2Status &= ~(m)
#define SCI2_STS_SET_BIT(m)     usSCI2Status |= (m)

/* ******************************************************************** */
/*                          Control Definition                          */
/* ******************************************************************** */
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
SCI2_EXT INT16U usSCI2Timer;
SCI2_EXT INT16U usSCI2Status;

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (SCI2_FUNCTION_ON == 1)

SCI2_EXT void   SCI2Init(void);
SCI2_EXT void   SCI2Start(void);
SCI2_EXT void   SCI2TaskLoop(void);
SCI2_EXT void   SCI2TxRxIntHook(void);
SCI2_EXT void   SCI2HardInit(void);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
