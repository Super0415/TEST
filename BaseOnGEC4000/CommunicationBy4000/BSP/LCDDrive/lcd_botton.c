#include "lcd_botton.h"
#include "core_cm3.h"
#include "TYPCortex.h"

void Delay1us1(uint32_t us);

/*��������־λ  0��GRAMָ��ɨ�跽��Ϊ����ģʽ 1��GRAMָ��ɨ�跽��Ϊ����ģʽ*/
volatile u8 display_direction = 0;	 /*�ñ�־λ�����÷����û�ʶ��ǰ�����Ǵ�������ģʽ*/

#define LCD_ILI9341_CMD(index)           LCD_WR_REG(index)
#define LCD_ILI9341_Parameter(val)	 LCD_WR_Data(val)
#define Delay_us(time)                   Delay1us(time)    	/*��ʱ����*/	                 
#define DEBUG_DELAY()    //Delay_us(500) 	 /*������ʱ���������ʱ��ֱ��ע�͵�����*/



void XIOPVDIntHook(void)
{
  if(PWR_GetFlagStatus(PWR_FLAG_PVDO)!=RESET)
  {
    LCD_ILI9341_CMD(0x10);  
  }
  else
  {
    LCD_ILI9341_CMD(0x11);  
  
  }
  EXTI_ClearITPendingBit(EXTI_Line16); 
}

/*******************************************
 * ��������Delay1us
 * ����  ����ʱ����
 * ����  : �� 
 * ���  ����
 * ����  ����
 * ע��  ��ϵ��24Ϊ��ǰʱ���²��Խ��
*********************************************/  
void Delay1us(uint32_t us)
{
    int n = 24*us;
    for(; n != 0; n--);
}
/* ******************************************************************** */
/*                       XIO_SetState()                      */
/* ******************************************************************** */
void XIO_SetState(GPIO_TypeDef *pPt,INT08U ucBit,u8 usSet)
{    
    if (usSet    ==  0)
    {   pPt->BRR  = (INT32U)0x01 << ucBit;
    }   else
    {   pPt->BSRR = (INT32U)0x01 << ucBit;
    }       
}
/*******************************************
 * ��������LCD_GPIO_Config
 * ����  ������FSMC����LCD��I/O
 * ����  : �� 
 * ���  ����
 * ����  ����
 * ע��  ����
*********************************************/  
void LCD_GPIO_Config(void)
{
	  GPIO_InitTypeDef GPIO_InitStructure;
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE, ENABLE);	
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOE, &GPIO_InitStructure);	

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_4|GPIO_Pin_5   \
	                               |GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10  \
	                               |GPIO_Pin_11|GPIO_Pin_14|GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
		 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10     \
	                               |GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14  \
	                               |GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    GPIO_SetBits(GPIOD, GPIO_Pin_7);
		GPIO_SetBits(GPIOD, GPIO_Pin_0);
		GPIO_SetBits(GPIOD, GPIO_Pin_1);
    GPIO_SetBits(GPIOD, GPIO_Pin_14);
    GPIO_SetBits(GPIOD, GPIO_Pin_15);
    GPIO_SetBits(GPIOE, GPIO_Pin_7); 
    GPIO_SetBits(GPIOE, GPIO_Pin_8);
    GPIO_SetBits(GPIOE, GPIO_Pin_9); 
    GPIO_SetBits(GPIOE, GPIO_Pin_10);
		GPIO_ResetBits(GPIOE, GPIO_Pin_1);
    GPIO_SetBits(GPIOD, GPIO_Pin_4);
    GPIO_SetBits(GPIOD, GPIO_Pin_5);
    GPIO_SetBits(GPIOB, GPIO_Pin_13);  
    
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
    GPIO_ResetBits(GPIOE, GPIO_Pin_1);	
    Delay_us(10000); 		
    GPIO_SetBits(GPIOE, GPIO_Pin_1);	
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
    LCD_ILI9341_Parameter(0x68);   // ����  ���Ͻǵ�(���)�����½�(�յ�)ɨ�跽ʽ
    
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
