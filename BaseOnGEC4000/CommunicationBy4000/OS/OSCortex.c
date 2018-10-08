/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File OSCortex.c                         */
/*                            By: Wu Xuekui                             */
/*                             2014-10-14                               */
/* ******************************************************************** */

#define   OS_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                            Const Section                             */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
const  INT16U usOSMaskTbl[16] = {
    0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080,
    0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000 };
const  INT08U ucOSUnMapTbl[256] = {
    0, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    7, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0 };
#endif

/* ******************************************************************** */
/*                          Extern Functions                            */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
extern void   OSStartHighRdy (void);
extern void   OSTaskStat (void);
extern OS_STK OSStatTaskStk[FW_TASK_STK_SIZE_STAT];
extern OS_STK OSIdleTaskStk[FW_TASK_STK_SIZE_IDLE];
#endif

/* ******************************************************************** */
/*                              OSInit()                                */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
void OSInit (void)
{   INT08U i;
    ucOSRunning     =  0;
    ucOSIntNesting  =  0;
    ucOSPrioCur     =  0;
    ucOSPrioHighRdy =  0;
    usOSRdyIndex    =  0;
    usOSCPUUsage    =  0;
    usOSTimeOverCnt =  0;
    uiOSIdleCtrMax  =  0;
    uiOSIdleCtr     =  0;
    uiOSTime        =  0;
    pOSTCBHighRdy   = (OS_TCB *)0;
    pOSTCBCur       = (OS_TCB *)0;
    pOSTCBFree      = &sOSTCBTbl[0];
    for (i=0; i<16; i++)
    {   pOSTCBPrioTbl[i] = (OS_TCB *)0;
    }
    for (i=0; i<16; i++)
    {   sOSTCBTbl[i].pOSTCBStkPtr   = (OS_STK *)0;
        sOSTCBTbl[i].pOSTCBEventPtr = (OS_EVENT *)0;
        sOSTCBTbl[i].usOSTCBDly     =  0;
        sOSTCBTbl[i].ucOSTCBStat    =  OS_STAT_SUSPEND;
        sOSTCBTbl[i].ucOSTCBPrio    =  0xFF;
        sOSTCBTbl[i].usOSTCBMask    =  0;
    }
    for (i=0; i<15; i++)
    {   sOSTCBTbl[i].pOSTCBNext     = &sOSTCBTbl[i+1];
    }
    sOSTCBTbl[15].pOSTCBNext        = (OS_TCB *)0;
    for (i=0; i<(OS_MAX_EVENTS-1); i++)
    {   sOSEventTbl[i].pOSEventNext = &sOSEventTbl[i+1];
    }
    sOSEventTbl[OS_MAX_EVENTS-1].pOSEventNext = (OS_EVENT *)0;
    pOSEventFreeList = &sOSEventTbl[0];
    (void)OSTaskCreate (OSTaskIdle,
                       &OSIdleTaskStk[0],
                       &OSIdleTaskStk[FW_TASK_STK_SIZE_IDLE],  //任务堆栈栈顶
                        OS_IDLE_PRIO);          //优先级15
    (void)OSTaskCreate (OSTaskStat,
                       &OSStatTaskStk[0],
                       &OSStatTaskStk[FW_TASK_STK_SIZE_STAT],  //任务堆栈栈顶
                        OS_STAT_PRIO);         //优先级14
}
#endif

/* ******************************************************************** */
/*                             OSSched()                                */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
void OSSched (void)
{   OS_CPU_SR cpu_sr = 0;
    OS_ENTER_CRITICAL();
    if (ucOSIntNesting == 0)
    {   if((usOSRdyIndex & 0x00FF) != 0)
        {   ucOSPrioHighRdy = ucOSUnMapTbl[usOSRdyIndex & 0x00FF];
        }   else
        {   ucOSPrioHighRdy = ucOSUnMapTbl[usOSRdyIndex >> 8] + 8;
        }
        if (ucOSPrioHighRdy != ucOSPrioCur)
        {   pOSTCBHighRdy = pOSTCBPrioTbl[ucOSPrioHighRdy];
            OS_TASK_SW();
        }
    }
    OS_EXIT_CRITICAL();
}
#endif

/* ******************************************************************** */
/*                             OSIntEnter()                             */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
void  OSIntEnter (void)
{   if (ucOSIntNesting < 255u)
    {   ucOSIntNesting++;
    }
}
#endif

/* ******************************************************************** */
/*                             OSIntExit()                              */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
void  OSIntExit (void)
{   OS_CPU_SR cpu_sr = 0;
    OS_ENTER_CRITICAL();
    if (ucOSIntNesting != 0)
    {   ucOSIntNesting--;
    }
    if (ucOSIntNesting == 0)
    {   if((usOSRdyIndex & 0x00FF) != 0)
        {   ucOSPrioHighRdy = ucOSUnMapTbl[usOSRdyIndex & 0x00FF];
        }   else
        {   ucOSPrioHighRdy = ucOSUnMapTbl[usOSRdyIndex >> 8] + 8;
        }
        if (ucOSPrioHighRdy != ucOSPrioCur)
        {   pOSTCBHighRdy = pOSTCBPrioTbl[ucOSPrioHighRdy];
            OS_INT_TASK_SW();
        }
    }
    OS_EXIT_CRITICAL();
}
#endif

/* ******************************************************************** */
/*                             OSStart()                                */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
void OSStart (void)
{   if (ucOSRunning == 0)
    {   if((usOSRdyIndex & 0x00FF) != 0)
        {   ucOSPrioHighRdy = ucOSUnMapTbl[usOSRdyIndex & 0x00FF];
        }   else
        {   ucOSPrioHighRdy = ucOSUnMapTbl[usOSRdyIndex >> 8] + 8;
        }
        ucOSPrioCur   = ucOSPrioHighRdy + 1;
        pOSTCBHighRdy = pOSTCBPrioTbl[ucOSPrioHighRdy];
        pOSTCBCur     = pOSTCBHighRdy;
        ucOSRunning   = 1;
        OSStartHighRdy();
    }
}
#endif

/* ******************************************************************** */
/*                         OSGetPrioHighRdy()                           */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
void OSGetPrioHighRdy (void)
{   if((usOSRdyIndex & 0x00FF) != 0)
    {   ucOSPrioHighRdy = ucOSUnMapTbl[usOSRdyIndex & 0x00FF];
    }   else
    {   ucOSPrioHighRdy = ucOSUnMapTbl[usOSRdyIndex >> 8] + 8;
    }
    if (ucOSPrioHighRdy != ucOSPrioCur)
    {   pOSTCBHighRdy = pOSTCBPrioTbl[ucOSPrioHighRdy];
    }
}
#endif

/* ******************************************************************** */
/*                           OSStatInit()                               */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
void OSStatInit (void)
{   OSTimeDly (2);
    uiOSIdleCtr = 0;
    OSTimeDly (OS_TICKS_PER_SEC);
    uiOSIdleCtrMax = uiOSIdleCtr;
}
#endif

/* ******************************************************************** */
/*                           OSTaskIdle()                               */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
void OSTaskIdle (void)
{   for (;;)
    {   uiOSIdleCtr++;
    }
}
#endif

/* ******************************************************************** */
/*                           OSTimeTick()                               */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
void OSTimeTick (void)
{   OS_TCB *ptcb;
    ptcb = &sOSTCBTbl[0];
    while (ptcb->ucOSTCBPrio != 0xFF)
    {   if (ptcb->usOSTCBDly != 0)
        {   if((--ptcb->usOSTCBDly) == 0)
            {   if((ptcb->ucOSTCBStat & OS_STAT_SUSPEND) != 0)
                {   ptcb->usOSTCBDly = 1;
                }   else
                {   usOSRdyIndex |= ptcb->usOSTCBMask;
                }
            }
        }
        ptcb = ptcb->pOSTCBNext;
        if (ptcb == (OS_TCB *)0)
        {   break;
        }
    }
    uiOSTime++;
}
#endif

/* ******************************************************************** */
/*                          OSTaskCreate()                              */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
INT08U OSTaskCreate (void (*task)(), OS_STK *pbot, OS_STK *ptop, INT08U prio)
{   OS_TCB *ptcb;
    OS_STK *stkp;
    if (prio >= 16)
    {   return OS_PRIO_INVALID;
    }
    if (pOSTCBPrioTbl[prio] == (OS_TCB *)0)
    {   stkp      = (OS_STK *)((INT32U)ptop & (INT32U)0xFFFFFFF8);
       #if (OS_CPU_M4_FP_ENABLE == 1)
        *--stkp   = (OS_STK)0x02000000u;                   /* FPSCR     */
        *--stkp   = (OS_STK)0x41700000u;                   /* S15       */
        *--stkp   = (OS_STK)0x41600000u;                   /* S14       */
        *--stkp   = (OS_STK)0x41500000u;                   /* S13       */
        *--stkp   = (OS_STK)0x41400000u;                   /* S12       */
        *--stkp   = (OS_STK)0x41300000u;                   /* S11       */
        *--stkp   = (OS_STK)0x41200000u;                   /* S10       */
        *--stkp   = (OS_STK)0x41100000u;                   /* S9        */
        *--stkp   = (OS_STK)0x41000000u;                   /* S8        */
        *--stkp   = (OS_STK)0x40E00000u;                   /* S7        */
        *--stkp   = (OS_STK)0x40C00000u;                   /* S6        */
        *--stkp   = (OS_STK)0x40A00000u;                   /* S5        */
        *--stkp   = (OS_STK)0x40800000u;                   /* S4        */
        *--stkp   = (OS_STK)0x40400000u;                   /* S3        */
        *--stkp   = (OS_STK)0x40000000u;                   /* S2        */
        *--stkp   = (OS_STK)0x3F800000u;                   /* S1        */
        *--stkp   = (OS_STK)0x00000000u;                   /* S0        */
       #endif
        *--stkp   = (OS_STK)0x01000000u;
        *--stkp   = (OS_STK)task;
        *--stkp   = (OS_STK)0xFFFFFFFEu;
        *--stkp   = (OS_STK)0x12121212u;
        *--stkp   = (OS_STK)0x03030303u;
        *--stkp   = (OS_STK)0x02020202u;
        *--stkp   = (OS_STK)0x01010101u;
        *--stkp   = (OS_STK)0x00000000u;
        *--stkp   = (OS_STK)0x11111111u;
        *--stkp   = (OS_STK)0x10101010u;
        *--stkp   = (OS_STK)0x09090909u;
        *--stkp   = (OS_STK)0x08080808u;
        *--stkp   = (OS_STK)0x07070707u;
        *--stkp   = (OS_STK)0x06060606u;
        *--stkp   = (OS_STK)0x05050505u;
        *--stkp   = (OS_STK)0x04040404u;
       #if (OS_CPU_M4_FP_ENABLE == 1)
        *--stkp   = (OS_STK)0x41F80000u;                   /* S31       */
        *--stkp   = (OS_STK)0x41F00000u;                   /* S30       */
        *--stkp   = (OS_STK)0x41E80000u;                   /* S29       */
        *--stkp   = (OS_STK)0x41E00000u;                   /* S28       */
        *--stkp   = (OS_STK)0x41D80000u;                   /* S27       */
        *--stkp   = (OS_STK)0x41D00000u;                   /* S26       */
        *--stkp   = (OS_STK)0x41C80000u;                   /* S25       */
        *--stkp   = (OS_STK)0x41C00000u;                   /* S24       */
        *--stkp   = (OS_STK)0x41B80000u;                   /* S23       */
        *--stkp   = (OS_STK)0x41B00000u;                   /* S22       */
        *--stkp   = (OS_STK)0x41A80000u;                   /* S21       */
        *--stkp   = (OS_STK)0x41A00000u;                   /* S20       */
        *--stkp   = (OS_STK)0x41980000u;                   /* S19       */
        *--stkp   = (OS_STK)0x41900000u;                   /* S18       */
        *--stkp   = (OS_STK)0x41880000u;                   /* S17       */
        *--stkp   = (OS_STK)0x41800000u;                   /* S16       */
       #endif
        ptcb      =  pOSTCBFree;
        if (ptcb != (OS_TCB *)0)
        {   pOSTCBFree           =  ptcb->pOSTCBNext;
            ptcb->pOSTCBStkPtr   =  stkp;
            ptcb->pOSTCBEventPtr = (OS_EVENT *)0;
            ptcb->usOSTCBDly     =  0;
            ptcb->ucOSTCBStat    =  OS_STAT_RDY;
            ptcb->ucOSTCBPrio    =  prio;
            ptcb->usOSTCBMask    =  usOSMaskTbl[prio];
            pOSTCBPrioTbl[prio]  =  ptcb;
            usOSRdyIndex        |=  usOSMaskTbl[prio];
            while (stkp > pbot)
            {   *--stkp = 0;
            }
            if (ucOSRunning != 0)
            {   OSSched();
            }
            return OS_NO_ERR;
        }   else
        {   return OS_NO_MORE_TCB;
        }        
    }
    return OS_PRIO_EXIST;
}
#endif

/* ******************************************************************** */
/*                          OSTaskSuspend()                             */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
INT08U OSTaskSuspend (INT08U prio)
{   OS_CPU_SR cpu_sr = 0;
    OS_TCB   *ptcb;
    BOOLEAN   self;
    if ((prio >= 15) && (prio != OS_PRIO_SELF))
    {   return OS_PRIO_INVALID;
    }
    OS_ENTER_CRITICAL();
    if (prio == OS_PRIO_SELF)
    {   prio  = pOSTCBCur->ucOSTCBPrio;
        self  = OS_TRUE;
    }   else if (prio == pOSTCBCur->ucOSTCBPrio)
    {   self  = OS_TRUE;
    }   else
    {   self  = OS_FALSE;
    }
    ptcb = pOSTCBPrioTbl[prio];
    if (ptcb == (OS_TCB *)0)
    {   OS_EXIT_CRITICAL();
        return OS_TASK_SUSPEND_PRIO;
    }   else
    {   usOSRdyIndex      &= ~ptcb->usOSTCBMask;
        ptcb->ucOSTCBStat |=  OS_STAT_SUSPEND;
        OS_EXIT_CRITICAL();
        if (self != OS_FALSE)
        {   OSSched();
        }
        return OS_NO_ERR;
    }
}
#endif

/* ******************************************************************** */
/*                          OSTaskResume()                              */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
INT08U OSTaskResume (INT08U prio)
{   OS_CPU_SR cpu_sr = 0;
    OS_TCB   *ptcb;
    if (prio >= 15)
    {   return OS_PRIO_INVALID;
    }
    OS_ENTER_CRITICAL();
    ptcb = pOSTCBPrioTbl[prio];
    if (ptcb == (OS_TCB *)0)
    {   OS_EXIT_CRITICAL();
        return OS_TASK_RESUME_PRIO;
    }
    else if((ptcb->ucOSTCBStat & OS_STAT_SUSPEND) != 0)
    {   if(((ptcb->ucOSTCBStat &= ~OS_STAT_SUSPEND) == OS_STAT_RDY) &&
            (ptcb->usOSTCBDly  ==  0))
        {   usOSRdyIndex |= ptcb->usOSTCBMask;
            OS_EXIT_CRITICAL();
            OSSched();
        }   else
        {   OS_EXIT_CRITICAL();
        }
        return OS_NO_ERR;
    }
    else
    {   OS_EXIT_CRITICAL();
        return OS_TASK_NOT_SUSPENDED;
    }
}
#endif

/* ******************************************************************** */
/*                         OSIntTaskResume()                            */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
INT08U OSIntTaskResume (INT08U prio)
{   OS_CPU_SR cpu_sr = 0;
    OS_TCB   *ptcb;
    if (prio >= 15)
    {   return OS_PRIO_INVALID;
    }
    OS_ENTER_CRITICAL();
    ptcb = pOSTCBPrioTbl[prio];
    if (ptcb == (OS_TCB *)0)
    {   OS_EXIT_CRITICAL();
        return OS_TASK_RESUME_PRIO;
    }
    else if((ptcb->ucOSTCBStat & OS_STAT_SUSPEND) != 0)
    {   if(((ptcb->ucOSTCBStat &= ~OS_STAT_SUSPEND) == OS_STAT_RDY) &&
            (ptcb->usOSTCBDly  ==  0))
        {   usOSRdyIndex |= ptcb->usOSTCBMask;
        }
        OS_EXIT_CRITICAL();
        return OS_NO_ERR;
    }
    else
    {   OS_EXIT_CRITICAL();
        return OS_TASK_NOT_SUSPENDED;
    }
}
#endif

/* ******************************************************************** */
/*                            OSTimeDly()                               */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
void OSTimeDly (INT16U ticks)
{   OS_CPU_SR cpu_sr = 0;
    if (ticks > 0)
    {   OS_ENTER_CRITICAL();
        usOSRdyIndex &= ~pOSTCBCur->usOSTCBMask;
        pOSTCBCur->usOSTCBDly = ticks;
        OS_EXIT_CRITICAL();
        OSSched();
    }
}
#endif

/* ******************************************************************** */
/*                         OSTimeDlyResume()                            */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
INT08U OSTimeDlyResume (INT08U prio)
{   OS_CPU_SR cpu_sr = 0;
    OS_TCB   *ptcb;
    if (prio >= 15)
    {   return OS_PRIO_INVALID;
    }
    OS_ENTER_CRITICAL();
    ptcb = pOSTCBPrioTbl[prio];
    if (ptcb == (OS_TCB *)0)
    {   OS_EXIT_CRITICAL();
        return OS_TASK_NOT_EXIST;
    }
    else if (ptcb->usOSTCBDly != 0)
    {   ptcb->usOSTCBDly = 0;
        if ((ptcb->ucOSTCBStat & OS_STAT_SUSPEND) != 0)
        {   OS_EXIT_CRITICAL();
        }   else
        {   usOSRdyIndex |= ptcb->usOSTCBMask;
            OS_EXIT_CRITICAL();
            OSSched();
        }
        return OS_NO_ERR;
    }
    else
    {   OS_EXIT_CRITICAL();
        return OS_TIME_NOT_DLY;
    }
}
#endif

/* ******************************************************************** */
/*                       OSIntTimeDlyResume()                           */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
INT08U OSIntTimeDlyResume (INT08U prio)
{   OS_CPU_SR cpu_sr = 0;
    OS_TCB   *ptcb;
    if (prio >= 15)
    {   return OS_PRIO_INVALID;
    }
    OS_ENTER_CRITICAL();
    ptcb = pOSTCBPrioTbl[prio];
    if (ptcb == (OS_TCB *)0)
    {   OS_EXIT_CRITICAL();
        return OS_TASK_NOT_EXIST;
    }
    else if (ptcb->usOSTCBDly != 0)
    {   ptcb->usOSTCBDly  = 0;
        if ((ptcb->ucOSTCBStat & OS_STAT_SUSPEND) == 0)
        {   usOSRdyIndex |= ptcb->usOSTCBMask;
        }
        OS_EXIT_CRITICAL();
        return OS_NO_ERR;
    }
    else
    {   OS_EXIT_CRITICAL();
        return OS_TIME_NOT_DLY;
    }
}
#endif

/* ******************************************************************** */
/*                           OSCheckStack()                             */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
INT16U OSCheckStack (OS_STK *pbot, INT16U size)
{   INT16U used  = size;
    OS_STK *pchk = pbot;
    while (used--)
    {   if (*pchk++ != 0)
        {   break;
        }
    }
    if (size == 0)
    {   return 100;
    }   else
    {   return used * 100 / size;
    }
}
#endif

/* ******************************************************************** */
/*                            OSTimeGet()                               */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
INT32U OSTimeGet (void)
{   return uiOSTime;
}
#endif

/* ******************************************************************** */
/*                            OSTimeSet()                               */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
void OSTimeSet (INT32U ticks)
{   uiOSTime = ticks;
}
#endif

/* ******************************************************************** */
/*                           OSSemCreate()                              */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
OS_EVENT *OSSemCreate (INT16U cnt)
{   OS_CPU_SR cpu_sr = 0;
    OS_EVENT *pevent;
    OS_ENTER_CRITICAL();
    pevent = pOSEventFreeList;
    if (pOSEventFreeList != (OS_EVENT *)0)
    {   pOSEventFreeList  = (OS_EVENT *)pOSEventFreeList->pOSEventNext;
    }
    OS_EXIT_CRITICAL();
    if (pevent != (OS_EVENT *)0)
    {   pevent->ucOSEventType  = OS_EVENT_TYPE_SEM;
        pevent->usOSEventIndex = 0x0000;
        pevent->usOSEventCnt   = cnt;
    }
    return pevent;
}
#endif

/* ******************************************************************** */
/*                           OSSemAccept()                              */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
INT16U OSSemAccept (OS_EVENT *pevent)
{   OS_CPU_SR cpu_sr = 0;
    INT16U cnt;
    OS_ENTER_CRITICAL();
    if (pevent->ucOSEventType != OS_EVENT_TYPE_SEM)
    {   OS_EXIT_CRITICAL();
        return 0;
    }
    cnt = pevent->usOSEventCnt;
    if (cnt > 0)
    {   pevent->usOSEventCnt--;
    }
    OS_EXIT_CRITICAL();
    return cnt;
}
#endif

/* ******************************************************************** */
/*                            OSSemPend()                               */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
void OSSemPend (OS_EVENT *pevent, INT16U timeout, INT08U *err)
{   OS_CPU_SR cpu_sr = 0;
    OS_ENTER_CRITICAL();
    if (pevent->ucOSEventType != OS_EVENT_TYPE_SEM)
    {   OS_EXIT_CRITICAL();
        *err = OS_ERR_EVENT_TYPE;
    }   else if (pevent->usOSEventCnt > 0)
    {   pevent->usOSEventCnt--;
        OS_EXIT_CRITICAL();
        *err = OS_NO_ERR;
    }   else if (timeout == 0)
    {   OS_EXIT_CRITICAL();
        *err = OS_TIMEOUT;
    }   else if (ucOSIntNesting > 0)
    {   OS_EXIT_CRITICAL();
        *err = OS_ERR_PEND_ISR;
    }   else
    {   pOSTCBCur->ucOSTCBStat   |=  OS_STAT_SEM;
        pOSTCBCur->pOSTCBEventPtr =  pevent;
        pOSTCBCur->usOSTCBDly     =  timeout;
        usOSRdyIndex             &= ~pOSTCBCur->usOSTCBMask;
        pevent->usOSEventIndex   |=  pOSTCBCur->usOSTCBMask;
        OS_EXIT_CRITICAL();
        OSSched();
        OS_ENTER_CRITICAL();
        if((pOSTCBCur->ucOSTCBStat & OS_STAT_SEM) != 0)
        {   pOSTCBCur->ucOSTCBStat    =  OS_STAT_RDY;
            pOSTCBCur->pOSTCBEventPtr = (OS_EVENT *)0;
            pevent->usOSEventIndex   &= ~pOSTCBCur->usOSTCBMask;
            OS_EXIT_CRITICAL();
            *err = OS_TIMEOUT;
        }   else
        {   pOSTCBCur->pOSTCBEventPtr = (OS_EVENT *)0;
            OS_EXIT_CRITICAL();
            *err = OS_NO_ERR;
        }
    }
}
#endif

/* ******************************************************************** */
/*                            OSSemPost()                               */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
INT08U OSSemPost (OS_EVENT *pevent)
{   OS_CPU_SR cpu_sr = 0;
    INT08U  prio;
    OS_TCB *ptcb;
    OS_ENTER_CRITICAL();
    if (pevent->ucOSEventType != OS_EVENT_TYPE_SEM)
    {   OS_EXIT_CRITICAL();
        return OS_ERR_EVENT_TYPE;
    }   else if (pevent->usOSEventIndex != 0)
    {   if((pevent->usOSEventIndex & 0x00FF) != 0)
        {   prio = ucOSUnMapTbl[pevent->usOSEventIndex & 0x00FF];
        }   else
        {   prio = ucOSUnMapTbl[pevent->usOSEventIndex >> 8] + 8;
        }
        ptcb                    =  pOSTCBPrioTbl[prio];
        pevent->usOSEventIndex &= ~ptcb->usOSTCBMask;
        ptcb->usOSTCBDly        =  0;
        ptcb->pOSTCBEventPtr    = (OS_EVENT *)0;
        ptcb->ucOSTCBStat      &= ~OS_STAT_SEM;
        if (ptcb->ucOSTCBStat  ==  OS_STAT_RDY)
        {   usOSRdyIndex       |=  ptcb->usOSTCBMask;
        }
        OS_EXIT_CRITICAL();
        OSSched();
        return OS_NO_ERR;
    }   else if (pevent->usOSEventCnt < 65535)
    {   pevent->usOSEventCnt++;
        OS_EXIT_CRITICAL();
        return OS_NO_ERR;
    }   else
    {   OS_EXIT_CRITICAL();
        return OS_SEM_OVF;
    }
}
#endif

/* ******************************************************************** */
/*                          OSIntSemPost()                              */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
INT08U OSIntSemPost (OS_EVENT *pevent)
{   OS_CPU_SR cpu_sr = 0;
    INT08U  prio;
    OS_TCB *ptcb;
    OS_ENTER_CRITICAL();
    if (pevent->ucOSEventType != OS_EVENT_TYPE_SEM)
    {   OS_EXIT_CRITICAL();
        return OS_ERR_EVENT_TYPE;
    }   else if (pevent->usOSEventIndex != 0)
    {   if((pevent->usOSEventIndex & 0x00FF) != 0)
        {   prio = ucOSUnMapTbl[pevent->usOSEventIndex & 0x00FF];
        }   else
        {   prio = ucOSUnMapTbl[pevent->usOSEventIndex >> 8] + 8;
        }
        ptcb                    =  pOSTCBPrioTbl[prio];
        pevent->usOSEventIndex &= ~ptcb->usOSTCBMask;
        ptcb->usOSTCBDly        =  0;
        ptcb->pOSTCBEventPtr    = (OS_EVENT *)0;
        ptcb->ucOSTCBStat      &= ~OS_STAT_SEM;
        if (ptcb->ucOSTCBStat  ==  OS_STAT_RDY)
        {   usOSRdyIndex       |=  ptcb->usOSTCBMask;
        }
        OS_EXIT_CRITICAL();
        return OS_NO_ERR;
    }   else if (pevent->usOSEventCnt < 65535)
    {   pevent->usOSEventCnt++;
        OS_EXIT_CRITICAL();
        return OS_NO_ERR;
    }   else
    {   OS_EXIT_CRITICAL();
        return OS_SEM_OVF;
    }
}
#endif

/* ******************************************************************** */
/*                           OSInitTimer()                              */
/* ******************************************************************** */
#if (OS_OS_FUNCTION_ON == 1)
void OSInitTimer (void)
{   SysTick->LOAD  = FW_FRQ_SYS / OS_TICKS_PER_SEC - 1;    //1/200=5ms
    SysTick->VAL   = 0;
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk
                  |  SysTick_CTRL_TICKINT_Msk
                  |  SysTick_CTRL_ENABLE_Msk;  
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
