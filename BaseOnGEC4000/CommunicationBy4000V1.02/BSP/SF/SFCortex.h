/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File SFCortex.h                         */
/* ******************************************************************** */

#ifndef _SFCORTEX_H

#define _SFCORTEX_H

#ifdef   SF_GLOBALS

#define  SF_EXT  

#else

#define  SF_EXT extern

#endif

#include "TYPCortex.h"

/* ******************************************************************** */
/*                           Basis Definition                           */
/* ******************************************************************** */
#define SF_FALSE                0
#define SF_TRUE                 1
#define SF_DISABLE              0
#define SF_ENABLE               1
#define SF_SAME                 0
#define SF_DIFFERENT            1
#define SF_RANGE_OUT            2
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
#define SF_UNIT_PHASE          (360.0/65536.0 Degree)
#define SF_UNIT_TIME           (0.1 S)
#define SF_UNIT_TEMPERATURE    (0.1 C)
#define SF_UNIT_PERSENT        (0.1 %)
#define SF_SIGNED_ZERO          32768
#define SF_ZEROPOT_CURRENT      30   //10
#define SF_ZEROPOT_VOLT_LN      30   //10
#define SF_ZEROPOT_VOLT_LL      53   //17
#define SF_GET_VOLT_LN(e,a)     \
       (e)<SF_ZEROPOT_VOLT_LN ? 0 : (INT16U)(((INT32U)(e)*(INT32U)(a))/1024)
#define SF_GET_VOLT_LL(e,a)     \
       (e)<SF_ZEROPOT_VOLT_LL ? 0 : (INT16U)(((INT32U)(e)*(INT32U)(a))/1024)
#define SF_GET_CURRENT(e,a,c)   \
       (e)<SF_ZEROPOT_CURRENT ? 0 : (INT16U)(((INT32U)(e)*(INT32U)(a)*(INT32U)(c))/16384)
#define SF_GET_ACT_PWR(m,a,b,c) \
       (INT32S)(((INT64S)(m) * (INT64S)((INT32U)(a)*(b)*(c))) / ((INT64S)10000 << 24))
#define SF_GET_APP_PWR(v,c)    (INT16U)(((INT32U)(v) * (INT32U)(c)) / 10000)
#define SF_GET_REACT_PWR(p,a)  ((p) <= (a)) ? 0 : \
                                SFSqrt32u((INT32U)((p) * (p)) - (INT32U)((a) * (a)))
#define SF_GET_PWR_FACT(a,p)   ((p) <= (a) || ((p) == 0)) ? 1000 : \
                               (INT16U)(((INT32U)(a) * 1000) / (p))
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
#define SF_PRS08_TO_16U(p,r)   (INT16U)(((INT32U)(p) * (INT32U)(r)) / 100)
#define SF_ANGLE_TO_16U(a)     ((INT16U)((FP32)(a) * (65536.0f / 360.0f)))
#define SF_16U_TO_ANGLE(x)     ((FP32)(x) * (360.0f / 65536.0f))
#define SF_16U_TO_3600(x)      ((INT16U)(((INT32U)(x) * 3600) >> 16))
#define SF_3600_TO_16U(x)      ((INT16U)(((INT32U)(x) << 16) / 3600))
#define SF_V5_TO_ADC(x)        ((INT16U)((FP32)(x) * (4095.0f / 5.0f)))
#define SF_ADC_TO_V5(d)        ((FP32)(d) * (5.0f / 4095.0f))
#define SF_3P3_TO_ADC(x)       ((INT16U)((FP32)(x) * (4095.0f / 3.3f)))
#define SF_ADC_TO_3P3(d)       ((FP32)(d) * (3.3f / 4095.0f))
#define SF_OUM_PULL_UP         ((FP32)(300.0f))
#define SF_OUM_TO_ADC(r)       ((INT16U)(((FP32)(r)*4095.0f)/((FP32)(r)+SF_OUM_PULL_UP)))

/* ******************************************************************** */
/*                           Modbus Control                             */
/* ******************************************************************** */
#define SF_UC_LOW(w)           (INT08U)(w)
#define SF_UC_HIGH(w)          (INT08U)((w)>>8)
#define SF_UC_ToLow(w)         (INT16U)(w)
#define SF_UC_ToHIGH(w)        (INT16U)((w)<<8)
#define SF_RS485RX_Color0     0x00FF  //接收无色
#define SF_RS485RX_Color1     0x01FF  //接收有色
#define SF_RS485TX_Color0     0x10FF  //发送无色
#define SF_RS485TX_Color1     0x11FF  //发送有色
#define Parity(M)   M%2==0?0:1  //偶数返回 0  奇数返回 1
#define SF_US_CREAT(h,l)       ((INT16U)(l)+((INT16U)(h)<<8))
#define SF_MOD_CRC_LOW_FIRST    0
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
#define SF_SPD_PLS_PRD_SIZ      400
#define SF_SPD_PLS_RST_TICK    (OS_TICKS_PER_SEC/2)
#define SF_ACC_KWH_CONST       (INT32U)180000              /* 0.1 KwH   */
#define SF_ACC_KVARH_CONST     (INT32U)180000              /* 0.1 KvarH */
#define SF_ACC_RUNTIM_CONST    (INT32U)3000                /* 1 Minutes */
#define SF_SAVE_HSTRY_TIME     (INT32U)15000               /* 5 Minutes */

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
#define SF_BATT1_VOLT_CH        15
#define SF_BATT2_VOLT_CH        18
#define SF_CHARG_VOLT_CH        14
#define SF_GET_BATT_VOLT(d)    (INT16U)(((INT32U)(d) * 1130) / 4095)
#define SF_GET_CHARG_VOLT(d)   (INT16U)(((INT32U)(d) * 1130) / 4095)
#define SF_SYS_PWR_ON_VMIN      90                            /* 9.0 V  */
#define SF_SYS_PWR_ON_TICKS    (OS_TICKS_PER_SEC * 3)         /* 3.0 S  */
#define SF_SYS_PWR_OFF_VMAX     60                            /* 6.0 V  */
#define SF_SYS_PWR_OFF_TICKS   (OS_TICKS_PER_SEC / 10)        /* 100 mS */
#define SF_OFFTIME_HEATER      (INT16U)3000                   /* 5 Min  */
#define SF_OFFTIME_OILPUMP     (INT16U)3000                   /* 5 Min  */
#define SF_OFFTIME_STOPPER     (INT16U)100                    /* 10 S   */
#define SF_FUELSTEAL_DELAY     (INT16U)150                    /* 15 S   */
#define SF_FUELSTEAL_LMIN      (INT16U)100                    /* 10 %   */
#define SF_FUELSTEAL_DSIZ       20                            /* 5 Min  */

/* ******************************************************************** */
/*                            Digital Inputs                            */
/* ******************************************************************** */
#define SF_NUM_OF_SW_IN         32
#define SF_NUM_OF_KEY_IN        16
#define SF_KEY_BIT_MENU_UP      0
#define SF_KEY_BIT_MENU_DOWN    1
#define SF_KEY_BIT_MENU_RIGHT   2
#define SF_KEY_BIT_MENU_LEFT    3
#define SF_KEY_BIT_MENU_ENTER   4
#define SF_KEY_BIT_OBD          5
#define SF_KEY_BIT_ENG_STOP     6
#define SF_KEY_BIT_ENG_START    7
#define SF_KEY_BIT_MODE_AUTO    8
#define SF_KEY_BIT_MODE_MANUAL  9
#define SF_KEY_BIT_ERROR_RESET  10
#define SF_KEY_BIT_SWITCH_ON    11
#define SF_KEY_BIT_SWITCH_OFF   12
#define SF_KEY_BIT_BEEPER       13
#define SF_KEY_MSK_MENU_UP     (1u << SF_KEY_BIT_MENU_UP)
#define SF_KEY_MSK_MENU_DOWN   (1u << SF_KEY_BIT_MENU_DOWN)
#define SF_KEY_MSK_MENU_RIGHT  (1u << SF_KEY_BIT_MENU_RIGHT)
#define SF_KEY_MSK_MENU_LEFT   (1u << SF_KEY_BIT_MENU_LEFT)
#define SF_KEY_MSK_MENU_ENTER  (1u << SF_KEY_BIT_MENU_ENTER)
#define SF_KEY_MSK_OBD         (1u << SF_KEY_BIT_OBD)
#define SF_KEY_MSK_ENG_STOP    (1u << SF_KEY_BIT_ENG_STOP)
#define SF_KEY_MSK_ENG_START   (1u << SF_KEY_BIT_ENG_START)
#define SF_KEY_MSK_MODE_AUTO   (1u << SF_KEY_BIT_MODE_AUTO)
#define SF_KEY_MSK_MODE_MANUAL (1u << SF_KEY_BIT_MODE_MANUAL)
#define SF_KEY_MSK_ERROR_RESET (1u << SF_KEY_BIT_ERROR_RESET)
#define SF_KEY_MSK_SWITCH_ON   (1u << SF_KEY_BIT_SWITCH_ON)
#define SF_KEY_MSK_SWITCH_OFF  (1u << SF_KEY_BIT_SWITCH_OFF)
#define SF_KEY_MSK_BEEPER      (1u << SF_KEY_BIT_BEEPER)
#define SF_KEY_CHECK_TICKS      20

/* ******************************************************************** */
/*                            Electric Switches                         */
/* ******************************************************************** */
#define SF_SW_STS_SWOFF_ED     (INT08U)0x00     //状态-开关断开结束
#define SF_SW_STS_SWON_ED      (INT08U)0x01     //状态-开关闭合结束
#define SF_SW_STS_SWOFF_ING    (INT08U)0x02     //状态-开关断开进行中
#define SF_SW_STS_SWON_ING     (INT08U)0x03     //状态-开关闭合进行中
#define SF_SW_CMD_HOLD         (INT08U)0x00     //指令-待机
#define SF_SW_CMD_SWON         (INT08U)0x01     //指令-开关闭合
#define SF_SW_CMD_SWOFF        (INT08U)0x02     //指令-开关断开
#define SF_SW_NO_LOCK          (INT08U)0x00     
#define SF_SW_LOCK_SWON        (INT08U)0x01
#define SF_SW_LOCK_SWOFF       (INT08U)0x02
#define SF_SW_LOCK_SWONOFF     (INT08U)0x03
#define SF_SW_NO_ERR           (INT08U)0x00
#define SF_SW_ERR_SWON         (INT08U)0x01     //错误-开关闭合
#define SF_SW_ERR_SWOFF        (INT08U)0x02     //错误-开关断开
#define SF_SW_DLY_ON_TO_OFF    (INT16U)10
#define SF_SW_DLY_OFF_TO_ON    (INT16U)10
#define SF_SW_DLY_FEED_CHECK   (INT16U)10

/* ***********************************t********************************* */
/*                            Type Definition                            */
/* ********************************************************************* */
/*
typedef struct
{   INT32S  siSum;
    INT16S  ssOut;
    INT16U  usFilter;
}   SF_IIR_FILTER_STR;
*/

/* ******************************************************************** */
/*                     Variable Definitions                             */
/* ******************************************************************** */
/*
SF_EXT INT32U uiSFStatus;
SF_EXT SF_I2T_TIM_STR sSFI2tMainCurrA;
*/

/* ******************************************************************** */
/*                      Function Definition                             */
/* ******************************************************************** */
SF_EXT INT08U SFProcessHostRxModMsg (MODBUS_MSG *pMsg);
SF_EXT INT08U SFProcessRxModMsg (MODBUS_MSG *pMsg);
SF_EXT INT08U SFCheckModMsgCrc (MODBUS_MSG *pMsg);
SF_EXT INT16U SFGetCrc16Code (INT08U *pBuf, INT08U ucSize);
SF_EXT INT08U SFModGetParams (INT08U *pDat, INT16U usBegin, INT16U usSize);
SF_EXT void SFUSARTRecordMesure(INT08U pDat,MODBUS_MSG *pMsg, INT16U uLeng, INT16U usSign);
SF_EXT void SFSetupModMsgCrc (MODBUS_MSG *pMsg);
SF_EXT void SFFill16u (INT16U *pDest, INT16U usData, INT16U usSize);
SF_EXT void SFFill08u (INT08U *pDest, INT08U usData, INT16U usSize);
SF_EXT INT08U SFModSetParam (INT16U usBegin, INT16U usValue);
SF_EXT INT08U SFModSetParams (INT08U *pDat, INT16U usBegin, INT16U usSize);
SF_EXT void SFCopy16u (INT16U *pSour, INT16U *pDest, INT16U usSize);
SF_EXT void SFCopy08u (INT08U *pSour, INT08U *pDest, INT16U usSize);
SF_EXT INT16U SFCopyAndSum16u (INT16U *pSour, INT16U *pDest, INT16U usSize);
SF_EXT INT16U SFCopyAndSum08u (INT08U *pSour, INT08U *pDest, INT16U usSize);
SF_EXT INT08U SFCompare16u (INT16U *pSouX, INT16U *pSouY, INT16U usSize);
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                               The END                                */
/* ******************************************************************** */

