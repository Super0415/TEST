/* ******************************************************************** */
/*                       Header File RTCCortex.h                        */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _RTCCORTEX_H

#define _RTCCORTEX_H

#ifdef   RTC_GLOBALS

#define  RTC_EXT  

#else

#define  RTC_EXT extern

#endif

/* ******************************************************************** */
/*  RTC_VERSION  = 10xx: VEC1000 Application                           */
/*  RTC_VERSION  = 40xx: VEC4000 Application                           */
/*  RTC_VERSION  = 68xx: VEC6800 Application                           */
/*  RTC_VERSION  = 69xx: VEC6900 Application                           */
/*  RTC_VERSION  = 760x: GEC7600-Main Application                      */
/*  RTC_VERSION  = 761x: GEC7600-Display Application                   */
/*  RTC_VERSION  = 780x: GEC7800-Main Application                      */
/*  RTC_VERSION  = 781x: GEC7800-Display Application                   */
/*  RTC_VERSION  = 80xx: VEC8000 Application                           */
/*  RTC_VERSION  = 90xx: VEC9000 Application                           */
/*  RTC_VERSION  = 96xx: VEC9600 Application                           */
/* ******************************************************************** */

#define RTC_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define RTC_1000_COMMON_ON       0
#define RTC_4000_COMMON_ON       0
#define RTC_6800_COMMON_ON       0
#define RTC_6900_COMMON_ON       0
#define RTC_7600_COMMON_ON       0
#define RTC_7600_MAIN_CHIP_ON    0
#define RTC_7600_AUX_CHIP_ON     0
#define RTC_7800_COMMON_ON       0
#define RTC_7800_MAIN_CHIP_ON    0
#define RTC_7800_AUX_CHIP_ON     0
#define RTC_8000_COMMON_ON       0
#define RTC_9000_COMMON_ON       0
#define RTC_9600_COMMON_ON       0
#if   ((RTC_VERSION / 100)   == 10)
#undef  RTC_1000_COMMON_ON
#define RTC_1000_COMMON_ON       1
#endif
#if   ((RTC_VERSION / 100)   == 40)
#undef  RTC_4000_COMMON_ON
#define RTC_4000_COMMON_ON       1
#endif
#if   ((RTC_VERSION / 100)   == 68)
#undef  RTC_6800_COMMON_ON
#define RTC_6800_COMMON_ON       1
#endif
#if   ((RTC_VERSION / 100)   == 69)
#undef  RTC_6900_COMMON_ON
#define RTC_6900_COMMON_ON       1
#endif
#if   ((RTC_VERSION / 100)   == 76)
#undef  RTC_7600_COMMON_ON
#define RTC_7600_COMMON_ON       1
#endif
#if   ((RTC_VERSION / 10)   == 760)
#undef  RTC_7600_MAIN_CHIP_ON
#define RTC_7600_MAIN_CHIP_ON    1
#endif
#if   ((RTC_VERSION / 10)   == 761)
#undef  RTC_7600_AUX_CHIP_ON
#define RTC_7600_AUX_CHIP_ON     1
#endif
#if   ((RTC_VERSION / 100)   == 78)
#undef  RTC_7800_COMMON_ON
#define RTC_7800_COMMON_ON       1
#endif
#if   ((RTC_VERSION / 10)   == 780)
#undef  RTC_7800_MAIN_CHIP_ON
#define RTC_7800_MAIN_CHIP_ON    1
#endif
#if   ((RTC_VERSION / 10)   == 781)
#undef  RTC_7800_AUX_CHIP_ON
#define RTC_7800_AUX_CHIP_ON     1
#endif
#if   ((RTC_VERSION / 100)   == 80)
#undef  RTC_8000_COMMON_ON
#define RTC_8000_COMMON_ON       1
#endif
#if   ((RTC_VERSION / 100)   == 90)
#undef  RTC_9000_COMMON_ON
#define RTC_9000_COMMON_ON       1
#endif
#if   ((RTC_VERSION / 100)   == 96)
#undef  RTC_9600_COMMON_ON
#define RTC_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define RTC_FUNCTION_ON          1
#define RTC_CPU_9S12_ON          0
#define RTC_CPU_POWERPC_ON       0
#define RTC_CPU_STM32F1_ON       0
#define RTC_CPU_STM32F103_ON     0
#define RTC_CPU_STM32F105_ON     0
#if    (RTC_1000_COMMON_ON    == 1)
#undef  RTC_CPU_9S12_ON
#define RTC_CPU_9S12_ON          1
#endif
#if    (RTC_4000_COMMON_ON    == 1)
#undef  RTC_CPU_9S12_ON
#define RTC_CPU_9S12_ON          1
#endif
#if    (RTC_6800_COMMON_ON    == 1)
#undef  RTC_CPU_9S12_ON
#define RTC_CPU_9S12_ON          1
#endif
#if    (RTC_6900_COMMON_ON    == 1)
#undef  RTC_CPU_POWERPC_ON
#define RTC_CPU_POWERPC_ON       1
#endif
#if    (RTC_7600_COMMON_ON    == 1)
#undef  RTC_CPU_STM32F1_ON
#define RTC_CPU_STM32F1_ON       1
#endif
#if    (RTC_7600_MAIN_CHIP_ON == 1)
#undef  RTC_CPU_STM32F105_ON
#define RTC_CPU_STM32F105_ON     1
#endif
#if    (RTC_7600_AUX_CHIP_ON  == 1)
#undef  RTC_CPU_STM32F103_ON
#define RTC_CPU_STM32F103_ON     1
#endif
#if    (RTC_7800_COMMON_ON    == 1)
#undef  RTC_CPU_STM32F1_ON
#define RTC_CPU_STM32F1_ON       1
#endif
#if    (RTC_7800_MAIN_CHIP_ON == 1)
#undef  RTC_CPU_STM32F105_ON
#define RTC_CPU_STM32F105_ON     1
#endif
#if    (RTC_7800_AUX_CHIP_ON  == 1)
#undef  RTC_CPU_STM32F103_ON
#define RTC_CPU_STM32F103_ON     1
#endif
#if    (RTC_8000_COMMON_ON    == 1)
#undef  RTC_CPU_POWERPC_ON
#define RTC_CPU_POWERPC_ON       1
#endif
#if    (RTC_9000_COMMON_ON    == 1)
#undef  RTC_CPU_POWERPC_ON
#define RTC_CPU_POWERPC_ON       1
#endif
#if    (RTC_9600_COMMON_ON    == 1)
#undef  RTC_CPU_POWERPC_ON
#define RTC_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                           Control Definition                         */
/* ******************************************************************** */
#define RTC_TRUE              (INT08U)1
#define RTC_FALSE             (INT08U)0
#define RTC_STS_NORMAL        (INT32U)0x00000000
#define RTC_STS_ERROR         (INT32U)0x00000001
#define RTC_RTC_TDIF          (+9.0)

/* ***********************************t********************************* */
/*                            Type Definition                            */
/* ********************************************************************* */
typedef struct
{   INT16U      year;
    INT08U      month;
    INT08U      mday;
    INT08U      hour;
    INT08U      min;
    INT08U      sec;
    INT08U      wday;
}   RTC_TIME_STR;

/* ******************************************************************** */
/*                     Variable Definitions                             */
/* ******************************************************************** */
#if (RTC_FUNCTION_ON == 1)

RTC_EXT INT32U uiRTCStatus;

#endif
/* ******************************************************************** */
/*                      Function Definition                             */
/* ******************************************************************** */
#if (RTC_FUNCTION_ON == 1)

RTC_EXT void   RTCInit(void);
RTC_EXT INT08U RTCGetUtc(INT32U *pUtc);
RTC_EXT INT08U RTCSetUtc(INT32U uiUtc);
RTC_EXT INT08U RTCGetTime(RTC_TIME_STR *pRtc);
RTC_EXT INT08U RTCSetTime(RTC_TIME_STR *pRtc);
RTC_EXT INT32U get_fattime(void);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
