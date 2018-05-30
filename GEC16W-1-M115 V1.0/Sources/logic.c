#include "logic.h"
#include "MSCAN12.h"

ulong LOADBUFF=0;
uint LOADSEND;
int SPEEDSEND;
uchar PS_ENMAINTAIN=0;  //热机标志位

uchar PS_MAINTAINLOCK=0;//维护锁定不启动
uchar PSTEST=0;
uchar PS_MAINTAIN_MODE=0;//0代表不维护，1代表补机油，2代表换机油
ulong PS_MAINTAIN_ERR=0; //补油时间误差
ulong PS_MAINTAIN_OVER=0;


float cost_kwh = 0;
float bus_voltage_high;
float bus_voltage_low;
float bus_freq_high;
float bus_freq_low;
float gen_voltage_high;                         
float gen_voltage_low;
float gen_freq_high;
float gen_freq_low;
float gen_current_high;
float des_overspeed;
float des_overspeedpre;
float des_lowspeed;
float gen_power_high;
float gen_power_high_pre;
float hw_oilchock;
float hwoilplowpre;
float hwoilplowala;

 int TARGETSPEED=0;
int DEADOFFSET=0;

long BATTCAPVALUE;
int FET_CHARGE_CURRENTLIMIT;
int FET_CHARGE_VOLTAGELIMIT; 
int FET_CHARGE_F2B_CURRENT; 
int FET_CHARGE_B2F_CURRENT; 
int FET_CONSTANTSPEED;
int FET_SPEEDMODE_ERROR;
uint FET_SPEEDMODE_INTERVAL;

uchar STARTSUCCFLAG=0;
uchar lastmode;
uchar AMF_TRANS_LOCK=0;
uchar BattFail=0;
uchar STA_BUS = 0;
uchar STA_GEN = 0;
uchar STA_DES = 0;
uchar StartNum = 0;
STRFLG16 TMPFLG;
STRFLG8 FETPROTECT;
uchar AMFED = 0;
uchar DI_AUTOSTART=0;
uchar DI_AUTOSTART_LOCK=0;
uchar DISABLE_AUTOSTART=0;

uchar RunningErr = 0;
uchar ALARMPAGE[3];
uchar ALARMCONFIRM[3];
//uchar DI_BTN_FAULTRESET_MASK;
STRFLG8 BTNVALUE;

uchar ResetFlag=0;
/*
#define BTN_START        BTNVALUE.BITS.BIT0
#define BTN_STOP         BTNVALUE.BITS.BIT1
#define BTN_FAULT_RESET  BTNVALUE.BITS.BIT2
#define BTN_HORN_RESET   BTNVALUE.BITS.BIT3
#define BTN_GCB_SWITCH   BTNVALUE.BITS.BIT4
#define BTN_MCB_SWITCH   BTNVALUE.BITS.BIT5
 */
void TRANSMIT_CAN_DATA_PARAM(void)
{                                
   int MODBUSDATA[4];
   
   if(CAN_PARAM_SENDFLAG)
   {
    
   if(CAN_PARAM_ADDRESS<200)
   {
      MODBUSDATA[0]=CAN_PARAM_ADDRESS;
      MODBUSDATA[1]=MODBUS_DATA[CAN_PARAM_ADDRESS];
      CAN_PARAM_ADDRESS++;
      MODBUSDATA[2]=MODBUS_DATA[CAN_PARAM_ADDRESS];
      CAN_PARAM_ADDRESS++;
      MODBUSDATA[3]=MODBUS_DATA[CAN_PARAM_ADDRESS];
      CAN_PARAM_ADDRESS++;
      CAN_PARAM_NUM=CAN_PARAM_NUM-3;
     CANSND1DFRM (0x00000032UL, (uchar *)&MODBUSDATA[0], 8, 1); 
     if(CAN_PARAM_NUM<=0)
     {
       CAN_PARAM_SENDFLAG=0;
     }
   }
   
   if(CAN_PARAM_ADDRESS>=200)
   {
      MODBUSDATA[0]=CAN_PARAM_ADDRESS-200;
      MODBUSDATA[1]=Params[CAN_PARAM_ADDRESS-200];
      CAN_PARAM_ADDRESS++;
      MODBUSDATA[2]=Params[CAN_PARAM_ADDRESS-200];
      CAN_PARAM_ADDRESS++;
      MODBUSDATA[3]=Params[CAN_PARAM_ADDRESS-200];
      CAN_PARAM_ADDRESS++;
      CAN_PARAM_NUM=CAN_PARAM_NUM-3;
     CANSND1DFRM (0x00000031UL, (uchar *)&MODBUSDATA[0], 8, 1); 
     if(CAN_PARAM_NUM<=0)
     {
       CAN_PARAM_SENDFLAG=0;
     }
   }
   }
   
}
void TRANSMIT_CAN_DATA(void)
{
    static uchar ID=1;
    uint SENDBUFF[4];
    switch(ID)
    {
      case 1:
      SENDBUFF[0]=GENVOLTAGE;
      SENDBUFF[1]=WTPRESSURE;
      SENDBUFF[2]=NO_STOP;
      SENDBUFF[3]=START_STATE;
      break;
      case 2:
      SENDBUFF[0]=START_DEL_OUTPUT;
      SENDBUFF[1]=START_DEL_INT;
      SENDBUFF[2]=START_NUMS;
      SENDBUFF[3]=START_DEL_PRE;
      break;  
      case 3:
      SENDBUFF[0]=WATERTEMP;
      SENDBUFF[1]=FUEL;
      SENDBUFF[2]=OILPRESSURE;
      SENDBUFF[3]=OILTEMP;
      break;           
      case 4:
      SENDBUFF[0]=PowerVoltage;
      SENDBUFF[1]=PowerVoltage2;
      SENDBUFF[2]=ChargerVoltage;
      SENDBUFF[3]=DES_SPEED;
      break;       
      case 5:
      SENDBUFF[0]=RUNNINGHOUR;
      SENDBUFF[1]=RUNNINGTIME;
      SENDBUFF[2]=ESTOPNUM;
      SENDBUFF[3]=INPUTVALUE;
      break;       
      case 6:
      SENDBUFF[0]=OUTPUTVALUE;
      SENDBUFF[1]=RUNNINGTIME;
      SENDBUFF[2]=COMMON_STATUS;
      SENDBUFF[3]=COMMON_STATUS2;
      break; 
      case 7:
      SENDBUFF[0]=DES_ALA_DATA1;
      SENDBUFF[1]=DES_ALA_DATA2;
      SENDBUFF[2]=LIGHTSTATUS;
      SENDBUFF[3]=GEN_ALA_DATA1;
      break;     
      case 8:
      SENDBUFF[0]=HWALA.Byte;
      SENDBUFF[1]=HWALA2.Byte;
      SENDBUFF[2]=NowMode;      
      SENDBUFF[3]=MAIN_ALA_DATA1;      
      break; 
                        
    }
    
    CANSND1DFRM (0x00000000UL+ID, (uchar *)&SENDBUFF[0], 8, 1);        
    ID++;    
    if(ID>8)
    {
        ID=1;
    }

}

void ADJUST_SPEED(void)
{
    if(NowMode!=2)
    {
        DO_SPEED_UP=0;
        DO_SPEED_DOWN=0;
        return;
    }
    
    TimerEnArr[TMR_SPEEDADJUST_FREQ]=1;
    //DEADOFFSET=DES_RATING_ROTATION/30;
    DEADOFFSET=10;
    if(STA_DES_START_SUCC==0 || DO_STOP)
    {
        DO_SPEED_UP=0;
        DO_SPEED_DOWN=0;
        return;    
    }
    
    
    if(DO_IDLE==1)
    {
        TARGETSPEED=DES_RATING_ROTATION+5;
    }
    else
    {
        TARGETSPEED=(DES_RATING_ROTATION+5)/2;
    }
       
    
    if(TimerTrig[TMR_SPEEDADJUST_FREQ]) //加减速判断开始
    {
        TimerTrig[TMR_SPEEDADJUST_FREQ]=0;
        TimerEnArr[TMR_SPEEDADJUST_DUTY]=0;       
        TimerTrig[TMR_SPEEDADJUST_DUTY]=0;
        
        if(TARGETSPEED-DEADOFFSET-DES_SPEED>0)
        {
            TimerSet[TMR_SPEEDADJUST_DUTY]=(TARGETSPEED-DEADOFFSET-DES_SPEED)/2;
        }
        else if(DES_SPEED-DEADOFFSET-TARGETSPEED>0)
        {
            TimerSet[TMR_SPEEDADJUST_DUTY]=(DES_SPEED-DEADOFFSET-TARGETSPEED)/2;
        }
        
        if(DES_SPEED<TARGETSPEED-DEADOFFSET) //转速低于目标转速-死区
        {
            if(DO_IDLE || DI_AUTOSTART)
            {              
                DO_SPEED_UP=1;                   //加速
                TimerEnArr[TMR_SPEEDADJUST_DUTY]=1;
            }
            if(DI_AUTOSTART==0)
            {
                DO_SPEED_UP=0;
                TimerEnArr[TMR_SPEEDADJUST_DUTY]=0;
            }
        }
        
        if(DES_SPEED>TARGETSPEED+DEADOFFSET) //转速高于目标转速+死区
        {
            
            DO_SPEED_DOWN=1;                 //减速
            TimerEnArr[TMR_SPEEDADJUST_DUTY]=1;
        }
    
    }
    
    
    if(TimerTrig[TMR_SPEEDADJUST_DUTY])
    {
        TimerTrig[TMR_SPEEDADJUST_DUTY]=0;
        DO_SPEED_UP=0;
        DO_SPEED_DOWN=0;        
    }
    
  
}
//*****************************************************************************
//函数名称：  EXTEND_SEND
//功能描述：  对扩展模块进行DO输出
//输入参数：  无
//输出参数：  无
//*****************************************************************************
void EXTEND_SEND (void)
{  
    STRFLG16 TMP;
    if(NOBUZZER)
    {
        ResetFlag|=2;
    }
    TMP.Byte=DES_RATING_ROTATION;
    CANSEND[0] = EXTERNOUTPUT.BYTES.BYTEH;
    CANSEND[1] = EXTERNOUTPUT.BYTES.BYTEL;
    CANSEND[2] = TMP.BYTES.BYTEH;
    CANSEND[3] = TMP.BYTES.BYTEL;
    CANSEND[4] = DI_NOSTOP; 
    CANSEND[5] = (uchar)DES_OVERSPEED_ALA; 
    CANSEND[6] = (uchar)DES_ROTATIONSCALE; 
    CANSEND[7] = ResetFlag;
    CANSND1DFRM (0x00000001, &CANSEND[0], 8, 0);
    ResetFlag=0;
    //CANSND1DFRM (0x00000003, &CANSEND[0], 4, 1);                      
}
//*****************************************************************************
//函数名称：  MCB_GCB_LOGIC
//功能描述：  市电发电合闸分闸逻辑
//输入参数：  无
//输出参数：  无
//*****************************************************************************
void MCB_GCB_LOGIC (void)
{
    static lastgcb;
    static lastmcb;



   
    //机组合闸分闸脉冲
    
    #if B_MODE
    if(NowMode==2)
    {
      
        if(DES_SPEED>DES_RATING_ROTATION-10 && DO_IDLE && TimerTrig[TMR_MAX_STABLETIME])
        {
            DO_GCB=1;
        }
        if(STA_DES_ENSTOP==1 && DO_IDLE==0)
        {
            DO_GCB=0;
        }
    
    }
    else
    {
        DO_GCB=0;         
    }
    #endif

    if (DO_GCB == 1)
    {
        TimerEnArr[TMR_GCB_PULSE_ON] = 1, DO_GCB_PULSEON = 1;
    }

    if (TimerTrig[TMR_GCB_PULSE_ON] == 1)
    {
        DO_GCB_PULSEON = 0;
    }
    
    if (DO_GCB == 0)
    {
        TimerValue[TMR_GCB_PULSE_ON] = 0;
        TimerEnArr[TMR_GCB_PULSE_ON] = 0;
        TimerTrig[TMR_GCB_PULSE_ON] = 0;
        DO_GCB_PULSEON = 0;
    }

   #if HF_MODE
    if (DI_GCB && STA_DES_ENSTOP)
    {
        GCBPULSEOFF;
    }
   #endif

    if(lastgcb==1&&DO_GCB==0) GCBPULSEOFF;
    //if(DI_GCB&&DO_GCB==0&&STA_DES_RUNNING)DO_GCB=1;

    //if(DI_GCB&&TimerEnArr[TMR_GEN_GCB_DELAY]==0&&STA_DES_RUNNING&&TimerEnArr[TMR_GCB_PULSE_OFF]==0)TimerEnArr[TMR_GEN_GCB_DELAY]=1;

    //if(TimerEnArr[TMR_GEN_GCB_DELAY]==0)TimerEnArr[TMR_GCB_PULSE_OFF]=1,DO_GCB_PULSEOFF=1;

    if (TimerTrig[TMR_GCB_PULSE_OFF] == 1)
    {
        DO_GCB_PULSEOFF = 0;
        TimerValue[TMR_GCB_PULSE_OFF] = 0;
        TimerEnArr[TMR_GCB_PULSE_OFF] = 0;
        TimerTrig[TMR_GCB_PULSE_OFF] = 0;
    }




    //if(DO_GCB==1||DI_GCB)
    //{
    //TimerValue[TMR_GCB_PULSE_OFF]=0;
    //TimerEnArr[TMR_GCB_PULSE_OFF]=0;
    //TimerTrig[TMR_GCB_PULSE_OFF]=0;
    //}

    //市电合闸分闸脉冲
    
    #if GECMODE25
    if (DO_MCB == 1)
    {
        TimerEnArr[TMR_MCB_PULSE_ON] = 1, DO_MCB_PULSEON = 1;
    }

    if (TimerTrig[TMR_MCB_PULSE_ON] == 1)
    {
        DO_MCB_PULSEON = 0;
    }
    if (DO_MCB == 0)
    {
        TimerValue[TMR_MCB_PULSE_ON] = 0;
        TimerEnArr[TMR_MCB_PULSE_ON] = 0;
        TimerTrig[TMR_MCB_PULSE_ON] = 0;
    }

    if (DO_MCB == 0)
    {
        TimerEnArr[TMR_MCB_PULSE_OFF] = 1, DO_MCB_PULSEOFF = 1;
    }

    if (TimerTrig[TMR_MCB_PULSE_OFF] == 1)
    {
        DO_MCB_PULSEOFF = 0;
    }
    if (DO_MCB == 1)
    {
        TimerValue[TMR_MCB_PULSE_OFF] = 0;
        TimerEnArr[TMR_MCB_PULSE_OFF] = 0;
        TimerTrig[TMR_MCB_PULSE_OFF] = 0;
    }
    #endif
    
    
   /*
    if (DO_MCB == 1 || DI_MCB == 1)
    {
        TimerValue[TMR_GEN_GCB_DELAY] = 0;
    }
    
    if (DO_GCB == 1 || DI_GCB == 1)
    {
        TimerValue[TMR_BUS_MCB_DELAY] = 0;
    }
*/
    lastgcb = DO_GCB;
    lastmcb = DO_MCB;

}


//*****************************************************************************
//函数名称：  ECU6800_SENDLOAD
//功能描述：  对ECU6800发送功率数据
//输入参数：  NOWLOAD，单位 1KW=100
//输出参数：  无
//*****************************************************************************
#if FEIERTE_MODE
void ECU6800_SENDLOAD (unsigned int NOWLOAD)
{
    static uchar i;
    uint SENDVALUE;
    
    FET_SPEEDMODE_INTERVAL++;

    if(i<50)
    {
        i++;  
        LOADBUFF+=NOWLOAD;        
    }
    else
    {
        i=0;        
        LOADSEND=LOADBUFF/50;
        LOADBUFF=0;
    }
    
    if ( (DO_FUEL || STA_DES_PREHEAT) && NOWLOAD < 10)
    {
        LOADSEND = 8;
    }

                                                
    if (DO_FUEL == 1 && ((DO_GCB == 1||TimerEnArr[TMR_GEN_GCB_DELAY]==1) && TimerTrig[TMR_DISABLE_SPEEDADJUST] == 0) && STA_DES_ENSTOP == 0)
    {
        LOADSEND = SPEEDADJUST_PRELOAD * GEN_RATING_POWER;
    }

    if (KWALL100 > LOADSEND)
    {
        TimerTrig[TMR_DISABLE_SPEEDADJUST] = 1;
    }

    if (TimerEnArr[TMR_STOP_IDLE_DELAY] == 1)
    {
        LOADSEND = 10;
    }

    TimerEnArr[TMR_DISABLE_SPEEDADJUST] = DO_GCB;
    if (DO_GCB == 0)
    {
        TimerTrig[TMR_DISABLE_SPEEDADJUST] = 0;
    }

    if (DO_FUEL == 0 && STA_DES_PREHEAT == 0)
    {
        LOADSEND = 0;
    }
    
    /*
    if(TimerEnArr[TMR_START_IDLE_DELAY] && TimerValue[TMR_START_IDLE_DELAY]<30)
    {
        NOWLOAD = GEN_RATING_POWER *80;
    }
    */
    
    
    
    if (LOADSEND>0 && FET_LOADMODE==1 && FET_WORKMODE==0)
    {
        SPEEDSEND= FET_CONSTANTSPEED;
    }
    
    if(DO_IDLE==0 && STA_DES_ENSTOP==0 && STA_DES_START_SUCC)
    {
        LOADSEND=GEN_RATING_POWER * 80;
    }
    
    
    
    //SPEEDSEND=DES_SPEED;
    
    if(LOADSEND>0 && FET_WORKMODE==1)
    {
        
        
        if(FET_SPEEDMODE_INTERVAL>40)
        {            
            FET_SPEEDMODE_INTERVAL=0;  
            
            
            
            
            if(FET_SPEEDMODE_ERROR>400||FET_SPEEDMODE_ERROR<-400)
            {
                if(FET_SPEEDMODE_ERROR>50)
                {
                  FET_SPEEDMODE_ERROR=50;
                }
                if(FET_SPEEDMODE_ERROR<-300)
                {
                  FET_SPEEDMODE_ERROR=-300;
                }
                SPEEDSEND+=FET_SPEEDMODE_ERROR/5;
            }
            else if(FET_SPEEDMODE_ERROR>200||FET_SPEEDMODE_ERROR<-200)
            {
                SPEEDSEND+=FET_SPEEDMODE_ERROR/20;
            }
            else if(FET_SPEEDMODE_ERROR>100||FET_SPEEDMODE_ERROR<-100)
            {
                SPEEDSEND+=(AO2PERCENT-500)/100;
            }
            else if(FET_SPEEDMODE_ERROR>30||FET_SPEEDMODE_ERROR<-30)
            {
                SPEEDSEND+=(AO2PERCENT-500)/400;
            }
        }
    

          
    }
    
        if(SPEEDSEND<FET_SPEEDLIMIT_LOW)
        {
            SPEEDSEND=FET_SPEEDLIMIT_LOW;
        }
        if(SPEEDSEND>FET_SPEEDLIMIT_HIGH)
        {
            SPEEDSEND=FET_SPEEDLIMIT_HIGH;
        }
        
        if(STA_DES_START_SUCC && DO_IDLE==0)
        {
            SPEEDSEND=FET_SPEEDLIMIT_LOW;
        }
                        
        if(LOADSEND==0)
        {
            SPEEDSEND=0;
        }
        
    SENDVALUE=SPEEDSEND*8;
    CANSEND[0] = 0;
    if(FET_LOADMODE||FET_WORKMODE)
    {
    CANSEND[1] = SENDVALUE & 0xFF;
    CANSEND[2] = (SENDVALUE & 0xFF00) >> 8;
    }
    else
    {      
    CANSEND[1] = LOADSEND & 0xFF;
    CANSEND[2] = (LOADSEND & 0xFF00) >> 8;
    }
    CANSEND[3] = 0;
    if(FET_LOADMODE || FET_WORKMODE)
    {      
        CANSEND[4] = 2;      //工作模式
    }
    else
    {
        CANSEND[4] = 0;
    }
    CANSEND[5] = 0;
    CANSEND[6] = 0;
    CANSEND[7] = 0;
    CANSND1DFRM (0x0C000003, &CANSEND[0], 8, 0);
}
#endif


INT16U SFGetPidControl (INT16U usInput, INT16U usSetp, PID_PAR_STR *pPara)
{   INT32U uiCtrl, uiTemp;
    INT16U usErr;
    uiCtrl = pPara->uiCtrlOld;
    usErr  = usSetp > usInput ? usSetp - usInput : usInput - usSetp;
    if (pPara->usStability != 0)
    {   uiTemp = (INT32U)usErr * 1024 / (INT32U)(pPara->usStability);
        if (usSetp  > usInput)
        {   uiCtrl += uiTemp;
        }   else if (uiCtrl > uiTemp)
        {   uiCtrl -= uiTemp;
        }   else
        {   uiCtrl  = 0;
        }
        if (uiCtrl  < pPara->uiCtrlMin)
        {   uiCtrl  = pPara->uiCtrlMin;
        }   else if (uiCtrl > pPara->uiCtrlMax)
        {   uiCtrl  = pPara->uiCtrlMax;
        }
    }
    pPara->uiCtrlOld = uiCtrl;
    if (pPara->usGain != 0)
    {   uiTemp = (INT32U)usErr * (INT32U)(pPara->usGain);
        if (usSetp  > usInput)
        {   uiCtrl += uiTemp;
        }   else if (uiCtrl > uiTemp)
        {   uiCtrl -= uiTemp;
        }   else
        {   uiCtrl  = 0;
        }
    }
    if (pPara->usInputOld > usInput)
    {   usErr = pPara->usInputOld - usInput;
    }   else
    {   usErr = usInput - pPara->usInputOld;
    }
    if (pPara->usDerivative != 0)
    {   uiTemp = (INT32U)usErr * (INT32U)(pPara->usDerivative) / 256;
        if (pPara->usInputOld > usInput)
        {   uiCtrl += uiTemp;
        }   else if (uiCtrl > uiTemp)
        {   uiCtrl -= uiTemp;
        }   else
        {   uiCtrl  = 0;
        }
    }
    pPara->usInputOld = usInput;
    if (uiCtrl < pPara->uiCtrlMin)
    {   uiCtrl = pPara->uiCtrlMin;
    }   else if (uiCtrl > pPara->uiCtrlMax)
    {   uiCtrl = pPara->uiCtrlMax;
    }
    return (INT16U)(uiCtrl / 256);
}





//*****************************************************************************
//函数名称：  StatusCheck
//功能描述：  状态报警检测
//输入参数：  无
//输出参数：  无
//*****************************************************************************
void StatusCheck (void) 
{

static STARTFLG=0;




if((COIL_U>=EXTERN_COILTEMP &&COIL_U!=-32768 &&COIL_U!=32767 && EXTERN_COILTEMP>0)
|| (COIL_V>=EXTERN_COILTEMP &&COIL_V!=-32768 &&COIL_V!=32767 && EXTERN_COILTEMP>0)
|| (COIL_W>=EXTERN_COILTEMP &&COIL_W!=-32768 &&COIL_W!=32767 && EXTERN_COILTEMP>0) )
{
    TimerEnArr[TMR_EXCOILTEMP]=1;
}
else
{
    TimerEnArr[TMR_EXCOILTEMP]=0;
}

if(BEARING_TEMP>=EXTERN_BEARINGTEMP && BEARING_TEMP!=-32768 && BEARING_TEMP!=32767 && EXTERN_BEARINGTEMP>0)
{
    TimerEnArr[TMR_EXBEARINGTEMP]=1;
}
else
{

    TimerEnArr[TMR_EXBEARINGTEMP]=0;
}

if(TimerTrig[TMR_EXCOILTEMP])
{
    TimerTrig[TMR_EXCOILTEMP]=0;
    
}
if(TimerTrig[TMR_EXBEARINGTEMP])
{
    TimerTrig[TMR_EXBEARINGTEMP]=0;
    
}

if(NowMode==1 && STA_DES_START_SUCC==0 && MANSTART_MODE)
{
    DO_START=MANSTART_FLAG;
}

if((ChargerVoltage<DES_DPLUS_VOLT && DES_SPEED>DES_DPLUS_SPEED && DES_DPLUS_VOLT!=0)||DI_DPLUSFAULT)
{
   TimerEnArr[TMR_DPLUSFAIL]=1;
}
else
{
   TimerTrig[TMR_DPLUSFAIL]=0;
   TimerEnArr[TMR_DPLUSFAIL]=0;  
}

if(TimerTrig[TMR_DPLUSFAIL])
{
   TimerTrig[TMR_DPLUSFAIL]=0;
    ALA_DPLUSFAIL=1;
}

if(DES_WATERP_LOW!=0 && WTPRESSURE!=-32768 && WTPRESSURE/10<DES_WATERP_LOW &&TimerTrig[TMR_MAX_STABLETIME])
{
    TimerEnArr[TMR_WP_DEL]=1;
}
else
{
    TimerEnArr[TMR_WP_DEL]=0;
}

if(TimerTrig[TMR_WP_DEL])
{
    TimerTrig[TMR_WP_DEL]=0;
    ALA_WATERPLOW=1;
}

TimerEnArr[TMR_SPRINGINPUT]=DI_SPRINGINPUT;

if(TimerTrig[TMR_SPRINGINPUT])
{
    TimerTrig[TMR_SPRINGINPUT]=0;
    ALA_SPRINGINPUT=1;
}

    #if GEC16P_MODE
    
    if(STA_DES_STOP==1 && STARTFLG)
    {      
        PS_ENMAINTAIN=1;
        STARTFLG=0;
    }
    
    if(STA_DES_START_SUCC)
    {
        PS_ENMAINTAIN=0;
        STARTFLG=1;
    }
    #endif 
    
    if (lastmode != NowMode)
    {
        MODESAVE=NowMode;        
        SaveParam (158,1);
    }

    lastmode = NowMode;
    
    if (TimerValue[TMR_START_DELAY] > 0 && TimerEnArr[TMR_START_DELAY] == 1 && TimerTrig[TMR_START_DELAY] == 0 || STA_ECU_PREHEAT == 1)
    {
        STA_DES_PREHEAT = 1;
    }
    else
    {
        STA_DES_PREHEAT = 0;
    }
    
    //if (TimerEnArr[TMR_START_IDLE_DELAY]||(DO_IDLE==0 && STA_DES_START_SUCC))
    if(STA_DES_START_SUCC && DES_SPEED<(DES_RATING_ROTATION-DES_RATING_ROTATION/3))
    {
        STA_DES_START_IDLE = 1;
    }
    else
    {
        STA_DES_START_IDLE = 0;
    }
    
    
    if (TimerEnArr[TMR_STOP_IDLE_DELAY])
    {
        STA_DES_STOP_IDLE = 1;
    }
    else
    {
        STA_DES_STOP_IDLE = 0;
    }
    if (TimerEnArr[TMR_STOP_DETECT_DELAY])
    {
        STA_DES_STOPING = 1;
    }
    else
    {
        STA_DES_STOPING = 0;
    }
    if (TimerEnArr[TMR_START_INTEVAL])
    {
        STA_DES_STARTINT = 1;
    }
    else
    {
        STA_DES_STARTINT = 0;
    }


    if (CHECKDELAY < 10)
    {
        return;
    }


    //if(DES_SPEED>800)EN_DES_PROTECT_OP=1; else EN_DES_PROTECT_OP=0;

    //----------------------------------------------------------------------------

    if(DES_SPEED > (float) DES_RATING_ROTATION * 0.8)
    {
        if(DI_COOLFANSTOP)
        {
            TimerEnArr[TMR_COOLFAN]=1;
        }
        else
        {
            TimerEnArr[TMR_COOLFAN]=0;
        }
    }
    else
    {
        TimerEnArr[TMR_COOLFAN]=0;
    }
    
    if(TimerTrig[TMR_COOLFAN])                 
    {
        TimerTrig[TMR_COOLFAN]=0;
        ALA_COOLINGFAN=1;
    }

    if (DES_SPEED > (float) DES_START_SUCC_SPEED / 100 * (float) DES_RATING_ROTATION || (OILPRESSURE / 10 > DES_START_SUCC_OP) )
    {
        STA_DES_CRANKING = 0; //转速大于起动成功转速则启动标志清零
        STA_DES_START_SUCC = 1;
    }
   
    if(DES_SPEED <5 && DES_SPEED!=-32768) 
    {
        STA_DES_START_SUCC = 0;
    }




    //if ((((DES_SPEED < 10)&&(DES_SPEED!=-32768))||((DES_SPEED==-32768)&&(OILPRESSURE==0))) && (STA_DES_START_SUCC == 0))
    
    if(STA_DES_START_SUCC==0)    
    {
        if((DES_SPEED<10&&DES_SPEED!= -32768)|| (DES_SPEED==-32768)&&(OILPRESSURE/10<=DES_START_SUCC_OP))
        {
          
        STA_DES_STOP = 1;
        }
        else
        {
           STA_DES_STOP=0;
        }
    }
    else
    {
        STA_DES_STOP = 0;    //转速小于10则停机状态标志置1
    }


    
    if (DES_SPEED!=-32768 && STA_DES_ENSTOP == 0 && DES_SPEED < (float) DES_START_SUCC_SPEED / 100 * (float) DES_RATING_ROTATION && STARTSUCCFLAG/*STA_DES_START_SUCC == 1 && TimerTrig[TMR_DISABLEPROT]*/)
    {
        TimerEnArr[TMR_DES_SPEED_LO] = 1;
    }
    else
    {
        TimerEnArr[TMR_DES_SPEED_LO] = 0;
        STARTSUCCFLAG=0;
    }
    
    
    if (DES_SPEED >= des_overspeedpre)
    {
        TimerEnArr[TMR_DES_SPEED_HI_PRE] = 1;
    }
    else
    {
        TimerEnArr[TMR_DES_SPEED_HI_PRE] = 0, TimerTrig[TMR_DES_SPEED_HI_PRE] = 0;    //柴油机转速高预警
    }
    if (DES_SPEED >= des_overspeed)
    {
        TimerEnArr[TMR_DES_SPEED_HI_ALA] = 1;
    }
    else
    {
        TimerEnArr[TMR_DES_SPEED_HI_ALA] = 0;    //柴油机转速高报警
    }
    // }

    if (EN_DES_PROTECT_WT)
    {
        if (WATERTEMP > DES_AI2_PRE)
        {
            TimerEnArr[TMR_DES_AI2_PRE] = 1;
        }
        else
        {
            TimerEnArr[TMR_DES_AI2_PRE] = 0;    //水温高预警
        }
        if (WATERTEMP >= DES_AI2_ALA || DI_WATERTEMP_H)
        {
            TimerEnArr[TMR_DES_AI2_ALA] = 1;
        }
        else
        {
            TimerEnArr[TMR_DES_AI2_ALA] = 0;    //水温高报警
        }
    }

    if (EN_DES_PROTECT_OP)
    {
        if (ECUMODE)
        {
            hwoilplowpre = (float) DES_AI1_PRE * (float) DES_SPEED / 3000;
            hwoilplowala = (float) DES_AI1_ALA * (float) DES_SPEED / 3000;
            if (OILPRESSURE / 10 <= hwoilplowpre && OILPRESSURE >= 0)
            {
                TimerEnArr[TMR_DES_AI1_PRE] = 1;
            }
            else
            {
                TimerEnArr[TMR_DES_AI1_PRE] = 0;    //油压低预警
            }
            if (OILPRESSURE / 10 <= hwoilplowala && OILPRESSURE >= 0 || DI_OILP_L)
            {
                TimerEnArr[TMR_DES_AI1_ALA] = 1;
            }
            else
            {
                TimerEnArr[TMR_DES_AI1_ALA] = 0;    //油压低报警
            }
        }
        else
        {
        #if GEC16P_MODE==0
            if (OILPRESSURE / 10 < DES_AI1_PRE && OILPRESSURE >= 0)
            {
                TimerEnArr[TMR_DES_AI1_PRE] = 1;
            }
            else
            {
                TimerEnArr[TMR_DES_AI1_PRE] = 0;    //油压低预警
            }
            if (OILPRESSURE / 10 < DES_AI1_ALA && OILPRESSURE >= 0 || DI_OILP_L)
            {
                TimerEnArr[TMR_DES_AI1_ALA] = 1;
            }
            else
            {
                TimerEnArr[TMR_DES_AI1_ALA] = 0;    //油压低报警
            }
         #else
             if (DI_OILP_L)
            {
                TimerEnArr[TMR_DES_AI1_ALA] = 1;
            }
            else
            {
                TimerEnArr[TMR_DES_AI1_ALA] = 0;    //油压低报警
            }
         #endif   
        }


        //if(AI_R0>=0)TimerEnArr[15]=1;else TimerEnArr[15]=0;

    }
    else
    {
        TimerEnArr[TMR_DES_AI1_ALA] = 0;
        TimerEnArr[TMR_DES_AI1_PRE] = 0;
    }

    #if 1
    
    if(AI_USEONECHANNEL==0)
    {
         if(PowerVoltage2<= DES_BATT_LOW_ALA)
         {
             TimerEnArr[TMR_BATT_LOW2] = 1;
         }
         else
         {
             TimerEnArr[TMR_BATT_LOW2] = 0;
             TimerTrig[TMR_BATT_LOW2] = 0;
         }         
    }
    else
    {
             TimerEnArr[TMR_BATT_LOW2] = 0;
             TimerTrig[TMR_BATT_LOW2] = 0;
    }
    
    
    if (PowerVoltage<= DES_BATT_LOW_ALA)
    {
        TimerEnArr[TMR_BATT_LOW] = 1;
    }
    else
    {
        TimerEnArr[TMR_BATT_LOW] = 0, TimerTrig[TMR_BATT_LOW] = 0;    //电瓶电压低报警
    }
    
    #endif

    if(AI_USEONECHANNEL==0)
    {
         if(PowerVoltage2> DES_BATT_HIGH_ALA)
         {
             TimerEnArr[TMR_BATT_HIGH2] = 1;
         }
         else
         {
             TimerEnArr[TMR_BATT_HIGH2] = 0;
             TimerTrig[TMR_BATT_HIGH2] = 0;
         }         
    }
    else
    {
             TimerEnArr[TMR_BATT_HIGH2] = 0;
             TimerTrig[TMR_BATT_HIGH2] = 0;
    }
        
    
    #if 1
    if (PowerVoltage > DES_BATT_HIGH_ALA)
    {
        TimerEnArr[TMR_BATT_HIGH] = 1;
    }
    else
    {
        TimerEnArr[TMR_BATT_HIGH] = 0;    //电瓶电压高报警
    }
    #endif


    if (Params[141] == 7 || ECUMODE || GEC16P_MODE)
    {
        if (OILTEMP >= DES_AI3_PRE && OILTEMP >= 0)
        {
            TimerEnArr[TMR_DES_AI3_PRE] = 1;
        }
        else
        {
            TimerEnArr[TMR_DES_AI3_PRE] = 0, TimerTrig[TMR_DES_AI3_PRE] = 0;
        }
        if (OILTEMP >= DES_AI3_ALA && OILTEMP >= 0)
        {
            TimerEnArr[TMR_DES_AI3_ALA] = 1;
        }
        else
        {
            TimerEnArr[TMR_DES_AI3_ALA] = 0;    //,TimerTrig[TMR_DES_AI3_ALA]=0;
        }
    }
    else
    {
        if (ECUMODE == 0)
        {
            
            
            if (FUEL < DES_AI3_PRE && FUEL >= 0)
            {
                TimerEnArr[TMR_DES_AI3_PRE] = 1;
            }
            else
            {
                TimerEnArr[TMR_DES_AI3_PRE] = 0, TimerTrig[TMR_DES_AI3_PRE] = 0;
            }
            
            if (FUEL < DES_AI3_ALA && FUEL >= 0)
            {
                TimerEnArr[TMR_DES_AI3_ALA] = 1;
            }
            else
            {
                TimerEnArr[TMR_DES_AI3_ALA] = 0;    //,TimerTrig[TMR_DES_AI3_ALA]=0;
            }
            
            
        }
    }


    
    ALA_SPEED_LOW_STOP=0;
    //if (TimerTrig[TMR_DES_SPEED_LO])
    //{
        //ALA_SPEED_LOW_STOP          = TimerTrig[TMR_DES_SPEED_LO];
        //STARTSUCCFLAG = 0;
    //}
    ALA_SPEED_HIGH_PRE                                          = TimerTrig[TMR_DES_SPEED_HI_PRE];
    if (TimerTrig[TMR_DES_SPEED_HI_ALA])
    {
        ALA_SPEED_HIGH_STOP     = TimerTrig[TMR_DES_SPEED_HI_ALA];
    }
    ALA_TEMP_HIGH_PRE                                           = TimerTrig[TMR_DES_AI2_PRE];
    if (TimerTrig[TMR_DES_AI2_ALA])
    {
        ALA_TEMP_HIGH_STOP            = TimerTrig[TMR_DES_AI2_ALA];
    }
    ALA_OP_LOW_PRE                                              = TimerTrig[TMR_DES_AI1_PRE];
    if (TimerTrig[TMR_DES_AI1_ALA])
    {
        ALA_OP_LOW_STOP               = TimerTrig[TMR_DES_AI1_ALA];
    }
    ALA_M_POWERLOW                                            = TimerTrig[TMR_BATT_LOW];
    ALA_M_POWERHI                                             = TimerTrig[TMR_BATT_HIGH];
    ALA_BATT_LOW_ALA                                          = TimerTrig[TMR_BATT_LOW2];
    ALA_BATT_HIGH_ALA                                         = TimerTrig[TMR_BATT_HIGH2];



    if (Params[141] == 7 || ECUMODE || GEC16P_MODE)
    {
        if (TimerTrig[TMR_DES_AI3_ALA])
        {
            ALA_OILTEMP_STOP          = TimerTrig[TMR_DES_AI3_ALA];
        }
        ALA_OILTEMP_PRE           = TimerTrig[TMR_DES_AI3_PRE];
    }
    else
    {
        ALA_FUEL_LOW_PRE          = TimerTrig[TMR_DES_AI3_PRE];
        ALA_FUEL_LOW_ALA          = TimerTrig[TMR_DES_AI3_ALA];
    }


    ALA_OILTEMP_STOP          |= DI_OILT_H;







    DO_START_FAIL = ALA_START_FAIL;


    if (DES_SPEED > 400)
    {
        DO_START_SUCCESS = 1;
    }
    else
    {
        DO_START_SUCCESS = 0;
    }
    
    
  

    if (GENALA2.Byte>0 || DESALA.Byte > 0 || DESALA2.Byte > 0 || DI_ESTOP || DESALA3.Byte > 0  || HWALA.Byte > 0 || HWALA2.Byte>0)
    {
        STA_DES_ALARMS = 1;
    } 
    else
    {
        STA_DES_ALARMS = 0;
    }
    
   
        
}


//*****************************************************************************
//函数名称：  DES_STARTSTOP
//功能描述：  起动停机逻辑
//输入参数：  无
//输出参数：  无
//*****************************************************************************
void DES_STARTSTOP (void)
{

static LastMode=0;
static REC_AUTOSTART_FLG=0;

#if B_MODE

if(NowMode==2 && DO_START && REC_AUTOSTART_FLG==0 )
{
    REC_AUTOSTART_FLG=1;
    REC_AUTOSTART=1;
}

if(DO_START==0)
{
    REC_AUTOSTART_FLG=0;
}


if(NowMode!=2 && DO_IDLE==1)
{
    TimerEnArr[TMR_IDLE_RESET]=1;
    
}
else
{
    TimerEnArr[TMR_IDLE_RESET]=0;
}

if(TimerTrig[TMR_IDLE_RESET])
{  
    TimerTrig[TMR_IDLE_RESET]=0;
    DO_IDLE=0;
}

/*
if(NowMode==1 && DES_SPEED> (ulong)DES_RATING_ROTATION*80/100)
{
    DO_IDLE=1;
}

if(NowMode==1 && DI_IDLE==0)
{
    DO_IDLE=0;
}
*/

if(NowMode==3)
{
    if(DI_RMT_IDLE)
    {
        DO_IDLE=1;
    }
    else
    {      
        DO_IDLE=0;
    }
}



START_NUMS=StartNum+1;

if(TimerEnArr[TMR_START_PULSE])
{
    START_STATE=1;
}
else
{
    START_STATE=0;
}

START_DEL_PRE    = (TimerSet[TMR_START_DELAY]-TimerValue[TMR_START_DELAY])/10;

if(STA_DES_CRANKING)
{
    START_DEL_OUTPUT = (TimerSet[TMR_START_PULSE]-TimerValue[TMR_START_PULSE])/10;
}

if(STA_DES_STARTINT)
{  
    START_DEL_INT    = (TimerSet[TMR_START_INTEVAL]-TimerValue[TMR_START_INTEVAL])/10;
}

#endif


if(IO_INPUT_CONFIG1 == 9 || IO_INPUT_CONFIG2 == 9 || IO_INPUT_CONFIG3 == 9
 || IO_INPUT_CONFIG4 == 9 || IO_INPUT_CONFIG5 == 9 || IO_INPUT_CONFIG6 == 9
 || IO_INPUT_CONFIG7 == 9 || IO_INPUT_CONFIG8 == 9||IO_INPUT_CONFIG9 == 9
 ||IO_INPUT_CONFIG10==9 || IO_INPUT_CONFIG11 == 9)
{  
    TimerEnArr[TMR_DI_AUTOSTARTON]=DI_AUTOSTART_IN;
    TimerEnArr[TMR_DI_AUTOSTARTOFF]=1-DI_AUTOSTART_IN;
}
else
{
    TimerEnArr[TMR_DI_AUTOSTARTON]=DI_BTN_START;
    TimerEnArr[TMR_DI_AUTOSTARTOFF]=DI_BTN_STOP;
    if(NowMode!=2)
    {
        DI_AUTOSTART=0;
    }
}

if(ALARMSTOP)
{
    DI_AUTOSTART=0;
}

if(TimerTrig[TMR_DI_AUTOSTARTON])
{
TimerTrig[TMR_DI_AUTOSTARTON]=0;
DI_AUTOSTART=1;
}

if(TimerTrig[TMR_DI_AUTOSTARTOFF])
{
TimerTrig[TMR_DI_AUTOSTARTOFF]=0;
DI_AUTOSTART=0;
}



    if (DI_MODE_AUTO)
    {
        if (NowMode != 2)
        {
            StartNum = 0;
        }
        NowMode = 2;
        TMPFLG.BYTES.BYTEH = NowMode;
        TMPFLG.BYTES.BYTEL = 0;
        Params[PNUM_STAT] = Params[PNUM_STAT] & 0xFF | TMPFLG.Byte;
    }

    

    if(DI_MODE_REMOTE)
    {

       NowMode=3;
       TMPFLG.BYTES.BYTEH = NowMode;
       TMPFLG.BYTES.BYTEL = 0;
       Params[PNUM_STAT] = Params[PNUM_STAT] & 0xFF | TMPFLG.Byte;
       
       
    }
    
    if(DI_MODE_REMOTE==0 && DI_MODE_AUTO==0)
    {
       NowMode=1;
       TMPFLG.BYTES.BYTEH = NowMode;
       TMPFLG.BYTES.BYTEL = 0;
       Params[PNUM_STAT] = Params[PNUM_STAT] & 0xFF | TMPFLG.Byte;
    }

    if (TimerEnArr[TMR_GEN_GCB_DELAY] == 0)
    {
        TimerTrig[TMR_GEN_GCB_DELAY] = 0;
    }
  
    
    /*  

    if (NowMode == 2 && TimerTrig[TMR_BUS_FAULTSTART_DELAY] == 1 && AMFED == 0)
    {
        TimerTrig[TMR_BUS_FAULTSTART_DELAY] = 0;
        STA_DES_ENSTART = 1;
        STA_DES_ENSTOP = 0;
        AMFED = 1;
        DI_AUTOSTART_LOCK=1;
    }
            
     */
                  

    if (IO_INPUT_CONFIG1 == 24 || IO_INPUT_CONFIG2 == 24 || IO_INPUT_CONFIG3 == 24 
    || IO_INPUT_CONFIG4 == 24 || IO_INPUT_CONFIG5 == 24 || IO_INPUT_CONFIG6 == 24 
    || IO_INPUT_CONFIG7 == 24||IO_INPUT_CONFIG8 == 24||IO_INPUT_CONFIG9 == 24
    ||IO_INPUT_CONFIG10 == 24||IO_INPUT_CONFIG11 == 24)
    {
        if (DI_ENABLE_AUTOSTART)
        {
            DI_DISABLE_AUTOSTART = 0;
        }
        else
        {
            DI_DISABLE_AUTOSTART = 1;
        }
    }


   
   

    //if (IO_INPUT_CONFIG1 == 9 || IO_INPUT_CONFIG2 == 9 || IO_INPUT_CONFIG3 == 9 || IO_INPUT_CONFIG4 == 9 || IO_INPUT_CONFIG5 == 9 || IO_INPUT_CONFIG6 == 9 || IO_INPUT_CONFIG7 == 9)
    {

        if (NowMode == 2)
        {

            if (DI_AUTOSTART == 1 && !(SpeedError==1&&OILPRESSURE==-32768))

            {
                STA_DES_ENSTART = 1;
                if (STA_DES_ENSTOP == 1 && ALARMSTOP == 0)
                {
                    STA_DES_ENSTOP = 0;
                }
                /*
                if (ALA_SPEED_LOW_STOP == 1)
                {
                    TimerTrig[TMR_START_PULSE] = 0, TimerValue[TMR_START_PULSE] = 0, STA_DES_CRANKING = 0, DO_START = 0, TimerTrig[TMR_START_DELAY] = 0, STA_DES_ENSTART = 0;
                }
                */
            }
            else
            {
                STA_DES_ENSTART = 0;
                TimerValue[TMR_START_PULSE] = 0;
            }
        
            if (DI_AUTOSTART == 0)

            {
                STA_DES_ENSTOP = 1, TimerTrig[TMR_START_INTEVAL] = 0, StartNum = 0;
                if (STA_DES_CRANKING == 1 ||TimerEnArr[TMR_START_INTEVAL])
                {
                    TimerTrig[TMR_START_PULSE] = 0;
                     TimerValue[TMR_START_PULSE] = 0;
                      STA_DES_CRANKING = 0;
                       DO_START = 0;
                       TimerTrig[TMR_START_DELAY] = 0;
                        STA_DES_ENSTART = 0;
                        TimerEnArr[TMR_START_INTEVAL]=0;
                        TimerValue[TMR_START_INTEVAL]=0;
                        TimerTrig[TMR_START_INTEVAL]=0;
                }
            }
            
        }

    }

    if (TimerEnArr[TMR_START_INTEVAL] == 1 && STA_DES_ENSTOP == 1)
    {
        TimerEnArr[TMR_START_INTEVAL] = 0;
    }
    if (TimerEnArr[TMR_START_INTEVAL] == 1)
    {
        STA_DES_ENSTART = 0;
    }


    //禁止起动条件
    #if FEIERTE_MODE
    if ( ( (DI_DISABLE_AUTOSTART == 1||DISABLE_AUTOSTART) && NowMode == 2) || NowMode == 0)      
    #else    
    if ( ( (DI_DISABLE_AUTOSTART == 1) && NowMode == 2)  || NowMode == 0)
    #endif
    {
        STA_DES_ENSTART = 0;
        STA_DES_ENSTOP = 1;
        FET_ENSTART=0;
        TimerEnArr[TMR_START_PULSE] = 0;
        TimerTrig[TMR_START_PULSE] = 0;
        TimerValue[TMR_START_PULSE] = 0;

        STA_DES_CRANKING = 0;
        AMFED = 0;
        StartNum = 0;
        DO_START = 0;
    }
    else
    {
        if (/*DES_SPEED < 5 && DES_SPEED!=-32768*/STA_DES_START_SUCC==0)
        {
            if(DES_SPEED!=-32768 || OILPRESSURE!=-32768)
            {              
                STA_DES_ENSTOP = 0;
            }
        }

    }




#if GECMODE25 
    if (STA_BUS_NORMAL == 1 && NowMode == 2)
    {
        TimerEnArr[TMR_BUS_NORMAL_DELAY] = 1;
    }
    else
    {
        TimerEnArr[TMR_BUS_NORMAL_DELAY] = 0;
        TimerTrig[TMR_BUS_NORMAL_DELAY] = 0;
    }

    if (TimerTrig[TMR_BUS_NORMAL_DELAY] == 1)
    {
        TimerTrig[TMR_BUS_NORMAL_DELAY] = 0;
        STA_DES_ENSTOP = 1;
    }

#endif


    if (DI_ESTOP || ALA_ESTOP)
    {
        StartNum = 0;
        DO_FUEL = 0;
        DO_START = 0;
        DO_IDLE = 0;
        //DO_STOP=1;
        STA_DES_ENSTART = 0;
        STA_DES_CRANKING = 0;
        TimerEnArr[TMR_GEN_GCB_DELAY]=0;
        //STA_DES_ENSTOP=1;
        if (NOBUZZER == 0)
        {
            DO_BUZZER = 1;
        }
        if (DES_SPEED > 5)
        {
            DO_STOP = 1;
        }
        else
        {
            DO_STOP = 0;
        }
        return;
    }

    if (NowMode <= 3) //手动或者测试模式时
    {

        if (DES_SPEED > 5 || ALARMSTOP)
        {
            STA_DES_ENSTART = 0;
        }
        
        if(DI_SPRINGINPUT)
        {
            STA_DES_ENSTART = 0;
            TimerEnArr[TMR_START_DELAY]=0;
        }
        
        if (STA_DES_ENSTART)
        
        {
            TimerEnArr[TMR_START_DELAY] = 1;
        }

        if(SpeedError==1 && OILPRESSURE==-32768)
        {        
            TimerTrig[TMR_START_DELAY]=0;
            STA_DES_ENSTART=0;
            TimerEnArr[TMR_START_DELAY]=0;
        }

        if (TimerTrig[TMR_START_INTEVAL] == 1)
        {
            TimerTrig[TMR_START_INTEVAL] = 0;
            STA_DES_ENSTART = 1;
        }

        if (DES_SPEED == 0 && STA_DES_ENSTART == 0)
        {
            TimerEnArr[TMR_START_DELAY] = 0, TimerTrig[TMR_START_DELAY] = 0;
        }


        if(STA_DES_START_SUCC)
        {
            TimerTrig[TMR_START_DELAY]=1;
            
        }


        if (TimerTrig[TMR_START_DELAY] == 1)
        {
            // TimerTrig[TMR_START_DELAY]=0;
            

            if (ALARMSTOP==0 && (SpeedError==1&&OILPRESSURE==-32768)==0)
            {



                if (STA_DES_STOP == 1 && STA_DES_CRANKING == 0 && STA_DES_ENSTART == 1 && STA_DES_START_SUCC == 0)
                {
                    TimerTrig[TMR_START_INTEVAL] = 0;
                    DO_FUEL = 1;
                    TimerEnArr[TMR_START_PULSE] = 1;
                    STA_DES_CRANKING = 1;
                }

                if (TimerValue[TMR_START_PULSE] > 10 && DO_START == 0 && STA_DES_CRANKING == 1 )
                {
                    DO_START = 1;
                    // DO_FUEL=0;
                }
                /*
                if(DI_SPRINGINPUT)
                {
                    DO_START=0;
                }
                */
                if (TimerTrig[TMR_START_PULSE] == 1)
                {
                    DO_FUEL = 0;
                    DO_START = 0;
                    StartNum++;
                    EPROM_UNSUCSTARTS++;
                    SaveParam(198,1);
                    TimerEnArr[TMR_START_PULSE] = 0;
                    TimerTrig[TMR_START_PULSE] = 0;
                    STA_DES_CRANKING = 0;
                    STA_DES_ENSTART = 0;

                    if (NowMode == 1|| NowMode==3 || (StartNum >= DES_START_TIMES && NowMode != 1) )
                    {
                        DO_FUEL = 0;
                        ALA_START_FAIL = 1;
                        StartNum = 0;
                        STA_DES_ENSTART = 0;
                    }
                    else
                    {
                        TimerEnArr[TMR_START_INTEVAL] = 1;
                    }


                }
            }

            if (STA_DES_START_SUCC) //DES_SPEED>(float)DES_START_SUCC_SPEED/1000*(float)DES_RATING_ROTATION)
            {
                STA_DES_ENSTART = 0;
                TimerEnArr[TMR_START_PULSE] = 0;
                if (DO_IDLE == 0 && STA_DES_ENSTOP == 0)
                {
                    TimerEnArr[TMR_START_IDLE_DELAY] = 1;
                }
                StartNum = 0;
                DO_START = 0;                 
            }
            if (TimerTrig[TMR_START_IDLE_DELAY] == 1)
            {
                TimerEnArr[TMR_START_IDLE_DELAY] = 0;
                
                #if B_MODE
                if(NowMode==2)
                {
                    DO_IDLE=1;
                }
                //else
                //{
                //    DO_IDLE=0;
                //}
                #else                
                if (WCZJ_MODE==1 && NowMode>1)
                {                  
                DO_IDLE = 1;
                }
                else if(WCZJ_MODE==0)
                {
                DO_IDLE=1;
                }
                #endif
                 
                 
                TimerTrig[TMR_START_IDLE_DELAY] = 0;
            }

        }

    }


    if (STA_DES_STOP == 1)
    {
        DO_IDLE = 0;
    }

    if (STA_DES_START_SUCC && DI_ESTOP==0) // && STA_DES_ENSTOP==0)
    {
        if (STA_DES_ENSTOP == 0)
        {
            DO_FUEL = 1, TimerEnArr[TMR_DISABLEPROT] = 1;
        }
        if (TimerTrig[TMR_DISABLEPROT])
        {
            EN_DES_PROTECT = 1;
        }
        if (TimerTrig[TMR_DISABLEPROT])
        {
            EN_DES_PROTECT_OP = 1;
        }
    }
    else
    {
        TimerTrig[TMR_DISABLEPROT] = 0;
        TimerTrig[TMR_DISABLEPROT] = 0;
        EN_DES_PROTECT = 0;
        EN_DES_PROTECT_OP = 0;
        TimerEnArr[TMR_DES_AI1_ALA] = 0;
    }

    if (STA_DES_ENSTOP && DES_SPEED==-32768 && OILPRESSURE==-32768)
    {
        TimerTrig[TMR_STOP_IDLE_DELAY] = 0;
        TimerEnArr[TMR_STOP_IDLE_DELAY] = 0;
        DO_STOP=1;
        TimerEnArr[TMR_STOP_DETECT_DELAY] = 1;
        if (TimerTrig[TMR_STOP_DETECT_DELAY] == 1)
        {
            //延时时间到并且转速小于5
            //STA_DES_START_SUCC=0;
            STA_DES_ENSTOP=0;
            TimerTrig[TMR_STOP_OUTPUT_PULSE] = 0;
            DO_STOP = 0;         //断开停机
            TimerTrig[TMR_STOP_DETECT_DELAY] = 0;
            TimerTrig[TMR_STOP_DELAY] = 0;
            TimerTrig[TMR_STOP_IDLE_DELAY] = 0;
            TimerEnArr[TMR_STOP_DETECT_DELAY]=0;
        }
          
    }    
    else if (STA_DES_ENSTOP && STA_DES_STOP == 0)
    {

        TimerTrig[TMR_START_IDLE_DELAY] = 0;
        STA_DES_ENSTART = 0;
        //TimerEnArr[TMR_START_DELAY]=0;
        //TimerTrig[TMR_START_DELAY]=0;


        if (/*DI_GCB==0 && */TimerTrig[TMR_STOP_IDLE_DELAY] == 0 && DO_STOP == 0 && STA_DES_START_SUCC && ALA_STOP_FAIL == 0)
        {
            TimerEnArr[TMR_STOP_DELAY] = 1;
        }


        TimerEnArr[TMR_GEN_GCB_DELAY] = 0;        //分闸


        if (TimerTrig[TMR_STOP_DELAY] == 1)
        {
            //高速延时结束
            TimerTrig[TMR_STOP_DELAY] = 0;
            TimerEnArr[TMR_STOP_DELAY] = 0;
            TimerEnArr[TMR_STOP_IDLE_DELAY] = 1; //怠速延时开始
        }

        if (TimerEnArr[TMR_STOP_DELAY])
        {
            if (DES_COOL_SPEED == 1)
            {
                DO_IDLE = 0;    //怠速
            }
        }




        if (TimerTrig[TMR_STOP_IDLE_DELAY] == 1)
        {
            //怠速延时结束
            TimerTrig[TMR_STOP_IDLE_DELAY] = 0;
            TimerEnArr[TMR_STOP_IDLE_DELAY] = 0;

            if (!ALA_STOP_FAIL)
            {
                DO_STOP = 1;    //停机输出
            }
            DO_FUEL = 0;         //供油断开
            TimerEnArr[TMR_STOP_DETECT_DELAY] = 1;  //停机失败监测延时开始
            TimerTrig[TMR_STOP_OUTPUT_PULSE] = 1;  //停机输出时间延时
        }

        //if (TimerTrig[TMR_STOP_OUTPUT_PULSE] == 1 && DES_SPEED < 5)
        if (TimerTrig[TMR_STOP_OUTPUT_PULSE] == 1 && STA_DES_START_SUCC == 0)
        {
            //延时时间到并且转速小于5
            //STA_DES_START_SUCC=0;
            TimerTrig[TMR_STOP_OUTPUT_PULSE] = 0;
            DO_STOP = 0;         //断开停机
            TimerTrig[TMR_STOP_DETECT_DELAY] = 0;
            TimerTrig[TMR_STOP_DELAY] = 0;
            TimerTrig[TMR_STOP_IDLE_DELAY] = 0;
        }

        if (TimerTrig[TMR_STOP_DETECT_DELAY] == 1)
        {
            TimerTrig[TMR_STOP_DETECT_DELAY] = 0;
            DO_STOP = 0;         //断开停机
            if (STA_DES_START_SUCC && NowMode < 4)
            {
                ALA_STOP_FAIL = 1; //停机失败被检测
            }
        }






    }
    else
    {
        TimerEnArr[TMR_STOP_DETECT_DELAY] = 0;
        TimerEnArr[TMR_STOP_OUTPUT_PULSE] = 0;
        TimerEnArr[TMR_STOP_DELAY] = 0;
        TimerEnArr[TMR_STOP_IDLE_DELAY] = 0;
        TimerTrig[TMR_STOP_DETECT_DELAY] = 0;
        TimerTrig[TMR_STOP_OUTPUT_PULSE] = 0;
        TimerTrig[TMR_STOP_DELAY] = 0;
        TimerTrig[TMR_STOP_IDLE_DELAY] = 0;

    }

    if (TimerEnArr[TMR_STOP_IDLE_DELAY] == 1 && NowMode==1)
    {
        TimerTrig[TMR_STOP_IDLE_DELAY] = 1;
    }

    if (DO_IDLE == 0 && TimerEnArr[TMR_START_IDLE_DELAY] == 0 && STA_DES_START_SUCC && STA_DES_ENSTOP == 0)
    {
              #if B_MODE
              if(NowMode==2)
              {              
                  TimerEnArr[TMR_START_IDLE_DELAY]= 1;
              }
              
              #endif  
                
    }
    if (/*DES_SPEED < 5 &&DES_SPEED!=-32768*/STA_DES_START_SUCC==0)
    {
        if (STA_DES_ENSTART == 0 && DO_START==0)
        {
            DO_FUEL = 0;
        }
        if(DES_SPEED<5 && SpeedError==0)
        {          
            DO_STOP = 0;
        }
        if(OILPRESSURE!=-32768 && OILPRESSURE<=20)
        {
            DO_STOP=0;
        }
        if(DES_SPEED!=-32768 || OILPRESSURE!=-32768)
        {          
            STA_DES_ENSTOP = 0;
        }
    }

    if (ALA_STOP_FAIL)
    {
        DO_STOP = 0;
    }

    if (DES_SPEED > (float) DES_RATING_ROTATION * 0.5/* && DES_SPEED<(float)DES_RATING_ROTATION*1.1*/)
    {
        STA_DES_RUNNING = 1;
    }
    else
    {
        STA_DES_RUNNING = 0;
    }



    if (STA_DES_START_SUCC && (DO_IDLE|| DES_SPEED> (ulong)DES_RATING_ROTATION*80/100))
    {
        TimerEnArr[TMR_MIN_STABLETIME] = 1;
        TimerEnArr[TMR_MAX_STABLETIME] = 1;
        if (TimerTrig[TMR_MAX_STABLETIME])
        {
            EN_GEN_PROTECT = 1;
        }
    }
    else
    {
        TimerEnArr[TMR_MIN_STABLETIME] = 0;
        TimerEnArr[TMR_MAX_STABLETIME] = 0;
        TimerTrig[TMR_MIN_STABLETIME] = 0;
        TimerTrig[TMR_MAX_STABLETIME] = 0;
        EN_GEN_PROTECT = 0;
    };


    /*
    if (DI_GCB)
    {
        EN_GEN_PROTECT = 1;
    }
      */



    LastMode = NowMode;

}

//*****************************************************************************
//函数名称：  Protection
//功能描述：  报警保护动作
//输入参数：  无
//输出参数：  无
//*****************************************************************************
void Protection (void)
{

if(OILPRESSURE==-32768)
{  
    TimerEnArr[TMR_OPERR]=1;
}
else
{
    TimerEnArr[TMR_OPERR]=0;
    ALA_OPERR=0;
}

if(TimerTrig[TMR_OPERR])
{
    TimerTrig[TMR_OPERR]=0;
    ALA_OPERR=1;
}

if(WATERTEMP==-32768)
{  
    TimerEnArr[TMR_WTERR]=1;    
}
else
{
    TimerEnArr[TMR_WTERR]=0; 
    ALA_WTERR =0;
}

if(TimerTrig[TMR_WTERR])
{
    TimerTrig[TMR_WTERR]=0;
    ALA_WTERR=1;
}



if(OILTEMP==-32768 && Params[141] == 7)
{      
    TimerEnArr[TMR_OTERR]=1;     
}
else
{
    TimerEnArr[TMR_OTERR]=0; 
    ALA_OTERR=0;    
}

if(TimerTrig[TMR_OTERR])
{
    TimerTrig[TMR_OTERR]=0;
    ALA_OTERR=1;
}



if(SpeedError)
{  
    ALA_SPEEDERR=1; 
}
else
{
    ALA_SPEEDERR=0;
}

if(SpeedError2)
{
    TimerEnArr[TMR_SPEEDERR2]=1;   
}

else
{
    TimerEnArr[TMR_SPEEDERR2]=0;
    ALA_SPEEDERR2=0;
}

    if(TimerTrig[TMR_SPEEDERR2])
    {
        TimerTrig[TMR_SPEEDERR2]=0;
        ALA_SPEEDERR2=1;
    }
 
 

    #if B_MODE
    
    if(ALA_START_FAIL)
    {
        ALARMSTOP = 1;
        STA_DES_ENSTOP=1;
    }
    
    if((ALA_COOLINGFAN ||ALA_TEMP_HIGH_STOP||ALA_SPEED_HIGH_STOP||
       ALA_OILTEMP_STOP||ALA_SAFE_LOWOP||ALA_SAFE_HIWT||ALA_SAFE_HIOT||ALA_SAFE_HISPD/*||ALA_SPEED_LOW_STOP*/)&&DI_NOSTOP==0) 
      {
          ALARMSTOP = 1;
          STA_DES_ENSTOP=1;
      }
    #endif
    

    if (ALA_SPEED_HIGH_STOP == 1||DI_ESTOP)
    {
        if (DO_START == 1)
        {       
            ALARMSTOP = 1;
            //FET_ENSTART=0;
            DO_START = 0;
        }
        ALARMSTOP = 1;
        STA_DES_ENSTOP = 1;
        STA_DES_CRANKING = 0;
        TimerTrig[TMR_STOP_IDLE_DELAY] = 1;
    }



    if (ALA_OP_LOW_STOP && DI_NOSTOP == 0)
    {
        ALARMSTOP = 1;
        FET_ENSTART=0;
        STA_DES_ENSTOP = 1;
        TimerTrig[TMR_STOP_IDLE_DELAY] = 1;
    }
    //改温度直接停机
    if (ALA_TEMP_HIGH_STOP && DI_NOSTOP == 0)
    {
        ALARMSTOP = 1;        
        STA_DES_ENSTOP = 1;
        TimerTrig[TMR_STOP_IDLE_DELAY] = 1;
    }    
    
}



//*****************************************************************************
//函数名称：  TransParams
//功能描述：  转换参数单位
//输入参数：  无
//输出参数：  无
//*****************************************************************************

void TransParams (void) //转换参数
{

    
   uchar idx;

   uchar LUBFUNC;
   
   TimerSet[TMR_WP_DEL]=20;
   TimerSet[TMR_DPLUSFAIL]=50;
   
   TimerSet[TMR_GCB_PULSE_ON] = 100;
   TimerSet[TMR_GCB_PULSE_OFF] = 100;


   TimerSet[TMR_EXCOILTEMP]=20;
   TimerSet[TMR_EXBEARINGTEMP]=20;
   
   
   
   for(idx=0;idx<11;idx++)
   {
   TimerSet[TMR_DI1_DEL+idx]= *(&IO_INPUT_DEL1 +idx*2);
   }
   
   LUBFUNC=0;   
   
   if(SYS_D4D2MODE)
   {
       D423MODE=1;
       D223MODE=0;
   }
   else
   {
       D423MODE=0;
       D223MODE=1;
   }
   
   
   for(idx=0;idx<7;idx++) 
   {
        if(Params[132+idx]==44)
        {
            LUBFUNC=1;
            break;
        }  
         if(Params[164+idx]==44)
        {
            LUBFUNC=1;
            break;
        }                  
   }
    STA_DES_LUBFUNC=LUBFUNC;
       TimerSet[TMR_SPEEDADJUST_FREQ]=20;
    TimerMode[TMR_SPEEDADJUST_FREQ]=1;
    
   TimerSet[TMR_SPEEDERR2]=50;
   
   
   TimerSet[TMR_FUEL_LEAK] =20;   //燃油泄漏
   TimerSet[TMR_LOW_LEVEL] =20;   //淡水位低
   TimerSet[TMR_WPLOW]     =20;   //淡水压力低
   TimerSet[TMR_SWPLOW]    =20;   //海水压力低
   TimerSet[TMR_FUELLOW]   =20;   //油位低
   TimerSet[TMR_SPLOW]     =20;   //起动压力低
   TimerSet[TMR_GENLEAK]   =20;   //电机水泄漏
   TimerSet[TMR_COILTEMP]  =20;   //绕组高温
   
   TimerSet[TMR_SPRINGINPUT]=5;   //弹簧起动输入
   
   TimerSet[TMR_COOLFAN]=10;
   
    TimerSet[TMR_OPERR]=20;
    TimerSet[TMR_WTERR]=20;
    TimerSet[TMR_OTERR]=20;   
   
   
    TimerSet[TMR_IDLE_RESET]=20;
   
    TimerSet[TMR_RESET_DELAY]=20;
                             

    TimerSet[TMR_TIMER1]=Timer1Value*600;
    TimerSet[TMR_TIMER2]=Timer2Value*600;
    TimerSet[TMR_DI_AUTOSTARTON]=10;
    TimerSet[TMR_DI_AUTOSTARTOFF]=10;
    
    TimerSet[TMR_SPEED_CHECK]=30;
    TimerMode[TMR_SPEED_CHECK]=1;    
   
    RunningErr                     = DES_RATING_ROTATION / 200;


    TimerSet[TMR_DES_SPEED_HI_PRE]   = 10;
    TimerSet[TMR_DES_SPEED_HI_ALA]   = 10;


    TimerSet[TMR_DES_SPEED_LO] = 80;
    TimerSet[TMR_DES_AI2_PRE] = DES_AI2_DELAY * 10; //水温高检测延时
    TimerSet[TMR_DES_AI2_ALA] = DES_AI2_DELAY * 10; //水温过高检测延时
    TimerSet[TMR_DES_AI1_PRE] = DES_AI1_DELAY * 10; //油压低检测延时
    TimerSet[TMR_DES_AI1_ALA] = DES_AI1_DELAY * 10; //油压过低检测延时
    TimerSet[TMR_BATT_LOW] = DES_BATT_DELAY * 10; //电瓶电压低检测延时
    TimerSet[TMR_BATT_LOW2] = DES_BATT_DELAY * 10; //电瓶电压低检测延时
    TimerSet[TMR_BATT_HIGH] = DES_BATT_DELAY * 10; //电瓶电压高检测延时
    TimerSet[TMR_BATT_HIGH2]=DES_BATT_DELAY * 10;  //电瓶电压高检测延时
    TimerSet[TMR_DES_AI3_PRE] = DES_AI3_DELAY * 10; //燃油位预报警检测延时
    TimerSet[TMR_DES_AI3_ALA] = DES_AI3_DELAY * 10; //燃油位报警检测延时
    TimerSet[TMR_MAX_STABLETIME] = (DES_MAX_STABLETIME + 1) * 10; //最长时间延时
    TimerSet[TMR_MIN_STABLETIME] = (DES_MIN_STABLETIME + 1) * 10; //最短时间延时
    TimerSet[TMR_STOP_DETECT_DELAY] = (DES_STOP_OUTPUT_PULSE) * 10; //停稳监测延时
    TimerSet[TMR_STOP_OUTPUT_PULSE] = (DES_STOP_OUTPUT_PULSE) * 10; //停机输出时间
    TimerSet[TMR_STOP_DELAY] = 10;   //停机延时
    TimerSet[TMR_STOP_IDLE_DELAY] = (DES_STOP_IDLE_DELAY) * 10; //停机怠速时间
    TimerSet[TMR_START_DELAY] = (DES_START_DELAY) * 10; //预启动延时时间
    TimerSet[TMR_START_IDLE_DELAY] = (DES_START_IDLE_DELAY + 1) * 10; //起动怠速延时时间
    TimerSet[TMR_START_INTEVAL] = (DES_START_INTEVAL + 1) * 10; //启动间隔时间
    TimerSet[TMR_START_PULSE] = (DES_START_PULSE + 1) * 10; //启动输出时间
    
    TimerSet[TMR_BUZZER] = DES_BUZZ_TIME * 10;        
    des_overspeed = (float) DES_OVERSPEED_ALA / 100 * (float) DES_RATING_ROTATION;
    des_overspeedpre = (float) (DES_OVERSPEED_ALA - 5) / 100 * (float) DES_RATING_ROTATION;
    
    des_lowspeed = (float) 80 * (float) DES_RATING_ROTATION;
    


    AIFACT1 = (float) ELECADJUST1 / 10000; //1.0017;
    AIFACT2 = (float) ELECADJUST2 / 10000; //1.0017;
    AIFACT3 = (float) ELECADJUST3 / 10000; //1.0017;
    AIFACT4 = (float) ELECADJUST4 / 10000; //1.0017;
    AIFACT5 = (float) ELECADJUST5 / 10000; //1.0017;
    AIFACT6 = (float) ELECADJUST6 / 10000; //1.0017;
    AIFACT7 = (float) ELECADJUST7 / 10000; //1.0017;
    AIFACT8 = (float) ELECADJUST8 / 10000; //1.0017;
    AIFACT9 = (float) ELECADJUST9 / 10000; //1.0017;
    BATTFACT = (float) BATTADJUST / 10000;
    CHARGEFACT = (float) CHARGEADJUST / 10000;
    GENVOLTFACT= (float) GENVOLTADJUST / 10000;
    ADJUST1 = (float) ADJUSTR1 / 10000; //1.0031;
    ADJUST2 = (float) ADJUSTR2 / 10000; //1;
    ADJUST3 = (float) ADJUSTR3 / 10000; //1.002;
    GENPT = (float) GEN_VOLTAGE_PT / 10;
    //MAINPT = (float) MAIN_VOLTAGE_PT / 10;
    #if B_MODE
    ADJUST[5] = ADJUST2;
    ADJUST[0] = ADJUST1;
    ADJUST[6] = ADJUST3;
    #endif

}


//*****************************************************************************
//函数名称：  ResetProcess
//功能描述：  复位故障处理
//输入参数：  无
//输出参数：  无
//*****************************************************************************
void ResetProcess (void) 
{
    char i;
    ResetFlag=1;
    TimerTrig[TMR_BATT_LOW2]=0;    
    TimerTrig[TMR_BATT_HIGH2]=0;
    TimerTrig[TMR_DPLUSFAIL]=0;
    ALA_DPLUSFAIL=0;
    
    TimerTrig[TMR_COOLFAN]=0;
    TimerEnArr[TMR_SPEED_CHECK]=0;
    TimerTrig[TMR_SPEED_CHECK]=0;
    DO_SPEEDCHECK=0;
    BOUT_SPEEDSENSOR=1;
    TimerEnArr[TMR_RESET_DELAY]=1;

    STA_DES_START_SUCC = 0;
    
    //for (i = 4; i < 21; i++)
    for (i = 0; i < 11; i++)
    {
        TimerTrig[i] = 0;
    }
    
    

    
    
    
    TimerTrig[TMR_COILTEMP] = 0;

    DO_STOP = 0;
    BUSALA.Byte =0;
    DESALA.Byte = 0;
    DESALA2.Byte = 0;
    DESALA3.Byte = 0;
    DESALA4.Byte=0;
    GENALA.Byte = 0;
    GENALA2.Byte = 0;
    HWALA.Byte = 0;
    
    if(AI_ADVALUE[1]<SPEEDAD || FreqArr[0]>5)
    {      
        SpeedError = 0;
    }
    
    STA_DES_ALARMS = 0;
    STA_DES_PREALARMS = 0;
    AMFED = 0;
    ALARMPAGE[0] = 0;
    ALARMPAGE[1] = 0;
    ALARMPAGE[2] = 0;
    ALARMSTOP = 0;
    if (STA_DES_ENSTOP == 1)
    {
        STA_DES_ENSTOP = 0;
    }
    TimerEnArr[TMR_STOP_DETECT_DELAY] = 0;
    TimerTrig[TMR_STOP_OUTPUT_PULSE] = 0;
    DO_STOP = 0;         //断开停机
    TimerTrig[TMR_STOP_DETECT_DELAY] = 0;
    TimerTrig[TMR_STOP_DELAY] = 0;
    TimerTrig[TMR_STOP_IDLE_DELAY] = 0;

TimerTrig[TMR_FUEL_LEAK]=0;
TimerTrig[TMR_LOW_LEVEL]=0;
TimerTrig[TMR_WPLOW]=0;
TimerTrig[TMR_SWPLOW]=0;
TimerTrig[TMR_FUELLOW]=0;
TimerTrig[TMR_SPLOW]=0;
TimerTrig[TMR_GENLEAK]=0;
TimerTrig[TMR_COILTEMP]=0;

}

//*****************************************************************************
//函数名称：  ForceMode
//功能描述：  强制转换模式
//输入参数：  mode 模式编号
//输出参数：  无
//*****************************************************************************
void ForceMode (uchar mode)
{
    COMMON_STATUS &= 0xFF00;
    if (mode > 3)
    {
        mode = 3;
    }
    NowMode = mode;
    TMPFLG.Byte=Params[PNUM_STAT];
    TMPFLG.BYTES.BYTEH = mode;
    Params[PNUM_STAT]=TMPFLG.Byte;
    COMMON_STATUS |= TMPFLG.BYTES.BYTEH;
}

void AccumulationCalc(void)
{
 static int Second=0;
 static int Minute=0;
 static int Hour=0;
 static int RunSec=0;
 static int RunMin=0;
 static int RunHour=0;
 static uchar LastStatus=0;
 STRFLG32 TMP;
 
 if(LastStatus==0 && STA_DES_START_SUCC)
 {
     RUNTIME++;
     if(RUNTIME>9999)
     {
         RUNTIME=0;
     }
     SaveParam(182,1);
 }
 
 LastStatus=STA_DES_START_SUCC;
 if(STA_DES_STOP)
 { 
     Second++;
 }
 
 if(STA_DES_START_SUCC)
 {
     RunSec++;          
 }
 
 if(RunSec>=60)
 {
     RunSec=0;
     RUNMINUTE++;     
     SaveParam(181,1); 
     if(MaintainDays>0)
     {      
         MaintainDays=0;
         SaveParam(PN_MAINTAINDAY,1);
     }
     
 }
 
 if(RUNMINUTE>=60)
 {
     RUNMINUTE=0;
     SaveParam(181,1);
     RUNHOUR++;
     SaveParam(PN_RUNHOUR,1);   
 }
 
 
 if(Second>=60)//每分钟
 {
     Minute++;
     Second=0;  
                                      
     #if GEC16P_MODE                              
     if(Minute % 10==0)
     {
      
         TMP.UDWORD=TimerValue[TMR_PS_FIRSTMAINTAIN];                    
         PS_TMRSAVE_FIRST_H=TMP.WORDS.WORDH;  
         PS_TMRSAVE_FIRST_L=TMP.WORDS.WORDL;  
         TMP.UDWORD=TimerValue[TMR_PS_REFRESH_CYCLE];
         PS_TMRSAVE_REFRESH_H=TMP.WORDS.WORDH;
         PS_TMRSAVE_REFRESH_L=TMP.WORDS.WORDL;
         TMP.UDWORD=TimerValue[TMR_PS_REFILL_CYCLE];
         PS_TMRSAVE_REFILL_H=TMP.WORDS.WORDH; 
         PS_TMRSAVE_REFILL_L=TMP.WORDS.WORDL;  
         SaveParam(91,6);
     }
     #endif
 }
 
  if(Minute>=60)//每小时
 {
     Hour++;
     Minute=0;
    
 }
 
  if(Hour>=24)  //每天
 {
 
     MaintainDays++;
     SaveParam(PN_MAINTAINDAY,1);      
     Hour=0;
 }
 
 
 
 
}

uchar ParamCheck(int ParamNum ,int Paramvalue)
{
   #if FEIERTE_MODE==0
   return 1;
   #endif

    switch(ParamNum)
    {
      case 171:
      if(Paramvalue<=Params[177])
      {
          return 0;
      }
      break;
      
      case 177:
      if(Paramvalue>=Params[171])
      {
          return 0;
      }
      break;   
      
      case 102:
      if(Paramvalue<=Params[103])
      {
          return 0;
      }
      break;  
          
      case 103:
      if(Paramvalue>=Params[102])
      {
          return 0;
      }
      break;         
         
      
      case 167:
      if(Paramvalue<=Params[168])
      {
          return 0;
      }
      break;  
          
      case 168:
      if(Paramvalue>=Params[167])
      {
          return 0;
      }
      break;  
      
      case 118:
      if(Paramvalue>=Params[119])
      {
          return 0;
      }
      break;  
          
      case 119:
      if(Paramvalue<=Params[118])
      {
          return 0;
      }
      break;  
            
      case 37:
      if(Paramvalue>=Params[38])
      {
          return 0;
      }
      break;  
          
      case 38:
      if(Paramvalue<=Params[37])
      {
          return 0;
      }
      break;       
             
               
    }
    
    
    
    return 1;
}

