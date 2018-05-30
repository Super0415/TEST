#include "PublicShare.h"
#include "ai.h"

//uchar SPEEDERR=0;
ulong modulusV1=1440;
ulong modulusV2=1440;
ulong modulusI=720;

int SPEEDTEST=0;
ulong FREQMPTEST=0;

uint angle_buf1;
uint angle_buf2;
uint angle_buf3;
uint tempdata1 = 0;
uint tempdata2 = 0;
uint tempdata3 = 0;
uint tempdata4 = 0;
uint tempdata5 = 0;

uchar MYTEST=0;

long KWA100 = 0;
long KWB100 = 0;
long KWC100 = 0;
long KVARA100 = 0;
long KVARB100 = 0;
long KVARC100 = 0;
long KVAA100=0;
long KVAB100=0;
long KVAC100=0;
long PhaseR[9];
long PhaseI[9];
float CT;
uint FUELBUFF[BUF_LEN];
uint UA1BUFF[BUF_LEN];
uint UB1BUFF[BUF_LEN];
uint UC1BUFF[BUF_LEN];
uint UA2BUFF[BUF_LEN];
uint UB2BUFF[BUF_LEN];
uint UC2BUFF[BUF_LEN];

uint UAB1BUFF[BUF_LEN];
uint UBC1BUFF[BUF_LEN];
uint UCA1BUFF[BUF_LEN];

uint UAB2BUFF[BUF_LEN];
uint UBC2BUFF[BUF_LEN];
uint UCA2BUFF[BUF_LEN];
uint IABUFF[BUF_LEN];
uint IBBUFF[BUF_LEN];
uint ICBUFF[BUF_LEN];

uint AI0BUFF[BUF_LEN];
uint AI1BUFF[BUF_LEN];
uint AI2BUFF[BUF_LEN];
uint AI3BUFF[BUF_LEN];
uint AI4BUFF[BUF_LEN];
uint AI5BUFF[BUF_LEN];
uint AI6BUFF[BUF_LEN];
uint AI7BUFF[BUF_LEN];

uint AIBUFF[AI_NUM][BUF_LEN];


uint BATTBUFF[BUF_LEN];
uint BATTBUFF2[BUF_LEN];
uint CHARGEBUFF[BUF_LEN];

uint SENDLOAD[BUF_LEN];

 

 long    r_powa_buf[BUF_LEN];//real power gen a phase buf
 long    r_powb_buf[BUF_LEN];//real power gen b phase buf
 long    r_powc_buf[BUF_LEN];//real power gen c phase buf
 long    i_powa_buf[BUF_LEN];//image power gen a phase buf
 long    i_powb_buf[BUF_LEN];//image power gen b phase buf
 long    i_powc_buf[BUF_LEN];//image power gen c phase buf
 


static uint ai_cal_ui (int *TmpArr , uint modulus, char lx_ch)
{
    
    int i;
    float anlog_cos, anlog_sin;
    long lng_cos = 0;
    long lng_sin = 0;
    float buf1;
    float buf2;
    float sum;
    unsigned long sumcheck = 0;
    anlog_cos = 0;
    anlog_sin = 0;
    sum = 0;

    for (i = 0; i < 32; i++) // COS value
    {
        lng_cos  += (long) TmpArr[i] * (long) cos_tab[i]; //平方值
        lng_sin  += (long) TmpArr[i] * (long) sin_tab[i]; //平方值

        if (TmpArr[i] >= 2048)
        {
            sumcheck += (ulong) TmpArr[i] - 2048;
        }
        else
        {
            sumcheck += 2048 - (ulong) TmpArr[i];
        }
    }

    if (sumcheck < 64)
    {
        PhaseR[lx_ch]=0;
        PhaseI[lx_ch]=0;    
        return 0;

    }

    anlog_cos = (float) lng_cos / 64 / (float) modulus;
    anlog_sin = (float) lng_sin / 64 / (float) modulus ;
    PhaseR[lx_ch] = anlog_cos;
    PhaseI[lx_ch] = anlog_sin;
    buf1 = anlog_cos * anlog_cos;
    buf2 = anlog_sin * anlog_sin;
    sum = sqrtf (buf1+buf2);
    return (unsigned int) (sum);
}




//************************************************************************************
//函数名称：  ai_pushdata_uint()
//功能描述：  push data buf , abandon oldest
//输入参数：  buf pointer
//输出参数：
//************************************************************************************
static void ai_pushdata_uint (uint *pdata)
{
    uchar i;

    for (i = 0; i < (BUF_LEN - 1); i++)
    {
        *pdata = * (pdata + 1);
        pdata++;
    }
}
//************************************************************************************
//函数名称：  ai_average_uint()
//功能描述：  cal average
//输入参数：  buf pointer
//输出参数：  average
//************************************************************************************
static uint ai_average_uint (uint *pdata, uchar len)
{
    uint  low_buf;
    uint  hi_buf;
    ulong sum_buf;
    uchar cnt_buf;
    uint  average_buf;
    uint  *p_buf;
    p_buf = pdata;
    low_buf = *p_buf;
    hi_buf  = *p_buf;

    for (cnt_buf = 0; cnt_buf < (len - 1); cnt_buf++) //find maxim and min number
    {
        p_buf++;

        if (low_buf > *p_buf)
        {
            low_buf = *p_buf;
        }

        if (hi_buf < *p_buf)
        {
            hi_buf = *p_buf;
        }
    }

    sum_buf = 0;
    p_buf = pdata;    //notice????

    for (cnt_buf = 0; cnt_buf < len; cnt_buf++) //sum
    {
        sum_buf += *p_buf++;
    }

    average_buf = ( (sum_buf - low_buf - hi_buf) / (len - 2) );
    return average_buf;
}
//************************************************************************************
//函数名称：  ai_pushdata_ulong()
//功能描述：  push data buf , abandon oldest
//输入参数：  buf pointer
//输出参数：
//************************************************************************************
static void ai_pushdata_long (long *pdata)
{
    uchar i;

    for (i = 0; i < (BUF_LEN - 1); i++)
    {
        *pdata = * (pdata + 1);
        pdata++;
    }
}
//************************************************************************************
//函数名称：  ai_average_ulong()
//功能描述：  cal average
//输入参数：  buf pointer
//输出参数：  average
//************************************************************************************
static long ai_average_long (long *pdata, uchar len)
{
    long  low_buf;
    long  hi_buf;
    long  sum_buf;
    uchar cnt_buf;
    long  average_buf;
    long  *p_buf;
    p_buf = pdata;
    low_buf = *p_buf;
    hi_buf = *p_buf;

    for (cnt_buf = 0; cnt_buf < (len - 1); cnt_buf++) //find maxim and min number
    {
        p_buf++;

        if (low_buf > *p_buf)
        {
            low_buf = *p_buf;
        }

        if (hi_buf < *p_buf)
        {
            hi_buf = *p_buf;
        }

        //pdata++;
    }

    sum_buf = 0;
    p_buf = pdata;    //notice????

    for (cnt_buf = 0; cnt_buf < len; cnt_buf++) //sum
    {
        sum_buf += *p_buf++;
    }

    average_buf = ( (sum_buf - low_buf - hi_buf) / (len - 2) );
    return average_buf;
}
//************************************************************************************
//函数名称：  ai_ui_process()
//功能描述：  hanle ad result of U I
//输入参数：  pointer to data buf, ad channel, real and image channel, modulus
//输出参数：  U or I real result
//************************************************************************************
uint ai_ui_process (uint *pdata, int *parrdata, uchar lx_ch, uint modulus)
{
    ai_pushdata_uint (pdata);
    pdata = (pdata + (BUF_LEN - 1) );
    *pdata = ai_cal_ui (parrdata, modulus, lx_ch); // anlog_average;
    pdata = (pdata - (BUF_LEN - 1) );
    return ( (ai_average_uint (pdata, BUF_LEN) + 5) / 10);
}
uint ai_ad_process (uint *pdata, uint data)
{
    ai_pushdata_uint (pdata);
    pdata = (pdata + (BUF_LEN - 1) );
    *pdata = data;
    pdata = (pdata - (BUF_LEN - 1) );
    return ai_average_uint (pdata, BUF_LEN);
}

//************************************************************************************
//函数名称：  ai_rpow_process()
//功能描述：  calculate real power
//输入参数：    pointer to array,
//                      channel of voltage
//                      channel of current
//                      modulus
//输出参数：
//************************************************************************************
static long ai_rpow_process (long *pdata, uchar chn_v, uchar chn_c)
{
    ai_pushdata_long (pdata);
    pdata = (pdata + (BUF_LEN - 1) );
    *pdata = PhaseR[chn_v] * PhaseR[chn_c] + PhaseI[chn_v] * PhaseI[chn_c];
    pdata = (pdata - (BUF_LEN - 1) );
    return ( (ai_average_long (pdata, BUF_LEN) ) / 1000);
}
//************************************************************************************
//函数名称：  ai_rpow_process()
//功能描述：  calculate real power
//输入参数：    pointer to array,
//                      channel of voltage
//                      channel of current
//                      modulus
//输出参数：
//************************************************************************************
static long ai_ipow_process (long *pdata, uchar chn_v, uchar chn_c)
{
    ai_pushdata_long (pdata);
    pdata = (pdata + (BUF_LEN - 1) );
    *pdata = ( (PhaseI[chn_v] * PhaseR[chn_c]) - (PhaseR[chn_v] * PhaseI[chn_c]) );
    pdata = (pdata - (BUF_LEN - 1) );
    return ( (ai_average_long (pdata, BUF_LEN) ) / 1000);
}
//************************************************************************************
//函数名称：  ai_pf_cal()
//功能描述：  caculate pf of every phase
//输入参数：
//输出参数：
//************************************************************************************
static sint ai_pf_cal (long data1, ulong data2)
{
    ulong buf;
    sint  buf1;

    if (data1 == data2)
    {
        return 100;
    }

    if (data1 < 0)
    {
        buf = -data1;
    }
    else
    {
        buf = data1;
    }

    buf1 = buf * 100 / data2;

    if (data1 < 0)
    {
        buf1 = -buf1;
    }

    return buf1;
}

//************************************************************************************
//函数名称：  ai_phse_cal()
//功能描述：  calculate phase sequence
//输入参数：
//输出参数：
//************************************************************************************
static uint ai_phse_cal (uchar lx_cnt)
{
    float buf;
    buf = sqrtf (PhaseI[lx_cnt] * PhaseI[lx_cnt] + PhaseR[lx_cnt] * PhaseR[lx_cnt]);
    buf = acosf (PhaseR[lx_cnt] / buf);

    if (PhaseI[lx_cnt] >= 0)
    {
        buf = buf / _M_PI * 180;
    }
    else
    {
        buf = 360 - buf / _M_PI * 180;
    }

    return buf;
}
//************************************************************************************
//函数名称：  ai_phse_cal1()
//功能描述：  calculate phase sequence
//输入参数：
//输出参数：
//************************************************************************************
static uint ai_phse_cal1 (uint angle1, uint angle2)
{
    if (angle2 >= angle1)
    {
        return (angle2 - angle1);
    }
    else
    {
        return (360 + angle2 - angle1);
    }
}





//************************************************************************************
//函数名称：  ai_ps_cal()
//功能描述：  calculate apparentpower
//输入参数：    real power , image power
//输出参数：    apparentpower
//************************************************************************************
static ulong ai_ps_cal (long buf1, long buf2)
{
    if (buf2 == 0)
    {
        return buf1;
    }
    else
    {
        return (sqrtf ((float)buf1 * (float)buf1 + (float)buf2 * (float)buf2) );
    }
}
//************************************************************************************
//函数名称：  ai_vi_process()
//功能描述：  calculate line voltage
//输入参数：    data buf, lx_cnt1, lx_cnt2
//输出参数：    line voltage
//************************************************************************************
static uint ai_vi_process (uint *pdata, uchar lx_cnt1, uchar lx_cnt2)
{
    float buf1;
    float buf2;
    uint tempdata;
    ai_pushdata_uint (pdata);
    buf1 = PhaseR[lx_cnt1] - PhaseR[lx_cnt2];
    buf2 = PhaseI[lx_cnt1] - PhaseI[lx_cnt2];
    pdata = (pdata + (BUF_LEN - 1) );
    tempdata = sqrtf (buf1 * buf1 + buf2 * buf2);

    if (tempdata < 10)
    {
        return 0;
    }

    *pdata = tempdata;
    pdata = (pdata - (BUF_LEN - 1) );
    return ( (ai_average_uint (pdata, BUF_LEN) + 5) / 10);
}
//************************************************************************************
//函数名称：  ai_process()
//功能描述：  do ad convert and handle ai result
//输入参数：
//输出参数：
//************************************************************************************

void ai_process (void)
{
    uchar i;
    long tempload;
    tempdata1 = 0;
    tempdata2 = 0;
    tempdata3 = 0;
    tempdata4 = 0;
    tempdata5 = 0;
    
    
    if (DEBUG_MODE == 1)
    {
        return;
    }





    #if B_MODE
    for(i=0;i<AI_NUM;i++)
    {
        AI_ADVALUE[i]=ai_ad_process(&AIBUFF[i][0],DataArrAI[i]/10)*ADJUST[i];
       
        if (AI_ADVALUE[i] > 4050)
        {
            AI_OHM[i] = -1;
        }
        else
        {
            AI_OHM[i] = (75000* AI_ADVALUE[i]) /  (4095 - AI_ADVALUE[i]) ;// * ADJUST2;
        } 
        
        DataArrAI[i]=0;  
           
    }
    #endif
    





     #if B_MODE
     if(AI_USEPOWERVOLT==0)
     {      
         PowerVoltage =(uint) ((ulong)ai_ad_process (BATTBUFF, AI_ADVALUE[AI_BV1_SELECT])*550/4096 * BATTFACT);     
         PowerVoltage2= (uint) ((ulong)ai_ad_process (BATTBUFF2, AI_ADVALUE[AI_BV2_SELECT])*550/4096 * CHARGEFACT);     
     }
     else
     {
         PowerVoltage =(uint) ((ulong)ai_ad_process (BATTBUFF, AI_ADVALUE[CHN_BATT])*550/4096 * ADJUST[CHN_BATT]); 
     }
     
     
     #else
     PowerVoltage =(uint) ((ulong)ai_ad_process (BATTBUFF, AI_ADVALUE[CHN_BATT]/32)*550/4096 * ADJUST[CHN_BATT]); 
     #endif
     
     if(PowerVoltage>10)
     {
         PowerVoltage +=6;
     }
     
    if(FUEL!=-32768)
    {      
        FUELCAP =(ulong)FUEL*(ulong)DES_RATING_FUELCAP/100;
    }
    else
    {    
         FUELCAP=-32768;
    }
   
  // #if FEIERTE_MODE
  //   ChargerVoltage = ai_ad_process (CHARGEBUFF, AI_ADVALUE[CHN_CHARGE]) / 32 * ADJUST[CHN_CHARGE] * 550 / 4096;
  
     //ChargerVoltage =(uint) ((ulong)ai_ad_process (CHARGEBUFF, AI_ADVALUE[CHN_CHARGE]/32)*550/4096 * ADJUST[CHN_BATT]);  
    // if(ChargerVoltage>10)
    // {
    //     ChargerVoltage+=6;
    // }
    // #else
    if (ECUMODE)
    {
        ChargerVoltage = ATMOP;
    }
    else
    {
       #if B_MODE
       ChargerVoltage =(uint) ((ulong)ai_ad_process (CHARGEBUFF, AI_ADVALUE[CHN_CHARGE])*550/4096 * ADJUST[CHN_BATT]);
       #else
       ChargerVoltage =(uint) ((ulong)ai_ad_process (CHARGEBUFF, AI_ADVALUE[CHN_CHARGE]/32)*550/4096 * ADJUST[CHN_BATT]);  
       #endif
       
        if(ChargerVoltage>10)
        {
            //ChargerVoltage+=6;
        }
    }
    //#endif
    
    
}

void hrdadc_init(void) 
{
  hrdCONFIG_ATD();
  atd_start();
}

void ai_check(void)
{
#if B_MODE
 if(FFTNUM>=10)
 {     
     ai_process();
     CalcSensor();
     PITTF_PTF2 = 1;
     
     atd_start();
     FFTNUM=0;     
 }
 
 if(FFTNUM==0 && PITINTE_PINTE2 ==0)
 {
     PITINTE_PINTE2 = 1;
 }
 #endif


  

}


float CalcCurve (int CurveType, float InputValue,int ADVALUE , char CurveMode)
{
    int *CurveAddr;
    int *NowAddr;
    char i = 0;
    float X1 = 0;
    float Y1 = 0;
    float X = 0;
    float Y = 0;
    float Err = 0;
       
    if (InputValue == -1)
    {
        return -32768;
    }
    InputValue=InputValue/100;
    if (CurveMode == 0)
    {
        switch (CurveType)
        {
        case 0:
            CurveAddr = &OIL_CURVE_VDO_5bar[0][0];
            break;
        case 1:
            CurveAddr = &OIL_CURVE_VDO_10bar[0][0];
            break;
        case 2:
            CurveAddr = &OIL_CURVE_Datcon_5bar[0][0];
            break;
        case 3:
            CurveAddr = &OIL_CURVE_Datcon_10bar[0][0];
            break;
        case 4:
            CurveAddr = &OIL_CURVE_Datcon_7bar[0][0];
            break;
        case 5:
            CurveAddr = &OIL_CURVE_Murphy_7bar[0][0];
            break;
        case 6:
            CurveAddr = &OIL_CURVE_CMB_812[0][0];
            break;
        case 7:
            CurveAddr = &OIL_CURVE_SGH_10bar[0][0];
            break;
        case 8:
            CurveAddr = &OIL_CURVE_Curtis[0][0];
            break;
        case 9:
            CurveAddr = &OIL_CURVE_SGD_10bar[0][0];
            break;
        case 10:
           

            if (ADVALUE >= 286 && ADVALUE < 410)
            {
                return 0;
            }

            if (ADVALUE < 286 || ADVALUE > 3685)
            {
                return -32768;
            }
            else
            {
                return 1000 * ((float)ADVALUE / 4096 * 5 - 0.5) / 4;
            }

            break;
        case 11:
            //CurveAddr = &OIL_CURVE_SCD_10bar[0][0];
            if(ADVALUE<819 && ADVALUE>800)
            {
                return 0;
            }
            
            if (ADVALUE <= 800)
            {
                return -32768;
            }
            else
            {
                return 30 * ((float)ADVALUE / 4096 * 5 - 1 ) / 4;
            }
            
            break;
        case 12:
            if(ADVALUE<819 && ADVALUE>800)
            {
                return 0;
            }
            
            if (ADVALUE <= 800)
            {
                return -32768;
            }
            else
            {
                return 1000 * ((float)ADVALUE / 4096 * 5 - 1 ) / 4;
            }
        break;    
            
        default:
            return -32768;    
        }

        //--------------------------------------
    }

    if (CurveMode == 1)
    {
        switch (CurveType)
        {
        case 0:
            CurveAddr = &TEMP_CURVE_Datcon_high[0][0];
            break;
        case 1:
            CurveAddr = &TEMP_CURVE_Datcon_low[0][0];
            break;
        case 2:
            CurveAddr = &TEMP_CURVE_Murphy[0][0];
            break;
        case 3:
            CurveAddr = &TEMP_CURVE_Cummins[0][0];
            break;
        case 4:
            CurveAddr = &TEMP_CURVE_SGH_120C[0][0];
            break;
        case 5:
            CurveAddr = &TEMP_CURVE_Curtis[0][0];
            break;
        case 6:
            CurveAddr = &TEMP_CURVE_SGD_120C[0][0];
            break;
        case 7:
            CurveAddr = &TEMP_CURVE_PT100[0][0];
            break;
        case 8:
            CurveAddr = &TEMP_CURVE_VDO_120C[0][0];
            break;
        case 9:
            CurveAddr = &TEMP_CURVE_PUSHENG[0][0];
            break;
        case 10:
            CurveAddr = &TEMP_CURVE_ST820JD[0][0];
            break;
            
        case 11:
            if(ADVALUE<819 && ADVALUE>800)
            {
                return 0;
            }
            
            if (ADVALUE <= 800)
            {
                return -32768;
            }
            else
            {
                return 750 * ((float)ADVALUE / 4096 * 5 - 1 ) / 4;
            }
             break;
            
        case 12:
            CurveAddr = &TEMP_CURVE_PT1000[0][0];
            break;
            
            default:
            return -32768;
        }
    }

    if (CurveMode == 2)
    {
        switch (CurveType)
        {
            //--------------------------------------
        case 0:
            CurveAddr = &FUEL_CURVE_VDO_Ohm_10_180[0][0];
            break;
        case 1:
            CurveAddr = &FUEL_CURVE_VDO_Tube_90_0[0][0];
            break;
        case 2:
            CurveAddr = &FUEL_CURVE_GM_Ohm_0_90[0][0];
            break;
        case 3:
            CurveAddr = &FUEL_CURVE_GM_Ohm_0_30[0][0];
            break;
        case 4:
            CurveAddr = &FUEL_CURVE_VDO_Ohm_10_180[0][0];
            break;
        case 5:
            CurveAddr = &FUEL_CURVE_Ford_73_10[0][0];
            break;
        case 6:
            CurveAddr = &FUEL_CURVE_NKZR_100_0[0][0];
            break;
        case 8:
            CurveAddr = &FUEL_CURVE_JS52026[0][0];
            break;
            default:
            return -32768;
        }
    }

    for (i = 2; i < 32; i += 2)
    {
        if (InputValue <= * (CurveAddr + i) )
        {
            NowAddr = CurveAddr + i;
            X1 = * (NowAddr);
            Y1 = * (NowAddr + 1);
            X = * (NowAddr - 2);
            Y = * (NowAddr - 1);
            Err = InputValue - * (NowAddr - 2);
            return (Y1 - Y) / (X1 - X) * Err + * (NowAddr - 1);
        }
    }

    return -32768;
};

void CalcSensor(void)
{
   
    int GENADVALUE;
    if(AI_ADVALUE[7]<3500)
    {
        DI_IDLE=1;
    }
    else
    {
        DI_IDLE=0;
    }
    
    #if B_MODE       
    GENADVALUE=AI_ADVALUE[AI_GENVOLT_SELECT]*GENVOLTFACT;
            if(GENADVALUE<819 && GENADVALUE>655)
            {
                GENVOLTAGE=0;
            }
            else
            if (GENADVALUE <= 655)
            {
                GENVOLTAGE= 0;
            }
            else
            {
                GENVOLTAGE= 400 * ((float)GENADVALUE / 4096 * 5 - 1 ) / 4;
            } 
            if(GENVOLTAGE<10 && GENVOLTAGE>0)
            {
                GENVOLTAGE=0;
            }
            
            
            
    if(MYTEST==0)
    {
      
    OILPRESSURE = CalcCurve (DES_SENSOR_OP,AI_OHM[AI_OP_SELECT],AI_ADVALUE[AI_OP_SELECT] , 0); //油压计算
    WATERTEMP   = CalcCurve (DES_SENSOR_WT, AI_OHM[AI_WT_SELECT],0, 1); //水温计算
    WTPRESSURE = CalcCurve (10,AI_OHM[AI_WP_SELECT],AI_ADVALUE[AI_WP_SELECT] , 0); //油压计算  
    OILPRESSURE1 = CalcCurve (DES_SENSOR_OP1,AI_OHM[AI_OP_SELECT1],AI_ADVALUE[AI_OP_SELECT1] , 0); //燃油压力计算  //@@@@ZC
    
    }
    #endif

    #if STANDARD_MODE || B_MODE    
    if (CalcCurve (DES_SENSOR_FUEL, AI_OHM[AI_LV_SELECT],0, 2) != -32768)
    {
        FUEL = CalcCurve (DES_SENSOR_FUEL, AI_OHM[AI_LV_SELECT],0, 2);
    }
    else
    {
        FUEL = -32768;    
    }    
    
    if (Params[141] == 7|| B_MODE)
    {
        OILTEMP = CalcCurve (DES_SENSOR_OT, AI_OHM[AI_OT_SELECT],0, 1);
    } 
    
    #endif
     
       
                  
 if (ECT_MCCTL_MCEN == 0 && FREQCOMP == 0)
    
    {
        //ECT_TIE = 0x00;
        FREQSET = 0;
        ECT_MCCTL_MCEN = 1;
        ECT_MCCNT = 25000;
        ECT_PACN10 = 0;
    }

    if (FREQCOMP >= 5)
    {
        //ECT_TIE = 0x00;
        ECT_MCCTL_MCEN = 0;
        ECT_MCCNT = 25000;                    
        FREQCOMP = 0;                                                                                             
        //ECT_TIE = 0x02;                    
        FreqArr[0] = (float) FREQCOUNT*2/1.0005;//转速修正
    }

    
    
}
               

void TransValue (void)
{
    unsigned long *tmpdata;
    unsigned long *tmpdata2;
    static LASTESTOP=0;
    if (DEBUG_MODE == 1)
    {
        return;
    }

    if (DI_ESTOP && LASTESTOP == 0)
    {
       // EPROM_ESTOP++, SaveParam (198,1);
    }
    LASTESTOP = DI_ESTOP;
   

  
    

    if(DES_SPEED<=0 && FreqArr[0]<5 && DO_START==0 && CHECKSPEEDERR)
    {
        TimerEnArr[TMR_SPEED_CHECK]=1;
        DO_SPEEDCHECK=1;
        if(TimerValue[TMR_SPEED_CHECK]>=10)
        {          
            BOUT_SPEEDSENSOR=0;
        }
    }
    else
    {
        DO_SPEEDCHECK=0;
        BOUT_SPEEDSENSOR=1;
        TimerEnArr[TMR_SPEED_CHECK]=0;
        TimerTrig[TMR_SPEED_CHECK]=0;
        SpeedError=0;
    }

    if(TimerTrig[TMR_SPEED_CHECK])    
    {
        TimerTrig[TMR_SPEED_CHECK]=0;
        if(SPEEDADVALUE>SPEEDAD && FreqArr[0]<5)
        {
            SpeedError=1;
        }
        else
        {
            SpeedError=0;
            BOUT_SPEEDSENSOR=1;
        }    
    }

    if (FEIERTE_MODE==0 && ECUMODE==0)
    {
        if (DES_ROTATIONSCALE > 0)
        {
            if(MYTEST==0)
            {
                DES_SPEED   = FreqArr[0]*60/DES_ROTATIONSCALE; //RPM计算
            }
            
            
            
            if(SpeedError)
            {
                DES_SPEED=-32768;
            }
            //DES_SPEED=(float)MPTEST*6/DES_ROTATIONSCALE;
        }
        else
        {
            if (VOLTAGEA1 > 5 && VOLTAGEB1 > 5 && VOLTAGEC1 > 5)
            {
                DES_SPEED   = FreqArr[2] * 30;
            }
            else
            {
                DES_SPEED = 0;
            }
        }
                         
    }
     
    if (ECUMODE == 1)
    {
   //     COILTEMP =   CalcCurve (9, AI_R2, 1);
    }
  
  
    if(MPCHECKED==1)
    {        
  //      FREQ_MP = (long)65535*(long)ovf_buf[2]+ (long)temp_buf_mp - (long)freq_pre_buf[2];
  //      ovf_buf[2] = 0;
  //      MPCHECKED=0;
  //      ECT_TIE_C0I=1;
    }
    
    RUNNINGHOUR = RUNHOUR;
    RUNNINGMINUTE = RUNMINUTE;
    RUNNINGTIME = RUNTIME;
    ESTOPNUM = EPROM_ESTOP;
    KWHH=EPROM_KWHH;
    KWHL=EPROM_KWHL;
    KVARHH=EPROM_KVARHH;
    KVARHL=EPROM_KVARHL;

}