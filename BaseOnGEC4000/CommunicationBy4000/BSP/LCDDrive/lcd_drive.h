/***********************************************************
                       Ұ��LCD��������
 Ĭ��Ϊ������Ӣ��Ĭ��Ϊ8*16������Ĭ��Ϊ16*16���ַ���Ĭ������롣

 ����д:
 LCD	Һ��		Liquid Crystal Display
 Char	�ַ�		character						�����ʾһ���ֵ���˼����ʾһ�����֣�Ҳ����Char��ʶ
 Str	�ַ���		string
 Num	����		Number
 CH		����		Chinese
 ENCH	��Ӣ����	English-Chinese
 O		����Ч��	overlying
 P		����		Portrait
 6x12	�����СΪ6*12
 R		�Ҷ���		right

 ����˳��:
 		����		��С	   ��������	   ��ʾѡ��   ���뷽ʽ 	  ��Ļѡ��
 LCD----Str 	----6x12	----CH		----O		----R		----P
        Char					ENCH	
 		Num
        XXX				

 ����XXX��ʾPoint��Line��Rectangle�ȵȡ�
 ͬһ�б�ʾͬ������˳��
 ���ֲ����ɲ�Ҫ
***********************************************************/


/***********************************************************
 				Ұ��LCD������������˳�����
 (x,y)	----str		----����δ֪����	----(color,bkColor)
			char		��:len
			num
***********************************************************/

#ifndef __LCD_DRIVE_H
#define	__LCD_DRIVE_H

#include "stm32f10x.h"
#include "lcd_botton.h"





#define HX8347		/* LCD������Ϊ HX8347-G(T) ---������ú궨��ע�͵�����ʹ��ili9325Һ��������*/

/******������ɫ*****/
#define RED   0XF800
#define GREEN 0X07E0
#define BLUE  0X001F  
#define BRED  0XF81F
#define GRED  0XFFE0
#define GBLUE 0X07FF
#define BLACK 0X0000
#define WHITE 0XFFFF


void LCD_Init1(void);
void GUI_Line(int x0, int y0, int x1, int y1,u32 color);
u16 GetPoint(u16 x,u16 y);

/***************  LCD�滭  ***************/
void LCD_Point			(u16 x,u16 y);
void LCD_ColorPoint		(u16 x,u16 y,u16 rgb565); 
void LCD_Line			(u16 x1,u16 y1,u16 x2,u16 y2);
void LCD_Rectangle		(u16 x,u16 y,u16 len,u16 wid,u16 rgb565);					/*����*/


/***************�����ַ���ʾ  Landscape����***************/
void LCD_Char			(u16 x,u16 y,	u8 ascii,	u16 Color,u16 bkColor);			/*8*16*/
void LCD_Char_O			(u16 x,u16 y,	u8 acsii,	u16 Color);
void LCD_Char_CH		(u16 x,u16 y,const u8 *str,	u16 Color,u16 bkColor);
void LCD_Char_CH_O		(u16 x,u16 y,const u8 *str,	u16 Color);

void LCD_Str_O			(u16 x,u16 y,const u8 *str,	u16 Color); 					/*8*16 ascii*/
void LCD_Str_CH			(u16 x,u16 y,const u8 *str,	u16 Color,u16 bkColor); 		/*16*16����*/
void LCD_Str_CH_O		(u16 x,u16 y,const u8 *str,	u16 Color);	        			/*16*16����*/


void LCD_Num_6x12_O		(u16 x,u16 y,	u32 num,	u16 Color);	   			 		/*6*12 */
void LCD_Char_6x12_O	(u16 x,u16 y,	u8 acsii,	u16 Color);						//6*12
void LCD_Str_6x12_O		(u16 x,u16 y,const u8 *str,	u16 Color);	 					/*6*12 ascii*/


/***************�����ַ���ʾ  Portrait����***************/

void LCD_Char_O_P		(u16 x,u16 y,	u8 acsii,	u16 Color);
void LCD_Char_CH_P		(u16 x,u16 y,const u8 *str,	u16 Color,u16 bkColor);
void LCD_Char_CH_O_P	(u16 x,u16 y,const u8 *str,	u16 Color);

void LCD_Str_O_P		(u16 x,u16 y,const u8 *str,	u16 Color); 			/*8*16 ascii*/			
void LCD_Str_CH_P		(u16 x,u16 y,const u8 *str,	u16 Color,u16 bkColor); 	/*16*16����*/
void LCD_Str_CH_O_P		(u16 x,u16 y,const u8 *str,	u16 Color);	    		/*16*16����*/

void LCD_Char_6x12_O_P	(u16 x,u16 y,	u8 acsii,	u16 Color);						//6*12
void LCD_Str_6x12_O_P	(u16 x,u16 y,const u8 *str,	u16 Color);	  					/*6*12 ascii*/	



/***************Ϊ����ʵ��ר�ű�д�ĺ���***************/
//������ʵ��ר��
void LCD_Str_R			(u16 x,u16 y,const u8 *str,	u8 len,u16 Color,u16 bkColor); 	/*�Ҷ��룬����lenλ������ʾ���lenλ*/

//MP3ʵ����
void LCD_Str_ENCH_O_P	(u16 x,u16 y,const u8 *str,	u16 Color);	     				/*��Ӣ�Ļ���*/



#endif /* __LCD_H */

