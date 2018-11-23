/* ******************************************************************** */
/*                CAN1 Software for Elctronic Unit (V1.0)               */
/*                       Header File CAN1Cortex.h                       */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _CAN1CORTEX_H

#define _CAN1CORTEX_H

#ifdef   CAN1_GLOBALS

#define  CAN1_EXT  

#else

#define  CAN1_EXT extern

#endif

/* ******************************************************************** */
/*  CAN1_VERSION  = 10xx: VEC1000 Application                           */
/*  CAN1_VERSION  = 40xx: VEC4000 Application                           */
/*  CAN1_VERSION  = 68xx: VEC6800 Application                           */
/*  CAN1_VERSION  = 69xx: VEC6900 Application                           */
/*  CAN1_VERSION  = 76xx: GEC7600 Application                           */
/*  CAN1_VERSION  = 78xx: GEC7800 Application                           */
/*  CAN1_VERSION  = 80xx: VEC8000 Application                           */
/*  CAN1_VERSION  = 90xx: VEC9000 Application                           */
/*  CAN1_VERSION  = 96xx: VEC9600 Application                           */
/* ******************************************************************** */

#define CAN1_VERSION         7600

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define CAN1_1000_COMMON_ON     0
#define CAN1_4000_COMMON_ON     0
#define CAN1_6800_COMMON_ON     0
#define CAN1_6900_COMMON_ON     0
#define CAN1_7600_COMMON_ON     0
#define CAN1_7800_COMMON_ON     0
#define CAN1_8000_COMMON_ON     0
#define CAN1_9000_COMMON_ON     0
#define CAN1_9600_COMMON_ON     0
#if   ((CAN1_VERSION / 100) == 10)
#undef  CAN1_1000_COMMON_ON
#define CAN1_1000_COMMON_ON     1
#endif
#if   ((CAN1_VERSION / 100) == 40)
#undef  CAN1_4000_COMMON_ON
#define CAN1_4000_COMMON_ON     1
#endif
#if   ((CAN1_VERSION / 100) == 68)
#undef  CAN1_6800_COMMON_ON
#define CAN1_6800_COMMON_ON     1
#endif
#if   ((CAN1_VERSION / 100) == 69)
#undef  CAN1_6900_COMMON_ON
#define CAN1_6900_COMMON_ON     1
#endif
#if   ((CAN1_VERSION / 100) == 76)
#undef  CAN1_7600_COMMON_ON
#define CAN1_7600_COMMON_ON     1
#endif
#if   ((CAN1_VERSION / 100) == 78)
#undef  CAN1_7800_COMMON_ON
#define CAN1_7800_COMMON_ON     1
#endif
#if   ((CAN1_VERSION / 100) == 80)
#undef  CAN1_8000_COMMON_ON
#define CAN1_8000_COMMON_ON     1
#endif
#if   ((CAN1_VERSION / 100) == 90)
#undef  CAN1_9000_COMMON_ON
#define CAN1_9000_COMMON_ON     1
#endif
#if   ((CAN1_VERSION / 100) == 96)
#undef  CAN1_9600_COMMON_ON
#define CAN1_9600_COMMON_ON     1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define CAN1_FUNCTION_ON        0
#define CAN1_CPU_9S12_ON        0
#define CAN1_CPU_POWERPC_ON     0
#define CAN1_CPU_STM32F1_ON     0
#if    (CAN1_1000_COMMON_ON  == 1)
#undef  CAN1_CPU_9S12_ON
#define CAN1_CPU_9S12_ON        1
#endif
#if    (CAN1_4000_COMMON_ON  == 1)
#undef  CAN1_CPU_9S12_ON
#define CAN1_CPU_9S12_ON        1
#endif
#if    (CAN1_6800_COMMON_ON  == 1)
#undef  CAN1_CPU_9S12_ON
#define CAN1_CPU_9S12_ON        1
#endif
#if    (CAN1_6900_COMMON_ON  == 1)
#undef  CAN1_CPU_POWERPC_ON
#define CAN1_CPU_POWERPC_ON     1
#endif
#if    (CAN1_7600_COMMON_ON  == 1)
#undef  CAN1_CPU_STM32F1_ON
#define CAN1_CPU_STM32F1_ON     1
#undef  CAN1_FUNCTION_ON
#define CAN1_FUNCTION_ON        1
#endif
#if    (CAN1_7800_COMMON_ON  == 1)
#undef  CAN1_CPU_STM32F1_ON
#define CAN1_CPU_STM32F1_ON     1
#undef  CAN1_FUNCTION_ON
#define CAN1_FUNCTION_ON        1
#endif
#if    (CAN1_8000_COMMON_ON  == 1)
#undef  CAN1_CPU_POWERPC_ON
#define CAN1_CPU_POWERPC_ON     1
#endif
#if    (CAN1_9000_COMMON_ON  == 1)
#undef  CAN1_CPU_POWERPC_ON
#define CAN1_CPU_POWERPC_ON     1
#endif
#if    (CAN1_9600_COMMON_ON  == 1)
#undef  CAN1_CPU_POWERPC_ON
#define CAN1_CPU_POWERPC_ON     1
#endif

/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define CAN1_TRUE              (INT08U)1
#define CAN1_FALSE             (INT08U)0
#define CAN1_NO_ERR            (INT08U)0
#define CAN1_ERR_RX_FULL       (INT08U)1
#define CAN1_ERR_RX_EMPTY      (INT08U)2
#define CAN1_ERR_TX_FULL       (INT08U)3
#define CAN1_ERR_TX_EMPTY      (INT08U)4
#define CAN1_ERR_RX_TIMEOUT    (INT08U)5
#define CAN1_ERR_TX_TIMEOUT    (INT08U)6
#define CAN1_STS_NORMAL        (INT16U)0
#define CAN1_STS_RESET         (INT16U)1
#define CAN1_STS_WARNING       (INT16U)2
#define CAN1_STS_BUS_OFF       (INT16U)4
#define CAN1_STS_SLEEPING      (INT16U)8
#define CAN1_STS_OVERRUN       (INT16U)16
#define CAN1_STS_TX_ERR        (INT16U)32
#define CAN1_STS_RX_ERR        (INT16U)64
#define CAN1_STS_GET_BIT(m)    (usCAN1Status & (m))
#define CAN1_STS_CLR_BIT(m)     usCAN1Status &= ~(m)
#define CAN1_STS_SET_BIT(m)     usCAN1Status |= (m)
#define CAN1_BAUD_RATE_KHZ      250
#define CAN1_RX_BUF_SIZE        8
#define CAN1_TX_BUF_SIZE        8
#define CAN1_TASK_FRQ           200

/* ******************************************************************** */
/*                          Control Definition                          */
/* ******************************************************************** */
#if    (CAN1_CPU_9S12_ON == 1)
#define CAN1_RX_INT_EN()        CAN0RIER |= 0x01
#define CAN1_RX_INT_DIS()       CAN0RIER &= 0xFE
#define CAN1_TX0_INT_EN()       CAN0TIER |= 0x01
#define CAN1_TX1_INT_EN()       CAN0TIER |= 0x02
#define CAN1_TX2_INT_EN()       CAN0TIER |= 0x04
#define CAN1_TXALL_INT_EN()     CAN0TIER  = 0x07
#define CAN1_TX0_INT_DIS()      CAN0TIER &= 0xFE
#define CAN1_TX1_INT_DIS()      CAN0TIER &= 0xFD
#define CAN1_TX2_INT_DIS()      CAN0TIER &= 0xFB
#define CAN1_TXALL_INT_DIS()    CAN0TIER  = 0x00
#endif
#if    (CAN1_CPU_POWERPC_ON == 1)
#define CAN1_CANA_RX_BUF        0
#define CAN1_CANA_TX_BUF        1
#define CAN1_RX_INT_EN()        CAN_A.IMRL.R |=  (1 << CAN1_CANA_RX_BUF)
#define CAN1_RX_INT_DIS()       CAN_A.IMRL.R &= ~(1 << CAN1_CANA_RX_BUF)
#define CAN1_TX_INT_EN()        CAN_A.IMRL.R |=  (1 << CAN1_CANA_TX_BUF)
#define CAN1_TX_INT_DIS()       CAN_A.IMRL.R &= ~(1 << CAN1_CANA_TX_BUF)
#define CAN1_CLR_RX_FLAG()      CAN_A.IFRL.R  =  (1 << CAN1_CANA_RX_BUF)
#define CAN1_CLR_TX_FLAG()      CAN_A.IFRL.R  =  (1 << CAN1_CANA_TX_BUF)
#define CAN1_GET_RX_FLAG()     (CAN_A.IFRL.R  &  (1 << CAN1_CANA_RX_BUF))
#define CAN1_GET_TX_FLAG()     (CAN_A.IFRL.R  &  (1 << CAN1_CANA_TX_BUF))
#define CAN1_BOFF_INT_EN()      CAN_A.CR.B.BOFFMSK  = 1
#define CAN1_BOFF_INT_DIS()     CAN_A.CR.B.BOFFMSK  = 0
#define CAN1_CLR_BOFF_FLAG()    CAN_A.ESR.B.BOFFINT = 1
#define CAN1_ERR_INT_EN()       CAN_A.CR.B.ERRMSK   = 1
#define CAN1_ERR_INT_DIS()      CAN_A.CR.B.ERRMSK   = 0
#define CAN1_CLR_ERR_FLAG()     CAN_A.ESR.B.ERRINT  = 1
#endif
#if    (CAN1_CPU_STM32F1_ON == 1)
#define CAN1_TC_INT_EN()        CAN1->IER |=   CAN_IER_TMEIE
#define CAN1_TC_INT_DIS()       CAN1->IER &=  ~CAN_IER_TMEIE
#define CAN1_RX_INT_EN()        CAN1->IER |=  (CAN_IER_FMPIE0 | CAN_IER_FMPIE1)
#define CAN1_RX_INT_DIS()       CAN1->IER |= ~(CAN_IER_FMPIE0 | CAN_IER_FMPIE1)
#define CAN1_CPU_ID_MSK        (INT32U)0xFFFFFFFC
#endif

/* ******************************************************************** */
/*                           Type Definition                            */
/* ******************************************************************** */
typedef struct
{   INT16U     usRingBufRxCtr;
    OS_EVENT   *pRingBufRxSem;
    CAN_MSG    *pRingBufRxInPtr;
    CAN_MSG    *pRingBufRxOutPtr;
    CAN_MSG    sRingBufRx[CAN1_RX_BUF_SIZE];
    INT16U     usRingBufTxCtr;
    OS_EVENT   *pRingBufTxSem;
    CAN_MSG    *pRingBufTxInPtr;
    CAN_MSG    *pRingBufTxOutPtr;
    CAN_MSG    sRingBufTx[CAN1_TX_BUF_SIZE];
}   CAN1_RING;

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
CAN1_EXT INT16U usCAN1Timer;
CAN1_EXT INT16U usCAN1Status;
#if (CAN1_FUNCTION_ON == 1)
CAN1_EXT CAN_MSG sCAN1TaskRxMsg;
CAN1_EXT CAN_MSG sCAN1TaskTxMsg;
CAN1_EXT CAN_MSG sCAN1IntrRxMsg;
CAN1_EXT CAN_MSG sCAN1IntrTxMsg;
CAN1_EXT CAN1_RING sCAN1RingBuf;
#endif

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (CAN1_FUNCTION_ON == 1)

CAN1_EXT void   CAN1Init(void);
CAN1_EXT void   CAN1Start(void);
CAN1_EXT void   CAN1TaskLoop(void);
CAN1_EXT void   CAN1TxIntHook(void);
CAN1_EXT void   CAN1Rx0IntHook(void);
CAN1_EXT void   CAN1Rx1IntHook(void);
CAN1_EXT void   CAN1SceIntHook(void);
CAN1_EXT void   CAN1BufInit(void);
CAN1_EXT INT08U CAN1IsTxBufFull(void);
CAN1_EXT INT08U CAN1IsRxBufEmpty(void);
CAN1_EXT void   CAN1PutRxMsgToBuf(CAN_MSG *msg);
CAN1_EXT INT08U CAN1GetTxMsgFmBuf(CAN_MSG *msg);
CAN1_EXT INT08U CAN1GetMsgFmRxBuf(INT16U to, CAN_MSG *msg);
CAN1_EXT INT08U CAN1PutMsgToTxBuf(INT16U to, CAN_MSG *msg);
CAN1_EXT void   CAN1HardInit(void);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */