/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File SCI3Cortex.c                       */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   SCI3_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                              SCI3Init ()                             */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
void SCI3Init (void)
{   usSCI3Timer = 0;
    usSCI3Status = 0;
    SCI3BufInit();
    SCI3HardInit();
}
#endif

/* ******************************************************************** */
/*                              SCI3Start ()                            */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
void SCI3Start (void)
{   SCI3_SCI_RX_EN();
    SCI3_SCI_TX_EN();
    SCI3_SCI_RX_INT_EN();
    SCI3_SCI_TC_INT_DIS();
}
#endif

/* ******************************************************************** */
/*                            SCI3TaskLoop ()                           */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
void SCI3TaskLoop (void)
{  // INT08U ucComd, ucErr;
   // while (1)
   // {   ucComd = SCI3GetChar (SCI3_RX_TO_TICKS, &ucErr);
   // }
    (void)OSTaskSuspend(OS_PRIO_SELF);
}
#endif

/* ******************************************************************** */
/*                           SCI3TxRxIntHook ()                         */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
void SCI3TxRxIntHook (void)
{   INT08U ucDat, ucErr;
    if ((USART3->SR & USART_SR_RXNE) != 0)
    {   ucDat = (INT08U)USART3->DR;
        SCI3PutRxChar(ucDat);
    }
    else if ((USART3->SR & USART_SR_TC) != 0)
    {   ucDat = SCI3GetTxChar(&ucErr);
        if (ucErr == SCI3_NO_ERR)
        {   SCI3_SCI_RX_DIS();
            USART3->DR = ucDat;
        }   else
        {   SCI3_SCI_TC_INT_DIS();
            SCI3_SCI_RX_EN();
        }
    }
}
#endif

/* ******************************************************************** */
/*                           SCI3CheckTime ()                           */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
INT08U SCI3CheckTime (INT16U usOld, INT16U usPer)
{   INT16U usTemp;
    usTemp = (INT16U)(usSCI3Timer - usOld);
    if (usTemp >= usPer)
    {   return SCI3_TRUE;
    }   else
    {   return SCI3_FALSE;
    }
}
#endif

/* ******************************************************************** */
/*                          SCI3BufInit()                               */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
void SCI3BufInit (void)
{   SCI3_RING_STR *pbuf;
    pbuf = &sSCI3RingBuf;
    pbuf->usRingBufRxCtr   =  0;
    pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxOutPtr = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxSem    =  OSSemCreate(0);
    pbuf->usRingBufTxCtr   =  0;
    pbuf->pRingBufTxInPtr  = &pbuf->ucRingBufTx[0];
    pbuf->pRingBufTxOutPtr = &pbuf->ucRingBufTx[0];
    pbuf->pRingBufTxSem    =  OSSemCreate(SCI3_TX_BUF_SIZE);
}
#endif

/* ******************************************************************** */
/*                          SCI3IsTxFull()                              */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
INT08U SCI3IsTxFull (void)
{   OS_CPU_SR cpu_sr = 0;
    SCI3_RING_STR *pbuf;
    pbuf = &sSCI3RingBuf;
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufTxCtr >= SCI3_TX_BUF_SIZE)
    {   OS_EXIT_CRITICAL();
        return SCI3_TRUE;
    }   else
    {   OS_EXIT_CRITICAL();
        return SCI3_FALSE;
    }
}
#endif

/* ******************************************************************** */
/*                          SCI3IsRxEmpty()                             */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
INT08U SCI3IsRxEmpty (void)
{   OS_CPU_SR cpu_sr = 0;
    SCI3_RING_STR *pbuf;
    pbuf = &sSCI3RingBuf;
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufRxCtr == 0)
    {   OS_EXIT_CRITICAL();
        return SCI3_TRUE;
    }   else
    {   OS_EXIT_CRITICAL();
        return SCI3_FALSE;
    }
}
#endif

/* ******************************************************************** */
/*                          SCI3PutRxChar()                             */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
void SCI3PutRxChar (INT08U c)
{   SCI3_RING_STR *pbuf;
    pbuf = &sSCI3RingBuf;
    if (pbuf->usRingBufRxCtr < SCI3_RX_BUF_SIZE)
    {   pbuf->usRingBufRxCtr++;
        *pbuf->pRingBufRxInPtr++ = c;
        if (pbuf->pRingBufRxInPtr == &pbuf->ucRingBufRx[SCI3_RX_BUF_SIZE])
        {   pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufRxSem);
    }
}
#endif

/* ******************************************************************** */
/*                          SCI3GetTxChar()                             */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
INT08U SCI3GetTxChar (INT08U *err)
{   INT08U c;
    SCI3_RING_STR *pbuf;
    pbuf = &sSCI3RingBuf;
    if (pbuf->usRingBufTxCtr > 0)
    {   pbuf->usRingBufTxCtr--;
        c = *pbuf->pRingBufTxOutPtr++;
        if (pbuf->pRingBufTxOutPtr == &pbuf->ucRingBufTx[SCI3_TX_BUF_SIZE])
        {   pbuf->pRingBufTxOutPtr  = &pbuf->ucRingBufTx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufTxSem);
        *err = SCI3_NO_ERR;
        return c;
    }   else
    {   *err = SCI3_ERR_TX_EMPTY;
        return 0;
    }
}
#endif

/* ******************************************************************** */
/*                           SCI3GetChar()                              */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
INT08U SCI3GetChar (INT16U to, INT08U *err)
{   OS_CPU_SR cpu_sr = 0;
    INT08U c, oserr;
    SCI3_RING_STR *pbuf;
    pbuf = &sSCI3RingBuf;
    (void)OSSemPend(pbuf->pRingBufRxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   *err   = SCI3_ERR_RX_TIMEOUT;
        return 0;
    }
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufRxCtr == 0)
    {   *err = SCI3_ERR_RX_TIMEOUT;
        OS_EXIT_CRITICAL();
        return 0;
    }
    pbuf->usRingBufRxCtr--;
    c = *pbuf->pRingBufRxOutPtr++;
    if (pbuf->pRingBufRxOutPtr == &pbuf->ucRingBufRx[SCI3_RX_BUF_SIZE])
    {   pbuf->pRingBufRxOutPtr  = &pbuf->ucRingBufRx[0];
    }
    OS_EXIT_CRITICAL();
    *err = SCI3_NO_ERR;
    return c;
}
#endif

/* ******************************************************************** */
/*                           SCI3PutChar()                              */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
INT08U SCI3PutChar (INT16U to, INT08U c)
{   OS_CPU_SR cpu_sr = 0;
    INT08U oserr;
    SCI3_RING_STR *pbuf;
    pbuf = &sSCI3RingBuf;
    (void)OSSemPend(pbuf->pRingBufTxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   return SCI3_ERR_TX_TIMEOUT;
    }   else
    {   OS_ENTER_CRITICAL();
        pbuf->usRingBufTxCtr++;
        *pbuf->pRingBufTxInPtr++ = c;
        if (pbuf->pRingBufTxInPtr == &pbuf->ucRingBufTx[SCI3_TX_BUF_SIZE])
        {   pbuf->pRingBufTxInPtr  = &pbuf->ucRingBufTx[0];
        }
        if (pbuf->usRingBufTxCtr == 1)
        {   SCI3_SCI_RX_DIS();
            SCI3_SCI_TC_INT_EN();
        }
        OS_EXIT_CRITICAL();
        return SCI3_NO_ERR;
    }
}
#endif

/* ******************************************************************** */
/*                             SCI3HardInit ()                          */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
void SCI3HardInit (void)
{   
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */