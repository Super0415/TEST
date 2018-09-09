/* ******************************************************************** */
/*                  CAN2 Software for Elctronic Unit (V1.0)             */
/*                       Source File CAN2Cortex.c                       */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   CAN2_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                              CAN2Init()                              */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2Init (void)
{   usCAN2Timer = 0;
    usCAN2Status = 0;
    CAN2BufInit();
    SAEInit();
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
            (void)SAEProcessRxMsg(&sCAN2TaskRxMsg);
        }
        /* ********************** CAN2 RX Message ********************* */
        if (SAECheckRxAllTimeOut() == SAE_FALSE)
        {   SAE_STS_CLR_BIT(SAE_STS_RX_ERR);
        }   else
        {   SAE_STS_SET_BIT(SAE_STS_RX_ERR);
        }
        /* ********************** CAN2 TX Message ********************* */
        if (SAEProcessTxMsg(&sCAN2TaskTxMsg) == SAE_NO_ERR)
        {   SAE_STS_CLR_BIT(SAE_STS_TX_ERR);
        }   else
        {   SAE_STS_SET_BIT(SAE_STS_TX_ERR);
        }
    }
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
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */