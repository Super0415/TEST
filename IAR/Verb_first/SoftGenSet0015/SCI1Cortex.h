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
/*  SCI1_VERSION  = 76xx: GEC7600 Application                           */
/*  SCI1_VERSION  = 78xx: GEC7800 Application                           */
/*  SCI1_VERSION  = 80xx: VEC8000 Application                           */
/*  SCI1_VERSION  = 90xx: VEC9000 Application                           */
/*  SCI1_VERSION  = 96xx: VEC9600 Application                           */
/* ******************************************************************** */

#define SCI1_VERSION         7600

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define SCI1_1000_COMMON_ON     0
#define SCI1_4000_COMMON_ON     0
#define SCI1_6800_COMMON_ON     0
#define SCI1_6900_COMMON_ON     0
#define SCI1_7600_COMMON_ON     0
#define SCI1_7800_COMMON_ON     0
#define SCI1_8000_COMMON_ON     0
#define SCI1_9000_COMMON_ON     0
#define SCI1_9600_COMMON_ON     0
#if   ((SCI1_VERSION / 100) == 10)
#undef  SCI1_1000_COMMON_ON
#define SCI1_1000_COMMON_ON     1
#endif
#if   ((SCI1_VERSION / 100) == 40)
#undef  SCI1_4000_COMMON_ON
#define SCI1_4000_COMMON_ON     1
#endif
#if   ((SCI1_VERSION / 100) == 68)
#undef  SCI1_6800_COMMON_ON
#define SCI1_6800_COMMON_ON     1
#endif
#if   ((SCI1_VERSION / 100) == 69)
#undef  SCI1_6900_COMMON_ON
#define SCI1_6900_COMMON_ON     1
#endif
#if   ((SCI1_VERSION / 100) == 76)
#undef  SCI1_7600_COMMON_ON
#define SCI1_7600_COMMON_ON     1
#endif
#if   ((SCI1_VERSION / 100) == 78)
#undef  SCI1_7800_COMMON_ON
#define SCI1_7800_COMMON_ON     1
#endif
#if   ((SCI1_VERSION / 100) == 80)
#undef  SCI1_8000_COMMON_ON
#define SCI1_8000_COMMON_ON     1
#endif
#if   ((SCI1_VERSION / 100) == 90)
#undef  SCI1_9000_COMMON_ON
#define SCI1_9000_COMMON_ON     1
#endif
#if   ((SCI1_VERSION / 100) == 96)
#undef  SCI1_9600_COMMON_ON
#define SCI1_9600_COMMON_ON     1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define SCI1_FUNCTION_ON        1
#define SCI1_CPU_9S12_ON        0
#define SCI1_CPU_POWERPC_ON     0
#define SCI1_CPU_STM32F1_ON     0
#if    (SCI1_1000_COMMON_ON  == 1)
#undef  SCI1_CPU_9S12_ON
#define SCI1_CPU_9S12_ON        1
#endif
#if    (SCI1_4000_COMMON_ON  == 1)
#undef  SCI1_CPU_9S12_ON
#define SCI1_CPU_9S12_ON        1
#endif
#if    (SCI1_6800_COMMON_ON  == 1)
#undef  SCI1_CPU_9S12_ON
#define SCI1_CPU_9S12_ON        1
#endif
#if    (SCI1_6900_COMMON_ON  == 1)
#undef  SCI1_CPU_POWERPC_ON
#define SCI1_CPU_POWERPC_ON     1
#endif
#if    (SCI1_7600_COMMON_ON  == 1)
#undef  SCI1_CPU_STM32F1_ON
#define SCI1_CPU_STM32F1_ON     1
#endif
#if    (SCI1_7800_COMMON_ON  == 1)
#undef  SCI1_CPU_STM32F1_ON
#define SCI1_CPU_STM32F1_ON     1
#endif
#if    (SCI1_8000_COMMON_ON  == 1)
#undef  SCI1_CPU_POWERPC_ON
#define SCI1_CPU_POWERPC_ON     1
#endif
#if    (SCI1_9000_COMMON_ON  == 1)
#undef  SCI1_CPU_POWERPC_ON
#define SCI1_CPU_POWERPC_ON     1
#endif
#if    (SCI1_9600_COMMON_ON  == 1)
#undef  SCI1_CPU_POWERPC_ON
#define SCI1_CPU_POWERPC_ON     1
#endif

/* ******************************************************************** */
/*                           Hardware Difference                        */
/* ******************************************************************** */
#if    (SCI1_CPU_9S12_ON == 1)
#define SCI1_SCI_RX_EN()        SCI0CR2_RE    = 1
#define SCI1_SCI_RX_DIS()       SCI0CR2_RE    = 0
#define SCI1_SCI_RX_INT_EN()    SCI0CR2_RIE   = 1
#define SCI1_SCI_RX_INT_DIS()   SCI0CR2_RIE   = 0
#define SCI1_SCI_TX_EN()        SCI0CR2_TE    = 1
#define SCI1_SCI_TX_DIS()       SCI0CR2_TE    = 0
#define SCI1_SCI_TC_INT_EN()    SCI0CR2_TCIE  = 1
#define SCI1_SCI_TC_INT_DIS()   SCI0CR2_TCIE  = 0
#define SCI1_SCI_TX_INT_EN()    SCI0CR2_SCTIE = 1
#define SCI1_SCI_TX_INT_DIS()   SCI0CR2_SCTIE = 0
#endif
#if    (OS_CPU_POWERPC_ON == 1)
#define SCI1_SCI_RX_EN()        ESCI_A.CR1.B.RE   = 1
#define SCI1_SCI_RX_DIS()       ESCI_A.CR1.B.RE   = 0
#define SCI1_SCI_RX_INT_EN()    ESCI_A.CR1.B.RIE  = 1
#define SCI1_SCI_RX_INT_DIS()   ESCI_A.CR1.B.RIE  = 0
#define SCI1_SCI_TX_EN()        ESCI_A.CR1.B.TE   = 1
#define SCI1_SCI_TX_DIS()       ESCI_A.CR1.B.TE   = 0
#define SCI1_SCI_TC_INT_EN()    ESCI_A.CR1.B.TCIE = 1
#define SCI1_SCI_TC_INT_DIS()   ESCI_A.CR1.B.TCIE = 0
#define SCI1_SCI_TX_INT_EN()    ESCI_A.CR1.B.TIE  = 1
#define SCI1_SCI_TX_INT_DIS()   ESCI_A.CR1.B.TIE  = 0
#endif
#if    (SCI1_CPU_STM32F1_ON == 1)
#define SCI1_FRQ_CLK           (INT32U)72000000     /* PCLK2 for USART1 */
#define SCI1_BAUD_DEFAULT       9600
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
#define SCI1_STS_NORMAL         0
#define SCI1_STS_RESET          1
#define SCI1_STS_WARNING        2
#define SCI1_STS_BUS_OFF        4
#define SCI1_STS_SLEEPING       8
#define SCI1_STS_OVERRUN        16
#define SCI1_STS_TX_ERR         32
#define SCI1_STS_RX_ERR         64
#define SCI1_STS_GET_BIT(m)    (usSCI1Status & (m))
#define SCI1_STS_CLR_BIT(m)     usSCI1Status &= ~(m)
#define SCI1_STS_SET_BIT(m)     usSCI1Status |= (m)

#define SCI1_SCI_DO_MASK       (INT08U)0xC0
#define SCI1_SCI_IS_MASK       (INT08U)0x30
#define SCI1_SCI_H4_MASK       (INT08U)0x0F
#define SCI1_SCI_DO_QUERY      (INT08U)0x40
#define SCI1_SCI_DO_MODIFY     (INT08U)0x80
#define SCI1_SCI_DO_SAVE       (INT08U)0xC0
#define SCI1_SCI_IS_PARAM      (INT08U)0x00
#define SCI1_SCI_IS_MEASU      (INT08U)0x10
#define SCI1_SCI_IS_FUNCT      (INT08U)0x20
#define SCI1_SCI_IS_CURVE      (INT08U)0x30

/* ******************************************************************** */
/*                          Control Definition                          */
/* ******************************************************************** */
#define SCI1_RX_BUF_SIZE        8
#define SCI1_TX_BUF_SIZE        8
#define SCI1_RX_TO_TICKS        10
#define SCI1_TX_TO_TICKS        10

/* ******************************************************************** */
/*                           Type Definition                            */
/* ******************************************************************** */
typedef struct
{   INT16U      usRingBufRxCtr;
    OS_EVENT   *pRingBufRxSem;
    INT08U     *pRingBufRxInPtr;
    INT08U     *pRingBufRxOutPtr;
    INT08U      ucRingBufRx[SCI1_RX_BUF_SIZE];
    INT16U      usRingBufTxCtr;
    OS_EVENT   *pRingBufTxSem;
    INT08U     *pRingBufTxInPtr;
    INT08U     *pRingBufTxOutPtr;
    INT08U      ucRingBufTx[SCI1_TX_BUF_SIZE];
}   SCI1_RING_STR;

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
SCI1_EXT INT16U usSCI1Timer;
SCI1_EXT INT16U usSCI1Status;
#if (SCI1_FUNCTION_ON == 1)
SCI1_EXT INT08U aSCI1TxDmaBuf[16];
SCI1_EXT SCI1_RING_STR sSCI1RingBuf;
#endif

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)

SCI1_EXT void   SCI1Init(void);
SCI1_EXT void   SCI1Start(void);
SCI1_EXT void   SCI1TaskLoop(void);
SCI1_EXT void   SCI1TxRxIntHook(void);
SCI1_EXT INT08U SCI1CheckTime(INT16U usOld, INT16U usPer);
SCI1_EXT void   SCI1BufInit(void);
SCI1_EXT INT08U SCI1IsTxFull(void);
SCI1_EXT INT08U SCI1IsRxEmpty(void);
SCI1_EXT void   SCI1PutRxChar(INT08U c);
SCI1_EXT INT08U SCI1GetTxChar(INT08U *err);
SCI1_EXT INT08U SCI1GetChar(INT16U to, INT08U *err);
SCI1_EXT INT08U SCI1PutChar(INT16U to, INT08U c);
SCI1_EXT void   SCI1HardInit(void);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
