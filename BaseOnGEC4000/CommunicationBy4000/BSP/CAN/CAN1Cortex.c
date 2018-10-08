/* ******************************************************************** */
/*                  CAN1 Software for Elctronic Unit (V1.0)             */
/*                       Source File CAN1Cortex.c                       */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   CAN1_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                              CAN1Init()                              */
/* ******************************************************************** */
#if (CAN1_FUNCTION_ON == 1)
void CAN1Init (void)
{   uiCAN1Status = 0;
    CAN1BufInit();
//    if ((usDBpCan1Address > 0) && (usDBpCan1Address < 256))
//    {   SAEInit((INT08U)usDBpCan1Address);
	     SAEInit((INT08U)0x01);
//    }   else
//    {   SAEInit(CAN1_MY_ADDRESS_DEF);
//    }
	
//    if (usDBpCan1Baudrate == 125)
//    {   CAN1HardInit(125);
//    }   else if (usDBpCan1Baudrate == 250)
//    {   
			  CAN1HardInit(250);
//    }   else if (usDBpCan1Baudrate == 500)
//    {   CAN1HardInit(500);
//    }   else if (usDBpCan1Baudrate == 1000)
//    {   CAN1HardInit(1000);
//    }   else
//    {   CAN1HardInit(CAN1_BAUDRATE_DEF);
//    }
}
#endif

/* ******************************************************************** */
/*                             CAN1Start()                              */
/* ******************************************************************** */
#if (CAN1_FUNCTION_ON == 1)
void CAN1Start (void)
{   CAN1_TC_INT_DIS();
    CAN1_RX_INT_EN();
//    FWIrqEnable(CAN1_TX_IRQn , 0);
//    FWIrqEnable(CAN1_RX0_IRQn, 0);
    FWIrqEnable(CAN1_RX1_IRQn, 0);
    FWIrqEnable(CAN1_SCE_IRQn, 0);
}
#endif

/* ******************************************************************** */
/*                            CAN1TaskLoop()                            */
/* ******************************************************************** */
#if (CAN1_FUNCTION_ON == 1)
void CAN1TaskLoop (void)
{
    INT16U NowTime = 0;
  	while (1)
    {   OSTimeDly(OS_TICKS_PER_SEC / CAN1_TASK_FRQ);
        /* ********************** CAN1 RX Message ********************* */
        while (CAN1IsRxBufEmpty() == CAN1_FALSE)
        {   (void)CAN1GetMsgFmRxBuf(0, &sCAN1TaskRxMsg);
            (void)SAEProcessRxMsg(&sCAN1TaskRxMsg);   
					  usDBmCANMsg0Norma0 = 1;
					  NowTime =  usFW100msTimer;
        }
				if(usFW100msTimer-NowTime>15) usDBmCANMsg0Norma0 = 0;
        /* ********************** CAN1 RX Message ********************* */
        if (SAECheckRxAllTimeOut() == SAE_FALSE)
        {   SAE_STS_CLR_BIT(SAE_STS_RX_ERR);  
        }   else
        {   SAE_STS_SET_BIT(SAE_STS_RX_ERR);  
        }
        /* ********************** CAN1 TX Message ********************* */
        if (SAEProcessTxMsg(&sCAN1TaskTxMsg) == SAE_NO_ERR)
        {   SAE_STS_CLR_BIT(SAE_STS_TX_ERR);
        }   else
        {   SAE_STS_SET_BIT(SAE_STS_TX_ERR);
        }
				
			if(usDBfCANEnable)
			{		
        if (CAN1GetTxMsgFmBuf(&sCAN1IntrTxMsg) == CAN1_NO_ERR)
        {   CAN1->sTxMailBox[0].TIR &= CAN_TI0R_TXRQ;
						CAN1->sTxMailBox[0].TIR |= sCAN1IntrTxMsg.DAT32.uiID;
						CAN1->sTxMailBox[0].TDTR = 8;
						CAN1->sTxMailBox[0].TDLR = sCAN1IntrTxMsg.DAT32.uiDat0;
						CAN1->sTxMailBox[0].TDHR = sCAN1IntrTxMsg.DAT32.uiDat1;
						CAN1->sTxMailBox[0].TIR |= CAN_TI0R_TXRQ;				
				
				}
				CAN1_TC_INT_EN();
			}
    }
}
#endif


//函数：CAN1TxData
//接口：
//说明：
//备注：
void CAN1TxData (void)
{
//    static INT16U usTimer0 = 0;
//		static INT16U usTimer1 = 0;
//		static INT16U usTimer2 = 0;
//		static INT16U usTimer3 = 0;
//		static INT16U usTimer4 = 0;
//		static INT16U usTimer5 = 0;
//		static INT16U usTimer6 = 0;
//		static INT16U usTimer7 = 0;
//		static INT16U usTimer8 = 0;
//    INT16U usDelay, usTimNow;
//    usTimNow = Time2Count;	
//	  usDelay = (INT16U)(usTimNow - usTimer0);
//    if (CAN1GetTxMsgFmBuf(&sCAN1IntrTxMsg) == CAN1_NO_ERR)
//    {
//			
//				if(usDBfCANEnSentData0 != 0)
//				{usTimer0 = usTimNow;}
//				else if(usDelay>=usDBfCANDelay0)
//				{
//						usTimer0 = usTimNow;	
//					
//            sCAN1IntrTxMsg.DAT32.uiID = 	SAE_ID32_TO_CPU(0x1234567);
//						sCAN1IntrTxMsg.DAT08.ucDat0 = 0x01;
//						sCAN1IntrTxMsg.DAT08.ucDat1 = 0x02;
//						sCAN1IntrTxMsg.DAT08.ucDat2 = 0x03;
//						sCAN1IntrTxMsg.DAT08.ucDat3 = 0x04;
//						sCAN1IntrTxMsg.DAT08.ucDat4 = 0x05;
//						sCAN1IntrTxMsg.DAT08.ucDat5 = 0x06;
//						sCAN1IntrTxMsg.DAT08.ucDat6 = 0x07;
//						sCAN1IntrTxMsg.DAT08.ucDat7 = 0x08;
//				}
//  

//		
//				
//				

//  			CAN1->sTxMailBox[0].TIR &= CAN_TI0R_TXRQ;
//        CAN1->sTxMailBox[0].TIR |= sCAN1IntrTxMsg.DAT32.uiID;
//        CAN1->sTxMailBox[0].TDTR = 8;
//        CAN1->sTxMailBox[0].TDLR = sCAN1IntrTxMsg.DAT32.uiDat0;
//        CAN1->sTxMailBox[0].TDHR = sCAN1IntrTxMsg.DAT32.uiDat1;
//        CAN1->sTxMailBox[0].TIR |= CAN_TI0R_TXRQ;
//        CAN1_TC_INT_EN();
//				
//				
//    }		
//		
}

/* ******************************************************************** */
/*                             CAN1TxIntHook()                          */
/* ******************************************************************** */
#if (CAN1_FUNCTION_ON == 1)
void CAN1TxIntHook (void)
{   CAN1_TC_INT_DIS();
    if (CAN1GetTxMsgFmBuf(&sCAN1IntrTxMsg) == CAN1_NO_ERR)
    {   CAN1->sTxMailBox[0].TIR &= CAN_TI0R_TXRQ;
        CAN1->sTxMailBox[0].TIR |= sCAN1IntrTxMsg.DAT32.uiID;
        CAN1->sTxMailBox[0].TDTR = 8;
        CAN1->sTxMailBox[0].TDLR = sCAN1IntrTxMsg.DAT32.uiDat0;
        CAN1->sTxMailBox[0].TDHR = sCAN1IntrTxMsg.DAT32.uiDat1;
        CAN1->sTxMailBox[0].TIR |= CAN_TI0R_TXRQ;
        if (CAN1GetTxMsgFmBuf(&sCAN1IntrTxMsg) == CAN1_NO_ERR)
        {   CAN1->sTxMailBox[1].TIR &= CAN_TI1R_TXRQ;
            CAN1->sTxMailBox[1].TIR |= sCAN1IntrTxMsg.DAT32.uiID;
            CAN1->sTxMailBox[1].TDTR = 8;
            CAN1->sTxMailBox[1].TDLR = sCAN1IntrTxMsg.DAT32.uiDat0;
            CAN1->sTxMailBox[1].TDHR = sCAN1IntrTxMsg.DAT32.uiDat1;
            CAN1->sTxMailBox[1].TIR |= CAN_TI1R_TXRQ;
            if (CAN1GetTxMsgFmBuf(&sCAN1IntrTxMsg) == CAN1_NO_ERR)
            {   CAN1->sTxMailBox[2].TIR &= CAN_TI2R_TXRQ;
                CAN1->sTxMailBox[2].TIR |= sCAN1IntrTxMsg.DAT32.uiID;
                CAN1->sTxMailBox[2].TDTR = 8;
                CAN1->sTxMailBox[2].TDLR = sCAN1IntrTxMsg.DAT32.uiDat0;
                CAN1->sTxMailBox[2].TDHR = sCAN1IntrTxMsg.DAT32.uiDat1;
                CAN1->sTxMailBox[2].TIR |= CAN_TI2R_TXRQ;
            }
        }
        CAN1_TC_INT_EN();
    }
}
#endif

/* ******************************************************************** */
/*                             CAN1Rx0IntHook()                         */
/* ******************************************************************** */
#if (CAN1_FUNCTION_ON == 1)
void CAN1Rx0IntHook (void)
{   sCAN1IntrRxMsg.DAT32.uiID   = CAN1->sFIFOMailBox[0].RIR & CAN1_CPU_ID_MSK;
    sCAN1IntrRxMsg.DAT32.uiDat0 = CAN1->sFIFOMailBox[0].RDLR;
    sCAN1IntrRxMsg.DAT32.uiDat1 = CAN1->sFIFOMailBox[0].RDHR;
    CAN1->RF0R                 |= CAN_RF0R_RFOM0;
    (void)CAN1PutRxMsgToBuf(&sCAN1IntrRxMsg);
    if ((CAN1->RF0R & CAN_RF0R_FMP0) != 0)
    {   sCAN1IntrRxMsg.DAT32.uiID   = CAN1->sFIFOMailBox[0].RIR & CAN1_CPU_ID_MSK;
        sCAN1IntrRxMsg.DAT32.uiDat0 = CAN1->sFIFOMailBox[0].RDLR;
        sCAN1IntrRxMsg.DAT32.uiDat1 = CAN1->sFIFOMailBox[0].RDHR;
        CAN1->RF0R                 |= CAN_RF0R_RFOM0;
        (void)CAN1PutRxMsgToBuf(&sCAN1IntrRxMsg);
        if ((CAN1->RF0R & CAN_RF0R_FMP0) != 0)
        {   sCAN1IntrRxMsg.DAT32.uiID   = CAN1->sFIFOMailBox[0].RIR & CAN1_CPU_ID_MSK;
            sCAN1IntrRxMsg.DAT32.uiDat0 = CAN1->sFIFOMailBox[0].RDLR;
            sCAN1IntrRxMsg.DAT32.uiDat1 = CAN1->sFIFOMailBox[0].RDHR;
            CAN1->RF0R                 |= CAN_RF0R_RFOM0;
            (void)CAN1PutRxMsgToBuf(&sCAN1IntrRxMsg);
        }
    }
}
#endif

/* ******************************************************************** */
/*                             CAN1Rx1IntHook()                         */
/* ******************************************************************** */
//#if (CAN1_FUNCTION_ON == 1)
//void CAN1Rx1IntHook (void)
//{   sCAN1IntrRxMsg.DAT32.uiID   = CAN1->sFIFOMailBox[1].RIR & CAN1_CPU_ID_MSK;
//    sCAN1IntrRxMsg.DAT32.uiDat0 = CAN1->sFIFOMailBox[1].RDLR;
//    sCAN1IntrRxMsg.DAT32.uiDat1 = CAN1->sFIFOMailBox[1].RDHR;
//    CAN1->RF1R                 |= CAN_RF1R_RFOM1;
//    (void)CAN1PutRxMsgToBuf(&sCAN1IntrRxMsg);
//    if ((CAN1->RF1R & CAN_RF1R_FMP1) != 0)
//    {   sCAN1IntrRxMsg.DAT32.uiID   = CAN1->sFIFOMailBox[1].RIR & CAN1_CPU_ID_MSK;
//        sCAN1IntrRxMsg.DAT32.uiDat0 = CAN1->sFIFOMailBox[1].RDLR;
//        sCAN1IntrRxMsg.DAT32.uiDat1 = CAN1->sFIFOMailBox[1].RDHR;
//        CAN1->RF1R                 |= CAN_RF1R_RFOM1;
//        (void)CAN1PutRxMsgToBuf(&sCAN1IntrRxMsg);
//        if ((CAN1->RF1R & CAN_RF1R_FMP1) != 0)
//        {   sCAN1IntrRxMsg.DAT32.uiID   = CAN1->sFIFOMailBox[1].RIR & CAN1_CPU_ID_MSK;
//            sCAN1IntrRxMsg.DAT32.uiDat0 = CAN1->sFIFOMailBox[1].RDLR;
//            sCAN1IntrRxMsg.DAT32.uiDat1 = CAN1->sFIFOMailBox[1].RDHR;
//            CAN1->RF1R                 |= CAN_RF1R_RFOM1;
//            (void)CAN1PutRxMsgToBuf(&sCAN1IntrRxMsg);
//        }
//    }
//}
//#endif

/* ******************************************************************** */
/*                            CAN1SceIntHook()                          */
/* ******************************************************************** */
//#if (CAN1_FUNCTION_ON == 1)
//void CAN1SceIntHook (void)
//{   INT32U uiTemp;
//    uiTemp = CAN1->ESR;
//    if ((uiTemp & CAN_ESR_BOFF) != 0)
//    {   CAN1_STS_SET_BIT(CAN1_STS_BUS_OFF);
//    }   else
//    {   CAN1_STS_CLR_BIT(CAN1_STS_BUS_OFF);
//    }
//    if ((uiTemp & CAN_ESR_EWGF) != 0)
//    {   CAN1_STS_SET_BIT(CAN1_STS_WARNING);
//    }   else
//    {   CAN1_STS_CLR_BIT(CAN1_STS_WARNING);
//    }
//    if ((uiTemp & CAN_ESR_EPVF) != 0)
//    {   CAN1_STS_SET_BIT(CAN1_STS_OVERRUN);
//    }   else
//    {   CAN1_STS_CLR_BIT(CAN1_STS_OVERRUN);
//    }
//}
//#endif

/* ******************************************************************** */
/*                             CAN1BufInit()                            */
/* ******************************************************************** */
#if (CAN1_FUNCTION_ON == 1)
void CAN1BufInit (void)
{   CAN1_RING *pbuf;
    pbuf = &sCAN1RingBuf;
    pbuf->usRingBufRxCtr   =  0;
    pbuf->pRingBufRxInPtr  = &pbuf->sRingBufRx[0];
    pbuf->pRingBufRxOutPtr = &pbuf->sRingBufRx[0];
    pbuf->pRingBufRxSem    =  OSSemCreate(0);
    pbuf->usRingBufTxCtr   =  0;
    pbuf->pRingBufTxInPtr  = &pbuf->sRingBufTx[0];
    pbuf->pRingBufTxOutPtr = &pbuf->sRingBufTx[0];
    pbuf->pRingBufTxSem    =  OSSemCreate(CAN1_TX_BUF_SIZE);
}
#endif

/* ******************************************************************** */
/*                            CAN1IsTxBufFull()                         */
/* ******************************************************************** */
#if (CAN1_FUNCTION_ON == 1)
INT08U CAN1IsTxBufFull (void)
{   OS_CPU_SR cpu_sr = 0;
    CAN1_RING *pbuf;
    pbuf = &sCAN1RingBuf;
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufTxCtr >= CAN1_TX_BUF_SIZE)
    {   OS_EXIT_CRITICAL();
        return CAN1_TRUE;
    }   else
    {   OS_EXIT_CRITICAL();
        return CAN1_FALSE;
    }
}
#endif

/* ******************************************************************** */
/*                           CAN1IsRxBufEmpty()                         */
/* ******************************************************************** */
#if (CAN1_FUNCTION_ON == 1)
INT08U CAN1IsRxBufEmpty (void)
{   OS_CPU_SR cpu_sr = 0;
    CAN1_RING *pbuf;
    pbuf = &sCAN1RingBuf;
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufRxCtr == 0)
    {   OS_EXIT_CRITICAL();
        return CAN1_TRUE;
    }   else
    {   OS_EXIT_CRITICAL();
        return CAN1_FALSE;
    }
}
#endif

/* ******************************************************************** */
/*                           CAN1PutRxMsgToBuf()                        */
/* ******************************************************************** */
#if (CAN1_FUNCTION_ON == 1)
void CAN1PutRxMsgToBuf (CAN_MSG *pmsg)
{   CAN1_RING *pbuf;
    CAN_MSG *ptmp;
    pbuf = &sCAN1RingBuf;
    if (pbuf->usRingBufRxCtr < CAN1_RX_BUF_SIZE)
    {   pbuf->usRingBufRxCtr++;
        ptmp = pbuf->pRingBufRxInPtr;
        ptmp->DAT32.uiID   = pmsg->DAT32.uiID;
        ptmp->DAT32.uiDat0 = pmsg->DAT32.uiDat0;
        ptmp->DAT32.uiDat1 = pmsg->DAT32.uiDat1;
        pbuf->pRingBufRxInPtr++;
        if (pbuf->pRingBufRxInPtr == &pbuf->sRingBufRx[CAN1_RX_BUF_SIZE])
        {   pbuf->pRingBufRxInPtr  = &pbuf->sRingBufRx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufRxSem);
    }
}
#endif

/* ******************************************************************** */
/*                          CAN1GetTxMsgFmBuf()                         */
/* ******************************************************************** */
#if (CAN1_FUNCTION_ON == 1)
INT08U CAN1GetTxMsgFmBuf (CAN_MSG *pmsg)
{   CAN1_RING *pbuf;
    CAN_MSG *ptmp;
    pbuf = &sCAN1RingBuf;
    if (pbuf->usRingBufTxCtr > 0)
    {   pbuf->usRingBufTxCtr--;
        ptmp = pbuf->pRingBufTxOutPtr;
        pmsg->DAT32.uiID   = ptmp->DAT32.uiID;
        pmsg->DAT32.uiDat0 = ptmp->DAT32.uiDat0;
        pmsg->DAT32.uiDat1 = ptmp->DAT32.uiDat1;
        pbuf->pRingBufTxOutPtr++;
        if (pbuf->pRingBufTxOutPtr == &pbuf->sRingBufTx[CAN1_TX_BUF_SIZE])
        {   pbuf->pRingBufTxOutPtr  = &pbuf->sRingBufTx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufTxSem);
        return CAN1_NO_ERR;
    }   else
    {   return CAN1_ERR_TX_EMPTY;
    }
}
#endif

/* ******************************************************************** */
/*                          CAN1GetMsgFmRxBuf()                         */
/* ******************************************************************** */
#if (CAN1_FUNCTION_ON == 1)
INT08U CAN1GetMsgFmRxBuf (INT16U to, CAN_MSG *pmsg)
{   OS_CPU_SR cpu_sr = 0;
    INT08U oserr;
    CAN1_RING *pbuf;
    CAN_MSG *ptmp;
    pbuf = &sCAN1RingBuf;
    OSSemPend(pbuf->pRingBufRxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   return CAN1_ERR_RX_TIMEOUT;
    }
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufRxCtr == 0)
    {   OS_EXIT_CRITICAL();
        return CAN1_ERR_RX_TIMEOUT;
    }
    pbuf->usRingBufRxCtr--;
    ptmp = pbuf->pRingBufRxOutPtr;
    pmsg->DAT32.uiID   = ptmp->DAT32.uiID;
    pmsg->DAT32.uiDat0 = ptmp->DAT32.uiDat0;
    pmsg->DAT32.uiDat1 = ptmp->DAT32.uiDat1;
    pbuf->pRingBufRxOutPtr++;
    if (pbuf->pRingBufRxOutPtr == &pbuf->sRingBufRx[CAN1_RX_BUF_SIZE])
    {   pbuf->pRingBufRxOutPtr  = &pbuf->sRingBufRx[0];
    }
    OS_EXIT_CRITICAL();
    return CAN1_NO_ERR;
}
#endif

/* ******************************************************************** */
/*                         CAN1TransMsgFirst()                          */
/* ******************************************************************** */
#if (CAN1_FUNCTION_ON == 1)
void CAN1TransMsgFirst (void)
{   CAN1_TC_INT_DIS();
    if (CAN1GetTxMsgFmBuf(&sCAN1IntrTxMsg) == CAN1_NO_ERR)
    {   CAN1->sTxMailBox[0].TIR &= CAN_TI0R_TXRQ;
        CAN1->sTxMailBox[0].TIR |= sCAN1IntrTxMsg.DAT32.uiID;
        CAN1->sTxMailBox[0].TDTR = 8;
        CAN1->sTxMailBox[0].TDLR = sCAN1IntrTxMsg.DAT32.uiDat0;
        CAN1->sTxMailBox[0].TDHR = sCAN1IntrTxMsg.DAT32.uiDat1;
        CAN1->sTxMailBox[0].TIR |= CAN_TI0R_TXRQ;
        CAN1_TC_INT_EN();
    }
}
#endif

/* ******************************************************************** */
/*                         CAN1PutMsgToTxBuf()                          */
/* ******************************************************************** */
#if (CAN1_FUNCTION_ON == 1)
INT08U CAN1PutMsgToTxBuf (INT16U to, CAN_MSG *pmsg)
{   static INT32U uiCAN1TxFirstFlag = 0;
    OS_CPU_SR cpu_sr = 0;
    INT08U oserr;
    CAN1_RING *pbuf;
    CAN_MSG *ptmp;
    pbuf = &sCAN1RingBuf;
    OSSemPend(pbuf->pRingBufTxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   return CAN1_ERR_TX_TIMEOUT;
    }   else
    {   OS_ENTER_CRITICAL();
        pbuf->usRingBufTxCtr++;
        ptmp = pbuf->pRingBufTxInPtr;
        ptmp->DAT32.uiID   = pmsg->DAT32.uiID;
        ptmp->DAT32.uiDat0 = pmsg->DAT32.uiDat0;
        ptmp->DAT32.uiDat1 = pmsg->DAT32.uiDat1;
        pbuf->pRingBufTxInPtr++;
        if (pbuf->pRingBufTxInPtr == &pbuf->sRingBufTx[CAN1_TX_BUF_SIZE])
        {   pbuf->pRingBufTxInPtr  = &pbuf->sRingBufTx[0];
        }
        if (pbuf->usRingBufTxCtr  == 1)
        {   if (uiCAN1TxFirstFlag == 0)
            {   uiCAN1TxFirstFlag  = 1;
                CAN1TransMsgFirst();
            }   else
            {   CAN1_TC_INT_EN();
            }
        }
        OS_EXIT_CRITICAL();
        return CAN1_NO_ERR;
    }
}
#endif

/* ******************************************************************** */
/*                              CAN1HardInit()                          */
/* ******************************************************************** */
#if (CAN1_FUNCTION_ON == 1)
void CAN1HardInit (INT32U uiBaud)
{   
//    RCC->APB1ENR  |=  RCC_APB1ENR_CAN1EN;
//  //  RCC->APB1RSTR |=  RCC_APB1RSTR_CAN1RST;
//  //  RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN1RST;
//    XIOConfigREMAP(CAN1_AFIO_REMAP1, CAN1_AFIO_REMAP2);
//    XIOConfigGPIO(CAN1_TX_PT, CAN1_TX_BT, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
//    XIOConfigGPIO(CAN1_RX_PT, CAN1_RX_BT, XIO_PT_GPI_PULL,   XIO_PT_SET_1);
//    CAN1->MCR &= ~CAN_MCR_SLEEP;            /* Exit from sleep mode     */
//    CAN1->MCR |=  CAN_MCR_INRQ;             /* Request initialisation   */
//    while((CAN1->MSR & CAN_MSR_INAK) == 0); /* Wait the acknowledge     */
//    CAN1->MCR &= ~CAN_MCR_TTCM              /* 0: Time Trigger mode dis */
//              &  ~CAN_MCR_ABOM              /* 0: No bus-off management */
//              &  ~CAN_MCR_AWUM              /* 0: No Automatic wakeup   */
//              &  ~CAN_MCR_RFLM;             /* 0: Receive FIFO not lock */
//    CAN1->MCR |=  CAN_MCR_TXFP              /* 1: Priority by the order */
//              |   CAN_MCR_NART;             /* 1: Not automatic retrans */
//    if (uiBaud == 125)
//    {   CAN1->BTR  = ((INT32U)0 << 30)      /* 0: Normal operation mode */
//                  |  ((INT32U)1 << 24)      /* 1: Resynch jump width= 2 */
//                  |  ((INT32U)5 << 20)      /* 5: Time segment 2 = 6tq  */
//                  |  ((INT32U)8 << 16)      /* 8: Time segment 1 = 9tq  */
//                  |  ((INT32U)18 - 1);      /* Prescaler=18: Tq = 1/2us */
//    }
//    else if (uiBaud == 250)
//    {   CAN1->BTR  = ((INT32U)0 << 30)      /* 0: Normal operation mode */
//                  |  ((INT32U)1 << 24)      /* 1: Resynch jump width= 2 */
//                  |  ((INT32U)5 << 20)      /* 5: Time segment 2 = 6tq  */
//                  |  ((INT32U)8 << 16)      /* 8: Time segment 1 = 9tq  */
//                  |  ((INT32U)9 - 1);       /* Prescaler=9:  Tq = 1/4us */
//    }
//    else if (uiBaud == 500)
//    {   CAN1->BTR  = ((INT32U)0 << 30)      /* 0: Normal operation mode */
//                  |  ((INT32U)0 << 24)      /* 0: Resynch jump width= 1 */
//                  |  ((INT32U)2 << 20)      /* 2: Time segment 2 = 3tq  */
//                  |  ((INT32U)3 << 16)      /* 3: Time segment 1 = 4tq  */
//                  |  ((INT32U)9 - 1);       /* Prescaler=9:  Tq = 1/4us */
//    }
//    else if (uiBaud == 1000)
//    {   CAN1->BTR  = ((INT32U)0 << 30)      /* 0: Normal operation mode */
//                  |  ((INT32U)0 << 24)      /* 0: Resynch jump width= 1 */
//                  |  ((INT32U)2 << 20)      /* 2: Time segment 2 = 3tq  */
//                  |  ((INT32U)4 << 16)      /* 4: Time segment 1 = 5tq  */
//                  |  ((INT32U)4 - 1);       /* Prescaler=4:  Tq = 1/9us */
//    }
//    CAN1->MCR  &= ~CAN_MCR_INRQ;            /* Request leave initialie  */
//    while((CAN1->MSR & CAN_MSR_INAK) != 0); /* Wait the acknowledge     */
//    CAN1->FMR  |=  CAN_FMR_FINIT;           /* 1: Initialization mode   */
//    CAN1->FA1R &= ~CAN_FA1R_FACT0;          /* 过滤器0不激活            */
//    CAN1->FS1R |=  CAN_FS1R_FSC0;           /* 过滤器0位宽为32位        */
//    CAN1->FM1R  =  0x00000000;              /* 0: Identifier Mask mode  */
//    CAN1->FFA1R =  0x00000000;              /* 过滤器0关联到FIFO0       */
//    CAN1->sFilterRegister[0].FR1 = 0x00000000;              /* 32位ID   */
//    CAN1->sFilterRegister[0].FR2 = 0x00000000;              /* 32位MASK */
//    CAN1->FA1R |=  CAN_FA1R_FACT0;          /* 激活过滤器0              */
//    CAN1->FMR  &= ~CAN_FMR_FINIT;           /* 0: Active filters mode   */

    GPIO_InitTypeDef GPIO_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;
		CAN_InitTypeDef  CAN_InitStructure; 
		CAN_FilterInitTypeDef  CAN_FilterInitStructure;
		
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,(FunctionalState)ENABLE); //íaéèê±?óéè??
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, (FunctionalState)ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;            //Configure CAN pin: RX PA11						
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	        //é?à-ê?è?
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;            //Configure CAN pin: TX PA12			
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    //?′ó?í?íìê?3?
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;    
    GPIO_Init(GPIOA, &GPIO_InitStructure);
        
    
    NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn; //?D??éè?? CAN1 RX0?D??
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //?à??ó??è??0
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;			    //×óó??è???a0
    NVIC_InitStructure.NVIC_IRQChannelCmd = (FunctionalState)ENABLE;
    NVIC_Init(&NVIC_InitStructure);       
   
             
    CAN_DeInit(CAN1);
    CAN_StructInit(&CAN_InitStructure);
    CAN_InitStructure.CAN_TTCM=(FunctionalState)DISABLE;						 //·?ê±??′￥·￠í¨D??￡ê?  
    CAN_InitStructure.CAN_ABOM=(FunctionalState)DISABLE;						 //èí?t×??ˉà???1üàí	 
    CAN_InitStructure.CAN_AWUM=(FunctionalState)DISABLE;						 //?ˉ???￡ê?í¨1yèí?t??D?(??3yCAN->MCRμ?SLEEP??)
    CAN_InitStructure.CAN_NART=(FunctionalState)ENABLE;						 //???1±¨??×??ˉ′??í 
    CAN_InitStructure.CAN_RFLM=(FunctionalState)DISABLE;						 //±¨??2????¨,D?μ??2???éμ? 
    CAN_InitStructure.CAN_TXFP=(FunctionalState)DISABLE;						 //ó??è??óé±¨??±êê?·????¨ 
    CAN_InitStructure.CAN_Mode= CAN_Mode_Normal;	 //?￡ê?éè??￡o mode:0,??í¨?￡ê?;1,???·?￡ê?; 
    //éè??2¨ì??ê
    CAN_InitStructure.CAN_SJW=CAN_SJW_1tq;				 //??D?í?2?ì????í?è(Tsjw)?atsjw+1??ê±??μ￥??  CAN_SJW_1tq	 CAN_SJW_2tq CAN_SJW_3tq CAN_SJW_4tq
    CAN_InitStructure.CAN_BS1=CAN_BS1_13tq;        //Tbs1=tbs1+1??ê±??μ￥??CAN_BS1_1tq ~CAN_BS1_16tq
    CAN_InitStructure.CAN_BS2=CAN_BS2_2tq;         //Tbs2=tbs2+1??ê±??μ￥??CAN_BS2_1tq ~	CAN_BS2_8tq
    CAN_InitStructure.CAN_Prescaler=9;             //·??μ?μêy(Fdiv)?abrp+1	
    CAN_Init(CAN1, &CAN_InitStructure);            //3?ê??ˉCAN1    
  
    
    CAN_FilterInitStructure.CAN_FilterNumber=0;	                     //1y???÷0
    CAN_FilterInitStructure.CAN_FilterMode=CAN_FilterMode_IdMask; 
    CAN_FilterInitStructure.CAN_FilterScale=CAN_FilterScale_32bit;   //32?? 
    CAN_FilterInitStructure.CAN_FilterIdHigh=0x0000;                 //32??ID
    CAN_FilterInitStructure.CAN_FilterIdLow=0x0000;
    CAN_FilterInitStructure.CAN_FilterMaskIdHigh=0x0000;             //32??MASK
    CAN_FilterInitStructure.CAN_FilterMaskIdLow=0x0000;
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment=CAN_FilterFIFO0;//1y???÷01?áaμ?FIFO0
    CAN_FilterInitStructure.CAN_FilterActivation=(FunctionalState)ENABLE;              //?¤??1y???÷0
    CAN_FilterInit(&CAN_FilterInitStructure);                         //??2¨?÷3?ê??ˉ
    CAN_ITConfig(CAN1,CAN_IT_FMP0,(FunctionalState)ENABLE);                            //FIFO0???￠1òo??D???êDí.  
}
#endif


#if (CAN1_FUNCTION_ON == 1)
void CCP10DecodeRxPar (CAN_MSG *pMsg)
{   INT16U usD0, usD1, usD2, usD3;
    usD0 = CCP_US_CREAT(pMsg->DAT08.ucDat0, pMsg->DAT08.ucDat1);
    usD1 = CCP_US_CREAT(pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat3);
    usD2 = CCP_US_CREAT(pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat5);
    usD3 = CCP_US_CREAT(pMsg->DAT08.ucDat6, pMsg->DAT08.ucDat7);
    if (usD3 == (usD0 + usD1 + usD2))
    {   sCCP10RxPar.usCode  = usD0;
        sCCP10RxPar.usWhich = usD1;
        sCCP10RxPar.usValue = usD2;
    }
}
#endif
#if (CAN1_FUNCTION_ON == 1)
void CCP10FillMsgTxReq (CAN_MSG *pMsg)
{   INT16U usTemp, usSum;
    usTemp  = sCCP10TxReq.usCode;
    usSum   = usTemp;
    pMsg->DAT08.ucDat0 = CCP_UC_LOW(usTemp);
    pMsg->DAT08.ucDat1 = CCP_UC_HIGH(usTemp);
    usTemp  = sCCP10TxReq.usWhich;
    usSum  += usTemp;
    pMsg->DAT08.ucDat2 = CCP_UC_LOW(usTemp);
    pMsg->DAT08.ucDat3 = CCP_UC_HIGH(usTemp);
    usTemp  = sCCP10TxReq.usValue;
    usSum  += usTemp;
    pMsg->DAT08.ucDat4 = CCP_UC_LOW(usTemp);
    pMsg->DAT08.ucDat5 = CCP_UC_HIGH(usTemp);
    usTemp  = usSum;
    pMsg->DAT08.ucDat6 = CCP_UC_LOW(usTemp);
    pMsg->DAT08.ucDat7 = CCP_UC_HIGH(usTemp);
}
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
