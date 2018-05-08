/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File RTCCortex.c                        */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   RTC_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                                 const                                */
/* ******************************************************************** */
const INT08U aRTCSamurai[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

/* ******************************************************************** */
/*                               RTCInit ()                             */
/* ******************************************************************** */
#if (RTC_FUNCTION_ON == 1)
void RTCInit (void)
{   INT32U uiCnt;
    uiRTCStatus   = RTC_STS_ERROR;
    RCC->APB1ENR |= RCC_APB1ENR_BKPEN;
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR      |= PWR_CR_DBP;                /* Enable write access   */
    RCC->BDCR     = RCC_BDCR_LSEON             /* Enable LSE oscillator */
                 |  RCC_BDCR_RTCSEL_0          /* 01: LSE as RTC clock  */
                 |  RCC_BDCR_RTCEN;            /* RTC clock enable      */
    uiCnt = 8000000ul;
    while (uiCnt--)                            /* Wait for LSE Ready    */
    {   if ((RCC->BDCR & RCC_BDCR_LSERDY) != 0)
        {   break;
        }
    }
    if (uiCnt == 0)
    {   RCC->BDCR = 0;                         /* Stop LSE oscillator   */
        PWR->CR &= ~PWR_CR_DBP;                /* Inhibit write access  */
        return;
    }
    uiCnt = 100000ul;
    while (uiCnt--)                            /* Wait for RTC process  */
    {   if ((RTC->CRL & RTC_CRL_RTOFF) != 0)
        {   break;
        }
    }
    if (uiCnt == 0)
    {   RCC->BDCR = 0;                         /* Stop LSE oscillator   */
        PWR->CR &= ~PWR_CR_DBP;                /* Inhibit write access  */
        return;
    }
    RTC->CRL  = RTC_CRL_CNF;                   /* Enter RTC config mode */
    RTC->PRLH = 0;                             /* Upper RTC prescaler   */
    RTC->PRLL = 32768 - 1;                     /* LSE frequency         */
    RTC->CRL  = 0;                             /* Exit RTC config mode  */
    while (uiCnt--)                            /* Wait for RTC process  */
    {   if ((RTC->CRL & RTC_CRL_RTOFF) != 0)
        {   break;
        }
    }
    while (uiCnt--)                            /* Wait for RTC sync     */
    {   if ((RTC->CRL & RTC_CRL_RSF) != 0)
        {   break;
        }
    }
    if (uiCnt == 0)
    {   RCC->BDCR = 0;                         /* Stop LSE oscillator   */
        PWR->CR &= ~PWR_CR_DBP;                /* Inhibit write access  */
        return;
    }
    PWR->CR &= ~PWR_CR_DBP;                    /* Inhibit write access  */
    uiRTCStatus = RTC_STS_NORMAL;
}
#endif

/* ******************************************************************** */
/*                              RTCGetUtc ()                            */
/* ******************************************************************** */
#if (RTC_FUNCTION_ON == 1)
INT08U RTCGetUtc (INT32U *pUtc)
{   INT32U uiT1, uiT2;
    if (uiRTCStatus != RTC_STS_NORMAL)
    {   return FALSE;
    }
    uiT1  = RTC->CNTH << 16;
    uiT1 |= RTC->CNTL;
    uiT2  = uiT1 + 1;
    while (uiT1 != uiT2)
    {   uiT2  = uiT1;
        uiT1  = RTC->CNTH << 16;
        uiT1 |= RTC->CNTL;
    }
    *pUtc = uiT1;
    return TRUE;
}
#endif

/* ******************************************************************** */
/*                              RTCSetUtc ()                            */
/* ******************************************************************** */
#if (RTC_FUNCTION_ON == 1)
INT08U RTCSetUtc (INT32U uiUtc)
{   INT32U uiCnt;
    if (uiRTCStatus != RTC_STS_NORMAL)
    {   return FALSE;
    }
    PWR->CR |= PWR_CR_DBP;                     /* Enable write access   */
    uiCnt = 100000;
    while (uiCnt--)                            /* Wait for RTC process  */
    {   if ((RCC->BDCR & RTC_CRL_RTOFF) != 0)
        {   break;
        }
    }
    if (uiCnt == 0)
    {   PWR->CR &= ~PWR_CR_DBP;
        return FALSE;
    }
    RTC->CRL  = RTC_CRL_CNF;                   /* Enter RTC config mode */
    RTC->CNTL = (INT16U)(uiUtc);               /* Set time counter low  */
    RTC->CNTH = (INT16U)(uiUtc >> 16);         /* Set time counter high */
    RTC->PRLH = 0;                             /* Upper RTC prescaler   */
    RTC->PRLL = 32768 - 1;                     /* LSE frequency         */
    RTC->CRL  = 0;                             /* Exit RTC config mode  */
    while (uiCnt--)                            /* Wait for RTC process  */
    {   if ((RCC->BDCR & RTC_CRL_RTOFF) != 0)
        {   break;
        }
    }
    PWR->CR &= ~PWR_CR_DBP;
    return uiCnt == 0 ? FALSE : TRUE;
}
#endif

/* ******************************************************************** */
/*                              RTCGetTime ()                           */
/* ******************************************************************** */
#if (RTC_FUNCTION_ON == 1)
INT08U RTCGetTime (RTC_TIME_STR *pRtc)
{   INT32U uiUtc, n, i, d;
    if (RTCGetUtc(&uiUtc) == FALSE)
    {   return FALSE;
    }
    uiUtc      += (INT32S)(RTC_RTC_TDIF * 3600);
    pRtc->sec   = (INT08U)(uiUtc % 60);
    uiUtc      /= 60;
    pRtc->min   = (INT08U)(uiUtc % 60);
    uiUtc      /= 60;
    pRtc->hour  = (INT08U)(uiUtc % 24);
    uiUtc      /= 24;
    pRtc->wday  = (INT08U)((uiUtc + 4) % 7);
    pRtc->year  = (INT16U)(1970 + uiUtc / 1461 * 4);
    uiUtc      %= 1461;
    n           = ((uiUtc >= 1096) ? uiUtc - 1 : uiUtc) / 365;
    pRtc->year += n;
    uiUtc      -= n * 365 + (n > 2 ? 1 : 0);
    for (i=0; i<12; i++)
    {   d = aRTCSamurai[i];
        if ((i == 1) && (n == 2))
        {   d++;
        }
        if (uiUtc < d)
        {   break;
        }
        uiUtc -= d;
    }
    pRtc->month = (INT08U)(1 + i);
    pRtc->mday  = (INT08U)(1 + uiUtc);
    return TRUE;
}
#endif

/* ******************************************************************** */
/*                              RTCSetTime ()                           */
/* ******************************************************************** */
#if (RTC_FUNCTION_ON == 1)
INT08U RTCSetTime (RTC_TIME_STR *pRtc)
{   INT32U uiUtc, i, y;
    y = pRtc->year - 1970;
    if ((y > 2106) || (pRtc->month == 0) || (pRtc->mday == 0))
    {   return FALSE;
    }
    uiUtc  = y / 4 * 1461;
    y     %= 4;
    uiUtc += y * 365 + (y > 2 ? 1 : 0);
    for (i=0; i<12 && i+1 < pRtc->month; i++)
    {   uiUtc += aRTCSamurai[i];
        if ((i == 1) && (y == 2))
        {   uiUtc++;
        }
    }
    uiUtc +=  pRtc->mday - 1;
    uiUtc *=  86400;
    uiUtc +=  pRtc->hour * 3600 + pRtc->min * 60 + pRtc->sec;
    uiUtc -= (INT32S)(RTC_RTC_TDIF * 3600);
    return RTCSetUtc(uiUtc);
}
#endif

/* ******************************************************************** */
/*                              get_fattime ()                          */
/* ******************************************************************** */
#if (RTC_FUNCTION_ON == 1)
INT32U get_fattime (void)
{   RTC_TIME_STR sRtc;
    if (RTCGetTime(&sRtc) == FALSE)
    {   return 0;
    }
    return  ((INT32U)(sRtc.year - 1980) << 25)
          | ((INT32U)sRtc.month << 21)
          | ((INT32U)sRtc.mday << 16)
          | ((INT32U)sRtc.hour << 11)
          | ((INT32U)sRtc.min << 5)
          | ((INT32U)sRtc.sec >> 1);
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */