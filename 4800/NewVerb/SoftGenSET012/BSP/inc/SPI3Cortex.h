/* ******************************************************************** */
/*                       Header File SPI3Cortex.h                       */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _SPI3CORTEX_H

#define _SPI3CORTEX_H

#ifdef   SPI3_GLOBALS

#define  SPI3_EXT  

#else

#define  SPI3_EXT extern

#endif

/* ******************************************************************** */
/*  SPI3_VERSION  = 10xx: VEC1000 Application                           */
/*  SPI3_VERSION  = 40xx: VEC4000 Application                           */
/*  SPI3_VERSION  = 68xx: VEC6800 Application                           */
/*  SPI3_VERSION  = 69xx: VEC6900 Application                           */
/*  SPI3_VERSION  = 760x: GEC7600-Main Application                      */
/*  SPI3_VERSION  = 761x: GEC7600-Display Application                   */
/*  SPI3_VERSION  = 780x: GEC7800-Main Application                      */
/*  SPI3_VERSION  = 781x: GEC7800-Display Application                   */
/*  SPI3_VERSION  = 80xx: VEC8000 Application                           */
/*  SPI3_VERSION  = 90xx: VEC9000 Application                           */
/*  SPI3_VERSION  = 96xx: VEC9600 Application                           */
/* ******************************************************************** */

#define SPI3_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define SPI3_1000_COMMON_ON       0
#define SPI3_4000_COMMON_ON       0
#define SPI3_6800_COMMON_ON       0
#define SPI3_6900_COMMON_ON       0
#define SPI3_7600_COMMON_ON       0
#define SPI3_7600_MAIN_CHIP_ON    0
#define SPI3_7600_AUX_CHIP_ON     0
#define SPI3_7800_COMMON_ON       0
#define SPI3_7800_MAIN_CHIP_ON    0
#define SPI3_7800_AUX_CHIP_ON     0
#define SPI3_8000_COMMON_ON       0
#define SPI3_9000_COMMON_ON       0
#define SPI3_9600_COMMON_ON       0
#if   ((SPI3_VERSION / 100)   == 10)
#undef  SPI3_1000_COMMON_ON
#define SPI3_1000_COMMON_ON       1
#endif
#if   ((SPI3_VERSION / 100)   == 40)
#undef  SPI3_4000_COMMON_ON
#define SPI3_4000_COMMON_ON       1
#endif
#if   ((SPI3_VERSION / 100)   == 68)
#undef  SPI3_6800_COMMON_ON
#define SPI3_6800_COMMON_ON       1
#endif
#if   ((SPI3_VERSION / 100)   == 69)
#undef  SPI3_6900_COMMON_ON
#define SPI3_6900_COMMON_ON       1
#endif
#if   ((SPI3_VERSION / 100)   == 76)
#undef  SPI3_7600_COMMON_ON
#define SPI3_7600_COMMON_ON       1
#endif
#if   ((SPI3_VERSION / 10)   == 760)
#undef  SPI3_7600_MAIN_CHIP_ON
#define SPI3_7600_MAIN_CHIP_ON    1
#endif
#if   ((SPI3_VERSION / 10)   == 761)
#undef  SPI3_7600_AUX_CHIP_ON
#define SPI3_7600_AUX_CHIP_ON     1
#endif
#if   ((SPI3_VERSION / 100)   == 78)
#undef  SPI3_7800_COMMON_ON
#define SPI3_7800_COMMON_ON       1
#endif
#if   ((SPI3_VERSION / 10)   == 780)
#undef  SPI3_7800_MAIN_CHIP_ON
#define SPI3_7800_MAIN_CHIP_ON    1
#endif
#if   ((SPI3_VERSION / 10)   == 781)
#undef  SPI3_7800_AUX_CHIP_ON
#define SPI3_7800_AUX_CHIP_ON     1
#endif
#if   ((SPI3_VERSION / 100)   == 80)
#undef  SPI3_8000_COMMON_ON
#define SPI3_8000_COMMON_ON       1
#endif
#if   ((SPI3_VERSION / 100)   == 90)
#undef  SPI3_9000_COMMON_ON
#define SPI3_9000_COMMON_ON       1
#endif
#if   ((SPI3_VERSION / 100)   == 96)
#undef  SPI3_9600_COMMON_ON
#define SPI3_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define SPI3_FUNCTION_ON          0
#define SPI3_CPU_9S12_ON          0
#define SPI3_CPU_POWERPC_ON       0
#define SPI3_CPU_STM32F1_ON       0
#define SPI3_CPU_STM32F103_ON     0
#define SPI3_CPU_STM32F105_ON     0
#if    (SPI3_1000_COMMON_ON    == 1)
#undef  SPI3_CPU_9S12_ON
#define SPI3_CPU_9S12_ON          1
#endif
#if    (SPI3_4000_COMMON_ON    == 1)
#undef  SPI3_CPU_9S12_ON
#define SPI3_CPU_9S12_ON          1
#endif
#if    (SPI3_6800_COMMON_ON    == 1)
#undef  SPI3_CPU_9S12_ON
#define SPI3_CPU_9S12_ON          1
#endif
#if    (SPI3_6900_COMMON_ON    == 1)
#undef  SPI3_CPU_POWERPC_ON
#define SPI3_CPU_POWERPC_ON       1
#endif
#if    (SPI3_7600_COMMON_ON    == 1)
#undef  SPI3_CPU_STM32F1_ON
#define SPI3_CPU_STM32F1_ON       1
#endif
#if    (SPI3_7600_MAIN_CHIP_ON == 1)
#undef  SPI3_CPU_STM32F105_ON
#define SPI3_CPU_STM32F105_ON     1
#endif
#if    (SPI3_7600_AUX_CHIP_ON  == 1)
#undef  SPI3_CPU_STM32F103_ON
#define SPI3_CPU_STM32F103_ON     1
#endif
#if    (SPI3_7800_COMMON_ON    == 1)
#undef  SPI3_CPU_STM32F1_ON
#define SPI3_CPU_STM32F1_ON       1
#endif
#if    (SPI3_7800_MAIN_CHIP_ON == 1)
#undef  SPI3_CPU_STM32F105_ON
#define SPI3_CPU_STM32F105_ON     1
#endif
#if    (SPI3_7800_AUX_CHIP_ON  == 1)
#undef  SPI3_CPU_STM32F103_ON
#define SPI3_CPU_STM32F103_ON     1
#endif
#if    (SPI3_8000_COMMON_ON    == 1)
#undef  SPI3_CPU_POWERPC_ON
#define SPI3_CPU_POWERPC_ON       1
#endif
#if    (SPI3_9000_COMMON_ON    == 1)
#undef  SPI3_CPU_POWERPC_ON
#define SPI3_CPU_POWERPC_ON       1
#endif
#if    (SPI3_9600_COMMON_ON    == 1)
#undef  SPI3_CPU_POWERPC_ON
#define SPI3_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                    (F105 SPI3 Remap Definition)                      */
/* Default:  (SPI3_NSS/PA4,  SCK/PA5, MISO/PA6, MOSI/PA7)               */
/* Remap:    (SPI3_NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5)               */
/* ******************************************************************** */
#define SPI3_AFIO_REMAP1        0
#define SPI3_AFIO_REMAP2        0
#define SPI3_PT_BT_CS           PA4
#define SPI3_PT_BT_SCK          PA5
#define SPI3_PT_BT_IN           PA6
#define SPI3_PT_BT_OUT          PA7
#define SPI3_PT_BT_CD           PC4
#define SPI3_PT_CS              GPIOA
#define SPI3_PT_SCK             GPIOA
#define SPI3_PT_IN              GPIOA
#define SPI3_PT_OUT             GPIOA
#define SPI3_PT_CD              GPIOC
#define SPI3_BT_CS              4
#define SPI3_BT_SCK             5
#define SPI3_BT_IN              6
#define SPI3_BT_OUT             7
#define SPI3_BT_CD              4
#define SPI3_CLK_SLOW()         SPI3->CR1 |=  SPI_CR1_BR_0 | SPI_CR1_BR_2
#define SPI3_CLK_FAST()         SPI3->CR1 &= ~SPI_CR1_BR
#define SPI3_CS_HIGH()          SPI3_PT_CS->BSRR = 1UL <<  SPI3_BT_CS
#define SPI3_CS_LOW()           SPI3_PT_CS->BSRR = 1UL << (SPI3_BT_CS+16)
#define SPI3_GET_DETECT_PIN()  (SPI3_PT_CD->IDR & (1UL << SPI3_BT_CD))
#define SPI3_I2S_FLAG_RXNE     (INT16U)0x0001
#define SPI3_I2S_FLAG_TXE      (INT16U)0x0002
#define SPI3_I2S_FLAG_CHSIDE   (INT16U)0x0004
#define SPI3_I2S_FLAG_UDR      (INT16U)0x0008
#define SPI3_I2S_FLAG_CRCERR   (INT16U)0x0010
#define SPI3_I2S_FLAG_MODF     (INT16U)0x0020
#define SPI3_I2S_FLAG_OVR      (INT16U)0x0040
#define SPI3_I2S_FLAG_BSY      (INT16U)0x0080

/* ******************************************************************** */
/*                       SD Card specific error defines                 */
/* ******************************************************************** */
#if    (SPI3_FUNCTION_ON == 1)

#define SD_CMD_GO_IDLE_STATE       0                    /* CMD0  = 0x40 */
#define SD_CMD_SEND_OP_COND        1                    /* CMD1  = 0x41 */
#define SD_CMD_SEND_CSD            9                    /* CMD9  = 0x49 */
#define SD_CMD_SEND_CID            10                   /* CMD10 = 0x4A */
#define SD_CMD_STOP_TRANSMISSION   12                   /* CMD12 = 0x4C */
#define SD_CMD_SEND_STATUS         13                   /* CMD13 = 0x4D */
#define SD_CMD_SET_BLOCKLEN        16                   /* CMD16 = 0x50 */
#define SD_CMD_READ_SINGLE_BLOCK   17                   /* CMD17 = 0x51 */
#define SD_CMD_READ_MULT_BLOCK     18                   /* CMD18 = 0x52 */
#define SD_CMD_SET_BLOCK_COUNT     23                   /* CMD23 = 0x57 */
#define SD_CMD_WRITE_SINGLE_BLOCK  24                   /* CMD24 = 0x58 */
#define SD_CMD_WRITE_MULT_BLOCK    25                   /* CMD25 = 0x59 */
#define SD_CMD_PROG_CSD            27                   /* CMD27 = 0x5B */
#define SD_CMD_SET_WRITE_PROT      28                   /* CMD28 = 0x5C */
#define SD_CMD_CLR_WRITE_PROT      29                   /* CMD29 = 0x5D */
#define SD_CMD_SEND_WRITE_PROT     30                   /* CMD30 = 0x5E */
#define SD_CMD_SD_ERASE_GRP_START  32                   /* CMD32 = 0x60 */
#define SD_CMD_SD_ERASE_GRP_END    33                   /* CMD33 = 0x61 */
#define SD_CMD_UNTAG_SECTOR        34                   /* CMD34 = 0x62 */
#define SD_CMD_ERASE_GRP_START     35                   /* CMD35 = 0x63 */
#define SD_CMD_ERASE_GRP_END       36                   /* CMD36 = 0x64 */
#define SD_CMD_UNTAG_ERASE_GROUP   37                   /* CMD37 = 0x65 */
#define SD_CMD_ERASE               38                   /* CMD38 = 0x66 */

#define SD_RESPONSE_NO_ERROR       0x00
#define SD_IN_IDLE_STATE           0x01
#define SD_ERASE_RESET             0x02
#define SD_ILLEGAL_COMMAND         0x04
#define SD_COM_CRC_ERROR           0x08
#define SD_ERASE_SEQUENCE_ERROR    0x10
#define SD_ADDRESS_ERROR           0x20
#define SD_PARAMETER_ERROR         0x40
#define SD_RESPONSE_FAILURE        0xFF
#define SD_DATA_OK                 0x05
#define SD_DATA_CRC_ERROR          0x0B
#define SD_DATA_WRITE_ERROR        0x0D
#define SD_DATA_OTHER_ERROR        0xFF

#define SD_BLOCK_SIZE              512
#define SD_DUMMY_BYTE              0xFF
#define SD_PRESENT                 0x01
#define SD_NOT_PRESENT             0x00

#define SD_START_SINGLE_BL_READ    0xFE    /* Start Single Block Read    */
#define SD_START_MULTIP_BL_READ    0xFE    /* Start Multiple Block Read  */
#define SD_START_SINGLE_BL_WRITE   0xFE    /* Start Single Block Write   */
#define SD_START_MULTIP_BL_WRITE   0xFD    /* Start Multiple Block Write */
#define SD_STOP_MULTIP_BL_WRITE    0xFD    /* Stop Multiple Block Write  */


#define SDReadByte                 SPI3Read08u
#define SDWriteByte                SPI3Write08u

#endif
/* ***********************************t********************************* */
/*                            Type Definition                            */
/* ********************************************************************* */
#if (SPI3_FUNCTION_ON == 1)
typedef struct
{   VINT08U  CSDStruct;            /* CSD structure */
    VINT08U  SysSpecVersion;       /* System specification version */
    VINT08U  Reserved1;            /* Reserved */
    VINT08U  TAAC;                 /* Data read access-time 1 */
    VINT08U  NSAC;                 /* Data read access-time 2 in CLK cycles */
    VINT08U  MaxBusClkFrec;        /* Max. bus clock frequency */
    VINT16U  CardComdClasses;      /* Card command classes */
    VINT08U  RdBlockLen;           /* Max. read data block length */
    VINT08U  PartBlockRead;        /* Partial blocks for read allowed */
    VINT08U  WrBlockMisalign;      /* Write block misalignment */
    VINT08U  RdBlockMisalign;      /* Read block misalignment */
    VINT08U  DSRImpl;              /* DSR implemented */
    VINT08U  Reserved2;            /* Reserved */
    VINT32U  DeviceSize;           /* Device Size */
    VINT08U  MaxRdCurrentVDDMin;   /* Max. read current @ VDD min */
    VINT08U  MaxRdCurrentVDDMax;   /* Max. read current @ VDD max */
    VINT08U  MaxWrCurrentVDDMin;   /* Max. write current @ VDD min */
    VINT08U  MaxWrCurrentVDDMax;   /* Max. write current @ VDD max */
    VINT08U  DeviceSizeMul;        /* Device size multiplier */
    VINT08U  EraseGrSize;          /* Erase group size */
    VINT08U  EraseGrMul;           /* Erase group size multiplier */
    VINT08U  WrProtectGrSize;      /* Write protect group size */
    VINT08U  WrProtectGrEnable;    /* Write protect group enable */
    VINT08U  ManDeflECC;           /* Manufacturer default ECC */
    VINT08U  WrSpeedFact;          /* Write speed factor */
    VINT08U  MaxWrBlockLen;        /* Max. write data block length */
    VINT08U  WriteBlockPaPartial;  /* Partial blocks for write allowed */
    VINT08U  Reserved3;            /* Reserded */
    VINT08U  ContentProtectAppli;  /* Content protection application */
    VINT08U  FileFormatGrouop;     /* File format group */
    VINT08U  CopyFlag;             /* Copy flag (OTP) */
    VINT08U  PermWrProtect;        /* Permanent write protection */
    VINT08U  TempWrProtect;        /* Temporary write protection */
    VINT08U  FileFormat;           /* File Format */
    VINT08U  ECC;                  /* ECC code */
    VINT08U  CSD_CRC;              /* CSD CRC */
    VINT08U  Reserved4;            /* always 1 */
}   SD_CSD_STR;

typedef struct
{   VINT08U  ManufacturerID;       /* ManufacturerID */
    VINT16U  OEM_AppliID;          /* OEM/Application ID */
    VINT32U  ProdName1;            /* Product Name part1 */
    VINT08U  ProdName2;            /* Product Name part2*/
    VINT08U  ProdRev;              /* Product Revision */
    VINT32U  ProdSN;               /* Product Serial Number */
    VINT08U  Reserved1;            /* Reserved1 */
    VINT16U  ManufactDate;         /* Manufacturing Date */
    VINT08U  CID_CRC;              /* CID CRC */
    VINT08U  Reserved2;            /* always 1 */
}   SD_CID_STR;

typedef struct
{   SD_CSD_STR SD_csd;
    SD_CID_STR SD_cid;
    INT32U  CardCapacity;          /* Card Capacity */
    INT32U  CardBlockSize;         /* Card Block Size */
 //   INT16U  RCA;
 //   INT08U  ucCardType;
}   SD_CARD_INFO;
#endif

/* ******************************************************************** */
/*                     Variable Definitions                             */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)
SPI3_EXT INT32U uiSPI3Status;
#endif

/* ******************************************************************** */
/*                      Function Definition                             */
/* ******************************************************************** */
#if (SPI3_FUNCTION_ON == 1)

SPI3_EXT INT08U SDInit(void);
SPI3_EXT INT08U SDDetect(void);
SPI3_EXT INT08U SDGetCardInfo(SD_CARD_INFO *pInfo);
SPI3_EXT INT08U SDReadBlock(INT08U* pBuff, INT32U uiAddr, INT16U usBSiz);
SPI3_EXT INT08U SDReadMultBlock(INT08U *pBuff, INT32U uiAddr, INT16U usBSiz, INT32U usBNum);
SPI3_EXT INT08U SDWriteBlock(INT08U *pBuff, INT32U uiAddr, INT16U usBSiz);
SPI3_EXT INT08U SDWriteMultBlock(INT08U *pBuff, INT32U uiAddr, INT16U usBSiz, INT32U uiBNum);
SPI3_EXT INT08U SDGetCSDRegister(SD_CSD_STR* pSdCsd);
SPI3_EXT INT08U SDGetCIDRegister(SD_CID_STR *pSdCid);
SPI3_EXT INT08U SDGetDataResponse(void);
SPI3_EXT INT16U SDGetStatus(void);
SPI3_EXT INT08U SDGoIdleState(void);
SPI3_EXT INT08U SDGetResponse(INT08U ucResp);
SPI3_EXT void   SDSendCmd(INT08U ucCmd, INT32U uiArg, INT08U ucCrc);

SPI3_EXT void   SPI3Init(void);
SPI3_EXT void   SPI3Start(void);
SPI3_EXT void   SPI3HardInit(void);
SPI3_EXT INT08U SPI3Read08u(void);
SPI3_EXT INT08U SPI3Write08u(INT08U ucData);
SPI3_EXT INT08U SPI3Exchange08u(INT08U ucData);
SPI3_EXT INT16U SPI3Read16u(void);
SPI3_EXT INT16U SPI3Write16u(INT16U usData);
SPI3_EXT INT16U SPI3Exchange16u(INT16U usData);
SPI3_EXT void   SPI3SendHardCrc(void);
SPI3_EXT INT08U SPI3GetHardCrc08u(INT08U ucTxOrRx);
SPI3_EXT INT16U SPI3GetHardCrc16u(INT08U ucTxOrRx);
SPI3_EXT INT16U SPI3GetFlags(INT16U usFlgMsk);
SPI3_EXT void   SPI3ClrFlags(INT16U usFlgMsk);
SPI3_EXT void   SPI3ConfigI2S(INT08U ucNewState);
SPI3_EXT void   SPI3ConfigIT(INT16U usIntMsk, INT08U ucNewState);
SPI3_EXT void   SPI3ConfigDMA(INT16U usDmaMsk, INT08U ucNewState);
SPI3_EXT void   SPI3ConfigHardCrc(INT08U ucNewState);
SPI3_EXT void   SPI3SetDataSize08b(void);
SPI3_EXT void   SPI3SetDataSize16b(void);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */