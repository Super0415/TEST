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
FW_EXT volatile INT16U Time2Count;
FW_EXT volatile INT16U RS485OverTCount;  //485发送接收周期间隔计数
FW_EXT volatile INT16U RSOnTime0;
FW_EXT volatile INT16U RSOnTime1;
FW_EXT volatile INT16U RSOnTime2;
FW_EXT volatile INT16U RSOnTime3;
FW_EXT volatile INT16U RSOnTime4;
FW_EXT volatile INT16U RSOnTime5;

FW_EXT volatile INT08U RSOnTimeSign0;
FW_EXT volatile INT08U RSOnTimeSign1;
FW_EXT volatile INT08U RSOnTimeSign2;
FW_EXT volatile INT08U RSOnTimeSign3;
FW_EXT volatile INT08U RSOnTimeSign4;
FW_EXT volatile INT08U RSOnTimeSign5;

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
