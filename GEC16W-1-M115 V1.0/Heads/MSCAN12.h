//[MSCAN12.h]CANͨ��ͷ�ļ�--------------------------------------------------

//CANͨ����Ҫ�õ���ͷ�ļ�
  #ifndef MSCAN12_H
  #define MSCAN12_H
//#include "Type.h"           //���ͱ�������
//#include "mc9s12dg128.h"    //MCUӳ��Ĵ�����
#include "PublicShare.h"    
PUBLIC volatile INT8U CANRNUM;
PUBLIC volatile INT8U CANRNUM2;
PUBLIC volatile INT8U CANRNUM3;
PUBLIC unsigned char CANBUFF[130];
PUBLIC unsigned char CANBUFF2[130];
PUBLIC unsigned char CANBUFF3[130];
PUBLIC volatile unsigned int CANDATA[20];
PUBLIC volatile uchar CanTimeOut;
PUBLIC INT8U CANSEND[8];
PUBLIC INT8U CANSEND2[8];
PUBLIC INT8U CANSEND3[8];
//CANͨ�żĴ�������־λ����
#define CANE 7          //MSCAN12ģ��ʹ��λ
#define INITRQ 0        //MSCAN12ģ���ʼ������λ
#define INITACK 0       //MSCAN12ģ���ʼ��Ӧ��λ
#define CLKSRC 6        //MSCAN12ʱ��ѡ��λ
#define LOOPB 5         //�Բ�λ
#define LISTEN 4        //ֻ��ģʽλ,ֻ��ģʽʱ���ܷ���
#define DataFrm    1    //����֡����
#define RemoteFrm  2    //Զ��֡����
#define RXF  0          //��������־λ
//#define TXE0 0          //���ͻ�����0�ձ�־λ
//#define TXE1 1          //���ͻ�����1�ձ�־λ
//#define TXE2 2          //���ͻ�����2�ձ�־λ
#define TXS0 0          //���ͻ�����0��ѡ��
#define TXS1 1          //���ͻ�����1��ѡ��
#define TXS2 2          //���ͻ�����2��ѡ��
#define TXF0 0          //���ͻ�����0��
#define TXF1 1          //���ͻ�����1��
#define TXF2 2          //���ͻ�����2��
#define IDE  3          //IDEλ
#define RTR  4          //RTRλ
#define ERTR 0          //��չ֡�е�RTRλ
#define CAN0TXF CAN0TXIDR0
#define CAN1TXF CAN1TXIDR0
#define CAN4TXF CAN4TXIDR0
#define CAN0RXF CAN0RXIDR0

//CANͨ���õ�������������
//bit.7-6=00��ͬ����ת���Ϊ1��bit.5-0=000100,Ԥ��Ƶ����Ϊ5

#define CAN0BTR0V  0x41  
 //// #define CAN0BTR0V  0x04 
//bit.7=0�����β�����bit.6-4=010,ʱ���2Ϊ3��bit.3-0=0101,
//ʱ���1Ϊ6��0b00100101����λ����=1.97M/10=197kbps

#define CAN0BTR1V  0x58 
//// #define CAN0BTR1V  0x25 
//����32λ�����˲���,�˲���0����
#define CAN0IDACV  0x00

//���ؽڵ��ʶ������Ϊ00000000 000
#define CAN0IDAR0V 0x00
#define CAN0IDAR1V 0X18

//���ؽڵ��ʶ�����μĴ�������Ϊ���00000000 000
#define CAN0IDMR0V 0xFF
#define CAN0IDMR1V 0xFF

//����������ж�
#define CAN0TIERV  0x00

//�������ͻ��������ж�
#define CAN0TIERV   0x00

//CANͨ����غ�������

//CANͨ�ų�ʼ��
void CANInit(void);
//CAN����1֡����֡(���ݳ���<=8)
PUBLIC INT8U CANSND1DFRM(INT32U ID,INT8U * DataBUF,INT8U LEN,INT8U PORT);
//���ҿ��з��ͻ�����
INT8U GetSNDBUF(void);
//����1֡
INT8U CANRCV1FRM(INT8U * CANRCVBUF);
PUBLIC void CANRCVPROCESS (void);
#endif
