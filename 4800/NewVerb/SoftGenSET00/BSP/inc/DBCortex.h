/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File DBCortex.h                         */
/*                            By: Wu Xuekui                             */
/*                              2016-1-14                               */
/* ******************************************************************** */

#ifndef _DBCORTEX_H

#define _DBCORTEX_H

#ifdef   DB_GLOBALS

#define  DB_EXT  

#else

#define  DB_EXT extern

#endif

/* ******************************************************************** */
/*  DB_VERSION  = 10xx: VEC1000 Application                             */
/*  DB_VERSION  = 40xx: VEC4000 Application                             */
/*  DB_VERSION  = 68xx: VEC6800 Application                             */
/*  DB_VERSION  = 69xx: VEC6900 Application                             */
/*  DB_VERSION  = 760x: GEC7600-Main Application                        */
/*  DB_VERSION  = 761x: GEC7600-Display Application                     */
/*  DB_VERSION  = 780x: GEC7800-Main Application                        */
/*  DB_VERSION  = 781x: GEC7800-Display Application                     */
/*  DB_VERSION  = 80xx: VEC8000 Application                             */
/*  DB_VERSION  = 90xx: VEC9000 Application                             */
/*  DB_VERSION  = 96xx: VEC9600 Application                             */
/* ******************************************************************** */

#define DB_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define DB_1000_COMMON_ON       0
#define DB_4000_COMMON_ON       0
#define DB_6800_COMMON_ON       0
#define DB_6900_COMMON_ON       0
#define DB_7600_COMMON_ON       0
#define DB_7600_MAIN_CHIP_ON    0
#define DB_7600_AUX_CHIP_ON     0
#define DB_7800_COMMON_ON       0
#define DB_7800_MAIN_CHIP_ON    0
#define DB_7800_AUX_CHIP_ON     0
#define DB_8000_COMMON_ON       0
#define DB_9000_COMMON_ON       0
#define DB_9600_COMMON_ON       0
#if   ((DB_VERSION / 100)   == 10)
#undef  DB_1000_COMMON_ON
#define DB_1000_COMMON_ON       1
#endif
#if   ((DB_VERSION / 100)   == 40)
#undef  DB_4000_COMMON_ON
#define DB_4000_COMMON_ON       1
#endif
#if   ((DB_VERSION / 100)   == 68)
#undef  DB_6800_COMMON_ON
#define DB_6800_COMMON_ON       1
#endif
#if   ((DB_VERSION / 100)   == 69)
#undef  DB_6900_COMMON_ON
#define DB_6900_COMMON_ON       1
#endif
#if   ((DB_VERSION / 100)   == 76)
#undef  DB_7600_COMMON_ON
#define DB_7600_COMMON_ON       1
#endif
#if   ((DB_VERSION / 10)   == 760)
#undef  DB_7600_MAIN_CHIP_ON
#define DB_7600_MAIN_CHIP_ON    1
#endif
#if   ((DB_VERSION / 10)   == 761)
#undef  DB_7600_AUX_CHIP_ON
#define DB_7600_AUX_CHIP_ON     1
#endif
#if   ((DB_VERSION / 100)   == 78)
#undef  DB_7800_COMMON_ON
#define DB_7800_COMMON_ON       1
#endif
#if   ((DB_VERSION / 10)   == 780)
#undef  DB_7800_MAIN_CHIP_ON
#define DB_7800_MAIN_CHIP_ON    1
#endif
#if   ((DB_VERSION / 10)   == 781)
#undef  DB_7800_AUX_CHIP_ON
#define DB_7800_AUX_CHIP_ON     1
#endif
#if   ((DB_VERSION / 100)   == 80)
#undef  DB_8000_COMMON_ON
#define DB_8000_COMMON_ON       1
#endif
#if   ((DB_VERSION / 100)   == 90)
#undef  DB_9000_COMMON_ON
#define DB_9000_COMMON_ON       1
#endif
#if   ((DB_VERSION / 100)   == 96)
#undef  DB_9600_COMMON_ON
#define DB_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define DB_CPU_9S12_ON          0
#define DB_CPU_POWERPC_ON       0
#define DB_CPU_STM32F1_ON       0
#define DB_CPU_STM32F103_ON     0
#define DB_CPU_STM32F105_ON     0
#define DB_SCI_UC_LOW_FIRST     0
#if    (DB_1000_COMMON_ON    == 1)
#undef  DB_CPU_9S12_ON
#define DB_CPU_9S12_ON          1
#endif
#if    (DB_4000_COMMON_ON    == 1)
#undef  DB_CPU_9S12_ON
#define DB_CPU_9S12_ON          1
#endif
#if    (DB_6800_COMMON_ON    == 1)
#undef  DB_CPU_9S12_ON
#define DB_CPU_9S12_ON          1
#endif
#if    (DB_6900_COMMON_ON    == 1)
#undef  DB_CPU_POWERPC_ON
#define DB_CPU_POWERPC_ON       1
#endif
#if    (DB_7600_COMMON_ON    == 1)
#undef  DB_CPU_STM32F1_ON
#define DB_CPU_STM32F1_ON       1
#endif
#if    (DB_7600_MAIN_CHIP_ON == 1)
#undef  DB_CPU_STM32F105_ON
#define DB_CPU_STM32F105_ON     1
#endif
#if    (DB_7600_AUX_CHIP_ON  == 1)
#undef  DB_CPU_STM32F103_ON
#define DB_CPU_STM32F103_ON     1
#endif
#if    (DB_7800_COMMON_ON    == 1)
#undef  DB_CPU_STM32F1_ON
#define DB_CPU_STM32F1_ON       1
#endif
#if    (DB_7800_MAIN_CHIP_ON == 1)
#undef  DB_CPU_STM32F105_ON
#define DB_CPU_STM32F105_ON     1
#endif
#if    (DB_7800_AUX_CHIP_ON  == 1)
#undef  DB_CPU_STM32F103_ON
#define DB_CPU_STM32F103_ON     1
#endif
#if    (DB_8000_COMMON_ON    == 1)
#undef  DB_CPU_POWERPC_ON
#define DB_CPU_POWERPC_ON       1
#endif
#if    (DB_9000_COMMON_ON    == 1)
#undef  DB_CPU_POWERPC_ON
#define DB_CPU_POWERPC_ON       1
#endif
#if    (DB_9600_COMMON_ON    == 1)
#undef  DB_CPU_POWERPC_ON
#define DB_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                           Basis Definition                           */
/* ******************************************************************** */
#define DB_TRUE                 1
#define DB_FALSE                0
#define DB_DIFFERENT            1
#define DB_SAME                 0
#define DB_NO_ERR               0
#define DB_ERR_EVENT_TYPE       1
#define DB_ERR_PEND_ISR         2
#define DB_ERR_BAD_CH           3
#define DB_ERR_RX_EMPTY         4
#define DB_ERR_TX_FULL          5
#define DB_ERR_TX_EMPTY         6
#define DB_ERR_RX_TIMEOUT       7
#define DB_ERR_TX_TIMEOUT       8
#define DB_FLASH_STS_COMPLETE   0
#define DB_FLASH_STS_BUSY       1
#define DB_FLASH_STS_ERR_WRP    2
#define DB_FLASH_STS_ERR_PG     4
#define DB_FLASH_STS_TIMEOUT    5
#define DB_BLOCK_STS_ERASED     0
#define DB_BLOCK_STS_PROTECT    1
#define DB_BLOCK_STS_FAULT      2
#define DB_BLOCK_STS_WRITED     3
#define DB_BLOCK_STS_DELETE     4
#define DB_STS_NORMAL          (INT32U)0x00000000
#define DB_STS_RESET           (INT32U)0x00000001
#define DB_STS_WARNING         (INT32U)0x00000002
#define DB_STS_INTERRUPT       (INT32U)0x00000004
#define DB_STS_ERR_LOGIC       (INT32U)0x00000008
#define DB_STS_ERR_READ_PARAM  (INT32U)0x00000010
#define DB_STS_ERR_READ_FUNCT  (INT32U)0x00000020
#define DB_STS_ERR_READ_CURVE  (INT32U)0x00000040
#define DB_STS_ERR_READ_HSTRY  (INT32U)0x00000080
#define DB_STS_ERR_WRITE_PARAM (INT32U)0x00000100
#define DB_STS_ERR_WRITE_FUNCT (INT32U)0x00000200
#define DB_STS_ERR_WRITE_CURVE (INT32U)0x00000400
#define DB_STS_ERR_WRITE_HSTRY (INT32U)0x00000800
#define DB_STS_ERR_CHECK_PARAM (INT32U)0x00001000
#define DB_STS_ERR_CHECK_FUNCT (INT32U)0x00002000
#define DB_STS_ERR_CHECK_CURVE (INT32U)0x00004000
#define DB_STS_ERR_CHECK_HSTRY (INT32U)0x00008000
#define DB_STS_GET_BIT(m)      (uiDBStatus & (m))
#define DB_STS_CLR_BIT(m)       uiDBStatus &= ~(m)
#define DB_STS_SET_BIT(m)       uiDBStatus |= (m)
#define DB_STS_ERR_READ_MSK    (DB_STS_ERR_READ_PARAM | \
                                DB_STS_ERR_READ_FUNCT | \
                                DB_STS_ERR_READ_CURVE | \
                                DB_STS_ERR_READ_HSTRY )
#define DB_STS_ERR_WRITE_MSK   (DB_STS_ERR_WRITE_PARAM | \
                                DB_STS_ERR_WRITE_FUNCT | \
                                DB_STS_ERR_WRITE_CURVE | \
                                DB_STS_ERR_WRITE_HSTRY )
#define DB_STS_ERR_CHECK_MSK   (DB_STS_ERR_CHECK_PARAM | \
                                DB_STS_ERR_CHECK_FUNCT | \
                                DB_STS_ERR_CHECK_CURVE | \
                                DB_STS_ERR_CHECK_HSTRY )

/* ******************************************************************** */
/*                           Control Definition                         */
/* ******************************************************************** */
#define DB_UC_LOW(w)           (INT08U)(w)
#define DB_UC_HIGH(w)          (INT08U)((w)>>8)
#define DB_US_CREAT(h,l)       ((INT16U)(l)+((INT16U)(h)<<8))
/* ************************** DB Save Command ************************* */
#define DB_CMD_BUF_SIZE         8
#define DB_CMD_TO_TICKS         10
#define DB_CMD_SAVE_PARAM      (INT08U)0xC0
#define DB_CMD_SAVE_MEASU      (INT08U)0xD0
#define DB_CMD_SAVE_HSTRY      (INT08U)0xD0
#define DB_CMD_SAVE_FUNCT      (INT08U)0xE0
#define DB_CMD_SAVE_CURVE      (INT08U)0xF0
#define DB_CMD_SAVE_STAT       (INT08U)0xF1
/* ************************** DB Params Size ************************** */
#define DB_PARAM_SIZE           480
#define DB_FUNCT_SIZE           120
#define DB_CURVE_SIZE           400
#define DB_MEASU_SIZE           500
#define DB_MEASU_NOR_SIZE       360
#define DB_HSTRY_SIZE           140
#define DB_PARAM_SIZE08        (DB_PARAM_SIZE * 2)
#define DB_PARAM_SIZE16         DB_PARAM_SIZE
#define DB_PARAM_SIZE32        (DB_PARAM_SIZE / 2)
#define DB_FUNCT_SIZE08        (DB_FUNCT_SIZE * 2)
#define DB_FUNCT_SIZE16         DB_FUNCT_SIZE
#define DB_FUNCT_SIZE32        (DB_FUNCT_SIZE / 2)
#define DB_CURVE_SIZE08        (DB_CURVE_SIZE * 2)
#define DB_CURVE_SIZE16         DB_CURVE_SIZE
#define DB_CURVE_SIZE32        (DB_CURVE_SIZE / 2)
#define DB_MEASU_SIZE08        (DB_MEASU_SIZE * 2)
#define DB_MEASU_SIZE16         DB_MEASU_SIZE
#define DB_MEASU_SIZE32        (DB_MEASU_SIZE / 2)
#define DB_HSTRY_SIZE08        (DB_HSTRY_SIZE * 2)
#define DB_HSTRY_SIZE16         DB_HSTRY_SIZE
#define DB_HSTRY_SIZE32        (DB_HSTRY_SIZE / 2)
/* ************************** DB Eeprom (Flash) *********************** */
#if    (DB_CPU_STM32F105_ON == 1)
#define DB_FLASH_BANK1_ADR_MAX (INT32U)0x0807FFFE
#define DB_RDP_KEY             (INT16U)0x00A5
#define DB_FLASH_KEY1          (INT32U)0x45670123
#define DB_FLASH_KEY2          (INT32U)0xCDEF89AB
#define DB_FLASH_ADDR_MIN      (INT32U)0x08000000
#define DB_FLASH_ADDR_MAX      (INT32U)0x0803FFFF
#define DB_FLASH_PAGE_NUM      (INT32U)128
#define DB_FLASH_PAGE_SIZ      (INT32U)0x0800
#define DB_FLASH_PAGE_MSK      (INT32U)0xFFFFF800
#define DB_EEP_HEAD_SIZE        4
#define DB_PARAM_ADDR          (INT32U)0x0803B000
#define DB_PARAM_PAGE_NUM       1
#define DB_FUNCT_ADDR          (INT32U)0x0803B800
#define DB_FUNCT_PAGE_NUM       1
#define DB_CURVE_ADDR          (INT32U)0x0803C000
#define DB_CURVE_PAGE_NUM       1
#define DB_HSTRY_ADDR          (INT32U)0x0803C800
#define DB_HSTRY_PAGE_NUM       7
#define DB_HSTRY_RECORD_SIZE   (DB_EEP_HEAD_SIZE + DB_HSTRY_SIZE08)
#define DB_HSTRY_RECORD_ID     (INT32U)0x00003412
#define DB_HSTRY_RECORD_HEAD   (DB_HSTRY_RECORD_ID + (DB_HSTRY_SIZE08 << 16))
#endif

/* ******************************************************************** */
/*                            Type Definition                           */
/* ******************************************************************** */
typedef struct
{   INT32U      uiStatus;
    INT32U      uiHead;
    INT32U      uiPageMask;
    INT32U      uiPageSiz8;
    INT32U      uiRcrdSiz8;
    INT32U      uiDatSiz16;
    INT32U      uiAddrMin;
    INT32U      uiAddrMax;
    INT32U      uiAddrCurr;
    INT32U      uiAddrNext;
    INT32U      uiCPageAMax;
    INT32U      uiNPageAMin;
}   DB_EEP_BLOCK;
typedef struct
{   INT16U      usRingBufRxCtr;
    OS_EVENT   *pRingBufRxSem;
    INT08U     *pRingBufRxInPtr;
    INT08U     *pRingBufRxOutPtr;
    INT08U      ucRingBufRx[DB_CMD_BUF_SIZE];
}   DB_CMD_RING;

/* ******************************************************************** */
/*                           Variable Definition                        */
/* ******************************************************************** */

DB_EXT INT32U uiDBStatus;
#pragma data_alignment = 4
DB_EXT INT16U aDBParam[DB_PARAM_SIZE];
#pragma data_alignment = 4
DB_EXT INT16U aDBFunct[DB_FUNCT_SIZE];
#pragma data_alignment = 4
DB_EXT INT16U aDBCurve[DB_CURVE_SIZE];
#pragma data_alignment = 4
DB_EXT INT16U aDBMeasu[DB_MEASU_SIZE];
DB_EXT DB_CMD_RING sDBCmdRingBuf;
DB_EXT DB_EEP_BLOCK sDBHstryBlck;

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
DB_EXT void   DBInit(void);
DB_EXT void   DBStart(void);
DB_EXT void   DBTaskLoop(void);
DB_EXT INT08U DBCheckParam(void);
DB_EXT void   DBResetParam(void);
DB_EXT INT08U DBCheckFunct(void);
DB_EXT void   DBResetFunct(void);
DB_EXT INT08U DBCheckCurve(void);
DB_EXT void   DBResetCurve(void);
DB_EXT INT08U DBCheckHstry(void);
DB_EXT void   DBResetHstry(void);
DB_EXT void   DBResetMeasu(void);
DB_EXT INT08U DBEepReadParam(INT16U *pData, INT32U uiAddr, INT16U usSize);
DB_EXT INT08U DBEepWriteParam(INT16U *pData, INT32U uiAddr, INT16U usSize);
DB_EXT void   DBEepInitHstryBlock(void);
DB_EXT void   DBEepCheckRecord(DB_EEP_BLOCK *pBlck);
DB_EXT INT08U DBEepReadRecord(DB_EEP_BLOCK *pBlck, INT16U *pData);
DB_EXT void   DBEepWriteRecord(DB_EEP_BLOCK *pBlck, INT16U *pData);
DB_EXT void   DBInitDFlash(void);
DB_EXT INT32U DBGetBank1Status(void);
DB_EXT INT32U DBGetBank2Status(void);
DB_EXT INT32U DBWaitBank1Complete(INT32U uiDelay);
DB_EXT INT32U DBWaitBank2Complete(INT32U uiDelay);
DB_EXT INT32U DBFlashErasePage(INT32U uiAddr);
DB_EXT INT32U DBFlashWrite16u(INT32U uiAddr, INT16U usData);
DB_EXT INT32U DBFlashWrite32u(INT32U uiAddr, INT32U uiData);
DB_EXT INT32U DBFlashWrite16p(INT32U uiAddr, INT16U *pData, INT32U uiSize);
DB_EXT INT16U DBFlashRead16u(INT32U uiAddr);
DB_EXT INT32U DBFlashRead32u(INT32U uiAddr);
DB_EXT void   DBFlashRead16p(INT32U uiAddr, INT16U *pData, INT32U uiSize);
DB_EXT void   DBCmdBufInit(void);
DB_EXT INT08U DBTskGetCmd(INT16U to, INT08U *err);
DB_EXT void   DBTskPutCmd(INT08U c);
DB_EXT INT16U DBGetParam16u(INT16U usBegin);
DB_EXT INT08U DBGetParam16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBGetParam08p(INT08U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBSetParam16u(INT16U usBegin, INT16U usValue);
DB_EXT INT08U DBSetParam16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBSetParam08p(INT08U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBCheckParam16u(INT16U usBegin, INT16U usValue);
DB_EXT INT08U DBCheckParam16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT16U DBGetMeasu16u(INT16U usBegin);
DB_EXT INT08U DBGetMeasu16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBGetMeasu08p(INT08U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBSetMeasu16u(INT16U usBegin, INT16U usValue);
DB_EXT INT08U DBSetMeasu16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBSetMeasu08p(INT08U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBCheckMeasu16u(INT16U usBegin, INT16U usValue);
DB_EXT INT08U DBCheckMeasu16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT16U DBGetFunct16u(INT16U usBegin);
DB_EXT INT08U DBGetFunct16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBGetFunct08p(INT08U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBSetFunct16u(INT16U usBegin, INT16U usValue);
DB_EXT INT08U DBSetFunct16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBSetFunct08p(INT08U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBCheckFunct16u(INT16U usBegin, INT16U usValue);
DB_EXT INT08U DBCheckFunct16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT16U DBGetCurve16u(INT16U usBegin);
DB_EXT INT08U DBGetCurve16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBGetCurve08p(INT08U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBSetCurve16u(INT16U usBegin, INT16U usValue);
DB_EXT INT08U DBSetCurve16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBSetCurve08p(INT08U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBCheckCurve16u(INT16U usBegin, INT16U usValue);
DB_EXT INT08U DBCheckCurve16p(INT16U *pDat, INT16U usBegin, INT16U usSize);

/* ******************************************************************** */
/*                     GEC7800 Parameter Definition                     */
/* ******************************************************************** */
/* **************** Part 1: Grid Electric Parameters ****************** */
#define usDBpMainSystemType        (*((INT16U*)aDBParam+  0))
#define usDBpMainVoltCtRatio       (*((INT16U*)aDBParam+  1))
#define usDBpMainVoltRated         (*((INT16U*)aDBParam+  2))
#define usDBpMainVoltErrLow        (*((INT16U*)aDBParam+  3))
#define usDBpMainVoltErrHigh       (*((INT16U*)aDBParam+  4))
#define usDBpMainVoltErrDly        (*((INT16U*)aDBParam+  5))
#define usDBpMainVoltLostLow       (*((INT16U*)aDBParam+  6))
#define usDBpMainVoltLostDly       (*((INT16U*)aDBParam+  7))
#define usDBpMainFreqRated         (*((INT16U*)aDBParam+  8))
#define usDBpMainFreqErrLow        (*((INT16U*)aDBParam+  9))
#define usDBpMainFreqErrHigh       (*((INT16U*)aDBParam+ 10))
#define usDBpMainFreqErrDly        (*((INT16U*)aDBParam+ 11))
#define usDBpMainPhaseErrLow       (*((INT16U*)aDBParam+ 12))
#define usDBpMainPhaseErrHigh      (*((INT16U*)aDBParam+ 13))
#define usDBpMainPhaseErrDly       (*((INT16U*)aDBParam+ 14))
#define usDBpMainCurrCtRatio       (*((INT16U*)aDBParam+ 15))
#define usDBpMainCurrRated         (*((INT16U*)aDBParam+ 16))
#define usDBpMainCurrShort         (*((INT16U*)aDBParam+ 17))
#define usDBpMainCurrShortDly      (*((INT16U*)aDBParam+ 18))
#define usDBpMainCurrLongDly       (*((INT16U*)aDBParam+ 19))
#define usDBpMainCurrGndErrHigh    (*((INT16U*)aDBParam+ 20))
#define usDBpMainCurrGndErrDly     (*((INT16U*)aDBParam+ 21))
#define usDBpMainCurrUnbErrHigh    (*((INT16U*)aDBParam+ 22))
#define usDBpMainCurrUnbErrDly     (*((INT16U*)aDBParam+ 23))
#define usDBpMainActPwrRated       (*((INT16U*)aDBParam+ 24))
#define usDBpMainActPwrErrHigh     (*((INT16U*)aDBParam+ 25))
#define usDBpMainActPwrErrDly      (*((INT16U*)aDBParam+ 26))
#define usDBpMainReactPwrRated     (*((INT16U*)aDBParam+ 27))
#define usDBpMainReactPwrErrHigh   (*((INT16U*)aDBParam+ 28))
#define usDBpMainReactPwrErrDly    (*((INT16U*)aDBParam+ 29))
#define usDBpMainAppPwrErrHigh     (*((INT16U*)aDBParam+ 30))
#define usDBpMainAppPwrErrDly      (*((INT16U*)aDBParam+ 31))
#define usDBpMainRocofErrHigh      (*((INT16U*)aDBParam+ 32))
#define usDBpMainRocofErrDly       (*((INT16U*)aDBParam+ 33))
#define usDBpMainVoltUnbErrHigh    (*((INT16U*)aDBParam+ 34))
#define usDBpMainVoltUnbErrDly     (*((INT16U*)aDBParam+ 35))
#define usDBpMainSyncVoltErrLow    (*((INT16U*)aDBParam+ 36))
#define usDBpMainSyncVoltErrHigh   (*((INT16U*)aDBParam+ 37))
#define usDBpMainSyncVoltErrDly    (*((INT16U*)aDBParam+ 38))
#define usDBpMainSyncFreqErrLow    (*((INT16U*)aDBParam+ 39))
#define usDBpMainSyncFreqErrHigh   (*((INT16U*)aDBParam+ 40))
#define usDBpMainSyncFreqErrDly    (*((INT16U*)aDBParam+ 41))
#define usDBpMainBackup1           (*((INT16U*)aDBParam+ 42))
#define usDBpMainBackup2           (*((INT16U*)aDBParam+ 43))

/* **************** Part 2: Generator Setpint Parameters ************** */
#define usDBpGeneratorType         (*((INT16U*)aDBParam+ 44))
#define usDBpGensPoleNum           (*((INT16U*)aDBParam+ 45))
#define usDBpGensVoltCtRatio       (*((INT16U*)aDBParam+ 46))
#define usDBpGensVoltRated         (*((INT16U*)aDBParam+ 47))
#define usDBpGensVoltToLoad        (*((INT16U*)aDBParam+ 48))
#define usDBpGensVoltToLoadDly     (*((INT16U*)aDBParam+ 49))
#define usDBpGensVoltWarnLow       (*((INT16U*)aDBParam+ 50))
#define usDBpGensVoltWarnHigh      (*((INT16U*)aDBParam+ 51))
#define usDBpGensVoltWarnDly       (*((INT16U*)aDBParam+ 52))
#define usDBpGensVoltStopLow       (*((INT16U*)aDBParam+ 53))
#define usDBpGensVoltStopHigh      (*((INT16U*)aDBParam+ 54))
#define usDBpGensVoltStopDly       (*((INT16U*)aDBParam+ 55))
#define usDBpGensFreqRated         (*((INT16U*)aDBParam+ 56))
#define usDBpGensFreqToLoad        (*((INT16U*)aDBParam+ 57))
#define usDBpGensFreqToLoadDly     (*((INT16U*)aDBParam+ 58))
#define usDBpGensFreqWarnLow       (*((INT16U*)aDBParam+ 59))
#define usDBpGensFreqWarnHigh      (*((INT16U*)aDBParam+ 60))
#define usDBpGensFreqWarnDly       (*((INT16U*)aDBParam+ 61))
#define usDBpGensFreqStopLow       (*((INT16U*)aDBParam+ 62))
#define usDBpGensFreqStopHigh      (*((INT16U*)aDBParam+ 63))
#define usDBpGensFreqStopDly       (*((INT16U*)aDBParam+ 64))
#define usDBpGensPhaseErrLow       (*((INT16U*)aDBParam+ 65))
#define usDBpGensPhaseErrHigh      (*((INT16U*)aDBParam+ 66))
#define usDBpGensPhaseErrDly       (*((INT16U*)aDBParam+ 67))
#define usDBpGensCurrCtRatio       (*((INT16U*)aDBParam+ 68))
#define usDBpGensCurrRated         (*((INT16U*)aDBParam+ 69))
#define usDBpGensCurrShort         (*((INT16U*)aDBParam+ 70))
#define usDBpGensCurrShortDly      (*((INT16U*)aDBParam+ 71))
#define usDBpGensCurrLongDly       (*((INT16U*)aDBParam+ 72))
#define usDBpGensCurrGndErrHigh    (*((INT16U*)aDBParam+ 73))
#define usDBpGensCurrGndErrDly     (*((INT16U*)aDBParam+ 74))
#define usDBpGensCurrUnbErrHigh    (*((INT16U*)aDBParam+ 75))
#define usDBpGensCurrUnbErrDly     (*((INT16U*)aDBParam+ 76))
#define usDBpGensActPwrRated       (*((INT16U*)aDBParam+ 77))
#define usDBpGensActPwrErrHigh     (*((INT16U*)aDBParam+ 78))
#define usDBpGensActPwrErrDly      (*((INT16U*)aDBParam+ 79))
#define usDBpGensReactPwrRated     (*((INT16U*)aDBParam+ 80))
#define usDBpGensReactPwrErrHigh   (*((INT16U*)aDBParam+ 81))
#define usDBpGensReactPwrErrDly    (*((INT16U*)aDBParam+ 82))
#define usDBpGensAppPwrErrHigh     (*((INT16U*)aDBParam+ 83))
#define usDBpGensAppPwrErrDly      (*((INT16U*)aDBParam+ 84))
#define usDBpGensInvPwrErrHigh     (*((INT16U*)aDBParam+ 85))
#define usDBpGensInvPwrErrDly      (*((INT16U*)aDBParam+ 86))
#define usDBpGensFactorErrLow      (*((INT16U*)aDBParam+ 87))
#define usDBpGensFactorErrHigh     (*((INT16U*)aDBParam+ 88))
#define usDBpGensFactorErrDly      (*((INT16U*)aDBParam+ 89))
#define usDBpGensMagLostErrHigh    (*((INT16U*)aDBParam+ 90))
#define usDBpGensMagLostErrDly     (*((INT16U*)aDBParam+ 91))
#define usDBpGensBackup1           (*((INT16U*)aDBParam+ 92))
#define usDBpGensBackup2           (*((INT16U*)aDBParam+ 93))

/* **************** Part 3: Engine Setpint Parameters ***************** */
#define usDBpEngineType            (*((INT16U*)aDBParam+ 94))
#define usDBpEngTeethCrank1        (*((INT16U*)aDBParam+ 95))
#define usDBpEngTeethCrank2        (*((INT16U*)aDBParam+ 96))
#define usDBpEngSpeedFilter1       (*((INT16U*)aDBParam+ 97))
#define usDBpEngSpeedFilter2       (*((INT16U*)aDBParam+ 98))
#define usDBpEngSpeedStart1        (*((INT16U*)aDBParam+ 99))
#define usDBpEngSpeedStart2        (*((INT16U*)aDBParam+100))
#define usDBpEngSpeedIdle          (*((INT16U*)aDBParam+101))
#define usDBpEngSpeedIdleMin       (*((INT16U*)aDBParam+102))
#define usDBpEngSpeedIdleMax       (*((INT16U*)aDBParam+103))
#define usDBpEngSpeedRated         (*((INT16U*)aDBParam+104))
#define usDBpEngSpeedRatedMin      (*((INT16U*)aDBParam+105))
#define usDBpEngSpeedWarnLow       (*((INT16U*)aDBParam+106))
#define usDBpEngSpeedWarnHigh      (*((INT16U*)aDBParam+107))
#define usDBpEngSpeedWarnDly       (*((INT16U*)aDBParam+108))
#define usDBpEngSpeedStopLow       (*((INT16U*)aDBParam+109))
#define usDBpEngSpeedStopHigh      (*((INT16U*)aDBParam+110))
#define usDBpEngSpeedStopDly       (*((INT16U*)aDBParam+111))
#define usDBpEngAutoStartTimesMax  (*((INT16U*)aDBParam+112))
#define usDBpEngHandStartTimesMax  (*((INT16U*)aDBParam+113))
#define usDBpEngStoppingTimeMax    (*((INT16U*)aDBParam+114))
#define usDBpEngRampTimeMaxToWarn  (*((INT16U*)aDBParam+115))
#define usDBpEngRampTimeMaxToStop  (*((INT16U*)aDBParam+116))
#define usDBpEngSpeedDeltaToWarn   (*((INT16U*)aDBParam+117))
#define usDBpEngSpeedDeltaToStop   (*((INT16U*)aDBParam+118))
#define usDBpEngSpeedDeltaErrDly   (*((INT16U*)aDBParam+119))
#define usDBpEngTempHeaterCold     (*((INT16U*)aDBParam+120))
#define usDBpEngTempHeaterWarm     (*((INT16U*)aDBParam+121))
#define usDBpEngOilPumpOnTime      (*((INT16U*)aDBParam+122))
#define usDBpEngOilPumpOffPress    (*((INT16U*)aDBParam+123))
#define usDBpEngCoolFanOnTemp      (*((INT16U*)aDBParam+124))
#define usDBpEngCoolFanOffDly      (*((INT16U*)aDBParam+125))
#define usDBpEngStartSignal        (*((INT16U*)aDBParam+126))
#define usDBpEngStartFreq          (*((INT16U*)aDBParam+127))
#define usDBpEngStartOilPress      (*((INT16U*)aDBParam+128))
#define usDBpEngBackup1            (*((INT16U*)aDBParam+129))
#define usDBpEngBackup2            (*((INT16U*)aDBParam+130))
#define usDBpEngBackup3            (*((INT16U*)aDBParam+131))

/* **************** Part 4: Timer Setpint Parameters ****************** */
#define usDBpSysOperationMode      (*((INT16U*)aDBParam+132))
#define usDBpTimeStoppedToReady    (*((INT16U*)aDBParam+133))
#define usDBpTimeReadyToStarting   (*((INT16U*)aDBParam+134))
#define usDBpTimeIdlingToRampUp    (*((INT16U*)aDBParam+135))
#define usDBpTimeIdlingToStopping  (*((INT16U*)aDBParam+136))
#define usDBpTimeRatedReadyDly     (*((INT16U*)aDBParam+137))
#define usDBpTimeRatedToRampDowm   (*((INT16U*)aDBParam+138))
#define usDBpTimeWorkToStopDly     (*((INT16U*)aDBParam+139))
#define usDBpTimeOfLoadingOn       (*((INT16U*)aDBParam+140))
#define usDBpTimeOfLoadingOff      (*((INT16U*)aDBParam+141))
#define usDBpTimeOfMainSwitchOn    (*((INT16U*)aDBParam+142))
#define usDBpTimeOfMainSwitchOff   (*((INT16U*)aDBParam+143))
#define usDBpTimeOfGensSwitchOn    (*((INT16U*)aDBParam+144))
#define usDBpTimeOfGensSwitchOff   (*((INT16U*)aDBParam+145))
#define usDBpTimeOfFixedPowerUp    (*((INT16U*)aDBParam+146))
#define usDBpTimeOfFixedPowerDown  (*((INT16U*)aDBParam+147))
#define usDBpTimeOfStarterOn       (*((INT16U*)aDBParam+148))
#define usDBpTimeOfStarterOff      (*((INT16U*)aDBParam+149))
#define usDBpTimeOfHeaterAtCold    (*((INT16U*)aDBParam+150))
#define usDBpTimeOfHeaterAtWarm    (*((INT16U*)aDBParam+151))
#define usDBpTimeOfSyncFailToWarn  (*((INT16U*)aDBParam+152))
#define usDBpTimeOfSyncFailToStop  (*((INT16U*)aDBParam+153))
#define usDBpTimeOfStatistics      (*((INT16U*)aDBParam+154))
#define usDBpTimeOfStopOutput      (*((INT16U*)aDBParam+155))
#define usDBpTimeOfMainSwOutput    (*((INT16U*)aDBParam+156))
#define usDBpTimeOfGensSwOutput    (*((INT16U*)aDBParam+157))
#define usDBpTimeBackup1           (*((INT16U*)aDBParam+158))
#define usDBpTimeBackup2           (*((INT16U*)aDBParam+159))
#define usDBpTimeBackup3           (*((INT16U*)aDBParam+160))
#define usDBpTimeBackup4           (*((INT16U*)aDBParam+161))

/* **************** Part 5: Synchronization & Load share ************** */
#define usDBpSyncVoltDiffMax       (*((INT16U*)aDBParam+162))
#define usDBpSyncPhaseDiffMax      (*((INT16U*)aDBParam+163))
#define usDBpSyncFreqDiffPosMax    (*((INT16U*)aDBParam+164))
#define usDBpSyncFreqDiffNegMax    (*((INT16U*)aDBParam+165))
#define usDBpSyncFreqDiffSetp      (*((INT16U*)aDBParam+166))
#define usDBpSyncGovCtrlInit       (*((INT16U*)aDBParam+167))
#define usDBpSyncGovGain           (*((INT16U*)aDBParam+168))
#define usDBpSyncGovStability      (*((INT16U*)aDBParam+169))
#define usDBpSyncGovDerivative     (*((INT16U*)aDBParam+170))
#define usDBpSyncAvrCtrlInit       (*((INT16U*)aDBParam+171))
#define usDBpSyncAvrGain           (*((INT16U*)aDBParam+172))
#define usDBpSyncAvrStability      (*((INT16U*)aDBParam+173))
#define usDBpSyncAvrDerivative     (*((INT16U*)aDBParam+174))
#define usDBpLoadReactCtrlMode     (*((INT16U*)aDBParam+175))
#define usDBpLoadActPowerSetp      (*((INT16U*)aDBParam+176))
#define usDBpLoadReactPowerSetp    (*((INT16U*)aDBParam+177))
#define usDBpLoadPowerFactorSetp   (*((INT16U*)aDBParam+178))
#define usDBpLoadGovGain           (*((INT16U*)aDBParam+179))
#define usDBpLoadGovStability      (*((INT16U*)aDBParam+180))
#define usDBpLoadGovDerivative     (*((INT16U*)aDBParam+181))
#define usDBpLoadAvrGain           (*((INT16U*)aDBParam+182))
#define usDBpLoadAvrStability      (*((INT16U*)aDBParam+183))
#define usDBpLoadAvrDerivative     (*((INT16U*)aDBParam+184))
#define usDBpSyncBackup1           (*((INT16U*)aDBParam+185))
#define usDBpSyncBackup2           (*((INT16U*)aDBParam+186))
#define usDBpSyncBackup3           (*((INT16U*)aDBParam+187))

/* **************** Part 6: CanBus / ModBus *************************** */
#define usDBpModulePassword        (*((INT16U*)aDBParam+188))
#define usDBpModuleLanguage        (*((INT16U*)aDBParam+189))
#define usDBpModBus1Baudrate       (*((INT16U*)aDBParam+190))
#define usDBpModBus1Address        (*((INT16U*)aDBParam+191))
#define usDBpModBus2Baudrate       (*((INT16U*)aDBParam+192))
#define usDBpModBus2Address        (*((INT16U*)aDBParam+193))
#define usDBpCan1Baudrate          (*((INT16U*)aDBParam+194))
#define usDBpCan1Address           (*((INT16U*)aDBParam+195))
#define usDBpCan2Baudrate          (*((INT16U*)aDBParam+196))
#define usDBpCan2Address           (*((INT16U*)aDBParam+197))
#define usDBpCanLoadPrsntToStart   (*((INT16U*)aDBParam+198))
#define usDBpCanLoadPrsntStartDly  (*((INT16U*)aDBParam+199))
#define usDBpCanLoadPrsntToStop    (*((INT16U*)aDBParam+200))
#define usDBpCanLoadPrsntStopDly   (*((INT16U*)aDBParam+201))
#define usDBpCanBackup1            (*((INT16U*)aDBParam+202))
#define usDBpCanBackup2            (*((INT16U*)aDBParam+203))
#define usDBpCanBackup3            (*((INT16U*)aDBParam+204))
#define usDBpCanBackup4            (*((INT16U*)aDBParam+205))

/* **************** Part 7: Monitoring & Warn ************************* */
#define usDBpMntrCoolTempToWarn    (*((INT16U*)aDBParam+206))
#define usDBpMntrCoolTempWarnDly   (*((INT16U*)aDBParam+207))
#define usDBpMntrCoolTempToStop    (*((INT16U*)aDBParam+208))
#define usDBpMntrCoolTempStopDly   (*((INT16U*)aDBParam+209))
#define usDBpMntrOilTempToWarn     (*((INT16U*)aDBParam+210))
#define usDBpMntrOilTempWarnDly    (*((INT16U*)aDBParam+211))
#define usDBpMntrOilTempToStop     (*((INT16U*)aDBParam+212))
#define usDBpMntrOilTempStopDly    (*((INT16U*)aDBParam+213))
#define usDBpMntrOilPresToWarn     (*((INT16U*)aDBParam+214))
#define usDBpMntrOilPresWarnDly    (*((INT16U*)aDBParam+215))
#define usDBpMntrOilPresToStop     (*((INT16U*)aDBParam+216))
#define usDBpMntrOilPresStopDly    (*((INT16U*)aDBParam+217))
#define usDBpMntrOilPresStartDly   (*((INT16U*)aDBParam+218))
#define usDBpMntrFuelLevelToWarn   (*((INT16U*)aDBParam+219))
#define usDBpMntrFuelLevelWarnDly  (*((INT16U*)aDBParam+220))
#define usDBpMntrCoolLevelToWarn   (*((INT16U*)aDBParam+221))
#define usDBpMntrCoolLevelWarnDly  (*((INT16U*)aDBParam+222))
#define usDBpMntrBatt1VoltToWarn   (*((INT16U*)aDBParam+223))
#define usDBpMntrBatt1VoltWarnDly  (*((INT16U*)aDBParam+224))
#define usDBpMntrBatt2VoltToWarn   (*((INT16U*)aDBParam+225))
#define usDBpMntrBatt2VoltWarnDly  (*((INT16U*)aDBParam+226))
#define usDBpMntrChargVoltToWarn   (*((INT16U*)aDBParam+227))
#define usDBpMntrChargVoltWarnDly  (*((INT16U*)aDBParam+228))
#define usDBpMntrChargVoltStartDly (*((INT16U*)aDBParam+229))
#define usDBpMntrAirFilterWarnDly  (*((INT16U*)aDBParam+230))
#define usDBpMntrBackup1           (*((INT16U*)aDBParam+231))
#define usDBpMntrBackup2           (*((INT16U*)aDBParam+232))
#define usDBpMntrBackup3           (*((INT16U*)aDBParam+233))

/* **************** Part 8: Maintenance Parameters ******************** */
#define usDBpMaintenance           (*((INT16U*)aDBParam+234))
#define usDBpMaintenanceBackup1    (*((INT16U*)aDBParam+235))
#define usDBpMaintenanceBackup2    (*((INT16U*)aDBParam+236))
#define usDBpMaintenanceBackup3    (*((INT16U*)aDBParam+237))
#define usDBpMaintenanceBackup4    (*((INT16U*)aDBParam+238))
#define usDBpMaintenanceBackup5    (*((INT16U*)aDBParam+239))

/* **************** Part 9: Electric Parameters *********************** */
#define usDBpAdcAmpMainVoltA       (*((INT16U*)aDBParam+240))
#define usDBpAdcAmpMainVoltB       (*((INT16U*)aDBParam+241))
#define usDBpAdcAmpMainVoltC       (*((INT16U*)aDBParam+242))
#define usDBpAdcAmpMainVoltAB      (*((INT16U*)aDBParam+243))
#define usDBpAdcAmpMainVoltBC      (*((INT16U*)aDBParam+244))
#define usDBpAdcAmpMainVoltCA      (*((INT16U*)aDBParam+245))
#define usDBpAdcAmpMainCurrA       (*((INT16U*)aDBParam+246))
#define usDBpAdcAmpMainCurrB       (*((INT16U*)aDBParam+247))
#define usDBpAdcAmpMainCurrC       (*((INT16U*)aDBParam+248))
#define usDBpAdcAmpMainCurrGnd     (*((INT16U*)aDBParam+249))
#define usDBpAdcAmpGensVoltA       (*((INT16U*)aDBParam+250))
#define usDBpAdcAmpGensVoltB       (*((INT16U*)aDBParam+251))
#define usDBpAdcAmpGensVoltC       (*((INT16U*)aDBParam+252))
#define usDBpAdcAmpGensVoltAB      (*((INT16U*)aDBParam+253))
#define usDBpAdcAmpGensVoltBC      (*((INT16U*)aDBParam+254))
#define usDBpAdcAmpGensVoltCA      (*((INT16U*)aDBParam+255))
#define usDBpAdcAmpGensCurrA       (*((INT16U*)aDBParam+256))
#define usDBpAdcAmpGensCurrB       (*((INT16U*)aDBParam+257))
#define usDBpAdcAmpGensCurrC       (*((INT16U*)aDBParam+258))
#define usDBpAdcAmpGensCurrGnd     (*((INT16U*)aDBParam+259))
#define usDBpAdcChFilter0          (*((INT16U*)aDBParam+260))
#define usDBpAdcChFilter1          (*((INT16U*)aDBParam+261))
#define usDBpAdcChFilter2          (*((INT16U*)aDBParam+262))
#define usDBpAdcChFilter3          (*((INT16U*)aDBParam+263))
#define usDBpAdcChFilter4          (*((INT16U*)aDBParam+264))
#define usDBpAdcChFilter5          (*((INT16U*)aDBParam+265))
#define usDBpAdcChFilter6          (*((INT16U*)aDBParam+266))
#define usDBpAdcChFilter7          (*((INT16U*)aDBParam+267))
#define usDBpAdcChFilter8          (*((INT16U*)aDBParam+268))
#define usDBpAdcChFilter9          (*((INT16U*)aDBParam+269))
#define usDBpAdcChFilter10         (*((INT16U*)aDBParam+270))
#define usDBpAdcChFilter11         (*((INT16U*)aDBParam+271))
#define usDBpAdcChFilter12         (*((INT16U*)aDBParam+272))
#define usDBpAdcChFilter13         (*((INT16U*)aDBParam+273))
#define usDBpAdcChFilter14         (*((INT16U*)aDBParam+274))
#define usDBpAdcChFilter15         (*((INT16U*)aDBParam+275))
#define usDBpAdcChRef0             (*((INT16U*)aDBParam+276))
#define usDBpAdcChRef1             (*((INT16U*)aDBParam+277))
#define usDBpAdcChRef2             (*((INT16U*)aDBParam+278))
#define usDBpAdcChRef3             (*((INT16U*)aDBParam+279))
#define usDBpAdcChRef4             (*((INT16U*)aDBParam+280))
#define usDBpAdcChRef5             (*((INT16U*)aDBParam+281))
#define usDBpAdcChRef6             (*((INT16U*)aDBParam+282))
#define usDBpAdcChRef7             (*((INT16U*)aDBParam+283))
#define usDBpAdcChRef8             (*((INT16U*)aDBParam+284))
#define usDBpAdcChRef9             (*((INT16U*)aDBParam+285))
#define usDBpAdcChRef10            (*((INT16U*)aDBParam+286))
#define usDBpAdcChRef11            (*((INT16U*)aDBParam+287))
#define usDBpAdcChRef12            (*((INT16U*)aDBParam+288))
#define usDBpAdcChRef13            (*((INT16U*)aDBParam+289))
#define usDBpAdcChRef14            (*((INT16U*)aDBParam+290))
#define usDBpAdcChRef15            (*((INT16U*)aDBParam+291))
#define usDBpAdcBackup1            (*((INT16U*)aDBParam+292))
#define usDBpAdcBackup2            (*((INT16U*)aDBParam+293))
#define usDBpAdcBackup3            (*((INT16U*)aDBParam+294))
#define usDBpAdcBackup4            (*((INT16U*)aDBParam+295))

/* **************** Part 10: Switch Assignment ************************ */
#define usDBpDinAssigEngineStop    (*((INT16U*)aDBParam+296))
#define usDBpDinAssigEngineStart   (*((INT16U*)aDBParam+297))
#define usDBpDinAssigOilPump       (*((INT16U*)aDBParam+298))
#define usDBpDinAssigHeater        (*((INT16U*)aDBParam+299))
#define usDBpDinAssigMainFeedback  (*((INT16U*)aDBParam+300))
#define usDBpDinAssigGensFeedback  (*((INT16U*)aDBParam+301))
#define usDBpDinAssigOilTemp       (*((INT16U*)aDBParam+302))
#define usDBpDinAssigFuelLevel     (*((INT16U*)aDBParam+303))
#define usDBpDinAssigOilPressure   (*((INT16U*)aDBParam+304))
#define usDBpDinAssigCoolantTemp   (*((INT16U*)aDBParam+305))
#define usDBpDinAssigCoolantLevel  (*((INT16U*)aDBParam+306))
#define usDBpDinAssigAirFilter     (*((INT16U*)aDBParam+307))
#define usDBpDinAssigEmergStop     (*((INT16U*)aDBParam+308))
#define usDBpDinBackup1            (*((INT16U*)aDBParam+309))
#define usDBpDinBackup2            (*((INT16U*)aDBParam+310))
#define usDBpDinBackup3            (*((INT16U*)aDBParam+311))
#define usDBpDinBackup4            (*((INT16U*)aDBParam+312))
#define usDBpDinBackup5            (*((INT16U*)aDBParam+313))
#define usDBpDinBackup6            (*((INT16U*)aDBParam+314))
#define usDBpDinBackup7            (*((INT16U*)aDBParam+315))
#define usDBpDinBackup8            (*((INT16U*)aDBParam+316))
#define usDBpDinBackup9            (*((INT16U*)aDBParam+317))
#define usDBpDinBackup10           (*((INT16U*)aDBParam+318))
#define usDBpDinBackup11           (*((INT16U*)aDBParam+319))

/* **************** Part 11: Sensor Assignment ************************ */
#define usDBpAinCoolTempAssign     (*((INT16U*)aDBParam+320))
#define usDBpAinCoolTempSenType    (*((INT16U*)aDBParam+321))
#define usDBpAinCoolTempSubst      (*((INT16U*)aDBParam+322))
#define usDBpAinCoolTempErrLow     (*((INT16U*)aDBParam+323))
#define usDBpAinCoolTempErrHigh    (*((INT16U*)aDBParam+324))
#define usDBpAinOilTempAssign      (*((INT16U*)aDBParam+325))
#define usDBpAinOilTempSenType     (*((INT16U*)aDBParam+326))
#define usDBpAinOilTempSubst       (*((INT16U*)aDBParam+327))
#define usDBpAinOilTempErrLow      (*((INT16U*)aDBParam+328))
#define usDBpAinOilTempErrHigh     (*((INT16U*)aDBParam+329))
#define usDBpAinOilPresAssign      (*((INT16U*)aDBParam+330))
#define usDBpAinOilPresSenType     (*((INT16U*)aDBParam+331))
#define usDBpAinOilPresSubst       (*((INT16U*)aDBParam+332))
#define usDBpAinOilPresErrLow      (*((INT16U*)aDBParam+333))
#define usDBpAinOilPresErrHigh     (*((INT16U*)aDBParam+334))
#define usDBpAinFuelLevelAssign    (*((INT16U*)aDBParam+335))
#define usDBpAinFuelLevelSenType   (*((INT16U*)aDBParam+336))
#define usDBpAinFuelLevelSubst     (*((INT16U*)aDBParam+337))
#define usDBpAinFuelLevelErrLow    (*((INT16U*)aDBParam+338))
#define usDBpAinFuelLevelErrHigh   (*((INT16U*)aDBParam+339))
#define usDBpAinCoolLevelAssign    (*((INT16U*)aDBParam+340))
#define usDBpAinCoolLevelSenType   (*((INT16U*)aDBParam+341))
#define usDBpAinCoolLevelSubst     (*((INT16U*)aDBParam+342))
#define usDBpAinCoolLevelErrLow    (*((INT16U*)aDBParam+343))
#define usDBpAinCoolLevelErrHigh   (*((INT16U*)aDBParam+344))
#define usDBpAinChargCurrAssign    (*((INT16U*)aDBParam+345))
#define usDBpAinChargCurrSubst     (*((INT16U*)aDBParam+346))
#define usDBpAinChargCurrErrLow    (*((INT16U*)aDBParam+347))
#define usDBpAinChargCurrErrHigh   (*((INT16U*)aDBParam+348))
#define usDBpAinChargCurrRefLow    (*((INT16U*)aDBParam+349))
#define usDBpAinChargCurrRefHigh   (*((INT16U*)aDBParam+350))
#define usDBpAinChargCurrAdcLow    (*((INT16U*)aDBParam+351))
#define usDBpAinChargCurrAdcHigh   (*((INT16U*)aDBParam+352))
#define usDBpAinBackup1            (*((INT16U*)aDBParam+353))
#define usDBpAinBackup2            (*((INT16U*)aDBParam+354))
#define usDBpAinBackup3            (*((INT16U*)aDBParam+355))
#define usDBpAinBackup4            (*((INT16U*)aDBParam+356))
#define usDBpAinBackup5            (*((INT16U*)aDBParam+357))
#define usDBpAinBackup6            (*((INT16U*)aDBParam+358))
#define usDBpAinBackup7            (*((INT16U*)aDBParam+359))

/* **************** Part 12: Output Calibration *********************** */
#define usDBpDout1Assign           (*((INT16U*)aDBParam+360))
#define usDBpDout2Assign           (*((INT16U*)aDBParam+361))
#define usDBpDout3Assign           (*((INT16U*)aDBParam+362))
#define usDBpDout4Assign           (*((INT16U*)aDBParam+363))
#define usDBpDout5Assign           (*((INT16U*)aDBParam+364))
#define usDBpDout6Assign           (*((INT16U*)aDBParam+365))
#define usDBpDout7Assign           (*((INT16U*)aDBParam+366))
#define usDBpDout8Assign           (*((INT16U*)aDBParam+367))
#define usDBpDout9Assign           (*((INT16U*)aDBParam+368))
#define usDBpDout10Assign          (*((INT16U*)aDBParam+369))
#define usDBpDout11Assign          (*((INT16U*)aDBParam+370))
#define usDBpDout12Assign          (*((INT16U*)aDBParam+371))
#define usDBpDout13Assign          (*((INT16U*)aDBParam+372))
#define usDBpDout14Assign          (*((INT16U*)aDBParam+373))
#define usDBpDout15Assign          (*((INT16U*)aDBParam+374))
#define usDBpDout16Assign          (*((INT16U*)aDBParam+375))
#define usDBpPWMOut1Assign         (*((INT16U*)aDBParam+376))
#define usDBpPWMOut1RefLow         (*((INT16U*)aDBParam+377))
#define usDBpPWMOut1RefHigh        (*((INT16U*)aDBParam+378))
#define usDBpPWMOut1DutyLow        (*((INT16U*)aDBParam+379))
#define usDBpPWMOut1DutyHigh       (*((INT16U*)aDBParam+380))
#define usDBpPWMOut1Period         (*((INT16U*)aDBParam+381))
#define usDBpPWMOut2Assign         (*((INT16U*)aDBParam+382))
#define usDBpPWMOut2RefLow         (*((INT16U*)aDBParam+383))
#define usDBpPWMOut2RefHigh        (*((INT16U*)aDBParam+384))
#define usDBpPWMOut2DutyLow        (*((INT16U*)aDBParam+385))
#define usDBpPWMOut2DutyHigh       (*((INT16U*)aDBParam+386))
#define usDBpPWMOut2Period         (*((INT16U*)aDBParam+387))
#define usDBpPWMOut3Assign         (*((INT16U*)aDBParam+388))
#define usDBpPWMOut3RefLow         (*((INT16U*)aDBParam+389))
#define usDBpPWMOut3RefHigh        (*((INT16U*)aDBParam+390))
#define usDBpPWMOut3DutyLow        (*((INT16U*)aDBParam+391))
#define usDBpPWMOut3DutyHigh       (*((INT16U*)aDBParam+392))
#define usDBpPWMOut3Period         (*((INT16U*)aDBParam+393))
#define usDBpPWMOut4Assign         (*((INT16U*)aDBParam+394))
#define usDBpPWMOut4RefLow         (*((INT16U*)aDBParam+395))
#define usDBpPWMOut4RefHigh        (*((INT16U*)aDBParam+396))
#define usDBpPWMOut4DutyLow        (*((INT16U*)aDBParam+397))
#define usDBpPWMOut4DutyHigh       (*((INT16U*)aDBParam+398))
#define usDBpPWMOut4Period         (*((INT16U*)aDBParam+399))

/* **************** Part 13: Reserved ********************************* */
#define usDBpReserved0             (*((INT16U*)aDBParam+400))
#define usDBpReserved1             (*((INT16U*)aDBParam+401))
#define usDBpReserved2             (*((INT16U*)aDBParam+402))
#define usDBpReserved3             (*((INT16U*)aDBParam+403))
#define usDBpReserved4             (*((INT16U*)aDBParam+404))
#define usDBpReserved5             (*((INT16U*)aDBParam+405))
#define usDBpReserved6             (*((INT16U*)aDBParam+406))
#define usDBpReserved7             (*((INT16U*)aDBParam+407))
#define usDBpReserved8             (*((INT16U*)aDBParam+408))
#define usDBpReserved9             (*((INT16U*)aDBParam+409))
#define usDBpReserved10            (*((INT16U*)aDBParam+410))
#define usDBpReserved11            (*((INT16U*)aDBParam+411))
#define usDBpReserved12            (*((INT16U*)aDBParam+412))
#define usDBpReserved13            (*((INT16U*)aDBParam+413))
#define usDBpReserved14            (*((INT16U*)aDBParam+414))
#define usDBpReserved15            (*((INT16U*)aDBParam+415))
#define usDBpReserved16            (*((INT16U*)aDBParam+416))
#define usDBpReserved17            (*((INT16U*)aDBParam+417))
#define usDBpReserved18            (*((INT16U*)aDBParam+418))
#define usDBpReserved19            (*((INT16U*)aDBParam+419))
#define usDBpReserved20            (*((INT16U*)aDBParam+420))
#define usDBpReserved21            (*((INT16U*)aDBParam+421))
#define usDBpReserved22            (*((INT16U*)aDBParam+422))
#define usDBpReserved23            (*((INT16U*)aDBParam+423))
#define usDBpReserved24            (*((INT16U*)aDBParam+424))
#define usDBpReserved25            (*((INT16U*)aDBParam+425))
#define usDBpReserved26            (*((INT16U*)aDBParam+426))
#define usDBpReserved27            (*((INT16U*)aDBParam+427))
#define usDBpReserved28            (*((INT16U*)aDBParam+428))
#define usDBpReserved29            (*((INT16U*)aDBParam+429))
#define usDBpReserved30            (*((INT16U*)aDBParam+430))
#define usDBpReserved31            (*((INT16U*)aDBParam+431))
#define usDBpReserved32            (*((INT16U*)aDBParam+432))
#define usDBpReserved33            (*((INT16U*)aDBParam+433))
#define usDBpReserved34            (*((INT16U*)aDBParam+434))
#define usDBpReserved35            (*((INT16U*)aDBParam+435))
#define usDBpReserved36            (*((INT16U*)aDBParam+436))
#define usDBpReserved37            (*((INT16U*)aDBParam+437))
#define usDBpReserved38            (*((INT16U*)aDBParam+438))
#define usDBpReserved39            (*((INT16U*)aDBParam+439))
#define usDBpReserved40            (*((INT16U*)aDBParam+440))
#define usDBpReserved41            (*((INT16U*)aDBParam+441))
#define usDBpReserved42            (*((INT16U*)aDBParam+442))
#define usDBpReserved43            (*((INT16U*)aDBParam+443))
#define usDBpReserved44            (*((INT16U*)aDBParam+444))
#define usDBpReserved45            (*((INT16U*)aDBParam+445))
#define usDBpReserved46            (*((INT16U*)aDBParam+446))
#define usDBpReserved47            (*((INT16U*)aDBParam+447))
#define usDBpReserved48            (*((INT16U*)aDBParam+448))
#define usDBpReserved49            (*((INT16U*)aDBParam+449))
#define usDBpReserved50            (*((INT16U*)aDBParam+450))
#define usDBpReserved51            (*((INT16U*)aDBParam+451))
#define usDBpReserved52            (*((INT16U*)aDBParam+452))
#define usDBpReserved53            (*((INT16U*)aDBParam+453))
#define usDBpReserved54            (*((INT16U*)aDBParam+454))
#define usDBpReserved55            (*((INT16U*)aDBParam+455))
#define usDBpReserved56            (*((INT16U*)aDBParam+456))
#define usDBpReserved57            (*((INT16U*)aDBParam+457))
#define usDBpReserved58            (*((INT16U*)aDBParam+458))
#define usDBpReserved59            (*((INT16U*)aDBParam+459))
#define usDBpReserved60            (*((INT16U*)aDBParam+460))
#define usDBpReserved61            (*((INT16U*)aDBParam+461))
#define usDBpReserved62            (*((INT16U*)aDBParam+462))
#define usDBpReserved63            (*((INT16U*)aDBParam+463))
#define usDBpReserved64            (*((INT16U*)aDBParam+464))
#define usDBpReserved65            (*((INT16U*)aDBParam+465))
#define usDBpReserved66            (*((INT16U*)aDBParam+466))
#define usDBpReserved67            (*((INT16U*)aDBParam+467))
#define usDBpReserved68            (*((INT16U*)aDBParam+468))
#define usDBpReserved69            (*((INT16U*)aDBParam+469))
#define usDBpReserved70            (*((INT16U*)aDBParam+470))
#define usDBpReserved71            (*((INT16U*)aDBParam+471))
#define usDBpReserved72            (*((INT16U*)aDBParam+472))
#define usDBpReserved73            (*((INT16U*)aDBParam+473))
#define usDBpReserved74            (*((INT16U*)aDBParam+474))
#define usDBpReserved75            (*((INT16U*)aDBParam+475))
#define usDBpReserved76            (*((INT16U*)aDBParam+476))
#define usDBpReserved77            (*((INT16U*)aDBParam+477))
#define usDBpReserved78            (*((INT16U*)aDBParam+478))
#define usDBpReserved79            (*((INT16U*)aDBParam+479))

/* ******************************************************************** */
/*                     GEC7800 Function Definition                      */
/* ******************************************************************** */
/* **************** Part 1: Grid Electric Functions ******************* */
#define usDBfMainVoltErrAct        (*((INT16U*)aDBFunct+  0))
#define usDBfMainFreqErrAct        (*((INT16U*)aDBFunct+  1))
#define usDBfMainPhaseErrAct       (*((INT16U*)aDBFunct+  2))
#define usDBfMainCurrShortErrAct   (*((INT16U*)aDBFunct+  3))
#define usDBfMainCurrLongErrAct    (*((INT16U*)aDBFunct+  4))
#define usDBfMainCurrGndErrAct     (*((INT16U*)aDBFunct+  5))
#define usDBfMainCurrUnbErrAct     (*((INT16U*)aDBFunct+  6))
#define usDBfMainActPwrErrAct      (*((INT16U*)aDBFunct+  7))
#define usDBfMainReactPwrErrAct    (*((INT16U*)aDBFunct+  8))
#define usDBfMainAppPwrErrAct      (*((INT16U*)aDBFunct+  9))
#define usDBfMainRocofErrAct       (*((INT16U*)aDBFunct+ 10))
#define usDBfMainVoltUnbErrAct     (*((INT16U*)aDBFunct+ 11))
#define usDBfMainBackup1           (*((INT16U*)aDBFunct+ 12))
#define usDBfMainBackup2           (*((INT16U*)aDBFunct+ 13))

/* **************** Part 2: Generator Setpint Functions *************** */
#define usDBfGensPhaseErrAct       (*((INT16U*)aDBFunct+ 14))
#define usDBfGensCurrShortErrAct   (*((INT16U*)aDBFunct+ 15))
#define usDBfGensCurrLongErrAct    (*((INT16U*)aDBFunct+ 16))
#define usDBfGensCurrGndErrAct     (*((INT16U*)aDBFunct+ 17))
#define usDBfGensCurrUnbErrAct     (*((INT16U*)aDBFunct+ 18))
#define usDBfGensActPwrErrAct      (*((INT16U*)aDBFunct+ 19))
#define usDBfGensReactPwrErrAct    (*((INT16U*)aDBFunct+ 20))
#define usDBfGensAppPwrErrAct      (*((INT16U*)aDBFunct+ 21))
#define usDBfGensInvPwrErrAct      (*((INT16U*)aDBFunct+ 22))
#define usDBfGensFactorErrAct      (*((INT16U*)aDBFunct+ 23))
#define usDBfGensMagLostErrAct     (*((INT16U*)aDBFunct+ 24))
#define usDBfGensBackup1           (*((INT16U*)aDBFunct+ 25))
#define usDBfGensBackup2           (*((INT16U*)aDBFunct+ 26))
#define usDBfGensBackup3           (*((INT16U*)aDBFunct+ 27))

/* **************** Part 3: Engine Setpint Functions ****************** */
#define usDBfEngSpeedDeltaErrAct   (*((INT16U*)aDBFunct+ 28))
#define usDBfEngHeaterOn           (*((INT16U*)aDBFunct+ 29))
#define usDBfEngOilPumpOn          (*((INT16U*)aDBFunct+ 30))
#define usDBfEngCoolantFanOn       (*((INT16U*)aDBFunct+ 31))
#define usDBfEngBackup1            (*((INT16U*)aDBFunct+ 32))
#define usDBfEngBackup2            (*((INT16U*)aDBFunct+ 33))

/* **************** Part 4: Timer Setpint Functions ******************* */
#define usDBfAmfMainSwOffBfrStart  (*((INT16U*)aDBFunct+ 34))
#define usDBfAmfSoftUnloadingOn    (*((INT16U*)aDBFunct+ 35))
#define usDBfTimeBackup1           (*((INT16U*)aDBFunct+ 36))
#define usDBfTimeBackup2           (*((INT16U*)aDBFunct+ 37))

/* **************** Part 5: Synchronization & Load share ************** */
#define usDBfSyncBackup1           (*((INT16U*)aDBFunct+ 38))
#define usDBfSyncBackup2           (*((INT16U*)aDBFunct+ 39))
#define usDBfSyncBackup3           (*((INT16U*)aDBFunct+ 40))
#define usDBfSyncBackup4           (*((INT16U*)aDBFunct+ 41))

/* **************** Part 6: CanBus / ModBus *************************** */
#define usDBfCanBackup1            (*((INT16U*)aDBFunct+ 42))
#define usDBfCanBackup2            (*((INT16U*)aDBFunct+ 43))
#define usDBfCanBackup3            (*((INT16U*)aDBFunct+ 44))
#define usDBfCanBackup4            (*((INT16U*)aDBFunct+ 45))

/* **************** Part 7: Monitoring & Warn ************************* */
#define usDBfMntrOilPressCurveOn   (*((INT16U*)aDBFunct+ 46))
#define usDBfMntrBackup1           (*((INT16U*)aDBFunct+ 47))
#define usDBfMntrBackup2           (*((INT16U*)aDBFunct+ 48))
#define usDBfMntrBackup3           (*((INT16U*)aDBFunct+ 49))

/* **************** Part 8: Maintenance Functions ********************* */
#define usDBfMaintenanceStartOn    (*((INT16U*)aDBFunct+ 50))
#define usDBfMaintenanceStartOff   (*((INT16U*)aDBFunct+ 51))
#define usDBfMaintenanceBackup1    (*((INT16U*)aDBFunct+ 52))
#define usDBfMaintenanceBackup2    (*((INT16U*)aDBFunct+ 53))

/* **************** Part 9: Electric Functions ************************ */
#define usDBfAdcRefAutoOrFixed     (*((INT16U*)aDBFunct+ 54))
#define usDBfAdcBackup1            (*((INT16U*)aDBFunct+ 55))
#define usDBfAdcBackup2            (*((INT16U*)aDBFunct+ 56))
#define usDBfAdcBackup3            (*((INT16U*)aDBFunct+ 57))

/* **************** Part 10: Switch Assignment ************************ */
#define usDBfDinPoleEngineStop     (*((INT16U*)aDBFunct+ 58))
#define usDBfDinPoleEngineStart    (*((INT16U*)aDBFunct+ 59))
#define usDBfDinPoleMainFeedback   (*((INT16U*)aDBFunct+ 60))
#define usDBfDinPoleGensFeedback   (*((INT16U*)aDBFunct+ 61))
#define usDBfDinPoleOilPump        (*((INT16U*)aDBFunct+ 62))
#define usDBfDinPoleHeater         (*((INT16U*)aDBFunct+ 63))
#define usDBfDinPoleOilTemp        (*((INT16U*)aDBFunct+ 64))
#define usDBfDinPoleFuelLevel      (*((INT16U*)aDBFunct+ 65))
#define usDBfDinPoleOilPressure    (*((INT16U*)aDBFunct+ 66))
#define usDBfDinPoleCoolantTemp    (*((INT16U*)aDBFunct+ 67))
#define usDBfDinPoleCoolantLevel   (*((INT16U*)aDBFunct+ 68))
#define usDBfDinPoleAirFilter      (*((INT16U*)aDBFunct+ 69))
#define usDBfDinPoleEmergStop      (*((INT16U*)aDBFunct+ 70))
#define usDBfDinBackup1            (*((INT16U*)aDBFunct+ 71))
#define usDBfDinBackup2            (*((INT16U*)aDBFunct+ 72))
#define usDBfDinBackup3            (*((INT16U*)aDBFunct+ 73))
#define usDBfDinBackup4            (*((INT16U*)aDBFunct+ 74))
#define usDBfDinBackup5            (*((INT16U*)aDBFunct+ 75))
#define usDBfDinBackup6            (*((INT16U*)aDBFunct+ 76))
#define usDBfDinBackup7            (*((INT16U*)aDBFunct+ 77))

/* **************** Part 11: Sensor Assignment ************************ */
#define usDBfAinCoolTempSenErrAct  (*((INT16U*)aDBFunct+ 78))
#define usDBfAinOilTempSenErrAct   (*((INT16U*)aDBFunct+ 79))
#define usDBfAinOilPresSenErrAct   (*((INT16U*)aDBFunct+ 80))
#define usDBfAinFuelLevelSenErrAct (*((INT16U*)aDBFunct+ 81))
#define usDBfAinCoolLevelSenErrAct (*((INT16U*)aDBFunct+ 82))
#define usDBfAinChargCurrSenErrAct (*((INT16U*)aDBFunct+ 83))
#define usDBfAinBackup1            (*((INT16U*)aDBFunct+ 84))
#define usDBfAinBackup2            (*((INT16U*)aDBFunct+ 85))

/* **************** Part 12: Output Calibration *********************** */
#define usDBfDout1Pole             (*((INT16U*)aDBFunct+ 86))
#define usDBfDout2Pole             (*((INT16U*)aDBFunct+ 87))
#define usDBfDout3Pole             (*((INT16U*)aDBFunct+ 88))
#define usDBfDout4Pole             (*((INT16U*)aDBFunct+ 89))
#define usDBfDout5Pole             (*((INT16U*)aDBFunct+ 90))
#define usDBfDout6Pole             (*((INT16U*)aDBFunct+ 91))
#define usDBfDout7Pole             (*((INT16U*)aDBFunct+ 92))
#define usDBfDout8Pole             (*((INT16U*)aDBFunct+ 93))
#define usDBfDout9Pole             (*((INT16U*)aDBFunct+ 94))
#define usDBfDout10Pole            (*((INT16U*)aDBFunct+ 95))
#define usDBfDout11Pole            (*((INT16U*)aDBFunct+ 96))
#define usDBfDout12Pole            (*((INT16U*)aDBFunct+ 97))
#define usDBfDout13Pole            (*((INT16U*)aDBFunct+ 98))
#define usDBfDout14Pole            (*((INT16U*)aDBFunct+ 99))
#define usDBfDout15Pole            (*((INT16U*)aDBFunct+100))
#define usDBfDout16Pole            (*((INT16U*)aDBFunct+101))

/* **************** Part 13: Reserved ********************************* */
#define usDBfReserved0             (*((INT16U*)aDBFunct+102))
#define usDBfReserved1             (*((INT16U*)aDBFunct+103))
#define usDBfReserved2             (*((INT16U*)aDBFunct+104))
#define usDBfReserved3             (*((INT16U*)aDBFunct+105))
#define usDBfReserved4             (*((INT16U*)aDBFunct+106))
#define usDBfReserved5             (*((INT16U*)aDBFunct+107))
#define usDBfReserved6             (*((INT16U*)aDBFunct+108))
#define usDBfReserved7             (*((INT16U*)aDBFunct+109))
#define usDBfReserved8             (*((INT16U*)aDBFunct+110))
#define usDBfReserved9             (*((INT16U*)aDBFunct+111))
#define usDBfReserved10            (*((INT16U*)aDBFunct+112))
#define usDBfReserved11            (*((INT16U*)aDBFunct+113))
#define usDBfReserved12            (*((INT16U*)aDBFunct+114))
#define usDBfReserved13            (*((INT16U*)aDBFunct+115))
#define usDBfReserved14            (*((INT16U*)aDBFunct+116))
#define usDBfReserved15            (*((INT16U*)aDBFunct+117))
#define usDBfReserved16            (*((INT16U*)aDBFunct+118))
#define usDBfReserved17            (*((INT16U*)aDBFunct+119))

/* ******************************************************************** */
/*                     GEC7800 Curves Definition                        */
/* ******************************************************************** */
#define aDBcTempMapAdc              ((INT16U*)(aDBCurve+  0))
#define aDBcTempMapTmp              ((INT16U*)(aDBCurve+ 10))
#define aDBcPressMapAdc             ((INT16U*)(aDBCurve+ 20))
#define aDBcPressMapPrs             ((INT16U*)(aDBCurve+ 30))
#define aDBcLevelMapAdc             ((INT16U*)(aDBCurve+ 40))
#define aDBcLevelMapLvl             ((INT16U*)(aDBCurve+ 50))
#define aDBcOilPressWarnSpeed       ((INT16U*)(aDBCurve+ 60))
#define aDBcOilPressWarnPress       ((INT16U*)(aDBCurve+ 70))
#define aDBcOilPressStopSpeed       ((INT16U*)(aDBCurve+ 80))
#define aDBcOilPressStopPress       ((INT16U*)(aDBCurve+ 90))
#define aDBcStatisticSpeed          ((INT16U*)(aDBCurve+100))
#define aDBcStatisticPower          ((INT16U*)(aDBCurve+110))
#define aDBcCurveBackup1            ((INT16U*)(aDBCurve+120))
#define aDBcCurveBackup2            ((INT16U*)(aDBCurve+130))
#define aDBcCurveBackup3            ((INT16U*)(aDBCurve+140))
#define aDBcCurveBackup4            ((INT16U*)(aDBCurve+150))
#define aDBcCurveBackup5            ((INT16U*)(aDBCurve+160))
#define aDBcCurveBackup6            ((INT16U*)(aDBCurve+170))
#define aDBcCurveBackup7            ((INT16U*)(aDBCurve+180))
#define aDBcCurveBackup8            ((INT16U*)(aDBCurve+190))
#define aDBcDataPlate               ((INT16U*)(aDBCurve+200))

/* ******************************************************************** */
/*                        Measurement Definition                        */
/* ******************************************************************** */
/* **************** Part 1: Grid Electric Measurements **************** */
#define usDBmMainVoltAB            (*((INT16U*)aDBMeasu+  0))
#define usDBmMainVoltBC            (*((INT16U*)aDBMeasu+  1))
#define usDBmMainVoltCA            (*((INT16U*)aDBMeasu+  2))
#define usDBmMainVoltA             (*((INT16U*)aDBMeasu+  3))
#define usDBmMainVoltB             (*((INT16U*)aDBMeasu+  4))
#define usDBmMainVoltC             (*((INT16U*)aDBMeasu+  5))
#define usDBmMainPhaseAB           (*((INT16U*)aDBMeasu+  6))
#define usDBmMainPhaseBC           (*((INT16U*)aDBMeasu+  7))
#define usDBmMainPhaseCA           (*((INT16U*)aDBMeasu+  8))
#define usDBmMainFreq              (*((INT16U*)aDBMeasu+  9))
#define usDBmMainCurrA             (*((INT16U*)aDBMeasu+ 10))
#define usDBmMainCurrB             (*((INT16U*)aDBMeasu+ 11))
#define usDBmMainCurrC             (*((INT16U*)aDBMeasu+ 12))
#define usDBmMainCurrGnd           (*((INT16U*)aDBMeasu+ 13))
#define usDBmMainCurrUnb           (*((INT16U*)aDBMeasu+ 14))
#define usDBmMainActPowerA         (*((INT16U*)aDBMeasu+ 15))
#define usDBmMainActPowerB         (*((INT16U*)aDBMeasu+ 16))
#define usDBmMainActPowerC         (*((INT16U*)aDBMeasu+ 17))
#define usDBmMainActPowerAll       (*((INT16U*)aDBMeasu+ 18))
#define usDBmMainInvPowerAll       (*((INT16U*)aDBMeasu+ 19))
#define usDBmMainReactPowerA       (*((INT16U*)aDBMeasu+ 20))
#define usDBmMainReactPowerB       (*((INT16U*)aDBMeasu+ 21))
#define usDBmMainReactPowerC       (*((INT16U*)aDBMeasu+ 22))
#define usDBmMainReactPowerAll     (*((INT16U*)aDBMeasu+ 23))
#define usDBmMainAppPowerA         (*((INT16U*)aDBMeasu+ 24))
#define usDBmMainAppPowerB         (*((INT16U*)aDBMeasu+ 25))
#define usDBmMainAppPowerC         (*((INT16U*)aDBMeasu+ 26))
#define usDBmMainAppPowerAll       (*((INT16U*)aDBMeasu+ 27))
#define usDBmMainPowerFactorA      (*((INT16U*)aDBMeasu+ 28))
#define usDBmMainPowerFactorB      (*((INT16U*)aDBMeasu+ 29))
#define usDBmMainPowerFactorC      (*((INT16U*)aDBMeasu+ 30))
#define usDBmMainPowerFactorAll    (*((INT16U*)aDBMeasu+ 31))
#define usDBmMainRocof             (*((INT16U*)aDBMeasu+ 32))
#define usDBmMainVoltUnb           (*((INT16U*)aDBMeasu+ 33))
#define usDBmMainVoltReadyToSyn    (*((INT16U*)aDBMeasu+ 34))
#define usDBmMainVoltIsNormal      (*((INT16U*)aDBMeasu+ 35))
#define usDBmMainVoltIsLost        (*((INT16U*)aDBMeasu+ 36))
#define usDBmMainBackup1           (*((INT16U*)aDBMeasu+ 37))
#define usDBmMainBackup2           (*((INT16U*)aDBMeasu+ 38))
#define usDBmMainBackup3           (*((INT16U*)aDBMeasu+ 39))

/* **************** Part 2: Gens Electric Measurements **************** */
#define usDBmGensVoltAB            (*((INT16U*)aDBMeasu+ 40))
#define usDBmGensVoltBC            (*((INT16U*)aDBMeasu+ 41))
#define usDBmGensVoltCA            (*((INT16U*)aDBMeasu+ 42))
#define usDBmGensVoltA             (*((INT16U*)aDBMeasu+ 43))
#define usDBmGensVoltB             (*((INT16U*)aDBMeasu+ 44))
#define usDBmGensVoltC             (*((INT16U*)aDBMeasu+ 45))
#define usDBmGensPhaseAB           (*((INT16U*)aDBMeasu+ 46))
#define usDBmGensPhaseBC           (*((INT16U*)aDBMeasu+ 47))
#define usDBmGensPhaseCA           (*((INT16U*)aDBMeasu+ 48))
#define usDBmGensFreq              (*((INT16U*)aDBMeasu+ 49))
#define usDBmGensCurrA             (*((INT16U*)aDBMeasu+ 50))
#define usDBmGensCurrB             (*((INT16U*)aDBMeasu+ 51))
#define usDBmGensCurrC             (*((INT16U*)aDBMeasu+ 52))
#define usDBmGensCurrGnd           (*((INT16U*)aDBMeasu+ 53))
#define usDBmGensCurrUnb           (*((INT16U*)aDBMeasu+ 54))
#define usDBmGensActPowerA         (*((INT16U*)aDBMeasu+ 55))
#define usDBmGensActPowerB         (*((INT16U*)aDBMeasu+ 56))
#define usDBmGensActPowerC         (*((INT16U*)aDBMeasu+ 57))
#define usDBmGensActPowerAll       (*((INT16U*)aDBMeasu+ 58))
#define usDBmGensInvPowerAll       (*((INT16U*)aDBMeasu+ 59))
#define usDBmGensReactPowerA       (*((INT16U*)aDBMeasu+ 60))
#define usDBmGensReactPowerB       (*((INT16U*)aDBMeasu+ 61))
#define usDBmGensReactPowerC       (*((INT16U*)aDBMeasu+ 62))
#define usDBmGensReactPowerAll     (*((INT16U*)aDBMeasu+ 63))
#define usDBmGensAppPowerA         (*((INT16U*)aDBMeasu+ 64))
#define usDBmGensAppPowerB         (*((INT16U*)aDBMeasu+ 65))
#define usDBmGensAppPowerC         (*((INT16U*)aDBMeasu+ 66))
#define usDBmGensAppPowerAll       (*((INT16U*)aDBMeasu+ 67))
#define usDBmGensPowerFactorA      (*((INT16U*)aDBMeasu+ 68))
#define usDBmGensPowerFactorB      (*((INT16U*)aDBMeasu+ 69))
#define usDBmGensPowerFactorC      (*((INT16U*)aDBMeasu+ 70))
#define usDBmGensPowerFactorAll    (*((INT16U*)aDBMeasu+ 71))
#define usDBmGensMagLost           (*((INT16U*)aDBMeasu+ 72))
#define usDBmGensIsWorking         (*((INT16U*)aDBMeasu+ 73))
#define usDBmGensIsReadyToLoad     (*((INT16U*)aDBMeasu+ 74))
#define usDBmGensBackup1           (*((INT16U*)aDBMeasu+ 75))
#define usDBmGensBackup2           (*((INT16U*)aDBMeasu+ 76))
#define usDBmGensBackup3           (*((INT16U*)aDBMeasu+ 77))
#define usDBmGensBackup4           (*((INT16U*)aDBMeasu+ 78))
#define usDBmGensBackup5           (*((INT16U*)aDBMeasu+ 79))

/* **************** Part 3: Engine Measurements *********************** */
#define usDBmEngSpeed              (*((INT16U*)aDBMeasu+ 80))
#define usDBmEngSpeedPickup1       (*((INT16U*)aDBMeasu+ 81))
#define usDBmEngSpeedPickup2       (*((INT16U*)aDBMeasu+ 82))
#define usDBmEngEngineIsStopped    (*((INT16U*)aDBMeasu+ 83))
#define usDBmEngEngineIsRunning    (*((INT16U*)aDBMeasu+ 84))
#define usDBmEngEngineIsIdling     (*((INT16U*)aDBMeasu+ 85))
#define usDBmEngEngineIsRated      (*((INT16U*)aDBMeasu+ 86))
#define usDBmEngStartFailTimes     (*((INT16U*)aDBMeasu+ 87))
#define usDBmEngStarterOutput      (*((INT16U*)aDBMeasu+ 88))
#define usDBmEngHeaterDuration     (*((INT16U*)aDBMeasu+ 89))
#define usDBmEngHeaterOutput       (*((INT16U*)aDBMeasu+ 90))
#define usDBmEngOilPumpOutput      (*((INT16U*)aDBMeasu+ 91))
#define usDBmEngCoolFanOutput      (*((INT16U*)aDBMeasu+ 92))
#define usDBmEngFuelSupplyOutput   (*((INT16U*)aDBMeasu+ 93))
#define usDBmEngSpeedRatedOutput   (*((INT16U*)aDBMeasu+ 94))
#define usDBmEngBackup1            (*((INT16U*)aDBMeasu+ 95))
#define usDBmEngBackup2            (*((INT16U*)aDBMeasu+ 96))
#define usDBmEngBackup3            (*((INT16U*)aDBMeasu+ 97))

/* **************** Part 4: Time/Sys Measurements ********************* */
#define usDBmSystemPhase           (*((INT16U*)aDBMeasu+ 98))
#define usDBmSysEmergnErrToStop    (*((INT16U*)aDBMeasu+ 99))
#define usDBmSysEmergnCmdToStop    (*((INT16U*)aDBMeasu+100))
#define usDBmSysCommonErrToStop    (*((INT16U*)aDBMeasu+101))
#define usDBmSysCommonErrToWarn    (*((INT16U*)aDBMeasu+102))
#define usDBmSysCommonCmdToStop    (*((INT16U*)aDBMeasu+103))
#define usDBmSysCommonCmdToStart   (*((INT16U*)aDBMeasu+104))
#define usDBmSysCommonCmdToSwOn    (*((INT16U*)aDBMeasu+105))
#define usDBmSysAutoOrManual       (*((INT16U*)aDBMeasu+106))
#define usDBmSysMainSwOnCndt       (*((INT16U*)aDBMeasu+107))
#define usDBmSysMainSwCtrl         (*((INT16U*)aDBMeasu+108))
#define usDBmSysMainSwOnOutput     (*((INT16U*)aDBMeasu+109))
#define usDBmSysMainSwOffOutput    (*((INT16U*)aDBMeasu+110))
#define usDBmSysGensSwOnCndt       (*((INT16U*)aDBMeasu+111))
#define usDBmSysGensSwCtrl         (*((INT16U*)aDBMeasu+112))
#define usDBmSysGensSwOnOutput     (*((INT16U*)aDBMeasu+113))
#define usDBmSysGensSwOffOutput    (*((INT16U*)aDBMeasu+114))
#define usDBmSysBackup1            (*((INT16U*)aDBMeasu+115))

/* **************** Part 5: Synchronization & Load share ************** */
#define ssDBmSyncVoltDiffer        (*((INT16S*)aDBMeasu+116))
#define ssDBmSyncFreqDiffer        (*((INT16S*)aDBMeasu+117))
#define ssDBmSyncPhaseDiffer       (*((INT16S*)aDBMeasu+118))
#define usDBmSyncConditionMatch    (*((INT16U*)aDBMeasu+119))
#define usDBmSyncLoadCtrlMode      (*((INT16U*)aDBMeasu+120))
#define usDBmSyncLoadGovCtrl       (*((INT16U*)aDBMeasu+121))
#define usDBmSyncLoadAvrCtrl       (*((INT16U*)aDBMeasu+122))
#define usDBmLoadActPwrSelect      (*((INT16U*)aDBMeasu+123))
#define usDBmLoadActPwrSetp        (*((INT16U*)aDBMeasu+124))
#define usDBmLoadRctPwrSelect      (*((INT16U*)aDBMeasu+125))
#define usDBmLoadRctPwrSetp        (*((INT16U*)aDBMeasu+126))
#define usDBmSyncBackup1           (*((INT16U*)aDBMeasu+127))
#define usDBmSyncBackup2           (*((INT16U*)aDBMeasu+128))
#define usDBmSyncBackup3           (*((INT16U*)aDBMeasu+129))

/* **************** Part 6: CanBus / ModBus *************************** */
#define usDBmModBus1State          (*((INT16U*)aDBMeasu+130))
#define usDBmModBus2State          (*((INT16U*)aDBMeasu+131))
#define usDBmCan1State             (*((INT16U*)aDBMeasu+132))
#define usDBmCan2State             (*((INT16U*)aDBMeasu+133))
#define usDBmCanSchedIsAlone       (*((INT16U*)aDBMeasu+134))
#define usDBmCanSchedIsHighest     (*((INT16U*)aDBMeasu+135))
#define usDBmCanSchedToStop        (*((INT16U*)aDBMeasu+136))
#define usDBmCanSchedToSwitch      (*((INT16U*)aDBMeasu+137))
#define usDBmCanSchedTxEngState    (*((INT16U*)aDBMeasu+138))
#define usDBmCanSchedActIntoPrsnt  (*((INT16U*)aDBMeasu+139))
#define usDBmCanSchedActPrsntSetp  (*((INT16U*)aDBMeasu+140))
#define usDBmCanSchedActPowerSetp  (*((INT16U*)aDBMeasu+141))
#define usDBmCanSchedRctIntoPrsnt  (*((INT16U*)aDBMeasu+142))
#define usDBmCanSchedRctPrsntSetp  (*((INT16U*)aDBMeasu+143))
#define usDBmCanSchedRctPowerSetp  (*((INT16U*)aDBMeasu+144))
#define usDBmCanBackup1            (*((INT16U*)aDBMeasu+145))
#define usDBmCanBackup2            (*((INT16U*)aDBMeasu+146))
#define usDBmCanBackup3            (*((INT16U*)aDBMeasu+147))
#define usDBmCanBackup4            (*((INT16U*)aDBMeasu+148))
#define usDBmCanBackup5            (*((INT16U*)aDBMeasu+149))

/* **************** Part 7: Monitoring & Warn ************************* */
#define usDBmHardwareVersion       (*((INT16U*)aDBMeasu+150))
#define usDBmSoftwareVersion       (*((INT16U*)aDBMeasu+151))
#define usDBmErrorStatus1          (*((INT16U*)aDBMeasu+152))
#define usDBmErrorStatus2          (*((INT16U*)aDBMeasu+153))
#define usDBmErrorStatus3          (*((INT16U*)aDBMeasu+154))
#define usDBmErrorStatus4          (*((INT16U*)aDBMeasu+155))
#define usDBmErrorStatus5          (*((INT16U*)aDBMeasu+156))
#define usDBmErrorStatus6          (*((INT16U*)aDBMeasu+157))
#define usDBmErrorStatus7          (*((INT16U*)aDBMeasu+158))
#define usDBmErrorStatus8          (*((INT16U*)aDBMeasu+159))
#define usDBmErrorStatus9          (*((INT16U*)aDBMeasu+160))
#define usDBmErrorStatus10         (*((INT16U*)aDBMeasu+161))
#define usDBmErrorStatus11         (*((INT16U*)aDBMeasu+162))
#define usDBmErrorStatus12         (*((INT16U*)aDBMeasu+163))
#define usDBmErrorStatus13         (*((INT16U*)aDBMeasu+164))
#define usDBmErrorStatus14         (*((INT16U*)aDBMeasu+165))
#define usDBmErrorStatus15         (*((INT16U*)aDBMeasu+166))
#define usDBmErrorStatus16         (*((INT16U*)aDBMeasu+167))
#define uiDBmErrorStatus1          (*((INT32U*)(&usDBmErrorStatus1)))
#define uiDBmErrorStatus2          (*((INT32U*)(&usDBmErrorStatus3)))
#define uiDBmErrorStatus3          (*((INT32U*)(&usDBmErrorStatus5)))
#define uiDBmErrorStatus4          (*((INT32U*)(&usDBmErrorStatus7)))
#define uiDBmErrorStatus5          (*((INT32U*)(&usDBmErrorStatus9)))
#define uiDBmErrorStatus6          (*((INT32U*)(&usDBmErrorStatus11)))
#define uiDBmErrorStatus7          (*((INT32U*)(&usDBmErrorStatus13)))
#define uiDBmErrorStatus8          (*((INT32U*)(&usDBmErrorStatus15)))

/* **************** Part 8: Maintenance Measurements ****************** */
#define usDBmMaintenanceBackup1    (*((INT16U*)aDBMeasu+168))
#define usDBmMaintenanceBackup2    (*((INT16U*)aDBMeasu+169))

/* **************** Part 9: Electric Measurements ********************* */
#define usDBmAdcInput                ((INT16U*)aDBMeasu+170)
#define usDBmAdcInput0             (*((INT16U*)aDBMeasu+170))
#define usDBmAdcInput1             (*((INT16U*)aDBMeasu+171))
#define usDBmAdcInput2             (*((INT16U*)aDBMeasu+172))
#define usDBmAdcInput3             (*((INT16U*)aDBMeasu+173))
#define usDBmAdcInput4             (*((INT16U*)aDBMeasu+174))
#define usDBmAdcInput5             (*((INT16U*)aDBMeasu+175))
#define usDBmAdcInput6             (*((INT16U*)aDBMeasu+176))
#define usDBmAdcInput7             (*((INT16U*)aDBMeasu+177))
#define usDBmAdcInput8             (*((INT16U*)aDBMeasu+178))
#define usDBmAdcInput9             (*((INT16U*)aDBMeasu+179))
#define usDBmAdcInput10            (*((INT16U*)aDBMeasu+180))
#define usDBmAdcInput11            (*((INT16U*)aDBMeasu+181))
#define usDBmAdcInput12            (*((INT16U*)aDBMeasu+182))
#define usDBmAdcInput13            (*((INT16U*)aDBMeasu+183))
#define usDBmAdcInput14            (*((INT16U*)aDBMeasu+184))
#define usDBmAdcInput15            (*((INT16U*)aDBMeasu+185))
#define usDBmAdcInput16            (*((INT16U*)aDBMeasu+186))
#define usDBmAdcInput17            (*((INT16U*)aDBMeasu+187))
#define usDBmAdcInput18            (*((INT16U*)aDBMeasu+188))
#define usDBmAdcInput19            (*((INT16U*)aDBMeasu+189))
#define usDBmAdcInput20            (*((INT16U*)aDBMeasu+190))
#define usDBmAdcInput21            (*((INT16U*)aDBMeasu+191))
#define usDBmAdcInput22            (*((INT16U*)aDBMeasu+192))
#define usDBmAdcInput23            (*((INT16U*)aDBMeasu+193))
#define usDBmAdcInput24            (*((INT16U*)aDBMeasu+194))
#define usDBmAdcInput25            (*((INT16U*)aDBMeasu+195))
#define usDBmAdcInput26            (*((INT16U*)aDBMeasu+196))
#define usDBmAdcInput27            (*((INT16U*)aDBMeasu+197))
#define usDBmAdcInput28            (*((INT16U*)aDBMeasu+198))
#define usDBmAdcInput29            (*((INT16U*)aDBMeasu+199))
#define usDBmSwitchesInput         (*((INT16U*)aDBMeasu+200))
#define usDBmSwitchesInput2        (*((INT16U*)aDBMeasu+201))
#define usDBmBoardKeyInput         (*((INT16U*)aDBMeasu+202))
#define usDBmBoardKeyInput2        (*((INT16U*)aDBMeasu+203))
#define usDBmSwitchesOutput        (*((INT16U*)aDBMeasu+204))
#define usDBmSwitchesOutput2       (*((INT16U*)aDBMeasu+205))
#define usDBmBoardLedOutput        (*((INT16U*)aDBMeasu+206))
#define usDBmBoardLedOutput2       (*((INT16U*)aDBMeasu+207))
#define uiDBmSwitchesInput         (*((INT32U*)(&usDBmSwitchesInput)))
#define uiDBmBoardKeyInput         (*((INT32U*)(&usDBmBoardKeyInput)))
#define uiDBmSwitchesOutput        (*((INT32U*)(&usDBmSwitchesOutput)))
#define uiDBmBoardLedOutput        (*((INT32U*)(&usDBmBoardLedOutput)))

/* **************** Part 10: Digital Inputs *************************** */
#define usDBmKeyMenuUp             (*((INT16U*)aDBMeasu+208))
#define usDBmKeyMenuDown           (*((INT16U*)aDBMeasu+209))
#define usDBmKeyMenuRight          (*((INT16U*)aDBMeasu+210))
#define usDBmKeyMenuLeft           (*((INT16U*)aDBMeasu+211))
#define usDBmKeyMenuEnter          (*((INT16U*)aDBMeasu+212))
#define usDBmKeyOBD                (*((INT16U*)aDBMeasu+213))
#define usDBmKeyEngineStop         (*((INT16U*)aDBMeasu+214))
#define usDBmKeyEngineStart        (*((INT16U*)aDBMeasu+215))
#define usDBmKeyModeAuto           (*((INT16U*)aDBMeasu+216))
#define usDBmKeyModeManual         (*((INT16U*)aDBMeasu+217))
#define usDBmKeyErrorReset         (*((INT16U*)aDBMeasu+218))
#define usDBmKeySwitchOn           (*((INT16U*)aDBMeasu+219))
#define usDBmKeySwitchOff          (*((INT16U*)aDBMeasu+220))
#define usDBmKeyBeeperOff          (*((INT16U*)aDBMeasu+221))
#define usDBmDinBackup1            (*((INT16U*)aDBMeasu+222))
#define usDBmDinBackup2            (*((INT16U*)aDBMeasu+223))
#define usDBmDinBackup3            (*((INT16U*)aDBMeasu+224))
#define usDBmSwitchEngineStop      (*((INT16U*)aDBMeasu+225))
#define usDBmSwitchEngineStart     (*((INT16U*)aDBMeasu+226))
#define usDBmSwitchMainFeedback    (*((INT16U*)aDBMeasu+227))
#define usDBmSwitchGensFeedback    (*((INT16U*)aDBMeasu+228))
#define usDBmSwitchOilPump         (*((INT16U*)aDBMeasu+229))
#define usDBmSwitchHeater          (*((INT16U*)aDBMeasu+230))
#define usDBmSwitchOilTemp         (*((INT16U*)aDBMeasu+231))
#define usDBmSwitchFuelLevel       (*((INT16U*)aDBMeasu+232))
#define usDBmSwitchOilPressure     (*((INT16U*)aDBMeasu+233))
#define usDBmSwitchCoolantTemp     (*((INT16U*)aDBMeasu+234))
#define usDBmSwitchCoolantLevel    (*((INT16U*)aDBMeasu+235))
#define usDBmSwitchAirFilter       (*((INT16U*)aDBMeasu+236))
#define usDBmSwitchEmergStop       (*((INT16U*)aDBMeasu+237))
#define usDBmDinBackup4            (*((INT16U*)aDBMeasu+238))
#define usDBmDinBackup5            (*((INT16U*)aDBMeasu+239))
#define usDBmDinBackup6            (*((INT16U*)aDBMeasu+240))
#define usDBmDinBackup7            (*((INT16U*)aDBMeasu+241))

/* **************** Part 11: Analog Inputs **************************** */
#define usDBmAinCoolantTemp        (*((INT16U*)aDBMeasu+242))
#define usDBmAinOilTemp            (*((INT16U*)aDBMeasu+243))
#define usDBmAinOilPres            (*((INT16U*)aDBMeasu+244))
#define usDBmAinFuelLevel          (*((INT16U*)aDBMeasu+245))
#define usDBmAinCoolantLevel       (*((INT16U*)aDBMeasu+246))
#define usDBmAinChargCurrent       (*((INT16U*)aDBMeasu+247))
#define usDBmAinInternTemp         (*((INT16U*)aDBMeasu+248))
#define usDBmAinChargVoltage       (*((INT16U*)aDBMeasu+249))
#define usDBmAinBatt1Voltage       (*((INT16U*)aDBMeasu+250))
#define usDBmAinBatt2Voltage       (*((INT16U*)aDBMeasu+251))
#define usDBmAinBackup1            (*((INT16U*)aDBMeasu+252))
#define usDBmAinBackup2            (*((INT16U*)aDBMeasu+253))
#define usDBmAinBackup3            (*((INT16U*)aDBMeasu+254))
#define usDBmAinBackup4            (*((INT16U*)aDBMeasu+255))
#define usDBmAinBackup5            (*((INT16U*)aDBMeasu+256))
#define usDBmAinBackup6            (*((INT16U*)aDBMeasu+257))
#define usDBmAinBackup7            (*((INT16U*)aDBMeasu+258))
#define usDBmAinBackup8            (*((INT16U*)aDBMeasu+259))
#define usDBmAinBackup9            (*((INT16U*)aDBMeasu+260))
#define usDBmAinBackup10           (*((INT16U*)aDBMeasu+261))

/* **************** Part 12: FFT Analysis ***************************** */
#define usDBmFftResult              ((INT16U*)(aDBMeasu+262))
#define usDBmFftResult0            (*((INT16U*)aDBMeasu+262))
#define usDBmFftResult1            (*((INT16U*)aDBMeasu+263))
#define usDBmFftResult2            (*((INT16U*)aDBMeasu+264))
#define usDBmFftResult3            (*((INT16U*)aDBMeasu+265))
#define usDBmFftResult4            (*((INT16U*)aDBMeasu+266))
#define usDBmFftResult5            (*((INT16U*)aDBMeasu+267))
#define usDBmFftResult6            (*((INT16U*)aDBMeasu+268))
#define usDBmFftResult7            (*((INT16U*)aDBMeasu+269))
#define usDBmFftResult8            (*((INT16U*)aDBMeasu+270))
#define usDBmFftResult9            (*((INT16U*)aDBMeasu+271))
#define usDBmFftResult10           (*((INT16U*)aDBMeasu+272))
#define usDBmFftResult11           (*((INT16U*)aDBMeasu+273))
#define usDBmFftResult12           (*((INT16U*)aDBMeasu+274))
#define usDBmFftResult13           (*((INT16U*)aDBMeasu+275))
#define usDBmFftResult14           (*((INT16U*)aDBMeasu+276))
#define usDBmFftResult15           (*((INT16U*)aDBMeasu+277))
#define usDBmFftResult16           (*((INT16U*)aDBMeasu+278))
#define usDBmFftResult17           (*((INT16U*)aDBMeasu+279))
#define usDBmFftResult18           (*((INT16U*)aDBMeasu+280))
#define usDBmFftResult19           (*((INT16U*)aDBMeasu+281))
#define usDBmFftResult20           (*((INT16U*)aDBMeasu+282))
#define usDBmFftResult21           (*((INT16U*)aDBMeasu+283))
#define usDBmFftResult22           (*((INT16U*)aDBMeasu+284))
#define usDBmFftResult23           (*((INT16U*)aDBMeasu+285))
#define usDBmFftResult24           (*((INT16U*)aDBMeasu+286))
#define usDBmFftResult25           (*((INT16U*)aDBMeasu+287))
#define usDBmFftResult26           (*((INT16U*)aDBMeasu+288))
#define usDBmFftResult27           (*((INT16U*)aDBMeasu+289))
#define usDBmFftResult28           (*((INT16U*)aDBMeasu+290))
#define usDBmFftResult29           (*((INT16U*)aDBMeasu+291))
#define usDBmFftResult30           (*((INT16U*)aDBMeasu+292))
#define usDBmFftResult31           (*((INT16U*)aDBMeasu+293))
#define usDBmFftAdcChannel         (*((INT16U*)aDBMeasu+294))
#define usDBmFftDistortion         (*((INT16U*)aDBMeasu+295))
#define usDBmMeasuBackup1          (*((INT16U*)aDBMeasu+296))
#define usDBmMeasuBackup2          (*((INT16U*)aDBMeasu+297))
#define usDBmMeasuBackup3          (*((INT16U*)aDBMeasu+298))
#define usDBmMeasuBackup4          (*((INT16U*)aDBMeasu+299))

/* **************** Part 13: Reserved ********************************* */
#define usDBmReserved0             (*((INT16U*)aDBMeasu+300))
#define usDBmReserved1             (*((INT16U*)aDBMeasu+301))
#define usDBmReserved2             (*((INT16U*)aDBMeasu+302))
#define usDBmReserved3             (*((INT16U*)aDBMeasu+303))
#define usDBmReserved4             (*((INT16U*)aDBMeasu+304))
#define usDBmReserved5             (*((INT16U*)aDBMeasu+305))
#define usDBmReserved6             (*((INT16U*)aDBMeasu+306))
#define usDBmReserved7             (*((INT16U*)aDBMeasu+307))
#define usDBmReserved8             (*((INT16U*)aDBMeasu+308))
#define usDBmReserved9             (*((INT16U*)aDBMeasu+309))
#define usDBmReserved10            (*((INT16U*)aDBMeasu+310))
#define usDBmReserved11            (*((INT16U*)aDBMeasu+311))
#define usDBmReserved12            (*((INT16U*)aDBMeasu+312))
#define usDBmReserved13            (*((INT16U*)aDBMeasu+313))
#define usDBmReserved14            (*((INT16U*)aDBMeasu+314))
#define usDBmReserved15            (*((INT16U*)aDBMeasu+315))
#define usDBmReserved16            (*((INT16U*)aDBMeasu+316))
#define usDBmReserved17            (*((INT16U*)aDBMeasu+317))
#define usDBmReserved18            (*((INT16U*)aDBMeasu+318))
#define usDBmReserved19            (*((INT16U*)aDBMeasu+319))
#define usDBmReserved20            (*((INT16U*)aDBMeasu+320))
#define usDBmReserved21            (*((INT16U*)aDBMeasu+321))
#define usDBmReserved22            (*((INT16U*)aDBMeasu+322))
#define usDBmReserved23            (*((INT16U*)aDBMeasu+323))
#define usDBmReserved24            (*((INT16U*)aDBMeasu+324))
#define usDBmReserved25            (*((INT16U*)aDBMeasu+325))
#define usDBmReserved26            (*((INT16U*)aDBMeasu+326))
#define usDBmReserved27            (*((INT16U*)aDBMeasu+327))
#define usDBmReserved28            (*((INT16U*)aDBMeasu+328))
#define usDBmReserved29            (*((INT16U*)aDBMeasu+329))
#define usDBmReserved30            (*((INT16U*)aDBMeasu+330))
#define usDBmReserved31            (*((INT16U*)aDBMeasu+331))
#define usDBmReserved32            (*((INT16U*)aDBMeasu+332))
#define usDBmReserved33            (*((INT16U*)aDBMeasu+333))
#define usDBmReserved34            (*((INT16U*)aDBMeasu+334))
#define usDBmReserved35            (*((INT16U*)aDBMeasu+335))
#define usDBmReserved36            (*((INT16U*)aDBMeasu+336))
#define usDBmReserved37            (*((INT16U*)aDBMeasu+337))
#define usDBmReserved38            (*((INT16U*)aDBMeasu+338))
#define usDBmReserved39            (*((INT16U*)aDBMeasu+339))
#define usDBmReserved40            (*((INT16U*)aDBMeasu+340))
#define usDBmReserved41            (*((INT16U*)aDBMeasu+341))
#define usDBmReserved42            (*((INT16U*)aDBMeasu+342))
#define usDBmReserved43            (*((INT16U*)aDBMeasu+343))
#define usDBmReserved44            (*((INT16U*)aDBMeasu+344))
#define usDBmReserved45            (*((INT16U*)aDBMeasu+345))
#define usDBmReserved46            (*((INT16U*)aDBMeasu+346))
#define usDBmReserved47            (*((INT16U*)aDBMeasu+347))
#define usDBmReserved48            (*((INT16U*)aDBMeasu+348))
#define usDBmReserved49            (*((INT16U*)aDBMeasu+349))
#define usDBmReserved50            (*((INT16U*)aDBMeasu+350))
#define usDBmReserved51            (*((INT16U*)aDBMeasu+351))
#define usDBmReserved52            (*((INT16U*)aDBMeasu+352))
#define usDBmReserved53            (*((INT16U*)aDBMeasu+353))
#define usDBmReserved54            (*((INT16U*)aDBMeasu+354))
#define usDBmReserved55            (*((INT16U*)aDBMeasu+355))
#define usDBmReserved56            (*((INT16U*)aDBMeasu+356))
#define usDBmReserved57            (*((INT16U*)aDBMeasu+357))
#define usDBmReserved58            (*((INT16U*)aDBMeasu+358))
#define usDBmReserved59            (*((INT16U*)aDBMeasu+359))

/* ******************************************************************** */
/*                           Histry Definition                          */
/* ******************************************************************** */
#define aDBHstry                    ((INT16U*)(aDBMeasu+360))
#define uiDBhKwh32B                (*(INT32U*)(aDBMeasu+360))
#define usDBhKwh16L                (*((INT16U*)aDBMeasu+360))
#define usDBhKwh16U                (*((INT16U*)aDBMeasu+361))
#define uiDBhKvarh32B              (*(INT32U*)(aDBMeasu+362))
#define usDBhKvarh16L              (*((INT16U*)aDBMeasu+362))
#define usDBhKvarh16U              (*((INT16U*)aDBMeasu+363))
#define uiDBhRunTime32B            (*(INT32U*)(aDBMeasu+364))
#define usDBhRunTime16L            (*((INT16U*)aDBMeasu+364))
#define usDBhRunTime16U            (*((INT16U*)aDBMeasu+365))
#define uiDBhStartTimes32B         (*(INT32U*)(aDBMeasu+366))
#define usDBhStartTimes16L         (*((INT16U*)aDBMeasu+366))
#define usDBhStartTimes16U         (*((INT16U*)aDBMeasu+367))
#define usDBhErrorStatus1          (*((INT16U*)aDBMeasu+368))
#define usDBhErrorStatus2          (*((INT16U*)aDBMeasu+369))
#define usDBhErrorStatus3          (*((INT16U*)aDBMeasu+370))
#define usDBhErrorStatus4          (*((INT16U*)aDBMeasu+371))
#define usDBhErrorStatus5          (*((INT16U*)aDBMeasu+372))
#define usDBhErrorStatus6          (*((INT16U*)aDBMeasu+373))
#define usDBhErrorStatus7          (*((INT16U*)aDBMeasu+374))
#define usDBhErrorStatus8          (*((INT16U*)aDBMeasu+375))
#define usDBhErrorStatus9          (*((INT16U*)aDBMeasu+376))
#define usDBhErrorStatus10         (*((INT16U*)aDBMeasu+377))
#define usDBhErrorStatus11         (*((INT16U*)aDBMeasu+378))
#define usDBhErrorStatus12         (*((INT16U*)aDBMeasu+379))
#define usDBhErrorStatus13         (*((INT16U*)aDBMeasu+380))
#define usDBhErrorStatus14         (*((INT16U*)aDBMeasu+381))
#define usDBhErrorStatus15         (*((INT16U*)aDBMeasu+382))
#define usDBhErrorStatus16         (*((INT16U*)aDBMeasu+383))
#define uiDBhErrorStatus1          (*((INT32U*)(&usDBhErrorStatus1)))
#define uiDBhErrorStatus2          (*((INT32U*)(&usDBhErrorStatus3)))
#define uiDBhErrorStatus3          (*((INT32U*)(&usDBhErrorStatus5)))
#define uiDBhErrorStatus4          (*((INT32U*)(&usDBhErrorStatus7)))
#define uiDBhErrorStatus5          (*((INT32U*)(&usDBhErrorStatus9)))
#define uiDBhErrorStatus6          (*((INT32U*)(&usDBhErrorStatus11)))
#define uiDBhErrorStatus7          (*((INT32U*)(&usDBhErrorStatus13)))
#define uiDBhErrorStatus8          (*((INT32U*)(&usDBhErrorStatus15)))
#define usDBhHstryBackup1          (*((INT16U*)aDBMeasu+384))
#define usDBhHstryBackup2          (*((INT16U*)aDBMeasu+385))
#define usDBhHstryBackup3          (*((INT16U*)aDBMeasu+386))
#define usDBhHstryBackup4          (*((INT16U*)aDBMeasu+387))
#define usDBhHstryBackup5          (*((INT16U*)aDBMeasu+388))
#define usDBhHstryBackup6          (*((INT16U*)aDBMeasu+389))
#define usDBhHstryBackup7          (*((INT16U*)aDBMeasu+390))
#define usDBhHstryBackup8          (*((INT16U*)aDBMeasu+391))
#define usDBhHstryBackup9          (*((INT16U*)aDBMeasu+392))
#define usDBhHstryBackup10         (*((INT16U*)aDBMeasu+393))
#define usDBhHstryBackup11         (*((INT16U*)aDBMeasu+394))
#define usDBhHstryBackup12         (*((INT16U*)aDBMeasu+395))
#define usDBhHstryBackup13         (*((INT16U*)aDBMeasu+396))
#define usDBhHstryBackup14         (*((INT16U*)aDBMeasu+397))
#define usDBhHstryBackup15         (*((INT16U*)aDBMeasu+398))
#define usDBhHstryBackup16         (*((INT16U*)aDBMeasu+399))
#define aDBhStatisticData           ((INT16U*)(aDBMeasu+400))

/* ******************************************************************** */
/*                    End of Measurement Definition                     */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */