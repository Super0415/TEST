/* ******************************************************************** */
/*                     MODBUS protocol Version 1.0                      */
/*                       Header File SCI3Cortex.h                       */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _USART1CORTEX_H

#define _USART1CORTEX_H

#ifdef   USART1_GLOBALS

#define  USART1_EXT  

#else

#define  USART1_EXT extern
#endif
#include "TYPCortex.h"
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#define RSRXData  0x00
#define RSRXData0 0x01
#define RSRXData1 0x02
#define RSRXData2 0x03
#define RSRXData3 0x04
#define RSRXData4 0x05
#define RSRXData5 0x06
#define RSTXData  0x10
#define RSTXData0 0x11
#define RSTXData1 0x12
#define RSTXData2 0x13
#define RSTXData3 0x14
#define RSTXData4 0x15
#define RSTXData5 0x16
#define RSTXDataOver 0x17
USART1_EXT INT08U USART1BUFFINFO; 
USART1_EXT INT16U Time2Count;
USART1_EXT MODBUS_MSG sUSART1ModbusMsg;
USART1_EXT INT08U USART1RxByteCnt;    //485接收数据长度计数


USART1_EXT void USART485_DataInit(void);
USART1_EXT void USART485_Init(void);
USART1_EXT void USART485_Tim2_Init(void);
USART1_EXT void TIM2_NVIC_Configuration(void);
USART1_EXT void TIM2_Configuration(void);
USART1_EXT void SCI1TaskLoop(void);
USART1_EXT void Tim2IntHook(void);
USART1_EXT void USART1SentData(INT16U Length,INT16U * DataAddrese,INT16U CRCCMD);
USART1_EXT void SCI1RxIntHook(void);
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
