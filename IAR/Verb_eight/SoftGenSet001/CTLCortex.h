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
/*  CTL_VERSION  = 760x: GEC7600-Main Application                       */
/*  CTL_VERSION  = 761x: GEC7600-Display Application                    */
/*  CTL_VERSION  = 780x: GEC7800-Main Application                       */
/*  CTL_VERSION  = 781x: GEC7800-Display Application                    */
/*  CTL_VERSION  = 80xx: VEC8000 Application                            */
/*  CTL_VERSION  = 90xx: VEC9000 Application                            */
/*  CTL_VERSION  = 96xx: VEC9600 Application                            */
/* ******************************************************************** */

#define CTL_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define CTL_1000_COMMON_ON       0
#define CTL_4000_COMMON_ON       0
#define CTL_6800_COMMON_ON       0
#define CTL_6900_COMMON_ON       0
#define CTL_7600_COMMON_ON       0
#define CTL_7600_MAIN_CHIP_ON    0
#define CTL_7600_AUX_CHIP_ON     0
#define CTL_7800_COMMON_ON       0
#define CTL_7800_MAIN_CHIP_ON    0
#define CTL_7800_AUX_CHIP_ON     0
#define CTL_8000_COMMON_ON       0
#define CTL_9000_COMMON_ON       0
#define CTL_9600_COMMON_ON       0
#if   ((CTL_VERSION / 100)   == 10)
#undef  CTL_1000_COMMON_ON
#define CTL_1000_COMMON_ON       1
#endif
#if   ((CTL_VERSION / 100)   == 40)
#undef  CTL_4000_COMMON_ON
#define CTL_4000_COMMON_ON       1
#endif
#if   ((CTL_VERSION / 100)   == 68)
#undef  CTL_6800_COMMON_ON
#define CTL_6800_COMMON_ON       1
#endif
#if   ((CTL_VERSION / 100)   == 69)
#undef  CTL_6900_COMMON_ON
#define CTL_6900_COMMON_ON       1
#endif
#if   ((CTL_VERSION / 100)   == 76)
#undef  CTL_7600_COMMON_ON
#define CTL_7600_COMMON_ON       1
#endif
#if   ((CTL_VERSION / 10)   == 760)
#undef  CTL_7600_MAIN_CHIP_ON
#define CTL_7600_MAIN_CHIP_ON    1
#endif
#if   ((CTL_VERSION / 10)   == 761)
#undef  CTL_7600_AUX_CHIP_ON
#define CTL_7600_AUX_CHIP_ON     1
#endif
#if   ((CTL_VERSION / 100)   == 78)
#undef  CTL_7800_COMMON_ON
#define CTL_7800_COMMON_ON       1
#endif
#if   ((CTL_VERSION / 10)   == 780)
#undef  CTL_7800_MAIN_CHIP_ON
#define CTL_7800_MAIN_CHIP_ON    1
#endif
#if   ((CTL_VERSION / 10)   == 781)
#undef  CTL_7800_AUX_CHIP_ON
#define CTL_7800_AUX_CHIP_ON     1
#endif
#if   ((CTL_VERSION / 100)   == 80)
#undef  CTL_8000_COMMON_ON
#define CTL_8000_COMMON_ON       1
#endif
#if   ((CTL_VERSION / 100)   == 90)
#undef  CTL_9000_COMMON_ON
#define CTL_9000_COMMON_ON       1
#endif
#if   ((CTL_VERSION / 100)   == 96)
#undef  CTL_9600_COMMON_ON
#define CTL_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define CTL_FUNCTION_ON          1
#define CTL_CPU_9S12_ON          0
#define CTL_CPU_POWERPC_ON       0
#define CTL_CPU_STM32F1_ON       0
#define CTL_CPU_STM32F103_ON     0
#define CTL_CPU_STM32F105_ON     0
#if    (CTL_1000_COMMON_ON    == 1)
#undef  CTL_CPU_9S12_ON
#define CTL_CPU_9S12_ON          1
#endif
#if    (CTL_4000_COMMON_ON    == 1)
#undef  CTL_CPU_9S12_ON
#define CTL_CPU_9S12_ON          1
#endif
#if    (CTL_6800_COMMON_ON    == 1)
#undef  CTL_CPU_9S12_ON
#define CTL_CPU_9S12_ON          1
#endif
#if    (CTL_6900_COMMON_ON    == 1)
#undef  CTL_CPU_POWERPC_ON
#define CTL_CPU_POWERPC_ON       1
#endif
#if    (CTL_7600_COMMON_ON    == 1)
#undef  CTL_CPU_STM32F1_ON
#define CTL_CPU_STM32F1_ON       1
#endif
#if    (CTL_7600_MAIN_CHIP_ON == 1)
#undef  CTL_CPU_STM32F105_ON
#define CTL_CPU_STM32F105_ON     1
#endif
#if    (CTL_7600_AUX_CHIP_ON  == 1)
#undef  CTL_CPU_STM32F103_ON
#define CTL_CPU_STM32F103_ON     1
#endif
#if    (CTL_7800_COMMON_ON    == 1)
#undef  CTL_CPU_STM32F1_ON
#define CTL_CPU_STM32F1_ON       1
#endif
#if    (CTL_7800_MAIN_CHIP_ON == 1)
#undef  CTL_CPU_STM32F105_ON
#define CTL_CPU_STM32F105_ON     1
#endif
#if    (CTL_7800_AUX_CHIP_ON  == 1)
#undef  CTL_CPU_STM32F103_ON
#define CTL_CPU_STM32F103_ON     1
#endif
#if    (CTL_8000_COMMON_ON    == 1)
#undef  CTL_CPU_POWERPC_ON
#define CTL_CPU_POWERPC_ON       1
#endif
#if    (CTL_9000_COMMON_ON    == 1)
#undef  CTL_CPU_POWERPC_ON
#define CTL_CPU_POWERPC_ON       1
#endif
#if    (CTL_9600_COMMON_ON    == 1)
#undef  CTL_CPU_POWERPC_ON
#define CTL_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define CTL_TRUE                 1
#define CTL_FALSE                0
#define CTL_NO_ERR               0
#define CTL_STS_NORMAL          (INT32U)0x00000000
#define CTL_STS_RESET           (INT32U)0x00000001
#define CTL_STS_WARNING         (INT32U)0x00000002
#define CTL_STS_ERR_LOGIC       (INT32U)0x00000004
#define CTL_STS_GET_BIT(m)      (uiCTLStatus & (m))
#define CTL_STS_CLR_BIT(m)       uiCTLStatus &= ~(m)
#define CTL_STS_SET_BIT(m)       uiCTLStatus |= (m)

/* ******************************************************************** */
/*                            System Definition                         */
/* ******************************************************************** */
#define CTL_MODE_SIMPLE          0
#define CTL_MODE_SINGLE          1
#define CTL_MODE_AMF             2
#define CTL_MODE_ISLAND          3
#define CTL_MODE_FIXPOWER        4
#define CTL_MODE_PARALLEL        5
#define CTL_PID_MODE_INIT        0
#define CTL_PID_MODE_SINGLE      1
#define CTL_PID_MODE_SYNC        2
#define CTL_PID_MODE_LOAD        3
#define CTL_PID_MODE_HOLD        4
#define CTL_CT4FUNC_NO_USE       0
#define CTL_CT4FUNC_MAIN_A       1
#define CTL_CT4FUNC_MAIN_GND     2
#define CTL_CT4FUNC_GENS_GND     3
#define CTL_PHASE_INIT           0
#define CTL_PHASE_STOPPED        1
#define CTL_PHASE_READY          2
#define CTL_PHASE_STARTING       3
#define CTL_PHASE_STOPPING       4
#define CTL_PHASE_IDLING_UP      5
#define CTL_PHASE_IDLING_DOWN    6
#define CTL_PHASE_RAMP_UP        7
#define CTL_PHASE_RAMP_DOWN      8
#define CTL_PHASE_RATED_UP       9
#define CTL_PHASE_RATED_DOWN     10
#define CTL_PHASE_WAIT_KEY_SW    11
#define CTL_PHASE_SYNCHRING      12
#define CTL_PHASE_SYNCHRING2     13
#define CTL_PHASE_LOADING_UP     14
#define CTL_PHASE_LOADING_DOWN   15
#define CTL_PHASE_FIXPWR_UP      16
#define CTL_PHASE_FIXPWR_DOWN    17
#define CTL_PHASE_WORKING        18
#define CTL_PHASE_EMERGENCY      19
#define CTL_PHASE_MAIN_SW_ON     20
#define CTL_PHASE_MAIN_SW_ON2    21
#define CTL_PHASE_MAIN_SW_OFF    22
#define CTL_PHASE_MAIN_SW_OFF2   23
#define CTL_PHASE_GENS_SW_ON     24
#define CTL_PHASE_GENS_SW_OFF    25

/* ******************************************************************** */
/*                          Control Definition                          */
/* ******************************************************************** */
#define CTL_LOAD_RAMP_FREQ       50
#define CTL_LOAD_RAMP_STEP_MIN   2
#define CTL_LOAD_OFF_ACT_SETP    3
#define CTL_LOAD_OFF_RCT_SETP    2
#define CTL_LED_BLINK_TICKS     (OS_TICKS_PER_SEC/4)

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)

CTL_EXT INT32U uiCTLStatus;
CTL_EXT INT08U ucCTLMainSwTry;
CTL_EXT INT08U ucCTLGensSwTry;
CTL_EXT SWITCH_DELAY_STR sCTLKeyErrReset;
CTL_EXT PID16S_PAR_STR CTLAvrTuner;
CTL_EXT PID16S_PAR_STR CTLGovTuner;
CTL_EXT SF_SW_CTRL_STR sCTLMainSwitch;
CTL_EXT SF_SW_CTRL_STR sCTLGensSwitch;

#endif
/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (CTL_FUNCTION_ON == 1)

CTL_EXT void   CTLInit(void);
CTL_EXT void   CTLSysMonitor(void);
CTL_EXT void   CTLSysController(void);

CTL_EXT INT16U CTLGetBoardLedOutput(void);
CTL_EXT void   CTLMainSwitchInit(SF_SW_CTRL_STR *pMain);
CTL_EXT void   CTLGensSwitchInit(SF_SW_CTRL_STR *pGens);
CTL_EXT INT16U CTLGetSingleCmdToSwOn(INT16U usPhase, INT16U usAuto);
CTL_EXT INT16U CTLGetParallCmdToSwOn(INT16U usPhase, INT16U usAuto);

CTL_EXT INT16U CTLGetSysAutoOrManual(void);
CTL_EXT INT16U CTLGetEmergnCmdToStop(void);
CTL_EXT INT16U CTLGetEmergnErrToStop(void);
CTL_EXT INT16U CTLGetCommonErrToStop(void);
CTL_EXT INT16U CTLGetCommonErrToWarn(void);

CTL_EXT INT16U CTLCheckGensReadyToLoad(void);
CTL_EXT INT16U CTLCheckMainReadyToSync(void);
CTL_EXT INT16U CTLCheckIsMainVoltNormal(void);
CTL_EXT INT16U CTLCheckSyncCondition(INT16U usReady);
CTL_EXT INT16U CTLCheckIsGensWorking(INT16U usPhase);
CTL_EXT INT16U CTLCheckIsMainVoltLost(void);

CTL_EXT INT16U CTLGetGovControl(INT16U usPidMod);
CTL_EXT INT16U CTLGetAvrControl(INT16U usPidMod);
CTL_EXT INT16U CTLGetLoadRampStepAct(INT32U uiRamp);
CTL_EXT INT16U CTLGetLoadSetpRampAct(INT16U usSelect, INT16U usOld, INT16U usAll);
CTL_EXT INT16U CTLGetLoadRampStepRct(INT32U uiRamp);
CTL_EXT INT16U CTLGetLoadSetpRampRct(INT16U usSelect, INT16U usOld, INT16U usAll);
CTL_EXT INT16U CTLGetFixPwrSetp(INT16U usPMain, INT16U usPGens, INT16U usPMax);

CTL_EXT INT16U CTLGetSimpleCmdToStop(INT16U usAutoOrHand);
CTL_EXT INT16U CTLGetSingleCmdToStop(INT16U usAutoOrHand);
CTL_EXT INT16U CTLGetAmfCmdToStop(INT16U usAutoOrHand);
CTL_EXT INT16U CTLGetIslandCmdToStop(INT16U usAutoOrHand);
CTL_EXT INT16U CTLGetFixPwrCmdToStop(INT16U usAutoOrHand);
CTL_EXT INT16U CTLGetParallCmdToStop(INT16U usAutoOrHand);

CTL_EXT INT16U CTLGetSimpleGensSwOnCndt(void);
CTL_EXT INT16U CTLGetSingleGensSwOnCndt(void);
CTL_EXT INT16U CTLGetAmfGensSwOnCndt(void);
CTL_EXT INT16U CTLGetIslandGensSwOnCndt(void);
CTL_EXT INT16U CTLGetFixPwrGensSwOnCndt(void);
CTL_EXT INT16U CTLGetParallGensSwOnCndt(void);

CTL_EXT INT16U CTLGetSimpleMainSwOnCndt(void);
CTL_EXT INT16U CTLGetSingleMainSwOnCndt(void);
CTL_EXT INT16U CTLGetAmfMainSwOnCndt(void);
CTL_EXT INT16U CTLGetIslandMainSwOnCndt(void);
CTL_EXT INT16U CTLGetFixPwrMainSwOnCndt(void);
CTL_EXT INT16U CTLGetParallMainSwOnCndt(void);

CTL_EXT INT16U CTLGetSimplePidMode(INT16U usPhase);
CTL_EXT INT16U CTLGetSinglePidMode(INT16U usPhase);
CTL_EXT INT16U CTLGetAmfPidMode(INT16U usPhase);
CTL_EXT INT16U CTLGetIslandPidMode(INT16U usPhase);
CTL_EXT INT16U CTLGetFixPwrPidMode(INT16U usPhase);
CTL_EXT INT16U CTLGetParallPidMode(INT16U usPhase);

CTL_EXT INT16U CTLGetSimpleSysPhase(INT16U usStep);
CTL_EXT INT16U CTLGetSingleSysPhase(INT16U usStep);
CTL_EXT INT16U CTLGetAmfSysPhase(INT16U usStep);
CTL_EXT INT16U CTLGetFixPwrSysPhase(INT16U usStep);
CTL_EXT INT16U CTLGetIslandSysPhase(INT16U usStep);
CTL_EXT INT16U CTLGetParallSysPhase(INT16U usStep);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
