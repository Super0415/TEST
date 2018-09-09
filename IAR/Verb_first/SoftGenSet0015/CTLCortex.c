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
void CTLInit (void)
{   usCTLTimer = 0;
    usCTLStatus = 0;
}

/* ******************************************************************** */
/*                            CTLSysMonitor()                           */
/* ******************************************************************** */
void CTLSysMonitor (void)
{   if (usDBmKeyErrorReset != 0)
    {   (void)SFResetAllErrors();
    }
    (void)SFEngineSpeedMonitor();
    (void)SFEngineTempMonitor();
    (void)SFEnginePressMonitor();
    (void)SFEngineLevelMonitor();
    (void)SFEngineFilterMonitor();
    (void)SFEngineVoltageMonitor();
    (void)SFEngineCurrentMonitor();
    (void)SFEngineRackPosiMonitor();
    (void)SFMainVoltageMonitor();
    (void)SFGensVoltageMonitor();
    (void)SFGensCurrentMonitor();
    (void)SFGensPowerMonitor();
    (void)SFVoltageDifferMonitor();
    (void)SFGensBreakerTripMonitor();
}

/* ******************************************************************** */
/*                         CTLSysController()                           */
/* ******************************************************************** */
void CTLSysController (void)
{   usDBmEngineStopped     = CTLGetEngineStsStopped();
    usDBmEngineRunning     = CTLGetEngineStsRunning();
    usDBmEmergnErrorToStop = CTLGetErrorEmergnStop();
    usDBmCommonErrorToStop = CTLGetErrorCommonStop();
    usDBmCommonErrorToWarn = CTLGetErrorCommonWarn();
    usDBmEngineStopActive  = CTLGetEngineStopActive();
    usDBmEngineStartActive = CTLGetEngineStartActive();
    usDBmBreakerOnAllowed  = CTLGetSwitchOnAllowed();
    usDBmAutoModeActive    = CTLGetAutoModeActive();
    usDBmSystemPhase       = CTLGetSystemPhase();
    usDBmAirHeatActive     = CTLGetAirHeatActive();
    usDBmOilPumpActive     = CTLGetOilPumpActive();
    usDBmStarterActive     = CTLGetStarterActive();
    usDBmFuelSupplyActive  = CTLGetFuelSupplyActive();
    usDBmCoolantFanActive  = CTLGetCoolantFanActive(usDBpFanRefAssign);
    usDBmSpeedRatedActive  = CTLGetSpeedRatedActive();
    usDBmMainBreakerOn     = CTLGetMainSwitchOn();
    usDBmGensBreakerOn     = CTLGetGensSwitchOn();
    ssDBmSpeedTuningCtrl   = CTLGetSpeedTuningControl();
    ssDBmAvrTuningCtrl     = CTLGetAvrTuningControl();
}

/* ******************************************************************** */
/*                       CTLGetEngineStsStopped()                       */
/* ******************************************************************** */
INT16U CTLGetEngineStsStopped (void)
{   static INT08U ucCount = 0;
    if (usDBmSpeed > usDBpStartSpeed1)
    {   ucCount = 0;
        return 0;
    }
    else if (ucCount < 3)
    {   ucCount++;
        return 0;
    }
    return 1;
}

/* ******************************************************************** */
/*                       CTLGetEngineStsRunning()                       */
/* ******************************************************************** */
INT16U CTLGetEngineStsRunning (void)
{   static INT08U ucCount = 0;
    if (usDBmSpeed <= usDBpStartSpeed2)
    {   ucCount = 0;
        return 0;
    }
    else if (ucCount < 3)
    {   ucCount++;
        return 0;
    }
    return 1;
}

/* ******************************************************************** */
/*                        CTLGetEngineStsIdling()                       */
/* ******************************************************************** */
INT16U CTLGetEngineStsIdling (void)
{   static INT08U ucCount = 0;
    if((usDBmSpeed < usDBpSpeedIdleMin) || (usDBmSpeed > usDBpSpeedIdleMax))
    {   ucCount = 0;
        return 0;
    }
    else if (ucCount < 3)
    {   ucCount++;
        return 0;
    }
    return 1;
}

/* ******************************************************************** */
/*                        CTLGetEngineStsRated()                        */
/* ******************************************************************** */
INT16U CTLGetEngineStsRated (void)
{   static INT08U ucCount = 0;
    if (usDBmSpeed < usDBpSpeedRatedMin)
    {   ucCount = 0;
        return 0;
    }
    else if (ucCount < 3)
    {   ucCount++;
        return 0;
    }
    return 1;
}

/* ******************************************************************** */
/*                       CTLGetErrorEmergnStop()                        */
/* ******************************************************************** */
INT16U CTLGetErrorEmergnStop (void)
{   if (SF_ERR1_GET_BIT(SF_ERR1_EMERG_MSK) != 0)
    {   return SF_ERR1_GET_BIT(SF_ERR1_EMERG_MSK);
    }
    if (SF_ERR2_GET_BIT(SF_ERR2_EMERG_MSK) != 0)
    {   return SF_ERR2_GET_BIT(SF_ERR2_EMERG_MSK);
    }
    if (SF_ERR3_GET_BIT(SF_ERR3_EMERG_MSK) != 0)
    {   return SF_ERR3_GET_BIT(SF_ERR3_EMERG_MSK);
    }
    if (SF_ERR4_GET_BIT(SF_ERR4_EMERG_MSK) != 0)
    {   return SF_ERR4_GET_BIT(SF_ERR4_EMERG_MSK);
    }
    if (SF_ERR5_GET_BIT(SF_ERR5_EMERG_MSK) != 0)
    {   return SF_ERR5_GET_BIT(SF_ERR5_EMERG_MSK);
    }
    return SF_ERR6_GET_BIT(SF_ERR6_EMERG_MSK);
}

/* ******************************************************************** */
/*                       CTLGetErrorCommonStop()                        */
/* ******************************************************************** */
INT16U CTLGetErrorCommonStop (void)
{   if (SF_ERR1_GET_BIT(SF_ERR1_STOP_MSK) != 0)
    {   return SF_ERR1_GET_BIT(SF_ERR1_STOP_MSK);
    }
    if (SF_ERR2_GET_BIT(SF_ERR2_STOP_MSK) != 0)
    {   return SF_ERR2_GET_BIT(SF_ERR2_STOP_MSK);
    }
    if (SF_ERR3_GET_BIT(SF_ERR3_STOP_MSK) != 0)
    {   return SF_ERR3_GET_BIT(SF_ERR3_STOP_MSK);
    }
    if (SF_ERR4_GET_BIT(SF_ERR4_STOP_MSK) != 0)
    {   return SF_ERR4_GET_BIT(SF_ERR4_STOP_MSK);
    }
    if (SF_ERR5_GET_BIT(SF_ERR5_STOP_MSK) != 0)
    {   return SF_ERR5_GET_BIT(SF_ERR5_STOP_MSK);
    }
    return SF_ERR6_GET_BIT(SF_ERR6_STOP_MSK);
}

/* ******************************************************************** */
/*                       CTLGetErrorCommonWarn()                        */
/* ******************************************************************** */
INT16U CTLGetErrorCommonWarn (void)
{   if (SF_ERR1_GET_BIT(SF_ERR1_WARN_MSK) != 0)
    {   return SF_ERR1_GET_BIT(SF_ERR1_WARN_MSK);
    }
    if (SF_ERR2_GET_BIT(SF_ERR2_WARN_MSK) != 0)
    {   return SF_ERR2_GET_BIT(SF_ERR2_WARN_MSK);
    }
    if (SF_ERR3_GET_BIT(SF_ERR3_WARN_MSK) != 0)
    {   return SF_ERR3_GET_BIT(SF_ERR3_WARN_MSK);
    }
    if (SF_ERR4_GET_BIT(SF_ERR4_WARN_MSK) != 0)
    {   return SF_ERR4_GET_BIT(SF_ERR4_WARN_MSK);
    }
    if (SF_ERR5_GET_BIT(SF_ERR5_WARN_MSK) != 0)
    {   return SF_ERR5_GET_BIT(SF_ERR5_WARN_MSK);
    }
    return SF_ERR6_GET_BIT(SF_ERR6_WARN_MSK);
}

/* ******************************************************************** */
/*                        CTLGetEngineStopActive()                      */
/* ******************************************************************** */
INT16U CTLGetEngineStopActive (void)
{   static INT16U usStopEnable = 0;
    if((usDBmKeyEngineStop != 0) ||
       (usDBmSwitchEngineStop != 0) ||
       (usDBmCommonErrorToStop != 0) ||
       (usDBmEmergnErrorToStop != 0) )
    {   usStopEnable = 1;
    }
    /* *********************** If Stopped, Clear ********************** */
    else if (usDBmEngineStopped != 0)
    {   usStopEnable = 0;
    }
    /* **************** Mode = 0,1: Manual And Remote ***************** */
    else if ((usDBpOperationMode == 0) || (usDBpOperationMode == 1))
    {
    }
    /* **************** Mode = 2,3: Manual And Main Voltage Low ******* */
    else if ((usDBpOperationMode == 2) || (usDBpOperationMode == 3))
    {   if (SF_ERR3_GET_BIT(SF_ERR3_MAIN_ERR_MSK) == 0)
        {   usStopEnable = 1;
        }   else
        {   usStopEnable = 0;
        }
    }
    /* **************** Mode = 4,5: Manual And Can+Differ ************* */
    else if ((usDBpOperationMode == 4) || (usDBpOperationMode == 5))
    {   usStopEnable = CTLCheckCanComdToStop();
    }
    return usStopEnable;
}

/* ******************************************************************** */
/*                         CTLGetEngineStartActive()                    */
/* ******************************************************************** */
INT16U CTLGetEngineStartActive (void)
{   static INT16U usStartEnable = 0;
    /* ****************** Stopped or Error Condition ****************** */
    if((usDBmKeyEngineStop != 0) || 
       (usDBmSwitchEngineStop != 0) ||
       (usDBmCommonErrorToStop != 0) ||
       (usDBmEmergnErrorToStop != 0) )
    {   usStartEnable = 0;
    }
    /* ****************** Stopped or Starting Phase ******************* */
    else if((usDBmSystemPhase != CTL_PHASE_STOPPED) &&
            (usDBmSystemPhase != CTL_PHASE_STARTING))
    {   usStartEnable = 0;
    }
    /* ****************** Mode = 0: Crank And Remote ****************** */
    else if (usDBpOperationMode == 0)
    {   if (usDBmAutoModeActive == 0)
        {   usStartEnable = usDBmKeyEngineStart;
        }   else if (usDBmSwitchEngineStart != 0)
        {   usStartEnable = 1;
        }
    }
    /* ****************** Mode = 1: Pulse And Remote ****************** */
    else if (usDBpOperationMode == 1)
    {   if (usDBmAutoModeActive == 0)
        {   if (usDBmKeyEngineStart != 0)
            {   usStartEnable = 1;
            }
        }   else if (usDBmSwitchEngineStart != 0)
        {   usStartEnable = 1;
        }
    }
    /* ****************** Mode = 2: Crank And Main Voltage Low ******** */
    else if (usDBpOperationMode == 2)
    {   if (usDBmAutoModeActive == 0)
        {   usStartEnable = usDBmKeyEngineStart;
        }   else if (SF_ERR3_GET_BIT(SF_ERR3_MAIN_ERR_MSK) == 0)
        {   usStartEnable = 0;
        }   else
        {   usStartEnable = 1;
        }
    }
    /* ****************** Mode = 3: Pulse And Main Voltage Low ******** */
    else if (usDBpOperationMode == 3)
    {   if (usDBmAutoModeActive == 0)
        {   if (usDBmKeyEngineStart != 0)
            {   usStartEnable = 1;
            }
        }   else if (SF_ERR3_GET_BIT(SF_ERR3_MAIN_ERR_MSK) == 0)
        {   usStartEnable = 0;
        }   else
        {   usStartEnable = 1;
        }
    }
    /* ****************** Mode = 4: Crank And Can Command ************* */
    else if (usDBpOperationMode == 4)
    {   if (usDBmAutoModeActive == 0)
        {   usStartEnable = usDBmKeyEngineStart;
        }   else
        {   usStartEnable = CTLCheckCanComdToStart();
        }
    }
    /* ****************** Mode = 5: Pulse And Can Command ************* */
    else if (usDBpOperationMode == 4)
    {   if (usDBmAutoModeActive == 0)
        {   if (usDBmKeyEngineStart != 0)
            {   usStartEnable = 1;
            }
        }   else
        {   usStartEnable = CTLCheckCanComdToStart();
        }
    }
    return usStartEnable;
}

/* ******************************************************************** */
/*                        CTLGetSwitchOnAllowed()                      */
/* ******************************************************************** */
INT16U CTLGetSwitchOnAllowed (void)
{   static INT16U usSwitchAllowed = 0;
    /* ****************** Stopped or Error Condition ****************** */
    if((usDBmKeyEngineStop != 0) || 
       (usDBmSwitchEngineStop != 0) ||
       (usDBmCommonErrorToStop != 0) ||
       (usDBmEmergnErrorToStop != 0) )
    {   usSwitchAllowed = 0;
    }
    /* ****************** Stopped or Starting Phase ******************* */
    else if((usDBmSystemPhase != CTL_PHASE_SYNCHRING) &&
            (usDBmSystemPhase != CTL_PHASE_SWITCHING_ON) &&
            (usDBmSystemPhase != CTL_PHASE_WORKING) )
    {   usSwitchAllowed = 0;
    }
    /* ****************** Mode = 0: Manual And Remote ***************** */
    else if (usDBpOperationMode == 0)
    {   if (SF_ERR3_GET_BIT(SF_ERR3_GENS_ERR_MSK) != 0)
        {   usSwitchAllowed = 0;
        }
        else if (usDBmAutoModeActive != 0)
        {   if (usDBmSwitchBreakerOff != 0)
            {   usSwitchAllowed = 0;
            }   else if (usDBmSwitchBreakerOn != 0)
            {   usSwitchAllowed = 1;
            }
        }
        else if (usDBmKeyBreakerOff != 0)
        {   usSwitchAllowed = 0;
        }   else if (usDBmKeyBreakerOn != 0)
        {   usSwitchAllowed = 1;
        }
    }
    /* ****************** Mode = 1: Only Remote *********************** */
    else if (usDBpOperationMode == 1)
    {   if (SF_ERR3_GET_BIT(SF_ERR3_GENS_ERR_MSK) != 0)
        {   usSwitchAllowed = 0;
        }   else if (usDBmSwitchBreakerOff != 0)
        {   usSwitchAllowed = 0;
        }   else if (usDBmSwitchBreakerOn != 0)
        {   usSwitchAllowed = 1;
        }
    }
    /* ****************** Mode = 2: Manual And Main Voltage Low ******* */
    else if (usDBpOperationMode == 2)
    {   if (SF_ERR3_GET_BIT(SF_ERR3_MAIN_ERR_MSK) == 0)
        {   usSwitchAllowed = 0;
        }   else if (SF_ERR3_GET_BIT(SF_ERR3_GENS_ERR_MSK) != 0)
        {   usSwitchAllowed = 0;
        }   else if (usDBmAutoModeActive != 0)
        {   usSwitchAllowed = 1;
        }   else if (usDBmKeyBreakerOff != 0)
        {   usSwitchAllowed = 0;
        }   else if (usDBmKeyBreakerOn != 0)
        {   usSwitchAllowed = 1;
        }
    }
    /* ****************** Mode = 3: Only Main Voltage Low ************* */
    else if (usDBpOperationMode == 3)
    {   if (SF_ERR3_GET_BIT(SF_ERR3_MAIN_ERR_MSK) == 0)
        {   usSwitchAllowed = 0;
        }   else if (SF_ERR3_GET_BIT(SF_ERR3_GENS_ERR_MSK) != 0)
        {   usSwitchAllowed = 0;
        }   else
        {   usSwitchAllowed = 1;
        }
    }
    /* ****************** Mode = 4: Manual And Can+Differ ************* */
    else if (usDBpOperationMode == 4)
    {   if (SF_ERR5_GET_BIT(SF_ERR5_VOLT_DIFF_OVER) != 0)
        {   usSwitchAllowed = 0;
        }   else if (usDBmAutoModeActive != 0)
        {   usSwitchAllowed = CTLCheckCanComdToSwitchOn();
        }   else if (usDBmKeyBreakerOff != 0)
        {   usSwitchAllowed = 0;
        }   else if (usDBmKeyBreakerOn != 0)
        {   usSwitchAllowed = 1;
        }
    }
    /* ****************** Mode = 5: Only Can+Differ ******************* */
    else if (usDBpOperationMode == 5)
    {   if (SF_ERR5_GET_BIT(SF_ERR5_VOLT_DIFF_OVER) != 0)
        {   usSwitchAllowed = 0;
        }   else
        {   usSwitchAllowed = CTLCheckCanComdToSwitchOn();
        }
    }
    return usSwitchAllowed;
}    

/* ******************************************************************** */
/*                         CTLGetAutoModeActive()                       */
/* ******************************************************************** */
INT16U CTLGetAutoModeActive(void)
{   static INT16U usAutoOn = 0;
    if (usDBmKeyModeManual != 0)
    {   usAutoOn = 0;
    }
    else if (usDBmKeyModeAuto != 0)
    {   usAutoOn = 1;
    }
    return usAutoOn;
}

/* ******************************************************************** */
/*                           CTLGetSystemPhase()                        */
/* ******************************************************************** */
INT16U CTLGetSystemPhase (void)
{   static INT16U usSystemTimer = 0;
    static INT16U usSystemPhase = CTL_PHASE_INIT;
    INT16U usDelay, usTimNow;
    usTimNow = usFW100msTimer;
    usDelay = usTimNow - usSystemTimer;
    /* **************** CTL_PHASE_INIT: Initializing ****************** */
    if (usSystemPhase == CTL_PHASE_INIT)
    {   usSystemTimer = usTimNow;
        if (usDBmEngineStopped != 0)
        {   usSystemPhase = CTL_PHASE_STOPPED;
        }   else
        {   usSystemPhase = CTL_PHASE_STOPPING;
        }
    }
    /* **************** CTL_PHASE_STOPPED: Stopped ******************** */
    else if (usSystemPhase == CTL_PHASE_STOPPED)
    {   if((usDBmEngineStartActive == 0) || (usDBmEngineStopActive != 0))
        {   usSystemTimer = usTimNow;
        }
        else if (usDelay  > usDBpStoppedToStartingDly)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_STARTING;
        }
    }
    /* **************** CTL_PHASE_EMERGENCY: Emergency **************** */
    else if (usSystemPhase == CTL_PHASE_EMERGENCY)
    {   if (usDBmEngineStopped != 0)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_STOPPED;
        }
    }
    /* **************** CTL_PHASE_EMERGENCY: Emergency **************** */
    else if (usDBmEmergnErrorToStop != 0)
    {   usSystemTimer = usTimNow;
        usSystemPhase = CTL_PHASE_EMERGENCY;
    }
    /* **************** CTL_PHASE_STARTING: Starting ****************** */
    else if (usSystemPhase == CTL_PHASE_STARTING)
    {   if((usDBmEngineStartActive == 0) || (usDBmEngineStopActive != 0))
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_STOPPING;
        }
        else if (CTLGetEngineStsIdling() != 0)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_IDLING_UP;
        }
    }
    /* **************** CTL_PHASE_STOPPING: Stopping ****************** */
    else if (usSystemPhase == CTL_PHASE_STOPPING)
    {   if (usDBmEngineStopped != 0)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_STOPPED;
        }
    }
    /* ********************** If Engine Stopped *********************** */
    else if (usDBmEngineStopped != 0)
    {   usSystemTimer = usTimNow;
        usSystemPhase = CTL_PHASE_STOPPED;
    }
    /* **************** CTL_PHASE_IDLING_UP: Idling_Up **************** */
    else if (usSystemPhase == CTL_PHASE_IDLING_UP)
    {   if (usDBmEngineStopActive != 0)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_IDLING_DOWN;
        }
        else if (usDelay  > usDBpIdlingToRampUpDly)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_RAMP_UP;
        }
    }
    /* **************** CTL_PHASE_IDLING_DOWN: Idling_Down ************ */
    else if (usSystemPhase == CTL_PHASE_IDLING_DOWN)
    {   if (usDBmEngineStopActive == 0)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_IDLING_UP;
        }
        else if (usDelay  > usDBpIdlingToStoppingDly)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_STOPPING;
        }
    }
    /* **************** CTL_PHASE_RAMP_UP: Ramp_Up ******************** */
    else if (usSystemPhase == CTL_PHASE_RAMP_UP)
    {   if (usDBmEngineStopActive != 0)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_RAMP_DOWN;
        }
        else if (CTLGetEngineStsRated() != 0)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_RATED_UP;
        }
    }
    /* **************** CTL_PHASE_RAMP_DOWN: Ramp_Down **************** */
    else if (usSystemPhase == CTL_PHASE_RAMP_DOWN)
    {   if (usDBmEngineStopActive == 0)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_RAMP_UP;
        }
        else if (CTLGetEngineStsIdling() != 0)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_IDLING_DOWN;
        }
    }
    /* **************** CTL_PHASE_RATED_UP: Rated_UP ****************** */
    else if (usSystemPhase == CTL_PHASE_RATED_UP)
    {   if (usDBmEngineStopActive != 0)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_RATED_DOWN;
        }
        else if (usDelay  > usDBpRatedToSynchringDly)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_SYNCHRING;
        }
    }
    /* **************** CTL_PHASE_RATED_DOWN: Rated_Down ************** */
    else if (usSystemPhase == CTL_PHASE_RATED_DOWN)
    {   if (usDBmEngineStopActive == 0)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_RATED_UP;
        }
        else if (usDelay  > usDBpRatedToRampDowmDly)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_RAMP_DOWN;
        }
    }
    /* **************** CTL_PHASE_SYNCHRING: Synchring **************** */
    else if (usSystemPhase == CTL_PHASE_SYNCHRING)
    {   if (usDBmEngineStopActive != 0)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_RATED_DOWN;
        }
        else if (usDBmBreakerOnAllowed != 0)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_SWITCHING_ON;
        }
    }
    /* **************** CTL_PHASE_SWITCHING_ON: Switching_On ********** */
    else if (usSystemPhase == CTL_PHASE_SWITCHING_ON)
    {   if((usDBmGensBreakerOn != 0) && (usDBmMainBreakerOn == 0))
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_WORKING;
        }
    }
    /* **************** CTL_PHASE_SWITCHING_OFF: Switching Off ******** */
    else if (usSystemPhase == CTL_PHASE_SWITCHING_OFF)
    {   if((usDBmGensBreakerOn == 0) && (usDBmMainBreakerOn != 0))
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_RATED_DOWN;
        }
    }
    /* **************** CTL_PHASE_WORKING: Working ******************** */
    else if (usSystemPhase == CTL_PHASE_WORKING)
    {   if (usDBmEngineStopActive == 0)
        {   usSystemTimer = usTimNow;
        }
        else if (usDelay  > usDBpWorkingToSwitchOffDly)
        {   usSystemTimer = usTimNow;
            usSystemPhase = CTL_PHASE_SWITCHING_OFF;
        }
    }
    /* ******************** Others: Logic Fault *********************** */
    else
    {   CTL_STS_SET_BIT(CTL_STS_ERR_LOGIC);
        usSystemPhase = CTL_PHASE_INIT;
        usSystemTimer = usTimNow;
    }
    /* *********************** End of IF ****************************** */
    return usSystemPhase;
}

/* ******************************************************************** */
/*                       CTLGetAirHeatActive()                        */
/* ******************************************************************** */
INT16U CTLGetAirHeatActive (void)
{   static INT16U usTimer1 = 0;
    static INT16U usActive = 0;
    INT16U usDelay, usTimNow;
    usTimNow = usFW100msTimer;
    usDelay  = usDBmCoolantTemperature;
    if (usDelay >= usDBpAirHeatTempWarm)
    {   usDBmAirHeatDuration = 0;
    }   else
    {   usDBmAirHeatDuration = SFInterp16u (usDelay, usDBpAirHeatTempCold,
        usDBpAirHeatTempWarm, usDBpAirHeatTimeAtCold, usDBpAirHeatTimeAtWarm);
    }
    usDelay = usTimNow - usTimer1;
    if((usDBmSystemPhase != CTL_PHASE_STARTING) ||
       (usDBmEngineRunning != 0) ||
       (usDBmSwitchAirHeat == 0) ||
       (usDBmAirHeatDuration == 0))
    {   usTimer1 = usTimNow - CTL_OFFTIME_HEATER;
        usActive = 0;
    }
    else if (usActive == 0)
    {   if (usDelay >= CTL_OFFTIME_HEATER)
        {   usTimer1 = usTimNow;
            usActive = 1;
        }
    }
    else if (usDelay >= usDBmAirHeatDuration)
    {   usTimer1 = usTimNow;
        usActive = 0;
    }
    return usActive;
}

/* ******************************************************************** */
/*                         CTLGetOilPumpActive()                        */
/* ******************************************************************** */
INT16U CTLGetOilPumpActive (void)
{   static INT16U usTimer1 = 0;
    static INT16U usActive = 0;
    INT16U usDelay;
    usDelay = usFW100msTimer - usTimer1;
    if((usDBmSwitchOilPump == 0) ||
       (usDBmEngineRunning != 0) ||
       (usDBmSystemPhase != CTL_PHASE_STARTING))
    {   usTimer1 = usFW100msTimer - CTL_OFFTIME_OILPUMP;
        usActive = 0;
    }
    else if (usActive == 0)
    {   if (usDelay >= CTL_OFFTIME_OILPUMP)
        {   usTimer1 = usFW100msTimer;
            usActive = 1;
        }
    }
    else if ((usDelay >= usDBpOilPumpOnTimeMax) ||
       (usDBmOilPressure >= usDBpOilPressMinAtStart))
    {   usTimer1 = usFW100msTimer;
        usActive = 0;
    }
    return usActive;
}

/* ******************************************************************** */
/*                      CTLGetFuelSupplyActive()                        */
/* ******************************************************************** */
INT16U CTLGetFuelSupplyActive (void)
{   if((usDBmSystemPhase == CTL_PHASE_INIT) ||
       (usDBmSystemPhase == CTL_PHASE_STOPPED) ||
       (usDBmSystemPhase == CTL_PHASE_EMERGENCY) ||
       (usDBmSystemPhase == CTL_PHASE_STOPPING) )
    {   return 0;
    }   else
    {   return 1;
    }
}

/* ******************************************************************** */
/*                        CTLGetStarterActive()                         */
/* ******************************************************************** */
INT16U CTLGetStarterActive (void)
{   static INT16U usTimer1 = 0;
    static INT16U usActive = 0;
    INT16U usDelay, usTimNow;
    usTimNow = usFW100msTimer;
    usDelay  = usTimNow - usTimer1;
    if((usDBmAirHeatActive != 0) ||
       (usDBmOilPumpActive != 0) ||
       (usDBmEngineRunning != 0) ||
       (usDBmSystemPhase   != CTL_PHASE_STARTING) ||
       (usDBmStartFailTimes >= usDBpStartFailMax) )
    {   usTimer1 = usTimNow - usDBpStarterOffDly;
        usActive = 0;
    }
    else if (usActive == 0)
    {   if (usDelay >= usDBpStarterOffDly)
        {   uiDBhStartTimes32B += 1;
            usTimer1 = usTimNow;
            usActive = 1;
        }
    }
    else if (usDelay >= usDBpStarterOnDly)
    {   usDBmStartFailTimes += 1;
        usTimer1 = usTimNow;
        usActive = 0;
    }
    return usActive;
}

/* ******************************************************************** */
/*                         CTLGetCoolantFanActive()                     */
/* ******************************************************************** */
INT16U CTLGetCoolantFanActive (INT16U usAssign)
{   static INT16U usTimer1 = 0;
    static INT16U usActive = 0;
    INT16U usTemp, usDelay;
    if (usAssign >= DB_MEASU_SIZE)
    {   return 0;
    }
    usTemp  = aDBMeasu[usAssign];
    usDelay = usFW100msTimer - usTimer1;
    if (usDBmEngineRunning != 0)
    {   usTimer1 = usFW100msTimer;
        if (usTemp >= usDBpFanActiveTemp)
        {   usActive = 1;
        }   else if ((usTemp + 80) <= usDBpFanActiveTemp)
        {   usActive = 0;
        }
    }
    else if (usActive != 0)
    {   if (usDelay >= usDBpFanActiveDly)
        {   usActive = 0;
        }
    }
    return usActive;
}

/* ******************************************************************** */
/*                         CTLGetSpeedRatedActive()                     */
/* ******************************************************************** */
INT16U CTLGetSpeedRatedActive (void)
{   if((usDBmSystemPhase == CTL_PHASE_RAMP_UP) ||
       (usDBmSystemPhase == CTL_PHASE_RATED_UP) ||
       (usDBmSystemPhase == CTL_PHASE_RATED_DOWN) ||
       (usDBmSystemPhase == CTL_PHASE_SYNCHRING) ||
       (usDBmSystemPhase == CTL_PHASE_SWITCHING_ON) ||
       (usDBmSystemPhase == CTL_PHASE_SWITCHING_OFF) ||
       (usDBmSystemPhase == CTL_PHASE_WORKING) )
    {   return 1;
    }   else
    {   return 0;
    }
}

/* ******************************************************************** */
/*                         CTLGetMainSwitchOn()                         */
/* ******************************************************************** */
INT16U CTLGetMainSwitchOn (void)
{   static INT16U usTimer1 = 0;
    static INT16U usActive = 0;
    INT16U usDelay, usTimNow;
    usTimNow = usFW100msTimer;
    usDelay  = usTimNow - usTimer1;
    if((usDBmSystemPhase == CTL_PHASE_WORKING) ||
       (usDBmSystemPhase == CTL_PHASE_SWITCHING_ON))
    {   usTimer1 = usTimNow;
        usActive = 0;
    }
    else if ((usDBmGensBreakerOn != 0) || (usDBmSwitchGensFeedback != 0))
    {   usTimer1 = usTimNow;
        usActive = 0;
    }
    else if (usDelay >= usDBpMainBreakerOnDly)
    {   usTimer1 = usTimNow;
        usActive = 1;
    }
    return usActive;
}

/* ******************************************************************** */
/*                         CTLGetGensSwitchOn()                         */
/* ******************************************************************** */
INT16U CTLGetGensSwitchOn (void)
{   static INT16U usTimer1 = 0;
    static INT16U usActive = 0;
    INT16U usDelay, usTimNow;
    usTimNow = usFW100msTimer;
    usDelay  = usTimNow - usTimer1;
    if((usDBmSystemPhase != CTL_PHASE_WORKING) &&
       (usDBmSystemPhase != CTL_PHASE_SWITCHING_ON))
    {   usTimer1 = usTimNow;
        usActive = 0;
    }
    else if ((usDBmMainBreakerOn != 0) || (usDBmSwitchMainFeedback != 0))
    {   usTimer1 = usTimNow;
        usActive = 0;
    }
    else if (usDelay >= usDBpGensBreakerOnDly)
    {   usTimer1 = usTimNow;
        usActive = 1;
    }
    return usActive;
}

/* ******************************************************************** */
/*                       CTLGetSpeedTuningControl()                     */
/* ******************************************************************** */
INT16S CTLGetSpeedTuningControl (void)
{   CTLSpeedTuner.usGain       =  usDBpSpeedTuneGain;
    CTLSpeedTuner.usStability  =  usDBpSpeedTuneStability;
    CTLSpeedTuner.usDerivative =  usDBpSpeedTuneDerivative;
    CTLSpeedTuner.siCtrlMax    =  2560000;
    CTLSpeedTuner.siCtrlMin    = -2560000;
    if((usDBmSystemPhase == CTL_PHASE_SYNCHRING) ||
       (usDBmSystemPhase == CTL_PHASE_SWITCHING_ON))
    {   return SFGetPidCtrl16s(ssDBmPhaseDiffer, 0, &CTLSpeedTuner);
    }
    else if((usDBmSystemPhase == CTL_PHASE_WORKING) ||
       (usDBmSystemPhase == CTL_PHASE_SWITCHING_OFF))
    {   return SFGetPidCtrl16s(ssDBmActPowerAll, ssDBmActPowerSetp, &CTLSpeedTuner);
    }
    else
    {   CTLSpeedTuner.siCtrlOld  = (INT32S)ssDBpSpeedTuneCtrlInit * 256;
        CTLSpeedTuner.ssInputOld = 0;
        return ssDBpSpeedTuneCtrlInit;
    }
}

/* ******************************************************************** */
/*                       CTLGetAvrTuningControl()                       */
/* ******************************************************************** */
INT16S CTLGetAvrTuningControl (void)
{   CTLAvrTuner.usGain       =  usDBpAvrTuneGain;
    CTLAvrTuner.usStability  =  usDBpAvrTuneStability;
    CTLAvrTuner.usDerivative =  usDBpAvrTuneDerivative;
    CTLAvrTuner.siCtrlMax    =  2560000;
    CTLAvrTuner.siCtrlMin    = -2560000;
    if((usDBmSystemPhase == CTL_PHASE_SYNCHRING) ||
       (usDBmSystemPhase == CTL_PHASE_SWITCHING_ON))
    {   return SFGetPidCtrl16s(ssDBmVoltDiffer, 0, &CTLAvrTuner);
    }
    else if((usDBmSystemPhase == CTL_PHASE_WORKING) ||
       (usDBmSystemPhase == CTL_PHASE_SWITCHING_OFF))
    {   return SFGetPidCtrl16s(ssDBmReactPowerAll, ssDBmReactPowerSetp, &CTLAvrTuner);
    }
    else
    {   CTLAvrTuner.siCtrlOld  = (INT32S)ssDBpAvrTuneCtrlInit * 256;
        CTLAvrTuner.ssInputOld = 0;
        return ssDBpAvrTuneCtrlInit;
    }
}

/* ******************************************************************** */
/*                       CTLCheckCanComdToStart()                       */
/* ******************************************************************** */
INT16U CTLCheckCanComdToStart (void)
{   return 0;
}

/* ******************************************************************** */
/*                       CTLCheckCanComdToStop()                        */
/* ******************************************************************** */
INT16U CTLCheckCanComdToStop (void)
{   return 1;
}

/* ******************************************************************** */
/*                       CTLCheckCanComdToStart()                       */
/* ******************************************************************** */
INT16U CTLCheckCanComdToSwitchOn (void)
{   return 0;
}

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */