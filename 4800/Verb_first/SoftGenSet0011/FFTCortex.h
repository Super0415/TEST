/* ******************************************************************** */
/*                      FFT Software Version 1.0                        */
/*                       Header File FFTCortex.h                        */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _FFTCORTEX_H

#define _FFTCORTEX_H

#ifdef   FFT_GLOBALS

#define  FFT_EXT  

#else

#define  FFT_EXT extern

#endif

/* ******************************************************************** */
/*  FFT_VERSION  = 10xx: VEC1000 Application                            */
/*  FFT_VERSION  = 40xx: VEC4000 Application                            */
/*  FFT_VERSION  = 68xx: VEC6800 Application                            */
/*  FFT_VERSION  = 69xx: VEC6900 Application                            */
/*  FFT_VERSION  = 76xx: GEC7600 Application                            */
/*  FFT_VERSION  = 78xx: GEC7800 Application                            */
/*  FFT_VERSION  = 80xx: VEC8000 Application                            */
/*  FFT_VERSION  = 90xx: VEC9000 Application                            */
/*  FFT_VERSION  = 96xx: VEC9600 Application                            */
/* ******************************************************************** */

#define FFT_VERSION          7600

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define FFT_1000_COMMON_ON      0
#define FFT_4000_COMMON_ON      0
#define FFT_6800_COMMON_ON      0
#define FFT_6900_COMMON_ON      0
#define FFT_7600_COMMON_ON      0
#define FFT_7800_COMMON_ON      0
#define FFT_8000_COMMON_ON      0
#define FFT_9000_COMMON_ON      0
#define FFT_9600_COMMON_ON      0
#if   ((FFT_VERSION / 100)  == 10)
#undef  FFT_1000_COMMON_ON
#define FFT_1000_COMMON_ON      1
#endif
#if   ((FFT_VERSION / 100)  == 40)
#undef  FFT_4000_COMMON_ON
#define FFT_4000_COMMON_ON      1
#endif
#if   ((FFT_VERSION / 100)  == 68)
#undef  FFT_6800_COMMON_ON
#define FFT_6800_COMMON_ON      1
#endif
#if   ((FFT_VERSION / 100)  == 69)
#undef  FFT_6900_COMMON_ON
#define FFT_6900_COMMON_ON      1
#endif
#if   ((FFT_VERSION / 100)  == 76)
#undef  FFT_7600_COMMON_ON
#define FFT_7600_COMMON_ON      1
#endif
#if   ((FFT_VERSION / 100)  == 78)
#undef  FFT_7800_COMMON_ON
#define FFT_7800_COMMON_ON      1
#endif
#if   ((FFT_VERSION / 100)  == 80)
#undef  FFT_8000_COMMON_ON
#define FFT_8000_COMMON_ON      1
#endif
#if   ((FFT_VERSION / 100)  == 90)
#undef  FFT_9000_COMMON_ON
#define FFT_9000_COMMON_ON      1
#endif
#if   ((FFT_VERSION / 100)  == 96)
#undef  FFT_9600_COMMON_ON
#define FFT_9600_COMMON_ON      1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define FFT_CPU_9S12_ON         0
#define FFT_CPU_POWERPC_ON      0
#define FFT_CPU_STM32F1_ON      0
#define FFT_FFT_FUNCTION_ON     0
#if    (FFT_1000_COMMON_ON   == 1)
#undef  FFT_CPU_9S12_ON
#define FFT_CPU_9S12_ON         1
#endif
#if    (FFT_4000_COMMON_ON   == 1)
#undef  FFT_CPU_9S12_ON
#define FFT_CPU_9S12_ON         1
#endif
#if    (FFT_6800_COMMON_ON   == 1)
#undef  FFT_CPU_9S12_ON
#define FFT_CPU_9S12_ON         1
#endif
#if    (FFT_6900_COMMON_ON   == 1)
#undef  FFT_CPU_POWERPC_ON
#define FFT_CPU_POWERPC_ON      1
#endif
#if    (FFT_7600_COMMON_ON   == 1)
#undef  FFT_CPU_STM32F1_ON
#define FFT_CPU_STM32F1_ON      1
#undef  FFT_FFT_FUNCTION_ON
#define FFT_FFT_FUNCTION_ON     1
#endif
#if    (FFT_7800_COMMON_ON   == 1)
#undef  FFT_CPU_STM32F1_ON
#define FFT_CPU_STM32F1_ON      1
#undef  FFT_FFT_FUNCTION_ON
#define FFT_FFT_FUNCTION_ON     1
#endif
#if    (FFT_8000_COMMON_ON   == 1)
#undef  FFT_CPU_POWERPC_ON
#define FFT_CPU_POWERPC_ON      1
#endif
#if    (FFT_9000_COMMON_ON   == 1)
#undef  FFT_CPU_POWERPC_ON
#define FFT_CPU_POWERPC_ON      1
#endif
#if    (FFT_9600_COMMON_ON   == 1)
#undef  FFT_CPU_POWERPC_ON
#define FFT_CPU_POWERPC_ON      1
#endif

/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define FFT_TRUE                1
#define FFT_FALSE               0
#define FFT_NO_ERR              0
#define FFT_ERR_EVENT_TYPE      1
#define FFT_ERR_PEND_ISR        2
#define FFT_ERR_BAD_CH          3
#define FFT_ERR_RX_EMPTY        4
#define FFT_ERR_TX_FULL         5
#define FFT_ERR_TX_EMPTY        6
#define FFT_ERR_RX_TIMEOUT      7
#define FFT_ERR_TX_TIMEOUT      8
#define FFT_STS_NORMAL         (INT16U)0
#define FFT_STS_BUFF_BUSY      (INT16U)1
#define FFT_STS_FFT_FINISH     (INT16U)2
#define FFT_STS_GET_BIT(m)     (usFFTStatus & (m))
#define FFT_STS_CLR_BIT(m)      usFFTStatus &= ~(m)
#define FFT_STS_SET_BIT(m)      usFFTStatus |= (m)

/* ******************************************************************** */
/*                          Control Definition                          */
/* ******************************************************************** */
#define FFT_CMD_DAT_RDY        (INT08U)0x6A
#define FFT_ALGORITHM_TEST_ON   0
#define FFT_AMPLITUDE_SPEC_ON   0
#define FFT_FFT_DAT_SIZE        64
#define FFT_FFT_FILTER          0.95f
#define FFT_RX_BUF_SIZE         4
#define FFT_RX_TO_TICKS         10

/* ******************************************************************** */
/*                           Type Definition                            */
/* ******************************************************************** */
typedef struct
{   INT16U      usRingBufRxCtr;
    OS_EVENT   *pRingBufRxSem;
    INT08U     *pRingBufRxInPtr;
    INT08U     *pRingBufRxOutPtr;
    INT08U      ucRingBufRx[FFT_RX_BUF_SIZE];
}   FFT_RING_STR;

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
FFT_EXT INT16U usFFTTimer;
FFT_EXT INT16U usFFTStatus;
#if (FFT_FFT_FUNCTION_ON == 1)
FFT_EXT INT16U usFFTCalcTime;
FFT_EXT FFT_RING_STR sFFTRingBuf;
FFT_EXT FP32   fFFTDatBuffer[FFT_FFT_DAT_SIZE*2];
FFT_EXT FP32   fFFTDatFilter[FFT_FFT_DAT_SIZE/2];
#endif

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (FFT_FFT_FUNCTION_ON == 1)

FFT_EXT void   FFTInit(void);
FFT_EXT void   FFTStart(void);
FFT_EXT void   FFTTaskLoop(void);
FFT_EXT void   FFTFillTestData(FP32 *pDest, INT16U usSize);
FFT_EXT void   FFTUpdateMeasu(FP32 *pSour, INT16U *pDest, INT16U usSize);
FFT_EXT void   FFTUpdateFilter(FP32 *pSour, FP32 *pFilt, INT16U usSize);
FFT_EXT void   FFTCmdBufInit(void);
FFT_EXT void   FFTPutCmdChar(INT08U c);
FFT_EXT INT08U FFTGetCmdChar(INT16U to, INT08U *err);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */




