/////////////////////////////////////////////////////////////////////////////////////////
//
// Serial Communication Interface (SCI) MC9S12XEP100
//
// --------------------------------------------------------------------------------------
// Copyright (c) 2006 SofTec Microsystems
// http://www.softecmicro.com/
// 
/////////////////////////////////////////////////////////////////////////////////////////
#ifndef _SCI_H
#define _SCI_H
#include <hidef.h>
#include "extern.h"
#include "defs.h"
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
#define SCI_0             0
#define SCI_1             1

#define SCIBDH            0x00
#define SCIBDL            0x01
#define SCICR1            0x02
#define SCIASR1           0x00
#define SCIACR1           0x01
#define SCIACR2           0x02
#define SCICR2            0x03
#define SCISR1            0x04
#define SCISR2            0x05
#define SCIDRH            0x06
#define SCIDRL            0x07

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
#define SYS_ADDR 1
PUBLIC volatile unsigned char ReceiveBuff[100];
PUBLIC volatile unsigned char SendBuff[100];
PUBLIC volatile unsigned char LastNum;
PUBLIC volatile unsigned char NowChar;
PUBLIC volatile unsigned char RXcomplete;
PUBLIC volatile char MODBUS_CHECK;
PUBLIC volatile unsigned int AddrOffset;
void SCIOpenCommunication(unsigned char sci_num);
void SCICloseCommunication(unsigned char sci_num);
Bool SCISendBuffer(unsigned char sci_num, unsigned char buffer);
Bool SCIGetBuffer(unsigned char sci_num, unsigned char *buffer);
Bool SCICheckGetBuffer(unsigned char sci_num);
extern unsigned int CalcCRC(volatile unsigned char *ByteStart,unsigned char CalcNum);
PUBLIC void SCIProcess(void);
PUBLIC void SciCommand(uchar cmd, uint addr_des, uchar op_num, int* data_addr, uchar write_num);
PUBLIC void SciReadValue(uint Pnum,uchar Rnum);
PUBLIC void SciWriteParam(uint Pnum,int *ValueAddr,uchar Wnum);
#endif