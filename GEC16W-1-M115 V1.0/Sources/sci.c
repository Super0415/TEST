/////////////////////////////////////////////////////////////////////////////////////////
//
// Serial Communication Interface (SCI) MC9S12XEP100
//
// --------------------------------------------------------------------------------------
// Copyright (c) 2006 SofTec Microsystems
// http://www.softecmicro.com/
//
/////////////////////////////////////////////////////////////////////////////////////////
//#include "mc9s12xet256.h"
#include "sci.h"
//#include "eee.h"

void sci_check(void)
{  
    CommTimeOut1++;
    CommTimeOut2++;    
    if (RXpt1 > 0 && CommTimeOut1 > 1)
    {
        CommTimeOut1 = 0;
        RXendpt1 = RXpt1;
        RXpt1 = 0;        
        MODBUS_CHECK1 = 0;
        RXcomplete1 = 1;
    }
    
    if (RXpt2 > 0 && CommTimeOut2 > 1)
    {
        CommTimeOut2 = 0;
        RXendpt2 = RXpt2;
        RXpt2 = 0;
        MODBUS_CHECK2 = 0;
        RXcomplete2 = 1;
    }
}

PRIVATE unsigned int CalcCRC (volatile unsigned char *ByteStart, unsigned char CalcNum)
{
    unsigned char i;
    char j;
    char LowZero;
    unsigned int CRC_REG = 0xFFFF;
    unsigned char CRC_LOW;

    for (i = 0; i < CalcNum; i++)
    {
        CRC_LOW = CRC_REG & 0xFF;
        CRC_LOW ^= * (ByteStart + i);
        CRC_REG &= 0xFF00;
        CRC_REG += CRC_LOW;

        for (j = 0; j < 8; j++)
        {
            LowZero = CRC_REG & 0x01;
            CRC_REG &= 0xFFFE;
            CRC_REG >>= 1;

            if (LowZero)
            {
                CRC_REG ^= 0xA001;
            }
        }
    }

    return CRC_REG;
} ;


void BroadcastSend(void)
{
    uchar SendData[17];
    uchar LRCDATA;
    uchar idx;
    STRFLG16 TMP;
    STRFLG8 TMP8;
    TMP.Byte=DES_SPEED;
    SendData[0]=0xB4;//固定同步头
    SendData[1]=0x0F;//帧数据长度：15
    SendData[2]=TMP.BYTES.BYTEH;//转速高八位
    SendData[3]=TMP.BYTES.BYTEL;//转速低八位
    if(OILPRESSURE>=0)
    {
        SendData[4]=OILPRESSURE/10;
    }
    else
    {
        SendData[4]=0;
    }
    if(WATERTEMP>=0)
    {
        SendData[5]=WATERTEMP;
    }
    else
    {
        SendData[5]=0;
    }    
    if(OILTEMP>=0)
    {
        SendData[6]=OILTEMP;
    }
    else
    {
        SendData[6]=0;
    } 
    TMP.Byte=PowerVoltage;
    SendData[7]=TMP.BYTES.BYTEH;//电池电压1高八位
    SendData[8]=TMP.BYTES.BYTEL;//电池电压1低八位      
    TMP.Byte=PowerVoltage2;
    SendData[9]=TMP.BYTES.BYTEH;//电池电压2高八位
    SendData[10]=TMP.BYTES.BYTEL;//电池电压2低八位      
    TMP.Byte=RUNNINGHOUR;
    SendData[11]=TMP.BYTES.BYTEH;//运行小时高八位
    SendData[12]=TMP.BYTES.BYTEL;//运行小时低八位
    
    TMP8.BITS.BIT0=ALA_SPEED_HIGH_PRE;
    TMP8.BITS.BIT1=ALA_SPEED_HIGH_STOP;
    TMP8.BITS.BIT2=ALA_TEMP_HIGH_PRE;
    TMP8.BITS.BIT3=ALA_TEMP_HIGH_STOP; 
    TMP8.BITS.BIT4=ALA_OP_LOW_PRE; 
    TMP8.BITS.BIT5=ALA_OP_LOW_STOP; 
    TMP8.BITS.BIT6=ALA_BATT_LOW_ALA;   
    TMP8.BITS.BIT7=ALA_BATT_HIGH_ALA;           
    SendData[13]=TMP8.Byte;
    
    TMP8.BITS.BIT0=ALA_START_FAIL;
    TMP8.BITS.BIT1=ALA_STOP_FAIL;
    TMP8.BITS.BIT2=ALA_OILTEMP_PRE;
    TMP8.BITS.BIT3=ALA_OILTEMP_STOP; 
    TMP8.BITS.BIT4=ALA_ESTOP; 
    TMP8.BITS.BIT5=ALA_LOSTOIL; 
    TMP8.BITS.BIT6=ALA_FUEL_LOW_PRE;   
    TMP8.BITS.BIT7=ALA_FUEL_LOW_ALA;         
    SendData[14]=TMP8.Byte;
    
    TMP8.BITS.BIT0=ALA_OPERR;
    TMP8.BITS.BIT1=ALA_WTERR;
    TMP8.BITS.BIT2=ALA_OTERR;
    TMP8.BITS.BIT3=ALA_SPEEDERR; 
    TMP8.BITS.BIT4=ALA_SAFE_LOWOP; 
    TMP8.BITS.BIT5=ALA_SAFE_HIWT; 
    TMP8.BITS.BIT6=ALA_SAFE_HIOT;   
    TMP8.BITS.BIT7=ALA_SAFE_HISPD;       
    SendData[15]=TMP8.Byte;
    
    LRCDATA=0;
    for(idx=1;idx<16;idx++)
    {
        LRCDATA+=SendData[idx];
    }
    SendData[16]=LRCDATA;
    
    CTL485(1);

    for (idx = 0; idx < 17; idx++)
    {
        (void) SCISendBuffer (0, SendData[idx]);
    }
}

//*****************************************************************************
//函数名称：  SCI_Modbus
//功能描述：  MODBUS通讯协议处理
//输入参数：  无
//输出参数：  无
//*****************************************************************************


void CTL485(uchar CtlMode)
{
#if  PCB16W

    #if ISOCOMM
        PTH_PTH1=1-CtlMode;
    #else
        PTH_PTH1 = CtlMode;
    #endif
    
    
    PORTA_PA0 = CtlMode;
#endif

#if  PCB16DW

    PTM_PTM6=1-CtlMode;

#endif
}

void SCI_Modbus (uchar ADDR)
{
    unsigned char i;
    unsigned int CRC_VALUE;
    unsigned char CRC_H;
    unsigned char CRC_L;
    unsigned char SendPort;
    unsigned int ADD = 0;
    unsigned int AddrOffset;
    unsigned int DataCount;
    unsigned char LastNumX;
    unsigned char *BUFFSTART;
    unsigned char exceptioncode = 0;
    unsigned char writeregion;

    if (RXcomplete1 && !MODBUS_CHECK1)
    {
        SendPort = 0, BUFFSTART = &ReceiveBuff1[0], LastNumX = RXendpt1;
    }
    
    else if (RXcomplete2 && !MODBUS_CHECK2)
    {
        SendPort = 1, BUFFSTART = &ReceiveBuff2[0], LastNumX = RXendpt2;
    }

    if ( (RXcomplete1 && !MODBUS_CHECK1) || (RXcomplete2 && !MODBUS_CHECK2) )
    {

        if (BUFFSTART[0] == ADDR || (RXcomplete2 && !MODBUS_CHECK2) )
        {

            CRC_VALUE = CalcCRC (BUFFSTART, LastNumX - 2);
            CRC_H = (CRC_VALUE >> 8) & 0xFF;
            CRC_L = CRC_VALUE & 0xFF;

            if (CRC_H == BUFFSTART[LastNumX-1] && CRC_L == BUFFSTART[LastNumX-2])
            {
                if (BUFFSTART[1] == 0x03)
                {
                    AddrOffset = BUFFSTART[2] * 256 + BUFFSTART[3];
                    DataCount = BUFFSTART[4] * 256 + BUFFSTART[5];
                    if (DataCount >= 1 && DataCount <= 0x007B)
                    {
                        if (AddrOffset + DataCount <= READONLY_DATA_LEN + RW_DATA_LEN)
                        {

                            if (AddrOffset >= READONLY_DATA_LEN)
                            {
                                AddrOffset -= READONLY_DATA_LEN;
                            }
                            SendBuff[0] = ADDR;
                            SendBuff[1] = 0x03;
                            SendBuff[2] = DataCount * 2;
                            for (i = 0; i < DataCount * 2; i += 2)
                            {
                                if (BUFFSTART[2] * 256 + BUFFSTART[3] < READONLY_DATA_LEN)  //!!!!!!!
                                {  // MODBUS_DATA[AddrOffset]=i;
                                    SendBuff[i+3] = (MODBUS_DATA[AddrOffset] >> 8) & 0xFF;
                                    SendBuff[i+4] = MODBUS_DATA[AddrOffset] & 0xFF;
                                }
                                else
                                {
                                    SendBuff[i+3] = (Params[AddrOffset] >> 8) & 0xFF;
                                    SendBuff[i+4] = Params[AddrOffset] & 0xFF;
                                }
                                AddrOffset++;
                            }
                            CRC_VALUE = CalcCRC (&SendBuff[0], DataCount * 2 + 3);
                            SendBuff[DataCount*2+4] = (CRC_VALUE >> 8) & 0xFF;
                            SendBuff[DataCount*2+3] = CRC_VALUE & 0xFF;
                            /*
                            if (SendPort == 0)
                            {
                                PTH_PTH1 = 1;
                            }
                            if (SendPort == 0)
                            {
                                PORTA_PA0 = 1;
                            }
                            */
                            if (SendPort == 0)
                            {
                              
                            CTL485(1);
                            }
                            for (i = 0; i < DataCount * 2 + 5; i++)
                            {
                                (void) SCISendBuffer (SendPort, SendBuff[i]);
                            }
                            if(SendPort == 0)
                            {                              
                                while (SCI0SR1_TC==0);
                            }
                            /*
                            if (SendPort == 0)
                            {
                                PTH_PTH1 = 0;
                            }
                            if (SendPort == 0)
                            {
                                PORTA_PA0 = 0;
                            }
                            */
                            if (SendPort == 0)
                            {
                            CTL485(0);
                            }
                        }
                        else
                        {
                            exceptioncode = 2;
                        }
                    }
                    else
                    {
                        exceptioncode = 3;
                    }
                }

                if (BUFFSTART[1] == 0x10)
                {
                    AddrOffset = BUFFSTART[2] * 256 + BUFFSTART[3];
                    DataCount = BUFFSTART[4] * 256 + BUFFSTART[5];
                    if (DataCount >= 1 && DataCount <= 0x007B)
                    {
                        if (AddrOffset >= 200)
                        {
                            if (AddrOffset >= 200)
                            {
                                AddrOffset -= 200;
                                writeregion = 1;
                            }
                            else
                            {
                                writeregion = 0;
                            }

                            if (AddrOffset + DataCount < 300)
                            {
                                //if (BUFFSTART[6] == LastNumX - 9)
                                if (1)
                                {
                                    for (i = 0; i < DataCount * 2; i += 2)
                                    {

                                        if (writeregion)
                                        {
                                            if(ParamCheck(AddrOffset + i / 2,BUFFSTART[7+i] * 256 + BUFFSTART[8+i]))
                                            { 
                                                Params[AddrOffset+i/2] = BUFFSTART[7+i] * 256 + BUFFSTART[8+i];
                                            
                                                if ( (AddrOffset + i / 2) < 200 && (AddrOffset + i / 2) != 2)
                                                {                                                                                                 
                                                    SaveParam (AddrOffset + i / 2,1);                                                
                                                }
                                            
                                            }
                                        }
                                        else
                                        {
                                            MODBUS_DATA[AddrOffset+i/2] = BUFFSTART[7+i] * 256 + BUFFSTART[8+i];
                                        }

                                    }
                                    if (AddrOffset == 203)
                                    {
                                        CANWRITE = 1;
                                    }
                                    if (AddrOffset == 205 || AddrOffset == 207)
                                    {
                                        EnWriteTime = 1;
                                    }
                                    SendBuff[0] = BUFFSTART[0];
                                    SendBuff[1] = BUFFSTART[1];
                                    SendBuff[2] = BUFFSTART[2];
                                    SendBuff[3] = BUFFSTART[3];
                                    SendBuff[4] = BUFFSTART[4];
                                    SendBuff[5] = BUFFSTART[5];
                                    CRC_VALUE = CalcCRC (&SendBuff[0], 6);
                                    SendBuff[6] = CRC_VALUE & 0xFF;
                                    SendBuff[7] = (CRC_VALUE >> 8) & 0xFF;
                                    /*
                                    if (SendPort == 0)
                                    {
                                        PTH_PTH1 = 1;
                                    }
                                    if (SendPort == 0)
                                    {
                                        PORTA_PA0 = 1;
                                    }
                                    */
                                    if (SendPort == 0)
                                    {                                    
                                        CTL485(1);
                                    }
                                    for (i = 0; i < 8; i++)
                                    {
                                        (void) SCISendBuffer (SendPort, SendBuff[i]);
                                    }
                                                                if(SendPort == 0)
                            {                              
                                while (SCI0SR1_TC==0);
                            }
                                    /*
                                    if (SendPort == 0)
                                    {
                                        PTH_PTH1 = 0;
                                    }
                                    if (SendPort == 0)
                                    {
                                        PORTA_PA0 = 0;
                                    }
                                    */
                                   if (SendPort == 0)
                                    {
                                        CTL485(0);
                                    }
                                }
                            }
                            else
                            {
                                exceptioncode = 2;
                            }
                        }
                        else
                        {
                            exceptioncode = 2;
                        }
                    }
                    else
                    {
                        exceptioncode = 3;
                    }
                }


                if (BUFFSTART[1] != 0x03 && BUFFSTART[1] != 0x10)
                {
                    exceptioncode = 1;
                }

                if (exceptioncode > 0)
                {
                    SendBuff[0] = BUFFSTART[0];
                    SendBuff[1] = BUFFSTART[1] | 0x80;
                    SendBuff[2] = exceptioncode;
                    CRC_VALUE = CalcCRC (&SendBuff[0], 3);
                    SendBuff[3] = CRC_VALUE & 0xFF;
                    SendBuff[4] = (CRC_VALUE >> 8) & 0xFF;
                    /*
                    if (SendPort == 0)
                    {
                        PTH_PTH1 = 1;
                    }
                    if (SendPort == 0)
                    {
                        PORTA_PA0 = 1;
                    }
                    */
                    if (SendPort == 0)
                            {                    
                        CTL485(1);
                    }
                    for (i = 0; i < 5; i++)
                    {
                        (void) SCISendBuffer (SendPort, SendBuff[i]);
                    }
                                                if(SendPort == 0)
                            {                              
                                while (SCI0SR1_TC==0||0);
                               CTL485(0);  
                            }


                }




                                            if(SendPort == 0)
                            {                              
                                while (SCI0SR1_TC==0||0);
                                CTL485(0);
                            }
                            /*
                if (SendPort == 0)
                {
                    PTH_PTH1 = 0;
                }
                if (SendPort == 0)
                {
                    PORTA_PA0 = 0;
                }
                */
                
            }

        }
        if (SendPort == 0)
        {
            MODBUS_CHECK1 = 1;
        }
        if (SendPort == 1)
        {
            MODBUS_CHECK2 = 1;
            SCI1CR2_RIE = 1;
        }
    }



}


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
struct sci_peripheral
{
    Bool ena;
    unsigned char *init_reg;
} sci[2] =
{
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
void SCIOpenCommunication (unsigned char sci_num)
{
    unsigned char *sci_pt;
    sci[sci_num].ena = TRUE;
    sci_pt = sci[sci_num].init_reg;

    // Set Baud Rate Modulo Divisor
    if (sci_num == 0)
    {

        //if(COMMTYPE==0)//MODBUS波特率4800
        //{          
        //    sci_pt[SCIBDH] = 0x01; // (unsigned char)(130 >> 8);
       //     sci_pt[SCIBDL] = (unsigned char) 4;
       // }
        //else            //广播波特率9600
        /*
        {
            sci_pt[SCIBDH] = 0x00; 
            sci_pt[SCIBDL] = 0x82;       
        }
        */
        
        #if BOUND9600
          sci_pt[SCIBDH] = 0x00; 
          sci_pt[SCIBDL] = 0x82;  
        #endif
        
        #if BOUND4800
          sci_pt[SCIBDH] = 0x01; 
          sci_pt[SCIBDL] = (unsigned char) 4;  
        #endif
    }
    else
    {
        sci_pt[SCIBDH] = 0x00; // (unsigned char)(130 >> 8);
        sci_pt[SCIBDL] = (unsigned char) 50;
    }

    // Trasmitter and Receiver Enable
    sci_pt[SCICR2] = 0x0C;
    SCI0CR2_RIE = 1;
    SCI1CR2_RIE = 1;
    #if PCB16W
    DDRH_DDRH1=1;
    DDRA_DDRA0=1;
    #endif
    #if PCB16DW
    DDRM_DDRM6=1;
    CTL485(0);
    #endif
    
    //SCI0CR2_ILIE=1;
    //SCI1CR2_ILIE=1;
    //SCI0CR2=0X08;
}

/////////////////////////////////////////////////////////////////////////////////////////
// SCICloseCommunication
// --------------------------------------------------------------------------------------
// Configures SCI (x) registers for disable Transmit and Receive data
/////////////////////////////////////////////////////////////////////////////////////////
void SCICloseCommunication (unsigned char sci_num)
{
    unsigned char *sci_pt;
    unsigned char data;
    unsigned int i;
    sci[sci_num].ena = FALSE;
    sci_pt = sci[sci_num].init_reg;
    i = 0;

    // Verify that Receive Data Register is FULL
    while (i < 1000 && ! (sci_pt[SCISR1] & 0x20) )
    {
        i++;
    }

    if (sci_pt[SCISR1] & 0x20)
        // Clear RDRF Flag·
    {
        data = sci_pt[SCIDRL];
    }

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
Bool SCISendBuffer (unsigned char sci_num, unsigned char buffer)
{
    unsigned char *sci_pt;

    if (!sci[sci_num].ena)
    {
        return (FALSE);
    }

    sci_pt = sci[sci_num].init_reg;

    // Wait until Transmit Data Register is empty.
    while (! (sci_pt[SCISR1] & 0x80) )
        ;

    // Send Buffer and clear TDRE flag
    sci_pt[SCIDRL] = buffer;
    //SCI0DRL=buffer;
    return (TRUE);
}

/////////////////////////////////////////////////////////////////////////////////////////
// SCIGetBuffer
// --------------------------------------------------------------------------------------
// SCI Receive Data, True if the buffer has been received
/////////////////////////////////////////////////////////////////////////////////////////
Bool SCIGetBuffer (unsigned char sci_num, unsigned char *buffer)
{
    unsigned char *sci_pt;

    if (!sci[sci_num].ena)
    {
        return (FALSE);
    }

    sci_pt = sci[sci_num].init_reg;

    while (! (sci_pt[SCISR1] & 0x20) )
        ;

    // Get Buffer and clear RDRF flag
    *buffer = sci_pt[SCISR1];
    *buffer = sci_pt[SCIDRL];
    return (TRUE);
}

/////////////////////////////////////////////////////////////////////////////////////////
// SCICheckGetBuffer
// --------------------------------------------------------------------------------------
// SCI Check Receive Data, True if receiver data register (SCIDR) is full
/////////////////////////////////////////////////////////////////////////////////////////
Bool SCICheckGetBuffer (unsigned char sci_num)
{
    unsigned char *sci_pt;

    if (!sci[sci_num].ena)
    {
        return (FALSE);
    }

    sci_pt = sci[sci_num].init_reg;

    if (sci_pt[SCISR1] & 0x20)
    {
        return (TRUE);
    }

    return (FALSE);
}

