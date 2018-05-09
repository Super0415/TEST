/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File SPI1Cortex.c                       */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   SPI1_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                              SPI1Init ()                             */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
void SPI1Init (void)
{   INT32U i;
    uiSPI1Status = 0;
    SPI1CmdBufInit();
    SPI1HardInit();
    SPI1_CS_HIGH();
    if (RTCGetTime(&sSPI1RtcTime) == FALSE)
    {   SPI1_STS_SET_BIT(SPI1_STS_ERR_RTC);
    }
    for (i=0; i<SPI1_FILE_NAME_SIZE; i++)
    {   aSPI1FileName[i] = '\n';
    }
}
#endif

/* ******************************************************************** */
/*                              SPI1Start ()                            */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
void SPI1Start (void)
{
}
#endif

/* ******************************************************************** */
/*                            SPI1TaskLoop ()                           */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
void SPI1TaskLoop (void)
{   INT08U ucComd, ucErr;
    INT32U uiWritenBytes;
    if (disk_initialize(0) != 0)
    {   SPI1_STS_SET_BIT(SPI1_STS_ERR_CARD);
    }   else
    {   SPI1_STS_CLR_BIT(SPI1_STS_ERR_CARD);
        f_mount(&sSPI1FatFs, "", 0);
    }
    while (1)
    {   ucComd = SPI1TskGetCmd (SPI1_CMD_TO_TICKS, &ucErr);
        NumTemp[10]++;
        if ((ucErr == OS_NO_ERR) &&
            (ucComd == SPI1_CMD_SAVE_FILE) &&
            (SPI1_STS_GET_BIT(SPI1_STS_ERR_CARD) == 0))
        {   if (RTCGetTime(&sSPI1RtcTime) != FALSE)
            {   SPI1_STS_CLR_BIT(SPI1_STS_ERR_RTC);
                SPI1CreatFileName(&sSPI1RtcTime,&aSPI1FileName[0]);
                if (f_open (&sSPI1File,
                           (const char*)&aSPI1FileName[0],
                            FA_CREATE_ALWAYS | FA_WRITE) == FR_OK)
                {   SPI1_STS_CLR_BIT(SPI1_STS_ERR_OPEN);
                    uiWritenBytes = 0;
                    f_write(&sSPI1File,
                            &aSPI1DataBuff[0],
                            SPI1_DATA_BUFF_SIZE,
                            &uiWritenBytes);
                    if (uiWritenBytes == SPI1_DATA_BUFF_SIZE)
                    {   SPI1_STS_CLR_BIT(SPI1_STS_ERR_WRITE);
                    }   else
                    {   SPI1_STS_SET_BIT(SPI1_STS_ERR_WRITE);
                    }
                }
                else
                {   SPI1_STS_SET_BIT(SPI1_STS_ERR_OPEN);
                }
                f_close(&sSPI1File);
            }
            else
            {   SPI1_STS_SET_BIT(SPI1_STS_ERR_RTC);
            }
        }
    }
}
#endif

/* ******************************************************************** */
/*                           SPI1TxRxIntHook ()                         */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
void SPI1CreatFileName (RTC_TIME_STR *pRtc, INT08S *pName)
{   INT16U usTemp;
    usTemp   = pRtc->year;
    *pName++ = '0' + (INT08U)(usTemp / 1000);
    usTemp   = usTemp % 1000;
    *pName++ = '0' + (INT08U)(usTemp / 100);
    usTemp   = usTemp % 100;
    *pName++ = '0' + (INT08U)(usTemp / 10);
    *pName++ = '0' + (INT08U)(usTemp % 10);
    *pName++ = '-';
    usTemp   = pRtc->month;
    *pName++ = '0' + (INT08U)(usTemp / 10);
    *pName++ = '0' + (INT08U)(usTemp % 10);
    *pName++ = '-';
    usTemp   = pRtc->mday;
    *pName++ = '0' + (INT08U)(usTemp / 10);
    *pName++ = '0' + (INT08U)(usTemp % 10);
    *pName++ = '-';
    usTemp   = pRtc->hour;
    *pName++ = '0' + (INT08U)(usTemp / 10);
    *pName++ = '0' + (INT08U)(usTemp % 10);
    *pName++ = '-';
    usTemp   = pRtc->min;
    *pName++ = '0' + (INT08U)(usTemp / 10);
    *pName++ = '0' + (INT08U)(usTemp % 10);
    *pName++ = '-';
    usTemp   = pRtc->sec;
    *pName++ = '0' + (INT08U)(usTemp / 10);
    *pName++ = '0' + (INT08U)(usTemp % 10);
    *pName++ = '.';
    *pName++ = 'd';
    *pName++ = 'a';
    *pName++ = 't';
    *pName   = '\n';
}
#endif

/* ******************************************************************** */
/*                           SPI1TxRxIntHook ()                         */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
void SPI1IntHook (void)
{
}
#endif

/* ******************************************************************** */
/*                           SPI1CmdBufInit()                           */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
void SPI1CmdBufInit (void)
{   SPI1_CMD_RING *pbuf;
    pbuf = &sSPI1CmdRingBuf;
    pbuf->usRingBufRxCtr   =  0;
    pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxOutPtr = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxSem    =  OSSemCreate(0);
}
#endif

/* ******************************************************************** */
/*                           SPI1TskGetCmd()                            */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
INT08U SPI1TskGetCmd (INT16U to, INT08U *err)
{   OS_CPU_SR cpu_sr = 0;
    INT08U c;
    INT08U oserr;
    SPI1_CMD_RING *pbuf;
    pbuf = &sSPI1CmdRingBuf;
    (void)OSSemPend(pbuf->pRingBufRxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   *err   = OS_ERR_RX_TIMEOUT;
        return OS_NULL;
    }
    OS_ENTER_CRITICAL();
    pbuf->usRingBufRxCtr--;
    c = *pbuf->pRingBufRxOutPtr++;
    if (pbuf->pRingBufRxOutPtr == &pbuf->ucRingBufRx[SPI1_CMD_BUF_SIZE])
    {   pbuf->pRingBufRxOutPtr  = &pbuf->ucRingBufRx[0];
    }
    OS_EXIT_CRITICAL();
    *err = OS_NO_ERR;
    return c;
}
#endif

/* ******************************************************************** */
/*                           SPI1TskPutCmd()                            */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
void SPI1TskPutCmd (INT08U c)
{   OS_CPU_SR cpu_sr = 0;
    SPI1_CMD_RING *pbuf;
    pbuf = &sSPI1CmdRingBuf;
    if (pbuf->usRingBufRxCtr < SPI1_CMD_BUF_SIZE)
    {   OS_ENTER_CRITICAL();
        pbuf->usRingBufRxCtr++;
        *pbuf->pRingBufRxInPtr++ = c;
        if (pbuf->pRingBufRxInPtr == &pbuf->ucRingBufRx[SPI1_CMD_BUF_SIZE])
        {   pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
        }
        OS_EXIT_CRITICAL();
        (void)OSSemPost(pbuf->pRingBufRxSem);
    }
}
#endif

/* ******************************************************************** */
/*                            SPI1HardInit()                            */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
void SPI1HardInit (void)
{   INT16U usTemp;
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
//    XIOConfigREMAP(SPI1_AFIO_REMAP1, SPI1_AFIO_REMAP2);
//    RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO, (FunctionalState)ENABLE);
//    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, (FunctionalState)ENABLE);    
    XIOConfigGPIO(SPI1_PT_CS,  SPI1_BT_CS,  XIO_PT_GPO_PP_50M, XIO_PT_SET_1);
    XIOConfigGPIO(SPI1_PT_SCK, SPI1_BT_SCK, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
    XIOConfigGPIO(SPI1_PT_IN,  SPI1_BT_IN,  XIO_PT_GPI_PULL,   XIO_PT_SET_1);
    XIOConfigGPIO(SPI1_PT_OUT, SPI1_BT_OUT, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
    XIOConfigGPIO(SPI1_PT_CD,  SPI1_BT_CD,  XIO_PT_GPI_PULL,   XIO_PT_SET_1);
    usTemp  =  SPI1->CR1;
    usTemp &= ~SPI_CR1_CPHA        /* 0: The first clock is first data  */
           &  ~SPI_CR1_CPOL        /* 0: CK to 0 when idle              */
           &  ~SPI_CR1_MSTR        /* 0: Slave configuration            */
           &  ~SPI_CR1_BR          /* 000: baud = fPCLK / 2             */
           &  ~SPI_CR1_SPE         /* 0: SPI disable                    */
           &  ~SPI_CR1_LSBFIRST    /* 0: MSB transmitted first          */
           &  ~SPI_CR1_SSI         /* 0: NSS pin set Low when SSM set   */
           &  ~SPI_CR1_SSM         /* 0: Software slave management dis  */
           &  ~SPI_CR1_RXONLY      /* 0: Full duplex (Trans and rece)   */
           &  ~SPI_CR1_DFF         /* 0: 8-bit data frame format        */
           &  ~SPI_CR1_CRCNEXT     /* 0: Data phase (no CRC phase)      */
           &  ~SPI_CR1_CRCEN       /* 0: Hardware CRC calc disabled     */
           &  ~SPI_CR1_BIDIOE      /* 0: Output disable in bidirect mod */
           &  ~SPI_CR1_BIDIMODE;   /* 0: 2-line unidirectional mode     */
    usTemp |=  SPI_CR1_CPHA        /* 1: The second clock is first data */
           |   SPI_CR1_CPOL        /* 1: CK to 1 when idle              */
      //     |   SPI_CR1_BR_0        /* 101: SCLK = PCLK / 64             */
      //     |   SPI_CR1_BR_2        /* 101: SCLK = PCLK / 64             */
           |   SPI_CR1_MSTR        /* 1: Master configuration           */
           |   SPI_CR1_SSI         /* 1: NSS pin set High when SSM set  */
           |   SPI_CR1_SSM;        /* 1: Software slave management en   */
    SPI1->CR1 = usTemp;
    usTemp  =  SPI1->I2SCFGR;
    usTemp &= ~SPI_I2SCFGR_CHLEN   /* 0: 16-bit wide (Channel length)   */
           &  ~SPI_I2SCFGR_DATLEN  /* 00: 16-bit, 01: 24-bit, 10: 32-b  */
           &  ~SPI_I2SCFGR_CKPOL   /* 0: I2S clock steady state is low  */
           &  ~SPI_I2SCFGR_I2SSTD  /* 00: I2S Philips standard          */
           &  ~SPI_I2SCFGR_PCMSYNC /* 0: Short frame synchronization    */
           &  ~SPI_I2SCFGR_I2SCFG  /* 00: S-tx, 01:S-rx,10:M-tx,11:M-rx */
           &  ~SPI_I2SCFGR_I2SE    /* 0: I2S peripheral is disabled     */
           &  ~SPI_I2SCFGR_I2SMOD; /* 0: SPI mode is selected           */
    SPI1->I2SCFGR = usTemp;
    SPI1->CRCPR = 0x0007;          /* SPI CRC polynomial (not for i2s)  */
    SPI1->CR1 |= SPI_CR1_SPE;      /* 1: SPI Enable                     */
}
#endif

/* ******************************************************************** */
/*                            SPI1Read08u()                            */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
INT08U SPI1Read08u (void)
{   while (SPI1GetFlags(SPI1_I2S_FLAG_TXE) == 0);
    SPI1->DR = SD_DUMMY_BYTE;
    while (SPI1GetFlags(SPI1_I2S_FLAG_RXNE) == 0);
    return (INT08U)(SPI1->DR);
}
#endif

/* ******************************************************************** */
/*                            SPI1Write08u()                           */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
INT08U SPI1Write08u (INT08U ucData)
{   while (SPI1GetFlags(SPI1_I2S_FLAG_TXE) == 0);
    SPI1->DR = ucData;
    while (SPI1GetFlags(SPI1_I2S_FLAG_RXNE) == 0);
    return (INT08U)(SPI1->DR);
}
#endif

/* ******************************************************************** */
/*                          SPI1Exchange08u()                           */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
INT08U SPI1Exchange08u (INT08U ucData)
{   while (SPI1GetFlags(SPI1_I2S_FLAG_TXE) == 0);
    SPI1->DR = ucData;
    while (SPI1GetFlags(SPI1_I2S_FLAG_RXNE) == 0);
    return (INT08U)(SPI1->DR);
}
#endif

/* ******************************************************************** */
/*                            SPI1Read16u()                            */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
INT16U SPI1Read16u (void)
{   while (SPI1GetFlags(SPI1_I2S_FLAG_TXE) == 0);
    SPI1->DR = (INT16U)0xFFFF;
    while (SPI1GetFlags(SPI1_I2S_FLAG_RXNE) == 0);
    return (INT16U)(SPI1->DR);
}
#endif

/* ******************************************************************** */
/*                            SPI1Write16u()                           */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
INT16U SPI1Write16u (INT16U usData)
{   while (SPI1GetFlags(SPI1_I2S_FLAG_TXE) == 0);
    SPI1->DR = usData;
    while (SPI1GetFlags(SPI1_I2S_FLAG_RXNE) == 0);
    return (INT16U)(SPI1->DR);
}
#endif

/* ******************************************************************** */
/*                          SPI1Exchange16u()                           */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
INT16U SPI1Exchange16u (INT16U usData)
{   while (SPI1GetFlags(SPI1_I2S_FLAG_TXE) == 0);
    SPI1->DR = usData;
    while (SPI1GetFlags(SPI1_I2S_FLAG_RXNE) == 0);
    return (INT16U)(SPI1->DR);
}
#endif

/* ******************************************************************** */
/*                          SPI1SendHardCrc()                           */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
void SPI1SendHardCrc (void)
{   SPI1->CR1 |= 0x1000;
}
#endif

/* ******************************************************************** */
/*                          SPI1GetHardCrc08u()                         */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
INT08U SPI1GetHardCrc08u (INT08U ucTxOrRx)
{   if (ucTxOrRx != 0)
    {   return (INT08U)(SPI1->TXCRCR);
    }   else
    {   return (INT08U)(SPI1->RXCRCR);
    }
}
#endif

/* ******************************************************************** */
/*                          SPI1GetHardCrc16u()                         */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
INT16U SPI1GetHardCrc16u (INT08U ucTxOrRx)
{   if (ucTxOrRx != 0)
    {   return SPI1->TXCRCR;
    }   else
    {   return SPI1->RXCRCR;
    }
}
#endif

/* ******************************************************************** */
/*                           SPI1GetFlags()                             */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
INT16U SPI1GetFlags (INT16U usFlgMsk)
{   return (SPI1->SR & usFlgMsk);
}
#endif

/* ******************************************************************** */
/*                           SPI1ClrFlags()                             */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
void SPI1ClrFlags (INT16U usFlgMsk)
{   SPI1->SR &= ~usFlgMsk;
}
#endif

/* ******************************************************************** */
/*                           SPI1ConfigI2S()                            */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
void SPI1ConfigI2S (INT08U ucNewState)
{   if (ucNewState != DISABLE)
    {   SPI1->I2SCFGR |= 0x0400;
    }   else
    {   SPI1->I2SCFGR &= 0xFBFF;
    }
}
#endif

/* ******************************************************************** */
/*                            SPI1ConfigIT()                            */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
void SPI1ConfigIT (INT16U usIntMsk, INT08U ucNewState)
{   if (ucNewState != DISABLE)
    {   SPI1->CR2 |=  usIntMsk;
    }   else
    {   SPI1->CR2 &= ~usIntMsk;
    }
}
#endif

/* ******************************************************************** */
/*                            SPI1ConfigDMA()                           */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
void SPI1ConfigDMA (INT16U usDmaMsk, INT08U ucNewState)
{   if (ucNewState != DISABLE)
    {   SPI1->CR2 |=  usDmaMsk;
    }   else
    {   SPI1->CR2 &= ~usDmaMsk;
    }
}
#endif

/* ******************************************************************** */
/*                         SPI1ConfigHardCrc()                          */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
void SPI1ConfigHardCrc (INT08U ucNewState)
{   if (ucNewState != DISABLE)
    {   SPI1->CR1 |= 0x2000;
    }   else
    {   SPI1->CR1 &= 0xDFFF;
    }
}
#endif

/* ******************************************************************** */
/*                          SPI1SetDataSize16b()                        */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
void SPI1SetDataSize16b (void)
{   if((SPI1->CR1 &   SPI_CR1_SPE) != 0)
    {   SPI1->CR1 &= ~SPI_CR1_SPE;
        SPI1->CR1 |=  SPI_CR1_DFF;
        SPI1->CR1 |=  SPI_CR1_SPE;
    }   else
    {   SPI1->CR1 |=  SPI_CR1_DFF;
    }
}
#endif

/* ******************************************************************** */
/*                          SPI1SetDataSize08b()                        */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)
void SPI1SetDataSize08b (void)
{   if((SPI1->CR1 &   SPI_CR1_SPE) != 0)
    {   SPI1->CR1 &= ~SPI_CR1_SPE;
        SPI1->CR1 &= ~SPI_CR1_DFF;
        SPI1->CR1 |=  SPI_CR1_SPE;
    }   else
    {   SPI1->CR1 &= ~SPI_CR1_DFF;
    }
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */