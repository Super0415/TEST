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

/* ******************************************************************** */
/*                      Temperature Sensor Maps                         */
/* ******************************************************************** */
const INT16U aSFTempMap0Adc[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap0Tmp[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFTempMap1Adc[10] =
{     SF_OUM_TO_ADC(10),  SF_OUM_TO_ADC(20),
      SF_OUM_TO_ADC(30),  SF_OUM_TO_ADC(40),
      SF_OUM_TO_ADC(50),  SF_OUM_TO_ADC(60),
      SF_OUM_TO_ADC(70),  SF_OUM_TO_ADC(80),
      SF_OUM_TO_ADC(90),  SF_OUM_TO_ADC(100)
};
const INT16U aSFTempMap1Tmp[10] =
{     SF_TMP_TO_16U(-40), SF_TMP_TO_16U(-30),
      SF_TMP_TO_16U(-10), SF_TMP_TO_16U(10),
      SF_TMP_TO_16U(30),  SF_TMP_TO_16U(50),
      SF_TMP_TO_16U(70),  SF_TMP_TO_16U(90),
      SF_TMP_TO_16U(110), SF_TMP_TO_16U(120)
};
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

/* ******************************************************************** */
/*                         Level Sensor Maps                            */
/* ******************************************************************** */
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

/* ******************************************************************** */
/*                       Pressure Sensor Maps                           */
/* ******************************************************************** */
const INT16U aSFPressMap0Adc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const INT16U aSFPressMap0Prs[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
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
{   uiSFStatus = 0;
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
{   return ssData >= 0 ? (INT16U)ssData : (INT16U)(-ssData);
}

/* ******************************************************************** */
/*                            SFSqrt32u()                               */
/* ******************************************************************** */
INT16U SFSqrt32u (INT32U uiInput)
{   INT32U uiDt, uiRt;
    uiDt  = uiInput;
    uiRt  = 0x8000;
    if ((uiRt * uiRt) > uiDt) uiRt -= 0x8000;
    uiRt += 0x4000;
    if ((uiRt * uiRt) > uiDt) uiRt -= 0x4000;
    uiRt += 0x2000;
    if ((uiRt * uiRt) > uiDt) uiRt -= 0x2000;
    uiRt += 0x1000;
    if ((uiRt * uiRt) > uiDt) uiRt -= 0x1000;
    uiRt += 0x0800;
    if ((uiRt * uiRt) > uiDt) uiRt -= 0x0800;
    uiRt += 0x0400;
    if ((uiRt * uiRt) > uiDt) uiRt -= 0x0400;
    uiRt += 0x0200;
    if ((uiRt * uiRt) > uiDt) uiRt -= 0x0200;
    uiRt += 0x0100;
    if ((uiRt * uiRt) > uiDt) uiRt -= 0x0100;
    uiRt += 0x0080;
    if ((uiRt * uiRt) > uiDt) uiRt -= 0x0080;
    uiRt += 0x0040;
    if ((uiRt * uiRt) > uiDt) uiRt -= 0x0040;
    uiRt += 0x0020;
    if ((uiRt * uiRt) > uiDt) uiRt -= 0x0020;
    uiRt += 0x0010;
    if ((uiRt * uiRt) > uiDt) uiRt -= 0x0010;
    uiRt += 0x0008;
    if ((uiRt * uiRt) > uiDt) uiRt -= 0x0008;
    uiRt += 0x0004;
    if ((uiRt * uiRt) > uiDt) uiRt -= 0x0004;
    uiRt += 0x0002;
    if ((uiRt * uiRt) > uiDt) uiRt -= 0x0002;
    uiRt += 0x0001;
    if ((uiRt * uiRt) > uiDt) uiRt -= 0x0001;
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
/*                           SFGetPowerTwo16u()                         */
/* ******************************************************************** */
INT08U SFGetPowerTwo16u (INT16U usData)
{   if((usData & 0x8000) != 0)
    {   return 15;
    }
    if((usData & 0x4000) != 0)
    {   return 14;
    }
    if((usData & 0x2000) != 0)
    {   return 13;
    }
    if((usData & 0x1000) != 0)
    {   return 12;
    }
    if((usData & 0x0800) != 0)
    {   return 11;
    }
    if((usData & 0x0400) != 0)
    {   return 10;
    }
    if((usData & 0x0200) != 0)
    {   return 9;
    }
    if((usData & 0x0100) != 0)
    {   return 8;
    }
    if((usData & 0x0080) != 0)
    {   return 7;
    }
    if((usData & 0x0040) != 0)
    {   return 6;
    }
    if((usData & 0x0020) != 0)
    {   return 5;
    }
    if((usData & 0x0010) != 0)
    {   return 4;
    }
    if((usData & 0x0008) != 0)
    {   return 3;
    }
    if((usData & 0x0004) != 0)
    {   return 2;
    }
    if((usData & 0x0002) != 0)
    {   return 1;
    }
    return 0;
}

/* ******************************************************************** */
/*                        SFEndianExchange16u()                         */
/* ******************************************************************** */
INT16U SFEndianExchange16u (INT16U usData)
{   return ((usData & (INT16U)0x00FF) << 8) |
           ((usData & (INT16U)0xFF00) >> 8);
}

/* ******************************************************************** */
/*                        SFEndianExchange32u()                         */
/* ******************************************************************** */
INT32U SFEndianExchange32u (INT32U uiData)
{   return ((uiData & (INT32U)0x000000FF) << 24) |
           ((uiData & (INT32U)0x0000FF00) <<  8) |
           ((uiData & (INT32U)0x00FF0000) >>  8) |
           ((uiData & (INT32U)0xFF000000) >> 24);
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
/*                          SFModGetParam()                             */
/* ******************************************************************** */
INT16U SFModGetParam (INT16U usBegin)
{   if (usBegin < DB_PARAM_SIZE)
    {   return DBGetParam16u(usBegin);
    }
    usBegin -= DB_PARAM_SIZE;
    if (usBegin < DB_FUNCT_SIZE)
    {   return DBGetFunct16u(usBegin);
    }
    usBegin -= DB_FUNCT_SIZE;
    if (usBegin < DB_CURVE_SIZE)
    {   return DBGetCurve16u(usBegin);
    }
    usBegin -= DB_CURVE_SIZE;
    return DBGetMeasu16u(usBegin);
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
/*                          SFModSetParam()                             */
/* ******************************************************************** */
INT08U SFModSetParam (INT16U usBegin, INT16U usValue)
{   if (usBegin < DB_PARAM_SIZE)
    {   return DBSetParam16u(usBegin, usValue);
    }
    usBegin -= DB_PARAM_SIZE;
    if (usBegin < DB_FUNCT_SIZE)
    {   return DBSetFunct16u(usBegin, usValue);
    }
    usBegin -= DB_FUNCT_SIZE;
    if (usBegin < DB_CURVE_SIZE)
    {   return DBSetCurve16u(usBegin, usValue);
    }
    usBegin -= DB_CURVE_SIZE;
    return DBSetMeasu16u(usBegin, usValue);
}

/* ******************************************************************** */
/*                          SFModSetParams()                            */
/* ******************************************************************** */
INT08U SFModSetParams (INT08U *pDat, INT16U usBegin, INT16U usSize)
{   if (usBegin < DB_PARAM_SIZE)
    {   return DBSetParam08p(pDat, usBegin, usSize);
    }
    usBegin -= DB_PARAM_SIZE;
    if (usBegin < DB_FUNCT_SIZE)
    {   return DBSetFunct08p(pDat, usBegin, usSize);
    }
    usBegin -= DB_FUNCT_SIZE;
    if (usBegin < DB_CURVE_SIZE)
    {   return DBSetCurve08p(pDat, usBegin, usSize);
    }
    usBegin -= DB_CURVE_SIZE;
    return DBSetMeasu08p(pDat, usBegin, usSize);
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
    if (usSize == 0)
    {   return 0;
    }
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
    if (usSize == 0)
    {   return 0;
    }
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
    ssMax = *pData;
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
    usMax   = *pData;
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
    if (usMin < ((usMax*2)/3))
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
    uiMax   = *pData;
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
    if (uiMin < ((uiMax*2)/3))
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
    uiOut  = uiSum / XIO_ADC_REF_FILTER;
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
/*                           SFNegate16s()                              */
/* ******************************************************************** */
void SFNegate16s (INT16S *pData, INT16U usSize)
{   INT16U usSiz;
    usSiz = usSize / 8;
    while (usSiz--)
    {   *pData = 0 - *pData;
        pData++;
        *pData = 0 - *pData;
        pData++;
        *pData = 0 - *pData;
        pData++;
        *pData = 0 - *pData;
        pData++;
        *pData = 0 - *pData;
        pData++;
        *pData = 0 - *pData;
        pData++;
        *pData = 0 - *pData;
        pData++;
        *pData = 0 - *pData;
        pData++;
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   *pData = 0 - *pData;
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
/*                            SFGetEffSum()                             */
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
    if (usSize == 0)
    {   return 0;
    }
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
            if ((++uiNum) > SF_ZERO_CROSS_MAX)
            {   break;
            }
        }
        siOld  = siNew;
        siNew  = (INT32S)(*pData++);
        uiTim += XIO_ADC_SMPL_TIM_US;
        if((siOld < 0) && (siNew >= 0))
        {   pZero->uiTold = pZero->uiTnew;
            pZero->uiTnew = SF_GET_CROSS_TIM(siOld,siNew) + uiTim;
            if ((++uiNum) > SF_ZERO_CROSS_MAX)
            {   break;
            }
        }
        siOld  = siNew;
        siNew  = (INT32S)(*pData++);
        uiTim += XIO_ADC_SMPL_TIM_US;
        if((siOld < 0) && (siNew >= 0))
        {   pZero->uiTold = pZero->uiTnew;
            pZero->uiTnew = SF_GET_CROSS_TIM(siOld,siNew) + uiTim;
            if ((++uiNum) > SF_ZERO_CROSS_MAX)
            {   break;
            }
        }
        siOld  = siNew;
        siNew  = (INT32S)(*pData++);
        uiTim += XIO_ADC_SMPL_TIM_US;
        if((siOld < 0) && (siNew >= 0))
        {   pZero->uiTold = pZero->uiTnew;
            pZero->uiTnew = SF_GET_CROSS_TIM(siOld,siNew) + uiTim;
            if ((++uiNum) > SF_ZERO_CROSS_MAX)
            {   break;
            }
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
            if ((++uiNum) > SF_ZERO_CROSS_MAX)
            {   break;
            }
        }
    }
    pZero->siDold = siNew;
    if (uiNum == 0)
    {   pZero->uiTlong += XIO_ADC_SMPL_PRD_US;
    }   else if (uiNum == 1)
    {   pZero->uiPrd    = pZero->uiTnew + pZero->uiTlong - pZero->uiTold;
        pZero->uiTlong  = XIO_ADC_SMPL_PRD_US;
    }   else if (uiNum <= SF_ZERO_CROSS_MAX)
    {   pZero->uiPrd    = pZero->uiTnew - pZero->uiTold;
        pZero->uiTlong  = XIO_ADC_SMPL_PRD_US;
    }   else
    {   pZero->uiPrd    = 0xFFFFFFFF;
        pZero->uiTlong  = XIO_ADC_SMPL_PRD_US;
    }
    uiTim = pZero->uiPrd;
    if ((uiTim != 0) && (uiNum != 0))
    {   pZero->usFreq   = (INT16U)((INT32U)100000000 / uiTim);
        pZero->usPhase  = (INT16U)(((pZero->uiTnew % uiTim) << 16) / uiTim);
    }
}

/* ******************************************************************** */
/*                           SFSoftFreqInit()                           */
/* ******************************************************************** */
void SFSoftFreqInit (SF_SOFT_FREQ_STR *pSoft, INT16U usFilt)
{   pSoft->usFreq  = 0;
    pSoft->usPhase = 0;
    pSoft->siDSum  = 0;
    pSoft->siDOld  = 0;
    pSoft->uiTOld  = 0;
    pSoft->uiTNew  = 0;
    pSoft->uiTPrd  = 0xFFFFFFFF;
    pSoft->uiTLng  = XIO_ADC_SMPL_PRD_US;
    pSoft->uiFilt  = usFilt > 0 ? usFilt : 8;
}

/* ******************************************************************** */
/*                           SFSoftFreqRefresh()                        */
/* ******************************************************************** */
void SFSoftFreqRefresh (INT16S *pSour, SF_SOFT_FREQ_STR *pSoft, INT16U usSize)
{   INT32S siSum, siFlt, siOld, siNew;
    INT32U uiTim, uiNum, uiSiz;
    uiTim = 0;
    uiNum = 0;
    siOld = 0;
    siNew = pSoft->siDOld;
    siSum = pSoft->siDSum;
    siFlt = pSoft->uiFilt;
    uiSiz = usSize / 4;
    while (uiSiz--)
    {   uiTim +=  XIO_ADC_SMPL_TIM_US;
        siSum += (INT32S)(*pSour++);
        siSum -=  siNew;
        siOld  =  siNew;
        siNew  =  siSum / siFlt;
        if((siOld < 0) && (siNew >= 0))
        {   pSoft->uiTOld = pSoft->uiTNew;
            pSoft->uiTNew = SF_GET_CROSS_TIM(siOld,siNew) + uiTim;
            if ((++uiNum) > SF_ZERO_CROSS_MAX)
            {   break;
            }
        }
        uiTim +=  XIO_ADC_SMPL_TIM_US;
        siSum += (INT32S)(*pSour++);
        siSum -=  siNew;
        siOld  =  siNew;
        siNew  =  siSum / siFlt;
        if((siOld < 0) && (siNew >= 0))
        {   pSoft->uiTOld = pSoft->uiTNew;
            pSoft->uiTNew = SF_GET_CROSS_TIM(siOld,siNew) + uiTim;
            if ((++uiNum) > SF_ZERO_CROSS_MAX)
            {   break;
            }
        }
        uiTim +=  XIO_ADC_SMPL_TIM_US;
        siSum += (INT32S)(*pSour++);
        siSum -=  siNew;
        siOld  =  siNew;
        siNew  =  siSum / siFlt;
        if((siOld < 0) && (siNew >= 0))
        {   pSoft->uiTOld = pSoft->uiTNew;
            pSoft->uiTNew = SF_GET_CROSS_TIM(siOld,siNew) + uiTim;
            if ((++uiNum) > SF_ZERO_CROSS_MAX)
            {   break;
            }
        }
        uiTim +=  XIO_ADC_SMPL_TIM_US;
        siSum += (INT32S)(*pSour++);
        siSum -=  siNew;
        siOld  =  siNew;
        siNew  =  siSum / siFlt;
        if((siOld < 0) && (siNew >= 0))
        {   pSoft->uiTOld = pSoft->uiTNew;
            pSoft->uiTNew = SF_GET_CROSS_TIM(siOld,siNew) + uiTim;
            if ((++uiNum) > SF_ZERO_CROSS_MAX)
            {   break;
            }
        }
    }
    uiSiz = usSize % 4;
    while (uiSiz--)
    {   uiTim +=  XIO_ADC_SMPL_TIM_US;
        siSum += (INT32S)(*pSour++);
        siSum -=  siNew;
        siOld  =  siNew;
        siNew  =  siSum / siFlt;
        if((siOld < 0) && (siNew >= 0))
        {   pSoft->uiTOld = pSoft->uiTNew;
            pSoft->uiTNew = SF_GET_CROSS_TIM(siOld,siNew) + uiTim;
            if ((++uiNum) > SF_ZERO_CROSS_MAX)
            {   break;
            }
        }
    }
    pSoft->siDOld = siNew;
    pSoft->siDSum = siSum;
    if (uiNum == 0)
    {   pSoft->uiTLng  += XIO_ADC_SMPL_PRD_US;
    }   else if (uiNum == 1)
    {   pSoft->uiTPrd   = pSoft->uiTNew + pSoft->uiTLng - pSoft->uiTOld;
        pSoft->uiTLng   = XIO_ADC_SMPL_PRD_US;
    }   else if (uiNum <= SF_ZERO_CROSS_MAX)
    {   pSoft->uiTPrd   = pSoft->uiTNew - pSoft->uiTOld;
        pSoft->uiTLng   = XIO_ADC_SMPL_PRD_US;
    }   else
    {   pSoft->uiTPrd   = 0xFFFFFFFF;
        pSoft->uiTLng   = XIO_ADC_SMPL_PRD_US;
    }
    uiTim = pSoft->uiTPrd;
    if ((uiTim != 0) && (uiNum != 0))
    {   pSoft->usFreq   = (INT16U)((INT32U)100000000 / uiTim);
        pSoft->usPhase  = (INT16U)(((pSoft->uiTNew % uiTim) << 16) / uiTim);
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
/* ******************************************************************** */
INT16U SFGet1DMapCst10 (INT16U usX, const INT16U *pXX, const INT16U *pYY)
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
/*                            SFHardFreqInit()                          */
/* ******************************************************************** */
void SFHardFreqInit (SF_HARD_FREQ_STR *pHard)
{   INT16U i;
    pHard->usTime  = 0;
    pHard->usTick  = usFW5msTimer;
    pHard->usFreq  = 0;
    pHard->usCount = SF_HARD_PRD_DAT_SIZ;
    pHard->pPeriod = &pHard->uiPeriod[SF_HARD_PRD_DAT_SIZ-1];
    for (i=0; i<SF_HARD_PRD_DAT_SIZ; i++)
    {   pHard->uiPeriod[i] = 0xFFFFFFFF;
    }
}

/* ******************************************************************** */
/*                          SFHardFreqRefresh()                         */
/* ******************************************************************** */
void SFHardFreqRefresh (SF_HARD_FREQ_STR *pHard)
{   INT16U usTemp;
    usTemp = usFW5msTimer - pHard->usTick;
    if (usTemp > SF_HARD_PRD_RST_TICK)
    {   pHard->usCount = SF_HARD_PRD_DAT_SIZ;
    }
}

/* ******************************************************************** */
/*                         SFHardFreqPutTime()                          */
/* ******************************************************************** */
void SFHardFreqPutTime (INT16U usTime, SF_HARD_FREQ_STR *pHard)
{   INT16U usTemp, usTicks;
    INT32U uiPeriod;
    usTemp        = usTime - pHard->usTime;
    pHard->usTime = usTime;
    usTicks       = usFW5msTimer - pHard->usTick;
    pHard->usTick = usFW5msTimer;
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
/*                          SFHardFreqGetFreq()                         */
/* ******************************************************************** */
INT16U SFHardFreqGetFreq (SF_HARD_FREQ_STR *pHard)
{   return pHard->usFreq;
}

/* ******************************************************************** */
/*                          SFHardFreqGetFreq()                         */
/* ******************************************************************** */
INT32U SFHardFreqGetPeriod (SF_HARD_FREQ_STR *pHard)
{   return *(pHard->pPeriod);
}

/* ******************************************************************** */
/*                        SFHardFreqCheckPeriod()                       */
/* ******************************************************************** */
INT08U SFHardFreqCheckPeriod (SF_HARD_FREQ_STR *pHard)
{   if (pHard->usCount != 0)
    {   return SF_FALSE;
    }
    return SFCheckMinMax32u(&pHard->uiPeriod[0], SF_HARD_PRD_DAT_SIZ);
}

/* ******************************************************************** */
/*                         SFHardFreqGetPhsDiff()                       */
/* ******************************************************************** */
INT16S SFHardFreqGetPhsDiff (SF_HARD_FREQ_STR *pHard0, SF_HARD_FREQ_STR *pHard1)
{   INT16S ssTemp;
    INT32U uiPrd;
    uiPrd  = (*(pHard0->pPeriod) + *(pHard1->pPeriod)) / 2;
    ssTemp = pHard1->usTime - pHard0->usTime;
    if (uiPrd == 0)
    {   return 0;
    }
    return (INT16S)((((INT32S)ssTemp) << 16) / uiPrd);
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
    usTemp = usFW5msTimer - pSpd->usTick;
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
    usTicks       = (INT16U)(usFW5msTimer - pSpd->usTick);
    pSpd->usTick  = usFW5msTimer;
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
/*                          SFGetErrorPidCtrl()                         */
/* ******************************************************************** */
INT16S SFGetErrorPidCtrl (INT16S ssError, PID16S_PAR_STR *pPara)
{   INT32S siCtrl;
    INT16S ssErr;
    siCtrl = pPara->siCtrlOld;
    ssErr  = ssError;
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
    ssErr = ssError - pPara->ssInputOld;
    pPara->ssInputOld = ssError;
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
    usTemp = usFW5msTimer - pDelay->usTimer;
    if (pDelay->usState == 0)
    {   if (usSwitch == 0)
        {   pDelay->usTimer = usFW5msTimer;
        }
        else if (usTemp >= pDelay->usDelayOn)
        {   pDelay->usTimer = usFW5msTimer;
            pDelay->usState = 1;
        }
    }
    else if (usSwitch != 0)
    {   pDelay->usTimer = usFW5msTimer;
    }
    else if (usTemp >= pDelay->usDelayOff)
    {   pDelay->usTimer = usFW5msTimer;
        pDelay->usState = 0;
    }
    return pDelay->usState;
}

/* ******************************************************************** */
/*                         SFResetSwitchDelay()                         */
/* ******************************************************************** */
void SFResetSwitchDelay (SWITCH_DELAY_STR *pDelay)
{   pDelay->usTimer = usFW5msTimer;
    pDelay->usState = 0;
}

/* ******************************************************************** */
/*                         SFI2tTimeOverInit()                          */
/* ******************************************************************** */
void SFI2tTimeOverInit (INT16U usRated, INT16U usTover,
                        INT16U usFreq,  SF_I2T_TIM_STR *pInver)
{   pInver->uiI2tRated = (INT32U)usRated * (INT32U)usRated;
    pInver->llI2tSum64 = 0;
    pInver->llI2tMax64 = (INT64U)usRated * (INT64U)usRated * (INT64U)usTover *
                         (INT64U)usFreq * (INT64U)3 / (INT64U)10;
}

/* ******************************************************************** */
/*                        SFI2tTimeOverCheck()                          */
/* ******************************************************************** */
INT16U SFI2tTimeOverCheck (INT16U usInput, SF_I2T_TIM_STR *pInver)
{   INT32U uiTemp;
    uiTemp = (INT32U)usInput * (INT32U)usInput;
    if (uiTemp >= pInver->uiI2tRated)
    {   uiTemp -= pInver->uiI2tRated;
        pInver->llI2tSum64 += (INT64U)uiTemp;
    }
    else
    {   uiTemp  = pInver->uiI2tRated - uiTemp;
        if (pInver->llI2tSum64 >= (INT64U)uiTemp)
        {   pInver->llI2tSum64 -= (INT64U)uiTemp;
        }   else
        {   pInver->llI2tSum64  = 0;
        }
    }
    if (pInver->llI2tSum64 >= pInver->llI2tMax64)
    {   return 1;
    }
    return 0;
}

/* ******************************************************************** */
/*                        SFGetReactPwrOfAct()                          */
/* ******************************************************************** */
INT16U SFGetReactPwrOfAct (INT16U usActPwr, INT16U usFactor)
{   INT32U uiTemp;
    if (usFactor >= 1000)
    {   return 0;
    }
    uiTemp = SFSqrt32u((INT32U)1000000-(INT32U)(usFactor*usFactor));
    return (INT16U)((INT32U)usActPwr * (INT32U)usFactor / uiTemp);
}

/* ******************************************************************** */
/*                          SFGetCpuTemp()                              */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
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
#endif

/* ******************************************************************** */
/*                          SFGetSensorTemp()                           */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
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
    {   return SFGet1DMap10(usAdc, &aDBcTempMapAdc[0], &aDBcTempMapTmp[0]);
    }
}
#endif

/* ******************************************************************** */
/*                          SFGetSensorPres()                          */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT16U SFGetSensorPres (INT16U usAdc, INT16U usType)
{   if (usType == 0)
    {   return SFGet1DMapCst10(usAdc, &aSFPressMap0Adc[0], &aSFPressMap0Prs[0]);
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
    {   return SFGet1DMap10(usAdc, &aDBcPressMapAdc[0], &aDBcPressMapPrs[0]);
    }
}
#endif

/* ******************************************************************** */
/*                          SFGetSensorLevel()                          */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
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
    {   return SFGet1DMap10(usAdc, &aDBcLevelMapAdc[0], &aDBcLevelMapLvl[0]);
    }
}
#endif

/* ******************************************************************** */
/*                             SFGetAccKwh()                            */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT32U SFGetAccKwh (INT16U usPower)
{   static INT32U uiSum = 0;
    INT32U uiAcc = 0;
    uiSum += (INT32U)usPower;
    uiAcc  =  uiSum / SF_ACC_KWH_CONST;
    uiSum  =  uiSum % SF_ACC_KWH_CONST;
    return uiAcc;
}
#endif

/* ******************************************************************** */
/*                            SFGetAccKvarh()                           */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT32U SFGetAccKvarh (INT16U usPower)
{   static INT32U uiSum = 0;
    INT32U uiAcc = 0;
    uiSum += (INT32U)usPower;
    uiAcc  =  uiSum / SF_ACC_KVARH_CONST;
    uiSum  =  uiSum % SF_ACC_KVARH_CONST;
    return uiAcc;
}
#endif

/* ******************************************************************** */
/*                          SFGetAccRunTime()                           */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT32U SFGetAccRunTime (INT16U usRunning)
{   static INT32U uiSum = 0;
    if (usRunning != 0)
    {   if ((++uiSum) >= SF_ACC_RUNTIM_CONST)
        {   uiSum = 0;
            return (INT32U)1;
        }
    }
    return (INT32U)0;
}
#endif

/* ******************************************************************** */
/*                          SFUpdataStatistics()                        */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT08U SFUpdataStatistics (INT16U usSpeed, INT16U usPower)
{   static INT16U usTimer1 = 0;
    INT16U usD0, usD1;
    usD0 = usFW100msTimer - usTimer1;
    if (usDBmEngEngineIsRunning == 0)
    {   usTimer1 = usFW100msTimer;
        return SF_FALSE;
    }
    else if (usD0 >= usDBpTimeOfStatistics)
    {   usTimer1 = usFW100msTimer;
        for (usD0=0; usD0<9; usD0++)
        {   if (usSpeed <= aDBcStatisticSpeed[usD0]) break;
        }
        for (usD1=0; usD1<9; usD1++)
        {   if (usPower <= aDBcStatisticPower[usD1]) break;
        }
        aDBhStatisticData[usD0*10+usD1] += 1;
        return SF_TRUE;
    }
    return SF_FALSE;
}
#endif

/* ******************************************************************** */
/*                          SFCheckToSaveHstry()                        */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFCheckToSaveHstry (void)
{   static INT32U uiSum = 0;
    if ((++uiSum) >= SF_SAVE_HSTRY_TIME)
    {   uiSum              = 0;
        uiDBhErrorStatus1 |= uiDBmErrorStatus1;
        uiDBhErrorStatus2 |= uiDBmErrorStatus2;
        uiDBhErrorStatus3 |= uiDBmErrorStatus3;
        uiDBhErrorStatus4 |= uiDBmErrorStatus4;
        uiDBhErrorStatus5 |= uiDBmErrorStatus5;
        uiDBhErrorStatus6 |= uiDBmErrorStatus6;
        uiDBhErrorStatus7 |= uiDBmErrorStatus7;
        uiDBhErrorStatus8 |= uiDBmErrorStatus8;
        DBTskPutCmd(DB_CMD_SAVE_HSTRY);
    }
}
#endif

/* ******************************************************************** */
/*                          SFUpdateAnalogStatus()                      */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFUpdateAnalogStatus (INT16U *pAin)
{   INT16U usTmp;
    /* ************************* Battary Voltage ********************** */
    usTmp = pAin[SF_BATT1_VOLT_CH];
    usDBmAinBatt1Voltage = SF_GET_BATT_VOLT(usTmp);
    usTmp = pAin[SF_BATT2_VOLT_CH];
    usDBmAinBatt2Voltage = SF_GET_BATT_VOLT(usTmp);
    usTmp = pAin[SF_CHARG_VOLT_CH];
    usDBmAinChargVoltage = SF_GET_CHARG_VOLT(usTmp);
    /* ************************* Intern Temperature ******************* */
    usTmp = pAin[SF_CPU_TMP_CH];
    usDBmAinInternTemp   = SFGetCpuTemp(usTmp);
    /* *********************** Coolant Temperature ******************** */
    usTmp = usDBpAinCoolTempAssign;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpAinCoolTempErrLow) ||
            (usTmp > usDBpAinCoolTempErrHigh))
        {   usDBmAinCoolantTemp = usDBpAinCoolTempSubst;
            if (usDBfAinCoolTempSenErrAct == 0)
            {   ERR_ES6_SET_BIT(ERR_ES6_WRN_SEN_T_COOL);
            }   else if (usDBfAinCoolTempSenErrAct == 1)
            {   ERR_ES6_SET_BIT(ERR_ES6_STP_SEN_T_COOL);
            }
        }   else
        {   usDBmAinCoolantTemp = SFGetSensorTemp(usTmp, usDBpAinCoolTempSenType);
            if (usDBfAinCoolTempSenErrAct == 0)
            {   ERR_ES6_CLR_BIT(ERR_ES6_WRN_SEN_T_COOL);
            }
        }
    }   else
    {   usDBmAinCoolantTemp = usDBpAinCoolTempSubst;
        ERR_ES6_CLR_BIT(ERR_ES6_STP_SEN_T_COOL | ERR_ES6_WRN_SEN_T_COOL);
    }
    /* *********************** Oil Temperature ************************ */
    usTmp = usDBpAinOilTempAssign;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpAinOilTempErrLow) ||
            (usTmp > usDBpAinOilTempErrHigh))
        {   usDBmAinOilTemp = usDBpAinOilTempSubst;
            if (usDBfAinOilTempSenErrAct == 0)
            {   ERR_ES6_SET_BIT(ERR_ES6_WRN_SEN_T_OIL);
            }   else if (usDBfAinOilTempSenErrAct == 1)
            {   ERR_ES6_SET_BIT(ERR_ES6_STP_SEN_T_OIL);
            }
        }   else
        {   usDBmAinOilTemp = SFGetSensorTemp(usTmp, usDBpAinOilTempSenType);
            if (usDBfAinOilTempSenErrAct == 0)
            {   ERR_ES6_CLR_BIT(ERR_ES6_WRN_SEN_T_OIL);
            }
        }
    }   else
    {   usDBmAinOilTemp = usDBpAinOilTempSubst;
        ERR_ES6_CLR_BIT(ERR_ES6_STP_SEN_T_OIL | ERR_ES6_WRN_SEN_T_OIL);
    }
    /* *********************** Oil Pressure *************************** */
    usTmp = usDBpAinOilPresAssign;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpAinOilPresErrLow) ||
            (usTmp > usDBpAinOilPresErrHigh))
        {   usDBmAinOilPres = usDBpAinOilPresSubst;
            if (usDBfAinOilPresSenErrAct == 0)
            {   ERR_ES6_SET_BIT(ERR_ES6_WRN_SEN_P_OIL);
            }   else if (usDBfAinOilPresSenErrAct == 1)
            {   ERR_ES6_SET_BIT(ERR_ES6_STP_SEN_P_OIL);
            }
        }   else
        {   usDBmAinOilPres = SFGetSensorPres(usTmp, usDBpAinOilPresSenType);
            if (usDBfAinOilPresSenErrAct == 0)
            {   ERR_ES6_CLR_BIT(ERR_ES6_WRN_SEN_P_OIL);
            }
        }
    }   else
    {   usDBmAinOilPres = usDBpAinOilPresSubst;
        ERR_ES6_CLR_BIT(ERR_ES6_STP_SEN_P_OIL | ERR_ES6_WRN_SEN_P_OIL);
    }
    /* ************************* Fuel Level *************************** */
    usTmp = usDBpAinFuelLevelAssign;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpAinFuelLevelErrLow) ||
            (usTmp > usDBpAinFuelLevelErrHigh))
        {   usDBmAinFuelLevel = usDBpAinFuelLevelSubst;
            if (usDBfAinFuelLevelSenErrAct == 0)
            {   ERR_ES6_SET_BIT(ERR_ES6_WRN_SEN_L_FUEL);
            }   else if (usDBfAinFuelLevelSenErrAct == 1)
            {   ERR_ES6_SET_BIT(ERR_ES6_STP_SEN_L_FUEL);
            }
        }   else
        {   usDBmAinFuelLevel = SFGetSensorLevel(usTmp, usDBpAinFuelLevelSenType);
            if (usDBfAinFuelLevelSenErrAct == 0)
            {   ERR_ES6_CLR_BIT(ERR_ES6_WRN_SEN_L_FUEL);
            }
        }
    }   else
    {   usDBmAinFuelLevel = usDBpAinFuelLevelSubst;
        ERR_ES6_CLR_BIT(ERR_ES6_STP_SEN_L_FUEL | ERR_ES6_WRN_SEN_L_FUEL);
    }
    /* ************************* Coolant Level ************************ */
    usTmp = usDBpAinCoolLevelAssign;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpAinCoolLevelErrLow) ||
            (usTmp > usDBpAinCoolLevelErrHigh))
        {   usDBmAinCoolantLevel = usDBpAinCoolLevelSubst;
            if (usDBfAinCoolLevelSenErrAct == 0)
            {   ERR_ES6_SET_BIT(ERR_ES6_WRN_SEN_L_COOL);
            }   else if (usDBfAinCoolLevelSenErrAct == 1)
            {   ERR_ES6_SET_BIT(ERR_ES6_STP_SEN_L_COOL);
            }
        }   else
        {   usDBmAinCoolantLevel = SFGetSensorLevel(usTmp, usDBpAinCoolLevelSenType);
            if (usDBfAinCoolLevelSenErrAct == 0)
            {   ERR_ES6_CLR_BIT(ERR_ES6_WRN_SEN_L_COOL);
            }
        }
    }   else
    {   usDBmAinCoolantLevel = usDBpAinCoolLevelSubst;
        ERR_ES6_CLR_BIT(ERR_ES6_STP_SEN_L_COOL | ERR_ES6_WRN_SEN_L_COOL);
    }
    /* ************************* Charger Current ********************** */
    usTmp = usDBpAinChargCurrAssign;
    if (usTmp < SF_NUM_OF_ANA_IN)
    {   usTmp = pAin[usTmp];
        if ((usTmp < usDBpAinChargCurrErrLow) ||
            (usTmp > usDBpAinChargCurrErrHigh))
        {   usDBmAinChargCurrent = usDBpAinChargCurrSubst;
            if (usDBfAinChargCurrSenErrAct == 0)
            {   ERR_ES6_SET_BIT(ERR_ES6_WRN_SEN_C_CHARG);
            }   else if (usDBfAinChargCurrSenErrAct == 1)
            {   ERR_ES6_SET_BIT(ERR_ES6_STP_SEN_C_CHARG);
            }
        }   else
        {   usDBmAinChargCurrent = SFInterp16u (usTmp, usDBpAinChargCurrAdcLow,
            usDBpAinChargCurrAdcHigh, usDBpAinChargCurrRefLow, usDBpAinChargCurrRefHigh);
            if (usDBfAinChargCurrSenErrAct == 0)
            {   ERR_ES6_CLR_BIT(ERR_ES6_WRN_SEN_C_CHARG);
            }
        }
    }   else
    {   usDBmAinChargCurrent = usDBpAinChargCurrSubst;
        ERR_ES6_CLR_BIT(ERR_ES6_STP_SEN_C_CHARG | ERR_ES6_WRN_SEN_C_CHARG);
    }
}
#endif

/* ******************************************************************** */
/*                         SFUpdateSwitchesStatus()                     */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFUpdateSwitchesStatus (INT32U uiInput)
{   INT16U usTmp;
    /* ************************ SwitchEngineStop ********************** */
    usTmp = usDBpDinAssigEngineStop;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchEngineStop =  usDBfDinPoleEngineStop;
    }   else if (usDBfDinPoleEngineStop != 0)
    {   usDBmSwitchEngineStop = (INT16U)((uiInput >> usTmp) & 1);
    }   else
    {   usDBmSwitchEngineStop = (INT16U)((~uiInput >> usTmp) & 1);
    }
    /* ************************ SwitchEngineStart ********************* */
    usTmp = usDBpDinAssigEngineStart;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchEngineStart =  usDBfDinPoleEngineStart;
    }   else if (usDBfDinPoleEngineStart != 0)
    {   usDBmSwitchEngineStart = (INT16U)((uiInput >> usTmp) & 1);
    }   else
    {   usDBmSwitchEngineStart = (INT16U)((~uiInput >> usTmp) & 1);
    }
    /* ************************ SwitchOilPump ************************* */
    usTmp = usDBpDinAssigOilPump;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchOilPump =  usDBfDinPoleOilPump;
    }   else if (usDBfDinPoleOilPump != 0)
    {   usDBmSwitchOilPump = (INT16U)((uiInput >> usTmp) & 1);
    }   else
    {   usDBmSwitchOilPump = (INT16U)((~uiInput >> usTmp) & 1);
    }
    /* ************************ SwitchHeater ************************** */
    usTmp = usDBpDinAssigHeater;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchHeater =  usDBfDinPoleHeater;
    }   else if (usDBfDinPoleHeater != 0)
    {   usDBmSwitchHeater = (INT16U)((uiInput >> usTmp) & 1);
    }   else
    {   usDBmSwitchHeater = (INT16U)((~uiInput >> usTmp) & 1);
    }
    /* ************************ SwitchMainFeedback ******************** */
    usTmp = usDBpDinAssigMainFeedback;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchMainFeedback =  usDBfDinPoleMainFeedback;
    }   else if (usDBfDinPoleMainFeedback != 0)
    {   usDBmSwitchMainFeedback = (INT16U)((uiInput >> usTmp) & 1);
    }   else
    {   usDBmSwitchMainFeedback = (INT16U)((~uiInput >> usTmp) & 1);
    }
    /* ************************ SwitchGensFeedback ******************** */
    usTmp = usDBpDinAssigGensFeedback;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchGensFeedback =  usDBfDinPoleGensFeedback;
    }   else if (usDBfDinPoleGensFeedback != 0)
    {   usDBmSwitchGensFeedback = (INT16U)((uiInput >> usTmp) & 1);
    }   else
    {   usDBmSwitchGensFeedback = (INT16U)((~uiInput >> usTmp) & 1);
    }
    /* ************************ SwitchParamLock *********************** */
    usTmp = usDBpDinAssigOilTemp;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchOilTemp =  usDBfDinPoleOilTemp;
    }   else if (usDBfDinPoleOilTemp != 0)
    {   usDBmSwitchOilTemp = (INT16U)((uiInput >> usTmp) & 1);
    }   else
    {   usDBmSwitchOilTemp = (INT16U)((~uiInput >> usTmp) & 1);
    }
    /* ************************ SwitchFuelLevel *********************** */
    usTmp = usDBpDinAssigFuelLevel;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchFuelLevel =  usDBfDinPoleFuelLevel;
    }   else if (usDBfDinPoleFuelLevel != 0)
    {   usDBmSwitchFuelLevel = (INT16U)((uiInput >> usTmp) & 1);
    }   else
    {   usDBmSwitchFuelLevel = (INT16U)((~uiInput >> usTmp) & 1);
    }
    /* ************************ SwitchOilPressure ********************* */
    usTmp = usDBpDinAssigOilPressure;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchOilPressure =  usDBfDinPoleOilPressure;
    }   else if (usDBfDinPoleOilPressure != 0)
    {   usDBmSwitchOilPressure = (INT16U)((uiInput >> usTmp) & 1);
    }   else
    {   usDBmSwitchOilPressure = (INT16U)((~uiInput >> usTmp) & 1);
    }
    /* ************************ SwitchCoolantTemp ********************* */
    usTmp = usDBpDinAssigCoolantTemp;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchCoolantTemp =  usDBfDinPoleCoolantTemp;
    }   else if (usDBfDinPoleCoolantTemp != 0)
    {   usDBmSwitchCoolantTemp = (INT16U)((uiInput >> usTmp) & 1);
    }   else
    {   usDBmSwitchCoolantTemp = (INT16U)((~uiInput >> usTmp) & 1);
    }
    /* ************************ SwitchCoolantLevel ******************** */
    usTmp = usDBpDinAssigCoolantLevel;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchCoolantLevel =  usDBfDinPoleCoolantLevel;
    }   else if (usDBfDinPoleCoolantLevel != 0)
    {   usDBmSwitchCoolantLevel = (INT16U)((uiInput >> usTmp) & 1);
    }   else
    {   usDBmSwitchCoolantLevel = (INT16U)((~uiInput >> usTmp) & 1);
    }
    /* ************************ SwitchAirFilter *********************** */
    usTmp = usDBpDinAssigAirFilter;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchAirFilter =  usDBfDinPoleAirFilter;
    }   else if (usDBfDinPoleAirFilter != 0)
    {   usDBmSwitchAirFilter = (INT16U)((uiInput >> usTmp) & 1);
    }   else
    {   usDBmSwitchAirFilter = (INT16U)((~uiInput >> usTmp) & 1);
    }
    /* ************************ SwitchEmergStop *********************** */
    usTmp = usDBpDinAssigEmergStop;
    if (usTmp >= SF_NUM_OF_SW_IN)
    {   usDBmSwitchEmergStop =  usDBfDinPoleEmergStop;
    }   else if (usDBfDinPoleEmergStop != 0)
    {   usDBmSwitchEmergStop = (INT16U)((uiInput >> usTmp) & 1);
    }   else
    {   usDBmSwitchEmergStop = (INT16U)((~uiInput >> usTmp) & 1);
    }
}
#endif

/* ******************************************************************** */
/*                         SFUpdateBoardKeyStatus()                     */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFUpdateBoardKeyStatus (INT32U uiInput)
{   usDBmKeyMenuUp      = (INT16U)((uiInput >> SF_KEY_BIT_MENU_UP) & 1);
    usDBmKeyMenuDown    = (INT16U)((uiInput >> SF_KEY_BIT_MENU_DOWN) & 1);
    usDBmKeyMenuRight   = (INT16U)((uiInput >> SF_KEY_BIT_MENU_RIGHT) & 1);
    usDBmKeyMenuLeft    = (INT16U)((uiInput >> SF_KEY_BIT_MENU_LEFT) & 1);
    usDBmKeyMenuEnter   = (INT16U)((uiInput >> SF_KEY_BIT_MENU_ENTER) & 1);
    usDBmKeyOBD         = (INT16U)((uiInput >> SF_KEY_BIT_OBD) & 1);
    usDBmKeyEngineStop  = (INT16U)((uiInput >> SF_KEY_BIT_ENG_STOP) & 1);
    usDBmKeyEngineStart = (INT16U)((uiInput >> SF_KEY_BIT_ENG_START) & 1);
    usDBmKeyModeAuto    = (INT16U)((uiInput >> SF_KEY_BIT_MODE_AUTO) & 1);
    usDBmKeyModeManual  = (INT16U)((uiInput >> SF_KEY_BIT_MODE_MANUAL) & 1);
    usDBmKeyErrorReset  = (INT16U)((uiInput >> SF_KEY_BIT_ERROR_RESET) & 1);
    usDBmKeySwitchOn    = (INT16U)((uiInput >> SF_KEY_BIT_SWITCH_ON) & 1);
    usDBmKeySwitchOff   = (INT16U)((uiInput >> SF_KEY_BIT_SWITCH_OFF) & 1);
    usDBmKeyBeeperOff   = (INT16U)((uiInput >> SF_KEY_BIT_BEEPER) & 1);
}
#endif

/* ******************************************************************** */
/*                            SFResetAllErrors()                        */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFResetAllErrors (void)
{   uiDBmErrorStatus1 = 0;
    uiDBmErrorStatus2 = 0;
    uiDBmErrorStatus3 = 0;
    uiDBmErrorStatus4 = 0;
    uiDBmErrorStatus5 = 0;
    uiDBmErrorStatus6 = 0;
    uiDBmErrorStatus7 = 0;
    uiDBmErrorStatus8 = 0;
    uiDBhErrorStatus1 = 0;
    uiDBhErrorStatus2 = 0;
    uiDBhErrorStatus3 = 0;
    uiDBhErrorStatus4 = 0;
    uiDBhErrorStatus5 = 0;
    uiDBhErrorStatus6 = 0;
    uiDBhErrorStatus7 = 0;
    uiDBhErrorStatus8 = 0;
    usDBmEngStartFailTimes = 0;
}
#endif

/* ******************************************************************** */
/*                            SFResetOneError()                         */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFResetOneError (void)
{   INT16U usMsk, usSts;
    if (ERR_ES5_GET_BIT(ERR_ES5_STP_START_FAIL) != 0)
    {   ERR_ES5_CLR_BIT(ERR_ES5_STP_START_FAIL);
        usDBmEngStartFailTimes = 0;
        return;
    }
    usSts = usDBmErrorStatus1;
    if (usSts != 0)
    {   for (usMsk = 0x8000; usMsk != 0; usMsk >>= 1)
        {   if ((usSts & usMsk) != 0)
            {   usDBmErrorStatus1 &= ~usMsk;
                return;
            }
        }
    }
    usSts = usDBmErrorStatus3;
    if (usSts != 0)
    {   for (usMsk = 0x8000; usMsk != 0; usMsk >>= 1)
        {   if ((usSts & usMsk) != 0)
            {   usDBmErrorStatus3 &= ~usMsk;
                return;
            }
        }
    }
    usSts = usDBmErrorStatus5;
    if (usSts != 0)
    {   for (usMsk = 0x8000; usMsk != 0; usMsk >>= 1)
        {   if ((usSts & usMsk) != 0)
            {   usDBmErrorStatus5 &= ~usMsk;
                return;
            }
        }
    }
    usSts = usDBmErrorStatus7;
    if (usSts != 0)
    {   for (usMsk = 0x8000; usMsk != 0; usMsk >>= 1)
        {   if ((usSts & usMsk) != 0)
            {   usDBmErrorStatus7 &= ~usMsk;
                return;
            }
        }
    }
    usSts = usDBmErrorStatus9;
    if (usSts != 0)
    {   for (usMsk = 0x8000; usMsk != 0; usMsk >>= 1)
        {   if ((usSts & usMsk) != 0)
            {   usDBmErrorStatus9 &= ~usMsk;
                return;
            }
        }
    }
    usSts = usDBmErrorStatus11;
    if (usSts != 0)
    {   for (usMsk = 0x8000; usMsk != 0; usMsk >>= 1)
        {   if ((usSts & usMsk) != 0)
            {   usDBmErrorStatus11 &= ~usMsk;
                return;
            }
        }
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorMainVolt()                         */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorMainVolt (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    static INT16U usTimer4 = 0;
    static INT16U usTimer5 = 0;
    static INT16U usTimer6 = 0;
    INT16U usVolt, usHigh, usLow, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpMainVoltErrDly;
    usLow    = usDBpMainVoltErrLow;
    usHigh   = usDBpMainVoltErrHigh;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_VA_LOW | ERR_ES1_WRN_MAIN_VA_HGH |
                        ERR_ES1_WRN_MAIN_VB_LOW | ERR_ES1_WRN_MAIN_VB_HGH |
                        ERR_ES1_WRN_MAIN_VC_LOW | ERR_ES1_WRN_MAIN_VC_HGH );
        usTimer1 = usTimNow;
        usTimer2 = usTimNow;
        usTimer3 = usTimNow;
        usTimer4 = usTimNow;
        usTimer5 = usTimNow;
        usTimer6 = usTimNow;
    }
    else if (usDBfMainVoltErrAct == 0)
    {   usVolt = usDBmMainVoltA;
        if (ERR_ES1_GET_BIT(ERR_ES1_WRN_MAIN_VA_LOW) == 0)
        {   if (usVolt >= usLow)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES1_SET_BIT(ERR_ES1_WRN_MAIN_VA_LOW);
                usTimer1 = usTimNow;
            }
        }
        else if (usVolt < usLow)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_VA_LOW);
            usTimer1 = usTimNow;
        }
        if (ERR_ES1_GET_BIT(ERR_ES1_WRN_MAIN_VA_HGH) == 0)
        {   if (usVolt < usHigh)
            {   usTimer2 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
            {   ERR_ES1_SET_BIT(ERR_ES1_WRN_MAIN_VA_HGH);
                usTimer2 = usTimNow;
            }
        }
        else if (usVolt >= usHigh)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
        {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_VA_HGH);
            usTimer2 = usTimNow;
        }
        usVolt = usDBmMainVoltB;
        if (ERR_ES1_GET_BIT(ERR_ES1_WRN_MAIN_VB_LOW) == 0)
        {   if (usVolt >= usLow)
            {   usTimer3 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer3) > usErrDly)
            {   ERR_ES1_SET_BIT(ERR_ES1_WRN_MAIN_VB_LOW);
                usTimer3 = usTimNow;
            }
        }
        else if (usVolt < usLow)
        {   usTimer3 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer3) > usErrDly)
        {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_VB_LOW);
            usTimer3 = usTimNow;
        }
        if (ERR_ES1_GET_BIT(ERR_ES1_WRN_MAIN_VB_HGH) == 0)
        {   if (usVolt < usHigh)
            {   usTimer4 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer4) > usErrDly)
            {   ERR_ES1_SET_BIT(ERR_ES1_WRN_MAIN_VB_HGH);
                usTimer4 = usTimNow;
            }
        }
        else if (usVolt >= usHigh)
        {   usTimer4 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer4) > usErrDly)
        {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_VB_HGH);
            usTimer4 = usTimNow;
        }
        usVolt = usDBmMainVoltC;
        if (ERR_ES1_GET_BIT(ERR_ES1_WRN_MAIN_VC_LOW) == 0)
        {   if (usVolt >= usLow)
            {   usTimer5 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer5) > usErrDly)
            {   ERR_ES1_SET_BIT(ERR_ES1_WRN_MAIN_VC_LOW);
                usTimer5 = usTimNow;
            }
        }
        else if (usVolt < usLow)
        {   usTimer5 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer5) > usErrDly)
        {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_VC_LOW);
            usTimer5 = usTimNow;
        }
        if (ERR_ES1_GET_BIT(ERR_ES1_WRN_MAIN_VC_HGH) == 0)
        {   if (usVolt < usHigh)
            {   usTimer6 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer6) > usErrDly)
            {   ERR_ES1_SET_BIT(ERR_ES1_WRN_MAIN_VC_HGH);
                usTimer6 = usTimNow;
            }
        }
        else if (usVolt >= usHigh)
        {   usTimer6 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer6) > usErrDly)
        {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_VC_HGH);
            usTimer6 = usTimNow;
        }
    }
    else if (usDBfMainVoltErrAct == 1)
    {   usVolt = usDBmMainVoltA;
        if (usVolt >= usLow)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_SET_BIT(ERR_ES1_STP_MAIN_VA_LOW);
            usTimer1 = usTimNow;
        }
        if (usVolt < usHigh)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
        {   ERR_ES1_SET_BIT(ERR_ES1_STP_MAIN_VA_HGH);
            usTimer2 = usTimNow;
        }
        usVolt = usDBmMainVoltB;
        if (usVolt >= usLow)
        {   usTimer3 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer3) > usErrDly)
        {   ERR_ES1_SET_BIT(ERR_ES1_STP_MAIN_VB_LOW);
            usTimer3 = usTimNow;
        }
        if (usVolt < usHigh)
        {   usTimer4 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer4) > usErrDly)
        {   ERR_ES1_SET_BIT(ERR_ES1_STP_MAIN_VB_HGH);
            usTimer4 = usTimNow;
        }
        usVolt = usDBmMainVoltC;
        if (usVolt >= usLow)
        {   usTimer5 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer5) > usErrDly)
        {   ERR_ES1_SET_BIT(ERR_ES1_STP_MAIN_VC_LOW);
            usTimer5 = usTimNow;
        }
        if (usVolt < usHigh)
        {   usTimer6 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer6) > usErrDly)
        {   ERR_ES1_SET_BIT(ERR_ES1_STP_MAIN_VC_HGH);
            usTimer6 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorMainFreq()                         */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorMainFreq (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    INT16U usFreq, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpMainFreqErrDly;
    usFreq   = usDBmMainFreq;
    if ((ucFunc == SF_DISABLE) ||
        (usDBmMainVoltA < usDBpMainVoltLostLow) ||
        (usDBmMainVoltB < usDBpMainVoltLostLow) ||
        (usDBmMainVoltC < usDBpMainVoltLostLow) )
    {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_F_LOW | ERR_ES1_WRN_MAIN_F_HGH);
        usTimer1 = usTimNow;
        usTimer2 = usTimNow;
    }
    else if (usDBfMainFreqErrAct == 0)
    {   if (ERR_ES1_GET_BIT(ERR_ES1_WRN_MAIN_F_LOW) == 0)
        {   if (usFreq >= usDBpMainFreqErrLow)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES1_SET_BIT(ERR_ES1_WRN_MAIN_F_LOW);
                usTimer1 = usTimNow;
            }
        }
        else if (usFreq < usDBpMainFreqErrLow)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_F_LOW);
            usTimer1 = usTimNow;
        }
        if (ERR_ES1_GET_BIT(ERR_ES1_WRN_MAIN_F_HGH) == 0)
        {   if (usFreq < usDBpMainFreqErrHigh)
            {   usTimer2 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
            {   ERR_ES1_SET_BIT(ERR_ES1_WRN_MAIN_F_HGH);
                usTimer2 = usTimNow;
            }
        }
        else if (usFreq >= usDBpMainFreqErrHigh)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
        {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_F_HGH);
            usTimer2 = usTimNow;
        }
    }
    else if (usDBfMainFreqErrAct == 1)
    {   if (usFreq >= usDBpMainFreqErrLow)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_SET_BIT(ERR_ES1_STP_MAIN_F_LOW);
            usTimer1 = usTimNow;
        }
        if (usFreq < usDBpMainFreqErrHigh)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
        {   ERR_ES1_SET_BIT(ERR_ES1_STP_MAIN_F_HGH);
            usTimer2 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorMainPhase()                        */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorMainPhase (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usMax, usMin, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpMainPhaseErrDly;
    usMax    = usDBmMainPhaseAB;
    usMin    = usMax;
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
    if ((ucFunc == SF_DISABLE) ||
        (usDBmMainVoltA < usDBpMainVoltLostLow) ||
        (usDBmMainVoltB < usDBpMainVoltLostLow) ||
        (usDBmMainVoltC < usDBpMainVoltLostLow) )
    {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_PHASE);
        usTimer1 = usTimNow;
    }
    else if (usDBfMainPhaseErrAct == 0)
    {   if (ERR_ES1_GET_BIT(ERR_ES1_WRN_MAIN_PHASE) == 0)
        {   if ((usMin >= usDBpMainPhaseErrLow) &&
                (usMax <  usDBpMainPhaseErrHigh))
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES1_SET_BIT(ERR_ES1_WRN_MAIN_PHASE);
                usTimer1 = usTimNow;
            }
        }
        else if ((usMin <  usDBpMainPhaseErrLow) ||
                 (usMax >= usDBpMainPhaseErrHigh))
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_PHASE);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfMainPhaseErrAct == 1)
    {   if ((usMin >= usDBpMainPhaseErrLow) &&
            (usMax <  usDBpMainPhaseErrHigh))
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_SET_BIT(ERR_ES1_STP_MAIN_PHASE);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                         SFMonitorMainCurrShort()                     */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorMainCurrShort (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    INT16U usCurr, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpMainCurrShortDly;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES2_CLR_BIT(ERR_ES2_WRN_MAIN_SHRT_A |
                        ERR_ES2_WRN_MAIN_SHRT_B |
                        ERR_ES2_WRN_MAIN_SHRT_C);
        usTimer1 = usTimNow;
        usTimer2 = usTimNow;
        usTimer3 = usTimNow;
    }
    else if (usDBfMainCurrShortErrAct == 0)
    {   usCurr = usDBmMainCurrA;
        if (ERR_ES2_GET_BIT(ERR_ES2_WRN_MAIN_SHRT_A) == 0)
        {   if (usCurr < usDBpMainCurrShort)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES2_SET_BIT(ERR_ES2_WRN_MAIN_SHRT_A);
                usTimer1 = usTimNow;
            }
        }
        else if (usCurr >= usDBpMainCurrShort)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES2_CLR_BIT(ERR_ES2_WRN_MAIN_SHRT_A);
            usTimer1 = usTimNow;
        }
        usCurr = usDBmMainCurrB;
        if (ERR_ES2_GET_BIT(ERR_ES2_WRN_MAIN_SHRT_B) == 0)
        {   if (usCurr < usDBpMainCurrShort)
            {   usTimer2 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
            {   ERR_ES2_SET_BIT(ERR_ES2_WRN_MAIN_SHRT_B);
                usTimer2 = usTimNow;
            }
        }
        else if (usCurr >= usDBpMainCurrShort)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
        {   ERR_ES2_CLR_BIT(ERR_ES2_WRN_MAIN_SHRT_B);
            usTimer2 = usTimNow;
        }
        usCurr = usDBmMainCurrC;
        if (ERR_ES2_GET_BIT(ERR_ES2_WRN_MAIN_SHRT_C) == 0)
        {   if (usCurr < usDBpMainCurrShort)
            {   usTimer3 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer3) > usErrDly)
            {   ERR_ES2_SET_BIT(ERR_ES2_WRN_MAIN_SHRT_C);
                usTimer3 = usTimNow;
            }
        }
        else if (usCurr >= usDBpMainCurrShort)
        {   usTimer3 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer3) > usErrDly)
        {   ERR_ES2_CLR_BIT(ERR_ES2_WRN_MAIN_SHRT_C);
            usTimer3 = usTimNow;
        }
    }
    else if (usDBfMainCurrShortErrAct == 1)
    {   usCurr = usDBmMainCurrA;
        if (usCurr < usDBpMainCurrShort)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_SHRT_A);
            usTimer1 = usTimNow;
        }
        usCurr = usDBmMainCurrB;
        if (usCurr < usDBpMainCurrShort)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
        {   ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_SHRT_B);
            usTimer2 = usTimNow;
        }
        usCurr = usDBmMainCurrC;
        if (usCurr < usDBpMainCurrShort)
        {   usTimer3 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer3) > usErrDly)
        {   ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_SHRT_C);
            usTimer3 = usTimNow;
        }
    }    
}
#endif

/* ******************************************************************** */
/*                    SFMonitorMainCurrLongInit()                       */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorMainCurrLongInit (INT16U usFreq)
{   SFI2tTimeOverInit(usDBpMainCurrRated, usDBpMainCurrLongDly,
                      usFreq, &sSFI2tMainCurrA);
    SFI2tTimeOverInit(usDBpMainCurrRated, usDBpMainCurrLongDly,
                      usFreq, &sSFI2tMainCurrB);
    SFI2tTimeOverInit(usDBpMainCurrRated, usDBpMainCurrLongDly,
                      usFreq, &sSFI2tMainCurrC);
}
#endif

/* ******************************************************************** */
/*                      SFMonitorMainCurrLong()                         */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorMainCurrLong (INT08U ucFunc)
{   if (ucFunc == SF_DISABLE)
    {   ERR_ES2_CLR_BIT(ERR_ES2_WRN_MAIN_LONG_A |
                        ERR_ES2_WRN_MAIN_LONG_B |
                        ERR_ES2_WRN_MAIN_LONG_C);
    }
    else if (usDBfMainCurrLongErrAct == 0)
    {   if (SFI2tTimeOverCheck(usDBmMainCurrA,&sSFI2tMainCurrA) != 0)
        {   ERR_ES2_SET_BIT(ERR_ES2_WRN_MAIN_LONG_A);
        }   else
        {   ERR_ES2_CLR_BIT(ERR_ES2_WRN_MAIN_LONG_A);
        }
        if (SFI2tTimeOverCheck(usDBmMainCurrB,&sSFI2tMainCurrB) != 0)
        {   ERR_ES2_SET_BIT(ERR_ES2_WRN_MAIN_LONG_B);
        }   else
        {   ERR_ES2_CLR_BIT(ERR_ES2_WRN_MAIN_LONG_B);
        }
        if (SFI2tTimeOverCheck(usDBmMainCurrC,&sSFI2tMainCurrC) != 0)
        {   ERR_ES2_SET_BIT(ERR_ES2_WRN_MAIN_LONG_C);
        }   else
        {   ERR_ES2_CLR_BIT(ERR_ES2_WRN_MAIN_LONG_C);
        }
    }
    else if (usDBfMainCurrLongErrAct == 1)
    {   if (SFI2tTimeOverCheck(usDBmMainCurrA,&sSFI2tMainCurrA) != 0)
        {   ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_LONG_A);
        }
        if (SFI2tTimeOverCheck(usDBmMainCurrB,&sSFI2tMainCurrB) != 0)
        {   ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_LONG_B);
        }
        if (SFI2tTimeOverCheck(usDBmMainCurrC,&sSFI2tMainCurrC) != 0)
        {   ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_LONG_C);
        }
    }
}
#endif

/* ******************************************************************** */
/*                         SFMonitorMainCurrGnd()                       */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorMainCurrGnd (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usCurr, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpMainCurrGndErrDly;
    usCurr   = usDBmMainCurrGnd;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES2_CLR_BIT(ERR_ES2_WRN_MAIN_C_GND);
        usTimer1 = usTimNow;
    }
    else if (usDBfMainCurrGndErrAct == 0)
    {   if (ERR_ES2_GET_BIT(ERR_ES2_WRN_MAIN_C_GND) == 0)
        {   if (usCurr < usDBpMainCurrGndErrHigh)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES2_SET_BIT(ERR_ES2_WRN_MAIN_C_GND);
                usTimer1 = usTimNow;
            }
        }
        else if (usCurr >= usDBpMainCurrGndErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES2_CLR_BIT(ERR_ES2_WRN_MAIN_C_GND);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfMainCurrGndErrAct == 1)
    {   if (usCurr < usDBpMainCurrGndErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_C_GND);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                         SFMonitorMainCurrUnb()                       */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorMainCurrUnb (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usCurr, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpMainCurrUnbErrDly;
    usCurr   = usDBmMainCurrUnb;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES2_CLR_BIT(ERR_ES2_WRN_MAIN_C_UNB);
        usTimer1 = usTimNow;
    }
    else if (usDBfMainCurrUnbErrAct == 0)
    {   if (ERR_ES2_GET_BIT(ERR_ES2_WRN_MAIN_C_UNB) == 0)
        {   if (usCurr < usDBpMainCurrUnbErrHigh)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES2_SET_BIT(ERR_ES2_WRN_MAIN_C_UNB);
                usTimer1 = usTimNow;
            }
        }
        else if (usCurr >= usDBpMainCurrUnbErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES2_CLR_BIT(ERR_ES2_WRN_MAIN_C_UNB);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfMainCurrUnbErrAct == 1)
    {   if (usCurr < usDBpMainCurrUnbErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES2_SET_BIT(ERR_ES2_STP_MAIN_C_UNB);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                         SFMonitorMainActPwr()                        */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorMainActPwr (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usPower, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpMainActPwrErrDly;
    usPower  = usDBmMainActPowerAll;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_P_ACT);
        usTimer1 = usTimNow;
    }
    else if (usDBfMainActPwrErrAct == 0)
    {   if (ERR_ES1_GET_BIT(ERR_ES1_WRN_MAIN_P_ACT) == 0)
        {   if (usPower < usDBpMainActPwrErrHigh)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES1_SET_BIT(ERR_ES1_WRN_MAIN_P_ACT);
                usTimer1 = usTimNow;
            }
        }
        else if (usPower >= usDBpMainActPwrErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_P_ACT);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfMainActPwrErrAct == 1)
    {   if (usPower < usDBpMainActPwrErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_SET_BIT(ERR_ES1_STP_MAIN_P_ACT);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                         SFMonitorMainReactPwr()                      */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorMainReactPwr (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usPower, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpMainReactPwrErrDly;
    usPower  = usDBmMainReactPowerAll;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_P_RCT);
        usTimer1 = usTimNow;
    }
    else if (usDBfMainReactPwrErrAct == 0)
    {   if (ERR_ES1_GET_BIT(ERR_ES1_WRN_MAIN_P_RCT) == 0)
        {   if (usPower < usDBpMainReactPwrErrHigh)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES1_SET_BIT(ERR_ES1_WRN_MAIN_P_RCT);
                usTimer1 = usTimNow;
            }
        }
        else if (usPower >= usDBpMainReactPwrErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_P_RCT);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfMainReactPwrErrAct == 1)
    {   if (usPower < usDBpMainReactPwrErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_SET_BIT(ERR_ES1_STP_MAIN_P_RCT);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                         SFMonitorMainAppPwr()                        */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorMainAppPwr (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usPower, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpMainAppPwrErrDly;
    usPower  = usDBmMainAppPowerAll;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_P_APP);
        usTimer1 = usTimNow;
    }
    else if (usDBfMainAppPwrErrAct == 0)
    {   if (ERR_ES1_GET_BIT(ERR_ES1_WRN_MAIN_P_APP) == 0)
        {   if (usPower < usDBpMainAppPwrErrHigh)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES1_SET_BIT(ERR_ES1_WRN_MAIN_P_APP);
                usTimer1 = usTimNow;
            }
        }
        else if (usPower >= usDBpMainAppPwrErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_P_APP);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfMainAppPwrErrAct == 1)
    {   if (usPower < usDBpMainAppPwrErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_SET_BIT(ERR_ES1_STP_MAIN_P_APP);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                         SFMonitorMainRocof()                         */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorMainRocof (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usRocof, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpMainRocofErrDly;
    usRocof  = usDBmMainRocof;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_ROCOF);
        usTimer1 = usTimNow;
    }
    else if (usDBfMainRocofErrAct == 0)
    {   if (ERR_ES1_GET_BIT(ERR_ES1_WRN_MAIN_ROCOF) == 0)
        {   if (usRocof < usDBpMainRocofErrHigh)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES1_SET_BIT(ERR_ES1_WRN_MAIN_ROCOF);
                usTimer1 = usTimNow;
            }
        }
        else if (usRocof >= usDBpMainRocofErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_ROCOF);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfMainRocofErrAct == 1)
    {   if (usRocof < usDBpMainRocofErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_SET_BIT(ERR_ES1_STP_MAIN_ROCOF);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                         SFMonitorMainVector()                        */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorMainVector (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usVector, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpMainVoltUnbErrDly;
    usVector = usDBmMainVoltUnb;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_VECTOR);
        usTimer1 = usTimNow;
    }
    else if (usDBfMainVoltUnbErrAct == 0)
    {   if (ERR_ES1_GET_BIT(ERR_ES1_WRN_MAIN_VECTOR) == 0)
        {   if (usVector < usDBpMainVoltUnbErrHigh)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES1_SET_BIT(ERR_ES1_WRN_MAIN_VECTOR);
                usTimer1 = usTimNow;
            }
        }
        else if (usVector >= usDBpMainVoltUnbErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_CLR_BIT(ERR_ES1_WRN_MAIN_VECTOR);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfMainVoltUnbErrAct == 1)
    {   if (usVector < usDBpMainVoltUnbErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_SET_BIT(ERR_ES1_STP_MAIN_VECTOR);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                         SFMonitorMainSynVolt()                       */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorMainSynVolt (void)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    INT16U usMax, usMin, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpMainSyncVoltErrDly;
    usMax    = usDBmMainVoltA;
    usMin    = usMax;
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
    if (ERR_ES7_GET_BIT(ERR_ES7_SYN_MAIN_V_LOW) == 0)
    {   if (usMin >= usDBpMainSyncVoltErrLow)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES7_SET_BIT(ERR_ES7_SYN_MAIN_V_LOW);
            usTimer1 = usTimNow;
        }
    }
    else if (usMin < usDBpMainSyncVoltErrLow)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
    {   ERR_ES7_CLR_BIT(ERR_ES7_SYN_MAIN_V_LOW);
        usTimer1 = usTimNow;
    }
    if (ERR_ES7_GET_BIT(ERR_ES7_SYN_MAIN_V_HGH) == 0)
    {   if (usMax < usDBpMainSyncVoltErrHigh)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
        {   ERR_ES7_SET_BIT(ERR_ES7_SYN_MAIN_V_HGH);
            usTimer2 = usTimNow;
        }
    }
    else if (usMax >= usDBpMainSyncVoltErrHigh)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
    {   ERR_ES7_CLR_BIT(ERR_ES7_SYN_MAIN_V_HGH);
        usTimer2 = usTimNow;
    }
}
#endif

/* ******************************************************************** */
/*                         SFMonitorMainSynFreq()                       */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorMainSynFreq (void)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    INT16U usFreq, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpMainSyncFreqErrDly;
    usFreq   = usDBmMainFreq;
    if (ERR_ES7_GET_BIT(ERR_ES7_SYN_MAIN_F_LOW) == 0)
    {   if (usFreq >= usDBpMainSyncFreqErrLow)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES7_SET_BIT(ERR_ES7_SYN_MAIN_F_LOW);
            usTimer1 = usTimNow;
        }
    }
    else if (usFreq < usDBpMainSyncFreqErrLow)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
    {   ERR_ES7_CLR_BIT(ERR_ES7_SYN_MAIN_F_LOW);
        usTimer1 = usTimNow;
    }
    if (ERR_ES7_GET_BIT(ERR_ES7_SYN_MAIN_F_HGH) == 0)
    {   if (usFreq < usDBpMainSyncFreqErrHigh)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
        {   ERR_ES7_SET_BIT(ERR_ES7_SYN_MAIN_F_HGH);
            usTimer2 = usTimNow;
        }
    }
    else if (usFreq >= usDBpMainSyncFreqErrHigh)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
    {   ERR_ES7_CLR_BIT(ERR_ES7_SYN_MAIN_F_HGH);
        usTimer2 = usTimNow;
    }
}
#endif

/* ******************************************************************** */
/*                         SFMonitorMainVoltLost()                      */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorMainVoltLost (void)
{   static INT16U usTimer1 = 0;
    INT16U usMax, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpMainVoltLostDly;
    usMax    = usDBmMainVoltA;
    if (usMax < usDBmMainVoltB)
    {   usMax = usDBmMainVoltB;
    }
    if (usMax < usDBmMainVoltC)
    {   usMax = usDBmMainVoltC;
    }
    if (ERR_ES1_GET_BIT(ERR_ES1_STS_MAIN_V_LOST) == 0)
    {   if (usMax >= usDBpMainVoltLostLow)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES1_SET_BIT(ERR_ES1_STS_MAIN_V_LOST);
            usTimer1 = usTimNow;
        }
    }
    else if (usMax < usDBpMainVoltLostLow)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
    {   ERR_ES1_CLR_BIT(ERR_ES1_STS_MAIN_V_LOST);
        usTimer1 = usTimNow;
    }
}
#endif

/* ******************************************************************** */
/*                         SFMonitorGensVolt()                          */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorGensVolt (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    static INT16U usTimer4 = 0;
    static INT16U usTimer5 = 0;
    static INT16U usTimer6 = 0;
    static INT16U usTimer7 = 0;
    static INT16U usTimer8 = 0;
    static INT16U usTimer9 = 0;
    static INT16U usTimer10 = 0;
    static INT16U usTimer11 = 0;
    static INT16U usTimer12 = 0;
    INT16U usHigh, usLow, usVolt, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_VA_LOW | ERR_ES3_WRN_GENS_VA_HGH |
                        ERR_ES3_WRN_GENS_VB_LOW | ERR_ES3_WRN_GENS_VB_HGH |
                        ERR_ES3_WRN_GENS_VC_LOW | ERR_ES3_WRN_GENS_VC_HGH);
        usTimer1 = usTimNow;
        usTimer2 = usTimNow;
        usTimer3 = usTimNow;
        usTimer4 = usTimNow;
        usTimer5 = usTimNow;
        usTimer6 = usTimNow;
        usTimer7 = usTimNow;
        usTimer8 = usTimNow;
        usTimer9 = usTimNow;
        usTimer10 = usTimNow;
        usTimer11 = usTimNow;
        usTimer12 = usTimNow;
        return;
    }
    /* ************** Warn: Gens voltage Low/High ********************* */
    usErrDly = usDBpGensVoltWarnDly;
    usHigh   = usDBpGensVoltWarnHigh;
    usLow    = usDBpGensVoltWarnLow;
    /* ************** Warn: Gens voltageA Low/High ******************** */
    usVolt   = usDBmGensVoltA;
    if (ERR_ES3_GET_BIT(ERR_ES3_WRN_GENS_VA_LOW) == 0)
    {   if (usVolt >= usLow)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES3_SET_BIT(ERR_ES3_WRN_GENS_VA_LOW);
            usTimer1 = usTimNow;
        }
    }
    else if (usVolt < usLow)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_VA_LOW);
        usTimer1 = usTimNow;
    }
    if (ERR_ES3_GET_BIT(ERR_ES3_WRN_GENS_VA_HGH) == 0)
    {   if (usVolt < usHigh)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
        {   ERR_ES3_SET_BIT(ERR_ES3_WRN_GENS_VA_HGH);
            usTimer2 = usTimNow;
        }
    }
    else if (usVolt >= usHigh)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_VA_HGH);
        usTimer2 = usTimNow;
    }
    /* ************** Warn: Gens voltageB Low/High ******************** */
    usVolt = usDBmGensVoltB;
    if (ERR_ES3_GET_BIT(ERR_ES3_WRN_GENS_VB_LOW) == 0)
    {   if (usVolt >= usLow)
        {   usTimer3 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer3) > usErrDly)
        {   ERR_ES3_SET_BIT(ERR_ES3_WRN_GENS_VB_LOW);
            usTimer3 = usTimNow;
        }
    }
    else if (usVolt < usLow)
    {   usTimer3 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer3) > usErrDly)
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_VB_LOW);
        usTimer3 = usTimNow;
    }
    if (ERR_ES3_GET_BIT(ERR_ES3_WRN_GENS_VB_HGH) == 0)
    {   if (usVolt < usHigh)
        {   usTimer4 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer4) > usErrDly)
        {   ERR_ES3_SET_BIT(ERR_ES3_WRN_GENS_VB_HGH);
            usTimer4 = usTimNow;
        }
    }
    else if (usVolt >= usHigh)
    {   usTimer4 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer4) > usErrDly)
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_VB_HGH);
        usTimer4 = usTimNow;
    }
    /* ************** Warn: Gens voltageC Low/High ******************** */
    usVolt = usDBmGensVoltC;
    if (ERR_ES3_GET_BIT(ERR_ES3_WRN_GENS_VC_LOW) == 0)
    {   if (usVolt >= usLow)
        {   usTimer5 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer5) > usErrDly)
        {   ERR_ES3_SET_BIT(ERR_ES3_WRN_GENS_VC_LOW);
            usTimer5 = usTimNow;
        }
    }
    else if (usVolt < usLow)
    {   usTimer5 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer5) > usErrDly)
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_VC_LOW);
        usTimer5 = usTimNow;
    }
    if (ERR_ES3_GET_BIT(ERR_ES3_WRN_GENS_VC_HGH) == 0)
    {   if (usVolt < usHigh)
        {   usTimer6 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer6) > usErrDly)
        {   ERR_ES3_SET_BIT(ERR_ES3_WRN_GENS_VC_HGH);
            usTimer6 = usTimNow;
        }
    }
    else if (usVolt >= usHigh)
    {   usTimer6 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer6) > usErrDly)
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_VC_HGH);
        usTimer6 = usTimNow;
    }
    /* ************** Stop: Gens voltage Low/High ********************* */
    usErrDly = usDBpGensVoltStopDly;
    usHigh   = usDBpGensVoltStopHigh;
    usLow    = usDBpGensVoltStopLow;
    /* ************** Stop: Gens voltageA Low/High ******************** */
    usVolt = usDBmGensVoltA;
    if (usVolt >= usLow)
    {   usTimer7 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer7) > usErrDly)
    {   ERR_ES3_SET_BIT(ERR_ES3_STP_GENS_VA_LOW);
        usTimer7 = usTimNow;
    }
    if (usVolt < usHigh)
    {   usTimer8 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer8) > usErrDly)
    {   ERR_ES3_SET_BIT(ERR_ES3_STP_GENS_VA_HGH);
        usTimer8 = usTimNow;
    }
    /* ************** Stop: Gens voltageB Low/High ******************** */
    usVolt = usDBmGensVoltB;
    if (usVolt >= usLow)
    {   usTimer9 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer9) > usErrDly)
    {   ERR_ES3_SET_BIT(ERR_ES3_STP_GENS_VB_LOW);
        usTimer9 = usTimNow;
    }
    if (usVolt < usHigh)
    {   usTimer10 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer10) > usErrDly)
    {   ERR_ES3_SET_BIT(ERR_ES3_STP_GENS_VB_HGH);
        usTimer10 = usTimNow;
    }
    /* ************** Stop: Gens voltageC Low/High ******************** */
    usVolt = usDBmGensVoltC;
    if (usVolt >= usLow)
    {   usTimer11 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer11) > usErrDly)
    {   ERR_ES3_SET_BIT(ERR_ES3_STP_GENS_VC_LOW);
        usTimer11 = usTimNow;
    }
    if (usVolt < usHigh)
    {   usTimer12 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer12) > usErrDly)
    {   ERR_ES3_SET_BIT(ERR_ES3_STP_GENS_VC_HGH);
        usTimer12 = usTimNow;
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorGensFreq()                           */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorGensFreq (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    static INT16U usTimer4 = 0;
    INT16U usFreq, usTimNow;
    usTimNow = usFW100msTimer;
    usFreq   = usDBmGensFreq;
    if ((ucFunc == SF_DISABLE) ||
        (usDBmGensVoltA < usDBpGensVoltStopLow) ||
        (usDBmGensVoltB < usDBpGensVoltStopLow) ||
        (usDBmGensVoltC < usDBpGensVoltStopLow) )
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_F_LOW | ERR_ES3_WRN_GENS_F_HGH);
        usTimer1 = usTimNow;
        usTimer2 = usTimNow;
        usTimer3 = usTimNow;
        usTimer4 = usTimNow;
        return;
    }
    /* **************** Warn: Gens frequency Low ********************** */
    if (ERR_ES3_GET_BIT(ERR_ES3_WRN_GENS_F_LOW) == 0)
    {   if (usFreq >= usDBpGensFreqWarnLow)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usDBpGensFreqWarnDly)
        {   ERR_ES3_SET_BIT(ERR_ES3_WRN_GENS_F_LOW);
            usTimer1 = usTimNow;
        }
    }
    else if (usFreq < usDBpGensFreqWarnLow)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpGensFreqWarnDly)
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_F_LOW);
        usTimer1 = usTimNow;
    }
    /* **************** Warn: Gens frequency High ********************* */
    if (ERR_ES3_GET_BIT(ERR_ES3_WRN_GENS_F_HGH) == 0)
    {   if (usFreq < usDBpGensFreqWarnHigh)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usDBpGensFreqWarnDly)
        {   ERR_ES3_SET_BIT(ERR_ES3_WRN_GENS_F_HGH);
            usTimer2 = usTimNow;
        }
    }
    else if (usFreq >= usDBpGensFreqWarnHigh)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usDBpGensFreqWarnDly)
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_F_HGH);
        usTimer2 = usTimNow;
    }
    /* **************** Stop: Gens frequency Low ********************** */
    if (usFreq >= usDBpGensFreqStopLow)
    {   usTimer3 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer3) > usDBpGensFreqStopDly)
    {   ERR_ES3_SET_BIT(ERR_ES3_STP_GENS_F_LOW);
        usTimer3 = usTimNow;
    }
    /* **************** Stop: Gens frequency High ********************* */
    if (usFreq < usDBpGensFreqStopHigh)
    {   usTimer4 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer4) > usDBpGensFreqStopDly)
    {   ERR_ES3_SET_BIT(ERR_ES3_STP_GENS_F_HGH);
        usTimer4 = usTimNow;
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorGensPhase()                        */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorGensPhase (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usMax, usMin, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpGensPhaseErrDly;
    usMax    = usDBmGensPhaseAB;
    usMin    = usMax;
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
    if ((ucFunc == SF_DISABLE) ||
        (usDBmGensVoltA < usDBpMainVoltLostLow) ||
        (usDBmGensVoltB < usDBpMainVoltLostLow) ||
        (usDBmGensVoltC < usDBpMainVoltLostLow) )
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_PHASE);
        usTimer1 = usTimNow;
    }
    else if (usDBfGensPhaseErrAct == 0)
    {   if (ERR_ES3_GET_BIT(ERR_ES3_WRN_GENS_PHASE) == 0)
        {   if ((usMin >= usDBpGensPhaseErrLow) &&
                (usMax <  usDBpGensPhaseErrHigh))
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES3_SET_BIT(ERR_ES3_WRN_GENS_PHASE);
                usTimer1 = usTimNow;
            }
        }
        else if ((usMin <  usDBpGensPhaseErrLow) ||
                 (usMax >= usDBpGensPhaseErrHigh))
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_PHASE);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfGensPhaseErrAct == 1)
    {   if ((usMin >= usDBpGensPhaseErrLow) &&
            (usMax <  usDBpGensPhaseErrHigh))
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES3_SET_BIT(ERR_ES3_STP_GENS_PHASE);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                        SFMonitorGensCurrShort()                      */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorGensCurrShort (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    INT16U usCurr, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpGensCurrShortDly;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES4_CLR_BIT(ERR_ES4_WRN_GENS_SHRT_A |
                        ERR_ES4_WRN_GENS_SHRT_B |
                        ERR_ES4_WRN_GENS_SHRT_C);
        usTimer1 = usTimNow;
        usTimer2 = usTimNow;
        usTimer3 = usTimNow;
    }
    else if (usDBfGensCurrShortErrAct == 0)
    {   usCurr = usDBmGensCurrA;
        if (ERR_ES4_GET_BIT(ERR_ES4_WRN_GENS_SHRT_A) == 0)
        {   if (usCurr < usDBpGensCurrShort)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES4_SET_BIT(ERR_ES4_WRN_GENS_SHRT_A);
                usTimer1 = usTimNow;
            }
        }
        else if (usCurr >= usDBpGensCurrShort)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES4_CLR_BIT(ERR_ES4_WRN_GENS_SHRT_A);
            usTimer1 = usTimNow;
        }
        usCurr = usDBmGensCurrB;
        if (ERR_ES4_GET_BIT(ERR_ES4_WRN_GENS_SHRT_B) == 0)
        {   if (usCurr < usDBpGensCurrShort)
            {   usTimer2 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
            {   ERR_ES4_SET_BIT(ERR_ES4_WRN_GENS_SHRT_B);
                usTimer2 = usTimNow;
            }
        }
        else if (usCurr >= usDBpGensCurrShort)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
        {   ERR_ES4_CLR_BIT(ERR_ES4_WRN_GENS_SHRT_B);
            usTimer2 = usTimNow;
        }
        usCurr = usDBmGensCurrC;
        if (ERR_ES4_GET_BIT(ERR_ES4_WRN_GENS_SHRT_C) == 0)
        {   if (usCurr < usDBpGensCurrShort)
            {   usTimer3 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer3) > usErrDly)
            {   ERR_ES4_SET_BIT(ERR_ES4_WRN_GENS_SHRT_C);
                usTimer3 = usTimNow;
            }
        }
        else if (usCurr >= usDBpGensCurrShort)
        {   usTimer3 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer3) > usErrDly)
        {   ERR_ES4_CLR_BIT(ERR_ES4_WRN_GENS_SHRT_C);
            usTimer3 = usTimNow;
        }
    }
    else if (usDBfGensCurrShortErrAct == 1)
    {   usCurr = usDBmGensCurrA;
        if (usCurr < usDBpGensCurrShort)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SHRT_A);
            usTimer1 = usTimNow;
        }
        usCurr = usDBmGensCurrB;
        if (usCurr < usDBpGensCurrShort)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SHRT_B);
            usTimer2 = usTimNow;
        }
        usCurr = usDBmGensCurrC;
        if (usCurr < usDBpGensCurrShort)
        {   usTimer3 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer3) > usErrDly)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_SHRT_C);
            usTimer3 = usTimNow;
        }
    }    
}
#endif

/* ******************************************************************** */
/*                    SFMonitorGensCurrLongInit()                       */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorGensCurrLongInit (INT16U usFreq)
{   SFI2tTimeOverInit(usDBpGensCurrRated, usDBpGensCurrLongDly,
                      usFreq, &sSFI2tGensCurrA);
    SFI2tTimeOverInit(usDBpGensCurrRated, usDBpGensCurrLongDly,
                      usFreq, &sSFI2tGensCurrB);
    SFI2tTimeOverInit(usDBpGensCurrRated, usDBpGensCurrLongDly,
                      usFreq, &sSFI2tGensCurrC);
}
#endif

/* ******************************************************************** */
/*                      SFMonitorGensCurrLong()                         */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorGensCurrLong (INT08U ucFunc)
{   if (ucFunc == SF_DISABLE)
    {   ERR_ES4_CLR_BIT(ERR_ES4_WRN_GENS_LONG_A |
                        ERR_ES4_WRN_GENS_LONG_B |
                        ERR_ES4_WRN_GENS_LONG_C);
    }
    else if (usDBfGensCurrLongErrAct == 0)
    {   if (SFI2tTimeOverCheck(usDBmGensCurrA,&sSFI2tGensCurrA) != 0)
        {   ERR_ES4_SET_BIT(ERR_ES4_WRN_GENS_LONG_A);
        }   else
        {   ERR_ES4_CLR_BIT(ERR_ES4_WRN_GENS_LONG_A);
        }
        if (SFI2tTimeOverCheck(usDBmGensCurrB,&sSFI2tGensCurrB) != 0)
        {   ERR_ES4_SET_BIT(ERR_ES4_WRN_GENS_LONG_B);
        }   else
        {   ERR_ES4_CLR_BIT(ERR_ES4_WRN_GENS_LONG_B);
        }
        if (SFI2tTimeOverCheck(usDBmGensCurrC,&sSFI2tGensCurrC) != 0)
        {   ERR_ES4_SET_BIT(ERR_ES4_WRN_GENS_LONG_C);
        }   else
        {   ERR_ES4_CLR_BIT(ERR_ES4_WRN_GENS_LONG_C);
        }
    }
    else if (usDBfGensCurrLongErrAct == 1)
    {   if (SFI2tTimeOverCheck(usDBmGensCurrA,&sSFI2tGensCurrA) != 0)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_LONG_A);
        }
        if (SFI2tTimeOverCheck(usDBmGensCurrB,&sSFI2tGensCurrB) != 0)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_LONG_B);
        }
        if (SFI2tTimeOverCheck(usDBmGensCurrC,&sSFI2tGensCurrC) != 0)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_LONG_C);
        }
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorGensCurrGnd()                      */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorGensCurrGnd (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usCurr, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpGensCurrGndErrDly;
    usCurr   = usDBmGensCurrGnd;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES4_CLR_BIT(ERR_ES4_WRN_GENS_C_GND);
        usTimer1 = usTimNow;
    }
    else if (usDBfGensCurrGndErrAct == 0)
    {   if (ERR_ES4_GET_BIT(ERR_ES4_WRN_GENS_C_GND) == 0)
        {   if (usCurr < usDBpGensCurrGndErrHigh)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES4_SET_BIT(ERR_ES4_WRN_GENS_C_GND);
                usTimer1 = usTimNow;
            }
        }
        else if (usCurr >= usDBpGensCurrGndErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES4_CLR_BIT(ERR_ES4_WRN_GENS_C_GND);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfGensCurrGndErrAct == 1)
    {   if (usCurr < usDBpGensCurrGndErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_C_GND);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorGensCurrUnb()                      */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorGensCurrUnb (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usCurr, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpGensCurrUnbErrDly;
    usCurr   = usDBmGensCurrUnb;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES4_CLR_BIT(ERR_ES4_WRN_GENS_C_UNB);
        usTimer1 = usTimNow;
    }
    else if (usDBfGensCurrUnbErrAct == 0)
    {   if (ERR_ES4_GET_BIT(ERR_ES4_WRN_GENS_C_UNB) == 0)
        {   if (usCurr < usDBpGensCurrUnbErrHigh)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES4_SET_BIT(ERR_ES4_WRN_GENS_C_UNB);
                usTimer1 = usTimNow;
            }
        }
        else if (usCurr >= usDBpGensCurrUnbErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES4_CLR_BIT(ERR_ES4_WRN_GENS_C_UNB);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfGensCurrUnbErrAct == 1)
    {   if (usCurr < usDBpGensCurrUnbErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES4_SET_BIT(ERR_ES4_STP_GENS_C_UNB);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorGensActPwr()                       */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorGensActPwr (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usPower, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpGensActPwrErrDly;
    usPower  = usDBmGensActPowerAll;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_P_ACT);
        usTimer1 = usTimNow;
    }
    else if (usDBfGensActPwrErrAct == 0)
    {   if (ERR_ES3_GET_BIT(ERR_ES3_WRN_GENS_P_ACT) == 0)
        {   if (usPower < usDBpGensActPwrErrHigh)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES3_SET_BIT(ERR_ES3_WRN_GENS_P_ACT);
                usTimer1 = usTimNow;
            }
        }
        else if (usPower >= usDBpGensActPwrErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_P_ACT);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfGensActPwrErrAct == 1)
    {   if (usPower < usDBpGensActPwrErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES3_SET_BIT(ERR_ES3_STP_GENS_P_ACT);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorGensReactPwr()                     */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorGensReactPwr (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usPower, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpGensReactPwrErrDly;
    usPower  = usDBmGensReactPowerAll;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_P_RCT);
        usTimer1 = usTimNow;
    }
    else if (usDBfGensReactPwrErrAct == 0)
    {   if (ERR_ES3_GET_BIT(ERR_ES3_WRN_GENS_P_RCT) == 0)
        {   if (usPower < usDBpGensReactPwrErrHigh)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES3_SET_BIT(ERR_ES3_WRN_GENS_P_RCT);
                usTimer1 = usTimNow;
            }
        }
        else if (usPower >= usDBpGensReactPwrErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_P_RCT);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfGensReactPwrErrAct == 1)
    {   if (usPower < usDBpGensReactPwrErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES3_SET_BIT(ERR_ES3_STP_GENS_P_RCT);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorGensAppPwr()                       */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorGensAppPwr (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usPower, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpGensAppPwrErrDly;
    usPower  = usDBmGensAppPowerAll;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_P_APP);
        usTimer1 = usTimNow;
    }
    else if (usDBfGensAppPwrErrAct == 0)
    {   if (ERR_ES3_GET_BIT(ERR_ES3_WRN_GENS_P_APP) == 0)
        {   if (usPower < usDBpGensAppPwrErrHigh)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES3_SET_BIT(ERR_ES3_WRN_GENS_P_APP);
                usTimer1 = usTimNow;
            }
        }
        else if (usPower >= usDBpGensAppPwrErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_P_APP);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfGensAppPwrErrAct == 1)
    {   if (usPower < usDBpGensAppPwrErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES3_SET_BIT(ERR_ES3_STP_GENS_P_APP);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorGensInvPwr()                       */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorGensInvPwr (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usPower, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpGensInvPwrErrDly;
    usPower  = usDBmGensInvPowerAll;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_P_INV);
        usTimer1 = usTimNow;
    }
    else if (usDBfGensInvPwrErrAct == 0)
    {   if (ERR_ES3_GET_BIT(ERR_ES3_WRN_GENS_P_INV) == 0)
        {   if (usPower < usDBpGensInvPwrErrHigh)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES3_SET_BIT(ERR_ES3_WRN_GENS_P_INV);
                usTimer1 = usTimNow;
            }
        }
        else if (usPower >= usDBpGensInvPwrErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_P_INV);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfGensInvPwrErrAct == 1)
    {   if (usPower < usDBpGensInvPwrErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES3_SET_BIT(ERR_ES3_STP_GENS_P_INV);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorGensFactor()                       */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorGensFactor (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usFactor, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpGensFactorErrDly;
    usFactor = usDBmGensPowerFactorAll;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_FACTOR);
        usTimer1 = usTimNow;
    }
    else if (usDBfGensFactorErrAct == 0)
    {   if (ERR_ES3_GET_BIT(ERR_ES3_WRN_GENS_FACTOR) == 0)
        {   if ((usFactor >= usDBpGensFactorErrLow) &&
                (usFactor <  usDBpGensFactorErrHigh))
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES3_SET_BIT(ERR_ES3_WRN_GENS_FACTOR);
                usTimer1 = usTimNow;
            }
        }
        else if ((usFactor <  usDBpGensFactorErrLow) ||
                 (usFactor >= usDBpGensFactorErrHigh))
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_FACTOR);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfGensFactorErrAct == 1)
    {   if ((usFactor >= usDBpGensFactorErrLow) &&
            (usFactor <  usDBpGensFactorErrHigh))
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES3_SET_BIT(ERR_ES3_STP_GENS_FACTOR);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorGensMagLost()                      */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorGensMagLost (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usPower, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpGensMagLostErrDly;
    usPower  = usDBmGensMagLost;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_M_LOST);
        usTimer1 = usTimNow;
    }
    else if (usDBfGensMagLostErrAct == 0)
    {   if (ERR_ES3_GET_BIT(ERR_ES3_WRN_GENS_M_LOST) == 0)
        {   if (usPower < usDBpGensMagLostErrHigh)
            {   usTimer1 = usTimNow;
            }
            else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
            {   ERR_ES3_SET_BIT(ERR_ES3_WRN_GENS_M_LOST);
                usTimer1 = usTimNow;
            }
        }
        else if (usPower >= usDBpGensMagLostErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_M_LOST);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBfGensMagLostErrAct == 1)
    {   if (usPower < usDBpGensMagLostErrHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES3_SET_BIT(ERR_ES3_STP_GENS_M_LOST);
            usTimer1 = usTimNow;
        }
    }
}
#endif

/* ******************************************************************** */
/*                       SFMonitorGensSyncTimeOver()                    */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorGensSyncTimeOver (INT16U usPhase)
{   static INT16U usTimer1 = 0;
    INT16U usTimNow;
    usTimNow = usFW100msTimer;
    if(((usPhase != CTL_PHASE_SYNCHRING) &&
        (usPhase != CTL_PHASE_SYNCHRING2)) ||
        (usDBmSyncConditionMatch != 0) )
    {   ERR_ES3_CLR_BIT(ERR_ES3_WRN_GENS_SYN_TO);
        usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpTimeOfSyncFailToStop)
    {   ERR_ES3_SET_BIT(ERR_ES3_STP_GENS_SYN_TO);
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpTimeOfSyncFailToWarn)
    {   ERR_ES3_SET_BIT(ERR_ES3_WRN_GENS_SYN_TO);
    }
}
#endif

/* ******************************************************************** */
/*                       SFMonitorGensReadyToLoad()                     */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorGensReadyToLoad (void)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    INT16U usMin, usTimNow, usErrDly;
    usTimNow = usFW100msTimer;
    usErrDly = usDBpGensVoltToLoadDly;
    usMin    = usDBmGensVoltA;
    if (usMin > usDBmGensVoltB)
    {   usMin = usDBmGensVoltB;
    }
    if (usMin > usDBmGensVoltC)
    {   usMin = usDBmGensVoltC;
    }
    if (ERR_ES7_GET_BIT(ERR_ES7_LD_GENS_V_LOW) == 0)
    {   if (usMin >= usDBpGensVoltToLoad)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
        {   ERR_ES7_SET_BIT(ERR_ES7_LD_GENS_V_LOW);
            usTimer1 = usTimNow;
        }
    }
    else if (usMin < usDBpGensVoltToLoad)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usErrDly)
    {   ERR_ES7_CLR_BIT(ERR_ES7_LD_GENS_V_LOW);
        usTimer1 = usTimNow;
    }
    usErrDly = usDBpGensFreqToLoadDly;
    usMin = usDBmGensFreq;
    if (ERR_ES7_GET_BIT(ERR_ES7_LD_GENS_F_LOW) == 0)
    {   if (usMin >= usDBpGensFreqToLoad)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
        {   ERR_ES7_SET_BIT(ERR_ES7_LD_GENS_F_LOW);
            usTimer2 = usTimNow;
        }
    }
    else if (usMin < usDBpGensFreqToLoad)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usErrDly)
    {   ERR_ES7_CLR_BIT(ERR_ES7_LD_GENS_F_LOW);
        usTimer2 = usTimNow;
    }
}
#endif

/* ******************************************************************** */
/*                        SFMonitorLoadSchedHigh()                      */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorLoadSchedHigh (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usTimNow;
    usTimNow = usFW100msTimer;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES7_CLR_BIT(ERR_ES7_LD_SCHED_HGH);
        usTimer1 = usTimNow;
    }
    else if (ERR_ES7_GET_BIT(ERR_ES7_LD_SCHED_HGH) == 0)
    {   if (usDBmCanSchedActIntoPrsnt < usDBpCanLoadPrsntToStart)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usDBpCanLoadPrsntStartDly)
        {   ERR_ES7_SET_BIT(ERR_ES7_LD_SCHED_HGH);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBmCanSchedActIntoPrsnt >= usDBpCanLoadPrsntToStart)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpCanLoadPrsntStartDly)
    {   ERR_ES7_CLR_BIT(ERR_ES7_LD_SCHED_HGH);
        usTimer1 = usTimNow;
    }
}
#endif

/* ******************************************************************** */
/*                        SFMonitorLoadSchedLow()                       */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorLoadSchedLow (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    INT16U usTimNow;
    usTimNow = usFW100msTimer;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES7_CLR_BIT(ERR_ES7_LD_SCHED_LOW);
        usTimer1 = usTimNow;
    }
    else if (ERR_ES7_GET_BIT(ERR_ES7_LD_SCHED_LOW) == 0)
    {   if (usDBmCanSchedActPrsntSetp >= usDBpCanLoadPrsntToStop)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usDBpCanLoadPrsntStopDly)
        {   ERR_ES7_SET_BIT(ERR_ES7_LD_SCHED_LOW);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBmCanSchedActPrsntSetp < usDBpCanLoadPrsntToStop)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpCanLoadPrsntStopDly)
    {   ERR_ES7_CLR_BIT(ERR_ES7_LD_SCHED_LOW);
        usTimer1 = usTimNow;
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorEngSpeedHigh()                     */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorEngSpeedHigh (void)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    INT16U usSpeed, usTimNow;
    usTimNow = usFW100msTimer;
    usSpeed  = usDBmEngSpeed;
    /* **************** Warn: Engine Speed High *********************** */
    if (ERR_ES5_GET_BIT(ERR_ES5_WRN_SPEED_HGH) == 0)
    {   if (usSpeed < usDBpEngSpeedWarnHigh)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usDBpEngSpeedWarnDly)
        {   ERR_ES5_SET_BIT(ERR_ES5_WRN_SPEED_HGH);
            usTimer1 = usTimNow;
        }
    }
    else if (usSpeed >= usDBpEngSpeedWarnHigh)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpEngSpeedWarnDly)
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_SPEED_HGH);
        usTimer1 = usTimNow;
    }
    /* **************** Stop: Engine Speed High *********************** */
    if (usSpeed < usDBpEngSpeedStopHigh)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usDBpEngSpeedStopDly)
    {   ERR_ES5_SET_BIT(ERR_ES5_STP_SPEED_HGH);
        usTimer2 = usTimNow;
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorEngSpeedLow()                      */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorEngSpeedLow (INT08U ucFunc)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    INT16U usSpeed, usTimNow;
    usTimNow = usFW100msTimer;
    usSpeed  = usDBmEngSpeed;
    if (ucFunc == SF_DISABLE)
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_SPEED_LOW);
        usTimer1 = usTimNow;
        usTimer2 = usTimNow;
        return;
    }
    /* **************** Warn: Engine Speed Low ************************ */
    if (ERR_ES5_GET_BIT(ERR_ES5_WRN_SPEED_LOW) == 0)
    {   if (usSpeed >= usDBpEngSpeedWarnLow)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usDBpEngSpeedWarnDly)
        {   ERR_ES5_SET_BIT(ERR_ES5_WRN_SPEED_LOW);
            usTimer1 = usTimNow;
        }
    }
    else if (usSpeed < usDBpEngSpeedWarnLow)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpEngSpeedWarnDly)
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_SPEED_LOW);
        usTimer1 = usTimNow;
    }
    /* **************** Stop: Engine Speed Low ************************ */
    if (usSpeed >= usDBpEngSpeedStopLow)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usDBpEngSpeedStopDly)
    {   ERR_ES5_SET_BIT(ERR_ES5_STP_SPEED_LOW);
        usTimer2 = usTimNow;
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorEngSpeedLow()                      */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorEngSpeedDelta (INT16U usPhase)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    INT16U usDelta, usTimNow;
    usTimNow = usFW100msTimer;
    if ((usDBmGensIsWorking != 0) ||
        (usPhase == CTL_PHASE_RATED_UP) ||
        (usPhase == CTL_PHASE_RATED_DOWN) )
    {   usDelta = usDBpEngSpeedRated;
    }
    else if ((usPhase == CTL_PHASE_IDLING_UP) ||
             (usPhase == CTL_PHASE_IDLING_DOWN) )
    {   usDelta = usDBpEngSpeedIdle;
    }
    else if ((usPhase == CTL_PHASE_INIT) ||
             (usPhase == CTL_PHASE_STOPPED) ||
             (usPhase == CTL_PHASE_READY) )
    {   usDelta = 0;
    }
    else
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_SPEED_DELTA);
        usTimer1 = usTimNow;
        usTimer2 = usTimNow;
        return;
    }
    if (usDelta >= usDBmEngSpeed)
    {   usDelta -= usDBmEngSpeed;
    }   else
    {   usDelta  = usDBmEngSpeed - usDelta;
    }
    if (ERR_ES5_GET_BIT(ERR_ES5_WRN_SPEED_DELTA) == 0)
    {   if (usDelta < usDBpEngSpeedDeltaToWarn)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usDBpEngSpeedDeltaErrDly)
        {   ERR_ES5_SET_BIT(ERR_ES5_WRN_SPEED_DELTA);
            usTimer1 = usTimNow;
        }
    }
    else if (usDelta >= usDBpEngSpeedDeltaToWarn)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpEngSpeedDeltaErrDly)
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_SPEED_DELTA);
        usTimer1 = usTimNow;
    }
    if (usDelta < usDBpEngSpeedDeltaToStop)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usDBpEngSpeedDeltaErrDly)
    {   ERR_ES5_SET_BIT(ERR_ES5_STP_SPEED_DELTA);
        usTimer2 = usTimNow;
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorEngSpeedRamp()                     */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorEngSpeedRamp (INT16U usPhase)
{   static INT16U usTimer1 = 0;
    INT16U usTimNow;
    usTimNow = usFW100msTimer;
    if ((usPhase != CTL_PHASE_RAMP_UP) &&
        (usPhase != CTL_PHASE_RAMP_DOWN))
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_RAMP_FAIL);
        usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpEngRampTimeMaxToStop)
    {   ERR_ES5_SET_BIT(ERR_ES5_STP_RAMP_FAIL);
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpEngRampTimeMaxToWarn)
    {   ERR_ES5_SET_BIT(ERR_ES5_WRN_RAMP_FAIL);
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorEngStopping()                      */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorEngStopping (INT16U usPhase)
{   static INT16U usTimer1 = 0;
    INT16U usTimNow;
    usTimNow = usFW100msTimer;
    if (usPhase != CTL_PHASE_STOPPING)
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_STOP_FAIL);
        usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpEngStoppingTimeMax)
    {   ERR_ES5_SET_BIT(ERR_ES5_STP_STOP_FAIL);
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorEngStarting()                      */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorEngTemperature (void)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    static INT16U usTimer4 = 0;
    INT16U usTimNow;
    usTimNow = usFW100msTimer;
    /* ****************** Coolant Temp Warn *************************** */
    if (ERR_ES5_GET_BIT(ERR_ES5_WRN_TEMP_COOL) == 0)
    {   if ((usDBmAinCoolantTemp < usDBpMntrCoolTempToWarn) &&
            (usDBmSwitchCoolantTemp == 0))
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usDBpMntrCoolTempWarnDly)
        {   ERR_ES5_SET_BIT(ERR_ES5_WRN_TEMP_COOL);
            usTimer1 = usTimNow;
        }
    }
    else if ((usDBmAinCoolantTemp >= usDBpMntrCoolTempToWarn) ||
             (usDBmSwitchCoolantTemp != 0))
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpMntrCoolTempWarnDly)
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_TEMP_COOL);
        usTimer1 = usTimNow;
    }
    /* ****************** Coolant Temp Stop *************************** */
    if (usDBmAinCoolantTemp < usDBpMntrCoolTempToStop)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usDBpMntrCoolTempStopDly)
    {   ERR_ES5_SET_BIT(ERR_ES5_STP_TEMP_COOL);
        usTimer2 = usTimNow;
    }
    /* ****************** Oil Temp Warn ******************************* */
    if (ERR_ES5_GET_BIT(ERR_ES5_WRN_TEMP_OIL) == 0)
    {   if ((usDBmAinOilTemp < usDBpMntrOilTempToWarn) &&
            (usDBmSwitchOilTemp == 0))
        {   usTimer3 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer3) > usDBpMntrOilTempWarnDly)
        {   ERR_ES5_SET_BIT(ERR_ES5_WRN_TEMP_OIL);
            usTimer3 = usTimNow;
        }
    }
    else if ((usDBmAinOilTemp >= usDBpMntrOilTempToWarn) ||
             (usDBmSwitchOilTemp != 0))
    {   usTimer3 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer3) > usDBpMntrOilTempWarnDly)
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_TEMP_OIL);
        usTimer3 = usTimNow;
    }
    /* ****************** Oil Temp Stop ******************************* */
    if (usDBmAinOilTemp < usDBpMntrOilTempToStop)
    {   usTimer4 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer4) > usDBpMntrOilTempStopDly)
    {   ERR_ES5_SET_BIT(ERR_ES5_STP_TEMP_OIL);
        usTimer4 = usTimNow;
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorEngPressure()                      */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorEngPressure (void)
{   static INT16U usStart  = 0;
    static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    INT16U usTmp, usTimNow;
    usTimNow = usFW100msTimer;
    /* ************************** Start Flag ************************** */
    if (usDBmEngEngineIsRunning == 0)
    {   usTimer1 = usTimNow;
        usStart  = 0;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpMntrOilPresStartDly)
    {   usStart  = 1;
    }
    /* ************************* Pressure Stop ************************ */
    if (usDBfMntrOilPressCurveOn != 0)
    {   usTmp = SFGet1DMap10(usDBmEngSpeed, &aDBcOilPressStopSpeed[0],
                                            &aDBcOilPressStopPress[0]);
    }   else
    {   usTmp = usDBpMntrOilPresToStop;
    }
    if ((usStart == 0) || (usDBmAinOilPres >= usTmp))
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usDBpMntrOilPresStopDly)
    {   ERR_ES5_SET_BIT(ERR_ES5_STP_PRES_OIL);
    }
    /* ************************* Pressure Warn ************************ */
    if (usDBfMntrOilPressCurveOn != 0)
    {   usTmp = SFGet1DMap10(usDBmEngSpeed, &aDBcOilPressWarnSpeed[0],
                                            &aDBcOilPressWarnPress[0]);
    }   else
    {   usTmp = usDBpMntrOilPresToWarn;
    }
    if (usStart == 0)
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_PRES_OIL);
        usTimer3 = usTimNow;
    }
    else if ((usDBmAinOilPres >= usTmp) && (usDBmSwitchOilPressure == 0))
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_PRES_OIL);
        usTimer3 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer3) > usDBpMntrOilPresWarnDly)
    {   ERR_ES5_SET_BIT(ERR_ES5_WRN_PRES_OIL);
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorEngLevel()                         */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorEngLevel (void)
{   static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    INT16U usTimNow;
    usTimNow = usFW100msTimer;
    /* ******************* Fuel Level Warn **************************** */
    if (ERR_ES5_GET_BIT(ERR_ES5_WRN_LVL_FUEL) == 0)
    {   if ((usDBmAinFuelLevel >= usDBpMntrFuelLevelToWarn) &&
            (usDBmSwitchFuelLevel == 0))
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usDBpMntrFuelLevelWarnDly)
        {   ERR_ES5_SET_BIT(ERR_ES5_WRN_LVL_FUEL);
            usTimer1 = usTimNow;
        }
    }
    else if ((usDBmAinFuelLevel < usDBpMntrFuelLevelToWarn) ||
             (usDBmSwitchFuelLevel != 0))
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpMntrFuelLevelWarnDly)
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_LVL_FUEL);
        usTimer1 = usTimNow;
    }
    /* ******************* Cool Level Warn **************************** */
    if (ERR_ES5_GET_BIT(ERR_ES5_WRN_LVL_COOL) == 0)
    {   if ((usDBmAinCoolantLevel >= usDBpMntrCoolLevelToWarn) &&
            (usDBmSwitchCoolantLevel == 0))
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usDBpMntrCoolLevelWarnDly)
        {   ERR_ES5_SET_BIT(ERR_ES5_WRN_LVL_COOL);
            usTimer2 = usTimNow;
        }
    }
    else if ((usDBmAinCoolantLevel < usDBpMntrCoolLevelToWarn) ||
             (usDBmSwitchCoolantLevel != 0))
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usDBpMntrCoolLevelWarnDly)
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_LVL_COOL);
        usTimer2 = usTimNow;
    }
}
#endif

/* ******************************************************************** */
/*                          SFMonitorEngVoltage()                       */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorEngVoltage (void)
{   static INT16U usStart  = 0;
    static INT16U usTimer1 = 0;
    static INT16U usTimer2 = 0;
    static INT16U usTimer3 = 0;
    static INT16U usTimer4 = 0;
    INT16U usTimNow;
    usTimNow = usFW100msTimer;
    /* ************************** Start Flag ************************** */
    if (usDBmEngEngineIsRunning == 0)
    {   usTimer4 = usTimNow;
        usStart  = 0;
    }
    else if ((INT16U)(usTimNow-usTimer4) > usDBpMntrChargVoltStartDly)
    {   usStart  = 1;
    }
    /* ******************* Charger Voltage Warn *********************** */
    if (usStart == 0)
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_VOLT_CHARG);
        usTimer1 = usTimNow;
    }
    else if (ERR_ES5_GET_BIT(ERR_ES5_WRN_VOLT_CHARG) == 0)
    {   if (usDBmAinChargVoltage >= usDBpMntrChargVoltToWarn)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usDBpMntrChargVoltWarnDly)
        {   ERR_ES5_SET_BIT(ERR_ES5_WRN_VOLT_CHARG);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBmAinChargVoltage < usDBpMntrChargVoltToWarn)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpMntrChargVoltWarnDly)
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_VOLT_CHARG);
        usTimer1 = usTimNow;
    }
    /* ******************* Battary1 Voltage Warn ********************** */
    if (ERR_ES5_GET_BIT(ERR_ES5_WRN_VOLT_BATT1) == 0)
    {   if (usDBmAinBatt1Voltage >= usDBpMntrBatt1VoltToWarn)
        {   usTimer2 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer2) > usDBpMntrBatt1VoltWarnDly)
        {   ERR_ES5_SET_BIT(ERR_ES5_WRN_VOLT_BATT1);
            usTimer2 = usTimNow;
        }
    }
    else if (usDBmAinBatt1Voltage < usDBpMntrBatt1VoltToWarn)
    {   usTimer2 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer2) > usDBpMntrBatt1VoltWarnDly)
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_VOLT_BATT1);
        usTimer2 = usTimNow;
    }
    /* ******************* Battary2 Voltage Warn ********************** */
    if (ERR_ES5_GET_BIT(ERR_ES5_WRN_VOLT_BATT2) == 0)
    {   if (usDBmAinBatt2Voltage >= usDBpMntrBatt2VoltToWarn)
        {   usTimer3 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer3) > usDBpMntrBatt2VoltWarnDly)
        {   ERR_ES5_SET_BIT(ERR_ES5_WRN_VOLT_BATT2);
            usTimer3 = usTimNow;
        }
    }
    else if (usDBmAinBatt2Voltage < usDBpMntrBatt2VoltToWarn)
    {   usTimer3 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer3) > usDBpMntrBatt2VoltWarnDly)
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_VOLT_BATT2);
        usTimer3 = usTimNow;
    }    
}
#endif

/* ******************************************************************** */
/*                          SFMonitorEngFilter()                        */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorEngFilter (void)
{   static INT16U usTimer1 = 0;
    INT16U usTimNow;
    usTimNow = usFW100msTimer;
    if (ERR_ES5_GET_BIT(ERR_ES5_WRN_AIR_FILTER) == 0)
    {   if (usDBmSwitchAirFilter == 0)
        {   usTimer1 = usTimNow;
        }
        else if ((INT16U)(usTimNow-usTimer1) > usDBpMntrAirFilterWarnDly)
        {   ERR_ES5_SET_BIT(ERR_ES5_WRN_AIR_FILTER);
            usTimer1 = usTimNow;
        }
    }
    else if (usDBmSwitchAirFilter != 0)
    {   usTimer1 = usTimNow;
    }
    else if ((INT16U)(usTimNow-usTimer1) > usDBpMntrAirFilterWarnDly)
    {   ERR_ES5_CLR_BIT(ERR_ES5_WRN_AIR_FILTER);
        usTimer1 = usTimNow;
    }
}
#endif

/* ******************************************************************** */
/*                       SFMonitorKeyCmdToStop()                        */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorKeyCmdToStop (INT16U usAutoOrHand)
{   if (usDBmKeyEngineStop != 0)
    {   ERR_ES7_SET_BIT(ERR_ES7_KEY_TO_STOP);
    }
    else if ((usAutoOrHand == 0) &&
             (usDBmKeyEngineStart != 0) &&
             (usDBmSystemPhase == CTL_PHASE_READY))
    {   ERR_ES7_CLR_BIT(ERR_ES7_KEY_TO_STOP);
    }
}
#endif

/* ******************************************************************** */
/*                      SFMonitorSwtCmdToStop()                         */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorSwtCmdToStop (INT16U usAutoOrHand)
{   if (usAutoOrHand == 0)
    {   ERR_ES7_CLR_BIT(ERR_ES7_SWT_TO_STOP);
    }
    else if (usDBmSwitchEngineStop != 0)
    {   ERR_ES7_SET_BIT(ERR_ES7_SWT_TO_STOP);
    }
    else if (usDBmSwitchEngineStart != 0)
    {   ERR_ES7_CLR_BIT(ERR_ES7_SWT_TO_STOP);
    }
}
#endif

/* ******************************************************************** */
/*                        SFMonitorKeyCmdToSwOn()                       */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorKeyCmdToSwOn (INT16U usAutoOrHand)
{   if (usAutoOrHand != 0)
    {   ERR_ES7_SET_BIT(ERR_ES7_KEY_TO_SWON);
    }
    else if ((usDBmKeySwitchOn != 0) &&
             (usDBmSystemPhase == CTL_PHASE_WAIT_KEY_SW))
    {   ERR_ES7_SET_BIT(ERR_ES7_KEY_TO_SWON);
    }
    else if ((usDBmKeySwitchOff != 0) &&
             (usDBmSystemPhase == CTL_PHASE_WORKING))
    {   ERR_ES7_CLR_BIT(ERR_ES7_KEY_TO_SWON);
    }
}
#endif

/* ******************************************************************** */
/*                      SFMonitorKeyAutoOrManual()                      */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorKeyAutoOrManual (void)
{   if (usDBmKeyModeManual != 0)
    {   ERR_ES7_CLR_BIT(ERR_ES7_KEY_TO_AUTO);
    }
    else if (usDBmKeyModeAuto != 0)
    {   ERR_ES7_SET_BIT(ERR_ES7_KEY_TO_AUTO);
    }
}
#endif

/* ******************************************************************** */
/*                      SFMonitorEepDataError()                         */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
void SFMonitorEepDataError (void)
{   if (DB_STS_GET_BIT(DB_STS_ERR_READ_MSK) != 0)
    {   ERR_ES6_SET_BIT(ERR_ES6_STP_DATA_READ);
    }
    if (DB_STS_GET_BIT(DB_STS_ERR_CHECK_MSK) != 0)
    {   ERR_ES6_SET_BIT(ERR_ES6_STP_DATA_CHECK);
    }
    if (DB_STS_GET_BIT(DB_STS_ERR_WRITE_MSK) != 0)
    {   ERR_ES6_SET_BIT(ERR_ES6_STP_DATA_WRITE);
    }   else
    {   ERR_ES6_CLR_BIT(ERR_ES6_STP_DATA_WRITE);
    }
}
#endif

/* ******************************************************************** */
/*                       SFGetEngStsStopped()                           */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT16U SFGetEngStsStopped (INT16U usSpeed)
{   static INT32U uiCount = 0;
    if (usSpeed > usDBpEngSpeedStart1)  //检测8次后转速小于设定转速值1，则判断停机
    {   uiCount = 0;
        return 0;
    }
    else if (uiCount < 8)  
    {   uiCount++;
        return 0;
    }
    return 1;
}
#endif

/* ******************************************************************** */
/*                       SFGetEngStsRunning()                           */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT16U SFGetEngStsRunning (INT16U usSpeed)
{   static INT32U uiCount = 0;
    if (usSpeed <= usDBpEngSpeedStart2)  //检测8次后转速大于设定转速值2，则判断处于运行状态
    {   uiCount = 0;
        return 0;
    }
    else if (uiCount < 8)
    {   uiCount++;
        return 0;
    }
    return 1;
}
#endif

/* ******************************************************************** */
/*                        SFGetEngStsIdling()                           */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT16U SFGetEngStsIdling (INT16U usSpeed)
{   static INT32U uiCount = 0;
    if((usSpeed < usDBpEngSpeedIdleMin) ||
       (usSpeed > usDBpEngSpeedIdleMax))  //检测8次后转速大于设定怠速最小值，小于设定怠速最大值，则判断处于怠速状态
    {   uiCount = 0;
        return 0;
    }
    else if (uiCount < 8)
    {   uiCount++;
        return 0;
    }
    return 1;
}
#endif

/* ******************************************************************** */
/*                        SFGetEngStsRated()                            */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT16U SFGetEngStsRated (INT16U usSpeed)
{   static INT32U uiCount = 0;
    if (usSpeed < usDBpEngSpeedRatedMin)
    {   uiCount = 0;
        return 0;
    }
    else if (uiCount < 8)
    {   uiCount++;
        return 0;
    }
    return 1;
}
#endif

/* ******************************************************************** */
/*                       SFGetAirHeaterActive()                         */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT16U SFGetAirHeaterActive (INT16U usPhase)
{   static INT16U usTimer1 = 0;
    static INT16U usActive = 0;
    INT16U usDelay, usTimNow;
    usTimNow = usFW100msTimer;
    usDelay  = usDBmAinCoolantTemp;
    if (usDelay >= usDBpEngTempHeaterWarm)
    {   usDBmEngHeaterDuration = 0;
    }   else
    {   usDBmEngHeaterDuration = SFInterp16u (usDelay, usDBpEngTempHeaterCold,
        usDBpEngTempHeaterWarm, usDBpTimeOfHeaterAtCold, usDBpTimeOfHeaterAtWarm);
    }
    usDelay = usTimNow - usTimer1;
    if ((usPhase != CTL_PHASE_STARTING) ||
        (usDBmEngEngineIsRunning != 0) ||
        (usDBmEngHeaterDuration == 0)  ||
        (usDBmSwitchHeater == 0))
    {   usTimer1 = usTimNow - CTL_OFFTIME_HEATER;
        usActive = 0;
    }
    else if (usActive == 0)
    {   if (usDelay >= CTL_OFFTIME_HEATER)
        {   usTimer1 = usTimNow;
            usActive = 1;
        }
    }
    else if (usDelay >= usDBmEngHeaterDuration)
    {   usTimer1 = usTimNow;
        usActive = 0;
    }
    return usActive;
}
#endif

/* ******************************************************************** */
/*                         SFGetOilPumpActive()                        */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT16U SFGetOilPumpActive (INT16U usPhase)
{   static INT16U usTimer1 = 0;
    static INT16U usActive = 0;
    INT16U usDelay;
    usDelay = usFW100msTimer - usTimer1;
    if ((usPhase != CTL_PHASE_STARTING) ||
        (usDBmEngEngineIsRunning != 0) ||
        (usDBmEngHeaterOutput != 0) ||
        (usDBmSwitchOilPump == 0))
    {   usTimer1 = usFW100msTimer - CTL_OFFTIME_OILPUMP;
        usActive = 0;
    }
    else if (usActive == 0)
    {   if (usDelay >= CTL_OFFTIME_OILPUMP)
        {   usTimer1 = usFW100msTimer;
            usActive = 1;
        }
    }
    else if ((usDelay >= usDBpEngOilPumpOnTime) ||
       (usDBmAinOilPres >= usDBpEngOilPumpOffPress))
    {   usTimer1 = usFW100msTimer;
        usActive = 0;
    }
    return usActive;
}
#endif

/* ******************************************************************** */
/*                        SFGetStarterActive()                         */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT16U SFGetStarterActive (INT16U usPhase, INT16U usAutoOrHand)
{   static INT16U usTimer1 = 0;
    static INT16U usActive = 0;
    INT16U usDelay, usTimNow;
    usTimNow = usFW100msTimer;
    usDelay  = usTimNow - usTimer1;
    if (ERR_ES5_GET_BIT(ERR_ES5_STP_START_FAIL) != 0)
    {   usTimer1 = usTimNow - usDBpTimeOfStarterOff;
        usActive = 0;
    }
    else if (((usAutoOrHand != 0) &&
              (usDBmEngStartFailTimes >= usDBpEngAutoStartTimesMax)) ||
             ((usAutoOrHand == 0) &&
              (usDBmEngStartFailTimes >= usDBpEngHandStartTimesMax)) )
    {   ERR_ES5_SET_BIT(ERR_ES5_STP_START_FAIL);
        usTimer1 = usTimNow - usDBpTimeOfStarterOff;
        usActive = 0;
    }
    else if ((usPhase != CTL_PHASE_STARTING) ||
             (usDBmEngEngineIsRunning != 0) ||
             (usDBmEngOilPumpOutput != 0) ||
             (usDBmEngHeaterOutput != 0) )
    {   usTimer1 = usTimNow - usDBpTimeOfStarterOff;
        usActive = 0;
    }
    else if (usActive == 0)
    {   if (usDelay >= usDBpTimeOfStarterOff)
        {   uiDBhStartTimes32B += 1;
            usTimer1 = usTimNow;
            usActive = 1;
        }
    }
    else if (usDelay >= usDBpTimeOfStarterOn)
    {   usDBmEngStartFailTimes += 1;
        usTimer1 = usTimNow;
        usActive = 0;
    }
    return usActive;
}
#endif

/* ******************************************************************** */
/*                      SFGetFuelSupplyActive()                        */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT16U SFGetFuelSupplyActive (INT16U usPhase)
{   if ((usPhase == CTL_PHASE_INIT) ||
        (usPhase == CTL_PHASE_STOPPED) ||
        (usPhase == CTL_PHASE_READY) ||
        (usPhase == CTL_PHASE_EMERGENCY) ||
        (usPhase == CTL_PHASE_STOPPING) )
    {   return 0;
    }   else
    {   return 1;
    }
}
#endif

/* ******************************************************************** */
/*                         SFGetCoolantFanActive()                     */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT16U SFGetCoolantFanActive (void)
{   static INT16U usTimer1 = 0;
    static INT16U usActive = 0;
    INT16U usTemp, usDelay;
    usTemp  = usDBmAinCoolantTemp;
    usDelay = usFW100msTimer - usTimer1;
    if (usDBmEngEngineIsRunning != 0)
    {   usTimer1 = usFW100msTimer;
        if (usTemp >= usDBpEngCoolFanOnTemp)
        {   usActive = 1;
        }   else if ((usTemp + SF_TMPSUB_TO_16U(5)) <= usDBpEngCoolFanOnTemp)
        {   usActive = 0;
        }
    }
    else if (usActive != 0)
    {   if (usDelay >= usDBpEngCoolFanOffDly)
        {   usActive = 0;
        }
    }
    return usActive;
}
#endif

/* ******************************************************************** */
/*                         SFGetSpeedRatedActive()                     */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT16U SFGetSpeedRatedActive (INT16U usPhase)
{   if ((usPhase == CTL_PHASE_INIT) ||
        (usPhase == CTL_PHASE_STOPPED) ||
        (usPhase == CTL_PHASE_READY) ||
        (usPhase == CTL_PHASE_MAIN_SW_OFF) ||
        (usPhase == CTL_PHASE_STARTING) ||
        (usPhase == CTL_PHASE_STOPPING) ||
        (usPhase == CTL_PHASE_IDLING_UP) ||
        (usPhase == CTL_PHASE_IDLING_DOWN) ||
        (usPhase == CTL_PHASE_RAMP_DOWN) ||
        (usPhase == CTL_PHASE_EMERGENCY) )
    {   return 0;
    }   else
    {   return 1;
    }
}
#endif

/* ******************************************************************** */
/*                         SFGetMainSwOnOutput()                        */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT16U SFGetMainSwOnOutput (INT16U usCtrl, INT16U usOutDly)
{   static INT16U usTimer1 = 0;
    static INT16U usOutput = 0;
    static INT16U usCtrlOld = 1;
    INT16U usDelay, usTimNow;
    usTimNow = usFW100msTimer;
    usDelay  = usTimNow - usTimer1;
    if (usOutDly == 0)
    {   usTimer1  = usTimNow;
        usOutput  = usCtrl;
    }
    else if ((usCtrl != 0) && (usCtrlOld == 0))
    {   usTimer1  = usTimNow;
        usOutput  = 1;
    }
    else if (usOutput == 0)
    {   usTimer1  = usTimNow;
    }
    else if (usDelay >= usOutDly)
    {   usTimer1  = usTimNow;
        usOutput  = 0;
    }
    usCtrlOld = usCtrl;
    return usOutput;
}
#endif

/* ******************************************************************** */
/*                         SFGetMainSwOffOutput()                       */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT16U SFGetMainSwOffOutput (INT16U usCtrl, INT16U usOutDly)
{   static INT16U usTimer1 = 0;
    static INT16U usOutput = 0;
    static INT16U usCtrlOld = 0;
    INT16U usDelay, usTimNow;
    usTimNow = usFW100msTimer;
    usDelay  = usTimNow - usTimer1;
    if (usOutDly == 0)
    {   usTimer1  = usTimNow;
        usOutput  = usCtrl == 0 ? 1 : 0;
    }
    else if ((usCtrl == 0) && (usCtrlOld != 0))
    {   usTimer1  = usTimNow;
        usOutput  = 1;
    }
    else if (usOutput == 0)
    {   usTimer1  = usTimNow;
    }
    else if (usDelay >= usOutDly)
    {   usTimer1  = usTimNow;
        usOutput  = 0;
    }
    usCtrlOld = usCtrl;
    return usOutput;
}
#endif

/* ******************************************************************** */
/*                         SFGetGensSwOnOutput()                        */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT16U SFGetGensSwOnOutput (INT16U usCtrl, INT16U usOutDly)
{   static INT16U usTimer1 = 0;
    static INT16U usOutput = 0;
    static INT16U usCtrlOld = 1;
    INT16U usDelay, usTimNow;
    usTimNow = usFW100msTimer;
    usDelay  = usTimNow - usTimer1;
    if (usOutDly == 0)
    {   usTimer1  = usTimNow;
        usOutput  = usCtrl;
    }
    else if ((usCtrl != 0) && (usCtrlOld == 0))
    {   usTimer1  = usTimNow;
        usOutput  = 1;
    }
    else if (usOutput == 0)
    {   usTimer1  = usTimNow;
    }
    else if (usDelay >= usOutDly)
    {   usTimer1  = usTimNow;
        usOutput  = 0;
    }
    usCtrlOld = usCtrl;
    return usOutput;
}
#endif

/* ******************************************************************** */
/*                         SFGetGensSwOffOutput()                       */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)
INT16U SFGetGensSwOffOutput (INT16U usCtrl, INT16U usOutDly)
{   static INT16U usTimer1 = 0;
    static INT16U usOutput = 0;
    static INT16U usCtrlOld = 0;
    INT16U usDelay, usTimNow;
    usTimNow = usFW100msTimer;
    usDelay  = usTimNow - usTimer1;
    if (usOutDly == 0)
    {   usTimer1  = usTimNow;
        usOutput  = usCtrl == 0 ? 1 : 0;
    }
    else if ((usCtrl == 0) && (usCtrlOld != 0))
    {   usTimer1  = usTimNow;
        usOutput  = 1;
    }
    else if (usOutput == 0)
    {   usTimer1  = usTimNow;
    }
    else if (usDelay >= usOutDly)
    {   usTimer1  = usTimNow;
        usOutput  = 0;
    }
    usCtrlOld = usCtrl;
    return usOutput;
}
#endif

/* ******************************************************************** */
/*                      SFGensBreakerTripMonitor()                      */
/* ******************************************************************** */
#if (SF_GENS_FUNCTION_ON == 1)

void SFGensBreakerTripMonitor (void)
{ /*  static INT16U usTimer1 = 0;
    if((usDBpDinAssigGensFeedback >= SF_NUM_OF_SW_IN) ||
       (usDBmSwitchGensFeedback != 0) ||
       (usDBmGensBreakerOn == 0) )
    {   usTimer1 = usFW100msTimer;
    }
    else if ((INT16U)(usFW100msTimer-usTimer1) > usDBpBreakerTripChkDly)
    {   ERR_ES2_SET_BIT(ERR_ES2_BREAKER_TRIP);
    } */
}

#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */