#include "btn.h"

#include "mscan12.h"
PRIVATE STRFLG8 BTNVALUE;
//PRIVATE STRFLG16 TMPFLG;

uchar DI_BTN_FAULTRESET_MASK;
void ButtonProcess (void) //按键处理
{
    if (DI_BTN_FAULTRESET == 0)
    {
        DI_BTN_FAULTRESET_MASK = 0;
    }
    TMPFLG.Byte = Params[PNUM_STAT];
    
    //if (TMPFLG.BYTES.BYTEL)
    //{
    //CANSND1DFRM (0x0000000AUL, (uchar *)&TMPFLG.Byte, 2, 1);
    //}
    if (DEBUG_MODE)
    {
        BTNVALUE.Byte |= FORCEBTN & 0xFF;
    }

    BTNVALUE.Byte |= TMPFLG.BYTES.BYTEL;



    if (DEBUG_MODE)
    {
        NowMode = FORCEMODE;
        ForceMode (NowMode);
    }
    else
    {
        NowMode = TMPFLG.BYTES.BYTEH;
    }

/*
#if WCZJ_MODE

    if(DI_MODE_AUTO==0 && DI_MODE_REMOTE==0)
    {
    ForceMode(1);
    }
    if(DI_MODE_REMOTE)
    {
    BTNVALUE.Byte=0;
    }

#endif
*/

    if (NowMode > 3)
    {
        NowMode = 3;
    }
    COMMON_STATUS &= 0xFF00;
    COMMON_STATUS |= TMPFLG.BYTES.BYTEH;
    Params[PNUM_STAT] &= 0xFF00;
    TMPFLG.BYTES.BYTEL = DESALA.Byte;
    TMPFLG.BYTES.BYTEH = DESALA2.Byte;
    DES_ALA_DATA1 = TMPFLG.Byte;
    DES_ALA_DATA2 = DESALA3.Byte;
    TMPFLG.BYTES.BYTEL = GENALA.Byte;
    TMPFLG.BYTES.BYTEH = GENALA2.Byte;
    GEN_ALA_DATA1 = TMPFLG.Byte;
    MAIN_ALA_DATA1 = BUSALA.Byte;
    TMPFLG.BYTES.BYTEL = DES_STATUS.Byte;
    TMPFLG.BYTES.BYTEH = DES_STATUS2.Byte;
    COMMON_STATUS2 = TMPFLG.Byte; //GEN_STATUS.Byte*256;
    TMPFLG.Byte = 0;
    ECUSTATUS &= 0xFF;
    TMPFLG.BYTES.BYTEH = HWALA.Byte;
    ECUSTATUS |= TMPFLG.Byte;
    TMPFLG.Byte = 0;
    TMPFLG.BYTES.BYTEL = HWALA2.Byte;
    ECUSTATUS2 = TMPFLG.Byte;
    
    //模式：0-关 1-手动 2-自动 3-远程
    
    if(BTN_STARTHOLD && BTN_STARTRELEASE)
    {
        BTN_STARTHOLD=0;
        BTN_STARTRELEASE=0;
        if(STA_DES_SELFTEST==0)
        {
            STA_DES_SELFTEST=1;
        }
        else
        {
            STA_DES_SELFTEST=0;
        }
    }
    
    if(NowMode==3)
    {      
        BTN_START|=DI_BTN_START;
        BTN_STOP|=DI_BTN_STOP;
    }
    
    
    if ((ECUMODE && HW_MODE))
    {
        ECUSTATUS |= 1;
    }
    else
    {
        ECUSTATUS &= 0xFFFE;
    }

    if (BTN_STOP)
    {
        if (NowMode==1 || (NowMode == 3 && DI_BTN_STOP)||NowMode==3)
        {
            STA_DES_ENSTART = 0;
            STA_DES_ENSTOP = 1;

            if (STA_DES_CRANKING == 1)
            {
                DO_START = 0;
                DO_FUEL = 0;
            }

            STA_DES_CRANKING = 0;
            TimerEnArr[TMR_START_PULSE] = 0;
            if (NowMode == 3)
            {
                TimerEnArr[TMR_STOP_IDLE_DELAY]=1;
                TimerTrig[TMR_STOP_IDLE_DELAY] = 1;
            }
        }

    }
    if (BTN_START)
    {
        if ((NowMode ==1 && MANSTART_MODE==0)||(NowMode == 3 && DI_BTN_START)||NowMode==3)
        {

            STA_DES_ENSTART = 1;            
            if (TimerTrig[TMR_START_IDLE_DELAY] == 1)
            {
                TimerTrig[TMR_START_IDLE_DELAY] = 1;
            }

        }
    }
    if(BTN_SELFTEST_SDOUT)
    {
        SELF_TEST_BUZZER=1;
        
    }
    
    if(BTN_SELFTEST_SDNOUT)
    {
        SELF_TEST_BUZZER=0;
    } 
    
    if(BTN_STARTHOLD)
    {
       MANSTART_FLAG=1;
    }
    if(BTN_STARTRELEASE)
    {
       MANSTART_FLAG=0;
    }
    
   /*
    if (BTN_GCB_SWITCH)
    {
        if (NowMode == 1)
        {
            if (DI_GCB == 0 && DI_MCB == 0 && DO_GCB == 0 && STA_GEN_RUNNING)
            {
                TimerEnArr[TMR_GEN_GCB_DELAY] = 1;
            }
            else
            {
                TimerEnArr[TMR_GEN_GCB_DELAY] = 0, GCBPULSEOFF;
            }


        }
    }

    if (BTN_MCB_SWITCH)
    {
    #if GECMODE25
        if (NowMode == 1)
        {
            if (DI_MCB == 0 && DI_GCB == 0 && DO_MCB == 0 && STA_BUS_NORMAL)
            {
                TimerEnArr[TMR_BUS_MCB_DELAY] = 1;
            }
            else
            {
                TimerEnArr[TMR_BUS_MCB_DELAY] = 0;
            }
        }
    #endif
    }
       */
    if (BTN_HORN_RESET)        //消音按钮
    {
        NOBUZZER = 1;        
        FUEL_RATE = 0;
    }

    if (BTN_FAULT_RESET || DI_BTN_FAULTRESET)    //复位按钮
    {

        NOBUZZER = 0;
        if (BTN_FAULT_RESET || (DI_BTN_FAULTRESET && DI_BTN_FAULTRESET_MASK == 0) )
        {
            ResetProcess();
        }
        if (DI_BTN_FAULTRESET)
        {
            DI_BTN_FAULTRESET_MASK = 1;
        }

    }

    BTNVALUE.Byte = 0;
    FORCEBTN = 0;

}
