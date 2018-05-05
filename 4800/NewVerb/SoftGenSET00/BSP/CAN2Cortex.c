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
/*   6: Current Persent of React Power                                  */
/* ******************************************************************** */

/* ******************************************************************** */
/*                              CAN2Init()                              */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2Init (void)
{   uiCAN2Status = 0;
    CAN2BufInit();
    CAN2HardInit();
}
#endif

/* ******************************************************************** */
/*                             CAN2Start()                              */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2Start (void)
{   CAN2_TC_INT_DIS();
    CAN2_RX_INT_EN();
}
#endif

/* ******************************************************************** */
/*                            CAN2TaskLoop()                            */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2TaskLoop (void)
{   while (1)
    {   OSTimeDly(OS_TICKS_PER_SEC / CAN2_TASK_FRQ);
        /* ********************** CAN2 RX Message ********************* */
        while (CAN2IsRxBufEmpty() == CAN2_FALSE)
        {   (void)CAN2GetMsgFmRxBuf(0, &sCAN2TaskRxMsg);
            (void)CAN2PutRxMsgToEngTbl(&sCAN2TaskRxMsg);
        }
        /* ********************** CAN2 TX Message ********************* */
        if (SFCheckTime(sCAN2EngTbl[0].usTime,sCAN2EngTbl[0].usPeriod) != SF_FALSE)
        {   usDBmCanSchedTxEngState = CAN2GetEngState(usDBmSystemPhase);
            (void)CAN2CheckEngTblTimeOut();
            (void)CAN2ProcessEngTbl();
            (void)CAN2SetupTxEngTcb(&sCAN2EngTbl[0]);
            (void)CAN2SetupTxCanMsg(&sCAN2TaskTxMsg,&sCAN2EngTbl[0]);
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
    usDBmCanSchedTxEngState = CAN2GetEngState(usDBmSystemPhase);
    CAN2SetupTxEngTcb(&sCAN2EngTbl[0]);
    for (i=1; i<CAN2_LS_TBL_SIZE; i++)
    {   pEng = &sCAN2EngTbl[i];
        pEng->ucEnable    = SF_ENABLE;
        pEng->ucState     = CAN2_ERR_RX_TIMEOUT;
        pEng->ucAddress   = 255;
        pEng->ucPriority  = 255;
        pEng->usTime      = usFW5msTimer;
        pEng->usPeriod    = CAN2_LS_RX_TO_TICKS;
        pEng->uiID        = 0;
        pEng->usEngState  = 0;
        pEng->usActRated  = 0;
        pEng->usRctRated  = 0;
        pEng->ucActPrsnt  = 0;
        pEng->ucRctPrsnt  = 0;
    }
}
#endif

/* ******************************************************************** */
/*                         CAN2CheckEngTblTimeOut()                     */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2CheckEngTblTimeOut (void)
{   INT32U i;
    CAN2_LS_TCB *pEng;
    for (i=1; i<CAN2_LS_TBL_SIZE; i++)
    {   pEng = &sCAN2EngTbl[i];
        if (pEng->ucState == CAN2_NO_ERR)
        {   if (SFCheckTime(pEng->usTime,pEng->usPeriod) != SF_FALSE)
            {   pEng->ucState = CAN2_ERR_RX_TIMEOUT;
                pEng->uiID    = 0;
            }
        }
    }
}
#endif

/* ******************************************************************** */
/*                        CAN2PutRxMsgToEngTbl()                        */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2PutRxMsgToEngTbl (CAN_MSG *pMsg)
{   INT32U i, uiTemp;
    CAN2_LS_TCB *pEng;
    uiTemp = CAN2_CPU_TO_ID32(pMsg->DAT32.uiID);
    if ((uiTemp & 0xFFFFFF00) != CAN2_LS_ID831)
    {   return;
    }
    if (uiTemp == sCAN2EngTbl[0].uiID)
    {   ERR_ES6_SET_BIT(ERR_ES6_STP_CAN2);
        return;
    }
    for (i=1; i<CAN2_LS_TBL_SIZE; i++)
    {   pEng = &sCAN2EngTbl[i];
        if (uiTemp == pEng->uiID)
        {   if (SFCheckTime(pEng->usTime,pEng->usPeriod) != SF_FALSE)
            {   pEng->ucState = CAN2_ERR_RX_TIMEOUT;
            }   else
            {   pEng->ucState = CAN2_NO_ERR;
            }
            pEng->usTime     = usFW5msTimer;
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
        {   pEng->uiID       = uiTemp;
            pEng->ucAddress  = (INT08U)(uiTemp & 0x00FF);
            pEng->ucPriority = pEng->ucAddress;
            pEng->ucState    = CAN2_ERR_RX_TIMEOUT;
            pEng->usTime     = usFW5msTimer;
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
/*                          CAN2SetupTxEngTcb()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2SetupTxEngTcb (CAN2_LS_TCB *pEng)
{   pEng->ucEnable   = SF_ENABLE;
    pEng->ucState    = CAN2_NO_ERR;
    pEng->ucAddress  = (INT08U)usDBpCan2Address;
    pEng->ucPriority = (INT08U)usDBpCan2Address;
    pEng->usTime     = usFW5msTimer;
    pEng->usPeriod   = CAN2_LS_TX_TICKS;
    pEng->uiID       = CAN2_LS_GET_ID32(usDBpCan2Address);
    pEng->usEngState = usDBmCanSchedTxEngState;
    pEng->usActRated = usDBpGensActPwrRated;
    pEng->usRctRated = usDBpGensReactPwrRated;
    if (usDBpGensActPwrRated == 0)
    {   pEng->ucActPrsnt = 0;
    }   else
    {   pEng->ucActPrsnt = SF_PRSNT_08U(usDBmGensActPowerAll,
                                        usDBpGensActPwrRated);
    }
    if (usDBpGensReactPwrRated == 0)
    {   pEng->ucRctPrsnt = 0;
    }   else
    {   pEng->ucRctPrsnt = SF_PRSNT_08U(usDBmGensReactPowerAll,
                                        usDBpGensReactPwrRated);
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
        (ERR_ES7_GET_BIT(ERR_ES7_SWT_TO_STOP) != 0) ||
        (ERR_ES7_GET_BIT(ERR_ES7_KEY_TO_STOP) != 0) )
    {   usEState |= CAN2_LS_MSK_STOP_CMD;
    }
    if (usDBpSysOperationMode != CTL_MODE_PARALLEL)
    {   usEState |= CAN2_LS_MSK_MODE;
    }
    if (usDBmSysAutoOrManual == 0)
    {   usEState |= CAN2_LS_MSK_MANUAL;
    }
    if (usPhase == CTL_PHASE_READY)
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
            (usPhase == CTL_PHASE_LOADING_DOWN) ||
            (usPhase == CTL_PHASE_WORKING) )
    {   usEState |= CAN2_LS_MSK_WORKING;
    }
    else if((usPhase == CTL_PHASE_STOPPING) ||
            (usPhase == CTL_PHASE_IDLING_DOWN) ||
            (usPhase == CTL_PHASE_RAMP_DOWN) ||
            (usPhase == CTL_PHASE_RATED_DOWN) ||
            (usPhase == CTL_PHASE_GENS_SW_OFF) )
    {   usEState |= CAN2_LS_MSK_STOPPING;
    }
    return usEState;
}
#endif

/* ******************************************************************** */
/*                          CAN2ProcessEngTbl()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2ProcessEngTbl (void)
{   CAN2_LS_TCB *pEng;
    INT16U i = 0;
    INT16U usEngState  = 0;
    INT32U uiSumLdAct  = 0;
    INT32U uiSumRdAct  = 0;
    INT32U uiSumStAct  = 0;
    INT32U uiSumWkAct  = 0;
    INT32U uiSumLdRct  = 0;
    INT32U uiSumRdRct  = 0;
    INT32U uiSumStRct  = 0;
    INT32U uiSumWkRct  = 0;
    INT08U ucNumReady  = 0;
    INT08U ucNumStart  = 0;
    INT08U ucNumWork   = 0;
    INT08U ucPrioStMax = 0;
    INT08U ucPrioStMin = 255;
    INT08U ucPrioRdMax = 0;
    INT08U ucPrioRdMin = 255;
    INT08U ucPrioWkMax = 0;
    INT08U ucPrioWkMin = 255;
    for (i=0; i<CAN2_LS_TBL_SIZE; i++)
    {   pEng = &sCAN2EngTbl[i];
        if (pEng->ucState == CAN2_NO_ERR)
        {   usEngState = CAN2_LS_ENG_STS(pEng->usEngState);
            if (usEngState == CAN2_LS_ENG_WORKING)
            {   uiSumLdAct += ((INT32U)(pEng->usActRated) *
                               (INT32U)(pEng->ucActPrsnt)) / 100u;
                uiSumLdRct += ((INT32U)(pEng->usRctRated) *
                               (INT32U)(pEng->ucRctPrsnt)) / 100u;
                uiSumWkAct +=  (INT32U)(pEng->usActRated);
                uiSumWkRct +=  (INT32U)(pEng->usRctRated);
                ucNumWork  +=  1;
                if (ucPrioWkMax < pEng->ucPriority)
                {   ucPrioWkMax = pEng->ucPriority;
                }
                if (ucPrioWkMin > pEng->ucPriority)
                {   ucPrioWkMin = pEng->ucPriority;
                }
            }
            else if (usEngState == CAN2_LS_ENG_STARTING)
            {   uiSumStAct +=  (INT32U)(pEng->usActRated);
                uiSumStRct +=  (INT32U)(pEng->usRctRated);
                ucNumStart +=  1;
                if (ucPrioStMax < pEng->ucPriority)
                {   ucPrioStMax = pEng->ucPriority;
                }
                if (ucPrioStMin > pEng->ucPriority)
                {   ucPrioStMin = pEng->ucPriority;
                }
            }
            else if ((usEngState == CAN2_LS_ENG_READY) ||
                     (usEngState == CAN2_LS_ENG_STOPPING))
            {   uiSumRdAct +=  (INT32U)(pEng->usActRated);
                uiSumRdRct +=  (INT32U)(pEng->usRctRated);
                ucNumReady +=  1;
                if (ucPrioRdMax < pEng->ucPriority)
                {   ucPrioRdMax = pEng->ucPriority;
                }
                if (ucPrioRdMin > pEng->ucPriority)
                {   ucPrioRdMin = pEng->ucPriority;
                }
            }
        }
    }
    uiCAN2SumWorkActLoad   = uiSumLdAct;
    uiCAN2SumReadyActRated = uiSumRdAct;
    uiCAN2SumStartActRated = uiSumStAct;
    uiCAN2SumWorkActRated  = uiSumWkAct;
    uiCAN2SumTotalActRated = uiSumRdAct + uiSumStAct + uiSumWkAct;
    uiCAN2SumWorkRctLoad   = uiSumLdRct;
    uiCAN2SumReadyRctRated = uiSumRdRct;
    uiCAN2SumStartRctRated = uiSumStRct;
    uiCAN2SumWorkRctRated  = uiSumWkRct;
    uiCAN2SumTotalRctRated = uiSumRdRct + uiSumStRct + uiSumWkRct;
    ucCAN2NumOfReady       = ucNumReady;
    ucCAN2NumOfStart       = ucNumStart;
    ucCAN2NumOfWork        = ucNumWork;
    ucCAN2NumOfTotal       = ucNumReady + ucNumStart + ucNumWork;
    ucCAN2PrioStartLow     = ucPrioStMax;
    ucCAN2PrioStartHigh    = ucPrioStMin;
    ucCAN2PrioReadyLow     = ucPrioRdMax;
    ucCAN2PrioReadyHigh    = ucPrioRdMin;
    ucCAN2PrioWorkLow      = ucPrioWkMax;
    ucCAN2PrioWorkHigh     = ucPrioWkMin;
    ucCAN2PrioTotalLow     = SF_MAX3(ucPrioStMax, ucPrioRdMax, ucPrioWkMax);
    ucCAN2PrioTotalHigh    = SF_MIN3(ucPrioStMin, ucPrioRdMin, ucPrioWkMin);
    usDBmCanSchedActPrsntSetp = uiSumWkAct == 0 ? 0 :
                                SF_16U_TO_PRSNT(uiSumLdAct,uiSumWkAct);
    usDBmCanSchedRctPrsntSetp = uiSumWkRct == 0 ? 0 :
                                SF_16U_TO_PRSNT(uiSumLdRct,uiSumWkRct);
    usDBmCanSchedActPowerSetp = SF_PRSNT_TO_16U(usDBmCanSchedActPrsntSetp,
                                                usDBpGensActPwrRated);
    usDBmCanSchedRctPowerSetp = SF_PRSNT_TO_16U(usDBmCanSchedRctPrsntSetp,
                                                usDBpGensReactPwrRated);
    uiSumWkAct               += uiSumStAct;
    uiSumWkRct               += uiSumStRct;
    usDBmCanSchedActIntoPrsnt = uiSumWkAct == 0 ? 0 :
                                SF_16U_TO_PRSNT(uiSumLdAct,uiSumWkAct);
    usDBmCanSchedRctIntoPrsnt = uiSumWkRct == 0 ? 0 :
                                SF_16U_TO_PRSNT(uiSumLdRct,uiSumWkRct);
}
#endif

/* ******************************************************************** */
/*                        CAN2GetCanSchedToStop()                       */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT16U CAN2GetCanSchedToStop (void)
{   INT16U usMyState;
    usMyState = CAN2_LS_ENG_STS(sCAN2EngTbl[0].usEngState);
    if (CAN2GetCanSchedIsHighest() != 0)
    {   SFMonitorLoadSchedLow(SF_DISABLE);
        SFMonitorLoadSchedHigh(SF_DISABLE);
        return 0;
    }
    else if (usMyState == CAN2_LS_ENG_READY)
    {   SFMonitorLoadSchedLow(SF_ENABLE);
        if (sCAN2EngTbl[0].ucPriority == ucCAN2PrioReadyHigh)
        {   SFMonitorLoadSchedHigh(SF_ENABLE);
        }   else
        {   SFMonitorLoadSchedHigh(SF_DISABLE);
        }
    }
    else if (usMyState == CAN2_LS_ENG_STARTING)
    {   SFMonitorLoadSchedLow(SF_ENABLE);
        SFMonitorLoadSchedHigh(SF_DISABLE);
    }
    else if (usMyState == CAN2_LS_ENG_STOPPING)
    {   SFMonitorLoadSchedLow(SF_DISABLE);
        SFMonitorLoadSchedHigh(SF_ENABLE);
    }
    else if (usMyState == CAN2_LS_ENG_WORKING)
    {   SFMonitorLoadSchedHigh(SF_DISABLE);
        if (sCAN2EngTbl[0].ucPriority == ucCAN2PrioWorkLow)        
        {   SFMonitorLoadSchedLow(SF_ENABLE);
        }   else        
        {   SFMonitorLoadSchedLow(SF_DISABLE);
        }
    }
    else
    {   SFMonitorLoadSchedLow(SF_DISABLE);
        SFMonitorLoadSchedHigh(SF_DISABLE);
        return 0;
    }
    if (ERR_ES7_GET_BIT(ERR_ES7_LD_SCHED_LOW) != 0)
    {   ERR_ES7_SET_BIT(ERR_ES7_LD_SCHED_STOP);
    }
    else if (ERR_ES7_GET_BIT(ERR_ES7_LD_SCHED_HGH) != 0)
    {   ERR_ES7_CLR_BIT(ERR_ES7_LD_SCHED_STOP);
    }
    if (ERR_ES7_GET_BIT(ERR_ES7_LD_SCHED_STOP) != 0)
    {   return 1;
    }    
    return 0;
}
#endif

/* ******************************************************************** */
/*                        CAN2GetCanSchedToSwitch()                     */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT16U CAN2GetCanSchedToSwitch (void)
{   INT16U usMyState;
    usMyState = CAN2_LS_ENG_STS(sCAN2EngTbl[0].usEngState);
    if ((usMyState == CAN2_LS_ENG_STARTING) &&
        (sCAN2EngTbl[0].ucPriority == ucCAN2PrioStartHigh) )
    {   return 1;
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                        CAN2GetCanSchedIsAlone()                      */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT16U CAN2GetCanSchedIsAlone (void)
{   INT16U usMyState;
    usMyState = CAN2_LS_ENG_STS(sCAN2EngTbl[0].usEngState);
    if (usMyState == CAN2_LS_ENG_WORKING)
    {   if (ucCAN2NumOfWork == 1)
        {   return 1;
        }
    }
    else if (usMyState == CAN2_LS_ENG_STARTING)
    {   if ((ucCAN2NumOfWork == 0) &&
            (sCAN2EngTbl[0].ucPriority == ucCAN2PrioStartHigh))
        {   return 1;
        }
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                       CAN2GetCanSchedIsHighest()                     */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT16U CAN2GetCanSchedIsHighest (void)
{   if ((sCAN2EngTbl[0].usEngState & CAN2_LS_ERR_MASK) != 0)
    {   return 0;
    }
    else if (sCAN2EngTbl[0].ucPriority == ucCAN2PrioTotalHigh)
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
void CAN2PutRxMsgToBuf (CAN_MSG *msg)
{   CAN2_RING *pbuf;
    CAN_MSG *pmsg, *ptmp;
    pbuf = &sCAN2RingBuf;
    if (pbuf->usRingBufRxCtr < CAN2_RX_BUF_SIZE)
    {   pbuf->usRingBufRxCtr++;
        pmsg = msg;
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
INT08U CAN2GetTxMsgFmBuf (CAN_MSG *msg)
{   CAN2_RING *pbuf;
    CAN_MSG *pmsg, *ptmp;
    pbuf = &sCAN2RingBuf;
    if (pbuf->usRingBufTxCtr > 0)
    {   pbuf->usRingBufTxCtr--;
        pmsg = msg;
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
INT08U CAN2GetMsgFmRxBuf (INT16U to, CAN_MSG *msg)
{   OS_CPU_SR cpu_sr = 0;
    INT08U oserr;
    CAN2_RING *pbuf;
    CAN_MSG *pmsg, *ptmp;
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
    pmsg = msg;
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
/*                         CAN2PutMsgToTxBuf()                          */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT08U CAN2PutMsgToTxBuf (INT16U to, CAN_MSG *msg)
{   OS_CPU_SR cpu_sr = 0;
    INT08U oserr;
    CAN2_RING *pbuf;
    CAN_MSG *pmsg, *ptmp;
    pbuf = &sCAN2RingBuf;
    OSSemPend(pbuf->pRingBufTxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   return CAN2_ERR_TX_TIMEOUT;
    }   else
    {   pmsg = msg;
        OS_ENTER_CRITICAL();
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
        {   CAN2_TC_INT_EN();
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
void CAN2HardInit (void)
{
//    RCC->APB1ENR  |=  RCC_APB1ENR_CAN2EN;
//    RCC->APB1RSTR |=  RCC_APB1RSTR_CAN2RST;
//    RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN2RST;
//    XIOConfigREMAP(CAN2_AFIO_REMAP1, CAN2_AFIO_REMAP2);
//    XIOConfigGPIO(CAN2_TX_PT, CAN2_TX_BT, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
//    XIOConfigGPIO(CAN2_RX_PT, CAN2_RX_BT, XIO_PT_GPI_PULL,   XIO_PT_SET_1);
//    CAN2->MCR &= ~CAN_MCR_SLEEP;            /* Exit from sleep mode     */
//    CAN2->MCR |=  CAN_MCR_INRQ;             /* Request initialisation   */
//    while((CAN2->MSR & CAN_MSR_INAK) == 0); /* Wait the acknowledge     */
//    CAN2->MCR &= ~CAN_MCR_TTCM              /* 0: Time Trigger mode dis */
//              &  ~CAN_MCR_ABOM              /* 0: No bus-off management */
//              &  ~CAN_MCR_AWUM              /* 0: No Automatic wakeup   */
//              &  ~CAN_MCR_NART              /* automatic retransmission */
//              &  ~CAN_MCR_RFLM;             /* 0: Receive FIFO not lock */
//    CAN2->MCR |=  CAN_MCR_TXFP;             /* 1: Priority by the order */
//   #if (CAN2_BAUDRATE_KHZ == 250)
//    CAN2->BTR  = ((INT32U)0 << 30)          /* 0: Normal operation mode */
//              +  ((INT32U)1 << 24)          /* 1: Resynch jump width= 2 */
//              +  ((INT32U)5 << 20)          /* 5: Time segment 2 = 6tq  */
//              +  ((INT32U)8 << 16)          /* 8: Time segment 1 = 9tq  */
//              +  ((INT32U)18 - 1);          /* Prescaler=18: Tq = 1/4us */
//   #elif (CAN2_BAUDRATE_KHZ == 500)
//    CAN2->BTR  = ((INT32U)0 << 30)          /* 0: Normal operation mode */
//              +  ((INT32U)1 << 24)          /* 1: Resynch jump width= 2 */
//              +  ((INT32U)5 << 20)          /* 5: Time segment 2 = 6tq  */
//              +  ((INT32U)8 << 16)          /* 8: Time segment 1 = 9tq  */
//              +  ((INT32U)9 - 1);           /* Prescaler=9:  Tq = 1/8us */
//   #elif (CAN2_BAUDRATE_KHZ == 1000)
//    CAN2->BTR  = ((INT32U)0 << 30)          /* 0: Normal operation mode */
//              +  ((INT32U)0 << 24)          /* 0: Resynch jump width= 1 */
//              +  ((INT32U)2 << 20)          /* 2: Time segment 2 = 3tq  */
//              +  ((INT32U)3 << 16)          /* 3: Time segment 1 = 4tq  */
//              +  ((INT32U)9 - 1);           /* Prescaler=9:  Tq = 1/8us */
//   #endif
//    CAN2->MCR &= ~CAN_MCR_INRQ;             /* Request leave initialie  */
//    while((CAN2->MSR & CAN_MSR_INAK) != 0); /* Wait the acknowledge     */
//    CAN2->FMR |=  CAN_FMR_FINIT;            /* 1: Initialization mode   */
//    CAN2->FA1R =  0x00000000;               /* All Filters not active   */
//    CAN2->FMR &= ~CAN_FMR_FINIT;            /* 0: Active filters mode   */
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */