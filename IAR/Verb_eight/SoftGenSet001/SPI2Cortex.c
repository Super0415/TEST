/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File SPI2Cortex.c                       */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   SPI2_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                              SPI2Init ()                             */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
void SPI2Init (void)
{   uiSPI2Status = 0;
}
#endif

/* ******************************************************************** */
/*                              SPI2Start ()                            */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
void SPI2Start (void)
{
}
#endif

/* ******************************************************************** */
/*                            SPI2HardInit()                            */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
void SPI2HardInit (void)
{   INT16U usTemp;
    RCC->APB2ENR |= RCC_APB2ENR_SPI2EN;
    XIOConfigREMAP(SPI2_AFIO_REMAP1, SPI2_AFIO_REMAP2);
    XIOConfigGPIO(SPI2_PT_CS,  SPI2_BT_CS,  XIO_PT_GPO_PP_50M, XIO_PT_SET_1);
    XIOConfigGPIO(SPI2_PT_SCK, SPI2_BT_SCK, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
    XIOConfigGPIO(SPI2_PT_IN,  SPI2_BT_IN,  XIO_PT_GPI_PULL,   XIO_PT_SET_1);
    XIOConfigGPIO(SPI2_PT_OUT, SPI2_BT_OUT, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
    XIOConfigGPIO(SPI2_PT_CD,  SPI2_BT_CD,  XIO_PT_GPI_PULL,   XIO_PT_SET_1);
    usTemp  =  SPI2->CR1;
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
    SPI2->CR1 = usTemp;
    usTemp  =  SPI2->I2SCFGR;
    usTemp &= ~SPI_I2SCFGR_CHLEN   /* 0: 16-bit wide (Channel length)   */
           &  ~SPI_I2SCFGR_DATLEN  /* 00: 16-bit, 01: 24-bit, 10: 32-b  */
           &  ~SPI_I2SCFGR_CKPOL   /* 0: I2S clock steady state is low  */
           &  ~SPI_I2SCFGR_I2SSTD  /* 00: I2S Philips standard          */
           &  ~SPI_I2SCFGR_PCMSYNC /* 0: Short frame synchronization    */
           &  ~SPI_I2SCFGR_I2SCFG  /* 00: S-tx, 01:S-rx,10:M-tx,11:M-rx */
           &  ~SPI_I2SCFGR_I2SE    /* 0: I2S peripheral is disabled     */
           &  ~SPI_I2SCFGR_I2SMOD; /* 0: SPI mode is selected           */
    SPI2->I2SCFGR = usTemp;
    SPI2->CRCPR = 0x0007;          /* SPI CRC polynomial (not for i2s)  */
    SPI2->CR1 |= SPI_CR1_SPE;      /* 1: SPI Enable                     */
}
#endif

/* ******************************************************************** */
/*                            SPI2ReadByte()                            */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
INT08U SPI2ReadByte (void)
{   while (SPI2GetFlagStatus(SPI2_I2S_FLAG_TXE) == 0);
    SPI2SendData(SD_DUMMY_BYTE);
    while (SPI2GetFlagStatus(SPI2_I2S_FLAG_RXNE) == 0);
    return SPI2ReceiveData();
}
#endif

/* ******************************************************************** */
/*                            SPI2WriteByte()                           */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
INT08U SPI2WriteByte (INT08U ucData)
{   while (SPI2GetFlagStatus(SPI2_I2S_FLAG_TXE) == 0);
    SPI2SendData(ucData);
    while (SPI2GetFlagStatus(SPI2_I2S_FLAG_RXNE) == 0);
    return SPI2ReceiveData();
}
#endif

/* ******************************************************************** */
/*                           SPI2I2SConfig()                            */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
void SPI2I2SConfig (INT08U ucNewState)
{   if (ucNewState != DISABLE)
    {   SPI2->I2SCFGR |= 0x0400;
    }   else
    {   SPI2->I2SCFGR &= 0xFBFF;
    }
}
#endif

/* ******************************************************************** */
/*                            SPI2IntConfig()                           */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
void SPI2IntConfig (INT16U usIntMsk, INT08U ucNewState)
{   if (ucNewState != DISABLE)
    {   SPI2->CR2 |=  usIntMsk;
    }   else
    {   SPI2->CR2 &= ~usIntMsk;
    }
}
#endif

/* ******************************************************************** */
/*                            SPI2DMAConfig()                           */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
void SPI2DMAConfig (INT16U usDmaMsk, INT08U ucNewState)
{   if (ucNewState != DISABLE)
    {   SPI2->CR2 |=  usDmaMsk;
    }   else
    {   SPI2->CR2 &= ~usDmaMsk;
    }
}
#endif

/* ******************************************************************** */
/*                          SPI2DataSizeConfig()                        */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
void SPI2DataSizeConfig (INT08U uc16bOr8b)
{   if (uc16bOr8b != 0)
    {   SPI2->CR1 |= 0x0800;
    }   else
    {   SPI2->CR1 &= 0xF7FF;
    }
}
#endif

/* ******************************************************************** */
/*                            SPI2SendData()                            */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
void SPI2SendData (INT16U usData)
{   SPI2->DR = usData;
}
#endif

/* ******************************************************************** */
/*                          SPI2ReceiveData()                           */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
INT16U SPI2ReceiveData (void)
{   return SPI2->DR;
}
#endif

/* ******************************************************************** */
/*                          SPI2TransmitCRC()                           */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
void SPI2TransmitCRC (void)
{   SPI2->CR1 |= 0x1000;
}
#endif

/* ******************************************************************** */
/*                         SPI2CalculateCRC()                           */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
void SPI2CalculateCRC (INT08U ucNewState)
{   if (ucNewState != DISABLE)
    {   SPI2->CR1 |= 0x2000;
    }   else
    {   SPI2->CR1 &= 0xDFFF;
    }
}
#endif

/* ******************************************************************** */
/*                          SPI2GetCRCValue()                           */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
INT16U SPI2GetCRCValue (INT08U ucTxOrRx)
{   if (ucTxOrRx != 0)
    {   return SPI2->TXCRCR;
    }   else
    {   return SPI2->RXCRCR;
    }
}
#endif

/* ******************************************************************** */
/*                         SPI2GetFlagStatus()                          */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
INT16U SPI2GetFlagStatus (INT16U usFlgMsk)
{   return (SPI2->SR & usFlgMsk);
}
#endif

/* ******************************************************************** */
/*                           SPI2ClearFlag()                            */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
void SPI2ClearFlag (INT16U usFlgMsk)
{   SPI2->SR &= ~usFlgMsk;
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */