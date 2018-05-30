#ifndef _DEFS_H
#define _DEFS_H

#define PCB_NORMAL 0
#define PCB_16YC 1

#define SHOWCOIL 0

/* Application/target specific configuration */

/* Custom integer types
 * uchar        8 bits unsigned
 * uint         16 bits unsigned
 * ulong        32 bits unsigned
 *
 * schar        8 bits signed
 * sint         16 bits signed
 * Slong        32 bits signed
 */
#undef NULL
#define NULL    (void *)0


#define VFDMODE 0   //0:VFD 
#define LCDMODE 1   //1:LCD

#define GECMODE16 1 //16模块 
#define GECMODE25 0 //25模块 



#define HW_MODE   0 //华为随载模式

#define WC_MODE   0 //潍柴模式

#define FEIERTE_MODE  0 //飞尔特充电机组

#define STANDARD_MODE 0  //标准模式

#define B_MODE        1//博杜安
#define GEC16P_MODE   0

//#define D423MODE 1
//#define D223MODE 0

#define RECNUM 25
#define REC_POINTER   220 
#define TESTPHASE     230

#if FEIERTE_MODE
#define PAGEALARM 14
#else
#define PAGEALARM 14
#endif

typedef unsigned char   uchar;
typedef unsigned int    uint;
typedef unsigned long   ulong;

typedef signed char     schar;
typedef signed int      sint;
typedef signed long     slong;

#define ALA_SPEED_LOW_PRE   FLG_ALA1.Bits.bit8 
#define ALA_SPEED_HIGH_PRE  FLG_ALA1.Bits.bit9 
#define ALA_SPEED_LOW_STOP  FLG_ALA1.Bits.bita 
#define ALA_SPEED_HIGH_STOP FLG_ALA1.Bits.bitb 
#define ALA_TEMP_HIGH_PRE   FLG_ALA1.Bits.bitc 
#define ALA_TEMP_HIGH_STOP  FLG_ALA1.Bits.bitd 
#define ALA_OP_LOW_PRE      FLG_ALA1.Bits.bite 
#define ALA_OP_LOW_STOP     FLG_ALA1.Bits.bitf 

#define ALA_BATT_LOW_ALA    FLG_ALA1.Bits.bit0 
#define ALA_BATT_HIGH_ALA   FLG_ALA1.Bits.bit1 
#define ALA_FUEL_LOW_PRE    FLG_ALA1.Bits.bit2 
#define ALA_FUEL_LOW_ALA    FLG_ALA1.Bits.bit3 
#define ALA_START_FAIL      FLG_ALA1.Bits.bit4 
#define ALA_STOP_FAIL       FLG_ALA1.Bits.bit5 
#define ALA_OILTEMP_STOP    FLG_ALA1.Bits.bit6 
#define ALA_LOSTOIL         FLG_ALA1.Bits.bit7 

#define ALA_OPERR           FLG_ALA2.Bits.bit8 
#define ALA_WTERR           FLG_ALA2.Bits.bit9
#define ALA_OTERR           FLG_ALA2.Bits.bita
#define ALA_COILTEMP        FLG_ALA2.Bits.bitb   //绕组温度过高
#define ALA_OILTEMP_PRE     FLG_ALA2.Bits.bitc
#define ALA_ESTOP           FLG_ALA2.Bits.bitd
#define ALA_POWERHIPRE      FLG_ALA2.Bits.bite
#define ALA_POWERHI         FLG_ALA2.Bits.bitf

//=
#define ALA_GEN_SHORT         FLG_ALA3.Bits.bit0  //发电机短路
#define ALA_GEN_CURRENT_NB    FLG_ALA3.Bits.bit1  //电流不平衡
#define ALA_GEN_VOLTAGE_NB    FLG_ALA3.Bits.bit2  //发电电压不平衡
#define ALA_COILTEMP2         FLG_ALA3.Bits.bit3  //绕组温度高
#define ALA_GENLEAK           FLG_ALA3.Bits.bit4  //发电机水泄漏
#define ALA_SPRINGINPUT       FLG_ALA3.Bits.bit5  //弹簧起动输入
#define ALA_COOLINGFAN        FLG_ALA3.Bits.bit6  //冷却风扇报警
#define ALA_WATERPLOW         FLG_ALA3.Bits.bit7  //冷却风扇报警




#define ALA_GEN_OVER_VOLTAGE  FLG_ALA3.Bits.bit8  //发电过压报警
#define ALA_GEN_LOW_VOLTAGE   FLG_ALA3.Bits.bit9  //发电欠压报警
#define ALA_GEN_OVER_FREQ     FLG_ALA3.Bits.bita  //发电过频报警
#define ALA_GEN_LOW_FREQ      FLG_ALA3.Bits.bitb  //发电欠频报警
#define ALA_GEN_HIGH_CURRENT  FLG_ALA3.Bits.bitc  //发电过流报警
#define ALA_GEN_ACBFAULT      FLG_ALA3.Bits.bitd  //ACB断路器故障
#define ALA_GEN_REVPOWER      FLG_ALA3.Bits.bite  //逆功
#define ALA_GEN_LOSTPHASE     FLG_ALA3.Bits.bitf  //缺相




#define ALA_BUS_OVER_VOLTAGE  FLG_ALA4.Bits.bit8  //市电过压报警
#define ALA_BUS_LOW_VOLTAGE   FLG_ALA4.Bits.bit9  //市电低压报警
#define ALA_BUS_OVER_FREQ     FLG_ALA4.Bits.bita  //市电过频报警
#define ALA_BUS_LOW_FREQ      FLG_ALA4.Bits.bitb  //市电欠频报警
#define STA_BUS_NORMAL        FLG_ALA4.Bits.bitc  //市电是否正常
#define ALA_BUS_VOLTAGE_NB    FLG_ALA4.Bits.bitd  //市电电压不平衡
#define ALA_DPLUSFAIL         FLG_ALA4.Bits.bite   //D+故障
#define ALA_M_POWER_HI        FLG_ALA4.Bits.bitf   //船用电压高

  
//#define STA_GEN_RUNNING     FLG_STAT.Bits.bit0  //发电机正常运行
//#define STA_GEN_ALARMS      FLG_STAT.Bits.bit1  //发电机报警
//#define STA_GEN_PREALARMS   FLG_STAT.Bits.bit2  //发电机预报警
//#define STA_GEN_STOP        FLG_STAT.Bits.bit3  //发电机停止供电

#define ECU_PUMPFAULT         FLG_ECUSTAT.Bits.bit0 //机油泵故障
#define ECU_OILCHOCK          FLG_ECUSTAT.Bits.bit1 //机滤堵塞
#define ECU_AIRCHOCK          FLG_ECUSTAT.Bits.bit2 //空滤堵塞
#define ECU_FUELCHOCK         FLG_ECUSTAT.Bits.bit3 //柴滤堵塞
#define ECU_DOORERR           FLG_ECUSTAT.Bits.bit4 //门禁
#define ECU_DESOIL_LEVEL      FLG_ECUSTAT.Bits.bit5 //机油箱油位低
#define ECU_FUELERR_UP        FLG_ECUSTAT.Bits.bit6 //燃油高异常
#define ECU_FUELERR_DOWN      FLG_ECUSTAT.Bits.bit7 //燃油低异常

#define ECU_PUMPFAULT2        FLG_ECUSTAT2.Bits.bit8 //溢油泵故障
#define ALA_POWERFAIL         FLG_ECUSTAT2.Bits.bit9 //电源故障
#define ALA_LOWLEVEL          FLG_ECUSTAT2.Bits.bita //液位低
#define ALA_PS_MAINTAIN       FLG_ECUSTAT2.Bits.bitb
#define ALA_PS_OIL_LOW_PRE    FLG_ECUSTAT2.Bits.bitc
#define ALA_PS_OIL_LOW_ALA    FLG_ECUSTAT2.Bits.bitd


typedef union 
{
  uint Byte; 
  struct 
  {
    uint bit0         :1;                                      
    uint bit1         :1;                                      
    uint bit2         :1;                                     
    uint bit3         :1;                                       
    uint bit4         :1;                                      
    uint bit5         :1;                                       
    uint bit6         :1;                                      
    uint bit7         :1; 
    uint bit8         :1;                                      
    uint bit9         :1;                                      
    uint bita         :1;                                     
    uint bitb         :1;                                       
    uint bitc         :1;                                      
    uint bitd         :1;                                       
    uint bite         :1;                                      
    uint bitf         :1;                                      
   } Bits;
    
   struct
   {
    uchar BYTEH:8;
    uchar BYTEL:8;
   }BYTES;
   
   
}FLAGSTR;

  typedef union
  { 
    unsigned int Byte;
    signed int Sbyte;    
    struct
    {
    uchar BIT0 :1;
    uchar BIT1 :1;
    uchar BIT2 :1;
    uchar BIT3 :1;
    uchar BIT4 :1;
    uchar BIT5 :1;
    uchar BIT6 :1;
    uchar BIT7 :1;
    uchar BIT8 :1;
    uchar BIT9 :1;
    uchar BITA :1;
    uchar BITB :1;
    uchar BITC :1;
    uchar BITD :1;
    uchar BITE :1;
    uchar BITF :1;
    }BITS;    
    
    struct
    {
    uchar BYTEH:8;
    uchar BYTEL:8;
    }BYTES;
    
  }STRFLG16;

  typedef union
  {
    uchar Byte;
    struct
    {
    uint bit0 :1;
    uint bit1 :1;
    uint bit2 :1;
    uint bit3 :1;
    uint bit4 :1;
    uint bit5 :1;
    uint bit6 :1;
    uint bit7 :1;
    }BITS;
  }FLAGSTR8;
  
     typedef union
  {
  uchar Byte;  
  struct
  {
   uchar L4 :4;
   uchar H4 :4;
  }BITS4;
  
    struct
    {
    uchar BIT0 :1;
    uchar BIT1 :1;
    uchar BIT2 :1;
    uchar BIT3 :1;
    uchar BIT4 :1;
    uchar BIT5 :1;
    uchar BIT6 :1;
    uchar BIT7 :1;
    }BITS;
  }BCDFLG;
 
  
     typedef union
  {
  uint ARRAY[RECNUM];
   struct 
  {
    uint RecNum;
    uint Reason;
    BCDFLG DateL;
    BCDFLG DateH;
    BCDFLG TimeL;
    BCDFLG TimeH;
    BCDFLG Time2;
    BCDFLG Time3; 
    uint Mode;
    uint RPM;
    uint POWER;
    uint PF;
    //uint LChr;
    uint Gfrq;
    uint Vg1;
    uint Vg2;
    uint Vg3;
    uint Ig1;
    uint Ig2;
    uint Ig3;
    uint Vm1;
    uint Vm2;
    uint Vm3;
    uint UBat;
    uint OilP;
    uint EngT;
    uint FLvl;
    uint OilT;
    STRFLG16 IODATA; 
    }MEMBER;      
  }RECORD;



#define FLAG_BTNSTART   BTNFLAG.BITS.bit0
#define FLAG_BTNSTOP    BTNFLAG.BITS.bit1
#define FLAG_BTNRESET   BTNFLAG.BITS.bit2
#define FLAG_BTNMUTE    BTNFLAG.BITS.bit3
#define FLAG_BTNGCB     BTNFLAG.BITS.bit4
#define FLAG_BTNMCB     BTNFLAG.BITS.bit5
#define F_BTN_SELFTEST_SDOUT  BTNFLAG.BITS.bit6
#define F_BTN_SELFTEST_SDNOUT BTNFLAG.BITS.bit7

#define PNUM_STATUS 200 
#define PNUM_MODESAVE 158
#define PNUM_AMF_ENABLE 90

#define nop()   _asm(nop)
#if PCB_NORMAL
//LED引脚定义
#define LED1							PTP_PTP0
#define LED2							PTP_PTP1
#define LED3							PTP_PTP2
#define LED4							PTP_PTP3
#define LED5							PTT_PTT4
#define LED6							PTP_PTP5
#define DDR_LED1					DDRP_DDRP0
#define DDR_LED2					DDRP_DDRP1
#define DDR_LED3					DDRP_DDRP2
#define DDR_LED4					DDRP_DDRP3
#define DDR_LED5					DDRT_DDRT4
#define DDR_LED6					DDRP_DDRP5


#define LCD_DATA_BIT0			PORTA_PA1
#define LCD_DATA_BIT1			PORTA_PA2
#define LCD_DATA_BIT2			PORTA_PA3
#define LCD_DATA_BIT3   	PTM_PTM0
#define LCD_DATA_BIT4   	PTT_PTT3
#define LCD_DATA_BIT5   	PTT_PTT2
#define LCD_DATA_BIT6   	PTT_PTT1
#define LCD_DATA_BIT7			PTT_PTT0

#define DDR_LCD_DATA_BIT0 DDRA_DDRA1
#define DDR_LCD_DATA_BIT1	DDRA_DDRA2
#define DDR_LCD_DATA_BIT2	DDRA_DDRA3
#define DDR_LCD_DATA_BIT3	DDRM_DDRM0
#define DDR_LCD_DATA_BIT4	DDRT_DDRT3
#define DDR_LCD_DATA_BIT5	DDRT_DDRT2
#define DDR_LCD_DATA_BIT6	DDRT_DDRT1
#define DDR_LCD_DATA_BIT7	DDRT_DDRT0


#if LCDMODE
//LCD引脚定义
//LCD控制口定义        
#define LCD_LED         	PTT_PTT6
#define LCD_CS1         	PORTB_PB7
#define LCD_RST         	PORTB_PB6
#define LCD_A0          	PORTB_PB5
#define LCD_WR          	PORTB_PB0
#define LCD_RD						PORTA_PA0

#define DDR_LCD_LED     	DDRT_DDRT6
#define DDR_LCD_CS1     	DDRB_DDRB7
#define DDR_LCD_RST     	DDRB_DDRB6
#define DDR_LCD_WR      	DDRB_DDRB0
#define DDR_LCD_A0      	DDRB_DDRB5
#define DDR_LCD_RD				DDRA_DDRA0

#endif
#endif

#if PCB_16YC
#define LED1							PTP_PTP0
#define LED2							PTP_PTP1
#define LED3							PTP_PTP2
#define LED4							PTP_PTP3
#define LED5							PTT_PTT4
#define LED6							PTP_PTP5
#define DDR_LED1					DDRP_DDRP0
#define DDR_LED2					DDRP_DDRP1
#define DDR_LED3					DDRP_DDRP2
#define DDR_LED4					DDRP_DDRP3
#define DDR_LED5					DDRT_DDRT4
#define DDR_LED6					DDRP_DDRP5


#define LCD_DATA_BIT0			PORTA_PA1
#define LCD_DATA_BIT1			PORTA_PA2
#define LCD_DATA_BIT2			PORTA_PA3
#define LCD_DATA_BIT3   	PTP_PTP7
#define LCD_DATA_BIT4   	PTT_PTT3
#define LCD_DATA_BIT5   	PTT_PTT2
#define LCD_DATA_BIT6   	PTT_PTT1
#define LCD_DATA_BIT7			PTT_PTT0

#define DDR_LCD_DATA_BIT0 DDRA_DDRA1
#define DDR_LCD_DATA_BIT1	DDRA_DDRA2
#define DDR_LCD_DATA_BIT2	DDRA_DDRA3
#define DDR_LCD_DATA_BIT3	DDRP_DDRP7
#define DDR_LCD_DATA_BIT4	DDRT_DDRT3
#define DDR_LCD_DATA_BIT5	DDRT_DDRT2
#define DDR_LCD_DATA_BIT6	DDRT_DDRT1
#define DDR_LCD_DATA_BIT7	DDRT_DDRT0


#if LCDMODE
//LCD引脚定义
//LCD控制口定义        
#define LCD_LED         	PTT_PTT6
#define LCD_CS1         	PORTB_PB7
#define LCD_RST         	PORTB_PB6
#define LCD_A0          	PORTB_PB5
#define LCD_WR          	PORTB_PB0
#define LCD_RD						PORTA_PA0

#define DDR_LCD_LED     	DDRT_DDRT6
#define DDR_LCD_CS1     	DDRB_DDRB7
#define DDR_LCD_RST     	DDRB_DDRB6
#define DDR_LCD_WR      	DDRB_DDRB0
#define DDR_LCD_A0      	DDRB_DDRB5
#define DDR_LCD_RD				DDRA_DDRA0


#endif
#endif

#if VFDMODE
//VFD引脚定义
//VFD控制口定义
#define VFD_POWER         PTT_PTT6
#define VFD_PBUSY         PORTB_PB6
#define VFD_RS            PORTB_PB5
#define VFD_RD            PORTB_PB0
#define VFD_WR            PORTA_PA0
/*
#define LCD_DATA_BIT0     PORTA_PA1
#define LCD_DATA_BIT1     PORTA_PA2
#define LCD_DATA_BIT2     PORTA_PA3
#define LCD_DATA_BIT3     PTM_PTM0
#define LCD_DATA_BIT4     PTT_PTT3
#define LCD_DATA_BIT5     PTT_PTT2
#define LCD_DATA_BIT6     PTT_PTT1
#define LCD_DATA_BIT7     PTT_PTT0
*/
#define DDR_VFD_POWER     DDRT_DDRT6
#define DDR_VFD_PBUSY     DDRB_DDRB6
#define DDR_VFD_RS        DDRB_DDRB5
#define DDR_VFD_RD        DDRB_DDRB0
#define DDR_VFD_WR        DDRA_DDRA0
#define DDR_VFD_DATA_BIT0 DDRA_DDRA1
#define DDR_VFD_DATA_BIT1 DDRA_DDRA2
#define DDR_VFD_DATA_BIT2 DDRA_DDRA3
#define DDR_VFD_DATA_BIT3 DDRM_DDRM0
#define DDR_VFD_DATA_BIT4 DDRT_DDRT3
#define DDR_VFD_DATA_BIT5 DDRT_DDRT2
#define DDR_VFD_DATA_BIT6 DDRT_DDRT1
#define DDR_VFD_DATA_BIT7 DDRT_DDRT0

#endif

#define DES_ALA_DATA1   StatusData[0]
#define DES_ALA_DATA2   StatusData[1]
#define GEN_ALA_DATA1   StatusData[2]
#define MAIN_ALA_DATA1  StatusData[3]
#define LEDBYTE         StatusData[4]
#define COMMON_STATUS   StatusData[5]
#define COMMON_STATUS2  StatusData[6]
#define INPUTVALUE      StatusData[7]
#define OUTPUTVALUE     StatusData[8]
#define ECUSTATUS       StatusData[9]
#define ECUSTATUS2      StatusData[10]
//时钟掩码
#define MASK_5MS          5
#define MASK_10MS         10
#define MASK_20MS         20
#define MASK_50MS         50
#define MASK_100MS        100
#define MASK_200MS        200
#define MASK_500MS        500
#define MASK_1000MS       1000
//按键端口定义                     

#define BTN_MODE_LEFT				PT1AD0_PT1AD00
#define BTN_HORN_RESET			PT1AD0_PT1AD01
#define BTN_FAULT_RESET    	PT1AD0_PT1AD02
#define BTN_MODE_RIGHT			PT1AD0_PT1AD03
#define BTN_STOP						PT1AD0_PT1AD04
#define BTN_START						PT1AD0_PT1AD05
#define BTN_ON_OFF_EN				PT1AD0_PT1AD06
#define BTN_ON_OFF_GE				PT1AD0_PT1AD07
#define BTN_PAGE_DOWN				PTM_PTM2
#define BTN_ENTER						PTM_PTM3
#define BTN_PAGE_UP					PTM_PTM4
#define	BTN_PAGE						PTM_PTM5
#define DDR_MODE_LEFT				DDR0AD0_DDR0AD00
#define DDR_HORN_RESET			DDR0AD0_DDR0AD01
#define DDR_BTN_FALT_RESET	DDR0AD0_DDR0AD02
#define DDR_MODE_RIGHT			DDR0AD0_DDR0AD03
#define DDR_BTN_STOP				DDR0AD0_DDR0AD04
#define	DDR_BTN_START				DDR0AD0_DDR0AD05
#define DDR_BTN_ON_OFF_EN 	DDR0AD0_DDR0AD06
#define DDR_BTN_ON_OFF_GE		DDR0AD0_DDR0AD07
#define DDR_BTN_PAGE_DOWN		DDRM_DDRM2
#define DDR_ENTER						DDRM_DDRM3
#define DDR_BTN_PAGE_UP			DDRM_DDRM4
#define DDR_BTN_PAGE				DDRM_DDRM5
//报警名称定义
#define ALASHOW_NONE            0
#define ALASHOW_LOWSPEEDPRE     1
#define ALASHOW_HIGHSPEEDPRE    2
#define ALASHOW_LOWSPEEDALA     3
#define ALASHOW_HIGHSPEEDALA    4
#define ALASHOW_HIGHWTTEMPPRE   5
#define ALASHOW_HIGHWTTEMPALA   6
#define ALASHOW_LOWOPPRE        7
#define ALASHOW_LOWOPALA        8

#define ALASHOW_BATTLOW         9
#define ALASHOW_BATTHIGH        10
#define ALASHOW_LOWFUELPRE      11
#define ALASHOW_LOWFUELALA      12
#define ALASHOW_STARTFAIL       13
#define ALASHOW_STOPFAIL        14
#define ALASHOW_HIGHOILTEMP     15
#define ALASHOW_LEAKFUEL        16 

#define ALASHOW_OPERR           17
#define ALASHOW_WTERR           18
#define ALASHOW_OTERR           19
#define ALASHOW_COILTEMP        20 
#define ALASHOW_OILTEMP_PRE     21

#define ALASHOW_GEN_HIVOLTAGE   22
#define ALASHOW_GEN_LOWVOLTAGE  23
#define ALASHOW_GEN_HIFREQ      24
#define ALASHOW_GEN_LOWFREQ     25 
#define ALASHOW_HICURRENT       26
#define ALASHOW_ACBFAULT        27
#define ALASHOW_REVPOWER        28
#define ALASHOW_LOSTPHASE       29

#define ALASHOW_BUS_HIVOLTAGE   30
#define ALASHOW_BUS_LOWVOLTAGE  31
#define ALASHOW_BUS_HIFREQ      32
#define ALASHOW_BUS_LOWFREQ     33 
#define ALASHOW_BUS_NORMAL      34

#define ALASHOW_ESTOP           35
#define ALASHOW_POWERHIPRE      36
#define ALASHOW_POWERHI         37
#define ALASHOW_DOORERR         38
#define ALASHOW_PUMPFAULT       39
#define ALASHOW_OILCHOCK        40
#define ALASHOW_AIRCHOCK        41
#define ALASHOW_FUELCHOCK       42
#define ALASHOW_DESOIL_LEVEL    43
#define ALASHOW_GEN_SHORT       44
#define ALASHOW_GEN_CURRENT_NB  45
#define ALASHOW_GEN_VOLTAGE_NB  46
#define ALASHOW_BUS_VOLTAGE_NB  47
#define ALASHOW_FUELERR_UP      48
#define ALASHOW_FUELERR_DOWN    49
#define ALASHOW_PUMPFAULT2      50
#define ALASHOW_COILTEMP2       51
#define ALASHOW_POWERFAIL       52
#define ALASHOW_LOWLEVEL        53
#define ALASHOW_EXHAUST_HI      54
#define ALASHOW_PS_MAINTAIN     55
#define ALASHOW_PS_OIL_LOW_PRE  56
#define ALASHOW_PS_OIL_LOW_ALA  57


#define ALASHOW_SAFE_OPLOW      60
#define ALASHOW_SAFE_WTHI       61
#define ALASHOW_SAFE_OTHI       62
#define ALASHOW_SAFE_SPDHI      63
#define ALASHOW_AUTOSTART       64
#define ALASHOW_GENLEAK         65
#define ALASHOW_SPRINGINPUT     66
#define ALASHOW_COOLINGFAN      67
#define ALASHOW_WATERPLOW       68
#define ALASHOW_DPLUSFAIL       69
#define ALASHOW_LOWOPALA_EM    70
#define ALASHOW_HIGHWTTEMPALA_EM   71

#define ALASHOW_HIGHOILTEMP_EM   72
#define ALASHOW_BATTLOW2        73
#define ALASHOW_BATTHIGH2       74



#define LNG            ParamValue[124]
#define TIMESET_SECOND ParamValue[204]                                 
#define TIMESET_MINUTE ParamValue[205]
#define TIMESET_HOUR   ParamValue[206]
   
#define TIMESET_DATE   ParamValue[207]                                                                                                     
#define TIMESET_MONTH  ParamValue[208]
#define TIMESET_YEAR   ParamValue[209]

#define Timer1Start    ParamValue[112]
#define Timer2Start    ParamValue[116]

#define TimeInhibitOn  ParamValue[118]
#define TimeInhibitOff ParamValue[119]


#define SAVEPASSWORD   ParamValue[1]

   
#define tmpminute TIMEDATA[0]
#define tmphour   TIMEDATA[1]
  
#define tmpdate   YEARDATA[0]
#define tmpmonth  YEARDATA[1]
#define tmpyear   YEARDATA[2]
  
  
#define RECDATA1  DataValue[60]
#define RECDATA2  DataValue[61]
#define RECDATA3  DataValue[62]
#define RECDATA4  DataValue[63]
#define RECDATA5  DataValue[64]  
#define RECDETAIL &DataValue[70]

  
/* 
#define ALASHOW_LOWWATER        26
#define ALASHOW_POWERFAIL       27  
*/



#define STA_DES_PREHEAT       FLG_STAT.Bits.bit0 //预热状态
#define STA_DES_START_IDLE    FLG_STAT.Bits.bit1 //起动怠速状态
#define STA_DES_STOP_IDLE     FLG_STAT.Bits.bit2 //停机怠速状态
#define STA_DES_ESTOP         FLG_STAT.Bits.bit3 //紧急停机状态
#define STA_DES_SELFTEST      FLG_STAT.Bits.bit4 //自检模式
#define STA_DES_LUB           FLG_STAT.Bits.bit5 //市电供电合闸
#define STA_DES_STOPING       FLG_STAT.Bits.bit6 //停机中
#define STA_DES_STARTINT      FLG_STAT.Bits.bit7 //起动间隔

#define STA_DES_CRANKING      FLG_STAT.Bits.bit8  //启动马达输出状态
#define STA_DES_RUNNING       FLG_STAT.Bits.bit9  //运行标志
#define STA_DES_ALARMS        FLG_STAT.Bits.bita  //柴油机报警
#define STA_DES_PREALARMS     FLG_STAT.Bits.bitb  //柴油机预警
#define STA_DES_STOP          FLG_STAT.Bits.bitc  //停机状态
#define STA_DES_ENSTART       FLG_STAT.Bits.bitd  //允许启动
#define STA_DES_START_SUCC    FLG_STAT.Bits.bite  //起动成功
#define STA_DES_ENSTOP        FLG_STAT.Bits.bitf  //启用停机

//按键掩码
#define MASK_BTN_ON_OFF_EN		0b1111111111111110
#define MASK_BTN_ON_OFF_GE  	0b1111111111111101
#define MASK_BTN_PAGE_UP			0b1111111111111011
#define MASK_BTN_PAGE					0b1111111111110111
#define MASK_BTN_PAGE_DOWN		0b1111111111101111
#define MASK_BTN_START				0b1111111111011111
#define MASK_BTN_FAULT_RESET 	0b1111111110111111
#define MASK_BTN_STOP					0b1111111101111111
#define MASK_BTN_ENTER				0b1111111011111111
#define MASK_BTN_HORN_RESET		0b1111110111111111
#define	MASK_BTN_MODE_LEFT		0b1111101111111111
#define MASK_BTN_MODE_RIGHT		0b1111011111111111
#define MASK_BTN_PAGE_ENTER   0b1111111011110111
#define MASK_BTN_LEFT_RIGHT   0b1111001111111111


#define BIT0    0X0001
#define BIT1    0X0002
#define BIT2    0X0004
#define BIT3    0X0008
#define BIT4    0X0010
#define BIT5    0X0020
#define BIT6    0X0040
#define BIT7    0X0080
#define BIT8    0X0100
#define BIT9    0X0200
#define BITA    0X0400
#define BITB    0X0800
#define BITC    0X1000
#define BITD    0X2000
#define BITE    0X4000
#define BITF    0X8000

typedef struct 
{
	uint Index;
	uint Msk;
}SENSORTYPE;
 typedef struct	/*12*16 汉字字模显示数据结构 */{
	unsigned char Index[2];
	char Msk[24];
}typFNT_GB16;

 typedef struct	/*6*16 汉字字模显示数据结构 */
{
	uchar Index;
	uchar Msk[12];
}typFNT_ASC16;





typedef void (*LCD_SCREEN)(void);

#endif
