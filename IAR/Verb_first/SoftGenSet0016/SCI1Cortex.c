/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File SCI1Cortex.c                       */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   SCI1_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                              SCI1Init ()                             */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
void SCI1Init (void)
{   usSCI1Timer = 0;
    usSCI1Status = 0;
    SCI1BufInit();
    SCI1HardInit();
}
#endif

/* ******************************************************************** */
/*                              SCI1Start ()                            */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
void SCI1Start (void)
{   SCI1_SCI_RX_EN();
    SCI1_SCI_TX_EN();
    SCI1_SCI_RX_INT_EN();
    SCI1_SCI_TC_INT_DIS();
    FWIrqEnable(USART1_IRQn, 0);
}
#endif

/* ******************************************************************** */
/*                            SCI1TaskLoop ()                           */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
void SCI1TaskLoop (void)
{   INT08U ucComd, ucChar, ucPF, ucErr;
    INT16U usWhich, usValue;  
    while (1)
    {   ucComd = SCI1GetChar (SCI1_RX_TO_TICKS, &ucErr);
        if (ucErr  ==  SCI1_NO_ERR)
        {   ucPF    =  ucComd;
            ucChar  =  ucComd & SCI1_SCI_DO_MASK;
            usWhich = (INT16U)(ucComd & SCI1_SCI_H4_MASK) << 8;
            /* ******************** SCI1 Data Query ******************* */
            if (ucChar  ==  SCI1_SCI_DO_QUERY)
            {   ucChar   =  SCI1GetChar(SCI1_RX_TO_TICKS, &ucErr);
                ucPF    +=  ucChar;
                usWhich += (INT16U)ucChar;
                ucChar   =  SCI1GetChar(SCI1_RX_TO_TICKS, &ucErr);
                if ((ucErr == SCI1_NO_ERR) && (ucChar == ucPF))
                {   ucComd &= SCI1_SCI_IS_MASK;
                    if (ucComd == SCI1_SCI_IS_PARAM)
                    {   if  (usWhich < DB_PARAM_SIZE)
                        {    usValue = aDBParam[usWhich];
                             ucComd  = SCI1_TRUE;
                        }
                        else ucComd  = SCI1_FALSE;
                    }
                    else if (ucComd == SCI1_SCI_IS_MEASU)
                    {   if  (usWhich < DB_MEASU_SIZE)
                        {    usValue = aDBMeasu[usWhich];
                             ucComd  = SCI1_TRUE;
                        }
                        else ucComd  = SCI1_FALSE;
                    }
                    else
                    {   ucComd  = SCI1_FALSE;
                    }
                    if (ucComd != SCI1_FALSE)
                    {   ucChar  = (INT08U)(usValue >> 8);
                        ucPF    =  ucChar;
                        (void)SCI1PutChar(SCI1_RX_TO_TICKS, ucChar);
                        ucChar  = (INT08U)usValue;
                        ucPF   +=  ucChar;
                        (void)SCI1PutChar(SCI1_RX_TO_TICKS, ucChar);
                        (void)SCI1PutChar(SCI1_RX_TO_TICKS, ucPF);
                    }
                }
            }
            /* ******************** SCI1 Data Modify ****************** */
            else if (ucChar == SCI1_SCI_DO_MODIFY)
            {   ucChar   =  SCI1GetChar(SCI1_RX_TO_TICKS, &ucErr);
                ucPF    +=  ucChar;
                usWhich += (INT16U)ucChar;
                ucChar   =  SCI1GetChar(SCI1_RX_TO_TICKS, &ucErr);
                ucPF    +=  ucChar;
                usValue  = (INT16U)ucChar << 8;
                ucChar   =  SCI1GetChar(SCI1_RX_TO_TICKS, &ucErr);
                ucPF    +=  ucChar;
                usValue += (INT16U)ucChar;
                ucChar   =  SCI1GetChar(SCI1_RX_TO_TICKS, &ucErr);
                if ((ucErr == SCI1_NO_ERR) && (ucChar == ucPF))
                {   ucComd &= SCI1_SCI_IS_MASK;
                    ucChar  = SCI1_FALSE;
                    if (ucComd == SCI1_SCI_IS_PARAM)
                    {   if  (usWhich < DB_PARAM_SIZE)
                        {    aDBParam[usWhich] = usValue;
                             ucChar = SCI1_TRUE;
                        }
                    }
                    else if (ucComd == SCI1_SCI_IS_MEASU)
                    {   if  (usWhich < DB_MEASU_SIZE)
                        {    aDBMeasu[usWhich] = usValue;
                             ucChar = SCI1_TRUE;
                        }
                    }
                    (void)SCI1PutChar(SCI1_RX_TO_TICKS, ucChar);
                }
                else if ((ucErr == SCI1_NO_ERR) && (ucChar != ucPF))
                {   (void)SCI1PutChar(SCI1_RX_TO_TICKS, SCI1_FALSE);
                }
            }
            /* ******************** SCI1 Data Save ******************** */
            else if ((ucChar == SCI1_SCI_DO_SAVE) && (usWhich == 0))
            {   (void)SCI1PutChar(SCI1_RX_TO_TICKS, SCI1_TRUE);
                (void)DBTskPutCmd(ucComd);
            }
        }
    }
}
#endif

/* ******************************************************************** */
/*                           SCI1TxRxIntHook ()                         */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
int TESTZCSCI1[10];
void SCI1TxRxIntHook (void)
{   INT08U ucDat, ucErr;
    if ((USART1->SR & USART_SR_RXNE) != 0)
    {   ucDat = (INT08U)USART1->DR;
        SCI1PutRxChar(ucDat);
    }
    else if ((USART1->SR & USART_SR_TC) != 0)
    {   ucDat = SCI1GetTxChar(&ucErr);
        if (ucErr == SCI1_NO_ERR)
        {   SCI1_SCI_RX_DIS();
            USART1->DR = ucDat;
        }   else
        {   SCI1_SCI_TC_INT_DIS();
            SCI1_SCI_RX_EN();
        }
    }
    TESTZCSCI1[0]++;
    TESTZCSCI1[1] = USART1->DR;
}
#endif

/* ******************************************************************** */
/*                           SCI1CheckTime ()                           */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
INT08U SCI1CheckTime (INT16U usOld, INT16U usPer)
{   INT16U usTemp;
    usTemp = (INT16U)(usSCI1Timer - usOld);
    if (usTemp >= usPer)
    {   return SCI1_TRUE;
    }   else
    {   return SCI1_FALSE;
    }
}
#endif

/* ******************************************************************** */
/*                          SCI1BufInit()                               */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
void SCI1BufInit (void)
{   SCI1_RING_STR *pbuf;
    pbuf = &sSCI1RingBuf;
    pbuf->usRingBufRxCtr   =  0;
    pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxOutPtr = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxSem    =  OSSemCreate(0);
    pbuf->usRingBufTxCtr   =  0;
    pbuf->pRingBufTxInPtr  = &pbuf->ucRingBufTx[0];
    pbuf->pRingBufTxOutPtr = &pbuf->ucRingBufTx[0];
    pbuf->pRingBufTxSem    =  OSSemCreate(SCI1_TX_BUF_SIZE);
}
#endif

/* ******************************************************************** */
/*                          SCI1IsTxFull()                              */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
INT08U SCI1IsTxFull (void)
{   OS_CPU_SR cpu_sr = 0;
    SCI1_RING_STR *pbuf;
    pbuf = &sSCI1RingBuf;
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufTxCtr >= SCI1_TX_BUF_SIZE)
    {   OS_EXIT_CRITICAL();
        return SCI1_TRUE;
    }   else
    {   OS_EXIT_CRITICAL();
        return SCI1_FALSE;
    }
}
#endif

/* ******************************************************************** */
/*                          SCI1IsRxEmpty()                             */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
INT08U SCI1IsRxEmpty (void)
{   OS_CPU_SR cpu_sr = 0;
    SCI1_RING_STR *pbuf;
    pbuf = &sSCI1RingBuf;
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufRxCtr == 0)
    {   OS_EXIT_CRITICAL();
        return SCI1_TRUE;
    }   else
    {   OS_EXIT_CRITICAL();
        return SCI1_FALSE;
    }
}
#endif

/* ******************************************************************** */
/*                          SCI1PutRxChar()                             */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
void SCI1PutRxChar (INT08U c)
{   SCI1_RING_STR *pbuf;
    pbuf = &sSCI1RingBuf;
    if (pbuf->usRingBufRxCtr < SCI1_RX_BUF_SIZE)
    {   pbuf->usRingBufRxCtr++;
        *pbuf->pRingBufRxInPtr++ = c;
        if (pbuf->pRingBufRxInPtr == &pbuf->ucRingBufRx[SCI1_RX_BUF_SIZE])
        {   pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufRxSem);
    }
}
#endif

/* ******************************************************************** */
/*                          SCI1GetTxChar()                             */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
INT08U SCI1GetTxChar (INT08U *err)
{   INT08U c;
    SCI1_RING_STR *pbuf;
    pbuf = &sSCI1RingBuf;
    if (pbuf->usRingBufTxCtr > 0)
    {   pbuf->usRingBufTxCtr--;
        c = *pbuf->pRingBufTxOutPtr++;
        if (pbuf->pRingBufTxOutPtr == &pbuf->ucRingBufTx[SCI1_TX_BUF_SIZE])
        {   pbuf->pRingBufTxOutPtr  = &pbuf->ucRingBufTx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufTxSem);
        *err = SCI1_NO_ERR;
        return c;
    }   else
    {   *err = SCI1_ERR_TX_EMPTY;
        return 0;
    }
}
#endif

/* ******************************************************************** */
/*                           SCI1GetChar()                              */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
INT08U SCI1GetChar (INT16U to, INT08U *err)
{   OS_CPU_SR cpu_sr = 0;
    INT08U c, oserr;
    SCI1_RING_STR *pbuf;
    pbuf = &sSCI1RingBuf;
    (void)OSSemPend(pbuf->pRingBufRxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   *err   = SCI1_ERR_RX_TIMEOUT;
        return 0;
    }
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufRxCtr == 0)
    {   *err = SCI1_ERR_RX_TIMEOUT;
        OS_EXIT_CRITICAL();
        return 0;
    }
    pbuf->usRingBufRxCtr--;
    c = *pbuf->pRingBufRxOutPtr++;
    if (pbuf->pRingBufRxOutPtr == &pbuf->ucRingBufRx[SCI1_RX_BUF_SIZE])
    {   pbuf->pRingBufRxOutPtr  = &pbuf->ucRingBufRx[0];
    }
    OS_EXIT_CRITICAL();
    *err = SCI1_NO_ERR;
    return c;
}
#endif

/* ******************************************************************** */
/*                           SCI1PutChar()                              */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
INT08U SCI1PutChar (INT16U to, INT08U c)
{   OS_CPU_SR cpu_sr = 0;
    INT08U oserr;
    SCI1_RING_STR *pbuf;
    pbuf = &sSCI1RingBuf;
    (void)OSSemPend(pbuf->pRingBufTxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   return SCI1_ERR_TX_TIMEOUT;
    }   else
    {   OS_ENTER_CRITICAL();
        pbuf->usRingBufTxCtr++;
        *pbuf->pRingBufTxInPtr++ = c;
        if (pbuf->pRingBufTxInPtr == &pbuf->ucRingBufTx[SCI1_TX_BUF_SIZE])
        {   pbuf->pRingBufTxInPtr  = &pbuf->ucRingBufTx[0];
        }
        if (pbuf->usRingBufTxCtr == 1)
        {   SCI1_SCI_RX_DIS();
            SCI1_SCI_TC_INT_EN();
        }
        OS_EXIT_CRITICAL();
        return SCI1_NO_ERR;
    }
}
#endif

/* ******************************************************************** */
/*                             SCI1HardInit ()                          */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
void SCI1HardInit (void)
{   RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    XIOConfigAFIO(XIO_Remap_USART1);
    //XIOConfigGPIO(GPIOA, XIO_PT_BT10, XIO_PT_GPI_FLOAT, XIO_PT_SET_0);
    //XIOConfigGPIO(GPIOA, XIO_PT_BT9, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT10, XIO_PT_GPI_FLOAT, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT9, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);    
    USART1->CR1 &= ~USART_CR1_SBK     /* 0: No break is transmitted     */
                &  ~USART_CR1_RWU     /* 0: Receiver in active mode     */
                &  ~USART_CR1_RE      /* 0: Receiver is disabled        */
                &  ~USART_CR1_TE      /* 0: Transmitter is disabled     */
                &  ~USART_CR1_IDLEIE  /* 0: IDLE Interrupt is inhibited */
                &  ~USART_CR1_RXNEIE  /* 0: RXNE Interrupt is inhibited */
                &  ~USART_CR1_TCIE    /* 0: TC Interrupt is inhibited   */
                &  ~USART_CR1_TXEIE   /* 0: TXE Interrupt is inhibited  */
                &  ~USART_CR1_PEIE    /* 0: PS Interrupt is inhibited   */
                &  ~USART_CR1_PS      /* 0: Even parity, 1: Odd parity  */
                &  ~USART_CR1_PCE     /* 0: 0: Parity control disabled  */
                &  ~USART_CR1_WAKE    /* 0: Idle Line (Wakeup method)   */
                &  ~USART_CR1_M       /* 0: 1 Start, 8 Data, n Stop bit */
                &  ~USART_CR1_UE;     /* 0: prescaler & outputs disable */
    USART1->CR2 &= ~USART_CR2_ADD     /* ADD[3:0] = 0000                */
                &  ~USART_CR2_LBDL    /* LIN break detection length     */
                &  ~USART_CR2_LBDIE   /* LIN break detection interrupt  */
                &  ~USART_CR2_LBCL    /* Last bit clock pulse           */
                &  ~USART_CR2_CPHA    /* Clock phase                    */
                &  ~USART_CR2_CPOL    /* Clock polarity                 */
                &  ~USART_CR2_CLKEN   /* Clock enable                   */
                &  ~USART_CR2_STOP    /* 00: 1 Stop bit, 10: 2 Stop bit */
                &  ~USART_CR2_LINEN;  /* 0: LIN mode disabled           */
    USART1->CR3 &= ~USART_CR3_EIE     /* 0: Error interrupt disabled    */
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
    USART1->BRR  = (INT16U)((SCI1_FRQ_CLK+SCI1_BAUD_DEFAULT/2)/SCI1_BAUD_DEFAULT);
    USART1->CR1 |=  USART_CR1_UE;
}
#endif

/* ******************************************************************** */
/*                          SCI1InitDma1Ch4Tx ()                        */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
void SCI1InitDma1Ch4Tx (INT16U usTxSize)
{   RCC->AHBENR         |=  RCC_AHBENR_DMA1EN; /* 1: DMA clock enable   */
    DMA1_Channel4->CCR  &= ~DMA_CCR4_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR4_PL        /* 00: Priority low      */
                        &  ~DMA_CCR4_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR4_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR4_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR4_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR4_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR4_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR4_TCIE;     /* 0: TC interrupt off   */
    DMA1_Channel4->CCR  |=  DMA_CCR4_MINC      /* Memory increment mode */
                        |   DMA_CCR4_DIR;      /* 1: Read from memory   */
    DMA1_Channel4->CNDTR =  usTxSize;
    DMA1_Channel4->CPAR  = (INT32U)&(USART1->DR);
    DMA1_Channel4->CMAR  = (INT32U)&aSCI1TxDmaBuf[0];
    DMA1_Channel4->CCR  |=  DMA_CCR4_TCIE
                        |   DMA_CCR4_EN;
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */