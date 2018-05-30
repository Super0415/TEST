//definition
#ifndef _AI_H
#define _AI_H
#include "PublicShare.h"
#define BUF_LEN     32
#define atd_cf_clr()    (ATD0STAT2       = 0XFF)
#define atd_scf_clr()   (ATD0STAT0_SCF   = 1)
#define atd_int_en()    (ATD0CTL2_ASCIE  = 1)
#define atd_int_dis()   (ATD0CTL2_ASCIE  = 0)
#define atd_start()     (ATD0CTL5 = 0x30)
PUBLIC void ai_check(void);
PUBLIC void ai_process (void);
PUBLIC void hrdadc_init(void);
PUBLIC void TransValue (void);
void CalcSensor(void);
#endif                          