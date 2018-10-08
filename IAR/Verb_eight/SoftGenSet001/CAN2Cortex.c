/* ******************************************************************** */
/*                  CAN2 Software for Elctronic Unit (V1.0)             */
/*                       Source File CAN2Cortex.c                       */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   CAN2_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*   CAN2 Message Structure                                             */
/*   ID: 0~7 Address, 8~31 Special Code                                 */
/*   0: Engine State (Low)                                              */
/*   1: Engine State (High)                                             */
/*   2: Rated Act Power (Low)                                           */
/*   3: Rated Act Power (High)                                          */
/*   4: Rated React Power (Low)                                         */
/*   5: Rated React Power (High)                                        */
/*   6: Current Persent of Act Power                                    */
/*   7: Current Persent of React Power                                  */
/* ******************************************************************** */

/* ******************************************************************** */
/*                              CAN2Init()                              */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2Init (void)
{   uiCAN2Status         = 0;
    ucCAN2NumOfTotal     = 0;
    ucCAN2NumOfNotStop   = 0;
    ucCAN2NumOfSwNotOff  = 0;
    ucCAN2NumOfNotLocked = 0;
    ucCAN2TxSwLockCmd    = 0;
    ucCAN2RxSwLockCmd    = 0;
    pCAN2EngThis         = &sCAN2EngTbl[0];
    pCAN2EngLeader       = &sCAN2EngTbl[0];
    pCAN2EngToStop       = &sCAN2EngTbl[0];
    pCAN2EngToSwOn       = &sCAN2EngTbl[0];
    pCAN2EngToStart      = &sCAN2EngTbl[0];
    CAN2BufInit();
    CAN2EngTblInit();
    if (usDBpCan2Baudrate == 125)
    {   CAN2HardInit(125);
    }   else if (usDBpCan2Baudrate == 250)
    {   CAN2HardInit(250);
    }   else if (usDBpCan2Baudrate == 500)
    {   CAN2HardInit(500);
    }   else if (usDBpCan2Baudrate == 1000)
    {   CAN2HardInit(1000);
    }   else
    {   CAN2HardInit(CAN2_BAUDRATE_DEF);
    }
}
#endif

/* ******************************************************************** */
/*                             CAN2Start()                              */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2Start (void)
{   CAN2_TC_INT_DIS();
    CAN2_RX_INT_EN();
    FWIrqEnable(CAN2_TX_IRQn , 0);
    FWIrqEnable(CAN2_RX0_IRQn, 0);
    FWIrqEnable(CAN2_RX1_IRQn, 0);
    FWIrqEnable(CAN2_SCE_IRQn, 0);
}
#endif

/* ******************************************************************** */
/*                            CAN2TaskLoop()                            */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2TaskLoop (void)
{   CAN2_LS_TCB *pThis;
    pThis = &sCAN2EngTbl[0];
    while (1)
    {   OSTimeDly(OS_TICKS_PER_SEC / CAN2_TASK_FRQ);
        /* ********************** CAN2 RX Message ********************* */
        while (CAN2IsRxBufEmpty() == CAN2_FALSE)
        {   (void)CAN2GetMsgFmRxBuf(0, &sCAN2TaskRxMsg);
            (void)CAN2PutRxMsgToEngTbl(&sCAN2TaskRxMsg);
        }
        /* ********************** CAN2 TX Message ********************* */
        if (SFCheckTime(pThis->usTime, pThis->usPeriod) != SF_FALSE)
        {   pThis->usTime = usFW5msTimer;
            (void)CAN2CheckRxTblTimeOut();
            (void)CAN2SetupTxEngTcb(pThis);
            (void)CAN2ProcessEngTbl();
            (void)CAN2SetupTxCanMsg(&sCAN2TaskTxMsg, pThis);
            if (CAN2PutMsgToTxBuf(10,&sCAN2TaskTxMsg) == CAN2_NO_ERR)
            {   CAN2_STS_CLR_BIT(CAN2_STS_TX_ERR);
            }   else
            {   CAN2_STS_SET_BIT(CAN2_STS_TX_ERR);
            }
        }
    }
}
#endif

/* ******************************************************************** */
/*                           CAN2EngTblInit()                           */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2EngTblInit (void)
{   INT32U i;
    CAN2_LS_TCB *pEng;
    pEng             = &sCAN2EngTbl[0];
    pEng->ucState    = CAN2_NO_ERR;
    pEng->ucPriority = (INT08U)usDBpCan2Address;
    pEng->usTime     = usFW5msTimer;
    pEng->usPeriod   = CAN2_LS_TX_TICKS;
    pEng->uiID       = CAN2_LS_GET_ID32(usDBpCan2Address);
    CAN2SetupTxEngTcb(pEng);
    CAN2DecodeEngTcb(pEng);
    for (i=1; i<CAN2_LS_TBL_SIZE; i++)
    {   pEng               = &sCAN2EngTbl[i];
        pEng->ucState      = CAN2_ERR_RX_TIMEOUT;
        pEng->ucPriority   = 255;
        pEng->ucAutoOrHand = 0;
        pEng->ucErrCmdMod  = 0;
        pEng->ucPhase      = CAN2_LS_STEP_STOPPED;
        pEng->ucSwStatus   = SF_SW_STS_SWOFF_ED;
        pEng->ucSwLocked   = 0;
        pEng->ucSwLockReq  = 0;
        pEng->ucActPrsnt   = 0;
        pEng->ucRctPrsnt   = 0;
        pEng->usEngState   = 0;
        pEng->usActRated   = 0;
        pEng->usRctRated   = 0;
        pEng->usActLoad    = 0;
        pEng->usRctLoad    = 0;
        pEng->usTime       = usFW5msTimer;
        pEng->usPeriod     = CAN2_LS_RX_TO_TICKS;
        pEng->uiID         = 0;
    }
}
#endif

/* ******************************************************************** */
/*                          CAN2SetupTxEngTcb()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2SetupTxEngTcb (CAN2_LS_TCB *pEng)
{   usDBmCanSchedTxEngState = CAN2GetEngState(usDBmSystemPhase);
    pEng->usEngState = usDBmCanSchedTxEngState;
    pEng->usActRated = usDBpGensActPwrRated;
    pEng->usRctRated = usDBpGensReactPwrRated;
    if (usDBpGensActPwrRated == 0)
    {   pEng->ucActPrsnt = 0;
    }   else
    {   pEng->ucActPrsnt = SF_PRSNT_08U(usDBmGensActPowerAll,usDBpGensActPwrRated);
    }
    if (usDBpGensReactPwrRated == 0)
    {   pEng->ucRctPrsnt = 0;
    }   else
    {   pEng->ucRctPrsnt = SF_PRSNT_08U(usDBmGensReactPowerAll,usDBpGensReactPwrRated);
    }
}
#endif

/* ******************************************************************** */
/*                          CAN2DecodeEngTcb()                          */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2DecodeEngTcb (CAN2_LS_TCB *pEng)
{   INT16U usTmp;
    usTmp              = pEng->usEngState;
    pEng->ucErrCmdMod  = (INT08U)((usTmp >> CAN2_LS_BIT_ERROR) & 0x07);
    pEng->ucAutoOrHand = (INT08U)((usTmp >> CAN2_LS_BIT_MANUAL) & 0x01);
    pEng->ucPhase      = (INT08U)((usTmp >> CAN2_LS_BIT_STEP) & 0x0F);
    pEng->ucSwStatus   = (INT08U)((usTmp >> CAN2_LS_BIT_SW_STS) & 0x03);
    pEng->ucSwLocked   = (INT08U)((usTmp >> CAN2_LS_BIT_SW_LOCKED) & 0x01);
    pEng->ucSwLockReq  = (INT08U)((usTmp >> CAN2_LS_BIT_SW_REQ) & 0x01);
    pEng->usActLoad    = SF_PRS08_TO_16U(pEng->ucActPrsnt, pEng->usActRated);
    pEng->usRctLoad    = SF_PRS08_TO_16U(pEng->ucRctPrsnt, pEng->usRctRated);
}
#endif

/* ******************************************************************** */
/*                          CAN2SetupTxCanMsg()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2SetupTxCanMsg (CAN_MSG *pMsg, CAN2_LS_TCB *pEng)
{   pMsg->DAT32.uiID   = CAN2_ID32_TO_CPU(pEng->uiID);
    pMsg->DAT16.usDat0 = pEng->usEngState;
    pMsg->DAT16.usDat1 = pEng->usActRated;
    pMsg->DAT16.usDat2 = pEng->usRctRated;
    pMsg->DAT08.ucDat6 = pEng->ucActPrsnt;
    pMsg->DAT08.ucDat7 = pEng->ucRctPrsnt;
}
#endif

/* ******************************************************************** */
/*                        CAN2PutRxMsgToEngTbl()                        */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2PutRxMsgToEngTbl (CAN_MSG *pMsg)
{   INT32U i, uiTmp;
    CAN2_LS_TCB *pEng;
    uiTmp = CAN2_CPU_TO_ID32(pMsg->DAT32.uiID);
    if ((uiTmp & 0xFFFFFF00) != CAN2_LS_ID831)
    {   return;
    }
    if (uiTmp == pCAN2EngThis->uiID)
    {   ERR_ES6_SET_BIT(ERR_ES6_STP_CAN2_PRIO);
        return;
    }
    for (i=1; i<CAN2_LS_TBL_SIZE; i++)
    {   pEng = &sCAN2EngTbl[i];
        if (uiTmp           == pEng->uiID)
        {   pEng->usTime     = usFW5msTimer;
            pEng->usEngState = pMsg->DAT16.usDat0;
            pEng->usActRated = pMsg->DAT16.usDat1;
            pEng->usRctRated = pMsg->DAT16.usDat2;
            pEng->ucActPrsnt = pMsg->DAT08.ucDat6;
            pEng->ucRctPrsnt = pMsg->DAT08.ucDat7;
            return;
        }
    }
    for (i=1; i<CAN2_LS_TBL_SIZE; i++)
    {   pEng = &sCAN2EngTbl[i];
        if (pEng->uiID      == 0)
        {   pEng->uiID       = uiTmp;
            pEng->ucState    = CAN2_ERR_RX_TIMEOUT;
            pEng->usTime     = usFW5msTimer;
            pEng->ucPriority = (INT08U)(uiTmp & 0x00FF);
            pEng->usEngState = pMsg->DAT16.usDat0;
            pEng->usActRated = pMsg->DAT16.usDat1;
            pEng->usRctRated = pMsg->DAT16.usDat2;
            pEng->ucActPrsnt = pMsg->DAT08.ucDat6;
            pEng->ucRctPrsnt = pMsg->DAT08.ucDat7;
            return;
        }
    }
}
#endif

/* ******************************************************************** */
/*                         CAN2CheckRxTblTimeOut()                      */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2CheckRxTblTimeOut (void)
{   INT32U i;
    CAN2_LS_TCB *pEng;
    for (i=1; i<CAN2_LS_TBL_SIZE; i++)
    {   pEng = &sCAN2EngTbl[i];
        if (pEng->uiID != 0)
        {   if (SFCheckTime(pEng->usTime,pEng->usPeriod) != SF_FALSE)
            {   pEng->ucState = CAN2_ERR_RX_TIMEOUT;
                pEng->uiID    = 0;
            }   else
            {   pEng->ucState = CAN2_NO_ERR;
            }
        }
    }
}
#endif

/* ******************************************************************** */
/*                          CAN2GetEngState()                           */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT16U CAN2GetEngState (INT16U usPhase)
{   INT16U usEState = 0;
    if ((usDBmSysEmergnErrToStop != 0) ||
        (usDBmSysCommonErrToStop != 0) )
    {   usEState |= CAN2_LS_MSK_ERROR;
    }
    if ((usDBmSysEmergnCmdToStop != 0) ||
        (ERR_ES7_GET_BIT(ERR_ES7_CMD_TO_STOP) != 0))
    {   usEState |= CAN2_LS_MSK_STOPCMD;
    }
    if (usDBpSysOperationMode != CTL_MODE_PARALLEL)
    {   usEState |= CAN2_LS_MSK_MODE;
    }
    if (usDBmSysAutoOrManual == 0)
    {   usEState |= CAN2_LS_MSK_MANUAL;
    }
    if (usPhase == CTL_PHASE_STOPPED)
    {   usEState |= CAN2_LS_MSK_STOPPED;
    }
    else if (usPhase == CTL_PHASE_READY)
    {   usEState |= CAN2_LS_MSK_READY;
    }
    else if((usPhase == CTL_PHASE_STARTING) ||
            (usPhase == CTL_PHASE_IDLING_UP) ||
            (usPhase == CTL_PHASE_RAMP_UP) ||
            (usPhase == CTL_PHASE_RATED_UP) ||
            (usPhase == CTL_PHASE_WAIT_KEY_SW) ||
            (usPhase == CTL_PHASE_SYNCHRING) ||
            (usPhase == CTL_PHASE_GENS_SW_ON) )
    {   usEState |= CAN2_LS_MSK_STARTING;
    }
    else if((usPhase == CTL_PHASE_LOADING_UP) ||
            (usPhase == CTL_PHASE_LOADING_DOWN))
    {   usEState |= CAN2_LS_MSK_LOADING;
    }
    else if (usPhase == CTL_PHASE_WORKING)
    {   usEState |= CAN2_LS_MSK_WORKING;
    }
    else
    {   usEState |= CAN2_LS_MSK_STOPPING;
    }
    if (SFGetSwitchOnLock(&sCTLGensSwitch) != 0)
    {   usEState |= CAN2_LS_MSK_SW_LOCKED;
    }
    if (ucCAN2TxSwLockCmd != 0)
    {   usEState |= CAN2_LS_MSK_SW_REQ;
    }
    usDBmSysGensSwStatus = (INT16U)SFGetSwitchStatus(&sCTLGensSwitch);
    usEState |= usDBmSysGensSwStatus << CAN2_LS_BIT_SW_STS;
    return usEState;
}
#endif

/* ******************************************************************** */
/*                          CAN2ProcessEngTbl()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2ProcessEngTbl (void)
{   static CAN2_LS_TCB *pLeader  = (CAN2_LS_TCB *)0;
    static CAN2_LS_TCB *pToStop  = (CAN2_LS_TCB *)0;
    static CAN2_LS_TCB *pToSwOn  = (CAN2_LS_TCB *)0;
    static CAN2_LS_TCB *pToStart = (CAN2_LS_TCB *)0;
    static INT32U uiSumShActLd   = 0;
    static INT32U uiSumShRctLd   = 0;
    static INT32U uiSumShActRt   = 0;
    static INT32U uiSumShRctRt   = 0;
    static INT32U uiSumFxActLd   = 0;
    static INT32U uiSumFxRctLd   = 0;
    static INT32U uiSumFxActRt   = 0;
    static INT32U uiSumFxRctRt   = 0;
    static INT32U uiSumStActRt   = 0;
    static INT32U uiSumStRctRt   = 0;
    static INT08U ucNumTotal     = 0;
    static INT08U ucNumNotStop   = 0;
    static INT08U ucNumSwNotOff  = 0;
    static INT08U ucNumNotLocked = 0;
    static INT08U ucNumLockCmd   = 0;
    static INT08U ucNumParallel  = 0;
    static INT08U ucPrioToSwOn   = 0;
    static INT08U ucPrioToStart  = 0;
    INT08U ucPrioToStop;
    INT08U ucPrioLeader;
    INT16U i, usTmp, usRated;
    CAN2_LS_TCB *pEng;
    pLeader        = &sCAN2EngTbl[0];
    pToStop        = &sCAN2EngTbl[0];
    pToSwOn        = &sCAN2EngTbl[0];
    pToStart       = &sCAN2EngTbl[0];
    uiSumShActLd   = 0;
    uiSumShRctLd   = 0;
    uiSumShActRt   = 0;
    uiSumShRctRt   = 0;
    uiSumFxActLd   = 0;
    uiSumFxRctLd   = 0;
    uiSumFxActRt   = 0;
    uiSumFxRctRt   = 0;
    uiSumStActRt   = 0;
    uiSumStRctRt   = 0;
    ucNumTotal     = 0;
    ucNumNotStop   = 0;
    ucNumSwNotOff  = 0;
    ucNumNotLocked = 0;
    ucNumLockCmd   = 0;
    ucNumParallel  = 0;
    ucPrioToStop   = 0;
    ucPrioLeader   = 255;
    ucPrioToSwOn   = 255;
    ucPrioToStart  = 255;
    /* *********************** Decode Eng Tab ************************* */
    for (i=0; i<CAN2_LS_TBL_SIZE; i++)
    {   pEng = &sCAN2EngTbl[i];
        if (pEng->ucState != CAN2_NO_ERR)
        {   continue;
        }
        ucNumTotal++;
        CAN2DecodeEngTcb(pEng);
        if (pEng->ucErrCmdMod != 0)
        {   continue;
        }
        /* ***************** Number of Statistic ********************** */
        if (i != 0)
        {   ucNumParallel++;
            if ((pEng->ucPhase != CAN2_LS_STEP_READY) &&
                (pEng->ucPhase != CAN2_LS_STEP_STOPPED))
            {   ucNumNotStop++;
            }
            if (pEng->ucSwStatus != SF_SW_STS_SWOFF_ED)
            {   ucNumSwNotOff++;
            }
            if (pEng->ucSwLockReq != 0)
            {   ucNumLockCmd++;
            }
            if (pEng->ucSwLocked == 0)
            {   ucNumNotLocked++;
            }
        }
        /* ***************** Power Load and Rated ********************* */
        if (pEng->ucAutoOrHand == 0)
        {   if (pEng->ucPhase == CAN2_LS_STEP_WORKING)
            {   uiSumShActLd  += pEng->usActLoad;
                uiSumShRctLd  += pEng->usRctLoad;
                uiSumShActRt  += pEng->usActRated;
                uiSumShRctRt  += pEng->usRctRated;
                if (ucPrioLeader > pEng->ucPriority)
                {   ucPrioLeader = pEng->ucPriority;
                    pLeader      = pEng;
                }
            }
            else if (pEng->ucPhase == CAN2_LS_STEP_LOADING)
            {   uiSumFxActLd  += pEng->usActLoad;
                uiSumFxRctLd  += pEng->usRctLoad;
                uiSumFxActRt  += pEng->usActRated;
                uiSumFxRctRt  += pEng->usRctRated;
                if (ucPrioLeader > pEng->ucPriority)
                {   ucPrioLeader = pEng->ucPriority;
                    pLeader      = pEng;
                }
            }
        }
        else if (pEng->ucPhase == CAN2_LS_STEP_WORKING)
        {   uiSumShActLd  += pEng->usActLoad;
            uiSumShRctLd  += pEng->usRctLoad;
            uiSumShActRt  += pEng->usActRated;
            uiSumShRctRt  += pEng->usRctRated;
            if (ucPrioLeader > pEng->ucPriority)
            {   ucPrioLeader = pEng->ucPriority;
                pLeader      = pEng;
            }
            if (ucPrioToStop < pEng->ucPriority)
            {   ucPrioToStop = pEng->ucPriority;
                pToStop      = pEng;
            }
        }
        else if (pEng->ucPhase == CAN2_LS_STEP_LOADING)
        {   uiSumFxActLd  += pEng->usActLoad;
            uiSumFxRctLd  += pEng->usRctLoad;
            uiSumFxActRt  += pEng->usActRated;
            uiSumFxRctRt  += pEng->usRctRated;
            if (ucPrioLeader > pEng->ucPriority)
            {   ucPrioLeader = pEng->ucPriority;
                pLeader      = pEng;
            }
            if (ucPrioToStop < pEng->ucPriority)
            {   ucPrioToStop = pEng->ucPriority;
                pToStop      = pEng;
            }
        }
        else if (pEng->ucPhase == CAN2_LS_STEP_STARTING)
        {   uiSumStActRt  += pEng->usActRated;
            uiSumStRctRt  += pEng->usRctRated;
            if (ucPrioToSwOn > pEng->ucPriority)
            {   ucPrioToSwOn = pEng->ucPriority;
                pToSwOn      = pEng;
            }
            if (ucPrioToStop < pEng->ucPriority)
            {   ucPrioToStop = pEng->ucPriority;
                pToStop      = pEng;
            }
        }
        else if ((pEng->ucPhase == CAN2_LS_STEP_READY) ||
                 (pEng->ucPhase == CAN2_LS_STEP_STOPPING))
        {   if (ucPrioToStart > pEng->ucPriority)
            {   ucPrioToStart = pEng->ucPriority;
                pToStart      = pEng;
            }
        }
    }
    /* *********************** Record Statistic *********************** */
    pCAN2EngLeader       = pLeader;
    pCAN2EngToStop       = pToStop;
    pCAN2EngToSwOn       = pToSwOn;
    pCAN2EngToStart      = pToStart;
    ucCAN2NumOfTotal     = ucNumTotal;
    ucCAN2NumOfNotStop   = ucNumNotStop;
    ucCAN2NumOfSwNotOff  = ucNumSwNotOff;
    ucCAN2NumOfNotLocked = ucNumNotLocked;
    ucCAN2RxSwLockCmd    = ucNumLockCmd;
    /* *********************** Mode Set Error ************************* */
    if ((ucNumParallel != 0) &&
        (usDBpSysOperationMode != CTL_MODE_PARALLEL))
    {   ERR_ES6_SET_BIT(ERR_ES6_STP_CAN2_MODE);
        SFSwitchOffTimes(&sCTLGensSwitch,1);
    }
    /* ******************** Share Act Power Present ******************* */
    usTmp   = SF_16U_TO_PRSNT(uiSumShActLd, uiSumShActRt);
    i       = usTmp;
    usRated = pLeader->usActRated;
    if (i > usDBpCanLeaderPrsntMax)
    {   i = SF_PRSNT_TO_16U(usDBpCanLeaderPrsntMax, usRated);
        if (uiSumShActLd < i)
        {   usTmp = 0;
        }
        else if (uiSumShActRt > usRated)
        {   i = (uiSumShActLd - i) * 1000 / (uiSumShActRt - usRated);
            usTmp = i < 1000 ? i : 1000;
        }
    }
    else if (i < usDBpCanLeaderPrsntMin)
    {   i = SF_PRSNT_TO_16U(usDBpCanLeaderPrsntMin, usRated);
        if (uiSumShActLd < i)
        {   usTmp = 0;
        }
        else if (uiSumShActRt > usRated)
        {   i = (uiSumShActLd - i) * 1000 / (uiSumShActRt - usRated);
            usTmp = i < 1000 ? i : 1000;
        }
    }
    usDBmCanSchedActPrsntSetp = usTmp;
    usDBmCanSchedActPowerSetp = SF_PRSNT_TO_16U(usTmp, usDBpGensActPwrRated);
    /* ******************** Share React Power Present ***************** */
    usTmp   = SF_16U_TO_PRSNT(uiSumShRctLd, uiSumShRctRt);
    i       = usTmp;
    usRated = pLeader->usRctRated;
    if (i > usDBpCanLeaderPrsntMax)
    {   i = SF_PRSNT_TO_16U(usDBpCanLeaderPrsntMax, usRated);
        if (uiSumShRctLd < i)
        {   usTmp = 0;
        }
        else if (uiSumShRctRt > usRated)
        {   i = (uiSumShRctLd - i) * 1000 / (uiSumShRctRt - usRated);
            usTmp = i < 1000 ? i : 1000;
        }
    }
    else if (i < usDBpCanLeaderPrsntMin)
    {   i = SF_PRSNT_TO_16U(usDBpCanLeaderPrsntMin, usRated);
        if (uiSumShRctLd < i)
        {   usTmp = 0;
        }
        else if (uiSumShRctRt > usRated)
        {   i = (uiSumShRctLd - i) * 1000 / (uiSumShRctRt - usRated);
            usTmp = i < 1000 ? i : 1000;
        }
    }
    usDBmCanSchedRctPrsntSetp = usTmp;
    usDBmCanSchedRctPowerSetp = SF_PRSNT_TO_16U(usTmp, usDBpGensReactPwrRated);
    /* ******************** Sched Act Power Present ******************* */
    uiSumShActLd += uiSumFxActLd;
    uiSumShActRt += uiSumFxActRt + uiSumStActRt;
    if (uiSumShActRt == 0)
    {   usDBmCanSchedActIntoPrsnt = 500;
    }   else
    {   usDBmCanSchedActIntoPrsnt = uiSumShActLd * 1000 / uiSumShActRt;
    }
    /* ******************** Sched React Power Present ***************** */
    uiSumShRctLd += uiSumFxRctLd;
    uiSumShRctRt += uiSumFxRctRt + uiSumStRctRt;
    if (uiSumShRctRt == 0)
    {   usDBmCanSchedRctIntoPrsnt = 500;
    }   else
    {   usDBmCanSchedRctIntoPrsnt = uiSumShRctLd * 1000 / uiSumShRctRt;
    }
}
#endif

/* ******************************************************************** */
/*                          CAN2GetTxSwitchLockCmd()                    */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT08U CAN2GetTxSwitchLockCmd (void)
{   return ucCAN2TxSwLockCmd;
}
#endif

/* ******************************************************************** */
/*                          CAN2SetTxSwitchLockCmd()                    */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2SetTxSwitchLockCmd (void)
{   ucCAN2TxSwLockCmd = 1;
}
#endif

/* ******************************************************************** */
/*                          CAN2ClrTxSwitchLockCmd()                    */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2ClrTxSwitchLockCmd (void)
{   ucCAN2TxSwLockCmd = 0;
}
#endif

/* ******************************************************************** */
/*                          CAN2GetRxSwitchLockCmd()                    */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT08U CAN2GetRxSwitchLockCmd (void)
{   return ucCAN2RxSwLockCmd == 0 ? CAN2_FALSE : CAN2_TRUE;
}
#endif

/* ******************************************************************** */
/*                          CAN2AreSwAllLocked()                        */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT08U CAN2AreSwAllLocked (void)
{   return ucCAN2NumOfNotLocked == 0 ? CAN2_TRUE : CAN2_FALSE;
}
#endif

/* ******************************************************************** */
/*                          CAN2AreSwAllOffed()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT08U CAN2AreSwAllOffed (void)
{   return ucCAN2NumOfSwNotOff == 0 ? CAN2_TRUE : CAN2_FALSE;
}
#endif

/* ******************************************************************** */
/*                         CAN2AreEngAllStopped()                       */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT08U CAN2AreEngAllStopped (void)
{   return ucCAN2NumOfNotStop == 0 ? CAN2_TRUE : CAN2_FALSE;
}
#endif

/* ******************************************************************** */
/*                        CAN2GetCanSchedToStop()                       */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT16U CAN2GetCanSchedToStop (void)
{   static INT16U usTimer1 = 0;
    static INT16U usToStop = 1;
    CAN2_LS_TCB *pThis;
    INT16U usTimNow;
    pThis = pCAN2EngThis;
    usTimNow = usFW100msTimer;
    if ((pThis->ucAutoOrHand == 0) ||
        (pThis->ucErrCmdMod  != 0) )
    {   usTimer1 = usTimNow;
        usToStop = 0;
    }
    else if (pThis->ucPhase == CAN2_LS_STEP_STOPPED)
    {   usTimer1 = usTimNow;
        usToStop = 1;
    }
    else if ((pThis->ucPhase == CAN2_LS_STEP_READY) ||
             (pThis->ucPhase == CAN2_LS_STEP_STOPPING) )
    {   if (pThis != pCAN2EngToStart)
        {   usTimer1 = usTimNow;
            usToStop = 1;
        }
        else if (usDBmCanSchedActIntoPrsnt <= usDBpCanLoadPrsntToStart)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usDBpCanLoadPrsntStartDly)
        {   usTimer1 = usTimNow;
            usToStop = 0;
        }
    }
    else if ((pThis->ucPhase == CAN2_LS_STEP_STARTING) ||
             (pThis->ucPhase == CAN2_LS_STEP_LOADING) ||
             (pThis->ucPhase == CAN2_LS_STEP_WORKING) )
    {   if (pThis != pCAN2EngToStop)
        {   usTimer1 = usTimNow;
            usToStop = 0;
        }
        else if (usDBmCanSchedActIntoPrsnt >= usDBpCanLoadPrsntToStop)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usDBpCanLoadPrsntStopDly)
        {   usTimer1 = usTimNow;
            usToStop = 1;
        }
    }
    return usToStop;
}
#endif

/* ******************************************************************** */
/*                        CAN2GetCanSchedToSwitch()                     */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT16U CAN2GetCanSchedToSwitch (void)
{   CAN2_LS_TCB *pThis;
    pThis = pCAN2EngThis;
    if ((pThis->ucPhase == CAN2_LS_STEP_LOADING) ||
        (pThis->ucPhase == CAN2_LS_STEP_WORKING) )
    {   return 1;
    }
    else if (pThis->ucPhase == CAN2_LS_STEP_STARTING)
    {   if ((pThis->ucErrCmdMod == 0) && (pThis == pCAN2EngToSwOn))
        {   return 1;
        }
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                        CAN2GetCanSchedIsAlone()                      */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT16U CAN2GetCanSchedIsAlone (void)
{   if (ucCAN2NumOfTotal <= 1)
    {   return 1;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CAN2GetCanSchedIsHighest()                     */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT16U CAN2GetCanSchedIsHighest (void)
{   CAN2_LS_TCB *pThis;
    pThis = pCAN2EngThis;
    if (ucCAN2NumOfTotal <= 1)
    {   return 1;
    }
    if ((pThis->ucErrCmdMod == 0) &&
        (pThis == pCAN2EngLeader) &&
       ((pThis->ucPhase == CAN2_LS_STEP_WORKING) ||
        (pThis->ucPhase == CAN2_LS_STEP_LOADING)))
    {   return 1;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                             CAN2TxIntHook()                          */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2TxIntHook (void)
{   CAN2_TC_INT_DIS();
    if (CAN2GetTxMsgFmBuf(&sCAN2IntrTxMsg) == CAN2_NO_ERR)
    {   CAN2->sTxMailBox[0].TIR &= CAN_TI0R_TXRQ;
        CAN2->sTxMailBox[0].TIR |= sCAN2IntrTxMsg.DAT32.uiID;
        CAN2->sTxMailBox[0].TDTR = 8;
        CAN2->sTxMailBox[0].TDLR = sCAN2IntrTxMsg.DAT32.uiDat0;
        CAN2->sTxMailBox[0].TDHR = sCAN2IntrTxMsg.DAT32.uiDat1;
        CAN2->sTxMailBox[0].TIR |= CAN_TI0R_TXRQ;
        if (CAN2GetTxMsgFmBuf(&sCAN2IntrTxMsg) == CAN2_NO_ERR)
        {   CAN2->sTxMailBox[1].TIR &= CAN_TI1R_TXRQ;
            CAN2->sTxMailBox[1].TIR |= sCAN2IntrTxMsg.DAT32.uiID;
            CAN2->sTxMailBox[1].TDTR = 8;
            CAN2->sTxMailBox[1].TDLR = sCAN2IntrTxMsg.DAT32.uiDat0;
            CAN2->sTxMailBox[1].TDHR = sCAN2IntrTxMsg.DAT32.uiDat1;
            CAN2->sTxMailBox[1].TIR |= CAN_TI1R_TXRQ;
            if (CAN2GetTxMsgFmBuf(&sCAN2IntrTxMsg) == CAN2_NO_ERR)
            {   CAN2->sTxMailBox[2].TIR &= CAN_TI2R_TXRQ;
                CAN2->sTxMailBox[2].TIR |= sCAN2IntrTxMsg.DAT32.uiID;
                CAN2->sTxMailBox[2].TDTR = 8;
                CAN2->sTxMailBox[2].TDLR = sCAN2IntrTxMsg.DAT32.uiDat0;
                CAN2->sTxMailBox[2].TDHR = sCAN2IntrTxMsg.DAT32.uiDat1;
                CAN2->sTxMailBox[2].TIR |= CAN_TI2R_TXRQ;
            }
        }
        CAN2_TC_INT_EN();
    }
}
#endif

/* ******************************************************************** */
/*                             CAN2Rx0IntHook()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2Rx0IntHook (void)
{   sCAN2IntrRxMsg.DAT32.uiID   = CAN2->sFIFOMailBox[0].RIR & CAN2_CPU_ID_MSK;
    sCAN2IntrRxMsg.DAT32.uiDat0 = CAN2->sFIFOMailBox[0].RDLR;
    sCAN2IntrRxMsg.DAT32.uiDat1 = CAN2->sFIFOMailBox[0].RDHR;
    CAN2->RF0R                 |= CAN_RF0R_RFOM0;
    (void)CAN2PutRxMsgToBuf(&sCAN2IntrRxMsg);
    if ((CAN2->RF0R & CAN_RF0R_FMP0) != 0)
    {   sCAN2IntrRxMsg.DAT32.uiID   = CAN2->sFIFOMailBox[0].RIR & CAN2_CPU_ID_MSK;
        sCAN2IntrRxMsg.DAT32.uiDat0 = CAN2->sFIFOMailBox[0].RDLR;
        sCAN2IntrRxMsg.DAT32.uiDat1 = CAN2->sFIFOMailBox[0].RDHR;
        CAN2->RF0R                 |= CAN_RF0R_RFOM0;
        (void)CAN2PutRxMsgToBuf(&sCAN2IntrRxMsg);
        if ((CAN2->RF0R & CAN_RF0R_FMP0) != 0)
        {   sCAN2IntrRxMsg.DAT32.uiID   = CAN2->sFIFOMailBox[0].RIR & CAN2_CPU_ID_MSK;
            sCAN2IntrRxMsg.DAT32.uiDat0 = CAN2->sFIFOMailBox[0].RDLR;
            sCAN2IntrRxMsg.DAT32.uiDat1 = CAN2->sFIFOMailBox[0].RDHR;
            CAN2->RF0R                 |= CAN_RF0R_RFOM0;
            (void)CAN2PutRxMsgToBuf(&sCAN2IntrRxMsg);
        }
    }
}
#endif

/* ******************************************************************** */
/*                             CAN2Rx1IntHook()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2Rx1IntHook (void)
{   sCAN2IntrRxMsg.DAT32.uiID   = CAN2->sFIFOMailBox[1].RIR & CAN2_CPU_ID_MSK;
    sCAN2IntrRxMsg.DAT32.uiDat0 = CAN2->sFIFOMailBox[1].RDLR;
    sCAN2IntrRxMsg.DAT32.uiDat1 = CAN2->sFIFOMailBox[1].RDHR;
    CAN2->RF1R                 |= CAN_RF1R_RFOM1;
    (void)CAN2PutRxMsgToBuf(&sCAN2IntrRxMsg);
    if ((CAN2->RF1R & CAN_RF1R_FMP1) != 0)
    {   sCAN2IntrRxMsg.DAT32.uiID   = CAN2->sFIFOMailBox[1].RIR & CAN2_CPU_ID_MSK;
        sCAN2IntrRxMsg.DAT32.uiDat0 = CAN2->sFIFOMailBox[1].RDLR;
        sCAN2IntrRxMsg.DAT32.uiDat1 = CAN2->sFIFOMailBox[1].RDHR;
        CAN2->RF1R                 |= CAN_RF1R_RFOM1;
        (void)CAN2PutRxMsgToBuf(&sCAN2IntrRxMsg);
        if ((CAN2->RF1R & CAN_RF1R_FMP1) != 0)
        {   sCAN2IntrRxMsg.DAT32.uiID   = CAN2->sFIFOMailBox[1].RIR & CAN2_CPU_ID_MSK;
            sCAN2IntrRxMsg.DAT32.uiDat0 = CAN2->sFIFOMailBox[1].RDLR;
            sCAN2IntrRxMsg.DAT32.uiDat1 = CAN2->sFIFOMailBox[1].RDHR;
            CAN2->RF1R                 |= CAN_RF1R_RFOM1;
            (void)CAN2PutRxMsgToBuf(&sCAN2IntrRxMsg);
        }
    }
}
#endif

/* ******************************************************************** */
/*                            CAN2SceIntHook()                          */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2SceIntHook (void)
{   INT32U uiTemp;
    uiTemp = CAN2->ESR;
    if ((uiTemp & CAN_ESR_BOFF) != 0)
    {   CAN2_STS_SET_BIT(CAN2_STS_BUS_OFF);
    }   else
    {   CAN2_STS_CLR_BIT(CAN2_STS_BUS_OFF);
    }
    if ((uiTemp & CAN_ESR_EWGF) != 0)
    {   CAN2_STS_SET_BIT(CAN2_STS_WARNING);
    }   else
    {   CAN2_STS_CLR_BIT(CAN2_STS_WARNING);
    }
    if ((uiTemp & CAN_ESR_EPVF) != 0)
    {   CAN2_STS_SET_BIT(CAN2_STS_OVERRUN);
    }   else
    {   CAN2_STS_CLR_BIT(CAN2_STS_OVERRUN);
    }
}
#endif

/* ******************************************************************** */
/*                             CAN2BufInit()                            */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2BufInit (void)
{   CAN2_RING *pbuf;
    pbuf = &sCAN2RingBuf;
    pbuf->usRingBufRxCtr   =  0;
    pbuf->pRingBufRxInPtr  = &pbuf->sRingBufRx[0];
    pbuf->pRingBufRxOutPtr = &pbuf->sRingBufRx[0];
    pbuf->pRingBufRxSem    =  OSSemCreate(0);
    pbuf->usRingBufTxCtr   =  0;
    pbuf->pRingBufTxInPtr  = &pbuf->sRingBufTx[0];
    pbuf->pRingBufTxOutPtr = &pbuf->sRingBufTx[0];
    pbuf->pRingBufTxSem    =  OSSemCreate(CAN2_TX_BUF_SIZE);
}
#endif

/* ******************************************************************** */
/*                            CAN2IsTxBufFull()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT08U CAN2IsTxBufFull (void)
{   OS_CPU_SR cpu_sr = 0;
    CAN2_RING *pbuf;
    pbuf = &sCAN2RingBuf;
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufTxCtr >= CAN2_TX_BUF_SIZE)
    {   OS_EXIT_CRITICAL();
        return CAN2_TRUE;
    }   else
    {   OS_EXIT_CRITICAL();
        return CAN2_FALSE;
    }
}
#endif

/* ******************************************************************** */
/*                           CAN2IsRxBufEmpty()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT08U CAN2IsRxBufEmpty (void)
{   OS_CPU_SR cpu_sr = 0;
    CAN2_RING *pbuf;
    pbuf = &sCAN2RingBuf;
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufRxCtr == 0)
    {   OS_EXIT_CRITICAL();
        return CAN2_TRUE;
    }   else
    {   OS_EXIT_CRITICAL();
        return CAN2_FALSE;
    }
}
#endif

/* ******************************************************************** */
/*                           CAN2PutRxMsgToBuf()                        */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2PutRxMsgToBuf (CAN_MSG *pmsg)
{   CAN2_RING *pbuf;
    CAN_MSG *ptmp;
    pbuf = &sCAN2RingBuf;
    if (pbuf->usRingBufRxCtr < CAN2_RX_BUF_SIZE)
    {   pbuf->usRingBufRxCtr++;
        ptmp = pbuf->pRingBufRxInPtr;
        ptmp->DAT32.uiID   = pmsg->DAT32.uiID;
        ptmp->DAT32.uiDat0 = pmsg->DAT32.uiDat0;
        ptmp->DAT32.uiDat1 = pmsg->DAT32.uiDat1;
        pbuf->pRingBufRxInPtr++;
        if (pbuf->pRingBufRxInPtr == &pbuf->sRingBufRx[CAN2_RX_BUF_SIZE])
        {   pbuf->pRingBufRxInPtr  = &pbuf->sRingBufRx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufRxSem);
    }
}
#endif

/* ******************************************************************** */
/*                          CAN2GetTxMsgFmBuf()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT08U CAN2GetTxMsgFmBuf (CAN_MSG *pmsg)
{   CAN2_RING *pbuf;
    CAN_MSG *ptmp;
    pbuf = &sCAN2RingBuf;
    if (pbuf->usRingBufTxCtr > 0)
    {   pbuf->usRingBufTxCtr--;
        ptmp = pbuf->pRingBufTxOutPtr;
        pmsg->DAT32.uiID   = ptmp->DAT32.uiID;
        pmsg->DAT32.uiDat0 = ptmp->DAT32.uiDat0;
        pmsg->DAT32.uiDat1 = ptmp->DAT32.uiDat1;
        pbuf->pRingBufTxOutPtr++;
        if (pbuf->pRingBufTxOutPtr == &pbuf->sRingBufTx[CAN2_TX_BUF_SIZE])
        {   pbuf->pRingBufTxOutPtr  = &pbuf->sRingBufTx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufTxSem);
        return CAN2_NO_ERR;
    }   else
    {   return CAN2_ERR_TX_EMPTY;
    }
}
#endif

/* ******************************************************************** */
/*                          CAN2GetMsgFmRxBuf()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT08U CAN2GetMsgFmRxBuf (INT16U to, CAN_MSG *pmsg)
{   OS_CPU_SR cpu_sr = 0;
    INT08U oserr;
    CAN2_RING *pbuf;
    CAN_MSG *ptmp;
    pbuf = &sCAN2RingBuf;
    OSSemPend(pbuf->pRingBufRxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   return CAN2_ERR_RX_TIMEOUT;
    }
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufRxCtr == 0)
    {   OS_EXIT_CRITICAL();
        return CAN2_ERR_RX_TIMEOUT;
    }
    pbuf->usRingBufRxCtr--;
    ptmp = pbuf->pRingBufRxOutPtr;
    pmsg->DAT32.uiID   = ptmp->DAT32.uiID;
    pmsg->DAT32.uiDat0 = ptmp->DAT32.uiDat0;
    pmsg->DAT32.uiDat1 = ptmp->DAT32.uiDat1;
    pbuf->pRingBufRxOutPtr++;
    if (pbuf->pRingBufRxOutPtr == &pbuf->sRingBufRx[CAN2_RX_BUF_SIZE])
    {   pbuf->pRingBufRxOutPtr  = &pbuf->sRingBufRx[0];
    }
    OS_EXIT_CRITICAL();
    return CAN2_NO_ERR;
}
#endif

/* ******************************************************************** */
/*                         CAN2TransMsgFirst()                          */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2TransMsgFirst (void)
{   CAN2_TC_INT_DIS();
    if (CAN2GetTxMsgFmBuf(&sCAN2IntrTxMsg) == CAN2_NO_ERR)
    {   CAN2->sTxMailBox[0].TIR &= CAN_TI0R_TXRQ;
        CAN2->sTxMailBox[0].TIR |= sCAN2IntrTxMsg.DAT32.uiID;
        CAN2->sTxMailBox[0].TDTR = 8;
        CAN2->sTxMailBox[0].TDLR = sCAN2IntrTxMsg.DAT32.uiDat0;
        CAN2->sTxMailBox[0].TDHR = sCAN2IntrTxMsg.DAT32.uiDat1;
        CAN2->sTxMailBox[0].TIR |= CAN_TI0R_TXRQ;
        CAN2_TC_INT_EN();
    }
}
#endif

/* ******************************************************************** */
/*                         CAN2PutMsgToTxBuf()                          */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT08U CAN2PutMsgToTxBuf (INT16U to, CAN_MSG *pmsg)
{   static INT32U uiCAN2TxFirstFlag = 0;
    OS_CPU_SR cpu_sr = 0;
    INT08U oserr;
    CAN2_RING *pbuf;
    CAN_MSG *ptmp;
    pbuf = &sCAN2RingBuf;
    OSSemPend(pbuf->pRingBufTxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   return CAN2_ERR_TX_TIMEOUT;
    }   else
    {   OS_ENTER_CRITICAL();
        pbuf->usRingBufTxCtr++;
        ptmp = pbuf->pRingBufTxInPtr;
        ptmp->DAT32.uiID   = pmsg->DAT32.uiID;
        ptmp->DAT32.uiDat0 = pmsg->DAT32.uiDat0;
        ptmp->DAT32.uiDat1 = pmsg->DAT32.uiDat1;
        pbuf->pRingBufTxInPtr++;
        if (pbuf->pRingBufTxInPtr == &pbuf->sRingBufTx[CAN2_TX_BUF_SIZE])
        {   pbuf->pRingBufTxInPtr  = &pbuf->sRingBufTx[0];
        }
        if (pbuf->usRingBufTxCtr  == 1)
        {   if (uiCAN2TxFirstFlag == 0)
            {   uiCAN2TxFirstFlag  = 1;
                CAN2TransMsgFirst();
            }   else
            {   CAN2_TC_INT_EN();
            }
        }
        OS_EXIT_CRITICAL();
        return CAN2_NO_ERR;
    }
}
#endif

/* ******************************************************************** */
/*                              CAN2HardInit()                          */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2HardInit (INT32U uiBaud)
{   RCC->APB1ENR  |=  RCC_APB1ENR_CAN2EN;
  //  RCC->APB1RSTR |=  RCC_APB1RSTR_CAN2RST;
  //  RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN2RST;
    XIOConfigREMAP(CAN2_AFIO_REMAP1, CAN2_AFIO_REMAP2);
    XIOConfigGPIO(CAN2_TX_PT, CAN2_TX_BT, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
    XIOConfigGPIO(CAN2_RX_PT, CAN2_RX_BT, XIO_PT_GPI_PULL,   XIO_PT_SET_1);
    CAN2->MCR &= ~CAN_MCR_SLEEP;            /* Exit from sleep mode     */
    CAN2->MCR |=  CAN_MCR_INRQ;             /* Request initialisation   */
    while((CAN2->MSR & CAN_MSR_INAK) == 0); /* Wait the acknowledge     */
    CAN2->MCR &= ~CAN_MCR_TTCM              /* 0: Time Trigger mode dis */
              &  ~CAN_MCR_ABOM              /* 0: No bus-off management */
              &  ~CAN_MCR_AWUM              /* 0: No Automatic wakeup   */
              &  ~CAN_MCR_RFLM;             /* 0: Receive FIFO not lock */
    CAN2->MCR |=  CAN_MCR_TXFP              /* 1: Priority by the order */
              |   CAN_MCR_NART;             /* 1: Not automatic retrans */
    if (uiBaud == 125)
    {   CAN2->BTR  = ((INT32U)0 << 30)      /* 0: Normal operation mode */
                  |  ((INT32U)1 << 24)      /* 1: Resynch jump width= 2 */
                  |  ((INT32U)5 << 20)      /* 5: Time segment 2 = 6tq  */
                  |  ((INT32U)8 << 16)      /* 8: Time segment 1 = 9tq  */
                  |  ((INT32U)18 - 1);      /* Prescaler=18: Tq = 1/2us */
    }
    else if (uiBaud == 250)
    {   CAN2->BTR  = ((INT32U)0 << 30)      /* 0: Normal operation mode */
                  |  ((INT32U)1 << 24)      /* 1: Resynch jump width= 2 */
                  |  ((INT32U)5 << 20)      /* 5: Time segment 2 = 6tq  */
                  |  ((INT32U)8 << 16)      /* 8: Time segment 1 = 9tq  */
                  |  ((INT32U)9 - 1);       /* Prescaler=9:  Tq = 1/4us */
    }
    else if (uiBaud == 500)
    {   CAN2->BTR  = ((INT32U)0 << 30)      /* 0: Normal operation mode */
                  |  ((INT32U)0 << 24)      /* 0: Resynch jump width= 1 */
                  |  ((INT32U)2 << 20)      /* 2: Time segment 2 = 3tq  */
                  |  ((INT32U)3 << 16)      /* 3: Time segment 1 = 4tq  */
                  |  ((INT32U)9 - 1);       /* Prescaler=9:  Tq = 1/4us */
    }
    else if (uiBaud == 1000)
    {   CAN2->BTR  = ((INT32U)0 << 30)      /* 0: Normal operation mode */
                  |  ((INT32U)0 << 24)      /* 0: Resynch jump width= 1 */
                  |  ((INT32U)2 << 20)      /* 2: Time segment 2 = 3tq  */
                  |  ((INT32U)4 << 16)      /* 4: Time segment 1 = 5tq  */
                  |  ((INT32U)4 - 1);       /* Prescaler=4:  Tq = 1/9us */
    }
    CAN2->MCR  &= ~CAN_MCR_INRQ;            /* Request leave initialie  */
    while((CAN2->MSR & CAN_MSR_INAK) != 0); /* Wait the acknowledge     */
    CAN1->FMR  |=  CAN_FMR_FINIT;           /* 1: Initialization mode   */
    CAN1->FMR  &= ~0x00003F00;              /* CAN2SB[5:0] = 28         */
    CAN1->FMR  |=  28uL << 8;               /* all filters to CAN1 used */
    CAN1->FMR  &= ~CAN_FMR_FINIT;           /* 0: Active filters mode   */
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */