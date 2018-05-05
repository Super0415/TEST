/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File SCI4Cortex.c                       */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   SCI4_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                              SCI4Init ()                             */
/* ******************************************************************** */
#if (SCI4_SLAVE_FUNCTION_ON == 1)
void SCI4Init (void)
{   uiSCI4Status = 0;
    (void)SCI4HardInit(SCI4_BAUDRATE_DEF);
    (void)SCI4InitTxDma();
    (void)SCI4InitRxDma();
}
#endif
#if (SCI4_MASTER_FUNCTION_ON == 1)
void SCI4Init (void)
{   uiSCI4Status = 0;
    usSCI4WriteBegin = 0;
    usSCI4WriteSize  = 0;
    usSCI4WriteData0 = 0;
    usSCI4WriteData1 = 0;
    usSCI4WriteData2 = 0;
    usSCI4WriteData3 = 0;
    usSCI4DigitInputs = 0;
    usSCI4AdcInput[0] = 0;
    usSCI4AdcInput[1] = 0;
    usSCI4AdcInput[2] = 0;
    usSCI4AdcInput[3] = 0;
    usSCI4AdcInput[4] = 0;
    usSCI4AdcInput[5] = 0;
    usSCI4AdcInput[6] = 0;
    usSCI4AdcInput[7] = 0;
    usSCI4AdcInput[8] = 0;
    (void)SCI4HardInit(SCI4_BAUDRATE_DEF);
    (void)SCI4InitTxDma();
    (void)SCI4InitRxDma();
}
#endif

/* ******************************************************************** */
/*                              SCI4Start ()                            */
/* ******************************************************************** */
#if (SCI4_SLAVE_FUNCTION_ON == 1)
void SCI4Start (void)
{   SCI4_SCI_TX_DIS();
    SCI4_SCI_RX_DIS();
    SCI4_SCI_TC_INT_DIS();
    SCI4_SCI_RX_INT_DIS();
    (void)SCI4SetupRxDma((INT08U*)&aSCI4RxBuf[0], SCI4_RX_BUF_SIZE*2);
   #if (SCI4_TX_DMA_TCINT_ON == 1)
    (void)FWIrqEnable(DMA2_Channel5_IRQn, FW_IRQ_PRIO_LOW);
   #endif
   #if (SCI4_RX_DMA_TCINT_ON == 1)
    (void)FWIrqEnable(DMA2_Channel3_IRQn, FW_IRQ_PRIO_LOW);
   #endif
    SCI4_SCI_RX_EN();
    SCI4_SCI_TX_EN();
}
#endif
#if (SCI4_MASTER_FUNCTION_ON == 1)
void SCI4Start (void)
{   SCI4_SCI_TX_DIS();
    SCI4_SCI_RX_DIS();
    SCI4_SCI_TC_INT_DIS();
    SCI4_SCI_RX_INT_DIS();
    (void)SCI4SetupRxDma((INT08U*)&aSCI4RxBuf[0], SCI4_RX_BUF_SIZE*2);
   #if (SCI4_TX_DMA_TCINT_ON == 1)
    (void)FWIrqEnable(DMA2_Channel5_IRQn, FW_IRQ_PRIO_LOW);
   #endif
   #if (SCI4_RX_DMA_TCINT_ON == 1)
    (void)FWIrqEnable(DMA2_Channel3_IRQn, FW_IRQ_PRIO_LOW);
   #endif
    SCI4_SCI_RX_EN();
    SCI4_SCI_TX_EN();
}
#endif

/* ******************************************************************** */
/*                            SCI4TaskLoop ()                           */
/* ******************************************************************** */
#if (SCI4_SLAVE_FUNCTION_ON == 1)
void SCI4TaskLoop (void)
{   INT16U usTmp;
    while (1)
    {   (void)OSTaskSuspend(OS_PRIO_SELF);
        usTmp = SCI4ProcessMsg(&aSCI4RxBuf[0], &aSCI4TxBuf[0]);
        (void)SCI4SetupRxDma((INT08U*)&aSCI4RxBuf[0], SCI4_RX_BUF_SIZE*2);
        if ((usTmp > 0) && (usTmp <= SCI4_TX_BUF_SIZE))
        {   SCI4SetupTxDma((INT08U*)&aSCI4TxBuf[0], usTmp*2);
        }
    }
}
#endif
#if (SCI4_MASTER_FUNCTION_ON == 1)
void SCI4TaskLoop (void)
{   OSTimeDly(OS_TICKS_PER_SEC / 2);
    SCI4SetTxBuf(&aSCI4TxBuf[0], SCI4_CODE_BEGIN_PARAM, 
                                 SCI4_CODE_SIZE_PARAM, 0);
    SCI4SetupRxDma((INT08U*)&aSCI4RxBuf[0], SCI4_CODE_SIZE_PARAM*2+8);
    SCI4SetupTxDma((INT08U*)&aSCI4TxBuf[0], SCI4_TX_BUF_SIZE*2);
    OSTimeDly(OS_TICKS_PER_SEC / SCI4_TASK_FRQ);
    if (SCI4ReadRxBuf(&aSCI4RxBuf[0]) == FALSE)
    {   SCI4_STS_SET_BIT(SCI4_STS_ERR_RX);
    }
    SCI4SetTxBuf(&aSCI4TxBuf[0], SCI4_CODE_BEGIN_FUNCT, 
                                 SCI4_CODE_SIZE_FUNCT, 0);
    SCI4SetupRxDma((INT08U*)&aSCI4RxBuf[0], SCI4_CODE_SIZE_FUNCT*2+8);
    SCI4SetupTxDma((INT08U*)&aSCI4TxBuf[0], SCI4_TX_BUF_SIZE*2);
    OSTimeDly(OS_TICKS_PER_SEC / SCI4_TASK_FRQ);
    if (SCI4ReadRxBuf(&aSCI4RxBuf[0]) == FALSE)
    {   SCI4_STS_SET_BIT(SCI4_STS_ERR_RX);
    }
    SCI4SetTxBuf(&aSCI4TxBuf[0], SCI4_CODE_BEGIN_CURVE, 
                                 SCI4_CODE_SIZE_CURVE, 0);
    SCI4SetupRxDma((INT08U*)&aSCI4RxBuf[0], SCI4_CODE_SIZE_CURVE*2+8);
    SCI4SetupTxDma((INT08U*)&aSCI4TxBuf[0], SCI4_TX_BUF_SIZE*2);
    OSTimeDly(OS_TICKS_PER_SEC / SCI4_TASK_FRQ);
    if (SCI4ReadRxBuf(&aSCI4RxBuf[0]) == FALSE)
    {   SCI4_STS_SET_BIT(SCI4_STS_ERR_RX);
    }
    while (1)
    {   SCI4SetTxBuf(&aSCI4TxBuf[0], SCI4_CODE_BEGIN_MEASU, 
                     SCI4_CODE_SIZE_MEASU, usSCI4WriteSize);
        usSCI4WriteSize = 0;
        SCI4SetupRxDma((INT08U*)&aSCI4RxBuf[0], SCI4_CODE_SIZE_MEASU*2+8);
        SCI4SetupTxDma((INT08U*)&aSCI4TxBuf[0], SCI4_TX_BUF_SIZE*2);
        OSTimeDly(OS_TICKS_PER_SEC / SCI4_TASK_FRQ);
        if (SCI4ReadRxBuf(&aSCI4RxBuf[0]) == FALSE)
        {   SCI4_STS_SET_BIT(SCI4_STS_ERR_RX);
        }
    }
}
#endif

/* ******************************************************************** */
/*                           SCI4TxRxIntHook ()                         */
/* ******************************************************************** */
#if (SCI4_SLAVE_FUNCTION_ON == 1)
void SCI4TxRxIntHook (void)
{
}
#endif
#if (SCI4_MASTER_FUNCTION_ON == 1)
void SCI4TxRxIntHook (void)
{
}
#endif

/* ******************************************************************** */
/*                           SCI4TxRxIntHook ()                         */
/* ******************************************************************** */
#if (SCI4_SLAVE_FUNCTION_ON == 1)
void SCI4OverTimerHook (void)
{
}
#endif
#if (SCI4_MASTER_FUNCTION_ON == 1)
void SCI4OverTimerHook (void)
{
}
#endif

/* ******************************************************************** */
/*                        SCI4Dma2Ch5IntHook()                          */
/* ******************************************************************** */
#if (SCI4_SLAVE_FUNCTION_ON == 1)
void SCI4Dma2Ch5IntHook (void)
{   DMA2_Channel5->CCR &= ~DMA_CCR5_EN;
    DMA2->IFCR = DMA_ISR_GIF5 | DMA_ISR_TCIF5 | DMA_ISR_HTIF5 | DMA_ISR_TEIF5;
}
#endif
#if (SCI4_MASTER_FUNCTION_ON == 1)
void SCI4Dma2Ch5IntHook (void)
{   DMA2_Channel5->CCR &= ~DMA_CCR5_EN;
    DMA2->IFCR = DMA_ISR_GIF5 | DMA_ISR_TCIF5 | DMA_ISR_HTIF5 | DMA_ISR_TEIF5;
}
#endif

/* ******************************************************************** */
/*                        SCI4Dma2Ch3IntHook()                          */
/* ******************************************************************** */
#if (SCI4_SLAVE_FUNCTION_ON == 1)
void SCI4Dma2Ch3IntHook (void)
{   DMA2_Channel3->CCR &= ~DMA_CCR3_EN;
    DMA2->IFCR = DMA_ISR_GIF3 | DMA_ISR_TCIF3 | DMA_ISR_HTIF3 | DMA_ISR_TEIF3;
    (void)OSIntTaskResume(FW_TASK_PRIO_SCI4);
}
#endif
#if (SCI4_MASTER_FUNCTION_ON == 1)
void SCI4Dma2Ch3IntHook (void)
{   DMA2_Channel3->CCR &= ~DMA_CCR3_EN;
    DMA2->IFCR = DMA_ISR_GIF3 | DMA_ISR_TCIF3 | DMA_ISR_HTIF3 | DMA_ISR_TEIF3;
}
#endif

/* ******************************************************************** */
/*                            SCI4TxWriteParam()                        */
/* ******************************************************************** */
#if (SCI4_MASTER_FUNCTION_ON == 1)
INT08U SCI4TxWriteParam (INT16U usBegin, INT16U usValue)
{   if (usSCI4WriteSize == 0)
    {   usSCI4WriteBegin = usBegin;
        usSCI4WriteData0 = usValue;
        usSCI4WriteSize  = 1;
        return TRUE;
    }
    OSTimeDly(1);
    if (usSCI4WriteSize == 0)
    {   usSCI4WriteBegin = usBegin;
        usSCI4WriteData0 = usValue;
        usSCI4WriteSize  = 1;
        return TRUE;
    }
    OSTimeDly(1);
    if (usSCI4WriteSize == 0)
    {   usSCI4WriteBegin = usBegin;
        usSCI4WriteData0 = usValue;
        usSCI4WriteSize  = 1;
        return TRUE;
    }
    OSTimeDly(1);
    if (usSCI4WriteSize == 0)
    {   usSCI4WriteBegin = usBegin;
        usSCI4WriteData0 = usValue;
        usSCI4WriteSize  = 1;
        return TRUE;
    }
    SCI4_STS_SET_BIT(SCI4_STS_ERR_TX);
    return FALSE;
}
#endif

/* ******************************************************************** */
/*                            SCI4SetTxBuf()                            */
/* ******************************************************************** */
#if (SCI4_MASTER_FUNCTION_ON == 1)
void SCI4SetTxBuf (INT16U *pTxBuf, INT16U usRBeg,
                                   INT16U usRSiz, INT16U usWSiz)
{   pTxBuf[0]  = SCI4_CODE_CALL;
    pTxBuf[1]  = usRBeg;                                /* Read Begin   */
    pTxBuf[2]  = usRSiz;                                /* Read Size    */
    pTxBuf[3]  = usSCI4WriteBegin;                      /* Write Begin  */
    pTxBuf[4]  = usWSiz;                                /* Write Size   */
    pTxBuf[5]  = usSCI4WriteData0;                      /* Write Data0  */
    pTxBuf[6]  = usSCI4WriteData1;                      /* Write Data1  */
    pTxBuf[7]  = usSCI4WriteData2;                      /* Write Data2  */
    pTxBuf[8]  = usSCI4WriteData3;                      /* Write Data3  */
    pTxBuf[9]  = usSCI4DigitInputs;                     /* DigitInputs  */
    pTxBuf[10] = usSCI4AdcInput[0];                     /* AnalogInput0 */
    pTxBuf[11] = usSCI4AdcInput[1];                     /* AnalogInput1 */
    pTxBuf[12] = usSCI4AdcInput[2];                     /* AnalogInput2 */
    pTxBuf[13] = usSCI4AdcInput[3];                     /* AnalogInput3 */
    pTxBuf[14] = usSCI4AdcInput[4];                     /* AnalogInput4 */
    pTxBuf[15] = usSCI4AdcInput[5];                     /* AnalogInput5 */
    pTxBuf[16] = usSCI4AdcInput[6];                     /* AnalogInput6 */
    pTxBuf[17] = usSCI4AdcInput[7];                     /* AnalogInput7 */
    pTxBuf[18] = usSCI4AdcInput[8];                     /* AnalogInput8 */
    pTxBuf[19] = SFGetSum16u(&pTxBuf[0], 19);           /* Sum of 0~18  */
}
#endif

/* ******************************************************************** */
/*                            SCI4ReadRxBuf()                           */
/* ******************************************************************** */
#if (SCI4_MASTER_FUNCTION_ON == 1)
INT08U SCI4ReadRxBuf (INT16U *pRxBuf)
{   INT16U usBegin, usSize;
    if (pRxBuf[0] != SCI4_CODE_RESPOND)
    {   pRxBuf[0]  = 0;
        return FALSE;
    }
    usBegin = SFGetSum16u(&pRxBuf[0], SCI4_RX_BUF_SIZE-1);
    if (pRxBuf[SCI4_RX_BUF_SIZE-1] != usBegin)
    {   pRxBuf[0]  = 0;
        return FALSE;
    }
    pRxBuf[0] = 0;
    usBegin = pRxBuf[1];
    usSize  = pRxBuf[2];
    if ((usSize > 0) && (usSize <= SCI4_READ_SIZE_MAX))
    {   if (usBegin >= (DB_PARAM_SIZE+DB_FUNCT_SIZE+DB_CURVE_SIZE))
        {   usBegin -= (DB_PARAM_SIZE+DB_FUNCT_SIZE+DB_CURVE_SIZE);
            if (DBCheckMeasu16p(&pRxBuf[3], usBegin, usSize) != DB_SAME)
            {   DBSetMeasu16p(&pRxBuf[3], usBegin, usSize);
            }
        }
        else if (usBegin >= (DB_PARAM_SIZE+DB_FUNCT_SIZE))
        {   usBegin -= (DB_PARAM_SIZE+DB_FUNCT_SIZE);
            if (DBCheckCurve16p(&pRxBuf[3], usBegin, usSize) != DB_SAME)
            {   DBSetCurve16p(&pRxBuf[3], usBegin, usSize);
            }
        }
        else if (usBegin >= DB_PARAM_SIZE)
        {   usBegin -= DB_PARAM_SIZE;
            if (DBCheckFunct16p(&pRxBuf[3], usBegin, usSize) != DB_SAME)
            {   DBSetFunct16p(&pRxBuf[3], usBegin, usSize);
            }
        }
        else if (DBCheckParam16p(&pRxBuf[3], usBegin, usSize) != DB_SAME)
        {   DBSetParam16p(&pRxBuf[3], usBegin, usSize);
        }
        return TRUE;
    }
    return FALSE;
}
#endif

/* ******************************************************************** */
/*                           SCI4ProcessMsg()                           */
/* ******************************************************************** */
#if (SCI4_SLAVE_FUNCTION_ON == 1)
INT16U SCI4ProcessMsg (INT16U *pRxBuf, INT16U *pTxBuf)
{   INT16U usBegin, usSize;
    if (pRxBuf[0] != SCI4_CODE_CALL)
    {   pRxBuf[0] = 0;
        return 0;
    }
    usBegin = SFGetSum16u(&pRxBuf[0], SCI4_RX_BUF_SIZE-1);
    if (pRxBuf[SCI4_RX_BUF_SIZE-1] != usBegin)
    {   pRxBuf[0] = 0;
        return 0;
    }
    usDBmSwitchesInput2 = pRxBuf[9];
    usDBmAdcInput16     = pRxBuf[10];
    usDBmAdcInput17     = pRxBuf[11];
    usDBmAdcInput18     = pRxBuf[12];
    usDBmAdcInput19     = pRxBuf[13];
    usDBmAdcInput20     = pRxBuf[14];
    usDBmAdcInput21     = pRxBuf[15];
    usDBmAdcInput22     = pRxBuf[16];
    usDBmAdcInput23     = pRxBuf[17];
    usDBmAdcInput24     = pRxBuf[18];
    pRxBuf[0]           = 0;
    usBegin             = pRxBuf[3];
    usSize              = pRxBuf[4];
    if ((usSize > 0) && (usSize <= SCI4_WRITE_SIZE_MAX))
    {   if (usBegin >= (DB_PARAM_SIZE+DB_FUNCT_SIZE+DB_CURVE_SIZE))
        {   usBegin -= (DB_PARAM_SIZE+DB_FUNCT_SIZE+DB_CURVE_SIZE);
            if (DBCheckMeasu16p(&pRxBuf[5], usBegin, usSize) != DB_SAME)
            {   DBSetMeasu16p(&pRxBuf[5], usBegin, usSize);
            }
        }
        else if (usBegin >= (DB_PARAM_SIZE+DB_FUNCT_SIZE))
        {   usBegin -= (DB_PARAM_SIZE+DB_FUNCT_SIZE);
            if (DBCheckCurve16p(&pRxBuf[5], usBegin, usSize) != DB_SAME)
            {   DBSetCurve16p(&pRxBuf[5], usBegin, usSize);
                DBTskPutCmd(DB_CMD_SAVE_CURVE);
            }
        }
        else if (usBegin >= DB_PARAM_SIZE)
        {   usBegin -= DB_PARAM_SIZE;
            if (DBCheckFunct16p(&pRxBuf[5], usBegin, usSize) != DB_SAME)
            {   DBSetFunct16p(&pRxBuf[5], usBegin, usSize);
                DBTskPutCmd(DB_CMD_SAVE_FUNCT);
            }
        }
        else if (DBCheckParam16p(&pRxBuf[5], usBegin, usSize) != DB_SAME)
        {   DBSetParam16p(&pRxBuf[5], usBegin, usSize);
            DBTskPutCmd(DB_CMD_SAVE_PARAM);
        }
    }
    usBegin = pRxBuf[1];
    usSize  = pRxBuf[2];
    if ((usSize == 0) || (usSize > (SCI4_TX_BUF_SIZE-4)))
    {   return 0;
    }
    pTxBuf[0] = SCI4_CODE_RESPOND;
    pTxBuf[1] = usBegin;
    pTxBuf[2] = usSize;
    if (usBegin >= (DB_PARAM_SIZE+DB_FUNCT_SIZE+DB_CURVE_SIZE))
    {   usBegin -= (DB_PARAM_SIZE+DB_FUNCT_SIZE+DB_CURVE_SIZE);
        DBGetMeasu16p(&pTxBuf[3], usBegin, usSize);
    }
    else if (usBegin >= (DB_PARAM_SIZE+DB_FUNCT_SIZE))
    {   usBegin -= (DB_PARAM_SIZE+DB_FUNCT_SIZE);
        DBGetCurve16p(&pTxBuf[3], usBegin, usSize);
    }
    else if (usBegin >= DB_PARAM_SIZE)
    {   usBegin -= DB_PARAM_SIZE;
        DBGetFunct16p(&pTxBuf[3], usBegin, usSize);
    }
    else
    {   DBGetParam16p(&pTxBuf[3], usBegin, usSize);
    }
    pTxBuf[usSize+3] = SFGetSum16u(&pTxBuf[0], usSize+3);
    return usSize+4;
}
#endif

/* ******************************************************************** */
/*                             SCI4HardInit ()                          */
/* ******************************************************************** */
#if (SCI4_SLAVE_FUNCTION_ON == 1)
void SCI4HardInit (INT32U uiBaud)
{   RCC->APB1ENR |= RCC_APB1ENR_UART4EN;
    XIOConfigGPIO(SCI4_TX_PT, SCI4_TX_BT, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
    XIOConfigGPIO(SCI4_RX_PT, SCI4_RX_BT, XIO_PT_GPI_FLOAT,  XIO_PT_SET_0);
    UART4->CR1  &= ~USART_CR1_SBK     /* 0: No break is transmitted     */
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
    UART4->CR2  &= ~USART_CR2_ADD     /* ADD[3:0] = 0000                */
                &  ~USART_CR2_LBDL    /* LIN break detection length     */
                &  ~USART_CR2_LBDIE   /* LIN break detection interrupt  */
                &  ~USART_CR2_LBCL    /* Last bit clock pulse           */
                &  ~USART_CR2_CPHA    /* Clock phase                    */
                &  ~USART_CR2_CPOL    /* Clock polarity                 */
                &  ~USART_CR2_CLKEN   /* Clock enable                   */
                &  ~USART_CR2_STOP    /* 00: 1 Stop bit, 10: 2 Stop bit */
                &  ~USART_CR2_LINEN;  /* 0: LIN mode disabled           */
    UART4->CR3  &= ~USART_CR3_EIE     /* 0: Error interrupt disabled    */
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
    UART4->BRR  = (INT16U)((SCI4_FRQ_CLK + uiBaud / 2) / uiBaud);
    UART4->CR1 |=  USART_CR1_UE;
}
#endif
#if (SCI4_MASTER_FUNCTION_ON == 1)
void SCI4HardInit (INT32U uiBaud)
{   RCC->APB1ENR |= RCC_APB1ENR_UART4EN;
    XIOConfigGPIO(SCI4_TX_PT, SCI4_TX_BT, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
    XIOConfigGPIO(SCI4_RX_PT, SCI4_RX_BT, XIO_PT_GPI_FLOAT,  XIO_PT_SET_0);
    UART4->CR1  &= ~USART_CR1_SBK     /* 0: No break is transmitted     */
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
    UART4->CR2  &= ~USART_CR2_ADD     /* ADD[3:0] = 0000                */
                &  ~USART_CR2_LBDL    /* LIN break detection length     */
                &  ~USART_CR2_LBDIE   /* LIN break detection interrupt  */
                &  ~USART_CR2_LBCL    /* Last bit clock pulse           */
                &  ~USART_CR2_CPHA    /* Clock phase                    */
                &  ~USART_CR2_CPOL    /* Clock polarity                 */
                &  ~USART_CR2_CLKEN   /* Clock enable                   */
                &  ~USART_CR2_STOP    /* 00: 1 Stop bit, 10: 2 Stop bit */
                &  ~USART_CR2_LINEN;  /* 0: LIN mode disabled           */
    UART4->CR3  &= ~USART_CR3_EIE     /* 0: Error interrupt disabled    */
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
    UART4->BRR  = (INT16U)((SCI4_FRQ_CLK + uiBaud / 2) / uiBaud);
    UART4->CR1 |=  USART_CR1_UE;
}
#endif

/* ******************************************************************** */
/*                           SCI4InitTxDma()                            */
/* ******************************************************************** */
#if (SCI4_SLAVE_FUNCTION_ON == 1)
void SCI4InitTxDma (void)
{   RCC->AHBENR         |=  RCC_AHBENR_DMA2EN; /* 1: DMA2 clock enable  */
    DMA2_Channel5->CCR  &= ~DMA_CCR5_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR5_PL        /* 00: Priority low      */
                        &  ~DMA_CCR5_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR5_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR5_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR5_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR5_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR5_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR5_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR5_EN;       /* 0: Channel disabled   */
    DMA2->IFCR           =  DMA_ISR_GIF5       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF5      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF5      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF5;     /* 1: clear TE flag      */
}
#endif
#if (SCI4_MASTER_FUNCTION_ON == 1)
void SCI4InitTxDma (void)
{   RCC->AHBENR         |=  RCC_AHBENR_DMA2EN; /* 1: DMA2 clock enable  */
    DMA2_Channel5->CCR  &= ~DMA_CCR5_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR5_PL        /* 00: Priority low      */
                        &  ~DMA_CCR5_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR5_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR5_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR5_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR5_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR5_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR5_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR5_EN;       /* 0: Channel disabled   */
    DMA2->IFCR           =  DMA_ISR_GIF5       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF5      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF5      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF5;     /* 1: clear TE flag      */
}
#endif

/* ******************************************************************** */
/*                            SCI4SetupTxDma ()                         */
/* ******************************************************************** */
#if (SCI4_SLAVE_FUNCTION_ON == 1)
void SCI4SetupTxDma (INT08U *pAddr, INT16U usSize)
{   DMA2_Channel5->CCR  &= ~DMA_CCR5_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR5_PL        /* 00: Priority low      */
                        &  ~DMA_CCR5_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR5_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR5_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR5_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR5_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR5_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR5_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR5_EN;       /* 0: Channel disabled   */
    DMA2_Channel5->CCR  |=  DMA_CCR5_MINC      /* Memory increment mode */
                        |   DMA_CCR5_DIR;      /* 1: Read from memory   */
    DMA2->IFCR           =  DMA_ISR_GIF5       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF5      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF5      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF5;     /* 1: clear TE flag      */
    DMA2_Channel5->CNDTR = (INT16U)usSize;
    DMA2_Channel5->CPAR  = (INT32U)&(UART4->DR);
    DMA2_Channel5->CMAR  = (INT32U)pAddr;
    SCI4_SCI_TXDMA_EN();
    SCI4_SCI_TX_EN();
    SCI4_SCI_SR_TC_CLR();
   #if (SCI4_TX_DMA_TCINT_ON == 1)
    DMA2_Channel5->CCR  |=  DMA_CCR5_TCIE      /* 1: TC int enabled     */
                        |   DMA_CCR5_EN;       /* 1: Channel5 enabled   */
   #else
    DMA2_Channel5->CCR  |=  DMA_CCR5_EN;       /* 1: Channel5 enabled   */
   #endif
}
#endif
#if (SCI4_MASTER_FUNCTION_ON == 1)
void SCI4SetupTxDma (INT08U *pAddr, INT16U usSize)
{   DMA2_Channel5->CCR  &= ~DMA_CCR5_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR5_PL        /* 00: Priority low      */
                        &  ~DMA_CCR5_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR5_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR5_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR5_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR5_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR5_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR5_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR5_EN;       /* 0: Channel disabled   */
    DMA2_Channel5->CCR  |=  DMA_CCR5_MINC      /* Memory increment mode */
                        |   DMA_CCR5_DIR;      /* 1: Read from memory   */
    DMA2->IFCR           =  DMA_ISR_GIF5       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF5      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF5      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF5;     /* 1: clear TE flag      */
    DMA2_Channel5->CNDTR = (INT16U)usSize;
    DMA2_Channel5->CPAR  = (INT32U)&(UART4->DR);
    DMA2_Channel5->CMAR  = (INT32U)pAddr;
    SCI4_SCI_TXDMA_EN();
    SCI4_SCI_TX_EN();
    SCI4_SCI_SR_TC_CLR();
   #if (SCI4_TX_DMA_TCINT_ON == 1)
    DMA2_Channel5->CCR  |=  DMA_CCR5_TCIE      /* 1: TC int enabled     */
                        |   DMA_CCR5_EN;       /* 1: Channel5 enabled   */
   #else
    DMA2_Channel5->CCR  |=  DMA_CCR5_EN;       /* 1: Channel5 enabled   */
   #endif
}
#endif

/* ******************************************************************** */
/*                           SCI4InitRxDma()                            */
/* ******************************************************************** */
#if (SCI4_SLAVE_FUNCTION_ON == 1)
void SCI4InitRxDma (void)
{   RCC->AHBENR         |=  RCC_AHBENR_DMA2EN; /* 1: DMA2 clock enable  */
    DMA2_Channel3->CCR  &= ~DMA_CCR3_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR3_PL        /* 00: Priority low      */
                        &  ~DMA_CCR3_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR3_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR3_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR3_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR3_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR3_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR3_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR3_EN;       /* 0: Channel disabled   */
    DMA2->IFCR           =  DMA_ISR_GIF3       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF3      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF3      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF3;     /* 1: clear TE flag      */
}
#endif
#if (SCI4_MASTER_FUNCTION_ON == 1)
void SCI4InitRxDma (void)
{   RCC->AHBENR         |=  RCC_AHBENR_DMA2EN; /* 1: DMA2 clock enable  */
    DMA2_Channel3->CCR  &= ~DMA_CCR3_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR3_PL        /* 00: Priority low      */
                        &  ~DMA_CCR3_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR3_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR3_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR3_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR3_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR3_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR3_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR3_EN;       /* 0: Channel disabled   */
    DMA2->IFCR           =  DMA_ISR_GIF3       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF3      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF3      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF3;     /* 1: clear TE flag      */
}
#endif

/* ******************************************************************** */
/*                            SCI4SetupRxDma ()                         */
/* ******************************************************************** */
#if (SCI4_SLAVE_FUNCTION_ON == 1)
void SCI4SetupRxDma (INT08U *pAddr, INT16U usSize)
{   DMA2_Channel3->CCR  &= ~DMA_CCR3_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR3_PL        /* 00: Priority low      */
                        &  ~DMA_CCR3_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR3_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR3_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR3_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR3_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR3_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR3_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR3_DIR       /* 0: Read from periphe  */
                        &  ~DMA_CCR3_EN;       /* 0: Channel disabled   */
    DMA2_Channel3->CCR  |=  DMA_CCR3_MINC;     /* Memory increment mode */
    DMA2->IFCR           =  DMA_ISR_GIF3       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF3      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF3      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF3;     /* 1: clear TE flag      */
    DMA2_Channel3->CNDTR = (INT16U)usSize;
    DMA2_Channel3->CPAR  = (INT32U)&(UART4->DR);
    DMA2_Channel3->CMAR  = (INT32U)pAddr;
    SCI4_SCI_RX_INT_DIS();
    SCI4_SCI_RXDMA_EN();
    SCI4_SCI_RX_EN();
   #if (SCI4_RX_DMA_TCINT_ON == 1)
    DMA2_Channel3->CCR  |=  DMA_CCR3_TCIE      /* 1: TC int enabled     */
                        |   DMA_CCR3_EN;       /* 1: Channel3 enabled   */
   #else
    DMA2_Channel3->CCR  |=  DMA_CCR3_EN;       /* 1: Channel3 enabled   */
   #endif
}
#endif
#if (SCI4_MASTER_FUNCTION_ON == 1)
void SCI4SetupRxDma (INT08U *pAddr, INT16U usSize)
{   DMA2_Channel3->CCR  &= ~DMA_CCR3_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR3_PL        /* 00: Priority low      */
                        &  ~DMA_CCR3_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR3_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR3_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR3_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR3_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR3_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR3_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR3_DIR       /* 0: Read from periphe  */
                        &  ~DMA_CCR3_EN;       /* 0: Channel disabled   */
    DMA2_Channel3->CCR  |=  DMA_CCR3_MINC;     /* Memory increment mode */
    DMA2->IFCR           =  DMA_ISR_GIF3       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF3      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF3      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF3;     /* 1: clear TE flag      */
    DMA2_Channel3->CNDTR = (INT16U)usSize;
    DMA2_Channel3->CPAR  = (INT32U)&(UART4->DR);
    DMA2_Channel3->CMAR  = (INT32U)pAddr;
    SCI4_SCI_RX_INT_DIS();
    SCI4_SCI_RXDMA_EN();
    SCI4_SCI_RX_EN();
   #if (SCI4_RX_DMA_TCINT_ON == 1)
    DMA2_Channel3->CCR  |=  DMA_CCR3_TCIE      /* 1: TC int enabled     */
                        |   DMA_CCR3_EN;       /* 1: Channel3 enabled   */
   #else
    DMA2_Channel3->CCR  |=  DMA_CCR3_EN;       /* 1: Channel3 enabled   */
   #endif
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */