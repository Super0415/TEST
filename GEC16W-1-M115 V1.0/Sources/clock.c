#include "clock.h"

uchar DATEVALUE[7];

 unsigned  char Get_Day (unsigned  char year, unsigned char month, unsigned  char date)
{
    //根据年月日换算出星期
    unsigned char day;
    unsigned int  temp;
    unsigned char century;
    century = 20;

    if (month < 3)
    {
        month += 12;

        if (year == 0)
        {
            year = 99;
            century --;
        }
        else
        {
            year --;
        }
    }

    temp = (month + 1) * 26;
    temp = temp / 10;
    temp += year;
    temp += (year >> 2);
    temp += (century >> 2);
    temp -= (century << 1);
    temp += date;
    temp --;
    day = temp % 7;

    if (day == 0)
    {
        day = 7;
    }

    return day;
}

void IIC_read_time (unsigned char *addr)
{
    unsigned char i;
    BCDFLG tmp;
    static ENI2C=1;
    unsigned int DOG = 0;
    IIC0_IBCR_IBEN=1;
    //if(ENI2C==0) return;
    IIC0_IBCR_TXAK = 0; // TXAK = 0;
    IIC0_IBCR |= 0x30; // RX/TX = 1; MS/SL = 1; TXAK = 0;
    // And generate START condition;
    //IIC0_IBCR_TXAK = 1; // acknowledge disable;
    IIC0_IBDR = 0xD0; // Address the slave and set up for master transmit;
    DOG=0;
    while (!IIC0_IBSR_IBIF)
    {
        DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;
            ENI2C=0;
            return; // generate stop signal;
        }
    }; // wait until IBIF;

    DOG = 0;

    IIC0_IBSR_IBIF = 1; // clear the interrupt event flag;
    
    while (IIC0_IBSR_RXAK)
    {
        DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;
            ENI2C=0;
            return; // generate stop signal;
        }
    };// check for RXAK;

    //-----Slave ACK occurred------------
    IIC0_IBDR = 0; // Send high byte of word address;
    DOG=0;
    while (!IIC0_IBSR_IBIF)
    {
            DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;
            ENI2C=0;
            return; // generate stop signal;
        }
    }; // wait until IBIF;

    IIC0_IBSR_IBIF = 1; // clear the interrupt event flag;
    DOG=0;
    while (IIC0_IBSR_RXAK); // check for RXAK;
        {
            DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;
            ENI2C=0;
            return; // generate stop signal;
        }
    }; // wait until IBIF;
    //-----Slave ACK occurred------------
    IIC0_IBCR_RSTA = 1; // set up repeated start;
    IIC0_IBDR = 0xD1; // Send low byte of word address;
    DOG=0;
    while (!IIC0_IBSR_IBIF); // wait until IBIF;
        {
            DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;
            ENI2C=0;
            return; // generate stop signal;
        }
    }; // wait until IBIF;

    IIC0_IBSR_IBIF = 1; // clear the interrupt event flag;
    DOG=0;
    while (IIC0_IBSR_RXAK); // check for RXAK;
        {
            DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;
            ENI2C=0;
            return; // generate stop signal;
        }
    }; // wait until IBIF;
    //-----Slave ACK occurred------------
    IIC0_IBCR_TX_RX = 0; // set up to receive;
    //IIC0_IBCR_TXAK = 1; // acknowledge disable;

    for (i = 0; i < 7; i++)
    {
        if (i == 6)
        {
            IIC0_IBCR_TXAK = 1;    // acknowledge disable;
            
        }

        tmp.Byte = IIC0_IBDR; // dummy read;
        DOG=0;
        while (!IIC0_IBSR_IBIF); // wait until IBIF;
        {
            DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;
            ENI2C=0;
            return; // generate stop signal;
        }
    }; // wait until IBIF;
        IIC0_IBSR_IBIF = 1; // clear the interrupt event flag;

        if (i == 6)
        {
            IIC0_IBCR_MS_SL = 0;    // generate stop signal;
        }

        * (addr + i) = IIC0_IBDR; // read right data;
        tmp.Byte = * (addr + i);
        * (addr + i) = tmp.BITS4.L4 + tmp.BITS4.H4 * 10;
    }
}


void IIC_write_time (unsigned char YEAR, unsigned char MONTH, unsigned char DATE, unsigned char HOUR, unsigned char MINUTE)
{
    BCDFLG tmp;
    unsigned int DOG = 0;
    unsigned char DAY;
    DAY = Get_Day (YEAR, MONTH, DATE);
    IIC0_IBCR_IBEN=1;
    IIC0_IBCR_TXAK = 0; // TXAK = 0;
    IIC0_IBCR |= 0x30; // RX/TX = 1; MS/SL = 1; TXAK = 0;
    // And generate START condition;
    IIC0_IBDR = 0xD0; // Address the slave and set up for master transmit;
    DOG=0;
    while (!IIC0_IBSR_IBIF); // wait until IBIF;
        {
            DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;

            return; // generate stop signal;
        }
    }; // wait until IBIF;
    IIC0_IBSR_IBIF = 1; // clear the interrupt event flag;
   DOG=0;
    while (IIC0_IBSR_RXAK)
    {
        DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;
            return; // generate stop signal;
        }
    }; // check for RXAK;

    //-----Slave ACK occurred------------
    IIC0_IBDR = 1; // Send high byte of word address;
    DOG=0;
    while (!IIC0_IBSR_IBIF); // wait until IBIF;
        {
            DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;
 
            return; // generate stop signal;
        }
    }; // wait until IBIF;
    IIC0_IBSR_IBIF = 1; // clear the interrupt event flag;
    DOG=0;
    while (IIC0_IBSR_RXAK); // check for RXAK;
        {
            DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;

            return; // generate stop signal;
        }
    }; // wait until IBIF;
    //-----Slave ACK occurred------------
    tmp.BITS4.L4 = MINUTE % 10;
    tmp.BITS4.H4 = MINUTE / 10;
    IIC0_IBDR = tmp.Byte; // Send high byte of word address;
    DOG=0;
    while (!IIC0_IBSR_IBIF); // wait until IBIF;
        {
            DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;

            return; // generate stop signal;
        }
    }; // wait until IBIF;
    IIC0_IBSR_IBIF = 1; // clear the interrupt event flag;
    DOG=0;
    while (IIC0_IBSR_RXAK); // check for RXAK;
        {
            DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;

            return; // generate stop signal;
        }
    }; // wait until IBIF;
    //-----Slave ACK occurred------------
    tmp.BITS4.L4 = HOUR % 10;
    tmp.BITS4.H4 = HOUR / 10;
    IIC0_IBDR = tmp.Byte; // Send high byte of word address;
     DOG=0;
    while (!IIC0_IBSR_IBIF); // wait until IBIF;
        {
            DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;
 
            return; // generate stop signal;
        }
    }; // wait until IBIF;
    IIC0_IBSR_IBIF = 1; // clear the interrupt event flag;
    DOG=0;
    while (IIC0_IBSR_RXAK); // check for RXAK;
        {
        DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;

            return; // generate stop signal;
        }
    }; // wait until IBIF;
    //-----Slave ACK occurred------------
    tmp.BITS4.L4 = DAY;
    tmp.BITS4.H4 = 0;
    IIC0_IBDR = tmp.Byte; // Send high byte of word address;
    DOG=0;
    while (!IIC0_IBSR_IBIF); // wait until IBIF;
    {
        DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;

            return; // generate stop signal;
        }
    }; // wait until IBIF;
    IIC0_IBSR_IBIF = 1; // clear the interrupt event flag;
    DOG=0;
    while (IIC0_IBSR_RXAK); // check for RXAK;
    {
        DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;

            return; // generate stop signal;
        }
    }; // wait until IBIF;
    //-----Slave ACK occurred------------
    tmp.BITS4.L4 = DATE % 10;
    tmp.BITS4.H4 = DATE / 10;
    IIC0_IBDR = tmp.Byte; // Send high byte of word address;
    DOG=0;
    while (!IIC0_IBSR_IBIF); // wait until IBIF;
     {
        DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;

            return; // generate stop signal;
        }
    }; // wait until IBIF;
    IIC0_IBSR_IBIF = 1; // clear the interrupt event flag;
    DOG=0;
    while (IIC0_IBSR_RXAK); // check for RXAK;
    {
        DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;

            return; // generate stop signal;
        }
    }; // wait until IBIF;
    //-----Slave ACK occurred------------
    tmp.BITS4.L4 = MONTH % 10;
    tmp.BITS4.H4 = MONTH / 10;
    IIC0_IBDR = tmp.Byte; // Send high byte of word address;
    DOG=0;
    while (!IIC0_IBSR_IBIF); // wait until IBIF;
    {
        DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;

            return; // generate stop signal;
        }
    }; // wait until IBIF;
    IIC0_IBSR_IBIF = 1; // clear the interrupt event flag;
    DOG=0;
    while (IIC0_IBSR_RXAK); // check for RXAK;
    {
        DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;

            return; // generate stop signal;
        }
    }; // wait until IBIF;
    //-----Slave ACK occurred------------
    tmp.BITS4.L4 = YEAR % 10;
    tmp.BITS4.H4 = YEAR / 10;
    IIC0_IBDR = tmp.Byte; // Send high byte of word address;
     DOG=0;
    while (!IIC0_IBSR_IBIF); // wait until IBIF;
    {
        DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;

            return; // generate stop signal;
        }
    }; // wait until IBIF;
    IIC0_IBSR_IBIF = 1; // clear the interrupt event flag;
    DOG=0;
    while (IIC0_IBSR_RXAK); // check for RXAK;
    {
        DOG++;

        if (DOG > 10000)
        {
            IIC0_IBCR_MS_SL = 0;
            IIC0_IBCR_IBEN=0;

            return; // generate stop signal;
        }
    }; // wait until IBIF;
    IIC0_IBCR_MS_SL = 0; // generate stop signal;
}


void Timer_Management(void)
{
   // DATE_YEAR 
  uint NowTime;
  static timer1flag;
  static timer2flag;
  static repeatflag1=1;
  static repeatflag2=1;
  static timer1trig=0;
  static timer2trig=0;
  uchar inhibitstartweek=0;
  #if B_MODE
  return;
  #endif
  #if FEIERTE_MODE
  if(DI_FET_INHIBITDAY)
  {
    
  switch(FET_INHIBIT_DAY)
  {
    case 0:
    if(DATE_WEEK==MON||DATE_WEEK==WEN||DATE_WEEK==FRI||DATE_WEEK==SUN)
    {
       inhibitstartweek=1;
    }
    break;
    
    case 1:
    if(DATE_WEEK==TUE||DATE_WEEK==THU||DATE_WEEK==SAT)
    {
       inhibitstartweek=1;
    }
    break;
    
    case 2:
    if(DATE_WEEK==MON||DATE_WEEK==TUE||DATE_WEEK==WEN||DATE_WEEK==THU||DATE_WEEK==FRI||DATE_WEEK==SAT||DATE_WEEK==SUN)
    {
       inhibitstartweek=1;
    }
    break;
    
    case 3:
    if(DATE_WEEK==SAT||DATE_WEEK==SUN)
    {
       inhibitstartweek=1;
    }
    break;
  }
  
  
  }
  
  #endif
  //当前时间
  NowTime=DATE_MINUTE+DATE_HOUR*60; 
 
 
  if((NowTime>FET_INHIBIT_TIME_ON &&NowTime<FET_INHIBIT_TIME_OFF)||inhibitstartweek)
  {
      DISABLE_AUTOSTART=1;
  }
  else
  {
      DISABLE_AUTOSTART=0;  
  }
 
 
 if(MaintainDays>FET_MAINTAINPERIOD)
 {
     FET_ENSTART=1;
     TIMERSTART=1;
     MaintainDays=0;
 }
  
  
  
 #if FEIERTE_MODE
     return;
 #endif
 
 #if FEIERTE_MODE==0
 switch(Timer1Repeat)
  {                    
      case NOREPEAT:
      repeatflag1=0;
      break;
          
      case MON:
     if(DATE_WEEK==MON)
     {
         repeatflag1=1;
     }
      break;
      
      case TUE:
     if(DATE_WEEK==TUE)
     {
         repeatflag1=1;
     }
      break; 
       
      case WEN:    
      if(DATE_WEEK==WEN)
     {
         repeatflag1=1;
     }
      break;
    
      case THU:    
      if(DATE_WEEK==THU)
     {
         repeatflag1=1;
     }
      break;
      
      case FRI:    
      if(DATE_WEEK==FRI)
     {
         repeatflag1=1;
     }
      break;
      
      case SAT:    
      if(DATE_WEEK==SAT)
     {
         repeatflag1=1;
     }
      break;   
       
      case SUN:    
      if(DATE_WEEK==SUN)
     {
         repeatflag1=1;
     }
      break;   
      
      case MON_FRI:    
      if(DATE_WEEK>=MON && DATE_WEEK<=FRI)
     {
         repeatflag1=1;
     }
      break;       

      
      case MON_SAT:    
      if(DATE_WEEK>=MON && DATE_WEEK<=SAT)
     {
         repeatflag1=1;
     }
      break;
      
      case MON_SUN: 
         repeatflag1=1;
      break;           
  
      case SAT_SUN: 
      if(DATE_WEEK>=SAT && DATE_WEEK<=SUN)
     {
         repeatflag1=1;
     }
      break;
  
  }
  
 
 if(repeatflag1)
 {
  
   //如果启动时间等于当前时间
    if(Timer1Start==NowTime) 
    {
       if(timer1flag==0)
       {   
        //计时器1开始动作     
        TimerEnArr[TMR_TIMER1]=1;
        timer1flag=1;
        }
    }
    else
    {
        timer1flag=0;
    }
  
    //计时器1持续时间
    if(TimerEnArr[TMR_TIMER1]==1)
    {
        #if FEIERTE_MODE
        if(Timer1Func==1||Timer1Func==2)
        {
            if(FET_ENSTART==0 && STA_DES_STOP)
            {
                timer1trig=1;
                FET_ENSTART=1;
                TIMERSTART=1;                                 
            }
            
            else if(TIMERSTART==0)
            {
                TimerEnArr[TMR_TIMER1]=0;                                
            }
        }
        #endif
    }
  

 }
 
     //计时器1定时器复位
  if(TimerTrig[TMR_TIMER1])
  {
      TimerEnArr[TMR_TIMER1]=0;
      TimerTrig[TMR_TIMER1]=0;
            
      #if FEIERTE_MODE
      if(Timer1Func==2||Timer1Func==1)
      {           
          if(timer1trig)
          {
              FET_ENSTART=0;
              TIMERSTART=0;
              timer1trig=0;                      
          }
      }
      #endif  
      
      
           
  }
  
  
  
  
  
  if(repeatflag2)
  {
    
  if(Timer2Start==NowTime) 
  {
      if(timer2flag==0)
      {        
      TimerEnArr[TMR_TIMER2]=1;
      timer2flag=1;
      }
  }
  else
  {
      timer2flag=0;
  }



  //计时器2持续时间
  if(TimerEnArr[TMR_TIMER2]==1)
  {
        #if FEIERTE_MODE
        if(Timer2Func==1||Timer2Func==2)
        {
            if(FET_ENSTART==0 && STA_DES_STOP)
            {
                timer2trig=1;
                FET_ENSTART=1;
                TIMERSTART=1;                                 
            }
            
            else if(TIMERSTART==0)
            {
                TimerEnArr[TMR_TIMER2]=0;                                
            }
        }
        #endif  
  }
  
}


  //计时器2定时器复位
  if(TimerTrig[TMR_TIMER2])
  {
      TimerEnArr[TMR_TIMER2]=0;
      TimerTrig[TMR_TIMER2]=0;
      #if FEIERTE_MODE
      if(Timer2Func==2||Timer2Func==1)
      {           
          if(timer2trig)
          {
              FET_ENSTART=0;
              TIMERSTART=0;
              timer2trig=0;                      
          }
      }
      #endif 
  }
  
  
  #endif

}
