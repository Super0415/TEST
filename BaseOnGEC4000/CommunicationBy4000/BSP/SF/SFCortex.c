/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File SFCortex.c                         */
/* ******************************************************************** */

#define   SF_GLOBALS
#include "TYPCortex.h"
#include "math.h"

/* ******************************************************************** */
/*                            CRC16 Tables                              */
/* ******************************************************************** */
const INT08U aSFCrc16TabHi[256] =
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
const INT08U aSFCrc16TabLo[256] =
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
//函数：SFProcessHostRxModMsg
//接口：主机接收数据时的处理
//说明：
//备注：


INT08U SFProcessHostRxModMsg (MODBUS_MSG *pMsg)
{
    INT08U ucAddr,Data16uleng;//usBegin,usPar;
	  INT08U DataType = 0;
	  INT16U Correct = 0;
    ucAddr = pMsg->aData[0];
    if (pMsg->ucLeng < 4)
    {   return SF_FALSE;
    }
    if ((ucAddr != 0) && (ucAddr != pMsg->ucAddr))
    {   return SF_FALSE;
    }
    if (SFCheckModMsgCrc(pMsg) == SF_FALSE)
    {   return SF_FALSE;
    }	
    DataType = 0x01;
		//Correct 的低8位 记录报文长度， 高8位 中前4位记录报文类型区分是发送还是接收
		Correct = SF_UC_ToHIGH(DataType) | SF_UC_ToLow(Data16uleng); 
		SFUSARTRecordMesure(pMsg,pMsg->ucLeng,Correct); //记录接收到的报文
		usDBhRS485RXToLeng ++;
		return SF_TRUE;
}
/* ******************************************************************** */
/*                           SFProcessRxModMsg ()                       */
/* ******************************************************************** */
INT08U SFProcessRxModMsg (MODBUS_MSG *pMsg)
{   INT08U ucAddr, ucCode;
    INT16U usBegin, usSize;
    ucAddr = pMsg->aData[0];
    ucCode = pMsg->aData[1];
    /* **************************************************************** */
    /*                            If Data Error                         */
    /* **************************************************************** */
    if (pMsg->ucLeng < 4)
    {   return SF_FALSE;
    }
    if ((ucAddr != 0) && (ucAddr != pMsg->ucAddr))
    {   return SF_FALSE;
    }
    if (SFCheckModMsgCrc(pMsg) == SF_FALSE)
    {   return SF_FALSE;
    }
    /* **************************************************************** */
    /*                     0x02: SF_MOD_READ_DINS                       */
    /* **************************************************************** */
    if (ucCode == SF_MOD_READ_DINS)
    {   if ((ucAddr != 0) && (pMsg->ucLeng == 8))
        {   pMsg->aData[1] = 0x80 + SF_MOD_READ_DINS;
            pMsg->aData[2] = 0x01;
            pMsg->ucLeng   = 3;
            return SF_TRUE;
        }
    }
    /* **************************************************************** */
    /*                     0x01: SF_MOD_READ_DOUTS                      */
    /* **************************************************************** */
    else if (ucCode == SF_MOD_READ_DOUTS)
    {   if ((ucAddr != 0) && (pMsg->ucLeng == 8))
        {   pMsg->aData[1] = 0x80 + SF_MOD_READ_DOUTS;
            pMsg->aData[2] = 0x01;
            pMsg->ucLeng   = 3;
            return SF_TRUE;
        }
    }
    /* **************************************************************** */
    /*                     0x05: SF_MOD_WRITE_DOUT                      */
    /* **************************************************************** */
    else if (ucCode == SF_MOD_WRITE_DOUT)
    {   if ((ucAddr != 0) && (pMsg->ucLeng == 8))
        {   pMsg->aData[1] = 0x80 + SF_MOD_WRITE_DOUT;
            pMsg->aData[2] = 0x01;
            pMsg->ucLeng   = 3;
            return SF_TRUE;
        }
    }
    /* **************************************************************** */
    /*                     0x0F: SF_MOD_WRITE_DOUTS                     */
    /* **************************************************************** */
    else if (ucCode == SF_MOD_WRITE_DOUTS)
    {   if (ucAddr != 0)
        {   pMsg->aData[1] = 0x80 + SF_MOD_WRITE_DOUTS;
            pMsg->aData[2] = 0x01;
            pMsg->ucLeng   = 3;
            return SF_TRUE;
        }
    }
    /* **************************************************************** */
    /*                     0x03: SF_MOD_READ_PARAMS                     */
    /* **************************************************************** */
    else if (ucCode == SF_MOD_READ_PARAMS)
    {   usBegin = SF_US_CREAT(pMsg->aData[2], pMsg->aData[3]);
        usSize  = SF_US_CREAT(pMsg->aData[4], pMsg->aData[5]);
        if (SFModGetParams(&pMsg->aData[3], usBegin, usSize) == SF_FALSE)
        {   pMsg->aData[1] = 0x80 + SF_MOD_READ_PARAMS;
            pMsg->aData[2] = 0x02;
            pMsg->ucLeng   = 3;
            return SF_TRUE;
        }
        pMsg->aData[1] = SF_MOD_READ_PARAMS;
        pMsg->aData[2] = (INT08U)(usSize * 2);
        pMsg->ucLeng   = (INT08U)(usSize * 2 + 3);
        return SF_TRUE;
    }
    /* **************************************************************** */
    /*                     0x06: SF_MOD_WRITE_PARAM                     */
    /* **************************************************************** */
    else if (ucCode == SF_MOD_WRITE_PARAM)
    {   usBegin = SF_US_CREAT(pMsg->aData[2], pMsg->aData[3]);
        usSize  = SF_US_CREAT(pMsg->aData[4], pMsg->aData[5]);
        if (pMsg->ucLeng != 8)
        {   return SF_FALSE;
        }
        if (SFModSetParam(usBegin, usSize) == SF_FALSE)
        {   pMsg->aData[1] = 0x80 + SF_MOD_WRITE_PARAM;
            pMsg->aData[2] = 0x02;
            pMsg->ucLeng   = 3;
            return SF_TRUE;
        }
        pMsg->aData[1] = SF_MOD_WRITE_PARAM;
        pMsg->aData[2] = SF_UC_HIGH(usBegin);
        pMsg->aData[3] = SF_UC_LOW(usBegin);
        pMsg->aData[4] = SF_UC_HIGH(usSize);
        pMsg->aData[5] = SF_UC_LOW(usSize);
        pMsg->ucLeng   = 6;
        return SF_TRUE;
    }
    /* **************************************************************** */
    /*                     0x10: SF_MOD_WRITE_PARAMS                    */
    /* **************************************************************** */
    else if (ucCode == SF_MOD_WRITE_PARAMS)
    {   usBegin = SF_US_CREAT(pMsg->aData[2], pMsg->aData[3]);
        usSize  = SF_US_CREAT(pMsg->aData[4], pMsg->aData[5]);
        if (SFModSetParams(&pMsg->aData[7], usBegin, usSize) == SF_FALSE)
        {   pMsg->aData[1] = 0x80 + SF_MOD_WRITE_PARAMS;
            pMsg->aData[2] = 0x02;
            pMsg->ucLeng   = 3;
            return SF_TRUE;
        }
        pMsg->aData[1] = SF_MOD_WRITE_PARAMS;
        pMsg->aData[2] = SF_UC_HIGH(usBegin);
        pMsg->aData[3] = SF_UC_LOW(usBegin);
        pMsg->aData[4] = SF_UC_HIGH(usSize);
        pMsg->aData[5] = SF_UC_LOW(usSize);
        pMsg->ucLeng   = 6;
        return SF_TRUE;
    }
    /* **************************************************************** */
    /*                     0x17: SF_MOD_R_W_PARAMS                      */
    /* **************************************************************** */
    else if (ucCode == SF_MOD_R_W_PARAMS)
    {   usBegin = SF_US_CREAT(pMsg->aData[6], pMsg->aData[7]);
        usSize  = SF_US_CREAT(pMsg->aData[8], pMsg->aData[9]);
        if (SFModSetParams(&pMsg->aData[11], usBegin, usSize) == SF_FALSE)
        {   pMsg->aData[1] = 0x80 + SF_MOD_R_W_PARAMS;
            pMsg->aData[2] = 0x02;
            pMsg->ucLeng   = 3;
            return SF_TRUE;
        }
        usBegin = SF_US_CREAT(pMsg->aData[2], pMsg->aData[3]);
        usSize  = SF_US_CREAT(pMsg->aData[4], pMsg->aData[5]);
        if (SFModGetParams(&pMsg->aData[3], usBegin, usSize) == SF_FALSE)
        {   pMsg->aData[1] = 0x80 + SF_MOD_R_W_PARAMS;
            pMsg->aData[2] = 0x02;
            pMsg->ucLeng   = 3;
            return SF_TRUE;
        }
        pMsg->aData[1] = SF_MOD_R_W_PARAMS;
        pMsg->aData[2] = (INT08U)(usSize * 2);
        pMsg->ucLeng   = (INT08U)(usSize * 2 + 3);
        return SF_TRUE;
    }    
    /* **************************************************************** */
    /*                     0x16: SF_MOD_MASK_PARAM                      */
    /* **************************************************************** */
    else if (ucCode == SF_MOD_MASK_PARAM)
    {   if (ucAddr != 0)
        {   pMsg->aData[1] = 0x80 + SF_MOD_MASK_PARAM;
            pMsg->aData[2] = 0x01;
            pMsg->ucLeng   = 3;
            return SF_TRUE;
        }
    }
    /* **************************************************************** */
    /*                     0x04: SF_MOD_READ_INPUTS                     */
    /* **************************************************************** */
    else if (ucCode == SF_MOD_READ_INPUTS)
    {   if (ucAddr != 0)
        {   pMsg->aData[1] = 0x80 + SF_MOD_READ_INPUTS;
            pMsg->aData[2] = 0x01;
            pMsg->ucLeng   = 3;
            return SF_TRUE;
        }
    }
    /* **************************************************************** */
    /*                     0x14: SF_MOD_READ_FILE                       */
    /* **************************************************************** */
    else if (ucCode == SF_MOD_READ_FILE)
    {   if (ucAddr != 0)
        {   pMsg->aData[1] = 0x80 + SF_MOD_READ_FILE;
            pMsg->aData[2] = 0x01;
            pMsg->ucLeng   = 3;
            return SF_TRUE;
        }
    }
    /* **************************************************************** */
    /*                     0x15: SF_MOD_WRITE_FILE                      */
    /* **************************************************************** */
    else if (ucCode == SF_MOD_WRITE_FILE)
    {   if (ucAddr != 0)
        {   pMsg->aData[1] = 0x80 + SF_MOD_WRITE_FILE;
            pMsg->aData[2] = 0x01;
            pMsg->ucLeng   = 3;
            return SF_TRUE;
        }
    }
    /* **************************************************************** */
    /*                     0x2B: SF_MOD_READ_DEV_ID                     */
    /* **************************************************************** */
    else if (ucCode == SF_MOD_READ_DEV_ID)
    {   if (ucAddr != 0)
        {   pMsg->aData[1] = 0x80 + SF_MOD_READ_DEV_ID;
            pMsg->aData[2] = 0x0E;
            pMsg->aData[3] = 0x01;
            pMsg->ucLeng   = 4;
            return SF_TRUE;
        }
    }
    /* **************************************************************** */
    /*                      The End of Code Lookup                      */
    /* **************************************************************** */
    return SF_FALSE;
}

/* ******************************************************************** */
/*                            SFCheckModMsgCrc()                        */
/* ******************************************************************** */
INT08U SFCheckModMsgCrc (MODBUS_MSG *pMsg)
{   INT16U usTemp, usData;
    INT08U ucLeng;
    ucLeng = pMsg->ucLeng;
    if (ucLeng <= 2)
    {   return SF_FALSE;
    }
    usTemp = SFGetCrc16Code(&pMsg->aData[0], ucLeng-2);
   #if (SF_MOD_CRC_LOW_FIRST == 1)
    usData = SF_US_CREAT(pMsg->aData[ucLeng-1], pMsg->aData[ucLeng-2]);
   #else
    usData = SF_US_CREAT(pMsg->aData[ucLeng-2], pMsg->aData[ucLeng-1]);
   #endif
    return usTemp == usData ? SF_TRUE : SF_FALSE;
}

/* ******************************************************************** */
/*                            SFGetCrc16Code()                          */
/* ******************************************************************** */
INT16U SFGetCrc16Code (INT08U *pBuf, INT08U ucSize)
{   INT08U ucIndex = 0;
    INT08U ucCrcHi = 0xFF;
    INT08U ucCrcLo = 0xFF;
    while (ucSize--)
    {   ucIndex = ucCrcHi ^ (*pBuf++);
        ucCrcHi = ucCrcLo ^ aSFCrc16TabHi[ucIndex];
        ucCrcLo = aSFCrc16TabLo[ucIndex];
    }
    return ((INT16U)ucCrcHi << 8) + (INT16U)ucCrcLo;
}

/* ******************************************************************** */
/*                          SFModGetParams()                            */
/* ******************************************************************** */
INT08U SFModGetParams (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   if (usBegin < DB_PARAM_SIZE)
    {   return DBGetParam08p(pDat, usBegin, usSize);
    }
    usBegin -= DB_PARAM_SIZE;
    if (usBegin < DB_FUNCT_SIZE)
    {   return DBGetFunct08p(pDat, usBegin, usSize);
    }
    usBegin -= DB_FUNCT_SIZE;
    if (usBegin < DB_CURVE_SIZE)
    {   return DBGetCurve08p(pDat, usBegin, usSize);
    }
    usBegin -= DB_CURVE_SIZE;
    return DBGetMeasu08p(pDat, usBegin, usSize);
}

/* ******************************************************************** */
/*                           SFSetupModMsgCrc()                         */
/* ******************************************************************** */
void SFSetupModMsgCrc (MODBUS_MSG *pMsg)
{   INT16U usTemp;
    INT08U ucLeng;
    ucLeng = pMsg->ucLeng;
    pMsg->aData[0]        = pMsg->ucAddr;
    usTemp = SFGetCrc16Code(&pMsg->aData[0], ucLeng);
   #if (SF_MOD_CRC_LOW_FIRST == 1)
    pMsg->aData[ucLeng++] = SF_UC_LOW(usTemp);
    pMsg->aData[ucLeng++] = SF_UC_HIGH(usTemp);
   #else
    pMsg->aData[ucLeng++] = SF_UC_HIGH(usTemp);
    pMsg->aData[ucLeng++] = SF_UC_LOW(usTemp);
   #endif
    pMsg->ucLeng          = ucLeng;
}

/* ******************************************************************** */
/*                          SFFill16u()                                 */
/* ******************************************************************** */
void SFFill16u (INT16U *pDest, INT16U usData, INT16U usSize)
{   INT16U usSiz;
    usSiz = usSize / 8;
    while (usSiz--)
    {   *pDest++ = usData;
        *pDest++ = usData;
        *pDest++ = usData;
        *pDest++ = usData;
        *pDest++ = usData;
        *pDest++ = usData;
        *pDest++ = usData;
        *pDest++ = usData;
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   *pDest++ = usData;
    }
}
/* ******************************************************************** */
/*                          SFModSetParam()                             */
/* ******************************************************************** */
INT08U SFModSetParam (INT16U usBegin, INT16U usValue)
{   INT08U ucTmp;
    if (usBegin < DB_PARAM_SIZE)
    {   ucTmp = DBSetParam16u(usBegin, usValue);
        if (ucTmp != DB_FALSE)
        {   DBTskPutCmd(DB_CMD_SAVE_PARAM);
        }
        return ucTmp;
    }
    usBegin -= DB_PARAM_SIZE;
    if (usBegin < DB_FUNCT_SIZE)
    {   ucTmp = DBSetFunct16u(usBegin, usValue);
        if (ucTmp != DB_FALSE)
        {   DBTskPutCmd(DB_CMD_SAVE_FUNCT);
        }
        return ucTmp;
    }
    usBegin -= DB_FUNCT_SIZE;
    if (usBegin < DB_CURVE_SIZE)
    {   ucTmp = DBSetCurve16u(usBegin, usValue);
        if (ucTmp != DB_FALSE)
        {   DBTskPutCmd(DB_CMD_SAVE_CURVE);
        }
        return ucTmp;
    }
    usBegin -= DB_CURVE_SIZE;
    return DBSetMeasu16u(usBegin, usValue);
}
/* ******************************************************************** */
/*                          SFModSetParams()                            */
/* ******************************************************************** */
INT08U SFModSetParams (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   INT08U ucTmp;
    if (usBegin < DB_PARAM_SIZE)
    {   ucTmp = DBSetParam08p(pDat, usBegin, usSize);
        if (ucTmp != DB_FALSE)
        {   DBTskPutCmd(DB_CMD_SAVE_PARAM);
        }
        return ucTmp;
    }
    usBegin -= DB_PARAM_SIZE;
    if (usBegin < DB_FUNCT_SIZE)
    {   ucTmp = DBSetFunct08p(pDat, usBegin, usSize);
        if (ucTmp != DB_FALSE)
        {   DBTskPutCmd(DB_CMD_SAVE_FUNCT);
        }
        return ucTmp;
    }
    usBegin -= DB_FUNCT_SIZE;
    if (usBegin < DB_CURVE_SIZE)
    {   ucTmp = DBSetCurve08p(pDat, usBegin, usSize);
        if (ucTmp != DB_FALSE)
        {   DBTskPutCmd(DB_CMD_SAVE_CURVE);
        }
        return ucTmp;
    }
    usBegin -= DB_CURVE_SIZE;
    return DBSetMeasu08p(pDat, usBegin, usSize);
}


//函数：SFUSARTRecordMesure
//接口：记录USART信息
//说明：
//备注：
//#define CheckRS485RecordBuffISFULL(AL,NL)  (AL+NL+1)>(DB_HSTRY_SIZE/2) ? 1:0   //判断
#define RS485EndADDR  (DB_MEASU_NOR_SIZE+DB_HSTRY_SIZE/2)-1  //(100+200)-1 = 299
#define RS485StartADDR  DB_MEASU_NOR_SIZE+1  //(100+1 = 101
void SFUSARTRecordMesure(MODBUS_MSG *pMsg,INT16U uLeng, INT16U usSign)
{  
	  INT16U i = 0;
    INT08U usPar = Parity(uLeng);
	  INT16U Data16uleng = uLeng/2 + usPar+1;  //多出一位用于记录报文信息		
	
	  for(i = RS485EndADDR;i>RS485StartADDR+Data16uleng-1;i--)
		{
				aDBMeasu[i] = aDBMeasu[i-Data16uleng];  //最少到101位，保留第100位记录各种数据
		}
    aDBMeasu[RS485StartADDR] = usSign;

	  for(i = 1;i < Data16uleng;i++)  //在数组区段前部填充 DataLeng 的数据
	  {
        aDBMeasu[RS485StartADDR+i] = SF_UC_ToHIGH(pMsg->aData[(i-1)*2]) | SF_UC_ToLow(pMsg->aData[(i-1)*2+1]);
		}
		if(usPar)aDBMeasu[RS485StartADDR+Data16uleng-1] &= 0xFF00;
}
void SFUSARTRecordTxMesure(INT16U *pMsg,INT16U uLeng, INT16U usSign)
{  
	  INT16U i = 0;
    INT08U usPar = Parity(uLeng);
	  INT16U Data16uleng = uLeng/2 + usPar+1;  //多出一位用于记录报文信息		
	
	  for(i = RS485EndADDR;i>RS485StartADDR+Data16uleng-1;i--)
		{
				aDBMeasu[i] = aDBMeasu[i-Data16uleng];  //最少到101位，保留第100位记录各种数据
		}
		
     aDBMeasu[RS485StartADDR] = usSign;
	  for(i = 1;i < Data16uleng;i++)  //在数组区段前部填充 DataLeng 的数据
	  {
			aDBMeasu[RS485StartADDR+i] = SF_UC_ToHIGH((INT16U)*(pMsg+(i-1)*2)) | SF_UC_ToLow((INT16U)*(pMsg+(i-1)*2+1));
		}
		if(usPar)aDBMeasu[RS485StartADDR+Data16uleng-1] &= 0xFF00;  //报文长度为奇数是，报文压缩存贮，最后一个数据只有高位有数据，低位清空
}

/* ******************************************************************** */
/*                          SFCopy16u()                                 */
/* ******************************************************************** */
void SFCopy16u (INT16U *pSour, INT16U *pDest, INT16U usSize)
{   INT16U usSiz;
    usSiz = usSize / 8;
    while (usSiz--)
    {   *pDest++ = *pSour++;
        *pDest++ = *pSour++;
        *pDest++ = *pSour++;
        *pDest++ = *pSour++;
        *pDest++ = *pSour++;
        *pDest++ = *pSour++;
        *pDest++ = *pSour++;
        *pDest++ = *pSour++;
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   *pDest++ = *pSour++;
    }
}
/* ******************************************************************** */
/*                          SFCopyAndSum16u()                           */
/* ******************************************************************** */
INT16U SFCopyAndSum16u (INT16U *pSour, INT16U *pDest, INT16U usSize)
{   INT16U usSiz, usTmp, usSum;
    usSum = 0;
    usSiz = usSize / 8;
    while (usSiz--)
    {   usTmp     = *pSour++;
        *pDest++  =  usTmp;
        usSum    +=  usTmp;
        usTmp     = *pSour++;
        *pDest++  =  usTmp;
        usSum    +=  usTmp;
        usTmp     = *pSour++;
        *pDest++  =  usTmp;
        usSum    +=  usTmp;
        usTmp     = *pSour++;
        *pDest++  =  usTmp;
        usSum    +=  usTmp;
        usTmp     = *pSour++;
        *pDest++  =  usTmp;
        usSum    +=  usTmp;
        usTmp     = *pSour++;
        *pDest++  =  usTmp;
        usSum    +=  usTmp;
        usTmp     = *pSour++;
        *pDest++  =  usTmp;
        usSum    +=  usTmp;
        usTmp     = *pSour++;
        *pDest++  =  usTmp;
        usSum    +=  usTmp;
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   usTmp     = *pSour++;
        *pDest++  =  usTmp;
        usSum    +=  usTmp;
    }
    return usSum;
}
/* ******************************************************************** */
/*                          SFCompare16u()                              */
/* ******************************************************************** */
INT08U SFCompare16u (INT16U *pSouX, INT16U *pSouY, INT16U usSize)
{   INT16U usSiz;
    usSiz = usSize / 8;
    while (usSiz--)
    {   if (*pSouX++ != *pSouY++)
        {   return SF_DIFFERENT;
        }
        if (*pSouX++ != *pSouY++)
        {   return SF_DIFFERENT;
        }
        if (*pSouX++ != *pSouY++)
        {   return SF_DIFFERENT;
        }
        if (*pSouX++ != *pSouY++)
        {   return SF_DIFFERENT;
        }
        if (*pSouX++ != *pSouY++)
        {   return SF_DIFFERENT;
        }
        if (*pSouX++ != *pSouY++)
        {   return SF_DIFFERENT;
        }
        if (*pSouX++ != *pSouY++)
        {   return SF_DIFFERENT;
        }
        if (*pSouX++ != *pSouY++)
        {   return SF_DIFFERENT;
        }
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   if (*pSouX++ != *pSouY++)
        {   return SF_DIFFERENT;
        }
    }
    return SF_SAME;
}
/* ******************************************************************** */
/*                            SFCheckTime()                             */
/* ******************************************************************** */
INT08U SFCheckTime (INT16U usOld, INT16U usPer)
{   if ((INT16U)(usFW5msTimer-usOld) >= usPer)
    {   return SF_TRUE;
    }   else
    {   return SF_FALSE;
    }
}
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */

