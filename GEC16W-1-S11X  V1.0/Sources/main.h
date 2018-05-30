#ifndef _MAIN_H
#define _MAIN_H

PUBLIC volatile FLAGSTR  FLAG;
#define F_10MS          FLAG.Bits.bit0
#define F_20MS          FLAG.Bits.bit1
#define F_50MS          FLAG.Bits.bit2
#define F_100MS         FLAG.Bits.bit3
#define F_200MS         FLAG.Bits.bit4
#define F_5MS           FLAG.Bits.bit5
#define F_500MS         FLAG.Bits.bit6
#define F_CLR_LCD       FLAG.Bits.bit7

PUBLIC volatile unsigned char PAGE_DIS[15];

PUBLIC volatile unsigned int NowPage;
//PUBLIC volatile unsigned int Timeout;
PUBLIC uchar CONFIRM_DEL;
PUBLIC  uint  cnt_1000ms;

PUBLIC uchar BTNSTART_FLAG;

PUBLIC uchar TESTMODE;
PUBLIC uchar ConfirmMode;
PUBLIC volatile float PowerPercent;
PUBLIC volatile int ParamValue[250];
PUBLIC volatile int DataValue[150];
PUBLIC volatile uint ALAWINDOW[10];
PUBLIC volatile uint RECWINDOW[10];
PUBLIC volatile uint ALACONFIRM[10];
PUBLIC volatile uchar ALARMPAGE;
PUBLIC volatile char ALARMNUMS;
PUBLIC volatile uchar EnREC;
PUBLIC volatile unsigned int ReadStart;
PUBLIC volatile unsigned int ReadLength;
//PUBLIC volatile unsigned char ParamType[150];
//PUBLIC volatile unsigned int ParamLimitH[150];
//PUBLIC volatile unsigned int ParamLimitL[150];
PUBLIC volatile unsigned int LocalValue[50];
PUBLIC volatile unsigned int StatusData[11];
//PUBLIC uchar MainMenu.MENUNUM;
PUBLIC unsigned char SPLASH;
PUBLIC unsigned char EnChangeMode;
PUBLIC unsigned char ModeLock;
PUBLIC unsigned char NowMode;
PUBLIC unsigned char GetMode;
//PUBLIC unsigned char PageShow.PageNums;
PUBLIC uchar SelfTestMode;
PUBLIC uchar SplashIcon;
PUBLIC uint SelfTestTimer;
PUBLIC uchar RECREAD;
PUBLIC uchar REC_UPDATE;
PUBLIC uint NOWPHASE;
PUBLIC FLAGSTR FLG_ALA1;
PUBLIC FLAGSTR FLG_ALA2;
PUBLIC FLAGSTR FLG_ALA3;
PUBLIC FLAGSTR FLG_ALA4;
PUBLIC FLAGSTR FLG_STAT;
PUBLIC FLAGSTR FLG_ECUSTAT;
PUBLIC FLAGSTR FLG_ECUSTAT2;

PUBLIC FLAGSTR LASTFLAG1;
PUBLIC FLAGSTR LASTFLAG2;
PUBLIC FLAGSTR LASTFLAG3;
PUBLIC FLAGSTR LASTFLAG4;
PUBLIC FLAGSTR LASTFLAG5;
PUBLIC FLAGSTR LASTFLAG6;
PUBLIC FLAGSTR LASTFLAG7;

PUBLIC int TIMEDATA[2];
PUBLIC int YEARDATA[3];

PUBLIC int RECPT;
PUBLIC uchar INIT;                          

PUBLIC int PASSWORD;     //当前输入密码
PUBLIC uchar ENSETUP;    //允许设置

PUBLIC uint STANDBYTIME;

PUBLIC int LngCursor;
extern unsigned char  ParamType[];
extern  long  ParamLimitH[250];
extern  long  ParamLimitL[250];

//PUBLIC unsigned char FLAG_BTNSTART;
//PUBLIC unsigned char FLAG_BTNSTOP;
//PUBLIC unsigned char FLAG_BTNRESET;
//PUBLIC unsigned char FLAG_BTNMUTE;
//PUBLIC unsigned char FLAG_BTNGCB;
//PUBLIC unsigned char FLAG_BTNMCB;



PUBLIC FLAGSTR8 BTNFLAG;
PUBLIC uchar CHECKFLAG;
PUBLIC uchar RETURNFLAG;
volatile PUBLIC uchar SENDFLAG;
PUBLIC uchar initnum;
//PUBLIC 
#endif