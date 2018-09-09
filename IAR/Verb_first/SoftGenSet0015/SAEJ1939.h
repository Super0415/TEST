/* ******************************************************************** */
/*                SAE J1939 Software for Elctronic Unit (V1.0)          */
/*                       Header File SAEJ1939.h                        */
/*                              2017-11-03                              */
/* ******************************************************************** */

#ifndef _SAEJ1939_H

#define _SAEJ1939_H

#ifdef   SAE_GLOBALS

#define  SAE_EXT  

#else

#define  SAE_EXT extern

#endif

/* ******************************************************************** */
/*  SAE_VERSION  = 10xx: VEC1000 Application                            */
/*  SAE_VERSION  = 40xx: VEC4000 Application                            */
/*  SAE_VERSION  = 68xx: VEC6800 Application                            */
/*  SAE_VERSION  = 69xx: VEC6900 Application                            */
/*  SAE_VERSION  = 76xx: GEC7600 Application                            */
/*  SAE_VERSION  = 78xx: GEC7800 Application                            */
/*  SAE_VERSION  = 80xx: VEC8000 Application                            */
/*  SAE_VERSION  = 90xx: VEC9000 Application                            */
/*  SAE_VERSION  = 96xx: VEC9600 Application                            */
/* ******************************************************************** */

#define SAE_VERSION          7600

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define SAE_1000_COMMON_ON      0
#define SAE_4000_COMMON_ON      0
#define SAE_6800_COMMON_ON      0
#define SAE_6900_COMMON_ON      0
#define SAE_7600_COMMON_ON      0
#define SAE_7800_COMMON_ON      0
#define SAE_8000_COMMON_ON      0
#define SAE_9000_COMMON_ON      0
#define SAE_9600_COMMON_ON      0
#if   ((SAE_VERSION / 100)  == 10)
#undef  SAE_1000_COMMON_ON
#define SAE_1000_COMMON_ON      1
#endif
#if   ((SAE_VERSION / 100)  == 40)
#undef  SAE_4000_COMMON_ON
#define SAE_4000_COMMON_ON      1
#endif
#if   ((SAE_VERSION / 100)  == 68)
#undef  SAE_6800_COMMON_ON
#define SAE_6800_COMMON_ON      1
#endif
#if   ((SAE_VERSION / 100)  == 69)
#undef  SAE_6900_COMMON_ON
#define SAE_6900_COMMON_ON      1
#endif
#if   ((SAE_VERSION / 100)  == 76)
#undef  SAE_7600_COMMON_ON
#define SAE_7600_COMMON_ON      1
#endif
#if   ((SAE_VERSION / 100)  == 78)
#undef  SAE_7800_COMMON_ON
#define SAE_7800_COMMON_ON      1
#endif
#if   ((SAE_VERSION / 100)  == 80)
#undef  SAE_8000_COMMON_ON
#define SAE_8000_COMMON_ON      1
#endif
#if   ((SAE_VERSION / 100)  == 90)
#undef  SAE_9000_COMMON_ON
#define SAE_9000_COMMON_ON      1
#endif
#if   ((SAE_VERSION / 100)  == 96)
#undef  SAE_9600_COMMON_ON
#define SAE_9600_COMMON_ON      1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define SAE_CPU_9S12_ON         0
#define SAE_CPU_POWERPC_ON      0
#define SAE_CPU_STM32F1_ON      0
#define SAE_MY_ADDRESS          0
#define SAE_CCP_CCP10_ON        1
#if    (SAE_1000_COMMON_ON   == 1)
#undef  SAE_CPU_9S12_ON
#define SAE_CPU_9S12_ON         1
#undef  SAE_MY_ADDRESS
#define SAE_MY_ADDRESS          23
#endif
#if    (SAE_4000_COMMON_ON   == 1)
#undef  SAE_CPU_9S12_ON
#define SAE_CPU_9S12_ON         1
#undef  SAE_MY_ADDRESS
#define SAE_MY_ADDRESS          23
#endif
#if    (SAE_6800_COMMON_ON   == 1)
#undef  SAE_CPU_9S12_ON
#define SAE_CPU_9S12_ON         1
#endif
#if    (SAE_6900_COMMON_ON   == 1)
#undef  SAE_CPU_POWERPC_ON
#define SAE_CPU_POWERPC_ON      1
#endif
#if    (SAE_7600_COMMON_ON   == 1)
#undef  SAE_CPU_STM32F1_ON
#define SAE_CPU_STM32F1_ON      1
#undef  SAE_MY_ADDRESS
#define SAE_MY_ADDRESS          23
#endif
#if    (SAE_7800_COMMON_ON   == 1)
#undef  SAE_CPU_STM32F1_ON
#define SAE_CPU_STM32F1_ON      1
#undef  SAE_MY_ADDRESS
#define SAE_MY_ADDRESS          23
#endif
#if    (SAE_8000_COMMON_ON   == 1)
#undef  SAE_CPU_POWERPC_ON
#define SAE_CPU_POWERPC_ON      1
#endif
#if    (SAE_9000_COMMON_ON   == 1)
#undef  SAE_CPU_POWERPC_ON
#define SAE_CPU_POWERPC_ON      1
#endif
#if    (SAE_9600_COMMON_ON   == 1)
#undef  SAE_CPU_POWERPC_ON
#define SAE_CPU_POWERPC_ON      1
#endif

/* ******************************************************************** */
/*                         VEC1000 Application                          */
/* ******************************************************************** */
#if    (SAE_1000_COMMON_ON   == 1)
#define SAE_IGNORE_SPEED_ERROR  1
#define SAE_IGNORE_RACK_ERROR   0
#define SAE_PRESS_RELATIVE_ON   1
#define SAE_RX_PGN_MATCH_ON     0
#define SAE_TX_DM1_DM2_SPN_ON   0
#define SAE_RX_PGN_MAX          20
#define SAE_TX_PGN_MAX          2
#define SAE_RX_PGN_EEC1         0
#define SAE_RX_PGN_EEC2         1
#define SAE_RX_PGN_EEC3         2
#define SAE_RX_PGN_AMCON        3
#define SAE_RX_PGN_VEHSPD       4
#define SAE_RX_PGN_CNFPBAM      5
#define SAE_RX_PGN_CNFPACK      6
#define SAE_RX_PGN_ENGTEMP      7
#define SAE_RX_PGN_LFE          8
#define SAE_RX_PGN_EFL          9
#define SAE_RX_PGN_LFC          10
#define SAE_RX_PGN_DM1SINGLE    11
#define SAE_RX_PGN_DM2SINGLE    12
#define SAE_RX_PGN_DM4SINGLE    13
#define SAE_RX_PGN_DM11ACK      14
#define SAE_RX_PGN_INCON        15
#define SAE_RX_PGN_VEHPOW       16
#define SAE_RX_PGN_ENGHOUR      17
#define SAE_RX_PGN_CRPRESS      18
#define SAE_RX_PGN_CCP10PAR     19
#define SAE_TX_PGN_PGNRQ        0
#define SAE_TX_PGN_CCP10REQ     1
#if    (SAE_1000_TWO_FUEL_ON == 1)
#undef  SAE_RX_PGN_MATCH_ON
#define SAE_RX_PGN_MATCH_ON     1
#endif
#endif

/* ******************************************************************** */
/*                         VEC4000 Application                          */
/* ******************************************************************** */
#if    (SAE_4000_COMMON_ON   == 1)
#define SAE_IGNORE_SPEED_ERROR  1
#define SAE_IGNORE_RACK_ERROR   0
#define SAE_PRESS_RELATIVE_ON   1
#define SAE_RX_PGN_MATCH_ON     0
#define SAE_TX_DM1_DM2_SPN_ON   0
#define SAE_RX_PGN_MAX          20
#define SAE_TX_PGN_MAX          2
#define SAE_RX_PGN_EEC1         0
#define SAE_RX_PGN_EEC2         1
#define SAE_RX_PGN_EEC3         2
#define SAE_RX_PGN_AMCON        3
#define SAE_RX_PGN_VEHSPD       4
#define SAE_RX_PGN_CNFPBAM      5
#define SAE_RX_PGN_CNFPACK      6
#define SAE_RX_PGN_ENGTEMP      7
#define SAE_RX_PGN_LFE          8
#define SAE_RX_PGN_EFL          9
#define SAE_RX_PGN_LFC          10
#define SAE_RX_PGN_DM1SINGLE    11
#define SAE_RX_PGN_DM2SINGLE    12
#define SAE_RX_PGN_DM4SINGLE    13
#define SAE_RX_PGN_DM11ACK      14
#define SAE_RX_PGN_INCON        15
#define SAE_RX_PGN_VEHPOW       16
#define SAE_RX_PGN_ENGHOUR      17
#define SAE_RX_PGN_CRPRESS      18
#endif

/* ******************************************************************** */
/*                         VEC6800 Application                          */
/* ******************************************************************** */
#if    (SAE_6800_COMMON_ON   == 1)
#define SAE_IGNORE_SPEED_ERROR  1
#define SAE_IGNORE_RACK_ERROR   0
#define SAE_PRESS_RELATIVE_ON   1
#define SAE_RX_PGN_MATCH_ON     0
#define SAE_TX_DM1_DM2_SPN_ON   0
#define SAE_RX_PGN_MAX          16
#define SAE_TX_PGN_MAX          20
#define SAE_RX_PGN_EBC1         0
#define SAE_RX_PGN_EBC2         1
#define SAE_RX_PGN_ETC1         2
#define SAE_RX_PGN_RXCCVS       3
#define SAE_RX_PGN_HRVD         4
#define SAE_RX_PGN_PGNRQ        5
#define SAE_RX_PGN_RXAMCON      6
#define SAE_RX_PGN_TCO1         7
#define SAE_RX_PGN_TSC1AE       8
#define SAE_RX_PGN_TSC1DE       9
#define SAE_RX_PGN_TSC1PE       10
#define SAE_RX_PGN_TSC1TE       11
#define SAE_RX_PGN_TSC1VE       12
#define SAE_RX_PGN_DM13         13
#define SAE_RX_PGN_DEC1         14
#define SAE_RX_PGN_CCP10REQ     15
#define SAE_TX_PGN_EEC1         0
#define SAE_TX_PGN_EEC2         1
#define SAE_TX_PGN_EEC3         2
#define SAE_TX_PGN_AMCON        3
#define SAE_TX_PGN_VEHSPD       4
#define SAE_TX_PGN_CNFPBAM      5
#define SAE_TX_PGN_CNFPACK      6
#define SAE_TX_PGN_ENGTEMP      7
#define SAE_TX_PGN_LFE          8
#define SAE_TX_PGN_EFL          9
#define SAE_TX_PGN_LFC          10
#define SAE_TX_PGN_DM1SINGLE    11
#define SAE_TX_PGN_DM2SINGLE    12
#define SAE_TX_PGN_DM4SINGLE    13
#define SAE_TX_PGN_DM11ACK      14
#define SAE_TX_PGN_INCON        15
#define SAE_TX_PGN_VEHPOW       16
#define SAE_TX_PGN_ENGHOUR      17
#define SAE_TX_PGN_CRPRESS      18
#define SAE_TX_PGN_CCP10PAR     19
#if    (SAE_6800_SHAN_TUI_ON == 1)
#undef  SAE_RX_PGN_MATCH_ON
#define SAE_RX_PGN_MATCH_ON     1
#undef  SAE_TX_DM1_DM2_SPN_ON
#define SAE_TX_DM1_DM2_SPN_ON   1
#undef  SAE_RX_PGN_MAX
#define SAE_RX_PGN_MAX          17
#define SAE_RX_PGN_ECULOCK      16
#endif
#if    (SAE_6800_TWO_FUEL_ON == 1)
#undef  SAE_RX_PGN_MAX
#define SAE_RX_PGN_MAX          17
#define SAE_RX_PGN_SLAVEERR     16
#undef  SAE_TX_PGN_MAX
#define SAE_TX_PGN_MAX          21
#define SAE_TX_PGN_TSC1AE       20
#endif
#endif

/* ******************************************************************** */
/*                         VEC6900 Application                          */
/* ******************************************************************** */
#if    (SAE_6900_COMMON_ON   == 1)
#define SAE_IGNORE_SPEED_ERROR  1
#define SAE_IGNORE_RACK_ERROR   0
#define SAE_PRESS_RELATIVE_ON   1
#define SAE_RX_PGN_MATCH_ON     0
#define SAE_TX_DM1_DM2_SPN_ON   0
#define SAE_RX_PGN_MAX          16
#define SAE_TX_PGN_MAX          20
#define SAE_RX_PGN_EBC1         0
#define SAE_RX_PGN_EBC2         1
#define SAE_RX_PGN_ETC1         2
#define SAE_RX_PGN_RXCCVS       3
#define SAE_RX_PGN_HRVD         4
#define SAE_RX_PGN_PGNRQ        5
#define SAE_RX_PGN_RXAMCON      6
#define SAE_RX_PGN_TCO1         7
#define SAE_RX_PGN_TSC1AE       8
#define SAE_RX_PGN_TSC1DE       9
#define SAE_RX_PGN_TSC1PE       10
#define SAE_RX_PGN_TSC1TE       11
#define SAE_RX_PGN_TSC1VE       12
#define SAE_RX_PGN_DM13         13
#define SAE_RX_PGN_DEC1         14
#define SAE_RX_PGN_CCP10REQ     15
#define SAE_TX_PGN_EEC1         0
#define SAE_TX_PGN_EEC2         1
#define SAE_TX_PGN_EEC3         2
#define SAE_TX_PGN_AMCON        3
#define SAE_TX_PGN_VEHSPD       4
#define SAE_TX_PGN_CNFPBAM      5
#define SAE_TX_PGN_CNFPACK      6
#define SAE_TX_PGN_ENGTEMP      7
#define SAE_TX_PGN_LFE          8
#define SAE_TX_PGN_EFL          9
#define SAE_TX_PGN_LFC          10
#define SAE_TX_PGN_DM1SINGLE    11
#define SAE_TX_PGN_DM2SINGLE    12
#define SAE_TX_PGN_DM4SINGLE    13
#define SAE_TX_PGN_DM11ACK      14
#define SAE_TX_PGN_INCON        15
#define SAE_TX_PGN_VEHPOW       16
#define SAE_TX_PGN_ENGHOUR      17
#define SAE_TX_PGN_CRPRESS      18
#define SAE_TX_PGN_CCP10PAR     19
#endif

/* ******************************************************************** */
/*                         VEC7600 Application                          */
/* ******************************************************************** */
#if    (SAE_7600_COMMON_ON   == 1)
#define SAE_IGNORE_SPEED_ERROR  1
#define SAE_IGNORE_RACK_ERROR   0
#define SAE_PRESS_RELATIVE_ON   1
#define SAE_RX_PGN_MATCH_ON     0
#define SAE_TX_DM1_DM2_SPN_ON   0
#define SAE_RX_PGN_MAX          20
#define SAE_TX_PGN_MAX          2
#define SAE_RX_PGN_EEC1         0
#define SAE_RX_PGN_EEC2         1
#define SAE_RX_PGN_EEC3         2
#define SAE_RX_PGN_AMCON        3
#define SAE_RX_PGN_VEHSPD       4
#define SAE_RX_PGN_CNFPBAM      5
#define SAE_RX_PGN_CNFPACK      6
#define SAE_RX_PGN_ENGTEMP      7
#define SAE_RX_PGN_LFE          8
#define SAE_RX_PGN_EFL          9
#define SAE_RX_PGN_LFC          10
#define SAE_RX_PGN_DM1SINGLE    11
#define SAE_RX_PGN_DM2SINGLE    12
#define SAE_RX_PGN_DM4SINGLE    13
#define SAE_RX_PGN_DM11ACK      14
#define SAE_RX_PGN_INCON        15
#define SAE_RX_PGN_VEHPOW       16
#define SAE_RX_PGN_ENGHOUR      17
#define SAE_RX_PGN_CRPRESS      18
#define SAE_RX_PGN_CCP10PAR     19
#define SAE_TX_PGN_PGNRQ        0
#define SAE_TX_PGN_CCP10REQ     1
#endif

/* ******************************************************************** */
/*                         VEC7800 Application                          */
/* ******************************************************************** */
#if    (SAE_7800_COMMON_ON   == 1)
#define SAE_IGNORE_SPEED_ERROR  1
#define SAE_IGNORE_RACK_ERROR   0
#define SAE_PRESS_RELATIVE_ON   1
#define SAE_RX_PGN_MATCH_ON     0
#define SAE_TX_DM1_DM2_SPN_ON   0
#define SAE_RX_PGN_MAX          20
#define SAE_TX_PGN_MAX          2
#define SAE_RX_PGN_EEC1         0
#define SAE_RX_PGN_EEC2         1
#define SAE_RX_PGN_EEC3         2
#define SAE_RX_PGN_AMCON        3
#define SAE_RX_PGN_VEHSPD       4
#define SAE_RX_PGN_CNFPBAM      5
#define SAE_RX_PGN_CNFPACK      6
#define SAE_RX_PGN_ENGTEMP      7
#define SAE_RX_PGN_LFE          8
#define SAE_RX_PGN_EFL          9
#define SAE_RX_PGN_LFC          10
#define SAE_RX_PGN_DM1SINGLE    11
#define SAE_RX_PGN_DM2SINGLE    12
#define SAE_RX_PGN_DM4SINGLE    13
#define SAE_RX_PGN_DM11ACK      14
#define SAE_RX_PGN_INCON        15
#define SAE_RX_PGN_VEHPOW       16
#define SAE_RX_PGN_ENGHOUR      17
#define SAE_RX_PGN_CRPRESS      18
#define SAE_RX_PGN_CCP10PAR     19
#define SAE_TX_PGN_PGNRQ        0
#define SAE_TX_PGN_CCP10REQ     1
#endif

/* ******************************************************************** */
/*                         VEC8000 Application                          */
/* ******************************************************************** */
#if    (SAE_ENGINE_EFI_ON == 1)
#define SAE_IGNORE_SPEED_ERROR  1
#define SAE_IGNORE_RACK_ERROR   0
#define SAE_PRESS_RELATIVE_ON   1
#define SAE_RX_PGN_MATCH_ON     0
#define SAE_TX_DM1_DM2_SPN_ON   0
#define SAE_RX_PGN_MAX          16
#define SAE_TX_PGN_MAX          20
#define SAE_RX_PGN_EBC1         0
#define SAE_RX_PGN_EBC2         1
#define SAE_RX_PGN_ETC1         2
#define SAE_RX_PGN_RXCCVS       3
#define SAE_RX_PGN_HRVD         4
#define SAE_RX_PGN_PGNRQ        5
#define SAE_RX_PGN_RXAMCON      6
#define SAE_RX_PGN_TCO1         7
#define SAE_RX_PGN_TSC1AE       8
#define SAE_RX_PGN_TSC1DE       9
#define SAE_RX_PGN_TSC1PE       10
#define SAE_RX_PGN_TSC1TE       11
#define SAE_RX_PGN_TSC1VE       12
#define SAE_RX_PGN_DM13         13
#define SAE_RX_PGN_DEC1         14
#define SAE_RX_PGN_CCP10REQ     15
#define SAE_TX_PGN_EEC1         0
#define SAE_TX_PGN_EEC2         1
#define SAE_TX_PGN_EEC3         2
#define SAE_TX_PGN_AMCON        3
#define SAE_TX_PGN_VEHSPD       4
#define SAE_TX_PGN_CNFPBAM      5
#define SAE_TX_PGN_CNFPACK      6
#define SAE_TX_PGN_ENGTEMP      7
#define SAE_TX_PGN_LFE          8
#define SAE_TX_PGN_EFL          9
#define SAE_TX_PGN_LFC          10
#define SAE_TX_PGN_DM1SINGLE    11
#define SAE_TX_PGN_DM2SINGLE    12
#define SAE_TX_PGN_DM4SINGLE    13
#define SAE_TX_PGN_DM11ACK      14
#define SAE_TX_PGN_INCON        15
#define SAE_TX_PGN_VEHPOW       16
#define SAE_TX_PGN_ENGHOUR      17
#define SAE_TX_PGN_CRPRESS      18
#define SAE_TX_PGN_CCP10PAR     19
#if    (SAE_8000_TWO_FUEL_ON == 1)
#undef  SAE_RX_PGN_MAX
#define SAE_RX_PGN_MAX          17
#define SAE_RX_PGN_SLAVEERR     16
#undef  SAE_TX_PGN_MAX
#define SAE_TX_PGN_MAX          21
#define SAE_TX_PGN_TSC1AE       20
#endif
#endif

/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define SAE_TRUE               (INT08U)1
#define SAE_FALSE              (INT08U)0
#define SAE_ENABLE             (INT08U)1
#define SAE_DISABLE            (INT08U)0
#define SAE_NO_ERR             (INT08U)0
#define SAE_ERR_RX_FULL        (INT08U)1
#define SAE_ERR_RX_EMPTY       (INT08U)2
#define SAE_ERR_TX_FULL        (INT08U)3
#define SAE_ERR_TX_EMPTY       (INT08U)4
#define SAE_ERR_RX_TIMEOUT     (INT08U)5
#define SAE_ERR_TX_TIMEOUT     (INT08U)6
#define SAE_CODE_FREE          (INT08U)0
#define SAE_CODE_CYCLIC        (INT08U)1
#define SAE_CODE_IMMED         (INT08U)2
#define SAE_STS_NORMAL         (INT16U)0
#define SAE_STS_RESET          (INT16U)1
#define SAE_STS_WARNING        (INT16U)2
#define SAE_STS_BUS_OFF        (INT16U)4
#define SAE_STS_SLEEPING       (INT16U)8
#define SAE_STS_OVERRUN        (INT16U)16
#define SAE_STS_TX_ERR         (INT16U)32
#define SAE_STS_RX_ERR         (INT16U)64
#define SAE_STS_GET_BIT(m)     (usSAEStatus & (m))
#define SAE_STS_CLR_BIT(m)      usSAEStatus &= ~(m)
#define SAE_STS_SET_BIT(m)      usSAEStatus |= (m)
#define SAE_BASIC_TIME          5

/* ******************************************************************** */
/*                      SAE J1939 ID Definition                         */
/* ******************************************************************** */
#define SAE_ID_J1939_EEC1      (INT32U)0x0CF00400
#define SAE_ID_J1939_EEC2      (INT32U)0x0CF00300
#define SAE_ID_J1939_EEC3      (INT32U)0x18FEDF00
#define SAE_ID_J1939_AMCON     (INT32U)0x18FEF500
#define SAE_ID_J1939_VEHSPD    (INT32U)0x18FEF100
#define SAE_ID_J1939_CNFPBAM   (INT32U)0x18ECFF00
#define SAE_ID_J1939_CNFPACK   (INT32U)0x18EBFF00
#define SAE_ID_J1939_ENGTEMP   (INT32U)0x18FEEE00
#define SAE_ID_J1939_LFE       (INT32U)0x18FEF200
#define SAE_ID_J1939_EFL       (INT32U)0x18FEEF00
#define SAE_ID_J1939_LFC       (INT32U)0x18FEE900
#define SAE_ID_J1939_DM1SINGLE (INT32U)0x18FECA00
#define SAE_ID_J1939_DM2SINGLE (INT32U)0x18FECB00
#define SAE_ID_J1939_DM4SINGLE (INT32U)0x18FECD00
#define SAE_ID_J1939_DM11ACK   (INT32U)0x18EBFF00
#define SAE_ID_J1939_INCON     (INT32U)0x18FEF600
#define SAE_ID_J1939_VEHPOW    (INT32U)0x18FEF700
#define SAE_ID_J1939_ENGHOUR   (INT32U)0x18FEE500
#define SAE_ID_J1939_CRPRESS   (INT32U)0x18FFF400

#define SAE_ID_J1939_EBC1      (INT32U)0x18F0010B
#define SAE_ID_J1939_EBC2      (INT32U)0x18FEBF0B
#define SAE_ID_J1939_ETC1      (INT32U)0x0CF00203
#define SAE_ID_J1939_RXCCVS    (INT32U)0x18FEF121
#define SAE_ID_J1939_HRVD      (INT32U)0x18FEC1EE
#define SAE_ID_J1939_PGNRQ     (INT32U)0x18EA0021
#define SAE_ID_J1939_RXAMCON   (INT32U)0x01FEF521
#define SAE_ID_J1939_TCO1      (INT32U)0x0CFE6CEE
#define SAE_ID_J1939_TSC1AE    (INT32U)0x0C00000B
#define SAE_ID_J1939_TSC1AR    (INT32U)0x0C000F0B
#define SAE_ID_J1939_TSC1DE    (INT32U)0x0C000010
#define SAE_ID_J1939_TSC1DR    (INT32U)0x0C000F10
#define SAE_ID_J1939_TSC1PE    (INT32U)0x0C000024
#define SAE_ID_J1939_TSC1TE    (INT32U)0x0C000003
#define SAE_ID_J1939_TSC1TR    (INT32U)0x0C000F03
#define SAE_ID_J1939_TSC1VE    (INT32U)0x0C000021
#define SAE_ID_J1939_TSC1VR    (INT32U)0x0C000F21
#define SAE_ID_J1939_DM13      (INT32U)0x18DFFF27
#define SAE_ID_J1939_DEC1      (INT32U)0x0CFF0431
#define SAE_ID_J1939_LOCK      (INT32U)0x18DC0027
#define SAE_ID_J1939_CCP10REQ  (INT32U)0x0CF00E21
#define SAE_ID_J1939_CCP10PAR  (INT32U)0x0CF00F00
#define SAE_ID_J1939_SLAVEERR  (INT32U)0x18FECA01

/* ******************************************************************** */
/*                          Control Definition                          */
/* ******************************************************************** */
#if    (SAE_CPU_9S12_ON == 1)
#define SAE_CPU_TO_ID32(x)    (((x>>1)&(INT32U)0x0003FFFF)|((x>>3)&(INT32U)0x1FFC0000))
#define SAE_ID32_TO_CPU(x)    (((x&(INT32U)0x0003FFFF)<<1)|((x&(INT32U)0x1FFC0000)<<3)|(INT32U)0x00180000)
#define SAE_CPU_TO_PGN16(x)     (INT16U)(((x>>9)&(INT32U)0x000003FF)|((x>>11)&(INT32U)0x0000FC00))
#define SAE_ID32_TO_PGN16(x)    (INT16U)(x>>8)
#define SAE_CPU_TO_PGN32(x)     (x&(INT32U)0x07E7FE00)
#endif
#if    (SAE_CPU_POWERPC_ON == 1)
#define SAE_CPU_TO_ID32(x)      ((x)&(INT32U)0x1FFFFFFF)
#define SAE_ID32_TO_CPU(x)      ((x)&(INT32U)0x1FFFFFFF)
#define SAE_CPU_TO_PGN16(x)     (INT16U)((x)>>8)
#define SAE_ID32_TO_PGN16(x)    (INT16U)((x)>>8)
#define SAE_CPU_TO_PGN32(x)     ((x)&(INT32U)0x00FFFF00)
#endif
#if    (SAE_CPU_STM32F1_ON == 1)
#define SAE_CPU_TO_ID32(x)      ((x)>>3)
#define SAE_ID32_TO_CPU(x)      (((x)<<3)|(INT32U)0x04)
#define SAE_CPU_TO_PGN16(x)     (INT16U)((x)>>11)
#define SAE_ID32_TO_PGN16(x)    (INT16U)((x)>>8)
#define SAE_CPU_TO_PGN32(x)     ((x)&(INT32U)0x07FFF800)
#endif
#define SAE_UC_LOW(w)           (INT08U)(w)
#define SAE_UC_HIGH(w)          (INT08U)((w)>>8)
#define SAE_US_CREAT(l,h)       ((INT16U)(l)+((INT16U)(h)<<8))
#define SAE_GET_TXPGN_ENABLE(N) (sSAETxPgnTbl[N].ucEnable)
#define SAE_GET_TXPGN_STATE(N)  (sSAETxPgnTbl[N].ucState)
#define SAE_SET_TXPGN_IMMED(N)   sSAETxPgnTbl[N].ucState = SAE_CODE_IMMED
#define SAEPutMsgToTxBuf         CAN1PutMsgToTxBuf
#define SAEGetMsgFmRxBuf         CAN1GetMsgFmRxBuf

/* ******************************************************************** */
/*                           Type Definition                            */
/* ******************************************************************** */
typedef struct
{   INT08U     ucEnable;
    INT08U     ucState;
    INT16U     usTime;
    INT16U     usPeriod;
    INT32U     uiID;
}   SAE_PGN_TCB;

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
SAE_EXT INT16U usSAETimer;
SAE_EXT INT16U usSAEStatus;
SAE_EXT SAE_PGN_TCB sSAERxPgnTbl[SAE_RX_PGN_MAX];
SAE_EXT SAE_PGN_TCB sSAETxPgnTbl[SAE_TX_PGN_MAX];

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
SAE_EXT void   SAEInit(void);
SAE_EXT INT08U SAECheckTime(INT16U usOld, INT16U usPer);

SAE_EXT void   SAERxPgnEnable(INT08U ucIndex, INT08U usAddr);
SAE_EXT void   SAERxPgnDisable(INT16U usIndex);
SAE_EXT void   SAERxPgnDisableAll(void);
SAE_EXT void   SAETxPgnEnable(INT08U ucIndex, INT08U usAddr);
SAE_EXT void   SAETxPgnDisable(INT16U usIndex);
SAE_EXT void   SAETxPgnDisableAll(void);
SAE_EXT void   SAEUpdataTxPgnAddr(INT08U ucIndex, INT08U ucAddr);
SAE_EXT void   SAEUpdataTxPgnAddrAll(INT08U ucAddr);
SAE_EXT void   SAEUpdataRxPgnAddr(INT08U ucIndex, INT08U ucAddr);
SAE_EXT void   SAEUpdataRxPgnAddrAll(INT08U ucAddr);
SAE_EXT void   SAERxPgnTblInit(void);
SAE_EXT void   SAETxPgnTblInit(void);

SAE_EXT INT08U SAEProcessRxMsg(CAN_MSG *pMsg);
SAE_EXT INT08U SAEProcessTxMsg(CAN_MSG *pMsg);

SAE_EXT INT08U SAECheckRxAllTimeOut(void);
SAE_EXT INT08U SAECheckRxSetpValid(void);

/* ******************************************************************** */
/*                          Call Back Functions                         */
/* ******************************************************************** */

#ifdef  SAE_TX_PGN_EEC1
SAE_EXT void SAEUpdateTxEEC1(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_EEC1
SAE_EXT void SAEUpdateRxEEC1(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_EEC2
SAE_EXT void SAEUpdateTxEEC2(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_EEC2
SAE_EXT void SAEUpdateRxEEC2(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_EEC3
SAE_EXT void SAEUpdateTxEEC3(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_EEC3
SAE_EXT void SAEUpdateRxEEC3(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_AMCON
SAE_EXT void SAEUpdateTxAMCON(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_AMCON
SAE_EXT void SAEUpdateRxAMCON(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_VEHSPD
SAE_EXT void SAEUpdateTxVEHSPD(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_VEHSPD
SAE_EXT void SAEUpdateRxVEHSPD(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_CNFPBAM
SAE_EXT void SAEUpdateTxCNFPBAM(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_CNFPBAM
SAE_EXT void SAEUpdateRxCNFPBAM(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_CNFPACK
SAE_EXT void SAEUpdateTxCNFPACK(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_CNFPACK
SAE_EXT void SAEUpdateRxCNFPACK(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_ENGTEMP
SAE_EXT void SAEUpdateTxENGTEMP(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_ENGTEMP
SAE_EXT void SAEUpdateRxENGTEMP(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_LFE
SAE_EXT void SAEUpdateTxLFE(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_LFE
SAE_EXT void SAEUpdateRxLFE(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_EFL
SAE_EXT void SAEUpdateTxEFL(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_EFL
SAE_EXT void SAEUpdateRxEFL(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_LFC
SAE_EXT void SAEUpdateTxLFC(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_LFC
SAE_EXT void SAEUpdateRxLFC(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_DM1SINGLE
SAE_EXT void SAEUpdateTxDM1(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_DM1SINGLE
SAE_EXT void SAEUpdateRxDM1(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_DM2SINGLE
SAE_EXT void SAEUpdateTxDM2(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_DM2SINGLE
SAE_EXT void SAEUpdateRxDM2(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_DM4SINGLE
SAE_EXT void SAEUpdateTxDM4(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_DM4SINGLE
SAE_EXT void SAEUpdateRxDM4(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_DM11ACK
SAE_EXT void SAEUpdateTxDM11ACK(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_DM11ACK
SAE_EXT void SAEUpdateRxDM11ACK(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_INCON
SAE_EXT void SAEUpdateTxINCON(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_INCON
SAE_EXT void SAEUpdateRxINCON(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_VEHPOW
SAE_EXT void SAEUpdateTxVEHPOW(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_VEHPOW
SAE_EXT void SAEUpdateRxVEHPOW(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_ENGHOUR
SAE_EXT void SAEUpdateTxENGHOUR(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_ENGHOUR
SAE_EXT void SAEUpdateRxENGHOUR(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_CRPRESS
SAE_EXT void SAEUpdateTxCRPRESS(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_CRPRESS
SAE_EXT void SAEUpdateRxCRPRESS(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_EBC1
SAE_EXT void SAEUpdateTxEBC1(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_EBC1
SAE_EXT void SAEUpdateRxEBC1(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_EBC2
SAE_EXT void SAEUpdateTxEBC2(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_EBC2
SAE_EXT void SAEUpdateRxEBC2(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_ETC1
SAE_EXT void SAEUpdateTxETC1(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_ETC1
SAE_EXT void SAEUpdateRxETC1(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_RXCCVS
SAE_EXT void SAEUpdateTxRXCCVS(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_RXCCVS
SAE_EXT void SAEUpdateRxRXCCVS(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_HRVD
SAE_EXT void SAEUpdateTxHRVD(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_HRVD
SAE_EXT void SAEUpdateRxHRVD(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_PGNRQ
SAE_EXT void SAEUpdateTxPGNRQ(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_PGNRQ
SAE_EXT void SAEUpdateRxPGNRQ(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_RXAMCON
SAE_EXT void SAEUpdateTxRXAMCON(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_RXAMCON
SAE_EXT void SAEUpdateRxRXAMCON(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_TCO1
SAE_EXT void SAEUpdateTxTCO1(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_TCO1
SAE_EXT void SAEUpdateRxTCO1(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_TSC1AE
SAE_EXT void SAEUpdateTxTSC1AE(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_TSC1AE
SAE_EXT void SAEUpdateRxTSC1AE(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_TSC1DE
SAE_EXT void SAEUpdateTxTSC1DE(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_TSC1DE
SAE_EXT void SAEUpdateRxTSC1DE(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_TSC1PE
SAE_EXT void SAEUpdateTxTSC1PE(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_TSC1PE
SAE_EXT void SAEUpdateRxTSC1PE(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_TSC1TE
SAE_EXT void SAEUpdateTxTSC1TE(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_TSC1TE
SAE_EXT void SAEUpdateRxTSC1TE(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_TSC1VE
SAE_EXT void SAEUpdateTxTSC1VE(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_TSC1VE
SAE_EXT void SAEUpdateRxTSC1VE(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_DM13
SAE_EXT void SAEUpdateTxDM13(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_DM13
SAE_EXT void SAEUpdateRxDM13(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_DEC1
SAE_EXT void SAEUpdateTxDEC1(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_DEC1
SAE_EXT void SAEUpdateRxDEC1(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_CCP10REQ
SAE_EXT void SAEUpdateTxCCPREQ(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_CCP10REQ
SAE_EXT void SAEUpdateRxCCPREQ(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_CCP10PAR
SAE_EXT void SAEUpdateTxCCPPAR(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_CCP10PAR
SAE_EXT void SAEUpdateRxCCPPAR(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_ECULOCK
SAE_EXT void SAEUpdateTxEcuLock(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_ECULOCK
SAE_EXT void SAEUpdateRxEcuLock(CAN_MSG *pMsg);
#endif

#ifdef  SAE_TX_PGN_SLAVEERR
SAE_EXT void SAEUpdateTxSlaveErr(CAN_MSG *pMsg);
#endif

#ifdef  SAE_RX_PGN_SLAVEERR
SAE_EXT void SAEUpdateRxSlaveErr(CAN_MSG *pMsg);
#endif

/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
