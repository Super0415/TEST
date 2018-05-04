/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * 文件名  ：main.c
 * 描述    ：LCD FSMC 应用函数库。
 *           实现的功能：清屏、画点、划线、显示数字、字符串、图片、汉字         
 * 实验平台：野火STM32开发板
 * 库版本  ：ST3.5.0
 *
 * 作者    ：wildfire team 
 * 论坛    ：www.ourdev.cn/bbs/bbs_list.jsp?bbs_id=1008
 * 淘宝    ：http://firestm32.taobao.com
**********************************************************************************/

#include "lcd.h"

#include "ascii.h"		
#include "asc_font.h"
#include <stdlib.h>



#define NO_CHNISEST_DISPLAY

u16 POINT_COLOR = BLACK;					      /*描点默认颜色*/
extern volatile u8 display_direction;		      /*0：横屏 1：竖屏*/



/*************************************API START*************************************************************/


/*****************************************
 * 函数名：LCD_Init1
 * 描述  ：LCD 控制 I/O 初始化
 *         LCD FSMC 初始化
 *         LCD 控制器 HX8347 初始化 
 * 输入  : 无
 * 输出  ：无
 * 举例  ：无
 * 注意  ：无
******************************************/    
void LCD_Init1(void)
{
    unsigned long i; 

    LCD_GPIO_Config();	  	//初始化使用到的GPIO
    LCD_FSMC_Config();		//初始化FSMC模式
    LCD_Rst();				//复位LCD液晶屏
	Lcd_init_conf();	    //写入命令参数，对液晶屏进行基本的初始化配置
    Lcd_data_start();   	//发送写GRAM命令
    for(i=0; i<(320*240); i++)		 		
    {
        LCD_WR_Data(WHITE); //发送颜色数据，使屏幕初始化为GBLUE颜色					    
    }
}


//************************************************************************************
//函数名称：  LCDClear()
//功能描述：  clear lcd
//输入参数：    
//输出参数：  
//************************************************************************************

//void LCDClear(void)
//{
//	unsigned long i; 
//    for(i=0; i<(320*240); i++)		 		
//    {
//        LCD_WR_Data(GRED); //发送颜色数据，使屏幕初始化为GBLUE颜色					    
//    }
//}
void LCDClear(void)
{
	unsigned long i; 
    for(i=0; i<(320*240); i++)		 		
    {
        LCD_WR_Data(GRED); //发送颜色数据，使屏幕初始化为GBLUE颜色					    
    }
}







/******************************************************
 * 函数名：LCD_Rectangle
 * 描述  ：在指定坐标处显示指定长宽的矩形
 * 输入  : -x1      横向矩形起点 0~319
           -y1      纵向矩形起点 0~239
		   -len     横向长度 0~319
		   -wid     纵向宽度 0~239
		   -rgb565  填充颜色
 * 输出  ：无
 * 举例  ：	LCD_Rectangle(10,10,120,160,0);
		    LCD_Rectangle(200,200,120,40,0);
 * 注意  ：	已测试
*********************************************************/    
void LCD_Rectangle(u16 x,u16 y,u16 len,u16 wid,u16 rgb565)
{                    
   u32 n, temp;
	 Set_direction(0);	 						/*设定方向为横向*/
   LCD_open_windows(x,y,len,wid);   
   temp = (u32)len*wid;    
   for(n=0; n<temp; n++)
	 {
        LCD_WR_Data( rgb565 );
	 }
	 
	  
}


/******************************************************
 * 函数名：LCD_Point
 * 描述  ：在指定坐标处显示一个点
 * 输入  : -x 横向显示位置 0~319
           -y 纵向显示位置 0~239
 * 输出  ：无
 * 举例  ：	LCD_Point(100,200);
		   	LCD_Point(10,200);
		   	LCD_Point(300,220);
 * 注意  ：	(0,0)位置为液晶屏左上角 已测试
*********************************************************/    
void LCD_Point(u16 x,u16 y)
{
    LCD_open_windows(x,y,1,1);   
    LCD_WR_Data(POINT_COLOR);	
} 


/******************************************************
 * 函数名：LCD_ColorPoint
 * 描述  ：在指定坐标处显示一个指定颜色的点
 * 输入  : -x      横向显示位置 0~319
           -y      纵向显示位置 0~239
					 -rgb565 指定颜色
 * 输出  ：无
 * 举例  ：	LCD_ColorPoint(100,200,0);
		   	LCD_ColorPoint(10,200,100);
		   	LCD_ColorPoint(300,220,1000);
 * 注意  ：	(0,0)位置为液晶屏左上角 已测试
*********************************************************/    
void LCD_ColorPoint(u16 x,u16 y, u16 rgb565)
{

      LCD_open_windows(x,y,1,1); 
      LCD_WR_Data(rgb565);	
} 


/******************************************************
 * 函数名：LCD_Line
 * 描述  ：在指定两点之间画直线
 * 输入  : -x1  横向起点 0~319
           -y1  纵向起点 0~239
		   -x2  横向终点 0~319
		   -y2  纵向终点 0~239 
 * 输出  ：无
 * 举例  ：	LCD_Line(10,10, 319, 239);
			LCD_Line(10,10, 100, 150);
			LCD_Line(100, 150,10,10 );
 * 注意  ：	已测试
 *********************************************************/    
void LCD_Line(u16 x1, u16 y1, u16 x2, u16 y2)
{
    u16 x, y, t;

		Set_direction(0);
    if( (x1 == x2) && (y1 == y2) )
        LCD_Point(x1, y1);
    else if( abs(y2 - y1) > abs(x2 - x1) )			/*斜率大于1*/ 
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
        for(y=y1; y<y2; y++)						/*以y轴为基准*/ 
        {
            x = (u32)(y-y1)*(x2-x1) / (y2-y1) + x1;
            LCD_Point(x, y);

        }
    }
    else     										/*斜率小于等于1*/ 
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
        for(x=x1; x<x2; x++)									/*以x轴为基准*/ 
        {
            y = (u32)(x-x1)*(y2-y1) / (x2-x1) + y1;
            LCD_Point(x, y);

        }
    } 
}





/******************************************************
 * 函数名：LCD_Char_6x12_O
 * 描述  ：在指定位置悬浮显示指定字符
 * 输入  : 	-x
           	-y 
      		-acsii 要写入的字符 
      		-Color 字符颜色
 * 输出  ：无
 * 举例  ：无
 * 注意  ：横屏 内部调用
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
   
    acsii = acsii - ' ';											 /*得到偏移后的值*/
    for(pos=0; pos<12; pos++)
    {
        temp = asc2_1206[acsii][pos];
        for(t=0; t<6; t++)											/* 低位开始,丢弃高两位*/
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
        		if(t==5)											/*如果是末尾点--开启剩下窗户*/
				{
						LCD_open_windows(x,y+pos+1,6,12-pos-1);	 	
				}
				else
				{
						LCD_open_windows(x+t+1,y+pos,6-t,1);  		/*前进一位 开启一行线*/	
				}				
            }   
            temp >>= 1; 
        }
    }
    
#undef MAX_CHAR_POSX
#undef MAX_CHAR_POSY   
}





/******************************************************
 * 函数名：LCD_Char_6x12_O_P
 * 描述  ：在指定位置悬浮显示指定字符
 * 输入  : 	-x
           	-y 
      		-acsii 要写入的字符
      		-Color 字符颜色 			 
 * 输出  ：无
 * 举例  ：无
 * 注意  ：竖屏 内部调用
 *********************************************************/    
void LCD_Char_6x12_O_P(u16 x, u16 y, u8 acsii,u16 Color)	//竖屏
{       
#define MAX_CHAR_POSX (320-12)
#define MAX_CHAR_POSY (240-6) 
    u8 temp, t, pos;     
    if(x > MAX_CHAR_POSX || y > MAX_CHAR_POSY)
        return;
    
    LCD_open_windows(x,y,12,6);
    acsii = acsii - ' ';									//得到偏移后的值
    for(pos=0; pos<12; pos++)
    {

        if(display_direction==0)
            temp = asc2_1206[acsii][pos];
        else
            temp = asc2_1206[acsii][12-pos];

        for(t=0; t<6; t++)														// 低位开始,丢弃高两位
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
                 if(t==5)														/*如果是末尾点--则直接开启下一个矩形*/
				{
					LCD_open_windows(x+pos+1,y,12-pos-1,6);	 	
				}
				else
				{
					LCD_open_windows(x+pos,y+t+1,1,6-t);					/*前进一位 开启一行线*/	
				}
		
            }   
            temp >>= 1; 
        }
    }
    
#undef MAX_CHAR_POSX
#undef MAX_CHAR_POSY    
}





/******************************************************
 * 函数名：LCD_Char_O
 * 描述  ：在指定位置悬浮显示指定字符
 * 输入  : 	-x
 *          -y 
 *     		-acsii 要写入的字符
 *     		-Color 字符颜色  
 * 输出  ：无
 * 举例  ：无
 * 注意  ：横屏 内部调用
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
			   if(t==0)									   /*如果是一行起点--则重新开启一个矩形*/
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
				if(t==7)									/*如果是末尾点--则直接开启下一个矩形*/
				{
						LCD_open_windows(x,y+pos+1,8,16-pos-1);	 	
				}
				else
				{
						LCD_open_windows(x+t+1,y+pos,8-t,1);/*前进一位 开启一行线*/	
				}

            } 
            
            temp <<= 1;	
            
        }        
    }
#undef MAX_CHAR_POSX
#undef MAX_CHAR_POSY   
}




/******************************************************
 * 函数名：LCD_Char_O_P
 * 描述  ：在指定位置悬浮显示指定字符
 * 输入  : 	-x
 *          -y 
 *     		-acsii 要写入的字符 
 *     		-Color 字符颜色 
 * 输出  ：无
 * 举例  ：无
 * 注意  ：竖屏 
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
                if(t==7)									/*如果是末尾点--则直接开启下一个矩形*/
				{
						LCD_open_windows(x+pos+1,y,16-pos-1,8);	 	
				}
				else
				{
						LCD_open_windows(x+pos,y+t+1,1,8-t);/*前进一位 开启一行线*/	
				}
            } 
            
            temp <<= 1;	
            
        }
        
        
    }
#undef MAX_CHAR_POSX
#undef MAX_CHAR_POSY     
}







/****************************************************************
 * 函数名：LCD_Str_O
 * 描述  ：在指定坐标处悬浮显示8*16大小的字符串
 * 输入  : -x   显示位置横向坐标 0 ~ 319
           -y   显示位置纵向坐标 0 ~ 239
 * 		   -str 字符串首址
 * 		   -Color字符颜色
 * 输出  ：无
 * 举例  ：	LCD_Str_O(0, 0, "Runing", 0);
		    LCD_Str_O(320-8*6, 239-16, "Runing",0); 
 * 注意  ：	字符串显示方向为横向 已测试					
******************************************************************/    
void LCD_Str_O(u16 x, u16 y,const u8 *str,u16 Color)
{

   	Set_direction(0);     
    while(*str != '\0')
    {       
        if(x > (320-8)) 
        {	
					//换行
           x = 0;
           y += 16;
        }
        if(y > (240-16)) 
        {	
					//一屏
           x = y = 0;
        }
        
        LCD_Char_O(x ,y, *str,Color);
        x += 8;
        str ++ ;
    }
		
}






/************************************************************
 * 函数名：LCD_Char
 * 描述  ：在液晶坐标(x,y)中,显示一个16*8大小的字符
 * 输入  : 	-x 0~(239-6)
 *         	-y 0~(319-12)
 *      	-acsii    要写入的字符
 *			-Color    字符颜色
 *			-bkColor  背景颜色
 * 输出  ：无
 * 举例  ：无
 * 注意  ：字符串显示方向为横 已测试
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
 * 函数名：LCD_Str_R
 * 描述  ：在液晶坐标(x,y)中,显示一个16*8大小的字符串,右对齐
 * 输入  : -x 0~(239-6)
 *         -y 0~(319-12)
 *         -str 字符串首址
 		   -len 字符串长度
		   -strColor 字符颜色
		   -bkColor  背景颜色
 * 输出  ：无
 * 举例  ：LCD_Str_R(304,59,“12345”,14,0x0000,0xffff)
 * 注意  ：字符串显示方向为横 已测试
******************************************************************/    
void LCD_Str_R(u16 x,u16 y,const u8 *str,u8 len,u16 Color,u16 bkColor)    //右对齐，超过35位，仅显示最后35位
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
 * 函数名：LCD_Str_O_P
 * 描述  ：在指定坐标处悬浮显示8*16大小的字符串
 * 输入  : -x   显示位置横向坐标 0 ~ 319
           -y   显示位置纵向坐标 0 ~ 239
 * 		   -str 字符串首址
 * 		   -Color字符串颜色
 * 输出  ：无
 * 举例  ：	LCD_Str_O_P(0, 0, "Runing", 0);
		    LCD_Str_O_P(150, 100, "Runing", 0);
           	LCD_Str_O_P(320-16, 239-8*6, "Runing", 0);
 * 注意  ：字符串显示方向为纵向 已测试
******************************************************************/    
void LCD_Str_O_P(u16 x, u16 y,const u8 *str,u16 Color)	
{
	Set_direction(1);
    while(*str != '\0')
    {
        if(y > (240-8)) 
        {	/* 换行*/
            y = 0;
            x -= 16;
        }
			  if(x >(320-16)) 
        {	/*重归起点*/
            y = x = 0;
        }        
				LCD_Char_O_P(x,y,*str,Color);		
        str ++ ;
        y += 8 ;
    }
   
}





 
/******************************************************
 * 函数名：LCD_Num_6x12_O
 * 描述  ：在指定坐标处悬浮显示6*12大小的数字
 * 输入  : -x   显示位置横向坐标 0 ~ 319
           -y   显示位置纵向坐标 0 ~ 239
		   -num  需要显示的数字
		   -Color 数字颜色
 * 输出  ：无
 * 举例  ：	LCD_Num_6x12_O(200, 100, 65535, BLACK);
		    LCD_Num_6x12_O(320-5*6, 240-12, 65535, BLACK);
			LCD_Num_6x12_O(0, 0, 65535, BLACK); 
 * 注意  ：	显示方向为横向 已测试
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
	   while( res )  /*得到数字长度t*/
    {
        res/=10;
        t++;
    }

		while(num)
		{
			 LCD_Char_6x12_O(x+(6*(t--)-6), y, (num%10)+'0',Color);/*先显示低位在显示高位*/
			 num /= 10 ;
		}			     
} 



/******************************************************
 * 函数名：LCD_Str_6x12_O
 * 描述  ：在指定坐标处悬浮显示6*12大小的字符串
 * 输入  : 	-x   显示位置横向坐标 0 ~ 319
           	-y   显示位置纵向坐标 0 ~ 239
 * 			-str 字符串首址
 * 			-Color字符串颜色
 * 输出  ：无
 * 举例  ： LCD_Str_6x12_O(300, 10,"LOVE STM32", BLACK);
		    LCD_Str_6x12_O(0, 0,"LOVE STM32", BLACK);
			LCD_Str_6x12_O(320-6*9, 10,"LOVE STM3", BLACK);
		    LCD_Str_6x12_O(320-6*10, 240-12,"LOVE STM32", BLACK);  
 * 注意  ：	字符串显示方向为横向 已测试
*********************************************************/    
void LCD_Str_6x12_O(u16 x, u16 y, const u8 *str,u16 Color)	
{    
    
		Set_direction(0);     
    while(*str != '\0')
    {       
        if(x > (320-6)) 
        {	
					//换行
           x = 0;
           y += 12;
        }
        if(y > (240-12)) 
        {	
					//一屏
           x = y = 0;
        }
        
        LCD_Char_6x12_O(x ,y, *str,Color);
        x += 6;
        str ++ ;
    }
				  
}





/******************************************************
 * 函数名：LCD_Str_6x12_O_P
 * 描述  ：在指定坐标处悬浮显示6*12大小的字符串
 * 输入  : -x   显示位置横向坐标 0 ~ 319
           -y   显示位置纵向坐标 0 ~ 239
 * 		   -str 字符串首址
 *         -Color字符颜色
 * 输出  ：无
 * 举例  ：	LCD_Str_6x12_O_P(200, 0,"LOVE STM32", 0);
		   	LCD_Str_6x12_O_P(0, 0,"LOVE STM32", 0);
		    LCD_Str_6x12_O_P(320-12, 239-6*10,"LOVE STM32", 0);
 * 注意  ：	字符串显示方向为纵向 已测试
*********************************************************/    
void LCD_Str_6x12_O_P(u16 x, u16 y, const u8 *str, u16 Color)	
{   
		
	  Set_direction(1);      
    while(*str != '\0')
    {       
        if(y > (240-6)) 
        {	/* 换行*/
            y = 0;
            x -= 12;
        }
        if(x >(320-12)) 
        {	/*重归起点*/
            y = x = 0;
        }        
        LCD_Char_6x12_O_P(x, y , *str,Color);
        y +=6;
        str ++ ;
    }
		  
}





/********************************************************************
 * 函数名：LCD_Char_CH
 * 描述  ：显示单个汉字字符
 * 输入  : 	x: 0~(319-16)
 *         	y: 0~(239-16)
 *			str: 中文字符串首址
 *			Color: 字符颜色   
 *			bkColor: 背景颜色
 * 输出  ：无
 * 举例  ：	LCD_Char_CH(200,100,"好",0,0);
 * 注意	 ：1 如果输入大于1的汉字字符串，显示将会截断，只显示最前面一个汉字
           2 中文字库从sd卡提取，请看"tip.txt"  
************************************************************************/    
void LCD_Char_CH(u16 x,u16 y,const u8 *str,u16 Color,u16 bkColor)
{
    
#ifndef NO_CHNISEST_DISPLAY         /*如果汉字显示功能没有关闭*/
    u8 i,j;
    u8 buffer[32];
    u16 tmp_char=0;
    
    
    GetGBKCode_from_sd(buffer,str);  /* 取字模数据 */
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
 * 函数名：LCD_Char_CH_P
 * 描述  ：显示单个汉字字符
 * 输入  : x: 0~(319-16)
 *         y: 0~(239-16)
 *		   str: 中文字符串首址
 *		   Color: 字符颜色   
 *		   bkColor: 背景颜色
 * 输出  ：无
 * 举例  ：	LCD_Char_CH_P(200,100,"好",0,0);
 * 注意	 ：1 如果输入大于1的汉字字符串，显示将会截断，只显示最前面一个汉字
           2 中文字库从sd卡提取，请看"tip.txt"  
***********************************************************************/    
void LCD_Char_CH_P(u16 x,u16 y,const u8 *str,u16 Color,u16 bkColor)
{
    
#ifndef NO_CHNISEST_DISPLAY         /*如果汉字显示功能没有关闭*/
    
    u8 i,j;
    u8 buffer[32];
    u16 tmp_char=0;
    
    Set_direction(1);
   	GetGBKCode_from_sd(buffer,str);	 /* 取字模数据 */
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
 * 函数名：	LCD_Char_CH_O
 * 描述  ： 悬浮显示单个汉字字符
 * 输入  : 	x: 0~(319-16)
 *         	y: 0~(239-16)
 *			str: 中文字符串首址
 *			Color: 字符颜色   
 * 输出  ：无
 * 举例  ：	LCD_Char_CH_O(200,100,"好",0,0);
 * 注意	 ：1 横屏2 如果输入大于1的汉字字符串，显示将会截断，只显示最前面一个汉字
           3 中文字库从sd卡提取，请看"tip.txt"  
 ********************************************************************************/    
void LCD_Char_CH_O(u16 x,u16 y,const u8 *str,u16 Color) 
{
#ifndef NO_CHNISEST_DISPLAY   
    u8 i,j;
    u8 buffer[32];
    u16 tmp_char=0;
    Set_direction(0);   
    GetGBKCode_from_sd(buffer,str); /* 取字模数据 */
    
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
 * 函数名：LCD_Char_CH_O_P
 * 描述  ：在Lcd屏上任意位置悬浮显示一个中文字
 * 输入  : 	- x: 水平坐标 
 *         	- y: 垂直坐标  
 *			- str: 显示的中文字
 *			- Color: 字符颜色   
 * 输出  ：无
 * 举例  ：	LCD_Char_CH_O_P(200,100,"云",0); 		
 * 注意  ：	1 竖屏2 如果输入大于1的汉字字符串，显示将会截断，只显示最前面一个汉字
*********************************************************************************/    
void LCD_Char_CH_O_P(u16 x,u16 y,const u8 *str,u16 Color) 
{
    
#ifndef NO_CHNISEST_DISPLAY                           /*如果汉字显示功能没有关闭*/
    
    u8 i,j;
    u8 buffer[32];
    u16 tmp_char=0;
    Set_direction(1);
    GetGBKCode_from_sd(buffer,str);  									/* 取字模数据 */
   
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
 * 函数名：LCD_Str_CH
 * 描述  ：在指定坐标处显示16*16大小的指定颜色汉字字符串
 * 输入  : 	- x: 显示位置横向坐标	 
 *         	- y: 显示位置纵向坐标 
 *			- str: 显示的中文字符串
 *			- Color: 字符颜色   
 *			- bkColor: 背景颜色
 * 输出  ：无
 * 举例  ：	LCD_Str_CH(0,0,"阿莫论坛野火专区",0,0xffff);
		    LCD_Str_CH(50,100,"阿莫论坛野火专区",0,0xffff);
		    LCD_Str_CH(320-16*8,240-16,"阿莫论坛野火专区",0,0xffff); 		
 * 注意  ：	字符串显示方向为横向 中文字库从sd卡提取，请看"tip.txt"  已测试
******************************************************************************/    
void LCD_Str_CH(u16 x,u16 y,const u8 *str,u16 Color,u16 bkColor)  
{
   
    Set_direction(0);
    while(*str != '\0')
    {
			if(x>(320-16))
			{	 
				 /*换行*/
				x =0;
				y +=16;
					
			}
			if(y >(240-16))
			{
				 /*重新归零*/
				 y =0;
				 x =0;
			}
	     LCD_Char_CH(x,y,str,Color,bkColor);      
       str += 2 ;
       x += 16 ;	
    }
}





/********************************************************************************
 * 函数名：LCD_Str_CH_P
 * 描述  ：在指定坐标处显示16*16大小的指定颜色汉字字符串
 * 输入  : 	- x: 显示位置横向坐标	 
 *         	- y: 显示位置纵向坐标 
 *			- str: 显示的中文字符串
 *			- Color: 字符颜色   
 *			- bkColor: 背景颜色
 * 输出  ：无
 * 举例  ：	LCD_Str_CH_P(200,240-16*8,"阿莫论坛野火专区欢迎你",0xff,0xffff);
		    LCD_Str_CH_P(320-16,240-16*8,"阿莫论坛野火专区",0xff,0xffff);
		    LCD_Str_CH_P(0,0,"阿莫论坛野火专区",0xff,0xffff);		
 * 注意  ：	字符串显示方向为纵向 中文字库从sd卡提取，请看"tip.txt"  已测试
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
 * 函数名：LCD_Str_CH_O
 * 描述  ：在指定坐标处悬浮显示16*16大小的指定颜色汉字字符串
 * 输入  : 	- x:  显示位置横向坐标	 
 *         	- y:  显示位置纵向坐标 
 *			- str:   显示的中文字符串
 *			- Color: 字符颜色    
 * 输出  ：无
 * 举例  ：	LCD_Str_CH_O(0,0,"阿莫论坛野火专区",0);
		   	LCD_Str_CH_O(320-16*5,100,"阿莫论坛野火专区欢迎你",0);
		    LCD_Str_CH_O(320-16*8,240-16,"阿莫论坛野火专区",0);		
 * 注意  ：	字符串显示方向为横向 中文字库从sd卡提取，请看"tip.txt"  已测试
***************************************************************************************/    
void LCD_Str_CH_O(u16 x,u16 y,const u8 *str,u16 Color)	 
{
    	
	Set_direction(0);
    while(*str != '\0')
    {
			if(x>(320-16))
			{	 
				 /*换行*/
				x =0;
				y +=16;
					
			}
			if(y >(240-16))
			{
				 /*重新归零*/
				 y =0;
				 x =0;
			}
	     LCD_Char_CH_O(x,y,str,Color);     
       str += 2 ;
       x += 16 ;	
    }
       
}



/**********************************************************************************
 * 函数名：LCD_Str_CH_O_P
 * 描述  ：在指定坐标处悬浮显示16*16大小的指定颜色汉字字符串
 * 输入  : - x: 显示位置横向坐标	 
 *         - y: 显示位置纵向坐标 
 *		   - str: 显示的中文字符串
 *		   - Color: 字符颜色   
 * 输出  ：无
 * 举例   	LCD_Str_CH_O_P(200,240-16*6,"阿莫论坛野火专区",0);
		    LCD_Str_CH_O_P(0,0,"阿莫论坛野火专区",0);
		    LCD_Str_CH_O_P(320-16,240-16*8,"阿莫论坛野火专区",0);
 * 注意  ：	字符串显示方向为纵向 中文字库从sd卡提取，请看"tip.txt"  已测试
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
 * 函数名：LCD_Str_ENCH_O_P
 * 描述  ：中英文混合悬浮显示，英文大小为16*8
 * 输入  : 	- x: 显示位置横向坐标	 
 *         	- y: 显示位置纵向坐标 
 *			- str: 显示的中文字符串
 *			- Color: 字符颜色   
 * 输出  ：无
 * 举例    LCD_Str_ENCH_O_P(200,100,"野火stm32阿莫专区野火stm32",0);
	       LCD_Str_ENCH_O_P(0,0,"野火stm32阿莫专区野火stm32",0);
 * 注意  ：	字符串显示方向为纵向 中文字库从sd卡提取，请看"tip.txt"  已测试
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
						 /*换行*/
						 Tmp_y =0;
						 Tmp_x -=16;
					}
					LCD_Char_O_P(Tmp_x,Tmp_y, *str,Color);
					str++ ;
					Tmp_y	+= 8;
				}
				else
				{
					if(*str==163)									/*163-172 是中文逗号	 163-187是中文分号*/
					{
						LCD_Char_O_P(Tmp_x,Tmp_y, ' ',Color);		/*改为显示1个空格*/
						str += 2 ;
						Tmp_x	+= 8 ;

					}
					if(Tmp_y >(240-16))
					{
						 /*换行*/
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

