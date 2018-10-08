/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File TestShow.c                         */
/*                            By: Fengzc                                */
/*                             2018-05-17                               */
/* ******************************************************************** */
#include "TestShow.h"
#include "TYPCortex.h"




/*  Ñ¡È¡µÄ¹¦ÄÜÏî
  0-0 485 µÚ1¸öµØÖ·½çÃæ
	1-0 485 µÚ2¸öµØÖ·½çÃæ
	2-0 485 µÚ3¸öµØÖ·½çÃæ
	3-0 CAN ÏÔÊ¾½çÃæ
*/
// µÚ1¸öÔªËØÎª ½çÃæÖÖÀà  µÚ2¸öÔªËØÎª ÖÖÀàÏÂµÄ·Ö½çÃæ  µÚ3¸öÔªËØÎª ·Ö½çÃæÏÂµÄÊý¾ÝÐòºÅ
INT08U ForwardPage_Num[3];    //½«ÒªÏÔÊ¾µÄ½çÃæ  //°´¼üÖÐ¸³Öµ
INT08U NowPage_Num[3];        //µ±Ç°ÏÔÊ¾µÄ½çÃæ  //ÏÔÊ¾ÖÐ¸³Öµ
INT08U HistoryPage_Num[3];    //ÀúÊ·¼ÇÂ¼µÄ½çÃæ  //°´¼üÖÐ¸³Öµ
INT08U EditPageEnable;           //±à¼­µ±Ç°½çÃæÊ¹ÄÜ
INT08U EditDATAEnable[2];        //±à¼­µ±Ç°½çÃæÖ¸¶¨Êý¾ÝÊ¹ÄÜ  //0-Êý¾ÝÔÚ´Ë½çÃæÐòºÅ  1-ÊÇ·ñ±à¼­Ê¹ÄÜ


INT08U DisSolidTips[SumSolidState+1] = {0};   //¾²Ì¬ÏÔÊ¾Î»ÖÃ
INT08U DisdynamicTips[SumSolidWord+1] = {0}; //¶¯Ì¬ÏÔÊ¾Î»ÖÃ


const DisFontStruct DisFontStrings[SumSolidWord] = 
{
/*   0 */    {{"RS485 -- "},{"RS485-TEST"}},
/*   1 */    {{"±¨ÎÄ:"},{"Message:"}},
/*   2 */    {{"CAN ----"},{"2222"}},
/*   3 */    {{"3333"},{"3333"}},

};

SolidStruct  SolidState[SumSolidState] = 
{
	          //ÏÔÊ¾Ê¹ÄÜ----0¼¶Î»ÖÃ--------1¼¶Î»ÖÃ---- -Pic_X-Pic_Y--Í¼Æ¬µØÖ·---TXT_X--TXT_Y----×ÖÌå------------------ÎÄ±¾Î»ÖÃ-----------------------¹¦ÄÜº¯Êý
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
	          //ÏÔÊ¾Ê¹ÄÜ-------0¼¶Î»ÖÃ--------1¼¶Î»ÖÃ------TXT_X--TXT_Y----×ÖÌå--------Êý¾ÝÌØÊâ¹¦ÄÜ-----Êý¾ÝÖ¸ÕëÎ»ÖÃ----------------¹¦ÄÜº¯Êý
/*000*/   {  FunDISable,   RS485AddPage0,  RS485Fun0   ,     0,   0,   &GUI_FontHZ24,       0,         NULL,        RS485Dis00Message,         NULL},  //485·¢ËÍ±¨ÎÄ
/*000*/   {  FunENable,   RS485AddPage0,  RS485Fun0   ,     0,   0,   &GUI_FontHZ24,       0,         NULL,        RS485Dis01Message,         NULL},  //µÚÒ»Ìõ±¨ÎÄ
/*000*/   {  FunDISable,   RS485AddPage0,  RS485Fun0   ,     0,   0,   &GUI_FontHZ24,       0,         NULL,        CANDis00Message,         NULL},  //485·¢ËÍ±¨ÎÄ
/*000*/   {  FunENable,   RS485AddPage0,  RS485Fun0   ,     0,   0,   &GUI_FontHZ24,       0,         NULL,        CANDis01Message,         NULL},  //µÚÒ»Ìõ±¨ÎÄ
};


//º¯Êý£ºTestShowTask
//½Ó¿Ú£ºÏÔÊ¾ÈÎÎñ
//ËµÃ÷£º
//±¸×¢£º
void TestShowTask(void)
{
	  DBKeyCheck();
	
    ShowScreen();
}

//º¯Êý£ºDBKeyCheck
//½Ó¿Ú£º¸ù¾Ýµ±Ç°½çÃæÅÐ¶Ï°´¼ü×÷ÓÃ
//ËµÃ÷£º
//±¸×¢£º
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
//º¯Êý£ºShowScreen
//½Ó¿Ú£º¸ù¾Ýµ±Ç°½çÃæÅÐ¶ÏÏÔÊ¾ÄÚÈÝ
//ËµÃ÷£º
//±¸×¢£º
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
//º¯Êý£ºRS485Fun0_KeyRule
//½Ó¿Ú£ºRS485Fun0½çÃæ°´¼ü¹æÔò
//ËµÃ÷£º
//±¸×¢£º
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
//º¯Êý£ºRS485Fun0_Show
//½Ó¿Ú£ºRS485Fun1½çÃæÏÔÊ¾
//ËµÃ÷£º
//±¸×¢£º
void RS485Fun0_Show(void)
{
    if(ForwardPage_Num[0] != NowPage_Num[0])
    {
        NowPage_Num[0] = ForwardPage_Num[0];    //¼ÇÂ¼È¨ÏÞ0½çÃæÖµ
    }
    if(ForwardPage_Num[1] != NowPage_Num[1])  //
    {
				NowPage_Num[1] = ForwardPage_Num[1];  // ¼ÇÂ¼È¨ÏÞ·Ö½çÃæ
				RS485Fun0_SolidShow(); 
    }
    
    RS485Fun0_dynamicShow();// 

}
//º¯Êý£ºRS485Fun0_SolidShow
//½Ó¿Ú£ºRS485Fun1½çÃæ¾²Ì¬ÏÔÊ¾
//ËµÃ÷£º
//±¸×¢£º

void RS485Fun0_SolidShow(void)
{
	  INT08U i = 0;
	  INT08U Temp = 0;
    GUI_SetBkColor(LCD_DisBKColor);
    GUI_SetColor(LCD_DisColor);
		RS485Fun0_DisCheckSolid(DisSolidTips,DisdynamicTips);  //¼ÇÂ¼´Ë´¦½çÃæµÄ¾²Ì¬Êý¾Ý ÒÔ¼° ¶¯Ì¬Êý¾Ý
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
//º¯Êý£ºRS485Fun0_dynamicShow
//½Ó¿Ú£ºRS485Fun1½çÃæÅÐ¶ÏÏÔÊ¾ÄÚÈÝ
//ËµÃ÷£º
//±¸×¢£º
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
		Count = 0;  //¼ÆÊýÖµÇåÁã
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
//º¯Êý£ºRS485Fun0_dynamicShow
//½Ó¿Ú£ºRS485Fun1½çÃæ¶¯Ì¬ÏÔÊ¾
//ËµÃ÷£º
//±¸×¢£º
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
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void RS485Fun1_KeyRule(void)
//{
//}
////º¯Êý£ºRS485Fun0_Show
////½Ó¿Ú£ºRS485Fun1½çÃæÏÔÊ¾
////ËµÃ÷£º
////±¸×¢£º
//void RS485Fun1_Show(void)
//{
//}
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void RS485Fun1_SolidShow(void)
//{
//}
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void RS485Fun1_dynamicShow(void)
//{
//}
////*************************************************************************************************  RS485-2
////º¯Êý£ºRS485Fun2_KeyRule
////½Ó¿Ú£ºRS485Fun2½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void RS485Fun2_KeyRule(void)
//{
//}
////º¯Êý£ºRS485Fun0_Show
////½Ó¿Ú£ºRS485Fun1½çÃæÏÔÊ¾
////ËµÃ÷£º
////±¸×¢£º
//void RS485Fun2_Show(void)
//{
//}
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void RS485Fun2_SolidShow(void)
//{
//}
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void RS485Fun2_dynamicShow(void)
//{
//}
////*************************************************************************************************  RS485-3
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void RS485Fun3_KeyRule(void)
//{
//}
////º¯Êý£ºRS485Fun0_Show
////½Ó¿Ú£ºRS485Fun1½çÃæÏÔÊ¾
////ËµÃ÷£º
////±¸×¢£º
//void RS485Fun3_Show(void)
//{
//}
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void RS485Fun3_SolidShow(void)
//{
//}
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void RS485Fun3_dynamicShow(void)
//{
//}
////*************************************************************************************************  RS485-4
////º¯Êý£ºCANFun4_KeyRule
////½Ó¿Ú£ºCANFun0½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void RS485Fun4_KeyRule(void)
//{
//}
////º¯Êý£ºRS485Fun0_Show
////½Ó¿Ú£ºRS485Fun1½çÃæÏÔÊ¾
////ËµÃ÷£º
////±¸×¢£º
//void RS485Fun4_Show(void)
//{
//}
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void RS485Fun4_SolidShow(void)
//{
//}
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void RS485Fun4_dynamicShow(void)
//{
//}


//º¯Êý£ºRS485Dis00Message
//½Ó¿Ú£ºÓÃÓÚÏÔÊ¾485·¢ËÍ±¨ÎÄÊý¾Ý
//ËµÃ÷£º
//±¸×¢£º
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
//º¯Êý£ºRS485Dis01Message
//½Ó¿Ú£ºÓÃÓÚÏÔÊ¾485½ÓÊÜ±¨ÎÄÊý¾Ý
//ËµÃ÷£º
//±¸×¢£º
void RS485Dis01Message(void)
{
		INT08U MsgLong = SF_UC_LOW(*usDBhRS485RXBuff);  //È¡µÚÒ»¸öÊý-±êÖ¾-µÄºó8Î»
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









//º¯Êý£ºCANDis00Message
//½Ó¿Ú£ºÓÃÓÚCAN·¢ËÍ±¨ÎÄÊý¾Ý
//ËµÃ÷£º
//±¸×¢£º
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
//º¯Êý£ºCANDis01Message
//½Ó¿Ú£ºÓÃÓÚCAN½ÓÊÕ±¨ÎÄÊý¾Ý
//ËµÃ÷£º
//±¸×¢£º
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
//º¯Êý£ºRS485Fun0_Show
//½Ó¿Ú£ºRS485Fun1½çÃæÏÔÊ¾
//ËµÃ÷£º
//±¸×¢£
void CANFun0_KeyRule(void)
{
}
//º¯Êý£ºRS485Fun0_Show
//½Ó¿Ú£ºRS485Fun1½çÃæÏÔÊ¾
//ËµÃ÷£º
//±¸×¢£º
void CANFun0_Show(void)
{
}
//º¯Êý£ºRS485Fun1_KeyRule
//½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
//ËµÃ÷£º
//±¸×¢£º
void CANFun0_SolidShow(void)
{
}
//º¯Êý£ºRS485Fun1_KeyRule
//½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
//ËµÃ÷£º
//±¸×¢£º
void CANFun0_dynamicShow(void)
{
}
////*************************************************************************************************  CAN-1
////º¯Êý£ºCANFun0_KeyRule
////½Ó¿Ú£ºCANFun0½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void CANFun1_KeyRule(void)
//{
//}
////º¯Êý£ºRS485Fun0_Show
////½Ó¿Ú£ºRS485Fun1½çÃæÏÔÊ¾
////ËµÃ÷£º
////±¸×¢£º
//void CANFun1_Show(void)
//{
//}
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void CANFun1_SolidShow(void)
//{
//}
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void CANFun1_dynamicShow(void)
//{
//}
////*************************************************************************************************  CAN-2
////º¯Êý£ºCANFun0_KeyRule
////½Ó¿Ú£ºCANFun0½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void CANFun2_KeyRule(void)
//{
//}
////º¯Êý£ºRS485Fun0_Show
////½Ó¿Ú£ºRS485Fun1½çÃæÏÔÊ¾
////ËµÃ÷£º
////±¸×¢£º
//void CANFun2_Show(void)
//{
//}
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void CANFun2_SolidShow(void)
//{
//}
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void CANFun2_dynamicShow(void)
//{
//}
////*************************************************************************************************  CAN-3
////º¯Êý£ºCANFun0_KeyRule
////½Ó¿Ú£ºCANFun0½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void CANFun3_KeyRule(void)
//{
//}
////º¯Êý£ºRS485Fun0_Show
////½Ó¿Ú£ºRS485Fun1½çÃæÏÔÊ¾
////ËµÃ÷£º
////±¸×¢£º
//void CANFun3_Show(void)
//{
//}
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void CANFun3_SolidShow(void)
//{
//}
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void CANFun3_dynamicShow(void)
//{
//}
////*************************************************************************************************  CAN-4
////º¯Êý£ºCANFun0_KeyRule
////½Ó¿Ú£ºCANFun0½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void CANFun4_KeyRule(void)
//{
//}
////º¯Êý£ºRS485Fun0_Show
////½Ó¿Ú£ºRS485Fun1½çÃæÏÔÊ¾
////ËµÃ÷£º
////±¸×¢£º
//void CANFun4_Show(void)
//{
//}
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void CANFun4_SolidShow(void)
//{
//}
////º¯Êý£ºRS485Fun1_KeyRule
////½Ó¿Ú£ºRS485Fun1½çÃæ°´¼ü¹æÔò
////ËµÃ÷£º
////±¸×¢£º
//void CANFun4_dynamicShow(void)
//{
//}
//*************************************************************************************************  CAN-END


