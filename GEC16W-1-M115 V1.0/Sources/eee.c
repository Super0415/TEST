#include "PublicShare.h"
#include "fact_parameter.h"
#include "clock.h"
#include "logic.h"

#pragma push

#pragma DATA_SEG PAGED_RAM
int RECBUFF[260];
uchar REC_PT = 0;
#pragma pop

#pragma DATA_SEG DEFAULT
#define LOAD_FACT_PAR 0
//******************************
//set value of DFPART and ERPART
#define DFPART 0
#define ERPART 16
//{0,16} means that whole Buffer RAM and whole D-Flash is used for Emulated EEPROM
//******************************
#define OK  0
#define ERROR 1



uint  * __eptr  recaddr; // =  0x000800;
uint  * __eptr  recaddr2;// =  0x010800;
uint  * __eptr  recaddr3;// =  0x020800;
uchar * __eptr  recaddrchar;


uint RECBUFFPT = 0;
RECORD MYRECORD;

PRIVATE void eee_memcpy(uchar  * ptr_dest0,uchar * far ptr_src, uint size)
{
	while(size-- >0)
	{
    *ptr_dest0++ = *ptr_src++;
		//*ptr_dest1++ = *ptr_src++;
	}
}
PRIVATE void eee_save(uchar * far ptr_dest, uchar * ptr_src, uint offset,uint size)
{
	while(size-- >0)
	{
    *(ptr_dest+offset) = *(ptr_src+offset);
    ptr_dest++;
    ptr_src++;
    
	}
}
//==============================================================================
//DFLASH_Full_Partition
//==============================================================================
PRIVATE void eee_DFLASH_Full_Partition(unsigned int set_DFPART, unsigned int set_ERPART)
{
  while(FSTAT_CCIF == 0); //wait if command in progress
  FSTAT = 0x30;           //clear ACCERR and PVIOL
  
  FCCOBIX = 0x00;     
  FCCOB = 0x0F00;         //Full Partition D-Flash Command  
  FCCOBIX = 0x01;   
  FCCOB = set_DFPART;
  FCCOBIX = 0x02;   
  FCCOB = set_ERPART;        
      
  FSTAT_CCIF = 1;         //launch command
  while(FSTAT_CCIF == 0); //wait for done  
 /*
  if(FSTAT_ACCERR == 0)
    return OK;
  else
    return ERROR;
*/
}
//==============================================================================
//EEE_Disable
//==============================================================================
PRIVATE void EEE_Disable(void)
{
  FSTAT = 0x30;     //clear ACCERR and PVIOL
  
  FCCOBIX = 0x00;   
  FCCOB = 0x1400;   //disable EEPROM Emulation Command
    
  FSTAT_CCIF = 1;   //launch command
  while(FSTAT_CCIF == 0); //wait for done  
}

//==============================================================================
//EEE_Enable
//==============================================================================
PRIVATE void EEE_Enable(void)
{
  while(FSTAT_CCIF == 0); //wait if command in progress
  FSTAT = 0x30;           //clear ACCERR and PVIOL
  
  FCCOBIX = 0x00;   
  FCCOB = 0x1300;         //enable EEPROM Emulation Command
    
  FSTAT_CCIF = 1;         //launch command
  while(FSTAT_CCIF == 0); //wait for done  
}
//==============================================================================
//EEE_access
//==============================================================================
PRIVATE void eee_access(void)
{
	while(FSTAT_CCIF == 0); 	//wait for FTM ready	
	FCLKDIV = 0x07; 					//set prescaler for flash clock (0x0F for 8MHz osc)  
	while(FSTAT_CCIF == 0); 	//wait for FTM ready	
	MMCCTL1_EEEIFRON = 1; 		//enable EEEIFR in memory map
	if((*(unsigned int *far)0x120000 != DFPART) || (*(unsigned int *far)0x120004 != ERPART))
	{
		eee_DFLASH_Full_Partition(DFPART,ERPART); 		 
	} 
}

//************************************************************************************
//name：  eee_load_par()
//function：  load parameter from the eeeprom
//input：
//output：
//************************************************************************************
PUBLIC void eee_load_par(void)
{
 uchar i;
 eee_memcpy((uchar *)&Params[0],&PARAMS_EEE,400);
 for (i=0;i<200;i++)
 {
     if(Params[i]==0xFFFF)
     {
         Params[i]=0;
     }
 }
 TransParams();
}
void SaveParam (unsigned int PN,unsigned int Len)
{
    eee_access();
		EEE_Enable();
	  eee_save(((uchar * far)&PARAMS_EEE[PN*2]),((uchar *)&Params[PN]),0,Len*2);
	  while((ETAG > 0) || (FSTAT_MGBUSY == 1)); //we can wait for EEE to finish
		EEE_Disable();	//the emulation is disabled. We can write into Buffer RAM but
		TransParams();
}


void SetDefaultParam (void)
{
    uchar i;

    for (i = 0; i < 180; i++)
    {
        Params[i] = ParamsDefault[i+1];
        
    }
    SaveParam (0,180);

}


//*****************************************************************************
//函数名称：  WriteRecEEP
//功能描述：  写入EEPROM记录数据
//输入参数：  无
//输出参数：  无
//*****************************************************************************

void WriteRecEEP (unsigned int PN, int value,  int offset)
{    
    uchar epage;
    STRFLG16 TMP;
    
    if (PN >= 60)
    {
        return;
    }

    
    PN = PN * RECNUM;

    if (PN < 500)
    {
        epage = 1;
    }
    
    if (PN >= 500 && PN < 1000)
    {
        epage = 2, PN = PN - 500;
    }
    
    if (PN >= 1000 && PN < 1500)
    {
        epage = 3, PN = PN - 1000;
    }           




    if (epage == 1)
    {
        recaddrchar = &RECORD_P1_EEE;
    }
    
    if (epage == 2)
    {
        recaddrchar = &RECORD_P2_EEE;
    }
    
    if (epage == 3)
    {
        recaddrchar = &RECORD_P3_EEE;
    }
    
    PN *=2;   
    TMP.Byte=value;
    eee_access();
		EEE_Enable();
    * (recaddrchar + PN + offset*2) = TMP.BYTES.BYTEH;
    * (recaddrchar + PN + offset*2 + 1) = TMP.BYTES.BYTEL;
    while((ETAG > 0) || (FSTAT_MGBUSY == 1)); //we can wait for EEE to finish
		EEE_Disable();	//the emulation is disabled. We can write into Buffer RAM but
		//TransParams();    
}

//*****************************************************************************
//函数名称：  LoadRecord
//功能描述：  写入EEPROM记录数据
//输入参数：  Arr数据数组指针
//输入参数：  PN编号
//输出参数：  无
//*****************************************************************************

void LoadRecord (int *Arr, int PN)
{
    uchar epage;
    uchar TmpIdx = 0;

    if (PN > 59)
    {
        PN = PN - 60;
    }
    if (PN < 0)
    {
        PN += 60;
    }


    PN = PN * RECNUM;

    if (PN < 500)
    {
        epage = 1;
    }
    if (PN >= 500 && PN < 1000)
    {
        epage = 2, PN = PN - 500;
    }
    if (PN >= 1000 && PN < 1500)
    {
        epage = 3, PN = PN - 1000;
    }

    if (epage == 1)
    {
        recaddr = &RECORD_P1_EEE;
    }

    if (epage == 2)
    {
        recaddr = &RECORD_P2_EEE;
    }

    if (epage == 3)
    {
        recaddr = &RECORD_P3_EEE;
    }

    for (TmpIdx = 0; TmpIdx < RECNUM; TmpIdx++)
    {
        Arr[TmpIdx] = * (recaddr + TmpIdx + PN);
        if (Arr[TmpIdx] == 0xFFFF)
        {
            Arr[TmpIdx] = 0;
        }
    }

}


//*****************************************************************************
//函数名称：  LoadRecordSets
//功能描述：  载入记录到内存
//输入参数：  无
//输出参数：  无
//*****************************************************************************
void LoadRecordSets (void)
{
    char i;
    unsigned char GETPT;
    unsigned char j;

    STRFLG16 tmpdata;
    if (RECBUFFPT > 0)
    {
        return;
    }
    LoadRecord (MYRECORD.ARRAY, REC_POINTER);
    for (j = 0; j < RECNUM; j++)
    {
        * (REC_DETAIL + j) = MYRECORD.ARRAY[j];
    }

    //if((REC_POINTER+2)%5==0||(REC_POINTER-2)%5==0)
    // {

    for (i = 1; i < 5; i++)
    {
        //if(REC_POINTER+i>59)GETPT=REC_POINTER-60+i;else GETPT=RECPOINTER;
        LoadRecord (MYRECORD.ARRAY, REC_POINTER + i - 2);
        tmpdata.BYTES.BYTEH = MYRECORD.MEMBER.RecNum;
        tmpdata.BYTES.BYTEL = MYRECORD.MEMBER.Reason;
        * (&REC_DATA1 + i) = tmpdata.Byte;
    }

    //  }


}

//*****************************************************************************
//函数名称：  SaveRecord
//功能描述：  载入记录到内存
//输入参数：  idx    记录编号
//输入参数：  Reason 记录原因
//输出参数：  无
//*****************************************************************************

void SaveRecord (unsigned int idx, unsigned int Reason)
{
    unsigned char i;
    RECORD NOWREC;
    NOWREC.MEMBER.RecNum = idx;
    NOWREC.MEMBER.Reason = Reason;
    NOWREC.MEMBER.DateL.BITS4.L4 = DATEVALUE[6] % 10; //年BCD低
    NOWREC.MEMBER.DateL.BITS4.H4 = DATEVALUE[6] / 10; //年BCD高
    NOWREC.MEMBER.DateH.BITS4.L4 = DATEVALUE[4] % 10; //日BCD低
    NOWREC.MEMBER.DateH.BITS4.H4 = DATEVALUE[4] / 10; //日BCD高
    NOWREC.MEMBER.TimeL.BITS4.L4 = DATEVALUE[5];  //月    
    NOWREC.MEMBER.TimeH.BITS4.L4 = DATEVALUE[0] % 10; //秒BCD低
    NOWREC.MEMBER.TimeH.BITS4.H4 = DATEVALUE[0] / 10; //秒BCD高
    NOWREC.MEMBER.Time2.BITS4.L4 = DATEVALUE[1] % 10; //分BCD低
    NOWREC.MEMBER.Time2.BITS4.H4 = DATEVALUE[1] / 10; //分BCD高
    NOWREC.MEMBER.Time3.BITS4.L4 = DATEVALUE[2] % 10; //时BCD低
    NOWREC.MEMBER.Time3.BITS4.H4 = DATEVALUE[2] / 10; //时BCD高
    NOWREC.MEMBER.Mode  = NowMode;
    NOWREC.MEMBER.RPM   = DES_SPEED;
   
    NOWREC.MEMBER.Vg1   = VOLTAGEA1;
    NOWREC.MEMBER.Vg2   = VOLTAGEB1;
    NOWREC.MEMBER.Vg3   = VOLTAGEC1;
    NOWREC.MEMBER.Ig1   = CURRENTA;
    NOWREC.MEMBER.Ig2   = CURRENTB;
    NOWREC.MEMBER.Ig3   = CURRENTC;

    NOWREC.MEMBER.OUTPUTDATA.Byte=OUTPUTVALUE;
    NOWREC.MEMBER.UBat1  = PowerVoltage;
    NOWREC.MEMBER.UBat2  = PowerVoltage2;
    NOWREC.MEMBER.OilP  = OILPRESSURE;
    NOWREC.MEMBER.EngT  = WATERTEMP;
    NOWREC.MEMBER.FLvl  = FUEL;
    NOWREC.MEMBER.OilT  = OILTEMP;
    //NOWREC.MEMBER.IODATA.BYTES.BYTEH = INPUTVALUE;
    //NOWREC.MEMBER.IODATA.BYTES.BYTEL = OUTPUTVALUE;
    NOWREC.MEMBER.INPUTDATA.Byte=INPUTVALUE;
    if (RECBUFFPT < 10)
    {
        RECBUFFPT++;
    }

    for (i = 0; i < RECNUM; i++)
    {
        RECBUFF[ (RECBUFFPT-1) *RECNUM+i] = NOWREC.ARRAY[i];
    }

     REC_PT=0;


}


//*****************************************************************************
//函数名称：  RecProcess
//功能描述：  载入记录到内存
//输入参数：  无
//输出参数：  无
//*****************************************************************************

void RecProcess (void)
{
    uchar i;
    if (REC_ALANUM > 0)
    {

        for (i = 0; i < REC_ALANUM; i++)
        {
            SaveRecord (RECPOINT, * (REC_WINDOW - i) );
            NOBUZZER = 0;
            REC_POINTER=RECPOINT;
            REC_DATA1=RECPOINT;            
            RECPOINT++;
            
            if (RECPOINT > 59)
            {
                RECPOINT = 0;
            }

        }
        REC_ALANUM = 0;
        SaveParam (199,1); //保存指针
    }
    
    if (REC_AUTOSTART)
    {
            SaveRecord (RECPOINT, 64 );            
            RECPOINT++;
            if (RECPOINT > 59)
            {
                RECPOINT = 0;
            }       
       
            SaveParam (199,1); //保存指针
            REC_AUTOSTART=0;
    }
    
    
}
//*****************************************************************************
//函数名称：  EEPROM_PROCESS
//功能描述：  把数据写入EPPROM
//输入参数：  无
//输出参数：  无
//*****************************************************************************

void EEPROM_PROCESS (void)
{
    if (RECBUFFPT > 0)
    {
       // eee_access();
		    //EEE_Enable();
        
        if (REC_PT < 25)
        {

            WriteRecEEP (RECBUFF[ (RECBUFFPT-1) *25], RECBUFF[ (RECBUFFPT-1) *25+REC_PT], REC_PT);
            
            REC_PT++;
            if (REC_PT >= 25)
            {
                REC_PT = 0;
                RECBUFFPT--;                    
          //      while((ETAG > 0) || (FSTAT_MGBUSY == 1)); //we can wait for EEE to finish
		     //       EEE_Disable();	//the emulation is disabled. We can write into Buffer RAM but

            }                
        }
    }
}
