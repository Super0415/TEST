//[MSCAN12.h]CAN通信头文件--------------------------------------------------

//CAN通信需要用到的头文件
  #ifndef MSCAN12_H
  #define MSCAN12_H
//#include "Type.h"           //类型别名定义
//#include "mc9s12dg128.h"    //MCU映像寄存器名
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
//CAN通信寄存器及标志位定义
#define CANE 7          //MSCAN12模块使能位
#define INITRQ 0        //MSCAN12模块初始化请求位
#define INITACK 0       //MSCAN12模块初始化应答位
#define CLKSRC 6        //MSCAN12时钟选择位
#define LOOPB 5         //自测位
#define LISTEN 4        //只听模式位,只听模式时不能发送
#define DataFrm    1    //数据帧类型
#define RemoteFrm  2    //远程帧类型
#define RXF  0          //接收满标志位
//#define TXE0 0          //发送缓冲区0空标志位
//#define TXE1 1          //发送缓冲区1空标志位
//#define TXE2 2          //发送缓冲区2空标志位
#define TXS0 0          //发送缓冲区0被选中
#define TXS1 1          //发送缓冲区1被选中
#define TXS2 2          //发送缓冲区2被选中
#define TXF0 0          //发送缓冲区0满
#define TXF1 1          //发送缓冲区1满
#define TXF2 2          //发送缓冲区2满
#define IDE  3          //IDE位
#define RTR  4          //RTR位
#define ERTR 0          //扩展帧中的RTR位
#define CAN0TXF CAN0TXIDR0
#define CAN1TXF CAN1TXIDR0
#define CAN4TXF CAN4TXIDR0
#define CAN0RXF CAN0RXIDR0

//CAN通信用到的设置量定义
//bit.7-6=00，同步跳转宽度为1，bit.5-0=000100,预分频因子为5

#define CAN0BTR0V  0x41  
 //// #define CAN0BTR0V  0x04 
//bit.7=0，单次采样，bit.6-4=010,时间段2为3，bit.3-0=0101,
//时间段1为6，0b00100101，故位速率=1.97M/10=197kbps

#define CAN0BTR1V  0x58 
//// #define CAN0BTR1V  0x25 
//两个32位验收滤波器,滤波器0命中
#define CAN0IDACV  0x00

//本地节点标识符定义为00000000 000
#define CAN0IDAR0V 0x00
#define CAN0IDAR1V 0X18

//本地节点标识符屏蔽寄存器定义为相关00000000 000
#define CAN0IDMR0V 0xFF
#define CAN0IDMR1V 0xFF

//不允许接收中断
#define CAN0TIERV  0x00

//不允许发送缓冲区空中断
#define CAN0TIERV   0x00

//CAN通信相关函数声明

//CAN通信初始化
void CANInit(void);
//CAN发送1帧数据帧(数据长度<=8)
PUBLIC INT8U CANSND1DFRM(INT32U ID,INT8U * DataBUF,INT8U LEN,INT8U PORT);
//查找空闲发送缓冲区
INT8U GetSNDBUF(void);
//接收1帧
INT8U CANRCV1FRM(INT8U * CANRCVBUF);
PUBLIC void CANRCVPROCESS (void);
#endif
