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
//�������ƣ�  ee_sck()
//����������  generate sck signal
//���������  
//���������
//************************************************************************************

//************************************************************************************
//�������ƣ�  ee_sda()
//����������  
//���������  
//���������
//************************************************************************************


PUBLIC void hrdeeprom_init(void)
{
	hrdCONFIG_EEPROM(); 
}