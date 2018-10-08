/* ******************************************************************** */
/*                     MODBUS protocol Version 1.0                      */
/*                       Header File SCI4Cortex.h                       */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _SCI4CORTEX_H

#define _SCI4CORTEX_H

#ifdef   SCI4_GLOBALS

#define  SCI4_EXT  

#else

#define  SCI4_EXT extern

#endif

/* ******************************************************************** */
/*  SCI4_VERSION  = 10xx: VEC1000 Application                           */
/*  SCI4_VERSION  = 40xx: VEC4000 Application                           */
/*  SCI4_VERSION  = 68xx: VEC6800 Application                           */
/*  SCI4_VERSION  = 69xx: VEC6900 Application                           */
/*  SCI4_VERSION  = 760x: GEC7600-Main Application                      */
/*  SCI4_VERSION  = 761x: GEC7600-Display Application                   */
/*  SCI4_VERSION  = 780x: GEC7800-Main Application                      */
/*  SCI4_VERSION  = 781x: GEC7800-Display Application                   */
/*  SCI4_VERSION  = 80xx: VEC8000 Application                           */
/*  SCI4_VERSION  = 90xx: VEC9000 Application                           */
/*  SCI4_VERSION  = 96xx: VEC9600 Application                           */
/* ******************************************************************** */

#define SCI4_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define SCI4_1000_COMMON_ON       0
#define SCI4_4000_COMMON_ON       0
#define SCI4_6800_COMMON_ON       0
#define SCI4_6900_COMMON_ON       0
#define SCI4_7600_COMMON_ON       0
#define SCI4_7600_MAIN_CHIP_ON    0
#define SCI4_7600_AUX_CHIP_ON     0
#define SCI4_7800_COMMON_ON       0
#define SCI4_7800_MAIN_CHIP_ON    0
#define SCI4_7800_AUX_CHIP_ON     0
#define SCI4_8000_COMMON_ON       0
#define SCI4_9000_COMMON_ON       0
#define SCI4_9600_COMMON_ON       0
#if   ((SCI4_VERSION / 100)   == 10)
#undef  SCI4_1000_COMMON_ON
#define SCI4_1000_COMMON_ON       1
#endif
#if   ((SCI4_VERSION / 100)   == 40)
#undef  SCI4_4000_COMMON_ON
#define SCI4_4000_COMMON_ON       1
#endif
#if   ((SCI4_VERSION / 100)   == 68)
#undef  SCI4_6800_COMMON_ON
#define SCI4_6800_COMMON_ON       1
#endif
#if   ((SCI4_VERSION / 100)   == 69)
#undef  SCI4_6900_COMMON_ON
#define SCI4_6900_COMMON_ON       1
#endif
#if   ((SCI4_VERSION / 100)   == 76)
#undef  SCI4_7600_COMMON_ON
#define SCI4_7600_COMMON_ON       1
#endif
#if   ((SCI4_VERSION / 10)   == 760)
#undef  SCI4_7600_MAIN_CHIP_ON
#define SCI4_7600_MAIN_CHIP_ON    1
#endif
#if   ((SCI4_VERSION / 10)   == 761)
#undef  SCI4_7600_AUX_CHIP_ON
#define SCI4_7600_AUX_CHIP_ON     1
#endif
#if   ((SCI4_VERSION / 100)   == 78)
#undef  SCI4_7800_COMMON_ON
#define SCI4_7800_COMMON_ON       1
#endif
#if   ((SCI4_VERSION / 10)   == 780)
#undef  SCI4_7800_MAIN_CHIP_ON
#define SCI4_7800_MAIN_CHIP_ON    1
#endif
#if   ((SCI4_VERSION / 10)   == 781)
#undef  SCI4_7800_AUX_CHIP_ON
#define SCI4_7800_AUX_CHIP_ON     1
#endif
#if   ((SCI4_VERSION / 100)   == 80)
#undef  SCI4_8000_COMMON_ON
#define SCI4_8000_COMMON_ON       1
#endif
#if   ((SCI4_VERSION / 100)   == 90)
#undef  SCI4_9000_COMMON_ON
#define SCI4_9000_COMMON_ON       1
#endif
#if   ((SCI4_VERSION / 100)   == 96)
#undef  SCI4_9600_COMMON_ON
#define SCI4_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define SCI4_SLAVE_FUNCTION_ON    1
#define SCI4_MASTER_FUNCTION_ON   0
#define SCI4_CPU_9S12_ON          0
#define SCI4_CPU_POWERPC_ON       0
#define SCI4_CPU_STM32F1_ON       0
#define SCI4_CPU_STM32F103_ON     0
#define SCI4_CPU_STM32F105_ON     0
#if    (SCI4_1000_COMMON_ON    == 1)
#undef  SCI4_CPU_9S12_ON
#define SCI4_CPU_9S12_ON          1
#endif
#if    (SCI4_4000_COMMON_ON    == 1)
#undef  SCI4_CPU_9S12_ON
#define SCI4_CPU_9S12_ON          1
#endif
#if    (SCI4_6800_COMMON_ON    == 1)
#undef  SCI4_CPU_9S12_ON
#define SCI4_CPU_9S12_ON          1
#endif
#if    (SCI4_6900_COMMON_ON    == 1)
#undef  SCI4_CPU_POWERPC_ON
#define SCI4_CPU_POWERPC_ON       1
#endif
#if    (SCI4_7600_COMMON_ON    == 1)
#undef  SCI4_CPU_STM32F1_ON
#define SCI4_CPU_STM32F1_ON       1
#endif
#if    (SCI4_7600_MAIN_CHIP_ON == 1)
#undef  SCI4_CPU_STM32F105_ON
#define SCI4_CPU_STM32F105_ON     1
#endif
#if    (SCI4_7600_AUX_CHIP_ON  == 1)
#undef  SCI4_CPU_STM32F103_ON
#define SCI4_CPU_STM32F103_ON     1
#endif
#if    (SCI4_7800_COMMON_ON    == 1)
#undef  SCI4_CPU_STM32F1_ON
#define SCI4_CPU_STM32F1_ON       1
#endif
#if    (SCI4_7800_MAIN_CHIP_ON == 1)
#undef  SCI4_CPU_STM32F105_ON
#define SCI4_CPU_STM32F105_ON     1
#endif
#if    (SCI4_7800_AUX_CHIP_ON  == 1)
#undef  SCI4_CPU_STM32F103_ON
#define SCI4_CPU_STM32F103_ON     1
#endif
#if    (SCI4_8000_COMMON_ON    == 1)
#undef  SCI4_CPU_POWERPC_ON
#define SCI4_CPU_POWERPC_ON       1
#endif
#if    (SCI4_9000_COMMON_ON    == 1)
#undef  SCI4_CPU_POWERPC_ON
#define SCI4_CPU_POWERPC_ON       1
#endif
#if    (SCI4_9600_COMMON_ON    == 1)
#undef  SCI4_CPU_POWERPC_ON
#define SCI4_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                 F105 UART4 RX And TX Pin Definition                 */
/*                   (Default: PC10 & PC11, No Remap)                   */
/* ******************************************************************** */
#if    (SCI4_SLAVE_FUNCTION_ON == 1)
#define SCI4_AFIO_REMAP1        0
#define SCI4_AFIO_REMAP2        0
#define SCI4_GPO_PT_SCITX       PC10
#define SCI4_GPI_PT_SCIRX       PC11
#define SCI4_TX_PT              GPIOC
#define SCI4_TX_BT              10
#define SCI4_RX_PT              GPIOC
#define SCI4_RX_BT              11
#endif
#if    (SCI4_MASTER_FUNCTION_ON == 1)
#define SCI4_AFIO_REMAP1        0
#define SCI4_AFIO_REMAP2        0
#define SCI4_GPO_PT_SCITX       PC10
#define SCI4_GPI_PT_SCIRX       PC11
#define SCI4_TX_PT              GPIOC
#define SCI4_TX_BT              10
#define SCI4_RX_PT              GPIOC
#define SCI4_RX_BT              11
#endif

/* ******************************************************************** */
/*                           Hardware Difference                        */
/* ******************************************************************** */
#if    (SCI4_SLAVE_FUNCTION_ON == 1)
#define SCI4_FRQ_CLK           (INT32U)36000000      /* PCLK1 for UART4 */
#define SCI4_SCI_RX_EN()        UART4->CR1 |=  USART_CR1_RE
#define SCI4_SCI_RX_DIS()       UART4->CR1 &= ~USART_CR1_RE
#define SCI4_SCI_RX_INT_EN()    UART4->CR1 |=  USART_CR1_RXNEIE
#define SCI4_SCI_RX_INT_DIS()   UART4->CR1 &= ~USART_CR1_RXNEIE
#define SCI4_SCI_TX_EN()        UART4->CR1 |=  USART_CR1_TE
#define SCI4_SCI_TX_DIS()       UART4->CR1 &= ~USART_CR1_TE
#define SCI4_SCI_TC_INT_EN()    UART4->CR1 |=  USART_CR1_TCIE
#define SCI4_SCI_TC_INT_DIS()   UART4->CR1 &= ~USART_CR1_TCIE
#define SCI4_SCI_TX_INT_EN()    UART4->CR1 |=  USART_CR1_TXEIE
#define SCI4_SCI_TX_INT_DIS()   UART4->CR1 &= ~USART_CR1_TXEIE
#define SCI4_SCI_SR_TC_CLR()    UART4->SR  &= ~USART_SR_TC
#define SCI4_SCI_TXDMA_EN()     UART4->CR3 |=  USART_CR3_DMAT
#define SCI4_SCI_TXDMA_DIS()    UART4->CR3 &= ~USART_CR3_DMAT
#define SCI4_SCI_RXDMA_EN()     UART4->CR3 |=  USART_CR3_DMAR
#define SCI4_SCI_RXDMA_DIS()    UART4->CR3 &= ~USART_CR3_DMAR
#define SCI4_TX_DMA_CHANNEL     DMA2->Channel5
#define SCI4_RX_DMA_CHANNEL     DMA2->Channel3
#define SCI4_SCI_TX_DMA_ON      1
#define SCI4_SCI_RX_DMA_ON      1
#define SCI4_TX_DMA_TCINT_ON    0
#define SCI4_RX_DMA_TCINT_ON    1
#endif
#if    (SCI4_MASTER_FUNCTION_ON == 1)
#define SCI4_FRQ_CLK           (INT32U)36000000      /* PCLK1 for UART4 */
#define SCI4_SCI_RX_EN()        UART4->CR1 |=  USART_CR1_RE
#define SCI4_SCI_RX_DIS()       UART4->CR1 &= ~USART_CR1_RE
#define SCI4_SCI_RX_INT_EN()    UART4->CR1 |=  USART_CR1_RXNEIE
#define SCI4_SCI_RX_INT_DIS()   UART4->CR1 &= ~USART_CR1_RXNEIE
#define SCI4_SCI_TX_EN()        UART4->CR1 |=  USART_CR1_TE
#define SCI4_SCI_TX_DIS()       UART4->CR1 &= ~USART_CR1_TE
#define SCI4_SCI_TC_INT_EN()    UART4->CR1 |=  USART_CR1_TCIE
#define SCI4_SCI_TC_INT_DIS()   UART4->CR1 &= ~USART_CR1_TCIE
#define SCI4_SCI_TX_INT_EN()    UART4->CR1 |=  USART_CR1_TXEIE
#define SCI4_SCI_TX_INT_DIS()   UART4->CR1 &= ~USART_CR1_TXEIE
#define SCI4_SCI_SR_TC_CLR()    UART4->SR  &= ~USART_SR_TC
#define SCI4_SCI_TXDMA_EN()     UART4->CR3 |=  USART_CR3_DMAT
#define SCI4_SCI_TXDMA_DIS()    UART4->CR3 &= ~USART_CR3_DMAT
#define SCI4_SCI_RXDMA_EN()     UART4->CR3 |=  USART_CR3_DMAR
#define SCI4_SCI_RXDMA_DIS()    UART4->CR3 &= ~USART_CR3_DMAR
#define SCI4_TX_DMA_CHANNEL     DMA2->Channel5
#define SCI4_RX_DMA_CHANNEL     DMA2->Channel3
#define SCI4_SCI_TX_DMA_ON      1
#define SCI4_SCI_RX_DMA_ON      1
#define SCI4_TX_DMA_TCINT_ON    0
#define SCI4_RX_DMA_TCINT_ON    0
#endif

/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define SCI4_TRUE               1
#define SCI4_FALSE              0
#define SCI4_NO_ERR             0
#define SCI4_ERR_EVENT_TYPE     1
#define SCI4_ERR_PEND_ISR       2
#define SCI4_ERR_BAD_CH         3
#define SCI4_ERR_RX_EMPTY       4
#define SCI4_ERR_TX_FULL        5
#define SCI4_ERR_TX_EMPTY       6
#define SCI4_ERR_RX_TIMEOUT     7
#define SCI4_ERR_TX_TIMEOUT     8
#define SCI4_STS_NORMAL        (INT32U)0x00000000
#define SCI4_STS_RESET         (INT32U)0x00000001
#define SCI4_STS_WARNING       (INT32U)0x00000002
#define SCI4_STS_BUS_OFF       (INT32U)0x00000004
#define SCI4_STS_SLEEPING      (INT32U)0x00000008
#define SCI4_STS_OVERRUN       (INT32U)0x00000010
#define SCI4_STS_ERR_TX        (INT32U)0x00000020
#define SCI4_STS_ERR_RX        (INT32U)0x00000040
#define SCI4_STS_ERR_ADDR      (INT32U)0x00000080
#define SCI4_STS_ERR_LOGIC     (INT32U)0x00000100
#define SCI4_STS_TO_1P5_ON     (INT32U)0x00000200
#define SCI4_STS_TO_2P5_ON     (INT32U)0x00000400
#define SCI4_STS_GET_BIT(m)    (uiSCI4Status & (m))
#define SCI4_STS_CLR_BIT(m)     uiSCI4Status &= ~(m)
#define SCI4_STS_SET_BIT(m)     uiSCI4Status |= (m)

/* ******************************************************************** */
/*   Master CALL                Slave RESPOND                           */
/*   0: CODE_CALL               0: CODE_RESPOND                         */
/*   1: Read Begin              1: Read Begin                           */
/*   2: Read Size               2: Read Size                            */
/*   3: Write Begin             3: Read Data0                           */
/*   4: Write Size              4: Read Data1                           */
/*   5: Write Data0                 .......                             */
/*   6: Write Data1             n: Sum of 0~(n-1)                       */
/*   7: Write Data2                                                     */
/*   8: Write Data3                                                     */
/*   9: DigitInputs                                                     */
/*  10: AnalogInput0                                                    */
/*  11: AnalogInput1                                                    */
/*  12: AnalogInput2                                                    */
/*  13: AnalogInput3                                                    */
/*  14: AnalogInput4                                                    */
/*  15: AnalogInput5                                                    */
/*  16: AnalogInput6                                                    */
/*  17: AnalogInput7                                                    */
/*  18: AnalogInput8                                                    */
/*  19: Sum of 0~18                                                     */
/* ******************************************************************** */
#define SCI4_BAUDRATE_DEF       1000000
#define SCI4_CODE_CALL          0x5055
#define SCI4_CODE_RESPOND       0xA0AA
#define SCI4_CODE_BEGIN_PARAM   0
#define SCI4_CODE_SIZE_PARAM    DB_PARAM_SIZE
#define SCI4_CODE_BEGIN_FUNCT  (DB_PARAM_SIZE)
#define SCI4_CODE_SIZE_FUNCT    DB_FUNCT_SIZE
#define SCI4_CODE_BEGIN_CURVE  (DB_PARAM_SIZE+DB_FUNCT_SIZE)
#define SCI4_CODE_SIZE_CURVE    DB_CURVE_SIZE
#define SCI4_CODE_BEGIN_MEASU  (DB_PARAM_SIZE+DB_FUNCT_SIZE+DB_CURVE_SIZE)
#define SCI4_CODE_SIZE_MEASU    DB_MEASU_SIZE
#define SCI4_DIN_DATA_SIZE      1
#define SCI4_AIN_DATA_SIZE      5
#if    (SCI4_SLAVE_FUNCTION_ON == 1)
#define SCI4_RX_BUF_SIZE        20
#define SCI4_TX_BUF_SIZE       (DB_MEASU_SIZE+4)
#define SCI4_READ_SIZE_MAX     (DB_MEASU_SIZE)
#define SCI4_WRITE_SIZE_MAX     4
#define SCI4_TASK_FRQ           50
#endif
#if    (SCI4_MASTER_FUNCTION_ON == 1)
#define SCI4_RX_BUF_SIZE       (DB_MEASU_SIZE+4)
#define SCI4_TX_BUF_SIZE        20
#define SCI4_READ_SIZE_MAX     (DB_MEASU_SIZE)
#define SCI4_WRITE_SIZE_MAX     4
#define SCI4_TASK_FRQ           50
#endif

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
#if (SCI4_SLAVE_FUNCTION_ON == 1)
SCI4_EXT INT32U uiSCI4Status;
SCI4_EXT INT16U aSCI4TxBuf[SCI4_TX_BUF_SIZE];
SCI4_EXT INT16U aSCI4RxBuf[SCI4_RX_BUF_SIZE];
#endif
#if (SCI4_MASTER_FUNCTION_ON == 1)
SCI4_EXT INT32U uiSCI4Status;
SCI4_EXT INT16U usSCI4WriteBegin;
SCI4_EXT INT16U usSCI4WriteSize;
SCI4_EXT INT16U usSCI4WriteData0;
SCI4_EXT INT16U usSCI4WriteData1;
SCI4_EXT INT16U usSCI4WriteData2;
SCI4_EXT INT16U usSCI4WriteData3;
SCI4_EXT INT16U usSCI4DigitInputs;
SCI4_EXT INT16U usSCI4AdcInput[9];
SCI4_EXT INT16U aSCI4TxBuf[SCI4_TX_BUF_SIZE];
SCI4_EXT INT16U aSCI4RxBuf[SCI4_RX_BUF_SIZE];
#endif

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (SCI4_SLAVE_FUNCTION_ON == 1)
SCI4_EXT void   SCI4Init(void);
SCI4_EXT void   SCI4Start(void);
SCI4_EXT void   SCI4Stop(void);
SCI4_EXT void   SCI4Reset(void);
SCI4_EXT void   SCI4TaskLoop(void);
SCI4_EXT void   SCI4TxRxIntHook(void);
SCI4_EXT void   SCI4OverTimerHook(void);
SCI4_EXT void   SCI4Dma2Ch5IntHook(void);
SCI4_EXT void   SCI4Dma2Ch3IntHook(void);
SCI4_EXT INT16U SCI4ProcessMsg(INT16U *pRxBuf, INT16U *pTxBuf);
SCI4_EXT void   SCI4HardInit(INT32U uiBaud);
SCI4_EXT void   SCI4InitTxDma(void);
SCI4_EXT void   SCI4SetupTxDma(INT08U *pAddr, INT16U usSize);
SCI4_EXT void   SCI4InitRxDma(void);
SCI4_EXT void   SCI4SetupRxDma(INT08U *pAddr, INT16U usSize);
#endif

#if (SCI4_MASTER_FUNCTION_ON == 1)
SCI4_EXT void   SCI4Init(void);
SCI4_EXT void   SCI4Start(void);
SCI4_EXT void   SCI4TaskLoop(void);
SCI4_EXT void   SCI4TxRxIntHook(void);
SCI4_EXT void   SCI4OverTimerHook(void);
SCI4_EXT void   SCI4Dma2Ch5IntHook(void);
SCI4_EXT void   SCI4Dma2Ch3IntHook(void);
SCI4_EXT INT08U SCI4TxWriteParam(INT16U usBegin, INT16U usValue);
SCI4_EXT void   SCI4SetTxBuf(INT16U *pTxBuf, INT16U usRBeg,
                             INT16U  usRSiz, INT16U usWSiz);
SCI4_EXT INT08U SCI4ReadRxBuf(INT16U *pRxBuf, INT16U usRxSiz);
SCI4_EXT void   SCI4HardInit(INT32U uiBaud);
SCI4_EXT void   SCI4InitTxDma(void);
SCI4_EXT void   SCI4SetupTxDma(INT08U *pAddr, INT16U usSize);
SCI4_EXT void   SCI4InitRxDma(void);
SCI4_EXT void   SCI4SetupRxDma(INT08U *pAddr, INT16U usSize);
#endif

/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */