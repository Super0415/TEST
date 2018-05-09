/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File XIOCortex.h                        */
/*                            By: Wu Xuekui                             */
/*                              2016-1-14                               */
/* ******************************************************************** */

#ifndef _XIOCORTEX_H

#define _XIOCORTEX_H

#ifdef   XIO_GLOBALS

#define  XIO_EXT  

#else

#define  XIO_EXT extern

#endif

/* ******************************************************************** */
/*  XIO_VERSION  = 10xx: VEC1000 Application                            */
/*  XIO_VERSION  = 40xx: VEC4000 Application                            */
/*  XIO_VERSION  = 68xx: VEC6800 Application                            */
/*  XIO_VERSION  = 69xx: VEC6900 Application                            */
/*  XIO_VERSION  = 760x: GEC7600-Main Application                       */
/*  XIO_VERSION  = 761x: GEC7600-Display Application                    */
/*  XIO_VERSION  = 780x: GEC7800-Main Application                       */
/*  XIO_VERSION  = 781x: GEC7800-Display Application                    */
/*  XIO_VERSION  = 80xx: VEC8000 Application                            */
/*  XIO_VERSION  = 90xx: VEC9000 Application                            */
/*  XIO_VERSION  = 96xx: VEC9600 Application                            */
/* ******************************************************************** */

//#define XIO_VERSION           7800
#define XIO_VERSION           4800

#define Change_Pin  1   //@@@@@@@@@@@@@@@@@@@@@ZC 删除

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define XIO_1000_COMMON_ON       0
#define XIO_4000_COMMON_ON       0
#define XIO_6800_COMMON_ON       0
#define XIO_6900_COMMON_ON       0
#define XIO_7600_COMMON_ON       0
#define XIO_7600_MAIN_CHIP_ON    0
#define XIO_7600_AUX_CHIP_ON     0
//@@@@@@@@@@@@@@@@@@@@ZC
#define XIO_4800_COMMON_ON       0
#define XIO_4800_MAIN_CHIP_ON    0
#define XIO_4800_AUX_CHIP_ON     0
//@@@@@@@@@@@@@@@@@@@@ZC

#define XIO_7800_COMMON_ON       0
#define XIO_7800_MAIN_CHIP_ON    0
#define XIO_7800_AUX_CHIP_ON     0
#define XIO_8000_COMMON_ON       0
#define XIO_9000_COMMON_ON       0
#define XIO_9600_COMMON_ON       0
#if   ((XIO_VERSION / 100)   == 10)
#undef  XIO_1000_COMMON_ON
#define XIO_1000_COMMON_ON       1
#endif
#if   ((XIO_VERSION / 100)   == 40)
#undef  XIO_4000_COMMON_ON
#define XIO_4000_COMMON_ON       1
#endif
#if   ((XIO_VERSION / 100)   == 68)
#undef  XIO_6800_COMMON_ON
#define XIO_6800_COMMON_ON       1
#endif
#if   ((XIO_VERSION / 100)   == 69)
#undef  XIO_6900_COMMON_ON
#define XIO_6900_COMMON_ON       1
#endif
#if   ((XIO_VERSION / 100)   == 76)
#undef  XIO_7600_COMMON_ON
#define XIO_7600_COMMON_ON       1
#endif
#if   ((XIO_VERSION / 10)   == 760)
#undef  XIO_7600_MAIN_CHIP_ON
#define XIO_7600_MAIN_CHIP_ON    1
#endif
#if   ((XIO_VERSION / 10)   == 761)
#undef  XIO_7600_AUX_CHIP_ON
#define XIO_7600_AUX_CHIP_ON     1
#endif
//@@@@@@@@@@@@@ZC
#if   ((XIO_VERSION / 100)   == 48)
#undef  XIO_4800_COMMON_ON
#define XIO_4800_COMMON_ON       1
#endif
#if   ((XIO_VERSION / 10)   == 480)
#undef  XIO_4800_MAIN_CHIP_ON
#define XIO_4800_MAIN_CHIP_ON    1
#endif
//@@@@@@@@@@@@ZC
#if   ((XIO_VERSION / 100)   == 78)
#undef  XIO_7800_COMMON_ON
#define XIO_7800_COMMON_ON       1
#endif
#if   ((XIO_VERSION / 10)   == 780)
#undef  XIO_7800_MAIN_CHIP_ON
#define XIO_7800_MAIN_CHIP_ON    1
#endif
#if   ((XIO_VERSION / 10)   == 781)
#undef  XIO_7800_AUX_CHIP_ON
#define XIO_7800_AUX_CHIP_ON     1
#endif
#if   ((XIO_VERSION / 100)   == 80)
#undef  XIO_8000_COMMON_ON
#define XIO_8000_COMMON_ON       1
#endif
#if   ((XIO_VERSION / 100)   == 90)
#undef  XIO_9000_COMMON_ON
#define XIO_9000_COMMON_ON       1
#endif
#if   ((XIO_VERSION / 100)   == 96)
#undef  XIO_9600_COMMON_ON
#define XIO_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define XIO_CPU_9S12_ON          0
#define XIO_CPU_POWERPC_ON       0
#define XIO_CPU_STM32F1_ON       0
#define XIO_CPU_STM32F103_ON     0
#define XIO_CPU_STM32F105_ON     0
#if    (XIO_1000_COMMON_ON    == 1)
#undef  XIO_CPU_9S12_ON
#define XIO_CPU_9S12_ON          1
#endif
#if    (XIO_4000_COMMON_ON    == 1)
#undef  XIO_CPU_9S12_ON
#define XIO_CPU_9S12_ON          1
#endif
#if    (XIO_6800_COMMON_ON    == 1)
#undef  XIO_CPU_9S12_ON
#define XIO_CPU_9S12_ON          1
#endif
#if    (XIO_6900_COMMON_ON    == 1)
#undef  XIO_CPU_POWERPC_ON
#define XIO_CPU_POWERPC_ON       1
#endif
#if    (XIO_7600_COMMON_ON    == 1)
#undef  XIO_CPU_STM32F1_ON
#define XIO_CPU_STM32F1_ON       1
#endif
#if    (XIO_7600_MAIN_CHIP_ON == 1)
#undef  XIO_CPU_STM32F105_ON
#define XIO_CPU_STM32F105_ON     1
#endif
#if    (XIO_7600_AUX_CHIP_ON  == 1)
#undef  XIO_CPU_STM32F103_ON
#define XIO_CPU_STM32F103_ON     1
#endif
//@@@@@@@@@@@@@@@ZC
#if    (XIO_4800_COMMON_ON    == 1)
#undef  XIO_CPU_STM32F1_ON
#define XIO_CPU_STM32F1_ON       1
#endif
#if    (XIO_4800_MAIN_CHIP_ON == 1)
#undef  XIO_CPU_STM32F105_ON
#define XIO_CPU_STM32F105_ON     1
#endif
//@@@@@@@@@@@@@@@ZC
#if    (XIO_7800_COMMON_ON    == 1)
#undef  XIO_CPU_STM32F1_ON
#define XIO_CPU_STM32F1_ON       1
#endif
#if    (XIO_7800_MAIN_CHIP_ON == 1)
#undef  XIO_CPU_STM32F105_ON
#define XIO_CPU_STM32F105_ON     1
#endif
#if    (XIO_7800_AUX_CHIP_ON  == 1)
#undef  XIO_CPU_STM32F103_ON
#define XIO_CPU_STM32F103_ON     1
#endif
#if    (XIO_8000_COMMON_ON    == 1)
#undef  XIO_CPU_POWERPC_ON
#define XIO_CPU_POWERPC_ON       1
#endif
#if    (XIO_9000_COMMON_ON    == 1)
#undef  XIO_CPU_POWERPC_ON
#define XIO_CPU_POWERPC_ON       1
#endif
#if    (XIO_9600_COMMON_ON    == 1)
#undef  XIO_CPU_POWERPC_ON
#define XIO_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                           Basis Definition                           */
/* ******************************************************************** */
#define XIO_TRUE                 1
#define XIO_FALSE                0
#define XIO_NO_ERR               0
#define XIO_ERR_BUSY             1
#define XIO_STS_NORMAL           0x00000000
#define XIO_STS_INT_DMA1_CH1     0x00000001
#define XIO_STS_INT_DMA2_CH1     0x00000002
#define XIO_STS_HARDPRD0_ERR     0x00000004
#define XIO_STS_HARDPRD1_ERR     0x00000008
#define XIO_STS_HARDPRD_BOTH    (XIO_STS_HARDPRD0_ERR | XIO_STS_HARDPRD1_ERR)
#define XIO_STS_GET_BIT(m)      (uiXIOStatus & (m))
#define XIO_STS_CLR_BIT(m)       uiXIOStatus &= ~(m)
#define XIO_STS_SET_BIT(m)       uiXIOStatus |= (m)
#define XIO_GET_FREE_TIMER()    (TIM2->CNT)

/* ******************************************************************** */
/*                            Port Config                               */
/* ******************************************************************** */
#if    (XIO_CPU_STM32F1_ON == 1)
/* ************************ GPIO Remap Codes ************************** */
#define XIO_Remap_SPI1             ((INT32U)0x00000001)
#define XIO_Remap_I2C1             ((INT32U)0x00000002)
#define XIO_Remap_USART1           ((INT32U)0x00000004)
#define XIO_Remap_USART2           ((INT32U)0x00000008)
#define XIO_PartialRemap_USART3    ((INT32U)0x00140010)
#define XIO_FullRemap_USART3       ((INT32U)0x00140030)
#define XIO_PartialRemap_TIM1      ((INT32U)0x00160040)
#define XIO_FullRemap_TIM1         ((INT32U)0x001600C0)
#define XIO_PartialRemap1_TIM2     ((INT32U)0x00180100)
#define XIO_PartialRemap2_TIM2     ((INT32U)0x00180200)
#define XIO_FullRemap_TIM2         ((INT32U)0x00180300)
#define XIO_PartialRemap_TIM3      ((INT32U)0x001A0800)
#define XIO_FullRemap_TIM3         ((INT32U)0x001A0C00)
#define XIO_Remap_TIM4             ((INT32U)0x00001000)
#define XIO_Remap1_CAN1            ((INT32U)0x001D4000)
#define XIO_Remap2_CAN1            ((INT32U)0x001D6000)
#define XIO_Remap_PD01             ((INT32U)0x00008000)
#define XIO_Remap_TIM5CH4_LSI      ((INT32U)0x00200001)
#define XIO_Remap_ADC1_ETRGINJ     ((INT32U)0x00200002)
#define XIO_Remap_ADC1_ETRGREG     ((INT32U)0x00200004)
#define XIO_Remap_ADC2_ETRGINJ     ((INT32U)0x00200008)
#define XIO_Remap_ADC2_ETRGREG     ((INT32U)0x00200010)
#define XIO_Remap_ETH              ((INT32U)0x00200020)
#define XIO_Remap_CAN2             ((INT32U)0x00200040)
#define XIO_Remap_SWJ_NoJTRST      ((INT32U)0x00300100)
#define XIO_Remap_SWJ_JTAGDisable  ((INT32U)0x00300200)
#define XIO_Remap_SWJ_Disable      ((INT32U)0x00300400)
#define XIO_Remap_SPI3             ((INT32U)0x00201100)
#define XIO_Remap_TIM2ITR1_PTP_SOF ((INT32U)0x00202000)
#define XIO_Remap_PTP_PPS          ((INT32U)0x00204000)
#define XIO_Remap_TIM15            ((INT32U)0x80000001)
#define XIO_Remap_TIM16            ((INT32U)0x80000002)
#define XIO_Remap_TIM17            ((INT32U)0x80000004)
#define XIO_Remap_CEC              ((INT32U)0x80000008)
#define XIO_Remap_TIM1_DMA         ((INT32U)0x80000010)
#define XIO_Remap_TIM9             ((INT32U)0x80000020)
#define XIO_Remap_TIM10            ((INT32U)0x80000040)
#define XIO_Remap_TIM11            ((INT32U)0x80000080)
#define XIO_Remap_TIM13            ((INT32U)0x80000100)
#define XIO_Remap_TIM14            ((INT32U)0x80000200)
#define XIO_Remap_FSMC_NADV        ((INT32U)0x80000400)
#define XIO_Remap_TIM67_DAC_DMA    ((INT32U)0x80000800)
#define XIO_Remap_TIM12            ((INT32U)0x80001000)
#define XIO_Remap_MISC             ((INT32U)0x80002000)
/* *************************** GPIO Config **************************** */
#define XIO_PT_MOD_IN           (INT32U)(0x00)
#define XIO_PT_MOD_10M          (INT32U)(0x01)
#define XIO_PT_MOD_02M          (INT32U)(0x02)
#define XIO_PT_MOD_50M          (INT32U)(0x03)
#define XIO_PT_IN_ANALOG        (INT32U)(0x00 << 2)
#define XIO_PT_IN_FLOAT         (INT32U)(0x01 << 2)
#define XIO_PT_IN_PULL          (INT32U)(0x02 << 2)
#define XIO_PT_OUT_PP           (INT32U)(0x00 << 2)
#define XIO_PT_OUT_OD           (INT32U)(0x01 << 2)
#define XIO_PT_ALT_PP           (INT32U)(0x02 << 2)
#define XIO_PT_ALT_OD           (INT32U)(0x03 << 2)
#define XIO_PT_GPI_ANALOG       (XIO_PT_MOD_IN + XIO_PT_IN_ANALOG)
#define XIO_PT_GPI_FLOAT        (XIO_PT_MOD_IN + XIO_PT_IN_FLOAT)
#define XIO_PT_GPI_PULL         (XIO_PT_MOD_IN + XIO_PT_IN_PULL)
#define XIO_PT_GPO_PP_10M       (XIO_PT_OUT_PP + XIO_PT_MOD_10M)
#define XIO_PT_GPO_OD_10M       (XIO_PT_OUT_OD + XIO_PT_MOD_10M)
#define XIO_PT_ALT_PP_10M       (XIO_PT_ALT_PP + XIO_PT_MOD_10M)
#define XIO_PT_ALT_OD_10M       (XIO_PT_ALT_OD + XIO_PT_MOD_10M)
#define XIO_PT_GPO_PP_02M       (XIO_PT_OUT_PP + XIO_PT_MOD_02M)
#define XIO_PT_GPO_OD_02M       (XIO_PT_OUT_OD + XIO_PT_MOD_02M)
#define XIO_PT_ALT_PP_02M       (XIO_PT_ALT_PP + XIO_PT_MOD_02M)
#define XIO_PT_ALT_OD_02M       (XIO_PT_ALT_OD + XIO_PT_MOD_02M)
#define XIO_PT_GPO_PP_50M       (XIO_PT_OUT_PP + XIO_PT_MOD_50M)
#define XIO_PT_GPO_OD_50M       (XIO_PT_OUT_OD + XIO_PT_MOD_50M)
#define XIO_PT_ALT_PP_50M       (XIO_PT_ALT_PP + XIO_PT_MOD_50M)
#define XIO_PT_ALT_OD_50M       (XIO_PT_ALT_OD + XIO_PT_MOD_50M)
#define XIO_PT_SET_0            (INT16U)0
#define XIO_PT_SET_1            (INT16U)1
#define XIO_PT_BT0              (INT08U)0
#define XIO_PT_BT1              (INT08U)1
#define XIO_PT_BT2              (INT08U)2
#define XIO_PT_BT3              (INT08U)3
#define XIO_PT_BT4              (INT08U)4
#define XIO_PT_BT5              (INT08U)5
#define XIO_PT_BT6              (INT08U)6
#define XIO_PT_BT7              (INT08U)7
#define XIO_PT_BT8              (INT08U)8
#define XIO_PT_BT9              (INT08U)9
#define XIO_PT_BT10             (INT08U)10
#define XIO_PT_BT11             (INT08U)11
#define XIO_PT_BT12             (INT08U)12
#define XIO_PT_BT13             (INT08U)13
#define XIO_PT_BT14             (INT08U)14
#define XIO_PT_BT15             (INT08U)15
#endif

/* ******************************************************************** */
/*                    Analog Input Channel Definition                   */
/* ******************************************************************** */
/* **************** ADC2 (CPU Temperature) Definitions **************** */
#define XIO_NUM_OF_ADC2         (INT32U)1
#define XIO_ADC2_SMPL_CYC       (INT32U)3                /* 28.5 Cycles */
#define XIO_ADC2_CH_1ST         (INT32U)0
#define XIO_ADC2_CH_2ND         (INT32U)0
#define XIO_ADC2_CH_3RD         (INT32U)0
#define XIO_ADC2_CH_4TH         (INT32U)0
#define XIO_ADC2_CH_5TH         (INT32U)0
#define XIO_ADC2_CH_6TH         (INT32U)0
#define XIO_ADC2_CH_7TH         (INT32U)0
#define XIO_ADC2_CH_8TH         (INT32U)0
#define XIO_ADC2_CH_9TH         (INT32U)0
#define XIO_ADC2_CH_10TH        (INT32U)0
#define XIO_ADC2_CH_11TH        (INT32U)0
#define XIO_ADC2_CH_12TH        (INT32U)0
#define XIO_ADC2_CH_13TH        (INT32U)0
#define XIO_ADC2_CH_14TH        (INT32U)0
#define XIO_ADC2_CH_15TH        (INT32U)0
#define XIO_ADC2_CH_16TH        (INT32U)0
/* **************** ADC1 (All External Inputs) Definitions ************ */
#define XIO_NUM_OF_ADC1         (INT32U)15
#define XIO_ADC1_SMPL_CYC       (INT32U)3      /* 28.5 Cycles           */
#define XIO_ADC_IN_MAIN_VA      (INT32U)2     /* Pin15, PC0, ADC1-Ch10 */
#define XIO_ADC_IN_MAIN_VB      (INT32U)3     /* Pin16, PC1, ADC1-Ch11 */
#define XIO_ADC_IN_MAIN_VC      (INT32U)10     /* Pin17, PC2, ADC1-Ch12 */
#define XIO_ADC_IN_GENS_VA      (INT32U)4     /* Pin18, PC3, ADC1-Ch13 */
#define XIO_ADC_IN_GENS_VB      (INT32U)5      /* Pin29, PA4, ADC1-Ch4  */
#define XIO_ADC_IN_GENS_VC      (INT32U)7      /* Pin30, PA5, ADC1-Ch5  */
#define XIO_ADC_IN_GENS_IA      (INT32U)14      /* Pin31, PA6, ADC1-Ch6  */
#define XIO_ADC_IN_GENS_IB      (INT32U)8      /* Pin32, PA7, ADC1-Ch7  */
#define XIO_ADC_IN_GENS_IC      (INT32U)9     /* Pin33, PC4, ADC1-Ch14 */
#define XIO_ADC_IN_TEMP_9       (INT32U)15      /* Pin23, PA0, ADC1-Ch0  */
#define XIO_ADC_IN_TEMP_10      (INT32U)11      /* Pin24, PA1, ADC1-Ch1  */
#define XIO_ADC_IN_TEMP_11      (INT32U)12      /* Pin25, PA2, ADC1-Ch2  */
#define XIO_ADC_IN_TEMP_12      (INT32U)13      /* Pin26, PA3, ADC1-Ch3  */
#define XIO_ADC_IN_TEMP_13      (INT32U)1      /* Pin35, PB0, ADC1-Ch8  */
#define XIO_ADC_IN_TEMP_14      (INT32U)0      /* Pin36, PB1, ADC1-Ch9  */
#define XIO_ADC_IN_TEMP_15      (INT32U)6//未使用     /* Pin34, PC5, ADC1-Ch15 */
#define XIO_ADC1_CH_1ST          XIO_ADC_IN_MAIN_VA
#define XIO_ADC1_CH_2ND          XIO_ADC_IN_GENS_VA
#define XIO_ADC1_CH_3RD          XIO_ADC_IN_GENS_IA
#define XIO_ADC1_CH_4TH          XIO_ADC_IN_MAIN_VB
#define XIO_ADC1_CH_5TH          XIO_ADC_IN_GENS_VB
#define XIO_ADC1_CH_6TH          XIO_ADC_IN_GENS_IB
#define XIO_ADC1_CH_7TH          XIO_ADC_IN_MAIN_VC
#define XIO_ADC1_CH_8TH          XIO_ADC_IN_GENS_VC
#define XIO_ADC1_CH_9TH          XIO_ADC_IN_GENS_IC
#define XIO_ADC1_CH_10TH         XIO_ADC_IN_TEMP_9
#define XIO_ADC1_CH_11TH         XIO_ADC_IN_TEMP_10
#define XIO_ADC1_CH_12TH         XIO_ADC_IN_TEMP_11
#define XIO_ADC1_CH_13TH         XIO_ADC_IN_TEMP_12
#define XIO_ADC1_CH_14TH         XIO_ADC_IN_TEMP_13
#define XIO_ADC1_CH_15TH         XIO_ADC_IN_TEMP_14
#define XIO_ADC1_CH_16TH         XIO_ADC_IN_TEMP_15
#define XIO_ADC_NO_MAIN_VA      (INT32U)0
#define XIO_ADC_NO_GENS_VA      (INT32U)1
#define XIO_ADC_NO_GENS_IA      (INT32U)2
#define XIO_ADC_NO_MAIN_VB      (INT32U)3
#define XIO_ADC_NO_GENS_VB      (INT32U)4
#define XIO_ADC_NO_GENS_IB      (INT32U)5
#define XIO_ADC_NO_MAIN_VC      (INT32U)6
#define XIO_ADC_NO_GENS_VC      (INT32U)7
#define XIO_ADC_NO_GENS_IC      (INT32U)8
#define XIO_ADC_NO_TEMP_9       (INT32U)9
#define XIO_ADC_NO_TEMP_10      (INT32U)10
#define XIO_ADC_NO_TEMP_11      (INT32U)11
#define XIO_ADC_NO_TEMP_12      (INT32U)12
#define XIO_ADC_NO_TEMP_13      (INT32U)13
#define XIO_ADC_NO_TEMP_14      (INT32U)14
#define XIO_ADC_NO_TEMP_15      (INT32U)15

/* ********************** ADC1 Sample Definitions ********************* */
#define XIO_ADC_SMPL_SIZ         64
#define XIO_ADC_SMPL_GROUP       6
#define XIO_ADC_ARRAY_SIZ       (XIO_ADC_SMPL_SIZ * XIO_ADC_SMPL_GROUP)
#define XIO_ADC_SMPL_PRD_US      20000
#define XIO_ADC_SMPL_TIM_US     (XIO_ADC_SMPL_PRD_US / XIO_ADC_SMPL_SIZ)
#define XIO_ADC_DMA_BUF_SIZ     (XIO_NUM_OF_ADC1 * XIO_ADC_SMPL_SIZ)
#define XIO_ADC_REF_FILTER       64
#define XIO_ADC_REF_DEF          2047

/* ******************************************************************** */
/*                    (F105 TIM1 Remap Definition)                      */
/* Default:  (ETR/PA12,  CH1/PA8,   CH2/PA9,   CH3/PA10,   CH4/PA11,    */
/*            BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15)               */
/* Partial:  (ETR/PA12,  CH1/PA8,   CH2/PA9,   CH3/PA10,   CH4/PA11,    */
/*            BKIN/PA6,  CH1N/PA7,  CH2N/PB0,  CH3N/PB1)                */
/* Full:     (ETR/PE7,   CH1/PE9,   CH2/PE11,  CH3/PE13,   CH4/PE14,    */
/*            BKIN/PE15, CH1N/PE8,  CH2N/PE10, CH3N/PE12)               */
/* ******************************************************************** */
#define XIO_TIM1_EXTERN_CHAN     0
#define XIO_TIM1_AFIO_REMAP1     0
#define XIO_TIM1_AFIO_REMAP2     0

/* ******************************************************************** */
/*                    (F105 TIM2 Remap Definition)                      */
/* Default:  (CH1/ETR/PA0,  CH2/PA1, CH3/PA2,  CH4/PA3)                 */
/* Partial1: (CH1/ETR/PA15, CH2/PB3, CH3/PA2,  CH4/PA3)                 */
/* Partial2: (CH1/ETR/PA0,  CH2/PA1, CH3/PB10, CH4/PB11)                */
/* Full:     (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11)                */
/* ******************************************************************** */
#define XIO_TIM2_EXTERN_CHAN     0
#define XIO_TIM2_AFIO_REMAP1     0
#define XIO_TIM2_AFIO_REMAP2     0

/* ******************************************************************** */
/*                    (F105 TIM3 Remap Definition)                      */
/* Default:  (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)                       */
/* Partial:  (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1)                       */
/* Full:     (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9)                       */
/* ******************************************************************** */
#define XIO_TIM3_EXTERN_CHAN     4
#define XIO_TIM3_AFIO_REMAP1     AFIO_MAPR_TIM3_REMAP_FULLREMAP
#define XIO_TIM3_AFIO_REMAP2     0
#define XIO_NUM_OF_FRQ           4
#define XIO_FRQ_IN_TIM           TIM3
#define XIO_FRQ_PT_SPEED_IN1     PC6           /* Pin63, PC6, TIM3-CH1  */
#if(Change_Pin!=1)
#define XIO_FRQ_PT_SPEED_IN2     PC7           /* Pin64, PC7, TIM3-CH2  */
#define XIO_FRQ_PT_HARD_PRD1     PC8           /* Pin65, PC8, TIM3-CH3  */
#endif
#define XIO_FRQ_PT_HARD_PRD2     PC9           /* Pin66, PC9, TIM3-CH4  */

/* ******************************************************************** */
/*                    (F105 TIM4 Remap Definition)                      */
/* Default:  (CH1/PB6,  CH2/PB7,  CH3/PB8,  CH4/PB9)                    */
/* Full:     (CH1/PD12, CH2/PD13, CH3/PD14, CH4/PD15)                   */
/* ******************************************************************** */
#define XIO_TIM4_EXTERN_CHAN     4
#define XIO_TIM4_AFIO_REMAP1     AFIO_MAPR_TIM4_REMAP
#define XIO_TIM4_AFIO_REMAP2     0
#define XIO_NUM_OF_PWMOUT        2
#define XIO_PWM_OUT_TIM          TIM4
#define XIO_PWM_PERIOD_DEF       1000
#define XIO_PWM_CH1_PT           PD12          /* Pin59, PD12, TIM4-CH1 */
#define XIO_PWM_CH2_PT           PD13          /* Pin60, PD13, TIM4-CH2 */
#define XIO_PWMOUT1_TIM4CH       1
#define XIO_PWMOUT2_TIM4CH       2

/* ******************************************************************** */
/*                            Key Inputs                                */
/* ******************************************************************** */
#define XIO_NUM_OF_KEY_IN        11
//复位PG0
#define XIO_GPI_PT_KEY_RESET     PG0 
#define XIO_PT_KEY_RESET         GPIOG
#define XIO_BT_KEY_RESET         0
#define XIO_GET_KEY_RESET()     (XIO_PT_KEY_RESET->IDR & (1<<XIO_BT_KEY_RESET))
//自动PG7
#define XIO_GPI_PT_KEY_AUTO      PG7
#define XIO_PT_KEY_AUTO          GPIOG
#define XIO_BT_KEY_AUTO          7
#define XIO_GET_KEY_AUTO()      (XIO_PT_KEY_AUTO->IDR & (1<<XIO_BT_KEY_AUTO))
//手动PG3
#define XIO_GPI_PT_KEY_MANUAL    PG3
#define XIO_PT_KEY_MANUAL        GPIOG
#define XIO_BT_KEY_MANUAL        3
#define XIO_GET_KEY_MANUAL()    (XIO_PT_KEY_MANUAL->IDR & (1<<XIO_BT_KEY_MANUAL))
//停机PG8
#define XIO_GPI_PT_KEY_STOP      PG8
#define XIO_PT_KEY_STOP          GPIOG
#define XIO_BT_KEY_STOP          8
#define XIO_GET_KEY_STOP()      (XIO_PT_KEY_STOP->IDR & (1<<XIO_BT_KEY_STOP))
//起机PG5
#define XIO_GPI_PT_KEY_START     PG5
#define XIO_PT_KEY_START         GPIOG
#define XIO_BT_KEY_START         5
#define XIO_GET_KEY_START()     (XIO_PT_KEY_START->IDR & (1<<XIO_BT_KEY_START))
//消音PF15
#define XIO_GPI_PT_KEY_NOISE     PF15
#define XIO_PT_KEY_NOISE         GPIOF
#define XIO_BT_KEY_NOISE         15
#define XIO_GET_KEY_NOISE()     (XIO_PT_KEY_NOISE->IDR & (1<<XIO_BT_KEY_NOISE))
//发电合分闸PF7
#define XIO_GPI_PT_KEY_SW_ON     PF7
#define XIO_PT_KEY_SW_ON         GPIOF
#define XIO_BT_KEY_SW_ON         7
#define XIO_GET_KEY_SW_ON()     (XIO_PT_KEY_SW_ON->IDR & (1<<XIO_BT_KEY_SW_ON))
//市电合分闸PE4
#define XIO_GPI_PT_KEY_SW_OFF    PE4
#define XIO_PT_KEY_SW_OFF        GPIOE
#define XIO_BT_KEY_SW_OFF        4
#define XIO_GET_KEY_SW_OFF()    (XIO_PT_KEY_SW_OFF->IDR & (1<<XIO_BT_KEY_SW_OFF))
//向上PF3
#define XIO_GPI_PT_KEY_SW_UP     PF3
#define XIO_PT_KEY_SW_UP         GPIOF
#define XIO_BT_KEY_SW_UP         3
#define XIO_GET_KEY_SW_UP()     (XIO_PT_KEY_SW_UP->IDR & (1<<XIO_BT_KEY_SW_UP))
//向下PB14
#define XIO_GPI_PT_KEY_SW_DOWN   PB14
#define XIO_PT_KEY_SW_DOWN       GPIOB
#define XIO_BT_KEY_SW_DOWN       14
#define XIO_GET_KEY_SW_DOWN()   (XIO_PT_KEY_SW_DOWN->IDR & (1<<XIO_BT_KEY_SW_DOWN))
//确认PF5
#define XIO_GPI_PT_KEY_SW_ENTER  PF5
#define XIO_PT_KEY_SW_ENTER      GPIOF
#define XIO_BT_KEY_SW_ENTER      5
#define XIO_GET_KEY_SW_ENTER()  (XIO_PT_KEY_SW_ENTER->IDR & (1<<XIO_BT_KEY_SW_ENTER))

/* ******************************************************************** */
/*                            Switch Inputs                             */
/* ******************************************************************** */
#define XIO_NUM_OF_DIN           9
//按照图纸顺序
//1-PE0
#define XIO_GPI_PT_DIN_CH1       PE0
#define XIO_PT_DIN_CH1           GPIOE
#define XIO_BT_DIN_CH1           0
#define XIO_GET_DIN_CH1()       (XIO_PT_DIN_CH1->IDR & (1<<XIO_BT_DIN_CH1))
//2-PB9 
#define XIO_GPI_PT_DIN_CH2       PB9
#define XIO_PT_DIN_CH2           GPIOB
#define XIO_BT_DIN_CH2           9
#define XIO_GET_DIN_CH2()       (XIO_PT_DIN_CH2->IDR & (1<<XIO_BT_DIN_CH2))
//3-PB8 
#define XIO_GPI_PT_DIN_CH3       PB8
#define XIO_PT_DIN_CH3           GPIOB
#define XIO_BT_DIN_CH3           8
#define XIO_GET_DIN_CH3()       (XIO_PT_DIN_CH3->IDR & (1<<XIO_BT_DIN_CH3))
//4-Buzzer-PB7
#define XIO_GPI_PT_DIN_CH4       PB7
#define XIO_PT_DIN_CH4           GPIOB
#define XIO_BT_DIN_CH4           7
#define XIO_GET_DIN_CH4()       (XIO_PT_DIN_CH4->IDR & (1<<XIO_BT_DIN_CH4))
//5-PB6
#define XIO_GPI_PT_DIN_CH5       PB6
#define XIO_PT_DIN_CH5           GPIOB
#define XIO_BT_DIN_CH5           6
#define XIO_GET_DIN_CH5()       (XIO_PT_DIN_CH5->IDR & (1<<XIO_BT_DIN_CH5))
//6-PB5
#define XIO_GPI_PT_DIN_CH6       PB5
#define XIO_PT_DIN_CH6           GPIOB
#define XIO_BT_DIN_CH6           5
#define XIO_GET_DIN_CH6()       (XIO_PT_DIN_CH6->IDR & (1<<XIO_BT_DIN_CH6))
//7-PB4
#define XIO_GPI_PT_DIN_CH7       PB4
#define XIO_PT_DIN_CH7           GPIOB
#define XIO_BT_DIN_CH7           4
#define XIO_GET_DIN_CH7()       (XIO_PT_DIN_CH7->IDR & (1<<XIO_BT_DIN_CH7))
//8-PD13
#define XIO_GPI_PT_DIN_CH8       PD13
#define XIO_PT_DIN_CH8           GPIOD
#define XIO_BT_DIN_CH8           13
#define XIO_GET_DIN_CH8()       (XIO_PT_DIN_CH8->IDR & (1<<XIO_BT_DIN_CH8))
//9-PB12
#define XIO_GPI_PT_DIN_CH9       PB12
#define XIO_PT_DIN_CH9           GPIOB
#define XIO_BT_DIN_CH9           12
#define XIO_GET_DIN_CH9()       (XIO_PT_DIN_CH9->IDR & (1<<XIO_BT_DIN_CH9))
//10-PF2  --急停
#define XIO_GPI_PT_DIN_CH10       PF2
#define XIO_PT_DIN_CH10           GPIOF
#define XIO_BT_DIN_CH10           2
#define XIO_GET_DIN_CH10()       (XIO_PT_DIN_CH10->IDR & (1<<XIO_BT_DIN_CH10))
/* ******************************************************************** */
/*                              Led Outputs                             */
/* ******************************************************************** */
#define XIO_NUM_OF_LED_OUT       14
//复位-PG1
#define XIO_GPO_PT_LED_RESET     PG1
#define XIO_PT_LED_RESET         GPIOG
#define XIO_BT_LED_RESET         1
#define XIO_LED_RESET_ON()       XIO_PT_LED_RESET->BRR  = 1<<XIO_BT_LED_RESET
#define XIO_LED_RESET_OFF()      XIO_PT_LED_RESET->BSRR = 1<<XIO_BT_LED_RESET
//自动-PG6
#define XIO_GPO_PT_LED_AUTO      PG6
#define XIO_PT_LED_AUTO          GPIOG
#define XIO_BT_LED_AUTO          6
#define XIO_LED_AUTO_ON()        XIO_PT_LED_AUTO->BRR  = 1<<XIO_BT_LED_AUTO
#define XIO_LED_AUTO_OFF()       XIO_PT_LED_AUTO->BSRR = 1<<XIO_BT_LED_AUTO
//手动-PG2
#define XIO_GPO_PT_LED_MANUAL    PG2
#define XIO_PT_LED_MANUAL        GPIOG
#define XIO_BT_LED_MANUAL        2
#define XIO_LED_MANUAL_ON()      XIO_PT_LED_MANUAL->BRR  = 1<<XIO_BT_LED_MANUAL
#define XIO_LED_MANUAL_OFF()     XIO_PT_LED_MANUAL->BSRR = 1<<XIO_BT_LED_MANUAL
//停机-PG4
#define XIO_GPO_PT_LED_STOP      PG4
#define XIO_PT_LED_STOP          GPIOG
#define XIO_BT_LED_STOP          4
#define XIO_LED_STOP_ON()        XIO_PT_LED_STOP->BRR  = 1<<XIO_BT_LED_STOP
#define XIO_LED_STOP_OFF()       XIO_PT_LED_STOP->BSRR = 1<<XIO_BT_LED_STOP
//起机-PC7
#define XIO_GPO_PT_LED_START     PC7
#define XIO_PT_LED_START         GPIOC
#define XIO_BT_LED_START         7
#define XIO_LED_START_ON()       XIO_PT_LED_START->BRR  = 1<<XIO_BT_LED_START
#define XIO_LED_START_OFF()      XIO_PT_LED_START->BSRR = 1<<XIO_BT_LED_START
//消音-PF14
#define XIO_GPO_PT_LED_NOISE     PF14
#define XIO_PT_LED_NOISE         GPIOF
#define XIO_BT_LED_NOISE         14
#define XIO_LED_NOISE_ON()       XIO_PT_LED_NOISE->BRR  = 1<<XIO_BT_LED_NOISE
#define XIO_LED_NOISE_OFF()      XIO_PT_LED_NOISE->BSRR = 1<<XIO_BT_LED_NOISE
//发电合分闸-PF8
#define XIO_GPO_PT_LED_SW_ON     PF8
#define XIO_PT_LED_SW_ON         GPIOF
#define XIO_BT_LED_SW_ON         8
#define XIO_LED_SW_ON_ON()       XIO_PT_LED_SW_ON->BRR  = 1<<XIO_BT_LED_SW_ON
#define XIO_LED_SW_ON_OFF()      XIO_PT_LED_SW_ON->BSRR = 1<<XIO_BT_LED_SW_ON
//市电合分闸-PE5
#define XIO_GPO_PT_LED_SW_OFF    PE5
#define XIO_PT_LED_SW_OFF        GPIOE
#define XIO_BT_LED_SW_OFF        5
#define XIO_LED_SW_OFF_ON()      XIO_PT_LED_SW_OFF->BRR  = 1<<XIO_BT_LED_SW_OFF
#define XIO_LED_SW_OFF_OFF()     XIO_PT_LED_SW_OFF->BSRR = 1<<XIO_BT_LED_SW_OFF

//确认-PF6
#define XIO_GPO_PT_LED_SW_ENTER  PF6
#define XIO_PT_LED_SW_ENTER      GPIOF
#define XIO_BT_LED_SW_ENTER      6
#define XIO_LED_SW_ENTER_ON()    XIO_PT_LED_SW_ENTER->BRR  = 1<<XIO_BT_LED_SW_ENTER
#define XIO_LED_SW_ENTER_OFF()   XIO_PT_LED_SW_ENTER->BSRR = 1<<XIO_BT_LED_SW_ENTER

//向上-PF4
#define XIO_GPO_PT_LED_SW_UP     PF4 
#define XIO_PT_LED_SW_UP         GPIOF
#define XIO_BT_LED_SW_UP         4
#define XIO_LED_SW_UP_ON()       XIO_PT_LED_SW_UP->BRR  = 1<<XIO_BT_LED_SW_UP
#define XIO_LED_SW_UP_OFF()      XIO_PT_LED_SW_UP->BSRR = 1<<XIO_BT_LED_SW_UP

//向下-PB13
#define XIO_GPO_PT_LED_SW_DOWN   PB13 
#define XIO_PT_LED_SW_DOWN       GPIOB
#define XIO_BT_LED_SW_DOWN       13
#define XIO_LED_SW_DOWN_ON()     XIO_PT_LED_SW_DOWN->BRR  = 1<<XIO_BT_LED_SW_DOWN
#define XIO_LED_SW_DOWN_OFF()    XIO_PT_LED_SW_DOWN->BSRR = 1<<XIO_BT_LED_SW_DOWN

//运行绿灯-PC8
#define XIO_GPO_PT_LED_SW_RUN    PC8
#define XIO_PT_LED_SW_RUN        GPIOC
#define XIO_BT_LED_SW_RUN        8
#define XIO_LED_SW_RUN_ON()      XIO_PT_LED_SW_RUN->BRR  = 1<<XIO_BT_LED_SW_RUN
#define XIO_LED_SW_RUN_OFF()     XIO_PT_LED_SW_RUN->BSRR = 1<<XIO_BT_LED_SW_RUN

//维保黄灯-PA8
#define XIO_GPO_PT_LED_SW_MAINTEN PA8
#define XIO_PT_LED_SW_MAINTEN     GPIOA
#define XIO_BT_LED_SW_MAINTEN     8
#define XIO_LED_SW_MAINTEN_ON()   XIO_PT_LED_SW_MAINTEN->BRR  = 1<<XIO_BT_LED_SW_MAINTEN
#define XIO_LED_SW_MAINTEN_OFF()  XIO_PT_LED_SW_MAINTEN->BSRR = 1<<XIO_BT_LED_SW_MAINTEN

//报警红灯-PA15
#define XIO_GPO_PT_LED_SW_ALARM  PA15
#define XIO_PT_LED_SW_ALARM      GPIOA
#define XIO_BT_LED_SW_ALARM      15
#define XIO_LED_SW_ALARM_ON()    XIO_PT_LED_SW_ALARM->BRR  = 1<<XIO_BT_LED_SW_ALARM
#define XIO_LED_SW_ALARM_OFF()   XIO_PT_LED_SW_ALARM->BSRR = 1<<XIO_BT_LED_SW_ALARM
    
/* ******************************************************************** */
/*                            Switch Outputs                            */
/* ******************************************************************** */
#define XIO_NUM_OF_DOUT          9
//发电合分闸-PD12
#define XIO_GPO_PT_DOUT_CH1      PD12
#define XIO_PT_DOUT_CH1          GPIOD
#define XIO_BT_DOUT_CH1          12
#define XIO_CLR_DOUT_CH1()       XIO_PT_DOUT_CH1->BRR  = 1<<XIO_BT_DOUT_CH1
#define XIO_SET_DOUT_CH1()       XIO_PT_DOUT_CH1->BSRR = 1<<XIO_BT_DOUT_CH1
//市电合分闸-PB15
#define XIO_GPO_PT_DOUT_CH2      PB15
#define XIO_PT_DOUT_CH2          GPIOB
#define XIO_BT_DOUT_CH2          15
#define XIO_CLR_DOUT_CH2()       XIO_PT_DOUT_CH2->BRR  = 1<<XIO_BT_DOUT_CH2
#define XIO_SET_DOUT_CH2()       XIO_PT_DOUT_CH2->BSRR = 1<<XIO_BT_DOUT_CH2
//SPE-PG14
#define XIO_GPO_PT_DOUT_CH3      PG14
#define XIO_PT_DOUT_CH3          GPIOG
#define XIO_BT_DOUT_CH3          14
#define XIO_CLR_DOUT_CH3()       XIO_PT_DOUT_CH3->BRR  = 1<<XIO_BT_DOUT_CH3
#define XIO_SET_DOUT_CH3()       XIO_PT_DOUT_CH3->BSRR = 1<<XIO_BT_DOUT_CH3
//Buzzer-PG13
#define XIO_GPO_PT_DOUT_CH4      PG13
#define XIO_PT_DOUT_CH4          GPIOG
#define XIO_BT_DOUT_CH4          13
#define XIO_CLR_DOUT_CH4()       XIO_PT_DOUT_CH4->BRR  = 1<<XIO_BT_DOUT_CH4
#define XIO_SET_DOUT_CH4()       XIO_PT_DOUT_CH4->BSRR = 1<<XIO_BT_DOUT_CH4
//UP-PG15
#define XIO_GPO_PT_DOUT_CH5      PG15
#define XIO_PT_DOUT_CH5          GPIOG
#define XIO_BT_DOUT_CH5          15
#define XIO_CLR_DOUT_CH5()       XIO_PT_DOUT_CH5->BRR  = 1<<XIO_BT_DOUT_CH5
#define XIO_SET_DOUT_CH5()       XIO_PT_DOUT_CH5->BSRR = 1<<XIO_BT_DOUT_CH5
//DOWN-PB3
#define XIO_GPO_PT_DOUT_CH6      PB3
#define XIO_PT_DOUT_CH6          GPIOB
#define XIO_BT_DOUT_CH6          3
#define XIO_CLR_DOUT_CH6()       XIO_PT_DOUT_CH6->BRR  = 1<<XIO_BT_DOUT_CH6
#define XIO_SET_DOUT_CH6()       XIO_PT_DOUT_CH6->BSRR = 1<<XIO_BT_DOUT_CH6
//FUEL-PG11
#define XIO_GPO_PT_DOUT_CH7      PG11
#define XIO_PT_DOUT_CH7          GPIOG
#define XIO_BT_DOUT_CH7          11
#define XIO_CLR_DOUT_CH7()       XIO_PT_DOUT_CH7->BRR  = 1<<XIO_BT_DOUT_CH7
#define XIO_SET_DOUT_CH7()       XIO_PT_DOUT_CH7->BSRR = 1<<XIO_BT_DOUT_CH7
//CRANK-PG10
#define XIO_GPO_PT_DOUT_CH8      PG10
#define XIO_PT_DOUT_CH8          GPIOG
#define XIO_BT_DOUT_CH8          10
#define XIO_CLR_DOUT_CH8()       XIO_PT_DOUT_CH8->BRR  = 1<<XIO_BT_DOUT_CH8
#define XIO_SET_DOUT_CH8()       XIO_PT_DOUT_CH8->BSRR = 1<<XIO_BT_DOUT_CH8
//PREHEAT-PG12
#define XIO_GPO_PT_DOUT_CH9      PG12
#define XIO_PT_DOUT_CH9          GPIOG
#define XIO_BT_DOUT_CH9          12
#define XIO_CLR_DOUT_CH9()       XIO_PT_DOUT_CH9->BRR  = 1<<XIO_BT_DOUT_CH9
#define XIO_SET_DOUT_CH9()       XIO_PT_DOUT_CH9->BSRR = 1<<XIO_BT_DOUT_CH9

/* ******************************************************************** */
/*                         Speed Intputs TIM3                           */
/* ******************************************************************** */
#define XIO_GPO_PT_SPE_CH9      PA6
#define XIO_PT_SPE_TIM3CH       GPIOA
#define XIO_BT_SPE_TIM3CH       6

/* ******************************************************************** */
/*                       Sensor ConfigInf ADC1                          */
/* ******************************************************************** */
//Main Voltage A
#define XIO_GPO_PT_Sensor_MVA   PA2     
#define XIO_PT_Sensor_MVA       GPIOA
#define XIO_BT_Sensor_MVA       2
//Main Voltage B
#define XIO_GPO_PT_Sensor_MVB   PA3     
#define XIO_PT_Sensor_MVB       GPIOA
#define XIO_BT_Sensor_MVB       3
//Main Voltage C
#define XIO_GPO_PT_Sensor_MVC   PC0     
#define XIO_PT_Sensor_MVC       GPIOC
#define XIO_BT_Sensor_MVC       0

//Gen Voltage A
#define XIO_GPO_PT_Sensor_GVA   PA4     
#define XIO_PT_Sensor_GVA       GPIOA
#define XIO_BT_Sensor_GVA       4
//Gen Voltage B
#define XIO_GPO_PT_Sensor_GVB   PA5     
#define XIO_PT_Sensor_GVB       GPIOA
#define XIO_BT_Sensor_GVB       5
//Gen Voltage C
#define XIO_GPO_PT_Sensor_GVC   PA7     
#define XIO_PT_Sensor_GVC       GPIOA
#define XIO_BT_Sensor_GVC       7

//Gen Current A
#define XIO_GPO_PT_Sensor_GCA   PC4     
#define XIO_PT_Sensor_GCA       GPIOC
#define XIO_BT_Sensor_GCA       4
//Gen Current B
#define XIO_GPO_PT_Sensor_GCB   PB0   
#define XIO_PT_Sensor_GCB       GPIOB
#define XIO_BT_Sensor_GCB       0
//Gen Current C
#define XIO_GPO_PT_Sensor_GCC   PB1    
#define XIO_PT_Sensor_GCC       GPIOB
#define XIO_BT_Sensor_GCC       1
//Gen Current COM
#define XIO_GPO_PT_Sensor_GCCOM PC5   
#define XIO_PT_Sensor_GCCOM     GPIOC
#define XIO_BT_Sensor_GCCOM     5

//OILTemp
#define XIO_GPO_PT_Sensor_OT    PC1   
#define XIO_PT_Sensor_OT        GPIOC
#define XIO_BT_Sensor_OT        1
//OILPressure
#define XIO_GPO_PT_Sensor_OP    PC2    
#define XIO_PT_Sensor_OP        GPIOC
#define XIO_BT_Sensor_OP        2
//WaterTemp
#define XIO_GPO_PT_Sensor_WT    PC3   
#define XIO_PT_Sensor_WT        GPIOC
#define XIO_BT_Sensor_WT        3
//D+
#define XIO_GPO_PT_Sensor_DVC  PA1   
#define XIO_PT_Sensor_DVC      GPIOA
#define XIO_BT_Sensor_DVC      1
//B+
#define XIO_GPO_PT_Sensor_BVC  PA0 
#define XIO_PT_Sensor_BVC      GPIOA
#define XIO_BT_Sensor_BVC      0
/* ******************************************************************** */
/*                       Sensor ConfigInf ADC3                         */
/* ******************************************************************** */
//SPEED
#define XIO_GPO_PT_Sensor_SPE  PF10     
#define XIO_PT_Sensor_SPE      GPIOF
#define XIO_BT_Sensor_SPE      10

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
XIO_EXT INT32U uiXIOStatus;
XIO_EXT INT16U usXIOCalcTime;
XIO_EXT INT16U usXIOAdcChRef0;
XIO_EXT INT16U usXIOAdcChRef1;
XIO_EXT INT16U usXIOAdcChRef2;
XIO_EXT INT16U usXIOAdcChRef3;
XIO_EXT INT16U usXIOAdcChRef4;
XIO_EXT INT16U usXIOAdcChRef5;
XIO_EXT INT16U usXIOAdcChRef6;
XIO_EXT INT16U usXIOAdcChRef7;
XIO_EXT INT16U usXIOAdcChRef8;
XIO_EXT INT16U usXIOAdcChEff0;
XIO_EXT INT16U usXIOAdcChEff1;
XIO_EXT INT16U usXIOAdcChEff2;
XIO_EXT INT16U usXIOAdcChEff3;
XIO_EXT INT16U usXIOAdcChEff4;
XIO_EXT INT16U usXIOAdcChEff5;
XIO_EXT INT16U usXIOAdcChEff6;
XIO_EXT INT16U usXIOAdcChEff7;
XIO_EXT INT16U usXIOAdcChEff8;
XIO_EXT INT16U usXIOAdcChEff03;
XIO_EXT INT16U usXIOAdcChEff06;
XIO_EXT INT16U usXIOAdcChEff36;
XIO_EXT INT16U usXIOAdcChEff036;
XIO_EXT INT16U usXIOAdcChEff14;
XIO_EXT INT16U usXIOAdcChEff17;
XIO_EXT INT16U usXIOAdcChEff47;
XIO_EXT INT16U usXIOAdcChEff147;
XIO_EXT INT32S siXIOCrossMac12;
XIO_EXT INT32S siXIOCrossMac45;
XIO_EXT INT32S siXIOCrossMac78;
XIO_EXT INT32S siXIOGensActPA;
XIO_EXT INT32S siXIOGensActPB;
XIO_EXT INT32S siXIOGensActPC;
XIO_EXT INT32S siXIOGensActPAll;
XIO_EXT INT16U usXIOHardFreqMainA;
XIO_EXT INT16U usXIOSoftFreqMainA;
XIO_EXT INT16U usXIOSoftFreqMainB;
XIO_EXT INT16U usXIOSoftFreqMainC;
XIO_EXT INT16U usXIOSoftPhsMainA;
XIO_EXT INT16U usXIOSoftPhsMainB;
XIO_EXT INT16U usXIOSoftPhsMainC;
XIO_EXT INT16U usXIOHardFreqGensA;
XIO_EXT INT16U usXIOSoftFreqGensA;
XIO_EXT INT16U usXIOSoftFreqGensB;
XIO_EXT INT16U usXIOSoftFreqGensC;
XIO_EXT INT16U usXIOSoftPhsGensA;
XIO_EXT INT16U usXIOSoftPhsGensB;
XIO_EXT INT16U usXIOSoftPhsGensC;
XIO_EXT INT32U uiXIOMainActPrd;
XIO_EXT INT32U uiXIOHardPrdMainA;
XIO_EXT INT32U uiXIOSoftPrdMainA;
XIO_EXT INT32U uiXIOSoftPrdMainB;
XIO_EXT INT32U uiXIOSoftPrdMainC;
XIO_EXT INT32U uiXIOGensActPrd;
XIO_EXT INT32U uiXIOHardPrdGensA;
XIO_EXT INT32U uiXIOSoftPrdGensA;
XIO_EXT INT32U uiXIOSoftPrdGensB;
XIO_EXT INT32U uiXIOSoftPrdGensC;
XIO_EXT INT16S ssXIOSoftPhsDiffer;
XIO_EXT INT16S ssXIOHardPhsDiffer;
XIO_EXT INT16U usXIOMainSmpSiz;
XIO_EXT INT16U usXIOGensSmpSiz;
XIO_EXT INT16U usXIOAdcDmaBuf0[XIO_ADC_DMA_BUF_SIZ];
XIO_EXT INT16U usXIOAdcDmaBuf1[XIO_ADC_DMA_BUF_SIZ];
XIO_EXT INT16S ssXIOAdcChDat0[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat1[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat2[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat3[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat4[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat5[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat6[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat7[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat8[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat9[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat10[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat11[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat12[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat13[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat14[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat15[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcArray0[XIO_ADC_ARRAY_SIZ];
XIO_EXT INT16S ssXIOAdcArray1[XIO_ADC_ARRAY_SIZ];
XIO_EXT INT16S ssXIOAdcArray2[XIO_ADC_ARRAY_SIZ];
XIO_EXT INT16S ssXIOAdcArray3[XIO_ADC_ARRAY_SIZ];
XIO_EXT INT16S ssXIOAdcArray4[XIO_ADC_ARRAY_SIZ];
XIO_EXT INT16S ssXIOAdcArray5[XIO_ADC_ARRAY_SIZ];
XIO_EXT INT16S ssXIOAdcArray6[XIO_ADC_ARRAY_SIZ];
XIO_EXT INT16S ssXIOAdcArray7[XIO_ADC_ARRAY_SIZ];
XIO_EXT INT16S ssXIOAdcArray8[XIO_ADC_ARRAY_SIZ];
XIO_EXT INT16U *pXIOAdcDmaBuf;
XIO_EXT INT16S *pXIOFftDatBuf;
XIO_EXT INT32U uiXIOAdcRefSum0;
XIO_EXT INT32U uiXIOAdcRefSum1;
XIO_EXT INT32U uiXIOAdcRefSum2;
XIO_EXT INT32U uiXIOAdcRefSum3;
XIO_EXT INT32U uiXIOAdcRefSum4;
XIO_EXT INT32U uiXIOAdcRefSum5;
XIO_EXT INT32U uiXIOAdcRefSum6;
XIO_EXT INT32U uiXIOAdcRefSum7;
XIO_EXT INT32U uiXIOAdcRefSum8;
XIO_EXT SF_SOFT_FREQ_STR sXIOSoftFreq0;
XIO_EXT SF_SOFT_FREQ_STR sXIOSoftFreq1;
XIO_EXT SF_SOFT_FREQ_STR sXIOSoftFreq2;
XIO_EXT SF_SOFT_FREQ_STR sXIOSoftFreq3;
XIO_EXT SF_SOFT_FREQ_STR sXIOSoftFreq4;
XIO_EXT SF_SOFT_FREQ_STR sXIOSoftFreq5;
XIO_EXT SF_SOFT_FREQ_STR sXIOSoftFreq6;
XIO_EXT SF_SOFT_FREQ_STR sXIOSoftFreq7;
XIO_EXT SF_SOFT_FREQ_STR sXIOSoftFreq8;
XIO_EXT SF_HARD_FREQ_STR sXIOHardFreq0;
XIO_EXT SF_HARD_FREQ_STR sXIOHardFreq1;
XIO_EXT SF_SPD_PULSE_STR sXIOSpdPulse0;
XIO_EXT SF_SPD_PULSE_STR sXIOSpdPulse1;

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
XIO_EXT void   XIOInit(void);
XIO_EXT void   XIOStart(void);
XIO_EXT void   XIOTaskLoop(void);
XIO_EXT void   XIODma1Ch1IntHook(void);
XIO_EXT void   XIOGetAdcChanDat(INT16U *pDmaBuf);

XIO_EXT INT16U XIOReadSwitchesInput(void);
XIO_EXT INT16U XIOReadBoardKeyInput(void);
XIO_EXT INT16U XIOGetSwitchesOutput(void);
XIO_EXT void   XIOUpdateSwitchesOutput(INT16U usOutput);
XIO_EXT void   XIOUpdateBoardLedOutput(INT16U usOutput);
XIO_EXT void   XIOUpdatePwmOutput(void);
XIO_EXT void   XIOInitDigInput(void);
XIO_EXT void   XIOInitDigOutput(void);

XIO_EXT void   XIOInitADC1(void);
XIO_EXT void   XIOInitDma1Ch1Adc(void);
XIO_EXT void   XIOInitADC2(void);
XIO_EXT void   XIOAdc2StartConversion(void);
XIO_EXT INT16U XIOAdc2ReadResult(void);
XIO_EXT void XIOInitADC3(void);
XIO_EXT u32 XIOADC3Hook (void);

XIO_EXT void   XIOInitTim1(void);
XIO_EXT void   XIOInitTim1AdcTriger(void);
XIO_EXT void   XIOInitTim2(void);
XIO_EXT void   XIOInitTim3(void);
XIO_EXT void   XIOInitTim3FrqIn(void);
XIO_EXT void   XIOTim3IntHook(void);
XIO_EXT void   XIOInitTim4(void);
XIO_EXT void   XIOInitTim4PwmOut(void);
XIO_EXT void   XIOInitTim4PwmCh(INT08U ucChan, INT08U ucSet);
XIO_EXT void   XIOUpdateTim4PwmCh(INT08U ucChan, INT16U usPeriod, INT16U usDuty);
XIO_EXT void   XIOInitTim8FrqIn (void);
XIO_EXT void   XIOTim8IntHook (void);

XIO_EXT void   XIOResetGPIO(GPIO_TypeDef *pPt);
XIO_EXT void   XIOConfigGPIO(GPIO_TypeDef *pPt, INT08U ucBit, INT32U uiMod, INT16U usSet);
XIO_EXT void   XIOConfigAFIO(INT32U uiRemap);
XIO_EXT void   XIOConfigREMAP(INT32U uiRemap1, INT32U uiRemap2);

/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
