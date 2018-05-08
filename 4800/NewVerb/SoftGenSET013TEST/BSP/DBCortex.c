/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File DBCortex.c                         */
/*                            By: Wu Xuekui                             */
/*                             2014-10-14                               */
/* ******************************************************************** */

#define   DB_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                               DBInit()                               */
/* ******************************************************************** */
void DBInit (void)
{   uiDBStatus = 0;
    DBCmdBufInit();
    DBInitDFlash();
    if (DBEepReadParam(&aDBParam[0],
                       DB_PARAM_ADDR, DB_PARAM_SIZE) == DB_FALSE)
    {   DB_STS_SET_BIT(DB_STS_ERR_READ_PARAM);
    }   else
    {   DB_STS_CLR_BIT(DB_STS_ERR_READ_PARAM);
    }
    if (DBEepReadParam(&aDBFunct[0],
                       DB_FUNCT_ADDR, DB_FUNCT_SIZE) == DB_FALSE)
    {   DB_STS_SET_BIT(DB_STS_ERR_READ_FUNCT);
    }   else
    {   DB_STS_CLR_BIT(DB_STS_ERR_READ_FUNCT);
    }
    if (DBEepReadParam(&aDBCurve[0],
                       DB_CURVE_ADDR, DB_CURVE_SIZE) == DB_FALSE)
    {   DB_STS_SET_BIT(DB_STS_ERR_READ_CURVE);
    }   else
    {   DB_STS_CLR_BIT(DB_STS_ERR_READ_CURVE);
    }
    if (DBCheckParam() == DB_FALSE)
    {   DB_STS_SET_BIT(DB_STS_ERR_CHECK_PARAM);
        DBResetParam();
    }   else
    {   DB_STS_CLR_BIT(DB_STS_ERR_CHECK_PARAM);
    }
    if (DBCheckFunct() == DB_FALSE)
    {   DB_STS_SET_BIT(DB_STS_ERR_CHECK_FUNCT);
        DBResetFunct();
    }   else
    {   DB_STS_CLR_BIT(DB_STS_ERR_CHECK_FUNCT);
    }
    if (DBCheckCurve() == DB_FALSE)
    {   DB_STS_SET_BIT(DB_STS_ERR_CHECK_CURVE);
        DBResetCurve();
    }   else
    {   DB_STS_CLR_BIT(DB_STS_ERR_CHECK_CURVE);
    }
    DBEepInitHstryBlock();
    if (sDBHstryBlck.uiStatus == DB_BLOCK_STS_FAULT)
    {   DB_STS_SET_BIT(DB_STS_ERR_READ_HSTRY);
    }   else
    {   DB_STS_CLR_BIT(DB_STS_ERR_READ_HSTRY);
    }
    if (DBCheckHstry() == DB_FALSE)
    {   DB_STS_SET_BIT(DB_STS_ERR_CHECK_HSTRY);
        DBResetHstry();
    }   else
    {   DB_STS_CLR_BIT(DB_STS_ERR_CHECK_HSTRY);
    }
    DBResetMeasu();
}

/* ******************************************************************** */
/*                               DBStart()                              */
/* ******************************************************************** */
void DBStart (void)
{   
}

/* ******************************************************************** */
/*                               DBTaskLoop()                           */
/* ******************************************************************** */
void DBTaskLoop (void)
{   INT08U ucComd, ucErr;
    while (1)
    {   ucComd = DBTskGetCmd (DB_CMD_TO_TICKS, &ucErr);
        NumTemp[8]++;
        if (ucErr == DB_NO_ERR)
        {   /* ********************* Save History ********************* */
            if (ucComd == DB_CMD_SAVE_HSTRY)
            {   DBEepWriteRecord(&sDBHstryBlck, &aDBHstry[0]);
            }
            /* ******************** Save Parameters ******************* */
            else if (ucComd == DB_CMD_SAVE_PARAM)
            {   DBFlashErasePage(DB_PARAM_ADDR);
                if (DBEepWriteParam(&aDBParam[0],
                                    DB_PARAM_ADDR, DB_PARAM_SIZE) == DB_FALSE)
                {   DB_STS_SET_BIT(DB_STS_ERR_WRITE_PARAM);
                }   else
                {   DB_STS_CLR_BIT(DB_STS_ERR_WRITE_PARAM);
                }
            }
            /* ******************** Save Functions ******************** */
            else if (ucComd == DB_CMD_SAVE_FUNCT)
            {   DBFlashErasePage(DB_FUNCT_ADDR);
                if (DBEepWriteParam(&aDBFunct[0],
                                    DB_FUNCT_ADDR, DB_FUNCT_SIZE) == DB_FALSE)
                {   DB_STS_SET_BIT(DB_STS_ERR_WRITE_FUNCT);
                }   else
                {   DB_STS_CLR_BIT(DB_STS_ERR_WRITE_FUNCT);
                }
            }
            /* ******************** Save Curves *********************** */
            else if (ucComd == DB_CMD_SAVE_CURVE)
            {   DBFlashErasePage(DB_CURVE_ADDR);
                if (DBEepWriteParam(&aDBCurve[0],
                                    DB_CURVE_ADDR, DB_CURVE_SIZE) == DB_FALSE)
                {   DB_STS_SET_BIT(DB_STS_ERR_WRITE_CURVE);
                }   else
                {   DB_STS_CLR_BIT(DB_STS_ERR_WRITE_CURVE);
                }
            }
        }
    }
}

/* ******************************************************************** */
/*                            DBCheckParam()                            */
/* ******************************************************************** */
INT08U DBCheckParam (void)
{   if (usDBpMainSystemType > 10)
    {   return DB_FALSE;
    }
    if ((usDBpMainVoltRated < 100) || (usDBpMainVoltRated > 10000))
    {   return DB_FALSE;
    }
    if ((usDBpMainFreqRated < 100) || (usDBpMainFreqRated > 10000))
    {   return DB_FALSE;
    }
    if (usDBpGeneratorType > 10)
    {   return DB_FALSE;
    }
    if ((usDBpGensVoltRated < 100) || (usDBpGensVoltRated > 10000))
    {   return DB_FALSE;
    }
    if ((usDBpGensFreqRated < 100) || (usDBpGensFreqRated > 10000))
    {   return DB_FALSE;
    }
    if (usDBpEngineType > 100)
    {   return DB_FALSE;
    }
    if ((usDBpEngTeethCrank1 < 2) || (usDBpEngTeethCrank1 > 1000))
    {   return DB_FALSE;
    }
    if ((usDBpEngTeethCrank2 < 2) || (usDBpEngTeethCrank2 > 1000))
    {   return DB_FALSE;
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                            DBResetParam()                            */
/* ******************************************************************** */
void DBResetParam (void)
{   /* ************** Part 1: Grid Electric Parameters **************** */
    usDBpMainSystemType       = 0;                       /*  0 - 3      */
    usDBpMainVoltCtRatio      = 1;
    usDBpMainVoltRated        = 2300;                    /*  230.0V     */
    usDBpMainVoltErrLow       = 1840;                    /*  230*0.8    */
    usDBpMainVoltErrHigh      = 2760;                    /*  230*1.2    */
    usDBpMainVoltErrDly       = 50;                      /*  5.0S       */
    usDBpMainVoltLostLow      = 300;                     /*  30.0V      */
    usDBpMainVoltLostDly      = 50;                      /*  5S         */
    usDBpMainFreqRated        = 5000;                    /*  50.0Hz     */
    usDBpMainFreqErrLow       = 4500;                    /*  45.0Hz     */
    usDBpMainFreqErrHigh      = 5500;                    /*  55.0Hz     */
    usDBpMainFreqErrDly       = 50;                      /*  5.0S       */
    usDBpMainPhaseErrLow      = SF_ANGLE_TO_16U(90.0f);  /*  90=65536/4 */
    usDBpMainPhaseErrHigh     = SF_ANGLE_TO_16U(150.0f); /*  150=32768  */
    usDBpMainPhaseErrDly      = 20;                      /*  2.0S       */
    usDBpMainCurrCtRatio      = 5;                       /*  5          */
    usDBpMainCurrRated        = 100;                     /*  10.0A      */
    usDBpMainCurrShort        = 500;                     /*  50.0A      */
    usDBpMainCurrShortDly     = 10;                      /*  1.0S       */
    usDBpMainCurrLongDly      = 3000;                    /*  300S(200A) */
    usDBpMainCurrGndErrHigh   = 10;                      /*  1.0A       */
    usDBpMainCurrGndErrDly    = 10;                      /*  1.0S       */
    usDBpMainCurrUnbErrHigh   = 50;                      /*  5.0A       */
    usDBpMainCurrUnbErrDly    = 100;                     /*  10.0S      */
    usDBpMainActPwrRated      = 690;                     /*  69.0Kw     */
    usDBpMainActPwrErrHigh    = 800;                     /*  80.0Kw     */
    usDBpMainActPwrErrDly     = 100;                     /*  10.0S      */
    usDBpMainReactPwrRated    = 69;                      /*  6.9KVAR    */
    usDBpMainReactPwrErrHigh  = 100;                     /*  10.0KVAR   */
    usDBpMainReactPwrErrDly   = 100;                     /*  10.0S      */
    usDBpMainAppPwrErrHigh    = 900;                     /*  90.0KVA    */
    usDBpMainAppPwrErrDly     = 100;                     /*  10.0S      */
    usDBpMainRocofErrHigh     = 65535;                   /*  Disabled   */
    usDBpMainRocofErrDly      = 65535;                   /*  Disabled   */
    usDBpMainVoltUnbErrHigh   = 2000;                    /*  200.0V     */
    usDBpMainVoltUnbErrDly    = 100;                     /*  10.0S      */
    usDBpMainSyncVoltErrLow   = 2185;                    /*  230*0.95   */
    usDBpMainSyncVoltErrHigh  = 2415;                    /*  230*1.05   */
    usDBpMainSyncVoltErrDly   = 50;                      /*  5.0S       */
    usDBpMainSyncFreqErrLow   = 4750;                    /*  50*0.95    */
    usDBpMainSyncFreqErrHigh  = 5250;                    /*  50*1.05    */
    usDBpMainSyncFreqErrDly   = 50;                      /*  5.0S       */
    /* ************** Part 2: Generator Setpint Parameters ************ */
    usDBpGeneratorType        = 1;                       /*  1          */
    usDBpGensPoleNum          = 4;                       /*  4 Poles    */
    usDBpGensVoltCtRatio      = 1;                       /*  1          */
    usDBpGensVoltRated        = 2300;                    /*  230.0V     */
    usDBpGensVoltToLoad       = 2070;                    /*  230*0.9    */
    usDBpGensVoltToLoadDly    = 50;                      /*  5.0S       */
    usDBpGensVoltWarnLow      = 1955;                    /*  230*0.85   */
    usDBpGensVoltWarnHigh     = 2530;                    /*  230*1.1    */
    usDBpGensVoltWarnDly      = 50;                      /*  5.0S       */
    usDBpGensVoltStopLow      = 1840;                    /*  230*0.8    */
    usDBpGensVoltStopHigh     = 2760;                    /*  230*1.2    */
    usDBpGensVoltStopDly      = 50;                      /*  5.0S       */
    usDBpGensFreqRated        = 5000;                    /*  50.0Hz     */
    usDBpGensFreqToLoad       = 4500;                    /*  45.0Hz     */
    usDBpGensFreqToLoadDly    = 50;                      /*  5.0S       */
    usDBpGensFreqWarnLow      = 4250;                    /*  42.5Hz     */
    usDBpGensFreqWarnHigh     = 5500;                    /*  55.0Hz     */
    usDBpGensFreqWarnDly      = 50;                      /*  5.0S       */
    usDBpGensFreqStopLow      = 4000;                    /*  40.0Hz     */
    usDBpGensFreqStopHigh     = 5700;                    /*  57.0Hz     */
    usDBpGensFreqStopDly      = 50;                      /*  5.0S       */
    usDBpGensPhaseErrLow      = SF_ANGLE_TO_16U(90.0f);  /*  90=65536/4 */
    usDBpGensPhaseErrHigh     = SF_ANGLE_TO_16U(180.0f); /*  180=32768  */
    usDBpGensPhaseErrDly      = 20;                      /*  2.0S       */
    usDBpGensCurrCtRatio      = 10;                      /*  10         */
    usDBpGensCurrRated        = 100;                     /*  10.0A      */
    usDBpGensCurrShort        = 500;                     /*  50.0A      */
    usDBpGensCurrShortDly     = 10;                      /*  1.0S       */
    usDBpGensCurrLongDly      = 3000;                    /*  300S(200A) */
    usDBpGensCurrGndErrHigh   = 10;                      /*  1.0A       */
    usDBpGensCurrGndErrDly    = 10;                      /*  1.0S       */
    usDBpGensCurrUnbErrHigh   = 50;                      /*  5.0A       */
    usDBpGensCurrUnbErrDly    = 100;                     /*  10.0S      */
    usDBpGensActPwrRated      = 690;                     /*  69.0Kw     */
    usDBpGensActPwrErrHigh    = 800;                     /*  80.0Kw     */
    usDBpGensActPwrErrDly     = 100;                     /*  10.0S      */
    usDBpGensReactPwrRated    = 69;                      /*  6.9KVAR    */
    usDBpGensReactPwrErrHigh  = 100;                     /*  10.0KVAR   */
    usDBpGensReactPwrErrDly   = 100;                     /*  10.0S      */
    usDBpGensAppPwrErrHigh    = 900;                     /*  90.0KVA    */
    usDBpGensAppPwrErrDly     = 100;                     /*  10.0S      */
    usDBpGensInvPwrErrHigh    = 69;                      /*  69*0.1     */
    usDBpGensInvPwrErrDly     = 10;                      /*  1.0S       */
    usDBpGensFactorErrLow     = 800;                     /*  0.8        */
    usDBpGensFactorErrHigh    = 1200;                    /*  1.2        */
    usDBpGensFactorErrDly     = 100;                     /*  10.0S      */
    usDBpGensMagLostErrHigh   = 65535;                   /*  Disabled   */
    usDBpGensMagLostErrDly    = 100;                     /*  10.0S      */
    /* ************** Part 3: Engine Setpint Parameters *************** */
    usDBpEngineType           = 1;
    usDBpEngTeethCrank1       = 120;
    usDBpEngTeethCrank2       = 120;
    usDBpEngSpeedFilter1      = 120;
    usDBpEngSpeedFilter2      = 120;
    usDBpEngSpeedStart1       = 40;                      /*  40 rpm     */
    usDBpEngSpeedStart2       = 400;                     /*  400 rpm    */
    usDBpEngSpeedIdle         = 700;                     /*  700 rpm    */
    usDBpEngSpeedIdleMin      = 600;                     /*  600 rpm    */
    usDBpEngSpeedIdleMax      = 800;                     /*  800 rpm    */
    usDBpEngSpeedRated        = 1500;                    /*  1500 rpm   */
    usDBpEngSpeedRatedMin     = 1350;                    /*  1350 rpm   */
    usDBpEngSpeedWarnLow      = 1400;                    /*  1400 rpm   */
    usDBpEngSpeedWarnHigh     = 1600;                    /*  1600 rpm   */
    usDBpEngSpeedWarnDly      = 30;                      /*  3.0S       */
    usDBpEngSpeedStopLow      = 1300;                    /*  1300 rpm   */
    usDBpEngSpeedStopHigh     = 1700;                    /*  1700 rpm   */
    usDBpEngSpeedStopDly      = 5;                       /*  0.5S       */
    usDBpEngAutoStartTimesMax = 3;                       /*  3 times    */
    usDBpEngHandStartTimesMax = 1;                       /*  1 times    */
    usDBpEngStoppingTimeMax   = 100;                     /*  10.0S      */
    usDBpEngRampTimeMaxToWarn = 200;                     /*  20.0S      */
    usDBpEngRampTimeMaxToStop = 400;                     /*  40.0S      */
    usDBpEngSpeedDeltaToWarn  = 300;                     /*  300 rpm    */
    usDBpEngSpeedDeltaToStop  = 400;                     /*  400 rpm    */
    usDBpEngSpeedDeltaErrDly  = 100;                     /*  10.0S      */
    usDBpEngTempHeaterCold    = SF_TMP_TO_16U(-10.0f);   /*  -10.0C     */
    usDBpEngTempHeaterWarm    = SF_TMP_TO_16U(0.0f);     /*  0.0C       */
    usDBpEngOilPumpOnTime     = 600;                     /*  60.0S      */
    usDBpEngOilPumpOffPress   = 1000;                    /*  1Bar=10kpa */
    usDBpEngCoolFanOnTemp     = SF_TMP_TO_16U(92.0f);    /*  92.0C      */
    usDBpEngCoolFanOffDly     = 600;                     /*  60.0S      */
    usDBpEngStartSignal       = 0;                       /*  Disable    */
    usDBpEngStartFreq         = 0;                       /*  Disable    */
    usDBpEngStartOilPress     = 0;                       /*  Disable    */
    /* ************** Part 4: Timer Setpint Parameters **************** */
    usDBpSysOperationMode     = 0;                       /*  SingleMode */
    usDBpTimeStoppedToReady   = 100;                     /*  10.0S      */
    usDBpTimeReadyToStarting  = 100;                     /*  10.0S      */
    usDBpTimeIdlingToRampUp   = 100;                     /*  10.0S      */
    usDBpTimeIdlingToStopping = 100;                     /*  10.0S      */
    usDBpTimeRatedReadyDly    = 100;                     /*  10.0S      */
    usDBpTimeRatedToRampDowm  = 100;                     /*  10.0S      */
    usDBpTimeWorkToStopDly    = 100;                     /*  10.0S      */
    usDBpTimeOfLoadingOn      = 50;                      /*  5.0S       */
    usDBpTimeOfLoadingOff     = 50;                      /*  5.0S       */
    usDBpTimeOfMainSwitchOn   = 50;                      /*  5.0S       */
    usDBpTimeOfMainSwitchOff  = 50;                      /*  5.0S       */
    usDBpTimeOfGensSwitchOn   = 50;                      /*  5.0S       */
    usDBpTimeOfGensSwitchOff  = 50;                      /*  5.0S       */
    usDBpTimeOfFixedPowerUp   = 600;                     /*  60.0S      */
    usDBpTimeOfFixedPowerDown = 600;                     /*  60.0S      */
    usDBpTimeOfStarterOn      = 80;                      /*  8.0S       */
    usDBpTimeOfStarterOff     = 100;                     /*  10.0S      */
    usDBpTimeOfHeaterAtCold   = 0;                       /*  0.0S       */
    usDBpTimeOfHeaterAtWarm   = 0;                       /*  0.0S       */
    usDBpTimeOfSyncFailToWarn = 300;                     /*  30.0S      */
    usDBpTimeOfSyncFailToStop = 600;                     /*  60.0S      */
    usDBpTimeOfStatistics     = 3000;                    /*  300.0S     */
    usDBpTimeOfStopOutput     = 200;                     /*  20.0S      */
    usDBpTimeOfMainSwOutput   = 50;                      /*  5.0S       */
    usDBpTimeOfGensSwOutput   = 50;                      /*  5.0S       */
    /* ************** Part 5: Synchronization & Load share ************ */
    usDBpSyncVoltDiffMax      = 30;                      /*  3.0V       */
    usDBpSyncPhaseDiffMax     = SF_ANGLE_TO_16U(10.0f);  /*  10 Degree  */
    usDBpSyncFreqDiffPosMax   = 20;                      /*  0.2Hz      */
    usDBpSyncFreqDiffNegMax   = 10;                      /*  0.1Hz      */
    usDBpSyncFreqDiffSetp     = 10;                      /*  0.1Hz      */
    usDBpSyncGovCtrlInit      = 5000;                    /*  5000-2.5V  */
    usDBpSyncGovGain          = 20;
    usDBpSyncGovStability     = 1000;
    usDBpSyncGovDerivative    = 0;
    usDBpSyncAvrCtrlInit      = 5000;                    /*  5000-2.5V  */
    usDBpSyncAvrGain          = 20;
    usDBpSyncAvrStability     = 1000;
    usDBpSyncAvrDerivative    = 0;
    usDBpLoadReactCtrlMode    = 0;                       /*  ReactPower */
    usDBpLoadActPowerSetp     = 500;                     /*  50 KW      */
    usDBpLoadReactPowerSetp   = 50;                      /*  5  KVAR    */
    usDBpLoadPowerFactorSetp  = 980;                     /*  0.98       */
    usDBpLoadGovGain          = 20;
    usDBpLoadGovStability     = 1000;
    usDBpLoadGovDerivative    = 0;
    usDBpLoadAvrGain          = 20;
    usDBpLoadAvrStability     = 1000;
    usDBpLoadAvrDerivative    = 0;
    /* ************** Part 6: CanBus / ModBus ************************* */
    usDBpModulePassword       = 5634;
    usDBpModuleLanguage       = 1;                       /*  Chinese    */
    usDBpModBus1Baudrate      = 3;                       /*  Baud=9600  */
    usDBpModBus1Address       = 1;                       /*  Addr=1     */
    usDBpModBus2Baudrate      = 3;                       /*  Baud=9600  */
    usDBpModBus2Address       = 1;                       /*  Addr=1     */
    usDBpCan1Baudrate         = 250;                     /*  Baud=250k  */
    usDBpCan1Address          = 1;                       /*  Addr=1     */
    usDBpCan2Baudrate         = 250;                     /*  Baud=250k  */
    usDBpCan2Address          = 1;                       /*  Addr=1     */
    usDBpCanLoadPrsntToStart  = 800;                     /*  >80% Start */
    usDBpCanLoadPrsntStartDly = 50;                      /*  5.0S       */
    usDBpCanLoadPrsntToStop   = 200;                     /*  <20% Stop  */
    usDBpCanLoadPrsntStopDly  = 100;                     /*  10.0S      */
    /* ************** Part 7: Monitoring & Warn *********************** */
    usDBpMntrCoolTempToWarn   = SF_TMP_TO_16U(95.0f);    /*  95.0C      */
    usDBpMntrCoolTempWarnDly  = 50;                      /*  5.0S       */
    usDBpMntrCoolTempToStop   = SF_TMP_TO_16U(98.0f);    /*  98.0C      */
    usDBpMntrCoolTempStopDly  = 30;                      /*  3.0S       */
    usDBpMntrOilTempToWarn    = SF_TMP_TO_16U(95.0f);    /*  95.0C      */
    usDBpMntrOilTempWarnDly   = 50;                      /*  5.0S       */
    usDBpMntrOilTempToStop    = SF_TMP_TO_16U(98.0f);    /*  98.0C      */
    usDBpMntrOilTempStopDly   = 30;                      /*  3.0S       */
    usDBpMntrOilPresToWarn    = 125;                     /*  125 kpa    */
    usDBpMntrOilPresWarnDly   = 50;                      /*  5.0S       */
    usDBpMntrOilPresToStop    = 105;                     /*  105 kpa    */
    usDBpMntrOilPresStopDly   = 30;                      /*  3.0S       */
    usDBpMntrOilPresStartDly  = 100;                     /*  10.0S      */
    usDBpMntrFuelLevelToWarn  = 100;                     /*  10%        */
    usDBpMntrFuelLevelWarnDly = 100;                     /*  10.0S      */
    usDBpMntrCoolLevelToWarn  = 100;                     /*  10%        */
    usDBpMntrCoolLevelWarnDly = 100;                     /*  10.0S      */
    usDBpMntrBatt1VoltToWarn  = 210;                     /*  21.0V      */
    usDBpMntrBatt1VoltWarnDly = 50;                      /*  5.0S       */
    usDBpMntrBatt2VoltToWarn  = 210;                     /*  21.0V      */
    usDBpMntrBatt2VoltWarnDly = 50;                      /*  5.0S       */
    usDBpMntrChargVoltToWarn  = 100;                     /*  10.0V      */
    usDBpMntrChargVoltWarnDly = 50;                      /*  5.0S       */
    usDBpMntrChargVoltStartDly = 50;                     /*  5.0S       */
    usDBpMntrAirFilterWarnDly = 50;                      /*  5.0S       */
    /* ************** Part 8: Maintenance Parameters ****************** */
    usDBpMaintenance          = 0;
    /* ************** Part 9: Electric Parameters ********************* */
    usDBpAdcAmpMainVoltA      = 1024;
    usDBpAdcAmpMainVoltB      = 1024;
    usDBpAdcAmpMainVoltC      = 1024;
    usDBpAdcAmpMainVoltAB     = 1024;
    usDBpAdcAmpMainVoltBC     = 1024;
    usDBpAdcAmpMainVoltCA     = 1024;
    usDBpAdcAmpMainCurrA      = 1024;
    usDBpAdcAmpMainCurrB      = 1024;
    usDBpAdcAmpMainCurrC      = 1024;
    usDBpAdcAmpMainCurrGnd    = 1024;
    usDBpAdcAmpGensVoltA      = 1024;
    usDBpAdcAmpGensVoltB      = 1024;
    usDBpAdcAmpGensVoltC      = 1024;
    usDBpAdcAmpGensVoltAB     = 1024;
    usDBpAdcAmpGensVoltBC     = 1024;
    usDBpAdcAmpGensVoltCA     = 1024;
    usDBpAdcAmpGensCurrA      = 1024;
    usDBpAdcAmpGensCurrB      = 1024;
    usDBpAdcAmpGensCurrC      = 1024;
    usDBpAdcAmpGensCurrGnd    = 1024;
    usDBpAdcChFilter0         = 16;
    usDBpAdcChFilter1         = 16;
    usDBpAdcChFilter2         = 16;
    usDBpAdcChFilter3         = 16;
    usDBpAdcChFilter4         = 16;
    usDBpAdcChFilter5         = 16;
    usDBpAdcChFilter6         = 16;
    usDBpAdcChFilter7         = 16;
    usDBpAdcChFilter8         = 16;
    usDBpAdcChFilter9         = 16;
    usDBpAdcChFilter10        = 16;
    usDBpAdcChFilter11        = 16;
    usDBpAdcChFilter12        = 16;
    usDBpAdcChFilter13        = 16;
    usDBpAdcChFilter14        = 16;
    usDBpAdcChFilter15        = 16;
    usDBpAdcChRef0            = 2047;
    usDBpAdcChRef1            = 2047;
    usDBpAdcChRef2            = 2047;
    usDBpAdcChRef3            = 2047;
    usDBpAdcChRef4            = 2047;
    usDBpAdcChRef5            = 2047;
    usDBpAdcChRef6            = 2047;
    usDBpAdcChRef7            = 2047;
    usDBpAdcChRef8            = 2047;
    usDBpAdcChRef9            = 2047;
    usDBpAdcChRef10           = 2047;
    usDBpAdcChRef11           = 2047;
    usDBpAdcChRef12           = 2047;
    usDBpAdcChRef13           = 2047;
    usDBpAdcChRef14           = 2047;
    usDBpAdcChRef15           = 2047;
    /* ************** Part 10: Switch Assignment ********************** */
    usDBpDinAssigEngineStop   = 1000;
    usDBpDinAssigEngineStart  = 1000;
    usDBpDinAssigOilPump      = 1000;
    usDBpDinAssigHeater       = 1000;
    usDBpDinAssigMainFeedback = 1000;
    usDBpDinAssigGensFeedback = 1000;
    usDBpDinAssigOilTemp      = 1000;
    usDBpDinAssigFuelLevel    = 1000;
    usDBpDinAssigOilPressure  = 1000;
    usDBpDinAssigCoolantTemp  = 1000;
    usDBpDinAssigCoolantLevel = 1000;
    usDBpDinAssigAirFilter    = 1000;
    usDBpDinAssigEmergStop    = 1000;
    /* ************** Part 11: Sensor Assignment ********************** */
    usDBpAinCoolTempAssign    = 100;
    usDBpAinCoolTempSenType   = 0;
    usDBpAinCoolTempSubst     = SF_TMP_TO_16U(25.0f);
    usDBpAinCoolTempErrLow    = SF_V5_TO_ADC(0.2f);
    usDBpAinCoolTempErrHigh   = SF_V5_TO_ADC(4.8f);
    usDBpAinOilTempAssign     = 100;
    usDBpAinOilTempSenType    = 0;
    usDBpAinOilTempSubst      = SF_TMP_TO_16U(25.0f);
    usDBpAinOilTempErrLow     = SF_V5_TO_ADC(0.2f);
    usDBpAinOilTempErrHigh    = SF_V5_TO_ADC(4.8f);
    usDBpAinOilPresAssign     = 100;
    usDBpAinOilPresSenType    = 0;
    usDBpAinOilPresSubst      = 500;
    usDBpAinOilPresErrLow     = SF_V5_TO_ADC(0.2f);
    usDBpAinOilPresErrHigh    = SF_V5_TO_ADC(4.8f);
    usDBpAinFuelLevelAssign   = 100;
    usDBpAinFuelLevelSenType  = 0;
    usDBpAinFuelLevelSubst    = 500;
    usDBpAinFuelLevelErrLow   = SF_V5_TO_ADC(0.2f);
    usDBpAinFuelLevelErrHigh  = SF_V5_TO_ADC(4.8f);
    usDBpAinCoolLevelAssign   = 100;
    usDBpAinCoolLevelSenType  = 0;
    usDBpAinCoolLevelSubst    = 500;
    usDBpAinCoolLevelErrLow   = SF_V5_TO_ADC(0.2f);
    usDBpAinCoolLevelErrHigh  = SF_V5_TO_ADC(4.8f);
    usDBpAinChargCurrAssign   = 100;
    usDBpAinChargCurrSubst    = 0;
    usDBpAinChargCurrErrLow   = SF_V5_TO_ADC(0.2f);
    usDBpAinChargCurrErrHigh  = SF_V5_TO_ADC(4.8f);
    usDBpAinChargCurrRefLow   = 0;
    usDBpAinChargCurrRefHigh  = 100;
    usDBpAinChargCurrAdcLow   = SF_V5_TO_ADC(0.5f);
    usDBpAinChargCurrAdcHigh  = SF_V5_TO_ADC(4.5f);
    /* ************** Part 12: Output Calibration ********************* */
    usDBpDout1Assign          = 88;                      /*  Starter    */
    usDBpDout2Assign          = 90;                      /*  AirHeater  */
    usDBpDout3Assign          = 91;                      /*  OilPump    */
    usDBpDout4Assign          = 92;                      /*  CoolFan    */
    usDBpDout5Assign          = 93;                      /*  FuelSupply */
    usDBpDout6Assign          = 94;                      /*  SpeedRated */
    usDBpDout7Assign          = 109;                     /*  MainSwOn   */
    usDBpDout8Assign          = 110;                     /*  MainSwOff  */
    usDBpDout9Assign          = 113;                     /*  GensSwOn   */
    usDBpDout10Assign         = 114;                     /*  GensSwOff  */
    usDBpDout11Assign         = 2000;                    /*  Disabled   */
    usDBpDout12Assign         = 2000;                    /*  Disabled   */
    usDBpDout13Assign         = 2000;                    /*  Disabled   */
    usDBpDout14Assign         = 2000;                    /*  Disabled   */
    usDBpDout15Assign         = 2000;                    /*  Disabled   */
    usDBpDout16Assign         = 2000;                    /*  Disabled   */
    usDBpPWMOut1Assign        = 121;                     /*  GovCtrl    */
    usDBpPWMOut1RefLow        = 0;                       /*  0-1%       */
    usDBpPWMOut1RefHigh       = 10000;                   /*  10000-99%  */
    usDBpPWMOut1DutyLow       = 10;                      /*  1% duty    */
    usDBpPWMOut1DutyHigh      = 990;                     /*  99% duty   */
    usDBpPWMOut1Period        = 1000;                    /*  1000 us    */
    usDBpPWMOut2Assign        = 122;                     /*  AvrCtrl    */
    usDBpPWMOut2RefLow        = 0;                       /*  0-1%       */
    usDBpPWMOut2RefHigh       = 10000;                   /*  10000-99%  */
    usDBpPWMOut2DutyLow       = 10;                      /*  1% duty    */
    usDBpPWMOut2DutyHigh      = 990;                     /*  99% duty   */
    usDBpPWMOut2Period        = 1000;                    /*  1000 us    */
    usDBpPWMOut3Assign        = 2000;
    usDBpPWMOut3RefLow        = 2000;
    usDBpPWMOut3RefHigh       = 2000;
    usDBpPWMOut3DutyLow       = 2000;
    usDBpPWMOut3DutyHigh      = 2000;
    usDBpPWMOut3Period        = 2000;
    usDBpPWMOut4Assign        = 2000;
    usDBpPWMOut4RefLow        = 2000;
    usDBpPWMOut4RefHigh       = 2000;
    usDBpPWMOut4DutyLow       = 2000;
    usDBpPWMOut4DutyHigh      = 2000;
    usDBpPWMOut4Period        = 2000;
}

/* ******************************************************************** */
/*                            DBCheckFunct()                            */
/* ******************************************************************** */
INT08U DBCheckFunct (void)
{   if (usDBfMainVoltErrAct > 10)
    {   return DB_FALSE;
    }
    if (usDBfMainFreqErrAct > 10)
    {   return DB_FALSE;
    }
    if (usDBfMainPhaseErrAct > 10)
    {   return DB_FALSE;
    }
    if (usDBfGensPhaseErrAct > 10)
    {   return DB_FALSE;
    }
    if (usDBfGensCurrShortErrAct > 10)
    {   return DB_FALSE;
    }
    if (usDBfGensCurrLongErrAct > 10)
    {   return DB_FALSE;
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                            DBResetFunct()                            */
/* ******************************************************************** */
void DBResetFunct (void)
{   (void)SFFill16u(&aDBFunct[0],0,DB_FUNCT_SIZE);
}

/* ******************************************************************** */
/*                            DBCheckCurve()                            */
/* ******************************************************************** */
INT08U DBCheckCurve (void)
{   if (aDBcTempMapAdc[0] > 4095)
    {   return DB_FALSE;
    }
    if (aDBcTempMapAdc[9] > 4095)
    {   return DB_FALSE;
    }
    if (aDBcPressMapAdc[0] > 4095)
    {   return DB_FALSE;
    }
    if (aDBcPressMapAdc[9] > 4095)
    {   return DB_FALSE;
    }
    if (aDBcLevelMapAdc[0] > 4095)
    {   return DB_FALSE;
    }
    if (aDBcLevelMapAdc[9] > 4095)
    {   return DB_FALSE;
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                            DBResetCurve()                            */
/* ******************************************************************** */
void DBResetCurve (void)
{   (void)SFFill16u(&aDBCurve[0],0,DB_CURVE_SIZE);
}

/* ******************************************************************** */
/*                            DBCheckHstry()                            */
/* ******************************************************************** */
INT08U DBCheckHstry (void)
{   if (uiDBhKwh32B == 0xFFFFFFFF)
    {   return DB_FALSE;
    }
    if (uiDBhKvarh32B == 0xFFFFFFFF)
    {   return DB_FALSE;
    }
    if (uiDBhRunTime32B == 0xFFFFFFFF)
    {   return DB_FALSE;
    }
    if (uiDBhStartTimes32B == 0xFFFFFFFF)
    {   return DB_FALSE;
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                            DBResetHstry()                            */
/* ******************************************************************** */
void DBResetHstry (void)
{   (void)SFFill16u(&aDBHstry[0],0,DB_HSTRY_SIZE);
}

/* ******************************************************************** */
/*                            DBResetMeasu()                            */
/* ******************************************************************** */
void DBResetMeasu (void)
{   (void)SFFill16u(&aDBMeasu[0],0,DB_MEASU_NOR_SIZE);
}

/* ******************************************************************** */
/*                            DBEepReadParam()                          */
/* ******************************************************************** */
INT08U DBEepReadParam (INT16U *pData, INT32U uiAddr, INT16U usSize)
{   INT16U usChck, usData;
    usChck = 0;
    while (usSize--)
    {   usData  = DBFlashRead16u(uiAddr);
        *pData  = usData;
        usChck += usData;
        uiAddr += 2;
        pData++;
    }
    if (usChck != DBFlashRead16u(uiAddr))
    {   return DB_FALSE;
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                            DBEepWriteParam()                         */
/* ******************************************************************** */
INT08U DBEepWriteParam (INT16U *pData, INT32U uiAddr, INT16U usSize)
{   INT16U usChck, usData;
    usChck = 0;
    while (usSize--)
    {   usData  = *pData++;
        if (DBFlashWrite16u(uiAddr,usData) != DB_FLASH_STS_COMPLETE)
        {   return DB_FALSE;
        }
        usChck += usData;
        uiAddr += 2;
    }
    if (DBFlashWrite16u(uiAddr,usChck) != DB_FLASH_STS_COMPLETE)
    {   return DB_FALSE;
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                         DBEepInitHstryBlock()                        */
/* ******************************************************************** */
void DBEepInitHstryBlock (void)
{   INT32U uiAddrErase;
    DB_EEP_BLOCK *pBlck;
    pBlck              = &sDBHstryBlck;
    pBlck->uiStatus    = DB_BLOCK_STS_FAULT;
    pBlck->uiHead      = DB_HSTRY_RECORD_HEAD;
    pBlck->uiPageMask  = DB_FLASH_PAGE_MSK;
    pBlck->uiPageSiz8  = DB_FLASH_PAGE_SIZ;
    pBlck->uiRcrdSiz8  = DB_HSTRY_RECORD_SIZE;
    pBlck->uiDatSiz16  = DB_HSTRY_SIZE16;
    pBlck->uiAddrMin   = DB_HSTRY_ADDR;
    pBlck->uiAddrMax   = DB_HSTRY_ADDR+DB_FLASH_PAGE_SIZ*DB_HSTRY_PAGE_NUM;
    pBlck->uiAddrCurr  = pBlck->uiAddrMin;
    pBlck->uiAddrNext  = pBlck->uiAddrMin;
    pBlck->uiCPageAMax = pBlck->uiAddrMin+pBlck->uiPageSiz8-pBlck->uiRcrdSiz8;
    pBlck->uiNPageAMin = pBlck->uiAddrMin+pBlck->uiPageSiz8;
    (void)DBEepCheckRecord(pBlck);
    if (pBlck->uiStatus == DB_BLOCK_STS_WRITED)
    {   (void)DBEepReadRecord(pBlck, &aDBHstry[0]);
    }
    else if (pBlck->uiStatus == DB_BLOCK_STS_ERASED)
    {   (void)DBResetHstry();
        (void)DBEepWriteRecord(pBlck, &aDBHstry[0]);
    }
    else if (pBlck->uiStatus == DB_BLOCK_STS_FAULT)
    {   for (uiAddrErase  = pBlck->uiAddrMin;
             uiAddrErase  < pBlck->uiAddrMax;
             uiAddrErase += pBlck->uiPageSiz8)
        {   (void)DBFlashErasePage(uiAddrErase);
        }
        (void)DBResetHstry();
        (void)DBEepWriteRecord(pBlck, &aDBHstry[0]);
    }
}

/* ******************************************************************** */
/*                         DBEepCheckRecord()                           */
/* ******************************************************************** */
void DBEepCheckRecord (DB_EEP_BLOCK *pBlck)
{   INT32U uiNext, uiAOut, uiHead, uiPage;
    uiAOut = pBlck->uiAddrMax;
    for (uiPage  = pBlck->uiAddrMin;
         uiPage  < uiAOut;
         uiPage += pBlck->uiPageSiz8)
    {   uiHead   = DBFlashRead32u(uiPage);
        if (uiHead != 0xFFFFFFFF)
        {   break;
        }
    }
    if (uiHead == pBlck->uiHead)
    {   pBlck->uiCPageAMax = uiPage + pBlck->uiPageSiz8 - pBlck->uiRcrdSiz8;
        pBlck->uiNPageAMin = uiPage + pBlck->uiPageSiz8;
        if (pBlck->uiNPageAMin >= pBlck->uiAddrMax)
        {   pBlck->uiNPageAMin  = pBlck->uiAddrMin;
        }
        uiAOut = uiPage + pBlck->uiPageSiz8;
        for (uiNext  = uiPage + pBlck->uiRcrdSiz8;
             uiNext  < uiAOut;
             uiNext += pBlck->uiRcrdSiz8)
        {   if (DBFlashRead32u(uiNext) != pBlck->uiHead)
            {   break;
            }
        }
        pBlck->uiAddrNext  = uiNext;
        pBlck->uiAddrCurr  = uiNext - pBlck->uiRcrdSiz8;
        pBlck->uiStatus    = DB_BLOCK_STS_WRITED;
    }
    else if (uiHead == 0xFFFFFFFF)
    {   pBlck->uiCPageAMax = pBlck->uiAddrMin+pBlck->uiPageSiz8-pBlck->uiRcrdSiz8;
        pBlck->uiNPageAMin = pBlck->uiAddrMin+pBlck->uiPageSiz8;
        pBlck->uiAddrNext  = pBlck->uiAddrMin;
        pBlck->uiAddrCurr  = pBlck->uiAddrMin;
        pBlck->uiStatus    = DB_BLOCK_STS_ERASED;
    }
    else
    {   pBlck->uiCPageAMax = pBlck->uiAddrMin+pBlck->uiPageSiz8-pBlck->uiRcrdSiz8;
        pBlck->uiNPageAMin = pBlck->uiAddrMin+pBlck->uiPageSiz8;
        pBlck->uiAddrNext  = pBlck->uiAddrMin;
        pBlck->uiAddrCurr  = pBlck->uiAddrMin;
        pBlck->uiStatus    = DB_BLOCK_STS_FAULT;
    }
}

/* ******************************************************************** */
/*                         DBEepReadRecord()                            */
/* ******************************************************************** */
INT08U DBEepReadRecord (DB_EEP_BLOCK *pBlck, INT16U *pData)
{   INT32U uiHead;
    uiHead = DBFlashRead32u(pBlck->uiAddrCurr);
    if (uiHead != pBlck->uiHead)
    {   return DB_FALSE;
    }
    (void)DBFlashRead16p(pBlck->uiAddrCurr+4, pData, pBlck->uiDatSiz16);
    return DB_TRUE;
}

/* ******************************************************************** */
/*                         DBEepWriteRecord()                           */
/* ******************************************************************** */
void DBEepWriteRecord (DB_EEP_BLOCK *pBlck, INT16U *pData)
{   INT32U uiAddrErase;
    uiAddrErase = pBlck->uiAddrCurr & pBlck->uiPageMask;
    if (pBlck->uiAddrNext  <= pBlck->uiCPageAMax)
    {  (void)DBFlashWrite16p(pBlck->uiAddrNext+4, pData, pBlck->uiDatSiz16);
       (void)DBFlashWrite32u(pBlck->uiAddrNext, pBlck->uiHead);
        pBlck->uiAddrCurr   = pBlck->uiAddrNext;
        pBlck->uiAddrNext  += pBlck->uiRcrdSiz8;
    }   else
    {   pBlck->uiAddrNext   = pBlck->uiNPageAMin;
       (void)DBFlashWrite16p(pBlck->uiAddrNext+4, pData, pBlck->uiDatSiz16);
       (void)DBFlashWrite32u(pBlck->uiAddrNext, pBlck->uiHead);
        pBlck->uiAddrCurr   = pBlck->uiAddrNext;
        pBlck->uiCPageAMax  = pBlck->uiAddrNext+pBlck->uiPageSiz8-pBlck->uiRcrdSiz8;
        pBlck->uiAddrNext  += pBlck->uiRcrdSiz8;
        pBlck->uiNPageAMin += pBlck->uiPageSiz8;
        if (pBlck->uiNPageAMin >= pBlck->uiAddrMax)
        {   pBlck->uiNPageAMin  = pBlck->uiAddrMin;
        }
       (void)DBFlashErasePage(uiAddrErase);
    }
}

/* ******************************************************************** */
/*                           DBInitDFlash()                             */
/* ******************************************************************** */
void DBInitDFlash (void)
{ /*  INT32U uiTmp;
    uiTmp        =  FLASH->ACR;
    uiTmp       &= ~FLASH_ACR_LATENCY;
    uiTmp       |=  FLASH_ACR_LATENCY_1;
    FLASH->ACR   =  uiTmp; */
    FLASH->KEYR  =  DB_FLASH_KEY1;
    FLASH->KEYR  =  DB_FLASH_KEY2;
   #if (DB_CPU_STM32F103_ON == 1)
    FLASH->KEYR2 =  DB_FLASH_KEY1;
    FLASH->KEYR2 =  DB_FLASH_KEY2;
   #endif
}

/* ******************************************************************** */
/*                           DBGetBank1Status()                         */
/* ******************************************************************** */
INT32U DBGetBank1Status (void)
{   INT32U uiStatus;
    uiStatus = FLASH->SR;
    if ((uiStatus & FLASH_SR_BSY) != 0)
    {   return DB_FLASH_STS_BUSY;
    }
    else if ((uiStatus & FLASH_SR_PGERR) != 0)
    {   return DB_FLASH_STS_ERR_PG;
    }
    else if ((uiStatus & FLASH_SR_WRPRTERR) != 0 )
    {   return DB_FLASH_STS_ERR_WRP;
    }
    return DB_FLASH_STS_COMPLETE;
}

/* ******************************************************************** */
/*                           DBGetBank2Status()                         */
/* ******************************************************************** */
#if (DB_CPU_STM32F103_ON == 1)
INT32U DBGetBank2Status (void)
{   INT32U uiStatus;
    uiStatus = FLASH->SR2;
    if ((uiStatus & FLASH_SR_BSY) != 0)
    {   return DB_FLASH_STS_BUSY;
    }
    else if ((uiStatus & FLASH_SR_PGERR) != 0)
    {   return DB_FLASH_STS_ERR_PG;
    }
    else if ((uiStatus & FLASH_SR_WRPRTERR) != 0)
    {   return DB_FLASH_STS_ERR_WRP;
    }
    return DB_FLASH_STS_COMPLETE;
}
#endif

/* ******************************************************************** */
/*                        DBWaitBank1Complete()                         */
/* ******************************************************************** */
INT32U DBWaitBank1Complete (INT32U uiDelay)
{   while (uiDelay--)
    {   if (DBGetBank1Status() == DB_FLASH_STS_COMPLETE)
        {   return DB_FLASH_STS_COMPLETE;
        }
    }
    return DB_FLASH_STS_TIMEOUT;
}

/* ******************************************************************** */
/*                        DBWaitBank2Complete()                         */
/* ******************************************************************** */
#if (DB_CPU_STM32F103_ON == 1)
INT32U DBWaitBank2Complete (INT32U uiDelay)
{   while (uiDelay--)
    {   if (DBGetBank2Status() == DB_FLASH_STS_COMPLETE)
        {   return DB_FLASH_STS_COMPLETE;
        }
    }
    return DB_FLASH_STS_TIMEOUT;
}
#endif

/* ******************************************************************** */
/*                         DBFlashErasePage()                           */
/* ******************************************************************** */
#if (DB_CPU_STM32F103_ON == 1)
INT32U DBFlashErasePage (INT32U uiAddr)
{   INT32U uiStatus;
    if (uiAddr < DB_FLASH_BANK1_ADR_MAX)
    {   uiStatus = DBWaitBank1Complete(800000);
        if (uiStatus  ==  DB_FLASH_STS_COMPLETE)
        {   FLASH->CR |=  (INT32U)FLASH_CR_PER;
            FLASH->AR  =  uiAddr;
            FLASH->CR |=  (INT32U)FLASH_CR_STRT;
            uiStatus   =  DBWaitBank1Complete(800000);
            FLASH->CR &= ~(INT32U)FLASH_CR_PER;
        } 
    }
    else
    {   uiStatus = DBWaitBank2Complete(800000);
        if (uiStatus  ==  DB_FLASH_STS_COMPLETE)
        {   FLASH->CR2 |=  (INT32U)FLASH_CR_PER;
            FLASH->AR2  =  uiAddr;
            FLASH->CR2 |=  (INT32U)FLASH_CR_STRT;
            uiStatus    =  DBWaitBank2Complete(800000);
            FLASH->CR2 &= ~(INT32U)FLASH_CR_PER;
        } 
    }
    return uiStatus;
}
#else
INT32U DBFlashErasePage (INT32U uiAddr)
{   INT32U uiStatus;
    uiStatus = DBWaitBank1Complete(800000);
    if (uiStatus  ==  DB_FLASH_STS_COMPLETE)
    {   FLASH->CR |=  (INT32U)FLASH_CR_PER;
        FLASH->AR  =  uiAddr;
        FLASH->CR |=  (INT32U)FLASH_CR_STRT;
        uiStatus   =  DBWaitBank1Complete(800000);
        FLASH->CR &= ~(INT32U)FLASH_CR_PER;
    } 
    return uiStatus;
}
#endif

/* ******************************************************************** */
/*                          DBFlashWrite16u()                           */
/* ******************************************************************** */
#if (DB_CPU_STM32F103_ON == 1)
INT32U DBFlashWrite16u (INT32U uiAddr, INT16U usData)
{   INT32U uiStatus;
    uiAddr  &= 0xFFFFFFFE;
    if (uiAddr < DB_FLASH_BANK1_ADR_MAX)
    {   uiStatus = DBWaitBank1Complete(10000);
        if (uiStatus  ==  DB_FLASH_STS_COMPLETE)
        {   FLASH->CR |=  (INT32U)FLASH_CR_PG;
            *(VINT16U*)uiAddr = usData;
            uiStatus   =  DBWaitBank1Complete(10000);
            FLASH->CR &= ~(INT32U)FLASH_CR_PG;
        }
    }
    else
    {   uiStatus = DBWaitBank2Complete(10000);
        if (uiStatus   ==  DB_FLASH_STS_COMPLETE)
        {   FLASH->CR2 |=  (INT32U)FLASH_CR_PG;
            *(VINT16U*)uiAddr = usData;
            uiStatus    =  DBWaitBank2Complete(10000);
            FLASH->CR2 &= ~(INT32U)FLASH_CR_PG;
        }
    }
    return uiStatus;
}
#else
INT32U DBFlashWrite16u (INT32U uiAddr, INT16U usData)
{   INT32U uiStatus;
    uiAddr  &= 0xFFFFFFFE;
    uiStatus = DBWaitBank1Complete(10000);
    if (uiStatus  ==  DB_FLASH_STS_COMPLETE)
    {   FLASH->CR |=  (INT32U)FLASH_CR_PG;
        *(VINT16U*)uiAddr = usData;
        uiStatus   =  DBWaitBank1Complete(10000);
        FLASH->CR &= ~(INT32U)FLASH_CR_PG;
    } 
    return uiStatus;
}
#endif

/* ******************************************************************** */
/*                          DBFlashWrite32u()                           */
/* ******************************************************************** */
INT32U DBFlashWrite32u (INT32U uiAddr, INT32U uiData)
{   INT32U uiTmp;
    uiAddr &= 0xFFFFFFFE;
    uiTmp   = DBFlashWrite16u(uiAddr, (INT16U)uiData);
    if (uiTmp == DB_FLASH_STS_COMPLETE)
    {   uiTmp  = DBFlashWrite16u(uiAddr+2, (INT16U)(uiData >> 16));
    }
    return uiTmp;
}

/* ******************************************************************** */
/*                          DBFlashWrite16p()                           */
/* ******************************************************************** */
INT32U DBFlashWrite16p (INT32U uiAddr, INT16U *pData, INT32U uiSize)
{   INT32U uiTmp;
    uiAddr &= 0xFFFFFFFE;
    while (uiSize--)
    {   uiTmp = DBFlashWrite16u(uiAddr,*pData);
        if (uiTmp != DB_FLASH_STS_COMPLETE)
        {   return uiTmp;
        }
        uiAddr += 2;
        pData++;
    }
    return DB_FLASH_STS_COMPLETE;
}

/* ******************************************************************** */
/*                           DBFlashRead16u()                           */
/* ******************************************************************** */
INT16U DBFlashRead16u (INT32U uiAddr)
{   return *((VINT16U*)uiAddr);
}

/* ******************************************************************** */
/*                           DBFlashRead32u()                           */
/* ******************************************************************** */
INT32U DBFlashRead32u (INT32U uiAddr)
{   return *((VINT32U*)uiAddr);
}

/* ******************************************************************** */
/*                           DBFlashRead16p()                           */
/* ******************************************************************** */
void DBFlashRead16p (INT32U uiAddr, INT16U *pData, INT32U uiSize)
{   VINT16U *pTemp;
    pTemp = (VINT16U*)(uiAddr & 0xFFFFFFFE);
    while (uiSize--)
    {   *pData++ = *pTemp++;
    }
}

/* ******************************************************************** */
/*                           DBCmdBufInit()                             */
/* ******************************************************************** */
void DBCmdBufInit (void)
{   DB_CMD_RING *pbuf;
    pbuf = &sDBCmdRingBuf;
    pbuf->usRingBufRxCtr   =  0;
    pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxOutPtr = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxSem    =  OSSemCreate(0);
}

/* ******************************************************************** */
/*                           DBTskGetCmd()                              */
/* ******************************************************************** */
INT08U DBTskGetCmd (INT16U to, INT08U *err)
{   OS_CPU_SR cpu_sr = 0;
    INT08U c;
    INT08U oserr;
    DB_CMD_RING *pbuf;
    pbuf = &sDBCmdRingBuf;
    (void)OSSemPend(pbuf->pRingBufRxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   *err   = OS_ERR_RX_TIMEOUT;
        return OS_NULL;
    }   else
    {   OS_ENTER_CRITICAL();
        pbuf->usRingBufRxCtr--;
        c = *pbuf->pRingBufRxOutPtr++;
        if (pbuf->pRingBufRxOutPtr == &pbuf->ucRingBufRx[DB_CMD_BUF_SIZE])
        {   pbuf->pRingBufRxOutPtr  = &pbuf->ucRingBufRx[0];
        }
        OS_EXIT_CRITICAL();
        *err = OS_NO_ERR;
        return c;
    }
}

/* ******************************************************************** */
/*                           DBTskPutCmd()                              */
/* ******************************************************************** */
void DBTskPutCmd (INT08U c)
{   OS_CPU_SR cpu_sr = 0;
    DB_CMD_RING *pbuf;
    pbuf = &sDBCmdRingBuf;
    if (pbuf->usRingBufRxCtr < DB_CMD_BUF_SIZE)
    {   OS_ENTER_CRITICAL();
        pbuf->usRingBufRxCtr++;
        *pbuf->pRingBufRxInPtr++ = c;
        if (pbuf->pRingBufRxInPtr == &pbuf->ucRingBufRx[DB_CMD_BUF_SIZE])
        {   pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
        }
        OS_EXIT_CRITICAL();
        (void)OSSemPost(pbuf->pRingBufRxSem);
    }
}

/* ******************************************************************** */
/*                           DBGetParam16u ()                           */
/* ******************************************************************** */
INT16U DBGetParam16u (INT16U usBegin)
{   if (usBegin < DB_PARAM_SIZE)
    {   return aDBParam[usBegin];
    }   else
    {   return 0;
    }
}

/* ******************************************************************** */
/*                           DBGetParam16p ()                           */
/* ******************************************************************** */
INT08U DBGetParam16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if ((usBegin + usSize) >= DB_PARAM_SIZE)
    {   return DB_FALSE;
    }
    while (usSize--)
    {   *pDat++ = DBGetParam16u(usBegin++);
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBGetParam08p ()                           */
/* ******************************************************************** */
INT08U DBGetParam08p (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT16U usTemp;
    if ((usBegin + usSize) >= DB_PARAM_SIZE)
    {   return DB_FALSE;
    }
    while (usSize--)
    {   usTemp  = DBGetParam16u(usBegin++);
       #if (DB_SCI_UC_LOW_FIRST == 1)
        *pDat++ = DB_UC_LOW(usTemp);
        *pDat++ = DB_UC_HIGH(usTemp);
       #else
        *pDat++ = DB_UC_HIGH(usTemp);
        *pDat++ = DB_UC_LOW(usTemp);
       #endif
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetParam16u ()                           */
/* ******************************************************************** */
INT08U DBSetParam16u (INT16U usBegin, INT16U usValue)
{   if (usBegin >= DB_PARAM_SIZE)
    {   return DB_FALSE;
    }
    aDBParam[usBegin] = usValue;
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetParam16p ()                           */
/* ******************************************************************** */
INT08U DBSetParam16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   while (usSize--)
    {   if (DBSetParam16u(usBegin++, *pDat++) == DB_FALSE)
        {   return DB_FALSE;
        }
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetParam08p ()                           */
/* ******************************************************************** */
INT08U DBSetParam08p (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT08U ucTmp1, ucTmp2;
    while (usSize--)
    {   ucTmp1 = *pDat++;
        ucTmp2 = *pDat++;
       #if (DB_SCI_UC_LOW_FIRST == 1)
        if (DBSetParam16u(usBegin++, DB_US_CREAT(ucTmp2, ucTmp1)) == DB_FALSE)
        {   return DB_FALSE;
        }
       #else
        if (DBSetParam16u(usBegin++, DB_US_CREAT(ucTmp1, ucTmp2)) == DB_FALSE)
        {   return DB_FALSE;
        }
       #endif
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBCheckParam16u ()                         */
/* ******************************************************************** */
INT08U DBCheckParam16u (INT16U usBegin, INT16U usValue)
{   if (DBGetParam16u(usBegin) != usValue)
    {   return DB_DIFFERENT;
    }
    return DB_SAME;
}

/* ******************************************************************** */
/*                           DBCheckParam16p ()                         */
/* ******************************************************************** */
INT08U DBCheckParam16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   while (usSize--)
    {   if (DBGetParam16u(usBegin) != (*pDat))
        {   return DB_DIFFERENT;
        }
        usBegin++;
        pDat++;
    }
    return DB_SAME;
}

/* ******************************************************************** */
/*                           DBGetMeasu16u ()                           */
/* ******************************************************************** */
INT16U DBGetMeasu16u (INT16U usBegin)
{   if (usBegin < DB_MEASU_SIZE)
    {   return aDBMeasu[usBegin];
    }   else
    {   return 0;
    }
}

/* ******************************************************************** */
/*                           DBGetMeasu16p ()                           */
/* ******************************************************************** */
INT08U DBGetMeasu16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if ((usBegin + usSize) >= DB_MEASU_SIZE)
    {   return DB_FALSE;
    }
    while (usSize--)
    {   *pDat++ = DBGetMeasu16u(usBegin++);
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBGetMeasu08p ()                           */
/* ******************************************************************** */
INT08U DBGetMeasu08p (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT16U usTemp;
    if ((usBegin + usSize) >= DB_MEASU_SIZE)
    {   return DB_FALSE;
    }
    while (usSize--)
    {   usTemp  = DBGetMeasu16u(usBegin++);
       #if (DB_SCI_UC_LOW_FIRST == 1)
        *pDat++ = DB_UC_LOW(usTemp);
        *pDat++ = DB_UC_HIGH(usTemp);
       #else
        *pDat++ = DB_UC_HIGH(usTemp);
        *pDat++ = DB_UC_LOW(usTemp);
       #endif
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetMeasu16u ()                           */
/* ******************************************************************** */
INT08U DBSetMeasu16u (INT16U usBegin, INT16U usValue)
{   if (usBegin >= DB_MEASU_SIZE)
    {   return DB_FALSE;
    }
    aDBMeasu[usBegin] = usValue;
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetMeasu16p ()                           */
/* ******************************************************************** */
INT08U DBSetMeasu16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   while (usSize--)
    {   if (DBSetMeasu16u(usBegin++, *pDat++) == DB_FALSE)
        {   return DB_FALSE;
        }
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetMeasu08p ()                           */
/* ******************************************************************** */
INT08U DBSetMeasu08p (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT08U ucTmp1, ucTmp2;
    while (usSize--)
    {   ucTmp1 = *pDat++;
        ucTmp2 = *pDat++;
       #if (DB_SCI_UC_LOW_FIRST == 1)
        if (DBSetMeasu16u(usBegin++, DB_US_CREAT(ucTmp2, ucTmp1)) == DB_FALSE)
        {   return DB_FALSE;
        }
       #else
        if (DBSetMeasu16u(usBegin++, DB_US_CREAT(ucTmp1, ucTmp2)) == DB_FALSE)
        {   return DB_FALSE;
        }
       #endif
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBCheckMeasu16u ()                         */
/* ******************************************************************** */
INT08U DBCheckMeasu16u (INT16U usBegin, INT16U usValue)
{   if (DBGetMeasu16u(usBegin) != usValue)
    {   return DB_DIFFERENT;
    }
    return DB_SAME;
}

/* ******************************************************************** */
/*                           DBCheckMeasu16p ()                         */
/* ******************************************************************** */
INT08U DBCheckMeasu16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   while (usSize--)
    {   if (DBGetMeasu16u(usBegin) != (*pDat))
        {   return DB_DIFFERENT;
        }
        usBegin++;
        pDat++;
    }
    return DB_SAME;
}

/* ******************************************************************** */
/*                           DBGetFunct16u ()                           */
/* ******************************************************************** */
INT16U DBGetFunct16u (INT16U usBegin)
{   if (usBegin < DB_FUNCT_SIZE)
    {   return aDBFunct[usBegin];
    }   else
    {   return 0;
    }
}

/* ******************************************************************** */
/*                           DBGetFunct16p ()                           */
/* ******************************************************************** */
INT08U DBGetFunct16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if ((usBegin + usSize) >= DB_FUNCT_SIZE)
    {   return DB_FALSE;
    }
    while (usSize--)
    {   *pDat++ = DBGetFunct16u(usBegin++);
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBGetFunct08p ()                           */
/* ******************************************************************** */
INT08U DBGetFunct08p (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT16U usTemp;
    if ((usBegin + usSize) >= DB_FUNCT_SIZE)
    {   return DB_FALSE;
    }
    while (usSize--)
    {   usTemp  = DBGetFunct16u(usBegin++);
       #if (DB_SCI_UC_LOW_FIRST == 1)
        *pDat++ = DB_UC_LOW(usTemp);
        *pDat++ = DB_UC_HIGH(usTemp);
       #else
        *pDat++ = DB_UC_HIGH(usTemp);
        *pDat++ = DB_UC_LOW(usTemp);
       #endif
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetFunct16u ()                           */
/* ******************************************************************** */
INT08U DBSetFunct16u (INT16U usBegin, INT16U usValue)
{   if (usBegin >= DB_FUNCT_SIZE)
    {   return DB_FALSE;
    }
    aDBFunct[usBegin] = usValue;
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetFunct16p ()                           */
/* ******************************************************************** */
INT08U DBSetFunct16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   while (usSize--)
    {   if (DBSetFunct16u(usBegin++, *pDat++) == DB_FALSE)
        {   return DB_FALSE;
        }
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetFunct08p ()                           */
/* ******************************************************************** */
INT08U DBSetFunct08p (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT08U ucTmp1, ucTmp2;
    while (usSize--)
    {   ucTmp1 = *pDat++;
        ucTmp2 = *pDat++;
       #if (DB_SCI_UC_LOW_FIRST == 1)
        if (DBSetFunct16u(usBegin++, DB_US_CREAT(ucTmp2, ucTmp1)) == DB_FALSE)
        {   return DB_FALSE;
        }
       #else
        if (DBSetFunct16u(usBegin++, DB_US_CREAT(ucTmp1, ucTmp2)) == DB_FALSE)
        {   return DB_FALSE;
        }
       #endif
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBCheckFunct16u ()                         */
/* ******************************************************************** */
INT08U DBCheckFunct16u (INT16U usBegin, INT16U usValue)
{   if (DBGetFunct16u(usBegin) != usValue)
    {   return DB_DIFFERENT;
    }
    return DB_SAME;
}

/* ******************************************************************** */
/*                           DBCheckFunct16p ()                         */
/* ******************************************************************** */
INT08U DBCheckFunct16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   while (usSize--)
    {   if (DBGetFunct16u(usBegin) != (*pDat))
        {   return DB_DIFFERENT;
        }
        usBegin++;
        pDat++;
    }
    return DB_SAME;
}

/* ******************************************************************** */
/*                           DBGetCurve16u ()                           */
/* ******************************************************************** */
INT16U DBGetCurve16u (INT16U usBegin)
{   if (usBegin < DB_CURVE_SIZE)
    {   return aDBCurve[usBegin];
    }   else
    {   return 0;
    }
}

/* ******************************************************************** */
/*                           DBGetCurve16p ()                           */
/* ******************************************************************** */
INT08U DBGetCurve16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if ((usBegin + usSize) >= DB_CURVE_SIZE)
    {   return DB_FALSE;
    }
    while (usSize--)
    {   *pDat++ = DBGetCurve16u(usBegin++);
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBGetCurve08p ()                           */
/* ******************************************************************** */
INT08U DBGetCurve08p (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT16U usTemp;
    if ((usBegin + usSize) >= DB_CURVE_SIZE)
    {   return DB_FALSE;
    }
    while (usSize--)
    {   usTemp  = DBGetCurve16u(usBegin++);
       #if (DB_SCI_UC_LOW_FIRST == 1)
        *pDat++ = DB_UC_LOW(usTemp);
        *pDat++ = DB_UC_HIGH(usTemp);
       #else
        *pDat++ = DB_UC_HIGH(usTemp);
        *pDat++ = DB_UC_LOW(usTemp);
       #endif
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetCurve16u ()                           */
/* ******************************************************************** */
INT08U DBSetCurve16u (INT16U usBegin, INT16U usValue)
{   if (usBegin >= DB_CURVE_SIZE)
    {   return DB_FALSE;
    }
    aDBCurve[usBegin] = usValue;
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetCurve16p ()                           */
/* ******************************************************************** */
INT08U DBSetCurve16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   while (usSize--)
    {   if (DBSetCurve16u(usBegin++, *pDat++) == DB_FALSE)
        {   return DB_FALSE;
        }
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetCurve08p ()                           */
/* ******************************************************************** */
INT08U DBSetCurve08p (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT08U ucTmp1, ucTmp2;
    while (usSize--)
    {   ucTmp1 = *pDat++;
        ucTmp2 = *pDat++;
       #if (DB_SCI_UC_LOW_FIRST == 1)
        if (DBSetCurve16u(usBegin++, DB_US_CREAT(ucTmp2, ucTmp1)) == DB_FALSE)
        {   return DB_FALSE;
        }
       #else
        if (DBSetCurve16u(usBegin++, DB_US_CREAT(ucTmp1, ucTmp2)) == DB_FALSE)
        {   return DB_FALSE;
        }
       #endif
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBCheckCurve16u ()                         */
/* ******************************************************************** */
INT08U DBCheckCurve16u (INT16U usBegin, INT16U usValue)
{   if (DBGetCurve16u(usBegin) != usValue)
    {   return DB_DIFFERENT;
    }
    return DB_SAME;
}

/* ******************************************************************** */
/*                           DBCheckCurve16p ()                         */
/* ******************************************************************** */
INT08U DBCheckCurve16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   while (usSize--)
    {   if (DBGetCurve16u(usBegin) != (*pDat))
        {   return DB_DIFFERENT;
        }
        usBegin++;
        pDat++;
    }
    return DB_SAME;
}

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
