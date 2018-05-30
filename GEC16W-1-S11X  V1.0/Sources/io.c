#include <hidef.h>      /* common defines and macros */
#include <MC9S12XS128.h>
#include "extern.h"
#include "defs.h"
#include "MCU_init.h"
#include "main.h"
#include "lcd.h"
#include "btn.h"
#include "alloc.h"
#include "io.h"
//#pragma CODE_SEG DEFAULT
#pragma DATA_SEG DEFAULT


//************************************************************************************
//函数名称：  ai_pushdata_uint()
//功能描述：  push data buf , abandon oldest
//输入参数：  buf pointer
//输出参数：
//************************************************************************************
static void ai_pushdata_uint (uint *pdata, uchar len)
{
    uchar i;

    for (i = 0; i < len; i++)
    {
        *pdata = * (pdata + 1);
        pdata++;
    }
}

//************************************************************************************
//函数名称：  io_refresh()
//功能描述：  refresh io
//输入参数：
//输出参数：
//************************************************************************************

static void alarm_check (uint NOWALA, uint PREALA, uchar STRINGNAME)
{
    uchar i;

   
    
    if (NOWALA == 0)
    {
        for (i = 0; i < 10; i++)
        {
            if (ALAWINDOW[i] == STRINGNAME)
            {
                ALAWINDOW[i] = 0;
                //ALACONFIRM[i] = 1;
            }
        }
    }

    if (NOWALA > 0)
    {
        ai_pushdata_uint (ALAWINDOW, 10);
        ai_pushdata_uint (ALACONFIRM, 10);

        if (PREALA == 0)
        {
            ai_pushdata_uint (&RECWINDOW[1], 9);
            EnREC++;
            RECWINDOW[9] = STRINGNAME;
            lcd_disp_mode = 0;
            lcd_disp_ParamMode=0;            
            
            if (NowPage != PAGEALARM)
            {
                NowPage = PAGEALARM;
            }
             
            lcd_state     = lcd_display;
        }

        ALAWINDOW[9] = STRINGNAME;
        ALACONFIRM[9] = 0;
    }


}

//************************************************************************************
//函数名称：  status_check()
//功能描述：  refresh io
//输入参数：
//输出参数：
//************************************************************************************
PUBLIC void status_check (void)
{
    uchar i;
    FLAGSTR8 TEMPLEDBYTE;
    uchar num;
    num=0;
    
    if (initnum < 180)
    {
#if GECMODE25
        LED3 = 0;
        LED5 = 0;
        LED6 = 0;
#endif
        LED1 = 0;
        LED2 = 0;
        LED4 = 1;
        return;
    }

    TEMPLEDBYTE.Byte = LEDBYTE & 0xFF;
#if GECMODE16

    if (TEMPLEDBYTE.BITS.bit0)
    {
        if (TEMPLEDBYTE.BITS.bit6)
        {
            if (SPLASH)
            {
                LED1 = 0;
            }
            else
            {
                LED1 = 1;
            }
        }
        else
        {
            LED1 = 0;
        }
    }
    else
    {
        LED1 = 1;
    }

    if (TEMPLEDBYTE.BITS.bit1)
    {
        LED2 = 0;
    }
    else
    {
        LED2 = 1;
    }

    if (TEMPLEDBYTE.BITS.bit2)
    {
        LED4 = 1;
    }
    else
    {
        LED4 = 0;
    }

    LED3 = 1;
    LED5 = 1;
    LED6 = 1;
#endif
#if GECMODE25

    if (TEMPLEDBYTE.BITS.bit0)
    {
        if (TEMPLEDBYTE.BITS.bit6)
        {
            if (SPLASH)
            {
                LED6 = 0;
            }
            else
            {
                LED6 = 1;
            }
        }
        else
        {
            LED6 = 0;
        }
    }
    else
    {
        LED6 = 1;
    }

    if (TEMPLEDBYTE.BITS.bit1)
    {
        LED5 = 0;
    }
    else
    {
        LED5 = 1;
    }

    if (TEMPLEDBYTE.BITS.bit2)
    {
        LED4 = 1;
    }
    else
    {
        LED4 = 0;
    }

    if (TEMPLEDBYTE.BITS.bit3)
    {
        LED3 = 0;
    }
    else
    {
        LED3 = 1;
    }

    if (TEMPLEDBYTE.BITS.bit4)
    {
        LED2 = 0;
    }
    else
    {
        LED2 = 1;
    }

    //if(LEDBYTE&0x20)LED6=0;else LED6=1;
    if (TEMPLEDBYTE.BITS.bit5)
    {
        if (TEMPLEDBYTE.BITS.bit7)
        {
            if (SPLASH)
            {
                LED1 = 0;
            }
            else
            {
                LED1 = 1;
            }
        }
        else
        {
            LED1 = 0;
        }
    }
    else
    {
        LED1 = 1;
    }

#endif
    GetMode = COMMON_STATUS & 0x0F;

    //if(RETURNFLAG && CHECKFLAG)NowMode=GetMode;
    if (EnChangeMode)
    {
        NowMode = GetMode;
    }

    FLG_ALA1.Byte = DES_ALA_DATA1;
    FLG_ALA2.Byte = DES_ALA_DATA2;
    FLG_ALA3.Byte = GEN_ALA_DATA1;
    FLG_ALA4.Byte = MAIN_ALA_DATA1;
    FLG_STAT.Byte = COMMON_STATUS2;
    FLG_ECUSTAT.Byte = ECUSTATUS;
    FLG_ECUSTAT2.Byte = ECUSTATUS2;

    for (i = 0; i < 10; i++)
    {
        ALAWINDOW[i] = 0;
        ALACONFIRM[i] = 0;
    }

    alarm_check (ALA_SPEED_LOW_PRE,   LASTFLAG1.Bits.bit8, ALASHOW_LOWSPEEDPRE);
    alarm_check (ALA_SPEED_HIGH_PRE,  LASTFLAG1.Bits.bit9, ALASHOW_HIGHSPEEDPRE);
    alarm_check (ALA_SPEED_LOW_STOP,  LASTFLAG1.Bits.bita, ALASHOW_LOWSPEEDALA);
    alarm_check (ALA_SPEED_HIGH_STOP, LASTFLAG1.Bits.bitb, ALASHOW_HIGHSPEEDALA);
    if(ParamValue[16]==1)    
    {
      alarm_check (ALA_TEMP_HIGH_STOP,  LASTFLAG1.Bits.bitd, ALASHOW_HIGHWTTEMPALA);
    }
    else
    {
      alarm_check (ALA_TEMP_HIGH_STOP,  LASTFLAG1.Bits.bitd, ALASHOW_HIGHWTTEMPALA);
    }
    alarm_check (ALA_TEMP_HIGH_PRE,   LASTFLAG1.Bits.bitc, ALASHOW_HIGHWTTEMPPRE);
    
    
    alarm_check (ALA_OP_LOW_PRE,      LASTFLAG1.Bits.bite, ALASHOW_LOWOPPRE);
    if(ParamValue[16]==1)    
    {
      alarm_check (ALA_OP_LOW_STOP,     LASTFLAG1.Bits.bitf, ALASHOW_LOWOPALA_EM);
    }
    else
    {
      alarm_check (ALA_OP_LOW_STOP,     LASTFLAG1.Bits.bitf, ALASHOW_LOWOPALA);
    }
    
    alarm_check (ALA_BATT_LOW_ALA,    LASTFLAG1.Bits.bit0, ALASHOW_BATTLOW);
    alarm_check (ALA_BATT_HIGH_ALA,   LASTFLAG1.Bits.bit1, ALASHOW_BATTHIGH);
    alarm_check (ALA_FUEL_LOW_PRE,    LASTFLAG1.Bits.bit2, ALASHOW_LOWFUELPRE);
    alarm_check (ALA_FUEL_LOW_ALA,    LASTFLAG1.Bits.bit3, ALASHOW_LOWFUELALA);
    alarm_check (ALA_START_FAIL,      LASTFLAG1.Bits.bit4, ALASHOW_STARTFAIL);
    alarm_check (ALA_STOP_FAIL,       LASTFLAG1.Bits.bit5, ALASHOW_STOPFAIL);
    
    if(ParamValue[16]==1)    
    {
        alarm_check (ALA_OILTEMP_STOP,    LASTFLAG1.Bits.bit6, ALASHOW_HIGHOILTEMP_EM);
    }
    else
    {
        alarm_check (ALA_OILTEMP_STOP,    LASTFLAG1.Bits.bit6, ALASHOW_HIGHOILTEMP);
    }
        
    alarm_check (ALA_LOSTOIL,         LASTFLAG1.Bits.bit7, ALASHOW_LEAKFUEL);
    alarm_check (ALA_OPERR,           LASTFLAG2.Bits.bit8, ALASHOW_OPERR);
    alarm_check (ALA_WTERR,           LASTFLAG2.Bits.bit9, ALASHOW_WTERR);
    alarm_check (ALA_OTERR,           LASTFLAG2.Bits.bita, ALASHOW_OTERR);
    alarm_check (ALA_COILTEMP,        LASTFLAG2.Bits.bitb, ALASHOW_COILTEMP);
    alarm_check (ALA_OILTEMP_PRE,     LASTFLAG2.Bits.bitc, ALASHOW_OILTEMP_PRE);
    alarm_check (ALA_ESTOP,           LASTFLAG2.Bits.bitd, ALASHOW_ESTOP);
    alarm_check (ALA_POWERHIPRE,      LASTFLAG2.Bits.bite, ALASHOW_POWERHIPRE);
    alarm_check (ALA_POWERHI,         LASTFLAG2.Bits.bitf, ALASHOW_POWERHI);
    alarm_check (ALA_GEN_SHORT,       LASTFLAG3.Bits.bit0, ALASHOW_GEN_SHORT);
    alarm_check (ALA_GEN_CURRENT_NB,  LASTFLAG3.Bits.bit1, ALASHOW_GEN_CURRENT_NB);
    alarm_check (ALA_GEN_VOLTAGE_NB,  LASTFLAG3.Bits.bit2, ALASHOW_GEN_VOLTAGE_NB);
    alarm_check (ALA_COILTEMP2,       LASTFLAG3.Bits.bit3, ALASHOW_COILTEMP2);
    alarm_check (ALA_GENLEAK,         LASTFLAG3.Bits.bit4, ALASHOW_GENLEAK);
    alarm_check (ALA_SPRINGINPUT,     LASTFLAG3.Bits.bit5, ALASHOW_SPRINGINPUT);   
    alarm_check (ALA_COOLINGFAN ,     LASTFLAG3.Bits.bit6, ALASHOW_COOLINGFAN);   
    alarm_check (ALA_WATERPLOW ,      LASTFLAG3.Bits.bit7, ALASHOW_WATERPLOW);   
     
    alarm_check (ALA_GEN_OVER_VOLTAGE, LASTFLAG3.Bits.bit8, ALASHOW_GEN_HIVOLTAGE);
    alarm_check (ALA_GEN_LOW_VOLTAGE, LASTFLAG3.Bits.bit9, ALASHOW_GEN_LOWVOLTAGE);
    alarm_check (ALA_GEN_OVER_FREQ,   LASTFLAG3.Bits.bita, ALASHOW_GEN_HIFREQ);
    alarm_check (ALA_GEN_LOW_FREQ,    LASTFLAG3.Bits.bitb, ALASHOW_GEN_LOWFREQ);
    alarm_check (ALA_GEN_HIGH_CURRENT, LASTFLAG3.Bits.bitc, ALASHOW_HICURRENT);
    alarm_check (ALA_GEN_ACBFAULT,    LASTFLAG3.Bits.bitd, ALASHOW_ACBFAULT);
    alarm_check (ALA_GEN_REVPOWER,    LASTFLAG3.Bits.bite, ALASHOW_REVPOWER);
    alarm_check (ALA_GEN_LOSTPHASE,   LASTFLAG3.Bits.bitf, ALASHOW_LOSTPHASE);
    //alarm_check (ALA_BUS_OVER_VOLTAGE, LASTFLAG4.Bits.bit8, ALASHOW_BUS_HIVOLTAGE);
    //alarm_check (ALA_BUS_LOW_VOLTAGE, LASTFLAG4.Bits.bit9, ALASHOW_BUS_LOWVOLTAGE);
    //alarm_check (ALA_BUS_OVER_FREQ,   LASTFLAG4.Bits.bita, ALASHOW_BUS_HIFREQ);
    //alarm_check (ALA_BUS_LOW_FREQ,    LASTFLAG4.Bits.bitb, ALASHOW_BUS_LOWFREQ);
    
    alarm_check (ALA_BUS_OVER_VOLTAGE, LASTFLAG4.Bits.bit8, ALASHOW_SAFE_OPLOW);
    alarm_check (ALA_BUS_LOW_VOLTAGE,  LASTFLAG4.Bits.bit9, ALASHOW_SAFE_WTHI);
    alarm_check (ALA_BUS_OVER_FREQ,    LASTFLAG4.Bits.bita, ALASHOW_SAFE_OTHI);
    alarm_check (ALA_BUS_LOW_FREQ,     LASTFLAG4.Bits.bitb, ALASHOW_SAFE_SPDHI);
    alarm_check (STA_BUS_NORMAL,     LASTFLAG4.Bits.bitc, ALASHOW_BATTLOW2);
    alarm_check (ALA_BUS_VOLTAGE_NB,  LASTFLAG4.Bits.bitd, ALASHOW_BUS_VOLTAGE_NB);
    alarm_check (ALA_DPLUSFAIL,       LASTFLAG4.Bits.bite, ALASHOW_DPLUSFAIL);
    alarm_check (ALA_M_POWER_HI,       LASTFLAG4.Bits.bitf, ALASHOW_BATTHIGH2);
    
    
    
    alarm_check (ECU_PUMPFAULT,       LASTFLAG6.Bits.bit0, ALASHOW_PUMPFAULT);
    alarm_check (ECU_OILCHOCK,        LASTFLAG6.Bits.bit1, ALASHOW_OILCHOCK);
    alarm_check (ECU_AIRCHOCK,        LASTFLAG6.Bits.bit2, ALASHOW_AIRCHOCK);
    alarm_check (ECU_FUELCHOCK,       LASTFLAG6.Bits.bit3, ALASHOW_FUELCHOCK);
    alarm_check (ECU_DOORERR,         LASTFLAG6.Bits.bit4, ALASHOW_DOORERR);
    alarm_check (ECU_DESOIL_LEVEL,    LASTFLAG6.Bits.bit5, ALASHOW_DESOIL_LEVEL);
    alarm_check (ECU_FUELERR_UP,      LASTFLAG6.Bits.bit6, ALASHOW_FUELERR_UP);
    alarm_check (ECU_FUELERR_DOWN,    LASTFLAG6.Bits.bit7, ALASHOW_FUELERR_DOWN);
    alarm_check (ECU_PUMPFAULT2,      LASTFLAG7.Bits.bit8, ALASHOW_PUMPFAULT2);
    alarm_check (ALA_POWERFAIL,       LASTFLAG7.Bits.bit9, ALASHOW_POWERFAIL);
    alarm_check (ALA_LOWLEVEL ,       LASTFLAG7.Bits.bita, ALASHOW_LOWLEVEL);
    alarm_check (ALA_PS_MAINTAIN ,    LASTFLAG7.Bits.bitb, ALASHOW_PS_MAINTAIN);
    alarm_check (ALA_PS_OIL_LOW_PRE , LASTFLAG7.Bits.bitc, ALASHOW_PS_OIL_LOW_PRE);
    alarm_check (ALA_PS_OIL_LOW_ALA , LASTFLAG7.Bits.bitd, ALASHOW_PS_OIL_LOW_ALA);
    
    
     for(i=0;i<10;i++)
    {
        if(ALAWINDOW[i]>0)
        {
            num++;
        }                                                        
    }    
    
    ALARMNUMS =num;
    
    if(ALARMPAGE>(ALARMNUMS-1)/4)
    {
       ALARMPAGE=0;
    }
    
    //if(STA_BUS_NORMAL==1) STA_BUS_NORMAL=0;else STA_BUS_NORMAL=1;
    //alarm_check(STA_BUS_NORMAL,      LASTFLAG4.Bits.bitc,ALASHOW_BUS_NORMAL);
    LASTFLAG1.Byte = FLG_ALA1.Byte;
    LASTFLAG2.Byte = FLG_ALA2.Byte;
    LASTFLAG3.Byte = FLG_ALA3.Byte;
    LASTFLAG4.Byte = FLG_ALA4.Byte;
    LASTFLAG5.Byte = FLG_STAT.Byte;
    LASTFLAG6.Byte = FLG_ECUSTAT.Byte;
    LASTFLAG7.Byte = FLG_ECUSTAT2.Byte;

    for (i = 0; i < 10; i++)
    {
        if (ALAWINDOW[i] == 0)
        {
            ALACONFIRM[i] = 1;
        }
    }
}

//************************************************************************************
//函数名称：  status_check()
//功能描述：  refresh io
//输入参数：
//输出参数：
//************************************************************************************
PUBLIC void io_refresh (void)
{
    if (BTN_ON_OFF_EN == 0)
    {
        btn_buf = MASK_BTN_ON_OFF_EN;
    }
    else
    {
        F_BTN_ON_OFF_EN = 0;
    }

    if (BTN_ON_OFF_GE == 0)
    {
        btn_buf = MASK_BTN_ON_OFF_GE;
    }
    else
    {
        F_BTN_ON_OFF_GE = 0;
    }

    if (BTN_PAGE_UP == 0)
    {
        btn_buf = MASK_BTN_PAGE_UP;
    }
    else
    {
        F_BTN_PAGE_UP = 0;
    }

    if (BTN_PAGE == 0)
    {
        if (F_BTN_PAGE == 0)
        {
            btn_buf = MASK_BTN_PAGE;
        }
    }
    else
    {
        F_BTN_PAGE = 0;
    }

    if (BTN_PAGE_DOWN == 0)
    {
        btn_buf = MASK_BTN_PAGE_DOWN;
    }
    else
    {
        F_BTN_PAGE_DOWN = 0;
    }

    if (BTN_START == 0)
    {
        btn_buf = MASK_BTN_START;
        BTNSTART_FLAG=1;
    }
    else
    {
        F_BTN_START = 0;
        BTNSTART_FLAG=0;
    }
    
    

    if (BTN_FAULT_RESET == 0)
    {
        btn_buf = MASK_BTN_FAULT_RESET;
    }
    else
    {
        F_BTN_FAULT_RESET = 0;
    }

    if (BTN_STOP == 0)
    {
        btn_buf = MASK_BTN_STOP;
    }
    else
    {
        F_BTN_STOP = 0;
    }

    if (BTN_ENTER == 0)
    {
        if (F_BTN_ENTER == 0)
        {
            btn_buf = MASK_BTN_ENTER;
        }
    }
    else
    {
        F_BTN_ENTER = 0;
    }

    if (BTN_HORN_RESET == 0)
    {
        btn_buf = MASK_BTN_HORN_RESET;
    }
    else
    {
        F_BTN_HORN_RESET = 0;
    }

    if (BTN_MODE_LEFT == 0)
    {
        btn_buf = MASK_BTN_MODE_LEFT;
    }
    else
    {
        F_BTN_MODE_LEFT = 0;
    }

    if (BTN_MODE_RIGHT == 0)
    {
        btn_buf = MASK_BTN_MODE_RIGHT;
    }
    else
    {
        F_BTN_MODE_RIGHT = 0;
    }

    if (BTN_PAGE == 0 && BTN_ENTER == 0)
    {
        btn_buf = MASK_BTN_PAGE_ENTER;
    }
    else
    {
        F_BTN_PAGE_ENTER = 0;
    }
    
    if (BTN_MODE_LEFT == 0 && BTN_MODE_RIGHT == 0)
    {
        btn_buf = MASK_BTN_LEFT_RIGHT;
    }
    else
    {
        F_BTN_LEFT_RIGHT = 0;
    }
    
    
}

