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
#include "TYPCortex.h"
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

//#define DB_VERSION           7800
#define DB_VERSION           4800

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

#define DB_4800_COMMON_ON       0
#define DB_4800_MAIN_CHIP_ON    0
#define DB_4800_AUX_CHIP_ON     0

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
//***************
#if   ((DB_VERSION / 100)   == 48)
#undef  DB_4800_COMMON_ON
#define DB_4800_COMMON_ON       1
#endif
#if   ((DB_VERSION / 10)   == 480)
#undef  DB_4800_MAIN_CHIP_ON
#define DB_4800_MAIN_CHIP_ON    1
#endif
#if   ((DB_VERSION / 10)   == 481)
#undef  DB_4800_AUX_CHIP_ON
#define DB_4800_AUX_CHIP_ON     1
#endif
//***************
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
//***************
#if    (DB_4800_COMMON_ON    == 1)
#undef  DB_CPU_STM32F1_ON
#define DB_CPU_STM32F1_ON       1
#endif
#if    (DB_4800_MAIN_CHIP_ON == 1)
#undef  DB_CPU_STM32F103_ON
#define DB_CPU_STM32F103_ON     1
#endif
//***************
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
#define DB_SAME                 0
#define DB_DIFFERENT            1
#define DB_RANGE_OUT            2
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
#define DB_STS_SAVE_PARAM      (INT32U)0x00010000
#define DB_STS_SAVE_FUNCT      (INT32U)0x00020000
#define DB_STS_SAVE_CURVE      (INT32U)0x00040000
#define DB_STS_SAVE_HSTRY      (INT32U)0x00080000
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
#define DB_CMD_POWER_OFF       (INT08U)0x5A
/* ************************** DB Params Size ************************** */
#define DB_PARAM_SIZE           480
#define DB_FUNCT_SIZE           120
#define DB_CURVE_SIZE           400
#define DB_MEASU_SIZE           500   //
#define DB_MEASU_NOR_SIZE       100
#define DB_HSTRY_SIZE           400
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
#if    (DB_CPU_STM32F103_ON == 1)
#define DB_CPU_STM32F1_XL_ON    0
#define DB_FLASH_BANK1_ADR_MAX (INT32U)0x0807FFFE
#define DB_RDP_KEY             (INT16U)0x00A5
#define DB_FLASH_KEY1          (INT32U)0x45670123
#define DB_FLASH_KEY2          (INT32U)0xCDEF89AB
#define DB_FLASH_ADDR_MIN      (INT32U)0x08000000
#define DB_FLASH_ADDR_MAX      (INT32U)0x0807FFFF
#define DB_FLASH_PAGE_NUM      (INT32U)256
#define DB_FLASH_PAGE_SIZ      (INT32U)0x00000800
#define DB_FLASH_PAGE_MSK      (INT32U)0xFFFFF800
#define DB_PARAM_ADDR          (INT32U)0x0807B000
#define DB_PARAM_PAGE_NUM       1
#define DB_FUNCT_ADDR          (INT32U)0x0807B800
#define DB_FUNCT_PAGE_NUM       1
#define DB_CURVE_ADDR          (INT32U)0x0807C000
#define DB_CURVE_PAGE_NUM       1
#define DB_HSTRY_ADDR          (INT32U)0x0807C800
#define DB_HSTRY_PAGE_NUM       7
#define DB_HSTRY_HEAD_SIZE      4
#define DB_HSTRY_RECORD_SIZE   (DB_HSTRY_HEAD_SIZE + DB_HSTRY_SIZE08)
#define DB_HSTRY_RECORD_ID     (INT32U)0x00003412
#define DB_HSTRY_RECORD_HEAD   (DB_HSTRY_RECORD_ID + (DB_HSTRY_SIZE08 << 16))
#endif
#if    (DB_CPU_STM32F105_ON == 1)
#define DB_CPU_STM32F1_XL_ON    0
#define DB_FLASH_BANK1_ADR_MAX (INT32U)0x0807FFFE
#define DB_RDP_KEY             (INT16U)0x00A5
#define DB_FLASH_KEY1          (INT32U)0x45670123
#define DB_FLASH_KEY2          (INT32U)0xCDEF89AB
#define DB_FLASH_ADDR_MIN      (INT32U)0x08000000
#define DB_FLASH_ADDR_MAX      (INT32U)0x0803FFFF
#define DB_FLASH_PAGE_NUM      (INT32U)128
#define DB_FLASH_PAGE_SIZ      (INT32U)0x00000800
#define DB_FLASH_PAGE_MSK      (INT32U)0xFFFFF800
#define DB_PARAM_ADDR          (INT32U)0x0803B000
#define DB_PARAM_PAGE_NUM       1
#define DB_FUNCT_ADDR          (INT32U)0x0803B800
#define DB_FUNCT_PAGE_NUM       1
#define DB_CURVE_ADDR          (INT32U)0x0803C000
#define DB_CURVE_PAGE_NUM       1
#define DB_HSTRY_ADDR          (INT32U)0x0803C800
#define DB_HSTRY_PAGE_NUM       7
#define DB_HSTRY_HEAD_SIZE      4
#define DB_HSTRY_RECORD_SIZE   (DB_HSTRY_HEAD_SIZE + DB_HSTRY_SIZE08)
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
//#pragma data_alignment = 4
DB_EXT INT16U aDBParam[DB_PARAM_SIZE];
//#pragma data_alignment = 4
DB_EXT INT16U aDBFunct[DB_FUNCT_SIZE];
//#pragma data_alignment = 4
DB_EXT INT16U aDBCurve[DB_CURVE_SIZE];
//#pragma data_alignment = 4
DB_EXT INT16U aDBMeasu[DB_MEASU_SIZE];
//DB_EXT INT08U aDBMeasu[DB_MEASU_SIZE];
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
DB_EXT INT08U DBFlashIsPageErased(INT32U uiAddr);
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
DB_EXT INT16U DBGetParamAndSum16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBGetParam08p(INT08U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBSetParam16u(INT16U usBegin, INT16U usValue);
DB_EXT INT08U DBSetParam16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBSetParam08p(INT08U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBCheckParam16u(INT16U usBegin, INT16U usValue);
DB_EXT INT08U DBCheckParam16p(INT16U *pDat, INT16U usBegin, INT16U usSize);

DB_EXT INT08U DBGetMeasu08u (INT16U usBegin);
DB_EXT INT08U DBGetMeasu16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT16U DBGetMeasuAndSum16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBGetMeasu08p(INT08U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBSetMeasu16u(INT16U usBegin, INT16U usValue);
DB_EXT INT08U DBSetMeasu16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBSetMeasu08p(INT08U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBCheckMeasu16u(INT16U usBegin, INT16U usValue);
DB_EXT INT08U DBCheckMeasu16p(INT16U *pDat, INT16U usBegin, INT16U usSize);

DB_EXT INT16U DBGetFunct16u(INT16U usBegin);
DB_EXT INT08U DBGetFunct16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT16U DBGetFunctAndSum16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBGetFunct08p(INT08U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBSetFunct16u(INT16U usBegin, INT16U usValue);
DB_EXT INT08U DBSetFunct16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBSetFunct08p(INT08U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT08U DBCheckFunct16u(INT16U usBegin, INT16U usValue);
DB_EXT INT08U DBCheckFunct16p(INT16U *pDat, INT16U usBegin, INT16U usSize);

DB_EXT INT16U DBGetCurve16u(INT16U usBegin);
DB_EXT INT08U DBGetCurve16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
DB_EXT INT16U DBGetCurveAndSum16p(INT16U *pDat, INT16U usBegin, INT16U usSize);
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
#define usDBpRS485Sent0delay             (*((INT16U*)aDBParam+  0))  //1ms的倍数
#define usDBpRS485Sent0Leng              (*((INT16U*)aDBParam+  1))  //aDBCurve中 29-0 = 29 故 usDBpRS485Sent0Leng0 最大为29    

#define usDBpRS485Sent1delay             (*((INT16U*)aDBParam+ 10))  //1ms的倍数
#define usDBpRS485Sent1Leng              (*((INT16U*)aDBParam+ 11))  // 59-30 = 29 故 usDBpRS485Sent0Leng0 最大为29


#define usDBpRS485Sent2delay             (*((INT16U*)aDBParam+ 20))  //1ms的倍数
#define usDBpRS485Sent2Leng              (*((INT16U*)aDBParam+ 21))  // 89-60 = 29 故 usDBpRS485Sent0Leng0 最大为29


#define usDBpRS485Sent3delay             (*((INT16U*)aDBParam+ 30))  //1ms的倍数
#define usDBpRS485Sent3Leng              (*((INT16U*)aDBParam+ 31))  // 119-90 = 29 故 usDBpRS485Sent0Leng0 最大为29


#define usDBpRS485Sent4delay             (*((INT16U*)aDBParam+ 40)) //1ms的倍数
#define usDBpRS485Sent4Leng              (*((INT16U*)aDBParam+ 41)) // 149-120 = 29 故 usDBpRS485Sent0Leng0 最大为29


#define usDBpRS485Sent5delay             (*((INT16U*)aDBParam+ 50)) //1ms的倍数
#define usDBpRS485Sent5Leng              (*((INT16U*)aDBParam+ 51)) // 179-150 = 29 故 usDBpRS485Sent0Leng0 最大为29

#define usDBfRS485HostAddr               (*((INT16U*)aDBParam+ 60))  //主机地址
#define usDBfRS485Monitor0Addr           (*((INT16U*)aDBParam+ 61))  //监视器0地址
#define usDBfRS485Monitor1Addr           (*((INT16U*)aDBParam+ 62))  //监视器1地址
#define usDBfRS485Monitor2Addr           (*((INT16U*)aDBParam+ 63))  //监视器2地址

/* ******************************************************************** */
/*                     GEC7800 Function Definition                      */
/* ******************************************************************** */
/* **************** Part 1: Grid Electric Functions ******************* */
#define usDBfRS485SysMode           (*((INT16U*)aDBFunct+  0))  //485运行模式 0-主机 1-从机
#define usDBfRS485EnableRead        (*((INT16U*)aDBFunct+  1))  //485读取功能使能
#define usDBfRS485EnableSent        (*((INT16U*)aDBFunct+  2))  //485写入功能使能
#define usDBfRS485EnableCRC         (*((INT16U*)aDBFunct+  3))   //485开启自动CRC校验使能
#define usDBfRS485EnSentData0       (*((INT16U*)aDBFunct+  4))   //第0条报文发送使能
#define usDBfRS485EnSentData1       (*((INT16U*)aDBFunct+  5))   //第1条报文发送使能
#define usDBfRS485EnSentData2       (*((INT16U*)aDBFunct+  6))   //第2条报文发送使能
#define usDBfRS485EnSentData3       (*((INT16U*)aDBFunct+  7))   //第3条报文发送使能
#define usDBfRS485EnSentData4       (*((INT16U*)aDBFunct+  8))   //第4条报文发送使能
#define usDBfRS485EnSentData5       (*((INT16U*)aDBFunct+  9))   //第5条报文发送使能
/* ******************************************************************** */
/*                     GEC7800 Curves Definition                        */
/* ******************************************************************** */
#define usDBcRS485Sent0DataA0             (((INT16U*)aDBCurve+  0)) //第0条报文
#define usDBcRS485Sent0Data0             (*((INT16U*)aDBCurve+  0))
#define usDBcRS485Sent0Data1             (*((INT16U*)aDBCurve+  1))
#define usDBcRS485Sent0Data2             (*((INT16U*)aDBCurve+  2))  

#define usDBcRS485Sent1DataA0             (((INT16U*)aDBCurve+ 30)) //第1条报文
#define usDBcRS485Sent1Data0             (*((INT16U*)aDBCurve+ 30))
#define usDBcRS485Sent1Data1             (*((INT16U*)aDBCurve+ 31))
#define usDBcRS485Sent1Data2             (*((INT16U*)aDBCurve+ 32))

#define usDBcRS485Sent2DataA0             (((INT16U*)aDBCurve+ 60)) //第2条报文
#define usDBcRS485Sent2Data0             (*((INT16U*)aDBCurve+ 60))
#define usDBcRS485Sent2Data1             (*((INT16U*)aDBCurve+ 61))
#define usDBcRS485Sent2Data2             (*((INT16U*)aDBCurve+ 62))

#define usDBcRS485Sent3DataA0             (((INT16U*)aDBCurve+ 90)) //第3条报文
#define usDBcRS485Sent3Data0             (*((INT16U*)aDBCurve+ 90))
#define usDBcRS485Sent3Data1             (*((INT16U*)aDBCurve+ 91))
#define usDBcRS485Sent3Data2             (*((INT16U*)aDBCurve+ 92))

#define usDBcRS485Sent4DataA0             (((INT16U*)aDBCurve+ 120)) //第4条报文
#define usDBcRS485Sent4Data0             (*((INT16U*)aDBCurve+ 120))
#define usDBcRS485Sent4Data1             (*((INT16U*)aDBCurve+ 121))
#define usDBcRS485Sent4Data2             (*((INT16U*)aDBCurve+ 122))

#define usDBcRS485Sent5DataA0             (((INT16U*)aDBCurve+ 150)) //第5条报文
#define usDBcRS485Sent5Data0             (*((INT16U*)aDBCurve+ 150))
#define usDBcRS485Sent5Data1             (*((INT16U*)aDBCurve+ 151))
#define usDBcRS485Sent5Data2             (*((INT16U*)aDBCurve+ 152))
/* ******************************************************************** */
/*                        Measurement Definition                        */
/* ******************************************************************** */
/* **************** Part 1: Grid Electric Measurements **************** */
#define usDBmSysBackup            (*((INT16U*)aDBMeasu+  0))  //数据保存



/* ******************************************************************** */
/*                           Histry Definition                          */
/* ******************************************************************** */
#define aDBHstry                    (((INT16U*)aDBMeasu+100))  //保存数据起始地址
#define usDBhRS485RXToLeng         (*((INT16U*)aDBMeasu+100))  //RS485数据总长度
#define usDBhRS485RXBuff            (((INT16U*)aDBMeasu+101))  //RS485数据起始地址
#define usDBhRS485RXBuf0           (*((INT16U*)aDBMeasu+101))

#define usDBhRS485RXToLeng         (*((INT16U*)aDBMeasu+100))  //RS485数据总长度
#define usDBhRS485RXBuff            (((INT16U*)aDBMeasu+101))  //RS485数据起始地址

#define usDBhCANRXToLeng           (*((INT16U*)aDBMeasu+300))  //CAN数据总长度
#define usDBhCANRXBuff              (((INT16U*)aDBMeasu+301))  //CAN数据起始地址
/* ******************************************************************** */
/*                    End of Measurement Definition                     */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */

