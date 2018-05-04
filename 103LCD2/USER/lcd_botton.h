#include "stm32f10x.h"
#include "stm32f10x_fsmc.h"

/* 选择BANK1-BORSRAM1 连接 TFT，地址范围为0X60000000~0X63FFFFFF
 * FSMC_A16 接LCD的DC(寄存器/数据选择)脚
 * 16 bit => FSMC[24:0]对应HADDR[25:1](AHB[25:1])
 * 寄存器基地址 = 0X60000000
 * RAM基地址 = 0X60020000 = 0X60000000+2^16*2 = 0X60000000 + 0X20000 = 0X60020000
 * 当选择不同的地址线时，地址要重新计算。
 */
#define Bank1_LCD_D    ((u32)0x60020000)       //Disp Data ADDR
#define Bank1_LCD_C    ((u32)0x60000000)	   //Disp Reg ADDR

/*选定LCD指定寄存器*/
#define LCD_WR_REG(index)    ((*(__IO u16 *) (Bank1_LCD_C)) = ((u16)index))
/*将LCD中的index寄存器设置为val值*/
#define LCD_WR_CMD(index,val)  do{(*(__IO u16 *) (Bank1_LCD_C)) = ((u16)index);	(*(__IO u16 *) (Bank1_LCD_D)) = ((u16)(val));}while(0)
/*往LCD GRAM写入数据*/
#define LCD_WR_Data(val)       ((*(__IO u16 *) (Bank1_LCD_D)) = ((u16)(val)))



#define u8 char


void Lcd_init_conf(void);
void Lcd_data_start(void);
void LCD_GPIO_Config(void);
void LCD_FSMC_Config(void);
void LCD_Rst(void);
u16 LCD_RD_data(void);
void Set_direction(u8 option);
void LCD_open_windows(u16 x,u16 y,u16 len,u16 wid);





















/********************************************************************************************************************************/
/*****************************************************横竖屏图解--开始*****************************************************************/
/********************************************************************************************************************************/
/*注：以下内容可能由于用户MDK设置的Tab Size不同导致图示不能对齐，请将Tab size统一设置为4个空格
      设置方法：Edit->Configuration->Edit->C/C++ Files->Tab Size选项的输入框输入4即可
*/


/*

①
图解一: 液晶如何摆放
        
		描述：液晶横向水平摆放在眼前(一 水平方向(左右方向)长度为320  二 上下方向长度为240  三 插针(如下图,"O"表示插针)在水平方向的左边，共两列，每列16个)

O  O  |---------------------------------320-------------------------------------------|
O  O  |屏起点                                                                         | 
O  O  |                                                                               | 
O  O  |                                                                               | 
O  O  |                                                                               | 
O  O  2                                                                               2 
O  O  4                                                                               4 
O  O  0                                                                               0 
O  O  |                                                                               | 
O  O  |                                                                               | 
O  O  |                                                                               | 
O  O  |                                                                               | 
O  O  |                                                                               | 
O  O  |                                                                               | 
O  O  |                                                                         屏终点| 
O  O  |-----------------------------------320-----------------------------------------|





②
图解二: 横屏GRAM扫描方向图解
        描述：每行有320个点 共有240行
		GRAM扫描方向及先后顺序图解如下：


(屏起点)------------------------------------------------------------->第0行
--------------------------------------------------------------------->第1行
--------------------------------------------------------------------->
--------------------------------------------------------------------->
--------------------------------------------------------------------->
...
...（此处略过很多行）
...
--------------------------------------------------------------------->
--------------------------------------------------------------------->
--------------------------------------------------------------------->
--------------------------------------------------------------------->第238行
--------------------------------------------------------------------->第239行(屏终点)



③
图解三: 竖屏GRAM扫描方向图解
        描述：每列有240个点 共320列
		GRAM扫描方向及先后顺序图解如下：
 屏
 起
 点
 0 0 0 0 0 0 0			                       3 3 3 3 3 3 3 3 3 3 3
 0 0 0 0 0 0 0			                       0 1 1 1 1 1 1 1 1 1 1
 0 1 2 3 4 5 6		                           9 0 1 2 3 4 5 6 7 8 9
 列列列列列列列			                       列列列列列列列列列列列       
 | | | | | | |                                 | | | | | | | | | | |
 | | | | | | |                                 | | | | | | | | | | |
 | | | | | | |                                 | | | | | | | | | | |
 | | | | | | |     ....此                      | | | | | | | | | | |
 | | | | | | |     ....处                      | | | | | | | | | | |
 | | | | | | |     ....略                      | | | | | | | | | | |
 | | | | | | |     ....过                      | | | | | | | | | | |
 | | | | | | |     ....很                      | | | | | | | | | | |
 | | | | | | |     ....多                      | | | | | | | | | | |
 | | | | | | |     ....列                      | | | | | | | | | | |
 | | | | | | |                                 | | | | | | | | | | |
 | | | | | | |                                 | | | | | | | | | | |
 ↓ ↓ ↓ ↓ ↓ ↓ ↓                                 ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓
						          					 	 	 	  屏
														          终
														          点


*/

/********************************************************************************************************************************/
/*****************************************************横竖屏图解--结束*****************************************************************/
/********************************************************************************************************************************/
