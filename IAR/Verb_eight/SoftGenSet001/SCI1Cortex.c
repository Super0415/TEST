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
{   uiSCI1Status    = 0;
    ucSCI1CtrlStep  = SCI1_STEP_INIT;
    ucSCI1RxByteCnt = 0;
    ucSCI1TxByteCnt = 0;
    sSCI1ModbusMsg.ucLeng = 0;
    if ((usDBpModBus2Address == 0) || (usDBpModBus2Address >= 255))
    {   sSCI1ModbusMsg.ucAddr = SCI1_MY_ADDRESS_DEF;
    }   else
    {   sSCI1ModbusMsg.ucAddr = (INT08U)usDBpModBus2Address;
    }
    if (usDBpModBus2Baudrate == 0)
    {   uiSCI1BaudRate = 1200u;
    }   else if (usDBpModBus2Baudrate == 1)
    {   uiSCI1BaudRate = 2400u;
    }   else if (usDBpModBus2Baudrate == 2)
    {   uiSCI1BaudRate = 4800u;
    }   else if (usDBpModBus2Baudrate == 3)
    {   uiSCI1BaudRate = 9600u;
    }   else if (usDBpModBus2Baudrate == 4)
    {   uiSCI1BaudRate = 19200u;
    }   else if (usDBpModBus2Baudrate == 5)
    {   uiSCI1BaudRate = 38400u;
    }   else if (usDBpModBus2Baudrate == 6)
    {   uiSCI1BaudRate = 57600u;
    }   else if (usDBpModBus2Baudrate == 7)
    {   uiSCI1BaudRate = 115200u;
    }   else
    {   uiSCI1BaudRate = SCI1_BAUDRATE_DEF;
    }
    if (uiSCI1BaudRate >= 19200u)
    {   usSCI1OverTime2P5 = 10000000u / uiSCI1BaudRate +  750;
        usSCI1OverTime2P0 = 1000;
        usSCI1OverTime4P5 = 10000000u / uiSCI1BaudRate + 1750;
        usSCI1OverTime1P5 = 10000000u / uiSCI1BaudRate +  250;
        usSCI1OverTime4P0 = 10000000u / uiSCI1BaudRate + 1500;
    }   else
    {   usSCI1OverTime2P5 = 25000000u / uiSCI1BaudRate;
        usSCI1OverTime2P0 = 20000000u / uiSCI1BaudRate;
        usSCI1OverTime4P5 = 45000000u / uiSCI1BaudRate;
        usSCI1OverTime1P5 = 15000000u / uiSCI1BaudRate;
        usSCI1OverTime4P0 = 40000000u / uiSCI1BaudRate;
    }
    if (usSCI1OverTime2P5 == usSCI1OverTime2P0)
    {   usSCI1OverTime2P5 += 1;
    }
    if (usSCI1OverTime1P5 == usSCI1OverTime2P0)
    {   usSCI1OverTime1P5 += 1;
    }
    (void)SCI1HardInit(uiSCI1BaudRate);
    (void)SCI1InitOverTimer();
   #if (SCI1_SCI_TX_DMA_ON == 1)
    (void)SCI1InitTxDma();
   #endif
   #if (SCI1_SCI_RX_DMA_ON == 1)
    (void)SCI1InitRxDma();
   #endif
}
#endif

/* ******************************************************************** */
/*                              SCI1Start ()                            */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
void SCI1Start (void)
{   SCI1_SCI_TX_DIS();
    SCI1_SCI_TC_INT_DIS();
    SCI1_SCI_RX_EN();
    SCI1_SCI_RX_INT_EN();
    (void)FWIrqEnable(TIM2_IRQn, FW_IRQ_PRIO_MID);
    (void)FWIrqEnable(USART1_IRQn, FW_IRQ_PRIO_LOW);
   #if (SCI1_SCI_TX_DMA_ON == 1)
    (void)FWIrqEnable(DMA1_Channel4_IRQn, FW_IRQ_PRIO_LOW);
   #endif
   #if (SCI1_SCI_RX_DMA_ON == 1)
    (void)FWIrqEnable(DMA1_Channel5_IRQn, FW_IRQ_PRIO_LOW);
   #endif
}
#endif

/* ******************************************************************** */
/*                            SCI1TaskLoop ()                           */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
void SCI1TaskLoop (void)
{   INT08U ucTmp;
    ucSCI1CtrlStep = SCI1_STEP_INIT;
    SCI1_STS_SET_BIT(SCI1_STS_ERR_RX | SCI1_STS_ERR_TX | SCI1_STS_ERR_ADDR);
    SCI1SetOverTimer(usSCI1OverTime4P5);
    while (1)
    {   (void)OSTaskSuspend(OS_PRIO_SELF);
        ucTmp = SFProcessRxModMsg(&sSCI1ModbusMsg);
        if ((ucTmp == SCI1_TRUE) && (ucSCI1CtrlStep == SCI1_STEP_IDLE))
        {   SFSetupModMsgCrc(&sSCI1ModbusMsg);
           #if (SCI1_FULL_DUPLEX_ON == 0)
            SCI1_SCI_RX_DIS();
           #endif
           #if (SCI1_SCI_TX_DMA_ON == 1)
            SCI1SetupTxDma(&sSCI1ModbusMsg.aData[0], sSCI1ModbusMsg.ucLeng);
           #else
            SCI1_SCI_TX_EN();
            SCI1_SCI_TC_INT_EN();
           #endif
        }
    }
}
#endif

/* ******************************************************************** */
/*                           SCI1TxRxIntHook ()                         */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
void SCI1TxRxIntHook (void)
{   INT08U ucDat;
    /* **************************************************************** */
    /*                          If RX a Byte                            */
    /* **************************************************************** */
    if ((USART1->SR & USART_SR_RXNE) != 0)
    {   ucDat = USART1->DR;
        /* ******************** Step = INIT *************************** */
        if (ucSCI1CtrlStep == SCI1_STEP_INIT)
        {   SCI1_STS_SET_BIT(SCI1_STS_ERR_RX | SCI1_STS_ERR_ADDR);
            SCI1SetOverTimer(usSCI1OverTime4P5);
            ucSCI1RxByteCnt = 0;
        }
        /* ******************** Step = IDLE *************************** */
        else if (ucSCI1CtrlStep == SCI1_STEP_IDLE)
        {   SCI1_STS_CLR_BIT(SCI1_STS_ERR_RX);
            SCI1_STS_SET_BIT(SCI1_STS_ERR_ADDR);
            SCI1SetOverTimer(usSCI1OverTime2P5);
            ucSCI1CtrlStep = SCI1_STEP_RX_ING;
            if((ucDat == 0) || (ucDat == sSCI1ModbusMsg.ucAddr))
            {   SCI1_STS_CLR_BIT(SCI1_STS_ERR_ADDR);
                sSCI1ModbusMsg.aData[0] = ucDat;
                ucSCI1RxByteCnt = 1;
            }
        }
        /* ******************** Step = RX_ING ************************* */
        else if (ucSCI1CtrlStep == SCI1_STEP_RX_ING)
        {   SCI1SetOverTimer(usSCI1OverTime2P5);
            if (SCI1_STS_GET_BIT(SCI1_STS_ERR_RX | SCI1_STS_ERR_ADDR) == 0)
            {   sSCI1ModbusMsg.aData[ucSCI1RxByteCnt++] = ucDat;
            }
        }
        /* *************** Step = RX_WAIT, TX_ING, TX_WAIT ************ */
        else
        {   SCI1_STS_SET_BIT(SCI1_STS_ERR_RX);
            SCI1SetOverTimer(usSCI1OverTime2P5);
            ucSCI1CtrlStep = SCI1_STEP_RX_ING;
        }
    }
    /* **************************************************************** */
    /*                          If TX Complete                          */
    /* **************************************************************** */
   #if (SCI1_SCI_TX_DMA_ON == 0)
    else if ((USART1->SR & USART_SR_TC) != 0)
    {   /* ******************** Step = IDLE *************************** */
        if (ucSCI1CtrlStep == SCI1_STEP_IDLE)
        {   ucSCI1CtrlStep  = SCI1_STEP_TX_ING;
            USART1->DR = sSCI1ModbusMsg.aData[0];
            ucSCI1TxByteCnt = 1;
        }
        /* ************ Step = INIT, RX_ING, RX_WAIT, TX_WAIT ********** */
        else if (ucSCI1CtrlStep != SCI1_STEP_TX_ING)
        {   SCI1_STS_SET_BIT(SCI1_STS_ERR_TX);
            SCI1SetOverTimer(usSCI1OverTime4P5);
            SCI1_SCI_TX_DIS();
            SCI1_SCI_TC_INT_DIS();
           #if (SCI1_FULL_DUPLEX_ON == 0)
            SCI1_SCI_RX_EN();
           #endif
        }
        /* ******************** Step = TX_ING, Cnt < Leng ************* */
        else if (ucSCI1TxByteCnt < sSCI1ModbusMsg.ucLeng)
        {   SCI1_STS_CLR_BIT(SCI1_STS_ERR_TX);
            USART1->DR = sSCI1ModbusMsg.aData[ucSCI1TxByteCnt++];
        }
        /* ******************** Step = TX_ING, Cnt = Leng ************* */
        else
        {   SCI1SetOverTimer(usSCI1OverTime4P5);
            SCI1_SCI_TX_DIS();
            SCI1_SCI_TC_INT_DIS();
           #if (SCI1_FULL_DUPLEX_ON == 0)
            SCI1_SCI_RX_EN();
           #endif
        }
    }
   #endif
}
#endif

/* ******************************************************************** */
/*                           SCI1TxRxIntHook ()                         */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
void SCI1OverTimerHook (void)
{   if (SCI1_STS_GET_BIT(SCI1_STS_TO_2P5_ON) != 0)
    {   SCI1_STS_CLR_BIT(SCI1_STS_TO_2P5_ON);
        SCI1SetOverTimer(usSCI1OverTime2P0);
        ucSCI1CtrlStep = SCI1_STEP_RX_WAIT;
    }
   #if (SCI1_SCI_TX_DMA_ON == 1)
    else if (SCI1_STS_GET_BIT(SCI1_STS_TO_1P5_ON) != 0)
    {   SCI1_STS_CLR_BIT(SCI1_STS_TO_1P5_ON);
        SCI1SetOverTimer(usSCI1OverTime4P0);
        ucSCI1CtrlStep = SCI1_STEP_TX_WAIT;
        SCI1_SCI_TX_DIS();
       #if (SCI1_FULL_DUPLEX_ON == 0)
        SCI1_SCI_RX_EN();
       #endif
    }
   #endif
    else if (ucSCI1CtrlStep == SCI1_STEP_RX_WAIT)
    {   ucSCI1CtrlStep = SCI1_STEP_IDLE;
        if (SCI1_STS_GET_BIT(SCI1_STS_ERR_RX | SCI1_STS_ERR_ADDR) == 0)
        {   sSCI1ModbusMsg.ucLeng = ucSCI1RxByteCnt;
            ucSCI1RxByteCnt = 0;
            (void)OSIntTaskResume(FW_TASK_PRIO_SCI1);
        }
        SCI1_STS_SET_BIT(SCI1_STS_ERR_RX | SCI1_STS_ERR_ADDR);
    }
    else
    {   ucSCI1CtrlStep = SCI1_STEP_IDLE;
    }
}
#endif

/* ******************************************************************** */
/*                        SCI1Dma1Ch4IntHook()                          */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
#if (SCI1_SCI_TX_DMA_ON == 1)
void SCI1Dma1Ch4IntHook (void)
{   DMA1_Channel4->CCR &= ~DMA_CCR4_EN;
    DMA1->IFCR = DMA_ISR_GIF4 | DMA_ISR_TCIF4 | DMA_ISR_HTIF4 | DMA_ISR_TEIF4;
    SCI1SetOverTimer(usSCI1OverTime1P5);
}
#endif
#endif

/* ******************************************************************** */
/*                        SCI1Dma1Ch5IntHook()                          */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
#if (SCI1_SCI_RX_DMA_ON == 1)
void SCI1Dma1Ch5IntHook (void)
{   DMA1_Channel5->CCR &= ~DMA_CCR5_EN;
    DMA1->IFCR = DMA_ISR_GIF5 | DMA_ISR_TCIF5 | DMA_ISR_HTIF5 | DMA_ISR_TEIF5;
}
#endif
#endif

/* ******************************************************************** */
/*                         SCI1InitOverTimer ()                       */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
void SCI1InitOverTimer (void)
{   RCC->APB1ENR |=  RCC_APB1ENR_TIM2EN;
    TIM2->CCR1    =  0xFFFF;
    TIM2->SR     &= ~TIM_SR_CC1IF;
    TIM2->DIER   &= ~TIM_DIER_CC1IE;
    TIM2->CR1    |=  TIM_CR1_CEN;
    TIM2->EGR     =  TIM_EGR_UG;
}
#endif

/* ******************************************************************** */
/*                          SCI1SetOverTimer ()                          */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
void SCI1SetOverTimer (INT16U usDelay)
{   if (usDelay == usSCI1OverTime1P5)
    {   SCI1_STS_SET_BIT(SCI1_STS_TO_1P5_ON);
    }   else if (usDelay == usSCI1OverTime2P5)
    {   SCI1_STS_SET_BIT(SCI1_STS_TO_2P5_ON);
    }
    TIM2->CCR1  =  TIM2->CNT + usDelay;
    TIM2->SR   &= ~TIM_SR_CC1IF;
    TIM2->DIER |=  TIM_DIER_CC1IE;
    TIM2->EGR   =  TIM_EGR_UG;
}
#endif

/* ******************************************************************** */
/*                             SCI1HardInit ()                          */
/* ******************************************************************** */
#if (SCI1_FUNCTION_ON == 1)
void SCI1HardInit (INT32U uiBaud)
{   RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    XIOConfigREMAP(SCI1_AFIO_REMAP1, SCI1_AFIO_REMAP2);
    XIOConfigGPIO(SCI1_RELOAD_PT, SCI1_RELOAD_BT, XIO_PT_GPO_PP_02M, XIO_PT_SET_1);
    SCI1_SET_RELOAD();
    XIOConfigGPIO(SCI1_TX_PT, SCI1_TX_BT, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
    XIOConfigGPIO(SCI1_RX_PT, SCI1_RX_BT, XIO_PT_GPI_FLOAT,  XIO_PT_SET_0);
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
                &  ~USART_CR1_PCE     /* 0: Parity control disabled     */
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
    USART1->BRR  = (INT16U)((SCI1_FRQ_CLK + uiBaud / 2) / uiBaud);
    USART1->CR1 |=  USART_CR1_UE;
}
#endif

/* ******************************************************************** */
/*                           SCI1InitTxDma()                            */
/* ******************************************************************** */
#if (SCI1_SCI_TX_DMA_ON == 1)
void SCI1InitTxDma (void)
{   RCC->AHBENR         |=  RCC_AHBENR_DMA1EN; /* 1: DMA1 clock enable  */
    DMA1_Channel4->CCR  &= ~DMA_CCR4_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR4_PL        /* 00: Priority low      */
                        &  ~DMA_CCR4_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR4_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR4_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR4_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR4_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR4_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR4_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR4_EN;       /* 0: Channel disabled   */
    DMA1->IFCR           =  DMA_ISR_GIF4       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF4      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF4      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF4;     /* 1: clear TE flag      */
}
#endif

/* ******************************************************************** */
/*                            SCI1SetupTxDma ()                         */
/* ******************************************************************** */
#if (SCI1_SCI_TX_DMA_ON == 1)
void SCI1SetupTxDma (INT08U *pAddr, INT16U usSize)
{   DMA1_Channel4->CCR  &= ~DMA_CCR4_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR4_PL        /* 00: Priority low      */
                        &  ~DMA_CCR4_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR4_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR4_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR4_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR4_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR4_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR4_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR4_EN;       /* 0: Channel disabled   */
    DMA1_Channel4->CCR  |=  DMA_CCR4_MINC      /* Memory increment mode */
                        |   DMA_CCR4_DIR;      /* 1: Read from memory   */
    DMA1->IFCR           =  DMA_ISR_GIF4       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF4      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF4      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF4;     /* 1: clear TE flag      */
    DMA1_Channel4->CNDTR = (INT16U)usSize;
    DMA1_Channel4->CPAR  = (INT32U)&(USART1->DR);
    DMA1_Channel4->CMAR  = (INT32U)pAddr;
    SCI1_SCI_TXDMA_EN();
    SCI1_SCI_TX_EN();
    SCI1_SCI_SR_TC_CLR();
    DMA1_Channel4->CCR  |=  DMA_CCR4_TCIE      /* 1: TC int enabled     */
                        |   DMA_CCR4_EN;       /* 1: Channel7 enabled   */
}
#endif

/* ******************************************************************** */
/*                           SCI1InitRxDma()                            */
/* ******************************************************************** */
#if (SCI1_SCI_RX_DMA_ON == 1)
void SCI1InitRxDma (void)
{   RCC->AHBENR         |=  RCC_AHBENR_DMA1EN; /* 1: DMA1 clock enable  */
    DMA1_Channel5->CCR  &= ~DMA_CCR5_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR5_PL        /* 00: Priority low      */
                        &  ~DMA_CCR5_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR5_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR5_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR5_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR5_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR5_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR5_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR5_EN;       /* 0: Channel disabled   */
    DMA1->IFCR           =  DMA_ISR_GIF5       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF5      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF5      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF5;     /* 1: clear TE flag      */
}
#endif

/* ******************************************************************** */
/*                            SCI1SetupRxDma ()                         */
/* ******************************************************************** */
#if (SCI1_SCI_RX_DMA_ON == 1)
void SCI1SetupRxDma (INT08U *pAddr, INT16U usSize)
{   DMA1_Channel5->CCR  &= ~DMA_CCR5_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR5_PL        /* 00: Priority low      */
                        &  ~DMA_CCR5_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR5_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR5_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR5_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR5_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR5_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR5_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR5_DIR       /* 0: Read from periphe  */
                        &  ~DMA_CCR5_EN;       /* 0: Channel disabled   */
    DMA1_Channel5->CCR  |=  DMA_CCR5_MINC;     /* Memory increment mode */
    DMA1->IFCR           =  DMA_ISR_GIF5       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF5      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF5      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF5;     /* 1: clear TE flag      */
    DMA1_Channel5->CNDTR = (INT16U)usSize;
    DMA1_Channel5->CPAR  = (INT32U)&(USART1->DR);
    DMA1_Channel5->CMAR  = (INT32U)pAddr;
    SCI1_SCI_RX_INT_DIS();
    SCI1_SCI_RXDMA_EN();
    SCI1_SCI_RX_EN();
    DMA1_Channel5->CCR  |=  DMA_CCR5_TCIE      /* 1: TC int enabled     */
                        |   DMA_CCR5_EN;       /* 1: Channel5 enabled   */
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */