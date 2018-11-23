/* ******************************************************************** */
/*                    MOD Bus protocol Version 1.0                      */
/*                       Header File MODBus10.h                         */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _MODBUS10_H

#define _MODBUS10_H

#ifdef   MOD_GLOBALS

#define  MOD_EXT  

#else

#define  MOD_EXT extern

#endif

/* ******************************************************************** */
/*  MOD_VERSION  = 10xx: VEC1000 Application                            */
/*  MOD_VERSION  = 40xx: VEC4000 Application                            */
/*  MOD_VERSION  = 68xx: VEC6800 Application                            */
/*  MOD_VERSION  = 69xx: VEC6900 Application                            */
/*  MOD_VERSION  = 76xx: GEC7600 Application                            */
/*  MOD_VERSION  = 78xx: GEC7800 Application                            */
/*  MOD_VERSION  = 80xx: VEC8000 Application                            */
/*  MOD_VERSION  = 90xx: VEC9000 Application                            */
/*  MOD_VERSION  = 96xx: VEC9600 Application                            */
/* ******************************************************************** */

#define MOD_VERSION          7600

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define MOD_1000_COMMON_ON      0
#define MOD_4000_COMMON_ON      0
#define MOD_6800_COMMON_ON      0
#define MOD_6900_COMMON_ON      0
#define MOD_7600_COMMON_ON      0
#define MOD_7800_COMMON_ON      0
#define MOD_8000_COMMON_ON      0
#define MOD_9000_COMMON_ON      0
#define MOD_9600_COMMON_ON      0
#if   ((MOD_VERSION / 100)  == 10)
#undef  MOD_1000_COMMON_ON
#define MOD_1000_COMMON_ON      1
#endif
#if   ((MOD_VERSION / 100)  == 40)
#undef  MOD_4000_COMMON_ON
#define MOD_4000_COMMON_ON      1
#endif
#if   ((MOD_VERSION / 100)  == 68)
#undef  MOD_6800_COMMON_ON
#define MOD_6800_COMMON_ON      1
#endif
#if   ((MOD_VERSION / 100)  == 69)
#undef  MOD_6900_COMMON_ON
#define MOD_6900_COMMON_ON      1
#endif
#if   ((MOD_VERSION / 100)  == 76)
#undef  MOD_7600_COMMON_ON
#define MOD_7600_COMMON_ON      1
#endif
#if   ((MOD_VERSION / 100)  == 78)
#undef  MOD_7800_COMMON_ON
#define MOD_7800_COMMON_ON      1
#endif
#if   ((MOD_VERSION / 100)  == 80)
#undef  MOD_8000_COMMON_ON
#define MOD_8000_COMMON_ON      1
#endif
#if   ((MOD_VERSION / 100)  == 90)
#undef  MOD_9000_COMMON_ON
#define MOD_9000_COMMON_ON      1
#endif
#if   ((MOD_VERSION / 100)  == 96)
#undef  MOD_9600_COMMON_ON
#define MOD_9600_COMMON_ON      1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define MOD_CPU_9S12_ON         0
#define MOD_CPU_POWERPC_ON      0
#define MOD_CPU_STM32F1_ON      0
#define MOD_MODBUS_V10_ON       0
#if    (MOD_1000_COMMON_ON   == 1)
#undef  MOD_CPU_9S12_ON
#define MOD_CPU_9S12_ON         1
#endif
#if    (MOD_4000_COMMON_ON   == 1)
#undef  MOD_CPU_9S12_ON
#define MOD_CPU_9S12_ON         1
#endif
#if    (MOD_6800_COMMON_ON   == 1)
#undef  MOD_CPU_9S12_ON
#define MOD_CPU_9S12_ON         1
#endif
#if    (MOD_6900_COMMON_ON   == 1)
#undef  MOD_CPU_POWERPC_ON
#define MOD_CPU_POWERPC_ON      1
#endif
#if    (MOD_7600_COMMON_ON   == 1)
#undef  MOD_CPU_STM32F1_ON
#define MOD_CPU_STM32F1_ON      1
#undef  MOD_MODBUS_V10_ON
#define MOD_MODBUS_V10_ON       1
#endif
#if    (MOD_7800_COMMON_ON   == 1)
#undef  MOD_CPU_STM32F1_ON
#define MOD_CPU_STM32F1_ON      1
#undef  MOD_MODBUS_V10_ON
#define MOD_MODBUS_V10_ON       1
#endif
#if    (MOD_8000_COMMON_ON   == 1)
#undef  MOD_CPU_POWERPC_ON
#define MOD_CPU_POWERPC_ON      1
#endif
#if    (MOD_9000_COMMON_ON   == 1)
#undef  MOD_CPU_POWERPC_ON
#define MOD_CPU_POWERPC_ON      1
#endif
#if    (MOD_9600_COMMON_ON   == 1)
#undef  MOD_CPU_POWERPC_ON
#define MOD_CPU_POWERPC_ON      1
#endif

/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define MOD_TRUE                1
#define MOD_FALSE               0
#define MOD_NO_ERR              0
#define MOD_ERR_EVENT_TYPE      1
#define MOD_ERR_PEND_ISR        2
#define MOD_ERR_BAD_CH          3
#define MOD_ERR_RX_EMPTY        4
#define MOD_ERR_TX_FULL         5
#define MOD_ERR_TX_EMPTY        6
#define MOD_ERR_RX_TIMEOUT      7
#define MOD_ERR_TX_TIMEOUT      8
#define MOD_STS_NORMAL         (INT16U)0
#define MOD_STS_RESET          (INT16U)1
#define MOD_STS_WARNING        (INT16U)2
#define MOD_STS_BUS_OFF        (INT16U)4
#define MOD_STS_SLEEPING       (INT16U)8
#define MOD_STS_OVERRUN        (INT16U)16
#define MOD_STS_ERR_TX         (INT16U)32
#define MOD_STS_ERR_RX         (INT16U)64
#define MOD_STS_ERR_ADDR       (INT16U)128
#define MOD_STS_ERR_LOGIC      (INT16U)256
#define MOD_STS_TO_1P5_ON      (INT16U)512
#define MOD_STS_GET_BIT(m)     (usMODStatus & (m))
#define MOD_STS_CLR_BIT(m)      usMODStatus &= ~(m)
#define MOD_STS_SET_BIT(m)      usMODStatus |= (m)
#define MOD_STEP_INIT          (INT08U)0
#define MOD_STEP_IDLE          (INT08U)1
#define MOD_STEP_RX_ING        (INT08U)2
#define MOD_STEP_RX_WAIT       (INT08U)3
#define MOD_STEP_TX_ING        (INT08U)4
#define MOD_CODE_READ_DINS      0x02
#define MOD_CODE_READ_DOUTS     0x01
#define MOD_CODE_WRITE_DOUT     0x05
#define MOD_CODE_WRITE_DOUTS    0x0F
#define MOD_CODE_READ_PARAMS    0x03
#define MOD_CODE_WRITE_PARAM    0x06
#define MOD_CODE_WRITE_PARAMS   0x10
#define MOD_CODE_R_W_PARAMS     0x17
#define MOD_CODE_MASK_PARAM     0x16
#define MOD_CODE_READ_MEASUS    0x04
#define MOD_CODE_WRITE_MEASU    0x43
#define MOD_CODE_WRITE_MEASUS   0x44
#define MOD_CODE_READ_FILE      0x14
#define MOD_CODE_WRITE_FILE     0x15
#define MOD_CODE_READ_DEV_ID    0x2B

/* ******************************************************************** */
/*                          Control Definition                          */
/* ******************************************************************** */
#define MOD_SCI_RX_EN()         SCI2_SCI_RX_EN()
#define MOD_SCI_RX_DIS()        SCI2_SCI_RX_DIS()
#define MOD_SCI_RX_INT_EN()     SCI2_SCI_RX_INT_EN()
#define MOD_SCI_RX_INT_DIS()    SCI2_SCI_RX_INT_DIS()
#define MOD_SCI_TX_EN()         SCI2_SCI_TX_EN()
#define MOD_SCI_TX_DIS()        SCI2_SCI_TX_DIS()
#define MOD_SCI_TC_INT_EN()     SCI2_SCI_TC_INT_EN()
#define MOD_SCI_TC_INT_DIS()    SCI2_SCI_TC_INT_DIS()
#define MOD_SCI_TX_INT_EN()     SCI2_SCI_TX_INT_EN()
#define MOD_SCI_TX_INT_DIS()    SCI2_SCI_TX_INT_DIS()
#define MOD_SCI_SR_REG          USART2->SR
#define MOD_SCI_DR_REG          USART2->DR

#define MOD_COMD_RX_RDY        (INT08U)0x5A
#define MOD_RX_BUF_SIZE         8
#define MOD_RX_TO_TICKS         10

#define MOD_UC_LOW(w)          (INT08U)(w)
#define MOD_UC_HIGH(w)         (INT08U)((w)>>8)
#define MOD_US_CREAT(h,l)      ((INT16U)(l)+((INT16U)(h)<<8))

#define MOD_RX_TO_TIME_9600    (800+1000)
#define MOD_MY_ADR_DEFAULT     (INT08U)1
#define MOD_BAUD_DEFAULT       (INT16U)9600

/* ******************************************************************** */
/*                           Type Definition                            */
/* ******************************************************************** */
typedef struct
{   INT16U      usRingBufRxCtr;
    OS_EVENT   *pRingBufRxSem;
    INT08U     *pRingBufRxInPtr;
    INT08U     *pRingBufRxOutPtr;
    INT08U      ucRingBufRx[MOD_RX_BUF_SIZE];
}   MOD_RING_STR;

typedef struct
{   INT08U      ucAddr;
    INT08U      ucLeng;
    INT08U      aData[256];
}   MOD_MSG_STR;

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
MOD_EXT INT16U usMODTimer;
MOD_EXT INT16U usMODStatus;
#if (MOD_MODBUS_V10_ON == 1)
MOD_EXT INT08U ucMODCtrlStep;
MOD_EXT INT08U ucMODRxByteCnt;
MOD_EXT INT08U ucMODTxByteCnt;
MOD_EXT INT16U usMODOverTime1P5;
MOD_EXT INT16U usMODOverTime3P5;
MOD_EXT INT16U usMODOverTime2P0;
MOD_EXT MOD_MSG_STR sMODTxRxMsg;
MOD_EXT MOD_RING_STR sMODRingBuf;
#endif

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)

MOD_EXT void   MODInit(void);
MOD_EXT void   MODStart(void);
MOD_EXT void   MODTaskLoop(void);
MOD_EXT void   MODOverTimerHook(void);
MOD_EXT void   MODTxRxIntHook(void);

MOD_EXT INT08U MODProcessRxMsg(MOD_MSG_STR *pMsg);
MOD_EXT void   MODSetupTxMsg(MOD_MSG_STR *pMsg);
MOD_EXT INT08U MODCheckMsgCrc16(MOD_MSG_STR *pMsg);
MOD_EXT INT16U MODGetCrc16Code(INT08U *pBuf, INT08U ucSize);

MOD_EXT void   MODCmdBufInit(void);
MOD_EXT INT08U MODIsRxEmpty(void);
MOD_EXT void   MODPutRxChar(INT08U c);
MOD_EXT INT08U MODGetCmdChar(INT16U to, INT08U *err);

MOD_EXT INT16U MODReadParam(INT16U usBegin);
MOD_EXT void   MODReadParams(INT08U *pDat, INT16U usBegin, INT16U usSize);
MOD_EXT void   MODWriteParam(INT16U usBegin, INT16U usValue);
MOD_EXT void   MODWriteParams(INT08U *pDat, INT16U usBegin, INT16U usSize);
MOD_EXT INT16U MODReadMeasu(INT16U usBegin);
MOD_EXT void   MODReadMeasus(INT08U *pDat, INT16U usBegin, INT16U usSize);
MOD_EXT void   MODWriteMeasu(INT16U usBegin, INT16U usValue);
MOD_EXT void   MODWriteMeasus(INT08U *pDat, INT16U usBegin, INT16U usSize);

MOD_EXT void   MODOverTimerSet(INT16U usDelay);
MOD_EXT void   MODOverTimerInit(void);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */




