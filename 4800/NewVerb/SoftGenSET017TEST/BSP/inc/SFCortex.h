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
/*  SF_VERSION  = 760x: GEC7600-Main Application                        */
/*  SF_VERSION  = 761x: GEC7600-Display Application                     */
/*  SF_VERSION  = 780x: GEC7800-Main Application                        */
/*  SF_VERSION  = 781x: GEC7800-Display Application                     */
/*  SF_VERSION  = 80xx: VEC8000 Application                             */
/*  SF_VERSION  = 90xx: VEC9000 Application                             */
/*  SF_VERSION  = 96xx: VEC9600 Application                             */
/* ******************************************************************** */

#define SF_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define SF_1000_COMMON_ON       0
#define SF_4000_COMMON_ON       0
#define SF_6800_COMMON_ON       0
#define SF_6900_COMMON_ON       0
#define SF_7600_COMMON_ON       0
#define SF_7600_MAIN_CHIP_ON    0
#define SF_7600_AUX_CHIP_ON     0
#define SF_7800_COMMON_ON       0
#define SF_7800_MAIN_CHIP_ON    0
#define SF_7800_AUX_CHIP_ON     0
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
#if   ((SF_VERSION / 10)   == 760)
#undef  SF_7600_MAIN_CHIP_ON
#define SF_7600_MAIN_CHIP_ON    1
#endif
#if   ((SF_VERSION / 10)   == 761)
#undef  SF_7600_AUX_CHIP_ON
#define SF_7600_AUX_CHIP_ON     1
#endif
#if   ((SF_VERSION / 100)   == 78)
#undef  SF_7800_COMMON_ON
#define SF_7800_COMMON_ON       1
#endif
#if   ((SF_VERSION / 10)   == 780)
#undef  SF_7800_MAIN_CHIP_ON
#define SF_7800_MAIN_CHIP_ON    1
#endif
#if   ((SF_VERSION / 10)   == 781)
#undef  SF_7800_AUX_CHIP_ON
#define SF_7800_AUX_CHIP_ON     1
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
#define SF_GENS_FUNCTION_ON     1
#define SF_CPU_9S12_ON          0
#define SF_CPU_POWERPC_ON       0
#define SF_CPU_STM32F1_ON       0
#define SF_CPU_STM32F103_ON     0
#define SF_CPU_STM32F105_ON     0
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
#if    (SF_7600_MAIN_CHIP_ON == 1)
#undef  SF_CPU_STM32F105_ON
#define SF_CPU_STM32F105_ON     1
#endif
#if    (SF_7600_AUX_CHIP_ON  == 1)
#undef  SF_CPU_STM32F103_ON
#define SF_CPU_STM32F103_ON     1
#endif
#if    (SF_7800_COMMON_ON    == 1)
#undef  SF_CPU_STM32F1_ON
#define SF_CPU_STM32F1_ON       1
#endif
#if    (SF_7800_MAIN_CHIP_ON == 1)
#undef  SF_CPU_STM32F105_ON
#define SF_CPU_STM32F105_ON     1
#endif
#if    (SF_7800_AUX_CHIP_ON  == 1)
#undef  SF_CPU_STM32F103_ON
#define SF_CPU_STM32F103_ON     1
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
#define SF_FALSE                0
#define SF_TRUE                 1
#define SF_DISABLE              0
#define SF_ENABLE               1
#define SF_MAX2(a,b)           ((a)>(b) ? (a) : (b))
#define SF_MIN2(a,b)           ((a)<(b) ? (a) : (b))
#define SF_MAX3(a,b,c)         ((a)>(b) ? SF_MAX2(a,c) : SF_MAX2(b,c))
#define SF_MIN3(a,b,c)         ((a)<(b) ? SF_MIN2(a,c) : SF_MIN2(b,c))
#define SF_INTERP(a,b,c,d,e)  ((d >= c) ? \
                 (c+(INT16U)((INT32U)(d-c)*(INT32U)(e-a)/(INT32U)(b-a))) : \
                 (c-(INT16U)((INT32U)(c-d)*(INT32U)(e-a)/(INT32U)(b-a))))
#define SF_UNIT_CURRENT        (0.1 A)
#define SF_UNIT_VOLTAGE        (0.1 V)
#define SF_UNIT_ACT_PWR        (0.1 KW)
#define SF_UNIT_APP_PWR        (0.1 KVA)
#define SF_UNIT_REACT_PWR      (0.1 KVAR)
#define SF_UNIT_PWR_FACTOR     (0.1 %)
#define SF_UNIT_FREQUENCY      (0.01 Hz)
#define SF_UNIT_PHASE          (360/65536 Degree)
#define SF_UNIT_TIME           (0.1 S)
#define SF_UNIT_TEMPERATURE    (0.1 C)
#define SF_UNIT_PERSENT        (0.1 %)
#define SF_ZEROPOT_CURRENT      10
#define SF_ZEROPOT_VOLT_LN      10
#define SF_ZEROPOT_VOLT_LL      17
#define SF_GET_VOLT_LN(e,a)     \
       (e)<SF_ZEROPOT_VOLT_LN ? 0 : (INT16U)(((INT32U)(e)*(INT32U)(a))/1024)
#define SF_GET_VOLT_LL(e,a)     \
       (e)<SF_ZEROPOT_VOLT_LL ? 0 : (INT16U)(((INT32U)(e)*(INT32U)(a))/1024)
#define SF_GET_CURRENT(e,a,c)   \
       (e)<SF_ZEROPOT_CURRENT ? 0 : (INT16U)(((INT32U)(e)*(INT32U)(a)*(INT32U)(c))/1024)
#define SF_GET_ACT_PWR(m,a,b,c) \
       (INT32S)(((INT64S)(m) * (INT64S)((INT32U)(a)*(b)*(c))) / ((INT64S)10000 << 20))
#define SF_GET_APP_PWR(v,c)    (INT16U)(((INT32U)(v) * (INT32U)(c)) / 10000)
#define SF_GET_REACT_PWR(c,a)   SFSqrt32u((INT32U)((c) * (c)) - (INT32U)((a) * (a)))
#define SF_GET_PWR_FACT(c,p)   ((p) == 0) ? 0 : (INT16U)(((INT32U)(c) * 1000) / (p))
#define SF_GET_ABS(x)          ((x)>0 ? (INT16U)(x) : (INT16U)(-(x)))
#define SF_GET_SUBABS(a,b)     ((a)>(b) ? (a)-(b) : (b)-(a))
#define SF_GET_CROSS_TIM(n,p)  (((INT32U)(0-(n))*XIO_ADC_SMPL_TIM_US)/(INT32U)((p)-(n)))
#define SF_TMP_TO_16U(t)       ((INT16U)(((FP32)(t) + 3276.8f) * 10.0f))
#define SF_16U_TO_TMP(x)       ((FP32)((INT16U)(x)) / 10.0f - 3276.8f)
#define SF_TMPSUB_TO_16U(t)    ((INT16U)((FP32)(t) * 10.0f))
#define SF_16U_TO_TMPSUB(x)    ((FP32)(x) / 10.0f)
#define SF_PRSNT_TO_16U(p,r)   (INT16U)(((INT32U)(r) * (INT32U)(p)) / 1000)
#define SF_16U_TO_PRSNT(x,r)   (INT16U)(((INT32U)(x) * 1000) / (INT32U)(r))
#define SF_VOLT_LN_TO_LL(v)    (INT16U)(((INT32U)(v) * 1774) / 1024)
#define SF_VOLT_LL_TO_LN(v)    (INT16U)(((INT32U)(v) * 1024) / 1774)
#define SF_PRSNT_08U(p,r)      (INT08U)(((INT32U)(p) * 100) / (INT32U)(r))
#define SF_ANGLE_TO_16U(a)     ((INT16U)((FP32)(a) * (65536.0f / 360.0f)))
#define SF_16U_TO_ANGLE(x)     ((FP32)(x) * (360.0f / 65536.0f))
#define SF_16U_TO_3600(x)      ((INT16U)(((INT32U)(x) * 3600) >> 16))
#define SF_3600_TO_16U(x)      ((INT16U)(((INT32U)(x) << 16) / 3600))
#define SF_V5_TO_ADC(x)        ((INT16U)((FP32)(x) * (4095.0f / 5.0f)))
#define SF_ADC_TO_V5(d)        ((FP32)(d) * (5.0f / 4095.0f))
#define SF_OUM_PULL_UP         ((FP32)(300.0f))
#define SF_OUM_TO_ADC(r)       ((INT16U)(((FP32)(r)*4095.0f)/((FP32)(r)+SF_OUM_PULL_UP)))

/* ******************************************************************** */
/*                           Modbus Control                             */
/* ******************************************************************** */
#define SF_UC_LOW(w)           (INT08U)(w)
#define SF_UC_HIGH(w)          (INT08U)((w)>>8)
#define SF_US_CREAT(h,l)       ((INT16U)(l)+((INT16U)(h)<<8))
#define SF_MOD_CRC_LOW_FIRST    1
#define SF_MOD_READ_DINS        0x02
#define SF_MOD_READ_DOUTS       0x01
#define SF_MOD_WRITE_DOUT       0x05
#define SF_MOD_WRITE_DOUTS      0x0F
#define SF_MOD_READ_PARAMS      0x03
#define SF_MOD_WRITE_PARAM      0x06
#define SF_MOD_WRITE_PARAMS     0x10
#define SF_MOD_R_W_PARAMS       0x17
#define SF_MOD_MASK_PARAM       0x16
#define SF_MOD_READ_INPUTS      0x04
#define SF_MOD_READ_FILE        0x14
#define SF_MOD_WRITE_FILE       0x15
#define SF_MOD_READ_DEV_ID      0x2B

/* ******************************************************************** */
/*                            Control Definition                        */
/* ******************************************************************** */
#define SF_ZERO_CROSS_MAX       10
#define SF_HARD_PRD_DAT_SIZ     8
#define SF_HARD_PRD_RST_TICK   (OS_TICKS_PER_SEC/10)
#define SF_SPD_PULSE_RST_TICK  (OS_TICKS_PER_SEC/2)
#define SF_ACC_KWH_CONST       (INT32U)1800000            /* KwH(Hour)  */
#define SF_ACC_KVARH_CONST     (INT32U)1800000            /* Kvar(Hour) */
#define SF_ACC_RUNTIM_CONST    (INT32U)50                 /* 1 S        */
#define SF_SAVE_HSTRY_TIME     (INT32U)15000              /* 5 Minutes  */

/* ******************************************************************** */
/*                            Analog Inputs                             */
/* ******************************************************************** */
#define SF_NUM_OF_ANA_IN        30
#define SF_CPU_TMP_CH           16
#define SF_CPU_TMP_V25         (FP32)1.43
#define SF_CPU_TMP_ADC25       (INT16U)(SF_CPU_TMP_V25 / 3.3f * 4095.0f)
#define SF_CPU_TMP_SLOP        (FP32)4.3
#define SF_CPU_TMP_SLOP_MUL    (INT32U)3300
#define SF_CPU_TMP_SLOP_DIV    (INT32U)(SF_CPU_TMP_SLOP * 4095.0f)
#define SF_BATT1_VOLT_CH        17
#define SF_BATT2_VOLT_CH        18
#define SF_CHARG_VOLT_CH        19
#define SF_GET_BATT_VOLT(d)    (INT16U)(((INT32U)(d) * 550) / 4095 + 6)
#define SF_GET_CHARG_VOLT(d)   (INT16U)(((INT32U)(d) * 550) / 4095 + 6)

/* ******************************************************************** */
/*                            Digital Inputs                            */
/* ******************************************************************** */
#define SF_NUM_OF_SW_IN         32
#define SF_NUM_OF_KEY_IN        32
#define SF_KEY_BIT_MENU_UP      0
#define SF_KEY_BIT_MENU_DOWN    1
#define SF_KEY_BIT_MENU_RIGHT   2
#define SF_KEY_BIT_MENU_LEFT    3
#define SF_KEY_BIT_MENU_ENTER   4
#define SF_KEY_BIT_OBD          5
#define SF_KEY_BIT_ENG_STOP     7
#define SF_KEY_BIT_ENG_START    6
#define SF_KEY_BIT_MODE_AUTO    8
#define SF_KEY_BIT_MODE_MANUAL  9
#define SF_KEY_BIT_ERROR_RESET  10
#define SF_KEY_BIT_SWITCH_ON    11
#define SF_KEY_BIT_SWITCH_OFF   12
#define SF_KEY_BIT_BEEPER       13

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
{   INT16U  usFreq;
    INT16U  usPhase;
    INT32S  siDSum;
    INT32S  siDOld;
    INT32U  uiTOld;
    INT32U  uiTNew;
    INT32U  uiTPrd;
    INT32U  uiTLng;
    INT32U  uiFilt;
}   SF_SOFT_FREQ_STR;

typedef struct
{   INT16U  usTime;
    INT16U  usTick;
    INT16U  usFreq;
    INT16U  usCount;
    INT32U  *pPeriod;
    INT32U  uiPeriod[SF_HARD_PRD_DAT_SIZ];
}   SF_HARD_FREQ_STR;

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
{   INT32U  uiI2tRated;
    INT64U  llI2tSum64;
    INT64U  llI2tMax64;
}   SF_I2T_TIM_STR;

/* ******************************************************************** */
/*                     Variable Definitions                             */
/* ******************************************************************** */
SF_EXT INT32U uiSFStatus;
SF_EXT SF_I2T_TIM_STR sSFI2tMainCurrA;
SF_EXT SF_I2T_TIM_STR sSFI2tMainCurrB;
SF_EXT SF_I2T_TIM_STR sSFI2tMainCurrC;
SF_EXT SF_I2T_TIM_STR sSFI2tGensCurrA;
SF_EXT SF_I2T_TIM_STR sSFI2tGensCurrB;
SF_EXT SF_I2T_TIM_STR sSFI2tGensCurrC;

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
SF_EXT INT08U SFGetPowerTwo16u(INT16U usData);
SF_EXT INT16U SFEndianExchange16u(INT16U usData);
SF_EXT INT32U SFEndianExchange32u(INT32U uiData);

SF_EXT INT16U SFGetCrc16Code(INT08U *pBuf, INT08U ucSize);
SF_EXT INT08U SFCheckModMsgCrc(MODBUS_MSG *pMsg);
SF_EXT void   SFSetupModMsgCrc(MODBUS_MSG *pMsg);
SF_EXT INT16U SFModGetParam(INT16U usBegin);
SF_EXT INT08U SFModGetParams(INT08U *pDat, INT16U usBegin, INT16U usSize);
SF_EXT INT08U SFModSetParam(INT16U usBegin, INT16U usValue);
SF_EXT INT08U SFModSetParams(INT08U *pDat, INT16U usBegin, INT16U usSize);
SF_EXT INT08U SFProcessRxModMsg(MODBUS_MSG *pMsg);

SF_EXT void   SFCopy16s(INT16S *pSour, INT16S *pDest, INT16U usSize);
SF_EXT void   SFCopy16u(INT16U *pSour, INT16U *pDest, INT16U usSize);
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
SF_EXT void   SFNegate16s(INT16S *pData, INT16U usSize);
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

SF_EXT void   SFSoftFreqInit(SF_SOFT_FREQ_STR *pSoft, INT16U usFilt);
SF_EXT void   SFSoftFreqRefresh(INT16S *pSour, SF_SOFT_FREQ_STR *pSoft, INT16U usSize);

SF_EXT INT16U SFGet1DMap8(INT16U usX, INT16U *pXX, INT16U *pYY);
SF_EXT INT16U SFGet1DMap10(INT16U usX, INT16U *pXX, INT16U *pYY);
SF_EXT INT16U SFGet1DMap20(INT16U usX, INT16U *pXX, INT16U *pYY);
SF_EXT INT16U SFGet1DMapCst10(INT16U usX, const INT16U *pXX, const INT16U *pYY);

SF_EXT void   SFHardFreqInit(SF_HARD_FREQ_STR *pHard);
SF_EXT void   SFHardFreqRefresh(SF_HARD_FREQ_STR *pHard);
SF_EXT void   SFHardFreqPutTime(INT16U usTime, SF_HARD_FREQ_STR *pHard);
SF_EXT INT16U SFHardFreqGetFreq(SF_HARD_FREQ_STR *pHard);
SF_EXT INT32U SFHardFreqGetPeriod(SF_HARD_FREQ_STR *pHard);
SF_EXT INT08U SFHardFreqCheckPeriod(SF_HARD_FREQ_STR *pHard);
SF_EXT INT16S SFHardFreqGetPhsDiff(SF_HARD_FREQ_STR *pHard0, SF_HARD_FREQ_STR *pHard1);

SF_EXT void   SFSpdPulseInit(SF_SPD_PULSE_STR *pSpd, INT16U usTeeth, INT16U usFilter);
SF_EXT void   SFSpdPulseRefrash(SF_SPD_PULSE_STR *pSpd);
SF_EXT INT16U SFSpdPulseGetSpeed(SF_SPD_PULSE_STR *pSpd);
SF_EXT void   SFSpdPulsePutTime(INT16U usTime, SF_SPD_PULSE_STR *pSpd);

SF_EXT INT16U SFGetPidCtrl16u(INT16U usInput, INT16U usSetp, PID16U_PAR_STR *pPara);
SF_EXT INT16S SFGetPidCtrl16s(INT16S ssInput, INT16S ssSetp, PID16S_PAR_STR *pPara);
SF_EXT INT16S SFGetErrorPidCtrl(INT16S ssError, PID16S_PAR_STR *pPara);
SF_EXT INT16U SFSwitchDelay(INT16U usSwitch, SWITCH_DELAY_STR *pDelay);
SF_EXT void   SFResetSwitchDelay(SWITCH_DELAY_STR *pDelay);
SF_EXT void   SFI2tTimeOverInit(INT16U usRated, INT16U usTover,
                                INT16U usFreq,  SF_I2T_TIM_STR *pInver);
SF_EXT INT16U SFI2tTimeOverCheck(INT16U usInput, SF_I2T_TIM_STR *pInver);
SF_EXT INT16U SFGetReactPwrOfAct(INT16U usActPwr, INT16U usFactor);

#if (SF_GENS_FUNCTION_ON == 1)

SF_EXT INT16U SFGetCpuTemp(INT16U usAdc);
SF_EXT INT16U SFGetSensorTemp(INT16U usAdc, INT16U usType);
SF_EXT INT16U SFGetSensorPres(INT16U usAdc, INT16U usType);
SF_EXT INT16U SFGetSensorLevel(INT16U usAdc, INT16U usType);
SF_EXT INT32U SFGetAccKwh(INT16U usPower);
SF_EXT INT32U SFGetAccKvarh(INT16U usPower);
SF_EXT INT32U SFGetAccRunTime(INT16U usRunning);
SF_EXT INT08U SFUpdataStatistics(INT16U usSpeed, INT16U usPower);
SF_EXT void   SFCheckToSaveHstry(void);

SF_EXT void   SFUpdateAnalogStatus(INT16U *pAin);
SF_EXT void   SFUpdateSwitchesStatus(INT32U uiInput);
SF_EXT void   SFUpdateBoardKeyStatus(INT32U uiInput);
SF_EXT void   SFResetAllErrors(void);
SF_EXT void   SFResetOneError(void);

SF_EXT void   SFMonitorMainVolt(INT08U ucFunc);
SF_EXT void   SFMonitorMainFreq(INT08U ucFunc);
SF_EXT void   SFMonitorMainPhase(INT08U ucFunc);
SF_EXT void   SFMonitorMainCurrShort(INT08U ucFunc);
SF_EXT void   SFMonitorMainCurrLongInit(INT16U usFreq);
SF_EXT void   SFMonitorMainCurrLong(INT08U ucFunc);
SF_EXT void   SFMonitorMainCurrGnd(INT08U ucFunc);
SF_EXT void   SFMonitorMainCurrUnb(INT08U ucFunc);
SF_EXT void   SFMonitorMainActPwr(INT08U ucFunc);
SF_EXT void   SFMonitorMainReactPwr(INT08U ucFunc);
SF_EXT void   SFMonitorMainAppPwr(INT08U ucFunc);
SF_EXT void   SFMonitorMainRocof(INT08U ucFunc);
SF_EXT void   SFMonitorMainVector(INT08U ucFunc);
SF_EXT void   SFMonitorMainSynVolt(void);
SF_EXT void   SFMonitorMainSynFreq(void);
SF_EXT void   SFMonitorMainVoltLost(void);

SF_EXT void   SFMonitorGensVolt(INT08U ucFunc);
SF_EXT void   SFMonitorGensFreq(INT08U ucFunc);
SF_EXT void   SFMonitorGensPhase(INT08U ucFunc);
SF_EXT void   SFMonitorGensCurrShort(INT08U ucFunc);
SF_EXT void   SFMonitorGensCurrLongInit(INT16U usFreq);
SF_EXT void   SFMonitorGensCurrLong(INT08U ucFunc);
SF_EXT void   SFMonitorGensCurrGnd(INT08U ucFunc);
SF_EXT void   SFMonitorGensCurrUnb(INT08U ucFunc);
SF_EXT void   SFMonitorGensActPwr(INT08U ucFunc);
SF_EXT void   SFMonitorGensReactPwr(INT08U ucFunc);
SF_EXT void   SFMonitorGensAppPwr(INT08U ucFunc);
SF_EXT void   SFMonitorGensInvPwr(INT08U ucFunc);
SF_EXT void   SFMonitorGensFactor(INT08U ucFunc);
SF_EXT void   SFMonitorGensMagLost(INT08U ucFunc);
SF_EXT void   SFMonitorGensSyncTimeOver(INT16U usPhase);
SF_EXT void   SFMonitorGensReadyToLoad(void);
SF_EXT void   SFMonitorLoadSchedLow(INT08U ucFunc);
SF_EXT void   SFMonitorLoadSchedHigh(INT08U ucFunc);

SF_EXT void   SFMonitorEngSpeedHigh(void);
SF_EXT void   SFMonitorEngSpeedLow(INT08U ucFunc);
SF_EXT void   SFMonitorEngSpeedDelta(INT16U usPhase);
SF_EXT void   SFMonitorEngSpeedRamp(INT16U usPhase);
SF_EXT void   SFMonitorEngStopping(INT16U usPhase);

SF_EXT void   SFMonitorEngTemperature(void);
SF_EXT void   SFMonitorEngPressure(void);
SF_EXT void   SFMonitorEngLevel(void);
SF_EXT void   SFMonitorEngVoltage(void);
SF_EXT void   SFMonitorEngFilter(void);
SF_EXT void   SFMonitorKeyCmdToStop(INT16U usAutoOrHand);
SF_EXT void   SFMonitorSwtCmdToStop(INT16U usAutoOrHand);
SF_EXT void   SFMonitorKeyCmdToSwOn(INT16U usAutoOrHand);
SF_EXT void   SFMonitorKeyAutoOrManual(void);
SF_EXT void   SFMonitorEepDataError(void);

SF_EXT INT16U SFGetEngStsStopped(INT16U usSpeed);
SF_EXT INT16U SFGetEngStsRunning(INT16U usSpeed);
SF_EXT INT16U SFGetEngStsIdling(INT16U usSpeed);
SF_EXT INT16U SFGetEngStsRated(INT16U usSpeed);
SF_EXT INT16U SFGetAirHeaterActive(INT16U usPhase);
SF_EXT INT16U SFGetOilPumpActive(INT16U usPhase);
SF_EXT INT16U SFGetFuelSupplyActive(INT16U usPhase);
SF_EXT INT16U SFGetStarterActive(INT16U usPhase, INT16U usAutoOrHand);
SF_EXT INT16U SFGetCoolantFanActive(void);
SF_EXT INT16U SFGetSpeedRatedActive(INT16U usPhase);
SF_EXT INT16U SFGetMainSwOnOutput(INT16U usCtrl, INT16U usOutDly);
SF_EXT INT16U SFGetMainSwOffOutput(INT16U usCtrl, INT16U usOutDly);
SF_EXT INT16U SFGetGensSwOnOutput(INT16U usCtrl, INT16U usOutDly);
SF_EXT INT16U SFGetGensSwOffOutput(INT16U usCtrl, INT16U usOutDly);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                               The END                                */
/* ******************************************************************** */
