/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File SCI2Cortex.c                       */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   SCI2_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                              SCI2Init ()                             */
/* ******************************************************************** */
#if (SCI2_PROTOCOL_SPECIAL == 1)
void SCI2Init (void)
{   uiSCI2Status = 0;
    (void)SCI2BufInit();
    (void)SCI2HardInit(SCI2_BAUDRATE_DEF);
}
#endif
#if (SCI2_PROTOCOL_MODBUS == 1)
void SCI2Init (void)
{   uiSCI2Status    = 0;
    ucSCI2CtrlStep  = SCI2_STEP_INIT;
    ucSCI2RxByteCnt = 0;
    ucSCI2TxByteCnt = 0;
    sSCI2ModbusMsg.ucLeng = 0;
    sSCI2ModbusMsg.ucAddr = SCI2_MY_ADDRESS_DEF;
    uiSCI2BaudRate = SCI2_BAUDRATE_DEF;
    usSCI2OverTime2P5 = (INT16U)(25000000uL / uiSCI2BaudRate);
    usSCI2OverTime2P0 = (INT16U)(20000000uL / uiSCI2BaudRate);
    usSCI2OverTime4P5 = (INT16U)(45000000uL / uiSCI2BaudRate);
    usSCI2OverTime1P5 = (INT16U)(15000000uL / uiSCI2BaudRate);
    usSCI2OverTime4P0 = (INT16U)(40000000uL / uiSCI2BaudRate);
    (void)SCI2HardInit(uiSCI2BaudRate);
    (void)SCI2InitOverTimer();
   #if (SCI2_SCI_TX_DMA_ON == 1)
    (void)SCI2InitTxDma();
   #endif
   #if (SCI2_SCI_RX_DMA_ON == 1)
    (void)SCI2InitRxDma();
   #endif
}
#endif

/* ******************************************************************** */
/*                              SCI2Start ()                            */
/* ******************************************************************** */
#if (SCI2_PROTOCOL_SPECIAL == 1)
void SCI2Start (void)
{   SCI2_SCI_TX_EN();
    SCI2_SCI_TC_INT_DIS();
    SCI2_SCI_RX_EN();
    SCI2_SCI_RX_INT_EN();
    (void)FWIrqEnable(USART2_IRQn, FW_IRQ_PRIO_LOW);
}
#endif
#if (SCI2_PROTOCOL_MODBUS == 1)
void SCI2Start (void)
{   SCI2_SCI_TX_DIS();
    SCI2_SCI_TC_INT_DIS();
    SCI2_SCI_RX_EN();
    SCI2_SCI_RX_INT_EN();
    (void)FWIrqEnable(TIM2_IRQn, FW_IRQ_PRIO_MID);
    (void)FWIrqEnable(USART2_IRQn, FW_IRQ_PRIO_LOW);
   #if (SCI2_TX_DMA_TCINT_ON == 1)
    (void)FWIrqEnable(DMA1_Channel7_IRQn, FW_IRQ_PRIO_LOW);
   #endif
   #if (SCI2_RX_DMA_TCINT_ON == 1)
    (void)FWIrqEnable(DMA1_Channel6_IRQn, FW_IRQ_PRIO_LOW);
   #endif
}
#endif

/* ******************************************************************** */
/*                              SCI2Stop ()                             */
/* ******************************************************************** */
#if (SCI2_FUNCTION_ON == 1)
void SCI2Stop (void)
{
   #if (SCI2_SCI_TX_DMA_ON == 1) || (SCI2_SCI_RX_DMA_ON == 1)
    SCI2_SCI_TX_DIS();
    SCI2_SCI_TC_INT_DIS();
    SCI2_SCI_RX_DIS();
    SCI2_SCI_RX_INT_DIS();
    (void)SCI2InitOverTimer();
   #if (SCI2_SCI_TX_DMA_ON == 1)
    (void)SCI2InitTxDma();
   #endif
   #if (SCI2_SCI_RX_DMA_ON == 1)
    (void)SCI2InitRxDma();
   #endif
   #endif
}
#endif

/* ******************************************************************** */
/*                              SCI2Reset ()                            */
/* ******************************************************************** */
#if (SCI2_FUNCTION_ON == 1)
void SCI2Reset (void)
{
   #if (SCI2_SCI_TX_DMA_ON == 1) || (SCI2_SCI_RX_DMA_ON == 1)
    SCI2_SCI_TX_DIS();
    SCI2_SCI_RX_DIS();
    SCI2_SCI_TC_INT_DIS();
    SCI2_SCI_RX_INT_DIS();
    uiSCI2Status    = 0;
    ucSCI2CtrlStep  = SCI2_STEP_INIT;
    ucSCI2RxByteCnt = 0;
    ucSCI2TxByteCnt = 0;
    sSCI2ModbusMsg.ucLeng = 0;
    (void)SCI2InitOverTimer();
   #if (SCI2_SCI_TX_DMA_ON == 1)
    (void)SCI2InitTxDma();
   #endif
   #if (SCI2_SCI_RX_DMA_ON == 1)
    (void)SCI2InitRxDma();
   #endif
    SCI2_STS_SET_BIT(SCI2_STS_ERR_RX | SCI2_STS_ERR_TX | SCI2_STS_ERR_ADDR);
    SCI2SetOverTimer(usSCI2OverTime4P5);
   #endif
}
#endif

/* ******************************************************************** */
/*                            SCI2TaskLoop ()                           */
/* ******************************************************************** */
#if (SCI2_PROTOCOL_SPECIAL == 1)
void SCI2TaskLoop (void)
{   INT08U ucComd, ucChar, ucPF, ucErr;
    INT16U usWhich, usValue;
    while (1)
    {   ucComd = SCI2GetChar (SCI2_RX_TO_TICKS, &ucErr);
        if (ucErr  ==  SCI2_NO_ERR)
        {   ucPF    =  ucComd;
            ucChar  =  ucComd & SCI2_SCI_DO_MASK;
            usWhich = (INT16U)(ucComd & SCI2_SCI_H4_MASK) << 8;
            /* ******************** SCI2 Data Query ******************* */
            if (ucChar  ==  SCI2_SCI_DO_QUERY)
            {   ucChar   =  SCI2GetChar(SCI2_RX_TO_TICKS, &ucErr);
                ucPF    +=  ucChar;
                usWhich += (INT16U)ucChar;
                ucChar   =  SCI2GetChar(SCI2_RX_TO_TICKS, &ucErr);
                if ((ucErr == SCI2_NO_ERR) && (ucChar == ucPF))
                {   ucComd &= SCI2_SCI_IS_MASK;
                    if (ucComd == SCI2_SCI_IS_PARAM)
                    {   ucComd  = SCI2_TRUE;
                        usValue = DBGetParam16u(usWhich);
                    }
                    else if (ucComd == SCI2_SCI_IS_MEASU)
                    {   ucComd  = SCI2_TRUE;
                        usValue = DBGetMeasu16u(usWhich);
                    }
                    else if (ucComd == SCI2_SCI_IS_FUNCT)
                    {   ucComd  = SCI2_TRUE;
                        usValue = DBGetFunct16u(usWhich);
                    }
                    else if (ucComd == SCI2_SCI_IS_CURVE)
                    {   ucComd  = SCI2_TRUE;
                        usValue = DBGetCurve16u(usWhich);
                    }
                    else
                    {   ucComd  = SCI2_FALSE;
                    }
                    if (ucComd != SCI2_FALSE)
                    {   ucChar  = (INT08U)(usValue >> 8);
                        ucPF    =  ucChar;
                        (void)SCI2PutChar(SCI2_RX_TO_TICKS, ucChar);
                        ucChar  = (INT08U)usValue;
                        ucPF   +=  ucChar;
                        (void)SCI2PutChar(SCI2_RX_TO_TICKS, ucChar);
                        (void)SCI2PutChar(SCI2_RX_TO_TICKS, ucPF);
                    }
                }
            }
            /* ******************** SCI2 Data Modify ****************** */
            else if (ucChar == SCI2_SCI_DO_MODIFY)
            {   ucChar   =  SCI2GetChar(SCI2_RX_TO_TICKS, &ucErr);
                ucPF    +=  ucChar;
                usWhich += (INT16U)ucChar;
                ucChar   =  SCI2GetChar(SCI2_RX_TO_TICKS, &ucErr);
                ucPF    +=  ucChar;
                usValue  = (INT16U)ucChar << 8;
                ucChar   =  SCI2GetChar(SCI2_RX_TO_TICKS, &ucErr);
                ucPF    +=  ucChar;
                usValue += (INT16U)ucChar;
                ucChar   =  SCI2GetChar(SCI2_RX_TO_TICKS, &ucErr);
                if ((ucErr == SCI2_NO_ERR) && (ucChar == ucPF))
                {   ucComd &= SCI2_SCI_IS_MASK;
                    if (ucComd == SCI2_SCI_IS_PARAM)
                    {   ucComd  = DBSetParam16u(usWhich, usValue);
                    }
                    else if (ucComd == SCI2_SCI_IS_MEASU)
                    {   ucComd  = DBSetMeasu16u(usWhich, usValue);
                    }
                    else if (ucComd == SCI2_SCI_IS_FUNCT)
                    {   ucComd  = DBSetFunct16u(usWhich, usValue);
                    }
                    else if (ucComd == SCI2_SCI_IS_CURVE)
                    {   ucComd  = DBSetCurve16u(usWhich, usValue);
                    }
                    else
                    {   ucComd  = SCI2_FALSE;
                    }
                    (void)SCI2PutChar(SCI2_RX_TO_TICKS, ucComd);
                }
                else if ((ucErr == SCI2_NO_ERR) && (ucChar != ucPF))
                {   (void)SCI2PutChar(SCI2_RX_TO_TICKS, SCI2_FALSE);
                }
            }
            /* ******************** SCI2 Data Save ******************** */
            else if ((ucChar == SCI2_SCI_DO_SAVE) && (usWhich == 0))
            {   (void)SCI2PutChar(SCI2_RX_TO_TICKS, SCI2_TRUE);
                (void)DBTskPutCmd(ucComd);
            }
        }
    }
}
#endif
#if (SCI2_PROTOCOL_MODBUS == 1)
void SCI2TaskLoop (void)
{   INT08U ucTmp;
    ucSCI2CtrlStep = SCI2_STEP_INIT;
    SCI2_STS_SET_BIT(SCI2_STS_ERR_RX | SCI2_STS_ERR_TX | SCI2_STS_ERR_ADDR);
    SCI2SetOverTimer(usSCI2OverTime4P5);
    while (1)
    {   (void)OSTaskSuspend(OS_PRIO_SELF);
        ucTmp = SFProcessRxModMsg(&sSCI2ModbusMsg);
        if ((ucTmp == SCI2_TRUE) && (ucSCI2CtrlStep == SCI2_STEP_IDLE))
        {   SFSetupModMsgCrc(&sSCI2ModbusMsg);
           #if (SCI2_FULL_DUPLEX_ON == 0)
            SCI2_SCI_RX_DIS();
           #endif
           #if (SCI2_SCI_TX_DMA_ON == 1)
            SCI2SetupTxDma(&sSCI2ModbusMsg.aData[0], sSCI2ModbusMsg.ucLeng);
           #else
            SCI2_SCI_TX_EN();
            SCI2_SCI_TC_INT_EN();
           #endif
        }
    }
}
#endif

/* ******************************************************************** */
/*                           SCI2TxRxIntHook ()                         */
/* ******************************************************************** */
#if (SCI2_PROTOCOL_SPECIAL == 1)
void SCI2TxRxIntHook (void)
{   INT08U ucDat, ucErr;
    if ((USART2->SR & USART_SR_RXNE) != 0)
    {   ucDat = (INT08U)USART2->DR;
        SCI2PutRxChar(ucDat);
    }
    else if ((USART2->SR & USART_SR_TC) != 0)
    {   ucDat = SCI2GetTxChar(&ucErr);
        if (ucErr == SCI2_NO_ERR)
        {   
           #if (SCI2_FULL_DUPLEX_ON == 0)
            SCI2_SCI_RX_DIS();
           #endif
            USART2->DR = ucDat;
        }
        else
        {   SCI2_SCI_TC_INT_DIS();
           #if (SCI2_FULL_DUPLEX_ON == 0)
            SCI2_SCI_RX_EN();
           #endif
        }
    }
}
#endif
#if (SCI2_PROTOCOL_MODBUS == 1)
void SCI2TxRxIntHook (void)
{   INT08U ucDat;
    /* **************************************************************** */
    /*                          If RX a Byte                            */
    /* **************************************************************** */
    if ((USART2->SR & USART_SR_RXNE) != 0)
    {   ucDat = USART2->DR;
        /* ******************** Step = INIT *************************** */
        if (ucSCI2CtrlStep == SCI2_STEP_INIT)
        {   SCI2_STS_SET_BIT(SCI2_STS_ERR_RX | SCI2_STS_ERR_ADDR);
            SCI2SetOverTimer(usSCI2OverTime4P5);
            ucSCI2RxByteCnt = 0;
        }
        /* ******************** Step = IDLE *************************** */
        else if (ucSCI2CtrlStep == SCI2_STEP_IDLE)
        {   SCI2_STS_CLR_BIT(SCI2_STS_ERR_RX);
            SCI2_STS_SET_BIT(SCI2_STS_ERR_ADDR);
            SCI2SetOverTimer(usSCI2OverTime2P5);
            ucSCI2CtrlStep = SCI2_STEP_RX_ING;
            if((ucDat == 0) || (ucDat == sSCI2ModbusMsg.ucAddr))
            {   SCI2_STS_CLR_BIT(SCI2_STS_ERR_ADDR);
                sSCI2ModbusMsg.aData[0] = ucDat;
                ucSCI2RxByteCnt = 1;
            }
        }
        /* ******************** Step = RX_ING ************************* */
        else if (ucSCI2CtrlStep == SCI2_STEP_RX_ING)
        {   SCI2SetOverTimer(usSCI2OverTime2P5);
            if (SCI2_STS_GET_BIT(SCI2_STS_ERR_RX | SCI2_STS_ERR_ADDR) == 0)
            {   sSCI2ModbusMsg.aData[ucSCI2RxByteCnt++] = ucDat;
            }
        }
        /* *************** Step = RX_WAIT, TX_ING, TX_WAIT ************ */
        else
        {   SCI2_STS_SET_BIT(SCI2_STS_ERR_RX);
            SCI2SetOverTimer(usSCI2OverTime2P5);
            ucSCI2CtrlStep = SCI2_STEP_RX_ING;
        }
    }
    /* **************************************************************** */
    /*                          If TX Complete                          */
    /* **************************************************************** */
   #if (SCI2_SCI_TX_DMA_ON == 0)
    else if ((USART2->SR & USART_SR_TC) != 0)
    {   /* ******************** Step = IDLE *************************** */
        if (ucSCI2CtrlStep == SCI2_STEP_IDLE)
        {   ucSCI2CtrlStep  = SCI2_STEP_TX_ING;
            USART2->DR = sSCI2ModbusMsg.aData[0];
            ucSCI2TxByteCnt = 1;
        }
        /* ************ Step = INIT, RX_ING, RX_WAIT, TX_WAIT ********** */
        else if (ucSCI2CtrlStep != SCI2_STEP_TX_ING)
        {   SCI2_STS_SET_BIT(SCI2_STS_ERR_TX);
            SCI2SetOverTimer(usSCI2OverTime4P5);
            SCI2_SCI_TX_DIS();
            SCI2_SCI_TC_INT_DIS();
           #if (SCI2_FULL_DUPLEX_ON == 0)
            SCI2_SCI_RX_EN();
           #endif
        }
        /* ******************** Step = TX_ING, Cnt < Leng ************* */
        else if (ucSCI2TxByteCnt < sSCI2ModbusMsg.ucLeng)
        {   SCI2_STS_CLR_BIT(SCI2_STS_ERR_TX);
            USART2->DR = sSCI2ModbusMsg.aData[ucSCI2TxByteCnt++];
        }
        /* ******************** Step = TX_ING, Cnt = Leng ************* */
        else
        {   SCI2SetOverTimer(usSCI2OverTime4P5);
            SCI2_SCI_TX_DIS();
            SCI2_SCI_TC_INT_DIS();
           #if (SCI2_FULL_DUPLEX_ON == 0)
            SCI2_SCI_RX_EN();
           #endif
        }
    }
   #endif
}
#endif

/* ******************************************************************** */
/*                           SCI2TxRxIntHook ()                         */
/* ******************************************************************** */
#if (SCI2_PROTOCOL_SPECIAL == 1)
void SCI2OverTimerHook (void)
{
}
#endif
#if (SCI2_PROTOCOL_MODBUS == 1)
void SCI2OverTimerHook (void)
{   if (SCI2_STS_GET_BIT(SCI2_STS_TO_2P5_ON) != 0)
    {   SCI2_STS_CLR_BIT(SCI2_STS_TO_2P5_ON);
        SCI2SetOverTimer(usSCI2OverTime2P0);
        ucSCI2CtrlStep = SCI2_STEP_RX_WAIT;
    }
   #if (SCI2_SCI_TX_DMA_ON == 1)
    else if (SCI2_STS_GET_BIT(SCI2_STS_TO_1P5_ON) != 0)
    {   SCI2_STS_CLR_BIT(SCI2_STS_TO_1P5_ON);
        SCI2SetOverTimer(usSCI2OverTime4P0);
        ucSCI2CtrlStep = SCI2_STEP_TX_WAIT;
        SCI2_SCI_TX_DIS();
       #if (SCI2_FULL_DUPLEX_ON == 0)
        SCI2_SCI_RX_EN();
       #endif
    }
   #endif
    else if (ucSCI2CtrlStep == SCI2_STEP_RX_WAIT)
    {   ucSCI2CtrlStep = SCI2_STEP_IDLE;
        if (SCI2_STS_GET_BIT(SCI2_STS_ERR_RX | SCI2_STS_ERR_ADDR) == 0)
        {   sSCI2ModbusMsg.ucLeng = ucSCI2RxByteCnt;
            ucSCI2RxByteCnt = 0;
            (void)OSIntTaskResume(FW_TASK_PRIO_SCI2);
        }
        SCI2_STS_SET_BIT(SCI2_STS_ERR_RX | SCI2_STS_ERR_ADDR);
    }
    else
    {   ucSCI2CtrlStep = SCI2_STEP_IDLE;
    }
}
#endif

/* ******************************************************************** */
/*                        SCI2Dma1Ch7IntHook()                          */
/* ******************************************************************** */
#if (SCI2_FUNCTION_ON == 1)
void SCI2Dma1Ch7IntHook (void)
{   DMA1_Channel7->CCR &= ~DMA_CCR7_EN;
    DMA1->IFCR = DMA_ISR_GIF7 | DMA_ISR_TCIF7 | DMA_ISR_HTIF7 | DMA_ISR_TEIF7;
   #if (SCI2_PROTOCOL_MODBUS == 1)
    SCI2SetOverTimer(usSCI2OverTime1P5);
   #endif
}
#endif

/* ******************************************************************** */
/*                        SCI2Dma1Ch6IntHook()                          */
/* ******************************************************************** */
#if (SCI2_FUNCTION_ON == 1)
void SCI2Dma1Ch6IntHook (void)
{   DMA1_Channel6->CCR &= ~DMA_CCR6_EN;
    DMA1->IFCR = DMA_ISR_GIF6 | DMA_ISR_TCIF6 | DMA_ISR_HTIF6 | DMA_ISR_TEIF6;
}
#endif

/* ******************************************************************** */
/*                         SCI2InitOverTimer ()                         */
/* ******************************************************************** */
#if (SCI2_PROTOCOL_MODBUS == 1)
void SCI2InitOverTimer (void)
{   RCC->APB1ENR |=  RCC_APB1ENR_TIM2EN;
    TIM2->CCR2    =  0xFFFF;
    TIM2->SR     &= ~TIM_SR_CC2IF;
    TIM2->DIER   &= ~TIM_DIER_CC2IE;
    TIM2->CR1    |=  TIM_CR1_CEN;
    TIM2->EGR     =  TIM_EGR_UG;
}
#endif

/* ******************************************************************** */
/*                          SCI2SetOverTimer ()                          */
/* ******************************************************************** */
#if (SCI2_PROTOCOL_MODBUS == 1)
void SCI2SetOverTimer (INT16U usDelay)
{   if (usDelay == usSCI2OverTime1P5)
    {   SCI2_STS_SET_BIT(SCI2_STS_TO_1P5_ON);
    }   else if (usDelay == usSCI2OverTime2P5)
    {   SCI2_STS_SET_BIT(SCI2_STS_TO_2P5_ON);
    }
    TIM2->CCR2  =  TIM2->CNT + usDelay;
    TIM2->SR   &= ~TIM_SR_CC2IF;
    TIM2->DIER |=  TIM_DIER_CC2IE;
    TIM2->EGR   =  TIM_EGR_UG;
}
#endif

/* ******************************************************************** */
/*                          SCI2BufInit()                               */
/* ******************************************************************** */
#if (SCI2_PROTOCOL_SPECIAL == 1)
void SCI2BufInit (void)
{   SCI2_RING_STR *pbuf;
    pbuf = &sSCI2RingBuf;
    pbuf->usRingBufRxCtr   =  0;
    pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxOutPtr = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxSem    =  OSSemCreate(0);
    pbuf->usRingBufTxCtr   =  0;
    pbuf->pRingBufTxInPtr  = &pbuf->ucRingBufTx[0];
    pbuf->pRingBufTxOutPtr = &pbuf->ucRingBufTx[0];
    pbuf->pRingBufTxSem    =  OSSemCreate(SCI2_TX_BUF_SIZE);
}
#endif

/* ******************************************************************** */
/*                          SCI2PutRxChar()                             */
/* ******************************************************************** */
#if (SCI2_PROTOCOL_SPECIAL == 1)
void SCI2PutRxChar (INT08U c)
{   SCI2_RING_STR *pbuf;
    pbuf = &sSCI2RingBuf;
    if (pbuf->usRingBufRxCtr < SCI2_RX_BUF_SIZE)
    {   pbuf->usRingBufRxCtr++;
        *pbuf->pRingBufRxInPtr++ = c;
        if (pbuf->pRingBufRxInPtr == &pbuf->ucRingBufRx[SCI2_RX_BUF_SIZE])
        {   pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufRxSem);
    }
}
#endif

/* ******************************************************************** */
/*                          SCI2GetTxChar()                             */
/* ******************************************************************** */
#if (SCI2_PROTOCOL_SPECIAL == 1)
INT08U SCI2GetTxChar (INT08U *err)
{   INT08U c;
    SCI2_RING_STR *pbuf;
    pbuf = &sSCI2RingBuf;
    if (pbuf->usRingBufTxCtr > 0)
    {   pbuf->usRingBufTxCtr--;
        c = *pbuf->pRingBufTxOutPtr++;
        if (pbuf->pRingBufTxOutPtr == &pbuf->ucRingBufTx[SCI2_TX_BUF_SIZE])
        {   pbuf->pRingBufTxOutPtr  = &pbuf->ucRingBufTx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufTxSem);
        *err = SCI2_NO_ERR;
        return c;
    }   else
    {   *err = SCI2_ERR_TX_EMPTY;
        return 0;
    }
}
#endif

/* ******************************************************************** */
/*                           SCI2GetChar()                              */
/* ******************************************************************** */
#if (SCI2_PROTOCOL_SPECIAL == 1)
INT08U SCI2GetChar (INT16U to, INT08U *err)
{   OS_CPU_SR cpu_sr = 0;
    INT08U c, oserr;
    SCI2_RING_STR *pbuf;
    pbuf = &sSCI2RingBuf;
    (void)OSSemPend(pbuf->pRingBufRxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   *err   = SCI2_ERR_RX_TIMEOUT;
        return 0;
    }
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufRxCtr == 0)
    {   *err = SCI2_ERR_RX_TIMEOUT;
        OS_EXIT_CRITICAL();
        return 0;
    }
    pbuf->usRingBufRxCtr--;
    c = *pbuf->pRingBufRxOutPtr++;
    if (pbuf->pRingBufRxOutPtr == &pbuf->ucRingBufRx[SCI2_RX_BUF_SIZE])
    {   pbuf->pRingBufRxOutPtr  = &pbuf->ucRingBufRx[0];
    }
    OS_EXIT_CRITICAL();
    *err = SCI2_NO_ERR;
    return c;
}
#endif

/* ******************************************************************** */
/*                           SCI2PutChar()                              */
/* ******************************************************************** */
#if (SCI2_PROTOCOL_SPECIAL == 1)
INT08U SCI2PutChar (INT16U to, INT08U c)
{   OS_CPU_SR cpu_sr = 0;
    INT08U oserr;
    SCI2_RING_STR *pbuf;
    pbuf = &sSCI2RingBuf;
    (void)OSSemPend(pbuf->pRingBufTxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   return SCI2_ERR_TX_TIMEOUT;
    }   else
    {   OS_ENTER_CRITICAL();
        pbuf->usRingBufTxCtr++;
        *pbuf->pRingBufTxInPtr++ = c;
        if (pbuf->pRingBufTxInPtr == &pbuf->ucRingBufTx[SCI2_TX_BUF_SIZE])
        {   pbuf->pRingBufTxInPtr  = &pbuf->ucRingBufTx[0];
        }
        if (pbuf->usRingBufTxCtr == 1)
        {
           #if (SCI2_FULL_DUPLEX_ON == 0)
            SCI2_SCI_RX_DIS();
           #endif
            SCI2_SCI_TC_INT_EN();
        }
        OS_EXIT_CRITICAL();
        return SCI2_NO_ERR;
    }
}
#endif

/* ******************************************************************** */
/*                             SCI2HardInit ()                          */
/* ******************************************************************** */
#if (SCI2_FUNCTION_ON == 1)
void SCI2HardInit (INT32U uiBaud)
{   RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    XIOConfigREMAP(SCI2_AFIO_REMAP1, SCI2_AFIO_REMAP2);
    XIOConfigGPIO(SCI2_TX_PT, SCI2_TX_BT, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
    XIOConfigGPIO(SCI2_RX_PT, SCI2_RX_BT, XIO_PT_GPI_FLOAT,  XIO_PT_SET_0);
    USART2->CR1 &= ~USART_CR1_SBK     /* 0: No break is transmitted     */
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
    USART2->CR2 &= ~USART_CR2_ADD     /* ADD[3:0] = 0000                */
                &  ~USART_CR2_LBDL    /* LIN break detection length     */
                &  ~USART_CR2_LBDIE   /* LIN break detection interrupt  */
                &  ~USART_CR2_LBCL    /* Last bit clock pulse           */
                &  ~USART_CR2_CPHA    /* Clock phase                    */
                &  ~USART_CR2_CPOL    /* Clock polarity                 */
                &  ~USART_CR2_CLKEN   /* Clock enable                   */
                &  ~USART_CR2_STOP    /* 00: 1 Stop bit, 10: 2 Stop bit */
                &  ~USART_CR2_LINEN;  /* 0: LIN mode disabled           */
    USART2->CR3 &= ~USART_CR3_EIE     /* 0: Error interrupt disabled    */
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
    USART2->BRR  = (INT16U)((SCI2_FRQ_CLK + uiBaud / 2) / uiBaud);
    USART2->CR1 |=  USART_CR1_UE;
}
#endif

/* ******************************************************************** */
/*                           SCI2InitTxDma()                            */
/* ******************************************************************** */
#if (SCI2_SCI_TX_DMA_ON == 1)
void SCI2InitTxDma (void)
{   RCC->AHBENR         |=  RCC_AHBENR_DMA1EN; /* 1: DMA1 clock enable  */
    DMA1_Channel7->CCR  &= ~DMA_CCR7_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR7_PL        /* 00: Priority low      */
                        &  ~DMA_CCR7_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR7_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR7_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR7_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR7_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR7_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR7_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR7_EN;       /* 0: Channel disabled   */
    DMA1->IFCR           =  DMA_ISR_GIF7       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF7      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF7      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF7;     /* 1: clear TE flag      */
}
#endif

/* ******************************************************************** */
/*                            SCI2SetupTxDma ()                         */
/* ******************************************************************** */
#if (SCI2_SCI_TX_DMA_ON == 1)
void SCI2SetupTxDma (INT08U *pAddr, INT16U usSize)
{   DMA1_Channel7->CCR  &= ~DMA_CCR7_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR7_PL        /* 00: Priority low      */
                        &  ~DMA_CCR7_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR7_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR7_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR7_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR7_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR7_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR7_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR7_EN;       /* 0: Channel disabled   */
    DMA1_Channel7->CCR  |=  DMA_CCR7_MINC      /* Memory increment mode */
                        |   DMA_CCR7_DIR;      /* 1: Read from memory   */
    DMA1->IFCR           =  DMA_ISR_GIF7       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF7      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF7      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF7;     /* 1: clear TE flag      */
    DMA1_Channel7->CNDTR = (INT16U)usSize;
    DMA1_Channel7->CPAR  = (INT32U)&(USART2->DR);
    DMA1_Channel7->CMAR  = (INT32U)pAddr;
    SCI2_SCI_TXDMA_EN();
    SCI2_SCI_TX_EN();
    SCI2_SCI_SR_TC_CLR();
   #if (SCI2_TX_DMA_TCINT_ON == 1)
    DMA1_Channel7->CCR  |=  DMA_CCR7_TCIE      /* 1: TC int enabled     */
                        |   DMA_CCR7_EN;       /* 1: Channel7 enabled   */
   #else
    DMA1_Channel7->CCR  |=  DMA_CCR7_EN;       /* 1: Channel7 enabled   */
   #endif
}
#endif

/* ******************************************************************** */
/*                           SCI2InitRxDma()                            */
/* ******************************************************************** */
#if (SCI2_SCI_RX_DMA_ON == 1)
void SCI2InitRxDma (void)
{   RCC->AHBENR         |=  RCC_AHBENR_DMA1EN; /* 1: DMA1 clock enable  */
    DMA1_Channel6->CCR  &= ~DMA_CCR6_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR6_PL        /* 00: Priority low      */
                        &  ~DMA_CCR6_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR6_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR6_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR6_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR6_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR6_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR6_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR6_EN;       /* 0: Channel disabled   */
    DMA1->IFCR           =  DMA_ISR_GIF6       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF6      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF6      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF6;     /* 1: clear TE flag      */
}
#endif

/* ******************************************************************** */
/*                            SCI2SetupRxDma ()                         */
/* ******************************************************************** */
#if (SCI2_SCI_RX_DMA_ON == 1)
void SCI2SetupRxDma (INT08U *pAddr, INT16U usSize)
{   DMA1_Channel6->CCR  &= ~DMA_CCR6_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR6_PL        /* 00: Priority low      */
                        &  ~DMA_CCR6_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR6_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR6_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR6_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR6_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR6_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR6_TCIE      /* 0: TC interrupt off   */
                        &  ~DMA_CCR6_DIR       /* 0: Read from periphe  */
                        &  ~DMA_CCR6_EN;       /* 0: Channel disabled   */
    DMA1_Channel6->CCR  |=  DMA_CCR6_MINC;     /* Memory increment mode */
    DMA1->IFCR           =  DMA_ISR_GIF6       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF6      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF6      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF6;     /* 1: clear TE flag      */
    DMA1_Channel6->CNDTR = (INT16U)usSize;
    DMA1_Channel6->CPAR  = (INT32U)&(USART2->DR);
    DMA1_Channel6->CMAR  = (INT32U)pAddr;
    SCI2_SCI_RX_INT_DIS();
    SCI2_SCI_RXDMA_EN();
    SCI2_SCI_RX_EN();
   #if (SCI2_RX_DMA_TCINT_ON == 1)
    DMA1_Channel6->CCR  |=  DMA_CCR6_TCIE      /* 1: TC int enabled     */
                        |   DMA_CCR6_EN;       /* 1: Channel6 enabled   */
   #else
    DMA1_Channel6->CCR  |=  DMA_CCR6_EN;       /* 1: Channel6 enabled   */
   #endif
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */