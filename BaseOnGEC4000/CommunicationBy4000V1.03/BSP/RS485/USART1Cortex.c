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

#define RS485SentEN     GPIO_SetBits(GPIOA,GPIO_Pin_8); //进入发送模式
#define RS485ReceiveEN  GPIO_ResetBits(GPIOA,GPIO_Pin_8); //进入接收模式

  INT16U Time2Count;
  INT16U RS485OverTCount;  //485发送接收周期间隔计数
  INT16U RS485TXOverTCount;  //485发送周期间隔计数	
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

MODBUS_MSG sUSART1ModbusMsg;  //485收发数据结构
INT08U USART1RxByteCnt;    //485接收数据长度计数
//数据信息-
//发送为 0x01 0x02 0x03 0x04 0x05 0x06
//接收为 0x11 0x12 0x13 0x14 0x15 0x16
INT08U USART1BUFFINFO; 

//函数：USART485_DataInit
//接口：
//说明：
//备注：
void USART485_DataInit(void)
{
    sUSART1ModbusMsg.ucAddr = usDBfRS485HostAddr = 0x01;   //初始化地址
	  sUSART1ModbusMsg.ucLeng = 0;
}
//函数：USART485_Init
//接口：
//说明：
//备注：
void USART485_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure; //声明一个结构体变量，用来初始化GPIO	
    USART_InitTypeDef USART_InitStructure;  //串口配置结构体
    //中断优先级结构体
    NVIC_InitTypeDef NVIC_InitStructure;	

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);     //管脚时钟
     //串口功能 管脚复用  //串口时钟   
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO|RCC_APB2Periph_USART1,ENABLE);    
    //RCC_APB1  和后面参数一致                                                         //RCC_APB1 -APB1总线
	                                                                                             //USART2 串口2
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;  //USART2-485  -  TX  输出
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;	 //设置复用推挽输出模式               //发送管脚 配置复用推挽输出
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
    GPIO_Init(GPIOA,&GPIO_InitStructure); 	   /* 初始化GPIO */

    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10; //USART2-485  -  RX  输入
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;	 //浮空模式                      //接收管脚 配置浮空模式
    GPIO_Init(GPIOA,&GPIO_InitStructure); 	   /* 初始化GPIO */
	
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8; //USART2-485  -  控制端口  CS-485   --- 半双工
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //推挽输出模式
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
    GPIO_Init(GPIOA,&GPIO_InitStructure); 	   /* 初始化GPIO */

    USART_InitStructure.USART_BaudRate = 9600;      //波特率设置为9600	//波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;        //数据长8位
    USART_InitStructure.USART_StopBits = USART_StopBits_1;             //1位停止位
    USART_InitStructure.USART_Parity = USART_Parity_No;                    //奇偶失能 无校验
    USART_InitStructure.USART_HardwareFlowControl =USART_HardwareFlowControl_None;    //硬件流控制失能  
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;     //开启发送和接受模式
    USART_Init(USART1, &USART_InitStructure);          /* 初始化USART1 */
	
    USART_Cmd(USART1, ENABLE);         //串口1使能
    USART_ClearFlag(USART1,USART_FLAG_TC);          //为避免中断二义性，先清空中断标志     USART_FLAG_TC发送完成标志位	
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);     //打开串口1的中断，   使能或者失能指定的USART中断         USART_IT_RXNE接收中断

	  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                           //分组	
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;   //中断函数入口              
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //抢占优先级
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;           //响应优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //使能
    NVIC_Init(&NVIC_InitStructure);	

    GPIO_ResetBits(GPIOA,GPIO_Pin_8);                                    //将控制端口清零，此时确保485处于接收状态	
}
//函数：USART485_Tim2_Init
//接口：
//说明：
//备注：
void USART485_Tim2_Init(void)
{
	  TIM2_Configuration();
    TIM2_NVIC_Configuration();
    START_TIME;
}
//函数：TIM2_NVIC_Configuration
//接口：
//说明：
//备注：
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
//函数：TIM2_Configuration
//接口：
//说明：
//备注：TIM_Period--1000   TIM_Prescaler--71 -->中断周期为1ms*/
void TIM2_Configuration(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);
    TIM_DeInit(TIM2);
    TIM_TimeBaseStructure.TIM_Period=1000;		 								/* 自动重装载寄存器周期的值(计数值) */
    /* 累计 TIM_Period个频率后产生一个更新或者中断 */
    TIM_TimeBaseStructure.TIM_Prescaler= (72 - 1);				    /* 时钟预分频数 72M/72 */
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 		/* 采样分频 */
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; /* 向上计数模式 */
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);							    		/* 清除溢出中断标志 */
    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
    TIM_Cmd(TIM2, ENABLE);																		/* 开启时钟 */
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , DISABLE);		/*先关闭等待使用*/    
}

//函数：SCI1TaskLoop
//接口：USART1任务循环
//说明：
//备注：
void SCI1TaskLoop(void)
{
	  INT08U ucTmp;
    INT08U Data16uleng,usBegin;
	  INT16U Correct = 0;	
	
    while(1)
    {
		    TESTZCnum[4]++;
        (void)OSTaskSuspend(OS_PRIO_SELF);
			  if(!usDBfRS485SysMode && (RSRXData == USART1BUFFINFO>4)) //主机模式 ，且已经接收信息
				{
					ucTmp = SFProcessHostRxModMsg(&sUSART1ModbusMsg);
				}
			  else if(usDBfRS485SysMode)  //从机接收返回数据
			  {
			      ucTmp = SFProcessRxModMsg(&sUSART1ModbusMsg);
			  }
			  else{}
			
			
			
				if(usDBfRS485EnSentData0 && RSOnTimeSign0) //第0条  
				{   
						RSOnTimeSign0 = 0;
					  sUSART1ModbusMsg.ucAddr = usDBfRS485HostAddr;
					  sUSART1ModbusMsg.ucLeng = usDBpRS485Sent0Leng;
					  
						USART1SentData(usDBpRS485Sent0Leng,usDBcRS485Sent0DataA0,usDBfRS485EnableCRC);
					
				
					  Correct = Data16uleng | SF_RS485TX_Color1;
					

					  SFUSARTRecordTxMesure(usDBcRS485Sent0DataA0,usDBpRS485Sent0Leng,Correct);
					  usDBhRS485RXToLeng ++;
				}
//				if(usDBfRS485EnSentData1 && RSOnTimeSign1) //第1条
//				{
//						RSOnTimeSign1 = 0;
//					  USART1SentData(usDBpRS485Sent1Leng,usDBcRS485Sent1DataA0,usDBfRS485EnableCRC);
//				}
//				if(usDBfRS485EnSentData2 && RSOnTimeSign2) //第2条
//				{
//						RSOnTimeSign2 = 0;
//					  USART1SentData(usDBpRS485Sent2Leng,usDBcRS485Sent2DataA0,usDBfRS485EnableCRC);
//				}
//				if(usDBfRS485EnSentData3 && RSOnTimeSign3) //第3条
//				{
//						RSOnTimeSign3 = 0;
//					USART1SentData(usDBpRS485Sent3Leng,usDBcRS485Sent3DataA0,usDBfRS485EnableCRC);
//				}
//				if(usDBfRS485EnSentData4 && RSOnTimeSign4) //第4条
//				{
//						RSOnTimeSign4 = 0;
//					  USART1SentData(usDBpRS485Sent4Leng,usDBcRS485Sent4DataA0,usDBfRS485EnableCRC);
//				}
//				if(usDBfRS485EnSentData5 && RSOnTimeSign5) //第5条
//				{
//						RSOnTimeSign5 = 0;
//					  USART1SentData(usDBpRS485Sent5Leng,usDBcRS485Sent5DataA0,usDBfRS485EnableCRC);
//				}

				
    }
}
//函数：USART1SentData
//接口：USART1发送数据
//说明：
//备注：
void USART1SentData(INT16U Length,INT16U * DataAddrese,INT16U CRCCMD)
{
	  INT08U i = 0;
	  INT16U Temp = 0;
	  for(i = 0;i < Length;i++)
	  {
			  RS485SentEN; //进入发送模式
			  Temp = (INT16U)*(DataAddrese+i);
			  //USART_ClearFlag(USART1,USART_FLAG_TC); 
			  if(USART_GetITStatus(USART1,USART_FLAG_TC)!=Bit_SET)
			  {
				    USART_SendData(USART1,Temp);	 //发送数据
				    while (USART_GetFlagStatus(USART1,USART_FLAG_TC) !=SET);//轮询直到发送数据完毕	
			  }
			  RS485ReceiveEN;	//进入接收模式	
	  }

}
//函数：Tim2IntHook
//接口：TIM2中断
//说明：
//备注：
void Tim2IntHook(void)
{	
	if ( TIM_GetITStatus(TIM2 , TIM_IT_Update) != RESET ) //1ms溢出中断
	{	
		TIM_ClearITPendingBit(TIM2 , TIM_FLAG_Update);    
    Time2Count++;
		RS485OverTCount++;
		RS485TXOverTCount++;
		
		if((USART1RxByteCnt) && (RS485OverTCount>10))   //485超时检测
		{
		    sUSART1ModbusMsg.ucLeng = USART1RxByteCnt;
			  USART1RxByteCnt = 0;  //清除接收数据记录的长度
			  RS485TXOverTCount = 0; //发送间隔超时检测重新起动
			  USART1BUFFINFO = RSRXData;
			  (void)OSIntTaskResume(FW_TASK_PRIO_SCI1); //启动SCI1
		}
		else if((!usDBfRS485SysMode)&&(RS485TXOverTCount>10))   //主机模式下发送间隔超时
		{
		    USART1BUFFINFO = RSTXDataOver;  //主机模式下 超时时是系统状态处于发送数据
		}
		else
		{
		    //USART1BUFFINFO = RSTXData;  //从机模式下 超时时是系统状态处于接收数据
		}
	}		
  if((!USART1RxByteCnt)&& usDBfRS485EnSentData0==1 &&((0 == USART1BUFFINFO>>4)||(RSTXDataOver == USART1BUFFINFO))&& (INT16U)(Time2Count-RSOnTime0)>usDBpRS485Sent0delay) //第0条发送报文
	{
		  RSOnTime0 = Time2Count;
		  RSOnTimeSign0 = 1;
		  USART1BUFFINFO = RSTXData0;
	    (void)OSIntTaskResume(FW_TASK_PRIO_SCI1); //启动SCI1
		
	}
  if((!USART1RxByteCnt)&& usDBfRS485EnSentData1==1 &&((0 == USART1BUFFINFO>>4)||(RSTXDataOver == USART1BUFFINFO))&& (INT16U)(Time2Count-RSOnTime1)>usDBpRS485Sent1delay) //第1条发送报文
	{
		  RSOnTime1 = Time2Count;
		  RSOnTimeSign1 = 1;
		  USART1BUFFINFO = RSTXData1;
	    (void)OSIntTaskResume(FW_TASK_PRIO_SCI1); //启动SCI1
	}
  if((!USART1RxByteCnt)&& usDBfRS485EnSentData2==1 &&((0 == USART1BUFFINFO>>4)||(RSTXDataOver == USART1BUFFINFO))&& (INT16U)(Time2Count-RSOnTime2)>usDBpRS485Sent2delay) //第2条发送报文
	{
		  RSOnTime2 = Time2Count;
		  RSOnTimeSign2 = 1;
		  USART1BUFFINFO = RSTXData2;
	    (void)OSIntTaskResume(FW_TASK_PRIO_SCI1); //启动SCI1
	}
  if((!USART1RxByteCnt)&& usDBfRS485EnSentData3==1 &&((0 == USART1BUFFINFO>>4)||(RSTXDataOver == USART1BUFFINFO))&& (INT16U)(Time2Count-RSOnTime3)>usDBpRS485Sent3delay) //第3条发送报文
	{
		  RSOnTime3 = Time2Count;
		  RSOnTimeSign3 = 1;
		  USART1BUFFINFO = RSTXData3;
	    (void)OSIntTaskResume(FW_TASK_PRIO_SCI1); //启动SCI1
	}
  if((!USART1RxByteCnt)&& usDBfRS485EnSentData4==1 &&((0 == USART1BUFFINFO>>4)||(RSTXDataOver == USART1BUFFINFO))&& (INT16U)(Time2Count-RSOnTime4)>usDBpRS485Sent4delay) //第4条发送报文
	{
		  RSOnTime4 = Time2Count;
		  RSOnTimeSign4 = 1;
		  USART1BUFFINFO = RSTXData4;
	    (void)OSIntTaskResume(FW_TASK_PRIO_SCI1); //启动SCI1
	}
  if((!USART1RxByteCnt)&& usDBfRS485EnSentData5==1 &&((0 == USART1BUFFINFO>>4)||(RSTXDataOver == USART1BUFFINFO))&& (INT16U)(Time2Count-RSOnTime5)>usDBpRS485Sent5delay) //第5条发送报文
	{
		  RSOnTime5 = Time2Count;
		  RSOnTimeSign5 = 1;
		  USART1BUFFINFO = RSTXData5;
	    (void)OSIntTaskResume(FW_TASK_PRIO_SCI1); //启动SCI1
	}	
	
	
}

void SCI1RxIntHook(void)
{
	  INT08U buff = 0;
	
    USART_ClearFlag(USART1,USART_FLAG_TC);  //清除串口1中断标志位   USART_FLAG_TC发送完成标志位
    if(USART_GetITStatus(USART1,USART_IT_RXNE)!=Bit_RESET)//检查指定的USART中断发生与否   USART_IT_RXNE接收中断
    {
			  RS485OverTCount = 0;  //接收一次，清除一次 485发送接收周期间隔计数
        buff=USART_ReceiveData(USART1);	
			  if(USART1RxByteCnt == 0 &&(((usDBfRS485SysMode==0)&&(0x01/*usDBfRS485HostAddr*/ == buff))||((usDBfRS485SysMode==1)&&((usDBfRS485Monitor0Addr == buff) ||(usDBfRS485Monitor1Addr == buff) ||(usDBfRS485Monitor2Addr == buff)))))
			  {
			      sUSART1ModbusMsg.aData[0] = buff;
				    USART1RxByteCnt = 1;  //地址记录在 第 0 位 ,下个数据跳至下一步
					  USART1BUFFINFO = RSRXData;
					  RS485TXOverTCount = 0; //主机模式下发送间隔清零
					  
			  }
			  else if(USART1RxByteCnt)
			  {
			      sUSART1ModbusMsg.aData[USART1RxByteCnt++] = buff;
			  }
			  else
			  {
			      //读取数据错误
			  }

	  }	

}

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
