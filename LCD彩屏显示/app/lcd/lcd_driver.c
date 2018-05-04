#include "lcd_driver.h"

/****************************************************************************
* Function Name  : TFT_GPIO_Config
* Description    : ��ʼ��TFT������IO��
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void TFT_GPIO_Config(void)
{	
	/* ��ʱ��ʹ�� */
    RCC->APB2ENR |= 0x00000020 | 0x00000040 | 0x00000100;

    /* ����IOΪ����������� */
    GPIOG->CRL &= 0xFFFFFFF0;  //PG0
    GPIOG->CRL |= 0x0000000B;
    GPIOG->CRH &= 0xFFF0FFFF;  //PG12
    GPIOG->CRH |= 0x000B0000;

    GPIOD->CRL &= 0xFF00FF00;
    GPIOD->CRL |= 0x00BB00BB;
    GPIOD->CRH &= 0x00000000;
    GPIOD->CRH |= 0xBBBBBBBB;

    GPIOE->CRL &= 0x0FFFFFFF;
    GPIOE->CRL |= 0xB0000000;
    GPIOE->CRH &= 0x00000000;
    GPIOE->CRH |= 0xBBBBBBBB;

}

/****************************************************************************
* Function Name  : TFT_FSMC_Config
* Description    : ��ʼ��FSMC
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void TFT_FSMC_Config(void)
{
    /* ʹ��FSMC��ʱ�� */
    RCC->AHBENR |= 1 << 8;     	 	//ʹ��FSMCʱ��
    
	/* bank1��NE1~4,ÿһ����һ��BCR+TCR�������ܹ��˸��Ĵ�����*/
	/* ��������ʹ��NE4 ��Ҳ�Ͷ�ӦBTCR[6],[7]�� */				    
	FSMC_Bank1->BTCR[6] = 0x00000000;
	FSMC_Bank1->BTCR[7] = 0x00000000;
	FSMC_Bank1E->BWTR[6] = 0x00000000;
	/* ����BCR�Ĵ���	ʹ���첽ģʽ */
	FSMC_Bank1->BTCR[6] |= 1 << 12;		//�洢��дʹ��
	FSMC_Bank1->BTCR[6] |= 1 << 14;		//��дʹ�ò�ͬ��ʱ��
	FSMC_Bank1->BTCR[6] |= 1 << 4; 		//�洢�����ݿ��Ϊ16bit 	    
	/* ����BTR�Ĵ��� */	
	/* ��ʱ����ƼĴ��� */							    
	FSMC_Bank1->BTCR[7] |= 0 << 28;		//ģʽA 	 							  	 
	FSMC_Bank1->BTCR[7] |= 1 << 0; 		//��ַ����ʱ�䣨ADDSET��Ϊ2��HCLK 1/36M=27ns	 	 
	/* ��ΪҺ������IC�Ķ����ݵ�ʱ���ٶȲ���̫�졣 */
	FSMC_Bank1->BTCR[7] |= 0x0F << 8;  	//���ݱ���ʱ��Ϊ16��HCLK	 	 
	/* дʱ����ƼĴ��� */ 
	FSMC_Bank1E->BWTR[6] |= 0 << 28; 	//ģʽA 	 							    
	FSMC_Bank1E->BWTR[6] |= 0 << 0;		//��ַ����ʱ�䣨ADDSET��Ϊ1��HCLK 
 	/* 4��HCLK��HCLK=72M����ΪҺ������IC��д�ź���������Ҳ��50ns��72M/4=24M=55ns */  	 
	FSMC_Bank1E->BWTR[6] |= 3 << 8; 	//���ݱ���ʱ��Ϊ4��HCLK	
	/* ʹ��BANK1,����4 */
	FSMC_Bank1->BTCR[6] |= 1 << 0;		//ʹ��BANK1������4	
}

/****************************************************************************
* Function Name  : TFT_WriteCmd
* Description    : LCDд������
* Input          : cmd��д���16λ����
* Output         : None
* Return         : None
****************************************************************************/

void TFT_WriteCmd(uint16_t cmd)
{
	TFT->TFT_CMD = cmd<<8 ;
}

/****************************************************************************
* Function Name  : TFT_WriteData
* Description    : LCDд������
* Input          : dat��д���16λ����
* Output         : None
* Return         : None
****************************************************************************/

void TFT_WriteData(u16 dat)
{
	TFT->TFT_DATA = dat<<8;
}

void TFT_WriteData_Color(u16 color)
{
	TFT->TFT_DATA = color&0xff00;
	TFT->TFT_DATA = color<<8;
}

/****************************************************************************
* Function Name  : TFT_Init
* Description    : ��ʼ��LCD��
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void TFT_Init(void)
{
	uint16_t i;

	TFT_GPIO_Config();
	TFT_FSMC_Config();

	//************* Start Initial Sequence **********//	
	TFT_WriteCmd(0xCB);  
	TFT_WriteData(0x39); 
	TFT_WriteData(0x2C); 
	TFT_WriteData(0x00); 
	TFT_WriteData(0x34);  
	TFT_WriteData(0x02);   

	TFT_WriteCmd(0xCF);  
	TFT_WriteData (0x00); 
	TFT_WriteData (0xa2); //c1
	TFT_WriteData (0Xf0);  //30
	 
	TFT_WriteCmd(0xE8);  
	TFT_WriteData (0x84); 	 //85
	TFT_WriteData (0x11); 	 //00
	TFT_WriteData (0x7a); 	 //79
	
	
	TFT_WriteCmd(0xEA);  
	TFT_WriteData (0x66);  //00
	TFT_WriteData (0x00); 
	
	TFT_WriteCmd(0xED);  
	TFT_WriteData (0x55); 	//64
	TFT_WriteData (0x01); 	//03
	TFT_WriteData (0X23); 	//12
	TFT_WriteData (0X01); 	//81
	 
	TFT_WriteCmd(0xF7);  
	TFT_WriteData (0x20); 	//20
	
	
	TFT_WriteCmd(0xC0);    //Power control 
	TFT_WriteData (0x1c);   //VRH[5:0] 	//1c
	 
	TFT_WriteCmd(0xC1);    //Power control 
	TFT_WriteData (0x13);   //SAP[2:0];BT[3:0] 	//13
	 
	TFT_WriteCmd(0xC5);    //VCM control 
	TFT_WriteData (0x23); 
	TFT_WriteData (0x3F); 
	 
	TFT_WriteCmd(0xC7);    //VCM control2 
	TFT_WriteData(0xA5); 
	
	TFT_WriteCmd(0xB1);  
	TFT_WriteData (0x00); 
	TFT_WriteData (0x17); 
	
	TFT_WriteCmd(0x3A);  
	TFT_WriteData (0x55); 
	
	TFT_WriteCmd(0xB6);  
	TFT_WriteData (0x0A);
	TFT_WriteData (0xa2);  //a2
	TFT_WriteData (0x27);
	TFT_WriteData (0x00); 
	 
	TFT_WriteCmd(0x36);    // Memory Access Control 
	TFT_WriteData (0x08); 	  //08	BGR
	 
	TFT_WriteCmd(0xF2);    // 3Gamma Function Disable 
	TFT_WriteData (0x02); 	//00
	 
	TFT_WriteCmd(0x26);    //Gamma curve selected 
	TFT_WriteData (0x01); 
	 
	TFT_WriteCmd(0xE0);    //Set Gamma 
	TFT_WriteData (0x0F); 
	TFT_WriteData (0x14); 
	TFT_WriteData (0x13); 
	TFT_WriteData (0x0C); 
	TFT_WriteData (0x0E); 
	TFT_WriteData (0x05); 
	TFT_WriteData (0x45); 
	TFT_WriteData (0x85); 
	TFT_WriteData (0x36); 
	TFT_WriteData (0x09); 
	TFT_WriteData (0x14); 
	TFT_WriteData (0x05); 
	TFT_WriteData (0x09); 
	TFT_WriteData (0x03); 
	TFT_WriteData (0x00); 
	 
	TFT_WriteCmd(0XE1);    //Set Gamma 
	TFT_WriteData (0x00); 
	TFT_WriteData (0x24); 
	TFT_WriteData (0x26); 
	TFT_WriteData (0x03); 
	TFT_WriteData (0x0F); 
	TFT_WriteData (0x04); 
	TFT_WriteData (0x3F); 
	TFT_WriteData (0x14); 
	TFT_WriteData (0x52); 
	TFT_WriteData (0x04); 
	TFT_WriteData (0x10); 
	TFT_WriteData (0x0E); 
	TFT_WriteData (0x38); 
	TFT_WriteData (0x39); 
	TFT_WriteData (0x0F); 

	TFT_WriteCmd(0x2A );
	TFT_WriteData(0x00);
	TFT_WriteData(0x00);
	TFT_WriteData(0x00);
	TFT_WriteData(0xEF);

	TFT_WriteCmd(0x2B );
	TFT_WriteData(0x00);
	TFT_WriteData(0x00);
	TFT_WriteData(0x01);
	TFT_WriteData(0x3F);
	 
	TFT_WriteCmd(0x11);    //Exit Sleep 
	for(i=50000; i>0; i--);	 //��ʱ
	for(i=50000; i>0; i--);
	for(i=50000; i>0; i--);
	for(i=50000; i>0; i--);
	for(i=50000; i>0; i--);
	for(i=50000; i>0; i--);
	TFT_WriteCmd(0x29);    //Display on
}

/****************************************************************************
* Function Name  : TFT_SetWindow
* Description    : ����Ҫ�����Ĵ��ڷ�Χ
* Input          : xStart��������ʼX����
*                * yStart��������ʼY����
*                * xEnd�����ڽ���X����
*                * yEnd�����ڽ���Y����
* Output         : None
* Return         : None
****************************************************************************/

void TFT_SetWindow(uint16_t xStart, uint16_t yStart, uint16_t xEnd, uint16_t yEnd)
{
 	TFT_WriteCmd(0x2A);

    TFT_WriteData(xStart/256);
    TFT_WriteData(xStart%256);
    TFT_WriteData(xEnd/256);
    TFT_WriteData(xEnd%256);

    TFT_WriteCmd(0x2b);
    TFT_WriteData(yStart/256);
    TFT_WriteData(yStart%256);
    TFT_WriteData(yEnd/256);
    TFT_WriteData(yEnd%256);
    TFT_WriteCmd(0x2c); 
}

/****************************************************************************
* Function Name  : TFT_ClearScreen
* Description    : ��LCD��������Ӧ����ɫ
* Input          : color��������ɫ
* Output         : None
* Return         : None
****************************************************************************/
	  
void TFT_ClearScreen(uint16_t color)
{
 	uint16_t i, j ;

	TFT_SetWindow(0, 0, TFT_XMAX, TFT_YMAX);	 //��������
  	for(i=0; i<TFT_XMAX+1; i++)
	{
		for (j=0; j<TFT_YMAX+1; j++)
		{
			TFT_WriteData_Color(color);
		}
	}
}
