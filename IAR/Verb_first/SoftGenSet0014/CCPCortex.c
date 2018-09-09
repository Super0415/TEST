/* ******************************************************************** */
/*                      CCP protocol Version 1.0                        */
/*                       Header File CCPCortex.C                         */
/*                              2017-11-02                              */
/* ******************************************************************** */

#define   CCP_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                         CCP10FillMsgTxReq ()                         */
/* ******************************************************************** */
#if (CCP_CCP_CCP10_ON == 1)
void CCP10FillMsgTxReq (CAN_MSG *pMsg)
{   INT16U usTemp, usSum;
    usTemp  = sCCP10TxReq.usCode;
    usSum   = usTemp;
    pMsg->DAT08.ucDat0 = CCP_UC_LOW(usTemp);
    pMsg->DAT08.ucDat1 = CCP_UC_HIGH(usTemp);
    usTemp  = sCCP10TxReq.usWhich;
    usSum  += usTemp;
    pMsg->DAT08.ucDat2 = CCP_UC_LOW(usTemp);
    pMsg->DAT08.ucDat3 = CCP_UC_HIGH(usTemp);
    usTemp  = sCCP10TxReq.usValue;
    usSum  += usTemp;
    pMsg->DAT08.ucDat4 = CCP_UC_LOW(usTemp);
    pMsg->DAT08.ucDat5 = CCP_UC_HIGH(usTemp);
    usTemp  = usSum;
    pMsg->DAT08.ucDat6 = CCP_UC_LOW(usTemp);
    pMsg->DAT08.ucDat7 = CCP_UC_HIGH(usTemp);
}
#endif

/* ******************************************************************** */
/*                         CCP10FillMsgTxPar ()                         */
/* ******************************************************************** */
#if (CCP_CCP_CCP10_ON == 1)
void CCP10FillMsgTxPar (CAN_MSG *pMsg)
{   INT16U usTemp, usSum;
    usTemp  = sCCP10TxPar.usCode;
    usSum   = usTemp;
    pMsg->DAT08.ucDat0 = CCP_UC_LOW(usTemp);
    pMsg->DAT08.ucDat1 = CCP_UC_HIGH(usTemp);
    usTemp  = sCCP10TxPar.usWhich;
    usSum  += usTemp;
    pMsg->DAT08.ucDat2 = CCP_UC_LOW(usTemp);
    pMsg->DAT08.ucDat3 = CCP_UC_HIGH(usTemp);
    usTemp  = sCCP10TxPar.usValue;
    usSum  += usTemp;
    pMsg->DAT08.ucDat4 = CCP_UC_LOW(usTemp);
    pMsg->DAT08.ucDat5 = CCP_UC_HIGH(usTemp);
    usTemp  = usSum;
    pMsg->DAT08.ucDat6 = CCP_UC_LOW(usTemp);
    pMsg->DAT08.ucDat7 = CCP_UC_HIGH(usTemp);
}
#endif

/* ******************************************************************** */
/*                         CCP10DecodeRxPar ()                          */
/* ******************************************************************** */
#if (CCP_CCP_CCP10_ON == 1)
void CCP10DecodeRxPar (CAN_MSG *pMsg)
{   INT16U usD0, usD1, usD2, usD3;
    usD0 = CCP_US_CREAT(pMsg->DAT08.ucDat0, pMsg->DAT08.ucDat1);
    usD1 = CCP_US_CREAT(pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat3);
    usD2 = CCP_US_CREAT(pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat5);
    usD3 = CCP_US_CREAT(pMsg->DAT08.ucDat6, pMsg->DAT08.ucDat7);
    if (usD3 == (usD0 + usD1 + usD2))
    {   sCCP10RxPar.usCode  = usD0;
        sCCP10RxPar.usWhich = usD1;
        sCCP10RxPar.usValue = usD2;
    }
}
#endif

/* ******************************************************************** */
/*                         CCP10DecodeRxReq ()                          */
/* ******************************************************************** */
#if (CCP_CCP_CCP10_ON == 1)
INT08U CCP10DecodeRxReq (CAN_MSG *pMsg)
{   INT16U usComd, usWhich;
    sCCP10RxReq.usCode  = CCP_US_CREAT(pMsg->DAT08.ucDat0, pMsg->DAT08.ucDat1);
    sCCP10RxReq.usWhich = CCP_US_CREAT(pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat3);
    sCCP10RxReq.usValue = CCP_US_CREAT(pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat5);
    usWhich             = CCP_US_CREAT(pMsg->DAT08.ucDat6, pMsg->DAT08.ucDat7);
    usComd = sCCP10RxReq.usCode + sCCP10RxReq.usWhich + sCCP10RxReq.usValue;
    if (usComd != usWhich)
    {   return CCP_FALSE;
    }
    usComd  = sCCP10RxReq.usWhich & CCP_CCP10_IS_MASK;
    usWhich = sCCP10RxReq.usWhich - usComd;
    if (sCCP10RxReq.usCode == CCP_CCP10_CODE_READ)
    {   if (usComd == CCP_CCP10_IS_PARAM)
        {   if (usWhich < DB_PARAM_SIZE)
            {   sCCP10TxPar.usCode  = CCP_CCP10_CODE_PARA;
                sCCP10TxPar.usWhich = usWhich + usComd;
                sCCP10TxPar.usValue = aDBParam[usWhich];
                return CCP_TRUE;
            }
        }
        else if (usComd == CCP_CCP10_IS_MEASU)
        {   if (usWhich < DB_MEASU_SIZE)
            {   sCCP10TxPar.usCode  = CCP_CCP10_CODE_PARA;
                sCCP10TxPar.usWhich = usWhich + usComd;
                sCCP10TxPar.usValue = aDBMeasu[usWhich];
                return CCP_TRUE;
            }
        }
        else if (usComd == CCP_CCP10_IS_FUNCT)
        {   if (usWhich < DB_FUNCT_SIZE)
            {   sCCP10TxPar.usCode  = CCP_CCP10_CODE_PARA;
                sCCP10TxPar.usWhich = usWhich + usComd;
                sCCP10TxPar.usValue = aDBFunct[usWhich];
                return CCP_TRUE;
            }
        }
        else if (usComd == CCP_CCP10_IS_CURVE)
        {   if (usWhich < DB_CURVE_SIZE)
            {   sCCP10TxPar.usCode  = CCP_CCP10_CODE_PARA;
                sCCP10TxPar.usWhich = usWhich + usComd;
                sCCP10TxPar.usValue = aDBCurve[usWhich];
                return CCP_TRUE;
            }
        }
    }
    else if (sCCP10RxReq.usCode == CCP_CCP10_CODE_WRITE)
    {   if (usComd == CCP_CCP10_IS_PARAM)
        {   if (usWhich < DB_PARAM_SIZE)
            {   aDBParam[usWhich] = sCCP10RxReq.usValue;
            }
        }
        else if (usComd == CCP_CCP10_IS_MEASU)
        {   if (usWhich < DB_MEASU_SIZE)
            {   aDBMeasu[usWhich] = sCCP10RxReq.usValue;
            }
        }
        else if (usComd == CCP_CCP10_IS_FUNCT)
        {   if (usWhich < DB_FUNCT_SIZE)
            {   aDBFunct[usWhich] = sCCP10RxReq.usValue;
            }
        }
        else if (usComd == CCP_CCP10_IS_CURVE)
        {   if (usWhich < DB_CURVE_SIZE)
            {   aDBCurve[usWhich] = sCCP10RxReq.usValue;
            }
        }
    }
    else if ((sCCP10RxReq.usCode == CCP_CCP10_CODE_SAVE) && (usWhich == 0))
    {   if (usComd == CCP_CCP10_IS_PARAM)
        {   DBTskPutCmd(DB_CMD_SAVE_PARAM);
        }
        else if (usComd == CCP_CCP10_IS_MEASU)
        {   DBTskPutCmd(DB_CMD_SAVE_MEASU);
            DBTskPutCmd(DB_CMD_SAVE_HSTRY);
        }
        else if (usComd == CCP_CCP10_IS_FUNCT)
        {   DBTskPutCmd(DB_CMD_SAVE_FUNCT);
        }
        else if (usComd == CCP_CCP10_IS_CURVE)
        {   DBTskPutCmd(DB_CMD_SAVE_CURVE);
            DBTskPutCmd(DB_CMD_SAVE_STAT);
        }
    }
    return CCP_FALSE;
}
#endif

/* ******************************************************************** */
/*                         CCP10CmdParaSave ()                          */
/* ******************************************************************** */
#if (CCP_CCP_CCP10_ON == 1)
INT08U CCP10CmdParaSave (INT16U usWhich)
{   OS_CPU_SR cpu_sr = 0;
    if (SAE_GET_TXPGN_ENABLE(SAE_TX_PGN_CCP10REQ) == SAE_DISABLE)
    {   return CCP_FALSE;
    }
    OS_ENTER_CRITICAL();
    if (SAE_GET_TXPGN_STATE(SAE_TX_PGN_CCP10REQ) != SAE_CODE_FREE)
    {   OS_EXIT_CRITICAL();
        OSTimeDly(2);
        OS_ENTER_CRITICAL();
        if (SAE_GET_TXPGN_STATE(SAE_TX_PGN_CCP10REQ) != SAE_CODE_FREE)
        {   OS_EXIT_CRITICAL();
            return CCP_FALSE;
        }
    }
    sCCP10TxReq.usCode  = CCP_CCP10_CODE_SAVE;
    sCCP10TxReq.usWhich = usWhich;
    sCCP10TxReq.usValue = 0;
    SAE_SET_TXPGN_IMMED(SAE_TX_PGN_CCP10REQ);
    OS_EXIT_CRITICAL();
    return CCP_TRUE;
}
#endif

/* ******************************************************************** */
/*                         CCP10CmdParaWrite ()                         */
/* ******************************************************************** */
#if (CCP_CCP_CCP10_ON == 1)
INT08U CCP10CmdParaWrite (INT16U usWhich, INT16U usValue)
{   OS_CPU_SR cpu_sr = 0;
    if (SAE_GET_TXPGN_ENABLE(SAE_TX_PGN_CCP10REQ) == SAE_DISABLE)
    {   return CCP_FALSE;
    }
    OS_ENTER_CRITICAL();
    if (SAE_GET_TXPGN_STATE(SAE_TX_PGN_CCP10REQ) != SAE_CODE_FREE)
    {   OS_EXIT_CRITICAL();
        OSTimeDly(2);
        OS_ENTER_CRITICAL();
        if (SAE_GET_TXPGN_STATE(SAE_TX_PGN_CCP10REQ) != SAE_CODE_FREE)
        {   OS_EXIT_CRITICAL();
            return CCP_FALSE;
        }
    }
    sCCP10TxReq.usCode  = CCP_CCP10_CODE_WRITE;
    sCCP10TxReq.usWhich = usWhich;
    sCCP10TxReq.usValue = usValue;
    SAE_SET_TXPGN_IMMED(SAE_TX_PGN_CCP10REQ);
    OS_EXIT_CRITICAL();
    return CCP_TRUE;
}
#endif

/* ******************************************************************** */
/*                         CCP10CmdParaRead ()                          */
/* ******************************************************************** */
#if (CCP_CCP_CCP10_ON == 1)
INT08U CCP10CmdParaRead (INT16U usWhich, INT16U *pResult)
{   static INT08U ucCcp10Reading = 0;
    OS_CPU_SR cpu_sr = 0;
    if (SAE_GET_TXPGN_ENABLE(SAE_TX_PGN_CCP10REQ) == SAE_DISABLE)
    {   return CCP_FALSE;
    }
    OS_ENTER_CRITICAL();
    if (ucCcp10Reading != 0)
    {   OS_EXIT_CRITICAL();
        return SAE_FALSE;
    }
    if (SAE_GET_TXPGN_STATE(SAE_TX_PGN_CCP10REQ) != SAE_CODE_FREE)
    {   OS_EXIT_CRITICAL();
        OSTimeDly(2);
        OS_ENTER_CRITICAL();
        if (SAE_GET_TXPGN_STATE(SAE_TX_PGN_CCP10REQ) != SAE_CODE_FREE)
        {   OS_EXIT_CRITICAL();
            return CCP_FALSE;
        }
    }
    ucCcp10Reading      = 1;
    sCCP10RxPar.usCode  = 0;
    sCCP10RxPar.usWhich = 0;
    sCCP10RxPar.usValue = 0;
    sCCP10TxReq.usCode  = CCP_CCP10_CODE_READ;
    sCCP10TxReq.usWhich = usWhich;
    sCCP10TxReq.usValue = 0;
    SAE_SET_TXPGN_IMMED(SAE_TX_PGN_CCP10REQ);
    OS_EXIT_CRITICAL();
    OSTimeDly(1);
    if((sCCP10RxPar.usCode == CCP_CCP10_CODE_PARA) && (sCCP10RxPar.usWhich == usWhich))
    {   *pResult = sCCP10RxPar.usValue;
        ucCcp10Reading = 0;
        return SAE_TRUE;
    }
    OSTimeDly(1);
    if((sCCP10RxPar.usCode == CCP_CCP10_CODE_PARA) && (sCCP10RxPar.usWhich == usWhich))
    {   *pResult = sCCP10RxPar.usValue;
        ucCcp10Reading = 0;
        return SAE_TRUE;
    }
    OSTimeDly(1);
    if((sCCP10RxPar.usCode == CCP_CCP10_CODE_PARA) && (sCCP10RxPar.usWhich == usWhich))
    {   *pResult = sCCP10RxPar.usValue;
        ucCcp10Reading = 0;
        return SAE_TRUE;
    }
    OSTimeDly(1);
    if((sCCP10RxPar.usCode == CCP_CCP10_CODE_PARA) && (sCCP10RxPar.usWhich == usWhich))
    {   *pResult = sCCP10RxPar.usValue;
        ucCcp10Reading = 0;
        return SAE_TRUE;
    }
    OSTimeDly(1);
    if((sCCP10RxPar.usCode == CCP_CCP10_CODE_PARA) && (sCCP10RxPar.usWhich == usWhich))
    {   *pResult = sCCP10RxPar.usValue;
        ucCcp10Reading = 0;
        return SAE_TRUE;
    }
    ucCcp10Reading = 0;
    return SAE_FALSE;
}
#endif

/* ******************************************************************** */
/*                            CCP21Init ()                              */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
void CCP21Init (void)
{   ucCCPActDaq      = 0;
    ucCCPActOdt      = 0;
    ucCCPActEle      = 0;
    ucCCPReqPrivil   = 0;
    ucCCPActPrivil   = 0;
    ucCCPActSssState = 0;
    ucCCPMta0AddrExt = 0;
    ucCCPMta1AddrExt = 0;
    usCCPTimer       = 0;
    usCCPStatus      = 0;
    usCCPMta0Addr    = 0;
    usCCPMta1Addr    = 0;
    uiCCPSlaveId     = CCP_ID32_SLAVE;
    CCPCanBufInit();
    CCPDaqInitAll();
}
#endif

/* ******************************************************************** */
/*                          CCPCheckTime ()                             */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
BOOL CCPCheckTime (INT16U usOld, INT16U usPer)
{   if ((INT16U)(usCCPTimer - usOld) >= usPer)
    {   return CCP_TRUE;
    }   else
    {   return CCP_FALSE;
    }
}
#endif

/* ******************************************************************** */
/*                           CCPCanBufInit()                            */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
void CCPCanBufInit (void)
{   CCP_CAN_RING *pbuf;
    pbuf = &sCCPCanCommBuf;
    pbuf->usRingBufRxCtr   =  0;
    pbuf->pRingBufRxInPtr  = &pbuf->sRingBufRx[0];
    pbuf->pRingBufRxOutPtr = &pbuf->sRingBufRx[0];
    pbuf->pRingBufRxSem    =  OSSemCreate(0);
}
#endif

/* ******************************************************************** */
/*                         CCPCanIsRxEmpty()                            */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
BOOL CCPCanIsRxEmpty (void)
{   OS_CPU_SR cpu_sr = 0;
    CCP_CAN_RING *pbuf;
    pbuf = &sCCPCanCommBuf;
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufRxCtr == 0)
    {   OS_EXIT_CRITICAL();
        return CCP_TRUE;
    }   else
    {   OS_EXIT_CRITICAL();
        return CCP_FALSE;
    }
}
#endif

/* ******************************************************************** */
/*                          CCPCanPutRxMsg()                            */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
void CCPCanPutRxMsg (CAN_MSG *msg)
{   CCP_CAN_RING *pbuf;
    CAN_MSG *pmsg, *ptmp;
    pbuf = &sCCPCanCommBuf;
    if (pbuf->usRingBufRxCtr < CCP_CAN_RX_BUF_SIZE)
    {   pbuf->usRingBufRxCtr++;
        pmsg = msg;
        ptmp = pbuf->pRingBufRxInPtr;
        ptmp->DAT32.uiID   = pmsg->DAT32.uiID;
        ptmp->DAT32.uiDat0 = pmsg->DAT32.uiDat0;
        ptmp->DAT32.uiDat1 = pmsg->DAT32.uiDat1;
        pbuf->pRingBufRxInPtr++;
        if (pbuf->pRingBufRxInPtr == &pbuf->sRingBufRx[CCP_CAN_RX_BUF_SIZE])
        {   pbuf->pRingBufRxInPtr  = &pbuf->sRingBufRx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufRxSem);
    }
}
#endif

/* ******************************************************************** */
/*                           CCPCanGetMsg()                             */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
INT08U CCPCanGetMsg (INT16U to, CAN_MSG *msg)
{   OS_CPU_SR cpu_sr = 0;
    INT08U oserr;
    CCP_CAN_RING *pbuf;
    CAN_MSG *pmsg, *ptmp;
    pbuf = &sCCPCanCommBuf;
    OSSemPend(pbuf->pRingBufRxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   return OS_ERR_RX_TIMEOUT;
    }   else
    {   pmsg = msg;
        OS_ENTER_CRITICAL();
        pbuf->usRingBufRxCtr--;
        ptmp = pbuf->pRingBufRxOutPtr;
        pmsg->DAT32.uiID   = ptmp->DAT32.uiID;
        pmsg->DAT32.uiDat0 = ptmp->DAT32.uiDat0;
        pmsg->DAT32.uiDat1 = ptmp->DAT32.uiDat1;
        pbuf->pRingBufRxOutPtr++;
        if (pbuf->pRingBufRxOutPtr == &pbuf->sRingBufRx[CCP_CAN_RX_BUF_SIZE])
        {   pbuf->pRingBufRxOutPtr  = &pbuf->sRingBufRx[0];
        }
        OS_EXIT_CRITICAL();
        return OS_NO_ERR;
    }
}
#endif

/* ******************************************************************** */
/*                          CCPGetChkSum ()                             */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
INT16U CCPGetChkSum (INT16U usAddr, INT16U usSize)
{   INT16U usSum = 0;
    while (usSize--)
    {   usSum += (INT16U)CCPGetEcuData8(usAddr++);
    }
    return usSum;
}
#endif

/* ******************************************************************** */
/*                          CCPClearMemory ()                           */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
void CCPClearMemory (INT16U usAddr, INT16U usSize)
{   while (usSize--)
    {   CCPSetEcuData8(usAddr++,0);
    }
}
#endif

/* ******************************************************************** */
/*                          CCPMoveMemory ()                            */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
void CCPMoveMemory (INT16U usSour, INT16U usDest, INT16U usSize)
{   while (usSize--)
    {   CCPSetEcuData8(usDest++,CCPGetEcuData8(usSour++));
    }
}
#endif

/* ******************************************************************** */
/*                          CCPGetEcuData8 ()                           */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
INT08U CCPGetEcuData8 (INT16U usWhich)
{   if (usWhich < (DB_PARAM_SIZE * 2))
    {   return *((INT08U*)aDBParam + usWhich);
    }
    usWhich -= DB_PARAM_SIZE * 2;
    if (usWhich < (DB_MEASU_SIZE * 2))
    {   return *((INT08U*)aDBMeasu + usWhich);
    }
    usWhich -= DB_MEASU_SIZE * 2;
    if (usWhich < (DB_FUNCT_SIZE * 2))
    {   return *((INT08U*)aDBFunct + usWhich);
    }
    usWhich -= DB_FUNCT_SIZE * 2;
    if (usWhich < (DB_CURVE_SIZE * 2))
    {   return *((INT08U*)aDBCurve + usWhich);
    }
    usWhich -= DB_CURVE_SIZE * 2;
    if (usWhich < 4)
    {   return *((INT08U*)(&uiCCPSlaveId) + usWhich);
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                          CCPGetEcuData16 ()                          */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
INT16U CCPGetEcuData16 (INT16U usWhich)
{   if (usWhich < DB_PARAM_SIZE)
    {   return aDBParam[usWhich];
    }
    usWhich -= DB_PARAM_SIZE;
    if (usWhich < DB_MEASU_SIZE)
    {   return aDBMeasu[usWhich];
    }
    usWhich -= DB_MEASU_SIZE;
    if (usWhich < DB_FUNCT_SIZE)
    {   return aDBFunct[usWhich];
    }
    usWhich -= DB_FUNCT_SIZE;
    if (usWhich < DB_CURVE_SIZE)
    {   return aDBCurve[usWhich];
    }
    usWhich -= DB_CURVE_SIZE;
    if (usWhich < 2)
    {   return *((INT16U*)(&uiCCPSlaveId) + usWhich);
    }
    return 0;
}
#endif

/* ******************************************************************** */
/*                          CCPSetEcuData8 ()                           */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
void CCPSetEcuData8 (INT16U usWhich, INT08U ucValue)
{   if (usWhich < (DB_PARAM_SIZE * 2))
    {   *((INT08U*)aDBParam + usWhich) = ucValue;
        return;
    }
    usWhich -= DB_PARAM_SIZE * 2;
    if (usWhich < (DB_MEASU_SIZE * 2))
    {   *((INT08U*)aDBMeasu + usWhich) = ucValue;
        return;
    }
    usWhich -= DB_MEASU_SIZE * 2;
    if (usWhich < (DB_FUNCT_SIZE * 2))
    {   *((INT08U*)aDBFunct + usWhich) = ucValue;
        return;
    }
    usWhich -= DB_FUNCT_SIZE * 2;
    if (usWhich < (DB_CURVE_SIZE * 2))
    {   *((INT08U*)aDBCurve + usWhich) = ucValue;
        return;
    }
    usWhich -= DB_CURVE_SIZE * 2;
    if (usWhich < 4)
    {   *((INT08U*)(&uiCCPSlaveId) + usWhich) = ucValue;
    }
}
#endif

/* ******************************************************************** */
/*                          CCPSetEcuData16 ()                          */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
void CCPSetEcuData16 (INT16U usWhich, INT16U usValue)
{   if (usWhich < DB_PARAM_SIZE)
    {   aDBParam[usWhich] = usValue;
        return;
    }
    usWhich -= DB_PARAM_SIZE;
    if (usWhich < DB_MEASU_SIZE)
    {   aDBMeasu[usWhich] = usValue;
        return;
    }
    usWhich -= DB_MEASU_SIZE;
    if (usWhich < DB_FUNCT_SIZE)
    {   aDBFunct[usWhich] = usValue;
        return;
    }
    usWhich -= DB_FUNCT_SIZE;
    if (usWhich < DB_CURVE_SIZE)
    {   aDBCurve[usWhich] = usValue;
        return;
    }
    usWhich -= DB_CURVE_SIZE;
    if (usWhich < 2)
    {   *((INT16U*)(&uiCCPSlaveId) + usWhich) = usValue;
    }
}
#endif

/* ******************************************************************** */
/*                          CCPSaveEcuData ()                           */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
void CCPSaveEcuData (void)
{ //  OSSpiPutComd(FW_SPI_SAVE_PARAM);
  //  OSSpiPutComd(FW_SPI_SAVE_MEASU);
  //  OSSpiPutComd(FW_SPI_SAVE_HIST);
  //  OSSpiPutComd(FW_SPI_SAVE_FUNCT);
  //  OSSpiPutComd(FW_SPI_SAVE_CURVE);
  //  OSSpiPutComd(FW_SPI_SAVE_STAT);
}
#endif

/* ******************************************************************** */
/*                          CCPDaqStartList ()                          */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
void CCPDaqStartList (INT08U ucList)
{   aCCPDaqList[ucList].ucState = CCP_DAQ_STAT_START;
}
#endif

/* ******************************************************************** */
/*                          CCPDaqStartAll ()                           */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
void CCPDaqStartAll (void)
{   INT08U i;
    for (i=0; i<CCP_DAQ_LIST_SIZE; i++)
    {   aCCPDaqList[i].ucState = CCP_DAQ_STAT_START;
    }
}
#endif

/* ******************************************************************** */
/*                          CCPDaqStopList ()                           */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
void CCPDaqStopList (INT08U ucList)
{   aCCPDaqList[ucList].ucState = CCP_DAQ_STAT_STOP;
}
#endif

/* ******************************************************************** */
/*                          CCPDaqStopAll ()                            */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
void CCPDaqStopAll (void)
{   INT08U i;
    for (i=0; i<CCP_DAQ_LIST_SIZE; i++)
    {   aCCPDaqList[i].ucState = CCP_DAQ_STAT_STOP;
    }
}
#endif

/* ******************************************************************** */
/*                          CCPDaqInitList ()                           */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
void CCPDaqInitList (INT08U ucList)
{   INT08U  i;
    CCP_DAQ *pDaq;
    if (ucList < CCP_DAQ_LIST_SIZE)
    {   pDaq            = &aCCPDaqList[ucList];
        ucList         *= CCP_DAQ_ODT_SIZE;
        pDaq->ucEnable  = CCP_DISABLE;
        pDaq->ucState   = CCP_DAQ_STAT_STOP;
        pDaq->ucLastOdt = 0;
        pDaq->ucEveChan = 0;
        pDaq->usTime    = usCCPTimer;
        pDaq->usPeriod  = 65535;
       #if (CCP_DAQ_USER_ID_ON == 1)
        pDaq->uiID      = CCP_ID32_TO_CPU(CCP_ID32_SLAVE);
       #endif
        for (i=0; i<CCP_DAQ_ODT_SIZE; i++)
        {   pDaq->aOdt[i].ucEnable = CCP_DISABLE;
            pDaq->aOdt[i].ucPid    = ucList + i;
            pDaq->aOdt[i].aAdr[0]  = 0xFFFF;
            pDaq->aOdt[i].aAdr[1]  = 0xFFFF;
            pDaq->aOdt[i].aAdr[2]  = 0xFFFF;
            pDaq->aOdt[i].aAdr[3]  = 0xFFFF;
            pDaq->aOdt[i].aAdr[4]  = 0xFFFF;
            pDaq->aOdt[i].aAdr[5]  = 0xFFFF;
            pDaq->aOdt[i].aAdr[6]  = 0xFFFF;
        }
    }
}
#endif

/* ******************************************************************** */
/*                            CCPDaqInitAll ()                          */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
void CCPDaqInitAll (void)
{   INT08U i;
    for (i=0; i<CCP_DAQ_LIST_SIZE; i++)
    {   CCPDaqInitList (i);
    }
}
#endif

/* ******************************************************************** */
/*                          CCPDaqSendMsg ()                            */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
void CCPDaqSendMsg (CAN_MSG *pTxMsg)
{   INT08U   i, j;
    CCP_DAQ *pDaq;
    CCP_ODT *pOdt;
    for (i=0; i<CCP_DAQ_LIST_SIZE; i++)
    {   pDaq = &aCCPDaqList[i];
       #if (CCP_DAQ_USER_ID_ON == 1)
        pTxMsg->DAT32.uiID = pDaq->uiID;
       #else
        pTxMsg->DAT32.uiID = CCP_ID32_TO_CPU(CCP_ID32_SLAVE);
       #endif
        if ((pDaq->ucEnable == CCP_DISABLE) || (pDaq->ucState != CCP_DAQ_STAT_START))
        {   continue;
        }
        if (CCPCheckTime(pDaq->usTime,pDaq->usPeriod) == CCP_FALSE)
        {   continue;
        }
        if (pDaq->ucLastOdt >= CCP_DAQ_ODT_SIZE)
        {   pDaq->ucLastOdt  = CCP_DAQ_ODT_SIZE-1;
        }
        for (j=0; j<=pDaq->ucLastOdt; j++)
        {   pOdt = &(aCCPDaqList[i].aOdt[j]);
            if (pOdt->ucEnable != CCP_DISABLE)
            {   pTxMsg->DAT08.ucDat0 = pOdt->ucPid;
                pTxMsg->DAT08.ucDat1 = CCPGetEcuData8(pOdt->aAdr[0]);
                pTxMsg->DAT08.ucDat2 = CCPGetEcuData8(pOdt->aAdr[1]);
                pTxMsg->DAT08.ucDat3 = CCPGetEcuData8(pOdt->aAdr[2]);
                pTxMsg->DAT08.ucDat4 = CCPGetEcuData8(pOdt->aAdr[3]);
                pTxMsg->DAT08.ucDat5 = CCPGetEcuData8(pOdt->aAdr[4]);
                pTxMsg->DAT08.ucDat6 = CCPGetEcuData8(pOdt->aAdr[5]);
                pTxMsg->DAT08.ucDat7 = CCPGetEcuData8(pOdt->aAdr[6]);
                (void)CCPPutCanMsg(10,pTxMsg);
            }
        }
    }
}
#endif

/* ******************************************************************** */
/*                          CCPProcessRxComd ()                         */
/* ******************************************************************** */
#if (CCP_CCP_CCP21_ON == 1)
INT08U CCPProcessRxComd (CAN_MSG *pRxMsg, CAN_MSG *pTxMsg)
{   INT08U  ucCmd, ucTmp;
    INT16U  usTmp;
   #if (CCP_DAQ_USER_ID_ON == 1)
    INT32U  uiTmp;
   #endif
    ucCmd = pRxMsg->DAT08.ucDat0;
    pTxMsg->DAT32.uiID   = CCP_ID32_TO_CPU(CCP_ID32_SLAVE);
    pTxMsg->DAT08.ucDat0 = 0xFF;
    pTxMsg->DAT08.ucDat1 = 0;
    pTxMsg->DAT08.ucDat2 = pRxMsg->DAT08.ucDat1;
    /* ********************** 1: CCP_CMD_TEST ************************* */
    if (ucCmd == CCP_CMD_TEST)
    {   (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************** 2: CCP_CMD_CONNECT ********************** */
    else if (ucCmd == CCP_CMD_CONNECT)
    {   if ((ucCCPActSssState & CCP_SS_CONNECTED) != 0)
        {   return CCP_NO_ERR;
        }
        usTmp = CCP_US_CREAT (pRxMsg->DAT08.ucDat3, pRxMsg->DAT08.ucDat2);
        if ((usTmp != CCP_STATION_ADDR) && (usTmp != CCP_BROADCAST_ADDR))
        {   return CCP_NO_ERR;
        }
        if ((ucCCPActSssState & CCP_SS_TMP_DISCONNECTED) == 0)
        {   CCPDaqStopAll();
        }
        ucCCPActSssState |= CCP_SS_CONNECTED;
        ucCCPActSssState &= ~CCP_SS_TMP_DISCONNECTED;
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************** 3: NOT CONNECTED ************************ */
    else if ((ucCCPActSssState & CCP_SS_CONNECTED) == 0)
    {   return CCP_NO_ERR;
    }
    /* ********************** 4: CCP_CMD_DISCONNECT ******************* */
    else if (ucCmd == CCP_CMD_DISCONNECT)
    {   if (pRxMsg->DAT08.ucDat2 == 0)
        {   ucCCPActSssState |= CCP_SS_TMP_DISCONNECTED;
        }
        else if ((ucCCPActSssState & CCP_SS_STORE) != 0)
        {   ucCCPActSssState &= ~CCP_SS_CONNECTED;
            CCPDaqStopAll();
            CCP21Init();
            CCPSaveEcuData();
        }
        else
        {   ucCCPActSssState &= ~CCP_SS_CONNECTED;
            CCPDaqStopAll();
            CCP21Init();
        }
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 5: CCP_CMD_GET_VERSION ******************* */
    else if (ucCmd == CCP_CMD_GET_VERSION)
    {   pTxMsg->DAT08.ucDat3 = CCP_VERSION_MAJOR;
        pTxMsg->DAT08.ucDat4 = CCP_VERSION_MINOR;
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 6: CCP_CMD_EXCHANG_ID ******************** */
    else if (ucCmd == CCP_CMD_EXCHANG_ID)
    {   usCCPMta0Addr        = CCP_ADDR_SLAVE_ID;
        pTxMsg->DAT08.ucDat3 = CCP_SLAVE_ID_LENGTH;
        pTxMsg->DAT08.ucDat4 = CCP_SLAVE_ID_TYPE;
        pTxMsg->DAT08.ucDat5 = CCP_SLAVE_AVAIL_MASK;
        pTxMsg->DAT08.ucDat6 = CCP_SLAVE_PROTECT_MASK;
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 7: CCP_CMD_SET_MTA *********************** */
    else if (ucCmd == CCP_CMD_SET_MTA)
    {   if (pRxMsg->DAT08.ucDat2 > 1)
        {   return CCP_ERR_ACCESS_DENIED;
        }
        if ((pRxMsg->DAT08.ucDat4 != 0) || (pRxMsg->DAT08.ucDat5 != 0))
        {   return CCP_ERR_ACCESS_DENIED;
        }
        usTmp = CCP_US_CREAT (pRxMsg->DAT08.ucDat6, pRxMsg->DAT08.ucDat7);
        if (usTmp >= CCP_CAL_DATA_TOTAL)
        {   return CCP_ERR_OUT_OF_RANGE;
        }
        if (pRxMsg->DAT08.ucDat2 == 0)
        {   ucCCPMta0AddrExt = pRxMsg->DAT08.ucDat3;
            usCCPMta0Addr    = usTmp;
        }   else
        {   ucCCPMta1AddrExt = pRxMsg->DAT08.ucDat3;
            usCCPMta1Addr    = usTmp;
        }
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 8: CCP_CMD_DNLOAD ************************ */
    else if (ucCmd == CCP_CMD_DNLOAD)
    {   if ((ucCCPActPrivil & CCP_PL_CAL) == 0)
        {   return CCP_ERR_ACCESS_LOCKED;
        }
        ucTmp = pRxMsg->DAT08.ucDat2;
        if (ucTmp > 5)
        {   return CCP_ERR_OUT_OF_RANGE;
        }
        usTmp = usCCPMta0Addr + (INT16U)ucTmp;
        if (usTmp > CCP_CAL_DATA_TOTAL)
        {   return CCP_ERR_ACCESS_DENIED;
        }
        if (ucTmp != 0)
        {   ucTmp -= 1;
            CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat3);
            usCCPMta0Addr += 1;
        }
        if (ucTmp != 0)
        {   ucTmp -= 1;
            CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat4);
            usCCPMta0Addr += 1;
        }
        if (ucTmp != 0)
        {   ucTmp -= 1;
            CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat5);
            usCCPMta0Addr += 1;
        }
        if (ucTmp != 0)
        {   ucTmp -= 1;
            CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat6);
            usCCPMta0Addr += 1;
        }
        if (ucTmp != 0)
        {   CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat7);
            usCCPMta0Addr += 1;
        }
        pTxMsg->DAT08.ucDat3 = ucCCPMta0AddrExt;
        pTxMsg->DAT08.ucDat4 = 0;
        pTxMsg->DAT08.ucDat5 = 0;
        pTxMsg->DAT08.ucDat6 = CCP_UC_HIGH (usCCPMta0Addr);
        pTxMsg->DAT08.ucDat7 = CCP_UC_LOW (usCCPMta0Addr);
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 9: CCP_CMD_UPLOAD ************************ */
    else if (ucCmd == CCP_CMD_UPLOAD)
    {   if ((ucCCPActPrivil & CCP_PL_DAQ) == 0)
        {   return CCP_ERR_ACCESS_LOCKED;
        }
        ucTmp = pRxMsg->DAT08.ucDat2;
        if (ucTmp > 5)
        {   return CCP_ERR_OUT_OF_RANGE;
        }
        usTmp = usCCPMta0Addr + (INT16U)ucTmp;
        if (usTmp > CCP_CAL_DATA_TOTAL)
        {   return CCP_ERR_ACCESS_DENIED;
        }
        if (ucTmp != 0)
        {   ucTmp -= 1;
            pTxMsg->DAT08.ucDat3 = CCPGetEcuData8 (usCCPMta0Addr);
            usCCPMta0Addr += 1;
        }
        if (ucTmp != 0)
        {   ucTmp -= 1;
            pTxMsg->DAT08.ucDat4 = CCPGetEcuData8 (usCCPMta0Addr);
            usCCPMta0Addr += 1;
        }
        if (ucTmp != 0)
        {   ucTmp -= 1;
            pTxMsg->DAT08.ucDat5 = CCPGetEcuData8 (usCCPMta0Addr);
            usCCPMta0Addr += 1;
        }
        if (ucTmp != 0)
        {   ucTmp -= 1;
            pTxMsg->DAT08.ucDat6 = CCPGetEcuData8 (usCCPMta0Addr);
            usCCPMta0Addr += 1;
        }
        if (ucTmp != 0)
        {   pTxMsg->DAT08.ucDat7 = CCPGetEcuData8 (usCCPMta0Addr);
            usCCPMta0Addr += 1;
        }
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 10: CCP_CMD_GET_DAQ_SIZE ***************** */
    else if (ucCmd == CCP_CMD_GET_DAQ_SIZE)
    {   if ((ucCCPActPrivil & CCP_PL_DAQ) == 0)
        {   return CCP_ERR_ACCESS_LOCKED;
        }
        ucTmp = pRxMsg->DAT08.ucDat2;
        if (ucTmp < CCP_DAQ_LIST_SIZE)
        {   CCPDaqInitList (ucTmp);
           #if (CCP_DAQ_USER_ID_ON == 1)
            uiTmp = CCP_ID_CREAT (pRxMsg->DAT08.ucDat4, pRxMsg->DAT08.ucDat5,
                                  pRxMsg->DAT08.ucDat6, pRxMsg->DAT08.ucDat7);
            aCCPDaqList[ucTmp].uiID = CCP_ID32_TO_CPU(uiTmp);
           #endif
            pTxMsg->DAT08.ucDat3 = CCP_DAQ_ODT_SIZE;
            pTxMsg->DAT08.ucDat4 = aCCPDaqList[ucTmp].aOdt[0].ucPid;
        }   else
        {   pTxMsg->DAT08.ucDat3 = 0;
            pTxMsg->DAT08.ucDat4 = 0;
        }
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 11: CCP_CMD_SET_DAQ_PTR ****************** */
    else if (ucCmd == CCP_CMD_SET_DAQ_PTR)
    {   if ((ucCCPActPrivil & CCP_PL_DAQ) == 0)
        {   return CCP_ERR_ACCESS_DENIED;
        }
        if (pRxMsg->DAT08.ucDat2 >= CCP_DAQ_LIST_SIZE)
        {   return CCP_ERR_CMD_SYNTAX;
        }
        if (pRxMsg->DAT08.ucDat3 >= CCP_DAQ_ODT_SIZE)
        {   return CCP_ERR_CMD_SYNTAX;
        }
        if (pRxMsg->DAT08.ucDat4 >= 7)
        {   return CCP_ERR_CMD_SYNTAX;
        }
        ucCCPActDaq = pRxMsg->DAT08.ucDat2;
        ucCCPActOdt = pRxMsg->DAT08.ucDat3;
        ucCCPActEle = pRxMsg->DAT08.ucDat4;
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 12: CCP_CMD_WRITE_DAQ ******************** */
    else if (ucCmd == CCP_CMD_WRITE_DAQ)
    {   if ((ucCCPActPrivil & CCP_PL_DAQ) == 0)
        {   return CCP_ERR_ACCESS_DENIED;
        }
        if ((pRxMsg->DAT08.ucDat4 != 0) || (pRxMsg->DAT08.ucDat5 != 0))
        {   return CCP_ERR_ACCESS_DENIED;
        }
        usTmp = CCP_US_CREAT (pRxMsg->DAT08.ucDat6, pRxMsg->DAT08.ucDat7);
        if (usTmp >= CCP_CAL_DATA_TOTAL)
        {   return CCP_ERR_OUT_OF_RANGE;
        }
        ucTmp = pRxMsg->DAT08.ucDat2;
        if ((ucTmp != 1) && (ucTmp != 2) && (ucTmp != 4))
        {   return CCP_ERR_CMD_SYNTAX;
        }
        aCCPDaqList[ucCCPActDaq].ucEnable = CCP_ENABLE;
        aCCPDaqList[ucCCPActDaq].aOdt[ucCCPActOdt].ucEnable = CCP_ENABLE;
        aCCPDaqList[ucCCPActDaq].aOdt[ucCCPActOdt].aAdr[ucCCPActEle] = usTmp;
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 13: CCP_CMD_START_STOP ******************* */
    else if (ucCmd == CCP_CMD_START_STOP)
    {   if ((ucCCPActPrivil & CCP_PL_DAQ) == 0)
        {   return CCP_ERR_DAQ_INIT_REQ;
        }
        if (pRxMsg->DAT08.ucDat2 > 2)
        {   return CCP_ERR_CMD_SYNTAX;
        }
        if (pRxMsg->DAT08.ucDat3 >= CCP_DAQ_LIST_SIZE)
        {   return CCP_ERR_OUT_OF_RANGE;
        }
        if (pRxMsg->DAT08.ucDat4 >= CCP_DAQ_ODT_SIZE)
        {   return CCP_ERR_OUT_OF_RANGE;
        }
        ucTmp = pRxMsg->DAT08.ucDat3;
        usTmp = CCP_US_CREAT (pRxMsg->DAT08.ucDat6, pRxMsg->DAT08.ucDat7);
        aCCPDaqList[ucTmp].ucState   = pRxMsg->DAT08.ucDat2;
        aCCPDaqList[ucTmp].ucLastOdt = pRxMsg->DAT08.ucDat4;
        aCCPDaqList[ucTmp].ucEveChan = pRxMsg->DAT08.ucDat5;
        aCCPDaqList[ucTmp].usPeriod  = usTmp * 2;
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 14: CCP_CMD_GET_SEED ********************* */
    else if (ucCmd == CCP_CMD_GET_SEED)
    {   ucCCPReqPrivil = pRxMsg->DAT08.ucDat2;
        ucTmp = ucCCPReqPrivil & ucCCPActPrivil;
        pTxMsg->DAT08.ucDat3 = ucTmp == 0 ? CCP_TRUE : CCP_FALSE;
        pTxMsg->DAT08.ucDat4 = CCP_SEED_BYTE0;
        pTxMsg->DAT08.ucDat5 = CCP_SEED_BYTE1;
        pTxMsg->DAT08.ucDat6 = CCP_SEED_BYTE2;
        pTxMsg->DAT08.ucDat7 = CCP_SEED_BYTE3;
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 15: CCP_CMD_UNLOCK *********************** */
    else if (ucCmd == CCP_CMD_UNLOCK)
    {   if (ucCCPReqPrivil > 0x03)
        {   return CCP_ERR_ACCESS_DENIED;
        }
        if ((pRxMsg->DAT08.ucDat2 != CCP_SEED_BYTE0) ||
            (pRxMsg->DAT08.ucDat3 != CCP_SEED_BYTE1) ||
            (pRxMsg->DAT08.ucDat4 != CCP_SEED_BYTE2) ||
            (pRxMsg->DAT08.ucDat5 != CCP_SEED_BYTE3) )
        {   return CCP_ERR_KEY_REQ;
        }
        ucCCPActPrivil |= ucCCPReqPrivil;
        pTxMsg->DAT08.ucDat3 = ucCCPActPrivil;
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 16: CCP_CMD_DNLOAD_6 ********************* */
    else if (ucCmd == CCP_CMD_DNLOAD_6)
    {   if ((ucCCPActPrivil & CCP_PL_CAL) == 0)
        {   return CCP_ERR_ACCESS_LOCKED;
        }
        usTmp = usCCPMta0Addr + 6;
        if (usTmp > CCP_CAL_DATA_TOTAL)
        {   return CCP_ERR_ACCESS_DENIED;
        }
        CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat2);
        usCCPMta0Addr += 1;
        CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat3);
        usCCPMta0Addr += 1;
        CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat4);
        usCCPMta0Addr += 1;
        CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat5);
        usCCPMta0Addr += 1;
        CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat6);
        usCCPMta0Addr += 1;
        CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat7);
        usCCPMta0Addr += 1;
        pTxMsg->DAT08.ucDat3 = ucCCPMta0AddrExt;
        pTxMsg->DAT08.ucDat4 = 0;
        pTxMsg->DAT08.ucDat5 = 0;
        pTxMsg->DAT08.ucDat6 = CCP_UC_HIGH (usCCPMta0Addr);
        pTxMsg->DAT08.ucDat7 = CCP_UC_LOW (usCCPMta0Addr);
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 17: CCP_CMD_SHORT_UP ********************* */
    else if (ucCmd == CCP_CMD_SHORT_UP)
    {   if ((ucCCPActPrivil & CCP_PL_DAQ) == 0)
        {   return CCP_ERR_ACCESS_LOCKED;
        }
        if ((pRxMsg->DAT08.ucDat4 != 0) || (pRxMsg->DAT08.ucDat5 != 0))
        {   return CCP_ERR_ACCESS_DENIED;
        }
        ucTmp  = pRxMsg->DAT08.ucDat2;
        if (ucTmp > 5)
        {   return CCP_ERR_OUT_OF_RANGE;
        }
        usTmp  = CCP_US_CREAT (pRxMsg->DAT08.ucDat6, pRxMsg->DAT08.ucDat7);
        usTmp += (INT16U)ucTmp;
        if (usTmp > CCP_CAL_DATA_TOTAL)
        {   return CCP_ERR_OUT_OF_RANGE;
        }
        usTmp -= (INT16U)ucTmp;
        if (ucTmp != 0)
        {   ucTmp -= 1;
            pTxMsg->DAT08.ucDat3 = CCPGetEcuData8 (usTmp);
            usTmp += 1;
        }
        if (ucTmp != 0)
        {   ucTmp -= 1;
            pTxMsg->DAT08.ucDat4 = CCPGetEcuData8 (usTmp);
            usTmp += 1;
        }
        if (ucTmp != 0)
        {   ucTmp -= 1;
            pTxMsg->DAT08.ucDat5 = CCPGetEcuData8 (usTmp);
            usTmp += 1;
        }
        if (ucTmp != 0)
        {   ucTmp -= 1;
            pTxMsg->DAT08.ucDat6 = CCPGetEcuData8 (usTmp);
            usTmp += 1;
        }
        if (ucTmp != 0)
        {   pTxMsg->DAT08.ucDat7 = CCPGetEcuData8 (usTmp);
        }
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 18: CCP_CMD_SET_CAL_PAGE ***************** */
    else if (ucCmd == CCP_CMD_SET_CAL_PAGE)
    {   (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 19: CCP_CMD_GET_CAL_PAGE ***************** */
    else if (ucCmd == CCP_CMD_GET_CAL_PAGE)
    {   pTxMsg->DAT08.ucDat3 = 0;
        pTxMsg->DAT08.ucDat4 = 0;
        pTxMsg->DAT08.ucDat5 = 0;
        pTxMsg->DAT08.ucDat6 = 0;
        pTxMsg->DAT08.ucDat7 = 0;
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 20: CCP_CMD_SET_S_STATUS ***************** */
    else if (ucCmd == CCP_CMD_SET_S_STATUS)
    {   ucTmp = pRxMsg->DAT08.ucDat2;
        ucCCPActSssState &= ~(CCP_SS_STORE | CCP_SS_RESUME);
        ucCCPActSssState |=  (CCP_SS_STORE | CCP_SS_RESUME) & ucTmp;
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 21: CCP_CMD_GET_S_STATUS ***************** */
    else if (ucCmd == CCP_CMD_GET_S_STATUS)
    {   pTxMsg->DAT08.ucDat3 = ucCCPActSssState;
        pTxMsg->DAT08.ucDat4 = 0;
        pTxMsg->DAT08.ucDat5 = 0;
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 22: CCP_CMD_BUILD_CHKSUM ***************** */
    else if (ucCmd == CCP_CMD_BUILD_CHKSUM)
    {   if ((ucCCPActPrivil & CCP_PL_DAQ) == 0)
        {   return CCP_ERR_ACCESS_LOCKED;
        }
        usTmp = CCP_US_CREAT (pRxMsg->DAT08.ucDat4, pRxMsg->DAT08.ucDat5);
        usTmp = CCPGetChkSum (usCCPMta0Addr, usTmp);
        pTxMsg->DAT08.ucDat3 = 2;
        pTxMsg->DAT08.ucDat4 = 0;
        pTxMsg->DAT08.ucDat5 = 0;
        pTxMsg->DAT08.ucDat6 = CCP_UC_HIGH (usTmp);
        pTxMsg->DAT08.ucDat7 = CCP_UC_LOW (usTmp);
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 23: CCP_CMD_CLEAR_MEMORY ***************** */
    else if (ucCmd == CCP_CMD_CLEAR_MEMORY)
    {   if ((ucCCPActPrivil & CCP_PL_CAL) == 0)
        {   return CCP_ERR_ACCESS_LOCKED;
        }
        usTmp = CCP_US_CREAT (pRxMsg->DAT08.ucDat4, pRxMsg->DAT08.ucDat5);
        CCPClearMemory (usCCPMta0Addr, usTmp);
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 24: CCP_CMD_PROGRAM ********************** */
    else if (ucCmd == CCP_CMD_PROGRAM)
    {   if ((ucCCPActPrivil & CCP_PL_PGM) == 0)
        {   return CCP_ERR_ACCESS_DENIED;
        }
        ucTmp = pRxMsg->DAT08.ucDat2;
        if (ucTmp != 0)
        {   ucTmp -= 1;
            CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat3);
            usCCPMta0Addr += 1;
        }
        if (ucTmp != 0)
        {   ucTmp -= 1;
            CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat4);
            usCCPMta0Addr += 1;
        }
        if (ucTmp != 0)
        {   ucTmp -= 1;
            CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat5);
            usCCPMta0Addr += 1;
        }
        if (ucTmp != 0)
        {   ucTmp -= 1;
            CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat6);
            usCCPMta0Addr += 1;
        }
        if (ucTmp != 0)
        {   CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat7);
            usCCPMta0Addr += 1;
        }
        pTxMsg->DAT08.ucDat3 = ucCCPMta0AddrExt;
        pTxMsg->DAT08.ucDat4 = 0;
        pTxMsg->DAT08.ucDat5 = 0;
        pTxMsg->DAT08.ucDat6 = CCP_UC_HIGH (usCCPMta0Addr);
        pTxMsg->DAT08.ucDat7 = CCP_UC_LOW (usCCPMta0Addr);
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 25: CCP_CMD_PROGRAM_6 ******************** */
    else if (ucCmd == CCP_CMD_PROGRAM_6)
    {   if ((ucCCPActPrivil & CCP_PL_PGM) == 0)
        {   return CCP_ERR_ACCESS_DENIED;
        }
        CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat2);
        usCCPMta0Addr += 1;
        CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat3);
        usCCPMta0Addr += 1;
        CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat4);
        usCCPMta0Addr += 1;
        CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat5);
        usCCPMta0Addr += 1;
        CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat6);
        usCCPMta0Addr += 1;
        CCPSetEcuData8 (usCCPMta0Addr, pRxMsg->DAT08.ucDat7);
        usCCPMta0Addr += 1;
        pTxMsg->DAT08.ucDat3 = ucCCPMta0AddrExt;
        pTxMsg->DAT08.ucDat4 = 0;
        pTxMsg->DAT08.ucDat5 = 0;
        pTxMsg->DAT08.ucDat6 = CCP_UC_HIGH (usCCPMta0Addr);
        pTxMsg->DAT08.ucDat7 = CCP_UC_LOW (usCCPMta0Addr);
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 26: CCP_CMD_MOVE ************************* */
    else if (ucCmd == CCP_CMD_MOVE)
    {   if ((ucCCPActPrivil & CCP_PL_CAL) == 0)
        {   return CCP_ERR_ACCESS_LOCKED;
        }
        usTmp = CCP_US_CREAT (pRxMsg->DAT08.ucDat4, pRxMsg->DAT08.ucDat5);
        CCPMoveMemory (usCCPMta0Addr, usCCPMta1Addr, usTmp);
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 27: CCP_CMD_DIAG_SERVICE ***************** */
    else if (ucCmd == CCP_CMD_DIAG_SERVICE)
    {   if ((ucCCPActPrivil & CCP_PL_CAL) == 0)
        {   return CCP_ERR_ACCESS_LOCKED;
        }
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 28: CCP_CMD_ACTION_SERVICE *************** */
    else if (ucCmd == CCP_CMD_ACTION_SERVICE)
    {   if ((ucCCPActPrivil & CCP_PL_CAL) == 0)
        {   return CCP_ERR_ACCESS_LOCKED;
        }
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 29: CCP_CMD_START_STOP_ALL *************** */
    else if (ucCmd == CCP_CMD_START_STOP_ALL)
    {   if ((ucCCPActPrivil & CCP_PL_DAQ) == 0)
        {   return CCP_ERR_DAQ_INIT_REQ;
        }
        if (pRxMsg->DAT08.ucDat2 > 1)
        {   return CCP_ERR_CMD_SYNTAX;
        }
        if (pRxMsg->DAT08.ucDat2 == CCP_DAQ_STAT_STOP)
        {   CCPDaqStopAll();
        }   else
        {   CCPDaqStartAll();
        }
        (void)CCPPutCanMsg(10,pTxMsg);
        return CCP_NO_ERR;
    }
    /* ********************* 30: FAULT CONDITION ********************** */
    else
    {   return CCP_ERR_CMD_UNKNOWN;
    }
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */