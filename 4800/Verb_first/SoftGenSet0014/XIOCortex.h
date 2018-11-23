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
/*  XIO_VERSION  = 76xx: GEC7600 Application                            */
/*  XIO_VERSION  = 78xx: GEC7800 Application                            */
/*  XIO_VERSION  = 80xx: VEC8000 Application                            */
/*  XIO_VERSION  = 90xx: VEC9000 Application                            */
/*  XIO_VERSION  = 96xx: VEC9600 Application                            */
/* ******************************************************************** */

#define XIO_VERSION          7600

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define XIO_1000_COMMON_ON      0
#define XIO_4000_COMMON_ON      0
#define XIO_6800_COMMON_ON      0
#define XIO_6900_COMMON_ON      0
#define XIO_7600_COMMON_ON      0
#define XIO_7800_COMMON_ON      0
#define XIO_8000_COMMON_ON      0
#define XIO_9000_COMMON_ON      0
#define XIO_9600_COMMON_ON      0
#if   ((XIO_VERSION / 100)  == 10)
#undef  XIO_1000_COMMON_ON
#define XIO_1000_COMMON_ON      1
#endif
#if   ((XIO_VERSION / 100)  == 40)
#undef  XIO_4000_COMMON_ON
#define XIO_4000_COMMON_ON      1
#endif
#if   ((XIO_VERSION / 100)  == 68)
#undef  XIO_6800_COMMON_ON
#define XIO_6800_COMMON_ON      1
#endif
#if   ((XIO_VERSION / 100)  == 69)
#undef  XIO_6900_COMMON_ON
#define XIO_6900_COMMON_ON      1
#endif
#if   ((XIO_VERSION / 100)  == 76)
#undef  XIO_7600_COMMON_ON
#define XIO_7600_COMMON_ON      1
#endif
#if   ((XIO_VERSION / 100)  == 78)
#undef  XIO_7800_COMMON_ON
#define XIO_7800_COMMON_ON      1
#endif
#if   ((XIO_VERSION / 100)  == 80)
#undef  XIO_8000_COMMON_ON
#define XIO_8000_COMMON_ON      1
#endif
#if   ((XIO_VERSION / 100)  == 90)
#undef  XIO_9000_COMMON_ON
#define XIO_9000_COMMON_ON      1
#endif
#if   ((XIO_VERSION / 100)  == 96)
#undef  XIO_9600_COMMON_ON
#define XIO_9600_COMMON_ON      1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define XIO_CPU_9S12_ON         0
#define XIO_CPU_POWERPC_ON      0
#define XIO_CPU_STM32F1_ON      0
#if    (XIO_1000_COMMON_ON   == 1)
#undef  XIO_CPU_9S12_ON
#define XIO_CPU_9S12_ON         1
#endif
#if    (XIO_4000_COMMON_ON   == 1)
#undef  XIO_CPU_9S12_ON
#define XIO_CPU_9S12_ON         1
#endif
#if    (XIO_6800_COMMON_ON   == 1)
#undef  XIO_CPU_9S12_ON
#define XIO_CPU_9S12_ON         1
#endif
#if    (XIO_6900_COMMON_ON   == 1)
#undef  XIO_CPU_POWERPC_ON
#define XIO_CPU_POWERPC_ON      1
#endif
#if    (XIO_7600_COMMON_ON   == 1)
#undef  XIO_CPU_STM32F1_ON
#define XIO_CPU_STM32F1_ON      1
#endif
#if    (XIO_7800_COMMON_ON   == 1)
#undef  XIO_CPU_STM32F1_ON
#define XIO_CPU_STM32F1_ON      1
#endif
#if    (XIO_8000_COMMON_ON   == 1)
#undef  XIO_CPU_POWERPC_ON
#define XIO_CPU_POWERPC_ON      1
#endif
#if    (XIO_9000_COMMON_ON   == 1)
#undef  XIO_CPU_POWERPC_ON
#define XIO_CPU_POWERPC_ON      1
#endif
#if    (XIO_9600_COMMON_ON   == 1)
#undef  XIO_CPU_POWERPC_ON
#define XIO_CPU_POWERPC_ON      1
#endif

/* ******************************************************************** */
/*                           Basis Definition                           */
/* ******************************************************************** */
#define XIO_TRUE                 1
#define XIO_FALSE                0
#define XIO_NO_ERR               0
#define XIO_ERR_BUSY             1
#define XIO_STS_NORMAL           0x0000
#define XIO_STS_INT_DMA1_CH1     0x0001
#define XIO_STS_INT_DMA2_CH1     0x0002
#define XIO_STS_HARDPRD0_ERR     0x0004
#define XIO_STS_HARDPRD1_ERR     0x0008
#define XIO_STS_HARDPRD_BOTH    (XIO_STS_HARDPRD0_ERR | XIO_STS_HARDPRD1_ERR)
#define XIO_STS_GET_BIT(m)      (usXIOStatus & (m))
#define XIO_STS_CLR_BIT(m)       usXIOStatus &= ~(m)
#define XIO_STS_SET_BIT(m)       usXIOStatus |= (m)
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

//@@@
//按键
#define KEY_MODE_STOP ((GPIOE->IDR >> 6) & 0x01)     //PE6  停机
#define KEY_MODE_MANUAL ((GPIOE->IDR >> 5) & 0x01)   //PE5  手动
#define KEY_MODE_AUTO ((GPIOD->IDR >> 3) & 0x01)   //PD3  自动
#define KEY_MODE_RESET ((GPIOC->IDR >> 11) & 0x01)   //PC11  复位
#define KEY_MODE_START ((GPIOC->IDR >> 10) & 0x01)   //PC10  起机
#define KEY_MODE_DOWN ((GPIOB->IDR >> 5) & 0x01)   //PB5   向下键
#define KEY_MODE_ENTER ((GPIOB->IDR >> 12) & 0x01)   //PB12  确认键
#define KEY_MODE_UP ((GPIOB->IDR >> 10) & 0x01)   //PB10  向上键
//输入端口
#define INPUT_VALUE_1 ((GPIOE->IDR >> 2) & 0x01)   //PE2  输入口1
#define INPUT_VALUE_2 ((GPIOE->IDR >> 3) & 0x01)   //PE3  输入口2

//@@@

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
#define XIO_NUM_OF_ADC1         (INT32U)16
#define XIO_ADC1_SMPL_CYC       (INT32U)3                /* 28.5 Cycles */
#define XIO_ADC_IN_MAIN_VA      (INT32U)0  //扫描通道0可设置
#define XIO_ADC_IN_GENS_VA      (INT32U)5  //扫描通道5-发电电压VA
#define XIO_ADC_IN_GENS_IA      (INT32U)1  //发电电流A
#define XIO_ADC_IN_MAIN_VB      (INT32U)15
#define XIO_ADC_IN_GENS_VB      (INT32U)6  //扫描通道6-发电电压VB
#define XIO_ADC_IN_GENS_IB      (INT32U)3  //发电电流B
#define XIO_ADC_IN_MAIN_VC      (INT32U)4
#define XIO_ADC_IN_GENS_VC      (INT32U)7  //扫描通道7-发电电压VC
#define XIO_ADC_IN_GENS_IC      (INT32U)2  //发电电流C
#define XIO_ADC_IN_ENG_TMP      (INT32U)12  //扫描通道12-温度
#define XIO_ADC_IN_OIL_PRS      (INT32U)13  //扫描通道13-油压
#define XIO_ADC_IN_OIL_TMP      (INT32U)14
#define XIO_ADC_IN_TEMP_1       (INT32U)11  //扫描通道11-液位（输入口4）
#define XIO_ADC_IN_TEMP_2       (INT32U)10  //扫描通道10-输入口3
#define XIO_ADC_IN_TEMP_3       (INT32U)9   //电池电压
#define XIO_ADC_IN_TEMP_4       (INT32U)8   //充电电压D+
#define XIO_ADC1_CH_1ST          XIO_ADC_IN_MAIN_VA
#define XIO_ADC1_CH_2ND          XIO_ADC_IN_GENS_VA
#define XIO_ADC1_CH_3RD          XIO_ADC_IN_GENS_IA
#define XIO_ADC1_CH_4TH          XIO_ADC_IN_MAIN_VB
#define XIO_ADC1_CH_5TH          XIO_ADC_IN_GENS_VB
#define XIO_ADC1_CH_6TH          XIO_ADC_IN_GENS_IB
#define XIO_ADC1_CH_7TH          XIO_ADC_IN_MAIN_VC
#define XIO_ADC1_CH_8TH          XIO_ADC_IN_GENS_VC
#define XIO_ADC1_CH_9TH          XIO_ADC_IN_GENS_IC
#define XIO_ADC1_CH_10TH         XIO_ADC_IN_ENG_TMP
#define XIO_ADC1_CH_11TH         XIO_ADC_IN_OIL_PRS
#define XIO_ADC1_CH_12TH         XIO_ADC_IN_OIL_TMP
#define XIO_ADC1_CH_13TH         XIO_ADC_IN_TEMP_1
#define XIO_ADC1_CH_14TH         XIO_ADC_IN_TEMP_2
#define XIO_ADC1_CH_15TH         XIO_ADC_IN_TEMP_3
#define XIO_ADC1_CH_16TH         XIO_ADC_IN_TEMP_4
#define XIO_ADC_NO_MAIN_VA      (INT32U)0
#define XIO_ADC_NO_GENS_VA      (INT32U)1
#define XIO_ADC_NO_GENS_IA      (INT32U)2
#define XIO_ADC_NO_MAIN_VB      (INT32U)3
#define XIO_ADC_NO_GENS_VB      (INT32U)4
#define XIO_ADC_NO_GENS_IB      (INT32U)5
#define XIO_ADC_NO_MAIN_VC      (INT32U)6
#define XIO_ADC_NO_GENS_VC      (INT32U)7
#define XIO_ADC_NO_GENS_IC      (INT32U)8
#define XIO_ADC_NO_ENG_TMP      (INT32U)9
#define XIO_ADC_NO_OIL_PRS      (INT32U)10
#define XIO_ADC_NO_OIL_TMP      (INT32U)11
#define XIO_ADC_NO_FUEL_LEVEL   (INT32U)12
#define XIO_ADC_NO_TEMP_1       (INT32U)13
#define XIO_ADC_NO_TEMP_2       (INT32U)14
#define XIO_ADC_NO_TEMP_3       (INT32U)15
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
/*                   Digital Input Channel Definition                   */
/* ******************************************************************** */
#define XIO_NUM_OF_GPI           16
#define XIO_GPI_PT_SWITCH_ON     PB12
#define XIO_GPI_PT_SWITCH_OFF    PB13

/* ******************************************************************** */
/*                          Speed Input Channel                         */
/* ******************************************************************** */
#define XIO_NUM_OF_FRQ           2
#define XIO_FRQ_PT_SPEED1        PB13         /* Pin-26, AF2, TIM1_CH1N */
#define XIO_FRQ_PT_SPEED2        PB13         /* Pin-26, AF2, TIM1_CH1N */

/* ******************************************************************** */
/*                  Digital Output Channel Definition                   */
/* ******************************************************************** */
#define XIO_NUM_OF_GPO           16
#define XIO_GPO_PT_A_L           PB13         /* Pin-26, AF2, TIM1_CH1N */
#define XIO_GPO_PT_B_L           PB14         /* Pin-27, AF2, TIM1_CH2N */
#define XIO_GPO_PT_C_L           PB15         /* Pin-28, AF2, TIM1_CH3N */

/* ******************************************************************** */
/*                    PWM Output Channel Definition                     */
/* ******************************************************************** */
#define XIO_NUM_OF_PWMOUT        2
#define XIO_PWM_PERIOD_DEF       1000
#define XIO_PWM_CH1_PT           PB13
#define XIO_PWM_CH2_PT           PB12
#define XIO_PWM_TIM              TIM4

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
XIO_EXT INT16U usXIOTimer;
XIO_EXT INT16U usXIOStatus;
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
XIO_EXT INT16U usXIOAdcChEff14;
XIO_EXT INT16U usXIOAdcChEff17;
XIO_EXT INT16U usXIOAdcChEff47;
XIO_EXT INT16U usXIOAdcChEffGd;
XIO_EXT INT32S siXIOCrossMac12;
XIO_EXT INT32S siXIOCrossMac45;
XIO_EXT INT32S siXIOCrossMac78;
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
XIO_EXT INT32U uiXIOActivePrdMain;
XIO_EXT INT32U uiXIOHardPrdMainA;
XIO_EXT INT32U uiXIOSoftPrdMainA;
XIO_EXT INT32U uiXIOSoftPrdMainB;
XIO_EXT INT32U uiXIOSoftPrdMainC;
XIO_EXT INT32U uiXIOActivePrdGens;
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
XIO_EXT INT16S ssXIOAdcIirBuf0[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcIirBuf1[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcIirBuf3[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcIirBuf4[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcIirBuf6[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcIirBuf7[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16U *pXIOAdcDmaBuf;  //DMA读取ADC数据地址
XIO_EXT INT16S *pXIOFftDatBuf;  //ADC采集数组地址
XIO_EXT INT32U uiXIOAdcRefSum0;
XIO_EXT INT32U uiXIOAdcRefSum1;
XIO_EXT INT32U uiXIOAdcRefSum2;
XIO_EXT INT32U uiXIOAdcRefSum3;
XIO_EXT INT32U uiXIOAdcRefSum4;
XIO_EXT INT32U uiXIOAdcRefSum5;
XIO_EXT INT32U uiXIOAdcRefSum6;
XIO_EXT INT32U uiXIOAdcRefSum7;
XIO_EXT INT32U uiXIOAdcRefSum8;
XIO_EXT SF_IIR_FILTER_STR sXIOIirFilter0;
XIO_EXT SF_IIR_FILTER_STR sXIOIirFilter1;
XIO_EXT SF_IIR_FILTER_STR sXIOIirFilter2;
XIO_EXT SF_IIR_FILTER_STR sXIOIirFilter3;
XIO_EXT SF_IIR_FILTER_STR sXIOIirFilter4;
XIO_EXT SF_IIR_FILTER_STR sXIOIirFilter5;
XIO_EXT SF_IIR_FILTER_STR sXIOIirFilter6;
XIO_EXT SF_IIR_FILTER_STR sXIOIirFilter7;
XIO_EXT SF_IIR_FILTER_STR sXIOIirFilter8;
XIO_EXT SF_ZERO_CROSS_STR sXIOZeroCross0;
XIO_EXT SF_ZERO_CROSS_STR sXIOZeroCross1;
XIO_EXT SF_ZERO_CROSS_STR sXIOZeroCross2;
XIO_EXT SF_ZERO_CROSS_STR sXIOZeroCross3;
XIO_EXT SF_ZERO_CROSS_STR sXIOZeroCross4;
XIO_EXT SF_ZERO_CROSS_STR sXIOZeroCross5;
XIO_EXT SF_ZERO_CROSS_STR sXIOZeroCross6;
XIO_EXT SF_ZERO_CROSS_STR sXIOZeroCross7;
XIO_EXT SF_ZERO_CROSS_STR sXIOZeroCross8;
XIO_EXT SF_HARD_PRD_STR   sXIOHardPeriod0;
XIO_EXT SF_HARD_PRD_STR   sXIOHardPeriod1;
XIO_EXT SF_SPD_PULSE_STR  sXIOSpdPulse0;
XIO_EXT SF_SPD_PULSE_STR  sXIOSpdPulse1;

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
XIO_EXT void   XIOUpdateSwitchesOutput(INT16U usOutput);
XIO_EXT void   XIOUpdateBoardLedOutput(INT16U usOutput);
XIO_EXT void   XIOUpdatePwmOutput(void);
XIO_EXT void   XIOInitDigInput(void);
XIO_EXT void   XIOInitDigOutput(void);
XIO_EXT void   XIOInitPwmOutput(void);

XIO_EXT void   XIOInitADC1(void);
XIO_EXT void   XIOInitDma1Ch1Adc(void);
XIO_EXT void   XIOInitADC2(void);
XIO_EXT void   XIOAdc2StartConversion(void);
XIO_EXT INT16U XIOAdc2ReadResult(void);

XIO_EXT void   XIOInitTim1(void);
XIO_EXT void   XIOInitTim1AdcTriger(void);
XIO_EXT void   XIOInitTim2(void);
XIO_EXT void   XIOInitTim2HardPrdIn(void);
XIO_EXT void   XIOInitTim3(void);
XIO_EXT void   XIOInitTim3SpeedIn(void);
XIO_EXT void   XIOInitTim4(void);
XIO_EXT void   XIOInitTim4Pwm(void);
XIO_EXT void   XIOUpdateTim4Pwm(INT08U ucChan, INT16U usPeriod, INT16U usDuty);

XIO_EXT void   XIOResetGPIO(GPIO_TypeDef *pPt);
XIO_EXT void   XIOConfigGPIO(GPIO_TypeDef *pPt, INT08U ucBit, INT32U uiMod, INT16U usSet);
XIO_EXT void   XIOConfigGPIOKEY(GPIO_TypeDef *pPt, INT08U ucBit, INT32U uiMod, INT16U usSet);   //@@@@@ZC
XIO_EXT void   XIOConfigAFIO(INT32U uiRemap);

/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
