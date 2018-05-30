#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <MC9S12XS128.h>
#pragma LINK_INFO DERIVATIVE "mc9s12xs128"
#include <string.h>
#include "extern.h"
#include "defs.h"
#include "MCU_init.h"
#include "btn.h"
#include "lcd.h"
#include "io.h"
#include "alloc.h"
#include "main.h"
#include "sci.h"
#include "lcdfont.h"

#pragma CODE_SEG __NEAR_SEG NON_BANKED
#define BUS_FRE       40000000
PRIVATE uchar cnt_5ms   = 1;
PRIVATE uchar cnt_10ms  = 2;
PRIVATE uchar cnt_20ms  = 4;
PRIVATE uchar cnt_50ms  = 6;
PRIVATE uchar cnt_100ms = 8;
PRIVATE uchar cnt_200ms = 10;
PRIVATE uint  cnt_500ms = 12;

PRIVATE uchar F_1000MS=0;
PRIVATE uchar timeout = 0;
PRIVATE uint SENDSTATUS = 0;
uchar initnum = 0;
volatile unsigned int ReadStart;
volatile unsigned int ReadLength;
uchar lngtime=0;

void main (void)
{
    uint LASTPT;
    uint sendtime;
    uchar i;
    static readrec=0;
    static OilPreSign=0;
    DisableInterrupts;
    MCU_init();
    (void) SCIOpenCommunication (0);
    EnableInterrupts;
    for (;;)
    {
        static uchar startflg;
        if (SAVEPASSWORD == PASSWORD || SAVEPASSWORD == 0)
        {
            ENSETUP = 1;
        }
        else
        {
            ENSETUP = 0;
        }

        if (lcd_disp_mode != 1)
        {
            PASSWORD = 0;
        }

        if (F_5MS)
        {
            F_5MS = 0;
            io_refresh();
            btn_process();
        }

        if (F_10MS)
        {
            SCIProcess();
            F_10MS = 0;
        }

        if (F_20MS)
        {
            F_20MS = 0;
        }

        if (F_50MS)
        {
            status_check();
            F_50MS = 0;
        }

        if (F_100MS)
        {
            ChangeLng (LNG);
            CheckMenu();                                   //菜单刷新
            #if FEIERTE_MODE
            if(ParamValue[PNUM_AMF_ENABLE]==1)
            {
            PAGE_DIS[4]=0;
            PageShow.Pages[4]->Disable=0;
            }
            else
            {
            PAGE_DIS[4]=1;
            PageShow.Pages[4]->Disable=1;
            }
            #endif
            
            if(NowMode==1)
            {                          
                if(startflg==0 && BTNSTART_FLAG)
                {                
                    FLAG_BTNGCB=1;
                }
                if(BTNSTART_FLAG==0 && startflg)
                {
                    FLAG_BTNMCB=1;
                }
                startflg=BTNSTART_FLAG; 
            }
            
       
            
            
            

            if (SENDFLAG)
            {
                timeout++;
            }
            else
            {
                timeout = 0;
            }

            if (timeout > 5)
            {
                timeout = 0, SENDFLAG = 0;    //,RETURNFLAG=1;
            }

            if (initnum < 180 && RETURNFLAG == 0 && SENDFLAG == 0)
            {
                SciReadValue (initnum + 200, 30), initnum += 30, CHECKFLAG = 0;
                EnChangeMode = 0;
                ModeLock = 0;
            }

            if (initnum > PNUM_MODESAVE && RETURNFLAG == 1 && INIT == 0)
            {
                NowMode = ParamValue[PNUM_MODESAVE], INIT = 1;
            }

            if (lcd_disp_ParamConfirm == 0 && SENDFLAG == 0 && RETURNFLAG == 0)
            {
                if (EnREC > 0)
                {
                    RECWINDOW[0] = EnREC, SciWriteParam (210, &RECWINDOW[0], 10), EnREC = 0;
                }
            }

            if (RETURNFLAG == 0 && SENDFLAG == 0 && lcd_disp_ParamConfirm == 0)
            {
                if (GetMode != NowMode || BTNFLAG.Byte != 0)
                {
                    SENDSTATUS = NowMode;
                    SENDSTATUS <<= 8;
                    SENDSTATUS |= BTNFLAG.Byte;
                    SciWriteParam (PNUM_STATUS, &SENDSTATUS, 1);
                    BTNFLAG.Byte = 0;
                    COMMON_STATUS = (COMMON_STATUS & 0xF0) | NowMode;
                }

                if (RECREAD)
                {
                    SciWriteParam (REC_POINTER, &RECPT, 1);
                    RECREAD = 0;
                    //readrec=0;
                }
            }

            if (RECPT != LASTPT)
            {
                RECREAD = 1;
            }

            
            if(RECPT!=RECDATA1 && lcd_disp_mode==2 && readrec==0) 
            {
                RECPT=RECDATA1;
                readrec=1;
            }
            
            
            
            
            if(lcd_disp_mode!=2)
            {
                 readrec=0;
            }
            
            LASTPT = RECPT;

            if (RETURNFLAG == 0 && SENDFLAG == 0 && lcd_disp_ParamConfirm == 0)
            {
                if (CHECKFLAG == 0)
                {
                    if (lcd_disp_mode == 0)
                    {
                       // if(ConfirmMode)
                       // {
                       //     NowPage=1;
                       // }
                        switch (NowPage)
                        {
                        case PAGEMAIN:
                            SciReadValue (0, 29);
                     
                            break;
                        case 2:
                            SciReadValue (6, 22);
                            break;
                        case 3:
                            SciReadValue (12, 3);
                            break;
                        case PAGECOIL:
                            SciReadValue (26,4);
                            break;
                        case PAGEDES:
                            if(!OilPreSign) 
                            {
                              SciReadValue (1, 50);   
                              OilPreSign = 1;
                            } 
                            else
                            {
                              SciReadValue (115, 10);     //此处读取燃油压力
                              OilPreSign = 1;
                            }
                            break;

                        case 6:
                            SciReadValue (0, 21);
                            break;


                        case 7:
                            SciReadValue (381, 5);
                            break;
                        case 8:
                            SciReadValue (386, 2);
                            break;
                        case 9:
                            SciReadValue (388, 5);
                            break;
                        case 10:
                            SciReadValue (393, 2);
                            break;
                        case 11:
                            SciReadValue (15, 28);
                            break;    
  
                        
                        case 12:
                            SciReadValue (46, 8);
                            break;
                        case 13:
                            SciReadValue (46, 9);
                            break;
                        case 14:
                            SciReadValue (101, 10);
                            break;
                        case 15:
                            SciReadValue (19, 26);
                            break;
                        case 21:
                            
                            SciWriteParam (TESTPHASE, &NOWPHASE, 1);
                            break;    
                        }
                    }

                    if (lcd_disp_mode == 1 && lcd_disp_ParamMode > 0 && lcd_disp_ParamConfirm == 0)
                    {
                        if (lcd_disp_cursor_submenu == 1)
                        {
                            if (lcd_disp_ParamNum >= 106 && lcd_disp_ParamNum <= 111)
                            {
                                SciReadValue (204 + 200, 6);
                            }
                            else
                            {
                                SciReadValue (lcd_disp_ParamNum + 200, 2);
                            }
                        }
                        else
                        {
                            if (lcd_disp_ParamNum >= 106 && lcd_disp_ParamNum <= 111)
                            {
                                SciReadValue (204 + 200, 6);
                            }
                            else
                            {
                                SciReadValue (lcd_disp_ParamNum + 199, 2);
                            }
                        }
                    }

                    if (lcd_disp_mode == 1 && lcd_disp_ParamMode == 0 && lcd_disp_ParamConfirm == 0)
                    {
                        SciReadValue (101, 11);
                    }

                    if (lcd_disp_mode == 2)
                    {
                        SciReadValue (60, 35);
                    }
                }

                if (CHECKFLAG == 1)
                {
                    SciReadValue (101, 11);
                }
            }

            lcd_state();

            if (RETURNFLAG == 1)
            {
                SENDFLAG = 0;
                RETURNFLAG = 0;
                timeout = 4;

                if (CHECKFLAG == 0)
                {
                    CHECKFLAG = 1;
                }
                else
                {
                    CHECKFLAG = 0;
                }
            }
            


            F_100MS = 0;
        }

        if (F_200MS)
        
        {   
            if(SplashIcon<4)
            {          
                SplashIcon++;
                if(SplashIcon>=3)
                {
                SplashIcon=0;
                }
            }

            F_200MS = 0;
        }

        if (F_500MS)
        {
            if(NowPage==20)
            {
                lngtime++;
                if(lngtime>=20)
                {
                    NowPage=1;
                }
            }
            else
            {
                lngtime=0;
            }
            if(SelfTestMode)
            {
                SelfTestTimer++;
            }
            if (EnChangeMode == 0)
            {
                ModeLock++;

                if (ModeLock > 2)
                {
                    ModeLock = 0;
                    EnChangeMode = 1;
                }
            }

            if (STANDBYTIME < 240 && lcd_disp_mode != 0)
            {
                STANDBYTIME++;
            }

            if (STANDBYTIME >= 240)
            {
                lcd_disp_mode = 0;
                NowPage = 1;
                STANDBYTIME = 0;
                lcd_disp_ParamMode = 0;
                lcd_state = lcd_display;
            }

            if (SPLASH)
            {
                SPLASH = 0;
            }
            else
            {
                SPLASH = 1;
            }

            F_500MS = 0;
        }
        
        if(F_1000MS)
        {
            if(CONFIRM_DEL>0)
            {
                CONFIRM_DEL-=1;
            }
            else
            {
                ConfirmMode=0;
            }
         
            
            F_1000MS=0;
        }
        
    }
}
#pragma CODE_SEG MY_INTERRUPT
void interrupt 20 SCI0_int (void)
{
    RXcomplete = 0;

    while (SCI0SR2_RAF)
    {
        if (SCI0SR1_RDRF)
        {
            ReceiveBuff[NowChar] = SCI0DRL;
            NowChar++;
        }
    }

    if (NowChar > 0)
    {
        LastNum = NowChar;
        NowChar = 0;
        RXcomplete = 1;
        MODBUS_CHECK = 0;
    }
}


void interrupt 66 pit0_int (void)
{
    PITTF_PTF0 = 1;
    cnt_5ms++;
    cnt_10ms++;
    cnt_20ms++;
    cnt_50ms++;
    cnt_100ms++;
    cnt_200ms++;
    cnt_500ms++;
    cnt_1000ms++;
    if (cnt_5ms  >= MASK_5MS)
    {
        F_5MS     = 1;
        cnt_5ms   = 0;
    }

    if (cnt_10ms >= MASK_10MS)
    {
        F_10MS    = 1;
        cnt_10ms  = 0;
    }

    if (cnt_20ms >= MASK_20MS)
    {
        F_20MS    = 1;
        cnt_20ms  = 0;
    }

    if (cnt_50ms >= MASK_50MS)
    {
        F_50MS    = 1;
        cnt_50ms  = 0;
    }

    if (cnt_100ms >= MASK_100MS)
    {
        F_100MS   = 1;
        cnt_100ms = 0;
    }

    if (cnt_200ms >= MASK_200MS)
    {
        F_200MS   = 1;
        cnt_200ms = 0;
    }

    if (cnt_500ms >= MASK_500MS)
    {
        F_500MS    = 1;
        cnt_500ms  = 0;
    }
    if (cnt_1000ms >= MASK_1000MS)
    {
        F_1000MS    = 1;
        cnt_1000ms  = 0;
    }
}

