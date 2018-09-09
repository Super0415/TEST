/* ******************************************************************** */
/*                CAN2 Software for Elctronic Unit (V1.0)               */
/*                       Header File CAN2Cortex.h                       */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _CAN2CORTEX_H

#define _CAN2CORTEX_H

#ifdef   CAN2_GLOBALS

#define  CAN2_EXT  

#else

#define  CAN2_EXT extern

#endif

/* ******************************************************************** */
/*  CAN2_VERSION  = 10xx: VEC1000 Application                           */
/*  CAN2_VERSION  = 40xx: VEC4000 Application                           */
/*  CAN2_VERSION  = 68xx: VEC6800 Application                           */
/*  CAN2_VERSION  = 69xx: VEC6900 Application                           */
/*  CAN2_VERSION  = 76xx: GEC7600 Application                           */
/*  CAN2_VERSION  = 78xx: GEC7800 Application                           */
/*  CAN2_VERSION  = 80xx: VEC8000 Application                           */
/*  CAN2_VERSION  = 90xx: VEC9000 Application                           */
/*  CAN2_VERSION  = 96xx: VEC9600 Application                           */
/* ******************************************************************** */

#define CAN2_VERSION         7600

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define CAN2_1000_COMMON_ON     0
#define CAN2_4000_COMMON_ON     0
#define CAN2_6800_COMMON_ON     0
#define CAN2_6900_COMMON_ON     0
#define CAN2_7600_COMMON_ON     0
#define CAN2_7800_COMMON_ON     0
#define CAN2_8000_COMMON_ON     0
#define CAN2_9000_COMMON_ON     0
#define CAN2_9600_COMMON_ON     0
#if   ((CAN2_VERSION / 100) == 10)
#undef  CAN2_1000_COMMON_ON
#define CAN2_1000_COMMON_ON     1
#endif
#if   ((CAN2_VERSION / 100) == 40)
#undef  CAN2_4000_COMMON_ON
#define CAN2_4000_COMMON_ON     1
#endif
#if   ((CAN2_VERSION / 100) == 68)
#undef  CAN2_6800_COMMON_ON
#define CAN2_6800_COMMON_ON     1
#endif
#if   ((CAN2_VERSION / 100) == 69)
#undef  CAN2_6900_COMMON_ON
#define CAN2_6900_COMMON_ON     1
#endif
#if   ((CAN2_VERSION / 100) == 76)
#undef  CAN2_7600_COMMON_ON
#define CAN2_7600_COMMON_ON     1
#endif
#if   ((CAN2_VERSION / 100) == 78)
#undef  CAN2_7800_COMMON_ON
#define CAN2_7800_COMMON_ON     1
#endif
#if   ((CAN2_VERSION / 100) == 80)
#undef  CAN2_8000_COMMON_ON
#define CAN2_8000_COMMON_ON     1
#endif
#if   ((CAN2_VERSION / 100) == 90)
#undef  CAN2_9000_COMMON_ON
#define CAN2_9000_COMMON_ON     1
#endif
#if   ((CAN2_VERSION / 100) == 96)
#undef  CAN2_9600_COMMON_ON
#define CAN2_9600_COMMON_ON     1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define CAN2_FUNCTION_ON        0
#define CAN2_CPU_9S12_ON        0
#define CAN2_CPU_POWERPC_ON     0
#define CAN2_CPU_STM32F1_ON     0
#if    (CAN2_1000_COMMON_ON  == 1)
#undef  CAN2_CPU_9S12_ON
#define CAN2_CPU_9S12_ON        1
#endif
#if    (CAN2_4000_COMMON_ON  == 1)
#undef  CAN2_CPU_9S12_ON
#define CAN2_CPU_9S12_ON        1
#endif
#if    (CAN2_6800_COMMON_ON  == 1)
#undef  CAN2_CPU_9S12_ON
#define CAN2_CPU_9S12_ON        1
#endif
#if    (CAN2_6900_COMMON_ON  == 1)
#undef  CAN2_CPU_POWERPC_ON
#define CAN2_CPU_POWERPC_ON     1
#endif
#if    (CAN2_7600_COMMON_ON  == 1)
#undef  CAN2_CPU_STM32F1_ON
#define CAN2_CPU_STM32F1_ON     1
#undef  CAN2_FUNCTION_ON
#define CAN2_FUNCTION_ON        1
#endif
#if    (CAN2_7800_COMMON_ON  == 1)
#undef  CAN2_CPU_STM32F1_ON
#define CAN2_CPU_STM32F1_ON     1
#undef  CAN2_FUNCTION_ON
#define CAN2_FUNCTION_ON        1
#endif
#if    (CAN2_8000_COMMON_ON  == 1)
#undef  CAN2_CPU_POWERPC_ON
#define CAN2_CPU_POWERPC_ON     1
#endif
#if    (CAN2_9000_COMMON_ON  == 1)
#undef  CAN2_CPU_POWERPC_ON
#define CAN2_CPU_POWERPC_ON     1
#endif
#if    (CAN2_9600_COMMON_ON  == 1)
#undef  CAN2_CPU_POWERPC_ON
#define CAN2_CPU_POWERPC_ON     1
#endif

/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define CAN2_TRUE              (INT08U)1
#define CAN2_FALSE             (INT08U)0
#define CAN2_NO_ERR            (INT08U)0
#define CAN2_ERR_RX_FULL       (INT08U)1
#define CAN2_ERR_RX_EMPTY      (INT08U)2
#define CAN2_ERR_TX_FULL       (INT08U)3
#define CAN2_ERR_TX_EMPTY      (INT08U)4
#define CAN2_ERR_RX_TIMEOUT    (INT08U)5
#define CAN2_ERR_TX_TIMEOUT    (INT08U)6
#define CAN2_STS_NORMAL        (INT16U)0
#define CAN2_STS_RESET         (INT16U)1
#define CAN2_STS_WARNING       (INT16U)2
#define CAN2_STS_BUS_OFF       (INT16U)4
#define CAN2_STS_SLEEPING      (INT16U)8
#define CAN2_STS_OVERRUN       (INT16U)16
#define CAN2_STS_TX_ERR        (INT16U)32
#define CAN2_STS_RX_ERR        (INT16U)64
#define CAN2_STS_GET_BIT(m)    (usCAN2Status & (m))
#define CAN2_STS_CLR_BIT(m)     usCAN2Status &= ~(m)
#define CAN2_STS_SET_BIT(m)     usCAN2Status |= (m)
#define CAN2_BAUD_RATE         (INT32U)250000
#define CAN2_RX_BUF_SIZE        8
#define CAN2_TX_BUF_SIZE        8
#define CAN2_TASK_FRQ           200

/* ******************************************************************** */
/*                          Control Definition                          */
/* ******************************************************************** */
#if    (CAN2_CPU_9S12_ON == 1)
#define CAN2_RX_INT_EN()        CAN1RIER |= 0x01
#define CAN2_RX_INT_DIS()       CAN1RIER &= 0xFE
#define CAN2_TX0_INT_EN()       CAN1TIER |= 0x01
#define CAN2_TX1_INT_EN()       CAN1TIER |= 0x02
#define CAN2_TX2_INT_EN()       CAN1TIER |= 0x04
#define CAN2_TXALL_INT_EN()     CAN1TIER  = 0x07
#define CAN2_TX0_INT_DIS()      CAN1TIER &= 0xFE
#define CAN2_TX1_INT_DIS()      CAN1TIER &= 0xFD
#define CAN2_TX2_INT_DIS()      CAN1TIER &= 0xFB
#define CAN2_TXALL_INT_DIS()    CAN1TIER  = 0x00
#endif
#if    (CAN2_CPU_POWERPC_ON == 1)
#define CAN2_CANA_RX_BUF        0
#define CAN2_CANA_TX_BUF        1
#define CAN2_RX_INT_EN()        CAN_B.IMRL.R |=  (1 << CAN2_CANA_RX_BUF)
#define CAN2_RX_INT_DIS()       CAN_B.IMRL.R &= ~(1 << CAN2_CANA_RX_BUF)
#define CAN2_TX_INT_EN()        CAN_B.IMRL.R |=  (1 << CAN2_CANA_TX_BUF)
#define CAN2_TX_INT_DIS()       CAN_B.IMRL.R &= ~(1 << CAN2_CANA_TX_BUF)
#define CAN2_CLR_RX_FLAG()      CAN_B.IFRL.R  =  (1 << CAN2_CANA_RX_BUF)
#define CAN2_CLR_TX_FLAG()      CAN_B.IFRL.R  =  (1 << CAN2_CANA_TX_BUF)
#define CAN2_GET_RX_FLAG()     (CAN_B.IFRL.R  &  (1 << CAN2_CANA_RX_BUF))
#define CAN2_GET_TX_FLAG()     (CAN_B.IFRL.R  &  (1 << CAN2_CANA_TX_BUF))
#define CAN2_BOFF_INT_EN()      CAN_B.CR.B.BOFFMSK  = 1
#define CAN2_BOFF_INT_DIS()     CAN_B.CR.B.BOFFMSK  = 0
#define CAN2_CLR_BOFF_FLAG()    CAN_B.ESR.B.BOFFINT = 1
#define CAN2_ERR_INT_EN()       CAN_B.CR.B.ERRMSK   = 1
#define CAN2_ERR_INT_DIS()      CAN_B.CR.B.ERRMSK   = 0
#define CAN2_CLR_ERR_FLAG()     CAN_B.ESR.B.ERRINT  = 1
#endif
#if    (CAN2_CPU_STM32F1_ON == 1)
#define CAN2_TC_INT_EN()        CAN2->IER |=   CAN_IER_TMEIE
#define CAN2_TC_INT_DIS()       CAN2->IER &=  ~CAN_IER_TMEIE
#define CAN2_RX_INT_EN()        CAN2->IER |=  (CAN_IER_FMPIE0 | CAN_IER_FMPIE1)
#define CAN2_RX_INT_DIS()       CAN2->IER |= ~(CAN_IER_FMPIE0 | CAN_IER_FMPIE1)
#define CAN2_CPU_ID_MSK        (INT32U)0xFFFFFFFC
#endif

/* ******************************************************************** */
/*                           Type Definition                            */
/* ******************************************************************** */
typedef struct
{   INT16U     usRingBufRxCtr;
    OS_EVENT   *pRingBufRxSem;
    CAN_MSG    *pRingBufRxInPtr;
    CAN_MSG    *pRingBufRxOutPtr;
    CAN_MSG    sRingBufRx[CAN2_RX_BUF_SIZE];
    INT16U     usRingBufTxCtr;
    OS_EVENT   *pRingBufTxSem;
    CAN_MSG    *pRingBufTxInPtr;
    CAN_MSG    *pRingBufTxOutPtr;
    CAN_MSG    sRingBufTx[CAN2_TX_BUF_SIZE];
}   CAN2_RING;

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
CAN2_EXT INT16U usCAN2Timer;
CAN2_EXT INT16U usCAN2Status;
#if (CAN2_FUNCTION_ON == 1)
CAN2_EXT CAN_MSG sCAN2TaskRxMsg;
CAN2_EXT CAN_MSG sCAN2TaskTxMsg;
CAN2_EXT CAN_MSG sCAN2IntrRxMsg;
CAN2_EXT CAN_MSG sCAN2IntrTxMsg;
CAN2_EXT CAN2_RING sCAN2RingBuf;
#endif

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)

CAN2_EXT void   CAN2Init(void);
CAN2_EXT void   CAN2Start(void);
CAN2_EXT void   CAN2TaskLoop(void);
CAN2_EXT void   CAN2TxIntHook(void);
CAN2_EXT void   CAN2Rx0IntHook(void);
CAN2_EXT void   CAN2Rx1IntHook(void);
CAN2_EXT void   CAN2SceIntHook(void);
CAN2_EXT void   CAN2BufInit(void);
CAN2_EXT INT08U CAN2IsTxBufFull(void);
CAN2_EXT INT08U CAN2IsRxBufEmpty(void);
CAN2_EXT void   CAN2PutRxMsgToBuf(CAN_MSG *msg);
CAN2_EXT INT08U CAN2GetTxMsgFmBuf(CAN_MSG *msg);
CAN2_EXT INT08U CAN2GetMsgFmRxBuf(INT16U to, CAN_MSG *msg);
CAN2_EXT INT08U CAN2PutMsgToTxBuf(INT16U to, CAN_MSG *msg);
CAN2_EXT void   CAN2HardInit(void);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */