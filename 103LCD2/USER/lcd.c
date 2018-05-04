/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��main.c
 * ����    ��LCD FSMC Ӧ�ú����⡣
 *           ʵ�ֵĹ��ܣ����������㡢���ߡ���ʾ���֡��ַ�����ͼƬ������         
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��www.ourdev.cn/bbs/bbs_list.jsp?bbs_id=1008
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/

#include "lcd.h"

#include "ascii.h"		
#include "asc_font.h"
#include <stdlib.h>



#define NO_CHNISEST_DISPLAY

u16 POINT_COLOR = BLACK;					      /*���Ĭ����ɫ*/
extern volatile u8 display_direction;		      /*0������ 1������*/



/*************************************API START*************************************************************/


/*****************************************
 * ��������LCD_Init1
 * ����  ��LCD ���� I/O ��ʼ��
 *         LCD FSMC ��ʼ��
 *         LCD ������ HX8347 ��ʼ�� 
 * ����  : ��
 * ���  ����
 * ����  ����
 * ע��  ����
******************************************/    
void LCD_Init1(void)
{
    unsigned long i; 

    LCD_GPIO_Config();	  	//��ʼ��ʹ�õ���GPIO
    LCD_FSMC_Config();		//��ʼ��FSMCģʽ
    LCD_Rst();				//��λLCDҺ����
	Lcd_init_conf();	    //д�������������Һ�������л����ĳ�ʼ������
    Lcd_data_start();   	//����дGRAM����
    for(i=0; i<(320*240); i++)		 		
    {
        LCD_WR_Data(WHITE); //������ɫ���ݣ�ʹ��Ļ��ʼ��ΪGBLUE��ɫ					    
    }
}


//************************************************************************************
//�������ƣ�  LCDClear()
//����������  clear lcd
//���������    
//���������  
//************************************************************************************

//void LCDClear(void)
//{
//	unsigned long i; 
//    for(i=0; i<(320*240); i++)		 		
//    {
//        LCD_WR_Data(GRED); //������ɫ���ݣ�ʹ��Ļ��ʼ��ΪGBLUE��ɫ					    
//    }
//}
void LCDClear(void)
{
	unsigned long i; 
    for(i=0; i<(320*240); i++)		 		
    {
        LCD_WR_Data(GRED); //������ɫ���ݣ�ʹ��Ļ��ʼ��ΪGBLUE��ɫ					    
    }
}







/******************************************************
 * ��������LCD_Rectangle
 * ����  ����ָ�����괦��ʾָ������ľ���
 * ����  : -x1      ���������� 0~319
           -y1      ���������� 0~239
		   -len     ���򳤶� 0~319
		   -wid     ������ 0~239
		   -rgb565  �����ɫ
 * ���  ����
 * ����  ��	LCD_Rectangle(10,10,120,160,0);
		    LCD_Rectangle(200,200,120,40,0);
 * ע��  ��	�Ѳ���
*********************************************************/    
void LCD_Rectangle(u16 x,u16 y,u16 len,u16 wid,u16 rgb565)
{                    
   u32 n, temp;
	 Set_direction(0);	 						/*�趨����Ϊ����*/
   LCD_open_windows(x,y,len,wid);   
   temp = (u32)len*wid;    
   for(n=0; n<temp; n++)
	 {
        LCD_WR_Data( rgb565 );
	 }
	 
	  
}


/******************************************************
 * ��������LCD_Point
 * ����  ����ָ�����괦��ʾһ����
 * ����  : -x ������ʾλ�� 0~319
           -y ������ʾλ�� 0~239
 * ���  ����
 * ����  ��	LCD_Point(100,200);
		   	LCD_Point(10,200);
		   	LCD_Point(300,220);
 * ע��  ��	(0,0)λ��ΪҺ�������Ͻ� �Ѳ���
*********************************************************/    
void LCD_Point(u16 x,u16 y)
{
    LCD_open_windows(x,y,1,1);   
    LCD_WR_Data(POINT_COLOR);	
} 


/******************************************************
 * ��������LCD_ColorPoint
 * ����  ����ָ�����괦��ʾһ��ָ����ɫ�ĵ�
 * ����  : -x      ������ʾλ�� 0~319
           -y      ������ʾλ�� 0~239
					 -rgb565 ָ����ɫ
 * ���  ����
 * ����  ��	LCD_ColorPoint(100,200,0);
		   	LCD_ColorPoint(10,200,100);
		   	LCD_ColorPoint(300,220,1000);
 * ע��  ��	(0,0)λ��ΪҺ�������Ͻ� �Ѳ���
*********************************************************/    
void LCD_ColorPoint(u16 x,u16 y, u16 rgb565)
{

      LCD_open_windows(x,y,1,1); 
      LCD_WR_Data(rgb565);	
} 


/******************************************************
 * ��������LCD_Line
 * ����  ����ָ������֮�仭ֱ��
 * ����  : -x1  ������� 0~319
           -y1  ������� 0~239
		   -x2  �����յ� 0~319
		   -y2  �����յ� 0~239 
 * ���  ����
 * ����  ��	LCD_Line(10,10, 319, 239);
			LCD_Line(10,10, 100, 150);
			LCD_Line(100, 150,10,10 );
 * ע��  ��	�Ѳ���
 *********************************************************/    
void LCD_Line(u16 x1, u16 y1, u16 x2, u16 y2)
{
    u16 x, y, t;

		Set_direction(0);
    if( (x1 == x2) && (y1 == y2) )
        LCD_Point(x1, y1);
    else if( abs(y2 - y1) > abs(x2 - x1) )			/*б�ʴ���1*/ 
    {
				if(y1 > y2) 
        {
            t = y1;
            y1 = y2;
            y2 = t; 
            t = x1;
            x1 = x2;
            x2 = t; 
        }
        for(y=y1; y<y2; y++)						/*��y��Ϊ��׼*/ 
        {
            x = (u32)(y-y1)*(x2-x1) / (y2-y1) + x1;
            LCD_Point(x, y);

        }
    }
    else     										/*б��С�ڵ���1*/ 
    {
        if(x1 > x2)
        {
            t = y1;
            y1 = y2;
            y2 = t;
            t = x1;
            x1 = x2;
            x2 = t;
        }   
        for(x=x1; x<x2; x++)									/*��x��Ϊ��׼*/ 
        {
            y = (u32)(x-x1)*(y2-y1) / (x2-x1) + y1;
            LCD_Point(x, y);

        }
    } 
}





/******************************************************
 * ��������LCD_Char_6x12_O
 * ����  ����ָ��λ��������ʾָ���ַ�
 * ����  : 	-x
           	-y 
      		-acsii Ҫд����ַ� 
      		-Color �ַ���ɫ
 * ���  ����
 * ����  ����
 * ע��  ������ �ڲ�����
 *********************************************************/    
void LCD_Char_6x12_O(u16 x, u16 y, u8 acsii, u16 Color)	
{       
#define MAX_CHAR_POSX (320-6)
#define MAX_CHAR_POSY (240-12)
    u8 temp, t, pos;  
 
     if(x > MAX_CHAR_POSX || y > MAX_CHAR_POSY)
     {
			 return;
		 }

    LCD_open_windows(x,y,6,12);
   
    acsii = acsii - ' ';											 /*�õ�ƫ�ƺ��ֵ*/
    for(pos=0; pos<12; pos++)
    {
        temp = asc2_1206[acsii][pos];
        for(t=0; t<6; t++)											/* ��λ��ʼ,��������λ*/
        {                 
            if(temp & 0x01)
			 {
                if(t==0)
				{
					LCD_open_windows(x,y+pos,6,12-pos);
					LCD_WR_Data(Color);
				}
				else
				{
					LCD_WR_Data(Color);	
				}
			 }
            else 	
            {
        		if(t==5)											/*�����ĩβ��--����ʣ�´���*/
				{
						LCD_open_windows(x,y+pos+1,6,12-pos-1);	 	
				}
				else
				{
						LCD_open_windows(x+t+1,y+pos,6-t,1);  		/*ǰ��һλ ����һ����*/	
				}				
            }   
            temp >>= 1; 
        }
    }
    
#undef MAX_CHAR_POSX
#undef MAX_CHAR_POSY   
}





/******************************************************
 * ��������LCD_Char_6x12_O_P
 * ����  ����ָ��λ��������ʾָ���ַ�
 * ����  : 	-x
           	-y 
      		-acsii Ҫд����ַ�
      		-Color �ַ���ɫ 			 
 * ���  ����
 * ����  ����
 * ע��  ������ �ڲ�����
 *********************************************************/    
void LCD_Char_6x12_O_P(u16 x, u16 y, u8 acsii,u16 Color)	//����
{       
#define MAX_CHAR_POSX (320-12)
#define MAX_CHAR_POSY (240-6) 
    u8 temp, t, pos;     
    if(x > MAX_CHAR_POSX || y > MAX_CHAR_POSY)
        return;
    
    LCD_open_windows(x,y,12,6);
    acsii = acsii - ' ';									//�õ�ƫ�ƺ��ֵ
    for(pos=0; pos<12; pos++)
    {

        if(display_direction==0)
            temp = asc2_1206[acsii][pos];
        else
            temp = asc2_1206[acsii][12-pos];

        for(t=0; t<6; t++)														// ��λ��ʼ,��������λ
        {                 
            if(temp & 0x01)
			{
                if(t==0)
				{
					 LCD_open_windows(x+pos,y,12-pos,6);
					 LCD_WR_Data(Color);
				}
				else
				{
					LCD_WR_Data(Color);
				}
            }
			else 	
            {
                 if(t==5)														/*�����ĩβ��--��ֱ�ӿ�����һ������*/
				{
					LCD_open_windows(x+pos+1,y,12-pos-1,6);	 	
				}
				else
				{
					LCD_open_windows(x+pos,y+t+1,1,6-t);					/*ǰ��һλ ����һ����*/	
				}
		
            }   
            temp >>= 1; 
        }
    }
    
#undef MAX_CHAR_POSX
#undef MAX_CHAR_POSY    
}





/******************************************************
 * ��������LCD_Char_O
 * ����  ����ָ��λ��������ʾָ���ַ�
 * ����  : 	-x
 *          -y 
 *     		-acsii Ҫд����ַ�
 *     		-Color �ַ���ɫ  
 * ���  ����
 * ����  ����
 * ע��  ������ �ڲ�����
*********************************************************/  
void LCD_Char_O(u16 x, u16 y, u8 acsii,u16 Color)
{       
#define MAX_CHAR_POSX (320-8)
#define MAX_CHAR_POSY (240-16)
    u8 temp, t, pos;     
    if(x > MAX_CHAR_POSX || y > MAX_CHAR_POSY)
        return;
       
    LCD_open_windows(x,y,8,16); 
    
    for (pos=0;pos<16;pos++)
    {
        temp=ascii_8x16[((acsii-0x20)*16)+pos];
        
        for(t=0; t<8; t++)
        {
            
            if(temp & 0x80)
            {
			   if(t==0)									   /*�����һ�����--�����¿���һ������*/
				{
					LCD_open_windows(x,y+pos,8,16-pos);
					LCD_WR_Data(Color);
				}
				else
				{
					LCD_WR_Data(Color);	
				}
            }
			else 	
            {
				if(t==7)									/*�����ĩβ��--��ֱ�ӿ�����һ������*/
				{
						LCD_open_windows(x,y+pos+1,8,16-pos-1);	 	
				}
				else
				{
						LCD_open_windows(x+t+1,y+pos,8-t,1);/*ǰ��һλ ����һ����*/	
				}

            } 
            
            temp <<= 1;	
            
        }        
    }
#undef MAX_CHAR_POSX
#undef MAX_CHAR_POSY   
}




/******************************************************
 * ��������LCD_Char_O_P
 * ����  ����ָ��λ��������ʾָ���ַ�
 * ����  : 	-x
 *          -y 
 *     		-acsii Ҫд����ַ� 
 *     		-Color �ַ���ɫ 
 * ���  ����
 * ����  ����
 * ע��  ������ 
*********************************************************/  
void LCD_Char_O_P(u16 x, u16 y, u8 acsii,u16 Color) 
{       
#define MAX_CHAR_POSX (320-16)
#define MAX_CHAR_POSY (240-8)
    u8 temp, t, pos;       
    if(x > MAX_CHAR_POSX || y > MAX_CHAR_POSY)
        return;
      
    LCD_open_windows(x,y,16,8);    
    
    for (pos=0;pos<16;pos++)
    {
        temp=ascii_8x16[((acsii-0x20)*16)+16-pos];
        
        for(t=0; t<8; t++)
        {
            
            if(temp & 0x80)
			{
				if(t==0)
				{
					LCD_open_windows(x+pos,y,16-pos,8);
					LCD_WR_Data(Color);
				}
				else
				{
                	LCD_WR_Data(Color);
				}
            }
			else 	
            {
                if(t==7)									/*�����ĩβ��--��ֱ�ӿ�����һ������*/
				{
						LCD_open_windows(x+pos+1,y,16-pos-1,8);	 	
				}
				else
				{
						LCD_open_windows(x+pos,y+t+1,1,8-t);/*ǰ��һλ ����һ����*/	
				}
            } 
            
            temp <<= 1;	
            
        }
        
        
    }
#undef MAX_CHAR_POSX
#undef MAX_CHAR_POSY     
}







/****************************************************************
 * ��������LCD_Str_O
 * ����  ����ָ�����괦������ʾ8*16��С���ַ���
 * ����  : -x   ��ʾλ�ú������� 0 ~ 319
           -y   ��ʾλ���������� 0 ~ 239
 * 		   -str �ַ�����ַ
 * 		   -Color�ַ���ɫ
 * ���  ����
 * ����  ��	LCD_Str_O(0, 0, "Runing", 0);
		    LCD_Str_O(320-8*6, 239-16, "Runing",0); 
 * ע��  ��	�ַ�����ʾ����Ϊ���� �Ѳ���					
******************************************************************/    
void LCD_Str_O(u16 x, u16 y,const u8 *str,u16 Color)
{

   	Set_direction(0);     
    while(*str != '\0')
    {       
        if(x > (320-8)) 
        {	
					//����
           x = 0;
           y += 16;
        }
        if(y > (240-16)) 
        {	
					//һ��
           x = y = 0;
        }
        
        LCD_Char_O(x ,y, *str,Color);
        x += 8;
        str ++ ;
    }
		
}






/************************************************************
 * ��������LCD_Char
 * ����  ����Һ������(x,y)��,��ʾһ��16*8��С���ַ�
 * ����  : 	-x 0~(239-6)
 *         	-y 0~(319-12)
 *      	-acsii    Ҫд����ַ�
 *			-Color    �ַ���ɫ
 *			-bkColor  ������ɫ
 * ���  ����
 * ����  ����
 * ע��  ���ַ�����ʾ����Ϊ�� �Ѳ���
******************************************************************/    
void LCD_Char(u16 x, u16 y,const u8 ascii, u16 Color, u16 bkColor)
{       
#define MAX_CHAR_POSX (320-8)
#define MAX_CHAR_POSY (240-16)
    u8 temp, t, pos;     
    if(x > MAX_CHAR_POSX || y > MAX_CHAR_POSY)
        return;
       
    LCD_open_windows(x,y,8,16); 
    
    for (pos=0;pos<16;pos++)
    {
        temp=ascii_8x16[((ascii-0x20)*16)+pos];
        
        for(t=0; t<8; t++)
        {
            
            if(temp & 0x80)              
						{
							LCD_WR_Data(Color);
						}
            else 	
            {
              LCD_WR_Data(bkColor);  
            }            
            temp <<= 1;	
            
        }
        
        
    }
#undef MAX_CHAR_POSX
#undef MAX_CHAR_POSY   
}





/************************************************************
 * ��������LCD_Str_R
 * ����  ����Һ������(x,y)��,��ʾһ��16*8��С���ַ���,�Ҷ���
 * ����  : -x 0~(239-6)
 *         -y 0~(319-12)
 *         -str �ַ�����ַ
 		   -len �ַ�������
		   -strColor �ַ���ɫ
		   -bkColor  ������ɫ
 * ���  ����
 * ����  ��LCD_Str_R(304,59,��12345��,14,0x0000,0xffff)
 * ע��  ���ַ�����ʾ����Ϊ�� �Ѳ���
******************************************************************/    
void LCD_Str_R(u16 x,u16 y,const u8 *str,u8 len,u16 Color,u16 bkColor)    //�Ҷ��룬����35λ������ʾ���35λ
{
  u16 i=1,strlen=0;	
	Set_direction(0);
  while(str[strlen])strlen++; 
  while(str[strlen-i])
  {
    LCD_Char((x-8*i),y,str[strlen-i],Color,bkColor); 
    i++;
    if(i>=len || i>strlen)return;
  }  
}


/************************************************************
 * ��������LCD_Str_O_P
 * ����  ����ָ�����괦������ʾ8*16��С���ַ���
 * ����  : -x   ��ʾλ�ú������� 0 ~ 319
           -y   ��ʾλ���������� 0 ~ 239
 * 		   -str �ַ�����ַ
 * 		   -Color�ַ�����ɫ
 * ���  ����
 * ����  ��	LCD_Str_O_P(0, 0, "Runing", 0);
		    LCD_Str_O_P(150, 100, "Runing", 0);
           	LCD_Str_O_P(320-16, 239-8*6, "Runing", 0);
 * ע��  ���ַ�����ʾ����Ϊ���� �Ѳ���
******************************************************************/    
void LCD_Str_O_P(u16 x, u16 y,const u8 *str,u16 Color)	
{
	Set_direction(1);
    while(*str != '\0')
    {
        if(y > (240-8)) 
        {	/* ����*/
            y = 0;
            x -= 16;
        }
			  if(x >(320-16)) 
        {	/*�ع����*/
            y = x = 0;
        }        
				LCD_Char_O_P(x,y,*str,Color);		
        str ++ ;
        y += 8 ;
    }
   
}





 
/******************************************************
 * ��������LCD_Num_6x12_O
 * ����  ����ָ�����괦������ʾ6*12��С������
 * ����  : -x   ��ʾλ�ú������� 0 ~ 319
           -y   ��ʾλ���������� 0 ~ 239
		   -num  ��Ҫ��ʾ������
		   -Color ������ɫ
 * ���  ����
 * ����  ��	LCD_Num_6x12_O(200, 100, 65535, BLACK);
		    LCD_Num_6x12_O(320-5*6, 240-12, 65535, BLACK);
			LCD_Num_6x12_O(0, 0, 65535, BLACK); 
 * ע��  ��	��ʾ����Ϊ���� �Ѳ���
*********************************************************/    
void LCD_Num_6x12_O(u16 x,u16 y,u32 num, u16 Color)	  
{      
    u32 res=num;   	   
    u8 t=0;

		Set_direction(0);  
	  if( num == 0 )
		{
	        LCD_Char_6x12_O(x, y, '0',Color);
					return;
		}	
	   while( res )  /*�õ����ֳ���t*/
    {
        res/=10;
        t++;
    }

		while(num)
		{
			 LCD_Char_6x12_O(x+(6*(t--)-6), y, (num%10)+'0',Color);/*����ʾ��λ����ʾ��λ*/
			 num /= 10 ;
		}			     
} 



/******************************************************
 * ��������LCD_Str_6x12_O
 * ����  ����ָ�����괦������ʾ6*12��С���ַ���
 * ����  : 	-x   ��ʾλ�ú������� 0 ~ 319
           	-y   ��ʾλ���������� 0 ~ 239
 * 			-str �ַ�����ַ
 * 			-Color�ַ�����ɫ
 * ���  ����
 * ����  �� LCD_Str_6x12_O(300, 10,"LOVE STM32", BLACK);
		    LCD_Str_6x12_O(0, 0,"LOVE STM32", BLACK);
			LCD_Str_6x12_O(320-6*9, 10,"LOVE STM3", BLACK);
		    LCD_Str_6x12_O(320-6*10, 240-12,"LOVE STM32", BLACK);  
 * ע��  ��	�ַ�����ʾ����Ϊ���� �Ѳ���
*********************************************************/    
void LCD_Str_6x12_O(u16 x, u16 y, const u8 *str,u16 Color)	
{    
    
		Set_direction(0);     
    while(*str != '\0')
    {       
        if(x > (320-6)) 
        {	
					//����
           x = 0;
           y += 12;
        }
        if(y > (240-12)) 
        {	
					//һ��
           x = y = 0;
        }
        
        LCD_Char_6x12_O(x ,y, *str,Color);
        x += 6;
        str ++ ;
    }
				  
}





/******************************************************
 * ��������LCD_Str_6x12_O_P
 * ����  ����ָ�����괦������ʾ6*12��С���ַ���
 * ����  : -x   ��ʾλ�ú������� 0 ~ 319
           -y   ��ʾλ���������� 0 ~ 239
 * 		   -str �ַ�����ַ
 *         -Color�ַ���ɫ
 * ���  ����
 * ����  ��	LCD_Str_6x12_O_P(200, 0,"LOVE STM32", 0);
		   	LCD_Str_6x12_O_P(0, 0,"LOVE STM32", 0);
		    LCD_Str_6x12_O_P(320-12, 239-6*10,"LOVE STM32", 0);
 * ע��  ��	�ַ�����ʾ����Ϊ���� �Ѳ���
*********************************************************/    
void LCD_Str_6x12_O_P(u16 x, u16 y, const u8 *str, u16 Color)	
{   
		
	  Set_direction(1);      
    while(*str != '\0')
    {       
        if(y > (240-6)) 
        {	/* ����*/
            y = 0;
            x -= 12;
        }
        if(x >(320-12)) 
        {	/*�ع����*/
            y = x = 0;
        }        
        LCD_Char_6x12_O_P(x, y , *str,Color);
        y +=6;
        str ++ ;
    }
		  
}





/********************************************************************
 * ��������LCD_Char_CH
 * ����  ����ʾ���������ַ�
 * ����  : 	x: 0~(319-16)
 *         	y: 0~(239-16)
 *			str: �����ַ�����ַ
 *			Color: �ַ���ɫ   
 *			bkColor: ������ɫ
 * ���  ����
 * ����  ��	LCD_Char_CH(200,100,"��",0,0);
 * ע��	 ��1 ����������1�ĺ����ַ�������ʾ����ضϣ�ֻ��ʾ��ǰ��һ������
           2 �����ֿ��sd����ȡ���뿴"tip.txt"  
************************************************************************/    
void LCD_Char_CH(u16 x,u16 y,const u8 *str,u16 Color,u16 bkColor)
{
    
#ifndef NO_CHNISEST_DISPLAY         /*���������ʾ����û�йر�*/
    u8 i,j;
    u8 buffer[32];
    u16 tmp_char=0;
    
    
    GetGBKCode_from_sd(buffer,str);  /* ȡ��ģ���� */
    for (i=0;i<16;i++)
    {
        tmp_char=buffer[i*2];
        tmp_char=(tmp_char<<8);
        tmp_char|=buffer[2*i+1];
        for (j=0;j<16;j++)
        {
            if ( (tmp_char >> 15-j) & 0x01 == 0x01)
            {
                LCD_ColorPoint(x+j,y+i,Color);
            }
            else
            {
                LCD_ColorPoint(x+j,y+i,bkColor);
            }
        }
    }
    
#endif
}



/******************************************************************
 * ��������LCD_Char_CH_P
 * ����  ����ʾ���������ַ�
 * ����  : x: 0~(319-16)
 *         y: 0~(239-16)
 *		   str: �����ַ�����ַ
 *		   Color: �ַ���ɫ   
 *		   bkColor: ������ɫ
 * ���  ����
 * ����  ��	LCD_Char_CH_P(200,100,"��",0,0);
 * ע��	 ��1 ����������1�ĺ����ַ�������ʾ����ضϣ�ֻ��ʾ��ǰ��һ������
           2 �����ֿ��sd����ȡ���뿴"tip.txt"  
***********************************************************************/    
void LCD_Char_CH_P(u16 x,u16 y,const u8 *str,u16 Color,u16 bkColor)
{
    
#ifndef NO_CHNISEST_DISPLAY         /*���������ʾ����û�йر�*/
    
    u8 i,j;
    u8 buffer[32];
    u16 tmp_char=0;
    
    Set_direction(1);
   	GetGBKCode_from_sd(buffer,str);	 /* ȡ��ģ���� */
    for (i=0;i<16;i++)
    {
        tmp_char=buffer[i*2];
        tmp_char=(tmp_char<<8);
        tmp_char|=buffer[2*i+1];
        for (j=0;j<16;j++)
        {
            if ( (tmp_char >> 15-j) & 0x01 == 0x01)
            {
                LCD_ColorPoint(x+16-i,y+j,Color);
            }
            else
            {
                LCD_ColorPoint(x+16-i,y+j,bkColor);
            }
        }
    }	 

#endif
}


/********************************************************************************
 * ��������	LCD_Char_CH_O
 * ����  �� ������ʾ���������ַ�
 * ����  : 	x: 0~(319-16)
 *         	y: 0~(239-16)
 *			str: �����ַ�����ַ
 *			Color: �ַ���ɫ   
 * ���  ����
 * ����  ��	LCD_Char_CH_O(200,100,"��",0,0);
 * ע��	 ��1 ����2 ����������1�ĺ����ַ�������ʾ����ضϣ�ֻ��ʾ��ǰ��һ������
           3 �����ֿ��sd����ȡ���뿴"tip.txt"  
 ********************************************************************************/    
void LCD_Char_CH_O(u16 x,u16 y,const u8 *str,u16 Color) 
{
#ifndef NO_CHNISEST_DISPLAY   
    u8 i,j;
    u8 buffer[32];
    u16 tmp_char=0;
    Set_direction(0);   
    GetGBKCode_from_sd(buffer,str); /* ȡ��ģ���� */
    
    for (i=0;i<16;i++)
    {
        tmp_char=buffer[i*2];
				tmp_char=(tmp_char<<8);
				tmp_char|=buffer[2*i+1];
        for (j=0;j<16;j++)
        {            
            if ( (tmp_char >> 15-j) & 0x01 == 0x01)
            {
                LCD_ColorPoint(x+j,y+i,Color);
            }
        }
    }   
#endif
}



/******************************************************************************
 * ��������LCD_Char_CH_O_P
 * ����  ����Lcd��������λ��������ʾһ��������
 * ����  : 	- x: ˮƽ���� 
 *         	- y: ��ֱ����  
 *			- str: ��ʾ��������
 *			- Color: �ַ���ɫ   
 * ���  ����
 * ����  ��	LCD_Char_CH_O_P(200,100,"��",0); 		
 * ע��  ��	1 ����2 ����������1�ĺ����ַ�������ʾ����ضϣ�ֻ��ʾ��ǰ��һ������
*********************************************************************************/    
void LCD_Char_CH_O_P(u16 x,u16 y,const u8 *str,u16 Color) 
{
    
#ifndef NO_CHNISEST_DISPLAY                           /*���������ʾ����û�йر�*/
    
    u8 i,j;
    u8 buffer[32];
    u16 tmp_char=0;
    Set_direction(1);
    GetGBKCode_from_sd(buffer,str);  									/* ȡ��ģ���� */
   
    for (i=0;i<16;i++)
    {
        tmp_char=buffer[i*2];
        tmp_char=(tmp_char<<8);
        tmp_char|=buffer[2*i+1];
        for (j=0;j<16;j++)
        {            
            if ( (tmp_char >> 15-j) & 0x01 == 0x01)
            {
                LCD_ColorPoint(x+16-i,y+j,Color);
            }
        }
    }
        
            
#endif
}





/***************************************************************************
 * ��������LCD_Str_CH
 * ����  ����ָ�����괦��ʾ16*16��С��ָ����ɫ�����ַ���
 * ����  : 	- x: ��ʾλ�ú�������	 
 *         	- y: ��ʾλ���������� 
 *			- str: ��ʾ�������ַ���
 *			- Color: �ַ���ɫ   
 *			- bkColor: ������ɫ
 * ���  ����
 * ����  ��	LCD_Str_CH(0,0,"��Ī��̳Ұ��ר��",0,0xffff);
		    LCD_Str_CH(50,100,"��Ī��̳Ұ��ר��",0,0xffff);
		    LCD_Str_CH(320-16*8,240-16,"��Ī��̳Ұ��ר��",0,0xffff); 		
 * ע��  ��	�ַ�����ʾ����Ϊ���� �����ֿ��sd����ȡ���뿴"tip.txt"  �Ѳ���
******************************************************************************/    
void LCD_Str_CH(u16 x,u16 y,const u8 *str,u16 Color,u16 bkColor)  
{
   
    Set_direction(0);
    while(*str != '\0')
    {
			if(x>(320-16))
			{	 
				 /*����*/
				x =0;
				y +=16;
					
			}
			if(y >(240-16))
			{
				 /*���¹���*/
				 y =0;
				 x =0;
			}
	     LCD_Char_CH(x,y,str,Color,bkColor);      
       str += 2 ;
       x += 16 ;	
    }
}





/********************************************************************************
 * ��������LCD_Str_CH_P
 * ����  ����ָ�����괦��ʾ16*16��С��ָ����ɫ�����ַ���
 * ����  : 	- x: ��ʾλ�ú�������	 
 *         	- y: ��ʾλ���������� 
 *			- str: ��ʾ�������ַ���
 *			- Color: �ַ���ɫ   
 *			- bkColor: ������ɫ
 * ���  ����
 * ����  ��	LCD_Str_CH_P(200,240-16*8,"��Ī��̳Ұ��ר����ӭ��",0xff,0xffff);
		    LCD_Str_CH_P(320-16,240-16*8,"��Ī��̳Ұ��ר��",0xff,0xffff);
		    LCD_Str_CH_P(0,0,"��Ī��̳Ұ��ר��",0xff,0xffff);		
 * ע��  ��	�ַ�����ʾ����Ϊ���� �����ֿ��sd����ȡ���뿴"tip.txt"  �Ѳ���
**********************************************************************************/    
void LCD_Str_CH_P(u16 x,u16 y,const u8 *str,u16 Color,u16 bkColor)	
{
        
    Set_direction(1);
    while(*str != '\0')
    {
        if(y >(240-16))
				{
						y = 0;
						x -= 16;
				}
				if(x >(320-16))
				{		
						y = 0;
						x = 0;
				}
				LCD_Char_CH_P(x,y,str,Color,bkColor);       
        str += 2 ;
        y += 16 ;	
    }
    
}


/*********************************************************************************
 * ��������LCD_Str_CH_O
 * ����  ����ָ�����괦������ʾ16*16��С��ָ����ɫ�����ַ���
 * ����  : 	- x:  ��ʾλ�ú�������	 
 *         	- y:  ��ʾλ���������� 
 *			- str:   ��ʾ�������ַ���
 *			- Color: �ַ���ɫ    
 * ���  ����
 * ����  ��	LCD_Str_CH_O(0,0,"��Ī��̳Ұ��ר��",0);
		   	LCD_Str_CH_O(320-16*5,100,"��Ī��̳Ұ��ר����ӭ��",0);
		    LCD_Str_CH_O(320-16*8,240-16,"��Ī��̳Ұ��ר��",0);		
 * ע��  ��	�ַ�����ʾ����Ϊ���� �����ֿ��sd����ȡ���뿴"tip.txt"  �Ѳ���
***************************************************************************************/    
void LCD_Str_CH_O(u16 x,u16 y,const u8 *str,u16 Color)	 
{
    	
	Set_direction(0);
    while(*str != '\0')
    {
			if(x>(320-16))
			{	 
				 /*����*/
				x =0;
				y +=16;
					
			}
			if(y >(240-16))
			{
				 /*���¹���*/
				 y =0;
				 x =0;
			}
	     LCD_Char_CH_O(x,y,str,Color);     
       str += 2 ;
       x += 16 ;	
    }
       
}



/**********************************************************************************
 * ��������LCD_Str_CH_O_P
 * ����  ����ָ�����괦������ʾ16*16��С��ָ����ɫ�����ַ���
 * ����  : - x: ��ʾλ�ú�������	 
 *         - y: ��ʾλ���������� 
 *		   - str: ��ʾ�������ַ���
 *		   - Color: �ַ���ɫ   
 * ���  ����
 * ����   	LCD_Str_CH_O_P(200,240-16*6,"��Ī��̳Ұ��ר��",0);
		    LCD_Str_CH_O_P(0,0,"��Ī��̳Ұ��ר��",0);
		    LCD_Str_CH_O_P(320-16,240-16*8,"��Ī��̳Ұ��ר��",0);
 * ע��  ��	�ַ�����ʾ����Ϊ���� �����ֿ��sd����ȡ���뿴"tip.txt"  �Ѳ���
**************************************************************************************/    
void LCD_Str_CH_O_P(u16 x,u16 y,const u8 *str,u16 Color) 
{    
    Set_direction(1);
    while(*str != '\0')
    {
				if(y > 240-16)
				{
					y = 0;
					x -=16;
				}
				if(x > 320-16)
				{
						y = 0;
						x = 0;
				}
        LCD_Char_CH_O_P(x,y,str,Color);        
        str += 2 ;
        y += 16 ;	
    } 
   
}





/**********************************************************************************
 * ��������LCD_Str_ENCH_O_P
 * ����  ����Ӣ�Ļ��������ʾ��Ӣ�Ĵ�СΪ16*8
 * ����  : 	- x: ��ʾλ�ú�������	 
 *         	- y: ��ʾλ���������� 
 *			- str: ��ʾ�������ַ���
 *			- Color: �ַ���ɫ   
 * ���  ����
 * ����    LCD_Str_ENCH_O_P(200,100,"Ұ��stm32��Īר��Ұ��stm32",0);
	       LCD_Str_ENCH_O_P(0,0,"Ұ��stm32��Īר��Ұ��stm32",0);
 * ע��  ��	�ַ�����ʾ����Ϊ���� �����ֿ��sd����ȡ���뿴"tip.txt"  �Ѳ���
**************************************************************************************/    
void LCD_Str_ENCH_O_P(u16 x,u16 y,const u8 *str,u16 Color)
{
    u16 Tmp_x, Tmp_y;
    Tmp_x = x;
    Tmp_y = y;
    Set_direction(1);
    while(*str != '\0')
    {
        if(*str<125)
				{
					if(Tmp_y >(240-8))
					{
						 /*����*/
						 Tmp_y =0;
						 Tmp_x -=16;
					}
					LCD_Char_O_P(Tmp_x,Tmp_y, *str,Color);
					str++ ;
					Tmp_y	+= 8;
				}
				else
				{
					if(*str==163)									/*163-172 �����Ķ���	 163-187�����ķֺ�*/
					{
						LCD_Char_O_P(Tmp_x,Tmp_y, ' ',Color);		/*��Ϊ��ʾ1���ո�*/
						str += 2 ;
						Tmp_x	+= 8 ;

					}
					if(Tmp_y >(240-16))
					{
						 /*����*/
						 Tmp_y =0;
						 Tmp_x -=16;
					}

					LCD_Char_CH_O_P(Tmp_x,Tmp_y,str,Color);
          str += 2 ;
        	Tmp_y += 16 ;						
        }
    }
}

/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/

