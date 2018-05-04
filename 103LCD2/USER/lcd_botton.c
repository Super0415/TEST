/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * 文件名  ：lcdbotton.c
 * 描述    ：lcd底层应用函数库         
 * 实验平台：野火STM32开发板
 * 硬件连接：-----------------------
 *          |见函数LCD_GPIO_Config()|
 *           -----------------------
 * 库版本  ：ST3.5.0
 *
 * 作者    ：wildfire team 
 * 论坛    ：http://www.amobbs.com/forum-1008-1.html
 * 淘宝    ：http://firestm32.taobao.com
******************************************************************************/
#include "lcd_botton.h"
#include "core_cm3.h"
#include "sysTick.h"
void Delay(__IO u32 nCount);



/*横竖屏标志位  0：GRAM指针扫描方向为横屏模式 1：GRAM指针扫描方向为竖屏模式*/
volatile u8 display_direction = 0;	 /*该标志位的作用方便用户识别当前究竟是处于哪种模式*/

#define LCD_ILI9341_CMD(index)       LCD_WR_REG(index)
#define LCD_ILI9341_Parameter(val)	 LCD_WR_Data(val)
//#define Delay_us(time)               delay_us(time)   	/*延时定义*/								  
#define DEBUG_DELAY()    //Delay_us(500) 	 /*调节延时，如果不延时则直接注释掉即可*/

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
 * 函数名：LCD_GPIO_Config
 * 描述  ：根据FSMC配置LCD的I/O
 * 输入  : 无 
 * 输出  ：无
 * 举例  ：无
 * 注意  ：无
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
  XIOConfigGPIO(GPIOB, XIO_PT_BT13, XIO_PT_GPO_PP_50M, XIO_PT_SET_0);  //LCD 背光控制	 
		
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
 * 函数名：LCD_FSMC_Config
 * 描述  ：LCD  FSMC 模式配置
 * 输入  : 无 
 * 输出  ：无
 * 举例  ：无
 * 注意  ：无
*********************************************/ 
void LCD_FSMC_Config(void)
{
    /* 使能FSMC的时钟 */
    RCC->AHBENR |= 1 << 8;     	 	//使能FSMC时钟                            //Ok
    
	/* bank1有NE1~4,每一个有一个BCR+TCR，所以总共八个寄存器。*/
	/* 这里我们使用NE4 ，也就对应BTCR[6],[7]。 */				    
	FSMC_Bank1->BTCR[0] = 0x00000000;
	FSMC_Bank1->BTCR[1] = 0x00000000;
	FSMC_Bank1E->BWTR[0] = 0x00000000;
	/* 操作BCR寄存器	使用异步模式 */
	FSMC_Bank1->BTCR[0] |= 1 << 12;		//存储器写使能
	FSMC_Bank1->BTCR[0] |= 1 << 14;		//读写使用不同的时序
	FSMC_Bank1->BTCR[0] |= 1 << 4; 		//存储器数据宽度为16bit 	    
	/* 操作BTR寄存器 */	
	/* 读时序控制寄存器 */							    
	FSMC_Bank1->BTCR[1] |= 0 << 28;		//模式A 	 							  	 
	FSMC_Bank1->BTCR[1] |= 1 << 0; 		//地址建立时间（ADDSET）为2个HCLK 1/36M=27ns	 	 
	/* 因为液晶驱动IC的读数据的时候，速度不能太快。 */
	FSMC_Bank1->BTCR[1] |= 0x0F << 8;  	//数据保存时间为16个HCLK	 	 
	/* 写时序控制寄存器 */ 
	FSMC_Bank1E->BWTR[0] |= 0 << 28; 	//模式A 	 							    
	FSMC_Bank1E->BWTR[0] |= 0 << 0;		//地址建立时间（ADDSET）为1个HCLK 
 	/* 4个HCLK（HCLK=72M）因为液晶驱动IC的写信号脉宽，最少也得50ns。72M/4=24M=55ns */  	 
	FSMC_Bank1E->BWTR[0] |= 3 << 8; 	//数据保存时间为4个HCLK	
	/* 使能BANK1,区域4 */
	FSMC_Bank1->BTCR[0] |= 1 << 0;		//使能BANK1，区域4	
}





/**********************************
 * 函数名：LCD_Rst
 * 描述  ：LCD 软件复位
 * 输入  : 无 
 * 输出  ：无
 * 举例  ：无
 * 注意  ：无
*************************************/
void LCD_Rst(void)
{			
	GPIO_ResetBits(GPIOE, GPIO_Pin_1);	 //低电平复位
    Delay_us(10000); 					   
    GPIO_SetBits(GPIOE, GPIO_Pin_1 );		 	 
    Delay_us(12000); 	
}







/**********************************
 * 函数名：LCD_RD_data
 * 描述  ：读 ILI9341 RAM 数据
 * 输入  : 无 
 * 输出  ：读取的数据,16bit *
 * 举例  ：无
 * 注意  ：无
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
 * 函数名：Set_direction
 * 描述  ：设置ILI9341GRAM指针扫描方向
 * 输入  : 0： 横向扫描
 		   1： 纵向扫描
 * 输出  ：无
 * 举例  ：无
 * 注意  ：无
*************************************/
void Set_direction(u8 option)
{

    switch(option)
    {
    case 0:
	{	    /*横屏*/
        LCD_ILI9341_CMD(0x36); 
		LCD_ILI9341_Parameter(0x68);    //横屏
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
        {		/*竖屏*/
        LCD_ILI9341_CMD(0x36); 
	    LCD_ILI9341_Parameter(0x48);	//竖屏 
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
* 名    称：u16 GetPoint(u16 x,u16 y)
* 功    能：获取指定座标的颜色值
* 入口参数：x      行座标
*           y      列座标
* 出口参数：当前座标颜色值
* 说    明：
* 调用方法：i=GetPoint(10,10);
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
 * 函数名：LCD_open_windows
 * 描述  ：开窗(以x,y为坐标起点，长为len,高为wid)
 * 输入  : -x    窗户起点
           -y	   窗户起点
           -len  窗户长 
           -wid 窗户宽
 * 输出  ：无
 * 举例  ：无
 * 注意  ：无
*************************************/
void LCD_open_windows(u16 x,u16 y,u16 len,u16 wid)
{                    

    if(display_direction == 0)		/*如果是横屏选项*/
    {

		LCD_ILI9341_CMD(0X2A); 
		LCD_ILI9341_Parameter(x>>8);	//start 起始位置的高8位
		LCD_ILI9341_Parameter(x-((x>>8)<<8));  //起始位置的低8位
		LCD_ILI9341_Parameter((x+len-1)>>8);	//end 结束位置的高8位
		LCD_ILI9341_Parameter((x+len-1)-(((x+len-1)>>8)<<8));  //结束位置的低8位
		
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
         LCD_WR_REG(0x2C);//开始写数据到GRAM
}




/**********************************
 * 函数名：Lcd_init_conf
 * 描述  ：ILI9341 LCD寄存器初始配置
 * 输入  : 无
 * 输出  ：无
 * 举例  ：无
 * 注意  ：无
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
	LCD_ILI9341_Parameter(0x68);    /*横屏  左上角到(起点)到右下角(终点)扫描方式*/
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
    
	Set_direction(0);	  //传入0-->初始化默认为横屏方式
	LCD_ILI9341_CMD(0x2c); 
}
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
