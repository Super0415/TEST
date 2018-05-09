/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Header File LCDCortex.h                        */
/*                              2016-1-14                               */
/* ******************************************************************** */

#ifndef _LCDCORTEX_H

#define _LCDCORTEX_H

#ifdef   LCD_GLOBALS

#define  LCD_EXT  

#else

#define  LCD_EXT extern

#endif

/* ******************************************************************** */
/*  LCD_VERSION  = 10xx: VEC1000 Application                            */
/*  LCD_VERSION  = 40xx: VEC4000 Application                            */
/*  LCD_VERSION  = 68xx: VEC6800 Application                            */
/*  LCD_VERSION  = 69xx: VEC6900 Application                            */
/*  LCD_VERSION  = 760x: GEC7600-Main Application                       */
/*  LCD_VERSION  = 761x: GEC7600-Display Application                    */
/*  LCD_VERSION  = 780x: GEC7800-Main Application                       */
/*  LCD_VERSION  = 781x: GEC7800-Display Application                    */
/*  LCD_VERSION  = 80xx: VEC8000 Application                            */
/*  LCD_VERSION  = 90xx: VEC9000 Application                            */
/*  LCD_VERSION  = 96xx: VEC9600 Application                            */
/* ******************************************************************** */

#define LCD_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define LCD_1000_COMMON_ON       0
#define LCD_4000_COMMON_ON       0
#define LCD_6800_COMMON_ON       0
#define LCD_6900_COMMON_ON       0
#define LCD_7600_COMMON_ON       0
#define LCD_7600_MAIN_CHIP_ON    0
#define LCD_7600_AUX_CHIP_ON     0
#define LCD_7800_COMMON_ON       0
#define LCD_7800_MAIN_CHIP_ON    0
#define LCD_7800_AUX_CHIP_ON     0
#define LCD_8000_COMMON_ON       0
#define LCD_9000_COMMON_ON       0
#define LCD_9600_COMMON_ON       0
#if   ((LCD_VERSION / 100)   == 10)
#undef  LCD_1000_COMMON_ON
#define LCD_1000_COMMON_ON       1
#endif
#if   ((LCD_VERSION / 100)   == 40)
#undef  LCD_4000_COMMON_ON
#define LCD_4000_COMMON_ON       1
#endif
#if   ((LCD_VERSION / 100)   == 68)
#undef  LCD_6800_COMMON_ON
#define LCD_6800_COMMON_ON       1
#endif
#if   ((LCD_VERSION / 100)   == 69)
#undef  LCD_6900_COMMON_ON
#define LCD_6900_COMMON_ON       1
#endif
#if   ((LCD_VERSION / 100)   == 76)
#undef  LCD_7600_COMMON_ON
#define LCD_7600_COMMON_ON       1
#endif
#if   ((LCD_VERSION / 10)   == 760)
#undef  LCD_7600_MAIN_CHIP_ON
#define LCD_7600_MAIN_CHIP_ON    1
#endif
#if   ((LCD_VERSION / 10)   == 761)
#undef  LCD_7600_AUX_CHIP_ON
#define LCD_7600_AUX_CHIP_ON     1
#endif
#if   ((LCD_VERSION / 100)   == 78)
#undef  LCD_7800_COMMON_ON
#define LCD_7800_COMMON_ON       1
#endif
#if   ((LCD_VERSION / 10)   == 780)
#undef  LCD_7800_MAIN_CHIP_ON
#define LCD_7800_MAIN_CHIP_ON    1
#endif
#if   ((LCD_VERSION / 10)   == 781)
#undef  LCD_7800_AUX_CHIP_ON
#define LCD_7800_AUX_CHIP_ON     1
#endif
#if   ((LCD_VERSION / 100)   == 80)
#undef  LCD_8000_COMMON_ON
#define LCD_8000_COMMON_ON       1
#endif
#if   ((LCD_VERSION / 100)   == 90)
#undef  LCD_9000_COMMON_ON
#define LCD_9000_COMMON_ON       1
#endif
#if   ((LCD_VERSION / 100)   == 96)
#undef  LCD_9600_COMMON_ON
#define LCD_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define LCD_FUNCTION_ON          1       //@@@@@@@@@ZC  0
#define LCD_CPU_9S12_ON          0
#define LCD_CPU_POWERPC_ON       0
#define LCD_CPU_STM32F1_ON       0
#define LCD_CPU_STM32F103_ON     0
#define LCD_CPU_STM32F105_ON     0
#if    (LCD_1000_COMMON_ON    == 1)
#undef  LCD_CPU_9S12_ON
#define LCD_CPU_9S12_ON          1
#endif
#if    (LCD_4000_COMMON_ON    == 1)
#undef  LCD_CPU_9S12_ON
#define LCD_CPU_9S12_ON          1
#endif
#if    (LCD_6800_COMMON_ON    == 1)
#undef  LCD_CPU_9S12_ON
#define LCD_CPU_9S12_ON          1
#endif
#if    (LCD_6900_COMMON_ON    == 1)
#undef  LCD_CPU_POWERPC_ON
#define LCD_CPU_POWERPC_ON       1
#endif
#if    (LCD_7600_COMMON_ON    == 1)
#undef  LCD_CPU_STM32F1_ON
#define LCD_CPU_STM32F1_ON       1
#endif
#if    (LCD_7600_MAIN_CHIP_ON == 1)
#undef  LCD_CPU_STM32F105_ON
#define LCD_CPU_STM32F105_ON     1
#endif
#if    (LCD_7600_AUX_CHIP_ON  == 1)
#undef  LCD_CPU_STM32F103_ON
#define LCD_CPU_STM32F103_ON     1
#endif
#if    (LCD_7800_COMMON_ON    == 1)
#undef  LCD_CPU_STM32F1_ON
#define LCD_CPU_STM32F1_ON       1
#endif
#if    (LCD_7800_MAIN_CHIP_ON == 1)
#undef  LCD_CPU_STM32F105_ON
#define LCD_CPU_STM32F105_ON     1
#endif
#if    (LCD_7800_AUX_CHIP_ON  == 1)
#undef  LCD_CPU_STM32F103_ON
#define LCD_CPU_STM32F103_ON     1
#endif
#if    (LCD_8000_COMMON_ON    == 1)
#undef  LCD_CPU_POWERPC_ON
#define LCD_CPU_POWERPC_ON       1
#endif
#if    (LCD_9000_COMMON_ON    == 1)
#undef  LCD_CPU_POWERPC_ON
#define LCD_CPU_POWERPC_ON       1
#endif
#if    (LCD_9600_COMMON_ON    == 1)
#undef  LCD_CPU_POWERPC_ON
#define LCD_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
#if (LCD_FUNCTION_ON == 1)

LCD_EXT INT32U uiLCDStatus;

#endif
/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (LCD_FUNCTION_ON == 1)

LCD_EXT void   LCDInit(void);
LCD_EXT void   LCDStart(void);
LCD_EXT void   LCDTaskLoop(void);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
