#include "hidef.h"      /* common defines and macros */
#include "MC9S12XET256.h"     /* derivative information */
#include "defs.h"
#include "pinout.h"
#include "string.h"
#include "extern.h"
#include "btn.h"
#include "MCU_init.h"
#include "xgate.h" 
#include "main.h"
#include "math.h"
#include "dido.h"
#include "eee.h"
#include "buz.h"
#include "ai.h" 
#include "io.h"
#include "share.h"
#include "lcd.h"
#include "warn.h"
#include "logic.h"
#include "alloc.h"
#include "eeprom.h"
#pragma DATA_SEG DEFAULT
#pragma CODE_SEG DEFAULT

//#pragma CODE_SEG DEFAULT
//************************************************************************************
//函数名称：  ee_sck()
//功能描述：  generate sck signal
//输入参数：  
//输出参数：
//************************************************************************************

//************************************************************************************
//函数名称：  ee_sda()
//功能描述：  
//输入参数：  
//输出参数：
//************************************************************************************


PUBLIC void hrdeeprom_init(void)
{
	hrdCONFIG_EEPROM(); 
}