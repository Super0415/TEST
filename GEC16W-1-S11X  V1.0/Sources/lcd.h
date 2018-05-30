#ifndef _LCD_H
#define _LCD_H

#define PAGEMAIN  1
#define PAGEDES   5
#define PAGECOIL  4
#define PAGEDI_1  7
#define PAGEDI_2  8
#define PAGEDI_3  9
#define PAGEDO_1  10
#define PAGEDO_2  11
#define PAGEDO_3  12
#define PAGEACC   13
#define PAGEALA   14

#define PX 29
#define PY 45
#define PLEN 25

PUBLIC volatile uchar D423MODE;
PUBLIC volatile uchar D223MODE;

PUBLIC uchar TestPhase; 
PUBLIC volatile LCD_SCREEN    lcd_state;
PUBLIC unsigned char lcd_disp_page;
PUBLIC unsigned char lcd_disp_mode;
PUBLIC unsigned char lcd_disp_cursor_setup;  //参数设置主菜单游标
PUBLIC unsigned char lcd_disp_point_setup;   //参数设置主菜单指针
PUBLIC unsigned char lcd_disp_cursor_submenu;//子菜单游标
PUBLIC unsigned char lcd_disp_point_submenu; //子菜单指针
PUBLIC unsigned char lcd_disp_ParamMode;     //菜单编辑模式     0：主菜单 1：子菜单 2：子菜单编辑模式
PUBLIC unsigned char lcd_disp_ParamConfirm;
PUBLIC unsigned int  lcd_disp_ParamNum;
PUBLIC unsigned char lcd_disp_recpage;
PUBLIC unsigned char lcd_disp_recmode;
PUBLIC unsigned char lcd_passwordlevel2;
PUBLIC unsigned char lcd_passwordlevel2value;
PUBLIC unsigned char lcd_rec_cursor;
PUBLIC uint ECUDATANUMBER;
PUBLIC uchar TEMPMODE;
PUBLIC long TmpParam;
PUBLIC void lcd_display(void);
PUBLIC void lcd_disp_status(void);
PUBLIC void lcd_disp_engine(void);
PUBLIC void lcd_disp_gen(void);
PUBLIC void lcd_disp_main(void);
PUBLIC void lcd_disp_load(void);
PUBLIC void lcd_disp_about(void);
PUBLIC void lcd_disp_setup(void);
PUBLIC void lcd_disp_setup_submenu(void);
PUBLIC void ChangeLng(uchar LngType);
PUBLIC void DrawValuePercent(int Nowvalue,int FullValue,uchar posx,uchar posy);
PUBLIC void CheckMenu(void);
//extern unsigned char MENUCOUNT[];
#endif
