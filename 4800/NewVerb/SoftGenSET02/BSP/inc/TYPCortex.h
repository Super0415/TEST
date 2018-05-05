/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File TYPCortex.h                        */
/*                            By: Wu Xuekui                             */
/*                              2016-1-14                               */
/* ******************************************************************** */

#ifndef _TYPCORTEX_H
#define _TYPCORTEX_H

/* ******************************************************************** */
/*  TYP_VERSION  = 10xx: VEC1000 Application                            */
/*  TYP_VERSION  = 40xx: VEC4000 Application                            */
/*  TYP_VERSION  = 68xx: VEC6800 Application                            */
/*  TYP_VERSION  = 69xx: VEC6900 Application                            */
/*  TYP_VERSION  = 760x: GEC7600-Main Application                       */
/*  TYP_VERSION  = 761x: GEC7600-Display Application                    */
/*  TYP_VERSION  = 780x: GEC7800-Main Application                       */
/*  TYP_VERSION  = 781x: GEC7800-Display Application                    */
/*  TYP_VERSION  = 80xx: VEC8000 Application                            */
/*  TYP_VERSION  = 90xx: VEC9000 Application                            */
/*  TYP_VERSION  = 96xx: VEC9600 Application                            */
/* ******************************************************************** */

//#define TYP_VERSION           7800
#define TYP_VERSION           4800
/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define TYP_1000_COMMON_ON       0
#define TYP_4000_COMMON_ON       0
#define TYP_6800_COMMON_ON       0
#define TYP_6900_COMMON_ON       0
#define TYP_7600_COMMON_ON       0
#define TYP_7600_MAIN_CHIP_ON    0
#define TYP_7600_AUX_CHIP_ON     0

//@@@@@@@@@@@@@@@@@ZC
#define TYP_4800_COMMON_ON       0
#define TYP_4800_MAIN_CHIP_ON    0
#define TYP_4800_AUX_CHIP_ON     0
//@@@@@@@@@@@@@@@@ZC

#define TYP_7800_COMMON_ON       0
#define TYP_7800_MAIN_CHIP_ON    0
#define TYP_7800_AUX_CHIP_ON     0
#define TYP_8000_COMMON_ON       0
#define TYP_9000_COMMON_ON       0
#define TYP_9600_COMMON_ON       0
#if   ((TYP_VERSION / 100)   == 10)
#undef  TYP_1000_COMMON_ON
#define TYP_1000_COMMON_ON       1
#endif
#if   ((TYP_VERSION / 100)   == 40)
#undef  TYP_4000_COMMON_ON
#define TYP_4000_COMMON_ON       1
#endif
#if   ((TYP_VERSION / 100)   == 68)
#undef  TYP_6800_COMMON_ON
#define TYP_6800_COMMON_ON       1
#endif
#if   ((TYP_VERSION / 100)   == 69)
#undef  TYP_6900_COMMON_ON
#define TYP_6900_COMMON_ON       1
#endif
#if   ((TYP_VERSION / 100)   == 76)
#undef  TYP_7600_COMMON_ON
#define TYP_7600_COMMON_ON       1
#endif
#if   ((TYP_VERSION / 10)   == 760)
#undef  TYP_7600_MAIN_CHIP_ON
#define TYP_7600_MAIN_CHIP_ON    1
#endif
#if   ((TYP_VERSION / 10)   == 761)
#undef  TYP_7600_AUX_CHIP_ON
#define TYP_7600_AUX_CHIP_ON     1
#endif

//@@@@@@@@@@@@@@@@@@@ZC
#if   ((TYP_VERSION / 100)   == 48)
#undef  TYP_4800_COMMON_ON
#define TYP_4800_COMMON_ON       1
#endif
#if   ((TYP_VERSION / 10)   == 480)
#undef  TYP_4800_MAIN_CHIP_ON
#define TYP_4800_MAIN_CHIP_ON    1
#endif
//@@@@@@@@@@@@@@@@@@ZC

#if   ((TYP_VERSION / 100)   == 78)
#undef  TYP_7800_COMMON_ON
#define TYP_7800_COMMON_ON       1
#endif
#if   ((TYP_VERSION / 10)   == 780)
#undef  TYP_7800_MAIN_CHIP_ON
#define TYP_7800_MAIN_CHIP_ON    1
#endif
#if   ((TYP_VERSION / 10)   == 781)
#undef  TYP_7800_AUX_CHIP_ON
#define TYP_7800_AUX_CHIP_ON     1
#endif
#if   ((TYP_VERSION / 100)   == 80)
#undef  TYP_8000_COMMON_ON
#define TYP_8000_COMMON_ON       1
#endif
#if   ((TYP_VERSION / 100)   == 90)
#undef  TYP_9000_COMMON_ON
#define TYP_9000_COMMON_ON       1
#endif
#if   ((TYP_VERSION / 100)   == 96)
#undef  TYP_9600_COMMON_ON
#define TYP_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define TYP_CPU_9S12_ON          0
#define TYP_CPU_POWERPC_ON       0
#define TYP_CPU_STM32F1_ON       0
#define TYP_CPU_STM32F103_ON     0
#define TYP_CPU_STM32F105_ON     0
#if    (TYP_1000_COMMON_ON    == 1)
#undef  TYP_CPU_9S12_ON
#define TYP_CPU_9S12_ON          1
#endif
#if    (TYP_4000_COMMON_ON    == 1)
#undef  TYP_CPU_9S12_ON
#define TYP_CPU_9S12_ON          1
#endif
#if    (TYP_6800_COMMON_ON    == 1)
#undef  TYP_CPU_9S12_ON
#define TYP_CPU_9S12_ON          1
#endif
#if    (TYP_6900_COMMON_ON    == 1)
#undef  TYP_CPU_POWERPC_ON
#define TYP_CPU_POWERPC_ON       1
#endif
#if    (TYP_7600_COMMON_ON    == 1)
#undef  TYP_CPU_STM32F1_ON
#define TYP_CPU_STM32F1_ON       1
#endif
#if    (TYP_7600_MAIN_CHIP_ON == 1)
#undef  TYP_CPU_STM32F105_ON
#define TYP_CPU_STM32F105_ON     1
#endif
#if    (TYP_7600_AUX_CHIP_ON  == 1)
#undef  TYP_CPU_STM32F103_ON
#define TYP_CPU_STM32F103_ON     1
#endif

//@@@@@@@@@@ZC
#if    (TYP_4800_COMMON_ON    == 1)
#undef  TYP_CPU_STM32F1_ON
#define TYP_CPU_STM32F1_ON       1
#endif
#if    (TYP_4800_MAIN_CHIP_ON == 1)
#undef  TYP_CPU_STM32F105_ON
#define TYP_CPU_STM32F105_ON     1
#endif
#if    (TYP_4800_AUX_CHIP_ON  == 1)
#undef  TYP_CPU_STM32F103_ON
#define TYP_CPU_STM32F103_ON     1
#endif
//@@@@@@@@@@ZC

#if    (TYP_7800_COMMON_ON    == 1)
#undef  TYP_CPU_STM32F1_ON
#define TYP_CPU_STM32F1_ON       1
#endif
#if    (TYP_7800_MAIN_CHIP_ON == 1)
#undef  TYP_CPU_STM32F105_ON
#define TYP_CPU_STM32F105_ON     1
#endif
#if    (TYP_7800_AUX_CHIP_ON  == 1)
#undef  TYP_CPU_STM32F103_ON
#define TYP_CPU_STM32F103_ON     1
#endif
#if    (TYP_8000_COMMON_ON    == 1)
#undef  TYP_CPU_POWERPC_ON
#define TYP_CPU_POWERPC_ON       1
#endif
#if    (TYP_9000_COMMON_ON    == 1)
#undef  TYP_CPU_POWERPC_ON
#define TYP_CPU_POWERPC_ON       1
#endif
#if    (TYP_9600_COMMON_ON    == 1)
#undef  TYP_CPU_POWERPC_ON
#define TYP_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                           Include Definition                         */
/* ******************************************************************** */
#if (TYP_CPU_9S12_ON == 1)
#include "mc9s12xs128.h"
#include <stdlib.h>
#include <string.h>
#endif
#if (TYP_CPU_POWERPC_ON == 1)
#include "REG5634.H"
#include <stdlib.h>
#include <string.h>
#endif
#if (TYP_CPU_STM32F1_ON == 1)
#include "stm32f10x.h"
#include <stdlib.h>
#include <string.h>
#endif

/* ******************************************************************** */
/*                             Type Definition                          */
/* ******************************************************************** */
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef SET
#define SET 1
#endif
#ifndef RESET
#define RESET 0
#endif
#ifndef ENABLE
#define ENABLE 1
#endif
#ifndef DISABLE
#define DISABLE 0
#endif
#ifndef EOF
#define EOF (-1)
#endif
#if    (TYP_CPU_9S12_ON == 1)
#define CPU_BIG_ENDIAN          1
typedef unsigned char           BOOL;
typedef unsigned char           BOOLEAN;
typedef unsigned char           INT8U;
typedef signed   char           INT8S;
typedef unsigned char           INT08U;
typedef signed   char           INT08S;
typedef volatile unsigned char  VINT8U;
typedef volatile signed   char  VINT8S;
typedef volatile unsigned char  VINT08U;
typedef volatile signed   char  VINT08S;
typedef unsigned short          INT16U;
typedef signed   short          INT16S;
typedef volatile unsigned short VINT16U;
typedef volatile signed   short VINT16S;
typedef unsigned long           INT24U;
typedef signed   long           INT24S;
typedef volatile unsigned long  VINT24U;
typedef volatile signed   long  VINT24S;
typedef unsigned long           INT32U;
typedef signed   long           INT32S;
typedef volatile unsigned long  VINT32U;
typedef volatile signed   long  VINT32S;
typedef unsigned long     long  INT64U;
typedef signed   long     long  INT64S;
typedef volatile unsigned long long VINT64U;
typedef volatile signed   long long VINT64S;
typedef float                   FP32;
typedef double                  FP64;
typedef unsigned char           OS_STK;
typedef unsigned char           OS_CPU_SR;
#endif
#if    (TYP_CPU_POWERPC_ON == 1)
#define CPU_BIG_ENDIAN          1
typedef unsigned char           BOOL;
typedef unsigned char           BOOLEAN;
typedef unsigned char           INT8U;
typedef signed   char           INT8S;
typedef unsigned char           INT08U;
typedef signed   char           INT08S;
typedef volatile unsigned char  VINT8U;
typedef volatile signed   char  VINT8S;
typedef volatile unsigned char  VINT08U;
typedef volatile signed   char  VINT08S;
typedef unsigned short          INT16U;
typedef signed   short          INT16S;
typedef volatile unsigned short VINT16U;
typedef volatile signed   short VINT16S;
typedef unsigned long           INT24U;
typedef signed   long           INT24S;
typedef volatile unsigned long  VINT24U;
typedef volatile signed   long  VINT24S;
typedef unsigned long           INT32U;
typedef signed   long           INT32S;
typedef volatile unsigned long  VINT32U;
typedef volatile signed   long  VINT32S;
typedef unsigned long     long  INT64U;
typedef signed   long     long  INT64S;
typedef volatile unsigned long long VINT64U;
typedef volatile signed   long long VINT64S;
typedef float                   FP32;
typedef double                  FP64;
typedef unsigned long           OS_STK;
typedef volatile unsigned long  OS_CPU_SR;
#endif
#if    (TYP_CPU_STM32F1_ON == 1)
#define CPU_BIG_ENDIAN          0
typedef unsigned char           BOOL;
typedef unsigned char           BOOLEAN;
typedef unsigned char           INT8U;
typedef signed   char           INT8S;
typedef unsigned char           INT08U;
typedef signed   char           INT08S;
typedef volatile unsigned char  VINT8U;
typedef volatile signed   char  VINT8S;
typedef volatile unsigned char  VINT08U;
typedef volatile signed   char  VINT08S;
typedef unsigned short          INT16U;
typedef signed   short          INT16S;
typedef volatile unsigned short VINT16U;
typedef volatile signed   short VINT16S;
typedef unsigned int            INT24U;
typedef signed   int            INT24S;
typedef volatile unsigned int   VINT24U;
typedef volatile signed   int   VINT24S;
typedef unsigned int            INT32U;
typedef signed   int            INT32S;
typedef volatile unsigned int   VINT32U;
typedef volatile signed   int   VINT32S;
typedef unsigned long     long  INT64U;
typedef signed   long     long  INT64S;
typedef volatile unsigned long long VINT64U;
typedef volatile signed   long long VINT64S;
typedef float                   FP32;
typedef double                  FP64;
typedef unsigned int            OS_STK;
typedef unsigned int            OS_CPU_SR;
#endif

/* ******************************************************************** */
/*                             Struct Definition                        */
/* ******************************************************************** */
typedef struct
{
   #if (CPU_BIG_ENDIAN == 1)
    INT08U          b1;
    INT08U          b0;
   #else
    INT08U          b0;
    INT08U          b1;
   #endif
}   TWOBYTE;

typedef union
{   INT16U          us;
    TWOBYTE         uc;
}   DBYTE;

typedef struct
{
   #if (CPU_BIG_ENDIAN == 1)
    INT08U          b3;
    INT08U          b2;
    INT08U          b1;
    INT08U          b0;
   #else
    INT08U          b0;
    INT08U          b1;
    INT08U          b2;
    INT08U          b3;
   #endif
}   FOURBYTE;

typedef struct
{
   #if (CPU_BIG_ENDIAN == 1)
    INT16U          w1;
    INT16U          w0;
   #else
    INT16U          w0;
    INT16U          w1;
   #endif
}   TWOWORD;

typedef union
{   INT32U          ui;
    TWOWORD         us;
    FOURBYTE        uc;
}   QBYTE;

typedef struct
{   INT32U          uiID;
    INT32U          uiDat0;
    INT32U          uiDat1;
}   CAN_DATA32_STR;

typedef struct
{
   #if (CPU_BIG_ENDIAN == 1)
    INT16U          usID1;
    INT16U          usID0;
    INT16U          usDat0;
    INT16U          usDat1;
    INT16U          usDat2;
    INT16U          usDat3;
   #else
    INT16U          usID0;
    INT16U          usID1;
    INT16U          usDat0;
    INT16U          usDat1;
    INT16U          usDat2;
    INT16U          usDat3;
   #endif
}   CAN_DATA16_STR;

typedef struct
{
   #if (CPU_BIG_ENDIAN == 1)
    INT08U          ucID3;
    INT08U          ucID2;
    INT08U          ucID1;
    INT08U          ucID0;
    INT08U          ucDat0;
    INT08U          ucDat1;
    INT08U          ucDat2;
    INT08U          ucDat3;
    INT08U          ucDat4;
    INT08U          ucDat5;
    INT08U          ucDat6;
    INT08U          ucDat7;
   #else
    INT08U          ucID0;
    INT08U          ucID1;
    INT08U          ucID2;
    INT08U          ucID3;
    INT08U          ucDat0;
    INT08U          ucDat1;
    INT08U          ucDat2;
    INT08U          ucDat3;
    INT08U          ucDat4;
    INT08U          ucDat5;
    INT08U          ucDat6;
    INT08U          ucDat7;
   #endif
}   CAN_DATA08_STR;

typedef union
{   CAN_DATA32_STR  DAT32;
    CAN_DATA16_STR  DAT16;
    CAN_DATA08_STR  DAT08;
}   CAN_MSG;

typedef struct
{   INT08U          ucAddr;
    INT08U          ucLeng;
    INT08U          aData[256];
}   MODBUS_MSG;

typedef struct
{   INT16U          usGain;
    INT16U          usStability;
    INT16U          usDerivative;
    INT16U          usInputOld;
    INT32U          uiCtrlOld;
    INT32U          uiCtrlMin;
    INT32U          uiCtrlMax;
}   PID16U_PAR_STR;

typedef struct
{   INT16U          usGain;
    INT16U          usStability;
    INT16U          usDerivative;
    INT16S          ssInputOld;
    INT32S          siCtrlOld;
    INT32S          siCtrlMin;
    INT32S          siCtrlMax;
}   PID16S_PAR_STR;

typedef struct
{   INT16U          usTimer;
    INT16U          usState;
    INT16U          usDelayOn;
    INT16U          usDelayOff;
}   SWITCH_DELAY_STR;

/* ******************************************************************** */
/*                           Include Definition                         */
/* ******************************************************************** */
#include "ERRCortex.h"
#include "OSCortex.h"
#include "SFCortex.h"
#include "DBCortex.h"
#include "FWCortex.h"
#include "XIOCortex.h"
#include "SAEJ1939.h"
#include "CCPCortex.h"
#include "CAN1Cortex.h"
#include "CAN2Cortex.h"
#include "SCI1Cortex.h"
#include "SCI2Cortex.h"
#include "SCI3Cortex.h"
#include "SCI4Cortex.h"
#include "SCI5Cortex.h"
#include "CTLCortex.h"
#include "FFTCortex.h"
#include "LCDCortex.h"
#include "RTCCortex.h"
#include "SPI1Cortex.h"
#include "SPI2Cortex.h"
#include "SPI3Cortex.h"

extern int NumTemp[50];

#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
