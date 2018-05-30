#ifndef __CONST_H_
#define __CONST_H_
#include "PublicShare.h"
 PUBLIC  long cos_tab[];
PUBLIC  long sin_tab[];
#pragma push
#pragma CONST_SEG __GPAGE_SEG MY_CONST


#if FEIERTE_MODE
PUBLIC const int ParamsDefault[];    //参数默认值
#else
PUBLIC const int ParamsDefault[];    //参数默认值
#endif

PUBLIC const int OIL_CURVE_VDO_5bar[16][2]; 
PUBLIC const int OIL_CURVE_VDO_10bar[16][2]; 
PUBLIC const int OIL_CURVE_Datcon_5bar[16][2]; 
PUBLIC const int OIL_CURVE_Datcon_10bar[16][2]; 
PUBLIC const int OIL_CURVE_Datcon_7bar[16][2]; 
PUBLIC const int OIL_CURVE_Murphy_7bar[16][2]; 
PUBLIC const int OIL_CURVE_CMB_812[16][2]; 
PUBLIC const int OIL_CURVE_SGH_10bar[16][2]; 
PUBLIC const int OIL_CURVE_Curtis[16][2]; 
PUBLIC const int OIL_CURVE_SGD_10bar[16][2];  
PUBLIC const int OIL_CURVE_SCD_10bar[16][2];  
//水温：
PUBLIC const int TEMP_CURVE_VDO_120C[16][2]; 
PUBLIC const int TEMP_CURVE_Datcon_high[16][2]; 
PUBLIC const int TEMP_CURVE_Datcon_low[16][2];
PUBLIC const int TEMP_CURVE_Murphy[16][2]; 
PUBLIC const int TEMP_CURVE_Cummins[16][2]; 
PUBLIC const int TEMP_CURVE_SGH_120C[16][2]; 
PUBLIC const int TEMP_CURVE_Curtis[16][2]; 
PUBLIC const int TEMP_CURVE_SGD_120C[16][2]; 
PUBLIC const int TEMP_CURVE_PT100[16][2]; 
PUBLIC const int TEMP_CURVE_PUSHENG[16][2];
PUBLIC const int TEMP_CURVE_ST820JD[16][2]; 
PUBLIC const int TEMP_CURVE_PT1000[16][2]; 

//液位：
PUBLIC const int FUEL_CURVE_VDO_Ohm_10_180[16][2]; 
PUBLIC const int FUEL_CURVE_VDO_Tube_90_0[16][2]; 
PUBLIC const int FUEL_CURVE_US_Ohm_240_33[16][2];
PUBLIC const int FUEL_CURVE_GM_Ohm_0_90[16][2]; 
PUBLIC const int FUEL_CURVE_GM_Ohm_0_30[16][2]; 
PUBLIC const int FUEL_CURVE_Ford_73_10[16][2];
PUBLIC const int FUEL_CURVE_NKZR_100_0[16][2]; 
PUBLIC const int FUEL_CURVE_S5E225[16][2];
PUBLIC const int FUEL_CURVE_JS52026[16][2];

#pragma pop




#endif
