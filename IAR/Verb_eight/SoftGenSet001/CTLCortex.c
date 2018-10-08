/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File CTLCortex.c                        */
/*                            By: Wu Xuekui                             */
/*                             2014-10-14                               */
/* ******************************************************************** */

#define   CTL_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                              CTLInit()                               */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
void CTLInit (void)
{   uiCTLStatus = 0;
    SFMonitorMainCurrLongInit(50);
    SFMonitorGensCurrLongInit(50);
    sCTLKeyErrReset.usDelayOn  = OS_TICKS_PER_SEC / 2;
    sCTLKeyErrReset.usDelayOff = 0;
    SFResetSwitchDelay(&sCTLKeyErrReset);
    SFFuelStealInit(&sSFFuelSteal);
    CTLMainSwitchInit(&sCTLMainSwitch);
    CTLGensSwitchInit(&sCTLGensSwitch);
    ERR_ES7_SET_BIT(ERR_ES7_CMD_TO_STOP);
}
#endif

/* ******************************************************************** */
/*                            CTLSysMonitor()                           */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
void CTLSysMonitor (void)
{   INT08U ucEnable;
    usDBmHardwareVersion = XIO_VERSION;
    usDBmSoftwareVersion = CTL_VERSION;
    if((SFSwitchDelay(usDBmKeyErrorReset,&sCTLKeyErrReset) != 0) &&
       (usDBmEngEngineIsStopped != 0))
    {   SFResetSwitchDelay(&sCTLKeyErrReset);
        SFResetOneError();
    }
    SFMonitorMainVolt(SF_ENABLE);
    SFMonitorMainFreq(SF_ENABLE);
    SFMonitorMainPhase(SF_ENABLE);
    SFMonitorMainSynVolt();
    SFMonitorMainSynFreq();
    SFMonitorMainVoltLost();
    if (usDBfMainCurrCtFunc == CTL_CT4FUNC_MAIN_A)
    {   SFMonitorMainCurrShort(SF_ENABLE);
        SFMonitorMainCurrLong(SF_ENABLE);
        SFMonitorMainCurrUnb(SF_ENABLE);
        SFMonitorMainActPwr(SF_ENABLE);
        SFMonitorMainReactPwr(SF_ENABLE);
        SFMonitorMainAppPwr(SF_ENABLE);
        SFMonitorMainRocof(SF_ENABLE);
        SFMonitorMainVector(SF_ENABLE);
    }
    else if (usDBfMainCurrCtFunc == CTL_CT4FUNC_MAIN_GND)
    {   SFMonitorMainCurrGnd(SF_ENABLE);
    }
    else if (usDBfMainCurrCtFunc == CTL_CT4FUNC_GENS_GND)
    {   SFMonitorGensCurrGnd(SF_ENABLE);
    }
    usDBmMainVoltIsLost   = CTLCheckIsMainVoltLost();
    usDBmMainVoltIsNormal = CTLCheckIsMainVoltNormal();
    SFMonitorGensCurrShort(SF_ENABLE);
    SFMonitorGensCurrLong(SF_ENABLE);
    SFMonitorGensCurrUnb(SF_ENABLE);
    usDBmGensIsWorking = CTLCheckIsGensWorking(usDBmSystemPhase);
    if (usDBmGensIsWorking != 0)
    {   ucEnable = SF_ENABLE;
    }   else
    {   ucEnable = SF_DISABLE;
    }
    SFMonitorGensVolt(ucEnable);
    SFMonitorGensFreq(ucEnable);
    SFMonitorGensPhase(ucEnable);
    SFMonitorGensActPwr(ucEnable);
    SFMonitorGensReactPwr(ucEnable);
    SFMonitorGensAppPwr(ucEnable);
    SFMonitorGensInvPwr(ucEnable);
    SFMonitorGensFactor(ucEnable);
    SFMonitorGensMagLost(ucEnable);
    SFMonitorGensReadyToLoad();
    SFMonitorGensSyncTimeOver(usDBmSystemPhase);
    SFMonitorEngSpeedLow(ucEnable);
    SFMonitorEngSpeedHigh();
    SFMonitorEngSpeedDelta(usDBmSystemPhase);
    SFMonitorEngSpeedRamp(usDBmSystemPhase);
    SFMonitorEngStopping(usDBmSystemPhase);
    SFMonitorEngTemperature();
    SFMonitorEngPressure();
    SFMonitorEngLevel();
    SFMonitorEngVoltage();
    SFMonitorEngFilter();
    SFMonitorEepDataError();
    if (SFMonitorPowerOff(usDBmAinBatt1Voltage,
                          usDBmAinBatt2Voltage) != SF_FALSE)
    {   (void)DBTskPutCmd(DB_CMD_SAVE_HSTRY);
        (void)DBTskPutCmd(DB_CMD_POWER_OFF);
    }
}
#endif

/* ******************************************************************** */
/*                         CTLSysController()                           */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
void CTLSysController (void)
{   INT16U usPhase, usSpeed, usAuto;
    usSpeed                  = usDBmEngSpeed;
    usPhase                  = usDBmSystemPhase;
    usAuto                   = CTLGetSysAutoOrManual();
    usDBmSysAutoOrManual     = usAuto;
    usDBmEngEngineIsStopped  = SFGetEngStsStopped(usSpeed);
    usDBmEngEngineIsRunning  = SFGetEngStsRunning(usSpeed);
    usDBmEngEngineIsIdling   = SFGetEngStsIdling(usSpeed);
    usDBmEngEngineIsRated    = SFGetEngStsRated(usSpeed);
    usDBmSysEmergnCmdToStop  = CTLGetEmergnCmdToStop();
    usDBmSysEmergnErrToStop  = CTLGetEmergnErrToStop();
    usDBmSysCommonErrToStop  = CTLGetCommonErrToStop();
    usDBmSysCommonErrToWarn  = CTLGetCommonErrToWarn();
    usDBmGensIsReadyToLoad   = CTLCheckGensReadyToLoad();
    usDBmMainVoltReadyToSyn  = CTLCheckMainReadyToSync();
    usDBmSyncConditionMatch  = CTLCheckSyncCondition(usDBmMainVoltReadyToSyn);
    if (usDBpSysOperationMode == CTL_MODE_SIMPLE)
    {   usDBmSysCommonCmdToStop = CTLGetSimpleCmdToStop(usAuto);
        usDBmSysCommonCmdToSwOn = 0;
        usDBmSysGensSwOnCndt    = 0;
        usDBmSysMainSwOnCndt    = 0;
        usPhase                 = CTLGetSimpleSysPhase(usPhase);
        usDBmSystemPhase        = usPhase;
        usDBmSyncLoadCtrlMode   = CTLGetSimplePidMode(usPhase);
    }
    else if (usDBpSysOperationMode == CTL_MODE_SINGLE)
    {   usDBmSysCommonCmdToStop = CTLGetSingleCmdToStop(usAuto);
        usDBmSysCommonCmdToSwOn = CTLGetSingleCmdToSwOn(usPhase, usAuto);
        usDBmSysGensSwOnCndt    = CTLGetSingleGensSwOnCndt();
        usDBmSysMainSwOnCndt    = CTLGetSingleMainSwOnCndt();
        usPhase                 = CTLGetSingleSysPhase(usPhase);
        usDBmSystemPhase        = usPhase;
        usDBmSyncLoadCtrlMode   = CTLGetSinglePidMode(usPhase);
    }
    else if (usDBpSysOperationMode == CTL_MODE_AMF)
    {   usDBmSysCommonCmdToStop = CTLGetAmfCmdToStop(usAuto);
        usDBmSysCommonCmdToSwOn = CTLGetSingleCmdToSwOn(usPhase, usAuto);
        usDBmSysGensSwOnCndt    = CTLGetAmfGensSwOnCndt();
        usDBmSysMainSwOnCndt    = CTLGetAmfMainSwOnCndt();
        usPhase                 = CTLGetAmfSysPhase(usPhase);
        usDBmSystemPhase        = usPhase;
        usDBmSyncLoadCtrlMode   = CTLGetAmfPidMode(usPhase);
    }
    else if (usDBpSysOperationMode == CTL_MODE_ISLAND)
    {   usDBmSysCommonCmdToStop = CTLGetIslandCmdToStop(usAuto);
        usDBmSysCommonCmdToSwOn = CTLGetSingleCmdToSwOn(usPhase, usAuto);
        usDBmSysGensSwOnCndt    = CTLGetIslandGensSwOnCndt();
        usDBmSysMainSwOnCndt    = CTLGetIslandMainSwOnCndt();
        usPhase                 = CTLGetIslandSysPhase(usPhase);
        usDBmSystemPhase        = usPhase;
        usDBmSyncLoadCtrlMode   = CTLGetIslandPidMode(usPhase);
    }
    else if (usDBpSysOperationMode == CTL_MODE_FIXPOWER)
    {   usDBmSysCommonCmdToStop = CTLGetFixPwrCmdToStop(usAuto);
        usDBmSysCommonCmdToSwOn = CTLGetSingleCmdToSwOn(usPhase, usAuto);
        usDBmSysGensSwOnCndt    = CTLGetFixPwrGensSwOnCndt();
        usDBmSysMainSwOnCndt    = CTLGetFixPwrMainSwOnCndt();
        usPhase                 = CTLGetFixPwrSysPhase(usPhase);
        usDBmSystemPhase        = usPhase;
        usDBmSyncLoadCtrlMode   = CTLGetFixPwrPidMode(usPhase);
    }
    else if (usDBpSysOperationMode == CTL_MODE_PARALLEL)
    {   usDBmCanSchedIsAlone    = CAN2GetCanSchedIsAlone();
        usDBmCanSchedIsHighest  = CAN2GetCanSchedIsHighest();
        usDBmCanSchedToStop     = CAN2GetCanSchedToStop();
        usDBmCanSchedToSwitch   = CAN2GetCanSchedToSwitch();
        usDBmSysCommonCmdToStop = CTLGetParallCmdToStop(usAuto);
        usDBmSysCommonCmdToSwOn = CTLGetParallCmdToSwOn(usPhase, usAuto);
        usDBmSysGensSwOnCndt    = CTLGetParallGensSwOnCndt();
        usDBmSysMainSwOnCndt    = 0;
        usPhase                 = CTLGetParallSysPhase(usPhase);
        usDBmSystemPhase        = usPhase;
        usDBmSyncLoadCtrlMode   = CTLGetParallPidMode(usPhase);
    }
    else
    {   usDBmSysCommonCmdToStop = 1;
        usDBmSysCommonCmdToSwOn = 0;
        usDBmSysGensSwOnCndt    = 0;
        usDBmSysMainSwOnCndt    = 0;
        usPhase                 = 0;
        usDBmSystemPhase        = 0;
        usDBmSyncLoadCtrlMode   = 0;
    }
    usDBmSyncLoadGovCtrl     = CTLGetGovControl(usDBmSyncLoadCtrlMode);
    usDBmSyncLoadAvrCtrl     = CTLGetAvrControl(usDBmSyncLoadCtrlMode);
    usDBmEngHeaterOutput     = SFGetAirHeaterActive(usPhase);
    usDBmEngOilPumpOutput    = SFGetOilPumpActive(usPhase);
    usDBmEngStarterOutput    = SFGetStarterActive(usPhase, usAuto);
    usDBmEngCoolFanOutput    = SFGetCoolantFanActive();
    usDBmEngFuelSupplyOutput = SFGetFuelSupplyActive(usPhase);
    usDBmEngSpeedRatedOutput = SFGetSpeedRatedActive(usPhase);
    usDBmEngStopperOutput    = SFGetStopperActive(usPhase);
    usDBmEngBeeperOutput     = SFGetBeeperActive(usDBmKeyBeeperOff);
    SFUpdateSwitchCtrl(&sCTLMainSwitch, usDBmSwitchMainFeedback);
    usDBmSysMainSwStatus     = sCTLMainSwitch.ucStatus;
    SFUpdateSwitchLock(&sCTLMainSwitch, &sCTLGensSwitch);
    SFUpdateSwitchCtrl(&sCTLGensSwitch, usDBmSwitchGensFeedback);
    usDBmSysGensSwStatus     = sCTLGensSwitch.ucStatus;
    SFUpdateSwitchLock(&sCTLMainSwitch, &sCTLGensSwitch);
    usDBmSysMainSwOnOutput   = sCTLMainSwitch.usSwOnOut;
    usDBmSysMainSwOffOutput  = sCTLMainSwitch.usSwOffOut;
    usDBmSysGensSwOnOutput   = sCTLGensSwitch.usSwOnOut;
    usDBmSysGensSwOffOutput  = sCTLGensSwitch.usSwOffOut;
    usDBmBoardLedOutput      = CTLGetBoardLedOutput();
}
#endif

/* ******************************************************************** */
/*                         CTLGetBoardLedOutput()                       */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetBoardLedOutput (void)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    static INT16U usTimer4 = 0;
    static INT16U usTimer5 = 0;
    static INT16U usOutput = 0;
    INT16U usTimNow, usOutTmp;
    usTimNow = usFW5msTimer;
    usOutTmp = usOutput;
    if (usDBmSysAutoOrManual != 0)
    {   usOutTmp |=  SF_KEY_MSK_MODE_AUTO;
        usOutTmp &= ~SF_KEY_MSK_MODE_MANUAL;
    }   else
    {   usOutTmp &= ~SF_KEY_MSK_MODE_AUTO;
        usOutTmp |=  SF_KEY_MSK_MODE_MANUAL;
    }
    if ((usDBmSysEmergnCmdToStop != 0) ||
        (usDBmSysEmergnErrToStop != 0) ||
        (usDBmSysCommonErrToStop != 0) )
    {   if ((INT16U)(usTimNow-usTimer1) >= CTL_LED_BLINK_TICKS)
        {   usTimer1  =  usTimNow;
            usOutTmp ^=  SF_KEY_MSK_ERROR_RESET;
        }
    }
    else if (usDBmSysCommonErrToWarn != 0)
    {   usTimer1  =  usTimNow;
        usOutTmp |=  SF_KEY_MSK_ERROR_RESET;
    }
    else
    {   usTimer1  =  usTimNow;
        usOutTmp &= ~SF_KEY_MSK_ERROR_RESET;
    }
    if (usDBmEngEngineIsStopped != 0)
    {   usTimer2  =  usTimNow;
        usOutTmp |=  SF_KEY_MSK_ENG_STOP;
    }
    else if ((usDBmSysEmergnCmdToStop != 0) ||
             (usDBmSysEmergnErrToStop != 0) ||
             (usDBmSysCommonCmdToStop != 0) ||
             (usDBmSysCommonErrToStop != 0) )
    {   if ((INT16U)(usTimNow-usTimer2) >= CTL_LED_BLINK_TICKS)
        {   usTimer2  =  usTimNow;
            usOutTmp ^=  SF_KEY_MSK_ENG_STOP;
        }
    }
    else
    {   usTimer2  =  usTimNow;
        usOutTmp &= ~SF_KEY_MSK_ENG_STOP;
    }
    if (usDBmSystemPhase == CTL_PHASE_STARTING)
    {   if ((INT16U)(usTimNow-usTimer3) >= CTL_LED_BLINK_TICKS)
        {   usTimer3  =  usTimNow;
            usOutTmp ^=  SF_KEY_MSK_ENG_START;
        }
    }
    else if (usDBmEngEngineIsRunning != 0)
    {   usTimer3  =  usTimNow;
        usOutTmp |=  SF_KEY_MSK_ENG_START;
    }
    else
    {   usTimer3  =  usTimNow;
        usOutTmp &= ~SF_KEY_MSK_ENG_START;
    }
    if (usDBmEngBeeperOutput != 0)
    {   usOutTmp |=  SF_KEY_MSK_BEEPER;
    }   else
    {   usOutTmp &= ~SF_KEY_MSK_BEEPER;
    }
    if (usDBfMainSwKeyFuncOn == 0)
    {   if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWON_ED)
        {   usTimer4  =  usTimNow;
            usOutTmp |=  SF_KEY_MSK_SWITCH_ON;
            usOutTmp &= ~SF_KEY_MSK_SWITCH_OFF;
        }
        else if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
        {   usTimer4  =  usTimNow;
            usOutTmp &= ~SF_KEY_MSK_SWITCH_ON;
            usOutTmp |=  SF_KEY_MSK_SWITCH_OFF;
        }
        else if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWON_ING)
        {   usOutTmp |=  SF_KEY_MSK_SWITCH_OFF;
            if ((INT16U)(usTimNow-usTimer4) >= CTL_LED_BLINK_TICKS)
            {   usTimer4  = usTimNow;
                usOutTmp ^= SF_KEY_MSK_SWITCH_ON;
            }
        }
        else
        {   usOutTmp |=  SF_KEY_MSK_SWITCH_ON;
            if ((INT16U)(usTimNow-usTimer4) >= CTL_LED_BLINK_TICKS)
            {   usTimer4  = usTimNow;
                usOutTmp ^= SF_KEY_MSK_SWITCH_OFF;
            }
        }
    }
    else
    {   if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWON_ED)
        {   usTimer4  =  usTimNow;
            usOutTmp |=  SF_KEY_MSK_SWITCH_ON;
        }
        else if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
        {   usTimer4  =  usTimNow;
            usOutTmp &= ~SF_KEY_MSK_SWITCH_ON;
        }
        else if ((INT16U)(usTimNow-usTimer4) >= CTL_LED_BLINK_TICKS)
        {   usTimer4  =  usTimNow;
            usOutTmp ^=  SF_KEY_MSK_SWITCH_ON;
        }
        if (sCTLMainSwitch.ucStatus == SF_SW_STS_SWON_ED)
        {   usTimer5  =  usTimNow;
            usOutTmp |=  SF_KEY_MSK_SWITCH_OFF;
        }
        else if (sCTLMainSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
        {   usTimer5  =  usTimNow;
            usOutTmp &= ~SF_KEY_MSK_SWITCH_OFF;
        }
        else if ((INT16U)(usTimNow-usTimer5) >= CTL_LED_BLINK_TICKS)
        {   usTimer5  =  usTimNow;
            usOutTmp ^=  SF_KEY_MSK_SWITCH_OFF;
        }
    }
    usOutput = usOutTmp;
    return usOutTmp;
}
#endif

/* ******************************************************************** */
/*                        SFMainSwitchInit()                            */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
void CTLMainSwitchInit (SF_SW_CTRL_STR *pMain)
{   pMain->ucComd      = SF_SW_CMD_HOLD;
    pMain->ucComdOld   = SF_SW_CMD_HOLD;
    pMain->ucLocker    = SF_SW_NO_LOCK;
    pMain->ucError     = SF_SW_NO_ERR;
    pMain->ucSwFails   = 0;
    pMain->ucSwFailMax = 1;
    pMain->ucErrSum    = 0;
    pMain->usTimer     = usFW100msTimer;
    pMain->usSwFeed    = usDBmSwitchMainFeedback;
    pMain->usSwOnPrd   = usDBpTimeOfMainSwitchOn;
    pMain->usSwOffPrd  = usDBpTimeOfMainSwitchOff;
    if (usDBfMainSwFeedbackOn == 0)
    {   pMain->ucSwFeedEn = 0;
        pMain->ucStatus   = SF_SW_STS_SWON_ED;
    }   else if (pMain->usSwFeed == 0)
    {   pMain->ucSwFeedEn = 1;
        pMain->ucStatus   = SF_SW_STS_SWOFF_ED;
    }   else
    {   pMain->ucSwFeedEn = 1;
        pMain->ucStatus   = SF_SW_STS_SWON_ED;
    }
    if (usDBfMainSwOutPulseOn == 0)
    {   pMain->ucSwPulseEn = 0;
        pMain->usSwOnOut   = pMain->ucStatus == SF_SW_STS_SWON_ED ? 1 : 0;
        pMain->usSwOffOut  = pMain->usSwOnOut == 0 ? 1 : 0;
    }   else
    {   pMain->ucSwPulseEn = 1;
        pMain->usSwOnOut   = 0;
        pMain->usSwOffOut  = 0;
    }
    if (usDBpMainSwitchTryTimes <= 1)
    {   ucCTLMainSwTry = 1;
    }   else if (usDBpMainSwitchTryTimes >= 10)
    {   ucCTLMainSwTry = 10;
    }   else
    {   ucCTLMainSwTry = (INT08U)usDBpMainSwitchTryTimes;
    }
}
#endif

/* ******************************************************************** */
/*                        SFGensSwitchInit()                            */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
void CTLGensSwitchInit (SF_SW_CTRL_STR *pGens)
{   pGens->ucComd      = SF_SW_CMD_HOLD;
    pGens->ucComdOld   = SF_SW_CMD_HOLD;
    pGens->ucLocker    = SF_SW_NO_LOCK;
    pGens->ucError     = SF_SW_NO_ERR;
    pGens->ucSwFails   = 0;
    pGens->ucSwFailMax = 1;
    pGens->ucErrSum    = 0;
    pGens->usTimer     = usFW100msTimer;
    pGens->usSwFeed    = usDBmSwitchGensFeedback;
    pGens->usSwOnPrd   = usDBpTimeOfGensSwitchOn;
    pGens->usSwOffPrd  = usDBpTimeOfGensSwitchOff;
    if (usDBfGensSwFeedbackOn == 0)
    {   pGens->ucSwFeedEn = 0;
        pGens->ucStatus   = SF_SW_STS_SWOFF_ED;
    }   else if (pGens->usSwFeed == 0)
    {   pGens->ucSwFeedEn = 1;
        pGens->ucStatus   = SF_SW_STS_SWOFF_ED;
    }   else
    {   pGens->ucSwFeedEn = 1;
        pGens->ucStatus   = SF_SW_STS_SWON_ED;
    }
    if (usDBfGensSwOutPulseOn == 0)
    {   pGens->ucSwPulseEn = 0;
        pGens->usSwOnOut   = pGens->ucStatus == SF_SW_STS_SWON_ED ? 1 : 0;
        pGens->usSwOffOut  = pGens->usSwOnOut == 0 ? 1 : 0;
    }   else
    {   pGens->ucSwPulseEn = 1;
        pGens->usSwOnOut   = 0;
        pGens->usSwOffOut  = 0;
    }
    if (usDBpGensSwitchTryTimes <= 1)
    {   ucCTLGensSwTry = 1;
    }   else if (usDBpGensSwitchTryTimes >= 10)
    {   ucCTLGensSwTry = 10;
    }   else
    {   ucCTLGensSwTry = (INT08U)usDBpGensSwitchTryTimes;
    }
}
#endif

/* ******************************************************************** */
/*                        CTLGetSingleCmdToSwOn()                       */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetSingleCmdToSwOn (INT16U usPhase, INT16U usAuto)
{   static INT16U usCmdToSwOn = 0;
    if (usAuto != 0)
    {   usCmdToSwOn = 1;
    }
    else if (usDBfMainSwKeyFuncOn == 0)
    {   if ((usPhase == CTL_PHASE_STOPPED) ||
            (usPhase == CTL_PHASE_READY) )
        {   if (usDBmKeySwitchOff != 0)
            {   SFSwitchOffTimes(&sCTLGensSwitch,1);
            }
            else if (usDBmKeySwitchOn != 0)
            {   if (sCTLMainSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
                {   SFSwitchOnTimes(&sCTLGensSwitch,1);
                }
            }
            if (SFGetSwitchOnErr(&sCTLGensSwitch) != 0)
            {   SFClrSwitchOnErr(&sCTLGensSwitch);
                ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_ON);
            }
            else if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
            {   SFClrSwitchOffErr(&sCTLGensSwitch);
                ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
            }
        }
        else if (usPhase == CTL_PHASE_WAIT_KEY_SW)
        {   if (usDBmKeySwitchOn != 0)
            {   usCmdToSwOn = 1;
            }
        }
        else if (usPhase == CTL_PHASE_WORKING)
        {   if (usDBmKeySwitchOff != 0)
            {   usCmdToSwOn = 0;
            }
        }
    }
    else if ((usPhase == CTL_PHASE_STOPPED) ||
             (usPhase == CTL_PHASE_READY) )
    {   if (usDBmKeySwitchOn != 0)
        {   if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWON_ED)
            {   SFSwitchOffTimes(&sCTLGensSwitch,1);
            }
            else if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
            {   if (sCTLMainSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
                {   SFSwitchOnTimes(&sCTLGensSwitch,1);
                }
            }
        }
        else if (usDBmKeySwitchOff != 0)
        {   if (sCTLMainSwitch.ucStatus == SF_SW_STS_SWON_ED)
            {   SFSwitchOffTimes(&sCTLMainSwitch,1);
            }
            else if (sCTLMainSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
            {   if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
                {   SFSwitchOnTimes(&sCTLMainSwitch,1);
                }
            }
        }
        if (SFGetSwitchOnErr(&sCTLGensSwitch) != 0)
        {   SFClrSwitchOnErr(&sCTLGensSwitch);
            ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_ON);
        }
        else if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   SFClrSwitchOffErr(&sCTLGensSwitch);
            ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }
        if (SFGetSwitchOnErr(&sCTLMainSwitch) != 0)
        {   SFClrSwitchOnErr(&sCTLMainSwitch);
            ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_SW_ON);
        }
        else if (SFGetSwitchOffErr(&sCTLMainSwitch) != 0)
        {   SFClrSwitchOffErr(&sCTLMainSwitch);
            ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_SW_OFF);
        }
    }
    else if (usPhase == CTL_PHASE_WAIT_KEY_SW)
    {   if ((usDBmKeySwitchOn != 0) || (usDBmKeySwitchOff != 0))
        {   usCmdToSwOn = 1;
        }
    }
    else if (usPhase == CTL_PHASE_WORKING)
    {   if ((usDBmKeySwitchOn != 0) || (usDBmKeySwitchOff != 0))
        {   usCmdToSwOn = 0;
        }
    }
    return usCmdToSwOn;
}
#endif

/* ******************************************************************** */
/*                        CTLGetParallCmdToSwOn()                       */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetParallCmdToSwOn (INT16U usPhase, INT16U usAuto)
{   static INT16U usCmdToSwOn = 0;
    if (usAuto != 0)
    {   usCmdToSwOn = usDBmCanSchedToSwitch;
    }
    else if ((usPhase == CTL_PHASE_STOPPED) ||
             (usPhase == CTL_PHASE_READY) )
    {   if (CAN2AreEngAllStopped() == CAN2_FALSE)
        {   SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
        else if (usDBmKeySwitchOff != 0)
        {   SFSwitchOffTimes(&sCTLGensSwitch,1);
        }
        else if (usDBmKeySwitchOn != 0)
        {   if (usDBmMainVoltIsLost != 0)
            {   SFSwitchOnTimes(&sCTLGensSwitch,1);
            }
        }
        if (SFGetSwitchOnErr(&sCTLGensSwitch) != 0)
        {   SFClrSwitchOnErr(&sCTLGensSwitch);
            ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_ON);
        }
        else if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   SFClrSwitchOffErr(&sCTLGensSwitch);
            ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }
    }
    else if (usPhase == CTL_PHASE_WAIT_KEY_SW)
    {   if (usDBmKeySwitchOn != 0)
        {   usCmdToSwOn = 1;
        }
    }
    else if (usPhase == CTL_PHASE_WORKING)
    {   if (usDBmKeySwitchOff != 0)
        {   usCmdToSwOn = 0;
        }
    }
    return usCmdToSwOn;
}
#endif

/* ******************************************************************** */
/*                         CTLGetSysAutoOrManual()                      */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetSysAutoOrManual (void)
{   static INT16U usAutoOrHand = 0;
    if (usDBmKeyModeAuto != 0)
    {   usAutoOrHand = 1;
    }
    else if (usDBmKeyModeManual != 0)
    {   usAutoOrHand = 0;
    }
    return usAutoOrHand;
}
#endif

/* ******************************************************************** */
/*                       CTLGetEmergnCmdToStop()                        */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetEmergnCmdToStop (void)
{   static INT16U usComd = 0;
    if (usDBmSwitchEmergStop != 0)
    {   usComd = 1;
    }
    else if (usDBmEngEngineIsStopped != 0)
    {   usComd = 0;
    }
    return usComd;
}
#endif

/* ******************************************************************** */
/*                       CTLGetEmergnErrToStop()                        */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetEmergnErrToStop (void)
{   if (ERR_ES1_GET_BIT(ERR_ES1_EMERG_MSK) != 0)
    {   return 1;
    }
    if (ERR_ES2_GET_BIT(ERR_ES2_EMERG_MSK) != 0)
    {   return 2;
    }
    if (ERR_ES3_GET_BIT(ERR_ES3_EMERG_MSK) != 0)
    {   return 3;
    }
    if (ERR_ES4_GET_BIT(ERR_ES4_EMERG_MSK) != 0)
    {   return 4;
    }
    if (ERR_ES5_GET_BIT(ERR_ES5_EMERG_MSK) != 0)
    {   return 5;
    }
    if (ERR_ES6_GET_BIT(ERR_ES6_EMERG_MSK) != 0)
    {   return 6;
    }
    if (ERR_ES7_GET_BIT(ERR_ES7_EMERG_MSK) != 0)
    {   return 7;
    }
    if (ERR_ES8_GET_BIT(ERR_ES8_EMERG_MSK) != 0)
    {   return 8;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CTLGetCommonErrToStop()                        */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetCommonErrToStop (void)
{   if (ERR_ES1_GET_BIT(ERR_ES1_STOP_MSK) != 0)
    {   return 1;
    }
    if (ERR_ES2_GET_BIT(ERR_ES2_STOP_MSK) != 0)
    {   return 2;
    }
    if (ERR_ES3_GET_BIT(ERR_ES3_STOP_MSK) != 0)
    {   return 3;
    }
    if (ERR_ES4_GET_BIT(ERR_ES4_STOP_MSK) != 0)
    {   return 4;
    }
    if (ERR_ES5_GET_BIT(ERR_ES5_STOP_MSK) != 0)
    {   return 5;
    }
    if (ERR_ES6_GET_BIT(ERR_ES6_STOP_MSK) != 0)
    {   return 6;
    }
    if (ERR_ES7_GET_BIT(ERR_ES7_STOP_MSK) != 0)
    {   return 7;
    }
    if (ERR_ES8_GET_BIT(ERR_ES8_STOP_MSK) != 0)
    {   return 8;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CTLGetCommonErrToWarn()                        */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetCommonErrToWarn (void)
{   if (ERR_ES1_GET_BIT(ERR_ES1_WARN_MSK | ERR_ES1_EMERG_MSK | ERR_ES1_STOP_MSK) != 0)
    {   return 1;
    }
    if (ERR_ES2_GET_BIT(ERR_ES2_WARN_MSK | ERR_ES2_EMERG_MSK | ERR_ES2_STOP_MSK) != 0)
    {   return 2;
    }
    if (ERR_ES3_GET_BIT(ERR_ES3_WARN_MSK | ERR_ES3_EMERG_MSK | ERR_ES3_STOP_MSK) != 0)
    {   return 3;
    }
    if (ERR_ES4_GET_BIT(ERR_ES4_WARN_MSK | ERR_ES4_EMERG_MSK | ERR_ES4_STOP_MSK) != 0)
    {   return 4;
    }
    if (ERR_ES5_GET_BIT(ERR_ES5_WARN_MSK | ERR_ES5_EMERG_MSK | ERR_ES5_STOP_MSK) != 0)
    {   return 5;
    }
    if (ERR_ES6_GET_BIT(ERR_ES6_WARN_MSK | ERR_ES6_EMERG_MSK | ERR_ES6_STOP_MSK) != 0)
    {   return 6;
    }
    if (ERR_ES7_GET_BIT(ERR_ES7_WARN_MSK | ERR_ES7_EMERG_MSK | ERR_ES7_STOP_MSK) != 0)
    {   return 7;
    }
    if (ERR_ES8_GET_BIT(ERR_ES8_WARN_MSK | ERR_ES8_EMERG_MSK | ERR_ES8_STOP_MSK) != 0)
    {   return 8;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CTLCheckGensReadyToLoad()                      */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLCheckGensReadyToLoad (void)
{   if (ERR_ES7_GET_BIT(ERR_ES7_LOAD_MSK) == 0)
    {   return 1;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CTLCheckMainReadyToSync()                      */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLCheckMainReadyToSync (void)
{   if (ERR_ES7_GET_BIT(ERR_ES7_SYNC_MSK) == 0)
    {   return 1;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CTLCheckIsMainVoltNormal()                     */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLCheckIsMainVoltNormal (void)
{   if (ERR_ES1_GET_BIT(ERR_ES1_MAIN_V_ERROR) != 0)
    {   return 0;
    }
    return 1;
}
#endif

/* ******************************************************************** */
/*                       CTLCheckSyncCondition()                        */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLCheckSyncCondition (INT16U usReady)
{   INT16U usTmp, usMax;
    if (usReady == 0)
    {   return 0;
    }
    usTmp = SF_GET_ABS(ssDBmSyncVoltDiffer);
    if (usTmp > usDBpSyncVoltDiffMax)
    {   return 0;
    }
    usTmp = SF_GET_ABS(ssDBmSyncPhaseDiffer);
    if (usTmp > usDBpSyncPhaseDiffMax)
    {   return 0;
    }
    if (ssDBmSyncFreqDiffer >= 0)
    {   usTmp = (INT16U)ssDBmSyncFreqDiffer;
        usMax = usDBpSyncFreqDiffPosMax;
    }   else
    {   usTmp = (INT16U)(-ssDBmSyncFreqDiffer);
        usMax = usDBpSyncFreqDiffNegMax;
    }
    return usTmp > usMax ? 0 : 1;
}
#endif

/* ******************************************************************** */
/*                       CTLCheckIsGensWorking()                        */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLCheckIsGensWorking (INT16U usPhase)
{   if ((usPhase == CTL_PHASE_INIT) ||
        (usPhase == CTL_PHASE_STOPPED) ||
        (usPhase == CTL_PHASE_READY) ||
        (usPhase == CTL_PHASE_STARTING) ||
        (usPhase == CTL_PHASE_STOPPING) ||
        (usPhase == CTL_PHASE_IDLING_UP) ||
        (usPhase == CTL_PHASE_IDLING_DOWN) ||
        (usPhase == CTL_PHASE_RAMP_UP) ||
        (usPhase == CTL_PHASE_RAMP_DOWN) ||
        (usPhase == CTL_PHASE_RATED_UP) ||
        (usPhase == CTL_PHASE_RATED_DOWN) ||
        (usPhase == CTL_PHASE_EMERGENCY) )
    {   return 0;
    }
    else if ((usDBpSysOperationMode == CTL_MODE_AMF) &&
             (usPhase == CTL_PHASE_MAIN_SW_OFF) )
    {   return 0;
    }
    return 1;
}
#endif

/* ******************************************************************** */
/*                       CTLCheckIsMainVoltLost()                       */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLCheckIsMainVoltLost (void)
{   if (ERR_ES1_GET_BIT(ERR_ES1_STS_MAIN_V_LOST) != 0)
    {   return 1;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CTLGetGovControl()                             */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetGovControl (INT16U usPidMod)
{   static INT16U usGovCtrl = 0;
    if (usPidMod == CTL_PID_MODE_INIT)
    {   CTLGovTuner.siCtrlMax  = 2560000;
        CTLGovTuner.siCtrlMin  = 0;
        CTLGovTuner.siCtrlOld  = (INT32U)usDBpSyncGovCtrlInit * 256;
        CTLGovTuner.ssInputOld = 0;
        usGovCtrl = usDBpSyncGovCtrlInit;
    }
    else if (usPidMod == CTL_PID_MODE_SINGLE)
    {   CTLGovTuner.usGain       = usDBpSyncGovGain;
        CTLGovTuner.usStability  = usDBpSyncGovStability;
        CTLGovTuner.usDerivative = usDBpSyncGovDerivative;
        usGovCtrl = SFGetErrorPidCtrl((usDBpGensFreqRated-usDBmGensFreq),
                                      &CTLGovTuner);
    }
    else if (usPidMod == CTL_PID_MODE_SYNC)
    {   CTLGovTuner.usGain       = usDBpSyncGovGain;
        CTLGovTuner.usStability  = usDBpSyncGovStability;
        CTLGovTuner.usDerivative = usDBpSyncGovDerivative;
        if (usDBmMainVoltReadyToSyn != 0)
        {   usGovCtrl = SFGetErrorPidCtrl((usDBmMainFreq+usDBpSyncFreqDiffSetp-usDBmGensFreq),
                                          &CTLGovTuner);
        }   else
        {   usGovCtrl = SFGetErrorPidCtrl((usDBpGensFreqRated-usDBmGensFreq),
                                          &CTLGovTuner);
        }
    }
    else if (usPidMod == CTL_PID_MODE_LOAD)
    {   CTLGovTuner.usGain       = usDBpLoadGovGain;
        CTLGovTuner.usStability  = usDBpLoadGovStability;
        CTLGovTuner.usDerivative = usDBpLoadGovDerivative;
        usGovCtrl = SFGetErrorPidCtrl((usDBmLoadActPwrSetp-usDBmGensActPowerAll),
                                      &CTLGovTuner);
    }
    return usGovCtrl;
}
#endif

/* ******************************************************************** */
/*                       CTLGetAvrControl()                             */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetAvrControl (INT16U usPidMod)
{   static INT16U usAvrCtrl = 0;
    if (usPidMod == CTL_PID_MODE_INIT)
    {   CTLAvrTuner.siCtrlMax  = 2560000;
        CTLAvrTuner.siCtrlMin  = 0;
        CTLAvrTuner.siCtrlOld  = (INT32U)usDBpSyncAvrCtrlInit * 256;
        CTLAvrTuner.ssInputOld = 0;
        usAvrCtrl = usDBpSyncAvrCtrlInit;
    }
    else if (usPidMod == CTL_PID_MODE_SINGLE)
    {   CTLAvrTuner.usGain       = usDBpSyncAvrGain;
        CTLAvrTuner.usStability  = usDBpSyncAvrStability;
        CTLAvrTuner.usDerivative = usDBpSyncAvrDerivative;
        usAvrCtrl = SFGetErrorPidCtrl((usDBpGensVoltRated-usDBmGensVoltA),
                                      &CTLAvrTuner);
    }
    else if (usPidMod == CTL_PID_MODE_SYNC)
    {   CTLAvrTuner.usGain       = usDBpSyncAvrGain;
        CTLAvrTuner.usStability  = usDBpSyncAvrStability;
        CTLAvrTuner.usDerivative = usDBpSyncAvrDerivative;
        if (usDBmMainVoltReadyToSyn != 0)
        {   usAvrCtrl = SFGetErrorPidCtrl((usDBmMainVoltA-usDBmGensVoltA),
                                          &CTLAvrTuner);
        }   else
        {   usAvrCtrl = SFGetErrorPidCtrl((usDBpGensVoltRated-usDBmGensVoltA),
                                          &CTLAvrTuner);
        }
    }
    else if (usPidMod == CTL_PID_MODE_LOAD)
    {   CTLAvrTuner.usGain       = usDBpLoadAvrGain;
        CTLAvrTuner.usStability  = usDBpLoadAvrStability;
        CTLAvrTuner.usDerivative = usDBpLoadAvrDerivative;
        usAvrCtrl = SFGetErrorPidCtrl((usDBmLoadRctPwrSetp-usDBmGensReactPowerAll),
                                      &CTLAvrTuner);
    }
    return usAvrCtrl;
}
#endif

/* ******************************************************************** */
/*                        CTLGetLoadRampStepAct()                       */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetLoadRampStepAct (INT32U uiRamp)
{   static INT32U uiLoadActResi = 0;
    INT32U uiTemp;
    uiTemp = uiRamp + uiLoadActResi;
    uiLoadActResi = uiTemp % (CTL_LOAD_RAMP_FREQ * 4096uL / 10uL);
    return (INT16U)(uiTemp / (CTL_LOAD_RAMP_FREQ * 4096uL / 10uL));
}
#endif

/* ******************************************************************** */
/*                        CTLGetLoadSetpRampAct()                       */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetLoadSetpRampAct (INT16U usSelect, INT16U usOld, INT16U usAll)
{   INT32U uiRamp;
    INT16U usTemp;
    if (usSelect > (usOld + CTL_LOAD_RAMP_STEP_MIN))
    {   uiRamp = (INT32U)usAll * 4096uL;
        usTemp = usDBpTimeOfLoadingOn;
        if (usTemp > 1)
        {   uiRamp = uiRamp / usTemp;
        }
        usTemp = CTLGetLoadRampStepAct(uiRamp);
        if (usSelect > (usOld + usTemp))
        {   return usOld + usTemp;
        }
    }
    else if ((usSelect + CTL_LOAD_RAMP_STEP_MIN) < usOld)
    {   uiRamp = (INT32U)usAll * 4096uL;
        usTemp = usDBpTimeOfLoadingOff;
        if (usTemp > 1)
        {   uiRamp = uiRamp / usTemp;
        }
        usTemp = CTLGetLoadRampStepAct(uiRamp);
        if ((usSelect + usTemp) < usOld)
        {   return usOld - usTemp;
        }
    }
    return usSelect;
}
#endif

/* ******************************************************************** */
/*                       CTLGetLoadRampStepRct()                        */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetLoadRampStepRct (INT32U uiRamp)
{   static INT32U uiLoadRctResi = 0;
    INT32U uiTemp;
    uiTemp = uiRamp + uiLoadRctResi;
    uiLoadRctResi = uiTemp % (CTL_LOAD_RAMP_FREQ * 4096uL / 10uL);
    return (INT16U)(uiTemp / (CTL_LOAD_RAMP_FREQ * 4096uL / 10uL));
}
#endif

/* ******************************************************************** */
/*                        CTLGetLoadSetpRampRct()                       */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetLoadSetpRampRct (INT16U usSelect, INT16U usOld, INT16U usAll)
{   INT32U uiRamp;
    INT16U usTemp;
    if (usSelect > (usOld + CTL_LOAD_RAMP_STEP_MIN))
    {   uiRamp = (INT32U)usAll * 4096uL;
        usTemp = usDBpTimeOfLoadingOn;
        if (usTemp > 1)
        {   uiRamp = uiRamp / usTemp;
        }
        usTemp = CTLGetLoadRampStepRct(uiRamp);
        if (usSelect > (usOld + usTemp))
        {   return usOld + usTemp;
        }
    }
    else if ((usSelect + CTL_LOAD_RAMP_STEP_MIN) < usOld)
    {   uiRamp = (INT32U)usAll * 4096uL;
        usTemp = usDBpTimeOfLoadingOff;
        if (usTemp > 1)
        {   uiRamp = uiRamp / usTemp;
        }
        usTemp = CTLGetLoadRampStepRct(uiRamp);
        if ((usSelect + usTemp) < usOld)
        {   return usOld - usTemp;
        }
    }
    return usSelect;
}
#endif

/* ******************************************************************** */
/*                       CTLGetFixPwrSetp()                             */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetFixPwrSetp (INT16U usPMain, INT16U usPGens, INT16U usPMax)
{   INT32U uiTmp;
    if (usDBfFixPwrMainLoadCtrlOn == 0)
    {   return usPMax;
    }
    uiTmp  = (INT32U)usPMain + (INT32U)usPGens;
    uiTmp *= (INT32U)usDBpFixPwrGensPrsntMax;
    uiTmp /= (INT32U)1000;
    return uiTmp < (INT32U)usPMax ? (INT16U)uiTmp : usPMax;
}
#endif

/* ******************************************************************** */
/*                       CTLGetSimpleCmdToStop()                        */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetSimpleCmdToStop (INT16U usAutoOrHand)
{   static INT16U usCmdToStop = 1;
    if ((usDBmSysEmergnCmdToStop != 0) ||
        (usDBmSysEmergnErrToStop != 0) ||
        (usDBmSysCommonErrToStop != 0) )
    {   usCmdToStop = 1;
    }
    else if (usAutoOrHand == 0)
    {   if (usDBmKeyEngineStop != 0)
        {   usCmdToStop = 1;
        }
        else if ((usDBmKeyEngineStart != 0) &&
                 (usDBmSystemPhase == CTL_PHASE_READY))
        {   usCmdToStop = 0;
        }
    }
    else if (usDBmSwitchEngineStop != 0)
    {   usCmdToStop = 1;
    }
    else if (usDBmSwitchEngineStart != 0)
    {   usCmdToStop = 0;
    }
    return usCmdToStop;
}
#endif

/* ******************************************************************** */
/*                       CTLGetSingleCmdToStop()                        */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetSingleCmdToStop (INT16U usAutoOrHand)
{   static INT16U usCmdToStop = 1;
    if ((usDBmSysEmergnCmdToStop != 0) ||
        (usDBmSysEmergnErrToStop != 0) ||
        (usDBmSysCommonErrToStop != 0) )
    {   usCmdToStop = 1;
    }
    else if (usAutoOrHand == 0)
    {   if (usDBmKeyEngineStop != 0)
        {   usCmdToStop = 1;
        }
        else if ((usDBmKeyEngineStart != 0) &&
                 (usDBmSystemPhase == CTL_PHASE_READY))
        {   usCmdToStop = 0;
        }
    }
    else if (usDBmSwitchEngineStop != 0)
    {   usCmdToStop = 1;
    }
    else if (usDBmSwitchEngineStart != 0)
    {   usCmdToStop = 0;
    }
    return usCmdToStop;
}
#endif

/* ******************************************************************** */
/*                         CTLGetAmfCmdToStop()                         */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetAmfCmdToStop (INT16U usAutoOrHand)
{   static INT16U usCmdToStop = 1;
    if ((usDBmSysEmergnCmdToStop != 0) ||
        (usDBmSysEmergnErrToStop != 0) ||
        (usDBmSysCommonErrToStop != 0) )
    {   usCmdToStop = 1;
    }
    else if (usAutoOrHand == 0)
    {   if (usDBmKeyEngineStop != 0)
        {   usCmdToStop = 1;
        }
        else if ((usDBmKeyEngineStart != 0) &&
                 (usDBmSystemPhase == CTL_PHASE_READY))
        {   usCmdToStop = 0;
        }
    }
    else if ((usDBmSwitchEngineStop != 0) ||
             (usDBmMainVoltIsNormal != 0) )
    {   usCmdToStop = 1;
    }
    else if (usDBmSwitchEngineStart != 0)
    {   usCmdToStop = 0;
    }
    return usCmdToStop;
}
#endif

/* ******************************************************************** */
/*                       CTLGetIslandCmdToStop()                        */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetIslandCmdToStop (INT16U usAutoOrHand)
{   static INT16U usCmdToStop = 1;
    if ((usDBmSysEmergnCmdToStop != 0) ||
        (usDBmSysEmergnErrToStop != 0) ||
        (usDBmSysCommonErrToStop != 0) )
    {   usCmdToStop = 1;
    }
    else if (usAutoOrHand == 0)
    {   if (usDBmKeyEngineStop != 0)
        {   usCmdToStop = 1;
        }
        else if ((usDBmKeyEngineStart != 0) &&
                 (usDBmSystemPhase == CTL_PHASE_READY))
        {   usCmdToStop = 0;
        }
    }
    else if (usDBmSwitchEngineStop != 0)
    {   usCmdToStop = 1;
    }
    else if (usDBmSwitchEngineStart != 0)
    {   usCmdToStop = 0;
    }
    return usCmdToStop;
}
#endif

/* ******************************************************************** */
/*                       CTLGetFixPwrCmdToStop()                        */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetFixPwrCmdToStop (INT16U usAutoOrHand)
{   static INT16U usCmdToStop = 1;
    if ((usDBmSysEmergnCmdToStop != 0) ||
        (usDBmSysEmergnErrToStop != 0) ||
        (usDBmSysCommonErrToStop != 0) )
    {   usCmdToStop = 1;
    }
    else if (usAutoOrHand == 0)
    {   if (usDBmKeyEngineStop != 0)
        {   usCmdToStop = 1;
        }
        else if ((usDBmKeyEngineStart != 0) &&
                 (usDBmSystemPhase == CTL_PHASE_READY))
        {   usCmdToStop = 0;
        }
    }
    else if (usDBmSwitchEngineStop != 0)
    {   usCmdToStop = 1;
    }
    else if (usDBmSwitchEngineStart != 0)
    {   usCmdToStop = 0;
    }
    return usCmdToStop;
}
#endif

/* ******************************************************************** */
/*                       CTLGetParallCmdToStop()                        */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetParallCmdToStop (INT16U usAutoOrHand)
{   static INT16U usKeyToStop = 1;
    static INT16U usSwtToStop = 1;
    if ((usDBmSysEmergnCmdToStop != 0) ||
        (usDBmSysEmergnErrToStop != 0) ||
        (usDBmSysCommonErrToStop != 0) )
    {   ERR_ES7_SET_BIT(ERR_ES7_CMD_TO_STOP);
        usKeyToStop = 1;
        usSwtToStop = 1;
    }
    else if (usAutoOrHand == 0)
    {   if (usDBmKeyEngineStop != 0)
        {   ERR_ES7_SET_BIT(ERR_ES7_CMD_TO_STOP);
            usKeyToStop = 1;
            usSwtToStop = 1;
        }
        else if ((usDBmKeyEngineStart != 0) &&
                 (usDBmSystemPhase == CTL_PHASE_READY))
        {   ERR_ES7_CLR_BIT(ERR_ES7_CMD_TO_STOP);
            usKeyToStop = 0;
            usSwtToStop = 0;
        }
        return usKeyToStop;
    }
    else if (usDBmSwitchEngineStop != 0)
    {   ERR_ES7_SET_BIT(ERR_ES7_CMD_TO_STOP);
        usSwtToStop  = 1;
    }
    else if (usDBmSwitchEngineStart != 0)
    {   ERR_ES7_CLR_BIT(ERR_ES7_CMD_TO_STOP);
        usSwtToStop  = 0;
    }
    if (usSwtToStop != 0)
    {   usKeyToStop  = 1;
    }   else
    {   usKeyToStop  = usDBmCanSchedToStop;
    }
    return usKeyToStop;
}
#endif

/* ******************************************************************** */
/*                       CTLGetSimpleGensSwOnCndt()                     */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetSimpleGensSwOnCndt (void)
{   return usDBmGensIsReadyToLoad;
}
#endif

/* ******************************************************************** */
/*                       CTLGetSingleGensSwOnCndt()                     */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetSingleGensSwOnCndt (void)
{   return usDBmGensIsReadyToLoad;
}
#endif

/* ******************************************************************** */
/*                        CTLGetAmfGensSwOnCndt()                       */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetAmfGensSwOnCndt (void)
{   return usDBmGensIsReadyToLoad;
}
#endif

/* ******************************************************************** */
/*                       CTLGetIslandGensSwOnCndt()                     */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetIslandGensSwOnCndt (void)
{   if ((usDBmGensIsReadyToLoad  != 0) &&
        (usDBmSyncConditionMatch != 0) )
    {   return 1;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CTLGetFixPwrGensSwOnCndt()                     */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetFixPwrGensSwOnCndt (void)
{   if ((usDBmGensIsReadyToLoad  != 0) &&
        (usDBmSyncConditionMatch != 0) )
    {   return 1;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CTLGetParallGensSwOnCndt()                     */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetParallGensSwOnCndt (void)
{   if ((usDBmGensIsReadyToLoad != 0) &&
        (SFGetSwitchOnLock(&sCTLGensSwitch) == 0) &&
        (sCTLGensSwitch.ucStatus == SF_SW_STS_SWOFF_ED) )
    {   if (usDBmSyncConditionMatch != 0)
        {   return 1;
        }
        if((usDBmMainVoltIsLost != 0) && (CAN2AreSwAllOffed() != 0))
        {   return 1;
        }
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CTLGetSimpleMainSwOnCndt()                     */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetSimpleMainSwOnCndt (void)
{   return 1;
}
#endif

/* ******************************************************************** */
/*                       CTLGetSingleMainSwOnCndt()                     */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetSingleMainSwOnCndt (void)
{   return 1;
}
#endif

/* ******************************************************************** */
/*                        CTLGetAmfGensSwOnCndt()                       */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetAmfMainSwOnCndt (void)
{   if ((usDBmMainVoltReadyToSyn != 0) &&
        (usDBmSyncConditionMatch != 0) )
    {   return 1;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CTLGetIslandMainSwOnCndt()                     */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetIslandMainSwOnCndt (void)
{   if ((usDBmMainVoltReadyToSyn != 0) &&
        (usDBmSyncConditionMatch != 0) )
    {   return 1;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CTLGetFixPwrMainSwOnCndt()                     */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetFixPwrMainSwOnCndt (void)
{   if ((usDBmMainVoltReadyToSyn != 0) &&
        (usDBmSyncConditionMatch != 0) )
    {   return 1;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CTLGetParallMainSwOnCndt()                     */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetParallMainSwOnCndt (void)
{   return 0;
}
#endif

/* ******************************************************************** */
/*                       CTLGetSimplePidMode()                          */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetSimplePidMode (INT16U usPhase)
{   usDBmLoadActPwrSelect = usDBmGensActPowerAll;
    usDBmLoadActPwrSetp   = usDBmGensActPowerAll;
    usDBmLoadRctPwrSelect = usDBmGensReactPowerAll;
    usDBmLoadRctPwrSetp   = usDBmGensReactPowerAll;
    if ((usPhase == CTL_PHASE_INIT) ||
        (usPhase == CTL_PHASE_STOPPED) ||
        (usPhase == CTL_PHASE_READY) ||
        (usPhase == CTL_PHASE_STARTING) ||
        (usPhase == CTL_PHASE_STOPPING) ||
        (usPhase == CTL_PHASE_IDLING_UP) ||
        (usPhase == CTL_PHASE_IDLING_DOWN) ||
        (usPhase == CTL_PHASE_RAMP_UP) ||
        (usPhase == CTL_PHASE_RAMP_DOWN) )
    {   return CTL_PID_MODE_INIT;
    }
    else if ((usPhase == CTL_PHASE_RATED_UP) ||
             (usPhase == CTL_PHASE_RATED_DOWN) ||
             (usPhase == CTL_PHASE_WORKING) )
    {   return CTL_PID_MODE_SINGLE;
    }
    return CTL_PID_MODE_HOLD;
}
#endif

/* ******************************************************************** */
/*                       CTLGetSinglePidMode()                          */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetSinglePidMode (INT16U usPhase)
{   usDBmLoadActPwrSelect = usDBmGensActPowerAll;
    usDBmLoadActPwrSetp   = usDBmGensActPowerAll;
    usDBmLoadRctPwrSelect = usDBmGensReactPowerAll;
    usDBmLoadRctPwrSetp   = usDBmGensReactPowerAll;
    if ((usPhase == CTL_PHASE_INIT) ||
        (usPhase == CTL_PHASE_STOPPED) ||
        (usPhase == CTL_PHASE_READY) ||
        (usPhase == CTL_PHASE_MAIN_SW_OFF) ||
        (usPhase == CTL_PHASE_STARTING) ||
        (usPhase == CTL_PHASE_STOPPING) ||
        (usPhase == CTL_PHASE_IDLING_UP) ||
        (usPhase == CTL_PHASE_IDLING_DOWN) ||
        (usPhase == CTL_PHASE_RAMP_UP) ||
        (usPhase == CTL_PHASE_RAMP_DOWN) )
    {   return CTL_PID_MODE_INIT;
    }
    else if ((usPhase == CTL_PHASE_RATED_UP) ||
             (usPhase == CTL_PHASE_RATED_DOWN) ||
             (usPhase == CTL_PHASE_WAIT_KEY_SW) ||
             (usPhase == CTL_PHASE_WORKING) )
    {   return CTL_PID_MODE_SINGLE;
    }
    return CTL_PID_MODE_HOLD;
}
#endif

/* ******************************************************************** */
/*                        CTLGetAmfPidMode()                            */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetAmfPidMode (INT16U usPhase)
{   if ((usPhase == CTL_PHASE_INIT) ||
        (usPhase == CTL_PHASE_STOPPED) ||
        (usPhase == CTL_PHASE_READY) ||
        (usPhase == CTL_PHASE_MAIN_SW_OFF) ||
        (usPhase == CTL_PHASE_STARTING) ||
        (usPhase == CTL_PHASE_STOPPING) ||
        (usPhase == CTL_PHASE_IDLING_UP) ||
        (usPhase == CTL_PHASE_IDLING_DOWN) ||
        (usPhase == CTL_PHASE_RAMP_UP) ||
        (usPhase == CTL_PHASE_RAMP_DOWN) )
    {   usDBmLoadActPwrSelect = usDBmGensActPowerAll;
        usDBmLoadActPwrSetp   = usDBmGensActPowerAll;
        usDBmLoadRctPwrSelect = usDBmGensReactPowerAll;
        usDBmLoadRctPwrSetp   = usDBmGensReactPowerAll;
        return CTL_PID_MODE_INIT;
    }
    else if ((usPhase == CTL_PHASE_RATED_UP) ||
             (usPhase == CTL_PHASE_RATED_DOWN) ||
             (usPhase == CTL_PHASE_WAIT_KEY_SW) ||
             (usPhase == CTL_PHASE_WORKING) )
    {   usDBmLoadActPwrSelect = usDBmGensActPowerAll;
        usDBmLoadActPwrSetp   = usDBmGensActPowerAll;
        usDBmLoadRctPwrSelect = usDBmGensReactPowerAll;
        usDBmLoadRctPwrSetp   = usDBmGensReactPowerAll;
        return CTL_PID_MODE_SINGLE;
    }
    else if (usPhase == CTL_PHASE_SYNCHRING)
    {   usDBmLoadActPwrSelect = usDBmGensActPowerAll;
        usDBmLoadActPwrSetp   = usDBmGensActPowerAll;
        usDBmLoadRctPwrSelect = usDBmGensReactPowerAll;
        usDBmLoadRctPwrSetp   = usDBmGensReactPowerAll;
        return CTL_PID_MODE_SYNC;
    }
    else if (usPhase == CTL_PHASE_LOADING_DOWN)
    {   usDBmLoadActPwrSetp = CTLGetLoadSetpRampAct(CTL_LOAD_OFF_ACT_SETP,
                                                    usDBmLoadActPwrSetp,
                                                    usDBmLoadActPwrSelect);
        usDBmLoadRctPwrSetp = CTLGetLoadSetpRampRct(CTL_LOAD_OFF_RCT_SETP,
                                                    usDBmLoadRctPwrSetp,
                                                    usDBmLoadRctPwrSelect);
        return CTL_PID_MODE_LOAD;
    }
    return CTL_PID_MODE_HOLD;
}
#endif

/* ******************************************************************** */
/*                       CTLGetIslandPidMode()                          */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetIslandPidMode (INT16U usPhase)
{   if ((usPhase == CTL_PHASE_INIT) ||
        (usPhase == CTL_PHASE_STOPPED) ||
        (usPhase == CTL_PHASE_READY) ||
        (usPhase == CTL_PHASE_MAIN_SW_OFF) ||
        (usPhase == CTL_PHASE_STARTING) ||
        (usPhase == CTL_PHASE_STOPPING) ||
        (usPhase == CTL_PHASE_IDLING_UP) ||
        (usPhase == CTL_PHASE_IDLING_DOWN) ||
        (usPhase == CTL_PHASE_RAMP_UP) ||
        (usPhase == CTL_PHASE_RAMP_DOWN) )
    {   usDBmLoadActPwrSelect = usDBmGensActPowerAll;
        usDBmLoadActPwrSetp   = usDBmGensActPowerAll;
        usDBmLoadRctPwrSelect = usDBmGensReactPowerAll;
        usDBmLoadRctPwrSetp   = usDBmGensReactPowerAll;
        return CTL_PID_MODE_INIT;
    }
    else if ((usPhase == CTL_PHASE_RATED_UP) ||
             (usPhase == CTL_PHASE_RATED_DOWN) ||
             (usPhase == CTL_PHASE_WAIT_KEY_SW) ||
             (usPhase == CTL_PHASE_WORKING) )
    {   usDBmLoadActPwrSelect = usDBmGensActPowerAll;
        usDBmLoadActPwrSetp   = usDBmGensActPowerAll;
        usDBmLoadRctPwrSelect = usDBmGensReactPowerAll;
        usDBmLoadRctPwrSetp   = usDBmGensReactPowerAll;
        return CTL_PID_MODE_SINGLE;
    }
    else if ((usPhase == CTL_PHASE_SYNCHRING) ||
             (usPhase == CTL_PHASE_SYNCHRING2) )
    {   usDBmLoadActPwrSelect = usDBmGensActPowerAll;
        usDBmLoadActPwrSetp   = usDBmGensActPowerAll;
        usDBmLoadRctPwrSelect = usDBmGensReactPowerAll;
        usDBmLoadRctPwrSetp   = usDBmGensReactPowerAll;
        return CTL_PID_MODE_SYNC;
    }
    else if (usPhase == CTL_PHASE_LOADING_UP)
    {   usDBmLoadActPwrSelect = CTLGetFixPwrSetp(usDBmMainActPowerAll,
                                                 usDBmGensActPowerAll,
                                                 usDBpLoadActPowerSetp);
        usDBmLoadActPwrSetp = CTLGetLoadSetpRampAct(usDBmLoadActPwrSelect,
                                                    usDBmLoadActPwrSetp,
                                                    usDBmLoadActPwrSelect);
        if (usDBpLoadReactCtrlMode == 0)
        {   usDBmLoadRctPwrSelect = CTLGetFixPwrSetp(usDBmMainReactPowerAll,
                                                     usDBmGensReactPowerAll,
                                                     usDBpLoadReactPowerSetp);
            usDBmLoadRctPwrSetp = CTLGetLoadSetpRampRct(usDBmLoadRctPwrSelect,
                                                        usDBmLoadRctPwrSetp,
                                                        usDBmLoadRctPwrSelect);
        }   else
        {   usDBmLoadRctPwrSelect = SFGetReactPwrOfAct(usDBmLoadActPwrSelect,
                                                       usDBpLoadPowerFactorSetp);
            usDBmLoadRctPwrSetp = SFGetReactPwrOfAct(usDBmLoadActPwrSetp,
                                                     usDBpLoadPowerFactorSetp);
        }
        return CTL_PID_MODE_LOAD;
    }
    else if (usPhase == CTL_PHASE_LOADING_DOWN)
    {   usDBmLoadActPwrSetp = CTLGetLoadSetpRampAct(CTL_LOAD_OFF_ACT_SETP,
                                                    usDBmLoadActPwrSetp,
                                                    usDBmLoadActPwrSelect);
        usDBmLoadRctPwrSetp = CTLGetLoadSetpRampRct(CTL_LOAD_OFF_RCT_SETP,
                                                    usDBmLoadRctPwrSetp,
                                                    usDBmLoadRctPwrSelect);
        return CTL_PID_MODE_LOAD;
    }
    else if ((usPhase == CTL_PHASE_FIXPWR_UP) ||
             (usPhase == CTL_PHASE_FIXPWR_DOWN) )
    {   usDBmLoadActPwrSelect = CTLGetFixPwrSetp(usDBmMainActPowerAll,
                                                 usDBmGensActPowerAll,
                                                 usDBpLoadActPowerSetp);
        usDBmLoadActPwrSetp = usDBmLoadActPwrSelect;
        if (usDBpLoadReactCtrlMode == 0)
        {   usDBmLoadRctPwrSelect = CTLGetFixPwrSetp(usDBmMainReactPowerAll,
                                                     usDBmGensReactPowerAll,
                                                     usDBpLoadReactPowerSetp);
        }   else
        {   usDBmLoadRctPwrSelect = SFGetReactPwrOfAct(usDBmLoadActPwrSelect,
                                                       usDBpLoadPowerFactorSetp);
        }
        usDBmLoadRctPwrSetp = usDBmLoadRctPwrSelect;
        return CTL_PID_MODE_LOAD;
    }
    return CTL_PID_MODE_HOLD;
}
#endif

/* ******************************************************************** */
/*                       CTLGetFixPwrPidMode()                          */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetFixPwrPidMode (INT16U usPhase)
{   if ((usPhase == CTL_PHASE_INIT) ||
        (usPhase == CTL_PHASE_STOPPED) ||
        (usPhase == CTL_PHASE_READY) ||
        (usPhase == CTL_PHASE_MAIN_SW_OFF) ||
        (usPhase == CTL_PHASE_STARTING) ||
        (usPhase == CTL_PHASE_STOPPING) ||
        (usPhase == CTL_PHASE_IDLING_UP) ||
        (usPhase == CTL_PHASE_IDLING_DOWN) ||
        (usPhase == CTL_PHASE_RAMP_UP) ||
        (usPhase == CTL_PHASE_RAMP_DOWN) )
    {   usDBmLoadActPwrSelect = usDBmGensActPowerAll;
        usDBmLoadActPwrSetp   = usDBmGensActPowerAll;
        usDBmLoadRctPwrSelect = usDBmGensReactPowerAll;
        usDBmLoadRctPwrSetp   = usDBmGensReactPowerAll;
        return CTL_PID_MODE_INIT;
    }
    else if ((usPhase == CTL_PHASE_RATED_UP) ||
             (usPhase == CTL_PHASE_RATED_DOWN) ||
             (usPhase == CTL_PHASE_WAIT_KEY_SW) )
    {   usDBmLoadActPwrSelect = usDBmGensActPowerAll;
        usDBmLoadActPwrSetp   = usDBmGensActPowerAll;
        usDBmLoadRctPwrSelect = usDBmGensReactPowerAll;
        usDBmLoadRctPwrSetp   = usDBmGensReactPowerAll;
        return CTL_PID_MODE_SINGLE;
    }
    else if (usPhase == CTL_PHASE_SYNCHRING)
    {   usDBmLoadActPwrSelect = usDBmGensActPowerAll;
        usDBmLoadActPwrSetp   = usDBmGensActPowerAll;
        usDBmLoadRctPwrSelect = usDBmGensReactPowerAll;
        usDBmLoadRctPwrSetp   = usDBmGensReactPowerAll;
        return CTL_PID_MODE_SYNC;
    }
    else if (usPhase == CTL_PHASE_LOADING_UP)
    {   usDBmLoadActPwrSelect = CTLGetFixPwrSetp(usDBmMainActPowerAll,
                                                 usDBmGensActPowerAll,
                                                 usDBpLoadActPowerSetp);
        usDBmLoadActPwrSetp = CTLGetLoadSetpRampAct(usDBmLoadActPwrSelect,
                                                    usDBmLoadActPwrSetp,
                                                    usDBmLoadActPwrSelect);
        if (usDBpLoadReactCtrlMode == 0)
        {   usDBmLoadRctPwrSelect = CTLGetFixPwrSetp(usDBmMainReactPowerAll,
                                                     usDBmGensReactPowerAll,
                                                     usDBpLoadReactPowerSetp);
            usDBmLoadRctPwrSetp = CTLGetLoadSetpRampRct(usDBmLoadRctPwrSelect,
                                                        usDBmLoadRctPwrSetp,
                                                        usDBmLoadRctPwrSelect);
        }   else
        {   usDBmLoadRctPwrSelect = SFGetReactPwrOfAct(usDBmLoadActPwrSelect,
                                                       usDBpLoadPowerFactorSetp);
            usDBmLoadRctPwrSetp = SFGetReactPwrOfAct(usDBmLoadActPwrSetp,
                                                     usDBpLoadPowerFactorSetp);
        }
        return CTL_PID_MODE_LOAD;
    }
    else if (usPhase == CTL_PHASE_LOADING_DOWN)
    {   usDBmLoadActPwrSetp = CTLGetLoadSetpRampAct(CTL_LOAD_OFF_ACT_SETP,
                                                    usDBmLoadActPwrSetp,
                                                    usDBmLoadActPwrSelect);
        usDBmLoadRctPwrSetp = CTLGetLoadSetpRampRct(CTL_LOAD_OFF_RCT_SETP,
                                                    usDBmLoadRctPwrSetp,
                                                    usDBmLoadRctPwrSelect);
        return CTL_PID_MODE_LOAD;
    }
    else if (usPhase == CTL_PHASE_WORKING)
    {   usDBmLoadActPwrSelect = CTLGetFixPwrSetp(usDBmMainActPowerAll,
                                                 usDBmGensActPowerAll,
                                                 usDBpLoadActPowerSetp);
        usDBmLoadActPwrSetp = usDBmLoadActPwrSelect;
        if (usDBpLoadReactCtrlMode == 0)
        {   usDBmLoadRctPwrSelect = CTLGetFixPwrSetp(usDBmMainReactPowerAll,
                                                     usDBmGensReactPowerAll,
                                                     usDBpLoadReactPowerSetp);
        }   else
        {   usDBmLoadRctPwrSelect = SFGetReactPwrOfAct(usDBmLoadActPwrSelect,
                                                       usDBpLoadPowerFactorSetp);
        }
        usDBmLoadRctPwrSetp = usDBmLoadRctPwrSelect;
        return CTL_PID_MODE_LOAD;
    }
    return CTL_PID_MODE_HOLD;
}
#endif

/* ******************************************************************** */
/*                       CTLGetParallPidMode()                          */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetParallPidMode (INT16U usPhase)
{   if ((usPhase == CTL_PHASE_INIT) ||
        (usPhase == CTL_PHASE_STOPPED) ||
        (usPhase == CTL_PHASE_READY) ||
        (usPhase == CTL_PHASE_MAIN_SW_OFF) ||
        (usPhase == CTL_PHASE_STARTING) ||
        (usPhase == CTL_PHASE_STOPPING) ||
        (usPhase == CTL_PHASE_IDLING_UP) ||
        (usPhase == CTL_PHASE_IDLING_DOWN) ||
        (usPhase == CTL_PHASE_RAMP_UP) ||
        (usPhase == CTL_PHASE_RAMP_DOWN) )
    {   usDBmLoadActPwrSelect = usDBmGensActPowerAll;
        usDBmLoadActPwrSetp   = usDBmGensActPowerAll;
        usDBmLoadRctPwrSelect = usDBmGensReactPowerAll;
        usDBmLoadRctPwrSetp   = usDBmGensReactPowerAll;
        return CTL_PID_MODE_INIT;
    }
    else if ((usPhase == CTL_PHASE_RATED_UP) ||
             (usPhase == CTL_PHASE_RATED_DOWN) ||
             (usPhase == CTL_PHASE_WAIT_KEY_SW) )
    {   usDBmLoadActPwrSelect = usDBmGensActPowerAll;
        usDBmLoadActPwrSetp   = usDBmGensActPowerAll;
        usDBmLoadRctPwrSelect = usDBmGensReactPowerAll;
        usDBmLoadRctPwrSetp   = usDBmGensReactPowerAll;
        return CTL_PID_MODE_SINGLE;
    }
    else if (usPhase == CTL_PHASE_SYNCHRING)
    {   usDBmLoadActPwrSelect = usDBmGensActPowerAll;
        usDBmLoadActPwrSetp   = usDBmGensActPowerAll;
        usDBmLoadRctPwrSelect = usDBmGensReactPowerAll;
        usDBmLoadRctPwrSetp   = usDBmGensReactPowerAll;
        return CTL_PID_MODE_SYNC;
    }
    else if (usPhase == CTL_PHASE_LOADING_UP)
    {   usDBmLoadActPwrSelect = usDBmCanSchedActPowerSetp;
        usDBmLoadActPwrSetp   = CTLGetLoadSetpRampAct(usDBmLoadActPwrSelect,
                                usDBmLoadActPwrSetp,  usDBmLoadActPwrSelect);
        usDBmLoadRctPwrSelect = usDBmCanSchedRctPowerSetp;
        usDBmLoadRctPwrSetp   = CTLGetLoadSetpRampRct(usDBmLoadRctPwrSelect,
                                usDBmLoadRctPwrSetp,  usDBmLoadRctPwrSelect);
        return CTL_PID_MODE_LOAD;
    }
    else if (usPhase == CTL_PHASE_LOADING_DOWN)
    {   usDBmLoadActPwrSetp   = CTLGetLoadSetpRampAct(CTL_LOAD_OFF_ACT_SETP,
                                usDBmLoadActPwrSetp,  usDBmLoadActPwrSelect);
        usDBmLoadRctPwrSetp   = CTLGetLoadSetpRampRct(CTL_LOAD_OFF_RCT_SETP,
                                usDBmLoadRctPwrSetp,  usDBmLoadRctPwrSelect);
        return CTL_PID_MODE_LOAD;
    }
    else if (usPhase == CTL_PHASE_WORKING)
    {   if (usDBmCanSchedIsHighest != 0)
        {   usDBmLoadActPwrSelect = usDBmGensActPowerAll;
            usDBmLoadActPwrSetp   = usDBmGensActPowerAll;
            usDBmLoadRctPwrSelect = usDBmGensReactPowerAll;
            usDBmLoadRctPwrSetp   = usDBmGensReactPowerAll;
            return CTL_PID_MODE_SINGLE;
        }
        else
        {   usDBmLoadActPwrSelect = usDBmCanSchedActPowerSetp;
            usDBmLoadActPwrSetp   = usDBmCanSchedActPowerSetp;
            usDBmLoadRctPwrSelect = usDBmCanSchedRctPowerSetp;
            usDBmLoadRctPwrSetp   = usDBmCanSchedRctPowerSetp;
            return CTL_PID_MODE_LOAD;
        }
    }
    return CTL_PID_MODE_HOLD;
}
#endif

/* ******************************************************************** */
/*                           CTLGetSimpleSysPhase()                     */
/* ******************************************************************** */
/*
CTL_PHASE_INIT
CTL_PHASE_STOPPED
CTL_PHASE_EMERGENCY
CTL_PHASE_READY
CTL_PHASE_STARTING
CTL_PHASE_STOPPING
CTL_PHASE_IDLING_UP
CTL_PHASE_IDLING_DOWN
CTL_PHASE_RAMP_UP
CTL_PHASE_RAMP_DOWN
CTL_PHASE_RATED_UP
CTL_PHASE_RATED_DOWN
CTL_PHASE_WORKING
*/
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetSimpleSysPhase (INT16U usStep)
{   static INT16U usSimpleTime = 0;
    INT16U usDelay, usTimNow, usSimpleStep;
    usSimpleStep = usStep;
    usTimNow = usFW100msTimer;
    usDelay = usTimNow - usSimpleTime;
    if (usSimpleStep == CTL_PHASE_INIT)
    {   ERR_ES7_CLR_BIT(ERR_ES7_STS_ENG_WARM);
        if (usDBmEngEngineIsStopped != 0)
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_STOPPED;
        }   else
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_STOPPING;
        }
    }
    else if (usSimpleStep == CTL_PHASE_STOPPED)
    {   ERR_ES7_CLR_BIT(ERR_ES7_STS_ENG_WARM);
        if ((usDBmSysEmergnErrToStop != 0) ||
            (usDBmSysCommonErrToStop != 0) )
        {   usSimpleTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeStoppedToReady)
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_READY;
        }
    }
    else if (usSimpleStep == CTL_PHASE_EMERGENCY)
    {   if (usDBmEngEngineIsStopped != 0)
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_STOPPED;
        }
    }
    else if ((usDBmSysEmergnErrToStop != 0) ||
             (usDBmSysEmergnCmdToStop != 0) )
    {   usSimpleTime = usTimNow;
        usSimpleStep = CTL_PHASE_EMERGENCY;
    }
    else if (usSimpleStep == CTL_PHASE_READY)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_STOPPED;
        }
        else if (usDBmSysCommonCmdToStop != 0)
        {   usSimpleTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeReadyToStarting)
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_STARTING;
        }
    }
    else if (usSimpleStep == CTL_PHASE_STARTING)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_STOPPING;
        }
        else if (usDBmEngSpeed > usDBpEngSpeedIdleMin)
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_IDLING_UP;
        }
    }
    else if (usSimpleStep == CTL_PHASE_STOPPING)
    {   if (usDBmEngEngineIsStopped != 0)
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_STOPPED;
        }
    }
    else if (usSimpleStep == CTL_PHASE_IDLING_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_IDLING_DOWN;
        }
        else if (usDelay >= usDBpTimeIdlingToRampUp)
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_RAMP_UP;
        }
    }
    else if (usSimpleStep == CTL_PHASE_IDLING_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_IDLING_UP;
        }
        else if (usDelay >= usDBpTimeIdlingToStopping)
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_STOPPING;
        }
    }
    else if (usSimpleStep == CTL_PHASE_RAMP_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_RAMP_DOWN;
        }
        else if (usDBmEngEngineIsRated != 0)
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_RATED_UP;
        }
    }
    else if (usSimpleStep == CTL_PHASE_RAMP_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_RAMP_UP;
        }
        else if (usDBmEngSpeed <= usDBpEngSpeedIdleMax)
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_IDLING_DOWN;
        }
    }
    else if (usSimpleStep == CTL_PHASE_RATED_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_RATED_DOWN;
        }
        else if (ERR_ES7_GET_BIT(ERR_ES7_STS_ENG_WARM) != 0)
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_WORKING;
        }
        else if (usDelay >= usDBpTimeRatedReadyDly)
        {   ERR_ES7_SET_BIT(ERR_ES7_STS_ENG_WARM);
            usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_WORKING;
        }
    }
    else if (usSimpleStep == CTL_PHASE_RATED_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_RATED_UP;
        }
        else if (usDelay >= usDBpTimeRatedToRampDowm)
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_RAMP_DOWN;
        }
    }
    else if (usSimpleStep == CTL_PHASE_WORKING)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_RATED_DOWN;
        }
        else if (usDBmSysCommonCmdToStop == 0)
        {   usSimpleTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeWorkToStopDly)
        {   usSimpleTime = usTimNow;
            usSimpleStep = CTL_PHASE_RATED_DOWN;
        }
    }
    else
    {   ERR_ES7_SET_BIT(CTL_STS_ERR_LOGIC);
        usSimpleStep = CTL_PHASE_INIT;
        usSimpleTime = usTimNow;
    }
    return usSimpleStep;
}
#endif

/* ******************************************************************** */
/*                           CTLGetSingleSysPhase()                     */
/* ******************************************************************** */
/*
CTL_PHASE_INIT
CTL_PHASE_STOPPED
CTL_PHASE_EMERGENCY
CTL_PHASE_READY
CTL_PHASE_STARTING
CTL_PHASE_STOPPING
CTL_PHASE_IDLING_UP
CTL_PHASE_IDLING_DOWN
CTL_PHASE_RAMP_UP
CTL_PHASE_RAMP_DOWN
CTL_PHASE_RATED_UP
CTL_PHASE_RATED_DOWN
CTL_PHASE_WAIT_KEY_SW
CTL_PHASE_MAIN_SW_ON
CTL_PHASE_MAIN_SW_OFF
CTL_PHASE_GENS_SW_ON
CTL_PHASE_GENS_SW_OFF
CTL_PHASE_WORKING
*/
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetSingleSysPhase (INT16U usStep)
{   static INT16U usSingleTime = 0;
    INT16U usDelay, usTimNow, usSingleStep;
    usSingleStep = usStep;
    usTimNow = usFW100msTimer;
    usDelay = usTimNow - usSingleTime;
    if (usSingleStep == CTL_PHASE_INIT)
    {   ERR_ES7_CLR_BIT(ERR_ES7_STS_ENG_WARM);
        if (usDBmEngEngineIsStopped != 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_STOPPED;
        }   else
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_STOPPING;
        }
    }
    else if (usSingleStep == CTL_PHASE_STOPPED)
    {   ERR_ES7_CLR_BIT(ERR_ES7_STS_ENG_WARM);
        if ((usDBmSysEmergnErrToStop != 0) ||
            (usDBmSysCommonErrToStop != 0) )
        {   usSingleTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeStoppedToReady)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_READY;
        }
    }
    else if (usSingleStep == CTL_PHASE_EMERGENCY)
    {   if (usDBmEngEngineIsStopped != 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_STOPPED;
        }
        if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }   else
        {   SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    else if ((usDBmSysEmergnErrToStop != 0) ||
             (usDBmSysEmergnCmdToStop != 0) )
    {   usSingleTime = usTimNow;
        usSingleStep = CTL_PHASE_EMERGENCY;
        SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
    }
    else if (usSingleStep == CTL_PHASE_READY)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_STOPPED;
        }
        else if (usDBmSysCommonCmdToStop != 0)
        {   usSingleTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeReadyToStarting)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_STARTING;
        }
    }
    else if (usSingleStep == CTL_PHASE_STARTING)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_STOPPING;
        }
        else if (usDBmEngSpeed > usDBpEngSpeedIdleMin)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_IDLING_UP;
        }
        if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }   else
        {   SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    else if (usSingleStep == CTL_PHASE_STOPPING)
    {   if (usDBmEngEngineIsStopped != 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_STOPPED;
        }
    }
    else if (usSingleStep == CTL_PHASE_IDLING_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_IDLING_DOWN;
        }
        else if (usDelay >= usDBpTimeIdlingToRampUp)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_RAMP_UP;
        }
    }
    else if (usSingleStep == CTL_PHASE_IDLING_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_IDLING_UP;
        }
        else if (usDelay >= usDBpTimeIdlingToStopping)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_STOPPING;
        }
    }
    else if (usSingleStep == CTL_PHASE_RAMP_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_RAMP_DOWN;
        }
        else if (usDBmEngEngineIsRated != 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_RATED_UP;
        }
    }
    else if (usSingleStep == CTL_PHASE_RAMP_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_RAMP_UP;
        }
        else if (usDBmEngSpeed <= usDBpEngSpeedIdleMax)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_IDLING_DOWN;
        }
    }
    else if (usSingleStep == CTL_PHASE_RATED_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_RATED_DOWN;
        }
        else if (ERR_ES7_GET_BIT(ERR_ES7_STS_ENG_WARM) != 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_WAIT_KEY_SW;
        }
        else if (usDelay >= usDBpTimeRatedReadyDly)
        {   ERR_ES7_SET_BIT(ERR_ES7_STS_ENG_WARM);
            usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_WAIT_KEY_SW;
        }
    }
    else if (usSingleStep == CTL_PHASE_RATED_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_RATED_UP;
        }
        else if (usDelay >= usDBpTimeRatedToRampDowm)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_RAMP_DOWN;
        }
    }    
    else if (usSingleStep == CTL_PHASE_WAIT_KEY_SW)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_RATED_DOWN;
        }
        else if ((usDBmSysCommonCmdToSwOn != 0) &&
                 (usDBmSysGensSwOnCndt != 0))
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_MAIN_SW_OFF;
        }
    }
    else if (usSingleStep == CTL_PHASE_MAIN_SW_OFF)
    {   if (sCTLMainSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_GENS_SW_ON;
        }
        else if (SFGetSwitchOffErr(&sCTLMainSwitch) != 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_RATED_DOWN;
            ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_SW_OFF);
        }
        else
        {   SFSwitchOffTimes(&sCTLMainSwitch,ucCTLMainSwTry);
        }
    }
    else if (usSingleStep == CTL_PHASE_MAIN_SW_ON)
    {   if (sCTLMainSwitch.ucStatus == SF_SW_STS_SWON_ED)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_RATED_DOWN;
        }
        else if (SFGetSwitchOnErr(&sCTLMainSwitch) != 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_RATED_DOWN;
            ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_SW_ON);
        }
        else
        {   SFSwitchOnTimes(&sCTLMainSwitch,ucCTLMainSwTry);
        }
    }
    else if (usSingleStep == CTL_PHASE_GENS_SW_ON)
    {   if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWON_ED)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_WORKING;
        }
        else if (SFGetSwitchOnErr(&sCTLGensSwitch) != 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_RATED_DOWN;
            ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_ON);
        }
        else
        {   SFSwitchOnTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    else if (usSingleStep == CTL_PHASE_GENS_SW_OFF)
    {   if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_MAIN_SW_ON;
        }
        else if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_RATED_DOWN;
            ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }
        else
        {   SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    else if (usSingleStep == CTL_PHASE_WORKING)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_GENS_SW_OFF;
        }
        else if ((usDBmSysCommonCmdToStop == 0) &&
                 (usDBmSysCommonCmdToSwOn != 0) )
        {   usSingleTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeWorkToStopDly)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_GENS_SW_OFF;
        }
    }
    else
    {   ERR_ES7_SET_BIT(CTL_STS_ERR_LOGIC);
        usSingleStep = CTL_PHASE_INIT;
        usSingleTime = usTimNow;
    }
    return usSingleStep;
}
#endif

/* ******************************************************************** */
/*                           CTLGetAmfSysPhase()                        */
/* ******************************************************************** */
/*
CTL_PHASE_INIT
CTL_PHASE_STOPPED
CTL_PHASE_EMERGENCY
CTL_PHASE_READY
CTL_PHASE_STARTING
CTL_PHASE_STOPPING
CTL_PHASE_IDLING_UP
CTL_PHASE_IDLING_DOWN
CTL_PHASE_RAMP_UP
CTL_PHASE_RAMP_DOWN
CTL_PHASE_RATED_UP
CTL_PHASE_RATED_DOWN
CTL_PHASE_WAIT_KEY_SW
CTL_PHASE_WORKING
CTL_PHASE_SYNCHRING
CTL_PHASE_LOADING_DOWN
CTL_PHASE_GENS_SW_ON
CTL_PHASE_GENS_SW_OFF
CTL_PHASE_MAIN_SW_ON
CTL_PHASE_MAIN_SW_ON2
CTL_PHASE_MAIN_SW_OFF
CTL_PHASE_MAIN_SW_OFF2
*/
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetAmfSysPhase (INT16U usStep)
{   static INT16U usAmfTime = 0;
    INT16U usDelay, usTimNow, usAmfStep;
    usAmfStep = usStep;
    usTimNow = usFW100msTimer;
    usDelay = usTimNow - usAmfTime;
    /* **************** CTL_PHASE_INIT: Initializing ****************** */
    if (usAmfStep == CTL_PHASE_INIT)
    {   ERR_ES7_CLR_BIT(ERR_ES7_STS_ENG_WARM);
        if (usDBmEngEngineIsStopped != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_STOPPED;
        }   else
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_STOPPING;
        }
    }
    /* **************** CTL_PHASE_STOPPED: Stopped ******************** */
    else if (usAmfStep == CTL_PHASE_STOPPED)
    {   ERR_ES7_CLR_BIT(ERR_ES7_STS_ENG_WARM);
        if ((usDBmSysEmergnErrToStop != 0) ||
            (usDBmSysCommonErrToStop != 0) )
        {   usAmfTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeStoppedToReady)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_READY;
        }
    }
    /* **************** CTL_PHASE_EMERGENCY: Emergency **************** */
    else if (usAmfStep == CTL_PHASE_EMERGENCY)
    {   if (usDBmEngEngineIsStopped != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_STOPPED;
        }
        if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }   else
        {   SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    /* **************** CTL_PHASE_EMERGENCY: Emergency **************** */
    else if ((usDBmSysEmergnErrToStop != 0) ||
             (usDBmSysEmergnCmdToStop != 0) )
    {   usAmfTime = usTimNow;
        usAmfStep = CTL_PHASE_EMERGENCY;
        SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
    }
    /* **************** CTL_PHASE_READY: Ready ************************ */
    else if (usAmfStep == CTL_PHASE_READY)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_STOPPED;
        }
        else if (usDBmSysCommonCmdToStop != 0)
        {   usAmfTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeReadyToStarting)
        {   usAmfTime = usTimNow;
            if (usDBfAmfMainSwOffBfrStart != 0)
            {   usAmfStep = CTL_PHASE_MAIN_SW_OFF;
            }   else
            {   usAmfStep = CTL_PHASE_STARTING;
            }
        }
    }
    /* **************** CTL_PHASE_MAIN_SW_OFF: Main Sw off1 ********** */
    else if (usAmfStep == CTL_PHASE_MAIN_SW_OFF)
    {   if (sCTLMainSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_STARTING;
        }
        else if (SFGetSwitchOffErr(&sCTLMainSwitch) != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_READY;
            ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_SW_OFF);
        }
        else
        {   SFSwitchOffTimes(&sCTLMainSwitch,ucCTLMainSwTry);
        }
    }
    /* **************** CTL_PHASE_STARTING: Starting ****************** */
    else if (usAmfStep == CTL_PHASE_STARTING)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_STOPPING;
        }
        else if (usDBmEngSpeed > usDBpEngSpeedIdleMin)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_IDLING_UP;
        }
        if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }   else
        {   SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    /* **************** CTL_PHASE_STOPPING: Stopping ****************** */
    else if (usAmfStep == CTL_PHASE_STOPPING)
    {   if (usDBmEngEngineIsStopped != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_STOPPED;
        }
    }
    /* **************** CTL_PHASE_IDLING_UP: Idling_Up **************** */
    else if (usAmfStep == CTL_PHASE_IDLING_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_IDLING_DOWN;
        }
        else if (usDelay >= usDBpTimeIdlingToRampUp)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_RAMP_UP;
        }
    }
    /* **************** CTL_PHASE_IDLING_DOWN: Idling_Down ************ */
    else if (usAmfStep == CTL_PHASE_IDLING_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_IDLING_UP;
        }
        else if (usDelay >= usDBpTimeIdlingToStopping)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_STOPPING;
        }
    }
    /* **************** CTL_PHASE_RAMP_UP: Ramp_Up ******************** */
    else if (usAmfStep == CTL_PHASE_RAMP_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_RAMP_DOWN;
        }
        else if (usDBmEngEngineIsRated != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_RATED_UP;
        }
    }
    /* **************** CTL_PHASE_RAMP_DOWN: Ramp_Down **************** */
    else if (usAmfStep == CTL_PHASE_RAMP_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_RAMP_UP;
        }
        else if (usDBmEngSpeed <= usDBpEngSpeedIdleMax)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_IDLING_DOWN;
        }
    }
    /* **************** CTL_PHASE_RATED_UP: Rated_UP ****************** */
    else if (usAmfStep == CTL_PHASE_RATED_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_RATED_DOWN;
        }
        else if (ERR_ES7_GET_BIT(ERR_ES7_STS_ENG_WARM) != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_WAIT_KEY_SW;
        }
        else if (usDelay >= usDBpTimeRatedReadyDly)
        {   ERR_ES7_SET_BIT(ERR_ES7_STS_ENG_WARM);
            usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_WAIT_KEY_SW;
        }
    }
    /* **************** CTL_PHASE_RATED_DOWN: Rated_Down ************** */
    else if (usAmfStep == CTL_PHASE_RATED_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_RATED_UP;
        }
        else if (usDelay >= usDBpTimeRatedToRampDowm)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_RAMP_DOWN;
        }
    }    
    /* **************** CTL_PHASE_WAIT_KEY_SW: Wait_sw_on_key ********* */
    else if (usAmfStep == CTL_PHASE_WAIT_KEY_SW)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_RATED_DOWN;
        }
        else if ((usDBmSysCommonCmdToSwOn != 0) &&
                 (usDBmSysGensSwOnCndt != 0))
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_MAIN_SW_OFF2;
        }
    }
    /* **************** CTL_PHASE_MAIN_SW_OFF2: Grid_Sw_off2 ********** */
    else if (usAmfStep == CTL_PHASE_MAIN_SW_OFF2)
    {   if (sCTLMainSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_GENS_SW_ON;
        }
        else if (SFGetSwitchOffErr(&sCTLMainSwitch) != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_RATED_DOWN;
            ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_SW_OFF);
        }
        else
        {   SFSwitchOffTimes(&sCTLMainSwitch,ucCTLMainSwTry);
        }
    }
    /* **************** CTL_PHASE_GENS_SW_ON: Gens_Sw_on ************** */
    else if (usAmfStep == CTL_PHASE_GENS_SW_ON)
    {   if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWON_ED)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_WORKING;
        }
        else if (SFGetSwitchOnErr(&sCTLGensSwitch) != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_RATED_DOWN;
            ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_ON);
        }
        else
        {   SFSwitchOnTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    /* **************** CTL_PHASE_WORKING: Working ******************** */
    else if (usAmfStep == CTL_PHASE_WORKING)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_GENS_SW_OFF;
        }
        else if ((usDBmSysCommonCmdToStop == 0) &&
                 (usDBmSysCommonCmdToSwOn != 0) )
        {   usAmfTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeWorkToStopDly)
        {   if ((usDBfAmfSoftUnloadingOn != 0) &&
                (usDBmMainVoltReadyToSyn != 0) )
            {   usAmfTime = usTimNow;
                usAmfStep = CTL_PHASE_SYNCHRING;
                SFClrSwitchErrSum(&sCTLMainSwitch);
            }   else
            {   usAmfTime = usTimNow;
                usAmfStep = CTL_PHASE_GENS_SW_OFF;
            }
        }
    }
    /* **************** CTL_PHASE_SYNCHRING: Synchring **************** */
    else if (usAmfStep == CTL_PHASE_SYNCHRING)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_GENS_SW_OFF;
        }
        else if ((usDBmSysCommonCmdToStop == 0) &&
                 (usDBmSysCommonCmdToSwOn != 0) )
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_WORKING;
        }
        else if (SFGetSwitchErrSum(&sCTLMainSwitch) >= ucCTLMainSwTry)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_GENS_SW_OFF;
            ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_SW_ON);
        }
        else if (usDBmSysMainSwOnCndt != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_MAIN_SW_ON;
            SFSwitchOnTimes(&sCTLMainSwitch,1);
        }
    }
    /* **************** CTL_PHASE_MAIN_SW_ON: Grid_Sw_on1 ************ */
    else if (usAmfStep == CTL_PHASE_MAIN_SW_ON)
    {   if (sCTLMainSwitch.ucStatus == SF_SW_STS_SWON_ED)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_LOADING_DOWN;
        }
        else if (SFGetSwitchOnErr(&sCTLMainSwitch) != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_SYNCHRING;
        }
        else
        {   SFSwitchOnTimes(&sCTLMainSwitch,1);
        }
    }
    /* **************** CTL_PHASE_MAIN_SW_ON2: Grid_Sw_on2 ************ */
    else if (usAmfStep == CTL_PHASE_MAIN_SW_ON2)
    {   if (sCTLMainSwitch.ucStatus == SF_SW_STS_SWON_ED)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_RATED_DOWN;
        }
        else if (SFGetSwitchOnErr(&sCTLMainSwitch) != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_RATED_DOWN;
            ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_SW_ON);
        }
        else
        {   SFSwitchOnTimes(&sCTLMainSwitch,ucCTLMainSwTry);
        }
    }
    /* **************** CTL_PHASE_GENS_SW_OFF: Gens_Sw_off ************ */
    else if (usAmfStep == CTL_PHASE_GENS_SW_OFF)
    {   if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_MAIN_SW_ON2;
        }
        else if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_RATED_DOWN;
            ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }
        else
        {   SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    /* **************** CTL_PHASE_LOADING_DOWN: Loading_Down ********** */
    else if (usAmfStep == CTL_PHASE_LOADING_DOWN)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDelay >= usDBpTimeOfLoadingOff))
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_GENS_SW_OFF;
        }
    }
    /* ******************** Others: Logic Fault *********************** */
    else
    {   ERR_ES7_SET_BIT(CTL_STS_ERR_LOGIC);
        usAmfStep = CTL_PHASE_INIT;
        usAmfTime = usTimNow;
    }
    /* *********************** End of IF ****************************** */
    return usAmfStep;
}
#endif

/* ******************************************************************** */
/*                         CTLGetFixPwrSysPhase()                       */
/* ******************************************************************** */
/*
CTL_PHASE_INIT
CTL_PHASE_STOPPED
CTL_PHASE_EMERGENCY
CTL_PHASE_READY
CTL_PHASE_STARTING
CTL_PHASE_STOPPING
CTL_PHASE_IDLING_UP
CTL_PHASE_IDLING_DOWN
CTL_PHASE_RAMP_UP
CTL_PHASE_RAMP_DOWN
CTL_PHASE_RATED_UP
CTL_PHASE_RATED_DOWN
CTL_PHASE_WAIT_KEY_SW
CTL_PHASE_SYNCHRING
CTL_PHASE_GENS_SW_ON
CTL_PHASE_GENS_SW_OFF
CTL_PHASE_LOADING_UP
CTL_PHASE_LOADING_DOWN
CTL_PHASE_WORKING
*/
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetFixPwrSysPhase (INT16U usStep)
{   static INT16U usFixPwrTime = 0;
    INT16U usDelay, usTimNow, usFixPwrStep;
    usFixPwrStep = usStep;
    usTimNow = usFW100msTimer;
    usDelay = usTimNow - usFixPwrTime;
    /* **************** CTL_PHASE_INIT: Initializing ****************** */
    if (usFixPwrStep == CTL_PHASE_INIT)
    {   ERR_ES7_CLR_BIT(ERR_ES7_STS_ENG_WARM);
        if (usDBmEngEngineIsStopped != 0)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_STOPPED;
        }   else
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_STOPPING;
        }
    }
    /* **************** CTL_PHASE_STOPPED: Stopped ******************** */
    else if (usFixPwrStep == CTL_PHASE_STOPPED)
    {   ERR_ES7_CLR_BIT(ERR_ES7_STS_ENG_WARM);
        if ((usDBmSysEmergnErrToStop != 0) ||
            (usDBmSysCommonErrToStop != 0) )
        {   usFixPwrTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeStoppedToReady)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_READY;
        }
    }    
    /* **************** CTL_PHASE_EMERGENCY: Emergency **************** */
    else if (usFixPwrStep == CTL_PHASE_EMERGENCY)
    {   if (usDBmEngEngineIsStopped != 0)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_STOPPED;
        }
        if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }   else
        {   SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    /* **************** CTL_PHASE_EMERGENCY: Emergency **************** */
    else if ((usDBmSysEmergnErrToStop != 0) ||
             (usDBmSysEmergnCmdToStop != 0) )
    {   usFixPwrTime = usTimNow;
        usFixPwrStep = CTL_PHASE_EMERGENCY;
        SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
    }    
    /* **************** CTL_PHASE_READY: Ready ************************ */
    else if (usFixPwrStep == CTL_PHASE_READY)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_STOPPED;
        }
        else if (usDBmSysCommonCmdToStop != 0)
        {   usFixPwrTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeReadyToStarting)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_STARTING;
        }
    }
    /* **************** CTL_PHASE_STARTING: Starting ****************** */
    else if (usFixPwrStep == CTL_PHASE_STARTING)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_STOPPING;
        }
        else if (usDBmEngSpeed > usDBpEngSpeedIdleMin)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_IDLING_UP;
        }
        if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }   else
        {   SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    /* **************** CTL_PHASE_STOPPING: Stopping ****************** */
    else if (usFixPwrStep == CTL_PHASE_STOPPING)
    {   if (usDBmEngEngineIsStopped != 0)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_STOPPED;
        }
    }
    /* **************** CTL_PHASE_IDLING_UP: Idling_Up **************** */
    else if (usFixPwrStep == CTL_PHASE_IDLING_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_IDLING_DOWN;
        }
        else if (usDelay >= usDBpTimeIdlingToRampUp)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_RAMP_UP;
        }
    }
    /* **************** CTL_PHASE_IDLING_DOWN: Idling_Down ************ */
    else if (usFixPwrStep == CTL_PHASE_IDLING_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_IDLING_UP;
        }
        else if (usDelay >= usDBpTimeIdlingToStopping)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_STOPPING;
        }
    }
    /* **************** CTL_PHASE_RAMP_UP: Ramp_Up ******************** */
    else if (usFixPwrStep == CTL_PHASE_RAMP_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_RAMP_DOWN;
        }
        else if (usDBmEngEngineIsRated != 0)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_RATED_UP;
        }
    }
    /* **************** CTL_PHASE_RAMP_DOWN: Ramp_Down **************** */
    else if (usFixPwrStep == CTL_PHASE_RAMP_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_RAMP_UP;
        }
        else if (usDBmEngSpeed <= usDBpEngSpeedIdleMax)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_IDLING_DOWN;
        }
    }
    /* **************** CTL_PHASE_RATED_UP: Rated_UP ****************** */
    else if (usFixPwrStep == CTL_PHASE_RATED_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_RATED_DOWN;
        }
        else if (ERR_ES7_GET_BIT(ERR_ES7_STS_ENG_WARM) != 0)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_WAIT_KEY_SW;
        }
        else if (usDelay >= usDBpTimeRatedReadyDly)
        {   ERR_ES7_SET_BIT(ERR_ES7_STS_ENG_WARM);
            usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_WAIT_KEY_SW;
        }
    }
    /* **************** CTL_PHASE_RATED_DOWN: Rated_Down ************** */
    else if (usFixPwrStep == CTL_PHASE_RATED_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_RATED_UP;
        }
        else if (usDelay >= usDBpTimeRatedToRampDowm)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_RAMP_DOWN;
        }
    }
    /* **************** CTL_PHASE_WAIT_KEY_SW: Wait_sw_on_key ********* */
    else if (usFixPwrStep == CTL_PHASE_WAIT_KEY_SW)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_RATED_DOWN;
        }
        else if ((usDBmSysCommonCmdToSwOn != 0) &&
                 (usDBmGensIsReadyToLoad  != 0))
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_SYNCHRING;
            SFClrSwitchErrSum(&sCTLGensSwitch);
        }
    }
    /* **************** CTL_PHASE_SYNCHRING: Synchring **************** */
    else if (usFixPwrStep == CTL_PHASE_SYNCHRING)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) ||
            (usDBmSysCommonCmdToSwOn == 0) )
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_RATED_DOWN;
        }
        else if (SFGetSwitchErrSum(&sCTLGensSwitch) >= ucCTLGensSwTry)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_RATED_DOWN;
            ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_ON);
        }
        else if (usDBmSysGensSwOnCndt != 0)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_GENS_SW_ON;
            SFSwitchOnTimes(&sCTLGensSwitch,1);
        }
    }
    /* **************** CTL_PHASE_GENS_SW_ON: Gens_Sw_on ************** */
    else if (usFixPwrStep == CTL_PHASE_GENS_SW_ON)
    {   if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWON_ED)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_LOADING_UP;
        }
        else if (SFGetSwitchOnErr(&sCTLGensSwitch) != 0)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_SYNCHRING;
        }
        else
        {   SFSwitchOnTimes(&sCTLGensSwitch,1);
        }
    }
    /* **************** CTL_PHASE_GENS_SW_OFF: Gens_Sw_off ************ */
    else if (usFixPwrStep == CTL_PHASE_GENS_SW_OFF)
    {   if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_RATED_DOWN;
        }
        else if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_RATED_DOWN;
            ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }
        else
        {   SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    /* **************** CTL_PHASE_LOADING_UP: Gens_Loading_Up ********* */
    else if (usFixPwrStep == CTL_PHASE_LOADING_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) ||
            (usDBmSysCommonCmdToSwOn == 0) )
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_LOADING_DOWN;
        }
        else if (usDelay >= usDBpTimeOfLoadingOn)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_WORKING;
        }
    }
    /* **************** CTL_PHASE_LOADING_DOWN: Gens_Loading_Down ******* */
    else if (usFixPwrStep == CTL_PHASE_LOADING_DOWN)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_GENS_SW_OFF;
        }
        else if ((usDBmSysCommonCmdToStop == 0) &&
                 (usDBmSysCommonCmdToSwOn != 0) )
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_LOADING_UP;
        }
        else if (usDelay >= usDBpTimeOfLoadingOff)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_GENS_SW_OFF;
        }
    }    
    /* **************** CTL_PHASE_WORKING: Working ******************** */
    else if (usFixPwrStep == CTL_PHASE_WORKING)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_GENS_SW_OFF;
        }
        else if ((usDBmSysCommonCmdToStop == 0) &&
                 (usDBmSysCommonCmdToSwOn != 0) )
        {   usFixPwrTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeWorkToStopDly)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_LOADING_DOWN;
        }
    }
    /* ******************** Others: Logic Fault *********************** */
    else
    {   ERR_ES7_SET_BIT(CTL_STS_ERR_LOGIC);
        usFixPwrStep = CTL_PHASE_INIT;
        usFixPwrTime = usTimNow;
    }
    /* *********************** End of IF ****************************** */
    return usFixPwrStep;
}
#endif

/* ******************************************************************** */
/*                          CTLGetIslandSysPhase()                      */
/* ******************************************************************** */
/*
CTL_PHASE_INIT
CTL_PHASE_STOPPED
CTL_PHASE_EMERGENCY
CTL_PHASE_READY
CTL_PHASE_STARTING
CTL_PHASE_STOPPING
CTL_PHASE_IDLING_UP
CTL_PHASE_IDLING_DOWN
CTL_PHASE_RAMP_UP
CTL_PHASE_RAMP_DOWN
CTL_PHASE_RATED_UP
CTL_PHASE_RATED_DOWN
CTL_PHASE_WAIT_KEY_SW
CTL_PHASE_SYNCHRING
CTL_PHASE_SYNCHRING2
CTL_PHASE_GENS_SW_ON
CTL_PHASE_GENS_SW_OFF
CTL_PHASE_LOADING_UP
CTL_PHASE_LOADING_DOWN
CTL_PHASE_FIXPWR_UP
CTL_PHASE_FIXPWR_DOWN
CTL_PHASE_MAIN_SW_ON
CTL_PHASE_MAIN_SW_ON2
CTL_PHASE_MAIN_SW_OFF
CTL_PHASE_WORKING
*/
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetIslandSysPhase (INT16U usStep)
{   static INT16U usIslandTime = 0;
    INT16U usDelay, usTimNow, usIslandStep;
    usIslandStep = usStep;
    usTimNow = usFW100msTimer;
    usDelay = usTimNow - usIslandTime;
    /* **************** CTL_PHASE_INIT: Initializing ****************** */
    if (usIslandStep == CTL_PHASE_INIT)
    {   ERR_ES7_CLR_BIT(ERR_ES7_STS_ENG_WARM);
        if (usDBmEngEngineIsStopped != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_STOPPED;
        }   else
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_STOPPING;
        }
    }
    /* **************** CTL_PHASE_STOPPED: Stopped ******************** */
    else if (usIslandStep == CTL_PHASE_STOPPED)
    {   ERR_ES7_CLR_BIT(ERR_ES7_STS_ENG_WARM);
        if ((usDBmSysEmergnErrToStop != 0) ||
            (usDBmSysCommonErrToStop != 0) )
        {   usIslandTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeStoppedToReady)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_READY;
        }
    }    
    /* **************** CTL_PHASE_EMERGENCY: Emergency **************** */
    else if (usIslandStep == CTL_PHASE_EMERGENCY)
    {   if (usDBmEngEngineIsStopped != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_STOPPED;
        }
        if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }   else
        {   SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    /* **************** CTL_PHASE_EMERGENCY: Emergency **************** */
    else if ((usDBmSysEmergnErrToStop != 0) ||
             (usDBmSysEmergnCmdToStop != 0) )
    {   usIslandTime = usTimNow;
        usIslandStep = CTL_PHASE_EMERGENCY;
        SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
    }    
    /* **************** CTL_PHASE_READY: Ready ************************ */
    else if (usIslandStep == CTL_PHASE_READY)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_STOPPED;
        }
        else if (usDBmSysCommonCmdToStop != 0)
        {   usIslandTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeReadyToStarting)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_STARTING;
        }
    }
    /* **************** CTL_PHASE_STARTING: Starting ****************** */
    else if (usIslandStep == CTL_PHASE_STARTING)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_STOPPING;
        }
        else if (usDBmEngSpeed > usDBpEngSpeedIdleMin)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_IDLING_UP;
        }
        if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }   else
        {   SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    /* **************** CTL_PHASE_STOPPING: Stopping ****************** */
    else if (usIslandStep == CTL_PHASE_STOPPING)
    {   if (usDBmEngEngineIsStopped != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_STOPPED;
        }
    }
    /* **************** CTL_PHASE_IDLING_UP: Idling_Up **************** */
    else if (usIslandStep == CTL_PHASE_IDLING_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_IDLING_DOWN;
        }
        else if (usDelay >= usDBpTimeIdlingToRampUp)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_RAMP_UP;
        }
    }
    /* **************** CTL_PHASE_IDLING_DOWN: Idling_Down ************ */
    else if (usIslandStep == CTL_PHASE_IDLING_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_IDLING_UP;
        }
        else if (usDelay >= usDBpTimeIdlingToStopping)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_STOPPING;
        }
    }
    /* **************** CTL_PHASE_RAMP_UP: Ramp_Up ******************** */
    else if (usIslandStep == CTL_PHASE_RAMP_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_RAMP_DOWN;
        }
        else if (usDBmEngEngineIsRated != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_RATED_UP;
        }
    }
    /* **************** CTL_PHASE_RAMP_DOWN: Ramp_Down **************** */
    else if (usIslandStep == CTL_PHASE_RAMP_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_RAMP_UP;
        }
        else if (usDBmEngSpeed <= usDBpEngSpeedIdleMax)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_IDLING_DOWN;
        }
    }
    /* **************** CTL_PHASE_RATED_UP: Rated_UP ****************** */
    else if (usIslandStep == CTL_PHASE_RATED_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_RATED_DOWN;
        }
        else if (ERR_ES7_GET_BIT(ERR_ES7_STS_ENG_WARM) != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_WAIT_KEY_SW;
        }
        else if (usDelay >= usDBpTimeRatedReadyDly)
        {   ERR_ES7_SET_BIT(ERR_ES7_STS_ENG_WARM);
            usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_WAIT_KEY_SW;
        }
    }
    /* **************** CTL_PHASE_RATED_DOWN: Rated_Down ************** */
    else if (usIslandStep == CTL_PHASE_RATED_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_RATED_UP;
        }
        else if (usDelay >= usDBpTimeRatedToRampDowm)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_RAMP_DOWN;
        }
    }    
    /* **************** CTL_PHASE_WAIT_KEY_SW: Wait_sw_on_key ********* */
    else if (usIslandStep == CTL_PHASE_WAIT_KEY_SW)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_RATED_DOWN;
        }
        else if ((usDBmSysCommonCmdToSwOn != 0) &&
                 (usDBmGensIsReadyToLoad  != 0))
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_SYNCHRING;
            SFClrSwitchErrSum(&sCTLGensSwitch);
        }
    }
    /* **************** CTL_PHASE_SYNCHRING: Synchring1 ************** */
    else if (usIslandStep == CTL_PHASE_SYNCHRING)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) ||
            (usDBmSysCommonCmdToSwOn == 0) )
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_RATED_DOWN;
        }
        else if (SFGetSwitchErrSum(&sCTLGensSwitch) >= ucCTLGensSwTry)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_RATED_DOWN;
            ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_ON);
        }
        else if (usDBmSysGensSwOnCndt != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_GENS_SW_ON;
            SFSwitchOnTimes(&sCTLGensSwitch,1);
        }
    }
    /* **************** CTL_PHASE_GENS_SW_ON: Gens_Sw_on ************** */
    else if (usIslandStep == CTL_PHASE_GENS_SW_ON)
    {   if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWON_ED)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_LOADING_UP;
        }
        else if (SFGetSwitchOnErr(&sCTLGensSwitch) != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_SYNCHRING;
        }
        else
        {   SFSwitchOnTimes(&sCTLGensSwitch,1);
        }
    }    
    /* **************** CTL_PHASE_LOADING_UP: Gens_Loading_Up ********* */
    else if (usIslandStep == CTL_PHASE_LOADING_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) ||
            (usDBmSysCommonCmdToSwOn == 0) )
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_LOADING_DOWN;
        }
        else if (usDelay >= usDBpTimeOfLoadingOn)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_FIXPWR_UP;
        }
    }
    /* **************** CTL_PHASE_FIXPWR_UP: Fixed_Power_Up ************** */
    else if (usIslandStep == CTL_PHASE_FIXPWR_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) ||
            (usDBmSysCommonCmdToSwOn == 0) )
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_FIXPWR_DOWN;
        }
        else if (usDelay >= usDBpTimeOfFixedPowerUp)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_MAIN_SW_OFF;
        }
    }
    /* **************** CTL_PHASE_MAIN_SW_OFF: Main_Sw_off ************ */
    else if (usIslandStep == CTL_PHASE_MAIN_SW_OFF)
    {   if (sCTLMainSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_WORKING;
        }
        else if (SFGetSwitchOffErr(&sCTLMainSwitch) != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_FIXPWR_DOWN;
            ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_SW_OFF);
        }
        else
        {   SFSwitchOffTimes(&sCTLMainSwitch,ucCTLMainSwTry);
        }
    }
    /* **************** CTL_PHASE_WORKING: Working ******************** */
    else if (usIslandStep == CTL_PHASE_WORKING)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_GENS_SW_OFF;
        }
        else if ((usDBmSysCommonCmdToStop == 0) &&
                 (usDBmSysCommonCmdToSwOn != 0) )
        {   usIslandTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeWorkToStopDly)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_SYNCHRING2;
            SFClrSwitchErrSum(&sCTLMainSwitch);
        }
    }
    /* **************** CTL_PHASE_SYNCHRING2: Synchring2 ************** */
    else if (usIslandStep == CTL_PHASE_SYNCHRING2)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_GENS_SW_OFF;
        }
        else if((usDBmSysCommonCmdToStop == 0) &&
                (usDBmSysCommonCmdToSwOn != 0) )
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_WORKING;
        }
        else if (SFGetSwitchErrSum(&sCTLMainSwitch) >= ucCTLMainSwTry)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_GENS_SW_OFF;
            ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_SW_ON);
        }
        else if (usDBmSysGensSwOnCndt != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_MAIN_SW_ON;
            SFSwitchOnTimes(&sCTLMainSwitch,1);
        }
    }
    /* **************** CTL_PHASE_MAIN_SW_ON: Main_Sw_on1 ************ */
    else if (usIslandStep == CTL_PHASE_MAIN_SW_ON)
    {   if (sCTLMainSwitch.ucStatus == SF_SW_STS_SWON_ED)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_FIXPWR_DOWN;
        }
        else if (SFGetSwitchOnErr(&sCTLMainSwitch) != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_SYNCHRING2;
        }
        else
        {   SFSwitchOnTimes(&sCTLMainSwitch,1);
        }
    }
    /* **************** CTL_PHASE_FIXPWR_DOWN: Fixed_Power_Down ********** */
    else if (usIslandStep == CTL_PHASE_FIXPWR_DOWN)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_GENS_SW_OFF;
        }
        else if ((usDBmSysCommonCmdToStop == 0) &&
                 (usDBmSysCommonCmdToSwOn != 0) )
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_FIXPWR_UP;
        }
        else if (usDelay >= usDBpTimeOfFixedPowerDown)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_LOADING_DOWN;
        }
    }
    /* **************** CTL_PHASE_LOADING_DOWN: Gens_Loading_Down ******* */
    else if (usIslandStep == CTL_PHASE_LOADING_DOWN)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_GENS_SW_OFF;
        }
        else if ((usDBmSysCommonCmdToStop == 0) &&
                 (usDBmSysCommonCmdToSwOn != 0) )
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_LOADING_UP;
        }
        else if (usDelay >= usDBpTimeOfLoadingOff)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_GENS_SW_OFF;
        }
    }
    /* **************** CTL_PHASE_GENS_SW_OFF: Gens_Sw_off ************ */
    else if (usIslandStep == CTL_PHASE_GENS_SW_OFF)
    {   if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_MAIN_SW_ON2;
        }
        else if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_RATED_DOWN;
            ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }
        else
        {   SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    /* **************** CTL_PHASE_MAIN_SW_ON2: Main_Sw_on2 ************ */
    else if (usIslandStep == CTL_PHASE_MAIN_SW_ON2)
    {   if (sCTLMainSwitch.ucStatus == SF_SW_STS_SWON_ED)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_RATED_DOWN;
        }
        else if (SFGetSwitchOnErr(&sCTLMainSwitch) != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_RATED_DOWN;
            ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_SW_ON);
        }
        else
        {   SFSwitchOnTimes(&sCTLMainSwitch,ucCTLMainSwTry);
        }
    }
    /* ******************** Others: Logic Fault *********************** */
    else
    {   ERR_ES7_SET_BIT(CTL_STS_ERR_LOGIC);
        usIslandStep = CTL_PHASE_INIT;
        usIslandTime = usTimNow;
    }
    /* *********************** End of IF ****************************** */
    return usIslandStep;
}
#endif

/* ******************************************************************** */
/*                         CTLGetParallSysPhase()                       */
/* ******************************************************************** */
/*
CTL_PHASE_INIT
CTL_PHASE_STOPPED
CTL_PHASE_EMERGENCY
CTL_PHASE_READY
CTL_PHASE_STARTING
CTL_PHASE_STOPPING
CTL_PHASE_IDLING_UP
CTL_PHASE_IDLING_DOWN
CTL_PHASE_RAMP_UP
CTL_PHASE_RAMP_DOWN
CTL_PHASE_RATED_UP
CTL_PHASE_RATED_DOWN
CTL_PHASE_WAIT_KEY_SW
CTL_PHASE_SYNCHRING
CTL_PHASE_GENS_SW_ON
CTL_PHASE_GENS_SW_OFF
CTL_PHASE_LOADING_UP
CTL_PHASE_LOADING_DOWN
CTL_PHASE_WORKING
*/
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetParallSysPhase (INT16U usStep)
{   static INT16U usParallTime = 0;
    INT16U usDelay, usTimNow, usParallStep;
    usParallStep = usStep;
    usTimNow = usFW100msTimer;
    usDelay = usTimNow - usParallTime;
    /* **************** CTL_PHASE_INIT: Initializing ****************** */
    if (usParallStep == CTL_PHASE_INIT)
    {   ERR_ES7_CLR_BIT(ERR_ES7_STS_ENG_WARM);
        CAN2ClrTxSwitchLockCmd();
        if (usDBmEngEngineIsStopped != 0)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_STOPPED;
        }   else
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_STOPPING;
        }
    }
    /* **************** CTL_PHASE_STOPPED: Stopped ******************** */
    else if (usParallStep == CTL_PHASE_STOPPED)
    {   ERR_ES7_CLR_BIT(ERR_ES7_STS_ENG_WARM);
        CAN2ClrTxSwitchLockCmd();
        if ((usDBmSysEmergnErrToStop != 0) ||
            (usDBmSysCommonErrToStop != 0) )
        {   usParallTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeStoppedToReady)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_READY;
        }
    }
    /* **************** CTL_PHASE_EMERGENCY: Emergency **************** */
    else if (usParallStep == CTL_PHASE_EMERGENCY)
    {   CAN2ClrTxSwitchLockCmd();
        if (usDBmEngEngineIsStopped != 0)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_STOPPED;
        }
        if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }   else
        {   SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    /* **************** CTL_PHASE_EMERGENCY: Emergency **************** */
    else if ((usDBmSysEmergnErrToStop != 0) ||
             (usDBmSysEmergnCmdToStop != 0) )
    {   usParallTime = usTimNow;
        usParallStep = CTL_PHASE_EMERGENCY;
        SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
    }    
    /* **************** CTL_PHASE_READY: Ready ************************ */
    else if (usParallStep == CTL_PHASE_READY)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_STOPPED;
        }
        else if (usDBmSysCommonCmdToStop != 0)
        {   usParallTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeReadyToStarting)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_STARTING;
        }
    }
    /* **************** CTL_PHASE_STARTING: Starting ****************** */
    else if (usParallStep == CTL_PHASE_STARTING)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_STOPPING;
        }
        else if (usDBmEngSpeed > usDBpEngSpeedIdleMin)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_IDLING_UP;
        }
        if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }   else
        {   SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    /* **************** CTL_PHASE_STOPPING: Stopping ****************** */
    else if (usParallStep == CTL_PHASE_STOPPING)
    {   if (usDBmEngEngineIsStopped != 0)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_STOPPED;
        }
    }
    /* **************** CTL_PHASE_IDLING_UP: Idling_Up **************** */
    else if (usParallStep == CTL_PHASE_IDLING_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_IDLING_DOWN;
        }
        else if (usDelay >= usDBpTimeIdlingToRampUp)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_RAMP_UP;
        }
    }
    /* **************** CTL_PHASE_IDLING_DOWN: Idling_Down ************ */
    else if (usParallStep == CTL_PHASE_IDLING_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_IDLING_UP;
        }
        else if (usDelay >= usDBpTimeIdlingToStopping)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_STOPPING;
        }
    }
    /* **************** CTL_PHASE_RAMP_UP: Ramp_Up ******************** */
    else if (usParallStep == CTL_PHASE_RAMP_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_RAMP_DOWN;
        }
        else if (usDBmEngEngineIsRated != 0)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_RATED_UP;
        }
    }
    /* **************** CTL_PHASE_RAMP_DOWN: Ramp_Down **************** */
    else if (usParallStep == CTL_PHASE_RAMP_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_RAMP_UP;
        }
        else if (usDBmEngSpeed <= usDBpEngSpeedIdleMax)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_IDLING_DOWN;
        }
    }
    /* **************** CTL_PHASE_RATED_UP: Rated_UP ****************** */
    else if (usParallStep == CTL_PHASE_RATED_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_RATED_DOWN;
        }
        else if (ERR_ES7_GET_BIT(ERR_ES7_STS_ENG_WARM) != 0)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_WAIT_KEY_SW;
        }
        else if (usDelay >= usDBpTimeRatedReadyDly)
        {   ERR_ES7_SET_BIT(ERR_ES7_STS_ENG_WARM);
            usParallTime = usTimNow;
            usParallStep = CTL_PHASE_WAIT_KEY_SW;
        }
    }
    /* **************** CTL_PHASE_RATED_DOWN: Rated_Down ************** */
    else if (usParallStep == CTL_PHASE_RATED_DOWN)
    {   if ((usDBmSysCommonErrToStop == 0) &&
            (usDBmSysCommonCmdToStop == 0) )
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_RATED_UP;
        }
        else if (usDelay >= usDBpTimeRatedToRampDowm)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_RAMP_DOWN;
        }
    }
    /* **************** CTL_PHASE_WAIT_KEY_SW: Wait_sw_on_key ********* */
    else if (usParallStep == CTL_PHASE_WAIT_KEY_SW)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_RATED_DOWN;
        }
        else if ((usDBmSysCommonCmdToSwOn != 0) &&
                 (usDBmGensIsReadyToLoad  != 0))
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_SYNCHRING;
            SFClrSwitchErrSum(&sCTLGensSwitch);
            if (usDBmSysAutoOrManual == 0)
            {   CAN2SetTxSwitchLockCmd();
            }   else
            {   CAN2ClrTxSwitchLockCmd();
            }
        }
    }
    /* **************** CTL_PHASE_SYNCHRING: Synchring **************** */
    else if (usParallStep == CTL_PHASE_SYNCHRING)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) ||
            (usDBmSysCommonCmdToSwOn == 0) )
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_RATED_DOWN;
            CAN2ClrTxSwitchLockCmd();
        }
        else if (SFGetSwitchErrSum(&sCTLGensSwitch) >= ucCTLGensSwTry)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_RATED_DOWN;
            ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_ON);
            CAN2ClrTxSwitchLockCmd();
        }
        else if ((usDBmSysGensSwOnCndt != 0) &&
                ((CAN2AreSwAllLocked() != 0) ||
                 (CAN2GetTxSwitchLockCmd() == 0)))
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_GENS_SW_ON;
            SFSwitchOnTimes(&sCTLGensSwitch,1);
        }
    }
    /* **************** CTL_PHASE_GENS_SW_ON: Gens_Sw_on ************** */
    else if (usParallStep == CTL_PHASE_GENS_SW_ON)
    {   if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWON_ED)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_LOADING_UP;
            CAN2ClrTxSwitchLockCmd();
        }
        else if ((SFGetSwitchOnErr(&sCTLGensSwitch) != 0) ||
                 (SFGetSwitchOnLock(&sCTLGensSwitch) != 0) )
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_SYNCHRING;
        }
        else
        {   SFSwitchOnTimes(&sCTLGensSwitch,1);
        }
    }
    /* **************** CTL_PHASE_GENS_SW_OFF: Gens_Sw_off ************ */
    else if (usParallStep == CTL_PHASE_GENS_SW_OFF)
    {   if (sCTLGensSwitch.ucStatus == SF_SW_STS_SWOFF_ED)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_RATED_DOWN;
        }
        else if (SFGetSwitchOffErr(&sCTLGensSwitch) != 0)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_RATED_DOWN;
            ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SW_OFF);
        }
        else
        {   SFSwitchOffTimes(&sCTLGensSwitch,ucCTLGensSwTry);
        }
    }
    /* **************** CTL_PHASE_LOADING_UP: Gens_Loading_Up ********* */
    else if (usParallStep == CTL_PHASE_LOADING_UP)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) ||
            (usDBmSysCommonCmdToSwOn == 0) )
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_LOADING_DOWN;
        }
        else if ((usDelay >= usDBpTimeOfLoadingOn) ||
                 (usDBmCanSchedIsHighest != 0) )
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_WORKING;
        }
    }
    /* **************** CTL_PHASE_LOADING_DOWN: Gens_Loading_Down ******* */
    else if (usParallStep == CTL_PHASE_LOADING_DOWN)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_GENS_SW_OFF;
        }
        else if ((usDBmSysCommonCmdToStop == 0) &&
                 (usDBmSysCommonCmdToSwOn != 0) )
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_LOADING_UP;
        }
        else if ((usDelay >= usDBpTimeOfLoadingOff) ||
                 (usDBmCanSchedIsHighest != 0) )
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_GENS_SW_OFF;
        }
    }    
    /* **************** CTL_PHASE_WORKING: Working ******************** */
    else if (usParallStep == CTL_PHASE_WORKING)
    {   if (usDBmSysCommonErrToStop != 0)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_GENS_SW_OFF;
        }
        else if ((usDBmSysCommonCmdToStop == 0) &&
                 (usDBmSysCommonCmdToSwOn != 0) )
        {   usParallTime = usTimNow;
        }
        else if (usDelay >= usDBpTimeWorkToStopDly)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_LOADING_DOWN;
        }
    }
    /* ******************** Others: Logic Fault *********************** */
    else
    {   ERR_ES7_SET_BIT(CTL_STS_ERR_LOGIC);
        usParallStep = CTL_PHASE_INIT;
        usParallTime = usTimNow;
    }
    /* *********************** End of IF ****************************** */
    return usParallStep;
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */