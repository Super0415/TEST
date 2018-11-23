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
{   uiDBStatus = 0;
    DBCmdBufInit();
    DBInitDFlash();
    if (DBEepReadParam(&aDBParam[0],
                       DB_PARAM_ADDR, DB_PARAM_SIZE) == DB_FALSE)
    {   DB_STS_SET_BIT(DB_STS_ERR_READ_PARAM);
    }   else
    {   DB_STS_CLR_BIT(DB_STS_ERR_READ_PARAM);
    }
    if (DBEepReadParam(&aDBFunct[0],
                       DB_FUNCT_ADDR, DB_FUNCT_SIZE) == DB_FALSE)
    {   DB_STS_SET_BIT(DB_STS_ERR_READ_FUNCT);
    }   else
    {   DB_STS_CLR_BIT(DB_STS_ERR_READ_FUNCT);
    }
    if (DBEepReadParam(&aDBCurve[0],
                       DB_CURVE_ADDR, DB_CURVE_SIZE) == DB_FALSE)
    {   DB_STS_SET_BIT(DB_STS_ERR_READ_CURVE);
    }   else
    {   DB_STS_CLR_BIT(DB_STS_ERR_READ_CURVE);
    }
    if (DBCheckParam() == DB_FALSE)
    {   DB_STS_SET_BIT(DB_STS_ERR_CHECK_PARAM);
        DBResetParam();
    }   else
    {   DB_STS_CLR_BIT(DB_STS_ERR_CHECK_PARAM);
    }
    if (DBCheckFunct() == DB_FALSE)
    {   DB_STS_SET_BIT(DB_STS_ERR_CHECK_FUNCT);
        DBResetFunct();
    }   else
    {   DB_STS_CLR_BIT(DB_STS_ERR_CHECK_FUNCT);
    }
    if (DBCheckCurve() == DB_FALSE)
    {   DB_STS_SET_BIT(DB_STS_ERR_CHECK_CURVE);
        DBResetCurve();
    }   else
    {   DB_STS_CLR_BIT(DB_STS_ERR_CHECK_CURVE);
    }
    DBEepInitHstryBlock();
    if (sDBHstryBlck.uiStatus == DB_BLOCK_STS_FAULT)
    {   DB_STS_SET_BIT(DB_STS_ERR_READ_HSTRY);
    }   else
    {   DB_STS_CLR_BIT(DB_STS_ERR_READ_HSTRY);
    }
    if (DBCheckHstry() == DB_FALSE)
    {   DB_STS_SET_BIT(DB_STS_ERR_CHECK_HSTRY);
        DBResetHstry();
    }   else
    {   DB_STS_CLR_BIT(DB_STS_ERR_CHECK_HSTRY);
    }
		if(TESTZCnum[47])
		{
			TESTZCnum[47] = 0;
		  (void)SFFill16u(&aDBParam[0],0,DB_PARAM_SIZE);
			(void)SFFill16u(&aDBFunct[0],0,DB_FUNCT_SIZE);
			(void)SFFill16u(&aDBCurve[0],0,DB_CURVE_SIZE);
		}
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
        if(usDBmSysBackup == 1)
				{
				    usDBmSysBackup = 0;
					  (void)DBTskPutCmd(DB_CMD_SAVE_PARAM);
					  (void)DBTskPutCmd(DB_CMD_SAVE_HSTRY);
						(void)DBTskPutCmd(DB_CMD_SAVE_FUNCT);
						(void)DBTskPutCmd(DB_CMD_SAVE_CURVE);
						(void)DBTskPutCmd(DB_CMD_POWER_OFF);
				}
				else if(usDBmSysBackup == 2)  //清除485缓存报文数据
				{
						usDBmSysBackup = 0;
						(void)SFFill16u(aDBUSARTHstry,0,DB_USARTHSTRY_SIZE);
				}
				else if(usDBmSysBackup == 3)  //清除CAN缓存报文数据
				{
						usDBmSysBackup = 0;
						(void)SFFill16u(aDBCANHstry,0,DB_CANHSTRY_SIZE);
				}
				
  			ucComd = DBTskGetCmd (DB_CMD_TO_TICKS, &ucErr);
        if((ucErr == DB_NO_ERR) && (ucComd == DB_CMD_POWER_OFF))
        {   

            (void)FWWatchdogFeed();
            if (DB_STS_GET_BIT(DB_STS_SAVE_PARAM) != 0)
            {   DB_STS_CLR_BIT(DB_STS_SAVE_PARAM);
                DBFlashErasePage(DB_PARAM_ADDR);
                if (DBEepWriteParam(&aDBParam[0],
                                    DB_PARAM_ADDR, DB_PARAM_SIZE) == DB_FALSE)
                {   DB_STS_SET_BIT(DB_STS_ERR_WRITE_PARAM);
                }   else
                {   DB_STS_CLR_BIT(DB_STS_ERR_WRITE_PARAM);
                }
                (void)FWWatchdogFeed();
            }
            if (DB_STS_GET_BIT(DB_STS_SAVE_FUNCT) != 0)
            {   DB_STS_CLR_BIT(DB_STS_SAVE_FUNCT);
                DBFlashErasePage(DB_FUNCT_ADDR);
                if (DBEepWriteParam(&aDBFunct[0],
                                    DB_FUNCT_ADDR, DB_FUNCT_SIZE) == DB_FALSE)
                {   DB_STS_SET_BIT(DB_STS_ERR_WRITE_FUNCT);
                }   else
                {   DB_STS_CLR_BIT(DB_STS_ERR_WRITE_FUNCT);
                }
                (void)FWWatchdogFeed();
            }
            if (DB_STS_GET_BIT(DB_STS_SAVE_CURVE) != 0)
            {   DB_STS_CLR_BIT(DB_STS_SAVE_CURVE);
                DBFlashErasePage(DB_CURVE_ADDR);
                if (DBEepWriteParam(&aDBCurve[0],
                                    DB_CURVE_ADDR, DB_CURVE_SIZE) == DB_FALSE)
                {   DB_STS_SET_BIT(DB_STS_ERR_WRITE_CURVE);
                }   else
                {   DB_STS_CLR_BIT(DB_STS_ERR_WRITE_CURVE);
                }
                (void)FWWatchdogFeed();
            }
            if (DB_STS_GET_BIT(DB_STS_SAVE_HSTRY) != 0)
            {   DB_STS_CLR_BIT(DB_STS_SAVE_HSTRY);
                DBEepWriteRecord(&sDBHstryBlck, &aDBHstry[0]);
                (void)FWWatchdogFeed();
            }

            (void)FWWatchdogFeed();
        }
    }
}

/* ******************************************************************** */
/*                            DBCheckParam()                            */
/* ******************************************************************** */
INT08U DBCheckParam (void)
{  
    return DB_TRUE;
}

/* ******************************************************************** */
/*                            DBResetParam()                            */
/* ******************************************************************** */
void DBResetParam (void)
{   /* ************** Part 1: Grid Electric Parameters **************** */
   
}

/* ******************************************************************** */
/*                            DBCheckFunct()                            */
/* ******************************************************************** */
INT08U DBCheckFunct (void)
{   
    return DB_TRUE;
}

/* ******************************************************************** */
/*                            DBResetFunct()                            */
/* ******************************************************************** */
void DBResetFunct (void)
{   (void)SFFill16u(&aDBFunct[0],0,DB_FUNCT_SIZE);
}

/* ******************************************************************** */
/*                            DBCheckCurve()                            */
/* ******************************************************************** */
INT08U DBCheckCurve (void)
{  
    return DB_TRUE;
}

/* ******************************************************************** */
/*                            DBResetCurve()                            */
/* ******************************************************************** */
void DBResetCurve (void)
{   (void)SFFill16u(&aDBCurve[0],0,DB_CURVE_SIZE);
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
   #if (DB_CPU_STM32F1_XL_ON == 1)
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
#if (DB_CPU_STM32F1_XL_ON == 1)
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
#if (DB_CPU_STM32F1_XL_ON == 1)
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
#if (DB_CPU_STM32F1_XL_ON == 1)
INT32U DBFlashErasePage (INT32U uiAddr)
{   INT32U uiStatus;
    if (DBFlashIsPageErased(uiAddr) != DB_FALSE)
    {   return DB_FLASH_STS_COMPLETE;
    }
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
    if (DBFlashIsPageErased(uiAddr) != DB_FALSE)
    {   return DB_FLASH_STS_COMPLETE;
    }
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
/*                        DBFlashIsPageErased()                         */
/* ******************************************************************** */
INT08U DBFlashIsPageErased (INT32U uiAddr)
{   VINT32U  *pData;
    INT32U    uiSize;
    pData  = (VINT32U*)(uiAddr & DB_FLASH_PAGE_MSK);
    uiSize = (DB_FLASH_PAGE_SIZ / 4) / 8;
    while (uiSize--)
    {   if (*pData++ != 0xFFFFFFFF)
        {   return DB_FALSE;
        }
        if (*pData++ != 0xFFFFFFFF)
        {   return DB_FALSE;
        }
        if (*pData++ != 0xFFFFFFFF)
        {   return DB_FALSE;
        }
        if (*pData++ != 0xFFFFFFFF)
        {   return DB_FALSE;
        }
        if (*pData++ != 0xFFFFFFFF)
        {   return DB_FALSE;
        }
        if (*pData++ != 0xFFFFFFFF)
        {   return DB_FALSE;
        }
        if (*pData++ != 0xFFFFFFFF)
        {   return DB_FALSE;
        }
        if (*pData++ != 0xFFFFFFFF)
        {   return DB_FALSE;
        }
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                          DBFlashWrite16u()                           */
/* ******************************************************************** */
#if (DB_CPU_STM32F1_XL_ON == 1)
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
    if (c == DB_CMD_SAVE_PARAM)
    {   DB_STS_SET_BIT(DB_STS_SAVE_PARAM);
        return;
    }
    if (c == DB_CMD_SAVE_FUNCT)
    {   DB_STS_SET_BIT(DB_STS_SAVE_FUNCT);
        return;
    }
    if (c == DB_CMD_SAVE_CURVE)
    {   DB_STS_SET_BIT(DB_STS_SAVE_CURVE);
        return;
    }
    if (c == DB_CMD_SAVE_HSTRY)
    {   DB_STS_SET_BIT(DB_STS_SAVE_HSTRY);
        return;
    }
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
/*                           DBGetParam16u ()                           */
/* ******************************************************************** */
INT16U DBGetParam16u (INT16U usBegin)
{   if (usBegin < DB_PARAM_SIZE)
    {   return aDBParam[usBegin];
    }   else
    {   return 0;
    }
}

/* ******************************************************************** */
/*                           DBGetParam16p ()                           */
/* ******************************************************************** */
INT08U DBGetParam16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_PARAM_SIZE)
    {   return DB_FALSE;
    }
    SFCopy16u(&aDBParam[usBegin], pDat, usSize);
    return DB_TRUE;
}

/* ******************************************************************** */
/*                        DBGetParamAndSum16p ()                        */
/* ******************************************************************** */
INT16U DBGetParamAndSum16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_PARAM_SIZE)
    {   return 0;
    }
    return SFCopyAndSum16u(&aDBParam[usBegin], pDat, usSize);
}

/* ******************************************************************** */
/*                           DBGetParam08p ()                           */
/* ******************************************************************** */
INT08U DBGetParam08p (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT16U usTemp;
    if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_PARAM_SIZE)
    {   return DB_FALSE;
    }
    while (usSize--)
    {   usTemp  = aDBParam[usBegin++];
       #if (DB_SCI_UC_LOW_FIRST == 1)
        *pDat++ = DB_UC_LOW(usTemp);
        *pDat++ = DB_UC_HIGH(usTemp);
       #else
        *pDat++ = DB_UC_HIGH(usTemp);
        *pDat++ = DB_UC_LOW(usTemp);
       #endif
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetParam16u ()                           */
/* ******************************************************************** */
INT08U DBSetParam16u (INT16U usBegin, INT16U usValue)
{   if (usBegin < DB_PARAM_SIZE)
    {   aDBParam[usBegin] = usValue;
        return DB_TRUE;
    }
    return DB_FALSE;
}

/* ******************************************************************** */
/*                           DBSetParam16p ()                           */
/* ******************************************************************** */
INT08U DBSetParam16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_PARAM_SIZE)
    {   return DB_FALSE;
    }
    SFCopy16u(pDat, &aDBParam[usBegin], usSize);
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetParam08p ()                           */
/* ******************************************************************** */
INT08U DBSetParam08p (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT08U ucTmp1, ucTmp2;
    if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_PARAM_SIZE)
    {   return DB_FALSE;
    }
    while (usSize--)
    {   ucTmp1 = *pDat++;
        ucTmp2 = *pDat++;
       #if (DB_SCI_UC_LOW_FIRST == 1)
        aDBParam[usBegin++] = DB_US_CREAT(ucTmp2, ucTmp1);
       #else
        aDBParam[usBegin++] = DB_US_CREAT(ucTmp1, ucTmp2);
       #endif
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBCheckParam16u ()                         */
/* ******************************************************************** */
INT08U DBCheckParam16u (INT16U usBegin, INT16U usValue)
{   if (usBegin >= DB_PARAM_SIZE)
    {   return DB_RANGE_OUT;
    }
    if (aDBParam[usBegin] != usValue)
    {   return DB_DIFFERENT;
    }
    return DB_SAME;
}

/* ******************************************************************** */
/*                           DBCheckParam16p ()                         */
/* ******************************************************************** */
INT08U DBCheckParam16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_PARAM_SIZE)
    {   return DB_RANGE_OUT;
    }
    return SFCompare16u(pDat, &aDBParam[usBegin], usSize);
}

/* ******************************************************************** */
/*                           DBGetMeasu16u ()                           */
/* ******************************************************************** */
INT16U DBGetMeasu16u (INT16U usBegin)
{   if (usBegin < DB_MEASU_SIZE)
    {   return aDBMeasu[usBegin];
    }   else
    {   return 0;
    }
}

/* ******************************************************************** */
/*                           DBGetMeasu16p ()                           */
/* ******************************************************************** */
INT08U DBGetMeasu16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_MEASU_SIZE)
    {   return DB_FALSE;
    }
    SFCopy16u(&aDBMeasu[usBegin], pDat, usSize);
    return DB_TRUE;
}

/* ******************************************************************** */
/*                        DBGetMeasuAndSum16p ()                        */
/* ******************************************************************** */
INT16U DBGetMeasuAndSum16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_MEASU_SIZE)
    {   return 0;
    }
    return SFCopyAndSum16u(&aDBMeasu[usBegin], pDat, usSize);
}

/* ******************************************************************** */
/*                           DBGetMeasu08p ()                           */
/* ******************************************************************** */
INT08U DBGetMeasu08p (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT16U usTemp;
    if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_MEASU_SIZE)
    {   return DB_FALSE;
    }
    while (usSize--)
    {   usTemp  = aDBMeasu[usBegin++];
       #if (DB_SCI_UC_LOW_FIRST == 1)
        *pDat++ = DB_UC_LOW(usTemp);
        *pDat++ = DB_UC_HIGH(usTemp);
       #else
        *pDat++ = DB_UC_HIGH(usTemp);
        *pDat++ = DB_UC_LOW(usTemp);
       #endif
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetMeasu16u ()                           */
/* ******************************************************************** */
INT08U DBSetMeasu16u (INT16U usBegin, INT16U usValue)
{   if (usBegin < DB_MEASU_SIZE)
    {   aDBMeasu[usBegin] = usValue;
        return DB_TRUE;
    }
    return DB_FALSE;
}

/* ******************************************************************** */
/*                           DBSetMeasu16p ()                           */
/* ******************************************************************** */
INT08U DBSetMeasu16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_MEASU_SIZE)
    {   return DB_FALSE;
    }
    SFCopy16u(pDat, &aDBMeasu[usBegin], usSize);
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetMeasu08p ()                           */
/* ******************************************************************** */
INT08U DBSetMeasu08p (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT08U ucTmp1, ucTmp2;
    if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_MEASU_SIZE)
    {   return DB_FALSE;
    }
    while (usSize--)
    {   ucTmp1 = *pDat++;
        ucTmp2 = *pDat++;
       #if (DB_SCI_UC_LOW_FIRST == 1)
        aDBMeasu[usBegin++] = DB_US_CREAT(ucTmp2, ucTmp1);
       #else
        aDBMeasu[usBegin++] = DB_US_CREAT(ucTmp1, ucTmp2);
       #endif
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBCheckMeasu16u ()                         */
/* ******************************************************************** */
INT08U DBCheckMeasu16u (INT16U usBegin, INT16U usValue)
{   if (usBegin >= DB_MEASU_SIZE)
    {   return DB_RANGE_OUT;
    }
    if (aDBMeasu[usBegin] != usValue)
    {   return DB_DIFFERENT;
    }
    return DB_SAME;
}

/* ******************************************************************** */
/*                           DBCheckMeasu16p ()                         */
/* ******************************************************************** */
INT08U DBCheckMeasu16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_MEASU_SIZE)
    {   return DB_RANGE_OUT;
    }
    return SFCompare16u(pDat, &aDBMeasu[usBegin], usSize);
}

/* ******************************************************************** */
/*                           DBGetFunct16u ()                           */
/* ******************************************************************** */
INT16U DBGetFunct16u (INT16U usBegin)
{   if (usBegin < DB_FUNCT_SIZE)
    {   return aDBFunct[usBegin];
    }   else
    {   return 0;
    }
}

/* ******************************************************************** */
/*                           DBGetFunct16p ()                           */
/* ******************************************************************** */
INT08U DBGetFunct16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_FUNCT_SIZE)
    {   return DB_FALSE;
    }
    SFCopy16u(&aDBFunct[usBegin], pDat, usSize);
    return DB_TRUE;
}

/* ******************************************************************** */
/*                        DBGetFunctAndSum16p ()                        */
/* ******************************************************************** */
INT16U DBGetFunctAndSum16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_FUNCT_SIZE)
    {   return 0;
    }
    return SFCopyAndSum16u(&aDBFunct[usBegin], pDat, usSize);
}

/* ******************************************************************** */
/*                           DBGetFunct08p ()                           */
/* ******************************************************************** */
INT08U DBGetFunct08p (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT16U usTemp;
    if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_FUNCT_SIZE)
    {   return DB_FALSE;
    }
    while (usSize--)
    {   usTemp  = aDBFunct[usBegin++];
       #if (DB_SCI_UC_LOW_FIRST == 1)
        *pDat++ = DB_UC_LOW(usTemp);
        *pDat++ = DB_UC_HIGH(usTemp);
       #else
        *pDat++ = DB_UC_HIGH(usTemp);
        *pDat++ = DB_UC_LOW(usTemp);
       #endif
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetFunct16u ()                           */
/* ******************************************************************** */
INT08U DBSetFunct16u (INT16U usBegin, INT16U usValue)
{   if (usBegin < DB_FUNCT_SIZE)
    {   aDBFunct[usBegin] = usValue;
        return DB_TRUE;
    }
    return DB_FALSE;
}

/* ******************************************************************** */
/*                           DBSetFunct16p ()                           */
/* ******************************************************************** */
INT08U DBSetFunct16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_FUNCT_SIZE)
    {   return DB_FALSE;
    }
    SFCopy16u(pDat, &aDBFunct[usBegin], usSize);
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetFunct08p ()                           */
/* ******************************************************************** */
INT08U DBSetFunct08p (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT08U ucTmp1, ucTmp2;
    if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_FUNCT_SIZE)
    {   return DB_FALSE;
    }
    while (usSize--)
    {   ucTmp1 = *pDat++;
        ucTmp2 = *pDat++;
       #if (DB_SCI_UC_LOW_FIRST == 1)
        aDBFunct[usBegin++] = DB_US_CREAT(ucTmp2, ucTmp1);
       #else
        aDBFunct[usBegin++] = DB_US_CREAT(ucTmp1, ucTmp2);
       #endif
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBCheckFunct16u ()                         */
/* ******************************************************************** */
INT08U DBCheckFunct16u (INT16U usBegin, INT16U usValue)
{   if (usBegin >= DB_FUNCT_SIZE)
    {   return DB_RANGE_OUT;
    }
    if (aDBFunct[usBegin] != usValue)
    {   return DB_DIFFERENT;
    }
    return DB_SAME;
}

/* ******************************************************************** */
/*                           DBCheckFunct16p ()                         */
/* ******************************************************************** */
INT08U DBCheckFunct16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_FUNCT_SIZE)
    {   return DB_RANGE_OUT;
    }
    return SFCompare16u(pDat, &aDBFunct[usBegin], usSize);
}

/* ******************************************************************** */
/*                           DBGetCurve16u ()                           */
/* ******************************************************************** */
INT16U DBGetCurve16u (INT16U usBegin)
{   if (usBegin < DB_CURVE_SIZE)
    {   return aDBCurve[usBegin];
    }   else
    {   return 0;
    }
}

/* ******************************************************************** */
/*                           DBGetCurve16p ()                           */
/* ******************************************************************** */
INT08U DBGetCurve16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_CURVE_SIZE)
    {   return DB_FALSE;
    }
    SFCopy16u(&aDBCurve[usBegin], pDat, usSize);
    return DB_TRUE;
}

/* ******************************************************************** */
/*                        DBGetCurveAndSum16p ()                        */
/* ******************************************************************** */
INT16U DBGetCurveAndSum16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_CURVE_SIZE)
    {   return 0;
    }
    return SFCopyAndSum16u(&aDBCurve[usBegin], pDat, usSize);
}

/* ******************************************************************** */
/*                           DBGetCurve08p ()                           */
/* ******************************************************************** */
INT08U DBGetCurve08p (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT16U usTemp;
    if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_CURVE_SIZE)
    {   return DB_FALSE;
    }
    while (usSize--)
    {   usTemp  = aDBCurve[usBegin++];
       #if (DB_SCI_UC_LOW_FIRST == 1)
        *pDat++ = DB_UC_LOW(usTemp);
        *pDat++ = DB_UC_HIGH(usTemp);
       #else
        *pDat++ = DB_UC_HIGH(usTemp);
        *pDat++ = DB_UC_LOW(usTemp);
       #endif
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetCurve16u ()                           */
/* ******************************************************************** */
INT08U DBSetCurve16u (INT16U usBegin, INT16U usValue)
{   if (usBegin < DB_CURVE_SIZE)
    {   aDBCurve[usBegin] = usValue;
        return DB_TRUE;
    }
    return DB_FALSE;
}

/* ******************************************************************** */
/*                           DBSetCurve16p ()                           */
/* ******************************************************************** */
INT08U DBSetCurve16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_CURVE_SIZE)
    {   return DB_FALSE;
    }
    SFCopy16u(pDat, &aDBCurve[usBegin], usSize);
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBSetCurve08p ()                           */
/* ******************************************************************** */
INT08U DBSetCurve08p (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT08U ucTmp1, ucTmp2;
    if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_CURVE_SIZE)
    {   return DB_FALSE;
    }
    while (usSize--)
    {   ucTmp1 = *pDat++;
        ucTmp2 = *pDat++;
       #if (DB_SCI_UC_LOW_FIRST == 1)
        aDBCurve[usBegin++] = DB_US_CREAT(ucTmp2, ucTmp1);
       #else
        aDBCurve[usBegin++] = DB_US_CREAT(ucTmp1, ucTmp2);
       #endif
    }
    return DB_TRUE;
}

/* ******************************************************************** */
/*                           DBCheckCurve16u ()                         */
/* ******************************************************************** */
INT08U DBCheckCurve16u (INT16U usBegin, INT16U usValue)
{   if (usBegin >= DB_CURVE_SIZE)
    {   return DB_RANGE_OUT;
    }
    if (aDBCurve[usBegin] != usValue)
    {   return DB_DIFFERENT;
    }
    return DB_SAME;
}

/* ******************************************************************** */
/*                           DBCheckCurve16p ()                         */
/* ******************************************************************** */
INT08U DBCheckCurve16p (INT16U *pDat, INT16U usBegin, INT16U usSize)
{   if (((INT32U)usBegin + (INT32U)usSize) > (INT32U)DB_CURVE_SIZE)
    {   return DB_RANGE_OUT;
    }
    return SFCompare16u(pDat, &aDBCurve[usBegin], usSize);
}

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
