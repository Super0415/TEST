/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File SPI3Cortex.c                       */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   SPI3_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                              SDInit()                                */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT08U SDInit(void)
{   SPI3HardInit();
    SPI3_CS_HIGH();
    SDWriteByte(SD_DUMMY_BYTE);
    SDWriteByte(SD_DUMMY_BYTE);
    SDWriteByte(SD_DUMMY_BYTE);
    SDWriteByte(SD_DUMMY_BYTE);
    SDWriteByte(SD_DUMMY_BYTE);
    SDWriteByte(SD_DUMMY_BYTE);
    SDWriteByte(SD_DUMMY_BYTE);
    SDWriteByte(SD_DUMMY_BYTE);
    SDWriteByte(SD_DUMMY_BYTE);
    SDWriteByte(SD_DUMMY_BYTE);
    return SDGoIdleState();
}
#endif

/* ******************************************************************** */
/*                             SDDetect()                               */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT08U SDDetect (void)
{   if (SPI3_GET_DETECT_PIN() != 0)
    {   return SD_NOT_PRESENT;
    }
    return SD_PRESENT;
}
#endif

/* ******************************************************************** */
/*                           SDGetCardInfo()                            */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT08U SDGetCardInfo (SD_CARD_INFO *pInfo)
{   INT08U ucStatus;
    ucStatus = SDGetCSDRegister(&(pInfo->SD_csd));
    ucStatus = SDGetCIDRegister(&(pInfo->SD_cid));
    pInfo->CardCapacity   = (pInfo->SD_csd.DeviceSize + 1) ;
    pInfo->CardCapacity  *= (1 << (pInfo->SD_csd.DeviceSizeMul + 2));
    pInfo->CardBlockSize  =  1 << (pInfo->SD_csd.RdBlockLen);
    pInfo->CardCapacity  *=  pInfo->CardBlockSize;
    return ucStatus;
}
#endif

/* ******************************************************************** */
/*                           SDReadBlock()                              */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT08U SDReadBlock (INT08U* pBuff, INT32U uiAddr, INT16U usBSiz)
{   SPI3_CS_LOW();
    SDSendCmd(SD_CMD_READ_SINGLE_BLOCK, uiAddr, 0xFF);
    if (SDGetResponse(SD_RESPONSE_NO_ERROR) == 0)
    {   if (SDGetResponse(SD_START_SINGLE_BL_READ) == 0)
        {   while (usBSiz--)
            {   *pBuff++ = SDReadByte();
            }
            (void)SDReadByte();
            (void)SDReadByte();
            SPI3_CS_HIGH();
            (void)SDWriteByte(SD_DUMMY_BYTE);
            return SD_RESPONSE_NO_ERROR;
        }
    }
    SPI3_CS_HIGH();
    SDWriteByte(SD_DUMMY_BYTE);
    return SD_RESPONSE_FAILURE;
}
#endif

/* ******************************************************************** */
/*                           SDReadBlock()                              */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT08U SDReadMultBlock (INT08U *pBuff, INT32U uiAddr, INT16U usBSiz, INT32U usBNum)
{   INT32U uiCnt    = 0;
    INT32U uiOffset = 0;
    INT08U ucError  = SD_RESPONSE_FAILURE;
    SPI3_CS_LOW();
    while (usBNum--)
    {   SDSendCmd(SD_CMD_READ_SINGLE_BLOCK, uiAddr+uiOffset, 0xFF);
        if (SDGetResponse(SD_RESPONSE_NO_ERROR) != 0)
        {   SPI3_CS_HIGH();
            return SD_RESPONSE_FAILURE;
        }
        if (SDGetResponse(SD_START_SINGLE_BL_READ) == 0)
        {   for (uiCnt = 0; uiCnt < usBSiz; uiCnt++)
            {   *pBuff++ = SDReadByte();
            }
            uiOffset += 512;
            SDReadByte();
            SDReadByte();
            ucError = SD_RESPONSE_NO_ERROR;
        }
        else
        {   ucError = SD_RESPONSE_FAILURE;
        }
    }
    SPI3_CS_HIGH();
    SDWriteByte(SD_DUMMY_BYTE);
    return ucError;
}
#endif

/* ******************************************************************** */
/*                           SDWriteBlock()                             */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT08U SDWriteBlock (INT08U *pBuff, INT32U uiAddr, INT16U usBSiz)
{   INT08U ucError = SD_RESPONSE_FAILURE;
    SPI3_CS_LOW();
    SDSendCmd(SD_CMD_WRITE_SINGLE_BLOCK, uiAddr, 0xFF);
    if (SDGetResponse(SD_RESPONSE_NO_ERROR) != 0)
    {   SDWriteByte(SD_DUMMY_BYTE);
        SDWriteByte(0xFE);
        while (usBSiz--)
        {   SDWriteByte(*pBuff++);
        }
        SDReadByte();
        SDReadByte();
        if (SDGetDataResponse() == SD_DATA_OK)
        {   ucError = SD_RESPONSE_NO_ERROR;
        }
    }
    SPI3_CS_HIGH();
    SDWriteByte(SD_DUMMY_BYTE);
    return ucError;
}
#endif

/* ******************************************************************** */
/*                           SDWriteMultBlock()                             */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT08U SDWriteMultBlock (INT08U *pBuff, INT32U uiAddr, INT16U usBSiz, INT32U uiBNum)
{   INT32U uiCnt    = 0;
    INT32U uiOffset = 0;
    INT08U ucError  = SD_RESPONSE_FAILURE;
    SPI3_CS_LOW();
    while (uiBNum--)
    {   SDSendCmd(SD_CMD_WRITE_SINGLE_BLOCK, uiAddr+uiOffset, 0xFF);
        if (SDGetResponse(SD_RESPONSE_NO_ERROR) != 0)
        {   return SD_RESPONSE_FAILURE;
        }
        SDWriteByte(SD_DUMMY_BYTE);
        SDWriteByte(SD_START_SINGLE_BL_WRITE);
        for (uiCnt = 0; uiCnt < usBSiz; uiCnt++)
        {   SDWriteByte(*pBuff++);
        }
        uiOffset += 512;
        SDReadByte();
        SDReadByte();
        if (SDGetDataResponse() == SD_DATA_OK)
        {   ucError = SD_RESPONSE_NO_ERROR;
        }   else
        {   ucError = SD_RESPONSE_FAILURE;
        }
    }
    SPI3_CS_HIGH();
    SDWriteByte(SD_DUMMY_BYTE);
    return ucError;
}
#endif

/* ******************************************************************** */
/*                         SDGetCIDRegister()                           */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT08U SDGetCSDRegister (SD_CSD_STR* pSdCsd)
{   INT08U ucError = SD_RESPONSE_FAILURE;
    INT08U ucCsdTab[16];
    SPI3_CS_LOW();
    SDSendCmd(SD_CMD_SEND_CSD, 0, 0xFF);
    if (SDGetResponse(SD_RESPONSE_NO_ERROR) == 0)
    {   if (SDGetResponse(SD_START_SINGLE_BL_READ) == 0)
        {   ucCsdTab[0]  = SDReadByte();
            ucCsdTab[1]  = SDReadByte();
            ucCsdTab[2]  = SDReadByte();
            ucCsdTab[3]  = SDReadByte();
            ucCsdTab[4]  = SDReadByte();
            ucCsdTab[5]  = SDReadByte();
            ucCsdTab[6]  = SDReadByte();
            ucCsdTab[7]  = SDReadByte();
            ucCsdTab[8]  = SDReadByte();
            ucCsdTab[9]  = SDReadByte();
            ucCsdTab[10] = SDReadByte();
            ucCsdTab[11] = SDReadByte();
            ucCsdTab[12] = SDReadByte();
            ucCsdTab[13] = SDReadByte();
            ucCsdTab[14] = SDReadByte();
            ucCsdTab[15] = SDReadByte();
        }
        SDWriteByte(SD_DUMMY_BYTE);
        SDWriteByte(SD_DUMMY_BYTE);
        ucError = SD_RESPONSE_NO_ERROR;
    }
    SPI3_CS_HIGH();
    SDWriteByte(SD_DUMMY_BYTE);
    pSdCsd->CSDStruct           = (ucCsdTab[0] & 0xC0) >> 6;
    pSdCsd->SysSpecVersion      = (ucCsdTab[0] & 0x3C) >> 2;
    pSdCsd->Reserved1           =  ucCsdTab[0] & 0x03;
    pSdCsd->TAAC                =  ucCsdTab[1];
    pSdCsd->NSAC                =  ucCsdTab[2];
    pSdCsd->MaxBusClkFrec       =  ucCsdTab[3];
    pSdCsd->CardComdClasses     =  ucCsdTab[4] << 4;
    pSdCsd->CardComdClasses    |= (ucCsdTab[5] & 0xF0) >> 4;
    pSdCsd->RdBlockLen          =  ucCsdTab[5] & 0x0F;
    pSdCsd->PartBlockRead       = (ucCsdTab[6] & 0x80) >> 7;
    pSdCsd->WrBlockMisalign     = (ucCsdTab[6] & 0x40) >> 6;
    pSdCsd->RdBlockMisalign     = (ucCsdTab[6] & 0x20) >> 5;
    pSdCsd->DSRImpl             = (ucCsdTab[6] & 0x10) >> 4;
    pSdCsd->Reserved2           = 0;
    pSdCsd->DeviceSize          = (ucCsdTab[6] & 0x03) << 10;
    pSdCsd->DeviceSize         |= (ucCsdTab[7]) << 2;
    pSdCsd->DeviceSize         |= (ucCsdTab[8] & 0xC0) >> 6;
    pSdCsd->MaxRdCurrentVDDMin  = (ucCsdTab[8] & 0x38) >> 3;
    pSdCsd->MaxRdCurrentVDDMax  = (ucCsdTab[8] & 0x07);
    pSdCsd->MaxWrCurrentVDDMin  = (ucCsdTab[9] & 0xE0) >> 5;
    pSdCsd->MaxWrCurrentVDDMax  = (ucCsdTab[9] & 0x1C) >> 2;
    pSdCsd->DeviceSizeMul       = (ucCsdTab[9] & 0x03) << 1;
    pSdCsd->DeviceSizeMul      |= (ucCsdTab[10] & 0x80) >> 7;
    pSdCsd->EraseGrSize         = (ucCsdTab[10] & 0x40) >> 6;
    pSdCsd->EraseGrMul          = (ucCsdTab[10] & 0x3F) << 1;
    pSdCsd->EraseGrMul         |= (ucCsdTab[11] & 0x80) >> 7;
    pSdCsd->WrProtectGrSize     = (ucCsdTab[11] & 0x7F);
    pSdCsd->WrProtectGrEnable   = (ucCsdTab[12] & 0x80) >> 7;
    pSdCsd->ManDeflECC          = (ucCsdTab[12] & 0x60) >> 5;
    pSdCsd->WrSpeedFact         = (ucCsdTab[12] & 0x1C) >> 2;
    pSdCsd->MaxWrBlockLen       = (ucCsdTab[12] & 0x03) << 2;
    pSdCsd->MaxWrBlockLen      |= (ucCsdTab[13] & 0xC0) >> 6;
    pSdCsd->WriteBlockPaPartial = (ucCsdTab[13] & 0x20) >> 5;
    pSdCsd->Reserved3           = 0;
    pSdCsd->ContentProtectAppli = (ucCsdTab[13] & 0x01);
    pSdCsd->FileFormatGrouop    = (ucCsdTab[14] & 0x80) >> 7;
    pSdCsd->CopyFlag            = (ucCsdTab[14] & 0x40) >> 6;
    pSdCsd->PermWrProtect       = (ucCsdTab[14] & 0x20) >> 5;
    pSdCsd->TempWrProtect       = (ucCsdTab[14] & 0x10) >> 4;
    pSdCsd->FileFormat          = (ucCsdTab[14] & 0x0C) >> 2;
    pSdCsd->ECC                 = (ucCsdTab[14] & 0x03);
    pSdCsd->CSD_CRC             = (ucCsdTab[15] & 0xFE) >> 1;
    pSdCsd->Reserved4           = 1;
    return ucError;
}
#endif

/* ******************************************************************** */
/*                         SDGetCIDRegister()                           */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT08U SDGetCIDRegister (SD_CID_STR *pSdCid)
{   INT08U ucError = SD_RESPONSE_FAILURE;
    INT08U ucCidTab[16];
    SPI3_CS_LOW();
    SDSendCmd(SD_CMD_SEND_CID, 0, 0xFF);
    if (SDGetResponse(SD_RESPONSE_NO_ERROR) == 0)
    {   if (SDGetResponse(SD_START_SINGLE_BL_READ) == 0)
        {   ucCidTab[0]  = SDReadByte();
            ucCidTab[1]  = SDReadByte();
            ucCidTab[2]  = SDReadByte();
            ucCidTab[3]  = SDReadByte();
            ucCidTab[4]  = SDReadByte();
            ucCidTab[5]  = SDReadByte();
            ucCidTab[6]  = SDReadByte();
            ucCidTab[7]  = SDReadByte();
            ucCidTab[8]  = SDReadByte();
            ucCidTab[9]  = SDReadByte();
            ucCidTab[10] = SDReadByte();
            ucCidTab[11] = SDReadByte();
            ucCidTab[12] = SDReadByte();
            ucCidTab[13] = SDReadByte();
            ucCidTab[14] = SDReadByte();
            ucCidTab[15] = SDReadByte();
        }
        SDWriteByte(SD_DUMMY_BYTE);
        SDWriteByte(SD_DUMMY_BYTE);
        ucError = SD_RESPONSE_NO_ERROR;
    }
    SPI3_CS_HIGH();
    SDWriteByte(SD_DUMMY_BYTE);
    pSdCid->ManufacturerID =  ucCidTab[0];
    pSdCid->OEM_AppliID    =  ucCidTab[1] << 8;
    pSdCid->OEM_AppliID   |=  ucCidTab[2];
    pSdCid->ProdName1      =  ucCidTab[3] << 24;
    pSdCid->ProdName1     |=  ucCidTab[4] << 16;
    pSdCid->ProdName1     |=  ucCidTab[5] << 8;
    pSdCid->ProdName1     |=  ucCidTab[6];
    pSdCid->ProdName2      =  ucCidTab[7];
    pSdCid->ProdRev        =  ucCidTab[8];
    pSdCid->ProdSN         =  ucCidTab[9] << 24;
    pSdCid->ProdSN        |=  ucCidTab[10] << 16;
    pSdCid->ProdSN        |=  ucCidTab[11] << 8;
    pSdCid->ProdSN        |=  ucCidTab[12];
    pSdCid->Reserved1     |= (ucCidTab[13] & 0xF0) >> 4;
    pSdCid->ManufactDate   = (ucCidTab[13] & 0x0F) << 8;
    pSdCid->ManufactDate  |=  ucCidTab[14];
    pSdCid->CID_CRC        = (ucCidTab[15] & 0xFE) >> 1;
    pSdCid->Reserved2      =  1;
    return ucError;
}
#endif

/* ******************************************************************** */
/*                         SDGetDataResponse()                          */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT08U SDGetDataResponse (void)
{   INT32U uiCnt;
    INT08U ucResp;
    uiCnt = 64;
    while (uiCnt--)
    {   ucResp = SDReadByte() & 0x1F;
        if (ucResp == SD_DATA_OK)
        {   break;
        }
        else if (ucResp == SD_DATA_CRC_ERROR)
        {   return SD_DATA_CRC_ERROR;
        }
        else if (ucResp == SD_DATA_WRITE_ERROR)
        {   return SD_DATA_WRITE_ERROR;
        }
    }
    while (SDReadByte() == 0);
    return ucResp;
}
#endif

/* ******************************************************************** */
/*                             SDGetStatus()                            */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT16U SDGetStatus (void)
{   INT16U usStatus;
    SPI3_CS_LOW();
    SDSendCmd(SD_CMD_SEND_STATUS, 0, 0xFF);
    usStatus  =  SDReadByte();
    usStatus |= (INT16U)(SDReadByte() << 8);
    SPI3_CS_HIGH();
    SDWriteByte(SD_DUMMY_BYTE);
    return usStatus;
}
#endif

/* ******************************************************************** */
/*                            SDGoIdleState()                           */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT08U SDGoIdleState(void)
{   SPI3_CS_LOW();
    SDSendCmd(SD_CMD_GO_IDLE_STATE, 0, 0x95);
    if (SDGetResponse(SD_IN_IDLE_STATE) != SD_RESPONSE_NO_ERROR)
    {   return SD_RESPONSE_FAILURE;
    }
    do
    {   SPI3_CS_HIGH();
        SDWriteByte(SD_DUMMY_BYTE);
        SPI3_CS_LOW();
        SDSendCmd(SD_CMD_SEND_OP_COND, 0, 0xFF);
    }
    while (SDGetResponse(SD_RESPONSE_NO_ERROR) != 0);
    SPI3_CS_HIGH();
    SDWriteByte(SD_DUMMY_BYTE);
    return SD_RESPONSE_NO_ERROR;
}
#endif

/* ******************************************************************** */
/*                            SDGetResponse()                           */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT08U SDGetResponse (INT08U ucResp)
{   INT32U uiCnt = 0x0FFF;
    while (uiCnt--)
    {   if (SDReadByte() == ucResp)
        {   break;
        }
    }
    if (uiCnt == 0)
    {   return SD_RESPONSE_FAILURE;
    }
    return SD_RESPONSE_NO_ERROR;
}
#endif

/* ******************************************************************** */
/*                             SDSendCmd()                              */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
void SDSendCmd (INT08U ucCmd, INT32U uiArg, INT08U ucCrc)
{   SDWriteByte(ucCmd | 0x40);
    SDWriteByte((INT08U)(uiArg >> 24));
    SDWriteByte((INT08U)(uiArg >> 16));
    SDWriteByte((INT08U)(uiArg >> 8));
    SDWriteByte((INT08U)(uiArg));
    SDWriteByte(ucCrc);
}
#endif








/* ******************************************************************** */
/*                            SPI3HardInit()                            */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
void SPI3HardInit (void)
{   INT16U usTemp;
    RCC->APB2ENR |= RCC_APB2ENR_SPI3EN;
//    XIOConfigREMAP(SPI3_AFIO_REMAP1, SPI3_AFIO_REMAP2);
//    RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO, (FunctionalState)ENABLE);
//    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, (FunctionalState)ENABLE);
    
    XIOConfigGPIO(SPI3_PT_CS,  SPI3_BT_CS,  XIO_PT_GPO_PP_50M, XIO_PT_SET_1);
    XIOConfigGPIO(SPI3_PT_SCK, SPI3_BT_SCK, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
    XIOConfigGPIO(SPI3_PT_IN,  SPI3_BT_IN,  XIO_PT_GPI_PULL,   XIO_PT_SET_1);
    XIOConfigGPIO(SPI3_PT_OUT, SPI3_BT_OUT, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
    XIOConfigGPIO(SPI3_PT_CD,  SPI3_BT_CD,  XIO_PT_GPI_PULL,   XIO_PT_SET_1);
    usTemp  =  SPI3->CR1;
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
    SPI3->CR1 = usTemp;
    usTemp  =  SPI3->I2SCFGR;
    usTemp &= ~SPI_I2SCFGR_CHLEN   /* 0: 16-bit wide (Channel length)   */
           &  ~SPI_I2SCFGR_DATLEN  /* 00: 16-bit, 01: 24-bit, 10: 32-b  */
           &  ~SPI_I2SCFGR_CKPOL   /* 0: I2S clock steady state is low  */
           &  ~SPI_I2SCFGR_I2SSTD  /* 00: I2S Philips standard          */
           &  ~SPI_I2SCFGR_PCMSYNC /* 0: Short frame synchronization    */
           &  ~SPI_I2SCFGR_I2SCFG  /* 00: S-tx, 01:S-rx,10:M-tx,11:M-rx */
           &  ~SPI_I2SCFGR_I2SE    /* 0: I2S peripheral is disabled     */
           &  ~SPI_I2SCFGR_I2SMOD; /* 0: SPI mode is selected           */
    SPI3->I2SCFGR = usTemp;
    SPI3->CRCPR = 0x0007;          /* SPI CRC polynomial (not for i2s)  */
    SPI3->CR1 |= SPI_CR1_SPE;      /* 1: SPI Enable                     */
}
#endif

/* ******************************************************************** */
/*                            SPI3Read08u()                            */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT08U SPI3Read08u (void)
{   while (SPI3GetFlags(SPI3_I2S_FLAG_TXE) == 0);
    SPI3->DR = SD_DUMMY_BYTE;
    while (SPI3GetFlags(SPI3_I2S_FLAG_RXNE) == 0);
    return (INT08U)(SPI3->DR);
}
#endif

/* ******************************************************************** */
/*                            SPI3Write08u()                           */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT08U SPI3Write08u (INT08U ucData)
{   while (SPI3GetFlags(SPI3_I2S_FLAG_TXE) == 0);
    SPI3->DR = ucData;
    while (SPI3GetFlags(SPI3_I2S_FLAG_RXNE) == 0);
    return (INT08U)(SPI3->DR);
}
#endif

/* ******************************************************************** */
/*                          SPI3Exchange08u()                           */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT08U SPI3Exchange08u (INT08U ucData)
{   while (SPI3GetFlags(SPI3_I2S_FLAG_TXE) == 0);
    SPI3->DR = ucData;
    while (SPI3GetFlags(SPI3_I2S_FLAG_RXNE) == 0);
    return (INT08U)(SPI3->DR);
}
#endif

/* ******************************************************************** */
/*                            SPI3Read16u()                            */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT16U SPI3Read16u (void)
{   while (SPI3GetFlags(SPI3_I2S_FLAG_TXE) == 0);
    SPI3->DR = (INT16U)0xFFFF;
    while (SPI3GetFlags(SPI3_I2S_FLAG_RXNE) == 0);
    return (INT16U)(SPI3->DR);
}
#endif

/* ******************************************************************** */
/*                            SPI3Write16u()                           */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT16U SPI3Write16u (INT16U usData)
{   while (SPI3GetFlags(SPI3_I2S_FLAG_TXE) == 0);
    SPI3->DR = usData;
    while (SPI3GetFlags(SPI3_I2S_FLAG_RXNE) == 0);
    return (INT16U)(SPI3->DR);
}
#endif

/* ******************************************************************** */
/*                          SPI3Exchange16u()                           */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT16U SPI3Exchange16u (INT16U usData)
{   while (SPI3GetFlags(SPI3_I2S_FLAG_TXE) == 0);
    SPI3->DR = usData;
    while (SPI3GetFlags(SPI3_I2S_FLAG_RXNE) == 0);
    return (INT16U)(SPI3->DR);
}
#endif

/* ******************************************************************** */
/*                          SPI3SendHardCrc()                           */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
void SPI3SendHardCrc (void)
{   SPI3->CR1 |= 0x1000;
}
#endif

/* ******************************************************************** */
/*                          SPI3GetHardCrc08u()                         */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT08U SPI3GetHardCrc08u (INT08U ucTxOrRx)
{   if (ucTxOrRx != 0)
    {   return (INT08U)(SPI3->TXCRCR);
    }   else
    {   return (INT08U)(SPI3->RXCRCR);
    }
}
#endif

/* ******************************************************************** */
/*                          SPI3GetHardCrc16u()                         */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT16U SPI3GetHardCrc16u (INT08U ucTxOrRx)
{   if (ucTxOrRx != 0)
    {   return SPI3->TXCRCR;
    }   else
    {   return SPI3->RXCRCR;
    }
}
#endif

/* ******************************************************************** */
/*                           SPI3GetFlags()                             */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
INT16U SPI3GetFlags (INT16U usFlgMsk)
{   return (SPI3->SR & usFlgMsk);
}
#endif

/* ******************************************************************** */
/*                           SPI3ClrFlags()                             */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
void SPI3ClrFlags (INT16U usFlgMsk)
{   SPI3->SR &= ~usFlgMsk;
}
#endif

/* ******************************************************************** */
/*                           SPI3ConfigI2S()                            */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
void SPI3ConfigI2S (INT08U ucNewState)
{   if (ucNewState != DISABLE)
    {   SPI3->I2SCFGR |= 0x0400;
    }   else
    {   SPI3->I2SCFGR &= 0xFBFF;
    }
}
#endif

/* ******************************************************************** */
/*                            SPI3ConfigIT()                            */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
void SPI3ConfigIT (INT16U usIntMsk, INT08U ucNewState)
{   if (ucNewState != DISABLE)
    {   SPI3->CR2 |=  usIntMsk;
    }   else
    {   SPI3->CR2 &= ~usIntMsk;
    }
}
#endif

/* ******************************************************************** */
/*                            SPI3ConfigDMA()                           */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
void SPI3ConfigDMA (INT16U usDmaMsk, INT08U ucNewState)
{   if (ucNewState != DISABLE)
    {   SPI3->CR2 |=  usDmaMsk;
    }   else
    {   SPI3->CR2 &= ~usDmaMsk;
    }
}
#endif

/* ******************************************************************** */
/*                         SPI3ConfigHardCrc()                          */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
void SPI3ConfigHardCrc (INT08U ucNewState)
{   if (ucNewState != DISABLE)
    {   SPI3->CR1 |= 0x2000;
    }   else
    {   SPI3->CR1 &= 0xDFFF;
    }
}
#endif

/* ******************************************************************** */
/*                          SPI3SetDataSize16b()                        */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
void SPI3SetDataSize16b (void)
{   if((SPI3->CR1 &   SPI_CR1_SPE) != 0)
    {   SPI3->CR1 &= ~SPI_CR1_SPE;
        SPI3->CR1 |=  SPI_CR1_DFF;
        SPI3->CR1 |=  SPI_CR1_SPE;
    }   else
    {   SPI3->CR1 |=  SPI_CR1_DFF;
    }
}
#endif

/* ******************************************************************** */
/*                          SPI3SetDataSize08b()                        */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
void SPI3SetDataSize08b (void)
{   if((SPI3->CR1 &   SPI_CR1_SPE) != 0)
    {   SPI3->CR1 &= ~SPI_CR1_SPE;
        SPI3->CR1 &= ~SPI_CR1_DFF;
        SPI3->CR1 |=  SPI_CR1_SPE;
    }   else
    {   SPI3->CR1 &= ~SPI_CR1_DFF;
    }
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */