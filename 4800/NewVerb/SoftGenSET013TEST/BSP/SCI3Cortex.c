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
{   uiSCI3Status    = 0;
    ucSCI3CtrlStep  = SCI3_STEP_INIT;
    ucSCI3RxByteCnt = 0;
    ucSCI3TxByteCnt = 0;
    sSCI3ModbusMsg.ucLeng = 0;
    if ((usDBpModBus1Address == 0) || (usDBpModBus1Address >= 255))
    {   sSCI3ModbusMsg.ucAddr = SCI3_MY_ADDRESS_DEF;
    }   else
    {   sSCI3ModbusMsg.ucAddr = (INT08U)usDBpModBus1Address;
    }
    if (usDBpModBus1Baudrate == 0)
    {   uiSCI3BaudRate = 1200u;
    }   else if (usDBpModBus1Baudrate == 1)
    {   uiSCI3BaudRate = 2400u;
    }   else if (usDBpModBus1Baudrate == 2)
    {   uiSCI3BaudRate = 4800u;
    }   else if (usDBpModBus1Baudrate == 3)
    {   uiSCI3BaudRate = 9600u;
    }   else if (usDBpModBus1Baudrate == 4)
    {   uiSCI3BaudRate = 19200u;
    }   else if (usDBpModBus1Baudrate == 5)
    {   uiSCI3BaudRate = 38400u;
    }   else if (usDBpModBus1Baudrate == 6)
    {   uiSCI3BaudRate = 56000u;
    }   else if (usDBpModBus1Baudrate == 7)
    {   uiSCI3BaudRate = 115000u;
    }   else
    {   uiSCI3BaudRate = SCI3_BAUDRATE_DEF;
    }
    if (uiSCI3BaudRate >= 19200u)
    {   usSCI3OverTime2P5 = 10000000u / uiSCI3BaudRate +  750;
        usSCI3OverTime2P0 = 1000;
        usSCI3OverTime4P5 = 10000000u / uiSCI3BaudRate + 1750;
        usSCI3OverTime1P5 = 10000000u / uiSCI3BaudRate +  250;
        usSCI3OverTime4P0 = 10000000u / uiSCI3BaudRate + 1500;
    }   else
    {   usSCI3OverTime2P5 = 25000000u / uiSCI3BaudRate;
        usSCI3OverTime2P0 = 20000000u / uiSCI3BaudRate;
        usSCI3OverTime4P5 = 45000000u / uiSCI3BaudRate;
        usSCI3OverTime1P5 = 15000000u / uiSCI3BaudRate;
        usSCI3OverTime4P0 = 40000000u / uiSCI3BaudRate;
    }
    if (usSCI3OverTime2P5 == usSCI3OverTime2P0)
    {   usSCI3OverTime2P5 += 1;
    }
    if (usSCI3OverTime1P5 == usSCI3OverTime2P0)
    {   usSCI3OverTime1P5 += 1;
    }
    (void)SCI3HardInit(uiSCI3BaudRate);
    (void)SCI3InitOverTimer();
   #if (SCI3_SCI_TX_DMA_ON == 1)
    (void)SCI3InitTxDma();
   #endif
   #if (SCI3_SCI_RX_DMA_ON == 1)
    (void)SCI3InitRxDma();
   #endif
}
#endif

/* ******************************************************************** */
/*                              SCI3Start ()                            */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
void SCI3Start (void)
{   SCI3_SCI_TX_DIS();
    SCI3_SCI_TC_INT_DIS();
    SCI3_SCI_RX_EN();
    SCI3_SCI_RX_INT_EN();
    (void)FWIrqEnable(TIM2_IRQn, FW_IRQ_PRIO_MID);
    (void)FWIrqEnable(USART3_IRQn, FW_IRQ_PRIO_LOW);
   #if (SCI3_TX_DMA_TCINT_ON == 1)
    (void)FWIrqEnable(DMA1_Channel2_IRQn, FW_IRQ_PRIO_LOW);
   #endif
   #if (SCI3_RX_DMA_TCINT_ON == 1)
    (void)FWIrqEnable(DMA1_Channel3_IRQn, FW_IRQ_PRIO_LOW);
   #endif
}
#endif

/* ******************************************************************** */
/*                            SCI3TaskLoop ()                           */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
void SCI3TaskLoop (void)
{   INT08U ucTmp;
    ucSCI3CtrlStep = SCI3_STEP_INIT;
    SCI3_STS_SET_BIT(SCI3_STS_ERR_RX | SCI3_STS_ERR_TX | SCI3_STS_ERR_ADDR);
    SCI3SetOverTimer(usSCI3OverTime4P5);
    while (1)
    {   (void)OSTaskSuspend(OS_PRIO_SELF);
        NumTemp[5]++;
        ucTmp = SFProcessRxModMsg(&sSCI3ModbusMsg);
        if ((ucTmp == SCI3_TRUE) && (ucSCI3CtrlStep == SCI3_STEP_IDLE))
        {   SFSetupModMsgCrc(&sSCI3ModbusMsg);
           #if (SCI3_FULL_DUPLEX_ON == 0)
            SCI3_SCI_RX_DIS();
           #endif
           #if (SCI3_SCI_TX_DMA_ON == 1)
            SCI3SetupTxDma(&sSCI3ModbusMsg.aData[0], sSCI3ModbusMsg.ucLeng);
           #else
            SCI3_SCI_TX_EN();
            SCI3_SCI_TC_INT_EN();
           #endif
        }
    }
}
#endif

/* ******************************************************************** */
/*                           SCI3TxRxIntHook ()                         */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
void SCI3TxRxIntHook (void)
{   INT08U ucDat;
    /* **************************************************************** */
    /*                          If RX a Byte                            */
    /* **************************************************************** */
    if ((USART3->SR & USART_SR_RXNE) != 0)
    {   ucDat = USART3->DR;
        /* ******************** Step = INIT *************************** */
        if (ucSCI3CtrlStep == SCI3_STEP_INIT)
        {   SCI3_STS_SET_BIT(SCI3_STS_ERR_RX | SCI3_STS_ERR_ADDR);
            SCI3SetOverTimer(usSCI3OverTime4P5);
            ucSCI3RxByteCnt = 0;
        }
        /* ******************** Step = IDLE *************************** */
        else if (ucSCI3CtrlStep == SCI3_STEP_IDLE)
        {   SCI3_STS_CLR_BIT(SCI3_STS_ERR_RX);
            SCI3_STS_SET_BIT(SCI3_STS_ERR_ADDR);
            SCI3SetOverTimer(usSCI3OverTime2P5);
            ucSCI3CtrlStep = SCI3_STEP_RX_ING;
            if((ucDat == 0) || (ucDat == sSCI3ModbusMsg.ucAddr))
            {   SCI3_STS_CLR_BIT(SCI3_STS_ERR_ADDR);
                sSCI3ModbusMsg.aData[0] = ucDat;
                ucSCI3RxByteCnt = 1;
            }
        }
        /* ******************** Step = RX_ING ************************* */
        else if (ucSCI3CtrlStep == SCI3_STEP_RX_ING)
        {   SCI3SetOverTimer(usSCI3OverTime2P5);
            if (SCI3_STS_GET_BIT(SCI3_STS_ERR_RX | SCI3_STS_ERR_ADDR) == 0)
            {   sSCI3ModbusMsg.aData[ucSCI3RxByteCnt++] = ucDat;
            }
        }
        /* *************** Step = RX_WAIT, TX_ING, TX_WAIT ************ */
        else
        {   SCI3_STS_SET_BIT(SCI3_STS_ERR_RX);
            SCI3SetOverTimer(usSCI3OverTime2P5);
            ucSCI3CtrlStep = SCI3_STEP_RX_ING;
        }
    }
    /* **************************************************************** */
    /*                          If TX Complete                          */
    /* **************************************************************** */
   #if (SCI3_SCI_TX_DMA_ON == 0)
    else if ((USART3->SR & USART_SR_TC) != 0)
    {   /* ******************** Step = IDLE *************************** */
        if (ucSCI3CtrlStep == SCI3_STEP_IDLE)
        {   ucSCI3CtrlStep  = SCI3_STEP_TX_ING;
            USART3->DR = sSCI3ModbusMsg.aData[0];
            ucSCI3TxByteCnt = 1;
        }
        /* ************ Step = INIT, RX_ING, RX_WAIT, TX_WAIT ********** */
        else if (ucSCI3CtrlStep != SCI3_STEP_TX_ING)
        {   SCI3_STS_SET_BIT(SCI3_STS_ERR_TX);
            SCI3SetOverTimer(usSCI3OverTime4P5);
            SCI3_SCI_TX_DIS();
            SCI3_SCI_TC_INT_DIS();
           #if (SCI3_FULL_DUPLEX_ON == 0)
            SCI3_SCI_RX_EN();
           #endif
        }
        /* ******************** Step = TX_ING, Cnt < Leng ************* */
        else if (ucSCI3TxByteCnt < sSCI3ModbusMsg.ucLeng)
        {   SCI3_STS_CLR_BIT(SCI3_STS_ERR_TX);
            USART3->DR = sSCI3ModbusMsg.aData[ucSCI3TxByteCnt++];
        }
        /* ******************** Step = TX_ING, Cnt = Leng ************* */
        else
        {   SCI3SetOverTimer(usSCI3OverTime4P5);
            SCI3_SCI_TX_DIS();
            SCI3_SCI_TC_INT_DIS();
           #if (SCI3_FULL_DUPLEX_ON == 0)
            SCI3_SCI_RX_EN();
           #endif
        }
    }
   #endif
}
#endif

/* ******************************************************************** */
/*                           SCI3TxRxIntHook ()                         */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
void SCI3OverTimerHook (void)
{   if (SCI3_STS_GET_BIT(SCI3_STS_TO_2P5_ON) != 0)
    {   SCI3_STS_CLR_BIT(SCI3_STS_TO_2P5_ON);
        SCI3SetOverTimer(usSCI3OverTime2P0);
        ucSCI3CtrlStep = SCI3_STEP_RX_WAIT;
    }
   #if (SCI3_SCI_TX_DMA_ON == 1)
    else if (SCI3_STS_GET_BIT(SCI3_STS_TO_1P5_ON) != 0)
    {   SCI3_STS_CLR_BIT(SCI3_STS_TO_1P5_ON);
        SCI3SetOverTimer(usSCI3OverTime4P0);
        ucSCI3CtrlStep = SCI3_STEP_TX_WAIT;
        SCI3_SCI_TX_DIS();
       #if (SCI3_FULL_DUPLEX_ON == 0)
        SCI3_SCI_RX_EN();
       #endif
    }
   #endif
    else if (ucSCI3CtrlStep == SCI3_STEP_RX_WAIT)
    {   ucSCI3CtrlStep = SCI3_STEP_IDLE;
        if (SCI3_STS_GET_BIT(SCI3_STS_ERR_RX | SCI3_STS_ERR_ADDR) == 0)
        {   sSCI3ModbusMsg.ucLeng = ucSCI3RxByteCnt;
            ucSCI3RxByteCnt = 0;
            (void)OSIntTaskResume(FW_TASK_PRIO_SCI3);
        }
        SCI3_STS_SET_BIT(SCI3_STS_ERR_RX | SCI3_STS_ERR_ADDR);
    }
    else
    {   ucSCI3CtrlStep = SCI3_STEP_IDLE;
    }
}
#endif

/* ******************************************************************** */
/*                        SCI3Dma1Ch2IntHook()                          */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
void SCI3Dma1Ch2IntHook (void)
{   DMA1_Channel2->CCR &= ~DMA_CCR2_EN;
    DMA1->IFCR = DMA_ISR_GIF2 | DMA_ISR_TCIF2 | DMA_ISR_HTIF2 | DMA_ISR_TEIF2;
    SCI3SetOverTimer(usSCI3OverTime1P5);
}
#endif

/* ******************************************************************** */
/*                        SCI3Dma1Ch3IntHook()                          */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
void SCI3Dma1Ch3IntHook (void)
{   DMA1_Channel3->CCR &= ~DMA_CCR3_EN;
    DMA1->IFCR = DMA_ISR_GIF3 | DMA_ISR_TCIF3 | DMA_ISR_HTIF3 | DMA_ISR_TEIF3;
}
#endif

/* ******************************************************************** */
/*                         SCI3InitOverTimer ()                       */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
void SCI3InitOverTimer (void)
{   RCC->APB1ENR |=  RCC_APB1ENR_TIM2EN;
    TIM2->CCR3    =  0xFFFF;
    TIM2->SR     &= ~TIM_SR_CC3IF;
    TIM2->DIER   &= ~TIM_DIER_CC3IE;
    TIM2->CR1    |=  TIM_CR1_CEN;
    TIM2->EGR     =  TIM_EGR_UG;
}
#endif

/* ******************************************************************** */
/*                          SCI3SetOverTimer ()                          */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
void SCI3SetOverTimer (INT16U usDelay)
{   if (usDelay == usSCI3OverTime1P5)
    {   SCI3_STS_SET_BIT(SCI3_STS_TO_1P5_ON);
    }   else if (usDelay == usSCI3OverTime2P5)
    {   SCI3_STS_SET_BIT(SCI3_STS_TO_2P5_ON);
    }
    TIM2->CCR3  =  TIM2->CNT + usDelay;
    TIM2->SR   &= ~TIM_SR_CC3IF;
    TIM2->DIER |=  TIM_DIER_CC3IE;
    TIM2->EGR   =  TIM_EGR_UG;
}
#endif

/* ******************************************************************** */
/*                             SCI3HardInit ()                          */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)
void SCI3HardInit (INT32U uiBaud)
{   RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
//    XIOConfigREMAP(SCI3_AFIO_REMAP1, SCI3_AFIO_REMAP2);
//    RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO, (FunctionalState)ENABLE);
//    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, (FunctionalState)ENABLE);
    XIOConfigGPIO(SCI3_TX_PT, SCI3_TX_BT, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
    XIOConfigGPIO(SCI3_RX_PT, SCI3_RX_BT, XIO_PT_GPI_FLOAT,  XIO_PT_SET_0);
    XIOConfigGPIO(SCI3_RE_PT, SCI3_RE_BT, XIO_PT_GPO_PP_10M, XIO_PT_SET_0);
    USART3->CR1 &= ~USART_CR1_SBK     /* 0: No break is transmitted     */
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
    USART3->CR2 &= ~USART_CR2_ADD     /* ADD[3:0] = 0000                */
                &  ~USART_CR2_LBDL    /* LIN break detection length     */
                &  ~USART_CR2_LBDIE   /* LIN break detection interrupt  */
                &  ~USART_CR2_LBCL    /* Last bit clock pulse           */
                &  ~USART_CR2_CPHA    /* Clock phase                    */
                &  ~USART_CR2_CPOL    /* Clock polarity                 */
                &  ~USART_CR2_CLKEN   /* Clock enable                   */
                &  ~USART_CR2_STOP    /* 00: 1 Stop bit, 10: 2 Stop bit */
                &  ~USART_CR2_LINEN;  /* 0: LIN mode disabled           */
    USART3->CR3 &= ~USART_CR3_EIE     /* 0: Error interrupt disabled    */
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
    USART3->BRR  = (INT16U)((SCI3_FRQ_CLK + uiBaud / 2) / uiBaud);
    USART3->CR1 |=  USART_CR1_UE;
}
#endif

/* ******************************************************************** */
/*                           SCI3InitTxDma()                            */
/* ******************************************************************** */
#if (SCI3_SCI_TX_DMA_ON == 1)
void SCI3InitTxDma (void)
{   RCC->AHBENR         |=  RCC_AHBENR_DMA1EN; /* 1: DMA1 clock enable  */
    DMA1_Channel2->CCR  &= ~DMA_CCR2_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR2_PL        /* 00: Priority low      */
                        &  ~DMA_CCR2_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR2_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR2_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR2_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR2_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR2_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR2_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR2_EN;       /* 0: Channel disabled   */
    DMA1->IFCR           =  DMA_ISR_GIF2       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF2      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF2      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF2;     /* 1: clear TE flag      */
}
#endif

/* ******************************************************************** */
/*                            SCI3SetupTxDma ()                         */
/* ******************************************************************** */
#if (SCI3_SCI_TX_DMA_ON == 1)
void SCI3SetupTxDma (INT08U *pAddr, INT16U usSize)
{   DMA1_Channel2->CCR  &= ~DMA_CCR2_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR2_PL        /* 00: Priority low      */
                        &  ~DMA_CCR2_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR2_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR2_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR2_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR2_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR2_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR2_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR2_EN;       /* 0: Channel disabled   */
    DMA1_Channel2->CCR  |=  DMA_CCR2_MINC      /* Memory increment mode */
                        |   DMA_CCR2_DIR;      /* 1: Read from memory   */
    DMA1->IFCR           =  DMA_ISR_GIF2       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF2      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF2      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF2;     /* 1: clear TE flag      */
    DMA1_Channel2->CNDTR = (INT16U)usSize;
    DMA1_Channel2->CPAR  = (INT32U)&(USART3->DR);
    DMA1_Channel2->CMAR  = (INT32U)pAddr;
    SCI3_SCI_TXDMA_EN();
    SCI3_SCI_TX_EN();
    SCI3_SCI_SR_TC_CLR();
   #if (SCI3_TX_DMA_TCINT_ON == 1)
    DMA1_Channel2->CCR  |=  DMA_CCR2_TCIE      /* 1: TC int enabled     */
                        |   DMA_CCR2_EN;       /* 1: Channel2 enabled   */
   #else
    DMA1_Channel2->CCR  |=  DMA_CCR2_EN;       /* 1: Channel2 enabled   */
   #endif
}
#endif

/* ******************************************************************** */
/*                           SCI3InitRxDma()                            */
/* ******************************************************************** */
#if (SCI3_SCI_RX_DMA_ON == 1)
void SCI3InitRxDma (void)
{   RCC->AHBENR         |=  RCC_AHBENR_DMA1EN; /* 1: DMA1 clock enable  */
    DMA1_Channel3->CCR  &= ~DMA_CCR3_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR3_PL        /* 00: Priority low      */
                        &  ~DMA_CCR3_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR3_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR3_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR3_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR3_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR3_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR3_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR3_EN;       /* 0: Channel disabled   */
    DMA1->IFCR           =  DMA_ISR_GIF3       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF3      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF3      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF3;     /* 1: clear TE flag      */
}
#endif

/* ******************************************************************** */
/*                            SCI3SetupRxDma ()                         */
/* ******************************************************************** */
#if (SCI3_SCI_RX_DMA_ON == 1)
void SCI3SetupRxDma (INT08U *pAddr, INT16U usSize)
{   DMA1_Channel3->CCR  &= ~DMA_CCR3_MEM2MEM   /* 0: Mem2mem mode off   */
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
    DMA1_Channel3->CCR  |=  DMA_CCR3_MINC;     /* Memory increment mode */
    DMA1->IFCR           =  DMA_ISR_GIF3       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF3      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF3      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF3;     /* 1: clear TE flag      */
    DMA1_Channel3->CNDTR = (INT16U)usSize;
    DMA1_Channel3->CPAR  = (INT32U)&(USART3->DR);
    DMA1_Channel3->CMAR  = (INT32U)pAddr;
    SCI3_SCI_RX_INT_DIS();
    SCI3_SCI_RXDMA_EN();
    SCI3_SCI_RX_EN();
   #if (SCI3_RX_DMA_TCINT_ON == 1)
    DMA1_Channel3->CCR  |=  DMA_CCR3_TCIE      /* 1: TC int enabled     */
                        |   DMA_CCR3_EN;       /* 1: Channel3 enabled   */
   #else
    DMA1_Channel3->CCR  |=  DMA_CCR3_EN;       /* 1: Channel3 enabled   */
   #endif
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */