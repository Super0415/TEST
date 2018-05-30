#include "extern.h"
#include "hidef.h"      /* common defines and macros */
#include "MC9S12XET256.h"     /* derivative information */
#include "string.h"
#include "defs.h"
#include "lcd.h"
#include "io.h"
#include "main.h"
#include "MCU_init.h"
#include "alloc.h"
#include "btn.h"
#include "lcdfont.h"
PRIVATE uint  btn_buf_pre;
PRIVATE uchar btn_cnt;
PRIVATE uint timevalue;
PRIVATE uchar timetick;
PRIVATE char changestep;
PRIVATE long LimitH;
PRIVATE long LimitL;
uchar DATEMAX;
uchar MONTHMAX;
uchar YEARMAX;


//PUBLIC unsigned char const ParamType[150];
//************************************************************************************
//函数名称：  btn_process()
//功能描述：  process buttons
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void CheckDate (uchar month)
{
    MONTHMAX = 12;
    YEARMAX = 99;

    switch (month)
    {
    case 1:
        DATEMAX = 31;
        break;
    case 2:

        if (tmpyear % 4 == 0)
        {
            DATEMAX = 29;
        }
        else
        {
            DATEMAX = 28;
        }

        break;
    case 3:
        DATEMAX = 31;
        break;
    case 5:
        DATEMAX = 31;
        break;
    case 7:
        DATEMAX = 31;
        break;
    case 8:
        DATEMAX = 31;
        break;
    case 10:
        DATEMAX = 31;
        break;
    case 12:
        DATEMAX = 31;
        break;
    default:
        DATEMAX = 30;
        break;
    }
}

PRIVATE void DateADD (uint STEP, uchar DIRECTION)
{
    CheckDate (tmpmonth);

    if (DIRECTION == 0)
    {
        if (STEP == 1 || STEP == 2)
        {
            if (tmpdate > 1)
            {
                tmpdate--;
            }
            else
            {
                if (tmpmonth > 1)
                {
                    tmpmonth--;
                    CheckDate (tmpmonth);
                }
                else
                {
                    tmpmonth = 12;

                    if (tmpyear > 1)
                    {
                        tmpyear--;
                    }
                }

                tmpdate = DATEMAX;
            }
        }

        if (STEP == 5 || STEP == 10)
        {
            if (tmpmonth > 1)
            {
                tmpmonth--;
            }
            else
            {
                tmpmonth = 12;

                if (tmpyear > 1)
                {
                    tmpyear--;
                }
            }
        }

        if (STEP == 50 || STEP == 100)
        {
            if (tmpyear > 1)
            {
                tmpyear--;
            }
        }
    }
    else
    {
        if (STEP == 1 || STEP == 2)
        {
            if (tmpdate < DATEMAX)
            {
                tmpdate++;
            }
            else
            {
                tmpdate = 1;

                if (tmpmonth < MONTHMAX)
                {
                    tmpmonth++;
                }
                else
                {
                    tmpmonth = 1;

                    if (tmpyear < YEARMAX)
                    {
                        tmpyear++;
                    }
                }
            }
        }

        if (STEP == 5 || STEP == 10)
        {
            if (tmpmonth < MONTHMAX)
            {
                tmpmonth++;
            }
            else
            {
                tmpmonth = 1;

                if (tmpyear < YEARMAX)
                {
                    tmpyear++;
                }
            }
        }

        if (STEP == 50 || STEP == 100)
        {
            if (tmpyear < YEARMAX)
            {
                tmpyear++;
            }
        }
    }
}

PUBLIC void btn_process (void)
{
    uchar alanum=0;
    uchar i=0;
    static uchar lasttest;
    if ((lcd_disp_mode == 1 && lcd_disp_ParamMode == 2)||lcd_passwordlevel2)
    {
        if (F_BTN_PAGE_UP == 0 && F_BTN_PAGE_DOWN == 0)
        {
            timevalue = 0, changestep = 1, timetick = 0;
        }

        if (F_BTN_PAGE_UP || F_BTN_PAGE_DOWN)
        {
            timevalue++;
            timetick++;
            if(lcd_passwordlevel2)
            {
              lcd_disp_ParamNum=0;
              LimitH=9999;
              LimitL=0;
            }
            if (timetick >= 100)
            {
                if (F_BTN_PAGE_UP)
                {
                    if (TmpParam < LimitH - changestep)
                    {
                        TmpParam += changestep;

                        if (lcd_disp_ParamNum == 108)
                        {
                            TmpParam = 0;

                            if (tmpminute + changestep >= 60)
                            {
                                tmpminute = 0, tmphour++;
                            }
                            else
                            {
                                tmpminute += changestep;
                            }

                            if (tmphour >= 24)
                            {
                                tmphour = 0;
                            }
                        }

                        if (lcd_disp_ParamNum == 109)
                        {
                           
                            DateADD (changestep, 1);
                        }
                    }
                    else
                    {
                        TmpParam = LimitL;
                    }
                }
                else
                {
                    if (TmpParam > LimitL + changestep)
                    {
                        TmpParam -= changestep;

                        if (lcd_disp_ParamNum == 108)
                        {
                            TmpParam = 0;

                            if (tmpminute - changestep <= 0)
                            {
                                tmpminute = 0, tmphour--;
                            }
                            else
                            {
                                tmpminute -= changestep;
                            }

                            if (tmphour <= 0)
                            {
                                tmphour = 23;
                            }
                        }

                        if (lcd_disp_ParamNum == 109)
                        {
                             
                            DateADD (changestep, 0);
                        }
                    }
                    else
                    {
                        TmpParam = LimitH;
                    }
                }

                timetick = 0;
            }

            if (timevalue > 100 && timevalue < 300)
            {
                changestep = 2;
            }

            if (timevalue > 300 && timevalue < 500)
            {
                changestep = 5;
            }

            if (timevalue > 500 && timevalue < 700)
            {
                changestep = 10;
            }

            if (timevalue > 700 && timevalue < 900)
            {
                changestep = 50;
            }

            if (timevalue >= 1000)
            {
                timevalue = 1000, changestep = 100;
            }
        }
    }


    if (btn_buf != btn_buf_pre)
    {
        if (btn_cnt >= 2)
        {
            STANDBYTIME = 0;

            switch (btn_buf)
            {
            case MASK_BTN_ON_OFF_EN:  //市电合闸
                FLAG_BTNMCB = 1;
                F_BTN_ON_OFF_EN = 1;
                break;
            case MASK_BTN_ON_OFF_GE:    //发电合闸
                FLAG_BTNGCB = 1;
                F_BTN_ON_OFF_GE = 1;
                break;
            case MASK_BTN_PAGE_UP:    //向上翻页

                if (lcd_disp_mode == 1 && lcd_disp_ParamMode == 0&&lcd_passwordlevel2==0)
                {
                    if (lcd_disp_cursor_setup > 1)
                    {
                        lcd_disp_cursor_setup--;
                    }

                    if (lcd_disp_point_setup > 1)
                    {
                        lcd_disp_point_setup--;
                    }

                    lcd_disp_point_submenu = 1;
                    lcd_disp_cursor_submenu = 1;
                }
                


                if (lcd_disp_mode == 1 && lcd_disp_ParamMode == 1)
                {
                    if (lcd_disp_cursor_submenu > 1)
                    {
                        lcd_disp_cursor_submenu--;
                    }

                    if (lcd_disp_point_submenu > 1)
                    {
                        lcd_disp_point_submenu--;
                    }
                }

                if (lcd_disp_mode == 0)
                {
                    if(NowPage==PAGEALARM && ALARMPAGE>0)
                    {

                        ALARMPAGE--;   
                    
                    }
                    else if (NowPage != 20)
                    {
                        do
                        {
                            if (NowPage > 1)
                            {
                                NowPage--;
                            }
                            else
                            {
                                NowPage = PageShow.PageNums;
                            }
                        }
                        while (PageShow.Pages[NowPage-1]->Disable == 1);
                    }
                    else
                    {
                        LngCursor = 0;
                    }
                }

                if ((lcd_disp_mode == 1 && lcd_disp_ParamMode == 2)||lcd_passwordlevel2) //子菜单修改模式
                {
                    if(lcd_passwordlevel2)
                    {
                        lcd_disp_ParamNum=0;
                        LimitH=9999;
                        LimitL=0;
                    }
                    if (TmpParam < LimitH)
                    {
                        TmpParam++;

                        if (lcd_disp_ParamNum == 108)
                        {
                            tmpminute++;
                            TmpParam = 0;

                            if (tmpminute >= 60)
                            {
                                tmpminute = 0, tmphour++;
                            }

                            if (tmphour >= 24)
                            {
                                tmphour = 0;
                            }
                        }

                        if (lcd_disp_ParamNum == 109)
                        {
                            DateADD (1, 1);
                        }
                    }
                    else
                    {
                        TmpParam = LimitL;
                    }
                }

                if (lcd_disp_mode == 2)
                {
                    if (lcd_disp_recmode == 0)
                    {
                        RECPT--;
                    }

                    if (RECPT < 0)
                    {
                        RECPT = 59;
                    }

                    if (lcd_disp_recmode)
                    {
                        if (lcd_disp_recpage > 0)
                        {
                            lcd_disp_recpage--;
                        }
                    }
                }

                F_CLR_LCD           = 1;
                F_BTN_PAGE_UP   = 1;
                break;
            case MASK_BTN_PAGE_ENTER:
                NowPage = 20;
                btn_buf = 0xFFFF;
                F_BTN_ENTER = 1;
                F_BTN_PAGE = 1;
                break;
            case MASK_BTN_LEFT_RIGHT:
                if(lcd_disp_mode==0)
                {                   
                    SelfTestMode=1;                    
                }
                
                btn_buf = 0xFFFF;
                F_BTN_MODE_LEFT = 1;
                F_BTN_MODE_RIGHT = 1;
                
                break;
            
            
            
            case MASK_BTN_PAGE:       //PAGE按键
                F_CLR_LCD           = 1;
                F_BTN_PAGE      = 1;
                
                if(lcd_passwordlevel2)
                {
                    lcd_passwordlevel2=0;
                    break;
                }
                if(ConfirmMode)
                {
                    ConfirmMode=0;
                    break;
                }
                if (lcd_disp_mode == 2 && lcd_disp_recmode == 1)
                {
                    lcd_disp_recmode = 0;
                }
                else
                {
                    if (lcd_disp_ParamMode == 0)
                    {
                        lcd_disp_mode++;
                    }
                    else  if (lcd_disp_ParamMode > 0)
                    {
                        lcd_disp_ParamMode--;
                    }
                }

                if (NowPage == 20)
                {
                    NowPage = 1;
                    lcd_disp_mode=0;
                }
                
                if(lcd_disp_mode==3)
                {
                    NowPage = 1;
                    lcd_disp_mode=0;
                }
                

                lcd_state     = lcd_display;
                break;
            case MASK_BTN_PAGE_DOWN:  //向下翻页

                if (lcd_disp_mode == 1 && lcd_disp_ParamMode == 0 && lcd_passwordlevel2==0)
                {
                    if (lcd_disp_cursor_setup < 5)
                    {
                        lcd_disp_cursor_setup++;
                    }

                    if (lcd_disp_point_setup < MAINMENU.MENUNUM)
                    {
                        lcd_disp_point_setup++;
                    }

                    lcd_disp_point_submenu = 1;
                    lcd_disp_cursor_submenu = 1;
                }

                if (lcd_disp_mode == 1 && lcd_disp_ParamMode == 1)
                {
                    if (lcd_disp_cursor_submenu < 2)
                    {
                        lcd_disp_cursor_submenu++;
                    }

                    if (lcd_disp_point_submenu < MAINMENU.SubPtr[lcd_disp_point_setup-1]->MaxItem)
                    {
                        lcd_disp_point_submenu++;
                    }
                }

                if (lcd_disp_mode == 0)
                {
                    
                    if(NowPage==PAGEALARM&& ALARMPAGE+1<=(ALARMNUMS-1)/4 )
                    {

                        ALARMPAGE++;   
                        if(ALARMPAGE> ALARMNUMS/4)
                        {
                            ALARMPAGE= ALARMNUMS/4;
                        }                     
                    }
                    else if (NowPage != 20)
                    {
                        do
                        {
                            if (NowPage < PageShow.PageNums)
                            {
                                NowPage++;
                            }
                            else
                            {
                                NowPage = 1;
                            }
                        }
                        while (PageShow.Pages[NowPage-1]->Disable  == 1);
                    }

                    else
                    {
                        LngCursor = 1;
                    }
                }

                if ((lcd_disp_mode == 1 && lcd_disp_ParamMode == 2)||lcd_passwordlevel2)
                {
                    if(lcd_passwordlevel2)                    
                    {
                        lcd_disp_ParamNum=0;
                        LimitH=9999;
                        LimitL=0;
                    }                    
                    if (TmpParam > LimitL)
                    {
                        TmpParam--;

                        if (lcd_disp_ParamNum == 108)
                        {
                            tmpminute--;
                            TmpParam = 0;

                            if (tmpminute <= 0)
                            {
                                tmpminute = 59, tmphour--;
                            }

                            if (tmphour <= 0)
                            {
                                tmphour = 23;
                            }
                        }

                        if (lcd_disp_ParamNum == 109)
                        {
                            DateADD (1, 0);
                        }
                    }
                    else
                    {
                        TmpParam = LimitH;
                    }
                }

                if (lcd_disp_mode == 2)
                {
                    if (lcd_disp_recmode == 0)
                    {
                        RECPT++;
                    }

                    if (RECPT >= 60)
                    {
                        RECPT = 0;
                    }

                    if (lcd_disp_recmode)
                    {
                        if (lcd_disp_recpage < 2)
                        {
                            lcd_disp_recpage++;
                        }
                    }
                }

                F_CLR_LCD           = 1;
                F_BTN_PAGE_DOWN = 1;
                break;
            case MASK_BTN_START:      //启动按钮
                //FLAG_BTNSTART = 1;
                if(NowMode==1 && ParamValue[13]==0)
                {                  
                    ConfirmMode = 1;
                    CONFIRM_DEL=5;
                    cnt_1000ms=0;
                }
                F_BTN_START     = 1;
                break;
            case MASK_BTN_FAULT_RESET://复位
                FLAG_BTNRESET = 1;
                if(SelfTestMode)
                {                  
                    F_BTN_SELFTEST_SDNOUT=0;
                    F_BTN_SELFTEST_SDOUT=0;
                    SelfTestTimer=0;
                    TestPhase=0;
                    SelfTestMode=0;
                    NowPage=1;
                    SciWriteParam (TESTPHASE, &NOWPHASE, 1);
                }
                ECUSTATUS &= 0xFE;
                FLG_ECUSTAT.Byte &= 0xFE;
                F_BTN_FAULT_RESET = 1;
                break;
            case MASK_BTN_STOP:       //停机按钮
                if(NowMode==1)
                {
                    
                    if(STA_DES_PREHEAT||STA_DES_CRANKING||STA_DES_STARTINT||ConfirmMode==1)
                    {                        
                        ConfirmMode=0;
                        FLAG_BTNSTOP=1;
                    }
                    else
                    {
                      
                        ConfirmMode=2;
                        CONFIRM_DEL=5;
                        cnt_1000ms=0;
                    }
                    //FLAG_BTNSTOP=1;
                }
                
                
                F_BTN_STOP  = 1;
                break;
            case MASK_BTN_ENTER:      //回车按钮

                if(lcd_passwordlevel2)
                {
                    if(TmpParam==5)
                    {
                        if(lcd_disp_ParamMode==1)
                        {
                            TmpParam=0;
                            LimitH=1;
                            LimitL=0;
                            lcd_disp_ParamMode=2;
                        }
                        else
                        {                          
                            lcd_disp_ParamMode=1;
                        }
                        lcd_passwordlevel2=0;
                        ENSETUP=1;
                        lcd_state     = lcd_display;                        
                    }
                    else
                    {
                        lcd_passwordlevel2=0;
                        lcd_state     = lcd_display;
                    }
                    break;
                }
                
                if(ConfirmMode==1)
                {
                    ConfirmMode=0;
                    FLAG_BTNSTART=1;
                    lcd_state     = lcd_display;
                    F_CLR_LCD   = 1;
                    F_BTN_ENTER = 1;
                    break;
                }
                
                if(ConfirmMode==2)
                {
                    ConfirmMode=0;
                    FLAG_BTNSTOP=1;
                    lcd_state     = lcd_display;
                    F_CLR_LCD   = 1;
                    F_BTN_ENTER = 1;
                    break;
                }
                
                if (lcd_disp_ParamMode == 0 && NowPage == 20)
                {
                    SciWriteParam (124, &LngCursor, 1);
                    ParamValue[124] = LngCursor;
                    NowPage = 1;
                }

                if (lcd_disp_ParamMode == 1 && lcd_disp_ParamConfirm == 0)
                {
                    if (lcd_disp_ParamNum == 203)
                    {
                        if (TEMPMODE == 1)
                        {
                            TmpParam = (int) ECUDATANUMBER;
                        }
                        else
                        {
                            if(lcd_disp_cursor_submenu==1)            //@@@@ZC  读取数据
                            {                                       //基本设置 2                         //内部菜单            1-同一界面上一条 2-下一跳
                                TmpParam=ParamValue[MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->ValueOffset];                                
                            }
                            else
                            {
                                TmpParam=ParamValue[MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->ValueOffset];                                 
                            }
                           // TmpParam = (uint) ParamValue[lcd_disp_ParamNum-1];
                        }
                    }
                    else
                    {
                        if (lcd_disp_ParamNum != 0)                        
                        {
                            if(lcd_disp_cursor_submenu==1)
                            {          
                                TmpParam=ParamValue[MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->ValueOffset];                                
                                LimitH=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->MaxValue;
                                LimitL=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->MinValue;
                            }
                            else
                            {
                                TmpParam=ParamValue[MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->ValueOffset];                                 
                                LimitH=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->MaxValue;
                                LimitL=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->MinValue;                           
                            }
                           // TmpParam = ParamValue[lcd_disp_ParamNum-1];
                        }
                        else
                        {
                            TmpParam = 0;
                            LimitH=9999;
                        }
                    }

                    tmpminute = TIMESET_MINUTE;
                    tmphour   = TIMESET_HOUR;
                    tmpdate   = TIMESET_DATE;
                    tmpmonth  = TIMESET_MONTH;
                    tmpyear   = TIMESET_YEAR;
                }

                if (lcd_disp_mode == 1)
                {
                    if (lcd_disp_ParamMode < 2)
                    {
                        
                        if(lcd_disp_ParamMode==1 && MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-1]->ValueOffset==2)
                        {
                            lcd_passwordlevel2=1;
                            break;
                        }
                        if ((lcd_disp_point_setup!=5 &&lcd_disp_point_setup!=6 &&lcd_disp_point_setup!=7 &&lcd_disp_point_setup!=8 || lcd_disp_ParamMode==1) && ENSETUP || (ENSETUP == 0 && lcd_disp_ParamMode == 0) || (lcd_disp_ParamMode == 1 && lcd_disp_ParamNum == 0) )
                        {
                            lcd_disp_ParamMode++;
                        }
                        else
                        {
                            lcd_passwordlevel2=1;
                            TmpParam=0;
                        }
                        
                        /*
                        if (ECUSTATUS & 0x01 == 1)
                        {
                            if (ENSETUP || (ENSETUP == 0 && lcd_disp_ParamMode == 0) || (lcd_disp_ParamMode == 1 && lcd_disp_ParamNum == 0) )
                            {
                                lcd_disp_ParamMode++;
                            }
                        }
                        else
                        {
                            if (ENSETUP || (ENSETUP == 0 && lcd_disp_ParamMode == 0) || (lcd_disp_ParamMode == 1 && lcd_disp_ParamNum == 0) )
                            {
                                lcd_disp_ParamMode++;
                            }
                        }
                        */
                    }
                    else if (lcd_disp_ParamMode == 2)
                    {
                        lcd_disp_ParamMode = 1;

                        if (lcd_disp_ParamNum == 0)
                        {
                            PASSWORD = TmpParam;
                        }
                        else
                        {
                            lcd_disp_ParamConfirm = 1;
                        }
                    }
                }

                //将临时参数从游标处取出
                if (lcd_disp_mode == 2 && lcd_disp_recmode == 0)
                {
                    lcd_disp_recmode = 1;
                }

                lcd_state     = lcd_display;
                F_CLR_LCD   = 1;
                F_BTN_ENTER = 1;
                break;
            case MASK_BTN_HORN_RESET: //消音
                FLAG_BTNMUTE = 1;
                //ALACONFIRM[0] = 1;
                //ALACONFIRM[1] = 1;
                //ALACONFIRM[2] = 1;
                //ALACONFIRM[3] = 1;
                F_BTN_HORN_RESET = 1;
                break;
            case MASK_BTN_MODE_LEFT:  //模式左
                if(NowPage==1)
                {                  
                    if (NowMode > 0)
                    { 
                        NowMode--;
                    }

                    EnChangeMode = 0;
                    ModeLock = 0;
                }
                
                F_BTN_MODE_LEFT  = 1;
                break;
                
            case MASK_BTN_MODE_RIGHT:  //模式右
                if(NowPage==1)
                {   
                    #if FEIERTE_MODE|| GEC16P_MODE
                    if (NowMode < 2)
                    #else           
                    if (NowMode < 3)
                    #endif
                    {
                        NowMode++;
                    }

                    EnChangeMode = 0;
                    ModeLock = 0;
                }
                F_BTN_MODE_RIGHT = 1;
                break;
                
            default:
                break;
            }
        }

        btn_buf_pre = btn_buf;
    }
    else
    {
        btn_cnt++;
        btn_buf   = 0xffff;
    }

    /*
            }
      else
      {

      NowPage=20;
      btn_buf_pre = btn_buf;

      }
      */
}
