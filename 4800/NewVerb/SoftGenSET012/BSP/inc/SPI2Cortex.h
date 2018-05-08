/* ******************************************************************** */
/*                       Header File SPI2Cortex.h                       */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _SPI2CORTEX_H

#define _SPI2CORTEX_H

#ifdef   SPI2_GLOBALS

#define  SPI2_EXT  

#else

#define  SPI2_EXT extern

#endif

/* ******************************************************************** */
/*  SPI2_VERSION  = 10xx: VEC1000 Application                           */
/*  SPI2_VERSION  = 40xx: VEC4000 Application                           */
/*  SPI2_VERSION  = 68xx: VEC6800 Application                           */
/*  SPI2_VERSION  = 69xx: VEC6900 Application                           */
/*  SPI2_VERSION  = 760x: GEC7600-Main Application                      */
/*  SPI2_VERSION  = 761x: GEC7600-Display Application                   */
/*  SPI2_VERSION  = 780x: GEC7800-Main Application                      */
/*  SPI2_VERSION  = 781x: GEC7800-Display Application                   */
/*  SPI2_VERSION  = 80xx: VEC8000 Application                           */
/*  SPI2_VERSION  = 90xx: VEC9000 Application                           */
/*  SPI2_VERSION  = 96xx: VEC9600 Application                           */
/* ******************************************************************** */

#define SPI2_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define SPI2_1000_COMMON_ON       0
#define SPI2_4000_COMMON_ON       0
#define SPI2_6800_COMMON_ON       0
#define SPI2_6900_COMMON_ON       0
#define SPI2_7600_COMMON_ON       0
#define SPI2_7600_MAIN_CHIP_ON    0
#define SPI2_7600_AUX_CHIP_ON     0
#define SPI2_7800_COMMON_ON       0
#define SPI2_7800_MAIN_CHIP_ON    0
#define SPI2_7800_AUX_CHIP_ON     0
#define SPI2_8000_COMMON_ON       0
#define SPI2_9000_COMMON_ON       0
#define SPI2_9600_COMMON_ON       0
#if   ((SPI2_VERSION / 100)   == 10)
#undef  SPI2_1000_COMMON_ON
#define SPI2_1000_COMMON_ON       1
#endif
#if   ((SPI2_VERSION / 100)   == 40)
#undef  SPI2_4000_COMMON_ON
#define SPI2_4000_COMMON_ON       1
#endif
#if   ((SPI2_VERSION / 100)   == 68)
#undef  SPI2_6800_COMMON_ON
#define SPI2_6800_COMMON_ON       1
#endif
#if   ((SPI2_VERSION / 100)   == 69)
#undef  SPI2_6900_COMMON_ON
#define SPI2_6900_COMMON_ON       1
#endif
#if   ((SPI2_VERSION / 100)   == 76)
#undef  SPI2_7600_COMMON_ON
#define SPI2_7600_COMMON_ON       1
#endif
#if   ((SPI2_VERSION / 10)   == 760)
#undef  SPI2_7600_MAIN_CHIP_ON
#define SPI2_7600_MAIN_CHIP_ON    1
#endif
#if   ((SPI2_VERSION / 10)   == 761)
#undef  SPI2_7600_AUX_CHIP_ON
#define SPI2_7600_AUX_CHIP_ON     1
#endif
#if   ((SPI2_VERSION / 100)   == 78)
#undef  SPI2_7800_COMMON_ON
#define SPI2_7800_COMMON_ON       1
#endif
#if   ((SPI2_VERSION / 10)   == 780)
#undef  SPI2_7800_MAIN_CHIP_ON
#define SPI2_7800_MAIN_CHIP_ON    1
#endif
#if   ((SPI2_VERSION / 10)   == 781)
#undef  SPI2_7800_AUX_CHIP_ON
#define SPI2_7800_AUX_CHIP_ON     1
#endif
#if   ((SPI2_VERSION / 100)   == 80)
#undef  SPI2_8000_COMMON_ON
#define SPI2_8000_COMMON_ON       1
#endif
#if   ((SPI2_VERSION / 100)   == 90)
#undef  SPI2_9000_COMMON_ON
#define SPI2_9000_COMMON_ON       1
#endif
#if   ((SPI2_VERSION / 100)   == 96)
#undef  SPI2_9600_COMMON_ON
#define SPI2_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define SPI2_FUNCTION_ON          0
#define SPI2_CPU_9S12_ON          0
#define SPI2_CPU_POWERPC_ON       0
#define SPI2_CPU_STM32F1_ON       0
#define SPI2_CPU_STM32F103_ON     0
#define SPI2_CPU_STM32F105_ON     0
#if    (SPI2_1000_COMMON_ON    == 1)
#undef  SPI2_CPU_9S12_ON
#define SPI2_CPU_9S12_ON          1
#endif
#if    (SPI2_4000_COMMON_ON    == 1)
#undef  SPI2_CPU_9S12_ON
#define SPI2_CPU_9S12_ON          1
#endif
#if    (SPI2_6800_COMMON_ON    == 1)
#undef  SPI2_CPU_9S12_ON
#define SPI2_CPU_9S12_ON          1
#endif
#if    (SPI2_6900_COMMON_ON    == 1)
#undef  SPI2_CPU_POWERPC_ON
#define SPI2_CPU_POWERPC_ON       1
#endif
#if    (SPI2_7600_COMMON_ON    == 1)
#undef  SPI2_CPU_STM32F1_ON
#define SPI2_CPU_STM32F1_ON       1
#endif
#if    (SPI2_7600_MAIN_CHIP_ON == 1)
#undef  SPI2_CPU_STM32F105_ON
#define SPI2_CPU_STM32F105_ON     1
#endif
#if    (SPI2_7600_AUX_CHIP_ON  == 1)
#undef  SPI2_CPU_STM32F103_ON
#define SPI2_CPU_STM32F103_ON     1
#endif
#if    (SPI2_7800_COMMON_ON    == 1)
#undef  SPI2_CPU_STM32F1_ON
#define SPI2_CPU_STM32F1_ON       1
#endif
#if    (SPI2_7800_MAIN_CHIP_ON == 1)
#undef  SPI2_CPU_STM32F105_ON
#define SPI2_CPU_STM32F105_ON     1
#endif
#if    (SPI2_7800_AUX_CHIP_ON  == 1)
#undef  SPI2_CPU_STM32F103_ON
#define SPI2_CPU_STM32F103_ON     1
#endif
#if    (SPI2_8000_COMMON_ON    == 1)
#undef  SPI2_CPU_POWERPC_ON
#define SPI2_CPU_POWERPC_ON       1
#endif
#if    (SPI2_9000_COMMON_ON    == 1)
#undef  SPI2_CPU_POWERPC_ON
#define SPI2_CPU_POWERPC_ON       1
#endif
#if    (SPI2_9600_COMMON_ON    == 1)
#undef  SPI2_CPU_POWERPC_ON
#define SPI2_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                    (F105 SPI2 Remap Definition)                      */
/* Default:  (SPI2_NSS/PA4,  SCK/PA5, MISO/PA6, MOSI/PA7)               */
/* Remap:    (SPI2_NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5)               */
/* ******************************************************************** */
#define SPI2_AFIO_REMAP1        0
#define SPI2_AFIO_REMAP2        0
#define SPI2_PT_BT_CS           PA4
#define SPI2_PT_BT_SCK          PA5
#define SPI2_PT_BT_IN           PA6
#define SPI2_PT_BT_OUT          PA7
#define SPI2_PT_BT_CD           PC4
#define SPI2_PT_CS              GPIOA
#define SPI2_PT_SCK             GPIOA
#define SPI2_PT_IN              GPIOA
#define SPI2_PT_OUT             GPIOA
#define SPI2_PT_CD              GPIOC
#define SPI2_BT_CS              4
#define SPI2_BT_SCK             5
#define SPI2_BT_IN              6
#define SPI2_BT_OUT             7
#define SPI2_BT_CD              4
#define SPI2_CLK_SLOW()         SPI2->CR1 |=  SPI_CR1_BR_0 | SPI_CR1_BR_2
#define SPI2_CLK_FAST()         SPI2->CR1 &= ~SPI_CR1_BR
#define SPI2_CS_HIGH()          SPI2_PT_CS->BSRR = 1UL <<  SPI2_BT_CS
#define SPI2_CS_LOW()           SPI2_PT_CS->BSRR = 1UL << (SPI2_BT_CS+16)
#define SPI2_GET_DETECT_PIN()  (SPI2_PT_CD->IDR & (1UL << SPI2_BT_CD))
#define SPI2_I2S_FLAG_RXNE     (INT16U)0x0001
#define SPI2_I2S_FLAG_TXE      (INT16U)0x0002
#define SPI2_I2S_FLAG_CHSIDE   (INT16U)0x0004
#define SPI2_I2S_FLAG_UDR      (INT16U)0x0008
#define SPI2_I2S_FLAG_CRCERR   (INT16U)0x0010
#define SPI2_I2S_FLAG_MODF     (INT16U)0x0020
#define SPI2_I2S_FLAG_OVR      (INT16U)0x0040
#define SPI2_I2S_FLAG_BSY      (INT16U)0x0080

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)
SPI2_EXT INT32U uiSPI2Status;
#endif

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (SPI2_FUNCTION_ON == 1)

SPI2_EXT void   SPI2Init(void);
SPI2_EXT void   SPI2Start(void);
SPI2_EXT void   SPI2HardInit(void);
SPI2_EXT INT08U SPI2ReadByte(void);
SPI2_EXT INT08U SPI2WriteByte(INT08U ucData);
SPI2_EXT void   SPI2I2SConfig(INT08U ucNewState);
SPI2_EXT void   SPI2IntConfig(INT16U usIntMsk, INT08U ucNewState);
SPI2_EXT void   SPI2DMAConfig(INT16U usDmaMsk, INT08U ucNewState);
SPI2_EXT void   SPI2DataSizeConfig(INT08U uc16bOr8b);
SPI2_EXT void   SPI2SendData(INT16U usData);
SPI2_EXT INT16U SPI2ReceiveData(void);
SPI2_EXT void   SPI2TransmitCRC(void);
SPI2_EXT void   SPI2CalculateCRC(INT08U ucNewState);
SPI2_EXT INT16U SPI2GetCRCValue(INT08U ucTxOrRx);
SPI2_EXT INT16U SPI2GetFlagStatus(INT16U usFlgMsk);
SPI2_EXT void   SPI2ClearFlag(INT16U usFlgMsk);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
