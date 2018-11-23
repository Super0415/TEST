#ifndef __TESTSHOW_H
#define	__TESTSHOW_H
#include "TYPCortex.h"

extern INT08U ForwardPage_Num[3];    //将要显示的界面
extern INT08U NowPage_Num[3];        //当前显示的界面
extern INT08U HistoryPage_Num[3];    //历史记录的界面
extern INT08U EditPageEnable;           //编辑当前界面使能

const typedef enum
{
    FunDISable = 0,
	  FunENable,
}FUNABLE;  //数据使能
const typedef enum
{
    RS485AddPage0 = 0,
	  CANFunPage,
	  TotalFunPage
}Level0num;  //界面种类
const typedef enum
{
    RS485Fun0 = 0,
	  RS485Fun1,
	  RS485Fun2,
	  RS485Fun3,
	  RS485Fun4
}RS485Pagenum; //RS485分界面
const typedef enum
{
    CANFun0 = 0,
	  CANFun1,
	  CANFun2,
	  CANFun3,
	  CANFun4
}CANPagenum; //CAN分界面
typedef struct
{
  FUNABLE SHOWABLE;             		//显示使能
  INT16U  Level0Pos;            		//在0级权限的位置
  INT16U  Level1Pos;            		//在1级权限的位置
  INT16U  Pic_X;                   	//图片 X坐标
  INT16U  Pic_Y;                   	//图片 Y坐标
  const GUI_BITMAP *Pic_Add;   	//图片地址
  INT16U TXT_X;                 		//文本 X坐标
  INT16U TXT_Y;                		 	//文本 Y坐标
  const GUI_FONT * GUIFont;         //文本字体
  INT16U TxTAdd;     //文本位置
  void (*FunF)();              //功能函数
  void (*FunB)();              //功能函数 
}SolidStruct;

typedef struct
{
   const char DisCNStrings[29];
   const char DisENStrings[29];

}DisFontStruct;

typedef struct
{
  FUNABLE SHOWABLE;             		//显示使能
  INT16U  Level0Pos;            		//在0级权限的位置
  INT16U  Level1Pos;            		//在1级权限的位置
  INT16U TXT_X;                 		//文本 X坐标
  INT16U TXT_Y;                		 	//文本 Y坐标
  const GUI_FONT * GUIFont;         //文本字体
  INT08U DISFun;               //数据特殊功能
  INT16U *DATAAdd;               //数据指针
  void (*FunF)();             //功能函数
  void (*FunB)();              //功能函数 
}dynamicStruct;

#define LCD_DisBKColor   0xff3300       //背景色
#define LCD_DisColor     GUI_WHITE      //显示字体

#define SumSolidState  10
#define SumSolidWord   7

#define SumdynamicData 4


// selfAPI
void TestShowTask(void);  //测试软件总循环

void DBKeyCheck(void);  //检测数据库按键值
void ShowScreen(void);  //显示界面
void RS485Fun0_KeyRule(void);//RS485Fun0界面按键规则
void RS485Fun0_Show(void);
void RS485Fun0_SolidShow(void);
void RS485Fun0_dynamicShow(void);
void RS485Fun0_DisCheckSolid(INT08U *DisSolTips,INT08U *DisdynTips);
//void RS485Fun1_KeyRule(void);//RS485Fun1界面按键规则
//void RS485Fun1_Show(void);
//void RS485Fun1_SolidShow(void);
//void RS485Fun1_dynamicShow(void);
//void RS485Fun2_KeyRule(void);//RS485Fun2界面按键规则
//void RS485Fun2_Show(void);
//void RS485Fun2_SolidShow(void);
//void RS485Fun2_dynamicShow(void);
//void RS485Fun3_KeyRule(void);//RS485Fun3界面按键规则
//void RS485Fun3_Show(void);
//void RS485Fun3_SolidShow(void);
//void RS485Fun3_dynamicShow(void);
//void RS485Fun4_KeyRule(void);//RS485Fun4界面按键规则
//void RS485Fun4_Show(void);
//void RS485Fun4_SolidShow(void);
//void RS485Fun4_dynamicShow(void);

void RS485Dis00Message(void);
void RS485Dis01Message(void);
void DisMessage(INT16U X,INT16U Y,INT16U XX,INT16U Data,INT08U DisLong);

void CANDis00Message(void);
void CANDis01Message(void);

void CANFun0_KeyRule(void);//CANFun0界面按键规则
void CANFun0_Show(void);
void CANFun0_SolidShow(void);
void CANFun0_dynamicShow(void);
//void CANFun1_KeyRule(void);//CANFun1界面按键规则
//void CANFun1_Show(void);
//void CANFun1_SolidShow(void);
//void CANFun1_dynamicShow(void);
//void CANFun2_KeyRule(void);//CANFun2界面按键规则
//void CANFun2_Show(void);
//void CANFun2_SolidShow(void);
//void CANFun2_dynamicShow(void);
//void CANFun3_KeyRule(void);//CANFun3界面按键规则
//void CANFun3_Show(void);
//void CANFun3_SolidShow(void);
//void CANFun3_dynamicShow(void);
//void CANFun4_KeyRule(void);//CANFun4界面按键规则
//void CANFun4_Show(void);
//void CANFun4_SolidShow(void);
//void CANFun4_dynamicShow(void);

#endif





