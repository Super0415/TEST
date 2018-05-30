/////////////////////////////////////////////////////////////////////////////////////////
//
// Serial Communication Interface (SCI) MC9S12XEP100
//
// --------------------------------------------------------------------------------------
// Copyright (c) 2006 SofTec Microsystems
// http://www.softecmicro.com/
//
/////////////////////////////////////////////////////////////////////////////////////////
#include <hidef.h>
#include "PublicShare.h"
#include "logic.h"

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
void SCIOpenCommunication (unsigned char sci_num);
void SCICloseCommunication (unsigned char sci_num);
Bool SCISendBuffer (unsigned char sci_num, unsigned char buffer);
Bool SCIGetBuffer (unsigned char sci_num, unsigned char *buffer);
Bool SCICheckGetBuffer (unsigned char sci_num);
PUBLIC void sci_check(void);
PUBLIC void SCI_Modbus (uchar ADDR);
PUBLIC void BroadcastSend(void);
PUBLIC void CTL485(uchar CtlMode);