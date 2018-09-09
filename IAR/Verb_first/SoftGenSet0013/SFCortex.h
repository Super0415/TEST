/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File SFCortex.h                         */
/*                            By: Wu Xuekui                             */
/*                              2016-1-14                               */
/* ******************************************************************** */

#ifndef _SFCORTEX_H

#define _SFCORTEX_H

#ifdef   SF_GLOBALS

#define  SF_EXT  

#else

#define  SF_EXT extern

#endif

/* ******************************************************************** */
/*  SF_VERSION  = 10xx: VEC1000 Application                             */
/*  SF_VERSION  = 40xx: VEC4000 Application                             */
/*  SF_VERSION  = 68xx: VEC6800 Application                             */
/*  SF_VERSION  = 69xx: VEC6900 Application                             */
/*  SF_VERSION  = 76xx: GEC7600 Application                             */
/*  SF_VERSION  = 78xx: GEC7800 Application                             */
/*  SF_VERSION  = 80xx: VEC8000 Application                             */
/*  SF_VERSION  = 90xx: VEC9000 Application                             */
/*  SF_VERSION  = 96xx: VEC9600 Application                             */
/* ******************************************************************** */

#define SF_VERSION           7600

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define SF_1000_COMMON_ON       0
#define SF_4000_COMMON_ON       0
#define SF_6800_COMMON_ON       0
#define SF_6900_COMMON_ON       0
#define SF_7600_COMMON_ON       0
#define SF_7800_COMMON_ON       0
#define SF_8000_COMMON_ON       0
#define SF_9000_COMMON_ON       0
#define SF_9600_COMMON_ON       0
#if   ((SF_VERSION / 100)   == 10)
#undef  SF_1000_COMMON_ON
#define SF_1000_COMMON_ON       1
#endif
#if   ((SF_VERSION / 100)   == 40)
#undef  SF_4000_COMMON_ON
#define SF_4000_COMMON_ON       1
#endif
#if   ((SF_VERSION / 100)   == 68)
#undef  SF_6800_COMMON_ON
#define SF_6800_COMMON_ON       1
#endif
#if   ((SF_VERSION / 100)   == 69)
#undef  SF_6900_COMMON_ON
#define SF_6900_COMMON_ON       1
#endif
#if   ((SF_VERSION / 100)   == 76)
#undef  SF_7600_COMMON_ON
#define SF_7600_COMMON_ON       1
#endif
#if   ((SF_VERSION / 100)   == 78)
#undef  SF_7800_COMMON_ON
#define SF_7800_COMMON_ON       1
#endif
#if   ((SF_VERSION / 100)   == 80)
#undef  SF_8000_COMMON_ON
#define SF_8000_COMMON_ON       1
#endif
#if   ((SF_VERSION / 100)   == 90)
#undef  SF_9000_COMMON_ON
#define SF_9000_COMMON_ON       1
#endif
#if   ((SF_VERSION / 100)   == 96)
#undef  SF_9600_COMMON_ON
#define SF_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define SF_CPU_9S12_ON          0
#define SF_CPU_POWERPC_ON       0
#define SF_CPU_STM32F1_ON       0
#if    (SF_1000_COMMON_ON    == 1)
#undef  SF_CPU_9S12_ON
#define SF_CPU_9S12_ON          1
#endif
#if    (SF_4000_COMMON_ON    == 1)
#undef  SF_CPU_9S12_ON
#define SF_CPU_9S12_ON          1
#endif
#if    (SF_6800_COMMON_ON    == 1)
#undef  SF_CPU_9S12_ON
#define SF_CPU_9S12_ON          1
#endif
#if    (SF_6900_COMMON_ON    == 1)
#undef  SF_CPU_POWERPC_ON
#define SF_CPU_POWERPC_ON       1
#endif
#if    (SF_7600_COMMON_ON    == 1)
#undef  SF_CPU_STM32F1_ON
#define SF_CPU_STM32F1_ON       1
#endif
#if    (SF_7800_COMMON_ON    == 1)
#undef  SF_CPU_STM32F1_ON
#define SF_CPU_STM32F1_ON       1
#endif
#if    (SF_8000_COMMON_ON    == 1)
#undef  SF_CPU_POWERPC_ON
#define SF_CPU_POWERPC_ON       1
#endif
#if    (SF_9000_COMMON_ON    == 1)
#undef  SF_CPU_POWERPC_ON
#define SF_CPU_POWERPC_ON       1
#endif
#if    (SF_9600_COMMON_ON    == 1)
#undef  SF_CPU_POWERPC_ON
#define SF_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                           Basis Definition                           */
/* ******************************************************************** */
#define SF_FALSE               (INT08U)0
#define SF_TRUE                (INT08U)1
#define SF_INTERP(a,b,c,d,e)  ((d >= c) ? \
                 (c+(INT16U)((INT32U)(d-c)*(INT32U)(e-a)/(INT32U)(b-a))) : \
                 (c-(INT16U)((INT32U)(c-d)*(INT32U)(e-a)/(INT32U)(b-a))))
#define SF_UNIT_CURRENT         0.1A
#define SF_UNIT_VOLTAGE         0.1V
#define SF_UNIT_ACT_PWR         0.1KW
#define SF_UNIT_APP_PWR         0.1KVAR
#define SF_UNIT_REACT_PWR       0.1KVAR
#define SF_ZEROPT_CURRENT       10
#define SF_ZEROPT_VOLT_LN       10
#define SF_ZEROPT_VOLT_LL       17
#define SF_GET_VOLT_LN(e,a)     \
       (e)<SF_ZEROPT_VOLT_LN ? 0 : (INT16U)(((INT32U)(e)*(INT32U)(a))/1024)
#define SF_GET_VOLT_LL(e,a)     \
       (e)<SF_ZEROPT_VOLT_LL ? 0 : (INT16U)(((INT32U)(e)*(INT32U)(a))/1024)
#define SF_GET_CURRENT(e,a,c)   \
       (e)<SF_ZEROPT_CURRENT ? 0 : (INT16U)(((INT32U)(e)*(INT32U)(a)*(INT32U)(c))/1024)
#define SF_GET_ACT_PWR(m,a,b,c) \
       (INT16S)(((INT64S)(m) * (INT64S)((INT32U)(a)*(b)*(c))) / ((INT64S)10000 << 20))
#define SF_GET_APP_PWR(v,c)    (INT16U)(((INT32U)(v) * (INT32U)(c)) / 10000)
#define SF_GET_REACT_PWR(c,a)   SFSqrt32u((INT32U)(c * c) - (INT32U)(a * a))
#define SF_GET_PWR_FACT(c,p)   (p == 0) ? 0 : (INT16S)(((INT32S)c * 1000) / p)
#define SF_GET_ABS(x)          ((x)>0 ? (INT16U)(x) : (INT16U)(-(x)))
#define SF_GET_SUBABS(a,b)     (a)>(b) ? (a)-(b) : (b)-(a)
#define SF_GET_CROSS_TIM(n,p)  (((INT32U)(0-(n))*XIO_ADC_SMPL_TIM_US)/(INT32U)((p)-(n)))
#define SF_TMP_TO_16U(t)       (INT16U)(((FP32)t + 273.0f) * 16.0f)
#define SF_16U_TO_TMP(x)       (((FP32)x / 16.0f - 273.0f)/)

/* ******************************************************************** */
/*                            Control Definition                        */
/* ******************************************************************** */
#define SF_ZERO_CROSS_MAX       16
#define SF_HARD_PRD_DAT_SIZ     8
#define SF_HARD_PRD_RST_TICK   (OS_TICKS_PER_SEC/10)
#define SF_SPD_PULSE_RST_TICK  (OS_TICKS_PER_SEC/2)
#define SF_ACC_KWH_CONST       (INT32U)1800000
#define SF_ACC_KVARH_CONST     (INT32U)1800000
#define SF_ACC_RUNTIM_CONST    (INT32U)50
#define SF_SAVE_HSTRY_TIME     (INT32U)15000               /* 5 Minutes */

/* ******************************************************************** */
/*                            Analog Inputs                             */
/* ******************************************************************** */
#define SF_NUM_OF_ANA_IN        24
#define SF_CPU_TMP_CH           16
#define SF_CPU_TMP_V25         (FP32)1.43
#define SF_CPU_TMP_ADC25       (INT16U)(SF_CPU_TMP_V25 / 3.3f * 4095.0f)
#define SF_CPU_TMP_SLOP        (FP32)4.3
#define SF_CPU_TMP_SLOP_MUL    (INT32U)3300
#define SF_CPU_TMP_SLOP_DIV    (INT32U)(SF_CPU_TMP_SLOP * 4095.0f)
#define SF_SUPPLY_VLT_CH        17
#define SF_SUPPLY_VLT_CORR     (4095/110)

/* ******************************************************************** */
/*                      System Error Status Mask                        */
/* ******************************************************************** */
#define SF_ERR1_GET_BIT(m)     (usDBmErrorStatus1 &   (m))
#define SF_ERR1_SET_BIT(m)      usDBmErrorStatus1 |=  (m)
#define SF_ERR1_CLR_BIT(m)      usDBmErrorStatus1 &= ~(m)
#define SF_ERR1_OIL_TMP_VT      0x0001
#define SF_ERR1_FUEL_TMP_VT     0x0002
#define SF_ERR1_BOOST_TMP_VT    0x0004
#define SF_ERR1_WATER_TMP_VT    0x0008
#define SF_ERR1_EXHAUST_TMP_VT  0x0010
#define SF_ERR1_OIL_PRES_VT     0x0020
#define SF_ERR1_FUEL_PRES_VT    0x0040
#define SF_ERR1_BOOST_PRES_VT   0x0080
#define SF_ERR1_WATER_PRES_VT   0x0100
#define SF_ERR1_FUEL_LVL_VT     0x0200
#define SF_ERR1_WATER_LVL_VT    0x0400
#define SF_ERR1_CHARGER_VLT_VT  0x0800
#define SF_ERR1_CHARGER_CUR_VT  0x1000
#define SF_ERR1_STARTER_CUR_VT  0x2000
#define SF_ERR1_RACK_POSI_VT    0x4000
#define SF_ERR1_AIR_FILTER_WARN 0x8000
#define SF_ERR1_WARN_MSK        0xFFFF
#define SF_ERR1_EMERG_MSK       0x0000
#define SF_ERR1_STOP_MSK      ( SF_ERR1_WATER_TMP_VT \
                              | SF_ERR1_OIL_PRES_VT )
#define SF_ERR2_GET_BIT(m)     (usDBmErrorStatus2 &   (m))
#define SF_ERR2_SET_BIT(m)      usDBmErrorStatus2 |=  (m)
#define SF_ERR2_CLR_BIT(m)      usDBmErrorStatus2 &= ~(m)
#define SF_ERR2_WATER_TMP_WARN  0x0001
#define SF_ERR2_WATER_TMP_STOP  0x0002
#define SF_ERR2_BOOST_TMP_WARN  0x0004
#define SF_ERR2_BOOST_TMP_STOP  0x0008
#define SF_ERR2_OIL_TMP_WARN    0x0010
#define SF_ERR2_OIL_TMP_STOP    0x0020
#define SF_ERR2_OIL_PRESS_WARN  0x0040
#define SF_ERR2_OIL_PRESS_STOP  0x0080
#define SF_ERR2_FUEL_LVL_WARN   0x0100
#define SF_ERR2_FUEL_LVL_STOP   0x0200
#define SF_ERR2_WATER_LVL_WARN  0x0400
#define SF_ERR2_WATER_LVL_STOP  0x0800
#define SF_ERR2_SUPPLY_VLT_LOW  0x1000
#define SF_ERR2_SUPPLY_VLT_HIGH 0x2000
#define SF_ERR2_CHARGER_VLT_LOW 0x4000
#define SF_ERR2_CHARGER_VLT_HGH 0x8000
#define SF_ERR2_WARN_MSK        0xFFFF
#define SF_ERR2_EMERG_MSK     ( SF_ERR2_WATER_TMP_STOP \
                              | SF_ERR2_OIL_PRESS_STOP )
#define SF_ERR2_STOP_MSK      ( SF_ERR2_BOOST_TMP_STOP \
                              | SF_ERR2_OIL_TMP_STOP \
                              | SF_ERR2_FUEL_LVL_STOP \
                              | SF_ERR2_WATER_LVL_STOP )
#define SF_ERR3_GET_BIT(m)     (usDBmErrorStatus3 &   (m))
#define SF_ERR3_SET_BIT(m)      usDBmErrorStatus3 |=  (m)
#define SF_ERR3_CLR_BIT(m)      usDBmErrorStatus3 &= ~(m)
#define SF_ERR3_MAIN_LNVLT_LOW  0x0001
#define SF_ERR3_MAIN_LNVLT_HIGH 0x0002
#define SF_ERR3_MAIN_LLVLT_LOW  0x0004
#define SF_ERR3_MAIN_LLVLT_HIGH 0x0008
#define SF_ERR3_MAIN_PHASE_LOW  0x0010
#define SF_ERR3_MAIN_PHASE_HIGH 0x0020
#define SF_ERR3_MAIN_FREQ_LOW   0x0040
#define SF_ERR3_MAIN_FREQ_HIGH  0x0080
#define SF_ERR3_GENS_LNVLT_LOW  0x0100
#define SF_ERR3_GENS_LNVLT_HIGH 0x0200
#define SF_ERR3_GENS_LLVLT_LOW  0x0400
#define SF_ERR3_GENS_LLVLT_HIGH 0x0800
#define SF_ERR3_GENS_PHASE_LOW  0x1000
#define SF_ERR3_GENS_PHASE_HIGH 0x2000
#define SF_ERR3_GENS_FREQ_LOW   0x4000
#define SF_ERR3_GENS_FREQ_HIGH  0x8000
#define SF_ERR3_STOP_MSK        0x0000
#define SF_ERR3_EMERG_MSK     ( SF_ERR3_GENS_FREQ_HIGH )
#define SF_ERR3_WARN_MSK      ( SF_ERR3_MAIN_LNVLT_LOW \
                              | SF_ERR3_MAIN_LNVLT_HIGH \
                              | SF_ERR3_MAIN_LLVLT_LOW \
                              | SF_ERR3_MAIN_LLVLT_HIGH \
                              | SF_ERR3_MAIN_PHASE_LOW \
                              | SF_ERR3_MAIN_PHASE_HIGH \
                              | SF_ERR3_MAIN_FREQ_LOW \
                              | SF_ERR3_MAIN_FREQ_HIGH )
/*
#define SF_ERR3_START_MSK     ( SF_ERR3_MAIN_LNVLT_LOW \
                              | SF_ERR3_MAIN_LNVLT_HIGH \
                              | SF_ERR3_MAIN_LLVLT_LOW \
                              | SF_ERR3_MAIN_LLVLT_HIGH \
                              | SF_ERR3_MAIN_FREQ_LOW \
                              | SF_ERR3_MAIN_FREQ_HIGH )
*/

#define SF_ERR3_MAIN_ERR_MSK  ( SF_ERR3_MAIN_LNVLT_LOW \
                              | SF_ERR3_MAIN_LNVLT_HIGH \
                              | SF_ERR3_MAIN_LLVLT_LOW \
                              | SF_ERR3_MAIN_LLVLT_HIGH \
                              | SF_ERR3_MAIN_FREQ_LOW \
                              | SF_ERR3_MAIN_FREQ_HIGH )
#define SF_ERR3_GENS_ERR_MSK  ( SF_ERR3_GENS_LNVLT_LOW \
                              | SF_ERR3_GENS_LNVLT_HIGH \
                              | SF_ERR3_GENS_LLVLT_LOW \
                              | SF_ERR3_GENS_LLVLT_HIGH \
                              | SF_ERR3_GENS_PHASE_LOW \
                              | SF_ERR3_GENS_PHASE_HIGH \
                              | SF_ERR3_GENS_FREQ_LOW \
                              | SF_ERR3_GENS_FREQ_HIGH )



#define SF_ERR4_GET_BIT(m)     (usDBmErrorStatus4 &   (m))
#define SF_ERR4_SET_BIT(m)      usDBmErrorStatus4 |=  (m)
#define SF_ERR4_CLR_BIT(m)      usDBmErrorStatus4 &= ~(m)
#define SF_ERR4_GENS_CURR_HIGH  0x0001
#define SF_ERR4_GENS_CURR_GND   0x0002
#define SF_ERR4_ACT_PWR_HIGH    0x0004
#define SF_ERR4_REACT_PWR_HIGH  0x0008
#define SF_ERR4_APP_PWR_HIGH    0x0010
#define SF_ERR4_PWR_FACTOR_HIGH 0x0020
#define SF_ERR4_PWR_FACTOR_LOW  0x0040
#define SF_ERR4_INTERN_TMP_WARN 0x0080
#define SF_ERR4_CHARGER_CUR_HGH 0x0100
#define SF_ERR4_RACK_POSI_HIGH  0x0200
#define SF_ERR4_SPEED_OVER_WARN 0x0400
#define SF_ERR4_SPEED_OVER_STOP 0x0800
#define SF_ERR4_STARTING_FAIL   0x1000
#define SF_ERR4_RAMP_UP_FAIL    0x2000
#define SF_ERR4_RAMP_DOWN_FAIL  0x4000
#define SF_ERR4_SYNCHRON_FAIL   0x8000
#define SF_ERR4_EMERG_MSK     ( SF_ERR4_SPEED_OVER_STOP )
#define SF_ERR4_STOP_MSK      ( SF_ERR4_STARTING_FAIL )
#define SF_ERR4_WARN_MSK      ( SF_ERR4_GENS_CURR_HIGH \
                              | SF_ERR4_GENS_CURR_GND \
                              | SF_ERR4_ACT_PWR_HIGH \
                              | SF_ERR4_REACT_PWR_HIGH \
                              | SF_ERR4_APP_PWR_HIGH \
                              | SF_ERR4_PWR_FACTOR_HIGH \
                              | SF_ERR4_PWR_FACTOR_LOW \
                              | SF_ERR4_INTERN_TMP_WARN \
                              | SF_ERR4_CHARGER_CUR_HGH \
                              | SF_ERR4_RACK_POSI_HIGH \
                              | SF_ERR4_SPEED_OVER_WARN \
                              | SF_ERR4_SPEED_OVER_STOP \
                              | SF_ERR4_STARTING_FAIL \
                              | SF_ERR4_RAMP_UP_FAIL \
                              | SF_ERR4_RAMP_DOWN_FAIL \
                              | SF_ERR4_SYNCHRON_FAIL )
#define SF_ERR5_GET_BIT(m)     (usDBmErrorStatus5 &   (m))
#define SF_ERR5_SET_BIT(m)      usDBmErrorStatus5 |=  (m)
#define SF_ERR5_CLR_BIT(m)      usDBmErrorStatus5 &= ~(m)
#define SF_ERR5_STOPPING_FAIL   0x0001
#define SF_ERR5_SPEED_WRONG     0x0002
#define SF_ERR5_BREAKER_TRIP    0x0004
#define SF_ERR5_VOLT_DIFF_OVER  0x0008
#define SF_ERR5_STOP_MSK      ( SF_ERR5_SPEED_WRONG \
                              | SF_ERR5_BREAKER_TRIP )
#define SF_ERR5_EMERG_MSK     ( SF_ERR5_STOPPING_FAIL )
#define SF_ERR5_WARN_MSK      ( SF_ERR5_STOPPING_FAIL \
                              | SF_ERR5_SPEED_WRONG \
                              | SF_ERR5_BREAKER_TRIP )
#define SF_ERR6_GET_BIT(m)     (usDBmErrorStatus6 &   (m))
#define SF_ERR6_SET_BIT(m)      usDBmErrorStatus6 |=  (m)
#define SF_ERR6_CLR_BIT(m)      usDBmErrorStatus6 &= ~(m)
#define SF_ERR6_STOP_MSK        0x0000
#define SF_ERR6_EMERG_MSK       0x0000
#define SF_ERR6_WARN_MSK        0x0000

/* ******************************************************************** */
/*                            Digital Inputs                            */
/* ******************************************************************** *///注：不需要改变，此为按键在一个字节中的对应关系
#define SF_NUM_OF_SW_IN         16
#define SF_NUM_OF_KEY_IN        13
#define SF_KEY_BIT_MENU_UP      0           //向上
#define SF_KEY_BIT_MENU_DOWN    1           //向下
#define SF_KEY_BIT_MENU_RIGHT   2           
#define SF_KEY_BIT_MENU_LEFT    3
#define SF_KEY_BIT_MENU_ENTER   4           //确认
#define SF_KEY_BIT_OBD          5
#define SF_KEY_BIT_ENG_STOP     6           //停机
#define SF_KEY_BIT_ENG_START    7           //起机
#define SF_KEY_BIT_MODE_AUTO    8           //自动
#define SF_KEY_BIT_MODE_MANUAL  9           //手动
#define SF_KEY_BIT_ERROR_RSET   10          //复位
#define SF_KEY_BIT_SWITCH_ON    11
#define SF_KEY_BIT_SWITCH_OFF   12

/* ***********************************t********************************* */
/*                            Type Definition                            */
/* ********************************************************************* */
typedef struct
{   INT32S  siSum;
    INT16S  ssOut;
    INT16U  usFilter;
}   SF_IIR_FILTER_STR;

typedef struct
{   INT16U  usFSize;
    INT16S  *pFilter;
}   SF_FIR_FILTER_STR;

typedef struct
{   INT16U  usFreq;
    INT16U  usPhase;
    INT32S  siDold;
    INT32U  uiPrd;
    INT32U  uiTold;
    INT32U  uiTnew;
    INT32U  uiTlong;
}   SF_ZERO_CROSS_STR;

typedef struct
{   INT16U  usTime;
    INT16U  usTick;
    INT16U  usFreq;
    INT16U  usCount;
    INT32U  *pPeriod;
    INT32U  uiPeriod[SF_HARD_PRD_DAT_SIZ];
}   SF_HARD_PRD_STR;

typedef struct
{   INT16U  usTime;
    INT16U  usTick;
    INT16U  usCount;
    INT16U  usCntMax;
    INT16U  usSpeed;
    INT32U  uiPeriod;
    INT32U  uiSpdCst;
}   SF_SPD_PULSE_STR;

typedef struct
{   INT16U  usState;
    INT16U  usTimer;
    INT16U  usDelay;
}   SF_SWITCH_KEY_CMD;

/* ******************************************************************** */
/*                     Variable Definitions                             */
/* ******************************************************************** */
SF_EXT INT16U usSFTimer;
SF_EXT INT16U usSFStatus;

/* ******************************************************************** */
/*                      Function Definition                             */
/* ******************************************************************** */
SF_EXT void   SFInit(void);
SF_EXT INT08U SFCheckTime(INT16U usOld, INT16U usPer);
SF_EXT void   SFDelay32(INT32U uiDelay);
SF_EXT INT16U SFAbs16s(INT16S ssData);
SF_EXT INT16U SFSqrt32u(INT32U uiInput);
SF_EXT INT16U SFInterp16u(INT16U usXX, INT16U usX0, INT16U usX1, INT16U usY0, INT16U usY1);
SF_EXT INT16S SFInterp16s(INT16S ssXX, INT16S ssX0, INT16S ssX1, INT16S ssY0, INT16S ssY1);

SF_EXT void   SFCopy16s(INT16S *pSour, INT16S *pDest, INT16U usSize);
SF_EXT void   SFCopy16u(INT16U *pSour, INT16U *pDest, INT16U usSize);
SF_EXT void   SFCopy16sToCmplx(INT16S *pSour, FP32 *pDest, INT16U usSize);

SF_EXT void   SFFill16s(INT16S *pDest, INT16S ssData, INT16U usSize);
SF_EXT void   SFFill16u(INT16U *pDest, INT16U usData, INT16U usSize);
SF_EXT void   SFFill32s(INT32S *pDest, INT32S siData, INT16U usSize);
SF_EXT void   SFFill32u(INT32U *pDest, INT32U uiData, INT16U usSize);
SF_EXT void   SFFill32f(FP32 *pDest, FP32 fData, INT16U usSize);

SF_EXT INT32S SFGetSum16s(INT16S *pData, INT16U usSize);
SF_EXT INT32U SFGetSum16u(INT16U *pData, INT16U usSize);
SF_EXT FP32   SFGetSum32f(FP32 *pData, INT16U usSize);
SF_EXT INT16S SFGetAve16s(INT16S *pData, INT16U usSize);
SF_EXT INT16U SFGetAve16u(INT16U *pData, INT16U usSize);

SF_EXT INT16S SFGetMax16s(INT16S *pData, INT16U usSize);
SF_EXT INT16U SFGetMax16u(INT16U *pData, INT16U usSize);
SF_EXT FP32   SFGetMax32f(FP32 *pData, INT16U usSize);
SF_EXT INT08U SFCheckMinMax16u(INT16U *pData, INT16U usSize);
SF_EXT INT08U SFCheckMinMax32u(INT32U *pData, INT16U usSize);

SF_EXT INT16U SFGetAdcRef16u(INT16U usInput, INT32U *pRSum);
SF_EXT void   SFSubRef16s(INT16S *pData, INT16S ssRef, INT16U usSize);
SF_EXT INT16U SFGetEffAve(INT16S *pData, INT16U usSize);
SF_EXT INT16U SFGetEffSum(INT16S *pData, INT16U usSize);
SF_EXT INT16U SFSubEffAve(INT16S *pDat0, INT16S *pDat1, INT16U usSize);
SF_EXT INT16U SFSubEffSum(INT16S *pDat0, INT16S *pDat1, INT16U usSize);
SF_EXT INT16U SFTriEffAve(INT16S *pDat0, INT16S *pDat1, INT16S *pDat2, INT16U usSize);
SF_EXT INT16U SFTriEffSum(INT16S *pDat0, INT16S *pDat1, INT16S *pDat2, INT16U usSize);

SF_EXT INT32S SFGetMacAve(INT16S *pSorA, INT16S *pSorB, INT16U usSize);
SF_EXT INT32S SFGetMacSum(INT16S *pSorA, INT16S *pSorB, INT16U usSize);
SF_EXT void   SFGetPowerSpectrum(FP32 *pSour, FP32 *pDest, INT16U usSize);
SF_EXT void   SFGetSqrt32f(FP32 *pSour, FP32 *pDest, INT16U usSize);
SF_EXT INT16S SFGetPhaseDelay(INT16S *pArray0, INT16S *pArray1, INT16U usSize);

SF_EXT void   SFGetFir16s(INT16S *pSour, INT16S *pDest, SF_FIR_FILTER_STR *pFilt, INT16U usSize);
SF_EXT void   SFIirFilterInit(SF_IIR_FILTER_STR *pFilt, INT16U usFilter);
SF_EXT void   SFGetIir16s(INT16S *pSour, INT16S *pDest, SF_IIR_FILTER_STR *pFilt, INT16U usSize);
SF_EXT void   SFZeroCrossInit(SF_ZERO_CROSS_STR *pZero);
SF_EXT void   SFFindZeroCross(INT16S *pData, SF_ZERO_CROSS_STR *pZero, INT16U usSize);

SF_EXT INT16U SFGet1DMap8(INT16U usX, INT16U *pXX, INT16U *pYY);
SF_EXT INT16U SFGet1DMap10(INT16U usX, INT16U *pXX, INT16U *pYY);
SF_EXT INT16U SFGet1DMap20(INT16U usX, INT16U *pXX, INT16U *pYY);
SF_EXT INT16U SFGet1DMapCst10(INT16U usX, const INT16U *pXX, const INT16U *pYY);

SF_EXT void   SFHardPrdInit(SF_HARD_PRD_STR *pHard);
SF_EXT void   SFHardPrdRefrash(SF_HARD_PRD_STR *pHard);
SF_EXT void   SFHardPrdPutTime(INT16U usTime, SF_HARD_PRD_STR *pHard);
SF_EXT INT16U SFHardPrdGetFreq(SF_HARD_PRD_STR *pHard);
SF_EXT INT32U SFHardPrdGetPeriod(SF_HARD_PRD_STR *pHard);
SF_EXT INT08U SFHardPrdCheckPeriod(SF_HARD_PRD_STR *pHard);
SF_EXT INT16S SFHardPrdGetPhsDiff(SF_HARD_PRD_STR *pHard0, SF_HARD_PRD_STR *pHard1);

SF_EXT void   SFSpdPulseInit(SF_SPD_PULSE_STR *pSpd, INT16U usTeeth, INT16U usFilter);
SF_EXT void   SFSpdPulseRefrash(SF_SPD_PULSE_STR *pSpd);
SF_EXT INT16U SFSpdPulseGetSpeed(SF_SPD_PULSE_STR *pSpd);
SF_EXT void   SFSpdPulsePutTime(INT16U usTime, SF_SPD_PULSE_STR *pSpd);

SF_EXT INT16U SFGetPidCtrl16u(INT16U usInput, INT16U usSetp, PID16U_PAR_STR *pPara);
SF_EXT INT16S SFGetPidCtrl16s(INT16S ssInput, INT16S ssSetp, PID16S_PAR_STR *pPara);
SF_EXT INT16U SFSwitchDelay(INT16U usSwitch, SWITCH_DELAY_STR *pDelay);

SF_EXT INT16U SFGetCpuTemp(INT16U usAdc);
SF_EXT INT16U SFGetSensorTemp(INT16U usAdc, INT16U usType);
SF_EXT INT16U SFGetSensorPress(INT16U usAdc, INT16U usType);
SF_EXT INT16U SFGetSensorLevel(INT16U usAdc, INT16U usType);
SF_EXT INT32U SFGetAccKwh(INT32S siPower);
SF_EXT INT32U SFGetAccKvarh(INT32S siPower);
SF_EXT INT32U SFGetAccRunTime(INT16U usRunning);
SF_EXT INT08U SFUpdataStatistics(INT16U usSpeed, INT16U usPower);
SF_EXT void   SFCheckToSaveHstry(void);

SF_EXT void   SFUpdateAnalogStatus(INT16U *pAin);
SF_EXT void   SFUpdateSwitchesStatus(INT16U usInput);
SF_EXT void   SFUpdateBoardKeyStatus(INT16U usInput);
SF_EXT void   SFResetAllErrors(void);
SF_EXT void   SFEngineSpeedMonitor(void);
SF_EXT void   SFEngineTempMonitor(void);
SF_EXT void   SFEnginePressMonitor(void);
SF_EXT void   SFEngineLevelMonitor(void);
SF_EXT void   SFEngineFilterMonitor(void);
SF_EXT void   SFEngineVoltageMonitor(void);
SF_EXT void   SFEngineCurrentMonitor(void);
SF_EXT void   SFEngineRackPosiMonitor(void);
SF_EXT void   SFMainVoltageMonitor(void);
SF_EXT void   SFGensVoltageMonitor(void);
SF_EXT void   SFGensCurrentMonitor(void);
SF_EXT void   SFGensPowerMonitor(void);
SF_EXT void   SFVoltageDifferMonitor(void);
SF_EXT void   SFGensBreakerTripMonitor(void);

/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                               The END                                */
/* ******************************************************************** */
