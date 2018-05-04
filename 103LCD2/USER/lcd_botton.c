/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��lcdbotton.c
 * ����    ��lcd�ײ�Ӧ�ú�����         
 * ʵ��ƽ̨��Ұ��STM32������
 * Ӳ�����ӣ�-----------------------
 *          |������LCD_GPIO_Config()|
 *           -----------------------
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
******************************************************************************/
#include "lcd_botton.h"
#include "core_cm3.h"
#include "sysTick.h"
void Delay(__IO u32 nCount);



/*��������־λ  0��GRAMָ��ɨ�跽��Ϊ����ģʽ 1��GRAMָ��ɨ�跽��Ϊ����ģʽ*/
volatile u8 display_direction = 0;	 /*�ñ�־λ�����÷����û�ʶ��ǰ�����Ǵ�������ģʽ*/

#define LCD_ILI9341_CMD(index)       LCD_WR_REG(index)
#define LCD_ILI9341_Parameter(val)	 LCD_WR_Data(val)
//#define Delay_us(time)               delay_us(time)   	/*��ʱ����*/								  
#define DEBUG_DELAY()    //Delay_us(500) 	 /*������ʱ���������ʱ��ֱ��ע�͵�����*/

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
typedef unsigned char           INT8U;
typedef signed   char           INT8S;
typedef unsigned char           INT08U;
typedef signed   char           INT08S;
typedef volatile unsigned char  VINT8U;
typedef volatile signed   char  VINT8S;
typedef volatile unsigned char  VINT08U;
typedef volatile signed   char  VINT08S;
typedef unsigned short          INT16U;
typedef signed   short          INT16S;
typedef volatile unsigned short VINT16U;
typedef volatile signed   short VINT16S;
typedef unsigned int            INT24U;
typedef signed   int            INT24S;
typedef volatile unsigned int   VINT24U;
typedef volatile signed   int   VINT24S;
typedef unsigned int            INT32U;
typedef signed   int            INT32S;
typedef volatile unsigned int   VINT32U;
typedef volatile signed   int   VINT32S;
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

void XIO_SetState(GPIO_TypeDef *pPt,INT08U ucBit,u8 usSet)
{    
    if (usSet    ==  0)
    {   pPt->BRR  = (INT32U)0x01 << ucBit;
    }   else
    {   pPt->BSRR = (INT32U)0x01 << ucBit;
    }    
    
}
/* ******************************************************************** */
/*                           XIOConfigGPIO()                            */
/* ******************************************************************** */
void XIOConfigGPIO (GPIO_TypeDef *pPt, INT08U ucBit, INT32U uiMod, INT16U usSet)
{   if (pPt == GPIOA)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    }   else if (pPt == GPIOB)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    }   else if (pPt == GPIOC)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    }   else if (pPt == GPIOD)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
    }   else if (pPt == GPIOE)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;
    }
   #ifdef RCC_APB2ENR_IOPFEN
    else if (pPt == GPIOF)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPFEN;
    }
   #endif
   #ifdef RCC_APB2ENR_IOPGEN
    else if (pPt == GPIOG)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPGEN;
    }
   #endif
    else
    {   return;
    }
//    if (usSet    ==  0)
//    {   pPt->BRR  = (INT32U)0x01 << ucBit;
//    }   else
//    {   pPt->BSRR = (INT32U)0x01 << ucBit;
//    }
    uiMod        &= (INT32U)0x0F;
    ucBit        *=  4;
    if (ucBit    <=  31)
    {   pPt->CRL &= ~((INT32U)0x0F << ucBit);
        pPt->CRL |=  uiMod << ucBit;
    }   else if (ucBit <= 63)
    {   ucBit    -=  32;
        pPt->CRH &= ~((INT32U)0x0F << ucBit);
        pPt->CRH |=  uiMod << ucBit;
    }
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

/*******************************************
 * ��������LCD_GPIO_Config
 * ����  ������FSMC����LCD��I/O
 * ����  : �� 
 * ���  ����
 * ����  ����
 * ע��  ����
*********************************************/  
void GPIO_CtlBKLingtON(void)
{
 //GPIO_SetBits(GPIOB, GPIO_Pin_13);			//LIGHT
	XIO_SetState(GPIOB, XIO_PT_BT13,1);
}

void GPIO_CtlBKLingtOFF(void)
{
// GPIO_ResetBits(GPIOB, GPIO_Pin_13);		//LIGHT
	XIO_SetState(GPIOB, XIO_PT_BT13,0);
}
#define LCD_GPIO  0
INT32U TESTZCLCD[10]; 
void LCD_GPIO_Config(void)
{	
  XIOConfigGPIO(GPIOB, XIO_PT_BT13, XIO_PT_GPO_PP_50M, XIO_PT_SET_0);  //LCD �������	 
		
  XIOConfigGPIO(GPIOE, XIO_PT_BT1, XIO_PT_GPO_PP_50M, XIO_PT_SET_0);  //LCD-RST	
 
	XIOConfigGPIO(GPIOD, XIO_PT_BT0, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PD0
	XIOConfigGPIO(GPIOD, XIO_PT_BT1, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PD1
	XIOConfigGPIO(GPIOD, XIO_PT_BT4, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PD4
	XIOConfigGPIO(GPIOD, XIO_PT_BT5, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PD5
  XIOConfigGPIO(GPIOD, XIO_PT_BT7, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PD7 NE1
	XIOConfigGPIO(GPIOD, XIO_PT_BT8, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PD8
	XIOConfigGPIO(GPIOD, XIO_PT_BT9, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PD9
	XIOConfigGPIO(GPIOD, XIO_PT_BT10, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PD10
  XIOConfigGPIO(GPIOD, XIO_PT_BT11, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PD11 RS
	XIOConfigGPIO(GPIOD, XIO_PT_BT14, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PD14
	XIOConfigGPIO(GPIOD, XIO_PT_BT15, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PD15	

  /* Set PE.07(D4), PE.08(D5), PE.09(D6), PE.10(D7), PE.11(D8), PE.12(D9), PE.13(D10),
     PE.14(D11), PE.15(D12) as alternate function push pull */
	XIOConfigGPIO(GPIOE, XIO_PT_BT7, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PE7
	XIOConfigGPIO(GPIOE, XIO_PT_BT8, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PE8
	XIOConfigGPIO(GPIOE, XIO_PT_BT9, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PE9
	XIOConfigGPIO(GPIOE, XIO_PT_BT10, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PE10
	XIOConfigGPIO(GPIOE, XIO_PT_BT11, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PE11
	XIOConfigGPIO(GPIOE, XIO_PT_BT12, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PE12
	XIOConfigGPIO(GPIOE, XIO_PT_BT13, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PE13
	XIOConfigGPIO(GPIOE, XIO_PT_BT14, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PE14
	XIOConfigGPIO(GPIOE, XIO_PT_BT15, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);  //PE15

	XIO_SetState(GPIOD, XIO_PT_BT7,1);  //CS=1 
	XIO_SetState(GPIOD, XIO_PT_BT0,1);
	XIO_SetState(GPIOD, XIO_PT_BT1,1);
	XIO_SetState(GPIOD, XIO_PT_BT14,1);
	XIO_SetState(GPIOD, XIO_PT_BT15,1);
	XIO_SetState(GPIOE, XIO_PT_BT7,1);  
	XIO_SetState(GPIOE, XIO_PT_BT8,1);  
	XIO_SetState(GPIOE, XIO_PT_BT9,1);  
	XIO_SetState(GPIOE, XIO_PT_BT10,1);  
	XIO_SetState(GPIOE, XIO_PT_BT1,0);  //RESET=0
	XIO_SetState(GPIOD, XIO_PT_BT4,1);  //RD=1
  XIO_SetState(GPIOD, XIO_PT_BT5,1);	  //WR=1

  GPIO_CtlBKLingtON();
	 
	 
}



/*******************************************
 * ��������LCD_FSMC_Config
 * ����  ��LCD  FSMC ģʽ����
 * ����  : �� 
 * ���  ����
 * ����  ����
 * ע��  ����
*********************************************/ 
void LCD_FSMC_Config(void)
{
    /* ʹ��FSMC��ʱ�� */
    RCC->AHBENR |= 1 << 8;     	 	//ʹ��FSMCʱ��                            //Ok
    
	/* bank1��NE1~4,ÿһ����һ��BCR+TCR�������ܹ��˸��Ĵ�����*/
	/* ��������ʹ��NE4 ��Ҳ�Ͷ�ӦBTCR[6],[7]�� */				    
	FSMC_Bank1->BTCR[0] = 0x00000000;
	FSMC_Bank1->BTCR[1] = 0x00000000;
	FSMC_Bank1E->BWTR[0] = 0x00000000;
	/* ����BCR�Ĵ���	ʹ���첽ģʽ */
	FSMC_Bank1->BTCR[0] |= 1 << 12;		//�洢��дʹ��
	FSMC_Bank1->BTCR[0] |= 1 << 14;		//��дʹ�ò�ͬ��ʱ��
	FSMC_Bank1->BTCR[0] |= 1 << 4; 		//�洢�����ݿ��Ϊ16bit 	    
	/* ����BTR�Ĵ��� */	
	/* ��ʱ����ƼĴ��� */							    
	FSMC_Bank1->BTCR[1] |= 0 << 28;		//ģʽA 	 							  	 
	FSMC_Bank1->BTCR[1] |= 1 << 0; 		//��ַ����ʱ�䣨ADDSET��Ϊ2��HCLK 1/36M=27ns	 	 
	/* ��ΪҺ������IC�Ķ����ݵ�ʱ���ٶȲ���̫�졣 */
	FSMC_Bank1->BTCR[1] |= 0x0F << 8;  	//���ݱ���ʱ��Ϊ16��HCLK	 	 
	/* дʱ����ƼĴ��� */ 
	FSMC_Bank1E->BWTR[0] |= 0 << 28; 	//ģʽA 	 							    
	FSMC_Bank1E->BWTR[0] |= 0 << 0;		//��ַ����ʱ�䣨ADDSET��Ϊ1��HCLK 
 	/* 4��HCLK��HCLK=72M����ΪҺ������IC��д�ź���������Ҳ��50ns��72M/4=24M=55ns */  	 
	FSMC_Bank1E->BWTR[0] |= 3 << 8; 	//���ݱ���ʱ��Ϊ4��HCLK	
	/* ʹ��BANK1,����4 */
	FSMC_Bank1->BTCR[0] |= 1 << 0;		//ʹ��BANK1������4	
}





/**********************************
 * ��������LCD_Rst
 * ����  ��LCD �����λ
 * ����  : �� 
 * ���  ����
 * ����  ����
 * ע��  ����
*************************************/
void LCD_Rst(void)
{			
	GPIO_ResetBits(GPIOE, GPIO_Pin_1);	 //�͵�ƽ��λ
    Delay_us(10000); 					   
    GPIO_SetBits(GPIOE, GPIO_Pin_1 );		 	 
    Delay_us(12000); 	
}







/**********************************
 * ��������LCD_RD_data
 * ����  ���� ILI9341 RAM ����
 * ����  : �� 
 * ���  ����ȡ������,16bit *
 * ����  ����
 * ע��  ����
*************************************/
u16 LCD_RD_data(void)
{
	u16 R=0, G=0, B=0 ;
	LCD_ILI9341_CMD(0x2e);	           /*LCD GRAM READ COMMAND--DATASHEET PAGE116*/
	R =(*(__IO u16 *) (Bank1_LCD_D));  /*FIRST READ OUT DUMMY DATA*/
	R =(*(__IO u16 *) (Bank1_LCD_D));  /*READ OUT RED DATA  */
	B =(*(__IO u16 *) (Bank1_LCD_D));  /*READ OUT BLACK DATA*/
	G =(*(__IO u16 *) (Bank1_LCD_D));  /*READ OUT GREEN DATA*/
	
    return (((R>>11)<<11) | ((G>>10)<<5) | (B>>11)) ;

}




/**********************************
 * ��������Set_direction
 * ����  ������ILI9341GRAMָ��ɨ�跽��
 * ����  : 0�� ����ɨ��
 		   1�� ����ɨ��
 * ���  ����
 * ����  ����
 * ע��  ����
*************************************/
void Set_direction(u8 option)
{

    switch(option)
    {
    case 0:
	{	    /*����*/
        LCD_ILI9341_CMD(0x36); 
		LCD_ILI9341_Parameter(0x68);    //����
		LCD_ILI9341_CMD(0X2A); 
		LCD_ILI9341_Parameter(0x00);	//start 
		LCD_ILI9341_Parameter(0x00);
		LCD_ILI9341_Parameter(0x01);	//end
		LCD_ILI9341_Parameter(0x3F);
		
		LCD_ILI9341_CMD(0X2B); 
		LCD_ILI9341_Parameter(0x00);   //start
		LCD_ILI9341_Parameter(0x00);
		LCD_ILI9341_Parameter(0x00);   //end
		LCD_ILI9341_Parameter(0xEF);
        display_direction = 0;		
        }break;
    case 1:
        {		/*����*/
        LCD_ILI9341_CMD(0x36); 
	    LCD_ILI9341_Parameter(0x48);	//���� 
	    LCD_ILI9341_CMD(0X2A); 
		LCD_ILI9341_Parameter(0x00);
		LCD_ILI9341_Parameter(0x00);
		LCD_ILI9341_Parameter(0x00);
		LCD_ILI9341_Parameter(0xEF);	
		
		LCD_ILI9341_CMD(0X2B); 
		LCD_ILI9341_Parameter(0x00);
		LCD_ILI9341_Parameter(0x00);
		LCD_ILI9341_Parameter(0x01);
		LCD_ILI9341_Parameter(0x3F);
        display_direction = 1;
        }break;
        
    }

}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

/****************************************************************************
* ��    �ƣ�u16 GetPoint(u16 x,u16 y)
* ��    �ܣ���ȡָ���������ɫֵ
* ��ڲ�����x      ������
*           y      ������
* ���ڲ�������ǰ������ɫֵ
* ˵    ����
* ���÷�����i=GetPoint(10,10);
****************************************************************************/
u16 GetPoint(u16 x,u16 y)
{ 
    u16 temp;
	LCD_open_windows(x,y,x,y);
    LCD_ILI9341_CMD(0x2e);
	
	temp=LCD_RD_data();
    return (temp);
}






//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


/**********************************
 * ��������LCD_open_windows
 * ����  ������(��x,yΪ������㣬��Ϊlen,��Ϊwid)
 * ����  : -x    �������
           -y	   �������
           -len  ������ 
           -wid ������
 * ���  ����
 * ����  ����
 * ע��  ����
*************************************/
void LCD_open_windows(u16 x,u16 y,u16 len,u16 wid)
{                    

    if(display_direction == 0)		/*����Ǻ���ѡ��*/
    {

		LCD_ILI9341_CMD(0X2A); 
		LCD_ILI9341_Parameter(x>>8);	//start ��ʼλ�õĸ�8λ
		LCD_ILI9341_Parameter(x-((x>>8)<<8));  //��ʼλ�õĵ�8λ
		LCD_ILI9341_Parameter((x+len-1)>>8);	//end ����λ�õĸ�8λ
		LCD_ILI9341_Parameter((x+len-1)-(((x+len-1)>>8)<<8));  //����λ�õĵ�8λ
		
		LCD_ILI9341_CMD(0X2B); 
		LCD_ILI9341_Parameter(y>>8);   //start
		LCD_ILI9341_Parameter(y-((y>>8)<<8));
		LCD_ILI9341_Parameter((y+wid-1)>>8);   //end
		LCD_ILI9341_Parameter((y+wid-1)-(((y+wid-1)>>8)<<8));
     
    }
    else
    {
		LCD_ILI9341_CMD(0X2B); 
		LCD_ILI9341_Parameter(x>>8);
		LCD_ILI9341_Parameter(x-((x>>8)<<8));
		LCD_ILI9341_Parameter((x+len-1)>>8);
		LCD_ILI9341_Parameter((x+len-1)-(((x+len-1)>>8)<<8));

	    LCD_ILI9341_CMD(0X2A); 
		LCD_ILI9341_Parameter(y>>8);
		LCD_ILI9341_Parameter(y-((y>>8)<<8));
		LCD_ILI9341_Parameter((y+wid-1)>>8);
		LCD_ILI9341_Parameter((y+wid-1)-(((y+wid-1)>>8)<<8));	
        
    }

      LCD_ILI9341_CMD(0x2c);     
}



void Lcd_data_start(void)
{
         LCD_WR_REG(0x2C);//��ʼд���ݵ�GRAM
}




/**********************************
 * ��������Lcd_init_conf
 * ����  ��ILI9341 LCD�Ĵ�����ʼ����
 * ����  : ��
 * ���  ����
 * ����  ����
 * ע��  ����
*************************************/
void Lcd_init_conf(void)
{
	DEBUG_DELAY();
	LCD_ILI9341_CMD(0xCF);
	LCD_ILI9341_Parameter(0x00);
	LCD_ILI9341_Parameter(0x81);
	LCD_ILI9341_Parameter(0x30);
	
	DEBUG_DELAY();
	LCD_ILI9341_CMD(0xED);
	LCD_ILI9341_Parameter(0x64);
	LCD_ILI9341_Parameter(0x03);
	LCD_ILI9341_Parameter(0x12);
	LCD_ILI9341_Parameter(0x81);
	
	DEBUG_DELAY();
	LCD_ILI9341_CMD(0xE8);
	LCD_ILI9341_Parameter(0x85);
	LCD_ILI9341_Parameter(0x10);
	LCD_ILI9341_Parameter(0x78);
	
	DEBUG_DELAY();
	LCD_ILI9341_CMD(0xCB);
	LCD_ILI9341_Parameter(0x39);
	LCD_ILI9341_Parameter(0x2C);
	LCD_ILI9341_Parameter(0x00);
	LCD_ILI9341_Parameter(0x34);
	LCD_ILI9341_Parameter(0x02);
	
	DEBUG_DELAY();
	LCD_ILI9341_CMD(0xF7);
	LCD_ILI9341_Parameter(0x20);
	
	DEBUG_DELAY();
	LCD_ILI9341_CMD(0xEA);
	LCD_ILI9341_Parameter(0x00);
	LCD_ILI9341_Parameter(0x00);
	
	DEBUG_DELAY();
	LCD_ILI9341_CMD(0xB1);
	LCD_ILI9341_Parameter(0x00);
	LCD_ILI9341_Parameter(0x1B);
	
	DEBUG_DELAY();
	LCD_ILI9341_CMD(0xB6);
	LCD_ILI9341_Parameter(0x0A);
	LCD_ILI9341_Parameter(0xA2);
	
	DEBUG_DELAY();
	LCD_ILI9341_CMD(0xC0);
	LCD_ILI9341_Parameter(0x35);
	
	DEBUG_DELAY();
	LCD_ILI9341_CMD(0xC1);
	LCD_ILI9341_Parameter(0x11);
	
	LCD_ILI9341_CMD(0xC5);
	LCD_ILI9341_Parameter(0x45);
	LCD_ILI9341_Parameter(0x45);
	
	LCD_ILI9341_CMD(0xC7);
	LCD_ILI9341_Parameter(0xA2);
	
	LCD_ILI9341_CMD(0xF2);
	LCD_ILI9341_Parameter(0x00);
	
	LCD_ILI9341_CMD(0x26);
	LCD_ILI9341_Parameter(0x01);
	DEBUG_DELAY();
	LCD_ILI9341_CMD(0xE0); //Set Gamma
	LCD_ILI9341_Parameter(0x0F);
	LCD_ILI9341_Parameter(0x26);
	LCD_ILI9341_Parameter(0x24);
	LCD_ILI9341_Parameter(0x0B);
	LCD_ILI9341_Parameter(0x0E);
	LCD_ILI9341_Parameter(0x09);
	LCD_ILI9341_Parameter(0x54);
	LCD_ILI9341_Parameter(0xA8);
	LCD_ILI9341_Parameter(0x46);
	LCD_ILI9341_Parameter(0x0C);
	LCD_ILI9341_Parameter(0x17);
	LCD_ILI9341_Parameter(0x09);
	LCD_ILI9341_Parameter(0x0F);
	LCD_ILI9341_Parameter(0x07);
	LCD_ILI9341_Parameter(0x00);
	LCD_ILI9341_CMD(0XE1); //Set Gamma
	LCD_ILI9341_Parameter(0x00);
	LCD_ILI9341_Parameter(0x19);
	LCD_ILI9341_Parameter(0x1B);
	LCD_ILI9341_Parameter(0x04);
	LCD_ILI9341_Parameter(0x10);
	LCD_ILI9341_Parameter(0x07);
	LCD_ILI9341_Parameter(0x2A);
	LCD_ILI9341_Parameter(0x47);
	LCD_ILI9341_Parameter(0x39);
	LCD_ILI9341_Parameter(0x03);
	LCD_ILI9341_Parameter(0x06);
	LCD_ILI9341_Parameter(0x06);
	LCD_ILI9341_Parameter(0x30);
	LCD_ILI9341_Parameter(0x38);
	LCD_ILI9341_Parameter(0x0F);
	DEBUG_DELAY();
	LCD_ILI9341_CMD(0x36); 
	LCD_ILI9341_Parameter(0x68);    /*����  ���Ͻǵ�(���)�����½�(�յ�)ɨ�跽ʽ*/
	DEBUG_DELAY();
	LCD_ILI9341_CMD(0X2A); 
	LCD_ILI9341_Parameter(0x00);
	LCD_ILI9341_Parameter(0x00);
	LCD_ILI9341_Parameter(0x01);
	LCD_ILI9341_Parameter(0x3F);
	
	DEBUG_DELAY();
	LCD_ILI9341_CMD(0X2B); 
	LCD_ILI9341_Parameter(0x00);
	LCD_ILI9341_Parameter(0x00);
	LCD_ILI9341_Parameter(0x00);
	LCD_ILI9341_Parameter(0xEF);

	DEBUG_DELAY();
	LCD_ILI9341_CMD(0x3a); // Memory Access Control
	LCD_ILI9341_Parameter(0x55);
	LCD_ILI9341_CMD(0x11); //Exit Sleep
	Delay_us(1200);
	LCD_ILI9341_CMD(0x29); //display on
    
	Set_direction(0);	  //����0-->��ʼ��Ĭ��Ϊ������ʽ
	LCD_ILI9341_CMD(0x2c); 
}
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
