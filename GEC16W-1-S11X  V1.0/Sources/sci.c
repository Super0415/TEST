/////////////////////////////////////////////////////////////////////////////////////////
//
// Serial Communication Interface (SCI) MC9S12XEP100
//
// --------------------------------------------------------------------------------------
// Copyright (c) 2006 SofTec Microsystems
// http://www.softecmicro.com/
// 
/////////////////////////////////////////////////////////////////////////////////////////
#include <MC9S12XS128.h>
#include "sci.h"
#include "defs.h"
#include "extern.h"
#include "main.h"
#include "lcd.h"

  unsigned int NowPoint;
 void SCIProcess(void){
 unsigned int i;
 unsigned int CRC_VALUE;
 unsigned char CRC_H;
 unsigned char CRC_L; 
 unsigned int ADD=0;
// unsigned int AddrOffset;
 unsigned int DataCount;
 int * DATADES; 
 char * LOCALDATA;
 
 if(CHECKFLAG==0)LOCALDATA=&LocalValue[0];else LOCALDATA=&StatusData[0];
 
  

 if (RXcomplete&&!MODBUS_CHECK){
  
  if(ReceiveBuff[1]==16 && LastNum==8)
  {
  
  MODBUS_CHECK=1;
  lcd_disp_ParamConfirm=0;
  RETURNFLAG=1;
  return;
  }
  
 CRC_VALUE=CalcCRC(&ReceiveBuff[0],LastNum-2);
 CRC_H=(CRC_VALUE>>8) & 0xFF;
 CRC_L=CRC_VALUE & 0xFF;
 
    if(CRC_H==ReceiveBuff[LastNum-1] && CRC_L==ReceiveBuff[LastNum-2])
    {   
       if(ReceiveBuff[1]==0x03)
       {  
          DataCount=ReceiveBuff[2]; 
          if(DataCount<=200)
          {
           for(i=0;i<DataCount;i+=2)LOCALDATA[AddrOffset+i]=ReceiveBuff[i+3],LOCALDATA[AddrOffset+i+1]=ReceiveBuff[i+4];              
          }
       }

    }
    
    if(ReadStart<200)DATADES=&DataValue[0],NowPoint=ReadStart;else DATADES=&ParamValue[0],NowPoint=ReadStart-200;
   
      
    for(i=0;i<ReadLength;i++)
    {
     
     *(DATADES+i+NowPoint)=LocalValue[i];
    
    }
 
 
      
    
   RETURNFLAG=1; 
   MODBUS_CHECK=1;  
 }
 
 }
 
 void SciCommand(uchar cmd,uint addr_des,uchar op_num, int* data_addr,uchar write_num){     
 uchar i;
 uint SendCRC;

 if(cmd==3)
 {  
    SendBuff[0]=1;
    SendBuff[1]=cmd;
    SendBuff[3]=addr_des&0xFF;
    SendBuff[2]=(addr_des>>8)&0xFF;
    SendBuff[4]=0;
    SendBuff[5]=op_num; 
    SendCRC=CalcCRC(&SendBuff[0],6);
    SendBuff[6]=SendCRC&0xFF;
    SendBuff[7]=(SendCRC>>8)&0xFF;
    
    ReadStart=addr_des;
    ReadLength=op_num;
    
    DisableInterrupts;
    for(i=0;i<8;i++)(void)SCISendBuffer(0,SendBuff[i]);
    SENDFLAG=1;
    EnableInterrupts;           
 }
 if(cmd==16)
 {
    addr_des+=200;
    SendBuff[0]=1;
    SendBuff[1]=cmd;
    SendBuff[3]=addr_des&0xFF;
    SendBuff[2]=(addr_des>>8)&0xFF;
    SendBuff[4]=0;
    SendBuff[5]=write_num; 
    SendBuff[6]=write_num*2;
    
    for(i=0;i<SendBuff[6];i+=2)
    {
    SendBuff[7+i+1]=data_addr[i/2]&0xFF;
    SendBuff[7+i]= (data_addr[i/2]>>8)&0xFF; 
    }
        
    SendCRC=CalcCRC(&SendBuff[0],SendBuff[6]+7);        
    SendBuff[SendBuff[6]+7]=SendCRC&0xFF;
    SendBuff[SendBuff[6]+8]=(SendCRC>>8)&0xFF;
    DisableInterrupts;
    for(i=0;i<SendBuff[6]+9;i++)(void)SCISendBuffer(0,SendBuff[i]);
    SENDFLAG=1;
    EnableInterrupts;
 } 
 
 
 
 
 
 
 
 }
 
 
  void SciReadValue(uint Pnum,uchar Rnum){
  
     SciCommand(3,Pnum,Rnum,0,Rnum);
  
  }
 
 
  void SciWriteParam(uint Pnum,int *ValueAddr,uchar Wnum){
  
     SciCommand(16,Pnum,0,ValueAddr,Wnum);
  
  }
 
 unsigned int CalcCRC(volatile unsigned char *ByteStart,unsigned char CalcNum){
 unsigned char i;
 char j;
 char LowZero;
 unsigned int CRC_REG=0xFFFF;
 unsigned char CRC_LOW;
 for(i=0;i<CalcNum;i++){
 
    CRC_LOW=CRC_REG & 0xFF;
    CRC_LOW ^= *(ByteStart+i);
    CRC_REG &=0xFF00;
    CRC_REG+=CRC_LOW;
    
    for(j=0;j<8;j++){ 
         
    LowZero=CRC_REG & 0x01;  
    CRC_REG &= 0xFFFE;
    CRC_REG >>=1;
    if(LowZero) CRC_REG ^= 0xA001;
    
    }
 }
 
 return CRC_REG;
 } ;

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
struct sci_peripheral
{
  Bool ena;
  unsigned char *init_reg;
} sci[2] = {
    FALSE, &SCI0BDH,
    FALSE, &SCI1BDH    
  };

/////////////////////////////////////////////////////////////////////////////////////////
// SCIOpenCommunication
// --------------------------------------------------------------------------------------
// Configures SCI registers for Enable Transmit and Receive data
// SCI BAUD RATE = BUSCLK/(16*BR)
// BUSCLK = 2 MHz
// BAUD RATE = 9600
// BR = 13 
// Baud rate mismatch = 0.160 %
/////////////////////////////////////////////////////////////////////////////////////////
void SCIOpenCommunication(unsigned char sci_num)
{

  unsigned char *sci_pt;

  sci[sci_num].ena = TRUE;
  sci_pt = sci[sci_num].init_reg;
  // Set Baud Rate Modulo Divisor
 //if(sci_num==0){
  
 //sci_pt[SCIBDH] =0x01;// (unsigned char)(130 >> 8);
 //sci_pt[SCIBDL] = (unsigned char)4;
 //}else{
 sci_pt[SCIBDH] =0x00;// (unsigned char)(130 >> 8);
 sci_pt[SCIBDL] = (unsigned char)100; 
 //}
  // Trasmitter and Receiver Enable
  sci_pt[SCICR2] = 0x0C;
 // SCI0CR2_RIE = 1;
  SCI0CR2_RIE = 1;
  //SCI0CR2_ILIE=1;
  //SCI1CR2_ILIE=1;
  //SCI0CR2=0X08;
}

/////////////////////////////////////////////////////////////////////////////////////////
// SCICloseCommunication
// --------------------------------------------------------------------------------------
// Configures SCI (x) registers for disable Transmit and Receive data 
/////////////////////////////////////////////////////////////////////////////////////////
void SCICloseCommunication(unsigned char sci_num)
{

  unsigned char *sci_pt;
  unsigned char data;
  unsigned int i;

  sci[sci_num].ena = FALSE;
  sci_pt = sci[sci_num].init_reg;
  i = 0;
  // Verify that Receive Data Register is FULL
  while(i < 1000 && !(sci_pt[SCISR1]&0x20))
    i++;
  if (sci_pt[SCISR1]&0x20)
    // Clear RDRF Flag¡¤                    
    data = sci_pt[SCIDRL];

  sci_pt[SCIBDH] = 0;
  sci_pt[SCIBDL] = 0;
  // Trasmitter and Receiver Disable
  sci_pt[SCICR2] = 0;
  
}

/////////////////////////////////////////////////////////////////////////////////////////
// SCISendBuffer
// --------------------------------------------------------------------------------------
// SCI Transmit Data. True if the buffer has been transmitted.
/////////////////////////////////////////////////////////////////////////////////////////
Bool SCISendBuffer(unsigned char sci_num, unsigned char buffer)
{

  unsigned char *sci_pt;

  if(!sci[sci_num].ena)
    return(FALSE);
  sci_pt = sci[sci_num].init_reg;
  // Wait until Transmit Data Register is empty.
  while(!(sci_pt[SCISR1]&0x80))
    ;
    
    
  // Send Buffer and clear TDRE flag  
  sci_pt[SCIDRL] = buffer;
  //SCI0DRL=buffer;


  
  return(TRUE);

}

/////////////////////////////////////////////////////////////////////////////////////////
// SCIGetBuffer
// --------------------------------------------------------------------------------------
// SCI Receive Data, True if the buffer has been received
/////////////////////////////////////////////////////////////////////////////////////////
Bool SCIGetBuffer(unsigned char sci_num, unsigned char *buffer)
{

  unsigned char *sci_pt;

  if(!sci[sci_num].ena)
    return(FALSE);
  sci_pt = sci[sci_num].init_reg;
  while(!(sci_pt[SCISR1]&0x20))
    ;
  // Get Buffer and clear RDRF flag
  *buffer = sci_pt[SCISR1];
  *buffer = sci_pt[SCIDRL];
  return(TRUE);

}

/////////////////////////////////////////////////////////////////////////////////////////
// SCICheckGetBuffer
// --------------------------------------------------------------------------------------
// SCI Check Receive Data, True if receiver data register (SCIDR) is full
/////////////////////////////////////////////////////////////////////////////////////////
Bool SCICheckGetBuffer(unsigned char sci_num)
{

  unsigned char *sci_pt;

  if(!sci[sci_num].ena)
    return(FALSE);
  sci_pt = sci[sci_num].init_reg;
  if(sci_pt[SCISR1]&0x20)
    return(TRUE);
  return(FALSE);

}

