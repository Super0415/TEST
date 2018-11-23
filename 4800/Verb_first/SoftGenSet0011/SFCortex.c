/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File SFCortex.c                         */
/*                            By: Wu Xuekui                             */
/*                             2014-10-14                               */
/* ******************************************************************** */

#define   SF_GLOBALS
#include "TYPCortex.h"
#include "arm_math.h"

/* ******************************************************************** */
/*                            Constant                                  */
/* ******************************************************************** */
const INT16U aSFTempMap0Adc[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap0Tmp[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap1Adc[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap1Tmp[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap2Adc[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap2Tmp[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap3Adc[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap3Tmp[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap4Adc[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap4Tmp[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap5Adc[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap5Tmp[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap6Adc[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap6Tmp[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap7Adc[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap7Tmp[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap8Adc[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap8Tmp[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap9Adc[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap9Tmp[10]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap10Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap10Tmp[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap11Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap11Tmp[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

const INT16U aSFLevelMap0Adc[10]  = {0, 4095, 0, 0, 0, 0, 0, 0, 0, 0};
const INT16U aSFLevelMap0Lvl[10]  = {0, 4095, 0, 0, 0, 0, 0, 0, 0, 0};
const INT16U aSFLevelMap1Adc[10]  = {0, 4095, 0, 0, 0, 0, 0, 0, 0, 0};
const INT16U aSFLevelMap1Lvl[10]  = {0, 1000, 0, 0, 0, 0, 0, 0, 0, 0};
const INT16U aSFLevelMap2Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFLevelMap2Lvl[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFLevelMap3Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFLevelMap3Lvl[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFLevelMap4Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFLevelMap4Lvl[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFLevelMap5Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFLevelMap5Lvl[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFLevelMap6Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFLevelMap6Lvl[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFLevelMap7Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFLevelMap7Lvl[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

const INT16U aSFPressMap0Adc[10]  = {14, 151, 274, 389, 496, 601, 693, 784, 871, 962};   //TEST-AD值
const INT16U aSFPressMap0Prs[10]  = { 0,  10,  20,  30,  40,  50,  60,  70,  80,  90};    //TEST-实际电阻值
const INT16U aSFPressMap1Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap1Prs[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap2Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap2Prs[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap3Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap3Prs[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap4Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap4Prs[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap5Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap5Prs[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap6Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap6Prs[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap7Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap7Prs[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap8Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap8Prs[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap9Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap9Prs[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap10Adc[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap10Prs[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap11Adc[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap11Prs[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

/* ******************************************************************** */
/*                            SFInit()                                  */
/* ******************************************************************** */
void SFInit (void)
{   usSFTimer = 0;
    usSFStatus = 0;
}

/* ******************************************************************** */
/*                            SFCheckTime()                             */
/* ******************************************************************** */
INT08U SFCheckTime (INT16U usOld, INT16U usPer)
{   if ((INT16U)(usSFTimer-usOld) >= usPer)
    {   return SF_TRUE;
    }   else
    {   return SF_FALSE;
    }
}

/* ******************************************************************** */
/*                          SFDelay32()                                 */
/* ******************************************************************** */
void SFDelay32 (INT32U uiDelay)
{   while (uiDelay--)
    {   asm(" NOP");
        asm(" NOP");
        asm(" NOP");
    }
}

/* ******************************************************************** */
/*                            SFAbs16s()                                */
/* ******************************************************************** */
INT16U SFAbs16s (INT16S ssData)
{   return ssData > 0 ? (INT16U)ssData : (INT16U)(-ssData);
}

/* ******************************************************************** */
/*                            SFSqrt32u()                               */
/* ******************************************************************** */
INT16U SFSqrt32u (INT32U uiInput)
{   INT32U uiDt, uiRt;
    uiDt  = uiInput;
    uiRt  = (INT32U)1 << 15;
    if ((uiRt * uiRt) > uiDt) uiRt -= (INT32U)1 << 15;
    uiRt += (INT32U)1 << 14;
    if ((uiRt * uiRt) > uiDt) uiRt -= (INT32U)1 << 14;
    uiRt += (INT32U)1 << 13;
    if ((uiRt * uiRt) > uiDt) uiRt -= (INT32U)1 << 13;
    uiRt += (INT32U)1 << 12;
    if ((uiRt * uiRt) > uiDt) uiRt -= (INT32U)1 << 12;
    uiRt += (INT32U)1 << 11;
    if ((uiRt * uiRt) > uiDt) uiRt -= (INT32U)1 << 11;
    uiRt += (INT32U)1 << 10;
    if ((uiRt * uiRt) > uiDt) uiRt -= (INT32U)1 << 10;
    uiRt += (INT32U)1 << 9;
    if ((uiRt * uiRt) > uiDt) uiRt -= (INT32U)1 << 9;
    uiRt += (INT32U)1 << 8;
    if ((uiRt * uiRt) > uiDt) uiRt -= (INT32U)1 << 8;
    uiRt += (INT32U)1 << 7;
    if ((uiRt * uiRt) > uiDt) uiRt -= (INT32U)1 << 7;
    uiRt += (INT32U)1 << 6;
    if ((uiRt * uiRt) > uiDt) uiRt -= (INT32U)1 << 6;
    uiRt += (INT32U)1 << 5;
    if ((uiRt * uiRt) > uiDt) uiRt -= (INT32U)1 << 5;
    uiRt += (INT32U)1 << 4;
    if ((uiRt * uiRt) > uiDt) uiRt -= (INT32U)1 << 4;
    uiRt += (INT32U)1 << 3;
    if ((uiRt * uiRt) > uiDt) uiRt -= (INT32U)1 << 3;
    uiRt += (INT32U)1 << 2;
    if ((uiRt * uiRt) > uiDt) uiRt -= (INT32U)1 << 2;
    uiRt += (INT32U)1 << 1;
    if ((uiRt * uiRt) > uiDt) uiRt -= (INT32U)1 << 1;
    uiRt += (INT32U)1 << 0;
    if ((uiRt * uiRt) > uiDt) uiRt -= (INT32U)1 << 0;
    return (INT16U)uiRt;
}

/* ******************************************************************** */
/*                           SFInterp16u()                              */
/* ******************************************************************** */
INT16U SFInterp16u (INT16U usXX, INT16U usX0, INT16U usX1, INT16U usY0, INT16U usY1)
{   if (usXX <= usX0)
    {   return usY0;
    }
    if (usXX >= usX1)
    {   return usY1;
    }
    usXX -= usX0;
    usX1 -= usX0;
    if (usY1 >= usY0)
    {   return usY0+(INT16U)((INT32U)(usY1-usY0)*(INT32U)usXX/(INT32U)usX1);
    }   else
    {   return usY0-(INT16U)((INT32U)(usY0-usY1)*(INT32U)usXX/(INT32U)usX1);
    }
}

/* ******************************************************************** */
/*                           SFInterp16s()                              */
/* ******************************************************************** */
INT16S SFInterp16s (INT16S ssXX, INT16S ssX0, INT16S ssX1, INT16S ssY0, INT16S ssY1)
{   INT16S ssTemp;
    ssTemp = ssX1 - ssX0;
    if (ssTemp == 0)
    {   return (ssY0 + ssY1) / 2;
    }
    else if (ssTemp > 0)
    {   if (ssXX <= ssX0)
        {   return ssY0;
        }
        else if (ssXX >= ssX1)
        {   return ssY1;
        }
    }
    else if (ssXX >= ssX0)
    {   return ssY0;
    }
    else if (ssXX <= ssX1)
    {   return ssY1;
    }
    return ssY0+(INT16S)((INT32S)(ssY1-ssY0)*(INT32S)(ssXX-ssX0)/(INT32S)ssTemp);
}

/* ******************************************************************** */
/*                          SFCopy16s()                                 */
/* ******************************************************************** */
void SFCopy16s (INT16S *pSour, INT16S *pDest, INT16U usSize)
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
/*                          SFCopy16sToCmplx()                          */
/* ******************************************************************** */
void SFCopy16sToCmplx (INT16S *pSour, FP32 *pDest, INT16U usSize)
{   INT16U usSiz;
    usSiz = usSize / 8;
    while (usSiz--)
    {   *pDest++ = (FP32)(*pSour++);
        *pDest++ = (FP32)0.0f;
        *pDest++ = (FP32)(*pSour++);
        *pDest++ = (FP32)0.0f;
        *pDest++ = (FP32)(*pSour++);
        *pDest++ = (FP32)0.0f;
        *pDest++ = (FP32)(*pSour++);
        *pDest++ = (FP32)0.0f;
        *pDest++ = (FP32)(*pSour++);
        *pDest++ = (FP32)0.0f;
        *pDest++ = (FP32)(*pSour++);
        *pDest++ = (FP32)0.0f;
        *pDest++ = (FP32)(*pSour++);
        *pDest++ = (FP32)0.0f;
        *pDest++ = (FP32)(*pSour++);
        *pDest++ = (FP32)0.0f;
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   *pDest++ = (FP32)(*pSour++);
        *pDest++ = (FP32)0.0f;
    }
}

/* ******************************************************************** */
/*                          SFFill16s()                                 */
/* ******************************************************************** */
void SFFill16s (INT16S *pDest, INT16S ssData, INT16U usSize)
{   INT16U usSiz;
    usSiz = usSize / 8;
    while (usSiz--)
    {   *pDest++ = ssData;
        *pDest++ = ssData;
        *pDest++ = ssData;
        *pDest++ = ssData;
        *pDest++ = ssData;
        *pDest++ = ssData;
        *pDest++ = ssData;
        *pDest++ = ssData;
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   *pDest++ = ssData;
    }
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
/*                          SFFill16u()                                 */
/* ******************************************************************** */
void SFFill32s (INT32S *pDest, INT32S siData, INT16U usSize)
{   INT16U usSiz;
    usSiz = usSize / 8;
    while (usSiz--)
    {   *pDest++ = siData;
        *pDest++ = siData;
        *pDest++ = siData;
        *pDest++ = siData;
        *pDest++ = siData;
        *pDest++ = siData;
        *pDest++ = siData;
        *pDest++ = siData;
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   *pDest++ = siData;
    }
}

/* ******************************************************************** */
/*                          SFFill16u()                                 */
/* ******************************************************************** */
void SFFill32u (INT32U *pDest, INT32U uiData, INT16U usSize)
{   INT16U usSiz;
    usSiz = usSize / 8;
    while (usSiz--)
    {   *pDest++ = uiData;
        *pDest++ = uiData;
        *pDest++ = uiData;
        *pDest++ = uiData;
        *pDest++ = uiData;
        *pDest++ = uiData;
        *pDest++ = uiData;
        *pDest++ = uiData;
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   *pDest++ = uiData;
    }
}

/* ******************************************************************** */
/*                           SFFill32f()                                */
/* ******************************************************************** */
void SFFill32f (FP32 *pDest, FP32 fData, INT16U usSize)
{   INT16U usSiz;
    usSiz = usSize / 8;
    while (usSiz--)
    {   *pDest++ = fData;
        *pDest++ = fData;
        *pDest++ = fData;
        *pDest++ = fData;
        *pDest++ = fData;
        *pDest++ = fData;
        *pDest++ = fData;
        *pDest++ = fData;
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   *pDest++ = fData;
    }
}

/* ******************************************************************** */
/*                           SFGetSum16s()                              */
/* ******************************************************************** */
INT32S SFGetSum16s (INT16S *pData, INT16U usSize)
{   INT32S siSum;
    INT16U usSiz;
    siSum = 0;
    usSiz = usSize / 8;
    while (usSiz--)
    {   siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   siSum += (INT32S)(*pData++);
    }
    return siSum;
}

/* ******************************************************************** */
/*                           SFGetSum16u()                              */
/* ******************************************************************** */
INT32U SFGetSum16u (INT16U *pData, INT16U usSize)
{   INT32U uiSum;
    INT16U usSiz;
    uiSum = 0;
    usSiz = usSize / 8;
    while (usSiz--)
    {   uiSum += (INT32U)(*pData++);
        uiSum += (INT32U)(*pData++);
        uiSum += (INT32U)(*pData++);
        uiSum += (INT32U)(*pData++);
        uiSum += (INT32U)(*pData++);
        uiSum += (INT32U)(*pData++);
        uiSum += (INT32U)(*pData++);
        uiSum += (INT32U)(*pData++);
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   uiSum += (INT32U)(*pData++);
    }
    return uiSum;
}

/* ******************************************************************** */
/*                           SFGetSum32f()                              */
/* ******************************************************************** */
FP32 SFGetSum32f (FP32 *pData, INT16U usSize)
{   FP32   fpSum;
    INT16U usSiz;
    fpSum = 0.0f;
    usSiz = usSize / 8;
    while (usSiz--)
    {   fpSum += *pData++;
        fpSum += *pData++;
        fpSum += *pData++;
        fpSum += *pData++;
        fpSum += *pData++;
        fpSum += *pData++;
        fpSum += *pData++;
        fpSum += *pData++;
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   fpSum += *pData++;
    }
    return fpSum;
}

/* ******************************************************************** */
/*                         SFGetAve16s()                                */
/* ******************************************************************** */
INT16S SFGetAve16s (INT16S *pData, INT16U usSize)
{   INT32S siSum;
    INT16U usSiz;
    siSum = 0;
    usSiz = usSize / 8;
    while (usSiz--)
    {   siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   siSum += (INT32S)(*pData++);
    }
    return (INT16S)(siSum / usSize);
}

/* ******************************************************************** */
/*                         SFGetAve16u()                                */
/* ******************************************************************** */
INT16U SFGetAve16u (INT16U *pData, INT16U usSize)
{   INT32U uiSum;
    INT16U usSiz;
    uiSum = 0;
    usSiz = usSize / 8;
    while (usSiz--)
    {   uiSum += (INT32U)(*pData++);
        uiSum += (INT32U)(*pData++);
        uiSum += (INT32U)(*pData++);
        uiSum += (INT32U)(*pData++);
        uiSum += (INT32U)(*pData++);
        uiSum += (INT32U)(*pData++);
        uiSum += (INT32U)(*pData++);
        uiSum += (INT32U)(*pData++);
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   uiSum += (INT32U)(*pData++);
    }
    return (INT16U)(uiSum / usSize);
}

/* ******************************************************************** */
/*                         SFGetMax16s()                                */
/* ******************************************************************** */
INT16S SFGetMax16s (INT16S *pData, INT16U usSize)
{   INT16S ssMax, ssTmp;
    INT16U usSiz;
    ssMax = INT16_MIN;
    usSiz = usSize / 4;
    while (usSiz--)
    {   ssTmp = *pData++;
        if (ssMax < ssTmp)
        {   ssMax = ssTmp;
        }
        ssTmp = *pData++;
        if (ssMax < ssTmp)
        {   ssMax = ssTmp;
        }
        ssTmp = *pData++;
        if (ssMax < ssTmp)
        {   ssMax = ssTmp;
        }
        ssTmp = *pData++;
        if (ssMax < ssTmp)
        {   ssMax = ssTmp;
        }
    }
    usSiz = usSize % 4;
    while (usSiz--)
    {   ssTmp = *pData++;
        if (ssMax < ssTmp)
        {   ssMax = ssTmp;
        }
    }
    return ssMax;
}

/* ******************************************************************** */
/*                         SFGetMax16u()                                */
/* ******************************************************************** */
INT16U SFGetMax16u (INT16U *pData, INT16U usSize)
{   INT16U usMax, usTmp;
    INT16U usSiz;
    usMax = 0;
    usSiz = usSize / 4;
    while (usSiz--)
    {   usTmp = *pData++;
        if (usMax < usTmp)
        {   usMax = usTmp;
        }
        usTmp = *pData++;
        if (usMax < usTmp)
        {   usMax = usTmp;
        }
        usTmp = *pData++;
        if (usMax < usTmp)
        {   usMax = usTmp;
        }
        usTmp = *pData++;
        if (usMax < usTmp)
        {   usMax = usTmp;
        }
    }
    usSiz = usSize % 4;
    while (usSiz--)
    {   usTmp = *pData++;
        if (usMax < usTmp)
        {   usMax = usTmp;
        }
    }
    return usMax;
}

/* ******************************************************************** */
/*                         SFGetMax32f()                                */
/* ******************************************************************** */
FP32 SFGetMax32f (FP32 *pData, INT16U usSize)
{   FP32   fpMax, fpTmp;
    INT16U usSiz;
    fpMax = *pData;
    usSiz = usSize / 4;
    while (usSiz--)
    {   fpTmp = *pData++;
        if (fpMax < fpTmp)
        {   fpMax = fpTmp;
        }
        fpTmp = *pData++;
        if (fpMax < fpTmp)
        {   fpMax = fpTmp;
        }
        fpTmp = *pData++;
        if (fpMax < fpTmp)
        {   fpMax = fpTmp;
        }
        fpTmp = *pData++;
        if (fpMax < fpTmp)
        {   fpMax = fpTmp;
        }
    }
    usSiz = usSize % 4;
    while (usSiz--)
    {   fpTmp = *pData++;
        if (fpMax < fpTmp)
        {   fpMax = fpTmp;
        }
    }
    return fpMax;
}

/* ******************************************************************** */
/*                            SFCheckMinMax16u()                        */
/* ******************************************************************** */
INT08U SFCheckMinMax16u (INT16U *pData, INT16U usSize)
{   INT16U usMax, usMin, usTmp, usSiz;
    usSize -= 1;
    usMax   = *pData++;
    usMin   = usMax;
    usSiz   = usSize / 4;
    while (usSiz--)
    {   usTmp = *pData++;
        if (usMax < usTmp)
        {   usMax = usTmp;
        }   else if (usMin > usTmp)
        {   usMin = usTmp;
        }
        usTmp = *pData++;
        if (usMax < usTmp)
        {   usMax = usTmp;
        }   else if (usMin > usTmp)
        {   usMin = usTmp;
        }
        usTmp = *pData++;
        if (usMax < usTmp)
        {   usMax = usTmp;
        }   else if (usMin > usTmp)
        {   usMin = usTmp;
        }
        usTmp = *pData++;
        if (usMax < usTmp)
        {   usMax = usTmp;
        }   else if (usMin > usTmp)
        {   usMin = usTmp;
        }
    }
    usSiz = usSize % 4;
    while (usSiz--)
    {   usTmp = *pData++;
        if (usMax < usTmp)
        {   usMax = usTmp;
        }   else if (usMin > usTmp)
        {   usMin = usTmp;
        }
    }    
    if (usMin < (usMax/2))
    {   return SF_FALSE;
    }
    return SF_TRUE;
}

/* ******************************************************************** */
/*                            SFCheckMinMax16u()                        */
/* ******************************************************************** */
INT08U SFCheckMinMax32u (INT32U *pData, INT16U usSize)
{   INT32U uiMax, uiMin, uiTmp;
    INT16U usSiz;
    usSize -= 1;
    uiMax   = *pData++;
    uiMin   = uiMax;
    usSiz   = usSize / 4;
    while (usSiz--)
    {   uiTmp = *pData++;
        if (uiMax < uiTmp)
        {   uiMax = uiTmp;
        }   else if (uiMin > uiTmp)
        {   uiMin = uiTmp;
        }
        uiTmp = *pData++;
        if (uiMax < uiTmp)
        {   uiMax = uiTmp;
        }   else if (uiMin > uiTmp)
        {   uiMin = uiTmp;
        }
        uiTmp = *pData++;
        if (uiMax < uiTmp)
        {   uiMax = uiTmp;
        }   else if (uiMin > uiTmp)
        {   uiMin = uiTmp;
        }
        uiTmp = *pData++;
        if (uiMax < uiTmp)
        {   uiMax = uiTmp;
        }   else if (uiMin > uiTmp)
        {   uiMin = uiTmp;
        }
    }
    usSiz   = usSize % 4;
    while (usSiz--)
    {   uiTmp = *pData++;
        if (uiMax < uiTmp)
        {   uiMax = uiTmp;
        }   else if (uiMin > uiTmp)
        {   uiMin = uiTmp;
        }
    }
    if (uiMin < (uiMax/2))
    {   return SF_FALSE;
    }
    return SF_TRUE;
}

/* ******************************************************************** */
/*                           SFGetAdcRef16u()                           */
/* ******************************************************************** */
INT16U SFGetAdcRef16u (INT16U usInput, INT32U *pRSum)
{   INT32U uiSum, uiOut;
    uiSum  = *pRSum;
    uiOut  = uiSum / XIO_ADC_REF_FILTER;  //uiOut = （固定基准值*滤波点数）/滤波点数
    uiSum += (INT32U)usInput;
    uiSum -= uiOut;
    *pRSum = uiSum;
    return (INT16U)uiOut;
}

/* ******************************************************************** */
/*                           SFSubRef16s()                              */
/* ******************************************************************** */
void SFSubRef16s (INT16S *pData, INT16S ssRef, INT16U usSize)
{   INT16U usSiz;
    INT16S ssReffer;
    ssReffer = ssRef;
    usSiz = usSize / 8;
    while (usSiz--)
    {   *pData -= ssReffer;
        pData++;
        *pData -= ssReffer;
        pData++;
        *pData -= ssReffer;
        pData++;
        *pData -= ssReffer;
        pData++;
        *pData -= ssReffer;
        pData++;
        *pData -= ssReffer;
        pData++;
        *pData -= ssReffer;
        pData++;
        *pData -= ssReffer;
        pData++;
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   *pData -= ssReffer;
        pData++;
    }
}

/* ******************************************************************** */
/*                            SFGetEffAve()                             */
/* ******************************************************************** */
INT16U SFGetEffAve (INT16S *pData, INT16U usSize)
{   INT32U uiSum;
    INT32S siTmp;
    INT16U usSiz;
    uiSum = 0;
    usSiz = usSize / 8;
    while (usSiz--)
    {   siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
    }
    uiSum /= usSize;
    return SFSqrt32u(uiSum);
}

/* ******************************************************************** */
/*                            SFGetEffSum()                          */
/* ******************************************************************** */
INT16U SFGetEffSum (INT16S *pData, INT16U usSize)
{   INT32U uiSum;
    INT32S siTmp;
    INT16U usSiz;
    uiSum = 0;
    usSiz = usSize / 8;
    while (usSiz--)
    {   siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   siTmp  = (INT32S)(*pData++);
        uiSum += (INT32U)(siTmp * siTmp);
    }
    return SFSqrt32u(uiSum);
}

/* ******************************************************************** */
/*                            SFSubEffAve()                             */
/* ******************************************************************** */
INT16U SFSubEffAve (INT16S *pDat0, INT16S *pDat1, INT16U usSize)
{   INT32U uiSum;
    INT32S siTmp;
    INT16U usSiz;
    uiSum = 0;
    usSiz = usSize / 4;
    while (usSiz--)
    {   siTmp  = (INT32S)(*pDat0++);
        siTmp -= (INT32S)(*pDat1++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pDat0++);
        siTmp -= (INT32S)(*pDat1++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pDat0++);
        siTmp -= (INT32S)(*pDat1++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pDat0++);
        siTmp -= (INT32S)(*pDat1++);
        uiSum += (INT32U)(siTmp * siTmp);
    }
    usSiz = usSize % 4;
    while (usSiz--)
    {   siTmp  = (INT32S)(*pDat0++);
        siTmp -= (INT32S)(*pDat1++);
        uiSum += (INT32U)(siTmp * siTmp);
    }
    uiSum /= usSize;
    return SFSqrt32u(uiSum);
}

/* ******************************************************************** */
/*                            SFSubEffSum()                             */
/* ******************************************************************** */
INT16U SFSubEffSum (INT16S *pDat0, INT16S *pDat1, INT16U usSize)
{   INT32U uiSum;
    INT32S siTmp;
    INT16U usSiz;
    uiSum = 0;
    usSiz = usSize / 4;
    while (usSiz--)
    {   siTmp  = (INT32S)(*pDat0++);
        siTmp -= (INT32S)(*pDat1++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pDat0++);
        siTmp -= (INT32S)(*pDat1++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pDat0++);
        siTmp -= (INT32S)(*pDat1++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pDat0++);
        siTmp -= (INT32S)(*pDat1++);
        uiSum += (INT32U)(siTmp * siTmp);
    }
    usSiz = usSize % 4;
    while (usSiz--)
    {   siTmp  = (INT32S)(*pDat0++);
        siTmp -= (INT32S)(*pDat1++);
        uiSum += (INT32U)(siTmp * siTmp);
    }
    return SFSqrt32u(uiSum);
}

/* ******************************************************************** */
/*                            SFTriEffAve()                             */
/* ******************************************************************** */
INT16U SFTriEffAve (INT16S *pDat0, INT16S *pDat1, INT16S *pDat2, INT16U usSize)
{   INT32U uiSum;
    INT32S siTmp;
    INT16U usSiz;
    uiSum = 0;
    usSiz = usSize / 4;
    while (usSiz--)
    {   siTmp  = (INT32S)(*pDat0++);
        siTmp += (INT32S)(*pDat1++);
        siTmp += (INT32S)(*pDat2++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pDat0++);
        siTmp += (INT32S)(*pDat1++);
        siTmp += (INT32S)(*pDat2++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pDat0++);
        siTmp += (INT32S)(*pDat1++);
        siTmp += (INT32S)(*pDat2++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pDat0++);
        siTmp += (INT32S)(*pDat1++);
        siTmp += (INT32S)(*pDat2++);
        uiSum += (INT32U)(siTmp * siTmp);
    }
    usSiz = usSize % 4;
    while (usSiz--)
    {   siTmp  = (INT32S)(*pDat0++);
        siTmp += (INT32S)(*pDat1++);
        siTmp += (INT32S)(*pDat2++);
        uiSum += (INT32U)(siTmp * siTmp);
    }
    uiSum /= usSize;
    return SFSqrt32u(uiSum);
}

/* ******************************************************************** */
/*                            SFTriEffSum()                             */
/* ******************************************************************** */
INT16U SFTriEffSum (INT16S *pDat0, INT16S *pDat1, INT16S *pDat2, INT16U usSize)
{   INT32U uiSum;
    INT32S siTmp;
    INT16U usSiz;
    uiSum = 0;
    usSiz = usSize / 4;
    while (usSiz--)
    {   siTmp  = (INT32S)(*pDat0++);
        siTmp += (INT32S)(*pDat1++);
        siTmp += (INT32S)(*pDat2++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pDat0++);
        siTmp += (INT32S)(*pDat1++);
        siTmp += (INT32S)(*pDat2++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pDat0++);
        siTmp += (INT32S)(*pDat1++);
        siTmp += (INT32S)(*pDat2++);
        uiSum += (INT32U)(siTmp * siTmp);
        siTmp  = (INT32S)(*pDat0++);
        siTmp += (INT32S)(*pDat1++);
        siTmp += (INT32S)(*pDat2++);
        uiSum += (INT32U)(siTmp * siTmp);
    }
    usSiz = usSize % 4;
    while (usSiz--)
    {   siTmp  = (INT32S)(*pDat0++);
        siTmp += (INT32S)(*pDat1++);
        siTmp += (INT32S)(*pDat2++);
        uiSum += (INT32U)(siTmp * siTmp);
    }
    return SFSqrt32u(uiSum);
}

/* ******************************************************************** */
/*                            SFGetMacAve()                             */
/* ******************************************************************** */
INT32S SFGetMacAve (INT16S *pSorA, INT16S *pSorB, INT16U usSize)
{   INT32S siSum;
    INT16U usSiz;
    siSum = 0;
    usSiz = usSize / 8;
    while (usSiz--)
    {   siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
        siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
        siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
        siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
        siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
        siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
        siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
        siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
    }
    return (siSum / usSize);
}

/* ******************************************************************** */
/*                            SFGetMacSum()                             */
/* ******************************************************************** */
INT32S SFGetMacSum (INT16S *pSorA, INT16S *pSorB, INT16U usSize)
{   INT32S siSum;
    INT16U usSiz;
    siSum = 0;
    usSiz = usSize / 8;
    while (usSiz--)
    {   siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
        siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
        siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
        siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
        siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
        siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
        siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
        siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   siSum += (INT32S)(*pSorA++) * (INT32S)(*pSorB++);
    }
    return siSum;
}

/* ******************************************************************** */
/*                          SFGetPowerSpectrum()                        */
/* ******************************************************************** */
void SFGetPowerSpectrum (FP32 *pSour, FP32 *pDest, INT16U usSize)
{   FP32 fpReal, fpImag;
    INT16U usSiz;
    usSiz = usSize / 4;
    while (usSiz--)
    {   fpReal   = *pSour++;
        fpImag   = *pSour++;
        *pDest++ = fpReal * fpReal + fpImag * fpImag;
        fpReal   = *pSour++;
        fpImag   = *pSour++;
        *pDest++ = fpReal * fpReal + fpImag * fpImag;
        fpReal   = *pSour++;
        fpImag   = *pSour++;
        *pDest++ = fpReal * fpReal + fpImag * fpImag;
        fpReal   = *pSour++;
        fpImag   = *pSour++;
        *pDest++ = fpReal * fpReal + fpImag * fpImag;
    }
    usSiz = usSize % 4;
    while (usSiz--)
    {   fpReal   = *pSour++;
        fpImag   = *pSour++;
        *pDest++ = fpReal * fpReal + fpImag * fpImag;
    }
}

/* ******************************************************************** */
/*                            SFGetSqrt32f()                            */
/* ******************************************************************** */
void SFGetSqrt32f (FP32 *pSour, FP32 *pDest, INT16U usSize)
{   INT16U usSiz;
    usSiz = usSize / 4;
    while (usSiz--)
    {   arm_sqrt_f32(*pSour++, pDest++);
        arm_sqrt_f32(*pSour++, pDest++);
        arm_sqrt_f32(*pSour++, pDest++);
        arm_sqrt_f32(*pSour++, pDest++);
    }
    usSiz = usSize % 4;
    while (usSiz--)
    {   arm_sqrt_f32(*pSour++, pDest++);
    }
}

/* ******************************************************************** */
/*                          SFGetPhaseDelay()                           */
/* ******************************************************************** */
INT16S SFGetPhaseDelay (INT16S *pArray0, INT16S *pArray1, INT16U usSize)
{   INT32S siMac0, siMac120, siMac240;
    siMac0   = SFGetMacSum(pArray0, &pArray1[0], usSize);
    siMac120 = SFGetMacSum(pArray0, &pArray1[usSize/3], usSize);
    siMac240 = SFGetMacSum(pArray0, &pArray1[usSize*2/3], usSize);
    if (siMac120 > siMac240)
    {   if (siMac0 > siMac120)
        {   return 0;
        }   else
        {   return 120;
        }
    }
    if (siMac0 > siMac240)
    {   return 0;
    }
    return 240;
}

/* ******************************************************************** */
/*                             SFGetFir16s()                            */
/* ******************************************************************** */
void SFGetFir16s (INT16S *pSour, INT16S *pDest, SF_FIR_FILTER_STR *pFilt, INT16U usSize)
{   INT16S *pFiltr, *pSourc;
    INT32S siSum;
    INT16U usSiz;
    usSize -= pFilt->usFSize;
    while (usSize--)
    {   siSum  = 0;
        pSourc = pSour;
        pFiltr = pFilt->pFilter;
        usSiz  = pFilt->usFSize / 4;
        while (usSiz--)
        {   siSum += (INT32S)(*pSourc++) * (INT32S)(*pFiltr++);
            siSum += (INT32S)(*pSourc++) * (INT32S)(*pFiltr++);
            siSum += (INT32S)(*pSourc++) * (INT32S)(*pFiltr++);
            siSum += (INT32S)(*pSourc++) * (INT32S)(*pFiltr++);
        }
        usSiz  = pFilt->usFSize % 4;
        while (usSiz--)
        {   siSum += (INT32S)(*pSourc++) * (INT32S)(*pFiltr++);
        }
        *pDest++ = (INT16S)(siSum >> 15);
        pSour++;
    }
}

/* ******************************************************************** */
/*                           SFIirFilterInit()                          */
/* ******************************************************************** */
void SFIirFilterInit (SF_IIR_FILTER_STR *pFilt, INT16U usFilter)
{   pFilt->usFilter = usFilter > 0 ? usFilter : 8;
    pFilt->siSum    = 0;
    pFilt->ssOut    = 0;
}

/* ******************************************************************** */
/*                             SFGetIir16s()                            */
/* ******************************************************************** */
void SFGetIir16s (INT16S *pSour, INT16S *pDest, SF_IIR_FILTER_STR *pFilt, INT16U usSize)
{   INT32S siIirSum, siIirOut, siIirFlt;
    INT16U usSiz;
    siIirSum =  pFilt->siSum;
    siIirOut = (INT32S)(pFilt->ssOut);
    siIirFlt = (INT32S)(pFilt->usFilter);
    usSiz    =  usSize / 4;
    while (usSiz--)
    {   siIirSum += (INT32S)(*pSour++);
        siIirSum -=  siIirOut;
        siIirOut  =  siIirSum / siIirFlt;
        *pDest++  = (INT16S)siIirOut;
        siIirSum += (INT32S)(*pSour++);
        siIirSum -=  siIirOut;
        siIirOut  =  siIirSum / siIirFlt;
        *pDest++  = (INT16S)siIirOut;
        siIirSum += (INT32S)(*pSour++);
        siIirSum -=  siIirOut;
        siIirOut  =  siIirSum / siIirFlt;
        *pDest++  = (INT16S)siIirOut;
        siIirSum += (INT32S)(*pSour++);
        siIirSum -=  siIirOut;
        siIirOut  =  siIirSum / siIirFlt;
        *pDest++  = (INT16S)siIirOut;
    }
    usSiz = usSize % 4;
    while (usSiz--)
    {   siIirSum += (INT32S)(*pSour++);
        siIirSum -=  siIirOut;
        siIirOut  =  siIirSum / siIirFlt;
        *pDest++  = (INT16S)siIirOut;
    }
    pFilt->siSum  =  siIirSum;
    pFilt->ssOut  = (INT16S)siIirOut;
}

/* ******************************************************************** */
/*                            SFZeroCrossInit()                         */
/* ******************************************************************** */
void SFZeroCrossInit (SF_ZERO_CROSS_STR *pZero)
{   pZero->usFreq  = 0;
    pZero->usPhase = 0;
    pZero->siDold  = 0;
    pZero->uiPrd   = 0xFFFFFFFF;
    pZero->uiTold  = 0;
    pZero->uiTnew  = 0;
    pZero->uiTlong = XIO_ADC_SMPL_PRD_US;
}

/* ******************************************************************** */
/*                            SFFindZeroCross()                         */
/* ******************************************************************** */
void SFFindZeroCross (INT16S *pData, SF_ZERO_CROSS_STR *pZero, INT16U usSize)
{   INT32U uiTim, uiNum, uiSiz;
    INT32S siOld, siNew;
    uiTim = 0;
    uiNum = 0;
    siOld = 0;
    siNew = pZero->siDold;
    uiSiz = usSize / 4;
    while (uiSiz--)
    {   siOld  = siNew;
        siNew  = (INT32S)(*pData++);
        uiTim += XIO_ADC_SMPL_TIM_US;
        if((siOld < 0) && (siNew >= 0))
        {   pZero->uiTold = pZero->uiTnew;
            pZero->uiTnew = SF_GET_CROSS_TIM(siOld,siNew) + uiTim;
            uiNum++;
        }
        siOld  = siNew;
        siNew  = (INT32S)(*pData++);
        uiTim += XIO_ADC_SMPL_TIM_US;
        if((siOld < 0) && (siNew >= 0))
        {   pZero->uiTold = pZero->uiTnew;
            pZero->uiTnew = SF_GET_CROSS_TIM(siOld,siNew) + uiTim;
            uiNum++;
        }
        siOld  = siNew;
        siNew  = (INT32S)(*pData++);
        uiTim += XIO_ADC_SMPL_TIM_US;
        if((siOld < 0) && (siNew >= 0))
        {   pZero->uiTold = pZero->uiTnew;
            pZero->uiTnew = SF_GET_CROSS_TIM(siOld,siNew) + uiTim;
            uiNum++;
        }
        siOld  = siNew;
        siNew  = (INT32S)(*pData++);
        uiTim += XIO_ADC_SMPL_TIM_US;
        if((siOld < 0) && (siNew >= 0))
        {   pZero->uiTold = pZero->uiTnew;
            pZero->uiTnew = SF_GET_CROSS_TIM(siOld,siNew) + uiTim;
            uiNum++;
        }
    }
    uiSiz = usSize % 4;
    while (uiSiz--)
    {   siOld  = siNew;
        siNew  = (INT32S)(*pData++);
        uiTim += XIO_ADC_SMPL_TIM_US;
        if((siOld < 0) && (siNew >= 0))
        {   pZero->uiTold = pZero->uiTnew;
            pZero->uiTnew = SF_GET_CROSS_TIM(siOld,siNew) + uiTim;
            uiNum++;
        }
    }
    pZero->siDold = siNew;
    if (uiNum == 0)
    {   pZero->uiTlong += XIO_ADC_SMPL_PRD_US;
    }   else if (uiNum == 1)
    {   pZero->uiPrd    = pZero->uiTnew + pZero->uiTlong - pZero->uiTold;
        pZero->uiTlong  = XIO_ADC_SMPL_PRD_US;
    }   else
    {   pZero->uiPrd    = pZero->uiTnew - pZero->uiTold;
        pZero->uiTlong  = XIO_ADC_SMPL_PRD_US;
    }
    uiTim = pZero->uiPrd;
    if ((uiTim != 0) && (uiNum != 0))
    {   pZero->usFreq  = (INT16U)((INT32U)100000000 / uiTim);
        pZero->usPhase = (INT16U)(((pZero->uiTnew % uiTim) << 16) / uiTim);
    }
}

/* ******************************************************************** */
/*                          SFGet1DMap8()                               */
/* ******************************************************************** */
INT16U SFGet1DMap8 (INT16U usX, INT16U *pXX, INT16U *pYY)
{   INT16U usD1, usD2, usD3, usD4;
    if (usX <= pXX[0])
    {   return pYY[0];
    }
    for (usD4=1; usD4<8; usD4++)
    {   usD2 = pXX[usD4];
        if (usD2 == 0)
        {   return pYY[usD4-1];
        }
        else if (usX <= usD2)
        {   usD1 = pXX[usD4-1];
            usD3 = pYY[usD4-1];
            usD4 = pYY[usD4];
            return SF_INTERP(usD1,usD2,usD3,usD4,usX);
        }
    }
    return pYY[7];
}

/* ******************************************************************** */
/*                            SFGet1DMap10()                            */
/* ******************************************************************** */
INT16U SFGet1DMap10 (INT16U usX, INT16U *pXX, INT16U *pYY)
{   INT16U usD1, usD2, usD3, usD4;
    if (usX <= pXX[0])
    {   return pYY[0];
    }
    for (usD4=1; usD4<10; usD4++)
    {   usD2 = pXX[usD4];
        if (usD2 == 0)
        {   return pYY[usD4-1];
        }
        else if (usX <= usD2)
        {   usD1 = pXX[usD4-1];
            usD3 = pYY[usD4-1];
            usD4 = pYY[usD4];
            return SF_INTERP(usD1,usD2,usD3,usD4,usX);
        }
    }
    return pYY[9];
}

/* ******************************************************************** */
/*                            SFGet1DMap20()                            */
/* ******************************************************************** */
INT16U SFGet1DMap20 (INT16U usX, INT16U *pXX, INT16U *pYY)
{   INT16U usD1, usD2, usD3, usD4;
    if (usX <= pXX[0])
    {   return pYY[0];
    }
    for (usD4=1; usD4<20; usD4++)
    {   usD2 = pXX[usD4];
        if (usD2 == 0)
        {   return pYY[usD4-1];
        }
        else if (usX <= usD2)
        {   usD1 = pXX[usD4-1];
            usD3 = pYY[usD4-1];
            usD4 = pYY[usD4];
            return SF_INTERP(usD1,usD2,usD3,usD4,usX);
        }
    }
    return pYY[19];
}

/* ******************************************************************** */
/*                          SFGet1DMapCst10()                           */
/* ******************************************************************** *///AD采样值-采样基准值-显示值
int TESTZC11[5];
INT16U SFGet1DMapCst10 (INT16U usX, const INT16U *pXX, const INT16U *pYY)
{   INT16U usD1, usD2, usD3, usD4;
    if (usX <= pXX[0])                                        //?????标准曲线表X轴按从小到大顺序
    {TESTZC11[0] = pYY[0];
      return pYY[0];
    }
    for (usD4=1; usD4<10; usD4++)
    {   usD2 = pXX[usD4];
        if (usD2 == 0)
        {TESTZC11[1] = pYY[usD4-1];
          return pYY[usD4-1];
        }
        else if (usX <= usD2)
        {   usD1 = pXX[usD4-1];
            usD3 = pYY[usD4-1];
            usD4 = pYY[usD4];
            TESTZC11[2] = SF_INTERP(usD1,usD2,usD3,usD4,usX);
            return SF_INTERP(usD1,usD2,usD3,usD4,usX);
        }
    }
    TESTZC11[3] = pYY[9];
    return pYY[9];
}

/* ******************************************************************** */
/*                            SFHardPrdInit()                           */
/* ******************************************************************** */
void SFHardPrdInit (SF_HARD_PRD_STR *pHard)
{   INT16U i;
    pHard->usTime  = 0;
    pHard->usTick  = usSFTimer;
    pHard->usFreq  = 0;
    pHard->usCount = SF_HARD_PRD_DAT_SIZ;
    pHard->pPeriod = &pHard->uiPeriod[SF_HARD_PRD_DAT_SIZ-1];
    for (i=0; i<SF_HARD_PRD_DAT_SIZ; i++)
    {   pHard->uiPeriod[i] = 0xFFFFFFFF;
    }
}

/* ******************************************************************** */
/*                          SFHardPrdRefrash()                          */
/* ******************************************************************** */
void SFHardPrdRefrash (SF_HARD_PRD_STR *pHard)
{   INT16U usTemp;
    usTemp = usSFTimer - pHard->usTick;
    if (usTemp > SF_HARD_PRD_RST_TICK)
    {   pHard->usCount = SF_HARD_PRD_DAT_SIZ;
    }
}

/* ******************************************************************** */
/*                         SFHardPrdPutTime()                           */
/* ******************************************************************** */
void SFHardPrdPutTime (INT16U usTime, SF_HARD_PRD_STR *pHard)
{   INT16U usTemp, usTicks;
    INT32U uiPeriod;
    usTemp        = usTime - pHard->usTime;
    pHard->usTime = usTime;
    usTicks       = usSFTimer - pHard->usTick;
    pHard->usTick = usSFTimer;
    if (usTicks  >= 10)
    {   uiPeriod  = (INT32U)usTicks;
        uiPeriod *= (INT32U)1000000 / OS_TICKS_PER_SEC;
        uiPeriod += (INT32U)0x8000;
        uiPeriod -= (INT32U)usTemp;
        uiPeriod &= (INT32U)0xFFFF0000;
        uiPeriod += (INT32U)usTemp;
    }   else
    {   uiPeriod  = (INT32U)usTemp;
    }
    pHard->pPeriod++;
    if (pHard->pPeriod >= &pHard->uiPeriod[SF_HARD_PRD_DAT_SIZ])
    {   pHard->pPeriod  = &pHard->uiPeriod[0];
    }
    *pHard->pPeriod = uiPeriod;
    if (uiPeriod == 0)
    {   pHard->usFreq = 0;
    }   else
    {   pHard->usFreq = (INT16U)((INT32U)100000000 / uiPeriod);
    }
    if (pHard->usCount != 0)
    {   pHard->usCount--;
    }
}

/* ******************************************************************** */
/*                          SFHardPrdGetFreq()                          */
/* ******************************************************************** */
INT16U SFHardPrdGetFreq (SF_HARD_PRD_STR *pHard)
{   return pHard->usFreq;
}

/* ******************************************************************** */
/*                          SFHardPrdGetFreq()                          */
/* ******************************************************************** */
INT32U SFHardPrdGetPeriod (SF_HARD_PRD_STR *pHard)
{   return *(pHard->pPeriod);
}

/* ******************************************************************** */
/*                        SFHardPrdCheckPeriod()                        */
/* ******************************************************************** */
INT08U SFHardPrdCheckPeriod (SF_HARD_PRD_STR *pHard)
{   if (pHard->usCount != 0)
    {   return SF_FALSE;
    }
    return SFCheckMinMax32u(&pHard->uiPeriod[0], SF_HARD_PRD_DAT_SIZ);
}

/* ******************************************************************** */
/*                         SFHardPrdGetPhsDiff()                        */
/* ******************************************************************** */
INT16S SFHardPrdGetPhsDiff (SF_HARD_PRD_STR *pHard0, SF_HARD_PRD_STR *pHard1)
{   INT16S ssTemp;
    INT32U uiPrd;
    uiPrd  = (*(pHard0->pPeriod) + *(pHard1->pPeriod)) / 2;
    ssTemp = pHard1->usTime - pHard0->usTime;
    if (uiPrd == 0)
    {   return 0;
    }
    return (INT16S)(((INT32S)ssTemp << 16) / uiPrd);
}

/* ******************************************************************** */
/*                           SFSpdPulseInit()                           */
/* ******************************************************************** */
void SFSpdPulseInit (SF_SPD_PULSE_STR *pSpd, INT16U usTeeth, INT16U usFilter)
{   pSpd->usTime = 0;
    pSpd->usTick = 0;
    pSpd->usSpeed = 0;
    pSpd->usCount = usFilter;
    pSpd->usCntMax = usFilter;
    pSpd->uiPeriod = 0xFFFFFFFF;
    pSpd->uiSpdCst = (INT32U)(((INT64U)usFilter * (INT64U)60000000) / (INT64U)usTeeth);
}

/* ******************************************************************** */
/*                          SFSpdPulseRefrash()                         */
/* ******************************************************************** */
void SFSpdPulseRefrash (SF_SPD_PULSE_STR *pSpd)
{   INT16U usTemp;
    usTemp = usSFTimer - pSpd->usTick;
    if (usTemp > SF_SPD_PULSE_RST_TICK)
    {   pSpd->usCount = pSpd->usCntMax;
        pSpd->usSpeed = 0;
    }
}

/* ******************************************************************** */
/*                         SFSpdPulseGetSpeed()                         */
/* ******************************************************************** */
INT16U SFSpdPulseGetSpeed (SF_SPD_PULSE_STR *pSpd)
{   return pSpd->usSpeed;
}

/* ******************************************************************** */
/*                         SFSpdPulsePutTime()                          */
/* ******************************************************************** */
void SFSpdPulsePutTime (INT16U usTime, SF_SPD_PULSE_STR *pSpd)
{   INT16U usTemp, usTicks;
    INT32U uiPeriod;
    usTemp        = (INT16U)(usTime - pSpd->usTime);
    pSpd->usTime  = usTime;
    usTicks       = (INT16U)(usSFTimer - pSpd->usTick);
    pSpd->usTick  = usSFTimer;
    if (usTicks  >= 10)
    {   uiPeriod  = (INT32U)usTicks;
        uiPeriod *= (INT32U)1000000 / OS_TICKS_PER_SEC;
        uiPeriod += (INT32U)0x8000;
        uiPeriod -= (INT32U)usTemp;
        uiPeriod &= (INT32U)0xFFFF0000;
        uiPeriod += (INT32U)usTemp;
        pSpd->uiPeriod += uiPeriod;
    }   else
    {   pSpd->uiPeriod += (INT32U)usTemp;
    }
    if ((--pSpd->usCount) == 0)
    {   pSpd->usCount  = pSpd->usCntMax;
        uiPeriod       = pSpd->uiPeriod;
        pSpd->uiPeriod = 0;
        if (uiPeriod  == 0)
        {   pSpd->usSpeed = 0;
        }   else
        {   pSpd->usSpeed = (INT16U)(pSpd->uiSpdCst / uiPeriod);
        }
    }
}

/* ******************************************************************** */
/*                           SFGetPidCtrl16u()                          */
/* ******************************************************************** */
INT16U SFGetPidCtrl16u (INT16U usInput, INT16U usSetp, PID16U_PAR_STR *pPara)
{   INT32U uiCtrl, uiTemp;
    INT16U usErr;
    uiCtrl = pPara->uiCtrlOld;
    usErr  = usSetp > usInput ? usSetp - usInput : usInput - usSetp;
    if (pPara->usStability != 0)
    {   uiTemp = (INT32U)usErr * 1024 / (INT32U)(pPara->usStability);
        if (usSetp  > usInput)
        {   uiCtrl += uiTemp;
        }   else if (uiCtrl > uiTemp)
        {   uiCtrl -= uiTemp;
        }   else
        {   uiCtrl  = 0;
        }
        if (uiCtrl  < pPara->uiCtrlMin)
        {   uiCtrl  = pPara->uiCtrlMin;
        }   else if (uiCtrl > pPara->uiCtrlMax)
        {   uiCtrl  = pPara->uiCtrlMax;
        }
    }
    pPara->uiCtrlOld = uiCtrl;
    if (pPara->usGain != 0)
    {   uiTemp = (INT32U)usErr * (INT32U)(pPara->usGain);
        if (usSetp  > usInput)
        {   uiCtrl += uiTemp;
        }   else if (uiCtrl > uiTemp)
        {   uiCtrl -= uiTemp;
        }   else
        {   uiCtrl  = 0;
        }
    }
    if (pPara->usInputOld > usInput)
    {   usErr = pPara->usInputOld - usInput;
    }   else
    {   usErr = usInput - pPara->usInputOld;
    }
    if (pPara->usDerivative != 0)
    {   uiTemp = (INT32U)usErr * (INT32U)(pPara->usDerivative) / 256;
        if (pPara->usInputOld > usInput)
        {   uiCtrl += uiTemp;
        }   else if (uiCtrl > uiTemp)
        {   uiCtrl -= uiTemp;
        }   else
        {   uiCtrl  = 0;
        }
    }
    pPara->usInputOld = usInput;
    if (uiCtrl < pPara->uiCtrlMin)
    {   uiCtrl = pPara->uiCtrlMin;
    }   else if (uiCtrl > pPara->uiCtrlMax)
    {   uiCtrl = pPara->uiCtrlMax;
    }
    return (INT16U)(uiCtrl / 256);
}

/* ******************************************************************** */
/*                           SFGetPidCtrl16s()                          */
/* ******************************************************************** */
INT16S SFGetPidCtrl16s (INT16S ssInput, INT16S ssSetp, PID16S_PAR_STR *pPara)
{   INT32S siCtrl;
    INT16S ssErr;
    siCtrl = pPara->siCtrlOld;
    ssErr  = ssSetp - ssInput;
    if (pPara->usStability != 0)
    {   siCtrl += ((INT32S)ssErr * 1024) / (INT32S)(pPara->usStability);
        if (siCtrl < pPara->siCtrlMin)
        {   siCtrl = pPara->siCtrlMin;
        }   else if (siCtrl > pPara->siCtrlMax)
        {   siCtrl = pPara->siCtrlMax;
        }
    }
    pPara->siCtrlOld = siCtrl;
    if (pPara->usGain != 0)
    {   siCtrl += (INT32S)ssErr * (INT32S)(pPara->usGain);
    }
    ssErr = pPara->ssInputOld - ssInput;
    pPara->ssInputOld = ssInput;
    if (pPara->usDerivative != 0)
    {   siCtrl += ((INT32S)ssErr * (INT32S)(pPara->usDerivative)) / 256;
    }
    if (siCtrl < pPara->siCtrlMin)
    {   siCtrl = pPara->siCtrlMin;
    }   else if (siCtrl > pPara->siCtrlMax)
    {   siCtrl = pPara->siCtrlMax;
    }
    return (INT16S)(siCtrl / 256);
}

/* ******************************************************************** */
/*                           SFSwitchDelay()                            */
/* ******************************************************************** */
INT16U SFSwitchDelay (INT16U usSwitch, SWITCH_DELAY_STR *pDelay)
{   INT16U usTemp;
    usTemp = usSFTimer - pDelay->usTimer;
    if (pDelay->usState == 0)
    {   if (usSwitch == 0)
        {   pDelay->usTimer = usSFTimer;
        }
        else if (usTemp >= pDelay->usDelayOn)
        {   pDelay->usTimer = usSFTimer;
            pDelay->usState = 1;
        }
    }
    else if (usSwitch != 0)
    {   pDelay->usTimer = usSFTimer;
    }
    else if (usTemp >= pDelay->usDelayOff)
    {   pDelay->usTimer = usSFTimer;
        pDelay->usState = 0;
    }
    return pDelay->usState;
}

/* ******************************************************************** */
/*                          SFGetCpuTemp()                              */
/* ******************************************************************** */
INT16U SFGetCpuTemp (INT16U usAdc)
{   INT32U uiTmp;
    if (usAdc >= SF_CPU_TMP_ADC25)
    {   uiTmp  = 25;
    }   else
    {   uiTmp  = SF_CPU_TMP_ADC25 - usAdc;
        uiTmp *= SF_CPU_TMP_SLOP_MUL;
        uiTmp /= SF_CPU_TMP_SLOP_DIV;
        uiTmp += 25;
    }
    return (INT16U)uiTmp;
}

/* ******************************************************************** */
/*                          SFGetSensorTemp()                           */
/* ******************************************************************** */
INT16U SFGetSensorTemp (INT16U usAdc, INT16U usType)
{   if (usType == 0)
    {   return SFGet1DMapCst10(usAdc, &aSFTempMap0Adc[0], &aSFTempMap0Tmp[0]);
    }   else if (usType == 1)
    {   return SFGet1DMapCst10(usAdc, &aSFTempMap1Adc[0], &aSFTempMap1Tmp[0]);
    }   else if (usType == 2)
    {   return SFGet1DMapCst10(usAdc, &aSFTempMap2Adc[0], &aSFTempMap2Tmp[0]);
    }   else if (usType == 3)
    {   return SFGet1DMapCst10(usAdc, &aSFTempMap3Adc[0], &aSFTempMap3Tmp[0]);
    }   else if (usType == 4)
    {   return SFGet1DMapCst10(usAdc, &aSFTempMap4Adc[0], &aSFTempMap4Tmp[0]);
    }   else if (usType == 5)
    {   return SFGet1DMapCst10(usAdc, &aSFTempMap5Adc[0], &aSFTempMap5Tmp[0]);
    }   else if (usType == 6)
    {   return SFGet1DMapCst10(usAdc, &aSFTempMap6Adc[0], &aSFTempMap6Tmp[0]);
    }   else if (usType == 7)
    {   return SFGet1DMapCst10(usAdc, &aSFTempMap7Adc[0], &aSFTempMap7Tmp[0]);
    }   else if (usType == 8)
    {   return SFGet1DMapCst10(usAdc, &aSFTempMap8Adc[0], &aSFTempMap8Tmp[0]);
    }   else if (usType == 9)
    {   return SFGet1DMapCst10(usAdc, &aSFTempMap9Adc[0], &aSFTempMap9Tmp[0]);
    }   else if (usType == 10)
    {   return SFGet1DMapCst10(usAdc, &aSFTempMap10Adc[0],&aSFTempMap10Tmp[0]);
    }   else if (usType == 11)
    {   return SFGet1DMapCst10(usAdc, &aSFTempMap11Adc[0],&aSFTempMap11Tmp[0]);
    }   else
    {   return SFGet1DMap10(usAdc, &aDBpTempMapAdc[0], &aDBpTempMapTmp[0]);
    }
}

/* ******************************************************************** */
/*                          SFGetSensorPress()                          */
/* ******************************************************************** */
int testzc12[2];
INT16U SFGetSensorPress (INT16U usAdc, INT16U usType)
{   if (usType == 0)
    { testzc12[0] = SFGet1DMapCst10(usAdc, &aSFPressMap0Adc[0], &aSFPressMap0Prs[0]);
      return SFGet1DMapCst10(usAdc, &aSFPressMap0Adc[0], &aSFPressMap0Prs[0]);
    }   else if (usType == 1)
    {   return SFGet1DMapCst10(usAdc, &aSFPressMap1Adc[0], &aSFPressMap1Prs[0]);
    }   else if (usType == 2)
    {   return SFGet1DMapCst10(usAdc, &aSFPressMap2Adc[0], &aSFPressMap2Prs[0]);
    }   else if (usType == 3)
    {   return SFGet1DMapCst10(usAdc, &aSFPressMap3Adc[0], &aSFPressMap3Prs[0]);
    }   else if (usType == 4)
    {   return SFGet1DMapCst10(usAdc, &aSFPressMap4Adc[0], &aSFPressMap4Prs[0]);
    }   else if (usType == 5)
    {   return SFGet1DMapCst10(usAdc, &aSFPressMap5Adc[0], &aSFPressMap5Prs[0]);
    }   else if (usType == 6)
    {   return SFGet1DMapCst10(usAdc, &aSFPressMap6Adc[0], &aSFPressMap6Prs[0]);
    }   else if (usType == 7)
    {   return SFGet1DMapCst10(usAdc, &aSFPressMap7Adc[0], &aSFPressMap7Prs[0]);
    }   else if (usType == 8)
    {   return SFGet1DMapCst10(usAdc, &aSFPressMap8Adc[0], &aSFPressMap8Prs[0]);
    }   else if (usType == 9)
    {   return SFGet1DMapCst10(usAdc, &aSFPressMap9Adc[0], &aSFPressMap9Prs[0]);
    }   else if (usType == 10)
    {   return SFGet1DMapCst10(usAdc, &aSFPressMap10Adc[0],&aSFPressMap10Prs[0]);
    }   else if (usType == 11)
    {   return SFGet1DMapCst10(usAdc, &aSFPressMap11Adc[0],&aSFPressMap11Prs[0]);
    }   else
    {   return SFGet1DMap10(usAdc, &aDBpPressMapAdc[0], &aDBpPressMapPrs[0]);
    }
}

/* ******************************************************************** */
/*                          SFGetSensorLevel()                          */
/* ******************************************************************** */
INT16U SFGetSensorLevel (INT16U usAdc, INT16U usType)
{   if (usType == 0)
    {   return SFGet1DMapCst10(usAdc, &aSFLevelMap0Adc[0], &aSFLevelMap0Lvl[0]);
    }   else if (usType == 1)
    {   return SFGet1DMapCst10(usAdc, &aSFLevelMap1Adc[0], &aSFLevelMap1Lvl[0]);
    }   else if (usType == 2)
    {   return SFGet1DMapCst10(usAdc, &aSFLevelMap2Adc[0], &aSFLevelMap2Lvl[0]);
    }   else if (usType == 3)
    {   return SFGet1DMapCst10(usAdc, &aSFLevelMap3Adc[0], &aSFLevelMap3Lvl[0]);
    }   else if (usType == 4)
    {   return SFGet1DMapCst10(usAdc, &aSFLevelMap4Adc[0], &aSFLevelMap4Lvl[0]);
    }   else if (usType == 5)
    {   return SFGet1DMapCst10(usAdc, &aSFLevelMap5Adc[0], &aSFLevelMap5Lvl[0]);
    }   else if (usType == 6)
    {   return SFGet1DMapCst10(usAdc, &aSFLevelMap6Adc[0], &aSFLevelMap6Lvl[0]);
    }   else if (usType == 7)
    {   return SFGet1DMapCst10(usAdc, &aSFLevelMap7Adc[0], &aSFLevelMap7Lvl[0]);
    }   else
    {   return SFGet1DMap10(usAdc, &aDBpLevelMapAdc[0], &aDBpLevelMapLvl[0]);
    }
}

/* ******************************************************************** */
/*                             SFGetAccKwh()                            */
/* ******************************************************************** */
INT32U SFGetAccKwh (INT32S siPower)
{   static INT32U uiSum = 0;
    INT32U uiAcc = 0;
    if (siPower > 0)
    {   uiSum += (INT32U)siPower;
        uiAcc  =  uiSum / SF_ACC_KWH_CONST;
        uiSum  =  uiSum % SF_ACC_KWH_CONST;
    }
    return uiAcc;
}

/* ******************************************************************** */
/*                            SFGetAccKvarh()                           */
/* ******************************************************************** */
INT32U SFGetAccKvarh (INT32S siPower)
{   static INT32U uiSum = 0;
    INT32U uiAcc = 0;
    if (siPower > 0)
    {   uiSum += (INT32U)siPower;
        uiAcc  =  uiSum / SF_ACC_KVARH_CONST;
        uiSum  =  uiSum % SF_ACC_KVARH_CONST;
    }
    return uiAcc;
}

/* ******************************************************************** */
/*                          SFGetAccRunTime()                           */
/* ******************************************************************** */
INT32U SFGetAccRunTime (INT16U usRunning)
{   static INT32U uiSum = 0;
    if (usRunning != 0)
    {   if ((++uiSum) >= SF_ACC_RUNTIM_CONST)
        {   uiSum -= SF_ACC_RUNTIM_CONST;
            return (INT32U)1;
        }
    }
    return (INT32U)0;
}

/* ******************************************************************** */
/*                          SFUpdataStatistics()                        */
/* ******************************************************************** */
INT08U SFUpdataStatistics (INT16U usSpeed, INT16U usPower)
{   static INT16U usTimer1 = 0;
    INT16U usD0, usD1;
    usD0 = usFW100msTimer - usTimer1;
    if (usDBmEngineRunning == 0)
    {   usTimer1 = usFW100msTimer;
        return SF_FALSE;
    }
    else if (usD0 >= usDBpStatisticsTime)
    {   usTimer1 = usFW100msTimer;
        for (usD0=0; usD0<9; usD0++)
        {   if (usSpeed <= aDBpStatisticSpeed[usD0]) break;
        }
        for (usD1=0; usD1<9; usD1++)
        {   if (usPower <= aDBpStatisticPower[usD1]) break;
        }
        aDBhStatisticData[usD0*10+usD1] += 1;
        return SF_TRUE;
    }
    return SF_FALSE;
}

/* ******************************************************************** */
/*                          SFCheckToSaveHstry()                        */
/* ******************************************************************** */
void SFCheckToSaveHstry (void)
{   static INT32U uiSum = 0;
    if ((++uiSum) >= SF_SAVE_HSTRY_TIME)
    {   uiSum = 0;
        DBTskPutCmd(DB_CMD_SAVE_HSTRY);
    }
}

/* ******************************************************************** */
/*                          SFUpdateAnalogStatus()                      */
/* ******************************************************************** */
int TESTZC1[10];
void SFUpdateAnalogStatus (INT16U *pAin)
{   INT16U usTmp;
    /* ************************* Power Supply ************************* */
    usDBmSupplyVoltage = pAin[SF_SUPPLY_VLT_CH] + SF_SUPPLY_VLT_CORR;
    /* *********************** CPU Temperature ************************ */
    usDBmInternTemperature = SFGetCpuTemp(pAin[SF_CPU_TMP_CH]);
    /* *********************** Oil Temperature ************************ */
    usTmp = usDBpAssignOilTemp;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {usTmp = pAin[usTmp];
        if ((usTmp < usDBpOilTempErrLow) || (usTmp > usDBpOilTempErrHigh))  //油温AD值超出范围，显示设置值
        {   SF_ERR1_SET_BIT(SF_ERR1_OIL_TMP_VT);
            usDBmOilTemperature = usDBpSubstOilTemp;                        //?????有反馈：传感器中短路与断路报警区分开
        }   else
        {   SF_ERR1_CLR_BIT(SF_ERR1_OIL_TMP_VT);
            usDBmOilTemperature = SFGetSensorTemp(usTmp, usDBpOilTempSenType);   //通过AD值获取具体物理现实值
        }
    }   else
    {   SF_ERR1_CLR_BIT(SF_ERR1_OIL_TMP_VT);
        usDBmOilTemperature = usDBpSubstOilTemp;
    }
    /* *********************** Fuel Temperature *********************** */
    usTmp = usDBpAssignFuelTemp;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpFuelTempErrLow) || (usTmp > usDBpFuelTempErrHigh))
        {   SF_ERR1_SET_BIT(SF_ERR1_FUEL_TMP_VT);
            usDBmFuelTemperature = usDBpSubstFuelTemp;
        }   else
        {   SF_ERR1_CLR_BIT(SF_ERR1_FUEL_TMP_VT);
            usDBmFuelTemperature = SFGetSensorTemp(usTmp, usDBpFuelTempSenType);
        }
    }   else
    {   SF_ERR1_CLR_BIT(SF_ERR1_FUEL_TMP_VT);
        usDBmFuelTemperature = usDBpSubstFuelTemp;
    }
    /* *********************** Boost Temperature ********************** */
    usTmp = usDBpAssignBoostTemp;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpBoostTempErrLow) || (usTmp > usDBpBoostTempErrHigh))
        {   SF_ERR1_SET_BIT(SF_ERR1_BOOST_TMP_VT);
            usDBmBoostTemperature = usDBpSubstBoostTemp;
        }   else
        {   SF_ERR1_CLR_BIT(SF_ERR1_BOOST_TMP_VT);
            usDBmBoostTemperature = SFGetSensorTemp(usTmp, usDBpBoostTempSenType);
        }
    }   else
    {   SF_ERR1_CLR_BIT(SF_ERR1_BOOST_TMP_VT);
        usDBmBoostTemperature = usDBpSubstBoostTemp;
    }
    /* *********************** Coolant Temperature ******************** */
    usTmp = usDBpAssignCoolantTemp;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpCoolantTempErrLow) || (usTmp > usDBpCoolantTempErrHigh))
        {   SF_ERR1_SET_BIT(SF_ERR1_WATER_TMP_VT);
            usDBmCoolantTemperature = usDBpSubstCoolantTemp;
        }   else
        {   SF_ERR1_CLR_BIT(SF_ERR1_WATER_TMP_VT);
            usDBmCoolantTemperature = SFGetSensorTemp(usTmp, usDBpCoolantTempSenType);
        }
    }   else
    {   SF_ERR1_CLR_BIT(SF_ERR1_WATER_TMP_VT);
        usDBmCoolantTemperature = usDBpSubstCoolantTemp;
    }
    /* *********************** Exhaust Temperature ******************** */
    usTmp = usDBpAssignExhaustTemp;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpExhaustTempErrLow) || (usTmp > usDBpExhaustTempErrHigh))
        {   SF_ERR1_SET_BIT(SF_ERR1_EXHAUST_TMP_VT);
            usDBmExhaustTemperature = usDBpSubstExhaustTemp;
        }   else
        {   SF_ERR1_CLR_BIT(SF_ERR1_EXHAUST_TMP_VT);
            usDBmExhaustTemperature = SFGetSensorTemp(usTmp, usDBpExhaustTempSenType);
        }
    }   else
    {   SF_ERR1_CLR_BIT(SF_ERR1_EXHAUST_TMP_VT);
        usDBmExhaustTemperature = usDBpSubstExhaustTemp;
    }
    /* ************************* Oil Pressure ************************* */  //油压测量
    usTmp = usDBpAssignOilPress;
    if (usTmp < SF_NUM_OF_ANA_IN)
    { TESTZC1[0] = usTmp;
      usTmp = pAin[usTmp];
      TESTZC1[1] = usTmp;
        if ((usTmp < usDBpOilPressErrLow) || (usTmp > usDBpOilPressErrHigh))
        {   SF_ERR1_SET_BIT(SF_ERR1_OIL_PRES_VT);
            usDBmOilPressure = usDBpSubstOilPress;
            TESTZC1[2]++;
        }   else
        {   SF_ERR1_CLR_BIT(SF_ERR1_OIL_PRES_VT);
            //usDBmOilPressure = SFGetSensorPress(usTmp, usDBpOilPressSenType);
            usDBmOilPressure = SFGetSensorPress(usTmp, 0);
            TESTZC1[3]++;
        }
    }   else
    {   SF_ERR1_CLR_BIT(SF_ERR1_OIL_PRES_VT);
        usDBmOilPressure = usDBpSubstOilPress;
        TESTZC1[4]++;
    }
    TESTZC1[5] = usDBmOilPressure;
    /* ************************* Fuel Pressure ************************ */
    usTmp = usDBpAssignFuelPress;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpFuelPressErrLow) || (usTmp > usDBpFuelPressErrHigh))
        {   SF_ERR1_SET_BIT(SF_ERR1_FUEL_PRES_VT);
            usDBmFuelPressure = usDBpSubstFuelPress;
        }   else
        {   SF_ERR1_CLR_BIT(SF_ERR1_FUEL_PRES_VT);
            usDBmFuelPressure = SFGetSensorPress(usTmp, usDBpFuelPressSenType);
        }
    }   else
    {   SF_ERR1_CLR_BIT(SF_ERR1_FUEL_PRES_VT);
        usDBmFuelPressure = usDBpSubstFuelPress;
    }
    /* ************************* Boost Pressure *********************** */
    usTmp = usDBpAssignBoostPress;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpBoostPressErrLow) || (usTmp > usDBpBoostPressErrHigh))
        {   SF_ERR1_SET_BIT(SF_ERR1_BOOST_PRES_VT);
            usDBmBoostPressure = usDBpSubstBoostPress;
        }   else
        {   SF_ERR1_CLR_BIT(SF_ERR1_BOOST_PRES_VT);
            usDBmBoostPressure = SFGetSensorPress(usTmp, usDBpBoostPressSenType);
        }
    }   else
    {   SF_ERR1_CLR_BIT(SF_ERR1_BOOST_PRES_VT);
        usDBmBoostPressure = usDBpSubstBoostPress;
    }
    /* ************************* Coolant Pressure ********************* */
    usTmp = usDBpAssignCoolantPress;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpCoolantPressErrLow) || (usTmp > usDBpCoolantPressErrHigh))
        {   SF_ERR1_SET_BIT(SF_ERR1_WATER_PRES_VT);
            usDBmCoolantPressure = usDBpSubstCoolantPress;
        }   else
        {   SF_ERR1_CLR_BIT(SF_ERR1_WATER_PRES_VT);
            usDBmCoolantPressure = SFGetSensorPress(usTmp, usDBpCoolantPressSenType);
        }
    }   else
    {   SF_ERR1_CLR_BIT(SF_ERR1_WATER_PRES_VT);
        usDBmCoolantPressure = usDBpSubstCoolantPress;
    }
    /* ************************* Fuel Level *************************** */
    usTmp = usDBpAssignFuelLevel;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpFuelLevelErrLow) || (usTmp > usDBpFuelLevelErrHigh))
        {   SF_ERR1_SET_BIT(SF_ERR1_FUEL_LVL_VT);
            usDBmFuelLevel = usDBpSubstFuelLevel;
        }   else
        {   SF_ERR1_CLR_BIT(SF_ERR1_FUEL_LVL_VT);
            usDBmFuelLevel = SFGetSensorLevel(usTmp, usDBpFuelLevelSenType);
        }
    }   else
    {   SF_ERR1_CLR_BIT(SF_ERR1_FUEL_LVL_VT);
        usDBmFuelLevel = usDBpSubstFuelLevel;
    }
    /* ************************* Coolant Level ************************ */
    usTmp = usDBpAssignCoolantLevel;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpCoolantLevelErrLow) || (usTmp > usDBpCoolantLevelErrHigh))
        {   SF_ERR1_SET_BIT(SF_ERR1_WATER_LVL_VT);
            usDBmCoolantLevel = usDBpSubstCoolantLevel;
        }   else
        {   SF_ERR1_CLR_BIT(SF_ERR1_WATER_LVL_VT);
            usDBmCoolantLevel = SFGetSensorLevel(usTmp, usDBpCoolantLevelSenType);
        }
    }   else
    {   SF_ERR1_CLR_BIT(SF_ERR1_WATER_LVL_VT);
        usDBmCoolantLevel = usDBpSubstCoolantLevel;
    }
    /* ************************* Charger Voltage ********************** */
    usTmp = usDBpAssignChargerVolt;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpChargerVoltErrLow) || (usTmp > usDBpChargerVoltErrHigh))
        {   SF_ERR1_SET_BIT(SF_ERR1_CHARGER_VLT_VT);
            usDBmChargerVoltage = usDBpSubstChargerVolt;
        }   else
        {   SF_ERR1_CLR_BIT(SF_ERR1_CHARGER_VLT_VT);
            usDBmChargerVoltage = SFInterp16u (usTmp, usDBpChargerVoltAdcLow,
            usDBpChargerVoltAdcHigh, usDBpChargerVoltRefLow, usDBpChargerVoltRefHigh);
        }
    }   else
    {   SF_ERR1_CLR_BIT(SF_ERR1_CHARGER_VLT_VT);
        usDBmChargerVoltage = usDBpSubstChargerVolt;
    }
    /* ************************* Charger Current ********************** */
    usTmp = usDBpAssignChargerCurr;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpChargerCurrErrLow) || (usTmp > usDBpChargerCurrErrHigh))
        {   SF_ERR1_SET_BIT(SF_ERR1_CHARGER_CUR_VT);
            usDBmChargerCurrent = usDBpSubstChargerCurr;
        }   else
        {   SF_ERR1_CLR_BIT(SF_ERR1_CHARGER_CUR_VT);
            usDBmChargerCurrent = SFInterp16u (usTmp, usDBpChargerCurrAdcLow,
            usDBpChargerCurrAdcHigh, usDBpChargerCurrRefLow, usDBpChargerCurrRefHigh);
        }
    }   else
    {   SF_ERR1_CLR_BIT(SF_ERR1_CHARGER_CUR_VT);
        usDBmChargerCurrent = usDBpSubstChargerCurr;
    }
    /* ************************* Starter Current ********************** */
    usTmp = usDBpAssignStarterCurr;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpStarterCurrErrLow) || (usTmp > usDBpStarterCurrErrHigh))
        {   SF_ERR1_SET_BIT(SF_ERR1_STARTER_CUR_VT);
            usDBmStarterCurrent = usDBpSubstStarterCurr;
        }   else
        {   SF_ERR1_CLR_BIT(SF_ERR1_STARTER_CUR_VT);
            usDBmStarterCurrent = SFInterp16u (usTmp, usDBpStarterCurrAdcLow,
            usDBpStarterCurrAdcHigh, usDBpStarterCurrRefLow, usDBpStarterCurrRefHigh);
        }
    }   else
    {   SF_ERR1_CLR_BIT(SF_ERR1_STARTER_CUR_VT);
        usDBmStarterCurrent = usDBpSubstStarterCurr;
    }
    /* ************************* Rack Position ************************ */
    usTmp = usDBpAssignRackPosition;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpRackPositionErrLow) || (usTmp > usDBpRackPositionErrHigh))
        {   SF_ERR1_SET_BIT(SF_ERR1_RACK_POSI_VT);
            usDBmRackPosition = usDBpSubstRackPosition;
        }   else
        {   SF_ERR1_CLR_BIT(SF_ERR1_RACK_POSI_VT);
            usDBmRackPosition = SFInterp16u (usTmp, usDBpRackPositionAdcLow,
            usDBpRackPositionAdcHigh, usDBpRackPositionRefLow, usDBpRackPositionRefHigh);
        }
    }   else
    {   SF_ERR1_CLR_BIT(SF_ERR1_RACK_POSI_VT);
        usDBmRackPosition = usDBpSubstRackPosition;
    }
}

/* ******************************************************************** */
/*                         SFUpdateSwitchesStatus()                     */
/* ******************************************************************** */
void SFUpdateSwitchesStatus (INT16U usInput)
{   INT16U usTmp, usBin;
    usBin = usInput;
    /* ************************ SwitchEngineStop ********************** */
    usTmp = usDBpFunctEngineStop;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchEngineStop  =  usDBpSwPoleEngineStop;
    }   else if (usDBpSwPoleEngineStop != 0)
    {   usDBmSwitchEngineStop  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchEngineStop  = ~(usBin >> usTmp) & 1;
    }
    /* ************************ SwitchEngineStart ********************* */
    usTmp = usDBpFunctEngineStart;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchEngineStart  =  usDBpSwPoleEngineStart;
    }   else if (usDBpSwPoleEngineStart != 0)
    {   usDBmSwitchEngineStart  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchEngineStart  = ~(usBin >> usTmp) & 1;
    }
    /* ************************ SwitchBreakerOn *********************** */
    usTmp = usDBpFunctBreakerOn;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchBreakerOn  =  usDBpSwPoleBreakerOn;
    }   else if (usDBpSwPoleBreakerOn != 0)
    {   usDBmSwitchBreakerOn  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchBreakerOn  = ~(usBin >> usTmp) & 1;
    }
    /* ************************ SwitchBreakerOff ********************** */
    usTmp = usDBpFunctBreakerOff;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchBreakerOff  =  usDBpSwPoleBreakerOff;
    }   else if (usDBpSwPoleBreakerOff != 0)
    {   usDBmSwitchBreakerOff  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchBreakerOff  = ~(usBin >> usTmp) & 1;
    }
    /* ************************ SwitchSpeedInc ************************ */
    usTmp = usDBpFunctSpeedInc;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchSpeedInc  =  usDBpSwPoleSpeedInc;
    }   else if (usDBpSwPoleSpeedInc != 0)
    {   usDBmSwitchSpeedInc  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchSpeedInc  = ~(usBin >> usTmp) & 1;
    }
    /* ************************ SwitchSpeedDec ************************ */
    usTmp = usDBpFunctSpeedDec;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchSpeedDec  =  usDBpSwPoleSpeedDec;
    }   else if (usDBpSwPoleSpeedDec != 0)
    {   usDBmSwitchSpeedDec  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchSpeedDec  = ~(usBin >> usTmp) & 1;
    }
    /* ************************ SwitchOilPump ************************* */
    usTmp = usDBpFunctOilPump;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchOilPump  =  usDBpSwPoleOilPump;
    }   else if (usDBpSwPoleOilPump != 0)
    {   usDBmSwitchOilPump  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchOilPump  = ~(usBin >> usTmp) & 1;
    }
    /* ************************ SwitchAirHeat ************************* */
    usTmp = usDBpFunctAirHeat;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchAirHeat  =  usDBpSwPoleAirHeat;
    }   else if (usDBpSwPoleAirHeat != 0)
    {   usDBmSwitchAirHeat  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchAirHeat  = ~(usBin >> usTmp) & 1;
    }
    /* ************************ SwitchAutoOrManual ******************** */
    usTmp = usDBpFunctAutoOrManual;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchAutoOrManual  =  usDBpSwPoleAutoOrManual;
    }   else if (usDBpSwPoleAutoOrManual != 0)
    {   usDBmSwitchAutoOrManual  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchAutoOrManual  = ~(usBin >> usTmp) & 1;
    }
    /* ************************ SwitchMainFeedback ******************** */
    usTmp = usDBpFunctMainFeedback;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchMainFeedback  =  usDBpSwPoleMainFeedback;
    }   else if (usDBpSwPoleMainFeedback != 0)
    {   usDBmSwitchMainFeedback  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchMainFeedback  = ~(usBin >> usTmp) & 1;
    }
    /* ************************ SwitchGensFeedback ******************** */
    usTmp = usDBpFunctGensFeedback;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchGensFeedback  =  usDBpSwPoleGensFeedback;
    }   else if (usDBpSwPoleGensFeedback != 0)
    {   usDBmSwitchGensFeedback  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchGensFeedback  = ~(usBin >> usTmp) & 1;
    }
    /* ************************ SwitchParamLock *********************** */
    usTmp = usDBpFunctParamLock;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchParamLock  =  usDBpSwPoleParamLock;
    }   else if (usDBpSwPoleParamLock != 0)
    {   usDBmSwitchParamLock  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchParamLock  = ~(usBin >> usTmp) & 1;
    }
    /* ************************ SwitchFuelLevel *********************** */
    usTmp = usDBpFunctFuelLevel;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchFuelLevel  =  usDBpSwPoleFuelLevel;
    }   else if (usDBpSwPoleFuelLevel != 0)
    {   usDBmSwitchFuelLevel  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchFuelLevel  = ~(usBin >> usTmp) & 1;
    }
    /* ************************ SwitchOilPressure ********************* */
    usTmp = usDBpFunctOilPressure;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchOilPressure  =  usDBpSwPoleOilPressure;
    }   else if (usDBpSwPoleOilPressure != 0)
    {   usDBmSwitchOilPressure  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchOilPressure  = ~(usBin >> usTmp) & 1;
    }
    /* ************************ SwitchCoolantTemp ********************* */
    usTmp = usDBpFunctCoolantTemp;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchCoolantTemp  =  usDBpSwPoleCoolantTemp;
    }   else if (usDBpSwPoleCoolantTemp != 0)
    {   usDBmSwitchCoolantTemp  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchCoolantTemp  = ~(usBin >> usTmp) & 1;
    }
    /* ************************ SwitchCoolantLevel ******************** */
    usTmp = usDBpFunctCoolantLevel;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchCoolantLevel  =  usDBpSwPoleCoolantLevel;
    }   else if (usDBpSwPoleCoolantLevel != 0)
    {   usDBmSwitchCoolantLevel  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchCoolantLevel  = ~(usBin >> usTmp) & 1;
    }
    /* ************************ SwitchAirFilter *********************** */
    usTmp = usDBpFunctAirFilter;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchAirFilter  =  usDBpSwPoleAirFilter;
    }   else if (usDBpSwPoleAirFilter != 0)
    {   usDBmSwitchAirFilter  =  (usBin >> usTmp) & 1;
    }   else
    {   usDBmSwitchAirFilter  = ~(usBin >> usTmp) & 1;
    }
}

/* ******************************************************************** */
/*                         SFUpdateBoardKeyStatus()                     */
/* ******************************************************************** */
void SFUpdateBoardKeyStatus (INT16U usInput)
{   INT16U usBin        =  usInput;
    usDBmKeyMenuUp      = (usBin >> SF_KEY_BIT_MENU_UP) & 1;
    usDBmKeyMenuDown    = (usBin >> SF_KEY_BIT_MENU_DOWN) & 1;
    usDBmKeyMenuRight   = (usBin >> SF_KEY_BIT_MENU_RIGHT) & 1;
    usDBmKeyMenuLeft    = (usBin >> SF_KEY_BIT_MENU_LEFT) & 1;
    usDBmKeyMenuEnter   = (usBin >> SF_KEY_BIT_MENU_ENTER) & 1;
    usDBmKeyOBD         = (usBin >> SF_KEY_BIT_OBD) & 1;
    usDBmKeyEngineStop  = (usBin >> SF_KEY_BIT_ENG_STOP) & 1;
    usDBmKeyEngineStart = (usBin >> SF_KEY_BIT_ENG_START) & 1;
    usDBmKeyModeAuto    = (usBin >> SF_KEY_BIT_MODE_AUTO) & 1;
    usDBmKeyModeManual  = (usBin >> SF_KEY_BIT_MODE_MANUAL) & 1;
    usDBmKeyErrorReset  = (usBin >> SF_KEY_BIT_ERROR_REET) & 1;
    usDBmKeyBreakerOn   = (usBin >> SF_KEY_BIT_SWITCH_ON) & 1;
    usDBmKeyBreakerOff  = (usBin >> SF_KEY_BIT_SWITCH_OFF) & 1;
}

/* ******************************************************************** */
/*                            SFResetAllErrors()                        */
/* ******************************************************************** */
void SFResetAllErrors (void)
{   usDBmErrorStatus1 = 0;
    usDBmErrorStatus2 = 0;
    usDBmErrorStatus3 = 0;
    usDBmErrorStatus4 = 0;
    usDBmErrorStatus5 = 0;
    usDBmErrorStatus6 = 0;
    usDBmStartFailTimes = 0;
}

/* ******************************************************************** */
/*                          SFEngineSpeedMonitor()                      */
/* ******************************************************************** */
void SFEngineSpeedMonitor (void)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    static INT16U usTimer4 = 0;
    static INT16U usTimer5 = 0;
    static INT16U usTimer6 = 0;
    INT16U usTimNow, usSpdNow;
    usSpdNow = usDBmSpeed;
    usTimNow = usFW100msTimer;
    /* ********************* Engine Starting Fail ********************* */
    if (usDBmStartFailTimes >= usDBpStartFailMax)
    {   SF_ERR4_SET_BIT(SF_ERR4_STARTING_FAIL);
    }
    /* ********************* Engine Over Speed Warn ******************* */
    if (usDBmSpeed >= usDBpSpeedOverToWarn)
    {   SF_ERR4_SET_BIT(SF_ERR4_SPEED_OVER_WARN);
    }
    else if ((usDBmSpeed + 10) < usDBpSpeedOverToWarn)
    {   SF_ERR4_CLR_BIT(SF_ERR4_SPEED_OVER_WARN);
    }
    /* ********************* Engine Over Speed Stop ******************* */
    if (usDBmSpeed < usDBpSpeedOverToStop)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpSpeedOverStopDly)
    {   SF_ERR4_SET_BIT(SF_ERR4_SPEED_OVER_STOP);
    }
    /* ********************* Engine Ramping Up Fail ******************* */
    if (usDBmSystemPhase != CTL_PHASE_RAMP_UP)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usDBpRampUpTimeMax)
    {   SF_ERR4_SET_BIT(SF_ERR4_RAMP_UP_FAIL);
    }
    /* ********************* Engine Ramping Down Fail ***************** */
    if (usDBmSystemPhase != CTL_PHASE_RAMP_DOWN)
    {   usTimer3 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer3) > usDBpRampDownTimeMax)
    {   SF_ERR4_SET_BIT(SF_ERR4_RAMP_DOWN_FAIL);
    }
    /* ********************* Engine Synchron Fail ********************* */
    if (usDBmSystemPhase != CTL_PHASE_SYNCHRING)
    {   usTimer4 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer4) > usDBpSynchronTimeMax)
    {   SF_ERR4_SET_BIT(SF_ERR4_SYNCHRON_FAIL);
    }
    /* ********************* Engine Stopping Fail ********************* */
    if (usDBmSystemPhase != CTL_PHASE_STOPPING)
    {   usTimer5 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer5) > usDBpStoppingTimeMax)
    {   SF_ERR5_SET_BIT(SF_ERR5_STOPPING_FAIL);
    }
    /* ********************* Engine Speed Wrong *********************** */
    if (usDBmSystemPhase == CTL_PHASE_STOPPED)
    {   if (usSpdNow < usDBpSpeedWrongMax)
        {   usTimer6 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer6) > usDBpSpeedWrongDly)
        {   SF_ERR5_SET_BIT(SF_ERR5_SPEED_WRONG);
        }
    }
    else if((usDBmSystemPhase == CTL_PHASE_IDLING_UP) ||
            (usDBmSystemPhase == CTL_PHASE_IDLING_DOWN) )
    {   usSpdNow = SF_GET_SUBABS(usSpdNow,usDBpSpeedIdle);
        if (usSpdNow < usDBpSpeedWrongMax)
        {   usTimer6 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer6) > usDBpSpeedWrongDly)
        {   SF_ERR5_SET_BIT(SF_ERR5_SPEED_WRONG);
        }
    }
    else if((usDBmSystemPhase == CTL_PHASE_RATED_UP) ||
            (usDBmSystemPhase == CTL_PHASE_RATED_DOWN) ||
            (usDBmSystemPhase == CTL_PHASE_SYNCHRING) ||
            (usDBmSystemPhase == CTL_PHASE_SWITCHING_ON) ||
            (usDBmSystemPhase == CTL_PHASE_SWITCHING_OFF) ||
            (usDBmSystemPhase == CTL_PHASE_WORKING) )
    {   usSpdNow = SF_GET_SUBABS(usSpdNow,usDBpSpeedRated);
        if (usSpdNow < usDBpSpeedWrongMax)
        {   usTimer6 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer6) > usDBpSpeedWrongDly)
        {   SF_ERR5_SET_BIT(SF_ERR5_SPEED_WRONG);
        }
    }
    else
    {   usTimer6 = usTimNow;
    }
}

/* ******************************************************************** */
/*                          SFEngineTempMonitor()                       */
/* ******************************************************************** */
void SFEngineTempMonitor (void)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    INT16U usTimNow;
    usTimNow = usFW100msTimer;
    /* ****************** Coolant Temp Warn and Stop ****************** */
    if ((usDBmCoolantTemperature > usDBpCoolantTempToWarn) ||
        (usDBmSwitchCoolantTemp != 0))
    {   SF_ERR2_SET_BIT(SF_ERR2_WATER_TMP_WARN);
    }
    else if ((usDBmCoolantTemperature + 80) <= usDBpCoolantTempToWarn)
    {   SF_ERR2_CLR_BIT(SF_ERR2_WATER_TMP_WARN);
    }
    if (usDBmCoolantTemperature <= usDBpCoolantTempToStop)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usDBpCoolantTempStopDly)
    {   SF_ERR2_SET_BIT(SF_ERR2_WATER_TMP_STOP);
    }
    /* ******************** Boost Temp Warn and Stop ****************** */
    if (usDBmBoostTemperature > usDBpBoostTempToWarn)
    {   SF_ERR2_SET_BIT(SF_ERR2_BOOST_TMP_WARN);
    }
    else if ((usDBmBoostTemperature + 80) <= usDBpBoostTempToWarn)
    {   SF_ERR2_CLR_BIT(SF_ERR2_BOOST_TMP_WARN);
    }
    if (usDBmBoostTemperature <= usDBpBoostTempToStop)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpBoostTempStopDly)
    {   SF_ERR2_SET_BIT(SF_ERR2_BOOST_TMP_STOP);
    }
    /* ********************* Oil Temp Warn and Stop ******************* */
    if (usDBmOilTemperature > usDBpOilTempToWarn)
    {   SF_ERR2_SET_BIT(SF_ERR2_OIL_TMP_WARN);
    }
    else if ((usDBmOilTemperature + 80) <= usDBpOilTempToWarn)
    {   SF_ERR2_CLR_BIT(SF_ERR2_OIL_TMP_WARN);
    }
    if (usDBmOilTemperature <= usDBpOilTempToStop)
    {   usTimer3 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer3) > usDBpOilTempStopDly)
    {   SF_ERR2_SET_BIT(SF_ERR2_OIL_TMP_STOP);
    }
    /* ********************* Intern Temperature Warn ****************** */
    if (usDBmInternTemperature > usDBpInternTempToWarn)
    {   SF_ERR4_SET_BIT(SF_ERR4_INTERN_TMP_WARN);
    }
    else if ((usDBmInternTemperature + 80) <= usDBpInternTempToWarn)
    {   SF_ERR4_CLR_BIT(SF_ERR4_INTERN_TMP_WARN);
    }
}

/* ******************************************************************** */
/*                          SFEnginePressMonitor()                      */
/* ******************************************************************** */
void SFEnginePressMonitor (void)
{   static INT16U usStart  = 0;
    static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    INT16U usTmp, usTimNow;
    usTimNow = usFW100msTimer;
    /* ************************** Start Flag ************************** */
    if (usDBmEngineRunning == 0)
    {   usTimer1 = usTimNow;
        usStart  = 0;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpOilPressStartDly)
    {   usStart  = 1;
    }
    /* ************************* Pressure Stop ************************ */
    usTmp = SFGet1DMap10(usDBmSpeed, &aDBpOilPressStopSpeed[0],
                                     &aDBpOilPressStopPress[0]);
    if ((usStart == 0) || (usDBmOilPressure >= usTmp))
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usDBpOilPressStopDly)
    {   SF_ERR2_SET_BIT(SF_ERR2_OIL_PRESS_STOP);
    }
    /* ************************* Pressure Warn ************************ */
    usTmp = SFGet1DMap10(usDBmSpeed, &aDBpOilPressWarnSpeed[0],
                                     &aDBpOilPressWarnPress[0]);
    if (usStart == 0)
    {   SF_ERR2_CLR_BIT(SF_ERR2_OIL_PRESS_WARN);
        usTimer3 = usTimNow;
    }
    else if ((usDBmOilPressure >= usTmp) && (usDBmSwitchOilPressure == 0))
    {   SF_ERR2_CLR_BIT(SF_ERR2_OIL_PRESS_WARN);
        usTimer3 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer3) > usDBpOilPressWarnDly)
    {   SF_ERR2_SET_BIT(SF_ERR2_OIL_PRESS_WARN);
    }
}

/* ******************************************************************** */
/*                          SFEngineLevelMonitor()                      */
/* ******************************************************************** */
void SFEngineLevelMonitor (void)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    static INT16U usTimer4 = 0;
    INT16U usTimNow;
    usTimNow = usFW100msTimer;
    /* ******************* Fuel Level Warn and Stop ******************* */
    if ((usDBmFuelLevel >= usDBpFuelLevelToWarn) &&
        (usDBmSwitchFuelLevel == 0))
    {   SF_ERR2_CLR_BIT(SF_ERR2_FUEL_LVL_WARN);
        usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpFuelLevelWarnDly)
    {   SF_ERR2_SET_BIT(SF_ERR2_FUEL_LVL_WARN);
    }
    if (usDBmFuelLevel >= usDBpFuelLevelToStop)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usDBpFuelLevelStopDly)
    {   SF_ERR2_SET_BIT(SF_ERR2_FUEL_LVL_STOP);
    }
    /* ****************** Coolant Level Warn and Stop ***************** */
    if ((usDBmCoolantLevel >= usDBpCoolantLevelToWarn) &&
        (usDBmSwitchCoolantLevel == 0))
    {   SF_ERR2_CLR_BIT(SF_ERR2_WATER_LVL_WARN);
        usTimer3 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer3) > usDBpCoolantLevelWarnDly)
    {   SF_ERR2_SET_BIT(SF_ERR2_WATER_LVL_WARN);
    }
    if (usDBmCoolantLevel >= usDBpCoolantLevelToStop)
    {   usTimer4 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer4) > usDBpCoolantLevelStopDly)
    {   SF_ERR2_SET_BIT(SF_ERR2_WATER_LVL_STOP);
    }
}

/* ******************************************************************** */
/*                          SFEngineLevelMonitor()                      */
/* ******************************************************************** */
void SFEngineFilterMonitor (void)
{   static INT16U usTimer1 = 0;
    if (usDBmSwitchAirFilter == 0)
    {   SF_ERR1_CLR_BIT(SF_ERR1_AIR_FILTER_WARN);
        usTimer1 = usFW100msTimer;
    }
    else if ((INT16U)(usFW100msTimer-usTimer1) > usDBpAirFilterWarnDly)
    {   SF_ERR1_SET_BIT(SF_ERR1_AIR_FILTER_WARN);
    }
}

/* ******************************************************************** */
/*                          SFEngineVoltageMonitor()                    */
/* ******************************************************************** */
void SFEngineVoltageMonitor (void)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    static INT16U usTimer4 = 0;
    INT16U usTimNow;
    usTimNow = usFW100msTimer;
    /* ********************** Supply voltage ************************** */
    if (usDBmSupplyVoltage >= usDBpSupplyVoltWarnLow)
    {   SF_ERR2_CLR_BIT(SF_ERR2_SUPPLY_VLT_LOW);
        usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpSupplyVoltWarnDly)
    {   SF_ERR2_SET_BIT(SF_ERR2_SUPPLY_VLT_LOW);
    }
    if (usDBmSupplyVoltage <= usDBpSupplyVoltWarnHigh)
    {   SF_ERR2_CLR_BIT(SF_ERR2_SUPPLY_VLT_HIGH);
        usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usDBpSupplyVoltWarnDly)
    {   SF_ERR2_SET_BIT(SF_ERR2_SUPPLY_VLT_HIGH);
    }
    /* ********************** Charger voltage ************************* */
    if (usDBmChargerVoltage >= usDBpChargerVoltWarnLow)
    {   SF_ERR2_CLR_BIT(SF_ERR2_CHARGER_VLT_LOW);
        usTimer3 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer3) > usDBpChargerVoltWarnDly)
    {   SF_ERR2_SET_BIT(SF_ERR2_CHARGER_VLT_LOW);
    }
    if (usDBmChargerVoltage <= usDBpChargerVoltWarnHigh)
    {   SF_ERR2_CLR_BIT(SF_ERR2_CHARGER_VLT_HGH);
        usTimer4 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer4) > usDBpChargerVoltWarnDly)
    {   SF_ERR2_SET_BIT(SF_ERR2_CHARGER_VLT_HGH);
    }
}

/* ******************************************************************** */
/*                          SFEngineCurrentMonitor()                    */
/* ******************************************************************** */
void SFEngineCurrentMonitor (void)
{   static INT16U usTimer1 = 0;
    INT16U usTimNow;
    usTimNow = usFW100msTimer;
    /* ********************** Charger Current ************************* */
    if (usDBmChargerCurrent <= usDBpChargerCurrToWarn)
    {   SF_ERR4_CLR_BIT(SF_ERR4_CHARGER_CUR_HGH);
        usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpChargerCurrWarnDly)
    {   SF_ERR4_SET_BIT(SF_ERR4_CHARGER_CUR_HGH);
    }
}

/* ******************************************************************** */
/*                          SFEngineRackPosiMonitor()                   */
/* ******************************************************************** */
void SFEngineRackPosiMonitor (void)
{   static INT16U usTimer1 = 0;
    INT16U usTimNow;
    usTimNow = usFW100msTimer;
    if (usDBmRackPosition <= usDBpRackPositionToWarn)
    {   SF_ERR4_CLR_BIT(SF_ERR4_RACK_POSI_HIGH);
        usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpRackPositionWarnDly)
    {   SF_ERR4_SET_BIT(SF_ERR4_RACK_POSI_HIGH);
    }
}

/* ******************************************************************** */
/*                          SFMainVoltageMonitor()                      */
/* ******************************************************************** */
void SFMainVoltageMonitor (void)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    static INT16U usTimer4 = 0;
    static INT16U usTimer5 = 0;
    static INT16U usTimer6 = 0;
    static INT16U usTimer7 = 0;
    static INT16U usTimer8 = 0;
    INT16U usMax, usMin, usTimNow, usErrDly, usNorDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpMainVoltErrorDly;
    usNorDly = usDBpMainVoltNormalDly;
    /* ********************** Main phase voltage ********************** */
    usMax = usDBmMainVoltA;
    usMin = usMax;
    if (usMax < usDBmMainVoltB)
    {   usMax = usDBmMainVoltB;
    }   else if (usMin > usDBmMainVoltB)
    {   usMin = usDBmMainVoltB;
    }
    if (usMax < usDBmMainVoltC)
    {   usMax = usDBmMainVoltC;
    }   else if (usMin > usDBmMainVoltC)
    {   usMin = usDBmMainVoltC;
    }
    /* ********************** Main phase voltage Low ****************** */
    if (SF_ERR3_GET_BIT(SF_ERR3_MAIN_LNVLT_LOW) == 0)
    {   if (usMin >= usDBpMainLnVoltErrLow)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   SF_ERR3_SET_BIT(SF_ERR3_MAIN_LNVLT_LOW);
            usTimer1 = usTimNow;
        }
    }
    else if (usMin < usDBpMainLnVoltErrLow)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usNorDly)
    {   SF_ERR3_CLR_BIT(SF_ERR3_MAIN_LNVLT_LOW);
        usTimer1 = usTimNow;
    }
    /* ********************** Main phase voltage High ***************** */
    if (SF_ERR3_GET_BIT(SF_ERR3_MAIN_LNVLT_HIGH) == 0)
    {   if (usMax < usDBpMainLnVoltErrHigh)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
        {   SF_ERR3_SET_BIT(SF_ERR3_MAIN_LNVLT_HIGH);
            usTimer2 = usTimNow;
        }
    }
    else if (usMax >= usDBpMainLnVoltErrHigh)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usNorDly)
    {   SF_ERR3_CLR_BIT(SF_ERR3_MAIN_LNVLT_HIGH);
        usTimer2 = usTimNow;
    }
    /* ********************* Main line voltage ************************ */
    usMax = usDBmMainVoltAB;
    usMin = usMax;
    if (usMax < usDBmMainVoltBC)
    {   usMax = usDBmMainVoltBC;
    }   else if (usMin > usDBmMainVoltBC)
    {   usMin = usDBmMainVoltBC;
    }
    if (usMax < usDBmMainVoltCA)
    {   usMax = usDBmMainVoltCA;
    }   else if (usMin > usDBmMainVoltCA)
    {   usMin = usDBmMainVoltCA;
    }
    /* ********************** Main line voltage Low ******************* */
    if (SF_ERR3_GET_BIT(SF_ERR3_MAIN_LLVLT_LOW) == 0)
    {   if (usMin >= usDBpMainLlVoltErrLow)
        {   usTimer3 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer3) > usErrDly)
        {   SF_ERR3_SET_BIT(SF_ERR3_MAIN_LLVLT_LOW);
            usTimer3 = usTimNow;
        }
    }
    else if (usMin < usDBpMainLlVoltErrLow)
    {   usTimer3 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer3) > usNorDly)
    {   SF_ERR3_CLR_BIT(SF_ERR3_MAIN_LLVLT_LOW);
        usTimer3 = usTimNow;
    }
    /* ********************** Main line voltage High ****************** */
    if (SF_ERR3_GET_BIT(SF_ERR3_MAIN_LLVLT_HIGH) == 0)
    {   if (usMax < usDBpMainLlVoltErrHigh)
        {   usTimer4 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer4) > usErrDly)
        {   SF_ERR3_SET_BIT(SF_ERR3_MAIN_LLVLT_HIGH);
            usTimer4 = usTimNow;
        }
    }
    else if (usMax >= usDBpMainLlVoltErrHigh)
    {   usTimer4 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer4) > usNorDly)
    {   SF_ERR3_CLR_BIT(SF_ERR3_MAIN_LLVLT_HIGH);
        usTimer4 = usTimNow;
    }
    /* ********************* Main voltage phase *********************** */
    usMax = usDBmMainPhaseAB;
    usMin = usMax;
    if (usMax < usDBmMainPhaseBC)
    {   usMax = usDBmMainPhaseBC;
    }   else if (usMin > usDBmMainPhaseBC)
    {   usMin = usDBmMainPhaseBC;
    }
    if (usMax < usDBmMainPhaseCA)
    {   usMax = usDBmMainPhaseCA;
    }   else if (usMin > usDBmMainPhaseCA)
    {   usMin = usDBmMainPhaseCA;
    }
    /* ********************** Main voltage phase Low ****************** */
    if (SF_ERR3_GET_BIT(SF_ERR3_MAIN_PHASE_LOW) == 0)
    {   if (usMin >= usDBpMainPhaseErrLow)
        {   usTimer5 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer5) > usErrDly)
        {   SF_ERR3_SET_BIT(SF_ERR3_MAIN_PHASE_LOW);
            usTimer5 = usTimNow;
        }
    }
    else if (usMin < usDBpMainPhaseErrLow)
    {   usTimer5 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer5) > usNorDly)
    {   SF_ERR3_CLR_BIT(SF_ERR3_MAIN_PHASE_LOW);
        usTimer5 = usTimNow;
    }
    /* ********************** Main voltage phase High ***************** */
    if (SF_ERR3_GET_BIT(SF_ERR3_MAIN_PHASE_HIGH) == 0)
    {   if (usMax < usDBpMainPhaseErrHigh)
        {   usTimer6 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer6) > usErrDly)
        {   SF_ERR3_SET_BIT(SF_ERR3_MAIN_PHASE_HIGH);
            usTimer6 = usTimNow;
        }
    }
    else if (usMax >= usDBpMainPhaseErrHigh)
    {   usTimer6 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer6) > usNorDly)
    {   SF_ERR3_CLR_BIT(SF_ERR3_MAIN_PHASE_HIGH);
        usTimer6 = usTimNow;
    }
    /* ********************** Main voltage freq Low ******************* */
    if (SF_ERR3_GET_BIT(SF_ERR3_MAIN_FREQ_LOW) == 0)
    {   if (usDBmMainFreq >= usDBpMainFreqErrLow)
        {   usTimer7 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer7) > usErrDly)
        {   SF_ERR3_SET_BIT(SF_ERR3_MAIN_FREQ_LOW);
            usTimer7 = usTimNow;
        }
    }
    else if (usDBmMainFreq < usDBpMainFreqErrLow)
    {   usTimer7 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer7) > usNorDly)
    {   SF_ERR3_CLR_BIT(SF_ERR3_MAIN_FREQ_LOW);
        usTimer7 = usTimNow;
    }
    /* ********************** Main voltage freq High ****************** */
    if (SF_ERR3_GET_BIT(SF_ERR3_MAIN_FREQ_HIGH) == 0)
    {   if (usDBmMainFreq < usDBpMainFreqErrHigh)
        {   usTimer8 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer8) > usErrDly)
        {   SF_ERR3_SET_BIT(SF_ERR3_MAIN_FREQ_HIGH);
            usTimer8 = usTimNow;
        }
    }
    else if (usDBmMainFreq >= usDBpMainFreqErrHigh)
    {   usTimer8 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer8) > usNorDly)
    {   SF_ERR3_CLR_BIT(SF_ERR3_MAIN_FREQ_HIGH);
        usTimer8 = usTimNow;
    }
}

/* ******************************************************************** */
/*                          SFGensVoltageMonitor()                      */
/* ******************************************************************** */
void SFGensVoltageMonitor (void)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    static INT16U usTimer4 = 0;
    static INT16U usTimer5 = 0;
    static INT16U usTimer6 = 0;
    static INT16U usTimer7 = 0;
    static INT16U usTimer8 = 0;
    INT16U usMax, usMin, usTimNow, usErrDly, usNorDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpGensVoltErrorDly;
    usNorDly = usDBpGensVoltNormalDly;
    /* ********************** Gens phase voltage ********************** */
    usMax = usDBmGensVoltA;
    usMin = usMax;
    if (usMax < usDBmGensVoltB)
    {   usMax = usDBmGensVoltB;
    }   else if (usMin > usDBmGensVoltB)
    {   usMin = usDBmGensVoltB;
    }
    if (usMax < usDBmGensVoltC)
    {   usMax = usDBmGensVoltC;
    }   else if (usMin > usDBmGensVoltC)
    {   usMin = usDBmGensVoltC;
    }
    /* ********************** Gens phase voltage Low ****************** */
    if (SF_ERR3_GET_BIT(SF_ERR3_GENS_LNVLT_LOW) == 0)
    {   if (usMin >= usDBpGensLnVoltErrLow)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   SF_ERR3_SET_BIT(SF_ERR3_GENS_LNVLT_LOW);
            usTimer1 = usTimNow;
        }
    }
    else if (usMin < usDBpGensLnVoltErrLow)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usNorDly)
    {   SF_ERR3_CLR_BIT(SF_ERR3_GENS_LNVLT_LOW);
        usTimer1 = usTimNow;
    }
    /* ********************** Gens phase voltage High ***************** */
    if (SF_ERR3_GET_BIT(SF_ERR3_GENS_LNVLT_HIGH) == 0)
    {   if (usMax < usDBpGensLnVoltErrHigh)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
        {   SF_ERR3_SET_BIT(SF_ERR3_GENS_LNVLT_HIGH);
            usTimer2 = usTimNow;
        }
    }
    else if (usMax >= usDBpGensLnVoltErrHigh)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usNorDly)
    {   SF_ERR3_CLR_BIT(SF_ERR3_GENS_LNVLT_HIGH);
        usTimer2 = usTimNow;
    }
    /* ********************* Gens line voltage ************************ */
    usMax = usDBmGensVoltAB;
    usMin = usMax;
    if (usMax < usDBmGensVoltBC)
    {   usMax = usDBmGensVoltBC;
    }   else if (usMin > usDBmGensVoltBC)
    {   usMin = usDBmGensVoltBC;
    }
    if (usMax < usDBmGensVoltCA)
    {   usMax = usDBmGensVoltCA;
    }   else if (usMin > usDBmGensVoltCA)
    {   usMin = usDBmGensVoltCA;
    }
    /* ********************** Gens line voltage Low ******************* */
    if (SF_ERR3_GET_BIT(SF_ERR3_GENS_LLVLT_LOW) == 0)
    {   if (usMin >= usDBpGensLlVoltErrLow)
        {   usTimer3 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer3) > usErrDly)
        {   SF_ERR3_SET_BIT(SF_ERR3_GENS_LLVLT_LOW);
            usTimer3 = usTimNow;
        }
    }
    else if (usMin < usDBpGensLlVoltErrLow)
    {   usTimer3 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer3) > usNorDly)
    {   SF_ERR3_CLR_BIT(SF_ERR3_GENS_LLVLT_LOW);
        usTimer3 = usTimNow;
    }
    /* ********************** Gens line voltage High ****************** */
    if (SF_ERR3_GET_BIT(SF_ERR3_GENS_LLVLT_HIGH) == 0)
    {   if (usMax < usDBpGensLlVoltErrHigh)
        {   usTimer4 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer4) > usErrDly)
        {   SF_ERR3_SET_BIT(SF_ERR3_GENS_LLVLT_HIGH);
            usTimer4 = usTimNow;
        }
    }
    else if (usMax >= usDBpGensLlVoltErrHigh)
    {   usTimer4 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer4) > usNorDly)
    {   SF_ERR3_CLR_BIT(SF_ERR3_GENS_LLVLT_HIGH);
        usTimer4 = usTimNow;
    }
    /* ********************* Gens voltage phase *********************** */
    usMax = usDBmGensPhaseAB;
    usMin = usMax;
    if (usMax < usDBmGensPhaseBC)
    {   usMax = usDBmGensPhaseBC;
    }   else if (usMin > usDBmGensPhaseBC)
    {   usMin = usDBmGensPhaseBC;
    }
    if (usMax < usDBmGensPhaseCA)
    {   usMax = usDBmGensPhaseCA;
    }   else if (usMin > usDBmGensPhaseCA)
    {   usMin = usDBmGensPhaseCA;
    }
    /* ********************** Gens voltage phase Low ****************** */
    if (SF_ERR3_GET_BIT(SF_ERR3_GENS_PHASE_LOW) == 0)
    {   if (usMin >= usDBpGensPhaseErrLow)
        {   usTimer5 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer5) > usErrDly)
        {   SF_ERR3_SET_BIT(SF_ERR3_GENS_PHASE_LOW);
            usTimer5 = usTimNow;
        }
    }
    else if (usMin < usDBpGensPhaseErrLow)
    {   usTimer5 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer5) > usNorDly)
    {   SF_ERR3_CLR_BIT(SF_ERR3_GENS_PHASE_LOW);
        usTimer5 = usTimNow;
    }
    /* ********************** Gens voltage phase High ***************** */
    if (SF_ERR3_GET_BIT(SF_ERR3_GENS_PHASE_HIGH) == 0)
    {   if (usMax < usDBpGensPhaseErrHigh)
        {   usTimer6 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer6) > usErrDly)
        {   SF_ERR3_SET_BIT(SF_ERR3_GENS_PHASE_HIGH);
            usTimer6 = usTimNow;
        }
    }
    else if (usMax >= usDBpGensPhaseErrHigh)
    {   usTimer6 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer6) > usNorDly)
    {   SF_ERR3_CLR_BIT(SF_ERR3_GENS_PHASE_HIGH);
        usTimer6 = usTimNow;
    }
    /* ********************** Gens voltage freq Low ******************* */
    if (SF_ERR3_GET_BIT(SF_ERR3_GENS_FREQ_LOW) == 0)
    {   if (usDBmGensFreq >= usDBpGensFreqErrLow)
        {   usTimer7 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer7) > usErrDly)
        {   SF_ERR3_SET_BIT(SF_ERR3_GENS_FREQ_LOW);
            usTimer7 = usTimNow;
        }
    }
    else if (usDBmGensFreq < usDBpGensFreqErrLow)
    {   usTimer7 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer7) > usNorDly)
    {   SF_ERR3_CLR_BIT(SF_ERR3_GENS_FREQ_LOW);
        usTimer7 = usTimNow;
    }
    /* ********************** Gens voltage freq High ****************** */
    if (SF_ERR3_GET_BIT(SF_ERR3_GENS_FREQ_HIGH) == 0)
    {   if (usDBmGensFreq < usDBpGensFreqErrHigh)
        {   usTimer8 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer8) > usErrDly)
        {   SF_ERR3_SET_BIT(SF_ERR3_GENS_FREQ_HIGH);
            usTimer8 = usTimNow;
        }
    }
    else if (usDBmGensFreq >= usDBpGensFreqErrHigh)
    {   usTimer8 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer8) > usNorDly)
    {   SF_ERR3_CLR_BIT(SF_ERR3_GENS_FREQ_HIGH);
        usTimer8 = usTimNow;
    }
}

/* ******************************************************************** */
/*                          SFGensCurrentMonitor()                      */
/* ******************************************************************** */
void SFGensCurrentMonitor (void)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    INT16U usMax, usTimNow, usErrDly, usNorDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpGensCurrErrorDly;
    usNorDly = usDBpGensCurrNormalDly;
    /* ********************** Gens phase current ********************** */
    usMax = usDBmGensCurrA;
    if (usMax < usDBmGensCurrB)
    {   usMax = usDBmGensCurrB;
    }
    if (usMax < usDBmGensCurrC)
    {   usMax = usDBmGensCurrC;
    }
    /* ********************** Gens Current High *********************** */
    if (SF_ERR4_GET_BIT(SF_ERR4_GENS_CURR_HIGH) == 0)
    {   if (usMax < usDBpGensCurrErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   SF_ERR4_SET_BIT(SF_ERR4_GENS_CURR_HIGH);
            usTimer1 = usTimNow;
        }
    }
    else if (usMax >= usDBpGensCurrErrHigh)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usNorDly)
    {   SF_ERR4_CLR_BIT(SF_ERR4_GENS_CURR_HIGH);
        usTimer1 = usTimNow;
    }
    /* ********************** Gens Gnd Current ************************ */
    if (SF_ERR4_GET_BIT(SF_ERR4_GENS_CURR_GND) == 0)
    {   if (usDBmGensCurrGd < usDBpGensCurrGdErrHigh)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
        {   SF_ERR4_SET_BIT(SF_ERR4_GENS_CURR_GND);
            usTimer2 = usTimNow;
        }
    }
    else if (usDBmGensCurrGd >= usDBpGensCurrGdErrHigh)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usNorDly)
    {   SF_ERR4_CLR_BIT(SF_ERR4_GENS_CURR_GND);
        usTimer2 = usTimNow;
    }
}

/* ******************************************************************** */
/*                          SFGensPowerMonitor()                        */
/* ******************************************************************** */
void SFGensPowerMonitor (void)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    static INT16U usTimer4 = 0;
    static INT16U usTimer5 = 0;
    INT16U usTimNow, usErrDly, usNorDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpGensPowerErrorDly;
    usNorDly = usDBpGensPowerNormalDly;
    /* ********************** Gens Act Power High ********************* */
    if (SF_ERR4_GET_BIT(SF_ERR4_ACT_PWR_HIGH) == 0)
    {   if (ssDBmActPowerAll < usDBpActPowerErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   SF_ERR4_SET_BIT(SF_ERR4_ACT_PWR_HIGH);
            usTimer1 = usTimNow;
        }
    }
    else if (ssDBmActPowerAll >= usDBpActPowerErrHigh)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usNorDly)
    {   SF_ERR4_CLR_BIT(SF_ERR4_ACT_PWR_HIGH);
        usTimer1 = usTimNow;
    }
    /* ********************** Gens React Power High ******************* */
    if (SF_ERR4_GET_BIT(SF_ERR4_REACT_PWR_HIGH) == 0)
    {   if (ssDBmReactPowerAll < usDBpReactPowerErrHigh)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
        {   SF_ERR4_SET_BIT(SF_ERR4_REACT_PWR_HIGH);
            usTimer2 = usTimNow;
        }
    }
    else if (ssDBmReactPowerAll >= usDBpReactPowerErrHigh)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usNorDly)
    {   SF_ERR4_CLR_BIT(SF_ERR4_REACT_PWR_HIGH);
        usTimer2 = usTimNow;
    }
    /* ********************** Gens App Power High ********************* */
    if (SF_ERR4_GET_BIT(SF_ERR4_APP_PWR_HIGH) == 0)
    {   if (usDBmAppPowerAll < usDBpAppPowerErrHigh)
        {   usTimer3 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer3) > usErrDly)
        {   SF_ERR4_SET_BIT(SF_ERR4_APP_PWR_HIGH);
            usTimer3 = usTimNow;
        }
    }
    else if (usDBmAppPowerAll >= usDBpAppPowerErrHigh)
    {   usTimer3 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer3) > usNorDly)
    {   SF_ERR4_CLR_BIT(SF_ERR4_APP_PWR_HIGH);
        usTimer3 = usTimNow;
    }
    /* ********************** Gens Power Factor High ****************** */
    if (SF_ERR4_GET_BIT(SF_ERR4_PWR_FACTOR_HIGH) == 0)
    {   if (ssDBmPowerFactorAll < usDBpPowerFactorErrHigh)
        {   usTimer4 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer4) > usErrDly)
        {   SF_ERR4_SET_BIT(SF_ERR4_PWR_FACTOR_HIGH);
            usTimer4 = usTimNow;
        }
    }
    else if (ssDBmPowerFactorAll >= usDBpPowerFactorErrHigh)
    {   usTimer4 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer4) > usNorDly)
    {   SF_ERR4_CLR_BIT(SF_ERR4_PWR_FACTOR_HIGH);
        usTimer4 = usTimNow;
    }
    /* ********************** Gens Power Factor Low ******************* */
    if (SF_ERR4_GET_BIT(SF_ERR4_PWR_FACTOR_LOW) == 0)
    {   if (ssDBmPowerFactorAll >= usDBpPowerFactorErrLow)
        {   usTimer5 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer5) > usErrDly)
        {   SF_ERR4_SET_BIT(SF_ERR4_PWR_FACTOR_LOW);
            usTimer5 = usTimNow;
        }
    }
    else if (ssDBmPowerFactorAll < usDBpPowerFactorErrLow)
    {   usTimer5 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer5) > usNorDly)
    {   SF_ERR4_CLR_BIT(SF_ERR4_PWR_FACTOR_LOW);
        usTimer5 = usTimNow;
    }
}

/* ******************************************************************** */
/*                       SFVoltageDifferMonitor()                       */
/* ******************************************************************** */
void SFVoltageDifferMonitor (void)
{   static INT16U usTimer1 = 0;
    if((SFAbs16s(ssDBmVoltDiffer) > usDBpVoltDifferMax) ||
       (SFAbs16s(ssDBmFreqDiffer) > usDBpFreqDifferMax) ||
       (SFAbs16s(ssDBmPhaseDiffer) > usDBpPhaseDifferMax))
    {   SF_ERR5_SET_BIT(SF_ERR5_VOLT_DIFF_OVER);
        usTimer1 = usFW100msTimer;
    }
    else if ((INT16U)(usFW100msTimer-usTimer1) > usDBpVoltageDifferChkDly)
    {   SF_ERR5_CLR_BIT(SF_ERR5_VOLT_DIFF_OVER);
        usTimer1 = usFW100msTimer;
    }
}

/* ******************************************************************** */
/*                      SFGensBreakerTripMonitor()                      */
/* ******************************************************************** */
void SFGensBreakerTripMonitor (void)
{   static INT16U usTimer1 = 0;
    if((usDBpFunctGensFeedback >= SF_NUM_OF_SW_IN) ||
       (usDBmSwitchGensFeedback != 0) ||
       (usDBmGensBreakerOn == 0) )
    {   usTimer1 = usFW100msTimer;
    }
    else if ((INT16U)(usFW100msTimer-usTimer1) > usDBpBreakerTripChkDly)
    {   SF_ERR5_SET_BIT(SF_ERR5_BREAKER_TRIP);
    }
}

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */