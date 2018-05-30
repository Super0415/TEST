/******************************************************************************
* COMPANY       : FORTURST
* PROJECT       : GEC7000
*******************************************************************************
* NAME          : defs.h
* DESCRIPTION   : Software definitions (depend on target configuration)
* CVS           : $Id: defs.h,v 1.0 2011/01/30 13:52:10 fisher Exp $
*******************************************************************************
* HISTORY       :
*   
******************************************************************************/

#ifndef _DEFS_H
#define _DEFS_H

#define PCB16W   0
#define PCB16DW  1
#define BOUND4800 0
#define BOUND9600 1

#define ISOCOMM 0 


#define CHECKSPEEDERR 1
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


//#undef NULL
//#define NULL    (void *)0


#undef TRUE
#define TRUE 1
#undef FALSE
#define FALSE 0
typedef unsigned char   uchar;
typedef unsigned char   INT8U;
typedef unsigned int    INT16U;

typedef unsigned int    uint;
typedef unsigned long   INT32U;
typedef unsigned long   ulong;

typedef signed char     schar;
typedef signed int      sint;
typedef signed long     slong;

typedef unsigned char byte;

#define GECMODE16     1  //16模块 
#define GECMODE25     0  //25模块
#define WCZJ_MODE     0  //潍柴主机
#define FEIERTE_MODE  0  //飞尔特基站充电系统
#define PUMP_MODE     0  //水泵模式
//#define BAUDOUIN_MODE 1  //博杜安

#define STANDARD_MODE 0
#define HF_MODE 0 //杭发
#define HW_MODE 0 //华为随载
#define B_MODE  1 //博杜安模式
#define GEC16P_MODE 0

#define RECNUM 25


//#define SPEEDAD 409 

#if PCB16W==1
#define SPEEDAD 2048 //2.5v  pm7  ad15
#endif

#if PCB16DW==1
#define SPEEDAD 1300 
#endif

typedef struct
{   uint         usGain;      //增益
    uint         usStability; //稳定
    uint         usDerivative;//微分
    uint         usInputOld;  //微分保存旧值
    ulong         uiCtrlOld;   //积分保存旧值
    ulong         uiCtrlMin;   //输出最小值
    ulong         uiCtrlMax;   //输出最大值
}   PID_PAR_STR;


typedef union
{
    byte Byte;
    struct
    {
        byte L4 : 4;
        byte H4 : 4;
    } BITS4;

    struct
    {
        byte BIT0 : 1;
        byte BIT1 : 1;
        byte BIT2 : 1;
        byte BIT3 : 1;
        byte BIT4 : 1;
        byte BIT5 : 1;
        byte BIT6 : 1;
        byte BIT7 : 1;
    } BITS;
} BCDFLG;


typedef union
{
    byte Byte;
    struct
    {
        byte BIT0 : 1;
        byte BIT1 : 1;
        byte BIT2 : 1;
        byte BIT3 : 1;
        byte BIT4 : 1;
        byte BIT5 : 1;
        byte BIT6 : 1;
        byte BIT7 : 1;
    } BITS;

} STRFLG8;

typedef union
{
    unsigned int Byte;
    signed int Sbyte;
    struct
    {
        byte BIT0 : 1;
        byte BIT1 : 1;
        byte BIT2 : 1;
        byte BIT3 : 1;
        byte BIT4 : 1;
        byte BIT5 : 1;
        byte BIT6 : 1;
        byte BIT7 : 1;
        byte BIT8 : 1;
        byte BIT9 : 1;
        byte BITA : 1;
        byte BITB : 1;
        byte BITC : 1;
        byte BITD : 1;
        byte BITE : 1;
        byte BITF : 1;
    } BITS;

    struct
    {
        byte BYTEH: 8;
        byte BYTEL: 8;
        
    } BYTES;

} STRFLG16;

typedef union
{
    unsigned long UDWORD;
    long DWORD;
    
    struct
    {
        unsigned int WORDH: 16;
        unsigned int WORDL: 16;
    }WORDS;
     
    struct
    {
        byte BYTE4: 8;
        byte BYTE3: 8;
        byte BYTE2: 8;
        byte BYTE1: 8;        
    } BYTES; 
            
    struct
    {
        byte BIT0  : 1;
        byte BIT1  : 1;
        byte BIT2  : 1;
        byte BIT3  : 1;
        byte BIT4  : 1;
        byte BIT5  : 1;
        byte BIT6  : 1;
        byte BIT7  : 1;
        byte BIT8  : 1;
        byte BIT9  : 1;
        byte BIT10 : 1;
        byte BIT11 : 1;
        byte BIT12 : 1;
        byte BIT13 : 1;
        byte BIT14 : 1;
        byte BIT15 : 1;
        byte BIT16 : 1;
        byte BIT17 : 1;
        byte BIT18 : 1;
        byte BIT19 : 1;
        byte BIT20 : 1;
        byte BIT21 : 1;
        byte BIT22 : 1;
        byte BIT23 : 1;
        byte BIT24 : 1;
        byte BIT25 : 1;
        byte BIT26 : 1;
        byte BIT27 : 1;
        byte BIT28 : 1;
        byte BIT29 : 1;
        byte BIT30 : 1;
        byte BIT31 : 1;                
    } BITS;

} STRFLG32;





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
        STRFLG16 OUTPUTDATA;
        uint UBat1;
        uint UBat2;
        uint OilP;
        uint EngT;
        uint FLvl;
        uint OilT;
        STRFLG16 INPUTDATA;
        
    } MEMBER;

} RECORD;

#define READONLY_DATA_LEN 200
#define RW_DATA_LEN 250
#define nop()   _asm(nop)



#define ROUTE_INTERRUPT(vec_adr, cfdata)                \
  INT_CFADDR= (vec_adr) & 0xF0;                         \
  INT_CFDATA_ARR[((vec_adr) & 0x0F) >> 1]= (cfdata)

#define SOFTWARETRIGGER0_VEC  0x72 /* vector address= 2 * channel id */
#define SCI0_VEC (0x6B * 2)
#define SCI1_VEC (0x6A * 2)
#define SCI4_VEC (0X43 * 2)
#define PIT0_VEC (0X3D * 2)
#define PIT1_VEC (0x3C * 2)
#define PIT2_VEC (0x3B * 2)
#define IOC0_VEC (0X77 * 2)
#define IOC2_VEC (0X75 * 2)
#define IOC3_VEC (0X74 * 2)
#define OVF_VEC  (0X6F * 2)
#define ATD0_VEC (0X69 * 2)


#define MSB(w) (*(((uchar*)(&w)) + 0))
#define LSB(w) (*(((uchar*)(&w)) + 1))   

#define AI_LEN      (16 * 64)

#if B_MODE
#define AI_NUM 10
#endif

#if FEIERTE_MODE
#define AI_NUM 11
#endif

#if STANDARD_MODE||GEC16P_MODE
#define AI_NUM 11
#endif

#define interval_logic_process			50
#define calib_logic_mask(x)					((x)*1000/interval_logic_process)

#define interval_warn_process   			100
#define warn_real_value(x,y)				((x)*(y))
#define ai_calib_dly_cnt(x)  	  		((x)*1000/interval_warn_process)

#define MASK_SENSOR_OPEN						65535
#define GCBPULSEOFF TimerEnArr[TMR_GCB_PULSE_OFF]=1,DO_GCB_PULSEOFF=1



#define sftEVENT(event)                        (event == TRUE)
#define sftSET_EVENT(event)                (event = TRUE)
#define sftACK_EVENT(event)                (event = FALSE)
#define sftRESET_EVENT(event)            (event = FALSE)
#define sftCLR_BUF(event)						(event=0)
#define sftCOMPARE_EVENT(event1,event2)					(event1==event2)
#define sftEVALUATION_EVENT(event1,event2)			(event1=event2)

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

#define HWPROT_OT             HWPROTECT.BITS.BIT0 //华为油温自复位标志位
#define HWPROT_OV             HWPROTECT.BITS.BIT1 //华为高电压自复位标志位
#define HWPROT_LV             HWPROTECT.BITS.BIT2 //华为低电压自复位标志位
#define HWPROT_OC             HWPROTECT.BITS.BIT3 //华为过电流自复位标志位
#define HWPROT_ST             HWPROTECT.BITS.BIT4 //华为短路自复位标志位
#define HWPROT_GH             HWPROTECT.BITS.BIT5 //华为电机温度高自复位标志位


#define FET_PROT_OT           FETPROTECT.BITS.BIT0 //水温自复位
#define FET_PROT_OP           FETPROTECT.BITS.BIT1 //油压自复位
#define FET_PROT_LV           FETPROTECT.BITS.BIT2 //低电压自复位
#define FET_PROT_HV           FETPROTECT.BITS.BIT3 //高电压自复位
#define FET_PROT_OC           FETPROTECT.BITS.BIT4 //过电流自复位
#define FET_PROT_BT           FETPROTECT.BITS.BIT5 //电池温度自复位
#define FET_PROT_RT           FETPROTECT.BITS.BIT6 //整流器温度自复位
#define FET_PROT_OL           FETPROTECT.BITS.BIT7 //过载自复位

#define ALA_SPEED_LOW_PRE     DESALA.BITS.BIT0   //低速预报警位
#define ALA_SPEED_HIGH_PRE    DESALA.BITS.BIT1   //高速预报警位
#define ALA_SPEED_LOW_STOP    DESALA.BITS.BIT2   //低速报警停机位
#define ALA_SPEED_HIGH_STOP   DESALA.BITS.BIT3   //高速报警停机位
#define ALA_TEMP_HIGH_PRE     DESALA.BITS.BIT4   //温度高预报警位
#define ALA_TEMP_HIGH_STOP    DESALA.BITS.BIT5   //温度高报警停机位
#define ALA_OP_LOW_PRE        DESALA.BITS.BIT6   //低油压预报警位
#define ALA_OP_LOW_STOP       DESALA.BITS.BIT7   //低油压报警停机位

#define ALA_BATT_LOW_ALA      DESALA2.BITS.BIT0  //电池电压低报警位
#define ALA_BATT_HIGH_ALA     DESALA2.BITS.BIT1  //电池电压高报警位
#define ALA_FUEL_LOW_PRE      DESALA2.BITS.BIT2  //油位低预报警位
#define ALA_FUEL_LOW_ALA      DESALA2.BITS.BIT3  //油位低报警位
#define ALA_START_FAIL        DESALA2.BITS.BIT4  //起动失败
#define ALA_STOP_FAIL         DESALA2.BITS.BIT5  //停机失败
#define ALA_OILTEMP_STOP      DESALA2.BITS.BIT6  //高油温报警
#define ALA_LOSTOIL           DESALA2.BITS.BIT7  //燃油泄漏

#define ALA_OPERR             DESALA3.BITS.BIT0  //油压断线
#define ALA_WTERR             DESALA3.BITS.BIT1  //水温断线
#define ALA_OTERR             DESALA3.BITS.BIT2  //油温断线
#define ALA_SPEEDERR          DESALA3.BITS.BIT3  //转速断线
#define ALA_OILTEMP_PRE       DESALA3.BITS.BIT4  //高油温预报警
#define ALA_ESTOP             DESALA3.BITS.BIT5  //紧急停机
#define ALA_POWERHIPRE        DESALA3.BITS.BIT6  //过载报警
#define ALA_SPEEDERR2         DESALA3.BITS.BIT7  //转速传感器断线2 




#define ALA_SAFE_LOWOP        BUSALA.BITS.BIT0   //安全模块低油压报警
#define ALA_SAFE_HIWT         BUSALA.BITS.BIT1   //安全模块高水温报警
#define ALA_SAFE_HIOT         BUSALA.BITS.BIT2   //安全模块高油温报警
#define ALA_SAFE_HISPD        BUSALA.BITS.BIT3   //安全模块超速报警
#define ALA_CANFAIL           BUSALA.BITS.BIT5   //安全模块通讯故障
#define ALA_DPLUSFAIL         BUSALA.BITS.BIT6   //D+故障
#define ALA_M_POWERLOW        BUSALA.BITS.BIT4   //船供电源电压低
#define ALA_M_POWERHI         BUSALA.BITS.BIT7   //船供电源电压高



//#define STA_BUS_NORMAL        BUSALA.BITS.BIT4   //市电是否正常
//#define ALA_BUS_VOLTAGE_NB    BUSALA.BITS.BIT5   //市电电压不平衡


#define ALA_BUS_OVER_VOLTAGE  TMPDATA   //市电过压报警
#define ALA_BUS_LOW_VOLTAGE   TMPDATA   //市电低压报警
#define ALA_BUS_OVER_FREQ     TMPDATA   //市电过频报警
#define ALA_BUS_LOW_FREQ      TMPDATA   //市电欠频报警
#define STA_BUS_NORMAL        TMPDATA   //市电是否正常
#define ALA_BUS_VOLTAGE_NB    TMPDATA   //市电电压不平衡




#define ALA_EXCOILTEMP        GENALA.BITS.BIT0   //外部绕组温度高
#define ALA_EXBEARINGTEMP     GENALA.BITS.BIT1   //外部轴承温度高
#define ALA_GEN_OVER_FREQ     GENALA.BITS.BIT2   //发电过频报警
#define ALA_GEN_LOW_FREQ      GENALA.BITS.BIT3   //发电欠频报警
#define ALA_GEN_HIGH_CURRENT  GENALA.BITS.BIT4   //发电过流报警
#define ALA_GEN_ACBFAULT      GENALA.BITS.BIT5   //ACB断路器故障
#define ALA_GEN_REVPOWER      GENALA.BITS.BIT6   //逆功
#define ALA_GEN_LOSTPHASE     GENALA.BITS.BIT7   //缺相




#define ALA_DES_STARTLOW      GENALA2.BITS.BIT0  //起动压力低
#define ALA_DES_SWPLOW        GENALA2.BITS.BIT1  //海水压力低
#define ALA_DES_WPLOW         GENALA2.BITS.BIT2  //淡水压力低
#define ALA_COILTEMP          GENALA2.BITS.BIT3  //绕组温度高
#define ALA_GENLEAK           GENALA2.BITS.BIT4  //发电机水泄漏
#define ALA_SPRINGINPUT       GENALA2.BITS.BIT5  //弹簧起动输入
#define ALA_COOLINGFAN        GENALA2.BITS.BIT6  //冷却风扇故障
#define ALA_WATERPLOW         GENALA2.BITS.BIT7  //水压低


#define STA_DES_CRANKING      DES_STATUS.BITS.BIT0  //启动马达输出状态
#define STA_DES_RUNNING       DES_STATUS.BITS.BIT1  //运行标志
#define STA_DES_ALARMS        DES_STATUS.BITS.BIT2  //柴油机报警
#define STA_DES_PREALARMS     DES_STATUS.BITS.BIT3  //柴油机预警
#define STA_DES_STOP          DES_STATUS.BITS.BIT4  //停机状态
#define STA_DES_ENSTART       DES_STATUS.BITS.BIT5  //允许启动
#define STA_DES_START_SUCC    DES_STATUS.BITS.BIT6  //起动成功
#define STA_DES_ENSTOP        DES_STATUS.BITS.BIT7  //启用停机

#define STA_DES_PREHEAT       DES_STATUS2.BITS.BIT0 //预热状态
#define STA_DES_START_IDLE    DES_STATUS2.BITS.BIT1 //起动怠速状态
#define STA_DES_STOP_IDLE     DES_STATUS2.BITS.BIT2 //停机怠速状态
#define STA_DES_ESTOP         DES_STATUS2.BITS.BIT3 //紧急停机状态
#define STA_DES_SELFTEST      DES_STATUS2.BITS.BIT4 //自检模式
#define STA_DES_LUBFUNC       DES_STATUS2.BITS.BIT5 //预润滑功能
#define STA_DES_STOPING       DES_STATUS2.BITS.BIT6 //停机中
#define STA_DES_STARTINT      DES_STATUS2.BITS.BIT7 //起动间隔 



#define STA_GEN_RUNNING       GEN_STATUS.BITS.BIT0  //发电机正常运行
#define STA_GEN_ALARMS        GEN_STATUS.BITS.BIT1  //发电机报警
#define STA_GEN_PREALARMS     GEN_STATUS.BITS.BIT2  //发电机预报警
#define STA_GEN_STOP          GEN_STATUS.BITS.BIT3  //发电机停止供电

#define STA_AIR_CHOCK         ECU_STATUS.BITS.BIT7
#define STA_FUEL_CHOCK        ECU_STATUS.BITS.BIT6
#define STA_DESOIL_LEVEL      ECU_STATUS.BITS.BIT5
#define STA_MANUAL_PUMP       ECU_STATUS.BITS.BIT4
#define STA_AUTOSCALE         ECU_STATUS.BITS.BIT3
#define STA_ECULOCK           ECU_STATUS.BITS.BIT2
#define STA_ECU_PREHEAT       ECU_STATUS.BITS.BIT1
#define STA_FUELCHANGE        ECU_STATUS.BITS.BIT0

#define STA_PUMP_ERR          ECU_STATUS2.BITS.BIT7
#define STA_SPEED_SENSOR      ECU_STATUS2.BITS.BIT6
#define STA_LOW_OP            ECU_STATUS2.BITS.BIT5
#define STA_ECU_OVERHEAT      ECU_STATUS2.BITS.BIT4
#define STA_ECU_POWER         ECU_STATUS2.BITS.BIT3
#define STA_HIGH_SPEED        ECU_STATUS2.BITS.BIT2
#define STA_INTERNALERR       ECU_STATUS2.BITS.BIT1
#define STA_PUMP_ERR2         ECU_STATUS2.BITS.BIT0

#define ALA_HW_PUMP_ERR       HWALA.BITS.BIT0
#define ALA_HW_OILCHOCK       HWALA.BITS.BIT1
#define ALA_HW_AIRCHOCK       HWALA.BITS.BIT2
#define ALA_HW_FUELCHOCK      HWALA.BITS.BIT3
#define ALA_HW_DOORERR        HWALA.BITS.BIT4
#define ALA_HW_DESOIL_LEVEL   HWALA.BITS.BIT5
#define ALA_HW_FUELERR_UP     HWALA.BITS.BIT6
#define ALA_HW_FUELERR_DOWN   HWALA.BITS.BIT7

#define ALA_HW_PUMP_ERR2      HWALA2.BITS.BIT0
#define ALA_POWERFAIL         HWALA2.BITS.BIT1  //电源故障
#define ALA_LOWLEVEL          HWALA2.BITS.BIT2  //液位低
#define ALA_MAINTAIN_OVER     HWALA2.BITS.BIT3
#define ALA_OIL_LOW_PRE       HWALA2.BITS.BIT4
#define ALA_OIL_LOW_ALA       HWALA2.BITS.BIT5


#define EN_DES_PROTECT_OP     PROTECT_FLAG.BITS.BIT0
#define EN_DES_PROTECT_WT     PROTECT_FLAG.BITS.BIT1
#define EN_DES_PROTECT_SPEED  PROTECT_FLAG.BITS.BIT2
#define EN_DES_PROTECT        PROTECT_FLAG.BITS.BIT3
#define EN_GEN_PROTECT        PROTECT_FLAG.BITS.BIT4
#define EN_BUS_PROTECT        PROTECT_FLAG.BITS.BIT5


#define EO_OILP_LOW      EDO1
#define EO_OILT_HIGH     EDO2
#define EO_STARTSUCC     EDO3
#define EO_BATT_LOW      EDO4
#define EO_WATERT_HIGH   EDO5
#define EO_BUZZER        EDO6
#define EO_COMMALA       EDO7
#define EO_EMSTOP        EDO11
#define EO_STARTFAIL     EDO8



//自定义输入
#define DI_SWPLOW            INPUT_TEMP[0] //海水压力低
#define DI_SPLOW             INPUT_TEMP[1] //起动空气压力低
#define DI_ESTOP             INPUT_TEMP[2] //急停输入


#if B_MODE
#define DI_RMT_IDLE          INPUT_TEMP[3]//怠速开关输入
#endif

#define DI_MODELOCK          INPUT_TEMP[3] //模式锁
#define DI_EXTERN_NOSTOP     INPUT_TEMP[4] //禁止停机
#define DI_MODE_STOP         INPUT_TEMP[5] //关模式
#define DI_MODE_REMOTE       INPUT_TEMP[6] //测试模式
#define DI_MODE_LOCAL        INPUT_TEMP[7] //手动模式
#define DI_MODE_AUTO         INPUT_TEMP[8] //自动模式
#define DI_AUTOSTART_IN      INPUT_TEMP[9] //自起动
#define DI_WATERTEMP_H       INPUT_TEMP[10]//水温高
#define DI_OILP_L            INPUT_TEMP[11]//油压低
#define DI_LOWLEVEL          INPUT_TEMP[12]//淡水位低


#define DI_OILT_H            INPUT_TEMP[13]//油温高
#define DI_FUEL_LEAK         INPUT_TEMP[14]//燃油泄漏 

#define DI_WPLOW             INPUT_TEMP[15]//淡水压力低

#define DI_COILTEMPHIGH      INPUT_TEMP[16]//绕组高温

#define DI_DISABLE_AUTOSTART INPUT_TEMP[17]//禁止自启动
#define DI_BTN_START         INPUT_TEMP[18]//起动按键
#define DI_BTN_STOP          INPUT_TEMP[19]//停机按键
#define DI_BTN_FAULTRESET    INPUT_TEMP[20]//故障复位
#define DI_BTN_HORNRESET     INPUT_TEMP[21]//蜂鸣器复位 
//#define DI_BTN_RSTART        INPUT_TEMP[22]//远程启动
//#define DI_BTN_RSTOP         INPUT_TEMP[23]//远程停机
#define DI_FUELLOW           INPUT_TEMP[22]
#define DI_GENLEAK           INPUT_TEMP[23]

#define DI_ENABLE_AUTOSTART  INPUT_TEMP[24]//允许自启动
#define DI_SPRINGINPUT       INPUT_TEMP[25]//弹簧起动
#define DI_COOLFANSTOP       INPUT_TEMP[26]//冷却风扇报警输入
#define DI_DPLUSFAULT        INPUT_TEMP[27]//充电机故障输入



//自定义输出
#define DO_FUEL                      OUTPUT_TEMP[0] //供油
#define DO_START                     OUTPUT_TEMP[1] //起动
#define DO_IDLE                      OUTPUT_TEMP[2] //怠速 
#define DO_STOP                      OUTPUT_TEMP[3] //停机
#define DO_GCB                       OUTPUT_TEMP[4] //机组合闸
#define DO_MCB                       OUTPUT_TEMP[5] //市电合闸
#define DO_BUZZER                    OUTPUT_TEMP[6] //蜂鸣器
#define DO_START_SUCCESS             OUTPUT_TEMP[7] //起动成功
#define DO_ALARMS_PRE                OUTPUT_TEMP[8] //预报警
#define DO_ALARMS_STOP               OUTPUT_TEMP[9] //报警停机
#define DO_PRESTART                  OUTPUT_TEMP[10]//预启动输出
#define DO_GEN_RUNNING               OUTPUT_TEMP[11]//发电机正常运行
#define DO_MAIN_RUNNING              OUTPUT_TEMP[12]//市电正常运行
#define DO_READY                     OUTPUT_TEMP[13]//机组准备
#define DO_IDLE_REV                  OUTPUT_TEMP[14]//常闭怠速
#define DO_SPEED_UP                  OUTPUT_TEMP[15]//加速
#define DO_SPEED_DOWN                OUTPUT_TEMP[16]//减速
#define DO_MAIN_ALARM_VOLTAGE        OUTPUT_TEMP[17]//网电电压异常
#define DO_MAIN_ALARM_FREQ           OUTPUT_TEMP[18]//网电频率异常
#define DO_GEN_ALARM_OVERLOAD        OUTPUT_TEMP[19]//发电过载
#define DO_DES_ALARM_STOPFAULT       OUTPUT_TEMP[20]//停机失败
#define DO_DES_ALARM_OVERSPEED_PRE   OUTPUT_TEMP[21]//超速预警
#define DO_DES_ALARM_OVERSPEED_ALA   OUTPUT_TEMP[22]//超速报警停机
#define DO_OILTEMP_HIGH              OUTPUT_TEMP[23]//油温高报警
#define DO_DES_BATT                  OUTPUT_TEMP[24]//电池低报警
#define DO_DES_LOWOP_PRE             OUTPUT_TEMP[25]//低油压预警
#define DO_DES_LOWOP_ALA             OUTPUT_TEMP[26]//低油压报警
#define DO_DES_HIGHWT_PRE            OUTPUT_TEMP[27]//高水温预警
#define DO_DES_HIGHWT_ALA            OUTPUT_TEMP[28]//高水温报警
#define DO_DES_LOWOIL_PRE            OUTPUT_TEMP[29]//低油位预警
#define DO_DES_LOWOIL_ALA            OUTPUT_TEMP[30]//低油位报警
#define DO_COMMON_PRE                OUTPUT_TEMP[31]//公共预警
#define DO_COMMON_ALA                OUTPUT_TEMP[32]//公共报警
#define DO_START_FAIL                OUTPUT_TEMP[33]//启动失败
#define DO_CHARGE                    OUTPUT_TEMP[34]//充电开关 
#define DO_GCB_PULSEOFF              OUTPUT_TEMP[35]//机组分闸输出脉冲
#define DO_MCB_PULSEOFF              OUTPUT_TEMP[36]//市电分闸输出脉冲
#define DO_GCB_PULSEON               OUTPUT_TEMP[37]//机组合闸输出脉冲
#define DO_MCB_PULSEON               OUTPUT_TEMP[38]//市电合闸输出脉冲
#define DO_FUELPUMP                  OUTPUT_TEMP[39]//燃油泵开关
#define DO_TEMPONOFF                 OUTPUT_TEMP[40]//温度开关
#define DO_SPEEDCHECK                OUTPUT_TEMP[41]//停机开关           
#define DO_PREPARE_OK                OUTPUT_TEMP[42]//备车
#define DO_FET_BATTCAP_ON            OUTPUT_TEMP[43]//电池容量低开
#define DO_PRELUB                    OUTPUT_TEMP[44]//滑油预供输出
#define DO_LOCAL                     OUTPUT_TEMP[45]//本地输出
#define DO_AUTO                      OUTPUT_TEMP[46]//自动输出
#define DO_REMOTE                    OUTPUT_TEMP[47]//遥控输出
#define DO_ESTOP                     OUTPUT_TEMP[48]//急停延伸


   


#define VOLTAGEAB1       MODBUS_DATA[6]  //油机AB线电压
#define VOLTAGEBC1       MODBUS_DATA[7]  //油机BC线电压
#define VOLTAGECA1       MODBUS_DATA[8]  //油机CA线电压 
#define VOLTAGEA1        MODBUS_DATA[9]  //油机A相电压
#define VOLTAGEB1        MODBUS_DATA[10] //油机B相电压
#define VOLTAGEC1        MODBUS_DATA[11] //油机C相电压
#define CURRENTA         MODBUS_DATA[12] //油机A相电流
#define CURRENTB         MODBUS_DATA[13] //油机B相电流
#define CURRENTC         MODBUS_DATA[14] //油机C相电流

#if B_MODE
#define EXPLODE_PRESSURE  MODBUS_DATA[0] 
#define EXHAUST_TEMP      MODBUS_DATA[1]
#define NO_STOP           MODBUS_DATA[2] //主发/应急
#define START_STATE       MODBUS_DATA[3] //起动状态 0:起动输出 1:起动间隔
#define START_DEL_OUTPUT  MODBUS_DATA[4] //起动输出时间
#define START_DEL_INT     MODBUS_DATA[5] //起动间隔时间
#define START_NUMS        MODBUS_DATA[6] //当前起动次数
#define START_DEL_PRE     MODBUS_DATA[7] //预启动时间
#define GENVOLTAGE        MODBUS_DATA[8] //发电机电压

#undef VOLTAGEAB1
#undef VOLTAGEBC1
#undef VOLTAGECA1

#undef VOLTAGEA1
#undef VOLTAGEB1
#undef VOLTAGEC1

#undef CURRENTA
#undef CURRENTB
#undef CURRENTC

#define VOLTAGEAB1       TMPDATA  //油机AB线电压
#define VOLTAGEBC1       TMPDATA  //油机BC线电压
#define VOLTAGECA1       TMPDATA  //油机CA线电压 
#define VOLTAGEA1        TMPDATA  //油机A相电压
#define VOLTAGEB1        TMPDATA //油机B相电压
#define VOLTAGEC1        TMPDATA //油机C相电压
#define CURRENTA         TMPDATA //油机A相电流
#define CURRENTB         TMPDATA //油机B相电流
#define CURRENTC         TMPDATA //油机C相电流

#endif



#define WATERTEMP        MODBUS_DATA[16] //水温
#define CHASSISTEMP      MODBUS_DATA[16] //机腔温度
#define FUEL             MODBUS_DATA[17] //油位
#define LOLEVEL          MODBUS_DATA[17] //机油液位
#define OILPRESSURE      MODBUS_DATA[18] //油压 
#define OILTEMP          MODBUS_DATA[19] //油温       

#define PowerVoltage     MODBUS_DATA[20] //电池电压
#define ChargerVoltage   MODBUS_DATA[23]//TMPDATA//MODBUS_DATA[21] //充电机电压
#define PowerVoltage2    MODBUS_DATA[21]
#define DES_SPEED        MODBUS_DATA[22] //油机转速
#define FUELCAP          MODBUS_DATA[24] //燃油量：单位升

#define WTPRESSURE       MODBUS_DATA[25] //水压




#define COIL_U           MODBUS_DATA[26] //U相绕组温度
#define COIL_V           MODBUS_DATA[27] //V相绕组温度
#define COIL_W           MODBUS_DATA[28] //W相绕组温度
#define BEARING_TEMP     MODBUS_DATA[29] //轴承温度


#define KVAALL           MODBUS_DATA[29] //油机总视在功率
#define KVARALL          MODBUS_DATA[30]
#define KWA              MODBUS_DATA[31] //油机A相有功功率
#define KWB              MODBUS_DATA[32] //油机B相有功功率
#define KWC              MODBUS_DATA[33] //油机C相有功功率 
#define KVARA            MODBUS_DATA[34] //油机A相无功功率
#define KVARB            MODBUS_DATA[35] //油机B相无功功率
#define KVARC            MODBUS_DATA[36] //油机C相无功功率 
#define KVAA             MODBUS_DATA[37] //油机A相视在功率
#define KVAB             MODBUS_DATA[38] //油机B相视在功率
#define KVAC             MODBUS_DATA[39] //油机C相视在功率
#define PFA              MODBUS_DATA[40] //A相功率因数
#define PFB              MODBUS_DATA[41] //B相功率因数
#define PFC              MODBUS_DATA[42] //C相功率因数 
#define FUEL_COST        MODBUS_DATA[43] //当前燃油消耗量
#define FUEL_RATE        MODBUS_DATA[44] //当前燃油消耗率
#define FUEL_L           MODBUS_DATA[45] //初始油量 
#define KWHH             MODBUS_DATA[46] //千瓦时高位
#define KWHL             MODBUS_DATA[47] //千瓦时低位          
#define KVARHH           MODBUS_DATA[48] //千乏时高位
#define KVARHL           MODBUS_DATA[49] //千乏时低位 
//#define KVARH          MODBUS_DATA[50]
#define RUNNINGHOUR      MODBUS_DATA[50] //运行累时
#define RUNNINGMINUTE    MODBUS_DATA[51] //运行累分
#define RUNNINGTIME      MODBUS_DATA[52] //运行次数 
#define MAINTAIN         MODBUS_DATA[53]
#define ESTOPNUM         MODBUS_DATA[54]
#define STOPNUM          MODBUS_DATA[55]
#define GEN_PA           MODBUS_DATA[56] //电压A相角
#define GEN_PB           MODBUS_DATA[57] //电压B相角
#define GEN_PC           MODBUS_DATA[58] //电压C相角
#define REC_DATA1        MODBUS_DATA[60]
#define REC_DATA2        MODBUS_DATA[61]
#define REC_DATA3        MODBUS_DATA[62]
#define REC_DATA4        MODBUS_DATA[63]
#define REC_DATA5        MODBUS_DATA[64]
#define REC_DATA6        MODBUS_DATA[65]
#define REC_DATA7        MODBUS_DATA[66]
#define REC_DATA8        MODBUS_DATA[67]
#define REC_DATA9        MODBUS_DATA[68]
#define REC_DATA10       MODBUS_DATA[69]
#define REC_DETAIL       &MODBUS_DATA[70]

#define DES_ALA_DATA1    MODBUS_DATA[101]
#define DES_ALA_DATA2    MODBUS_DATA[102]
#define GEN_ALA_DATA1    MODBUS_DATA[103]
#define MAIN_ALA_DATA1   MODBUS_DATA[104]
#define LIGHTSTATUS      MODBUS_DATA[105]
#define COMMON_STATUS    MODBUS_DATA[106]
#define COMMON_STATUS2   MODBUS_DATA[107]
#define INPUTVALUE       MODBUS_DATA[108] //开关量输入
#define OUTPUTVALUE      MODBUS_DATA[109] //开关量输出
#define ECUSTATUS        MODBUS_DATA[110] //ECU状态 
#define ECUSTATUS2       MODBUS_DATA[111] //ECU状态2

#define ATMOP            MODBUS_DATA[112]
#define FUELOHM          MODBUS_DATA[113] //油位电阻值
#define FORCEINPUT       MODBUS_DATA[114] //强制输入
#define FORCEBTN         MODBUS_DATA[115] //模拟按钮
#define FORCEMODE        MODBUS_DATA[116] //强制模式

#define OILPRESSURE1     MODBUS_DATA[120] //@@@@@@@@@@@@@@@ZC燃油压力
#define VALUER1          MODBUS_DATA[121]
#define VALUER2          MODBUS_DATA[122]
#define OFFSETAOV        MODBUS_DATA[123]
#define OFFSETAOA        MODBUS_DATA[124]




//基本设定
#define SYS_PASSWORD                          Params[1]   //控制器参数设置密码
#define SYS_SET_DEFAULT_PARAM                 Params[2]   //恢复默认设置
#define GEN_RATING_POWER                      Params[3]   //额定功率 
#define DES_RATING_FUELCAP                    Params[4]   //额定油量
#define GEN_CURRENT_CT                        Params[5]   //电流互感器变比   
#define GEN_VOLTAGE_PT                        Params[6]   //电压互感器变比 
#define SYS_D4D2MODE                          Params[7]
#define GEN_RATING_VOLTAGE                    Params[8]   //额定电压 
#define GEN_RATING_VOLTAGELINE                Params[9]   //额定线电压
#define GEN_RATING_FREQ                       Params[10]  //额定频率       
#define DES_ROTATIONSCALE                     Params[11]  //飞轮齿数                         
#define DES_RATING_ROTATION                   Params[12]  //额定转速                      

//#define BATTCAP_FULL                          Params[13]
#define MANSTART_MODE                         Params[13]  //0程序起动 1手动起动
#define WP_SHOW                               Params[14]  //水压显示 
#define SYS_ADDR                              Params[15]  //控制器通讯地址
#define EMER_MODE                             Params[16]
#define COMMTYPE                              Params[18]  //通讯模式0-MODBUS 1-恩达
#define SAFESYSTEM_COMMALARM                  Params[17]
#define GENVOLT_SHOW                          Params[19]
#define CHARGE_SHOW                           Params[20]

//发动机参数
#define DES_START_SUCC_SPEED                  Params[21]  //起动脱开转速（%）    
#define DES_START_SUCC_OP                     Params[22]  //起动油压                       
#define DES_START_DELAY                       Params[23]  //预启动时间                        
#define DES_START_PULSE                       Params[24]  //启动电机最大时间                 
#define DES_START_INTEVAL                     Params[25]  //启动失败重试间隔               
#define DES_START_TIMES                       Params[26]  //最大启动次数                     
#define DES_START_IDLE_DELAY                  Params[27]  //启动怠速时间                
#define DES_MIN_STABLETIME                    Params[28]  //最短稳定时间                   
#define DES_MAX_STABLETIME                    Params[29]  //最长稳定时间                 
#define DES_COOL_SPEED                        Params[30]  //停机冷却速度选择 (额定/怠速)     
#define DES_STOP_IDLE_DELAY                   Params[31]  //停机怠速时间 
#define DES_STOP_OUTPUT_PULSE                 Params[32]  //停机输出脉冲时间          
#define DES_FUELTYPE                          Params[33]  //燃料阀
#define DES_D_SELECTION                       Params[34]  //D+选择 
#define DES_ECU_DES_D_SELECTION               Params[35]  //ECU频率选择
#define DES_ECU_SPEED_ADJUST                  Params[36]  //ECU速度调节
//#if FEIERTE_MODE
#define FET_LOWCAP_ON                         Params[37]  //电池容量低开
#define FET_HICAP_OFF                         Params[38]  //电池容量高关
#define DES_FUEL_ON                           Params[37]  //供油泵开
#define DES_FUEL_OFF                          Params[38]  //供油泵关
//#endif
#define DES_TEMP_ON                           Params[39]  //温度开
#define DES_TEMP_OFF                          Params[40]  //温度关
#define DES_DPLUS_SPEED                       Params[41]  //充发电机转速有效
#define DES_DPLUS_VOLT                        Params[42]  //充发电机故障电压

//发动机保护
#define DES_NOPROTECT_SEC                     Params[43]  //暂停保护
#define DES_BUZZ_TIME                         Params[44]  //蜂鸣时间                     
#define DES_OVERSPEED_ALA                     Params[45]  //超速报警停机                 
#define DES_AI1_PRE                           Params[46]  //AI1警告
#define DES_AI1_ALA                           Params[47]  //AI1报警
#define DES_AI1_DELAY                         Params[48]  //AI1延时
#define DES_AI2_PRE                           Params[49]  //AI2警告
#define DES_AI2_ALA                           Params[50]  //AI2报警
#define DES_AI2_DELAY                         Params[51]  //AI2延时
#define DES_AI3_PRE                           Params[52]  //AI3警告
#define DES_AI3_ALA                           Params[53]  //AI3报警
#define DES_AI3_DELAY                         Params[54]  //AI3延时
#define DES_BATT_HIGH_ALA                     Params[55]  //电池电压高报警               
#define DES_BATT_LOW_ALA                      Params[56]  //电池电压低报警                 
#define DES_BATT_DELAY                        Params[57]  //电池电压检测延时
#define DES_WATERP_LOW                        Params[58]  //



//自定义输入延时                                                           //极性0=常开 1=常闭
#define IO_INPUT_DEL1                         Params[60]//开关量输入1延时
#define IO_INPUT_POL1                         Params[61]//开关量输入1极性  
#define IO_INPUT_DEL2                         Params[62]//开关量输入1延时
#define IO_INPUT_POL2                         Params[63]//开关量输入1极性
#define IO_INPUT_DEL3                         Params[64]//开关量输入1延时
#define IO_INPUT_POL3                         Params[65]//开关量输入1极性
#define IO_INPUT_DEL4                         Params[66]//开关量输入1延时
#define IO_INPUT_POL4                         Params[67]//开关量输入1极性
#define IO_INPUT_DEL5                         Params[68]//开关量输入1延时
#define IO_INPUT_POL5                         Params[69]//开关量输入1极性
#define IO_INPUT_DEL6                         Params[70]//开关量输入1延时
#define IO_INPUT_POL6                         Params[71]//开关量输入1极性
#define IO_INPUT_DEL7                         Params[72]//开关量输入1延时
#define IO_INPUT_POL7                         Params[73]//开关量输入1极性
#define IO_INPUT_DEL8                         Params[74]//开关量输入1延时
#define IO_INPUT_POL8                         Params[75]//开关量输入1极性
#define IO_INPUT_DEL9                         Params[76]//开关量输入1延时
#define IO_INPUT_POL9                         Params[77]//开关量输入1极性
#define IO_INPUT_DEL10                        Params[78]//开关量输入1延时
#define IO_INPUT_POL10                        Params[79]//开关量输入1极性
#define IO_INPUT_DEL11                        Params[80]//开关量输入1延时
#define IO_INPUT_POL11                        Params[81]//开关量输入1极性


#define AI_OP_SELECT                          Params[82]//油压通道选择   0     +1
#define AI_WT_SELECT                          Params[83]//水温通道选择   6     +1
#define AI_OT_SELECT                          Params[84]//油温通道选择   5     +1
#define AI_BV1_SELECT                         Params[85]//电池组1通道选择 1    +1
#define AI_BV2_SELECT                         Params[86]//电池组2通道选择 2    +1
#define AI_LV_SELECT                          Params[87]//液位通道选择    5    +1
#define AI_GENVOLT_SELECT                     Params[88]//发电机通道选择  3    +1
#define AI_USEPOWERVOLT                       Params[89]//是否使用控制器电源电压 0:不使用 1：使用
#define AI_USEONECHANNEL                      Params[90]//是否使用单路电压 0：双路 1：单路
#define AI_WP_SELECT                          Params[91]//水压通道选择  7    +1

#define EXTERN_COILTEMP                       Params[92]//绕组温度高报警
#define EXTERN_BEARINGTEMP                    Params[93]//轴承温度高报警

#define AI_OP_SELECT1                         Params[94]//燃油压力通道选择   0     +1//@@@@@@@@@@@ZC
#define DES_SENSOR_OP1                        Params[95] //燃油压力传感器选择   //@@@@@@@ZC
#define OP_SHOW1                              Params[97] //燃油压力显示         //@@@@@@@ZC
//时间日期

#define HistoryTrig                           Params[106] //历史印记
#define WeekPeriod                            Params[107] //星期间隔
#define FET_MAINTAINPERIOD                    Params[107]

#define FET_MAINTAINTIME                      Params[110]
#define FET_MAINTAINFUNC                      Params[111]

#define Timer1Func                            Params[110] //计时器1功能
#define Timer1Repeat                          Params[111] //计时器1重复
#define Timer1Start                           Params[112] //计时器1开时间
#define Timer1Value                           Params[113] //计时器1期间
#define Timer2Func                            Params[114] //计时器2功能
#define Timer2Repeat                          Params[115] //计时器2重复
#define Timer2Start                           Params[116] //计时器2开时间
#define Timer2Value                           Params[117] //计时器2期间


#define FET_INHIBIT_TIME_ON                   Params[118] //禁止时间开
#define FET_INHIBIT_TIME_OFF                  Params[119] //禁止时间关
#define FET_INHIBIT_DAY                       Params[120] //禁止星期




//自定义输入输出
#define IO_INPUT_CONFIG1                      Params[125] //自定义输入1                                
#define IO_INPUT_CONFIG2                      Params[126] //自定义输入2                                
#define IO_INPUT_CONFIG3                      Params[127] //自定义输入3                                
#define IO_INPUT_CONFIG4                      Params[128] //自定义输入4                                
#define IO_INPUT_CONFIG5                      Params[129] //自定义输入5                                
#define IO_INPUT_CONFIG6                      Params[130] //自定义输入6                                
#define IO_INPUT_CONFIG7                      Params[131] //自定义输入7                                                                                                  
#define IO_OUTPUT_CONFIG1                     Params[132] //自定义输出1                               
#define IO_OUTPUT_CONFIG2                     Params[133] //自定义输出2                               
#define IO_OUTPUT_CONFIG3                     Params[134] //自定义输出3                               
#define IO_OUTPUT_CONFIG4                     Params[135] //自定义输出4                               
#define IO_OUTPUT_CONFIG5                     Params[136] //自定义输出5                               
#define IO_OUTPUT_CONFIG6                     Params[137] //自定义输出6                              
#define IO_OUTPUT_CONFIG7                     Params[138] //自定义输出7       


#if B_MODE
#define IO_INPUT_CONFIG8                      Params[160]
#define IO_INPUT_CONFIG9                      Params[161]
#define IO_INPUT_CONFIG10                     Params[162]
#define IO_INPUT_CONFIG11                     Params[163]

#define IO_OUTPUT_CONFIG8                     Params[164]
#define IO_OUTPUT_CONFIG9                     Params[165]
#define IO_OUTPUT_CONFIG10                    Params[166]
#define IO_OUTPUT_CONFIG11                    Params[167]
#define IO_OUTPUT_CONFIG12                    Params[168]
#define IO_OUTPUT_CONFIG13                    Params[169]
#define IO_OUTPUT_CONFIG14                    Params[170]

#define DES_SENSOR_EP                         Params[171]
#define DES_SENSOR_ET                         Params[172]


#endif

                        

//传感器选择
#define DES_SENSOR_OP                         Params[139] //油压传感器选择                   
#define DES_SENSOR_WT                         Params[140] //水温传感器选择                   
#define DES_SENSOR_FUEL                       Params[141] //液位传感器选择                   
#define DES_SENSOR_OT                         Params[142] //油温传感器选择 

//校准
#define ADJUSTR1                              Params[143] //电阻1校准
#define ADJUSTR2                              Params[144] //电阻2校准
#define ADJUSTR3                              Params[145] //电阻3校准  
#define ELECADJUST1                           Params[146] //发电电压A校准
#define ELECADJUST2                           Params[147] //发电电压B校准
#define ELECADJUST3                           Params[148] //发电电压C校准
#define ELECADJUST4                           Params[149] //网电电压A校准
#define ELECADJUST5                           Params[150] //网电电压B校准
#define ELECADJUST6                           Params[151] //网电电压C校准
#define ELECADJUST7                           Params[152] //电流A校准
#define ELECADJUST8                           Params[153] //电流B校准
#define ELECADJUST9                           Params[154] //电流C校准
#define BATTADJUST                            Params[155] //电池电压校准
#define CHARGEADJUST                          Params[156] //充电电压校准  
#define GENVOLTADJUST                         Params[157] //发电电压校准 
#define MODESAVE                              Params[158] //模式保存    




#define RUNHOUR                               Params[PN_RUNHOUR] //运行小时
#define RUNMINUTE                             Params[181] //运行分钟
#define RUNTIME                               Params[182] //起动次数
#define EPROM_KWHH                            Params[183] //千瓦时高位
#define EPROM_KWHL                            Params[184] //千瓦时低位
#define EPROM_KVARHH                          Params[185] //千乏时高位
#define EPROM_KVARHL                          Params[186] //千乏时低位
#define EPROM_KWS                             Params[187] //千瓦秒
#define EPROM_KVARS                           Params[188] //千乏秒
#define EP_KWH_STARTH                         Params[189] //初始电度高位
#define EP_KWH_STARTL                         Params[190] //初始电度低位
#define EP_KWS_START                          Params[191] //初始电度千瓦秒

#define MaintainDays                          Params[192] //维护天数    

//#define DEBUG_MODE                            Params[197] //RUNHOUR
#define EPROM_UNSUCSTARTS                     Params[198]
#define EPROM_ESTOP                           Params[198] //急停次数  
#define RECPOINT                              Params[199] //记录指针          
#define REC_ALANUM                            Params[210]
#define REC_WINDOW                            &Params[219]
#define REC_POINTER                           Params[220]



#define ECU_PCLASS      Params[201]
#define ECU_PNUM        Params[202]
#define ECU_NOWDATA     Params[203]

#define TIMESET_SECOND  Params[204]
#define TIMESET_MINUTE  Params[205]
#define TIMESET_HOUR    Params[206]

#define TIMESET_DATE    Params[207]
#define TIMESET_MONTH   Params[208]
#define TIMESET_YEAR    Params[209]



#define PNUM_STAT                 200
#define PNUM_CANPNUM              201
#define PNUM_CANPDATA             202

#if FEIERTE_MODE
#define DEBUG_MODE                0
#define PN_RUNHOUR                197
#define PN_RUNMINUTE              181
#else
#define DEBUG_MODE                0
#define PN_RUNHOUR                180
#define PN_RUNMINUTE              181
#endif

#define PN_MAINTAINDAY            192


#define NOREPEAT 0
#define MON      1
#define TUE      2
#define WEN      3
#define THU      4
#define FRI      5
#define SAT      6
#define SUN      7
#define MON_FRI  8
#define MON_SAT  9
#define MON_SUN  10
#define SAT_SUN  11

/*---------------*/

#define CHN_AI1           0
#define CHN_AI2           1
#define CHN_AI3           2

#define CHN_GENV          3
#define CHN_BATTSETV      4
#define CHN_GENCURRENT    5
#define CHN_BATTCURRENT   6
//#define CHN_GENC3         7
#define CHN_BATT          8
#define CHN_CHARGE        9

/*---------------*/




#define TMR_DES_SPEED_HI_PRE      0
#define TMR_DES_SPEED_HI_ALA      1
#define TMR_DES_SPEED_LO          2
#define TMR_DES_AI1_PRE           3
#define TMR_DES_AI1_ALA           4
#define TMR_DES_AI2_PRE           5
#define TMR_DES_AI2_ALA           6
#define TMR_DES_AI3_PRE           7
#define TMR_DES_AI3_ALA           8
#define TMR_BATT_HIGH             9
#define TMR_BATT_LOW              10
#define TMR_MAX_STABLETIME        11
#define TMR_MIN_STABLETIME        12
#define TMR_STOP_DETECT_DELAY     13
#define TMR_STOP_OUTPUT_PULSE     14
#define TMR_STOP_DELAY            15
#define TMR_STOP_IDLE_DELAY       16
#define TMR_START_DELAY           17
#define TMR_START_IDLE_DELAY      18
#define TMR_START_INTEVAL         19
#define TMR_START_PULSE           20
#define TMR_DISABLEPROT           21
#define TMR_GCB_PULSE_ON          22
#define TMR_GCB_PULSE_OFF         23
#define TMR_DISABLE_SPEEDADJUST   24
#define TMR_SECOND                25
#define TMR_MINUTERUN             26
#define TMR_BUZZER                27
#define TMR_FUELLOW_STOP          28
#define TMR_FUELCHECK             29
#define TMR_OVERLOADSTOP          30
#define TMR_OVERCURRENTRETRY      31
#define TMR_SHORTRETRY            32
#define TMR_OVERCURRENTRECHECK    33
#define TMR_SHORTRECHECK          34
#define TMR_COILTEMP              35
#define TMR_TIMER1                36
#define TMR_TIMER2                37
#define TMR_DI_AUTOSTARTON        38
#define TMR_DI_AUTOSTARTOFF       39
#define TMR_SPRINGINPUT           40
#define TMR_OPERR                 41
#define TMR_WTERR                 42
#define TMR_OTERR                 43
#define TMR_SPEEDADJUST_DUTY      44
#define TMR_SPEEDADJUST_FREQ      45
#define TMR_WPLOW                 46//淡水压力低
#define TMR_SWPLOW                47//海水压力低
#define TMR_FUELLOW               48//燃油位低
#define TMR_SPLOW                 49//起动压力低
#define TMR_SPEED_CHECK           50
#define TMR_RESET_DELAY           51
#define TMR_IDLE_RESET            52
#define TMR_SPEEDERR2             53
#define TMR_FUEL_LEAK             54
#define TMR_LOW_LEVEL             55//淡水低
#define TMR_GENLEAK               56//电机水泄漏
#define TMR_COOLFAN               57
#define TMR_GEN_GCB_DELAY         58

#define TMR_DI1_DEL               59
#define TMR_DI2_DEL               60
#define TMR_DI3_DEL               61
#define TMR_DI4_DEL               62
#define TMR_DI5_DEL               63
#define TMR_DI6_DEL               64
#define TMR_DI7_DEL               65
#define TMR_DI8_DEL               66
#define TMR_DI9_DEL               67
#define TMR_DI10_DEL              68
#define TMR_DI11_DEL              69

#define TMR_WP_DEL                70
#define TMR_DPLUSFAIL             71
#define TMR_BATT_LOW2             72
#define TMR_BATT_HIGH2            73
#define TMR_EXCOILTEMP            74
#define TMR_EXBEARINGTEMP         75


#endif /*_DEFS_H*/
