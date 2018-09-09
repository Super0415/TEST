/* ******************************************************************** */
/*                       Source File FFTBus10.c                         */
/*                            By: Wu Xuekui                             */
/*                              2017-11-02                              */
/* ******************************************************************** */

#define   FFT_GLOBALS
#include "TYPCortex.h"
#include "arm_math.h"
#include "arm_const_structs.h"
#include "arm_common_tables.h"

/* ******************************************************************** */
/*                              FFTInit ()                              */
/* ******************************************************************** */
#if (FFT_FFT_FUNCTION_ON == 1)
void FFTInit (void)
{   usFFTTimer = 0;
    usFFTStatus = 0;
    (void)FFTCmdBufInit();
    (void)SFFill32f(fFFTDatFilter,0.0f,FFT_FFT_DAT_SIZE/2);
}
#endif

/* ******************************************************************** */
/*                          FFTStart ()                                 */
/* ******************************************************************** */
#if (FFT_FFT_FUNCTION_ON == 1)
void FFTStart (void)
{
}
#endif

/* ******************************************************************** */
/*                            FFTTaskLoop ()                            */
/* ******************************************************************** */
#if (FFT_FFT_FUNCTION_ON == 1)
void FFTTaskLoop (void)
{   INT08U ucTmp, ucErr;
    INT16U usTim;
    while (1)
    {   ucTmp = FFTGetCmdChar(FFT_RX_TO_TICKS, &ucErr);
        if ((ucErr == FFT_NO_ERR) && (ucTmp == FFT_CMD_DAT_RDY))
        {   usTim = XIO_GET_FREE_TIMER();
           #if (FFT_ALGORITHM_TEST_ON == 1)
            FFTFillTestData(&fFFTDatBuffer[0], FFT_FFT_DAT_SIZE);
           #endif
            arm_cfft_f32(&arm_cfft_sR_f32_len64, fFFTDatBuffer, 0, 1);
            SFGetPowerSpectrum(fFFTDatBuffer, fFFTDatBuffer, FFT_FFT_DAT_SIZE/2);
           #if (FFT_AMPLITUDE_SPEC_ON == 1)
            SFGetSqrt32f(fFFTDatBuffer, fFFTDatBuffer, FFT_FFT_DAT_SIZE/2);
           #endif
            FFTUpdateFilter(fFFTDatBuffer, fFFTDatFilter, FFT_FFT_DAT_SIZE/2);
            FFTUpdateMeasu(fFFTDatFilter, &usDBmFftResult[0], FFT_FFT_DAT_SIZE/2);
            FFT_STS_CLR_BIT(FFT_STS_BUFF_BUSY);
            usFFTCalcTime = XIO_GET_FREE_TIMER() - usTim;
        }
    }
}
#endif

/* ******************************************************************** */
/*                          FFTUpdateMeasu()                             */
/* ******************************************************************** */
#if (FFT_FFT_FUNCTION_ON == 1)
void FFTFillTestData (FP32 *pDest, INT16U usSize)
{   INT16U usSiz;
    const FP32 *pSour;
    usSiz = usSize / 2;
    pSour = &twiddleCoef_64[0];
    while (usSiz--)
    {   *pDest++ = *pSour;
        *pDest++ = 0.0f;
        pSour   += 4;
    }
    usSiz = usSize / 2;
    pSour = &twiddleCoef_64[0];
    while (usSiz--)
    {   *pDest++ = *pSour;
        *pDest++ = 0.0f;
        pSour   += 4;
    }
}
#endif

/* ******************************************************************** */
/*                          FFTUpdateMeasu()                            */
/* ******************************************************************** */
#if (FFT_FFT_FUNCTION_ON == 1)
void FFTUpdateMeasu (FP32 *pSour, INT16U *pDest, INT16U usSize)
{   INT16U usSiz;
    FP32   fpSum;
    *pSour = 0.0f;
    fpSum  = SFGetSum32f(pSour,usSize);
    if (fpSum != 0.0f)
    {   fpSum  = 10000.0f / fpSum;
    }
    usSiz = usSize / 4;
    while (usSiz--)
    {   *pDest++ = (INT16U)((*pSour++) * fpSum);
        *pDest++ = (INT16U)((*pSour++) * fpSum);
        *pDest++ = (INT16U)((*pSour++) * fpSum);
        *pDest++ = (INT16U)((*pSour++) * fpSum);
    }
    usSiz = usSize % 4;
    while (usSiz--)
    {   *pDest++ = (INT16U)((*pSour++) * fpSum);
    }
}
#endif

/* ******************************************************************** */
/*                          FFTUpdateFilter()                             */
/* ******************************************************************** */
#if (FFT_FFT_FUNCTION_ON == 1)
void FFTUpdateFilter (FP32 *pSour, FP32 *pFilt, INT16U usSize)
{   INT16U usSiz;
    usSiz = usSize / 4;
    while (usSiz--)
    {   *pFilt = *pFilt * FFT_FFT_FILTER + *pSour;
        pSour++;
        pFilt++;
        *pFilt = *pFilt * FFT_FFT_FILTER + *pSour;
        pSour++;
        pFilt++;
        *pFilt = *pFilt * FFT_FFT_FILTER + *pSour;
        pSour++;
        pFilt++;
        *pFilt = *pFilt * FFT_FFT_FILTER + *pSour;
        pSour++;
        pFilt++;
    }
    usSiz = usSize % 4;
    while (usSiz--)
    {   *pFilt = *pFilt * FFT_FFT_FILTER + *pSour;
        pSour++;
        pFilt++;
    }
}
#endif

/* ******************************************************************** */
/*                          FFTCmdBufInit()                             */
/* ******************************************************************** */
#if (FFT_FFT_FUNCTION_ON == 1)
void FFTCmdBufInit (void)
{   FFT_RING_STR *pbuf;
    pbuf = &sFFTRingBuf;
    pbuf->usRingBufRxCtr   =  0;
    pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxOutPtr = &pbuf->ucRingBufRx[0];
    pbuf->pRingBufRxSem    =  OSSemCreate(0);
}
#endif

/* ******************************************************************** */
/*                          FFTPutCmdChar()                              */
/* ******************************************************************** */
#if (FFT_FFT_FUNCTION_ON == 1)
void FFTPutCmdChar (INT08U c)
{   FFT_RING_STR *pbuf;
    pbuf = &sFFTRingBuf;
    if (pbuf->usRingBufRxCtr < FFT_RX_BUF_SIZE)
    {   pbuf->usRingBufRxCtr++;
        *pbuf->pRingBufRxInPtr++ = c;
        if (pbuf->pRingBufRxInPtr == &pbuf->ucRingBufRx[FFT_RX_BUF_SIZE])
        {   pbuf->pRingBufRxInPtr  = &pbuf->ucRingBufRx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufRxSem);
    }
}
#endif

/* ******************************************************************** */
/*                           FFTGetCmdChar()                            */
/* ******************************************************************** */
#if (FFT_FFT_FUNCTION_ON == 1)
INT08U FFTGetCmdChar (INT16U to, INT08U *err)
{   OS_CPU_SR cpu_sr = 0;
    INT08U c, oserr;
    FFT_RING_STR *pbuf;
    pbuf = &sFFTRingBuf;
    (void)OSSemPend(pbuf->pRingBufRxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   *err   = FFT_ERR_RX_TIMEOUT;
        return 0;
    }
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufRxCtr == 0)
    {   *err = FFT_ERR_RX_TIMEOUT;
        OS_EXIT_CRITICAL();
        return 0;
    }
    pbuf->usRingBufRxCtr--;
    c = *pbuf->pRingBufRxOutPtr++;
    if (pbuf->pRingBufRxOutPtr == &pbuf->ucRingBufRx[FFT_RX_BUF_SIZE])
    {   pbuf->pRingBufRxOutPtr  = &pbuf->ucRingBufRx[0];
    }
    OS_EXIT_CRITICAL();
    *err = FFT_NO_ERR;
    return c;
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */

