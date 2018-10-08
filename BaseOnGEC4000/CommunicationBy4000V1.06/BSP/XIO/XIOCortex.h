/* ******************************************************************** */
/*                CAN1 Software for Elctronic Unit (V1.0)               */
/*                       Header File CAN1Cortex.h                       */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _XIOCORTEX_H

#define _XIOCORTEX_H

#ifdef   XIO_GLOBALS

#define  XIO_EXT  

#else

#define  XIO_EXT extern

#endif
#include "TYPCortex.h"


#define KEY_GPIO_CLK  (RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE)

#define KEY_PORT_Up            GPIOB10
#define KEY_PORT_Menu_Up       GPIOB
#define KEY_Pin_Menu_Up        GPIO_Pin_10
#define XIO_GET_KEY_Up()       GPIO_ReadInputDataBit(KEY_PORT_Menu_Up,KEY_Pin_Menu_Up)

#define KEY_PORT_Down          GPIOB5
#define KEY_PORT_Menu_Down     GPIOB
#define KEY_Pin_Menu_Down      GPIO_Pin_5
#define XIO_GET_KEY_Down()     GPIO_ReadInputDataBit(KEY_PORT_Menu_Down,KEY_Pin_Menu_Down)

#define KEY_PORT_ENTER         GPIOB12
#define KEY_PORT_Menu_ENTER    GPIOB
#define KEY_Pin_Menu_ENTER     GPIO_Pin_12
#define XIO_GET_KEY_ENTER()    GPIO_ReadInputDataBit(KEY_PORT_Menu_ENTER,KEY_Pin_Menu_ENTER)

#define KEY_PORT_STOP          GPIOE6
#define KEY_PORT_Menu_STOP     GPIOE
#define KEY_Pin_Menu_STOP      GPIO_Pin_6
#define XIO_GET_KEY_STOP()     GPIO_ReadInputDataBit(KEY_PORT_Menu_STOP,KEY_Pin_Menu_STOP)

#define KEY_PORT_Manual        GPIOE5
#define KEY_PORT_Menu_Manual   GPIOE
#define KEY_Pin_Menu_Manual    GPIO_Pin_5
#define XIO_GET_KEY_Manual()   GPIO_ReadInputDataBit(KEY_PORT_Menu_Manual,KEY_Pin_Menu_Manual)

#define KEY_PORT_AUTO          GPIOD3
#define KEY_PORT_Menu_AUTO     GPIOD
#define KEY_Pin_Menu_AUTO      GPIO_Pin_3
#define XIO_GET_KEY_AUTO()     GPIO_ReadInputDataBit(KEY_PORT_Menu_AUTO,KEY_Pin_Menu_AUTO)

#define KEY_PORT_RESET         GPIOC11
#define KEY_PORT_Menu_RESET    GPIOC
#define KEY_Pin_Menu_RESET     GPIO_Pin_11
#define XIO_GET_KEY_RESET()     GPIO_ReadInputDataBit(KEY_PORT_Menu_RESET,KEY_Pin_Menu_RESET)

#define KEY_PORT_START         GPIOC10
#define KEY_PORT_Menu_START    GPIOC
#define KEY_Pin_Menu_START     GPIO_Pin_10
#define XIO_GET_KEY_START()    GPIO_ReadInputDataBit(KEY_PORT_Menu_START,KEY_Pin_Menu_START)

XIO_EXT void  XIOInit(void);
XIO_EXT void  XIOStart(void);
XIO_EXT void  XIOTaskLoop(void);
XIO_EXT void  KEY_LEDInit(void);
XIO_EXT void  ReadKeyBuff(void);
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */

