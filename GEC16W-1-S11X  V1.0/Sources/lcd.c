#include "hidef.h"      /* common defines and macros */
#include <MC9S12XS128.h>
//#include "string.h"
#include "extern.h"
#include "defs.h"
#include "main.h"
#include "btn.h"
#include "MCU_init.h"
#include "math.h"
#include "io.h"
#include "alloc.h"
#include "lcdfont.h"
#include "lcd.h"
#define SCREENWIDE 128
const uchar *__far pointchar;
const uchar *__far strchar;
const uchar *__far startpoint;
const uchar *__far showstr1;
const uchar *__far showstr2;
const uchar *__far showstr3;
const uchar *__far showstr4;
//const ParamStruct *__far PT_ParamStruct;
uchar BL = 1;
uchar CLOSE = 0;

#define LCD_ADC_N       0XA0
#define LCD_ADC_R       0XA1
#define LCD_DIS_MODE_N  0XA4
#define LCD_DIS_MODE_A  0XA5
#define LCD_DIS_N       0XA6
#define LCD_DIS_R       0XA7
#define LCD_CUR_ON      0XAD
#define LCD_CUR_OFF     0XAC
#define LCD_FRE_314     0XE4
#define LCD_FRE_263     0XE5
#define LCD_PAGE_BASE   0XB0

uchar TX0 = 0;
uchar TY0 = 0;
uchar TX1 = 131;
uchar TY1 = 63;

uchar reverse = 0;

uchar line_hi[SCREENWIDE];
uchar line_lo[SCREENWIDE];

uchar line_hi1[SCREENWIDE];
uchar line_lo1[SCREENWIDE];
uchar line_hi2[SCREENWIDE];
uchar line_lo2[SCREENWIDE];
uchar line_hi3[SCREENWIDE];
uchar line_lo3[SCREENWIDE];
uchar line_hi4[SCREENWIDE];
uchar line_lo4[SCREENWIDE];

uchar numbuffer[15];
/*
unsigned char MENUCOUNT[] =
{
     2,//密码
    19,//基本设定
    22,//发动机参数
    16,//发动机保护
    15,//发电机保护 
    16,//AMF设定
    16,//扩展I/O 
    12,//日期/时间
    14,//传感器规格        
    #if FEIERTE_MODE
    21,//充电设置
    #else
    14,//其他设置
    #endif
    14,//自定义输入输出
     4,//传感器曲线选择
     3 //ECU6800设置
};
*/


PRIVATE uchar line_cnt;
PRIVATE uchar line_len;
PRIVATE uchar line_start;
PRIVATE uchar line_drawed;

PRIVATE uint strlen (const uchar *__far  ptr)
{
    uint i = 0;

    while (*ptr++)
    {
        i++;
    }

    return i;
}


//*****************************************************************************
//函数名称：  lcd_delay_ms()
//功能描述：  delay
//输入参数：  ms
//输出参数：
//*****************************************************************************
PRIVATE void lcd_delay_ms (uchar delay_cnt)
{
    uint i;
    uint j;

    for (i = delay_cnt; i > 0; i--)
    {
        for (j = 3200; j > 0; j--);
    }
}


//************************************************************************************
//函数名称：  lcd_clr_buf()
//功能描述：  clear display data buf
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void lcd_clr_buf (void)
{
    uchar i;

    for (i = 0; i < SCREENWIDE; i++)
    {
        line_hi[i] = 0;
        line_lo[i] = 0;
    }
}

PRIVATE void lcd_clr_page (void)
{
    uchar i;

    for (i = 0; i < SCREENWIDE; i++)
    {
        line_hi1[i] = 0;
        line_lo1[i] = 0;
        line_hi2[i] = 0;
        line_lo2[i] = 0;
        line_hi3[i] = 0;
        line_lo3[i] = 0;
        line_hi4[i] = 0;
        line_lo4[i] = 0;
    }
}

PRIVATE uchar GetLineNum (const uchar *__far pdata)
{
    return strlen (pdata) * 6;
}
//************************************************************************************
//函数名称：  lcd_ser_chs()
//功能描述：  find charactor mask and fix it to the buf,chinese font
//输入参数：  pointer to charator, location of buf,length of charactor, length of font
//输出参数：
//************************************************************************************
PRIVATE void lcd_ser_chs (uchar *__far pdata, uchar len)
{
#if 1
    uchar hi_buf;
    uchar lo_buf;
    uchar i;
    uint j;
    uchar k;
    uchar widthlen;
    uchar linestart;
    uchar A;
    linestart = line_cnt;

    for (i = 0; i < len; i++)
    {
        if (*pdata > 128)
        {
            lo_buf = *pdata;
            hi_buf = * (pdata + 1);
        }
        else
        {
            lo_buf = *pdata;
        }

        if (lo_buf > 128)
        {
            for (j = 0; j < sizeof (GB_16) / sizeof (typFNT_GB16); j++)
            {
                if ( (lo_buf == GB_16[j].Index[0]) && (hi_buf == GB_16[j].Index[1]) )
                {
                    for (k = 0; k < 12; k++)
                    {
                        line_hi[linestart] = GB_16[j].Msk[k]; // ((GB_16[j].Msk[k])>>1)&0x7F | (GB_16[j].Msk[k+12]&0x01)<<7;// | GB_16[j].Msk[k]>>1+ (GB_16[j].Msk[k+12]&0x01);
                        line_lo[linestart] = GB_16[j].Msk[k+12]; // GB_16[j].Msk[k+12]>>1;
                        linestart++;
                    }

                    lo_buf = *pdata++;
                    hi_buf = *pdata++;
                    break;
                }
            }
        }
        else
        {
            for (j = 0; j < sizeof (ASC_16) / sizeof (typFNT_ASC16); j++)
            {
                if (lo_buf == ASC_16[j].Index)
                {
                    for (k = 0; k < 6; k++)
                    {
                        line_hi[linestart] = ASC_16[j].Msk[k];
                        line_lo[linestart] = ASC_16[j].Msk[k+6];
                        linestart++;
                    }

                    pdata++;
                    break;
                }
            }
        }

        line_drawed = linestart - line_cnt;
    }

#endif
}

//*****************************************************************************
//函数名称：  lcd_delay_ms()
//功能描述：  delay
//输入参数：  ms
//输出参数：
//*****************************************************************************
PRIVATE void lcd_delay_ns (uchar delay_cnt)
{
    uint i;
    uint j;

    for (i = delay_cnt; i > 0; i--)
    {
        for (j = 4; j > 0; j--);
    }
}
PRIVATE void lcd_data_convert (uchar disp_buf)
{
    if (disp_buf & BIT0)
    {
        LCD_DATA_BIT0 = 1;
    }
    else
    {
        LCD_DATA_BIT0 = 0;
    }

    if (disp_buf & BIT1)
    {
        LCD_DATA_BIT1 = 1;
    }
    else
    {
        LCD_DATA_BIT1 = 0;
    }

    if (disp_buf & BIT2)
    {
        LCD_DATA_BIT2 = 1;
    }
    else
    {
        LCD_DATA_BIT2 = 0;
    }

    if (disp_buf & BIT3)
    {
        LCD_DATA_BIT3 = 1;
    }
    else
    {
        LCD_DATA_BIT3 = 0;
    }

    if (disp_buf & BIT4)
    {
        LCD_DATA_BIT4 = 1;
    }
    else
    {
        LCD_DATA_BIT4 = 0;
    }

    if (disp_buf & BIT5)
    {
        LCD_DATA_BIT5 = 1;
    }
    else
    {
        LCD_DATA_BIT5 = 0;
    }

    if (disp_buf & BIT6)
    {
        LCD_DATA_BIT6 = 1;
    }
    else
    {
        LCD_DATA_BIT6 = 0;
    }

    if (disp_buf & BIT7)
    {
        LCD_DATA_BIT7 = 1;
    }
    else
    {
        LCD_DATA_BIT7 = 0;
    }
}
#if LCDMODE

//************************************************************************************
//函数名称：  lcd_cs_en()
//功能描述：  enable chip set
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void lcd_cs_en (void)
{
    DDR_LCD_CS1 = 1;
    LCD_CS1     = 0;
}
//************************************************************************************
//函数名称：  lcd_cs_dis()
//功能描述：  disable chip set
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void lcd_cs_dis (void)
{
    DDR_LCD_CS1 = 1;
    LCD_CS1     = 1;
}
//************************************************************************************
//函数名称：  lcd_set_A0()
//功能描述：  indicate data is display data
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void lcd_dis_en (void)
{
    DDR_LCD_A0 = 1;
    LCD_A0     = 1;
}
//************************************************************************************
//函数名称：  lcd_clr_A0()
//功能描述：  indicate data is control data
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void lcd_ctr_en (void)
{
    DDR_LCD_A0 = 1;
    LCD_A0     = 0;
}
//************************************************************************************
//函数名称：  lcd_rd_en()
//功能描述：  enable read data
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void lcd_rd_en (void)
{
    DDR_LCD_RD = 1;
    LCD_RD     = 0;
}
//************************************************************************************
//函数名称：  lcd_rd_dis()
//功能描述：  disable read data
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void lcd_rd_dis (void)
{
    DDR_LCD_RD = 1;
    LCD_RD     = 1;
}
//************************************************************************************
//函数名称：  lcd_wr_en()
//功能描述：  enable write data
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void lcd_wr_en (void)
{
    DDR_LCD_WR = 1;
    LCD_WR     = 0;
}
//************************************************************************************
//函数名称：  lcd_wr_dis()
//功能描述：  disable write data
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void lcd_wr_dis (void)
{
    DDR_LCD_WR = 1;
    LCD_WR     = 1;
}

//************************************************************************************
//函数名称：  lcd_wr_ctr()
//功能描述：  write control data in internal register
//输入参数：  control data
//输出参数：
//************************************************************************************
PRIVATE void lcd_wr_ctr (uchar data_ctr)
{
    lcd_cs_dis();
    lcd_ctr_en();
    lcd_cs_en();
    lcd_rd_dis();
    lcd_wr_en();
    lcd_data_convert (data_ctr);
    lcd_cs_dis();
    lcd_wr_dis();
}
//************************************************************************************
//函数名称：  lcd_putchar()
//功能描述：  write display data to lcd data ram
//输入参数：  display data
//输出参数：
//************************************************************************************
PRIVATE void lcd_putchar (uchar disp_buf)
{
    DDR_LCD_CS1 = 1;
    LCD_CS1     = 1;
    DDR_LCD_A0 = 1;
    LCD_A0     = 1;
    DDR_LCD_CS1 = 1;
    LCD_CS1     = 0;
    DDR_LCD_RD = 1;
    LCD_RD     = 1;
    DDR_LCD_WR = 1;
    LCD_WR     = 0;
    lcd_data_convert (disp_buf);
    DDR_LCD_CS1 = 1;
    LCD_CS1     = 1;
    DDR_LCD_WR = 1;
    LCD_WR     = 1;
}
//************************************************************************************
//函数名称：  lcd_colu_set()
//功能描述：  column address set
//输入参数：  column address ; scope is 0x00--0x18
//输出参数：
//************************************************************************************
PRIVATE void lcd_colu_set (uchar clu_addr)
{
    uchar lo_addr_buf;
    uchar hi_addr_buf;

    if (clu_addr > 0x83)   //if column address is over scope , return false
    {
        return;
    }
    else
    {
        lo_addr_buf = (clu_addr & 0x0f);
        hi_addr_buf = ( ( (clu_addr >> 4) | 0x10 & 0x1f) );
        lcd_wr_ctr (hi_addr_buf);
        lcd_wr_ctr (lo_addr_buf);
        return;
    }
}

//************************************************************************************
//函数名称：  lcd_clear()
//功能描述：  clear lcd
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void lcd_clear (void)
{
    uchar i;
    uchar j;

    if (F_CLR_LCD)
    {
        F_CLR_LCD = 0;

        for (i = 0; i < 8; i++)
        {
            lcd_wr_ctr (i + LCD_PAGE_BASE);
            lcd_colu_set (0x00);

            for (j = 0; j < 132; j++)
            {
                lcd_putchar (0x00);
            }
        }
    }
}

//************************************************************************************
//函数名称：  lcd_initial()
//功能描述：  initial lcd state
//输入参数：
//输出参数：
//************************************************************************************
PUBLIC void lcd_initial (void)
{
    LCD_RST = 0;      //hardware reset
    lcd_delay_ms (2);
    LCD_RST = 1;      //release reset signal
    lcd_delay_ms (200);
    lcd_delay_ms (200);
    lcd_wr_ctr (0xe2);
    lcd_delay_ms (40);
    lcd_wr_ctr (0xa2);  //bias set 1/9, 1/65 dusy
    lcd_wr_ctr (LCD_ADC_N);    //ADC select SEG0 to SEG131 normal
    lcd_wr_ctr (0xc8); //com reverse
    lcd_wr_ctr (0x40);   //display start line set = 0
    lcd_delay_ms (20);
    lcd_wr_ctr (0x25);              //V0 valtage regulator internal resistor ratio set
    lcd_wr_ctr (0x2f);
    lcd_delay_ms (20);
    lcd_wr_ctr (0x81);
    lcd_wr_ctr (0x30);    // vo = 8.25 X (1 - (63 - 0X30) / 162 X 1.4 = ;
    lcd_delay_ms (20);
    lcd_wr_ctr (LCD_DIS_N);  //normal display
    lcd_wr_ctr (0x89);
    lcd_wr_ctr (0x01);  // //4 times boosting circuit
    lcd_wr_ctr (LCD_FRE_314); //osc frequency is 31.4KHz
    lcd_wr_ctr (LCD_DIS_MODE_N); //entire display on
    lcd_wr_ctr (0xaf);
    lcd_delay_ms (100);
    lcd_clear();
}

#endif

#if VFDMODE

PRIVATE void vfd_putchar (uchar data_ctr)
{
    VFD_WR = 1;
    VFD_RD = 0;

    while (VFD_PBUSY);

    VFD_RD = 1;
    VFD_WR = 0;
    lcd_data_convert (data_ctr);
    VFD_WR = 1;
}

PRIVATE void vfd_cursorset (uchar X, uchar Y)
{
    vfd_putchar (0x1F);
    vfd_putchar (0x24);
    vfd_putchar (X);
    vfd_putchar (0);
    vfd_putchar (Y);
    vfd_putchar (0);
}


PRIVATE void vfd_writeline (uchar startcolu, uchar linenum, uchar *datastart, uchar datalength)
{
    uchar i;
    uchar A;
    vfd_cursorset (startcolu, linenum);
    vfd_putchar (0x1F);
    vfd_putchar (0x28);
    vfd_putchar (0x66);
    vfd_putchar (0x11);
    vfd_putchar (datalength);
    vfd_putchar (0x00);
    vfd_putchar (0x01);
    vfd_putchar (0x00);
    vfd_putchar (0x01);

    for (i = 0; i < datalength; i++)
    {
        A = * (datastart + i);
        A = ( (A & 0xaa) >> 1) | ( (A & 0x55) << 1);
        A = ( (A & 0xcc) >> 2) | ( (A & 0x33) << 2);
        A = ( (A & 0xf0) >> 4) | ( (A & 0x0f) << 4);
        //*(datastart+i)=A;
        vfd_putchar (A);
    }
}


#endif

//************************************************************************************
//函数名称：  lcd_puts()
//功能描述：  put string to lcd,inverse buf, 1 inverse,0 normal
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void lcd_puts (uchar line_buf, uchar refresh)
{
    uchar i;
    uchar j;
    uchar m;
    uchar *lineh;
    uchar *linel;
    uchar nowline;

    //  if(inverse_buf)
    //  {
    //      for(i=0;i<SCREENWIDE;i++)
    //      {
    //          line_hi[i] = ~line_hi[i];
    //          line_lo[i] = ~line_lo[i];
    //      }
    //  }
    switch (line_buf)
    {
    case 1:

        for (i = line_start; i < (line_start + line_len); i++)
        {
            //          line_hi1[i]=0;
            //          line_lo1[i]=0;
            line_hi1[i] = line_hi[i];
            line_lo1[i] |= line_lo[i] & 0x0F;
        }

        break;
    case 2:

        for (i = line_start; i < (line_start + line_len); i++)
        {
            //         line_hi2[i]=0;
            //          line_lo2[i]=0;
            line_lo1[i] |= (line_hi[i] & 0x0F) << 4;
            line_hi2[i] = (line_hi[i] & 0xF0) >> 4;
            line_hi2[i] |= (line_lo[i] & 0x0F) << 4;
            //  line_lo2[i]|=(line_lo[i]&0xF0)>>4;
        }

        break;
    case 3:

        for (i = line_start; i < (line_start + line_len); i++)
        {
            //          line_hi3[i]=0;
            //          line_lo3[i]=0;
            line_lo2[i] = (line_hi[i] & 0x0F);
            line_lo2[i] |= (line_hi[i] & 0xF0);
            line_hi3[i] |= (line_lo[i] & 0x0F);
            //line_hi3[i]|=(line_lo[i]&0xF0);
        }

        break;
    case 4:

        for (i = line_start; i < (line_start + line_len); i++)
        {
            line_hi3[i] |= (line_hi[i] & 0x0F) << 4;
            line_lo3[i] = (line_hi[i] & 0xF0) >> 4;
            line_lo3[i] |= (line_lo[i] & 0x0F) << 4;
            //      line_hi2[i]|=(line_lo[i]&0x0F)<<4;
        }

        break;
    case 5:

        for (i = line_start; i < (line_start + line_len); i++)
        {
            //      line_hi4[i]=0;
            //          line_lo4[i]=0;
            line_hi4[i] = line_hi[i];
            line_lo4[i] = line_lo[i];
        }

        break;
        // default:
        // return;
        // break;
    }

    if (refresh)
    {
        //VFD刷新
#if VFDMODE
        for (m = 1; m <= 4; m++)
        {
            nowline = line_start;

            switch (m)
            {
            case 1:
                lineh = &line_hi1[0];
                linel = &line_lo1[0];
                break;
            case 2:
                lineh = &line_hi2[0];
                linel = &line_lo2[0];
                break;
            case 3:
                lineh = &line_hi3[0];
                linel = &line_lo3[0];
                break;
            case 4:
                lineh = &line_hi4[0];
                linel = &line_lo4[0];
                break;
            }

            vfd_writeline (line_start, (m - 1) * 2, lineh, line_len);
            vfd_writeline (line_start, (m - 1) * 2 + 1, linel, line_len);
        }

#endif
        //LCD刷新
#if LCDMODE

        for (m = 1; m <= 4; m++)
        {
            for (i = 0; i < 2; i++)
            {
                lcd_wr_ctr (i + (m - 1) * 2 + LCD_PAGE_BASE);
                lcd_colu_set (line_start);
                nowline = line_start;

                switch (i)
                {
                case 0:

                    switch (m)
                    {
                    case 1:
                        lineh = &line_hi1[0];
                        break;
                    case 2:
                        lineh = &line_hi2[0];
                        break;
                    case 3:
                        lineh = &line_hi3[0];
                        break;
                    case 4:
                        lineh = &line_hi4[0];
                        break;
                    }

                    for (j = 0; j < line_len; j++)
                    {
                        lcd_putchar (* (lineh + nowline++) );
                    }

                    break;
                case 1:

                    switch (m)
                    {
                    case 1:
                        linel = &line_lo1[0];
                        break;
                    case 2:
                        linel = &line_lo2[0];
                        break;
                    case 3:
                        linel = &line_lo3[0];
                        break;
                    case 4:
                        linel = &line_lo4[0];
                        break;
                    }

                    for (j = 0; j < line_len; j++)
                    {
                        lcd_putchar (* (linel + nowline++) );
                    }

                    break;
                }
            }
        }

#endif
    }
}


//************************************************************************************
//函数名称：
//功能描述：
//输入参数：
//输出参数：
//************************************************************************************
PRIVATE void lcd_show_number (long Number, uchar dot, int posX, uchar line)
{
    uchar i;
    uchar j;
    uchar IsNeg = 0;
    uchar refreshnum = 5;

    if (Number == -32768)
    {
   // refreshnum=4;
    
        for (i = 0; i < 5; i++)
        {
            numbuffer[i] = '#';
        }

        lcd_clr_buf();
        line_cnt   = posX+6;//+refreshnum;
        line_start = posX+6;//+refreshnum;
        line_len   = 24;
        lcd_ser_chs (&numbuffer[0], 4);
        lcd_puts (line, 0);
        return;
    }

    if (Number < 0)
    {
        Number = 0 - Number;
        IsNeg = 1;
    }

    for (i = 0; i < 5; i++)
    {
        if (Number >= 1)
        {
            numbuffer[4-i] = Number % 10 + 48; //else numbuffer[3-L]=Number+49;
            Number = (Number - Number % 10) / 10;
        }
        else
        {
            numbuffer[4-i] = 48;
        }
    }

    for (i = 0; i < 4; i++)
    {
        if (numbuffer[i] == 48)
        {
            numbuffer[i] = 32;
        }
        else
        {
            i = 5;
        }
    }

    if (dot <= 4 && dot > 0)
    {
        for (i = 1; i <= 4 - dot; i++)
        {
            numbuffer[i-1] = numbuffer[i];

            if (i == (4 - dot) )
            {
                numbuffer[i] = 46;

                if (numbuffer[i-1] == 32)
                {
                    numbuffer[i-1] = 48;
                }

                for (j = 0; j < dot; j++) if (numbuffer[4-j] == 32)
                    {
                        numbuffer[4-j] = 48;
                    }

                break;
            }
        }

        // for(i=1;i<4;i++) //处理小数点前的0
        // {
        //   if(numbuffer[i]==46&&numbuffer[i-1]==32)numbuffer[i-1]=48,i=5;
        // }
    }

    for (i = 1; i < 5; i++) //处理负符号
    {
        if (numbuffer[i] != 32 && numbuffer[i-1] == 32 && IsNeg == 1)
        {
            numbuffer[i-1] = '-', i = 5;
        }
    }

    for (i = 0; i < 5; i++)
    {
        if (numbuffer[i] == 32)
        {
            posX += 6, refreshnum -= 1;
        }
    }

    line_cnt   = posX;//+refreshnum;
    line_start = posX;//+refreshnum;
    line_len   = refreshnum * 6;
    lcd_clr_buf();
    lcd_ser_chs (&numbuffer[0] + 5 - refreshnum, refreshnum);
    lcd_puts (line, 0);
}

PRIVATE void lcd_show_number_lng (unsigned long Number, uchar dot, uchar posX, uchar line)
{
    uchar i;
    uchar j;
    uchar IsNeg = 0;
    uchar refreshnum = 10;
    /*
          if(Number==-32768)
          {
          for(i=0;i<5;i++)numbuffer[i]='+';
           lcd_clr_buf();
           line_cnt   = posX;//+refreshnum;
           line_start = posX;//+refreshnum;
          line_len   = 30;
           lcd_ser_chs(&numbuffer[0],5);
           lcd_puts(line,0);
           return;
          }


           if(Number<0)
           {
           Number=0-Number;
           IsNeg=1;
           }

    */

    for (i = 0; i < 10; i++)
    {
        if (Number >= 1)
        {
            numbuffer[9-i] = Number % 10 + 48; //else numbuffer[3-L]=Number+49;
            Number = (Number - Number % 10) / 10;
        }
        else
        {
            numbuffer[9-i] = 48;
        }
    }

    for (i = 0; i < 9; i++)
    {
        if (numbuffer[i] == 48)
        {
            numbuffer[i] = 32;
        }
        else
        {
            i = 10;
        }
    }

    /*
    if(dot<=9&&dot>0)
    {
      for(i=1;i<=9-dot;i++)
      {
        numbuffer[i-1]=numbuffer[i];
        if(i==(9-dot))
        {
         numbuffer[i]=46;
         if(numbuffer[i-1]==32)numbuffer[i-1]=48;

         for(j=0;j<dot;j++) if(numbuffer[9-j]==32)numbuffer[4-j]=48;

         break;
        }

      }


     // for(i=1;i<4;i++) //处理小数点前的0
     // {
     //   if(numbuffer[i]==46&&numbuffer[i-1]==32)numbuffer[i-1]=48,i=5;
     // }

    }
    */
    //       for(i=1;i<5;i++) //处理负符号
    //       {
    //         if(numbuffer[i]!=32&&numbuffer[i-1]==32&&IsNeg==1)numbuffer[i-1]='-',i=5;
    //       }

    for (i = 0; i < 10; i++)
    {
        if (numbuffer[i] == 32)
        {
            posX += 6, refreshnum -= 1;
        }
    }

    line_cnt   = posX;//+refreshnum;
    line_start = posX;//+refreshnum;
    line_len   = refreshnum * 6;
    lcd_clr_buf();
    lcd_ser_chs (&numbuffer[0] + 10 - refreshnum, refreshnum);
    lcd_puts (line, 0);
}

PRIVATE const uchar *__far GetParamString (uint Pnum, uint value)
{
    if (Pnum >= 126 && Pnum <= 132)
    {
        Pnum = 126;
    }

    if (Pnum >= 133 && Pnum <= 139)
    {
        Pnum = 133;
    }

    switch (Pnum)
    {
    case 3://重设默认
        startpoint = &Stringlist[33].line1[0];
        break;
    case 14: //iG模式
        startpoint = &Stringlist[1].line1[0];
        break;
    case 15: //复位转手动
        startpoint = &Stringlist[1].line5[0];
        break;
    case 20: //MODBUS速度
        startpoint = &Stringlist[0].line1[0];
        break;
    case 21: //连接方法
        startpoint = &Stringlist[2].line3[0];
        break;
    case 31: //冷却速度
        startpoint = &Stringlist[3].line2[0];
        break;
    case 34: //燃料阀
        startpoint = &Stringlist[3].line4[0];
        break;
    case 35: //D+功能
        startpoint = &Stringlist[4].line1[0];
        break;
    case 75: //回到岛运行
        startpoint = &Stringlist[5].line2[0];
        break;
    case 88: //MCB逻辑
        startpoint = &Stringlist[5].line4[0];
        break;
    case 89: //测试回复
        startpoint = &Stringlist[6].line5[0];
        break;
    case 90: //MCB断路当
        startpoint = &Stringlist[7].line2[0];
        break;
    //case 108://夏令时间
    //    startpoint = &Stringlist[7].line4[0];
    //    break;
    case 111://计时1功能
        startpoint = &Stringlist[8].line4[0];
        break;
    case 112://计时1重复
        startpoint = &Stringlist[9].line4[0];
        break;
    case 115://计时2重复
        startpoint = &Stringlist[8].line4[0];
        break;
    case 116://计时2重复
        startpoint = &Stringlist[9].line4[0];
        break;
    case 126://自定义输入
        if(LNG==0)
        {          
            startpoint = &DI_Stringlist_EN[0].line1[0];
        }
        else
        {
            startpoint = &DI_Stringlist_CN[0].line1[0];
        }
        return startpoint + value * 23;
        break;
    case 133://自定义输出
    
        startpoint = &Stringlist[17].line3[0];
        break;
    case 140://油压传感器类型
        startpoint = &Stringlist[37].line1[0];
        break;
    case 141://水温传感器类型
        startpoint = &Stringlist[39].line2[0];
        break;
    case 142://液位传感器类型
        startpoint = &Stringlist[35].line2[0];
        break;
    case 143://油温传感器类型
        startpoint = &Stringlist[39].line2[0];
        break;
    case 202:
        startpoint = &Stringlist[34].line1[0];
        break;
    case 113:
        startpoint = &Stringlist[32].line1[0];
        value = 0;
        break;
    case 109:
        startpoint = &Stringlist[32].line1[0];
        value = 0;
        break;
    case 110:
        startpoint = &Stringlist[32].line2[0];
        value = 0;
        break;
    case 117:
        startpoint = &Stringlist[32].line1[0];
        value = 0;
        break;      
        
    default:
        startpoint = &Stringlist[0].line5[0];
        break;
    }

    return startpoint + value * 23;
}

/*
反色函数 参数line 反色的行    pstart 开始反色的列   plen 反色长度
*/
PRIVATE void Reverseblock (uchar line, uchar pstart, uint plen)
{
    uint i;

    switch (line)
    {
    case 1:

        for (i = pstart; i < pstart + plen; i++)
        {
            line_hi1[i] = ~line_hi1[i];
            line_lo1[i] ^= 0x0F;
        }

        break;
    case 2:

        for (i = pstart; i < pstart + plen; i++)
        {
            line_lo1[i] ^= 0xF0;
            line_hi2[i] = ~line_hi2[i];
        }

        break;
    case 3:

        for (i = pstart; i < pstart + plen; i++)
        {
            line_lo2[i] = ~ line_lo2[i];
            line_hi3[i] ^= 0x0F;
        }

        break;
    case 4:

        for (i = pstart; i < pstart + plen; i++)
        {
            line_hi3[i] ^= 0xF0;
            line_lo3[i] = ~line_lo3[i];
        }

        break;
    case 5:

        for (i = pstart; i < pstart + plen; i++)
        {
            line_hi4[i] = ~line_hi4[i];
            line_lo4[i] ^= 0x0F;
        }

        break;
    }
}
PRIVATE void Clearline (uchar line)
{
    uchar i;

    switch (line)
    {
    case 1:

        for (i = 0; i < SCREENWIDE; i++)
        {
            line_hi1[i] = 0;
            line_lo1[i] &= 0xF0;
        }

        break;
    case 2:

        for (i = 0; i < SCREENWIDE; i++)
        {
            line_lo1[i] &= 0x0F;
            line_hi2[i] = 0;
        }

        break;
    case 3:

        for (i = 0; i < SCREENWIDE; i++)
        {
            line_lo2[i] = 0;
            line_hi3[i] &= 0xF0;
        }

        break;
    case 4:

        for (i = 0; i < SCREENWIDE; i++)
        {
            line_hi3[i] &= 0x0F;
            line_lo3[i] = 0;
        }

        break;
    case 5:

        for (i = 0; i < SCREENWIDE; i++)
        {
            line_hi4[i] = 0;
            line_lo4[i] &= 0xF0;
        }

        break;
    }
}

PRIVATE void drawpixel (int ptx, int pty)
{
    uchar i;
    uchar row;
    uchar col;
    uchar rowdot;
    uchar dotvalue;
    dotvalue = 1;
    row = pty / 8;
    rowdot = pty - row * 8;

    for (i = 0; i < rowdot; i++)
    {
        dotvalue = dotvalue << 1;
    }

    switch (row)
    {
    case 0:
        line_hi1[ptx] |= dotvalue;
        break;
    case 1:
        line_lo1[ptx] |= dotvalue;
        break;
    case 2:
        line_hi2[ptx] |= dotvalue;
        break;
    case 3:
        line_lo2[ptx] |= dotvalue;
        break;
    case 4:
        line_hi3[ptx] |= dotvalue;
        break;
    case 5:
        line_lo3[ptx] |= dotvalue;
        break;
    case 6:
        line_hi4[ptx] |= dotvalue;
        break;
    case 7:
        line_lo4[ptx] |= dotvalue;
        break;
    }
}



void Bresenham (int x0, int y0, int x1, int y1)
{
    unsigned int dx, dy, x, y;
    signed int e, sign, i, j, k;
    int tmp;

    if (x0 >= x1)
    {
        tmp = x1;
        x1 = x0;
        x0 = tmp;
        tmp = y1;
        y1 = y0;
        y0 = tmp;
    }

    sign = 1;
    dx = x1 - x0;
    dy = y1 - y0;

    if (y0 > y1)
    {
        sign = -1;
        dy = y0 - y1;
    }

    x = x0; y = y0;

    if (dy < dx)
    {
        e = -dx;

        for (i = 0; i <= dx; i++)
        {
            drawpixel (x, y);
            x++;
            e = e + 2 * dy;

            if (e >= 0)
            {
                y = y + sign;
                e = e - 2 * dx;
            }
        }
    }
    else
    {
        e = -dy;

        for (i = 0; i <= dy; i++)
        {
            drawpixel (x, y);
            y = y + sign;
            e = e + 2 * dx;

            if (e >= 0)
            {
                x = x + 1;
                e = e - 2 * dy;
            }
        }
    }
}



PUBLIC void DrawValuePercent (int Nowvalue, int FullValue, uchar posx, uchar posy, uint drawlen)
{
    float percent;
    uchar NowX;
    uchar i;
    percent = (float) Nowvalue / (float) FullValue;
    NowX = percent * drawlen;

    if (NowX > drawlen)
    {
        NowX = drawlen;
    }

    Bresenham (posx, posy, posx + drawlen, posy);
    Bresenham (posx, posy + 6, posx + drawlen, posy + 6);
    Bresenham (posx, posy, posx, posy + 6);
    Bresenham (posx + drawlen, posy, posx + drawlen, posy + 6);

    for (i = 1; i <= 5; i++)
    {
        Bresenham (posx, posy + i, posx + NowX, posy + i);
    }

    line_start = 0;
    line_len = SCREENWIDE;
}


PRIVATE void background_onoff (uchar onoff)
{
    vfd_putchar (0x1F);
    vfd_putchar (0x28);
    vfd_putchar (0x61);
    vfd_putchar (0x40);
    vfd_putchar (onoff);
}

PRIVATE void brightness (uchar level)
{
    vfd_putchar (0x1F);
    vfd_putchar (0x58);
    vfd_putchar (level);
}
PRIVATE void SelfTestProcess(void)
{
 static uchar outflag;
 static uchar noutflag;
 NowPage=21;
 NOWPHASE=100;
 if(DataValue[22]>0)
 {
     SelfTestMode=0;
     NowPage=1;
     NOWPHASE=0;
     SelfTestTimer=0;
     SciWriteParam (TESTPHASE, &NOWPHASE, 1);
     return;
 }
 
 switch(TestPhase)
 {
 
  case 0:
  lcd_clr_buf();
  line_cnt = 0;
  line_start = 0;
  line_len = SCREENWIDE;
  outflag=0;
  noutflag=0;
  if(LNG==0)
  {
      lcd_ser_chs ("     selftest        ", 21 );
  }
  else
  {  
      lcd_ser_chs ("     正在自检        ", 21 );
  }
  lcd_puts (1, 0);
  line_cnt = 0;
  line_start = 0;
  line_len = SCREENWIDE;
    if(LNG==0)
  {
      lcd_ser_chs ("GearTeeth            ", 21 );
  }
  else
  {   
      lcd_ser_chs ("齿数                 ", 21 );
  }
  lcd_puts (2, 0); 
  line_cnt = 0;
  line_start = 0;
  line_len = SCREENWIDE;   
  if(LNG==0)
  {  
      lcd_ser_chs ("Nominal Speed     RPM", 21 );
  }
  else
  {
      lcd_ser_chs ("额定转速          RPM", 21 );
  }
  lcd_puts (4, 0);
  
  lcd_show_number (ParamValue[11], 0,  97,  2);
  lcd_show_number (ParamValue[12], 0,  79,  4);
  
  if(SelfTestTimer>=2 && SelfTestTimer<8)
  {
      if(SelfTestTimer%2==0)
      {
          Reverseblock(2,0,128);
          
      }
  }
  
   if(SelfTestTimer>=10 && SelfTestTimer<16)
  {
      if(SelfTestTimer%2==0)
      {
          Reverseblock(4,0,128);
      }
  } 
  
  
  if(SelfTestTimer>=18)
  {
      SelfTestTimer=0;
      TestPhase=1;
  }
        
  break;
  case 1:
  lcd_clr_buf();
  line_cnt = 0;
  line_start = 0;
  line_len = SCREENWIDE;
  
  if(LNG==0)
  {
      lcd_ser_chs ("     selftest        ", 21 );
  }
  else
  {  
      lcd_ser_chs ("     正在自检        ", 21 );
  }
  lcd_puts (1, 0);
  line_cnt = 0;
  line_start = 0;
  line_len = SCREENWIDE;
  if(LNG==0)
  {
      lcd_ser_chs ("OverSpeed Sd      RPM", 21 );
  }
  else
  {
      lcd_ser_chs ("超速停机          RPM", 21 );
  }
  lcd_puts (3, 0); 
  line_cnt = 0;
  line_start = 0;
  line_len = SCREENWIDE; 
  if(LNG==0)
  {   
      lcd_ser_chs ("OverSpeed Wrn     RPM", 21 );
  }
  else
  {
      lcd_ser_chs ("超速预警          RPM", 21 );
  }
  lcd_puts (2, 0); 
  line_cnt = 0;
  line_start = 0;
  line_len = SCREENWIDE; 
  if(LNG==0) 
  {
      lcd_ser_chs ("O.P Sd            Bar", 21 );
  }
  else
  {
      lcd_ser_chs ("油压过低停机      Bar", 21 );
  }
  lcd_puts (5, 0);
  line_cnt = 0;
  line_start = 0;
  line_len = SCREENWIDE; 
  if(LNG==0)
  {
      lcd_ser_chs ("O.P Wrn           Bar", 21 );
  }
  else
  {
      lcd_ser_chs ("油压低预警        Bar", 21 );
  }
  
  lcd_puts (4, 0); 
  lcd_show_number ((int)((long)ParamValue[12]*ParamValue[45]/100), 0,  79,  3);
  lcd_show_number ((int)((long)ParamValue[12]*(ParamValue[45]-5)/100), 0,  79,  2);
  lcd_show_number (ParamValue[47], 1,  79,  5);
  lcd_show_number (ParamValue[46], 1,  79,  4);  
  
  if(SelfTestTimer<2)
  {
      outflag=0;
      noutflag=0;
  }
  
  if(SelfTestTimer>=2 && SelfTestTimer<8)
  {
      NOWPHASE=1;
      noutflag=0;
      if(outflag==0)
      {        
          F_BTN_SELFTEST_SDOUT=1;
          outflag=1;
      }
      
      if(SelfTestTimer%2==0)
      {
          Reverseblock(2,0,128);      
      }
  }
  
  if(SelfTestTimer>=8 && SelfTestTimer<10)
  {
      outflag=0;
      if(noutflag==0)
      {
          F_BTN_SELFTEST_SDNOUT=1;
          noutflag=1;
      }
  } 
  
  if(SelfTestTimer>=10 && SelfTestTimer<16)
  {
      NOWPHASE=2;
      noutflag=0;
      if(outflag==0)
      {        
          F_BTN_SELFTEST_SDOUT=1;
          outflag=1;
          noutflag=0;
      }
      
      if(SelfTestTimer%2==0)
      {
          Reverseblock(3,0,128);        
      }
  } 
  
  if(SelfTestTimer>=16 && SelfTestTimer<18)
  {
      outflag=0;
      if(noutflag==0)
      {
          F_BTN_SELFTEST_SDNOUT=1;
          noutflag=1;
      }
  } 
  
  
  
    if(SelfTestTimer>=18 && SelfTestTimer<24)
  {
      NOWPHASE=3;
      noutflag=0;
      if(outflag==0)
      {
          F_BTN_SELFTEST_SDOUT=1;
          outflag=1;
      }
      if(SelfTestTimer%2==0)
      {
          Reverseblock(4,0,128);          
      }
  } 
  
    if(SelfTestTimer>=24 && SelfTestTimer<26)
  {
      outflag=0;
      if(noutflag==0)
      {
          F_BTN_SELFTEST_SDNOUT=1;
          noutflag=1;
      }
  } 
  
   if(SelfTestTimer>=26 && SelfTestTimer<32)
  {
      NOWPHASE=4;
      noutflag=0;
      if(outflag==0)
      {        
          F_BTN_SELFTEST_SDOUT=1;
          outflag=1;
          
      }                  
      if(SelfTestTimer%2==0)
      {
          Reverseblock(5,0,128);
      }
  }  
  
  if(SelfTestTimer>=32 && SelfTestTimer<34)
  {
      outflag=0;
      if(noutflag==0)
      {
          F_BTN_SELFTEST_SDNOUT=1;
          noutflag=1;
      }
  }     
  
  if(SelfTestTimer>=36)
  {
      SelfTestTimer=0;
      TestPhase=2;
      outflag=0;
      noutflag=0;
  }
     
  break;
  case 2:
    lcd_clr_buf();
  line_cnt = 0;
  line_start = 0;
  line_len = SCREENWIDE;
  
  if(LNG==0)
  {
      lcd_ser_chs ("     selftest        ", 21 );
  }
  else
  {  
      lcd_ser_chs ("     正在自检        ", 21 );
  }
  lcd_puts (1, 0);
  line_cnt = 0;
  line_start = 0;
  line_len = SCREENWIDE;
  if(LNG==0)
  {
      lcd_ser_chs ("CoolTemp Wrn       ℃", 21 );
      
  }
  else
  {
      lcd_ser_chs ("水温高预警         ℃", 21 );
  }
  lcd_puts (2, 0); 
  line_cnt = 0;
  line_start = 0;
  line_len = SCREENWIDE; 
  if(LNG==0)
  {   
      lcd_ser_chs ("CoolTemp Sd        ℃", 21 );
      
  }
  else
  {
      
      lcd_ser_chs ("水温过高停机       ℃", 21 );
  }
  lcd_puts (3, 0); 
  line_cnt = 0;
  line_start = 0;
  line_len = SCREENWIDE;  
  if(LNG==0)
  {
      if(ParamValue[141]==7)
      {        
          lcd_ser_chs ("OilTemp Wrn        ℃", 21 );
      }
      else
      {
          lcd_ser_chs ("FuelLevel Wrn       %", 21 );
      }
  }
  else  
  {    
      if(ParamValue[141]==7)
      {          
          lcd_ser_chs ("油温高预警         ℃", 21 );
      }
      else
      {
          lcd_ser_chs ("燃油位低预警        %", 21 );
      }
  }
  lcd_puts (4, 0);
  line_cnt = 0;
  line_start = 0;
  line_len = SCREENWIDE;  
  if(LNG==0)
  {
      if(ParamValue[141]==7)
      {
          lcd_ser_chs ("OilTemp Sd         ℃", 21 );
      }
      else
      {
          lcd_ser_chs ("FuelLevel Sd        %", 21 );
      }
  }
  else
  {   if(ParamValue[141]==7)
      {    
          lcd_ser_chs ("油温过高停机       ℃", 21 );
      }
      else
      {
          lcd_ser_chs ("燃油位低停机        %", 21 );
      }
  }
  lcd_puts (5, 0); 
  lcd_show_number (ParamValue[49], 0,  84,  2);
  lcd_show_number (ParamValue[50], 0,  84,  3);
  lcd_show_number (ParamValue[52], 0,  84,  4);
  lcd_show_number (ParamValue[53], 0,  84,  5);  
  if(SelfTestTimer>=2 && SelfTestTimer<8)
  {  
      NOWPHASE=5;
      noutflag=0;
      if(outflag==0)
      {        
          F_BTN_SELFTEST_SDOUT=1;
          outflag=1;
      }
      if(SelfTestTimer%2==0)
      {
          Reverseblock(2,0,128);          
      }
  }
  
  if(SelfTestTimer>=8 && SelfTestTimer<10)
  {
      outflag=0;
      if(noutflag==0)
      {
          F_BTN_SELFTEST_SDNOUT=1;
          noutflag=1;
      }
  }    
  
   if(SelfTestTimer>=10 && SelfTestTimer<16)
  {
      NOWPHASE=6; 
      noutflag=0; 
      if(outflag==0)
      {        
          F_BTN_SELFTEST_SDOUT=1;
          outflag=1;
      }
      if(SelfTestTimer%2==0)
      {
          Reverseblock(3,0,128);

      }
  } 
  
  if(SelfTestTimer>=16 && SelfTestTimer<18)
  {
      outflag=0;
      if(noutflag==0)
      {
          F_BTN_SELFTEST_SDNOUT=1;
          noutflag=1;
      }
  }    
    
    if(SelfTestTimer>=18 && SelfTestTimer<24)
  {
      NOWPHASE=7;
      noutflag=0;
      if(outflag==0)
      {
          F_BTN_SELFTEST_SDOUT=1;
          outflag=1;
      }
      if(SelfTestTimer%2==0)
      {
          Reverseblock(4,0,128);
    
      }
  } 
  if(SelfTestTimer>=24 && SelfTestTimer<26)
  {
      outflag=0;
      if(noutflag==0)
      {
          F_BTN_SELFTEST_SDNOUT=1;
          noutflag=1;
      }
  }     
     if(SelfTestTimer>=26 && SelfTestTimer<32)
  {
      NOWPHASE=8;
      noutflag=0;
      if(outflag==0)
      {        
          F_BTN_SELFTEST_SDOUT=1;
          outflag=1;
      }
      if(SelfTestTimer%2==0)
      {
          Reverseblock(5,0,128);          
      }
  }  
  
  if(SelfTestTimer>=32 && SelfTestTimer<34)
  {
      outflag=0;
      if(noutflag==0)
      {
          F_BTN_SELFTEST_SDNOUT=1;
          noutflag=1;
      }
  }   
  if(SelfTestTimer>=34)
  {
      SelfTestTimer=0;
      TestPhase=3;
      outflag=0;
      noutflag=0;
  }
    
  break;
  case 3:
  lcd_clr_buf();
  line_cnt = 0;
  line_start = 0;
  line_len = SCREENWIDE;
  
  if(LNG==0)
  {
      lcd_ser_chs ("     selftest        ", 21 );
  }
  else
  {  
      lcd_ser_chs ("     正在自检        ", 21 );
  }
  lcd_puts (1, 0);
  line_cnt = 0;
  line_start = 0;
  line_len = SCREENWIDE;
  if(LNG==0)
  {    
      lcd_ser_chs ("Batt Undervolt      V", 21 );
  }
  else
  {
      lcd_ser_chs ("电池电压低          V", 21 );
  }
  lcd_puts (2, 0); 
  line_cnt = 0;
  line_start = 0;
  line_len = SCREENWIDE;  
  if(LNG==0)
  { 
      lcd_ser_chs ("Batt Overvolt       V", 21 );
  }
  else
  {
      lcd_ser_chs ("电池电压高          V", 21 );
  }
  
  
  lcd_puts (4, 0);
  lcd_show_number (ParamValue[56], 1,  91,  2);
  lcd_show_number (ParamValue[55], 1,  91,  4);
  
  if(SelfTestTimer>=2 && SelfTestTimer<8)
  {
      NOWPHASE=9;
      noutflag=0;
      if(outflag==0)
      {        
          F_BTN_SELFTEST_SDOUT=1;
          outflag=1;
      }
      if(SelfTestTimer%2==0)
      {
          Reverseblock(2,0,128);
      }
  }
   if(SelfTestTimer>=8 && SelfTestTimer<10)
  {
      outflag=0;
      if(noutflag==0)
      {
          F_BTN_SELFTEST_SDNOUT=1;
          noutflag=1;
      }
  }   
   if(SelfTestTimer>=10 && SelfTestTimer<16)
  {
      NOWPHASE=10;  
      noutflag=0;
      if(outflag==0)
      {        
          F_BTN_SELFTEST_SDOUT=1;
          outflag=1;
      }    
      if(SelfTestTimer%2==0)
      {
          Reverseblock(4,0,128);
      }
  } 
   
  if(SelfTestTimer>=16 && SelfTestTimer<18)
  {
      outflag=0;
      if(noutflag==0)
      {
          F_BTN_SELFTEST_SDNOUT=1;
          noutflag=1;
      }
  }   
  if(SelfTestTimer>=18)
  {
      NOWPHASE=0;  
  }
  if(SelfTestTimer>=20)
  {
      SelfTestTimer=0;
      TestPhase=0;
      SelfTestMode=0;
      NowPage=1;
      outflag=0;
      noutflag=0;
  }
  
  break;
 }
 
  line_cnt = 78;
  line_start = 78;
  line_len = 6;
  switch(SplashIcon)
  {
    case 0:
    lcd_ser_chs("-",1);
    break;
    case 1:
    lcd_ser_chs("`",1);
    break;
    case 2:
    lcd_ser_chs("|",1);
    break;
    case 3:
    lcd_ser_chs("/",1);
    break;
    
  }
 lcd_puts (1, 0);
 
 line_cnt = 0;
 line_start = 0;
 line_len = SCREENWIDE;
 lcd_puts (0, 1);


}
static ConfirmProcess(void)
{
    lcd_clr_buf();
    line_cnt = 0;
    line_start = 0;
    line_len = SCREENWIDE;
  
    if(LNG==0)
    {
        if(ConfirmMode==1)
        {        
            lcd_ser_chs ("    Confirm Start    ", 21 );
        }
        else
        {
            lcd_ser_chs ("    Confirm Stop    ", 21 );
        }        
    }
    else
    {
        if(ConfirmMode==1)
        {   
            lcd_ser_chs ("      确认起动       ", 21 );
        }
        else
        {
            lcd_ser_chs ("      确认停机       ", 21 );
        }
    } 
    
    lcd_puts (1, 0);
    
    lcd_clr_buf();
    line_cnt = 0;
    line_start = 0;
    line_len = SCREENWIDE;
  
    if(LNG==0)
    {
        if(ConfirmMode==1)
        {  
            lcd_ser_chs (" Press Enter To Start", 21 );
        }
        else
        {
            lcd_ser_chs (" Press Enter To Stop", 21 );
        }    
    }
    else
    {  
        if(ConfirmMode==1)
        { 
            lcd_ser_chs ("  按Enter键确认起动", 21 );
        }
        else
        {
            lcd_ser_chs ("  按Enter键确认停机", 21 );
        }    
    } 
    
    lcd_puts (3, 0); 
    
    lcd_clr_buf();
    line_cnt = 0;
    line_start = 0;
    line_len = SCREENWIDE;
  
    if(LNG==0)
    {
      lcd_ser_chs (" Page To Cancel   s", 21 );
    }
    else
    {  
      lcd_ser_chs ("  按Page键取消    s  ", 21 );
    } 
    lcd_puts (5, 0);    

   
      lcd_show_number(CONFIRM_DEL,0,79,5);
   
   
        
                                                                              
     
        
    
    
    
    
    line_cnt = 0;
    line_start = 0;
    line_len = SCREENWIDE;
    lcd_puts (0, 1);
   
    
}

void DISP_PAGEMAIN(void)
{
       static char drawinit;
       uchar showsign = 0;
       uchar showsign2 = 0; 
       uchar i;
           double PowerDegree;
    double eX;
    double eY;
    double bX;
    double bY;
        
    static int RndX[91];
    static int RndY[91];
        if (drawinit == 0)
        {
            for (i = 0; i <= 90; i++)
            {
                PowerDegree = (45 - i) * 0.01745329251994;
                RndX[i] = PX - (PLEN + 3) * sin (PowerDegree);
                RndY[i] = PY - (PLEN + 3) * cos (PowerDegree);
            }

            drawinit = 1;
        }

        for (i = 0; i <= 90; i++)
        {
            PowerDegree = (45 - i) * 0.01745329251994;

            if (i == 0 || i == 21 || i == 45 || i == 69 || i == 90)
            {
                eX = PX - (PLEN + 4) * sin (PowerDegree);
                eY = PY - (PLEN + 4) * cos (PowerDegree);
                drawpixel (eX, eY);
                eX = PX - (PLEN + 5) * sin (PowerDegree);
                eY = PY - (PLEN + 5) * cos (PowerDegree);
                drawpixel (eX, eY);
            }

            drawpixel (RndX[i], RndY[i]);
        }

        for (i = 0; i < 5; i++)
        {
            drawpixel (PX + i - 2, PY - 1);
            drawpixel (PX + i - 2, PY);
            drawpixel (PX + i - 2, PY + 1);
        }

        for (i = 0; i < 3; i++)
        {
            drawpixel (PX + i - 1, PY - 2);
            drawpixel (PX + i - 1, PY + 2);
        }

        #if B_MODE
        if(DataValue[22]<0)
        {          
            PowerPercent = 0;
        }
        else
        {
            PowerPercent = (float) DataValue[22] * 100 / (float) ParamValue[12];
        }
        #else
        PowerPercent = (float) DataValue[28] * 10 / (float) ParamValue[3];
        #endif
        
        if (PowerPercent > 100)
        {
            PowerPercent = 100;
        }
        
        
        #if B_MODE
        PowerDegree = (45 - (float) PowerPercent * 0.9) * 0.01745329251994;
        #else
        PowerDegree = (45 - (float) PowerPercent * 0.9) * 0.01745329251994;
        #endif
        eX = PX - PLEN * sin (PowerDegree);
        eY = PY - PLEN * cos (PowerDegree);
        bX = PX - 4 * sin (PowerDegree);
        bY = PY - 4 * cos (PowerDegree);
        Bresenham (eX, eY, bX, bY);
  
        #if B_MODE        
        lcd_show_number (DataValue[22], 0,  6,  5); //显示转速   
        
        if(DataValue[18]!=-32768)     
        {
          lcd_show_number (DataValue[18]/10, 1, 78, 4);  //显示油压
        }
        else
        {
          lcd_show_number (-32768, 1, 78, 4); 
        }
        lcd_show_number (DataValue[16], 0, 84, 5);  //显示水温
        #else
        lcd_show_number (DataValue[22], 0, 82, 5);  //显示转速
        #endif
        
        
        #if GEC16P_MODE
        lcd_show_number (DataValue[19], 0, 84, 4); //显示油温
        #endif
        
        #if FEIERTE_MODE
        lcd_show_number (DataValue[23], 2, 91, 4);                       
        #endif
        
        #if STANDARD_MODE                
        lcd_show_number (DataValue[15], 2, 88, 4); //显示PF
        #endif
        
        
        
        
        #if STANDARD_MODE || FEIERTE_MODE || GEC16P_MODE
        
        if (DataValue[28] < 1000 && DataValue[28] > -1000)
        {
            lcd_show_number (DataValue[28], 1, 12, 5);
        }
        else
        {
            lcd_show_number (DataValue[28] / 10, 0, 12, 5);    //显示功率
        }
        #endif
      

        switch (NowMode)
        {
        case 0:

            if (LNG == 1)
            {
                Reverseblock (1, 0, 12);
            }
            else
            {
                Reverseblock (1, 0, 19);
            }

            break;
        case 1:
            #if B_MODE
            if (LNG == 1)
            {
                Reverseblock (1, 48, 24);
            }
            else
            {
                Reverseblock (1, 48, 19);
            }

            break;
            #else
            
            if (LNG == 1)
            {
                Reverseblock (1, 18, 24);
            }
            else
            {
                Reverseblock (1, 24, 19);
            }
            break;
            #endif
            
        case 3:
            #if B_MODE            
            if (LNG == 1)
            {
                Reverseblock (1, 18, 24);
            }
            else
            {
                Reverseblock (1, 24, 19);
            }
            break;
            #else         
            if (LNG == 1)
            {
                Reverseblock (1, 48, 24);
            }
            else
            {
                Reverseblock (1, 48, 19);
            }

            break;
            #endif
        case 2:

            if (LNG == 1)
            {
                Reverseblock (1, 78, 24);
            }
            else
            {
                Reverseblock (1, 72, 25);
            }

            break;
        }
        
        if(ParamValue[16])
        {
            line_cnt = 104;
            line_start = 104;
            line_len = 128 - 104;
            lcd_clr_buf();

            if (LNG == 1)
            {
                lcd_ser_chs ("应急", strlen ("应急") );
            }
            else
            {
                lcd_ser_chs ("EMER", strlen ("EMER") );
            }   
            
            lcd_puts (1, 0);     
            Reverseblock (1, 103, 25);
        }
        
        //画方框
        Bresenham (1, 13, 57, 13);
        Bresenham (57, 13, 57, 60);
        Bresenham (1, 13, 1, 60);
        Bresenham (1, 60, 57, 60);

        if (STA_DES_CRANKING)
        {
            line_cnt = 64;
            line_start = 64;
            line_len = 128 - 64;
            lcd_clr_buf();

            if (LNG == 1)
            {
                lcd_ser_chs ("启动输出", strlen ("启动输出") );
            }
            else
            {
                lcd_ser_chs ("Starting", strlen ("Starting") );
            }

            lcd_puts (3, 0);
            showsign = 1;
        }

        if (STA_DES_STOP && STA_DES_CRANKING == 0)
        {
            line_cnt = 64;
            line_start = 64;
            line_len = 128 - 64;
            lcd_clr_buf();

            if (STA_DES_ALARMS == 0)
            {
                if (LNG == 1)
                {
                    lcd_ser_chs ("已预备", strlen ("已预备") );
                }
                else
                {
                    lcd_ser_chs ("Ready", strlen ("Ready") );
                }
            }
            else
            {
                if (LNG == 1)
                {
                    lcd_ser_chs ("未预备", strlen ("未预备") );
                }
                else
                {
                    lcd_ser_chs ("Not ready", strlen ("Not ready") );
                }
            }

            if (showsign == 0)
            {
                lcd_puts (3, 0);
            }

            showsign = 1;
        }

        if (STA_DES_RUNNING && STA_DES_START_IDLE == 0 && STA_DES_STOP_IDLE == 0 && STA_DES_STOPING == 0)
        {
            line_cnt = 64;
            line_start = 64;
            line_len = 128 - 64;
            lcd_clr_buf();

            if (LNG == 1)
            {
                lcd_ser_chs ("机组运行", strlen ("机组运行") );
            }
            else
            {
                lcd_ser_chs ("Gen running", strlen ("Gen running") );
            }

            if (showsign == 0)
            {
                lcd_puts (3, 0);
            }

            showsign = 1;
        }

        if (STA_DES_STOP_IDLE)
        {
            line_cnt = 64;
            line_start = 64;
            line_len = 128 - 64;
            lcd_clr_buf();

            if (LNG == 1)
            {
                lcd_ser_chs ("冷却停机中", strlen ("冷却停机中") );
            }
            else
            {
                lcd_ser_chs ("Cooling", strlen ("Cooling") );
            }

            if (showsign == 0)
            {
                lcd_puts (3, 0);
            }

            showsign = 1;
        }   
        
        if (STA_DES_STOPING && ALA_STOP_FAIL == 0)
        {
            line_cnt = 64;
            line_start = 64;
            line_len = 128 - 64;
            lcd_clr_buf();

            if (LNG == 1)
            {
                lcd_ser_chs ("停机中", strlen ("停机中") );
            }
            else
            {
                lcd_ser_chs ("Shutting", strlen ("Shutting") );
            }

            if (showsign == 0)
            {
                lcd_puts (3, 0);
            }

            showsign = 1;
        }
                     
        if (STA_DES_START_IDLE)
        {
            line_cnt = 64;
            line_start = 64;
            line_len = 128 - 64;
            lcd_clr_buf();

            if (LNG == 1)
            {
                lcd_ser_chs ("怠速运行", strlen ("怠速运行") );
            }
            else
            {
                lcd_ser_chs ("Idle", strlen ("Idle") );
            }

            if (showsign == 0)
            {
                lcd_puts (3, 0);
            }

            showsign = 1;
        }





        if (STA_DES_STARTINT)
        {
            line_cnt = 64;
            line_start = 64;
            line_len = 128 - 64;
            lcd_clr_buf();

            if (LNG == 1)
            {
                lcd_ser_chs ("起动间隔", strlen ("起动间隔") );
            }
            else
            {
                lcd_ser_chs ("Restarting", strlen ("Restarting") );
            }

            if (showsign == 0)
            {
                lcd_puts (3, 0);
            }

            showsign = 1;
        }

        if (ALA_STOP_FAIL)
        {
            line_cnt = 64;
            line_start = 64;
            line_len = 128 - 64;
            lcd_clr_buf();

            if (LNG == 1)
            {
                lcd_ser_chs ("停机失败", strlen ("停机失败") );
            }
            else
            {
                lcd_ser_chs ("Stop fail", strlen ("Stop fail") );
            }

            if (showsign == 0)
            {
                lcd_puts (3, 0);
            }

            showsign = 1;
        }

        if (STA_DES_PREHEAT)
        {
            line_cnt = 64;
            line_start = 64;
            line_len = 128 - 64;
            lcd_clr_buf();

            if (LNG == 1)
            {
                
                
                lcd_ser_chs ("正在预启动", strlen ("正在预启动") );
                
            }
            else
            {
                
                
                lcd_ser_chs ("Pre-start", strlen ("Pre-start") );
            }

            lcd_puts (2, 0);
            showsign2 = 1;
        }

    
}
void DISP_PAGEDES(void)
{                       
        lcd_show_number (DataValue[20], 1, 90, 2); 
                        
        if(ParamValue[90]==1)
        {
            Clearline(2);
            Clearline(3); 
            if(LNG==0)
            {
              lcd_clr_buf();
              line_cnt=0;
              line_start=0;
              line_len=128;            
              lcd_ser_chs("Battery Volt        V",21);
              lcd_puts(2,0);            
            }
            else
            {
              lcd_clr_buf();
              line_cnt=0;
              line_start=0;
              line_len=128;            
              lcd_ser_chs("蓄电池电压          V",21);
              lcd_puts(2,0);            
            }
            lcd_show_number (DataValue[20], 1, 90, 2);                    
        }
        else
        {
            lcd_show_number (DataValue[21], 1, 90, 3); 
        }
        
        
        
        
        
        if(ParamValue[20])
        {
            lcd_show_number (DataValue[23], 1, 90, 4);        
        }
        else if(ParamValue[14])
        {
        Clearline(4);
            if(LNG==0)
            {
            Clearline(4);
            lcd_clr_buf();
            line_cnt=0;
            line_start=0;
            line_len=128;            
            lcd_ser_chs("WaterPressure     bar",21);
            lcd_puts(4,0);            
            }
            else
            {
            Clearline(4);
            lcd_clr_buf();
            line_cnt=0;
            line_start=0;
            line_len=128;            
            lcd_ser_chs("水压              bar",21);
            lcd_puts(4,0);            
            }
            if(DataValue[25]!=-32768)
            {              
                lcd_show_number(DataValue[25]/10, 1, 78, 4); 
            }
            else
            {
                lcd_show_number(-32768, 1, 78, 4); 
            }
        }
        else
        {
        Clearline(4);
        }
        
        
        
        
        if(ParamValue[19])
        {   
            lcd_show_number (DataValue[8], 0, 90, 5);  
        }
        else if(ParamValue[97])   //燃油压力显示
        {
        Clearline(5);
            if(LNG==0)
            {
            Clearline(5);
            lcd_clr_buf();
            line_cnt=0;
            line_start=0;
            line_len=128;            
            lcd_ser_chs("FuelPressure      bar",21);
            lcd_puts(5,0);            
            }
            else
            {
            Clearline(5);
            lcd_clr_buf();
            line_cnt=0;
            line_start=0;
            line_len=128;            
            lcd_ser_chs("燃油压力          bar",21);
            lcd_puts(5,0);            
            }
            if(DataValue[120]!=-32768)
            {              
                lcd_show_number(DataValue[120]/10, 1, 78, 5); 
            }
            else
            {
                lcd_show_number(-32768, 1, 78, 5); 
            }
        }
        
        else
        {
        Clearline(5);
        }
                                                    
        if(ParamValue[141]==7)
        {                  
        if(DataValue[19]!=-32768)
        {
            //DrawValuePercent (DataValue[19], ParamValue[50]+20, 4, 39, 120);
            lcd_show_number (DataValue[19] , 0, 84, 1);    
        }
        else
        {
            //DrawValuePercent (0, 100, 4, 39, 120);
            lcd_show_number (-32768 , 0, 84, 1); 
        }
        }
        else
        {
            
            if(LNG==0)
            {
            Clearline(1);
            lcd_clr_buf();
            line_cnt=0;
            line_start=0;
            line_len=128;            
            lcd_ser_chs("FUEL     L          %",21);
            lcd_puts(1,0);            
            }
            else
            {
            Clearline(1);
            lcd_clr_buf();
            line_cnt=0;
            line_start=0;
            line_len=128;            
            lcd_ser_chs("液位     L          %",21);
            lcd_puts(1,0);            
            }

        if(DataValue[17]!=-32768)
        {
            //DrawValuePercent (DataValue[19], ParamValue[50]+20, 4, 39, 120);
            lcd_show_number (DataValue[17] , 0, 84, 1);    
            lcd_show_number (DataValue[24] , 0, 24, 1);   
        }
        else
        {
            //DrawValuePercent (0, 100, 4, 39, 120);
            lcd_show_number (-32768 , 0, 84, 1); 
            lcd_show_number (-32768 , 0, 24, 1);
        }        
        
        }                                          
}

void DISP_PAGEDI_1(void)
{

        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (126, ParamValue[125]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (1, 0);
        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (127, ParamValue[126]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (2, 0);
        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (128, ParamValue[127]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (3, 0);
        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (129, ParamValue[128]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (4, 0);
        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (130, ParamValue[129]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (5, 0);

        if (INPUTVALUE & 0x01)
        {
            lcd_show_number (1, 0, 97, 1);
        }
        else
        {
            lcd_show_number (0, 0, 97, 1);
        }

        if (INPUTVALUE & 0x02)
        {
            lcd_show_number (1, 0, 97, 2);
        }
        else
        {
            lcd_show_number (0, 0, 97, 2);
        }

        if (INPUTVALUE & 0x04)
        {
            lcd_show_number (1, 0, 97, 3);
        }
        else
        {
            lcd_show_number (0, 0, 97, 3);
        }

        if (INPUTVALUE & 0x08)
        {
            lcd_show_number (1, 0, 97, 4);
        }
        else
        {
            lcd_show_number (0, 0, 97, 4);
        }

        if (INPUTVALUE & 0x10)
        {
            lcd_show_number (1, 0, 97, 5);
        }
        else
        {
            lcd_show_number (0, 0, 97, 5);
        }
    
}
void DISP_PAGEDI_2(void)
{

        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (131, ParamValue[130]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (1, 0);
        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (132, ParamValue[131]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (2, 0);
        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (132, ParamValue[160]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (3, 0);

        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (132, ParamValue[161]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (4, 0);

        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (132, ParamValue[162]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (5, 0);

        if (INPUTVALUE & 0x20)
        {
            lcd_show_number (1, 0, 97, 1);
        }
        else
        {
            lcd_show_number (0, 0, 97, 1);
        }

        if (INPUTVALUE & 0x40)
        {
            lcd_show_number (1, 0, 97, 2);
        }
        else
        {
            lcd_show_number (0, 0, 97, 2);
        }
        
        if (INPUTVALUE & 0x80)
        {
            lcd_show_number (1, 0, 97, 3);
        }
        else
        {
            lcd_show_number (0, 0, 97, 3);
        }
        if (INPUTVALUE & 0x100)
        {
            lcd_show_number (1, 0, 97, 4);
        }
        else
        {
            lcd_show_number (0, 0, 97, 4);
        }
        if (INPUTVALUE & 0x200)
        {
            lcd_show_number (1, 0, 97, 5);
        }
        else
        {
            lcd_show_number (0, 0, 97, 5);
        }                        
        
        
    
}
void DISP_PAGEDI_3(void)
{

        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (131, ParamValue[163]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (1, 0); 
        if (INPUTVALUE & 0x400)
        {
            lcd_show_number (1, 0, 97, 1);
        }
        else
        {
            lcd_show_number (0, 0, 97, 1);
        }   
    
}
void DISP_PAGEDO_1(void)
{
  
        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (133, ParamValue[132]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (1, 0);
        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (134, ParamValue[133]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (2, 0);
        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (135, ParamValue[134]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (3, 0);
        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (136, ParamValue[135]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (4, 0);
        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (137, ParamValue[136]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (5, 0);

        if (OUTPUTVALUE & 0x01)
        {
            lcd_show_number (1, 0, 97, 1);
        }
        else
        {
            lcd_show_number (0, 0, 97, 1);
        }

        if (OUTPUTVALUE & 0x02)
        {
            lcd_show_number (1, 0, 97, 2);
        }
        else
        {
            lcd_show_number (0, 0, 97, 2);
        }

        if (OUTPUTVALUE & 0x04)
        {
            lcd_show_number (1, 0, 97, 3);
        }
        else
        {
            lcd_show_number (0, 0, 97, 3);
        }

        if (OUTPUTVALUE & 0x08)
        {
            lcd_show_number (1, 0, 97, 4);
        }
        else
        {
            lcd_show_number (0, 0, 97, 4);
        }

        if (OUTPUTVALUE & 0x10)
        {
            lcd_show_number (1, 0, 97, 5);
        }
        else
        {
            lcd_show_number (0, 0, 97, 5);
        }
        
        
        
    
}
void DISP_PAGEDO_2(void)
{

        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (138, ParamValue[137]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (1, 0);
        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (139, ParamValue[138]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (2, 0);

        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (139, ParamValue[164]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (3, 0);

        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (139, ParamValue[165]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (4, 0);

        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (139, ParamValue[166]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (5, 0);

        if (OUTPUTVALUE & 0x20)
        {
            lcd_show_number (1, 0, 97, 1);
        }
        else
        {
            lcd_show_number (0, 0, 97, 1);
        }

        if (OUTPUTVALUE & 0x40)
        {
            lcd_show_number (1, 0, 97, 2);
        }
        else
        {
            lcd_show_number (0, 0, 97, 2);
        }
        if (OUTPUTVALUE & 0x80)
        {
            lcd_show_number (1, 0, 97, 3);
        }
        else
        {
            lcd_show_number (0, 0, 97, 3);
        }
        if (OUTPUTVALUE & 0x100)
        {
            lcd_show_number (1, 0, 97, 4);
        }
        else
        {
            lcd_show_number (0, 0, 97, 4);
        }
        if (OUTPUTVALUE & 0x200)
        {
            lcd_show_number (1, 0, 97, 5);
        }
        else
        {
            lcd_show_number (0, 0, 97, 5);
        }                        
    
}
void DISP_PAGEDO_3(void)
{
 
    
            line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (139, ParamValue[167]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (1, 0);

        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (139, ParamValue[168]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (2, 0);

        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (139, ParamValue[169]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (3, 0);    
        line_cnt = 0;
        lcd_clr_buf();
        pointchar = GetParamString (139, ParamValue[170]);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (4, 0);          
        
        
        if (OUTPUTVALUE & 0x400)
        {
            lcd_show_number (1, 0, 97, 1);
        }
        else
        {
            lcd_show_number (0, 0, 97, 1);
        }   
        if (OUTPUTVALUE & 0x800)
        {
            lcd_show_number (1, 0, 97, 2);
        }
        else
        {
            lcd_show_number (0, 0, 97, 2);
        } 
        if (OUTPUTVALUE & 0x1000)
        {
            lcd_show_number (1, 0, 97, 3);
        }
        else
        {
            lcd_show_number (0, 0, 97, 3);
        } 
        if (OUTPUTVALUE & 0x2000)
        {
            lcd_show_number (1, 0, 97, 4);
        }
        else
        {
            lcd_show_number (0, 0, 97, 4);
        }                         
    
}
void DISP_PAGEACC(void)
{
        #if B_MODE
        lcd_show_number (DataValue[50], 0, 90, 1);
        lcd_show_number (DataValue[52], 0, 96, 2);
        lcd_show_number (DataValue[54], 0, 96, 3);
        #endif
}

void DISP_PAGEALARM(void)
{
        
        line_cnt = 0;
        pointchar = &AlarmStrings[0].line1[0];
        
        strchar = pointchar + ALAWINDOW[9-ALARMPAGE*4] * 23;
        lcd_clr_buf();
        lcd_ser_chs (strchar, strlen (strchar) );
        lcd_puts (2, 0);

        if (ALACONFIRM[9-ALARMPAGE*4] == 0)
        {
            Reverseblock (2, 0, GetLineNum (strchar) );
        }
        
        line_cnt = 0;
        strchar=pointchar+ALAWINDOW[8-ALARMPAGE*4]*23;
        lcd_clr_buf();
        lcd_ser_chs(strchar,strlen(strchar));
        lcd_puts(3,0);
        
        if(ALACONFIRM[8-ALARMPAGE*4]==0)
        {
            Reverseblock(3,0,GetLineNum(strchar));
        }
        line_cnt = 0;
        strchar=pointchar+ALAWINDOW[7-ALARMPAGE*4]*23;
        lcd_clr_buf();
        lcd_ser_chs(strchar,strlen(strchar));
        lcd_puts(4,0);
        if(ALACONFIRM[7-ALARMPAGE*4]==0)
        {
            Reverseblock(4,0,GetLineNum(strchar));
        }
        line_cnt = 0;
        strchar=pointchar+ALAWINDOW[6-ALARMPAGE*4]*23;
        lcd_clr_buf();
        lcd_ser_chs(strchar,strlen(strchar));
        lcd_puts(5,0);
        if(ALACONFIRM[6-ALARMPAGE*4]==0)
        {
            Reverseblock(5,0,GetLineNum(strchar));
        }
            
}
void DISP_PAGECOIL(void)
{
lcd_show_number (DataValue[26] , 0, 84, 1); 
lcd_show_number (DataValue[27] , 0, 84, 2); 
lcd_show_number (DataValue[28] , 0, 84, 3); 
lcd_show_number (DataValue[29] , 0, 84, 4); 

}
PUBLIC void lcd_disp_status (void)
{
    static uchar lastmode;
    uint  baseoffset = 0;
    unsigned long *tmplong;


    char i;
    uchar showsign = 0;
    uchar showsign2 = 0;
    static char lastpage;
    typPGPointer Page_Status_P1;
   
    lastpage = NowPage;
    lcd_clr_page();

    
    if(ParamValue[7])
    {
        D423MODE=1;
        D223MODE=0;
       PageP1.Pagept[0]=&Page_Status_P1_EN_D4[0].line1[0];
       PageP1.Pagept[1]=&Page_Status_P1_CN_D4[0].line1[0];
    }
    else
    {
        D423MODE=0;
        D223MODE=1;  
        PageP1.Pagept[0]=&Page_Status_P1_EN_D2[0].line1[0];
        PageP1.Pagept[1]=&Page_Status_P1_CN_D2[0].line1[0];        
    }
    
    
//{
//0,
//
//&Page_Status_P1_CN[0].line1[0],
//};
  
    if(SelfTestMode!=lastmode)
    {
        FLAG_BTNGCB=1;
        FLAG_BTNMCB=1;
    }
    lastmode=SelfTestMode;
     
      
    if(SelfTestMode)
    {
        SelfTestProcess();
        return;
    }
    
    if(ConfirmMode)
    {
        ConfirmProcess();
        return;
    }
    
    if(NowPage<=PageShow.PageNums)
    {      
        pointchar = PageShow.Pages[NowPage-1]->Pagept[LNG];
    }
    
    if(NowPage==20)
    {
        pointchar = &LngPage[0].line1[0]; 
    }
    


    if (initnum < 180)
    {
        pointchar = &Page_Status_P0[0].line1[0];
    }

    
    
    if(STA_DES_PREHEAT||STA_DES_CRANKING||STA_DES_STARTINT)
    {
        NowPage=1;
        if(LNG==0)
        {          
            pointchar=&Page_Start_Status1_EN[0].line1[0];
        }
        else
        {
            pointchar=&Page_Start_Status1_CN[0].line1[0];
        }
    }
  
    for (i = 0; i < 5; i++)
    {
        lcd_clr_buf();
        line_cnt = 0;
        lcd_ser_chs (pointchar, strlen (pointchar) );
        line_start = 0;
        line_len = SCREENWIDE;
        lcd_puts (i + 1, 0);
        pointchar += 23;
    }

    if (initnum < 180)
    {
        line_start = 0;
        line_len = SCREENWIDE;
        lcd_puts (0, 1);
        return;
    }

    

    if(STA_DES_PREHEAT||STA_DES_CRANKING||STA_DES_STARTINT)
    {

        if(NowMode==1)
        {
            lcd_clr_buf();
            line_cnt = 0;
            if(LNG==1)
            {              
                lcd_ser_chs ("本地起动", 8 );
            }
            else
            {
                lcd_ser_chs ("MAN START", 9 );
            }
            line_start = 0;
            line_len = SCREENWIDE;
            lcd_puts (2, 0);
        }
        
        if(NowMode==2)
        {
            lcd_clr_buf();
            line_cnt = 0;            
            if(LNG==1)
            {              
                lcd_ser_chs ("自动起动", 8 );
            }
            else
            {
                lcd_ser_chs ("AUTO START", 10);
            }
            line_start = 0;
            line_len = SCREENWIDE;
            lcd_puts (2, 0);
        }        
        if(NowMode==3)
        {
            lcd_clr_buf();
            line_cnt = 0;            
            if(LNG==1)
            {              
                lcd_ser_chs ("遥控起动", 8 );
            }
            else
            {
                lcd_ser_chs ("RMT START", 9 );
            }
            line_start = 0;
            line_len = SCREENWIDE;
            lcd_puts (2, 0);
        }         
        if(STA_DES_PREHEAT)
        {
            lcd_clr_buf();
            line_cnt = 0;
            
            if(LNG==1)
            {
                if(STA_DES_LUB)
                {
                    lcd_ser_chs ("正在预润滑",10  );
                }
                else
                {                  
                    lcd_ser_chs ("正在预起动",10  );
                }
            }
            else
            {              
                if(STA_DES_LUB)
                {
                    lcd_ser_chs ("PRE-STARTING",12  );
                }
                else
                {                  
                    lcd_ser_chs ("PRE-LUB.",7  );
                }
            }
            line_start = 0;
            line_len = 60;
            lcd_puts (3, 0);
            lcd_show_number(DataValue[7],0,78,3);            
        }
        
        if(STA_DES_CRANKING)
        {
            lcd_clr_buf();
            line_cnt = 0;
            if(LNG==1)
            {              
                lcd_ser_chs ("正在起动",8  );
            }
            else
            {
                lcd_ser_chs ("CRANKING",8  );
            }
            line_start = 0;
            line_len = 48;
            lcd_puts (3, 0);
            lcd_show_number(DataValue[4],0,78,3);
        } 
        
        if(STA_DES_STARTINT)
        {
            lcd_clr_buf();
            line_cnt = 0;
            if(LNG==1)
            {
                lcd_ser_chs ("起动间隔",8  );
            }
            else
            {
                lcd_ser_chs ("START INTERVAL",14  );
            }
            line_start = 0;
            line_len = 48;
            lcd_puts (3, 0);
            lcd_show_number(DataValue[5],0,78,3);
        } 
                
        lcd_show_number(DataValue[6],0,0,4);
        
        line_start = 0;
        line_cnt = 0;
        line_len=SCREENWIDE;
        lcd_ser_chs ("     RPM      V     V",21);
        lcd_puts (5, 0);
        
        
        lcd_show_number(DataValue[22],0,0,5);
        lcd_show_number(DataValue[20],1,54,5);
        lcd_show_number(DataValue[21],1,90,5);        
        line_cnt = 0;       
        line_start = 0;
        line_len = SCREENWIDE;
        lcd_puts (0, 1);
        return;
    }


    if (NowPage == 1)
    {
    
    DISP_PAGEMAIN();
    
    }

    if (NowPage == 2)
    {
    
    
    
    }

    if (NowPage == 3)
    {}

    if (NowPage == 4)
    {
        DISP_PAGECOIL();
    }

    if (NowPage == 5)
    {
        DISP_PAGEDES();  
    }

    if (NowPage == 6)
    {
    
    }
    if (NowPage == 7)
    {
        DISP_PAGEDI_1();
    }


    if (NowPage == 8)
    {
        DISP_PAGEDI_2();
    }
    if(NowPage==9)     
    {
        DISP_PAGEDI_3();
    }

    if (NowPage == 10)

    {
        DISP_PAGEDO_1();
    }


    if (NowPage == 11)
    {
        DISP_PAGEDO_2();
    }
    if (NowPage == 12)
    {
        DISP_PAGEDO_3();
    }
    
  
    if (NowPage == 13)
    {
        DISP_PAGEACC();
    }

    if (NowPage == PAGEALARM)
    {
       DISP_PAGEALARM();
    }

    if (NowPage == 15)
    {
        lcd_show_number (DataValue[23] / 10, 1, 78, 1);
        lcd_show_number (DataValue[24] / 100, 1, 90, 2);
        lcd_show_number (DataValue[19], 0, 84, 3);

        if (DataValue[25] >= 0)
        {
            lcd_show_number (DataValue[25], 0, 84, 4);
        }
        else
        {
            lcd_show_number (-32768, 1, 84, 4);
        }

        lcd_show_number (DataValue[44], 0, 60, 5);
    }

    if (NowPage == 20)
    {
        line_cnt = 0;
        line_start = 0;
        line_len = 6;
        lcd_ser_chs (">", 1);

        if (LngCursor == 0)
        {
            lcd_puts (2, 0);
        }
        else
        {
            lcd_puts (3, 0);
        }
    }

    line_start = 0;
    line_len = SCREENWIDE;
    lcd_puts (0, 1);
}








//主菜单页面
PUBLIC void lcd_disp_setup (void)
{
    uint  baseoffset;
    unsigned char i;
    line_cnt = 0;
    
    lcd_clr_page();
    
    //lcd_puts(0,1);
    
   if(lcd_passwordlevel2)
   {
       lcd_clr_buf();
       line_cnt = 0;
       line_start = 0;       
       line_len=128;
       if(LNG==1)
       {        
           lcd_ser_chs("    请输入高级密码",strlen("    请输入高级密码"));
       }
       else
       {
           lcd_ser_chs("Input level2 Password",strlen("Input level2 Password"));
       }
       lcd_puts (1, 0);
       lcd_show_number (TmpParam,0, 46, 3);
       line_cnt = 0;
       line_start = 0;       
       line_len=127;       
       lcd_puts (0, 1);
       return;
       
   }
    
    lcd_clr_buf();    
    line_cnt = 0;
    line_start = 0;
    line_len = 6;                    
    lcd_ser_chs (">", strlen (">") ); 
    lcd_puts (lcd_disp_cursor_setup, 0);
    baseoffset = (lcd_disp_point_setup - lcd_disp_cursor_setup);// * 23;
    line_cnt = 0;
    line_start = 6;
    line_len = 122;
     
    //pointchar= &MAINMENU.StrPtr[0].line1[0+baseoffset];


       
     for (i=0;i<5;i++)
     {
         if(baseoffset+i<SUBMENU_NUM)
         {
         if(LNG==0)
         {          
         pointchar=MAINMENU.SubPtr[baseoffset+i]->ptNameStrEN;
         }
         else
         {
         pointchar=MAINMENU.SubPtr[baseoffset+i]->ptNameStrCN;
         }
         line_cnt = 0;
         lcd_clr_buf();
         lcd_ser_chs (pointchar,23);   
         lcd_puts (i+1, 0);
         }
         //pointchar+=23;     
     }
    
    line_start = 0;
    line_len = SCREENWIDE;
    lcd_puts (0, 1);
}

//子菜单显示页面

PUBLIC void lcd_disp_setup_submenu (void)
{
    uint  baseoffset;         //字串偏移量
    uint ParamOffset;
    uchar ParamMode;
    // unsigned char *pointchar; //显示字串指针变量
    uchar i;
    uchar shownum;            //显示参数字串列表数
    lcd_disp_ParamNum = 0;
   lcd_clr_page();
   if(lcd_passwordlevel2)
   {
       lcd_clr_buf();
       line_cnt = 0;
       line_start = 0;       
       line_len=128;
       if(LNG==1)
       {        
           lcd_ser_chs("    请输入高级密码",strlen("    请输入高级密码"));
       }
       else
       {
           lcd_ser_chs("Input level2 Password",strlen("Input level2 Password"));
       }
       lcd_puts (1, 0);
       lcd_show_number (TmpParam,0, 46, 3);
       line_cnt = 0;
       line_start = 0;       
       line_len=127;       
       lcd_puts (0, 1);
       return;
       
   }
    line_cnt = 0;
    
    line_start = 6;
    line_len = 122;
    baseoffset = ( (uint) lcd_disp_point_submenu - (uint) lcd_disp_cursor_submenu) * 23;
    

    if(LNG==1)
    {        
        pointchar=&MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->NameStrCN;    
    }
    else
    {   
        pointchar=&MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->NameStrEN;    
    }
    lcd_clr_buf();
    lcd_ser_chs (pointchar, strlen (pointchar) );
    lcd_puts (1, 0);
    line_cnt = 0;
    lcd_clr_buf();
    
    if(LNG==1)
    {
        pointchar=&MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->NameStrCN;       
    }
    else
    {
        pointchar=&MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->NameStrEN;       
    }
    lcd_ser_chs (pointchar, strlen (pointchar) );
    lcd_puts (3, 0);
    line_cnt = 0;
    line_start = 0;
    line_len = 6;
    lcd_ser_chs (">", strlen (">") );
    
    lcd_puts (lcd_disp_cursor_submenu * 2 - 1, 0);
    
            

    if (ParamValue[202] == 360 || ParamValue[202] == 332 || ParamValue[202] == 335 || ParamValue[202] == 337 || ParamValue[202] == 338) //6800ECU设置温度模式
    {
        TEMPMODE = 1;
    }
    else
    {
        TEMPMODE = 0;
    }


    lcd_disp_ParamNum=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-1]->ValueOffset;
    
    //写参数
    if (lcd_disp_ParamConfirm == 1 && SENDFLAG == 0)
    {
       
          
        lcd_disp_ParamNum=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-1]->ValueOffset;
      
        
        switch (lcd_disp_ParamNum)
        {
        case 108:
            SciWriteParam (205, &TIMEDATA[0], 2);
            break;
        case 109:
            SciWriteParam (207, &YEARDATA[0], 3);
            break;
        default:

            if (TEMPMODE == 1 && lcd_disp_ParamNum == 204)
            {
                TmpParam = (TmpParam * 10) + 32768;
            }

            ParamValue[lcd_disp_ParamNum] = TmpParam;
            SciWriteParam (lcd_disp_ParamNum , &ParamValue[lcd_disp_ParamNum], 1);
            //LocalValue[lcd_disp_cursor_submenu-1] = TmpParam;
            lcd_disp_ParamConfirm=0;
            break;
            
        }
    }




    if (MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->Mode < 5)
    {
        if (lcd_disp_ParamNum != 0 && lcd_disp_ParamNum != 1)
        {
        ParamOffset=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->ValueOffset;
        ParamMode=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->Mode;
        lcd_show_number (ParamValue[ParamOffset],ParamMode, 76, 2);
        }
    }
    else
    {
        lcd_clr_buf();
        if(LNG==0)
        {          
        pointchar = MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->ParamStrEN; //取显示字串
        }
        else
        {
        pointchar = MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->ParamStrCN; //取显示字串
        }
        
        ParamOffset=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->ValueOffset;
        
        if(lcd_disp_ParamNum - lcd_disp_cursor_submenu  +1 != 112 && \
        lcd_disp_ParamNum - lcd_disp_cursor_submenu  +1!= 116 &&\
        lcd_disp_ParamNum - lcd_disp_cursor_submenu  +1!= 118 &&\
        lcd_disp_ParamNum - lcd_disp_cursor_submenu  +1!= 119 )
        {
            pointchar+= ParamValue[ParamOffset]*23;    
        }
        
        
        line_cnt = 127 - GetLineNum (pointchar);                 //取字串占列数并右对齐，计算初始列
        line_start = 127 - GetLineNum (pointchar);
        line_len = GetLineNum (pointchar);line_len = GetLineNum (pointchar);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        
        
        lcd_puts (2, 0);

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu +1 == 108)
        {
            lcd_show_number (TIMESET_SECOND, 0, 96, 2);
        }

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu +1== 108)
        {
            lcd_show_number (TIMESET_MINUTE, 0, 78, 2);
        }

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu +1== 108)
        {
            lcd_show_number (TIMESET_HOUR, 0, 60, 2);
        }

        if (lcd_disp_ParamNum==109 && lcd_disp_cursor_submenu== 1 ||\
        lcd_disp_ParamNum==118 && lcd_disp_cursor_submenu == 2)
        {
            lcd_show_number (TIMESET_YEAR, 0, 96, 2);
            lcd_show_number (TIMESET_DATE, 0, 78, 2);
            lcd_show_number (TIMESET_MONTH, 0, 60, 2);
        }


        
        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu  +1== 112)
        {
            lcd_show_number (0, 0, 96, 2);
        }

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu  +1== 112)
        {
            lcd_show_number (Timer1Start % 60, 0, 78, 2);
        }

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu  +1== 112)
        {
            lcd_show_number (Timer1Start / 60, 0, 60, 2);
        }
               
        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu  +1== 116)
        {
            lcd_show_number (0, 0, 96, 2);
        }

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu  +1== 116)
        {
            lcd_show_number (Timer2Start % 60, 0, 78, 2);
        }

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu  +1== 116)
        {
            lcd_show_number (Timer2Start / 60, 0, 60, 2);
        }
        
        if(lcd_disp_ParamNum==118 && lcd_disp_cursor_submenu==1||\
        lcd_disp_ParamNum==119 && lcd_disp_cursor_submenu==2)          
        {
            lcd_show_number (0, 0, 96, 2);
            lcd_show_number (TimeInhibitOn % 60, 0, 78, 2);
            lcd_show_number (TimeInhibitOn / 60, 0, 60, 2);
        }
        
        if(lcd_disp_ParamNum==119 && lcd_disp_cursor_submenu==1||\
        lcd_disp_ParamNum==120 && lcd_disp_cursor_submenu==2)          
        {
            lcd_show_number (0, 0, 96, 2);
            lcd_show_number (TimeInhibitOff % 60, 0, 78, 2);
            lcd_show_number (TimeInhibitOff / 60, 0, 60, 2);
        }
        
    }

    if (MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->Mode < 5)
    {
        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu + 2 != 204)
        {
            if (lcd_disp_ParamNum != 0 && lcd_disp_ParamNum != 1)
            {
                ParamOffset=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->ValueOffset;
                ParamMode=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->Mode;
                lcd_show_number (ParamValue[ParamOffset], ParamMode, 76, 4);
            }
        }
        else
        {
            ECUDATANUMBER = (unsigned int) ParamValue[lcd_disp_ParamNum-lcd_disp_cursor_submenu+1];

            if (TEMPMODE)
            {
                ECUDATANUMBER = (int) (ECUDATANUMBER - 32768) / 10;
                //！！！！！
                //lcd_show_number ( (int) ECUDATANUMBER, ParamType[lcd_disp_ParamNum-lcd_disp_cursor_submenu+2], 76, 4);
                lcd_show_number ( (int) ECUDATANUMBER, ParamMode, 76, 4);
            }
            else
            {
                lcd_show_number_lng (ECUDATANUMBER, 0, 66, 4);
            }
        }
    }
    else
    {
        lcd_clr_buf();
   //     pointchar = GetParamString (lcd_disp_ParamNum - lcd_disp_cursor_submenu + 2, ParamValue[lcd_disp_ParamNum-lcd_disp_cursor_submenu+1]); //取显示字串
        if(LNG==0)
        {
        pointchar = MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->ParamStrEN; //取显示字串
        }
        else
        {
        pointchar = MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->ParamStrCN; //取显示字串
        }
        ParamOffset=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->ValueOffset;
       
        if(lcd_disp_ParamNum - lcd_disp_cursor_submenu  +2 != 112 && \
        lcd_disp_ParamNum - lcd_disp_cursor_submenu  +2!= 116 &&\
        !(lcd_disp_ParamNum==118 && lcd_disp_cursor_submenu ==1)&&\
        !(lcd_disp_ParamNum==119 && lcd_disp_cursor_submenu ==2) &&\
        !(lcd_disp_ParamNum==109 && lcd_disp_cursor_submenu ==1)&&\
        !(lcd_disp_ParamNum==118 && lcd_disp_cursor_submenu ==2)
         )
        {
            pointchar+= ParamValue[ParamOffset]*23;    
        }
        
        //pointchar+= ParamValue[ParamOffset]*23;      
        line_cnt = 127 - GetLineNum (pointchar);                 //取字串占列数并右对齐，计算初始列        
        line_start = 127 - GetLineNum (pointchar);
        line_len = GetLineNum (pointchar);
        lcd_ser_chs (pointchar, strlen (pointchar) );
        lcd_puts (4, 0);

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu + 2 == 108)
        {
            lcd_show_number (TIMESET_SECOND, 0, 96, 4);
        }

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu + 2 == 108)
        {
            lcd_show_number (TIMESET_MINUTE, 0, 78, 4);
        }

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu + 2 == 108)
        {
            lcd_show_number (TIMESET_HOUR, 0, 60, 4);
        }

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu + 2 == 109)
        {
            lcd_show_number (TIMESET_YEAR, 0, 96, 4);
        }

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu + 2 == 109)
        {
            lcd_show_number (TIMESET_DATE, 0, 78, 4);
        }

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu + 2 == 109)
        {
            lcd_show_number (TIMESET_MONTH, 0, 60, 4);
        }
        
        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu + 2 == 112)
        {
            lcd_show_number (0, 0, 96, 4);
        }

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu + 2 == 112)
        {
            lcd_show_number (Timer1Start % 60, 0, 78, 4);
        }

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu + 2 == 112)
        {
            lcd_show_number (Timer1Start / 60, 0, 60, 4);
        }  
        
        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu + 2 == 116)
        {
            lcd_show_number (0, 0, 96, 4);
        }

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu + 2 == 116)
        {
            lcd_show_number (Timer2Start % 60, 0, 78, 4);
        }

        if (lcd_disp_ParamNum - lcd_disp_cursor_submenu + 2 == 116)
        {
            lcd_show_number (Timer2Start / 60, 0, 60, 4);
        } 
        
        
        if(lcd_disp_ParamNum==109 && lcd_disp_cursor_submenu==1||\
        lcd_disp_ParamNum==118 && lcd_disp_cursor_submenu==2)        
        {
            lcd_show_number (0, 0, 96, 4);
            lcd_show_number (TimeInhibitOn % 60, 0, 78, 4);
            lcd_show_number (TimeInhibitOn / 60, 0, 60, 4);
        }
        
        if(lcd_disp_ParamNum==118 && lcd_disp_cursor_submenu==1||\
        lcd_disp_ParamNum==119 && lcd_disp_cursor_submenu==2)        
        {
            lcd_show_number (0, 0, 96, 4);
            lcd_show_number (TimeInhibitOff % 60, 0, 78, 4);
            lcd_show_number (TimeInhibitOff / 60, 0, 60, 4);
        }        
        
    }


    if(MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->Mode!=255)
    {
      
    pointchar=&MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->ScaleStr;       

    {
        lcd_clr_buf();
        line_cnt = 109;
        line_start = 109;
        line_len = 18;  
        if (strlen (pointchar) > 1)
        {
            lcd_ser_chs (pointchar, 3), lcd_puts (2, 0);
        }
    }
    }
    if(MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->Mode!=255)
    {
      
    pointchar=&MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->ScaleStr;       

    {
        lcd_clr_buf();
        line_cnt = 109;
        line_start = 109;
        line_len = 18;  
        if (strlen (pointchar) > 1)
        {
            lcd_ser_chs (pointchar, 3), lcd_puts (4, 0);
        }
    }
    }


/*
    if (ParamValue[141] == 7 || (ECUSTATUS & 0x01 && HW_MODE) )
    {
        if ( ( (lcd_disp_ParamNum == 53 || lcd_disp_ParamNum == 54) && lcd_disp_cursor_submenu == 2) || ( (lcd_disp_ParamNum == 52 || lcd_disp_ParamNum == 53) && lcd_disp_cursor_submenu == 1) )
        {
            lcd_clr_buf();
            line_cnt = 109;
            line_start = 109;
            line_len = 18;
            lcd_ser_chs (" ℃", strlen (" ℃") );
            lcd_puts (4, 0);
        }

        if ( ( (lcd_disp_ParamNum == 54 || lcd_disp_ParamNum == 55) && lcd_disp_cursor_submenu == 2) || ( (lcd_disp_ParamNum == 54 || lcd_disp_ParamNum == 53) && lcd_disp_cursor_submenu == 1) )
        {
            lcd_clr_buf();
            line_cnt = 109;
            line_start = 109;
            line_len = 18;
            lcd_ser_chs (" ℃", strlen (" ℃") );
            lcd_puts (2, 0);
        }
    }
  */
    if (lcd_disp_ParamMode == 2)    //编辑模式
    {   
        
        if(lcd_disp_cursor_submenu==1)
        {          
            ParamMode=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->Mode;
            ParamOffset=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->ValueOffset;       
            if(LNG==0)
            {              
            pointchar=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->ParamStrEN;       
            }
            else
            {
            pointchar=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu]->ParamStrCN;
            }
        }
        else
        {
            ParamMode=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->Mode;
            ParamOffset=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->ValueOffset;       
            if(LNG==0)
            {              
            pointchar=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->ParamStrEN;       
            }
            else
            {
            pointchar=MAINMENU.SubPtr[lcd_disp_point_setup-1]->SubItems[lcd_disp_point_submenu-lcd_disp_cursor_submenu+1]->ParamStrCN;       
            }
        }
        
        
        if (ParamMode < 5)
        {
            lcd_show_number (TmpParam, ParamMode, 6, 0);
        }
        else
        {
            line_cnt = 0;
            lcd_clr_buf();
            if(lcd_disp_ParamNum!=108&&\
             lcd_disp_ParamNum!=109&& \
             lcd_disp_ParamNum!=112&& \
             lcd_disp_ParamNum!=116&& \
             lcd_disp_ParamNum!=118&& \
             lcd_disp_ParamNum!=119) 
            {                          
                pointchar += TmpParam*23;
            }
            lcd_ser_chs (pointchar, strlen (pointchar) );
            line_start = 0;
            line_len = SCREENWIDE;
        }


        if (lcd_disp_cursor_submenu == 1)
        {
            if (ParamMode == 255)
            {
                Clearline (2);
            }

            lcd_puts (2, 0);

            if (lcd_disp_ParamNum == 108)
            {
                lcd_show_number (TIMESET_SECOND, 0, 36, 2);
            }

            if (lcd_disp_ParamNum == 108)
            {
                lcd_show_number (tmpminute, 0, 18, 2);
            }

            if (lcd_disp_ParamNum == 108)
            {
                lcd_show_number (tmphour, 0, 0, 2);
            }

            if (lcd_disp_ParamNum == 108)
            {
                lcd_show_number (tmpyear, 0, 36, 2);
            }

            if (lcd_disp_ParamNum == 109)
            {
                lcd_show_number (tmpdate, 0, 18, 2);
            }

            if (lcd_disp_ParamNum == 109)
            {
                lcd_show_number (tmpmonth, 0, 0, 2);
            }
            
            if (lcd_disp_ParamNum == 112||lcd_disp_ParamNum == 116 || lcd_disp_ParamNum == 118||lcd_disp_ParamNum == 119)
            {
                lcd_show_number (0, 0, 36, 2);
            }

            if (lcd_disp_ParamNum == 112||lcd_disp_ParamNum == 116 || lcd_disp_ParamNum == 118||lcd_disp_ParamNum == 119)
            {
                lcd_show_number (TmpParam % 60, 0, 18, 2);
            }

            if (lcd_disp_ParamNum == 112||lcd_disp_ParamNum == 116 || lcd_disp_ParamNum == 118||lcd_disp_ParamNum == 119)
            {
                lcd_show_number (TmpParam / 60, 0, 0, 2);
            }
            
            
            
            
            
        }
        else
        {
            if (ParamMode == 255)
            {
                Clearline (4);
            }

            lcd_puts (4, 0);

            if (lcd_disp_ParamNum == 108)
            {
                lcd_show_number (TIMESET_SECOND, 0, 36, 4);
            }

            if (lcd_disp_ParamNum == 108)
            {
                lcd_show_number (tmpminute, 0, 18, 4);
            }

            if (lcd_disp_ParamNum == 108)
            {
                lcd_show_number (tmphour, 0, 0, 4);
            }

            if (lcd_disp_ParamNum == 109)
            {
                lcd_show_number (tmpyear, 0, 36, 4);
            }

            if (lcd_disp_ParamNum == 109)
            {
                lcd_show_number (tmpdate, 0, 18, 4);
            }

            if (lcd_disp_ParamNum == 109)
            {
                lcd_show_number (tmpmonth, 0, 0, 4);
            }
            
            if (lcd_disp_ParamNum == 112||lcd_disp_ParamNum == 116 || lcd_disp_ParamNum == 118||lcd_disp_ParamNum == 119)
            {
                lcd_show_number (0, 0, 36, 4);
            }

            if (lcd_disp_ParamNum == 112||lcd_disp_ParamNum == 116 || lcd_disp_ParamNum == 118||lcd_disp_ParamNum == 119)
            {
                lcd_show_number (TmpParam % 60, 0, 18, 4);
            }

            if (lcd_disp_ParamNum == 112||lcd_disp_ParamNum == 116 || lcd_disp_ParamNum == 118||lcd_disp_ParamNum == 119)
            {
                lcd_show_number (TmpParam / 60, 0, 0, 4);
            }
            
            
            
            
            
        }
    }

    line_start = 0;
    line_len = SCREENWIDE;
    lcd_puts (0, 1);
}

PRIVATE void lcd_disp_history (void)
{
    RECORD MYREC;
    static FLAGSTR tmpdata1;
    static FLAGSTR tmpdata2;
    static FLAGSTR tmpdata3;
    static LASTRECPT;
    //unsigned char *pointchar;//显示字串指针变量
    //unsigned char *strchar;
    unsigned char i;
    FLAGSTR IODATA;
    unsigned char NOWIO;
    lcd_clr_page();

    if (lcd_disp_recmode == 0)
    {
        tmpdata1.Byte = RECDATA2;
        tmpdata2.Byte = RECDATA3;
        tmpdata3.Byte = RECDATA4;
        line_cnt = 25;
        line_start = 25;
        line_len = SCREENWIDE - 25;
        pointchar = &AlarmStrings[0].line1[0];
        strchar = pointchar + (uint) tmpdata1.BYTES.BYTEL * 23;
        lcd_clr_buf();
        lcd_ser_chs (strchar, strlen (strchar) );
        lcd_puts (2, 0);
        line_cnt = 25;
        line_start = 25;
        line_len = SCREENWIDE - 25;
        pointchar = &AlarmStrings[0].line1[0];
        strchar = pointchar + (uint) tmpdata2.BYTES.BYTEL * 23;
        lcd_clr_buf();
        lcd_ser_chs (strchar, strlen (strchar) );
        lcd_puts (3, 0);
        line_cnt = 25;
        line_start = 25;
        line_len = SCREENWIDE - 25;
        pointchar = &AlarmStrings[0].line1[0];
        strchar = pointchar + (uint) tmpdata3.BYTES.BYTEL * 23;
        lcd_clr_buf();
        lcd_ser_chs (strchar, strlen (strchar) );
        lcd_puts (4, 0);
        line_cnt = 0;
        line_start = 0;
        line_len = SCREENWIDE;
        lcd_clr_buf();

        if (LNG == 0)
        {
            lcd_ser_chs ("History Record", strlen ("History Record") );
        }
        else
        {
            lcd_ser_chs ("编号原因", strlen ("编号原因") );
        }

        lcd_puts (1, 0);
        pointchar = &Stringlist_CN[32].line3[0];
        lcd_ser_chs (pointchar, strlen (pointchar) );
        line_start = 0;
        line_len = SCREENWIDE;
        lcd_puts (5, 0);
        line_cnt = 0;
        line_start = 0;
        line_len = 6;
        lcd_clr_buf();
        lcd_ser_chs (">", strlen (">") );
        lcd_puts (lcd_rec_cursor, 0);
        lcd_show_number (tmpdata1.BYTES.BYTEH, 0, -6, 2);
        lcd_show_number (tmpdata2.BYTES.BYTEH, 0, -6, 3);
        lcd_show_number (tmpdata3.BYTES.BYTEH, 0, -6, 4);
        MYREC.ARRAY[2] = * (RECDETAIL + 2);
        MYREC.ARRAY[3] = * (RECDETAIL + 3);
        MYREC.ARRAY[4] = * (RECDETAIL + 4);
        lcd_show_number (MYREC.MEMBER.TimeL.BITS4.L4, 0, 0, 5);
        lcd_show_number (MYREC.MEMBER.DateH.BITS4.L4 + MYREC.MEMBER.DateH.BITS4.H4 * 10, 0, 18, 5);
        lcd_show_number (MYREC.MEMBER.DateL.BITS4.L4 + MYREC.MEMBER.DateL.BITS4.H4 * 10, 0, 36, 5);
        lcd_show_number (MYREC.MEMBER.TimeH.BITS4.L4 + MYREC.MEMBER.TimeH.BITS4.H4 * 10, 0, 96, 5);
        lcd_show_number (MYREC.MEMBER.Time2.BITS4.L4 + MYREC.MEMBER.Time2.BITS4.H4 * 10, 0, 78, 5);
        lcd_show_number (MYREC.MEMBER.Time3.BITS4.L4 + MYREC.MEMBER.Time3.BITS4.H4 * 10, 0, 60, 5);
    }

    if (lcd_disp_recmode == 1)
    {
        line_cnt = 0;
        line_start = 0;
        line_len = SCREENWIDE;
        lcd_clr_buf();

        if (LNG == 0)
        {
            lcd_ser_chs (" Detail information", strlen (" Detail information") );
        }
        else
        {
            lcd_ser_chs ("      故障信息", strlen ("      故障信息") );
        }

        lcd_puts (1, 0);
        pointchar = &RecDetailPage[0].line1[0];
        showstr1 = pointchar + (uint) lcd_disp_recpage * 4 * 23;
        showstr2 = showstr1 + 23;
        showstr3 = showstr2 + 23;
        showstr4 = showstr3 + 23;
        line_cnt = 0;
        line_start = 0;
        line_len = SCREENWIDE;
        lcd_clr_buf();
        lcd_ser_chs (showstr1, strlen (showstr1) );
        lcd_puts (2, 0);
        line_cnt = 0;
        line_start = 0;
        line_len = SCREENWIDE;
        lcd_clr_buf();
        lcd_ser_chs (showstr2, strlen (showstr2) );
        lcd_puts (3, 0);
        line_cnt = 0;
        line_start = 0;
        line_len = SCREENWIDE;
        lcd_clr_buf();
        lcd_ser_chs (showstr3, strlen (showstr3) );
        lcd_puts (4, 0);
        line_cnt = 0;
        line_start = 0;
        line_len = SCREENWIDE;
        lcd_clr_buf();
        lcd_ser_chs (showstr4, strlen (showstr4) );
        lcd_puts (5, 0);

        switch (lcd_disp_recpage)
        {
        case 0:
            pointchar = &Stringlist[1].line1[0] + * (RECDETAIL + 5) * 23;
            line_cnt = 103;
            line_start = 103;
            line_len = SCREENWIDE - 103;
            lcd_clr_buf();
            lcd_ser_chs (pointchar, strlen (pointchar) );
            lcd_puts (2, 0);
            lcd_show_number (* (RECDETAIL + 6), 0, 78, 3);
            lcd_show_number (* (RECDETAIL + 18), 1, 90, 4);//电池电压1
            lcd_show_number (* (RECDETAIL + 19), 1, 90, 5);//电池电压2
            
            break;
        case 1:
            lcd_show_number (* (RECDETAIL + 20), 0, 78, 2);//油压
            lcd_show_number (* (RECDETAIL + 21), 0, 84, 3);
            lcd_show_number (* (RECDETAIL + 22), 0, 90, 4);
            lcd_show_number (* (RECDETAIL + 23), 0, 84, 5);            

            break;
        case 2:
            IODATA.Byte = * (RECDETAIL + 24);
            for (i = 0; i < 11; i++)
            {
                switch (i)
                {
                case 0:

                    if (IODATA.Bits.bit8)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;
                case 1:

                    if (IODATA.Bits.bit9)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;
                case 2:

                    if (IODATA.Bits.bita)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;
                case 3:

                    if (IODATA.Bits.bitb)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;
                case 4:

                    if (IODATA.Bits.bitc)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;
                case 5:

                    if (IODATA.Bits.bitd)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;
                case 6:

                    if (IODATA.Bits.bite)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;
                case 7:

                    if (IODATA.Bits.bitf)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;
                case 8:

                    if (IODATA.Bits.bit0)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break; 
                case 9:

                    if (IODATA.Bits.bit1)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;
                case 10:

                    if (IODATA.Bits.bit2)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;                                                                               
                }
                

                line_cnt = i * 6 ;
                line_start = i * 6 ;
                line_len = 6;
                lcd_clr_buf();

                if (NOWIO)
                {
                    lcd_ser_chs ("1", strlen ("1") );
                }
                else
                {
                    lcd_ser_chs ("0", strlen ("0") );
                }

                lcd_puts (3, 0);
            }

            IODATA.Byte = * (RECDETAIL + 17);

            for (i = 0; i < 14; i++)
            {
                switch (i)
                {
                case 0:

                    if (IODATA.Bits.bit8)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;
                case 1:

                    if (IODATA.Bits.bit9)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;
                case 2:

                    if (IODATA.Bits.bita)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;
                case 3:

                    if (IODATA.Bits.bitb)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;
                case 4:

                    if (IODATA.Bits.bitc)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;
                case 5:

                    if (IODATA.Bits.bitd)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;
                case 6:

                    if (IODATA.Bits.bite)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;
                case 7:

                    if (IODATA.Bits.bitf)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;  
                case 8:

                    if (IODATA.Bits.bit0)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;  
                case 9:

                    if (IODATA.Bits.bit1)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;     
                case 10:

                    if (IODATA.Bits.bit2)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;  
                case 11:

                    if (IODATA.Bits.bit3)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;   
                case 12:

                    if (IODATA.Bits.bit4)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;   
                case 13:

                    if (IODATA.Bits.bit5)
                    {
                        NOWIO = 1;
                    }
                    else
                    {
                        NOWIO = 0;
                    }

                    break;                                                                                                                                 
                }

                line_cnt = i * 6 ;
                line_start = i * 6 ;
                line_len = 6;
                lcd_clr_buf();

                if (NOWIO)
                {
                    lcd_ser_chs ("1", strlen ("1") );
                }
                else
                {
                    lcd_ser_chs ("0", strlen ("0") );
                }

                lcd_puts (5, 0);
            }

            
        }
    }

    line_cnt = 0;
    line_start = 0;
    line_len = SCREENWIDE;
    lcd_puts (0, 1);
    LASTRECPT = RECPT;
}



//************************************************************************************
//函数名称：  lcd_display()
//功能描述：  display lcd
//输入参数：
//输出参数：
//************************************************************************************
PUBLIC void lcd_display (void)
{
    //  lcd_clear();
    lcd_disp_page = 0;
    line_cnt      = 0;
    F_CLR_LCD           = 1;

    //  lcd_clr_buf();
    if ( (lcd_disp_mode & 0x0f) >= 0x03)
    {
        lcd_disp_mode &= 0xc0;
    }

    if (lcd_disp_ParamMode == 0)
    {
        switch (lcd_disp_mode & 0x0f)
        {
        case 0x00:
            lcd_state = lcd_disp_status;
            break;
        case 0x01:
            lcd_state = lcd_disp_setup;
            break;
        case 0x02:
            lcd_state = lcd_disp_history;
            break;
        case 0x03:
            //          lcd_ser_chs("市电",strlen("市电"));
            //          lcd_puts(2,0);
            //      lcd_state = lcd_disp_main;
            break;
        case 0x04:
            //          lcd_ser_chs("负载",strlen("负载"));
            //          lcd_puts(2,0);
            //  lcd_state = lcd_disp_load;
            break;
        case 0x05:
            //          lcd_ser_chs("关于",strlen("关于"));
            //          lcd_puts(2,0);
            //          lcd_state = lcd_disp_about;
            break;
        }
    }
    else if (lcd_disp_ParamMode >= 1)
    {
        lcd_state = lcd_disp_setup_submenu;
    }
}


void ChangeLng (uchar LngType)
{
   
    switch (LngType)
    {
    case 0:
        /*
        Page_Status_P1          = Page_Status_P1_EN;
        Page_Status_P2          = Page_Status_P2_EN;
        Page_Status_P3          = Page_Status_P3_EN;
        Page_Status_P4          = Page_Status_P4_EN;
        Page_Status_P5          = Page_Status_P5_EN;
        Page_Status_P6          = Page_Status_P6_EN;
        Page_Status_P11         = Page_Status_P11_EN;
        Page_Status_P12         = Page_Status_P12_EN;
        Page_Status_P13         = Page_Status_P13_EN;
        Page_Status_P14         = Page_Status_P14_EN;
        Page_Status_P15         = Page_Status_P15_EN;
        */
        RecDetailPage           = RecDetailPage_EN;        
        Stringlist              = Stringlist_EN;
        AlarmStrings            = AlarmStrings_EN;
        break;
    case 1:
        /*
        Page_Status_P1          = Page_Status_P1_CN;
        Page_Status_P2          = Page_Status_P2_CN;
        Page_Status_P3          = Page_Status_P3_CN;
        Page_Status_P4          = Page_Status_P4_CN;
        Page_Status_P5          = Page_Status_P5_CN;
        Page_Status_P6          = Page_Status_P6_CN;
        Page_Status_P11         = Page_Status_P11_CN;
        Page_Status_P12         = Page_Status_P12_CN;
        Page_Status_P13         = Page_Status_P13_CN;
        Page_Status_P14         = Page_Status_P14_CN;
        Page_Status_P15         = Page_Status_P15_CN;
        */
        RecDetailPage           = RecDetailPage_CN;        
        Stringlist              = Stringlist_CN;
        AlarmStrings            = AlarmStrings_CN;
        break;
    }
   
}

void CheckMenu(void)
{
uchar i=0;
uchar j=0;
#if FEIERTE_MODE
if(ParamValue[96]==0)
{
    SUBMENU_BASIC.MaxItem=14;
    SUBMENU_ENGINE.MaxItem=18;
    for(i=0;i<14;i++)
    {           
        SUBMENU_BASIC.SubItems[i]=&PARAMS_BASIC[i];
    }
    
    for(i=0;i<18;i++)
    {           
        SUBMENU_ENGINE.SubItems[i]=&PARAMS_ENGINE[i];
    }             
}
else
{
    SUBMENU_BASIC.MaxItem=10;
    SUBMENU_ENGINE.MaxItem=17;
    for(i=0;i<10;i++)
    {      
        if(j==2)
        {
            j=4;
        }
       if(j==12)
        {
            j=13;
        }        
        SUBMENU_BASIC.SubItems[i]= &PARAMS_BASIC[j];
        j++;
    }
    
    j=0;
    
    for(i=0;i<17;i++)
    {     
        if(j==6)
        {
            j=7;
        }
        SUBMENU_ENGINE.SubItems[i]=&PARAMS_ENGINE[j];
        j++;
    } 
    
}






#endif
}
