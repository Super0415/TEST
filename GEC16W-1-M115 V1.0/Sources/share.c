#include "PublicShare.h"
//define the variables between xgate and hc12x
#pragma DATA_SEG SHARED_DATA /* allocate the following variables in the segment SHARED_DATA */
volatile int shared_counter; /* volatile because both cores are accessing it. */

 typvoltage generator;
 typvoltage	mains;
 long FREQ_MP;
 uint ai_cnt;
 uint ai_result[AI_LEN]; 
 volatile typTIM_FLAG tim_flag;

volatile uint MPTEST=0;
 volatile uint SPEEDADVALUE;
uchar volatile RXcomplete1=0;
uchar volatile RXcomplete2=0;
uchar volatile RXpt1=0;
uchar volatile RXpt2=0;
uchar MODBUS_CHECK1=0;
uchar MODBUS_CHECK2=0;
uchar RXendpt1=0;
uchar RXendpt2=0;
uchar CommTimeOut1=0;
uchar CommTimeOut2=0;
uchar ReceiveBuff1[100];
uchar ReceiveBuff2[200];
volatile uchar MPCHECKED=0;
volatile uint  freq_pre_buf[3] = 0;
volatile uchar ovf_buf[3];            //overflow buf 
volatile uint temp_buf_mp;

volatile uchar TimerEnArr[TMRNUM];
volatile ulong TimerSet[TMRNUM];
volatile ulong TimerValue[TMRNUM];
volatile uchar TimerMode[TMRNUM];
volatile uchar TimerTrig[TMRNUM];
 
volatile  uint DataArrGENA[32];
volatile  uint DataArrGENB[32];
volatile  uint DataArrGENC[32];
volatile  uint DataArrMAINA[32];
volatile  uint DataArrMAINB[32];
volatile  uint DataArrMAINC[32];
volatile  int DataArrIA[32];
volatile  int DataArrIB[32];
volatile  int DataArrIC[32];
volatile  ulong DataArrAI[AI_NUM];








volatile unsigned int DataArrBATT[10];
volatile unsigned int DataArrCHARGE[10];


volatile uchar FFTNUM = 0;
volatile uchar FFTNUM2 = 0;
volatile uchar ADSEQ;

