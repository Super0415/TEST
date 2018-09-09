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
/*  DB_VERSION  = 76xx: GEC7600 Application                             */
/*  DB_VERSION  = 78xx: GEC7800 Application                             */
/*  DB_VERSION  = 80xx: VEC8000 Application                             */
/*  DB_VERSION  = 90xx: VEC9000 Application                             */
/*  DB_VERSION  = 96xx: VEC9600 Application                             */
/* ******************************************************************** */

#define DB_VERSION           7600

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define DB_1000_COMMON_ON       0
#define DB_4000_COMMON_ON       0
#define DB_6800_COMMON_ON       0
#define DB_6900_COMMON_ON       0
#define DB_7600_COMMON_ON       0
#define DB_7800_COMMON_ON       0
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
#if   ((DB_VERSION / 100)   == 78)
#undef  DB_7800_COMMON_ON
#define DB_7800_COMMON_ON       1
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
#if    (DB_7800_COMMON_ON    == 1)
#undef  DB_CPU_STM32F1_ON
#define DB_CPU_STM32F1_ON       1
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


#define DB_CPU_STM32F10_XL_ON   0


/* ******************************************************************** */
/*                           Basis Definition                           */
/* ******************************************************************** */
#define DB_TRUE                 1
#define DB_FALSE                0
#define DB_NO_ERR               0
#define DB_ERR_EVENT_TYPE       1
#define DB_ERR_PEND_ISR         2
#define DB_ERR_BAD_CH           3
#define DB_ERR_RX_EMPTY         4
#define DB_ERR_TX_FULL          5
#define DB_ERR_TX_EMPTY         6
#define DB_ERR_RX_TIMEOUT       7
#define DB_ERR_TX_TIMEOUT       8
#define DB_STS_NORMAL           0
#define DB_STS_INTERRUPT        1
#define DB_STS_USAGE_WARN       2
#define DB_STS_STACK_WARN       4
#define DB_STS_FLASH_WARN       8
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

/* ******************************************************************** */
/*                           Control Definition                         */
/* ******************************************************************** */
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
#define DB_PARAM_SIZE           560
#define DB_MEASU_SIZE           320
#define DB_MEASU_NOR_SIZE       200
#define DB_FUNCT_SIZE           2
#define DB_CURVE_SIZE           2
#define DB_HSTRY_SIZE           120
#define DB_MEASU_SIZE08        (DB_MEASU_SIZE * 2)
#define DB_MEASU_SIZE16         DB_MEASU_SIZE
#define DB_MEASU_SIZE32        (DB_MEASU_SIZE / 2)
#define DB_PARAM_SIZE08        (DB_PARAM_SIZE * 2)
#define DB_PARAM_SIZE16         DB_PARAM_SIZE
#define DB_PARAM_SIZE32        (DB_PARAM_SIZE / 2)
#define DB_HSTRY_SIZE08        (DB_HSTRY_SIZE * 2)
#define DB_HSTRY_SIZE16         DB_HSTRY_SIZE
#define DB_HSTRY_SIZE32        (DB_HSTRY_SIZE / 2)
/* ************************** DB Eeprom (Flash) *********************** */
#if    (DB_CPU_STM32F1_ON == 1)
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
#define DB_CURVE_ADDR          (INT32U)0x0803B800
#define DB_CURVE_PAGE_NUM       0
#define DB_HSTRY_ADDR          (INT32U)0x0803B800
#define DB_HSTRY_PAGE_NUM       9
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
DB_EXT INT16U usDBTimer;
DB_EXT INT16U usDBStatus;
DB_EXT INT16U aDBParam[DB_PARAM_SIZE];
DB_EXT INT16U aDBMeasu[DB_MEASU_SIZE];
DB_EXT INT16U aDBFunct[DB_FUNCT_SIZE];
DB_EXT INT16U aDBCurve[DB_CURVE_SIZE];
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

/* ******************************************************************** */
/*                        Parameter Definition                          */
/* ******************************************************************** */
/* **************** Part 1: Electric Parameters (0 - 42) ************** */
#define usDBpGensCtRatio           (*((INT16U*)aDBParam+  0))
#define usDBpAmpMainVoltA          (*((INT16U*)aDBParam+  1))
#define usDBpAmpMainVoltB          (*((INT16U*)aDBParam+  2))
#define usDBpAmpMainVoltC          (*((INT16U*)aDBParam+  3))
#define usDBpAmpMainVoltAB         (*((INT16U*)aDBParam+  4))
#define usDBpAmpMainVoltBC         (*((INT16U*)aDBParam+  5))
#define usDBpAmpMainVoltCA         (*((INT16U*)aDBParam+  6))
#define usDBpAmpGensVoltA          (*((INT16U*)aDBParam+  7))
#define usDBpAmpGensVoltB          (*((INT16U*)aDBParam+  8))
#define usDBpAmpGensVoltC          (*((INT16U*)aDBParam+  9))
#define usDBpAmpGensVoltAB         (*((INT16U*)aDBParam+ 10))
#define usDBpAmpGensVoltBC         (*((INT16U*)aDBParam+ 11))
#define usDBpAmpGensVoltCA         (*((INT16U*)aDBParam+ 12))
#define usDBpAmpGensCurrA          (*((INT16U*)aDBParam+ 13))
#define usDBpAmpGensCurrB          (*((INT16U*)aDBParam+ 14))
#define usDBpAmpGensCurrC          (*((INT16U*)aDBParam+ 15))
#define usDBpAdcChFilter             ((INT16U*)aDBParam+ 17)
#define usDBpAdcChFilter0          (*((INT16U*)aDBParam+ 17))
#define usDBpAdcChFilter1          (*((INT16U*)aDBParam+ 18))
#define usDBpAdcChFilter2          (*((INT16U*)aDBParam+ 19))
#define usDBpAdcChFilter3          (*((INT16U*)aDBParam+ 20))
#define usDBpAdcChFilter4          (*((INT16U*)aDBParam+ 21))
#define usDBpAdcChFilter5          (*((INT16U*)aDBParam+ 22))
#define usDBpAdcChFilter6          (*((INT16U*)aDBParam+ 23))
#define usDBpAdcChFilter7          (*((INT16U*)aDBParam+ 24))
#define usDBpAdcChFilter8          (*((INT16U*)aDBParam+ 25))
#define usDBpAdcChRef                ((INT16U*)aDBParam+ 26)
#define usDBpAdcChRef0             (*((INT16U*)aDBParam+ 26))
#define usDBpAdcChRef1             (*((INT16U*)aDBParam+ 27))
#define usDBpAdcChRef2             (*((INT16U*)aDBParam+ 28))
#define usDBpAdcChRef3             (*((INT16U*)aDBParam+ 29))
#define usDBpAdcChRef4             (*((INT16U*)aDBParam+ 30))
#define usDBpAdcChRef5             (*((INT16U*)aDBParam+ 31))
#define usDBpAdcChRef6             (*((INT16U*)aDBParam+ 32))
#define usDBpAdcChRef7             (*((INT16U*)aDBParam+ 33))
#define usDBpAdcChRef8             (*((INT16U*)aDBParam+ 34))
#define usDBpAdcChRef9             (*((INT16U*)aDBParam+ 35))
#define usDBpAdcChRef10            (*((INT16U*)aDBParam+ 36))
#define usDBpAdcChRef11            (*((INT16U*)aDBParam+ 37))
#define usDBpAdcChRef12            (*((INT16U*)aDBParam+ 38))
#define usDBpAdcChRef13            (*((INT16U*)aDBParam+ 39))
#define usDBpAdcChRef14            (*((INT16U*)aDBParam+ 40))
#define usDBpAdcChRef15            (*((INT16U*)aDBParam+ 41))
#define usDBpAdcRefAutoOrFixed     (*((INT16U*)aDBParam+ 42))
/* **************** Part 2: Generator (43 - 53) *********************** */
#define	usDBpVoltDifferMax         (*((INT16U*)aDBParam+ 43))
#define	usDBpFreqDifferMax         (*((INT16U*)aDBParam+ 44))
#define	usDBpPhaseDifferMax        (*((INT16U*)aDBParam+ 45))
#define	usDBpSpeedTuneGain         (*((INT16U*)aDBParam+ 46))
#define	usDBpSpeedTuneStability    (*((INT16U*)aDBParam+ 47))
#define	usDBpSpeedTuneDerivative   (*((INT16U*)aDBParam+ 48))
#define	ssDBpSpeedTuneCtrlInit     (*((INT16S*)aDBParam+ 49))
#define	usDBpAvrTuneGain           (*((INT16U*)aDBParam+ 50))
#define	usDBpAvrTuneStability      (*((INT16U*)aDBParam+ 51))
#define	usDBpAvrTuneDerivative     (*((INT16U*)aDBParam+ 52))
#define	ssDBpAvrTuneCtrlInit       (*((INT16S*)aDBParam+ 53))

/* **************** Part 3: Teeth/Speed (54 - 79) ********************* */
#define usDBpTeethCrank1           (*((INT16U*)aDBParam+ 54))
#define usDBpTeethCrank2           (*((INT16U*)aDBParam+ 55))
#define usDBpSpeedFilter1          (*((INT16U*)aDBParam+ 56))
#define usDBpSpeedFilter2          (*((INT16U*)aDBParam+ 57))
#define	usDBpStartSpeed1           (*((INT16U*)aDBParam+ 58))
#define	usDBpStartSpeed2           (*((INT16U*)aDBParam+ 59))
#define usDBpSpeedIdle             (*((INT16U*)aDBParam+ 60))
#define usDBpSpeedIdleMin          (*((INT16U*)aDBParam+ 61))
#define usDBpSpeedIdleMax          (*((INT16U*)aDBParam+ 62))
#define usDBpSpeedRated            (*((INT16U*)aDBParam+ 63))
#define usDBpSpeedRatedMin         (*((INT16U*)aDBParam+ 64))
#define usDBpSpeedWrongMax         (*((INT16U*)aDBParam+ 65))
#define usDBpSpeedWrongDly         (*((INT16U*)aDBParam+ 66))
#define usDBpSpeedOverToWarn       (*((INT16U*)aDBParam+ 67))
#define usDBpSpeedOverToStop       (*((INT16U*)aDBParam+ 68))
#define usDBpSpeedOverStopDly      (*((INT16U*)aDBParam+ 69))
#define	usDBpDroop                 (*((INT16U*)aDBParam+ 70))
#define	usDBpDroopRefLow           (*((INT16U*)aDBParam+ 71))
#define	usDBpDroopRefHigh          (*((INT16U*)aDBParam+ 72))
#define	usDBpDroopSpeedRef         (*((INT16U*)aDBParam+ 73))
#define	usDBpSpeedRampDigitPot     (*((INT16U*)aDBParam+ 74))
#define	usDBpSpeedRampUp           (*((INT16U*)aDBParam+ 75))
#define	usDBpSpeedRampDown         (*((INT16U*)aDBParam+ 76))
#define	usDBpSpeedRampUp2          (*((INT16U*)aDBParam+ 77))
#define	usDBpSpeedRampDown2        (*((INT16U*)aDBParam+ 78))
#define	usDBpSpeedSwitchToRamp2    (*((INT16U*)aDBParam+ 79))

/* **************** Part 4: System Control (80 - 107) ***************** */
#define usDBpStoppedToStartingDly  (*((INT16U*)aDBParam+ 80))
#define usDBpIdlingToRampUpDly     (*((INT16U*)aDBParam+ 81))
#define usDBpRatedToSynchringDly   (*((INT16U*)aDBParam+ 82))
#define usDBpWorkingToSwitchOffDly (*((INT16U*)aDBParam+ 83))
#define usDBpRatedToRampDowmDly    (*((INT16U*)aDBParam+ 84))
#define usDBpIdlingToStoppingDly   (*((INT16U*)aDBParam+ 85))
#define usDBpMainBreakerOnDly      (*((INT16U*)aDBParam+ 86))
#define usDBpGensBreakerOnDly      (*((INT16U*)aDBParam+ 87))
#define usDBpBreakerTripChkDly     (*((INT16U*)aDBParam+ 88))
#define usDBpVoltageDifferChkDly   (*((INT16U*)aDBParam+ 89))
#define usDBpRampUpTimeMax         (*((INT16U*)aDBParam+ 90))
#define usDBpRampDownTimeMax       (*((INT16U*)aDBParam+ 91))
#define usDBpSynchronTimeMax       (*((INT16U*)aDBParam+ 92))
#define usDBpStoppingTimeMax       (*((INT16U*)aDBParam+ 93))
#define	usDBpAirHeatTempCold       (*((INT16U*)aDBParam+ 94))
#define	usDBpAirHeatTempWarm       (*((INT16U*)aDBParam+ 95))
#define	usDBpAirHeatTimeAtCold     (*((INT16U*)aDBParam+ 96))
#define	usDBpAirHeatTimeAtWarm     (*((INT16U*)aDBParam+ 97))
#define	usDBpOilPumpOnTimeMax      (*((INT16U*)aDBParam+ 98))
#define	usDBpOilPressMinAtStart    (*((INT16U*)aDBParam+ 99))
#define	usDBpFanRefAssign          (*((INT16U*)aDBParam+100))
#define	usDBpFanActiveTemp         (*((INT16U*)aDBParam+101))
#define	usDBpFanActiveDly          (*((INT16U*)aDBParam+102))
#define	usDBpStarterOnDly          (*((INT16U*)aDBParam+103))
#define	usDBpStarterOffDly         (*((INT16U*)aDBParam+104))
#define usDBpStartFailMax          (*((INT16U*)aDBParam+105))
#define	usDBpOperationMode         (*((INT16U*)aDBParam+106))
#define	usDBpStatisticsTime        (*((INT16U*)aDBParam+107))

/* **************** Part 5: CanBus / ModBus (108 - 115) *************** */
#define	usDBpModBusBaudrate        (*((INT16U*)aDBParam+108))
#define	usDBpModBusMyAddress       (*((INT16U*)aDBParam+109))
#define	usDBpCan1Baudrate          (*((INT16U*)aDBParam+110))
#define	usDBpCan1MyAddress         (*((INT16U*)aDBParam+111))
#define	usDBpCan2Baudrate          (*((INT16U*)aDBParam+112))
#define	usDBpCan2MyAddress         (*((INT16U*)aDBParam+113))
#define	usDBpCan3Baudrate          (*((INT16U*)aDBParam+114))
#define	usDBpCan3MyAddress         (*((INT16U*)aDBParam+115))

/* ****************** Part 6: Monitoring (116 - 178) ****************** */
#define	usDBpCoolantTempToWarn     (*((INT16U*)aDBParam+116))
#define	usDBpCoolantTempToStop     (*((INT16U*)aDBParam+117))
#define	usDBpCoolantTempStopDly    (*((INT16U*)aDBParam+118))
#define	usDBpBoostTempToWarn       (*((INT16U*)aDBParam+119))
#define	usDBpBoostTempToStop       (*((INT16U*)aDBParam+120))
#define	usDBpBoostTempStopDly      (*((INT16U*)aDBParam+121))
#define	usDBpOilTempToWarn         (*((INT16U*)aDBParam+122))
#define	usDBpOilTempToStop         (*((INT16U*)aDBParam+123))
#define	usDBpOilTempStopDly        (*((INT16U*)aDBParam+124))
#define	usDBpInternTempToWarn      (*((INT16U*)aDBParam+125))
#define	usDBpOilPressStartDly      (*((INT16U*)aDBParam+126))
#define	usDBpOilPressWarnDly       (*((INT16U*)aDBParam+127))
#define	usDBpOilPressStopDly       (*((INT16U*)aDBParam+128))
#define	usDBpFuelLevelToWarn       (*((INT16U*)aDBParam+129))
#define	usDBpFuelLevelWarnDly      (*((INT16U*)aDBParam+130))
#define	usDBpFuelLevelToStop       (*((INT16U*)aDBParam+131))
#define	usDBpFuelLevelStopDly      (*((INT16U*)aDBParam+132))
#define	usDBpCoolantLevelToWarn    (*((INT16U*)aDBParam+133))
#define	usDBpCoolantLevelWarnDly   (*((INT16U*)aDBParam+134))
#define	usDBpCoolantLevelToStop    (*((INT16U*)aDBParam+135))
#define	usDBpCoolantLevelStopDly   (*((INT16U*)aDBParam+136))
#define	usDBpSupplyVoltWarnLow     (*((INT16U*)aDBParam+137))
#define	usDBpSupplyVoltWarnHigh    (*((INT16U*)aDBParam+138))
#define	usDBpSupplyVoltWarnDly     (*((INT16U*)aDBParam+139))
#define	usDBpChargerVoltWarnLow    (*((INT16U*)aDBParam+140))
#define	usDBpChargerVoltWarnHigh   (*((INT16U*)aDBParam+141))
#define	usDBpChargerVoltWarnDly    (*((INT16U*)aDBParam+142))
#define	usDBpChargerCurrToWarn     (*((INT16U*)aDBParam+143))
#define	usDBpChargerCurrWarnDly    (*((INT16U*)aDBParam+144))
#define	usDBpRackPositionToWarn    (*((INT16U*)aDBParam+145))
#define	usDBpRackPositionWarnDly   (*((INT16U*)aDBParam+146))
#define	usDBpAirFilterWarnDly      (*((INT16U*)aDBParam+147))
#define usDBpMainLnVoltErrLow      (*((INT16U*)aDBParam+148))
#define usDBpMainLnVoltErrHigh     (*((INT16U*)aDBParam+149))
#define usDBpMainLlVoltErrLow      (*((INT16U*)aDBParam+150))
#define usDBpMainLlVoltErrHigh     (*((INT16U*)aDBParam+151))
#define usDBpMainPhaseErrLow       (*((INT16U*)aDBParam+152))
#define usDBpMainPhaseErrHigh      (*((INT16U*)aDBParam+153))
#define usDBpMainFreqErrLow        (*((INT16U*)aDBParam+154))
#define usDBpMainFreqErrHigh       (*((INT16U*)aDBParam+155))
#define usDBpMainVoltErrorDly      (*((INT16U*)aDBParam+156))
#define usDBpMainVoltNormalDly     (*((INT16U*)aDBParam+157))
#define usDBpGensLnVoltErrLow      (*((INT16U*)aDBParam+158))
#define usDBpGensLnVoltErrHigh     (*((INT16U*)aDBParam+159))
#define usDBpGensLlVoltErrLow      (*((INT16U*)aDBParam+160))
#define usDBpGensLlVoltErrHigh     (*((INT16U*)aDBParam+161))
#define usDBpGensPhaseErrLow       (*((INT16U*)aDBParam+162))
#define usDBpGensPhaseErrHigh      (*((INT16U*)aDBParam+163))
#define usDBpGensFreqErrLow        (*((INT16U*)aDBParam+164))
#define usDBpGensFreqErrHigh       (*((INT16U*)aDBParam+165))
#define usDBpGensVoltErrorDly      (*((INT16U*)aDBParam+166))
#define usDBpGensVoltNormalDly     (*((INT16U*)aDBParam+167))
#define usDBpGensCurrErrHigh       (*((INT16U*)aDBParam+168))
#define usDBpGensCurrGdErrHigh     (*((INT16U*)aDBParam+169))
#define usDBpGensCurrErrorDly      (*((INT16U*)aDBParam+170))
#define usDBpGensCurrNormalDly     (*((INT16U*)aDBParam+171))
#define usDBpActPowerErrHigh       (*((INT16U*)aDBParam+172))
#define usDBpReactPowerErrHigh     (*((INT16U*)aDBParam+173))
#define usDBpAppPowerErrHigh       (*((INT16U*)aDBParam+174))
#define usDBpPowerFactorErrHigh    (*((INT16U*)aDBParam+175))
#define usDBpPowerFactorErrLow     (*((INT16U*)aDBParam+176))
#define usDBpGensPowerErrorDly     (*((INT16U*)aDBParam+177))
#define usDBpGensPowerNormalDly    (*((INT16U*)aDBParam+178))

/* *************** Part 7: Switch Assignment (179 - 212) ************** */
#define	usDBpFunctEngineStop       (*((INT16U*)aDBParam+179))
#define	usDBpFunctEngineStart      (*((INT16U*)aDBParam+180))
#define	usDBpFunctBreakerOn        (*((INT16U*)aDBParam+181))
#define	usDBpFunctBreakerOff       (*((INT16U*)aDBParam+182))
#define	usDBpFunctSpeedInc         (*((INT16U*)aDBParam+183))
#define	usDBpFunctSpeedDec         (*((INT16U*)aDBParam+184))
#define	usDBpFunctOilPump          (*((INT16U*)aDBParam+185))
#define	usDBpFunctAirHeat          (*((INT16U*)aDBParam+186))
#define	usDBpFunctAutoOrManual     (*((INT16U*)aDBParam+187))
#define	usDBpFunctMainFeedback     (*((INT16U*)aDBParam+188))
#define	usDBpFunctGensFeedback     (*((INT16U*)aDBParam+189))
#define	usDBpFunctParamLock        (*((INT16U*)aDBParam+190))
#define	usDBpFunctFuelLevel        (*((INT16U*)aDBParam+191))
#define	usDBpFunctOilPressure      (*((INT16U*)aDBParam+192))
#define	usDBpFunctCoolantTemp      (*((INT16U*)aDBParam+193))
#define	usDBpFunctCoolantLevel     (*((INT16U*)aDBParam+194))
#define	usDBpFunctAirFilter        (*((INT16U*)aDBParam+195))
#define	usDBpSwPoleEngineStop      (*((INT16U*)aDBParam+196))
#define	usDBpSwPoleEngineStart     (*((INT16U*)aDBParam+197))
#define	usDBpSwPoleBreakerOn       (*((INT16U*)aDBParam+198))
#define	usDBpSwPoleBreakerOff      (*((INT16U*)aDBParam+199))
#define	usDBpSwPoleSpeedInc        (*((INT16U*)aDBParam+200))
#define	usDBpSwPoleSpeedDec        (*((INT16U*)aDBParam+201))
#define	usDBpSwPoleOilPump         (*((INT16U*)aDBParam+202))
#define	usDBpSwPoleAirHeat         (*((INT16U*)aDBParam+203))
#define	usDBpSwPoleAutoOrManual    (*((INT16U*)aDBParam+204))
#define	usDBpSwPoleMainFeedback    (*((INT16U*)aDBParam+205))
#define	usDBpSwPoleGensFeedback    (*((INT16U*)aDBParam+206))
#define	usDBpSwPoleParamLock       (*((INT16U*)aDBParam+207))
#define	usDBpSwPoleFuelLevel       (*((INT16U*)aDBParam+208))
#define	usDBpSwPoleOilPressure     (*((INT16U*)aDBParam+209))
#define	usDBpSwPoleCoolantTemp     (*((INT16U*)aDBParam+210))
#define	usDBpSwPoleCoolantLevel    (*((INT16U*)aDBParam+211))
#define	usDBpSwPoleAirFilter       (*((INT16U*)aDBParam+212))

/* ************** Part 8: Sensor Assignment (213 - 242) *************** */
#define	usDBpAssignOilTemp         (*((INT16U*)aDBParam+213))
#define	usDBpAssignFuelTemp        (*((INT16U*)aDBParam+214))
#define	usDBpAssignBoostTemp       (*((INT16U*)aDBParam+215))
#define	usDBpAssignCoolantTemp     (*((INT16U*)aDBParam+216))
#define	usDBpAssignExhaustTemp     (*((INT16U*)aDBParam+217))
#define	usDBpAssignOilPress        (*((INT16U*)aDBParam+218))
#define	usDBpAssignFuelPress       (*((INT16U*)aDBParam+219))
#define	usDBpAssignBoostPress      (*((INT16U*)aDBParam+220))
#define	usDBpAssignCoolantPress    (*((INT16U*)aDBParam+221))
#define	usDBpAssignFuelLevel       (*((INT16U*)aDBParam+222))
#define	usDBpAssignCoolantLevel    (*((INT16U*)aDBParam+223))
#define	usDBpAssignChargerVolt     (*((INT16U*)aDBParam+224))
#define	usDBpAssignChargerCurr     (*((INT16U*)aDBParam+225))
#define	usDBpAssignStarterCurr     (*((INT16U*)aDBParam+226))
#define	usDBpAssignRackPosition    (*((INT16U*)aDBParam+227))
#define	usDBpSubstOilTemp          (*((INT16U*)aDBParam+228))
#define	usDBpSubstFuelTemp         (*((INT16U*)aDBParam+229))
#define	usDBpSubstBoostTemp        (*((INT16U*)aDBParam+230))
#define	usDBpSubstCoolantTemp      (*((INT16U*)aDBParam+231))
#define	usDBpSubstExhaustTemp      (*((INT16U*)aDBParam+232))
#define	usDBpSubstOilPress         (*((INT16U*)aDBParam+233))
#define	usDBpSubstFuelPress        (*((INT16U*)aDBParam+234))
#define	usDBpSubstBoostPress       (*((INT16U*)aDBParam+235))
#define	usDBpSubstCoolantPress     (*((INT16U*)aDBParam+236))
#define	usDBpSubstFuelLevel        (*((INT16U*)aDBParam+237))
#define	usDBpSubstCoolantLevel     (*((INT16U*)aDBParam+238))
#define	usDBpSubstChargerVolt      (*((INT16U*)aDBParam+239))
#define	usDBpSubstChargerCurr      (*((INT16U*)aDBParam+240))
#define	usDBpSubstStarterCurr      (*((INT16U*)aDBParam+241))
#define	usDBpSubstRackPosition     (*((INT16U*)aDBParam+242))

/* ************** Part 9: Sensor Calibration (243 - 299) ************** */
#define	usDBpOilTempErrLow         (*((INT16U*)aDBParam+243))
#define	usDBpOilTempErrHigh        (*((INT16U*)aDBParam+244))
#define	usDBpOilTempSenType        (*((INT16U*)aDBParam+245))
#define	usDBpFuelTempErrLow        (*((INT16U*)aDBParam+246))
#define	usDBpFuelTempErrHigh       (*((INT16U*)aDBParam+247))
#define	usDBpFuelTempSenType       (*((INT16U*)aDBParam+248))
#define	usDBpBoostTempErrLow       (*((INT16U*)aDBParam+249))
#define	usDBpBoostTempErrHigh      (*((INT16U*)aDBParam+250))
#define	usDBpBoostTempSenType      (*((INT16U*)aDBParam+251))
#define	usDBpCoolantTempErrLow     (*((INT16U*)aDBParam+252))
#define	usDBpCoolantTempErrHigh    (*((INT16U*)aDBParam+253))
#define	usDBpCoolantTempSenType    (*((INT16U*)aDBParam+254))
#define	usDBpExhaustTempErrLow     (*((INT16U*)aDBParam+255))
#define	usDBpExhaustTempErrHigh    (*((INT16U*)aDBParam+256))
#define	usDBpExhaustTempSenType    (*((INT16U*)aDBParam+257))
#define	usDBpOilPressErrLow        (*((INT16U*)aDBParam+258))
#define	usDBpOilPressErrHigh       (*((INT16U*)aDBParam+259))
#define	usDBpOilPressSenType       (*((INT16U*)aDBParam+260))
#define	usDBpFuelPressErrLow       (*((INT16U*)aDBParam+261))
#define	usDBpFuelPressErrHigh      (*((INT16U*)aDBParam+262))
#define	usDBpFuelPressSenType      (*((INT16U*)aDBParam+263))
#define	usDBpBoostPressErrLow      (*((INT16U*)aDBParam+264))
#define	usDBpBoostPressErrHigh     (*((INT16U*)aDBParam+265))
#define	usDBpBoostPressSenType     (*((INT16U*)aDBParam+266))
#define	usDBpCoolantPressErrLow    (*((INT16U*)aDBParam+267))
#define	usDBpCoolantPressErrHigh   (*((INT16U*)aDBParam+268))
#define	usDBpCoolantPressSenType   (*((INT16U*)aDBParam+269))
#define	usDBpFuelLevelErrLow       (*((INT16U*)aDBParam+270))
#define	usDBpFuelLevelErrHigh      (*((INT16U*)aDBParam+271))
#define	usDBpFuelLevelSenType      (*((INT16U*)aDBParam+272))
#define	usDBpCoolantLevelErrLow    (*((INT16U*)aDBParam+273))
#define	usDBpCoolantLevelErrHigh   (*((INT16U*)aDBParam+274))
#define	usDBpCoolantLevelSenType   (*((INT16U*)aDBParam+275))
#define	usDBpChargerVoltRefLow     (*((INT16U*)aDBParam+276))
#define	usDBpChargerVoltRefHigh    (*((INT16U*)aDBParam+277))
#define	usDBpChargerVoltAdcLow     (*((INT16U*)aDBParam+278))
#define	usDBpChargerVoltAdcHigh    (*((INT16U*)aDBParam+279))
#define	usDBpChargerVoltErrLow     (*((INT16U*)aDBParam+280))
#define	usDBpChargerVoltErrHigh    (*((INT16U*)aDBParam+281))
#define	usDBpChargerCurrRefLow     (*((INT16U*)aDBParam+282))
#define	usDBpChargerCurrRefHigh    (*((INT16U*)aDBParam+283))
#define	usDBpChargerCurrAdcLow     (*((INT16U*)aDBParam+284))
#define	usDBpChargerCurrAdcHigh    (*((INT16U*)aDBParam+285))
#define	usDBpChargerCurrErrLow     (*((INT16U*)aDBParam+286))
#define	usDBpChargerCurrErrHigh    (*((INT16U*)aDBParam+287))
#define	usDBpStarterCurrRefLow     (*((INT16U*)aDBParam+288))
#define	usDBpStarterCurrRefHigh    (*((INT16U*)aDBParam+289))
#define	usDBpStarterCurrAdcLow     (*((INT16U*)aDBParam+290))
#define	usDBpStarterCurrAdcHigh    (*((INT16U*)aDBParam+291))
#define	usDBpStarterCurrErrLow     (*((INT16U*)aDBParam+292))
#define	usDBpStarterCurrErrHigh    (*((INT16U*)aDBParam+293))
#define	usDBpRackPositionRefLow    (*((INT16U*)aDBParam+294))
#define	usDBpRackPositionRefHigh   (*((INT16U*)aDBParam+295))
#define	usDBpRackPositionAdcLow    (*((INT16U*)aDBParam+296))
#define	usDBpRackPositionAdcHigh   (*((INT16U*)aDBParam+297))
#define	usDBpRackPositionErrLow    (*((INT16U*)aDBParam+298))
#define	usDBpRackPositionErrHigh   (*((INT16U*)aDBParam+299))

/* ************* Part 10: Output Calibration (300 - 333) ************** */
#define	usDBpDigitalOut1Assign     (*((INT16U*)aDBParam+300))
#define	usDBpDigitalOut2Assign     (*((INT16U*)aDBParam+301))
#define	usDBpDigitalOut3Assign     (*((INT16U*)aDBParam+302))
#define	usDBpDigitalOut4Assign     (*((INT16U*)aDBParam+303))
#define	usDBpDigitalOut5Assign     (*((INT16U*)aDBParam+304))
#define	usDBpDigitalOut6Assign     (*((INT16U*)aDBParam+305))
#define	usDBpDigitalOut7Assign     (*((INT16U*)aDBParam+306))
#define	usDBpDigitalOut8Assign     (*((INT16U*)aDBParam+307))
#define	usDBpDigitalOut9Assign     (*((INT16U*)aDBParam+308))
#define	usDBpDigitalOut10Assign    (*((INT16U*)aDBParam+309))
#define	usDBpPWMOut1Assign         (*((INT16U*)aDBParam+310))
#define	usDBpPWMOut1RefLow         (*((INT16U*)aDBParam+311))
#define	usDBpPWMOut1RefHigh        (*((INT16U*)aDBParam+312))
#define	usDBpPWMOut1DutyLow        (*((INT16U*)aDBParam+313))
#define	usDBpPWMOut1DutyHigh       (*((INT16U*)aDBParam+314))
#define	usDBpPWMOut1Period         (*((INT16U*)aDBParam+315))
#define	usDBpPWMOut2Assign         (*((INT16U*)aDBParam+316))
#define	usDBpPWMOut2RefLow         (*((INT16U*)aDBParam+317))
#define	usDBpPWMOut2RefHigh        (*((INT16U*)aDBParam+318))
#define	usDBpPWMOut2DutyLow        (*((INT16U*)aDBParam+319))
#define	usDBpPWMOut2DutyHigh       (*((INT16U*)aDBParam+320))
#define	usDBpPWMOut2Period         (*((INT16U*)aDBParam+321))
#define	usDBpPWMOut3Assign         (*((INT16U*)aDBParam+322))
#define	usDBpPWMOut3RefLow         (*((INT16U*)aDBParam+323))
#define	usDBpPWMOut3RefHigh        (*((INT16U*)aDBParam+324))
#define	usDBpPWMOut3DutyLow        (*((INT16U*)aDBParam+325))
#define	usDBpPWMOut3DutyHigh       (*((INT16U*)aDBParam+326))
#define	usDBpPWMOut3Period         (*((INT16U*)aDBParam+327))
#define	usDBpPWMOut4Assign         (*((INT16U*)aDBParam+328))
#define	usDBpPWMOut4RefLow         (*((INT16U*)aDBParam+329))
#define	usDBpPWMOut4RefHigh        (*((INT16U*)aDBParam+330))
#define	usDBpPWMOut4DutyLow        (*((INT16U*)aDBParam+331))
#define	usDBpPWMOut4DutyHigh       (*((INT16U*)aDBParam+332))
#define	usDBpPWMOut4Period         (*((INT16U*)aDBParam+333))

/* ****************** Part 11: Backups (334 - 379) ******************** */
#define	usDBpParamBackup0          (*((INT16U*)aDBParam+334))
#define	usDBpParamBackup1          (*((INT16U*)aDBParam+335))
#define	usDBpParamBackup2          (*((INT16U*)aDBParam+336))
#define	usDBpParamBackup3          (*((INT16U*)aDBParam+337))
#define	usDBpParamBackup4          (*((INT16U*)aDBParam+338))
#define	usDBpParamBackup5          (*((INT16U*)aDBParam+339))
#define	usDBpParamBackup6          (*((INT16U*)aDBParam+340))
#define	usDBpParamBackup7          (*((INT16U*)aDBParam+341))
#define	usDBpParamBackup8          (*((INT16U*)aDBParam+342))
#define	usDBpParamBackup9          (*((INT16U*)aDBParam+343))
#define	usDBpParamBackup10         (*((INT16U*)aDBParam+344))
#define	usDBpParamBackup11         (*((INT16U*)aDBParam+345))
#define	usDBpParamBackup12         (*((INT16U*)aDBParam+346))
#define	usDBpParamBackup13         (*((INT16U*)aDBParam+347))
#define	usDBpParamBackup14         (*((INT16U*)aDBParam+348))
#define	usDBpParamBackup15         (*((INT16U*)aDBParam+349))
#define	usDBpParamBackup16         (*((INT16U*)aDBParam+350))
#define	usDBpParamBackup17         (*((INT16U*)aDBParam+351))
#define	usDBpParamBackup18         (*((INT16U*)aDBParam+352))
#define	usDBpParamBackup19         (*((INT16U*)aDBParam+353))
#define	usDBpParamBackup20         (*((INT16U*)aDBParam+354))
#define	usDBpParamBackup21         (*((INT16U*)aDBParam+355))
#define	usDBpParamBackup22         (*((INT16U*)aDBParam+356))
#define	usDBpParamBackup23         (*((INT16U*)aDBParam+357))
#define	usDBpParamBackup24         (*((INT16U*)aDBParam+358))
#define	usDBpParamBackup25         (*((INT16U*)aDBParam+359))
#define	usDBpParamBackup26         (*((INT16U*)aDBParam+360))
#define	usDBpParamBackup27         (*((INT16U*)aDBParam+361))
#define	usDBpParamBackup28         (*((INT16U*)aDBParam+362))
#define	usDBpParamBackup29         (*((INT16U*)aDBParam+363))
#define	usDBpParamBackup30         (*((INT16U*)aDBParam+364))
#define	usDBpParamBackup31         (*((INT16U*)aDBParam+365))
#define	usDBpParamBackup32         (*((INT16U*)aDBParam+366))
#define	usDBpParamBackup33         (*((INT16U*)aDBParam+367))
#define	usDBpParamBackup34         (*((INT16U*)aDBParam+368))
#define	usDBpParamBackup35         (*((INT16U*)aDBParam+369))
#define	usDBpParamBackup36         (*((INT16U*)aDBParam+370))
#define	usDBpParamBackup37         (*((INT16U*)aDBParam+371))
#define	usDBpParamBackup38         (*((INT16U*)aDBParam+372))
#define	usDBpParamBackup39         (*((INT16U*)aDBParam+373))
#define	usDBpParamBackup40         (*((INT16U*)aDBParam+374))
#define	usDBpParamBackup41         (*((INT16U*)aDBParam+375))
#define	usDBpParamBackup42         (*((INT16U*)aDBParam+376))
#define	usDBpParamBackup43         (*((INT16U*)aDBParam+377))
#define	usDBpParamBackup44         (*((INT16U*)aDBParam+378))
#define	usDBpParamBackup45         (*((INT16U*)aDBParam+379))

/* ****************** Part 12: Maps (380 - 559) *********************** */
#define	aDBpTempMapAdc              ((INT16U*)(aDBParam+380))
#define	aDBpTempMapTmp              ((INT16U*)(aDBParam+390))
#define	aDBpPressMapAdc             ((INT16U*)(aDBParam+400))
#define	aDBpPressMapPrs             ((INT16U*)(aDBParam+410))
#define	aDBpLevelMapAdc             ((INT16U*)(aDBParam+420))
#define	aDBpLevelMapLvl             ((INT16U*)(aDBParam+430))
#define	aDBpOilPressWarnSpeed       ((INT16U*)(aDBParam+440))
#define	aDBpOilPressWarnPress       ((INT16U*)(aDBParam+450))
#define	aDBpOilPressStopSpeed       ((INT16U*)(aDBParam+460))
#define	aDBpOilPressStopPress       ((INT16U*)(aDBParam+470))
#define	aDBpStatisticSpeed          ((INT16U*)(aDBParam+480))
#define	aDBpStatisticPower          ((INT16U*)(aDBParam+490))
#define	aDBpCurveBackup1            ((INT16U*)(aDBParam+500))
#define	aDBpCurveBackup2            ((INT16U*)(aDBParam+510))
#define	aDBpCurveBackup3            ((INT16U*)(aDBParam+520))
#define	aDBpCurveBackup4            ((INT16U*)(aDBParam+530))
#define	aDBpCurveBackup5            ((INT16U*)(aDBParam+540))
#define	aDBpCurveBackup6            ((INT16U*)(aDBParam+550))

/* ******************************************************************** */
/*                        Measurement Definition                        */
/* ******************************************************************** */
/* *************** Part 1: Electric Measurements (0 - 39) ************* */
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
#define usDBmGensVoltAB            (*((INT16U*)aDBMeasu+ 10))
#define usDBmGensVoltBC            (*((INT16U*)aDBMeasu+ 11))
#define usDBmGensVoltCA            (*((INT16U*)aDBMeasu+ 12))
#define usDBmGensVoltA             (*((INT16U*)aDBMeasu+ 13))
#define usDBmGensVoltB             (*((INT16U*)aDBMeasu+ 14))
#define usDBmGensVoltC             (*((INT16U*)aDBMeasu+ 15))
#define usDBmGensPhaseAB           (*((INT16U*)aDBMeasu+ 16))
#define usDBmGensPhaseBC           (*((INT16U*)aDBMeasu+ 17))
#define usDBmGensPhaseCA           (*((INT16U*)aDBMeasu+ 18))
#define usDBmGensFreq              (*((INT16U*)aDBMeasu+ 19))
#define usDBmGensCurrA             (*((INT16U*)aDBMeasu+ 20))
#define usDBmGensCurrB             (*((INT16U*)aDBMeasu+ 21))
#define usDBmGensCurrC             (*((INT16U*)aDBMeasu+ 22))
#define usDBmGensCurrGd            (*((INT16U*)aDBMeasu+ 23))
#define ssDBmActPowerA             (*((INT16S*)aDBMeasu+ 24))
#define ssDBmActPowerB             (*((INT16S*)aDBMeasu+ 25))
#define ssDBmActPowerC             (*((INT16S*)aDBMeasu+ 26))
#define ssDBmActPowerAll           (*((INT16S*)aDBMeasu+ 27))
#define ssDBmReactPowerA           (*((INT16S*)aDBMeasu+ 28))
#define ssDBmReactPowerB           (*((INT16S*)aDBMeasu+ 29))
#define ssDBmReactPowerC           (*((INT16S*)aDBMeasu+ 30))
#define ssDBmReactPowerAll         (*((INT16S*)aDBMeasu+ 31))
#define usDBmAppPowerA             (*((INT16U*)aDBMeasu+ 32))
#define usDBmAppPowerB             (*((INT16U*)aDBMeasu+ 33))
#define usDBmAppPowerC             (*((INT16U*)aDBMeasu+ 34))
#define usDBmAppPowerAll           (*((INT16U*)aDBMeasu+ 35))
#define ssDBmPowerFactorA          (*((INT16S*)aDBMeasu+ 36))
#define ssDBmPowerFactorB          (*((INT16S*)aDBMeasu+ 37))
#define ssDBmPowerFactorC          (*((INT16S*)aDBMeasu+ 38))
#define ssDBmPowerFactorAll        (*((INT16S*)aDBMeasu+ 39))

/* ************** Part 2: Main and Gens Controls (40 - 49) ************ */
#define ssDBmVoltDiffer            (*((INT16S*)aDBMeasu+ 40))
#define ssDBmFreqDiffer            (*((INT16S*)aDBMeasu+ 41))
#define ssDBmPhaseDiffer           (*((INT16S*)aDBMeasu+ 42))
#define ssDBmActPowerSetp          (*((INT16S*)aDBMeasu+ 43))
#define ssDBmReactPowerSetp        (*((INT16S*)aDBMeasu+ 44))
#define usDBmBreakerOnAllowed      (*((INT16U*)aDBMeasu+ 45))
#define usDBmMainBreakerOn         (*((INT16U*)aDBMeasu+ 46))
#define usDBmGensBreakerOn         (*((INT16U*)aDBMeasu+ 47))
#define ssDBmSpeedTuningCtrl       (*((INT16S*)aDBMeasu+ 48))
#define ssDBmAvrTuningCtrl         (*((INT16S*)aDBMeasu+ 49))

/* **************** Part 3: Engine Controls *************************** */
#define usDBmSpeed                 (*((INT16U*)aDBMeasu+ 50))
#define usDBmSpeedPickup1          (*((INT16U*)aDBMeasu+ 51))
#define usDBmSpeedPickup2          (*((INT16U*)aDBMeasu+ 52))
#define usDBmSpeedCan              (*((INT16U*)aDBMeasu+ 53))
#define usDBmSystemPhase           (*((INT16U*)aDBMeasu+ 54))
#define usDBmEngineStopped         (*((INT16U*)aDBMeasu+ 55))
#define usDBmEngineRunning         (*((INT16U*)aDBMeasu+ 56))
#define usDBmEmergnErrorToStop     (*((INT16U*)aDBMeasu+ 57))
#define usDBmCommonErrorToStop     (*((INT16U*)aDBMeasu+ 58))
#define usDBmCommonErrorToWarn     (*((INT16U*)aDBMeasu+ 59))
#define usDBmEngineStartActive     (*((INT16U*)aDBMeasu+ 60))
#define usDBmEngineStopActive      (*((INT16U*)aDBMeasu+ 61))
#define usDBmAutoModeActive        (*((INT16U*)aDBMeasu+ 62))
#define usDBmAirHeatDuration       (*((INT16U*)aDBMeasu+ 63))
#define usDBmAirHeatActive         (*((INT16U*)aDBMeasu+ 64))
#define usDBmOilPumpActive         (*((INT16U*)aDBMeasu+ 65))
#define usDBmFuelSupplyActive      (*((INT16U*)aDBMeasu+ 66))
#define usDBmStartFailTimes        (*((INT16U*)aDBMeasu+ 67))
#define usDBmStarterActive         (*((INT16U*)aDBMeasu+ 68))
#define usDBmCoolantFanActive      (*((INT16U*)aDBMeasu+ 69))
#define usDBmSpeedRatedActive      (*((INT16U*)aDBMeasu+ 70))
#define usDBmHardwareVersion       (*((INT16U*)aDBMeasu+ 71))
#define usDBmSoftwareVersion       (*((INT16U*)aDBMeasu+ 72))

/* **************** Part 3: ModBus / CanBus *************************** */
#define usDBmModBusState           (*((INT16U*)aDBMeasu+ 73))
#define usDBmCan1State             (*((INT16U*)aDBMeasu+ 74))
#define usDBmCan2State             (*((INT16U*)aDBMeasu+ 75))

/* **************** Part 4: Inputs and Outputs ************************ */
#define usDBmAdcInput                ((INT16U*)aDBMeasu+ 76)
#define usDBmAdcInput0             (*((INT16U*)aDBMeasu+ 76))
#define usDBmAdcInput1             (*((INT16U*)aDBMeasu+ 77))
#define usDBmAdcInput2             (*((INT16U*)aDBMeasu+ 78))
#define usDBmAdcInput3             (*((INT16U*)aDBMeasu+ 79))
#define usDBmAdcInput4             (*((INT16U*)aDBMeasu+ 80))
#define usDBmAdcInput5             (*((INT16U*)aDBMeasu+ 81))
#define usDBmAdcInput6             (*((INT16U*)aDBMeasu+ 82))
#define usDBmAdcInput7             (*((INT16U*)aDBMeasu+ 83))
#define usDBmAdcInput8             (*((INT16U*)aDBMeasu+ 84))
#define usDBmAdcInput9             (*((INT16U*)aDBMeasu+ 85))
#define usDBmAdcInput10            (*((INT16U*)aDBMeasu+ 86))
#define usDBmAdcInput11            (*((INT16U*)aDBMeasu+ 87))
#define usDBmAdcInput12            (*((INT16U*)aDBMeasu+ 88))
#define usDBmAdcInput13            (*((INT16U*)aDBMeasu+ 89))
#define usDBmAdcInput14            (*((INT16U*)aDBMeasu+ 90))
#define usDBmAdcInput15            (*((INT16U*)aDBMeasu+ 91))
#define usDBmAdcInput16            (*((INT16U*)aDBMeasu+ 92))
#define usDBmAdcInput17            (*((INT16U*)aDBMeasu+ 93))
#define usDBmAdcInput18            (*((INT16U*)aDBMeasu+ 94))
#define usDBmAdcInput19            (*((INT16U*)aDBMeasu+ 95))
#define usDBmAdcInput20            (*((INT16U*)aDBMeasu+ 96))
#define usDBmAdcInput21            (*((INT16U*)aDBMeasu+ 97))
#define usDBmAdcInput22            (*((INT16U*)aDBMeasu+ 98))
#define usDBmAdcInput23            (*((INT16U*)aDBMeasu+ 99))
#define usDBmSwitchesInput         (*((INT16U*)aDBMeasu+100))
#define usDBmBoardKeyInput         (*((INT16U*)aDBMeasu+101))
#define usDBmSwitchesOutput        (*((INT16U*)aDBMeasu+102))
#define usDBmBoardLedOutput        (*((INT16U*)aDBMeasu+103))

/* **************** Part 5: Switches Status *************************** */
#define	usDBmKeyMenuUp             (*((INT16U*)aDBMeasu+104))
#define	usDBmKeyMenuDown           (*((INT16U*)aDBMeasu+105))
#define	usDBmKeyMenuRight          (*((INT16U*)aDBMeasu+106))
#define	usDBmKeyMenuLeft           (*((INT16U*)aDBMeasu+107))
#define	usDBmKeyMenuEnter          (*((INT16U*)aDBMeasu+108))
#define	usDBmKeyOBD                (*((INT16U*)aDBMeasu+109))
#define	usDBmKeyEngineStop         (*((INT16U*)aDBMeasu+110))
#define	usDBmKeyEngineStart        (*((INT16U*)aDBMeasu+111))
#define	usDBmKeyModeAuto           (*((INT16U*)aDBMeasu+112))
#define	usDBmKeyModeManual         (*((INT16U*)aDBMeasu+113))
#define	usDBmKeyErrorReset         (*((INT16U*)aDBMeasu+114))
#define	usDBmKeyBreakerOn          (*((INT16U*)aDBMeasu+115))
#define	usDBmKeyBreakerOff         (*((INT16U*)aDBMeasu+116))
#define	usDBmSwitchEngineStop      (*((INT16U*)aDBMeasu+117))
#define	usDBmSwitchEngineStart     (*((INT16U*)aDBMeasu+118))
#define	usDBmSwitchBreakerOn       (*((INT16U*)aDBMeasu+119))
#define	usDBmSwitchBreakerOff      (*((INT16U*)aDBMeasu+120))
#define	usDBmSwitchSpeedInc        (*((INT16U*)aDBMeasu+121))
#define	usDBmSwitchSpeedDec        (*((INT16U*)aDBMeasu+122))
#define	usDBmSwitchOilPump         (*((INT16U*)aDBMeasu+123))
#define	usDBmSwitchAirHeat         (*((INT16U*)aDBMeasu+124))
#define	usDBmSwitchAutoOrManual    (*((INT16U*)aDBMeasu+125))
#define	usDBmSwitchMainFeedback    (*((INT16U*)aDBMeasu+126))
#define	usDBmSwitchGensFeedback    (*((INT16U*)aDBMeasu+127))
#define	usDBmSwitchParamLock       (*((INT16U*)aDBMeasu+128))
#define	usDBmSwitchFuelLevel       (*((INT16U*)aDBMeasu+129))
#define	usDBmSwitchOilPressure     (*((INT16U*)aDBMeasu+130))
#define	usDBmSwitchCoolantTemp     (*((INT16U*)aDBMeasu+131))
#define	usDBmSwitchCoolantLevel    (*((INT16U*)aDBMeasu+132))
#define	usDBmSwitchAirFilter       (*((INT16U*)aDBMeasu+133))

/* **************** Part 6: Sensors Inputs **************************** */
#define usDBmOilTemperature        (*((INT16U*)aDBMeasu+134))
#define usDBmFuelTemperature       (*((INT16U*)aDBMeasu+135))
#define usDBmBoostTemperature      (*((INT16U*)aDBMeasu+136))
#define usDBmCoolantTemperature    (*((INT16U*)aDBMeasu+137))
#define usDBmExhaustTemperature    (*((INT16U*)aDBMeasu+138))
#define usDBmOilPressure           (*((INT16U*)aDBMeasu+139))
#define usDBmFuelPressure          (*((INT16U*)aDBMeasu+140))
#define usDBmBoostPressure         (*((INT16U*)aDBMeasu+141))
#define usDBmCoolantPressure       (*((INT16U*)aDBMeasu+142))
#define usDBmFuelLevel             (*((INT16U*)aDBMeasu+143))
#define usDBmCoolantLevel          (*((INT16U*)aDBMeasu+144))
#define usDBmChargerVoltage        (*((INT16U*)aDBMeasu+145))
#define usDBmChargerCurrent        (*((INT16U*)aDBMeasu+146))
#define usDBmStarterCurrent        (*((INT16U*)aDBMeasu+147))
#define usDBmRackPosition          (*((INT16U*)aDBMeasu+148))
#define usDBmInternTemperature     (*((INT16U*)aDBMeasu+149))
#define usDBmSupplyVoltage         (*((INT16U*)aDBMeasu+150))

/* **************** Part 7: System Error Status *********************** */
#define usDBmErrorStatus1          (*((INT16U*)aDBMeasu+151))
#define usDBmErrorStatus2          (*((INT16U*)aDBMeasu+152))
#define usDBmErrorStatus3          (*((INT16U*)aDBMeasu+153))
#define usDBmErrorStatus4          (*((INT16U*)aDBMeasu+154))
#define usDBmErrorStatus5          (*((INT16U*)aDBMeasu+155))
#define usDBmErrorStatus6          (*((INT16U*)aDBMeasu+156))
#define usDBmAdcFftChannel         (*((INT16U*)aDBMeasu+157))
#define usDBmFftResult              ((INT16U*)(aDBMeasu+158))
#define usDBmFftResult0            (*((INT16U*)aDBMeasu+158))
#define usDBmFftResult1            (*((INT16U*)aDBMeasu+159))
#define usDBmFftResult2            (*((INT16U*)aDBMeasu+160))
#define usDBmFftResult3            (*((INT16U*)aDBMeasu+161))
#define usDBmFftResult4            (*((INT16U*)aDBMeasu+162))
#define usDBmFftResult5            (*((INT16U*)aDBMeasu+163))
#define usDBmFftResult6            (*((INT16U*)aDBMeasu+164))
#define usDBmFftResult7            (*((INT16U*)aDBMeasu+165))
#define usDBmFftResult8            (*((INT16U*)aDBMeasu+166))
#define usDBmFftResult9            (*((INT16U*)aDBMeasu+167))
#define usDBmFftResult10           (*((INT16U*)aDBMeasu+168))
#define usDBmFftResult11           (*((INT16U*)aDBMeasu+169))
#define usDBmFftResult12           (*((INT16U*)aDBMeasu+170))
#define usDBmFftResult13           (*((INT16U*)aDBMeasu+171))
#define usDBmFftResult14           (*((INT16U*)aDBMeasu+172))
#define usDBmFftResult15           (*((INT16U*)aDBMeasu+173))
#define usDBmFftResult16           (*((INT16U*)aDBMeasu+174))
#define usDBmFftResult17           (*((INT16U*)aDBMeasu+175))
#define usDBmFftResult18           (*((INT16U*)aDBMeasu+176))
#define usDBmFftResult19           (*((INT16U*)aDBMeasu+177))
#define usDBmFftResult20           (*((INT16U*)aDBMeasu+178))
#define usDBmFftResult21           (*((INT16U*)aDBMeasu+179))
#define usDBmFftResult22           (*((INT16U*)aDBMeasu+180))
#define usDBmFftResult23           (*((INT16U*)aDBMeasu+181))
#define usDBmFftResult24           (*((INT16U*)aDBMeasu+182))
#define usDBmFftResult25           (*((INT16U*)aDBMeasu+183))
#define usDBmFftResult26           (*((INT16U*)aDBMeasu+184))
#define usDBmFftResult27           (*((INT16U*)aDBMeasu+185))
#define usDBmFftResult28           (*((INT16U*)aDBMeasu+186))
#define usDBmFftResult29           (*((INT16U*)aDBMeasu+187))
#define usDBmFftResult30           (*((INT16U*)aDBMeasu+188))
#define usDBmFftResult31           (*((INT16U*)aDBMeasu+189))
#define usDBmMeasuBackup1          (*((INT16U*)aDBMeasu+190))
#define usDBmMeasuBackup2          (*((INT16U*)aDBMeasu+191))
#define usDBmMeasuBackup3          (*((INT16U*)aDBMeasu+192))
#define usDBmMeasuBackup4          (*((INT16U*)aDBMeasu+193))
#define usDBmMeasuBackup5          (*((INT16U*)aDBMeasu+194))
#define usDBmMeasuBackup6          (*((INT16U*)aDBMeasu+195))
#define usDBmMeasuBackup7          (*((INT16U*)aDBMeasu+196))
#define usDBmMeasuBackup8          (*((INT16U*)aDBMeasu+197))
#define usDBmMeasuBackup9          (*((INT16U*)aDBMeasu+198))
#define usDBmMeasuBackup10         (*((INT16U*)aDBMeasu+199))

/* ******************************************************************** */
/*                           Histry Definition                          */
/* ******************************************************************** */
#define aDBHstry                    ((INT16U*)(aDBMeasu+200))
#define uiDBhKwh32B                (*(INT32U*)(aDBMeasu+200))
#define usDBhKwh16L                (*((INT16U*)aDBMeasu+200))
#define usDBhKwh16U                (*((INT16U*)aDBMeasu+201))
#define uiDBhKvarh32B              (*(INT32U*)(aDBMeasu+202))
#define usDBhKvarh16L              (*((INT16U*)aDBMeasu+202))
#define usDBhKvarh16U              (*((INT16U*)aDBMeasu+203))
#define uiDBhRunTime32B            (*(INT32U*)(aDBMeasu+204))
#define usDBhRunTime16L            (*((INT16U*)aDBMeasu+204))
#define usDBhRunTime16U            (*((INT16U*)aDBMeasu+205))
#define uiDBhStartTimes32B         (*(INT32U*)(aDBMeasu+206))
#define usDBhStartTimes16L         (*((INT16U*)aDBMeasu+206))
#define usDBhStartTimes16U         (*((INT16U*)aDBMeasu+207))
#define usDBhErrorStatus1          (*((INT16U*)aDBMeasu+208))
#define usDBhErrorStatus2          (*((INT16U*)aDBMeasu+209))
#define usDBhErrorStatus3          (*((INT16U*)aDBMeasu+210))
#define usDBhErrorStatus4          (*((INT16U*)aDBMeasu+211))
#define usDBhErrorStatus5          (*((INT16U*)aDBMeasu+212))
#define usDBhErrorStatus6          (*((INT16U*)aDBMeasu+213))
#define usDBhHstryBackup0          (*((INT16U*)aDBMeasu+214))
#define usDBhHstryBackup1          (*((INT16U*)aDBMeasu+215))
#define usDBhHstryBackup2          (*((INT16U*)aDBMeasu+216))
#define usDBhHstryBackup3          (*((INT16U*)aDBMeasu+217))
#define usDBhHstryBackup4          (*((INT16U*)aDBMeasu+218))
#define usDBhHstryBackup5          (*((INT16U*)aDBMeasu+219))
#define aDBhStatisticData           ((INT16U*)(aDBMeasu+220))

/* ******************************************************************** */
/*                    End of Measurement Definition                     */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */