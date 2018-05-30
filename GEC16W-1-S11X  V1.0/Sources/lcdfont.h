

#ifndef	_LCDFONT_H
#define	_LCDFONT_H
//#pragma CONST_SEG DEFAULT
#define ASC_CH_WIDTH	6
#define ASC_CH_HEIGHT	16

#include "defs.h"
#include "extern.h"

#define LNGMAX 2

#if B_MODE
#define SUBMENU_NUM 9
#endif

#if FEIERTE_MODE
#define SUBMENU_NUM 12
#endif

#if GEC16P_MODE
#define SUBMENU_NUM 11
#endif

 typedef struct
{
  uchar line1[23];
  uchar line2[23];
  uchar line3[23];
  uchar line4[23];
  uchar line5[23];
} const typPG;

typedef const typPG *__far  typPGPointer;

typedef struct
{
uchar Mode;        //参数类型，255为字符串
const uchar NameStrCN[23]; //名称字符串指针(中文)
const uchar NameStrEN[23]; //名称字符串指针(英文)
uchar ScaleStr[5]; //单位字符串
uchar *__far ParamStrCN;   //参数字符串显示指针
uchar *__far ParamStrEN;
//uchar ParamStrEN[23];   //参数字符串显示指针
long MinValue;     //最小值
long MaxValue;     //最大值
long DefaultValue; //默认值
uint ValueOffset;  //数据偏移
}const ParamStruct;


//typedef typPG *__far PagePtr;
typedef const ParamStruct *__far ParamPtr;

typedef struct
{
uchar *__far ptNameStrCN; //名称字符串指针(中文)
uchar *__far ptNameStrEN; //名称字符串指针(英文)
uint          MaxItem;  //最大项目数
//uint         NowItem;  //当前选择
//uint         NowCursor;//当前页面光标
ParamPtr     SubItems[30]; //子菜单参数指针
}SubMenu;

typedef const SubMenu *__far SubMenuPtr;

typedef struct
{
//uchar        MaxItem;   
uchar        MENUNUM;   //子菜单数
//uchar       NowItem;  //当前选择
//uchar       NowCursor;//当前页面光标
//typPGPointer StrPtr;    //页面指针
SubMenuPtr   SubPtr[SUBMENU_NUM];  //子菜单指针
}MainMenu;


typedef struct                  
{
    uchar Disable;
    //typPGPointer Pagept[LNGMAX];
    uchar *__far Pagept[LNGMAX];
}Page;

typedef Page *__far PagePtr;

typedef struct
{
uchar PageNums;
PagePtr Pages[20];
}MainPage;

  


#define Page_Param_Pass           Page_Param_Pass_POINT
#define Page_Param_Basic          Page_Param_Basic_POINT
#define Page_Param                Page_Param_POINT
#define Page_Param_Des            Page_Param_Des_POINT 
#define Page_Param_DesProtect     Page_Param_DesProtect_POINT 
#define Page_Param_GenProtect     Page_Param_GenProtect_POINT 
#define Page_Param_AMF            Page_Param_AMF_POINT 
#define Page_Param_EXIO           Page_Param_EXIO_POINT 
#define Page_Param_DateTime       Page_Param_DateTime_POINT 
#define Page_Param_SensorAdjust   Page_Param_SensorAdjust_POINT 
#define Page_Param_SMS            Page_Param_SMS_POINT
#define Page_Param_CUSTOMIO       Page_Param_CUSTOMIO_POINT 
#define Page_Param_CUSTOMCURVE    Page_Param_CUSTOMCURVE_POINT 
#define Page_Param_ECU            Page_Param_ECU_POINT 

#define Page_Status_P2            Page_Status_P2_POINT 
#define Page_Status_P3            Page_Status_P3_POINT 
#define Page_Status_P4            Page_Status_P4_POINT 
#define Page_Status_P5            Page_Status_P5_POINT 
#define Page_Status_P6            Page_Status_P6_POINT 
#define Page_Status_P11           Page_Status_P11_POINT 
#define Page_Status_P12           Page_Status_P12_POINT 
#define Page_Status_P13           Page_Status_P13_POINT 
#define Page_Status_P14           Page_Status_P14_POINT 
#define Page_Status_P15           Page_Status_P15_POINT 
#define RecDetailPage             RecDetailPage_POINT   
#define Stringlist                Stringlist_POINT 
#define AlarmStrings              AlarmStrings_POINT

#pragma push
#pragma #pragma DATA_SEG DEFAULT_RAM
extern typPGPointer Page_Param_Pass_POINT;//=Page_Param_Pass_CN;//=Page_Param_Pass_CN[];
extern typPGPointer Page_Param_Basic_POINT;
extern typPGPointer Page_Param_POINT;
extern typPGPointer Page_Param_Des_POINT;
extern typPGPointer Page_Param_DesProtect_POINT;
extern typPGPointer Page_Param_GenProtect_POINT;
extern typPGPointer Page_Param_AMF_POINT;
extern typPGPointer Page_Param_EXIO_POINT;
extern typPGPointer Page_Param_DateTime_POINT;
extern typPGPointer Page_Param_SensorAdjust_POINT;
extern typPGPointer Page_Param_SMS_POINT;
extern typPGPointer Page_Param_CUSTOMIO_POINT;
extern typPGPointer Page_Param_CUSTOMCURVE_POINT;
extern typPGPointer Page_Param_ECU_POINT;
extern typPGPointer Page_Status_P1_POINT;
extern typPGPointer Page_Status_P2_POINT;
extern typPGPointer Page_Status_P3_POINT;
extern typPGPointer Page_Status_P4_POINT;
extern typPGPointer Page_Status_P5_POINT;
extern typPGPointer Page_Status_P6_POINT;
extern typPGPointer Page_Status_P11_POINT;
extern typPGPointer Page_Status_P12_POINT;
extern typPGPointer Page_Status_P13_POINT;
extern typPGPointer Page_Status_P14_POINT;
extern typPGPointer Page_Status_P15_POINT;
extern typPGPointer RecDetailPage_POINT;
extern typPGPointer Stringlist_POINT;
extern typPGPointer AlarmStrings_POINT;
extern MainMenu MAINMENU;
extern MainPage PageShow;
extern const typPG DI_Stringlist_EN[];
extern const typPG DI_Stringlist_CN[];
#pragma pop



#pragma push
#pragma CONST_SEG __GPAGE_SEG PAGE_1
extern const ParamStruct PARAMS_PASS[];
extern const ParamStruct PARAMS_BASIC[];
extern const ParamStruct PARAMS_ENGINE[];
extern const ParamStruct PARAMS_ENGINE_PROTECT[];
extern const ParamStruct PARAMS_GEN_PROTECT[];
extern const ParamStruct PARAMS_TIMEDATE[];
extern const ParamStruct PARAMS_SENSOR_ADJUST[];
extern const ParamStruct PARAMS_CUSTOMIO[];
extern const ParamStruct PARAMS_SENSORCURVE[];
extern const ParamStruct PARAMS_CHARGE_SETTING[];
extern const ParamStruct PARAMS_AMF[];
extern const ParamStruct PARAMS_PID[];
extern const ParamStruct PARAMS_REFRESHOIL[];
extern const ParamStruct PARAMS_CUSTOMDI_POL[];
#pragma pop

extern SubMenu SUBMENU_AMF;
extern SubMenu SUBMENU_PID;
extern SubMenu SUBMENU_CHARGEPARAM;
extern SubMenu SUBMENU_PASS;
extern SubMenu SUBMENU_BASIC;
extern SubMenu SUBMENU_ENGINE;
extern SubMenu SUBMENU_ENGINE_PROTECT;
extern SubMenu SUBMENU_GEN_PROTECT;
extern SubMenu SUBMENU_TIMEDATE;
extern SubMenu SUBMENU_SENSOR_ADJUST;
extern SubMenu SUBMENU_CUSTOMIO;
extern SubMenu SUBMENU_SENSORCURVE;
extern SubMenu SUBMENU_REFRESHOIL;
extern SubMenu SUBMENU_DI_POL;





extern Page PageP1;
extern Page PageP2;
extern Page PageP3;
extern Page PageP4;
extern Page PageP5;
extern Page PageP6;
extern Page PageP7;
extern Page PageP8;
extern Page PageP9;
extern Page PageP10;
extern Page PageP11;
extern Page PageP12;
extern Page PageP13;
extern Page PageP14;



#pragma CONST_SEG __GPAGE_SEG PAGE_1

//参数显示      
extern const typPG    Stringlist_CN[];
extern const typPG    Stringlist_EN[];

//报警字符串
extern const typPG    AlarmStrings_CN[];
extern const typPG    AlarmStrings_EN[];
 
//单位字符串 
extern const unsigned char   ScaleStringlist1[18][5];
extern const unsigned char   ScaleStringlist2[22][5]; 
extern const unsigned char   ScaleStringlist3[16][5]; 
extern const unsigned char   ScaleStringlist4[15][5];  
extern const unsigned char   ScaleStringlist5[13][5];  
extern const unsigned char   ScaleStringlist6[12][5];  
extern const unsigned char   ScaleStringlist7[14][5];
#if FEIERTE_MODE
extern const unsigned char   ScaleStringlist8[21][5];
#else
extern const unsigned char   ScaleStringlist8[14][5];
#endif






extern const typPG   Page_Param_CN[];
extern const typPG   Page_Param_EN[];
#pragma CONST_SEG __GPAGE_SEG PAGE_2
extern const typPG   Page_Param_Pass_CN[];
extern const typPG   Page_Param_Pass_EN[];

extern const typPG   Page_Param_Basic_CN[];
extern const typPG   Page_Param_Basic_EN[];

extern const typPG   Page_Param_Des_CN[];
extern const typPG   Page_Param_Des_EN[];

extern const typPG   Page_Param_DesProtect_CN[];
extern const typPG   Page_Param_DesProtect_EN[];

extern const typPG   Page_Param_GenProtect_CN[];
extern const typPG   Page_Param_GenProtect_EN[];

extern const typPG   Page_Param_AMF_CN[];
extern const typPG   Page_Param_AMF_EN[];

extern const typPG   Page_Param_EXIO_CN[];
extern const typPG   Page_Param_EXIO_EN[];


extern const typPG   Page_Param_DateTime_CN[];
extern const typPG   Page_Param_DateTime_EN[];

 
extern const typPG   Page_Param_SensorAdjust_CN[];
extern const typPG   Page_Param_SensorAdjust_EN[];

extern const typPG   Page_Param_SMS_CN[];
extern const typPG   Page_Param_SMS_EN[];


extern const typPG   Page_Param_CUSTOMIO_CN[];
extern const typPG   Page_Param_CUSTOMIO_EN[];


extern const typPG   Page_Param_CUSTOMCURVE_CN[];
extern const typPG   Page_Param_CUSTOMCURVE_EN[];

extern const typPG   Page_Param_ECU_CN[];
extern const typPG   Page_Param_ECU_EN[];

extern const typPG    Page_Status_P0[];
   
extern const typPG  Page_Status_P1_CN_D4[];
extern const typPG  Page_Status_P1_EN_D4[];
extern const typPG  Page_Status_P1_CN_D2[];
extern const typPG  Page_Status_P1_EN_D2[];

extern const typPG  Page_Status_P2_CN[];
extern const typPG  Page_Status_P2_EN[];


extern const typPG  Page_Status_P3_CN[];
extern const typPG  Page_Status_P3_EN[];

extern const typPG  Page_Status_P4_CN[];
extern const typPG  Page_Status_P4_EN[];

extern const typPG   Page_Status_P5_CN[];
extern const typPG   Page_Status_P5_EN[];

extern const typPG   Page_Status_P6_CN[];
extern const typPG   Page_Status_P6_EN[];

extern const typPG   Page_Status_P7[];
extern const typPG   Page_Status_P8[];
extern const typPG   Page_Status_P9[];
extern const typPG   Page_Status_P10[];

extern const typPG   Page_Status_P11_CN[];
extern const typPG   Page_Status_P11_EN[];

extern const typPG   Page_Status_P12_CN[];
extern const typPG   Page_Status_P12_EN[];

extern const typPG   Page_Status_P13_CN[];
extern const typPG   Page_Status_P13_EN[];

extern const typPG   Page_Status_P14_CN[];
extern const typPG   Page_Status_P14_EN[];

extern const typPG   Page_Status_P15_CN[];
extern const typPG   Page_Status_P15_EN[];

extern const typPG   RecDetailPage_CN[];
extern const typPG   RecDetailPage_EN[];

extern const typPG   LngPage[];

extern const typPG Page_Start_Status1_CN[];
extern const typPG Page_Start_Status1_EN[];
extern const typPG Page_Start_Status2_CN[];
extern const typPG Page_Start_Status2_EN[];
extern const typPG Page_Start_Status3_CN[];
extern const typPG Page_Start_Status3_EN[];

extern const typPG Page_Rec_Status_CN[];

#pragma CONST_SEG __GPAGE_SEG PAGE_3
extern const typFNT_ASC16   ASC_16[88];
extern const typFNT_GB16   GB_16[418];



#define ASC_HZ_WIDTH	12
#define ASC_HZ_HEIGHT	16



#endif

