//[MSCAN12.c]串行通信------------------------------------------------------*
//本文件包含:                                                              *
//    (1)CANInit:CAN通信初始化                                             *
//    (2)GetSNDBUF:查找空闲发送缓冲区                                      *
//    (3)CANSND1DFRM:CAN发送1帧数据帧(数据长度<=8字节)                     *
//    (4)CANRCV1FRM:CAN接收1帧数据帧                                       *
//-------------------------------------------------------------------------*

//头文件
#include "MSCAN12.h"    //CAN通信头文件
//#include "PublicShare.h"
unsigned char CANERR=0;
INT8U dataframe[13];
volatile INT8U  SUBID0;
volatile INT8U  SUBID1;
volatile INT8U  SUBID2;
volatile INT8U  SUBID21;
volatile INT8U  SUBID22;
volatile INT8U  SUBID3;
volatile INT32U  CANID;
volatile INT32U TESTCANID;
volatile INT32U  CANIDSEND;
volatile INT32U CANIDTEMP;
volatile INT8U CANRNUM = 0;
volatile INT8U CANRNUM2 = 0;
volatile INT8U CANRNUM3 = 0;
unsigned char CANBUFF[130];
unsigned char CANBUFF2[130];
unsigned char CANBUFF3[130];
volatile unsigned int CANDATA[20];
volatile uchar CanTimeOut=0;
INT8U CANSEND[8];
INT8U CANSEND2[8];
INT8U CANSEND3[8];

//CANInit:CAN通信初始化----------------------------------------------------*
//功  能:CAN初始化                                                         *
//参  数:无                                                                *
//返  回:无                                                                *
//说  明:在9.83M 外部晶振频率下将总线速率设为200kbps，节点标识符为0        *
//       双滤波方式，工作在查询方式                                        *
//-------------------------------------------------------------------------*
void CANInit(void)
{    MODRR=0x04;
    CAN0CTL1 |= (1 << CANE);    //MSCAN12模块使能   
    //初始化模式请求，并判断初始化应答位，INITACK为1则CAN模块已进入初始化
    CAN0CTL0 |= (1 << INITRQ);    // INITRQ=1，初始化请求
    //等待应答
    while ((CAN0CTL1 & (1<<INITACK)) == 0)
    {
    } 
    CAN0CTL1 &= ~(1 << CLKSRC);    //MSCAN12时钟源选择外部晶振fmscan=9.83M
   // CAN0CTL1 |= (1 << LOOPB);      //回环自测模式
    CAN0CTL1 &= ~(1 << LISTEN);    //禁止只听模式  
    CAN0BTR0 = CAN0BTR0V;    //同步跳转宽度为1,预分频因子为5
    CAN0BTR1 = CAN0BTR1V;    //将位速率设置成 197kbps
    CAN0IDAC = CAN0IDACV;    //两个32位验收过滤器
    CAN0IDAR0 = CAN0IDAR0V;    //给接收验证码寄存器0-1赋值
    CAN0IDAR1 = CAN0IDAR1V;
    CAN0IDAR2 =0;
    CAN0IDAR3=0;
    CAN0IDMR0 = CAN0IDMR0V;    //给接收验证屏蔽寄存器0-1赋值
    CAN0IDMR1 = CAN0IDMR1V;
    CAN0IDMR2=0xFF;
    CAN0IDMR3=0xFF;
    //CAN0IDMR4=0xFF;
    //CAN0IDMR5=0xFF;
    //CAN0IDMR6=0xFF;
    //CAN0IDMR7=0xFF;
    CAN0TIER = 0;//CAN0TIERV;      //设置中断方式
    //CAN0TIER = CAN0TIERV;
    CAN0CTL0 &= ~(1<<INITRQ);   //INITRQ=0，退出初始化模式
    //等待应答
    while ((CAN0CTL1 & (1<<INITACK)) == 1)
    {
    }
        CAN1CTL1 |= (1 << CANE);    //MSCAN12模块使能   
    //初始化模式请求，并判断初始化应答位，INITACK为1则CAN模块已进入初始化
    CAN1CTL0 |= (1 << INITRQ);    // INITRQ=1，初始化请求
    //等待应答
    while ((CAN1CTL1 & (1<<INITACK)) == 0)
    {
    } 
    CAN1CTL1 &= ~(1 << CLKSRC);    //MSCAN12时钟源选择外部晶振fmscan=9.83M
   // CAN0CTL1 |= (1 << LOOPB);      //回环自测模式
    CAN1CTL1 &= ~(1 << LISTEN);    //禁止只听模式  
    CAN1BTR0 = CAN0BTR0V;    //同步跳转宽度为1,预分频因子为5
    CAN1BTR1 = CAN0BTR1V;    //将位速率设置成 197kbps
    CAN1IDAC = CAN0IDACV;    //两个32位验收过滤器
    CAN1IDAR0 = CAN0IDAR0V;    //给接收验证码寄存器0-1赋值
    CAN1IDAR1 = CAN0IDAR1V;
    CAN1IDAR2 =0;
    CAN1IDAR3=0;
    CAN1IDMR0 = CAN0IDMR0V;    //给接收验证屏蔽寄存器0-1赋值
    CAN1IDMR1 = CAN0IDMR1V;
    CAN1IDMR2=0xFF;
    CAN1IDMR3=0xFF;
    //CAN0IDMR4=0xFF;
    //CAN0IDMR5=0xFF;
    //CAN0IDMR6=0xFF;
    //CAN0IDMR7=0xFF;
    CAN1TIER = CAN0TIERV;      //设置中断方式
    CAN1TIER = CAN0TIERV;
    CAN1CTL0 &= ~(1<<INITRQ);   //INITRQ=0，退出初始化模式
    //等待应答
    while ((CAN1CTL1 & 1) == 1)
    {
    }
         CAN4CTL1 |= (1 << CANE);    //MSCAN12模块使能   
    //初始化模式请求，并判断初始化应答位，INITACK为1则CAN模块已进入初始化
    CAN4CTL0 |= (1 << INITRQ);    // INITRQ=1，初始化请求
    //等待应答
    while ((CAN4CTL1 & (1<<INITACK)) == 0)
    {
    } 
    CAN4CTL1 &= ~(1 << CLKSRC);    //MSCAN12时钟源选择外部晶振fmscan=9.83M
   // CAN0CTL1 |= (1 << LOOPB);      //回环自测模式
    CAN4CTL1 &= ~(1 << LISTEN);    //禁止只听模式  
    CAN4BTR0 = CAN0BTR0V;    //同步跳转宽度为1,预分频因子为5
    CAN4BTR1 = CAN0BTR1V;    //将位速率设置成 197kbps
    CAN4IDAC = CAN0IDACV;    //两个32位验收过滤器
    CAN4IDAR0 = CAN0IDAR0V;    //给接收验证码寄存器0-1赋值
    CAN4IDAR1 = CAN0IDAR1V;
    CAN4IDAR2 =0;
    CAN4IDAR3=0;
    CAN4IDMR0 = CAN0IDMR0V;    //给接收验证屏蔽寄存器0-1赋值
    CAN4IDMR1 = CAN0IDMR1V;
    CAN4IDMR2=0xFF;
    CAN4IDMR3=0xFF;
    //CAN0IDMR4=0xFF;
    //CAN0IDMR5=0xFF;
    //CAN0IDMR6=0xFF;
    //CAN0IDMR7=0xFF;
    CAN4TIER = CAN0TIERV;      //设置中断方式
    CAN4TIER = CAN0TIERV;
    CAN4CTL0 &= ~(1<<INITRQ);   //INITRQ=0，退出初始化模式
    //等待应答
    while ((CAN4CTL1 & 1) == 1)
    {
    }
    CAN0RIER=0x01;
    CAN1RIER=0x01;
    CAN4RIER=0x01;
}

//CANSND1DFRM:CAN发送1帧数据-----------------------------------------------*
//功  能:CAN发送1帧数据(数据长度<=8)                                       *
//参  数:ID---报文标识符                                                   *
//       DataBUF---报文数据区首址                                          *
//       LEN---报文数据长度                                                *
//返  回:INT8U CANsnd1DFrm --- 发送成功与否标志，                          *
//       =0，没有空闲发送缓冲区，发送不成功；=1，发送成功                  *
//说明:在发送数据之前，先查询是否有空闲发送缓冲区，若无则不能发送，返回0   *
//-------------------------------------------------------------------------*
INT8U CANSND1DFRM(INT32U ID,INT8U * DataBUF, INT8U LEN,INT8U PORT)
{
    INT8U i;
    INT8U * addr;               //发送缓冲区
    INT8U BufNum = 0xFF;        //空闲的发送缓冲区号
    INT8U txbuffer;
   
    STRFLG8 ID0;
    STRFLG8 ID1;
    STRFLG8 ID2;
    STRFLG8 ID3;
    STRFLG32 MYID;    
   if(PORT==0 && CAN0TFLG_TXE0==0 )
   {     
  //  if(CAN0TFLG_TXE0==0) 
 //   {
     return 0;   
 //   }
   
   }
   
      if(PORT==1 && CAN1TFLG_TXE0==0 )
   {     
  //  if(CAN0TFLG_TXE0==0) 
 //   {
     return 0;   
 //   }
   
   }
      if(PORT==2 && CAN4TFLG_TXE0==0 )
   {     
  //  if(CAN0TFLG_TXE0==0) 
 //   {
     return 0;   
 //   }
   
   }
   
   /*
    if(PORT==1)
    {
      if(!CAN1TFLG)// (BufNum == 0xFF)         //若返回0xff，则没有空闲的发送缓冲区
      { 
           
        return 0; 
      }
    }
    
    if(PORT==2)
    {
      if(!CAN4TFLG)// (BufNum == 0xFF)         //若返回0xff，则没有空闲的发送缓冲区
      {
        return 0;
      }
    }
   */ 
   // MYID.BYTES.
            
    MYID.UDWORD=ID;
    ID0.Byte=MYID.BYTES.BYTE1;
    ID1.Byte=MYID.BYTES.BYTE2;    
    ID2.Byte=MYID.BYTES.BYTE3;    
    ID3.Byte=MYID.BYTES.BYTE4;
        
    //ID0.Byte=MYID & 0xFF;
    //ID1.Byte=(MYID & 0xFF00)/256;
    //ID2.Byte=(MYID & 0xFF0000)/65536;
    //ID3.Byte=(MYID & 0xFF000000)/0x1000000;
    
    //BufNum = GetSNDBUF();       //查找空闲的发送缓冲区   
                //没有空闲的发送缓冲区，发送不成功，返回0

if(PORT==0)
{
   CAN0TBSEL =1;//CAN0TFLG;//|= (1<<TXS2);
   txbuffer=CAN0TBSEL;
   addr=(INT8U *)(&CAN0TXF);  //获得发送前台缓冲区首地址 
} 
else if(PORT==1)
{
   CAN1TBSEL =2;//|= (1<<TXS2);
   txbuffer=CAN1TBSEL;
   addr=(INT8U *)(&CAN1TXF);  //获得发送前台缓冲区首地址 
} else if(PORT==2)
{
   CAN4TBSEL =CAN4TFLG;//|= (1<<TXS2);
   txbuffer=CAN4TBSEL;
   addr=(INT8U *)(&CAN4TXF);  //获得发送前台缓冲区首地址 
}


    
    //---------------------------------------------------------------------
    //将报文按CAN格式进行封装并存入空闲发送缓冲区等待发送
    //addr[0] =0;// (INT8U)(ID >> 8); //11位报文标识符高8位
    addr[0]=ID2.BITS.BIT5;
    addr[0]+=ID2.BITS.BIT6<<1;
    addr[0]+=ID2.BITS.BIT7<<2;
    addr[0]+=ID3.Byte<<3;
    addr[1]=ID1.BITS.BIT7;//((INT8U)(ID));    //低3位
    addr[1]+=ID2.BITS.BIT0<<1;
    addr[1]+=ID2.BITS.BIT1<<2;
    addr[1]+=ID2.BITS.BIT2<<5;
    addr[1]+=ID2.BITS.BIT3<<6;
    addr[1]+=ID2.BITS.BIT4<<7;        
   // addr[1] &= ~(1 << RTR);     //RTR=0，数据帧
    addr[1] |= (1 << RTR);     //SRR为1，扩展帧
   // addr[1] &= ~(1 << IDE);     //IDE位=0      
    addr[1] |= (1 << IDE);     //IDE位=1  
    addr[2]=(INT8U)(ID1.Byte<<1)+ID0.BITS.BIT7;
    //addr[2]=0;
    addr[3]=(INT8U)ID0.Byte<<1;        
    for(i = 0; i < LEN; i++)
    {      
    addr[i+4] = DataBUF[i]; //数据赋值   
    }
    addr[12] = LEN;             //数据长度
    //---------------------------------------------------------------------
  if(PORT==0)
  {  
    CAN0TFLG=txbuffer;
    while((CAN0TFLG&txbuffer)!=txbuffer)     
    return (1);                 //数据成功写入空闲缓冲区，返回1
  }
  else if(PORT==1)
  {
    CAN1TFLG=txbuffer;
    while((CAN1TFLG&txbuffer)!=txbuffer)     
    return (1);
  } 
  else if(PORT==2)
  {
    CAN4TFLG=txbuffer;
    while((CAN4TFLG&txbuffer)!=txbuffer)     
    return (1);
  }


}
 

//GetSNDBUF:查找空闲发送缓冲区---------------------------------------------*
//功能：查找空闲发送缓冲区                                                 *
//入口：无                                                                 *
//出口：空闲区号或0xFF                                                     *
//-------------------------------------------------------------------------*
INT8U GetSNDBUF(void)
{   
   INT8U bufbit = 0xFF;         //空闲区号
   //查找空闲的发送缓冲区
   if ((CAN0TFLG & (1 << 0)) != 0)
   {  //发送缓冲区0空      
      bufbit = 0;  
   }
   else if ((CAN0TFLG & (1 << 1)) != 0) 
   {  //发送缓冲区1空      
      bufbit = 1; 
   }
   else if ((CAN0TFLG & (1 << 2)) != 0) 
   {  //发送缓冲区2空
      bufbit = 2;
   }  

   return bufbit;//返回空闲区号
}

//CANRCV1FRM:CAN接收1帧数据------------------------------------------------*
//功  能:CAN接收1帧子程序                                                  *
//参  数:无                                                                *
//返  回:INT8U CANRCV1FRM---函数名，表示接收帧的情况，                     *
//       =0xFF，未收到帧；=1，收到数据帧；=2，收到远程帧                   *
//       CANRCVBUF--若收到报文，为16字节报文缓冲区的首地址                 *
//说  明:无                                                                *
//-------------------------------------------------------------------------*
INT8U CANRCV1FRM(INT8U * CANRCVBUF)
{   
    INT8U i;            
    INT8U IDEFlag;              //IDE标志
    INT8U RTRFlag;              //RTR标志
    INT8U FrameFlag;            //帧标志
    INT8U * addr;               //接收帧首地址

    if ((CAN0RFLG &(1 << RXF)) == 0) 
      return 0xFF;            //未收到数据，返回0xFF
    if(CAN0RFLG==3)
    {      
      CAN0RFLG=3;
      return 0xFF;
    }
    //RXF=1，表示收到数据，取数据处理
    addr = (INT8U *)(&CAN0RXF);   
    for(i = 0; i < 16; i++)
        CANRCVBUF[i] = addr[i]; //将CAN接收缓冲区中的数据取到临时缓冲区  
    CAN0RFLG = 0xFF;            //清所有接收标志     
    //------判断是标准帧还是扩展帧-----------------------------------------
    IDEFlag = (CANRCVBUF[1] & (1 << IDE)); //取标识符中IDE标志
    if (IDEFlag == 0)           //标准帧
    {  
        RTRFlag = (CANRCVBUF[1] & (1 << RTR)); //取标识符中RTR标志
        //判断是数据帧还是远程帧
        FrameFlag = ((RTRFlag == 0)?DataFrm:RemoteFrm);  
    }
    else                        //扩展帧
    {   
        RTRFlag = (CANRCVBUF[3] & (1 << ERTR)); //取标识符中RTR标志
        //判断是数据帧还是远程帧
        FrameFlag = ((RTRFlag == 0)?DataFrm:RemoteFrm);  
    } 
    return FrameFlag;           //返回数据帧标志(1)或远程帧(2)标志
}

void CANRCVPROCESS (void)
{

    INT8U i;
    STRFLG8 IDBYTE1;
    STRFLG8 IDBYTE2;
    STRFLG8 IDBYTE3;
    STRFLG8 IDBYTE4; 
    STRFLG8 TEMPBYTE;
    STRFLG32 CANID32;   
    STRFLG16 MODBUSDATA[4];
    CAN0RIER = 0x00;
    CAN1RIER = 0x00;
    CAN4RIER = 0x00;
    

    while (CANRNUM > 0)
    {
        for (i = 0; i < 13; i++)
        {
            dataframe[i] = CANBUFF[ (CANRNUM-1) *13+i];
        }
        TEMPBYTE.Byte=0;
        IDBYTE1.Byte=dataframe[3];
        IDBYTE2.Byte=dataframe[2];
        IDBYTE3.Byte=dataframe[1];
        IDBYTE4.Byte=dataframe[0];
        CANID32.DWORD=0;      
        IDBYTE1.BITS.BIT0=0;
        CANID32.BYTES.BYTE1=(IDBYTE1.Byte&0xFE)>>1;
        CANID32.BITS.BIT31=IDBYTE2.BITS.BIT0;
        CANID32.BYTES.BYTE2=(IDBYTE2.Byte&0xFE)>>1;
        CANID32.BITS.BIT23=IDBYTE3.BITS.BIT0;        
        TEMPBYTE.BITS.BIT0=IDBYTE3.BITS.BIT1;    
        TEMPBYTE.BITS.BIT1=IDBYTE3.BITS.BIT2;            
        TEMPBYTE.BITS.BIT2=IDBYTE3.BITS.BIT5;
        TEMPBYTE.BITS.BIT3=IDBYTE3.BITS.BIT6;
        TEMPBYTE.BITS.BIT4=IDBYTE3.BITS.BIT7;
        TEMPBYTE.BITS.BIT5=IDBYTE4.BITS.BIT0;
        TEMPBYTE.BITS.BIT6=IDBYTE4.BITS.BIT1;
        TEMPBYTE.BITS.BIT7=IDBYTE4.BITS.BIT2;                              
        CANID32.BYTES.BYTE3=TEMPBYTE.Byte;
        CANID32.BYTES.BYTE4=IDBYTE4.Byte>>3;
        switch (CANID32.UDWORD)
        {                
        case 0x00000002:
            EXTERNINPUT.Byte = dataframe[4];
           // REMOTESPEED = dataframe[5] + dataframe[6] * 256;
            SpeedError2     =dataframe[5];
            SpeedHigh2      =dataframe[6];
            OilPressureLow2 =dataframe[7];
            WTHI2           =dataframe[8];
            OTHI2           =dataframe[9];
            break;
                
        case 0x18FEEE00:

            #if FEIERTE_MODE==0
            if (ECUMODE)
            {
                OILTEMP = ( (int) dataframe[6] + (int) dataframe[7] * 256) / 32 - 273;
            }

            if (ECUMODE||PUMP_MODE)
            {
                WATERTEMP = (int) dataframe[4] - 40;
            }

            #endif
            
            #if FEIERTE_MODE
                RECRIFERTEMP= ( (int) dataframe[6] + (int) dataframe[7] * 256+16) / 32 - 273;
            #endif
            
            break;
        case 0x18FEF500:

            if (ECUMODE)
            {
                ATMOP = dataframe[4];
            }

            break;
        case 0x18FEE900:

            //if(ECUMODE)FUELAVG=(dataframe[6]+dataframe[7]*256)/10;
            if (ECUMODE)
            {
                FUELAVG = dataframe[6] + dataframe[7] * 256;
            }
            
            #if HW_MODE
            OILPRESSURE2   = (dataframe[4] + dataframe[5] * 256) - 100;
            #endif
                        
            #if FEIERTE_MODE
            
            /*
            CHARGEVOLTAGE=dataframe[4] + dataframe[5] * 256;              
            CHARGECURRENT=dataframe[6] + dataframe[7] * 256;            
            BATTSVOLTAGE = (dataframe[8] + dataframe[9] * 256); 
            
            if(CHARGEVOLTAGE<100)
            {
                CHARGEVOLTAGE=0;
            }
            
            if(CHARGECURRENT<200)
            {
                CHARGECURRENT=0;
            }
            
            if(BATTSVOLTAGE<100)
            {
                BATTSVOLTAGE=0;
            }
            */
            
            //电池温度          
            BATTTEMP=( (int) dataframe[10] + (int) dataframe[11] * 256+16) / 32 - 273;
            if(BATTTEMP<0)
            {
                BATTTEMP=0;
            }
            #endif

           #if HW_MODE
            if (OILPRESSURE2 < 0)
            {
                OILPRESSURE2 = 0;
            }                                 
            PUMPCURRENT    = (dataframe[8] + dataframe[9] * 256);
            ECU_STATUS2.Byte = dataframe[10];
            ECU_STATUS.Byte = dataframe[11];
           #endif
           
           #if PUMP_MODE
           BATTV1=dataframe[4]+dataframe[5]*256;
           BATTV2=dataframe[6]+dataframe[7]*256;
           CHARGEV1=dataframe[8]+dataframe[9]*256;
           CHARGEV2=dataframe[10]+dataframe[11]*256;
           #endif
            
            break;
        case 0x18FEDF00:
            break;
        case 0x18FEEF00:
        
#if HW_MODE 

            if (ECUMODE)
            {
                OILPRESSURE = (int) dataframe[7] * 8 - 100; //J1939默认乘以4，华为随载乘以8;

                if (OILPRESSURE < 0)
                {
                    OILPRESSURE = 0;
                }
            }

#else

            #if STANDARD_MODE || PUMP_MODE

            if (ECUMODE||PUMP_MODE)
            {
                OILPRESSURE = (int) dataframe[7] * 4;    //J1939默认乘以4，华为随载乘以8;
            }            
            #endif
            
  
            

#endif
            break;
        case 0x0CF00400:

            if (ECUMODE||HW_MODE||PUMP_MODE||FEIERTE_MODE)
            {
                DES_SPEED = ( (int) dataframe[7] + (int) dataframe[8] * 256) / 8;
            }
            #if PUMP_MODE
            
            OUTPUTPRESSURE = dataframe[10]+dataframe[11]*256;
            
            #endif
            
            
            break;
            
            
            //     case 0x0CF00300:
            //     APPPERCENT=dataframe[5];
            //     break;
            //     case 0x18FFF400:
            //     APP1=dataframe[4]+dataframe[5]*256;
            //     APP2=dataframe[6]+dataframe[7]*256;
            //     break;
        case 0x0CF00F00:
            CANDATA[0] = dataframe[4] + dataframe[5] * 256;
            CANDATA[1] = dataframe[6] + dataframe[7] * 256;

            if (CANWRITE == 0)
            {
                ECU_NOWDATA = dataframe[8] + dataframe[9] * 256;
            }

            break;
        }

        SUBID0 = 0;
        SUBID1 = 0;
        SUBID2 = 0;
        SUBID3 = 0;
        CANID = 0;
        CANRNUM--;
    }

    while (CANRNUM2 > 0)
    {
        for (i = 0; i < 13; i++)
        {
            dataframe[i] = CANBUFF2[ (CANRNUM2-1) *13+i];
        }

        IDBYTE1.Byte=dataframe[3];
        IDBYTE2.Byte=dataframe[2];
        IDBYTE3.Byte=dataframe[1];
        IDBYTE4.Byte=dataframe[0];
        CANID32.DWORD=0;
        TEMPBYTE.Byte=0;
        IDBYTE1.BITS.BIT0=0;
        CANID32.BYTES.BYTE1=IDBYTE1.Byte>>1;
        CANID32.BITS.BIT7=IDBYTE2.BITS.BIT0;
        CANID32.BYTES.BYTE2=IDBYTE2.Byte>>1;
        CANID32.BITS.BIT15=IDBYTE3.BITS.BIT0;
        
        TEMPBYTE.BITS.BIT0=IDBYTE3.BITS.BIT1;    
        TEMPBYTE.BITS.BIT1=IDBYTE3.BITS.BIT2;            
        TEMPBYTE.BITS.BIT2=IDBYTE3.BITS.BIT5;
        TEMPBYTE.BITS.BIT3=IDBYTE3.BITS.BIT6;
        TEMPBYTE.BITS.BIT4=IDBYTE3.BITS.BIT7;
        TEMPBYTE.BITS.BIT5=IDBYTE4.BITS.BIT0;
        TEMPBYTE.BITS.BIT6=IDBYTE4.BITS.BIT1;
        TEMPBYTE.BITS.BIT7=IDBYTE4.BITS.BIT2;
        
                      
        CANID32.BYTES.BYTE3=TEMPBYTE.Byte;
        CANID32.BYTES.BYTE4=IDBYTE4.Byte>>3;
        MODBUSDATA[0].BYTES.BYTEL=dataframe[5];
        MODBUSDATA[0].BYTES.BYTEH=dataframe[4];
        MODBUSDATA[1].BYTES.BYTEL=dataframe[7];
        MODBUSDATA[1].BYTES.BYTEH=dataframe[6];
        MODBUSDATA[2].BYTES.BYTEL=dataframe[9];
        MODBUSDATA[2].BYTES.BYTEH=dataframe[8];
        MODBUSDATA[3].BYTES.BYTEL=dataframe[11];
        MODBUSDATA[3].BYTES.BYTEH=dataframe[10];

        switch (CANID32.UDWORD)
        {
            case 0x0000000A:
            Params[PNUM_STAT]=dataframe[4]*256+dataframe[5];
            break;
            
            case 0x00000020:
            Params[MODBUSDATA[0].Byte]=MODBUSDATA[1].Byte;
            if ( (MODBUSDATA[0].Byte) < 200 && (MODBUSDATA[0].Byte != 2))
            {                                                                                                                            
              SaveParam (MODBUSDATA[0].Byte,1);                                                
            }
            break;
          case 0x00000030:
              if(CAN_PARAM_SENDFLAG==0)
              {                
                  CAN_PARAM_ADDRESS=MODBUSDATA[0].Byte;
                  CAN_PARAM_NUM=MODBUSDATA[1].Byte;
                  CAN_PARAM_SENDFLAG=1;
              }
          break;
            
        }

        SUBID0 = 0;
        SUBID1 = 0;
        SUBID2 = 0;
        SUBID3 = 0;
        CANID = 0;
        CANRNUM2--;
    }

    while (CANRNUM3 > 0)
    {
        for (i = 0; i < 13; i++)
        {
            dataframe[i] = CANBUFF3[ (CANRNUM3-1) *13+i];
        }

        IDBYTE1.Byte=dataframe[3];
        IDBYTE2.Byte=dataframe[2];
        IDBYTE3.Byte=dataframe[1];
        IDBYTE4.Byte=dataframe[0];
        CANID32.DWORD=0;
      
        IDBYTE1.BITS.BIT0=0;
        CANID32.BYTES.BYTE1=IDBYTE1.Byte>>1;
        CANID32.BITS.BIT7=IDBYTE2.BITS.BIT0;
        CANID32.BYTES.BYTE2=IDBYTE2.Byte>>1;
        CANID32.BITS.BIT15=IDBYTE3.BITS.BIT0;
        
        TEMPBYTE.BITS.BIT0=IDBYTE3.BITS.BIT1;    
        TEMPBYTE.BITS.BIT1=IDBYTE3.BITS.BIT2;            
        TEMPBYTE.BITS.BIT2=IDBYTE3.BITS.BIT5;
        TEMPBYTE.BITS.BIT3=IDBYTE3.BITS.BIT6;
        TEMPBYTE.BITS.BIT4=IDBYTE3.BITS.BIT7;
        TEMPBYTE.BITS.BIT5=IDBYTE4.BITS.BIT0;
        TEMPBYTE.BITS.BIT6=IDBYTE4.BITS.BIT1;
        TEMPBYTE.BITS.BIT7=IDBYTE4.BITS.BIT2;
        
                      
        CANID32.BYTES.BYTE3=TEMPBYTE.Byte;
        CANID32.BYTES.BYTE4=IDBYTE4.Byte>>3;

        switch (CANID32.UDWORD)
        {
        case 0x00000001:
            break;
        }

        SUBID0 = 0;
        SUBID1 = 0;
        SUBID2 = 0;
        SUBID3 = 0;
        CANID = 0;
        CANRNUM3--;
    }

    CAN0RIER = 0x01;
    CAN1RIER = 0x01;
    CAN4RIER = 0x01;
    // if(CANBUFF[3]>>1==11 && CANBUFF[0]==0 && CANBUFF[2]==0){
    // REMOTEDI=CANBUFF[4];
    // }
    //REMOTEDI

}
