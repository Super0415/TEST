//#include "PublicShare.h"
#include "defs.h"
#pragma DATA_SEG DEFAULT
volatile uchar D423MODE;
volatile uchar D223MODE;

volatile uchar MANSTART_FLAG;

uchar SELF_TEST_BUZZER;
 uint CAN_PARAM_ADDRESS;
 int CAN_PARAM_NUM;
 uchar CAN_PARAM_SENDFLAG;

 uchar DI_NOSTOP;
 uchar DI[11];
 uchar DO[14];

 uchar REC_AUTOSTART=0;
 uchar DI_IDLE=0;
 
 uint FREQCOUNT = 0;
 uint FREQSET = 0;
 uchar FREQCOMP = 0;
 PID_PAR_STR PID_PARAM;
 
 uchar SPLASH_500ms;
 STRFLG16 EXTERNOUTPUT;
 STRFLG8 EXTERNINPUT;
 
 int SHORTVALUE;
 uchar SHORTFLAG;
 uint SHORTCNT;
 uint SHORTCNTMAX;
 uchar SpeedError=0;
 uchar SpeedError2=0;
 uchar SpeedHigh2=0;
 uchar OilPressureLow2=0;
 uchar WTHI2=0;
 uchar OTHI2=0;
 uchar PARAMSBUFF[100];
 int MODBUS_DATA[200];
 volatile int Params[250];
 uchar SendBuff[200];
 uchar CANWRITE=0;
 uchar EnWriteTime=0;
 
 volatile int AO1PERCENT=0;
 volatile int AO2PERCENT=0;
 volatile float AIFACT1;
 volatile float AIFACT2;
 volatile float AIFACT3;
 volatile float AIFACT4;
 volatile float AIFACT5;
 volatile float AIFACT6;
 volatile float AIFACT7;
 volatile float AIFACT8;
 volatile float AIFACT9;
 volatile float BATTFACT;
 volatile float CHARGEFACT;
 volatile float GENPT;
 volatile float MAINPT;
 volatile float GENVOLTFACT;
 int TMPDATA;
 volatile  int KWALL100;
 volatile long AI0;
 volatile long AI1;
 volatile long AI2;
 float ADJUST1=1.0;
 float ADJUST2=1.0;
 float ADJUST3=1.0;
 float ADJUST[AI_NUM];
 uchar ECUMODE;
 volatile uint FUELAVG;
 uchar INPUT_TEMP[50];
 uchar OUTPUT_TEMP[50];
 uchar NowMode;  
 STRFLG8 GENALA;
 STRFLG8 GENALA2;
 STRFLG8 BUSALA;
 STRFLG8 DESALA;
 STRFLG8 DESALA2;
 STRFLG8 DESALA3;
 STRFLG8 DESALA4;
 STRFLG8 DES_STATUS;
 STRFLG8 DES_STATUS2;
 STRFLG8 GEN_STATUS;
 STRFLG8 BUS_STATUS;
 STRFLG8 ECU_STATUS;
 STRFLG8 ECU_STATUS2;
 STRFLG8 HWALA;
 STRFLG8 HWALA2;
 STRFLG8 DESALAMASK;
 STRFLG8 DESALA2MASK;
 STRFLG8 DESALA3MASK;
 STRFLG8 GENALAMASK;
 STRFLG8 BUSALAMASK;
 STRFLG8 HWALAMASK;
 STRFLG8 PROTECT_FLAG;
 uchar NOBUZZER;
 uchar CHECKDELAY;
 float FreqArr[4];
 long AI_ADVALUE[AI_NUM];
 long AI_OHM[AI_NUM];                     
 
 long AI_R0 = 0;
 long AI_R1 = 0;
 long AI_R2 = 0;
 
 uchar ALARMSTOP=0;
 
 uchar FET_ENSTART=0;
 uchar TIMERSTART=0;
 uchar BATTSTART=0;


#pragma push
#pragma DATA_SEG __EPAGE_SEG EEE_PAGED_FE
uchar PARAMS_EEE[400];
#pragma pop

#pragma push
#pragma DATA_SEG __EPAGE_SEG EEE_PAGED_FC
uchar RECORD_P1_EEE;
#pragma pop

#pragma push
#pragma DATA_SEG __EPAGE_SEG EEE_PAGED_FD
uchar RECORD_P2_EEE;
#pragma pop

#pragma push
#pragma DATA_SEG __EPAGE_SEG EEE_PAGED_FF
uchar RECORD_P3_EEE;
#pragma pop


