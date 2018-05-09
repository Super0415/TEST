/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File ERRCortex.h                        */
/*                            By: Wu Xuekui                             */
/*                              2016-1-14                               */
/* ******************************************************************** */

#ifndef _ERRCORTEX_H

#define _ERRCORTEX_H

#ifdef   ERR_GLOBALS

#define  ERR_EXT  

#else

#define  ERR_EXT extern

#endif

/* ******************************************************************** */
/*  ERR_VERSION  = 10xx: VEC1000 Application                            */
/*  ERR_VERSION  = 40xx: VEC4000 Application                            */
/*  ERR_VERSION  = 68xx: VEC6800 Application                            */
/*  ERR_VERSION  = 69xx: VEC6900 Application                            */
/*  ERR_VERSION  = 760x: GEC7600-Main Application                       */
/*  ERR_VERSION  = 761x: GEC7600-Display Application                    */
/*  ERR_VERSION  = 780x: GEC7800-Main Application                       */
/*  ERR_VERSION  = 781x: GEC7800-Display Application                    */
/*  ERR_VERSION  = 80xx: VEC8000 Application                            */
/*  ERR_VERSION  = 90xx: VEC9000 Application                            */
/*  ERR_VERSION  = 96xx: VEC9600 Application                            */
/* ******************************************************************** */

#define ERR_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define ERR_1000_COMMON_ON       0
#define ERR_4000_COMMON_ON       0
#define ERR_6800_COMMON_ON       0
#define ERR_6900_COMMON_ON       0
#define ERR_7600_COMMON_ON       0
#define ERR_7600_MAIN_CHIP_ON    0
#define ERR_7600_AUX_CHIP_ON     0
#define ERR_7800_COMMON_ON       0
#define ERR_7800_MAIN_CHIP_ON    0
#define ERR_7800_AUX_CHIP_ON     0
#define ERR_8000_COMMON_ON       0
#define ERR_9000_COMMON_ON       0
#define ERR_9600_COMMON_ON       0
#if   ((ERR_VERSION / 100)   == 10)
#undef  ERR_1000_COMMON_ON
#define ERR_1000_COMMON_ON       1
#endif
#if   ((ERR_VERSION / 100)   == 40)
#undef  ERR_4000_COMMON_ON
#define ERR_4000_COMMON_ON       1
#endif
#if   ((ERR_VERSION / 100)   == 68)
#undef  ERR_6800_COMMON_ON
#define ERR_6800_COMMON_ON       1
#endif
#if   ((ERR_VERSION / 100)   == 69)
#undef  ERR_6900_COMMON_ON
#define ERR_6900_COMMON_ON       1
#endif
#if   ((ERR_VERSION / 100)   == 76)
#undef  ERR_7600_COMMON_ON
#define ERR_7600_COMMON_ON       1
#endif
#if   ((ERR_VERSION / 10)   == 760)
#undef  ERR_7600_MAIN_CHIP_ON
#define ERR_7600_MAIN_CHIP_ON    1
#endif
#if   ((ERR_VERSION / 10)   == 761)
#undef  ERR_7600_AUX_CHIP_ON
#define ERR_7600_AUX_CHIP_ON     1
#endif
#if   ((ERR_VERSION / 100)   == 78)
#undef  ERR_7800_COMMON_ON
#define ERR_7800_COMMON_ON       1
#endif
#if   ((ERR_VERSION / 10)   == 780)
#undef  ERR_7800_MAIN_CHIP_ON
#define ERR_7800_MAIN_CHIP_ON    1
#endif
#if   ((ERR_VERSION / 10)   == 781)
#undef  ERR_7800_AUX_CHIP_ON
#define ERR_7800_AUX_CHIP_ON     1
#endif
#if   ((ERR_VERSION / 100)   == 80)
#undef  ERR_8000_COMMON_ON
#define ERR_8000_COMMON_ON       1
#endif
#if   ((ERR_VERSION / 100)   == 90)
#undef  ERR_9000_COMMON_ON
#define ERR_9000_COMMON_ON       1
#endif
#if   ((ERR_VERSION / 100)   == 96)
#undef  ERR_9600_COMMON_ON
#define ERR_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       ERR1: Main Voltage/Power                       */
/* ******************************************************************** */
#define ERR_ES1_GET_BIT(m)      (uiDBmErrorStatus1 & (m))
#define ERR_ES1_SET_BIT(m)       uiDBmErrorStatus1 |= (m)        //市电报警、停机报警
#define ERR_ES1_CLR_BIT(m)       uiDBmErrorStatus1 &= ~(m)
#define ERR_ES1_STP_MAIN_VA_LOW (1UL << 0)
#define ERR_ES1_STP_MAIN_VA_HGH (1UL << 1)
#define ERR_ES1_STP_MAIN_VB_LOW (1UL << 2)
#define ERR_ES1_STP_MAIN_VB_HGH (1UL << 3)
#define ERR_ES1_STP_MAIN_VC_LOW (1UL << 4)
#define ERR_ES1_STP_MAIN_VC_HGH (1UL << 5)
#define ERR_ES1_STP_MAIN_F_LOW  (1UL << 6)
#define ERR_ES1_STP_MAIN_F_HGH  (1UL << 7)
#define ERR_ES1_STP_MAIN_PHASE  (1UL << 8)
#define ERR_ES1_STP_MAIN_P_ACT  (1UL << 9)
#define ERR_ES1_STP_MAIN_P_RCT  (1UL << 10)
#define ERR_ES1_STP_MAIN_P_APP  (1UL << 11)
#define ERR_ES1_STP_MAIN_ROCOF  (1UL << 12)
#define ERR_ES1_STP_MAIN_VECTOR (1UL << 13)
#define ERR_ES1_BACKUP1         (1UL << 14)
#define ERR_ES1_BACKUP2         (1UL << 15)
#define ERR_ES1_WRN_MAIN_VA_LOW (1UL << 16)
#define ERR_ES1_WRN_MAIN_VA_HGH (1UL << 17)
#define ERR_ES1_WRN_MAIN_VB_LOW (1UL << 18)
#define ERR_ES1_WRN_MAIN_VB_HGH (1UL << 19)
#define ERR_ES1_WRN_MAIN_VC_LOW (1UL << 20)
#define ERR_ES1_WRN_MAIN_VC_HGH (1UL << 21)
#define ERR_ES1_WRN_MAIN_F_LOW  (1UL << 22)
#define ERR_ES1_WRN_MAIN_F_HGH  (1UL << 23)
#define ERR_ES1_WRN_MAIN_PHASE  (1UL << 24)
#define ERR_ES1_WRN_MAIN_P_ACT  (1UL << 25)
#define ERR_ES1_WRN_MAIN_P_RCT  (1UL << 26)
#define ERR_ES1_WRN_MAIN_P_APP  (1UL << 27)
#define ERR_ES1_WRN_MAIN_ROCOF  (1UL << 28)
#define ERR_ES1_WRN_MAIN_VECTOR (1UL << 29)
#define ERR_ES1_STS_MAIN_V_LOST (1UL << 30)
#define ERR_ES1_BACKUP3         (1UL << 31)
#define ERR_ES1_EMERG_MSK       (0x00000000)
#define ERR_ES1_STOP_MSK        ( ERR_ES1_STP_MAIN_VA_LOW \
                                | ERR_ES1_STP_MAIN_VA_HGH \
                                | ERR_ES1_STP_MAIN_VB_LOW \
                                | ERR_ES1_STP_MAIN_VB_HGH \
                                | ERR_ES1_STP_MAIN_VC_LOW \
                                | ERR_ES1_STP_MAIN_VC_HGH \
                                | ERR_ES1_STP_MAIN_F_LOW \
                                | ERR_ES1_STP_MAIN_F_HGH \
                                | ERR_ES1_STP_MAIN_PHASE \
                                | ERR_ES1_STP_MAIN_P_ACT \
                                | ERR_ES1_STP_MAIN_P_RCT \
                                | ERR_ES1_STP_MAIN_P_APP \
                                | ERR_ES1_STP_MAIN_ROCOF \
                                | ERR_ES1_STP_MAIN_VECTOR )
#define ERR_ES1_WARN_MSK        ( ERR_ES1_WRN_MAIN_VA_LOW \
                                | ERR_ES1_WRN_MAIN_VA_HGH \
                                | ERR_ES1_WRN_MAIN_VB_LOW \
                                | ERR_ES1_WRN_MAIN_VB_HGH \
                                | ERR_ES1_WRN_MAIN_VC_LOW \
                                | ERR_ES1_WRN_MAIN_VC_HGH \
                                | ERR_ES1_WRN_MAIN_F_LOW \
                                | ERR_ES1_WRN_MAIN_F_HGH \
                                | ERR_ES1_WRN_MAIN_PHASE \
                                | ERR_ES1_WRN_MAIN_P_ACT \
                                | ERR_ES1_WRN_MAIN_P_RCT \
                                | ERR_ES1_WRN_MAIN_P_APP \
                                | ERR_ES1_WRN_MAIN_ROCOF \
                                | ERR_ES1_WRN_MAIN_VECTOR )

/* ******************************************************************** */
/*                         ERR2: Main Current                           */
/* ******************************************************************** */
#define ERR_ES2_GET_BIT(m)      (uiDBmErrorStatus2 & (m))
#define ERR_ES2_SET_BIT(m)       uiDBmErrorStatus2 |= (m)
#define ERR_ES2_CLR_BIT(m)       uiDBmErrorStatus2 &= ~(m)
#define ERR_ES2_STP_MAIN_SHRT_A (1UL << 0)
#define ERR_ES2_STP_MAIN_SHRT_B (1UL << 1)
#define ERR_ES2_STP_MAIN_SHRT_C (1UL << 2)
#define ERR_ES2_STP_MAIN_LONG_A (1UL << 3)
#define ERR_ES2_STP_MAIN_LONG_B (1UL << 4)
#define ERR_ES2_STP_MAIN_LONG_C (1UL << 5)
#define ERR_ES2_STP_MAIN_C_GND  (1UL << 6)
#define ERR_ES2_STP_MAIN_C_UNB  (1UL << 7)
#define ERR_ES2_BACKUP1         (1UL << 8)
#define ERR_ES2_BACKUP2         (1UL << 9)
#define ERR_ES2_BACKUP3         (1UL << 10)
#define ERR_ES2_BACKUP4         (1UL << 11)
#define ERR_ES2_BACKUP5         (1UL << 12)
#define ERR_ES2_BACKUP6         (1UL << 13)
#define ERR_ES2_BACKUP7         (1UL << 14)
#define ERR_ES2_BACKUP8         (1UL << 15)
#define ERR_ES2_WRN_MAIN_SHRT_A (1UL << 16)
#define ERR_ES2_WRN_MAIN_SHRT_B (1UL << 17)
#define ERR_ES2_WRN_MAIN_SHRT_C (1UL << 18)
#define ERR_ES2_WRN_MAIN_LONG_A (1UL << 19)
#define ERR_ES2_WRN_MAIN_LONG_B (1UL << 20)
#define ERR_ES2_WRN_MAIN_LONG_C (1UL << 21)
#define ERR_ES2_WRN_MAIN_C_GND  (1UL << 22)
#define ERR_ES2_WRN_MAIN_C_UNB  (1UL << 23)
#define ERR_ES2_BACKUP9         (1UL << 24)
#define ERR_ES2_BACKUP10        (1UL << 25)
#define ERR_ES2_BACKUP11        (1UL << 26)
#define ERR_ES2_BACKUP12        (1UL << 27)
#define ERR_ES2_BACKUP13        (1UL << 28)
#define ERR_ES2_BACKUP14        (1UL << 29)
#define ERR_ES2_BACKUP15        (1UL << 30)
#define ERR_ES2_BACKUP16        (1UL << 31)
#define ERR_ES2_EMERG_MSK       (0x00000000)
#define ERR_ES2_STOP_MSK        ( ERR_ES2_STP_MAIN_SHRT_A \
                                | ERR_ES2_STP_MAIN_SHRT_B \
                                | ERR_ES2_STP_MAIN_SHRT_C \
                                | ERR_ES2_STP_MAIN_LONG_A \
                                | ERR_ES2_STP_MAIN_LONG_B \
                                | ERR_ES2_STP_MAIN_LONG_C \
                                | ERR_ES2_STP_MAIN_C_GND \
                                | ERR_ES2_STP_MAIN_C_UNB )
#define ERR_ES2_WARN_MSK        ( ERR_ES2_WRN_MAIN_SHRT_A \
                                | ERR_ES2_WRN_MAIN_SHRT_B \
                                | ERR_ES2_WRN_MAIN_SHRT_C \
                                | ERR_ES2_WRN_MAIN_LONG_A \
                                | ERR_ES2_WRN_MAIN_LONG_B \
                                | ERR_ES2_WRN_MAIN_LONG_C \
                                | ERR_ES2_WRN_MAIN_C_GND \
                                | ERR_ES2_WRN_MAIN_C_UNB )

/* ******************************************************************** */
/*                     ERR3: Gens Voltage/Power                         */
/* ******************************************************************** */
#define ERR_ES3_GET_BIT(m)      (uiDBmErrorStatus3 & (m))
#define ERR_ES3_SET_BIT(m)       uiDBmErrorStatus3 |= (m)    //发电报警、停机报警
#define ERR_ES3_CLR_BIT(m)       uiDBmErrorStatus3 &= ~(m)
#define ERR_ES3_STP_GENS_VA_LOW (1UL << 0)
#define ERR_ES3_STP_GENS_VA_HGH (1UL << 1)
#define ERR_ES3_STP_GENS_VB_LOW (1UL << 2)
#define ERR_ES3_STP_GENS_VB_HGH (1UL << 3)
#define ERR_ES3_STP_GENS_VC_LOW (1UL << 4)
#define ERR_ES3_STP_GENS_VC_HGH (1UL << 5)
#define ERR_ES3_STP_GENS_F_LOW  (1UL << 6)
#define ERR_ES3_STP_GENS_F_HGH  (1UL << 7)
#define ERR_ES3_STP_GENS_PHASE  (1UL << 8)
#define ERR_ES3_STP_GENS_P_ACT  (1UL << 9)
#define ERR_ES3_STP_GENS_P_RCT  (1UL << 10)
#define ERR_ES3_STP_GENS_P_APP  (1UL << 11)
#define ERR_ES3_STP_GENS_P_INV  (1UL << 12)
#define ERR_ES3_STP_GENS_FACTOR (1UL << 13)
#define ERR_ES3_STP_GENS_M_LOST (1UL << 14)
#define ERR_ES3_STP_GENS_SYN_TO (1UL << 15)
#define ERR_ES3_WRN_GENS_VA_LOW (1UL << 16)
#define ERR_ES3_WRN_GENS_VA_HGH (1UL << 17)
#define ERR_ES3_WRN_GENS_VB_LOW (1UL << 18)
#define ERR_ES3_WRN_GENS_VB_HGH (1UL << 19)
#define ERR_ES3_WRN_GENS_VC_LOW (1UL << 20)
#define ERR_ES3_WRN_GENS_VC_HGH (1UL << 21)
#define ERR_ES3_WRN_GENS_F_LOW  (1UL << 22)
#define ERR_ES3_WRN_GENS_F_HGH  (1UL << 23)
#define ERR_ES3_WRN_GENS_PHASE  (1UL << 24)
#define ERR_ES3_WRN_GENS_P_ACT  (1UL << 25)
#define ERR_ES3_WRN_GENS_P_RCT  (1UL << 26)
#define ERR_ES3_WRN_GENS_P_APP  (1UL << 27)
#define ERR_ES3_WRN_GENS_P_INV  (1UL << 28)
#define ERR_ES3_WRN_GENS_FACTOR (1UL << 29)
#define ERR_ES3_WRN_GENS_M_LOST (1UL << 30)
#define ERR_ES3_WRN_GENS_SYN_TO (1UL << 31)
#define ERR_ES3_EMERG_MSK       ( ERR_ES3_STP_GENS_F_HGH )
#define ERR_ES3_STOP_MSK        ( ERR_ES3_STP_GENS_VA_LOW \
                                | ERR_ES3_STP_GENS_VA_HGH \
                                | ERR_ES3_STP_GENS_VB_LOW \
                                | ERR_ES3_STP_GENS_VB_HGH \
                                | ERR_ES3_STP_GENS_VC_LOW \
                                | ERR_ES3_STP_GENS_VC_HGH \
                                | ERR_ES3_STP_GENS_F_LOW \
                                | ERR_ES3_STP_GENS_F_HGH \
                                | ERR_ES3_STP_GENS_PHASE \
                                | ERR_ES3_STP_GENS_P_ACT \
                                | ERR_ES3_STP_GENS_P_RCT \
                                | ERR_ES3_STP_GENS_P_APP \
                                | ERR_ES3_STP_GENS_P_INV \
                                | ERR_ES3_STP_GENS_FACTOR \
                                | ERR_ES3_STP_GENS_M_LOST \
                                | ERR_ES3_STP_GENS_SYN_TO )
#define ERR_ES3_WARN_MSK        ( ERR_ES3_WRN_GENS_VA_LOW \
                                | ERR_ES3_WRN_GENS_VA_HGH \
                                | ERR_ES3_WRN_GENS_VB_LOW \
                                | ERR_ES3_WRN_GENS_VB_HGH \
                                | ERR_ES3_WRN_GENS_VC_LOW \
                                | ERR_ES3_WRN_GENS_VC_HGH \
                                | ERR_ES3_WRN_GENS_F_LOW \
                                | ERR_ES3_WRN_GENS_F_HGH \
                                | ERR_ES3_WRN_GENS_PHASE \
                                | ERR_ES3_WRN_GENS_P_ACT \
                                | ERR_ES3_WRN_GENS_P_RCT \
                                | ERR_ES3_WRN_GENS_P_APP \
                                | ERR_ES3_WRN_GENS_P_INV \
                                | ERR_ES3_WRN_GENS_FACTOR \
                                | ERR_ES3_WRN_GENS_M_LOST \
                                | ERR_ES3_WRN_GENS_SYN_TO )

/* ******************************************************************** */
/*                     ERR4: Gens Current                               */
/* ******************************************************************** */
#define ERR_ES4_GET_BIT(m)      (uiDBmErrorStatus4 & (m))
#define ERR_ES4_SET_BIT(m)       uiDBmErrorStatus4 |= (m)
#define ERR_ES4_CLR_BIT(m)       uiDBmErrorStatus4 &= ~(m)
#define ERR_ES4_STP_GENS_SHRT_A (1UL << 0)
#define ERR_ES4_STP_GENS_SHRT_B (1UL << 1)
#define ERR_ES4_STP_GENS_SHRT_C (1UL << 2)
#define ERR_ES4_STP_GENS_LONG_A (1UL << 3)
#define ERR_ES4_STP_GENS_LONG_B (1UL << 4)
#define ERR_ES4_STP_GENS_LONG_C (1UL << 5)
#define ERR_ES4_STP_GENS_C_GND  (1UL << 6)
#define ERR_ES4_STP_GENS_C_UNB  (1UL << 7)
#define ERR_ES4_BACKUP1         (1UL << 8)
#define ERR_ES4_BACKUP2         (1UL << 9)
#define ERR_ES4_BACKUP3         (1UL << 10)
#define ERR_ES4_BACKUP4         (1UL << 11)
#define ERR_ES4_BACKUP5         (1UL << 12)
#define ERR_ES4_BACKUP6         (1UL << 13)
#define ERR_ES4_BACKUP7         (1UL << 14)
#define ERR_ES4_BACKUP8         (1UL << 15)
#define ERR_ES4_WRN_GENS_SHRT_A (1UL << 16)
#define ERR_ES4_WRN_GENS_SHRT_B (1UL << 17)
#define ERR_ES4_WRN_GENS_SHRT_C (1UL << 18)
#define ERR_ES4_WRN_GENS_LONG_A (1UL << 19)
#define ERR_ES4_WRN_GENS_LONG_B (1UL << 20)
#define ERR_ES4_WRN_GENS_LONG_C (1UL << 21)
#define ERR_ES4_WRN_GENS_C_GND  (1UL << 22)
#define ERR_ES4_WRN_GENS_C_UNB  (1UL << 23)
#define ERR_ES4_BACKUP9         (1UL << 24)
#define ERR_ES4_BACKUP10        (1UL << 25)
#define ERR_ES4_BACKUP11        (1UL << 26)
#define ERR_ES4_BACKUP12        (1UL << 27)
#define ERR_ES4_BACKUP13        (1UL << 28)
#define ERR_ES4_BACKUP14        (1UL << 29)
#define ERR_ES4_BACKUP15        (1UL << 30)
#define ERR_ES4_BACKUP16        (1UL << 31)
#define ERR_ES4_EMERG_MSK       (0x00000000)
#define ERR_ES4_STOP_MSK        ( ERR_ES4_STP_GENS_SHRT_A \
                                | ERR_ES4_STP_GENS_SHRT_B \
                                | ERR_ES4_STP_GENS_SHRT_C \
                                | ERR_ES4_STP_GENS_LONG_A \
                                | ERR_ES4_STP_GENS_LONG_B \
                                | ERR_ES4_STP_GENS_LONG_C \
                                | ERR_ES4_STP_GENS_C_GND \
                                | ERR_ES4_STP_GENS_C_UNB )
#define ERR_ES4_WARN_MSK        ( ERR_ES4_WRN_GENS_SHRT_A \
                                | ERR_ES4_WRN_GENS_SHRT_B \
                                | ERR_ES4_WRN_GENS_SHRT_C \
                                | ERR_ES4_WRN_GENS_LONG_A \
                                | ERR_ES4_WRN_GENS_LONG_B \
                                | ERR_ES4_WRN_GENS_LONG_C \
                                | ERR_ES4_WRN_GENS_C_GND \
                                | ERR_ES4_WRN_GENS_C_UNB )

/* ******************************************************************** */
/*                            ERR5: Engine                              */
/* ******************************************************************** */
#define ERR_ES5_GET_BIT(m)      (uiDBmErrorStatus5 & (m))
#define ERR_ES5_SET_BIT(m)       uiDBmErrorStatus5 |= (m)    //传感器报警、停机报警
#define ERR_ES5_CLR_BIT(m)       uiDBmErrorStatus5 &= ~(m)
#define ERR_ES5_STP_SPEED_LOW   (1UL << 0)
#define ERR_ES5_STP_SPEED_HGH   (1UL << 1)
#define ERR_ES5_STP_SPEED_DELTA (1UL << 2)
#define ERR_ES5_STP_START_FAIL  (1UL << 3)
#define ERR_ES5_STP_RAMP_FAIL   (1UL << 4)
#define ERR_ES5_STP_STOP_FAIL   (1UL << 5)
#define ERR_ES5_STP_TEMP_COOL   (1UL << 6)
#define ERR_ES5_STP_TEMP_OIL    (1UL << 7)
#define ERR_ES5_STP_PRES_OIL    (1UL << 8)
#define ERR_ES5_STP_LVL_FUEL    (1UL << 9)
#define ERR_ES5_STP_LVL_COOL    (1UL << 10)
#define ERR_ES5_STP_TEMP_PCB    (1UL << 11)
#define ERR_ES5_STP_VOLT_CHARG  (1UL << 12)
#define ERR_ES5_STP_VOLT_BATT1  (1UL << 13)
#define ERR_ES5_STP_VOLT_BATT2  (1UL << 14)
#define ERR_ES5_STP_AIR_FILTER  (1UL << 15)
#define ERR_ES5_WRN_SPEED_LOW   (1UL << 16)
#define ERR_ES5_WRN_SPEED_HGH   (1UL << 17)
#define ERR_ES5_WRN_SPEED_DELTA (1UL << 18)
#define ERR_ES5_WRN_START_FAIL  (1UL << 19)
#define ERR_ES5_WRN_RAMP_FAIL   (1UL << 20)
#define ERR_ES5_WRN_STOP_FAIL   (1UL << 21)
#define ERR_ES5_WRN_TEMP_COOL   (1UL << 22)
#define ERR_ES5_WRN_TEMP_OIL    (1UL << 23)
#define ERR_ES5_WRN_PRES_OIL    (1UL << 24)
#define ERR_ES5_WRN_LVL_FUEL    (1UL << 25)
#define ERR_ES5_WRN_LVL_COOL    (1UL << 26)
#define ERR_ES5_WRN_TEMP_PCB    (1UL << 27)
#define ERR_ES5_WRN_VOLT_CHARG  (1UL << 28)
#define ERR_ES5_WRN_VOLT_BATT1  (1UL << 29)
#define ERR_ES5_WRN_VOLT_BATT2  (1UL << 30)
#define ERR_ES5_WRN_AIR_FILTER  (1UL << 31)
#define ERR_ES5_EMERG_MSK       ( ERR_ES5_STP_SPEED_HGH \
                                | ERR_ES5_STP_STOP_FAIL \
                                | ERR_ES5_STP_TEMP_COOL \
                                | ERR_ES5_STP_PRES_OIL )
#define ERR_ES5_STOP_MSK        ( ERR_ES5_STP_SPEED_LOW \
                                | ERR_ES5_STP_SPEED_DELTA \
                                | ERR_ES5_STP_START_FAIL \
                                | ERR_ES5_STP_RAMP_FAIL \
                                | ERR_ES5_STP_TEMP_OIL \
                                | ERR_ES5_STP_LVL_FUEL \
                                | ERR_ES5_STP_LVL_COOL \
                                | ERR_ES5_STP_TEMP_PCB \
                                | ERR_ES5_STP_VOLT_CHARG \
                                | ERR_ES5_STP_VOLT_BATT1 \
                                | ERR_ES5_STP_VOLT_BATT2 \
                                | ERR_ES5_STP_AIR_FILTER )
#define ERR_ES5_WARN_MSK        ( ERR_ES5_WRN_SPEED_LOW \
                                | ERR_ES5_WRN_SPEED_HGH \
                                | ERR_ES5_WRN_SPEED_DELTA \
                                | ERR_ES5_WRN_START_FAIL \
                                | ERR_ES5_WRN_RAMP_FAIL \
                                | ERR_ES5_WRN_STOP_FAIL \
                                | ERR_ES5_WRN_TEMP_COOL \
                                | ERR_ES5_WRN_TEMP_OIL \
                                | ERR_ES5_WRN_PRES_OIL \
                                | ERR_ES5_WRN_LVL_FUEL \
                                | ERR_ES5_WRN_LVL_COOL \
                                | ERR_ES5_WRN_TEMP_PCB \
                                | ERR_ES5_WRN_VOLT_CHARG \
                                | ERR_ES5_WRN_VOLT_BATT1 \
                                | ERR_ES5_WRN_VOLT_BATT2 \
                                | ERR_ES5_WRN_AIR_FILTER )

/* ******************************************************************** */
/*                            ERR6: Sensors                             */
/* ******************************************************************** */
#define ERR_ES6_GET_BIT(m)      (uiDBmErrorStatus6 & (m))
#define ERR_ES6_SET_BIT(m)       uiDBmErrorStatus6 |= (m)
#define ERR_ES6_CLR_BIT(m)       uiDBmErrorStatus6 &= ~(m)
#define ERR_ES6_STP_SEN_T_COOL  (1UL << 0)
#define ERR_ES6_STP_SEN_T_OIL   (1UL << 1)
#define ERR_ES6_STP_SEN_P_OIL   (1UL << 2)
#define ERR_ES6_STP_SEN_L_FUEL  (1UL << 3)
#define ERR_ES6_STP_SEN_L_COOL  (1UL << 4)
#define ERR_ES6_STP_SEN_C_CHARG (1UL << 5)
#define ERR_ES6_STP_DATA_READ   (1UL << 6)
#define ERR_ES6_STP_DATA_WRITE  (1UL << 7)
#define ERR_ES6_STP_DATA_CHECK  (1UL << 8)
#define ERR_ES6_STP_CAN1        (1UL << 9)
#define ERR_ES6_STP_CAN2        (1UL << 10)
#define ERR_ES6_BACKUP1         (1UL << 11)
#define ERR_ES6_BACKUP2         (1UL << 12)
#define ERR_ES6_BACKUP3         (1UL << 13)
#define ERR_ES6_BACKUP4         (1UL << 14)
#define ERR_ES6_BACKUP5         (1UL << 15)
#define ERR_ES6_WRN_SEN_T_COOL  (1UL << 16)
#define ERR_ES6_WRN_SEN_T_OIL   (1UL << 17)
#define ERR_ES6_WRN_SEN_P_OIL   (1UL << 18)
#define ERR_ES6_WRN_SEN_L_FUEL  (1UL << 19)
#define ERR_ES6_WRN_SEN_L_COOL  (1UL << 20)
#define ERR_ES6_WRN_SEN_C_CHARG (1UL << 21)
#define ERR_ES6_WRN_DATA_READ   (1UL << 22)
#define ERR_ES6_WRN_DATA_WRITE  (1UL << 23)
#define ERR_ES6_WRN_DATA_CHECK  (1UL << 24)
#define ERR_ES6_WRN_CAN1        (1UL << 25)
#define ERR_ES6_WRN_CAN2        (1UL << 26)
#define ERR_ES6_BACKUP6         (1UL << 27)
#define ERR_ES6_BACKUP7         (1UL << 28)
#define ERR_ES6_BACKUP8         (1UL << 29)
#define ERR_ES6_BACKUP9         (1UL << 30)
#define ERR_ES6_BACKUP10        (1UL << 31)
#define ERR_ES6_EMERG_MSK       (0x00000000)
#define ERR_ES6_STOP_MSK        ( ERR_ES6_STP_SEN_T_OIL \
                                | ERR_ES6_STP_SEN_T_COOL \
                                | ERR_ES6_STP_SEN_P_OIL \
                                | ERR_ES6_STP_SEN_L_FUEL \
                                | ERR_ES6_STP_SEN_L_COOL \
                                | ERR_ES6_STP_SEN_C_CHARG \
                                | ERR_ES6_STP_DATA_READ \
                                | ERR_ES6_STP_DATA_WRITE \
                                | ERR_ES6_STP_DATA_CHECK \
                                | ERR_ES6_STP_CAN1 \
                                | ERR_ES6_STP_CAN2 )
#define ERR_ES6_WARN_MSK        ( ERR_ES6_WRN_SEN_T_OIL \
                                | ERR_ES6_WRN_SEN_T_COOL \
                                | ERR_ES6_WRN_SEN_P_OIL \
                                | ERR_ES6_WRN_SEN_L_FUEL \
                                | ERR_ES6_WRN_SEN_L_COOL \
                                | ERR_ES6_WRN_SEN_C_CHARG \
                                | ERR_ES6_WRN_DATA_READ \
                                | ERR_ES6_WRN_DATA_WRITE \
                                | ERR_ES6_WRN_DATA_CHECK \
                                | ERR_ES6_WRN_CAN1 \
                                | ERR_ES6_WRN_CAN2 )

/* ******************************************************************** */
/*                            ERR7: Status                              */
/* ******************************************************************** */
#define ERR_ES7_GET_BIT(m)      (uiDBmErrorStatus7 & (m))
#define ERR_ES7_SET_BIT(m)       uiDBmErrorStatus7 |= (m)
#define ERR_ES7_CLR_BIT(m)       uiDBmErrorStatus7 &= ~(m)
#define ERR_ES7_SYN_MAIN_V_LOW  (1UL << 0)
#define ERR_ES7_SYN_MAIN_V_HGH  (1UL << 1)
#define ERR_ES7_SYN_MAIN_F_LOW  (1UL << 2)
#define ERR_ES7_SYN_MAIN_F_HGH  (1UL << 3)
#define ERR_ES7_LD_GENS_V_LOW   (1UL << 4)
#define ERR_ES7_LD_GENS_F_LOW   (1UL << 5)
#define ERR_ES7_LD_SCHED_LOW    (1UL << 6)
#define ERR_ES7_LD_SCHED_HGH    (1UL << 7)
#define ERR_ES7_LD_SCHED_STOP   (1UL << 8)
#define ERR_ES7_KEY_TO_SWON     (1UL << 9)
#define ERR_ES7_KEY_TO_STOP     (1UL << 10)
#define ERR_ES7_KEY_TO_AUTO     (1UL << 11)
#define ERR_ES7_SWT_TO_STOP     (1UL << 12)
#define ERR_ES7_BACKUP4         (1UL << 13)
#define ERR_ES7_BACKUP5         (1UL << 14)
#define ERR_ES7_BACKUP6         (1UL << 15)
#define ERR_ES7_BACKUP7         (1UL << 16)
#define ERR_ES7_BACKUP8         (1UL << 17)
#define ERR_ES7_BACKUP9         (1UL << 18)
#define ERR_ES7_BACKUP10        (1UL << 19)
#define ERR_ES7_BACKUP11        (1UL << 20)
#define ERR_ES7_BACKUP12        (1UL << 21)
#define ERR_ES7_BACKUP13        (1UL << 22)
#define ERR_ES7_BACKUP14        (1UL << 23)
#define ERR_ES7_BACKUP15        (1UL << 24)
#define ERR_ES7_BACKUP16        (1UL << 25)
#define ERR_ES7_BACKUP17        (1UL << 26)
#define ERR_ES7_BACKUP18        (1UL << 27)
#define ERR_ES7_BACKUP19        (1UL << 28)
#define ERR_ES7_BACKUP20        (1UL << 29)
#define ERR_ES7_BACKUP21        (1UL << 30)
#define ERR_ES7_BACKUP22        (1UL << 31)
#define ERR_ES7_EMERG_MSK       (0x00000000)
#define ERR_ES7_STOP_MSK        (0x00000000)
#define ERR_ES7_WARN_MSK        (0x00000000)
#define ERR_ES7_SYNC_MSK        ( ERR_ES7_SYN_MAIN_V_LOW \
                                | ERR_ES7_SYN_MAIN_V_HGH \
                                | ERR_ES7_SYN_MAIN_F_LOW \
                                | ERR_ES7_SYN_MAIN_F_HGH )
#define ERR_ES7_LOAD_MSK        ( ERR_ES7_LD_GENS_V_LOW \
                                | ERR_ES7_LD_GENS_F_LOW )

/* ******************************************************************** */
/*                            ERR8: Backup                              */
/* ******************************************************************** */
#define ERR_ES8_GET_BIT(m)      (uiDBmErrorStatus8 & (m))
#define ERR_ES8_SET_BIT(m)       uiDBmErrorStatus8 |= (m)
#define ERR_ES8_CLR_BIT(m)       uiDBmErrorStatus8 &= ~(m)
#define ERR_ES8_EMERG_MSK       (0x00000000)
#define ERR_ES8_STOP_MSK        (0x00000000)
#define ERR_ES8_WARN_MSK        (0x00000000)

/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                               The END                                */
/* ******************************************************************** */
