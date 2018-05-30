//[MSCAN12.c]����ͨ��------------------------------------------------------*
//���ļ�����:                                                              *
//    (1)CANInit:CANͨ�ų�ʼ��                                             *
//    (2)GetSNDBUF:���ҿ��з��ͻ�����                                      *
//    (3)CANSND1DFRM:CAN����1֡����֡(���ݳ���<=8�ֽ�)                     *
//    (4)CANRCV1FRM:CAN����1֡����֡                                       *
//-------------------------------------------------------------------------*

//ͷ�ļ�
#include "MSCAN12.h"    //CANͨ��ͷ�ļ�
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

//CANInit:CANͨ�ų�ʼ��----------------------------------------------------*
//��  ��:CAN��ʼ��                                                         *
//��  ��:��                                                                *
//��  ��:��                                                                *
//˵  ��:��9.83M �ⲿ����Ƶ���½�����������Ϊ200kbps���ڵ��ʶ��Ϊ0        *
//       ˫�˲���ʽ�������ڲ�ѯ��ʽ                                        *
//-------------------------------------------------------------------------*
void CANInit(void)
{    MODRR=0x04;
    CAN0CTL1 |= (1 << CANE);    //MSCAN12ģ��ʹ��   
    //��ʼ��ģʽ���󣬲��жϳ�ʼ��Ӧ��λ��INITACKΪ1��CANģ���ѽ����ʼ��
    CAN0CTL0 |= (1 << INITRQ);    // INITRQ=1����ʼ������
    //�ȴ�Ӧ��
    while ((CAN0CTL1 & (1<<INITACK)) == 0)
    {
    } 
    CAN0CTL1 &= ~(1 << CLKSRC);    //MSCAN12ʱ��Դѡ���ⲿ����fmscan=9.83M
   // CAN0CTL1 |= (1 << LOOPB);      //�ػ��Բ�ģʽ
    CAN0CTL1 &= ~(1 << LISTEN);    //��ֹֻ��ģʽ  
    CAN0BTR0 = CAN0BTR0V;    //ͬ����ת���Ϊ1,Ԥ��Ƶ����Ϊ5
    CAN0BTR1 = CAN0BTR1V;    //��λ�������ó� 197kbps
    CAN0IDAC = CAN0IDACV;    //����32λ���չ�����
    CAN0IDAR0 = CAN0IDAR0V;    //��������֤��Ĵ���0-1��ֵ
    CAN0IDAR1 = CAN0IDAR1V;
    CAN0IDAR2 =0;
    CAN0IDAR3=0;
    CAN0IDMR0 = CAN0IDMR0V;    //��������֤���μĴ���0-1��ֵ
    CAN0IDMR1 = CAN0IDMR1V;
    CAN0IDMR2=0xFF;
    CAN0IDMR3=0xFF;
    //CAN0IDMR4=0xFF;
    //CAN0IDMR5=0xFF;
    //CAN0IDMR6=0xFF;
    //CAN0IDMR7=0xFF;
    CAN0TIER = 0;//CAN0TIERV;      //�����жϷ�ʽ
    //CAN0TIER = CAN0TIERV;
    CAN0CTL0 &= ~(1<<INITRQ);   //INITRQ=0���˳���ʼ��ģʽ
    //�ȴ�Ӧ��
    while ((CAN0CTL1 & (1<<INITACK)) == 1)
    {
    }
        CAN1CTL1 |= (1 << CANE);    //MSCAN12ģ��ʹ��   
    //��ʼ��ģʽ���󣬲��жϳ�ʼ��Ӧ��λ��INITACKΪ1��CANģ���ѽ����ʼ��
    CAN1CTL0 |= (1 << INITRQ);    // INITRQ=1����ʼ������
    //�ȴ�Ӧ��
    while ((CAN1CTL1 & (1<<INITACK)) == 0)
    {
    } 
    CAN1CTL1 &= ~(1 << CLKSRC);    //MSCAN12ʱ��Դѡ���ⲿ����fmscan=9.83M
   // CAN0CTL1 |= (1 << LOOPB);      //�ػ��Բ�ģʽ
    CAN1CTL1 &= ~(1 << LISTEN);    //��ֹֻ��ģʽ  
    CAN1BTR0 = CAN0BTR0V;    //ͬ����ת���Ϊ1,Ԥ��Ƶ����Ϊ5
    CAN1BTR1 = CAN0BTR1V;    //��λ�������ó� 197kbps
    CAN1IDAC = CAN0IDACV;    //����32λ���չ�����
    CAN1IDAR0 = CAN0IDAR0V;    //��������֤��Ĵ���0-1��ֵ
    CAN1IDAR1 = CAN0IDAR1V;
    CAN1IDAR2 =0;
    CAN1IDAR3=0;
    CAN1IDMR0 = CAN0IDMR0V;    //��������֤���μĴ���0-1��ֵ
    CAN1IDMR1 = CAN0IDMR1V;
    CAN1IDMR2=0xFF;
    CAN1IDMR3=0xFF;
    //CAN0IDMR4=0xFF;
    //CAN0IDMR5=0xFF;
    //CAN0IDMR6=0xFF;
    //CAN0IDMR7=0xFF;
    CAN1TIER = CAN0TIERV;      //�����жϷ�ʽ
    CAN1TIER = CAN0TIERV;
    CAN1CTL0 &= ~(1<<INITRQ);   //INITRQ=0���˳���ʼ��ģʽ
    //�ȴ�Ӧ��
    while ((CAN1CTL1 & 1) == 1)
    {
    }
         CAN4CTL1 |= (1 << CANE);    //MSCAN12ģ��ʹ��   
    //��ʼ��ģʽ���󣬲��жϳ�ʼ��Ӧ��λ��INITACKΪ1��CANģ���ѽ����ʼ��
    CAN4CTL0 |= (1 << INITRQ);    // INITRQ=1����ʼ������
    //�ȴ�Ӧ��
    while ((CAN4CTL1 & (1<<INITACK)) == 0)
    {
    } 
    CAN4CTL1 &= ~(1 << CLKSRC);    //MSCAN12ʱ��Դѡ���ⲿ����fmscan=9.83M
   // CAN0CTL1 |= (1 << LOOPB);      //�ػ��Բ�ģʽ
    CAN4CTL1 &= ~(1 << LISTEN);    //��ֹֻ��ģʽ  
    CAN4BTR0 = CAN0BTR0V;    //ͬ����ת���Ϊ1,Ԥ��Ƶ����Ϊ5
    CAN4BTR1 = CAN0BTR1V;    //��λ�������ó� 197kbps
    CAN4IDAC = CAN0IDACV;    //����32λ���չ�����
    CAN4IDAR0 = CAN0IDAR0V;    //��������֤��Ĵ���0-1��ֵ
    CAN4IDAR1 = CAN0IDAR1V;
    CAN4IDAR2 =0;
    CAN4IDAR3=0;
    CAN4IDMR0 = CAN0IDMR0V;    //��������֤���μĴ���0-1��ֵ
    CAN4IDMR1 = CAN0IDMR1V;
    CAN4IDMR2=0xFF;
    CAN4IDMR3=0xFF;
    //CAN0IDMR4=0xFF;
    //CAN0IDMR5=0xFF;
    //CAN0IDMR6=0xFF;
    //CAN0IDMR7=0xFF;
    CAN4TIER = CAN0TIERV;      //�����жϷ�ʽ
    CAN4TIER = CAN0TIERV;
    CAN4CTL0 &= ~(1<<INITRQ);   //INITRQ=0���˳���ʼ��ģʽ
    //�ȴ�Ӧ��
    while ((CAN4CTL1 & 1) == 1)
    {
    }
    CAN0RIER=0x01;
    CAN1RIER=0x01;
    CAN4RIER=0x01;
}

//CANSND1DFRM:CAN����1֡����-----------------------------------------------*
//��  ��:CAN����1֡����(���ݳ���<=8)                                       *
//��  ��:ID---���ı�ʶ��                                                   *
//       DataBUF---������������ַ                                          *
//       LEN---�������ݳ���                                                *
//��  ��:INT8U CANsnd1DFrm --- ���ͳɹ�����־��                          *
//       =0��û�п��з��ͻ����������Ͳ��ɹ���=1�����ͳɹ�                  *
//˵��:�ڷ�������֮ǰ���Ȳ�ѯ�Ƿ��п��з��ͻ��������������ܷ��ͣ�����0   *
//-------------------------------------------------------------------------*
INT8U CANSND1DFRM(INT32U ID,INT8U * DataBUF, INT8U LEN,INT8U PORT)
{
    INT8U i;
    INT8U * addr;               //���ͻ�����
    INT8U BufNum = 0xFF;        //���еķ��ͻ�������
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
      if(!CAN1TFLG)// (BufNum == 0xFF)         //������0xff����û�п��еķ��ͻ�����
      { 
           
        return 0; 
      }
    }
    
    if(PORT==2)
    {
      if(!CAN4TFLG)// (BufNum == 0xFF)         //������0xff����û�п��еķ��ͻ�����
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
    
    //BufNum = GetSNDBUF();       //���ҿ��еķ��ͻ�����   
                //û�п��еķ��ͻ����������Ͳ��ɹ�������0

if(PORT==0)
{
   CAN0TBSEL =1;//CAN0TFLG;//|= (1<<TXS2);
   txbuffer=CAN0TBSEL;
   addr=(INT8U *)(&CAN0TXF);  //��÷���ǰ̨�������׵�ַ 
} 
else if(PORT==1)
{
   CAN1TBSEL =2;//|= (1<<TXS2);
   txbuffer=CAN1TBSEL;
   addr=(INT8U *)(&CAN1TXF);  //��÷���ǰ̨�������׵�ַ 
} else if(PORT==2)
{
   CAN4TBSEL =CAN4TFLG;//|= (1<<TXS2);
   txbuffer=CAN4TBSEL;
   addr=(INT8U *)(&CAN4TXF);  //��÷���ǰ̨�������׵�ַ 
}


    
    //---------------------------------------------------------------------
    //�����İ�CAN��ʽ���з�װ��������з��ͻ������ȴ�����
    //addr[0] =0;// (INT8U)(ID >> 8); //11λ���ı�ʶ����8λ
    addr[0]=ID2.BITS.BIT5;
    addr[0]+=ID2.BITS.BIT6<<1;
    addr[0]+=ID2.BITS.BIT7<<2;
    addr[0]+=ID3.Byte<<3;
    addr[1]=ID1.BITS.BIT7;//((INT8U)(ID));    //��3λ
    addr[1]+=ID2.BITS.BIT0<<1;
    addr[1]+=ID2.BITS.BIT1<<2;
    addr[1]+=ID2.BITS.BIT2<<5;
    addr[1]+=ID2.BITS.BIT3<<6;
    addr[1]+=ID2.BITS.BIT4<<7;        
   // addr[1] &= ~(1 << RTR);     //RTR=0������֡
    addr[1] |= (1 << RTR);     //SRRΪ1����չ֡
   // addr[1] &= ~(1 << IDE);     //IDEλ=0      
    addr[1] |= (1 << IDE);     //IDEλ=1  
    addr[2]=(INT8U)(ID1.Byte<<1)+ID0.BITS.BIT7;
    //addr[2]=0;
    addr[3]=(INT8U)ID0.Byte<<1;        
    for(i = 0; i < LEN; i++)
    {      
    addr[i+4] = DataBUF[i]; //���ݸ�ֵ   
    }
    addr[12] = LEN;             //���ݳ���
    //---------------------------------------------------------------------
  if(PORT==0)
  {  
    CAN0TFLG=txbuffer;
    while((CAN0TFLG&txbuffer)!=txbuffer)     
    return (1);                 //���ݳɹ�д����л�����������1
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
 

//GetSNDBUF:���ҿ��з��ͻ�����---------------------------------------------*
//���ܣ����ҿ��з��ͻ�����                                                 *
//��ڣ���                                                                 *
//���ڣ��������Ż�0xFF                                                     *
//-------------------------------------------------------------------------*
INT8U GetSNDBUF(void)
{   
   INT8U bufbit = 0xFF;         //��������
   //���ҿ��еķ��ͻ�����
   if ((CAN0TFLG & (1 << 0)) != 0)
   {  //���ͻ�����0��      
      bufbit = 0;  
   }
   else if ((CAN0TFLG & (1 << 1)) != 0) 
   {  //���ͻ�����1��      
      bufbit = 1; 
   }
   else if ((CAN0TFLG & (1 << 2)) != 0) 
   {  //���ͻ�����2��
      bufbit = 2;
   }  

   return bufbit;//���ؿ�������
}

//CANRCV1FRM:CAN����1֡����------------------------------------------------*
//��  ��:CAN����1֡�ӳ���                                                  *
//��  ��:��                                                                *
//��  ��:INT8U CANRCV1FRM---����������ʾ����֡�������                     *
//       =0xFF��δ�յ�֡��=1���յ�����֡��=2���յ�Զ��֡                   *
//       CANRCVBUF--���յ����ģ�Ϊ16�ֽڱ��Ļ��������׵�ַ                 *
//˵  ��:��                                                                *
//-------------------------------------------------------------------------*
INT8U CANRCV1FRM(INT8U * CANRCVBUF)
{   
    INT8U i;            
    INT8U IDEFlag;              //IDE��־
    INT8U RTRFlag;              //RTR��־
    INT8U FrameFlag;            //֡��־
    INT8U * addr;               //����֡�׵�ַ

    if ((CAN0RFLG &(1 << RXF)) == 0) 
      return 0xFF;            //δ�յ����ݣ�����0xFF
    if(CAN0RFLG==3)
    {      
      CAN0RFLG=3;
      return 0xFF;
    }
    //RXF=1����ʾ�յ����ݣ�ȡ���ݴ���
    addr = (INT8U *)(&CAN0RXF);   
    for(i = 0; i < 16; i++)
        CANRCVBUF[i] = addr[i]; //��CAN���ջ������е�����ȡ����ʱ������  
    CAN0RFLG = 0xFF;            //�����н��ձ�־     
    //------�ж��Ǳ�׼֡������չ֡-----------------------------------------
    IDEFlag = (CANRCVBUF[1] & (1 << IDE)); //ȡ��ʶ����IDE��־
    if (IDEFlag == 0)           //��׼֡
    {  
        RTRFlag = (CANRCVBUF[1] & (1 << RTR)); //ȡ��ʶ����RTR��־
        //�ж�������֡����Զ��֡
        FrameFlag = ((RTRFlag == 0)?DataFrm:RemoteFrm);  
    }
    else                        //��չ֡
    {   
        RTRFlag = (CANRCVBUF[3] & (1 << ERTR)); //ȡ��ʶ����RTR��־
        //�ж�������֡����Զ��֡
        FrameFlag = ((RTRFlag == 0)?DataFrm:RemoteFrm);  
    } 
    return FrameFlag;           //��������֡��־(1)��Զ��֡(2)��־
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
            
            //����¶�          
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
                OILPRESSURE = (int) dataframe[7] * 8 - 100; //J1939Ĭ�ϳ���4����Ϊ���س���8;

                if (OILPRESSURE < 0)
                {
                    OILPRESSURE = 0;
                }
            }

#else

            #if STANDARD_MODE || PUMP_MODE

            if (ECUMODE||PUMP_MODE)
            {
                OILPRESSURE = (int) dataframe[7] * 4;    //J1939Ĭ�ϳ���4����Ϊ���س���8;
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
