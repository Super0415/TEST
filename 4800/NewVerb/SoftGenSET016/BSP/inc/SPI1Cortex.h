/* ******************************************************************** */
/*                       Header File SPI1Cortex.h                       */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _SPI1CORTEX_H

#define _SPI1CORTEX_H

#ifdef   SPI1_GLOBALS

#define  SPI1_EXT  

#else

#define  SPI1_EXT extern

#endif

/* ******************************************************************** */
/*  SPI1_VERSION  = 10xx: VEC1000 Application                           */
/*  SPI1_VERSION  = 40xx: VEC4000 Application                           */
/*  SPI1_VERSION  = 68xx: VEC6800 Application                           */
/*  SPI1_VERSION  = 69xx: VEC6900 Application                           */
/*  SPI1_VERSION  = 760x: GEC7600-Main Application                      */
/*  SPI1_VERSION  = 761x: GEC7600-Display Application                   */
/*  SPI1_VERSION  = 780x: GEC7800-Main Application                      */
/*  SPI1_VERSION  = 781x: GEC7800-Display Application                   */
/*  SPI1_VERSION  = 80xx: VEC8000 Application                           */
/*  SPI1_VERSION  = 90xx: VEC9000 Application                           */
/*  SPI1_VERSION  = 96xx: VEC9600 Application                           */
/* ******************************************************************** */

#define SPI1_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define SPI1_1000_COMMON_ON       0
#define SPI1_4000_COMMON_ON       0
#define SPI1_6800_COMMON_ON       0
#define SPI1_6900_COMMON_ON       0
#define SPI1_7600_COMMON_ON       0
#define SPI1_7600_MAIN_CHIP_ON    0
#define SPI1_7600_AUX_CHIP_ON     0
#define SPI1_7800_COMMON_ON       0
#define SPI1_7800_MAIN_CHIP_ON    0
#define SPI1_7800_AUX_CHIP_ON     0
#define SPI1_8000_COMMON_ON       0
#define SPI1_9000_COMMON_ON       0
#define SPI1_9600_COMMON_ON       0
#if   ((SPI1_VERSION / 100)   == 10)
#undef  SPI1_1000_COMMON_ON
#define SPI1_1000_COMMON_ON       1
#endif
#if   ((SPI1_VERSION / 100)   == 40)
#undef  SPI1_4000_COMMON_ON
#define SPI1_4000_COMMON_ON       1
#endif
#if   ((SPI1_VERSION / 100)   == 68)
#undef  SPI1_6800_COMMON_ON
#define SPI1_6800_COMMON_ON       1
#endif
#if   ((SPI1_VERSION / 100)   == 69)
#undef  SPI1_6900_COMMON_ON
#define SPI1_6900_COMMON_ON       1
#endif
#if   ((SPI1_VERSION / 100)   == 76)
#undef  SPI1_7600_COMMON_ON
#define SPI1_7600_COMMON_ON       1
#endif
#if   ((SPI1_VERSION / 10)   == 760)
#undef  SPI1_7600_MAIN_CHIP_ON
#define SPI1_7600_MAIN_CHIP_ON    1
#endif
#if   ((SPI1_VERSION / 10)   == 761)
#undef  SPI1_7600_AUX_CHIP_ON
#define SPI1_7600_AUX_CHIP_ON     1
#endif
#if   ((SPI1_VERSION / 100)   == 78)
#undef  SPI1_7800_COMMON_ON
#define SPI1_7800_COMMON_ON       1
#endif
#if   ((SPI1_VERSION / 10)   == 780)
#undef  SPI1_7800_MAIN_CHIP_ON
#define SPI1_7800_MAIN_CHIP_ON    1
#endif
#if   ((SPI1_VERSION / 10)   == 781)
#undef  SPI1_7800_AUX_CHIP_ON
#define SPI1_7800_AUX_CHIP_ON     1
#endif
#if   ((SPI1_VERSION / 100)   == 80)
#undef  SPI1_8000_COMMON_ON
#define SPI1_8000_COMMON_ON       1
#endif
#if   ((SPI1_VERSION / 100)   == 90)
#undef  SPI1_9000_COMMON_ON
#define SPI1_9000_COMMON_ON       1
#endif
#if   ((SPI1_VERSION / 100)   == 96)
#undef  SPI1_9600_COMMON_ON
#define SPI1_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define SPI1_FUNCTION_ON          0
#define SPI1_CPU_9S12_ON          0
#define SPI1_CPU_POWERPC_ON       0
#define SPI1_CPU_STM32F1_ON       0
#define SPI1_CPU_STM32F103_ON     0
#define SPI1_CPU_STM32F105_ON     0
#if    (SPI1_1000_COMMON_ON    == 1)
#undef  SPI1_CPU_9S12_ON
#define SPI1_CPU_9S12_ON          1
#endif
#if    (SPI1_4000_COMMON_ON    == 1)
#undef  SPI1_CPU_9S12_ON
#define SPI1_CPU_9S12_ON          1
#endif
#if    (SPI1_6800_COMMON_ON    == 1)
#undef  SPI1_CPU_9S12_ON
#define SPI1_CPU_9S12_ON          1
#endif
#if    (SPI1_6900_COMMON_ON    == 1)
#undef  SPI1_CPU_POWERPC_ON
#define SPI1_CPU_POWERPC_ON       1
#endif
#if    (SPI1_7600_COMMON_ON    == 1)
#undef  SPI1_CPU_STM32F1_ON
#define SPI1_CPU_STM32F1_ON       1
#endif
#if    (SPI1_7600_MAIN_CHIP_ON == 1)
#undef  SPI1_CPU_STM32F105_ON
#define SPI1_CPU_STM32F105_ON     1
#endif
#if    (SPI1_7600_AUX_CHIP_ON  == 1)
#undef  SPI1_CPU_STM32F103_ON
#define SPI1_CPU_STM32F103_ON     1
#endif
#if    (SPI1_7800_COMMON_ON    == 1)
#undef  SPI1_CPU_STM32F1_ON
#define SPI1_CPU_STM32F1_ON       1
#endif
#if    (SPI1_7800_MAIN_CHIP_ON == 1)
#undef  SPI1_CPU_STM32F105_ON
#define SPI1_CPU_STM32F105_ON     1
#endif
#if    (SPI1_7800_AUX_CHIP_ON  == 1)
#undef  SPI1_CPU_STM32F103_ON
#define SPI1_CPU_STM32F103_ON     1
#endif
#if    (SPI1_8000_COMMON_ON    == 1)
#undef  SPI1_CPU_POWERPC_ON
#define SPI1_CPU_POWERPC_ON       1
#endif
#if    (SPI1_9000_COMMON_ON    == 1)
#undef  SPI1_CPU_POWERPC_ON
#define SPI1_CPU_POWERPC_ON       1
#endif
#if    (SPI1_9600_COMMON_ON    == 1)
#undef  SPI1_CPU_POWERPC_ON
#define SPI1_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                    (F105 SPI1 Remap Definition)                      */
/* Default:  (SPI1_NSS/PA4,  SCK/PA5, MISO/PA6, MOSI/PA7)               */
/* Remap:    (SPI1_NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5)               */
/* ******************************************************************** */
#define SPI1_AFIO_REMAP1        0
#define SPI1_AFIO_REMAP2        0
#define SPI1_PT_BT_CS           PA4
#define SPI1_PT_BT_SCK          PA5
#define SPI1_PT_BT_IN           PA6
#define SPI1_PT_BT_OUT          PA7
#define SPI1_PT_BT_CD           PC4
#define SPI1_PT_CS              GPIOA
#define SPI1_PT_SCK             GPIOA
#define SPI1_PT_IN              GPIOA
#define SPI1_PT_OUT             GPIOA
#define SPI1_PT_CD              GPIOC
#define SPI1_BT_CS              4
#define SPI1_BT_SCK             5
#define SPI1_BT_IN              6
#define SPI1_BT_OUT             7
#define SPI1_BT_CD              4
#define SPI1_CLK_SLOW()         SPI1->CR1 |=  SPI_CR1_BR_0 | SPI_CR1_BR_2
#define SPI1_CLK_FAST()         SPI1->CR1 &= ~SPI_CR1_BR
#define SPI1_CS_HIGH()          SPI1_PT_CS->BSRR = 1UL <<  SPI1_BT_CS
#define SPI1_CS_LOW()           SPI1_PT_CS->BSRR = 1UL << (SPI1_BT_CS+16)
#define SPI1_GET_DETECT_PIN()  (SPI1_PT_CD->IDR & (1UL << SPI1_BT_CD))

/* ******************************************************************** */
/*                           Control Definition                         */
/* ******************************************************************** */
#define SPI1_I2S_FLAG_RXNE     (INT16U)0x0001
#define SPI1_I2S_FLAG_TXE      (INT16U)0x0002
#define SPI1_I2S_FLAG_CHSIDE   (INT16U)0x0004
#define SPI1_I2S_FLAG_UDR      (INT16U)0x0008
#define SPI1_I2S_FLAG_CRCERR   (INT16U)0x0010
#define SPI1_I2S_FLAG_MODF     (INT16U)0x0020
#define SPI1_I2S_FLAG_OVR      (INT16U)0x0040
#define SPI1_I2S_FLAG_BSY      (INT16U)0x0080
#define SPI1_STS_NORMAL        (INT32U)0x00000000
#define SPI1_STS_RESET         (INT32U)0x00000001
#define SPI1_STS_WARNING       (INT32U)0x00000002
#define SPI1_STS_BUS_OFF       (INT32U)0x00000004
#define SPI1_STS_SLEEPING      (INT32U)0x00000008
#define SPI1_STS_OVERRUN       (INT32U)0x00000010
#define SPI1_STS_ERR_TX        (INT32U)0x00000020
#define SPI1_STS_ERR_RX        (INT32U)0x00000040
#define SPI1_STS_ERR_ADDR      (INT32U)0x00000080
#define SPI1_STS_ERR_LOGIC     (INT32U)0x00000100
#define SPI1_STS_ERR_CARD      (INT32U)0x00000200
#define SPI1_STS_ERR_RTC       (INT32U)0x00000400
#define SPI1_STS_ERR_OPEN      (INT32U)0x00000800
#define SPI1_STS_ERR_READ      (INT32U)0x00001000
#define SPI1_STS_ERR_WRITE     (INT32U)0x00002000
#define SPI1_STS_GET_BIT(m)    (uiSPI1Status & (m))
#define SPI1_STS_CLR_BIT(m)     uiSPI1Status &= ~(m)
#define SPI1_STS_SET_BIT(m)     uiSPI1Status |= (m)
#define SPI1_CMD_BUF_SIZE       8
#define SPI1_CMD_TO_TICKS       10
#define SPI1_CMD_SAVE_FILE      0x55
#define SPI1_FILE_NAME_SIZE     32
#define SPI1_DATA_BUFF_SIZE     400

/* ***********************************t********************************* */
/*                            Type Definition                            */
/* ********************************************************************* */
typedef struct
{   INT16U      usRingBufRxCtr;
    OS_EVENT   *pRingBufRxSem;
    INT08U     *pRingBufRxInPtr;
    INT08U     *pRingBufRxOutPtr;
    INT08U      ucRingBufRx[SPI1_CMD_BUF_SIZE];
}   SPI1_CMD_RING;

/* ******************************************************************** */
/*                     Variable Definitions                             */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)

SPI1_EXT INT32U uiSPI1Status;
SPI1_EXT FIL    sSPI1File;
SPI1_EXT FATFS  sSPI1FatFs;
SPI1_EXT INT08S aSPI1FileName[SPI1_FILE_NAME_SIZE];
SPI1_EXT INT08U aSPI1DataBuff[SPI1_DATA_BUFF_SIZE];
SPI1_EXT RTC_TIME_STR sSPI1RtcTime;
SPI1_EXT SPI1_CMD_RING sSPI1CmdRingBuf;

#endif
/* ******************************************************************** */
/*                      Function Definition                             */
/* ******************************************************************** */
#if (SPI1_FUNCTION_ON == 1)

SPI1_EXT void   SPI1Init(void);
SPI1_EXT void   SPI1Start(void);
SPI1_EXT void   SPI1TaskLoop(void);
SPI1_EXT void   SPI1IntHook(void);
SPI1_EXT void   SPI1CmdBufInit(void);
SPI1_EXT INT08U SPI1TskGetCmd(INT16U to, INT08U *err);
SPI1_EXT void   SPI1TskPutCmd(INT08U c);
SPI1_EXT void   SPI1HardInit(void);
SPI1_EXT INT08U SPI1Read08u(void);
SPI1_EXT INT08U SPI1Write08u(INT08U ucData);
SPI1_EXT INT08U SPI1Exchange08u(INT08U ucData);
SPI1_EXT INT16U SPI1Read16u(void);
SPI1_EXT INT16U SPI1Write16u(INT16U usData);
SPI1_EXT INT16U SPI1Exchange16u(INT16U usData);
SPI1_EXT void   SPI1SendHardCrc(void);
SPI1_EXT INT08U SPI1GetHardCrc08u(INT08U ucTxOrRx);
SPI1_EXT INT16U SPI1GetHardCrc16u(INT08U ucTxOrRx);
SPI1_EXT INT16U SPI1GetFlags(INT16U usFlgMsk);
SPI1_EXT void   SPI1ClrFlags(INT16U usFlgMsk);
SPI1_EXT void   SPI1ConfigI2S(INT08U ucNewState);
SPI1_EXT void   SPI1ConfigIT(INT16U usIntMsk, INT08U ucNewState);
SPI1_EXT void   SPI1ConfigDMA(INT16U usDmaMsk, INT08U ucNewState);
SPI1_EXT void   SPI1ConfigHardCrc(INT08U ucNewState);
SPI1_EXT void   SPI1SetDataSize08b(void);
SPI1_EXT void   SPI1SetDataSize16b(void);
SPI1_EXT void   SPI1CreatFileName(RTC_TIME_STR *pRtc, INT08S *pName);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
