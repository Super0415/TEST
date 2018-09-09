/* ******************************************************************** */
/*                    MOD Bus protocol Version 1.0                      */
/*                       Source File MODBus10.c                         */
/*                            By: Wu Xuekui                             */
/*                              2017-11-02                              */
/* ******************************************************************** */

#define   MOD_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                            Const Section                             */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
INT08U const aMODCrc16TabHi[256] =
{   0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40
};
INT08U const aMODCrc16TabLo[256] =
{   0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2,
    0xC6, 0x06, 0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04,
    0xCC, 0x0C, 0x0D, 0xCD, 0x0F, 0xCF, 0xCE, 0x0E,
    0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09, 0x08, 0xC8,
    0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A,
    0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC,
    0x14, 0xD4, 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6,
    0xD2, 0x12, 0x13, 0xD3, 0x11, 0xD1, 0xD0, 0x10,
    0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 0xF2, 0x32,
    0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
    0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE,
    0xFA, 0x3A, 0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38,
    0x28, 0xE8, 0xE9, 0x29, 0xEB, 0x2B, 0x2A, 0xEA,
    0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED, 0xEC, 0x2C,
    0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
    0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0,
    0xA0, 0x60, 0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62,
    0x66, 0xA6, 0xA7, 0x67, 0xA5, 0x65, 0x64, 0xA4,
    0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F, 0x6E, 0xAE,
    0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
    0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA,
    0xBE, 0x7E, 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C,
    0xB4, 0x74, 0x75, 0xB5, 0x77, 0xB7, 0xB6, 0x76,
    0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 0x70, 0xB0,
    0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
    0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54,
    0x9C, 0x5C, 0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E,
    0x5A, 0x9A, 0x9B, 0x5B, 0x99, 0x59, 0x58, 0x98,
    0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B, 0x8A, 0x4A,
    0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
    0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86,
    0x82, 0x42, 0x43, 0x83, 0x41, 0x81, 0x80, 0x40
};
#endif

/* ******************************************************************** */
/*                              MODInit ()                              */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
void MODInit (void)
{   usMODTimer = 0;
    usMODStatus = 0;
    ucMODCtrlStep = MOD_STEP_INIT;
    ucMODRxByteCnt = 0;
    ucMODTxByteCnt = 0;
    usMODOverTime1P5 = 2500;
    usMODOverTime3P5 = 4500;
    usMODOverTime2P0 = usMODOverTime3P5 - usMODOverTime1P5;
    sMODTxRxMsg.ucLeng = 0;
    sMODTxRxMsg.ucAddr = MOD_MY_ADR_DEFAULT;
    (void)MODCmdBufInit();
}
#endif

/* ******************************************************************** */
/*                          MODStart ()                                 */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
void MODStart (void)
{   (void)MODOverTimerInit();
}
#endif

/* ******************************************************************** */
/*                          MODOverTimerHook ()                         */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
void MODOverTimerHook (void)
{   if (MOD_STS_GET_BIT(MOD_STS_TO_1P5_ON) != 0)
    {   MOD_STS_CLR_BIT(MOD_STS_TO_1P5_ON);
        MODOverTimerSet(usMODOverTime2P0);
        if (ucMODCtrlStep == MOD_STEP_RX_ING)
        {   ucMODCtrlStep  = MOD_STEP_RX_WAIT;
        }   else
        {   MOD_STS_SET_BIT(MOD_STS_ERR_LOGIC);
        }
    }
    else if (ucMODCtrlStep == MOD_STEP_INIT)
    {   ucMODCtrlStep = MOD_STEP_IDLE;
    }
    else if (ucMODCtrlStep == MOD_STEP_TX_ING)
    {   ucMODCtrlStep = MOD_STEP_IDLE;
    }
    else if (ucMODCtrlStep == MOD_STEP_RX_WAIT)
    {   if (MOD_STS_GET_BIT(MOD_STS_ERR_RX | MOD_STS_ERR_ADDR) == 0)
        {   sMODTxRxMsg.ucLeng = ucMODRxByteCnt;
            ucMODRxByteCnt = 0;
            MODPutRxChar(MOD_COMD_RX_RDY);
        }
        ucMODCtrlStep = MOD_STEP_IDLE;
        MOD_STS_SET_BIT(MOD_STS_ERR_RX | MOD_STS_ERR_ADDR);
    }
    else
    {   MOD_STS_SET_BIT(MOD_STS_ERR_LOGIC);
    }
}
#endif

/* ******************************************************************** */
/*                           MODTxRxIntHook ()                          */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
void MODTxRxIntHook (void)
{   INT08U ucDat;
    /* **************************************************************** */
    /*                          If RX a Byte                            */
    /* **************************************************************** */
    if ((MOD_SCI_SR_REG & USART_SR_RXNE) != 0)
    {   ucDat = (INT08U)(MOD_SCI_DR_REG);
        /* ******************** Step = INIT *************************** */
        if (ucMODCtrlStep == MOD_STEP_INIT)
        {   MOD_STS_CLR_BIT(MOD_STS_TO_1P5_ON);
            MODOverTimerSet(usMODOverTime3P5);
        }
        /* ******************** Step = IDLE *************************** */
        else if (ucMODCtrlStep == MOD_STEP_IDLE)
        {   MOD_STS_CLR_BIT(MOD_STS_ERR_RX);
            MOD_STS_SET_BIT(MOD_STS_TO_1P5_ON | MOD_STS_ERR_ADDR);
            MODOverTimerSet(usMODOverTime1P5);
            ucMODCtrlStep = MOD_STEP_RX_ING;
            if((ucDat == 0) || (ucDat == sMODTxRxMsg.ucAddr))
            {   MOD_STS_CLR_BIT(MOD_STS_ERR_ADDR);
                sMODTxRxMsg.aData[0] = ucDat;
                ucMODRxByteCnt = 1;
            }
        }
        /* ******************** Step = RX_ING ************************* */
        else if (ucMODCtrlStep == MOD_STEP_RX_ING)
        {   MOD_STS_SET_BIT(MOD_STS_TO_1P5_ON);
            MODOverTimerSet(usMODOverTime1P5);
            if (MOD_STS_GET_BIT(MOD_STS_ERR_RX | MOD_STS_ERR_ADDR) == 0)
            {   sMODTxRxMsg.aData[ucMODRxByteCnt++] = ucDat;
            }
        }
        /* ******************** Step = RX_WAIT, TX_ING **************** */
        else
        {   MOD_STS_SET_BIT(MOD_STS_TO_1P5_ON | MOD_STS_ERR_RX);
            MODOverTimerSet(usMODOverTime1P5);
            ucMODCtrlStep = MOD_STEP_RX_ING;
        }
    }
    /* **************************************************************** */
    /*                          If TX Complete                          */
    /* **************************************************************** */
    else if ((MOD_SCI_SR_REG & USART_SR_TC) != 0)
    {   /* ******************** Step = IDLE *************************** */
        if (ucMODCtrlStep == MOD_STEP_IDLE)
        {   ucMODCtrlStep  = MOD_STEP_TX_ING;
            MOD_SCI_DR_REG = sMODTxRxMsg.aData[0];
            ucMODTxByteCnt = 1;
        }
        /* ******************** Step = INIT, RX_ING, RX_WAIT ********** */
        else if (ucMODCtrlStep != MOD_STEP_TX_ING)
        {   MOD_STS_SET_BIT(MOD_STS_ERR_TX);
            MOD_SCI_TC_INT_DIS();
            MOD_SCI_RX_EN();
        }
        /* ******************** Step = TX_ING, Cnt < Leng ************* */
        else if (ucMODTxByteCnt < sMODTxRxMsg.ucLeng)
        {   MOD_STS_CLR_BIT(MOD_STS_ERR_TX);
            MOD_SCI_DR_REG = sMODTxRxMsg.aData[ucMODTxByteCnt++];
        }
        /* ******************** Step = TX_ING, Cnt = Leng ************* */
        else
        {   MOD_SCI_TC_INT_DIS();
            MOD_SCI_RX_EN();
            MOD_STS_CLR_BIT(MOD_STS_TO_1P5_ON);
            MODOverTimerSet(usMODOverTime3P5);
        }
    }
}
#endif

/* ******************************************************************** */
/*                            MODTaskLoop ()                            */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
void MODTaskLoop (void)
{   INT08U ucTmp, ucErr;
    ucMODCtrlStep = MOD_STEP_INIT;
    MOD_STS_SET_BIT(MOD_STS_ERR_RX | MOD_STS_ERR_ADDR | MOD_STS_ERR_TX);
    MOD_STS_CLR_BIT(MOD_STS_TO_1P5_ON);
    MODOverTimerSet(usMODOverTime3P5);
    while (1)
    {   ucTmp = MODGetCmdChar(MOD_RX_TO_TICKS, &ucErr);
        if ((ucErr == MOD_NO_ERR) && (ucTmp == MOD_COMD_RX_RDY))
        {   ucTmp = MODProcessRxMsg(&sMODTxRxMsg);
            if ((ucTmp == MOD_TRUE) && (ucMODCtrlStep == MOD_STEP_IDLE))
            {   MODSetupTxMsg(&sMODTxRxMsg);
                MOD_SCI_RX_DIS();
                MOD_SCI_TC_INT_EN();
            }
        }
    }
}
#endif

/* ******************************************************************** */
/*                           MODProcessRxMsg ()                         */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
INT08U MODProcessRxMsg (MOD_MSG_STR *pMsg)
{   INT08U ucAddr, ucCode, ucLeng;
    INT16U usBegin, usSize, usLast;
    ucLeng = pMsg->ucLeng;
    ucAddr = pMsg->aData[0];
    ucCode = pMsg->aData[1];
    /* **************************************************************** */
    /*                            If Data Error                         */
    /* **************************************************************** */
    if (ucLeng < 4)
    {   return MOD_FALSE;
    }
    if ((ucAddr != 0) && (ucAddr != pMsg->ucAddr))
    {   return MOD_FALSE;
    }
    if (MODCheckMsgCrc16(pMsg) == MOD_FALSE)
    {   return MOD_FALSE;
    }
    /* **************************************************************** */
    /*                     0x02: MOD_CODE_READ_DINS                     */
    /* **************************************************************** */
    if (ucCode == MOD_CODE_READ_DINS)
    {   if ((ucAddr != 0) && (ucLeng == 8))
        {   pMsg->aData[1] = 0x80 + MOD_CODE_READ_DINS;
            pMsg->aData[2] = 0x01;
            pMsg->ucLeng   = 3;
            return MOD_TRUE;
        }
    }
    /* **************************************************************** */
    /*                     0x01: MOD_CODE_READ_DOUTS                    */
    /* **************************************************************** */
    else if (ucCode == MOD_CODE_READ_DOUTS)
    {   if ((ucAddr != 0) && (ucLeng == 8))
        {   pMsg->aData[1] = 0x80 + MOD_CODE_READ_DOUTS;
            pMsg->aData[2] = 0x01;
            pMsg->ucLeng   = 3;
            return MOD_TRUE;
        }
    }
    /* **************************************************************** */
    /*                     0x05: MOD_CODE_WRITE_DOUT                    */
    /* **************************************************************** */
    else if (ucCode == MOD_CODE_WRITE_DOUT)
    {   if ((ucAddr != 0) && (ucLeng == 8))
        {   pMsg->aData[1] = 0x80 + MOD_CODE_WRITE_DOUT;
            pMsg->aData[2] = 0x01;
            pMsg->ucLeng   = 3;
            return MOD_TRUE;
        }
    }
    /* **************************************************************** */
    /*                     0x0F: MOD_CODE_WRITE_DOUTS                   */
    /* **************************************************************** */
    else if (ucCode == MOD_CODE_WRITE_DOUTS)
    {   if (ucAddr != 0)
        {   pMsg->aData[1] = 0x80 + MOD_CODE_WRITE_DOUTS;
            pMsg->aData[2] = 0x01;
            pMsg->ucLeng   = 3;
            return MOD_TRUE;
        }
    }
    /* **************************************************************** */
    /*                     0x03: MOD_CODE_READ_PARAMS                   */
    /* **************************************************************** */
    else if (ucCode == MOD_CODE_READ_PARAMS)
    {   usBegin = MOD_US_CREAT(pMsg->aData[2], pMsg->aData[3]);
        usSize  = MOD_US_CREAT(pMsg->aData[4], pMsg->aData[5]);
        usLast  = usBegin + usSize;
        if((usBegin >= DB_PARAM_SIZE) ||
           (usLast  >= DB_PARAM_SIZE) ||
           (usSize  >= 126))
        {   pMsg->aData[1] = 0x80 + MOD_CODE_READ_PARAMS;
            pMsg->aData[2] = 0x02;
            pMsg->ucLeng   = 3;
            return MOD_TRUE;
        }
        pMsg->aData[1] = MOD_CODE_READ_PARAMS;
        pMsg->aData[2] = (INT08U)(usSize * 2);
        pMsg->ucLeng   = (INT08U)(usSize * 2 + 3);
        MODReadParams(&pMsg->aData[3], usBegin, usSize);
        return MOD_TRUE;
    }
    /* **************************************************************** */
    /*                     0x06: MOD_CODE_WRITE_PARAM                   */
    /* **************************************************************** */
    else if (ucCode == MOD_CODE_WRITE_PARAM)
    {   usBegin = MOD_US_CREAT(pMsg->aData[2], pMsg->aData[3]);
        usSize  = MOD_US_CREAT(pMsg->aData[4], pMsg->aData[5]);
        if (ucLeng != 8)
        {   return MOD_FALSE;
        }
        else if (usBegin >= DB_PARAM_SIZE)
        {   pMsg->aData[1] = 0x80 + MOD_CODE_WRITE_PARAM;
            pMsg->aData[2] = 0x02;
            pMsg->ucLeng   = 3;
            return MOD_TRUE;
        }
        MODWriteParam(usBegin, usSize);
        pMsg->aData[1] = MOD_CODE_WRITE_PARAM;
        pMsg->aData[2] = MOD_UC_HIGH(usBegin);
        pMsg->aData[3] = MOD_UC_LOW(usBegin);
        pMsg->aData[4] = MOD_UC_HIGH(usSize);
        pMsg->aData[5] = MOD_UC_LOW(usSize);
        pMsg->ucLeng   = 6;
        return MOD_TRUE;
    }
    /* **************************************************************** */
    /*                     0x10: MOD_CODE_WRITE_PARAMS                  */
    /* **************************************************************** */
    else if (ucCode == MOD_CODE_WRITE_PARAMS)
    {   usBegin = MOD_US_CREAT(pMsg->aData[2], pMsg->aData[3]);
        usSize  = MOD_US_CREAT(pMsg->aData[4], pMsg->aData[5]);
        usLast  = usBegin + usSize;
        if((usBegin >= DB_PARAM_SIZE) ||
           (usLast  >= DB_PARAM_SIZE) ||
           (usSize  >= 126))
        {   pMsg->aData[1] = 0x80 + MOD_CODE_WRITE_PARAMS;
            pMsg->aData[2] = 0x02;
            pMsg->ucLeng   = 3;
            return MOD_TRUE;
        }
        MODWriteParams(&pMsg->aData[7], usBegin, usSize);
        pMsg->aData[1] = MOD_CODE_WRITE_PARAMS;
        pMsg->aData[2] = MOD_UC_HIGH(usBegin);
        pMsg->aData[3] = MOD_UC_LOW(usBegin);
        pMsg->aData[4] = MOD_UC_HIGH(usSize);
        pMsg->aData[5] = MOD_UC_LOW(usSize);
        pMsg->ucLeng   = 6;
        return MOD_TRUE;
    }    
    /* **************************************************************** */
    /*                     0x17: MOD_CODE_R_W_PARAMS                    */
    /* **************************************************************** */
    else if (ucCode == MOD_CODE_R_W_PARAMS)
    {   usBegin = MOD_US_CREAT(pMsg->aData[6], pMsg->aData[7]);
        usSize  = MOD_US_CREAT(pMsg->aData[8], pMsg->aData[9]);
        usLast  = usBegin + usSize;
        if((usBegin >= DB_PARAM_SIZE) ||
           (usLast  >= DB_PARAM_SIZE) ||
           (usSize  >= 119))
        {   pMsg->aData[1] = 0x80 + MOD_CODE_R_W_PARAMS;
            pMsg->aData[2] = 0x02;
            pMsg->ucLeng   = 3;
            return MOD_TRUE;
        }
        MODWriteParams(&pMsg->aData[11], usBegin, usSize);
        usBegin = MOD_US_CREAT(pMsg->aData[2], pMsg->aData[3]);
        usSize  = MOD_US_CREAT(pMsg->aData[4], pMsg->aData[5]);
        usLast  = usBegin + usSize;
        if((usBegin >= DB_PARAM_SIZE) ||
           (usLast  >= DB_PARAM_SIZE) ||
           (usSize  >= 119))
        {   pMsg->aData[1] = 0x80 + MOD_CODE_R_W_PARAMS;
            pMsg->aData[2] = 0x02;
            pMsg->ucLeng   = 3;
            return MOD_TRUE;
        }
        pMsg->aData[1] = MOD_CODE_R_W_PARAMS;
        pMsg->aData[2] = (INT08U)(usSize * 2);
        pMsg->ucLeng   = (INT08U)(usSize * 2 + 3);
        MODReadParams(&pMsg->aData[3], usBegin, usSize);
        return MOD_TRUE;
    }    
    /* **************************************************************** */
    /*                     0x16: MOD_CODE_MASK_PARAM                    */
    /* **************************************************************** */
    else if (ucCode == MOD_CODE_MASK_PARAM)
    {   if (ucAddr != 0)
        {   pMsg->aData[1] = 0x80 + MOD_CODE_MASK_PARAM;
            pMsg->aData[2] = 0x01;
            pMsg->ucLeng   = 3;
            return MOD_TRUE;
        }
    }    
    /* **************************************************************** */
    /*                     0x04: MOD_CODE_READ_MEASUS                   */
    /* **************************************************************** */
    else if (ucCode == MOD_CODE_READ_MEASUS)
    {   usBegin = MOD_US_CREAT(pMsg->aData[2], pMsg->aData[3]);
        usSize  = MOD_US_CREAT(pMsg->aData[4], pMsg->aData[5]);
        usLast  = usBegin + usSize;
        if((usBegin >= DB_MEASU_SIZE) ||
           (usLast  >= DB_MEASU_SIZE) ||
           (usSize  >= 126))
        {   pMsg->aData[1] = 0x80 + MOD_CODE_READ_MEASUS;
            pMsg->aData[2] = 0x02;
            pMsg->ucLeng   = 3;
            return MOD_TRUE;
        }
        pMsg->aData[1] = MOD_CODE_READ_MEASUS;
        pMsg->aData[2] = (INT08U)(usSize * 2);
        pMsg->ucLeng   = (INT08U)(usSize * 2 + 3);
        MODReadMeasus(&pMsg->aData[3], usBegin, usSize);
        return MOD_TRUE;
    }
    /* **************************************************************** */
    /*                     0x43: MOD_CODE_WRITE_MEASU (Self defined)    */
    /* **************************************************************** */
    else if (ucCode == MOD_CODE_WRITE_MEASU)
    {   usBegin = MOD_US_CREAT(pMsg->aData[2], pMsg->aData[3]);
        usSize  = MOD_US_CREAT(pMsg->aData[4], pMsg->aData[5]);
        if (ucLeng != 8)
        {   return MOD_FALSE;
        }
        else if (usBegin >= DB_MEASU_SIZE)
        {   pMsg->aData[1] = 0x80 + MOD_CODE_WRITE_MEASU;
            pMsg->aData[2] = 0x02;
            pMsg->ucLeng   = 3;
            return MOD_TRUE;
        }
        MODWriteMeasu(usBegin, usSize);
        pMsg->aData[1] = MOD_CODE_WRITE_MEASU;
        pMsg->aData[2] = MOD_UC_HIGH(usBegin);
        pMsg->aData[3] = MOD_UC_LOW(usBegin);
        pMsg->aData[4] = MOD_UC_HIGH(usSize);
        pMsg->aData[5] = MOD_UC_LOW(usSize);
        pMsg->ucLeng   = 6;
        return MOD_TRUE;
    }
    /* **************************************************************** */
    /*                     0x44: MOD_CODE_WRITE_MEASUS (Self defined)   */
    /* **************************************************************** */
    else if (ucCode == MOD_CODE_WRITE_MEASUS)
    {   usBegin = MOD_US_CREAT(pMsg->aData[2], pMsg->aData[3]);
        usSize  = MOD_US_CREAT(pMsg->aData[4], pMsg->aData[5]);
        usLast  = usBegin + usSize;
        if((usBegin >= DB_PARAM_SIZE) ||
           (usLast  >= DB_PARAM_SIZE) ||
           (usSize  >= 126))
        {   pMsg->aData[1] = 0x80 + MOD_CODE_WRITE_MEASUS;
            pMsg->aData[2] = 0x02;
            pMsg->ucLeng   = 3;
            return MOD_TRUE;
        }
        MODWriteMeasus(&pMsg->aData[7], usBegin, usSize);
        pMsg->aData[1] = MOD_CODE_WRITE_MEASUS;
        pMsg->aData[2] = MOD_UC_HIGH(usBegin);
        pMsg->aData[3] = MOD_UC_LOW(usBegin);
        pMsg->aData[4] = MOD_UC_HIGH(usSize);
        pMsg->aData[5] = MOD_UC_LOW(usSize);
        pMsg->ucLeng   = 6;
        return MOD_TRUE;
    }
    /* **************************************************************** */
    /*                     0x14: MOD_CODE_READ_FILE                     */
    /* **************************************************************** */
    else if (ucCode == MOD_CODE_READ_FILE)
    {   if (ucAddr != 0)
        {   pMsg->aData[1] = 0x80 + MOD_CODE_READ_FILE;
            pMsg->aData[2] = 0x01;
            pMsg->ucLeng   = 3;
            return MOD_TRUE;
        }
    }
    /* **************************************************************** */
    /*                     0x15: MOD_CODE_WRITE_FILE                    */
    /* **************************************************************** */
    else if (ucCode == MOD_CODE_WRITE_FILE)
    {   if (ucAddr != 0)
        {   pMsg->aData[1] = 0x80 + MOD_CODE_WRITE_FILE;
            pMsg->aData[2] = 0x01;
            pMsg->ucLeng   = 3;
            return MOD_TRUE;
        }
    }
    /* **************************************************************** */
    /*                     0x2B: MOD_CODE_READ_DEV_ID                   */
    /* **************************************************************** */
    else if (ucCode == MOD_CODE_READ_DEV_ID)
    {   if (ucAddr != 0)
        {   pMsg->aData[1] = 0x80 + MOD_CODE_READ_DEV_ID;
            pMsg->aData[2] = 0x0E;
            pMsg->aData[3] = 0x01;
            pMsg->ucLeng   = 4;
            return MOD_TRUE;
        }
    }
    /* **************************************************************** */
    /*                      The End of Code Lookup                      */
    /* **************************************************************** */
    return MOD_FALSE;
}
#endif

/* ******************************************************************** */
/*                           MODSetupTxMsg ()                           */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
void MODSetupTxMsg (MOD_MSG_STR *pMsg)
{   INT16U usTemp;
    INT08U ucLeng;
    ucLeng = pMsg->ucLeng;
    usTemp = MODGetCrc16Code(&pMsg->aData[0], ucLeng);
    pMsg->aData[0]        = pMsg->ucAddr;
    pMsg->aData[ucLeng++] = MOD_UC_LOW(usTemp);
    pMsg->aData[ucLeng++] = MOD_UC_HIGH(usTemp);
    pMsg->ucLeng          = ucLeng;
}
#endif

/* ******************************************************************** */
/*                           MODCheckMsgCrc16()                         */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
INT08U MODCheckMsgCrc16 (MOD_MSG_STR *pMsg)
{   INT16U usTemp, usData;
    INT08U ucLeng;
    ucLeng = pMsg->ucLeng;
    usTemp = MODGetCrc16Code(&pMsg->aData[0], ucLeng-2);
    usData = MOD_US_CREAT(pMsg->aData[ucLeng-2], pMsg->aData[ucLeng-1]);
    return usTemp == usData ? MOD_TRUE : MOD_FALSE;
}
#endif

/* ******************************************************************** */
/*                            MODGetCrc16Code()                         */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
INT16U MODGetCrc16Code (INT08U *pBuf, INT08U ucSize)
{   INT08U ucIndex = 0;
    INT08U ucCrcHi = 0xFF;
    INT08U ucCrcLo = 0xFF;
    while (ucSize--)
    {   ucIndex = ucCrcHi ^ (*pBuf++);
        ucCrcHi = ucCrcLo ^ aMODCrc16TabHi[ucIndex];
        ucCrcLo = aMODCrc16TabLo[ucIndex];
    }
    return ((INT16U)ucCrcHi << 8) + (INT16U)ucCrcLo;
}
#endif

/* ******************************************************************** */
/*                          MODCmdBufInit()                             */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
void MODCmdBufInit (void)
{   MOD_RING_STR *pbuf;
    pbuf = &sMODRingBuf;
    pbuf->usRingBufRxCtr   =  0;
    pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxOutPtr = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxSem    =  OSSemCreate(0);
}
#endif

/* ******************************************************************** */
/*                          MODIsRxEmpty()                              */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
INT08U MODIsRxEmpty (void)
{   OS_CPU_SR cpu_sr = 0;
    MOD_RING_STR *pbuf;
    pbuf = &sMODRingBuf;
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufRxCtr == 0)
    {   OS_EXIT_CRITICAL();
        return MOD_TRUE;
    }   else
    {   OS_EXIT_CRITICAL();
        return MOD_FALSE;
    }
}
#endif

/* ******************************************************************** */
/*                          MODPutRxChar()                              */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
void MODPutRxChar (INT08U c)
{   MOD_RING_STR *pbuf;
    pbuf = &sMODRingBuf;
    if (pbuf->usRingBufRxCtr < MOD_RX_BUF_SIZE)
    {   pbuf->usRingBufRxCtr++;
        *pbuf->pRingBufRxInPtr++ = c;
        if (pbuf->pRingBufRxInPtr == &pbuf->ucRingBufRx[MOD_RX_BUF_SIZE])
        {   pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufRxSem);
    }
}
#endif

/* ******************************************************************** */
/*                           MODGetCmdChar()                            */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
INT08U MODGetCmdChar (INT16U to, INT08U *err)
{   OS_CPU_SR cpu_sr = 0;
    INT08U c, oserr;
    MOD_RING_STR *pbuf;
    pbuf = &sMODRingBuf;
    (void)OSSemPend(pbuf->pRingBufRxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   *err   = MOD_ERR_RX_TIMEOUT;
        return 0;
    }
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufRxCtr == 0)
    {   *err = MOD_ERR_RX_TIMEOUT;
        OS_EXIT_CRITICAL();
        return 0;
    }
    pbuf->usRingBufRxCtr--;
    c = *pbuf->pRingBufRxOutPtr++;
    if (pbuf->pRingBufRxOutPtr == &pbuf->ucRingBufRx[MOD_RX_BUF_SIZE])
    {   pbuf->pRingBufRxOutPtr  = &pbuf->ucRingBufRx[0];
    }
    OS_EXIT_CRITICAL();
    *err = MOD_NO_ERR;
    return c;
}
#endif

/* ******************************************************************** */
/*                           MODReadParam ()                            */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
INT16U MODReadParam (INT16U usBegin)
{   return aDBParam[usBegin];
}
#endif

/* ******************************************************************** */
/*                           MODReadParams ()                           */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
void MODReadParams (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT16U usTemp;
    while (usSize--)
    {   usTemp  = aDBParam[usBegin++];
        *pDat++ = MOD_UC_HIGH(usTemp);
        *pDat++ = MOD_UC_LOW(usTemp);
    }
}
#endif

/* ******************************************************************** */
/*                           MODWriteParam ()                           */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
void MODWriteParam (INT16U usBegin, INT16U usValue)
{   aDBParam[usBegin] = usValue;
}
#endif

/* ******************************************************************** */
/*                           MODWriteParams ()                          */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
void MODWriteParams (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT08U ucTmp1, ucTmp2;
    while (usSize--)
    {   ucTmp1 = *pDat++;
        ucTmp2 = *pDat++;
        aDBParam[usBegin++] = MOD_US_CREAT(ucTmp1, ucTmp2);
    }
}
#endif

/* ******************************************************************** */
/*                           MODReadMeasu ()                            */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
INT16U MODReadMeasu (INT16U usBegin)
{   return aDBMeasu[usBegin];
}
#endif

/* ******************************************************************** */
/*                           MODReadMeasus ()                           */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
void MODReadMeasus (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT16U usTemp;
    while (usSize--)
    {   usTemp  = aDBMeasu[usBegin++];
        *pDat++ = MOD_UC_HIGH(usTemp);
        *pDat++ = MOD_UC_LOW(usTemp);
    }
}
#endif

/* ******************************************************************** */
/*                           MODWriteMeasu ()                           */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
void MODWriteMeasu (INT16U usBegin, INT16U usValue)
{   aDBMeasu[usBegin] = usValue;
}
#endif

/* ******************************************************************** */
/*                           MODWriteMeasus ()                          */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
void MODWriteMeasus (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT08U ucTmp1, ucTmp2;
    while (usSize--)
    {   ucTmp1 = *pDat++;
        ucTmp2 = *pDat++;
        aDBMeasu[usBegin++] = MOD_US_CREAT(ucTmp1, ucTmp2);
    }
}
#endif

/* ******************************************************************** */
/*                          MODOverTimerInit ()                         */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
void MODOverTimerInit (void)
{   RCC->APB1ENR  |=  RCC_APB1ENR_TIM2EN;
    TIM2->CCR4     =  0xFFFF;
    TIM2->SR      &= ~TIM_SR_CC4IF;
    TIM2->DIER    &= ~TIM_DIER_CC4IE;
    TIM2->CR1     |=  TIM_CR1_CEN;
    TIM2->EGR      =  TIM_EGR_UG;
}
#endif

/* ******************************************************************** */
/*                          MODOverTimerSet ()                          */
/* ******************************************************************** */
#if (MOD_MODBUS_V10_ON == 1)
void MODOverTimerSet (INT16U usDelay)
{   TIM2->CCR4  = (TIM2->CNT) + usDelay;
    TIM2->SR   &= ~TIM_SR_CC4IF;
    TIM2->DIER |=  TIM_DIER_CC4IE;
    TIM2->EGR   =  TIM_EGR_UG;
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */

