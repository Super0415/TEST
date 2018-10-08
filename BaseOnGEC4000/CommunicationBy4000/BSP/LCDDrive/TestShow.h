#ifndef __TESTSHOW_H
#define	__TESTSHOW_H
#include "TYPCortex.h"

extern INT08U ForwardPage_Num[3];    //��Ҫ��ʾ�Ľ���
extern INT08U NowPage_Num[3];        //��ǰ��ʾ�Ľ���
extern INT08U HistoryPage_Num[3];    //��ʷ��¼�Ľ���
extern INT08U EditPageEnable;           //�༭��ǰ����ʹ��

const typedef enum
{
    FunDISable = 0,
	  FunENable,
}FUNABLE;  //����ʹ��
const typedef enum
{
    RS485AddPage0 = 0,
	  CANFunPage,
	  TotalFunPage
}Level0num;  //��������
const typedef enum
{
    RS485Fun0 = 0,
	  RS485Fun1,
	  RS485Fun2,
	  RS485Fun3,
	  RS485Fun4
}RS485Pagenum; //RS485�ֽ���
const typedef enum
{
    CANFun0 = 0,
	  CANFun1,
	  CANFun2,
	  CANFun3,
	  CANFun4
}CANPagenum; //CAN�ֽ���
typedef struct
{
  FUNABLE SHOWABLE;             		//��ʾʹ��
  INT16U  Level0Pos;            		//��0��Ȩ�޵�λ��
  INT16U  Level1Pos;            		//��1��Ȩ�޵�λ��
  INT16U  Pic_X;                   	//ͼƬ X����
  INT16U  Pic_Y;                   	//ͼƬ Y����
  const GUI_BITMAP *Pic_Add;   	//ͼƬ��ַ
  INT16U TXT_X;                 		//�ı� X����
  INT16U TXT_Y;                		 	//�ı� Y����
  const GUI_FONT * GUIFont;         //�ı�����
  INT16U TxTAdd;     //�ı�λ��
  void (*FunF)();              //���ܺ���
  void (*FunB)();              //���ܺ��� 
}SolidStruct;

typedef struct
{
   const char DisCNStrings[29];
   const char DisENStrings[29];

}DisFontStruct;

typedef struct
{
  FUNABLE SHOWABLE;             		//��ʾʹ��
  INT16U  Level0Pos;            		//��0��Ȩ�޵�λ��
  INT16U  Level1Pos;            		//��1��Ȩ�޵�λ��
  INT16U TXT_X;                 		//�ı� X����
  INT16U TXT_Y;                		 	//�ı� Y����
  const GUI_FONT * GUIFont;         //�ı�����
  INT08U DISFun;               //�������⹦��
  INT16U *DATAAdd;               //����ָ��
  void (*FunF)();             //���ܺ���
  void (*FunB)();              //���ܺ��� 
}dynamicStruct;

#define LCD_DisBKColor   0xff3300       //����ɫ
#define LCD_DisColor     GUI_WHITE      //��ʾ����

#define SumSolidState  10
#define SumSolidWord   7

#define SumdynamicData 4


// selfAPI
void TestShowTask(void);  //���������ѭ��

void DBKeyCheck(void);  //������ݿⰴ��ֵ
void ShowScreen(void);  //��ʾ����
void RS485Fun0_KeyRule(void);//RS485Fun0���水������
void RS485Fun0_Show(void);
void RS485Fun0_SolidShow(void);
void RS485Fun0_dynamicShow(void);
void RS485Fun0_DisCheckSolid(INT08U *DisSolTips,INT08U *DisdynTips);
//void RS485Fun1_KeyRule(void);//RS485Fun1���水������
//void RS485Fun1_Show(void);
//void RS485Fun1_SolidShow(void);
//void RS485Fun1_dynamicShow(void);
//void RS485Fun2_KeyRule(void);//RS485Fun2���水������
//void RS485Fun2_Show(void);
//void RS485Fun2_SolidShow(void);
//void RS485Fun2_dynamicShow(void);
//void RS485Fun3_KeyRule(void);//RS485Fun3���水������
//void RS485Fun3_Show(void);
//void RS485Fun3_SolidShow(void);
//void RS485Fun3_dynamicShow(void);
//void RS485Fun4_KeyRule(void);//RS485Fun4���水������
//void RS485Fun4_Show(void);
//void RS485Fun4_SolidShow(void);
//void RS485Fun4_dynamicShow(void);

void RS485Dis00Message(void);
void RS485Dis01Message(void);
void DisMessage(INT16U X,INT16U Y,INT16U XX,INT16U Data,INT08U DisLong);

void CANDis00Message(void);
void CANDis01Message(void);

void CANFun0_KeyRule(void);//CANFun0���水������
void CANFun0_Show(void);
void CANFun0_SolidShow(void);
void CANFun0_dynamicShow(void);
//void CANFun1_KeyRule(void);//CANFun1���水������
//void CANFun1_Show(void);
//void CANFun1_SolidShow(void);
//void CANFun1_dynamicShow(void);
//void CANFun2_KeyRule(void);//CANFun2���水������
//void CANFun2_Show(void);
//void CANFun2_SolidShow(void);
//void CANFun2_dynamicShow(void);
//void CANFun3_KeyRule(void);//CANFun3���水������
//void CANFun3_Show(void);
//void CANFun3_SolidShow(void);
//void CANFun3_dynamicShow(void);
//void CANFun4_KeyRule(void);//CANFun4���水������
//void CANFun4_Show(void);
//void CANFun4_SolidShow(void);
//void CANFun4_dynamicShow(void);

#endif





