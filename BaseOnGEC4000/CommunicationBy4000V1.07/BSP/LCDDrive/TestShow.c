/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File TestShow.c                         */
/*                            By: Fengzc                                */
/*                             2018-05-17                               */
/* ******************************************************************** */
#include "TestShow.h"
#include "TYPCortex.h"




/*  ѡȡ�Ĺ�����
  0-0 485 ��1����ַ����
	1-0 485 ��2����ַ����
	2-0 485 ��3����ַ����
	3-0 CAN ��ʾ����
*/
// ��1��Ԫ��Ϊ ��������  ��2��Ԫ��Ϊ �����µķֽ���  ��3��Ԫ��Ϊ �ֽ����µ��������
INT08U ForwardPage_Num[3];    //��Ҫ��ʾ�Ľ���  //�����и�ֵ
INT08U NowPage_Num[3];        //��ǰ��ʾ�Ľ���  //��ʾ�и�ֵ
INT08U HistoryPage_Num[3];    //��ʷ��¼�Ľ���  //�����и�ֵ
INT08U EditPageEnable;           //�༭��ǰ����ʹ��
INT08U EditDATAEnable[2];        //�༭��ǰ����ָ������ʹ��  //0-�����ڴ˽������  1-�Ƿ�༭ʹ��


INT08U DisSolidTips[SumSolidState+1] = {0};   //��̬��ʾλ��
INT08U DisdynamicTips[SumSolidWord+1] = {0}; //��̬��ʾλ��


const DisFontStruct DisFontStrings[SumSolidWord] = 
{
/*   0 */    {{"RS485 -- "},{"RS485-TEST"}},
/*   1 */    {{"����:"},{"Message:"}},
/*   2 */    {{"CAN ----"},{"2222"}},
/*   3 */    {{"3333"},{"3333"}},

};

SolidStruct  SolidState[SumSolidState] = 
{
	          //��ʾʹ��----0��λ��--------1��λ��---- -Pic_X-Pic_Y--ͼƬ��ַ---TXT_X--TXT_Y----����------------------�ı�λ��-----------------------���ܺ���
/*000*/   {  FunENable,    RS485AddPage0,  RS485Fun0   ,  0,    0,       NULL,    80,  70,   &GUI_FontHZ24,     0,        NULL,         NULL},
/*001*/   {  FunDISable,   RS485AddPage0,  RS485Fun0   ,  0,    0,       NULL,    5,   30,   &GUI_FontHZ24,     1,        NULL,         NULL},
/*002*/   {  FunENable,    RS485AddPage0,  RS485Fun0   ,  0,    0,       NULL,    80,  120,  &GUI_FontHZ24,     2,        NULL,         NULL},
/*003*/   {  FunDISable,   RS485AddPage0,  RS485Fun0   ,  0,    0,       NULL,    5,   120,  &GUI_FontHZ24,     1,        NULL,         NULL},
/*004*/   {  FunDISable,   RS485AddPage0,  RS485Fun0   ,  0,    0,       NULL,    60,  150,  &GUI_FontHZ24,     4,        NULL,         NULL},


/*005*/   {  FunDISable,   CANFunPage,     CANFun0     ,  0,    0,       NULL,    0,     0,  &GUI_FontHZ24,     0,        NULL,         NULL},
/*006*/   {  FunDISable,   CANFunPage,     CANFun0     ,  0,    0,       NULL,    30,    0,  &GUI_FontHZ24,     1,        NULL,         NULL},
/*007*/   {  FunDISable,   CANFunPage,     CANFun0     ,  0,    0,       NULL,    60,    0,  &GUI_FontHZ24,     2,        NULL,         NULL},
/*008*/   {  FunDISable,   CANFunPage,     CANFun0     ,  0,    0,       NULL,    90,    0,  &GUI_FontHZ24,     3,        NULL,         NULL},
/*009*/   {  FunDISable,   CANFunPage,     CANFun0     ,  0,    0,       NULL,    120,   0,  &GUI_FontHZ24,     4,        NULL,         NULL},
};



dynamicStruct dynamicData[SumdynamicData] = 
{
	          //��ʾʹ��-------0��λ��--------1��λ��------TXT_X--TXT_Y----����--------�������⹦��-----����ָ��λ��----------------���ܺ���
/*000*/   {  FunDISable,   RS485AddPage0,  RS485Fun0   ,     0,   0,   &GUI_FontHZ24,       0,         NULL,        RS485Dis00Message,         NULL},  //485���ͱ���
/*000*/   {  FunENable,   RS485AddPage0,  RS485Fun0   ,     0,   0,   &GUI_FontHZ24,       0,         NULL,        RS485Dis01Message,         NULL},  //��һ������
/*000*/   {  FunDISable,   RS485AddPage0,  RS485Fun0   ,     0,   0,   &GUI_FontHZ24,       0,         NULL,        CANDis00Message,         NULL},  //485���ͱ���
/*000*/   {  FunENable,   RS485AddPage0,  RS485Fun0   ,     0,   0,   &GUI_FontHZ24,       0,         NULL,        CANDis01Message,         NULL},  //��һ������
};


//������TestShowTask
//�ӿڣ���ʾ����
//˵����
//��ע��
void TestShowTask(void)
{
	  DBKeyCheck();
	
    ShowScreen();
}

//������DBKeyCheck
//�ӿڣ����ݵ�ǰ�����жϰ�������
//˵����
//��ע��
void DBKeyCheck(void)
{
	  switch(ForwardPage_Num[0])
		{
			case RS485AddPage0:	
				switch(ForwardPage_Num[1])
				{
					case RS485Fun0:  RS485Fun0_KeyRule(); break;
//				  case RS485Fun1:  RS485Fun1_KeyRule(); break;
//					case RS485Fun2:  RS485Fun2_KeyRule(); break;
//					case RS485Fun3:  RS485Fun3_KeyRule(); break;
//					case RS485Fun4:  RS485Fun4_KeyRule(); break;
				}

		  break;
			case CANFunPage:
				switch(ForwardPage_Num[1])
				{
					case CANFun0:  CANFun0_KeyRule(); break;
//				  case CANFun1:  CANFun0_KeyRule(); break;
//					case CANFun2:  CANFun0_KeyRule(); break;
//					case CANFun3:  CANFun0_KeyRule(); break;
//					case CANFun4:  CANFun0_KeyRule(); break;
				}				
		  break;
      default:
			break;
		}
}
//������ShowScreen
//�ӿڣ����ݵ�ǰ�����ж���ʾ����
//˵����
//��ע��
void ShowScreen(void)
{
	  switch(ForwardPage_Num[0])
		{
			case RS485AddPage0:
				switch(ForwardPage_Num[1])
				{
					case RS485Fun0:  RS485Fun0_Show(); break;
//				  case RS485Fun1:  RS485Fun1_Show(); break;
//					case RS485Fun2:  RS485Fun2_Show(); break;
//					case RS485Fun3:  RS485Fun3_Show(); break;
//					case RS485Fun4:  RS485Fun4_Show(); break;
				}

		  break;
			case CANFunPage:
				switch(ForwardPage_Num[1])
				{
					case CANFun0:  CANFun0_Show(); break;
//				  case CANFun1:  CANFun1_Show(); break;
//					case CANFun2:  CANFun2_Show(); break;
//					case CANFun3:  CANFun3_Show(); break;
//					case CANFun4:  CANFun4_Show(); break;
				}				
		  break;
      default:
			break;
		}  	

}
//������RS485Fun0_KeyRule
//�ӿڣ�RS485Fun0���水������
//˵����
//��ע��
void RS485Fun0_KeyRule(void)
{
	  if(usDBmKeyMenuUp)
		{
			  if(EditPageEnable)
				{
				
				}
				else
				{
				
				}
		}	
		else if(usDBmKeyMenuDown)
		{
		
		
		}
		else if(usDBmKeyMenuEnter)
		{
			  if(EditPageEnable)
				{
				    EditPageEnable = 0;
				}
				else
				{
				    EditPageEnable = 1;
				}
		
		}
		else if(usDBmKeyMenuLeft)
		{
		
		}
		else if(usDBmKeyMenuRight)
		{
		
		}

}
//*************************************************************************************************  RS485-0
//������RS485Fun0_Show
//�ӿڣ�RS485Fun1������ʾ
//˵����
//��ע��
void RS485Fun0_Show(void)
{
    if(ForwardPage_Num[0] != NowPage_Num[0])
    {
        NowPage_Num[0] = ForwardPage_Num[0];    //��¼Ȩ��0����ֵ
    }
    if(ForwardPage_Num[1] != NowPage_Num[1])  //
    {
				NowPage_Num[1] = ForwardPage_Num[1];  // ��¼Ȩ�޷ֽ���
				RS485Fun0_SolidShow(); 
    }
    
    RS485Fun0_dynamicShow();// 

}
//������RS485Fun0_SolidShow
//�ӿڣ�RS485Fun1���澲̬��ʾ
//˵����
//��ע��

void RS485Fun0_SolidShow(void)
{
	  INT08U i = 0;
	  INT08U Temp = 0;
    GUI_SetBkColor(LCD_DisBKColor);
    GUI_SetColor(LCD_DisColor);
		RS485Fun0_DisCheckSolid(DisSolidTips,DisdynamicTips);  //��¼�˴�����ľ�̬���� �Լ� ��̬����
    GUI_Clear();	

		for(i = 0;i < DisSolidTips[0];i++)
		{
			  Temp = DisSolidTips[i+1];
			  if(SolidState[Temp].FunF != NULL) SolidState[Temp].FunF(); 
				if(NULL != SolidState[Temp].GUIFont) 
				{
					GUI_SetFont(SolidState[Temp].GUIFont);  
				}
			  if(NULL != SolidState[Temp].Pic_Add) 
				{
						GUI_DrawBitmap(SolidState[Temp].Pic_Add,SolidState[Temp].Pic_X ,SolidState[Temp].Pic_Y);   //SolidState[Temp].TxTAdd
				}
		    if(SumSolidWord>SolidState[Temp].TxTAdd)	
				{
						GUI_DispStringAt(DisFontStrings[SolidState[Temp].TxTAdd].DisCNStrings, SolidState[Temp].TXT_X, SolidState[Temp].TXT_Y);
				}
				if(SolidState[Temp].FunB != NULL) SolidState[Temp].FunB(); 
		}
	
	
}
//������RS485Fun0_dynamicShow
//�ӿڣ�RS485Fun1�����ж���ʾ����
//˵����
//��ע��
void RS485Fun0_DisCheckSolid(INT08U *DisSolTips,INT08U *DisdynTips)
{
	  INT08U i = 0;
	  INT08U Count = 0;
	  for(i = 0;i<SumSolidState;i++)
		{
				if((SolidState[i].SHOWABLE == FunENable) && SolidState[i].Level0Pos == NowPage_Num[0] && SolidState[i].Level1Pos == NowPage_Num[1])
				{
					  Count++;
					  *(DisSolTips+Count) = i;
				}
		}
		*DisSolTips = Count;
		Count = 0;  //����ֵ����
	  for(i = 0;i<SumdynamicData;i++)
		{
				if((dynamicData[i].SHOWABLE == FunENable) && dynamicData[i].Level0Pos == NowPage_Num[0] && dynamicData[i].Level1Pos == NowPage_Num[1])
				{
					  Count++;
					  *(DisdynTips+Count) = i;
				}
		}
		*DisdynTips = Count;		


}
//������RS485Fun0_dynamicShow
//�ӿڣ�RS485Fun1���涯̬��ʾ
//˵����
//��ע��
void RS485Fun0_dynamicShow(void)
{
	  INT08U i = 0;
	  INT08U Temp = 0;

		for(i = 1;i <= DisdynamicTips[0];i++)
		{
			  Temp = DisdynamicTips[i];
				if(NULL != dynamicData[Temp].GUIFont) 
					GUI_SetFont(dynamicData[Temp].GUIFont);
			  if(dynamicData[Temp].FunF != NULL) dynamicData[Temp].FunF(); 
  
		    if(NULL != dynamicData[Temp].DATAAdd)	
					GUI_DispStringAt(DisFontStrings[SolidState[Temp].TxTAdd].DisCNStrings, SolidState[Temp].TXT_X, SolidState[Temp].TXT_Y);
				if(dynamicData[Temp].FunB != NULL) dynamicData[Temp].FunB(); 
		}	
	
	
}
////*************************************************************************************************  RS485-1
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void RS485Fun1_KeyRule(void)
//{
//}
////������RS485Fun0_Show
////�ӿڣ�RS485Fun1������ʾ
////˵����
////��ע��
//void RS485Fun1_Show(void)
//{
//}
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void RS485Fun1_SolidShow(void)
//{
//}
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void RS485Fun1_dynamicShow(void)
//{
//}
////*************************************************************************************************  RS485-2
////������RS485Fun2_KeyRule
////�ӿڣ�RS485Fun2���水������
////˵����
////��ע��
//void RS485Fun2_KeyRule(void)
//{
//}
////������RS485Fun0_Show
////�ӿڣ�RS485Fun1������ʾ
////˵����
////��ע��
//void RS485Fun2_Show(void)
//{
//}
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void RS485Fun2_SolidShow(void)
//{
//}
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void RS485Fun2_dynamicShow(void)
//{
//}
////*************************************************************************************************  RS485-3
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void RS485Fun3_KeyRule(void)
//{
//}
////������RS485Fun0_Show
////�ӿڣ�RS485Fun1������ʾ
////˵����
////��ע��
//void RS485Fun3_Show(void)
//{
//}
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void RS485Fun3_SolidShow(void)
//{
//}
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void RS485Fun3_dynamicShow(void)
//{
//}
////*************************************************************************************************  RS485-4
////������CANFun4_KeyRule
////�ӿڣ�CANFun0���水������
////˵����
////��ע��
//void RS485Fun4_KeyRule(void)
//{
//}
////������RS485Fun0_Show
////�ӿڣ�RS485Fun1������ʾ
////˵����
////��ע��
//void RS485Fun4_Show(void)
//{
//}
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void RS485Fun4_SolidShow(void)
//{
//}
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void RS485Fun4_dynamicShow(void)
//{
//}


//������RS485Dis00Message
//�ӿڣ�������ʾ485���ͱ�������
//˵����
//��ע��
void RS485Dis00Message(void)
{
		INT08U MsgLong = usDBpRS485Sent0Leng;
	  INT16U X = 80;
	  INT16U Y = 30;
	  INT16U* DataAdd = usDBcRS485Sent0DataA0;
	  INT08U i = 0;
		
		for(i = 0;i<MsgLong;i++)
		{
			  GUI_DispHexAt(*(DataAdd+i),X+i*30,Y,2);
		}
}
//������RS485Dis01Message
//�ӿڣ�������ʾ485���ܱ�������
//˵����
//��ע��
void RS485Dis01Message(void)
{
		INT08U MsgLong = SF_UC_LOW(*usDBhRS485RXBuff);  //ȡ��һ����-��־-�ĺ�8λ
	  INT16U X = 170;
	  INT16U Y = 70;
	  INT16U* DataAdd = (usDBhRS485RXBuff+1);
	  INT08U i = 0;
		
	  if(usDBmRS485Msg0Norma0)
	  {
//				for(i = 0;i<MsgLong;i++)
//				{
//						GUI_DispHexAt(*(DataAdd+i),X+i*30,Y,2);
//				}	
			  GUI_DispStringAt("  YES        ",X,Y);
  	}
		else
		{
		    GUI_DispStringAt("  NO         ",X,Y);
		
		}

}









//������CANDis00Message
//�ӿڣ�����CAN���ͱ�������
//˵����
//��ע��
void CANDis00Message(void)
{
		INT08U MsgLong = 8;
	  INT16U X = 80;
	  INT16U Y = 120;
	  INT16U* DataAdd = usDBcCANTTX0DataA0;
	  INT08U i = 0;
		
		for(i = 0;i<MsgLong;i++)
		{
			  GUI_DispHexAt(*(DataAdd+i),X+i*30,Y,2);
		}
}
//������CANDis01Message
//�ӿڣ�����CAN���ձ�������
//˵����
//��ע��
void CANDis01Message(void)
{
		INT08U MsgLong = 8;
	  INT16U X = 170;
	  INT16U Y = 120;
	  INT16U* DataAdd = usDBhCANRXBuff;
	  INT08U i = 0;
	  if(usDBmCANMsg0Norma0)
	  {		
//				for(i = 0;i<MsgLong;i++)
//				{
//						GUI_DispHexAt(*(DataAdd+i),X+i*30,Y,2);
//				}
			  GUI_DispStringAt("  YES        ",X,Y);
		}
		else
		{
		    GUI_DispStringAt("  NO         ",X,Y);
		
		}		
}









//*************************************************************************************************  CAN-0
//������RS485Fun0_Show
//�ӿڣ�RS485Fun1������ʾ
//˵����
//��ע�
void CANFun0_KeyRule(void)
{
}
//������RS485Fun0_Show
//�ӿڣ�RS485Fun1������ʾ
//˵����
//��ע��
void CANFun0_Show(void)
{
}
//������RS485Fun1_KeyRule
//�ӿڣ�RS485Fun1���水������
//˵����
//��ע��
void CANFun0_SolidShow(void)
{
}
//������RS485Fun1_KeyRule
//�ӿڣ�RS485Fun1���水������
//˵����
//��ע��
void CANFun0_dynamicShow(void)
{
}
////*************************************************************************************************  CAN-1
////������CANFun0_KeyRule
////�ӿڣ�CANFun0���水������
////˵����
////��ע��
//void CANFun1_KeyRule(void)
//{
//}
////������RS485Fun0_Show
////�ӿڣ�RS485Fun1������ʾ
////˵����
////��ע��
//void CANFun1_Show(void)
//{
//}
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void CANFun1_SolidShow(void)
//{
//}
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void CANFun1_dynamicShow(void)
//{
//}
////*************************************************************************************************  CAN-2
////������CANFun0_KeyRule
////�ӿڣ�CANFun0���水������
////˵����
////��ע��
//void CANFun2_KeyRule(void)
//{
//}
////������RS485Fun0_Show
////�ӿڣ�RS485Fun1������ʾ
////˵����
////��ע��
//void CANFun2_Show(void)
//{
//}
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void CANFun2_SolidShow(void)
//{
//}
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void CANFun2_dynamicShow(void)
//{
//}
////*************************************************************************************************  CAN-3
////������CANFun0_KeyRule
////�ӿڣ�CANFun0���水������
////˵����
////��ע��
//void CANFun3_KeyRule(void)
//{
//}
////������RS485Fun0_Show
////�ӿڣ�RS485Fun1������ʾ
////˵����
////��ע��
//void CANFun3_Show(void)
//{
//}
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void CANFun3_SolidShow(void)
//{
//}
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void CANFun3_dynamicShow(void)
//{
//}
////*************************************************************************************************  CAN-4
////������CANFun0_KeyRule
////�ӿڣ�CANFun0���水������
////˵����
////��ע��
//void CANFun4_KeyRule(void)
//{
//}
////������RS485Fun0_Show
////�ӿڣ�RS485Fun1������ʾ
////˵����
////��ע��
//void CANFun4_Show(void)
//{
//}
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void CANFun4_SolidShow(void)
//{
//}
////������RS485Fun1_KeyRule
////�ӿڣ�RS485Fun1���水������
////˵����
////��ע��
//void CANFun4_dynamicShow(void)
//{
//}
//*************************************************************************************************  CAN-END


