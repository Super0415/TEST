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
    if (SFSwitchDelay(usDBmKeyErrorReset,&sCTLKeyErrReset) != 0)
    {   SFResetSwitchDelay(&sCTLKeyErrReset);
        SFResetOneError();
    }
    SFMonitorMainVolt(SF_ENABLE);
    SFMonitorMainFreq(SF_ENABLE);
    SFMonitorMainPhase(SF_ENABLE);
    SFMonitorMainSynVolt();
    SFMonitorMainSynFreq();
    SFMonitorMainVoltLost();
   #if (CTL_MAIN_CURR_ON == 1)
    SFMonitorMainCurrShort(SF_ENABLE);
    SFMonitorMainCurrLong(SF_ENABLE);
    SFMonitorMainCurrUnb(SF_ENABLE);
    SFMonitorMainActPwr(SF_ENABLE);
    SFMonitorMainReactPwr(SF_ENABLE);
    SFMonitorMainAppPwr(SF_ENABLE);
    SFMonitorMainRocof(SF_ENABLE);
    SFMonitorMainVector(SF_ENABLE);
   #endif
   #if (CTL_MAIN_CURR_GND_ON == 1)
    SFMonitorMainCurrGnd(SF_ENABLE);
   #endif
    SFMonitorGensCurrShort(SF_ENABLE);
    SFMonitorGensCurrLong(SF_ENABLE);
    SFMonitorGensCurrUnb(SF_ENABLE);
   #if (CTL_GENS_CURR_GND_ON == 1)
    SFMonitorGensCurrGnd(SF_ENABLE);
   #endif
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
    SFMonitorKeyAutoOrManual();
    usDBmSysAutoOrManual = CTLGetSysAutoOrManual();
    SFMonitorKeyCmdToStop(usDBmSysAutoOrManual);
    SFMonitorSwtCmdToStop(usDBmSysAutoOrManual);
    SFMonitorKeyCmdToSwOn(usDBmSysAutoOrManual);
    SFMonitorEepDataError();
}
#endif

/* ******************************************************************** */
/*                         CTLSysController()                           */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
void CTLSysController (void)
{   INT16U usPhase, usSpeed;
    usSpeed                  = usDBmEngSpeed;
    usDBmEngEngineIsStopped  = SFGetEngStsStopped(usSpeed);
    usDBmEngEngineIsRunning  = SFGetEngStsRunning(usSpeed);
    usDBmEngEngineIsIdling   = SFGetEngStsIdling(usSpeed);
    usDBmEngEngineIsRated    = SFGetEngStsRated(usSpeed);
    if (usDBmSwitchEmergStop != 0)
    {   usDBmSysEmergnCmdToStop = 1;
    }
    else if (usDBmEngEngineIsStopped != 0)
    {   usDBmSysEmergnCmdToStop = 0;
    }
    usDBmSysEmergnErrToStop  = CTLGetEmergnErrToStop();
    usDBmSysCommonErrToStop  = CTLGetCommonErrToStop();
    usDBmSysCommonErrToWarn  = CTLGetCommonErrToWarn();
    usDBmSysCommonCmdToSwOn  = CTLGetCommonCmdToSwOn();
    usDBmGensIsReadyToLoad   = CTLCheckGensReadyToLoad();
    usDBmMainVoltIsLost      = CTLCheckIsMainVoltLost();
    usDBmMainVoltReadyToSyn  = CTLCheckMainReadyToSync();
    usDBmSyncConditionMatch  = CTLCheckSyncCondition(usDBmMainVoltReadyToSyn);
    if (usDBpSysOperationMode == CTL_MODE_SIMPLE)         //单机模式
    {   usDBmSysCommonCmdToStop = CTLGetSingleCmdToStop(usDBmSysAutoOrManual);
        usDBmSysGensSwOnCndt    = CTLGetSingleGensSwOnCndt();
        usDBmSysMainSwOnCndt    = CTLGetSingleMainSwOnCndt();
        usPhase                 = CTLGetSingleSysPhase(usDBmSystemPhase);
        usDBmSystemPhase        = usPhase;
        usDBmSyncLoadCtrlMode   = CTLGetSinglePidMode(usPhase);
    }
    else if (usDBpSysOperationMode == CTL_MODE_AMF)
    {   usDBmSysCommonCmdToStop = CTLGetAmfCmdToStop(usDBmSysAutoOrManual);
        usDBmSysGensSwOnCndt    = CTLGetAmfGensSwOnCndt();
        usDBmSysMainSwOnCndt    = CTLGetAmfMainSwOnCndt();
        usPhase                 = CTLGetAmfSysPhase(usDBmSystemPhase);
        usDBmSystemPhase        = usPhase;
        usDBmSyncLoadCtrlMode   = CTLGetAmfPidMode(usPhase);
    }
    else if (usDBpSysOperationMode == CTL_MODE_ISLAND)
    {   usDBmSysCommonCmdToStop = CTLGetIslandCmdToStop(usDBmSysAutoOrManual);
        usDBmSysGensSwOnCndt    = CTLGetIslandGensSwOnCndt();
        usDBmSysMainSwOnCndt    = CTLGetIslandMainSwOnCndt();
        usPhase                 = CTLGetIslandSysPhase(usDBmSystemPhase);
        usDBmSystemPhase        = usPhase;
        usDBmSyncLoadCtrlMode   = CTLGetIslandPidMode(usPhase);
    }
    else if (usDBpSysOperationMode == CTL_MODE_FIXPOWER)
    {   usDBmSysCommonCmdToStop = CTLGetFixPwrCmdToStop(usDBmSysAutoOrManual);
        usDBmSysGensSwOnCndt    = CTLGetFixPwrGensSwOnCndt();
        usDBmSysMainSwOnCndt    = CTLGetFixPwrMainSwOnCndt();
        usPhase                 = CTLGetFixPwrSysPhase(usDBmSystemPhase);
        usDBmSystemPhase        = usPhase;
        usDBmSyncLoadCtrlMode   = CTLGetFixPwrPidMode(usPhase);
    }
    else if (usDBpSysOperationMode == CTL_MODE_PARALLEL)
    {   usDBmCanSchedIsAlone    = CAN2GetCanSchedIsAlone();
        usDBmCanSchedIsHighest  = CAN2GetCanSchedIsHighest();
        usDBmCanSchedToStop     = CAN2GetCanSchedToStop();
        usDBmCanSchedToSwitch   = CAN2GetCanSchedToSwitch();
        usDBmSysCommonCmdToStop = CTLGetParallCmdToStop(usDBmSysAutoOrManual);
        usDBmSysGensSwOnCndt    = CTLGetParallGensSwOnCndt();
        usDBmSysMainSwOnCndt    = CTLGetParallMainSwOnCndt();
        usPhase                 = CTLGetParallSysPhase(usDBmSystemPhase);
        usDBmSystemPhase        = usPhase;
        usDBmSyncLoadCtrlMode   = CTLGetParallPidMode(usPhase);
    }
    else
    {   usDBmSysCommonCmdToStop = 1;
        usDBmSysGensSwOnCndt    = 0;
        usDBmSysMainSwOnCndt    = 0;
        usPhase                 = 0;
        usDBmSystemPhase        = usPhase;
        usDBmSyncLoadCtrlMode   = 0;
    }
    usDBmSyncLoadGovCtrl     = CTLGetGovControl(usDBmSyncLoadCtrlMode);
    usDBmSyncLoadAvrCtrl     = CTLGetAvrControl(usDBmSyncLoadCtrlMode);
    usDBmEngHeaterOutput     = SFGetAirHeaterActive(usPhase);
    usDBmEngOilPumpOutput    = SFGetOilPumpActive(usPhase);
    usDBmEngStarterOutput    = SFGetStarterActive(usPhase,usDBmSysAutoOrManual);
    usDBmEngCoolFanOutput    = SFGetCoolantFanActive();
    usDBmEngFuelSupplyOutput = SFGetFuelSupplyActive(usPhase);
    usDBmEngSpeedRatedOutput = SFGetSpeedRatedActive(usPhase);
    usDBmSysMainSwCtrl       = CTLGetMainSwCtrl(usPhase);
    usDBmSysGensSwCtrl       = CTLGetGensSwCtrl(usPhase);
    usDBmSysMainSwOnOutput   = SFGetMainSwOnOutput(usDBmSysMainSwCtrl,usDBpTimeOfMainSwOutput);
    usDBmSysMainSwOffOutput  = SFGetMainSwOffOutput(usDBmSysMainSwCtrl,usDBpTimeOfMainSwOutput);
    usDBmSysGensSwOnOutput   = SFGetGensSwOnOutput(usDBmSysGensSwCtrl,usDBpTimeOfGensSwOutput);
    usDBmSysGensSwOffOutput  = SFGetGensSwOffOutput(usDBmSysGensSwCtrl,usDBpTimeOfGensSwOutput);
}
#endif

/* ******************************************************************** */
/*                         CTLGetSysAutoOrManual()                      */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetSysAutoOrManual (void)
{   if (ERR_ES7_GET_BIT(ERR_ES7_KEY_TO_AUTO) != 0)
    {   return 1;
    }
    return 0;
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
    if (ERR_ES3_GET_BIT(ERR_ES3_EMERG_MSK) != 0)
    {   return 2;
    }
    if (ERR_ES5_GET_BIT(ERR_ES5_EMERG_MSK) != 0)
    {   return 3;
    }
    if (ERR_ES6_GET_BIT(ERR_ES6_EMERG_MSK) != 0)
    {   return 4;
    }
    if (ERR_ES2_GET_BIT(ERR_ES2_EMERG_MSK) != 0)
    {   return 5;
    }
    if (ERR_ES7_GET_BIT(ERR_ES7_EMERG_MSK) != 0)
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
    if (ERR_ES3_GET_BIT(ERR_ES3_STOP_MSK) != 0)
    {   return 2;
    }
    if (ERR_ES5_GET_BIT(ERR_ES5_STOP_MSK) != 0)
    {   return 3;
    }
    if (ERR_ES6_GET_BIT(ERR_ES6_STOP_MSK) != 0)
    {   return 4;
    }
    if (ERR_ES2_GET_BIT(ERR_ES2_STOP_MSK) != 0)
    {   return 5;
    }
    if (ERR_ES7_GET_BIT(ERR_ES7_STOP_MSK) != 0)
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
{   if (ERR_ES1_GET_BIT(ERR_ES1_WARN_MSK) != 0)
    {   return 1;
    }
    if (ERR_ES3_GET_BIT(ERR_ES3_WARN_MSK) != 0)
    {   return 2;
    }
    if (ERR_ES5_GET_BIT(ERR_ES5_WARN_MSK) != 0)
    {   return 3;
    }
    if (ERR_ES6_GET_BIT(ERR_ES6_WARN_MSK) != 0)
    {   return 4;
    }
    if (ERR_ES2_GET_BIT(ERR_ES2_WARN_MSK) != 0)
    {   return 5;
    }
    if (ERR_ES7_GET_BIT(ERR_ES7_WARN_MSK) != 0)
    {   return 6;
    }
    if (ERR_ES7_GET_BIT(ERR_ES7_WARN_MSK) != 0)
    {   return 7;
    }
    if (ERR_ES8_GET_BIT(ERR_ES8_WARN_MSK) != 0)
    {   return 8;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                        CTLGetCommonCmdToSwOn()                       */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetCommonCmdToSwOn (void)
{   if (ERR_ES7_GET_BIT(ERR_ES7_KEY_TO_SWON) != 0)
    {   return 1;
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
/*                           CTLGetMainSwCtrl()                         */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetMainSwCtrl (INT16U usPhase)
{   static INT16U usSwCtrl = 1;
    if ((usPhase == CTL_PHASE_MAIN_SW_ON) ||
        (usPhase == CTL_PHASE_MAIN_SW_ON2) )
    {   usSwCtrl = 1;
    }
    else if ((usPhase == CTL_PHASE_MAIN_SW_OFF) ||
             (usPhase == CTL_PHASE_MAIN_SW_OFF2) )
    {   usSwCtrl = 0;
    }
    return usSwCtrl;
}
#endif

/* ******************************************************************** */
/*                           CTLGetGensSwCtrl()                         */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetGensSwCtrl (INT16U usPhase)
{   static INT16U usSwCtrl = 0;
    if (usPhase == CTL_PHASE_GENS_SW_ON)
    {   usSwCtrl = 1;
    }
    else if ((usPhase == CTL_PHASE_GENS_SW_OFF) ||
             (usPhase == CTL_PHASE_EMERGENCY) )
    {   usSwCtrl = 0;
    }
    return usSwCtrl;
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
        usGovCtrl = SFGetErrorPidCtrl((usDBpSyncFreqDiffSetp-ssDBmSyncFreqDiffer),
                                      &CTLGovTuner);
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
        usAvrCtrl = SFGetErrorPidCtrl((0-ssDBmSyncVoltDiffer), &CTLAvrTuner);
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
    uiLoadActResi = uiTemp % (CTL_LOAD_RAMP_FREQ * 1024u);
    return (INT16U)(uiTemp / (CTL_LOAD_RAMP_FREQ * 1024u));
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
    {   uiRamp = (INT32U)usAll * 1024u;
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
    {   uiRamp = (INT32U)usAll * 1024u;
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
    uiLoadRctResi = uiTemp % (CTL_LOAD_RAMP_FREQ * 1024u);
    return (INT16U)(uiTemp / (CTL_LOAD_RAMP_FREQ * 1024u));
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
    {   uiRamp = (INT32U)usAll * 1024u;
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
    {   uiRamp = (INT32U)usAll * 1024u;
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
/*                       CTLGetSingleCmdToStop()                        */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetSingleCmdToStop (INT16U usAutoOrHand)
{   if (ERR_ES7_GET_BIT(ERR_ES7_KEY_TO_STOP) != 0)
    {   return 1;
    }
    else if (usAutoOrHand == 0)
    {   return 0;
    }
    else if (ERR_ES7_GET_BIT(ERR_ES7_SWT_TO_STOP) != 0)
    {   return 1;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                         CTLGetAmfCmdToStop()                         */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetAmfCmdToStop (INT16U usAutoOrHand)
{   if (ERR_ES7_GET_BIT(ERR_ES7_KEY_TO_STOP) != 0)
    {   return 1;
    }
    else if (usAutoOrHand == 0)
    {   return 0;
    }
    else if ((ERR_ES7_GET_BIT(ERR_ES7_SWT_TO_STOP) != 0) ||
             (usDBmMainVoltIsNormal != 0) )
    {   return 1;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CTLGetIslandCmdToStop()                        */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetIslandCmdToStop (INT16U usAutoOrHand)
{   if (ERR_ES7_GET_BIT(ERR_ES7_KEY_TO_STOP) != 0)
    {   return 1;
    }
    else if (usAutoOrHand == 0)
    {   return 0;
    }
    else if (ERR_ES7_GET_BIT(ERR_ES7_SWT_TO_STOP) != 0)
    {   return 1;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CTLGetFixPwrCmdToStop()                        */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetFixPwrCmdToStop (INT16U usAutoOrHand)
{   if (ERR_ES7_GET_BIT(ERR_ES7_KEY_TO_STOP) != 0)
    {   return 1;
    }
    else if (usAutoOrHand == 0)
    {   return 0;
    }
    else if (ERR_ES7_GET_BIT(ERR_ES7_SWT_TO_STOP) != 0)
    {   return 1;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CTLGetParallCmdToStop()                        */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)
INT16U CTLGetParallCmdToStop (INT16U usAutoOrHand)
{   if (ERR_ES7_GET_BIT(ERR_ES7_KEY_TO_STOP) != 0)
    {   return 1;
    }
    else if (usAutoOrHand == 0)
    {   return 0;
    }
    else if ((ERR_ES7_GET_BIT(ERR_ES7_SWT_TO_STOP) != 0) ||
             (usDBmCanSchedToStop != 0) )
    {   return 1;
    }
    return 0;
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
{   if ((usDBmGensIsReadyToLoad  != 0)  &&
        (usDBmCanSchedToSwitch   != 0)  &&
       ((usDBmSyncConditionMatch != 0)  ||
        (usDBmMainVoltIsLost     != 0)) )
    {   return 1;
    }
    return 0;
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
                              usDBmLoadActPwrSetp, usDBmLoadActPwrSelect);
        usDBmLoadRctPwrSetp = CTLGetLoadSetpRampRct(CTL_LOAD_OFF_RCT_SETP,
                              usDBmLoadRctPwrSetp, usDBmLoadRctPwrSelect);
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
    {   usDBmLoadActPwrSelect = usDBpLoadActPowerSetp;
        usDBmLoadActPwrSetp   = CTLGetLoadSetpRampAct(usDBmLoadActPwrSelect,
                                usDBmLoadActPwrSetp, usDBmLoadActPwrSelect);
        usDBmLoadRctPwrSelect = usDBpLoadReactPowerSetp;
        usDBmLoadRctPwrSetp   = CTLGetLoadSetpRampRct(usDBmLoadRctPwrSelect,
                                usDBmLoadRctPwrSetp, usDBmLoadRctPwrSelect);
        return CTL_PID_MODE_LOAD;
    }
    else if (usPhase == CTL_PHASE_LOADING_DOWN)
    {   usDBmLoadActPwrSetp   = CTLGetLoadSetpRampAct(CTL_LOAD_OFF_ACT_SETP,
                                usDBmLoadActPwrSetp, usDBmLoadActPwrSelect);
        usDBmLoadRctPwrSetp   = CTLGetLoadSetpRampRct(CTL_LOAD_OFF_RCT_SETP,
                                usDBmLoadRctPwrSetp, usDBmLoadRctPwrSelect);
        return CTL_PID_MODE_LOAD;
    }
    else if ((usPhase == CTL_PHASE_FIXPWR_UP) ||
             (usPhase == CTL_PHASE_FIXPWR_DOWN) )
    {   usDBmLoadActPwrSelect = usDBpLoadActPowerSetp;
        usDBmLoadActPwrSetp   = usDBpLoadActPowerSetp;
        usDBmLoadRctPwrSelect = usDBpLoadReactPowerSetp;
        usDBmLoadRctPwrSetp   = usDBpLoadReactPowerSetp;
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
    {   usDBmLoadActPwrSelect = usDBpLoadActPowerSetp;
        usDBmLoadActPwrSetp   = CTLGetLoadSetpRampAct(usDBmLoadActPwrSelect,
                                usDBmLoadActPwrSetp, usDBmLoadActPwrSelect);
        usDBmLoadRctPwrSelect = CTL_REACT_PWR_SETP(usDBpLoadReactPowerSetp,
                                                   usDBpLoadPowerFactorSetp);
        usDBmLoadRctPwrSetp   = CTLGetLoadSetpRampRct(usDBmLoadRctPwrSelect,
                                usDBmLoadRctPwrSetp, usDBmLoadRctPwrSelect);
        return CTL_PID_MODE_LOAD;
    }
    else if (usPhase == CTL_PHASE_LOADING_DOWN)
    {   usDBmLoadActPwrSetp   = CTLGetLoadSetpRampAct(CTL_LOAD_OFF_ACT_SETP,
                                usDBmLoadActPwrSetp, usDBmLoadActPwrSelect);
        usDBmLoadRctPwrSetp   = CTLGetLoadSetpRampRct(CTL_LOAD_OFF_RCT_SETP,
                                usDBmLoadRctPwrSetp, usDBmLoadRctPwrSelect);
        return CTL_PID_MODE_LOAD;
    }
    else if (usPhase == CTL_PHASE_WORKING)
    {   usDBmLoadActPwrSelect = usDBpLoadActPowerSetp;
        usDBmLoadActPwrSetp   = usDBpLoadActPowerSetp;
        usDBmLoadRctPwrSelect = CTL_REACT_PWR_SETP(usDBpLoadReactPowerSetp,
                                                   usDBpLoadPowerFactorSetp);
        usDBmLoadRctPwrSetp   = usDBmLoadRctPwrSelect;
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
                                usDBmLoadActPwrSetp, usDBmLoadActPwrSelect);
        usDBmLoadRctPwrSelect = usDBmCanSchedRctPowerSetp;
        usDBmLoadRctPwrSetp   = CTLGetLoadSetpRampRct(usDBmLoadRctPwrSelect,
                                usDBmLoadRctPwrSetp, usDBmLoadRctPwrSelect);
        return CTL_PID_MODE_LOAD;
    }
    else if (usPhase == CTL_PHASE_LOADING_DOWN)
    {   usDBmLoadActPwrSetp   = CTLGetLoadSetpRampAct(CTL_LOAD_OFF_ACT_SETP,
                                usDBmLoadActPwrSetp, usDBmLoadActPwrSelect);
        usDBmLoadRctPwrSetp   = CTLGetLoadSetpRampRct(CTL_LOAD_OFF_RCT_SETP,
                                usDBmLoadRctPwrSetp, usDBmLoadRctPwrSelect);
        return CTL_PID_MODE_LOAD;
    }
    else if (usPhase == CTL_PHASE_WORKING)
    {   if ((usDBmCanSchedIsAlone != 0) || (usDBmCanSchedIsHighest != 0))
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
    {   CTL_STS_CLR_BIT(CTL_STS_MSK_ENG_WARM | CTL_STS_MSK_GENS_SW);
        CTL_STS_SET_BIT(CTL_STS_MSK_MAIN_SW);
        if (usDBmEngEngineIsStopped != 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_STOPPED;
        }   else
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_STOPPING;
        }
    }
    else if (usSingleStep == CTL_PHASE_STOPPED)
    {   CTL_STS_CLR_BIT(CTL_STS_MSK_ENG_WARM);
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
    }
    else if ((usDBmSysEmergnErrToStop != 0) ||
             (usDBmSysEmergnCmdToStop != 0) )
    {   usSingleTime = usTimNow;
        usSingleStep = CTL_PHASE_EMERGENCY;
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
        else if (usDBmEngEngineIsIdling != 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_IDLING_UP;
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
        else if (usDBmEngEngineIsIdling != 0)
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
        else if (CTL_STS_GET_BIT(CTL_STS_MSK_ENG_WARM) != 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_WAIT_KEY_SW;
        }
        else if (usDelay >= usDBpTimeRatedReadyDly)
        {   CTL_STS_SET_BIT(CTL_STS_MSK_ENG_WARM);
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
    else if (usSingleStep == CTL_PHASE_MAIN_SW_ON)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_MAIN_SW) != 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_RATED_DOWN;
        }
        else if (usDelay >= usDBpTimeOfMainSwitchOn)
        {   CTL_STS_SET_BIT(CTL_STS_MSK_MAIN_SW);
            usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_RATED_DOWN;
        }
    }
    else if (usSingleStep == CTL_PHASE_MAIN_SW_OFF)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_MAIN_SW) == 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_GENS_SW_ON;
        }
        else if (usDelay >= usDBpTimeOfMainSwitchOff)
        {   CTL_STS_CLR_BIT(CTL_STS_MSK_MAIN_SW);
            usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_GENS_SW_ON;
        }
    }
    else if (usSingleStep == CTL_PHASE_GENS_SW_ON)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_GENS_SW) != 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_WORKING;
        }
        else if (usDelay >= usDBpTimeOfGensSwitchOn)
        {   CTL_STS_SET_BIT(CTL_STS_MSK_GENS_SW);
            usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_WORKING;
        }
    }
    else if (usSingleStep == CTL_PHASE_GENS_SW_OFF)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_GENS_SW) == 0)
        {   usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_MAIN_SW_ON;
        }
        else if (usDelay >= usDBpTimeOfGensSwitchOff)
        {   CTL_STS_CLR_BIT(CTL_STS_MSK_GENS_SW);
            usSingleTime = usTimNow;
            usSingleStep = CTL_PHASE_MAIN_SW_ON;
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
    {   CTL_STS_SET_BIT(CTL_STS_ERR_LOGIC);
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
    {   CTL_STS_CLR_BIT(CTL_STS_MSK_ENG_WARM | CTL_STS_MSK_GENS_SW);
        CTL_STS_SET_BIT(CTL_STS_MSK_MAIN_SW);
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
    {   CTL_STS_CLR_BIT(CTL_STS_MSK_ENG_WARM);
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
    }
    /* **************** CTL_PHASE_EMERGENCY: Emergency **************** */
    else if ((usDBmSysEmergnErrToStop != 0) ||
             (usDBmSysEmergnCmdToStop != 0) )
    {   usAmfTime = usTimNow;
        usAmfStep = CTL_PHASE_EMERGENCY;
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
    /* **************** CTL_PHASE_MAIN_SW_OFF: Grid Sw off1 ********** */
    else if (usAmfStep == CTL_PHASE_MAIN_SW_OFF)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_MAIN_SW) == 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_STARTING;
        }
        else if (usDelay >= usDBpTimeOfMainSwitchOff)
        {   CTL_STS_CLR_BIT(CTL_STS_MSK_MAIN_SW);
            usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_STARTING;
        }
    }
    /* **************** CTL_PHASE_STARTING: Starting ****************** */
    else if (usAmfStep == CTL_PHASE_STARTING)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) )
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_STOPPING;
        }
        else if (usDBmEngEngineIsIdling != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_IDLING_UP;
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
        else if (usDBmEngEngineIsIdling != 0)
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
        else if (CTL_STS_GET_BIT(CTL_STS_MSK_ENG_WARM) != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_WAIT_KEY_SW;
        }
        else if (usDelay >= usDBpTimeRatedReadyDly)
        {   CTL_STS_SET_BIT(CTL_STS_MSK_ENG_WARM);
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
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_MAIN_SW) == 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_GENS_SW_ON;
        }
        else if (usDelay >= usDBpTimeOfMainSwitchOff)
        {   CTL_STS_CLR_BIT(CTL_STS_MSK_MAIN_SW);
            usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_GENS_SW_ON;
        }
    }
    /* **************** CTL_PHASE_GENS_SW_ON: Gens_Sw_on ************** */
    else if (usAmfStep == CTL_PHASE_GENS_SW_ON)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_GENS_SW) != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_WORKING;
        }
        else if (usDelay >= usDBpTimeOfGensSwitchOn)
        {   CTL_STS_SET_BIT(CTL_STS_MSK_GENS_SW);
            usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_WORKING;
        }
    }
    /* **************** CTL_PHASE_GENS_SW_OFF: Gens_Sw_off ************ */
    else if (usAmfStep == CTL_PHASE_GENS_SW_OFF)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_GENS_SW) == 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_MAIN_SW_ON2;
        }
        else if (usDelay >= usDBpTimeOfGensSwitchOff)
        {   CTL_STS_CLR_BIT(CTL_STS_MSK_GENS_SW);
            usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_MAIN_SW_ON2;
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
        else if (usDBmSysMainSwOnCndt != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_MAIN_SW_ON;
        }
    }
    /* **************** CTL_PHASE_MAIN_SW_ON: Grid_Sw_on1 ************ */
    else if (usAmfStep == CTL_PHASE_MAIN_SW_ON)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_MAIN_SW) != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_LOADING_DOWN;
        }
        else if (usDelay >= usDBpTimeOfMainSwitchOn)
        {   CTL_STS_SET_BIT(CTL_STS_MSK_MAIN_SW);
            usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_LOADING_DOWN;
        }
    }
    /* **************** CTL_PHASE_MAIN_SW_ON2: Grid_Sw_on2 ************ */
    else if (usAmfStep == CTL_PHASE_MAIN_SW_ON2)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_MAIN_SW) != 0)
        {   usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_RATED_DOWN;
        }
        else if (usDelay >= usDBpTimeOfMainSwitchOn)
        {   CTL_STS_SET_BIT(CTL_STS_MSK_MAIN_SW);
            usAmfTime = usTimNow;
            usAmfStep = CTL_PHASE_RATED_DOWN;
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
    {   CTL_STS_SET_BIT(CTL_STS_ERR_LOGIC);
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
    {   CTL_STS_CLR_BIT(CTL_STS_MSK_ENG_WARM | CTL_STS_MSK_GENS_SW);
        CTL_STS_SET_BIT(CTL_STS_MSK_MAIN_SW);
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
    {   CTL_STS_CLR_BIT(CTL_STS_MSK_ENG_WARM);
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
    }
    /* **************** CTL_PHASE_EMERGENCY: Emergency **************** */
    else if ((usDBmSysEmergnErrToStop != 0) ||
             (usDBmSysEmergnCmdToStop != 0) )
    {   usFixPwrTime = usTimNow;
        usFixPwrStep = CTL_PHASE_EMERGENCY;
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
        else if (usDBmEngEngineIsIdling != 0)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_IDLING_UP;
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
        else if (usDBmEngEngineIsIdling != 0)
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
        else if (CTL_STS_GET_BIT(CTL_STS_MSK_ENG_WARM) != 0)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_WAIT_KEY_SW;
        }
        else if (usDelay >= usDBpTimeRatedReadyDly)
        {   CTL_STS_SET_BIT(CTL_STS_MSK_ENG_WARM);
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
        else if (usDBmSysGensSwOnCndt != 0)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_GENS_SW_ON;
        }
    }
    /* **************** CTL_PHASE_GENS_SW_ON: Gens_Sw_on ************** */
    else if (usFixPwrStep == CTL_PHASE_GENS_SW_ON)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_GENS_SW) != 0)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_LOADING_UP;
        }
        else if (usDelay >= usDBpTimeOfGensSwitchOn)
        {   CTL_STS_SET_BIT(CTL_STS_MSK_GENS_SW);
            usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_LOADING_UP;
        }
    }
    /* **************** CTL_PHASE_GENS_SW_OFF: Gens_Sw_off ************ */
    else if (usFixPwrStep == CTL_PHASE_GENS_SW_OFF)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_GENS_SW) == 0)
        {   usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_RATED_DOWN;
        }
        else if (usDelay >= usDBpTimeOfGensSwitchOff)
        {   CTL_STS_CLR_BIT(CTL_STS_MSK_GENS_SW);
            usFixPwrTime = usTimNow;
            usFixPwrStep = CTL_PHASE_RATED_DOWN;
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
    {   CTL_STS_SET_BIT(CTL_STS_ERR_LOGIC);
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
    {   CTL_STS_CLR_BIT(CTL_STS_MSK_ENG_WARM | CTL_STS_MSK_GENS_SW);
        CTL_STS_SET_BIT(CTL_STS_MSK_MAIN_SW);
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
    {   CTL_STS_CLR_BIT(CTL_STS_MSK_ENG_WARM);
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
    }
    /* **************** CTL_PHASE_EMERGENCY: Emergency **************** */
    else if ((usDBmSysEmergnErrToStop != 0) ||
             (usDBmSysEmergnCmdToStop != 0) )
    {   usIslandTime = usTimNow;
        usIslandStep = CTL_PHASE_EMERGENCY;
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
        else if (usDBmEngEngineIsIdling != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_IDLING_UP;
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
        else if (usDBmEngEngineIsIdling != 0)
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
        else if (CTL_STS_GET_BIT(CTL_STS_MSK_ENG_WARM) != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_WAIT_KEY_SW;
        }
        else if (usDelay >= usDBpTimeRatedReadyDly)
        {   CTL_STS_SET_BIT(CTL_STS_MSK_ENG_WARM);
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
        else if (usDBmSysGensSwOnCndt != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_GENS_SW_ON;
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
        else if (usDBmSysMainSwOnCndt != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_MAIN_SW_ON;
        }
    }
    /* **************** CTL_PHASE_GENS_SW_ON: Gens_Sw_on ************** */
    else if (usIslandStep == CTL_PHASE_GENS_SW_ON)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_GENS_SW) != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_LOADING_UP;
        }
        else if (usDelay >= usDBpTimeOfGensSwitchOn)
        {   CTL_STS_SET_BIT(CTL_STS_MSK_GENS_SW);
            usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_LOADING_UP;
        }
    }
    /* **************** CTL_PHASE_GENS_SW_OFF: Gens_Sw_off ************ */
    else if (usIslandStep == CTL_PHASE_GENS_SW_OFF)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_GENS_SW) == 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_MAIN_SW_ON2;
        }
        else if (usDelay >= usDBpTimeOfGensSwitchOff)
        {   CTL_STS_CLR_BIT(CTL_STS_MSK_GENS_SW);
            usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_MAIN_SW_ON2;
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
    /* **************** CTL_PHASE_MAIN_SW_ON: Main_Sw_on1 ************ */
    else if (usIslandStep == CTL_PHASE_MAIN_SW_ON)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_MAIN_SW) != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_FIXPWR_DOWN;
        }
        else if (usDelay >= usDBpTimeOfMainSwitchOn)
        {   CTL_STS_SET_BIT(CTL_STS_MSK_MAIN_SW);
            usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_FIXPWR_DOWN;
        }
    }
    /* **************** CTL_PHASE_MAIN_SW_ON2: Main_Sw_on2 ************ */
    else if (usIslandStep == CTL_PHASE_MAIN_SW_ON2)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_MAIN_SW) != 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_RATED_DOWN;
        }
        else if (usDelay >= usDBpTimeOfMainSwitchOn)
        {   CTL_STS_SET_BIT(CTL_STS_MSK_MAIN_SW);
            usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_RATED_DOWN;
        }
    }
    /* **************** CTL_PHASE_MAIN_SW_OFF: Main_Sw_off ************ */
    else if (usIslandStep == CTL_PHASE_MAIN_SW_OFF)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_MAIN_SW) == 0)
        {   usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_WORKING;
        }
        else if (usDelay >= usDBpTimeOfMainSwitchOff)
        {   CTL_STS_CLR_BIT(CTL_STS_MSK_MAIN_SW);
            usIslandTime = usTimNow;
            usIslandStep = CTL_PHASE_WORKING;
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
        }
    }
    /* ******************** Others: Logic Fault *********************** */
    else
    {   CTL_STS_SET_BIT(CTL_STS_ERR_LOGIC);
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
    {   CTL_STS_CLR_BIT(CTL_STS_MSK_ENG_WARM | CTL_STS_MSK_GENS_SW);
        CTL_STS_SET_BIT(CTL_STS_MSK_MAIN_SW);
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
    {   CTL_STS_CLR_BIT(CTL_STS_MSK_ENG_WARM);
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
    {   if (usDBmEngEngineIsStopped != 0)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_STOPPED;
        }
    }
    /* **************** CTL_PHASE_EMERGENCY: Emergency **************** */
    else if ((usDBmSysEmergnErrToStop != 0) ||
             (usDBmSysEmergnCmdToStop != 0) )
    {   usParallTime = usTimNow;
        usParallStep = CTL_PHASE_EMERGENCY;
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
        else if (usDBmEngEngineIsIdling != 0)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_IDLING_UP;
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
        else if (usDBmEngEngineIsIdling != 0)
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
        else if (CTL_STS_GET_BIT(CTL_STS_MSK_ENG_WARM) != 0)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_WAIT_KEY_SW;
        }
        else if (usDelay >= usDBpTimeRatedReadyDly)
        {   CTL_STS_SET_BIT(CTL_STS_MSK_ENG_WARM);
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
        }
    }
    /* **************** CTL_PHASE_SYNCHRING: Synchring **************** */
    else if (usParallStep == CTL_PHASE_SYNCHRING)
    {   if ((usDBmSysCommonErrToStop != 0) ||
            (usDBmSysCommonCmdToStop != 0) ||
            (usDBmSysCommonCmdToSwOn == 0) )
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_RATED_DOWN;
        }
        else if (usDBmSysGensSwOnCndt != 0)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_GENS_SW_ON;
        }
    }
    /* **************** CTL_PHASE_GENS_SW_ON: Gens_Sw_on ************** */
    else if (usParallStep == CTL_PHASE_GENS_SW_ON)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_GENS_SW) != 0)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_LOADING_UP;
        }
        else if (usDelay >= usDBpTimeOfGensSwitchOn)
        {   CTL_STS_SET_BIT(CTL_STS_MSK_GENS_SW);
            usParallTime = usTimNow;
            usParallStep = CTL_PHASE_LOADING_UP;
        }
    }
    /* **************** CTL_PHASE_GENS_SW_OFF: Gens_Sw_off ************ */
    else if (usParallStep == CTL_PHASE_GENS_SW_OFF)
    {   if (CTL_STS_GET_BIT(CTL_STS_MSK_GENS_SW) == 0)
        {   usParallTime = usTimNow;
            usParallStep = CTL_PHASE_RATED_DOWN;
        }
        else if (usDelay >= usDBpTimeOfGensSwitchOff)
        {   CTL_STS_CLR_BIT(CTL_STS_MSK_GENS_SW);
            usParallTime = usTimNow;
            usParallStep = CTL_PHASE_RATED_DOWN;
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
                 (usDBmCanSchedIsAlone != 0) )
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
                 (usDBmCanSchedIsAlone != 0) )
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
    {   CTL_STS_SET_BIT(CTL_STS_ERR_LOGIC);
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