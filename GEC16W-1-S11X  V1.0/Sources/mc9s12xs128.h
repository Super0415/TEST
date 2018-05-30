/* Based on CPU DB MC9S12XS256_112, version 3.00.018 (RegistersPrg V2.32) */
/*
** ###################################################################
**     Filename  : mc9s12xs128.h
**     Processor : MC9S12XS128CAL
**     FileFormat: V2.32
**     DataSheet : MC9S12XS256RMV1 Rev. 1.03 06/2008
**     Compiler  : CodeWarrior compiler
**     Date/Time : 7.6.2010, 15:35
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**      - 20.02.2008, V3.00.0:
**              - Corrected register's address: ATD0DIENL 0x02CC => 0x02CD
**              - Removed bit FSTAT[RSVD].
**              -   REASON: Changes in the data sheet (from Rev. 1.00 5/2007 to Rev. 1.01 8/2007).
**      - 17.04.2008, V3.00.1:
**              - Renamed registers TCNTH/L ==> TCNTHi/Lo, TCxH/L ==> TCxHi/Lo.
**              -   REASON: Bug-fix (#6048 in Issue Manager).
**      - 21.05.2008, V3.00.2:
**              - Added register VREGHTTR. Added interrupt vector Vhti.
**              -   REASON: Changes in the data sheet (from Rev. 1.01 08/2007 to Rev. 1.02 02/2008).
**      - 23.02.2009, V3.00.3:
**              - Corrected definition of 16-bit Port AD0 registers to use properly AD0L/AD0H parts.
**              -   REASON: Bug-fix (#7029 in Issue Manager).
**
**     File-Format-Revisions:
**      - 19.07.2007, V2.18 :
**               - Improved number of blanked lines inside register structures
**      - 06.08.2007, V2.19 :
**               - CPUDB revisions generated ahead of the file-format revisions.
**      - 11.09.2007, V2.20 :
**               - Added comment about initialization of unbonded pins.
**      - 02.01.2008, V2.21 :
**               - Changes have not affected this file (because they are related to another family)
**      - 13.02.2008, V2.22 :
**               - Changes have not affected this file (because they are related to another family)
**      - 20.02.2008, V2.23 :
**               - Termination of pragma V30toV31Compatible added, #5708
**      - 03.07.2008, V2.24 :
**               - Added support for bits with name starting with number (like "1HZ")
**      - 28.11.2008, V2.25 :
**               - StandBy RAM array declaration for ANSI-C added
**      - 1.12.2008, V2.26 :
**               - Duplication of bit (or bit-group) name with register name is not marked as a problem, is register is internal only and it is not displayed in I/O map.
**      - 17.3.2009, V2.27 :
**               - Merged bit-group is not generated, if the name matches with another bit name in the register
**      - 6.4.2009, V2.28 :
**               - Fixed generation of merged bits for bit-groups with a digit at the end, if group-name is defined in CPUDB
**      - 3.8.2009, V2.29 :
**               - If there is just one bits group matching register name, single bits are not generated
**      - 10.9.2009, V2.30 :
**               - Fixed generation of registers arrays.
**      - 15.10.2009, V2.31 :
**               - Changes have not affected this file (because they are related to another family)
**      - 18.05.2010, V2.32 :
**               - MISRA compliance: U/UL suffixes added to all numbers (_MASK,_BITNUM and addresses)
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user�s reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/

#ifndef _MC9S12XS128_H
#define _MC9S12XS128_H

/*lint -save  -e950 -esym(960,18.4) -e46 -esym(961,19.7) Disable MISRA rule (1.1,18.4,6.4,19.7) checking. */
/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */
#pragma OPTION ADD V30toV31Compatible "-BfaGapLimitBits4294967295" /*this guarantee correct bitfield positions*/

/**************** interrupt vector numbers ****************/
#define VectorNumber_Vsi                119U
#define VectorNumber_Vsyscall           118U
#define VectorNumber_VReserved118       117U
#define VectorNumber_VReserved117       116U
#define VectorNumber_VReserved116       115U
#define VectorNumber_VReserved115       114U
#define VectorNumber_VReserved114       113U
#define VectorNumber_VReserved113       112U
#define VectorNumber_VReserved112       111U
#define VectorNumber_VReserved111       110U
#define VectorNumber_VReserved110       109U
#define VectorNumber_VReserved109       108U
#define VectorNumber_VReserved108       107U
#define VectorNumber_VReserved107       106U
#define VectorNumber_VReserved106       105U
#define VectorNumber_VReserved105       104U
#define VectorNumber_VReserved104       103U
#define VectorNumber_VReserved103       102U
#define VectorNumber_VReserved102       101U
#define VectorNumber_VReserved101       100U
#define VectorNumber_VReserved100       99U
#define VectorNumber_VReserved99        98U
#define VectorNumber_VReserved98        97U
#define VectorNumber_Vatd0compare       96U
#define VectorNumber_VReserved96        95U
#define VectorNumber_VReserved95        94U
#define VectorNumber_VReserved94        93U
#define VectorNumber_VReserved93        92U
#define VectorNumber_VReserved92        91U
#define VectorNumber_VReserved91        90U
#define VectorNumber_VReserved90        89U
#define VectorNumber_VReserved89        88U
#define VectorNumber_VReserved88        87U
#define VectorNumber_VReserved87        86U
#define VectorNumber_VReserved86        85U
#define VectorNumber_VReserved85        84U
#define VectorNumber_VReserved84        83U
#define VectorNumber_VReserved83        82U
#define VectorNumber_VReserved82        81U
#define VectorNumber_VReserved81        80U
#define VectorNumber_VReserved79        79U
#define VectorNumber_VReserved78        78U
#define VectorNumber_VReserved77        77U
#define VectorNumber_VReserved76        76U
#define VectorNumber_VReserved75        75U
#define VectorNumber_VReserved74        74U
#define VectorNumber_VReserved73        73U
#define VectorNumber_VReserved72        72U
#define VectorNumber_VReserved71        71U
#define VectorNumber_VReserved70        70U
#define VectorNumber_Vpit3              69U
#define VectorNumber_Vpit2              68U
#define VectorNumber_Vpit1              67U
#define VectorNumber_Vpit0              66U
#define VectorNumber_Vhti               65U
#define VectorNumber_Vapi               64U
#define VectorNumber_Vlvi               63U
#define VectorNumber_VReserved62        62U
#define VectorNumber_VReserved61        61U
#define VectorNumber_VReserved60        60U
#define VectorNumber_VReserved59        59U
#define VectorNumber_VReserved58        58U
#define VectorNumber_Vpwmesdn           57U
#define VectorNumber_Vportp             56U
#define VectorNumber_VReserved55        55U
#define VectorNumber_VReserved54        54U
#define VectorNumber_VReserved53        53U
#define VectorNumber_VReserved52        52U
#define VectorNumber_VReserved51        51U
#define VectorNumber_VReserved50        50U
#define VectorNumber_VReserved49        49U
#define VectorNumber_VReserved48        48U
#define VectorNumber_VReserved47        47U
#define VectorNumber_VReserved46        46U
#define VectorNumber_VReserved45        45U
#define VectorNumber_VReserved44        44U
#define VectorNumber_VReserved43        43U
#define VectorNumber_VReserved42        42U
#define VectorNumber_VReserved41        41U
#define VectorNumber_VReserved40        40U
#define VectorNumber_Vcan0tx            39U
#define VectorNumber_Vcan0rx            38U
#define VectorNumber_Vcan0err           37U
#define VectorNumber_Vcan0wkup          36U
#define VectorNumber_Vflash             35U
#define VectorNumber_Vflashfd           34U
#define VectorNumber_VReserved33        33U
#define VectorNumber_VReserved32        32U
#define VectorNumber_VReserved31        31U
#define VectorNumber_VReserved30        30U
#define VectorNumber_Vcrgscm            29U
#define VectorNumber_Vcrgplllck         28U
#define VectorNumber_VReserved27        27U
#define VectorNumber_VReserved26        26U
#define VectorNumber_Vporth             25U
#define VectorNumber_Vportj             24U
#define VectorNumber_VReserved23        23U
#define VectorNumber_Vatd0              22U
#define VectorNumber_Vsci1              21U
#define VectorNumber_Vsci0              20U
#define VectorNumber_Vspi0              19U
#define VectorNumber_Vtimpaie           18U
#define VectorNumber_Vtimpaaovf         17U
#define VectorNumber_Vtimovf            16U
#define VectorNumber_Vtimch7            15U
#define VectorNumber_Vtimch6            14U
#define VectorNumber_Vtimch5            13U
#define VectorNumber_Vtimch4            12U
#define VectorNumber_Vtimch3            11U
#define VectorNumber_Vtimch2            10U
#define VectorNumber_Vtimch1            9U
#define VectorNumber_Vtimch0            8U
#define VectorNumber_Vrti               7U
#define VectorNumber_Virq               6U
#define VectorNumber_Vxirq              5U
#define VectorNumber_Vswi               4U
#define VectorNumber_Vtrap              3U
#define VectorNumber_Vcop               2U
#define VectorNumber_Vclkmon            1U
#define VectorNumber_Vreset             0U

/**************** interrupt vector table ****************/
#define Vsi                             0xFF10U
#define Vsyscall                        0xFF12U
#define VReserved118                    0xFF14U
#define VReserved117                    0xFF16U
#define VReserved116                    0xFF18U
#define VReserved115                    0xFF1AU
#define VReserved114                    0xFF1CU
#define VReserved113                    0xFF1EU
#define VReserved112                    0xFF20U
#define VReserved111                    0xFF22U
#define VReserved110                    0xFF24U
#define VReserved109                    0xFF26U
#define VReserved108                    0xFF28U
#define VReserved107                    0xFF2AU
#define VReserved106                    0xFF2CU
#define VReserved105                    0xFF2EU
#define VReserved104                    0xFF30U
#define VReserved103                    0xFF32U
#define VReserved102                    0xFF34U
#define VReserved101                    0xFF36U
#define VReserved100                    0xFF38U
#define VReserved99                     0xFF3AU
#define VReserved98                     0xFF3CU
#define Vatd0compare                    0xFF3EU
#define VReserved96                     0xFF40U
#define VReserved95                     0xFF42U
#define VReserved94                     0xFF44U
#define VReserved93                     0xFF46U
#define VReserved92                     0xFF48U
#define VReserved91                     0xFF4AU
#define VReserved90                     0xFF4CU
#define VReserved89                     0xFF4EU
#define VReserved88                     0xFF50U
#define VReserved87                     0xFF52U
#define VReserved86                     0xFF54U
#define VReserved85                     0xFF56U
#define VReserved84                     0xFF58U
#define VReserved83                     0xFF5AU
#define VReserved82                     0xFF5CU
#define VReserved81                     0xFF5EU
#define VReserved79                     0xFF60U
#define VReserved78                     0xFF62U
#define VReserved77                     0xFF64U
#define VReserved76                     0xFF66U
#define VReserved75                     0xFF68U
#define VReserved74                     0xFF6AU
#define VReserved73                     0xFF6CU
#define VReserved72                     0xFF6EU
#define VReserved71                     0xFF70U
#define VReserved70                     0xFF72U
#define Vpit3                           0xFF74U
#define Vpit2                           0xFF76U
#define Vpit1                           0xFF78U
#define Vpit0                           0xFF7AU
#define Vhti                            0xFF7CU
#define Vapi                            0xFF7EU
#define Vlvi                            0xFF80U
#define VReserved62                     0xFF82U
#define VReserved61                     0xFF84U
#define VReserved60                     0xFF86U
#define VReserved59                     0xFF88U
#define VReserved58                     0xFF8AU
#define Vpwmesdn                        0xFF8CU
#define Vportp                          0xFF8EU
#define VReserved55                     0xFF90U
#define VReserved54                     0xFF92U
#define VReserved53                     0xFF94U
#define VReserved52                     0xFF96U
#define VReserved51                     0xFF98U
#define VReserved50                     0xFF9AU
#define VReserved49                     0xFF9CU
#define VReserved48                     0xFF9EU
#define VReserved47                     0xFFA0U
#define VReserved46                     0xFFA2U
#define VReserved45                     0xFFA4U
#define VReserved44                     0xFFA6U
#define VReserved43                     0xFFA8U
#define VReserved42                     0xFFAAU
#define VReserved41                     0xFFACU
#define VReserved40                     0xFFAEU
#define Vcan0tx                         0xFFB0U
#define Vcan0rx                         0xFFB2U
#define Vcan0err                        0xFFB4U
#define Vcan0wkup                       0xFFB6U
#define Vflash                          0xFFB8U
#define Vflashfd                        0xFFBAU
#define VReserved33                     0xFFBCU
#define VReserved32                     0xFFBEU
#define VReserved31                     0xFFC0U
#define VReserved30                     0xFFC2U
#define Vcrgscm                         0xFFC4U
#define Vcrgplllck                      0xFFC6U
#define VReserved27                     0xFFC8U
#define VReserved26                     0xFFCAU
#define Vporth                          0xFFCCU
#define Vportj                          0xFFCEU
#define VReserved23                     0xFFD0U
#define Vatd0                           0xFFD2U
#define Vsci1                           0xFFD4U
#define Vsci0                           0xFFD6U
#define Vspi0                           0xFFD8U
#define Vtimpaie                        0xFFDAU
#define Vtimpaaovf                      0xFFDCU
#define Vtimovf                         0xFFDEU
#define Vtimch7                         0xFFE0U
#define Vtimch6                         0xFFE2U
#define Vtimch5                         0xFFE4U
#define Vtimch4                         0xFFE6U
#define Vtimch3                         0xFFE8U
#define Vtimch2                         0xFFEAU
#define Vtimch1                         0xFFECU
#define Vtimch0                         0xFFEEU
#define Vrti                            0xFFF0U
#define Virq                            0xFFF2U
#define Vxirq                           0xFFF4U
#define Vswi                            0xFFF6U
#define Vtrap                           0xFFF8U
#define Vcop                            0xFFFAU
#define Vclkmon                         0xFFFCU
#define Vreset                          0xFFFEU

/**************** registers I/O map ****************/

/*** PORTAB - Port AB Data Register; 0x00000000 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PORTA - Port A Data Register; 0x00000000 ***/
    union {
      byte Byte;
      struct {
        byte PA0         :1;                                       /* Port A Bit 0 */
        byte PA1         :1;                                       /* Port A Bit 1 */
        byte PA2         :1;                                       /* Port A Bit 2 */
        byte PA3         :1;                                       /* Port A Bit 3 */
        byte PA4         :1;                                       /* Port A Bit 4 */
        byte PA5         :1;                                       /* Port A Bit 5 */
        byte PA6         :1;                                       /* Port A Bit 6 */
        byte PA7         :1;                                       /* Port A Bit 7 */
      } Bits;
    } PORTASTR;
    #define PORTA                       _PORTAB.Overlap_STR.PORTASTR.Byte
    #define PORTA_PA0                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA0
    #define PORTA_PA1                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA1
    #define PORTA_PA2                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA2
    #define PORTA_PA3                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA3
    #define PORTA_PA4                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA4
    #define PORTA_PA5                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA5
    #define PORTA_PA6                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA6
    #define PORTA_PA7                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA7
    
    #define PORTA_PA0_MASK              1U
    #define PORTA_PA1_MASK              2U
    #define PORTA_PA2_MASK              4U
    #define PORTA_PA3_MASK              8U
    #define PORTA_PA4_MASK              16U
    #define PORTA_PA5_MASK              32U
    #define PORTA_PA6_MASK              64U
    #define PORTA_PA7_MASK              128U
    

    /*** PORTB - Port B Data Register; 0x00000001 ***/
    union {
      byte Byte;
      struct {
        byte PB0         :1;                                       /* Port B Bit 0 */
        byte PB1         :1;                                       /* Port B Bit 1 */
        byte PB2         :1;                                       /* Port B Bit 2 */
        byte PB3         :1;                                       /* Port B Bit 3 */
        byte PB4         :1;                                       /* Port B Bit 4 */
        byte PB5         :1;                                       /* Port B Bit 5 */
        byte PB6         :1;                                       /* Port B Bit 6 */
        byte PB7         :1;                                       /* Port B Bit 7 */
      } Bits;
    } PORTBSTR;
    #define PORTB                       _PORTAB.Overlap_STR.PORTBSTR.Byte
    #define PORTB_PB0                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB0
    #define PORTB_PB1                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB1
    #define PORTB_PB2                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB2
    #define PORTB_PB3                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB3
    #define PORTB_PB4                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB4
    #define PORTB_PB5                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB5
    #define PORTB_PB6                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB6
    #define PORTB_PB7                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB7
    
    #define PORTB_PB0_MASK              1U
    #define PORTB_PB1_MASK              2U
    #define PORTB_PB2_MASK              4U
    #define PORTB_PB3_MASK              8U
    #define PORTB_PB4_MASK              16U
    #define PORTB_PB5_MASK              32U
    #define PORTB_PB6_MASK              64U
    #define PORTB_PB7_MASK              128U
    
  } Overlap_STR;

  struct {
    word PB0         :1;                                       /* Port B Bit 0 */
    word PB1         :1;                                       /* Port B Bit 1 */
    word PB2         :1;                                       /* Port B Bit 2 */
    word PB3         :1;                                       /* Port B Bit 3 */
    word PB4         :1;                                       /* Port B Bit 4 */
    word PB5         :1;                                       /* Port B Bit 5 */
    word PB6         :1;                                       /* Port B Bit 6 */
    word PB7         :1;                                       /* Port B Bit 7 */
    word PA0         :1;                                       /* Port A Bit 0 */
    word PA1         :1;                                       /* Port A Bit 1 */
    word PA2         :1;                                       /* Port A Bit 2 */
    word PA3         :1;                                       /* Port A Bit 3 */
    word PA4         :1;                                       /* Port A Bit 4 */
    word PA5         :1;                                       /* Port A Bit 5 */
    word PA6         :1;                                       /* Port A Bit 6 */
    word PA7         :1;                                       /* Port A Bit 7 */
  } Bits;
  struct {
    word grpPB   :8;
    word grpPA   :8;
  } MergedBits;
} PORTABSTR;
extern volatile PORTABSTR _PORTAB @(REG_BASE + 0x00000000UL);
#define PORTAB                          _PORTAB.Word
#define PORTAB_PB0                      _PORTAB.Bits.PB0
#define PORTAB_PB1                      _PORTAB.Bits.PB1
#define PORTAB_PB2                      _PORTAB.Bits.PB2
#define PORTAB_PB3                      _PORTAB.Bits.PB3
#define PORTAB_PB4                      _PORTAB.Bits.PB4
#define PORTAB_PB5                      _PORTAB.Bits.PB5
#define PORTAB_PB6                      _PORTAB.Bits.PB6
#define PORTAB_PB7                      _PORTAB.Bits.PB7
#define PORTAB_PA0                      _PORTAB.Bits.PA0
#define PORTAB_PA1                      _PORTAB.Bits.PA1
#define PORTAB_PA2                      _PORTAB.Bits.PA2
#define PORTAB_PA3                      _PORTAB.Bits.PA3
#define PORTAB_PA4                      _PORTAB.Bits.PA4
#define PORTAB_PA5                      _PORTAB.Bits.PA5
#define PORTAB_PA6                      _PORTAB.Bits.PA6
#define PORTAB_PA7                      _PORTAB.Bits.PA7
#define PORTAB_PB                       _PORTAB.MergedBits.grpPB
#define PORTAB_PA                       _PORTAB.MergedBits.grpPA

#define PORTAB_PB0_MASK                 1U
#define PORTAB_PB1_MASK                 2U
#define PORTAB_PB2_MASK                 4U
#define PORTAB_PB3_MASK                 8U
#define PORTAB_PB4_MASK                 16U
#define PORTAB_PB5_MASK                 32U
#define PORTAB_PB6_MASK                 64U
#define PORTAB_PB7_MASK                 128U
#define PORTAB_PA0_MASK                 256U
#define PORTAB_PA1_MASK                 512U
#define PORTAB_PA2_MASK                 1024U
#define PORTAB_PA3_MASK                 2048U
#define PORTAB_PA4_MASK                 4096U
#define PORTAB_PA5_MASK                 8192U
#define PORTAB_PA6_MASK                 16384U
#define PORTAB_PA7_MASK                 32768U
#define PORTAB_PB_MASK                  255U
#define PORTAB_PB_BITNUM                0U
#define PORTAB_PA_MASK                  65280U
#define PORTAB_PA_BITNUM                8U


/*** DDRAB - Port AB Data Direction Register; 0x00000002 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DDRA - Port A Data Direction Register; 0x00000002 ***/
    union {
      byte Byte;
      struct {
        byte DDRA0       :1;                                       /* Data Direction Port A Bit 0 */
        byte DDRA1       :1;                                       /* Data Direction Port A Bit 1 */
        byte DDRA2       :1;                                       /* Data Direction Port A Bit 2 */
        byte DDRA3       :1;                                       /* Data Direction Port A Bit 3 */
        byte DDRA4       :1;                                       /* Data Direction Port A Bit 4 */
        byte DDRA5       :1;                                       /* Data Direction Port A Bit 5 */
        byte DDRA6       :1;                                       /* Data Direction Port A Bit 6 */
        byte DDRA7       :1;                                       /* Data Direction Port A Bit 7 */
      } Bits;
    } DDRASTR;
    #define DDRA                        _DDRAB.Overlap_STR.DDRASTR.Byte
    #define DDRA_DDRA0                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA0
    #define DDRA_DDRA1                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA1
    #define DDRA_DDRA2                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA2
    #define DDRA_DDRA3                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA3
    #define DDRA_DDRA4                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA4
    #define DDRA_DDRA5                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA5
    #define DDRA_DDRA6                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA6
    #define DDRA_DDRA7                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA7
    
    #define DDRA_DDRA0_MASK             1U
    #define DDRA_DDRA1_MASK             2U
    #define DDRA_DDRA2_MASK             4U
    #define DDRA_DDRA3_MASK             8U
    #define DDRA_DDRA4_MASK             16U
    #define DDRA_DDRA5_MASK             32U
    #define DDRA_DDRA6_MASK             64U
    #define DDRA_DDRA7_MASK             128U
    

    /*** DDRB - Port B Data Direction Register; 0x00000003 ***/
    union {
      byte Byte;
      struct {
        byte DDRB0       :1;                                       /* Data Direction Port B Bit 0 */
        byte DDRB1       :1;                                       /* Data Direction Port B Bit 1 */
        byte DDRB2       :1;                                       /* Data Direction Port B Bit 2 */
        byte DDRB3       :1;                                       /* Data Direction Port B Bit 3 */
        byte DDRB4       :1;                                       /* Data Direction Port B Bit 4 */
        byte DDRB5       :1;                                       /* Data Direction Port B Bit 5 */
        byte DDRB6       :1;                                       /* Data Direction Port B Bit 6 */
        byte DDRB7       :1;                                       /* Data Direction Port B Bit 7 */
      } Bits;
    } DDRBSTR;
    #define DDRB                        _DDRAB.Overlap_STR.DDRBSTR.Byte
    #define DDRB_DDRB0                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB0
    #define DDRB_DDRB1                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB1
    #define DDRB_DDRB2                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB2
    #define DDRB_DDRB3                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB3
    #define DDRB_DDRB4                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB4
    #define DDRB_DDRB5                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB5
    #define DDRB_DDRB6                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB6
    #define DDRB_DDRB7                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB7
    
    #define DDRB_DDRB0_MASK             1U
    #define DDRB_DDRB1_MASK             2U
    #define DDRB_DDRB2_MASK             4U
    #define DDRB_DDRB3_MASK             8U
    #define DDRB_DDRB4_MASK             16U
    #define DDRB_DDRB5_MASK             32U
    #define DDRB_DDRB6_MASK             64U
    #define DDRB_DDRB7_MASK             128U
    
  } Overlap_STR;

  struct {
    word DDRB0       :1;                                       /* Data Direction Port B Bit 0 */
    word DDRB1       :1;                                       /* Data Direction Port B Bit 1 */
    word DDRB2       :1;                                       /* Data Direction Port B Bit 2 */
    word DDRB3       :1;                                       /* Data Direction Port B Bit 3 */
    word DDRB4       :1;                                       /* Data Direction Port B Bit 4 */
    word DDRB5       :1;                                       /* Data Direction Port B Bit 5 */
    word DDRB6       :1;                                       /* Data Direction Port B Bit 6 */
    word DDRB7       :1;                                       /* Data Direction Port B Bit 7 */
    word DDRA0       :1;                                       /* Data Direction Port A Bit 0 */
    word DDRA1       :1;                                       /* Data Direction Port A Bit 1 */
    word DDRA2       :1;                                       /* Data Direction Port A Bit 2 */
    word DDRA3       :1;                                       /* Data Direction Port A Bit 3 */
    word DDRA4       :1;                                       /* Data Direction Port A Bit 4 */
    word DDRA5       :1;                                       /* Data Direction Port A Bit 5 */
    word DDRA6       :1;                                       /* Data Direction Port A Bit 6 */
    word DDRA7       :1;                                       /* Data Direction Port A Bit 7 */
  } Bits;
  struct {
    word grpDDRB :8;
    word grpDDRA :8;
  } MergedBits;
} DDRABSTR;
extern volatile DDRABSTR _DDRAB @(REG_BASE + 0x00000002UL);
#define DDRAB                           _DDRAB.Word
#define DDRAB_DDRB0                     _DDRAB.Bits.DDRB0
#define DDRAB_DDRB1                     _DDRAB.Bits.DDRB1
#define DDRAB_DDRB2                     _DDRAB.Bits.DDRB2
#define DDRAB_DDRB3                     _DDRAB.Bits.DDRB3
#define DDRAB_DDRB4                     _DDRAB.Bits.DDRB4
#define DDRAB_DDRB5                     _DDRAB.Bits.DDRB5
#define DDRAB_DDRB6                     _DDRAB.Bits.DDRB6
#define DDRAB_DDRB7                     _DDRAB.Bits.DDRB7
#define DDRAB_DDRA0                     _DDRAB.Bits.DDRA0
#define DDRAB_DDRA1                     _DDRAB.Bits.DDRA1
#define DDRAB_DDRA2                     _DDRAB.Bits.DDRA2
#define DDRAB_DDRA3                     _DDRAB.Bits.DDRA3
#define DDRAB_DDRA4                     _DDRAB.Bits.DDRA4
#define DDRAB_DDRA5                     _DDRAB.Bits.DDRA5
#define DDRAB_DDRA6                     _DDRAB.Bits.DDRA6
#define DDRAB_DDRA7                     _DDRAB.Bits.DDRA7
#define DDRAB_DDRB                      _DDRAB.MergedBits.grpDDRB
#define DDRAB_DDRA                      _DDRAB.MergedBits.grpDDRA

#define DDRAB_DDRB0_MASK                1U
#define DDRAB_DDRB1_MASK                2U
#define DDRAB_DDRB2_MASK                4U
#define DDRAB_DDRB3_MASK                8U
#define DDRAB_DDRB4_MASK                16U
#define DDRAB_DDRB5_MASK                32U
#define DDRAB_DDRB6_MASK                64U
#define DDRAB_DDRB7_MASK                128U
#define DDRAB_DDRA0_MASK                256U
#define DDRAB_DDRA1_MASK                512U
#define DDRAB_DDRA2_MASK                1024U
#define DDRAB_DDRA3_MASK                2048U
#define DDRAB_DDRA4_MASK                4096U
#define DDRAB_DDRA5_MASK                8192U
#define DDRAB_DDRA6_MASK                16384U
#define DDRAB_DDRA7_MASK                32768U
#define DDRAB_DDRB_MASK                 255U
#define DDRAB_DDRB_BITNUM               0U
#define DDRAB_DDRA_MASK                 65280U
#define DDRAB_DDRA_BITNUM               8U


/*** PORTE - Port E Data Register; 0x00000008 ***/
typedef union {
  byte Byte;
  struct {
    byte PE0         :1;                                       /* Port E Bit 0 */
    byte PE1         :1;                                       /* Port E Bit 1 */
    byte PE2         :1;                                       /* Port E Bit 2 */
    byte PE3         :1;                                       /* Port E Bit 3 */
    byte PE4         :1;                                       /* Port E Bit 4 */
    byte PE5         :1;                                       /* Port E Bit 5 */
    byte PE6         :1;                                       /* Port E Bit 6 */
    byte PE7         :1;                                       /* Port E Bit 7 */
  } Bits;
} PORTESTR;
extern volatile PORTESTR _PORTE @(REG_BASE + 0x00000008UL);
#define PORTE                           _PORTE.Byte
#define PORTE_PE0                       _PORTE.Bits.PE0
#define PORTE_PE1                       _PORTE.Bits.PE1
#define PORTE_PE2                       _PORTE.Bits.PE2
#define PORTE_PE3                       _PORTE.Bits.PE3
#define PORTE_PE4                       _PORTE.Bits.PE4
#define PORTE_PE5                       _PORTE.Bits.PE5
#define PORTE_PE6                       _PORTE.Bits.PE6
#define PORTE_PE7                       _PORTE.Bits.PE7

#define PORTE_PE0_MASK                  1U
#define PORTE_PE1_MASK                  2U
#define PORTE_PE2_MASK                  4U
#define PORTE_PE3_MASK                  8U
#define PORTE_PE4_MASK                  16U
#define PORTE_PE5_MASK                  32U
#define PORTE_PE6_MASK                  64U
#define PORTE_PE7_MASK                  128U


/*** DDRE - Port E Data Direction Register; 0x00000009 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte DDRE2       :1;                                       /* Data Direction Port E Bit 2 */
    byte DDRE3       :1;                                       /* Data Direction Port E Bit 3 */
    byte DDRE4       :1;                                       /* Data Direction Port E Bit 4 */
    byte DDRE5       :1;                                       /* Data Direction Port E Bit 5 */
    byte DDRE6       :1;                                       /* Data Direction Port E Bit 6 */
    byte DDRE7       :1;                                       /* Data Direction Port E Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpDDRE_2 :6;
  } MergedBits;
} DDRESTR;
extern volatile DDRESTR _DDRE @(REG_BASE + 0x00000009UL);
#define DDRE                            _DDRE.Byte
#define DDRE_DDRE2                      _DDRE.Bits.DDRE2
#define DDRE_DDRE3                      _DDRE.Bits.DDRE3
#define DDRE_DDRE4                      _DDRE.Bits.DDRE4
#define DDRE_DDRE5                      _DDRE.Bits.DDRE5
#define DDRE_DDRE6                      _DDRE.Bits.DDRE6
#define DDRE_DDRE7                      _DDRE.Bits.DDRE7
#define DDRE_DDRE_2                     _DDRE.MergedBits.grpDDRE_2

#define DDRE_DDRE2_MASK                 4U
#define DDRE_DDRE3_MASK                 8U
#define DDRE_DDRE4_MASK                 16U
#define DDRE_DDRE5_MASK                 32U
#define DDRE_DDRE6_MASK                 64U
#define DDRE_DDRE7_MASK                 128U
#define DDRE_DDRE_2_MASK                252U
#define DDRE_DDRE_2_BITNUM              2U


/*** MODE - Mode Register; 0x0000000B ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODC        :1;                                       /* Mode Select Bit */
  } Bits;
} MODESTR;
extern volatile MODESTR _MODE @(REG_BASE + 0x0000000BUL);
#define MODE                            _MODE.Byte
#define MODE_MODC                       _MODE.Bits.MODC

#define MODE_MODC_MASK                  128U


/*** PUCR - Pull-Up Control Register; 0x0000000C ***/
typedef union {
  byte Byte;
  struct {
    byte PUPAE       :1;                                       /* Pull-up Port A Enable */
    byte PUPBE       :1;                                       /* Pull-up Port B Enable */
    byte             :1; 
    byte             :1; 
    byte PUPEE       :1;                                       /* Pull-up Port E Enable */
    byte             :1; 
    byte BKPUE       :1;                                       /* BKGD and VREGEN Pin Pull-up Enable */
    byte PUPKE       :1;                                       /* Pull-up Port K Enable */
  } Bits;
} PUCRSTR;
extern volatile PUCRSTR _PUCR @(REG_BASE + 0x0000000CUL);
#define PUCR                            _PUCR.Byte
#define PUCR_PUPAE                      _PUCR.Bits.PUPAE
#define PUCR_PUPBE                      _PUCR.Bits.PUPBE
#define PUCR_PUPEE                      _PUCR.Bits.PUPEE
#define PUCR_BKPUE                      _PUCR.Bits.BKPUE
#define PUCR_PUPKE                      _PUCR.Bits.PUPKE

#define PUCR_PUPAE_MASK                 1U
#define PUCR_PUPBE_MASK                 2U
#define PUCR_PUPEE_MASK                 16U
#define PUCR_BKPUE_MASK                 64U
#define PUCR_PUPKE_MASK                 128U


/*** RDRIV - Reduced Drive Register; 0x0000000D ***/
typedef union {
  byte Byte;
  struct {
    byte RDPA        :1;                                       /* Reduced Drive of Port A */
    byte RDPB        :1;                                       /* Reduced Drive of Port B */
    byte             :1; 
    byte             :1; 
    byte RDPE        :1;                                       /* Reduced Drive of Port E */
    byte             :1; 
    byte             :1; 
    byte RDPK        :1;                                       /* Reduced Drive of Port K */
  } Bits;
  struct {
    byte grpRDPx :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} RDRIVSTR;
extern volatile RDRIVSTR _RDRIV @(REG_BASE + 0x0000000DUL);
#define RDRIV                           _RDRIV.Byte
#define RDRIV_RDPA                      _RDRIV.Bits.RDPA
#define RDRIV_RDPB                      _RDRIV.Bits.RDPB
#define RDRIV_RDPE                      _RDRIV.Bits.RDPE
#define RDRIV_RDPK                      _RDRIV.Bits.RDPK
#define RDRIV_RDPx                      _RDRIV.MergedBits.grpRDPx

#define RDRIV_RDPA_MASK                 1U
#define RDRIV_RDPB_MASK                 2U
#define RDRIV_RDPE_MASK                 16U
#define RDRIV_RDPK_MASK                 128U
#define RDRIV_RDPx_MASK                 3U
#define RDRIV_RDPx_BITNUM               0U


/*** GPAGE - Global Page Index Register; 0x00000010 ***/
typedef union {
  byte Byte;
  struct {
    byte GP0         :1;                                       /* Global Page Index Bit 0 */
    byte GP1         :1;                                       /* Global Page Index Bit 1 */
    byte GP2         :1;                                       /* Global Page Index Bit 2 */
    byte GP3         :1;                                       /* Global Page Index Bit 3 */
    byte GP4         :1;                                       /* Global Page Index Bit 4 */
    byte GP5         :1;                                       /* Global Page Index Bit 5 */
    byte GP6         :1;                                       /* Global Page Index Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpGP   :7;
    byte         :1;
  } MergedBits;
} GPAGESTR;
extern volatile GPAGESTR _GPAGE @(REG_BASE + 0x00000010UL);
#define GPAGE                           _GPAGE.Byte
#define GPAGE_GP0                       _GPAGE.Bits.GP0
#define GPAGE_GP1                       _GPAGE.Bits.GP1
#define GPAGE_GP2                       _GPAGE.Bits.GP2
#define GPAGE_GP3                       _GPAGE.Bits.GP3
#define GPAGE_GP4                       _GPAGE.Bits.GP4
#define GPAGE_GP5                       _GPAGE.Bits.GP5
#define GPAGE_GP6                       _GPAGE.Bits.GP6
#define GPAGE_GP                        _GPAGE.MergedBits.grpGP

#define GPAGE_GP0_MASK                  1U
#define GPAGE_GP1_MASK                  2U
#define GPAGE_GP2_MASK                  4U
#define GPAGE_GP3_MASK                  8U
#define GPAGE_GP4_MASK                  16U
#define GPAGE_GP5_MASK                  32U
#define GPAGE_GP6_MASK                  64U
#define GPAGE_GP_MASK                   127U
#define GPAGE_GP_BITNUM                 0U


/*** DIRECT - Direct Page Register; 0x00000011 ***/
typedef union {
  byte Byte;
  struct {
    byte DP8         :1;                                       /* Direct Page Index Bit 8 */
    byte DP9         :1;                                       /* Direct Page Index Bit 9 */
    byte DP10        :1;                                       /* Direct Page Index Bit 10 */
    byte DP11        :1;                                       /* Direct Page Index Bit 11 */
    byte DP12        :1;                                       /* Direct Page Index Bit 12 */
    byte DP13        :1;                                       /* Direct Page Index Bit 13 */
    byte DP14        :1;                                       /* Direct Page Index Bit 14 */
    byte DP15        :1;                                       /* Direct Page Index Bit 15 */
  } Bits;
} DIRECTSTR;
extern volatile DIRECTSTR _DIRECT @(REG_BASE + 0x00000011UL);
#define DIRECT                          _DIRECT.Byte
#define DIRECT_DP8                      _DIRECT.Bits.DP8
#define DIRECT_DP9                      _DIRECT.Bits.DP9
#define DIRECT_DP10                     _DIRECT.Bits.DP10
#define DIRECT_DP11                     _DIRECT.Bits.DP11
#define DIRECT_DP12                     _DIRECT.Bits.DP12
#define DIRECT_DP13                     _DIRECT.Bits.DP13
#define DIRECT_DP14                     _DIRECT.Bits.DP14
#define DIRECT_DP15                     _DIRECT.Bits.DP15

#define DIRECT_DP8_MASK                 1U
#define DIRECT_DP9_MASK                 2U
#define DIRECT_DP10_MASK                4U
#define DIRECT_DP11_MASK                8U
#define DIRECT_DP12_MASK                16U
#define DIRECT_DP13_MASK                32U
#define DIRECT_DP14_MASK                64U
#define DIRECT_DP15_MASK                128U


/*** MMCCTL1 - MMC Control Register; 0x00000013 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PGMIFRON    :1;                                       /* Program Flash Information Row (IFR) visible in the global memory map */
    byte DFIFRON     :1;                                       /* Data Flash Information Row (IFR) visible in the global memory map */
    byte             :1; 
    byte MGRAMON     :1;                                       /* Flash Memory Controller SCRATCH RAM visible in the global memory map */
  } Bits;
} MMCCTL1STR;
extern volatile MMCCTL1STR _MMCCTL1 @(REG_BASE + 0x00000013UL);
#define MMCCTL1                         _MMCCTL1.Byte
#define MMCCTL1_PGMIFRON                _MMCCTL1.Bits.PGMIFRON
#define MMCCTL1_DFIFRON                 _MMCCTL1.Bits.DFIFRON
#define MMCCTL1_MGRAMON                 _MMCCTL1.Bits.MGRAMON

#define MMCCTL1_PGMIFRON_MASK           16U
#define MMCCTL1_DFIFRON_MASK            32U
#define MMCCTL1_MGRAMON_MASK            128U


/*** PPAGE - Program Page Index Register; 0x00000015 ***/
typedef union {
  byte Byte;
  struct {
    byte PIX0        :1;                                       /* Program Page Index Bit 0 */
    byte PIX1        :1;                                       /* Program Page Index Bit 1 */
    byte PIX2        :1;                                       /* Program Page Index Bit 2 */
    byte PIX3        :1;                                       /* Program Page Index Bit 3 */
    byte PIX4        :1;                                       /* Program Page Index Bit 4 */
    byte PIX5        :1;                                       /* Program Page Index Bit 5 */
    byte PIX6        :1;                                       /* Program Page Index Bit 6 */
    byte PIX7        :1;                                       /* Program Page Index Bit 7 */
  } Bits;
} PPAGESTR;
extern volatile PPAGESTR _PPAGE @(REG_BASE + 0x00000015UL);
#define PPAGE                           _PPAGE.Byte
#define PPAGE_PIX0                      _PPAGE.Bits.PIX0
#define PPAGE_PIX1                      _PPAGE.Bits.PIX1
#define PPAGE_PIX2                      _PPAGE.Bits.PIX2
#define PPAGE_PIX3                      _PPAGE.Bits.PIX3
#define PPAGE_PIX4                      _PPAGE.Bits.PIX4
#define PPAGE_PIX5                      _PPAGE.Bits.PIX5
#define PPAGE_PIX6                      _PPAGE.Bits.PIX6
#define PPAGE_PIX7                      _PPAGE.Bits.PIX7

#define PPAGE_PIX0_MASK                 1U
#define PPAGE_PIX1_MASK                 2U
#define PPAGE_PIX2_MASK                 4U
#define PPAGE_PIX3_MASK                 8U
#define PPAGE_PIX4_MASK                 16U
#define PPAGE_PIX5_MASK                 32U
#define PPAGE_PIX6_MASK                 64U
#define PPAGE_PIX7_MASK                 128U


/*** RPAGE - RAM Page Index Register; 0x00000016 ***/
typedef union {
  byte Byte;
  struct {
    byte RP0         :1;                                       /* RAM Page Index Bit 0 */
    byte RP1         :1;                                       /* RAM Page Index Bit 1 */
    byte RP2         :1;                                       /* RAM Page Index Bit 2 */
    byte RP3         :1;                                       /* RAM Page Index Bit 3 */
    byte RP4         :1;                                       /* RAM Page Index Bit 4 */
    byte RP5         :1;                                       /* RAM Page Index Bit 5 */
    byte RP6         :1;                                       /* RAM Page Index Bit 6 */
    byte RP7         :1;                                       /* RAM Page Index Bit 7 */
  } Bits;
} RPAGESTR;
extern volatile RPAGESTR _RPAGE @(REG_BASE + 0x00000016UL);
#define RPAGE                           _RPAGE.Byte
#define RPAGE_RP0                       _RPAGE.Bits.RP0
#define RPAGE_RP1                       _RPAGE.Bits.RP1
#define RPAGE_RP2                       _RPAGE.Bits.RP2
#define RPAGE_RP3                       _RPAGE.Bits.RP3
#define RPAGE_RP4                       _RPAGE.Bits.RP4
#define RPAGE_RP5                       _RPAGE.Bits.RP5
#define RPAGE_RP6                       _RPAGE.Bits.RP6
#define RPAGE_RP7                       _RPAGE.Bits.RP7

#define RPAGE_RP0_MASK                  1U
#define RPAGE_RP1_MASK                  2U
#define RPAGE_RP2_MASK                  4U
#define RPAGE_RP3_MASK                  8U
#define RPAGE_RP4_MASK                  16U
#define RPAGE_RP5_MASK                  32U
#define RPAGE_RP6_MASK                  64U
#define RPAGE_RP7_MASK                  128U


/*** EPAGE - Data FLASH Page Index Register; 0x00000017 ***/
typedef union {
  byte Byte;
  struct {
    byte EP0         :1;                                       /* Data FLASH Page Index Bit 0 */
    byte EP1         :1;                                       /* Data FLASH Page Index Bit 1 */
    byte EP2         :1;                                       /* Data FLASH Page Index Bit 2 */
    byte EP3         :1;                                       /* Data FLASH Page Index Bit 3 */
    byte EP4         :1;                                       /* Data FLASH Page Index Bit 4 */
    byte EP5         :1;                                       /* Data FLASH Page Index Bit 5 */
    byte EP6         :1;                                       /* Data FLASH Page Index Bit 6 */
    byte EP7         :1;                                       /* Data FLASH Page Index Bit 7 */
  } Bits;
} EPAGESTR;
extern volatile EPAGESTR _EPAGE @(REG_BASE + 0x00000017UL);
#define EPAGE                           _EPAGE.Byte
#define EPAGE_EP0                       _EPAGE.Bits.EP0
#define EPAGE_EP1                       _EPAGE.Bits.EP1
#define EPAGE_EP2                       _EPAGE.Bits.EP2
#define EPAGE_EP3                       _EPAGE.Bits.EP3
#define EPAGE_EP4                       _EPAGE.Bits.EP4
#define EPAGE_EP5                       _EPAGE.Bits.EP5
#define EPAGE_EP6                       _EPAGE.Bits.EP6
#define EPAGE_EP7                       _EPAGE.Bits.EP7

#define EPAGE_EP0_MASK                  1U
#define EPAGE_EP1_MASK                  2U
#define EPAGE_EP2_MASK                  4U
#define EPAGE_EP3_MASK                  8U
#define EPAGE_EP4_MASK                  16U
#define EPAGE_EP5_MASK                  32U
#define EPAGE_EP6_MASK                  64U
#define EPAGE_EP7_MASK                  128U


/*** PARTID - Part ID Register; 0x0000001A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PARTIDH - Part ID Register High; 0x0000001A ***/
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       /* Part ID Register Bit 8 */
        byte ID9         :1;                                       /* Part ID Register Bit 9 */
        byte ID10        :1;                                       /* Part ID Register Bit 10 */
        byte ID11        :1;                                       /* Part ID Register Bit 11 */
        byte ID12        :1;                                       /* Part ID Register Bit 12 */
        byte ID13        :1;                                       /* Part ID Register Bit 13 */
        byte ID14        :1;                                       /* Part ID Register Bit 14 */
        byte ID15        :1;                                       /* Part ID Register Bit 15 */
      } Bits;
    } PARTIDHSTR;
    #define PARTIDH                     _PARTID.Overlap_STR.PARTIDHSTR.Byte
    #define PARTIDH_ID8                 _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID8
    #define PARTIDH_ID9                 _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID9
    #define PARTIDH_ID10                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID10
    #define PARTIDH_ID11                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID11
    #define PARTIDH_ID12                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID12
    #define PARTIDH_ID13                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID13
    #define PARTIDH_ID14                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID14
    #define PARTIDH_ID15                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID15
    
    #define PARTIDH_ID8_MASK            1U
    #define PARTIDH_ID9_MASK            2U
    #define PARTIDH_ID10_MASK           4U
    #define PARTIDH_ID11_MASK           8U
    #define PARTIDH_ID12_MASK           16U
    #define PARTIDH_ID13_MASK           32U
    #define PARTIDH_ID14_MASK           64U
    #define PARTIDH_ID15_MASK           128U
    

    /*** PARTIDL - Part ID Register Low; 0x0000001B ***/
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       /* Part ID Register Bit 0 */
        byte ID1         :1;                                       /* Part ID Register Bit 1 */
        byte ID2         :1;                                       /* Part ID Register Bit 2 */
        byte ID3         :1;                                       /* Part ID Register Bit 3 */
        byte ID4         :1;                                       /* Part ID Register Bit 4 */
        byte ID5         :1;                                       /* Part ID Register Bit 5 */
        byte ID6         :1;                                       /* Part ID Register Bit 6 */
        byte ID7         :1;                                       /* Part ID Register Bit 7 */
      } Bits;
    } PARTIDLSTR;
    #define PARTIDL                     _PARTID.Overlap_STR.PARTIDLSTR.Byte
    #define PARTIDL_ID0                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID0
    #define PARTIDL_ID1                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID1
    #define PARTIDL_ID2                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID2
    #define PARTIDL_ID3                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID3
    #define PARTIDL_ID4                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID4
    #define PARTIDL_ID5                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID5
    #define PARTIDL_ID6                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID6
    #define PARTIDL_ID7                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID7
    
    #define PARTIDL_ID0_MASK            1U
    #define PARTIDL_ID1_MASK            2U
    #define PARTIDL_ID2_MASK            4U
    #define PARTIDL_ID3_MASK            8U
    #define PARTIDL_ID4_MASK            16U
    #define PARTIDL_ID5_MASK            32U
    #define PARTIDL_ID6_MASK            64U
    #define PARTIDL_ID7_MASK            128U
    
  } Overlap_STR;

  struct {
    word ID0         :1;                                       /* Part ID Register Bit 0 */
    word ID1         :1;                                       /* Part ID Register Bit 1 */
    word ID2         :1;                                       /* Part ID Register Bit 2 */
    word ID3         :1;                                       /* Part ID Register Bit 3 */
    word ID4         :1;                                       /* Part ID Register Bit 4 */
    word ID5         :1;                                       /* Part ID Register Bit 5 */
    word ID6         :1;                                       /* Part ID Register Bit 6 */
    word ID7         :1;                                       /* Part ID Register Bit 7 */
    word ID8         :1;                                       /* Part ID Register Bit 8 */
    word ID9         :1;                                       /* Part ID Register Bit 9 */
    word ID10        :1;                                       /* Part ID Register Bit 10 */
    word ID11        :1;                                       /* Part ID Register Bit 11 */
    word ID12        :1;                                       /* Part ID Register Bit 12 */
    word ID13        :1;                                       /* Part ID Register Bit 13 */
    word ID14        :1;                                       /* Part ID Register Bit 14 */
    word ID15        :1;                                       /* Part ID Register Bit 15 */
  } Bits;
} PARTIDSTR;
extern volatile PARTIDSTR _PARTID @(REG_BASE + 0x0000001AUL);
#define PARTID                          _PARTID.Word
#define PARTID_ID0                      _PARTID.Bits.ID0
#define PARTID_ID1                      _PARTID.Bits.ID1
#define PARTID_ID2                      _PARTID.Bits.ID2
#define PARTID_ID3                      _PARTID.Bits.ID3
#define PARTID_ID4                      _PARTID.Bits.ID4
#define PARTID_ID5                      _PARTID.Bits.ID5
#define PARTID_ID6                      _PARTID.Bits.ID6
#define PARTID_ID7                      _PARTID.Bits.ID7
#define PARTID_ID8                      _PARTID.Bits.ID8
#define PARTID_ID9                      _PARTID.Bits.ID9
#define PARTID_ID10                     _PARTID.Bits.ID10
#define PARTID_ID11                     _PARTID.Bits.ID11
#define PARTID_ID12                     _PARTID.Bits.ID12
#define PARTID_ID13                     _PARTID.Bits.ID13
#define PARTID_ID14                     _PARTID.Bits.ID14
#define PARTID_ID15                     _PARTID.Bits.ID15

#define PARTID_ID0_MASK                 1U
#define PARTID_ID1_MASK                 2U
#define PARTID_ID2_MASK                 4U
#define PARTID_ID3_MASK                 8U
#define PARTID_ID4_MASK                 16U
#define PARTID_ID5_MASK                 32U
#define PARTID_ID6_MASK                 64U
#define PARTID_ID7_MASK                 128U
#define PARTID_ID8_MASK                 256U
#define PARTID_ID9_MASK                 512U
#define PARTID_ID10_MASK                1024U
#define PARTID_ID11_MASK                2048U
#define PARTID_ID12_MASK                4096U
#define PARTID_ID13_MASK                8192U
#define PARTID_ID14_MASK                16384U
#define PARTID_ID15_MASK                32768U


/*** ECLKCTL - ECLK Control Register; 0x0000001C ***/
typedef union {
  byte Byte;
  struct {
    byte EDIV0       :1;                                       /* Free-running ECLK Divider, bit 0 */
    byte EDIV1       :1;                                       /* Free-running ECLK Divider, bit 1 */
    byte EDIV2       :1;                                       /* Free-running ECLK Divider, bit 2 */
    byte EDIV3       :1;                                       /* Free-running ECLK Divider, bit 3 */
    byte EDIV4       :1;                                       /* Free-running ECLK Divider, bit 4 */
    byte DIV16       :1;                                       /* Free-running ECLK predivider */
    byte NCLKX2      :1;                                       /* No ECLKX2 */
    byte NECLK       :1;                                       /* No ECLK */
  } Bits;
  struct {
    byte grpEDIV :5;
    byte grpDIV_16 :1;
    byte grpNCLKX_2 :1;
    byte         :1;
  } MergedBits;
} ECLKCTLSTR;
extern volatile ECLKCTLSTR _ECLKCTL @(REG_BASE + 0x0000001CUL);
#define ECLKCTL                         _ECLKCTL.Byte
#define ECLKCTL_EDIV0                   _ECLKCTL.Bits.EDIV0
#define ECLKCTL_EDIV1                   _ECLKCTL.Bits.EDIV1
#define ECLKCTL_EDIV2                   _ECLKCTL.Bits.EDIV2
#define ECLKCTL_EDIV3                   _ECLKCTL.Bits.EDIV3
#define ECLKCTL_EDIV4                   _ECLKCTL.Bits.EDIV4
#define ECLKCTL_DIV16                   _ECLKCTL.Bits.DIV16
#define ECLKCTL_NCLKX2                  _ECLKCTL.Bits.NCLKX2
#define ECLKCTL_NECLK                   _ECLKCTL.Bits.NECLK
#define ECLKCTL_EDIV                    _ECLKCTL.MergedBits.grpEDIV

#define ECLKCTL_EDIV0_MASK              1U
#define ECLKCTL_EDIV1_MASK              2U
#define ECLKCTL_EDIV2_MASK              4U
#define ECLKCTL_EDIV3_MASK              8U
#define ECLKCTL_EDIV4_MASK              16U
#define ECLKCTL_DIV16_MASK              32U
#define ECLKCTL_NCLKX2_MASK             64U
#define ECLKCTL_NECLK_MASK              128U
#define ECLKCTL_EDIV_MASK               31U
#define ECLKCTL_EDIV_BITNUM             0U


/*** IRQCR - Interrupt Control Register; 0x0000001E ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte IRQEN       :1;                                       /* External IRQ Enable */
    byte IRQE        :1;                                       /* IRQ Select Edge Sensitive Only */
  } Bits;
} IRQCRSTR;
extern volatile IRQCRSTR _IRQCR @(REG_BASE + 0x0000001EUL);
#define IRQCR                           _IRQCR.Byte
#define IRQCR_IRQEN                     _IRQCR.Bits.IRQEN
#define IRQCR_IRQE                      _IRQCR.Bits.IRQE

#define IRQCR_IRQEN_MASK                64U
#define IRQCR_IRQE_MASK                 128U


/*** DBGC1 - Debug Control Register 1; 0x00000020 ***/
typedef union {
  byte Byte;
  struct {
    byte COMRV       :2;                                       /* Comparator Register Visibility Bits */
    byte             :1; 
    byte DBGBRK      :1;                                       /* S12XDBG Breakpoint Enable Bit 1 */
    byte BDM         :1;                                       /* Background Debug Mode Enable */
    byte             :1; 
    byte TRIG        :1;                                       /* Immediate Trigger Request Bit */
    byte ARM         :1;                                       /* Arm Bit */
  } Bits;
} DBGC1STR;
extern volatile DBGC1STR _DBGC1 @(REG_BASE + 0x00000020UL);
#define DBGC1                           _DBGC1.Byte
#define DBGC1_COMRV                     _DBGC1.Bits.COMRV
#define DBGC1_DBGBRK                    _DBGC1.Bits.DBGBRK
#define DBGC1_BDM                       _DBGC1.Bits.BDM
#define DBGC1_TRIG                      _DBGC1.Bits.TRIG
#define DBGC1_ARM                       _DBGC1.Bits.ARM

#define DBGC1_COMRV_MASK                3U
#define DBGC1_COMRV_BITNUM              0U
#define DBGC1_DBGBRK_MASK               8U
#define DBGC1_BDM_MASK                  16U
#define DBGC1_TRIG_MASK                 64U
#define DBGC1_ARM_MASK                  128U


/*** DBGSR - Debug Status Register; 0x00000021 ***/
typedef union {
  byte Byte;
  struct {
    byte SSF0        :1;                                       /* State Sequencer Flag Bits */
    byte SSF1        :1;                                       /* State Sequencer Flag Bit 1 */
    byte SSF2        :1;                                       /* State Sequencer Flag Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TBF         :1;                                       /* Trace Buffer Full */
  } Bits;
  struct {
    byte grpSSF  :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGSRSTR;
extern volatile DBGSRSTR _DBGSR @(REG_BASE + 0x00000021UL);
#define DBGSR                           _DBGSR.Byte
#define DBGSR_SSF0                      _DBGSR.Bits.SSF0
#define DBGSR_SSF1                      _DBGSR.Bits.SSF1
#define DBGSR_SSF2                      _DBGSR.Bits.SSF2
#define DBGSR_TBF                       _DBGSR.Bits.TBF
#define DBGSR_SSF                       _DBGSR.MergedBits.grpSSF

#define DBGSR_SSF0_MASK                 1U
#define DBGSR_SSF1_MASK                 2U
#define DBGSR_SSF2_MASK                 4U
#define DBGSR_TBF_MASK                  128U
#define DBGSR_SSF_MASK                  7U
#define DBGSR_SSF_BITNUM                0U


/*** DBGTCR - Debug Trace Control Register; 0x00000022 ***/
typedef union {
  byte Byte;
  struct {
    byte TALIGN      :2;                                       /* Trigger Align Bits */
    byte TRCMOD      :2;                                       /* Trace Mode Bits */
    byte TRANGE      :2;                                       /* Trace Range Bits */
    byte TSOURCE     :1;                                       /* Trace Source Control Bits */
    byte             :1; 
  } Bits;
} DBGTCRSTR;
extern volatile DBGTCRSTR _DBGTCR @(REG_BASE + 0x00000022UL);
#define DBGTCR                          _DBGTCR.Byte
#define DBGTCR_TALIGN                   _DBGTCR.Bits.TALIGN
#define DBGTCR_TRCMOD                   _DBGTCR.Bits.TRCMOD
#define DBGTCR_TRANGE                   _DBGTCR.Bits.TRANGE
#define DBGTCR_TSOURCE                  _DBGTCR.Bits.TSOURCE

#define DBGTCR_TALIGN_MASK              3U
#define DBGTCR_TALIGN_BITNUM            0U
#define DBGTCR_TRCMOD_MASK              12U
#define DBGTCR_TRCMOD_BITNUM            2U
#define DBGTCR_TRANGE_MASK              48U
#define DBGTCR_TRANGE_BITNUM            4U
#define DBGTCR_TSOURCE_MASK             64U


/*** DBGC2 - Debug Control Register 2; 0x00000023 ***/
typedef union {
  byte Byte;
  struct {
    byte ABCM        :2;                                       /* A and B Comparator Match Control */
    byte CDCM        :2;                                       /* C and D Comparator Match Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} DBGC2STR;
extern volatile DBGC2STR _DBGC2 @(REG_BASE + 0x00000023UL);
#define DBGC2                           _DBGC2.Byte
#define DBGC2_ABCM                      _DBGC2.Bits.ABCM
#define DBGC2_CDCM                      _DBGC2.Bits.CDCM

#define DBGC2_ABCM_MASK                 3U
#define DBGC2_ABCM_BITNUM               0U
#define DBGC2_CDCM_MASK                 12U
#define DBGC2_CDCM_BITNUM               2U


/*** DBGTB - Debug Trace Buffer Register; 0x00000024 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGTBH - Debug Trace Buffer Register High; 0x00000024 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Trace Buffer Data Bits */
        byte BIT9        :1;                                       /* Trace Buffer Data Bit 9 */
        byte BIT10       :1;                                       /* Trace Buffer Data Bit 10 */
        byte BIT11       :1;                                       /* Trace Buffer Data Bit 11 */
        byte BIT12       :1;                                       /* Trace Buffer Data Bit 12 */
        byte BIT13       :1;                                       /* Trace Buffer Data Bit 13 */
        byte BIT14       :1;                                       /* Trace Buffer Data Bit 14 */
        byte BIT15       :1;                                       /* Trace Buffer Data Bit 15 */
      } Bits;
    } DBGTBHSTR;
    #define DBGTBH                      _DBGTB.Overlap_STR.DBGTBHSTR.Byte
    #define DBGTBH_BIT8                 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT8
    #define DBGTBH_BIT9                 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT9
    #define DBGTBH_BIT10                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT10
    #define DBGTBH_BIT11                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT11
    #define DBGTBH_BIT12                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT12
    #define DBGTBH_BIT13                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT13
    #define DBGTBH_BIT14                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT14
    #define DBGTBH_BIT15                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT15
    
    #define DBGTBH_BIT8_MASK            1U
    #define DBGTBH_BIT9_MASK            2U
    #define DBGTBH_BIT10_MASK           4U
    #define DBGTBH_BIT11_MASK           8U
    #define DBGTBH_BIT12_MASK           16U
    #define DBGTBH_BIT13_MASK           32U
    #define DBGTBH_BIT14_MASK           64U
    #define DBGTBH_BIT15_MASK           128U
    

    /*** DBGTBL - Debug Trace Buffer Register Low; 0x00000025 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Trace Buffer Data Bits */
        byte BIT1        :1;                                       /* Trace Buffer Data Bit 1 */
        byte BIT2        :1;                                       /* Trace Buffer Data Bit 2 */
        byte BIT3        :1;                                       /* Trace Buffer Data Bit 3 */
        byte BIT4        :1;                                       /* Trace Buffer Data Bit 4 */
        byte BIT5        :1;                                       /* Trace Buffer Data Bit 5 */
        byte BIT6        :1;                                       /* Trace Buffer Data Bit 6 */
        byte BIT7        :1;                                       /* Trace Buffer Data Bit 7 */
      } Bits;
    } DBGTBLSTR;
    #define DBGTBL                      _DBGTB.Overlap_STR.DBGTBLSTR.Byte
    #define DBGTBL_BIT0                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT0
    #define DBGTBL_BIT1                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT1
    #define DBGTBL_BIT2                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT2
    #define DBGTBL_BIT3                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT3
    #define DBGTBL_BIT4                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT4
    #define DBGTBL_BIT5                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT5
    #define DBGTBL_BIT6                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT6
    #define DBGTBL_BIT7                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT7
    
    #define DBGTBL_BIT0_MASK            1U
    #define DBGTBL_BIT1_MASK            2U
    #define DBGTBL_BIT2_MASK            4U
    #define DBGTBL_BIT3_MASK            8U
    #define DBGTBL_BIT4_MASK            16U
    #define DBGTBL_BIT5_MASK            32U
    #define DBGTBL_BIT6_MASK            64U
    #define DBGTBL_BIT7_MASK            128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Trace Buffer Data Bits */
    word BIT1        :1;                                       /* Trace Buffer Data Bit 1 */
    word BIT2        :1;                                       /* Trace Buffer Data Bit 2 */
    word BIT3        :1;                                       /* Trace Buffer Data Bit 3 */
    word BIT4        :1;                                       /* Trace Buffer Data Bit 4 */
    word BIT5        :1;                                       /* Trace Buffer Data Bit 5 */
    word BIT6        :1;                                       /* Trace Buffer Data Bit 6 */
    word BIT7        :1;                                       /* Trace Buffer Data Bit 7 */
    word BIT8        :1;                                       /* Trace Buffer Data Bit 8 */
    word BIT9        :1;                                       /* Trace Buffer Data Bit 9 */
    word BIT10       :1;                                       /* Trace Buffer Data Bit 10 */
    word BIT11       :1;                                       /* Trace Buffer Data Bit 11 */
    word BIT12       :1;                                       /* Trace Buffer Data Bit 12 */
    word BIT13       :1;                                       /* Trace Buffer Data Bit 13 */
    word BIT14       :1;                                       /* Trace Buffer Data Bit 14 */
    word BIT15       :1;                                       /* Trace Buffer Data Bit 15 */
  } Bits;
} DBGTBSTR;
extern volatile DBGTBSTR _DBGTB @(REG_BASE + 0x00000024UL);
#define DBGTB                           _DBGTB.Word
#define DBGTB_BIT0                      _DBGTB.Bits.BIT0
#define DBGTB_BIT1                      _DBGTB.Bits.BIT1
#define DBGTB_BIT2                      _DBGTB.Bits.BIT2
#define DBGTB_BIT3                      _DBGTB.Bits.BIT3
#define DBGTB_BIT4                      _DBGTB.Bits.BIT4
#define DBGTB_BIT5                      _DBGTB.Bits.BIT5
#define DBGTB_BIT6                      _DBGTB.Bits.BIT6
#define DBGTB_BIT7                      _DBGTB.Bits.BIT7
#define DBGTB_BIT8                      _DBGTB.Bits.BIT8
#define DBGTB_BIT9                      _DBGTB.Bits.BIT9
#define DBGTB_BIT10                     _DBGTB.Bits.BIT10
#define DBGTB_BIT11                     _DBGTB.Bits.BIT11
#define DBGTB_BIT12                     _DBGTB.Bits.BIT12
#define DBGTB_BIT13                     _DBGTB.Bits.BIT13
#define DBGTB_BIT14                     _DBGTB.Bits.BIT14
#define DBGTB_BIT15                     _DBGTB.Bits.BIT15

#define DBGTB_BIT0_MASK                 1U
#define DBGTB_BIT1_MASK                 2U
#define DBGTB_BIT2_MASK                 4U
#define DBGTB_BIT3_MASK                 8U
#define DBGTB_BIT4_MASK                 16U
#define DBGTB_BIT5_MASK                 32U
#define DBGTB_BIT6_MASK                 64U
#define DBGTB_BIT7_MASK                 128U
#define DBGTB_BIT8_MASK                 256U
#define DBGTB_BIT9_MASK                 512U
#define DBGTB_BIT10_MASK                1024U
#define DBGTB_BIT11_MASK                2048U
#define DBGTB_BIT12_MASK                4096U
#define DBGTB_BIT13_MASK                8192U
#define DBGTB_BIT14_MASK                16384U
#define DBGTB_BIT15_MASK                32768U


/*** DBGCNT - Debug Count Register; 0x00000026 ***/
typedef union {
  byte Byte;
  struct {
    byte CNT         :7;                                       /* Count Value */
    byte             :1; 
  } Bits;
} DBGCNTSTR;
extern volatile DBGCNTSTR _DBGCNT @(REG_BASE + 0x00000026UL);
#define DBGCNT                          _DBGCNT.Byte
#define DBGCNT_CNT                      _DBGCNT.Bits.CNT

#define DBGCNT_CNT_MASK                 127U
#define DBGCNT_CNT_BITNUM               0U


/*** DBGSCRX - Debug State Control Register; 0x00000027 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** DBGSCRX - Debug State Control Register; Several registers at the same address ***/
    union {
      struct {
        byte SC0         :1;                                       /* State X Sequencer Next State Selection Bit 0 */
        byte SC1         :1;                                       /* State X Sequencer Next State Selection Bit 1 */
        byte SC2         :1;                                       /* State X Sequencer Next State Selection Bit 2 */
        byte SC3         :1;                                       /* State X Sequencer Next State Selection Bit 3 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpSC :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DBGSCRXSTR;
    #define DBGSCRX                     _DBGSCRX.Byte
    #define DBGSCRX_SC0                 _DBGSCRX.SameAddr_STR.DBGSCRXSTR.Bits.SC0
    #define DBGSCRX_SC1                 _DBGSCRX.SameAddr_STR.DBGSCRXSTR.Bits.SC1
    #define DBGSCRX_SC2                 _DBGSCRX.SameAddr_STR.DBGSCRXSTR.Bits.SC2
    #define DBGSCRX_SC3                 _DBGSCRX.SameAddr_STR.DBGSCRXSTR.Bits.SC3
    #define DBGSCRX_SC                  _DBGSCRX.SameAddr_STR.DBGSCRXSTR.MergedBits.grpSC
    
    #define DBGSCRX_SC0_MASK            1U
    #define DBGSCRX_SC1_MASK            2U
    #define DBGSCRX_SC2_MASK            4U
    #define DBGSCRX_SC3_MASK            8U
    #define DBGSCRX_SC_MASK             15U
    #define DBGSCRX_SC_BITNUM           0U
    
    /*** DBGMFR - Debug Match Flag Register; Several registers at the same address ***/
    union {
      struct {
        byte MC0         :1;                                       /* Debug Match Flag Bit 0 */
        byte MC1         :1;                                       /* Debug Match Flag Bit 1 */
        byte MC2         :1;                                       /* Debug Match Flag Bit 2 */
        byte MC3         :1;                                       /* Debug Match Flag Bit 3 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpMC :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DBGMFRSTR;
    #define DBGMFR                      _DBGSCRX.Byte
    #define DBGMFR_MC0                  _DBGSCRX.SameAddr_STR.DBGMFRSTR.Bits.MC0
    #define DBGMFR_MC1                  _DBGSCRX.SameAddr_STR.DBGMFRSTR.Bits.MC1
    #define DBGMFR_MC2                  _DBGSCRX.SameAddr_STR.DBGMFRSTR.Bits.MC2
    #define DBGMFR_MC3                  _DBGSCRX.SameAddr_STR.DBGMFRSTR.Bits.MC3
    #define DBGMFR_MC                   _DBGSCRX.SameAddr_STR.DBGMFRSTR.MergedBits.grpMC
    
    #define DBGMFR_MC0_MASK             1U
    #define DBGMFR_MC1_MASK             2U
    #define DBGMFR_MC2_MASK             4U
    #define DBGMFR_MC3_MASK             8U
    #define DBGMFR_MC_MASK              15U
    #define DBGMFR_MC_BITNUM            0U
    
  } SameAddr_STR; /*Several registers at the same address */

} DBGSCRXSTR;
extern volatile DBGSCRXSTR _DBGSCRX @(REG_BASE + 0x00000027UL);


/*** DBGXCTL - Debug Comparator Control Register; 0x00000028 ***/
typedef union {
  byte Byte;
  struct {
    byte COMPE       :1;                                       /* Determines if comparator is enabled */
    byte             :1; 
    byte RWE         :1;                                       /* Read/Write Enable Bit */
    byte RW          :1;                                       /* Read/Write Comparator Value Bit */
    byte BRK         :1;                                       /* Break */
    byte TAG         :1;                                       /* Tag Select */
    byte NDB_SZ      :1;                                       /* Not Data Bus(Comparators A and C), Size Comparator Value Bit(Comparators B and D) */
    byte SZE         :1;                                       /* Size Comparator Enable Bit */
  } Bits;
} DBGXCTLSTR;
extern volatile DBGXCTLSTR _DBGXCTL @(REG_BASE + 0x00000028UL);
#define DBGXCTL                         _DBGXCTL.Byte
#define DBGXCTL_COMPE                   _DBGXCTL.Bits.COMPE
#define DBGXCTL_RWE                     _DBGXCTL.Bits.RWE
#define DBGXCTL_RW                      _DBGXCTL.Bits.RW
#define DBGXCTL_BRK                     _DBGXCTL.Bits.BRK
#define DBGXCTL_TAG                     _DBGXCTL.Bits.TAG
#define DBGXCTL_NDB_SZ                  _DBGXCTL.Bits.NDB_SZ
#define DBGXCTL_SZE                     _DBGXCTL.Bits.SZE

#define DBGXCTL_COMPE_MASK              1U
#define DBGXCTL_RWE_MASK                4U
#define DBGXCTL_RW_MASK                 8U
#define DBGXCTL_BRK_MASK                16U
#define DBGXCTL_TAG_MASK                32U
#define DBGXCTL_NDB_SZ_MASK             64U
#define DBGXCTL_SZE_MASK                128U


/*** DBGXAH - Debug Comparator Address High Register; 0x00000029 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT16       :1;                                       /* Comparator Address High Compare Bits */
    byte BIT17       :1;                                       /* Comparator Address High Compare Bit 17 */
    byte BIT18       :1;                                       /* Comparator Address High Compare Bit 18 */
    byte BIT19       :1;                                       /* Comparator Address High Compare Bit 19 */
    byte BIT20       :1;                                       /* Comparator Address High Compare Bit 20 */
    byte BIT21       :1;                                       /* Comparator Address High Compare Bit 21 */
    byte BIT22       :1;                                       /* Comparator Address High Compare Bit 22 */
    byte             :1; 
  } Bits;
  struct {
    byte grpBIT_16 :7;
    byte         :1;
  } MergedBits;
} DBGXAHSTR;
extern volatile DBGXAHSTR _DBGXAH @(REG_BASE + 0x00000029UL);
#define DBGXAH                          _DBGXAH.Byte
#define DBGXAH_BIT16                    _DBGXAH.Bits.BIT16
#define DBGXAH_BIT17                    _DBGXAH.Bits.BIT17
#define DBGXAH_BIT18                    _DBGXAH.Bits.BIT18
#define DBGXAH_BIT19                    _DBGXAH.Bits.BIT19
#define DBGXAH_BIT20                    _DBGXAH.Bits.BIT20
#define DBGXAH_BIT21                    _DBGXAH.Bits.BIT21
#define DBGXAH_BIT22                    _DBGXAH.Bits.BIT22
#define DBGXAH_BIT_16                   _DBGXAH.MergedBits.grpBIT_16
#define DBGXAH_BIT                      DBGXAH_BIT_16

#define DBGXAH_BIT16_MASK               1U
#define DBGXAH_BIT17_MASK               2U
#define DBGXAH_BIT18_MASK               4U
#define DBGXAH_BIT19_MASK               8U
#define DBGXAH_BIT20_MASK               16U
#define DBGXAH_BIT21_MASK               32U
#define DBGXAH_BIT22_MASK               64U
#define DBGXAH_BIT_16_MASK              127U
#define DBGXAH_BIT_16_BITNUM            0U


/*** DBGXAM - Debug Comparator Address Mid Register; 0x0000002A ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Address Mid Compare Bits */
    byte BIT9        :1;                                       /* Comparator Address Mid Compare Bit 9 */
    byte BIT10       :1;                                       /* Comparator Address Mid Compare Bit 10 */
    byte BIT11       :1;                                       /* Comparator Address Mid Compare Bit 11 */
    byte BIT12       :1;                                       /* Comparator Address Mid Compare Bit 12 */
    byte BIT13       :1;                                       /* Comparator Address Mid Compare Bit 13 */
    byte BIT14       :1;                                       /* Comparator Address Mid Compare Bit 14 */
    byte BIT15       :1;                                       /* Comparator Address Mid Compare Bit 15 */
  } Bits;
} DBGXAMSTR;
extern volatile DBGXAMSTR _DBGXAM @(REG_BASE + 0x0000002AUL);
#define DBGXAM                          _DBGXAM.Byte
#define DBGXAM_BIT8                     _DBGXAM.Bits.BIT8
#define DBGXAM_BIT9                     _DBGXAM.Bits.BIT9
#define DBGXAM_BIT10                    _DBGXAM.Bits.BIT10
#define DBGXAM_BIT11                    _DBGXAM.Bits.BIT11
#define DBGXAM_BIT12                    _DBGXAM.Bits.BIT12
#define DBGXAM_BIT13                    _DBGXAM.Bits.BIT13
#define DBGXAM_BIT14                    _DBGXAM.Bits.BIT14
#define DBGXAM_BIT15                    _DBGXAM.Bits.BIT15

#define DBGXAM_BIT8_MASK                1U
#define DBGXAM_BIT9_MASK                2U
#define DBGXAM_BIT10_MASK               4U
#define DBGXAM_BIT11_MASK               8U
#define DBGXAM_BIT12_MASK               16U
#define DBGXAM_BIT13_MASK               32U
#define DBGXAM_BIT14_MASK               64U
#define DBGXAM_BIT15_MASK               128U


/*** DBGXAL - Debug Comparator Address Low Register; 0x0000002B ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Address Low Compare Bits */
    byte BIT1        :1;                                       /* Comparator Address Low Compare Bit 1 */
    byte BIT2        :1;                                       /* Comparator Address Low Compare Bit 2 */
    byte BIT3        :1;                                       /* Comparator Address Low Compare Bit 3 */
    byte BIT4        :1;                                       /* Comparator Address Low Compare Bit 4 */
    byte BIT5        :1;                                       /* Comparator Address Low Compare Bit 5 */
    byte BIT6        :1;                                       /* Comparator Address Low Compare Bit 6 */
    byte BIT7        :1;                                       /* Comparator Address Low Compare Bit 7 */
  } Bits;
} DBGXALSTR;
extern volatile DBGXALSTR _DBGXAL @(REG_BASE + 0x0000002BUL);
#define DBGXAL                          _DBGXAL.Byte
#define DBGXAL_BIT0                     _DBGXAL.Bits.BIT0
#define DBGXAL_BIT1                     _DBGXAL.Bits.BIT1
#define DBGXAL_BIT2                     _DBGXAL.Bits.BIT2
#define DBGXAL_BIT3                     _DBGXAL.Bits.BIT3
#define DBGXAL_BIT4                     _DBGXAL.Bits.BIT4
#define DBGXAL_BIT5                     _DBGXAL.Bits.BIT5
#define DBGXAL_BIT6                     _DBGXAL.Bits.BIT6
#define DBGXAL_BIT7                     _DBGXAL.Bits.BIT7

#define DBGXAL_BIT0_MASK                1U
#define DBGXAL_BIT1_MASK                2U
#define DBGXAL_BIT2_MASK                4U
#define DBGXAL_BIT3_MASK                8U
#define DBGXAL_BIT4_MASK                16U
#define DBGXAL_BIT5_MASK                32U
#define DBGXAL_BIT6_MASK                64U
#define DBGXAL_BIT7_MASK                128U


/*** DBGXDH - Debug Comparator Data High Register; 0x0000002C ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Data High Compare Bit 8 */
    byte BIT9        :1;                                       /* Comparator Data High Compare Bit 9 */
    byte BIT10       :1;                                       /* Comparator Data High Compare Bit 10 */
    byte BIT11       :1;                                       /* Comparator Data High Compare Bit 11 */
    byte BIT12       :1;                                       /* Comparator Data High Compare Bit 12 */
    byte BIT13       :1;                                       /* Comparator Data High Compare Bit 13 */
    byte BIT14       :1;                                       /* Comparator Data High Compare Bit 14 */
    byte BIT15       :1;                                       /* Comparator Data High Compare Bit 15 */
  } Bits;
} DBGXDHSTR;
extern volatile DBGXDHSTR _DBGXDH @(REG_BASE + 0x0000002CUL);
#define DBGXDH                          _DBGXDH.Byte
#define DBGXDH_BIT8                     _DBGXDH.Bits.BIT8
#define DBGXDH_BIT9                     _DBGXDH.Bits.BIT9
#define DBGXDH_BIT10                    _DBGXDH.Bits.BIT10
#define DBGXDH_BIT11                    _DBGXDH.Bits.BIT11
#define DBGXDH_BIT12                    _DBGXDH.Bits.BIT12
#define DBGXDH_BIT13                    _DBGXDH.Bits.BIT13
#define DBGXDH_BIT14                    _DBGXDH.Bits.BIT14
#define DBGXDH_BIT15                    _DBGXDH.Bits.BIT15

#define DBGXDH_BIT8_MASK                1U
#define DBGXDH_BIT9_MASK                2U
#define DBGXDH_BIT10_MASK               4U
#define DBGXDH_BIT11_MASK               8U
#define DBGXDH_BIT12_MASK               16U
#define DBGXDH_BIT13_MASK               32U
#define DBGXDH_BIT14_MASK               64U
#define DBGXDH_BIT15_MASK               128U


/*** DBGXDL - Debug Comparator Data Low Register; 0x0000002D ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Data Low Compare Bit 0 */
    byte BIT1        :1;                                       /* Comparator Data Low Compare Bit 1 */
    byte BIT2        :1;                                       /* Comparator Data Low Compare Bit 2 */
    byte BIT3        :1;                                       /* Comparator Data Low Compare Bit 3 */
    byte BIT4        :1;                                       /* Comparator Data Low Compare Bit 4 */
    byte BIT5        :1;                                       /* Comparator Data Low Compare Bit 5 */
    byte BIT6        :1;                                       /* Comparator Data Low Compare Bit 6 */
    byte BIT7        :1;                                       /* Comparator Data Low Compare Bit 7 */
  } Bits;
} DBGXDLSTR;
extern volatile DBGXDLSTR _DBGXDL @(REG_BASE + 0x0000002DUL);
#define DBGXDL                          _DBGXDL.Byte
#define DBGXDL_BIT0                     _DBGXDL.Bits.BIT0
#define DBGXDL_BIT1                     _DBGXDL.Bits.BIT1
#define DBGXDL_BIT2                     _DBGXDL.Bits.BIT2
#define DBGXDL_BIT3                     _DBGXDL.Bits.BIT3
#define DBGXDL_BIT4                     _DBGXDL.Bits.BIT4
#define DBGXDL_BIT5                     _DBGXDL.Bits.BIT5
#define DBGXDL_BIT6                     _DBGXDL.Bits.BIT6
#define DBGXDL_BIT7                     _DBGXDL.Bits.BIT7

#define DBGXDL_BIT0_MASK                1U
#define DBGXDL_BIT1_MASK                2U
#define DBGXDL_BIT2_MASK                4U
#define DBGXDL_BIT3_MASK                8U
#define DBGXDL_BIT4_MASK                16U
#define DBGXDL_BIT5_MASK                32U
#define DBGXDL_BIT6_MASK                64U
#define DBGXDL_BIT7_MASK                128U


/*** DBGXDHM - Debug Comparator Data High Mask Register; 0x0000002E ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Data High Mask Bit 8 */
    byte BIT9        :1;                                       /* Comparator Data High Mask Bit 9 */
    byte BIT10       :1;                                       /* Comparator Data High Mask Bit 10 */
    byte BIT11       :1;                                       /* Comparator Data High Mask Bit 11 */
    byte BIT12       :1;                                       /* Comparator Data High Mask Bit 12 */
    byte BIT13       :1;                                       /* Comparator Data High Mask Bit 13 */
    byte BIT14       :1;                                       /* Comparator Data High Mask Bit 14 */
    byte BIT15       :1;                                       /* Comparator Data High Mask Bit 15 */
  } Bits;
} DBGXDHMSTR;
extern volatile DBGXDHMSTR _DBGXDHM @(REG_BASE + 0x0000002EUL);
#define DBGXDHM                         _DBGXDHM.Byte
#define DBGXDHM_BIT8                    _DBGXDHM.Bits.BIT8
#define DBGXDHM_BIT9                    _DBGXDHM.Bits.BIT9
#define DBGXDHM_BIT10                   _DBGXDHM.Bits.BIT10
#define DBGXDHM_BIT11                   _DBGXDHM.Bits.BIT11
#define DBGXDHM_BIT12                   _DBGXDHM.Bits.BIT12
#define DBGXDHM_BIT13                   _DBGXDHM.Bits.BIT13
#define DBGXDHM_BIT14                   _DBGXDHM.Bits.BIT14
#define DBGXDHM_BIT15                   _DBGXDHM.Bits.BIT15

#define DBGXDHM_BIT8_MASK               1U
#define DBGXDHM_BIT9_MASK               2U
#define DBGXDHM_BIT10_MASK              4U
#define DBGXDHM_BIT11_MASK              8U
#define DBGXDHM_BIT12_MASK              16U
#define DBGXDHM_BIT13_MASK              32U
#define DBGXDHM_BIT14_MASK              64U
#define DBGXDHM_BIT15_MASK              128U


/*** DBGXDLM - Debug Comparator Data Low Mask Register; 0x0000002F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Data Low Mask Bit 0 */
    byte BIT1        :1;                                       /* Comparator Data Low Mask Bit 1 */
    byte BIT2        :1;                                       /* Comparator Data Low Mask Bit 2 */
    byte BIT3        :1;                                       /* Comparator Data Low Mask Bit 3 */
    byte BIT4        :1;                                       /* Comparator Data Low Mask Bit 4 */
    byte BIT5        :1;                                       /* Comparator Data Low Mask Bit 5 */
    byte BIT6        :1;                                       /* Comparator Data Low Mask Bit 6 */
    byte BIT7        :1;                                       /* Comparator Data Low Mask Bit 7 */
  } Bits;
} DBGXDLMSTR;
extern volatile DBGXDLMSTR _DBGXDLM @(REG_BASE + 0x0000002FUL);
#define DBGXDLM                         _DBGXDLM.Byte
#define DBGXDLM_BIT0                    _DBGXDLM.Bits.BIT0
#define DBGXDLM_BIT1                    _DBGXDLM.Bits.BIT1
#define DBGXDLM_BIT2                    _DBGXDLM.Bits.BIT2
#define DBGXDLM_BIT3                    _DBGXDLM.Bits.BIT3
#define DBGXDLM_BIT4                    _DBGXDLM.Bits.BIT4
#define DBGXDLM_BIT5                    _DBGXDLM.Bits.BIT5
#define DBGXDLM_BIT6                    _DBGXDLM.Bits.BIT6
#define DBGXDLM_BIT7                    _DBGXDLM.Bits.BIT7

#define DBGXDLM_BIT0_MASK               1U
#define DBGXDLM_BIT1_MASK               2U
#define DBGXDLM_BIT2_MASK               4U
#define DBGXDLM_BIT3_MASK               8U
#define DBGXDLM_BIT4_MASK               16U
#define DBGXDLM_BIT5_MASK               32U
#define DBGXDLM_BIT6_MASK               64U
#define DBGXDLM_BIT7_MASK               128U


/*** PORTK - Port K Data Register; 0x00000032 ***/
typedef union {
  byte Byte;
  struct {
    byte PK0         :1;                                       /* Port K Bit 0 */
    byte PK1         :1;                                       /* Port K Bit 1 */
    byte PK2         :1;                                       /* Port K Bit 2 */
    byte PK3         :1;                                       /* Port K Bit 3 */
    byte PK4         :1;                                       /* Port K Bit 4 */
    byte PK5         :1;                                       /* Port K Bit 5 */
    byte             :1; 
    byte PK7         :1;                                       /* Port K Bit 7 */
  } Bits;
  struct {
    byte grpPK   :6;
    byte         :1;
    byte grpPK_7 :1;
  } MergedBits;
} PORTKSTR;
extern volatile PORTKSTR _PORTK @(REG_BASE + 0x00000032UL);
#define PORTK                           _PORTK.Byte
#define PORTK_PK0                       _PORTK.Bits.PK0
#define PORTK_PK1                       _PORTK.Bits.PK1
#define PORTK_PK2                       _PORTK.Bits.PK2
#define PORTK_PK3                       _PORTK.Bits.PK3
#define PORTK_PK4                       _PORTK.Bits.PK4
#define PORTK_PK5                       _PORTK.Bits.PK5
#define PORTK_PK7                       _PORTK.Bits.PK7
#define PORTK_PK                        _PORTK.MergedBits.grpPK

#define PORTK_PK0_MASK                  1U
#define PORTK_PK1_MASK                  2U
#define PORTK_PK2_MASK                  4U
#define PORTK_PK3_MASK                  8U
#define PORTK_PK4_MASK                  16U
#define PORTK_PK5_MASK                  32U
#define PORTK_PK7_MASK                  128U
#define PORTK_PK_MASK                   63U
#define PORTK_PK_BITNUM                 0U


/*** DDRK - Port K Data Direction Register; 0x00000033 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRK0       :1;                                       /* Data Direction Port K Bit 0 */
    byte DDRK1       :1;                                       /* Data Direction Port K Bit 1 */
    byte DDRK2       :1;                                       /* Data Direction Port K Bit 2 */
    byte DDRK3       :1;                                       /* Data Direction Port K Bit 3 */
    byte DDRK4       :1;                                       /* Data Direction Port K Bit 4 */
    byte DDRK5       :1;                                       /* Data Direction Port K Bit 5 */
    byte             :1; 
    byte DDRK7       :1;                                       /* Data Direction Port K Bit 7 */
  } Bits;
  struct {
    byte grpDDRK :6;
    byte         :1;
    byte grpDDRK_7 :1;
  } MergedBits;
} DDRKSTR;
extern volatile DDRKSTR _DDRK @(REG_BASE + 0x00000033UL);
#define DDRK                            _DDRK.Byte
#define DDRK_DDRK0                      _DDRK.Bits.DDRK0
#define DDRK_DDRK1                      _DDRK.Bits.DDRK1
#define DDRK_DDRK2                      _DDRK.Bits.DDRK2
#define DDRK_DDRK3                      _DDRK.Bits.DDRK3
#define DDRK_DDRK4                      _DDRK.Bits.DDRK4
#define DDRK_DDRK5                      _DDRK.Bits.DDRK5
#define DDRK_DDRK7                      _DDRK.Bits.DDRK7
#define DDRK_DDRK                       _DDRK.MergedBits.grpDDRK

#define DDRK_DDRK0_MASK                 1U
#define DDRK_DDRK1_MASK                 2U
#define DDRK_DDRK2_MASK                 4U
#define DDRK_DDRK3_MASK                 8U
#define DDRK_DDRK4_MASK                 16U
#define DDRK_DDRK5_MASK                 32U
#define DDRK_DDRK7_MASK                 128U
#define DDRK_DDRK_MASK                  63U
#define DDRK_DDRK_BITNUM                0U


/*** SYNR - S12XECRG Synthesizer Register; 0x00000034 ***/
typedef union {
  byte Byte;
  struct {
    byte SYNDIV0     :1;                                       /* Multiplication factor of the IPLL bit 0 */
    byte SYNDIV1     :1;                                       /* Multiplication factor of the IPLL bit 1 */
    byte SYNDIV2     :1;                                       /* Multiplication factor of the IPLL bit 2 */
    byte SYNDIV3     :1;                                       /* Multiplication factor of the IPLL bit 3 */
    byte SYNDIV4     :1;                                       /* Multiplication factor of the IPLL bit 4 */
    byte SYNDIV5     :1;                                       /* Multiplication factor of the IPLL bit 5 */
    byte VCOFRQ0     :1;                                       /* VCO frequency range bit 0 */
    byte VCOFRQ1     :1;                                       /* VCO frequency range bit 1 */
  } Bits;
  struct {
    byte grpSYNDIV :6;
    byte grpVCOFRQ :2;
  } MergedBits;
} SYNRSTR;
extern volatile SYNRSTR _SYNR @(REG_BASE + 0x00000034UL);
#define SYNR                            _SYNR.Byte
#define SYNR_SYNDIV0                    _SYNR.Bits.SYNDIV0
#define SYNR_SYNDIV1                    _SYNR.Bits.SYNDIV1
#define SYNR_SYNDIV2                    _SYNR.Bits.SYNDIV2
#define SYNR_SYNDIV3                    _SYNR.Bits.SYNDIV3
#define SYNR_SYNDIV4                    _SYNR.Bits.SYNDIV4
#define SYNR_SYNDIV5                    _SYNR.Bits.SYNDIV5
#define SYNR_VCOFRQ0                    _SYNR.Bits.VCOFRQ0
#define SYNR_VCOFRQ1                    _SYNR.Bits.VCOFRQ1
#define SYNR_SYNDIV                     _SYNR.MergedBits.grpSYNDIV
#define SYNR_VCOFRQ                     _SYNR.MergedBits.grpVCOFRQ

#define SYNR_SYNDIV0_MASK               1U
#define SYNR_SYNDIV1_MASK               2U
#define SYNR_SYNDIV2_MASK               4U
#define SYNR_SYNDIV3_MASK               8U
#define SYNR_SYNDIV4_MASK               16U
#define SYNR_SYNDIV5_MASK               32U
#define SYNR_VCOFRQ0_MASK               64U
#define SYNR_VCOFRQ1_MASK               128U
#define SYNR_SYNDIV_MASK                63U
#define SYNR_SYNDIV_BITNUM              0U
#define SYNR_VCOFRQ_MASK                192U
#define SYNR_VCOFRQ_BITNUM              6U


/*** REFDV - S12XECRG Reference Divider Register; 0x00000035 ***/
typedef union {
  byte Byte;
  struct {
    byte REFDIV0     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 0 */
    byte REFDIV1     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 1 */
    byte REFDIV2     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 2 */
    byte REFDIV3     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 3 */
    byte REFDIV4     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 4 */
    byte REFDIV5     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 5 */
    byte REFFRQ0     :1;                                       /* IPLL optimal stability and lock time configuration bit 0 */
    byte REFFRQ1     :1;                                       /* IPLL optimal stability and lock time configuration bit 1 */
  } Bits;
  struct {
    byte grpREFDIV :6;
    byte grpREFFRQ :2;
  } MergedBits;
} REFDVSTR;
extern volatile REFDVSTR _REFDV @(REG_BASE + 0x00000035UL);
#define REFDV                           _REFDV.Byte
#define REFDV_REFDIV0                   _REFDV.Bits.REFDIV0
#define REFDV_REFDIV1                   _REFDV.Bits.REFDIV1
#define REFDV_REFDIV2                   _REFDV.Bits.REFDIV2
#define REFDV_REFDIV3                   _REFDV.Bits.REFDIV3
#define REFDV_REFDIV4                   _REFDV.Bits.REFDIV4
#define REFDV_REFDIV5                   _REFDV.Bits.REFDIV5
#define REFDV_REFFRQ0                   _REFDV.Bits.REFFRQ0
#define REFDV_REFFRQ1                   _REFDV.Bits.REFFRQ1
#define REFDV_REFDIV                    _REFDV.MergedBits.grpREFDIV
#define REFDV_REFFRQ                    _REFDV.MergedBits.grpREFFRQ

#define REFDV_REFDIV0_MASK              1U
#define REFDV_REFDIV1_MASK              2U
#define REFDV_REFDIV2_MASK              4U
#define REFDV_REFDIV3_MASK              8U
#define REFDV_REFDIV4_MASK              16U
#define REFDV_REFDIV5_MASK              32U
#define REFDV_REFFRQ0_MASK              64U
#define REFDV_REFFRQ1_MASK              128U
#define REFDV_REFDIV_MASK               63U
#define REFDV_REFDIV_BITNUM             0U
#define REFDV_REFFRQ_MASK               192U
#define REFDV_REFFRQ_BITNUM             6U


/*** POSTDIV - S12XECRG Post Divider Register; 0x00000036 ***/
typedef union {
  byte Byte;
  struct {
    byte POSTDIV0    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 0 */
    byte POSTDIV1    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 1 */
    byte POSTDIV2    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 2 */
    byte POSTDIV3    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 3 */
    byte POSTDIV4    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPOSTDIV :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} POSTDIVSTR;
extern volatile POSTDIVSTR _POSTDIV @(REG_BASE + 0x00000036UL);
#define POSTDIV                         _POSTDIV.Byte
#define POSTDIV_POSTDIV0                _POSTDIV.Bits.POSTDIV0
#define POSTDIV_POSTDIV1                _POSTDIV.Bits.POSTDIV1
#define POSTDIV_POSTDIV2                _POSTDIV.Bits.POSTDIV2
#define POSTDIV_POSTDIV3                _POSTDIV.Bits.POSTDIV3
#define POSTDIV_POSTDIV4                _POSTDIV.Bits.POSTDIV4
#define POSTDIV_POSTDIV                 _POSTDIV.MergedBits.grpPOSTDIV

#define POSTDIV_POSTDIV0_MASK           1U
#define POSTDIV_POSTDIV1_MASK           2U
#define POSTDIV_POSTDIV2_MASK           4U
#define POSTDIV_POSTDIV3_MASK           8U
#define POSTDIV_POSTDIV4_MASK           16U
#define POSTDIV_POSTDIV_MASK            31U
#define POSTDIV_POSTDIV_BITNUM          0U


/*** CRGFLG - S12XECRG Flags Register; 0x00000037 ***/
typedef union {
  byte Byte;
  struct {
    byte SCM         :1;                                       /* Self Clock Mode Status Bit */
    byte SCMIF       :1;                                       /* Self Clock Mode Interrupt Flag */
    byte ILAF        :1;                                       /* Illegal Address Reset Flag */
    byte LOCK        :1;                                       /* Lock Status Bit */
    byte LOCKIF      :1;                                       /* IPLL Lock Interrupt Flag */
    byte LVRF        :1;                                       /* Low Voltage Reset Flag */
    byte PORF        :1;                                       /* Power on Reset Flag */
    byte RTIF        :1;                                       /* Real Time Interrupt Flag */
  } Bits;
} CRGFLGSTR;
extern volatile CRGFLGSTR _CRGFLG @(REG_BASE + 0x00000037UL);
#define CRGFLG                          _CRGFLG.Byte
#define CRGFLG_SCM                      _CRGFLG.Bits.SCM
#define CRGFLG_SCMIF                    _CRGFLG.Bits.SCMIF
#define CRGFLG_ILAF                     _CRGFLG.Bits.ILAF
#define CRGFLG_LOCK                     _CRGFLG.Bits.LOCK
#define CRGFLG_LOCKIF                   _CRGFLG.Bits.LOCKIF
#define CRGFLG_LVRF                     _CRGFLG.Bits.LVRF
#define CRGFLG_PORF                     _CRGFLG.Bits.PORF
#define CRGFLG_RTIF                     _CRGFLG.Bits.RTIF

#define CRGFLG_SCM_MASK                 1U
#define CRGFLG_SCMIF_MASK               2U
#define CRGFLG_ILAF_MASK                4U
#define CRGFLG_LOCK_MASK                8U
#define CRGFLG_LOCKIF_MASK              16U
#define CRGFLG_LVRF_MASK                32U
#define CRGFLG_PORF_MASK                64U
#define CRGFLG_RTIF_MASK                128U


/*** CRGINT - S12XECRG Interrupt Enable Register; 0x00000038 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte SCMIE       :1;                                       /* Self Clock Mode Interrupt Enable Bit */
    byte             :1; 
    byte             :1; 
    byte LOCKIE      :1;                                       /* Lock Interrupt Enable Bit */
    byte             :1; 
    byte             :1; 
    byte RTIE        :1;                                       /* Real Time Interrupt Enable Bit */
  } Bits;
} CRGINTSTR;
extern volatile CRGINTSTR _CRGINT @(REG_BASE + 0x00000038UL);
#define CRGINT                          _CRGINT.Byte
#define CRGINT_SCMIE                    _CRGINT.Bits.SCMIE
#define CRGINT_LOCKIE                   _CRGINT.Bits.LOCKIE
#define CRGINT_RTIE                     _CRGINT.Bits.RTIE

#define CRGINT_SCMIE_MASK               2U
#define CRGINT_LOCKIE_MASK              16U
#define CRGINT_RTIE_MASK                128U


/*** CLKSEL - S12XECRG Clock Select Register; 0x00000039 ***/
typedef union {
  byte Byte;
  struct {
    byte COPWAI      :1;                                       /* COP Stops in Wait Mode Bit */
    byte RTIWAI      :1;                                       /* RTI Stops in Wait Mode Bit */
    byte             :1; 
    byte PLLWAI      :1;                                       /* PLL Stops in Wait Mode Bit */
    byte             :1; 
    byte XCLKS       :1;                                       /* Oscillator Configuration Status Bit */
    byte PSTP        :1;                                       /* Pseudo Stop Bit */
    byte PLLSEL      :1;                                       /* PLL Select Bit */
  } Bits;
} CLKSELSTR;
extern volatile CLKSELSTR _CLKSEL @(REG_BASE + 0x00000039UL);
#define CLKSEL                          _CLKSEL.Byte
#define CLKSEL_COPWAI                   _CLKSEL.Bits.COPWAI
#define CLKSEL_RTIWAI                   _CLKSEL.Bits.RTIWAI
#define CLKSEL_PLLWAI                   _CLKSEL.Bits.PLLWAI
#define CLKSEL_XCLKS                    _CLKSEL.Bits.XCLKS
#define CLKSEL_PSTP                     _CLKSEL.Bits.PSTP
#define CLKSEL_PLLSEL                   _CLKSEL.Bits.PLLSEL

#define CLKSEL_COPWAI_MASK              1U
#define CLKSEL_RTIWAI_MASK              2U
#define CLKSEL_PLLWAI_MASK              8U
#define CLKSEL_XCLKS_MASK               32U
#define CLKSEL_PSTP_MASK                64U
#define CLKSEL_PLLSEL_MASK              128U


/*** PLLCTL - S12XECRG IPLL Control Register; 0x0000003A ***/
typedef union {
  byte Byte;
  struct {
    byte SCME        :1;                                       /* Self Clock Mode Enable Bit */
    byte PCE         :1;                                       /* COP Enable During Pseudo Stop Bit */
    byte PRE         :1;                                       /* RTI Enable During Pseudo Stop Bit */
    byte FSTWKP      :1;                                       /* Fast Wake-up from Full Stop Bit */
    byte FM0         :1;                                       /* IPLL Frequency Modulation Enable Bit 0 */
    byte FM1         :1;                                       /* IPLL Frequency Modulation Enable Bit 1 */
    byte PLLON       :1;                                       /* Phase Lock Loop On Bit */
    byte CME         :1;                                       /* Clock Monitor Enable Bit */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpFM   :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} PLLCTLSTR;
extern volatile PLLCTLSTR _PLLCTL @(REG_BASE + 0x0000003AUL);
#define PLLCTL                          _PLLCTL.Byte
#define PLLCTL_SCME                     _PLLCTL.Bits.SCME
#define PLLCTL_PCE                      _PLLCTL.Bits.PCE
#define PLLCTL_PRE                      _PLLCTL.Bits.PRE
#define PLLCTL_FSTWKP                   _PLLCTL.Bits.FSTWKP
#define PLLCTL_FM0                      _PLLCTL.Bits.FM0
#define PLLCTL_FM1                      _PLLCTL.Bits.FM1
#define PLLCTL_PLLON                    _PLLCTL.Bits.PLLON
#define PLLCTL_CME                      _PLLCTL.Bits.CME
#define PLLCTL_FM                       _PLLCTL.MergedBits.grpFM

#define PLLCTL_SCME_MASK                1U
#define PLLCTL_PCE_MASK                 2U
#define PLLCTL_PRE_MASK                 4U
#define PLLCTL_FSTWKP_MASK              8U
#define PLLCTL_FM0_MASK                 16U
#define PLLCTL_FM1_MASK                 32U
#define PLLCTL_PLLON_MASK               64U
#define PLLCTL_CME_MASK                 128U
#define PLLCTL_FM_MASK                  48U
#define PLLCTL_FM_BITNUM                4U


/*** RTICTL - ECRG RTI Control Register; 0x0000003B ***/
typedef union {
  byte Byte;
  struct {
    byte RTR0        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 0 */
    byte RTR1        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 1 */
    byte RTR2        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 2 */
    byte RTR3        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 3 */
    byte RTR4        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 4 */
    byte RTR5        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 5 */
    byte RTR6        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 6 */
    byte RTDEC       :1;                                       /* Decimal or Binary Divider Select Bit */
  } Bits;
  struct {
    byte grpRTR  :7;
    byte         :1;
  } MergedBits;
} RTICTLSTR;
extern volatile RTICTLSTR _RTICTL @(REG_BASE + 0x0000003BUL);
#define RTICTL                          _RTICTL.Byte
#define RTICTL_RTR0                     _RTICTL.Bits.RTR0
#define RTICTL_RTR1                     _RTICTL.Bits.RTR1
#define RTICTL_RTR2                     _RTICTL.Bits.RTR2
#define RTICTL_RTR3                     _RTICTL.Bits.RTR3
#define RTICTL_RTR4                     _RTICTL.Bits.RTR4
#define RTICTL_RTR5                     _RTICTL.Bits.RTR5
#define RTICTL_RTR6                     _RTICTL.Bits.RTR6
#define RTICTL_RTDEC                    _RTICTL.Bits.RTDEC
#define RTICTL_RTR                      _RTICTL.MergedBits.grpRTR

#define RTICTL_RTR0_MASK                1U
#define RTICTL_RTR1_MASK                2U
#define RTICTL_RTR2_MASK                4U
#define RTICTL_RTR3_MASK                8U
#define RTICTL_RTR4_MASK                16U
#define RTICTL_RTR5_MASK                32U
#define RTICTL_RTR6_MASK                64U
#define RTICTL_RTDEC_MASK               128U
#define RTICTL_RTR_MASK                 127U
#define RTICTL_RTR_BITNUM               0U


/*** COPCTL - CRG COP Control Register; 0x0000003C ***/
typedef union {
  byte Byte;
  struct {
    byte CR0         :1;                                       /* COP Watchdog Timer Rate select Bit 0 */
    byte CR1         :1;                                       /* COP Watchdog Timer Rate select Bit 1 */
    byte CR2         :1;                                       /* COP Watchdog Timer Rate select Bit 2 */
    byte             :1; 
    byte             :1; 
    byte WRTMASK     :1;                                       /* Write Mask for WCOP */
    byte RSBCK       :1;                                       /* COP and RTI stop in Active BDM mode Bit */
    byte WCOP        :1;                                       /* Window COP mode */
  } Bits;
  struct {
    byte grpCR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} COPCTLSTR;
extern volatile COPCTLSTR _COPCTL @(REG_BASE + 0x0000003CUL);
#define COPCTL                          _COPCTL.Byte
#define COPCTL_CR0                      _COPCTL.Bits.CR0
#define COPCTL_CR1                      _COPCTL.Bits.CR1
#define COPCTL_CR2                      _COPCTL.Bits.CR2
#define COPCTL_WRTMASK                  _COPCTL.Bits.WRTMASK
#define COPCTL_RSBCK                    _COPCTL.Bits.RSBCK
#define COPCTL_WCOP                     _COPCTL.Bits.WCOP
#define COPCTL_CR                       _COPCTL.MergedBits.grpCR

#define COPCTL_CR0_MASK                 1U
#define COPCTL_CR1_MASK                 2U
#define COPCTL_CR2_MASK                 4U
#define COPCTL_WRTMASK_MASK             32U
#define COPCTL_RSBCK_MASK               64U
#define COPCTL_WCOP_MASK                128U
#define COPCTL_CR_MASK                  7U
#define COPCTL_CR_BITNUM                0U


/*** ARMCOP - CRG COP Timer Arm/Reset Register; 0x0000003F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* CRG COP Timer Arm/Reset Bit 0 */
    byte BIT1        :1;                                       /* CRG COP Timer Arm/Reset Bit 1 */
    byte BIT2        :1;                                       /* CRG COP Timer Arm/Reset Bit 2 */
    byte BIT3        :1;                                       /* CRG COP Timer Arm/Reset Bit 3 */
    byte BIT4        :1;                                       /* CRG COP Timer Arm/Reset Bit 4 */
    byte BIT5        :1;                                       /* CRG COP Timer Arm/Reset Bit 5 */
    byte BIT6        :1;                                       /* CRG COP Timer Arm/Reset Bit 6 */
    byte BIT7        :1;                                       /* CRG COP Timer Arm/Reset Bit 7 */
  } Bits;
} ARMCOPSTR;
extern volatile ARMCOPSTR _ARMCOP @(REG_BASE + 0x0000003FUL);
#define ARMCOP                          _ARMCOP.Byte
#define ARMCOP_BIT0                     _ARMCOP.Bits.BIT0
#define ARMCOP_BIT1                     _ARMCOP.Bits.BIT1
#define ARMCOP_BIT2                     _ARMCOP.Bits.BIT2
#define ARMCOP_BIT3                     _ARMCOP.Bits.BIT3
#define ARMCOP_BIT4                     _ARMCOP.Bits.BIT4
#define ARMCOP_BIT5                     _ARMCOP.Bits.BIT5
#define ARMCOP_BIT6                     _ARMCOP.Bits.BIT6
#define ARMCOP_BIT7                     _ARMCOP.Bits.BIT7

#define ARMCOP_BIT0_MASK                1U
#define ARMCOP_BIT1_MASK                2U
#define ARMCOP_BIT2_MASK                4U
#define ARMCOP_BIT3_MASK                8U
#define ARMCOP_BIT4_MASK                16U
#define ARMCOP_BIT5_MASK                32U
#define ARMCOP_BIT6_MASK                64U
#define ARMCOP_BIT7_MASK                128U


/*** TIOS - Timer Input Capture/Output Compare Select; 0x00000040 ***/
typedef union {
  byte Byte;
  struct {
    byte IOS0        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 0 */
    byte IOS1        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 1 */
    byte IOS2        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 2 */
    byte IOS3        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 3 */
    byte IOS4        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 4 */
    byte IOS5        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 5 */
    byte IOS6        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 6 */
    byte IOS7        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 7 */
  } Bits;
} TIOSSTR;
extern volatile TIOSSTR _TIOS @(REG_BASE + 0x00000040UL);
#define TIOS                            _TIOS.Byte
#define TIOS_IOS0                       _TIOS.Bits.IOS0
#define TIOS_IOS1                       _TIOS.Bits.IOS1
#define TIOS_IOS2                       _TIOS.Bits.IOS2
#define TIOS_IOS3                       _TIOS.Bits.IOS3
#define TIOS_IOS4                       _TIOS.Bits.IOS4
#define TIOS_IOS5                       _TIOS.Bits.IOS5
#define TIOS_IOS6                       _TIOS.Bits.IOS6
#define TIOS_IOS7                       _TIOS.Bits.IOS7

#define TIOS_IOS0_MASK                  1U
#define TIOS_IOS1_MASK                  2U
#define TIOS_IOS2_MASK                  4U
#define TIOS_IOS3_MASK                  8U
#define TIOS_IOS4_MASK                  16U
#define TIOS_IOS5_MASK                  32U
#define TIOS_IOS6_MASK                  64U
#define TIOS_IOS7_MASK                  128U


/*** CFORC - Timer Compare Force Register; 0x00000041 ***/
typedef union {
  byte Byte;
  struct {
    byte FOC0        :1;                                       /* Force Output Compare Action for Channel 0 */
    byte FOC1        :1;                                       /* Force Output Compare Action for Channel 1 */
    byte FOC2        :1;                                       /* Force Output Compare Action for Channel 2 */
    byte FOC3        :1;                                       /* Force Output Compare Action for Channel 3 */
    byte FOC4        :1;                                       /* Force Output Compare Action for Channel 4 */
    byte FOC5        :1;                                       /* Force Output Compare Action for Channel 5 */
    byte FOC6        :1;                                       /* Force Output Compare Action for Channel 6 */
    byte FOC7        :1;                                       /* Force Output Compare Action for Channel 7 */
  } Bits;
} CFORCSTR;
extern volatile CFORCSTR _CFORC @(REG_BASE + 0x00000041UL);
#define CFORC                           _CFORC.Byte
#define CFORC_FOC0                      _CFORC.Bits.FOC0
#define CFORC_FOC1                      _CFORC.Bits.FOC1
#define CFORC_FOC2                      _CFORC.Bits.FOC2
#define CFORC_FOC3                      _CFORC.Bits.FOC3
#define CFORC_FOC4                      _CFORC.Bits.FOC4
#define CFORC_FOC5                      _CFORC.Bits.FOC5
#define CFORC_FOC6                      _CFORC.Bits.FOC6
#define CFORC_FOC7                      _CFORC.Bits.FOC7

#define CFORC_FOC0_MASK                 1U
#define CFORC_FOC1_MASK                 2U
#define CFORC_FOC2_MASK                 4U
#define CFORC_FOC3_MASK                 8U
#define CFORC_FOC4_MASK                 16U
#define CFORC_FOC5_MASK                 32U
#define CFORC_FOC6_MASK                 64U
#define CFORC_FOC7_MASK                 128U


/*** OC7M - Output Compare 7 Mask Register; 0x00000042 ***/
typedef union {
  byte Byte;
  struct {
    byte OC7M0       :1;                                       /* Output Compare 7 Mask Bit 0 */
    byte OC7M1       :1;                                       /* Output Compare 7 Mask Bit 1 */
    byte OC7M2       :1;                                       /* Output Compare 7 Mask Bit 2 */
    byte OC7M3       :1;                                       /* Output Compare 7 Mask Bit 3 */
    byte OC7M4       :1;                                       /* Output Compare 7 Mask Bit 4 */
    byte OC7M5       :1;                                       /* Output Compare 7 Mask Bit 5 */
    byte OC7M6       :1;                                       /* Output Compare 7 Mask Bit 6 */
    byte OC7M7       :1;                                       /* Output Compare 7 Mask Bit 7 */
  } Bits;
} OC7MSTR;
extern volatile OC7MSTR _OC7M @(REG_BASE + 0x00000042UL);
#define OC7M                            _OC7M.Byte
#define OC7M_OC7M0                      _OC7M.Bits.OC7M0
#define OC7M_OC7M1                      _OC7M.Bits.OC7M1
#define OC7M_OC7M2                      _OC7M.Bits.OC7M2
#define OC7M_OC7M3                      _OC7M.Bits.OC7M3
#define OC7M_OC7M4                      _OC7M.Bits.OC7M4
#define OC7M_OC7M5                      _OC7M.Bits.OC7M5
#define OC7M_OC7M6                      _OC7M.Bits.OC7M6
#define OC7M_OC7M7                      _OC7M.Bits.OC7M7

#define OC7M_OC7M0_MASK                 1U
#define OC7M_OC7M1_MASK                 2U
#define OC7M_OC7M2_MASK                 4U
#define OC7M_OC7M3_MASK                 8U
#define OC7M_OC7M4_MASK                 16U
#define OC7M_OC7M5_MASK                 32U
#define OC7M_OC7M6_MASK                 64U
#define OC7M_OC7M7_MASK                 128U


/*** OC7D - Output Compare 7 Data Register; 0x00000043 ***/
typedef union {
  byte Byte;
  struct {
    byte OC7D0       :1;                                       /* Output Compare 7 Bit 0 */
    byte OC7D1       :1;                                       /* Output Compare 7 Bit 1 */
    byte OC7D2       :1;                                       /* Output Compare 7 Bit 2 */
    byte OC7D3       :1;                                       /* Output Compare 7 Bit 3 */
    byte OC7D4       :1;                                       /* Output Compare 7 Bit 4 */
    byte OC7D5       :1;                                       /* Output Compare 7 Bit 5 */
    byte OC7D6       :1;                                       /* Output Compare 7 Bit 6 */
    byte OC7D7       :1;                                       /* Output Compare 7 Bit 7 */
  } Bits;
} OC7DSTR;
extern volatile OC7DSTR _OC7D @(REG_BASE + 0x00000043UL);
#define OC7D                            _OC7D.Byte
#define OC7D_OC7D0                      _OC7D.Bits.OC7D0
#define OC7D_OC7D1                      _OC7D.Bits.OC7D1
#define OC7D_OC7D2                      _OC7D.Bits.OC7D2
#define OC7D_OC7D3                      _OC7D.Bits.OC7D3
#define OC7D_OC7D4                      _OC7D.Bits.OC7D4
#define OC7D_OC7D5                      _OC7D.Bits.OC7D5
#define OC7D_OC7D6                      _OC7D.Bits.OC7D6
#define OC7D_OC7D7                      _OC7D.Bits.OC7D7

#define OC7D_OC7D0_MASK                 1U
#define OC7D_OC7D1_MASK                 2U
#define OC7D_OC7D2_MASK                 4U
#define OC7D_OC7D3_MASK                 8U
#define OC7D_OC7D4_MASK                 16U
#define OC7D_OC7D5_MASK                 32U
#define OC7D_OC7D6_MASK                 64U
#define OC7D_OC7D7_MASK                 128U


/*** TCNT - Timer Count Register; 0x00000044 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TCNTHi - Timer Count Register High; 0x00000044 ***/
    union {
      byte Byte;
    } TCNTHiSTR;
    #define TCNTHi                      _TCNT.Overlap_STR.TCNTHiSTR.Byte
    

    /*** TCNTLo - Timer Count Register Low; 0x00000045 ***/
    union {
      byte Byte;
    } TCNTLoSTR;
    #define TCNTLo                      _TCNT.Overlap_STR.TCNTLoSTR.Byte
    
  } Overlap_STR;

} TCNTSTR;
extern volatile TCNTSTR _TCNT @(REG_BASE + 0x00000044UL);
#define TCNT                            _TCNT.Word


/*** TSCR1 - Timer System Control Register1; 0x00000046 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PRNT        :1;                                       /* Precision Timer */
    byte TFFCA       :1;                                       /* Timer Fast Flag Clear All */
    byte TSFRZ       :1;                                       /* Timer and Modulus Counter Stop While in Freeze Mode */
    byte TSWAI       :1;                                       /* Timer Module Stops While in Wait */
    byte TEN         :1;                                       /* Timer Enable */
  } Bits;
} TSCR1STR;
extern volatile TSCR1STR _TSCR1 @(REG_BASE + 0x00000046UL);
#define TSCR1                           _TSCR1.Byte
#define TSCR1_PRNT                      _TSCR1.Bits.PRNT
#define TSCR1_TFFCA                     _TSCR1.Bits.TFFCA
#define TSCR1_TSFRZ                     _TSCR1.Bits.TSFRZ
#define TSCR1_TSWAI                     _TSCR1.Bits.TSWAI
#define TSCR1_TEN                       _TSCR1.Bits.TEN

#define TSCR1_PRNT_MASK                 8U
#define TSCR1_TFFCA_MASK                16U
#define TSCR1_TSFRZ_MASK                32U
#define TSCR1_TSWAI_MASK                64U
#define TSCR1_TEN_MASK                  128U


/*** TTOV - Timer Toggle On Overflow Register; 0x00000047 ***/
typedef union {
  byte Byte;
  struct {
    byte TOV0        :1;                                       /* Toggle On Overflow Bit 0 */
    byte TOV1        :1;                                       /* Toggle On Overflow Bit 1 */
    byte TOV2        :1;                                       /* Toggle On Overflow Bit 2 */
    byte TOV3        :1;                                       /* Toggle On Overflow Bit 3 */
    byte TOV4        :1;                                       /* Toggle On Overflow Bit 4 */
    byte TOV5        :1;                                       /* Toggle On Overflow Bit 5 */
    byte TOV6        :1;                                       /* Toggle On Overflow Bit 6 */
    byte TOV7        :1;                                       /* Toggle On Overflow Bit 7 */
  } Bits;
} TTOVSTR;
extern volatile TTOVSTR _TTOV @(REG_BASE + 0x00000047UL);
#define TTOV                            _TTOV.Byte
#define TTOV_TOV0                       _TTOV.Bits.TOV0
#define TTOV_TOV1                       _TTOV.Bits.TOV1
#define TTOV_TOV2                       _TTOV.Bits.TOV2
#define TTOV_TOV3                       _TTOV.Bits.TOV3
#define TTOV_TOV4                       _TTOV.Bits.TOV4
#define TTOV_TOV5                       _TTOV.Bits.TOV5
#define TTOV_TOV6                       _TTOV.Bits.TOV6
#define TTOV_TOV7                       _TTOV.Bits.TOV7

#define TTOV_TOV0_MASK                  1U
#define TTOV_TOV1_MASK                  2U
#define TTOV_TOV2_MASK                  4U
#define TTOV_TOV3_MASK                  8U
#define TTOV_TOV4_MASK                  16U
#define TTOV_TOV5_MASK                  32U
#define TTOV_TOV6_MASK                  64U
#define TTOV_TOV7_MASK                  128U


/*** TCTL1 - Timer Control Register 1; 0x00000048 ***/
typedef union {
  byte Byte;
  struct {
    byte OL4         :1;                                       /* Output Level Bit 4 */
    byte OM4         :1;                                       /* Output Mode Bit 4 */
    byte OL5         :1;                                       /* Output Level Bit 5 */
    byte OM5         :1;                                       /* Output Mode Bit 5 */
    byte OL6         :1;                                       /* Output Level Bit 6 */
    byte OM6         :1;                                       /* Output Mode Bit 6 */
    byte OL7         :1;                                       /* Output Level Bit 7 */
    byte OM7         :1;                                       /* Output Mode Bit 7 */
  } Bits;
} TCTL1STR;
extern volatile TCTL1STR _TCTL1 @(REG_BASE + 0x00000048UL);
#define TCTL1                           _TCTL1.Byte
#define TCTL1_OL4                       _TCTL1.Bits.OL4
#define TCTL1_OM4                       _TCTL1.Bits.OM4
#define TCTL1_OL5                       _TCTL1.Bits.OL5
#define TCTL1_OM5                       _TCTL1.Bits.OM5
#define TCTL1_OL6                       _TCTL1.Bits.OL6
#define TCTL1_OM6                       _TCTL1.Bits.OM6
#define TCTL1_OL7                       _TCTL1.Bits.OL7
#define TCTL1_OM7                       _TCTL1.Bits.OM7

#define TCTL1_OL4_MASK                  1U
#define TCTL1_OM4_MASK                  2U
#define TCTL1_OL5_MASK                  4U
#define TCTL1_OM5_MASK                  8U
#define TCTL1_OL6_MASK                  16U
#define TCTL1_OM6_MASK                  32U
#define TCTL1_OL7_MASK                  64U
#define TCTL1_OM7_MASK                  128U


/*** TCTL2 - Timer Control Register 2; 0x00000049 ***/
typedef union {
  byte Byte;
  struct {
    byte OL0         :1;                                       /* Output Level Bit 0 */
    byte OM0         :1;                                       /* Output Mode Bit 0 */
    byte OL1         :1;                                       /* Output Lecel Bit 1 */
    byte OM1         :1;                                       /* Output Mode Bit 1 */
    byte OL2         :1;                                       /* Output Level Bit 2 */
    byte OM2         :1;                                       /* Output Mode Bit 2 */
    byte OL3         :1;                                       /* Output Level Bit 3 */
    byte OM3         :1;                                       /* Output Mode Bit 3 */
  } Bits;
} TCTL2STR;
extern volatile TCTL2STR _TCTL2 @(REG_BASE + 0x00000049UL);
#define TCTL2                           _TCTL2.Byte
#define TCTL2_OL0                       _TCTL2.Bits.OL0
#define TCTL2_OM0                       _TCTL2.Bits.OM0
#define TCTL2_OL1                       _TCTL2.Bits.OL1
#define TCTL2_OM1                       _TCTL2.Bits.OM1
#define TCTL2_OL2                       _TCTL2.Bits.OL2
#define TCTL2_OM2                       _TCTL2.Bits.OM2
#define TCTL2_OL3                       _TCTL2.Bits.OL3
#define TCTL2_OM3                       _TCTL2.Bits.OM3

#define TCTL2_OL0_MASK                  1U
#define TCTL2_OM0_MASK                  2U
#define TCTL2_OL1_MASK                  4U
#define TCTL2_OM1_MASK                  8U
#define TCTL2_OL2_MASK                  16U
#define TCTL2_OM2_MASK                  32U
#define TCTL2_OL3_MASK                  64U
#define TCTL2_OM3_MASK                  128U


/*** TCTL3 - Timer Control Register 3; 0x0000004A ***/
typedef union {
  byte Byte;
  struct {
    byte EDG4A       :1;                                       /* Input Capture Edge Control 4A */
    byte EDG4B       :1;                                       /* Input Capture Edge Control 4B */
    byte EDG5A       :1;                                       /* Input Capture Edge Control 5A */
    byte EDG5B       :1;                                       /* Input Capture Edge Control 5B */
    byte EDG6A       :1;                                       /* Input Capture Edge Control 6A */
    byte EDG6B       :1;                                       /* Input Capture Edge Control 6B */
    byte EDG7A       :1;                                       /* Input Capture Edge Control 7A */
    byte EDG7B       :1;                                       /* Input Capture Edge Control 7B */
  } Bits;
  struct {
    byte grpEDG4x :2;
    byte grpEDG5x :2;
    byte grpEDG6x :2;
    byte grpEDG7x :2;
  } MergedBits;
} TCTL3STR;
extern volatile TCTL3STR _TCTL3 @(REG_BASE + 0x0000004AUL);
#define TCTL3                           _TCTL3.Byte
#define TCTL3_EDG4A                     _TCTL3.Bits.EDG4A
#define TCTL3_EDG4B                     _TCTL3.Bits.EDG4B
#define TCTL3_EDG5A                     _TCTL3.Bits.EDG5A
#define TCTL3_EDG5B                     _TCTL3.Bits.EDG5B
#define TCTL3_EDG6A                     _TCTL3.Bits.EDG6A
#define TCTL3_EDG6B                     _TCTL3.Bits.EDG6B
#define TCTL3_EDG7A                     _TCTL3.Bits.EDG7A
#define TCTL3_EDG7B                     _TCTL3.Bits.EDG7B
#define TCTL3_EDG4x                     _TCTL3.MergedBits.grpEDG4x
#define TCTL3_EDG5x                     _TCTL3.MergedBits.grpEDG5x
#define TCTL3_EDG6x                     _TCTL3.MergedBits.grpEDG6x
#define TCTL3_EDG7x                     _TCTL3.MergedBits.grpEDG7x

#define TCTL3_EDG4A_MASK                1U
#define TCTL3_EDG4B_MASK                2U
#define TCTL3_EDG5A_MASK                4U
#define TCTL3_EDG5B_MASK                8U
#define TCTL3_EDG6A_MASK                16U
#define TCTL3_EDG6B_MASK                32U
#define TCTL3_EDG7A_MASK                64U
#define TCTL3_EDG7B_MASK                128U
#define TCTL3_EDG4x_MASK                3U
#define TCTL3_EDG4x_BITNUM              0U
#define TCTL3_EDG5x_MASK                12U
#define TCTL3_EDG5x_BITNUM              2U
#define TCTL3_EDG6x_MASK                48U
#define TCTL3_EDG6x_BITNUM              4U
#define TCTL3_EDG7x_MASK                192U
#define TCTL3_EDG7x_BITNUM              6U


/*** TCTL4 - Timer Control Register 4; 0x0000004B ***/
typedef union {
  byte Byte;
  struct {
    byte EDG0A       :1;                                       /* Input Capture Edge Control 0A */
    byte EDG0B       :1;                                       /* Input Capture Edge Control 0B */
    byte EDG1A       :1;                                       /* Input Capture Edge Control 1A */
    byte EDG1B       :1;                                       /* Input Capture Edge Control 1B */
    byte EDG2A       :1;                                       /* Input Capture Edge Control 2A */
    byte EDG2B       :1;                                       /* Input Capture Edge Control 2B */
    byte EDG3A       :1;                                       /* Input Capture Edge Control 3A */
    byte EDG3B       :1;                                       /* Input Capture Edge Control 3B */
  } Bits;
  struct {
    byte grpEDG0x :2;
    byte grpEDG1x :2;
    byte grpEDG2x :2;
    byte grpEDG3x :2;
  } MergedBits;
} TCTL4STR;
extern volatile TCTL4STR _TCTL4 @(REG_BASE + 0x0000004BUL);
#define TCTL4                           _TCTL4.Byte
#define TCTL4_EDG0A                     _TCTL4.Bits.EDG0A
#define TCTL4_EDG0B                     _TCTL4.Bits.EDG0B
#define TCTL4_EDG1A                     _TCTL4.Bits.EDG1A
#define TCTL4_EDG1B                     _TCTL4.Bits.EDG1B
#define TCTL4_EDG2A                     _TCTL4.Bits.EDG2A
#define TCTL4_EDG2B                     _TCTL4.Bits.EDG2B
#define TCTL4_EDG3A                     _TCTL4.Bits.EDG3A
#define TCTL4_EDG3B                     _TCTL4.Bits.EDG3B
#define TCTL4_EDG0x                     _TCTL4.MergedBits.grpEDG0x
#define TCTL4_EDG1x                     _TCTL4.MergedBits.grpEDG1x
#define TCTL4_EDG2x                     _TCTL4.MergedBits.grpEDG2x
#define TCTL4_EDG3x                     _TCTL4.MergedBits.grpEDG3x

#define TCTL4_EDG0A_MASK                1U
#define TCTL4_EDG0B_MASK                2U
#define TCTL4_EDG1A_MASK                4U
#define TCTL4_EDG1B_MASK                8U
#define TCTL4_EDG2A_MASK                16U
#define TCTL4_EDG2B_MASK                32U
#define TCTL4_EDG3A_MASK                64U
#define TCTL4_EDG3B_MASK                128U
#define TCTL4_EDG0x_MASK                3U
#define TCTL4_EDG0x_BITNUM              0U
#define TCTL4_EDG1x_MASK                12U
#define TCTL4_EDG1x_BITNUM              2U
#define TCTL4_EDG2x_MASK                48U
#define TCTL4_EDG2x_BITNUM              4U
#define TCTL4_EDG3x_MASK                192U
#define TCTL4_EDG3x_BITNUM              6U


/*** TIE - Timer Interrupt Enable Register; 0x0000004C ***/
typedef union {
  byte Byte;
  struct {
    byte C0I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 0 */
    byte C1I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 1 */
    byte C2I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 2 */
    byte C3I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 3 */
    byte C4I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 4 */
    byte C5I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 5 */
    byte C6I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 6 */
    byte C7I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 7 */
  } Bits;
} TIESTR;
extern volatile TIESTR _TIE @(REG_BASE + 0x0000004CUL);
#define TIE                             _TIE.Byte
#define TIE_C0I                         _TIE.Bits.C0I
#define TIE_C1I                         _TIE.Bits.C1I
#define TIE_C2I                         _TIE.Bits.C2I
#define TIE_C3I                         _TIE.Bits.C3I
#define TIE_C4I                         _TIE.Bits.C4I
#define TIE_C5I                         _TIE.Bits.C5I
#define TIE_C6I                         _TIE.Bits.C6I
#define TIE_C7I                         _TIE.Bits.C7I

#define TIE_C0I_MASK                    1U
#define TIE_C1I_MASK                    2U
#define TIE_C2I_MASK                    4U
#define TIE_C3I_MASK                    8U
#define TIE_C4I_MASK                    16U
#define TIE_C5I_MASK                    32U
#define TIE_C6I_MASK                    64U
#define TIE_C7I_MASK                    128U


/*** TSCR2 - Timer System Control Register 2; 0x0000004D ***/
typedef union {
  byte Byte;
  struct {
    byte PR0         :1;                                       /* Timer Prescaler Select Bit 0 */
    byte PR1         :1;                                       /* Timer Prescaler Select Bit 1 */
    byte PR2         :1;                                       /* Timer Prescaler Select Bit 2 */
    byte TCRE        :1;                                       /* Timer Counter Reset Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOI         :1;                                       /* Timer Overflow Interrupt Enable */
  } Bits;
  struct {
    byte grpPR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TSCR2STR;
extern volatile TSCR2STR _TSCR2 @(REG_BASE + 0x0000004DUL);
#define TSCR2                           _TSCR2.Byte
#define TSCR2_PR0                       _TSCR2.Bits.PR0
#define TSCR2_PR1                       _TSCR2.Bits.PR1
#define TSCR2_PR2                       _TSCR2.Bits.PR2
#define TSCR2_TCRE                      _TSCR2.Bits.TCRE
#define TSCR2_TOI                       _TSCR2.Bits.TOI
#define TSCR2_PR                        _TSCR2.MergedBits.grpPR

#define TSCR2_PR0_MASK                  1U
#define TSCR2_PR1_MASK                  2U
#define TSCR2_PR2_MASK                  4U
#define TSCR2_TCRE_MASK                 8U
#define TSCR2_TOI_MASK                  128U
#define TSCR2_PR_MASK                   7U
#define TSCR2_PR_BITNUM                 0U


/*** TFLG1 - Main Timer Interrupt Flag 1; 0x0000004E ***/
typedef union {
  byte Byte;
  struct {
    byte C0F         :1;                                       /* Input Capture/Output Compare Channel Flag 0 */
    byte C1F         :1;                                       /* Input Capture/Output Compare Channel Flag 1 */
    byte C2F         :1;                                       /* Input Capture/Output Compare Channel Flag 2 */
    byte C3F         :1;                                       /* Input Capture/Output Compare Channel Flag 3 */
    byte C4F         :1;                                       /* Input Capture/Output Compare Channel Flag 4 */
    byte C5F         :1;                                       /* Input Capture/Output Compare Channel Flag 5 */
    byte C6F         :1;                                       /* Input Capture/Output Compare Channel Flag 6 */
    byte C7F         :1;                                       /* Input Capture/Output Compare Channel Flag 7 */
  } Bits;
} TFLG1STR;
extern volatile TFLG1STR _TFLG1 @(REG_BASE + 0x0000004EUL);
#define TFLG1                           _TFLG1.Byte
#define TFLG1_C0F                       _TFLG1.Bits.C0F
#define TFLG1_C1F                       _TFLG1.Bits.C1F
#define TFLG1_C2F                       _TFLG1.Bits.C2F
#define TFLG1_C3F                       _TFLG1.Bits.C3F
#define TFLG1_C4F                       _TFLG1.Bits.C4F
#define TFLG1_C5F                       _TFLG1.Bits.C5F
#define TFLG1_C6F                       _TFLG1.Bits.C6F
#define TFLG1_C7F                       _TFLG1.Bits.C7F

#define TFLG1_C0F_MASK                  1U
#define TFLG1_C1F_MASK                  2U
#define TFLG1_C2F_MASK                  4U
#define TFLG1_C3F_MASK                  8U
#define TFLG1_C4F_MASK                  16U
#define TFLG1_C5F_MASK                  32U
#define TFLG1_C6F_MASK                  64U
#define TFLG1_C7F_MASK                  128U


/*** TFLG2 - Main Timer Interrupt Flag 2; 0x0000004F ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
} TFLG2STR;
extern volatile TFLG2STR _TFLG2 @(REG_BASE + 0x0000004FUL);
#define TFLG2                           _TFLG2.Byte
#define TFLG2_TOF                       _TFLG2.Bits.TOF

#define TFLG2_TOF_MASK                  128U


/*** TC0 - Timer Input Capture/Output Compare Register 0; 0x00000050 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC0Hi - Timer Input Capture/Output Compare Register 0 High; 0x00000050 ***/
    union {
      byte Byte;
    } TC0HiSTR;
    #define TC0Hi                       _TC0.Overlap_STR.TC0HiSTR.Byte
    

    /*** TC0Lo - Timer Input Capture/Output Compare Register 0 Low; 0x00000051 ***/
    union {
      byte Byte;
    } TC0LoSTR;
    #define TC0Lo                       _TC0.Overlap_STR.TC0LoSTR.Byte
    
  } Overlap_STR;

} TC0STR;
extern volatile TC0STR _TC0 @(REG_BASE + 0x00000050UL);
#define TC0                             _TC0.Word
/* TC_ARR: Access 8 TCx registers in an array */
#define TC_ARR                          ((volatile word *) &TC0)


/*** TC1 - Timer Input Capture/Output Compare Register 1; 0x00000052 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC1Hi - Timer Input Capture/Output Compare Register 1 High; 0x00000052 ***/
    union {
      byte Byte;
    } TC1HiSTR;
    #define TC1Hi                       _TC1.Overlap_STR.TC1HiSTR.Byte
    

    /*** TC1Lo - Timer Input Capture/Output Compare Register 1 Low; 0x00000053 ***/
    union {
      byte Byte;
    } TC1LoSTR;
    #define TC1Lo                       _TC1.Overlap_STR.TC1LoSTR.Byte
    
  } Overlap_STR;

} TC1STR;
extern volatile TC1STR _TC1 @(REG_BASE + 0x00000052UL);
#define TC1                             _TC1.Word


/*** TC2 - Timer Input Capture/Output Compare Register 2; 0x00000054 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC2Hi - Timer Input Capture/Output Compare Register 2 High; 0x00000054 ***/
    union {
      byte Byte;
    } TC2HiSTR;
    #define TC2Hi                       _TC2.Overlap_STR.TC2HiSTR.Byte
    

    /*** TC2Lo - Timer Input Capture/Output Compare Register 2 Low; 0x00000055 ***/
    union {
      byte Byte;
    } TC2LoSTR;
    #define TC2Lo                       _TC2.Overlap_STR.TC2LoSTR.Byte
    
  } Overlap_STR;

} TC2STR;
extern volatile TC2STR _TC2 @(REG_BASE + 0x00000054UL);
#define TC2                             _TC2.Word


/*** TC3 - Timer Input Capture/Output Compare Register 3; 0x00000056 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC3Hi - Timer Input Capture/Output Compare Register 3 High; 0x00000056 ***/
    union {
      byte Byte;
    } TC3HiSTR;
    #define TC3Hi                       _TC3.Overlap_STR.TC3HiSTR.Byte
    

    /*** TC3Lo - Timer Input Capture/Output Compare Register 3 Low; 0x00000057 ***/
    union {
      byte Byte;
    } TC3LoSTR;
    #define TC3Lo                       _TC3.Overlap_STR.TC3LoSTR.Byte
    
  } Overlap_STR;

} TC3STR;
extern volatile TC3STR _TC3 @(REG_BASE + 0x00000056UL);
#define TC3                             _TC3.Word


/*** TC4 - Timer Input Capture/Output Compare Register 4; 0x00000058 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC4Hi - Timer Input Capture/Output Compare Register 4 High; 0x00000058 ***/
    union {
      byte Byte;
    } TC4HiSTR;
    #define TC4Hi                       _TC4.Overlap_STR.TC4HiSTR.Byte
    

    /*** TC4Lo - Timer Input Capture/Output Compare Register 4 Low; 0x00000059 ***/
    union {
      byte Byte;
    } TC4LoSTR;
    #define TC4Lo                       _TC4.Overlap_STR.TC4LoSTR.Byte
    
  } Overlap_STR;

} TC4STR;
extern volatile TC4STR _TC4 @(REG_BASE + 0x00000058UL);
#define TC4                             _TC4.Word


/*** TC5 - Timer Input Capture/Output Compare Register 5; 0x0000005A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC5Hi - Timer Input Capture/Output Compare Register 5 High; 0x0000005A ***/
    union {
      byte Byte;
    } TC5HiSTR;
    #define TC5Hi                       _TC5.Overlap_STR.TC5HiSTR.Byte
    

    /*** TC5Lo - Timer Input Capture/Output Compare Register 5 Low; 0x0000005B ***/
    union {
      byte Byte;
    } TC5LoSTR;
    #define TC5Lo                       _TC5.Overlap_STR.TC5LoSTR.Byte
    
  } Overlap_STR;

} TC5STR;
extern volatile TC5STR _TC5 @(REG_BASE + 0x0000005AUL);
#define TC5                             _TC5.Word


/*** TC6 - Timer Input Capture/Output Compare Register 6; 0x0000005C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC6Hi - Timer Input Capture/Output Compare Register 6 High; 0x0000005C ***/
    union {
      byte Byte;
    } TC6HiSTR;
    #define TC6Hi                       _TC6.Overlap_STR.TC6HiSTR.Byte
    

    /*** TC6Lo - Timer Input Capture/Output Compare Register 6 Low; 0x0000005D ***/
    union {
      byte Byte;
    } TC6LoSTR;
    #define TC6Lo                       _TC6.Overlap_STR.TC6LoSTR.Byte
    
  } Overlap_STR;

} TC6STR;
extern volatile TC6STR _TC6 @(REG_BASE + 0x0000005CUL);
#define TC6                             _TC6.Word


/*** TC7 - Timer Input Capture/Output Compare Register 7; 0x0000005E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC7Hi - Timer Input Capture/Output Compare Register 7 High; 0x0000005E ***/
    union {
      byte Byte;
    } TC7HiSTR;
    #define TC7Hi                       _TC7.Overlap_STR.TC7HiSTR.Byte
    

    /*** TC7Lo - Timer Input Capture/Output Compare Register 7 Low; 0x0000005F ***/
    union {
      byte Byte;
    } TC7LoSTR;
    #define TC7Lo                       _TC7.Overlap_STR.TC7LoSTR.Byte
    
  } Overlap_STR;

} TC7STR;
extern volatile TC7STR _TC7 @(REG_BASE + 0x0000005EUL);
#define TC7                             _TC7.Word


/*** PACTL - 16-Bit Pulse Accumulator A Control Register; 0x00000060 ***/
typedef union {
  byte Byte;
  struct {
    byte PAI         :1;                                       /* Pulse Accumulator Input Interrupt enable */
    byte PAOVI       :1;                                       /* Pulse Accumulator A Overflow Interrupt enable */
    byte CLK0        :1;                                       /* Clock Select Bit 0 */
    byte CLK1        :1;                                       /* Clock Select Bit 1 */
    byte PEDGE       :1;                                       /* Pulse Accumulator Edge Control */
    byte PAMOD       :1;                                       /* Pulse Accumulator Mode */
    byte PAEN        :1;                                       /* Pulse Accumulator A System Enable */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpCLK  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PACTLSTR;
extern volatile PACTLSTR _PACTL @(REG_BASE + 0x00000060UL);
#define PACTL                           _PACTL.Byte
#define PACTL_PAI                       _PACTL.Bits.PAI
#define PACTL_PAOVI                     _PACTL.Bits.PAOVI
#define PACTL_CLK0                      _PACTL.Bits.CLK0
#define PACTL_CLK1                      _PACTL.Bits.CLK1
#define PACTL_PEDGE                     _PACTL.Bits.PEDGE
#define PACTL_PAMOD                     _PACTL.Bits.PAMOD
#define PACTL_PAEN                      _PACTL.Bits.PAEN
#define PACTL_CLK                       _PACTL.MergedBits.grpCLK

#define PACTL_PAI_MASK                  1U
#define PACTL_PAOVI_MASK                2U
#define PACTL_CLK0_MASK                 4U
#define PACTL_CLK1_MASK                 8U
#define PACTL_PEDGE_MASK                16U
#define PACTL_PAMOD_MASK                32U
#define PACTL_PAEN_MASK                 64U
#define PACTL_CLK_MASK                  12U
#define PACTL_CLK_BITNUM                2U


/*** PAFLG - Pulse Accumulator A Flag Register; 0x00000061 ***/
typedef union {
  byte Byte;
  struct {
    byte PAIF        :1;                                       /* Pulse Accumulator Input edge Flag */
    byte PAOVF       :1;                                       /* Pulse Accumulator A Overflow Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PAFLGSTR;
extern volatile PAFLGSTR _PAFLG @(REG_BASE + 0x00000061UL);
#define PAFLG                           _PAFLG.Byte
#define PAFLG_PAIF                      _PAFLG.Bits.PAIF
#define PAFLG_PAOVF                     _PAFLG.Bits.PAOVF

#define PAFLG_PAIF_MASK                 1U
#define PAFLG_PAOVF_MASK                2U


/*** PACNT - Pulse Accumulators Count Register; 0x00000062 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PACNTH - Pulse Accumulators Count Register High; 0x00000062 ***/
    union {
      byte Byte;
    } PACNTHSTR;
    #define PACNTH                      _PACNT.Overlap_STR.PACNTHSTR.Byte
    

    /*** PACNTL - Pulse Accumulators Count Register Low; 0x00000063 ***/
    union {
      byte Byte;
    } PACNTLSTR;
    #define PACNTL                      _PACNT.Overlap_STR.PACNTLSTR.Byte
    
  } Overlap_STR;

} PACNTSTR;
extern volatile PACNTSTR _PACNT @(REG_BASE + 0x00000062UL);
#define PACNT                           _PACNT.Word


/*** OCPD - Output Compare Pin Disconnect Register; 0x0000006C ***/
typedef union {
  byte Byte;
  struct {
    byte OCPD0       :1;                                       /* Output Compare Pin Disconnect Bit 0 */
    byte OCPD1       :1;                                       /* Output Compare Pin Disconnect Bit 1 */
    byte OCPD2       :1;                                       /* Output Compare Pin Disconnect Bit 2 */
    byte OCPD3       :1;                                       /* Output Compare Pin Disconnect Bit 3 */
    byte OCPD4       :1;                                       /* Output Compare Pin Disconnect Bit 4 */
    byte OCPD5       :1;                                       /* Output Compare Pin Disconnect Bit 5 */
    byte OCPD6       :1;                                       /* Output Compare Pin Disconnect Bit 6 */
    byte OCPD7       :1;                                       /* Output Compare Pin Disconnect Bit 7 */
  } Bits;
} OCPDSTR;
extern volatile OCPDSTR _OCPD @(REG_BASE + 0x0000006CUL);
#define OCPD                            _OCPD.Byte
#define OCPD_OCPD0                      _OCPD.Bits.OCPD0
#define OCPD_OCPD1                      _OCPD.Bits.OCPD1
#define OCPD_OCPD2                      _OCPD.Bits.OCPD2
#define OCPD_OCPD3                      _OCPD.Bits.OCPD3
#define OCPD_OCPD4                      _OCPD.Bits.OCPD4
#define OCPD_OCPD5                      _OCPD.Bits.OCPD5
#define OCPD_OCPD6                      _OCPD.Bits.OCPD6
#define OCPD_OCPD7                      _OCPD.Bits.OCPD7

#define OCPD_OCPD0_MASK                 1U
#define OCPD_OCPD1_MASK                 2U
#define OCPD_OCPD2_MASK                 4U
#define OCPD_OCPD3_MASK                 8U
#define OCPD_OCPD4_MASK                 16U
#define OCPD_OCPD5_MASK                 32U
#define OCPD_OCPD6_MASK                 64U
#define OCPD_OCPD7_MASK                 128U


/*** PTPSR - Precision Timer Prescaler Select Register; 0x0000006E ***/
typedef union {
  byte Byte;
  struct {
    byte PTPS0       :1;                                       /* Precision Timer Prescaler Select Bit 0 */
    byte PTPS1       :1;                                       /* Precision Timer Prescaler Select Bit 1 */
    byte PTPS2       :1;                                       /* Precision Timer Prescaler Select Bit 2 */
    byte PTPS3       :1;                                       /* Precision Timer Prescaler Select Bit 3 */
    byte PTPS4       :1;                                       /* Precision Timer Prescaler Select Bit 4 */
    byte PTPS5       :1;                                       /* Precision Timer Prescaler Select Bit 5 */
    byte PTPS6       :1;                                       /* Precision Timer Prescaler Select Bit 6 */
    byte PTPS7       :1;                                       /* Precision Timer Prescaler Select Bit 7 */
  } Bits;
} PTPSRSTR;
extern volatile PTPSRSTR _PTPSR @(REG_BASE + 0x0000006EUL);
#define PTPSR                           _PTPSR.Byte
#define PTPSR_PTPS0                     _PTPSR.Bits.PTPS0
#define PTPSR_PTPS1                     _PTPSR.Bits.PTPS1
#define PTPSR_PTPS2                     _PTPSR.Bits.PTPS2
#define PTPSR_PTPS3                     _PTPSR.Bits.PTPS3
#define PTPSR_PTPS4                     _PTPSR.Bits.PTPS4
#define PTPSR_PTPS5                     _PTPSR.Bits.PTPS5
#define PTPSR_PTPS6                     _PTPSR.Bits.PTPS6
#define PTPSR_PTPS7                     _PTPSR.Bits.PTPS7

#define PTPSR_PTPS0_MASK                1U
#define PTPSR_PTPS1_MASK                2U
#define PTPSR_PTPS2_MASK                4U
#define PTPSR_PTPS3_MASK                8U
#define PTPSR_PTPS4_MASK                16U
#define PTPSR_PTPS5_MASK                32U
#define PTPSR_PTPS6_MASK                64U
#define PTPSR_PTPS7_MASK                128U


/*** SCI0BD - SCI 0 Baud Rate Register; 0x000000C8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI0ASR1 - SCI 0 Alternative Status Register 1; 0x000000C8 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SCI0ASR1 - SCI 0 Alternative Status Register 1; Several registers at the same address ***/
        union {
          struct {
            byte BKDIF       :1;                                       /* Break Detect Interrupt Flag */
            byte BERRIF      :1;                                       /* Bit Error Interrupt Flag */
            byte BERRV       :1;                                       /* Bit Error Value */
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte RXEDGIF     :1;                                       /* Receive Input Active Edge Interrupt Flag */
          } Bits;
        } SCI0ASR1STR;
        #define SCI0ASR1                _SCI0BD.Overlap_STR.SCI0ASR1STR.Byte
        #define SCI0ASR1_BKDIF          _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0ASR1STR.Bits.BKDIF
        #define SCI0ASR1_BERRIF         _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0ASR1STR.Bits.BERRIF
        #define SCI0ASR1_BERRV          _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0ASR1STR.Bits.BERRV
        #define SCI0ASR1_RXEDGIF        _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0ASR1STR.Bits.RXEDGIF
        
        #define SCI0ASR1_BKDIF_MASK     1U
        #define SCI0ASR1_BERRIF_MASK    2U
        #define SCI0ASR1_BERRV_MASK     4U
        #define SCI0ASR1_RXEDGIF_MASK   128U
        
        /*** SCI0BDH - SCI 0 Baud Rate Register High; Several registers at the same address ***/
        union {
          struct {
            byte SBR8        :1;                                       /* SCI Baud Rate Bit 8 */
            byte SBR9        :1;                                       /* SCI Baud Rate Bit 9 */
            byte SBR10       :1;                                       /* SCI Baud Rate Bit 10 */
            byte SBR11       :1;                                       /* SCI Baud Rate Bit 11 */
            byte SBR12       :1;                                       /* SCI Baud Rate Bit 12 */
            byte TNP0        :1;                                       /* Transmitter Narrow Pulse Bit 0 */
            byte TNP1        :1;                                       /* Transmitter Narrow Pulse Bit 1 */
            byte IREN        :1;                                       /* Infrared Enable Bit */
          } Bits;
          struct {
            byte grpSBR_8 :5;
            byte grpTNP :2;
            byte :1;
          } MergedBits;
        } SCI0BDHSTR;
        #define SCI0BDH                 _SCI0BD.Overlap_STR.SCI0ASR1STR.Byte
        #define SCI0BDH_SBR8            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR8
        #define SCI0BDH_SBR9            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR9
        #define SCI0BDH_SBR10           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR10
        #define SCI0BDH_SBR11           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR11
        #define SCI0BDH_SBR12           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR12
        #define SCI0BDH_TNP0            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.TNP0
        #define SCI0BDH_TNP1            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.TNP1
        #define SCI0BDH_IREN            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.IREN
        #define SCI0BDH_SBR_8           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.MergedBits.grpSBR_8
        #define SCI0BDH_TNP             _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.MergedBits.grpTNP
        #define SCI0BDH_SBR             SCI0BDH_SBR_8
        
        #define SCI0BDH_SBR8_MASK       1U
        #define SCI0BDH_SBR9_MASK       2U
        #define SCI0BDH_SBR10_MASK      4U
        #define SCI0BDH_SBR11_MASK      8U
        #define SCI0BDH_SBR12_MASK      16U
        #define SCI0BDH_TNP0_MASK       32U
        #define SCI0BDH_TNP1_MASK       64U
        #define SCI0BDH_IREN_MASK       128U
        #define SCI0BDH_SBR_8_MASK      31U
        #define SCI0BDH_SBR_8_BITNUM    0U
        #define SCI0BDH_TNP_MASK        96U
        #define SCI0BDH_TNP_BITNUM      5U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SCI0ASR1STR;
    

    /*** SCI0ACR1 - SCI 0 Alternative Control Register 1; 0x000000C9 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SCI0ACR1 - SCI 0 Alternative Control Register 1; Several registers at the same address ***/
        union {
          struct {
            byte BKDIE       :1;                                       /* Break Detect Interrupt Enable */
            byte BERRIE      :1;                                       /* Bit Error Interrupt Enable */
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte RXEDGIE     :1;                                       /* Receive Input Active Edge Interrupt Enable */
          } Bits;
        } SCI0ACR1STR;
        #define SCI0ACR1                _SCI0BD.Overlap_STR.SCI0ACR1STR.Byte
        #define SCI0ACR1_BKDIE          _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0ACR1STR.Bits.BKDIE
        #define SCI0ACR1_BERRIE         _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0ACR1STR.Bits.BERRIE
        #define SCI0ACR1_RXEDGIE        _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0ACR1STR.Bits.RXEDGIE
        
        #define SCI0ACR1_BKDIE_MASK     1U
        #define SCI0ACR1_BERRIE_MASK    2U
        #define SCI0ACR1_RXEDGIE_MASK   128U
        
        /*** SCI0BDL - SCI 0 Baud Rate Register Low; Several registers at the same address ***/
        union {
          struct {
            byte SBR0        :1;                                       /* SCI Baud Rate Bit 0 */
            byte SBR1        :1;                                       /* SCI Baud Rate Bit 1 */
            byte SBR2        :1;                                       /* SCI Baud Rate Bit 2 */
            byte SBR3        :1;                                       /* SCI Baud Rate Bit 3 */
            byte SBR4        :1;                                       /* SCI Baud Rate Bit 4 */
            byte SBR5        :1;                                       /* SCI Baud Rate Bit 5 */
            byte SBR6        :1;                                       /* SCI Baud Rate Bit 6 */
            byte SBR7        :1;                                       /* SCI Baud Rate Bit 7 */
          } Bits;
        } SCI0BDLSTR;
        #define SCI0BDL                 _SCI0BD.Overlap_STR.SCI0ACR1STR.Byte
        #define SCI0BDL_SBR0            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR0
        #define SCI0BDL_SBR1            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR1
        #define SCI0BDL_SBR2            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR2
        #define SCI0BDL_SBR3            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR3
        #define SCI0BDL_SBR4            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR4
        #define SCI0BDL_SBR5            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR5
        #define SCI0BDL_SBR6            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR6
        #define SCI0BDL_SBR7            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR7
        
        #define SCI0BDL_SBR0_MASK       1U
        #define SCI0BDL_SBR1_MASK       2U
        #define SCI0BDL_SBR2_MASK       4U
        #define SCI0BDL_SBR3_MASK       8U
        #define SCI0BDL_SBR4_MASK       16U
        #define SCI0BDL_SBR5_MASK       32U
        #define SCI0BDL_SBR6_MASK       64U
        #define SCI0BDL_SBR7_MASK       128U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SCI0ACR1STR;
    
  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* SCI Baud Rate Bit 0 */
    word SBR1        :1;                                       /* SCI Baud Rate Bit 1 */
    word SBR2        :1;                                       /* SCI Baud Rate Bit 2 */
    word SBR3        :1;                                       /* SCI Baud Rate Bit 3 */
    word SBR4        :1;                                       /* SCI Baud Rate Bit 4 */
    word SBR5        :1;                                       /* SCI Baud Rate Bit 5 */
    word SBR6        :1;                                       /* SCI Baud Rate Bit 6 */
    word SBR7        :1;                                       /* SCI Baud Rate Bit 7 */
    word SBR8        :1;                                       /* SCI Baud Rate Bit 8 */
    word SBR9        :1;                                       /* SCI Baud Rate Bit 9 */
    word SBR10       :1;                                       /* SCI Baud Rate Bit 10 */
    word SBR11       :1;                                       /* SCI Baud Rate Bit 11 */
    word SBR12       :1;                                       /* SCI Baud Rate Bit 12 */
    word TNP0        :1;                                       /* Transmitter Narrow Pulse Bit 0 */
    word TNP1        :1;                                       /* Transmitter Narrow Pulse Bit 1 */
    word IREN        :1;                                       /* Infrared Enable Bit */
  } Bits;
  struct {
    word grpSBR  :13;
    word grpTNP  :2;
    word         :1;
  } MergedBits;
} SCI0BDSTR;
extern volatile SCI0BDSTR _SCI0BD @(REG_BASE + 0x000000C8UL);
#define SCI0BD                          _SCI0BD.Word
#define SCI0BD_SBR0                     _SCI0BD.Bits.SBR0
#define SCI0BD_SBR1                     _SCI0BD.Bits.SBR1
#define SCI0BD_SBR2                     _SCI0BD.Bits.SBR2
#define SCI0BD_SBR3                     _SCI0BD.Bits.SBR3
#define SCI0BD_SBR4                     _SCI0BD.Bits.SBR4
#define SCI0BD_SBR5                     _SCI0BD.Bits.SBR5
#define SCI0BD_SBR6                     _SCI0BD.Bits.SBR6
#define SCI0BD_SBR7                     _SCI0BD.Bits.SBR7
#define SCI0BD_SBR8                     _SCI0BD.Bits.SBR8
#define SCI0BD_SBR9                     _SCI0BD.Bits.SBR9
#define SCI0BD_SBR10                    _SCI0BD.Bits.SBR10
#define SCI0BD_SBR11                    _SCI0BD.Bits.SBR11
#define SCI0BD_SBR12                    _SCI0BD.Bits.SBR12
#define SCI0BD_TNP0                     _SCI0BD.Bits.TNP0
#define SCI0BD_TNP1                     _SCI0BD.Bits.TNP1
#define SCI0BD_IREN                     _SCI0BD.Bits.IREN
#define SCI0BD_SBR                      _SCI0BD.MergedBits.grpSBR
#define SCI0BD_TNP                      _SCI0BD.MergedBits.grpTNP

#define SCI0BD_SBR0_MASK                1U
#define SCI0BD_SBR1_MASK                2U
#define SCI0BD_SBR2_MASK                4U
#define SCI0BD_SBR3_MASK                8U
#define SCI0BD_SBR4_MASK                16U
#define SCI0BD_SBR5_MASK                32U
#define SCI0BD_SBR6_MASK                64U
#define SCI0BD_SBR7_MASK                128U
#define SCI0BD_SBR8_MASK                256U
#define SCI0BD_SBR9_MASK                512U
#define SCI0BD_SBR10_MASK               1024U
#define SCI0BD_SBR11_MASK               2048U
#define SCI0BD_SBR12_MASK               4096U
#define SCI0BD_TNP0_MASK                8192U
#define SCI0BD_TNP1_MASK                16384U
#define SCI0BD_IREN_MASK                32768U
#define SCI0BD_SBR_MASK                 8191U
#define SCI0BD_SBR_BITNUM               0U
#define SCI0BD_TNP_MASK                 24576U
#define SCI0BD_TNP_BITNUM               13U


/*** SCI0ACR2 - SCI 0 Alternative Control Register 2; 0x000000CA ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** SCI0ACR2 - SCI 0 Alternative Control Register 2; Several registers at the same address ***/
    union {
      struct {
        byte BKDFE       :1;                                       /* Break Detect Feature Enable */
        byte BERRM0      :1;                                       /* Bit Error Mode 0 */
        byte BERRM1      :1;                                       /* Bit Error Mode 1 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte     :1;
        byte grpBERRM :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI0ACR2STR;
    #define SCI0ACR2                    _SCI0ACR2.Byte
    #define SCI0ACR2_BKDFE              _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.BKDFE
    #define SCI0ACR2_BERRM0             _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.BERRM0
    #define SCI0ACR2_BERRM1             _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.BERRM1
    #define SCI0ACR2_BERRM              _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.MergedBits.grpBERRM
    
    #define SCI0ACR2_BKDFE_MASK         1U
    #define SCI0ACR2_BERRM0_MASK        2U
    #define SCI0ACR2_BERRM1_MASK        4U
    #define SCI0ACR2_BERRM_MASK         6U
    #define SCI0ACR2_BERRM_BITNUM       1U
    
    /*** SCI0CR1 - SCI 0 Control Register 1; Several registers at the same address ***/
    union {
      struct {
        byte PT          :1;                                       /* Parity Type Bit */
        byte PE          :1;                                       /* Parity Enable Bit */
        byte ILT         :1;                                       /* Idle Line Type Bit */
        byte WAKE        :1;                                       /* Wakeup Condition Bit */
        byte M           :1;                                       /* Data Format Mode Bit */
        byte RSRC        :1;                                       /* Receiver Source Bit */
        byte SCISWAI     :1;                                       /* SCI Stop in Wait Mode Bit */
        byte LOOPS       :1;                                       /* Loop Select Bit */
      } Bits;
    } SCI0CR1STR;
    #define SCI0CR1                     _SCI0ACR2.Byte
    #define SCI0CR1_PT                  _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.PT
    #define SCI0CR1_PE                  _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.PE
    #define SCI0CR1_ILT                 _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.ILT
    #define SCI0CR1_WAKE                _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.WAKE
    #define SCI0CR1_M                   _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.M
    #define SCI0CR1_RSRC                _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.RSRC
    #define SCI0CR1_SCISWAI             _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.SCISWAI
    #define SCI0CR1_LOOPS               _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.LOOPS
    
    #define SCI0CR1_PT_MASK             1U
    #define SCI0CR1_PE_MASK             2U
    #define SCI0CR1_ILT_MASK            4U
    #define SCI0CR1_WAKE_MASK           8U
    #define SCI0CR1_M_MASK              16U
    #define SCI0CR1_RSRC_MASK           32U
    #define SCI0CR1_SCISWAI_MASK        64U
    #define SCI0CR1_LOOPS_MASK          128U
    
  } SameAddr_STR; /*Several registers at the same address */

} SCI0ACR2STR;
extern volatile SCI0ACR2STR _SCI0ACR2 @(REG_BASE + 0x000000CAUL);


/*** SCI0CR2 - SCI 0 Control Register 2; 0x000000CB ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break Bit */
    byte RWU         :1;                                       /* Receiver Wakeup Bit */
    byte RE          :1;                                       /* Receiver Enable Bit */
    byte TE          :1;                                       /* Transmitter Enable Bit */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable Bit */
    byte RIE         :1;                                       /* Receiver Full Interrupt Enable Bit */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable Bit */
    byte TIE_bit     :1;                                       /* Transmitter Interrupt Enable Bit */ /*Warning: bit name is duplicated with register name*/
  } Bits;
} SCI0CR2STR;
extern volatile SCI0CR2STR _SCI0CR2 @(REG_BASE + 0x000000CBUL);
#define SCI0CR2                         _SCI0CR2.Byte
#define SCI0CR2_SBK                     _SCI0CR2.Bits.SBK
#define SCI0CR2_RWU                     _SCI0CR2.Bits.RWU
#define SCI0CR2_RE                      _SCI0CR2.Bits.RE
#define SCI0CR2_TE                      _SCI0CR2.Bits.TE
#define SCI0CR2_ILIE                    _SCI0CR2.Bits.ILIE
#define SCI0CR2_RIE                     _SCI0CR2.Bits.RIE
#define SCI0CR2_TCIE                    _SCI0CR2.Bits.TCIE
#define SCI0CR2_TIE                     _SCI0CR2.Bits.TIE_bit

#define SCI0CR2_SBK_MASK                1U
#define SCI0CR2_RWU_MASK                2U
#define SCI0CR2_RE_MASK                 4U
#define SCI0CR2_TE_MASK                 8U
#define SCI0CR2_ILIE_MASK               16U
#define SCI0CR2_RIE_MASK                32U
#define SCI0CR2_TCIE_MASK               64U
#define SCI0CR2_TIE_MASK                128U


/*** SCI0SR1 - SCI 0 Status Register 1; 0x000000CC ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmit Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI0SR1STR;
extern volatile SCI0SR1STR _SCI0SR1 @(REG_BASE + 0x000000CCUL);
#define SCI0SR1                         _SCI0SR1.Byte
#define SCI0SR1_PF                      _SCI0SR1.Bits.PF
#define SCI0SR1_FE                      _SCI0SR1.Bits.FE
#define SCI0SR1_NF                      _SCI0SR1.Bits.NF
#define SCI0SR1_OR                      _SCI0SR1.Bits.OR
#define SCI0SR1_IDLE                    _SCI0SR1.Bits.IDLE
#define SCI0SR1_RDRF                    _SCI0SR1.Bits.RDRF
#define SCI0SR1_TC                      _SCI0SR1.Bits.TC
#define SCI0SR1_TDRE                    _SCI0SR1.Bits.TDRE

#define SCI0SR1_PF_MASK                 1U
#define SCI0SR1_FE_MASK                 2U
#define SCI0SR1_NF_MASK                 4U
#define SCI0SR1_OR_MASK                 8U
#define SCI0SR1_IDLE_MASK               16U
#define SCI0SR1_RDRF_MASK               32U
#define SCI0SR1_TC_MASK                 64U
#define SCI0SR1_TDRE_MASK               128U


/*** SCI0SR2 - SCI 0 Status Register 2; 0x000000CD ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte TXDIR       :1;                                       /* Transmitter pin data direction in Single-Wire mode */
    byte BRK13       :1;                                       /* Break Transmit character length */
    byte RXPOL       :1;                                       /* Receive Polarity */
    byte TXPOL       :1;                                       /* Transmit Polarity */
    byte             :1; 
    byte             :1; 
    byte AMAP        :1;                                       /* Alternative Map */
  } Bits;
} SCI0SR2STR;
extern volatile SCI0SR2STR _SCI0SR2 @(REG_BASE + 0x000000CDUL);
#define SCI0SR2                         _SCI0SR2.Byte
#define SCI0SR2_RAF                     _SCI0SR2.Bits.RAF
#define SCI0SR2_TXDIR                   _SCI0SR2.Bits.TXDIR
#define SCI0SR2_BRK13                   _SCI0SR2.Bits.BRK13
#define SCI0SR2_RXPOL                   _SCI0SR2.Bits.RXPOL
#define SCI0SR2_TXPOL                   _SCI0SR2.Bits.TXPOL
#define SCI0SR2_AMAP                    _SCI0SR2.Bits.AMAP

#define SCI0SR2_RAF_MASK                1U
#define SCI0SR2_TXDIR_MASK              2U
#define SCI0SR2_BRK13_MASK              4U
#define SCI0SR2_RXPOL_MASK              8U
#define SCI0SR2_TXPOL_MASK              16U
#define SCI0SR2_AMAP_MASK               128U


/*** SCI0DRH - SCI 0 Data Register High; 0x000000CE ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte T8          :1;                                       /* Transmit Bit 8 */
    byte R8          :1;                                       /* Received Bit 8 */
  } Bits;
} SCI0DRHSTR;
extern volatile SCI0DRHSTR _SCI0DRH @(REG_BASE + 0x000000CEUL);
#define SCI0DRH                         _SCI0DRH.Byte
#define SCI0DRH_T8                      _SCI0DRH.Bits.T8
#define SCI0DRH_R8                      _SCI0DRH.Bits.R8

#define SCI0DRH_T8_MASK                 64U
#define SCI0DRH_R8_MASK                 128U


/*** SCI0DRL - SCI 0 Data Register Low; 0x000000CF ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Received bit 0 or Transmit bit 0 */
    byte R1_T1       :1;                                       /* Received bit 1 or Transmit bit 1 */
    byte R2_T2       :1;                                       /* Received bit 2 or Transmit bit 2 */
    byte R3_T3       :1;                                       /* Received bit 3 or Transmit bit 3 */
    byte R4_T4       :1;                                       /* Received bit 4 or Transmit bit 4 */
    byte R5_T5       :1;                                       /* Received bit 5 or Transmit bit 5 */
    byte R6_T6       :1;                                       /* Received bit 6 or Transmit bit 6 */
    byte R7_T7       :1;                                       /* Received bit 7 or Transmit bit 7 */
  } Bits;
} SCI0DRLSTR;
extern volatile SCI0DRLSTR _SCI0DRL @(REG_BASE + 0x000000CFUL);
#define SCI0DRL                         _SCI0DRL.Byte
#define SCI0DRL_R0_T0                   _SCI0DRL.Bits.R0_T0
#define SCI0DRL_R1_T1                   _SCI0DRL.Bits.R1_T1
#define SCI0DRL_R2_T2                   _SCI0DRL.Bits.R2_T2
#define SCI0DRL_R3_T3                   _SCI0DRL.Bits.R3_T3
#define SCI0DRL_R4_T4                   _SCI0DRL.Bits.R4_T4
#define SCI0DRL_R5_T5                   _SCI0DRL.Bits.R5_T5
#define SCI0DRL_R6_T6                   _SCI0DRL.Bits.R6_T6
#define SCI0DRL_R7_T7                   _SCI0DRL.Bits.R7_T7

#define SCI0DRL_R0_T0_MASK              1U
#define SCI0DRL_R1_T1_MASK              2U
#define SCI0DRL_R2_T2_MASK              4U
#define SCI0DRL_R3_T3_MASK              8U
#define SCI0DRL_R4_T4_MASK              16U
#define SCI0DRL_R5_T5_MASK              32U
#define SCI0DRL_R6_T6_MASK              64U
#define SCI0DRL_R7_T7_MASK              128U


/*** SCI1BD - SCI 1 Baud Rate Register; 0x000000D0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI1ASR1 - SCI 1 Alternative Status Register 1; 0x000000D0 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SCI1ASR1 - SCI 1 Alternative Status Register 1; Several registers at the same address ***/
        union {
          struct {
            byte BKDIF       :1;                                       /* Break Detect Interrupt Flag */
            byte BERRIF      :1;                                       /* Bit Error Interrupt Flag */
            byte BERRV       :1;                                       /* Bit Error Value */
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte RXEDGIF     :1;                                       /* Receive Input Active Edge Interrupt Flag */
          } Bits;
        } SCI1ASR1STR;
        #define SCI1ASR1                _SCI1BD.Overlap_STR.SCI1ASR1STR.Byte
        #define SCI1ASR1_BKDIF          _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1ASR1STR.Bits.BKDIF
        #define SCI1ASR1_BERRIF         _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1ASR1STR.Bits.BERRIF
        #define SCI1ASR1_BERRV          _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1ASR1STR.Bits.BERRV
        #define SCI1ASR1_RXEDGIF        _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1ASR1STR.Bits.RXEDGIF
        
        #define SCI1ASR1_BKDIF_MASK     1U
        #define SCI1ASR1_BERRIF_MASK    2U
        #define SCI1ASR1_BERRV_MASK     4U
        #define SCI1ASR1_RXEDGIF_MASK   128U
        
        /*** SCI1BDH - SCI 1 Baud Rate Register High; Several registers at the same address ***/
        union {
          struct {
            byte SBR8        :1;                                       /* SCI Baud Rate Bit 8 */
            byte SBR9        :1;                                       /* SCI Baud Rate Bit 9 */
            byte SBR10       :1;                                       /* SCI Baud Rate Bit 10 */
            byte SBR11       :1;                                       /* SCI Baud Rate Bit 11 */
            byte SBR12       :1;                                       /* SCI Baud Rate Bit 12 */
            byte TNP0        :1;                                       /* Transmitter Narrow Pulse Bit 0 */
            byte TNP1        :1;                                       /* Transmitter Narrow Pulse Bit 1 */
            byte IREN        :1;                                       /* Infrared Enable Bit */
          } Bits;
          struct {
            byte grpSBR_8 :5;
            byte grpTNP :2;
            byte :1;
          } MergedBits;
        } SCI1BDHSTR;
        #define SCI1BDH                 _SCI1BD.Overlap_STR.SCI1ASR1STR.Byte
        #define SCI1BDH_SBR8            _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR8
        #define SCI1BDH_SBR9            _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR9
        #define SCI1BDH_SBR10           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR10
        #define SCI1BDH_SBR11           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR11
        #define SCI1BDH_SBR12           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR12
        #define SCI1BDH_TNP0            _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.TNP0
        #define SCI1BDH_TNP1            _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.TNP1
        #define SCI1BDH_IREN            _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.IREN
        #define SCI1BDH_SBR_8           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.MergedBits.grpSBR_8
        #define SCI1BDH_TNP             _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.MergedBits.grpTNP
        #define SCI1BDH_SBR             SCI1BDH_SBR_8
        
        #define SCI1BDH_SBR8_MASK       1U
        #define SCI1BDH_SBR9_MASK       2U
        #define SCI1BDH_SBR10_MASK      4U
        #define SCI1BDH_SBR11_MASK      8U
        #define SCI1BDH_SBR12_MASK      16U
        #define SCI1BDH_TNP0_MASK       32U
        #define SCI1BDH_TNP1_MASK       64U
        #define SCI1BDH_IREN_MASK       128U
        #define SCI1BDH_SBR_8_MASK      31U
        #define SCI1BDH_SBR_8_BITNUM    0U
        #define SCI1BDH_TNP_MASK        96U
        #define SCI1BDH_TNP_BITNUM      5U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SCI1ASR1STR;
    

    /*** SCI1ACR1 - SCI 1 Alternative Control Register 1; 0x000000D1 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SCI1ACR1 - SCI 1 Alternative Control Register 1; Several registers at the same address ***/
        union {
          struct {
            byte BKDIE       :1;                                       /* Break Detect Interrupt Enable */
            byte BERRIE      :1;                                       /* Bit Error Interrupt Enable */
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte RXEDGIE     :1;                                       /* Receive Input Active Edge Interrupt Enable */
          } Bits;
        } SCI1ACR1STR;
        #define SCI1ACR1                _SCI1BD.Overlap_STR.SCI1ACR1STR.Byte
        #define SCI1ACR1_BKDIE          _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1ACR1STR.Bits.BKDIE
        #define SCI1ACR1_BERRIE         _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1ACR1STR.Bits.BERRIE
        #define SCI1ACR1_RXEDGIE        _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1ACR1STR.Bits.RXEDGIE
        
        #define SCI1ACR1_BKDIE_MASK     1U
        #define SCI1ACR1_BERRIE_MASK    2U
        #define SCI1ACR1_RXEDGIE_MASK   128U
        
        /*** SCI1BDL - SCI 1 Baud Rate Register Low; Several registers at the same address ***/
        union {
          struct {
            byte SBR0        :1;                                       /* SCI Baud Rate Bit 0 */
            byte SBR1        :1;                                       /* SCI Baud Rate Bit 1 */
            byte SBR2        :1;                                       /* SCI Baud Rate Bit 2 */
            byte SBR3        :1;                                       /* SCI Baud Rate Bit 3 */
            byte SBR4        :1;                                       /* SCI Baud Rate Bit 4 */
            byte SBR5        :1;                                       /* SCI Baud Rate Bit 5 */
            byte SBR6        :1;                                       /* SCI Baud Rate Bit 6 */
            byte SBR7        :1;                                       /* SCI Baud Rate Bit 7 */
          } Bits;
        } SCI1BDLSTR;
        #define SCI1BDL                 _SCI1BD.Overlap_STR.SCI1ACR1STR.Byte
        #define SCI1BDL_SBR0            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR0
        #define SCI1BDL_SBR1            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR1
        #define SCI1BDL_SBR2            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR2
        #define SCI1BDL_SBR3            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR3
        #define SCI1BDL_SBR4            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR4
        #define SCI1BDL_SBR5            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR5
        #define SCI1BDL_SBR6            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR6
        #define SCI1BDL_SBR7            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR7
        
        #define SCI1BDL_SBR0_MASK       1U
        #define SCI1BDL_SBR1_MASK       2U
        #define SCI1BDL_SBR2_MASK       4U
        #define SCI1BDL_SBR3_MASK       8U
        #define SCI1BDL_SBR4_MASK       16U
        #define SCI1BDL_SBR5_MASK       32U
        #define SCI1BDL_SBR6_MASK       64U
        #define SCI1BDL_SBR7_MASK       128U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SCI1ACR1STR;
    
  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* SCI Baud Rate Bit 0 */
    word SBR1        :1;                                       /* SCI Baud Rate Bit 1 */
    word SBR2        :1;                                       /* SCI Baud Rate Bit 2 */
    word SBR3        :1;                                       /* SCI Baud Rate Bit 3 */
    word SBR4        :1;                                       /* SCI Baud Rate Bit 4 */
    word SBR5        :1;                                       /* SCI Baud Rate Bit 5 */
    word SBR6        :1;                                       /* SCI Baud Rate Bit 6 */
    word SBR7        :1;                                       /* SCI Baud Rate Bit 7 */
    word SBR8        :1;                                       /* SCI Baud Rate Bit 8 */
    word SBR9        :1;                                       /* SCI Baud Rate Bit 9 */
    word SBR10       :1;                                       /* SCI Baud Rate Bit 10 */
    word SBR11       :1;                                       /* SCI Baud Rate Bit 11 */
    word SBR12       :1;                                       /* SCI Baud Rate Bit 12 */
    word TNP0        :1;                                       /* Transmitter Narrow Pulse Bit 0 */
    word TNP1        :1;                                       /* Transmitter Narrow Pulse Bit 1 */
    word IREN        :1;                                       /* Infrared Enable Bit */
  } Bits;
  struct {
    word grpSBR  :13;
    word grpTNP  :2;
    word         :1;
  } MergedBits;
} SCI1BDSTR;
extern volatile SCI1BDSTR _SCI1BD @(REG_BASE + 0x000000D0UL);
#define SCI1BD                          _SCI1BD.Word
#define SCI1BD_SBR0                     _SCI1BD.Bits.SBR0
#define SCI1BD_SBR1                     _SCI1BD.Bits.SBR1
#define SCI1BD_SBR2                     _SCI1BD.Bits.SBR2
#define SCI1BD_SBR3                     _SCI1BD.Bits.SBR3
#define SCI1BD_SBR4                     _SCI1BD.Bits.SBR4
#define SCI1BD_SBR5                     _SCI1BD.Bits.SBR5
#define SCI1BD_SBR6                     _SCI1BD.Bits.SBR6
#define SCI1BD_SBR7                     _SCI1BD.Bits.SBR7
#define SCI1BD_SBR8                     _SCI1BD.Bits.SBR8
#define SCI1BD_SBR9                     _SCI1BD.Bits.SBR9
#define SCI1BD_SBR10                    _SCI1BD.Bits.SBR10
#define SCI1BD_SBR11                    _SCI1BD.Bits.SBR11
#define SCI1BD_SBR12                    _SCI1BD.Bits.SBR12
#define SCI1BD_TNP0                     _SCI1BD.Bits.TNP0
#define SCI1BD_TNP1                     _SCI1BD.Bits.TNP1
#define SCI1BD_IREN                     _SCI1BD.Bits.IREN
#define SCI1BD_SBR                      _SCI1BD.MergedBits.grpSBR
#define SCI1BD_TNP                      _SCI1BD.MergedBits.grpTNP

#define SCI1BD_SBR0_MASK                1U
#define SCI1BD_SBR1_MASK                2U
#define SCI1BD_SBR2_MASK                4U
#define SCI1BD_SBR3_MASK                8U
#define SCI1BD_SBR4_MASK                16U
#define SCI1BD_SBR5_MASK                32U
#define SCI1BD_SBR6_MASK                64U
#define SCI1BD_SBR7_MASK                128U
#define SCI1BD_SBR8_MASK                256U
#define SCI1BD_SBR9_MASK                512U
#define SCI1BD_SBR10_MASK               1024U
#define SCI1BD_SBR11_MASK               2048U
#define SCI1BD_SBR12_MASK               4096U
#define SCI1BD_TNP0_MASK                8192U
#define SCI1BD_TNP1_MASK                16384U
#define SCI1BD_IREN_MASK                32768U
#define SCI1BD_SBR_MASK                 8191U
#define SCI1BD_SBR_BITNUM               0U
#define SCI1BD_TNP_MASK                 24576U
#define SCI1BD_TNP_BITNUM               13U


/*** SCI1ACR2 - SCI 1 Alternative Control Register 2; 0x000000D2 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** SCI1ACR2 - SCI 1 Alternative Control Register 2; Several registers at the same address ***/
    union {
      struct {
        byte BKDFE       :1;                                       /* Break Detect Feature Enable */
        byte BERRM0      :1;                                       /* Bit Error Mode 0 */
        byte BERRM1      :1;                                       /* Bit Error Mode 1 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte     :1;
        byte grpBERRM :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI1ACR2STR;
    #define SCI1ACR2                    _SCI1ACR2.Byte
    #define SCI1ACR2_BKDFE              _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.BKDFE
    #define SCI1ACR2_BERRM0             _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.BERRM0
    #define SCI1ACR2_BERRM1             _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.BERRM1
    #define SCI1ACR2_BERRM              _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.MergedBits.grpBERRM
    
    #define SCI1ACR2_BKDFE_MASK         1U
    #define SCI1ACR2_BERRM0_MASK        2U
    #define SCI1ACR2_BERRM1_MASK        4U
    #define SCI1ACR2_BERRM_MASK         6U
    #define SCI1ACR2_BERRM_BITNUM       1U
    
    /*** SCI1CR1 - SCI 1 Control Register 1; Several registers at the same address ***/
    union {
      struct {
        byte PT          :1;                                       /* Parity Type Bit */
        byte PE          :1;                                       /* Parity Enable Bit */
        byte ILT         :1;                                       /* Idle Line Type Bit */
        byte WAKE        :1;                                       /* Wakeup Condition Bit */
        byte M           :1;                                       /* Data Format Mode Bit */
        byte RSRC        :1;                                       /* Receiver Source Bit */
        byte SCISWAI     :1;                                       /* SCI Stop in Wait Mode Bit */
        byte LOOPS       :1;                                       /* Loop Select Bit */
      } Bits;
    } SCI1CR1STR;
    #define SCI1CR1                     _SCI1ACR2.Byte
    #define SCI1CR1_PT                  _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.PT
    #define SCI1CR1_PE                  _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.PE
    #define SCI1CR1_ILT                 _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.ILT
    #define SCI1CR1_WAKE                _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.WAKE
    #define SCI1CR1_M                   _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.M
    #define SCI1CR1_RSRC                _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.RSRC
    #define SCI1CR1_SCISWAI             _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.SCISWAI
    #define SCI1CR1_LOOPS               _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.LOOPS
    
    #define SCI1CR1_PT_MASK             1U
    #define SCI1CR1_PE_MASK             2U
    #define SCI1CR1_ILT_MASK            4U
    #define SCI1CR1_WAKE_MASK           8U
    #define SCI1CR1_M_MASK              16U
    #define SCI1CR1_RSRC_MASK           32U
    #define SCI1CR1_SCISWAI_MASK        64U
    #define SCI1CR1_LOOPS_MASK          128U
    
  } SameAddr_STR; /*Several registers at the same address */

} SCI1ACR2STR;
extern volatile SCI1ACR2STR _SCI1ACR2 @(REG_BASE + 0x000000D2UL);


/*** SCI1CR2 - SCI 1 Control Register 2; 0x000000D3 ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break Bit */
    byte RWU         :1;                                       /* Receiver Wakeup Bit */
    byte RE          :1;                                       /* Receiver Enable Bit */
    byte TE          :1;                                       /* Transmitter Enable Bit */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable Bit */
    byte RIE         :1;                                       /* Receiver Full Interrupt Enable Bit */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable Bit */
    byte TIE_bit     :1;                                       /* Transmitter Interrupt Enable Bit */ /*Warning: bit name is duplicated with register name*/
  } Bits;
} SCI1CR2STR;
extern volatile SCI1CR2STR _SCI1CR2 @(REG_BASE + 0x000000D3UL);
#define SCI1CR2                         _SCI1CR2.Byte
#define SCI1CR2_SBK                     _SCI1CR2.Bits.SBK
#define SCI1CR2_RWU                     _SCI1CR2.Bits.RWU
#define SCI1CR2_RE                      _SCI1CR2.Bits.RE
#define SCI1CR2_TE                      _SCI1CR2.Bits.TE
#define SCI1CR2_ILIE                    _SCI1CR2.Bits.ILIE
#define SCI1CR2_RIE                     _SCI1CR2.Bits.RIE
#define SCI1CR2_TCIE                    _SCI1CR2.Bits.TCIE
#define SCI1CR2_TIE                     _SCI1CR2.Bits.TIE_bit

#define SCI1CR2_SBK_MASK                1U
#define SCI1CR2_RWU_MASK                2U
#define SCI1CR2_RE_MASK                 4U
#define SCI1CR2_TE_MASK                 8U
#define SCI1CR2_ILIE_MASK               16U
#define SCI1CR2_RIE_MASK                32U
#define SCI1CR2_TCIE_MASK               64U
#define SCI1CR2_TIE_MASK                128U


/*** SCI1SR1 - SCI 1 Status Register 1; 0x000000D4 ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmit Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI1SR1STR;
extern volatile SCI1SR1STR _SCI1SR1 @(REG_BASE + 0x000000D4UL);
#define SCI1SR1                         _SCI1SR1.Byte
#define SCI1SR1_PF                      _SCI1SR1.Bits.PF
#define SCI1SR1_FE                      _SCI1SR1.Bits.FE
#define SCI1SR1_NF                      _SCI1SR1.Bits.NF
#define SCI1SR1_OR                      _SCI1SR1.Bits.OR
#define SCI1SR1_IDLE                    _SCI1SR1.Bits.IDLE
#define SCI1SR1_RDRF                    _SCI1SR1.Bits.RDRF
#define SCI1SR1_TC                      _SCI1SR1.Bits.TC
#define SCI1SR1_TDRE                    _SCI1SR1.Bits.TDRE

#define SCI1SR1_PF_MASK                 1U
#define SCI1SR1_FE_MASK                 2U
#define SCI1SR1_NF_MASK                 4U
#define SCI1SR1_OR_MASK                 8U
#define SCI1SR1_IDLE_MASK               16U
#define SCI1SR1_RDRF_MASK               32U
#define SCI1SR1_TC_MASK                 64U
#define SCI1SR1_TDRE_MASK               128U


/*** SCI1SR2 - SCI 1 Status Register 2; 0x000000D5 ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte TXDIR       :1;                                       /* Transmitter pin data direction in Single-Wire mode */
    byte BRK13       :1;                                       /* Break Transmit character length */
    byte RXPOL       :1;                                       /* Receive Polarity */
    byte TXPOL       :1;                                       /* Transmit Polarity */
    byte             :1; 
    byte             :1; 
    byte AMAP        :1;                                       /* Alternative Map */
  } Bits;
} SCI1SR2STR;
extern volatile SCI1SR2STR _SCI1SR2 @(REG_BASE + 0x000000D5UL);
#define SCI1SR2                         _SCI1SR2.Byte
#define SCI1SR2_RAF                     _SCI1SR2.Bits.RAF
#define SCI1SR2_TXDIR                   _SCI1SR2.Bits.TXDIR
#define SCI1SR2_BRK13                   _SCI1SR2.Bits.BRK13
#define SCI1SR2_RXPOL                   _SCI1SR2.Bits.RXPOL
#define SCI1SR2_TXPOL                   _SCI1SR2.Bits.TXPOL
#define SCI1SR2_AMAP                    _SCI1SR2.Bits.AMAP

#define SCI1SR2_RAF_MASK                1U
#define SCI1SR2_TXDIR_MASK              2U
#define SCI1SR2_BRK13_MASK              4U
#define SCI1SR2_RXPOL_MASK              8U
#define SCI1SR2_TXPOL_MASK              16U
#define SCI1SR2_AMAP_MASK               128U


/*** SCI1DRH - SCI 1 Data Register High; 0x000000D6 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte T8          :1;                                       /* Transmit Bit 8 */
    byte R8          :1;                                       /* Received Bit 8 */
  } Bits;
} SCI1DRHSTR;
extern volatile SCI1DRHSTR _SCI1DRH @(REG_BASE + 0x000000D6UL);
#define SCI1DRH                         _SCI1DRH.Byte
#define SCI1DRH_T8                      _SCI1DRH.Bits.T8
#define SCI1DRH_R8                      _SCI1DRH.Bits.R8

#define SCI1DRH_T8_MASK                 64U
#define SCI1DRH_R8_MASK                 128U


/*** SCI1DRL - SCI 1 Data Register Low; 0x000000D7 ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Received bit 0 or Transmit bit 0 */
    byte R1_T1       :1;                                       /* Received bit 1 or Transmit bit 1 */
    byte R2_T2       :1;                                       /* Received bit 2 or Transmit bit 2 */
    byte R3_T3       :1;                                       /* Received bit 3 or Transmit bit 3 */
    byte R4_T4       :1;                                       /* Received bit 4 or Transmit bit 4 */
    byte R5_T5       :1;                                       /* Received bit 5 or Transmit bit 5 */
    byte R6_T6       :1;                                       /* Received bit 6 or Transmit bit 6 */
    byte R7_T7       :1;                                       /* Received bit 7 or Transmit bit 7 */
  } Bits;
} SCI1DRLSTR;
extern volatile SCI1DRLSTR _SCI1DRL @(REG_BASE + 0x000000D7UL);
#define SCI1DRL                         _SCI1DRL.Byte
#define SCI1DRL_R0_T0                   _SCI1DRL.Bits.R0_T0
#define SCI1DRL_R1_T1                   _SCI1DRL.Bits.R1_T1
#define SCI1DRL_R2_T2                   _SCI1DRL.Bits.R2_T2
#define SCI1DRL_R3_T3                   _SCI1DRL.Bits.R3_T3
#define SCI1DRL_R4_T4                   _SCI1DRL.Bits.R4_T4
#define SCI1DRL_R5_T5                   _SCI1DRL.Bits.R5_T5
#define SCI1DRL_R6_T6                   _SCI1DRL.Bits.R6_T6
#define SCI1DRL_R7_T7                   _SCI1DRL.Bits.R7_T7

#define SCI1DRL_R0_T0_MASK              1U
#define SCI1DRL_R1_T1_MASK              2U
#define SCI1DRL_R2_T2_MASK              4U
#define SCI1DRL_R3_T3_MASK              8U
#define SCI1DRL_R4_T4_MASK              16U
#define SCI1DRL_R5_T5_MASK              32U
#define SCI1DRL_R6_T6_MASK              64U
#define SCI1DRL_R7_T7_MASK              128U


/*** SPI0CR1 - SPI 0 Control Register 1; 0x000000D8 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* SPI LSB-First Enable */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* SPI Clock Phase Bit */
    byte CPOL        :1;                                       /* SPI Clock Polarity Bit */
    byte MSTR        :1;                                       /* SPI Master/Slave Mode Select Bit */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable Bit */
    byte SPIE        :1;                                       /* SPI Interrupt Enable Bit */
  } Bits;
} SPI0CR1STR;
extern volatile SPI0CR1STR _SPI0CR1 @(REG_BASE + 0x000000D8UL);
#define SPI0CR1                         _SPI0CR1.Byte
#define SPI0CR1_LSBFE                   _SPI0CR1.Bits.LSBFE
#define SPI0CR1_SSOE                    _SPI0CR1.Bits.SSOE
#define SPI0CR1_CPHA                    _SPI0CR1.Bits.CPHA
#define SPI0CR1_CPOL                    _SPI0CR1.Bits.CPOL
#define SPI0CR1_MSTR                    _SPI0CR1.Bits.MSTR
#define SPI0CR1_SPTIE                   _SPI0CR1.Bits.SPTIE
#define SPI0CR1_SPE                     _SPI0CR1.Bits.SPE
#define SPI0CR1_SPIE                    _SPI0CR1.Bits.SPIE

#define SPI0CR1_LSBFE_MASK              1U
#define SPI0CR1_SSOE_MASK               2U
#define SPI0CR1_CPHA_MASK               4U
#define SPI0CR1_CPOL_MASK               8U
#define SPI0CR1_MSTR_MASK               16U
#define SPI0CR1_SPTIE_MASK              32U
#define SPI0CR1_SPE_MASK                64U
#define SPI0CR1_SPIE_MASK               128U


/*** SPI0CR2 - SPI 0 Control Register 2; 0x000000D9 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* Serial Pin Control Bit 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode Bit */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Output enable in the Bidirectional mode of operation */
    byte MODFEN      :1;                                       /* Mode Fault Enable Bit */
    byte             :1; 
    byte XFRW        :1;                                       /* Transfer Width */
    byte             :1; 
  } Bits;
} SPI0CR2STR;
extern volatile SPI0CR2STR _SPI0CR2 @(REG_BASE + 0x000000D9UL);
#define SPI0CR2                         _SPI0CR2.Byte
#define SPI0CR2_SPC0                    _SPI0CR2.Bits.SPC0
#define SPI0CR2_SPISWAI                 _SPI0CR2.Bits.SPISWAI
#define SPI0CR2_BIDIROE                 _SPI0CR2.Bits.BIDIROE
#define SPI0CR2_MODFEN                  _SPI0CR2.Bits.MODFEN
#define SPI0CR2_XFRW                    _SPI0CR2.Bits.XFRW

#define SPI0CR2_SPC0_MASK               1U
#define SPI0CR2_SPISWAI_MASK            2U
#define SPI0CR2_BIDIROE_MASK            8U
#define SPI0CR2_MODFEN_MASK             16U
#define SPI0CR2_XFRW_MASK               64U


/*** SPI0BR - SPI 0 Baud Rate Register; 0x000000DA ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Selection Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Selection Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Selection Bit 2 */
    byte             :1; 
    byte SPPR0       :1;                                       /* SPI Baud Rate Preselection Bits 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Preselection Bits 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Preselection Bits 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPI0BRSTR;
extern volatile SPI0BRSTR _SPI0BR @(REG_BASE + 0x000000DAUL);
#define SPI0BR                          _SPI0BR.Byte
#define SPI0BR_SPR0                     _SPI0BR.Bits.SPR0
#define SPI0BR_SPR1                     _SPI0BR.Bits.SPR1
#define SPI0BR_SPR2                     _SPI0BR.Bits.SPR2
#define SPI0BR_SPPR0                    _SPI0BR.Bits.SPPR0
#define SPI0BR_SPPR1                    _SPI0BR.Bits.SPPR1
#define SPI0BR_SPPR2                    _SPI0BR.Bits.SPPR2
#define SPI0BR_SPR                      _SPI0BR.MergedBits.grpSPR
#define SPI0BR_SPPR                     _SPI0BR.MergedBits.grpSPPR

#define SPI0BR_SPR0_MASK                1U
#define SPI0BR_SPR1_MASK                2U
#define SPI0BR_SPR2_MASK                4U
#define SPI0BR_SPPR0_MASK               16U
#define SPI0BR_SPPR1_MASK               32U
#define SPI0BR_SPPR2_MASK               64U
#define SPI0BR_SPR_MASK                 7U
#define SPI0BR_SPR_BITNUM               0U
#define SPI0BR_SPPR_MASK                112U
#define SPI0BR_SPPR_BITNUM              4U


/*** SPI0SR - SPI 0 Status Register; 0x000000DB ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Empty Interrupt Flag */
    byte             :1; 
    byte SPIF        :1;                                       /* SPIF Receive Interrupt Flag */
  } Bits;
} SPI0SRSTR;
extern volatile SPI0SRSTR _SPI0SR @(REG_BASE + 0x000000DBUL);
#define SPI0SR                          _SPI0SR.Byte
#define SPI0SR_MODF                     _SPI0SR.Bits.MODF
#define SPI0SR_SPTEF                    _SPI0SR.Bits.SPTEF
#define SPI0SR_SPIF                     _SPI0SR.Bits.SPIF

#define SPI0SR_MODF_MASK                16U
#define SPI0SR_SPTEF_MASK               32U
#define SPI0SR_SPIF_MASK                128U


/*** SPI0DR - SPI 0 Data Register; 0x000000DC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPI0DRH - SPI 0 Data Register High; 0x000000DC ***/
    union {
      byte Byte;
      struct {
        byte R8_T8       :1;                                       /* SPI 0 Data Bit 8 */
        byte R9_T9       :1;                                       /* SPI 0 Data Bit 9 */
        byte R10_T10     :1;                                       /* SPI 0 Data Bit 10 */
        byte R11_T11     :1;                                       /* SPI 0 Data Bit 11 */
        byte R12_T12     :1;                                       /* SPI 0 Data Bit 12 */
        byte R13_T13     :1;                                       /* SPI 0 Data Bit 13 */
        byte R14_T14     :1;                                       /* SPI 0 Data Bit 14 */
        byte R15_T15     :1;                                       /* SPI 0 Data Bit 15 */
      } Bits;
    } SPI0DRHSTR;
    #define SPI0DRH                     _SPI0DR.Overlap_STR.SPI0DRHSTR.Byte
    #define SPI0DRH_R8_T8               _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R8_T8
    #define SPI0DRH_R9_T9               _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R9_T9
    #define SPI0DRH_R10_T10             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R10_T10
    #define SPI0DRH_R11_T11             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R11_T11
    #define SPI0DRH_R12_T12             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R12_T12
    #define SPI0DRH_R13_T13             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R13_T13
    #define SPI0DRH_R14_T14             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R14_T14
    #define SPI0DRH_R15_T15             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R15_T15
    
    #define SPI0DRH_R8_T8_MASK          1U
    #define SPI0DRH_R9_T9_MASK          2U
    #define SPI0DRH_R10_T10_MASK        4U
    #define SPI0DRH_R11_T11_MASK        8U
    #define SPI0DRH_R12_T12_MASK        16U
    #define SPI0DRH_R13_T13_MASK        32U
    #define SPI0DRH_R14_T14_MASK        64U
    #define SPI0DRH_R15_T15_MASK        128U
    

    /*** SPI0DRL - SPI 0 Data Register Low; 0x000000DD ***/
    union {
      byte Byte;
      struct {
        byte R0_T0       :1;                                       /* SPI 0 Data Bit 0 */
        byte R1_T1       :1;                                       /* SPI 0 Data Bit 1 */
        byte R2_T2       :1;                                       /* SPI 0 Data Bit 2 */
        byte R3_T3       :1;                                       /* SPI 0 Data Bit 3 */
        byte R4_T4       :1;                                       /* SPI 0 Data Bit 4 */
        byte R5_T5       :1;                                       /* SPI 0 Data Bit 5 */
        byte R6_T6       :1;                                       /* SPI 0 Data Bit 6 */
        byte R7_T7       :1;                                       /* SPI 0 Data Bit 7 */
      } Bits;
    } SPI0DRLSTR;
    #define SPI0DRL                     _SPI0DR.Overlap_STR.SPI0DRLSTR.Byte
    #define SPI0DRL_R0_T0               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R0_T0
    #define SPI0DRL_R1_T1               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R1_T1
    #define SPI0DRL_R2_T2               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R2_T2
    #define SPI0DRL_R3_T3               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R3_T3
    #define SPI0DRL_R4_T4               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R4_T4
    #define SPI0DRL_R5_T5               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R5_T5
    #define SPI0DRL_R6_T6               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R6_T6
    #define SPI0DRL_R7_T7               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R7_T7
    
    #define SPI0DRL_R0_T0_MASK          1U
    #define SPI0DRL_R1_T1_MASK          2U
    #define SPI0DRL_R2_T2_MASK          4U
    #define SPI0DRL_R3_T3_MASK          8U
    #define SPI0DRL_R4_T4_MASK          16U
    #define SPI0DRL_R5_T5_MASK          32U
    #define SPI0DRL_R6_T6_MASK          64U
    #define SPI0DRL_R7_T7_MASK          128U
    
  } Overlap_STR;

  struct {
    word R0_T0       :1;                                       /* SPI 0 Data Bit 0 */
    word R1_T1       :1;                                       /* SPI 0 Data Bit 1 */
    word R2_T2       :1;                                       /* SPI 0 Data Bit 2 */
    word R3_T3       :1;                                       /* SPI 0 Data Bit 3 */
    word R4_T4       :1;                                       /* SPI 0 Data Bit 4 */
    word R5_T5       :1;                                       /* SPI 0 Data Bit 5 */
    word R6_T6       :1;                                       /* SPI 0 Data Bit 6 */
    word R7_T7       :1;                                       /* SPI 0 Data Bit 7 */
    word R8_T8       :1;                                       /* SPI 0 Data Bit 8 */
    word R9_T9       :1;                                       /* SPI 0 Data Bit 9 */
    word R10_T10     :1;                                       /* SPI 0 Data Bit 10 */
    word R11_T11     :1;                                       /* SPI 0 Data Bit 11 */
    word R12_T12     :1;                                       /* SPI 0 Data Bit 12 */
    word R13_T13     :1;                                       /* SPI 0 Data Bit 13 */
    word R14_T14     :1;                                       /* SPI 0 Data Bit 14 */
    word R15_T15     :1;                                       /* SPI 0 Data Bit 15 */
  } Bits;
} SPI0DRSTR;
extern volatile SPI0DRSTR _SPI0DR @(REG_BASE + 0x000000DCUL);
#define SPI0DR                          _SPI0DR.Word
#define SPI0DR_R0_T0                    _SPI0DR.Bits.R0_T0
#define SPI0DR_R1_T1                    _SPI0DR.Bits.R1_T1
#define SPI0DR_R2_T2                    _SPI0DR.Bits.R2_T2
#define SPI0DR_R3_T3                    _SPI0DR.Bits.R3_T3
#define SPI0DR_R4_T4                    _SPI0DR.Bits.R4_T4
#define SPI0DR_R5_T5                    _SPI0DR.Bits.R5_T5
#define SPI0DR_R6_T6                    _SPI0DR.Bits.R6_T6
#define SPI0DR_R7_T7                    _SPI0DR.Bits.R7_T7
#define SPI0DR_R8_T8                    _SPI0DR.Bits.R8_T8
#define SPI0DR_R9_T9                    _SPI0DR.Bits.R9_T9
#define SPI0DR_R10_T10                  _SPI0DR.Bits.R10_T10
#define SPI0DR_R11_T11                  _SPI0DR.Bits.R11_T11
#define SPI0DR_R12_T12                  _SPI0DR.Bits.R12_T12
#define SPI0DR_R13_T13                  _SPI0DR.Bits.R13_T13
#define SPI0DR_R14_T14                  _SPI0DR.Bits.R14_T14
#define SPI0DR_R15_T15                  _SPI0DR.Bits.R15_T15

#define SPI0DR_R0_T0_MASK               1U
#define SPI0DR_R1_T1_MASK               2U
#define SPI0DR_R2_T2_MASK               4U
#define SPI0DR_R3_T3_MASK               8U
#define SPI0DR_R4_T4_MASK               16U
#define SPI0DR_R5_T5_MASK               32U
#define SPI0DR_R6_T6_MASK               64U
#define SPI0DR_R7_T7_MASK               128U
#define SPI0DR_R8_T8_MASK               256U
#define SPI0DR_R9_T9_MASK               512U
#define SPI0DR_R10_T10_MASK             1024U
#define SPI0DR_R11_T11_MASK             2048U
#define SPI0DR_R12_T12_MASK             4096U
#define SPI0DR_R13_T13_MASK             8192U
#define SPI0DR_R14_T14_MASK             16384U
#define SPI0DR_R15_T15_MASK             32768U


/*** FCLKDIV - Flash Clock Divider Register; 0x00000100 ***/
typedef union {
  byte Byte;
  struct {
    byte FDIV0       :1;                                       /* Clock Divider Bit 0 */
    byte FDIV1       :1;                                       /* Clock Divider Bit 1 */
    byte FDIV2       :1;                                       /* Clock Divider Bit 2 */
    byte FDIV3       :1;                                       /* Clock Divider Bit 3 */
    byte FDIV4       :1;                                       /* Clock Divider Bit 4 */
    byte FDIV5       :1;                                       /* Clock Divider Bit 5 */
    byte FDIV6       :1;                                       /* Clock Divider Bit 6 */
    byte FDIVLD      :1;                                       /* Clock Divider Loaded */
  } Bits;
  struct {
    byte grpFDIV :7;
    byte         :1;
  } MergedBits;
} FCLKDIVSTR;
extern volatile FCLKDIVSTR _FCLKDIV @(REG_BASE + 0x00000100UL);
#define FCLKDIV                         _FCLKDIV.Byte
#define FCLKDIV_FDIV0                   _FCLKDIV.Bits.FDIV0
#define FCLKDIV_FDIV1                   _FCLKDIV.Bits.FDIV1
#define FCLKDIV_FDIV2                   _FCLKDIV.Bits.FDIV2
#define FCLKDIV_FDIV3                   _FCLKDIV.Bits.FDIV3
#define FCLKDIV_FDIV4                   _FCLKDIV.Bits.FDIV4
#define FCLKDIV_FDIV5                   _FCLKDIV.Bits.FDIV5
#define FCLKDIV_FDIV6                   _FCLKDIV.Bits.FDIV6
#define FCLKDIV_FDIVLD                  _FCLKDIV.Bits.FDIVLD
#define FCLKDIV_FDIV                    _FCLKDIV.MergedBits.grpFDIV

#define FCLKDIV_FDIV0_MASK              1U
#define FCLKDIV_FDIV1_MASK              2U
#define FCLKDIV_FDIV2_MASK              4U
#define FCLKDIV_FDIV3_MASK              8U
#define FCLKDIV_FDIV4_MASK              16U
#define FCLKDIV_FDIV5_MASK              32U
#define FCLKDIV_FDIV6_MASK              64U
#define FCLKDIV_FDIVLD_MASK             128U
#define FCLKDIV_FDIV_MASK               127U
#define FCLKDIV_FDIV_BITNUM             0U


/*** FSEC - Flash Security Register; 0x00000101 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte RNV2        :1;                                       /* Reserved Nonvolatile Bit 2 */
    byte RNV3        :1;                                       /* Reserved Nonvolatile Bit 3 */
    byte RNV4        :1;                                       /* Reserved Nonvolatile Bit 4 */
    byte RNV5        :1;                                       /* Reserved Nonvolatile Bit 5 */
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte grpRNV_2 :4;
    byte grpKEYEN :2;
  } MergedBits;
} FSECSTR;
extern volatile FSECSTR _FSEC @(REG_BASE + 0x00000101UL);
#define FSEC                            _FSEC.Byte
#define FSEC_SEC0                       _FSEC.Bits.SEC0
#define FSEC_SEC1                       _FSEC.Bits.SEC1
#define FSEC_RNV2                       _FSEC.Bits.RNV2
#define FSEC_RNV3                       _FSEC.Bits.RNV3
#define FSEC_RNV4                       _FSEC.Bits.RNV4
#define FSEC_RNV5                       _FSEC.Bits.RNV5
#define FSEC_KEYEN0                     _FSEC.Bits.KEYEN0
#define FSEC_KEYEN1                     _FSEC.Bits.KEYEN1
#define FSEC_SEC                        _FSEC.MergedBits.grpSEC
#define FSEC_RNV_2                      _FSEC.MergedBits.grpRNV_2
#define FSEC_KEYEN                      _FSEC.MergedBits.grpKEYEN
#define FSEC_RNV                        FSEC_RNV_2

#define FSEC_SEC0_MASK                  1U
#define FSEC_SEC1_MASK                  2U
#define FSEC_RNV2_MASK                  4U
#define FSEC_RNV3_MASK                  8U
#define FSEC_RNV4_MASK                  16U
#define FSEC_RNV5_MASK                  32U
#define FSEC_KEYEN0_MASK                64U
#define FSEC_KEYEN1_MASK                128U
#define FSEC_SEC_MASK                   3U
#define FSEC_SEC_BITNUM                 0U
#define FSEC_RNV_2_MASK                 60U
#define FSEC_RNV_2_BITNUM               2U
#define FSEC_KEYEN_MASK                 192U
#define FSEC_KEYEN_BITNUM               6U


/*** FCCOBIX - Flash CCOB Index Register; 0x00000102 ***/
typedef union {
  byte Byte;
  struct {
    byte CCOBIX0     :1;                                       /* Common Command Register Index Bit 0 */
    byte CCOBIX1     :1;                                       /* Common Command Register Index Bit 1 */
    byte CCOBIX2     :1;                                       /* Common Command Register Index Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCCOBIX :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FCCOBIXSTR;
extern volatile FCCOBIXSTR _FCCOBIX @(REG_BASE + 0x00000102UL);
#define FCCOBIX                         _FCCOBIX.Byte
#define FCCOBIX_CCOBIX0                 _FCCOBIX.Bits.CCOBIX0
#define FCCOBIX_CCOBIX1                 _FCCOBIX.Bits.CCOBIX1
#define FCCOBIX_CCOBIX2                 _FCCOBIX.Bits.CCOBIX2
#define FCCOBIX_CCOBIX                  _FCCOBIX.MergedBits.grpCCOBIX

#define FCCOBIX_CCOBIX0_MASK            1U
#define FCCOBIX_CCOBIX1_MASK            2U
#define FCCOBIX_CCOBIX2_MASK            4U
#define FCCOBIX_CCOBIX_MASK             7U
#define FCCOBIX_CCOBIX_BITNUM           0U


/*** FECCRIX - Flash ECCR Index Register; 0x00000103 ***/
typedef union {
  byte Byte;
  struct {
    byte ECCRIX0     :1;                                       /* ECC Error Register Index Bit 0 */
    byte ECCRIX1     :1;                                       /* ECC Error Register Index Bit 1 */
    byte ECCRIX2     :1;                                       /* ECC Error Register Index Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpECCRIX :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FECCRIXSTR;
extern volatile FECCRIXSTR _FECCRIX @(REG_BASE + 0x00000103UL);
#define FECCRIX                         _FECCRIX.Byte
#define FECCRIX_ECCRIX0                 _FECCRIX.Bits.ECCRIX0
#define FECCRIX_ECCRIX1                 _FECCRIX.Bits.ECCRIX1
#define FECCRIX_ECCRIX2                 _FECCRIX.Bits.ECCRIX2
#define FECCRIX_ECCRIX                  _FECCRIX.MergedBits.grpECCRIX

#define FECCRIX_ECCRIX0_MASK            1U
#define FECCRIX_ECCRIX1_MASK            2U
#define FECCRIX_ECCRIX2_MASK            4U
#define FECCRIX_ECCRIX_MASK             7U
#define FECCRIX_ECCRIX_BITNUM           0U


/*** FCNFG - Flash Configuration Register; 0x00000104 ***/
typedef union {
  byte Byte;
  struct {
    byte FSFD        :1;                                       /* Force Single Bit Fault Detect */
    byte FDFD        :1;                                       /* Force Double Bit Fault Detect */
    byte             :1; 
    byte             :1; 
    byte IGNSF       :1;                                       /* Ignore Single Bit Fault */
    byte             :1; 
    byte             :1; 
    byte CCIE        :1;                                       /* Command Complete Interrupt Enable */
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @(REG_BASE + 0x00000104UL);
#define FCNFG                           _FCNFG.Byte
#define FCNFG_FSFD                      _FCNFG.Bits.FSFD
#define FCNFG_FDFD                      _FCNFG.Bits.FDFD
#define FCNFG_IGNSF                     _FCNFG.Bits.IGNSF
#define FCNFG_CCIE                      _FCNFG.Bits.CCIE

#define FCNFG_FSFD_MASK                 1U
#define FCNFG_FDFD_MASK                 2U
#define FCNFG_IGNSF_MASK                16U
#define FCNFG_CCIE_MASK                 128U


/*** FERCNFG - Flash Error Configuration Register; 0x00000105 ***/
typedef union {
  byte Byte;
  struct {
    byte SFDIE       :1;                                       /* Single Bit Fault Detect Interrupt Enable */
    byte DFDIE       :1;                                       /* Double Bit Fault Detect Interrupt Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FERCNFGSTR;
extern volatile FERCNFGSTR _FERCNFG @(REG_BASE + 0x00000105UL);
#define FERCNFG                         _FERCNFG.Byte
#define FERCNFG_SFDIE                   _FERCNFG.Bits.SFDIE
#define FERCNFG_DFDIE                   _FERCNFG.Bits.DFDIE

#define FERCNFG_SFDIE_MASK              1U
#define FERCNFG_DFDIE_MASK              2U


/*** FSTAT - Flash Status Register; 0x00000106 ***/
typedef union {
  byte Byte;
  struct {
    byte MGSTAT0     :1;                                       /* Memory Controller Command Completion Status Flag 0 */
    byte MGSTAT1     :1;                                       /* Memory Controller Command Completion Status Flag 1 */
    byte             :1; 
    byte MGBUSY      :1;                                       /* Memory Controller Busy Flag */
    byte FPVIOL      :1;                                       /* Flash Protection Violation Flag */
    byte ACCERR      :1;                                       /* Flash Access Error Flag */
    byte             :1; 
    byte CCIF        :1;                                       /* Command Complete Interrupt Flag */
  } Bits;
  struct {
    byte grpMGSTAT :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @(REG_BASE + 0x00000106UL);
#define FSTAT                           _FSTAT.Byte
#define FSTAT_MGSTAT0                   _FSTAT.Bits.MGSTAT0
#define FSTAT_MGSTAT1                   _FSTAT.Bits.MGSTAT1
#define FSTAT_MGBUSY                    _FSTAT.Bits.MGBUSY
#define FSTAT_FPVIOL                    _FSTAT.Bits.FPVIOL
#define FSTAT_ACCERR                    _FSTAT.Bits.ACCERR
#define FSTAT_CCIF                      _FSTAT.Bits.CCIF
#define FSTAT_MGSTAT                    _FSTAT.MergedBits.grpMGSTAT

#define FSTAT_MGSTAT0_MASK              1U
#define FSTAT_MGSTAT1_MASK              2U
#define FSTAT_MGBUSY_MASK               8U
#define FSTAT_FPVIOL_MASK               16U
#define FSTAT_ACCERR_MASK               32U
#define FSTAT_CCIF_MASK                 128U
#define FSTAT_MGSTAT_MASK               3U
#define FSTAT_MGSTAT_BITNUM             0U


/*** FERSTAT - Flash Error Status Register; 0x00000107 ***/
typedef union {
  byte Byte;
  struct {
    byte SFDIF       :1;                                       /* Single Bit Fault Detect Interrupt Flag */
    byte DFDIF       :1;                                       /* Double Bit Fault Detect Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FERSTATSTR;
extern volatile FERSTATSTR _FERSTAT @(REG_BASE + 0x00000107UL);
#define FERSTAT                         _FERSTAT.Byte
#define FERSTAT_SFDIF                   _FERSTAT.Bits.SFDIF
#define FERSTAT_DFDIF                   _FERSTAT.Bits.DFDIF

#define FERSTAT_SFDIF_MASK              1U
#define FERSTAT_DFDIF_MASK              2U


/*** FPROT - P-Flash Protection Register; 0x00000108 ***/
typedef union {
  byte Byte;
  struct {
    byte FPLS0       :1;                                       /* Flash Protection Lower Address Size Bit 0 */
    byte FPLS1       :1;                                       /* Flash Protection Lower Address Size Bit 1 */
    byte FPLDIS      :1;                                       /* Flash Protection Lower Address Range Disable */
    byte FPHS0       :1;                                       /* Flash Protection Higher Address Size Bit 0 */
    byte FPHS1       :1;                                       /* Flash Protection Higher Address Size Bit 1 */
    byte FPHDIS      :1;                                       /* Flash Protection Higher Address Range Disable */
    byte RNV6        :1;                                       /* Reserved Nonvolatile Bit */
    byte FPOPEN      :1;                                       /* Flash Protection Operation Enable */
  } Bits;
  struct {
    byte grpFPLS :2;
    byte         :1;
    byte grpFPHS :2;
    byte         :1;
    byte grpRNV_6 :1;
    byte         :1;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @(REG_BASE + 0x00000108UL);
#define FPROT                           _FPROT.Byte
#define FPROT_FPLS0                     _FPROT.Bits.FPLS0
#define FPROT_FPLS1                     _FPROT.Bits.FPLS1
#define FPROT_FPLDIS                    _FPROT.Bits.FPLDIS
#define FPROT_FPHS0                     _FPROT.Bits.FPHS0
#define FPROT_FPHS1                     _FPROT.Bits.FPHS1
#define FPROT_FPHDIS                    _FPROT.Bits.FPHDIS
#define FPROT_RNV6                      _FPROT.Bits.RNV6
#define FPROT_FPOPEN                    _FPROT.Bits.FPOPEN
#define FPROT_FPLS                      _FPROT.MergedBits.grpFPLS
#define FPROT_FPHS                      _FPROT.MergedBits.grpFPHS

#define FPROT_FPLS0_MASK                1U
#define FPROT_FPLS1_MASK                2U
#define FPROT_FPLDIS_MASK               4U
#define FPROT_FPHS0_MASK                8U
#define FPROT_FPHS1_MASK                16U
#define FPROT_FPHDIS_MASK               32U
#define FPROT_RNV6_MASK                 64U
#define FPROT_FPOPEN_MASK               128U
#define FPROT_FPLS_MASK                 3U
#define FPROT_FPLS_BITNUM               0U
#define FPROT_FPHS_MASK                 24U
#define FPROT_FPHS_BITNUM               3U


/*** DFPROT - D-Flash Protection Register; 0x00000109 ***/
typedef union {
  byte Byte;
  struct {
    byte DPS0        :1;                                       /* D-Flash Protection Size Bit 0 */
    byte DPS1        :1;                                       /* D-Flash Protection Size Bit 1 */
    byte DPS2        :1;                                       /* D-Flash Protection Size Bit 2 */
    byte DPS3        :1;                                       /* D-Flash Protection Size Bit 3 */
    byte DPS4        :1;                                       /* D-Flash Protection Size Bit 4 */
    byte             :1; 
    byte             :1; 
    byte DPOPEN      :1;                                       /* D-Flash Protection Control */
  } Bits;
  struct {
    byte grpDPS  :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DFPROTSTR;
extern volatile DFPROTSTR _DFPROT @(REG_BASE + 0x00000109UL);
#define DFPROT                          _DFPROT.Byte
#define DFPROT_DPS0                     _DFPROT.Bits.DPS0
#define DFPROT_DPS1                     _DFPROT.Bits.DPS1
#define DFPROT_DPS2                     _DFPROT.Bits.DPS2
#define DFPROT_DPS3                     _DFPROT.Bits.DPS3
#define DFPROT_DPS4                     _DFPROT.Bits.DPS4
#define DFPROT_DPOPEN                   _DFPROT.Bits.DPOPEN
#define DFPROT_DPS                      _DFPROT.MergedBits.grpDPS

#define DFPROT_DPS0_MASK                1U
#define DFPROT_DPS1_MASK                2U
#define DFPROT_DPS2_MASK                4U
#define DFPROT_DPS3_MASK                8U
#define DFPROT_DPS4_MASK                16U
#define DFPROT_DPOPEN_MASK              128U
#define DFPROT_DPS_MASK                 31U
#define DFPROT_DPS_BITNUM               0U


/*** FCCOB - Flash Common Command Object Register; 0x0000010A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FCCOBHI - Flash Common Command Object Register High; 0x0000010A ***/
    union {
      byte Byte;
      struct {
        byte CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
        byte CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
        byte CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
        byte CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
        byte CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
        byte CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
        byte CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
        byte CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
      } Bits;
    } FCCOBHISTR;
    #define FCCOBHI                     _FCCOB.Overlap_STR.FCCOBHISTR.Byte
    #define FCCOBHI_CCOB8               _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB8
    #define FCCOBHI_CCOB9               _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB9
    #define FCCOBHI_CCOB10              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB10
    #define FCCOBHI_CCOB11              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB11
    #define FCCOBHI_CCOB12              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB12
    #define FCCOBHI_CCOB13              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB13
    #define FCCOBHI_CCOB14              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB14
    #define FCCOBHI_CCOB15              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB15
    
    #define FCCOBHI_CCOB8_MASK          1U
    #define FCCOBHI_CCOB9_MASK          2U
    #define FCCOBHI_CCOB10_MASK         4U
    #define FCCOBHI_CCOB11_MASK         8U
    #define FCCOBHI_CCOB12_MASK         16U
    #define FCCOBHI_CCOB13_MASK         32U
    #define FCCOBHI_CCOB14_MASK         64U
    #define FCCOBHI_CCOB15_MASK         128U
    

    /*** FCCOBLO - Flash Common Command Object Register Low; 0x0000010B ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
        byte CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
        byte CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
        byte CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
        byte CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
        byte CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
        byte CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
        byte CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
      } Bits;
    } FCCOBLOSTR;
    #define FCCOBLO                     _FCCOB.Overlap_STR.FCCOBLOSTR.Byte
    #define FCCOBLO_CCOB0               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB0
    #define FCCOBLO_CCOB1               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB1
    #define FCCOBLO_CCOB2               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB2
    #define FCCOBLO_CCOB3               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB3
    #define FCCOBLO_CCOB4               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB4
    #define FCCOBLO_CCOB5               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB5
    #define FCCOBLO_CCOB6               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB6
    #define FCCOBLO_CCOB7               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB7
    
    #define FCCOBLO_CCOB0_MASK          1U
    #define FCCOBLO_CCOB1_MASK          2U
    #define FCCOBLO_CCOB2_MASK          4U
    #define FCCOBLO_CCOB3_MASK          8U
    #define FCCOBLO_CCOB4_MASK          16U
    #define FCCOBLO_CCOB5_MASK          32U
    #define FCCOBLO_CCOB6_MASK          64U
    #define FCCOBLO_CCOB7_MASK          128U
    
  } Overlap_STR;

  struct {
    word CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
    word CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
    word CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
    word CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
    word CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
    word CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
    word CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
    word CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
    word CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
    word CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
    word CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
    word CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
    word CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
    word CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
    word CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
    word CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
  } Bits;
} FCCOBSTR;
extern volatile FCCOBSTR _FCCOB @(REG_BASE + 0x0000010AUL);
#define FCCOB                           _FCCOB.Word
#define FCCOB_CCOB0                     _FCCOB.Bits.CCOB0
#define FCCOB_CCOB1                     _FCCOB.Bits.CCOB1
#define FCCOB_CCOB2                     _FCCOB.Bits.CCOB2
#define FCCOB_CCOB3                     _FCCOB.Bits.CCOB3
#define FCCOB_CCOB4                     _FCCOB.Bits.CCOB4
#define FCCOB_CCOB5                     _FCCOB.Bits.CCOB5
#define FCCOB_CCOB6                     _FCCOB.Bits.CCOB6
#define FCCOB_CCOB7                     _FCCOB.Bits.CCOB7
#define FCCOB_CCOB8                     _FCCOB.Bits.CCOB8
#define FCCOB_CCOB9                     _FCCOB.Bits.CCOB9
#define FCCOB_CCOB10                    _FCCOB.Bits.CCOB10
#define FCCOB_CCOB11                    _FCCOB.Bits.CCOB11
#define FCCOB_CCOB12                    _FCCOB.Bits.CCOB12
#define FCCOB_CCOB13                    _FCCOB.Bits.CCOB13
#define FCCOB_CCOB14                    _FCCOB.Bits.CCOB14
#define FCCOB_CCOB15                    _FCCOB.Bits.CCOB15

#define FCCOB_CCOB0_MASK                1U
#define FCCOB_CCOB1_MASK                2U
#define FCCOB_CCOB2_MASK                4U
#define FCCOB_CCOB3_MASK                8U
#define FCCOB_CCOB4_MASK                16U
#define FCCOB_CCOB5_MASK                32U
#define FCCOB_CCOB6_MASK                64U
#define FCCOB_CCOB7_MASK                128U
#define FCCOB_CCOB8_MASK                256U
#define FCCOB_CCOB9_MASK                512U
#define FCCOB_CCOB10_MASK               1024U
#define FCCOB_CCOB11_MASK               2048U
#define FCCOB_CCOB12_MASK               4096U
#define FCCOB_CCOB13_MASK               8192U
#define FCCOB_CCOB14_MASK               16384U
#define FCCOB_CCOB15_MASK               32768U


/*** FECCR - Flash ECC Error Results Register; 0x0000010E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FECCRHI - Flash ECC Error Results Register High; 0x0000010E ***/
    union {
      byte Byte;
      struct {
        byte ECCR8       :1;                                       /* Flash ECC Error Result Bit 8 */
        byte ECCR9       :1;                                       /* Flash ECC Error Result Bit 9 */
        byte ECCR10      :1;                                       /* Flash ECC Error Result Bit 10 */
        byte ECCR11      :1;                                       /* Flash ECC Error Result Bit 11 */
        byte ECCR12      :1;                                       /* Flash ECC Error Result Bit 12 */
        byte ECCR13      :1;                                       /* Flash ECC Error Result Bit 13 */
        byte ECCR14      :1;                                       /* Flash ECC Error Result Bit 14 */
        byte ECCR15      :1;                                       /* Flash ECC Error Result Bit 15 */
      } Bits;
    } FECCRHISTR;
    #define FECCRHI                     _FECCR.Overlap_STR.FECCRHISTR.Byte
    #define FECCRHI_ECCR8               _FECCR.Overlap_STR.FECCRHISTR.Bits.ECCR8
    #define FECCRHI_ECCR9               _FECCR.Overlap_STR.FECCRHISTR.Bits.ECCR9
    #define FECCRHI_ECCR10              _FECCR.Overlap_STR.FECCRHISTR.Bits.ECCR10
    #define FECCRHI_ECCR11              _FECCR.Overlap_STR.FECCRHISTR.Bits.ECCR11
    #define FECCRHI_ECCR12              _FECCR.Overlap_STR.FECCRHISTR.Bits.ECCR12
    #define FECCRHI_ECCR13              _FECCR.Overlap_STR.FECCRHISTR.Bits.ECCR13
    #define FECCRHI_ECCR14              _FECCR.Overlap_STR.FECCRHISTR.Bits.ECCR14
    #define FECCRHI_ECCR15              _FECCR.Overlap_STR.FECCRHISTR.Bits.ECCR15
    
    #define FECCRHI_ECCR8_MASK          1U
    #define FECCRHI_ECCR9_MASK          2U
    #define FECCRHI_ECCR10_MASK         4U
    #define FECCRHI_ECCR11_MASK         8U
    #define FECCRHI_ECCR12_MASK         16U
    #define FECCRHI_ECCR13_MASK         32U
    #define FECCRHI_ECCR14_MASK         64U
    #define FECCRHI_ECCR15_MASK         128U
    

    /*** FECCRLO - Flash ECC Error Results Register Low; 0x0000010F ***/
    union {
      byte Byte;
      struct {
        byte ECCR0       :1;                                       /* Flash ECC Error Result Bit 0 */
        byte ECCR1       :1;                                       /* Flash ECC Error Result Bit 1 */
        byte ECCR2       :1;                                       /* Flash ECC Error Result Bit 2 */
        byte ECCR3       :1;                                       /* Flash ECC Error Result Bit 3 */
        byte ECCR4       :1;                                       /* Flash ECC Error Result Bit 4 */
        byte ECCR5       :1;                                       /* Flash ECC Error Result Bit 5 */
        byte ECCR6       :1;                                       /* Flash ECC Error Result Bit 6 */
        byte ECCR7       :1;                                       /* Flash ECC Error Result Bit 7 */
      } Bits;
    } FECCRLOSTR;
    #define FECCRLO                     _FECCR.Overlap_STR.FECCRLOSTR.Byte
    #define FECCRLO_ECCR0               _FECCR.Overlap_STR.FECCRLOSTR.Bits.ECCR0
    #define FECCRLO_ECCR1               _FECCR.Overlap_STR.FECCRLOSTR.Bits.ECCR1
    #define FECCRLO_ECCR2               _FECCR.Overlap_STR.FECCRLOSTR.Bits.ECCR2
    #define FECCRLO_ECCR3               _FECCR.Overlap_STR.FECCRLOSTR.Bits.ECCR3
    #define FECCRLO_ECCR4               _FECCR.Overlap_STR.FECCRLOSTR.Bits.ECCR4
    #define FECCRLO_ECCR5               _FECCR.Overlap_STR.FECCRLOSTR.Bits.ECCR5
    #define FECCRLO_ECCR6               _FECCR.Overlap_STR.FECCRLOSTR.Bits.ECCR6
    #define FECCRLO_ECCR7               _FECCR.Overlap_STR.FECCRLOSTR.Bits.ECCR7
    
    #define FECCRLO_ECCR0_MASK          1U
    #define FECCRLO_ECCR1_MASK          2U
    #define FECCRLO_ECCR2_MASK          4U
    #define FECCRLO_ECCR3_MASK          8U
    #define FECCRLO_ECCR4_MASK          16U
    #define FECCRLO_ECCR5_MASK          32U
    #define FECCRLO_ECCR6_MASK          64U
    #define FECCRLO_ECCR7_MASK          128U
    
  } Overlap_STR;

  struct {
    word ECCR0       :1;                                       /* Flash ECC Error Result Bit 0 */
    word ECCR1       :1;                                       /* Flash ECC Error Result Bit 1 */
    word ECCR2       :1;                                       /* Flash ECC Error Result Bit 2 */
    word ECCR3       :1;                                       /* Flash ECC Error Result Bit 3 */
    word ECCR4       :1;                                       /* Flash ECC Error Result Bit 4 */
    word ECCR5       :1;                                       /* Flash ECC Error Result Bit 5 */
    word ECCR6       :1;                                       /* Flash ECC Error Result Bit 6 */
    word ECCR7       :1;                                       /* Flash ECC Error Result Bit 7 */
    word ECCR8       :1;                                       /* Flash ECC Error Result Bit 8 */
    word ECCR9       :1;                                       /* Flash ECC Error Result Bit 9 */
    word ECCR10      :1;                                       /* Flash ECC Error Result Bit 10 */
    word ECCR11      :1;                                       /* Flash ECC Error Result Bit 11 */
    word ECCR12      :1;                                       /* Flash ECC Error Result Bit 12 */
    word ECCR13      :1;                                       /* Flash ECC Error Result Bit 13 */
    word ECCR14      :1;                                       /* Flash ECC Error Result Bit 14 */
    word ECCR15      :1;                                       /* Flash ECC Error Result Bit 15 */
  } Bits;
} FECCRSTR;
extern volatile FECCRSTR _FECCR @(REG_BASE + 0x0000010EUL);
#define FECCR                           _FECCR.Word
#define FECCR_ECCR0                     _FECCR.Bits.ECCR0
#define FECCR_ECCR1                     _FECCR.Bits.ECCR1
#define FECCR_ECCR2                     _FECCR.Bits.ECCR2
#define FECCR_ECCR3                     _FECCR.Bits.ECCR3
#define FECCR_ECCR4                     _FECCR.Bits.ECCR4
#define FECCR_ECCR5                     _FECCR.Bits.ECCR5
#define FECCR_ECCR6                     _FECCR.Bits.ECCR6
#define FECCR_ECCR7                     _FECCR.Bits.ECCR7
#define FECCR_ECCR8                     _FECCR.Bits.ECCR8
#define FECCR_ECCR9                     _FECCR.Bits.ECCR9
#define FECCR_ECCR10                    _FECCR.Bits.ECCR10
#define FECCR_ECCR11                    _FECCR.Bits.ECCR11
#define FECCR_ECCR12                    _FECCR.Bits.ECCR12
#define FECCR_ECCR13                    _FECCR.Bits.ECCR13
#define FECCR_ECCR14                    _FECCR.Bits.ECCR14
#define FECCR_ECCR15                    _FECCR.Bits.ECCR15

#define FECCR_ECCR0_MASK                1U
#define FECCR_ECCR1_MASK                2U
#define FECCR_ECCR2_MASK                4U
#define FECCR_ECCR3_MASK                8U
#define FECCR_ECCR4_MASK                16U
#define FECCR_ECCR5_MASK                32U
#define FECCR_ECCR6_MASK                64U
#define FECCR_ECCR7_MASK                128U
#define FECCR_ECCR8_MASK                256U
#define FECCR_ECCR9_MASK                512U
#define FECCR_ECCR10_MASK               1024U
#define FECCR_ECCR11_MASK               2048U
#define FECCR_ECCR12_MASK               4096U
#define FECCR_ECCR13_MASK               8192U
#define FECCR_ECCR14_MASK               16384U
#define FECCR_ECCR15_MASK               32768U


/*** FOPT - Flash Option Register; 0x00000110 ***/
typedef union {
  byte Byte;
  struct {
    byte NV0         :1;                                       /* Nonvolatile Bit 0 */
    byte NV1         :1;                                       /* Nonvolatile Bit 1 */
    byte NV2         :1;                                       /* Nonvolatile Bit 2 */
    byte NV3         :1;                                       /* Nonvolatile Bit 3 */
    byte NV4         :1;                                       /* Nonvolatile Bit 4 */
    byte NV5         :1;                                       /* Nonvolatile Bit 5 */
    byte NV6         :1;                                       /* Nonvolatile Bit 6 */
    byte NV7         :1;                                       /* Nonvolatile Bit 7 */
  } Bits;
} FOPTSTR;
extern volatile FOPTSTR _FOPT @(REG_BASE + 0x00000110UL);
#define FOPT                            _FOPT.Byte
#define FOPT_NV0                        _FOPT.Bits.NV0
#define FOPT_NV1                        _FOPT.Bits.NV1
#define FOPT_NV2                        _FOPT.Bits.NV2
#define FOPT_NV3                        _FOPT.Bits.NV3
#define FOPT_NV4                        _FOPT.Bits.NV4
#define FOPT_NV5                        _FOPT.Bits.NV5
#define FOPT_NV6                        _FOPT.Bits.NV6
#define FOPT_NV7                        _FOPT.Bits.NV7

#define FOPT_NV0_MASK                   1U
#define FOPT_NV1_MASK                   2U
#define FOPT_NV2_MASK                   4U
#define FOPT_NV3_MASK                   8U
#define FOPT_NV4_MASK                   16U
#define FOPT_NV5_MASK                   32U
#define FOPT_NV6_MASK                   64U
#define FOPT_NV7_MASK                   128U


/*** IVBR - Interrupt Vector Base Register; 0x00000121 ***/
typedef union {
  byte Byte;
  struct {
    byte IVB_ADDR    :8;                                       /* Interrupt Vector Base Address Bits */
  } Bits;
} IVBRSTR;
extern volatile IVBRSTR _IVBR @(REG_BASE + 0x00000121UL);
#define IVBR                            _IVBR.Byte
#define IVBR_IVB_ADDR                   _IVBR.Bits.IVB_ADDR

#define IVBR_IVB_ADDR_MASK              255U
#define IVBR_IVB_ADDR_BITNUM            0U


/*** INT_XGPRIO - XGATE Interrupt Priority Configuration Register; 0x00000126 ***/
typedef union {
  byte Byte;
  struct {
    byte XILVL       :3;                                       /* XGATE Interrupt Priority Level */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} INT_XGPRIOSTR;
extern volatile INT_XGPRIOSTR _INT_XGPRIO @(REG_BASE + 0x00000126UL);
#define INT_XGPRIO                      _INT_XGPRIO.Byte
#define INT_XGPRIO_XILVL                _INT_XGPRIO.Bits.XILVL

#define INT_XGPRIO_XILVL_MASK           7U
#define INT_XGPRIO_XILVL_BITNUM         0U


/*** INT_CFADDR - Interrupt Request Configuration Address Register; 0x00000127 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte INT_CFADDR_grp :4;                                    /* Interrupt Request Configuration Data Register Select Bits */ /*Warning: group name is duplicated with register name*/
  } Bits;
} INT_CFADDRSTR;
extern volatile INT_CFADDRSTR _INT_CFADDR @(REG_BASE + 0x00000127UL);
#define INT_CFADDR                      _INT_CFADDR.Byte
#define INT_CFADDR_INT_CFADDR           _INT_CFADDR.Bits.INT_CFADDR_grp

#define INT_CFADDR_INT_CFADDR_MASK      240U
#define INT_CFADDR_INT_CFADDR_BITNUM    4U


/*** INT_CFDATA0 - Interrupt Request Configuration Data Register 0; 0x00000128 ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA0STR;
extern volatile INT_CFDATA0STR _INT_CFDATA0 @(REG_BASE + 0x00000128UL);
#define INT_CFDATA0                     _INT_CFDATA0.Byte
#define INT_CFDATA0_PRIOLVL             _INT_CFDATA0.Bits.PRIOLVL
#define INT_CFDATA0_RQST                _INT_CFDATA0.Bits.RQST
/* INT_CFDATA_ARR: Access 8 INT_CFDATAx registers in an array */
#define INT_CFDATA_ARR                  ((volatile byte *) &INT_CFDATA0)

#define INT_CFDATA0_PRIOLVL_MASK        7U
#define INT_CFDATA0_PRIOLVL_BITNUM      0U
#define INT_CFDATA0_RQST_MASK           128U


/*** INT_CFDATA1 - Interrupt Request Configuration Data Register 1; 0x00000129 ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA1STR;
extern volatile INT_CFDATA1STR _INT_CFDATA1 @(REG_BASE + 0x00000129UL);
#define INT_CFDATA1                     _INT_CFDATA1.Byte
#define INT_CFDATA1_PRIOLVL             _INT_CFDATA1.Bits.PRIOLVL
#define INT_CFDATA1_RQST                _INT_CFDATA1.Bits.RQST

#define INT_CFDATA1_PRIOLVL_MASK        7U
#define INT_CFDATA1_PRIOLVL_BITNUM      0U
#define INT_CFDATA1_RQST_MASK           128U


/*** INT_CFDATA2 - Interrupt Request Configuration Data Register 2; 0x0000012A ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA2STR;
extern volatile INT_CFDATA2STR _INT_CFDATA2 @(REG_BASE + 0x0000012AUL);
#define INT_CFDATA2                     _INT_CFDATA2.Byte
#define INT_CFDATA2_PRIOLVL             _INT_CFDATA2.Bits.PRIOLVL
#define INT_CFDATA2_RQST                _INT_CFDATA2.Bits.RQST

#define INT_CFDATA2_PRIOLVL_MASK        7U
#define INT_CFDATA2_PRIOLVL_BITNUM      0U
#define INT_CFDATA2_RQST_MASK           128U


/*** INT_CFDATA3 - Interrupt Request Configuration Data Register 3; 0x0000012B ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA3STR;
extern volatile INT_CFDATA3STR _INT_CFDATA3 @(REG_BASE + 0x0000012BUL);
#define INT_CFDATA3                     _INT_CFDATA3.Byte
#define INT_CFDATA3_PRIOLVL             _INT_CFDATA3.Bits.PRIOLVL
#define INT_CFDATA3_RQST                _INT_CFDATA3.Bits.RQST

#define INT_CFDATA3_PRIOLVL_MASK        7U
#define INT_CFDATA3_PRIOLVL_BITNUM      0U
#define INT_CFDATA3_RQST_MASK           128U


/*** INT_CFDATA4 - Interrupt Request Configuration Data Register 4; 0x0000012C ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA4STR;
extern volatile INT_CFDATA4STR _INT_CFDATA4 @(REG_BASE + 0x0000012CUL);
#define INT_CFDATA4                     _INT_CFDATA4.Byte
#define INT_CFDATA4_PRIOLVL             _INT_CFDATA4.Bits.PRIOLVL
#define INT_CFDATA4_RQST                _INT_CFDATA4.Bits.RQST

#define INT_CFDATA4_PRIOLVL_MASK        7U
#define INT_CFDATA4_PRIOLVL_BITNUM      0U
#define INT_CFDATA4_RQST_MASK           128U


/*** INT_CFDATA5 - Interrupt Request Configuration Data Register 5; 0x0000012D ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA5STR;
extern volatile INT_CFDATA5STR _INT_CFDATA5 @(REG_BASE + 0x0000012DUL);
#define INT_CFDATA5                     _INT_CFDATA5.Byte
#define INT_CFDATA5_PRIOLVL             _INT_CFDATA5.Bits.PRIOLVL
#define INT_CFDATA5_RQST                _INT_CFDATA5.Bits.RQST

#define INT_CFDATA5_PRIOLVL_MASK        7U
#define INT_CFDATA5_PRIOLVL_BITNUM      0U
#define INT_CFDATA5_RQST_MASK           128U


/*** INT_CFDATA6 - Interrupt Request Configuration Data Register 6; 0x0000012E ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA6STR;
extern volatile INT_CFDATA6STR _INT_CFDATA6 @(REG_BASE + 0x0000012EUL);
#define INT_CFDATA6                     _INT_CFDATA6.Byte
#define INT_CFDATA6_PRIOLVL             _INT_CFDATA6.Bits.PRIOLVL
#define INT_CFDATA6_RQST                _INT_CFDATA6.Bits.RQST

#define INT_CFDATA6_PRIOLVL_MASK        7U
#define INT_CFDATA6_PRIOLVL_BITNUM      0U
#define INT_CFDATA6_RQST_MASK           128U


/*** INT_CFDATA7 - Interrupt Request Configuration Data Register 7; 0x0000012F ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RQST        :1;                                       /* XGATE Request Enable */
  } Bits;
} INT_CFDATA7STR;
extern volatile INT_CFDATA7STR _INT_CFDATA7 @(REG_BASE + 0x0000012FUL);
#define INT_CFDATA7                     _INT_CFDATA7.Byte
#define INT_CFDATA7_PRIOLVL             _INT_CFDATA7.Bits.PRIOLVL
#define INT_CFDATA7_RQST                _INT_CFDATA7.Bits.RQST

#define INT_CFDATA7_PRIOLVL_MASK        7U
#define INT_CFDATA7_PRIOLVL_BITNUM      0U
#define INT_CFDATA7_RQST_MASK           128U


/*** CAN0CTL0 - MSCAN0 Control 0 Register; 0x00000140 ***/
typedef union {
  byte Byte;
  struct {
    byte INITRQ      :1;                                       /* Initialization Mode Request */
    byte SLPRQ       :1;                                       /* Sleep Mode Request */
    byte WUPE        :1;                                       /* Wake-Up Enable */
    byte TIME        :1;                                       /* Timer Enable */
    byte SYNCH       :1;                                       /* Synchronized Status */
    byte CSWAI       :1;                                       /* CAN Stops in Wait Mode */
    byte RXACT       :1;                                       /* Receiver Active Status */
    byte RXFRM       :1;                                       /* Received Frame Flag */
  } Bits;
} CAN0CTL0STR;
extern volatile CAN0CTL0STR _CAN0CTL0 @(REG_BASE + 0x00000140UL);
#define CAN0CTL0                        _CAN0CTL0.Byte
#define CAN0CTL0_INITRQ                 _CAN0CTL0.Bits.INITRQ
#define CAN0CTL0_SLPRQ                  _CAN0CTL0.Bits.SLPRQ
#define CAN0CTL0_WUPE                   _CAN0CTL0.Bits.WUPE
#define CAN0CTL0_TIME                   _CAN0CTL0.Bits.TIME
#define CAN0CTL0_SYNCH                  _CAN0CTL0.Bits.SYNCH
#define CAN0CTL0_CSWAI                  _CAN0CTL0.Bits.CSWAI
#define CAN0CTL0_RXACT                  _CAN0CTL0.Bits.RXACT
#define CAN0CTL0_RXFRM                  _CAN0CTL0.Bits.RXFRM
/* CAN0CTL_ARR: Access 2 CAN0CTLx registers in an array */
#define CAN0CTL_ARR                     ((volatile byte *) &CAN0CTL0)

#define CAN0CTL0_INITRQ_MASK            1U
#define CAN0CTL0_SLPRQ_MASK             2U
#define CAN0CTL0_WUPE_MASK              4U
#define CAN0CTL0_TIME_MASK              8U
#define CAN0CTL0_SYNCH_MASK             16U
#define CAN0CTL0_CSWAI_MASK             32U
#define CAN0CTL0_RXACT_MASK             64U
#define CAN0CTL0_RXFRM_MASK             128U


/*** CAN0CTL1 - MSCAN0 Control 1 Register; 0x00000141 ***/
typedef union {
  byte Byte;
  struct {
    byte INITAK      :1;                                       /* Initialization Mode Acknowledge */
    byte SLPAK       :1;                                       /* Sleep Mode Acknowledge */
    byte WUPM        :1;                                       /* Wake-Up Mode */
    byte BORM        :1;                                       /* Bus-Off Recovery Mode */
    byte LISTEN      :1;                                       /* Listen Only Mode */
    byte LOOPB       :1;                                       /* Loop Back Self Test Mode */
    byte CLKSRC      :1;                                       /* MSCAN Clock Source */
    byte CANE        :1;                                       /* MSCAN Enable */
  } Bits;
} CAN0CTL1STR;
extern volatile CAN0CTL1STR _CAN0CTL1 @(REG_BASE + 0x00000141UL);
#define CAN0CTL1                        _CAN0CTL1.Byte
#define CAN0CTL1_INITAK                 _CAN0CTL1.Bits.INITAK
#define CAN0CTL1_SLPAK                  _CAN0CTL1.Bits.SLPAK
#define CAN0CTL1_WUPM                   _CAN0CTL1.Bits.WUPM
#define CAN0CTL1_BORM                   _CAN0CTL1.Bits.BORM
#define CAN0CTL1_LISTEN                 _CAN0CTL1.Bits.LISTEN
#define CAN0CTL1_LOOPB                  _CAN0CTL1.Bits.LOOPB
#define CAN0CTL1_CLKSRC                 _CAN0CTL1.Bits.CLKSRC
#define CAN0CTL1_CANE                   _CAN0CTL1.Bits.CANE

#define CAN0CTL1_INITAK_MASK            1U
#define CAN0CTL1_SLPAK_MASK             2U
#define CAN0CTL1_WUPM_MASK              4U
#define CAN0CTL1_BORM_MASK              8U
#define CAN0CTL1_LISTEN_MASK            16U
#define CAN0CTL1_LOOPB_MASK             32U
#define CAN0CTL1_CLKSRC_MASK            64U
#define CAN0CTL1_CANE_MASK              128U


/*** CAN0BTR0 - MSCAN0 Bus Timing Register 0; 0x00000142 ***/
typedef union {
  byte Byte;
  struct {
    byte BRP0        :1;                                       /* Baud Rate Prescaler 0 */
    byte BRP1        :1;                                       /* Baud Rate Prescaler 1 */
    byte BRP2        :1;                                       /* Baud Rate Prescaler 2 */
    byte BRP3        :1;                                       /* Baud Rate Prescaler 3 */
    byte BRP4        :1;                                       /* Baud Rate Prescaler 4 */
    byte BRP5        :1;                                       /* Baud Rate Prescaler 5 */
    byte SJW0        :1;                                       /* Synchronization Jump Width 0 */
    byte SJW1        :1;                                       /* Synchronization Jump Width 1 */
  } Bits;
  struct {
    byte grpBRP  :6;
    byte grpSJW  :2;
  } MergedBits;
} CAN0BTR0STR;
extern volatile CAN0BTR0STR _CAN0BTR0 @(REG_BASE + 0x00000142UL);
#define CAN0BTR0                        _CAN0BTR0.Byte
#define CAN0BTR0_BRP0                   _CAN0BTR0.Bits.BRP0
#define CAN0BTR0_BRP1                   _CAN0BTR0.Bits.BRP1
#define CAN0BTR0_BRP2                   _CAN0BTR0.Bits.BRP2
#define CAN0BTR0_BRP3                   _CAN0BTR0.Bits.BRP3
#define CAN0BTR0_BRP4                   _CAN0BTR0.Bits.BRP4
#define CAN0BTR0_BRP5                   _CAN0BTR0.Bits.BRP5
#define CAN0BTR0_SJW0                   _CAN0BTR0.Bits.SJW0
#define CAN0BTR0_SJW1                   _CAN0BTR0.Bits.SJW1
/* CAN0BTR_ARR: Access 2 CAN0BTRx registers in an array */
#define CAN0BTR_ARR                     ((volatile byte *) &CAN0BTR0)
#define CAN0BTR0_BRP                    _CAN0BTR0.MergedBits.grpBRP
#define CAN0BTR0_SJW                    _CAN0BTR0.MergedBits.grpSJW

#define CAN0BTR0_BRP0_MASK              1U
#define CAN0BTR0_BRP1_MASK              2U
#define CAN0BTR0_BRP2_MASK              4U
#define CAN0BTR0_BRP3_MASK              8U
#define CAN0BTR0_BRP4_MASK              16U
#define CAN0BTR0_BRP5_MASK              32U
#define CAN0BTR0_SJW0_MASK              64U
#define CAN0BTR0_SJW1_MASK              128U
#define CAN0BTR0_BRP_MASK               63U
#define CAN0BTR0_BRP_BITNUM             0U
#define CAN0BTR0_SJW_MASK               192U
#define CAN0BTR0_SJW_BITNUM             6U


/*** CAN0BTR1 - MSCAN0 Bus Timing Register 1; 0x00000143 ***/
typedef union {
  byte Byte;
  struct {
    byte TSEG10      :1;                                       /* Time Segment 10 */
    byte TSEG11      :1;                                       /* Time Segment 11 */
    byte TSEG12      :1;                                       /* Time Segment 12 */
    byte TSEG13      :1;                                       /* Time Segment 13 */
    byte TSEG20      :1;                                       /* Time Segment 20 */
    byte TSEG21      :1;                                       /* Time Segment 21 */
    byte TSEG22      :1;                                       /* Time Segment 22 */
    byte SAMP        :1;                                       /* Sampling */
  } Bits;
  struct {
    byte grpTSEG_10 :4;
    byte grpTSEG_20 :3;
    byte         :1;
  } MergedBits;
} CAN0BTR1STR;
extern volatile CAN0BTR1STR _CAN0BTR1 @(REG_BASE + 0x00000143UL);
#define CAN0BTR1                        _CAN0BTR1.Byte
#define CAN0BTR1_TSEG10                 _CAN0BTR1.Bits.TSEG10
#define CAN0BTR1_TSEG11                 _CAN0BTR1.Bits.TSEG11
#define CAN0BTR1_TSEG12                 _CAN0BTR1.Bits.TSEG12
#define CAN0BTR1_TSEG13                 _CAN0BTR1.Bits.TSEG13
#define CAN0BTR1_TSEG20                 _CAN0BTR1.Bits.TSEG20
#define CAN0BTR1_TSEG21                 _CAN0BTR1.Bits.TSEG21
#define CAN0BTR1_TSEG22                 _CAN0BTR1.Bits.TSEG22
#define CAN0BTR1_SAMP                   _CAN0BTR1.Bits.SAMP
#define CAN0BTR1_TSEG_10                _CAN0BTR1.MergedBits.grpTSEG_10
#define CAN0BTR1_TSEG_20                _CAN0BTR1.MergedBits.grpTSEG_20
#define CAN0BTR1_TSEG                   CAN0BTR1_TSEG_10

#define CAN0BTR1_TSEG10_MASK            1U
#define CAN0BTR1_TSEG11_MASK            2U
#define CAN0BTR1_TSEG12_MASK            4U
#define CAN0BTR1_TSEG13_MASK            8U
#define CAN0BTR1_TSEG20_MASK            16U
#define CAN0BTR1_TSEG21_MASK            32U
#define CAN0BTR1_TSEG22_MASK            64U
#define CAN0BTR1_SAMP_MASK              128U
#define CAN0BTR1_TSEG_10_MASK           15U
#define CAN0BTR1_TSEG_10_BITNUM         0U
#define CAN0BTR1_TSEG_20_MASK           112U
#define CAN0BTR1_TSEG_20_BITNUM         4U


/*** CAN0RFLG - MSCAN0 Receiver Flag Register; 0x00000144 ***/
typedef union {
  byte Byte;
  struct {
    byte RXF         :1;                                       /* Receive Buffer Full */
    byte OVRIF       :1;                                       /* Overrun Interrupt Flag */
    byte TSTAT0      :1;                                       /* Transmitter Status Bit 0 */
    byte TSTAT1      :1;                                       /* Transmitter Status Bit 1 */
    byte RSTAT0      :1;                                       /* Receiver Status Bit 0 */
    byte RSTAT1      :1;                                       /* Receiver Status Bit 1 */
    byte CSCIF       :1;                                       /* CAN Status Change Interrupt Flag */
    byte WUPIF       :1;                                       /* Wake-up Interrupt Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTSTAT :2;
    byte grpRSTAT :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CAN0RFLGSTR;
extern volatile CAN0RFLGSTR _CAN0RFLG @(REG_BASE + 0x00000144UL);
#define CAN0RFLG                        _CAN0RFLG.Byte
#define CAN0RFLG_RXF                    _CAN0RFLG.Bits.RXF
#define CAN0RFLG_OVRIF                  _CAN0RFLG.Bits.OVRIF
#define CAN0RFLG_TSTAT0                 _CAN0RFLG.Bits.TSTAT0
#define CAN0RFLG_TSTAT1                 _CAN0RFLG.Bits.TSTAT1
#define CAN0RFLG_RSTAT0                 _CAN0RFLG.Bits.RSTAT0
#define CAN0RFLG_RSTAT1                 _CAN0RFLG.Bits.RSTAT1
#define CAN0RFLG_CSCIF                  _CAN0RFLG.Bits.CSCIF
#define CAN0RFLG_WUPIF                  _CAN0RFLG.Bits.WUPIF
#define CAN0RFLG_TSTAT                  _CAN0RFLG.MergedBits.grpTSTAT
#define CAN0RFLG_RSTAT                  _CAN0RFLG.MergedBits.grpRSTAT

#define CAN0RFLG_RXF_MASK               1U
#define CAN0RFLG_OVRIF_MASK             2U
#define CAN0RFLG_TSTAT0_MASK            4U
#define CAN0RFLG_TSTAT1_MASK            8U
#define CAN0RFLG_RSTAT0_MASK            16U
#define CAN0RFLG_RSTAT1_MASK            32U
#define CAN0RFLG_CSCIF_MASK             64U
#define CAN0RFLG_WUPIF_MASK             128U
#define CAN0RFLG_TSTAT_MASK             12U
#define CAN0RFLG_TSTAT_BITNUM           2U
#define CAN0RFLG_RSTAT_MASK             48U
#define CAN0RFLG_RSTAT_BITNUM           4U


/*** CAN0RIER - MSCAN0 Receiver Interrupt Enable Register; 0x00000145 ***/
typedef union {
  byte Byte;
  struct {
    byte RXFIE       :1;                                       /* Receiver Full Interrupt Enable */
    byte OVRIE       :1;                                       /* Overrun Interrupt Enable */
    byte TSTATE0     :1;                                       /* Transmitter Status Change Enable 0 */
    byte TSTATE1     :1;                                       /* Transmitter Status Change Enable 1 */
    byte RSTATE0     :1;                                       /* Receiver Status Change Enable 0 */
    byte RSTATE1     :1;                                       /* Receiver Status Change Enable 1 */
    byte CSCIE       :1;                                       /* CAN Status Change Interrupt Enable */
    byte WUPIE       :1;                                       /* Wake-up Interrupt Enable */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTSTATE :2;
    byte grpRSTATE :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CAN0RIERSTR;
extern volatile CAN0RIERSTR _CAN0RIER @(REG_BASE + 0x00000145UL);
#define CAN0RIER                        _CAN0RIER.Byte
#define CAN0RIER_RXFIE                  _CAN0RIER.Bits.RXFIE
#define CAN0RIER_OVRIE                  _CAN0RIER.Bits.OVRIE
#define CAN0RIER_TSTATE0                _CAN0RIER.Bits.TSTATE0
#define CAN0RIER_TSTATE1                _CAN0RIER.Bits.TSTATE1
#define CAN0RIER_RSTATE0                _CAN0RIER.Bits.RSTATE0
#define CAN0RIER_RSTATE1                _CAN0RIER.Bits.RSTATE1
#define CAN0RIER_CSCIE                  _CAN0RIER.Bits.CSCIE
#define CAN0RIER_WUPIE                  _CAN0RIER.Bits.WUPIE
#define CAN0RIER_TSTATE                 _CAN0RIER.MergedBits.grpTSTATE
#define CAN0RIER_RSTATE                 _CAN0RIER.MergedBits.grpRSTATE

#define CAN0RIER_RXFIE_MASK             1U
#define CAN0RIER_OVRIE_MASK             2U
#define CAN0RIER_TSTATE0_MASK           4U
#define CAN0RIER_TSTATE1_MASK           8U
#define CAN0RIER_RSTATE0_MASK           16U
#define CAN0RIER_RSTATE1_MASK           32U
#define CAN0RIER_CSCIE_MASK             64U
#define CAN0RIER_WUPIE_MASK             128U
#define CAN0RIER_TSTATE_MASK            12U
#define CAN0RIER_TSTATE_BITNUM          2U
#define CAN0RIER_RSTATE_MASK            48U
#define CAN0RIER_RSTATE_BITNUM          4U


/*** CAN0TFLG - MSCAN0 Transmitter Flag Register; 0x00000146 ***/
typedef union {
  byte Byte;
  struct {
    byte TXE0        :1;                                       /* Transmitter Buffer Empty 0 */
    byte TXE1        :1;                                       /* Transmitter Buffer Empty 1 */
    byte TXE2        :1;                                       /* Transmitter Buffer Empty 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTXE  :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CAN0TFLGSTR;
extern volatile CAN0TFLGSTR _CAN0TFLG @(REG_BASE + 0x00000146UL);
#define CAN0TFLG                        _CAN0TFLG.Byte
#define CAN0TFLG_TXE0                   _CAN0TFLG.Bits.TXE0
#define CAN0TFLG_TXE1                   _CAN0TFLG.Bits.TXE1
#define CAN0TFLG_TXE2                   _CAN0TFLG.Bits.TXE2
#define CAN0TFLG_TXE                    _CAN0TFLG.MergedBits.grpTXE

#define CAN0TFLG_TXE0_MASK              1U
#define CAN0TFLG_TXE1_MASK              2U
#define CAN0TFLG_TXE2_MASK              4U
#define CAN0TFLG_TXE_MASK               7U
#define CAN0TFLG_TXE_BITNUM             0U


/*** CAN0TIER - MSCAN0 Transmitter Interrupt Enable Register; 0x00000147 ***/
typedef union {
  byte Byte;
  struct {
    byte TXEIE0      :1;                                       /* Transmitter Empty Interrupt Enable 0 */
    byte TXEIE1      :1;                                       /* Transmitter Empty Interrupt Enable 1 */
    byte TXEIE2      :1;                                       /* Transmitter Empty Interrupt Enable 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTXEIE :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CAN0TIERSTR;
extern volatile CAN0TIERSTR _CAN0TIER @(REG_BASE + 0x00000147UL);
#define CAN0TIER                        _CAN0TIER.Byte
#define CAN0TIER_TXEIE0                 _CAN0TIER.Bits.TXEIE0
#define CAN0TIER_TXEIE1                 _CAN0TIER.Bits.TXEIE1
#define CAN0TIER_TXEIE2                 _CAN0TIER.Bits.TXEIE2
#define CAN0TIER_TXEIE                  _CAN0TIER.MergedBits.grpTXEIE

#define CAN0TIER_TXEIE0_MASK            1U
#define CAN0TIER_TXEIE1_MASK            2U
#define CAN0TIER_TXEIE2_MASK            4U
#define CAN0TIER_TXEIE_MASK             7U
#define CAN0TIER_TXEIE_BITNUM           0U


/*** CAN0TARQ - MSCAN0 Transmitter Message Abort Request; 0x00000148 ***/
typedef union {
  byte Byte;
  struct {
    byte ABTRQ0      :1;                                       /* Abort Request 0 */
    byte ABTRQ1      :1;                                       /* Abort Request 1 */
    byte ABTRQ2      :1;                                       /* Abort Request 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpABTRQ :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CAN0TARQSTR;
extern volatile CAN0TARQSTR _CAN0TARQ @(REG_BASE + 0x00000148UL);
#define CAN0TARQ                        _CAN0TARQ.Byte
#define CAN0TARQ_ABTRQ0                 _CAN0TARQ.Bits.ABTRQ0
#define CAN0TARQ_ABTRQ1                 _CAN0TARQ.Bits.ABTRQ1
#define CAN0TARQ_ABTRQ2                 _CAN0TARQ.Bits.ABTRQ2
#define CAN0TARQ_ABTRQ                  _CAN0TARQ.MergedBits.grpABTRQ

#define CAN0TARQ_ABTRQ0_MASK            1U
#define CAN0TARQ_ABTRQ1_MASK            2U
#define CAN0TARQ_ABTRQ2_MASK            4U
#define CAN0TARQ_ABTRQ_MASK             7U
#define CAN0TARQ_ABTRQ_BITNUM           0U


/*** CAN0TAAK - MSCAN0 Transmitter Message Abort Acknowledge; 0x00000149 ***/
typedef union {
  byte Byte;
  struct {
    byte ABTAK0      :1;                                       /* Abort Acknowledge 0 */
    byte ABTAK1      :1;                                       /* Abort Acknowledge 1 */
    byte ABTAK2      :1;                                       /* Abort Acknowledge 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpABTAK :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CAN0TAAKSTR;
extern volatile CAN0TAAKSTR _CAN0TAAK @(REG_BASE + 0x00000149UL);
#define CAN0TAAK                        _CAN0TAAK.Byte
#define CAN0TAAK_ABTAK0                 _CAN0TAAK.Bits.ABTAK0
#define CAN0TAAK_ABTAK1                 _CAN0TAAK.Bits.ABTAK1
#define CAN0TAAK_ABTAK2                 _CAN0TAAK.Bits.ABTAK2
#define CAN0TAAK_ABTAK                  _CAN0TAAK.MergedBits.grpABTAK

#define CAN0TAAK_ABTAK0_MASK            1U
#define CAN0TAAK_ABTAK1_MASK            2U
#define CAN0TAAK_ABTAK2_MASK            4U
#define CAN0TAAK_ABTAK_MASK             7U
#define CAN0TAAK_ABTAK_BITNUM           0U


/*** CAN0TBSEL - MSCAN0 Transmit Buffer Selection; 0x0000014A ***/
typedef union {
  byte Byte;
  struct {
    byte TX0         :1;                                       /* Transmit Buffer Select 0 */
    byte TX1         :1;                                       /* Transmit Buffer Select 1 */
    byte TX2         :1;                                       /* Transmit Buffer Select 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTX   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CAN0TBSELSTR;
extern volatile CAN0TBSELSTR _CAN0TBSEL @(REG_BASE + 0x0000014AUL);
#define CAN0TBSEL                       _CAN0TBSEL.Byte
#define CAN0TBSEL_TX0                   _CAN0TBSEL.Bits.TX0
#define CAN0TBSEL_TX1                   _CAN0TBSEL.Bits.TX1
#define CAN0TBSEL_TX2                   _CAN0TBSEL.Bits.TX2
#define CAN0TBSEL_TX                    _CAN0TBSEL.MergedBits.grpTX

#define CAN0TBSEL_TX0_MASK              1U
#define CAN0TBSEL_TX1_MASK              2U
#define CAN0TBSEL_TX2_MASK              4U
#define CAN0TBSEL_TX_MASK               7U
#define CAN0TBSEL_TX_BITNUM             0U


/*** CAN0IDAC - MSCAN0 Identifier Acceptance Control Register; 0x0000014B ***/
typedef union {
  byte Byte;
  struct {
    byte IDHIT0      :1;                                       /* Identifier Acceptance Hit Indicator 0 */
    byte IDHIT1      :1;                                       /* Identifier Acceptance Hit Indicator 1 */
    byte IDHIT2      :1;                                       /* Identifier Acceptance Hit Indicator 2 */
    byte             :1; 
    byte IDAM0       :1;                                       /* Identifier Acceptance Mode 0 */
    byte IDAM1       :1;                                       /* Identifier Acceptance Mode 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpIDHIT :3;
    byte         :1;
    byte grpIDAM :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CAN0IDACSTR;
extern volatile CAN0IDACSTR _CAN0IDAC @(REG_BASE + 0x0000014BUL);
#define CAN0IDAC                        _CAN0IDAC.Byte
#define CAN0IDAC_IDHIT0                 _CAN0IDAC.Bits.IDHIT0
#define CAN0IDAC_IDHIT1                 _CAN0IDAC.Bits.IDHIT1
#define CAN0IDAC_IDHIT2                 _CAN0IDAC.Bits.IDHIT2
#define CAN0IDAC_IDAM0                  _CAN0IDAC.Bits.IDAM0
#define CAN0IDAC_IDAM1                  _CAN0IDAC.Bits.IDAM1
#define CAN0IDAC_IDHIT                  _CAN0IDAC.MergedBits.grpIDHIT
#define CAN0IDAC_IDAM                   _CAN0IDAC.MergedBits.grpIDAM

#define CAN0IDAC_IDHIT0_MASK            1U
#define CAN0IDAC_IDHIT1_MASK            2U
#define CAN0IDAC_IDHIT2_MASK            4U
#define CAN0IDAC_IDAM0_MASK             16U
#define CAN0IDAC_IDAM1_MASK             32U
#define CAN0IDAC_IDHIT_MASK             7U
#define CAN0IDAC_IDHIT_BITNUM           0U
#define CAN0IDAC_IDAM_MASK              48U
#define CAN0IDAC_IDAM_BITNUM            4U


/*** CAN0MISC - MSCAN0 Miscellaneous Register; 0x0000014D ***/
typedef union {
  byte Byte;
  struct {
    byte BOHOLD      :1;                                       /* Bus-off State Hold Until User Request */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CAN0MISCSTR;
extern volatile CAN0MISCSTR _CAN0MISC @(REG_BASE + 0x0000014DUL);
#define CAN0MISC                        _CAN0MISC.Byte
#define CAN0MISC_BOHOLD                 _CAN0MISC.Bits.BOHOLD

#define CAN0MISC_BOHOLD_MASK            1U


/*** CAN0RXERR - MSCAN0 Receive Error Counter Register; 0x0000014E ***/
typedef union {
  byte Byte;
  struct {
    byte RXERR0      :1;                                       /* Bit 0 */
    byte RXERR1      :1;                                       /* Bit 1 */
    byte RXERR2      :1;                                       /* Bit 2 */
    byte RXERR3      :1;                                       /* Bit 3 */
    byte RXERR4      :1;                                       /* Bit 4 */
    byte RXERR5      :1;                                       /* Bit 5 */
    byte RXERR6      :1;                                       /* Bit 6 */
    byte RXERR7      :1;                                       /* Bit 7 */
  } Bits;
} CAN0RXERRSTR;
extern volatile CAN0RXERRSTR _CAN0RXERR @(REG_BASE + 0x0000014EUL);
#define CAN0RXERR                       _CAN0RXERR.Byte
#define CAN0RXERR_RXERR0                _CAN0RXERR.Bits.RXERR0
#define CAN0RXERR_RXERR1                _CAN0RXERR.Bits.RXERR1
#define CAN0RXERR_RXERR2                _CAN0RXERR.Bits.RXERR2
#define CAN0RXERR_RXERR3                _CAN0RXERR.Bits.RXERR3
#define CAN0RXERR_RXERR4                _CAN0RXERR.Bits.RXERR4
#define CAN0RXERR_RXERR5                _CAN0RXERR.Bits.RXERR5
#define CAN0RXERR_RXERR6                _CAN0RXERR.Bits.RXERR6
#define CAN0RXERR_RXERR7                _CAN0RXERR.Bits.RXERR7

#define CAN0RXERR_RXERR0_MASK           1U
#define CAN0RXERR_RXERR1_MASK           2U
#define CAN0RXERR_RXERR2_MASK           4U
#define CAN0RXERR_RXERR3_MASK           8U
#define CAN0RXERR_RXERR4_MASK           16U
#define CAN0RXERR_RXERR5_MASK           32U
#define CAN0RXERR_RXERR6_MASK           64U
#define CAN0RXERR_RXERR7_MASK           128U


/*** CAN0TXERR - MSCAN0 Transmit Error Counter Register; 0x0000014F ***/
typedef union {
  byte Byte;
  struct {
    byte TXERR0      :1;                                       /* Bit 0 */
    byte TXERR1      :1;                                       /* Bit 1 */
    byte TXERR2      :1;                                       /* Bit 2 */
    byte TXERR3      :1;                                       /* Bit 3 */
    byte TXERR4      :1;                                       /* Bit 4 */
    byte TXERR5      :1;                                       /* Bit 5 */
    byte TXERR6      :1;                                       /* Bit 6 */
    byte TXERR7      :1;                                       /* Bit 7 */
  } Bits;
} CAN0TXERRSTR;
extern volatile CAN0TXERRSTR _CAN0TXERR @(REG_BASE + 0x0000014FUL);
#define CAN0TXERR                       _CAN0TXERR.Byte
#define CAN0TXERR_TXERR0                _CAN0TXERR.Bits.TXERR0
#define CAN0TXERR_TXERR1                _CAN0TXERR.Bits.TXERR1
#define CAN0TXERR_TXERR2                _CAN0TXERR.Bits.TXERR2
#define CAN0TXERR_TXERR3                _CAN0TXERR.Bits.TXERR3
#define CAN0TXERR_TXERR4                _CAN0TXERR.Bits.TXERR4
#define CAN0TXERR_TXERR5                _CAN0TXERR.Bits.TXERR5
#define CAN0TXERR_TXERR6                _CAN0TXERR.Bits.TXERR6
#define CAN0TXERR_TXERR7                _CAN0TXERR.Bits.TXERR7

#define CAN0TXERR_TXERR0_MASK           1U
#define CAN0TXERR_TXERR1_MASK           2U
#define CAN0TXERR_TXERR2_MASK           4U
#define CAN0TXERR_TXERR3_MASK           8U
#define CAN0TXERR_TXERR4_MASK           16U
#define CAN0TXERR_TXERR5_MASK           32U
#define CAN0TXERR_TXERR6_MASK           64U
#define CAN0TXERR_TXERR7_MASK           128U


/*** CAN0IDAR0 - MSCAN0 Identifier Acceptance Register 0; 0x00000150 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CAN0IDAR0STR;
extern volatile CAN0IDAR0STR _CAN0IDAR0 @(REG_BASE + 0x00000150UL);
#define CAN0IDAR0                       _CAN0IDAR0.Byte
#define CAN0IDAR0_AC0                   _CAN0IDAR0.Bits.AC0
#define CAN0IDAR0_AC1                   _CAN0IDAR0.Bits.AC1
#define CAN0IDAR0_AC2                   _CAN0IDAR0.Bits.AC2
#define CAN0IDAR0_AC3                   _CAN0IDAR0.Bits.AC3
#define CAN0IDAR0_AC4                   _CAN0IDAR0.Bits.AC4
#define CAN0IDAR0_AC5                   _CAN0IDAR0.Bits.AC5
#define CAN0IDAR0_AC6                   _CAN0IDAR0.Bits.AC6
#define CAN0IDAR0_AC7                   _CAN0IDAR0.Bits.AC7
/* CAN0IDAR_ARR: Access 4 CAN0IDARx registers in an array */
#define CAN0IDAR_ARR                    ((volatile byte *) &CAN0IDAR0)

#define CAN0IDAR0_AC0_MASK              1U
#define CAN0IDAR0_AC1_MASK              2U
#define CAN0IDAR0_AC2_MASK              4U
#define CAN0IDAR0_AC3_MASK              8U
#define CAN0IDAR0_AC4_MASK              16U
#define CAN0IDAR0_AC5_MASK              32U
#define CAN0IDAR0_AC6_MASK              64U
#define CAN0IDAR0_AC7_MASK              128U


/*** CAN0IDAR1 - MSCAN0 Identifier Acceptance Register 1; 0x00000151 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CAN0IDAR1STR;
extern volatile CAN0IDAR1STR _CAN0IDAR1 @(REG_BASE + 0x00000151UL);
#define CAN0IDAR1                       _CAN0IDAR1.Byte
#define CAN0IDAR1_AC0                   _CAN0IDAR1.Bits.AC0
#define CAN0IDAR1_AC1                   _CAN0IDAR1.Bits.AC1
#define CAN0IDAR1_AC2                   _CAN0IDAR1.Bits.AC2
#define CAN0IDAR1_AC3                   _CAN0IDAR1.Bits.AC3
#define CAN0IDAR1_AC4                   _CAN0IDAR1.Bits.AC4
#define CAN0IDAR1_AC5                   _CAN0IDAR1.Bits.AC5
#define CAN0IDAR1_AC6                   _CAN0IDAR1.Bits.AC6
#define CAN0IDAR1_AC7                   _CAN0IDAR1.Bits.AC7

#define CAN0IDAR1_AC0_MASK              1U
#define CAN0IDAR1_AC1_MASK              2U
#define CAN0IDAR1_AC2_MASK              4U
#define CAN0IDAR1_AC3_MASK              8U
#define CAN0IDAR1_AC4_MASK              16U
#define CAN0IDAR1_AC5_MASK              32U
#define CAN0IDAR1_AC6_MASK              64U
#define CAN0IDAR1_AC7_MASK              128U


/*** CAN0IDAR2 - MSCAN0 Identifier Acceptance Register 2; 0x00000152 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CAN0IDAR2STR;
extern volatile CAN0IDAR2STR _CAN0IDAR2 @(REG_BASE + 0x00000152UL);
#define CAN0IDAR2                       _CAN0IDAR2.Byte
#define CAN0IDAR2_AC0                   _CAN0IDAR2.Bits.AC0
#define CAN0IDAR2_AC1                   _CAN0IDAR2.Bits.AC1
#define CAN0IDAR2_AC2                   _CAN0IDAR2.Bits.AC2
#define CAN0IDAR2_AC3                   _CAN0IDAR2.Bits.AC3
#define CAN0IDAR2_AC4                   _CAN0IDAR2.Bits.AC4
#define CAN0IDAR2_AC5                   _CAN0IDAR2.Bits.AC5
#define CAN0IDAR2_AC6                   _CAN0IDAR2.Bits.AC6
#define CAN0IDAR2_AC7                   _CAN0IDAR2.Bits.AC7

#define CAN0IDAR2_AC0_MASK              1U
#define CAN0IDAR2_AC1_MASK              2U
#define CAN0IDAR2_AC2_MASK              4U
#define CAN0IDAR2_AC3_MASK              8U
#define CAN0IDAR2_AC4_MASK              16U
#define CAN0IDAR2_AC5_MASK              32U
#define CAN0IDAR2_AC6_MASK              64U
#define CAN0IDAR2_AC7_MASK              128U


/*** CAN0IDAR3 - MSCAN0 Identifier Acceptance Register 3; 0x00000153 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CAN0IDAR3STR;
extern volatile CAN0IDAR3STR _CAN0IDAR3 @(REG_BASE + 0x00000153UL);
#define CAN0IDAR3                       _CAN0IDAR3.Byte
#define CAN0IDAR3_AC0                   _CAN0IDAR3.Bits.AC0
#define CAN0IDAR3_AC1                   _CAN0IDAR3.Bits.AC1
#define CAN0IDAR3_AC2                   _CAN0IDAR3.Bits.AC2
#define CAN0IDAR3_AC3                   _CAN0IDAR3.Bits.AC3
#define CAN0IDAR3_AC4                   _CAN0IDAR3.Bits.AC4
#define CAN0IDAR3_AC5                   _CAN0IDAR3.Bits.AC5
#define CAN0IDAR3_AC6                   _CAN0IDAR3.Bits.AC6
#define CAN0IDAR3_AC7                   _CAN0IDAR3.Bits.AC7

#define CAN0IDAR3_AC0_MASK              1U
#define CAN0IDAR3_AC1_MASK              2U
#define CAN0IDAR3_AC2_MASK              4U
#define CAN0IDAR3_AC3_MASK              8U
#define CAN0IDAR3_AC4_MASK              16U
#define CAN0IDAR3_AC5_MASK              32U
#define CAN0IDAR3_AC6_MASK              64U
#define CAN0IDAR3_AC7_MASK              128U


/*** CAN0IDMR0 - MSCAN0 Identifier Mask Register 0; 0x00000154 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CAN0IDMR0STR;
extern volatile CAN0IDMR0STR _CAN0IDMR0 @(REG_BASE + 0x00000154UL);
#define CAN0IDMR0                       _CAN0IDMR0.Byte
#define CAN0IDMR0_AM0                   _CAN0IDMR0.Bits.AM0
#define CAN0IDMR0_AM1                   _CAN0IDMR0.Bits.AM1
#define CAN0IDMR0_AM2                   _CAN0IDMR0.Bits.AM2
#define CAN0IDMR0_AM3                   _CAN0IDMR0.Bits.AM3
#define CAN0IDMR0_AM4                   _CAN0IDMR0.Bits.AM4
#define CAN0IDMR0_AM5                   _CAN0IDMR0.Bits.AM5
#define CAN0IDMR0_AM6                   _CAN0IDMR0.Bits.AM6
#define CAN0IDMR0_AM7                   _CAN0IDMR0.Bits.AM7
/* CAN0IDMR_ARR: Access 4 CAN0IDMRx registers in an array */
#define CAN0IDMR_ARR                    ((volatile byte *) &CAN0IDMR0)

#define CAN0IDMR0_AM0_MASK              1U
#define CAN0IDMR0_AM1_MASK              2U
#define CAN0IDMR0_AM2_MASK              4U
#define CAN0IDMR0_AM3_MASK              8U
#define CAN0IDMR0_AM4_MASK              16U
#define CAN0IDMR0_AM5_MASK              32U
#define CAN0IDMR0_AM6_MASK              64U
#define CAN0IDMR0_AM7_MASK              128U


/*** CAN0IDMR1 - MSCAN0 Identifier Mask Register 1; 0x00000155 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CAN0IDMR1STR;
extern volatile CAN0IDMR1STR _CAN0IDMR1 @(REG_BASE + 0x00000155UL);
#define CAN0IDMR1                       _CAN0IDMR1.Byte
#define CAN0IDMR1_AM0                   _CAN0IDMR1.Bits.AM0
#define CAN0IDMR1_AM1                   _CAN0IDMR1.Bits.AM1
#define CAN0IDMR1_AM2                   _CAN0IDMR1.Bits.AM2
#define CAN0IDMR1_AM3                   _CAN0IDMR1.Bits.AM3
#define CAN0IDMR1_AM4                   _CAN0IDMR1.Bits.AM4
#define CAN0IDMR1_AM5                   _CAN0IDMR1.Bits.AM5
#define CAN0IDMR1_AM6                   _CAN0IDMR1.Bits.AM6
#define CAN0IDMR1_AM7                   _CAN0IDMR1.Bits.AM7

#define CAN0IDMR1_AM0_MASK              1U
#define CAN0IDMR1_AM1_MASK              2U
#define CAN0IDMR1_AM2_MASK              4U
#define CAN0IDMR1_AM3_MASK              8U
#define CAN0IDMR1_AM4_MASK              16U
#define CAN0IDMR1_AM5_MASK              32U
#define CAN0IDMR1_AM6_MASK              64U
#define CAN0IDMR1_AM7_MASK              128U


/*** CAN0IDMR2 - MSCAN0 Identifier Mask Register 2; 0x00000156 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CAN0IDMR2STR;
extern volatile CAN0IDMR2STR _CAN0IDMR2 @(REG_BASE + 0x00000156UL);
#define CAN0IDMR2                       _CAN0IDMR2.Byte
#define CAN0IDMR2_AM0                   _CAN0IDMR2.Bits.AM0
#define CAN0IDMR2_AM1                   _CAN0IDMR2.Bits.AM1
#define CAN0IDMR2_AM2                   _CAN0IDMR2.Bits.AM2
#define CAN0IDMR2_AM3                   _CAN0IDMR2.Bits.AM3
#define CAN0IDMR2_AM4                   _CAN0IDMR2.Bits.AM4
#define CAN0IDMR2_AM5                   _CAN0IDMR2.Bits.AM5
#define CAN0IDMR2_AM6                   _CAN0IDMR2.Bits.AM6
#define CAN0IDMR2_AM7                   _CAN0IDMR2.Bits.AM7

#define CAN0IDMR2_AM0_MASK              1U
#define CAN0IDMR2_AM1_MASK              2U
#define CAN0IDMR2_AM2_MASK              4U
#define CAN0IDMR2_AM3_MASK              8U
#define CAN0IDMR2_AM4_MASK              16U
#define CAN0IDMR2_AM5_MASK              32U
#define CAN0IDMR2_AM6_MASK              64U
#define CAN0IDMR2_AM7_MASK              128U


/*** CAN0IDMR3 - MSCAN0 Identifier Mask Register 3; 0x00000157 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CAN0IDMR3STR;
extern volatile CAN0IDMR3STR _CAN0IDMR3 @(REG_BASE + 0x00000157UL);
#define CAN0IDMR3                       _CAN0IDMR3.Byte
#define CAN0IDMR3_AM0                   _CAN0IDMR3.Bits.AM0
#define CAN0IDMR3_AM1                   _CAN0IDMR3.Bits.AM1
#define CAN0IDMR3_AM2                   _CAN0IDMR3.Bits.AM2
#define CAN0IDMR3_AM3                   _CAN0IDMR3.Bits.AM3
#define CAN0IDMR3_AM4                   _CAN0IDMR3.Bits.AM4
#define CAN0IDMR3_AM5                   _CAN0IDMR3.Bits.AM5
#define CAN0IDMR3_AM6                   _CAN0IDMR3.Bits.AM6
#define CAN0IDMR3_AM7                   _CAN0IDMR3.Bits.AM7

#define CAN0IDMR3_AM0_MASK              1U
#define CAN0IDMR3_AM1_MASK              2U
#define CAN0IDMR3_AM2_MASK              4U
#define CAN0IDMR3_AM3_MASK              8U
#define CAN0IDMR3_AM4_MASK              16U
#define CAN0IDMR3_AM5_MASK              32U
#define CAN0IDMR3_AM6_MASK              64U
#define CAN0IDMR3_AM7_MASK              128U


/*** CAN0IDAR4 - MSCAN0 Identifier Acceptance Register 4; 0x00000158 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CAN0IDAR4STR;
extern volatile CAN0IDAR4STR _CAN0IDAR4 @(REG_BASE + 0x00000158UL);
#define CAN0IDAR4                       _CAN0IDAR4.Byte
#define CAN0IDAR4_AC0                   _CAN0IDAR4.Bits.AC0
#define CAN0IDAR4_AC1                   _CAN0IDAR4.Bits.AC1
#define CAN0IDAR4_AC2                   _CAN0IDAR4.Bits.AC2
#define CAN0IDAR4_AC3                   _CAN0IDAR4.Bits.AC3
#define CAN0IDAR4_AC4                   _CAN0IDAR4.Bits.AC4
#define CAN0IDAR4_AC5                   _CAN0IDAR4.Bits.AC5
#define CAN0IDAR4_AC6                   _CAN0IDAR4.Bits.AC6
#define CAN0IDAR4_AC7                   _CAN0IDAR4.Bits.AC7

#define CAN0IDAR4_AC0_MASK              1U
#define CAN0IDAR4_AC1_MASK              2U
#define CAN0IDAR4_AC2_MASK              4U
#define CAN0IDAR4_AC3_MASK              8U
#define CAN0IDAR4_AC4_MASK              16U
#define CAN0IDAR4_AC5_MASK              32U
#define CAN0IDAR4_AC6_MASK              64U
#define CAN0IDAR4_AC7_MASK              128U


/*** CAN0IDAR5 - MSCAN0 Identifier Acceptance Register 5; 0x00000159 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CAN0IDAR5STR;
extern volatile CAN0IDAR5STR _CAN0IDAR5 @(REG_BASE + 0x00000159UL);
#define CAN0IDAR5                       _CAN0IDAR5.Byte
#define CAN0IDAR5_AC0                   _CAN0IDAR5.Bits.AC0
#define CAN0IDAR5_AC1                   _CAN0IDAR5.Bits.AC1
#define CAN0IDAR5_AC2                   _CAN0IDAR5.Bits.AC2
#define CAN0IDAR5_AC3                   _CAN0IDAR5.Bits.AC3
#define CAN0IDAR5_AC4                   _CAN0IDAR5.Bits.AC4
#define CAN0IDAR5_AC5                   _CAN0IDAR5.Bits.AC5
#define CAN0IDAR5_AC6                   _CAN0IDAR5.Bits.AC6
#define CAN0IDAR5_AC7                   _CAN0IDAR5.Bits.AC7

#define CAN0IDAR5_AC0_MASK              1U
#define CAN0IDAR5_AC1_MASK              2U
#define CAN0IDAR5_AC2_MASK              4U
#define CAN0IDAR5_AC3_MASK              8U
#define CAN0IDAR5_AC4_MASK              16U
#define CAN0IDAR5_AC5_MASK              32U
#define CAN0IDAR5_AC6_MASK              64U
#define CAN0IDAR5_AC7_MASK              128U


/*** CAN0IDAR6 - MSCAN0 Identifier Acceptance Register 6; 0x0000015A ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CAN0IDAR6STR;
extern volatile CAN0IDAR6STR _CAN0IDAR6 @(REG_BASE + 0x0000015AUL);
#define CAN0IDAR6                       _CAN0IDAR6.Byte
#define CAN0IDAR6_AC0                   _CAN0IDAR6.Bits.AC0
#define CAN0IDAR6_AC1                   _CAN0IDAR6.Bits.AC1
#define CAN0IDAR6_AC2                   _CAN0IDAR6.Bits.AC2
#define CAN0IDAR6_AC3                   _CAN0IDAR6.Bits.AC3
#define CAN0IDAR6_AC4                   _CAN0IDAR6.Bits.AC4
#define CAN0IDAR6_AC5                   _CAN0IDAR6.Bits.AC5
#define CAN0IDAR6_AC6                   _CAN0IDAR6.Bits.AC6
#define CAN0IDAR6_AC7                   _CAN0IDAR6.Bits.AC7

#define CAN0IDAR6_AC0_MASK              1U
#define CAN0IDAR6_AC1_MASK              2U
#define CAN0IDAR6_AC2_MASK              4U
#define CAN0IDAR6_AC3_MASK              8U
#define CAN0IDAR6_AC4_MASK              16U
#define CAN0IDAR6_AC5_MASK              32U
#define CAN0IDAR6_AC6_MASK              64U
#define CAN0IDAR6_AC7_MASK              128U


/*** CAN0IDAR7 - MSCAN0 Identifier Acceptance Register 7; 0x0000015B ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CAN0IDAR7STR;
extern volatile CAN0IDAR7STR _CAN0IDAR7 @(REG_BASE + 0x0000015BUL);
#define CAN0IDAR7                       _CAN0IDAR7.Byte
#define CAN0IDAR7_AC0                   _CAN0IDAR7.Bits.AC0
#define CAN0IDAR7_AC1                   _CAN0IDAR7.Bits.AC1
#define CAN0IDAR7_AC2                   _CAN0IDAR7.Bits.AC2
#define CAN0IDAR7_AC3                   _CAN0IDAR7.Bits.AC3
#define CAN0IDAR7_AC4                   _CAN0IDAR7.Bits.AC4
#define CAN0IDAR7_AC5                   _CAN0IDAR7.Bits.AC5
#define CAN0IDAR7_AC6                   _CAN0IDAR7.Bits.AC6
#define CAN0IDAR7_AC7                   _CAN0IDAR7.Bits.AC7

#define CAN0IDAR7_AC0_MASK              1U
#define CAN0IDAR7_AC1_MASK              2U
#define CAN0IDAR7_AC2_MASK              4U
#define CAN0IDAR7_AC3_MASK              8U
#define CAN0IDAR7_AC4_MASK              16U
#define CAN0IDAR7_AC5_MASK              32U
#define CAN0IDAR7_AC6_MASK              64U
#define CAN0IDAR7_AC7_MASK              128U


/*** CAN0IDMR4 - MSCAN0 Identifier Mask Register 4; 0x0000015C ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CAN0IDMR4STR;
extern volatile CAN0IDMR4STR _CAN0IDMR4 @(REG_BASE + 0x0000015CUL);
#define CAN0IDMR4                       _CAN0IDMR4.Byte
#define CAN0IDMR4_AM0                   _CAN0IDMR4.Bits.AM0
#define CAN0IDMR4_AM1                   _CAN0IDMR4.Bits.AM1
#define CAN0IDMR4_AM2                   _CAN0IDMR4.Bits.AM2
#define CAN0IDMR4_AM3                   _CAN0IDMR4.Bits.AM3
#define CAN0IDMR4_AM4                   _CAN0IDMR4.Bits.AM4
#define CAN0IDMR4_AM5                   _CAN0IDMR4.Bits.AM5
#define CAN0IDMR4_AM6                   _CAN0IDMR4.Bits.AM6
#define CAN0IDMR4_AM7                   _CAN0IDMR4.Bits.AM7

#define CAN0IDMR4_AM0_MASK              1U
#define CAN0IDMR4_AM1_MASK              2U
#define CAN0IDMR4_AM2_MASK              4U
#define CAN0IDMR4_AM3_MASK              8U
#define CAN0IDMR4_AM4_MASK              16U
#define CAN0IDMR4_AM5_MASK              32U
#define CAN0IDMR4_AM6_MASK              64U
#define CAN0IDMR4_AM7_MASK              128U


/*** CAN0IDMR5 - MSCAN0 Identifier Mask Register 5; 0x0000015D ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CAN0IDMR5STR;
extern volatile CAN0IDMR5STR _CAN0IDMR5 @(REG_BASE + 0x0000015DUL);
#define CAN0IDMR5                       _CAN0IDMR5.Byte
#define CAN0IDMR5_AM0                   _CAN0IDMR5.Bits.AM0
#define CAN0IDMR5_AM1                   _CAN0IDMR5.Bits.AM1
#define CAN0IDMR5_AM2                   _CAN0IDMR5.Bits.AM2
#define CAN0IDMR5_AM3                   _CAN0IDMR5.Bits.AM3
#define CAN0IDMR5_AM4                   _CAN0IDMR5.Bits.AM4
#define CAN0IDMR5_AM5                   _CAN0IDMR5.Bits.AM5
#define CAN0IDMR5_AM6                   _CAN0IDMR5.Bits.AM6
#define CAN0IDMR5_AM7                   _CAN0IDMR5.Bits.AM7

#define CAN0IDMR5_AM0_MASK              1U
#define CAN0IDMR5_AM1_MASK              2U
#define CAN0IDMR5_AM2_MASK              4U
#define CAN0IDMR5_AM3_MASK              8U
#define CAN0IDMR5_AM4_MASK              16U
#define CAN0IDMR5_AM5_MASK              32U
#define CAN0IDMR5_AM6_MASK              64U
#define CAN0IDMR5_AM7_MASK              128U


/*** CAN0IDMR6 - MSCAN0 Identifier Mask Register 6; 0x0000015E ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CAN0IDMR6STR;
extern volatile CAN0IDMR6STR _CAN0IDMR6 @(REG_BASE + 0x0000015EUL);
#define CAN0IDMR6                       _CAN0IDMR6.Byte
#define CAN0IDMR6_AM0                   _CAN0IDMR6.Bits.AM0
#define CAN0IDMR6_AM1                   _CAN0IDMR6.Bits.AM1
#define CAN0IDMR6_AM2                   _CAN0IDMR6.Bits.AM2
#define CAN0IDMR6_AM3                   _CAN0IDMR6.Bits.AM3
#define CAN0IDMR6_AM4                   _CAN0IDMR6.Bits.AM4
#define CAN0IDMR6_AM5                   _CAN0IDMR6.Bits.AM5
#define CAN0IDMR6_AM6                   _CAN0IDMR6.Bits.AM6
#define CAN0IDMR6_AM7                   _CAN0IDMR6.Bits.AM7

#define CAN0IDMR6_AM0_MASK              1U
#define CAN0IDMR6_AM1_MASK              2U
#define CAN0IDMR6_AM2_MASK              4U
#define CAN0IDMR6_AM3_MASK              8U
#define CAN0IDMR6_AM4_MASK              16U
#define CAN0IDMR6_AM5_MASK              32U
#define CAN0IDMR6_AM6_MASK              64U
#define CAN0IDMR6_AM7_MASK              128U


/*** CAN0IDMR7 - MSCAN0 Identifier Mask Register 7; 0x0000015F ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CAN0IDMR7STR;
extern volatile CAN0IDMR7STR _CAN0IDMR7 @(REG_BASE + 0x0000015FUL);
#define CAN0IDMR7                       _CAN0IDMR7.Byte
#define CAN0IDMR7_AM0                   _CAN0IDMR7.Bits.AM0
#define CAN0IDMR7_AM1                   _CAN0IDMR7.Bits.AM1
#define CAN0IDMR7_AM2                   _CAN0IDMR7.Bits.AM2
#define CAN0IDMR7_AM3                   _CAN0IDMR7.Bits.AM3
#define CAN0IDMR7_AM4                   _CAN0IDMR7.Bits.AM4
#define CAN0IDMR7_AM5                   _CAN0IDMR7.Bits.AM5
#define CAN0IDMR7_AM6                   _CAN0IDMR7.Bits.AM6
#define CAN0IDMR7_AM7                   _CAN0IDMR7.Bits.AM7

#define CAN0IDMR7_AM0_MASK              1U
#define CAN0IDMR7_AM1_MASK              2U
#define CAN0IDMR7_AM2_MASK              4U
#define CAN0IDMR7_AM3_MASK              8U
#define CAN0IDMR7_AM4_MASK              16U
#define CAN0IDMR7_AM5_MASK              32U
#define CAN0IDMR7_AM6_MASK              64U
#define CAN0IDMR7_AM7_MASK              128U


/*** CAN0RXIDR0 - MSCAN0 Receive Identifier Register 0; 0x00000160 ***/
typedef union {
  byte Byte;
  struct {
    byte ID21        :1;                                       /* Extended format identifier Bit 21 */
    byte ID22        :1;                                       /* Extended format identifier Bit 22 */
    byte ID23        :1;                                       /* Extended format identifier Bit 23 */
    byte ID24        :1;                                       /* Extended format identifier Bit 24 */
    byte ID25        :1;                                       /* Extended format identifier Bit 25 */
    byte ID26        :1;                                       /* Extended format identifier Bit 26 */
    byte ID27        :1;                                       /* Extended format identifier Bit 27 */
    byte ID28        :1;                                       /* Extended format identifier Bit 28 */
  } Bits;
} CAN0RXIDR0STR;
extern volatile CAN0RXIDR0STR _CAN0RXIDR0 @(REG_BASE + 0x00000160UL);
#define CAN0RXIDR0                      _CAN0RXIDR0.Byte
#define CAN0RXIDR0_ID21                 _CAN0RXIDR0.Bits.ID21
#define CAN0RXIDR0_ID22                 _CAN0RXIDR0.Bits.ID22
#define CAN0RXIDR0_ID23                 _CAN0RXIDR0.Bits.ID23
#define CAN0RXIDR0_ID24                 _CAN0RXIDR0.Bits.ID24
#define CAN0RXIDR0_ID25                 _CAN0RXIDR0.Bits.ID25
#define CAN0RXIDR0_ID26                 _CAN0RXIDR0.Bits.ID26
#define CAN0RXIDR0_ID27                 _CAN0RXIDR0.Bits.ID27
#define CAN0RXIDR0_ID28                 _CAN0RXIDR0.Bits.ID28
/* CAN0RXIDR_ARR: Access 4 CAN0RXIDRx registers in an array */
#define CAN0RXIDR_ARR                   ((volatile byte *) &CAN0RXIDR0)

#define CAN0RXIDR0_ID21_MASK            1U
#define CAN0RXIDR0_ID22_MASK            2U
#define CAN0RXIDR0_ID23_MASK            4U
#define CAN0RXIDR0_ID24_MASK            8U
#define CAN0RXIDR0_ID25_MASK            16U
#define CAN0RXIDR0_ID26_MASK            32U
#define CAN0RXIDR0_ID27_MASK            64U
#define CAN0RXIDR0_ID28_MASK            128U


/*** CAN0RXIDR1 - MSCAN0 Receive Identifier Register 1; 0x00000161 ***/
typedef union {
  byte Byte;
  struct {
    byte ID15        :1;                                       /* Extended format identifier Bit 15 */
    byte ID16        :1;                                       /* Extended format identifier Bit 16 */
    byte ID17        :1;                                       /* Extended format identifier Bit 17 */
    byte IDE         :1;                                       /* ID Extended */
    byte SRR         :1;                                       /* Substitute Remote Request */
    byte ID18        :1;                                       /* Extended format identifier Bit 18 */
    byte ID19        :1;                                       /* Extended format identifier Bit 19 */
    byte ID20        :1;                                       /* Extended format identifier Bit 20 */
  } Bits;
  struct {
    byte grpID_15 :3;
    byte         :1;
    byte         :1;
    byte grpID_18 :3;
  } MergedBits;
} CAN0RXIDR1STR;
extern volatile CAN0RXIDR1STR _CAN0RXIDR1 @(REG_BASE + 0x00000161UL);
#define CAN0RXIDR1                      _CAN0RXIDR1.Byte
#define CAN0RXIDR1_ID15                 _CAN0RXIDR1.Bits.ID15
#define CAN0RXIDR1_ID16                 _CAN0RXIDR1.Bits.ID16
#define CAN0RXIDR1_ID17                 _CAN0RXIDR1.Bits.ID17
#define CAN0RXIDR1_IDE                  _CAN0RXIDR1.Bits.IDE
#define CAN0RXIDR1_SRR                  _CAN0RXIDR1.Bits.SRR
#define CAN0RXIDR1_ID18                 _CAN0RXIDR1.Bits.ID18
#define CAN0RXIDR1_ID19                 _CAN0RXIDR1.Bits.ID19
#define CAN0RXIDR1_ID20                 _CAN0RXIDR1.Bits.ID20
#define CAN0RXIDR1_ID_15                _CAN0RXIDR1.MergedBits.grpID_15
#define CAN0RXIDR1_ID_18                _CAN0RXIDR1.MergedBits.grpID_18
#define CAN0RXIDR1_ID                   CAN0RXIDR1_ID_15

#define CAN0RXIDR1_ID15_MASK            1U
#define CAN0RXIDR1_ID16_MASK            2U
#define CAN0RXIDR1_ID17_MASK            4U
#define CAN0RXIDR1_IDE_MASK             8U
#define CAN0RXIDR1_SRR_MASK             16U
#define CAN0RXIDR1_ID18_MASK            32U
#define CAN0RXIDR1_ID19_MASK            64U
#define CAN0RXIDR1_ID20_MASK            128U
#define CAN0RXIDR1_ID_15_MASK           7U
#define CAN0RXIDR1_ID_15_BITNUM         0U
#define CAN0RXIDR1_ID_18_MASK           224U
#define CAN0RXIDR1_ID_18_BITNUM         5U


/*** CAN0RXIDR2 - MSCAN0 Receive Identifier Register 2; 0x00000162 ***/
typedef union {
  byte Byte;
  struct {
    byte ID7         :1;                                       /* Extended format identifier Bit 7 */
    byte ID8         :1;                                       /* Extended format identifier Bit 8 */
    byte ID9         :1;                                       /* Extended format identifier Bit 9 */
    byte ID10        :1;                                       /* Extended format identifier Bit 10 */
    byte ID11        :1;                                       /* Extended format identifier Bit 11 */
    byte ID12        :1;                                       /* Extended format identifier Bit 12 */
    byte ID13        :1;                                       /* Extended format identifier Bit 13 */
    byte ID14        :1;                                       /* Extended format identifier Bit 14 */
  } Bits;
} CAN0RXIDR2STR;
extern volatile CAN0RXIDR2STR _CAN0RXIDR2 @(REG_BASE + 0x00000162UL);
#define CAN0RXIDR2                      _CAN0RXIDR2.Byte
#define CAN0RXIDR2_ID7                  _CAN0RXIDR2.Bits.ID7
#define CAN0RXIDR2_ID8                  _CAN0RXIDR2.Bits.ID8
#define CAN0RXIDR2_ID9                  _CAN0RXIDR2.Bits.ID9
#define CAN0RXIDR2_ID10                 _CAN0RXIDR2.Bits.ID10
#define CAN0RXIDR2_ID11                 _CAN0RXIDR2.Bits.ID11
#define CAN0RXIDR2_ID12                 _CAN0RXIDR2.Bits.ID12
#define CAN0RXIDR2_ID13                 _CAN0RXIDR2.Bits.ID13
#define CAN0RXIDR2_ID14                 _CAN0RXIDR2.Bits.ID14

#define CAN0RXIDR2_ID7_MASK             1U
#define CAN0RXIDR2_ID8_MASK             2U
#define CAN0RXIDR2_ID9_MASK             4U
#define CAN0RXIDR2_ID10_MASK            8U
#define CAN0RXIDR2_ID11_MASK            16U
#define CAN0RXIDR2_ID12_MASK            32U
#define CAN0RXIDR2_ID13_MASK            64U
#define CAN0RXIDR2_ID14_MASK            128U


/*** CAN0RXIDR3 - MSCAN0 Receive Identifier Register 3; 0x00000163 ***/
typedef union {
  byte Byte;
  struct {
    byte RTR         :1;                                       /* Remote Transmission Request */
    byte ID0         :1;                                       /* Extended format identifier Bit 0 */
    byte ID1         :1;                                       /* Extended format identifier Bit 1 */
    byte ID2         :1;                                       /* Extended format identifier Bit 2 */
    byte ID3         :1;                                       /* Extended format identifier Bit 3 */
    byte ID4         :1;                                       /* Extended format identifier Bit 4 */
    byte ID5         :1;                                       /* Extended format identifier Bit 5 */
    byte ID6         :1;                                       /* Extended format identifier Bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpID   :7;
  } MergedBits;
} CAN0RXIDR3STR;
extern volatile CAN0RXIDR3STR _CAN0RXIDR3 @(REG_BASE + 0x00000163UL);
#define CAN0RXIDR3                      _CAN0RXIDR3.Byte
#define CAN0RXIDR3_RTR                  _CAN0RXIDR3.Bits.RTR
#define CAN0RXIDR3_ID0                  _CAN0RXIDR3.Bits.ID0
#define CAN0RXIDR3_ID1                  _CAN0RXIDR3.Bits.ID1
#define CAN0RXIDR3_ID2                  _CAN0RXIDR3.Bits.ID2
#define CAN0RXIDR3_ID3                  _CAN0RXIDR3.Bits.ID3
#define CAN0RXIDR3_ID4                  _CAN0RXIDR3.Bits.ID4
#define CAN0RXIDR3_ID5                  _CAN0RXIDR3.Bits.ID5
#define CAN0RXIDR3_ID6                  _CAN0RXIDR3.Bits.ID6
#define CAN0RXIDR3_ID                   _CAN0RXIDR3.MergedBits.grpID

#define CAN0RXIDR3_RTR_MASK             1U
#define CAN0RXIDR3_ID0_MASK             2U
#define CAN0RXIDR3_ID1_MASK             4U
#define CAN0RXIDR3_ID2_MASK             8U
#define CAN0RXIDR3_ID3_MASK             16U
#define CAN0RXIDR3_ID4_MASK             32U
#define CAN0RXIDR3_ID5_MASK             64U
#define CAN0RXIDR3_ID6_MASK             128U
#define CAN0RXIDR3_ID_MASK              254U
#define CAN0RXIDR3_ID_BITNUM            1U


/*** CAN0RXDSR0 - MSCAN0 Receive Data Segment Register 0; 0x00000164 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CAN0RXDSR0STR;
extern volatile CAN0RXDSR0STR _CAN0RXDSR0 @(REG_BASE + 0x00000164UL);
#define CAN0RXDSR0                      _CAN0RXDSR0.Byte
#define CAN0RXDSR0_DB0                  _CAN0RXDSR0.Bits.DB0
#define CAN0RXDSR0_DB1                  _CAN0RXDSR0.Bits.DB1
#define CAN0RXDSR0_DB2                  _CAN0RXDSR0.Bits.DB2
#define CAN0RXDSR0_DB3                  _CAN0RXDSR0.Bits.DB3
#define CAN0RXDSR0_DB4                  _CAN0RXDSR0.Bits.DB4
#define CAN0RXDSR0_DB5                  _CAN0RXDSR0.Bits.DB5
#define CAN0RXDSR0_DB6                  _CAN0RXDSR0.Bits.DB6
#define CAN0RXDSR0_DB7                  _CAN0RXDSR0.Bits.DB7
/* CAN0RXDSR_ARR: Access 8 CAN0RXDSRx registers in an array */
#define CAN0RXDSR_ARR                   ((volatile byte *) &CAN0RXDSR0)

#define CAN0RXDSR0_DB0_MASK             1U
#define CAN0RXDSR0_DB1_MASK             2U
#define CAN0RXDSR0_DB2_MASK             4U
#define CAN0RXDSR0_DB3_MASK             8U
#define CAN0RXDSR0_DB4_MASK             16U
#define CAN0RXDSR0_DB5_MASK             32U
#define CAN0RXDSR0_DB6_MASK             64U
#define CAN0RXDSR0_DB7_MASK             128U


/*** CAN0RXDSR1 - MSCAN0 Receive Data Segment Register 1; 0x00000165 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CAN0RXDSR1STR;
extern volatile CAN0RXDSR1STR _CAN0RXDSR1 @(REG_BASE + 0x00000165UL);
#define CAN0RXDSR1                      _CAN0RXDSR1.Byte
#define CAN0RXDSR1_DB0                  _CAN0RXDSR1.Bits.DB0
#define CAN0RXDSR1_DB1                  _CAN0RXDSR1.Bits.DB1
#define CAN0RXDSR1_DB2                  _CAN0RXDSR1.Bits.DB2
#define CAN0RXDSR1_DB3                  _CAN0RXDSR1.Bits.DB3
#define CAN0RXDSR1_DB4                  _CAN0RXDSR1.Bits.DB4
#define CAN0RXDSR1_DB5                  _CAN0RXDSR1.Bits.DB5
#define CAN0RXDSR1_DB6                  _CAN0RXDSR1.Bits.DB6
#define CAN0RXDSR1_DB7                  _CAN0RXDSR1.Bits.DB7

#define CAN0RXDSR1_DB0_MASK             1U
#define CAN0RXDSR1_DB1_MASK             2U
#define CAN0RXDSR1_DB2_MASK             4U
#define CAN0RXDSR1_DB3_MASK             8U
#define CAN0RXDSR1_DB4_MASK             16U
#define CAN0RXDSR1_DB5_MASK             32U
#define CAN0RXDSR1_DB6_MASK             64U
#define CAN0RXDSR1_DB7_MASK             128U


/*** CAN0RXDSR2 - MSCAN0 Receive Data Segment Register 2; 0x00000166 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CAN0RXDSR2STR;
extern volatile CAN0RXDSR2STR _CAN0RXDSR2 @(REG_BASE + 0x00000166UL);
#define CAN0RXDSR2                      _CAN0RXDSR2.Byte
#define CAN0RXDSR2_DB0                  _CAN0RXDSR2.Bits.DB0
#define CAN0RXDSR2_DB1                  _CAN0RXDSR2.Bits.DB1
#define CAN0RXDSR2_DB2                  _CAN0RXDSR2.Bits.DB2
#define CAN0RXDSR2_DB3                  _CAN0RXDSR2.Bits.DB3
#define CAN0RXDSR2_DB4                  _CAN0RXDSR2.Bits.DB4
#define CAN0RXDSR2_DB5                  _CAN0RXDSR2.Bits.DB5
#define CAN0RXDSR2_DB6                  _CAN0RXDSR2.Bits.DB6
#define CAN0RXDSR2_DB7                  _CAN0RXDSR2.Bits.DB7

#define CAN0RXDSR2_DB0_MASK             1U
#define CAN0RXDSR2_DB1_MASK             2U
#define CAN0RXDSR2_DB2_MASK             4U
#define CAN0RXDSR2_DB3_MASK             8U
#define CAN0RXDSR2_DB4_MASK             16U
#define CAN0RXDSR2_DB5_MASK             32U
#define CAN0RXDSR2_DB6_MASK             64U
#define CAN0RXDSR2_DB7_MASK             128U


/*** CAN0RXDSR3 - MSCAN0 Receive Data Segment Register 3; 0x00000167 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CAN0RXDSR3STR;
extern volatile CAN0RXDSR3STR _CAN0RXDSR3 @(REG_BASE + 0x00000167UL);
#define CAN0RXDSR3                      _CAN0RXDSR3.Byte
#define CAN0RXDSR3_DB0                  _CAN0RXDSR3.Bits.DB0
#define CAN0RXDSR3_DB1                  _CAN0RXDSR3.Bits.DB1
#define CAN0RXDSR3_DB2                  _CAN0RXDSR3.Bits.DB2
#define CAN0RXDSR3_DB3                  _CAN0RXDSR3.Bits.DB3
#define CAN0RXDSR3_DB4                  _CAN0RXDSR3.Bits.DB4
#define CAN0RXDSR3_DB5                  _CAN0RXDSR3.Bits.DB5
#define CAN0RXDSR3_DB6                  _CAN0RXDSR3.Bits.DB6
#define CAN0RXDSR3_DB7                  _CAN0RXDSR3.Bits.DB7

#define CAN0RXDSR3_DB0_MASK             1U
#define CAN0RXDSR3_DB1_MASK             2U
#define CAN0RXDSR3_DB2_MASK             4U
#define CAN0RXDSR3_DB3_MASK             8U
#define CAN0RXDSR3_DB4_MASK             16U
#define CAN0RXDSR3_DB5_MASK             32U
#define CAN0RXDSR3_DB6_MASK             64U
#define CAN0RXDSR3_DB7_MASK             128U


/*** CAN0RXDSR4 - MSCAN0 Receive Data Segment Register 4; 0x00000168 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CAN0RXDSR4STR;
extern volatile CAN0RXDSR4STR _CAN0RXDSR4 @(REG_BASE + 0x00000168UL);
#define CAN0RXDSR4                      _CAN0RXDSR4.Byte
#define CAN0RXDSR4_DB0                  _CAN0RXDSR4.Bits.DB0
#define CAN0RXDSR4_DB1                  _CAN0RXDSR4.Bits.DB1
#define CAN0RXDSR4_DB2                  _CAN0RXDSR4.Bits.DB2
#define CAN0RXDSR4_DB3                  _CAN0RXDSR4.Bits.DB3
#define CAN0RXDSR4_DB4                  _CAN0RXDSR4.Bits.DB4
#define CAN0RXDSR4_DB5                  _CAN0RXDSR4.Bits.DB5
#define CAN0RXDSR4_DB6                  _CAN0RXDSR4.Bits.DB6
#define CAN0RXDSR4_DB7                  _CAN0RXDSR4.Bits.DB7

#define CAN0RXDSR4_DB0_MASK             1U
#define CAN0RXDSR4_DB1_MASK             2U
#define CAN0RXDSR4_DB2_MASK             4U
#define CAN0RXDSR4_DB3_MASK             8U
#define CAN0RXDSR4_DB4_MASK             16U
#define CAN0RXDSR4_DB5_MASK             32U
#define CAN0RXDSR4_DB6_MASK             64U
#define CAN0RXDSR4_DB7_MASK             128U


/*** CAN0RXDSR5 - MSCAN0 Receive Data Segment Register 5; 0x00000169 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CAN0RXDSR5STR;
extern volatile CAN0RXDSR5STR _CAN0RXDSR5 @(REG_BASE + 0x00000169UL);
#define CAN0RXDSR5                      _CAN0RXDSR5.Byte
#define CAN0RXDSR5_DB0                  _CAN0RXDSR5.Bits.DB0
#define CAN0RXDSR5_DB1                  _CAN0RXDSR5.Bits.DB1
#define CAN0RXDSR5_DB2                  _CAN0RXDSR5.Bits.DB2
#define CAN0RXDSR5_DB3                  _CAN0RXDSR5.Bits.DB3
#define CAN0RXDSR5_DB4                  _CAN0RXDSR5.Bits.DB4
#define CAN0RXDSR5_DB5                  _CAN0RXDSR5.Bits.DB5
#define CAN0RXDSR5_DB6                  _CAN0RXDSR5.Bits.DB6
#define CAN0RXDSR5_DB7                  _CAN0RXDSR5.Bits.DB7

#define CAN0RXDSR5_DB0_MASK             1U
#define CAN0RXDSR5_DB1_MASK             2U
#define CAN0RXDSR5_DB2_MASK             4U
#define CAN0RXDSR5_DB3_MASK             8U
#define CAN0RXDSR5_DB4_MASK             16U
#define CAN0RXDSR5_DB5_MASK             32U
#define CAN0RXDSR5_DB6_MASK             64U
#define CAN0RXDSR5_DB7_MASK             128U


/*** CAN0RXDSR6 - MSCAN0 Receive Data Segment Register 6; 0x0000016A ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CAN0RXDSR6STR;
extern volatile CAN0RXDSR6STR _CAN0RXDSR6 @(REG_BASE + 0x0000016AUL);
#define CAN0RXDSR6                      _CAN0RXDSR6.Byte
#define CAN0RXDSR6_DB0                  _CAN0RXDSR6.Bits.DB0
#define CAN0RXDSR6_DB1                  _CAN0RXDSR6.Bits.DB1
#define CAN0RXDSR6_DB2                  _CAN0RXDSR6.Bits.DB2
#define CAN0RXDSR6_DB3                  _CAN0RXDSR6.Bits.DB3
#define CAN0RXDSR6_DB4                  _CAN0RXDSR6.Bits.DB4
#define CAN0RXDSR6_DB5                  _CAN0RXDSR6.Bits.DB5
#define CAN0RXDSR6_DB6                  _CAN0RXDSR6.Bits.DB6
#define CAN0RXDSR6_DB7                  _CAN0RXDSR6.Bits.DB7

#define CAN0RXDSR6_DB0_MASK             1U
#define CAN0RXDSR6_DB1_MASK             2U
#define CAN0RXDSR6_DB2_MASK             4U
#define CAN0RXDSR6_DB3_MASK             8U
#define CAN0RXDSR6_DB4_MASK             16U
#define CAN0RXDSR6_DB5_MASK             32U
#define CAN0RXDSR6_DB6_MASK             64U
#define CAN0RXDSR6_DB7_MASK             128U


/*** CAN0RXDSR7 - MSCAN0 Receive Data Segment Register 7; 0x0000016B ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CAN0RXDSR7STR;
extern volatile CAN0RXDSR7STR _CAN0RXDSR7 @(REG_BASE + 0x0000016BUL);
#define CAN0RXDSR7                      _CAN0RXDSR7.Byte
#define CAN0RXDSR7_DB0                  _CAN0RXDSR7.Bits.DB0
#define CAN0RXDSR7_DB1                  _CAN0RXDSR7.Bits.DB1
#define CAN0RXDSR7_DB2                  _CAN0RXDSR7.Bits.DB2
#define CAN0RXDSR7_DB3                  _CAN0RXDSR7.Bits.DB3
#define CAN0RXDSR7_DB4                  _CAN0RXDSR7.Bits.DB4
#define CAN0RXDSR7_DB5                  _CAN0RXDSR7.Bits.DB5
#define CAN0RXDSR7_DB6                  _CAN0RXDSR7.Bits.DB6
#define CAN0RXDSR7_DB7                  _CAN0RXDSR7.Bits.DB7

#define CAN0RXDSR7_DB0_MASK             1U
#define CAN0RXDSR7_DB1_MASK             2U
#define CAN0RXDSR7_DB2_MASK             4U
#define CAN0RXDSR7_DB3_MASK             8U
#define CAN0RXDSR7_DB4_MASK             16U
#define CAN0RXDSR7_DB5_MASK             32U
#define CAN0RXDSR7_DB6_MASK             64U
#define CAN0RXDSR7_DB7_MASK             128U


/*** CAN0RXDLR - MSCAN0 Receive Data Length Register; 0x0000016C ***/
typedef union {
  byte Byte;
  struct {
    byte DLC0        :1;                                       /* Data Length Code Bit 0 */
    byte DLC1        :1;                                       /* Data Length Code Bit 1 */
    byte DLC2        :1;                                       /* Data Length Code Bit 2 */
    byte DLC3        :1;                                       /* Data Length Code Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDLC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CAN0RXDLRSTR;
extern volatile CAN0RXDLRSTR _CAN0RXDLR @(REG_BASE + 0x0000016CUL);
#define CAN0RXDLR                       _CAN0RXDLR.Byte
#define CAN0RXDLR_DLC0                  _CAN0RXDLR.Bits.DLC0
#define CAN0RXDLR_DLC1                  _CAN0RXDLR.Bits.DLC1
#define CAN0RXDLR_DLC2                  _CAN0RXDLR.Bits.DLC2
#define CAN0RXDLR_DLC3                  _CAN0RXDLR.Bits.DLC3
#define CAN0RXDLR_DLC                   _CAN0RXDLR.MergedBits.grpDLC

#define CAN0RXDLR_DLC0_MASK             1U
#define CAN0RXDLR_DLC1_MASK             2U
#define CAN0RXDLR_DLC2_MASK             4U
#define CAN0RXDLR_DLC3_MASK             8U
#define CAN0RXDLR_DLC_MASK              15U
#define CAN0RXDLR_DLC_BITNUM            0U


/*** CAN0RXTSR - MSCAN0 Receive Time Stamp Register; 0x0000016E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CAN0RXTSRH - MSCAN0 Receive Time Stamp Register High; 0x0000016E ***/
    union {
      byte Byte;
      struct {
        byte TSR8        :1;                                       /* Time Stamp Bit 8 */
        byte TSR9        :1;                                       /* Time Stamp Bit 9 */
        byte TSR10       :1;                                       /* Time Stamp Bit 10 */
        byte TSR11       :1;                                       /* Time Stamp Bit 11 */
        byte TSR12       :1;                                       /* Time Stamp Bit 12 */
        byte TSR13       :1;                                       /* Time Stamp Bit 13 */
        byte TSR14       :1;                                       /* Time Stamp Bit 14 */
        byte TSR15       :1;                                       /* Time Stamp Bit 15 */
      } Bits;
    } CAN0RXTSRHSTR;
    #define CAN0RXTSRH                  _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Byte
    #define CAN0RXTSRH_TSR8             _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR8
    #define CAN0RXTSRH_TSR9             _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR9
    #define CAN0RXTSRH_TSR10            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR10
    #define CAN0RXTSRH_TSR11            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR11
    #define CAN0RXTSRH_TSR12            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR12
    #define CAN0RXTSRH_TSR13            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR13
    #define CAN0RXTSRH_TSR14            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR14
    #define CAN0RXTSRH_TSR15            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR15
    
    #define CAN0RXTSRH_TSR8_MASK        1U
    #define CAN0RXTSRH_TSR9_MASK        2U
    #define CAN0RXTSRH_TSR10_MASK       4U
    #define CAN0RXTSRH_TSR11_MASK       8U
    #define CAN0RXTSRH_TSR12_MASK       16U
    #define CAN0RXTSRH_TSR13_MASK       32U
    #define CAN0RXTSRH_TSR14_MASK       64U
    #define CAN0RXTSRH_TSR15_MASK       128U
    

    /*** CAN0RXTSRL - MSCAN0 Receive Time Stamp Register Low; 0x0000016F ***/
    union {
      byte Byte;
      struct {
        byte TSR0        :1;                                       /* Time Stamp Bit 0 */
        byte TSR1        :1;                                       /* Time Stamp Bit 1 */
        byte TSR2        :1;                                       /* Time Stamp Bit 2 */
        byte TSR3        :1;                                       /* Time Stamp Bit 3 */
        byte TSR4        :1;                                       /* Time Stamp Bit 4 */
        byte TSR5        :1;                                       /* Time Stamp Bit 5 */
        byte TSR6        :1;                                       /* Time Stamp Bit 6 */
        byte TSR7        :1;                                       /* Time Stamp Bit 7 */
      } Bits;
    } CAN0RXTSRLSTR;
    #define CAN0RXTSRL                  _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Byte
    #define CAN0RXTSRL_TSR0             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR0
    #define CAN0RXTSRL_TSR1             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR1
    #define CAN0RXTSRL_TSR2             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR2
    #define CAN0RXTSRL_TSR3             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR3
    #define CAN0RXTSRL_TSR4             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR4
    #define CAN0RXTSRL_TSR5             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR5
    #define CAN0RXTSRL_TSR6             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR6
    #define CAN0RXTSRL_TSR7             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR7
    
    #define CAN0RXTSRL_TSR0_MASK        1U
    #define CAN0RXTSRL_TSR1_MASK        2U
    #define CAN0RXTSRL_TSR2_MASK        4U
    #define CAN0RXTSRL_TSR3_MASK        8U
    #define CAN0RXTSRL_TSR4_MASK        16U
    #define CAN0RXTSRL_TSR5_MASK        32U
    #define CAN0RXTSRL_TSR6_MASK        64U
    #define CAN0RXTSRL_TSR7_MASK        128U
    
  } Overlap_STR;

  struct {
    word TSR0        :1;                                       /* Time Stamp Bit 0 */
    word TSR1        :1;                                       /* Time Stamp Bit 1 */
    word TSR2        :1;                                       /* Time Stamp Bit 2 */
    word TSR3        :1;                                       /* Time Stamp Bit 3 */
    word TSR4        :1;                                       /* Time Stamp Bit 4 */
    word TSR5        :1;                                       /* Time Stamp Bit 5 */
    word TSR6        :1;                                       /* Time Stamp Bit 6 */
    word TSR7        :1;                                       /* Time Stamp Bit 7 */
    word TSR8        :1;                                       /* Time Stamp Bit 8 */
    word TSR9        :1;                                       /* Time Stamp Bit 9 */
    word TSR10       :1;                                       /* Time Stamp Bit 10 */
    word TSR11       :1;                                       /* Time Stamp Bit 11 */
    word TSR12       :1;                                       /* Time Stamp Bit 12 */
    word TSR13       :1;                                       /* Time Stamp Bit 13 */
    word TSR14       :1;                                       /* Time Stamp Bit 14 */
    word TSR15       :1;                                       /* Time Stamp Bit 15 */
  } Bits;
} CAN0RXTSRSTR;
extern volatile CAN0RXTSRSTR _CAN0RXTSR @(REG_BASE + 0x0000016EUL);
#define CAN0RXTSR                       _CAN0RXTSR.Word
#define CAN0RXTSR_TSR0                  _CAN0RXTSR.Bits.TSR0
#define CAN0RXTSR_TSR1                  _CAN0RXTSR.Bits.TSR1
#define CAN0RXTSR_TSR2                  _CAN0RXTSR.Bits.TSR2
#define CAN0RXTSR_TSR3                  _CAN0RXTSR.Bits.TSR3
#define CAN0RXTSR_TSR4                  _CAN0RXTSR.Bits.TSR4
#define CAN0RXTSR_TSR5                  _CAN0RXTSR.Bits.TSR5
#define CAN0RXTSR_TSR6                  _CAN0RXTSR.Bits.TSR6
#define CAN0RXTSR_TSR7                  _CAN0RXTSR.Bits.TSR7
#define CAN0RXTSR_TSR8                  _CAN0RXTSR.Bits.TSR8
#define CAN0RXTSR_TSR9                  _CAN0RXTSR.Bits.TSR9
#define CAN0RXTSR_TSR10                 _CAN0RXTSR.Bits.TSR10
#define CAN0RXTSR_TSR11                 _CAN0RXTSR.Bits.TSR11
#define CAN0RXTSR_TSR12                 _CAN0RXTSR.Bits.TSR12
#define CAN0RXTSR_TSR13                 _CAN0RXTSR.Bits.TSR13
#define CAN0RXTSR_TSR14                 _CAN0RXTSR.Bits.TSR14
#define CAN0RXTSR_TSR15                 _CAN0RXTSR.Bits.TSR15

#define CAN0RXTSR_TSR0_MASK             1U
#define CAN0RXTSR_TSR1_MASK             2U
#define CAN0RXTSR_TSR2_MASK             4U
#define CAN0RXTSR_TSR3_MASK             8U
#define CAN0RXTSR_TSR4_MASK             16U
#define CAN0RXTSR_TSR5_MASK             32U
#define CAN0RXTSR_TSR6_MASK             64U
#define CAN0RXTSR_TSR7_MASK             128U
#define CAN0RXTSR_TSR8_MASK             256U
#define CAN0RXTSR_TSR9_MASK             512U
#define CAN0RXTSR_TSR10_MASK            1024U
#define CAN0RXTSR_TSR11_MASK            2048U
#define CAN0RXTSR_TSR12_MASK            4096U
#define CAN0RXTSR_TSR13_MASK            8192U
#define CAN0RXTSR_TSR14_MASK            16384U
#define CAN0RXTSR_TSR15_MASK            32768U


/*** CAN0TXIDR0 - MSCAN0 Transmit Identifier Register 0; 0x00000170 ***/
typedef union {
  byte Byte;
  struct {
    byte ID21        :1;                                       /* Extended format identifier Bit 21 */
    byte ID22        :1;                                       /* Extended format identifier Bit 22 */
    byte ID23        :1;                                       /* Extended format identifier Bit 23 */
    byte ID24        :1;                                       /* Extended format identifier Bit 24 */
    byte ID25        :1;                                       /* Extended format identifier Bit 25 */
    byte ID26        :1;                                       /* Extended format identifier Bit 26 */
    byte ID27        :1;                                       /* Extended format identifier Bit 27 */
    byte ID28        :1;                                       /* Extended format identifier Bit 28 */
  } Bits;
} CAN0TXIDR0STR;
extern volatile CAN0TXIDR0STR _CAN0TXIDR0 @(REG_BASE + 0x00000170UL);
#define CAN0TXIDR0                      _CAN0TXIDR0.Byte
#define CAN0TXIDR0_ID21                 _CAN0TXIDR0.Bits.ID21
#define CAN0TXIDR0_ID22                 _CAN0TXIDR0.Bits.ID22
#define CAN0TXIDR0_ID23                 _CAN0TXIDR0.Bits.ID23
#define CAN0TXIDR0_ID24                 _CAN0TXIDR0.Bits.ID24
#define CAN0TXIDR0_ID25                 _CAN0TXIDR0.Bits.ID25
#define CAN0TXIDR0_ID26                 _CAN0TXIDR0.Bits.ID26
#define CAN0TXIDR0_ID27                 _CAN0TXIDR0.Bits.ID27
#define CAN0TXIDR0_ID28                 _CAN0TXIDR0.Bits.ID28
/* CAN0TXIDR_ARR: Access 4 CAN0TXIDRx registers in an array */
#define CAN0TXIDR_ARR                   ((volatile byte *) &CAN0TXIDR0)

#define CAN0TXIDR0_ID21_MASK            1U
#define CAN0TXIDR0_ID22_MASK            2U
#define CAN0TXIDR0_ID23_MASK            4U
#define CAN0TXIDR0_ID24_MASK            8U
#define CAN0TXIDR0_ID25_MASK            16U
#define CAN0TXIDR0_ID26_MASK            32U
#define CAN0TXIDR0_ID27_MASK            64U
#define CAN0TXIDR0_ID28_MASK            128U


/*** CAN0TXIDR1 - MSCAN0 Transmit Identifier Register 1; 0x00000171 ***/
typedef union {
  byte Byte;
  struct {
    byte ID15        :1;                                       /* Extended format identifier Bit 15 */
    byte ID16        :1;                                       /* Extended format identifier Bit 16 */
    byte ID17        :1;                                       /* Extended format identifier Bit 17 */
    byte IDE         :1;                                       /* ID Extended */
    byte SRR         :1;                                       /* Substitute Remote Request */
    byte ID18        :1;                                       /* Extended format identifier Bit 18 */
    byte ID19        :1;                                       /* Extended format identifier Bit 19 */
    byte ID20        :1;                                       /* Extended format identifier Bit 20 */
  } Bits;
  struct {
    byte grpID_15 :3;
    byte         :1;
    byte         :1;
    byte grpID_18 :3;
  } MergedBits;
} CAN0TXIDR1STR;
extern volatile CAN0TXIDR1STR _CAN0TXIDR1 @(REG_BASE + 0x00000171UL);
#define CAN0TXIDR1                      _CAN0TXIDR1.Byte
#define CAN0TXIDR1_ID15                 _CAN0TXIDR1.Bits.ID15
#define CAN0TXIDR1_ID16                 _CAN0TXIDR1.Bits.ID16
#define CAN0TXIDR1_ID17                 _CAN0TXIDR1.Bits.ID17
#define CAN0TXIDR1_IDE                  _CAN0TXIDR1.Bits.IDE
#define CAN0TXIDR1_SRR                  _CAN0TXIDR1.Bits.SRR
#define CAN0TXIDR1_ID18                 _CAN0TXIDR1.Bits.ID18
#define CAN0TXIDR1_ID19                 _CAN0TXIDR1.Bits.ID19
#define CAN0TXIDR1_ID20                 _CAN0TXIDR1.Bits.ID20
#define CAN0TXIDR1_ID_15                _CAN0TXIDR1.MergedBits.grpID_15
#define CAN0TXIDR1_ID_18                _CAN0TXIDR1.MergedBits.grpID_18
#define CAN0TXIDR1_ID                   CAN0TXIDR1_ID_15

#define CAN0TXIDR1_ID15_MASK            1U
#define CAN0TXIDR1_ID16_MASK            2U
#define CAN0TXIDR1_ID17_MASK            4U
#define CAN0TXIDR1_IDE_MASK             8U
#define CAN0TXIDR1_SRR_MASK             16U
#define CAN0TXIDR1_ID18_MASK            32U
#define CAN0TXIDR1_ID19_MASK            64U
#define CAN0TXIDR1_ID20_MASK            128U
#define CAN0TXIDR1_ID_15_MASK           7U
#define CAN0TXIDR1_ID_15_BITNUM         0U
#define CAN0TXIDR1_ID_18_MASK           224U
#define CAN0TXIDR1_ID_18_BITNUM         5U


/*** CAN0TXIDR2 - MSCAN0 Transmit Identifier Register 2; 0x00000172 ***/
typedef union {
  byte Byte;
  struct {
    byte ID7         :1;                                       /* Extended format identifier Bit 7 */
    byte ID8         :1;                                       /* Extended format identifier Bit 8 */
    byte ID9         :1;                                       /* Extended format identifier Bit 9 */
    byte ID10        :1;                                       /* Extended format identifier Bit 10 */
    byte ID11        :1;                                       /* Extended format identifier Bit 11 */
    byte ID12        :1;                                       /* Extended format identifier Bit 12 */
    byte ID13        :1;                                       /* Extended format identifier Bit 13 */
    byte ID14        :1;                                       /* Extended format identifier Bit 14 */
  } Bits;
} CAN0TXIDR2STR;
extern volatile CAN0TXIDR2STR _CAN0TXIDR2 @(REG_BASE + 0x00000172UL);
#define CAN0TXIDR2                      _CAN0TXIDR2.Byte
#define CAN0TXIDR2_ID7                  _CAN0TXIDR2.Bits.ID7
#define CAN0TXIDR2_ID8                  _CAN0TXIDR2.Bits.ID8
#define CAN0TXIDR2_ID9                  _CAN0TXIDR2.Bits.ID9
#define CAN0TXIDR2_ID10                 _CAN0TXIDR2.Bits.ID10
#define CAN0TXIDR2_ID11                 _CAN0TXIDR2.Bits.ID11
#define CAN0TXIDR2_ID12                 _CAN0TXIDR2.Bits.ID12
#define CAN0TXIDR2_ID13                 _CAN0TXIDR2.Bits.ID13
#define CAN0TXIDR2_ID14                 _CAN0TXIDR2.Bits.ID14

#define CAN0TXIDR2_ID7_MASK             1U
#define CAN0TXIDR2_ID8_MASK             2U
#define CAN0TXIDR2_ID9_MASK             4U
#define CAN0TXIDR2_ID10_MASK            8U
#define CAN0TXIDR2_ID11_MASK            16U
#define CAN0TXIDR2_ID12_MASK            32U
#define CAN0TXIDR2_ID13_MASK            64U
#define CAN0TXIDR2_ID14_MASK            128U


/*** CAN0TXIDR3 - MSCAN0 Transmit Identifier Register 3; 0x00000173 ***/
typedef union {
  byte Byte;
  struct {
    byte RTR         :1;                                       /* Remote Transmission Request */
    byte ID0         :1;                                       /* Extended format identifier Bit 0 */
    byte ID1         :1;                                       /* Extended format identifier Bit 1 */
    byte ID2         :1;                                       /* Extended format identifier Bit 2 */
    byte ID3         :1;                                       /* Extended format identifier Bit 3 */
    byte ID4         :1;                                       /* Extended format identifier Bit 4 */
    byte ID5         :1;                                       /* Extended format identifier Bit 5 */
    byte ID6         :1;                                       /* Extended format identifier Bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpID   :7;
  } MergedBits;
} CAN0TXIDR3STR;
extern volatile CAN0TXIDR3STR _CAN0TXIDR3 @(REG_BASE + 0x00000173UL);
#define CAN0TXIDR3                      _CAN0TXIDR3.Byte
#define CAN0TXIDR3_RTR                  _CAN0TXIDR3.Bits.RTR
#define CAN0TXIDR3_ID0                  _CAN0TXIDR3.Bits.ID0
#define CAN0TXIDR3_ID1                  _CAN0TXIDR3.Bits.ID1
#define CAN0TXIDR3_ID2                  _CAN0TXIDR3.Bits.ID2
#define CAN0TXIDR3_ID3                  _CAN0TXIDR3.Bits.ID3
#define CAN0TXIDR3_ID4                  _CAN0TXIDR3.Bits.ID4
#define CAN0TXIDR3_ID5                  _CAN0TXIDR3.Bits.ID5
#define CAN0TXIDR3_ID6                  _CAN0TXIDR3.Bits.ID6
#define CAN0TXIDR3_ID                   _CAN0TXIDR3.MergedBits.grpID

#define CAN0TXIDR3_RTR_MASK             1U
#define CAN0TXIDR3_ID0_MASK             2U
#define CAN0TXIDR3_ID1_MASK             4U
#define CAN0TXIDR3_ID2_MASK             8U
#define CAN0TXIDR3_ID3_MASK             16U
#define CAN0TXIDR3_ID4_MASK             32U
#define CAN0TXIDR3_ID5_MASK             64U
#define CAN0TXIDR3_ID6_MASK             128U
#define CAN0TXIDR3_ID_MASK              254U
#define CAN0TXIDR3_ID_BITNUM            1U


/*** CAN0TXDSR0 - MSCAN0 Transmit Data Segment Register 0; 0x00000174 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CAN0TXDSR0STR;
extern volatile CAN0TXDSR0STR _CAN0TXDSR0 @(REG_BASE + 0x00000174UL);
#define CAN0TXDSR0                      _CAN0TXDSR0.Byte
#define CAN0TXDSR0_DB0                  _CAN0TXDSR0.Bits.DB0
#define CAN0TXDSR0_DB1                  _CAN0TXDSR0.Bits.DB1
#define CAN0TXDSR0_DB2                  _CAN0TXDSR0.Bits.DB2
#define CAN0TXDSR0_DB3                  _CAN0TXDSR0.Bits.DB3
#define CAN0TXDSR0_DB4                  _CAN0TXDSR0.Bits.DB4
#define CAN0TXDSR0_DB5                  _CAN0TXDSR0.Bits.DB5
#define CAN0TXDSR0_DB6                  _CAN0TXDSR0.Bits.DB6
#define CAN0TXDSR0_DB7                  _CAN0TXDSR0.Bits.DB7
/* CAN0TXDSR_ARR: Access 8 CAN0TXDSRx registers in an array */
#define CAN0TXDSR_ARR                   ((volatile byte *) &CAN0TXDSR0)

#define CAN0TXDSR0_DB0_MASK             1U
#define CAN0TXDSR0_DB1_MASK             2U
#define CAN0TXDSR0_DB2_MASK             4U
#define CAN0TXDSR0_DB3_MASK             8U
#define CAN0TXDSR0_DB4_MASK             16U
#define CAN0TXDSR0_DB5_MASK             32U
#define CAN0TXDSR0_DB6_MASK             64U
#define CAN0TXDSR0_DB7_MASK             128U


/*** CAN0TXDSR1 - MSCAN0 Transmit Data Segment Register 1; 0x00000175 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CAN0TXDSR1STR;
extern volatile CAN0TXDSR1STR _CAN0TXDSR1 @(REG_BASE + 0x00000175UL);
#define CAN0TXDSR1                      _CAN0TXDSR1.Byte
#define CAN0TXDSR1_DB0                  _CAN0TXDSR1.Bits.DB0
#define CAN0TXDSR1_DB1                  _CAN0TXDSR1.Bits.DB1
#define CAN0TXDSR1_DB2                  _CAN0TXDSR1.Bits.DB2
#define CAN0TXDSR1_DB3                  _CAN0TXDSR1.Bits.DB3
#define CAN0TXDSR1_DB4                  _CAN0TXDSR1.Bits.DB4
#define CAN0TXDSR1_DB5                  _CAN0TXDSR1.Bits.DB5
#define CAN0TXDSR1_DB6                  _CAN0TXDSR1.Bits.DB6
#define CAN0TXDSR1_DB7                  _CAN0TXDSR1.Bits.DB7

#define CAN0TXDSR1_DB0_MASK             1U
#define CAN0TXDSR1_DB1_MASK             2U
#define CAN0TXDSR1_DB2_MASK             4U
#define CAN0TXDSR1_DB3_MASK             8U
#define CAN0TXDSR1_DB4_MASK             16U
#define CAN0TXDSR1_DB5_MASK             32U
#define CAN0TXDSR1_DB6_MASK             64U
#define CAN0TXDSR1_DB7_MASK             128U


/*** CAN0TXDSR2 - MSCAN0 Transmit Data Segment Register 2; 0x00000176 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CAN0TXDSR2STR;
extern volatile CAN0TXDSR2STR _CAN0TXDSR2 @(REG_BASE + 0x00000176UL);
#define CAN0TXDSR2                      _CAN0TXDSR2.Byte
#define CAN0TXDSR2_DB0                  _CAN0TXDSR2.Bits.DB0
#define CAN0TXDSR2_DB1                  _CAN0TXDSR2.Bits.DB1
#define CAN0TXDSR2_DB2                  _CAN0TXDSR2.Bits.DB2
#define CAN0TXDSR2_DB3                  _CAN0TXDSR2.Bits.DB3
#define CAN0TXDSR2_DB4                  _CAN0TXDSR2.Bits.DB4
#define CAN0TXDSR2_DB5                  _CAN0TXDSR2.Bits.DB5
#define CAN0TXDSR2_DB6                  _CAN0TXDSR2.Bits.DB6
#define CAN0TXDSR2_DB7                  _CAN0TXDSR2.Bits.DB7

#define CAN0TXDSR2_DB0_MASK             1U
#define CAN0TXDSR2_DB1_MASK             2U
#define CAN0TXDSR2_DB2_MASK             4U
#define CAN0TXDSR2_DB3_MASK             8U
#define CAN0TXDSR2_DB4_MASK             16U
#define CAN0TXDSR2_DB5_MASK             32U
#define CAN0TXDSR2_DB6_MASK             64U
#define CAN0TXDSR2_DB7_MASK             128U


/*** CAN0TXDSR3 - MSCAN0 Transmit Data Segment Register 3; 0x00000177 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CAN0TXDSR3STR;
extern volatile CAN0TXDSR3STR _CAN0TXDSR3 @(REG_BASE + 0x00000177UL);
#define CAN0TXDSR3                      _CAN0TXDSR3.Byte
#define CAN0TXDSR3_DB0                  _CAN0TXDSR3.Bits.DB0
#define CAN0TXDSR3_DB1                  _CAN0TXDSR3.Bits.DB1
#define CAN0TXDSR3_DB2                  _CAN0TXDSR3.Bits.DB2
#define CAN0TXDSR3_DB3                  _CAN0TXDSR3.Bits.DB3
#define CAN0TXDSR3_DB4                  _CAN0TXDSR3.Bits.DB4
#define CAN0TXDSR3_DB5                  _CAN0TXDSR3.Bits.DB5
#define CAN0TXDSR3_DB6                  _CAN0TXDSR3.Bits.DB6
#define CAN0TXDSR3_DB7                  _CAN0TXDSR3.Bits.DB7

#define CAN0TXDSR3_DB0_MASK             1U
#define CAN0TXDSR3_DB1_MASK             2U
#define CAN0TXDSR3_DB2_MASK             4U
#define CAN0TXDSR3_DB3_MASK             8U
#define CAN0TXDSR3_DB4_MASK             16U
#define CAN0TXDSR3_DB5_MASK             32U
#define CAN0TXDSR3_DB6_MASK             64U
#define CAN0TXDSR3_DB7_MASK             128U


/*** CAN0TXDSR4 - MSCAN0 Transmit Data Segment Register 4; 0x00000178 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CAN0TXDSR4STR;
extern volatile CAN0TXDSR4STR _CAN0TXDSR4 @(REG_BASE + 0x00000178UL);
#define CAN0TXDSR4                      _CAN0TXDSR4.Byte
#define CAN0TXDSR4_DB0                  _CAN0TXDSR4.Bits.DB0
#define CAN0TXDSR4_DB1                  _CAN0TXDSR4.Bits.DB1
#define CAN0TXDSR4_DB2                  _CAN0TXDSR4.Bits.DB2
#define CAN0TXDSR4_DB3                  _CAN0TXDSR4.Bits.DB3
#define CAN0TXDSR4_DB4                  _CAN0TXDSR4.Bits.DB4
#define CAN0TXDSR4_DB5                  _CAN0TXDSR4.Bits.DB5
#define CAN0TXDSR4_DB6                  _CAN0TXDSR4.Bits.DB6
#define CAN0TXDSR4_DB7                  _CAN0TXDSR4.Bits.DB7

#define CAN0TXDSR4_DB0_MASK             1U
#define CAN0TXDSR4_DB1_MASK             2U
#define CAN0TXDSR4_DB2_MASK             4U
#define CAN0TXDSR4_DB3_MASK             8U
#define CAN0TXDSR4_DB4_MASK             16U
#define CAN0TXDSR4_DB5_MASK             32U
#define CAN0TXDSR4_DB6_MASK             64U
#define CAN0TXDSR4_DB7_MASK             128U


/*** CAN0TXDSR5 - MSCAN0 Transmit Data Segment Register 5; 0x00000179 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CAN0TXDSR5STR;
extern volatile CAN0TXDSR5STR _CAN0TXDSR5 @(REG_BASE + 0x00000179UL);
#define CAN0TXDSR5                      _CAN0TXDSR5.Byte
#define CAN0TXDSR5_DB0                  _CAN0TXDSR5.Bits.DB0
#define CAN0TXDSR5_DB1                  _CAN0TXDSR5.Bits.DB1
#define CAN0TXDSR5_DB2                  _CAN0TXDSR5.Bits.DB2
#define CAN0TXDSR5_DB3                  _CAN0TXDSR5.Bits.DB3
#define CAN0TXDSR5_DB4                  _CAN0TXDSR5.Bits.DB4
#define CAN0TXDSR5_DB5                  _CAN0TXDSR5.Bits.DB5
#define CAN0TXDSR5_DB6                  _CAN0TXDSR5.Bits.DB6
#define CAN0TXDSR5_DB7                  _CAN0TXDSR5.Bits.DB7

#define CAN0TXDSR5_DB0_MASK             1U
#define CAN0TXDSR5_DB1_MASK             2U
#define CAN0TXDSR5_DB2_MASK             4U
#define CAN0TXDSR5_DB3_MASK             8U
#define CAN0TXDSR5_DB4_MASK             16U
#define CAN0TXDSR5_DB5_MASK             32U
#define CAN0TXDSR5_DB6_MASK             64U
#define CAN0TXDSR5_DB7_MASK             128U


/*** CAN0TXDSR6 - MSCAN0 Transmit Data Segment Register 6; 0x0000017A ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CAN0TXDSR6STR;
extern volatile CAN0TXDSR6STR _CAN0TXDSR6 @(REG_BASE + 0x0000017AUL);
#define CAN0TXDSR6                      _CAN0TXDSR6.Byte
#define CAN0TXDSR6_DB0                  _CAN0TXDSR6.Bits.DB0
#define CAN0TXDSR6_DB1                  _CAN0TXDSR6.Bits.DB1
#define CAN0TXDSR6_DB2                  _CAN0TXDSR6.Bits.DB2
#define CAN0TXDSR6_DB3                  _CAN0TXDSR6.Bits.DB3
#define CAN0TXDSR6_DB4                  _CAN0TXDSR6.Bits.DB4
#define CAN0TXDSR6_DB5                  _CAN0TXDSR6.Bits.DB5
#define CAN0TXDSR6_DB6                  _CAN0TXDSR6.Bits.DB6
#define CAN0TXDSR6_DB7                  _CAN0TXDSR6.Bits.DB7

#define CAN0TXDSR6_DB0_MASK             1U
#define CAN0TXDSR6_DB1_MASK             2U
#define CAN0TXDSR6_DB2_MASK             4U
#define CAN0TXDSR6_DB3_MASK             8U
#define CAN0TXDSR6_DB4_MASK             16U
#define CAN0TXDSR6_DB5_MASK             32U
#define CAN0TXDSR6_DB6_MASK             64U
#define CAN0TXDSR6_DB7_MASK             128U


/*** CAN0TXDSR7 - MSCAN0 Transmit Data Segment Register 7; 0x0000017B ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CAN0TXDSR7STR;
extern volatile CAN0TXDSR7STR _CAN0TXDSR7 @(REG_BASE + 0x0000017BUL);
#define CAN0TXDSR7                      _CAN0TXDSR7.Byte
#define CAN0TXDSR7_DB0                  _CAN0TXDSR7.Bits.DB0
#define CAN0TXDSR7_DB1                  _CAN0TXDSR7.Bits.DB1
#define CAN0TXDSR7_DB2                  _CAN0TXDSR7.Bits.DB2
#define CAN0TXDSR7_DB3                  _CAN0TXDSR7.Bits.DB3
#define CAN0TXDSR7_DB4                  _CAN0TXDSR7.Bits.DB4
#define CAN0TXDSR7_DB5                  _CAN0TXDSR7.Bits.DB5
#define CAN0TXDSR7_DB6                  _CAN0TXDSR7.Bits.DB6
#define CAN0TXDSR7_DB7                  _CAN0TXDSR7.Bits.DB7

#define CAN0TXDSR7_DB0_MASK             1U
#define CAN0TXDSR7_DB1_MASK             2U
#define CAN0TXDSR7_DB2_MASK             4U
#define CAN0TXDSR7_DB3_MASK             8U
#define CAN0TXDSR7_DB4_MASK             16U
#define CAN0TXDSR7_DB5_MASK             32U
#define CAN0TXDSR7_DB6_MASK             64U
#define CAN0TXDSR7_DB7_MASK             128U


/*** CAN0TXDLR - MSCAN0 Transmit Data Length Register; 0x0000017C ***/
typedef union {
  byte Byte;
  struct {
    byte DLC0        :1;                                       /* Data Length Code Bit 0 */
    byte DLC1        :1;                                       /* Data Length Code Bit 1 */
    byte DLC2        :1;                                       /* Data Length Code Bit 2 */
    byte DLC3        :1;                                       /* Data Length Code Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDLC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CAN0TXDLRSTR;
extern volatile CAN0TXDLRSTR _CAN0TXDLR @(REG_BASE + 0x0000017CUL);
#define CAN0TXDLR                       _CAN0TXDLR.Byte
#define CAN0TXDLR_DLC0                  _CAN0TXDLR.Bits.DLC0
#define CAN0TXDLR_DLC1                  _CAN0TXDLR.Bits.DLC1
#define CAN0TXDLR_DLC2                  _CAN0TXDLR.Bits.DLC2
#define CAN0TXDLR_DLC3                  _CAN0TXDLR.Bits.DLC3
#define CAN0TXDLR_DLC                   _CAN0TXDLR.MergedBits.grpDLC

#define CAN0TXDLR_DLC0_MASK             1U
#define CAN0TXDLR_DLC1_MASK             2U
#define CAN0TXDLR_DLC2_MASK             4U
#define CAN0TXDLR_DLC3_MASK             8U
#define CAN0TXDLR_DLC_MASK              15U
#define CAN0TXDLR_DLC_BITNUM            0U


/*** CAN0TXTBPR - MSCAN0 Transmit Buffer Priority; 0x0000017D ***/
typedef union {
  byte Byte;
  struct {
    byte PRIO0       :1;                                       /* Transmit Buffer Priority Bit 0 */
    byte PRIO1       :1;                                       /* Transmit Buffer Priority Bit 1 */
    byte PRIO2       :1;                                       /* Transmit Buffer Priority Bit 2 */
    byte PRIO3       :1;                                       /* Transmit Buffer Priority Bit 3 */
    byte PRIO4       :1;                                       /* Transmit Buffer Priority Bit 4 */
    byte PRIO5       :1;                                       /* Transmit Buffer Priority Bit 5 */
    byte PRIO6       :1;                                       /* Transmit Buffer Priority Bit 6 */
    byte PRIO7       :1;                                       /* Transmit Buffer Priority Bit 7 */
  } Bits;
} CAN0TXTBPRSTR;
extern volatile CAN0TXTBPRSTR _CAN0TXTBPR @(REG_BASE + 0x0000017DUL);
#define CAN0TXTBPR                      _CAN0TXTBPR.Byte
#define CAN0TXTBPR_PRIO0                _CAN0TXTBPR.Bits.PRIO0
#define CAN0TXTBPR_PRIO1                _CAN0TXTBPR.Bits.PRIO1
#define CAN0TXTBPR_PRIO2                _CAN0TXTBPR.Bits.PRIO2
#define CAN0TXTBPR_PRIO3                _CAN0TXTBPR.Bits.PRIO3
#define CAN0TXTBPR_PRIO4                _CAN0TXTBPR.Bits.PRIO4
#define CAN0TXTBPR_PRIO5                _CAN0TXTBPR.Bits.PRIO5
#define CAN0TXTBPR_PRIO6                _CAN0TXTBPR.Bits.PRIO6
#define CAN0TXTBPR_PRIO7                _CAN0TXTBPR.Bits.PRIO7

#define CAN0TXTBPR_PRIO0_MASK           1U
#define CAN0TXTBPR_PRIO1_MASK           2U
#define CAN0TXTBPR_PRIO2_MASK           4U
#define CAN0TXTBPR_PRIO3_MASK           8U
#define CAN0TXTBPR_PRIO4_MASK           16U
#define CAN0TXTBPR_PRIO5_MASK           32U
#define CAN0TXTBPR_PRIO6_MASK           64U
#define CAN0TXTBPR_PRIO7_MASK           128U


/*** CAN0TXTSR - MSCAN0 Transmit Time Stamp Register; 0x0000017E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CAN0TXTSRH - MSCAN0 Transmit Time Stamp Register High; 0x0000017E ***/
    union {
      byte Byte;
      struct {
        byte TSR8        :1;                                       /* Time Stamp Bit 8 */
        byte TSR9        :1;                                       /* Time Stamp Bit 9 */
        byte TSR10       :1;                                       /* Time Stamp Bit 10 */
        byte TSR11       :1;                                       /* Time Stamp Bit 11 */
        byte TSR12       :1;                                       /* Time Stamp Bit 12 */
        byte TSR13       :1;                                       /* Time Stamp Bit 13 */
        byte TSR14       :1;                                       /* Time Stamp Bit 14 */
        byte TSR15       :1;                                       /* Time Stamp Bit 15 */
      } Bits;
    } CAN0TXTSRHSTR;
    #define CAN0TXTSRH                  _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Byte
    #define CAN0TXTSRH_TSR8             _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR8
    #define CAN0TXTSRH_TSR9             _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR9
    #define CAN0TXTSRH_TSR10            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR10
    #define CAN0TXTSRH_TSR11            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR11
    #define CAN0TXTSRH_TSR12            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR12
    #define CAN0TXTSRH_TSR13            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR13
    #define CAN0TXTSRH_TSR14            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR14
    #define CAN0TXTSRH_TSR15            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR15
    
    #define CAN0TXTSRH_TSR8_MASK        1U
    #define CAN0TXTSRH_TSR9_MASK        2U
    #define CAN0TXTSRH_TSR10_MASK       4U
    #define CAN0TXTSRH_TSR11_MASK       8U
    #define CAN0TXTSRH_TSR12_MASK       16U
    #define CAN0TXTSRH_TSR13_MASK       32U
    #define CAN0TXTSRH_TSR14_MASK       64U
    #define CAN0TXTSRH_TSR15_MASK       128U
    

    /*** CAN0TXTSRL - MSCAN0 Transmit Time Stamp Register Low; 0x0000017F ***/
    union {
      byte Byte;
      struct {
        byte TSR0        :1;                                       /* Time Stamp Bit 0 */
        byte TSR1        :1;                                       /* Time Stamp Bit 1 */
        byte TSR2        :1;                                       /* Time Stamp Bit 2 */
        byte TSR3        :1;                                       /* Time Stamp Bit 3 */
        byte TSR4        :1;                                       /* Time Stamp Bit 4 */
        byte TSR5        :1;                                       /* Time Stamp Bit 5 */
        byte TSR6        :1;                                       /* Time Stamp Bit 6 */
        byte TSR7        :1;                                       /* Time Stamp Bit 7 */
      } Bits;
    } CAN0TXTSRLSTR;
    #define CAN0TXTSRL                  _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Byte
    #define CAN0TXTSRL_TSR0             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR0
    #define CAN0TXTSRL_TSR1             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR1
    #define CAN0TXTSRL_TSR2             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR2
    #define CAN0TXTSRL_TSR3             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR3
    #define CAN0TXTSRL_TSR4             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR4
    #define CAN0TXTSRL_TSR5             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR5
    #define CAN0TXTSRL_TSR6             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR6
    #define CAN0TXTSRL_TSR7             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR7
    
    #define CAN0TXTSRL_TSR0_MASK        1U
    #define CAN0TXTSRL_TSR1_MASK        2U
    #define CAN0TXTSRL_TSR2_MASK        4U
    #define CAN0TXTSRL_TSR3_MASK        8U
    #define CAN0TXTSRL_TSR4_MASK        16U
    #define CAN0TXTSRL_TSR5_MASK        32U
    #define CAN0TXTSRL_TSR6_MASK        64U
    #define CAN0TXTSRL_TSR7_MASK        128U
    
  } Overlap_STR;

  struct {
    word TSR0        :1;                                       /* Time Stamp Bit 0 */
    word TSR1        :1;                                       /* Time Stamp Bit 1 */
    word TSR2        :1;                                       /* Time Stamp Bit 2 */
    word TSR3        :1;                                       /* Time Stamp Bit 3 */
    word TSR4        :1;                                       /* Time Stamp Bit 4 */
    word TSR5        :1;                                       /* Time Stamp Bit 5 */
    word TSR6        :1;                                       /* Time Stamp Bit 6 */
    word TSR7        :1;                                       /* Time Stamp Bit 7 */
    word TSR8        :1;                                       /* Time Stamp Bit 8 */
    word TSR9        :1;                                       /* Time Stamp Bit 9 */
    word TSR10       :1;                                       /* Time Stamp Bit 10 */
    word TSR11       :1;                                       /* Time Stamp Bit 11 */
    word TSR12       :1;                                       /* Time Stamp Bit 12 */
    word TSR13       :1;                                       /* Time Stamp Bit 13 */
    word TSR14       :1;                                       /* Time Stamp Bit 14 */
    word TSR15       :1;                                       /* Time Stamp Bit 15 */
  } Bits;
} CAN0TXTSRSTR;
extern volatile CAN0TXTSRSTR _CAN0TXTSR @(REG_BASE + 0x0000017EUL);
#define CAN0TXTSR                       _CAN0TXTSR.Word
#define CAN0TXTSR_TSR0                  _CAN0TXTSR.Bits.TSR0
#define CAN0TXTSR_TSR1                  _CAN0TXTSR.Bits.TSR1
#define CAN0TXTSR_TSR2                  _CAN0TXTSR.Bits.TSR2
#define CAN0TXTSR_TSR3                  _CAN0TXTSR.Bits.TSR3
#define CAN0TXTSR_TSR4                  _CAN0TXTSR.Bits.TSR4
#define CAN0TXTSR_TSR5                  _CAN0TXTSR.Bits.TSR5
#define CAN0TXTSR_TSR6                  _CAN0TXTSR.Bits.TSR6
#define CAN0TXTSR_TSR7                  _CAN0TXTSR.Bits.TSR7
#define CAN0TXTSR_TSR8                  _CAN0TXTSR.Bits.TSR8
#define CAN0TXTSR_TSR9                  _CAN0TXTSR.Bits.TSR9
#define CAN0TXTSR_TSR10                 _CAN0TXTSR.Bits.TSR10
#define CAN0TXTSR_TSR11                 _CAN0TXTSR.Bits.TSR11
#define CAN0TXTSR_TSR12                 _CAN0TXTSR.Bits.TSR12
#define CAN0TXTSR_TSR13                 _CAN0TXTSR.Bits.TSR13
#define CAN0TXTSR_TSR14                 _CAN0TXTSR.Bits.TSR14
#define CAN0TXTSR_TSR15                 _CAN0TXTSR.Bits.TSR15

#define CAN0TXTSR_TSR0_MASK             1U
#define CAN0TXTSR_TSR1_MASK             2U
#define CAN0TXTSR_TSR2_MASK             4U
#define CAN0TXTSR_TSR3_MASK             8U
#define CAN0TXTSR_TSR4_MASK             16U
#define CAN0TXTSR_TSR5_MASK             32U
#define CAN0TXTSR_TSR6_MASK             64U
#define CAN0TXTSR_TSR7_MASK             128U
#define CAN0TXTSR_TSR8_MASK             256U
#define CAN0TXTSR_TSR9_MASK             512U
#define CAN0TXTSR_TSR10_MASK            1024U
#define CAN0TXTSR_TSR11_MASK            2048U
#define CAN0TXTSR_TSR12_MASK            4096U
#define CAN0TXTSR_TSR13_MASK            8192U
#define CAN0TXTSR_TSR14_MASK            16384U
#define CAN0TXTSR_TSR15_MASK            32768U


/*** PTT - Port T Data Register; 0x00000240 ***/
typedef union {
  byte Byte;
  struct {
    byte PTT0        :1;                                       /* Port T general purpose input/output data bit 0 */
    byte PTT1        :1;                                       /* Port T general purpose input/output data bit 1 */
    byte PTT2        :1;                                       /* Port T general purpose input/output data bit 2 */
    byte PTT3        :1;                                       /* Port T general purpose input/output data bit 3 */
    byte PTT4        :1;                                       /* Port T general purpose input/output data bit 4 */
    byte PTT5        :1;                                       /* Port T general purpose input/output data bit 5 */
    byte PTT6        :1;                                       /* Port T general purpose input/output data bit 6 */
    byte PTT7        :1;                                       /* Port T general purpose input/output data bit 7 */
  } Bits;
} PTTSTR;
extern volatile PTTSTR _PTT @(REG_BASE + 0x00000240UL);
#define PTT                             _PTT.Byte
#define PTT_PTT0                        _PTT.Bits.PTT0
#define PTT_PTT1                        _PTT.Bits.PTT1
#define PTT_PTT2                        _PTT.Bits.PTT2
#define PTT_PTT3                        _PTT.Bits.PTT3
#define PTT_PTT4                        _PTT.Bits.PTT4
#define PTT_PTT5                        _PTT.Bits.PTT5
#define PTT_PTT6                        _PTT.Bits.PTT6
#define PTT_PTT7                        _PTT.Bits.PTT7

#define PTT_PTT0_MASK                   1U
#define PTT_PTT1_MASK                   2U
#define PTT_PTT2_MASK                   4U
#define PTT_PTT3_MASK                   8U
#define PTT_PTT4_MASK                   16U
#define PTT_PTT5_MASK                   32U
#define PTT_PTT6_MASK                   64U
#define PTT_PTT7_MASK                   128U


/*** PTIT - Port T Input Register; 0x00000241 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIT0       :1;                                       /* Port T input data bit 0 */
    byte PTIT1       :1;                                       /* Port T input data bit 1 */
    byte PTIT2       :1;                                       /* Port T input data bit 2 */
    byte PTIT3       :1;                                       /* Port T input data bit 3 */
    byte PTIT4       :1;                                       /* Port T input data bit 4 */
    byte PTIT5       :1;                                       /* Port T input data bit 5 */
    byte PTIT6       :1;                                       /* Port T input data bit 6 */
    byte PTIT7       :1;                                       /* Port T input data bit 7 */
  } Bits;
} PTITSTR;
extern volatile PTITSTR _PTIT @(REG_BASE + 0x00000241UL);
#define PTIT                            _PTIT.Byte
#define PTIT_PTIT0                      _PTIT.Bits.PTIT0
#define PTIT_PTIT1                      _PTIT.Bits.PTIT1
#define PTIT_PTIT2                      _PTIT.Bits.PTIT2
#define PTIT_PTIT3                      _PTIT.Bits.PTIT3
#define PTIT_PTIT4                      _PTIT.Bits.PTIT4
#define PTIT_PTIT5                      _PTIT.Bits.PTIT5
#define PTIT_PTIT6                      _PTIT.Bits.PTIT6
#define PTIT_PTIT7                      _PTIT.Bits.PTIT7

#define PTIT_PTIT0_MASK                 1U
#define PTIT_PTIT1_MASK                 2U
#define PTIT_PTIT2_MASK                 4U
#define PTIT_PTIT3_MASK                 8U
#define PTIT_PTIT4_MASK                 16U
#define PTIT_PTIT5_MASK                 32U
#define PTIT_PTIT6_MASK                 64U
#define PTIT_PTIT7_MASK                 128U


/*** DDRT - Port T Data Direction Register; 0x00000242 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRT0       :1;                                       /* Port T data direction bit 0 */
    byte DDRT1       :1;                                       /* Port T data direction bit 1 */
    byte DDRT2       :1;                                       /* Port T data direction bit 2 */
    byte DDRT3       :1;                                       /* Port T data direction bit 3 */
    byte DDRT4       :1;                                       /* Port T data direction bit 4 */
    byte DDRT5       :1;                                       /* Port T data direction bit 5 */
    byte DDRT6       :1;                                       /* Port T data direction bit 6 */
    byte DDRT7       :1;                                       /* Port T data direction bit 7 */
  } Bits;
} DDRTSTR;
extern volatile DDRTSTR _DDRT @(REG_BASE + 0x00000242UL);
#define DDRT                            _DDRT.Byte
#define DDRT_DDRT0                      _DDRT.Bits.DDRT0
#define DDRT_DDRT1                      _DDRT.Bits.DDRT1
#define DDRT_DDRT2                      _DDRT.Bits.DDRT2
#define DDRT_DDRT3                      _DDRT.Bits.DDRT3
#define DDRT_DDRT4                      _DDRT.Bits.DDRT4
#define DDRT_DDRT5                      _DDRT.Bits.DDRT5
#define DDRT_DDRT6                      _DDRT.Bits.DDRT6
#define DDRT_DDRT7                      _DDRT.Bits.DDRT7

#define DDRT_DDRT0_MASK                 1U
#define DDRT_DDRT1_MASK                 2U
#define DDRT_DDRT2_MASK                 4U
#define DDRT_DDRT3_MASK                 8U
#define DDRT_DDRT4_MASK                 16U
#define DDRT_DDRT5_MASK                 32U
#define DDRT_DDRT6_MASK                 64U
#define DDRT_DDRT7_MASK                 128U


/*** RDRT - Port T Reduced Drive Register; 0x00000243 ***/
typedef union {
  byte Byte;
  struct {
    byte RDRT0       :1;                                       /* Port T reduced drive bit 0 */
    byte RDRT1       :1;                                       /* Port T reduced drive bit 1 */
    byte RDRT2       :1;                                       /* Port T reduced drive bit 2 */
    byte RDRT3       :1;                                       /* Port T reduced drive bit 3 */
    byte RDRT4       :1;                                       /* Port T reduced drive bit 4 */
    byte RDRT5       :1;                                       /* Port T reduced drive bit 5 */
    byte RDRT6       :1;                                       /* Port T reduced drive bit 6 */
    byte RDRT7       :1;                                       /* Port T reduced drive bit 7 */
  } Bits;
} RDRTSTR;
extern volatile RDRTSTR _RDRT @(REG_BASE + 0x00000243UL);
#define RDRT                            _RDRT.Byte
#define RDRT_RDRT0                      _RDRT.Bits.RDRT0
#define RDRT_RDRT1                      _RDRT.Bits.RDRT1
#define RDRT_RDRT2                      _RDRT.Bits.RDRT2
#define RDRT_RDRT3                      _RDRT.Bits.RDRT3
#define RDRT_RDRT4                      _RDRT.Bits.RDRT4
#define RDRT_RDRT5                      _RDRT.Bits.RDRT5
#define RDRT_RDRT6                      _RDRT.Bits.RDRT6
#define RDRT_RDRT7                      _RDRT.Bits.RDRT7

#define RDRT_RDRT0_MASK                 1U
#define RDRT_RDRT1_MASK                 2U
#define RDRT_RDRT2_MASK                 4U
#define RDRT_RDRT3_MASK                 8U
#define RDRT_RDRT4_MASK                 16U
#define RDRT_RDRT5_MASK                 32U
#define RDRT_RDRT6_MASK                 64U
#define RDRT_RDRT7_MASK                 128U


/*** PERT - Port T Pull Device Enable Register; 0x00000244 ***/
typedef union {
  byte Byte;
  struct {
    byte PERT0       :1;                                       /* Port T pull device enable bit 0 */
    byte PERT1       :1;                                       /* Port T pull device enable bit 1 */
    byte PERT2       :1;                                       /* Port T pull device enable bit 2 */
    byte PERT3       :1;                                       /* Port T pull device enable bit 3 */
    byte PERT4       :1;                                       /* Port T pull device enable bit 4 */
    byte PERT5       :1;                                       /* Port T pull device enable bit 5 */
    byte PERT6       :1;                                       /* Port T pull device enable bit 6 */
    byte PERT7       :1;                                       /* Port T pull device enable bit 7 */
  } Bits;
} PERTSTR;
extern volatile PERTSTR _PERT @(REG_BASE + 0x00000244UL);
#define PERT                            _PERT.Byte
#define PERT_PERT0                      _PERT.Bits.PERT0
#define PERT_PERT1                      _PERT.Bits.PERT1
#define PERT_PERT2                      _PERT.Bits.PERT2
#define PERT_PERT3                      _PERT.Bits.PERT3
#define PERT_PERT4                      _PERT.Bits.PERT4
#define PERT_PERT5                      _PERT.Bits.PERT5
#define PERT_PERT6                      _PERT.Bits.PERT6
#define PERT_PERT7                      _PERT.Bits.PERT7

#define PERT_PERT0_MASK                 1U
#define PERT_PERT1_MASK                 2U
#define PERT_PERT2_MASK                 4U
#define PERT_PERT3_MASK                 8U
#define PERT_PERT4_MASK                 16U
#define PERT_PERT5_MASK                 32U
#define PERT_PERT6_MASK                 64U
#define PERT_PERT7_MASK                 128U


/*** PPST - Port T Polarity Select Register; 0x00000245 ***/
typedef union {
  byte Byte;
  struct {
    byte PPST0       :1;                                       /* Port T pull device select bit 0 */
    byte PPST1       :1;                                       /* Port T pull device select bit 1 */
    byte PPST2       :1;                                       /* Port T pull device select bit 2 */
    byte PPST3       :1;                                       /* Port T pull device select bit 3 */
    byte PPST4       :1;                                       /* Port T pull device select bit 4 */
    byte PPST5       :1;                                       /* Port T pull device select bit 5 */
    byte PPST6       :1;                                       /* Port T pull device select bit 6 */
    byte PPST7       :1;                                       /* Port T pull device select bit 7 */
  } Bits;
} PPSTSTR;
extern volatile PPSTSTR _PPST @(REG_BASE + 0x00000245UL);
#define PPST                            _PPST.Byte
#define PPST_PPST0                      _PPST.Bits.PPST0
#define PPST_PPST1                      _PPST.Bits.PPST1
#define PPST_PPST2                      _PPST.Bits.PPST2
#define PPST_PPST3                      _PPST.Bits.PPST3
#define PPST_PPST4                      _PPST.Bits.PPST4
#define PPST_PPST5                      _PPST.Bits.PPST5
#define PPST_PPST6                      _PPST.Bits.PPST6
#define PPST_PPST7                      _PPST.Bits.PPST7

#define PPST_PPST0_MASK                 1U
#define PPST_PPST1_MASK                 2U
#define PPST_PPST2_MASK                 4U
#define PPST_PPST3_MASK                 8U
#define PPST_PPST4_MASK                 16U
#define PPST_PPST5_MASK                 32U
#define PPST_PPST6_MASK                 64U
#define PPST_PPST7_MASK                 128U


/*** PTTRR - Port T Routing Register; 0x00000247 ***/
typedef union {
  byte Byte;
  struct {
    byte PTTRR0      :1;                                       /* Port T  routing */
    byte PTTRR1      :1;                                       /* Port T  routing */
    byte PTTRR2      :1;                                       /* Port T  routing */
    byte             :1; 
    byte PTTRR4      :1;                                       /* Port T  routing */
    byte PTTRR5      :1;                                       /* Port T  routing */
    byte PTTRR6      :1;                                       /* Port T  routing */
    byte PTTRR7      :1;                                       /* Port T  routing */
  } Bits;
  struct {
    byte grpPTTRR :3;
    byte         :1;
    byte grpPTTRR_4 :4;
  } MergedBits;
} PTTRRSTR;
extern volatile PTTRRSTR _PTTRR @(REG_BASE + 0x00000247UL);
#define PTTRR                           _PTTRR.Byte
#define PTTRR_PTTRR0                    _PTTRR.Bits.PTTRR0
#define PTTRR_PTTRR1                    _PTTRR.Bits.PTTRR1
#define PTTRR_PTTRR2                    _PTTRR.Bits.PTTRR2
#define PTTRR_PTTRR4                    _PTTRR.Bits.PTTRR4
#define PTTRR_PTTRR5                    _PTTRR.Bits.PTTRR5
#define PTTRR_PTTRR6                    _PTTRR.Bits.PTTRR6
#define PTTRR_PTTRR7                    _PTTRR.Bits.PTTRR7
#define PTTRR_PTTRR                     _PTTRR.MergedBits.grpPTTRR
#define PTTRR_PTTRR_4                   _PTTRR.MergedBits.grpPTTRR_4

#define PTTRR_PTTRR0_MASK               1U
#define PTTRR_PTTRR1_MASK               2U
#define PTTRR_PTTRR2_MASK               4U
#define PTTRR_PTTRR4_MASK               16U
#define PTTRR_PTTRR5_MASK               32U
#define PTTRR_PTTRR6_MASK               64U
#define PTTRR_PTTRR7_MASK               128U
#define PTTRR_PTTRR_MASK                7U
#define PTTRR_PTTRR_BITNUM              0U
#define PTTRR_PTTRR_4_MASK              240U
#define PTTRR_PTTRR_4_BITNUM            4U


/*** PTS - Port S Data Register; 0x00000248 ***/
typedef union {
  byte Byte;
  struct {
    byte PTS0        :1;                                       /* Port S general purpose input/output data bit 0 */
    byte PTS1        :1;                                       /* Port S general purpose input/output data bit 1 */
    byte PTS2        :1;                                       /* Port S general purpose input/output data bit 2 */
    byte PTS3        :1;                                       /* Port S general purpose input/output data bit 3 */
    byte PTS4        :1;                                       /* Port S general purpose input/output data bit 4 */
    byte PTS5        :1;                                       /* Port S general purpose input/output data bit 5 */
    byte PTS6        :1;                                       /* Port S general purpose input/output data bit 6 */
    byte PTS7        :1;                                       /* Port S general purpose input/output data bit 7 */
  } Bits;
} PTSSTR;
extern volatile PTSSTR _PTS @(REG_BASE + 0x00000248UL);
#define PTS                             _PTS.Byte
#define PTS_PTS0                        _PTS.Bits.PTS0
#define PTS_PTS1                        _PTS.Bits.PTS1
#define PTS_PTS2                        _PTS.Bits.PTS2
#define PTS_PTS3                        _PTS.Bits.PTS3
#define PTS_PTS4                        _PTS.Bits.PTS4
#define PTS_PTS5                        _PTS.Bits.PTS5
#define PTS_PTS6                        _PTS.Bits.PTS6
#define PTS_PTS7                        _PTS.Bits.PTS7

#define PTS_PTS0_MASK                   1U
#define PTS_PTS1_MASK                   2U
#define PTS_PTS2_MASK                   4U
#define PTS_PTS3_MASK                   8U
#define PTS_PTS4_MASK                   16U
#define PTS_PTS5_MASK                   32U
#define PTS_PTS6_MASK                   64U
#define PTS_PTS7_MASK                   128U


/*** PTIS - Port S Input Register; 0x00000249 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIS0       :1;                                       /* Port S input data bit 0 */
    byte PTIS1       :1;                                       /* Port S input data bit 1 */
    byte PTIS2       :1;                                       /* Port S input data bit 2 */
    byte PTIS3       :1;                                       /* Port S input data bit 3 */
    byte PTIS4       :1;                                       /* Port S input data bit 4 */
    byte PTIS5       :1;                                       /* Port S input data bit 5 */
    byte PTIS6       :1;                                       /* Port S input data bit 6 */
    byte PTIS7       :1;                                       /* Port S input data bit 7 */
  } Bits;
} PTISSTR;
extern volatile PTISSTR _PTIS @(REG_BASE + 0x00000249UL);
#define PTIS                            _PTIS.Byte
#define PTIS_PTIS0                      _PTIS.Bits.PTIS0
#define PTIS_PTIS1                      _PTIS.Bits.PTIS1
#define PTIS_PTIS2                      _PTIS.Bits.PTIS2
#define PTIS_PTIS3                      _PTIS.Bits.PTIS3
#define PTIS_PTIS4                      _PTIS.Bits.PTIS4
#define PTIS_PTIS5                      _PTIS.Bits.PTIS5
#define PTIS_PTIS6                      _PTIS.Bits.PTIS6
#define PTIS_PTIS7                      _PTIS.Bits.PTIS7

#define PTIS_PTIS0_MASK                 1U
#define PTIS_PTIS1_MASK                 2U
#define PTIS_PTIS2_MASK                 4U
#define PTIS_PTIS3_MASK                 8U
#define PTIS_PTIS4_MASK                 16U
#define PTIS_PTIS5_MASK                 32U
#define PTIS_PTIS6_MASK                 64U
#define PTIS_PTIS7_MASK                 128U


/*** DDRS - Port S Data Direction Register; 0x0000024A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRS0       :1;                                       /* Port S data direction bit 0 */
    byte DDRS1       :1;                                       /* Port S data direction bit 1 */
    byte DDRS2       :1;                                       /* Port S data direction bit 2 */
    byte DDRS3       :1;                                       /* Port S data direction bit 3 */
    byte DDRS4       :1;                                       /* Port S data direction bit 4 */
    byte DDRS5       :1;                                       /* Port S data direction bit 5 */
    byte DDRS6       :1;                                       /* Port S data direction bit 6 */
    byte DDRS7       :1;                                       /* Port S data direction bit 7 */
  } Bits;
} DDRSSTR;
extern volatile DDRSSTR _DDRS @(REG_BASE + 0x0000024AUL);
#define DDRS                            _DDRS.Byte
#define DDRS_DDRS0                      _DDRS.Bits.DDRS0
#define DDRS_DDRS1                      _DDRS.Bits.DDRS1
#define DDRS_DDRS2                      _DDRS.Bits.DDRS2
#define DDRS_DDRS3                      _DDRS.Bits.DDRS3
#define DDRS_DDRS4                      _DDRS.Bits.DDRS4
#define DDRS_DDRS5                      _DDRS.Bits.DDRS5
#define DDRS_DDRS6                      _DDRS.Bits.DDRS6
#define DDRS_DDRS7                      _DDRS.Bits.DDRS7

#define DDRS_DDRS0_MASK                 1U
#define DDRS_DDRS1_MASK                 2U
#define DDRS_DDRS2_MASK                 4U
#define DDRS_DDRS3_MASK                 8U
#define DDRS_DDRS4_MASK                 16U
#define DDRS_DDRS5_MASK                 32U
#define DDRS_DDRS6_MASK                 64U
#define DDRS_DDRS7_MASK                 128U


/*** RDRS - Port S Reduced Drive Register; 0x0000024B ***/
typedef union {
  byte Byte;
  struct {
    byte RDRS0       :1;                                       /* Port S reduced drive bit 0 */
    byte RDRS1       :1;                                       /* Port S reduced drive bit 1 */
    byte RDRS2       :1;                                       /* Port S reduced drive bit 2 */
    byte RDRS3       :1;                                       /* Port S reduced drive bit 3 */
    byte RDRS4       :1;                                       /* Port S reduced drive bit 4 */
    byte RDRS5       :1;                                       /* Port S reduced drive bit 5 */
    byte RDRS6       :1;                                       /* Port S reduced drive bit 6 */
    byte RDRS7       :1;                                       /* Port S reduced drive bit 7 */
  } Bits;
} RDRSSTR;
extern volatile RDRSSTR _RDRS @(REG_BASE + 0x0000024BUL);
#define RDRS                            _RDRS.Byte
#define RDRS_RDRS0                      _RDRS.Bits.RDRS0
#define RDRS_RDRS1                      _RDRS.Bits.RDRS1
#define RDRS_RDRS2                      _RDRS.Bits.RDRS2
#define RDRS_RDRS3                      _RDRS.Bits.RDRS3
#define RDRS_RDRS4                      _RDRS.Bits.RDRS4
#define RDRS_RDRS5                      _RDRS.Bits.RDRS5
#define RDRS_RDRS6                      _RDRS.Bits.RDRS6
#define RDRS_RDRS7                      _RDRS.Bits.RDRS7

#define RDRS_RDRS0_MASK                 1U
#define RDRS_RDRS1_MASK                 2U
#define RDRS_RDRS2_MASK                 4U
#define RDRS_RDRS3_MASK                 8U
#define RDRS_RDRS4_MASK                 16U
#define RDRS_RDRS5_MASK                 32U
#define RDRS_RDRS6_MASK                 64U
#define RDRS_RDRS7_MASK                 128U


/*** PERS - Port S Pull Device Enable Register; 0x0000024C ***/
typedef union {
  byte Byte;
  struct {
    byte PERS0       :1;                                       /* Port S pull device enable bit 0 */
    byte PERS1       :1;                                       /* Port S pull device enable bit 1 */
    byte PERS2       :1;                                       /* Port S pull device enable bit 2 */
    byte PERS3       :1;                                       /* Port S pull device enable bit 3 */
    byte PERS4       :1;                                       /* Port S pull device enable bit 4 */
    byte PERS5       :1;                                       /* Port S pull device enable bit 5 */
    byte PERS6       :1;                                       /* Port S pull device enable bit 6 */
    byte PERS7       :1;                                       /* Port S pull device enable bit 7 */
  } Bits;
} PERSSTR;
extern volatile PERSSTR _PERS @(REG_BASE + 0x0000024CUL);
#define PERS                            _PERS.Byte
#define PERS_PERS0                      _PERS.Bits.PERS0
#define PERS_PERS1                      _PERS.Bits.PERS1
#define PERS_PERS2                      _PERS.Bits.PERS2
#define PERS_PERS3                      _PERS.Bits.PERS3
#define PERS_PERS4                      _PERS.Bits.PERS4
#define PERS_PERS5                      _PERS.Bits.PERS5
#define PERS_PERS6                      _PERS.Bits.PERS6
#define PERS_PERS7                      _PERS.Bits.PERS7

#define PERS_PERS0_MASK                 1U
#define PERS_PERS1_MASK                 2U
#define PERS_PERS2_MASK                 4U
#define PERS_PERS3_MASK                 8U
#define PERS_PERS4_MASK                 16U
#define PERS_PERS5_MASK                 32U
#define PERS_PERS6_MASK                 64U
#define PERS_PERS7_MASK                 128U


/*** PPSS - Port S Polarity Select Register; 0x0000024D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSS0       :1;                                       /* Port S pull device select bit 0 */
    byte PPSS1       :1;                                       /* Port S pull device select bit 1 */
    byte PPSS2       :1;                                       /* Port S pull device select bit 2 */
    byte PPSS3       :1;                                       /* Port S pull device select bit 3 */
    byte PPSS4       :1;                                       /* Port S pull device select bit 4 */
    byte PPSS5       :1;                                       /* Port S pull device select bit 5 */
    byte PPSS6       :1;                                       /* Port S pull device select bit 6 */
    byte PPSS7       :1;                                       /* Port S pull device select bit 7 */
  } Bits;
} PPSSSTR;
extern volatile PPSSSTR _PPSS @(REG_BASE + 0x0000024DUL);
#define PPSS                            _PPSS.Byte
#define PPSS_PPSS0                      _PPSS.Bits.PPSS0
#define PPSS_PPSS1                      _PPSS.Bits.PPSS1
#define PPSS_PPSS2                      _PPSS.Bits.PPSS2
#define PPSS_PPSS3                      _PPSS.Bits.PPSS3
#define PPSS_PPSS4                      _PPSS.Bits.PPSS4
#define PPSS_PPSS5                      _PPSS.Bits.PPSS5
#define PPSS_PPSS6                      _PPSS.Bits.PPSS6
#define PPSS_PPSS7                      _PPSS.Bits.PPSS7

#define PPSS_PPSS0_MASK                 1U
#define PPSS_PPSS1_MASK                 2U
#define PPSS_PPSS2_MASK                 4U
#define PPSS_PPSS3_MASK                 8U
#define PPSS_PPSS4_MASK                 16U
#define PPSS_PPSS5_MASK                 32U
#define PPSS_PPSS6_MASK                 64U
#define PPSS_PPSS7_MASK                 128U


/*** WOMS - Port S Wired-Or Mode Register; 0x0000024E ***/
typedef union {
  byte Byte;
  struct {
    byte WOMS0       :1;                                       /* Port S wired-or mode bit 0 */
    byte WOMS1       :1;                                       /* Port S wired-or mode bit 1 */
    byte WOMS2       :1;                                       /* Port S wired-or mode bit 2 */
    byte WOMS3       :1;                                       /* Port S wired-or mode bit 3 */
    byte WOMS4       :1;                                       /* Port S wired-or mode bit 4 */
    byte WOMS5       :1;                                       /* Port S wired-or mode bit 5 */
    byte WOMS6       :1;                                       /* Port S wired-or mode bit 6 */
    byte WOMS7       :1;                                       /* Port S wired-or mode bit 7 */
  } Bits;
} WOMSSTR;
extern volatile WOMSSTR _WOMS @(REG_BASE + 0x0000024EUL);
#define WOMS                            _WOMS.Byte
#define WOMS_WOMS0                      _WOMS.Bits.WOMS0
#define WOMS_WOMS1                      _WOMS.Bits.WOMS1
#define WOMS_WOMS2                      _WOMS.Bits.WOMS2
#define WOMS_WOMS3                      _WOMS.Bits.WOMS3
#define WOMS_WOMS4                      _WOMS.Bits.WOMS4
#define WOMS_WOMS5                      _WOMS.Bits.WOMS5
#define WOMS_WOMS6                      _WOMS.Bits.WOMS6
#define WOMS_WOMS7                      _WOMS.Bits.WOMS7

#define WOMS_WOMS0_MASK                 1U
#define WOMS_WOMS1_MASK                 2U
#define WOMS_WOMS2_MASK                 4U
#define WOMS_WOMS3_MASK                 8U
#define WOMS_WOMS4_MASK                 16U
#define WOMS_WOMS5_MASK                 32U
#define WOMS_WOMS6_MASK                 64U
#define WOMS_WOMS7_MASK                 128U


/*** PTM - Port M Data Register; 0x00000250 ***/
typedef union {
  byte Byte;
  struct {
    byte PTM0        :1;                                       /* Port M general purpose input/output data bit 0 */
    byte PTM1        :1;                                       /* Port M general purpose input/output data bit 1 */
    byte PTM2        :1;                                       /* Port M general purpose input/output data bit 2 */
    byte PTM3        :1;                                       /* Port M general purpose input/output data bit 3 */
    byte PTM4        :1;                                       /* Port M general purpose input/output data bit 4 */
    byte PTM5        :1;                                       /* Port M general purpose input/output data bit 5 */
    byte PTM6        :1;                                       /* Port M general purpose input/output data bit 6 */
    byte PTM7        :1;                                       /* Port M general purpose input/output data bit 7 */
  } Bits;
} PTMSTR;
extern volatile PTMSTR _PTM @(REG_BASE + 0x00000250UL);
#define PTM                             _PTM.Byte
#define PTM_PTM0                        _PTM.Bits.PTM0
#define PTM_PTM1                        _PTM.Bits.PTM1
#define PTM_PTM2                        _PTM.Bits.PTM2
#define PTM_PTM3                        _PTM.Bits.PTM3
#define PTM_PTM4                        _PTM.Bits.PTM4
#define PTM_PTM5                        _PTM.Bits.PTM5
#define PTM_PTM6                        _PTM.Bits.PTM6
#define PTM_PTM7                        _PTM.Bits.PTM7

#define PTM_PTM0_MASK                   1U
#define PTM_PTM1_MASK                   2U
#define PTM_PTM2_MASK                   4U
#define PTM_PTM3_MASK                   8U
#define PTM_PTM4_MASK                   16U
#define PTM_PTM5_MASK                   32U
#define PTM_PTM6_MASK                   64U
#define PTM_PTM7_MASK                   128U


/*** PTIM - Port M Input Register; 0x00000251 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIM0       :1;                                       /* Port M input data bit 0 */
    byte PTIM1       :1;                                       /* Port M input data bit 1 */
    byte PTIM2       :1;                                       /* Port M input data bit 2 */
    byte PTIM3       :1;                                       /* Port M input data bit 3 */
    byte PTIM4       :1;                                       /* Port M input data bit 4 */
    byte PTIM5       :1;                                       /* Port M input data bit 5 */
    byte PTIM6       :1;                                       /* Port M input data bit 6 */
    byte PTIM7       :1;                                       /* Port M input data bit 7 */
  } Bits;
} PTIMSTR;
extern volatile PTIMSTR _PTIM @(REG_BASE + 0x00000251UL);
#define PTIM                            _PTIM.Byte
#define PTIM_PTIM0                      _PTIM.Bits.PTIM0
#define PTIM_PTIM1                      _PTIM.Bits.PTIM1
#define PTIM_PTIM2                      _PTIM.Bits.PTIM2
#define PTIM_PTIM3                      _PTIM.Bits.PTIM3
#define PTIM_PTIM4                      _PTIM.Bits.PTIM4
#define PTIM_PTIM5                      _PTIM.Bits.PTIM5
#define PTIM_PTIM6                      _PTIM.Bits.PTIM6
#define PTIM_PTIM7                      _PTIM.Bits.PTIM7

#define PTIM_PTIM0_MASK                 1U
#define PTIM_PTIM1_MASK                 2U
#define PTIM_PTIM2_MASK                 4U
#define PTIM_PTIM3_MASK                 8U
#define PTIM_PTIM4_MASK                 16U
#define PTIM_PTIM5_MASK                 32U
#define PTIM_PTIM6_MASK                 64U
#define PTIM_PTIM7_MASK                 128U


/*** DDRM - Port M Data Direction Register; 0x00000252 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRM0       :1;                                       /* Port M data direction bit 0 */
    byte DDRM1       :1;                                       /* Port M data direction bit 1 */
    byte DDRM2       :1;                                       /* Port M data direction bit 2 */
    byte DDRM3       :1;                                       /* Port M data direction bit 3 */
    byte DDRM4       :1;                                       /* Port M data direction bit 4 */
    byte DDRM5       :1;                                       /* Port M data direction bit 5 */
    byte DDRM6       :1;                                       /* Port M data direction bit 6 */
    byte DDRM7       :1;                                       /* Port M data direction bit 7 */
  } Bits;
} DDRMSTR;
extern volatile DDRMSTR _DDRM @(REG_BASE + 0x00000252UL);
#define DDRM                            _DDRM.Byte
#define DDRM_DDRM0                      _DDRM.Bits.DDRM0
#define DDRM_DDRM1                      _DDRM.Bits.DDRM1
#define DDRM_DDRM2                      _DDRM.Bits.DDRM2
#define DDRM_DDRM3                      _DDRM.Bits.DDRM3
#define DDRM_DDRM4                      _DDRM.Bits.DDRM4
#define DDRM_DDRM5                      _DDRM.Bits.DDRM5
#define DDRM_DDRM6                      _DDRM.Bits.DDRM6
#define DDRM_DDRM7                      _DDRM.Bits.DDRM7

#define DDRM_DDRM0_MASK                 1U
#define DDRM_DDRM1_MASK                 2U
#define DDRM_DDRM2_MASK                 4U
#define DDRM_DDRM3_MASK                 8U
#define DDRM_DDRM4_MASK                 16U
#define DDRM_DDRM5_MASK                 32U
#define DDRM_DDRM6_MASK                 64U
#define DDRM_DDRM7_MASK                 128U


/*** RDRM - Port M Reduced Drive Register; 0x00000253 ***/
typedef union {
  byte Byte;
  struct {
    byte RDRM0       :1;                                       /* Port M reduced drive bit 0 */
    byte RDRM1       :1;                                       /* Port M reduced drive bit 1 */
    byte RDRM2       :1;                                       /* Port M reduced drive bit 2 */
    byte RDRM3       :1;                                       /* Port M reduced drive bit 3 */
    byte RDRM4       :1;                                       /* Port M reduced drive bit 4 */
    byte RDRM5       :1;                                       /* Port M reduced drive bit 5 */
    byte RDRM6       :1;                                       /* Port M reduced drive bit 6 */
    byte RDRM7       :1;                                       /* Port M reduced drive bit 7 */
  } Bits;
} RDRMSTR;
extern volatile RDRMSTR _RDRM @(REG_BASE + 0x00000253UL);
#define RDRM                            _RDRM.Byte
#define RDRM_RDRM0                      _RDRM.Bits.RDRM0
#define RDRM_RDRM1                      _RDRM.Bits.RDRM1
#define RDRM_RDRM2                      _RDRM.Bits.RDRM2
#define RDRM_RDRM3                      _RDRM.Bits.RDRM3
#define RDRM_RDRM4                      _RDRM.Bits.RDRM4
#define RDRM_RDRM5                      _RDRM.Bits.RDRM5
#define RDRM_RDRM6                      _RDRM.Bits.RDRM6
#define RDRM_RDRM7                      _RDRM.Bits.RDRM7

#define RDRM_RDRM0_MASK                 1U
#define RDRM_RDRM1_MASK                 2U
#define RDRM_RDRM2_MASK                 4U
#define RDRM_RDRM3_MASK                 8U
#define RDRM_RDRM4_MASK                 16U
#define RDRM_RDRM5_MASK                 32U
#define RDRM_RDRM6_MASK                 64U
#define RDRM_RDRM7_MASK                 128U


/*** PERM - Port M Pull Device Enable Register; 0x00000254 ***/
typedef union {
  byte Byte;
  struct {
    byte PERM0       :1;                                       /* Port M pull device enable bit 0 */
    byte PERM1       :1;                                       /* Port M pull device enable bit 1 */
    byte PERM2       :1;                                       /* Port M pull device enable bit 2 */
    byte PERM3       :1;                                       /* Port M pull device enable bit 3 */
    byte PERM4       :1;                                       /* Port M pull device enable bit 4 */
    byte PERM5       :1;                                       /* Port M pull device enable bit 5 */
    byte PERM6       :1;                                       /* Port M pull device enable bit 6 */
    byte PERM7       :1;                                       /* Port M pull device enable bit 7 */
  } Bits;
} PERMSTR;
extern volatile PERMSTR _PERM @(REG_BASE + 0x00000254UL);
#define PERM                            _PERM.Byte
#define PERM_PERM0                      _PERM.Bits.PERM0
#define PERM_PERM1                      _PERM.Bits.PERM1
#define PERM_PERM2                      _PERM.Bits.PERM2
#define PERM_PERM3                      _PERM.Bits.PERM3
#define PERM_PERM4                      _PERM.Bits.PERM4
#define PERM_PERM5                      _PERM.Bits.PERM5
#define PERM_PERM6                      _PERM.Bits.PERM6
#define PERM_PERM7                      _PERM.Bits.PERM7

#define PERM_PERM0_MASK                 1U
#define PERM_PERM1_MASK                 2U
#define PERM_PERM2_MASK                 4U
#define PERM_PERM3_MASK                 8U
#define PERM_PERM4_MASK                 16U
#define PERM_PERM5_MASK                 32U
#define PERM_PERM6_MASK                 64U
#define PERM_PERM7_MASK                 128U


/*** PPSM - Port M Polarity Select Register; 0x00000255 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSM0       :1;                                       /* Port M pull device select bit 0 */
    byte PPSM1       :1;                                       /* Port M pull device select bit 1 */
    byte PPSM2       :1;                                       /* Port M pull device select bit 2 */
    byte PPSM3       :1;                                       /* Port M pull device select bit 3 */
    byte PPSM4       :1;                                       /* Port M pull device select bit 4 */
    byte PPSM5       :1;                                       /* Port M pull device select bit 5 */
    byte PPSM6       :1;                                       /* Port M pull device select bit 6 */
    byte PPSM7       :1;                                       /* Port M pull device select bit 7 */
  } Bits;
} PPSMSTR;
extern volatile PPSMSTR _PPSM @(REG_BASE + 0x00000255UL);
#define PPSM                            _PPSM.Byte
#define PPSM_PPSM0                      _PPSM.Bits.PPSM0
#define PPSM_PPSM1                      _PPSM.Bits.PPSM1
#define PPSM_PPSM2                      _PPSM.Bits.PPSM2
#define PPSM_PPSM3                      _PPSM.Bits.PPSM3
#define PPSM_PPSM4                      _PPSM.Bits.PPSM4
#define PPSM_PPSM5                      _PPSM.Bits.PPSM5
#define PPSM_PPSM6                      _PPSM.Bits.PPSM6
#define PPSM_PPSM7                      _PPSM.Bits.PPSM7

#define PPSM_PPSM0_MASK                 1U
#define PPSM_PPSM1_MASK                 2U
#define PPSM_PPSM2_MASK                 4U
#define PPSM_PPSM3_MASK                 8U
#define PPSM_PPSM4_MASK                 16U
#define PPSM_PPSM5_MASK                 32U
#define PPSM_PPSM6_MASK                 64U
#define PPSM_PPSM7_MASK                 128U


/*** WOMM - Port M Wired-Or Mode Register; 0x00000256 ***/
typedef union {
  byte Byte;
  struct {
    byte WOMM0       :1;                                       /* Port M wired-or mode bit 0 */
    byte WOMM1       :1;                                       /* Port M wired-or mode bit 1 */
    byte WOMM2       :1;                                       /* Port M wired-or mode bit 2 */
    byte WOMM3       :1;                                       /* Port M wired-or mode bit 3 */
    byte WOMM4       :1;                                       /* Port M wired-or mode bit 4 */
    byte WOMM5       :1;                                       /* Port M wired-or mode bit 5 */
    byte WOMM6       :1;                                       /* Port M wired-or mode bit 6 */
    byte WOMM7       :1;                                       /* Port M wired-or mode bit 7 */
  } Bits;
} WOMMSTR;
extern volatile WOMMSTR _WOMM @(REG_BASE + 0x00000256UL);
#define WOMM                            _WOMM.Byte
#define WOMM_WOMM0                      _WOMM.Bits.WOMM0
#define WOMM_WOMM1                      _WOMM.Bits.WOMM1
#define WOMM_WOMM2                      _WOMM.Bits.WOMM2
#define WOMM_WOMM3                      _WOMM.Bits.WOMM3
#define WOMM_WOMM4                      _WOMM.Bits.WOMM4
#define WOMM_WOMM5                      _WOMM.Bits.WOMM5
#define WOMM_WOMM6                      _WOMM.Bits.WOMM6
#define WOMM_WOMM7                      _WOMM.Bits.WOMM7

#define WOMM_WOMM0_MASK                 1U
#define WOMM_WOMM1_MASK                 2U
#define WOMM_WOMM2_MASK                 4U
#define WOMM_WOMM3_MASK                 8U
#define WOMM_WOMM4_MASK                 16U
#define WOMM_WOMM5_MASK                 32U
#define WOMM_WOMM6_MASK                 64U
#define WOMM_WOMM7_MASK                 128U


/*** MODRR - Module Routing Register; 0x00000257 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODRR4      :1;                                       /* Module Routing bit 4 */
    byte             :1; 
    byte MODRR6      :1;                                       /* Module Routing bit 6 */
    byte MODRR7      :1;                                       /* Module Routing bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpMODRR_4 :1;
    byte         :1;
    byte grpMODRR_6 :2;
  } MergedBits;
} MODRRSTR;
extern volatile MODRRSTR _MODRR @(REG_BASE + 0x00000257UL);
#define MODRR                           _MODRR.Byte
#define MODRR_MODRR4                    _MODRR.Bits.MODRR4
#define MODRR_MODRR6                    _MODRR.Bits.MODRR6
#define MODRR_MODRR7                    _MODRR.Bits.MODRR7
#define MODRR_MODRR_6                   _MODRR.MergedBits.grpMODRR_6

#define MODRR_MODRR4_MASK               16U
#define MODRR_MODRR6_MASK               64U
#define MODRR_MODRR7_MASK               128U
#define MODRR_MODRR_6_MASK              192U
#define MODRR_MODRR_6_BITNUM            6U


/*** PTP - Port P Data Register; 0x00000258 ***/
typedef union {
  byte Byte;
  struct {
    byte PTP0        :1;                                       /* Port P general purpose input/output data bit 0 */
    byte PTP1        :1;                                       /* Port P general purpose input/output data bit 1 */
    byte PTP2        :1;                                       /* Port P general purpose input/output data bit 2 */
    byte PTP3        :1;                                       /* Port P general purpose input/output data bit 3 */
    byte PTP4        :1;                                       /* Port P general purpose input/output data bit 4 */
    byte PTP5        :1;                                       /* Port P general purpose input/output data bit 5 */
    byte PTP6        :1;                                       /* Port P general purpose input/output data bit 6 */
    byte PTP7        :1;                                       /* Port P general purpose input/output data bit 7 */
  } Bits;
} PTPSTR;
extern volatile PTPSTR _PTP @(REG_BASE + 0x00000258UL);
#define PTP                             _PTP.Byte
#define PTP_PTP0                        _PTP.Bits.PTP0
#define PTP_PTP1                        _PTP.Bits.PTP1
#define PTP_PTP2                        _PTP.Bits.PTP2
#define PTP_PTP3                        _PTP.Bits.PTP3
#define PTP_PTP4                        _PTP.Bits.PTP4
#define PTP_PTP5                        _PTP.Bits.PTP5
#define PTP_PTP6                        _PTP.Bits.PTP6
#define PTP_PTP7                        _PTP.Bits.PTP7

#define PTP_PTP0_MASK                   1U
#define PTP_PTP1_MASK                   2U
#define PTP_PTP2_MASK                   4U
#define PTP_PTP3_MASK                   8U
#define PTP_PTP4_MASK                   16U
#define PTP_PTP5_MASK                   32U
#define PTP_PTP6_MASK                   64U
#define PTP_PTP7_MASK                   128U


/*** PTIP - Port P Input Register; 0x00000259 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIP0       :1;                                       /* Port P input data bit 0 */
    byte PTIP1       :1;                                       /* Port P input data bit 1 */
    byte PTIP2       :1;                                       /* Port P input data bit 2 */
    byte PTIP3       :1;                                       /* Port P input data bit 3 */
    byte PTIP4       :1;                                       /* Port P input data bit 4 */
    byte PTIP5       :1;                                       /* Port P input data bit 5 */
    byte PTIP6       :1;                                       /* Port P input data bit 6 */
    byte PTIP7       :1;                                       /* Port P input data bit 7 */
  } Bits;
} PTIPSTR;
extern volatile PTIPSTR _PTIP @(REG_BASE + 0x00000259UL);
#define PTIP                            _PTIP.Byte
#define PTIP_PTIP0                      _PTIP.Bits.PTIP0
#define PTIP_PTIP1                      _PTIP.Bits.PTIP1
#define PTIP_PTIP2                      _PTIP.Bits.PTIP2
#define PTIP_PTIP3                      _PTIP.Bits.PTIP3
#define PTIP_PTIP4                      _PTIP.Bits.PTIP4
#define PTIP_PTIP5                      _PTIP.Bits.PTIP5
#define PTIP_PTIP6                      _PTIP.Bits.PTIP6
#define PTIP_PTIP7                      _PTIP.Bits.PTIP7

#define PTIP_PTIP0_MASK                 1U
#define PTIP_PTIP1_MASK                 2U
#define PTIP_PTIP2_MASK                 4U
#define PTIP_PTIP3_MASK                 8U
#define PTIP_PTIP4_MASK                 16U
#define PTIP_PTIP5_MASK                 32U
#define PTIP_PTIP6_MASK                 64U
#define PTIP_PTIP7_MASK                 128U


/*** DDRP - Port P Data Direction Register; 0x0000025A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRP0       :1;                                       /* Port P data direction bit 0 */
    byte DDRP1       :1;                                       /* Port P data direction bit 1 */
    byte DDRP2       :1;                                       /* Port P data direction bit 2 */
    byte DDRP3       :1;                                       /* Port P data direction bit 3 */
    byte DDRP4       :1;                                       /* Port P data direction bit 4 */
    byte DDRP5       :1;                                       /* Port P data direction bit 5 */
    byte DDRP6       :1;                                       /* Port P data direction bit 6 */
    byte DDRP7       :1;                                       /* Port P data direction bit 7 */
  } Bits;
} DDRPSTR;
extern volatile DDRPSTR _DDRP @(REG_BASE + 0x0000025AUL);
#define DDRP                            _DDRP.Byte
#define DDRP_DDRP0                      _DDRP.Bits.DDRP0
#define DDRP_DDRP1                      _DDRP.Bits.DDRP1
#define DDRP_DDRP2                      _DDRP.Bits.DDRP2
#define DDRP_DDRP3                      _DDRP.Bits.DDRP3
#define DDRP_DDRP4                      _DDRP.Bits.DDRP4
#define DDRP_DDRP5                      _DDRP.Bits.DDRP5
#define DDRP_DDRP6                      _DDRP.Bits.DDRP6
#define DDRP_DDRP7                      _DDRP.Bits.DDRP7

#define DDRP_DDRP0_MASK                 1U
#define DDRP_DDRP1_MASK                 2U
#define DDRP_DDRP2_MASK                 4U
#define DDRP_DDRP3_MASK                 8U
#define DDRP_DDRP4_MASK                 16U
#define DDRP_DDRP5_MASK                 32U
#define DDRP_DDRP6_MASK                 64U
#define DDRP_DDRP7_MASK                 128U


/*** RDRP - Port P Reduced Drive Register; 0x0000025B ***/
typedef union {
  byte Byte;
  struct {
    byte RDRP0       :1;                                       /* Port P reduced drive bit 0 */
    byte RDRP1       :1;                                       /* Port P reduced drive bit 1 */
    byte RDRP2       :1;                                       /* Port P reduced drive bit 2 */
    byte RDRP3       :1;                                       /* Port P reduced drive bit 3 */
    byte RDRP4       :1;                                       /* Port P reduced drive bit 4 */
    byte RDRP5       :1;                                       /* Port P reduced drive bit 5 */
    byte RDRP6       :1;                                       /* Port P reduced drive bit 6 */
    byte RDRP7       :1;                                       /* Port P reduced drive bit 7 */
  } Bits;
} RDRPSTR;
extern volatile RDRPSTR _RDRP @(REG_BASE + 0x0000025BUL);
#define RDRP                            _RDRP.Byte
#define RDRP_RDRP0                      _RDRP.Bits.RDRP0
#define RDRP_RDRP1                      _RDRP.Bits.RDRP1
#define RDRP_RDRP2                      _RDRP.Bits.RDRP2
#define RDRP_RDRP3                      _RDRP.Bits.RDRP3
#define RDRP_RDRP4                      _RDRP.Bits.RDRP4
#define RDRP_RDRP5                      _RDRP.Bits.RDRP5
#define RDRP_RDRP6                      _RDRP.Bits.RDRP6
#define RDRP_RDRP7                      _RDRP.Bits.RDRP7

#define RDRP_RDRP0_MASK                 1U
#define RDRP_RDRP1_MASK                 2U
#define RDRP_RDRP2_MASK                 4U
#define RDRP_RDRP3_MASK                 8U
#define RDRP_RDRP4_MASK                 16U
#define RDRP_RDRP5_MASK                 32U
#define RDRP_RDRP6_MASK                 64U
#define RDRP_RDRP7_MASK                 128U


/*** PERP - Port P Pull Device Enable Register; 0x0000025C ***/
typedef union {
  byte Byte;
  struct {
    byte PERP0       :1;                                       /* Port P pull device enable bit 0 */
    byte PERP1       :1;                                       /* Port P pull device enable bit 1 */
    byte PERP2       :1;                                       /* Port P pull device enable bit 2 */
    byte PERP3       :1;                                       /* Port P pull device enable bit 3 */
    byte PERP4       :1;                                       /* Port P pull device enable bit 4 */
    byte PERP5       :1;                                       /* Port P pull device enable bit 5 */
    byte PERP6       :1;                                       /* Port P pull device enable bit 6 */
    byte PERP7       :1;                                       /* Port P pull device enable bit 7 */
  } Bits;
} PERPSTR;
extern volatile PERPSTR _PERP @(REG_BASE + 0x0000025CUL);
#define PERP                            _PERP.Byte
#define PERP_PERP0                      _PERP.Bits.PERP0
#define PERP_PERP1                      _PERP.Bits.PERP1
#define PERP_PERP2                      _PERP.Bits.PERP2
#define PERP_PERP3                      _PERP.Bits.PERP3
#define PERP_PERP4                      _PERP.Bits.PERP4
#define PERP_PERP5                      _PERP.Bits.PERP5
#define PERP_PERP6                      _PERP.Bits.PERP6
#define PERP_PERP7                      _PERP.Bits.PERP7

#define PERP_PERP0_MASK                 1U
#define PERP_PERP1_MASK                 2U
#define PERP_PERP2_MASK                 4U
#define PERP_PERP3_MASK                 8U
#define PERP_PERP4_MASK                 16U
#define PERP_PERP5_MASK                 32U
#define PERP_PERP6_MASK                 64U
#define PERP_PERP7_MASK                 128U


/*** PPSP - Port P Polarity Select Register; 0x0000025D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSP0       :1;                                       /* Port P pull device select bit 0 */
    byte PPSP1       :1;                                       /* Port P pull device select bit 1 */
    byte PPSP2       :1;                                       /* Port P pull device select bit 2 */
    byte PPSP3       :1;                                       /* Port P pull device select bit 3 */
    byte PPSP4       :1;                                       /* Port P pull device select bit 4 */
    byte PPSP5       :1;                                       /* Port P pull device select bit 5 */
    byte PPSP6       :1;                                       /* Port P pull device select bit 6 */
    byte PPSP7       :1;                                       /* Port P pull device select bit 7 */
  } Bits;
} PPSPSTR;
extern volatile PPSPSTR _PPSP @(REG_BASE + 0x0000025DUL);
#define PPSP                            _PPSP.Byte
#define PPSP_PPSP0                      _PPSP.Bits.PPSP0
#define PPSP_PPSP1                      _PPSP.Bits.PPSP1
#define PPSP_PPSP2                      _PPSP.Bits.PPSP2
#define PPSP_PPSP3                      _PPSP.Bits.PPSP3
#define PPSP_PPSP4                      _PPSP.Bits.PPSP4
#define PPSP_PPSP5                      _PPSP.Bits.PPSP5
#define PPSP_PPSP6                      _PPSP.Bits.PPSP6
#define PPSP_PPSP7                      _PPSP.Bits.PPSP7

#define PPSP_PPSP0_MASK                 1U
#define PPSP_PPSP1_MASK                 2U
#define PPSP_PPSP2_MASK                 4U
#define PPSP_PPSP3_MASK                 8U
#define PPSP_PPSP4_MASK                 16U
#define PPSP_PPSP5_MASK                 32U
#define PPSP_PPSP6_MASK                 64U
#define PPSP_PPSP7_MASK                 128U


/*** PIEP - Port P Interrupt Enable Register; 0x0000025E ***/
typedef union {
  byte Byte;
  struct {
    byte PIEP0       :1;                                       /* Port P interrupt enable bit 0 */
    byte PIEP1       :1;                                       /* Port P interrupt enable bit 1 */
    byte PIEP2       :1;                                       /* Port P interrupt enable bit 2 */
    byte PIEP3       :1;                                       /* Port P interrupt enable bit 3 */
    byte PIEP4       :1;                                       /* Port P interrupt enable bit 4 */
    byte PIEP5       :1;                                       /* Port P interrupt enable bit 5 */
    byte PIEP6       :1;                                       /* Port P interrupt enable bit 6 */
    byte PIEP7       :1;                                       /* Port P interrupt enable bit 7 */
  } Bits;
} PIEPSTR;
extern volatile PIEPSTR _PIEP @(REG_BASE + 0x0000025EUL);
#define PIEP                            _PIEP.Byte
#define PIEP_PIEP0                      _PIEP.Bits.PIEP0
#define PIEP_PIEP1                      _PIEP.Bits.PIEP1
#define PIEP_PIEP2                      _PIEP.Bits.PIEP2
#define PIEP_PIEP3                      _PIEP.Bits.PIEP3
#define PIEP_PIEP4                      _PIEP.Bits.PIEP4
#define PIEP_PIEP5                      _PIEP.Bits.PIEP5
#define PIEP_PIEP6                      _PIEP.Bits.PIEP6
#define PIEP_PIEP7                      _PIEP.Bits.PIEP7

#define PIEP_PIEP0_MASK                 1U
#define PIEP_PIEP1_MASK                 2U
#define PIEP_PIEP2_MASK                 4U
#define PIEP_PIEP3_MASK                 8U
#define PIEP_PIEP4_MASK                 16U
#define PIEP_PIEP5_MASK                 32U
#define PIEP_PIEP6_MASK                 64U
#define PIEP_PIEP7_MASK                 128U


/*** PIFP - Port P Interrupt Flag Register; 0x0000025F ***/
typedef union {
  byte Byte;
  struct {
    byte PIFP0       :1;                                       /* Port P interrupt flag bit 0 */
    byte PIFP1       :1;                                       /* Port P interrupt flag bit 1 */
    byte PIFP2       :1;                                       /* Port P interrupt flag bit 2 */
    byte PIFP3       :1;                                       /* Port P interrupt flag bit 3 */
    byte PIFP4       :1;                                       /* Port P interrupt flag bit 4 */
    byte PIFP5       :1;                                       /* Port P interrupt flag bit 5 */
    byte PIFP6       :1;                                       /* Port P interrupt flag bit 6 */
    byte PIFP7       :1;                                       /* Port P interrupt flag bit 7 */
  } Bits;
} PIFPSTR;
extern volatile PIFPSTR _PIFP @(REG_BASE + 0x0000025FUL);
#define PIFP                            _PIFP.Byte
#define PIFP_PIFP0                      _PIFP.Bits.PIFP0
#define PIFP_PIFP1                      _PIFP.Bits.PIFP1
#define PIFP_PIFP2                      _PIFP.Bits.PIFP2
#define PIFP_PIFP3                      _PIFP.Bits.PIFP3
#define PIFP_PIFP4                      _PIFP.Bits.PIFP4
#define PIFP_PIFP5                      _PIFP.Bits.PIFP5
#define PIFP_PIFP6                      _PIFP.Bits.PIFP6
#define PIFP_PIFP7                      _PIFP.Bits.PIFP7

#define PIFP_PIFP0_MASK                 1U
#define PIFP_PIFP1_MASK                 2U
#define PIFP_PIFP2_MASK                 4U
#define PIFP_PIFP3_MASK                 8U
#define PIFP_PIFP4_MASK                 16U
#define PIFP_PIFP5_MASK                 32U
#define PIFP_PIFP6_MASK                 64U
#define PIFP_PIFP7_MASK                 128U


/*** PTH - Port H Data Register; 0x00000260 ***/
typedef union {
  byte Byte;
  struct {
    byte PTH0        :1;                                       /* Port H general purpose input/output data bit 0 */
    byte PTH1        :1;                                       /* Port H general purpose input/output data bit 1 */
    byte PTH2        :1;                                       /* Port H general purpose input/output data bit 2 */
    byte PTH3        :1;                                       /* Port H general purpose input/output data bit 3 */
    byte PTH4        :1;                                       /* Port H general purpose input/output data bit 4 */
    byte PTH5        :1;                                       /* Port H general purpose input/output data bit 5 */
    byte PTH6        :1;                                       /* Port H general purpose input/output data bit 6 */
    byte PTH7        :1;                                       /* Port H general purpose input/output data bit 7 */
  } Bits;
} PTHSTR;
extern volatile PTHSTR _PTH @(REG_BASE + 0x00000260UL);
#define PTH                             _PTH.Byte
#define PTH_PTH0                        _PTH.Bits.PTH0
#define PTH_PTH1                        _PTH.Bits.PTH1
#define PTH_PTH2                        _PTH.Bits.PTH2
#define PTH_PTH3                        _PTH.Bits.PTH3
#define PTH_PTH4                        _PTH.Bits.PTH4
#define PTH_PTH5                        _PTH.Bits.PTH5
#define PTH_PTH6                        _PTH.Bits.PTH6
#define PTH_PTH7                        _PTH.Bits.PTH7

#define PTH_PTH0_MASK                   1U
#define PTH_PTH1_MASK                   2U
#define PTH_PTH2_MASK                   4U
#define PTH_PTH3_MASK                   8U
#define PTH_PTH4_MASK                   16U
#define PTH_PTH5_MASK                   32U
#define PTH_PTH6_MASK                   64U
#define PTH_PTH7_MASK                   128U


/*** PTIH - Port H Input Register; 0x00000261 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIH0       :1;                                       /* Port H input data bit 0 */
    byte PTIH1       :1;                                       /* Port H input data bit 1 */
    byte PTIH2       :1;                                       /* Port H input data bit 2 */
    byte PTIH3       :1;                                       /* Port H input data bit 3 */
    byte PTIH4       :1;                                       /* Port H input data bit 4 */
    byte PTIH5       :1;                                       /* Port H input data bit 5 */
    byte PTIH6       :1;                                       /* Port H input data bit 6 */
    byte PTIH7       :1;                                       /* Port H input data bit 7 */
  } Bits;
} PTIHSTR;
extern volatile PTIHSTR _PTIH @(REG_BASE + 0x00000261UL);
#define PTIH                            _PTIH.Byte
#define PTIH_PTIH0                      _PTIH.Bits.PTIH0
#define PTIH_PTIH1                      _PTIH.Bits.PTIH1
#define PTIH_PTIH2                      _PTIH.Bits.PTIH2
#define PTIH_PTIH3                      _PTIH.Bits.PTIH3
#define PTIH_PTIH4                      _PTIH.Bits.PTIH4
#define PTIH_PTIH5                      _PTIH.Bits.PTIH5
#define PTIH_PTIH6                      _PTIH.Bits.PTIH6
#define PTIH_PTIH7                      _PTIH.Bits.PTIH7

#define PTIH_PTIH0_MASK                 1U
#define PTIH_PTIH1_MASK                 2U
#define PTIH_PTIH2_MASK                 4U
#define PTIH_PTIH3_MASK                 8U
#define PTIH_PTIH4_MASK                 16U
#define PTIH_PTIH5_MASK                 32U
#define PTIH_PTIH6_MASK                 64U
#define PTIH_PTIH7_MASK                 128U


/*** DDRH - Port H Data Direction Register; 0x00000262 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRH0       :1;                                       /* Port H data direction bit 0 */
    byte DDRH1       :1;                                       /* Port H data direction bit 1 */
    byte DDRH2       :1;                                       /* Port H data direction bit 2 */
    byte DDRH3       :1;                                       /* Port H data direction bit 3 */
    byte DDRH4       :1;                                       /* Port H data direction bit 4 */
    byte DDRH5       :1;                                       /* Port H data direction bit 5 */
    byte DDRH6       :1;                                       /* Port H data direction bit 6 */
    byte DDRH7       :1;                                       /* Port H data direction bit 7 */
  } Bits;
} DDRHSTR;
extern volatile DDRHSTR _DDRH @(REG_BASE + 0x00000262UL);
#define DDRH                            _DDRH.Byte
#define DDRH_DDRH0                      _DDRH.Bits.DDRH0
#define DDRH_DDRH1                      _DDRH.Bits.DDRH1
#define DDRH_DDRH2                      _DDRH.Bits.DDRH2
#define DDRH_DDRH3                      _DDRH.Bits.DDRH3
#define DDRH_DDRH4                      _DDRH.Bits.DDRH4
#define DDRH_DDRH5                      _DDRH.Bits.DDRH5
#define DDRH_DDRH6                      _DDRH.Bits.DDRH6
#define DDRH_DDRH7                      _DDRH.Bits.DDRH7

#define DDRH_DDRH0_MASK                 1U
#define DDRH_DDRH1_MASK                 2U
#define DDRH_DDRH2_MASK                 4U
#define DDRH_DDRH3_MASK                 8U
#define DDRH_DDRH4_MASK                 16U
#define DDRH_DDRH5_MASK                 32U
#define DDRH_DDRH6_MASK                 64U
#define DDRH_DDRH7_MASK                 128U


/*** RDRH - Port H Reduced Drive Register; 0x00000263 ***/
typedef union {
  byte Byte;
  struct {
    byte RDRH0       :1;                                       /* Port H reduced drive bit 0 */
    byte RDRH1       :1;                                       /* Port H reduced drive bit 1 */
    byte RDRH2       :1;                                       /* Port H reduced drive bit 2 */
    byte RDRH3       :1;                                       /* Port H reduced drive bit 3 */
    byte RDRH4       :1;                                       /* Port H reduced drive bit 4 */
    byte RDRH5       :1;                                       /* Port H reduced drive bit 5 */
    byte RDRH6       :1;                                       /* Port H reduced drive bit 6 */
    byte RDRH7       :1;                                       /* Port H reduced drive bit 7 */
  } Bits;
} RDRHSTR;
extern volatile RDRHSTR _RDRH @(REG_BASE + 0x00000263UL);
#define RDRH                            _RDRH.Byte
#define RDRH_RDRH0                      _RDRH.Bits.RDRH0
#define RDRH_RDRH1                      _RDRH.Bits.RDRH1
#define RDRH_RDRH2                      _RDRH.Bits.RDRH2
#define RDRH_RDRH3                      _RDRH.Bits.RDRH3
#define RDRH_RDRH4                      _RDRH.Bits.RDRH4
#define RDRH_RDRH5                      _RDRH.Bits.RDRH5
#define RDRH_RDRH6                      _RDRH.Bits.RDRH6
#define RDRH_RDRH7                      _RDRH.Bits.RDRH7

#define RDRH_RDRH0_MASK                 1U
#define RDRH_RDRH1_MASK                 2U
#define RDRH_RDRH2_MASK                 4U
#define RDRH_RDRH3_MASK                 8U
#define RDRH_RDRH4_MASK                 16U
#define RDRH_RDRH5_MASK                 32U
#define RDRH_RDRH6_MASK                 64U
#define RDRH_RDRH7_MASK                 128U


/*** PERH - Port H Pull Device Enable Register; 0x00000264 ***/
typedef union {
  byte Byte;
  struct {
    byte PERH0       :1;                                       /* Port H pull device enable bit 0 */
    byte PERH1       :1;                                       /* Port H pull device enable bit 1 */
    byte PERH2       :1;                                       /* Port H pull device enable bit 2 */
    byte PERH3       :1;                                       /* Port H pull device enable bit 3 */
    byte PERH4       :1;                                       /* Port H pull device enable bit 4 */
    byte PERH5       :1;                                       /* Port H pull device enable bit 5 */
    byte PERH6       :1;                                       /* Port H pull device enable bit 6 */
    byte PERH7       :1;                                       /* Port H pull device enable bit 7 */
  } Bits;
} PERHSTR;
extern volatile PERHSTR _PERH @(REG_BASE + 0x00000264UL);
#define PERH                            _PERH.Byte
#define PERH_PERH0                      _PERH.Bits.PERH0
#define PERH_PERH1                      _PERH.Bits.PERH1
#define PERH_PERH2                      _PERH.Bits.PERH2
#define PERH_PERH3                      _PERH.Bits.PERH3
#define PERH_PERH4                      _PERH.Bits.PERH4
#define PERH_PERH5                      _PERH.Bits.PERH5
#define PERH_PERH6                      _PERH.Bits.PERH6
#define PERH_PERH7                      _PERH.Bits.PERH7

#define PERH_PERH0_MASK                 1U
#define PERH_PERH1_MASK                 2U
#define PERH_PERH2_MASK                 4U
#define PERH_PERH3_MASK                 8U
#define PERH_PERH4_MASK                 16U
#define PERH_PERH5_MASK                 32U
#define PERH_PERH6_MASK                 64U
#define PERH_PERH7_MASK                 128U


/*** PPSH - Port H Polarity Select Register; 0x00000265 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSH0       :1;                                       /* Port H pull device select bit 0 */
    byte PPSH1       :1;                                       /* Port H pull device select bit 1 */
    byte PPSH2       :1;                                       /* Port H pull device select bit 2 */
    byte PPSH3       :1;                                       /* Port H pull device select bit 3 */
    byte PPSH4       :1;                                       /* Port H pull device select bit 4 */
    byte PPSH5       :1;                                       /* Port H pull device select bit 5 */
    byte PPSH6       :1;                                       /* Port H pull device select bit 6 */
    byte PPSH7       :1;                                       /* Port H pull device select bit 7 */
  } Bits;
} PPSHSTR;
extern volatile PPSHSTR _PPSH @(REG_BASE + 0x00000265UL);
#define PPSH                            _PPSH.Byte
#define PPSH_PPSH0                      _PPSH.Bits.PPSH0
#define PPSH_PPSH1                      _PPSH.Bits.PPSH1
#define PPSH_PPSH2                      _PPSH.Bits.PPSH2
#define PPSH_PPSH3                      _PPSH.Bits.PPSH3
#define PPSH_PPSH4                      _PPSH.Bits.PPSH4
#define PPSH_PPSH5                      _PPSH.Bits.PPSH5
#define PPSH_PPSH6                      _PPSH.Bits.PPSH6
#define PPSH_PPSH7                      _PPSH.Bits.PPSH7

#define PPSH_PPSH0_MASK                 1U
#define PPSH_PPSH1_MASK                 2U
#define PPSH_PPSH2_MASK                 4U
#define PPSH_PPSH3_MASK                 8U
#define PPSH_PPSH4_MASK                 16U
#define PPSH_PPSH5_MASK                 32U
#define PPSH_PPSH6_MASK                 64U
#define PPSH_PPSH7_MASK                 128U


/*** PIEH - Port H Interrupt Enable Register; 0x00000266 ***/
typedef union {
  byte Byte;
  struct {
    byte PIEH0       :1;                                       /* Port H interrupt enable bit 0 */
    byte PIEH1       :1;                                       /* Port H interrupt enable bit 1 */
    byte PIEH2       :1;                                       /* Port H interrupt enable bit 2 */
    byte PIEH3       :1;                                       /* Port H interrupt enable bit 3 */
    byte PIEH4       :1;                                       /* Port H interrupt enable bit 4 */
    byte PIEH5       :1;                                       /* Port H interrupt enable bit 5 */
    byte PIEH6       :1;                                       /* Port H interrupt enable bit 6 */
    byte PIEH7       :1;                                       /* Port H interrupt enable bit 7 */
  } Bits;
} PIEHSTR;
extern volatile PIEHSTR _PIEH @(REG_BASE + 0x00000266UL);
#define PIEH                            _PIEH.Byte
#define PIEH_PIEH0                      _PIEH.Bits.PIEH0
#define PIEH_PIEH1                      _PIEH.Bits.PIEH1
#define PIEH_PIEH2                      _PIEH.Bits.PIEH2
#define PIEH_PIEH3                      _PIEH.Bits.PIEH3
#define PIEH_PIEH4                      _PIEH.Bits.PIEH4
#define PIEH_PIEH5                      _PIEH.Bits.PIEH5
#define PIEH_PIEH6                      _PIEH.Bits.PIEH6
#define PIEH_PIEH7                      _PIEH.Bits.PIEH7

#define PIEH_PIEH0_MASK                 1U
#define PIEH_PIEH1_MASK                 2U
#define PIEH_PIEH2_MASK                 4U
#define PIEH_PIEH3_MASK                 8U
#define PIEH_PIEH4_MASK                 16U
#define PIEH_PIEH5_MASK                 32U
#define PIEH_PIEH6_MASK                 64U
#define PIEH_PIEH7_MASK                 128U


/*** PIFH - Port H Interrupt Flag Register; 0x00000267 ***/
typedef union {
  byte Byte;
  struct {
    byte PIFH0       :1;                                       /* Port H interrupt flag bit 0 */
    byte PIFH1       :1;                                       /* Port H interrupt flag bit 1 */
    byte PIFH2       :1;                                       /* Port H interrupt flag bit 2 */
    byte PIFH3       :1;                                       /* Port H interrupt flag bit 3 */
    byte PIFH4       :1;                                       /* Port H interrupt flag bit 4 */
    byte PIFH5       :1;                                       /* Port H interrupt flag bit 5 */
    byte PIFH6       :1;                                       /* Port H interrupt flag bit 6 */
    byte PIFH7       :1;                                       /* Port H interrupt flag bit 7 */
  } Bits;
} PIFHSTR;
extern volatile PIFHSTR _PIFH @(REG_BASE + 0x00000267UL);
#define PIFH                            _PIFH.Byte
#define PIFH_PIFH0                      _PIFH.Bits.PIFH0
#define PIFH_PIFH1                      _PIFH.Bits.PIFH1
#define PIFH_PIFH2                      _PIFH.Bits.PIFH2
#define PIFH_PIFH3                      _PIFH.Bits.PIFH3
#define PIFH_PIFH4                      _PIFH.Bits.PIFH4
#define PIFH_PIFH5                      _PIFH.Bits.PIFH5
#define PIFH_PIFH6                      _PIFH.Bits.PIFH6
#define PIFH_PIFH7                      _PIFH.Bits.PIFH7

#define PIFH_PIFH0_MASK                 1U
#define PIFH_PIFH1_MASK                 2U
#define PIFH_PIFH2_MASK                 4U
#define PIFH_PIFH3_MASK                 8U
#define PIFH_PIFH4_MASK                 16U
#define PIFH_PIFH5_MASK                 32U
#define PIFH_PIFH6_MASK                 64U
#define PIFH_PIFH7_MASK                 128U


/*** PTJ - Port J Data Register; 0x00000268 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJ0        :1;                                       /* Port J general purpose input/output data bit 0 */
    byte PTJ1        :1;                                       /* Port J general purpose input/output data bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PTJ6        :1;                                       /* Port J general purpose input/output data bit 6 */
    byte PTJ7        :1;                                       /* Port J general purpose input/output data bit 7 */
  } Bits;
  struct {
    byte grpPTJ  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPTJ_6 :2;
  } MergedBits;
} PTJSTR;
extern volatile PTJSTR _PTJ @(REG_BASE + 0x00000268UL);
#define PTJ                             _PTJ.Byte
#define PTJ_PTJ0                        _PTJ.Bits.PTJ0
#define PTJ_PTJ1                        _PTJ.Bits.PTJ1
#define PTJ_PTJ6                        _PTJ.Bits.PTJ6
#define PTJ_PTJ7                        _PTJ.Bits.PTJ7
#define PTJ_PTJ                         _PTJ.MergedBits.grpPTJ
#define PTJ_PTJ_6                       _PTJ.MergedBits.grpPTJ_6

#define PTJ_PTJ0_MASK                   1U
#define PTJ_PTJ1_MASK                   2U
#define PTJ_PTJ6_MASK                   64U
#define PTJ_PTJ7_MASK                   128U
#define PTJ_PTJ_MASK                    3U
#define PTJ_PTJ_BITNUM                  0U
#define PTJ_PTJ_6_MASK                  192U
#define PTJ_PTJ_6_BITNUM                6U


/*** PTIJ - Port J Input Register; 0x00000269 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIJ0       :1;                                       /* Port J input data bit 0 */
    byte PTIJ1       :1;                                       /* Port J input data bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PTIJ6       :1;                                       /* Port J input data bit 6 */
    byte PTIJ7       :1;                                       /* Port J input data bit 7 */
  } Bits;
  struct {
    byte grpPTIJ :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPTIJ_6 :2;
  } MergedBits;
} PTIJSTR;
extern volatile PTIJSTR _PTIJ @(REG_BASE + 0x00000269UL);
#define PTIJ                            _PTIJ.Byte
#define PTIJ_PTIJ0                      _PTIJ.Bits.PTIJ0
#define PTIJ_PTIJ1                      _PTIJ.Bits.PTIJ1
#define PTIJ_PTIJ6                      _PTIJ.Bits.PTIJ6
#define PTIJ_PTIJ7                      _PTIJ.Bits.PTIJ7
#define PTIJ_PTIJ                       _PTIJ.MergedBits.grpPTIJ
#define PTIJ_PTIJ_6                     _PTIJ.MergedBits.grpPTIJ_6

#define PTIJ_PTIJ0_MASK                 1U
#define PTIJ_PTIJ1_MASK                 2U
#define PTIJ_PTIJ6_MASK                 64U
#define PTIJ_PTIJ7_MASK                 128U
#define PTIJ_PTIJ_MASK                  3U
#define PTIJ_PTIJ_BITNUM                0U
#define PTIJ_PTIJ_6_MASK                192U
#define PTIJ_PTIJ_6_BITNUM              6U


/*** DDRJ - Port J Data Direction Register; 0x0000026A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRJ0       :1;                                       /* Port J data direction bit 0 */
    byte DDRJ1       :1;                                       /* Port J data direction bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DDRJ6       :1;                                       /* Port J data direction bit 6 */
    byte DDRJ7       :1;                                       /* Port J data direction bit 7 */
  } Bits;
  struct {
    byte grpDDRJ :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpDDRJ_6 :2;
  } MergedBits;
} DDRJSTR;
extern volatile DDRJSTR _DDRJ @(REG_BASE + 0x0000026AUL);
#define DDRJ                            _DDRJ.Byte
#define DDRJ_DDRJ0                      _DDRJ.Bits.DDRJ0
#define DDRJ_DDRJ1                      _DDRJ.Bits.DDRJ1
#define DDRJ_DDRJ6                      _DDRJ.Bits.DDRJ6
#define DDRJ_DDRJ7                      _DDRJ.Bits.DDRJ7
#define DDRJ_DDRJ                       _DDRJ.MergedBits.grpDDRJ
#define DDRJ_DDRJ_6                     _DDRJ.MergedBits.grpDDRJ_6

#define DDRJ_DDRJ0_MASK                 1U
#define DDRJ_DDRJ1_MASK                 2U
#define DDRJ_DDRJ6_MASK                 64U
#define DDRJ_DDRJ7_MASK                 128U
#define DDRJ_DDRJ_MASK                  3U
#define DDRJ_DDRJ_BITNUM                0U
#define DDRJ_DDRJ_6_MASK                192U
#define DDRJ_DDRJ_6_BITNUM              6U


/*** RDRJ - Port J Reduced Drive Register; 0x0000026B ***/
typedef union {
  byte Byte;
  struct {
    byte RDRJ0       :1;                                       /* Port J reduced drive bit 0 */
    byte RDRJ1       :1;                                       /* Port J reduced drive bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RDRJ6       :1;                                       /* Port J reduced drive bit 6 */
    byte RDRJ7       :1;                                       /* Port J reduced drive bit 7 */
  } Bits;
  struct {
    byte grpRDRJ :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRDRJ_6 :2;
  } MergedBits;
} RDRJSTR;
extern volatile RDRJSTR _RDRJ @(REG_BASE + 0x0000026BUL);
#define RDRJ                            _RDRJ.Byte
#define RDRJ_RDRJ0                      _RDRJ.Bits.RDRJ0
#define RDRJ_RDRJ1                      _RDRJ.Bits.RDRJ1
#define RDRJ_RDRJ6                      _RDRJ.Bits.RDRJ6
#define RDRJ_RDRJ7                      _RDRJ.Bits.RDRJ7
#define RDRJ_RDRJ                       _RDRJ.MergedBits.grpRDRJ
#define RDRJ_RDRJ_6                     _RDRJ.MergedBits.grpRDRJ_6

#define RDRJ_RDRJ0_MASK                 1U
#define RDRJ_RDRJ1_MASK                 2U
#define RDRJ_RDRJ6_MASK                 64U
#define RDRJ_RDRJ7_MASK                 128U
#define RDRJ_RDRJ_MASK                  3U
#define RDRJ_RDRJ_BITNUM                0U
#define RDRJ_RDRJ_6_MASK                192U
#define RDRJ_RDRJ_6_BITNUM              6U


/*** PERJ - Port J Pull Device Enable Register; 0x0000026C ***/
typedef union {
  byte Byte;
  struct {
    byte PERJ0       :1;                                       /* Port J pull device enable bit 0 */
    byte PERJ1       :1;                                       /* Port J pull device enable bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PERJ6       :1;                                       /* Port J pull device enable bit 6 */
    byte PERJ7       :1;                                       /* Port J pull device enable bit 7 */
  } Bits;
  struct {
    byte grpPERJ :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPERJ_6 :2;
  } MergedBits;
} PERJSTR;
extern volatile PERJSTR _PERJ @(REG_BASE + 0x0000026CUL);
#define PERJ                            _PERJ.Byte
#define PERJ_PERJ0                      _PERJ.Bits.PERJ0
#define PERJ_PERJ1                      _PERJ.Bits.PERJ1
#define PERJ_PERJ6                      _PERJ.Bits.PERJ6
#define PERJ_PERJ7                      _PERJ.Bits.PERJ7
#define PERJ_PERJ                       _PERJ.MergedBits.grpPERJ
#define PERJ_PERJ_6                     _PERJ.MergedBits.grpPERJ_6

#define PERJ_PERJ0_MASK                 1U
#define PERJ_PERJ1_MASK                 2U
#define PERJ_PERJ6_MASK                 64U
#define PERJ_PERJ7_MASK                 128U
#define PERJ_PERJ_MASK                  3U
#define PERJ_PERJ_BITNUM                0U
#define PERJ_PERJ_6_MASK                192U
#define PERJ_PERJ_6_BITNUM              6U


/*** PPSJ - Port J Polarity Select Register; 0x0000026D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSJ0       :1;                                       /* Port J pull device select bit 0 */
    byte PPSJ1       :1;                                       /* Port J pull device select bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PPSJ6       :1;                                       /* Port J pull device select bit 6 */
    byte PPSJ7       :1;                                       /* Port J pull device select bit 7 */
  } Bits;
  struct {
    byte grpPPSJ :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPPSJ_6 :2;
  } MergedBits;
} PPSJSTR;
extern volatile PPSJSTR _PPSJ @(REG_BASE + 0x0000026DUL);
#define PPSJ                            _PPSJ.Byte
#define PPSJ_PPSJ0                      _PPSJ.Bits.PPSJ0
#define PPSJ_PPSJ1                      _PPSJ.Bits.PPSJ1
#define PPSJ_PPSJ6                      _PPSJ.Bits.PPSJ6
#define PPSJ_PPSJ7                      _PPSJ.Bits.PPSJ7
#define PPSJ_PPSJ                       _PPSJ.MergedBits.grpPPSJ
#define PPSJ_PPSJ_6                     _PPSJ.MergedBits.grpPPSJ_6

#define PPSJ_PPSJ0_MASK                 1U
#define PPSJ_PPSJ1_MASK                 2U
#define PPSJ_PPSJ6_MASK                 64U
#define PPSJ_PPSJ7_MASK                 128U
#define PPSJ_PPSJ_MASK                  3U
#define PPSJ_PPSJ_BITNUM                0U
#define PPSJ_PPSJ_6_MASK                192U
#define PPSJ_PPSJ_6_BITNUM              6U


/*** PIEJ - Port J Interrupt Enable Register; 0x0000026E ***/
typedef union {
  byte Byte;
  struct {
    byte PIEJ0       :1;                                       /* Port J interrupt enable bit 0 */
    byte PIEJ1       :1;                                       /* Port J interrupt enable bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PIEJ6       :1;                                       /* Port J interrupt enable bit 6 */
    byte PIEJ7       :1;                                       /* Port J interrupt enable bit 7 */
  } Bits;
  struct {
    byte grpPIEJ :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPIEJ_6 :2;
  } MergedBits;
} PIEJSTR;
extern volatile PIEJSTR _PIEJ @(REG_BASE + 0x0000026EUL);
#define PIEJ                            _PIEJ.Byte
#define PIEJ_PIEJ0                      _PIEJ.Bits.PIEJ0
#define PIEJ_PIEJ1                      _PIEJ.Bits.PIEJ1
#define PIEJ_PIEJ6                      _PIEJ.Bits.PIEJ6
#define PIEJ_PIEJ7                      _PIEJ.Bits.PIEJ7
#define PIEJ_PIEJ                       _PIEJ.MergedBits.grpPIEJ
#define PIEJ_PIEJ_6                     _PIEJ.MergedBits.grpPIEJ_6

#define PIEJ_PIEJ0_MASK                 1U
#define PIEJ_PIEJ1_MASK                 2U
#define PIEJ_PIEJ6_MASK                 64U
#define PIEJ_PIEJ7_MASK                 128U
#define PIEJ_PIEJ_MASK                  3U
#define PIEJ_PIEJ_BITNUM                0U
#define PIEJ_PIEJ_6_MASK                192U
#define PIEJ_PIEJ_6_BITNUM              6U


/*** PIFJ - Port J Interrupt Flag Register; 0x0000026F ***/
typedef union {
  byte Byte;
  struct {
    byte PIFJ0       :1;                                       /* Port J interrupt flag bit 0 */
    byte PIFJ1       :1;                                       /* Port J interrupt flag bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PIFJ6       :1;                                       /* Port J interrupt flag bit 6 */
    byte PIFJ7       :1;                                       /* Port J interrupt flag bit 7 */
  } Bits;
  struct {
    byte grpPIFJ :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPIFJ_6 :2;
  } MergedBits;
} PIFJSTR;
extern volatile PIFJSTR _PIFJ @(REG_BASE + 0x0000026FUL);
#define PIFJ                            _PIFJ.Byte
#define PIFJ_PIFJ0                      _PIFJ.Bits.PIFJ0
#define PIFJ_PIFJ1                      _PIFJ.Bits.PIFJ1
#define PIFJ_PIFJ6                      _PIFJ.Bits.PIFJ6
#define PIFJ_PIFJ7                      _PIFJ.Bits.PIFJ7
#define PIFJ_PIFJ                       _PIFJ.MergedBits.grpPIFJ
#define PIFJ_PIFJ_6                     _PIFJ.MergedBits.grpPIFJ_6

#define PIFJ_PIFJ0_MASK                 1U
#define PIFJ_PIFJ1_MASK                 2U
#define PIFJ_PIFJ6_MASK                 64U
#define PIFJ_PIFJ7_MASK                 128U
#define PIFJ_PIFJ_MASK                  3U
#define PIFJ_PIFJ_BITNUM                0U
#define PIFJ_PIFJ_6_MASK                192U
#define PIFJ_PIFJ_6_BITNUM              6U


/*** PT01AD0 - Port AD0 Data Register; 0x00000270 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PT0AD0 - Port AD0H Data Register; 0x00000270 ***/
    union {
      byte Byte;
      struct {
        byte PT0AD00     :1;                                       /* Port AD0 data bit 0 */
        byte PT0AD01     :1;                                       /* Port AD0 data bit 1 */
        byte PT0AD02     :1;                                       /* Port AD0 data bit 2 */
        byte PT0AD03     :1;                                       /* Port AD0 data bit 3 */
        byte PT0AD04     :1;                                       /* Port AD0 data bit 4 */
        byte PT0AD05     :1;                                       /* Port AD0 data bit 5 */
        byte PT0AD06     :1;                                       /* Port AD0 data bit 6 */
        byte PT0AD07     :1;                                       /* Port AD0 data bit 7 */
      } Bits;
    } PT0AD0STR;
    #define PT0AD0                      _PT01AD0.Overlap_STR.PT0AD0STR.Byte
    #define PT0AD0_PT0AD00              _PT01AD0.Overlap_STR.PT0AD0STR.Bits.PT0AD00
    #define PT0AD0_PT0AD01              _PT01AD0.Overlap_STR.PT0AD0STR.Bits.PT0AD01
    #define PT0AD0_PT0AD02              _PT01AD0.Overlap_STR.PT0AD0STR.Bits.PT0AD02
    #define PT0AD0_PT0AD03              _PT01AD0.Overlap_STR.PT0AD0STR.Bits.PT0AD03
    #define PT0AD0_PT0AD04              _PT01AD0.Overlap_STR.PT0AD0STR.Bits.PT0AD04
    #define PT0AD0_PT0AD05              _PT01AD0.Overlap_STR.PT0AD0STR.Bits.PT0AD05
    #define PT0AD0_PT0AD06              _PT01AD0.Overlap_STR.PT0AD0STR.Bits.PT0AD06
    #define PT0AD0_PT0AD07              _PT01AD0.Overlap_STR.PT0AD0STR.Bits.PT0AD07
    
    #define PT0AD0_PT0AD00_MASK         1U
    #define PT0AD0_PT0AD01_MASK         2U
    #define PT0AD0_PT0AD02_MASK         4U
    #define PT0AD0_PT0AD03_MASK         8U
    #define PT0AD0_PT0AD04_MASK         16U
    #define PT0AD0_PT0AD05_MASK         32U
    #define PT0AD0_PT0AD06_MASK         64U
    #define PT0AD0_PT0AD07_MASK         128U
    

    /*** PT1AD0 - Port AD0L Data Register; 0x00000271 ***/
    union {
      byte Byte;
      struct {
        byte PT1AD00     :1;                                       /* Port AD0 data bit 0 */
        byte PT1AD01     :1;                                       /* Port AD0 data bit 1 */
        byte PT1AD02     :1;                                       /* Port AD0 data bit 2 */
        byte PT1AD03     :1;                                       /* Port AD0 data bit 3 */
        byte PT1AD04     :1;                                       /* Port AD0 data bit 4 */
        byte PT1AD05     :1;                                       /* Port AD0 data bit 5 */
        byte PT1AD06     :1;                                       /* Port AD0 data bit 6 */
        byte PT1AD07     :1;                                       /* Port AD0 data bit 7 */
      } Bits;
    } PT1AD0STR;
    #define PT1AD0                      _PT01AD0.Overlap_STR.PT1AD0STR.Byte
    #define PT1AD0_PT1AD00              _PT01AD0.Overlap_STR.PT1AD0STR.Bits.PT1AD00
    #define PT1AD0_PT1AD01              _PT01AD0.Overlap_STR.PT1AD0STR.Bits.PT1AD01
    #define PT1AD0_PT1AD02              _PT01AD0.Overlap_STR.PT1AD0STR.Bits.PT1AD02
    #define PT1AD0_PT1AD03              _PT01AD0.Overlap_STR.PT1AD0STR.Bits.PT1AD03
    #define PT1AD0_PT1AD04              _PT01AD0.Overlap_STR.PT1AD0STR.Bits.PT1AD04
    #define PT1AD0_PT1AD05              _PT01AD0.Overlap_STR.PT1AD0STR.Bits.PT1AD05
    #define PT1AD0_PT1AD06              _PT01AD0.Overlap_STR.PT1AD0STR.Bits.PT1AD06
    #define PT1AD0_PT1AD07              _PT01AD0.Overlap_STR.PT1AD0STR.Bits.PT1AD07
    
    #define PT1AD0_PT1AD00_MASK         1U
    #define PT1AD0_PT1AD01_MASK         2U
    #define PT1AD0_PT1AD02_MASK         4U
    #define PT1AD0_PT1AD03_MASK         8U
    #define PT1AD0_PT1AD04_MASK         16U
    #define PT1AD0_PT1AD05_MASK         32U
    #define PT1AD0_PT1AD06_MASK         64U
    #define PT1AD0_PT1AD07_MASK         128U
    
  } Overlap_STR;

  struct {
    word PT1AD00     :1;                                       /* Port AD0 data bit 0 */
    word PT1AD01     :1;                                       /* Port AD0 data bit 1 */
    word PT1AD02     :1;                                       /* Port AD0 data bit 2 */
    word PT1AD03     :1;                                       /* Port AD0 data bit 3 */
    word PT1AD04     :1;                                       /* Port AD0 data bit 4 */
    word PT1AD05     :1;                                       /* Port AD0 data bit 5 */
    word PT1AD06     :1;                                       /* Port AD0 data bit 6 */
    word PT1AD07     :1;                                       /* Port AD0 data bit 7 */
    word PT0AD00     :1;                                       /* Port AD0 data bit 8 */
    word PT0AD01     :1;                                       /* Port AD0 data bit 9 */
    word PT0AD02     :1;                                       /* Port AD0 data bit 10 */
    word PT0AD03     :1;                                       /* Port AD0 data bit 11 */
    word PT0AD04     :1;                                       /* Port AD0 data bit 12 */
    word PT0AD05     :1;                                       /* Port AD0 data bit 13 */
    word PT0AD06     :1;                                       /* Port AD0 data bit 14 */
    word PT0AD07     :1;                                       /* Port AD0 data bit 15 */
  } Bits;
  struct {
    word grpPT1AD0 :8;
    word grpPT0AD0 :8;
  } MergedBits;
} PT01AD0STR;
extern volatile PT01AD0STR _PT01AD0 @(REG_BASE + 0x00000270UL);
#define PT01AD0                         _PT01AD0.Word
#define PT01AD0_PT1AD00                 _PT01AD0.Bits.PT1AD00
#define PT01AD0_PT1AD01                 _PT01AD0.Bits.PT1AD01
#define PT01AD0_PT1AD02                 _PT01AD0.Bits.PT1AD02
#define PT01AD0_PT1AD03                 _PT01AD0.Bits.PT1AD03
#define PT01AD0_PT1AD04                 _PT01AD0.Bits.PT1AD04
#define PT01AD0_PT1AD05                 _PT01AD0.Bits.PT1AD05
#define PT01AD0_PT1AD06                 _PT01AD0.Bits.PT1AD06
#define PT01AD0_PT1AD07                 _PT01AD0.Bits.PT1AD07
#define PT01AD0_PT0AD00                 _PT01AD0.Bits.PT0AD00
#define PT01AD0_PT0AD01                 _PT01AD0.Bits.PT0AD01
#define PT01AD0_PT0AD02                 _PT01AD0.Bits.PT0AD02
#define PT01AD0_PT0AD03                 _PT01AD0.Bits.PT0AD03
#define PT01AD0_PT0AD04                 _PT01AD0.Bits.PT0AD04
#define PT01AD0_PT0AD05                 _PT01AD0.Bits.PT0AD05
#define PT01AD0_PT0AD06                 _PT01AD0.Bits.PT0AD06
#define PT01AD0_PT0AD07                 _PT01AD0.Bits.PT0AD07
#define PT01AD0_PT1AD0                  _PT01AD0.MergedBits.grpPT1AD0
#define PT01AD0_PT0AD0                  _PT01AD0.MergedBits.grpPT0AD0

#define PT01AD0_PT1AD00_MASK            1U
#define PT01AD0_PT1AD01_MASK            2U
#define PT01AD0_PT1AD02_MASK            4U
#define PT01AD0_PT1AD03_MASK            8U
#define PT01AD0_PT1AD04_MASK            16U
#define PT01AD0_PT1AD05_MASK            32U
#define PT01AD0_PT1AD06_MASK            64U
#define PT01AD0_PT1AD07_MASK            128U
#define PT01AD0_PT0AD00_MASK            256U
#define PT01AD0_PT0AD01_MASK            512U
#define PT01AD0_PT0AD02_MASK            1024U
#define PT01AD0_PT0AD03_MASK            2048U
#define PT01AD0_PT0AD04_MASK            4096U
#define PT01AD0_PT0AD05_MASK            8192U
#define PT01AD0_PT0AD06_MASK            16384U
#define PT01AD0_PT0AD07_MASK            32768U
#define PT01AD0_PT1AD0_MASK             255U
#define PT01AD0_PT1AD0_BITNUM           0U
#define PT01AD0_PT0AD0_MASK             65280U
#define PT01AD0_PT0AD0_BITNUM           8U


/*** DDR01AD0 - Port AD0 Data Direction Register; 0x00000272 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DDR0AD0 - Port AD0H Data Direction Register; 0x00000272 ***/
    union {
      byte Byte;
      struct {
        byte DDR0AD00    :1;                                       /* Port AD0 data direction bit 0 */
        byte DDR0AD01    :1;                                       /* Port AD0 data direction bit 1 */
        byte DDR0AD02    :1;                                       /* Port AD0 data direction bit 2 */
        byte DDR0AD03    :1;                                       /* Port AD0 data direction bit 3 */
        byte DDR0AD04    :1;                                       /* Port AD0 data direction bit 4 */
        byte DDR0AD05    :1;                                       /* Port AD0 data direction bit 5 */
        byte DDR0AD06    :1;                                       /* Port AD0 data direction bit 6 */
        byte DDR0AD07    :1;                                       /* Port AD0 data direction bit 7 */
      } Bits;
    } DDR0AD0STR;
    #define DDR0AD0                     _DDR01AD0.Overlap_STR.DDR0AD0STR.Byte
    #define DDR0AD0_DDR0AD00            _DDR01AD0.Overlap_STR.DDR0AD0STR.Bits.DDR0AD00
    #define DDR0AD0_DDR0AD01            _DDR01AD0.Overlap_STR.DDR0AD0STR.Bits.DDR0AD01
    #define DDR0AD0_DDR0AD02            _DDR01AD0.Overlap_STR.DDR0AD0STR.Bits.DDR0AD02
    #define DDR0AD0_DDR0AD03            _DDR01AD0.Overlap_STR.DDR0AD0STR.Bits.DDR0AD03
    #define DDR0AD0_DDR0AD04            _DDR01AD0.Overlap_STR.DDR0AD0STR.Bits.DDR0AD04
    #define DDR0AD0_DDR0AD05            _DDR01AD0.Overlap_STR.DDR0AD0STR.Bits.DDR0AD05
    #define DDR0AD0_DDR0AD06            _DDR01AD0.Overlap_STR.DDR0AD0STR.Bits.DDR0AD06
    #define DDR0AD0_DDR0AD07            _DDR01AD0.Overlap_STR.DDR0AD0STR.Bits.DDR0AD07
    
    #define DDR0AD0_DDR0AD00_MASK       1U
    #define DDR0AD0_DDR0AD01_MASK       2U
    #define DDR0AD0_DDR0AD02_MASK       4U
    #define DDR0AD0_DDR0AD03_MASK       8U
    #define DDR0AD0_DDR0AD04_MASK       16U
    #define DDR0AD0_DDR0AD05_MASK       32U
    #define DDR0AD0_DDR0AD06_MASK       64U
    #define DDR0AD0_DDR0AD07_MASK       128U
    

    /*** DDR1AD0 - Port AD0L Data Direction Register; 0x00000273 ***/
    union {
      byte Byte;
      struct {
        byte DDR1AD00    :1;                                       /* Port AD0 data direction bit 0 */
        byte DDR1AD01    :1;                                       /* Port AD0 data direction bit 1 */
        byte DDR1AD02    :1;                                       /* Port AD0 data direction bit 2 */
        byte DDR1AD03    :1;                                       /* Port AD0 data direction bit 3 */
        byte DDR1AD04    :1;                                       /* Port AD0 data direction bit 4 */
        byte DDR1AD05    :1;                                       /* Port AD0 data direction bit 5 */
        byte DDR1AD06    :1;                                       /* Port AD0 data direction bit 6 */
        byte DDR1AD07    :1;                                       /* Port AD0 data direction bit 7 */
      } Bits;
    } DDR1AD0STR;
    #define DDR1AD0                     _DDR01AD0.Overlap_STR.DDR1AD0STR.Byte
    #define DDR1AD0_DDR1AD00            _DDR01AD0.Overlap_STR.DDR1AD0STR.Bits.DDR1AD00
    #define DDR1AD0_DDR1AD01            _DDR01AD0.Overlap_STR.DDR1AD0STR.Bits.DDR1AD01
    #define DDR1AD0_DDR1AD02            _DDR01AD0.Overlap_STR.DDR1AD0STR.Bits.DDR1AD02
    #define DDR1AD0_DDR1AD03            _DDR01AD0.Overlap_STR.DDR1AD0STR.Bits.DDR1AD03
    #define DDR1AD0_DDR1AD04            _DDR01AD0.Overlap_STR.DDR1AD0STR.Bits.DDR1AD04
    #define DDR1AD0_DDR1AD05            _DDR01AD0.Overlap_STR.DDR1AD0STR.Bits.DDR1AD05
    #define DDR1AD0_DDR1AD06            _DDR01AD0.Overlap_STR.DDR1AD0STR.Bits.DDR1AD06
    #define DDR1AD0_DDR1AD07            _DDR01AD0.Overlap_STR.DDR1AD0STR.Bits.DDR1AD07
    
    #define DDR1AD0_DDR1AD00_MASK       1U
    #define DDR1AD0_DDR1AD01_MASK       2U
    #define DDR1AD0_DDR1AD02_MASK       4U
    #define DDR1AD0_DDR1AD03_MASK       8U
    #define DDR1AD0_DDR1AD04_MASK       16U
    #define DDR1AD0_DDR1AD05_MASK       32U
    #define DDR1AD0_DDR1AD06_MASK       64U
    #define DDR1AD0_DDR1AD07_MASK       128U
    
  } Overlap_STR;

  struct {
    word DDR1AD00    :1;                                       /* Port AD0 data direction bit 0 */
    word DDR1AD01    :1;                                       /* Port AD0 data direction bit 1 */
    word DDR1AD02    :1;                                       /* Port AD0 data direction bit 2 */
    word DDR1AD03    :1;                                       /* Port AD0 data direction bit 3 */
    word DDR1AD04    :1;                                       /* Port AD0 data direction bit 4 */
    word DDR1AD05    :1;                                       /* Port AD0 data direction bit 5 */
    word DDR1AD06    :1;                                       /* Port AD0 data direction bit 6 */
    word DDR1AD07    :1;                                       /* Port AD0 data direction bit 7 */
    word DDR0AD00    :1;                                       /* Port AD0 data direction bit 8 */
    word DDR0AD01    :1;                                       /* Port AD0 data direction bit 9 */
    word DDR0AD02    :1;                                       /* Port AD0 data direction bit 10 */
    word DDR0AD03    :1;                                       /* Port AD0 data direction bit 11 */
    word DDR0AD04    :1;                                       /* Port AD0 data direction bit 12 */
    word DDR0AD05    :1;                                       /* Port AD0 data direction bit 13 */
    word DDR0AD06    :1;                                       /* Port AD0 data direction bit 14 */
    word DDR0AD07    :1;                                       /* Port AD0 data direction bit 15 */
  } Bits;
  struct {
    word grpDDR1AD0 :8;
    word grpDDR0AD0 :8;
  } MergedBits;
} DDR01AD0STR;
extern volatile DDR01AD0STR _DDR01AD0 @(REG_BASE + 0x00000272UL);
#define DDR01AD0                        _DDR01AD0.Word
#define DDR01AD0_DDR1AD00               _DDR01AD0.Bits.DDR1AD00
#define DDR01AD0_DDR1AD01               _DDR01AD0.Bits.DDR1AD01
#define DDR01AD0_DDR1AD02               _DDR01AD0.Bits.DDR1AD02
#define DDR01AD0_DDR1AD03               _DDR01AD0.Bits.DDR1AD03
#define DDR01AD0_DDR1AD04               _DDR01AD0.Bits.DDR1AD04
#define DDR01AD0_DDR1AD05               _DDR01AD0.Bits.DDR1AD05
#define DDR01AD0_DDR1AD06               _DDR01AD0.Bits.DDR1AD06
#define DDR01AD0_DDR1AD07               _DDR01AD0.Bits.DDR1AD07
#define DDR01AD0_DDR0AD00               _DDR01AD0.Bits.DDR0AD00
#define DDR01AD0_DDR0AD01               _DDR01AD0.Bits.DDR0AD01
#define DDR01AD0_DDR0AD02               _DDR01AD0.Bits.DDR0AD02
#define DDR01AD0_DDR0AD03               _DDR01AD0.Bits.DDR0AD03
#define DDR01AD0_DDR0AD04               _DDR01AD0.Bits.DDR0AD04
#define DDR01AD0_DDR0AD05               _DDR01AD0.Bits.DDR0AD05
#define DDR01AD0_DDR0AD06               _DDR01AD0.Bits.DDR0AD06
#define DDR01AD0_DDR0AD07               _DDR01AD0.Bits.DDR0AD07
#define DDR01AD0_DDR1AD0                _DDR01AD0.MergedBits.grpDDR1AD0
#define DDR01AD0_DDR0AD0                _DDR01AD0.MergedBits.grpDDR0AD0

#define DDR01AD0_DDR1AD00_MASK          1U
#define DDR01AD0_DDR1AD01_MASK          2U
#define DDR01AD0_DDR1AD02_MASK          4U
#define DDR01AD0_DDR1AD03_MASK          8U
#define DDR01AD0_DDR1AD04_MASK          16U
#define DDR01AD0_DDR1AD05_MASK          32U
#define DDR01AD0_DDR1AD06_MASK          64U
#define DDR01AD0_DDR1AD07_MASK          128U
#define DDR01AD0_DDR0AD00_MASK          256U
#define DDR01AD0_DDR0AD01_MASK          512U
#define DDR01AD0_DDR0AD02_MASK          1024U
#define DDR01AD0_DDR0AD03_MASK          2048U
#define DDR01AD0_DDR0AD04_MASK          4096U
#define DDR01AD0_DDR0AD05_MASK          8192U
#define DDR01AD0_DDR0AD06_MASK          16384U
#define DDR01AD0_DDR0AD07_MASK          32768U
#define DDR01AD0_DDR1AD0_MASK           255U
#define DDR01AD0_DDR1AD0_BITNUM         0U
#define DDR01AD0_DDR0AD0_MASK           65280U
#define DDR01AD0_DDR0AD0_BITNUM         8U


/*** RDR01AD0 - Port AD0 Reduced Drive Register; 0x00000274 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** RDR0AD0 - Port AD0H Reduced Drive Register; 0x00000274 ***/
    union {
      byte Byte;
      struct {
        byte RDR0AD00    :1;                                       /* Port AD0H reduced drive bit 0 */
        byte RDR0AD01    :1;                                       /* Port AD0H reduced drive bit 1 */
        byte RDR0AD02    :1;                                       /* Port AD0H reduced drive bit 2 */
        byte RDR0AD03    :1;                                       /* Port AD0H reduced drive bit 3 */
        byte RDR0AD04    :1;                                       /* Port AD0H reduced drive bit 4 */
        byte RDR0AD05    :1;                                       /* Port AD0H reduced drive bit 5 */
        byte RDR0AD06    :1;                                       /* Port AD0H reduced drive bit 6 */
        byte RDR0AD07    :1;                                       /* Port AD0H reduced drive bit 7 */
      } Bits;
    } RDR0AD0STR;
    #define RDR0AD0                     _RDR01AD0.Overlap_STR.RDR0AD0STR.Byte
    #define RDR0AD0_RDR0AD00            _RDR01AD0.Overlap_STR.RDR0AD0STR.Bits.RDR0AD00
    #define RDR0AD0_RDR0AD01            _RDR01AD0.Overlap_STR.RDR0AD0STR.Bits.RDR0AD01
    #define RDR0AD0_RDR0AD02            _RDR01AD0.Overlap_STR.RDR0AD0STR.Bits.RDR0AD02
    #define RDR0AD0_RDR0AD03            _RDR01AD0.Overlap_STR.RDR0AD0STR.Bits.RDR0AD03
    #define RDR0AD0_RDR0AD04            _RDR01AD0.Overlap_STR.RDR0AD0STR.Bits.RDR0AD04
    #define RDR0AD0_RDR0AD05            _RDR01AD0.Overlap_STR.RDR0AD0STR.Bits.RDR0AD05
    #define RDR0AD0_RDR0AD06            _RDR01AD0.Overlap_STR.RDR0AD0STR.Bits.RDR0AD06
    #define RDR0AD0_RDR0AD07            _RDR01AD0.Overlap_STR.RDR0AD0STR.Bits.RDR0AD07
    
    #define RDR0AD0_RDR0AD00_MASK       1U
    #define RDR0AD0_RDR0AD01_MASK       2U
    #define RDR0AD0_RDR0AD02_MASK       4U
    #define RDR0AD0_RDR0AD03_MASK       8U
    #define RDR0AD0_RDR0AD04_MASK       16U
    #define RDR0AD0_RDR0AD05_MASK       32U
    #define RDR0AD0_RDR0AD06_MASK       64U
    #define RDR0AD0_RDR0AD07_MASK       128U
    

    /*** RDR1AD0 - Port AD0L Reduced Drive Register; 0x00000275 ***/
    union {
      byte Byte;
      struct {
        byte RDR1AD00    :1;                                       /* Port AD0L reduced drive bit 0 */
        byte RDR1AD01    :1;                                       /* Port AD0L reduced drive bit 1 */
        byte RDR1AD02    :1;                                       /* Port AD0L reduced drive bit 2 */
        byte RDR1AD03    :1;                                       /* Port AD0L reduced drive bit 3 */
        byte RDR1AD04    :1;                                       /* Port AD0L reduced drive bit 4 */
        byte RDR1AD05    :1;                                       /* Port AD0L reduced drive bit 5 */
        byte RDR1AD06    :1;                                       /* Port AD0L reduced drive bit 6 */
        byte RDR1AD07    :1;                                       /* Port AD0L reduced drive bit 7 */
      } Bits;
    } RDR1AD0STR;
    #define RDR1AD0                     _RDR01AD0.Overlap_STR.RDR1AD0STR.Byte
    #define RDR1AD0_RDR1AD00            _RDR01AD0.Overlap_STR.RDR1AD0STR.Bits.RDR1AD00
    #define RDR1AD0_RDR1AD01            _RDR01AD0.Overlap_STR.RDR1AD0STR.Bits.RDR1AD01
    #define RDR1AD0_RDR1AD02            _RDR01AD0.Overlap_STR.RDR1AD0STR.Bits.RDR1AD02
    #define RDR1AD0_RDR1AD03            _RDR01AD0.Overlap_STR.RDR1AD0STR.Bits.RDR1AD03
    #define RDR1AD0_RDR1AD04            _RDR01AD0.Overlap_STR.RDR1AD0STR.Bits.RDR1AD04
    #define RDR1AD0_RDR1AD05            _RDR01AD0.Overlap_STR.RDR1AD0STR.Bits.RDR1AD05
    #define RDR1AD0_RDR1AD06            _RDR01AD0.Overlap_STR.RDR1AD0STR.Bits.RDR1AD06
    #define RDR1AD0_RDR1AD07            _RDR01AD0.Overlap_STR.RDR1AD0STR.Bits.RDR1AD07
    
    #define RDR1AD0_RDR1AD00_MASK       1U
    #define RDR1AD0_RDR1AD01_MASK       2U
    #define RDR1AD0_RDR1AD02_MASK       4U
    #define RDR1AD0_RDR1AD03_MASK       8U
    #define RDR1AD0_RDR1AD04_MASK       16U
    #define RDR1AD0_RDR1AD05_MASK       32U
    #define RDR1AD0_RDR1AD06_MASK       64U
    #define RDR1AD0_RDR1AD07_MASK       128U
    
  } Overlap_STR;

  struct {
    word RDR1AD00    :1;                                       /* Port AD0 reduced drive bit 0 */
    word RDR1AD01    :1;                                       /* Port AD0 reduced drive bit 1 */
    word RDR1AD02    :1;                                       /* Port AD0 reduced drive bit 2 */
    word RDR1AD03    :1;                                       /* Port AD0 reduced drive bit 3 */
    word RDR1AD04    :1;                                       /* Port AD0 reduced drive bit 4 */
    word RDR1AD05    :1;                                       /* Port AD0 reduced drive bit 5 */
    word RDR1AD06    :1;                                       /* Port AD0 reduced drive bit 6 */
    word RDR1AD07    :1;                                       /* Port AD0 reduced drive bit 7 */
    word RDR0AD00    :1;                                       /* Port AD0 reduced drive bit 8 */
    word RDR0AD01    :1;                                       /* Port AD0 reduced drive bit 9 */
    word RDR0AD02    :1;                                       /* Port AD0 reduced drive bit 10 */
    word RDR0AD03    :1;                                       /* Port AD0 reduced drive bit 11 */
    word RDR0AD04    :1;                                       /* Port AD0 reduced drive bit 12 */
    word RDR0AD05    :1;                                       /* Port AD0 reduced drive bit 13 */
    word RDR0AD06    :1;                                       /* Port AD0 reduced drive bit 14 */
    word RDR0AD07    :1;                                       /* Port AD0 reduced drive bit 15 */
  } Bits;
  struct {
    word grpRDR1AD0 :8;
    word grpRDR0AD0 :8;
  } MergedBits;
} RDR01AD0STR;
extern volatile RDR01AD0STR _RDR01AD0 @(REG_BASE + 0x00000274UL);
#define RDR01AD0                        _RDR01AD0.Word
#define RDR01AD0_RDR1AD00               _RDR01AD0.Bits.RDR1AD00
#define RDR01AD0_RDR1AD01               _RDR01AD0.Bits.RDR1AD01
#define RDR01AD0_RDR1AD02               _RDR01AD0.Bits.RDR1AD02
#define RDR01AD0_RDR1AD03               _RDR01AD0.Bits.RDR1AD03
#define RDR01AD0_RDR1AD04               _RDR01AD0.Bits.RDR1AD04
#define RDR01AD0_RDR1AD05               _RDR01AD0.Bits.RDR1AD05
#define RDR01AD0_RDR1AD06               _RDR01AD0.Bits.RDR1AD06
#define RDR01AD0_RDR1AD07               _RDR01AD0.Bits.RDR1AD07
#define RDR01AD0_RDR0AD00               _RDR01AD0.Bits.RDR0AD00
#define RDR01AD0_RDR0AD01               _RDR01AD0.Bits.RDR0AD01
#define RDR01AD0_RDR0AD02               _RDR01AD0.Bits.RDR0AD02
#define RDR01AD0_RDR0AD03               _RDR01AD0.Bits.RDR0AD03
#define RDR01AD0_RDR0AD04               _RDR01AD0.Bits.RDR0AD04
#define RDR01AD0_RDR0AD05               _RDR01AD0.Bits.RDR0AD05
#define RDR01AD0_RDR0AD06               _RDR01AD0.Bits.RDR0AD06
#define RDR01AD0_RDR0AD07               _RDR01AD0.Bits.RDR0AD07
#define RDR01AD0_RDR1AD0                _RDR01AD0.MergedBits.grpRDR1AD0
#define RDR01AD0_RDR0AD0                _RDR01AD0.MergedBits.grpRDR0AD0

#define RDR01AD0_RDR1AD00_MASK          1U
#define RDR01AD0_RDR1AD01_MASK          2U
#define RDR01AD0_RDR1AD02_MASK          4U
#define RDR01AD0_RDR1AD03_MASK          8U
#define RDR01AD0_RDR1AD04_MASK          16U
#define RDR01AD0_RDR1AD05_MASK          32U
#define RDR01AD0_RDR1AD06_MASK          64U
#define RDR01AD0_RDR1AD07_MASK          128U
#define RDR01AD0_RDR0AD00_MASK          256U
#define RDR01AD0_RDR0AD01_MASK          512U
#define RDR01AD0_RDR0AD02_MASK          1024U
#define RDR01AD0_RDR0AD03_MASK          2048U
#define RDR01AD0_RDR0AD04_MASK          4096U
#define RDR01AD0_RDR0AD05_MASK          8192U
#define RDR01AD0_RDR0AD06_MASK          16384U
#define RDR01AD0_RDR0AD07_MASK          32768U
#define RDR01AD0_RDR1AD0_MASK           255U
#define RDR01AD0_RDR1AD0_BITNUM         0U
#define RDR01AD0_RDR0AD0_MASK           65280U
#define RDR01AD0_RDR0AD0_BITNUM         8U


/*** PER01AD0 - Port AD0 Pull Up Enable Register; 0x00000276 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PER0AD0 - Port AD0H Pull Up Enable Register; 0x00000276 ***/
    union {
      byte Byte;
      struct {
        byte PER0AD00    :1;                                       /* Port AD0H pull up enable bit 0 */
        byte PER0AD01    :1;                                       /* Port AD0H pull up enable bit 1 */
        byte PER0AD02    :1;                                       /* Port AD0H pull up enable bit 2 */
        byte PER0AD03    :1;                                       /* Port AD0H pull up enable bit 3 */
        byte PER0AD04    :1;                                       /* Port AD0H pull up enable bit 4 */
        byte PER0AD05    :1;                                       /* Port AD0H pull up enable bit 5 */
        byte PER0AD06    :1;                                       /* Port AD0H pull up enable bit 6 */
        byte PER0AD07    :1;                                       /* Port AD0H pull up enable bit 7 */
      } Bits;
    } PER0AD0STR;
    #define PER0AD0                     _PER01AD0.Overlap_STR.PER0AD0STR.Byte
    #define PER0AD0_PER0AD00            _PER01AD0.Overlap_STR.PER0AD0STR.Bits.PER0AD00
    #define PER0AD0_PER0AD01            _PER01AD0.Overlap_STR.PER0AD0STR.Bits.PER0AD01
    #define PER0AD0_PER0AD02            _PER01AD0.Overlap_STR.PER0AD0STR.Bits.PER0AD02
    #define PER0AD0_PER0AD03            _PER01AD0.Overlap_STR.PER0AD0STR.Bits.PER0AD03
    #define PER0AD0_PER0AD04            _PER01AD0.Overlap_STR.PER0AD0STR.Bits.PER0AD04
    #define PER0AD0_PER0AD05            _PER01AD0.Overlap_STR.PER0AD0STR.Bits.PER0AD05
    #define PER0AD0_PER0AD06            _PER01AD0.Overlap_STR.PER0AD0STR.Bits.PER0AD06
    #define PER0AD0_PER0AD07            _PER01AD0.Overlap_STR.PER0AD0STR.Bits.PER0AD07
    
    #define PER0AD0_PER0AD00_MASK       1U
    #define PER0AD0_PER0AD01_MASK       2U
    #define PER0AD0_PER0AD02_MASK       4U
    #define PER0AD0_PER0AD03_MASK       8U
    #define PER0AD0_PER0AD04_MASK       16U
    #define PER0AD0_PER0AD05_MASK       32U
    #define PER0AD0_PER0AD06_MASK       64U
    #define PER0AD0_PER0AD07_MASK       128U
    

    /*** PER1AD0 - Port AD0L Pull Up Enable Register; 0x00000277 ***/
    union {
      byte Byte;
      struct {
        byte PER1AD00    :1;                                       /* Port AD0L pull up enable bit 0 */
        byte PER1AD01    :1;                                       /* Port AD0L pull up enable bit 1 */
        byte PER1AD02    :1;                                       /* Port AD0L pull up enable bit 2 */
        byte PER1AD03    :1;                                       /* Port AD0L pull up enable bit 3 */
        byte PER1AD04    :1;                                       /* Port AD0L pull up enable bit 4 */
        byte PER1AD05    :1;                                       /* Port AD0L pull up enable bit 5 */
        byte PER1AD06    :1;                                       /* Port AD0L pull up enable bit 6 */
        byte PER1AD07    :1;                                       /* Port AD0L pull up enable bit 7 */
      } Bits;
    } PER1AD0STR;
    #define PER1AD0                     _PER01AD0.Overlap_STR.PER1AD0STR.Byte
    #define PER1AD0_PER1AD00            _PER01AD0.Overlap_STR.PER1AD0STR.Bits.PER1AD00
    #define PER1AD0_PER1AD01            _PER01AD0.Overlap_STR.PER1AD0STR.Bits.PER1AD01
    #define PER1AD0_PER1AD02            _PER01AD0.Overlap_STR.PER1AD0STR.Bits.PER1AD02
    #define PER1AD0_PER1AD03            _PER01AD0.Overlap_STR.PER1AD0STR.Bits.PER1AD03
    #define PER1AD0_PER1AD04            _PER01AD0.Overlap_STR.PER1AD0STR.Bits.PER1AD04
    #define PER1AD0_PER1AD05            _PER01AD0.Overlap_STR.PER1AD0STR.Bits.PER1AD05
    #define PER1AD0_PER1AD06            _PER01AD0.Overlap_STR.PER1AD0STR.Bits.PER1AD06
    #define PER1AD0_PER1AD07            _PER01AD0.Overlap_STR.PER1AD0STR.Bits.PER1AD07
    
    #define PER1AD0_PER1AD00_MASK       1U
    #define PER1AD0_PER1AD01_MASK       2U
    #define PER1AD0_PER1AD02_MASK       4U
    #define PER1AD0_PER1AD03_MASK       8U
    #define PER1AD0_PER1AD04_MASK       16U
    #define PER1AD0_PER1AD05_MASK       32U
    #define PER1AD0_PER1AD06_MASK       64U
    #define PER1AD0_PER1AD07_MASK       128U
    
  } Overlap_STR;

  struct {
    word PER1AD00    :1;                                       /* Port AD0 pull up enable bit 0 */
    word PER1AD01    :1;                                       /* Port AD0 pull up enable bit 1 */
    word PER1AD02    :1;                                       /* Port AD0 pull up enable bit 2 */
    word PER1AD03    :1;                                       /* Port AD0 pull up enable bit 3 */
    word PER1AD04    :1;                                       /* Port AD0 pull up enable bit 4 */
    word PER1AD05    :1;                                       /* Port AD0 pull up enable bit 5 */
    word PER1AD06    :1;                                       /* Port AD0 pull up enable bit 6 */
    word PER1AD07    :1;                                       /* Port AD0 pull up enable bit 7 */
    word PER0AD00    :1;                                       /* Port AD0 pull up enable bit 8 */
    word PER0AD01    :1;                                       /* Port AD0 pull up enable bit 9 */
    word PER0AD02    :1;                                       /* Port AD0 pull up enable bit 10 */
    word PER0AD03    :1;                                       /* Port AD0 pull up enable bit 11 */
    word PER0AD04    :1;                                       /* Port AD0 pull up enable bit 12 */
    word PER0AD05    :1;                                       /* Port AD0 pull up enable bit 13 */
    word PER0AD06    :1;                                       /* Port AD0 pull up enable bit 14 */
    word PER0AD07    :1;                                       /* Port AD0 pull up enable bit 15 */
  } Bits;
  struct {
    word grpPER1AD0 :8;
    word grpPER0AD0 :8;
  } MergedBits;
} PER01AD0STR;
extern volatile PER01AD0STR _PER01AD0 @(REG_BASE + 0x00000276UL);
#define PER01AD0                        _PER01AD0.Word
#define PER01AD0_PER1AD00               _PER01AD0.Bits.PER1AD00
#define PER01AD0_PER1AD01               _PER01AD0.Bits.PER1AD01
#define PER01AD0_PER1AD02               _PER01AD0.Bits.PER1AD02
#define PER01AD0_PER1AD03               _PER01AD0.Bits.PER1AD03
#define PER01AD0_PER1AD04               _PER01AD0.Bits.PER1AD04
#define PER01AD0_PER1AD05               _PER01AD0.Bits.PER1AD05
#define PER01AD0_PER1AD06               _PER01AD0.Bits.PER1AD06
#define PER01AD0_PER1AD07               _PER01AD0.Bits.PER1AD07
#define PER01AD0_PER0AD00               _PER01AD0.Bits.PER0AD00
#define PER01AD0_PER0AD01               _PER01AD0.Bits.PER0AD01
#define PER01AD0_PER0AD02               _PER01AD0.Bits.PER0AD02
#define PER01AD0_PER0AD03               _PER01AD0.Bits.PER0AD03
#define PER01AD0_PER0AD04               _PER01AD0.Bits.PER0AD04
#define PER01AD0_PER0AD05               _PER01AD0.Bits.PER0AD05
#define PER01AD0_PER0AD06               _PER01AD0.Bits.PER0AD06
#define PER01AD0_PER0AD07               _PER01AD0.Bits.PER0AD07
#define PER01AD0_PER1AD0                _PER01AD0.MergedBits.grpPER1AD0
#define PER01AD0_PER0AD0                _PER01AD0.MergedBits.grpPER0AD0

#define PER01AD0_PER1AD00_MASK          1U
#define PER01AD0_PER1AD01_MASK          2U
#define PER01AD0_PER1AD02_MASK          4U
#define PER01AD0_PER1AD03_MASK          8U
#define PER01AD0_PER1AD04_MASK          16U
#define PER01AD0_PER1AD05_MASK          32U
#define PER01AD0_PER1AD06_MASK          64U
#define PER01AD0_PER1AD07_MASK          128U
#define PER01AD0_PER0AD00_MASK          256U
#define PER01AD0_PER0AD01_MASK          512U
#define PER01AD0_PER0AD02_MASK          1024U
#define PER01AD0_PER0AD03_MASK          2048U
#define PER01AD0_PER0AD04_MASK          4096U
#define PER01AD0_PER0AD05_MASK          8192U
#define PER01AD0_PER0AD06_MASK          16384U
#define PER01AD0_PER0AD07_MASK          32768U
#define PER01AD0_PER1AD0_MASK           255U
#define PER01AD0_PER1AD0_BITNUM         0U
#define PER01AD0_PER0AD0_MASK           65280U
#define PER01AD0_PER0AD0_BITNUM         8U


/*** ATD0CTL01 - ATD 0 Control Register 01; 0x000002C0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0CTL0 - ATD 0 Control Register 0; 0x000002C0 ***/
    union {
      byte Byte;
      struct {
        byte WRAP0       :1;                                       /* Wrap Around Channel Select Bit 0 */
        byte WRAP1       :1;                                       /* Wrap Around Channel Select Bit 1 */
        byte WRAP2       :1;                                       /* Wrap Around Channel Select Bit 2 */
        byte WRAP3       :1;                                       /* Wrap Around Channel Select Bit 3 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpWRAP :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATD0CTL0STR;
    #define ATD0CTL0                    _ATD0CTL01.Overlap_STR.ATD0CTL0STR.Byte
    #define ATD0CTL0_WRAP0              _ATD0CTL01.Overlap_STR.ATD0CTL0STR.Bits.WRAP0
    #define ATD0CTL0_WRAP1              _ATD0CTL01.Overlap_STR.ATD0CTL0STR.Bits.WRAP1
    #define ATD0CTL0_WRAP2              _ATD0CTL01.Overlap_STR.ATD0CTL0STR.Bits.WRAP2
    #define ATD0CTL0_WRAP3              _ATD0CTL01.Overlap_STR.ATD0CTL0STR.Bits.WRAP3
    /* ATD0CTL_ARR: Access 6 ATD0CTLx registers in an array */
    #define ATD0CTL_ARR                 ((volatile byte *) &ATD0CTL0)
    #define ATD0CTL0_WRAP               _ATD0CTL01.Overlap_STR.ATD0CTL0STR.MergedBits.grpWRAP
    
    #define ATD0CTL0_WRAP0_MASK         1U
    #define ATD0CTL0_WRAP1_MASK         2U
    #define ATD0CTL0_WRAP2_MASK         4U
    #define ATD0CTL0_WRAP3_MASK         8U
    #define ATD0CTL0_WRAP_MASK          15U
    #define ATD0CTL0_WRAP_BITNUM        0U
    

    /*** ATD0CTL1 - ATD 0 Control Register 1; 0x000002C1 ***/
    union {
      byte Byte;
      struct {
        byte ETRIGCH0    :1;                                       /* External Trigger Channel Select Bit 0 */
        byte ETRIGCH1    :1;                                       /* External Trigger Channel Select Bit 1 */
        byte ETRIGCH2    :1;                                       /* External Trigger Channel Select Bit 2 */
        byte ETRIGCH3    :1;                                       /* External Trigger Channel Select Bit 3 */
        byte SMP_DIS     :1;                                       /* Discharge Before Sampling Bit */
        byte SRES0       :1;                                       /* A/D Resolution Select Bit 0 */
        byte SRES1       :1;                                       /* A/D Resolution Select Bit 1 */
        byte ETRIGSEL    :1;                                       /* External Trigger Source Select */
      } Bits;
      struct {
        byte grpETRIGCH :4;
        byte     :1;
        byte grpSRES :2;
        byte     :1;
      } MergedBits;
    } ATD0CTL1STR;
    #define ATD0CTL1                    _ATD0CTL01.Overlap_STR.ATD0CTL1STR.Byte
    #define ATD0CTL1_ETRIGCH0           _ATD0CTL01.Overlap_STR.ATD0CTL1STR.Bits.ETRIGCH0
    #define ATD0CTL1_ETRIGCH1           _ATD0CTL01.Overlap_STR.ATD0CTL1STR.Bits.ETRIGCH1
    #define ATD0CTL1_ETRIGCH2           _ATD0CTL01.Overlap_STR.ATD0CTL1STR.Bits.ETRIGCH2
    #define ATD0CTL1_ETRIGCH3           _ATD0CTL01.Overlap_STR.ATD0CTL1STR.Bits.ETRIGCH3
    #define ATD0CTL1_SMP_DIS            _ATD0CTL01.Overlap_STR.ATD0CTL1STR.Bits.SMP_DIS
    #define ATD0CTL1_SRES0              _ATD0CTL01.Overlap_STR.ATD0CTL1STR.Bits.SRES0
    #define ATD0CTL1_SRES1              _ATD0CTL01.Overlap_STR.ATD0CTL1STR.Bits.SRES1
    #define ATD0CTL1_ETRIGSEL           _ATD0CTL01.Overlap_STR.ATD0CTL1STR.Bits.ETRIGSEL
    #define ATD0CTL1_ETRIGCH            _ATD0CTL01.Overlap_STR.ATD0CTL1STR.MergedBits.grpETRIGCH
    #define ATD0CTL1_SRES               _ATD0CTL01.Overlap_STR.ATD0CTL1STR.MergedBits.grpSRES
    
    #define ATD0CTL1_ETRIGCH0_MASK      1U
    #define ATD0CTL1_ETRIGCH1_MASK      2U
    #define ATD0CTL1_ETRIGCH2_MASK      4U
    #define ATD0CTL1_ETRIGCH3_MASK      8U
    #define ATD0CTL1_SMP_DIS_MASK       16U
    #define ATD0CTL1_SRES0_MASK         32U
    #define ATD0CTL1_SRES1_MASK         64U
    #define ATD0CTL1_ETRIGSEL_MASK      128U
    #define ATD0CTL1_ETRIGCH_MASK       15U
    #define ATD0CTL1_ETRIGCH_BITNUM     0U
    #define ATD0CTL1_SRES_MASK          96U
    #define ATD0CTL1_SRES_BITNUM        5U
    
  } Overlap_STR;

  struct {
    word ETRIGCH0    :1;                                       /* External Trigger Channel Select Bit 0 */
    word ETRIGCH1    :1;                                       /* External Trigger Channel Select Bit 1 */
    word ETRIGCH2    :1;                                       /* External Trigger Channel Select Bit 2 */
    word ETRIGCH3    :1;                                       /* External Trigger Channel Select Bit 3 */
    word SMP_DIS     :1;                                       /* Discharge Before Sampling Bit */
    word SRES0       :1;                                       /* A/D Resolution Select Bit 0 */
    word SRES1       :1;                                       /* A/D Resolution Select Bit 1 */
    word ETRIGSEL    :1;                                       /* External Trigger Source Select */
    word WRAP0       :1;                                       /* Wrap Around Channel Select Bit 0 */
    word WRAP1       :1;                                       /* Wrap Around Channel Select Bit 1 */
    word WRAP2       :1;                                       /* Wrap Around Channel Select Bit 2 */
    word WRAP3       :1;                                       /* Wrap Around Channel Select Bit 3 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpETRIGCH :4;
    word         :1;
    word grpSRES :2;
    word         :1;
    word grpWRAP :4;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATD0CTL01STR;
extern volatile ATD0CTL01STR _ATD0CTL01 @(REG_BASE + 0x000002C0UL);
#define ATD0CTL01                       _ATD0CTL01.Word
#define ATD0CTL01_ETRIGCH0              _ATD0CTL01.Bits.ETRIGCH0
#define ATD0CTL01_ETRIGCH1              _ATD0CTL01.Bits.ETRIGCH1
#define ATD0CTL01_ETRIGCH2              _ATD0CTL01.Bits.ETRIGCH2
#define ATD0CTL01_ETRIGCH3              _ATD0CTL01.Bits.ETRIGCH3
#define ATD0CTL01_SMP_DIS               _ATD0CTL01.Bits.SMP_DIS
#define ATD0CTL01_SRES0                 _ATD0CTL01.Bits.SRES0
#define ATD0CTL01_SRES1                 _ATD0CTL01.Bits.SRES1
#define ATD0CTL01_ETRIGSEL              _ATD0CTL01.Bits.ETRIGSEL
#define ATD0CTL01_WRAP0                 _ATD0CTL01.Bits.WRAP0
#define ATD0CTL01_WRAP1                 _ATD0CTL01.Bits.WRAP1
#define ATD0CTL01_WRAP2                 _ATD0CTL01.Bits.WRAP2
#define ATD0CTL01_WRAP3                 _ATD0CTL01.Bits.WRAP3
#define ATD0CTL01_ETRIGCH               _ATD0CTL01.MergedBits.grpETRIGCH
#define ATD0CTL01_SRES                  _ATD0CTL01.MergedBits.grpSRES
#define ATD0CTL01_WRAP                  _ATD0CTL01.MergedBits.grpWRAP

#define ATD0CTL01_ETRIGCH0_MASK         1U
#define ATD0CTL01_ETRIGCH1_MASK         2U
#define ATD0CTL01_ETRIGCH2_MASK         4U
#define ATD0CTL01_ETRIGCH3_MASK         8U
#define ATD0CTL01_SMP_DIS_MASK          16U
#define ATD0CTL01_SRES0_MASK            32U
#define ATD0CTL01_SRES1_MASK            64U
#define ATD0CTL01_ETRIGSEL_MASK         128U
#define ATD0CTL01_WRAP0_MASK            256U
#define ATD0CTL01_WRAP1_MASK            512U
#define ATD0CTL01_WRAP2_MASK            1024U
#define ATD0CTL01_WRAP3_MASK            2048U
#define ATD0CTL01_ETRIGCH_MASK          15U
#define ATD0CTL01_ETRIGCH_BITNUM        0U
#define ATD0CTL01_SRES_MASK             96U
#define ATD0CTL01_SRES_BITNUM           5U
#define ATD0CTL01_WRAP_MASK             3840U
#define ATD0CTL01_WRAP_BITNUM           8U


/*** ATD0CTL23 - ATD 0 Control Register 23; 0x000002C2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0CTL2 - ATD 0 Control Register 2; 0x000002C2 ***/
    union {
      byte Byte;
      struct {
        byte ACMPIE      :1;                                       /* ATD Compare Interrupt Enable */
        byte ASCIE       :1;                                       /* ATD Sequence Complete Interrupt Enable */
        byte ETRIGE      :1;                                       /* External Trigger Mode enable */
        byte ETRIGP      :1;                                       /* External Trigger Polarity */
        byte ETRIGLE     :1;                                       /* External Trigger Level/Edge control */
        byte ICLKSTP     :1;                                       /* Internal Clock in Stop Mode Bit */
        byte AFFC        :1;                                       /* ATD Fast Conversion Complete Flag Clear */
        byte             :1; 
      } Bits;
    } ATD0CTL2STR;
    #define ATD0CTL2                    _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Byte
    #define ATD0CTL2_ACMPIE             _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ACMPIE
    #define ATD0CTL2_ASCIE              _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ASCIE
    #define ATD0CTL2_ETRIGE             _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ETRIGE
    #define ATD0CTL2_ETRIGP             _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ETRIGP
    #define ATD0CTL2_ETRIGLE            _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ETRIGLE
    #define ATD0CTL2_ICLKSTP            _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.ICLKSTP
    #define ATD0CTL2_AFFC               _ATD0CTL23.Overlap_STR.ATD0CTL2STR.Bits.AFFC
    
    #define ATD0CTL2_ACMPIE_MASK        1U
    #define ATD0CTL2_ASCIE_MASK         2U
    #define ATD0CTL2_ETRIGE_MASK        4U
    #define ATD0CTL2_ETRIGP_MASK        8U
    #define ATD0CTL2_ETRIGLE_MASK       16U
    #define ATD0CTL2_ICLKSTP_MASK       32U
    #define ATD0CTL2_AFFC_MASK          64U
    

    /*** ATD0CTL3 - ATD 0 Control Register 3; 0x000002C3 ***/
    union {
      byte Byte;
      struct {
        byte FRZ0        :1;                                       /* Background Debug Freeze Enable Bit 0 */
        byte FRZ1        :1;                                       /* Background Debug Freeze Enable Bit 1 */
        byte FIFO        :1;                                       /* Result Register FIFO Mode */
        byte S1C         :1;                                       /* Conversion Sequence Length 1 */
        byte S2C         :1;                                       /* Conversion Sequence Length 2 */
        byte S4C         :1;                                       /* Conversion Sequence Length 4 */
        byte S8C         :1;                                       /* Conversion Sequence Length 8 */
        byte DJM         :1;                                       /* Result Register Data Justification */
      } Bits;
      struct {
        byte grpFRZ :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATD0CTL3STR;
    #define ATD0CTL3                    _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Byte
    #define ATD0CTL3_FRZ0               _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.FRZ0
    #define ATD0CTL3_FRZ1               _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.FRZ1
    #define ATD0CTL3_FIFO               _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.FIFO
    #define ATD0CTL3_S1C                _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.S1C
    #define ATD0CTL3_S2C                _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.S2C
    #define ATD0CTL3_S4C                _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.S4C
    #define ATD0CTL3_S8C                _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.S8C
    #define ATD0CTL3_DJM                _ATD0CTL23.Overlap_STR.ATD0CTL3STR.Bits.DJM
    #define ATD0CTL3_FRZ                _ATD0CTL23.Overlap_STR.ATD0CTL3STR.MergedBits.grpFRZ
    
    #define ATD0CTL3_FRZ0_MASK          1U
    #define ATD0CTL3_FRZ1_MASK          2U
    #define ATD0CTL3_FIFO_MASK          4U
    #define ATD0CTL3_S1C_MASK           8U
    #define ATD0CTL3_S2C_MASK           16U
    #define ATD0CTL3_S4C_MASK           32U
    #define ATD0CTL3_S8C_MASK           64U
    #define ATD0CTL3_DJM_MASK           128U
    #define ATD0CTL3_FRZ_MASK           3U
    #define ATD0CTL3_FRZ_BITNUM         0U
    
  } Overlap_STR;

  struct {
    word FRZ0        :1;                                       /* Background Debug Freeze Enable Bit 0 */
    word FRZ1        :1;                                       /* Background Debug Freeze Enable Bit 1 */
    word FIFO        :1;                                       /* Result Register FIFO Mode */
    word S1C         :1;                                       /* Conversion Sequence Length 1 */
    word S2C         :1;                                       /* Conversion Sequence Length 2 */
    word S4C         :1;                                       /* Conversion Sequence Length 4 */
    word S8C         :1;                                       /* Conversion Sequence Length 8 */
    word DJM         :1;                                       /* Result Register Data Justification */
    word ACMPIE      :1;                                       /* ATD Compare Interrupt Enable */
    word ASCIE       :1;                                       /* ATD Sequence Complete Interrupt Enable */
    word ETRIGE      :1;                                       /* External Trigger Mode enable */
    word ETRIGP      :1;                                       /* External Trigger Polarity */
    word ETRIGLE     :1;                                       /* External Trigger Level/Edge control */
    word ICLKSTP     :1;                                       /* Internal Clock in Stop Mode Bit */
    word AFFC        :1;                                       /* ATD Fast Conversion Complete Flag Clear */
    word             :1; 
  } Bits;
  struct {
    word grpFRZ  :2;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATD0CTL23STR;
extern volatile ATD0CTL23STR _ATD0CTL23 @(REG_BASE + 0x000002C2UL);
#define ATD0CTL23                       _ATD0CTL23.Word
#define ATD0CTL23_FRZ0                  _ATD0CTL23.Bits.FRZ0
#define ATD0CTL23_FRZ1                  _ATD0CTL23.Bits.FRZ1
#define ATD0CTL23_FIFO                  _ATD0CTL23.Bits.FIFO
#define ATD0CTL23_S1C                   _ATD0CTL23.Bits.S1C
#define ATD0CTL23_S2C                   _ATD0CTL23.Bits.S2C
#define ATD0CTL23_S4C                   _ATD0CTL23.Bits.S4C
#define ATD0CTL23_S8C                   _ATD0CTL23.Bits.S8C
#define ATD0CTL23_DJM                   _ATD0CTL23.Bits.DJM
#define ATD0CTL23_ACMPIE                _ATD0CTL23.Bits.ACMPIE
#define ATD0CTL23_ASCIE                 _ATD0CTL23.Bits.ASCIE
#define ATD0CTL23_ETRIGE                _ATD0CTL23.Bits.ETRIGE
#define ATD0CTL23_ETRIGP                _ATD0CTL23.Bits.ETRIGP
#define ATD0CTL23_ETRIGLE               _ATD0CTL23.Bits.ETRIGLE
#define ATD0CTL23_ICLKSTP               _ATD0CTL23.Bits.ICLKSTP
#define ATD0CTL23_AFFC                  _ATD0CTL23.Bits.AFFC
#define ATD0CTL23_FRZ                   _ATD0CTL23.MergedBits.grpFRZ

#define ATD0CTL23_FRZ0_MASK             1U
#define ATD0CTL23_FRZ1_MASK             2U
#define ATD0CTL23_FIFO_MASK             4U
#define ATD0CTL23_S1C_MASK              8U
#define ATD0CTL23_S2C_MASK              16U
#define ATD0CTL23_S4C_MASK              32U
#define ATD0CTL23_S8C_MASK              64U
#define ATD0CTL23_DJM_MASK              128U
#define ATD0CTL23_ACMPIE_MASK           256U
#define ATD0CTL23_ASCIE_MASK            512U
#define ATD0CTL23_ETRIGE_MASK           1024U
#define ATD0CTL23_ETRIGP_MASK           2048U
#define ATD0CTL23_ETRIGLE_MASK          4096U
#define ATD0CTL23_ICLKSTP_MASK          8192U
#define ATD0CTL23_AFFC_MASK             16384U
#define ATD0CTL23_FRZ_MASK              3U
#define ATD0CTL23_FRZ_BITNUM            0U


/*** ATD0CTL45 - ATD 0 Control Register 45; 0x000002C4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0CTL4 - ATD 0 Control Register 4; 0x000002C4 ***/
    union {
      byte Byte;
      struct {
        byte PRS0        :1;                                       /* ATD Clock Prescaler 0 */
        byte PRS1        :1;                                       /* ATD Clock Prescaler 1 */
        byte PRS2        :1;                                       /* ATD Clock Prescaler 2 */
        byte PRS3        :1;                                       /* ATD Clock Prescaler 3 */
        byte PRS4        :1;                                       /* ATD Clock Prescaler 4 */
        byte SMP0        :1;                                       /* Sample Time Select 0 */
        byte SMP1        :1;                                       /* Sample Time Select 1 */
        byte SMP2        :1;                                       /* Sample Time Select 2 */
      } Bits;
      struct {
        byte grpPRS :5;
        byte grpSMP :3;
      } MergedBits;
    } ATD0CTL4STR;
    #define ATD0CTL4                    _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Byte
    #define ATD0CTL4_PRS0               _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.PRS0
    #define ATD0CTL4_PRS1               _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.PRS1
    #define ATD0CTL4_PRS2               _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.PRS2
    #define ATD0CTL4_PRS3               _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.PRS3
    #define ATD0CTL4_PRS4               _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.PRS4
    #define ATD0CTL4_SMP0               _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.SMP0
    #define ATD0CTL4_SMP1               _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.SMP1
    #define ATD0CTL4_SMP2               _ATD0CTL45.Overlap_STR.ATD0CTL4STR.Bits.SMP2
    #define ATD0CTL4_PRS                _ATD0CTL45.Overlap_STR.ATD0CTL4STR.MergedBits.grpPRS
    #define ATD0CTL4_SMP                _ATD0CTL45.Overlap_STR.ATD0CTL4STR.MergedBits.grpSMP
    
    #define ATD0CTL4_PRS0_MASK          1U
    #define ATD0CTL4_PRS1_MASK          2U
    #define ATD0CTL4_PRS2_MASK          4U
    #define ATD0CTL4_PRS3_MASK          8U
    #define ATD0CTL4_PRS4_MASK          16U
    #define ATD0CTL4_SMP0_MASK          32U
    #define ATD0CTL4_SMP1_MASK          64U
    #define ATD0CTL4_SMP2_MASK          128U
    #define ATD0CTL4_PRS_MASK           31U
    #define ATD0CTL4_PRS_BITNUM         0U
    #define ATD0CTL4_SMP_MASK           224U
    #define ATD0CTL4_SMP_BITNUM         5U
    

    /*** ATD0CTL5 - ATD 0 Control Register 5; 0x000002C5 ***/
    union {
      byte Byte;
      struct {
        byte CA          :1;                                       /* Analog Input Channel Select Code A */
        byte CB          :1;                                       /* Analog Input Channel Select Code B */
        byte CC          :1;                                       /* Analog Input Channel Select Code C */
        byte CD          :1;                                       /* Analog Input Channel Select Code D */
        byte MULT        :1;                                       /* Multi-Channel Sample Mode */
        byte SCAN        :1;                                       /* Continuous Conversion Sequence Mode */
        byte SC          :1;                                       /* Special Channel Conversion Bit */
        byte             :1; 
      } Bits;
      struct {
        byte grpCx :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATD0CTL5STR;
    #define ATD0CTL5                    _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Byte
    #define ATD0CTL5_CA                 _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.CA
    #define ATD0CTL5_CB                 _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.CB
    #define ATD0CTL5_CC                 _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.CC
    #define ATD0CTL5_CD                 _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.CD
    #define ATD0CTL5_MULT               _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.MULT
    #define ATD0CTL5_SCAN               _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.SCAN
    #define ATD0CTL5_SC                 _ATD0CTL45.Overlap_STR.ATD0CTL5STR.Bits.SC
    #define ATD0CTL5_Cx                 _ATD0CTL45.Overlap_STR.ATD0CTL5STR.MergedBits.grpCx
    
    #define ATD0CTL5_CA_MASK            1U
    #define ATD0CTL5_CB_MASK            2U
    #define ATD0CTL5_CC_MASK            4U
    #define ATD0CTL5_CD_MASK            8U
    #define ATD0CTL5_MULT_MASK          16U
    #define ATD0CTL5_SCAN_MASK          32U
    #define ATD0CTL5_SC_MASK            64U
    #define ATD0CTL5_Cx_MASK            15U
    #define ATD0CTL5_Cx_BITNUM          0U
    
  } Overlap_STR;

  struct {
    word CA          :1;                                       /* Analog Input Channel Select Code A */
    word CB          :1;                                       /* Analog Input Channel Select Code B */
    word CC          :1;                                       /* Analog Input Channel Select Code C */
    word CD          :1;                                       /* Analog Input Channel Select Code D */
    word MULT        :1;                                       /* Multi-Channel Sample Mode */
    word SCAN        :1;                                       /* Continuous Conversion Sequence Mode */
    word SC          :1;                                       /* Special Channel Conversion Bit */
    word             :1; 
    word PRS0        :1;                                       /* ATD Clock Prescaler 0 */
    word PRS1        :1;                                       /* ATD Clock Prescaler 1 */
    word PRS2        :1;                                       /* ATD Clock Prescaler 2 */
    word PRS3        :1;                                       /* ATD Clock Prescaler 3 */
    word PRS4        :1;                                       /* ATD Clock Prescaler 4 */
    word SMP0        :1;                                       /* Sample Time Select 0 */
    word SMP1        :1;                                       /* Sample Time Select 1 */
    word SMP2        :1;                                       /* Sample Time Select 2 */
  } Bits;
  struct {
    word grpCx   :4;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpPRS  :5;
    word grpSMP  :3;
  } MergedBits;
} ATD0CTL45STR;
extern volatile ATD0CTL45STR _ATD0CTL45 @(REG_BASE + 0x000002C4UL);
#define ATD0CTL45                       _ATD0CTL45.Word
#define ATD0CTL45_CA                    _ATD0CTL45.Bits.CA
#define ATD0CTL45_CB                    _ATD0CTL45.Bits.CB
#define ATD0CTL45_CC                    _ATD0CTL45.Bits.CC
#define ATD0CTL45_CD                    _ATD0CTL45.Bits.CD
#define ATD0CTL45_MULT                  _ATD0CTL45.Bits.MULT
#define ATD0CTL45_SCAN                  _ATD0CTL45.Bits.SCAN
#define ATD0CTL45_SC                    _ATD0CTL45.Bits.SC
#define ATD0CTL45_PRS0                  _ATD0CTL45.Bits.PRS0
#define ATD0CTL45_PRS1                  _ATD0CTL45.Bits.PRS1
#define ATD0CTL45_PRS2                  _ATD0CTL45.Bits.PRS2
#define ATD0CTL45_PRS3                  _ATD0CTL45.Bits.PRS3
#define ATD0CTL45_PRS4                  _ATD0CTL45.Bits.PRS4
#define ATD0CTL45_SMP0                  _ATD0CTL45.Bits.SMP0
#define ATD0CTL45_SMP1                  _ATD0CTL45.Bits.SMP1
#define ATD0CTL45_SMP2                  _ATD0CTL45.Bits.SMP2
#define ATD0CTL45_Cx                    _ATD0CTL45.MergedBits.grpCx
#define ATD0CTL45_PRS                   _ATD0CTL45.MergedBits.grpPRS
#define ATD0CTL45_SMP                   _ATD0CTL45.MergedBits.grpSMP

#define ATD0CTL45_CA_MASK               1U
#define ATD0CTL45_CB_MASK               2U
#define ATD0CTL45_CC_MASK               4U
#define ATD0CTL45_CD_MASK               8U
#define ATD0CTL45_MULT_MASK             16U
#define ATD0CTL45_SCAN_MASK             32U
#define ATD0CTL45_SC_MASK               64U
#define ATD0CTL45_PRS0_MASK             256U
#define ATD0CTL45_PRS1_MASK             512U
#define ATD0CTL45_PRS2_MASK             1024U
#define ATD0CTL45_PRS3_MASK             2048U
#define ATD0CTL45_PRS4_MASK             4096U
#define ATD0CTL45_SMP0_MASK             8192U
#define ATD0CTL45_SMP1_MASK             16384U
#define ATD0CTL45_SMP2_MASK             32768U
#define ATD0CTL45_Cx_MASK               15U
#define ATD0CTL45_Cx_BITNUM             0U
#define ATD0CTL45_PRS_MASK              7936U
#define ATD0CTL45_PRS_BITNUM            8U
#define ATD0CTL45_SMP_MASK              57344U
#define ATD0CTL45_SMP_BITNUM            13U


/*** ATD0STAT0 - ATD 0 Status Register 0; 0x000002C6 ***/
typedef union {
  byte Byte;
  struct {
    byte CC0         :1;                                       /* Conversion Counter 0 */
    byte CC1         :1;                                       /* Conversion Counter 1 */
    byte CC2         :1;                                       /* Conversion Counter 2 */
    byte CC3         :1;                                       /* Conversion Counter 3 */
    byte FIFOR       :1;                                       /* FIFO Over Run Flag */
    byte ETORF       :1;                                       /* External Trigger Overrun Flag */
    byte             :1; 
    byte SCF         :1;                                       /* Sequence Complete Flag */
  } Bits;
  struct {
    byte grpCC   :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ATD0STAT0STR;
extern volatile ATD0STAT0STR _ATD0STAT0 @(REG_BASE + 0x000002C6UL);
#define ATD0STAT0                       _ATD0STAT0.Byte
#define ATD0STAT0_CC0                   _ATD0STAT0.Bits.CC0
#define ATD0STAT0_CC1                   _ATD0STAT0.Bits.CC1
#define ATD0STAT0_CC2                   _ATD0STAT0.Bits.CC2
#define ATD0STAT0_CC3                   _ATD0STAT0.Bits.CC3
#define ATD0STAT0_FIFOR                 _ATD0STAT0.Bits.FIFOR
#define ATD0STAT0_ETORF                 _ATD0STAT0.Bits.ETORF
#define ATD0STAT0_SCF                   _ATD0STAT0.Bits.SCF
#define ATD0STAT0_CC                    _ATD0STAT0.MergedBits.grpCC

#define ATD0STAT0_CC0_MASK              1U
#define ATD0STAT0_CC1_MASK              2U
#define ATD0STAT0_CC2_MASK              4U
#define ATD0STAT0_CC3_MASK              8U
#define ATD0STAT0_FIFOR_MASK            16U
#define ATD0STAT0_ETORF_MASK            32U
#define ATD0STAT0_SCF_MASK              128U
#define ATD0STAT0_CC_MASK               15U
#define ATD0STAT0_CC_BITNUM             0U


/*** ATD0CMPE - ATD 0 Compare Enable Register; 0x000002C8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0CMPEH - ATD 0 Compare Enable Register High; 0x000002C8 ***/
    union {
      byte Byte;
      struct {
        byte CMPE8       :1;                                       /* Compare Enable for Conversion Number 8 of a Sequence */
        byte CMPE9       :1;                                       /* Compare Enable for Conversion Number 9 of a Sequence */
        byte CMPE10      :1;                                       /* Compare Enable for Conversion Number 10 of a Sequence */
        byte CMPE11      :1;                                       /* Compare Enable for Conversion Number 11 of a Sequence */
        byte CMPE12      :1;                                       /* Compare Enable for Conversion Number 12 of a Sequence */
        byte CMPE13      :1;                                       /* Compare Enable for Conversion Number 13 of a Sequence */
        byte CMPE14      :1;                                       /* Compare Enable for Conversion Number 14 of a Sequence */
        byte CMPE15      :1;                                       /* Compare Enable for Conversion Number 15 of a Sequence */
      } Bits;
    } ATD0CMPEHSTR;
    #define ATD0CMPEH                   _ATD0CMPE.Overlap_STR.ATD0CMPEHSTR.Byte
    #define ATD0CMPEH_CMPE8             _ATD0CMPE.Overlap_STR.ATD0CMPEHSTR.Bits.CMPE8
    #define ATD0CMPEH_CMPE9             _ATD0CMPE.Overlap_STR.ATD0CMPEHSTR.Bits.CMPE9
    #define ATD0CMPEH_CMPE10            _ATD0CMPE.Overlap_STR.ATD0CMPEHSTR.Bits.CMPE10
    #define ATD0CMPEH_CMPE11            _ATD0CMPE.Overlap_STR.ATD0CMPEHSTR.Bits.CMPE11
    #define ATD0CMPEH_CMPE12            _ATD0CMPE.Overlap_STR.ATD0CMPEHSTR.Bits.CMPE12
    #define ATD0CMPEH_CMPE13            _ATD0CMPE.Overlap_STR.ATD0CMPEHSTR.Bits.CMPE13
    #define ATD0CMPEH_CMPE14            _ATD0CMPE.Overlap_STR.ATD0CMPEHSTR.Bits.CMPE14
    #define ATD0CMPEH_CMPE15            _ATD0CMPE.Overlap_STR.ATD0CMPEHSTR.Bits.CMPE15
    
    #define ATD0CMPEH_CMPE8_MASK        1U
    #define ATD0CMPEH_CMPE9_MASK        2U
    #define ATD0CMPEH_CMPE10_MASK       4U
    #define ATD0CMPEH_CMPE11_MASK       8U
    #define ATD0CMPEH_CMPE12_MASK       16U
    #define ATD0CMPEH_CMPE13_MASK       32U
    #define ATD0CMPEH_CMPE14_MASK       64U
    #define ATD0CMPEH_CMPE15_MASK       128U
    

    /*** ATD0CMPEL - ATD 0 Compare Enable Register Low; 0x000002C9 ***/
    union {
      byte Byte;
      struct {
        byte CMPE0       :1;                                       /* Compare Enable for Conversion Number 0 of a Sequence */
        byte CMPE1       :1;                                       /* Compare Enable for Conversion Number 1 of a Sequence */
        byte CMPE2       :1;                                       /* Compare Enable for Conversion Number 2 of a Sequence */
        byte CMPE3       :1;                                       /* Compare Enable for Conversion Number 3 of a Sequence */
        byte CMPE4       :1;                                       /* Compare Enable for Conversion Number 4 of a Sequence */
        byte CMPE5       :1;                                       /* Compare Enable for Conversion Number 5 of a Sequence */
        byte CMPE6       :1;                                       /* Compare Enable for Conversion Number 6 of a Sequence */
        byte CMPE7       :1;                                       /* Compare Enable for Conversion Number 7 of a Sequence */
      } Bits;
    } ATD0CMPELSTR;
    #define ATD0CMPEL                   _ATD0CMPE.Overlap_STR.ATD0CMPELSTR.Byte
    #define ATD0CMPEL_CMPE0             _ATD0CMPE.Overlap_STR.ATD0CMPELSTR.Bits.CMPE0
    #define ATD0CMPEL_CMPE1             _ATD0CMPE.Overlap_STR.ATD0CMPELSTR.Bits.CMPE1
    #define ATD0CMPEL_CMPE2             _ATD0CMPE.Overlap_STR.ATD0CMPELSTR.Bits.CMPE2
    #define ATD0CMPEL_CMPE3             _ATD0CMPE.Overlap_STR.ATD0CMPELSTR.Bits.CMPE3
    #define ATD0CMPEL_CMPE4             _ATD0CMPE.Overlap_STR.ATD0CMPELSTR.Bits.CMPE4
    #define ATD0CMPEL_CMPE5             _ATD0CMPE.Overlap_STR.ATD0CMPELSTR.Bits.CMPE5
    #define ATD0CMPEL_CMPE6             _ATD0CMPE.Overlap_STR.ATD0CMPELSTR.Bits.CMPE6
    #define ATD0CMPEL_CMPE7             _ATD0CMPE.Overlap_STR.ATD0CMPELSTR.Bits.CMPE7
    
    #define ATD0CMPEL_CMPE0_MASK        1U
    #define ATD0CMPEL_CMPE1_MASK        2U
    #define ATD0CMPEL_CMPE2_MASK        4U
    #define ATD0CMPEL_CMPE3_MASK        8U
    #define ATD0CMPEL_CMPE4_MASK        16U
    #define ATD0CMPEL_CMPE5_MASK        32U
    #define ATD0CMPEL_CMPE6_MASK        64U
    #define ATD0CMPEL_CMPE7_MASK        128U
    
  } Overlap_STR;

  struct {
    word CMPE0       :1;                                       /* Compare Enable for Conversion Number 0 of a Sequence */
    word CMPE1       :1;                                       /* Compare Enable for Conversion Number 1 of a Sequence */
    word CMPE2       :1;                                       /* Compare Enable for Conversion Number 2 of a Sequence */
    word CMPE3       :1;                                       /* Compare Enable for Conversion Number 3 of a Sequence */
    word CMPE4       :1;                                       /* Compare Enable for Conversion Number 4 of a Sequence */
    word CMPE5       :1;                                       /* Compare Enable for Conversion Number 5 of a Sequence */
    word CMPE6       :1;                                       /* Compare Enable for Conversion Number 6 of a Sequence */
    word CMPE7       :1;                                       /* Compare Enable for Conversion Number 7 of a Sequence */
    word CMPE8       :1;                                       /* Compare Enable for Conversion Number 8 of a Sequence */
    word CMPE9       :1;                                       /* Compare Enable for Conversion Number 9 of a Sequence */
    word CMPE10      :1;                                       /* Compare Enable for Conversion Number 10 of a Sequence */
    word CMPE11      :1;                                       /* Compare Enable for Conversion Number 11 of a Sequence */
    word CMPE12      :1;                                       /* Compare Enable for Conversion Number 12 of a Sequence */
    word CMPE13      :1;                                       /* Compare Enable for Conversion Number 13 of a Sequence */
    word CMPE14      :1;                                       /* Compare Enable for Conversion Number 14 of a Sequence */
    word CMPE15      :1;                                       /* Compare Enable for Conversion Number 15 of a Sequence */
  } Bits;
} ATD0CMPESTR;
extern volatile ATD0CMPESTR _ATD0CMPE @(REG_BASE + 0x000002C8UL);
#define ATD0CMPE                        _ATD0CMPE.Word
#define ATD0CMPE_CMPE0                  _ATD0CMPE.Bits.CMPE0
#define ATD0CMPE_CMPE1                  _ATD0CMPE.Bits.CMPE1
#define ATD0CMPE_CMPE2                  _ATD0CMPE.Bits.CMPE2
#define ATD0CMPE_CMPE3                  _ATD0CMPE.Bits.CMPE3
#define ATD0CMPE_CMPE4                  _ATD0CMPE.Bits.CMPE4
#define ATD0CMPE_CMPE5                  _ATD0CMPE.Bits.CMPE5
#define ATD0CMPE_CMPE6                  _ATD0CMPE.Bits.CMPE6
#define ATD0CMPE_CMPE7                  _ATD0CMPE.Bits.CMPE7
#define ATD0CMPE_CMPE8                  _ATD0CMPE.Bits.CMPE8
#define ATD0CMPE_CMPE9                  _ATD0CMPE.Bits.CMPE9
#define ATD0CMPE_CMPE10                 _ATD0CMPE.Bits.CMPE10
#define ATD0CMPE_CMPE11                 _ATD0CMPE.Bits.CMPE11
#define ATD0CMPE_CMPE12                 _ATD0CMPE.Bits.CMPE12
#define ATD0CMPE_CMPE13                 _ATD0CMPE.Bits.CMPE13
#define ATD0CMPE_CMPE14                 _ATD0CMPE.Bits.CMPE14
#define ATD0CMPE_CMPE15                 _ATD0CMPE.Bits.CMPE15

#define ATD0CMPE_CMPE0_MASK             1U
#define ATD0CMPE_CMPE1_MASK             2U
#define ATD0CMPE_CMPE2_MASK             4U
#define ATD0CMPE_CMPE3_MASK             8U
#define ATD0CMPE_CMPE4_MASK             16U
#define ATD0CMPE_CMPE5_MASK             32U
#define ATD0CMPE_CMPE6_MASK             64U
#define ATD0CMPE_CMPE7_MASK             128U
#define ATD0CMPE_CMPE8_MASK             256U
#define ATD0CMPE_CMPE9_MASK             512U
#define ATD0CMPE_CMPE10_MASK            1024U
#define ATD0CMPE_CMPE11_MASK            2048U
#define ATD0CMPE_CMPE12_MASK            4096U
#define ATD0CMPE_CMPE13_MASK            8192U
#define ATD0CMPE_CMPE14_MASK            16384U
#define ATD0CMPE_CMPE15_MASK            32768U


/*** ATD0STAT2 - ATD 0 Status Register 2; 0x000002CA ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0STAT2H - ATD 0 Status Register 2 High; 0x000002CA ***/
    union {
      byte Byte;
      struct {
        byte CCF8        :1;                                       /* Conversion Complete Flag 8 */
        byte CCF9        :1;                                       /* Conversion Complete Flag 9 */
        byte CCF10       :1;                                       /* Conversion Complete Flag 10 */
        byte CCF11       :1;                                       /* Conversion Complete Flag 11 */
        byte CCF12       :1;                                       /* Conversion Complete Flag 12 */
        byte CCF13       :1;                                       /* Conversion Complete Flag 13 */
        byte CCF14       :1;                                       /* Conversion Complete Flag 14 */
        byte CCF15       :1;                                       /* Conversion Complete Flag 15 */
      } Bits;
    } ATD0STAT2HSTR;
    #define ATD0STAT2H                  _ATD0STAT2.Overlap_STR.ATD0STAT2HSTR.Byte
    #define ATD0STAT2H_CCF8             _ATD0STAT2.Overlap_STR.ATD0STAT2HSTR.Bits.CCF8
    #define ATD0STAT2H_CCF9             _ATD0STAT2.Overlap_STR.ATD0STAT2HSTR.Bits.CCF9
    #define ATD0STAT2H_CCF10            _ATD0STAT2.Overlap_STR.ATD0STAT2HSTR.Bits.CCF10
    #define ATD0STAT2H_CCF11            _ATD0STAT2.Overlap_STR.ATD0STAT2HSTR.Bits.CCF11
    #define ATD0STAT2H_CCF12            _ATD0STAT2.Overlap_STR.ATD0STAT2HSTR.Bits.CCF12
    #define ATD0STAT2H_CCF13            _ATD0STAT2.Overlap_STR.ATD0STAT2HSTR.Bits.CCF13
    #define ATD0STAT2H_CCF14            _ATD0STAT2.Overlap_STR.ATD0STAT2HSTR.Bits.CCF14
    #define ATD0STAT2H_CCF15            _ATD0STAT2.Overlap_STR.ATD0STAT2HSTR.Bits.CCF15
    
    #define ATD0STAT2H_CCF8_MASK        1U
    #define ATD0STAT2H_CCF9_MASK        2U
    #define ATD0STAT2H_CCF10_MASK       4U
    #define ATD0STAT2H_CCF11_MASK       8U
    #define ATD0STAT2H_CCF12_MASK       16U
    #define ATD0STAT2H_CCF13_MASK       32U
    #define ATD0STAT2H_CCF14_MASK       64U
    #define ATD0STAT2H_CCF15_MASK       128U
    

    /*** ATD0STAT2L - ATD 0 Status Register 2 Low; 0x000002CB ***/
    union {
      byte Byte;
      struct {
        byte CCF0        :1;                                       /* Conversion Complete Flag 0 */
        byte CCF1        :1;                                       /* Conversion Complete Flag 1 */
        byte CCF2        :1;                                       /* Conversion Complete Flag 2 */
        byte CCF3        :1;                                       /* Conversion Complete Flag 3 */
        byte CCF4        :1;                                       /* Conversion Complete Flag 4 */
        byte CCF5        :1;                                       /* Conversion Complete Flag 5 */
        byte CCF6        :1;                                       /* Conversion Complete Flag 6 */
        byte CCF7        :1;                                       /* Conversion Complete Flag 7 */
      } Bits;
    } ATD0STAT2LSTR;
    #define ATD0STAT2L                  _ATD0STAT2.Overlap_STR.ATD0STAT2LSTR.Byte
    #define ATD0STAT2L_CCF0             _ATD0STAT2.Overlap_STR.ATD0STAT2LSTR.Bits.CCF0
    #define ATD0STAT2L_CCF1             _ATD0STAT2.Overlap_STR.ATD0STAT2LSTR.Bits.CCF1
    #define ATD0STAT2L_CCF2             _ATD0STAT2.Overlap_STR.ATD0STAT2LSTR.Bits.CCF2
    #define ATD0STAT2L_CCF3             _ATD0STAT2.Overlap_STR.ATD0STAT2LSTR.Bits.CCF3
    #define ATD0STAT2L_CCF4             _ATD0STAT2.Overlap_STR.ATD0STAT2LSTR.Bits.CCF4
    #define ATD0STAT2L_CCF5             _ATD0STAT2.Overlap_STR.ATD0STAT2LSTR.Bits.CCF5
    #define ATD0STAT2L_CCF6             _ATD0STAT2.Overlap_STR.ATD0STAT2LSTR.Bits.CCF6
    #define ATD0STAT2L_CCF7             _ATD0STAT2.Overlap_STR.ATD0STAT2LSTR.Bits.CCF7
    
    #define ATD0STAT2L_CCF0_MASK        1U
    #define ATD0STAT2L_CCF1_MASK        2U
    #define ATD0STAT2L_CCF2_MASK        4U
    #define ATD0STAT2L_CCF3_MASK        8U
    #define ATD0STAT2L_CCF4_MASK        16U
    #define ATD0STAT2L_CCF5_MASK        32U
    #define ATD0STAT2L_CCF6_MASK        64U
    #define ATD0STAT2L_CCF7_MASK        128U
    
  } Overlap_STR;

  struct {
    word CCF0        :1;                                       /* Conversion Complete Flag 0 */
    word CCF1        :1;                                       /* Conversion Complete Flag 1 */
    word CCF2        :1;                                       /* Conversion Complete Flag 2 */
    word CCF3        :1;                                       /* Conversion Complete Flag 3 */
    word CCF4        :1;                                       /* Conversion Complete Flag 4 */
    word CCF5        :1;                                       /* Conversion Complete Flag 5 */
    word CCF6        :1;                                       /* Conversion Complete Flag 6 */
    word CCF7        :1;                                       /* Conversion Complete Flag 7 */
    word CCF8        :1;                                       /* Conversion Complete Flag 8 */
    word CCF9        :1;                                       /* Conversion Complete Flag 9 */
    word CCF10       :1;                                       /* Conversion Complete Flag 10 */
    word CCF11       :1;                                       /* Conversion Complete Flag 11 */
    word CCF12       :1;                                       /* Conversion Complete Flag 12 */
    word CCF13       :1;                                       /* Conversion Complete Flag 13 */
    word CCF14       :1;                                       /* Conversion Complete Flag 14 */
    word CCF15       :1;                                       /* Conversion Complete Flag 15 */
  } Bits;
} ATD0STAT2STR;
extern volatile ATD0STAT2STR _ATD0STAT2 @(REG_BASE + 0x000002CAUL);
#define ATD0STAT2                       _ATD0STAT2.Word
#define ATD0STAT2_CCF0                  _ATD0STAT2.Bits.CCF0
#define ATD0STAT2_CCF1                  _ATD0STAT2.Bits.CCF1
#define ATD0STAT2_CCF2                  _ATD0STAT2.Bits.CCF2
#define ATD0STAT2_CCF3                  _ATD0STAT2.Bits.CCF3
#define ATD0STAT2_CCF4                  _ATD0STAT2.Bits.CCF4
#define ATD0STAT2_CCF5                  _ATD0STAT2.Bits.CCF5
#define ATD0STAT2_CCF6                  _ATD0STAT2.Bits.CCF6
#define ATD0STAT2_CCF7                  _ATD0STAT2.Bits.CCF7
#define ATD0STAT2_CCF8                  _ATD0STAT2.Bits.CCF8
#define ATD0STAT2_CCF9                  _ATD0STAT2.Bits.CCF9
#define ATD0STAT2_CCF10                 _ATD0STAT2.Bits.CCF10
#define ATD0STAT2_CCF11                 _ATD0STAT2.Bits.CCF11
#define ATD0STAT2_CCF12                 _ATD0STAT2.Bits.CCF12
#define ATD0STAT2_CCF13                 _ATD0STAT2.Bits.CCF13
#define ATD0STAT2_CCF14                 _ATD0STAT2.Bits.CCF14
#define ATD0STAT2_CCF15                 _ATD0STAT2.Bits.CCF15

#define ATD0STAT2_CCF0_MASK             1U
#define ATD0STAT2_CCF1_MASK             2U
#define ATD0STAT2_CCF2_MASK             4U
#define ATD0STAT2_CCF3_MASK             8U
#define ATD0STAT2_CCF4_MASK             16U
#define ATD0STAT2_CCF5_MASK             32U
#define ATD0STAT2_CCF6_MASK             64U
#define ATD0STAT2_CCF7_MASK             128U
#define ATD0STAT2_CCF8_MASK             256U
#define ATD0STAT2_CCF9_MASK             512U
#define ATD0STAT2_CCF10_MASK            1024U
#define ATD0STAT2_CCF11_MASK            2048U
#define ATD0STAT2_CCF12_MASK            4096U
#define ATD0STAT2_CCF13_MASK            8192U
#define ATD0STAT2_CCF14_MASK            16384U
#define ATD0STAT2_CCF15_MASK            32768U


/*** ATD0DIEN - ATD 0 Input Enable Register; 0x000002CC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DIENH - ATD 0 Input Enable Register High; 0x000002CC ***/
    union {
      byte Byte;
      struct {
        byte IEN8        :1;                                       /* ATD Digital Input Enable on channel 8 */
        byte IEN9        :1;                                       /* ATD Digital Input Enable on channel 9 */
        byte IEN10       :1;                                       /* ATD Digital Input Enable on channel 10 */
        byte IEN11       :1;                                       /* ATD Digital Input Enable on channel 11 */
        byte IEN12       :1;                                       /* ATD Digital Input Enable on channel 12 */
        byte IEN13       :1;                                       /* ATD Digital Input Enable on channel 13 */
        byte IEN14       :1;                                       /* ATD Digital Input Enable on channel 14 */
        byte IEN15       :1;                                       /* ATD Digital Input Enable on channel 15 */
      } Bits;
    } ATD0DIENHSTR;
    #define ATD0DIENH                   _ATD0DIEN.Overlap_STR.ATD0DIENHSTR.Byte
    #define ATD0DIENH_IEN8              _ATD0DIEN.Overlap_STR.ATD0DIENHSTR.Bits.IEN8
    #define ATD0DIENH_IEN9              _ATD0DIEN.Overlap_STR.ATD0DIENHSTR.Bits.IEN9
    #define ATD0DIENH_IEN10             _ATD0DIEN.Overlap_STR.ATD0DIENHSTR.Bits.IEN10
    #define ATD0DIENH_IEN11             _ATD0DIEN.Overlap_STR.ATD0DIENHSTR.Bits.IEN11
    #define ATD0DIENH_IEN12             _ATD0DIEN.Overlap_STR.ATD0DIENHSTR.Bits.IEN12
    #define ATD0DIENH_IEN13             _ATD0DIEN.Overlap_STR.ATD0DIENHSTR.Bits.IEN13
    #define ATD0DIENH_IEN14             _ATD0DIEN.Overlap_STR.ATD0DIENHSTR.Bits.IEN14
    #define ATD0DIENH_IEN15             _ATD0DIEN.Overlap_STR.ATD0DIENHSTR.Bits.IEN15
    
    #define ATD0DIENH_IEN8_MASK         1U
    #define ATD0DIENH_IEN9_MASK         2U
    #define ATD0DIENH_IEN10_MASK        4U
    #define ATD0DIENH_IEN11_MASK        8U
    #define ATD0DIENH_IEN12_MASK        16U
    #define ATD0DIENH_IEN13_MASK        32U
    #define ATD0DIENH_IEN14_MASK        64U
    #define ATD0DIENH_IEN15_MASK        128U
    

    /*** ATD0DIENL - ATD 0 Input Enable Register Low; 0x000002CD ***/
    union {
      byte Byte;
      struct {
        byte IEN0        :1;                                       /* ATD Digital Input Enable on channel 0 */
        byte IEN1        :1;                                       /* ATD Digital Input Enable on channel 1 */
        byte IEN2        :1;                                       /* ATD Digital Input Enable on channel 2 */
        byte IEN3        :1;                                       /* ATD Digital Input Enable on channel 3 */
        byte IEN4        :1;                                       /* ATD Digital Input Enable on channel 4 */
        byte IEN5        :1;                                       /* ATD Digital Input Enable on channel 5 */
        byte IEN6        :1;                                       /* ATD Digital Input Enable on channel 6 */
        byte IEN7        :1;                                       /* ATD Digital Input Enable on channel 7 */
      } Bits;
    } ATD0DIENLSTR;
    #define ATD0DIENL                   _ATD0DIEN.Overlap_STR.ATD0DIENLSTR.Byte
    #define ATD0DIENL_IEN0              _ATD0DIEN.Overlap_STR.ATD0DIENLSTR.Bits.IEN0
    #define ATD0DIENL_IEN1              _ATD0DIEN.Overlap_STR.ATD0DIENLSTR.Bits.IEN1
    #define ATD0DIENL_IEN2              _ATD0DIEN.Overlap_STR.ATD0DIENLSTR.Bits.IEN2
    #define ATD0DIENL_IEN3              _ATD0DIEN.Overlap_STR.ATD0DIENLSTR.Bits.IEN3
    #define ATD0DIENL_IEN4              _ATD0DIEN.Overlap_STR.ATD0DIENLSTR.Bits.IEN4
    #define ATD0DIENL_IEN5              _ATD0DIEN.Overlap_STR.ATD0DIENLSTR.Bits.IEN5
    #define ATD0DIENL_IEN6              _ATD0DIEN.Overlap_STR.ATD0DIENLSTR.Bits.IEN6
    #define ATD0DIENL_IEN7              _ATD0DIEN.Overlap_STR.ATD0DIENLSTR.Bits.IEN7
    
    #define ATD0DIENL_IEN0_MASK         1U
    #define ATD0DIENL_IEN1_MASK         2U
    #define ATD0DIENL_IEN2_MASK         4U
    #define ATD0DIENL_IEN3_MASK         8U
    #define ATD0DIENL_IEN4_MASK         16U
    #define ATD0DIENL_IEN5_MASK         32U
    #define ATD0DIENL_IEN6_MASK         64U
    #define ATD0DIENL_IEN7_MASK         128U
    
  } Overlap_STR;

  struct {
    word IEN0        :1;                                       /* ATD Digital Input Enable on channel 0 */
    word IEN1        :1;                                       /* ATD Digital Input Enable on channel 1 */
    word IEN2        :1;                                       /* ATD Digital Input Enable on channel 2 */
    word IEN3        :1;                                       /* ATD Digital Input Enable on channel 3 */
    word IEN4        :1;                                       /* ATD Digital Input Enable on channel 4 */
    word IEN5        :1;                                       /* ATD Digital Input Enable on channel 5 */
    word IEN6        :1;                                       /* ATD Digital Input Enable on channel 6 */
    word IEN7        :1;                                       /* ATD Digital Input Enable on channel 7 */
    word IEN8        :1;                                       /* ATD Digital Input Enable on channel 8 */
    word IEN9        :1;                                       /* ATD Digital Input Enable on channel 9 */
    word IEN10       :1;                                       /* ATD Digital Input Enable on channel 10 */
    word IEN11       :1;                                       /* ATD Digital Input Enable on channel 11 */
    word IEN12       :1;                                       /* ATD Digital Input Enable on channel 12 */
    word IEN13       :1;                                       /* ATD Digital Input Enable on channel 13 */
    word IEN14       :1;                                       /* ATD Digital Input Enable on channel 14 */
    word IEN15       :1;                                       /* ATD Digital Input Enable on channel 15 */
  } Bits;
} ATD0DIENSTR;
extern volatile ATD0DIENSTR _ATD0DIEN @(REG_BASE + 0x000002CCUL);
#define ATD0DIEN                        _ATD0DIEN.Word
#define ATD0DIEN_IEN0                   _ATD0DIEN.Bits.IEN0
#define ATD0DIEN_IEN1                   _ATD0DIEN.Bits.IEN1
#define ATD0DIEN_IEN2                   _ATD0DIEN.Bits.IEN2
#define ATD0DIEN_IEN3                   _ATD0DIEN.Bits.IEN3
#define ATD0DIEN_IEN4                   _ATD0DIEN.Bits.IEN4
#define ATD0DIEN_IEN5                   _ATD0DIEN.Bits.IEN5
#define ATD0DIEN_IEN6                   _ATD0DIEN.Bits.IEN6
#define ATD0DIEN_IEN7                   _ATD0DIEN.Bits.IEN7
#define ATD0DIEN_IEN8                   _ATD0DIEN.Bits.IEN8
#define ATD0DIEN_IEN9                   _ATD0DIEN.Bits.IEN9
#define ATD0DIEN_IEN10                  _ATD0DIEN.Bits.IEN10
#define ATD0DIEN_IEN11                  _ATD0DIEN.Bits.IEN11
#define ATD0DIEN_IEN12                  _ATD0DIEN.Bits.IEN12
#define ATD0DIEN_IEN13                  _ATD0DIEN.Bits.IEN13
#define ATD0DIEN_IEN14                  _ATD0DIEN.Bits.IEN14
#define ATD0DIEN_IEN15                  _ATD0DIEN.Bits.IEN15

#define ATD0DIEN_IEN0_MASK              1U
#define ATD0DIEN_IEN1_MASK              2U
#define ATD0DIEN_IEN2_MASK              4U
#define ATD0DIEN_IEN3_MASK              8U
#define ATD0DIEN_IEN4_MASK              16U
#define ATD0DIEN_IEN5_MASK              32U
#define ATD0DIEN_IEN6_MASK              64U
#define ATD0DIEN_IEN7_MASK              128U
#define ATD0DIEN_IEN8_MASK              256U
#define ATD0DIEN_IEN9_MASK              512U
#define ATD0DIEN_IEN10_MASK             1024U
#define ATD0DIEN_IEN11_MASK             2048U
#define ATD0DIEN_IEN12_MASK             4096U
#define ATD0DIEN_IEN13_MASK             8192U
#define ATD0DIEN_IEN14_MASK             16384U
#define ATD0DIEN_IEN15_MASK             32768U


/*** ATD0CMPHT - ATD 0 Compare Higher Than Register; 0x000002CE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0CMPHTH - ATD 0 Compare Higher Than Register High; 0x000002CE ***/
    union {
      byte Byte;
      struct {
        byte CMPHT8      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 8 of a Sequence */
        byte CMPHT9      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 9 of a Sequence */
        byte CMPHT10     :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 10 of a Sequence */
        byte CMPHT11     :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 11 of a Sequence */
        byte CMPHT12     :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 12 of a Sequence */
        byte CMPHT13     :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 13 of a Sequence */
        byte CMPHT14     :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 14 of a Sequence */
        byte CMPHT15     :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 15 of a Sequence */
      } Bits;
    } ATD0CMPHTHSTR;
    #define ATD0CMPHTH                  _ATD0CMPHT.Overlap_STR.ATD0CMPHTHSTR.Byte
    #define ATD0CMPHTH_CMPHT8           _ATD0CMPHT.Overlap_STR.ATD0CMPHTHSTR.Bits.CMPHT8
    #define ATD0CMPHTH_CMPHT9           _ATD0CMPHT.Overlap_STR.ATD0CMPHTHSTR.Bits.CMPHT9
    #define ATD0CMPHTH_CMPHT10          _ATD0CMPHT.Overlap_STR.ATD0CMPHTHSTR.Bits.CMPHT10
    #define ATD0CMPHTH_CMPHT11          _ATD0CMPHT.Overlap_STR.ATD0CMPHTHSTR.Bits.CMPHT11
    #define ATD0CMPHTH_CMPHT12          _ATD0CMPHT.Overlap_STR.ATD0CMPHTHSTR.Bits.CMPHT12
    #define ATD0CMPHTH_CMPHT13          _ATD0CMPHT.Overlap_STR.ATD0CMPHTHSTR.Bits.CMPHT13
    #define ATD0CMPHTH_CMPHT14          _ATD0CMPHT.Overlap_STR.ATD0CMPHTHSTR.Bits.CMPHT14
    #define ATD0CMPHTH_CMPHT15          _ATD0CMPHT.Overlap_STR.ATD0CMPHTHSTR.Bits.CMPHT15
    
    #define ATD0CMPHTH_CMPHT8_MASK      1U
    #define ATD0CMPHTH_CMPHT9_MASK      2U
    #define ATD0CMPHTH_CMPHT10_MASK     4U
    #define ATD0CMPHTH_CMPHT11_MASK     8U
    #define ATD0CMPHTH_CMPHT12_MASK     16U
    #define ATD0CMPHTH_CMPHT13_MASK     32U
    #define ATD0CMPHTH_CMPHT14_MASK     64U
    #define ATD0CMPHTH_CMPHT15_MASK     128U
    

    /*** ATD0CMPHTL - ATD 0 Compare Higher Than Register Low; 0x000002CF ***/
    union {
      byte Byte;
      struct {
        byte CMPHT0      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 0 of a Sequence */
        byte CMPHT1      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 1 of a Sequence */
        byte CMPHT2      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 2 of a Sequence */
        byte CMPHT3      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 3 of a Sequence */
        byte CMPHT4      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 4 of a Sequence */
        byte CMPHT5      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 5 of a Sequence */
        byte CMPHT6      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 6 of a Sequence */
        byte CMPHT7      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 7 of a Sequence */
      } Bits;
    } ATD0CMPHTLSTR;
    #define ATD0CMPHTL                  _ATD0CMPHT.Overlap_STR.ATD0CMPHTLSTR.Byte
    #define ATD0CMPHTL_CMPHT0           _ATD0CMPHT.Overlap_STR.ATD0CMPHTLSTR.Bits.CMPHT0
    #define ATD0CMPHTL_CMPHT1           _ATD0CMPHT.Overlap_STR.ATD0CMPHTLSTR.Bits.CMPHT1
    #define ATD0CMPHTL_CMPHT2           _ATD0CMPHT.Overlap_STR.ATD0CMPHTLSTR.Bits.CMPHT2
    #define ATD0CMPHTL_CMPHT3           _ATD0CMPHT.Overlap_STR.ATD0CMPHTLSTR.Bits.CMPHT3
    #define ATD0CMPHTL_CMPHT4           _ATD0CMPHT.Overlap_STR.ATD0CMPHTLSTR.Bits.CMPHT4
    #define ATD0CMPHTL_CMPHT5           _ATD0CMPHT.Overlap_STR.ATD0CMPHTLSTR.Bits.CMPHT5
    #define ATD0CMPHTL_CMPHT6           _ATD0CMPHT.Overlap_STR.ATD0CMPHTLSTR.Bits.CMPHT6
    #define ATD0CMPHTL_CMPHT7           _ATD0CMPHT.Overlap_STR.ATD0CMPHTLSTR.Bits.CMPHT7
    
    #define ATD0CMPHTL_CMPHT0_MASK      1U
    #define ATD0CMPHTL_CMPHT1_MASK      2U
    #define ATD0CMPHTL_CMPHT2_MASK      4U
    #define ATD0CMPHTL_CMPHT3_MASK      8U
    #define ATD0CMPHTL_CMPHT4_MASK      16U
    #define ATD0CMPHTL_CMPHT5_MASK      32U
    #define ATD0CMPHTL_CMPHT6_MASK      64U
    #define ATD0CMPHTL_CMPHT7_MASK      128U
    
  } Overlap_STR;

  struct {
    word CMPHT0      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 0 of a Sequence */
    word CMPHT1      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 1 of a Sequence */
    word CMPHT2      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 2 of a Sequence */
    word CMPHT3      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 3 of a Sequence */
    word CMPHT4      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 4 of a Sequence */
    word CMPHT5      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 5 of a Sequence */
    word CMPHT6      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 6 of a Sequence */
    word CMPHT7      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 7 of a Sequence */
    word CMPHT8      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 8 of a Sequence */
    word CMPHT9      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 9 of a Sequence */
    word CMPHT10     :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 10 of a Sequence */
    word CMPHT11     :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 11 of a Sequence */
    word CMPHT12     :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 12 of a Sequence */
    word CMPHT13     :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 13 of a Sequence */
    word CMPHT14     :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 14 of a Sequence */
    word CMPHT15     :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 15 of a Sequence */
  } Bits;
} ATD0CMPHTSTR;
extern volatile ATD0CMPHTSTR _ATD0CMPHT @(REG_BASE + 0x000002CEUL);
#define ATD0CMPHT                       _ATD0CMPHT.Word
#define ATD0CMPHT_CMPHT0                _ATD0CMPHT.Bits.CMPHT0
#define ATD0CMPHT_CMPHT1                _ATD0CMPHT.Bits.CMPHT1
#define ATD0CMPHT_CMPHT2                _ATD0CMPHT.Bits.CMPHT2
#define ATD0CMPHT_CMPHT3                _ATD0CMPHT.Bits.CMPHT3
#define ATD0CMPHT_CMPHT4                _ATD0CMPHT.Bits.CMPHT4
#define ATD0CMPHT_CMPHT5                _ATD0CMPHT.Bits.CMPHT5
#define ATD0CMPHT_CMPHT6                _ATD0CMPHT.Bits.CMPHT6
#define ATD0CMPHT_CMPHT7                _ATD0CMPHT.Bits.CMPHT7
#define ATD0CMPHT_CMPHT8                _ATD0CMPHT.Bits.CMPHT8
#define ATD0CMPHT_CMPHT9                _ATD0CMPHT.Bits.CMPHT9
#define ATD0CMPHT_CMPHT10               _ATD0CMPHT.Bits.CMPHT10
#define ATD0CMPHT_CMPHT11               _ATD0CMPHT.Bits.CMPHT11
#define ATD0CMPHT_CMPHT12               _ATD0CMPHT.Bits.CMPHT12
#define ATD0CMPHT_CMPHT13               _ATD0CMPHT.Bits.CMPHT13
#define ATD0CMPHT_CMPHT14               _ATD0CMPHT.Bits.CMPHT14
#define ATD0CMPHT_CMPHT15               _ATD0CMPHT.Bits.CMPHT15

#define ATD0CMPHT_CMPHT0_MASK           1U
#define ATD0CMPHT_CMPHT1_MASK           2U
#define ATD0CMPHT_CMPHT2_MASK           4U
#define ATD0CMPHT_CMPHT3_MASK           8U
#define ATD0CMPHT_CMPHT4_MASK           16U
#define ATD0CMPHT_CMPHT5_MASK           32U
#define ATD0CMPHT_CMPHT6_MASK           64U
#define ATD0CMPHT_CMPHT7_MASK           128U
#define ATD0CMPHT_CMPHT8_MASK           256U
#define ATD0CMPHT_CMPHT9_MASK           512U
#define ATD0CMPHT_CMPHT10_MASK          1024U
#define ATD0CMPHT_CMPHT11_MASK          2048U
#define ATD0CMPHT_CMPHT12_MASK          4096U
#define ATD0CMPHT_CMPHT13_MASK          8192U
#define ATD0CMPHT_CMPHT14_MASK          16384U
#define ATD0CMPHT_CMPHT15_MASK          32768U


/*** ATD0DR0 - ATD 0 Conversion Result Register 0; 0x000002D0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR0H - ATD 0 Conversion Result Register 0 High; 0x000002D0 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATD0DR0HSTR;
    #define ATD0DR0H                    _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Byte
    #define ATD0DR0H_BIT8               _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT8
    #define ATD0DR0H_BIT9               _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT9
    #define ATD0DR0H_BIT10              _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT10
    #define ATD0DR0H_BIT11              _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT11
    #define ATD0DR0H_BIT12              _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT12
    #define ATD0DR0H_BIT13              _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT13
    #define ATD0DR0H_BIT14              _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT14
    #define ATD0DR0H_BIT15              _ATD0DR0.Overlap_STR.ATD0DR0HSTR.Bits.BIT15
    
    #define ATD0DR0H_BIT8_MASK          1U
    #define ATD0DR0H_BIT9_MASK          2U
    #define ATD0DR0H_BIT10_MASK         4U
    #define ATD0DR0H_BIT11_MASK         8U
    #define ATD0DR0H_BIT12_MASK         16U
    #define ATD0DR0H_BIT13_MASK         32U
    #define ATD0DR0H_BIT14_MASK         64U
    #define ATD0DR0H_BIT15_MASK         128U
    

    /*** ATD0DR0L - ATD 0 Conversion Result Register 0 Low; 0x000002D1 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATD0DR0LSTR;
    #define ATD0DR0L                    _ATD0DR0.Overlap_STR.ATD0DR0LSTR.Byte
    #define ATD0DR0L_BIT0               _ATD0DR0.Overlap_STR.ATD0DR0LSTR.Bits.BIT0
    #define ATD0DR0L_BIT1               _ATD0DR0.Overlap_STR.ATD0DR0LSTR.Bits.BIT1
    #define ATD0DR0L_BIT2               _ATD0DR0.Overlap_STR.ATD0DR0LSTR.Bits.BIT2
    #define ATD0DR0L_BIT3               _ATD0DR0.Overlap_STR.ATD0DR0LSTR.Bits.BIT3
    #define ATD0DR0L_BIT4               _ATD0DR0.Overlap_STR.ATD0DR0LSTR.Bits.BIT4
    #define ATD0DR0L_BIT5               _ATD0DR0.Overlap_STR.ATD0DR0LSTR.Bits.BIT5
    #define ATD0DR0L_BIT6               _ATD0DR0.Overlap_STR.ATD0DR0LSTR.Bits.BIT6
    #define ATD0DR0L_BIT7               _ATD0DR0.Overlap_STR.ATD0DR0LSTR.Bits.BIT7
    
    #define ATD0DR0L_BIT0_MASK          1U
    #define ATD0DR0L_BIT1_MASK          2U
    #define ATD0DR0L_BIT2_MASK          4U
    #define ATD0DR0L_BIT3_MASK          8U
    #define ATD0DR0L_BIT4_MASK          16U
    #define ATD0DR0L_BIT5_MASK          32U
    #define ATD0DR0L_BIT6_MASK          64U
    #define ATD0DR0L_BIT7_MASK          128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATD0DR0STR;
extern volatile ATD0DR0STR _ATD0DR0 @(REG_BASE + 0x000002D0UL);
#define ATD0DR0                         _ATD0DR0.Word
#define ATD0DR0_BIT0                    _ATD0DR0.Bits.BIT0
#define ATD0DR0_BIT1                    _ATD0DR0.Bits.BIT1
#define ATD0DR0_BIT2                    _ATD0DR0.Bits.BIT2
#define ATD0DR0_BIT3                    _ATD0DR0.Bits.BIT3
#define ATD0DR0_BIT4                    _ATD0DR0.Bits.BIT4
#define ATD0DR0_BIT5                    _ATD0DR0.Bits.BIT5
#define ATD0DR0_BIT6                    _ATD0DR0.Bits.BIT6
#define ATD0DR0_BIT7                    _ATD0DR0.Bits.BIT7
#define ATD0DR0_BIT8                    _ATD0DR0.Bits.BIT8
#define ATD0DR0_BIT9                    _ATD0DR0.Bits.BIT9
#define ATD0DR0_BIT10                   _ATD0DR0.Bits.BIT10
#define ATD0DR0_BIT11                   _ATD0DR0.Bits.BIT11
#define ATD0DR0_BIT12                   _ATD0DR0.Bits.BIT12
#define ATD0DR0_BIT13                   _ATD0DR0.Bits.BIT13
#define ATD0DR0_BIT14                   _ATD0DR0.Bits.BIT14
#define ATD0DR0_BIT15                   _ATD0DR0.Bits.BIT15
/* ATD0DR_ARR: Access 16 ATD0DRx registers in an array */
#define ATD0DR_ARR                      ((volatile word *) &ATD0DR0)

#define ATD0DR0_BIT0_MASK               1U
#define ATD0DR0_BIT1_MASK               2U
#define ATD0DR0_BIT2_MASK               4U
#define ATD0DR0_BIT3_MASK               8U
#define ATD0DR0_BIT4_MASK               16U
#define ATD0DR0_BIT5_MASK               32U
#define ATD0DR0_BIT6_MASK               64U
#define ATD0DR0_BIT7_MASK               128U
#define ATD0DR0_BIT8_MASK               256U
#define ATD0DR0_BIT9_MASK               512U
#define ATD0DR0_BIT10_MASK              1024U
#define ATD0DR0_BIT11_MASK              2048U
#define ATD0DR0_BIT12_MASK              4096U
#define ATD0DR0_BIT13_MASK              8192U
#define ATD0DR0_BIT14_MASK              16384U
#define ATD0DR0_BIT15_MASK              32768U


/*** ATD0DR1 - ATD 0 Conversion Result Register 1; 0x000002D2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR1H - ATD 0 Conversion Result Register 1 High; 0x000002D2 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATD0DR1HSTR;
    #define ATD0DR1H                    _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Byte
    #define ATD0DR1H_BIT8               _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT8
    #define ATD0DR1H_BIT9               _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT9
    #define ATD0DR1H_BIT10              _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT10
    #define ATD0DR1H_BIT11              _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT11
    #define ATD0DR1H_BIT12              _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT12
    #define ATD0DR1H_BIT13              _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT13
    #define ATD0DR1H_BIT14              _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT14
    #define ATD0DR1H_BIT15              _ATD0DR1.Overlap_STR.ATD0DR1HSTR.Bits.BIT15
    
    #define ATD0DR1H_BIT8_MASK          1U
    #define ATD0DR1H_BIT9_MASK          2U
    #define ATD0DR1H_BIT10_MASK         4U
    #define ATD0DR1H_BIT11_MASK         8U
    #define ATD0DR1H_BIT12_MASK         16U
    #define ATD0DR1H_BIT13_MASK         32U
    #define ATD0DR1H_BIT14_MASK         64U
    #define ATD0DR1H_BIT15_MASK         128U
    

    /*** ATD0DR1L - ATD 0 Conversion Result Register 1 Low; 0x000002D3 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATD0DR1LSTR;
    #define ATD0DR1L                    _ATD0DR1.Overlap_STR.ATD0DR1LSTR.Byte
    #define ATD0DR1L_BIT0               _ATD0DR1.Overlap_STR.ATD0DR1LSTR.Bits.BIT0
    #define ATD0DR1L_BIT1               _ATD0DR1.Overlap_STR.ATD0DR1LSTR.Bits.BIT1
    #define ATD0DR1L_BIT2               _ATD0DR1.Overlap_STR.ATD0DR1LSTR.Bits.BIT2
    #define ATD0DR1L_BIT3               _ATD0DR1.Overlap_STR.ATD0DR1LSTR.Bits.BIT3
    #define ATD0DR1L_BIT4               _ATD0DR1.Overlap_STR.ATD0DR1LSTR.Bits.BIT4
    #define ATD0DR1L_BIT5               _ATD0DR1.Overlap_STR.ATD0DR1LSTR.Bits.BIT5
    #define ATD0DR1L_BIT6               _ATD0DR1.Overlap_STR.ATD0DR1LSTR.Bits.BIT6
    #define ATD0DR1L_BIT7               _ATD0DR1.Overlap_STR.ATD0DR1LSTR.Bits.BIT7
    
    #define ATD0DR1L_BIT0_MASK          1U
    #define ATD0DR1L_BIT1_MASK          2U
    #define ATD0DR1L_BIT2_MASK          4U
    #define ATD0DR1L_BIT3_MASK          8U
    #define ATD0DR1L_BIT4_MASK          16U
    #define ATD0DR1L_BIT5_MASK          32U
    #define ATD0DR1L_BIT6_MASK          64U
    #define ATD0DR1L_BIT7_MASK          128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATD0DR1STR;
extern volatile ATD0DR1STR _ATD0DR1 @(REG_BASE + 0x000002D2UL);
#define ATD0DR1                         _ATD0DR1.Word
#define ATD0DR1_BIT0                    _ATD0DR1.Bits.BIT0
#define ATD0DR1_BIT1                    _ATD0DR1.Bits.BIT1
#define ATD0DR1_BIT2                    _ATD0DR1.Bits.BIT2
#define ATD0DR1_BIT3                    _ATD0DR1.Bits.BIT3
#define ATD0DR1_BIT4                    _ATD0DR1.Bits.BIT4
#define ATD0DR1_BIT5                    _ATD0DR1.Bits.BIT5
#define ATD0DR1_BIT6                    _ATD0DR1.Bits.BIT6
#define ATD0DR1_BIT7                    _ATD0DR1.Bits.BIT7
#define ATD0DR1_BIT8                    _ATD0DR1.Bits.BIT8
#define ATD0DR1_BIT9                    _ATD0DR1.Bits.BIT9
#define ATD0DR1_BIT10                   _ATD0DR1.Bits.BIT10
#define ATD0DR1_BIT11                   _ATD0DR1.Bits.BIT11
#define ATD0DR1_BIT12                   _ATD0DR1.Bits.BIT12
#define ATD0DR1_BIT13                   _ATD0DR1.Bits.BIT13
#define ATD0DR1_BIT14                   _ATD0DR1.Bits.BIT14
#define ATD0DR1_BIT15                   _ATD0DR1.Bits.BIT15

#define ATD0DR1_BIT0_MASK               1U
#define ATD0DR1_BIT1_MASK               2U
#define ATD0DR1_BIT2_MASK               4U
#define ATD0DR1_BIT3_MASK               8U
#define ATD0DR1_BIT4_MASK               16U
#define ATD0DR1_BIT5_MASK               32U
#define ATD0DR1_BIT6_MASK               64U
#define ATD0DR1_BIT7_MASK               128U
#define ATD0DR1_BIT8_MASK               256U
#define ATD0DR1_BIT9_MASK               512U
#define ATD0DR1_BIT10_MASK              1024U
#define ATD0DR1_BIT11_MASK              2048U
#define ATD0DR1_BIT12_MASK              4096U
#define ATD0DR1_BIT13_MASK              8192U
#define ATD0DR1_BIT14_MASK              16384U
#define ATD0DR1_BIT15_MASK              32768U


/*** ATD0DR2 - ATD 0 Conversion Result Register 2; 0x000002D4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR2H - ATD 0 Conversion Result Register 2 High; 0x000002D4 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATD0DR2HSTR;
    #define ATD0DR2H                    _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Byte
    #define ATD0DR2H_BIT8               _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT8
    #define ATD0DR2H_BIT9               _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT9
    #define ATD0DR2H_BIT10              _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT10
    #define ATD0DR2H_BIT11              _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT11
    #define ATD0DR2H_BIT12              _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT12
    #define ATD0DR2H_BIT13              _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT13
    #define ATD0DR2H_BIT14              _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT14
    #define ATD0DR2H_BIT15              _ATD0DR2.Overlap_STR.ATD0DR2HSTR.Bits.BIT15
    
    #define ATD0DR2H_BIT8_MASK          1U
    #define ATD0DR2H_BIT9_MASK          2U
    #define ATD0DR2H_BIT10_MASK         4U
    #define ATD0DR2H_BIT11_MASK         8U
    #define ATD0DR2H_BIT12_MASK         16U
    #define ATD0DR2H_BIT13_MASK         32U
    #define ATD0DR2H_BIT14_MASK         64U
    #define ATD0DR2H_BIT15_MASK         128U
    

    /*** ATD0DR2L - ATD 0 Conversion Result Register 2 Low; 0x000002D5 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATD0DR2LSTR;
    #define ATD0DR2L                    _ATD0DR2.Overlap_STR.ATD0DR2LSTR.Byte
    #define ATD0DR2L_BIT0               _ATD0DR2.Overlap_STR.ATD0DR2LSTR.Bits.BIT0
    #define ATD0DR2L_BIT1               _ATD0DR2.Overlap_STR.ATD0DR2LSTR.Bits.BIT1
    #define ATD0DR2L_BIT2               _ATD0DR2.Overlap_STR.ATD0DR2LSTR.Bits.BIT2
    #define ATD0DR2L_BIT3               _ATD0DR2.Overlap_STR.ATD0DR2LSTR.Bits.BIT3
    #define ATD0DR2L_BIT4               _ATD0DR2.Overlap_STR.ATD0DR2LSTR.Bits.BIT4
    #define ATD0DR2L_BIT5               _ATD0DR2.Overlap_STR.ATD0DR2LSTR.Bits.BIT5
    #define ATD0DR2L_BIT6               _ATD0DR2.Overlap_STR.ATD0DR2LSTR.Bits.BIT6
    #define ATD0DR2L_BIT7               _ATD0DR2.Overlap_STR.ATD0DR2LSTR.Bits.BIT7
    
    #define ATD0DR2L_BIT0_MASK          1U
    #define ATD0DR2L_BIT1_MASK          2U
    #define ATD0DR2L_BIT2_MASK          4U
    #define ATD0DR2L_BIT3_MASK          8U
    #define ATD0DR2L_BIT4_MASK          16U
    #define ATD0DR2L_BIT5_MASK          32U
    #define ATD0DR2L_BIT6_MASK          64U
    #define ATD0DR2L_BIT7_MASK          128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATD0DR2STR;
extern volatile ATD0DR2STR _ATD0DR2 @(REG_BASE + 0x000002D4UL);
#define ATD0DR2                         _ATD0DR2.Word
#define ATD0DR2_BIT0                    _ATD0DR2.Bits.BIT0
#define ATD0DR2_BIT1                    _ATD0DR2.Bits.BIT1
#define ATD0DR2_BIT2                    _ATD0DR2.Bits.BIT2
#define ATD0DR2_BIT3                    _ATD0DR2.Bits.BIT3
#define ATD0DR2_BIT4                    _ATD0DR2.Bits.BIT4
#define ATD0DR2_BIT5                    _ATD0DR2.Bits.BIT5
#define ATD0DR2_BIT6                    _ATD0DR2.Bits.BIT6
#define ATD0DR2_BIT7                    _ATD0DR2.Bits.BIT7
#define ATD0DR2_BIT8                    _ATD0DR2.Bits.BIT8
#define ATD0DR2_BIT9                    _ATD0DR2.Bits.BIT9
#define ATD0DR2_BIT10                   _ATD0DR2.Bits.BIT10
#define ATD0DR2_BIT11                   _ATD0DR2.Bits.BIT11
#define ATD0DR2_BIT12                   _ATD0DR2.Bits.BIT12
#define ATD0DR2_BIT13                   _ATD0DR2.Bits.BIT13
#define ATD0DR2_BIT14                   _ATD0DR2.Bits.BIT14
#define ATD0DR2_BIT15                   _ATD0DR2.Bits.BIT15

#define ATD0DR2_BIT0_MASK               1U
#define ATD0DR2_BIT1_MASK               2U
#define ATD0DR2_BIT2_MASK               4U
#define ATD0DR2_BIT3_MASK               8U
#define ATD0DR2_BIT4_MASK               16U
#define ATD0DR2_BIT5_MASK               32U
#define ATD0DR2_BIT6_MASK               64U
#define ATD0DR2_BIT7_MASK               128U
#define ATD0DR2_BIT8_MASK               256U
#define ATD0DR2_BIT9_MASK               512U
#define ATD0DR2_BIT10_MASK              1024U
#define ATD0DR2_BIT11_MASK              2048U
#define ATD0DR2_BIT12_MASK              4096U
#define ATD0DR2_BIT13_MASK              8192U
#define ATD0DR2_BIT14_MASK              16384U
#define ATD0DR2_BIT15_MASK              32768U


/*** ATD0DR3 - ATD 0 Conversion Result Register 3; 0x000002D6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR3H - ATD 0 Conversion Result Register 3 High; 0x000002D6 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATD0DR3HSTR;
    #define ATD0DR3H                    _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Byte
    #define ATD0DR3H_BIT8               _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT8
    #define ATD0DR3H_BIT9               _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT9
    #define ATD0DR3H_BIT10              _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT10
    #define ATD0DR3H_BIT11              _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT11
    #define ATD0DR3H_BIT12              _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT12
    #define ATD0DR3H_BIT13              _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT13
    #define ATD0DR3H_BIT14              _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT14
    #define ATD0DR3H_BIT15              _ATD0DR3.Overlap_STR.ATD0DR3HSTR.Bits.BIT15
    
    #define ATD0DR3H_BIT8_MASK          1U
    #define ATD0DR3H_BIT9_MASK          2U
    #define ATD0DR3H_BIT10_MASK         4U
    #define ATD0DR3H_BIT11_MASK         8U
    #define ATD0DR3H_BIT12_MASK         16U
    #define ATD0DR3H_BIT13_MASK         32U
    #define ATD0DR3H_BIT14_MASK         64U
    #define ATD0DR3H_BIT15_MASK         128U
    

    /*** ATD0DR3L - ATD 0 Conversion Result Register 3 Low; 0x000002D7 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATD0DR3LSTR;
    #define ATD0DR3L                    _ATD0DR3.Overlap_STR.ATD0DR3LSTR.Byte
    #define ATD0DR3L_BIT0               _ATD0DR3.Overlap_STR.ATD0DR3LSTR.Bits.BIT0
    #define ATD0DR3L_BIT1               _ATD0DR3.Overlap_STR.ATD0DR3LSTR.Bits.BIT1
    #define ATD0DR3L_BIT2               _ATD0DR3.Overlap_STR.ATD0DR3LSTR.Bits.BIT2
    #define ATD0DR3L_BIT3               _ATD0DR3.Overlap_STR.ATD0DR3LSTR.Bits.BIT3
    #define ATD0DR3L_BIT4               _ATD0DR3.Overlap_STR.ATD0DR3LSTR.Bits.BIT4
    #define ATD0DR3L_BIT5               _ATD0DR3.Overlap_STR.ATD0DR3LSTR.Bits.BIT5
    #define ATD0DR3L_BIT6               _ATD0DR3.Overlap_STR.ATD0DR3LSTR.Bits.BIT6
    #define ATD0DR3L_BIT7               _ATD0DR3.Overlap_STR.ATD0DR3LSTR.Bits.BIT7
    
    #define ATD0DR3L_BIT0_MASK          1U
    #define ATD0DR3L_BIT1_MASK          2U
    #define ATD0DR3L_BIT2_MASK          4U
    #define ATD0DR3L_BIT3_MASK          8U
    #define ATD0DR3L_BIT4_MASK          16U
    #define ATD0DR3L_BIT5_MASK          32U
    #define ATD0DR3L_BIT6_MASK          64U
    #define ATD0DR3L_BIT7_MASK          128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATD0DR3STR;
extern volatile ATD0DR3STR _ATD0DR3 @(REG_BASE + 0x000002D6UL);
#define ATD0DR3                         _ATD0DR3.Word
#define ATD0DR3_BIT0                    _ATD0DR3.Bits.BIT0
#define ATD0DR3_BIT1                    _ATD0DR3.Bits.BIT1
#define ATD0DR3_BIT2                    _ATD0DR3.Bits.BIT2
#define ATD0DR3_BIT3                    _ATD0DR3.Bits.BIT3
#define ATD0DR3_BIT4                    _ATD0DR3.Bits.BIT4
#define ATD0DR3_BIT5                    _ATD0DR3.Bits.BIT5
#define ATD0DR3_BIT6                    _ATD0DR3.Bits.BIT6
#define ATD0DR3_BIT7                    _ATD0DR3.Bits.BIT7
#define ATD0DR3_BIT8                    _ATD0DR3.Bits.BIT8
#define ATD0DR3_BIT9                    _ATD0DR3.Bits.BIT9
#define ATD0DR3_BIT10                   _ATD0DR3.Bits.BIT10
#define ATD0DR3_BIT11                   _ATD0DR3.Bits.BIT11
#define ATD0DR3_BIT12                   _ATD0DR3.Bits.BIT12
#define ATD0DR3_BIT13                   _ATD0DR3.Bits.BIT13
#define ATD0DR3_BIT14                   _ATD0DR3.Bits.BIT14
#define ATD0DR3_BIT15                   _ATD0DR3.Bits.BIT15

#define ATD0DR3_BIT0_MASK               1U
#define ATD0DR3_BIT1_MASK               2U
#define ATD0DR3_BIT2_MASK               4U
#define ATD0DR3_BIT3_MASK               8U
#define ATD0DR3_BIT4_MASK               16U
#define ATD0DR3_BIT5_MASK               32U
#define ATD0DR3_BIT6_MASK               64U
#define ATD0DR3_BIT7_MASK               128U
#define ATD0DR3_BIT8_MASK               256U
#define ATD0DR3_BIT9_MASK               512U
#define ATD0DR3_BIT10_MASK              1024U
#define ATD0DR3_BIT11_MASK              2048U
#define ATD0DR3_BIT12_MASK              4096U
#define ATD0DR3_BIT13_MASK              8192U
#define ATD0DR3_BIT14_MASK              16384U
#define ATD0DR3_BIT15_MASK              32768U


/*** ATD0DR4 - ATD 0 Conversion Result Register 4; 0x000002D8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR4H - ATD 0 Conversion Result Register 4 High; 0x000002D8 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATD0DR4HSTR;
    #define ATD0DR4H                    _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Byte
    #define ATD0DR4H_BIT8               _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT8
    #define ATD0DR4H_BIT9               _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT9
    #define ATD0DR4H_BIT10              _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT10
    #define ATD0DR4H_BIT11              _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT11
    #define ATD0DR4H_BIT12              _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT12
    #define ATD0DR4H_BIT13              _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT13
    #define ATD0DR4H_BIT14              _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT14
    #define ATD0DR4H_BIT15              _ATD0DR4.Overlap_STR.ATD0DR4HSTR.Bits.BIT15
    
    #define ATD0DR4H_BIT8_MASK          1U
    #define ATD0DR4H_BIT9_MASK          2U
    #define ATD0DR4H_BIT10_MASK         4U
    #define ATD0DR4H_BIT11_MASK         8U
    #define ATD0DR4H_BIT12_MASK         16U
    #define ATD0DR4H_BIT13_MASK         32U
    #define ATD0DR4H_BIT14_MASK         64U
    #define ATD0DR4H_BIT15_MASK         128U
    

    /*** ATD0DR4L - ATD 0 Conversion Result Register 4 Low; 0x000002D9 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATD0DR4LSTR;
    #define ATD0DR4L                    _ATD0DR4.Overlap_STR.ATD0DR4LSTR.Byte
    #define ATD0DR4L_BIT0               _ATD0DR4.Overlap_STR.ATD0DR4LSTR.Bits.BIT0
    #define ATD0DR4L_BIT1               _ATD0DR4.Overlap_STR.ATD0DR4LSTR.Bits.BIT1
    #define ATD0DR4L_BIT2               _ATD0DR4.Overlap_STR.ATD0DR4LSTR.Bits.BIT2
    #define ATD0DR4L_BIT3               _ATD0DR4.Overlap_STR.ATD0DR4LSTR.Bits.BIT3
    #define ATD0DR4L_BIT4               _ATD0DR4.Overlap_STR.ATD0DR4LSTR.Bits.BIT4
    #define ATD0DR4L_BIT5               _ATD0DR4.Overlap_STR.ATD0DR4LSTR.Bits.BIT5
    #define ATD0DR4L_BIT6               _ATD0DR4.Overlap_STR.ATD0DR4LSTR.Bits.BIT6
    #define ATD0DR4L_BIT7               _ATD0DR4.Overlap_STR.ATD0DR4LSTR.Bits.BIT7
    
    #define ATD0DR4L_BIT0_MASK          1U
    #define ATD0DR4L_BIT1_MASK          2U
    #define ATD0DR4L_BIT2_MASK          4U
    #define ATD0DR4L_BIT3_MASK          8U
    #define ATD0DR4L_BIT4_MASK          16U
    #define ATD0DR4L_BIT5_MASK          32U
    #define ATD0DR4L_BIT6_MASK          64U
    #define ATD0DR4L_BIT7_MASK          128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATD0DR4STR;
extern volatile ATD0DR4STR _ATD0DR4 @(REG_BASE + 0x000002D8UL);
#define ATD0DR4                         _ATD0DR4.Word
#define ATD0DR4_BIT0                    _ATD0DR4.Bits.BIT0
#define ATD0DR4_BIT1                    _ATD0DR4.Bits.BIT1
#define ATD0DR4_BIT2                    _ATD0DR4.Bits.BIT2
#define ATD0DR4_BIT3                    _ATD0DR4.Bits.BIT3
#define ATD0DR4_BIT4                    _ATD0DR4.Bits.BIT4
#define ATD0DR4_BIT5                    _ATD0DR4.Bits.BIT5
#define ATD0DR4_BIT6                    _ATD0DR4.Bits.BIT6
#define ATD0DR4_BIT7                    _ATD0DR4.Bits.BIT7
#define ATD0DR4_BIT8                    _ATD0DR4.Bits.BIT8
#define ATD0DR4_BIT9                    _ATD0DR4.Bits.BIT9
#define ATD0DR4_BIT10                   _ATD0DR4.Bits.BIT10
#define ATD0DR4_BIT11                   _ATD0DR4.Bits.BIT11
#define ATD0DR4_BIT12                   _ATD0DR4.Bits.BIT12
#define ATD0DR4_BIT13                   _ATD0DR4.Bits.BIT13
#define ATD0DR4_BIT14                   _ATD0DR4.Bits.BIT14
#define ATD0DR4_BIT15                   _ATD0DR4.Bits.BIT15

#define ATD0DR4_BIT0_MASK               1U
#define ATD0DR4_BIT1_MASK               2U
#define ATD0DR4_BIT2_MASK               4U
#define ATD0DR4_BIT3_MASK               8U
#define ATD0DR4_BIT4_MASK               16U
#define ATD0DR4_BIT5_MASK               32U
#define ATD0DR4_BIT6_MASK               64U
#define ATD0DR4_BIT7_MASK               128U
#define ATD0DR4_BIT8_MASK               256U
#define ATD0DR4_BIT9_MASK               512U
#define ATD0DR4_BIT10_MASK              1024U
#define ATD0DR4_BIT11_MASK              2048U
#define ATD0DR4_BIT12_MASK              4096U
#define ATD0DR4_BIT13_MASK              8192U
#define ATD0DR4_BIT14_MASK              16384U
#define ATD0DR4_BIT15_MASK              32768U


/*** ATD0DR5 - ATD 0 Conversion Result Register 5; 0x000002DA ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR5H - ATD 0 Conversion Result Register 5 High; 0x000002DA ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATD0DR5HSTR;
    #define ATD0DR5H                    _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Byte
    #define ATD0DR5H_BIT8               _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT8
    #define ATD0DR5H_BIT9               _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT9
    #define ATD0DR5H_BIT10              _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT10
    #define ATD0DR5H_BIT11              _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT11
    #define ATD0DR5H_BIT12              _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT12
    #define ATD0DR5H_BIT13              _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT13
    #define ATD0DR5H_BIT14              _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT14
    #define ATD0DR5H_BIT15              _ATD0DR5.Overlap_STR.ATD0DR5HSTR.Bits.BIT15
    
    #define ATD0DR5H_BIT8_MASK          1U
    #define ATD0DR5H_BIT9_MASK          2U
    #define ATD0DR5H_BIT10_MASK         4U
    #define ATD0DR5H_BIT11_MASK         8U
    #define ATD0DR5H_BIT12_MASK         16U
    #define ATD0DR5H_BIT13_MASK         32U
    #define ATD0DR5H_BIT14_MASK         64U
    #define ATD0DR5H_BIT15_MASK         128U
    

    /*** ATD0DR5L - ATD 0 Conversion Result Register 5 Low; 0x000002DB ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATD0DR5LSTR;
    #define ATD0DR5L                    _ATD0DR5.Overlap_STR.ATD0DR5LSTR.Byte
    #define ATD0DR5L_BIT0               _ATD0DR5.Overlap_STR.ATD0DR5LSTR.Bits.BIT0
    #define ATD0DR5L_BIT1               _ATD0DR5.Overlap_STR.ATD0DR5LSTR.Bits.BIT1
    #define ATD0DR5L_BIT2               _ATD0DR5.Overlap_STR.ATD0DR5LSTR.Bits.BIT2
    #define ATD0DR5L_BIT3               _ATD0DR5.Overlap_STR.ATD0DR5LSTR.Bits.BIT3
    #define ATD0DR5L_BIT4               _ATD0DR5.Overlap_STR.ATD0DR5LSTR.Bits.BIT4
    #define ATD0DR5L_BIT5               _ATD0DR5.Overlap_STR.ATD0DR5LSTR.Bits.BIT5
    #define ATD0DR5L_BIT6               _ATD0DR5.Overlap_STR.ATD0DR5LSTR.Bits.BIT6
    #define ATD0DR5L_BIT7               _ATD0DR5.Overlap_STR.ATD0DR5LSTR.Bits.BIT7
    
    #define ATD0DR5L_BIT0_MASK          1U
    #define ATD0DR5L_BIT1_MASK          2U
    #define ATD0DR5L_BIT2_MASK          4U
    #define ATD0DR5L_BIT3_MASK          8U
    #define ATD0DR5L_BIT4_MASK          16U
    #define ATD0DR5L_BIT5_MASK          32U
    #define ATD0DR5L_BIT6_MASK          64U
    #define ATD0DR5L_BIT7_MASK          128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATD0DR5STR;
extern volatile ATD0DR5STR _ATD0DR5 @(REG_BASE + 0x000002DAUL);
#define ATD0DR5                         _ATD0DR5.Word
#define ATD0DR5_BIT0                    _ATD0DR5.Bits.BIT0
#define ATD0DR5_BIT1                    _ATD0DR5.Bits.BIT1
#define ATD0DR5_BIT2                    _ATD0DR5.Bits.BIT2
#define ATD0DR5_BIT3                    _ATD0DR5.Bits.BIT3
#define ATD0DR5_BIT4                    _ATD0DR5.Bits.BIT4
#define ATD0DR5_BIT5                    _ATD0DR5.Bits.BIT5
#define ATD0DR5_BIT6                    _ATD0DR5.Bits.BIT6
#define ATD0DR5_BIT7                    _ATD0DR5.Bits.BIT7
#define ATD0DR5_BIT8                    _ATD0DR5.Bits.BIT8
#define ATD0DR5_BIT9                    _ATD0DR5.Bits.BIT9
#define ATD0DR5_BIT10                   _ATD0DR5.Bits.BIT10
#define ATD0DR5_BIT11                   _ATD0DR5.Bits.BIT11
#define ATD0DR5_BIT12                   _ATD0DR5.Bits.BIT12
#define ATD0DR5_BIT13                   _ATD0DR5.Bits.BIT13
#define ATD0DR5_BIT14                   _ATD0DR5.Bits.BIT14
#define ATD0DR5_BIT15                   _ATD0DR5.Bits.BIT15

#define ATD0DR5_BIT0_MASK               1U
#define ATD0DR5_BIT1_MASK               2U
#define ATD0DR5_BIT2_MASK               4U
#define ATD0DR5_BIT3_MASK               8U
#define ATD0DR5_BIT4_MASK               16U
#define ATD0DR5_BIT5_MASK               32U
#define ATD0DR5_BIT6_MASK               64U
#define ATD0DR5_BIT7_MASK               128U
#define ATD0DR5_BIT8_MASK               256U
#define ATD0DR5_BIT9_MASK               512U
#define ATD0DR5_BIT10_MASK              1024U
#define ATD0DR5_BIT11_MASK              2048U
#define ATD0DR5_BIT12_MASK              4096U
#define ATD0DR5_BIT13_MASK              8192U
#define ATD0DR5_BIT14_MASK              16384U
#define ATD0DR5_BIT15_MASK              32768U


/*** ATD0DR6 - ATD 0 Conversion Result Register 6; 0x000002DC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR6H - ATD 0 Conversion Result Register 6 High; 0x000002DC ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATD0DR6HSTR;
    #define ATD0DR6H                    _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Byte
    #define ATD0DR6H_BIT8               _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT8
    #define ATD0DR6H_BIT9               _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT9
    #define ATD0DR6H_BIT10              _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT10
    #define ATD0DR6H_BIT11              _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT11
    #define ATD0DR6H_BIT12              _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT12
    #define ATD0DR6H_BIT13              _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT13
    #define ATD0DR6H_BIT14              _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT14
    #define ATD0DR6H_BIT15              _ATD0DR6.Overlap_STR.ATD0DR6HSTR.Bits.BIT15
    
    #define ATD0DR6H_BIT8_MASK          1U
    #define ATD0DR6H_BIT9_MASK          2U
    #define ATD0DR6H_BIT10_MASK         4U
    #define ATD0DR6H_BIT11_MASK         8U
    #define ATD0DR6H_BIT12_MASK         16U
    #define ATD0DR6H_BIT13_MASK         32U
    #define ATD0DR6H_BIT14_MASK         64U
    #define ATD0DR6H_BIT15_MASK         128U
    

    /*** ATD0DR6L - ATD 0 Conversion Result Register 6 Low; 0x000002DD ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATD0DR6LSTR;
    #define ATD0DR6L                    _ATD0DR6.Overlap_STR.ATD0DR6LSTR.Byte
    #define ATD0DR6L_BIT0               _ATD0DR6.Overlap_STR.ATD0DR6LSTR.Bits.BIT0
    #define ATD0DR6L_BIT1               _ATD0DR6.Overlap_STR.ATD0DR6LSTR.Bits.BIT1
    #define ATD0DR6L_BIT2               _ATD0DR6.Overlap_STR.ATD0DR6LSTR.Bits.BIT2
    #define ATD0DR6L_BIT3               _ATD0DR6.Overlap_STR.ATD0DR6LSTR.Bits.BIT3
    #define ATD0DR6L_BIT4               _ATD0DR6.Overlap_STR.ATD0DR6LSTR.Bits.BIT4
    #define ATD0DR6L_BIT5               _ATD0DR6.Overlap_STR.ATD0DR6LSTR.Bits.BIT5
    #define ATD0DR6L_BIT6               _ATD0DR6.Overlap_STR.ATD0DR6LSTR.Bits.BIT6
    #define ATD0DR6L_BIT7               _ATD0DR6.Overlap_STR.ATD0DR6LSTR.Bits.BIT7
    
    #define ATD0DR6L_BIT0_MASK          1U
    #define ATD0DR6L_BIT1_MASK          2U
    #define ATD0DR6L_BIT2_MASK          4U
    #define ATD0DR6L_BIT3_MASK          8U
    #define ATD0DR6L_BIT4_MASK          16U
    #define ATD0DR6L_BIT5_MASK          32U
    #define ATD0DR6L_BIT6_MASK          64U
    #define ATD0DR6L_BIT7_MASK          128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATD0DR6STR;
extern volatile ATD0DR6STR _ATD0DR6 @(REG_BASE + 0x000002DCUL);
#define ATD0DR6                         _ATD0DR6.Word
#define ATD0DR6_BIT0                    _ATD0DR6.Bits.BIT0
#define ATD0DR6_BIT1                    _ATD0DR6.Bits.BIT1
#define ATD0DR6_BIT2                    _ATD0DR6.Bits.BIT2
#define ATD0DR6_BIT3                    _ATD0DR6.Bits.BIT3
#define ATD0DR6_BIT4                    _ATD0DR6.Bits.BIT4
#define ATD0DR6_BIT5                    _ATD0DR6.Bits.BIT5
#define ATD0DR6_BIT6                    _ATD0DR6.Bits.BIT6
#define ATD0DR6_BIT7                    _ATD0DR6.Bits.BIT7
#define ATD0DR6_BIT8                    _ATD0DR6.Bits.BIT8
#define ATD0DR6_BIT9                    _ATD0DR6.Bits.BIT9
#define ATD0DR6_BIT10                   _ATD0DR6.Bits.BIT10
#define ATD0DR6_BIT11                   _ATD0DR6.Bits.BIT11
#define ATD0DR6_BIT12                   _ATD0DR6.Bits.BIT12
#define ATD0DR6_BIT13                   _ATD0DR6.Bits.BIT13
#define ATD0DR6_BIT14                   _ATD0DR6.Bits.BIT14
#define ATD0DR6_BIT15                   _ATD0DR6.Bits.BIT15

#define ATD0DR6_BIT0_MASK               1U
#define ATD0DR6_BIT1_MASK               2U
#define ATD0DR6_BIT2_MASK               4U
#define ATD0DR6_BIT3_MASK               8U
#define ATD0DR6_BIT4_MASK               16U
#define ATD0DR6_BIT5_MASK               32U
#define ATD0DR6_BIT6_MASK               64U
#define ATD0DR6_BIT7_MASK               128U
#define ATD0DR6_BIT8_MASK               256U
#define ATD0DR6_BIT9_MASK               512U
#define ATD0DR6_BIT10_MASK              1024U
#define ATD0DR6_BIT11_MASK              2048U
#define ATD0DR6_BIT12_MASK              4096U
#define ATD0DR6_BIT13_MASK              8192U
#define ATD0DR6_BIT14_MASK              16384U
#define ATD0DR6_BIT15_MASK              32768U


/*** ATD0DR7 - ATD 0 Conversion Result Register 7; 0x000002DE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR7H - ATD 0 Conversion Result Register 7 High; 0x000002DE ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATD0DR7HSTR;
    #define ATD0DR7H                    _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Byte
    #define ATD0DR7H_BIT8               _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT8
    #define ATD0DR7H_BIT9               _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT9
    #define ATD0DR7H_BIT10              _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT10
    #define ATD0DR7H_BIT11              _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT11
    #define ATD0DR7H_BIT12              _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT12
    #define ATD0DR7H_BIT13              _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT13
    #define ATD0DR7H_BIT14              _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT14
    #define ATD0DR7H_BIT15              _ATD0DR7.Overlap_STR.ATD0DR7HSTR.Bits.BIT15
    
    #define ATD0DR7H_BIT8_MASK          1U
    #define ATD0DR7H_BIT9_MASK          2U
    #define ATD0DR7H_BIT10_MASK         4U
    #define ATD0DR7H_BIT11_MASK         8U
    #define ATD0DR7H_BIT12_MASK         16U
    #define ATD0DR7H_BIT13_MASK         32U
    #define ATD0DR7H_BIT14_MASK         64U
    #define ATD0DR7H_BIT15_MASK         128U
    

    /*** ATD0DR7L - ATD 0 Conversion Result Register 7 Low; 0x000002DF ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATD0DR7LSTR;
    #define ATD0DR7L                    _ATD0DR7.Overlap_STR.ATD0DR7LSTR.Byte
    #define ATD0DR7L_BIT0               _ATD0DR7.Overlap_STR.ATD0DR7LSTR.Bits.BIT0
    #define ATD0DR7L_BIT1               _ATD0DR7.Overlap_STR.ATD0DR7LSTR.Bits.BIT1
    #define ATD0DR7L_BIT2               _ATD0DR7.Overlap_STR.ATD0DR7LSTR.Bits.BIT2
    #define ATD0DR7L_BIT3               _ATD0DR7.Overlap_STR.ATD0DR7LSTR.Bits.BIT3
    #define ATD0DR7L_BIT4               _ATD0DR7.Overlap_STR.ATD0DR7LSTR.Bits.BIT4
    #define ATD0DR7L_BIT5               _ATD0DR7.Overlap_STR.ATD0DR7LSTR.Bits.BIT5
    #define ATD0DR7L_BIT6               _ATD0DR7.Overlap_STR.ATD0DR7LSTR.Bits.BIT6
    #define ATD0DR7L_BIT7               _ATD0DR7.Overlap_STR.ATD0DR7LSTR.Bits.BIT7
    
    #define ATD0DR7L_BIT0_MASK          1U
    #define ATD0DR7L_BIT1_MASK          2U
    #define ATD0DR7L_BIT2_MASK          4U
    #define ATD0DR7L_BIT3_MASK          8U
    #define ATD0DR7L_BIT4_MASK          16U
    #define ATD0DR7L_BIT5_MASK          32U
    #define ATD0DR7L_BIT6_MASK          64U
    #define ATD0DR7L_BIT7_MASK          128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATD0DR7STR;
extern volatile ATD0DR7STR _ATD0DR7 @(REG_BASE + 0x000002DEUL);
#define ATD0DR7                         _ATD0DR7.Word
#define ATD0DR7_BIT0                    _ATD0DR7.Bits.BIT0
#define ATD0DR7_BIT1                    _ATD0DR7.Bits.BIT1
#define ATD0DR7_BIT2                    _ATD0DR7.Bits.BIT2
#define ATD0DR7_BIT3                    _ATD0DR7.Bits.BIT3
#define ATD0DR7_BIT4                    _ATD0DR7.Bits.BIT4
#define ATD0DR7_BIT5                    _ATD0DR7.Bits.BIT5
#define ATD0DR7_BIT6                    _ATD0DR7.Bits.BIT6
#define ATD0DR7_BIT7                    _ATD0DR7.Bits.BIT7
#define ATD0DR7_BIT8                    _ATD0DR7.Bits.BIT8
#define ATD0DR7_BIT9                    _ATD0DR7.Bits.BIT9
#define ATD0DR7_BIT10                   _ATD0DR7.Bits.BIT10
#define ATD0DR7_BIT11                   _ATD0DR7.Bits.BIT11
#define ATD0DR7_BIT12                   _ATD0DR7.Bits.BIT12
#define ATD0DR7_BIT13                   _ATD0DR7.Bits.BIT13
#define ATD0DR7_BIT14                   _ATD0DR7.Bits.BIT14
#define ATD0DR7_BIT15                   _ATD0DR7.Bits.BIT15

#define ATD0DR7_BIT0_MASK               1U
#define ATD0DR7_BIT1_MASK               2U
#define ATD0DR7_BIT2_MASK               4U
#define ATD0DR7_BIT3_MASK               8U
#define ATD0DR7_BIT4_MASK               16U
#define ATD0DR7_BIT5_MASK               32U
#define ATD0DR7_BIT6_MASK               64U
#define ATD0DR7_BIT7_MASK               128U
#define ATD0DR7_BIT8_MASK               256U
#define ATD0DR7_BIT9_MASK               512U
#define ATD0DR7_BIT10_MASK              1024U
#define ATD0DR7_BIT11_MASK              2048U
#define ATD0DR7_BIT12_MASK              4096U
#define ATD0DR7_BIT13_MASK              8192U
#define ATD0DR7_BIT14_MASK              16384U
#define ATD0DR7_BIT15_MASK              32768U


/*** ATD0DR8 - ATD 0 Conversion Result Register 8; 0x000002E0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR8H - ATD 0 Conversion Result Register 8 High; 0x000002E0 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATD0DR8HSTR;
    #define ATD0DR8H                    _ATD0DR8.Overlap_STR.ATD0DR8HSTR.Byte
    #define ATD0DR8H_BIT8               _ATD0DR8.Overlap_STR.ATD0DR8HSTR.Bits.BIT8
    #define ATD0DR8H_BIT9               _ATD0DR8.Overlap_STR.ATD0DR8HSTR.Bits.BIT9
    #define ATD0DR8H_BIT10              _ATD0DR8.Overlap_STR.ATD0DR8HSTR.Bits.BIT10
    #define ATD0DR8H_BIT11              _ATD0DR8.Overlap_STR.ATD0DR8HSTR.Bits.BIT11
    #define ATD0DR8H_BIT12              _ATD0DR8.Overlap_STR.ATD0DR8HSTR.Bits.BIT12
    #define ATD0DR8H_BIT13              _ATD0DR8.Overlap_STR.ATD0DR8HSTR.Bits.BIT13
    #define ATD0DR8H_BIT14              _ATD0DR8.Overlap_STR.ATD0DR8HSTR.Bits.BIT14
    #define ATD0DR8H_BIT15              _ATD0DR8.Overlap_STR.ATD0DR8HSTR.Bits.BIT15
    
    #define ATD0DR8H_BIT8_MASK          1U
    #define ATD0DR8H_BIT9_MASK          2U
    #define ATD0DR8H_BIT10_MASK         4U
    #define ATD0DR8H_BIT11_MASK         8U
    #define ATD0DR8H_BIT12_MASK         16U
    #define ATD0DR8H_BIT13_MASK         32U
    #define ATD0DR8H_BIT14_MASK         64U
    #define ATD0DR8H_BIT15_MASK         128U
    

    /*** ATD0DR8L - ATD 0 Conversion Result Register 8 Low; 0x000002E1 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATD0DR8LSTR;
    #define ATD0DR8L                    _ATD0DR8.Overlap_STR.ATD0DR8LSTR.Byte
    #define ATD0DR8L_BIT0               _ATD0DR8.Overlap_STR.ATD0DR8LSTR.Bits.BIT0
    #define ATD0DR8L_BIT1               _ATD0DR8.Overlap_STR.ATD0DR8LSTR.Bits.BIT1
    #define ATD0DR8L_BIT2               _ATD0DR8.Overlap_STR.ATD0DR8LSTR.Bits.BIT2
    #define ATD0DR8L_BIT3               _ATD0DR8.Overlap_STR.ATD0DR8LSTR.Bits.BIT3
    #define ATD0DR8L_BIT4               _ATD0DR8.Overlap_STR.ATD0DR8LSTR.Bits.BIT4
    #define ATD0DR8L_BIT5               _ATD0DR8.Overlap_STR.ATD0DR8LSTR.Bits.BIT5
    #define ATD0DR8L_BIT6               _ATD0DR8.Overlap_STR.ATD0DR8LSTR.Bits.BIT6
    #define ATD0DR8L_BIT7               _ATD0DR8.Overlap_STR.ATD0DR8LSTR.Bits.BIT7
    
    #define ATD0DR8L_BIT0_MASK          1U
    #define ATD0DR8L_BIT1_MASK          2U
    #define ATD0DR8L_BIT2_MASK          4U
    #define ATD0DR8L_BIT3_MASK          8U
    #define ATD0DR8L_BIT4_MASK          16U
    #define ATD0DR8L_BIT5_MASK          32U
    #define ATD0DR8L_BIT6_MASK          64U
    #define ATD0DR8L_BIT7_MASK          128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATD0DR8STR;
extern volatile ATD0DR8STR _ATD0DR8 @(REG_BASE + 0x000002E0UL);
#define ATD0DR8                         _ATD0DR8.Word
#define ATD0DR8_BIT0                    _ATD0DR8.Bits.BIT0
#define ATD0DR8_BIT1                    _ATD0DR8.Bits.BIT1
#define ATD0DR8_BIT2                    _ATD0DR8.Bits.BIT2
#define ATD0DR8_BIT3                    _ATD0DR8.Bits.BIT3
#define ATD0DR8_BIT4                    _ATD0DR8.Bits.BIT4
#define ATD0DR8_BIT5                    _ATD0DR8.Bits.BIT5
#define ATD0DR8_BIT6                    _ATD0DR8.Bits.BIT6
#define ATD0DR8_BIT7                    _ATD0DR8.Bits.BIT7
#define ATD0DR8_BIT8                    _ATD0DR8.Bits.BIT8
#define ATD0DR8_BIT9                    _ATD0DR8.Bits.BIT9
#define ATD0DR8_BIT10                   _ATD0DR8.Bits.BIT10
#define ATD0DR8_BIT11                   _ATD0DR8.Bits.BIT11
#define ATD0DR8_BIT12                   _ATD0DR8.Bits.BIT12
#define ATD0DR8_BIT13                   _ATD0DR8.Bits.BIT13
#define ATD0DR8_BIT14                   _ATD0DR8.Bits.BIT14
#define ATD0DR8_BIT15                   _ATD0DR8.Bits.BIT15

#define ATD0DR8_BIT0_MASK               1U
#define ATD0DR8_BIT1_MASK               2U
#define ATD0DR8_BIT2_MASK               4U
#define ATD0DR8_BIT3_MASK               8U
#define ATD0DR8_BIT4_MASK               16U
#define ATD0DR8_BIT5_MASK               32U
#define ATD0DR8_BIT6_MASK               64U
#define ATD0DR8_BIT7_MASK               128U
#define ATD0DR8_BIT8_MASK               256U
#define ATD0DR8_BIT9_MASK               512U
#define ATD0DR8_BIT10_MASK              1024U
#define ATD0DR8_BIT11_MASK              2048U
#define ATD0DR8_BIT12_MASK              4096U
#define ATD0DR8_BIT13_MASK              8192U
#define ATD0DR8_BIT14_MASK              16384U
#define ATD0DR8_BIT15_MASK              32768U


/*** ATD0DR9 - ATD 0 Conversion Result Register 9; 0x000002E2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR9H - ATD 0 Conversion Result Register 9 High; 0x000002E2 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATD0DR9HSTR;
    #define ATD0DR9H                    _ATD0DR9.Overlap_STR.ATD0DR9HSTR.Byte
    #define ATD0DR9H_BIT8               _ATD0DR9.Overlap_STR.ATD0DR9HSTR.Bits.BIT8
    #define ATD0DR9H_BIT9               _ATD0DR9.Overlap_STR.ATD0DR9HSTR.Bits.BIT9
    #define ATD0DR9H_BIT10              _ATD0DR9.Overlap_STR.ATD0DR9HSTR.Bits.BIT10
    #define ATD0DR9H_BIT11              _ATD0DR9.Overlap_STR.ATD0DR9HSTR.Bits.BIT11
    #define ATD0DR9H_BIT12              _ATD0DR9.Overlap_STR.ATD0DR9HSTR.Bits.BIT12
    #define ATD0DR9H_BIT13              _ATD0DR9.Overlap_STR.ATD0DR9HSTR.Bits.BIT13
    #define ATD0DR9H_BIT14              _ATD0DR9.Overlap_STR.ATD0DR9HSTR.Bits.BIT14
    #define ATD0DR9H_BIT15              _ATD0DR9.Overlap_STR.ATD0DR9HSTR.Bits.BIT15
    
    #define ATD0DR9H_BIT8_MASK          1U
    #define ATD0DR9H_BIT9_MASK          2U
    #define ATD0DR9H_BIT10_MASK         4U
    #define ATD0DR9H_BIT11_MASK         8U
    #define ATD0DR9H_BIT12_MASK         16U
    #define ATD0DR9H_BIT13_MASK         32U
    #define ATD0DR9H_BIT14_MASK         64U
    #define ATD0DR9H_BIT15_MASK         128U
    

    /*** ATD0DR9L - ATD 0 Conversion Result Register 9 Low; 0x000002E3 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATD0DR9LSTR;
    #define ATD0DR9L                    _ATD0DR9.Overlap_STR.ATD0DR9LSTR.Byte
    #define ATD0DR9L_BIT0               _ATD0DR9.Overlap_STR.ATD0DR9LSTR.Bits.BIT0
    #define ATD0DR9L_BIT1               _ATD0DR9.Overlap_STR.ATD0DR9LSTR.Bits.BIT1
    #define ATD0DR9L_BIT2               _ATD0DR9.Overlap_STR.ATD0DR9LSTR.Bits.BIT2
    #define ATD0DR9L_BIT3               _ATD0DR9.Overlap_STR.ATD0DR9LSTR.Bits.BIT3
    #define ATD0DR9L_BIT4               _ATD0DR9.Overlap_STR.ATD0DR9LSTR.Bits.BIT4
    #define ATD0DR9L_BIT5               _ATD0DR9.Overlap_STR.ATD0DR9LSTR.Bits.BIT5
    #define ATD0DR9L_BIT6               _ATD0DR9.Overlap_STR.ATD0DR9LSTR.Bits.BIT6
    #define ATD0DR9L_BIT7               _ATD0DR9.Overlap_STR.ATD0DR9LSTR.Bits.BIT7
    
    #define ATD0DR9L_BIT0_MASK          1U
    #define ATD0DR9L_BIT1_MASK          2U
    #define ATD0DR9L_BIT2_MASK          4U
    #define ATD0DR9L_BIT3_MASK          8U
    #define ATD0DR9L_BIT4_MASK          16U
    #define ATD0DR9L_BIT5_MASK          32U
    #define ATD0DR9L_BIT6_MASK          64U
    #define ATD0DR9L_BIT7_MASK          128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATD0DR9STR;
extern volatile ATD0DR9STR _ATD0DR9 @(REG_BASE + 0x000002E2UL);
#define ATD0DR9                         _ATD0DR9.Word
#define ATD0DR9_BIT0                    _ATD0DR9.Bits.BIT0
#define ATD0DR9_BIT1                    _ATD0DR9.Bits.BIT1
#define ATD0DR9_BIT2                    _ATD0DR9.Bits.BIT2
#define ATD0DR9_BIT3                    _ATD0DR9.Bits.BIT3
#define ATD0DR9_BIT4                    _ATD0DR9.Bits.BIT4
#define ATD0DR9_BIT5                    _ATD0DR9.Bits.BIT5
#define ATD0DR9_BIT6                    _ATD0DR9.Bits.BIT6
#define ATD0DR9_BIT7                    _ATD0DR9.Bits.BIT7
#define ATD0DR9_BIT8                    _ATD0DR9.Bits.BIT8
#define ATD0DR9_BIT9                    _ATD0DR9.Bits.BIT9
#define ATD0DR9_BIT10                   _ATD0DR9.Bits.BIT10
#define ATD0DR9_BIT11                   _ATD0DR9.Bits.BIT11
#define ATD0DR9_BIT12                   _ATD0DR9.Bits.BIT12
#define ATD0DR9_BIT13                   _ATD0DR9.Bits.BIT13
#define ATD0DR9_BIT14                   _ATD0DR9.Bits.BIT14
#define ATD0DR9_BIT15                   _ATD0DR9.Bits.BIT15

#define ATD0DR9_BIT0_MASK               1U
#define ATD0DR9_BIT1_MASK               2U
#define ATD0DR9_BIT2_MASK               4U
#define ATD0DR9_BIT3_MASK               8U
#define ATD0DR9_BIT4_MASK               16U
#define ATD0DR9_BIT5_MASK               32U
#define ATD0DR9_BIT6_MASK               64U
#define ATD0DR9_BIT7_MASK               128U
#define ATD0DR9_BIT8_MASK               256U
#define ATD0DR9_BIT9_MASK               512U
#define ATD0DR9_BIT10_MASK              1024U
#define ATD0DR9_BIT11_MASK              2048U
#define ATD0DR9_BIT12_MASK              4096U
#define ATD0DR9_BIT13_MASK              8192U
#define ATD0DR9_BIT14_MASK              16384U
#define ATD0DR9_BIT15_MASK              32768U


/*** ATD0DR10 - ATD 0 Conversion Result Register 10; 0x000002E4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR10H - ATD 0 Conversion Result Register 10 High; 0x000002E4 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATD0DR10HSTR;
    #define ATD0DR10H                   _ATD0DR10.Overlap_STR.ATD0DR10HSTR.Byte
    #define ATD0DR10H_BIT8              _ATD0DR10.Overlap_STR.ATD0DR10HSTR.Bits.BIT8
    #define ATD0DR10H_BIT9              _ATD0DR10.Overlap_STR.ATD0DR10HSTR.Bits.BIT9
    #define ATD0DR10H_BIT10             _ATD0DR10.Overlap_STR.ATD0DR10HSTR.Bits.BIT10
    #define ATD0DR10H_BIT11             _ATD0DR10.Overlap_STR.ATD0DR10HSTR.Bits.BIT11
    #define ATD0DR10H_BIT12             _ATD0DR10.Overlap_STR.ATD0DR10HSTR.Bits.BIT12
    #define ATD0DR10H_BIT13             _ATD0DR10.Overlap_STR.ATD0DR10HSTR.Bits.BIT13
    #define ATD0DR10H_BIT14             _ATD0DR10.Overlap_STR.ATD0DR10HSTR.Bits.BIT14
    #define ATD0DR10H_BIT15             _ATD0DR10.Overlap_STR.ATD0DR10HSTR.Bits.BIT15
    
    #define ATD0DR10H_BIT8_MASK         1U
    #define ATD0DR10H_BIT9_MASK         2U
    #define ATD0DR10H_BIT10_MASK        4U
    #define ATD0DR10H_BIT11_MASK        8U
    #define ATD0DR10H_BIT12_MASK        16U
    #define ATD0DR10H_BIT13_MASK        32U
    #define ATD0DR10H_BIT14_MASK        64U
    #define ATD0DR10H_BIT15_MASK        128U
    

    /*** ATD0DR10L - ATD 0 Conversion Result Register 10 Low; 0x000002E5 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATD0DR10LSTR;
    #define ATD0DR10L                   _ATD0DR10.Overlap_STR.ATD0DR10LSTR.Byte
    #define ATD0DR10L_BIT0              _ATD0DR10.Overlap_STR.ATD0DR10LSTR.Bits.BIT0
    #define ATD0DR10L_BIT1              _ATD0DR10.Overlap_STR.ATD0DR10LSTR.Bits.BIT1
    #define ATD0DR10L_BIT2              _ATD0DR10.Overlap_STR.ATD0DR10LSTR.Bits.BIT2
    #define ATD0DR10L_BIT3              _ATD0DR10.Overlap_STR.ATD0DR10LSTR.Bits.BIT3
    #define ATD0DR10L_BIT4              _ATD0DR10.Overlap_STR.ATD0DR10LSTR.Bits.BIT4
    #define ATD0DR10L_BIT5              _ATD0DR10.Overlap_STR.ATD0DR10LSTR.Bits.BIT5
    #define ATD0DR10L_BIT6              _ATD0DR10.Overlap_STR.ATD0DR10LSTR.Bits.BIT6
    #define ATD0DR10L_BIT7              _ATD0DR10.Overlap_STR.ATD0DR10LSTR.Bits.BIT7
    
    #define ATD0DR10L_BIT0_MASK         1U
    #define ATD0DR10L_BIT1_MASK         2U
    #define ATD0DR10L_BIT2_MASK         4U
    #define ATD0DR10L_BIT3_MASK         8U
    #define ATD0DR10L_BIT4_MASK         16U
    #define ATD0DR10L_BIT5_MASK         32U
    #define ATD0DR10L_BIT6_MASK         64U
    #define ATD0DR10L_BIT7_MASK         128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATD0DR10STR;
extern volatile ATD0DR10STR _ATD0DR10 @(REG_BASE + 0x000002E4UL);
#define ATD0DR10                        _ATD0DR10.Word
#define ATD0DR10_BIT0                   _ATD0DR10.Bits.BIT0
#define ATD0DR10_BIT1                   _ATD0DR10.Bits.BIT1
#define ATD0DR10_BIT2                   _ATD0DR10.Bits.BIT2
#define ATD0DR10_BIT3                   _ATD0DR10.Bits.BIT3
#define ATD0DR10_BIT4                   _ATD0DR10.Bits.BIT4
#define ATD0DR10_BIT5                   _ATD0DR10.Bits.BIT5
#define ATD0DR10_BIT6                   _ATD0DR10.Bits.BIT6
#define ATD0DR10_BIT7                   _ATD0DR10.Bits.BIT7
#define ATD0DR10_BIT8                   _ATD0DR10.Bits.BIT8
#define ATD0DR10_BIT9                   _ATD0DR10.Bits.BIT9
#define ATD0DR10_BIT10                  _ATD0DR10.Bits.BIT10
#define ATD0DR10_BIT11                  _ATD0DR10.Bits.BIT11
#define ATD0DR10_BIT12                  _ATD0DR10.Bits.BIT12
#define ATD0DR10_BIT13                  _ATD0DR10.Bits.BIT13
#define ATD0DR10_BIT14                  _ATD0DR10.Bits.BIT14
#define ATD0DR10_BIT15                  _ATD0DR10.Bits.BIT15

#define ATD0DR10_BIT0_MASK              1U
#define ATD0DR10_BIT1_MASK              2U
#define ATD0DR10_BIT2_MASK              4U
#define ATD0DR10_BIT3_MASK              8U
#define ATD0DR10_BIT4_MASK              16U
#define ATD0DR10_BIT5_MASK              32U
#define ATD0DR10_BIT6_MASK              64U
#define ATD0DR10_BIT7_MASK              128U
#define ATD0DR10_BIT8_MASK              256U
#define ATD0DR10_BIT9_MASK              512U
#define ATD0DR10_BIT10_MASK             1024U
#define ATD0DR10_BIT11_MASK             2048U
#define ATD0DR10_BIT12_MASK             4096U
#define ATD0DR10_BIT13_MASK             8192U
#define ATD0DR10_BIT14_MASK             16384U
#define ATD0DR10_BIT15_MASK             32768U


/*** ATD0DR11 - ATD 0 Conversion Result Register 11; 0x000002E6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR11H - ATD 0 Conversion Result Register 11 High; 0x000002E6 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATD0DR11HSTR;
    #define ATD0DR11H                   _ATD0DR11.Overlap_STR.ATD0DR11HSTR.Byte
    #define ATD0DR11H_BIT8              _ATD0DR11.Overlap_STR.ATD0DR11HSTR.Bits.BIT8
    #define ATD0DR11H_BIT9              _ATD0DR11.Overlap_STR.ATD0DR11HSTR.Bits.BIT9
    #define ATD0DR11H_BIT10             _ATD0DR11.Overlap_STR.ATD0DR11HSTR.Bits.BIT10
    #define ATD0DR11H_BIT11             _ATD0DR11.Overlap_STR.ATD0DR11HSTR.Bits.BIT11
    #define ATD0DR11H_BIT12             _ATD0DR11.Overlap_STR.ATD0DR11HSTR.Bits.BIT12
    #define ATD0DR11H_BIT13             _ATD0DR11.Overlap_STR.ATD0DR11HSTR.Bits.BIT13
    #define ATD0DR11H_BIT14             _ATD0DR11.Overlap_STR.ATD0DR11HSTR.Bits.BIT14
    #define ATD0DR11H_BIT15             _ATD0DR11.Overlap_STR.ATD0DR11HSTR.Bits.BIT15
    
    #define ATD0DR11H_BIT8_MASK         1U
    #define ATD0DR11H_BIT9_MASK         2U
    #define ATD0DR11H_BIT10_MASK        4U
    #define ATD0DR11H_BIT11_MASK        8U
    #define ATD0DR11H_BIT12_MASK        16U
    #define ATD0DR11H_BIT13_MASK        32U
    #define ATD0DR11H_BIT14_MASK        64U
    #define ATD0DR11H_BIT15_MASK        128U
    

    /*** ATD0DR11L - ATD 0 Conversion Result Register 11 Low; 0x000002E7 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATD0DR11LSTR;
    #define ATD0DR11L                   _ATD0DR11.Overlap_STR.ATD0DR11LSTR.Byte
    #define ATD0DR11L_BIT0              _ATD0DR11.Overlap_STR.ATD0DR11LSTR.Bits.BIT0
    #define ATD0DR11L_BIT1              _ATD0DR11.Overlap_STR.ATD0DR11LSTR.Bits.BIT1
    #define ATD0DR11L_BIT2              _ATD0DR11.Overlap_STR.ATD0DR11LSTR.Bits.BIT2
    #define ATD0DR11L_BIT3              _ATD0DR11.Overlap_STR.ATD0DR11LSTR.Bits.BIT3
    #define ATD0DR11L_BIT4              _ATD0DR11.Overlap_STR.ATD0DR11LSTR.Bits.BIT4
    #define ATD0DR11L_BIT5              _ATD0DR11.Overlap_STR.ATD0DR11LSTR.Bits.BIT5
    #define ATD0DR11L_BIT6              _ATD0DR11.Overlap_STR.ATD0DR11LSTR.Bits.BIT6
    #define ATD0DR11L_BIT7              _ATD0DR11.Overlap_STR.ATD0DR11LSTR.Bits.BIT7
    
    #define ATD0DR11L_BIT0_MASK         1U
    #define ATD0DR11L_BIT1_MASK         2U
    #define ATD0DR11L_BIT2_MASK         4U
    #define ATD0DR11L_BIT3_MASK         8U
    #define ATD0DR11L_BIT4_MASK         16U
    #define ATD0DR11L_BIT5_MASK         32U
    #define ATD0DR11L_BIT6_MASK         64U
    #define ATD0DR11L_BIT7_MASK         128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATD0DR11STR;
extern volatile ATD0DR11STR _ATD0DR11 @(REG_BASE + 0x000002E6UL);
#define ATD0DR11                        _ATD0DR11.Word
#define ATD0DR11_BIT0                   _ATD0DR11.Bits.BIT0
#define ATD0DR11_BIT1                   _ATD0DR11.Bits.BIT1
#define ATD0DR11_BIT2                   _ATD0DR11.Bits.BIT2
#define ATD0DR11_BIT3                   _ATD0DR11.Bits.BIT3
#define ATD0DR11_BIT4                   _ATD0DR11.Bits.BIT4
#define ATD0DR11_BIT5                   _ATD0DR11.Bits.BIT5
#define ATD0DR11_BIT6                   _ATD0DR11.Bits.BIT6
#define ATD0DR11_BIT7                   _ATD0DR11.Bits.BIT7
#define ATD0DR11_BIT8                   _ATD0DR11.Bits.BIT8
#define ATD0DR11_BIT9                   _ATD0DR11.Bits.BIT9
#define ATD0DR11_BIT10                  _ATD0DR11.Bits.BIT10
#define ATD0DR11_BIT11                  _ATD0DR11.Bits.BIT11
#define ATD0DR11_BIT12                  _ATD0DR11.Bits.BIT12
#define ATD0DR11_BIT13                  _ATD0DR11.Bits.BIT13
#define ATD0DR11_BIT14                  _ATD0DR11.Bits.BIT14
#define ATD0DR11_BIT15                  _ATD0DR11.Bits.BIT15

#define ATD0DR11_BIT0_MASK              1U
#define ATD0DR11_BIT1_MASK              2U
#define ATD0DR11_BIT2_MASK              4U
#define ATD0DR11_BIT3_MASK              8U
#define ATD0DR11_BIT4_MASK              16U
#define ATD0DR11_BIT5_MASK              32U
#define ATD0DR11_BIT6_MASK              64U
#define ATD0DR11_BIT7_MASK              128U
#define ATD0DR11_BIT8_MASK              256U
#define ATD0DR11_BIT9_MASK              512U
#define ATD0DR11_BIT10_MASK             1024U
#define ATD0DR11_BIT11_MASK             2048U
#define ATD0DR11_BIT12_MASK             4096U
#define ATD0DR11_BIT13_MASK             8192U
#define ATD0DR11_BIT14_MASK             16384U
#define ATD0DR11_BIT15_MASK             32768U


/*** ATD0DR12 - ATD 0 Conversion Result Register 12; 0x000002E8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR12H - ATD 0 Conversion Result Register 12 High; 0x000002E8 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATD0DR12HSTR;
    #define ATD0DR12H                   _ATD0DR12.Overlap_STR.ATD0DR12HSTR.Byte
    #define ATD0DR12H_BIT8              _ATD0DR12.Overlap_STR.ATD0DR12HSTR.Bits.BIT8
    #define ATD0DR12H_BIT9              _ATD0DR12.Overlap_STR.ATD0DR12HSTR.Bits.BIT9
    #define ATD0DR12H_BIT10             _ATD0DR12.Overlap_STR.ATD0DR12HSTR.Bits.BIT10
    #define ATD0DR12H_BIT11             _ATD0DR12.Overlap_STR.ATD0DR12HSTR.Bits.BIT11
    #define ATD0DR12H_BIT12             _ATD0DR12.Overlap_STR.ATD0DR12HSTR.Bits.BIT12
    #define ATD0DR12H_BIT13             _ATD0DR12.Overlap_STR.ATD0DR12HSTR.Bits.BIT13
    #define ATD0DR12H_BIT14             _ATD0DR12.Overlap_STR.ATD0DR12HSTR.Bits.BIT14
    #define ATD0DR12H_BIT15             _ATD0DR12.Overlap_STR.ATD0DR12HSTR.Bits.BIT15
    
    #define ATD0DR12H_BIT8_MASK         1U
    #define ATD0DR12H_BIT9_MASK         2U
    #define ATD0DR12H_BIT10_MASK        4U
    #define ATD0DR12H_BIT11_MASK        8U
    #define ATD0DR12H_BIT12_MASK        16U
    #define ATD0DR12H_BIT13_MASK        32U
    #define ATD0DR12H_BIT14_MASK        64U
    #define ATD0DR12H_BIT15_MASK        128U
    

    /*** ATD0DR12L - ATD 0 Conversion Result Register 12 Low; 0x000002E9 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATD0DR12LSTR;
    #define ATD0DR12L                   _ATD0DR12.Overlap_STR.ATD0DR12LSTR.Byte
    #define ATD0DR12L_BIT0              _ATD0DR12.Overlap_STR.ATD0DR12LSTR.Bits.BIT0
    #define ATD0DR12L_BIT1              _ATD0DR12.Overlap_STR.ATD0DR12LSTR.Bits.BIT1
    #define ATD0DR12L_BIT2              _ATD0DR12.Overlap_STR.ATD0DR12LSTR.Bits.BIT2
    #define ATD0DR12L_BIT3              _ATD0DR12.Overlap_STR.ATD0DR12LSTR.Bits.BIT3
    #define ATD0DR12L_BIT4              _ATD0DR12.Overlap_STR.ATD0DR12LSTR.Bits.BIT4
    #define ATD0DR12L_BIT5              _ATD0DR12.Overlap_STR.ATD0DR12LSTR.Bits.BIT5
    #define ATD0DR12L_BIT6              _ATD0DR12.Overlap_STR.ATD0DR12LSTR.Bits.BIT6
    #define ATD0DR12L_BIT7              _ATD0DR12.Overlap_STR.ATD0DR12LSTR.Bits.BIT7
    
    #define ATD0DR12L_BIT0_MASK         1U
    #define ATD0DR12L_BIT1_MASK         2U
    #define ATD0DR12L_BIT2_MASK         4U
    #define ATD0DR12L_BIT3_MASK         8U
    #define ATD0DR12L_BIT4_MASK         16U
    #define ATD0DR12L_BIT5_MASK         32U
    #define ATD0DR12L_BIT6_MASK         64U
    #define ATD0DR12L_BIT7_MASK         128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATD0DR12STR;
extern volatile ATD0DR12STR _ATD0DR12 @(REG_BASE + 0x000002E8UL);
#define ATD0DR12                        _ATD0DR12.Word
#define ATD0DR12_BIT0                   _ATD0DR12.Bits.BIT0
#define ATD0DR12_BIT1                   _ATD0DR12.Bits.BIT1
#define ATD0DR12_BIT2                   _ATD0DR12.Bits.BIT2
#define ATD0DR12_BIT3                   _ATD0DR12.Bits.BIT3
#define ATD0DR12_BIT4                   _ATD0DR12.Bits.BIT4
#define ATD0DR12_BIT5                   _ATD0DR12.Bits.BIT5
#define ATD0DR12_BIT6                   _ATD0DR12.Bits.BIT6
#define ATD0DR12_BIT7                   _ATD0DR12.Bits.BIT7
#define ATD0DR12_BIT8                   _ATD0DR12.Bits.BIT8
#define ATD0DR12_BIT9                   _ATD0DR12.Bits.BIT9
#define ATD0DR12_BIT10                  _ATD0DR12.Bits.BIT10
#define ATD0DR12_BIT11                  _ATD0DR12.Bits.BIT11
#define ATD0DR12_BIT12                  _ATD0DR12.Bits.BIT12
#define ATD0DR12_BIT13                  _ATD0DR12.Bits.BIT13
#define ATD0DR12_BIT14                  _ATD0DR12.Bits.BIT14
#define ATD0DR12_BIT15                  _ATD0DR12.Bits.BIT15

#define ATD0DR12_BIT0_MASK              1U
#define ATD0DR12_BIT1_MASK              2U
#define ATD0DR12_BIT2_MASK              4U
#define ATD0DR12_BIT3_MASK              8U
#define ATD0DR12_BIT4_MASK              16U
#define ATD0DR12_BIT5_MASK              32U
#define ATD0DR12_BIT6_MASK              64U
#define ATD0DR12_BIT7_MASK              128U
#define ATD0DR12_BIT8_MASK              256U
#define ATD0DR12_BIT9_MASK              512U
#define ATD0DR12_BIT10_MASK             1024U
#define ATD0DR12_BIT11_MASK             2048U
#define ATD0DR12_BIT12_MASK             4096U
#define ATD0DR12_BIT13_MASK             8192U
#define ATD0DR12_BIT14_MASK             16384U
#define ATD0DR12_BIT15_MASK             32768U


/*** ATD0DR13 - ATD 0 Conversion Result Register 13; 0x000002EA ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR13H - ATD 0 Conversion Result Register 13 High; 0x000002EA ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATD0DR13HSTR;
    #define ATD0DR13H                   _ATD0DR13.Overlap_STR.ATD0DR13HSTR.Byte
    #define ATD0DR13H_BIT8              _ATD0DR13.Overlap_STR.ATD0DR13HSTR.Bits.BIT8
    #define ATD0DR13H_BIT9              _ATD0DR13.Overlap_STR.ATD0DR13HSTR.Bits.BIT9
    #define ATD0DR13H_BIT10             _ATD0DR13.Overlap_STR.ATD0DR13HSTR.Bits.BIT10
    #define ATD0DR13H_BIT11             _ATD0DR13.Overlap_STR.ATD0DR13HSTR.Bits.BIT11
    #define ATD0DR13H_BIT12             _ATD0DR13.Overlap_STR.ATD0DR13HSTR.Bits.BIT12
    #define ATD0DR13H_BIT13             _ATD0DR13.Overlap_STR.ATD0DR13HSTR.Bits.BIT13
    #define ATD0DR13H_BIT14             _ATD0DR13.Overlap_STR.ATD0DR13HSTR.Bits.BIT14
    #define ATD0DR13H_BIT15             _ATD0DR13.Overlap_STR.ATD0DR13HSTR.Bits.BIT15
    
    #define ATD0DR13H_BIT8_MASK         1U
    #define ATD0DR13H_BIT9_MASK         2U
    #define ATD0DR13H_BIT10_MASK        4U
    #define ATD0DR13H_BIT11_MASK        8U
    #define ATD0DR13H_BIT12_MASK        16U
    #define ATD0DR13H_BIT13_MASK        32U
    #define ATD0DR13H_BIT14_MASK        64U
    #define ATD0DR13H_BIT15_MASK        128U
    

    /*** ATD0DR13L - ATD 0 Conversion Result Register 13 Low; 0x000002EB ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATD0DR13LSTR;
    #define ATD0DR13L                   _ATD0DR13.Overlap_STR.ATD0DR13LSTR.Byte
    #define ATD0DR13L_BIT0              _ATD0DR13.Overlap_STR.ATD0DR13LSTR.Bits.BIT0
    #define ATD0DR13L_BIT1              _ATD0DR13.Overlap_STR.ATD0DR13LSTR.Bits.BIT1
    #define ATD0DR13L_BIT2              _ATD0DR13.Overlap_STR.ATD0DR13LSTR.Bits.BIT2
    #define ATD0DR13L_BIT3              _ATD0DR13.Overlap_STR.ATD0DR13LSTR.Bits.BIT3
    #define ATD0DR13L_BIT4              _ATD0DR13.Overlap_STR.ATD0DR13LSTR.Bits.BIT4
    #define ATD0DR13L_BIT5              _ATD0DR13.Overlap_STR.ATD0DR13LSTR.Bits.BIT5
    #define ATD0DR13L_BIT6              _ATD0DR13.Overlap_STR.ATD0DR13LSTR.Bits.BIT6
    #define ATD0DR13L_BIT7              _ATD0DR13.Overlap_STR.ATD0DR13LSTR.Bits.BIT7
    
    #define ATD0DR13L_BIT0_MASK         1U
    #define ATD0DR13L_BIT1_MASK         2U
    #define ATD0DR13L_BIT2_MASK         4U
    #define ATD0DR13L_BIT3_MASK         8U
    #define ATD0DR13L_BIT4_MASK         16U
    #define ATD0DR13L_BIT5_MASK         32U
    #define ATD0DR13L_BIT6_MASK         64U
    #define ATD0DR13L_BIT7_MASK         128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATD0DR13STR;
extern volatile ATD0DR13STR _ATD0DR13 @(REG_BASE + 0x000002EAUL);
#define ATD0DR13                        _ATD0DR13.Word
#define ATD0DR13_BIT0                   _ATD0DR13.Bits.BIT0
#define ATD0DR13_BIT1                   _ATD0DR13.Bits.BIT1
#define ATD0DR13_BIT2                   _ATD0DR13.Bits.BIT2
#define ATD0DR13_BIT3                   _ATD0DR13.Bits.BIT3
#define ATD0DR13_BIT4                   _ATD0DR13.Bits.BIT4
#define ATD0DR13_BIT5                   _ATD0DR13.Bits.BIT5
#define ATD0DR13_BIT6                   _ATD0DR13.Bits.BIT6
#define ATD0DR13_BIT7                   _ATD0DR13.Bits.BIT7
#define ATD0DR13_BIT8                   _ATD0DR13.Bits.BIT8
#define ATD0DR13_BIT9                   _ATD0DR13.Bits.BIT9
#define ATD0DR13_BIT10                  _ATD0DR13.Bits.BIT10
#define ATD0DR13_BIT11                  _ATD0DR13.Bits.BIT11
#define ATD0DR13_BIT12                  _ATD0DR13.Bits.BIT12
#define ATD0DR13_BIT13                  _ATD0DR13.Bits.BIT13
#define ATD0DR13_BIT14                  _ATD0DR13.Bits.BIT14
#define ATD0DR13_BIT15                  _ATD0DR13.Bits.BIT15

#define ATD0DR13_BIT0_MASK              1U
#define ATD0DR13_BIT1_MASK              2U
#define ATD0DR13_BIT2_MASK              4U
#define ATD0DR13_BIT3_MASK              8U
#define ATD0DR13_BIT4_MASK              16U
#define ATD0DR13_BIT5_MASK              32U
#define ATD0DR13_BIT6_MASK              64U
#define ATD0DR13_BIT7_MASK              128U
#define ATD0DR13_BIT8_MASK              256U
#define ATD0DR13_BIT9_MASK              512U
#define ATD0DR13_BIT10_MASK             1024U
#define ATD0DR13_BIT11_MASK             2048U
#define ATD0DR13_BIT12_MASK             4096U
#define ATD0DR13_BIT13_MASK             8192U
#define ATD0DR13_BIT14_MASK             16384U
#define ATD0DR13_BIT15_MASK             32768U


/*** ATD0DR14 - ATD 0 Conversion Result Register 14; 0x000002EC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR14H - ATD 0 Conversion Result Register 14 High; 0x000002EC ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATD0DR14HSTR;
    #define ATD0DR14H                   _ATD0DR14.Overlap_STR.ATD0DR14HSTR.Byte
    #define ATD0DR14H_BIT8              _ATD0DR14.Overlap_STR.ATD0DR14HSTR.Bits.BIT8
    #define ATD0DR14H_BIT9              _ATD0DR14.Overlap_STR.ATD0DR14HSTR.Bits.BIT9
    #define ATD0DR14H_BIT10             _ATD0DR14.Overlap_STR.ATD0DR14HSTR.Bits.BIT10
    #define ATD0DR14H_BIT11             _ATD0DR14.Overlap_STR.ATD0DR14HSTR.Bits.BIT11
    #define ATD0DR14H_BIT12             _ATD0DR14.Overlap_STR.ATD0DR14HSTR.Bits.BIT12
    #define ATD0DR14H_BIT13             _ATD0DR14.Overlap_STR.ATD0DR14HSTR.Bits.BIT13
    #define ATD0DR14H_BIT14             _ATD0DR14.Overlap_STR.ATD0DR14HSTR.Bits.BIT14
    #define ATD0DR14H_BIT15             _ATD0DR14.Overlap_STR.ATD0DR14HSTR.Bits.BIT15
    
    #define ATD0DR14H_BIT8_MASK         1U
    #define ATD0DR14H_BIT9_MASK         2U
    #define ATD0DR14H_BIT10_MASK        4U
    #define ATD0DR14H_BIT11_MASK        8U
    #define ATD0DR14H_BIT12_MASK        16U
    #define ATD0DR14H_BIT13_MASK        32U
    #define ATD0DR14H_BIT14_MASK        64U
    #define ATD0DR14H_BIT15_MASK        128U
    

    /*** ATD0DR14L - ATD 0 Conversion Result Register 14 Low; 0x000002ED ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATD0DR14LSTR;
    #define ATD0DR14L                   _ATD0DR14.Overlap_STR.ATD0DR14LSTR.Byte
    #define ATD0DR14L_BIT0              _ATD0DR14.Overlap_STR.ATD0DR14LSTR.Bits.BIT0
    #define ATD0DR14L_BIT1              _ATD0DR14.Overlap_STR.ATD0DR14LSTR.Bits.BIT1
    #define ATD0DR14L_BIT2              _ATD0DR14.Overlap_STR.ATD0DR14LSTR.Bits.BIT2
    #define ATD0DR14L_BIT3              _ATD0DR14.Overlap_STR.ATD0DR14LSTR.Bits.BIT3
    #define ATD0DR14L_BIT4              _ATD0DR14.Overlap_STR.ATD0DR14LSTR.Bits.BIT4
    #define ATD0DR14L_BIT5              _ATD0DR14.Overlap_STR.ATD0DR14LSTR.Bits.BIT5
    #define ATD0DR14L_BIT6              _ATD0DR14.Overlap_STR.ATD0DR14LSTR.Bits.BIT6
    #define ATD0DR14L_BIT7              _ATD0DR14.Overlap_STR.ATD0DR14LSTR.Bits.BIT7
    
    #define ATD0DR14L_BIT0_MASK         1U
    #define ATD0DR14L_BIT1_MASK         2U
    #define ATD0DR14L_BIT2_MASK         4U
    #define ATD0DR14L_BIT3_MASK         8U
    #define ATD0DR14L_BIT4_MASK         16U
    #define ATD0DR14L_BIT5_MASK         32U
    #define ATD0DR14L_BIT6_MASK         64U
    #define ATD0DR14L_BIT7_MASK         128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATD0DR14STR;
extern volatile ATD0DR14STR _ATD0DR14 @(REG_BASE + 0x000002ECUL);
#define ATD0DR14                        _ATD0DR14.Word
#define ATD0DR14_BIT0                   _ATD0DR14.Bits.BIT0
#define ATD0DR14_BIT1                   _ATD0DR14.Bits.BIT1
#define ATD0DR14_BIT2                   _ATD0DR14.Bits.BIT2
#define ATD0DR14_BIT3                   _ATD0DR14.Bits.BIT3
#define ATD0DR14_BIT4                   _ATD0DR14.Bits.BIT4
#define ATD0DR14_BIT5                   _ATD0DR14.Bits.BIT5
#define ATD0DR14_BIT6                   _ATD0DR14.Bits.BIT6
#define ATD0DR14_BIT7                   _ATD0DR14.Bits.BIT7
#define ATD0DR14_BIT8                   _ATD0DR14.Bits.BIT8
#define ATD0DR14_BIT9                   _ATD0DR14.Bits.BIT9
#define ATD0DR14_BIT10                  _ATD0DR14.Bits.BIT10
#define ATD0DR14_BIT11                  _ATD0DR14.Bits.BIT11
#define ATD0DR14_BIT12                  _ATD0DR14.Bits.BIT12
#define ATD0DR14_BIT13                  _ATD0DR14.Bits.BIT13
#define ATD0DR14_BIT14                  _ATD0DR14.Bits.BIT14
#define ATD0DR14_BIT15                  _ATD0DR14.Bits.BIT15

#define ATD0DR14_BIT0_MASK              1U
#define ATD0DR14_BIT1_MASK              2U
#define ATD0DR14_BIT2_MASK              4U
#define ATD0DR14_BIT3_MASK              8U
#define ATD0DR14_BIT4_MASK              16U
#define ATD0DR14_BIT5_MASK              32U
#define ATD0DR14_BIT6_MASK              64U
#define ATD0DR14_BIT7_MASK              128U
#define ATD0DR14_BIT8_MASK              256U
#define ATD0DR14_BIT9_MASK              512U
#define ATD0DR14_BIT10_MASK             1024U
#define ATD0DR14_BIT11_MASK             2048U
#define ATD0DR14_BIT12_MASK             4096U
#define ATD0DR14_BIT13_MASK             8192U
#define ATD0DR14_BIT14_MASK             16384U
#define ATD0DR14_BIT15_MASK             32768U


/*** ATD0DR15 - ATD 0 Conversion Result Register 15; 0x000002EE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATD0DR15H - ATD 0 Conversion Result Register 15 High; 0x000002EE ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATD0DR15HSTR;
    #define ATD0DR15H                   _ATD0DR15.Overlap_STR.ATD0DR15HSTR.Byte
    #define ATD0DR15H_BIT8              _ATD0DR15.Overlap_STR.ATD0DR15HSTR.Bits.BIT8
    #define ATD0DR15H_BIT9              _ATD0DR15.Overlap_STR.ATD0DR15HSTR.Bits.BIT9
    #define ATD0DR15H_BIT10             _ATD0DR15.Overlap_STR.ATD0DR15HSTR.Bits.BIT10
    #define ATD0DR15H_BIT11             _ATD0DR15.Overlap_STR.ATD0DR15HSTR.Bits.BIT11
    #define ATD0DR15H_BIT12             _ATD0DR15.Overlap_STR.ATD0DR15HSTR.Bits.BIT12
    #define ATD0DR15H_BIT13             _ATD0DR15.Overlap_STR.ATD0DR15HSTR.Bits.BIT13
    #define ATD0DR15H_BIT14             _ATD0DR15.Overlap_STR.ATD0DR15HSTR.Bits.BIT14
    #define ATD0DR15H_BIT15             _ATD0DR15.Overlap_STR.ATD0DR15HSTR.Bits.BIT15
    
    #define ATD0DR15H_BIT8_MASK         1U
    #define ATD0DR15H_BIT9_MASK         2U
    #define ATD0DR15H_BIT10_MASK        4U
    #define ATD0DR15H_BIT11_MASK        8U
    #define ATD0DR15H_BIT12_MASK        16U
    #define ATD0DR15H_BIT13_MASK        32U
    #define ATD0DR15H_BIT14_MASK        64U
    #define ATD0DR15H_BIT15_MASK        128U
    

    /*** ATD0DR15L - ATD 0 Conversion Result Register 15 Low; 0x000002EF ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATD0DR15LSTR;
    #define ATD0DR15L                   _ATD0DR15.Overlap_STR.ATD0DR15LSTR.Byte
    #define ATD0DR15L_BIT0              _ATD0DR15.Overlap_STR.ATD0DR15LSTR.Bits.BIT0
    #define ATD0DR15L_BIT1              _ATD0DR15.Overlap_STR.ATD0DR15LSTR.Bits.BIT1
    #define ATD0DR15L_BIT2              _ATD0DR15.Overlap_STR.ATD0DR15LSTR.Bits.BIT2
    #define ATD0DR15L_BIT3              _ATD0DR15.Overlap_STR.ATD0DR15LSTR.Bits.BIT3
    #define ATD0DR15L_BIT4              _ATD0DR15.Overlap_STR.ATD0DR15LSTR.Bits.BIT4
    #define ATD0DR15L_BIT5              _ATD0DR15.Overlap_STR.ATD0DR15LSTR.Bits.BIT5
    #define ATD0DR15L_BIT6              _ATD0DR15.Overlap_STR.ATD0DR15LSTR.Bits.BIT6
    #define ATD0DR15L_BIT7              _ATD0DR15.Overlap_STR.ATD0DR15LSTR.Bits.BIT7
    
    #define ATD0DR15L_BIT0_MASK         1U
    #define ATD0DR15L_BIT1_MASK         2U
    #define ATD0DR15L_BIT2_MASK         4U
    #define ATD0DR15L_BIT3_MASK         8U
    #define ATD0DR15L_BIT4_MASK         16U
    #define ATD0DR15L_BIT5_MASK         32U
    #define ATD0DR15L_BIT6_MASK         64U
    #define ATD0DR15L_BIT7_MASK         128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATD0DR15STR;
extern volatile ATD0DR15STR _ATD0DR15 @(REG_BASE + 0x000002EEUL);
#define ATD0DR15                        _ATD0DR15.Word
#define ATD0DR15_BIT0                   _ATD0DR15.Bits.BIT0
#define ATD0DR15_BIT1                   _ATD0DR15.Bits.BIT1
#define ATD0DR15_BIT2                   _ATD0DR15.Bits.BIT2
#define ATD0DR15_BIT3                   _ATD0DR15.Bits.BIT3
#define ATD0DR15_BIT4                   _ATD0DR15.Bits.BIT4
#define ATD0DR15_BIT5                   _ATD0DR15.Bits.BIT5
#define ATD0DR15_BIT6                   _ATD0DR15.Bits.BIT6
#define ATD0DR15_BIT7                   _ATD0DR15.Bits.BIT7
#define ATD0DR15_BIT8                   _ATD0DR15.Bits.BIT8
#define ATD0DR15_BIT9                   _ATD0DR15.Bits.BIT9
#define ATD0DR15_BIT10                  _ATD0DR15.Bits.BIT10
#define ATD0DR15_BIT11                  _ATD0DR15.Bits.BIT11
#define ATD0DR15_BIT12                  _ATD0DR15.Bits.BIT12
#define ATD0DR15_BIT13                  _ATD0DR15.Bits.BIT13
#define ATD0DR15_BIT14                  _ATD0DR15.Bits.BIT14
#define ATD0DR15_BIT15                  _ATD0DR15.Bits.BIT15

#define ATD0DR15_BIT0_MASK              1U
#define ATD0DR15_BIT1_MASK              2U
#define ATD0DR15_BIT2_MASK              4U
#define ATD0DR15_BIT3_MASK              8U
#define ATD0DR15_BIT4_MASK              16U
#define ATD0DR15_BIT5_MASK              32U
#define ATD0DR15_BIT6_MASK              64U
#define ATD0DR15_BIT7_MASK              128U
#define ATD0DR15_BIT8_MASK              256U
#define ATD0DR15_BIT9_MASK              512U
#define ATD0DR15_BIT10_MASK             1024U
#define ATD0DR15_BIT11_MASK             2048U
#define ATD0DR15_BIT12_MASK             4096U
#define ATD0DR15_BIT13_MASK             8192U
#define ATD0DR15_BIT14_MASK             16384U
#define ATD0DR15_BIT15_MASK             32768U


/*** VREGHTCL - HT Control Register; 0x000002F0 ***/
typedef union {
  byte Byte;
  struct {
    byte HTIF        :1;                                       /* High Temperature Interrupt Flag */
    byte HTIE        :1;                                       /* High Temperature Interrupt Enable Bit */
    byte HTDS        :1;                                       /* High Temperature Detect Status Bi */
    byte HTEN        :1;                                       /* High Temperature Enable Bit */
    byte VAE         :1;                                       /* Voltage Access Enable Bit */
    byte VSEL        :1;                                       /* Voltage Access Select Bit */
    byte             :1; 
    byte             :1; 
  } Bits;
} VREGHTCLSTR;
extern volatile VREGHTCLSTR _VREGHTCL @(REG_BASE + 0x000002F0UL);
#define VREGHTCL                        _VREGHTCL.Byte
#define VREGHTCL_HTIF                   _VREGHTCL.Bits.HTIF
#define VREGHTCL_HTIE                   _VREGHTCL.Bits.HTIE
#define VREGHTCL_HTDS                   _VREGHTCL.Bits.HTDS
#define VREGHTCL_HTEN                   _VREGHTCL.Bits.HTEN
#define VREGHTCL_VAE                    _VREGHTCL.Bits.VAE
#define VREGHTCL_VSEL                   _VREGHTCL.Bits.VSEL

#define VREGHTCL_HTIF_MASK              1U
#define VREGHTCL_HTIE_MASK              2U
#define VREGHTCL_HTDS_MASK              4U
#define VREGHTCL_HTEN_MASK              8U
#define VREGHTCL_VAE_MASK               16U
#define VREGHTCL_VSEL_MASK              32U


/*** VREGCTRL - Control Register; 0x000002F1 ***/
typedef union {
  byte Byte;
  struct {
    byte LVIF        :1;                                       /* Low-Voltage Interrupt Flag */
    byte LVIE        :1;                                       /* Low-Voltage Interrupt Enable Bit */
    byte LVDS        :1;                                       /* Low-Voltage Detect Status Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} VREGCTRLSTR;
extern volatile VREGCTRLSTR _VREGCTRL @(REG_BASE + 0x000002F1UL);
#define VREGCTRL                        _VREGCTRL.Byte
#define VREGCTRL_LVIF                   _VREGCTRL.Bits.LVIF
#define VREGCTRL_LVIE                   _VREGCTRL.Bits.LVIE
#define VREGCTRL_LVDS                   _VREGCTRL.Bits.LVDS

#define VREGCTRL_LVIF_MASK              1U
#define VREGCTRL_LVIE_MASK              2U
#define VREGCTRL_LVDS_MASK              4U


/*** VREGAPICL - Autonomous Periodical Interrupt Control Register; 0x000002F2 ***/
typedef union {
  byte Byte;
  struct {
    byte APIF        :1;                                       /* Autonomous Periodical Interrupt Flag */
    byte APIE        :1;                                       /* Autonomous Periodical Interrupt Enable Bit */
    byte APIFE       :1;                                       /* Autonomous Periodical Interrupt Feature Enable Bit */
    byte APIEA       :1;                                       /* Autonomous Periodical Interrupt External Access Enable Bit */
    byte APIES       :1;                                       /* Autonomous Periodical Interrupt External Select Bit */
    byte             :1; 
    byte             :1; 
    byte APICLK      :1;                                       /* Autonomous Periodical Interrupt Clock Select Bit */
  } Bits;
} VREGAPICLSTR;
extern volatile VREGAPICLSTR _VREGAPICL @(REG_BASE + 0x000002F2UL);
#define VREGAPICL                       _VREGAPICL.Byte
#define VREGAPICL_APIF                  _VREGAPICL.Bits.APIF
#define VREGAPICL_APIE                  _VREGAPICL.Bits.APIE
#define VREGAPICL_APIFE                 _VREGAPICL.Bits.APIFE
#define VREGAPICL_APIEA                 _VREGAPICL.Bits.APIEA
#define VREGAPICL_APIES                 _VREGAPICL.Bits.APIES
#define VREGAPICL_APICLK                _VREGAPICL.Bits.APICLK

#define VREGAPICL_APIF_MASK             1U
#define VREGAPICL_APIE_MASK             2U
#define VREGAPICL_APIFE_MASK            4U
#define VREGAPICL_APIEA_MASK            8U
#define VREGAPICL_APIES_MASK            16U
#define VREGAPICL_APICLK_MASK           128U


/*** VREGAPITR - Autonomous Periodical Interrupt Trimming Register; 0x000002F3 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte APITR0      :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 0 */
    byte APITR1      :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 1 */
    byte APITR2      :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 2 */
    byte APITR3      :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 3 */
    byte APITR4      :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 4 */
    byte APITR5      :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 5 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpAPITR :6;
  } MergedBits;
} VREGAPITRSTR;
extern volatile VREGAPITRSTR _VREGAPITR @(REG_BASE + 0x000002F3UL);
#define VREGAPITR                       _VREGAPITR.Byte
#define VREGAPITR_APITR0                _VREGAPITR.Bits.APITR0
#define VREGAPITR_APITR1                _VREGAPITR.Bits.APITR1
#define VREGAPITR_APITR2                _VREGAPITR.Bits.APITR2
#define VREGAPITR_APITR3                _VREGAPITR.Bits.APITR3
#define VREGAPITR_APITR4                _VREGAPITR.Bits.APITR4
#define VREGAPITR_APITR5                _VREGAPITR.Bits.APITR5
#define VREGAPITR_APITR                 _VREGAPITR.MergedBits.grpAPITR

#define VREGAPITR_APITR0_MASK           4U
#define VREGAPITR_APITR1_MASK           8U
#define VREGAPITR_APITR2_MASK           16U
#define VREGAPITR_APITR3_MASK           32U
#define VREGAPITR_APITR4_MASK           64U
#define VREGAPITR_APITR5_MASK           128U
#define VREGAPITR_APITR_MASK            252U
#define VREGAPITR_APITR_BITNUM          2U


/*** VREGAPIR - Autonomous Periodical Interrupt Rate Register; 0x000002F4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** VREGAPIRH - Autonomous Periodical Interrupt Rate Register High; 0x000002F4 ***/
    union {
      byte Byte;
      struct {
        byte APIR8       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 8 */
        byte APIR9       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 9 */
        byte APIR10      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 10 */
        byte APIR11      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 11 */
        byte APIR12      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 12 */
        byte APIR13      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 13 */
        byte APIR14      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 14 */
        byte APIR15      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 15 */
      } Bits;
    } VREGAPIRHSTR;
    #define VREGAPIRH                   _VREGAPIR.Overlap_STR.VREGAPIRHSTR.Byte
    #define VREGAPIRH_APIR8             _VREGAPIR.Overlap_STR.VREGAPIRHSTR.Bits.APIR8
    #define VREGAPIRH_APIR9             _VREGAPIR.Overlap_STR.VREGAPIRHSTR.Bits.APIR9
    #define VREGAPIRH_APIR10            _VREGAPIR.Overlap_STR.VREGAPIRHSTR.Bits.APIR10
    #define VREGAPIRH_APIR11            _VREGAPIR.Overlap_STR.VREGAPIRHSTR.Bits.APIR11
    #define VREGAPIRH_APIR12            _VREGAPIR.Overlap_STR.VREGAPIRHSTR.Bits.APIR12
    #define VREGAPIRH_APIR13            _VREGAPIR.Overlap_STR.VREGAPIRHSTR.Bits.APIR13
    #define VREGAPIRH_APIR14            _VREGAPIR.Overlap_STR.VREGAPIRHSTR.Bits.APIR14
    #define VREGAPIRH_APIR15            _VREGAPIR.Overlap_STR.VREGAPIRHSTR.Bits.APIR15
    
    #define VREGAPIRH_APIR8_MASK        1U
    #define VREGAPIRH_APIR9_MASK        2U
    #define VREGAPIRH_APIR10_MASK       4U
    #define VREGAPIRH_APIR11_MASK       8U
    #define VREGAPIRH_APIR12_MASK       16U
    #define VREGAPIRH_APIR13_MASK       32U
    #define VREGAPIRH_APIR14_MASK       64U
    #define VREGAPIRH_APIR15_MASK       128U
    

    /*** VREGAPIRL - Autonomous Periodical Interrupt Rate Register Low; 0x000002F5 ***/
    union {
      byte Byte;
      struct {
        byte APIR0       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 0 */
        byte APIR1       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 1 */
        byte APIR2       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 2 */
        byte APIR3       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 3 */
        byte APIR4       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 4 */
        byte APIR5       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 5 */
        byte APIR6       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 6 */
        byte APIR7       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 7 */
      } Bits;
    } VREGAPIRLSTR;
    #define VREGAPIRL                   _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Byte
    #define VREGAPIRL_APIR0             _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Bits.APIR0
    #define VREGAPIRL_APIR1             _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Bits.APIR1
    #define VREGAPIRL_APIR2             _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Bits.APIR2
    #define VREGAPIRL_APIR3             _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Bits.APIR3
    #define VREGAPIRL_APIR4             _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Bits.APIR4
    #define VREGAPIRL_APIR5             _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Bits.APIR5
    #define VREGAPIRL_APIR6             _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Bits.APIR6
    #define VREGAPIRL_APIR7             _VREGAPIR.Overlap_STR.VREGAPIRLSTR.Bits.APIR7
    
    #define VREGAPIRL_APIR0_MASK        1U
    #define VREGAPIRL_APIR1_MASK        2U
    #define VREGAPIRL_APIR2_MASK        4U
    #define VREGAPIRL_APIR3_MASK        8U
    #define VREGAPIRL_APIR4_MASK        16U
    #define VREGAPIRL_APIR5_MASK        32U
    #define VREGAPIRL_APIR6_MASK        64U
    #define VREGAPIRL_APIR7_MASK        128U
    
  } Overlap_STR;

  struct {
    word APIR0       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 0 */
    word APIR1       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 1 */
    word APIR2       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 2 */
    word APIR3       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 3 */
    word APIR4       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 4 */
    word APIR5       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 5 */
    word APIR6       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 6 */
    word APIR7       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 7 */
    word APIR8       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 8 */
    word APIR9       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 9 */
    word APIR10      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 10 */
    word APIR11      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 11 */
    word APIR12      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 12 */
    word APIR13      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 13 */
    word APIR14      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 14 */
    word APIR15      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 15 */
  } Bits;
} VREGAPIRSTR;
extern volatile VREGAPIRSTR _VREGAPIR @(REG_BASE + 0x000002F4UL);
#define VREGAPIR                        _VREGAPIR.Word
#define VREGAPIR_APIR0                  _VREGAPIR.Bits.APIR0
#define VREGAPIR_APIR1                  _VREGAPIR.Bits.APIR1
#define VREGAPIR_APIR2                  _VREGAPIR.Bits.APIR2
#define VREGAPIR_APIR3                  _VREGAPIR.Bits.APIR3
#define VREGAPIR_APIR4                  _VREGAPIR.Bits.APIR4
#define VREGAPIR_APIR5                  _VREGAPIR.Bits.APIR5
#define VREGAPIR_APIR6                  _VREGAPIR.Bits.APIR6
#define VREGAPIR_APIR7                  _VREGAPIR.Bits.APIR7
#define VREGAPIR_APIR8                  _VREGAPIR.Bits.APIR8
#define VREGAPIR_APIR9                  _VREGAPIR.Bits.APIR9
#define VREGAPIR_APIR10                 _VREGAPIR.Bits.APIR10
#define VREGAPIR_APIR11                 _VREGAPIR.Bits.APIR11
#define VREGAPIR_APIR12                 _VREGAPIR.Bits.APIR12
#define VREGAPIR_APIR13                 _VREGAPIR.Bits.APIR13
#define VREGAPIR_APIR14                 _VREGAPIR.Bits.APIR14
#define VREGAPIR_APIR15                 _VREGAPIR.Bits.APIR15

#define VREGAPIR_APIR0_MASK             1U
#define VREGAPIR_APIR1_MASK             2U
#define VREGAPIR_APIR2_MASK             4U
#define VREGAPIR_APIR3_MASK             8U
#define VREGAPIR_APIR4_MASK             16U
#define VREGAPIR_APIR5_MASK             32U
#define VREGAPIR_APIR6_MASK             64U
#define VREGAPIR_APIR7_MASK             128U
#define VREGAPIR_APIR8_MASK             256U
#define VREGAPIR_APIR9_MASK             512U
#define VREGAPIR_APIR10_MASK            1024U
#define VREGAPIR_APIR11_MASK            2048U
#define VREGAPIR_APIR12_MASK            4096U
#define VREGAPIR_APIR13_MASK            8192U
#define VREGAPIR_APIR14_MASK            16384U
#define VREGAPIR_APIR15_MASK            32768U


/*** VREGHTTR - HTTrimming Register; 0x000002F7 ***/
typedef union {
  byte Byte;
  struct {
    byte HTTR        :4;                                       /* High Temperature Trimming Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte HTOEN       :1;                                       /* High Temperature Offeset Enable Bit */
  } Bits;
} VREGHTTRSTR;
extern volatile VREGHTTRSTR _VREGHTTR @(REG_BASE + 0x000002F7UL);
#define VREGHTTR                        _VREGHTTR.Byte
#define VREGHTTR_HTTR                   _VREGHTTR.Bits.HTTR
#define VREGHTTR_HTOEN                  _VREGHTTR.Bits.HTOEN

#define VREGHTTR_HTTR_MASK              15U
#define VREGHTTR_HTTR_BITNUM            0U
#define VREGHTTR_HTOEN_MASK             128U


/*** PWME - PWM Enable Register; 0x00000300 ***/
typedef union {
  byte Byte;
  struct {
    byte PWME0       :1;                                       /* Pulse Width Channel 0 Enable */
    byte PWME1       :1;                                       /* Pulse Width Channel 1 Enable */
    byte PWME2       :1;                                       /* Pulse Width Channel 2 Enable */
    byte PWME3       :1;                                       /* Pulse Width Channel 3 Enable */
    byte PWME4       :1;                                       /* Pulse Width Channel 4 Enable */
    byte PWME5       :1;                                       /* Pulse Width Channel 5 Enable */
    byte PWME6       :1;                                       /* Pulse Width Channel 6 Enable */
    byte PWME7       :1;                                       /* Pulse Width Channel 7 Enable */
  } Bits;
} PWMESTR;
extern volatile PWMESTR _PWME @(REG_BASE + 0x00000300UL);
#define PWME                            _PWME.Byte
#define PWME_PWME0                      _PWME.Bits.PWME0
#define PWME_PWME1                      _PWME.Bits.PWME1
#define PWME_PWME2                      _PWME.Bits.PWME2
#define PWME_PWME3                      _PWME.Bits.PWME3
#define PWME_PWME4                      _PWME.Bits.PWME4
#define PWME_PWME5                      _PWME.Bits.PWME5
#define PWME_PWME6                      _PWME.Bits.PWME6
#define PWME_PWME7                      _PWME.Bits.PWME7

#define PWME_PWME0_MASK                 1U
#define PWME_PWME1_MASK                 2U
#define PWME_PWME2_MASK                 4U
#define PWME_PWME3_MASK                 8U
#define PWME_PWME4_MASK                 16U
#define PWME_PWME5_MASK                 32U
#define PWME_PWME6_MASK                 64U
#define PWME_PWME7_MASK                 128U


/*** PWMPOL - PWM Polarity Register; 0x00000301 ***/
typedef union {
  byte Byte;
  struct {
    byte PPOL0       :1;                                       /* Pulse Width Channel 0 Polarity */
    byte PPOL1       :1;                                       /* Pulse Width Channel 1 Polarity */
    byte PPOL2       :1;                                       /* Pulse Width Channel 2 Polarity */
    byte PPOL3       :1;                                       /* Pulse Width Channel 3 Polarity */
    byte PPOL4       :1;                                       /* Pulse Width Channel 4 Polarity */
    byte PPOL5       :1;                                       /* Pulse Width Channel 5 Polarity */
    byte PPOL6       :1;                                       /* Pulse Width Channel 6 Polarity */
    byte PPOL7       :1;                                       /* Pulse Width Channel 7 Polarity */
  } Bits;
} PWMPOLSTR;
extern volatile PWMPOLSTR _PWMPOL @(REG_BASE + 0x00000301UL);
#define PWMPOL                          _PWMPOL.Byte
#define PWMPOL_PPOL0                    _PWMPOL.Bits.PPOL0
#define PWMPOL_PPOL1                    _PWMPOL.Bits.PPOL1
#define PWMPOL_PPOL2                    _PWMPOL.Bits.PPOL2
#define PWMPOL_PPOL3                    _PWMPOL.Bits.PPOL3
#define PWMPOL_PPOL4                    _PWMPOL.Bits.PPOL4
#define PWMPOL_PPOL5                    _PWMPOL.Bits.PPOL5
#define PWMPOL_PPOL6                    _PWMPOL.Bits.PPOL6
#define PWMPOL_PPOL7                    _PWMPOL.Bits.PPOL7

#define PWMPOL_PPOL0_MASK               1U
#define PWMPOL_PPOL1_MASK               2U
#define PWMPOL_PPOL2_MASK               4U
#define PWMPOL_PPOL3_MASK               8U
#define PWMPOL_PPOL4_MASK               16U
#define PWMPOL_PPOL5_MASK               32U
#define PWMPOL_PPOL6_MASK               64U
#define PWMPOL_PPOL7_MASK               128U


/*** PWMCLK - PWM Clock Select Register; 0x00000302 ***/
typedef union {
  byte Byte;
  struct {
    byte PCLK0       :1;                                       /* Pulse Width Channel 0 Clock Select */
    byte PCLK1       :1;                                       /* Pulse Width Channel 1 Clock Select */
    byte PCLK2       :1;                                       /* Pulse Width Channel 2 Clock Select */
    byte PCLK3       :1;                                       /* Pulse Width Channel 3 Clock Select */
    byte PCLK4       :1;                                       /* Pulse Width Channel 4 Clock Select */
    byte PCLK5       :1;                                       /* Pulse Width Channel 5 Clock Select */
    byte PCLK6       :1;                                       /* Pulse Width Channel 6 Clock Select */
    byte PCLK7       :1;                                       /* Pulse Width Channel 7 Clock Select */
  } Bits;
} PWMCLKSTR;
extern volatile PWMCLKSTR _PWMCLK @(REG_BASE + 0x00000302UL);
#define PWMCLK                          _PWMCLK.Byte
#define PWMCLK_PCLK0                    _PWMCLK.Bits.PCLK0
#define PWMCLK_PCLK1                    _PWMCLK.Bits.PCLK1
#define PWMCLK_PCLK2                    _PWMCLK.Bits.PCLK2
#define PWMCLK_PCLK3                    _PWMCLK.Bits.PCLK3
#define PWMCLK_PCLK4                    _PWMCLK.Bits.PCLK4
#define PWMCLK_PCLK5                    _PWMCLK.Bits.PCLK5
#define PWMCLK_PCLK6                    _PWMCLK.Bits.PCLK6
#define PWMCLK_PCLK7                    _PWMCLK.Bits.PCLK7

#define PWMCLK_PCLK0_MASK               1U
#define PWMCLK_PCLK1_MASK               2U
#define PWMCLK_PCLK2_MASK               4U
#define PWMCLK_PCLK3_MASK               8U
#define PWMCLK_PCLK4_MASK               16U
#define PWMCLK_PCLK5_MASK               32U
#define PWMCLK_PCLK6_MASK               64U
#define PWMCLK_PCLK7_MASK               128U


/*** PWMPRCLK - PWM Prescale Clock Select Register; 0x00000303 ***/
typedef union {
  byte Byte;
  struct {
    byte PCKA0       :1;                                       /* Prescaler Select for Clock A 0 */
    byte PCKA1       :1;                                       /* Prescaler Select for Clock A 1 */
    byte PCKA2       :1;                                       /* Prescaler Select for Clock A 2 */
    byte             :1; 
    byte PCKB0       :1;                                       /* Prescaler Select for Clock B 0 */
    byte PCKB1       :1;                                       /* Prescaler Select for Clock B 1 */
    byte PCKB2       :1;                                       /* Prescaler Select for Clock B 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPCKA :3;
    byte         :1;
    byte grpPCKB :3;
    byte         :1;
  } MergedBits;
} PWMPRCLKSTR;
extern volatile PWMPRCLKSTR _PWMPRCLK @(REG_BASE + 0x00000303UL);
#define PWMPRCLK                        _PWMPRCLK.Byte
#define PWMPRCLK_PCKA0                  _PWMPRCLK.Bits.PCKA0
#define PWMPRCLK_PCKA1                  _PWMPRCLK.Bits.PCKA1
#define PWMPRCLK_PCKA2                  _PWMPRCLK.Bits.PCKA2
#define PWMPRCLK_PCKB0                  _PWMPRCLK.Bits.PCKB0
#define PWMPRCLK_PCKB1                  _PWMPRCLK.Bits.PCKB1
#define PWMPRCLK_PCKB2                  _PWMPRCLK.Bits.PCKB2
#define PWMPRCLK_PCKA                   _PWMPRCLK.MergedBits.grpPCKA
#define PWMPRCLK_PCKB                   _PWMPRCLK.MergedBits.grpPCKB

#define PWMPRCLK_PCKA0_MASK             1U
#define PWMPRCLK_PCKA1_MASK             2U
#define PWMPRCLK_PCKA2_MASK             4U
#define PWMPRCLK_PCKB0_MASK             16U
#define PWMPRCLK_PCKB1_MASK             32U
#define PWMPRCLK_PCKB2_MASK             64U
#define PWMPRCLK_PCKA_MASK              7U
#define PWMPRCLK_PCKA_BITNUM            0U
#define PWMPRCLK_PCKB_MASK              112U
#define PWMPRCLK_PCKB_BITNUM            4U


/*** PWMCAE - PWM Center Align Enable Register; 0x00000304 ***/
typedef union {
  byte Byte;
  struct {
    byte CAE0        :1;                                       /* Center Aligned Output Mode on channel 0 */
    byte CAE1        :1;                                       /* Center Aligned Output Mode on channel 1 */
    byte CAE2        :1;                                       /* Center Aligned Output Mode on channel 2 */
    byte CAE3        :1;                                       /* Center Aligned Output Mode on channel 3 */
    byte CAE4        :1;                                       /* Center Aligned Output Mode on channel 4 */
    byte CAE5        :1;                                       /* Center Aligned Output Mode on channel 5 */
    byte CAE6        :1;                                       /* Center Aligned Output Mode on channel 6 */
    byte CAE7        :1;                                       /* Center Aligned Output Mode on channel 7 */
  } Bits;
} PWMCAESTR;
extern volatile PWMCAESTR _PWMCAE @(REG_BASE + 0x00000304UL);
#define PWMCAE                          _PWMCAE.Byte
#define PWMCAE_CAE0                     _PWMCAE.Bits.CAE0
#define PWMCAE_CAE1                     _PWMCAE.Bits.CAE1
#define PWMCAE_CAE2                     _PWMCAE.Bits.CAE2
#define PWMCAE_CAE3                     _PWMCAE.Bits.CAE3
#define PWMCAE_CAE4                     _PWMCAE.Bits.CAE4
#define PWMCAE_CAE5                     _PWMCAE.Bits.CAE5
#define PWMCAE_CAE6                     _PWMCAE.Bits.CAE6
#define PWMCAE_CAE7                     _PWMCAE.Bits.CAE7

#define PWMCAE_CAE0_MASK                1U
#define PWMCAE_CAE1_MASK                2U
#define PWMCAE_CAE2_MASK                4U
#define PWMCAE_CAE3_MASK                8U
#define PWMCAE_CAE4_MASK                16U
#define PWMCAE_CAE5_MASK                32U
#define PWMCAE_CAE6_MASK                64U
#define PWMCAE_CAE7_MASK                128U


/*** PWMCTL - PWM Control Register; 0x00000305 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte PFRZ        :1;                                       /* PWM Counters Stop in Freeze Mode */
    byte PSWAI       :1;                                       /* PWM Stops in Wait Mode */
    byte CON01       :1;                                       /* Concatenate channels 0 and 1 */
    byte CON23       :1;                                       /* Concatenate channels 2 and 3 */
    byte CON45       :1;                                       /* Concatenate channels 4 and 5 */
    byte CON67       :1;                                       /* Concatenate channels 6 and 7 */
  } Bits;
} PWMCTLSTR;
extern volatile PWMCTLSTR _PWMCTL @(REG_BASE + 0x00000305UL);
#define PWMCTL                          _PWMCTL.Byte
#define PWMCTL_PFRZ                     _PWMCTL.Bits.PFRZ
#define PWMCTL_PSWAI                    _PWMCTL.Bits.PSWAI
#define PWMCTL_CON01                    _PWMCTL.Bits.CON01
#define PWMCTL_CON23                    _PWMCTL.Bits.CON23
#define PWMCTL_CON45                    _PWMCTL.Bits.CON45
#define PWMCTL_CON67                    _PWMCTL.Bits.CON67

#define PWMCTL_PFRZ_MASK                4U
#define PWMCTL_PSWAI_MASK               8U
#define PWMCTL_CON01_MASK               16U
#define PWMCTL_CON23_MASK               32U
#define PWMCTL_CON45_MASK               64U
#define PWMCTL_CON67_MASK               128U


/*** PWMSCLA - PWM Scale A Register; 0x00000308 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* PWM Scale A Bit 0 */
    byte BIT1        :1;                                       /* PWM Scale A Bit 1 */
    byte BIT2        :1;                                       /* PWM Scale A Bit 2 */
    byte BIT3        :1;                                       /* PWM Scale A Bit 3 */
    byte BIT4        :1;                                       /* PWM Scale A Bit 4 */
    byte BIT5        :1;                                       /* PWM Scale A Bit 5 */
    byte BIT6        :1;                                       /* PWM Scale A Bit 6 */
    byte BIT7        :1;                                       /* PWM Scale A Bit 7 */
  } Bits;
} PWMSCLASTR;
extern volatile PWMSCLASTR _PWMSCLA @(REG_BASE + 0x00000308UL);
#define PWMSCLA                         _PWMSCLA.Byte
#define PWMSCLA_BIT0                    _PWMSCLA.Bits.BIT0
#define PWMSCLA_BIT1                    _PWMSCLA.Bits.BIT1
#define PWMSCLA_BIT2                    _PWMSCLA.Bits.BIT2
#define PWMSCLA_BIT3                    _PWMSCLA.Bits.BIT3
#define PWMSCLA_BIT4                    _PWMSCLA.Bits.BIT4
#define PWMSCLA_BIT5                    _PWMSCLA.Bits.BIT5
#define PWMSCLA_BIT6                    _PWMSCLA.Bits.BIT6
#define PWMSCLA_BIT7                    _PWMSCLA.Bits.BIT7

#define PWMSCLA_BIT0_MASK               1U
#define PWMSCLA_BIT1_MASK               2U
#define PWMSCLA_BIT2_MASK               4U
#define PWMSCLA_BIT3_MASK               8U
#define PWMSCLA_BIT4_MASK               16U
#define PWMSCLA_BIT5_MASK               32U
#define PWMSCLA_BIT6_MASK               64U
#define PWMSCLA_BIT7_MASK               128U


/*** PWMSCLB - PWM Scale B Register; 0x00000309 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* PWM Scale B Bit 0 */
    byte BIT1        :1;                                       /* PWM Scale B Bit 1 */
    byte BIT2        :1;                                       /* PWM Scale B Bit 2 */
    byte BIT3        :1;                                       /* PWM Scale B Bit 3 */
    byte BIT4        :1;                                       /* PWM Scale B Bit 4 */
    byte BIT5        :1;                                       /* PWM Scale B Bit 5 */
    byte BIT6        :1;                                       /* PWM Scale B Bit 6 */
    byte BIT7        :1;                                       /* PWM Scale B Bit 7 */
  } Bits;
} PWMSCLBSTR;
extern volatile PWMSCLBSTR _PWMSCLB @(REG_BASE + 0x00000309UL);
#define PWMSCLB                         _PWMSCLB.Byte
#define PWMSCLB_BIT0                    _PWMSCLB.Bits.BIT0
#define PWMSCLB_BIT1                    _PWMSCLB.Bits.BIT1
#define PWMSCLB_BIT2                    _PWMSCLB.Bits.BIT2
#define PWMSCLB_BIT3                    _PWMSCLB.Bits.BIT3
#define PWMSCLB_BIT4                    _PWMSCLB.Bits.BIT4
#define PWMSCLB_BIT5                    _PWMSCLB.Bits.BIT5
#define PWMSCLB_BIT6                    _PWMSCLB.Bits.BIT6
#define PWMSCLB_BIT7                    _PWMSCLB.Bits.BIT7

#define PWMSCLB_BIT0_MASK               1U
#define PWMSCLB_BIT1_MASK               2U
#define PWMSCLB_BIT2_MASK               4U
#define PWMSCLB_BIT3_MASK               8U
#define PWMSCLB_BIT4_MASK               16U
#define PWMSCLB_BIT5_MASK               32U
#define PWMSCLB_BIT6_MASK               64U
#define PWMSCLB_BIT7_MASK               128U


/*** PWMCNT01 - PWM Channel Counter 01 Register; 0x0000030C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMCNT0 - PWM Channel Counter 0 Register; 0x0000030C ***/
    union {
      byte Byte;
    } PWMCNT0STR;
    #define PWMCNT0                     _PWMCNT01.Overlap_STR.PWMCNT0STR.Byte
    /* PWMCNT_ARR: Access 8 PWMCNTx registers in an array */
    #define PWMCNT_ARR                  ((volatile byte *) &PWMCNT0)
    

    /*** PWMCNT1 - PWM Channel Counter 1 Register; 0x0000030D ***/
    union {
      byte Byte;
    } PWMCNT1STR;
    #define PWMCNT1                     _PWMCNT01.Overlap_STR.PWMCNT1STR.Byte
    
  } Overlap_STR;

} PWMCNT01STR;
extern volatile PWMCNT01STR _PWMCNT01 @(REG_BASE + 0x0000030CUL);
#define PWMCNT01                        _PWMCNT01.Word


/*** PWMCNT23 - PWM Channel Counter 23 Register; 0x0000030E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMCNT2 - PWM Channel Counter 2 Register; 0x0000030E ***/
    union {
      byte Byte;
    } PWMCNT2STR;
    #define PWMCNT2                     _PWMCNT23.Overlap_STR.PWMCNT2STR.Byte
    

    /*** PWMCNT3 - PWM Channel Counter 3 Register; 0x0000030F ***/
    union {
      byte Byte;
    } PWMCNT3STR;
    #define PWMCNT3                     _PWMCNT23.Overlap_STR.PWMCNT3STR.Byte
    
  } Overlap_STR;

} PWMCNT23STR;
extern volatile PWMCNT23STR _PWMCNT23 @(REG_BASE + 0x0000030EUL);
#define PWMCNT23                        _PWMCNT23.Word


/*** PWMCNT45 - PWM Channel Counter 45 Register; 0x00000310 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMCNT4 - PWM Channel Counter 4 Register; 0x00000310 ***/
    union {
      byte Byte;
    } PWMCNT4STR;
    #define PWMCNT4                     _PWMCNT45.Overlap_STR.PWMCNT4STR.Byte
    

    /*** PWMCNT5 - PWM Channel Counter 5 Register; 0x00000311 ***/
    union {
      byte Byte;
    } PWMCNT5STR;
    #define PWMCNT5                     _PWMCNT45.Overlap_STR.PWMCNT5STR.Byte
    
  } Overlap_STR;

} PWMCNT45STR;
extern volatile PWMCNT45STR _PWMCNT45 @(REG_BASE + 0x00000310UL);
#define PWMCNT45                        _PWMCNT45.Word


/*** PWMCNT67 - PWM Channel Counter 67 Register; 0x00000312 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMCNT6 - PWM Channel Counter 6 Register; 0x00000312 ***/
    union {
      byte Byte;
    } PWMCNT6STR;
    #define PWMCNT6                     _PWMCNT67.Overlap_STR.PWMCNT6STR.Byte
    

    /*** PWMCNT7 - PWM Channel Counter 7 Register; 0x00000313 ***/
    union {
      byte Byte;
    } PWMCNT7STR;
    #define PWMCNT7                     _PWMCNT67.Overlap_STR.PWMCNT7STR.Byte
    
  } Overlap_STR;

} PWMCNT67STR;
extern volatile PWMCNT67STR _PWMCNT67 @(REG_BASE + 0x00000312UL);
#define PWMCNT67                        _PWMCNT67.Word


/*** PWMPER01 - PWM Channel Period 01 Register; 0x00000314 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMPER0 - PWM Channel Period 0 Register; 0x00000314 ***/
    union {
      byte Byte;
    } PWMPER0STR;
    #define PWMPER0                     _PWMPER01.Overlap_STR.PWMPER0STR.Byte
    /* PWMPER_ARR: Access 8 PWMPERx registers in an array */
    #define PWMPER_ARR                  ((volatile byte *) &PWMPER0)
    

    /*** PWMPER1 - PWM Channel Period 1 Register; 0x00000315 ***/
    union {
      byte Byte;
    } PWMPER1STR;
    #define PWMPER1                     _PWMPER01.Overlap_STR.PWMPER1STR.Byte
    
  } Overlap_STR;

} PWMPER01STR;
extern volatile PWMPER01STR _PWMPER01 @(REG_BASE + 0x00000314UL);
#define PWMPER01                        _PWMPER01.Word


/*** PWMPER23 - PWM Channel Period 23 Register; 0x00000316 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMPER2 - PWM Channel Period 2 Register; 0x00000316 ***/
    union {
      byte Byte;
    } PWMPER2STR;
    #define PWMPER2                     _PWMPER23.Overlap_STR.PWMPER2STR.Byte
    

    /*** PWMPER3 - PWM Channel Period 3 Register; 0x00000317 ***/
    union {
      byte Byte;
    } PWMPER3STR;
    #define PWMPER3                     _PWMPER23.Overlap_STR.PWMPER3STR.Byte
    
  } Overlap_STR;

} PWMPER23STR;
extern volatile PWMPER23STR _PWMPER23 @(REG_BASE + 0x00000316UL);
#define PWMPER23                        _PWMPER23.Word


/*** PWMPER45 - PWM Channel Period 45 Register; 0x00000318 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMPER4 - PWM Channel Period 4 Register; 0x00000318 ***/
    union {
      byte Byte;
    } PWMPER4STR;
    #define PWMPER4                     _PWMPER45.Overlap_STR.PWMPER4STR.Byte
    

    /*** PWMPER5 - PWM Channel Period 5 Register; 0x00000319 ***/
    union {
      byte Byte;
    } PWMPER5STR;
    #define PWMPER5                     _PWMPER45.Overlap_STR.PWMPER5STR.Byte
    
  } Overlap_STR;

} PWMPER45STR;
extern volatile PWMPER45STR _PWMPER45 @(REG_BASE + 0x00000318UL);
#define PWMPER45                        _PWMPER45.Word


/*** PWMPER67 - PWM Channel Period 67 Register; 0x0000031A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMPER6 - PWM Channel Period 6 Register; 0x0000031A ***/
    union {
      byte Byte;
    } PWMPER6STR;
    #define PWMPER6                     _PWMPER67.Overlap_STR.PWMPER6STR.Byte
    

    /*** PWMPER7 - PWM Channel Period 7 Register; 0x0000031B ***/
    union {
      byte Byte;
    } PWMPER7STR;
    #define PWMPER7                     _PWMPER67.Overlap_STR.PWMPER7STR.Byte
    
  } Overlap_STR;

} PWMPER67STR;
extern volatile PWMPER67STR _PWMPER67 @(REG_BASE + 0x0000031AUL);
#define PWMPER67                        _PWMPER67.Word


/*** PWMDTY01 - PWM Channel Duty 01 Register; 0x0000031C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMDTY0 - PWM Channel Duty 0 Register; 0x0000031C ***/
    union {
      byte Byte;
    } PWMDTY0STR;
    #define PWMDTY0                     _PWMDTY01.Overlap_STR.PWMDTY0STR.Byte
    /* PWMDTY_ARR: Access 8 PWMDTYx registers in an array */
    #define PWMDTY_ARR                  ((volatile byte *) &PWMDTY0)
    

    /*** PWMDTY1 - PWM Channel Duty 1 Register; 0x0000031D ***/
    union {
      byte Byte;
    } PWMDTY1STR;
    #define PWMDTY1                     _PWMDTY01.Overlap_STR.PWMDTY1STR.Byte
    
  } Overlap_STR;

} PWMDTY01STR;
extern volatile PWMDTY01STR _PWMDTY01 @(REG_BASE + 0x0000031CUL);
#define PWMDTY01                        _PWMDTY01.Word


/*** PWMDTY23 - PWM Channel Duty 23 Register; 0x0000031E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMDTY2 - PWM Channel Duty 2 Register; 0x0000031E ***/
    union {
      byte Byte;
    } PWMDTY2STR;
    #define PWMDTY2                     _PWMDTY23.Overlap_STR.PWMDTY2STR.Byte
    

    /*** PWMDTY3 - PWM Channel Duty 3 Register; 0x0000031F ***/
    union {
      byte Byte;
    } PWMDTY3STR;
    #define PWMDTY3                     _PWMDTY23.Overlap_STR.PWMDTY3STR.Byte
    
  } Overlap_STR;

} PWMDTY23STR;
extern volatile PWMDTY23STR _PWMDTY23 @(REG_BASE + 0x0000031EUL);
#define PWMDTY23                        _PWMDTY23.Word


/*** PWMDTY45 - PWM Channel Duty 45 Register; 0x00000320 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMDTY4 - PWM Channel Duty 4 Register; 0x00000320 ***/
    union {
      byte Byte;
    } PWMDTY4STR;
    #define PWMDTY4                     _PWMDTY45.Overlap_STR.PWMDTY4STR.Byte
    

    /*** PWMDTY5 - PWM Channel Duty 5 Register; 0x00000321 ***/
    union {
      byte Byte;
    } PWMDTY5STR;
    #define PWMDTY5                     _PWMDTY45.Overlap_STR.PWMDTY5STR.Byte
    
  } Overlap_STR;

} PWMDTY45STR;
extern volatile PWMDTY45STR _PWMDTY45 @(REG_BASE + 0x00000320UL);
#define PWMDTY45                        _PWMDTY45.Word


/*** PWMDTY67 - PWM Channel Duty 67 Register; 0x00000322 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMDTY6 - PWM Channel Duty 6 Register; 0x00000322 ***/
    union {
      byte Byte;
    } PWMDTY6STR;
    #define PWMDTY6                     _PWMDTY67.Overlap_STR.PWMDTY6STR.Byte
    

    /*** PWMDTY7 - PWM Channel Duty 7 Register; 0x00000323 ***/
    union {
      byte Byte;
    } PWMDTY7STR;
    #define PWMDTY7                     _PWMDTY67.Overlap_STR.PWMDTY7STR.Byte
    
  } Overlap_STR;

} PWMDTY67STR;
extern volatile PWMDTY67STR _PWMDTY67 @(REG_BASE + 0x00000322UL);
#define PWMDTY67                        _PWMDTY67.Word


/*** PWMSDN - PWM Shutdown Register; 0x00000324 ***/
typedef union {
  byte Byte;
  struct {
    byte PWM7ENA     :1;                                       /* PWM emergency shutdown Enable */
    byte PWM7INL     :1;                                       /* PWM shutdown active input level for ch. 7 */
    byte PWM7IN      :1;                                       /* PWM channel 7 input status */
    byte             :1; 
    byte PWMLVL      :1;                                       /* PWM shutdown output Level */
    byte PWMRSTRT    :1;                                       /* PWM Restart */
    byte PWMIE       :1;                                       /* PWM Interrupt Enable */
    byte PWMIF       :1;                                       /* PWM Interrupt Flag */
  } Bits;
} PWMSDNSTR;
extern volatile PWMSDNSTR _PWMSDN @(REG_BASE + 0x00000324UL);
#define PWMSDN                          _PWMSDN.Byte
#define PWMSDN_PWM7ENA                  _PWMSDN.Bits.PWM7ENA
#define PWMSDN_PWM7INL                  _PWMSDN.Bits.PWM7INL
#define PWMSDN_PWM7IN                   _PWMSDN.Bits.PWM7IN
#define PWMSDN_PWMLVL                   _PWMSDN.Bits.PWMLVL
#define PWMSDN_PWMRSTRT                 _PWMSDN.Bits.PWMRSTRT
#define PWMSDN_PWMIE                    _PWMSDN.Bits.PWMIE
#define PWMSDN_PWMIF                    _PWMSDN.Bits.PWMIF

#define PWMSDN_PWM7ENA_MASK             1U
#define PWMSDN_PWM7INL_MASK             2U
#define PWMSDN_PWM7IN_MASK              4U
#define PWMSDN_PWMLVL_MASK              16U
#define PWMSDN_PWMRSTRT_MASK            32U
#define PWMSDN_PWMIE_MASK               64U
#define PWMSDN_PWMIF_MASK               128U


/*** PITCFLMT - PIT Control and Force Load Micro Timer Register; 0x00000340 ***/
typedef union {
  byte Byte;
  struct {
    byte PFLMT0      :1;                                       /* PIT Force Load Bits for Micro Timer 0 */
    byte PFLMT1      :1;                                       /* PIT Force Load Bits for Micro Timer 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PITFRZ      :1;                                       /* PIT Counter Freeze while in Freeze Mode Bit */
    byte PITSWAI     :1;                                       /* PIT Stop in Wait Mode Bit */
    byte PITE        :1;                                       /* PIT Module Enable Bit */
  } Bits;
  struct {
    byte grpPFLMT :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PITCFLMTSTR;
extern volatile PITCFLMTSTR _PITCFLMT @(REG_BASE + 0x00000340UL);
#define PITCFLMT                        _PITCFLMT.Byte
#define PITCFLMT_PFLMT0                 _PITCFLMT.Bits.PFLMT0
#define PITCFLMT_PFLMT1                 _PITCFLMT.Bits.PFLMT1
#define PITCFLMT_PITFRZ                 _PITCFLMT.Bits.PITFRZ
#define PITCFLMT_PITSWAI                _PITCFLMT.Bits.PITSWAI
#define PITCFLMT_PITE                   _PITCFLMT.Bits.PITE
#define PITCFLMT_PFLMT                  _PITCFLMT.MergedBits.grpPFLMT

#define PITCFLMT_PFLMT0_MASK            1U
#define PITCFLMT_PFLMT1_MASK            2U
#define PITCFLMT_PITFRZ_MASK            32U
#define PITCFLMT_PITSWAI_MASK           64U
#define PITCFLMT_PITE_MASK              128U
#define PITCFLMT_PFLMT_MASK             3U
#define PITCFLMT_PFLMT_BITNUM           0U


/*** PITFLT - PIT Force Load Timer Register; 0x00000341 ***/
typedef union {
  byte Byte;
  struct {
    byte PFLT0       :1;                                       /* PIT Force Load Bits for Timer 0 */
    byte PFLT1       :1;                                       /* PIT Force Load Bits for Timer 1 */
    byte PFLT2       :1;                                       /* PIT Force Load Bits for Timer 2 */
    byte PFLT3       :1;                                       /* PIT Force Load Bits for Timer 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPFLT :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PITFLTSTR;
extern volatile PITFLTSTR _PITFLT @(REG_BASE + 0x00000341UL);
#define PITFLT                          _PITFLT.Byte
#define PITFLT_PFLT0                    _PITFLT.Bits.PFLT0
#define PITFLT_PFLT1                    _PITFLT.Bits.PFLT1
#define PITFLT_PFLT2                    _PITFLT.Bits.PFLT2
#define PITFLT_PFLT3                    _PITFLT.Bits.PFLT3
#define PITFLT_PFLT                     _PITFLT.MergedBits.grpPFLT

#define PITFLT_PFLT0_MASK               1U
#define PITFLT_PFLT1_MASK               2U
#define PITFLT_PFLT2_MASK               4U
#define PITFLT_PFLT3_MASK               8U
#define PITFLT_PFLT_MASK                15U
#define PITFLT_PFLT_BITNUM              0U


/*** PITCE - PIT Channel Enable Register; 0x00000342 ***/
typedef union {
  byte Byte;
  struct {
    byte PCE0        :1;                                       /* PIT Enable Bits for Timer Channel 0 */
    byte PCE1        :1;                                       /* PIT Enable Bits for Timer Channel 1 */
    byte PCE2        :1;                                       /* PIT Enable Bits for Timer Channel 2 */
    byte PCE3        :1;                                       /* PIT Enable Bits for Timer Channel 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPCE  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PITCESTR;
extern volatile PITCESTR _PITCE @(REG_BASE + 0x00000342UL);
#define PITCE                           _PITCE.Byte
#define PITCE_PCE0                      _PITCE.Bits.PCE0
#define PITCE_PCE1                      _PITCE.Bits.PCE1
#define PITCE_PCE2                      _PITCE.Bits.PCE2
#define PITCE_PCE3                      _PITCE.Bits.PCE3
#define PITCE_PCE                       _PITCE.MergedBits.grpPCE

#define PITCE_PCE0_MASK                 1U
#define PITCE_PCE1_MASK                 2U
#define PITCE_PCE2_MASK                 4U
#define PITCE_PCE3_MASK                 8U
#define PITCE_PCE_MASK                  15U
#define PITCE_PCE_BITNUM                0U


/*** PITMUX - PIT Multiplex Register; 0x00000343 ***/
typedef union {
  byte Byte;
  struct {
    byte PMUX0       :1;                                       /* PIT Multiplex Bits for Timer Channel 0 */
    byte PMUX1       :1;                                       /* PIT Multiplex Bits for Timer Channel 1 */
    byte PMUX2       :1;                                       /* PIT Multiplex Bits for Timer Channel 2 */
    byte PMUX3       :1;                                       /* PIT Multiplex Bits for Timer Channel 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPMUX :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PITMUXSTR;
extern volatile PITMUXSTR _PITMUX @(REG_BASE + 0x00000343UL);
#define PITMUX                          _PITMUX.Byte
#define PITMUX_PMUX0                    _PITMUX.Bits.PMUX0
#define PITMUX_PMUX1                    _PITMUX.Bits.PMUX1
#define PITMUX_PMUX2                    _PITMUX.Bits.PMUX2
#define PITMUX_PMUX3                    _PITMUX.Bits.PMUX3
#define PITMUX_PMUX                     _PITMUX.MergedBits.grpPMUX

#define PITMUX_PMUX0_MASK               1U
#define PITMUX_PMUX1_MASK               2U
#define PITMUX_PMUX2_MASK               4U
#define PITMUX_PMUX3_MASK               8U
#define PITMUX_PMUX_MASK                15U
#define PITMUX_PMUX_BITNUM              0U


/*** PITINTE - PIT Interrupt Enable Register; 0x00000344 ***/
typedef union {
  byte Byte;
  struct {
    byte PINTE0      :1;                                       /* PIT Time-out Interrupt Enable Bits for Timer Channel 0 */
    byte PINTE1      :1;                                       /* PIT Time-out Interrupt Enable Bits for Timer Channel 1 */
    byte PINTE2      :1;                                       /* PIT Time-out Interrupt Enable Bits for Timer Channel 2 */
    byte PINTE3      :1;                                       /* PIT Time-out Interrupt Enable Bits for Timer Channel 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPINTE :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PITINTESTR;
extern volatile PITINTESTR _PITINTE @(REG_BASE + 0x00000344UL);
#define PITINTE                         _PITINTE.Byte
#define PITINTE_PINTE0                  _PITINTE.Bits.PINTE0
#define PITINTE_PINTE1                  _PITINTE.Bits.PINTE1
#define PITINTE_PINTE2                  _PITINTE.Bits.PINTE2
#define PITINTE_PINTE3                  _PITINTE.Bits.PINTE3
#define PITINTE_PINTE                   _PITINTE.MergedBits.grpPINTE

#define PITINTE_PINTE0_MASK             1U
#define PITINTE_PINTE1_MASK             2U
#define PITINTE_PINTE2_MASK             4U
#define PITINTE_PINTE3_MASK             8U
#define PITINTE_PINTE_MASK              15U
#define PITINTE_PINTE_BITNUM            0U


/*** PITTF - PIT Time-out Flag Register; 0x00000345 ***/
typedef union {
  byte Byte;
  struct {
    byte PTF0        :1;                                       /* PIT Time-out Flag Bits for Timer Channel 0 */
    byte PTF1        :1;                                       /* PIT Time-out Flag Bits for Timer Channel 1 */
    byte PTF2        :1;                                       /* PIT Time-out Flag Bits for Timer Channel 2 */
    byte PTF3        :1;                                       /* PIT Time-out Flag Bits for Timer Channel 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTF  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PITTFSTR;
extern volatile PITTFSTR _PITTF @(REG_BASE + 0x00000345UL);
#define PITTF                           _PITTF.Byte
#define PITTF_PTF0                      _PITTF.Bits.PTF0
#define PITTF_PTF1                      _PITTF.Bits.PTF1
#define PITTF_PTF2                      _PITTF.Bits.PTF2
#define PITTF_PTF3                      _PITTF.Bits.PTF3
#define PITTF_PTF                       _PITTF.MergedBits.grpPTF

#define PITTF_PTF0_MASK                 1U
#define PITTF_PTF1_MASK                 2U
#define PITTF_PTF2_MASK                 4U
#define PITTF_PTF3_MASK                 8U
#define PITTF_PTF_MASK                  15U
#define PITTF_PTF_BITNUM                0U


/*** PITMTLD0 - PIT Micro Timer Load Register 0; 0x00000346 ***/
typedef union {
  byte Byte;
  struct {
    byte PMTLD0      :1;                                       /* PIT Micro Timer Load Bit 0 */
    byte PMTLD1      :1;                                       /* PIT Micro Timer Load Bit 1 */
    byte PMTLD2      :1;                                       /* PIT Micro Timer Load Bit 2 */
    byte PMTLD3      :1;                                       /* PIT Micro Timer Load Bit 3 */
    byte PMTLD4      :1;                                       /* PIT Micro Timer Load Bit 4 */
    byte PMTLD5      :1;                                       /* PIT Micro Timer Load Bit 5 */
    byte PMTLD6      :1;                                       /* PIT Micro Timer Load Bit 6 */
    byte PMTLD7      :1;                                       /* PIT Micro Timer Load Bit 7 */
  } Bits;
} PITMTLD0STR;
extern volatile PITMTLD0STR _PITMTLD0 @(REG_BASE + 0x00000346UL);
#define PITMTLD0                        _PITMTLD0.Byte
#define PITMTLD0_PMTLD0                 _PITMTLD0.Bits.PMTLD0
#define PITMTLD0_PMTLD1                 _PITMTLD0.Bits.PMTLD1
#define PITMTLD0_PMTLD2                 _PITMTLD0.Bits.PMTLD2
#define PITMTLD0_PMTLD3                 _PITMTLD0.Bits.PMTLD3
#define PITMTLD0_PMTLD4                 _PITMTLD0.Bits.PMTLD4
#define PITMTLD0_PMTLD5                 _PITMTLD0.Bits.PMTLD5
#define PITMTLD0_PMTLD6                 _PITMTLD0.Bits.PMTLD6
#define PITMTLD0_PMTLD7                 _PITMTLD0.Bits.PMTLD7
/* PITMTLD_ARR: Access 2 PITMTLDx registers in an array */
#define PITMTLD_ARR                     ((volatile byte *) &PITMTLD0)

#define PITMTLD0_PMTLD0_MASK            1U
#define PITMTLD0_PMTLD1_MASK            2U
#define PITMTLD0_PMTLD2_MASK            4U
#define PITMTLD0_PMTLD3_MASK            8U
#define PITMTLD0_PMTLD4_MASK            16U
#define PITMTLD0_PMTLD5_MASK            32U
#define PITMTLD0_PMTLD6_MASK            64U
#define PITMTLD0_PMTLD7_MASK            128U


/*** PITMTLD1 - PIT Micro Timer Load Register 1; 0x00000347 ***/
typedef union {
  byte Byte;
  struct {
    byte PMTLD0      :1;                                       /* PIT Micro Timer Load Bit 0 */
    byte PMTLD1      :1;                                       /* PIT Micro Timer Load Bit 1 */
    byte PMTLD2      :1;                                       /* PIT Micro Timer Load Bit 2 */
    byte PMTLD3      :1;                                       /* PIT Micro Timer Load Bit 3 */
    byte PMTLD4      :1;                                       /* PIT Micro Timer Load Bit 4 */
    byte PMTLD5      :1;                                       /* PIT Micro Timer Load Bit 5 */
    byte PMTLD6      :1;                                       /* PIT Micro Timer Load Bit 6 */
    byte PMTLD7      :1;                                       /* PIT Micro Timer Load Bit 7 */
  } Bits;
} PITMTLD1STR;
extern volatile PITMTLD1STR _PITMTLD1 @(REG_BASE + 0x00000347UL);
#define PITMTLD1                        _PITMTLD1.Byte
#define PITMTLD1_PMTLD0                 _PITMTLD1.Bits.PMTLD0
#define PITMTLD1_PMTLD1                 _PITMTLD1.Bits.PMTLD1
#define PITMTLD1_PMTLD2                 _PITMTLD1.Bits.PMTLD2
#define PITMTLD1_PMTLD3                 _PITMTLD1.Bits.PMTLD3
#define PITMTLD1_PMTLD4                 _PITMTLD1.Bits.PMTLD4
#define PITMTLD1_PMTLD5                 _PITMTLD1.Bits.PMTLD5
#define PITMTLD1_PMTLD6                 _PITMTLD1.Bits.PMTLD6
#define PITMTLD1_PMTLD7                 _PITMTLD1.Bits.PMTLD7

#define PITMTLD1_PMTLD0_MASK            1U
#define PITMTLD1_PMTLD1_MASK            2U
#define PITMTLD1_PMTLD2_MASK            4U
#define PITMTLD1_PMTLD3_MASK            8U
#define PITMTLD1_PMTLD4_MASK            16U
#define PITMTLD1_PMTLD5_MASK            32U
#define PITMTLD1_PMTLD6_MASK            64U
#define PITMTLD1_PMTLD7_MASK            128U


/*** PITLD0 - PIT Load Register 0; 0x00000348 ***/
typedef union {
  word Word;
} PITLD0STR;
extern volatile PITLD0STR _PITLD0 @(REG_BASE + 0x00000348UL);
#define PITLD0                          _PITLD0.Word


/*** PITCNT0 - PIT Count Register 0; 0x0000034A ***/
typedef union {
  word Word;
} PITCNT0STR;
extern volatile PITCNT0STR _PITCNT0 @(REG_BASE + 0x0000034AUL);
#define PITCNT0                         _PITCNT0.Word


/*** PITLD1 - PIT Load Register 1; 0x0000034C ***/
typedef union {
  word Word;
} PITLD1STR;
extern volatile PITLD1STR _PITLD1 @(REG_BASE + 0x0000034CUL);
#define PITLD1                          _PITLD1.Word


/*** PITCNT1 - PIT Count Register 1; 0x0000034E ***/
typedef union {
  word Word;
} PITCNT1STR;
extern volatile PITCNT1STR _PITCNT1 @(REG_BASE + 0x0000034EUL);
#define PITCNT1                         _PITCNT1.Word


/*** PITLD2 - PIT Load Register 2; 0x00000350 ***/
typedef union {
  word Word;
} PITLD2STR;
extern volatile PITLD2STR _PITLD2 @(REG_BASE + 0x00000350UL);
#define PITLD2                          _PITLD2.Word


/*** PITCNT2 - PIT Count Register 2; 0x00000352 ***/
typedef union {
  word Word;
} PITCNT2STR;
extern volatile PITCNT2STR _PITCNT2 @(REG_BASE + 0x00000352UL);
#define PITCNT2                         _PITCNT2.Word


/*** PITLD3 - PIT Load Register 3; 0x00000354 ***/
typedef union {
  word Word;
} PITLD3STR;
extern volatile PITLD3STR _PITLD3 @(REG_BASE + 0x00000354UL);
#define PITLD3                          _PITLD3.Word


/*** PITCNT3 - PIT Count Register 3; 0x00000356 ***/
typedef union {
  word Word;
} PITCNT3STR;
extern volatile PITCNT3STR _PITCNT3 @(REG_BASE + 0x00000356UL);
#define PITCNT3                         _PITCNT3.Word


/*** BAKEY0 - Backdoor Comparison Key 0; 0x0000FF00 ***/
typedef union {
  word Word;
  struct {
    word KEY         :16;                                      /* Backdoor Comparison Key Bits */
  } Bits;
} BAKEY0STR;
/* Tip for register initialization in the user code:  const word BAKEY0_INIT @0x0000FF00 = <BAKEY0_INITVAL>; */
#define _BAKEY0 (*(const BAKEY0STR *)0x0000FF00)
#define BAKEY0                          _BAKEY0.Word
#define BAKEY0_KEY                      _BAKEY0.Bits.KEY
/* BAKEY_ARR: Access 4 BAKEYx registers in an array */
#define BAKEY_ARR                       ((volatile word *) &BAKEY0)

#define BAKEY0_KEY_MASK                 65535U
#define BAKEY0_KEY_BITNUM               0U


/*** BAKEY1 - Backdoor Comparison Key 1; 0x0000FF02 ***/
typedef union {
  word Word;
  struct {
    word KEY         :16;                                      /* Backdoor Comparison Key Bits */
  } Bits;
} BAKEY1STR;
/* Tip for register initialization in the user code:  const word BAKEY1_INIT @0x0000FF02 = <BAKEY1_INITVAL>; */
#define _BAKEY1 (*(const BAKEY1STR *)0x0000FF02)
#define BAKEY1                          _BAKEY1.Word
#define BAKEY1_KEY                      _BAKEY1.Bits.KEY

#define BAKEY1_KEY_MASK                 65535U
#define BAKEY1_KEY_BITNUM               0U


/*** BAKEY2 - Backdoor Comparison Key 2; 0x0000FF04 ***/
typedef union {
  word Word;
  struct {
    word KEY         :16;                                      /* Backdoor Comparison Key Bits */
  } Bits;
} BAKEY2STR;
/* Tip for register initialization in the user code:  const word BAKEY2_INIT @0x0000FF04 = <BAKEY2_INITVAL>; */
#define _BAKEY2 (*(const BAKEY2STR *)0x0000FF04)
#define BAKEY2                          _BAKEY2.Word
#define BAKEY2_KEY                      _BAKEY2.Bits.KEY

#define BAKEY2_KEY_MASK                 65535U
#define BAKEY2_KEY_BITNUM               0U


/*** BAKEY3 - Backdoor Comparison Key 3; 0x0000FF06 ***/
typedef union {
  word Word;
  struct {
    word KEY         :16;                                      /* Backdoor Comparison Key Bits */
  } Bits;
} BAKEY3STR;
/* Tip for register initialization in the user code:  const word BAKEY3_INIT @0x0000FF06 = <BAKEY3_INITVAL>; */
#define _BAKEY3 (*(const BAKEY3STR *)0x0000FF06)
#define BAKEY3                          _BAKEY3.Word
#define BAKEY3_KEY                      _BAKEY3.Bits.KEY

#define BAKEY3_KEY_MASK                 65535U
#define BAKEY3_KEY_BITNUM               0U


/*** NVFPROT - Non Volatile P-Flash Protection Register; 0x0000FF0C ***/
typedef union {
  byte Byte;
  struct {
    byte FPLS0       :1;                                       /* Flash Protection Lower Address Size Bit 0 */
    byte FPLS1       :1;                                       /* Flash Protection Lower Address Size Bit 1 */
    byte FPLDIS      :1;                                       /* Flash Protection Lower Address Range Disable */
    byte FPHS0       :1;                                       /* Flash Protection Higher Address Size Bit 0 */
    byte FPHS1       :1;                                       /* Flash Protection Higher Address Size Bit 1 */
    byte FPHDIS      :1;                                       /* Flash Protection Higher Address Range Disable */
    byte RNV6        :1;                                       /* Reserved Nonvolatile Bit */
    byte FPOPEN      :1;                                       /* Flash Protection Operation Enable */
  } Bits;
  struct {
    byte grpFPLS :2;
    byte         :1;
    byte grpFPHS :2;
    byte         :1;
    byte grpRNV_6 :1;
    byte         :1;
  } MergedBits;
} NVFPROTSTR;
/* Tip for register initialization in the user code:  const byte NVFPROT_INIT @0x0000FF0C = <NVFPROT_INITVAL>; */
#define _NVFPROT (*(const NVFPROTSTR *)0x0000FF0C)
#define NVFPROT                         _NVFPROT.Byte
#define NVFPROT_FPLS0                   _NVFPROT.Bits.FPLS0
#define NVFPROT_FPLS1                   _NVFPROT.Bits.FPLS1
#define NVFPROT_FPLDIS                  _NVFPROT.Bits.FPLDIS
#define NVFPROT_FPHS0                   _NVFPROT.Bits.FPHS0
#define NVFPROT_FPHS1                   _NVFPROT.Bits.FPHS1
#define NVFPROT_FPHDIS                  _NVFPROT.Bits.FPHDIS
#define NVFPROT_RNV6                    _NVFPROT.Bits.RNV6
#define NVFPROT_FPOPEN                  _NVFPROT.Bits.FPOPEN
#define NVFPROT_FPLS                    _NVFPROT.MergedBits.grpFPLS
#define NVFPROT_FPHS                    _NVFPROT.MergedBits.grpFPHS

#define NVFPROT_FPLS0_MASK              1U
#define NVFPROT_FPLS1_MASK              2U
#define NVFPROT_FPLDIS_MASK             4U
#define NVFPROT_FPHS0_MASK              8U
#define NVFPROT_FPHS1_MASK              16U
#define NVFPROT_FPHDIS_MASK             32U
#define NVFPROT_RNV6_MASK               64U
#define NVFPROT_FPOPEN_MASK             128U
#define NVFPROT_FPLS_MASK               3U
#define NVFPROT_FPLS_BITNUM             0U
#define NVFPROT_FPHS_MASK               24U
#define NVFPROT_FPHS_BITNUM             3U


/*** NVDFPROT - Non Volatile D-Flash Protection Register; 0x0000FF0D ***/
typedef union {
  byte Byte;
  struct {
    byte DPS0        :1;                                       /* D-Flash Protection Size Bit 0 */
    byte DPS1        :1;                                       /* D-Flash Protection Size Bit 1 */
    byte DPS2        :1;                                       /* D-Flash Protection Size Bit 2 */
    byte DPS3        :1;                                       /* D-Flash Protection Size Bit 3 */
    byte DPS4        :1;                                       /* D-Flash Protection Size Bit 4 */
    byte             :1; 
    byte             :1; 
    byte DPOPEN      :1;                                       /* D-Flash Protection Control */
  } Bits;
  struct {
    byte grpDPS  :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NVDFPROTSTR;
/* Tip for register initialization in the user code:  const byte NVDFPROT_INIT @0x0000FF0D = <NVDFPROT_INITVAL>; */
#define _NVDFPROT (*(const NVDFPROTSTR *)0x0000FF0D)
#define NVDFPROT                        _NVDFPROT.Byte
#define NVDFPROT_DPS0                   _NVDFPROT.Bits.DPS0
#define NVDFPROT_DPS1                   _NVDFPROT.Bits.DPS1
#define NVDFPROT_DPS2                   _NVDFPROT.Bits.DPS2
#define NVDFPROT_DPS3                   _NVDFPROT.Bits.DPS3
#define NVDFPROT_DPS4                   _NVDFPROT.Bits.DPS4
#define NVDFPROT_DPOPEN                 _NVDFPROT.Bits.DPOPEN
#define NVDFPROT_DPS                    _NVDFPROT.MergedBits.grpDPS

#define NVDFPROT_DPS0_MASK              1U
#define NVDFPROT_DPS1_MASK              2U
#define NVDFPROT_DPS2_MASK              4U
#define NVDFPROT_DPS3_MASK              8U
#define NVDFPROT_DPS4_MASK              16U
#define NVDFPROT_DPOPEN_MASK            128U
#define NVDFPROT_DPS_MASK               31U
#define NVDFPROT_DPS_BITNUM             0U


/*** NVFOPT - Non Volatile Flash Option Register; 0x0000FF0E ***/
typedef union {
  byte Byte;
  struct {
    byte NV0         :1;                                       /* Nonvolatile Bit 0 */
    byte NV1         :1;                                       /* Nonvolatile Bit 1 */
    byte NV2         :1;                                       /* Nonvolatile Bit 2 */
    byte NV3         :1;                                       /* Nonvolatile Bit 3 */
    byte NV4         :1;                                       /* Nonvolatile Bit 4 */
    byte NV5         :1;                                       /* Nonvolatile Bit 5 */
    byte NV6         :1;                                       /* Nonvolatile Bit 6 */
    byte NV7         :1;                                       /* Nonvolatile Bit 7 */
  } Bits;
} NVFOPTSTR;
/* Tip for register initialization in the user code:  const byte NVFOPT_INIT @0x0000FF0E = <NVFOPT_INITVAL>; */
#define _NVFOPT (*(const NVFOPTSTR *)0x0000FF0E)
#define NVFOPT                          _NVFOPT.Byte
#define NVFOPT_NV0                      _NVFOPT.Bits.NV0
#define NVFOPT_NV1                      _NVFOPT.Bits.NV1
#define NVFOPT_NV2                      _NVFOPT.Bits.NV2
#define NVFOPT_NV3                      _NVFOPT.Bits.NV3
#define NVFOPT_NV4                      _NVFOPT.Bits.NV4
#define NVFOPT_NV5                      _NVFOPT.Bits.NV5
#define NVFOPT_NV6                      _NVFOPT.Bits.NV6
#define NVFOPT_NV7                      _NVFOPT.Bits.NV7

#define NVFOPT_NV0_MASK                 1U
#define NVFOPT_NV1_MASK                 2U
#define NVFOPT_NV2_MASK                 4U
#define NVFOPT_NV3_MASK                 8U
#define NVFOPT_NV4_MASK                 16U
#define NVFOPT_NV5_MASK                 32U
#define NVFOPT_NV6_MASK                 64U
#define NVFOPT_NV7_MASK                 128U


/*** NVFSEC - Non Volatile Flash Security Register; 0x0000FF0F ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte RNV2        :1;                                       /* Reserved Nonvolatile Bit 2 */
    byte RNV3        :1;                                       /* Reserved Nonvolatile Bit 3 */
    byte RNV4        :1;                                       /* Reserved Nonvolatile Bit 4 */
    byte RNV5        :1;                                       /* Reserved Nonvolatile Bit 5 */
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte grpRNV_2 :4;
    byte grpKEYEN :2;
  } MergedBits;
} NVFSECSTR;
/* Tip for register initialization in the user code:  const byte NVFSEC_INIT @0x0000FF0F = <NVFSEC_INITVAL>; */
#define _NVFSEC (*(const NVFSECSTR *)0x0000FF0F)
#define NVFSEC                          _NVFSEC.Byte
#define NVFSEC_SEC0                     _NVFSEC.Bits.SEC0
#define NVFSEC_SEC1                     _NVFSEC.Bits.SEC1
#define NVFSEC_RNV2                     _NVFSEC.Bits.RNV2
#define NVFSEC_RNV3                     _NVFSEC.Bits.RNV3
#define NVFSEC_RNV4                     _NVFSEC.Bits.RNV4
#define NVFSEC_RNV5                     _NVFSEC.Bits.RNV5
#define NVFSEC_KEYEN0                   _NVFSEC.Bits.KEYEN0
#define NVFSEC_KEYEN1                   _NVFSEC.Bits.KEYEN1
#define NVFSEC_SEC                      _NVFSEC.MergedBits.grpSEC
#define NVFSEC_RNV_2                    _NVFSEC.MergedBits.grpRNV_2
#define NVFSEC_KEYEN                    _NVFSEC.MergedBits.grpKEYEN
#define NVFSEC_RNV                      NVFSEC_RNV_2

#define NVFSEC_SEC0_MASK                1U
#define NVFSEC_SEC1_MASK                2U
#define NVFSEC_RNV2_MASK                4U
#define NVFSEC_RNV3_MASK                8U
#define NVFSEC_RNV4_MASK                16U
#define NVFSEC_RNV5_MASK                32U
#define NVFSEC_KEYEN0_MASK              64U
#define NVFSEC_KEYEN1_MASK              128U
#define NVFSEC_SEC_MASK                 3U
#define NVFSEC_SEC_BITNUM               0U
#define NVFSEC_RNV_2_MASK               60U
#define NVFSEC_RNV_2_BITNUM             2U
#define NVFSEC_KEYEN_MASK               192U
#define NVFSEC_KEYEN_BITNUM             6U


  /* Watchdog reset macro */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() (void)(ARMCOP = 0x55U, ARMCOP = 0xAAU)
#endif
#endif /* __RESET_WATCHDOG */


/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/
/* --------------------------------------------------------------------------- */
/* The following symbols were removed, because they were invalid or irrelevant */
/* --------------------------------------------------------------------------- */



/* **** 20.2.2008 7:32:00 */

#define FSTAT_RSVD                       This_symb_has_been_depreciated
#define FSTAT_RSVD_MASK                  This_symb_has_been_depreciated

/* **** 17.4.2008 11:27:59 */

#define TCNTH                            TCNTHi
#define TCNTL                            TCNTLo
#define TC0H                             TC0Hi
#define TC0L                             TC0Lo
#define TC1H                             TC1Hi
#define TC1L                             TC1Lo
#define TC2H                             TC2Hi
#define TC2L                             TC2Lo
#define TC3H                             TC3Hi
#define TC3L                             TC3Lo
#define TC4H                             TC4Hi
#define TC4L                             TC4Lo
#define TC5H                             TC5Hi
#define TC5L                             TC5Lo
#define TC6H                             TC6Hi
#define TC6L                             TC6Lo
#define TC7H                             TC7Hi
#define TC7L                             TC7Lo

/* **** 22.5.2008 14:43:20 */

#define VectorNumber_VReserved65         VectorNumber_Vhti
#define VReserved65                      Vhti



#ifndef __V30COMPATIBLE__
#pragma OPTION DEL V30toV31Compatible
#endif
/*lint -restore  +esym(961,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */

#endif
