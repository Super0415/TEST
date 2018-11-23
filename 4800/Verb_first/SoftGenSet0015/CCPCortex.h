/* ******************************************************************** */
/*                      CCP protocol Version 1.0                        */
/*                       Header File CCPCortex.h                        */
/*                              2016-1-14                               */
/* ******************************************************************** */

#ifndef _CCPCORTEX_H

#define _CCPCORTEX_H

#ifdef   CCP_GLOBALS

#define  CCP_EXT  

#else

#define  CCP_EXT extern

#endif

/* ******************************************************************** */
/*  CCP_VERSION  = 10xx: VEC1000 Application                            */
/*  CCP_VERSION  = 40xx: VEC4000 Application                            */
/*  CCP_VERSION  = 68xx: VEC6800 Application                            */
/*  CCP_VERSION  = 69xx: VEC6900 Application                            */
/*  CCP_VERSION  = 76xx: GEC7600 Application                            */
/*  CCP_VERSION  = 78xx: GEC7800 Application                            */
/*  CCP_VERSION  = 80xx: VEC8000 Application                            */
/*  CCP_VERSION  = 90xx: VEC9000 Application                            */
/*  CCP_VERSION  = 96xx: VEC9600 Application                            */
/* ******************************************************************** */

#define CCP_VERSION          7600

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define CCP_1000_COMMON_ON      0
#define CCP_4000_COMMON_ON      0
#define CCP_6800_COMMON_ON      0
#define CCP_6900_COMMON_ON      0
#define CCP_7600_COMMON_ON      0
#define CCP_7800_COMMON_ON      0
#define CCP_8000_COMMON_ON      0
#define CCP_9000_COMMON_ON      0
#define CCP_9600_COMMON_ON      0
#if   ((CCP_VERSION / 100)  == 10)
#undef  CCP_1000_COMMON_ON
#define CCP_1000_COMMON_ON      1
#endif
#if   ((CCP_VERSION / 100)  == 40)
#undef  CCP_4000_COMMON_ON
#define CCP_4000_COMMON_ON      1
#endif
#if   ((CCP_VERSION / 100)  == 68)
#undef  CCP_6800_COMMON_ON
#define CCP_6800_COMMON_ON      1
#endif
#if   ((CCP_VERSION / 100)  == 69)
#undef  CCP_6900_COMMON_ON
#define CCP_6900_COMMON_ON      1
#endif
#if   ((CCP_VERSION / 100)  == 76)
#undef  CCP_7600_COMMON_ON
#define CCP_7600_COMMON_ON      1
#endif
#if   ((CCP_VERSION / 100)  == 78)
#undef  CCP_7800_COMMON_ON
#define CCP_7800_COMMON_ON      1
#endif
#if   ((CCP_VERSION / 100)  == 80)
#undef  CCP_8000_COMMON_ON
#define CCP_8000_COMMON_ON      1
#endif
#if   ((CCP_VERSION / 100)  == 90)
#undef  CCP_9000_COMMON_ON
#define CCP_9000_COMMON_ON      1
#endif
#if   ((CCP_VERSION / 100)  == 96)
#undef  CCP_9600_COMMON_ON
#define CCP_9600_COMMON_ON      1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define CCP_CPU_9S12_ON         0
#define CCP_CPU_POWERPC_ON      0
#define CCP_CPU_STM32F1_ON      0
#define CCP_MY_ADDRESS          0
#define CCP_CCP_CCP10_ON        1
#define CCP_CCP_CCP21_ON        0
#if    (CCP_1000_COMMON_ON   == 1)
#undef  CCP_CPU_9S12_ON
#define CCP_CPU_9S12_ON         1
#endif
#if    (CCP_4000_COMMON_ON   == 1)
#undef  CCP_CPU_9S12_ON
#define CCP_CPU_9S12_ON         1
#endif
#if    (CCP_6800_COMMON_ON   == 1)
#undef  CCP_CPU_9S12_ON
#define CCP_CPU_9S12_ON         1
#endif
#if    (CCP_6900_COMMON_ON   == 1)
#undef  CCP_CPU_POWERPC_ON
#define CCP_CPU_POWERPC_ON      1
#endif
#if    (CCP_7600_COMMON_ON   == 1)
#undef  CCP_CPU_STM32F1_ON
#define CCP_CPU_STM32F1_ON      1
#endif
#if    (CCP_7800_COMMON_ON   == 1)
#undef  CCP_CPU_STM32F1_ON
#define CCP_CPU_STM32F1_ON      1
#endif
#if    (CCP_8000_COMMON_ON   == 1)
#undef  CCP_CPU_POWERPC_ON
#define CCP_CPU_POWERPC_ON      1
#endif
#if    (CCP_9000_COMMON_ON   == 1)
#undef  CCP_CPU_POWERPC_ON
#define CCP_CPU_POWERPC_ON      1
#endif
#if    (CCP_9600_COMMON_ON   == 1)
#undef  CCP_CPU_POWERPC_ON
#define CCP_CPU_POWERPC_ON      1
#endif

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */

#if    (CCP_1000_COMMON_ON   == 1)
#if   ((CCP_VERSION % 10)    == 0)
#define CCP_1000_GENERNAL_ON    1
#elif ((CCP_VERSION % 10)    == 1)
#define CCP_1000_TBS_ON         1
#elif ((CCP_VERSION % 10)    == 2)
#define CCP_1000_TONG_JIE_ON    1
#elif ((CCP_VERSION % 10)    == 3)
#define CCP_1000_ECU_TESTER_ON  1
#elif ((CCP_VERSION % 10)    == 4)
#define CCP_1000_PRES_MONIT_ON  1
#elif ((CCP_VERSION % 10)    == 5)
#define CCP_1000_TWO_FUEL_ON    1
#endif
#endif

#if    (CCP_6800_COMMON_ON   == 1)
#if   ((CCP_VERSION % 10)    == 0)
#define CCP_6800_GENERNAL_ON    1
#elif ((CCP_VERSION % 10)    == 1)
#define CCP_6800_TBS_ON         1
#elif ((CCP_VERSION % 10)    == 2)
#define CCP_6800_SHAN_TUI_ON    1
#elif ((CCP_VERSION % 10)    == 3)
#define CCP_6800_ANA_CAL_ON     1
#elif ((CCP_VERSION % 10)    == 4)
#define CCP_6800_WATER_PUMP_ON  1
#elif ((CCP_VERSION % 10)    == 5)
#define CCP_6800_HUA_WEI_ON     1
#elif ((CCP_VERSION % 10)    == 6)
#define CCP_6800_TONG_JIE_ON    1
#elif ((CCP_VERSION % 10)    == 7)
#define CCP_6800_TONG_CHAI_ON   1
#elif ((CCP_VERSION % 10)    == 8)
#define CCP_6800_TWO_FUEL_ON    1
#endif
#endif

#if    (CCP_8000_COMMON_ON   == 1)
#if   ((CCP_VERSION % 10)    == 0)
#define CCP_8000_GENERNAL_ON    1
#elif ((CCP_VERSION % 10)    == 1)
#define CCP_8000_TWO_FUEL_ON    1
#endif
#endif

#if    (CCP_9000_COMMON_ON   == 1)
#if   ((CCP_VERSION % 10)    == 0)
#define CCP_9000_GENERNAL_ON    1
#endif
#endif

#if    (CCP_9600_COMMON_ON   == 1)
#if   ((CCP_VERSION % 10)    == 0)
#define CCP_9600_GENERNAL_ON    1
#endif
#endif

/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define CCP_FALSE               0x00
#define CCP_TRUE                0x01
#define CCP_ENABLE              0x01
#define CCP_DISABLE             0x00
#define CCP_NO_ERR              0x00
#define CCP_ERR_ADDR            0x01
#define CCP_ERR_FCODE           0x02
#define CCP_ERR_LENGTH          0x03
#define CCP_ERR_CRC16           0x04
#define CCP_ERR_TAB_FULL        0x05
#define CCP_ERR_CMD_BUSY        0x10
#define CCP_ERR_DAQ_BUSY        0x11
#define CCP_ERR_KEY_REQ         0x18
#define CCP_ERR_STATUS_REQ      0x19
#define CCP_ERR_COLD_START_REQ  0x20
#define CCP_ERR_CAL_INIT_REQ    0x21
#define CCP_ERR_DAQ_INIT_REQ    0x22
#define CCP_ERR_CODE_REQ        0x23
#define CCP_ERR_CMD_UNKNOWN     0x30
#define CCP_ERR_CMD_SYNTAX      0x31
#define CCP_ERR_OUT_OF_RANGE    0x32
#define CCP_ERR_ACCESS_DENIED   0x33
#define CCP_ERR_OVERLOAD        0x34
#define CCP_ERR_ACCESS_LOCKED   0x35
#define CCP_CMD_CONNECT         0x01
#define CCP_CMD_GET_VERSION     0x1B
#define CCP_CMD_EXCHANG_ID      0x17
#define CCP_CMD_SET_MTA         0x02
#define CCP_CMD_DNLOAD          0x03
#define CCP_CMD_UPLOAD          0x04
#define CCP_CMD_GET_DAQ_SIZE    0x14
#define CCP_CMD_SET_DAQ_PTR     0x15
#define CCP_CMD_WRITE_DAQ       0x16
#define CCP_CMD_START_STOP      0x06
#define CCP_CMD_DISCONNECT      0x07
#define CCP_CMD_GET_SEED        0x12
#define CCP_CMD_UNLOCK          0x13
#define CCP_CMD_DNLOAD_6        0x23
#define CCP_CMD_SHORT_UP        0x0F
#define CCP_CMD_SET_CAL_PAGE    0x11
#define CCP_CMD_GET_CAL_PAGE    0x09
#define CCP_CMD_SET_S_STATUS    0x0C
#define CCP_CMD_GET_S_STATUS    0x0D
#define CCP_CMD_BUILD_CHKSUM    0x0E
#define CCP_CMD_CLEAR_MEMORY    0x10
#define CCP_CMD_PROGRAM         0x18
#define CCP_CMD_PROGRAM_6       0x22
#define CCP_CMD_MOVE            0x19
#define CCP_CMD_TEST            0x05
#define CCP_CMD_DIAG_SERVICE    0x20
#define CCP_CMD_ACTION_SERVICE  0x21
#define CCP_CMD_START_STOP_ALL  0x08
#define CCP_SS_CAL              0x01
#define CCP_SS_DAQ              0x02
#define CCP_SS_RESUME           0x04
#define CCP_SS_TMP_DISCONNECTED 0x10
#define CCP_SS_CONNECTED        0x20
#define CCP_SS_STORE            0x40
#define CCP_SS_RUN              0x80
#define CCP_PL_CAL              0x01
#define CCP_PL_DAQ              0x02
#define CCP_PL_PGM              0x40
#define CCP_DAQ_STAT_STOP       0x00
#define CCP_DAQ_STAT_START      0x01
#define CCP_DAQ_STAT_PREPARE    0x02
#define CCP_UC_LOW(w)          (INT08U)(w)
#define CCP_UC_HIGH(w)         (INT08U)((w)>>8)
#define CCP_US_CREAT(h,l)     ((INT16U)(l)+((INT16U)(h)<<8))
#define CCP_ID_CREAT(a,b,c,d) ((INT32U)(d)+((INT32U)(c)<<8)+((INT32U)(b)<<16)+((INT32U)(a)<<24))
#define CCPPutCanMsg            CAN1PutMsgToTxBuf

#if    (CCP_CPU_9S12_ON == 1)
#define CCP_CPU_TO_ID32(x)    (((x>>1)&(INT32U)0x0003FFFF)|((x>>3)&(INT32U)0x1FFC0000))
#define CCP_ID32_TO_CPU(x)    (((x&(INT32U)0x0003FFFF)<<1)|((x&(INT32U)0x1FFC0000)<<3)|(INT32U)0x00180000)
#define CCP_CPU_TO_PGN16(x)     (INT16U)(((x>>9)&(INT32U)0x000003FF)|((x>>11)&(INT32U)0x0000FC00))
#define CCP_ID32_TO_PGN16(x)    (INT16U)(x>>8)
#define CCP_CPU_TO_PGN32(x)     (x&(INT32U)0x07E7FE00)
#endif
#if    (CCP_CPU_POWERPC_ON == 1)
#define CCP_CPU_TO_ID32(x)      ((x)&(INT32U)0x1FFFFFFF)
#define CCP_ID32_TO_CPU(x)      ((x)&(INT32U)0x1FFFFFFF)
#define CCP_CPU_TO_PGN16(x)     (INT16U)((x)>>8)
#define CCP_ID32_TO_PGN16(x)    (INT16U)((x)>>8)
#define CCP_CPU_TO_PGN32(x)     ((x)&(INT32U)0x00FFFF00)
#endif
#if    (CCP_CPU_STM32F1_ON == 1)
#define CCP_CPU_TO_ID32(x)      ((x)>>3)
#define CCP_ID32_TO_CPU(x)      (((x)<<3)|(INT32U)0x04)
#define CCP_CPU_TO_PGN16(x)     (INT16U)((x)>>11)
#define CCP_ID32_TO_PGN16(x)    (INT16U)((x)>>8)
#define CCP_CPU_TO_PGN32(x)     ((x)&(INT32U)0x07FFF800)
#endif

/* ******************************************************************** */
/*                         CCP 2.1 Definition                           */
/* ******************************************************************** */
#define CCP_ID32_SLAVE         (INT32U)0x18AAAAAA
#define CCP_ID32_MASTER        (INT32U)0x18BBBBBB
#define CCP_STATION_ADDR       (INT16U)0x1234
#define CCP_BROADCAST_ADDR     (INT16U)0x0000
#define CCP_VERSION_MAJOR      (INT08U)0x02
#define CCP_VERSION_MINOR      (INT08U)0x01
#define CCP_SEED_BYTE0         (INT08U)0x14
#define CCP_SEED_BYTE1         (INT08U)0x15
#define CCP_SEED_BYTE2         (INT08U)0x16
#define CCP_SEED_BYTE3         (INT08U)0x17
#define CCP_DB_DATA_TOTAL      (DB_PARAM_SIZE+DB_MEASU_SIZE+DB_FUNCT_SIZE+DB_CURVE_SIZE)
#define CCP_ADDR_SLAVE_ID      (CCP_DB_DATA_TOTAL*2)
#define CCP_CAL_DATA_TOTAL     (CCP_DB_DATA_TOTAL*2+4)
#define CCP_DAQ_ODT_SIZE        3
#define CCP_DAQ_LIST_SIZE       3
#define CCP_CAN_RX_BUF_SIZE     4
#define CCP_RX_TO_TICKS         5
#define CCP_SLAVE_ID_LENGTH     4
#define CCP_SLAVE_ID_TYPE       2
#define CCP_SLAVE_AVAIL_MASK    3
#define CCP_SLAVE_PROTECT_MASK  3
#define CCP_DAQ_USER_ID_ON      0

/* ******************************************************************** */
/*                         CCP 1.0 Definition                           */
/* ******************************************************************** */
#define CCP_CCP10_CODE_READ    (INT16U)0x1234
#define CCP_CCP10_CODE_WRITE   (INT16U)0x2345
#define CCP_CCP10_CODE_SAVE    (INT16U)0x3456
#define CCP_CCP10_CODE_PARA    (INT16U)0x4567
#define CCP_CCP10_IS_MASK      (INT16U)0x3000
#define CCP_CCP10_IS_PARAM     (INT16U)0x0000
#define CCP_CCP10_IS_MEASU     (INT16U)0x1000
#define CCP_CCP10_IS_FUNCT     (INT16U)0x2000
#define CCP_CCP10_IS_CURVE     (INT16U)0x3000

/* ******************************************************************** */
/*                           Type Definition                            */
/* ******************************************************************** */
typedef struct
{   INT16U     usCode;
    INT16U     usWhich;
    INT16U     usValue;
}   CCP_CCP10_STR;
typedef struct
{   INT08U     ucEnable;
    INT08U     ucPid;
    INT16U     aAdr[7];
}   CCP_ODT;
typedef struct
{   INT08U     ucEnable;
    INT08U     ucState;
    INT08U     ucLastOdt;
    INT08U     ucEveChan;
    INT16U     usTime;
    INT16U     usPeriod;
   #if (CCP_DAQ_USER_ID_ON == 1)
    INT32U     uiID;
   #endif
    CCP_ODT    aOdt[CCP_DAQ_ODT_SIZE];
}   CCP_DAQ;
typedef struct
{   INT16U     usRingBufRxCtr;
    OS_EVENT   *pRingBufRxSem;
    CAN_MSG    *pRingBufRxInPtr;
    CAN_MSG    *pRingBufRxOutPtr;
    CAN_MSG    sRingBufRx[CCP_CAN_RX_BUF_SIZE];
}   CCP_CAN_RING;

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
CCP_EXT INT16U usCCPTimer;
CCP_EXT INT16U usCCPStatus;
#if (CCP_CCP_CCP10_ON == 1)
CCP_EXT CCP_CCP10_STR sCCP10TxReq;
CCP_EXT CCP_CCP10_STR sCCP10RxReq;
CCP_EXT CCP_CCP10_STR sCCP10TxPar;
CCP_EXT CCP_CCP10_STR sCCP10RxPar;
#endif
#if (CCP_CCP_CCP21_ON == 1)
CCP_EXT INT08U ucCCPActDaq;
CCP_EXT INT08U ucCCPActOdt;
CCP_EXT INT08U ucCCPActEle;
CCP_EXT INT08U ucCCPReqPrivil;
CCP_EXT INT08U ucCCPActPrivil;
CCP_EXT INT08U ucCCPActSssState;
CCP_EXT INT08U ucCCPMta0AddrExt;
CCP_EXT INT08U ucCCPMta1AddrExt;
CCP_EXT INT16U usCCPMta0Addr;
CCP_EXT INT16U usCCPMta1Addr;
CCP_EXT INT32U uiCCPSlaveId;
CCP_EXT CCP_DAQ aCCPDaqList[CCP_DAQ_LIST_SIZE];
CCP_EXT CCP_CAN_RING sCCPCanCommBuf;
#endif

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (CCP_CCP_CCP10_ON == 1)
CCP_EXT void   CCP10FillMsgTxReq(CAN_MSG *pMsg);
CCP_EXT void   CCP10FillMsgTxPar(CAN_MSG *pMsg);
CCP_EXT void   CCP10DecodeRxPar(CAN_MSG *pMsg);
CCP_EXT INT08U CCP10DecodeRxReq(CAN_MSG *pMsg);
CCP_EXT INT08U CCP10CmdParaSave(INT16U usWhich);
CCP_EXT INT08U CCP10CmdParaWrite(INT16U usWhich, INT16U usValue);
CCP_EXT INT08U CCP10CmdParaRead(INT16U usWhich, INT16U *pResult);
#endif
#if (CCP_CCP_CCP21_ON == 1)
CCP_EXT void   CCP21Init(void);
CCP_EXT BOOL   CCPCheckTime(INT16U usOld, INT16U usPer);
CCP_EXT void   CCPCanBufInit(void);
CCP_EXT BOOL   CCPCanIsRxEmpty(void);
CCP_EXT void   CCPCanPutRxMsg(CAN_MSG *msg);
CCP_EXT INT08U CCPCanGetMsg(INT16U to, CAN_MSG *msg);
CCP_EXT INT16U CCPGetChkSum(INT16U usAddr, INT16U usSize);
CCP_EXT void   CCPClearMemory(INT16U usAddr, INT16U usSize);
CCP_EXT void   CCPMoveMemory(INT16U usSour, INT16U usDest, INT16U usSize);
CCP_EXT INT08U CCPGetEcuData8(INT16U usWhich);
CCP_EXT INT16U CCPGetEcuData16(INT16U usWhich);
CCP_EXT void   CCPSetEcuData8(INT16U usWhich, INT08U ucValue);
CCP_EXT void   CCPSetEcuData16(INT16U usWhich, INT16U usValue);
CCP_EXT void   CCPSaveEcuData(void);
CCP_EXT void   CCPDaqStartList(INT08U ucList);
CCP_EXT void   CCPDaqStartAll(void);
CCP_EXT void   CCPDaqStopList(INT08U ucList);
CCP_EXT void   CCPDaqStopAll(void);
CCP_EXT void   CCPDaqInitList(INT08U ucList);
CCP_EXT void   CCPDaqInitAll(void);
CCP_EXT void   CCPDaqSendMsg(CAN_MSG *pTxMsg);
CCP_EXT INT08U CCPProcessRxComd(CAN_MSG *pRxMsg, CAN_MSG *pTxMsg);
#endif

/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
