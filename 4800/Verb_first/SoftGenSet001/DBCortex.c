/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File DBCortex.c                         */
/*                            By: Wu Xuekui                             */
/*                             2014-10-14                               */
/* ******************************************************************** */

#define   DB_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                               DBInit()                               */
/* ******************************************************************** */
void DBInit (void)
{   usDBTimer = 0;
    usDBStatus = 0;
    (void)DBCmdBufInit();
    (void)DBInitDFlash();
    (void)DBEepReadParam(&aDBParam[0], DB_PARAM_ADDR, DB_PARAM_SIZE);
   #if (DB_CURVE_SIZE > 10)
    (void)DBEepReadParam(&aDBCurve[0], DB_CURVE_ADDR, DB_CURVE_SIZE);
   #endif
    if (DBCheckParam() == DB_FALSE)
    {   (void)DBResetParam();
    }
    (void)DBEepInitHstryBlock();
    if (DBCheckHstry() == DB_FALSE)
    {   (void)DBResetHstry();
    }
    (void)DBResetMeasu();
}

/* ******************************************************************** */
/*                               DBStart()                              */
/* ******************************************************************** */
void DBStart (void)
{   
}

/* ******************************************************************** */
/*                               DBTaskLoop()                           */
/* ******************************************************************** */
void DBTaskLoop (void)
{   INT08U ucComd, ucErr;
    while (1)
    {
      ucComd = DBTskGetCmd (DB_CMD_TO_TICKS, &ucErr);
        if (ucErr == DB_NO_ERR)
        {   /* ********************* Save History ********************* */
            if (ucComd == DB_CMD_SAVE_HSTRY)
            { //  (void)SFCopy16u(&usDBmErrorStatus1,&usDBhErrorStatus1,6);
                (void)DBEepWriteRecord(&sDBHstryBlck, &aDBHstry[0]);
            }
            /* ******************** Save Parameters ******************* */
            else if (ucComd == DB_CMD_SAVE_PARAM)
            {   (void)DBFlashErasePage(DB_PARAM_ADDR);
                (void)DBEepWriteParam(&aDBParam[0],
                                      DB_PARAM_ADDR, DB_PARAM_SIZE);
            }
            /* ******************** Save Parameters ******************* */
           #if (DB_CURVE_SIZE > 10)
            else if (ucComd == DB_CMD_SAVE_CURVE)
            {   (void)DBFlashErasePage(DB_CURVE_ADDR);
                (void)DBEepWriteParam(&aDBCurve[0],
                                      DB_CURVE_ADDR, DB_CURVE_SIZE);
            }
           #endif
        }
    }
}

/* ******************************************************************** */
/*                            DBCheckParam()                            */
/* ******************************************************************** */
INT08U DBCheckParam (void)
{
    if((usDBpAmpMainVoltA < 2) || (usDBpAmpMainVoltA > (INT16U)50000))
    {   return DB_FALSE;
    }
    if((usDBpAmpMainVoltB < 2) || (usDBpAmpMainVoltB > (INT16U)50000))
    {   return DB_FALSE;
    }
    if((usDBpAmpMainVoltC < 2) || (usDBpAmpMainVoltC > (INT16U)50000))
    {   return DB_FALSE;
    }
    if((usDBpTeethCrank1 < 2) || (usDBpTeethCrank1 > 500))
    {   return DB_FALSE;
    }
    if((usDBpSpeedFilter1 < 1) || (usDBpSpeedFilter1 > 2000))
    {   return DB_FALSE;
    }
    if((usDBpTeethCrank2 < 2) || (usDBpTeethCrank2 > 500))
    {   return DB_FALSE;
    }
    if((usDBpSpeedFilter2 < 1) || (usDBpSpeedFilter2 > 2000))
    {   return DB_FALSE;
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                            DBResetParam()                            */
/* ******************************************************************** */
void DBResetParam (void)
{   usDBpGensCtRatio           = 1;
    usDBpAmpMainVoltA          = 1024;
    usDBpAmpMainVoltB          = 1024;
    usDBpAmpMainVoltC          = 1024;
    usDBpAmpMainVoltAB         = 1024;
    usDBpAmpMainVoltBC         = 1024;
    usDBpAmpMainVoltCA         = 1024;
    usDBpAmpGensVoltA          = 1024;
    usDBpAmpGensVoltB          = 1024;
    usDBpAmpGensVoltC          = 1024;
    usDBpAmpGensVoltAB         = 1024;
    usDBpAmpGensVoltBC         = 1024;
    usDBpAmpGensVoltCA         = 1024;
    usDBpAmpGensCurrA          = 1024;
    usDBpAmpGensCurrB          = 1024;
    usDBpAmpGensCurrC          = 1024;
    usDBpAdcChFilter0          = 16;
    usDBpAdcChFilter1          = 16;
    usDBpAdcChFilter2          = 16;
    usDBpAdcChFilter3          = 16;
    usDBpAdcChFilter4          = 16;
    usDBpAdcChFilter5          = 16;
    usDBpAdcChFilter6          = 16;
    usDBpAdcChFilter7          = 16;
    usDBpAdcChFilter8          = 16;
    usDBpAdcChRef0             = 2047;
    usDBpAdcChRef1             = 2047;
    usDBpAdcChRef2             = 2047;
    usDBpAdcChRef3             = 2047;
    usDBpAdcChRef4             = 2047;
    usDBpAdcChRef5             = 2047;
    usDBpAdcChRef6             = 2047;
    usDBpAdcChRef7             = 2047;
    usDBpAdcChRef8             = 2047;
    usDBpAdcChRef9             = 2047;
    usDBpAdcChRef10            = 2047;
    usDBpAdcChRef11            = 2047;
    usDBpAdcChRef12            = 2047;
    usDBpAdcChRef13            = 2047;
    usDBpAdcChRef14            = 2047;
    usDBpAdcChRef15            = 2047;
    usDBpAdcRefAutoOrFixed     = 1;
    
    usDBpVoltDifferMax         = 100;
    usDBpFreqDifferMax         = 100;
    usDBpPhaseDifferMax        = 100;
    usDBpSpeedTuneGain         = 0;
    usDBpSpeedTuneStability    = 0;
    usDBpSpeedTuneDerivative   = 0;
    ssDBpSpeedTuneCtrlInit     = 0;
    usDBpAvrTuneGain           = 0;
    usDBpAvrTuneStability      = 0;
    usDBpAvrTuneDerivative     = 0;
    ssDBpAvrTuneCtrlInit       = 0;
    
    usDBpTeethCrank1           = 100;
    usDBpTeethCrank2           = 100;
    usDBpSpeedFilter1          = 100;
    usDBpSpeedFilter2          = 100;
    usDBpStartSpeed1           = 40;
    usDBpStartSpeed2           = 400;
    usDBpSpeedIdle             = 600;
    usDBpSpeedIdleMin          = 550;
    usDBpSpeedIdleMax          = 650;
    usDBpSpeedRated            = 1500;
    usDBpSpeedRatedMin         = 1450;
    usDBpSpeedOverToWarn       = 1650;
    usDBpSpeedOverToStop       = 1700;
    usDBpSpeedOverStopDly      = 10;
    usDBpDroop                 = 0;
    usDBpDroopRefLow           = 100;
    usDBpDroopRefHigh          = 1000;
    usDBpDroopSpeedRef         = 1500;
    usDBpSpeedRampUp           = 100;
    usDBpSpeedRampDown         = 100;
    usDBpSpeedRampUp2          = 100;
    usDBpSpeedRampDown2        = 100;
    usDBpSpeedSwitchToRamp2    = 1000;
    usDBpSpeedRampDigitPot     = 100;
    
    usDBpStoppedToStartingDly  = 100;
    usDBpIdlingToRampUpDly     = 100;
    usDBpRatedToSynchringDly   = 100;
    usDBpWorkingToSwitchOffDly = 100;
    usDBpRatedToRampDowmDly    = 100;
    usDBpIdlingToStoppingDly   = 100;
    usDBpMainBreakerOnDly      = 100;
    usDBpGensBreakerOnDly      = 100;
    usDBpRampUpTimeMax         = 100;
    usDBpRampDownTimeMax       = 100;
    usDBpSynchronTimeMax       = 100;
    usDBpAirHeatTempCold       = 100;
    usDBpAirHeatTempWarm       = 100;
    usDBpAirHeatTimeAtCold     = 100;
    usDBpAirHeatTimeAtWarm     = 100;
    usDBpOilPumpOnTimeMax      = 100;
    usDBpOilPressMinAtStart    = 100;
    usDBpFanRefAssign          = 100;
    usDBpFanActiveTemp         = 100;
    usDBpFanActiveDly          = 100;
    usDBpStarterOnDly          = 100;
    usDBpStarterOffDly         = 100;
    usDBpStartFailMax          = 3;
    usDBpOperationMode         = 0;
    usDBpStatisticsTime        = 3000;
    
    usDBpModBusBaudrate        = 9600;
    usDBpModBusMyAddress       = 1;
    usDBpCan1Baudrate          = 250;
    usDBpCan1MyAddress         = 1;
    usDBpCan2Baudrate          = 250;
    usDBpCan2MyAddress         = 1;
    usDBpCan3Baudrate          = 250;
    usDBpCan3MyAddress         = 1;
    
    usDBpCoolantTempToWarn     = 0;
    usDBpCoolantTempToStop     = 0;
    usDBpCoolantTempStopDly    = 0;
    usDBpBoostTempToWarn       = 0;
    usDBpBoostTempToStop       = 0;
    usDBpBoostTempStopDly      = 0;
    usDBpOilTempToWarn         = 0;
    usDBpOilTempToStop         = 0;
    usDBpOilTempStopDly        = 0;
    usDBpInternTempToWarn      = 0;
    
    usDBpOilPressStartDly      = 0;
    usDBpOilPressWarnDly       = 0;
    usDBpOilPressStopDly       = 0;
    usDBpFuelLevelToWarn       = 0;
    usDBpFuelLevelWarnDly      = 0;
    usDBpFuelLevelToStop       = 0;
    usDBpFuelLevelStopDly      = 0;
    usDBpCoolantLevelToWarn    = 0;
    usDBpCoolantLevelWarnDly   = 0;
    usDBpCoolantLevelToStop    = 0;
    usDBpCoolantLevelStopDly   = 0;
    usDBpSupplyVoltWarnLow     = 0;
    usDBpSupplyVoltWarnHigh    = 0;
    usDBpSupplyVoltWarnDly     = 0;
    usDBpChargerVoltWarnLow    = 0;
    usDBpChargerVoltWarnHigh   = 0;
    usDBpChargerVoltWarnDly    = 0;
    usDBpChargerCurrToWarn     = 0;
    usDBpChargerCurrWarnDly    = 0;
    usDBpRackPositionToWarn    = 0;
    usDBpRackPositionWarnDly   = 0;
    usDBpAirFilterWarnDly      = 0;
    usDBpMainLnVoltErrLow      = 0;
    usDBpMainLnVoltErrHigh     = 0;
    usDBpMainLlVoltErrLow      = 0;
    usDBpMainLlVoltErrHigh     = 0;
    usDBpMainPhaseErrLow       = 0;
    usDBpMainPhaseErrHigh      = 0;
    usDBpMainFreqErrLow        = 0;
    usDBpMainFreqErrHigh       = 0;
    usDBpMainVoltErrorDly      = 0;
    usDBpMainVoltNormalDly     = 0;
    usDBpGensLnVoltErrLow      = 0;
    usDBpGensLnVoltErrHigh     = 0;
    usDBpGensLlVoltErrLow      = 0;
    usDBpGensLlVoltErrHigh     = 0;
    usDBpGensPhaseErrLow       = 0;
    usDBpGensPhaseErrHigh      = 0;
    usDBpGensFreqErrLow        = 0;
    usDBpGensFreqErrHigh       = 0;
    usDBpGensVoltErrorDly      = 0;
    usDBpGensVoltNormalDly     = 0;
    usDBpGensCurrErrHigh       = 0;
    usDBpGensCurrGdErrHigh    = 0;
    usDBpGensCurrErrorDly      = 0;
    usDBpGensCurrNormalDly     = 0;
    usDBpActPowerErrHigh       = 0;
    usDBpReactPowerErrHigh     = 0;
    usDBpAppPowerErrHigh       = 0;
    usDBpPowerFactorErrHigh    = 0;
    usDBpPowerFactorErrLow     = 0;
    usDBpGensPowerErrorDly     = 0;
    usDBpGensPowerNormalDly    = 0;
    
}

/* ******************************************************************** */
/*                            DBCheckHstry()                            */
/* ******************************************************************** */
INT08U DBCheckHstry (void)
{
    return DB_TRUE;
}

/* ******************************************************************** */
/*                            DBResetHstry()                            */
/* ******************************************************************** */
void DBResetHstry (void)
{   (void)SFFill16u(&aDBHstry[0],0,DB_HSTRY_SIZE);
}

/* ******************************************************************** */
/*                            DBResetMeasu()                            */
/* ******************************************************************** */
void DBResetMeasu (void)
{   (void)SFFill16u(&aDBMeasu[0],0,DB_MEASU_NOR_SIZE);
}

/* ******************************************************************** */
/*                            DBEepReadParam()                          */
/* ******************************************************************** */
INT08U DBEepReadParam (INT16U *pData, INT32U uiAddr, INT16U usSize)
{   INT16U usChck, usData;
    usChck = 0;
    while (usSize--)
    {   usData  = DBFlashRead16u(uiAddr);
        *pData  = usData;
        usChck += usData;
        uiAddr += 2;
        pData++;
    }
    if (usChck != DBFlashRead16u(uiAddr))
    {   return DB_FALSE;
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                            DBEepWriteParam()                         */
/* ******************************************************************** */
INT08U DBEepWriteParam (INT16U *pData, INT32U uiAddr, INT16U usSize)
{   INT16U usChck, usData;
    usChck = 0;
    while (usSize--)
    {   usData  = *pData++;
        if (DBFlashWrite16u(uiAddr,usData) != DB_FLASH_STS_COMPLETE)
        {   return DB_FALSE;
        }
        usChck += usData;
        uiAddr += 2;
    }
    if (DBFlashWrite16u(uiAddr,usChck) != DB_FLASH_STS_COMPLETE)
    {   return DB_FALSE;
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                         DBEepInitHstryBlock()                        */
/* ******************************************************************** */
void DBEepInitHstryBlock (void)
{   INT32U uiAddrErase;
    DB_EEP_BLOCK *pBlck;
    pBlck              = &sDBHstryBlck;
    pBlck->uiStatus    = DB_BLOCK_STS_FAULT;
    pBlck->uiHead      = DB_HSTRY_RECORD_HEAD;
    pBlck->uiPageMask  = DB_FLASH_PAGE_MSK;
    pBlck->uiPageSiz8  = DB_FLASH_PAGE_SIZ;
    pBlck->uiRcrdSiz8  = DB_HSTRY_RECORD_SIZE;
    pBlck->uiDatSiz16  = DB_HSTRY_SIZE16;
    pBlck->uiAddrMin   = DB_HSTRY_ADDR;
    pBlck->uiAddrMax   = DB_HSTRY_ADDR+DB_FLASH_PAGE_SIZ*DB_HSTRY_PAGE_NUM;
    pBlck->uiAddrCurr  = pBlck->uiAddrMin;
    pBlck->uiAddrNext  = pBlck->uiAddrMin;
    pBlck->uiCPageAMax = pBlck->uiAddrMin+pBlck->uiPageSiz8-pBlck->uiRcrdSiz8;
    pBlck->uiNPageAMin = pBlck->uiAddrMin+pBlck->uiPageSiz8;
    (void)DBEepCheckRecord(pBlck);
    if (pBlck->uiStatus == DB_BLOCK_STS_WRITED)
    {   (void)DBEepReadRecord(pBlck, &aDBHstry[0]);
    }
    else if (pBlck->uiStatus == DB_BLOCK_STS_ERASED)
    {   (void)DBResetHstry();
        (void)DBEepWriteRecord(pBlck, &aDBHstry[0]);
    }
    else if (pBlck->uiStatus == DB_BLOCK_STS_FAULT)
    {   for (uiAddrErase  = pBlck->uiAddrMin;
             uiAddrErase  < pBlck->uiAddrMax;
             uiAddrErase += pBlck->uiPageSiz8)
        {   (void)DBFlashErasePage(uiAddrErase);
        }
        (void)DBResetHstry();
        (void)DBEepWriteRecord(pBlck, &aDBHstry[0]);
    }
}

/* ******************************************************************** */
/*                         DBEepCheckRecord()                           */
/* ******************************************************************** */
void DBEepCheckRecord (DB_EEP_BLOCK *pBlck)
{   INT32U uiNext, uiAOut, uiHead, uiPage;
    uiAOut = pBlck->uiAddrMax;
    for (uiPage  = pBlck->uiAddrMin;
         uiPage  < uiAOut;
         uiPage += pBlck->uiPageSiz8)
    {   uiHead   = DBFlashRead32u(uiPage);
        if (uiHead != 0xFFFFFFFF)
        {   break;
        }
    }
    if (uiHead == pBlck->uiHead)
    {   pBlck->uiCPageAMax = uiPage + pBlck->uiPageSiz8 - pBlck->uiRcrdSiz8;
        pBlck->uiNPageAMin = uiPage + pBlck->uiPageSiz8;
        if (pBlck->uiNPageAMin >= pBlck->uiAddrMax)
        {   pBlck->uiNPageAMin  = pBlck->uiAddrMin;
        }
        uiAOut = uiPage + pBlck->uiPageSiz8;
        for (uiNext  = uiPage + pBlck->uiRcrdSiz8;
             uiNext  < uiAOut;
             uiNext += pBlck->uiRcrdSiz8)
        {   if (DBFlashRead32u(uiNext) != pBlck->uiHead)
            {   break;
            }
        }
        pBlck->uiAddrNext  = uiNext;
        pBlck->uiAddrCurr  = uiNext - pBlck->uiRcrdSiz8;
        pBlck->uiStatus    = DB_BLOCK_STS_WRITED;
    }
    else if (uiHead == 0xFFFFFFFF)
    {   pBlck->uiCPageAMax = pBlck->uiAddrMin+pBlck->uiPageSiz8-pBlck->uiRcrdSiz8;
        pBlck->uiNPageAMin = pBlck->uiAddrMin+pBlck->uiPageSiz8;
        pBlck->uiAddrNext  = pBlck->uiAddrMin;
        pBlck->uiAddrCurr  = pBlck->uiAddrMin;
        pBlck->uiStatus    = DB_BLOCK_STS_ERASED;
    }
    else
    {   pBlck->uiCPageAMax = pBlck->uiAddrMin+pBlck->uiPageSiz8-pBlck->uiRcrdSiz8;
        pBlck->uiNPageAMin = pBlck->uiAddrMin+pBlck->uiPageSiz8;
        pBlck->uiAddrNext  = pBlck->uiAddrMin;
        pBlck->uiAddrCurr  = pBlck->uiAddrMin;
        pBlck->uiStatus    = DB_BLOCK_STS_FAULT;
    }
}

/* ******************************************************************** */
/*                         DBEepReadRecord()                            */
/* ******************************************************************** */
INT08U DBEepReadRecord (DB_EEP_BLOCK *pBlck, INT16U *pData)
{   INT32U uiHead;
    uiHead = DBFlashRead32u(pBlck->uiAddrCurr);
    if (uiHead != pBlck->uiHead)
    {   return DB_FALSE;
    }
    (void)DBFlashRead16p(pBlck->uiAddrCurr+4, pData, pBlck->uiDatSiz16);
    return DB_TRUE;
}

/* ******************************************************************** */
/*                         DBEepWriteRecord()                           */
/* ******************************************************************** */
void DBEepWriteRecord (DB_EEP_BLOCK *pBlck, INT16U *pData)
{   INT32U uiAddrErase;
    uiAddrErase = pBlck->uiAddrCurr & pBlck->uiPageMask;
    if (pBlck->uiAddrNext  <= pBlck->uiCPageAMax)
    {  (void)DBFlashWrite16p(pBlck->uiAddrNext+4, pData, pBlck->uiDatSiz16);
       (void)DBFlashWrite32u(pBlck->uiAddrNext, pBlck->uiHead);
        pBlck->uiAddrCurr   = pBlck->uiAddrNext;
        pBlck->uiAddrNext  += pBlck->uiRcrdSiz8;
    }   else
    {   pBlck->uiAddrNext   = pBlck->uiNPageAMin;
       (void)DBFlashWrite16p(pBlck->uiAddrNext+4, pData, pBlck->uiDatSiz16);
       (void)DBFlashWrite32u(pBlck->uiAddrNext, pBlck->uiHead);
        pBlck->uiAddrCurr   = pBlck->uiAddrNext;
        pBlck->uiCPageAMax  = pBlck->uiAddrNext+pBlck->uiPageSiz8-pBlck->uiRcrdSiz8;
        pBlck->uiAddrNext  += pBlck->uiRcrdSiz8;
        pBlck->uiNPageAMin += pBlck->uiPageSiz8;
        if (pBlck->uiNPageAMin >= pBlck->uiAddrMax)
        {   pBlck->uiNPageAMin  = pBlck->uiAddrMin;
        }
       (void)DBFlashErasePage(uiAddrErase);
    }
}

/* ******************************************************************** */
/*                           DBInitDFlash()                             */
/* ******************************************************************** */
void DBInitDFlash (void)
{ /*  INT32U uiTmp;
    uiTmp        =  FLASH->ACR;
    uiTmp       &= ~FLASH_ACR_LATENCY;
    uiTmp       |=  FLASH_ACR_LATENCY_1;
    FLASH->ACR   =  uiTmp; */
    FLASH->KEYR  =  DB_FLASH_KEY1;
    FLASH->KEYR  =  DB_FLASH_KEY2;
   #if (DB_CPU_STM32F10_XL_ON == 1)
    FLASH->KEYR2 =  DB_FLASH_KEY1;
    FLASH->KEYR2 =  DB_FLASH_KEY2;
   #endif
}

/* ******************************************************************** */
/*                           DBGetBank1Status()                         */
/* ******************************************************************** */
INT32U DBGetBank1Status (void)
{   INT32U uiStatus;
    uiStatus = FLASH->SR;
    if ((uiStatus & FLASH_SR_BSY) != 0)
    {   return DB_FLASH_STS_BUSY;
    }
    else if ((uiStatus & FLASH_SR_PGERR) != 0)
    {   return DB_FLASH_STS_ERR_PG;
    }
    else if ((uiStatus & FLASH_SR_WRPRTERR) != 0 )
    {   return DB_FLASH_STS_ERR_WRP;
    }
    return DB_FLASH_STS_COMPLETE;
}

/* ******************************************************************** */
/*                           DBGetBank2Status()                         */
/* ******************************************************************** */
#if (DB_CPU_STM32F10_XL_ON == 1)
INT32U DBGetBank2Status (void)
{   INT32U uiStatus;
    uiStatus = FLASH->SR2;
    if ((uiStatus & FLASH_SR_BSY) != 0)
    {   return DB_FLASH_STS_BUSY;
    }
    else if ((uiStatus & FLASH_SR_PGERR) != 0)
    {   return DB_FLASH_STS_ERR_PG;
    }
    else if ((uiStatus & FLASH_SR_WRPRTERR) != 0)
    {   return DB_FLASH_STS_ERR_WRP;
    }
    return DB_FLASH_STS_COMPLETE;
}
#endif

/* ******************************************************************** */
/*                        DBWaitBank1Complete()                         */
/* ******************************************************************** */
INT32U DBWaitBank1Complete (INT32U uiDelay)
{   while (uiDelay--)
    {   if (DBGetBank1Status() == DB_FLASH_STS_COMPLETE)
        {   return DB_FLASH_STS_COMPLETE;
        }
    }
    return DB_FLASH_STS_TIMEOUT;
}

/* ******************************************************************** */
/*                        DBWaitBank2Complete()                         */
/* ******************************************************************** */
#if (DB_CPU_STM32F10_XL_ON == 1)
INT32U DBWaitBank2Complete (INT32U uiDelay)
{   while (uiDelay--)
    {   if (DBGetBank2Status() == DB_FLASH_STS_COMPLETE)
        {   return DB_FLASH_STS_COMPLETE;
        }
    }
    return DB_FLASH_STS_TIMEOUT;
}
#endif

/* ******************************************************************** */
/*                         DBFlashErasePage()                           */
/* ******************************************************************** */
#if (DB_CPU_STM32F10_XL_ON == 1)
INT32U DBFlashErasePage (INT32U uiAddr)
{   INT32U uiStatus;
    if (uiAddr < DB_FLASH_BANK1_ADR_MAX)
    {   uiStatus = DBWaitBank1Complete(800000);
        if (uiStatus  ==  DB_FLASH_STS_COMPLETE)
        {   FLASH->CR |=  (INT32U)FLASH_CR_PER;
            FLASH->AR  =  uiAddr;
            FLASH->CR |=  (INT32U)FLASH_CR_STRT;
            uiStatus   =  DBWaitBank1Complete(800000);
            FLASH->CR &= ~(INT32U)FLASH_CR_PER;
        } 
    }
    else
    {   uiStatus = DBWaitBank2Complete(800000);
        if (uiStatus  ==  DB_FLASH_STS_COMPLETE)
        {   FLASH->CR2 |=  (INT32U)FLASH_CR_PER;
            FLASH->AR2  =  uiAddr;
            FLASH->CR2 |=  (INT32U)FLASH_CR_STRT;
            uiStatus    =  DBWaitBank2Complete(800000);
            FLASH->CR2 &= ~(INT32U)FLASH_CR_PER;
        } 
    }
    return uiStatus;
}
#else
INT32U DBFlashErasePage (INT32U uiAddr)
{   INT32U uiStatus;
    uiStatus = DBWaitBank1Complete(800000);
    if (uiStatus  ==  DB_FLASH_STS_COMPLETE)
    {   FLASH->CR |=  (INT32U)FLASH_CR_PER;
        FLASH->AR  =  uiAddr;
        FLASH->CR |=  (INT32U)FLASH_CR_STRT;
        uiStatus   =  DBWaitBank1Complete(800000);
        FLASH->CR &= ~(INT32U)FLASH_CR_PER;
    } 
    return uiStatus;
}
#endif

/* ******************************************************************** */
/*                          DBFlashWrite16u()                           */
/* ******************************************************************** */
#if (DB_CPU_STM32F10_XL_ON == 1)
INT32U DBFlashWrite16u (INT32U uiAddr, INT16U usData)
{   INT32U uiStatus;
    uiAddr  &= 0xFFFFFFFE;
    if (uiAddr < DB_FLASH_BANK1_ADR_MAX)
    {   uiStatus = DBWaitBank1Complete(10000);
        if (uiStatus  ==  DB_FLASH_STS_COMPLETE)
        {   FLASH->CR |=  (INT32U)FLASH_CR_PG;
            *(VINT16U*)uiAddr = usData;
            uiStatus   =  DBWaitBank1Complete(10000);
            FLASH->CR &= ~(INT32U)FLASH_CR_PG;
        }
    }
    else
    {   uiStatus = DBWaitBank2Complete(10000);
        if (uiStatus   ==  DB_FLASH_STS_COMPLETE)
        {   FLASH->CR2 |=  (INT32U)FLASH_CR_PG;
            *(VINT16U*)uiAddr = usData;
            uiStatus    =  DBWaitBank2Complete(10000);
            FLASH->CR2 &= ~(INT32U)FLASH_CR_PG;
        }
    }
    return uiStatus;
}
#else
INT32U DBFlashWrite16u (INT32U uiAddr, INT16U usData)
{   INT32U uiStatus;
    uiAddr  &= 0xFFFFFFFE;
    uiStatus = DBWaitBank1Complete(10000);
    if (uiStatus  ==  DB_FLASH_STS_COMPLETE)
    {   FLASH->CR |=  (INT32U)FLASH_CR_PG;
        *(VINT16U*)uiAddr = usData;
        uiStatus   =  DBWaitBank1Complete(10000);
        FLASH->CR &= ~(INT32U)FLASH_CR_PG;
    } 
    return uiStatus;
}
#endif

/* ******************************************************************** */
/*                          DBFlashWrite32u()                           */
/* ******************************************************************** */
INT32U DBFlashWrite32u (INT32U uiAddr, INT32U uiData)
{   INT32U uiTmp;
    uiAddr &= 0xFFFFFFFE;
    uiTmp   = DBFlashWrite16u(uiAddr, (INT16U)uiData);
    if (uiTmp == DB_FLASH_STS_COMPLETE)
    {   uiTmp  = DBFlashWrite16u(uiAddr+2, (INT16U)(uiData >> 16));
    }
    return uiTmp;
}

/* ******************************************************************** */
/*                          DBFlashWrite16p()                           */
/* ******************************************************************** */
INT32U DBFlashWrite16p (INT32U uiAddr, INT16U *pData, INT32U uiSize)
{   INT32U uiTmp;
    uiAddr &= 0xFFFFFFFE;
    while (uiSize--)
    {   uiTmp = DBFlashWrite16u(uiAddr,*pData);
        if (uiTmp != DB_FLASH_STS_COMPLETE)
        {   return uiTmp;
        }
        uiAddr += 2;
        pData++;
    }
    return DB_FLASH_STS_COMPLETE;
}

/* ******************************************************************** */
/*                           DBFlashRead16u()                           */
/* ******************************************************************** */
INT16U DBFlashRead16u (INT32U uiAddr)
{   return *((VINT16U*)uiAddr);
}

/* ******************************************************************** */
/*                           DBFlashRead32u()                           */
/* ******************************************************************** */
INT32U DBFlashRead32u (INT32U uiAddr)
{   return *((VINT32U*)uiAddr);
}

/* ******************************************************************** */
/*                           DBFlashRead16p()                           */
/* ******************************************************************** */
void DBFlashRead16p (INT32U uiAddr, INT16U *pData, INT32U uiSize)
{   VINT16U *pTemp;
    pTemp = (VINT16U*)(uiAddr & 0xFFFFFFFE);
    while (uiSize--)
    {   *pData++ = *pTemp++;
    }
}

/* ******************************************************************** */
/*                           DBCmdBufInit()                             */
/* ******************************************************************** */
void DBCmdBufInit (void)
{   DB_CMD_RING *pbuf;
    pbuf = &sDBCmdRingBuf;
    pbuf->usRingBufRxCtr   =  0;
    pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxOutPtr = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxSem    =  OSSemCreate(0);
}

/* ******************************************************************** */
/*                           DBTskGetCmd()                              */
/* ******************************************************************** */
INT08U DBTskGetCmd (INT16U to, INT08U *err)
{   OS_CPU_SR cpu_sr = 0;
    INT08U c;
    INT08U oserr;
    DB_CMD_RING *pbuf;
    pbuf = &sDBCmdRingBuf;
    (void)OSSemPend(pbuf->pRingBufRxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   *err   = OS_ERR_RX_TIMEOUT;
        return OS_NULL;
    }   else
    {   OS_ENTER_CRITICAL();
        pbuf->usRingBufRxCtr--;
        c = *pbuf->pRingBufRxOutPtr++;
        if (pbuf->pRingBufRxOutPtr == &pbuf->ucRingBufRx[DB_CMD_BUF_SIZE])
        {   pbuf->pRingBufRxOutPtr  = &pbuf->ucRingBufRx[0];
        }
        OS_EXIT_CRITICAL();
        *err = OS_NO_ERR;
        return c;
    }
}

/* ******************************************************************** */
/*                           DBTskPutCmd()                              */
/* ******************************************************************** */
void DBTskPutCmd (INT08U c)
{   OS_CPU_SR cpu_sr = 0;
    DB_CMD_RING *pbuf;
    pbuf = &sDBCmdRingBuf;
    if (pbuf->usRingBufRxCtr < DB_CMD_BUF_SIZE)
    {   OS_ENTER_CRITICAL();
        pbuf->usRingBufRxCtr++;
        *pbuf->pRingBufRxInPtr++ = c;
        if (pbuf->pRingBufRxInPtr == &pbuf->ucRingBufRx[DB_CMD_BUF_SIZE])
        {   pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
        }
        OS_EXIT_CRITICAL();
        (void)OSSemPost(pbuf->pRingBufRxSem);
    }
}

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
