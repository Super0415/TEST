#ifndef __CLOCK_H_
#define __CLOCK_H_

#include "PublicShare.h"
#include "logic.h"
#define DATE_YEAR       DATEVALUE[6]
#define DATE_MONTH      DATEVALUE[5]
#define DATE_DAY        DATEVALUE[4]
#define DATE_WEEK       DATEVALUE[3]                          
#define DATE_HOUR       DATEVALUE[2]
#define DATE_MINUTE     DATEVALUE[1]
#define DATE_SECOND     DATEVALUE[0]
PUBLIC uchar DATEVALUE[7];
PUBLIC void IIC_read_time (unsigned char *addr);
PUBLIC void IIC_write_time (unsigned char YEAR, unsigned char MONTH, unsigned char DATE, unsigned char HOUR, unsigned char MINUTE);
PUBLIC void Timer_Management(void);
#endif