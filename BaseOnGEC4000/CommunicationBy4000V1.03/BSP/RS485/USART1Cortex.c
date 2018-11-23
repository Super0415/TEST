/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File SCI3Cortex.c                       */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   SCI3_GLOBALS
#include "TYPCortex.h"


#define START_TIME  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);TIM_Cmd(TIM2, ENABLE)
#define STOP_TIME   TIM_Cmd(TIM2, DISABLE);RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , DISABLE)

#define RS485SentEN     GPIO_SetBits(GPIOA,GPIO_Pin_8); //���뷢��ģʽ
#define RS485ReceiveEN  GPIO_ResetBits(GPIOA,GPIO_Pin_8); //�������ģʽ

  INT16U Time2Count;
  INT16U RS485OverTCount;  //485���ͽ������ڼ������
  INT16U RS485TXOverTCount;  //485�������ڼ������	
  INT16U RSOnTime0;
  INT16U RSOnTime1;
  INT16U RSOnTime2;
  INT16U RSOnTime3;
  INT16U RSOnTime4;
  INT16U RSOnTime5;
  INT08U RSOnTimeSign0;
  INT08U RSOnTimeSign1;
  INT08U RSOnTimeSign2;
  INT08U RSOnTimeSign3;
  INT08U RSOnTimeSign4;
  INT08U RSOnTimeSign5;	

MODBUS_MSG sUSART1ModbusMsg;  //485�շ����ݽṹ
INT08U USART1RxByteCnt;    //485�������ݳ��ȼ���
//������Ϣ-
//����Ϊ 0x01 0x02 0x03 0x04 0x05 0x06
//����Ϊ 0x11 0x12 0x13 0x14 0x15 0x16
INT08U USART1BUFFINFO; 

//������USART485_DataInit
//�ӿڣ�
//˵����
//��ע��
void USART485_DataInit(void)
{
    sUSART1ModbusMsg.ucAddr = usDBfRS485HostAddr = 0x01;   //��ʼ����ַ
	  sUSART1ModbusMsg.ucLeng = 0;
}
//������USART485_Init
//�ӿڣ�
//˵����
//��ע��
void USART485_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure; //����һ���ṹ�������������ʼ��GPIO	
    USART_InitTypeDef USART_InitStructure;  //�������ýṹ��
    //�ж����ȼ��ṹ��
    NVIC_InitTypeDef NVIC_InitStructure;	

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);     //�ܽ�ʱ��
     //���ڹ��� �ܽŸ���  //����ʱ��   
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO|RCC_APB2Periph_USART1,ENABLE);    
    //RCC_APB1  �ͺ������һ��                                                         //RCC_APB1 -APB1����
	                                                                                             //USART2 ����2
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;  //USART2-485  -  TX  ���
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;	 //���ø����������ģʽ               //���͹ܽ� ���ø����������
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
    GPIO_Init(GPIOA,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10; //USART2-485  -  RX  ����
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;	 //����ģʽ                      //���չܽ� ���ø���ģʽ
    GPIO_Init(GPIOA,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */
	
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8; //USART2-485  -  ���ƶ˿�  CS-485   --- ��˫��
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //�������ģʽ
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
    GPIO_Init(GPIOA,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */

    USART_InitStructure.USART_BaudRate = 9600;      //����������Ϊ9600	//������
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;        //���ݳ�8λ
    USART_InitStructure.USART_StopBits = USART_StopBits_1;             //1λֹͣλ
    USART_InitStructure.USART_Parity = USART_Parity_No;                    //��żʧ�� ��У��
    USART_InitStructure.USART_HardwareFlowControl =USART_HardwareFlowControl_None;    //Ӳ��������ʧ��  
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;     //�������ͺͽ���ģʽ
    USART_Init(USART1, &USART_InitStructure);          /* ��ʼ��USART1 */
	
    USART_Cmd(USART1, ENABLE);         //����1ʹ��
    USART_ClearFlag(USART1,USART_FLAG_TC);          //Ϊ�����ж϶����ԣ�������жϱ�־     USART_FLAG_TC������ɱ�־λ	
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);     //�򿪴���1���жϣ�   ʹ�ܻ���ʧ��ָ����USART�ж�         USART_IT_RXNE�����ж�

	  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                           //����	
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;   //�жϺ������              
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //��ռ���ȼ�
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;           //��Ӧ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //ʹ��
    NVIC_Init(&NVIC_InitStructure);	

    GPIO_ResetBits(GPIOA,GPIO_Pin_8);                                    //�����ƶ˿����㣬��ʱȷ��485���ڽ���״̬	
}
//������USART485_Tim2_Init
//�ӿڣ�
//˵����
//��ע��
void USART485_Tim2_Init(void)
{
	  TIM2_Configuration();
    TIM2_NVIC_Configuration();
    START_TIME;
}
//������TIM2_NVIC_Configuration
//�ӿڣ�
//˵����
//��ע��
void TIM2_NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure; 
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);  													
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;	  
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}
//������TIM2_Configuration
//�ӿڣ�
//˵����
//��ע��TIM_Period--1000   TIM_Prescaler--71 -->�ж�����Ϊ1ms*/
void TIM2_Configuration(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);
    TIM_DeInit(TIM2);
    TIM_TimeBaseStructure.TIM_Period=1000;		 								/* �Զ���װ�ؼĴ������ڵ�ֵ(����ֵ) */
    /* �ۼ� TIM_Period��Ƶ�ʺ����һ�����»����ж� */
    TIM_TimeBaseStructure.TIM_Prescaler= (72 - 1);				    /* ʱ��Ԥ��Ƶ�� 72M/72 */
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 		/* ������Ƶ */
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; /* ���ϼ���ģʽ */
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);							    		/* �������жϱ�־ */
    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
    TIM_Cmd(TIM2, ENABLE);																		/* ����ʱ�� */
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , DISABLE);		/*�ȹرյȴ�ʹ��*/    
}

//������SCI1TaskLoop
//�ӿڣ�USART1����ѭ��
//˵����
//��ע��
void SCI1TaskLoop(void)
{
	  INT08U ucTmp;
    INT08U Data16uleng,usBegin;
	  INT16U Correct = 0;	
	
    while(1)
    {
		    TESTZCnum[4]++;
        (void)OSTaskSuspend(OS_PRIO_SELF);
			  if(!usDBfRS485SysMode && (RSRXData == USART1BUFFINFO>4)) //����ģʽ �����Ѿ�������Ϣ
				{
					ucTmp = SFProcessHostRxModMsg(&sUSART1ModbusMsg);
				}
			  else if(usDBfRS485SysMode)  //�ӻ����շ�������
			  {
			      ucTmp = SFProcessRxModMsg(&sUSART1ModbusMsg);
			  }
			  else{}
			
			
			
				if(usDBfRS485EnSentData0 && RSOnTimeSign0) //��0��  
				{   
						RSOnTimeSign0 = 0;
					  sUSART1ModbusMsg.ucAddr = usDBfRS485HostAddr;
					  sUSART1ModbusMsg.ucLeng = usDBpRS485Sent0Leng;
					  
						USART1SentData(usDBpRS485Sent0Leng,usDBcRS485Sent0DataA0,usDBfRS485EnableCRC);
					
				
					  Correct = Data16uleng | SF_RS485TX_Color1;
					

					  SFUSARTRecordTxMesure(usDBcRS485Sent0DataA0,usDBpRS485Sent0Leng,Correct);
					  usDBhRS485RXToLeng ++;
				}
//				if(usDBfRS485EnSentData1 && RSOnTimeSign1) //��1��
//				{
//						RSOnTimeSign1 = 0;
//					  USART1SentData(usDBpRS485Sent1Leng,usDBcRS485Sent1DataA0,usDBfRS485EnableCRC);
//				}
//				if(usDBfRS485EnSentData2 && RSOnTimeSign2) //��2��
//				{
//						RSOnTimeSign2 = 0;
//					  USART1SentData(usDBpRS485Sent2Leng,usDBcRS485Sent2DataA0,usDBfRS485EnableCRC);
//				}
//				if(usDBfRS485EnSentData3 && RSOnTimeSign3) //��3��
//				{
//						RSOnTimeSign3 = 0;
//					USART1SentData(usDBpRS485Sent3Leng,usDBcRS485Sent3DataA0,usDBfRS485EnableCRC);
//				}
//				if(usDBfRS485EnSentData4 && RSOnTimeSign4) //��4��
//				{
//						RSOnTimeSign4 = 0;
//					  USART1SentData(usDBpRS485Sent4Leng,usDBcRS485Sent4DataA0,usDBfRS485EnableCRC);
//				}
//				if(usDBfRS485EnSentData5 && RSOnTimeSign5) //��5��
//				{
//						RSOnTimeSign5 = 0;
//					  USART1SentData(usDBpRS485Sent5Leng,usDBcRS485Sent5DataA0,usDBfRS485EnableCRC);
//				}

				
    }
}
//������USART1SentData
//�ӿڣ�USART1��������
//˵����
//��ע��
void USART1SentData(INT16U Length,INT16U * DataAddrese,INT16U CRCCMD)
{
	  INT08U i = 0;
	  INT16U Temp = 0;
	  for(i = 0;i < Length;i++)
	  {
			  RS485SentEN; //���뷢��ģʽ
			  Temp = (INT16U)*(DataAddrese+i);
			  //USART_ClearFlag(USART1,USART_FLAG_TC); 
			  if(USART_GetITStatus(USART1,USART_FLAG_TC)!=Bit_SET)
			  {
				    USART_SendData(USART1,Temp);	 //��������
				    while (USART_GetFlagStatus(USART1,USART_FLAG_TC) !=SET);//��ѯֱ�������������	
			  }
			  RS485ReceiveEN;	//�������ģʽ	
	  }

}
//������Tim2IntHook
//�ӿڣ�TIM2�ж�
//˵����
//��ע��
void Tim2IntHook(void)
{	
	if ( TIM_GetITStatus(TIM2 , TIM_IT_Update) != RESET ) //1ms����ж�
	{	
		TIM_ClearITPendingBit(TIM2 , TIM_FLAG_Update);    
    Time2Count++;
		RS485OverTCount++;
		RS485TXOverTCount++;
		
		if((USART1RxByteCnt) && (RS485OverTCount>10))   //485��ʱ���
		{
		    sUSART1ModbusMsg.ucLeng = USART1RxByteCnt;
			  USART1RxByteCnt = 0;  //����������ݼ�¼�ĳ���
			  RS485TXOverTCount = 0; //���ͼ����ʱ���������
			  USART1BUFFINFO = RSRXData;
			  (void)OSIntTaskResume(FW_TASK_PRIO_SCI1); //����SCI1
		}
		else if((!usDBfRS485SysMode)&&(RS485TXOverTCount>10))   //����ģʽ�·��ͼ����ʱ
		{
		    USART1BUFFINFO = RSTXDataOver;  //����ģʽ�� ��ʱʱ��ϵͳ״̬���ڷ�������
		}
		else
		{
		    //USART1BUFFINFO = RSTXData;  //�ӻ�ģʽ�� ��ʱʱ��ϵͳ״̬���ڽ�������
		}
	}		
  if((!USART1RxByteCnt)&& usDBfRS485EnSentData0==1 &&((0 == USART1BUFFINFO>>4)||(RSTXDataOver == USART1BUFFINFO))&& (INT16U)(Time2Count-RSOnTime0)>usDBpRS485Sent0delay) //��0�����ͱ���
	{
		  RSOnTime0 = Time2Count;
		  RSOnTimeSign0 = 1;
		  USART1BUFFINFO = RSTXData0;
	    (void)OSIntTaskResume(FW_TASK_PRIO_SCI1); //����SCI1
		
	}
  if((!USART1RxByteCnt)&& usDBfRS485EnSentData1==1 &&((0 == USART1BUFFINFO>>4)||(RSTXDataOver == USART1BUFFINFO))&& (INT16U)(Time2Count-RSOnTime1)>usDBpRS485Sent1delay) //��1�����ͱ���
	{
		  RSOnTime1 = Time2Count;
		  RSOnTimeSign1 = 1;
		  USART1BUFFINFO = RSTXData1;
	    (void)OSIntTaskResume(FW_TASK_PRIO_SCI1); //����SCI1
	}
  if((!USART1RxByteCnt)&& usDBfRS485EnSentData2==1 &&((0 == USART1BUFFINFO>>4)||(RSTXDataOver == USART1BUFFINFO))&& (INT16U)(Time2Count-RSOnTime2)>usDBpRS485Sent2delay) //��2�����ͱ���
	{
		  RSOnTime2 = Time2Count;
		  RSOnTimeSign2 = 1;
		  USART1BUFFINFO = RSTXData2;
	    (void)OSIntTaskResume(FW_TASK_PRIO_SCI1); //����SCI1
	}
  if((!USART1RxByteCnt)&& usDBfRS485EnSentData3==1 &&((0 == USART1BUFFINFO>>4)||(RSTXDataOver == USART1BUFFINFO))&& (INT16U)(Time2Count-RSOnTime3)>usDBpRS485Sent3delay) //��3�����ͱ���
	{
		  RSOnTime3 = Time2Count;
		  RSOnTimeSign3 = 1;
		  USART1BUFFINFO = RSTXData3;
	    (void)OSIntTaskResume(FW_TASK_PRIO_SCI1); //����SCI1
	}
  if((!USART1RxByteCnt)&& usDBfRS485EnSentData4==1 &&((0 == USART1BUFFINFO>>4)||(RSTXDataOver == USART1BUFFINFO))&& (INT16U)(Time2Count-RSOnTime4)>usDBpRS485Sent4delay) //��4�����ͱ���
	{
		  RSOnTime4 = Time2Count;
		  RSOnTimeSign4 = 1;
		  USART1BUFFINFO = RSTXData4;
	    (void)OSIntTaskResume(FW_TASK_PRIO_SCI1); //����SCI1
	}
  if((!USART1RxByteCnt)&& usDBfRS485EnSentData5==1 &&((0 == USART1BUFFINFO>>4)||(RSTXDataOver == USART1BUFFINFO))&& (INT16U)(Time2Count-RSOnTime5)>usDBpRS485Sent5delay) //��5�����ͱ���
	{
		  RSOnTime5 = Time2Count;
		  RSOnTimeSign5 = 1;
		  USART1BUFFINFO = RSTXData5;
	    (void)OSIntTaskResume(FW_TASK_PRIO_SCI1); //����SCI1
	}	
	
	
}

void SCI1RxIntHook(void)
{
	  INT08U buff = 0;
	
    USART_ClearFlag(USART1,USART_FLAG_TC);  //�������1�жϱ�־λ   USART_FLAG_TC������ɱ�־λ
    if(USART_GetITStatus(USART1,USART_IT_RXNE)!=Bit_RESET)//���ָ����USART�жϷ������   USART_IT_RXNE�����ж�
    {
			  RS485OverTCount = 0;  //����һ�Σ����һ�� 485���ͽ������ڼ������
        buff=USART_ReceiveData(USART1);	
			  if(USART1RxByteCnt == 0 &&(((usDBfRS485SysMode==0)&&(0x01/*usDBfRS485HostAddr*/ == buff))||((usDBfRS485SysMode==1)&&((usDBfRS485Monitor0Addr == buff) ||(usDBfRS485Monitor1Addr == buff) ||(usDBfRS485Monitor2Addr == buff)))))
			  {
			      sUSART1ModbusMsg.aData[0] = buff;
				    USART1RxByteCnt = 1;  //��ַ��¼�� �� 0 λ ,�¸�����������һ��
					  USART1BUFFINFO = RSRXData;
					  RS485TXOverTCount = 0; //����ģʽ�·��ͼ������
					  
			  }
			  else if(USART1RxByteCnt)
			  {
			      sUSART1ModbusMsg.aData[USART1RxByteCnt++] = buff;
			  }
			  else
			  {
			      //��ȡ���ݴ���
			  }

	  }	

}

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
