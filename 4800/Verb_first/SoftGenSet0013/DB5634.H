/* ******************************************************************** */
/*                       Data Base for ECU (V1.0)                       */
/*                         Header File DB5634.H                         */
/*                             By Wu Xuekui                             */
/*                              2011-11-02                              */
/* ******************************************************************** */

#ifndef _DB5634_H

#define _DB5634_H

#ifdef   DB_GLOBALS

#define  DB_EXT 

#else

#define  DB_EXT  extern

#endif

/* ******************************************************************** */
/*  DB_VERSION  = 1000: VEC1000 Genernal Application                    */
/*  DB_VERSION  = 1001: VEC1000 Telecom Base Station Application        */
/*  DB_VERSION  = 1002: VEC1000 TongJie Application                     */
/*  DB_VERSION  = 1003: VEC1000 ECU Tester Application                  */
/*  DB_VERSION  = 1004: VEC1000 Pressure Monitoring Application         */
/*  DB_VERSION  = 1005: VEC1000 Two Fuel Application                    */
/*  DB_VERSION  = 4000: VEC4000 RF Genernal Application                 */
/*  DB_VERSION  = 4001: VEC4000 RF TongJie Application                  */
/*  DB_VERSION  = 6840: VEC6800 Genernal Application                    */
/*  DB_VERSION  = 6841: VEC6800 Telecom Base Station Application        */
/*  DB_VERSION  = 6842: VEC6800 Shan Tui Application                    */
/*  DB_VERSION  = 6843: VEC6800 Analog Calibration Application          */
/*  DB_VERSION  = 6844: VEC6800 Water Pump Application                  */
/*  DB_VERSION  = 6845: VEC6800 Hua Wei Application                     */
/*  DB_VERSION  = 6846: VEC6800 Tong Jie Application                    */
/*  DB_VERSION  = 6847: VEC6800 Tong Chai Application                   */
/*  DB_VERSION  = 6848: VEC6800 Two Fuel Application                    */
/*  DB_VERSION  = 8000: VEC8000 Genernal Application                    */
/*  DB_VERSION  = 8001: VEC8000 Two Fuel Application                    */
/*  DB_VERSION  = 9000: VEC9000 Genernal Application                    */
/*  DB_VERSION  = 9600: VEC9600 Genernal Application                    */
/* ******************************************************************** */

#define DB_VERSION              6840

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define DB_1000_COMMON_ON       0
#define DB_1000_GENERNAL_ON     0
#define DB_1000_TBS_ON          0
#define DB_1000_TONG_JIE_ON     0
#define DB_1000_ECU_TESTER_ON   0
#define DB_1000_PRES_MONIT_ON   0
#define DB_1000_TWO_FUEL_ON     0
#define DB_4000_COMMON_ON       0
#define DB_4000_GENERNAL_ON     0
#define DB_4000_TONG_JIE_ON     0
#define DB_6800_COMMON_ON       0
#define DB_6800_GENERNAL_ON     0
#define DB_6800_TBS_ON          0
#define DB_6800_SHAN_TUI_ON     0
#define DB_6800_ANA_CAL_ON      0
#define DB_6800_WATER_PUMP_ON   0
#define DB_6800_HUA_WEI_ON      0
#define DB_6800_TONG_JIE_ON     0
#define DB_6800_TONG_CHAI_ON    0
#define DB_6800_TWO_FUEL_ON     0
#define DB_8000_COMMON_ON       0
#define DB_8000_GENERNAL_ON     0
#define DB_8000_TWO_FUEL_ON     0
#define DB_9000_COMMON_ON       0
#define DB_9000_GENERNAL_ON     0
#define DB_9600_COMMON_ON       0
#define DB_9600_GENERNAL_ON     0
#if   ((DB_VERSION / 100)   == 10)
#undef  DB_1000_COMMON_ON
#define DB_1000_COMMON_ON       1
#if   ((DB_VERSION % 10)     == 0)
#undef  DB_1000_GENERNAL_ON
#define DB_1000_GENERNAL_ON     1
#elif ((DB_VERSION % 10)     == 1)
#undef  DB_1000_TBS_ON
#define DB_1000_TBS_ON          1
#elif ((DB_VERSION % 10)     == 2)
#undef  DB_1000_TONG_JIE_ON
#define DB_1000_TONG_JIE_ON     1
#elif ((DB_VERSION % 10)     == 3)
#undef  DB_1000_ECU_TESTER_ON
#define DB_1000_ECU_TESTER_ON   1
#elif ((DB_VERSION % 10)     == 4)
#undef  DB_1000_PRES_MONIT_ON
#define DB_1000_PRES_MONIT_ON   1
#elif ((DB_VERSION % 10)     == 5)
#undef  DB_1000_TWO_FUEL_ON
#define DB_1000_TWO_FUEL_ON     1
#endif
#endif
#if   ((DB_VERSION / 100)   == 40)
#undef  DB_4000_COMMON_ON
#define DB_4000_COMMON_ON       1
#if   ((DB_VERSION % 10)     == 0)
#undef  DB_4000_GENERNAL_ON
#define DB_4000_GENERNAL_ON     1
#elif ((DB_VERSION % 10)     == 1)
#undef  DB_4000_TONG_JIE_ON
#define DB_4000_TONG_JIE_ON     1
#endif
#endif
#if   ((DB_VERSION / 100)   == 68)
#undef  DB_6800_COMMON_ON
#define DB_6800_COMMON_ON       1
#if   ((DB_VERSION % 10)     == 0)
#undef  DB_6800_GENERNAL_ON
#define DB_6800_GENERNAL_ON     1
#elif ((DB_VERSION % 10)     == 1)
#undef  DB_6800_TBS_ON
#define DB_6800_TBS_ON          1
#elif ((DB_VERSION % 10)     == 2)
#undef  DB_6800_SHAN_TUI_ON
#define DB_6800_SHAN_TUI_ON     1
#elif ((DB_VERSION % 10)     == 3)
#undef  DB_6800_ANA_CAL_ON
#define DB_6800_ANA_CAL_ON      1
#elif ((DB_VERSION % 10)     == 4)
#undef  DB_6800_WATER_PUMP_ON
#define DB_6800_WATER_PUMP_ON   1
#elif ((DB_VERSION % 10)     == 5)
#undef  DB_6800_HUA_WEI_ON
#define DB_6800_HUA_WEI_ON      1
#elif ((DB_VERSION % 10)     == 6)
#undef  DB_6800_TONG_JIE_ON
#define DB_6800_TONG_JIE_ON     1
#elif ((DB_VERSION % 10)     == 7)
#undef  DB_6800_TONG_CHAI_ON
#define DB_6800_TONG_CHAI_ON    1
#elif ((DB_VERSION % 10)     == 8)
#undef  DB_6800_TWO_FUEL_ON
#define DB_6800_TWO_FUEL_ON     1
#endif
#endif
#if   ((DB_VERSION / 100)   == 80)
#undef  DB_8000_COMMON_ON
#define DB_8000_COMMON_ON       1
#if   ((DB_VERSION % 10)     == 0)
#undef  DB_8000_GENERNAL_ON
#define DB_8000_GENERNAL_ON     1
#elif ((DB_VERSION % 10)     == 1)
#undef  DB_8000_TWO_FUEL_ON
#define DB_8000_TWO_FUEL_ON     1
#endif
#endif
#if   ((DB_VERSION / 100)   == 90)
#undef  DB_9000_COMMON_ON
#define DB_9000_COMMON_ON       1
#if   ((DB_VERSION % 10)     == 0)
#undef  DB_9000_GENERNAL_ON
#define DB_9000_GENERNAL_ON     1
#endif
#endif
#if   ((DB_VERSION / 100)   == 96)
#undef  DB_9600_COMMON_ON
#define DB_9600_COMMON_ON       1
#if   ((DB_VERSION % 10)     == 0)
#undef  DB_9600_GENERNAL_ON
#define DB_9600_GENERNAL_ON     1
#endif
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#if    (DB_1000_COMMON_ON    == 1)
#define DB_CPU_9S12_ON          1
#define DB_CPU_POWERPC_ON       0
#define DB_CPU_MPC5534_ON       0
#define DB_CPU_MPC5634_ON       0
#define DB_ENGINE_CONTROL_ON    0
#define DB_ENGINE_EFI_ON        0
#define DB_ERR_DECODE_SPN_ON    0
#define DB_SPI_EEPROM_ON        1
#define DB_FLS_EEPROM_OPT_ON    0
#endif
#if    (DB_4000_COMMON_ON    == 1)
#define DB_CPU_9S12_ON          1
#define DB_CPU_POWERPC_ON       0
#define DB_CPU_MPC5534_ON       0
#define DB_CPU_MPC5634_ON       0
#define DB_ENGINE_CONTROL_ON    0
#define DB_ENGINE_EFI_ON        0
#define DB_ERR_DECODE_SPN_ON    0
#define DB_SPI_EEPROM_ON        1
#define DB_FLS_EEPROM_OPT_ON    0
#endif
#if    (DB_6800_COMMON_ON    == 1)
#define DB_CPU_9S12_ON          1
#define DB_CPU_POWERPC_ON       0
#define DB_CPU_MPC5534_ON       0
#define DB_CPU_MPC5634_ON       0
#define DB_ENGINE_CONTROL_ON    1
#define DB_ENGINE_EFI_ON        0
#define DB_ERR_DECODE_SPN_ON    0
#define DB_SPI_EEPROM_ON        1
#define DB_FLS_EEPROM_OPT_ON    0
#endif
#if    (DB_8000_COMMON_ON    == 1)
#define DB_CPU_9S12_ON          0
#define DB_CPU_POWERPC_ON       1
#define DB_CPU_MPC5534_ON       1
#define DB_CPU_MPC5634_ON       0
#define DB_ENGINE_CONTROL_ON    1
#define DB_ENGINE_EFI_ON        1
#define DB_ERR_DECODE_SPN_ON    0
#define DB_SPI_EEPROM_ON        1
#define DB_FLS_EEPROM_OPT_ON    0
#endif
#if    (DB_9000_COMMON_ON    == 1)
#define DB_CPU_9S12_ON          0
#define DB_CPU_POWERPC_ON       1
#define DB_CPU_MPC5534_ON       1
#define DB_CPU_MPC5634_ON       0
#define DB_ENGINE_CONTROL_ON    1
#define DB_ENGINE_EFI_ON        1
#define DB_ERR_DECODE_SPN_ON    0
#define DB_SPI_EEPROM_ON        1
#define DB_FLS_EEPROM_OPT_ON    0
#endif
#if    (DB_9600_COMMON_ON    == 1)
#define DB_CPU_9S12_ON          0
#define DB_CPU_POWERPC_ON       1
#define DB_CPU_MPC5534_ON       0
#define DB_CPU_MPC5634_ON       1
#define DB_ENGINE_CONTROL_ON    1
#define DB_ENGINE_EFI_ON        1
#define DB_ERR_DECODE_SPN_ON    0
#define DB_SPI_EEPROM_ON        1
#define DB_FLS_EEPROM_OPT_ON    0
#endif

/* ******************************************************************** */
/*                           Basis Definition                           */
/* ******************************************************************** */
#define DB_TRUE                (INT08U)0x01
#define DB_FALSE               (INT08U)0x00
#define DB_ERR_NO_ERROR        (INT08U)0x00
#define DB_ERR_INVALID         (INT08U)0x01
#define DB_ERR_MISSING         (INT08U)0x02
#define DB_SIGNED_ZERO         (INT16U)32768

#if    (DB_1000_COMMON_ON    == 1)
#define DB_ACT_FCBUF_SIZE       8
#define DB_STO_FCBUF_SIZE       8
#define DB_PARAM_SIZE           60
#define DB_PARAM_SIZE_NOR       60
#define DB_MEASU_SIZE           60
#define DB_MEASU_SIZE_NOR       50
#define DB_FUNCT_SIZE           2
#define DB_FUNCT_SIZE_NOR       2
#define DB_CURVE_SIZE           2
#define DB_CURVE_SIZE_NOR       2
#define DB_ERROR_SIZE           15
#define DB_SERROR_SIZE          15
#define DB_MILE_SIZE            4
#define DB_HIST_SIZE            15
#define DB_STAT_SIZE            16
#define DB_DF_PARAM_ADDR       (INT16U)0x0000
#define DB_DF_MEASU_ADDR       (INT16U)0x0200
#define DB_DF_FUNCT_ADDR       (INT16U)0x0400
#define DB_DF_CURVE_ADDR       (INT16U)0x0500
#define DB_DF_HIST_BEGIN       (INT16U)0x0600
#define DB_DF_HIST_LAST        (INT16U)0x0A00
#define DB_DF_STAT_BEGIN       (INT16U)0x0B00
#define DB_DF_STAT_LAST        (INT16U)0x0F00
#endif

#if    (DB_4000_COMMON_ON    == 1)
#define DB_PARAM_SIZE           60
#define DB_PARAM_SIZE_NOR       60
#define DB_MEASU_SIZE           80
#define DB_MEASU_SIZE_NOR       65
#define DB_FUNCT_SIZE           2
#define DB_FUNCT_SIZE_NOR       2
#define DB_CURVE_SIZE           2
#define DB_CURVE_SIZE_NOR       2
#define DB_ERROR_SIZE           15
#define DB_SERROR_SIZE          15
#define DB_MILE_SIZE            4
#define DB_HIST_SIZE            15
#define DB_STAT_SIZE            2
#define DB_DF_PARAM_ADDR       (INT16U)0x0000
#define DB_DF_MEASU_ADDR       (INT16U)0x0200
#define DB_DF_FUNCT_ADDR       (INT16U)0x0400
#define DB_DF_CURVE_ADDR       (INT16U)0x0500
#define DB_DF_HIST_BEGIN       (INT16U)0x0600
#define DB_DF_HIST_LAST        (INT16U)0x0A00
#define DB_DF_STAT_BEGIN       (INT16U)0x0B00
#define DB_DF_STAT_LAST        (INT16U)0x0F00
#define DB_MNO_WATER_IN_PRES    111
#define DB_MNO_SPEED_SETP       168
#define DB_MNO_PUMPOIL_PRES     169
#define DB_MNO_CHARG_VOLT       170
#define DB_MNO_WATER_PRES       171
#define DB_MNO_DIFFER_PRES      172
#define DB_MNO_START_TIME       173
#define DB_MNO_SWITCH_STAT      174
#define DB_MNO_OUT_PRES_REF1    199
#define DB_MNO_OUT_PRES_REF2    200
#define DB_MNO_OUT_PRES_ERR1    201
#define DB_MNO_OUT_PRES_ERR2    202
#define DB_MNO_PRES_WARN_ABS    360
#define DB_MNO_PRES_WARN_USER   373
#define DB_MNO_PRES_SETPOINT    375
#define DB_MNO_ECY_STOP         140
#endif

#if    (DB_6800_COMMON_ON    == 1)
#define DB_PICKUP_CRANK1_ON     1
#define DB_PICKUP_CRANK2_ON     1
#define DB_PICKUP_CAM_ON        0
#define DB_CAM_NUM_MIN          2
#define DB_CAM_NUM_DEF          8
#define DB_CAM_NUM_MAX          20
#define DB_SAMPLE_NUM_MIN       2
#define DB_SAMPLE_NUM_DEF       6
#define DB_SAMPLE_NUM_MAX       10
#define DB_PARAM_SIZE           400
#define DB_PARAM_SIZE_NOR       400
#define DB_MEASU_SIZE           320
#define DB_MEASU_SIZE_NOR       260
#define DB_FUNCT_SIZE           120
#define DB_FUNCT_SIZE_NOR       120
#define DB_CURVE_SIZE           1300
#define DB_CURVE_SIZE_NOR       1200
#define DB_ERROR_SIZE           56
#define DB_SERROR_SIZE          56
#define DB_MILE_SIZE            4
#define DB_HIST_SIZE            60
#define DB_STAT_SIZE            100
#define DB_DF_PARAM_ADDR       (INT16U)0x0000
#define DB_DF_MEASU_ADDR       (INT16U)0x0400
#define DB_DF_FUNCT_ADDR       (INT16U)0x0700
#define DB_DF_CURVE_ADDR       (INT16U)0x0800
#define DB_DF_HIST_BEGIN       (INT16U)0x1300
#define DB_DF_HIST_LAST        (INT16U)0x1800
#define DB_DF_STAT_BEGIN       (INT16U)0x1900
#define DB_DF_STAT_LAST        (INT16U)0x1F00
#if    (DB_6800_TBS_ON       == 1)
#undef  DB_PICKUP_CRANK2_ON
#define DB_PICKUP_CRANK2_ON     0
#undef  DB_PICKUP_CAM_ON
#define DB_PICKUP_CAM_ON        1
#endif
#endif

#if    (DB_CPU_POWERPC_ON    == 1)
#define DB_FLS_REG_BASE         0xC3F88000
#define DB_PICKUP_CRANK1_ON     1
#define DB_PICKUP_CRANK2_ON     0
#define DB_PICKUP_CAM_ON        1
#define DB_CAM_NUM_MIN          2
#define DB_CAM_NUM_DEF          4
#define DB_CAM_NUM_MAX          10
#define DB_SAMPLE_NUM_MIN       2
#define DB_SAMPLE_NUM_DEF       6
#define DB_SAMPLE_NUM_MAX       10
#define DB_PARAM_SIZE           460
#define DB_PARAM_SIZE_NOR       460
#define DB_MEASU_SIZE           460
#define DB_MEASU_SIZE_NOR       376
#define DB_FUNCT_SIZE           140
#define DB_FUNCT_SIZE_NOR       140
#define DB_CURVE_SIZE           3000
#define DB_CURVE_SIZE_NOR       2900
#define DB_ERROR_SIZE           80
#define DB_SERROR_SIZE          80
#define DB_MILE_SIZE            4
#define DB_HIST_SIZE            84
#define DB_STAT_SIZE            100
#define DB_PARAM_SIZE8         (DB_PARAM_SIZE * 2)
#define DB_PARAM_SIZE8_NOR     (DB_PARAM_SIZE_NOR * 2)
#define DB_MEASU_SIZE8         (DB_MEASU_SIZE * 2)
#define DB_MEASU_SIZE8_NOR     (DB_MEASU_SIZE_NOR * 2)
#define DB_FUNCT_SIZE8         (DB_FUNCT_SIZE * 2)
#define DB_FUNCT_SIZE8_NOR     (DB_FUNCT_SIZE_NOR * 2)
#define DB_CURVE_SIZE8         (DB_CURVE_SIZE * 2)
#define DB_CURVE_SIZE8_NOR     (DB_CURVE_SIZE_NOR * 2)
#define DB_ERROR_SIZE8         (DB_ERROR_SIZE * 2)
#define DB_SERROR_SIZE8        (DB_SERROR_SIZE * 2)
#define DB_HIST_SIZE8          (DB_HIST_SIZE * 2)
#define DB_STAT_SIZE8          (DB_STAT_SIZE * 2)
#define DB_EE_PARAM_ADDR       (INT16U)0x0000
#define DB_EE_MEASU_ADDR       (INT16U)0x0800
#define DB_EE_FUNCT_ADDR       (INT16U)0x1000
#define DB_EE_CURVE_ADDR       (INT16U)0x1800
#define DB_EE_HIST_ADDR        (INT16U)0x3800
#define DB_EE_STAT_ADDR        (INT16U)0x3D00
#define DB_EE_PARAM_ID         (INT16U)0x0001
#define DB_EE_MEASU_ID         (INT16U)0x0002
#define DB_EE_FUNCT_ID         (INT16U)0x0003
#define DB_EE_CURVE_ID         (INT16U)0x0004
#define DB_EE_HIST_ID          (INT16U)0x0005
#define DB_EE_STAT_ID          (INT16U)0x0006
#define DB_FLS_BLOCK_START      0x000A0000
#define DB_FLS_BLOCK_SIZE       0x00020000
#define DB_FLS_BLOCK_MASK       0x00000002
#define DB_FLS_PARAM_ADDR       0x000A0000
#define DB_FLS_MEASU_ADDR       0x000A0800
#define DB_FLS_FUNCT_ADDR       0x000A1000
#define DB_FLS_CURVE_ADDR       0x000A1800
#if    (DB_CPU_MPC5634_ON    == 1)
#undef  DB_FLS_REG_BASE
#define DB_FLS_REG_BASE         0xC3FB0000
#endif
#endif

/* ******************************************************************** */
/*                       VEC1000 Const Definition                       */
/* ******************************************************************** */
#if    (DB_1000_COMMON_ON    == 1)
#define DB_MNO_TEETH1           1
#define DB_MNO_SPEED_IDLE1      3
#define DB_MNO_SPEED_MAX1       6
#define DB_MNO_SPEED_OVER       12
#define DB_MNO_GAIN             24
#define DB_MNO_STABILITY        25
#define DB_MNO_DERIVATIVE       26
#define DB_MNO_IDLE_CORR        75
#define DB_MNO_RATE_CORR        76
#define DB_MNO_SPEED1           1
#define DB_MNO_SPEED2           2
#define DB_MNO_SETPOINT         6
#define DB_MNO_RACK_OUT         34
#define DB_MNO_ADC68_0          117
#define DB_MNO_ADC68_1          118
#define DB_MNO_ADC68_2          119
#define DB_MNO_ADC68_3          120
#define DB_MNO_ADC68_4          121
#define DB_MNO_ADC68_5          122
#define DB_MNO_ADC68_6          123
#define DB_MNO_RACK_IN          123
#define DB_MNO_ADC68_7          124
#define DB_MNO_ADC68_8          125
#define DB_MNO_ADC68_9          126
#define DB_MNO_ADC68_10         127
#define DB_MNO_ADC68_11         128
#define DB_MNO_ADC68_12         129
#define DB_MNO_ADC68_13         130
#define DB_MNO_ADC68_14         131
#define DB_MNO_ADC68_15         132
#define DB_MNO_SWITCHES         136
#define DB_MNO_ECY_STOP         140
#define DB_MNO_SOFT_VERSION     148
#define DB_MNO_VSPEED           150
#define DB_ECU_SERROR_SIZE      56
#define DB_ECU_SERROR_BEGIN     264
#define DB_ENG_SPEED_DEF       (INT16S)0
#define DB_ENG_SPEED_MIN       (INT16S)0
#define DB_ENG_SPEED_MAX       (INT16S)3000
#define DB_VEH_SPEED_DEF       (INT16S)0
#define DB_VEH_SPEED_MIN       (INT16S)0
#define DB_VEH_SPEED_MAX       (INT16S)300
#define DB_ENG_LOAD_DEF        (INT16S)0
#define DB_ENG_LOAD_MIN        (INT16S)0
#define DB_ENG_LOAD_MAX        (INT16S)100
#define DB_ENG_HOUR_DEF        (INT16S)0
#define DB_ENG_HOUR_MIN        (INT16S)0
#define DB_ENG_HOUR_MAX        (INT16S)30000
#define DB_COOL_TEMP_DEF       (INT16S)0
#define DB_COOL_TEMP_MIN       (INT16S)(-40)
#define DB_COOL_TEMP_MAX       (INT16S)140
#define DB_AIR_TEMP_DEF        (INT16S)0
#define DB_AIR_TEMP_MIN        (INT16S)(-40)
#define DB_AIR_TEMP_MAX        (INT16S)140
#define DB_OIL_TEMP_DEF        (INT16S)0
#define DB_OIL_TEMP_MIN        (INT16S)(-40)
#define DB_OIL_TEMP_MAX        (INT16S)140
#define DB_FUEL_TEMP_DEF       (INT16S)0
#define DB_FUEL_TEMP_MIN       (INT16S)(-40)
#define DB_FUEL_TEMP_MAX       (INT16S)140
#define DB_AIR_PRES_DEF        (INT16S)0
#define DB_AIR_PRES_MIN        (INT16S)0
#define DB_AIR_PRES_MAX        (INT16S)1000
#define DB_OIL_PRES_DEF        (INT16S)0
#define DB_OIL_PRES_MIN        (INT16S)0
#define DB_OIL_PRES_MAX        (INT16S)1000
#define DB_FUEL_PRES_DEF       (INT16S)0
#define DB_FUEL_PRES_MIN       (INT16S)0
#define DB_FUEL_PRES_MAX       (INT16S)1000
#define DB_RAIL_PRES_DEF       (INT16S)0
#define DB_RAIL_PRES_MIN       (INT16S)0
#define DB_RAIL_PRES_MAX       (INT16S)200
#define DB_FUEL_ECONOMY_DEF    (INT16S)0
#define DB_FUEL_ECONOMY_MIN    (INT16S)0
#define DB_FUEL_ECONOMY_MAX    (INT16S)100
#define DB_FUEL_RATE_DEF       (INT16S)0
#define DB_FUEL_RATE_MIN       (INT16S)0
#define DB_FUEL_RATE_MAX       (INT16S)100
#define DB_PEDAL_POSI_DEF      (INT16S)0
#define DB_PEDAL_POSI_MIN      (INT16S)0
#define DB_PEDAL_POSI_MAX      (INT16S)100
#define DB_GEAR_POSI_DEF       (INT16S)0
#define DB_GEAR_POSI_MIN       (INT16S)0
#define DB_GEAR_POSI_MAX       (INT16S)10
#define DB_SYS_VOLT_DEF        (INT16S)24
#define DB_SYS_VOLT_MIN        (INT16S)0
#define DB_SYS_VOLT_MAX        (INT16S)50
#define DB_ENG_CONFIG_DEF      (INT16S)0
#define DB_ENG_CONFIG_MIN      (INT16S)0
#define DB_ENG_CONFIG_MAX      (INT16S)1000
#define DB_ACT_FAULT_DEF       (INT16S)0
#define DB_ACT_FAULT_MIN       (INT16S)0
#define DB_ACT_FAULT_MAX       (INT16S)127
#define DB_STO_FAULT_DEF       (INT16S)0
#define DB_STO_FAULT_MIN       (INT16S)0
#define DB_STO_FAULT_MAX       (INT16S)127
#define DB_CHARG_VOLT_DEF      (INT16S)24
#define DB_CHARG_VOLT_MIN      (INT16S)0
#define DB_CHARG_VOLT_MAX      (INT16S)50
#define DB_START_TIME_DEF      (INT16S)0
#define DB_START_TIME_MIN      (INT16S)0
#define DB_START_TIME_MAX      (INT16S)100
#define DB_WATER_PRES_DEF      (INT16S)0
#define DB_WATER_PRES_MIN      (INT16S)0
#define DB_WATER_PRES_MAX      (INT16S)1000
#define DB_DIFFER_PRES_DEF     (INT16S)0
#define DB_DIFFER_PRES_MIN     (INT16S)0
#define DB_DIFFER_PRES_MAX     (INT16S)1000
#define DB_PUMPOIL_PRES_DEF    (INT16S)0
#define DB_PUMPOIL_PRES_MIN    (INT16S)0
#define DB_PUMPOIL_PRES_MAX    (INT16S)1000
#define DB_SPEED_SETP_DEF      (INT16S)0
#define DB_SPEED_SETP_MIN      (INT16S)0
#define DB_SPEED_SETP_MAX      (INT16S)3000
#define DB_SWITCH_STAT_DEF     (INT16S)0
#define DB_SWITCH_STAT_MIN     (INT16S)0
#define DB_SWITCH_STAT_MAX     (INT16S)30000
#define DB_WATER_IN_PRES_DEF   (INT16S)0
#define DB_WATER_IN_PRES_MIN   (INT16S)0
#define DB_WATER_IN_PRES_MAX   (INT16S)1000
#define DB_SWITCH_OUT_DEF      (INT16S)0
#define DB_SWITCH_OUT_MIN      (INT16S)0
#define DB_SWITCH_OUT_MAX      (INT16S)111
#define DB_SYS_TEMP_DEF        (INT16S)0
#define DB_SYS_TEMP_MIN        (INT16S)(-40)
#define DB_SYS_TEMP_MAX        (INT16S)140
#endif

/* ******************************************************************** */
/*                     VEC1000 : Genernal Application                   */
/* ******************************************************************** */
#if    (DB_1000_GENERNAL_ON  == 1)
#define DB_DISP_PAR_NUM         20
#define DB_NO_ENG_SPEED         0
#define DB_NO_VEH_SPEED         1
#define DB_NO_ENG_LOAD          2
#define DB_NO_ENG_HOUR          3
#define DB_NO_COOL_TEMP         4
#define DB_NO_AIR_TEMP          5
#define DB_NO_OIL_TEMP          6
#define DB_NO_FUEL_TEMP         7
#define DB_NO_AIR_PRES          8
#define DB_NO_OIL_PRES          9
#define DB_NO_FUEL_PRES         10
#define DB_NO_RAIL_PRES         11
#define DB_NO_FUEL_ECONOMY      12
#define DB_NO_FUEL_RATE         13
#define DB_NO_PEDAL_POSI        14
#define DB_NO_GEAR_POSI         15
#define DB_NO_SYS_VOLT          16
#define DB_NO_ENG_CONFIG        17
#define DB_NO_ACT_FAULT         18
#define DB_NO_STO_FAULT         19
#endif

/* ******************************************************************** */
/*                        VEC1000 : TBS Application                     */
/* ******************************************************************** */
#if    (DB_1000_TBS_ON       == 1)
#define DB_DISP_PAR_NUM         20
#define DB_NO_ENG_SPEED         0
#define DB_NO_VEH_SPEED         1
#define DB_NO_ENG_LOAD          2
#define DB_NO_ENG_HOUR          3
#define DB_NO_COOL_TEMP         4
#define DB_NO_AIR_TEMP          5
#define DB_NO_OIL_TEMP          6
#define DB_NO_FUEL_TEMP         7
#define DB_NO_AIR_PRES          8
#define DB_NO_OIL_PRES          9
#define DB_NO_FUEL_PRES         10
#define DB_NO_RAIL_PRES         11
#define DB_NO_FUEL_ECONOMY      12
#define DB_NO_FUEL_RATE         13
#define DB_NO_PEDAL_POSI        14
#define DB_NO_GEAR_POSI         15
#define DB_NO_SYS_VOLT          16
#define DB_NO_ENG_CONFIG        17
#define DB_NO_ACT_FAULT         18
#define DB_NO_STO_FAULT         19
#endif

/* ******************************************************************** */
/*                     VEC1000 : Tong Jie Application                   */
/* ******************************************************************** */
#if    (DB_1000_TONG_JIE_ON  == 1)
#define DB_DISP_PAR_NUM         16
#define DB_NO_ENG_SPEED         0
#define DB_NO_COOL_TEMP         1
#define DB_NO_OIL_PRES          2
#define DB_NO_OIL_TEMP          3
#define DB_NO_ENG_LOAD          4
#define DB_NO_ENG_HOUR          5
#define DB_NO_SYS_VOLT          6
#define DB_NO_CHARG_VOLT        7
#define DB_NO_WATER_IN_PRES     8
#define DB_NO_DIFFER_PRES       9
#define DB_NO_WATER_PRES        10
#define DB_NO_PUMPOIL_PRES      11
#define DB_NO_START_TIME        12
#define DB_NO_SWITCH_STAT       13
#define DB_NO_ACT_FAULT         14
#define DB_NO_STO_FAULT         15
#define DB_MNO_WATER_IN_PRES    111
#define DB_MNO_SPEED_SETP       168
#define DB_MNO_PUMPOIL_PRES     169
#define DB_MNO_CHARG_VOLT       170
#define DB_MNO_WATER_PRES       171
#define DB_MNO_DIFFER_PRES      172
#define DB_MNO_START_TIME       173
#define DB_MNO_SWITCH_STAT      174
#define DB_MNO_OUT_PRES_REF1    199
#define DB_MNO_OUT_PRES_REF2    200
#define DB_MNO_OUT_PRES_ERR1    201
#define DB_MNO_OUT_PRES_ERR2    202
#define DB_MNO_PRES_WARN_ABS    360
#define DB_MNO_PRES_WARN_USER   373
#define DB_MNO_PRES_SETPOINT    375
#endif

/* ******************************************************************** */
/*                    VEC1000 : ECU Tester Application                  */
/* ******************************************************************** */
#if    (DB_1000_ECU_TESTER_ON == 1)
#define DB_DISP_PAR_NUM         20
#define DB_NO_ENG_SPEED         0
#define DB_NO_VEH_SPEED         1
#define DB_NO_ENG_LOAD          2
#define DB_NO_ENG_HOUR          3
#define DB_NO_COOL_TEMP         4
#define DB_NO_AIR_TEMP          5
#define DB_NO_OIL_TEMP          6
#define DB_NO_FUEL_TEMP         7
#define DB_NO_AIR_PRES          8
#define DB_NO_OIL_PRES          9
#define DB_NO_FUEL_PRES         10
#define DB_NO_RAIL_PRES         11
#define DB_NO_FUEL_ECONOMY      12
#define DB_NO_FUEL_RATE         13
#define DB_NO_PEDAL_POSI        14
#define DB_NO_GEAR_POSI         15
#define DB_NO_SYS_VOLT          16
#define DB_NO_ENG_CONFIG        17
#define DB_NO_ACT_FAULT         18
#define DB_NO_STO_FAULT         19
#endif

/* ******************************************************************** */
/*                   VEC1000 : PressMonitor Application                 */
/* ******************************************************************** */
#if    (DB_1000_PRES_MONIT_ON == 1)
#define DB_DISP_PAR_NUM         8
#define DB_NO_WATER_PRES        0
#define DB_NO_PUMPOIL_PRES      1
#define DB_NO_WATER_IN_PRES     2
#define DB_NO_DIFFER_PRES       3
#define DB_NO_SWITCH_OUT        4
#define DB_NO_SYS_VOLT          5
#define DB_NO_ACT_FAULT         6
#define DB_NO_STO_FAULT         7
#define DB_SENS_PAR_NUM         32
#define aDBpSensPar             aDBpParamBackBegin
#define	usDBpSens1ErrLow        usDBpParamBackup0
#define	usDBpSens1ErrHigh       usDBpParamBackup1
#define	usDBpSens1RefLow        usDBpParamBackup2
#define	usDBpSens1RefHigh       usDBpParamBackup3
#define	usDBpSens1ValLow        usDBpParamBackup4
#define	usDBpSens1ValHigh       usDBpParamBackup5
#define	usDBpSens1WarnLow       usDBpParamBackup6
#define	usDBpSens1WarnHigh      usDBpParamBackup7
#define	usDBpSens2ErrLow        usDBpParamBackup8
#define	usDBpSens2ErrHigh       usDBpParamBackup9
#define	usDBpSens2RefLow        usDBpParamBackup10
#define	usDBpSens2RefHigh       usDBpParamBackup11
#define	usDBpSens2ValLow        usDBpParamBackup12
#define	usDBpSens2ValHigh       usDBpParamBackup13
#define	usDBpSens2WarnLow       usDBpParamBackup14
#define	usDBpSens2WarnHigh      usDBpParamBackup15
#define	usDBpSens3ErrLow        usDBpParamBackup16
#define	usDBpSens3ErrHigh       usDBpParamBackup17
#define	usDBpSens3RefLow        usDBpParamBackup18
#define	usDBpSens3RefHigh       usDBpParamBackup19
#define	usDBpSens3ValLow        usDBpParamBackup20
#define	usDBpSens3ValHigh       usDBpParamBackup21
#define	usDBpSens3WarnLow       usDBpParamBackup22
#define	usDBpSens3WarnHigh      usDBpParamBackup23
#define	usDBpSens4ErrLow        usDBpParamBackup24
#define	usDBpSens4ErrHigh       usDBpParamBackup25
#define	usDBpSens4RefLow        usDBpParamBackup26
#define	usDBpSens4RefHigh       usDBpParamBackup27
#define	usDBpSens4ValLow        usDBpParamBackup28
#define	usDBpSens4ValHigh       usDBpParamBackup29
#define	usDBpSens4WarnLow       usDBpParamBackup30
#define	usDBpSens4WarnHigh      usDBpParamBackup31
#define	usDBmSens1Input         usDBmMeasusBackup0
#define	usDBmSens2Input         usDBmMeasusBackup1
#define	usDBmSens3Input         usDBmMeasusBackup2
#define	usDBmSens4Input         usDBmMeasusBackup3
#define	usDBmErrSens1           usDBmErrBackup0
#define	usDBmErrSens2           usDBmErrBackup1
#define	usDBmErrSens3           usDBmErrBackup2
#define	usDBmErrSens4           usDBmErrBackup3
#define	usDBmErrPresIn          usDBmErrBackup4
#define	usDBmErrPresOut         usDBmErrBackup5
#define	usDBmErrPresDiff        usDBmErrBackup6
#define	usDBmErrPumpOilPres     usDBmErrBackup7
#endif

/* ******************************************************************** */
/*                     VEC1000 : Two Fuel Application                   */
/* ******************************************************************** */
#if    (DB_1000_TWO_FUEL_ON  == 1)
#define DB_DISP_PAR_NUM         20
#define DB_NO_ENG_SPEED         0
#define DB_NO_VEH_SPEED         1
#define DB_NO_ENG_LOAD          2
#define DB_NO_ENG_HOUR          3
#define DB_NO_COOL_TEMP         4
#define DB_NO_AIR_TEMP          5
#define DB_NO_OIL_TEMP          6
#define DB_NO_FUEL_TEMP         7
#define DB_NO_AIR_PRES          8
#define DB_NO_OIL_PRES          9
#define DB_NO_FUEL_PRES         10
#define DB_NO_RAIL_PRES         11
#define DB_NO_FUEL_ECONOMY      12
#define DB_NO_FUEL_RATE         13
#define DB_NO_PEDAL_POSI        14
#define DB_NO_GEAR_POSI         15
#define DB_NO_SYS_VOLT          16
#define DB_NO_ENG_CONFIG        17
#define DB_NO_ACT_FAULT         18
#define DB_NO_STO_FAULT         19
#endif

/* ******************************************************************** */
/*                         VEC1000 Type Definition                      */
/* ******************************************************************** */
#if (DB_1000_COMMON_ON == 1)
typedef struct db_par_tcb
{   const INT08U *pName;
    const INT08U *pCName;
    const INT08U *pBName;
    const INT08U *pUnit;
    INT16S        ssValue;
    INT16S        ssMin;
    INT16S        ssMax;
    INT08U        ucPos;
    INT08U        ucErr;
}   DB_PAR_TCB;
typedef struct db_ccp_par
{   INT16U        usWhich;
    INT16U        usValue;
}   DB_CCP_PAR;
typedef struct
{   const INT08U *pEMessage;
    const INT08U *pCMessage;
    INT08U        ucKeyComd;
    INT08U        ucDispCurr;
    INT08U        ucMessageOn;
    INT08U        ucDisp1Posi;
    INT08U       *pDisp4Posi;
    INT08U        ucDisp5Posi;
    INT08U        ucDispSleep;
    INT08U        ucDispStart;
    INT08U        ucMenuBeg;
    INT08U        ucMenuSel;
    INT08U        ucMenuSelOld;
    INT08U        ucBitFlag;
    INT08U        ucLanguage;
    INT08U        ucCCPErr;
    INT08U        ucErrTimer;
    INT08U        ucContrast;
    INT08U        ucBackLight;
    INT08U        ucDispWrong;
    INT08U        ucDispRight;
    INT16U        usPassRight;
    INT16U        usPassword;
    INT16U        usFaultCurr;
    INT16U        usFaultDisp;
}   DB_MENU_STR;
typedef struct app_tj_pres_str
{   INT16U        usEcuPresRef1;
    INT16U        usEcuPresRef2;
    INT16U        usEcuPresErr1;
    INT16U        usEcuPresErr2;
    INT16U        usEcuPresAbs;
    INT16U        usEcuPresUser;
    INT16U        usEcuPresSetp;
    INT16U        usDispPresSen1;
    INT16U        usDispPresSen2;
    INT16U        usDispPresAbs;
    INT16U        usDispPresUser;
    INT16U        usDispTimeStop;
    INT16U        usDispPresSetp;
}   DB_TJ_PRES_STR;
#endif

/* ******************************************************************** */
/*                           Variable Definition                        */
/* ******************************************************************** */
DB_EXT INT16U usDBHistDataHead;
DB_EXT INT16U usDBHistAddrCurr;
DB_EXT INT16U usDBStatDataHead;
DB_EXT INT16U usDBStatAddrCurr;
DB_EXT INT16U aDBParam[DB_PARAM_SIZE];
DB_EXT INT16U aDBMeasu[DB_MEASU_SIZE];
DB_EXT INT16U aDBFunct[DB_FUNCT_SIZE];
DB_EXT INT16U aDBCurve[DB_CURVE_SIZE];
#if   (DB_1000_COMMON_ON == 1)
DB_EXT INT08U ucDBDispParTotle;
DB_EXT INT16U usDBECUSoftVersion;
DB_EXT INT16U aDBEcuParPid[3];
DB_EXT INT16U aDBEcuParRange[6];
DB_EXT INT16U aDBActFCBuffer[DB_ACT_FCBUF_SIZE];
DB_EXT INT16U aDBStoFCBuffer[DB_STO_FCBUF_SIZE];
DB_EXT INT08U aDBDispParIndex[DB_DISP_PAR_NUM];
DB_EXT DB_CCP_PAR aCcpParam;
DB_EXT DB_CCP_PAR aCcpMeasu;
DB_EXT DB_CCP_PAR aCcpFunct;
DB_EXT DB_CCP_PAR aCcpCurve;
DB_EXT DB_PAR_TCB aDBDisplay[DB_DISP_PAR_NUM];
#endif
#if   (DB_6800_COMMON_ON == 1)
DB_EXT INT08U ucDBCamNum;
DB_EXT INT08U ucDBCamMode;
DB_EXT INT08U ucDBSampleNum;
DB_EXT INT08U ucDBSampleMode;
#endif

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */

DB_EXT void   DBInit(void);
DB_EXT void   DBInitErrors(void);
DB_EXT void   DBInitSErrors(void);
DB_EXT void   DBInitMeasument(void);
DB_EXT BOOL   DBCheckParamScope(void);
DB_EXT BOOL   DBReadParamNor(void);
DB_EXT BOOL   DBReadMeasuNor(void);
DB_EXT BOOL   DBReadMeasuHist(void);
DB_EXT BOOL   DBReadFunctNor(void);
DB_EXT BOOL   DBReadCurveNor(void);
DB_EXT BOOL   DBReadCurveStat(void);
DB_EXT BOOL   DBWriteParamNor(void);
DB_EXT BOOL   DBWriteMeasuNor(void);
DB_EXT BOOL   DBWriteMeasuHist(void);
DB_EXT BOOL   DBWriteFunctNor(void);
DB_EXT BOOL   DBWriteCurveNor(void);
DB_EXT BOOL   DBWriteCurveStat(void);
#if   (DB_1000_COMMON_ON == 1)
DB_EXT void   DBInitCcpPar(void);
DB_EXT void   DBInitDispPar(void);
DB_EXT void   DBClearFCBuf(INT08U ucBuf);
DB_EXT INT16U DBGetFCBufCode(INT08U ucBuf);
DB_EXT void   DBPutFCBufCode(INT16U usCode, INT08U ucBuf);
DB_EXT const  INT08U *DBDecodeFault(INT16U usCode, INT08U usLanguage);
DB_EXT void   DBSetDispParIndex(void);
DB_EXT INT08U DBGetNextDisp1Posi(INT08U ucPrevOrNext);
DB_EXT INT08U *DBGetNextDisp4Posi(INT08U ucPrevOrNext);
#endif
#if   (DB_CPU_9S12_ON == 1)
DB_EXT BOOL   DBReadEcuData(INT16U usAddr, INT16U *pData, INT16U usSize);
DB_EXT BOOL   DBWriteEcuData(INT16U usAddr, INT16U *pData, INT16U usSize);
DB_EXT BOOL   DBReadEcuHist(INT16U *pData, INT16U usSize, INT16U usBegAdr, INT16U usLstAdr);
DB_EXT BOOL   DBWriteEcuHist(INT16U *pData, INT16U usSize, INT16U usBegAdr, INT16U usLstAdr);
DB_EXT BOOL   DBReadEcuStat(INT16U *pData, INT16U usSize, INT16U usBegAdr, INT16U usLstAdr);
DB_EXT BOOL   DBWriteEcuStat(INT16U *pData, INT16U usSize, INT16U usBegAdr, INT16U usLstAdr);
#endif
#if   (DB_CPU_POWERPC_ON == 1)
DB_EXT BOOL   DBEepReadParamNor(void);
DB_EXT BOOL   DBEepReadMeasuNor(void);
DB_EXT BOOL   DBEepReadMeasuHist(void);
DB_EXT BOOL   DBEepReadFunctNor(void);
DB_EXT BOOL   DBEepReadCurveNor(void);
DB_EXT BOOL   DBEepReadCurveStat(void);
DB_EXT BOOL   DBGetSpiEepromData(INT16U size, INT16U addr, INT16U *pdat);
DB_EXT BOOL   DBPutSpiEepromData(INT16U size, INT16U addr, INT16U *pdat);
DB_EXT BOOL   DBUpdateSpiEepromData(INT16U size, INT16U addr, INT16U *pdat);
#if   (DB_FLS_EEPROM_OPT_ON == 1)
DB_EXT INT08U DBPutFlsEepromData(INT32U uiAddr, INT16U *pData, INT16U usSize);
DB_EXT INT08U DBGetFlsEepromData(INT32U uiAddr, INT16U *pData, INT16U usSize);
#endif
#endif

/* ******************************************************************** */
/*                      VEC1000 Parameter Definition                    */
/* ******************************************************************** */
#if    (DB_1000_COMMON_ON == 1)
#define aDBpParamPosBegin                 (aDBParam+   0)
#define usDBpParPosition0               (*(aDBParam+   0))
#define usDBpParPosition1               (*(aDBParam+   1))
#define usDBpParPosition2               (*(aDBParam+   2))
#define usDBpParPosition3               (*(aDBParam+   3))
#define usDBpParPosition4               (*(aDBParam+   4))
#define usDBpParPosition5               (*(aDBParam+   5))
#define usDBpParPosition6               (*(aDBParam+   6))
#define usDBpParPosition7               (*(aDBParam+   7))
#define usDBpParPosition8               (*(aDBParam+   8))
#define usDBpParPosition9               (*(aDBParam+   9))
#define usDBpParPosition10              (*(aDBParam+  10))
#define usDBpParPosition11              (*(aDBParam+  11))
#define usDBpParPosition12              (*(aDBParam+  12))
#define usDBpParPosition13              (*(aDBParam+  13))
#define usDBpParPosition14              (*(aDBParam+  14))
#define usDBpParPosition15              (*(aDBParam+  15))
#define usDBpParPosition16              (*(aDBParam+  16))
#define usDBpParPosition17              (*(aDBParam+  17))
#define usDBpParPosition18              (*(aDBParam+  18))
#define usDBpParPosition19              (*(aDBParam+  19))
#define usDBpLanguage                   (*(aDBParam+  20))
#define usDBpContrast                   (*(aDBParam+  21))
#define usDBpBackLight                  (*(aDBParam+  22))
#define usDBpDispStart                  (*(aDBParam+  23))
#define usDBpErrDecodeMode              (*(aDBParam+  24))
#define	aDBpParamBackBegin                (aDBParam+  25)
#define	usDBpParamBackup0               (*(aDBParam+  25))
#define	usDBpParamBackup1               (*(aDBParam+  26))
#define	usDBpParamBackup2               (*(aDBParam+  27))
#define	usDBpParamBackup3               (*(aDBParam+  28))
#define	usDBpParamBackup4               (*(aDBParam+  29))
#define	usDBpParamBackup5               (*(aDBParam+  30))
#define	usDBpParamBackup6               (*(aDBParam+  31))
#define	usDBpParamBackup7               (*(aDBParam+  32))
#define	usDBpParamBackup8               (*(aDBParam+  33))
#define	usDBpParamBackup9               (*(aDBParam+  34))
#define	usDBpParamBackup10              (*(aDBParam+  35))
#define	usDBpParamBackup11              (*(aDBParam+  36))
#define	usDBpParamBackup12              (*(aDBParam+  37))
#define	usDBpParamBackup13              (*(aDBParam+  38))
#define	usDBpParamBackup14              (*(aDBParam+  39))
#define	usDBpParamBackup15              (*(aDBParam+  40))
#define	usDBpParamBackup16              (*(aDBParam+  41))
#define	usDBpParamBackup17              (*(aDBParam+  42))
#define	usDBpParamBackup18              (*(aDBParam+  43))
#define	usDBpParamBackup19              (*(aDBParam+  44))
#define	usDBpParamBackup20              (*(aDBParam+  45))
#define	usDBpParamBackup21              (*(aDBParam+  46))
#define	usDBpParamBackup22              (*(aDBParam+  47))
#define	usDBpParamBackup23              (*(aDBParam+  48))
#define	usDBpParamBackup24              (*(aDBParam+  49))
#define	usDBpParamBackup25              (*(aDBParam+  50))
#define	usDBpParamBackup26              (*(aDBParam+  51))
#define	usDBpParamBackup27              (*(aDBParam+  52))
#define	usDBpParamBackup28              (*(aDBParam+  53))
#define	usDBpParamBackup29              (*(aDBParam+  54))
#define	usDBpParamBackup30              (*(aDBParam+  55))
#define	usDBpParamBackup31              (*(aDBParam+  56))
#define	usDBpParamBackup32              (*(aDBParam+  57))
#define	usDBpParamBackup33              (*(aDBParam+  58))
#define	usDBpParamBackup34              (*(aDBParam+  59))
#endif

/* ******************************************************************** */
/*                   VEC1000 Measurement Definition                     */
/* ******************************************************************** */
#if    (DB_1000_COMMON_ON == 1)
#define	aDBmAnalogIn                      (aDBMeasu+   0)
#define usDBmAnalogIn00                 (*(aDBMeasu+   0))
#define usDBmAnalogIn01                 (*(aDBMeasu+   1))
#define usDBmAnalogIn02                 (*(aDBMeasu+   2))
#define usDBmAnalogIn03                 (*(aDBMeasu+   3))
#define usDBmAnalogIn04                 (*(aDBMeasu+   4))
#define usDBmAnalogIn05                 (*(aDBMeasu+   5))
#define usDBmAnalogIn06                 (*(aDBMeasu+   6))
#define usDBmAnalogIn07                 (*(aDBMeasu+   7))
#define usDBmAnalogIn08                 (*(aDBMeasu+   8))
#define usDBmAnalogIn09                 (*(aDBMeasu+   9))
#define usDBmAnalogIn10                 (*(aDBMeasu+  10))
#define usDBmAnalogIn11                 (*(aDBMeasu+  11))
#define usDBmAnalogIn12                 (*(aDBMeasu+  12))
#define usDBmAnalogIn13                 (*(aDBMeasu+  13))
#define usDBmAnalogIn14                 (*(aDBMeasu+  14))
#define usDBmAnalogIn15                 (*(aDBMeasu+  15))
#define usDBmPowerSupply                (*(aDBMeasu+  16))
#define usDBmTempIntern                 (*(aDBMeasu+  17))
#define	usDBmLightCtrl                  (*(aDBMeasu+  18))
#define usDBmBinaryIn                   (*(aDBMeasu+  19))
#define	usDBmCanState                   (*(aDBMeasu+  20))
#define	usDBmStopLampActive             (*(aDBMeasu+  21))
#define	usDBmWarnLampActive             (*(aDBMeasu+  22))
#define	usDBmMeasusBackup0              (*(aDBMeasu+  23))
#define	usDBmMeasusBackup1              (*(aDBMeasu+  24))
#define	usDBmMeasusBackup2              (*(aDBMeasu+  25))
#define	usDBmMeasusBackup3              (*(aDBMeasu+  26))
#define	usDBmMeasusBackup4              (*(aDBMeasu+  27))
#define	usDBmMeasusBackup5              (*(aDBMeasu+  28))
#define	usDBmMeasusBackup6              (*(aDBMeasu+  29))
#define aDBmErrBegin                      (aDBMeasu+  30)
#define	usDBmErrCAN                     (*(aDBMeasu+  30))
#define	usDBmErrLIN                     (*(aDBMeasu+  31))
#define	usDBmErrLogical                 (*(aDBMeasu+  32))
#define	usDBmErrDataCheck               (*(aDBMeasu+  33))
#define	usDBmErrClearFlash              (*(aDBMeasu+  34))
#define	usDBmErrParamStore              (*(aDBMeasu+  35))
#define usDBmErrBackup0                 (*(aDBMeasu+  36))
#define usDBmErrBackup1                 (*(aDBMeasu+  37))
#define usDBmErrBackup2                 (*(aDBMeasu+  38))
#define usDBmErrBackup3                 (*(aDBMeasu+  39))
#define usDBmErrBackup4                 (*(aDBMeasu+  40))
#define usDBmErrBackup5                 (*(aDBMeasu+  41))
#define usDBmErrBackup6                 (*(aDBMeasu+  42))
#define usDBmErrBackup7                 (*(aDBMeasu+  43))
#define usDBmErrBackup8                 (*(aDBMeasu+  44))
#define aDBmHistBegin                     (aDBMeasu+  45)
#define aDBmSErrBegin                     (aDBMeasu+  45)
#define	usDBmSErrCAN                    (*(aDBMeasu+  45))
#define	usDBmSErrLIN                    (*(aDBMeasu+  46))
#define	usDBmSErrLogical                (*(aDBMeasu+  47))
#define	usDBmSErrDataCheck              (*(aDBMeasu+  48))
#define	usDBmSErrClearFlash             (*(aDBMeasu+  49))
#define	usDBmSErrParamStore             (*(aDBMeasu+  50))
#define usDBmSErrBackup0                (*(aDBMeasu+  51))
#define usDBmSErrBackup1                (*(aDBMeasu+  52))
#define usDBmSErrBackup2                (*(aDBMeasu+  53))
#define usDBmSErrBackup3                (*(aDBMeasu+  54))
#define usDBmSErrBackup4                (*(aDBMeasu+  55))
#define usDBmSErrBackup5                (*(aDBMeasu+  56))
#define usDBmSErrBackup6                (*(aDBMeasu+  57))
#define usDBmSErrBackup7                (*(aDBMeasu+  58))
#define usDBmSErrBackup8                (*(aDBMeasu+  59))
#endif

/* ******************************************************************** */
/*                     VEC1000 Function Definition                      */
/* ******************************************************************** */
#if    (DB_1000_COMMON_ON == 1)
#define	usDBfFunctBackup0               (*(aDBFunct+   0))
#define	usDBfFunctBackup1               (*(aDBFunct+   1))
#endif

/* ******************************************************************** */
/*                      VEC1000 Curve Definition                        */
/* ******************************************************************** */
#if    (DB_1000_COMMON_ON == 1)
#define usDBcCurveBackup0               (*(aDBCurve+   0))
#define usDBcCurveBackup1               (*(aDBCurve+   1))
#define aDBcStatistics_T                  (aDBCurve+   0)
#endif

/* ******************************************************************** */
/*                      VEC4000 Parameter Definition                    */
/* ******************************************************************** */
/* ******************************************************************** */
/*                      VEC4000 Parameter Definition                    */
/* ******************************************************************** */
#if    (DB_4000_COMMON_ON == 1)

#define usDBpModConfig                  (*(aDBParam+   0))
#define usDBpModNodeNum                 (*(aDBParam+   1))
#define usDBpModBaudRate                (*(aDBParam+   2))
#define usDBpModAddress                 (*(aDBParam+   3))
#define usDBpLinConfig                  (*(aDBParam+   4))
#define usDBpLinNodeNum                 (*(aDBParam+   5))
#define usDBpLinBaudRate                (*(aDBParam+   6))
#define usDBpLinAddress                 (*(aDBParam+   7))
#define usDBpCanConfig                  (*(aDBParam+   8))
#define usDBpCanNodeNum                 (*(aDBParam+   9))
#define usDBpCanBaudRate                (*(aDBParam+  10))
#define usDBpCanAddress                 (*(aDBParam+  11))
#define usDBpRfConfig                   (*(aDBParam+  12))
#define usDBpRfNodeNum                  (*(aDBParam+  13))
#define usDBpRfBaudRate                 (*(aDBParam+  14))
#define usDBpRfChannelNo                (*(aDBParam+  15))
#define usDBpRfTxAddress0               (*(aDBParam+  16))
#define usDBpRfTxAddress1               (*(aDBParam+  17))
#define usDBpRfRxAddress0               (*(aDBParam+  18))
#define usDBpRfRxAddress1               (*(aDBParam+  19))
#define usDBpCanFilterMode              (*(aDBParam+  20))
#define  aDBpCanFilter                    (aDBParam+  21)
#define usDBpCanFilter0                 (*(aDBParam+  21))
#define usDBpCanFilter1                 (*(aDBParam+  22))
#define usDBpCanFilter2                 (*(aDBParam+  23))
#define usDBpCanFilter3                 (*(aDBParam+  24))
#define usDBpCanFilter4                 (*(aDBParam+  25))
#define usDBpCanFilter5                 (*(aDBParam+  26))
#define usDBpCanFilter6                 (*(aDBParam+  27))
#define usDBpCanFilter7                 (*(aDBParam+  28))
#define usDBpCanFilter8                 (*(aDBParam+  29))
#define usDBpCanFilter9                 (*(aDBParam+  30))
#define	usDBpParamBackup0               (*(aDBParam+  31))
#define	usDBpParamBackup1               (*(aDBParam+  32))
#define	usDBpParamBackup2               (*(aDBParam+  33))
#define	usDBpParamBackup3               (*(aDBParam+  34))
#define	usDBpParamBackup4               (*(aDBParam+  35))
#define	usDBpParamBackup5               (*(aDBParam+  36))
#define	usDBpParamBackup6               (*(aDBParam+  37))
#define	usDBpParamBackup7               (*(aDBParam+  38))
#define	usDBpParamBackup8               (*(aDBParam+  39))
#define	usDBpParamBackup9               (*(aDBParam+  40))
#define	usDBpParamBackup10              (*(aDBParam+  41))
#define	usDBpParamBackup11              (*(aDBParam+  42))
#define	usDBpParamBackup12              (*(aDBParam+  43))
#define	usDBpParamBackup13              (*(aDBParam+  44))
#define	usDBpParamBackup14              (*(aDBParam+  45))
#define	usDBpParamBackup15              (*(aDBParam+  46))
#define	usDBpParamBackup16              (*(aDBParam+  47))
#define	usDBpParamBackup17              (*(aDBParam+  48))
#define	usDBpParamBackup18              (*(aDBParam+  49))
#define	usDBpParamBackup19              (*(aDBParam+  50))
#define	usDBpParamBackup20              (*(aDBParam+  51))
#define	usDBpParamBackup21              (*(aDBParam+  52))
#define	usDBpParamBackup22              (*(aDBParam+  53))
#define	usDBpParamBackup23              (*(aDBParam+  54))
#define	usDBpParamBackup24              (*(aDBParam+  55))
#define	usDBpParamBackup25              (*(aDBParam+  56))
#define	usDBpParamBackup26              (*(aDBParam+  57))
#define	usDBpParamBackup27              (*(aDBParam+  58))
#define	usDBpParamBackup28              (*(aDBParam+  59))

#endif
/* ******************************************************************** */
/*                   VEC4000 Measurement Definition                     */
/* ******************************************************************** */
#if    (DB_4000_COMMON_ON == 1)

#define	usDBmSpeed                      (*(aDBMeasu+   0))
#define	usDBmEngineLoad                 (*(aDBMeasu+   1))
#define	usDBmPedalPosi                  (*(aDBMeasu+   2))
#define usDBmPowerSupply                (*(aDBMeasu+   3))
#define usDBmCoolantTemp                (*(aDBMeasu+   4))
#define usDBmBoostTemp                  (*(aDBMeasu+   5))
#define usDBmOilTemp                    (*(aDBMeasu+   6))
#define	usDBmTempIntern                 (*(aDBMeasu+   7))
#define usDBmBoostPressure              (*(aDBMeasu+   8))
#define usDBmOilPressure                (*(aDBMeasu+   9))
#define uiDBmTimer32           (*(INT32U*)(aDBMeasu+  10))
#define usDBmTimer16U                   (*(aDBMeasu+  10))
#define usDBmTimer16L                   (*(aDBMeasu+  11))
#define usDBmBinaryIn                   (*(aDBMeasu+  12))
#define	usDBmVeSpeed                    (*(aDBMeasu+  13))
#define	usDBmSpeedSetp                  (*(aDBMeasu+  14))
#define usDBmFuelTemp                   (*(aDBMeasu+  15))
#define usDBmFuelRate                   (*(aDBMeasu+  16))
#define usDBmFuelEconomy                (*(aDBMeasu+  17))
#define	usDBmAmbientPressure            (*(aDBMeasu+  18))
#define	usDBmFuelPressure               (*(aDBMeasu+  19))
#define	usDBmRailPressure               (*(aDBMeasu+  20))
#define usDBmRackInput                  (*(aDBMeasu+  21))
#define	usDBmEngineConfig               (*(aDBMeasu+  22))
#define	usDBmActFault                   (*(aDBMeasu+  23))
#define	usDBmStoFault                   (*(aDBMeasu+  24))
#define	usDBmCanState                   (*(aDBMeasu+  25))
#define	usDBmCanSetpoint1               (*(aDBMeasu+  26))
#define	usDBmCanStopStart               (*(aDBMeasu+  27))
#define	usDBmStopLampActive             (*(aDBMeasu+  28))
#define	usDBmWarnLampActive             (*(aDBMeasu+  29))
#define	usDBmSoftVersion                (*(aDBMeasu+  30))
#define	usDBmMeasuBackup0               (*(aDBMeasu+  31))
#define	usDBmMeasuBackup1               (*(aDBMeasu+  32))
#define	usDBmMeasuBackup2               (*(aDBMeasu+  33))
#define	usDBmMeasuBackup3               (*(aDBMeasu+  34))
#define	usDBmMeasuBackup4               (*(aDBMeasu+  35))
#define	usDBmMeasuBackup5               (*(aDBMeasu+  36))
#define	usDBmMeasuBackup6               (*(aDBMeasu+  37))
#define	usDBmMeasuBackup7               (*(aDBMeasu+  38))
#define	usDBmMeasuBackup8               (*(aDBMeasu+  39))
#define	usDBmMeasuBackup9               (*(aDBMeasu+  40))
#define	usDBmMeasuBackup10              (*(aDBMeasu+  41))
#define	usDBmMeasuBackup11              (*(aDBMeasu+  42))
#define	usDBmMeasuBackup12              (*(aDBMeasu+  43))
#define	usDBmMeasuBackup13              (*(aDBMeasu+  44))
#define	usDBmMeasuBackup14              (*(aDBMeasu+  45))
#define	usDBmMeasuBackup15              (*(aDBMeasu+  46))
#define	usDBmMeasuBackup16              (*(aDBMeasu+  47))
#define	usDBmMeasuBackup17              (*(aDBMeasu+  48))
#define	usDBmMeasuBackup18              (*(aDBMeasu+  49))
#define aDBmErrBegin                      (aDBMeasu+  50)
#define	usDBmErrCAN                     (*(aDBMeasu+  50))
#define	usDBmErrLIN                     (*(aDBMeasu+  51))
#define	usDBmErr485Bus                  (*(aDBMeasu+  52))
#define usDBmErrRf905                   (*(aDBMeasu+  53))
#define	usDBmErrLogical                 (*(aDBMeasu+  54))
#define	usDBmErrDataCheck               (*(aDBMeasu+  55))
#define	usDBmErrClearFlash              (*(aDBMeasu+  56))
#define	usDBmErrParamStore              (*(aDBMeasu+  57))
#define usDBmErrBackup0                 (*(aDBMeasu+  58))
#define usDBmErrBackup1                 (*(aDBMeasu+  59))
#define usDBmErrBackup2                 (*(aDBMeasu+  60))
#define usDBmErrBackup3                 (*(aDBMeasu+  61))
#define usDBmErrBackup4                 (*(aDBMeasu+  62))
#define usDBmErrBackup5                 (*(aDBMeasu+  63))
#define usDBmErrBackup6                 (*(aDBMeasu+  64))
#define aDBmHistBegin                     (aDBMeasu+  65)
#define aDBmSErrBegin                     (aDBMeasu+  65)
#define	usDBmSErrCAN                    (*(aDBMeasu+  65))
#define	usDBmSErrLIN                    (*(aDBMeasu+  66))
#define	usDBmSErr485Bus                 (*(aDBMeasu+  67))
#define usDBmSErrRf905                  (*(aDBMeasu+  68))
#define	usDBmSErrLogical                (*(aDBMeasu+  69))
#define	usDBmSErrDataCheck              (*(aDBMeasu+  70))
#define	usDBmSErrClearFlash             (*(aDBMeasu+  71))
#define	usDBmSErrParamStore             (*(aDBMeasu+  72))
#define usDBmSErrBackup0                (*(aDBMeasu+  73))
#define usDBmSErrBackup1                (*(aDBMeasu+  74))
#define usDBmSErrBackup2                (*(aDBMeasu+  75))
#define usDBmSErrBackup3                (*(aDBMeasu+  76))
#define usDBmSErrBackup4                (*(aDBMeasu+  77))
#define usDBmSErrBackup5                (*(aDBMeasu+  78))
#define usDBmSErrBackup6                (*(aDBMeasu+  79))

#endif
/* ******************************************************************** */
/*                     VEC4000 Function Definition                      */
/* ******************************************************************** */
#if    (DB_4000_COMMON_ON == 1)

#define	usDBfFunctBackup0               (*(aDBFunct+   0))
#define	usDBfFunctBackup1               (*(aDBFunct+   1))

#endif
/* ******************************************************************** */
/*                      VEC4000 Curve Definition                        */
/* ******************************************************************** */
#if    (DB_4000_COMMON_ON == 1)

#define usDBcCurveBackup0               (*(aDBCurve+   0))
#define usDBcCurveBackup1               (*(aDBCurve+   1))
#define aDBcStatistics_T                  (aDBCurve+   0)

#endif
/* ******************************************************************** */
/*                      VEC6800 Parameter Definition                    */
/* ******************************************************************** */
/* ******************************************************************** */
/*                      VEC6800 Parameter Definition                    */
/* ******************************************************************** */
#if    (DB_6800_COMMON_ON == 1)
/* ****************** Part 1: Teeth/Speed (0 - 23) ******************** */
#define usDBpSamplePerRound             (*(aDBParam+   0))
#define usDBpTeethCrank1                (*(aDBParam+   1))
#define usDBpTeethCrank2                (*(aDBParam+   2))
#define usDBpTeethCam                   (*(aDBParam+   2))       /* !!! */
#define usDBpSpeedIdle1                 (*(aDBParam+   3))
#define usDBpSpeedIdle2                 (*(aDBParam+   4))
#define usDBpSpeedIdle3                 (*(aDBParam+   5))
#define usDBpSpeedMax1                  (*(aDBParam+   6))
#define usDBpSpeedMax2                  (*(aDBParam+   7))
#define usDBpSpeedMax3                  (*(aDBParam+   8))
#define usDBpSpeedFix1                  (*(aDBParam+   9))
#define usDBpSpeedFix2                  (*(aDBParam+  10))
#define usDBpSpeedSetpPC                (*(aDBParam+  11))
#define usDBpSpeedOver                  (*(aDBParam+  12))
#define usDBpSpeedIdleMin               (*(aDBParam+  13))
#define usDBpSpeedIdleMax               (*(aDBParam+  14))
#define usDBpSpeedIdleIncByTemp         (*(aDBParam+  15))
#define usDBpSpeedIdleIncTempLow        (*(aDBParam+  16))
#define usDBpSpeedIdleIncTempHigh       (*(aDBParam+  17))
#define	usDBpSpeedIdleIncByVolt         (*(aDBParam+  18))
#define	usDBpSpeedIdleIncVoltLow        (*(aDBParam+  19))
#define	usDBpSpeedIdleIncVoltHigh       (*(aDBParam+  20))
#define	usDBpSpeedIdleIncByLoad         (*(aDBParam+  21))
#define	usDBpSpeedIdleIncLoadLow        (*(aDBParam+  22))
#define	usDBpSpeedIdleIncLoadHigh       (*(aDBParam+  23))

/* **************** Part 2: Stability/Droop, (24 - 43) **************** */
#define	usDBpGain                       (*(aDBParam+  24))
#define	usDBpStability                  (*(aDBParam+  25))
#define	usDBpDerivative                 (*(aDBParam+  26))
#define	usDBpStaticCorrFactor           (*(aDBParam+  27))
#define	usDBpStaticCorrRange            (*(aDBParam+  28))
#define	usDBpPIDCorrTempLow             (*(aDBParam+  29))
#define	usDBpPIDCorrTempHigh            (*(aDBParam+  30))
#define	usDBpPIDCorrAtTempLow           (*(aDBParam+  31))
#define	usDBpDroop1                     (*(aDBParam+  32))
#define	usDBpDroop1RefLow               (*(aDBParam+  33))
#define	usDBpDroop1RefHigh              (*(aDBParam+  34))
#define	usDBpDroop1SpeedRef             (*(aDBParam+  35))
#define	usDBpDroop2                     (*(aDBParam+  36))
#define	usDBpDroop2RefLow               (*(aDBParam+  37))
#define	usDBpDroop2RefHigh              (*(aDBParam+  38))
#define	usDBpDroop2SpeedRef             (*(aDBParam+  39))
#define	usDBpDroop3                     (*(aDBParam+  40))
#define	usDBpDroop3RefLow               (*(aDBParam+  41))
#define	usDBpDroop3RefHigh              (*(aDBParam+  42))
#define	usDBpDroop3SpeedRef             (*(aDBParam+  43))
#define	usDBpFuelCorrTempLow            (*(aDBParam+  44))
#define	usDBpFuelCorrTempHigh           (*(aDBParam+  45))
#define	usDBpFuelCorrAtTempHigh         (*(aDBParam+  46))

/* ****************** Part 3: Ramp/Start, (44 - 64) ******************* */
#define	usDBpSpeedRampUp                (*(aDBParam+  47))
#define	usDBpSpeedRampDown              (*(aDBParam+  48))
#define	usDBpSpeedRampUp2               (*(aDBParam+  49))
#define	usDBpSpeedRampDown2             (*(aDBParam+  50))
#define	usDBpSpeedRampUp3               (*(aDBParam+  51))
#define	usDBpSpeedRampDown3             (*(aDBParam+  52))
#define	usDBpSpeedSwitchToRamp2         (*(aDBParam+  53))
#define	usDBpSpeedSwitchToRamp3         (*(aDBParam+  54))
#define	usDBpDigitPotSpeedRamp          (*(aDBParam+  55))
#define	usDBpStartSpeedRampUp           (*(aDBParam+  56))
#define	usDBpStartType                  (*(aDBParam+  57))
#define	usDBpStartLimitDelay            (*(aDBParam+  58))
#define	usDBpStartSpeed1                (*(aDBParam+  59))
#define	usDBpStartSpeed2                (*(aDBParam+  60))
#define	usDBpStartSpeed3                (*(aDBParam+  61))
#define	usDBpStartFuel1                 (*(aDBParam+  62))
#define	usDBpStartFuel2                 (*(aDBParam+  63))
#define	usDBpStartDuration1             (*(aDBParam+  64))
#define	usDBpStartDuration2             (*(aDBParam+  65))
#define	usDBpStartTempWarm              (*(aDBParam+  66))
#define	usDBpStartTempCold              (*(aDBParam+  67))

/* **************** Part 4: Rack Control, (65 - 76) ******************* */
#define	usDBpRackGain                   (*(aDBParam+  68))
#define	usDBpRackStability              (*(aDBParam+  69))
#define	usDBpRackDerivative             (*(aDBParam+  70))
#define	usDBpRackSetpointTest           (*(aDBParam+  71))
#define	usDBpRackControlTest            (*(aDBParam+  72))
#define	usDBpRackCorrSpeedLow           (*(aDBParam+  73))
#define	usDBpRackCorrSpeedHigh          (*(aDBParam+  74))
#define	usDBpRackCorrAtSpeedLow         (*(aDBParam+  75))
#define	usDBpRackCorrAtSpeedHigh        (*(aDBParam+  76))

/* **************** Part 5: Begin Control, (77 - 88) ****************** */
#define	usDBpBeginGain                  (*(aDBParam+  77))
#define	usDBpBeginStability             (*(aDBParam+  70))
#define	usDBpBeginDerivative            (*(aDBParam+  71))
#define	usDBpBeginSetpoint              (*(aDBParam+  80))
#define	usDBpBeginControlTest           (*(aDBParam+  81))
#define	usDBpBeginCorrTempLow           (*(aDBParam+  82))
#define	usDBpBeginCorrTempHigh          (*(aDBParam+  83))
#define	usDBpBeginCorrAtTempLow         (*(aDBParam+  84))
#define	usDBpBeginCorrAmbLow            (*(aDBParam+  85))
#define	usDBpBeginCorrAmbHigh           (*(aDBParam+  86))
#define	usDBpBeginCorrAtAmbLow          (*(aDBParam+  87))
#define	usDBpBeginCorrAmbDelay          (*(aDBParam+  88))

/* ***************** Part 6: EGR Control, (89 - 102) ****************** */
#define	usDBpEgrGain                    (*(aDBParam+  89))
#define	usDBpEgrStability               (*(aDBParam+  90))
#define	usDBpEgrDerivative              (*(aDBParam+  91))
#define	usDBpEgrSetpoint                (*(aDBParam+  92))
#define	usDBpEgrControlTest             (*(aDBParam+  93))
#define	usDBpEgrCorrTempLow             (*(aDBParam+  94))
#define	usDBpEgrCorrTempHigh            (*(aDBParam+  95))
#define	usDBpEgrCorrAtTempLow           (*(aDBParam+  96))
#define	usDBpEgrCorrBoostLow            (*(aDBParam+  97))
#define	usDBpEgrCorrBoostHigh           (*(aDBParam+  98))
#define	usDBpEgrCorrAtBoostLow          (*(aDBParam+  99))
#define	usDBpEgrCorrGradientLow         (*(aDBParam+ 100))
#define	usDBpEgrCorrGradientHigh        (*(aDBParam+ 101))
#define	usDBpEgrCorrAtGradientHigh      (*(aDBParam+ 102))

/* ******************* Part 7: Can Bus, (103 - 106) ******************* */
#define	usDBpCanBaudrate                (*(aDBParam+ 103))
#define	usDBpCanRxIDNumber              (*(aDBParam+ 104))
#define	usDBpCanTxIDNumber              (*(aDBParam+ 105))
#define	usDBpCanTxPeriod                (*(aDBParam+ 106))

/* ****************** Part 8: Monitoring, (107 - 115) ***************** */
#define	usDBpOilPressStartDelay         (*(aDBParam+ 107))
#define	usDBpOilPressWarnDelay          (*(aDBParam+ 108))
#define	usDBpOilPressEcyDelay           (*(aDBParam+ 109))
#define	usDBpCoolantTempLimit           (*(aDBParam+ 110))
#define	usDBpBoostTempLimit             (*(aDBParam+ 111))
#define	usDBpOilTempLimit               (*(aDBParam+ 112))
#define	usDBpSpeedDeltaWarnLimit        (*(aDBParam+ 113))
#define	usDBpRackDeltaWarnLimit         (*(aDBParam+ 114))
#define	usDBpRackWaveWarnLimit          (*(aDBParam+ 115))
#define	usDBpStatisticsTime             (*(aDBParam+ 116))

/* ****************** Part 9: Limitation (117 - 121) ****************** */
#define	usDBpSpeedLimitTempDec          (*(aDBParam+ 117))
#define	usDBpSpeedLimitTempLow          (*(aDBParam+ 118))
#define	usDBpSpeedLimitTempHigh         (*(aDBParam+ 119))
#define	usDBpFuelLimitMaxAbsolut        (*(aDBParam+ 120))
#define	usDBpFuelLimitForced            (*(aDBParam+ 121))

/* ************** Part 10: Switch Assignment (122 - 153) ************** */
#define	usDBpFunctEngineStop            (*(aDBParam+ 122))
#define	usDBpFunctIdleSpeed             (*(aDBParam+ 123))
#define	usDBpFunctSpeedFix1             (*(aDBParam+ 124))
#define	usDBpFunctSpeedFix2             (*(aDBParam+ 125))
#define	usDBpFunctSpeedInc              (*(aDBParam+ 126))
#define	usDBpFunctSpeedDec              (*(aDBParam+ 127))
#define	usDBpFunctDroop2Or1             (*(aDBParam+ 128))
#define	usDBpFunctDroop3Or2             (*(aDBParam+ 129))
#define	usDBpFunctSpeedRange2Or1        (*(aDBParam+ 130))
#define	usDBpFunctSpeedRange3Or2        (*(aDBParam+ 131))
#define	usDBpFunctSpeedLimit2Or1        (*(aDBParam+ 132))
#define	usDBpFunctSpeedLimit3Or2        (*(aDBParam+ 133))
#define	usDBpFunctOilPump               (*(aDBParam+ 134))
#define	usDBpFunctAirHeater             (*(aDBParam+ 135))
#define	usDBpFunctEngineStart           (*(aDBParam+ 136))
#define	usDBpFunctSetpoint2Or1          (*(aDBParam+ 137))
#define	usDBpFunctForcedLimit           (*(aDBParam+ 138))
#define	usDBpFunctSyncEnable            (*(aDBParam+ 139))
#define	usDBpFunctLoadEnable            (*(aDBParam+ 140))
#define	usDBpFunctAutoOrManual          (*(aDBParam+ 141))
#define	usDBpFunctErrorReset            (*(aDBParam+ 142))
#define	usDBpFunctPTO                   (*(aDBParam+ 143))
#define	usDBpFunctRPTO                  (*(aDBParam+ 144))
#define	usDBpFunctPTOCCSet              (*(aDBParam+ 145))
#define	usDBpFunctPTOCCReset            (*(aDBParam+ 146))
#define	usDBpFunctPTOAdd                (*(aDBParam+ 147))
#define	usDBpFunctMainBrake             (*(aDBParam+ 148))
#define	usDBpFunctClutch                (*(aDBParam+ 149))
#define	usDBpFunctDiagnostic            (*(aDBParam+ 150))
#define	usDBpFunctIMOrAllSpeed          (*(aDBParam+ 151))
#define	usDBpFunctCruiseControl         (*(aDBParam+ 152))
#define	usDBpFunctAirConditioner        (*(aDBParam+ 153))

/* ************* Part 11: Sensor Assignment, (154 - 186) ************** */
#define	usDBpAssignInSetp1Ext           (*(aDBParam+ 154))
#define	usDBpAssignInSetp1Sub           (*(aDBParam+ 155))
#define	usDBpAssignInSetp2Ext           (*(aDBParam+ 156))
#define	usDBpAssignInBoostPress         (*(aDBParam+ 157))
#define	usDBpAssignInOilPress           (*(aDBParam+ 158))
#define	usDBpAssignInAmbPress           (*(aDBParam+ 159))
#define	usDBpAssignInCoolantTemp        (*(aDBParam+ 160))
#define	usDBpAssignInBoostTemp          (*(aDBParam+ 161))
#define	usDBpAssignInOilTemp            (*(aDBParam+ 162))
#define	usDBpAssignInFuelTemp           (*(aDBParam+ 163))
#define	usDBpAssignInExhaustTemp        (*(aDBParam+ 164))
#define	usDBpAssignInLoadInput          (*(aDBParam+ 165))
#define	usDBpAssignInSyncInput          (*(aDBParam+ 166))
#define	usDBpAssignInRackCurrent        (*(aDBParam+ 167))
#define	usDBpAssignInRackInput          (*(aDBParam+ 168))
#define	usDBpAssignInEgrInput           (*(aDBParam+ 169))
#define	usDBpAssignInBeginInput         (*(aDBParam+ 170))
#define	aDBpADCChanFilter                 (aDBParam+ 171)
#define	usDBpADCChanFilter00            (*(aDBParam+ 171))
#define	usDBpADCChanFilter01            (*(aDBParam+ 172))
#define	usDBpADCChanFilter02            (*(aDBParam+ 173))
#define	usDBpADCChanFilter03            (*(aDBParam+ 174))
#define	usDBpADCChanFilter04            (*(aDBParam+ 175))
#define	usDBpADCChanFilter05            (*(aDBParam+ 176))
#define	usDBpADCChanFilter06            (*(aDBParam+ 177))
#define	usDBpADCChanFilter07            (*(aDBParam+ 178))
#define	usDBpADCChanFilter08            (*(aDBParam+ 179))
#define	usDBpADCChanFilter09            (*(aDBParam+ 180))
#define	usDBpADCChanFilter10            (*(aDBParam+ 181))
#define	usDBpADCChanFilter11            (*(aDBParam+ 182))
#define	usDBpADCChanFilter12            (*(aDBParam+ 183))
#define	usDBpADCChanFilter13            (*(aDBParam+ 184))
#define	usDBpADCChanFilter14            (*(aDBParam+ 185))
#define	usDBpADCChanFilter15            (*(aDBParam+ 186))

/* ************* Part 12: Sensor Calibration, (187 - 244) ************* */
#define	usDBpSetp1ExtRefLow             (*(aDBParam+ 187))
#define	usDBpSetp1ExtRefHigh            (*(aDBParam+ 188))
#define	usDBpSetp1ExtErrorLow           (*(aDBParam+ 189))
#define	usDBpSetp1ExtErrorHigh          (*(aDBParam+ 190))
#define	usDBpSetp1SubRefLow             (*(aDBParam+ 191))
#define	usDBpSetp1SubRefHigh            (*(aDBParam+ 192))
#define	usDBpSetp1SubErrorLow           (*(aDBParam+ 193))
#define	usDBpSetp1SubErrorHigh          (*(aDBParam+ 194))
#define	usDBpSetp2ExtRefLow             (*(aDBParam+ 195))
#define	usDBpSetp2ExtRefHigh            (*(aDBParam+ 196))
#define	usDBpSetp2ExtErrorLow           (*(aDBParam+ 197))
#define	usDBpSetp2ExtErrorHigh          (*(aDBParam+ 198))
#define	usDBpBoostPressRefLow           (*(aDBParam+ 199))
#define	usDBpBoostPressRefHigh          (*(aDBParam+ 200))
#define	usDBpBoostPressErrorLow         (*(aDBParam+ 201))
#define	usDBpBoostPressErrorHigh        (*(aDBParam+ 202))
#define	usDBpOilPressRefLow             (*(aDBParam+ 203))
#define	usDBpOilPressRefHigh            (*(aDBParam+ 204))
#define	usDBpOilPressErrorLow           (*(aDBParam+ 205))
#define	usDBpOilPressErrorHigh          (*(aDBParam+ 206))
#define	usDBpAmbPressRefLow             (*(aDBParam+ 207))
#define	usDBpAmbPressRefHigh            (*(aDBParam+ 208))
#define	usDBpAmbPressErrorLow           (*(aDBParam+ 209))
#define	usDBpAmbPressErrorHigh          (*(aDBParam+ 210))
#define	usDBpCoolantTempErrorLow        (*(aDBParam+ 211))
#define	usDBpCoolantTempErrorHigh       (*(aDBParam+ 212))
#define	usDBpBoostTempErrorLow          (*(aDBParam+ 213))
#define	usDBpBoostTempErrorHigh         (*(aDBParam+ 214))
#define	usDBpOilTempErrorLow            (*(aDBParam+ 215))
#define	usDBpOilTempErrorHigh           (*(aDBParam+ 216))
#define	usDBpFuelTempErrorLow           (*(aDBParam+ 217))
#define	usDBpFuelTempErrorHigh          (*(aDBParam+ 218))
#define	usDBpExhaustTempErrorLow        (*(aDBParam+ 219))
#define	usDBpExhaustTempErrorHigh       (*(aDBParam+ 220))
#define	usDBpLoadInputRefLow            (*(aDBParam+ 221))
#define	usDBpLoadInputRefHigh           (*(aDBParam+ 222))
#define	usDBpLoadInputErrorLow          (*(aDBParam+ 223))
#define	usDBpLoadInputErrorHigh         (*(aDBParam+ 224))
#define	usDBpSyncInputRefLow            (*(aDBParam+ 225))
#define	usDBpSyncInputRefHigh           (*(aDBParam+ 226))
#define	usDBpSyncInputErrorLow          (*(aDBParam+ 227))
#define	usDBpSyncInputErrorHigh         (*(aDBParam+ 228))
#define	usDBpRackCurrentRefLow          (*(aDBParam+ 229))
#define	usDBpRackCurrentRefHigh         (*(aDBParam+ 230))
#define	usDBpRackCurrentErrorLow        (*(aDBParam+ 231))
#define	usDBpRackCurrentErrorHigh       (*(aDBParam+ 232))
#define	usDBpRackInputRefLow            (*(aDBParam+ 233))
#define	usDBpRackInputRefHigh           (*(aDBParam+ 234))
#define	usDBpRackInputErrorLow          (*(aDBParam+ 235))
#define	usDBpRackInputErrorHigh         (*(aDBParam+ 236))
#define	usDBpEgrInputRefLow             (*(aDBParam+ 237))
#define	usDBpEgrInputRefHigh            (*(aDBParam+ 238))
#define	usDBpEgrInputErrorLow           (*(aDBParam+ 239))
#define	usDBpEgrInputErrorHigh          (*(aDBParam+ 240))
#define	usDBpBeginInputRefLow           (*(aDBParam+ 241))
#define	usDBpBeginInputRefHigh          (*(aDBParam+ 242))
#define	usDBpBeginInputErrorLow         (*(aDBParam+ 243))
#define	usDBpBeginInputErrorHigh        (*(aDBParam+ 244))

/* ************* Part 13: Substitute Values, (245 - 261) ************** */
#define	usDBpSubstSetp1Ext              (*(aDBParam+ 245))
#define	usDBpSubstSetp1Sub              (*(aDBParam+ 246))
#define	usDBpSubstSetp2Ext              (*(aDBParam+ 247))
#define	usDBpSubstBoostPress            (*(aDBParam+ 248))
#define	usDBpSubstOilPress              (*(aDBParam+ 249))
#define	usDBpSubstAmbientPress          (*(aDBParam+ 250))
#define	usDBpSubstCoolantTemp           (*(aDBParam+ 251))
#define	usDBpSubstBoostTemp             (*(aDBParam+ 252))
#define	usDBpSubstOilTemp               (*(aDBParam+ 253))
#define	usDBpSubstFuelTemp              (*(aDBParam+ 254))
#define	usDBpSubstExhaustTemp           (*(aDBParam+ 255))
#define	usDBpSubstLoadInput             (*(aDBParam+ 256))
#define	usDBpSubstSyncInput             (*(aDBParam+ 257))
#define	usDBpSubstRackCurrent           (*(aDBParam+ 258))
#define	usDBpSubstRackInput             (*(aDBParam+ 259))
#define	usDBpSubstEgrInput              (*(aDBParam+ 260))
#define	usDBpSubstBeginInput            (*(aDBParam+ 261))

/* ************* Part 14: Output Calibration, (262 - 293) ************* */
#define	usDBpDigitalOut1Assign          (*(aDBParam+ 262))
#define	usDBpDigitalOut2Assign          (*(aDBParam+ 263))
#define	usDBpDigitalOut3Assign          (*(aDBParam+ 264))
#define	usDBpDigitalOut4Assign          (*(aDBParam+ 265))
#define	usDBpDigitalOut5Assign          (*(aDBParam+ 266))
#define	usDBpDigitalOut6Assign          (*(aDBParam+ 267))
#define	usDBpDigitalOut7Assign          (*(aDBParam+ 268))
#define	usDBpDigitalOut8Assign          (*(aDBParam+ 269))
#define	usDBpPWMOut1Assign              (*(aDBParam+ 270))
#define	usDBpPWMOut1RefLow              (*(aDBParam+ 271))
#define	usDBpPWMOut1RefHigh             (*(aDBParam+ 272))
#define	usDBpPWMOut1FrqOrDutyMin        (*(aDBParam+ 273))
#define	usDBpPWMOut1FrqOrDutyMax        (*(aDBParam+ 274))
#define	usDBpPWMOut1Period              (*(aDBParam+ 275))
#define	usDBpPWMOut2Assign              (*(aDBParam+ 276))
#define	usDBpPWMOut2RefLow              (*(aDBParam+ 277))
#define	usDBpPWMOut2RefHigh             (*(aDBParam+ 278))
#define	usDBpPWMOut2FrqOrDutyMin        (*(aDBParam+ 279))
#define	usDBpPWMOut2FrqOrDutyMax        (*(aDBParam+ 280))
#define	usDBpPWMOut2Period              (*(aDBParam+ 281))
#define	usDBpPWMOut3Assign              (*(aDBParam+ 282))
#define	usDBpPWMOut3RefLow              (*(aDBParam+ 283))
#define	usDBpPWMOut3RefHigh             (*(aDBParam+ 284))
#define	usDBpPWMOut3FrqOrDutyMin        (*(aDBParam+ 285))
#define	usDBpPWMOut3FrqOrDutyMax        (*(aDBParam+ 286))
#define	usDBpPWMOut3Period              (*(aDBParam+ 287))
#define	usDBpPWMOut4Assign              (*(aDBParam+ 288))
#define	usDBpPWMOut4RefLow              (*(aDBParam+ 289))
#define	usDBpPWMOut4RefHigh             (*(aDBParam+ 290))
#define	usDBpPWMOut4FrqOrDutyMin        (*(aDBParam+ 291))
#define	usDBpPWMOut4FrqOrDutyMax        (*(aDBParam+ 292))
#define	usDBpPWMOut4Period              (*(aDBParam+ 293))

/* ****************** Part 15: Status, (294 - 295) ******************** */
#define	usDBpLevel                      (*(aDBParam+ 294))
#define	usDBpOperationMode              (*(aDBParam+ 295))

/* **************** Part 16: Generator, (296 - 299) ******************* */
#define	usDBpSynchronFactor             (*(aDBParam+ 296))
#define	usDBpSynchronReference          (*(aDBParam+ 297))
#define	usDBpLoadControlFactor          (*(aDBParam+ 298))
#define	usDBpLoadControlReference       (*(aDBParam+ 299))

/* ***************** Part 17: Vehicle, (300 - 303) ******************** */
#define	usDBpVSSensorRatio              (*(aDBParam+ 300))
#define	usDBpVSpeedMaxAbsolut           (*(aDBParam+ 301))
#define	usDBpVSpeedMinCruise            (*(aDBParam+ 302))
#define	usDBpVSpeedMaxCruise            (*(aDBParam+ 303))
#define	usDBpVSpeedMaxPTO               (*(aDBParam+ 304))
#define	usDBpVSpeedMaxFaultHome         (*(aDBParam+ 305))
#define	usDBpEBrakeDeltaMax             (*(aDBParam+ 306))
#define	usDBpEBrakeDeltaMin             (*(aDBParam+ 307))
#define	usDBpEBrakeDelay                (*(aDBParam+ 308))
#define	usDBpEBrakeVSpeedMin            (*(aDBParam+ 309))
#define	usDBpEBrakeESpeedMin            (*(aDBParam+ 310))
#define	usDBpEBrakeBPressMax            (*(aDBParam+ 311))
#define	usDBpPTOSpeedSet                (*(aDBParam+ 312))
#define	usDBpPTOSpeedReset              (*(aDBParam+ 313))
#define	usDBpPTOSpeedAdd                (*(aDBParam+ 314))
#define	usDBpRPTOSpeedNum               (*(aDBParam+ 315))
#define	aDBpRPTOSpeedSetp                 (aDBParam+ 316)
#define	usDBpRPTOSpeedSetp1             (*(aDBParam+ 316))
#define	usDBpRPTOSpeedSetp2             (*(aDBParam+ 317))
#define	usDBpRPTOSpeedSetp3             (*(aDBParam+ 318))
#define	usDBpRPTOSpeedSetp4             (*(aDBParam+ 319))
#define	usDBpRPTOSpeedSetp5             (*(aDBParam+ 320))
#define	usDBpRPTOSpeedSetp6             (*(aDBParam+ 321))
#define	usDBpSpeedMinCruise             (*(aDBParam+ 322))
#define	usDBpSpeedMaxVSSZero            (*(aDBParam+ 323))
#define	usDBpSpeedMaxFaultHome          (*(aDBParam+ 324))
#define	usDBpSpeedDecVSOverLow          (*(aDBParam+ 325))
#define	usDBpSpeedDecVSOverHigh         (*(aDBParam+ 326))
#define	usDBpSpeedDecByVSOver           (*(aDBParam+ 327))
#define	usDBpSpeedIdleIncByAC           (*(aDBParam+ 328))
#define	usDBpIMModeRampUp               (*(aDBParam+ 329))
#define	usDBpIMModeRampDown             (*(aDBParam+ 330))
#define	usDBpFan1RefAssign              (*(aDBParam+ 331))
#define	usDBpFan1ActiveTemp             (*(aDBParam+ 332))
#define	usDBpFan1ActiveDelay            (*(aDBParam+ 333))
#define	usDBpFan2RefAssign              (*(aDBParam+ 334))
#define	usDBpFan2ActiveTemp             (*(aDBParam+ 335))
#define	usDBpFan2ActiveDelay            (*(aDBParam+ 336))
#define	usDBpAirHeaterTempCold          (*(aDBParam+ 337))
#define	usDBpAirHeaterTempWarm          (*(aDBParam+ 338))
#define	usDBpAirHeaterTimeAtCold        (*(aDBParam+ 339))
#define	usDBpAirHeaterTimeAtWarm        (*(aDBParam+ 340))
#define	usDBpAirHeaterCorrPressLow      (*(aDBParam+ 341))
#define	usDBpAirHeaterCorrPressHigh     (*(aDBParam+ 342))
#define	usDBpAirHeaterCorrAtPressLow    (*(aDBParam+ 343))
#define	usDBpAirHeaterCorrAtPressHigh   (*(aDBParam+ 344))
#define	usDBpAirHeaterCorrVoltLow       (*(aDBParam+ 345))
#define	usDBpAirHeaterCorrVoltHigh      (*(aDBParam+ 346))
#define	usDBpAirHeaterCorrAtVoltLow     (*(aDBParam+ 347))
#define	usDBpAirHeaterCorrAtVoltHigh    (*(aDBParam+ 348))
#define	usDBpOilPumpOnTimeMax           (*(aDBParam+ 349))
#define	usDBpOilPressMinAtStart         (*(aDBParam+ 350))
#define	usDBpStarterOnTime              (*(aDBParam+ 351))
#define	usDBpStarterOffTime             (*(aDBParam+ 352))

/* ****************** Part 18: Others, (304 - 359) ******************** */
#define	usDBpParamBackup0               (*(aDBParam+ 353))
#define	usDBpParamBackup1               (*(aDBParam+ 354))
#define	usDBpParamBackup2               (*(aDBParam+ 355))
#define	usDBpParamBackup3               (*(aDBParam+ 356))
#define	usDBpParamBackup4               (*(aDBParam+ 357))
#define	usDBpParamBackup5               (*(aDBParam+ 358))
#define	usDBpParamBackup6               (*(aDBParam+ 359))
#define	usDBpParamBackup7               (*(aDBParam+ 360))
#define	usDBpParamBackup8               (*(aDBParam+ 361))
#define	usDBpParamBackup9               (*(aDBParam+ 362))
#define	usDBpParamBackup10              (*(aDBParam+ 363))
#define	usDBpParamBackup11              (*(aDBParam+ 364))
#define	usDBpParamBackup12              (*(aDBParam+ 365))
#define	usDBpParamBackup13              (*(aDBParam+ 366))
#define	usDBpParamBackup14              (*(aDBParam+ 367))
#define	usDBpParamBackup15              (*(aDBParam+ 368))
#define	usDBpParamBackup16              (*(aDBParam+ 369))
#define	usDBpParamBackup17              (*(aDBParam+ 370))
#define	usDBpParamBackup18              (*(aDBParam+ 371))
#define	usDBpParamBackup19              (*(aDBParam+ 372))
#define	usDBpParamBackup20              (*(aDBParam+ 373))
#define	usDBpParamBackup21              (*(aDBParam+ 374))
#define	usDBpParamBackup22              (*(aDBParam+ 375))
#define	usDBpParamBackup23              (*(aDBParam+ 376))
#define	usDBpParamBackup24              (*(aDBParam+ 377))
#define	usDBpParamBackup25              (*(aDBParam+ 378))
#define	usDBpParamBackup26              (*(aDBParam+ 379))
#define	usDBpParamBackup27              (*(aDBParam+ 380))
#define	usDBpParamBackup28              (*(aDBParam+ 381))
#define	usDBpParamBackup29              (*(aDBParam+ 382))
#define	usDBpParamBackup30              (*(aDBParam+ 383))
#define	usDBpParamBackup31              (*(aDBParam+ 384))
#define	usDBpParamBackup32              (*(aDBParam+ 385))
#define	usDBpParamBackup33              (*(aDBParam+ 386))
#define	usDBpParamBackup34              (*(aDBParam+ 387))
#define	usDBpParamBackup35              (*(aDBParam+ 388))
#define	usDBpParamBackup36              (*(aDBParam+ 389))
#define	usDBpParamBackup37              (*(aDBParam+ 390))
#define	usDBpParamBackup38              (*(aDBParam+ 391))
#define	usDBpParamBackup39              (*(aDBParam+ 392))
#define	usDBpParamBackup40              (*(aDBParam+ 393))
#define	usDBpParamBackup41              (*(aDBParam+ 394))
#define	usDBpParamBackup42              (*(aDBParam+ 395))
#define	usDBpParamBackup43              (*(aDBParam+ 396))
#define	usDBpParamBackup44              (*(aDBParam+ 397))
#define	usDBpParamBackup45              (*(aDBParam+ 398))
#define	usDBpParamBackup46              (*(aDBParam+ 399))

#endif

/* ******************************************************************** */
/*                   VEC6800 Measurement Definition                     */
/* ******************************************************************** */
#if    (DB_6800_COMMON_ON == 1)
/* ****************** Part 1: Speed Pickup (0 - 25) ******************* */
#define	usDBmSpeed                      (*(aDBMeasu+   0))
#define	usDBmSpeedCrank1                (*(aDBMeasu+   1))
#define	usDBmSpeedCrank2                (*(aDBMeasu+   2))
#define	usDBmSpeedCam                   (*(aDBMeasu+   2))       /* !!! */
#define usDBmPickupActive               (*(aDBMeasu+   3))
#define	usDBmSpeedGradient              (*(aDBMeasu+   4))
#define	usDBmSpeedDelta                 (*(aDBMeasu+   5))
#define	usDBmSpeedSetp                  (*(aDBMeasu+   6))
#define	usDBmSpeedSetpRamp              (*(aDBMeasu+   7))
#define	usDBmSpeedSetpSelect            (*(aDBMeasu+   8))
#define usDBmSpeedIdleActive            (*(aDBMeasu+   9))
#define usDBmSpeedMaxActive             (*(aDBMeasu+  10))
#define usDBmIdleSetpOffset             (*(aDBMeasu+  11))
#define	usDBmDroopOffset                (*(aDBMeasu+  12))
#define	usDBmDigitPotOffset             (*(aDBMeasu+  13))
#define	usDBmGeneSetpOffset             (*(aDBMeasu+  14))
#define	usDBmSpeedDeltaAve              (*(aDBMeasu+  15))
#define	aDBmInstSpeed                     (aDBMeasu+  16)
#define	usDBmInstSpeed1                 (*(aDBMeasu+  16))
#define	usDBmInstSpeed2                 (*(aDBMeasu+  17))
#define	usDBmInstSpeed3                 (*(aDBMeasu+  18))
#define	usDBmInstSpeed4                 (*(aDBMeasu+  19))
#define	usDBmInstSpeed5                 (*(aDBMeasu+  20))
#define	usDBmInstSpeed6                 (*(aDBMeasu+  21))
#define	usDBmInstSpeed7                 (*(aDBMeasu+  22))
#define	usDBmInstSpeed8                 (*(aDBMeasu+  23))
#define	usDBmInstSpeed9                 (*(aDBMeasu+  24))
#define	usDBmInstSpeed10                (*(aDBMeasu+  25))

/* **************** Part 2: Stability/Droop (26 - 32) ***************** */
#define	usDBmPIDGainCorr                (*(aDBMeasu+  26))
#define	usDBmPIDStabCorr                (*(aDBMeasu+  27))
#define	usDBmPIDDeriCorr                (*(aDBMeasu+  28))
#define	usDBmFuelGovernor               (*(aDBMeasu+  29))
#define	usDBmFuelInjection              (*(aDBMeasu+  30))
#define	usDBmFuelAverage                (*(aDBMeasu+  31))
#define	usDBmFuelTempCorrFactor         (*(aDBMeasu+  32))

/* **************** Part 3: Rack Control (33 - 36) ****************** */
#define	usDBmRackSetpoint               (*(aDBMeasu+  33))
#define	usDBmRackControl                (*(aDBMeasu+  34))
#define	usDBmRackInDeltaAve             (*(aDBMeasu+  35))
#define	usDBmRackInWaveAve              (*(aDBMeasu+  36))

/* ***************** Part 4: Begin Control (37 - 38) ****************** */
#define	usDBmBeginSetpoint              (*(aDBMeasu+  37))
#define	usDBmBeginControl               (*(aDBMeasu+  38))

/* ****************** Part 5: EGR Control (39 - 40) ******************* */
#define	usDBmEgrSetpoint                (*(aDBMeasu+  39))
#define	usDBmEgrControl                 (*(aDBMeasu+  40))

/* ******************** Part 6: Can Bus (41 - 45) ********************* */
#define usDBmCanState                   (*(aDBMeasu+  41))
#define usDBmCanSetpoint1               (*(aDBMeasu+  42))
#define usDBmCanSetpoint2               (*(aDBMeasu+  43))
#define usDBmCanSetpoint3               (*(aDBMeasu+  44))
#define usDBmCanBinaryIn                (*(aDBMeasu+  45))

/* ****************** Part 7: Limitations (46 - 65) ******************* */
#define	usDBmFuelLimitMin               (*(aDBMeasu+  46))
#define	usDBmFuelLimitMax               (*(aDBMeasu+  47))
#define	usDBmFuelLimitStart             (*(aDBMeasu+  48))
#define	usDBmFuelLimitSpeed             (*(aDBMeasu+  49))
#define	usDBmFuelLimitBoost             (*(aDBMeasu+  50))
#define	usDBmFuelLimitAmbient           (*(aDBMeasu+  51))
#define	usDBmFuelLimitForced            (*(aDBMeasu+  52))
#define	usDBmFuelLimitMinActive         (*(aDBMeasu+  53))
#define	usDBmFuelLimitMaxActive         (*(aDBMeasu+  54))
#define	usDBmStartLimitActive           (*(aDBMeasu+  55))
#define	usDBmSpeedLimitActive           (*(aDBMeasu+  56))
#define	usDBmBoostLimitActive           (*(aDBMeasu+  57))
#define	usDBmAmbientLimitActive         (*(aDBMeasu+  58))
#define	usDBmForcedLimitActive          (*(aDBMeasu+  59))

/* *************** Part 8: Digital In/Outputs (60 - 99) *************** */
#define	usDBmSwitchEngineStop           (*(aDBMeasu+  60))
#define	usDBmSwitchIdleSpeed            (*(aDBMeasu+  61))
#define	usDBmSwitchSpeedFix1            (*(aDBMeasu+  62))
#define	usDBmSwitchSpeedFix2            (*(aDBMeasu+  63))
#define	usDBmSwitchSpeedInc             (*(aDBMeasu+  64))
#define	usDBmSwitchSpeedDec             (*(aDBMeasu+  65))
#define	usDBmSwitchDroop2Or1            (*(aDBMeasu+  66))
#define	usDBmSwitchDroop3Or2            (*(aDBMeasu+  67))
#define	usDBmSwitchSpeedRange2Or1       (*(aDBMeasu+  68))
#define	usDBmSwitchSpeedRange3Or2       (*(aDBMeasu+  69))
#define	usDBmSwitchSpeedLimit2Or1       (*(aDBMeasu+  70))
#define	usDBmSwitchSpeedLimit3Or2       (*(aDBMeasu+  71))
#define	usDBmSwitchOilPump              (*(aDBMeasu+  72))
#define	usDBmSwitchAirHeater            (*(aDBMeasu+  73))
#define	usDBmSwitchEngineStart          (*(aDBMeasu+  74))
#define	usDBmSwitchSetpoint2Or1         (*(aDBMeasu+  75))
#define	usDBmSwitchForcedLimit          (*(aDBMeasu+  76))
#define	usDBmSwitchSyncEnable           (*(aDBMeasu+  77))
#define	usDBmSwitchLoadEnable           (*(aDBMeasu+  78))
#define	usDBmSwitchAutoOrManual         (*(aDBMeasu+  79))
#define	usDBmSwitchErrorReset           (*(aDBMeasu+  80))
#define	usDBmSwitchPTO                  (*(aDBMeasu+  81))
#define	usDBmSwitchRPTO                 (*(aDBMeasu+  82))
#define	usDBmSwitchPTOCCSet             (*(aDBMeasu+  83))
#define	usDBmSwitchPTOCCReset           (*(aDBMeasu+  84))
#define	usDBmSwitchPTOAdd               (*(aDBMeasu+  85))
#define	usDBmSwitchMainBrake            (*(aDBMeasu+  86))
#define	usDBmSwitchClutch               (*(aDBMeasu+  87))
#define	usDBmSwitchDiagnostic           (*(aDBMeasu+  88))
#define	usDBmSwitchIMOrAllSpeed         (*(aDBMeasu+  89))
#define	usDBmSwitchCruiseControl        (*(aDBMeasu+  90))
#define	usDBmSwitchAirConditioner       (*(aDBMeasu+  91))
#define	usDBmDigitalOut1                (*(aDBMeasu+  92))
#define	usDBmDigitalOut2                (*(aDBMeasu+  93))
#define	usDBmDigitalOut3                (*(aDBMeasu+  94))
#define	usDBmDigitalOut4                (*(aDBMeasu+  95))
#define	usDBmDigitalOut5                (*(aDBMeasu+  96))
#define	usDBmDigitalOut6                (*(aDBMeasu+  97))
#define	usDBmDigitalOut7                (*(aDBMeasu+  98))
#define	usDBmDigitalOut8                (*(aDBMeasu+  99))

/* **************** Part 9: Sensors Inputs (100 - 116) **************** */
#define	usDBmSetp1Extern                (*(aDBMeasu+ 100))
#define	usDBmSetp1ExtSub                (*(aDBMeasu+ 101))
#define	usDBmSetp2Extern                (*(aDBMeasu+ 102))
#define usDBmBoostPressure              (*(aDBMeasu+ 103))
#define usDBmOilPressure                (*(aDBMeasu+ 104))
#define usDBmAmbientPressure            (*(aDBMeasu+ 105))
#define usDBmCoolantTemp                (*(aDBMeasu+ 106))
#define usDBmBoostTemp                  (*(aDBMeasu+ 107))
#define usDBmOilTemp                    (*(aDBMeasu+ 108))
#define usDBmFuelTemp                   (*(aDBMeasu+ 109))
#define usDBmExhaustTemp                (*(aDBMeasu+ 110))
#define	usDBmLoadInput                  (*(aDBMeasu+ 111))
#define usDBmSyncInput                  (*(aDBMeasu+ 112))
#define usDBmRackCurrent                (*(aDBMeasu+ 113))
#define usDBmRackInput                  (*(aDBMeasu+ 114))
#define usDBmEgrInput                   (*(aDBMeasu+ 115))
#define usDBmBeginInput                 (*(aDBMeasu+ 116))

/* *************** Part 10: Inputs Status (117 - 135) ***************** */
#define aDBmAnalogIn                      (aDBMeasu+ 117)
#define usDBmAnalogIn00                 (*(aDBMeasu+ 117))
#define usDBmAnalogIn01                 (*(aDBMeasu+ 118))
#define usDBmAnalogIn02                 (*(aDBMeasu+ 119))
#define usDBmAnalogIn03                 (*(aDBMeasu+ 120))
#define usDBmAnalogIn04                 (*(aDBMeasu+ 121))
#define usDBmAnalogIn05                 (*(aDBMeasu+ 122))
#define usDBmAnalogIn06                 (*(aDBMeasu+ 123))
#define usDBmAnalogIn07                 (*(aDBMeasu+ 124))
#define usDBmAnalogIn08                 (*(aDBMeasu+ 125))
#define usDBmAnalogIn09                 (*(aDBMeasu+ 126))
#define usDBmAnalogIn10                 (*(aDBMeasu+ 127))
#define usDBmAnalogIn11                 (*(aDBMeasu+ 128))
#define usDBmAnalogIn12                 (*(aDBMeasu+ 129))
#define usDBmAnalogIn13                 (*(aDBMeasu+ 130))
#define usDBmAnalogIn14                 (*(aDBMeasu+ 131))
#define usDBmAnalogIn15                 (*(aDBMeasu+ 132))
#define usDBmPowerSupply                (*(aDBMeasu+ 133))
#define usDBmTempIntern                 (*(aDBMeasu+ 134))
#define	usDBmBoostPressAt25C            (*(aDBMeasu+ 135))
#define usDBmBinaryIn                   (*(aDBMeasu+ 136))

/* **************** Part 11: Engine Status (137 - 149) **************** */
#define usDBmPhase                      (*(aDBMeasu+ 137))
#define usDBmEngineTimer                (*(aDBMeasu+ 138))
#define usDBmCommonAlarm                (*(aDBMeasu+ 139))
#define usDBmEngineStopEcy              (*(aDBMeasu+ 140))
#define usDBmEngineStopping             (*(aDBMeasu+ 141))
#define usDBmEngineStopped              (*(aDBMeasu+ 142))
#define usDBmEngineStarting             (*(aDBMeasu+ 143))
#define usDBmEngineRunning              (*(aDBMeasu+ 144))
#define usDBmEngineReleased             (*(aDBMeasu+ 145))
#define usDBmCalculationTime            (*(aDBMeasu+ 146))
#define usDBmHardwareVersion            (*(aDBMeasu+ 147))
#define usDBmSoftwareVersion            (*(aDBMeasu+ 148))
#define usDBmCPUTimeUsage               (*(aDBMeasu+ 149))

/* ******************* Part 12: Vehicle (150 - 167) ******************* */
#define	usDBmVeSpeed                    (*(aDBMeasu+ 150))
#define	usDBmEBrakeActive               (*(aDBMeasu+ 151))
#define usDBmDiagnosActive              (*(aDBMeasu+ 152))
#define usDBmFaultHomeActive            (*(aDBMeasu+ 153))
#define	usDBmAirHeaterActive            (*(aDBMeasu+ 154))
#define usDBmIMGovernorActive           (*(aDBMeasu+ 155))
#define	usDBmPTOSetpSelect              (*(aDBMeasu+ 156))
#define usDBmCCSetpSelect               (*(aDBMeasu+ 157))
#define usDBmPTOSetpOffset              (*(aDBMeasu+ 158))
#define usDBmCCSetpOffset               (*(aDBMeasu+ 159))
#define	usDBmFan1Active                 (*(aDBMeasu+ 160))
#define	usDBmFan2Active                 (*(aDBMeasu+ 161))
#define	usDBmAirHeaterDuration          (*(aDBMeasu+ 162))
#define	usDBmFaultCodeBlink             (*(aDBMeasu+ 163))
#define	usDBmOilPumpActive              (*(aDBMeasu+ 164))
#define	usDBmStarterActive              (*(aDBMeasu+ 165))
#define	usDBmWarnLampActive             (*(aDBMeasu+ 166))
#define	usDBmStopLampActive             (*(aDBMeasu+ 167))

/* ******************** Part 13: Ohters, (166 - 203) ****************** */
#define	usDBmMeasuBackup0               (*(aDBMeasu+ 168))
#define	usDBmMeasuBackup1               (*(aDBMeasu+ 169))
#define	usDBmMeasuBackup2               (*(aDBMeasu+ 170))
#define	usDBmMeasuBackup3               (*(aDBMeasu+ 171))
#define	usDBmMeasuBackup4               (*(aDBMeasu+ 172))
#define	usDBmMeasuBackup5               (*(aDBMeasu+ 173))
#define	usDBmMeasuBackup6               (*(aDBMeasu+ 174))
#define	usDBmMeasuBackup7               (*(aDBMeasu+ 175))
#define	usDBmMeasuBackup8               (*(aDBMeasu+ 176))
#define	usDBmMeasuBackup9               (*(aDBMeasu+ 177))
#define	usDBmMeasuBackup10              (*(aDBMeasu+ 178))
#define	usDBmMeasuBackup11              (*(aDBMeasu+ 179))
#define	usDBmMeasuBackup12              (*(aDBMeasu+ 180))
#define	usDBmMeasuBackup13              (*(aDBMeasu+ 181))
#define	usDBmMeasuBackup14              (*(aDBMeasu+ 182))
#define	usDBmMeasuBackup15              (*(aDBMeasu+ 183))
#define	usDBmMeasuBackup16              (*(aDBMeasu+ 184))
#define	usDBmMeasuBackup17              (*(aDBMeasu+ 185))
#define	usDBmMeasuBackup18              (*(aDBMeasu+ 186))
#define	usDBmMeasuBackup19              (*(aDBMeasu+ 187))
#define	usDBmMeasuBackup20              (*(aDBMeasu+ 188))
#define	usDBmMeasuBackup21              (*(aDBMeasu+ 189))
#define	usDBmMeasuBackup22              (*(aDBMeasu+ 190))
#define	usDBmMeasuBackup23              (*(aDBMeasu+ 191))
#define	usDBmMeasuBackup24              (*(aDBMeasu+ 192))
#define	usDBmMeasuBackup25              (*(aDBMeasu+ 193))
#define	usDBmMeasuBackup26              (*(aDBMeasu+ 194))
#define	usDBmMeasuBackup27              (*(aDBMeasu+ 195))
#define	usDBmMeasuBackup28              (*(aDBMeasu+ 196))
#define	usDBmMeasuBackup29              (*(aDBMeasu+ 197))
#define	usDBmMeasuBackup30              (*(aDBMeasu+ 198))
#define	usDBmMeasuBackup31              (*(aDBMeasu+ 199))
#define	usDBmMeasuBackup32              (*(aDBMeasu+ 200))
#define	usDBmMeasuBackup33              (*(aDBMeasu+ 201))
#define	usDBmMeasuBackup34              (*(aDBMeasu+ 202))
#define	usDBmMeasuDataSum               (*(aDBMeasu+ 203))

/* *************** Part 14: Actual Errors, (204 - 259) **************** */
#define aDBmErrBegin                      (aDBMeasu+ 204)
#define usDBmErrCrankSensor1            (*(aDBMeasu+ 204))
#define usDBmErrCrankSensor2            (*(aDBMeasu+ 205))
#define usDBmErrCamSensor               (*(aDBMeasu+ 205))       /* !!! */
#define usDBmErrVSSensor                (*(aDBMeasu+ 206))
#define usDBmErrSetp1Extern             (*(aDBMeasu+ 207))
#define usDBmErrSetp1ExtSub             (*(aDBMeasu+ 208))
#define usDBmErrSetp2Extern             (*(aDBMeasu+ 209))
#define usDBmErrBoostPressure           (*(aDBMeasu+ 210))
#define usDBmErrOilPressure             (*(aDBMeasu+ 211))
#define usDBmErrAmbientPressure         (*(aDBMeasu+ 212))
#define usDBmErrCoolantTemp             (*(aDBMeasu+ 213))
#define usDBmErrBoostTemp               (*(aDBMeasu+ 214))
#define usDBmErrOilTemp                 (*(aDBMeasu+ 215))
#define usDBmErrFuelTemp                (*(aDBMeasu+ 216))
#define usDBmErrExhaustTemp             (*(aDBMeasu+ 217))
#define usDBmErrLoadInput               (*(aDBMeasu+ 218))
#define usDBmErrSyncInput               (*(aDBMeasu+ 219))
#define usDBmErrRackInput               (*(aDBMeasu+ 220))
#define usDBmErrRackCurrent             (*(aDBMeasu+ 221))
#define usDBmErrEgrInput                (*(aDBMeasu+ 222))
#define usDBmErrBeginInput              (*(aDBMeasu+ 223))
#define usDBmErrRackActuator            (*(aDBMeasu+ 224))
#define usDBmErrEgrActuator             (*(aDBMeasu+ 225))
#define usDBmErrBeginActuator           (*(aDBMeasu+ 226))
#define usDBmErrOilPressWarn            (*(aDBMeasu+ 227))
#define usDBmErrOilPressEcy             (*(aDBMeasu+ 228))
#define usDBmErrCoolantTempWarn         (*(aDBMeasu+ 229))
#define usDBmErrBoostTempWarn           (*(aDBMeasu+ 230))
#define usDBmErrOilTempWarn             (*(aDBMeasu+ 231))
#define usDBmErrTempIntern              (*(aDBMeasu+ 232))
#define usDBmErrVoltage                 (*(aDBMeasu+ 233))
#define usDBmErrOverSpeed               (*(aDBMeasu+ 234))
#define usDBmErrCAN                     (*(aDBMeasu+ 235))
#define usDBmErr5VOut                   (*(aDBMeasu+ 236))
#define usDBmErrADC                     (*(aDBMeasu+ 237))
#define usDBmErrStack                   (*(aDBMeasu+ 238))
#define usDBmErrLogical                 (*(aDBMeasu+ 239))
#define usDBmErrCalcTime                (*(aDBMeasu+ 240))
#define usDBmErrDataCheck               (*(aDBMeasu+ 241))
#define usDBmErrClearFlash              (*(aDBMeasu+ 242))
#define usDBmErrParamStore              (*(aDBMeasu+ 243))
#define usDBmErrPogramTest              (*(aDBMeasu+ 244))
#define usDBmErrIntern                  (*(aDBMeasu+ 245))
#define usDBmErrSpeedDelta              (*(aDBMeasu+ 246))
#define usDBmErrRackInDelta             (*(aDBMeasu+ 247))
#define usDBmErrRackInWave              (*(aDBMeasu+ 248))
#define usDBmErrEngineStart             (*(aDBMeasu+ 249))
#define usDBmErrBackup0                 (*(aDBMeasu+ 250))
#define usDBmErrBackup1                 (*(aDBMeasu+ 251))
#define usDBmErrBackup2                 (*(aDBMeasu+ 252))
#define usDBmErrBackup3                 (*(aDBMeasu+ 253))
#define usDBmErrBackup4                 (*(aDBMeasu+ 254))
#define usDBmErrBackup5                 (*(aDBMeasu+ 255))
#define usDBmErrBackup6                 (*(aDBMeasu+ 256))
#define usDBmErrBackup7                 (*(aDBMeasu+ 257))
#define usDBmErrBackup8                 (*(aDBMeasu+ 258))
#define usDBmErrBackup9                 (*(aDBMeasu+ 259))

/* ***************** Part 15: Historys, (146 - 211) ******************* */
#define aDBmHistBegin                     (aDBMeasu+ 260)
#define uiDBmTimer32           (*(INT32U*)(aDBMeasu+ 260))
#define usDBmTimer16U                   (*(aDBMeasu+ 260))
#define usDBmTimer16L                   (*(aDBMeasu+ 261))
#define uiDBmMiles32           (*(INT32U*)(aDBMeasu+ 262))
#define usDBmMiles16U                   (*(aDBMeasu+ 262))
#define usDBmMiles16L                   (*(aDBMeasu+ 263))
#define aDBmSErrBegin                     (aDBMeasu+ 264)
#define usDBmSErrCrankSensor1           (*(aDBMeasu+ 264))
#define usDBmSErrCrankSensor2           (*(aDBMeasu+ 265))
#define usDBmSErrVSSensor               (*(aDBMeasu+ 266))
#define usDBmSErrSetp1Extern            (*(aDBMeasu+ 267))
#define usDBmSErrSetp1ExtSub            (*(aDBMeasu+ 268))
#define usDBmSErrSetp2Extern            (*(aDBMeasu+ 269))
#define usDBmSErrBoostPressure          (*(aDBMeasu+ 270))
#define usDBmSErrOilPressure            (*(aDBMeasu+ 271))
#define usDBmSErrAmbientPressure        (*(aDBMeasu+ 272))
#define usDBmSErrCoolantTemp            (*(aDBMeasu+ 273))
#define usDBmSErrBoostTemp              (*(aDBMeasu+ 274))
#define usDBmSErrOilTemp                (*(aDBMeasu+ 275))
#define usDBmSErrFuelTemp               (*(aDBMeasu+ 276))
#define usDBmSErrExhaustTemp            (*(aDBMeasu+ 277))
#define usDBmSErrLoadInput              (*(aDBMeasu+ 278))
#define usDBmSErrSyncInput              (*(aDBMeasu+ 279))
#define usDBmSErrRackInput              (*(aDBMeasu+ 280))
#define usDBmSErrRackCurrent            (*(aDBMeasu+ 281))
#define usDBmSErrEgrInput               (*(aDBMeasu+ 282))
#define usDBmSErrBeginInput             (*(aDBMeasu+ 283))
#define usDBmSErrRackActuator           (*(aDBMeasu+ 284))
#define usDBmSErrEgrActuator            (*(aDBMeasu+ 285))
#define usDBmSErrBeginActuator          (*(aDBMeasu+ 286))
#define usDBmSErrOilPressWarn           (*(aDBMeasu+ 287))
#define usDBmSErrOilPressEcy            (*(aDBMeasu+ 288))
#define usDBmSErrCoolantTempWarn        (*(aDBMeasu+ 289))
#define usDBmSErrBoostTempWarn          (*(aDBMeasu+ 290))
#define usDBmSErrOilTempWarn            (*(aDBMeasu+ 291))
#define usDBmSErrTempIntern             (*(aDBMeasu+ 292))
#define usDBmSErrVoltage                (*(aDBMeasu+ 293))
#define usDBmSErrOverSpeed              (*(aDBMeasu+ 294))
#define usDBmSErrCAN                    (*(aDBMeasu+ 295))
#define usDBmSErr5VOut                  (*(aDBMeasu+ 296))
#define usDBmSErrADC                    (*(aDBMeasu+ 297))
#define usDBmSErrStack                  (*(aDBMeasu+ 298))
#define usDBmSErrLogical                (*(aDBMeasu+ 299))
#define usDBmSErrCalcTime               (*(aDBMeasu+ 300))
#define usDBmSErrDataCheck              (*(aDBMeasu+ 301))
#define usDBmSErrClearFlash             (*(aDBMeasu+ 302))
#define usDBmSErrParamStore             (*(aDBMeasu+ 303))
#define usDBmSErrPogramTest             (*(aDBMeasu+ 304))
#define usDBmSErrIntern                 (*(aDBMeasu+ 305))
#define usDBmSErrSpeedDelta             (*(aDBMeasu+ 306))
#define usDBmSErrRackInDelta            (*(aDBMeasu+ 307))
#define usDBmSErrRackInWave             (*(aDBMeasu+ 308))
#define usDBmSErrEngineStart            (*(aDBMeasu+ 309))
#define usDBmSErrBackup0                (*(aDBMeasu+ 310))
#define usDBmSErrBackup1                (*(aDBMeasu+ 311))
#define usDBmSErrBackup2                (*(aDBMeasu+ 312))
#define usDBmSErrBackup3                (*(aDBMeasu+ 313))
#define usDBmSErrBackup4                (*(aDBMeasu+ 314))
#define usDBmSErrBackup5                (*(aDBMeasu+ 315))
#define usDBmSErrBackup6                (*(aDBMeasu+ 316))
#define usDBmSErrBackup7                (*(aDBMeasu+ 317))
#define usDBmSErrBackup8                (*(aDBMeasu+ 318))
#define usDBmSErrBackup9                (*(aDBMeasu+ 319))

#endif

/* ******************************************************************** */
/*                     VEC6800 Function Definition                      */
/* ******************************************************************** */
#if    (DB_6800_COMMON_ON == 1)
/* ****************** Part 1: Speed Pickup (0 - 4) ******************** */
#define usDBfSpeedSetpPCOn              (*(aDBFunct+   0))
#define usDBfSpeedIdleAdjustOn          (*(aDBFunct+   1))
#define usDBfSpeedIdleTempCorrOn        (*(aDBFunct+   2))
#define	usDBfSpeedIdleVoltCorrOn        (*(aDBFunct+   3))
#define	usDBfSpeedIdleLoadCorrOn        (*(aDBFunct+   4))

/* ***************** Part 2: Stability/Droop (5 - 12) ***************** */
#define usDBfPIDGainMapOn               (*(aDBFunct+   5))
#define	usDBfPIDStabilityMapOn          (*(aDBFunct+   6))
#define	usDBfPIDDerivativeMapOn         (*(aDBFunct+   7))
#define usDBfPIDTempCorrOn              (*(aDBFunct+   8))
#define usDBfStaticCorrOn               (*(aDBFunct+   9))
#define usDBfDroopOn                    (*(aDBFunct+  10))
#define usDBfDroopMapOn                 (*(aDBFunct+  11))
#define usDBfFuelTempCorrOn             (*(aDBFunct+  12))

/* ********************* Part 3: Ramp (13 - 15) *********************** */
#define usDBfSpeedRampOn                (*(aDBFunct+  13))
#define usDBfSectionalOrFixedRamp       (*(aDBFunct+  14))
#define usDBfStartSpeedRampOn           (*(aDBFunct+  15))

/* ***************** Part 4: Rack Control (16 - 19) ******************* */
#define usDBfRackInputMapOn             (*(aDBFunct+  16))
#define usDBfRackOutputMapOn            (*(aDBFunct+  17))
#define usDBfRackSetpMapOn              (*(aDBFunct+  18))
#define	usDBfRackSpeedCorrOn            (*(aDBFunct+  19))

/* ***************** Part 5: Begin Control (20 - 22) ****************** */
#define usDBfBeginSetpMapOn             (*(aDBFunct+  20))
#define usDBfBeginSetpTempCorrOn        (*(aDBFunct+  21))
#define	usDBfBeginSetpAmbCorrOn         (*(aDBFunct+  22))

/* ****************** Part 6: EGR Control (23 - 27) ******************* */
#define usDBfEgrSetpMapOn               (*(aDBFunct+  23))
#define usDBfEgrSetpTempCorrOn          (*(aDBFunct+  24))
#define usDBfEgrSetpBoostCorrOn         (*(aDBFunct+  25))
#define	usDBfEgrSetpGradientCorrOn      (*(aDBFunct+  26))

/* ******************* Part 7: Monitoring (27 - 32) ******************* */
#define usDBfOilPressWarnCurveOn        (*(aDBFunct+  27))
#define usDBfOilPressEcyCurveOn         (*(aDBFunct+  28))
#define usDBfCoolantTempWarnOn          (*(aDBFunct+  29))
#define usDBfBoostTempWarnOn            (*(aDBFunct+  30))
#define usDBfOilTempWarnOn              (*(aDBFunct+  31))
#define	usDBfEngineStatisticsOn         (*(aDBFunct+  32))

/* ****************** Part 8: Limitations (33 - 36) ******************* */
#define usDBfSpeedLimitOn               (*(aDBFunct+  33))
#define usDBfSpeedLimitTempOn           (*(aDBFunct+  34))
#define usDBfBoostLimitOn               (*(aDBFunct+  35))
#define	usDBfAmbientLimitOn             (*(aDBFunct+  36))

/* ****************** Part 9: PWM Outputs (37 - 48) ******************* */
#define	usDBfDigitalOut1Pole            (*(aDBFunct+  37))
#define	usDBfDigitalOut2Pole            (*(aDBFunct+  38))
#define	usDBfDigitalOut3Pole            (*(aDBFunct+  39))
#define	usDBfDigitalOut4Pole            (*(aDBFunct+  40))
#define	usDBfDigitalOut5Pole            (*(aDBFunct+  41))
#define	usDBfDigitalOut6Pole            (*(aDBFunct+  42))
#define	usDBfDigitalOut7Pole            (*(aDBFunct+  43))
#define	usDBfDigitalOut8Pole            (*(aDBFunct+  44))
#define usDBfPWMOut1FrqOrDuty           (*(aDBFunct+  45))
#define usDBfPWMOut2FrqOrDuty           (*(aDBFunct+  46))
#define usDBfPWMOut3FrqOrDuty           (*(aDBFunct+  47))
#define usDBfPWMOut4FrqOrDuty           (*(aDBFunct+  48))

/* ***************** Part 10: Channel Type, (49 - 97) ***************** */
#define	usDBfSwPoleEngineStop           (*(aDBFunct+  49))
#define	usDBfSwPoleIdleSpeed            (*(aDBFunct+  50))
#define	usDBfSwPoleSpeedFix1            (*(aDBFunct+  51))
#define	usDBfSwPoleSpeedFix2            (*(aDBFunct+  52))
#define	usDBfSwPoleSpeedInc             (*(aDBFunct+  53))
#define	usDBfSwPoleSpeedDec             (*(aDBFunct+  54))
#define	usDBfSwPoleDroop2Or1            (*(aDBFunct+  55))
#define	usDBfSwPoleDroop3Or2            (*(aDBFunct+  56))
#define	usDBfSwPoleSpeedRange2Or1       (*(aDBFunct+  57))
#define	usDBfSwPoleSpeedRange3Or2       (*(aDBFunct+  58))
#define	usDBfSwPoleSpeedLimit2Or1       (*(aDBFunct+  59))
#define	usDBfSwPoleSpeedLimit3Or2       (*(aDBFunct+  60))
#define	usDBfSwPoleOilPump              (*(aDBFunct+  61))
#define	usDBfSwPoleAirHeater            (*(aDBFunct+  62))
#define	usDBfSwPoleEngineStart          (*(aDBFunct+  63))
#define	usDBfSwPoleSetpoint2Or1         (*(aDBFunct+  64))
#define	usDBfSwPoleForcedLimit          (*(aDBFunct+  65))
#define	usDBfSwPoleSyncEnable           (*(aDBFunct+  66))
#define	usDBfSwPoleLoadEnable           (*(aDBFunct+  67))
#define	usDBfSwPoleAutoOrManual         (*(aDBFunct+  68))
#define	usDBfSwPoleErrorReset           (*(aDBFunct+  69))
#define	usDBfSwPolePTO                  (*(aDBFunct+  70))
#define	usDBfSwPoleRPTO                 (*(aDBFunct+  71))
#define	usDBfSwPolePTOCCSet             (*(aDBFunct+  72))
#define	usDBfSwPolePTOCCReset           (*(aDBFunct+  73))
#define	usDBfSwPolePTOAdd               (*(aDBFunct+  74))
#define	usDBfSwPoleMainBrake            (*(aDBFunct+  75))
#define	usDBfSwPoleClutch               (*(aDBFunct+  76))
#define	usDBfSwPoleDiagnostic           (*(aDBFunct+  77))
#define	usDBfSwPoleIMOrAllSpeed         (*(aDBFunct+  78))
#define	usDBfSwPoleCruiseControl        (*(aDBFunct+  79))
#define	usDBfSwPoleAirConditioner       (*(aDBFunct+  80))
#define usDBfChanTypeSetp1Ext           (*(aDBFunct+  81))
#define usDBfChanTypeSetp1Sub           (*(aDBFunct+  82))
#define usDBfChanTypeSetp2Ext           (*(aDBFunct+  83))
#define usDBfChanTypeBoostPress         (*(aDBFunct+  84))
#define usDBfChanTypeOilPress           (*(aDBFunct+  85))
#define usDBfChanTypeAmbPress           (*(aDBFunct+  86))
#define usDBfChanTypeCoolantTemp        (*(aDBFunct+  87))
#define usDBfChanTypeBoostTemp          (*(aDBFunct+  88))
#define usDBfChanTypeOilTemp            (*(aDBFunct+  89))
#define usDBfChanTypeFuelTemp           (*(aDBFunct+  90))
#define usDBfChanTypeExhaustTemp        (*(aDBFunct+  91))
#define usDBfChanTypeLoadInput          (*(aDBFunct+  92))
#define usDBfChanTypeSyncInput          (*(aDBFunct+  93))
#define usDBfChanTypeRackCurrent        (*(aDBFunct+  94))
#define usDBfChanTypeRackInput          (*(aDBFunct+  95))
#define usDBfChanTypeEgrInput           (*(aDBFunct+  96))
#define usDBfChanTypeBeginInput         (*(aDBFunct+  97))

/* *********************** Part 11: Errors (98) *********************** */
#define usDBfStoreSErrOn                (*(aDBFunct+  98))

/* ******************* Part 12: Generator (99 - 100) ****************** */
#define usDBfSyncAnalogOrDigit          (*(aDBFunct+  99))
#define usDBfLoadControlOrPot           (*(aDBFunct+ 100))

/* ******************* Part 13: Vehicle (101 - 107) ******************* */
#define	usDBfSwitchIdleSoftOn           (*(aDBFunct+ 101))
#define	usDBfSwitchIMModeSoftOn         (*(aDBFunct+ 102))
#define	usDBfSpeedMaxVSSZeroOn          (*(aDBFunct+ 103))
#define	usDBfEBrakeServiceOn            (*(aDBFunct+ 104))
#define	usDBfEBrakeCruiseOn             (*(aDBFunct+ 105))
#define	usDBfIMGovernorOn               (*(aDBFunct+ 106))
#define	usDBfIMFuelRampOn               (*(aDBFunct+ 107))
#define	usDBfSpeedIdleACCorrOn          (*(aDBFunct+ 108))
#define	usDBfAirHeaterCorrAmbOn         (*(aDBFunct+ 109))
#define	usDBfAirHeaterCorrVoltOn        (*(aDBFunct+ 110))

/* ****************** Part 14: Others, (100 - 109) ******************** */
#define	usDBfFunctBackup0               (*(aDBFunct+ 111))
#define	usDBfFunctBackup1               (*(aDBFunct+ 112))
#define	usDBfFunctBackup2               (*(aDBFunct+ 113))
#define	usDBfFunctBackup3               (*(aDBFunct+ 114))
#define	usDBfFunctBackup4               (*(aDBFunct+ 115))
#define	usDBfFunctBackup5               (*(aDBFunct+ 116))
#define	usDBfFunctBackup6               (*(aDBFunct+ 117))
#define	usDBfFunctBackup7               (*(aDBFunct+ 118))
#define	usDBfFunctBackup8               (*(aDBFunct+ 119))

#endif
/* ******************************************************************** */
/*                      VEC6800 Curve Definition                        */
/* ******************************************************************** */
#if    (DB_6800_COMMON_ON == 1)
/* ************************** 1: PID Gain Map ************************* */
#define aDBcPIDGainMap_n                 (aDBCurve+   0)    /* 0:   8   */
#define aDBcPIDGainMap_Q                 (aDBCurve+   8)    /* 1:   8   */
#define aDBcPIDGainMap_C                 (aDBCurve+  16)    /* 2:   8*8 */

/* ************************** 2: Boost Limit ************************** */
#define aDBcBoostLimit_n                 (aDBCurve+  80)    /* 3:   8   */
#define aDBcBoostLimit_p                 (aDBCurve+  88)    /* 4:   8   */
#define aDBcBoostLimit_Q                 (aDBCurve+  96)    /* 5:   8*8 */

/* ************************* 3: Ambient Limit ************************* */
#define aDBcAmbientLimit_n               (aDBCurve+ 160)    /* 6:   8   */
#define aDBcAmbientLimit_p               (aDBCurve+ 168)    /* 7:   8   */
#define aDBcAmbientLimit_Q               (aDBCurve+ 176)    /* 8:   8*8 */

/* ************************** 4: Speed Limit ************************** */
#define aDBcSpeedLimit_n                 (aDBCurve+ 240)    /* 9:  30   */
#define aDBcSpeedLimit_Q1                (aDBCurve+ 270)    /* 10: 30   */
#define aDBcSpeedLimit_Q2                (aDBCurve+ 300)    /* 11: 30   */
#define aDBcSpeedLimit_Q3                (aDBCurve+ 330)    /* 12: 30   */

/* ******************** 5: Oil Press Warn and Ecy ********************* */
#define aDBcOilPressWarn_n               (aDBCurve+ 360)    /* 13: 10   */
#define aDBcOilPressWarn_p               (aDBCurve+ 370)    /* 14: 10   */
#define aDBcOilPressEcy_n                (aDBCurve+ 380)    /* 15: 10   */
#define aDBcOilPressEcy_p                (aDBCurve+ 390)    /* 16: 10   */

/* ********************** 6: Rack Position Maps *********************** */
#define aDBcRackSetp_n                   (aDBCurve+ 400)    /* 17: 8    */
#define aDBcRackSetp_Q                   (aDBCurve+ 408)    /* 18: 8    */
#define aDBcRackSetp_p                   (aDBCurve+ 416)    /* 19: 8*8  */
#define aDBcRackSetpAlt_Q                (aDBCurve+ 480)    /* 20: 2    */
#define aDBcRackSetpAlt_p                (aDBCurve+ 482)    /* 21: 2    */

/* ************************ 7: Rack Input Maps ************************ */
#define aDBcRackInputMap_A               (aDBCurve+ 484)    /* 22: 10   */
#define aDBcRackInputMap_p               (aDBCurve+ 494)    /* 23: 10   */

/* *********************** 8: Rack Output Maps ************************ */
#define aDBcRackOutputMap_p              (aDBCurve+ 504)    /* 24: 10   */
#define aDBcRackOutputMap_D              (aDBCurve+ 514)    /* 25: 10   */
#define aDBcRackOutputAlt_p              (aDBCurve+ 524)    /* 26: 2    */
#define aDBcRackOutputAlt_D              (aDBCurve+ 526)    /* 27: 2    */

/* ************************* 9: Begin Setpoint ************************ */
#define aDBcBeginSetp_n                  (aDBCurve+ 528)    /* 28: 8    */
#define aDBcBeginSetp_Q                  (aDBCurve+ 536)    /* 29: 8    */
#define aDBcBeginSetp_B                  (aDBCurve+ 544)    /* 30: 8*8  */

/* ************************* 10: EGR Setpoint ************************* */
#define aDBcEgrSetp_n                    (aDBCurve+ 608)    /* 31: 8    */
#define aDBcEgrSetp_Q                    (aDBCurve+ 616)    /* 32: 8    */
#define aDBcEgrSetp_p                    (aDBCurve+ 624)    /* 33: 8*8  */

/* ************************* 11: PID I/D Map ************************** */
#define aDBcPIDStabMap_n                 (aDBCurve+ 688)    /* 34: 10   */
#define aDBcPIDStabMap_C                 (aDBCurve+ 698)    /* 35: 10   */
#define aDBcPIDDeriMap_n                 (aDBCurve+ 708)    /* 36: 10   */
#define aDBcPIDDeriMap_C                 (aDBCurve+ 718)    /* 37: 10   */

/* ********************* 12: Temperature Sensor *********************** */
#define aDBcTempIn1_D                    (aDBCurve+ 728)    /* 38: 10   */
#define aDBcTempIn1_T                    (aDBCurve+ 738)    /* 39: 10   */
#define aDBcTempIn2_D                    (aDBCurve+ 748)    /* 40: 10   */
#define aDBcTempIn2_T                    (aDBCurve+ 758)    /* 41: 10   */

/* *********************** 13: Pedal Angle Map ************************ */
#define aDBcIMFuelMap_n                  (aDBCurve+ 768)    /* 42: 10   */
#define aDBcIMFuelMap_S                  (aDBCurve+ 778)    /* 43: 10   */
#define aDBcIMFuelMap_Q                  (aDBCurve+ 788)    /* 44: 100  */
#define aDBcSetp1Map_n                   (aDBcIMFuelMap_n+  0)
#define aDBcSetp1Map_Min                 (aDBcIMFuelMap_n+ 20)
#define aDBcSetp1Map_Max                 (aDBcIMFuelMap_n+ 40)
#define aDBcSetp1Sub_n                   (aDBcIMFuelMap_n+ 60)
#define aDBcSetp1Sub_Min                 (aDBcIMFuelMap_n+ 80)
#define aDBcSetp1Sub_Max                 (aDBcIMFuelMap_n+100)
#define aDBcSetp2Map_n                   (aDBcIMFuelMap_n+ 60)
#define aDBcSetp2Map_Min                 (aDBcIMFuelMap_n+ 80)
#define aDBcSetp2Map_Max                 (aDBcIMFuelMap_n+100)

/* ************************** 14: Droop Map *************************** */
#if    (DB_VERSION >= 6840)
#define aDBcDroopMap_n                   (aDBCurve+ 888)    /* 45: 10   */
#define aDBcDroop1Map_n                  (aDBCurve+ 888)    /* 45: 10   */
#define aDBcDroop2Map_n                  (aDBCurve+ 888)    /* 45: 10   */
#define aDBcDroop3Map_n                  (aDBCurve+ 888)    /* 45: 10   */
#define aDBcDroopMap_D                   (aDBCurve+ 898)    /* 46: 10   */
#define aDBcDroop1Map_D                  (aDBCurve+ 898)    /* 46: 10   */
#define aDBcDroop2Map_D                  (aDBCurve+ 908)    /* 46: 10   */
#define aDBcDroop3Map_D                  (aDBCurve+ 918)    /* 46: 10   */
#else
#define aDBcDroopMap_n                   (aDBCurve+ 888)    /* 45: 10   */
#define aDBcDroopMap_D                   (aDBCurve+ 898)    /* 46: 10   */
#define aDBcDroop1Map_n                  (aDBCurve+ 888)    /* 45: 10   */
#define aDBcDroop2Map_n                  (aDBCurve+ 888)    /* 45: 10   */
#define aDBcDroop3Map_n                  (aDBCurve+ 888)    /* 45: 10   */
#define aDBcDroop1Map_D                  (aDBCurve+1080)    /* 46: 10   */
#define aDBcDroop2Map_D                  (aDBCurve+ 898)    /* 46: 10   */
#define aDBcDroop3Map_D                  (aDBCurve+1090)    /* 46: 10   */
#endif

/* ************************* 15: Data Plate *************************** */
#if    (DB_VERSION >= 6840)
#define aDBcDataPlate_D                  (aDBCurve+ 928)    /* 47: 152  */
#else
#define aDBcDataPlate_D                  (aDBCurve+ 908)    /* 47: 172  */
#endif

/* ************************* 16: Data Plate *************************** */
#define aDBcCurveBackup1_x               (aDBCurve+1080)    /* 48: 8    */
#define aDBcCurveBackup1_y               (aDBCurve+1088)    /* 49: 8    */
#define aDBcCurveBackup1_z               (aDBCurve+1096)    /* 50: 8*8  */

/* ************************* 17: Data Plate *************************** */
#define aDBcCurveBackup2_x               (aDBCurve+1160)    /* 51: 10   */
#define aDBcCurveBackup2_y               (aDBCurve+1170)    /* 52: 10   */

/* ************************* 18: Statistics *************************** */
#define aDBcStatistics_n                 (aDBCurve+1180)    /* 53: 10   */
#define aDBcStatistics_Q                 (aDBCurve+1190)    /* 54: 10   */
#define aDBcStatistics_T                 (aDBCurve+1200)    /* 55: 100  */

#endif
/* ******************************************************************** */
/*                      VEC8000 Parameter Definition                    */
/* ******************************************************************** */
/* ******************************************************************** */
/*                      VEC8000 Parameter Definition                    */
/* ******************************************************************** */
#if    (DB_ENGINE_EFI_ON == 1)
/* ****************** Part 1: Teeth/Speed (0 - 26) ******************** */
#define usDBpTeethCrank1                (*(aDBParam+   0))
#define usDBpTeethCrank2                (*(aDBParam+   1))
#define usDBpGapToCrankSensor1          (*(aDBParam+   2))
#define usDBpGapToCrankSensor2          (*(aDBParam+   3))
#define usDBpCamIndexToSensor           (*(aDBParam+   4))
#define usDBpGapRatio                   (*(aDBParam+   5))
#define usDBpSpeedIdle1                 (*(aDBParam+   6))
#define usDBpSpeedIdle2                 (*(aDBParam+   7))
#define usDBpSpeedIdle3                 (*(aDBParam+   8))
#define usDBpSpeedMax1                  (*(aDBParam+   9))
#define usDBpSpeedMax2                  (*(aDBParam+  10))
#define usDBpSpeedMax3                  (*(aDBParam+  11))
#define usDBpSpeedFix1                  (*(aDBParam+  12))
#define usDBpSpeedFix2                  (*(aDBParam+  13))
#define usDBpSpeedSetpPC                (*(aDBParam+  14))
#define usDBpSpeedOver                  (*(aDBParam+  15))
#define usDBpSpeedIdleMin               (*(aDBParam+  16))
#define usDBpSpeedIdleMax               (*(aDBParam+  17))
#define usDBpSpeedIdleIncByTemp         (*(aDBParam+  18))
#define usDBpSpeedIdleIncTempLow        (*(aDBParam+  19))
#define usDBpSpeedIdleIncTempHigh       (*(aDBParam+  20))
#define usDBpSpeedIdleIncByVolt         (*(aDBParam+  21))
#define usDBpSpeedIdleIncVoltLow        (*(aDBParam+  22))
#define usDBpSpeedIdleIncVoltHigh       (*(aDBParam+  23))
#define usDBpSpeedIdleIncByLoad         (*(aDBParam+  24))
#define usDBpSpeedIdleIncLoadLow        (*(aDBParam+  25))
#define usDBpSpeedIdleIncLoadHigh       (*(aDBParam+  26))

/* **************** Part 2: Stability/Droop (27 - 49) ***************** */
#define usDBpGain                       (*(aDBParam+  27))
#define usDBpStability                  (*(aDBParam+  28))
#define usDBpDerivative                 (*(aDBParam+  29))
#define usDBpStaticCorrFactor           (*(aDBParam+  30))
#define usDBpStaticCorrRange            (*(aDBParam+  31))
#define usDBpPIDCorrTempLow             (*(aDBParam+  32))
#define usDBpPIDCorrTempHigh            (*(aDBParam+  33))
#define usDBpPIDCorrAtTempLow           (*(aDBParam+  34))
#define usDBpDroop1                     (*(aDBParam+  35))
#define usDBpDroop1RefLow               (*(aDBParam+  36))
#define usDBpDroop1RefHigh              (*(aDBParam+  37))
#define usDBpDroop1SpeedRef             (*(aDBParam+  38))
#define usDBpDroop2                     (*(aDBParam+  39))
#define usDBpDroop2RefLow               (*(aDBParam+  40))
#define usDBpDroop2RefHigh              (*(aDBParam+  41))
#define usDBpDroop2SpeedRef             (*(aDBParam+  42))
#define usDBpDroop3                     (*(aDBParam+  43))
#define usDBpDroop3RefLow               (*(aDBParam+  44))
#define usDBpDroop3RefHigh              (*(aDBParam+  45))
#define usDBpDroop3SpeedRef             (*(aDBParam+  46))
#define usDBpFuelCorrTempLow            (*(aDBParam+  47))
#define usDBpFuelCorrTempHigh           (*(aDBParam+  48))
#define usDBpFuelCorrAtTempHigh         (*(aDBParam+  49))

/* ****************** Part 3: Ramp/Start (50 - 70) ******************** */
#define usDBpSpeedRampUp                (*(aDBParam+  50))
#define usDBpSpeedRampDown              (*(aDBParam+  51))
#define usDBpSpeedRampUp2               (*(aDBParam+  52))
#define usDBpSpeedRampDown2             (*(aDBParam+  53))
#define usDBpSpeedRampUp3               (*(aDBParam+  54))
#define usDBpSpeedRampDown3             (*(aDBParam+  55))
#define usDBpSpeedSwitchToRamp2         (*(aDBParam+  56))
#define usDBpSpeedSwitchToRamp3         (*(aDBParam+  57))
#define usDBpDigitPotSpeedRamp          (*(aDBParam+  58))
#define usDBpStartSpeedRampUp           (*(aDBParam+  59))
#define usDBpStartType                  (*(aDBParam+  60))
#define usDBpStartLimitDelay            (*(aDBParam+  61))
#define usDBpStartSpeed1                (*(aDBParam+  62))
#define usDBpStartSpeed2                (*(aDBParam+  63))
#define usDBpStartSpeed3                (*(aDBParam+  64))
#define usDBpStartFuel1                 (*(aDBParam+  65))
#define usDBpStartFuel2                 (*(aDBParam+  66))
#define usDBpStartDuration1             (*(aDBParam+  67))
#define usDBpStartDuration2             (*(aDBParam+  68))
#define usDBpStartTempWarm              (*(aDBParam+  69))
#define usDBpStartTempCold              (*(aDBParam+  70))

/* *************** Part 4: Solenoid Valves (71 - 84) ****************** */
#define usDBpSolPeakTime                (*(aDBParam+  71))
#define usDBpSolZeroTime                (*(aDBParam+  72))
#define usDBpSolRisingMin               (*(aDBParam+  73))
#define usDBpSolRisingMax               (*(aDBParam+  74))
#define usDBpSolFaultEcyNo              (*(aDBParam+  75))
#define usDBpSolDelayDefault            (*(aDBParam+  76))
#define usDBpSolDelayCorrVoltLow        (*(aDBParam+  77))
#define usDBpSolDelayCorrVoltHigh       (*(aDBParam+  78))
#define usDBpSolDelayCorrAtVoltLow      (*(aDBParam+  79))
#define usDBpSolDelayCorrAtVoltHigh     (*(aDBParam+  80))
#define usDBpCylinderMaskA              (*(aDBParam+  81))
#define usDBpCylinderMaskB              (*(aDBParam+  82))
#define usDBpCylinderMaskRefLow         (*(aDBParam+  83))
#define usDBpCylinderMaskRefHigh        (*(aDBParam+  84))

/* **************** Part 5: Begin Control, (85 - 96) ****************** */
#define usDBpBeginGain                  (*(aDBParam+  85))
#define usDBpBeginStability             (*(aDBParam+  86))
#define usDBpBeginDerivative            (*(aDBParam+  87))
#define usDBpBeginSetpoint              (*(aDBParam+  88))
#define usDBpBeginControlTest           (*(aDBParam+  89))
#define usDBpBeginCorrTempLow           (*(aDBParam+  90))
#define usDBpBeginCorrTempHigh          (*(aDBParam+  91))
#define usDBpBeginCorrAtTempLow         (*(aDBParam+  92))
#define usDBpBeginCorrAmbLow            (*(aDBParam+  93))
#define usDBpBeginCorrAmbHigh           (*(aDBParam+  94))
#define usDBpBeginCorrAtAmbLow          (*(aDBParam+  95))
#define usDBpBeginCorrAmbDelay          (*(aDBParam+  96))

/* ***************** Part 6: EGR Control, (97 - 110) ****************** */
#define	usDBpEgrGain                    (*(aDBParam+  97))
#define	usDBpEgrStability               (*(aDBParam+  98))
#define	usDBpEgrDerivative	            (*(aDBParam+  99))
#define	usDBpEgrSetpoint                (*(aDBParam+ 100))
#define	usDBpEgrControlTest             (*(aDBParam+ 101))
#define	usDBpEgrCorrTempLow             (*(aDBParam+ 102))
#define	usDBpEgrCorrTempHigh            (*(aDBParam+ 103))
#define	usDBpEgrCorrAtTempLow           (*(aDBParam+ 104))
#define	usDBpEgrCorrBoostLow            (*(aDBParam+ 105))
#define	usDBpEgrCorrBoostHigh           (*(aDBParam+ 106))
#define	usDBpEgrCorrAtBoostLow          (*(aDBParam+ 107))
#define	usDBpEgrCorrGradientLow         (*(aDBParam+ 108))
#define	usDBpEgrCorrGradientHigh        (*(aDBParam+ 109))
#define	usDBpEgrCorrAtGradientHigh      (*(aDBParam+ 110))

/* ******************* Part 7: Can Bus, (111 - 114) ******************* */
#define	usDBpCanBaudrate                (*(aDBParam+ 111))
#define	usDBpCanRxIDNumber              (*(aDBParam+ 112))
#define	usDBpCanTxIDNumber              (*(aDBParam+ 113))
#define	usDBpCanTxPeriod                (*(aDBParam+ 114))

/* ****************** Part 8: Monitoring, (115 - 124) ***************** */
#define usDBpOilPressStartDelay         (*(aDBParam+ 115))
#define usDBpOilPressWarnDelay          (*(aDBParam+ 116))
#define usDBpOilPressEcyDelay           (*(aDBParam+ 117))
#define usDBpCoolantTempLimit           (*(aDBParam+ 118))
#define usDBpBoostTempLimit             (*(aDBParam+ 119))
#define usDBpOilTempLimit               (*(aDBParam+ 120))
#define usDBpSpeedDeltaWarnLimit        (*(aDBParam+ 121))
#define	usDBpCRPressure1Limit           (*(aDBParam+ 122))
#define	usDBpCRPressure2Limit           (*(aDBParam+ 123))
#define usDBpStatisticsTime             (*(aDBParam+ 124))

/* ****************** Part 9: Limitation (125 - 129) ****************** */
#define usDBpSpeedLimitTempDec          (*(aDBParam+ 125))
#define usDBpSpeedLimitTempLow          (*(aDBParam+ 126))
#define usDBpSpeedLimitTempHigh         (*(aDBParam+ 127))
#define usDBpFuelLimitMaxAbsolut        (*(aDBParam+ 128))
#define usDBpFuelLimitForced            (*(aDBParam+ 129))

/* ************** Part 10: Switch Assignment (130 - 161) ************** */
#define	usDBpFunctEngineStop            (*(aDBParam+ 130))
#define	usDBpFunctIdleSpeed	            (*(aDBParam+ 131))
#define	usDBpFunctSpeedFix1	            (*(aDBParam+ 132))
#define	usDBpFunctSpeedFix2	            (*(aDBParam+ 133))
#define	usDBpFunctSpeedInc	            (*(aDBParam+ 134))
#define	usDBpFunctSpeedDec	            (*(aDBParam+ 135))
#define	usDBpFunctDroop2Or1	            (*(aDBParam+ 136))
#define	usDBpFunctDroop3Or2	            (*(aDBParam+ 137))
#define	usDBpFunctSpeedRange2Or1        (*(aDBParam+ 138))
#define	usDBpFunctSpeedRange3Or2        (*(aDBParam+ 139))
#define	usDBpFunctSpeedLimit2Or1        (*(aDBParam+ 140))
#define	usDBpFunctSpeedLimit3Or2        (*(aDBParam+ 141))
#define	usDBpFunctOilPump               (*(aDBParam+ 142))
#define	usDBpFunctAirHeater             (*(aDBParam+ 143))
#define	usDBpFunctEngineStart           (*(aDBParam+ 144))
#define	usDBpFunctSetpoint2Or1	        (*(aDBParam+ 145))
#define	usDBpFunctForcedLimit           (*(aDBParam+ 146))
#define	usDBpFunctSyncEnable            (*(aDBParam+ 147))
#define	usDBpFunctLoadEnable            (*(aDBParam+ 148))
#define	usDBpFunctAutoOrManual	        (*(aDBParam+ 149))
#define	usDBpFunctErrorReset            (*(aDBParam+ 150))
#define	usDBpFunctPTO                   (*(aDBParam+ 151))
#define	usDBpFunctRPTO                  (*(aDBParam+ 152))
#define	usDBpFunctPTOCCSet              (*(aDBParam+ 153))
#define	usDBpFunctPTOCCReset            (*(aDBParam+ 154))
#define	usDBpFunctPTOAdd                (*(aDBParam+ 155))
#define	usDBpFunctMainBrake             (*(aDBParam+ 156))
#define	usDBpFunctClutch                (*(aDBParam+ 157))
#define	usDBpFunctDiagnostic            (*(aDBParam+ 158))
#define	usDBpFunctIMOrAllSpeed          (*(aDBParam+ 159))
#define	usDBpFunctCruiseControl	        (*(aDBParam+ 160))
#define	usDBpFunctAirConditioner        (*(aDBParam+ 161))

/* ************* Part 11: Sensor Assignment, (162 - 210) ************** */
#define usDBpAssignInSetp1Ext           (*(aDBParam+ 162))
#define usDBpAssignInSetp1Sub           (*(aDBParam+ 163))
#define usDBpAssignInSetp2Ext           (*(aDBParam+ 164))
#define usDBpAssignInBoostPress         (*(aDBParam+ 165))
#define usDBpAssignInOilPress           (*(aDBParam+ 166))
#define usDBpAssignInAmbPress           (*(aDBParam+ 167))
#define usDBpAssignInCoolantTemp        (*(aDBParam+ 168))
#define usDBpAssignInBoostTemp          (*(aDBParam+ 169))
#define usDBpAssignInOilTemp            (*(aDBParam+ 170))
#define usDBpAssignInFuelTemp           (*(aDBParam+ 171))
#define usDBpAssignInExhaustTemp        (*(aDBParam+ 172))
#define usDBpAssignInLoadInput          (*(aDBParam+ 173))
#define usDBpAssignInSyncInput          (*(aDBParam+ 174))
#define usDBpAssignInEgrInput           (*(aDBParam+ 175))
#define usDBpAssignInBeginInput         (*(aDBParam+ 176))
#define usDBpAssignInRailPress1         (*(aDBParam+ 177))
#define usDBpAssignInRailPress2         (*(aDBParam+ 178))
#define	usDBpAssignInCurrent1           (*(aDBParam+ 179))
#define	usDBpAssignInCurrent2           (*(aDBParam+ 180))
#define	aDBpADCChanFilter                 (aDBParam+ 181)
#define	usDBpADCChanFilter00            (*(aDBParam+ 181))
#define	usDBpADCChanFilter01            (*(aDBParam+ 182))
#define	usDBpADCChanFilter02            (*(aDBParam+ 183))
#define	usDBpADCChanFilter03            (*(aDBParam+ 184))
#define	usDBpADCChanFilter04            (*(aDBParam+ 185))
#define	usDBpADCChanFilter05            (*(aDBParam+ 186))
#define	usDBpADCChanFilter06            (*(aDBParam+ 187))
#define	usDBpADCChanFilter07            (*(aDBParam+ 188))
#define	usDBpADCChanFilter08            (*(aDBParam+ 189))
#define	usDBpADCChanFilter09            (*(aDBParam+ 190))
#define	usDBpADCChanFilter10            (*(aDBParam+ 191))
#define	usDBpADCChanFilter11            (*(aDBParam+ 192))
#define	usDBpADCChanFilter12            (*(aDBParam+ 193))
#define	usDBpADCChanFilter13            (*(aDBParam+ 194))
#define	usDBpADCChanFilter14            (*(aDBParam+ 195))
#define	usDBpADCChanFilter15            (*(aDBParam+ 196))
#define	usDBpADCChanFilter16            (*(aDBParam+ 197))
#define	usDBpADCChanFilter17            (*(aDBParam+ 198))
#define	usDBpADCChanFilter18            (*(aDBParam+ 199))
#define	usDBpADCChanFilter19            (*(aDBParam+ 200))
#define	usDBpADCChanFilter20            (*(aDBParam+ 201))
#define	usDBpADCChanFilter21            (*(aDBParam+ 202))
#define	usDBpADCChanFilter22            (*(aDBParam+ 203))
#define	usDBpADCChanFilter23            (*(aDBParam+ 204))
#define	usDBpADCChanFilter24            (*(aDBParam+ 205))
#define	usDBpADCChanFilter25            (*(aDBParam+ 206))
#define	usDBpADCChanFilter26            (*(aDBParam+ 207))
#define	usDBpADCChanFilter27            (*(aDBParam+ 208))
#define	usDBpADCChanFilter28            (*(aDBParam+ 209))
#define	usDBpADCChanFilter29            (*(aDBParam+ 210))
#define	usDBpFuelAverageFilter          (*(aDBParam+ 210)) /* ??? */

/* ************* Part 12: Sensor Calibration, (211 - 276) ************* */
#define	usDBpSetp1ExtRefLow             (*(aDBParam+ 211))
#define	usDBpSetp1ExtRefHigh            (*(aDBParam+ 212))
#define	usDBpSetp1ExtErrorLow           (*(aDBParam+ 213))
#define	usDBpSetp1ExtErrorHigh          (*(aDBParam+ 214))
#define	usDBpSetp1SubRefLow             (*(aDBParam+ 215))
#define	usDBpSetp1SubRefHigh            (*(aDBParam+ 216))
#define	usDBpSetp1SubErrorLow           (*(aDBParam+ 217))
#define	usDBpSetp1SubErrorHigh          (*(aDBParam+ 218))
#define	usDBpSetp2ExtRefLow             (*(aDBParam+ 219))
#define	usDBpSetp2ExtRefHigh            (*(aDBParam+ 220))
#define	usDBpSetp2ExtErrorLow           (*(aDBParam+ 221))
#define	usDBpSetp2ExtErrorHigh          (*(aDBParam+ 222))
#define	usDBpBoostPressRefLow           (*(aDBParam+ 223))
#define	usDBpBoostPressRefHigh          (*(aDBParam+ 224))
#define	usDBpBoostPressErrorLow         (*(aDBParam+ 225))
#define	usDBpBoostPressErrorHigh        (*(aDBParam+ 226))
#define	usDBpOilPressRefLow             (*(aDBParam+ 227))
#define	usDBpOilPressRefHigh            (*(aDBParam+ 228))
#define	usDBpOilPressErrorLow           (*(aDBParam+ 229))
#define	usDBpOilPressErrorHigh          (*(aDBParam+ 230))
#define	usDBpAmbPressRefLow	            (*(aDBParam+ 231))
#define	usDBpAmbPressRefHigh            (*(aDBParam+ 232))
#define	usDBpAmbPressErrorLow           (*(aDBParam+ 233))
#define	usDBpAmbPressErrorHigh          (*(aDBParam+ 234))
#define	usDBpCoolantTempErrorLow        (*(aDBParam+ 235))
#define	usDBpCoolantTempErrorHigh       (*(aDBParam+ 236))
#define	usDBpBoostTempErrorLow          (*(aDBParam+ 237))
#define	usDBpBoostTempErrorHigh         (*(aDBParam+ 238))
#define	usDBpOilTempErrorLow            (*(aDBParam+ 239))
#define	usDBpOilTempErrorHigh           (*(aDBParam+ 240))
#define	usDBpFuelTempErrorLow           (*(aDBParam+ 241))
#define	usDBpFuelTempErrorHigh          (*(aDBParam+ 242))
#define	usDBpExhaustTempErrorLow        (*(aDBParam+ 243))
#define	usDBpExhaustTempErrorHigh       (*(aDBParam+ 244))
#define	usDBpLoadInputRefLow            (*(aDBParam+ 245))
#define	usDBpLoadInputRefHigh           (*(aDBParam+ 246))
#define	usDBpLoadInputErrorLow          (*(aDBParam+ 247))
#define	usDBpLoadInputErrorHigh         (*(aDBParam+ 248))
#define	usDBpSyncInputRefLow            (*(aDBParam+ 249))
#define	usDBpSyncInputRefHigh           (*(aDBParam+ 250))
#define	usDBpSyncInputErrorLow          (*(aDBParam+ 251))
#define	usDBpSyncInputErrorHigh         (*(aDBParam+ 252))
#define	usDBpEgrInputRefLow             (*(aDBParam+ 253))
#define	usDBpEgrInputRefHigh            (*(aDBParam+ 254))
#define	usDBpEgrInputErrorLow           (*(aDBParam+ 255))
#define	usDBpEgrInputErrorHigh          (*(aDBParam+ 256))
#define	usDBpBeginInputRefLow           (*(aDBParam+ 257))
#define	usDBpBeginInputRefHigh          (*(aDBParam+ 258))
#define	usDBpBeginInputErrorLow         (*(aDBParam+ 259))
#define	usDBpBeginInputErrorHigh        (*(aDBParam+ 260))
#define usDBpRailPress1RefLow           (*(aDBParam+ 261))
#define usDBpRailPress1RefHigh          (*(aDBParam+ 262))
#define usDBpRailPress1ErrorLow         (*(aDBParam+ 263))
#define usDBpRailPress1ErrorHigh        (*(aDBParam+ 264))
#define usDBpRailPress2RefLow           (*(aDBParam+ 265))
#define usDBpRailPress2RefHigh          (*(aDBParam+ 266))
#define usDBpRailPress2ErrorLow         (*(aDBParam+ 267))
#define usDBpRailPress2ErrorHigh        (*(aDBParam+ 268))
#define	usDBpCurrent1RefLow             (*(aDBParam+ 269))
#define	usDBpCurrent1RefHigh            (*(aDBParam+ 270))
#define	usDBpCurrent1ErrorLow           (*(aDBParam+ 271))
#define	usDBpCurrent1ErrorHigh          (*(aDBParam+ 272))
#define	usDBpCurrent2RefLow             (*(aDBParam+ 273))
#define	usDBpCurrent2RefHigh            (*(aDBParam+ 274))
#define	usDBpCurrent2ErrorLow           (*(aDBParam+ 275))
#define	usDBpCurrent2ErrorHigh          (*(aDBParam+ 276))

/* ************* Part 13: Substitute Values, (277 - 295) ************** */
#define	usDBpSubstSetp1Ext	            (*(aDBParam+ 277))
#define	usDBpSubstSetp1Sub	            (*(aDBParam+ 278))
#define	usDBpSubstSetp2Ext	            (*(aDBParam+ 279))
#define	usDBpSubstBoostPress	        (*(aDBParam+ 280))
#define	usDBpSubstOilPress              (*(aDBParam+ 281))
#define	usDBpSubstAmbientPress          (*(aDBParam+ 282))
#define	usDBpSubstCoolantTemp           (*(aDBParam+ 283))
#define	usDBpSubstBoostTemp	            (*(aDBParam+ 284))
#define	usDBpSubstOilTemp               (*(aDBParam+ 285))
#define	usDBpSubstFuelTemp	            (*(aDBParam+ 286))
#define	usDBpSubstExhaustTemp           (*(aDBParam+ 287))
#define	usDBpSubstLoadInput	            (*(aDBParam+ 288))
#define	usDBpSubstSyncInput	            (*(aDBParam+ 289))
#define	usDBpSubstEgrInput              (*(aDBParam+ 290))
#define	usDBpSubstBeginInput            (*(aDBParam+ 291))
#define usDBpSubstRailPress1            (*(aDBParam+ 292))
#define usDBpSubstRailPress2            (*(aDBParam+ 293))
#define	usDBpSubstCurrent1              (*(aDBParam+ 294))
#define	usDBpSubstCurrent2              (*(aDBParam+ 295))

/* ************* Part 14: Output Calibration, (296 - 327) ************* */
#define	usDBpDigitalOut1Assign          (*(aDBParam+ 296))
#define	usDBpDigitalOut2Assign          (*(aDBParam+ 297))
#define	usDBpDigitalOut3Assign          (*(aDBParam+ 298))
#define	usDBpDigitalOut4Assign          (*(aDBParam+ 299))
#define	usDBpDigitalOut5Assign          (*(aDBParam+ 300))
#define	usDBpDigitalOut6Assign          (*(aDBParam+ 301))
#define	usDBpDigitalOut7Assign          (*(aDBParam+ 302))
#define	usDBpDigitalOut8Assign          (*(aDBParam+ 303))
#define	usDBpPWMOut1Assign              (*(aDBParam+ 304))
#define	usDBpPWMOut1RefLow              (*(aDBParam+ 305))
#define	usDBpPWMOut1RefHigh             (*(aDBParam+ 306))
#define	usDBpPWMOut1FrqOrDutyMin        (*(aDBParam+ 307))
#define	usDBpPWMOut1FrqOrDutyMax        (*(aDBParam+ 308))
#define	usDBpPWMOut1Period              (*(aDBParam+ 309))
#define	usDBpPWMOut2Assign              (*(aDBParam+ 310))
#define	usDBpPWMOut2RefLow              (*(aDBParam+ 311))
#define	usDBpPWMOut2RefHigh             (*(aDBParam+ 312))
#define	usDBpPWMOut2FrqOrDutyMin        (*(aDBParam+ 313))
#define	usDBpPWMOut2FrqOrDutyMax        (*(aDBParam+ 314))
#define	usDBpPWMOut2Period              (*(aDBParam+ 315))
#define	usDBpPWMOut3Assign              (*(aDBParam+ 316))
#define	usDBpPWMOut3RefLow              (*(aDBParam+ 317))
#define	usDBpPWMOut3RefHigh             (*(aDBParam+ 318))
#define	usDBpPWMOut3FrqOrDutyMin        (*(aDBParam+ 319))
#define	usDBpPWMOut3FrqOrDutyMax        (*(aDBParam+ 320))
#define	usDBpPWMOut3Period              (*(aDBParam+ 321))
#define	usDBpPWMOut4Assign              (*(aDBParam+ 322))
#define	usDBpPWMOut4RefLow              (*(aDBParam+ 323))
#define	usDBpPWMOut4RefHigh             (*(aDBParam+ 324))
#define	usDBpPWMOut4FrqOrDutyMin        (*(aDBParam+ 325))
#define	usDBpPWMOut4FrqOrDutyMax        (*(aDBParam+ 326))
#define	usDBpPWMOut4Period              (*(aDBParam+ 327))

/* ****************** Part 15: Status, (328 - 329) ******************** */
#define	usDBpLevel	                    (*(aDBParam+ 328))
#define	usDBpOperationMode	            (*(aDBParam+ 329))

/* **************** Part 16: Generator, (330 - 333) ******************* */
#define	usDBpSynchronFactor	            (*(aDBParam+ 330))
#define	usDBpSynchronReference	        (*(aDBParam+ 331))
#define	usDBpLoadControlFactor	        (*(aDBParam+ 332))
#define	usDBpLoadControlReference       (*(aDBParam+ 333))

/* ***************** Part 17: Vehicle, (334 - 386) ******************** */
#define	usDBpVSSensorRatio              (*(aDBParam+ 334))
#define	usDBpVSpeedMaxAbsolut           (*(aDBParam+ 335))
#define	usDBpVSpeedMinCruise            (*(aDBParam+ 336))
#define	usDBpVSpeedMaxCruise            (*(aDBParam+ 337))
#define	usDBpVSpeedMaxPTO               (*(aDBParam+ 338))
#define	usDBpVSpeedMaxFaultHome         (*(aDBParam+ 339))
#define	usDBpEBrakeDeltaMax             (*(aDBParam+ 340))
#define	usDBpEBrakeDeltaMin             (*(aDBParam+ 341))
#define	usDBpEBrakeDelay                (*(aDBParam+ 342))
#define	usDBpEBrakeVSpeedMin            (*(aDBParam+ 343))
#define	usDBpEBrakeESpeedMin            (*(aDBParam+ 344))
#define	usDBpEBrakeBPressMax            (*(aDBParam+ 345))
#define	usDBpPTOSpeedSet                (*(aDBParam+ 346))
#define	usDBpPTOSpeedReset              (*(aDBParam+ 347))
#define	usDBpPTOSpeedAdd                (*(aDBParam+ 348))
#define	usDBpRPTOSpeedNum               (*(aDBParam+ 349))
#define	aDBpRPTOSpeedSetp                 (aDBParam+ 350)
#define	usDBpRPTOSpeedSetp1             (*(aDBParam+ 350))
#define	usDBpRPTOSpeedSetp2             (*(aDBParam+ 351))
#define	usDBpRPTOSpeedSetp3             (*(aDBParam+ 352))
#define	usDBpRPTOSpeedSetp4             (*(aDBParam+ 353))
#define	usDBpRPTOSpeedSetp5             (*(aDBParam+ 354))
#define	usDBpRPTOSpeedSetp6             (*(aDBParam+ 355))
#define	usDBpSpeedMinCruise             (*(aDBParam+ 356))
#define	usDBpSpeedMaxVSSZero            (*(aDBParam+ 357))
#define	usDBpSpeedMaxFaultHome          (*(aDBParam+ 358))
#define	usDBpSpeedDecVSOverLow          (*(aDBParam+ 359))
#define	usDBpSpeedDecVSOverHigh         (*(aDBParam+ 360))
#define	usDBpSpeedDecByVSOver           (*(aDBParam+ 361))
#define	usDBpSpeedIdleIncByAC           (*(aDBParam+ 362))
#define	usDBpIMModeRampUp               (*(aDBParam+ 363))
#define	usDBpIMModeRampDown             (*(aDBParam+ 364))
#define	usDBpFan1RefAssign              (*(aDBParam+ 365))
#define	usDBpFan1ActiveTemp             (*(aDBParam+ 366))
#define	usDBpFan1ActiveDelay            (*(aDBParam+ 367))
#define	usDBpFan2RefAssign              (*(aDBParam+ 368))
#define	usDBpFan2ActiveTemp             (*(aDBParam+ 369))
#define	usDBpFan2ActiveDelay            (*(aDBParam+ 370))
#define	usDBpAirHeaterTempCold          (*(aDBParam+ 371))
#define	usDBpAirHeaterTempWarm          (*(aDBParam+ 372))
#define	usDBpAirHeaterTimeAtCold        (*(aDBParam+ 373))
#define	usDBpAirHeaterTimeAtWarm        (*(aDBParam+ 374))
#define	usDBpAirHeaterCorrPressLow      (*(aDBParam+ 375))
#define	usDBpAirHeaterCorrPressHigh     (*(aDBParam+ 376))
#define	usDBpAirHeaterCorrAtPressLow    (*(aDBParam+ 377))
#define	usDBpAirHeaterCorrAtPressHigh   (*(aDBParam+ 378))
#define	usDBpAirHeaterCorrVoltLow       (*(aDBParam+ 379))
#define	usDBpAirHeaterCorrVoltHigh      (*(aDBParam+ 380))
#define	usDBpAirHeaterCorrAtVoltLow     (*(aDBParam+ 381))
#define	usDBpAirHeaterCorrAtVoltHigh    (*(aDBParam+ 382))
#define	usDBpOilPumpOnTimeMax           (*(aDBParam+ 383))
#define	usDBpOilPressMinAtStart         (*(aDBParam+ 384))
#define	usDBpStarterOnTime              (*(aDBParam+ 385))
#define	usDBpStarterOffTime             (*(aDBParam+ 386))

/* ***************** Part 18: Injection, (387 - 405) ****************** */
#define usDBpPilotInjectBeginSetp       (*(aDBParam+ 387))
#define usDBpPilotInjectTimeSetp        (*(aDBParam+ 388))
#define usDBpPreInjectBeginSetp         (*(aDBParam+ 389))
#define usDBpPreInjectTimeSetp          (*(aDBParam+ 390))
#define usDBpMainInjectPeriodSetp       (*(aDBParam+ 391))
#define usDBpMainInjectTimeSetp         (*(aDBParam+ 392))
#define usDBpMainInjectBeginSetp        (*(aDBParam+ 393))
#define usDBpMainBeginCorrTempCold      (*(aDBParam+ 394))
#define usDBpMainBeginCorrTempWarm      (*(aDBParam+ 395))
#define usDBpMainBeginCorrAtCold        (*(aDBParam+ 396))
#define usDBpMainBeginCorrAtWarm        (*(aDBParam+ 397))
#define usDBpMainBeginCorrAmbLow        (*(aDBParam+ 398))
#define usDBpMainBeginCorrAmbHigh       (*(aDBParam+ 399))
#define usDBpMainBeginCorrAtAmbLow      (*(aDBParam+ 400))
#define usDBpMainBeginCorrAmbDelay      (*(aDBParam+ 401))
#define usDBpPostInjectBeginSetp        (*(aDBParam+ 402))
#define usDBpPostInjectTimeSetp         (*(aDBParam+ 403))
#define usDBpLastInjectBeginSetp        (*(aDBParam+ 404))
#define usDBpLastInjectTimeSetp         (*(aDBParam+ 405))

/* **************** Part 19: Common Rail (406 - 411) ****************** */
#define usDBpCRPumpGain                 (*(aDBParam+ 406))
#define usDBpCRPumpStability            (*(aDBParam+ 407))
#define usDBpCRPumpDerivative           (*(aDBParam+ 408))
#define usDBpCRPumpControlTest          (*(aDBParam+ 409))
#define usDBpCRPressSetp                (*(aDBParam+ 410))
#define usDBpCRPressMinAtStart          (*(aDBParam+ 411))

/* ****************** Part 20: Others, (412 - 459) ******************** */
#define	usDBpParamBackup0               (*(aDBParam+ 412))
#define	usDBpParamBackup1               (*(aDBParam+ 413))
#define	usDBpParamBackup2               (*(aDBParam+ 414))
#define	usDBpParamBackup3               (*(aDBParam+ 415))
#define	usDBpParamBackup4               (*(aDBParam+ 416))
#define	usDBpParamBackup5               (*(aDBParam+ 417))
#define	usDBpParamBackup6               (*(aDBParam+ 418))
#define	usDBpParamBackup7               (*(aDBParam+ 419))
#define	usDBpParamBackup8               (*(aDBParam+ 420))
#define	usDBpParamBackup9               (*(aDBParam+ 421))
#define	usDBpParamBackup10              (*(aDBParam+ 422))
#define	usDBpParamBackup11              (*(aDBParam+ 423))
#define	usDBpParamBackup12              (*(aDBParam+ 424))
#define	usDBpParamBackup13              (*(aDBParam+ 425))
#define	usDBpParamBackup14              (*(aDBParam+ 426))
#define	usDBpParamBackup15              (*(aDBParam+ 427))
#define	usDBpParamBackup16              (*(aDBParam+ 428))
#define	usDBpParamBackup17              (*(aDBParam+ 429))
#define	usDBpParamBackup18              (*(aDBParam+ 430))
#define	usDBpParamBackup19              (*(aDBParam+ 431))
#define	usDBpParamBackup20              (*(aDBParam+ 432))
#define	usDBpParamBackup21              (*(aDBParam+ 433))
#define	usDBpParamBackup22              (*(aDBParam+ 434))
#define	usDBpParamBackup23              (*(aDBParam+ 435))
#define	usDBpParamBackup24              (*(aDBParam+ 436))
#define	usDBpParamBackup25              (*(aDBParam+ 437))
#define	usDBpParamBackup26              (*(aDBParam+ 438))
#define	usDBpParamBackup27              (*(aDBParam+ 439))
#define	usDBpParamBackup28              (*(aDBParam+ 440))
#define	usDBpParamBackup29              (*(aDBParam+ 441))
#define	usDBpParamBackup30              (*(aDBParam+ 442))
#define	usDBpParamBackup31              (*(aDBParam+ 443))
#define	usDBpParamBackup32              (*(aDBParam+ 444))
#define	usDBpParamBackup33              (*(aDBParam+ 445))
#define	usDBpParamBackup34              (*(aDBParam+ 446))
#define	usDBpParamBackup35              (*(aDBParam+ 447))
#define	usDBpParamBackup36              (*(aDBParam+ 448))
#define	usDBpParamBackup37              (*(aDBParam+ 449))
#define	usDBpParamBackup38              (*(aDBParam+ 450))
#define	usDBpParamBackup39              (*(aDBParam+ 451))
#define	usDBpParamBackup40              (*(aDBParam+ 452))
#define	usDBpParamBackup41              (*(aDBParam+ 453))
#define	usDBpParamBackup42              (*(aDBParam+ 454))
#define	usDBpParamBackup43              (*(aDBParam+ 455))
#define	usDBpParamBackup44              (*(aDBParam+ 456))
#define	usDBpParamBackup45              (*(aDBParam+ 457))
#define	usDBpParamBackup46              (*(aDBParam+ 458))
#define	usDBpParamBackup47              (*(aDBParam+ 459))

#endif
/* ******************************************************************** */
/*                   VEC8000 Measurement Definition                     */
/* ******************************************************************** */
#if    (DB_ENGINE_EFI_ON == 1)
/* ****************** Part 1: Speed Pickup (0 - 29) ******************* */
#define usDBmSpeed                      (*(aDBMeasu+   0))
#define usDBmSpeedCrank1                (*(aDBMeasu+   1))
#define usDBmSpeedCrank2                (*(aDBMeasu+   2))
#define usDBmSpeedCam                   (*(aDBMeasu+   3))
#define usDBmPickupActive               (*(aDBMeasu+   4))
#define usDBmSpeedGradient              (*(aDBMeasu+   5))
#define usDBmSpeedDelta                 (*(aDBMeasu+   6))
#define usDBmSpeedSetp                  (*(aDBMeasu+   7))
#define usDBmSpeedSetpRamp              (*(aDBMeasu+   8))
#define usDBmSpeedSetpSelect            (*(aDBMeasu+   9))
#define usDBmSpeedIdleActive            (*(aDBMeasu+  10))
#define usDBmSpeedMaxActive             (*(aDBMeasu+  11))
#define usDBmIdleSetpOffset             (*(aDBMeasu+  12))
#define usDBmDroopOffset                (*(aDBMeasu+  13))
#define usDBmDigitPotOffset             (*(aDBMeasu+  14))
#define usDBmGeneSetpOffset             (*(aDBMeasu+  15))
#define usDBmSpeedDeltaAve              (*(aDBMeasu+  16))
#define usDBmAngleClockState            (*(aDBMeasu+  17))
#define usDBmSynchronToGap              (*(aDBMeasu+  18))
#define usDBmGapToCamIndex              (*(aDBMeasu+  19))
#define aDBmInstSpeed                     (aDBMeasu+  20)
#define usDBmInstSpeed1                 (*(aDBMeasu+  20))
#define usDBmInstSpeed2                 (*(aDBMeasu+  21))
#define usDBmInstSpeed3                 (*(aDBMeasu+  22))
#define usDBmInstSpeed4                 (*(aDBMeasu+  23))
#define usDBmInstSpeed5                 (*(aDBMeasu+  24))
#define usDBmInstSpeed6                 (*(aDBMeasu+  25))
#define usDBmInstSpeed7                 (*(aDBMeasu+  26))
#define usDBmInstSpeed8                 (*(aDBMeasu+  27))
#define usDBmInstSpeed9                 (*(aDBMeasu+  28))
#define usDBmInstSpeed10                (*(aDBMeasu+  29))

/* **************** Part 2: Stability/Droop (30 - 36) ***************** */
#define usDBmPIDGainCorr                (*(aDBMeasu+  30))
#define usDBmPIDStabCorr                (*(aDBMeasu+  31))
#define usDBmPIDDeriCorr                (*(aDBMeasu+  32))
#define usDBmFuelGovernor               (*(aDBMeasu+  33))
#define usDBmFuelInjection              (*(aDBMeasu+  34))
#define usDBmFuelAverage                (*(aDBMeasu+  35))
#define usDBmFuelTempCorrFactor         (*(aDBMeasu+  36))

/* **************** Part 3: Solenoid Valves, (37 - 69) **************** */
#define aDBmMainTime                      (aDBMeasu+  37)  /* CR */
#define usDBmMainTime1                  (*(aDBMeasu+  37)) /* CR */
#define usDBmMainTime2                  (*(aDBMeasu+  38)) /* CR */
#define usDBmMainTime3                  (*(aDBMeasu+  39)) /* CR */
#define usDBmMainTime4                  (*(aDBMeasu+  40)) /* CR */
#define usDBmMainTime5                  (*(aDBMeasu+  41)) /* CR */
#define usDBmMainTime6                  (*(aDBMeasu+  42)) /* CR */
#define usDBmMainTime7                  (*(aDBMeasu+  43)) /* CR */
#define usDBmMainTime8                  (*(aDBMeasu+  44)) /* CR */
#define usDBmMainTime9                  (*(aDBMeasu+  45)) /* CR */
#define usDBmMainTime10                 (*(aDBMeasu+  46)) /* CR */
#define aDBmMainPeriod                    (aDBMeasu+  37)
#define usDBmMainPeriod1                (*(aDBMeasu+  37))
#define usDBmMainPeriod2                (*(aDBMeasu+  38))
#define usDBmMainPeriod3                (*(aDBMeasu+  39))
#define usDBmMainPeriod4                (*(aDBMeasu+  40))
#define usDBmMainPeriod5                (*(aDBMeasu+  41))
#define usDBmMainPeriod6                (*(aDBMeasu+  42))
#define usDBmMainPeriod7                (*(aDBMeasu+  43))
#define usDBmMainPeriod8                (*(aDBMeasu+  44))
#define usDBmMainPeriod9                (*(aDBMeasu+  45))
#define usDBmMainPeriod10               (*(aDBMeasu+  46))
#define aDBmMainBegin                     (aDBMeasu+  47)
#define usDBmMainBegin1                 (*(aDBMeasu+  47))
#define usDBmMainBegin2                 (*(aDBMeasu+  48))
#define usDBmMainBegin3                 (*(aDBMeasu+  49))
#define usDBmMainBegin4                 (*(aDBMeasu+  50))
#define usDBmMainBegin5                 (*(aDBMeasu+  51))
#define usDBmMainBegin6                 (*(aDBMeasu+  52))
#define usDBmMainBegin7                 (*(aDBMeasu+  53))
#define usDBmMainBegin8                 (*(aDBMeasu+  54))
#define usDBmMainBegin9                 (*(aDBMeasu+  55))
#define usDBmMainBegin10                (*(aDBMeasu+  56))
#define aDBmSolErrStatus                  (aDBMeasu+  57)
#define usDBmSolErrStatus1              (*(aDBMeasu+  57))
#define usDBmSolErrStatus2              (*(aDBMeasu+  58))
#define usDBmSolErrStatus3              (*(aDBMeasu+  59))
#define usDBmSolErrStatus4              (*(aDBMeasu+  60))
#define usDBmSolErrStatus5              (*(aDBMeasu+  61))
#define usDBmSolErrStatus6              (*(aDBMeasu+  62))
#define usDBmSolErrStatus7              (*(aDBMeasu+  63))
#define usDBmSolErrStatus8              (*(aDBMeasu+  64))
#define usDBmSolErrStatus9              (*(aDBMeasu+  65))
#define usDBmSolErrStatus10             (*(aDBMeasu+  66))
#define usDBmSolDelayTime               (*(aDBMeasu+  67))
#define usDBmSolDelayVoltCorr           (*(aDBMeasu+  68))
#define usDBmSolActiveMask              (*(aDBMeasu+  69))

/* ***************** Part 4: Begin Control (70 - 71) ****************** */
#define	usDBmBeginSetpoint              (*(aDBMeasu+  70))
#define	usDBmBeginControl               (*(aDBMeasu+  71))

/* ****************** Part 5: EGR Control (72 - 73) ******************* */
#define	usDBmEgrSetpoint                (*(aDBMeasu+  72))
#define	usDBmEgrControl                 (*(aDBMeasu+  73))

/* ******************** Part 6: Can Bus (74 - 78) ********************* */
#define	usDBmCanState                   (*(aDBMeasu+  74))
#define	usDBmCanSetpoint1               (*(aDBMeasu+  75))
#define	usDBmCanSetpoint2               (*(aDBMeasu+  76))
#define	usDBmCanSetpoint3               (*(aDBMeasu+  77))
#define	usDBmCanBinaryIn                (*(aDBMeasu+  78))

/* ****************** Part 7: Limitations (79 - 92) ******************* */
#define	usDBmFuelLimitMin               (*(aDBMeasu+  79))
#define	usDBmFuelLimitMax               (*(aDBMeasu+  80))
#define	usDBmFuelLimitStart             (*(aDBMeasu+  81))
#define	usDBmFuelLimitSpeed             (*(aDBMeasu+  82))
#define	usDBmFuelLimitBoost             (*(aDBMeasu+  83))
#define	usDBmFuelLimitAmbient           (*(aDBMeasu+  84))
#define	usDBmFuelLimitForced            (*(aDBMeasu+  85))
#define	usDBmFuelLimitMinActive         (*(aDBMeasu+  86))
#define	usDBmFuelLimitMaxActive         (*(aDBMeasu+  87))
#define	usDBmStartLimitActive           (*(aDBMeasu+  88))
#define	usDBmSpeedLimitActive           (*(aDBMeasu+  89))
#define	usDBmBoostLimitActive           (*(aDBMeasu+  90))
#define	usDBmAmbientLimitActive         (*(aDBMeasu+  91))
#define	usDBmForcedLimitActive          (*(aDBMeasu+  92))

/* ************** Part 8: Digital In/Outputs (93 - 132) *************** */
#define	usDBmSwitchEngineStop           (*(aDBMeasu+  93))
#define	usDBmSwitchIdleSpeed            (*(aDBMeasu+  94))
#define	usDBmSwitchSpeedFix1            (*(aDBMeasu+  95))
#define	usDBmSwitchSpeedFix2            (*(aDBMeasu+  96))
#define	usDBmSwitchSpeedInc             (*(aDBMeasu+  97))
#define	usDBmSwitchSpeedDec             (*(aDBMeasu+  98))
#define	usDBmSwitchDroop2Or1            (*(aDBMeasu+  99))
#define	usDBmSwitchDroop3Or2            (*(aDBMeasu+ 100))
#define	usDBmSwitchSpeedRange2Or1       (*(aDBMeasu+ 101))
#define	usDBmSwitchSpeedRange3Or2       (*(aDBMeasu+ 102))
#define	usDBmSwitchSpeedLimit2Or1       (*(aDBMeasu+ 103))
#define	usDBmSwitchSpeedLimit3Or2       (*(aDBMeasu+ 104))
#define	usDBmSwitchOilPump              (*(aDBMeasu+ 105))
#define	usDBmSwitchAirHeater            (*(aDBMeasu+ 106))
#define	usDBmSwitchEngineStart          (*(aDBMeasu+ 107))
#define	usDBmSwitchSetpoint2Or1         (*(aDBMeasu+ 108))
#define	usDBmSwitchForcedLimit          (*(aDBMeasu+ 109))
#define	usDBmSwitchSyncEnable           (*(aDBMeasu+ 110))
#define	usDBmSwitchLoadEnable           (*(aDBMeasu+ 111))
#define	usDBmSwitchAutoOrManual         (*(aDBMeasu+ 112))
#define	usDBmSwitchErrorReset           (*(aDBMeasu+ 113))
#define	usDBmSwitchPTO                  (*(aDBMeasu+ 114))
#define	usDBmSwitchRPTO                 (*(aDBMeasu+ 115))
#define	usDBmSwitchPTOCCSet             (*(aDBMeasu+ 116))
#define	usDBmSwitchPTOCCReset           (*(aDBMeasu+ 117))
#define	usDBmSwitchPTOAdd               (*(aDBMeasu+ 118))
#define	usDBmSwitchMainBrake            (*(aDBMeasu+ 119))
#define	usDBmSwitchClutch               (*(aDBMeasu+ 120))
#define	usDBmSwitchDiagnostic           (*(aDBMeasu+ 121))
#define	usDBmSwitchIMOrAllSpeed         (*(aDBMeasu+ 122))
#define	usDBmSwitchCruiseControl        (*(aDBMeasu+ 123))
#define	usDBmSwitchAirConditioner       (*(aDBMeasu+ 124))
#define	usDBmDigitalOut1                (*(aDBMeasu+ 125))
#define	usDBmDigitalOut2                (*(aDBMeasu+ 126))
#define	usDBmDigitalOut3                (*(aDBMeasu+ 127))
#define	usDBmDigitalOut4                (*(aDBMeasu+ 128))
#define	usDBmDigitalOut5                (*(aDBMeasu+ 129))
#define	usDBmDigitalOut6                (*(aDBMeasu+ 130))
#define	usDBmDigitalOut7                (*(aDBMeasu+ 131))
#define	usDBmDigitalOut8                (*(aDBMeasu+ 132))

/* **************** Part 9: Sensors Inputs (133 - 151) **************** */
#define	usDBmSetp1Extern                (*(aDBMeasu+ 133))
#define	usDBmSetp1ExtSub                (*(aDBMeasu+ 134))
#define	usDBmSetp2Extern                (*(aDBMeasu+ 135))
#define usDBmBoostPressure              (*(aDBMeasu+ 136))
#define usDBmOilPressure                (*(aDBMeasu+ 137))
#define usDBmAmbientPressure            (*(aDBMeasu+ 138))
#define usDBmCoolantTemp                (*(aDBMeasu+ 139))
#define usDBmBoostTemp                  (*(aDBMeasu+ 140))
#define usDBmOilTemp                    (*(aDBMeasu+ 141))
#define usDBmFuelTemp                   (*(aDBMeasu+ 142))
#define usDBmExhaustTemp                (*(aDBMeasu+ 143))
#define	usDBmLoadInput                  (*(aDBMeasu+ 144))
#define usDBmSyncInput                  (*(aDBMeasu+ 145))
#define usDBmEgrInput                   (*(aDBMeasu+ 146))
#define usDBmBeginInput                 (*(aDBMeasu+ 147))
#define usDBmRailPressure1              (*(aDBMeasu+ 148))
#define usDBmRailPressure2              (*(aDBMeasu+ 149))
#define usDBmCurrent1                   (*(aDBMeasu+ 150))
#define usDBmCurrent2                   (*(aDBMeasu+ 151))

/* *************** Part 10: Inputs Status (152 - 193) ***************** */
#define aDBmAnalogIn                      (aDBMeasu+ 152)
#define usDBmAnalogIn00                 (*(aDBMeasu+ 152))
#define usDBmAnalogIn01                 (*(aDBMeasu+ 153))
#define usDBmAnalogIn02                 (*(aDBMeasu+ 154))
#define usDBmAnalogIn03                 (*(aDBMeasu+ 155))
#define usDBmAnalogIn04                 (*(aDBMeasu+ 156))
#define usDBmAnalogIn05                 (*(aDBMeasu+ 157))
#define usDBmAnalogIn06                 (*(aDBMeasu+ 158))
#define usDBmAnalogIn07                 (*(aDBMeasu+ 159))
#define usDBmAnalogIn08                 (*(aDBMeasu+ 160))
#define usDBmAnalogIn09                 (*(aDBMeasu+ 161))
#define usDBmAnalogIn10                 (*(aDBMeasu+ 162))
#define usDBmAnalogIn11                 (*(aDBMeasu+ 163))
#define usDBmAnalogIn12                 (*(aDBMeasu+ 164))
#define usDBmAnalogIn13                 (*(aDBMeasu+ 165))
#define usDBmAnalogIn14                 (*(aDBMeasu+ 166))
#define usDBmAnalogIn15                 (*(aDBMeasu+ 167))
#define usDBmAnalogIn16                 (*(aDBMeasu+ 168))
#define usDBmAnalogIn17                 (*(aDBMeasu+ 169))
#define usDBmAnalogIn18                 (*(aDBMeasu+ 170))
#define usDBmAnalogIn19                 (*(aDBMeasu+ 171))
#define usDBmAnalogIn20                 (*(aDBMeasu+ 172))
#define usDBmAnalogIn21                 (*(aDBMeasu+ 173))
#define usDBmAnalogIn22                 (*(aDBMeasu+ 174))
#define usDBmAnalogIn23                 (*(aDBMeasu+ 175))
#define usDBmAnalogIn24                 (*(aDBMeasu+ 176))
#define usDBmAnalogIn25                 (*(aDBMeasu+ 177))
#define usDBmAnalogIn26                 (*(aDBMeasu+ 178))
#define usDBmAnalogIn27                 (*(aDBMeasu+ 179))
#define usDBmAnalogIn28                 (*(aDBMeasu+ 180))
#define usDBmAnalogIn29                 (*(aDBMeasu+ 181))
#define usDBmPowerSupply                (*(aDBMeasu+ 182))
#define usDBmTempIntern                 (*(aDBMeasu+ 183))
#define	usDBmBoostPressAt25C            (*(aDBMeasu+ 184))
#define usDBmPower60V                   (*(aDBMeasu+ 185))
#define usDBmPower12V                   (*(aDBMeasu+ 186))
#define usDBmPower5V                    (*(aDBMeasu+ 187))
#define usDBmPower3D3V                  (*(aDBMeasu+ 188))
#define usDBmPower1D2V                  (*(aDBMeasu+ 189))
#define usDBmPowerOut5V1                (*(aDBMeasu+ 190))
#define usDBmPowerOut5V2                (*(aDBMeasu+ 191))
#define usDBmTempCPU                    (*(aDBMeasu+ 192))
#define usDBmBinaryIn                   (*(aDBMeasu+ 193))

/* **************** Part 11: Engine Status (194 - 206) **************** */
#define usDBmPhase                      (*(aDBMeasu+ 194))
#define usDBmEngineTimer                (*(aDBMeasu+ 195))
#define usDBmCommonAlarm                (*(aDBMeasu+ 196))
#define usDBmEngineStopEcy              (*(aDBMeasu+ 197))
#define usDBmEngineStopping             (*(aDBMeasu+ 198))
#define usDBmEngineStopped              (*(aDBMeasu+ 199))
#define usDBmEngineStarting             (*(aDBMeasu+ 200))
#define usDBmEngineRunning              (*(aDBMeasu+ 201))
#define usDBmEngineReleased             (*(aDBMeasu+ 202))
#define usDBmCalculationTime            (*(aDBMeasu+ 203))
#define usDBmHardwareVersion            (*(aDBMeasu+ 204))
#define usDBmSoftwareVersion            (*(aDBMeasu+ 205))
#define usDBmCPUTimeUsage               (*(aDBMeasu+ 206))

/* ******************* Part 12: Vehicle (207 - 224) ******************* */
#define	usDBmVeSpeed                    (*(aDBMeasu+ 207))
#define	usDBmEBrakeActive               (*(aDBMeasu+ 208))
#define usDBmDiagnosActive              (*(aDBMeasu+ 209))
#define usDBmFaultHomeActive            (*(aDBMeasu+ 210))
#define	usDBmAirHeaterActive            (*(aDBMeasu+ 211))
#define usDBmIMGovernorActive           (*(aDBMeasu+ 212))
#define	usDBmPTOSetpSelect              (*(aDBMeasu+ 213))
#define usDBmCCSetpSelect               (*(aDBMeasu+ 214))
#define usDBmPTOSetpOffset              (*(aDBMeasu+ 215))
#define usDBmCCSetpOffset               (*(aDBMeasu+ 216))
#define	usDBmFan1Active                 (*(aDBMeasu+ 217))
#define	usDBmFan2Active                 (*(aDBMeasu+ 218))
#define	usDBmAirHeaterDuration          (*(aDBMeasu+ 219))
#define	usDBmFaultCodeBlink             (*(aDBMeasu+ 220))
#define	usDBmOilPumpActive              (*(aDBMeasu+ 221))
#define	usDBmStarterActive              (*(aDBMeasu+ 222))
#define	usDBmWarnLampActive             (*(aDBMeasu+ 223))
#define	usDBmStopLampActive             (*(aDBMeasu+ 224))

/* ****************** Part 13: Injection (225 - 249) ****************** */
#define usDBmPilotInjectPeriod          (*(aDBMeasu+ 225))
#define usDBmPilotInjectTime            (*(aDBMeasu+ 226))
#define usDBmPilotInjectBegin           (*(aDBMeasu+ 227))
#define usDBmPilotInjectActive          (*(aDBMeasu+ 228))
#define usDBmPreInjectPeriod            (*(aDBMeasu+ 229))
#define usDBmPreInjectTime              (*(aDBMeasu+ 230))
#define usDBmPreInjectBegin             (*(aDBMeasu+ 231))
#define usDBmPreInjectActive            (*(aDBMeasu+ 232))
#define usDBmMainInjectFuel             (*(aDBMeasu+ 233))
#define usDBmMainInjectPeriod           (*(aDBMeasu+ 234))
#define usDBmMainInjectTime             (*(aDBMeasu+ 235))
#define usDBmMainInjectBegin            (*(aDBMeasu+ 236))
#define usDBmMainPeriodCylCorr          (*(aDBMeasu+ 237))
#define usDBmMainTimeCylCorr            (*(aDBMeasu+ 237)) /* CR */
#define usDBmMainBeginCylCorr           (*(aDBMeasu+ 238))
#define usDBmMainBeginTempCorr          (*(aDBMeasu+ 239))
#define usDBmMainBeginAmbiCorr          (*(aDBMeasu+ 240))
#define usDBmMainInjectCount            (*(aDBMeasu+ 241))
#define usDBmPostInjectPeriod           (*(aDBMeasu+ 242))
#define usDBmPostInjectTime             (*(aDBMeasu+ 243))
#define usDBmPostInjectBegin            (*(aDBMeasu+ 244))
#define usDBmPostInjectActive           (*(aDBMeasu+ 245))
#define usDBmLastInjectPeriod           (*(aDBMeasu+ 246))
#define usDBmLastInjectTime             (*(aDBMeasu+ 247))
#define usDBmLastInjectBegin            (*(aDBMeasu+ 248))
#define usDBmLastInjectActive           (*(aDBMeasu+ 249))

/* ***************** Part 14: Common Rail (250 - 252) ***************** */
#define usDBmCRPumpControl              (*(aDBMeasu+ 250))
#define usDBmRailPressSetp              (*(aDBMeasu+ 251))
#define usDBmRailPressSetpSelect        (*(aDBMeasu+ 252))

/* ******************* Part 15: Ohters (253 - 295) ******************** */
#define	usDBmMeasuBackup0               (*(aDBMeasu+ 253))
#define	usDBmMeasuBackup1               (*(aDBMeasu+ 254))
#define	usDBmMeasuBackup2               (*(aDBMeasu+ 255))
#define	usDBmMeasuBackup3               (*(aDBMeasu+ 256))
#define	usDBmMeasuBackup4               (*(aDBMeasu+ 257))
#define	usDBmMeasuBackup5               (*(aDBMeasu+ 258))
#define	usDBmMeasuBackup6               (*(aDBMeasu+ 259))
#define	usDBmMeasuBackup7               (*(aDBMeasu+ 260))
#define	usDBmMeasuBackup8               (*(aDBMeasu+ 261))
#define	usDBmMeasuBackup9               (*(aDBMeasu+ 262))
#define	usDBmMeasuBackup10              (*(aDBMeasu+ 263))
#define	usDBmMeasuBackup11              (*(aDBMeasu+ 264))
#define	usDBmMeasuBackup12              (*(aDBMeasu+ 265))
#define	usDBmMeasuBackup13              (*(aDBMeasu+ 266))
#define	usDBmMeasuBackup14              (*(aDBMeasu+ 267))
#define	usDBmMeasuBackup15              (*(aDBMeasu+ 268))
#define	usDBmMeasuBackup16              (*(aDBMeasu+ 269))
#define	usDBmMeasuBackup17              (*(aDBMeasu+ 270))
#define	usDBmMeasuBackup18              (*(aDBMeasu+ 271))
#define	usDBmMeasuBackup19              (*(aDBMeasu+ 272))
#define	usDBmMeasuBackup20              (*(aDBMeasu+ 273))
#define	usDBmMeasuBackup21              (*(aDBMeasu+ 274))
#define	usDBmMeasuBackup22              (*(aDBMeasu+ 275))
#define	usDBmMeasuBackup23              (*(aDBMeasu+ 276))
#define	usDBmMeasuBackup24              (*(aDBMeasu+ 277))
#define	usDBmMeasuBackup25              (*(aDBMeasu+ 278))
#define	usDBmMeasuBackup26              (*(aDBMeasu+ 279))
#define	usDBmMeasuBackup27              (*(aDBMeasu+ 280))
#define	usDBmMeasuBackup28              (*(aDBMeasu+ 281))
#define	usDBmMeasuBackup29              (*(aDBMeasu+ 282))
#define	usDBmMeasuBackup30              (*(aDBMeasu+ 283))
#define	usDBmMeasuBackup31              (*(aDBMeasu+ 284))
#define	usDBmMeasuBackup32              (*(aDBMeasu+ 285))
#define	usDBmMeasuBackup33              (*(aDBMeasu+ 286))
#define	usDBmMeasuBackup34              (*(aDBMeasu+ 287))
#define	usDBmMeasuBackup35              (*(aDBMeasu+ 288))
#define	usDBmMeasuBackup36              (*(aDBMeasu+ 289))
#define	usDBmMeasuBackup37              (*(aDBMeasu+ 290))
#define	usDBmMeasuBackup38              (*(aDBMeasu+ 291))
#define	usDBmMeasuBackup39              (*(aDBMeasu+ 292))
#define	usDBmMeasuBackup40              (*(aDBMeasu+ 293))
#define	usDBmMeasuBackup41              (*(aDBMeasu+ 294))
#define	usDBmMeasuDataSum               (*(aDBMeasu+ 295))

/* *************** Part 16: Actual Errors, (296 - 375) **************** */
#define aDBmErrBegin                      (aDBMeasu+ 296)
#define usDBmErrCrankSensor1            (*(aDBMeasu+ 296))
#define usDBmErrCrankSensor2            (*(aDBMeasu+ 297))
#define usDBmErrCamSensor               (*(aDBMeasu+ 298))
#define usDBmErrVSSensor                (*(aDBMeasu+ 299))
#define usDBmErrSetp1Extern             (*(aDBMeasu+ 300))
#define usDBmErrSetp1ExtSub             (*(aDBMeasu+ 301))
#define usDBmErrSetp2Extern             (*(aDBMeasu+ 302))
#define usDBmErrBoostPressure           (*(aDBMeasu+ 303))
#define usDBmErrOilPressure             (*(aDBMeasu+ 304))
#define usDBmErrAmbientPressure         (*(aDBMeasu+ 305))
#define usDBmErrCoolantTemp             (*(aDBMeasu+ 306))
#define usDBmErrBoostTemp               (*(aDBMeasu+ 307))
#define usDBmErrOilTemp                 (*(aDBMeasu+ 308))
#define usDBmErrFuelTemp                (*(aDBMeasu+ 309))
#define usDBmErrExhaustTemp             (*(aDBMeasu+ 310))
#define usDBmErrLoadInput               (*(aDBMeasu+ 311))
#define usDBmErrSyncInput               (*(aDBMeasu+ 312))
#define usDBmErrEgrInput                (*(aDBMeasu+ 313))
#define usDBmErrBeginInput              (*(aDBMeasu+ 314))
#define usDBmErrRailPressure1           (*(aDBMeasu+ 315))
#define usDBmErrRailPressure2           (*(aDBMeasu+ 316))
#define usDBmErrCurrent1                (*(aDBMeasu+ 317))
#define usDBmErrCurrent2                (*(aDBMeasu+ 318))
#define usDBmErrCylinderFault           (*(aDBMeasu+ 319))
#define usDBmErrEgrActuator             (*(aDBMeasu+ 320))
#define usDBmErrBeginActuator           (*(aDBMeasu+ 321))
#define usDBmErrOilPressWarn            (*(aDBMeasu+ 322))
#define usDBmErrOilPressEcy             (*(aDBMeasu+ 323))
#define usDBmErrCoolantTempWarn         (*(aDBMeasu+ 324))
#define usDBmErrBoostTempWarn           (*(aDBMeasu+ 325))
#define usDBmErrOilTempWarn             (*(aDBMeasu+ 326))
#define usDBmErrTempIntern              (*(aDBMeasu+ 327))
#define usDBmErrVoltage                 (*(aDBMeasu+ 328))
#define usDBmErrOverSpeed               (*(aDBMeasu+ 329))
#define usDBmErrCAN                     (*(aDBMeasu+ 330))
#define usDBmErr5VOut                   (*(aDBMeasu+ 331))
#define usDBmErrADC                     (*(aDBMeasu+ 332))
#define usDBmErrStack                   (*(aDBMeasu+ 333))
#define usDBmErrLogical                 (*(aDBMeasu+ 334))
#define usDBmErrCalcTime                (*(aDBMeasu+ 335))
#define usDBmErrDataCheck               (*(aDBMeasu+ 336))
#define usDBmErrClearFlash              (*(aDBMeasu+ 337))
#define usDBmErrParamStore              (*(aDBMeasu+ 338))
#define usDBmErrPogramTest              (*(aDBMeasu+ 339))
#define usDBmErrRamTest                 (*(aDBMeasu+ 340))
#define usDBmErrIntern                  (*(aDBMeasu+ 341))
#define usDBmErrSpeedDelta              (*(aDBMeasu+ 342))
#define usDBmErrEngineStart             (*(aDBMeasu+ 343))
#define usDBmErrPower60V                (*(aDBMeasu+ 344))
#define usDBmErrPower12V                (*(aDBMeasu+ 345))
#define usDBmErrPower5V                 (*(aDBMeasu+ 346))
#define usDBmErrPower3D3V               (*(aDBMeasu+ 347))
#define usDBmErrPower1D2V               (*(aDBMeasu+ 348))
#define usDBmErrTempCPU                 (*(aDBMeasu+ 349))
#define aDBmErrCylinder                   (aDBMeasu+ 350)
#define usDBmErrCylinder1               (*(aDBMeasu+ 350))
#define usDBmErrCylinder2               (*(aDBMeasu+ 351))
#define usDBmErrCylinder3               (*(aDBMeasu+ 352))
#define usDBmErrCylinder4               (*(aDBMeasu+ 353))
#define usDBmErrCylinder5               (*(aDBMeasu+ 354))
#define usDBmErrCylinder6               (*(aDBMeasu+ 355))
#define usDBmErrCylinder7               (*(aDBMeasu+ 356))
#define usDBmErrCylinder8               (*(aDBMeasu+ 357))
#define usDBmErrCylinder9               (*(aDBMeasu+ 358))
#define usDBmErrCylinder10              (*(aDBMeasu+ 359))
#define	usDBmErrDigitOut1               (*(aDBMeasu+ 360))
#define	usDBmErrDigitOut2               (*(aDBMeasu+ 361))
#define	usDBmErrDigitOut3               (*(aDBMeasu+ 362))
#define	usDBmErrDigitOut4               (*(aDBMeasu+ 363))
#define	usDBmErrDigitOut5               (*(aDBMeasu+ 364))
#define	usDBmErrDigitOut6               (*(aDBMeasu+ 365))
#define	usDBmErrDigitOut7               (*(aDBMeasu+ 366))
#define	usDBmErrDigitOut8               (*(aDBMeasu+ 367))
#define usDBmErrBackup0                 (*(aDBMeasu+ 368))
#define usDBmErrBackup1                 (*(aDBMeasu+ 369))
#define usDBmErrBackup2                 (*(aDBMeasu+ 370))
#define usDBmErrBackup3                 (*(aDBMeasu+ 371))
#define usDBmErrBackup4                 (*(aDBMeasu+ 372))
#define usDBmErrBackup5                 (*(aDBMeasu+ 373))
#define usDBmErrBackup6                 (*(aDBMeasu+ 374))
#define usDBmErrBackup7                 (*(aDBMeasu+ 375))

/* ***************** Part 17: Historys, (376 - 459) ******************* */
#define aDBmHistBegin                     (aDBMeasu+ 376)
#define uiDBmTimer32           (*(INT32U*)(aDBMeasu+ 376))
#define usDBmTimer16U                   (*(aDBMeasu+ 376))
#define usDBmTimer16L                   (*(aDBMeasu+ 377))
#define uiDBmMiles32           (*(INT32U*)(aDBMeasu+ 378))
#define usDBmMiles16U                   (*(aDBMeasu+ 378))
#define usDBmMiles16L                   (*(aDBMeasu+ 379))
#define aDBmSErrBegin                     (aDBMeasu+ 380)
#define usDBmSErrCrankSensor1           (*(aDBMeasu+ 380))
#define usDBmSErrCrankSensor2           (*(aDBMeasu+ 381))
#define usDBmSErrCamSensor              (*(aDBMeasu+ 382))
#define usDBmSErrVSSensor               (*(aDBMeasu+ 383))
#define usDBmSErrSetp1Extern            (*(aDBMeasu+ 384))
#define usDBmSErrSetp1ExtSub            (*(aDBMeasu+ 385))
#define usDBmSErrSetp2Extern            (*(aDBMeasu+ 386))
#define usDBmSErrBoostPressure          (*(aDBMeasu+ 387))
#define usDBmSErrOilPressure            (*(aDBMeasu+ 388))
#define usDBmSErrAmbientPressure        (*(aDBMeasu+ 389))
#define usDBmSErrCoolantTemp            (*(aDBMeasu+ 390))
#define usDBmSErrBoostTemp              (*(aDBMeasu+ 391))
#define usDBmSErrOilTemp                (*(aDBMeasu+ 392))
#define usDBmSErrFuelTemp               (*(aDBMeasu+ 393))
#define usDBmSErrExhaustTemp            (*(aDBMeasu+ 394))
#define usDBmSErrLoadInput              (*(aDBMeasu+ 395))
#define usDBmSErrSyncInput              (*(aDBMeasu+ 396))
#define usDBmSErrEgrInput               (*(aDBMeasu+ 397))
#define usDBmSErrBeginInput             (*(aDBMeasu+ 398))
#define usDBmSErrRailPressure1          (*(aDBMeasu+ 399))
#define usDBmSErrRailPressure2          (*(aDBMeasu+ 400))
#define usDBmSErrCurrent1               (*(aDBMeasu+ 401))
#define usDBmSErrCurrent2               (*(aDBMeasu+ 402))
#define usDBmSErrCylinderFault          (*(aDBMeasu+ 403))
#define usDBmSErrEgrActuator            (*(aDBMeasu+ 404))
#define usDBmSErrBeginActuator          (*(aDBMeasu+ 405))
#define usDBmSErrOilPressWarn           (*(aDBMeasu+ 406))
#define usDBmSErrOilPressEcy            (*(aDBMeasu+ 407))
#define usDBmSErrCoolantTempWarn        (*(aDBMeasu+ 408))
#define usDBmSErrBoostTempWarn          (*(aDBMeasu+ 409))
#define usDBmSErrOilTempWarn            (*(aDBMeasu+ 410))
#define usDBmSErrTempIntern             (*(aDBMeasu+ 411))
#define usDBmSErrVoltage                (*(aDBMeasu+ 412))
#define usDBmSErrOverSpeed              (*(aDBMeasu+ 413))
#define usDBmSErrCAN                    (*(aDBMeasu+ 414))
#define usDBmSErr5VOut                  (*(aDBMeasu+ 415))
#define usDBmSErrADC                    (*(aDBMeasu+ 416))
#define usDBmSErrStack                  (*(aDBMeasu+ 417))
#define usDBmSErrLogical                (*(aDBMeasu+ 418))
#define usDBmSErrCalcTime               (*(aDBMeasu+ 419))
#define usDBmSErrDataCheck              (*(aDBMeasu+ 420))
#define usDBmSErrClearFlash             (*(aDBMeasu+ 421))
#define usDBmSErrParamStore             (*(aDBMeasu+ 422))
#define usDBmSErrPogramTest             (*(aDBMeasu+ 423))
#define usDBmSErrRamTest                (*(aDBMeasu+ 424))
#define usDBmSErrIntern                 (*(aDBMeasu+ 425))
#define usDBmSErrSpeedDelta             (*(aDBMeasu+ 426))
#define usDBmSErrEngineStart            (*(aDBMeasu+ 427))
#define usDBmSErrPower60V               (*(aDBMeasu+ 428))
#define usDBmSErrPower12V               (*(aDBMeasu+ 429))
#define usDBmSErrPower5V                (*(aDBMeasu+ 430))
#define usDBmSErrPower3D3V              (*(aDBMeasu+ 431))
#define usDBmSErrPower1D2V              (*(aDBMeasu+ 432))
#define usDBmSErrTempCPU                (*(aDBMeasu+ 433))
#define aDBmSErrCylinder                  (aDBMeasu+ 434)
#define usDBmSErrCylinder1              (*(aDBMeasu+ 434))
#define usDBmSErrCylinder2              (*(aDBMeasu+ 435))
#define usDBmSErrCylinder3              (*(aDBMeasu+ 436))
#define usDBmSErrCylinder4              (*(aDBMeasu+ 437))
#define usDBmSErrCylinder5              (*(aDBMeasu+ 438))
#define usDBmSErrCylinder6              (*(aDBMeasu+ 439))
#define usDBmSErrCylinder7              (*(aDBMeasu+ 440))
#define usDBmSErrCylinder8              (*(aDBMeasu+ 441))
#define usDBmSErrCylinder9              (*(aDBMeasu+ 442))
#define usDBmSErrCylinder10             (*(aDBMeasu+ 443))
#define usDBmSErrDigitOut1              (*(aDBMeasu+ 444))
#define usDBmSErrDigitOut2              (*(aDBMeasu+ 445))
#define usDBmSErrDigitOut3              (*(aDBMeasu+ 446))
#define usDBmSErrDigitOut4              (*(aDBMeasu+ 447))
#define usDBmSErrDigitOut5              (*(aDBMeasu+ 448))
#define usDBmSErrDigitOut6              (*(aDBMeasu+ 449))
#define usDBmSErrDigitOut7              (*(aDBMeasu+ 450))
#define usDBmSErrDigitOut8              (*(aDBMeasu+ 451))
#define usDBmSErrBackup0                (*(aDBMeasu+ 452))
#define usDBmSErrBackup1                (*(aDBMeasu+ 453))
#define usDBmSErrBackup2                (*(aDBMeasu+ 454))
#define usDBmSErrBackup3                (*(aDBMeasu+ 455))
#define usDBmSErrBackup4                (*(aDBMeasu+ 456))
#define usDBmSErrBackup5                (*(aDBMeasu+ 457))
#define usDBmSErrBackup6                (*(aDBMeasu+ 458))
#define usDBmSErrBackup7                (*(aDBMeasu+ 459))

#endif
/* ******************************************************************** */
/*                     VEC8000 Function Definition                      */
/* ******************************************************************** */
#if    (DB_ENGINE_EFI_ON == 1)
/* ****************** Part 1: Speed Pickup (0 - 4) ******************** */
#define usDBfSpeedSetpPCOn              (*(aDBFunct+   0))
#define usDBfSpeedIdleAdjustOn          (*(aDBFunct+   1))
#define usDBfSpeedIdleTempCorrOn        (*(aDBFunct+   2))
#define	usDBfSpeedIdleVoltCorrOn        (*(aDBFunct+   3))
#define	usDBfSpeedIdleLoadCorrOn        (*(aDBFunct+   4))

/* ***************** Part 2: Stability/Droop (5 - 12) ***************** */
#define usDBfPIDGainMapOn               (*(aDBFunct+   5))
#define	usDBfPIDStabilityMapOn          (*(aDBFunct+   6))
#define	usDBfPIDDerivativeMapOn         (*(aDBFunct+   7))
#define usDBfPIDTempCorrOn              (*(aDBFunct+   8))
#define usDBfStaticCorrOn               (*(aDBFunct+   9))
#define usDBfDroopOn                    (*(aDBFunct+  10))
#define usDBfDroopMapOn                 (*(aDBFunct+  11))
#define usDBfFuelTempCorrOn             (*(aDBFunct+  12))

/* ********************* Part 3: Ramp (13 - 15) *********************** */
#define usDBfSpeedRampOn                (*(aDBFunct+  13))
#define usDBfSectionalOrFixedRamp       (*(aDBFunct+  14))
#define usDBfStartSpeedRampOn           (*(aDBFunct+  15))

/* **************** Part 4: Solenoid Valves, (16 - 19) **************** */
#define usDBfSolFaultEcyOn              (*(aDBFunct+  16))
#define usDBfSolDelayVoltCorrOn         (*(aDBFunct+  17))
#define usDBfCylinderMaskAOn            (*(aDBFunct+  18))
#define usDBfCylinderMaskBOn            (*(aDBFunct+  19))

/* ****************** Part 5: Begin Control (20 - 22) ***************** */
#define usDBfBeginSetpMapOn             (*(aDBFunct+  20))
#define usDBfBeginSetpTempCorrOn        (*(aDBFunct+  21))
#define	usDBfBeginSetpAmbCorrOn         (*(aDBFunct+  22))

/* ******************* Part 6: EGR Control (23 - 26) ****************** */
#define usDBfEgrSetpMapOn               (*(aDBFunct+  23))
#define usDBfEgrSetpTempCorrOn          (*(aDBFunct+  24))
#define usDBfEgrSetpBoostCorrOn         (*(aDBFunct+  25))
#define	usDBfEgrSetpGradientCorrOn      (*(aDBFunct+  26))

/* ******************* Part 7: Monitoring (27 - 32) ******************* */
#define usDBfOilPressWarnCurveOn        (*(aDBFunct+  27))
#define usDBfOilPressEcyCurveOn         (*(aDBFunct+  28))
#define usDBfCoolantTempWarnOn          (*(aDBFunct+  29))
#define usDBfBoostTempWarnOn            (*(aDBFunct+  30))
#define usDBfOilTempWarnOn              (*(aDBFunct+  31))
#define	usDBfEngineStatisticsOn         (*(aDBFunct+  32))

/* ****************** Part 8: Limitations (33 - 36) ******************* */
#define usDBfSpeedLimitOn               (*(aDBFunct+  33))
#define usDBfSpeedLimitTempOn           (*(aDBFunct+  34))
#define usDBfBoostLimitOn               (*(aDBFunct+  35))
#define	usDBfAmbientLimitOn             (*(aDBFunct+  36))

/* ****************** Part 9: PWM Outputs (37 - 48) ******************* */
#define	usDBfDigitalOut1Pole            (*(aDBFunct+  37))
#define	usDBfDigitalOut2Pole            (*(aDBFunct+  38))
#define	usDBfDigitalOut3Pole            (*(aDBFunct+  39))
#define	usDBfDigitalOut4Pole            (*(aDBFunct+  40))
#define	usDBfDigitalOut5Pole            (*(aDBFunct+  41))
#define	usDBfDigitalOut6Pole            (*(aDBFunct+  42))
#define	usDBfDigitalOut7Pole            (*(aDBFunct+  43))
#define	usDBfDigitalOut8Pole            (*(aDBFunct+  44))
#define usDBfPWMOut1FrqOrDuty           (*(aDBFunct+  45))
#define usDBfPWMOut2FrqOrDuty           (*(aDBFunct+  46))
#define usDBfPWMOut3FrqOrDuty           (*(aDBFunct+  47))
#define usDBfPWMOut4FrqOrDuty           (*(aDBFunct+  48))

/* ****************** Part 10: Channel Type, (49 - 97) **************** */
#define	usDBfSwPoleEngineStop           (*(aDBFunct+  49))
#define	usDBfSwPoleIdleSpeed            (*(aDBFunct+  50))
#define	usDBfSwPoleSpeedFix1            (*(aDBFunct+  51))
#define	usDBfSwPoleSpeedFix2            (*(aDBFunct+  52))
#define	usDBfSwPoleSpeedInc             (*(aDBFunct+  53))
#define	usDBfSwPoleSpeedDec             (*(aDBFunct+  54))
#define	usDBfSwPoleDroop2Or1            (*(aDBFunct+  55))
#define	usDBfSwPoleDroop3Or2            (*(aDBFunct+  56))
#define	usDBfSwPoleSpeedRange2Or1       (*(aDBFunct+  57))
#define	usDBfSwPoleSpeedRange3Or2       (*(aDBFunct+  58))
#define	usDBfSwPoleSpeedLimit2Or1       (*(aDBFunct+  59))
#define	usDBfSwPoleSpeedLimit3Or2       (*(aDBFunct+  60))
#define	usDBfSwPoleOilPump              (*(aDBFunct+  61))
#define	usDBfSwPoleAirHeater            (*(aDBFunct+  62))
#define	usDBfSwPoleEngineStart          (*(aDBFunct+  63))
#define	usDBfSwPoleSetpoint2Or1         (*(aDBFunct+  64))
#define	usDBfSwPoleForcedLimit          (*(aDBFunct+  65))
#define	usDBfSwPoleSyncEnable           (*(aDBFunct+  66))
#define	usDBfSwPoleLoadEnable           (*(aDBFunct+  67))
#define	usDBfSwPoleAutoOrManual         (*(aDBFunct+  68))
#define	usDBfSwPoleErrorReset           (*(aDBFunct+  69))
#define	usDBfSwPolePTO                  (*(aDBFunct+  70))
#define	usDBfSwPoleRPTO                 (*(aDBFunct+  71))
#define	usDBfSwPolePTOCCSet             (*(aDBFunct+  72))
#define	usDBfSwPolePTOCCReset           (*(aDBFunct+  73))
#define	usDBfSwPolePTOAdd               (*(aDBFunct+  74))
#define	usDBfSwPoleMainBrake            (*(aDBFunct+  75))
#define	usDBfSwPoleClutch               (*(aDBFunct+  76))
#define	usDBfSwPoleDiagnostic           (*(aDBFunct+  77))
#define	usDBfSwPoleIMOrAllSpeed         (*(aDBFunct+  78))
#define	usDBfSwPoleCruiseControl        (*(aDBFunct+  79))
#define	usDBfSwPoleAirConditioner       (*(aDBFunct+  80))
#define usDBfChanTypeSetp1Ext           (*(aDBFunct+  81))
#define usDBfChanTypeSetp1Sub           (*(aDBFunct+  82))
#define usDBfChanTypeSetp2Ext           (*(aDBFunct+  83))
#define usDBfChanTypeBoostPress         (*(aDBFunct+  84))
#define usDBfChanTypeOilPress           (*(aDBFunct+  85))
#define usDBfChanTypeAmbPress           (*(aDBFunct+  86))
#define usDBfChanTypeCoolantTemp        (*(aDBFunct+  87))
#define usDBfChanTypeBoostTemp          (*(aDBFunct+  88))
#define usDBfChanTypeOilTemp            (*(aDBFunct+  89))
#define usDBfChanTypeFuelTemp           (*(aDBFunct+  90))
#define usDBfChanTypeExhaustTemp        (*(aDBFunct+  91))
#define usDBfChanTypeLoadInput          (*(aDBFunct+  92))
#define usDBfChanTypeSyncInput          (*(aDBFunct+  93))
#define usDBfChanTypeEgrInput           (*(aDBFunct+  94))
#define usDBfChanTypeBeginInput         (*(aDBFunct+  95))
#define usDBfChanTypeRailPress1         (*(aDBFunct+  96))
#define usDBfChanTypeRailPress2         (*(aDBFunct+  97))
#define usDBfChanTypeCurrent1           (*(aDBFunct+  98))
#define usDBfChanTypeCurrent2           (*(aDBFunct+  99))

/* ************************ Part 11: Errors (98) ********************** */
#define usDBfStoreSErrOn                (*(aDBFunct+ 100))

/* ****************** Part 12: Generator (99 - 100) ******************* */
#define usDBfSyncAnalogOrDigit          (*(aDBFunct+ 101))
#define usDBfLoadControlOrPot           (*(aDBFunct+ 102))

/* ******************* Part 13: Vehicle (101 - 107) ******************* */
#define	usDBfSwitchIdleSoftOn           (*(aDBFunct+ 103))
#define	usDBfSwitchIMModeSoftOn         (*(aDBFunct+ 104))
#define	usDBfSpeedMaxVSSZeroOn          (*(aDBFunct+ 105))
#define	usDBfEBrakeServiceOn            (*(aDBFunct+ 106))
#define	usDBfEBrakeCruiseOn             (*(aDBFunct+ 107))
#define	usDBfIMGovernorOn               (*(aDBFunct+ 108))
#define	usDBfIMFuelRampOn               (*(aDBFunct+ 109))
#define	usDBfSpeedIdleACCorrOn          (*(aDBFunct+ 110))
#define	usDBfAirHeaterCorrAmbOn         (*(aDBFunct+ 111))
#define	usDBfAirHeaterCorrVoltOn        (*(aDBFunct+ 112))

/* ****************** Part 14: Injection Map, (111 - 124) ************* */
#define usDBfPilotInjectOn              (*(aDBFunct+ 113))
#define usDBfPilotInjectMapOn           (*(aDBFunct+ 114))
#define usDBfPreInjectOn                (*(aDBFunct+ 115))
#define usDBfPreInjectMapOn             (*(aDBFunct+ 116))
#define usDBfMainPeriodMapOn            (*(aDBFunct+ 117))
#define usDBfMainTimeMapOn              (*(aDBFunct+ 117)) /* CR */
#define usDBfMainPeriodCylCorrOn        (*(aDBFunct+ 118))
#define usDBfMainTimeCylCorrOn          (*(aDBFunct+ 118)) /* CR */
#define usDBfMainBeginMapOn             (*(aDBFunct+ 119))
#define usDBfMainBeginCylCorrOn         (*(aDBFunct+ 120))
#define usDBfMainBeginTempCorrOn        (*(aDBFunct+ 121))
#define usDBfMainBeginAmbCorrOn         (*(aDBFunct+ 122))
#define usDBfPostInjectOn               (*(aDBFunct+ 123))
#define usDBfPostInjectMapOn            (*(aDBFunct+ 124))
#define usDBfLastInjectOn               (*(aDBFunct+ 125))
#define usDBfLastInjectMapOn            (*(aDBFunct+ 126))

/* ***************** Part 15: Common Rail, (125 - 127) **************** */
#define usDBfCRPressSetpMapOn           (*(aDBFunct+ 127))
#define usDBfCRPressRampOn              (*(aDBFunct+ 128))
#define usDBfCRPressMinStartOn          (*(aDBFunct+ 129))

/* ******************* Part 16: Others, (100 - 109) ******************* */
#define	usDBfFunctBackup0               (*(aDBFunct+ 130))
#define	usDBfFunctBackup1               (*(aDBFunct+ 131))
#define	usDBfFunctBackup2               (*(aDBFunct+ 132))
#define	usDBfFunctBackup3               (*(aDBFunct+ 133))
#define	usDBfFunctBackup4               (*(aDBFunct+ 134))
#define	usDBfFunctBackup5               (*(aDBFunct+ 135))
#define	usDBfFunctBackup6               (*(aDBFunct+ 136))
#define	usDBfFunctBackup7               (*(aDBFunct+ 137))
#define	usDBfFunctBackup8               (*(aDBFunct+ 138))
#define	usDBfFunctBackup9               (*(aDBFunct+ 139))

#endif
/* ******************************************************************** */
/*                      VEC8000 Curve Definition                        */
/* ******************************************************************** */
#if    (DB_ENGINE_EFI_ON == 1)
/* ************************** 1: PID Gain Map ************************* */
#define aDBcPIDGainMap_n                 (aDBCurve+   0)    /* 0:   8   */
#define aDBcPIDGainMap_Q                 (aDBCurve+   8)    /* 1:   8   */
#define aDBcPIDGainMap_C                 (aDBCurve+  16)    /* 2:   8*8 */

/* ************************** 2: Boost Limit ************************** */
#define aDBcBoostLimit_n                 (aDBCurve+  80)    /* 3:   8   */
#define aDBcBoostLimit_p                 (aDBCurve+  88)    /* 4:   8   */
#define aDBcBoostLimit_Q                 (aDBCurve+  96)    /* 5:   8*8 */

/* ************************* 3: Ambient Limit ************************* */
#define aDBcAmbientLimit_n               (aDBCurve+ 160)    /* 6:   8   */
#define aDBcAmbientLimit_p               (aDBCurve+ 168)    /* 7:   8   */
#define aDBcAmbientLimit_Q               (aDBCurve+ 176)    /* 8:   8*8 */

/* ************************** 4: Speed Limit ************************** */
#define aDBcSpeedLimit_n                 (aDBCurve+ 240)    /* 9:  30   */
#define aDBcSpeedLimit_Q1                (aDBCurve+ 270)    /* 10: 30   */
#define aDBcSpeedLimit_Q2                (aDBCurve+ 300)    /* 11: 30   */
#define aDBcSpeedLimit_Q3                (aDBCurve+ 330)    /* 12: 30   */

/* ******************** 5: Oil Press Warn and Ecy ********************* */
#define aDBcOilPressWarn_n               (aDBCurve+ 360)    /* 13: 10   */
#define aDBcOilPressWarn_p               (aDBCurve+ 370)    /* 14: 10   */
#define aDBcOilPressEcy_n                (aDBCurve+ 380)    /* 15: 10   */
#define aDBcOilPressEcy_p                (aDBCurve+ 390)    /* 16: 10   */

/* ******************** 6: Main Injection Period ********************** */
#define aDBcMainPeriod_B                 (aDBCurve+ 400)    /* 17: 4    */

#define aDBcMainPeriod_n                 (aDBCurve+ 404)    /* 18: 8    */
#define aDBcMainPeriod_Q                 (aDBCurve+ 412)    /* 19: 8    */
#define aDBcMainPeriod0_DP               (aDBCurve+ 420)    /* 20: 8*8  */
#define aDBcMainPeriod1_DP               (aDBCurve+ 484)    /* 21: 8*8  */
#define aDBcMainPeriod2_DP               (aDBCurve+ 548)    /* 22: 8*8  */
#define aDBcMainPeriod3_DP               (aDBCurve+ 612)    /* 23: 8*8  */

#define aDBcMainPeriod_n2                (aDBCurve+ 404)    /* 18: 16   */
#define aDBcMainPeriod_Q2                (aDBCurve+ 420)    /* 19: 128  */
#define aDBcMainPeriod_DP2               (aDBCurve+ 548)    /* 20: 128  */

#define aDBcMainPeriodAlt_Q              (aDBCurve+ 676)    /* 24: 2    */
#define aDBcMainPeriodAlt_P              (aDBCurve+ 678)    /* 25: 2    */
#define aDBcMainTime_B                   (aDBCurve+ 400)    /* 17: 4    */
#define aDBcMainTime_Pr                  (aDBCurve+ 404)    /* 18: 8    */
#define aDBcMainTime_Q                   (aDBCurve+ 412)    /* 19: 8    */
#define aDBcMainTime_DT                  (aDBCurve+ 420)    /* 20: 8*8  */
#define aDBcMainTime1_DT                 (aDBCurve+ 484)    /* 21: 8*8  */
#define aDBcMainTime2_DT                 (aDBCurve+ 548)    /* 22: 8*8  */
#define aDBcMainTime3_DT                 (aDBCurve+ 612)    /* 23: 8*8  */
#define aDBcMainTimeAlt_Q                (aDBCurve+ 676)    /* 24: 2    */
#define aDBcMainTimeAlt_T                (aDBCurve+ 678)    /* 25: 2    */

/* ******************** 7: Main Injection Begin *********************** */
#define aDBcMainBegin_n                  (aDBCurve+ 680)    /* 26: 30   */
#define aDBcMainBegin_Q                  (aDBCurve+ 710)    /* 27: 30*8 */
#define aDBcMainBegin_DB                 (aDBCurve+ 950)    /* 28: 30*8 */

/* ********************* 8: Main Period Correction ******************** */
#define aDBcMainPerCorr_n                (aDBCurve+1190)    /* 29: 3    */
#define aDBcMainPerCorr_Q                (aDBCurve+1193)    /* 30: 3    */
#define aDBcMainPerCorr1_DP              (aDBCurve+1196)    /* 31: 3*3  */
#define aDBcMainPerCorr2_DP              (aDBCurve+1205)    /* 32: 3*3  */
#define aDBcMainPerCorr3_DP              (aDBCurve+1214)    /* 33: 3*3  */
#define aDBcMainPerCorr4_DP              (aDBCurve+1223)    /* 34: 3*3  */
#define aDBcMainPerCorr5_DP              (aDBCurve+1232)    /* 35: 3*3  */
#define aDBcMainPerCorr6_DP              (aDBCurve+1241)    /* 36: 3*3  */
#define aDBcMainPerCorr7_DP              (aDBCurve+1250)    /* 37: 3*3  */
#define aDBcMainPerCorr8_DP              (aDBCurve+1259)    /* 38: 3*3  */
#define aDBcMainPerCorr9_DP              (aDBCurve+1268)    /* 39: 3*3  */
#define aDBcMainPerCorr10_DP             (aDBCurve+1277)    /* 40: 3*3  */

#define aDBcMainTimCorr_n                (aDBCurve+1190)    /* 29: 3    */
#define aDBcMainTimCorr_Q                (aDBCurve+1193)    /* 30: 3    */
#define aDBcMainTimCorr1_DT              (aDBCurve+1196)    /* 31: 3*3  */
#define aDBcMainTimCorr2_DT              (aDBCurve+1205)    /* 32: 3*3  */
#define aDBcMainTimCorr3_DT              (aDBCurve+1214)    /* 33: 3*3  */
#define aDBcMainTimCorr4_DT              (aDBCurve+1223)    /* 34: 3*3  */
#define aDBcMainTimCorr5_DT              (aDBCurve+1232)    /* 35: 3*3  */
#define aDBcMainTimCorr6_DT              (aDBCurve+1241)    /* 36: 3*3  */
#define aDBcMainTimCorr7_DT              (aDBCurve+1250)    /* 37: 3*3  */
#define aDBcMainTimCorr8_DT              (aDBCurve+1259)    /* 38: 3*3  */
#define aDBcMainTimCorr9_DT              (aDBCurve+1268)    /* 39: 3*3  */
#define aDBcMainTimCorr10_DT             (aDBCurve+1277)    /* 40: 3*3  */

/* ********************** 9: Main Begin Correction ******************** */
#define aDBcMainBegCorr_n                (aDBCurve+1286)    /* 41: 3    */
#define aDBcMainBegCorr_Q                (aDBCurve+1289)    /* 42: 3    */
#define aDBcMainBegCorr1_DB              (aDBCurve+1292)    /* 43: 3*3  */
#define aDBcMainBegCorr2_DB              (aDBCurve+1301)    /* 44: 3*3  */
#define aDBcMainBegCorr3_DB              (aDBCurve+1310)    /* 45: 3*3  */
#define aDBcMainBegCorr4_DB              (aDBCurve+1319)    /* 46: 3*3  */
#define aDBcMainBegCorr5_DB              (aDBCurve+1328)    /* 47: 3*3  */
#define aDBcMainBegCorr6_DB              (aDBCurve+1337)    /* 48: 3*3  */
#define aDBcMainBegCorr7_DB              (aDBCurve+1346)    /* 49: 3*3  */
#define aDBcMainBegCorr8_DB              (aDBCurve+1355)    /* 50: 3*3  */
#define aDBcMainBegCorr9_DB              (aDBCurve+1364)    /* 51: 3*3  */
#define aDBcMainBegCorr10_DB             (aDBCurve+1373)    /* 52: 3*3  */

/* ************** 10: Pilot Injection Period and Begin **************** */
#define aDBcPilotInject_n                (aDBCurve+1382)    /* 53: 8    */
#define aDBcPilotInject_Q                (aDBCurve+1390)    /* 54: 8    */
#define aDBcPilotInject_Time             (aDBCurve+1398)    /* 55: 8*8  */
#define aDBcPilotInject_Begin            (aDBCurve+1462)    /* 56: 8*8  */

/* *************** 11: Pre Injection Period and Begin ***************** */
#define aDBcPreInject_n                  (aDBCurve+1526)    /* 57: 8    */
#define aDBcPreInject_Q                  (aDBCurve+1534)    /* 58: 8    */
#define aDBcPreInject_Time               (aDBCurve+1542)    /* 59: 8*8  */
#define aDBcPreInject_Begin              (aDBCurve+1606)    /* 60: 8*8  */

/* ************** 12: Post Injection Period and Begin ***************** */
#define aDBcPostInject_n                 (aDBCurve+1670)    /* 61: 8    */
#define aDBcPostInject_Q                 (aDBCurve+1678)    /* 62: 8    */
#define aDBcPostInject_Time              (aDBCurve+1686)    /* 63: 8*8  */
#define aDBcPostInject_Begin             (aDBCurve+1750)    /* 64: 8*8  */

/* *************** 13: End Injection Period and Begin ***************** */
#define aDBcLastInject_n                 (aDBCurve+1814)    /* 65: 8    */
#define aDBcLastInject_Q                 (aDBCurve+1822)    /* 66: 8    */
#define aDBcLastInject_Time              (aDBCurve+1830)    /* 67: 8*8  */
#define aDBcLastInject_Begin             (aDBCurve+1894)    /* 68: 8*8  */

/* ***************** 14: Common Rail Press Setpoint ******************* */
#define aDBcCRPressSetp_n                (aDBCurve+1958)    /* 69: 8    */
#define aDBcCRPressSetp_Q                (aDBCurve+1966)    /* 70: 8    */
#define aDBcCRPressSetp                  (aDBCurve+1974)    /* 71: 8*8  */

/* ***************** 15: Common Rail Press Ramp  ********************** */
#define aDBcCRPressRamp_Q                (aDBCurve+2038)    /* 72: 10   */
#define aDBcCRPressRamp_Up               (aDBCurve+2048)    /* 73: 10   */
#define aDBcCRPressRamp_Down             (aDBCurve+2058)    /* 74: 10   */

/* ************************* 16: Begin Setpoint *********************** */
#define aDBcBeginSetp_n                  (aDBCurve+2068)    /* 75: 8    */
#define aDBcBeginSetp_Q                  (aDBCurve+2076)    /* 76: 8    */
#define aDBcBeginSetp_B                  (aDBCurve+2084)    /* 77: 8*8  */

/* ************************* 17: EGR Setpoint ************************* */
#define aDBcEgrSetp_n                    (aDBCurve+2148)    /* 78: 8    */
#define aDBcEgrSetp_Q                    (aDBCurve+2156)    /* 79: 8    */
#define aDBcEgrSetp_p                    (aDBCurve+2164)    /* 80: 8*8  */

/* ************************* 18: PID I/D Map ************************** */
#define aDBcPIDStabMap_n                 (aDBCurve+2228)    /* 81: 10   */
#define aDBcPIDStabMap_C                 (aDBCurve+2238)    /* 82: 10   */
#define aDBcPIDDeriMap_n                 (aDBCurve+2248)    /* 83: 10   */
#define aDBcPIDDeriMap_C                 (aDBCurve+2258)    /* 84: 10   */

/* ********************* 19: Temperature Sensor *********************** */
#define aDBcTempIn1_D                    (aDBCurve+2268)    /* 85: 10   */
#define aDBcTempIn1_T                    (aDBCurve+2278)    /* 86: 10   */
#define aDBcTempIn2_D                    (aDBCurve+2288)    /* 87: 10   */
#define aDBcTempIn2_T                    (aDBCurve+2298)    /* 88: 10   */

/* *********************** 20: Pedal Angle Map ************************ */
#define aDBcIMFuelMap_n                  (aDBCurve+2308)    /* 89: 10   */
#define aDBcIMFuelMap_S                  (aDBCurve+2318)    /* 90: 10   */
#define aDBcIMFuelMap_Q                  (aDBCurve+2328)    /* 91: 100  */
#define aDBcSetp1Map_n                   (aDBcIMFuelMap_n+  0)
#define aDBcSetp1Map_Min                 (aDBcIMFuelMap_n+ 20)
#define aDBcSetp1Map_Max                 (aDBcIMFuelMap_n+ 40)
#define aDBcSetp1Sub_n                   (aDBcIMFuelMap_n+ 60)
#define aDBcSetp1Sub_Min                 (aDBcIMFuelMap_n+ 80)
#define aDBcSetp1Sub_Max                 (aDBcIMFuelMap_n+100)
#define aDBcSetp2Map_n                   (aDBcIMFuelMap_n+ 60)
#define aDBcSetp2Map_Min                 (aDBcIMFuelMap_n+ 80)
#define aDBcSetp2Map_Max                 (aDBcIMFuelMap_n+100)

/* ************************** 21: Droop Map *************************** */
#define aDBcDroopMap_n                   (aDBCurve+2428)    /* 92: 10   */
#define aDBcDroop1Map_n                  (aDBCurve+2428)    /* 92: 10   */
#define aDBcDroop2Map_n                  (aDBCurve+2428)    /* 92: 10   */
#define aDBcDroop3Map_n                  (aDBCurve+2428)    /* 92: 10   */
#define aDBcDroopMap_D                   (aDBCurve+2438)    /* 93: 10   */
#define aDBcDroop1Map_D                  (aDBCurve+2438)    /* 93: 10   */
#define aDBcDroop2Map_D                  (aDBCurve+2448)    /* 94: 10   */
#define aDBcDroop3Map_D                  (aDBCurve+2458)    /* 95: 10   */

/* ************************* 22: Data Plate *************************** */
#define aDBcDataPlate_D                  (aDBCurve+2468)    /* 96: 312  */

/* ************************* 23: Data Plate *************************** */
#define aDBcCurveBackup1_x               (aDBCurve+2780)    /* 97: 8    */
#define aDBcCurveBackup1_y               (aDBCurve+2788)    /* 98: 8    */
#define aDBcCurveBackup1_z               (aDBCurve+2796)    /* 99: 8*8  */

/* ************************* 24: Data Plate *************************** */
#define aDBcCurveBackup2_x               (aDBCurve+2860)    /* 100: 10  */
#define aDBcCurveBackup2_y               (aDBCurve+2870)    /* 101: 10  */

/* ************************* 25: Statistics *************************** */
#define aDBcStatistics_n                 (aDBCurve+2880)    /* 102: 10  */
#define aDBcStatistics_Q                 (aDBCurve+2890)    /* 103: 10  */
#define aDBcStatistics_T                 (aDBCurve+2900)    /* 104: 100 */

#endif
/* ******************************************************************** */
/*                             End of Curve                             */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */