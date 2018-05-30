#ifndef _PINOUT_H
#define _PINOUT_H
#include "defs.h"



#define hrdPORT_IN_OUTPUT			1
#define hrdPORT_IN_INTPUT			0
#define hrdPORT_UNUSED				hrdPORT_IN_INTPUT
/*************************************************************\
≤©∂≈∞≤∂®“Â
\*************************************************************/
#if PCB16W
//redefine PORTA

#define BIN06           PORTA_PA1
#define DDR_BIN06       DDRA_DDRA1
#define BIN05           PORTA_PA2
#define DDR_BIN05       DDRA_DDRA2
#define BIN04           PORTA_PA3
#define DDR_BIN04       DDRA_DDRA3
#define BIN03           PORTA_PA4
#define DDR_BIN03       DDRA_DDRA4
#define BIN02           PORTA_PA5
#define DDR_BIN02       DDRA_DDRA5
#define BIN01           PORTA_PA6
#define DDR_BIN01       DDRA_DDRA6
#define BIN00           PORTA_PA7
#define DDR_BIN00       DDRA_DDRA7

//redefine PORTB
#define CTLEXTEND       PORTB_PB0
#define DDR_CTLEXTEND   DDRB_DDRB0
#define BOUT00          PORTB_PB1
#define DDR_BOUT00       DDRB_DDRB1
#define BOUT01          PORTB_PB2
#define DDR_BOUT01       DDRB_DDRB2
#define BOUT02          PORTB_PB3
#define DDR_BOUT02       DDRB_DDRB3
#define BOUT03          PORTB_PB4
#define DDR_BOUT03       DDRB_DDRB4
#define BOUT04          PORTB_PB5
#define DDR_BOUT04       DDRB_DDRB5
#define BOUT05          PORTB_PB6
#define DDR_BOUT05       DDRB_DDRB6
#define BOUT06          PORTB_PB7
#define DDR_BOUT06       DDRB_DDRB7

//redefine PORTC
//redefine PORTD
//redefine PORTE

#define BOUT09          PORTE_PE2
#define DDR_BOUT09      DDRE_DDRE2
#define BOUT10          PORTE_PE3
#define DDR_BOUT10      DDRE_DDRE3 

//redefine PORTF
//redefine PORTG
//redefine PORTH
#define BOUT07          PTH_PTH7
#define DDR_BOUT07      DDRH_DDRH7
#define BOUT08          PTH_PTH6
#define DDR_BOUT08      DDRH_DDRH6

#define BOUT11          PTH_PTH0
#define DDR_BOUT11      DDRH_DDRH0
#define BOUT12          PTH_PTH2
#define DDR_BOUT12      DDRH_DDRH2
#define BOUT13          PTH_PTH3
#define DDR_BOUT13      DDRH_DDRH3

#define DDR_DOUTPUT     DDRH_DDRH5
#define DOUTPUT         PTH_PTH5

//redefine  PORTI
//redefine  PORTJ
//redefine  PORTK



//redefine  PORTM
#define DDR_SPEEDSENSOR DDRM_DDRM7
#define BOUT_SPEEDSENSOR PTM_PTM7



//redefine  PORTN
//redefine  PORTO
//redefine  PORTP
#define BIN07           PTP_PTP0
#define DDR_BIN07       DDRP_DDRP0
#define BIN08           PTP_PTP1
#define DDR_BIN08       DDRP_DDRP1
#define BIN09           PTP_PTP2
#define DDR_BIN09       DDRP_DDRP2
#define BIN10           PTP_PTP3
#define DDR_BIN10       DDRP_DDRP3
        

//redefine  PORTS

 

//redefine  PORTT

        
#endif

#if PCB16DW 
//redefine PORTA

#define BIN06           PORTA_PA1
#define DDR_BIN06       DDRA_DDRA1
#define BIN05           PORTA_PA2
#define DDR_BIN05       DDRA_DDRA2
#define BIN04           PORTA_PA3
#define DDR_BIN04       DDRA_DDRA3
#define BIN03           PORTA_PA4
#define DDR_BIN03       DDRA_DDRA4
#define BIN02           PORTA_PA5
#define DDR_BIN02       DDRA_DDRA5
#define BIN01           PORTA_PA6
#define DDR_BIN01       DDRA_DDRA6
#define BIN00           PORTA_PA7
#define DDR_BIN00       DDRA_DDRA7

//redefine PORTB

#define BOUT00          PORTB_PB1
#define DDR_BOUT00       DDRB_DDRB1
#define BOUT01          PORTB_PB2
#define DDR_BOUT01       DDRB_DDRB2
#define BOUT02          PORTB_PB3
#define DDR_BOUT02       DDRB_DDRB3
#define BOUT03          PORTB_PB4
#define DDR_BOUT03       DDRB_DDRB4
#define BOUT04          PORTB_PB5
#define DDR_BOUT04      DDRB_DDRB5
#define BOUT05          PORTB_PB6
#define DDR_BOUT05       DDRB_DDRB6
#define BOUT06          PORTB_PB7
#define DDR_BOUT06       DDRB_DDRB7



//redefine PORTC
//redefine PORTD
//redefine PORTE

#define BOUT13          PORTE_PE2
#define DDR_BOUT13      DDRE_DDRE2
#define BOUT12          PORTE_PE3
#define DDR_BOUT12      DDRE_DDRE3 

//redefine PORTF
//redefine PORTG
//redefine PORTH




#define BOUT07          PTH_PTH7
#define DDR_BOUT07      DDRH_DDRH7
#define BOUT08          PTH_PTH6
#define DDR_BOUT08      DDRH_DDRH6

#define BOUT09          PTH_PTH2
#define DDR_BOUT09      DDRH_DDRH2
#define BOUT10          PTH_PTH1
#define DDR_BOUT10      DDRH_DDRH1

#define BOUT11          PTH_PTH0
#define DDR_BOUT11      DDRH_DDRH0


#define DDR_DOUTPUT     DDRH_DDRH5
#define DOUTPUT         PTH_PTH5

//redefine  PORTI
//redefine  PORTJ

#define BIN09           PTJ_PTJ1
#define DDR_BIN09       DDRJ_DDRJ1
#define BIN10           PTJ_PTJ0
#define DDR_BIN10       DDRJ_DDRJ0
//redefine  PORTK
#define BIN07           PORTK_PK5
#define DDR_BIN07       DDRK_DDRK5
#define BIN08           PORTK_PK4
#define DDR_BIN08       DDRK_DDRK4


//redefine  PORTM
#define DDR_SPEEDSENSOR DDRM_DDRM7
#define BOUT_SPEEDSENSOR PTM_PTM7



//redefine  PORTN
//redefine  PORTO
//redefine  PORTP


        

//redefine  PORTS

 

//redefine  PORTT

        
#endif






/*************************************************************\
								keyboard config
								key1 output
								key2 input
								key3 input
								key4 input
/*************************************************************/



/*
#define hrdconfig_btn_port()	{	DDR_KEY1 = hrdPORT_IN_OUTPUT;\
																KEY1     = 0;\
  															DDR_KEY2 = hrdPORT_IN_INTPUT;\
  															DDR_KEY3 = hrdPORT_IN_INTPUT;\
  															DDR_KEY4 = hrdPORT_IN_INTPUT;}
  															
*/  															
  															
  															
/**************config atd***********************\
  //12bit solution, discharge before sampling bit , disable external trigger
  ATD0CTL1 = 0X5F;  
  //ATD1CTL1 = 0X5F;
  //changes all ATD conversion complere flags to a fast clear qequence.
  //disable external trigger
  //disable ATD sequence complere intrrupt
  //disable compare interrupt
  ATD0CTL2 = 0X40;
  //ATD1CTL2 = 0X40;
  //right justified data, conversion sequence length is 16,
  ATD0CTL3 = 0x80;
  //ATD1CTL3 = 0XF8;
  //sample time is 10 ATD clock cycles, fATDCLK = fBUS/(2X(PRS+1)) = 5MHZ
  ATD0CTL4 = 0X61;
  //ATD1CTL4 = 0X61;
  //disable special channel conversion, single conversion sequence, 
  //sample across several channels
  //ATD0CTL5 = 0X10;
  //ATD1CTL5 = 0X10;  
\******************************************************************/
#define hrdCONFIG_ATD()				{ ATD0CTL1 = 0X5F;\
  															ATD0CTL2 = 0X40;\
															  ATD0CTL3 = 0x80;\
															  ATD0CTL4 = 0X61;}

                          
														

 #define  hrdCONFIG_DIDO()       {BIN00     = 1;\
                                  DDR_BIN01 = 0;\
                                  BIN01     = 1;\
                                  DDR_BIN02 = 0;\
                                  BIN02     = 1;\
                                  DDR_BIN03 = 0;\
                                  BIN03     = 1;\
                                  DDR_BIN04 = 0;\
                                  BIN04     = 1;\
                                  DDR_BIN05 = 0;\
                                  BIN05     = 1;\
                                  DDR_BIN06 = 0;\
                                  BIN06     = 1;\
                                  DDR_BIN07 = 0;\
                                  BIN07     = 1;\
                                  DDR_BIN08 = 0;\
                                  BIN08     = 1;\
                                  DDR_BIN09 = 0;\
                                  BIN09     = 1;\
                                  DDR_BIN10 = 0;\
                                  BIN10     = 1;\
                                  DDR_BOUT00= 1;\
                                  BOUT00    = 0;\
                                  DDR_BOUT01= 1;\
                                  BOUT01    = 0;\
                                  DDR_BOUT02= 1;\
                                  BOUT02    = 0;\
                                  DDR_BOUT03= 1;\
                                  BOUT03    = 0;\
                                  DDR_BOUT04= 1;\
                                  BOUT04    = 0;\
                                  DDR_BOUT05= 1;\
                                  BOUT05    = 0;\
                                  DDR_BOUT06= 1;\
                                  BOUT06    = 0;\
                                  DDR_BOUT07= 1;\
                                  BOUT07    = 0;\
                                  DDR_BOUT08= 1;\
                                  BOUT08    = 0;\
                                  DDR_BOUT09= 1;\
                                  BOUT09    = 0;\
                                  DDR_BOUT10= 1;\
                                  BOUT10    = 0;\
                                  DDR_BOUT11= 1;\
                                  BOUT11    = 0;\
                                  DDR_BOUT12= 1;\
                                  BOUT12    = 0;\
                                  DDR_BOUT13= 1;\
                                  BOUT13    = 0;\
                                  DDR_DOUTPUT=1;\
                                  DDR_SPEEDSENSOR=1;}
                                
                               
      

#endif
