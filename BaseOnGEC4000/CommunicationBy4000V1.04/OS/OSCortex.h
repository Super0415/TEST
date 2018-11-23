/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File OSCortex.h                         */
/*                            By: Wu Xuekui                             */
/*                              2016-1-14                               */
/* ******************************************************************** */

#ifndef _OSCORTEX_H

#define _OSCORTEX_H

#ifdef   OS_GLOBALS

#define  OS_EXT  

#else

#define  OS_EXT extern

#endif

/* ******************************************************************** */
/*  OS_VERSION  = 10xx: VEC1000 Application                             */
/*  OS_VERSION  = 40xx: VEC4000 Application                             */
/*  OS_VERSION  = 68xx: VEC6800 Application                             */
/*  OS_VERSION  = 69xx: VEC6900 Application                             */
/*  OS_VERSION  = 760x: GEC7600-Main Application                        */
/*  OS_VERSION  = 761x: GEC7600-Display Application                     */
/*  OS_VERSION  = 780x: GEC7800-Main Application                        */
/*  OS_VERSION  = 781x: GEC7800-Display Application                     */
/*  OS_VERSION  = 80xx: VEC8000 Application                             */
/*  OS_VERSION  = 90xx: VEC9000 Application                             */
/*  OS_VERSION  = 96xx: VEC9600 Application                             */
/* ******************************************************************** */

#define OS_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define OS_1000_COMMON_ON       0
#define OS_4000_COMMON_ON       0
#define OS_6800_COMMON_ON       0
#define OS_6900_COMMON_ON       0
#define OS_7600_COMMON_ON       0
#define OS_7600_MAIN_CHIP_ON    0
#define OS_7600_AUX_CHIP_ON     0
#define OS_7800_COMMON_ON       0
#define OS_7800_MAIN_CHIP_ON    0
#define OS_7800_AUX_CHIP_ON     0
#define OS_8000_COMMON_ON       0
#define OS_9000_COMMON_ON       0
#define OS_9600_COMMON_ON       0
#if   ((OS_VERSION / 100)   == 10)
#undef  OS_1000_COMMON_ON
#define OS_1000_COMMON_ON       1
#endif
#if   ((OS_VERSION / 100)   == 40)
#undef  OS_4000_COMMON_ON
#define OS_4000_COMMON_ON       1
#endif
#if   ((OS_VERSION / 100)   == 68)
#undef  OS_6800_COMMON_ON
#define OS_6800_COMMON_ON       1
#endif
#if   ((OS_VERSION / 100)   == 69)
#undef  OS_6900_COMMON_ON
#define OS_6900_COMMON_ON       1
#endif
#if   ((OS_VERSION / 100)   == 76)
#undef  OS_7600_COMMON_ON
#define OS_7600_COMMON_ON       1
#endif
#if   ((OS_VERSION / 10)   == 760)
#undef  OS_7600_MAIN_CHIP_ON
#define OS_7600_MAIN_CHIP_ON    1
#endif
#if   ((OS_VERSION / 10)   == 761)
#undef  OS_7600_AUX_CHIP_ON
#define OS_7600_AUX_CHIP_ON     1
#endif
#if   ((OS_VERSION / 100)   == 78)
#undef  OS_7800_COMMON_ON
#define OS_7800_COMMON_ON       1
#endif
#if   ((OS_VERSION / 10)   == 780)
#undef  OS_7800_MAIN_CHIP_ON
#define OS_7800_MAIN_CHIP_ON    1
#endif
#if   ((OS_VERSION / 10)   == 781)
#undef  OS_7800_AUX_CHIP_ON
#define OS_7800_AUX_CHIP_ON     1
#endif
#if   ((OS_VERSION / 100)   == 80)
#undef  OS_8000_COMMON_ON
#define OS_8000_COMMON_ON       1
#endif
#if   ((OS_VERSION / 100)   == 90)
#undef  OS_9000_COMMON_ON
#define OS_9000_COMMON_ON       1
#endif
#if   ((OS_VERSION / 100)   == 96)
#undef  OS_9600_COMMON_ON
#define OS_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define OS_OS_FUNCTION_ON       1
#define OS_CPU_9S12_ON          0
#define OS_CPU_POWERPC_ON       0
#define OS_CPU_STM32F1_ON       0
#define OS_CPU_STM32F103_ON     0
#define OS_CPU_STM32F105_ON     0
#define OS_CPU_M4_FP_ENABLE     0
#if    (OS_1000_COMMON_ON    == 1)
#undef  OS_CPU_9S12_ON
#define OS_CPU_9S12_ON          1
#endif
#if    (OS_4000_COMMON_ON    == 1)
#undef  OS_CPU_9S12_ON
#define OS_CPU_9S12_ON          1
#endif
#if    (OS_6800_COMMON_ON    == 1)
#undef  OS_CPU_9S12_ON
#define OS_CPU_9S12_ON          1
#endif
#if    (OS_6900_COMMON_ON    == 1)
#undef  OS_CPU_POWERPC_ON
#define OS_CPU_POWERPC_ON       1
#endif
#if    (OS_7600_COMMON_ON    == 1)
#undef  OS_CPU_STM32F1_ON
#define OS_CPU_STM32F1_ON       1
#endif
#if    (OS_7600_MAIN_CHIP_ON == 1)
#undef  OS_CPU_STM32F105_ON
#define OS_CPU_STM32F105_ON     1
#endif
#if    (OS_7600_AUX_CHIP_ON  == 1)
#undef  OS_CPU_STM32F103_ON
#define OS_CPU_STM32F103_ON     1
#endif
#if    (OS_7800_COMMON_ON    == 1)
#undef  OS_CPU_STM32F1_ON
#define OS_CPU_STM32F1_ON       1
#endif
#if    (OS_7800_MAIN_CHIP_ON == 1)
#undef  OS_CPU_STM32F105_ON
#define OS_CPU_STM32F105_ON     1
#endif
#if    (OS_7800_AUX_CHIP_ON  == 1)
#undef  OS_CPU_STM32F103_ON
#define OS_CPU_STM32F103_ON     1
#endif
#if    (OS_8000_COMMON_ON    == 1)
#undef  OS_CPU_POWERPC_ON
#define OS_CPU_POWERPC_ON       1
#endif
#if    (OS_9000_COMMON_ON    == 1)
#undef  OS_CPU_POWERPC_ON
#define OS_CPU_POWERPC_ON       1
#endif
#if    (OS_9600_COMMON_ON    == 1)
#undef  OS_CPU_POWERPC_ON
#define OS_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                           Basis Definition                           */
/* ******************************************************************** */
#define OS_TRUE                 (INT08U)0x01
#define OS_FALSE                (INT08U)0x00
#define OS_NULL                 (INT08U)0x00
#define OS_STAT_PRIO            (INT08U)14
#define OS_IDLE_PRIO            (INT08U)15
#define OS_PRIO_SELF            (INT08U)0xFF
#define OS_STAT_RDY             (INT08U)0x00
#define OS_STAT_SEM             (INT08U)0x01
#define OS_STAT_MBOX            (INT08U)0x02
#define OS_STAT_Q               (INT08U)0x04
#define OS_STAT_SUSPEND         (INT08U)0x08
#if    (OS_CPU_STM32F1_ON == 1)
#define OS_ENTER_CRITICAL()      cpu_sr = OS_CPU_SR_Save()
#define OS_EXIT_CRITICAL()       OS_CPU_SR_Restore(cpu_sr)
#define OS_TASK_SW()             OSCtxSw()
#define OS_INT_TASK_SW()         OSIntCtxSw()
#define OS_TICKS_PER_SEC         200
#define OS_MAX_EVENTS            16
#define OS_INT_EN()              __asm(" CPSIE I")
#define OS_INT_DIS()             __asm(" CPSID I")
#endif

/* ******************************************************************** */
/*                             Error Codes                              */
/* ******************************************************************** */
#define OS_NO_ERR               (INT08U)0
#define OS_ERR_EVENT_TYPE       (INT08U)1
#define OS_ERR_PEND_ISR         (INT08U)2
#define OS_ERR_BAD_CH           (INT08U)3
#define OS_ERR_RX_EMPTY         (INT08U)4
#define OS_ERR_TX_FULL          (INT08U)5
#define OS_ERR_TX_EMPTY         (INT08U)6
#define OS_ERR_RX_TIMEOUT       (INT08U)7
#define OS_ERR_TX_TIMEOUT       (INT08U)8
#define OS_TIMEOUT              (INT08U)10
#define OS_TASK_NOT_EXIST       (INT08U)11
#define OS_MBOX_FULL            (INT08U)20
#define OS_Q_FULL               (INT08U)30
#define OS_PRIO_EXIST           (INT08U)40
#define OS_PRIO_ERR             (INT08U)41
#define OS_PRIO_INVALID         (INT08U)42
#define OS_SEM_OVF              (INT08U)50
#define OS_TASK_DEL_ERR         (INT08U)60
#define OS_TASK_DEL_IDLE        (INT08U)61
#define OS_TASK_DEL_REQ         (INT08U)62
#define OS_TASK_DEL_ISR         (INT08U)63
#define OS_NO_MORE_TCB          (INT08U)70
#define OS_TIME_NOT_DLY         (INT08U)80
#define OS_TIME_INVALID_MINUTES (INT08U)81
#define OS_TIME_INVALID_SECONDS (INT08U)82
#define OS_TIME_INVALID_MILLI   (INT08U)83
#define OS_TIME_ZERO_DLY        (INT08U)84
#define OS_TASK_SUSPEND_PRIO    (INT08U)90
#define OS_TASK_SUSPEND_IDLE    (INT08U)91
#define OS_TASK_RESUME_PRIO     (INT08U)100
#define OS_TASK_NOT_SUSPENDED   (INT08U)101
#define OS_MEM_INVALID_PART     (INT08U)110
#define OS_MEM_INVALID_BLKS     (INT08U)111
#define OS_MEM_INVALID_SIZE     (INT08U)112
#define OS_MEM_NO_FREE_BLKS     (INT08U)113
#define OS_MEM_FULL             (INT08U)114
#define OS_TASK_OPT_ERR         (INT08U)130
#define OS_EVENT_TYPE_MBOX      (INT08U)1
#define OS_EVENT_TYPE_Q         (INT08U)2
#define OS_EVENT_TYPE_SEM       (INT08U)3

/* ******************************************************************** */
/*                            Type Definition                           */
/* ******************************************************************** */
typedef struct       os_event
{   struct os_event *pOSEventNext;
    INT08U           ucOSEventType;
    INT16U           usOSEventIndex;
    INT16U           usOSEventCnt;
}   OS_EVENT;

typedef struct       os_tcb
{   OS_STK          *pOSTCBStkPtr;
    struct os_tcb   *pOSTCBNext;
    OS_EVENT        *pOSTCBEventPtr;
    INT16U           usOSTCBDly;
    INT08U           ucOSTCBStat;
    INT08U           ucOSTCBPrio;
    INT16U           usOSTCBMask;
}   OS_TCB;

/* ******************************************************************** */
/*                           Variable Definition                        */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
OS_EXT INT08U   ucOSRunning,
                ucOSIntNesting,
                ucOSPrioCur,
                ucOSPrioHighRdy,
                ucOSGpageTemp;
OS_EXT INT16U   usOSRdyIndex,
                usOSCPUUsage,
                usOSTimeOverCnt;
OS_EXT INT32U   uiOSIdleCtrMax,
                uiOSIdleCtr,
                uiOSTime;
OS_EXT OS_TCB   *pOSTCBHighRdy,
                *pOSTCBCur,
                *pOSTCBFree,
                *pOSTCBPrioTbl[16],
                sOSTCBTbl[16];
OS_EXT OS_EVENT *pOSEventFreeList,
                sOSEventTbl[OS_MAX_EVENTS];
#endif

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
OS_EXT void     OSInit(void);
OS_EXT void     OSSched(void);
OS_EXT void     OSIntEnter(void);
OS_EXT void     OSIntExit(void);
OS_EXT void     OSStart(void);
OS_EXT void     OSStatInit(void);
OS_EXT void     OSTaskIdle(void);
OS_EXT void     OSTimeTick(void);
OS_EXT void     OSInitTimer(void);
OS_EXT void     OSGetPrioHighRdy(void);
OS_EXT INT08U   OSTaskCreate(void (*task)(), OS_STK *pbot, OS_STK *ptop, INT08U prio);
OS_EXT INT08U   OSTaskSuspend(INT08U prio);
OS_EXT INT08U   OSTaskResume(INT08U prio);
OS_EXT INT08U   OSIntTaskResume(INT08U prio);
OS_EXT void     OSTimeDly(INT16U ticks);
OS_EXT INT08U   OSTimeDlyResume(INT08U prio);
OS_EXT INT08U   OSIntTimeDlyResume(INT08U prio);
OS_EXT INT16U   OSCheckStack(OS_STK *pbot, INT16U size);
OS_EXT INT32U   OSTimeGet(void);
OS_EXT void     OSTimeSet(INT32U ticks);
OS_EXT OS_EVENT *OSSemCreate(INT16U cnt);
OS_EXT INT16U   OSSemAccept(OS_EVENT *pevent);
OS_EXT void     OSSemPend(OS_EVENT *pevent, INT16U timeout, INT08U *err);
OS_EXT INT08U   OSSemPost(OS_EVENT *pevent);
OS_EXT INT08U   OSIntSemPost(OS_EVENT *pevent);
#endif

/* ******************************************************************** */
/*                            ASM Functions                             */
/* ******************************************************************** */
extern OS_CPU_SR OS_CPU_SR_Save(void);
extern void OS_CPU_SR_Restore(OS_CPU_SR cpu_sr);
extern void OSCtxSw(void);
extern void OSIntCtxSw(void);
extern void OS_CPU_S16_31_Push(OS_STK *stkPtr);
extern void OS_CPU_S16_31_Pop(OS_STK *stkPtr);

/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
