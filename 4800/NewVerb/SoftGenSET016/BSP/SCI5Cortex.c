/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File SCI5Cortex.c                       */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   SCI5_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                              SCI5Init ()                             */
/* ******************************************************************** */
#if (SCI5_FUNCTION_ON == 1)
void SCI5Init (void)
{   uiSCI5Status = 0;
    (void)SCI5BufInit();
    (void)SCI5HardInit(SCI5_BAUDRATE_DEF);
}
#endif

/* ******************************************************************** */
/*                              SCI5Start ()                            */
/* ******************************************************************** */
#if (SCI5_FUNCTION_ON == 1)
void SCI5Start (void)
{   SCI5_SCI_TX_EN();
    SCI5_SCI_TC_INT_DIS();
    SCI5_SCI_RX_EN();
    SCI5_SCI_RX_INT_EN();
    (void)FWIrqEnable(UART5_IRQn, FW_IRQ_PRIO_LOW);
}
#endif

/* ******************************************************************** */
/*                            SCI5TaskLoop ()                           */
/* ******************************************************************** */
#if (SCI5_FUNCTION_ON == 1)
void SCI5TaskLoop (void)
{   INT08U ucComd, ucChar, ucPF, ucErr;
    INT16U usWhich, usValue;
    while (1)
    {   ucComd = SCI5GetChar (SCI5_RX_TO_TICKS, &ucErr);
        NumTemp[7]++;
        if (ucErr  ==  SCI5_NO_ERR)
        {   ucPF    =  ucComd;
            ucChar  =  ucComd & SCI5_SCI_DO_MASK;
            usWhich = (INT16U)(ucComd & SCI5_SCI_H4_MASK) << 8;
            /* ******************** SCI5 Data Query ******************* */
            if (ucChar  ==  SCI5_SCI_DO_QUERY)
            {   ucChar   =  SCI5GetChar(SCI5_RX_TO_TICKS, &ucErr);
                ucPF    +=  ucChar;
                usWhich += (INT16U)ucChar;
                ucChar   =  SCI5GetChar(SCI5_RX_TO_TICKS, &ucErr);
                if ((ucErr == SCI5_NO_ERR) && (ucChar == ucPF))
                {   ucComd &= SCI5_SCI_IS_MASK;
                    if (ucComd == SCI5_SCI_IS_PARAM)
                    {   ucComd  = SCI5_TRUE;
                        usValue = DBGetParam16u(usWhich);
                    }
                    else if (ucComd == SCI5_SCI_IS_MEASU)
                    {   ucComd  = SCI5_TRUE;
                        usValue = DBGetMeasu16u(usWhich);
                    }
                    else if (ucComd == SCI5_SCI_IS_FUNCT)
                    {   ucComd  = SCI5_TRUE;
                        usValue = DBGetFunct16u(usWhich);
                    }
                    else if (ucComd == SCI5_SCI_IS_CURVE)
                    {   ucComd  = SCI5_TRUE;
                        usValue = DBGetCurve16u(usWhich);
                    }
                    else
                    {   ucComd  = SCI5_FALSE;
                    }
                    if (ucComd != SCI5_FALSE)
                    {   ucChar  = (INT08U)(usValue >> 8);
                        ucPF    =  ucChar;
                        (void)SCI5PutChar(SCI5_RX_TO_TICKS, ucChar);
                        ucChar  = (INT08U)usValue;
                        ucPF   +=  ucChar;
                        (void)SCI5PutChar(SCI5_RX_TO_TICKS, ucChar);
                        (void)SCI5PutChar(SCI5_RX_TO_TICKS, ucPF);
                    }
                }
            }
            /* ******************** SCI5 Data Modify ****************** */
            else if (ucChar == SCI5_SCI_DO_MODIFY)
            {   ucChar   =  SCI5GetChar(SCI5_RX_TO_TICKS, &ucErr);
                ucPF    +=  ucChar;
                usWhich += (INT16U)ucChar;
                ucChar   =  SCI5GetChar(SCI5_RX_TO_TICKS, &ucErr);
                ucPF    +=  ucChar;
                usValue  = (INT16U)ucChar << 8;
                ucChar   =  SCI5GetChar(SCI5_RX_TO_TICKS, &ucErr);
                ucPF    +=  ucChar;
                usValue += (INT16U)ucChar;
                ucChar   =  SCI5GetChar(SCI5_RX_TO_TICKS, &ucErr);
                if ((ucErr == SCI5_NO_ERR) && (ucChar == ucPF))
                {   ucComd &= SCI5_SCI_IS_MASK;
                    if (ucComd == SCI5_SCI_IS_PARAM)
                    {   ucComd  = DBSetParam16u(usWhich, usValue);
                    }
                    else if (ucComd == SCI5_SCI_IS_MEASU)
                    {   ucComd  = DBSetMeasu16u(usWhich, usValue);
                    }
                    else if (ucComd == SCI5_SCI_IS_FUNCT)
                    {   ucComd  = DBSetFunct16u(usWhich, usValue);
                    }
                    else if (ucComd == SCI5_SCI_IS_CURVE)
                    {   ucComd  = DBSetCurve16u(usWhich, usValue);
                    }
                    else
                    {   ucComd  = SCI5_FALSE;
                    }
                    (void)SCI5PutChar(SCI5_RX_TO_TICKS, ucComd);
                }
                else if ((ucErr == SCI5_NO_ERR) && (ucChar != ucPF))
                {   (void)SCI5PutChar(SCI5_RX_TO_TICKS, SCI5_FALSE);
                }
            }
            /* ******************** SCI5 Data Save ******************** */
            else if ((ucChar == SCI5_SCI_DO_SAVE) && (usWhich == 0))
            {   (void)SCI5PutChar(SCI5_RX_TO_TICKS, SCI5_TRUE);
                (void)DBTskPutCmd(ucComd);
            }
        }
    }
}
#endif

/* ******************************************************************** */
/*                           SCI5TxRxIntHook ()                         */
/* ******************************************************************** */
#if (SCI5_FUNCTION_ON == 1)
void SCI5TxRxIntHook (void)
{   INT08U ucDat, ucErr;
    if ((UART5->SR & USART_SR_RXNE) != 0)
    {   ucDat = (INT08U)UART5->DR;
        SCI5PutRxChar(ucDat);
    }
    else if ((UART5->SR & USART_SR_TC) != 0)
    {   ucDat = SCI5GetTxChar(&ucErr);
        if (ucErr == SCI5_NO_ERR)
        {   
           #if (SCI5_FULL_DUPLEX_ON == 0)
            SCI5_SCI_RX_DIS();
           #endif
            UART5->DR = ucDat;
        }
        else
        {   SCI5_SCI_TC_INT_DIS();
           #if (SCI5_FULL_DUPLEX_ON == 0)
            SCI5_SCI_RX_EN();
           #endif
        }
    }
}
#endif

/* ******************************************************************** */
/*                          SCI5BufInit()                               */
/* ******************************************************************** */
#if (SCI5_FUNCTION_ON == 1)
void SCI5BufInit (void)
{   SCI5_RING_STR *pbuf;
    pbuf = &sSCI5RingBuf;
    pbuf->usRingBufRxCtr   =  0;
    pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxOutPtr = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxSem    =  OSSemCreate(0);
    pbuf->usRingBufTxCtr   =  0;
    pbuf->pRingBufTxInPtr  = &pbuf->ucRingBufTx[0];
    pbuf->pRingBufTxOutPtr = &pbuf->ucRingBufTx[0];
    pbuf->pRingBufTxSem    =  OSSemCreate(SCI5_TX_BUF_SIZE);
}
#endif

/* ******************************************************************** */
/*                          SCI5PutRxChar()                             */
/* ******************************************************************** */
#if (SCI5_FUNCTION_ON == 1)
void SCI5PutRxChar (INT08U c)
{   SCI5_RING_STR *pbuf;
    pbuf = &sSCI5RingBuf;
    if (pbuf->usRingBufRxCtr < SCI5_RX_BUF_SIZE)
    {   pbuf->usRingBufRxCtr++;
        *pbuf->pRingBufRxInPtr++ = c;
        if (pbuf->pRingBufRxInPtr == &pbuf->ucRingBufRx[SCI5_RX_BUF_SIZE])
        {   pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufRxSem);
    }
}
#endif

/* ******************************************************************** */
/*                          SCI5GetTxChar()                             */
/* ******************************************************************** */
#if (SCI5_FUNCTION_ON == 1)
INT08U SCI5GetTxChar (INT08U *err)
{   INT08U c;
    SCI5_RING_STR *pbuf;
    pbuf = &sSCI5RingBuf;
    if (pbuf->usRingBufTxCtr > 0)
    {   pbuf->usRingBufTxCtr--;
        c = *pbuf->pRingBufTxOutPtr++;
        if (pbuf->pRingBufTxOutPtr == &pbuf->ucRingBufTx[SCI5_TX_BUF_SIZE])
        {   pbuf->pRingBufTxOutPtr  = &pbuf->ucRingBufTx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufTxSem);
        *err = SCI5_NO_ERR;
        return c;
    }   else
    {   *err = SCI5_ERR_TX_EMPTY;
        return 0;
    }
}
#endif

/* ******************************************************************** */
/*                           SCI5GetChar()                              */
/* ******************************************************************** */
#if (SCI5_FUNCTION_ON == 1)
INT08U SCI5GetChar (INT16U to, INT08U *err)
{   OS_CPU_SR cpu_sr = 0;
    INT08U c, oserr;
    SCI5_RING_STR *pbuf;
    pbuf = &sSCI5RingBuf;
    (void)OSSemPend(pbuf->pRingBufRxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   *err   = SCI5_ERR_RX_TIMEOUT;
        return 0;
    }
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufRxCtr == 0)
    {   *err = SCI5_ERR_RX_TIMEOUT;
        OS_EXIT_CRITICAL();
        return 0;
    }
    pbuf->usRingBufRxCtr--;
    c = *pbuf->pRingBufRxOutPtr++;
    if (pbuf->pRingBufRxOutPtr == &pbuf->ucRingBufRx[SCI5_RX_BUF_SIZE])
    {   pbuf->pRingBufRxOutPtr  = &pbuf->ucRingBufRx[0];
    }
    OS_EXIT_CRITICAL();
    *err = SCI5_NO_ERR;
    return c;
}
#endif

/* ******************************************************************** */
/*                           SCI5PutChar()                              */
/* ******************************************************************** */
#if (SCI5_FUNCTION_ON == 1)
INT08U SCI5PutChar (INT16U to, INT08U c)
{   OS_CPU_SR cpu_sr = 0;
    INT08U oserr;
    SCI5_RING_STR *pbuf;
    pbuf = &sSCI5RingBuf;
    (void)OSSemPend(pbuf->pRingBufTxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   return SCI5_ERR_TX_TIMEOUT;
    }   else
    {   OS_ENTER_CRITICAL();
        pbuf->usRingBufTxCtr++;
        *pbuf->pRingBufTxInPtr++ = c;
        if (pbuf->pRingBufTxInPtr == &pbuf->ucRingBufTx[SCI5_TX_BUF_SIZE])
        {   pbuf->pRingBufTxInPtr  = &pbuf->ucRingBufTx[0];
        }
        if (pbuf->usRingBufTxCtr == 1)
        {
           #if (SCI5_FULL_DUPLEX_ON == 0)
            SCI5_SCI_RX_DIS();
           #endif
            SCI5_SCI_TC_INT_EN();
        }
        OS_EXIT_CRITICAL();
        return SCI5_NO_ERR;
    }
}
#endif

/* ******************************************************************** */
/*                             SCI5HardInit ()                          */
/* ******************************************************************** */
#if (SCI5_FUNCTION_ON == 1)
void SCI5HardInit (INT32U uiBaud)
{   RCC->APB1ENR |= RCC_APB1ENR_UART5EN;
//    XIOConfigREMAP(SCI5_AFIO_REMAP1, SCI5_AFIO_REMAP2);
//    RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO, (FunctionalState)ENABLE);
//    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, (FunctionalState)ENABLE);
    XIOConfigGPIO(SCI5_TX_PT, SCI5_TX_BT, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
    XIOConfigGPIO(SCI5_RX_PT, SCI5_RX_BT, XIO_PT_GPI_FLOAT,  XIO_PT_SET_0);
    UART5->CR1  &= ~USART_CR1_SBK     /* 0: No break is transmitted     */
                &  ~USART_CR1_RWU     /* 0: Receiver in active mode     */
                &  ~USART_CR1_RE      /* 0: Receiver is disabled        */
                &  ~USART_CR1_TE      /* 0: Transmitter is disabled     */
                &  ~USART_CR1_IDLEIE  /* 0: IDLE Interrupt is inhibited */
                &  ~USART_CR1_RXNEIE  /* 0: RXNE Interrupt is inhibited */
                &  ~USART_CR1_TCIE    /* 0: TC Interrupt is inhibited   */
                &  ~USART_CR1_TXEIE   /* 0: TXE Interrupt is inhibited  */
                &  ~USART_CR1_PEIE    /* 0: PS Interrupt is inhibited   */
                &  ~USART_CR1_PS      /* 0: Even parity, 1: Odd parity  */
                &  ~USART_CR1_PCE     /* 0: Parity control disabled     */
                &  ~USART_CR1_WAKE    /* 0: Idle Line (Wakeup method)   */
                &  ~USART_CR1_M       /* 0: 1 Start, 8 Data, n Stop bit */
                &  ~USART_CR1_UE;     /* 0: prescaler & outputs disable */
    UART5->CR2  &= ~USART_CR2_ADD     /* ADD[3:0] = 0000                */
                &  ~USART_CR2_LBDL    /* LIN break detection length     */
                &  ~USART_CR2_LBDIE   /* LIN break detection interrupt  */
                &  ~USART_CR2_LBCL    /* Last bit clock pulse           */
                &  ~USART_CR2_CPHA    /* Clock phase                    */
                &  ~USART_CR2_CPOL    /* Clock polarity                 */
                &  ~USART_CR2_CLKEN   /* Clock enable                   */
                &  ~USART_CR2_STOP    /* 00: 1 Stop bit, 10: 2 Stop bit */
                &  ~USART_CR2_LINEN;  /* 0: LIN mode disabled           */
    UART5->CR3  &= ~USART_CR3_EIE     /* 0: Error interrupt disabled    */
                &  ~USART_CR3_IREN    /* 0: IrDA mode disabled          */
                &  ~USART_CR3_IRLP    /* 0: IrDA Normal mode            */
                &  ~USART_CR3_HDSEL   /* 0: Half duplex mode not select */
                &  ~USART_CR3_NACK    /* 0: Smartcard NACK disable      */
                &  ~USART_CR3_SCEN    /* 0: Smartcard Mode disabled     */
                &  ~USART_CR3_DMAR    /* 0: DMA mode is disabled for RX */
                &  ~USART_CR3_DMAT    /* 0: DMA mode is disabled for TX */
                &  ~USART_CR3_RTSE    /* 0: RTS flow control disabled   */
                &  ~USART_CR3_CTSE    /* 0: CTS flow control disabled   */
                &  ~USART_CR3_CTSIE;  /* 0: CTS Interrupt is inhibited  */
    UART5->BRR  = (INT16U)((SCI5_FRQ_CLK + uiBaud / 2) / uiBaud);
    UART5->CR1 |=  USART_CR1_UE;
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */