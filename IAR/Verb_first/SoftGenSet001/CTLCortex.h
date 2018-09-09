/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Header File CTLCortex.h                        */
/*                              2016-1-14                               */
/* ******************************************************************** */

#ifndef _CTLCORTEX_H

#define _CTLCORTEX_H

#ifdef   CTL_GLOBALS

#define  CTL_EXT  

#else

#define  CTL_EXT extern

#endif

/* ******************************************************************** */
/*  CTL_VERSION  = 10xx: VEC1000 Application                            */
/*  CTL_VERSION  = 40xx: VEC4000 Application                            */
/*  CTL_VERSION  = 68xx: VEC6800 Application                            */
/*  CTL_VERSION  = 69xx: VEC6900 Application                            */
/*  CTL_VERSION  = 76xx: GEC7600 Application                            */
/*  CTL_VERSION  = 78xx: GEC7800 Application                            */
/*  CTL_VERSION  = 80xx: VEC8000 Application                            */
/*  CTL_VERSION  = 90xx: VEC9000 Application                            */
/*  CTL_VERSION  = 96xx: VEC9600 Application                            */
/* ******************************************************************** */

#define CTL_VERSION          7600

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define CTL_1000_COMMON_ON      0
#define CTL_4000_COMMON_ON      0
#define CTL_6800_COMMON_ON      0
#define CTL_6900_COMMON_ON      0
#define CTL_7600_COMMON_ON      0
#define CTL_7800_COMMON_ON      0
#define CTL_8000_COMMON_ON      0
#define CTL_9000_COMMON_ON      0
#define CTL_9600_COMMON_ON      0
#if   ((CTL_VERSION / 100)  == 10)
#undef  CTL_1000_COMMON_ON
#define CTL_1000_COMMON_ON      1
#endif
#if   ((CTL_VERSION / 100)  == 40)
#undef  CTL_4000_COMMON_ON
#define CTL_4000_COMMON_ON      1
#endif
#if   ((CTL_VERSION / 100)  == 68)
#undef  CTL_6800_COMMON_ON
#define CTL_6800_COMMON_ON      1
#endif
#if   ((CTL_VERSION / 100)  == 69)
#undef  CTL_6900_COMMON_ON
#define CTL_6900_COMMON_ON      1
#endif
#if   ((CTL_VERSION / 100)  == 76)
#undef  CTL_7600_COMMON_ON
#define CTL_7600_COMMON_ON      1
#endif
#if   ((CTL_VERSION / 100)  == 78)
#undef  CTL_7800_COMMON_ON
#define CTL_7800_COMMON_ON      1
#endif
#if   ((CTL_VERSION / 100)  == 80)
#undef  CTL_8000_COMMON_ON
#define CTL_8000_COMMON_ON      1
#endif
#if   ((CTL_VERSION / 100)  == 90)
#undef  CTL_9000_COMMON_ON
#define CTL_9000_COMMON_ON      1
#endif
#if   ((CTL_VERSION / 100)  == 96)
#undef  CTL_9600_COMMON_ON
#define CTL_9600_COMMON_ON      1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define CTL_CPU_9S12_ON         0
#define CTL_CPU_POWERPC_ON      0
#define CTL_CPU_STM32F1_ON      0
#if    (CTL_1000_COMMON_ON   == 1)
#undef  CTL_CPU_9S12_ON
#define CTL_CPU_9S12_ON         1
#endif
#if    (CTL_4000_COMMON_ON   == 1)
#undef  CTL_CPU_9S12_ON
#define CTL_CPU_9S12_ON         1
#endif
#if    (CTL_6800_COMMON_ON   == 1)
#undef  CTL_CPU_9S12_ON
#define CTL_CPU_9S12_ON         1
#endif
#if    (CTL_6900_COMMON_ON   == 1)
#undef  CTL_CPU_POWERPC_ON
#define CTL_CPU_POWERPC_ON      1
#endif
#if    (CTL_7600_COMMON_ON   == 1)
#undef  CTL_CPU_STM32F1_ON
#define CTL_CPU_STM32F1_ON      1
#endif
#if    (CTL_7800_COMMON_ON   == 1)
#undef  CTL_CPU_STM32F1_ON
#define CTL_CPU_STM32F1_ON      1
#endif
#if    (CTL_8000_COMMON_ON   == 1)
#undef  CTL_CPU_POWERPC_ON
#define CTL_CPU_POWERPC_ON      1
#endif
#if    (CTL_9000_COMMON_ON   == 1)
#undef  CTL_CPU_POWERPC_ON
#define CTL_CPU_POWERPC_ON      1
#endif
#if    (CTL_9600_COMMON_ON   == 1)
#undef  CTL_CPU_POWERPC_ON
#define CTL_CPU_POWERPC_ON      1
#endif

/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define CTL_TRUE                 1
#define CTL_FALSE                0
#define CTL_NO_ERR               0
#define CTL_STS_NORMAL           0
#define CTL_STS_RESET            1
#define CTL_STS_WARNING          2
#define CTL_STS_ERR_LOGIC        4
#define CTL_STS_GET_BIT(m)     (usCTLStatus & (m))
#define CTL_STS_CLR_BIT(m)      usCTLStatus &= ~(m)
#define CTL_STS_SET_BIT(m)      usCTLStatus |= (m)
#define CTL_MODE_MANUAL          0
#define CTL_MODE_AUTO_ALONE      1
#define CTL_MODE_AUTO_ONLINE     2
#define CTL_PHASE_INIT           0
#define CTL_PHASE_STOPPED        1
#define CTL_PHASE_STARTING       2
#define CTL_PHASE_STOPPING       3
#define CTL_PHASE_IDLING_UP      4
#define CTL_PHASE_IDLING_DOWN    5
#define CTL_PHASE_RAMP_UP        6
#define CTL_PHASE_RAMP_DOWN      7
#define CTL_PHASE_RATED_UP       8
#define CTL_PHASE_RATED_DOWN     9
#define CTL_PHASE_SYNCHRING      10
#define CTL_PHASE_SWITCHING_ON   11
#define CTL_PHASE_SWITCHING_OFF  12
#define CTL_PHASE_WORKING        13
#define CTL_PHASE_EMERGENCY      14

/* ******************************************************************** */
/*                          Control Definition                          */
/* ******************************************************************** */
#define CTL_START_CNT_MAX        3
#define CTL_START_DLY_INSERT    (OS_TICKS_PER_SEC * 10)
#define CTL_START_DLY_STOP      (OS_TICKS_PER_SEC * 5)
#define CTL_SPEED_RAMP_MIN       5
#define CTL_SPEED_RAMP_MAX       20
#define CTL_SPEED_RAMP_CONST     10
#define CTL_SPEED_DROOP_MAX      500
#define CTL_SPEED_DROOP_CTRL_MIN 102                   /* Percent = 10% */
#define CTL_SPEED_DROOP_CTRL_MAX 819                   /* Percent = 80% */
#define CTL_SPEED_CTRL_FILTER    64
#define CTL_SPEED_CTRL_MIN       0
#define CTL_SPEED_CTRL_MAX       1024
#define CTL_SPEED_CTRL_MIN32    (INT32U)0
#define CTL_SPEED_CTRL_MAX32    (INT32U)(CTL_SPEED_CTRL_MAX * 1024)
#define CTL_OFFTIME_HEATER      (INT16U)3000
#define CTL_OFFTIME_OILPUMP     (INT16U)3000

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
CTL_EXT INT16U usCTLTimer;
CTL_EXT INT16U usCTLStatus;
CTL_EXT PID16S_PAR_STR CTLAvrTuner;
CTL_EXT PID16S_PAR_STR CTLSpeedTuner;

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
CTL_EXT void   CTLInit(void);
CTL_EXT void   CTLSysMonitor(void);
CTL_EXT void   CTLSysController(void);

CTL_EXT INT16U CTLGetEngineStsStopped(void);
CTL_EXT INT16U CTLGetEngineStsRunning(void);
CTL_EXT INT16U CTLGetEngineStsIdling(void);
CTL_EXT INT16U CTLGetEngineStsRated(void);

CTL_EXT INT16U CTLGetErrorEmergnStop(void);
CTL_EXT INT16U CTLGetErrorCommonStop(void);
CTL_EXT INT16U CTLGetErrorCommonWarn(void);

CTL_EXT INT16U CTLGetEngineStopActive(void);
CTL_EXT INT16U CTLGetEngineStartActive(void);
CTL_EXT INT16U CTLGetSwitchOnAllowed(void);
CTL_EXT INT16U CTLGetAutoModeActive(void);
CTL_EXT INT16U CTLGetSystemPhase(void);

CTL_EXT INT16U CTLGetAirHeatActive(void);
CTL_EXT INT16U CTLGetOilPumpActive(void);
CTL_EXT INT16U CTLGetStarterActive(void);
CTL_EXT INT16U CTLGetFuelSupplyActive(void);
CTL_EXT INT16U CTLGetCoolantFanActive(INT16U usAssign);
CTL_EXT INT16U CTLGetSpeedRatedActive(void);
CTL_EXT INT16U CTLGetMainSwitchOn(void);
CTL_EXT INT16U CTLGetGensSwitchOn(void);
CTL_EXT INT16S CTLGetSpeedTuningControl(void);
CTL_EXT INT16S CTLGetAvrTuningControl(void);

CTL_EXT INT16U CTLCheckCanComdToStart(void);
CTL_EXT INT16U CTLCheckCanComdToStop(void);
CTL_EXT INT16U CTLCheckCanComdToSwitchOn(void);

/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
