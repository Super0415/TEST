#include "io.h"
/*
 unsigned char DI1;
 unsigned char DI2;
 unsigned char DI3;
 unsigned char DI4;
 unsigned char DI5;
 unsigned char DI6;
 unsigned char DI7;
 unsigned char DO1;
 unsigned char DO2;
 unsigned char DO3;
 unsigned char DO4;
 unsigned char DO5;
 unsigned char DO6;
 unsigned char DO7;
*/
 uchar LampByte=0;
 
#define EDI1 EXTERNINPUT.BITS.BIT7
#define EDI2 EXTERNINPUT.BITS.BIT6
#define EDI3 EXTERNINPUT.BITS.BIT5
#define EDI4 EXTERNINPUT.BITS.BIT4
#define EDI5 EXTERNINPUT.BITS.BIT3
#define EDI6 EXTERNINPUT.BITS.BIT2
#define EDI7 EXTERNINPUT.BITS.BIT1
#define EDI8 EXTERNINPUT.BITS.BIT0

#define EDO1 EXTERNOUTPUT.BITS.BITD
#define EDO2 EXTERNOUTPUT.BITS.BITC
#define EDO3 EXTERNOUTPUT.BITS.BITB
#define EDO4 EXTERNOUTPUT.BITS.BITA
#define EDO5 EXTERNOUTPUT.BITS.BITE
#define EDO6 EXTERNOUTPUT.BITS.BITF
#define EDO7 EXTERNOUTPUT.BITS.BIT0
#define EDO8 EXTERNOUTPUT.BITS.BIT1
#define EDO9 EXTERNOUTPUT.BITS.BIT2
#define EDO10 EXTERNOUTPUT.BITS.BIT3
#define EDO11 EXTERNOUTPUT.BITS.BIT4
#define EDO12 EXTERNOUTPUT.BITS.BIT5
#define EDO13 EXTERNOUTPUT.BITS.BIT6
#define EDO14 EXTERNOUTPUT.BITS.BIT7
 
//*****************************************************************************
//函数名称：  UpdateIO
//功能描述：  输入输出口刷新
//输入参数：  无
//输出参数：  无
//*****************************************************************************
void UpdateIO (void)
{

    STRFLG8 TMPINPUT;
    uchar i;
    int * ptPOL;
    unsigned char idx; 

    
    if(NowMode==1)
    {
        DO_LOCAL=1;
    }
    else
    {
        DO_LOCAL=0;
    }
    
    if(NowMode==2)
    {
        DO_AUTO=1;
    }
    else
    {
        DO_AUTO=0;
    }
    
    if(NowMode==3)
    {
        DO_REMOTE=1;
    }
    else
    {
        DO_REMOTE=0;
    }        
        
    if (DO_IDLE)
    {
        DO_IDLE_REV = 0;
    }
    else
    {
        DO_IDLE_REV = 1;
    }
    if (DI_ESTOP)
    {
        ALA_ESTOP = 1;
    }
    //if(DI_RESIS_FAULT)ALA_RESISFAIL=1;else ALA_RESISFAIL=0;
    if (DO_START)
    {
        DO_CHARGE = 0;
    }
    else
    {
        DO_CHARGE = 1;
    }
    
    
    DO_ESTOP=DI_ESTOP;
    /*
    if (DO_GCB || DI_GCB)
    {
        STA_DES_GCB = 1;
    }
    else
    {
        STA_DES_GCB = 0;
    }
    */
    
    //STA_DES_GCB=1;
    
    /*
    if (AMF_MCB_LOGIC == 0)
    {

        if (DO_MCB || DI_MCB)
        {
            STA_DES_MCB = 1;
        }
        else
        {
            STA_DES_MCB = 0;
        }
    }
    else
    {
        if (DO_MCB == 0 || DI_MCB)
        {
            STA_DES_MCB = 1;
        }
        else
        {
            STA_DES_MCB = 0;
        }
    }
    */

    if (STA_DES_PREHEAT)
    {
        DO_PRESTART = 1;
    }
    else
    {
        DO_PRESTART = 0;
    }
    
    

    if (FUEL / 10 <= DES_FUEL_ON)
    {
        DO_FUELPUMP = 1;
    }
    if (FUEL / 10 >= DES_FUEL_OFF)
    {
        DO_FUELPUMP = 0;
    }
    if (WATERTEMP >= DES_TEMP_ON)
    {
        DO_TEMPONOFF = 1;
    }
    if (WATERTEMP <= DES_TEMP_OFF)
    {
        DO_TEMPONOFF = 0;
    }
    
    DO_PRELUB=DO_PRESTART;
    
    if(ALA_OP_LOW_STOP)
    {
        DO_DES_LOWOP_ALA=1;
    }
    else
    {
        DO_DES_LOWOP_ALA=0;
    }
    
    if(ALA_OP_LOW_PRE)
    {
        DO_DES_LOWOP_PRE=1;
    }
    else
    {
        DO_DES_LOWOP_PRE=0;
    }

    if(ALA_TEMP_HIGH_STOP)
    {
        DO_DES_HIGHWT_ALA=1;
    }
    else
    {
        DO_DES_HIGHWT_ALA=0;
    }
    
    if(ALA_TEMP_HIGH_PRE)
    {
        DO_DES_HIGHWT_PRE=1;
    }
    else
    {
        DO_DES_HIGHWT_PRE=0;
    }
    
    if(ALA_OP_LOW_PRE||ALA_TEMP_HIGH_PRE||ALA_SPEED_HIGH_PRE||ALA_OILTEMP_PRE
    ||ALA_BATT_LOW_ALA||ALA_BATT_HIGH_ALA||ALA_FUEL_LOW_PRE||ALA_LOSTOIL
    ||ALA_OPERR||ALA_WTERR||ALA_OTERR||ALA_SPEEDERR||ALA_OILTEMP_PRE||ALA_SPEEDERR2
    ||ALA_DPLUSFAIL||ALA_COILTEMP||ALA_DES_STARTLOW||ALA_DES_SWPLOW||ALA_DES_WPLOW
    ||ALA_GENLEAK||ALA_COOLINGFAN||ALA_WATERPLOW
    )
    {
        DO_ALARMS_PRE=1;
    }
    else
    {
        DO_ALARMS_PRE=0;
    }
    
    if(ALA_SPEED_HIGH_PRE)
    {
        DO_DES_ALARM_OVERSPEED_PRE=1;
    }
    else
    {
        DO_DES_ALARM_OVERSPEED_PRE=0;
    }
    
    if(ALA_SPEED_HIGH_STOP)
    {
        DO_DES_ALARM_OVERSPEED_ALA=1;
    }
    else
    {
        DO_DES_ALARM_OVERSPEED_ALA=0;
    }    
    
    if(ALARMSTOP)
    {
        DO_ALARMS_STOP=1;
    }
    else
    {
        DO_ALARMS_STOP=0;        
    }
    
    if(DO_COMMON_ALA==0 && STA_DES_STOP)
    {
        DO_PREPARE_OK=1;
    }
    else
    {
        DO_PREPARE_OK=0;
    }
    #if GEC16P_MODE==0
   // DOUTPUT=DO_START;
    #endif
    
    TMPINPUT.Byte = FORCEINPUT & 0xFF;


    for(i=0;i<50;i++)
    {
        INPUT_TEMP[i]=0;
    }


     ptPOL=&IO_INPUT_POL1;
     
    for(i=0;i<11;i++)
    {
    if(*(ptPOL+i*2)==0)  //常开
    {
        if(DI[i])
        {
            TimerEnArr[TMR_DI1_DEL+i]=1;
        }
        else
        {
            TimerEnArr[TMR_DI1_DEL+i]=0;            
            TimerTrig[TMR_DI1_DEL+i]=0; 
        }
    }
    else
    {
        if(DI[i]==0)
        {
            TimerEnArr[TMR_DI1_DEL+i]=1;
        }
        else
        {
            TimerEnArr[TMR_DI1_DEL+i]=0;            
            TimerTrig[TMR_DI1_DEL+i]=0; 
        }    
    }
    
    if(i<7)
    {
      
    if(TimerTrig[TMR_DI1_DEL+i])
    {
         
         INPUT_TEMP[*(&IO_INPUT_CONFIG1+i)]|=1;    
    } 
    }
    else
    {
    
    if(TimerTrig[TMR_DI1_DEL+i])
    {
         
         INPUT_TEMP[*(&IO_INPUT_CONFIG8+i-7)]|=1;    
    }    
    
    }
    
    }


    /*

    INPUT_TEMP[IO_INPUT_CONFIG1] = DI[0];
    INPUT_TEMP[IO_INPUT_CONFIG2] = DI[1];
    INPUT_TEMP[IO_INPUT_CONFIG3] = DI[2];
    INPUT_TEMP[IO_INPUT_CONFIG4] = DI[3];
    INPUT_TEMP[IO_INPUT_CONFIG5] = DI[4];
    INPUT_TEMP[IO_INPUT_CONFIG6] = DI[5];
    INPUT_TEMP[IO_INPUT_CONFIG7] = DI[6];

    INPUT_TEMP[IO_INPUT_CONFIG8] = DI[7];
    INPUT_TEMP[IO_INPUT_CONFIG9] = DI[8];
    INPUT_TEMP[IO_INPUT_CONFIG10] = DI[9];
    INPUT_TEMP[IO_INPUT_CONFIG11] = DI[10];

   */
    
    DI_SPRINGINPUT|=EDI5;
    //DOUTPUT=DO_START;
    
    #if B_MODE
   // DI_ESTOP=1-DI_ESTOP;
    #endif
     /*
    if (DI_MCB == 1)
    {
        LampByte |= 0x08;
    }
    else
    {
        LampByte &= ~0x08;
    }
    */
    
    #if FEIERTE_MODE
    if (DO_GCB == 1)
    {
        LampByte |= 0x04;
    }
    else
    {
        LampByte &= ~0x04;
    }
    #else
/*
    if (DI_GCB == 1 || DO_GCB == 1)
    {
        LampByte |= 0x04;
    }
    else
    {
        LampByte &= ~0x04;
    }
  */
    #endif


    if (STA_BUS_NORMAL == 0)
    {
        LampByte &= ~0x10;
        LampByte |= 0x20;
    }
    else
    {
        LampByte &= ~0x20;
        LampByte |= 0x10;
    }

    if ((STA_DES_ALARMS||BUSALA.Byte>0) && NOBUZZER == 0 && SPLASH_500ms == 1)
    {
        DO_BUZZER = 1;
    }
    else
    {
        DO_BUZZER = 0;
    }

    if ((STA_DES_ALARMS||BUSALA.Byte>0) && NOBUZZER == 0 && DES_BUZZ_TIME != 0)
    {
        TimerEnArr[TMR_BUZZER] = 1;
    }
    else
    {
        TimerEnArr[TMR_BUZZER] = 0, TimerTrig[TMR_BUZZER] = 0;
    }
    
    if (TimerTrig[TMR_BUZZER])
    {
        DO_BUZZER = 0;
    }

    if (STA_DES_ALARMS || BUSALA.Byte>0 || STA_DES_PREALARMS)
    {
        LampByte |= 0x01;
    }
    else
    {
        LampByte &= 0xFE;
    }

    if(STA_DES_ALARMS||BUSALA.Byte>0)
    {      
        DO_COMMON_ALA=1;
    }
    else
    {
        DO_COMMON_ALA=0;
    }

    #if B_MODE
    if (STA_DES_RUNNING)
    #else
    if (STA_GEN_RUNNING)
    #endif
    {
        LampByte |= 0x02;
    }
    else
    {
        LampByte &= 0xFD;
    }

    
    if(DES_SPEED!=-32768 )    
    {
        if(DES_SPEED>=DES_RATING_ROTATION-10)
        {      
            DO_GEN_RUNNING=1;
        }
        else if(DES_SPEED<=DES_RATING_ROTATION-50)
        {
             DO_GEN_RUNNING=0;
        }        
    }
    else
    {
        DO_GEN_RUNNING=0;
    }
    
   
   /* 
    if(STA_DES_START_SUCC)
    {
        DO_GEN_RUNNING=1;
    }
    else
    {
        DO_GEN_RUNNING=0;
    }
    */
    

    LIGHTSTATUS = LampByte;
    if (NOBUZZER)
    {
        LIGHTSTATUS &= 0x3F;
    }
    else
    {
        LIGHTSTATUS |= 0xC0;
    }
    if(Params[230]>0)
    {
        
        DO_BUZZER=SELF_TEST_BUZZER;
    }
    
    DO[0] = OUTPUT_TEMP[IO_OUTPUT_CONFIG1];
    DO[1] = OUTPUT_TEMP[IO_OUTPUT_CONFIG2];
    DO[2] = OUTPUT_TEMP[IO_OUTPUT_CONFIG3];
    DO[3] = OUTPUT_TEMP[IO_OUTPUT_CONFIG4];
    DO[4] = OUTPUT_TEMP[IO_OUTPUT_CONFIG5];
    DO[5] = OUTPUT_TEMP[IO_OUTPUT_CONFIG6];
    DO[6] = OUTPUT_TEMP[IO_OUTPUT_CONFIG7];
    #if B_MODE
    DO[7] = OUTPUT_TEMP[IO_OUTPUT_CONFIG8];
    DO[8] = OUTPUT_TEMP[IO_OUTPUT_CONFIG9];
    DO[9] = OUTPUT_TEMP[IO_OUTPUT_CONFIG10];
    DO[10] = OUTPUT_TEMP[IO_OUTPUT_CONFIG11];
    DO[11] = OUTPUT_TEMP[IO_OUTPUT_CONFIG12];
    DO[12] = OUTPUT_TEMP[IO_OUTPUT_CONFIG13];
    DO[13] = OUTPUT_TEMP[IO_OUTPUT_CONFIG14];
    #endif
    
    #if B_MODE
    EO_OILP_LOW     =   ALA_OP_LOW_PRE; 
    EO_OILT_HIGH    =   ALA_OILTEMP_PRE;
    EO_STARTSUCC    =   STA_DES_START_SUCC;
    EO_STARTFAIL    =   ALA_START_FAIL;
    EO_BATT_LOW     =   ALA_BATT_LOW_ALA;
    EO_WATERT_HIGH  =   ALA_TEMP_HIGH_PRE;
    
    EO_COMMALA      =   DO_COMMON_ALA;
    DO_OILTEMP_HIGH =   ALA_OILTEMP_STOP || ALA_OILTEMP_PRE;  
    DO_DES_BATT     =   ALA_BATT_LOW_ALA;

    if(SpeedError ==0 && DES_SPEED<=8*(ulong)DES_RATING_ROTATION/10)
    {      
        TimerEnArr[TMR_WPLOW]=0;
        TimerEnArr[TMR_SWPLOW]=0; 
        for(idx=0;idx<7;idx++)
        {
            if(*(&IO_INPUT_CONFIG1+idx)==15)
            { 
                TimerEnArr[TMR_DI1_DEL+idx]=0;
                TimerTrig[TMR_DI1_DEL+idx]=0;
            }
        } 
        
        for(idx=0;idx<4;idx++)
        {
            if(*(&IO_INPUT_CONFIG8+idx)==15)
            { 
                TimerEnArr[TMR_DI8_DEL+idx]=0;
                TimerTrig[TMR_DI8_DEL+idx]=0;
            }       
        }
          
    }
    else
    {
        TimerEnArr[TMR_WPLOW]=DI_WPLOW;
        TimerEnArr[TMR_SWPLOW]=DI_SWPLOW;
    }
    
    TimerEnArr[TMR_FUELLOW]=DI_FUELLOW;
    TimerEnArr[TMR_SPLOW]=DI_SPLOW;
    TimerEnArr[TMR_GENLEAK]=DI_GENLEAK;
    TimerEnArr[TMR_COILTEMP]=DI_COILTEMPHIGH;
    TimerEnArr[TMR_FUEL_LEAK]=DI_FUEL_LEAK;
    TimerEnArr[TMR_LOW_LEVEL]=DI_LOWLEVEL;


ALA_LOSTOIL       = TimerTrig[TMR_FUEL_LEAK];    
ALA_LOWLEVEL      = TimerTrig[TMR_LOW_LEVEL]; 
ALA_DES_WPLOW     = TimerTrig[TMR_WPLOW];
ALA_DES_SWPLOW    = TimerTrig[TMR_SWPLOW];
ALA_FUEL_LOW_ALA  = TimerTrig[TMR_FUELLOW];
ALA_DES_STARTLOW  = TimerTrig[TMR_SPLOW];
ALA_GENLEAK       = TimerTrig[TMR_GENLEAK];
ALA_COILTEMP      = TimerTrig[TMR_COILTEMP];


   

   if(TimerTrig[TMR_RESET_DELAY])
   {
       TimerTrig[TMR_RESET_DELAY]=0;
   }
    
    if(TimerEnArr[TMR_RESET_DELAY]==0)
    {
      
    if(OilPressureLow2)
    {
        ALA_SAFE_LOWOP=1;
    }
    if(WTHI2)
    {
        ALA_SAFE_HIWT=1;
    }
    if(OTHI2)
    {
        ALA_SAFE_HIOT=1;
    }
 
    
    ALA_SAFE_HISPD=SpeedHigh2;
    
    NO_STOP=EMER_MODE|DI_EXTERN_NOSTOP;
    DI_NOSTOP=NO_STOP;
    
}
    #endif          


    
    

    



}