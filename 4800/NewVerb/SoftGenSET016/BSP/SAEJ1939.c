/* ******************************************************************** */
/*                SAE J1939 Software for Elctronic Unit (V1.0)          */
/*                       Source File SAEJ1939.c                         */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   SAE_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                           Extern Reference                           */
/* ******************************************************************** */
extern INT08U const eHourUnit[];
extern INT08U const eHourUnit2[];

/* ******************************************************************** */
/*                              SAEInit()                               */
/* ******************************************************************** */
void SAEInit (void)
{   uiSAEStatus = 0;
    SAERxPgnTblInit();
    SAETxPgnTblInit();
}

/* ******************************************************************** */
/*                           SAERxPgnDisable ()                         */
/* ******************************************************************** */
void SAERxPgnEnable (INT08U ucIndex, INT08U usAddr)
{   SAEUpdataRxPgnAddr (ucIndex, usAddr);
    sSAERxPgnTbl[ucIndex].ucEnable = SAE_ENABLE;
}

/* ******************************************************************** */
/*                           SAERxPgnDisable ()                         */
/* ******************************************************************** */
void SAERxPgnDisable (INT16U usIndex)
{   sSAERxPgnTbl[usIndex].ucEnable = SAE_DISABLE;
}

/* ******************************************************************** */
/*                          SAERxPgnDisableAll ()                       */
/* ******************************************************************** */
void SAERxPgnDisableAll (void)
{   INT08U i;
    for (i=0; i<SAE_RX_PGN_MAX; i++)
    {   sSAERxPgnTbl[i].ucEnable = SAE_DISABLE;
    }
}

/* ******************************************************************** */
/*                           SAETxPgnEnable ()                          */
/* ******************************************************************** */
void SAETxPgnEnable (INT08U ucIndex, INT08U usAddr)
{   SAEUpdataTxPgnAddr (ucIndex, usAddr);
    sSAETxPgnTbl[ucIndex].ucEnable = SAE_ENABLE;
}

/* ******************************************************************** */
/*                           SAETxPgnDisable ()                         */
/* ******************************************************************** */
void SAETxPgnDisable (INT16U usIndex)
{   sSAETxPgnTbl[usIndex].ucEnable = SAE_DISABLE;
}

/* ******************************************************************** */
/*                          SAETxPgnDisableAll ()                       */
/* ******************************************************************** */
void SAETxPgnDisableAll (void)
{   INT08U i;
    for (i=0; i<SAE_TX_PGN_MAX; i++)
    {   sSAETxPgnTbl[i].ucEnable = SAE_DISABLE;
    }
}

/* ******************************************************************** */
/*                        SAEUpdataTxPgnAddr ()                         */
/* ******************************************************************** */
void SAEUpdataTxPgnAddr (INT08U ucIndex, INT08U ucAddr)
{   INT32U uiTemp;
    uiTemp = sSAETxPgnTbl[ucIndex].uiID;
   #if (SAE_CPU_9S12_ON == 1)
    uiTemp &= 0xFFFFFE01;
    uiTemp |= (INT32U)ucAddr << 1;
   #endif
   #if (SAE_CPU_POWERPC_ON == 1)
    uiTemp &= 0xFFFFFF00;
    uiTemp |= (INT32U)ucAddr;
   #endif
   #if (SAE_CPU_STM32F1_ON == 1)
    uiTemp &= 0xFFFFF807;
    uiTemp |= (INT32U)ucAddr << 3;
   #endif
    sSAETxPgnTbl[ucIndex].uiID = uiTemp;
}

/* ******************************************************************** */
/*                        SAEUpdataTxPgnAddrAll ()                      */
/* ******************************************************************** */
void SAEUpdataTxPgnAddrAll (INT08U ucAddr)
{   INT08U i;
    for (i=0; i<SAE_TX_PGN_MAX; i++)
    {   SAEUpdataTxPgnAddr (i, ucAddr);
    }
}

/* ******************************************************************** */
/*                        SAEUpdataRxPgnAddr ()                         */
/* ******************************************************************** */
void SAEUpdataRxPgnAddr (INT08U ucIndex, INT08U ucAddr)
{   INT32U uiTemp;
    uiTemp = sSAERxPgnTbl[ucIndex].uiID;
   #if (SAE_CPU_9S12_ON == 1)
    uiTemp &= 0xFFFFFE01;
    uiTemp |= (INT32U)ucAddr << 1;
   #endif
   #if (SAE_CPU_POWERPC_ON == 1)
    uiTemp &= 0xFFFFFF00;
    uiTemp |= (INT32U)ucAddr;
   #endif
   #if (SAE_CPU_STM32F1_ON == 1)
    uiTemp &= 0xFFFFF807;
    uiTemp |= (INT32U)ucAddr << 3;
   #endif
    sSAERxPgnTbl[ucIndex].uiID = uiTemp;
}

/* ******************************************************************** */
/*                        SAEUpdataRxPgnAddrAll ()                      */
/* ******************************************************************** */
void SAEUpdataRxPgnAddrAll (INT08U ucAddr)
{   INT08U i;
    for (i=0; i<SAE_RX_PGN_MAX; i++)
    {   SAEUpdataRxPgnAddr (i, ucAddr);
    }
}

/* ******************************************************************** */
/*                        SAECheckRxAllTimeOut ()                       */
/* ******************************************************************** */
INT08U SAECheckRxAllTimeOut (void)
{   INT08U  i, ucFlag;
    SAE_PGN_TCB *pTcb;
    ucFlag = SAE_TRUE;
    for (i=0; i<SAE_RX_PGN_MAX; i++)
    {   pTcb = &sSAERxPgnTbl[i];
        if (pTcb->ucEnable == SAE_DISABLE)
        {   continue;
        }
        if (pTcb->ucState == SAE_NO_ERR)
        {   if (SFCheckTime(pTcb->usTime,pTcb->usPeriod) != SAE_FALSE)
            {   pTcb->ucState = SAE_ERR_RX_TIMEOUT;
            }   else
            {   ucFlag = SAE_FALSE;
            }
        }
    }
    return ucFlag;
}

/* ******************************************************************** */
/*                        SAECheckRxSetpValid ()                        */
/* ******************************************************************** */
INT08U SAECheckRxSetpValid (void)
{
   #ifdef SAE_RX_PGN_TSC1AE
    SAE_PGN_TCB *pTcb;
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_TSC1AE];
    if((pTcb->ucEnable != SAE_DISABLE) && (pTcb->ucState == SAE_NO_ERR))
    {   return SAE_TRUE;
    }
   #endif
   #ifdef SAE_RX_PGN_TSC1DE
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_TSC1DE];
    if((pTcb->ucEnable != SAE_DISABLE) && (pTcb->ucState == SAE_NO_ERR))
    {   return SAE_TRUE;
    }
   #endif
   #ifdef SAE_RX_PGN_TSC1PE
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_TSC1PE];
    if((pTcb->ucEnable != SAE_DISABLE) && (pTcb->ucState == SAE_NO_ERR))
    {   return SAE_TRUE;
    }
   #endif
   #ifdef SAE_RX_PGN_TSC1TE
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_TSC1TE];
    if((pTcb->ucEnable != SAE_DISABLE) && (pTcb->ucState == SAE_NO_ERR))
    {   return SAE_TRUE;
    }
   #endif
   #ifdef SAE_RX_PGN_TSC1VE
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_TSC1VE];
    if((pTcb->ucEnable != SAE_DISABLE) && (pTcb->ucState == SAE_NO_ERR))
    {   return SAE_TRUE;
    }
   #endif
    return SAE_FALSE;
}

/* ******************************************************************** */
/*                          SAERxPgnTblInit ()                          */
/* ******************************************************************** */
void SAERxPgnTblInit (void)
{   INT08U i;
    SAE_PGN_TCB *pTcb;
    for (i=0; i<SAE_RX_PGN_MAX; i++)
    {   sSAERxPgnTbl[i].ucEnable = SAE_DISABLE;
        sSAERxPgnTbl[i].ucState  = SAE_ERR_RX_TIMEOUT;
    }
    /* ********************** 1: SAE_RX_PGN_EEC1 ********************** */
   #ifdef SAE_RX_PGN_EEC1
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_EEC1];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_EEC1);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 100 / SAE_BASIC_TIME;
   #endif
    /* ********************** 2: SAE_RX_PGN_EEC2 ********************** */
   #ifdef SAE_RX_PGN_EEC2
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_EEC2];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_EEC2);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 100 / SAE_BASIC_TIME;
   #endif
    /* ********************** 3: SAE_RX_PGN_EEC3 ********************** */
   #ifdef SAE_RX_PGN_EEC3
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_EEC3];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_EEC3);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 500 / SAE_BASIC_TIME;
   #endif
    /* ********************** 4: SAE_RX_PGN_AMCON ********************* */
   #ifdef SAE_RX_PGN_AMCON
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_AMCON];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_AMCON);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ********************* 5: SAE_RX_PGN_VEHSPD ********************* */
   #ifdef SAE_RX_PGN_VEHSPD
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_VEHSPD];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_VEHSPD);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 200 / SAE_BASIC_TIME;
   #endif
    /* ******************** 6: SAE_RX_PGN_CNFPBAM ********************* */
   #ifdef SAE_RX_PGN_CNFPBAM
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_CNFPBAM];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_CNFPBAM);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ******************** 7: SAE_RX_PGN_CNFPACK ********************* */
   #ifdef SAE_RX_PGN_CNFPACK
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_CNFPACK];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_CNFPACK);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ******************** 8: SAE_RX_PGN_ENGTEMP ********************* */
   #ifdef SAE_RX_PGN_ENGTEMP
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_ENGTEMP];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_ENGTEMP);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ********************** 9: SAE_RX_PGN_LFE *********************** */
   #ifdef SAE_RX_PGN_LFE
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_LFE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_LFE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 200 / SAE_BASIC_TIME;
   #endif
    /* ********************** 10: SAE_RX_PGN_EFL ********************** */
   #ifdef SAE_RX_PGN_EFL
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_EFL];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_EFL);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 1000 / SAE_BASIC_TIME;
   #endif
    /* ********************** 11: SAE_RX_PGN_LFC ********************** */
   #ifdef SAE_RX_PGN_LFC
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_LFC];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_LFC);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ******************* 12: SAE_RX_PGN_DM1SINGLE ******************* */
   #ifdef SAE_RX_PGN_DM1SINGLE
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_DM1SINGLE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_DM1SINGLE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ******************* 13: SAE_RX_PGN_DM2SINGLE ******************* */
   #ifdef SAE_RX_PGN_DM2SINGLE
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_DM2SINGLE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_DM2SINGLE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ******************* 14: SAE_RX_PGN_DM4SINGLE ******************* */
   #ifdef SAE_RX_PGN_DM4SINGLE
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_DM4SINGLE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_DM4SINGLE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ******************* 15: SAE_RX_PGN_DM11ACK ********************* */
   #ifdef SAE_RX_PGN_DM11ACK
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_DM11ACK];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_DM11ACK);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ******************** 16: SAE_RX_PGN_INCON ********************** */
   #ifdef SAE_RX_PGN_INCON
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_INCON];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_INCON);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ******************** 17: SAE_RX_PGN_VEHPOW ********************* */
   #ifdef SAE_RX_PGN_VEHPOW
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_VEHPOW];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_VEHPOW);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ******************** 18: SAE_RX_PGN_ENGHOUR ******************** */
   #ifdef SAE_RX_PGN_ENGHOUR
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_ENGHOUR];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_ENGHOUR);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ******************** 19: SAE_RX_PGN_CRPRESS ******************** */
   #ifdef SAE_RX_PGN_CRPRESS
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_CRPRESS];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_CRPRESS);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ********************** 20: SAE_RX_PGN_EBC1 ********************* */
   #ifdef SAE_RX_PGN_EBC1
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_EBC1];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_EBC1);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 100 / SAE_BASIC_TIME;
   #endif
    /* ********************** 21: SAE_RX_PGN_EBC2 ********************* */
   #ifdef SAE_RX_PGN_EBC2
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_EBC2];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_EBC2);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 100 / SAE_BASIC_TIME;
   #endif
    /* ********************** 22: SAE_RX_PGN_ETC1 ********************* */
   #ifdef SAE_RX_PGN_ETC1
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_ETC1];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_ETC1);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 100 / SAE_BASIC_TIME;
   #endif
    /* ********************* 23: SAE_RX_PGN_RXCCVS ******************** */
   #ifdef SAE_RX_PGN_RXCCVS
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_RXCCVS];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_RXCCVS);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 200 / SAE_BASIC_TIME;
   #endif
    /* ********************** 24: SAE_RX_PGN_HRVD ********************* */
   #ifdef SAE_RX_PGN_HRVD
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_HRVD];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_HRVD);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ********************* 25: SAE_RX_PGN_PGNRQ ********************* */
   #ifdef SAE_RX_PGN_PGNRQ
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_PGNRQ];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_PGNRQ);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ******************** 26: SAE_RX_PGN_RXAMCON ******************** */
   #ifdef SAE_RX_PGN_RXAMCON
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_RXAMCON];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_RXAMCON);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ********************** 27: SAE_RX_PGN_TCO1 ********************* */
   #ifdef SAE_RX_PGN_TCO1
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_TCO1];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_TCO1);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 100 / SAE_BASIC_TIME;
   #endif
    /* ********************* 28: SAE_RX_PGN_TSC1AE ******************** */
   #ifdef SAE_RX_PGN_TSC1AE
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_TSC1AE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_TSC1AE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 100 / SAE_BASIC_TIME;
   #endif
    /* ******************** 29: SAE_RX_PGN_TSC1DE ********************* */
   #ifdef SAE_RX_PGN_TSC1DE
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_TSC1DE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_TSC1DE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 100 / SAE_BASIC_TIME;
   #endif
    /* ******************** 30: SAE_RX_PGN_TSC1PE ********************* */
   #ifdef SAE_RX_PGN_TSC1PE
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_TSC1PE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_TSC1PE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 100 / SAE_BASIC_TIME;
   #endif
    /* ******************** 31: SAE_RX_PGN_TSC1TE ********************* */
   #ifdef SAE_RX_PGN_TSC1TE
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_TSC1TE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_TSC1TE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 100 / SAE_BASIC_TIME;
   #endif
    /* ******************** 32: SAE_RX_PGN_TSC1VE ********************* */
   #ifdef SAE_RX_PGN_TSC1VE
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_TSC1VE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_TSC1VE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 100 / SAE_BASIC_TIME;
   #endif
    /* ********************* 33: SAE_RX_PGN_DM13 ********************** */
   #ifdef SAE_RX_PGN_DM13
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_DM13];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_DM13);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ********************* 34: SAE_RX_PGN_DEC1 ********************** */
   #ifdef SAE_RX_PGN_DEC1
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_DEC1];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_DEC1);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 100 / SAE_BASIC_TIME;
   #endif
    /* ******************* 35: SAE_RX_PGN_CCP10REQ ******************** */
   #ifdef SAE_RX_PGN_CCP10REQ
   #if   (SAE_CCP_CCP10_ON == 1)
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_CCP10REQ];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_CCP10REQ);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
   #endif
    /* ******************* 36: SAE_RX_PGN_CCP10PAR ******************** */
   #ifdef SAE_RX_PGN_CCP10PAR
   #if   (SAE_CCP_CCP10_ON == 1)
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_CCP10PAR];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_CCP10PAR);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
   #endif
    /* ******************** 37: SAE_RX_PGN_ECULOCK ******************** */
   #ifdef SAE_RX_PGN_ECULOCK
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_ECULOCK];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_LOCK);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ******************** 38: SAE_RX_PGN_SLAVEERR ******************* */
   #ifdef SAE_RX_PGN_SLAVEERR
    pTcb = &sSAERxPgnTbl[SAE_RX_PGN_SLAVEERR];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_SLAVEERR);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_ERR_RX_TIMEOUT;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 2000 / SAE_BASIC_TIME;
   #endif
    /* ******************* If RX Msg Only PGN Match ******************* */
   #if (SAE_RX_PGN_MATCH_ON == 1)
    for (i=0; i<SAE_RX_PGN_MAX; i++)
    {   sSAERxPgnTbl[i].uiID = SAE_CPU_TO_PGN32(sSAERxPgnTbl[i].uiID);
    }
   #endif
}

/* ******************************************************************** */
/*                          SAETxPgnTblInit ()                          */
/* ******************************************************************** */
void SAETxPgnTblInit (void)
{   INT08U i;
    SAE_PGN_TCB *pTcb;
    for (i=0; i<SAE_TX_PGN_MAX; i++)
    {   sSAETxPgnTbl[i].ucEnable = SAE_DISABLE;
        sSAETxPgnTbl[i].ucState  = SAE_CODE_FREE;
    }
    /* ********************** 1: SAE_TX_PGN_EEC1 ********************** */
   #ifdef SAE_TX_PGN_EEC1
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_EEC1];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_EEC1);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 10 / SAE_BASIC_TIME;
   #endif
    /* ********************** 2: SAE_TX_PGN_EEC2 ********************** */
   #ifdef SAE_TX_PGN_EEC2
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_EEC2];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_EEC2);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 50 / SAE_BASIC_TIME;
   #endif
    /* ********************** 3: SAE_TX_PGN_EEC3 ********************** */
   #ifdef SAE_TX_PGN_EEC3
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_EEC3];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_EEC3);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 250 / SAE_BASIC_TIME;
   #endif
    /* ********************** 4: SAE_TX_PGN_AMCON ********************* */
   #ifdef SAE_TX_PGN_AMCON
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_AMCON];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_AMCON);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 1000 / SAE_BASIC_TIME;
   #endif
    /* ********************* 5: SAE_TX_PGN_VEHSPD ********************* */
   #ifdef SAE_TX_PGN_VEHSPD
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_VEHSPD];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_VEHSPD);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 100 / SAE_BASIC_TIME;
   #endif
    /* ******************** 6: SAE_TX_PGN_CNFPBAM ********************* */
   #ifdef SAE_TX_PGN_CNFPBAM
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_CNFPBAM];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_CNFPBAM);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 5000 / SAE_BASIC_TIME;
   #endif
    /* ******************** 7: SAE_TX_PGN_CNFPACK ********************* */
   #ifdef SAE_TX_PGN_CNFPACK
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_CNFPACK];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_CNFPACK);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_FREE;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 65535;
   #endif
    /* ******************** 8: SAE_TX_PGN_ENGTEMP ********************* */
   #ifdef SAE_TX_PGN_ENGTEMP
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_ENGTEMP];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_ENGTEMP);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 1000 / SAE_BASIC_TIME;
   #endif
    /* ********************** 9: SAE_TX_PGN_LFE *********************** */
   #ifdef SAE_TX_PGN_LFE
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_LFE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_LFE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 100 / SAE_BASIC_TIME;
   #endif
    /* ********************** 10: SAE_TX_PGN_EFL ********************** */
   #ifdef SAE_TX_PGN_EFL
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_EFL];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_EFL);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 500 / SAE_BASIC_TIME;
   #endif
    /* ********************** 11: SAE_TX_PGN_LFC ********************** */
   #ifdef SAE_TX_PGN_LFC
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_LFC];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_LFC);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_FREE;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 65535;
   #if (SAE_6800_TBS_ON == 1)
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usPeriod = 10 / SAE_BASIC_TIME;
   #endif
   #if (SAE_6800_HUA_WEI_ON == 1)
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usPeriod = 100 / SAE_BASIC_TIME;
   #endif
   #if (SAE_6800_WATER_PUMP_ON == 1)
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usPeriod = 500 / SAE_BASIC_TIME;
   #endif
   #if (SAE_6800_TWO_FUEL_ON == 1) || (SAE_8000_TWO_FUEL_ON == 1)
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usPeriod = 500 / SAE_BASIC_TIME;
   #endif
   #endif
    /* ******************* 12: SAE_TX_PGN_DM1SINGLE ******************* */
   #ifdef SAE_TX_PGN_DM1SINGLE
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_DM1SINGLE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_DM1SINGLE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 1000 / SAE_BASIC_TIME;
   #endif
    /* ******************* 13: SAE_TX_PGN_DM2SINGLE ******************* */
   #ifdef SAE_TX_PGN_DM2SINGLE
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_DM2SINGLE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_DM2SINGLE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_FREE;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 65535;
   #endif
    /* ******************* 14: SAE_TX_PGN_DM4SINGLE ******************* */
   #ifdef SAE_TX_PGN_DM4SINGLE
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_DM4SINGLE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_DM4SINGLE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_FREE;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 65535;
   #endif
    /* ******************* 15: SAE_TX_PGN_DM11ACK ********************* */
   #ifdef SAE_TX_PGN_DM11ACK
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_DM11ACK];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_DM11ACK);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_FREE;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 65535;
   #endif
    /* ******************** 16: SAE_TX_PGN_INCON ********************** */
   #ifdef SAE_TX_PGN_INCON
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_INCON];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_INCON);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 1000 / SAE_BASIC_TIME;
   #endif
    /* ******************** 17: SAE_TX_PGN_VEHPOW ********************* */
   #ifdef SAE_TX_PGN_VEHPOW
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_VEHPOW];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_VEHPOW);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 1000 / SAE_BASIC_TIME;
   #endif
    /* ******************** 18: SAE_TX_PGN_ENGHOUR ******************** */
   #ifdef SAE_TX_PGN_ENGHOUR
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_ENGHOUR];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_ENGHOUR);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_FREE;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 65535;
   #if (SAE_6800_SHAN_TUI_ON == 1)
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usPeriod = 1000 / SAE_BASIC_TIME;
   #endif
   #endif
    /* ******************** 19: SAE_TX_PGN_CRPRESS ******************** */
   #ifdef SAE_TX_PGN_CRPRESS
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_CRPRESS];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_CRPRESS);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 500 / SAE_BASIC_TIME;
   #endif
    /* ********************** 20: SAE_TX_PGN_EBC1 ********************* */
   #ifdef SAE_TX_PGN_EBC1
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_EBC1];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_EBC1);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 20 / SAE_BASIC_TIME;
   #endif
    /* ********************** 21: SAE_TX_PGN_EBC2 ********************* */
   #ifdef SAE_TX_PGN_EBC2
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_EBC2];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_EBC2);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 50 / SAE_BASIC_TIME;
   #endif
    /* ********************** 22: SAE_TX_PGN_ETC1 ********************* */
   #ifdef SAE_TX_PGN_ETC1
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_ETC1];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_ETC1);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 10 / SAE_BASIC_TIME;
   #endif
    /* ********************* 23: SAE_TX_PGN_RXCCVS ******************** */
   #ifdef SAE_TX_PGN_RXCCVS
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_RXCCVS];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_RXCCVS);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 100 / SAE_BASIC_TIME;
   #endif
    /* ********************** 24: SAE_TX_PGN_HRVD ********************* */
   #ifdef SAE_TX_PGN_HRVD
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_HRVD];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_HRVD);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 1000 / SAE_BASIC_TIME;
   #endif
    /* ********************* 25: SAE_TX_PGN_PGNRQ ********************* */
   #ifdef SAE_TX_PGN_PGNRQ
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_PGNRQ];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_PGNRQ);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 1000 / SAE_BASIC_TIME;
   #endif
    /* ******************** 26: SAE_TX_PGN_RXAMCON ******************** */
   #ifdef SAE_TX_PGN_RXAMCON
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_RXAMCON];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_RXAMCON);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 1000 / SAE_BASIC_TIME;
   #endif
    /* ********************** 27: SAE_TX_PGN_TCO1 ********************* */
   #ifdef SAE_TX_PGN_TCO1
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_TCO1];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_TCO1);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 50 / SAE_BASIC_TIME;
   #endif
    /* ********************* 28: SAE_TX_PGN_TSC1AE ******************** */
   #ifdef SAE_TX_PGN_TSC1AE
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_TSC1AE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_TSC1AE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 10 / SAE_BASIC_TIME;
   #endif
    /* ******************** 29: SAE_TX_PGN_TSC1DE ********************* */
   #ifdef SAE_TX_PGN_TSC1DE
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_TSC1DE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_TSC1DE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 10 / SAE_BASIC_TIME;
   #endif
    /* ******************** 30: SAE_TX_PGN_TSC1PE ********************* */
   #ifdef SAE_TX_PGN_TSC1PE
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_TSC1PE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_TSC1PE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 10 / SAE_BASIC_TIME;
   #endif
    /* ******************** 31: SAE_TX_PGN_TSC1TE ********************* */
   #ifdef SAE_TX_PGN_TSC1TE
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_TSC1TE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_TSC1TE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 10 / SAE_BASIC_TIME;
   #endif
    /* ******************** 32: SAE_TX_PGN_TSC1VE ********************* */
   #ifdef SAE_TX_PGN_TSC1VE
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_TSC1VE];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_TSC1VE);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 10 / SAE_BASIC_TIME;
   #endif
    /* ********************* 33: SAE_TX_PGN_DM13 ********************** */
   #ifdef SAE_TX_PGN_DM13
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_DM13];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_DM13);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 1000 / SAE_BASIC_TIME;
   #endif
    /* ********************* 34: SAE_TX_PGN_DEC1 ********************** */
   #ifdef SAE_TX_PGN_DEC1
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_DEC1];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_DEC1);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_CYCLIC;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 20 / SAE_BASIC_TIME;
   #endif
    /* ******************* 35: SAE_TX_PGN_CCP10REQ ******************** */
   #ifdef SAE_TX_PGN_CCP10REQ
   #if   (SAE_CCP_CCP10_ON == 1)
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_CCP10REQ];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_CCP10REQ);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_FREE;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 65535;
   #endif
   #endif
    /* ******************* 36: SAE_TX_PGN_CCP10PAR ******************** */
   #ifdef SAE_TX_PGN_CCP10PAR
   #if   (SAE_CCP_CCP10_ON == 1)
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_CCP10PAR];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_CCP10PAR);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_FREE;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 65535;
   #endif
   #endif
    /* ******************** 37: SAE_TX_PGN_ECULOCK ******************** */
   #ifdef SAE_TX_PGN_ECULOCK
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_ECULOCK];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_LOCK);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_FREE;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 500 / SAE_BASIC_TIME;
   #endif
    /* ******************** 38: SAE_TX_PGN_SLAVEERR ******************* */
   #ifdef SAE_TX_PGN_SLAVEERR
    pTcb = &sSAETxPgnTbl[SAE_TX_PGN_SLAVEERR];
    pTcb->uiID     = SAE_ID32_TO_CPU(SAE_ID_J1939_SLAVEERR);
    pTcb->ucEnable = SAE_ENABLE;
    pTcb->ucState  = SAE_CODE_FREE;
    pTcb->usTime   = usFW5msTimer;
    pTcb->usPeriod = 1000 / SAE_BASIC_TIME;
   #endif
}

/* ******************************************************************** */
/*                          SAEProcessRxMsg ()                          */
/* ******************************************************************** */
INT08U SAEProcessRxMsg (CAN_MSG *pMsg)
{   INT08U  i;
    INT32U  uiTemp;
    SAE_PGN_TCB *pTcb;
    uiTemp = pMsg->DAT32.uiID;
   #if (SAE_RX_PGN_MATCH_ON == 1)
    uiTemp = SAE_CPU_TO_PGN32(uiTemp);
   #endif
    for (i=0; i<SAE_RX_PGN_MAX; i++)
    {   pTcb = &sSAERxPgnTbl[i];
        if (pTcb->ucEnable == SAE_DISABLE)
        {   continue;
        }
        if (pTcb->uiID != uiTemp)
        {   continue;
        }
        if (SFCheckTime(pTcb->usTime,pTcb->usPeriod) != SAE_FALSE)
        {   pTcb->ucState = SAE_ERR_RX_TIMEOUT;
            pTcb->usTime  = usFW5msTimer;
        }   else
        {   pTcb->ucState = SAE_NO_ERR;
            pTcb->usTime  = usFW5msTimer;
        }
        if (0) {;}
       #ifdef SAE_RX_PGN_EEC1
        else if (i == SAE_RX_PGN_EEC1)
        {   SAEUpdateRxEEC1 (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_EEC2
        else if (i == SAE_RX_PGN_EEC2)
        {   SAEUpdateRxEEC2 (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_EEC3
        else if (i == SAE_RX_PGN_EEC3)
        {   SAEUpdateRxEEC3 (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_AMCON
        else if (i == SAE_RX_PGN_AMCON)
        {   SAEUpdateRxAMCON (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_VEHSPD
        else if (i == SAE_RX_PGN_VEHSPD)
        {   SAEUpdateRxVEHSPD (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_CNFPBAM
        else if (i == SAE_RX_PGN_CNFPBAM)
        {   SAEUpdateRxCNFPBAM (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_CNFPACK
        else if (i == SAE_RX_PGN_CNFPACK)
        {   SAEUpdateRxCNFPACK (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_ENGTEMP
        else if (i == SAE_RX_PGN_ENGTEMP)
        {   SAEUpdateRxENGTEMP (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_LFE
        else if (i == SAE_RX_PGN_LFE)
        {   SAEUpdateRxLFE (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_EFL
        else if (i == SAE_RX_PGN_EFL)
        {   SAEUpdateRxEFL (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_LFC
        else if (i == SAE_RX_PGN_LFC)
        {   SAEUpdateRxLFC (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_DM1SINGLE
        else if (i == SAE_RX_PGN_DM1SINGLE)
        {   SAEUpdateRxDM1 (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_DM2SINGLE
        else if (i == SAE_RX_PGN_DM2SINGLE)
        {   SAEUpdateRxDM2 (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_DM4SINGLE
        else if (i == SAE_RX_PGN_DM4SINGLE)
        {   SAEUpdateRxDM4 (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_DM11ACK
        else if (i == SAE_RX_PGN_DM11ACK)
        {   SAEUpdateRxDM11ACK (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_INCON
        else if (i == SAE_RX_PGN_INCON)
        {   SAEUpdateRxINCON (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_VEHPOW
        else if (i == SAE_RX_PGN_VEHPOW)
        {   SAEUpdateRxVEHPOW (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_ENGHOUR
        else if (i == SAE_RX_PGN_ENGHOUR)
        {   SAEUpdateRxENGHOUR (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_CRPRESS
        else if (i == SAE_RX_PGN_CRPRESS)
        {   SAEUpdateRxCRPRESS (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_EBC1
        else if (i == SAE_RX_PGN_EBC1)
        {   SAEUpdateRxEBC1 (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_EBC2
        else if (i == SAE_RX_PGN_EBC2)
        {   SAEUpdateRxEBC2 (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_ETC1
        else if (i == SAE_RX_PGN_ETC1)
        {   SAEUpdateRxETC1 (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_RXCCVS
        else if (i == SAE_RX_PGN_RXCCVS)
        {   SAEUpdateRxRXCCVS (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_HRVD
        else if (i == SAE_RX_PGN_HRVD)
        {   SAEUpdateRxHRVD (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_PGNRQ
        else if (i == SAE_RX_PGN_PGNRQ)
        {   SAEUpdateRxPGNRQ (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_RXAMCON
        else if (i == SAE_RX_PGN_RXAMCON)
        {   SAEUpdateRxRXAMCON (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_TCO1
        else if (i == SAE_RX_PGN_TCO1)
        {   SAEUpdateRxTCO1 (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_TSC1AE
        else if (i == SAE_RX_PGN_TSC1AE)
        {   SAEUpdateRxTSC1AE (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_TSC1DE
        else if (i == SAE_RX_PGN_TSC1DE)
        {   SAEUpdateRxTSC1DE (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_TSC1PE
        else if (i == SAE_RX_PGN_TSC1PE)
        {   SAEUpdateRxTSC1PE (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_TSC1TE
        else if (i == SAE_RX_PGN_TSC1TE)
        {   SAEUpdateRxTSC1TE (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_TSC1VE
        else if (i == SAE_RX_PGN_TSC1VE)
        {   SAEUpdateRxTSC1VE (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_DM13
        else if (i == SAE_RX_PGN_DM13)
        {   SAEUpdateRxDM13 (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_DEC1
        else if (i == SAE_RX_PGN_DEC1)
        {   SAEUpdateRxDEC1 (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_CCP10REQ
       #if   (SAE_CCP_CCP10_ON == 1)
        else if (i == SAE_RX_PGN_CCP10REQ)
        {   SAEUpdateRxCCPREQ (pMsg);
        }
       #endif
       #endif
       #ifdef SAE_RX_PGN_CCP10PAR
       #if   (SAE_CCP_CCP10_ON == 1)
        else if (i == SAE_RX_PGN_CCP10PAR)
        {   SAEUpdateRxCCPPAR (pMsg);
        }
       #endif
       #endif
       #ifdef SAE_RX_PGN_ECULOCK
        else if (i == SAE_RX_PGN_ECULOCK)
        {   SAEUpdateRxEcuLock (pMsg);
        }
       #endif
       #ifdef SAE_RX_PGN_SLAVEERR
        else if (i == SAE_RX_PGN_SLAVEERR)
        {   SAEUpdateRxSlaveErr (pMsg);
        }
       #endif
        return SAE_TRUE;
    }
    return SAE_FALSE;
}

/* ******************************************************************** */
/*                            SAEProcessTxMsg ()                        */
/* ******************************************************************** */
INT08U SAEProcessTxMsg (CAN_MSG *pMsg)
{   INT08U  i;
    SAE_PGN_TCB *pTcb;
    for (i=0; i<SAE_TX_PGN_MAX; i++)
    {   pTcb = &sSAETxPgnTbl[i];
        if (pTcb->ucEnable == SAE_DISABLE)
        {   continue;
        }
        if (pTcb->ucState == SAE_CODE_IMMED)
        {   pTcb->ucState  = SAE_CODE_FREE;
        }
        else if (pTcb->ucState != SAE_CODE_CYCLIC)
        {   continue;
        }
        else if (SFCheckTime(pTcb->usTime,pTcb->usPeriod) != SAE_FALSE)
        {   pTcb->usTime = usFW5msTimer;
        }
        else
        {   continue;
        }
        pMsg->DAT32.uiID   = pTcb->uiID;
        pMsg->DAT32.uiDat0 = 0xFFFFFFFF;
        pMsg->DAT32.uiDat1 = 0xFFFFFFFF;
        if (0) {;}
       #ifdef SAE_TX_PGN_EEC1
        else if (i == SAE_TX_PGN_EEC1)
        {   SAEUpdateTxEEC1 (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_EEC2
        else if (i == SAE_TX_PGN_EEC2)
        {   SAEUpdateTxEEC2 (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_EEC3
        else if (i == SAE_TX_PGN_EEC3)
        {   SAEUpdateTxEEC3 (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_AMCON
        else if (i == SAE_TX_PGN_AMCON)
        {   SAEUpdateTxAMCON (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_VEHSPD
        else if (i == SAE_TX_PGN_VEHSPD)
        {   SAEUpdateTxVEHSPD (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_CNFPBAM
        else if (i == SAE_TX_PGN_CNFPBAM)
        {   SAEUpdateTxCNFPBAM (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_CNFPACK
        else if (i == SAE_TX_PGN_CNFPACK)
        {   SAEUpdateTxCNFPACK (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_ENGTEMP
        else if (i == SAE_TX_PGN_ENGTEMP)
        {   SAEUpdateTxENGTEMP (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_LFE
        else if (i == SAE_TX_PGN_LFE)
        {   SAEUpdateTxLFE (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_EFL
        else if (i == SAE_TX_PGN_EFL)
        {   SAEUpdateTxEFL (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_LFC
        else if (i == SAE_TX_PGN_LFC)
        {   SAEUpdateTxLFC (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_DM1SINGLE
        else if (i == SAE_TX_PGN_DM1SINGLE)
        {   SAEUpdateTxDM1 (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_DM2SINGLE
        else if (i == SAE_TX_PGN_DM2SINGLE)
        {   SAEUpdateTxDM2 (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_DM4SINGLE
        else if (i == SAE_TX_PGN_DM4SINGLE)
        {   SAEUpdateTxDM4 (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_DM11ACK
        else if (i == SAE_TX_PGN_DM11ACK)
        {   SAEUpdateTxDM11ACK (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_INCON
        else if (i == SAE_TX_PGN_INCON)
        {   SAEUpdateTxINCON (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_VEHPOW
        else if (i == SAE_TX_PGN_VEHPOW)
        {   SAEUpdateTxVEHPOW (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_ENGHOUR
        else if (i == SAE_TX_PGN_ENGHOUR)
        {   SAEUpdateTxENGHOUR (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_CRPRESS
        else if (i == SAE_TX_PGN_CRPRESS)
        {   SAEUpdateTxCRPRESS (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_EBC1
        else if (i == SAE_TX_PGN_EBC1)
        {   SAEUpdateTxEBC1 (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_EBC2
        else if (i == SAE_TX_PGN_EBC2)
        {   SAEUpdateTxEBC2 (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_ETC1
        else if (i == SAE_TX_PGN_ETC1)
        {   SAEUpdateTxETC1 (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_RXCCVS
        else if (i == SAE_TX_PGN_RXCCVS)
        {   SAEUpdateTxRXCCVS (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_HRVD
        else if (i == SAE_TX_PGN_HRVD)
        {   SAEUpdateTxHRVD (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_PGNRQ
        else if (i == SAE_TX_PGN_PGNRQ)
        {   SAEUpdateTxPGNRQ (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_RXAMCON
        else if (i == SAE_TX_PGN_RXAMCON)
        {   SAEUpdateTxRXAMCON (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_TCO1
        else if (i == SAE_TX_PGN_TCO1)
        {   SAEUpdateTxTCO1 (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_TSC1AE
        else if (i == SAE_TX_PGN_TSC1AE)
        {   SAEUpdateTxTSC1AE (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_TSC1DE
        else if (i == SAE_TX_PGN_TSC1DE)
        {   SAEUpdateTxTSC1DE (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_TSC1PE
        else if (i == SAE_TX_PGN_TSC1PE)
        {   SAEUpdateTxTSC1PE (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_TSC1TE
        else if (i == SAE_TX_PGN_TSC1TE)
        {   SAEUpdateTxTSC1TE (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_TSC1VE
        else if (i == SAE_TX_PGN_TSC1VE)
        {   SAEUpdateTxTSC1VE (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_DM13
        else if (i == SAE_TX_PGN_DM13)
        {   SAEUpdateTxDM13 (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_DEC1
        else if (i == SAE_TX_PGN_DEC1)
        {   SAEUpdateTxDEC1 (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_CCP10REQ
       #if   (SAE_CCP_CCP10_ON == 1)
        else if (i == SAE_TX_PGN_CCP10REQ)
        {   SAEUpdateTxCCPREQ (pMsg);
        }
       #endif
       #endif
       #ifdef SAE_TX_PGN_CCP10PAR
       #if   (SAE_CCP_CCP10_ON == 1)
        else if (i == SAE_TX_PGN_CCP10PAR)
        {   SAEUpdateTxCCPPAR (pMsg);
        }
       #endif
       #endif
       #ifdef SAE_TX_PGN_ECULOCK
        else if (i == SAE_TX_PGN_ECULOCK)
        {   SAEUpdateTxEcuLock (pMsg);
        }
       #endif
       #ifdef SAE_TX_PGN_SLAVEERR
        else if (i == SAE_TX_PGN_SLAVEERR)
        {   SAEUpdateTxSlaveErr (pMsg);
        }
       #endif
        if (SAEPutMsgToTxBuf(10,pMsg) != SAE_NO_ERR)
        {   return SAE_ERR_TX_TIMEOUT;
        }
    }
    return SAE_NO_ERR;
}

/* ******************************************************************** */
/*                           1: SAE_TX_PGN_EEC1                         */
/* ******************************************************************** */

/* ****************************** TX_EEC1 ***************************** */
#ifdef SAE_TX_PGN_EEC1
void SAEUpdateTxEEC1 (CAN_MSG *pMsg)
{
   #if (SAE_6800_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = usDBmFuelLimitMaxActive;
    if (usTemp == 0)
    {   pMsg->DAT08.ucDat2 = 0;
    }   else
    {   pMsg->DAT08.ucDat2 = (INT08U)((INT32U)usDBmFuelGovernor * 100 / (INT32U)usTemp);
    }
    usTemp             = usDBmSpeed * 2;
    pMsg->DAT08.ucDat3 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat4 = SAE_UC_HIGH (usTemp);
    pMsg->DAT08.ucDat5 = SAE_MY_ADDRESS;
   #if (SAE_6800_WATER_PUMP_ON == 1)
    usTemp             = mWPInPressure > 1000 ? mWPInPressure - 1000 : 0;
    pMsg->DAT08.ucDat0 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat1 = SAE_UC_HIGH (usTemp);
    usTemp             = mWPOutPressure > 1000 ? mWPOutPressure - 1000 : 0;
    pMsg->DAT08.ucDat6 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat7 = SAE_UC_HIGH (usTemp);
   #endif
   #endif
}
#endif

/* ****************************** RX_EEC1 ***************************** */
#ifdef SAE_RX_PGN_EEC1
void SAEUpdateRxEEC1 (CAN_MSG *pMsg)
{
   #ifdef DB_NO_ENG_SPEED
    INT16U usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat3);
    if (usTemp <= 64255)
    {   aDBDisplay[DB_NO_ENG_SPEED].ssValue = usTemp / 8;
        aDBDisplay[DB_NO_ENG_SPEED].ucErr   = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_ENG_SPEED].ssValue = 0;
        aDBDisplay[DB_NO_ENG_SPEED].ucErr   = SAE_ERR_INVALID;
    }
   #endif
   #ifdef DB_NO_ENG_LOAD
    usTemp = pMsg->DAT08.ucDat2;
    if (usTemp <= 125)
    {   aDBDisplay[DB_NO_ENG_LOAD].ssValue  = usTemp;
        aDBDisplay[DB_NO_ENG_LOAD].ucErr    = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_ENG_LOAD].ssValue  = 0;
        aDBDisplay[DB_NO_ENG_LOAD].ucErr    = SAE_ERR_INVALID;
    }
   #endif
}
#endif

/* ******************************************************************** */
/*                           2: SAE_TX_PGN_EEC2                         */
/* ******************************************************************** */
/* ****************************** TX_EEC2 ***************************** */
#ifdef SAE_TX_PGN_EEC2
void SAEUpdateTxEEC2 (CAN_MSG *pMsg)
{
   #if (SAE_6800_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = usDBmSpeedMaxActive - usDBmSpeedIdleActive;
    if (usDBmSetp1Extern <= usDBmSpeedIdleActive)
    {   usTemp = 0;
    }   else if (usTemp != 0)
    {   usTemp = (INT16U)((INT32U)(usDBmSetp1Extern-usDBmSpeedIdleActive)*250/(INT32U)usTemp);
    }
    if (usTemp > 250)
    {   usTemp = 250;
    }
    pMsg->DAT08.ucDat1 = (INT08U)usTemp;
   #endif
}
#endif

/* ****************************** RX_EEC2 ***************************** */
#ifdef SAE_RX_PGN_EEC2
void SAEUpdateRxEEC2 (CAN_MSG *pMsg)
{
   #ifdef DB_NO_PEDAL_POSI
    INT16U usTemp;
    usTemp = pMsg->DAT08.ucDat1;
    if (usTemp <= 250)
    {   aDBDisplay[DB_NO_PEDAL_POSI].ssValue = (usTemp * 2) / 5;
        aDBDisplay[DB_NO_PEDAL_POSI].ucErr   = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_PEDAL_POSI].ssValue = 0;
        aDBDisplay[DB_NO_PEDAL_POSI].ucErr   = SAE_ERR_INVALID;
    }
   #endif
}
#endif

/* ******************************************************************** */
/*                           3: SAE_TX_PGN_EEC3                         */
/* ******************************************************************** */
/* ****************************** TX_EEC3 ***************************** */
#ifdef SAE_TX_PGN_EEC3
void SAEUpdateTxEEC3 (CAN_MSG *pMsg)
{
   #ifdef usDBmSpeedSetp
    INT16U usTemp;
    usTemp = usDBmSpeedSetp * 2;
    pMsg->DAT08.ucDat1 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat2 = SAE_UC_HIGH (usTemp);
   #endif
}
#endif

/* ****************************** RX_EEC3 ***************************** */
#ifdef SAE_RX_PGN_EEC3
void SAEUpdateRxEEC3 (CAN_MSG *pMsg)
{
    pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                           4: SAE_TX_PGN_AMCON                        */
/* ******************************************************************** */
/* ****************************** TX_AMCON **************************** */
#ifdef SAE_TX_PGN_AMCON
void SAEUpdateTxAMCON (CAN_MSG *pMsg)
{
   #if (SAE_6800_HUA_WEI_ON == 1)
    INT16U usTemp;
    usTemp = (INT16U)((INT32U)(mHWCabinetTemp - (DB_SIGNED_ZERO-2730)) * 16 / 5);
    pMsg->DAT08.ucDat0 = (INT08U)(usDBmAmbientPressure / 10);
    pMsg->DAT08.ucDat3 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat4 = SAE_UC_HIGH (usTemp);
   #else
   #ifdef usDBmTempIntern
    INT16U usTemp;
    usTemp = (INT16U)((INT32U)(usDBmTempIntern - (DB_SIGNED_ZERO-2730)) * 16 / 5);
    pMsg->DAT08.ucDat0 = (INT08U)(usDBmAmbientPressure / 40);
    pMsg->DAT08.ucDat3 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat4 = SAE_UC_HIGH (usTemp);
   #endif
   #endif
}
#endif

/* ****************************** RX_AMCON **************************** */
#ifdef SAE_RX_PGN_AMCON
void SAEUpdateRxAMCON (CAN_MSG *pMsg)
{
   #if (SAE_4000_COMMON_ON == 1)
    INT16U usTemp;
    usDBmAmbientPressure = (INT16U)(pMsg->DAT08.ucDat0) * 40;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat3);
    usDBmTempIntern = (INT16U)((INT32U)usTemp * 5 / 16 + (DB_SIGNED_ZERO-2730));
   #endif
    pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                           5: SAE_TX_PGN_VEHSPD                       */
/* ******************************************************************** */
/* ****************************** TX_VEHSPD *************************** */
#ifdef SAE_TX_PGN_VEHSPD
void SAEUpdateTxVEHSPD (CAN_MSG *pMsg)
{
   #ifdef usDBmVeSpeed
    INT16U usTemp;
    usTemp             = (INT16U)((INT32U)usDBmVeSpeed * 128 / 5);
    pMsg->DAT08.ucDat1 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat2 = SAE_UC_HIGH (usTemp);
   #endif
}
#endif

/* ****************************** RX_VEHSPD *************************** */
#ifdef SAE_RX_PGN_VEHSPD
void SAEUpdateRxVEHSPD (CAN_MSG *pMsg)
{
   #ifdef DB_NO_VEH_SPEED
    INT16U usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat1);
    if (usTemp <= 64255)
    {   aDBDisplay[DB_NO_VEH_SPEED].ssValue = usTemp / 256;
        aDBDisplay[DB_NO_VEH_SPEED].ucErr   = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_VEH_SPEED].ssValue = 0;
        aDBDisplay[DB_NO_VEH_SPEED].ucErr   = SAE_ERR_INVALID;
    }
   #endif
   #if (SAE_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat1);
    usDBmVeSpeed = (INT16U)((INT32U)usTemp * 5 / 128);
   #endif
}
#endif

/* ******************************************************************** */
/*                          6: SAE_TX_PGN_CNFPBAM                       */
/* ******************************************************************** */
/* ****************************** TX_CNFPBAM ************************** */
#ifdef SAE_TX_PGN_CNFPBAM
void SAEUpdateTxCNFPBAM (CAN_MSG *pMsg)
{
   #if (SAE_6800_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = APP_VERSION;
    pMsg->DAT08.ucDat3 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat4 = SAE_UC_HIGH (usTemp);
    pMsg->DAT08.ucDat5 = 0xE3;
    pMsg->DAT08.ucDat6 = 0xFE;
    pMsg->DAT08.ucDat7 = 0x00;
   #endif
   #if (SAE_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = APP_VERSION;
    pMsg->DAT08.ucDat3 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat4 = SAE_UC_HIGH (usTemp);
    pMsg->DAT08.ucDat5 = 0xE3;
    pMsg->DAT08.ucDat6 = 0xFE;
    pMsg->DAT08.ucDat7 = 0x00;
   #endif
}
#endif

/* ****************************** RX_CNFPBAM ************************** */
#ifdef SAE_RX_PGN_CNFPBAM
void SAEUpdateRxCNFPBAM (CAN_MSG *pMsg)
{
   #ifdef DB_NO_ENG_CONFIG
    INT16U usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat3);
    if (pMsg->DAT08.ucDat5 == 0xE3)
    {   aDBDisplay[DB_NO_ENG_CONFIG].ssValue = usTemp;
        aDBDisplay[DB_NO_ENG_CONFIG].ucErr   = SAE_NO_ERR;
    }
   #endif
   #if (SAE_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat3);
    usDBmEngineConfig = usTemp;
   #endif
}
#endif

/* ******************************************************************** */
/*                          7: SAE_TX_PGN_CNFPACK                       */
/* ******************************************************************** */
/* ****************************** TX_CNFPACK ************************** */
#ifdef SAE_TX_PGN_CNFPACK
void SAEUpdateTxCNFPACK (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_CNFPACK ************************** */
#ifdef SAE_RX_PGN_CNFPACK
void SAEUpdateRxCNFPACK (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                          8: SAE_TX_PGN_ENGTEMP                       */
/* ******************************************************************** */
/* ****************************** TX_ENGTEMP ************************** */
#ifdef SAE_TX_PGN_ENGTEMP
void SAEUpdateTxENGTEMP (CAN_MSG *pMsg)
{   INT16U usTemp;
    usTemp = usDBmCoolantTemp;
   #if (SAE_6800_SHAN_TUI_ON == 1)
    if (usTemp < mSTCoolantTemp2)
    {   usTemp = mSTCoolantTemp2;
    }
   #endif
    pMsg->DAT08.ucDat0 = (INT08U)((usTemp - (DB_SIGNED_ZERO-400)) / 10);
    pMsg->DAT08.ucDat1 = (INT08U)((usDBmFuelTemp - (DB_SIGNED_ZERO-400)) / 10);
    usTemp             = (INT16U)((INT32U)(usDBmOilTemp - (DB_SIGNED_ZERO-2730)) * 16 / 5);
    pMsg->DAT08.ucDat2 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat3 = SAE_UC_HIGH (usTemp);
}
#endif

/* ****************************** RX_ENGTEMP ************************** */
#ifdef SAE_RX_PGN_ENGTEMP
void SAEUpdateRxENGTEMP (CAN_MSG *pMsg)
{
   #ifdef DB_NO_COOL_TEMP
    INT16U usTemp;
    usTemp = pMsg->DAT08.ucDat0;
    if (usTemp <= 250)
    {   aDBDisplay[DB_NO_COOL_TEMP].ssValue = usTemp - 40;
        aDBDisplay[DB_NO_COOL_TEMP].ucErr   = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_COOL_TEMP].ssValue = 0;
        aDBDisplay[DB_NO_COOL_TEMP].ucErr   = SAE_ERR_INVALID;
    }
   #endif
   #ifdef DB_NO_FUEL_TEMP
   #if (SAE_1000_TWO_FUEL_ON == 0)
    usTemp = pMsg->DAT08.ucDat1;
    if (usTemp <= 250)
    {   aDBDisplay[DB_NO_FUEL_TEMP].ssValue = usTemp - 40;
        aDBDisplay[DB_NO_FUEL_TEMP].ucErr   = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_FUEL_TEMP].ssValue = 0;
        aDBDisplay[DB_NO_FUEL_TEMP].ucErr   = SAE_ERR_INVALID;
    }
   #endif
   #endif
   #ifdef DB_NO_OIL_TEMP
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat3, pMsg->DAT08.ucDat2);
    if (usTemp <= 64255)
    {   aDBDisplay[DB_NO_OIL_TEMP].ssValue  = usTemp / 32 - 273;
        aDBDisplay[DB_NO_OIL_TEMP].ucErr    = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_OIL_TEMP].ssValue  = 0;
        aDBDisplay[DB_NO_OIL_TEMP].ucErr    = SAE_ERR_INVALID;
    }
   #endif
   #if (SAE_4000_COMMON_ON == 1)
    INT16U usTemp;
    usDBmCoolantTemp = (INT16U)(pMsg->DAT08.ucDat0) * 10 + (DB_SIGNED_ZERO-400);
    usDBmFuelTemp    = (INT16U)(pMsg->DAT08.ucDat1) * 10 + (DB_SIGNED_ZERO-400);
    usTemp           = SAE_US_CREAT (pMsg->DAT08.ucDat3, pMsg->DAT08.ucDat2);
    usDBmOilTemp     = (INT16U)((INT32U)usTemp * 5 / 16 + (DB_SIGNED_ZERO-2730));
   #endif
}
#endif

/* ******************************************************************** */
/*                           9: SAE_TX_PGN_LFE                          */
/* ******************************************************************** */
/* ****************************** TX_LFE ****************************** */
#ifdef SAE_TX_PGN_LFE
void SAEUpdateTxLFE (CAN_MSG *pMsg)
{
   #if (SAE_6800_COMMON_ON == 1)
    pMsg->DAT08.ucDat0 = 0;
    pMsg->DAT08.ucDat1 = 0;
    pMsg->DAT08.ucDat2 = 0;
    pMsg->DAT08.ucDat3 = 0;
   #endif
   #if (SAE_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp             = usDBmFuelRate;
    pMsg->DAT08.ucDat0 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat1 = SAE_UC_HIGH (usTemp);
    usTemp             = usDBmFuelEconomy;
    pMsg->DAT08.ucDat2 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat3 = SAE_UC_HIGH (usTemp);
   #endif
}
#endif

/* ****************************** RX_LFE ****************************** */
#ifdef SAE_RX_PGN_LFE
void SAEUpdateRxLFE (CAN_MSG *pMsg)
{
   #ifdef DB_NO_FUEL_RATE
    INT16U usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat1, pMsg->DAT08.ucDat0);
    if (usTemp <= 64255)
    {   aDBDisplay[DB_NO_FUEL_RATE].ssValue = usTemp / 20;
        aDBDisplay[DB_NO_FUEL_RATE].ucErr   = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_FUEL_RATE].ssValue = 0;
        aDBDisplay[DB_NO_FUEL_RATE].ucErr   = SAE_ERR_INVALID;
    }
   #endif
   #ifdef DB_NO_FUEL_ECONOMY
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat3, pMsg->DAT08.ucDat2);
    if (usTemp <= 64255)
    {   aDBDisplay[DB_NO_FUEL_ECONOMY].ssValue = usTemp / 512;
        aDBDisplay[DB_NO_FUEL_ECONOMY].ucErr   = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_FUEL_ECONOMY].ssValue = 0;
        aDBDisplay[DB_NO_FUEL_ECONOMY].ucErr   = SAE_ERR_INVALID;
    }
   #endif
   #if (SAE_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat1, pMsg->DAT08.ucDat0);
    usDBmFuelRate = usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat3, pMsg->DAT08.ucDat2);
    usDBmFuelEconomy = usTemp;
   #endif
}
#endif

/* ******************************************************************** */
/*                           10: SAE_TX_PGN_EFL                         */
/* ******************************************************************** */
/* ****************************** TX_EFL ****************************** */
#ifdef SAE_TX_PGN_EFL
void SAEUpdateTxEFL (CAN_MSG *pMsg)
{
   #if (SAE_6800_COMMON_ON == 1) || (SAE_8000_COMMON_ON == 1)
   #if (SAE_PRESS_RELATIVE_ON == 1)
    pMsg->DAT08.ucDat0 = 0;
    if (usDBmOilPressure > 1000)
    {   pMsg->DAT08.ucDat3 = (INT08U)((usDBmOilPressure - 1000) / 40);
    }   else
    {   pMsg->DAT08.ucDat3 = (INT08U)0;
    }
    pMsg->DAT08.ucDat7 = 0;
   #else
    pMsg->DAT08.ucDat0 = 0;
    pMsg->DAT08.ucDat3 = (INT08U)(usDBmOilPressure / 40);
    pMsg->DAT08.ucDat7 = 0;
   #endif
   #endif
   #if (SAE_6800_SHAN_TUI_ON == 1)
    if((usDBmSwitchEngineStop != 0) ||
       (usDBmEngineStopping   != 0) ||
       (usDBmEngineRunning    != 0) ||
       (usDBmAirHeaterActive  != 0) ||
       (usDBmOilPumpActive    != 0) ||
       (usDBmSwitchClutch     != 0) )
    {   pMsg->DAT08.ucDat7 = 1;
    }   else
    {   pMsg->DAT08.ucDat7 = 0;
    }
   #endif
   #if (SAE_6800_WATER_PUMP_ON == 1)
    if (mWPFuelLevel > 1000)
    {   pMsg->DAT08.ucDat7 = 250;
    }   else
    {   pMsg->DAT08.ucDat7 = (INT08U)(mWPFuelLevel / 4);
    }
   #endif
   #if (SAE_4000_COMMON_ON == 1)
   #if (SAE_PRESS_RELATIVE_ON == 1)
    if (usDBmFuelPressure > 1000)
    {   pMsg->DAT08.ucDat0 = (INT08U)((usDBmFuelPressure - 1000) / 40);
    }   else
    {   pMsg->DAT08.ucDat0 = (INT08U)0;
    }
    if (usDBmOilPressure > 1000)
    {   pMsg->DAT08.ucDat3 = (INT08U)((usDBmOilPressure - 1000) / 40);
    }   else
    {   pMsg->DAT08.ucDat3 = (INT08U)0;
    }
    pMsg->DAT08.ucDat7 = 0;
   #else
    pMsg->DAT08.ucDat0 = (INT08U)(usDBmFuelPressure / 40);
    pMsg->DAT08.ucDat3 = (INT08U)(usDBmOilPressure / 40);
    pMsg->DAT08.ucDat7 = 0;
   #endif
   #endif
}
#endif

/* ****************************** RX_EFL ****************************** */
#ifdef SAE_RX_PGN_EFL
void SAEUpdateRxEFL (CAN_MSG *pMsg)
{
   #ifdef DB_NO_OIL_PRES
    INT16U usTemp;
    usTemp = pMsg->DAT08.ucDat3;
    if (usTemp <= 250)
    {   aDBDisplay[DB_NO_OIL_PRES].ssValue = usTemp * 4;
        aDBDisplay[DB_NO_OIL_PRES].ucErr   = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_OIL_PRES].ssValue = 0;
        aDBDisplay[DB_NO_OIL_PRES].ucErr   = SAE_ERR_INVALID;
    }
   #endif
   #ifdef DB_NO_FUEL_PRES
   #if (SAE_1000_TWO_FUEL_ON == 0)
    usTemp = pMsg->DAT08.ucDat0;
    if (usTemp <= 250)
    {   aDBDisplay[DB_NO_FUEL_PRES].ssValue = usTemp * 4;
        aDBDisplay[DB_NO_FUEL_PRES].ucErr   = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_FUEL_PRES].ssValue = 0;
        aDBDisplay[DB_NO_FUEL_PRES].ucErr   = SAE_ERR_INVALID;
    }
   #endif
   #endif
   #if (SAE_4000_COMMON_ON == 1)
   #if (SAE_PRESS_RELATIVE_ON == 1)
    usDBmFuelPressure = (INT16U)(pMsg->DAT08.ucDat0) * 40 + 1000;
    usDBmOilPressure  = (INT16U)(pMsg->DAT08.ucDat3) * 40 + 1000;
   #else
    usDBmFuelPressure = (INT16U)(pMsg->DAT08.ucDat0) * 40;
    usDBmOilPressure  = (INT16U)(pMsg->DAT08.ucDat3) * 40;
   #endif
   #endif
}
#endif

/* ******************************************************************** */
/*                           11: SAE_TX_PGN_LFC                         */
/* ******************************************************************** */
/* ****************************** TX_LFC ****************************** */
#ifdef SAE_TX_PGN_LFC
void SAEUpdateTxLFC (CAN_MSG *pMsg)
{
   #if (SAE_6800_TBS_ON == 1)
    INT16U usTemp;
    usTemp             = mTBSVoltage;
    pMsg->DAT08.ucDat0 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat1 = SAE_UC_HIGH (usTemp);
    usTemp             = mTBSCurrent;
    pMsg->DAT08.ucDat2 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat3 = SAE_UC_HIGH (usTemp);
    usTemp             = mTBSBattVoltage;
    pMsg->DAT08.ucDat4 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat5 = SAE_UC_HIGH (usTemp);
    usTemp             = (INT16U)((INT32U)(mTBSBattTemp - (DB_SIGNED_ZERO-2730)) * 16 / 5);
    pMsg->DAT08.ucDat6 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat7 = SAE_UC_HIGH (usTemp);
   #endif
   #if (SAE_6800_HUA_WEI_ON == 1)
    INT16U usTemp;
    usTemp             = mHWOilPressure0;
    pMsg->DAT08.ucDat0 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat1 = SAE_UC_HIGH (usTemp);
    usTemp             = mHWFuelLevel;
    pMsg->DAT08.ucDat2 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat3 = SAE_UC_HIGH (usTemp);
    usTemp             = mHWFillerCurrent;
    pMsg->DAT08.ucDat4 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat5 = SAE_UC_HIGH (usTemp);
    usTemp             = mHWSwitchStatus;
    pMsg->DAT08.ucDat6 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat7 = SAE_UC_HIGH (usTemp);
   #endif
   #if (SAE_6800_WATER_PUMP_ON == 1)
    INT16U usTemp;
    usTemp             = mWPBatteryVoltage1;
    pMsg->DAT08.ucDat0 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat1 = SAE_UC_HIGH (usTemp);
    usTemp             = mWPBatteryVoltage2;
    pMsg->DAT08.ucDat2 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat3 = SAE_UC_HIGH (usTemp);
    usTemp             = mWPChargerVoltage1;
    pMsg->DAT08.ucDat4 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat5 = SAE_UC_HIGH (usTemp);
    usTemp             = mWPChargerVoltage2;
    pMsg->DAT08.ucDat6 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat7 = SAE_UC_HIGH (usTemp);
   #endif
   #if (SAE_6800_TWO_FUEL_ON == 1) || (SAE_8000_TWO_FUEL_ON == 1)
    INT16U usTemp;
    usTemp             = usDBmFuelTemp;
    pMsg->DAT08.ucDat0 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat1 = SAE_UC_HIGH (usTemp);
    usTemp             = mTFFuelPress;
    pMsg->DAT08.ucDat2 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat3 = SAE_UC_HIGH (usTemp);
   #endif
    pMsg = pMsg;   
}
#endif

/* ****************************** RX_LFC ****************************** */
#ifdef SAE_RX_PGN_LFC
void SAEUpdateRxLFC (CAN_MSG *pMsg)
{
   #if (SAE_1000_COMMON_ON == 1)
   #if (SAE_1000_TWO_FUEL_ON == 1)
    INT16U usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat1, pMsg->DAT08.ucDat0);
    aDBDisplay[DB_NO_FUEL_TEMP].ssValue = (INT16S)(usTemp - DB_SIGNED_ZERO) / 10;
    aDBDisplay[DB_NO_FUEL_TEMP].ucErr   = SAE_NO_ERR;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat3, pMsg->DAT08.ucDat2);
    if (usTemp >= 1000)
    {   usTemp -= 1000;
    }   else
    {   usTemp  = 0;
    }
    aDBDisplay[DB_NO_FUEL_PRES].ssValue = usTemp / 10;
    aDBDisplay[DB_NO_FUEL_PRES].ucErr   = SAE_NO_ERR;
   #endif
   #endif
    pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                        12: SAE_TX_PGN_DM1SINGLE                      */
/* ******************************************************************** */
/* ****************************** TX_DM1 ****************************** */
#ifdef SAE_TX_PGN_DM1SINGLE
void SAEUpdateTxDM1 (CAN_MSG *pMsg)
{   INT16U usTemp;
    INT32U uiTemp;
    if (SFCheckErrorsToStop() == 0)
    {   pMsg->DAT08.ucDat0  = 0x00;
    }   else
    {   pMsg->DAT08.ucDat0  = 0x10;
    }
    if (SFCheckErrorsToWarn() != 0)
    {   pMsg->DAT08.ucDat0 |= 0x04;
    }
    usTemp = SFGetNextCanTxCode(0);
   #if (SAE_TX_DM1_DM2_SPN_ON == 1)
    uiTemp = SFErrCodeToSpnCode(usTemp);
    pMsg->DAT08.ucDat2  = (INT08U)uiTemp;
    pMsg->DAT08.ucDat3  = (INT08U)(uiTemp >> 8);
    pMsg->DAT08.ucDat4  = (INT08U)(uiTemp >> 11);
    pMsg->DAT08.ucDat4 &= 0xE0;
    pMsg->DAT08.ucDat4 |= SFErrCodeToFmiCode(usTemp);
    pMsg->DAT08.ucDat5  = (INT08U)(uiTemp >> 19);
   #else
    uiTemp = usTemp;
    pMsg->DAT08.ucDat2  = (INT08U)uiTemp;
    pMsg->DAT08.ucDat3  = (INT08U)(uiTemp >> 8);
    pMsg->DAT08.ucDat4  = 0;
    pMsg->DAT08.ucDat5  = 0;
   #endif
}
#endif

/* ****************************** RX_DM1 ****************************** */
#ifdef SAE_RX_PGN_DM1SINGLE
void SAEUpdateRxDM1 (CAN_MSG *pMsg)
{
   #ifdef DB_NO_ACT_FAULT
    INT16U usTemp;
    INT32U uiTemp;
    usDBmStopLampActive = pMsg->DAT08.ucDat0 & 0x30;
    usDBmWarnLampActive = pMsg->DAT08.ucDat0 & 0x0C;
    pMsg->DAT08.ucDat4 &= 0xE0;
    uiTemp  = (INT32U)(pMsg->DAT08.ucDat2) +
             ((INT32U)(pMsg->DAT08.ucDat3) << 8)  +
             ((INT32U)(pMsg->DAT08.ucDat4) << 11) +
             ((INT32U)(pMsg->DAT08.ucDat5) << 19) ;
    if (uiTemp >= (INT32U)520000)
    {   uiTemp -= (INT32U)520000;
    }
    usTemp = (INT16U)uiTemp;
   #if (SAE_IGNORE_SPEED_ERROR == 1)
    if((usTemp == ERR_CODE_CRANK_SENSOR1) ||
       (usTemp == ERR_CODE_CRANK_SENSOR2) ||
       (usTemp == ERR_CODE_VSS_SENSOR) )
    {   usTemp  = 0;
    }
   #endif
   #if (SAE_IGNORE_RACK_ERROR == 1)
    if((usTemp == ERR_CODE_RACK_DELTA) ||
       (usTemp == ERR_CODE_RACK_WAVE ) )
    {   usTemp  = 0;
    }
   #endif
    DBPutFCBufCode(usTemp,0);
    aDBDisplay[DB_NO_ACT_FAULT].ssValue = usTemp;
    aDBDisplay[DB_NO_ACT_FAULT].ucErr   = SAE_NO_ERR;
   #endif
}
#endif

/* ******************************************************************** */
/*                        13: SAE_TX_PGN_DM2SINGLE                      */
/* ******************************************************************** */
/* ****************************** TX_DM2 ****************************** */
#ifdef SAE_TX_PGN_DM2SINGLE
void SAEUpdateTxDM2 (CAN_MSG *pMsg)
{   INT16U usTemp;
    INT32U uiTemp;
    if (SFCheckErrorsToStop() == 0)
    {   pMsg->DAT08.ucDat0  = 0x00;
    }   else
    {   pMsg->DAT08.ucDat0  = 0x20;
    }
    if (SFCheckErrorsToWarn() != 0)
    {   pMsg->DAT08.ucDat0 |= 0x08;
    }
    usTemp = SFGetNextCanTxCode(1);
   #if (SAE_TX_DM1_DM2_SPN_ON == 1)
    uiTemp = SFErrCodeToSpnCode(usTemp);
    pMsg->DAT08.ucDat2  = (INT08U)uiTemp;
    pMsg->DAT08.ucDat3  = (INT08U)(uiTemp >> 8);
    pMsg->DAT08.ucDat4  = (INT08U)(uiTemp >> 11);
    pMsg->DAT08.ucDat4 &= 0xE0;
    pMsg->DAT08.ucDat4 |= SFErrCodeToFmiCode(usTemp);
    pMsg->DAT08.ucDat5  = (INT08U)(uiTemp >> 19);
   #else
    uiTemp = usTemp;
    pMsg->DAT08.ucDat2  = (INT08U)uiTemp;
    pMsg->DAT08.ucDat3  = (INT08U)(uiTemp >> 8);
    pMsg->DAT08.ucDat4  = 0;
    pMsg->DAT08.ucDat5  = 0;
   #endif
}
#endif

/* ****************************** RX_DM2 ****************************** */
#ifdef SAE_RX_PGN_DM2SINGLE
void SAEUpdateRxDM2 (CAN_MSG *pMsg)
{
   #ifdef DB_NO_STO_FAULT
    INT16U usTemp;
    INT32U uiTemp;
    pMsg->DAT08.ucDat4 &= 0xE0;
    uiTemp  = (INT32U)(pMsg->DAT08.ucDat2) +
             ((INT32U)(pMsg->DAT08.ucDat3) << 8)  +
             ((INT32U)(pMsg->DAT08.ucDat4) << 11) +
             ((INT32U)(pMsg->DAT08.ucDat5) << 19) ;
    if (uiTemp >= (INT32U)520000)
    {   uiTemp -= (INT32U)520000;
    }
    usTemp = (INT16U)uiTemp;
   #if (SAE_IGNORE_SPEED_ERROR == 1)
    if((usTemp == ERR_CODE_CRANK_SENSOR1) ||
       (usTemp == ERR_CODE_CRANK_SENSOR2) ||
       (usTemp == ERR_CODE_VSS_SENSOR) )
    {   usTemp  = 0;
    }
   #endif
   #if (SAE_IGNORE_RACK_ERROR == 1)
    if((usTemp == ERR_CODE_RACK_DELTA) ||
       (usTemp == ERR_CODE_RACK_WAVE ) )
    {   usTemp  = 0;
    }
   #endif
    DBPutFCBufCode(usTemp,1);
    aDBDisplay[DB_NO_STO_FAULT].ssValue = usTemp;
    aDBDisplay[DB_NO_STO_FAULT].ucErr   = SAE_NO_ERR;
   #endif
}
#endif

/* ******************************************************************** */
/*                        14: SAE_TX_PGN_DM4SINGLE                      */
/* ******************************************************************** */
/* ****************************** TX_DM4 ****************************** */
#ifdef SAE_TX_PGN_DM4SINGLE
void SAEUpdateTxDM4 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_DM4 ****************************** */
#ifdef SAE_RX_PGN_DM4SINGLE
void SAEUpdateRxDM4 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                         15: SAE_TX_PGN_DM11ACK                       */
/* ******************************************************************** */
/* ****************************** TX_DM11 ***************************** */
#ifdef SAE_TX_PGN_DM11ACK
void SAEUpdateTxDM11ACK (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_DM11 ***************************** */
#ifdef SAE_RX_PGN_DM11ACK
void SAEUpdateRxDM11ACK (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                          16: SAE_TX_PGN_INCON                        */
/* ******************************************************************** */
/* ****************************** TX_INCON **************************** */
#ifdef SAE_TX_PGN_INCON
void SAEUpdateTxINCON (CAN_MSG *pMsg)
{   INT16U usTemp, usPres;
    usTemp = usDBmBoostTemp;
    usPres = usDBmBoostPressure;
   #if (SAE_6800_SHAN_TUI_ON == 1)
    if (usTemp < mSTBoostTemp2)
    {   usTemp = mSTBoostTemp2;
    }
    if (usPres < mSTBoostPressure2)
    {   usPres = mSTBoostPressure2;
    }
   #endif
    pMsg->DAT08.ucDat2 = (INT08U)((usTemp - (DB_SIGNED_ZERO-400)) / 10);
   #if (SAE_PRESS_RELATIVE_ON == 1)
    if (usPres > 1000)
    {   pMsg->DAT08.ucDat3 = (INT08U)((usPres - 1000) / 20);
    }   else
    {   pMsg->DAT08.ucDat3 = (INT08U)0;
    }
   #else
    pMsg->DAT08.ucDat3 = (INT08U)(usPres / 20);
   #endif
   #if (SAE_6800_TWO_FUEL_ON == 1) || (SAE_8000_TWO_FUEL_ON == 1)
    usTemp = usDBmExhaustTemp;
    pMsg->DAT08.ucDat4 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat5 = SAE_UC_HIGH (usTemp);
   #endif
}
#endif

/* ****************************** RX_INCON **************************** */
#ifdef SAE_RX_PGN_INCON
void SAEUpdateRxINCON (CAN_MSG *pMsg)
{
   #ifdef DB_NO_AIR_TEMP
   #if (SAE_1000_TWO_FUEL_ON == 1)
    INT16U usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat5, pMsg->DAT08.ucDat4);
    if (usTemp <= (INT16U)62768)
    {   aDBDisplay[DB_NO_AIR_TEMP].ssValue = (INT16S)(usTemp - DB_SIGNED_ZERO) / 10;
        aDBDisplay[DB_NO_AIR_TEMP].ucErr   = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_AIR_TEMP].ssValue = 0;
        aDBDisplay[DB_NO_AIR_TEMP].ucErr   = SAE_ERR_INVALID;
    }
   #else
    INT16U usTemp;
    usTemp = pMsg->DAT08.ucDat2;
    if (usTemp <= 250)
    {   aDBDisplay[DB_NO_AIR_TEMP].ssValue = usTemp - 40;
        aDBDisplay[DB_NO_AIR_TEMP].ucErr   = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_AIR_TEMP].ssValue = 0;
        aDBDisplay[DB_NO_AIR_TEMP].ucErr   = SAE_ERR_INVALID;
    }
   #endif
   #endif
   #ifdef DB_NO_AIR_PRES
    usTemp = pMsg->DAT08.ucDat3;
    if (usTemp <= 250)
    {   aDBDisplay[DB_NO_AIR_PRES].ssValue = usTemp * 2;
        aDBDisplay[DB_NO_AIR_PRES].ucErr   = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_AIR_PRES].ssValue = 0;
        aDBDisplay[DB_NO_AIR_PRES].ucErr   = SAE_ERR_INVALID;
    }
   #endif
   #if (SAE_4000_COMMON_ON == 1)
   #if (SAE_PRESS_RELATIVE_ON == 1)
    usDBmBoostTemp = (INT16U)(pMsg->DAT08.ucDat2) * 10 + (DB_SIGNED_ZERO-400);
    usDBmBoostPressure = (INT16U)(pMsg->DAT08.ucDat3) * 20 + 1000;
   #else
    usDBmBoostTemp = (INT16U)(pMsg->DAT08.ucDat2) * 10 + (DB_SIGNED_ZERO-400);
    usDBmBoostPressure = (INT16U)(pMsg->DAT08.ucDat3) * 20;
   #endif
   #endif
}
#endif

/* ******************************************************************** */
/*                          17: SAE_TX_PGN_VEHPOW                       */
/* ******************************************************************** */
/* ****************************** TX_VEHPOW *************************** */
#ifdef SAE_TX_PGN_VEHPOW
void SAEUpdateTxVEHPOW (CAN_MSG *pMsg)
{   INT16U usTemp;
    usTemp = (INT16U)((INT32U)usDBmPowerSupply * 220 / 819);
    pMsg->DAT08.ucDat6 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat7 = SAE_UC_HIGH (usTemp);
}
#endif

/* ****************************** RX_VEHPOW *************************** */
#ifdef SAE_RX_PGN_VEHPOW
void SAEUpdateRxVEHPOW (CAN_MSG *pMsg)
{
   #ifdef DB_NO_SYS_VOLT
    INT16U usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat7, pMsg->DAT08.ucDat6);
    if (usTemp <= 64255)
    {   aDBDisplay[DB_NO_SYS_VOLT].ssValue = usTemp / 20;
        aDBDisplay[DB_NO_SYS_VOLT].ucErr = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_SYS_VOLT].ssValue = 0;
        aDBDisplay[DB_NO_SYS_VOLT].ucErr = SAE_ERR_INVALID;
    }
   #endif
   #if (SAE_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat7, pMsg->DAT08.ucDat6);
    usDBmPowerSupply = (INT16U)((INT32U)usTemp * 819 / 220);
   #endif
}
#endif

/* ******************************************************************** */
/*                         18: SAE_TX_PGN_ENGHOUR                       */
/* ******************************************************************** */
/* ****************************** TX_ENGHOUR ************************** */
#ifdef SAE_TX_PGN_ENGHOUR
void SAEUpdateTxENGHOUR (CAN_MSG *pMsg)
{   INT32U uiTemp;
    uiTemp = uiDBmTimer32 / (FW_FRQ_ENGINE_TIMER * 180);
    pMsg->DAT08.ucDat0  = (INT08U)uiTemp;
    pMsg->DAT08.ucDat1  = (INT08U)(uiTemp >> 8);
    pMsg->DAT08.ucDat2  = (INT08U)(uiTemp >> 16);
    pMsg->DAT08.ucDat3  = (INT08U)(uiTemp >> 24);
}
#endif

/* ****************************** RX_ENGHOUR ************************** */
#ifdef SAE_RX_PGN_ENGHOUR
void SAEUpdateRxENGHOUR (CAN_MSG *pMsg)
{
   #ifdef DB_NO_ENG_HOUR
    INT32U uiTemp;
    uiTemp  = (INT32U)(pMsg->DAT08.ucDat0) +
             ((INT32U)(pMsg->DAT08.ucDat1) << 8)  +
             ((INT32U)(pMsg->DAT08.ucDat2) << 16) +
             ((INT32U)(pMsg->DAT08.ucDat3) << 24) ;
    uiTemp /= 20;
    if (uiTemp < (INT32U)0x8000)
    {   aDBDisplay[DB_NO_ENG_HOUR].ssValue = (INT16S)uiTemp;
        aDBDisplay[DB_NO_ENG_HOUR].pUnit   = &eHourUnit[0];
        aDBDisplay[DB_NO_ENG_HOUR].ucErr   = SAE_NO_ERR;
    }   else if (uiTemp < ((INT32U)0x8000 * 10))
    {   uiTemp /= 10;
        aDBDisplay[DB_NO_ENG_HOUR].ssValue = (INT16S)uiTemp;
        aDBDisplay[DB_NO_ENG_HOUR].pUnit   = &eHourUnit2[0];
        aDBDisplay[DB_NO_ENG_HOUR].ucErr   = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_ENG_HOUR].ssValue = (INT16S)0x7FFF;
        aDBDisplay[DB_NO_ENG_HOUR].pUnit   = &eHourUnit2[0];
        aDBDisplay[DB_NO_ENG_HOUR].ucErr   = SAE_ERR_INVALID;
    }
   #endif
   #if (SAE_4000_COMMON_ON == 1)
    INT32U uiTemp;
    uiTemp  = (INT32U)(pMsg->DAT08.ucDat0) +
             ((INT32U)(pMsg->DAT08.ucDat1) << 8)  +
             ((INT32U)(pMsg->DAT08.ucDat2) << 16) +
             ((INT32U)(pMsg->DAT08.ucDat3) << 24) ;
    uiDBmTimer32 = uiTemp * (FW_FRQ_ENGINE_TIMER * 180);
   #endif
}
#endif

/* ******************************************************************** */
/*                         19: SAE_TX_PGN_CRPRESS                       */
/* ******************************************************************** */
/* ****************************** TX_CRPRESS ************************** */
#ifdef SAE_TX_PGN_CRPRESS
void SAEUpdateTxCRPRESS (CAN_MSG *pMsg)
{
   #if (SAE_6800_COMMON_ON == 1)
    pMsg->DAT08.ucDat4 = 0;
    pMsg->DAT08.ucDat5 = 0;
   #endif
   #if (SAE_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = usDBmRailPressure;
    pMsg->DAT08.ucDat4 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat5 = SAE_UC_HIGH (usTemp);
   #endif
}
#endif

/* ****************************** RX_CRPRESS ************************** */
#ifdef SAE_RX_PGN_CRPRESS
void SAEUpdateRxCRPRESS (CAN_MSG *pMsg)
{
   #ifdef DB_NO_RAIL_PRES
    INT16U usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat5, pMsg->DAT08.ucDat4);
    if (usTemp <= 64255)
    {   aDBDisplay[DB_NO_RAIL_PRES].ssValue = usTemp / 100;
        aDBDisplay[DB_NO_RAIL_PRES].ucErr   = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_RAIL_PRES].ssValue = 0;
        aDBDisplay[DB_NO_RAIL_PRES].ucErr   = SAE_ERR_INVALID;
    }
   #endif
   #if (SAE_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat5, pMsg->DAT08.ucDat4);
    usDBmRailPressure = usTemp;
   #endif
}
#endif

/* ******************************************************************** */
/*                           20: SAE_TX_PGN_EBC1                        */
/* ******************************************************************** */
/* ****************************** TX_EBC1 ***************************** */
#ifdef SAE_TX_PGN_EBC1
void SAEUpdateTxEBC1 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_EBC1 ***************************** */
#ifdef SAE_RX_PGN_EBC1
void SAEUpdateRxEBC1 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                           21: SAE_TX_PGN_EBC2                        */
/* ******************************************************************** */
/* ****************************** TX_EBC2 ***************************** */
#ifdef SAE_TX_PGN_EBC2
void SAEUpdateTxEBC2 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_EBC2 ***************************** */
#ifdef SAE_RX_PGN_EBC2
void SAEUpdateRxEBC2 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                           22: SAE_TX_PGN_ETC1                        */
/* ******************************************************************** */
/* ****************************** TX_ETC1 ***************************** */
#ifdef SAE_TX_PGN_ETC1
void SAEUpdateTxETC1 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_ETC1 ***************************** */
#ifdef SAE_RX_PGN_ETC1
void SAEUpdateRxETC1 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                           23: SAE_TX_PGN_RXCCVS                      */
/* ******************************************************************** */
/* ****************************** TX_RXCCVS *************************** */
#ifdef SAE_TX_PGN_RXCCVS
void SAEUpdateTxRXCCVS (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_RXCCVS *************************** */
#ifdef SAE_RX_PGN_RXCCVS
void SAEUpdateRxRXCCVS (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                            24: SAE_TX_PGN_HRVD                       */
/* ******************************************************************** */
/* ****************************** TX_HRVD ***************************** */
#ifdef SAE_TX_PGN_HRVD
void SAEUpdateTxHRVD (CAN_MSG *pMsg)
{   INT32U uiTemp;
    uiTemp = uiDBmMiles32;
    pMsg->DAT08.ucDat0 = (INT08U)uiTemp;
    pMsg->DAT08.ucDat1 = (INT08U)(uiTemp >> 8);
    pMsg->DAT08.ucDat2 = (INT08U)(uiTemp >> 16);
    pMsg->DAT08.ucDat3 = (INT08U)(uiTemp >> 24);
}
#endif

/* ****************************** RX_HRVD ***************************** */
#ifdef SAE_RX_PGN_HRVD
void SAEUpdateRxHRVD (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                           25: SAE_TX_PGN_PGNRQ                       */
/* ******************************************************************** */
/* ****************************** TX_PGNRQ **************************** */
#ifdef SAE_TX_PGN_PGNRQ
void SAEUpdateTxPGNRQ (CAN_MSG *pMsg)
{   static INT08U ucSAETxFlagPGNRQ = 0;
    if (ucSAETxFlagPGNRQ == 0)
    {   ucSAETxFlagPGNRQ  = 4;
    }   else
    {   ucSAETxFlagPGNRQ  = 0;
    }
    if (ucSAETxFlagPGNRQ == 0)
    {   pMsg->DAT08.ucDat0 = 0xCB;
    }   else if (ucSAETxFlagPGNRQ == 1)
    {   pMsg->DAT08.ucDat0 = 0xCD;
    }   else if (ucSAETxFlagPGNRQ == 2)
    {   pMsg->DAT08.ucDat0 = 0xD3;
    }   else if (ucSAETxFlagPGNRQ == 3)
    {   pMsg->DAT08.ucDat0 = 0x00;
    }   else if (ucSAETxFlagPGNRQ == 4)
    {   pMsg->DAT08.ucDat0 = 0xE5;
    }   else if (ucSAETxFlagPGNRQ == 5)
    {   pMsg->DAT08.ucDat0 = 0xE9;
    }   else if (ucSAETxFlagPGNRQ == 6)
    {   pMsg->DAT08.ucDat0 = 0xDA;
    }   else if (ucSAETxFlagPGNRQ == 7)
    {   pMsg->DAT08.ucDat0 = 0xEB;
    }   else
    {   pMsg->DAT08.ucDat0 = 0x00;
    }
    pMsg->DAT08.ucDat1 = 0xFE;
    pMsg->DAT08.ucDat2 = 0x00;
}
#endif

/* ****************************** RX_PGNRQ **************************** */
#ifdef SAE_RX_PGN_PGNRQ
void SAEUpdateRxPGNRQ (CAN_MSG *pMsg)
{   INT08U ucFlag = 8;
    if ((pMsg->DAT08.ucDat1 == 0xFE) && (pMsg->DAT08.ucDat2 == 0x00))
    {   if (pMsg->DAT08.ucDat0 == 0xCB)
        {   ucFlag = 0;
        }   else if (pMsg->DAT08.ucDat0 == 0xCD)
        {   ucFlag = 1;
        }   else if (pMsg->DAT08.ucDat0 == 0xD3)
        {   ucFlag = 2;
        }   else if (pMsg->DAT08.ucDat0 == 0x00)
        {   ucFlag = 3;
        }   else if (pMsg->DAT08.ucDat0 == 0xE5)
        {   ucFlag = 4;
        }   else if (pMsg->DAT08.ucDat0 == 0xE9)
        {   ucFlag = 5;
        }   else if (pMsg->DAT08.ucDat0 == 0xDA)
        {   ucFlag = 6;
        }   else if (pMsg->DAT08.ucDat0 == 0xEB)
        {   ucFlag = 7;
        }
    }
    if (0) {;}
   #ifdef SAE_TX_PGN_DM2SINGLE
    else if (ucFlag == 0)
    {   if (sSAETxPgnTbl[SAE_TX_PGN_DM2SINGLE].ucEnable != SAE_DISABLE)
        {   sSAETxPgnTbl[SAE_TX_PGN_DM2SINGLE].ucState = SAE_CODE_IMMED;
        }
    }
   #endif
   #ifdef SAE_TX_PGN_DM4SINGLE
    else if (ucFlag == 1)
    {   if (sSAETxPgnTbl[SAE_TX_PGN_DM4SINGLE].ucEnable != SAE_DISABLE)
        {   sSAETxPgnTbl[SAE_TX_PGN_DM4SINGLE].ucState = SAE_CODE_IMMED;
        }
    }
   #endif
   #ifdef SAE_TX_PGN_DM11SINGLE
    else if (ucFlag == 2)
    {   if (sSAETxPgnTbl[SAE_TX_PGN_DM11SINGLE].ucEnable != SAE_DISABLE)
        {   sSAETxPgnTbl[SAE_TX_PGN_DM11SINGLE].ucState = SAE_CODE_IMMED;
        }
    }
   #endif
   #ifdef SAE_TX_PGN_ENGHOUR
    else if (ucFlag == 4)
    {   if (sSAETxPgnTbl[SAE_TX_PGN_ENGHOUR].ucEnable != SAE_DISABLE)
        {   sSAETxPgnTbl[SAE_TX_PGN_ENGHOUR].ucState = SAE_CODE_IMMED;
        }
    }
   #endif
}
#endif

/* ******************************************************************** */
/*                          26: SAE_TX_PGN_RXAMCON                      */
/* ******************************************************************** */
/* ****************************** TX_RXAMCON ************************** */
#ifdef SAE_TX_PGN_RXAMCON
void SAEUpdateTxRXAMCON (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_RXAMCON ************************** */
#ifdef SAE_RX_PGN_RXAMCON
void SAEUpdateRxRXAMCON (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                            27: SAE_TX_PGN_TCO1                       */
/* ******************************************************************** */
/* ****************************** TX_TCO1 ***************************** */
#ifdef SAE_TX_PGN_TCO1
void SAEUpdateTxTCO1 (CAN_MSG *pMsg)
{   INT16U usTemp;
    usTemp = (INT16U)((INT32U)usDBmVeSpeed * 128 / 5);
    pMsg->DAT08.ucDat6 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat7 = SAE_UC_HIGH (usTemp);
}
#endif

/* ****************************** RX_TCO1 ***************************** */
#ifdef SAE_RX_PGN_TCO1
void SAEUpdateRxTCO1 (CAN_MSG *pMsg)
{
   #ifdef DB_NO_VEH_SPEED
    INT16U usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat7, pMsg->DAT08.ucDat6);
    if (usTemp <= 64255)
    {   aDBDisplay[DB_NO_VEH_SPEED].ssValue = usTemp / 256;
        aDBDisplay[DB_NO_VEH_SPEED].ucErr   = SAE_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_VEH_SPEED].ssValue = 0;
        aDBDisplay[DB_NO_VEH_SPEED].ucErr   = SAE_ERR_INVALID;
    }
   #endif
   #if (SAE_6800_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat7, pMsg->DAT08.ucDat6);
    usDBmVeSpeed = (INT16U)((INT32U)usTemp * 5 / 128);
   #endif
   #if (SAE_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = SAE_US_CREAT (pMsg->DAT08.ucDat7, pMsg->DAT08.ucDat6);
    usDBmVeSpeed = (INT16U)((INT32U)usTemp * 5 / 128);
   #endif
}
#endif

/* ******************************************************************** */
/*                           28: SAE_TX_PGN_TSC1AE                      */
/* ******************************************************************** */
/* ****************************** TX_TSC1AE *************************** */
#ifdef SAE_TX_PGN_TSC1AE
void SAEUpdateTxTSC1AE (CAN_MSG *pMsg)
{
   #if (SAE_6800_TWO_FUEL_ON == 1) || (SAE_8000_TWO_FUEL_ON == 1)
    INT16U usTemp;
    usTemp = mTFTxGasQuantity * 2;
    pMsg->DAT08.ucDat0 = 0;
    pMsg->DAT08.ucDat1 = SAE_UC_LOW (usTemp);
    pMsg->DAT08.ucDat2 = SAE_UC_HIGH (usTemp);
    pMsg->DAT08.ucDat3 = 0;
    pMsg->DAT08.ucDat4 = 0;
    pMsg->DAT08.ucDat5 = 0;
    pMsg->DAT08.ucDat6 = 0;
    pMsg->DAT08.ucDat7 = 0;
   #else
    pMsg->DAT08.ucDat0 = 0;
    pMsg->DAT08.ucDat1 = 0;
    pMsg->DAT08.ucDat2 = 0;
    pMsg->DAT08.ucDat3 = 0;
    pMsg->DAT08.ucDat4 = 0;
    pMsg->DAT08.ucDat5 = 0;
    pMsg->DAT08.ucDat6 = 0;
    pMsg->DAT08.ucDat7 = 0;
   #endif
}
#endif

/* ****************************** RX_TSC1AE *************************** */
#ifdef SAE_RX_PGN_TSC1AE
void SAEUpdateRxTSC1AE (CAN_MSG *pMsg)
{   INT16U usTemp;
    usDBmCanSetpoint1 = SAE_US_CREAT (pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat1);
    usDBmCanSetpoint2 = SAE_US_CREAT (pMsg->DAT08.ucDat7, pMsg->DAT08.ucDat6);
    usDBmCanSetpoint3 = SAE_US_CREAT (pMsg->DAT08.ucDat3, pMsg->DAT08.ucDat0);
    usTemp            = SAE_US_CREAT (pMsg->DAT08.ucDat5, pMsg->DAT08.ucDat4);
    usTemp           &= 0x7FFF;
    if (usDBmCanSetpoint1 == 0)
    {   usTemp       |= 0x8000;
    }
    usDBmCanBinaryIn  = usTemp;
}
#endif

/* ******************************************************************** */
/*                           29: SAE_TX_PGN_TSC1DE                      */
/* ******************************************************************** */
/* ****************************** TX_TSC1DE *************************** */
#ifdef SAE_TX_PGN_TSC1DE
void SAEUpdateTxTSC1DE (CAN_MSG *pMsg)
{   pMsg->DAT08.ucDat0 = 0;
    pMsg->DAT08.ucDat1 = 0;
    pMsg->DAT08.ucDat2 = 0;
    pMsg->DAT08.ucDat3 = 0;
    pMsg->DAT08.ucDat4 = 0;
    pMsg->DAT08.ucDat5 = 0;
    pMsg->DAT08.ucDat6 = 0;
    pMsg->DAT08.ucDat7 = 0;
}
#endif

/* ****************************** RX_TSC1DE *************************** */
#ifdef SAE_RX_PGN_TSC1DE
void SAEUpdateRxTSC1DE (CAN_MSG *pMsg)
{   INT16U usTemp;
    usDBmCanSetpoint1 = SAE_US_CREAT (pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat1);
    usDBmCanSetpoint2 = SAE_US_CREAT (pMsg->DAT08.ucDat7, pMsg->DAT08.ucDat6);
    usDBmCanSetpoint3 = SAE_US_CREAT (pMsg->DAT08.ucDat3, pMsg->DAT08.ucDat0);
    usTemp            = SAE_US_CREAT (pMsg->DAT08.ucDat5, pMsg->DAT08.ucDat4);
    usTemp           &= 0x7FFF;
    if (usDBmCanSetpoint1 == 0)
    {   usTemp       |= 0x8000;
    }
    usDBmCanBinaryIn  = usTemp;
}
#endif

/* ******************************************************************** */
/*                           30: SAE_TX_PGN_TSC1PE                      */
/* ******************************************************************** */
/* ****************************** TX_TSC1PE *************************** */
#ifdef SAE_TX_PGN_TSC1PE
void SAEUpdateTxTSC1PE (CAN_MSG *pMsg)
{   pMsg->DAT08.ucDat0 = 0;
    pMsg->DAT08.ucDat1 = 0;
    pMsg->DAT08.ucDat2 = 0;
    pMsg->DAT08.ucDat3 = 0;
    pMsg->DAT08.ucDat4 = 0;
    pMsg->DAT08.ucDat5 = 0;
    pMsg->DAT08.ucDat6 = 0;
    pMsg->DAT08.ucDat7 = 0;
}
#endif

/* ****************************** RX_TSC1PE *************************** */
#ifdef SAE_RX_PGN_TSC1PE
void SAEUpdateRxTSC1PE (CAN_MSG *pMsg)
{   INT16U usTemp;
    usDBmCanSetpoint1 = SAE_US_CREAT (pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat1);
    usDBmCanSetpoint2 = SAE_US_CREAT (pMsg->DAT08.ucDat7, pMsg->DAT08.ucDat6);
    usDBmCanSetpoint3 = SAE_US_CREAT (pMsg->DAT08.ucDat3, pMsg->DAT08.ucDat0);
    usTemp            = SAE_US_CREAT (pMsg->DAT08.ucDat5, pMsg->DAT08.ucDat4);
    usTemp           &= 0x7FFF;
    if (usDBmCanSetpoint1 == 0)
    {   usTemp       |= 0x8000;
    }
    usDBmCanBinaryIn  = usTemp;
}
#endif

/* ******************************************************************** */
/*                           31: SAE_TX_PGN_TSC1TE                      */
/* ******************************************************************** */
/* ****************************** TX_TSC1TE *************************** */
#ifdef SAE_TX_PGN_TSC1TE
void SAEUpdateTxTSC1TE (CAN_MSG *pMsg)
{   pMsg->DAT08.ucDat0 = 0;
    pMsg->DAT08.ucDat1 = 0;
    pMsg->DAT08.ucDat2 = 0;
    pMsg->DAT08.ucDat3 = 0;
    pMsg->DAT08.ucDat4 = 0;
    pMsg->DAT08.ucDat5 = 0;
    pMsg->DAT08.ucDat6 = 0;
    pMsg->DAT08.ucDat7 = 0;
}
#endif

/* ****************************** RX_TSC1TE *************************** */
#ifdef SAE_RX_PGN_TSC1TE
void SAEUpdateRxTSC1TE (CAN_MSG *pMsg)
{   INT16U usTemp;
    usDBmCanSetpoint1 = SAE_US_CREAT (pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat1);
    usDBmCanSetpoint2 = SAE_US_CREAT (pMsg->DAT08.ucDat7, pMsg->DAT08.ucDat6);
    usDBmCanSetpoint3 = SAE_US_CREAT (pMsg->DAT08.ucDat3, pMsg->DAT08.ucDat0);
    usTemp            = SAE_US_CREAT (pMsg->DAT08.ucDat5, pMsg->DAT08.ucDat4);
    usTemp           &= 0x7FFF;
    if (usDBmCanSetpoint1 == 0)
    {   usTemp       |= 0x8000;
    }
    usDBmCanBinaryIn  = usTemp;
}
#endif

/* ******************************************************************** */
/*                           32: SAE_TX_PGN_TSC1VE                      */
/* ******************************************************************** */
/* ****************************** TX_TSC1VE *************************** */
#ifdef SAE_TX_PGN_TSC1VE
void SAEUpdateTxTSC1VE (CAN_MSG *pMsg)
{   pMsg->DAT08.ucDat0 = 0;
    pMsg->DAT08.ucDat1 = 0;
    pMsg->DAT08.ucDat2 = 0;
    pMsg->DAT08.ucDat3 = 0;
    pMsg->DAT08.ucDat4 = 0;
    pMsg->DAT08.ucDat5 = 0;
    pMsg->DAT08.ucDat6 = 0;
    pMsg->DAT08.ucDat7 = 0;
}
#endif

/* ****************************** RX_TSC1VE *************************** */
#ifdef SAE_RX_PGN_TSC1VE
void SAEUpdateRxTSC1VE (CAN_MSG *pMsg)
{   INT16U usTemp;
    usDBmCanSetpoint1 = SAE_US_CREAT (pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat1);
    usDBmCanSetpoint2 = SAE_US_CREAT (pMsg->DAT08.ucDat7, pMsg->DAT08.ucDat6);
    usDBmCanSetpoint3 = SAE_US_CREAT (pMsg->DAT08.ucDat3, pMsg->DAT08.ucDat0);
    usTemp            = SAE_US_CREAT (pMsg->DAT08.ucDat5, pMsg->DAT08.ucDat4);
    usTemp           &= 0x7FFF;
    if (usDBmCanSetpoint1 == 0)
    {   usTemp       |= 0x8000;
    }
    usDBmCanBinaryIn  = usTemp;
}
#endif

/* ******************************************************************** */
/*                            33: SAE_TX_PGN_DM13                       */
/* ******************************************************************** */
/* ****************************** TX_DM13 ***************************** */
#ifdef SAE_TX_PGN_DM13
void SAEUpdateTxDM13 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_DM13 ***************************** */
#ifdef SAE_RX_PGN_DM13
void SAEUpdateRxDM13 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                            34: SAE_TX_PGN_DEC1                       */
/* ******************************************************************** */
/* ****************************** TX_DEC1 ***************************** */
#ifdef SAE_TX_PGN_DEC1
void SAEUpdateTxDEC1 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_DEC1 ***************************** */
#ifdef SAE_RX_PGN_DEC1
void SAEUpdateRxDEC1 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                          35: SAE_TX_PGN_CCP10REQ                     */
/* ******************************************************************** */
/* ****************************** TX_CCPREQ *************************** */
#ifdef SAE_TX_PGN_CCP10REQ
void SAEUpdateTxCCPREQ (CAN_MSG *pMsg)
{
   #if (SAE_CCP_CCP10_ON == 1)
    (void)CCP10FillMsgTxReq(pMsg);
   #endif
}
#endif

/* ****************************** RX_CCPREQ *************************** */
#ifdef SAE_RX_PGN_CCP10REQ
void SAEUpdateRxCCPREQ (CAN_MSG *pMsg)
{
   #if (SAE_CCP_CCP10_ON == 1)
    if (CCP10DecodeRxReq(pMsg) != CCP_FALSE)
    {   SAE_SET_TXPGN_IMMED(SAE_TX_PGN_CCP10PAR);
    }
   #endif
}
#endif

/* ******************************************************************** */
/*                          36: SAE_TX_PGN_CCP10PAR                     */
/* ******************************************************************** */
/* ****************************** TX_CCPPAR *************************** */
#ifdef SAE_TX_PGN_CCP10PAR
void SAEUpdateTxCCPPAR (CAN_MSG *pMsg)
{
   #if (SAE_CCP_CCP10_ON == 1)
    (void)CCP10FillMsgTxPar(pMsg);
   #endif
}
#endif

/* ****************************** RX_CCPPAR *************************** */
#ifdef SAE_RX_PGN_CCP10PAR
void SAEUpdateRxCCPPAR (CAN_MSG *pMsg)
{
   #if (SAE_CCP_CCP10_ON == 1)
    (void)CCP10DecodeRxPar(pMsg);
   #endif
}
#endif

/* ******************************************************************** */
/*                          37: SAE_TX_PGN_ECULOCK                      */
/* ******************************************************************** */
/* ****************************** TX_ECULOCK ************************** */
#ifdef SAE_TX_PGN_ECULOCK
void SAEUpdateTxEcuLock (CAN_MSG *pMsg)
{   pMsg->DAT08.ucDat0 = (INT08U)mSTEcuLockCode;
}
#endif

/* ****************************** RX_ECULOCK ************************** */
#ifdef SAE_RX_PGN_ECULOCK
void SAEUpdateRxEcuLock (CAN_MSG *pMsg)
{   mSTEcuLockCode = (INT16U)(pMsg->DAT08.ucDat0);
}
#endif

/* ******************************************************************** */
/*                          38: SAE_TX_PGN_SLAVEERR                     */
/* ******************************************************************** */
/* ****************************** TX_SLAVEERR ************************* */
#ifdef SAE_TX_PGN_SLAVEERR
void SAEUpdateTxSlaveErr (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_SLAVEERR ************************* */
#ifdef SAE_RX_PGN_SLAVEERR
void SAEUpdateRxSlaveErr (CAN_MSG *pMsg)
{   mTFRxSlaveError = (INT16U)(pMsg->DAT08.ucDat0 & 0x30);
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */