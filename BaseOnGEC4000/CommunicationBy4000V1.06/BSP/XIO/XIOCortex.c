/* ******************************************************************** */
/*                  CAN1 Software for Elctronic Unit (V1.0)             */
/*                       Source File CAN1Cortex.c                       */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   XIO_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                                XIOInit                               */
/* ******************************************************************** */
void XIOInit(void)
{
	KEY_LEDInit();

}	

/* ******************************************************************** */
/*                                XIOStart                              */
/* ******************************************************************** */
void XIOStart(void)
{

}	
/* ******************************************************************** */
/*                                XIOTaskLoop                           */
/* ******************************************************************** */
void XIOTaskLoop(void)
{
	  while(1)
		{
				(void)OSTaskSuspend(OS_PRIO_SELF);
			  TESTZCnum[1]++;
        ReadKeyBuff();
        			
		}
}	


/* ******************************************************************** */
/*                                KEY_LEDInit                           */
/* ******************************************************************** */
void KEY_LEDInit(void)
{
	  GPIO_InitTypeDef GPIO_InitStructure;
	
	  RCC_APB2PeriphClockCmd(KEY_GPIO_CLK, ENABLE);
	  //上
    GPIO_InitStructure.GPIO_Pin = KEY_Pin_Menu_Up;    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;
    GPIO_Init(KEY_PORT_Menu_Up, &GPIO_InitStructure);	

	  //确认
    GPIO_InitStructure.GPIO_Pin = KEY_Pin_Menu_ENTER;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;
    GPIO_Init(KEY_PORT_Menu_ENTER, &GPIO_InitStructure);			

    //下
    GPIO_InitStructure.GPIO_Pin = KEY_Pin_Menu_Down;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;
    GPIO_Init(KEY_PORT_Menu_Down, &GPIO_InitStructure);	

    //停机
    GPIO_InitStructure.GPIO_Pin = KEY_Pin_Menu_STOP;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;
    GPIO_Init(KEY_PORT_Menu_STOP, &GPIO_InitStructure);		

    //手动
    GPIO_InitStructure.GPIO_Pin = KEY_Pin_Menu_Manual;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;
    GPIO_Init(KEY_PORT_Menu_Manual, &GPIO_InitStructure);
		
		//自动
    GPIO_InitStructure.GPIO_Pin = KEY_Pin_Menu_AUTO;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;
    GPIO_Init(KEY_PORT_Menu_AUTO, &GPIO_InitStructure);
		
		//复位
    GPIO_InitStructure.GPIO_Pin = KEY_Pin_Menu_RESET;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;
    GPIO_Init(KEY_PORT_Menu_RESET, &GPIO_InitStructure);
		
		//起机
    GPIO_InitStructure.GPIO_Pin = KEY_Pin_Menu_START;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;
    GPIO_Init(KEY_PORT_Menu_START, &GPIO_InitStructure);	
		
		//灯光
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(GPIOE, &GPIO_InitStructure);
		
}

/* ******************************************************************** */
/*                                ReadKeyBuff                           */
/* ******************************************************************** */
INT08U KeyTemp[20];
void ReadKeyBuff(void)
{
    if(XIO_GET_KEY_Up()!=1) KeyTemp[SF_KEY_BIT_MENU_UP]=1;                  //上键
    if((XIO_GET_KEY_Up()!=1)  && KeyTemp[SF_KEY_BIT_MENU_UP]==1)
    {
        usDBmKeyMenuUp      = 1;
        KeyTemp[SF_KEY_BIT_MENU_UP]=0;    
    }

    if(XIO_GET_KEY_Down()!=1) KeyTemp[SF_KEY_BIT_MENU_DOWN]=1;              //下键
    if((XIO_GET_KEY_Down()!=1)  && KeyTemp[SF_KEY_BIT_MENU_DOWN]==1)
    {
        usDBmKeyMenuDown      = 1;
        KeyTemp[SF_KEY_BIT_MENU_DOWN]=0;    
    }
		
		if(XIO_GET_KEY_ENTER()!=1) KeyTemp[SF_KEY_BIT_MENU_ENTER]=1;           //确认键
    if((XIO_GET_KEY_ENTER()!=1)  && KeyTemp[SF_KEY_BIT_MENU_ENTER]==1)
    {
        usDBmKeyMenuEnter      = 1;
        KeyTemp[SF_KEY_BIT_MENU_ENTER]=0;    
    }
		
		if(XIO_GET_KEY_STOP()!=1) KeyTemp[SF_KEY_BIT_ENG_STOP]=1;
    if((XIO_GET_KEY_STOP()!=1)  && KeyTemp[SF_KEY_BIT_ENG_STOP]==1)
    {
        usDBmKeyEngineStop      = 1;
        KeyTemp[SF_KEY_BIT_ENG_STOP]=0;    
    }
		
		if(XIO_GET_KEY_Manual()!=1) KeyTemp[SF_KEY_BIT_MODE_MANUAL]=1;
    if((XIO_GET_KEY_Manual()!=1)  && KeyTemp[SF_KEY_BIT_MODE_MANUAL]==1)
    {
        usDBmKeyModeManual      = 1;
        KeyTemp[SF_KEY_BIT_MODE_MANUAL]=0;    
    }
		
		if(XIO_GET_KEY_AUTO()!=1) KeyTemp[SF_KEY_BIT_MODE_AUTO]=1;
    if((XIO_GET_KEY_AUTO()!=1)  && KeyTemp[SF_KEY_BIT_MODE_AUTO]==1)
    {
        usDBmKeyModeAuto      = 1;
        KeyTemp[SF_KEY_BIT_MODE_AUTO]=0;    
    }
		
		if(XIO_GET_KEY_RESET()!=1) KeyTemp[SF_KEY_BIT_ERROR_RESET]=1;         //左键
    if((XIO_GET_KEY_RESET()!=1)  && KeyTemp[SF_KEY_BIT_ERROR_RESET]==1)
    {
        //usDBmKeyErrorReset      = 1;
			  usDBmKeyMenuLeft        =1;
        KeyTemp[SF_KEY_BIT_ERROR_RESET]=0;    
    }
	
		if(XIO_GET_KEY_START()!=1) KeyTemp[SF_KEY_BIT_ENG_START]=1;          //右键
    if((XIO_GET_KEY_START()!=1)  && KeyTemp[SF_KEY_BIT_ENG_START]==1)
    {
        //usDBmKeyEngineStart      = 1;
			  usDBmKeyMenuRight        =1;
        KeyTemp[SF_KEY_BIT_ENG_START]=0;    
    }
		
//		if(XIO_GET_KEY_Up()    !=1) usDBmKeyMenuUp     		= 1;
//		if(XIO_GET_KEY_Down()  !=1) usDBmKeyMenuDown   		= 1;
//		if(XIO_GET_KEY_ENTER() !=1) usDBmKeyMenuEnter  		= 1;
//		if(XIO_GET_KEY_STOP()  !=1) usDBmKeyEngineStop 		= 1;
//		if(XIO_GET_KEY_Manual()!=1) usDBmKeyModeManual 		= 1;
//		if(XIO_GET_KEY_AUTO()  !=1) usDBmKeyModeAuto   		= 1;
//		if(XIO_GET_KEY_RESET() !=1) usDBmKeyErrorReset  	= 1;
//		if(XIO_GET_KEY_START() !=1) usDBmKeyEngineStart  	= 1;
		
		if(usFW100msTimer%20 > 10)GPIO_SetBits(GPIOE,GPIO_Pin_4);
		else GPIO_ResetBits(GPIOE,GPIO_Pin_4);
}
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
