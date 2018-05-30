//define the variables between xgate and hc12x
#ifndef _SHARE_H
#define _SHARE_H
#pragma DATA_SEG SHARED_DATA /* allocate the following variables in the segment SHARED_DATA */
PUBLIC volatile int shared_counter; /* volatile because both cores are accessing it. */
typedef struct
{
	uint ua;
	uint ub;
	uint uc;
	uint uab;
	uint ubc;
	uint uca;
	uint phasea;
	uint phaseb;
	uint phasec;
	uint freq;
}typvoltage;
#define gen_ua					generator.ua
#define gen_ub					generator.ub
#define gen_uc					generator.uc
#define gen_uab					generator.uab
#define gen_ubc					generator.ubc
#define gen_uca					generator.uca
#define gen_phasea			generator.phasea
#define gen_phaseb			generator.phaseb
#define gen_phasec			generator.phasec
#define gen_freq				generator.freq
#define mains_ua				mains.ua
#define mains_ub				mains.ub
#define mains_uc				mains.uc
#define mains_uab				mains.uab
#define mains_ubc				mains.ubc
#define mains_uca				mains.uca
#define mains_phasea		mains.phasea
#define mains_phaseb		mains.phaseb
#define mains_phasec		mains.phasec
#define mains_freq			mains.freq
#define TMRNUM 110
PUBLIC volatile uint SPEEDADVALUE;
PUBLIC volatile uchar RXcomplete1;
PUBLIC volatile uchar RXcomplete2;
PUBLIC volatile uchar RXpt1;
PUBLIC volatile uchar RXpt2;
PUBLIC uchar CommTimeOut1;
PUBLIC uchar CommTimeOut2;
PUBLIC uchar ReceiveBuff1[100];
PUBLIC uchar ReceiveBuff2[200];
PUBLIC uchar MODBUS_CHECK1;
PUBLIC uchar MODBUS_CHECK2;
PUBLIC uchar RXendpt1;
PUBLIC uchar RXendpt2;
PUBLIC volatile uchar TimerEnArr[TMRNUM];
PUBLIC volatile ulong TimerSet[TMRNUM];
PUBLIC volatile ulong TimerValue[TMRNUM];
PUBLIC volatile uchar TimerMode[TMRNUM];
PUBLIC volatile uchar TimerTrig[TMRNUM];
PUBLIC volatile unsigned int DataArrGENA[32];
PUBLIC volatile unsigned int DataArrGENB[32];
PUBLIC volatile unsigned int DataArrGENC[32];
PUBLIC volatile unsigned int DataArrMAINA[32];
PUBLIC volatile unsigned int DataArrMAINB[32];
PUBLIC volatile unsigned int DataArrMAINC[32];
PUBLIC volatile int DataArrIA[32];
PUBLIC volatile int DataArrIB[32];
PUBLIC volatile int DataArrIC[32];
PUBLIC volatile ulong DataArrAI[AI_NUM];



PUBLIC volatile unsigned int DataArrBATT[10];
PUBLIC volatile unsigned int DataArrCHARGE[10];


PUBLIC typvoltage generator;
PUBLIC typvoltage	mains;
PUBLIC long FREQ_MP;
PUBLIC uint ai_cnt;
PUBLIC uint ai_result[AI_LEN]; 
PUBLIC volatile uchar ADSEQ;
PUBLIC volatile uchar FFTNUM;
PUBLIC volatile uchar FFTNUM2;


PUBLIC volatile uchar ovf_buf[3];
PUBLIC volatile uchar MPCHECKED;
PUBLIC uint  freq_pre_buf[3]; 
PUBLIC volatile uint temp_buf_mp;

PUBLIC volatile uint MPTEST;

typedef union 
{
  uchar Byte; 
  struct {
    uchar tim_5ms		       	:1;
    uchar tim_10ms         	:1;
    uchar tim_20ms         	:1;
    uchar tim_50ms         	:1;
    uchar tim_100ms        	:1;
    uchar tim_200ms        	:1;
		uchar tim_500ms					:1;
		uchar tim_1s						:1;
   } Bits; 
}typTIM_FLAG;
PUBLIC volatile typTIM_FLAG tim_flag;
#define schedule_5ms				tim_flag.Bits.tim_5ms
#define schedule_10ms				tim_flag.Bits.tim_10ms
#define schedule_20ms				tim_flag.Bits.tim_20ms
#define schedule_50ms				tim_flag.Bits.tim_50ms
#define schedule_100ms			tim_flag.Bits.tim_100ms
#define schedule_200ms			tim_flag.Bits.tim_200ms
#define schedule_500ms			tim_flag.Bits.tim_500ms
#define schedule_1s					tim_flag.Bits.tim_1s

#define F_ADC_DONE      FLAG.Bits.bit1
#define F_BUZ           FLAG.Bits.bit2
#define F_SET           FLAG.Bits.bit3
#endif
