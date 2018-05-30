/******************************************************************************
* COMPANY       : FORTURST
* PROJECT       : GEC7000
*******************************************************************************
* NAME          : defs.h
* DESCRIPTION   : Software definitions (depend on target configuration)
* CVS           : $Id: defs.h,v 1.0 2011/01/30 13:52:10 fisher Exp $
*******************************************************************************
* HISTORY       :
*   
******************************************************************************/

#ifndef _DEFS_H
#define _DEFS_H

#define PCB16W   0
#define PCB16DW  1
#define BOUND4800 0
#define BOUND9600 1

#define ISOCOMM 0 


#define CHECKSPEEDERR 1
/* Application/target specific configuration */

/* Custom integer types
 * uchar        8 bits unsigned
 * uint         16 bits unsigned
 * ulong        32 bits unsigned
 *
 * schar        8 bits signed
 * sint         16 bits signed
 * Slong        32 bits signed
 */


//#undef NULL
//#define NULL    (void *)0


#undef TRUE
#define TRUE 1
#undef FALSE
#define FALSE 0
typedef unsigned char   uchar;
typedef unsigned char   INT8U;
typedef unsigned int    INT16U;

typedef unsigned int    uint;
typedef unsigned long   INT32U;
typedef unsigned long   ulong;

typedef signed char     schar;
typedef signed int      sint;
typedef signed long     slong;

typedef unsigned char byte;

#define GECMODE16     1  //16ģ�� 
#define GECMODE25     0  //25ģ��
#define WCZJ_MODE     0  //Ϋ������
#define FEIERTE_MODE  0  //�ɶ��ػ�վ���ϵͳ
#define PUMP_MODE     0  //ˮ��ģʽ
//#define BAUDOUIN_MODE 1  //���Ű�

#define STANDARD_MODE 0
#define HF_MODE 0 //����
#define HW_MODE 0 //��Ϊ����
#define B_MODE  1 //���Ű�ģʽ
#define GEC16P_MODE 0

#define RECNUM 25


//#define SPEEDAD 409 

#if PCB16W==1
#define SPEEDAD 2048 //2.5v  pm7  ad15
#endif

#if PCB16DW==1
#define SPEEDAD 1300 
#endif

typedef struct
{   uint         usGain;      //����
    uint         usStability; //�ȶ�
    uint         usDerivative;//΢��
    uint         usInputOld;  //΢�ֱ����ֵ
    ulong         uiCtrlOld;   //���ֱ����ֵ
    ulong         uiCtrlMin;   //�����Сֵ
    ulong         uiCtrlMax;   //������ֵ
}   PID_PAR_STR;


typedef union
{
    byte Byte;
    struct
    {
        byte L4 : 4;
        byte H4 : 4;
    } BITS4;

    struct
    {
        byte BIT0 : 1;
        byte BIT1 : 1;
        byte BIT2 : 1;
        byte BIT3 : 1;
        byte BIT4 : 1;
        byte BIT5 : 1;
        byte BIT6 : 1;
        byte BIT7 : 1;
    } BITS;
} BCDFLG;


typedef union
{
    byte Byte;
    struct
    {
        byte BIT0 : 1;
        byte BIT1 : 1;
        byte BIT2 : 1;
        byte BIT3 : 1;
        byte BIT4 : 1;
        byte BIT5 : 1;
        byte BIT6 : 1;
        byte BIT7 : 1;
    } BITS;

} STRFLG8;

typedef union
{
    unsigned int Byte;
    signed int Sbyte;
    struct
    {
        byte BIT0 : 1;
        byte BIT1 : 1;
        byte BIT2 : 1;
        byte BIT3 : 1;
        byte BIT4 : 1;
        byte BIT5 : 1;
        byte BIT6 : 1;
        byte BIT7 : 1;
        byte BIT8 : 1;
        byte BIT9 : 1;
        byte BITA : 1;
        byte BITB : 1;
        byte BITC : 1;
        byte BITD : 1;
        byte BITE : 1;
        byte BITF : 1;
    } BITS;

    struct
    {
        byte BYTEH: 8;
        byte BYTEL: 8;
        
    } BYTES;

} STRFLG16;

typedef union
{
    unsigned long UDWORD;
    long DWORD;
    
    struct
    {
        unsigned int WORDH: 16;
        unsigned int WORDL: 16;
    }WORDS;
     
    struct
    {
        byte BYTE4: 8;
        byte BYTE3: 8;
        byte BYTE2: 8;
        byte BYTE1: 8;        
    } BYTES; 
            
    struct
    {
        byte BIT0  : 1;
        byte BIT1  : 1;
        byte BIT2  : 1;
        byte BIT3  : 1;
        byte BIT4  : 1;
        byte BIT5  : 1;
        byte BIT6  : 1;
        byte BIT7  : 1;
        byte BIT8  : 1;
        byte BIT9  : 1;
        byte BIT10 : 1;
        byte BIT11 : 1;
        byte BIT12 : 1;
        byte BIT13 : 1;
        byte BIT14 : 1;
        byte BIT15 : 1;
        byte BIT16 : 1;
        byte BIT17 : 1;
        byte BIT18 : 1;
        byte BIT19 : 1;
        byte BIT20 : 1;
        byte BIT21 : 1;
        byte BIT22 : 1;
        byte BIT23 : 1;
        byte BIT24 : 1;
        byte BIT25 : 1;
        byte BIT26 : 1;
        byte BIT27 : 1;
        byte BIT28 : 1;
        byte BIT29 : 1;
        byte BIT30 : 1;
        byte BIT31 : 1;                
    } BITS;

} STRFLG32;





typedef union
{
    uint ARRAY[RECNUM];
    struct
    {
        uint RecNum;
        uint Reason;
        BCDFLG DateL;
        BCDFLG DateH;
        BCDFLG TimeL;
        BCDFLG TimeH;
        BCDFLG Time2;
        BCDFLG Time3;
        uint Mode;
        uint RPM;
        uint POWER;
        uint PF;
        //uint LChr;
        uint Gfrq;
        uint Vg1;
        uint Vg2;
        uint Vg3;
        uint Ig1;
        uint Ig2;
        uint Ig3;
        uint Vm1;
        STRFLG16 OUTPUTDATA;
        uint UBat1;
        uint UBat2;
        uint OilP;
        uint EngT;
        uint FLvl;
        uint OilT;
        STRFLG16 INPUTDATA;
        
    } MEMBER;

} RECORD;

#define READONLY_DATA_LEN 200
#define RW_DATA_LEN 250
#define nop()   _asm(nop)



#define ROUTE_INTERRUPT(vec_adr, cfdata)                \
  INT_CFADDR= (vec_adr) & 0xF0;                         \
  INT_CFDATA_ARR[((vec_adr) & 0x0F) >> 1]= (cfdata)

#define SOFTWARETRIGGER0_VEC  0x72 /* vector address= 2 * channel id */
#define SCI0_VEC (0x6B * 2)
#define SCI1_VEC (0x6A * 2)
#define SCI4_VEC (0X43 * 2)
#define PIT0_VEC (0X3D * 2)
#define PIT1_VEC (0x3C * 2)
#define PIT2_VEC (0x3B * 2)
#define IOC0_VEC (0X77 * 2)
#define IOC2_VEC (0X75 * 2)
#define IOC3_VEC (0X74 * 2)
#define OVF_VEC  (0X6F * 2)
#define ATD0_VEC (0X69 * 2)


#define MSB(w) (*(((uchar*)(&w)) + 0))
#define LSB(w) (*(((uchar*)(&w)) + 1))   

#define AI_LEN      (16 * 64)

#if B_MODE
#define AI_NUM 10
#endif

#if FEIERTE_MODE
#define AI_NUM 11
#endif

#if STANDARD_MODE||GEC16P_MODE
#define AI_NUM 11
#endif

#define interval_logic_process			50
#define calib_logic_mask(x)					((x)*1000/interval_logic_process)

#define interval_warn_process   			100
#define warn_real_value(x,y)				((x)*(y))
#define ai_calib_dly_cnt(x)  	  		((x)*1000/interval_warn_process)

#define MASK_SENSOR_OPEN						65535
#define GCBPULSEOFF TimerEnArr[TMR_GCB_PULSE_OFF]=1,DO_GCB_PULSEOFF=1



#define sftEVENT(event)                        (event == TRUE)
#define sftSET_EVENT(event)                (event = TRUE)
#define sftACK_EVENT(event)                (event = FALSE)
#define sftRESET_EVENT(event)            (event = FALSE)
#define sftCLR_BUF(event)						(event=0)
#define sftCOMPARE_EVENT(event1,event2)					(event1==event2)
#define sftEVALUATION_EVENT(event1,event2)			(event1=event2)

#define EDI1 EXTERNINPUT.BITS.BIT7
#define EDI2 EXTERNINPUT.BITS.BIT6
#define EDI3 EXTERNINPUT.BITS.BIT5
#define EDI4 EXTERNINPUT.BITS.BIT4
#define EDI5 EXTERNINPUT.BITS.BIT3
#define EDI6 EXTERNINPUT.BITS.BIT2
#define EDI7 EXTERNINPUT.BITS.BIT1
#define EDI8 EXTERNINPUT.BITS.BIT0

#define EDO1 EXTERNOUTPUT.BITS.BITD
#define EDO2 EXTERNOUTPUT.BITS.BITC
#define EDO3 EXTERNOUTPUT.BITS.BITB
#define EDO4 EXTERNOUTPUT.BITS.BITA
#define EDO5 EXTERNOUTPUT.BITS.BITE
#define EDO6 EXTERNOUTPUT.BITS.BITF
#define EDO7 EXTERNOUTPUT.BITS.BIT0
#define EDO8 EXTERNOUTPUT.BITS.BIT1
#define EDO9 EXTERNOUTPUT.BITS.BIT2
#define EDO10 EXTERNOUTPUT.BITS.BIT3
#define EDO11 EXTERNOUTPUT.BITS.BIT4
#define EDO12 EXTERNOUTPUT.BITS.BIT5
#define EDO13 EXTERNOUTPUT.BITS.BIT6
#define EDO14 EXTERNOUTPUT.BITS.BIT7

#define HWPROT_OT             HWPROTECT.BITS.BIT0 //��Ϊ�����Ը�λ��־λ
#define HWPROT_OV             HWPROTECT.BITS.BIT1 //��Ϊ�ߵ�ѹ�Ը�λ��־λ
#define HWPROT_LV             HWPROTECT.BITS.BIT2 //��Ϊ�͵�ѹ�Ը�λ��־λ
#define HWPROT_OC             HWPROTECT.BITS.BIT3 //��Ϊ�������Ը�λ��־λ
#define HWPROT_ST             HWPROTECT.BITS.BIT4 //��Ϊ��·�Ը�λ��־λ
#define HWPROT_GH             HWPROTECT.BITS.BIT5 //��Ϊ����¶ȸ��Ը�λ��־λ


#define FET_PROT_OT           FETPROTECT.BITS.BIT0 //ˮ���Ը�λ
#define FET_PROT_OP           FETPROTECT.BITS.BIT1 //��ѹ�Ը�λ
#define FET_PROT_LV           FETPROTECT.BITS.BIT2 //�͵�ѹ�Ը�λ
#define FET_PROT_HV           FETPROTECT.BITS.BIT3 //�ߵ�ѹ�Ը�λ
#define FET_PROT_OC           FETPROTECT.BITS.BIT4 //�������Ը�λ
#define FET_PROT_BT           FETPROTECT.BITS.BIT5 //����¶��Ը�λ
#define FET_PROT_RT           FETPROTECT.BITS.BIT6 //�������¶��Ը�λ
#define FET_PROT_OL           FETPROTECT.BITS.BIT7 //�����Ը�λ

#define ALA_SPEED_LOW_PRE     DESALA.BITS.BIT0   //����Ԥ����λ
#define ALA_SPEED_HIGH_PRE    DESALA.BITS.BIT1   //����Ԥ����λ
#define ALA_SPEED_LOW_STOP    DESALA.BITS.BIT2   //���ٱ���ͣ��λ
#define ALA_SPEED_HIGH_STOP   DESALA.BITS.BIT3   //���ٱ���ͣ��λ
#define ALA_TEMP_HIGH_PRE     DESALA.BITS.BIT4   //�¶ȸ�Ԥ����λ
#define ALA_TEMP_HIGH_STOP    DESALA.BITS.BIT5   //�¶ȸ߱���ͣ��λ
#define ALA_OP_LOW_PRE        DESALA.BITS.BIT6   //����ѹԤ����λ
#define ALA_OP_LOW_STOP       DESALA.BITS.BIT7   //����ѹ����ͣ��λ

#define ALA_BATT_LOW_ALA      DESALA2.BITS.BIT0  //��ص�ѹ�ͱ���λ
#define ALA_BATT_HIGH_ALA     DESALA2.BITS.BIT1  //��ص�ѹ�߱���λ
#define ALA_FUEL_LOW_PRE      DESALA2.BITS.BIT2  //��λ��Ԥ����λ
#define ALA_FUEL_LOW_ALA      DESALA2.BITS.BIT3  //��λ�ͱ���λ
#define ALA_START_FAIL        DESALA2.BITS.BIT4  //��ʧ��
#define ALA_STOP_FAIL         DESALA2.BITS.BIT5  //ͣ��ʧ��
#define ALA_OILTEMP_STOP      DESALA2.BITS.BIT6  //�����±���
#define ALA_LOSTOIL           DESALA2.BITS.BIT7  //ȼ��й©

#define ALA_OPERR             DESALA3.BITS.BIT0  //��ѹ����
#define ALA_WTERR             DESALA3.BITS.BIT1  //ˮ�¶���
#define ALA_OTERR             DESALA3.BITS.BIT2  //���¶���
#define ALA_SPEEDERR          DESALA3.BITS.BIT3  //ת�ٶ���
#define ALA_OILTEMP_PRE       DESALA3.BITS.BIT4  //������Ԥ����
#define ALA_ESTOP             DESALA3.BITS.BIT5  //����ͣ��
#define ALA_POWERHIPRE        DESALA3.BITS.BIT6  //���ر���
#define ALA_SPEEDERR2         DESALA3.BITS.BIT7  //ת�ٴ���������2 




#define ALA_SAFE_LOWOP        BUSALA.BITS.BIT0   //��ȫģ�����ѹ����
#define ALA_SAFE_HIWT         BUSALA.BITS.BIT1   //��ȫģ���ˮ�±���
#define ALA_SAFE_HIOT         BUSALA.BITS.BIT2   //��ȫģ������±���
#define ALA_SAFE_HISPD        BUSALA.BITS.BIT3   //��ȫģ�鳬�ٱ���
#define ALA_CANFAIL           BUSALA.BITS.BIT5   //��ȫģ��ͨѶ����
#define ALA_DPLUSFAIL         BUSALA.BITS.BIT6   //D+����
#define ALA_M_POWERLOW        BUSALA.BITS.BIT4   //������Դ��ѹ��
#define ALA_M_POWERHI         BUSALA.BITS.BIT7   //������Դ��ѹ��



//#define STA_BUS_NORMAL        BUSALA.BITS.BIT4   //�е��Ƿ�����
//#define ALA_BUS_VOLTAGE_NB    BUSALA.BITS.BIT5   //�е��ѹ��ƽ��


#define ALA_BUS_OVER_VOLTAGE  TMPDATA   //�е��ѹ����
#define ALA_BUS_LOW_VOLTAGE   TMPDATA   //�е��ѹ����
#define ALA_BUS_OVER_FREQ     TMPDATA   //�е��Ƶ����
#define ALA_BUS_LOW_FREQ      TMPDATA   //�е�ǷƵ����
#define STA_BUS_NORMAL        TMPDATA   //�е��Ƿ�����
#define ALA_BUS_VOLTAGE_NB    TMPDATA   //�е��ѹ��ƽ��




#define ALA_EXCOILTEMP        GENALA.BITS.BIT0   //�ⲿ�����¶ȸ�
#define ALA_EXBEARINGTEMP     GENALA.BITS.BIT1   //�ⲿ����¶ȸ�
#define ALA_GEN_OVER_FREQ     GENALA.BITS.BIT2   //�����Ƶ����
#define ALA_GEN_LOW_FREQ      GENALA.BITS.BIT3   //����ǷƵ����
#define ALA_GEN_HIGH_CURRENT  GENALA.BITS.BIT4   //�����������
#define ALA_GEN_ACBFAULT      GENALA.BITS.BIT5   //ACB��·������
#define ALA_GEN_REVPOWER      GENALA.BITS.BIT6   //�湦
#define ALA_GEN_LOSTPHASE     GENALA.BITS.BIT7   //ȱ��




#define ALA_DES_STARTLOW      GENALA2.BITS.BIT0  //��ѹ����
#define ALA_DES_SWPLOW        GENALA2.BITS.BIT1  //��ˮѹ����
#define ALA_DES_WPLOW         GENALA2.BITS.BIT2  //��ˮѹ����
#define ALA_COILTEMP          GENALA2.BITS.BIT3  //�����¶ȸ�
#define ALA_GENLEAK           GENALA2.BITS.BIT4  //�����ˮй©
#define ALA_SPRINGINPUT       GENALA2.BITS.BIT5  //����������
#define ALA_COOLINGFAN        GENALA2.BITS.BIT6  //��ȴ���ȹ���
#define ALA_WATERPLOW         GENALA2.BITS.BIT7  //ˮѹ��


#define STA_DES_CRANKING      DES_STATUS.BITS.BIT0  //����������״̬
#define STA_DES_RUNNING       DES_STATUS.BITS.BIT1  //���б�־
#define STA_DES_ALARMS        DES_STATUS.BITS.BIT2  //���ͻ�����
#define STA_DES_PREALARMS     DES_STATUS.BITS.BIT3  //���ͻ�Ԥ��
#define STA_DES_STOP          DES_STATUS.BITS.BIT4  //ͣ��״̬
#define STA_DES_ENSTART       DES_STATUS.BITS.BIT5  //��������
#define STA_DES_START_SUCC    DES_STATUS.BITS.BIT6  //�𶯳ɹ�
#define STA_DES_ENSTOP        DES_STATUS.BITS.BIT7  //����ͣ��

#define STA_DES_PREHEAT       DES_STATUS2.BITS.BIT0 //Ԥ��״̬
#define STA_DES_START_IDLE    DES_STATUS2.BITS.BIT1 //�𶯵���״̬
#define STA_DES_STOP_IDLE     DES_STATUS2.BITS.BIT2 //ͣ������״̬
#define STA_DES_ESTOP         DES_STATUS2.BITS.BIT3 //����ͣ��״̬
#define STA_DES_SELFTEST      DES_STATUS2.BITS.BIT4 //�Լ�ģʽ
#define STA_DES_LUBFUNC       DES_STATUS2.BITS.BIT5 //Ԥ�󻬹���
#define STA_DES_STOPING       DES_STATUS2.BITS.BIT6 //ͣ����
#define STA_DES_STARTINT      DES_STATUS2.BITS.BIT7 //�𶯼�� 



#define STA_GEN_RUNNING       GEN_STATUS.BITS.BIT0  //�������������
#define STA_GEN_ALARMS        GEN_STATUS.BITS.BIT1  //���������
#define STA_GEN_PREALARMS     GEN_STATUS.BITS.BIT2  //�����Ԥ����
#define STA_GEN_STOP          GEN_STATUS.BITS.BIT3  //�����ֹͣ����

#define STA_AIR_CHOCK         ECU_STATUS.BITS.BIT7
#define STA_FUEL_CHOCK        ECU_STATUS.BITS.BIT6
#define STA_DESOIL_LEVEL      ECU_STATUS.BITS.BIT5
#define STA_MANUAL_PUMP       ECU_STATUS.BITS.BIT4
#define STA_AUTOSCALE         ECU_STATUS.BITS.BIT3
#define STA_ECULOCK           ECU_STATUS.BITS.BIT2
#define STA_ECU_PREHEAT       ECU_STATUS.BITS.BIT1
#define STA_FUELCHANGE        ECU_STATUS.BITS.BIT0

#define STA_PUMP_ERR          ECU_STATUS2.BITS.BIT7
#define STA_SPEED_SENSOR      ECU_STATUS2.BITS.BIT6
#define STA_LOW_OP            ECU_STATUS2.BITS.BIT5
#define STA_ECU_OVERHEAT      ECU_STATUS2.BITS.BIT4
#define STA_ECU_POWER         ECU_STATUS2.BITS.BIT3
#define STA_HIGH_SPEED        ECU_STATUS2.BITS.BIT2
#define STA_INTERNALERR       ECU_STATUS2.BITS.BIT1
#define STA_PUMP_ERR2         ECU_STATUS2.BITS.BIT0

#define ALA_HW_PUMP_ERR       HWALA.BITS.BIT0
#define ALA_HW_OILCHOCK       HWALA.BITS.BIT1
#define ALA_HW_AIRCHOCK       HWALA.BITS.BIT2
#define ALA_HW_FUELCHOCK      HWALA.BITS.BIT3
#define ALA_HW_DOORERR        HWALA.BITS.BIT4
#define ALA_HW_DESOIL_LEVEL   HWALA.BITS.BIT5
#define ALA_HW_FUELERR_UP     HWALA.BITS.BIT6
#define ALA_HW_FUELERR_DOWN   HWALA.BITS.BIT7

#define ALA_HW_PUMP_ERR2      HWALA2.BITS.BIT0
#define ALA_POWERFAIL         HWALA2.BITS.BIT1  //��Դ����
#define ALA_LOWLEVEL          HWALA2.BITS.BIT2  //Һλ��
#define ALA_MAINTAIN_OVER     HWALA2.BITS.BIT3
#define ALA_OIL_LOW_PRE       HWALA2.BITS.BIT4
#define ALA_OIL_LOW_ALA       HWALA2.BITS.BIT5


#define EN_DES_PROTECT_OP     PROTECT_FLAG.BITS.BIT0
#define EN_DES_PROTECT_WT     PROTECT_FLAG.BITS.BIT1
#define EN_DES_PROTECT_SPEED  PROTECT_FLAG.BITS.BIT2
#define EN_DES_PROTECT        PROTECT_FLAG.BITS.BIT3
#define EN_GEN_PROTECT        PROTECT_FLAG.BITS.BIT4
#define EN_BUS_PROTECT        PROTECT_FLAG.BITS.BIT5


#define EO_OILP_LOW      EDO1
#define EO_OILT_HIGH     EDO2
#define EO_STARTSUCC     EDO3
#define EO_BATT_LOW      EDO4
#define EO_WATERT_HIGH   EDO5
#define EO_BUZZER        EDO6
#define EO_COMMALA       EDO7
#define EO_EMSTOP        EDO11
#define EO_STARTFAIL     EDO8



//�Զ�������
#define DI_SWPLOW            INPUT_TEMP[0] //��ˮѹ����
#define DI_SPLOW             INPUT_TEMP[1] //�𶯿���ѹ����
#define DI_ESTOP             INPUT_TEMP[2] //��ͣ����


#if B_MODE
#define DI_RMT_IDLE          INPUT_TEMP[3]//���ٿ�������
#endif

#define DI_MODELOCK          INPUT_TEMP[3] //ģʽ��
#define DI_EXTERN_NOSTOP     INPUT_TEMP[4] //��ֹͣ��
#define DI_MODE_STOP         INPUT_TEMP[5] //��ģʽ
#define DI_MODE_REMOTE       INPUT_TEMP[6] //����ģʽ
#define DI_MODE_LOCAL        INPUT_TEMP[7] //�ֶ�ģʽ
#define DI_MODE_AUTO         INPUT_TEMP[8] //�Զ�ģʽ
#define DI_AUTOSTART_IN      INPUT_TEMP[9] //����
#define DI_WATERTEMP_H       INPUT_TEMP[10]//ˮ�¸�
#define DI_OILP_L            INPUT_TEMP[11]//��ѹ��
#define DI_LOWLEVEL          INPUT_TEMP[12]//��ˮλ��


#define DI_OILT_H            INPUT_TEMP[13]//���¸�
#define DI_FUEL_LEAK         INPUT_TEMP[14]//ȼ��й© 

#define DI_WPLOW             INPUT_TEMP[15]//��ˮѹ����

#define DI_COILTEMPHIGH      INPUT_TEMP[16]//�������

#define DI_DISABLE_AUTOSTART INPUT_TEMP[17]//��ֹ������
#define DI_BTN_START         INPUT_TEMP[18]//�𶯰���
#define DI_BTN_STOP          INPUT_TEMP[19]//ͣ������
#define DI_BTN_FAULTRESET    INPUT_TEMP[20]//���ϸ�λ
#define DI_BTN_HORNRESET     INPUT_TEMP[21]//��������λ 
//#define DI_BTN_RSTART        INPUT_TEMP[22]//Զ������
//#define DI_BTN_RSTOP         INPUT_TEMP[23]//Զ��ͣ��
#define DI_FUELLOW           INPUT_TEMP[22]
#define DI_GENLEAK           INPUT_TEMP[23]

#define DI_ENABLE_AUTOSTART  INPUT_TEMP[24]//����������
#define DI_SPRINGINPUT       INPUT_TEMP[25]//������
#define DI_COOLFANSTOP       INPUT_TEMP[26]//��ȴ���ȱ�������
#define DI_DPLUSFAULT        INPUT_TEMP[27]//������������



//�Զ������
#define DO_FUEL                      OUTPUT_TEMP[0] //����
#define DO_START                     OUTPUT_TEMP[1] //��
#define DO_IDLE                      OUTPUT_TEMP[2] //���� 
#define DO_STOP                      OUTPUT_TEMP[3] //ͣ��
#define DO_GCB                       OUTPUT_TEMP[4] //�����բ
#define DO_MCB                       OUTPUT_TEMP[5] //�е��բ
#define DO_BUZZER                    OUTPUT_TEMP[6] //������
#define DO_START_SUCCESS             OUTPUT_TEMP[7] //�𶯳ɹ�
#define DO_ALARMS_PRE                OUTPUT_TEMP[8] //Ԥ����
#define DO_ALARMS_STOP               OUTPUT_TEMP[9] //����ͣ��
#define DO_PRESTART                  OUTPUT_TEMP[10]//Ԥ�������
#define DO_GEN_RUNNING               OUTPUT_TEMP[11]//�������������
#define DO_MAIN_RUNNING              OUTPUT_TEMP[12]//�е���������
#define DO_READY                     OUTPUT_TEMP[13]//����׼��
#define DO_IDLE_REV                  OUTPUT_TEMP[14]//���յ���
#define DO_SPEED_UP                  OUTPUT_TEMP[15]//����
#define DO_SPEED_DOWN                OUTPUT_TEMP[16]//����
#define DO_MAIN_ALARM_VOLTAGE        OUTPUT_TEMP[17]//�����ѹ�쳣
#define DO_MAIN_ALARM_FREQ           OUTPUT_TEMP[18]//����Ƶ���쳣
#define DO_GEN_ALARM_OVERLOAD        OUTPUT_TEMP[19]//�������
#define DO_DES_ALARM_STOPFAULT       OUTPUT_TEMP[20]//ͣ��ʧ��
#define DO_DES_ALARM_OVERSPEED_PRE   OUTPUT_TEMP[21]//����Ԥ��
#define DO_DES_ALARM_OVERSPEED_ALA   OUTPUT_TEMP[22]//���ٱ���ͣ��
#define DO_OILTEMP_HIGH              OUTPUT_TEMP[23]//���¸߱���
#define DO_DES_BATT                  OUTPUT_TEMP[24]//��صͱ���
#define DO_DES_LOWOP_PRE             OUTPUT_TEMP[25]//����ѹԤ��
#define DO_DES_LOWOP_ALA             OUTPUT_TEMP[26]//����ѹ����
#define DO_DES_HIGHWT_PRE            OUTPUT_TEMP[27]//��ˮ��Ԥ��
#define DO_DES_HIGHWT_ALA            OUTPUT_TEMP[28]//��ˮ�±���
#define DO_DES_LOWOIL_PRE            OUTPUT_TEMP[29]//����λԤ��
#define DO_DES_LOWOIL_ALA            OUTPUT_TEMP[30]//����λ����
#define DO_COMMON_PRE                OUTPUT_TEMP[31]//����Ԥ��
#define DO_COMMON_ALA                OUTPUT_TEMP[32]//��������
#define DO_START_FAIL                OUTPUT_TEMP[33]//����ʧ��
#define DO_CHARGE                    OUTPUT_TEMP[34]//��翪�� 
#define DO_GCB_PULSEOFF              OUTPUT_TEMP[35]//�����բ�������
#define DO_MCB_PULSEOFF              OUTPUT_TEMP[36]//�е��բ�������
#define DO_GCB_PULSEON               OUTPUT_TEMP[37]//�����բ�������
#define DO_MCB_PULSEON               OUTPUT_TEMP[38]//�е��բ�������
#define DO_FUELPUMP                  OUTPUT_TEMP[39]//ȼ�ͱÿ���
#define DO_TEMPONOFF                 OUTPUT_TEMP[40]//�¶ȿ���
#define DO_SPEEDCHECK                OUTPUT_TEMP[41]//ͣ������           
#define DO_PREPARE_OK                OUTPUT_TEMP[42]//����
#define DO_FET_BATTCAP_ON            OUTPUT_TEMP[43]//��������Ϳ�
#define DO_PRELUB                    OUTPUT_TEMP[44]//����Ԥ�����
#define DO_LOCAL                     OUTPUT_TEMP[45]//�������
#define DO_AUTO                      OUTPUT_TEMP[46]//�Զ����
#define DO_REMOTE                    OUTPUT_TEMP[47]//ң�����
#define DO_ESTOP                     OUTPUT_TEMP[48]//��ͣ����


   


#define VOLTAGEAB1       MODBUS_DATA[6]  //�ͻ�AB�ߵ�ѹ
#define VOLTAGEBC1       MODBUS_DATA[7]  //�ͻ�BC�ߵ�ѹ
#define VOLTAGECA1       MODBUS_DATA[8]  //�ͻ�CA�ߵ�ѹ 
#define VOLTAGEA1        MODBUS_DATA[9]  //�ͻ�A���ѹ
#define VOLTAGEB1        MODBUS_DATA[10] //�ͻ�B���ѹ
#define VOLTAGEC1        MODBUS_DATA[11] //�ͻ�C���ѹ
#define CURRENTA         MODBUS_DATA[12] //�ͻ�A�����
#define CURRENTB         MODBUS_DATA[13] //�ͻ�B�����
#define CURRENTC         MODBUS_DATA[14] //�ͻ�C�����

#if B_MODE
#define EXPLODE_PRESSURE  MODBUS_DATA[0] 
#define EXHAUST_TEMP      MODBUS_DATA[1]
#define NO_STOP           MODBUS_DATA[2] //����/Ӧ��
#define START_STATE       MODBUS_DATA[3] //��״̬ 0:����� 1:�𶯼��
#define START_DEL_OUTPUT  MODBUS_DATA[4] //�����ʱ��
#define START_DEL_INT     MODBUS_DATA[5] //�𶯼��ʱ��
#define START_NUMS        MODBUS_DATA[6] //��ǰ�𶯴���
#define START_DEL_PRE     MODBUS_DATA[7] //Ԥ����ʱ��
#define GENVOLTAGE        MODBUS_DATA[8] //�������ѹ

#undef VOLTAGEAB1
#undef VOLTAGEBC1
#undef VOLTAGECA1

#undef VOLTAGEA1
#undef VOLTAGEB1
#undef VOLTAGEC1

#undef CURRENTA
#undef CURRENTB
#undef CURRENTC

#define VOLTAGEAB1       TMPDATA  //�ͻ�AB�ߵ�ѹ
#define VOLTAGEBC1       TMPDATA  //�ͻ�BC�ߵ�ѹ
#define VOLTAGECA1       TMPDATA  //�ͻ�CA�ߵ�ѹ 
#define VOLTAGEA1        TMPDATA  //�ͻ�A���ѹ
#define VOLTAGEB1        TMPDATA //�ͻ�B���ѹ
#define VOLTAGEC1        TMPDATA //�ͻ�C���ѹ
#define CURRENTA         TMPDATA //�ͻ�A�����
#define CURRENTB         TMPDATA //�ͻ�B�����
#define CURRENTC         TMPDATA //�ͻ�C�����

#endif



#define WATERTEMP        MODBUS_DATA[16] //ˮ��
#define CHASSISTEMP      MODBUS_DATA[16] //��ǻ�¶�
#define FUEL             MODBUS_DATA[17] //��λ
#define LOLEVEL          MODBUS_DATA[17] //����Һλ
#define OILPRESSURE      MODBUS_DATA[18] //��ѹ 
#define OILTEMP          MODBUS_DATA[19] //����       

#define PowerVoltage     MODBUS_DATA[20] //��ص�ѹ
#define ChargerVoltage   MODBUS_DATA[23]//TMPDATA//MODBUS_DATA[21] //������ѹ
#define PowerVoltage2    MODBUS_DATA[21]
#define DES_SPEED        MODBUS_DATA[22] //�ͻ�ת��
#define FUELCAP          MODBUS_DATA[24] //ȼ��������λ��

#define WTPRESSURE       MODBUS_DATA[25] //ˮѹ




#define COIL_U           MODBUS_DATA[26] //U�������¶�
#define COIL_V           MODBUS_DATA[27] //V�������¶�
#define COIL_W           MODBUS_DATA[28] //W�������¶�
#define BEARING_TEMP     MODBUS_DATA[29] //����¶�


#define KVAALL           MODBUS_DATA[29] //�ͻ������ڹ���
#define KVARALL          MODBUS_DATA[30]
#define KWA              MODBUS_DATA[31] //�ͻ�A���й�����
#define KWB              MODBUS_DATA[32] //�ͻ�B���й�����
#define KWC              MODBUS_DATA[33] //�ͻ�C���й����� 
#define KVARA            MODBUS_DATA[34] //�ͻ�A���޹�����
#define KVARB            MODBUS_DATA[35] //�ͻ�B���޹�����
#define KVARC            MODBUS_DATA[36] //�ͻ�C���޹����� 
#define KVAA             MODBUS_DATA[37] //�ͻ�A�����ڹ���
#define KVAB             MODBUS_DATA[38] //�ͻ�B�����ڹ���
#define KVAC             MODBUS_DATA[39] //�ͻ�C�����ڹ���
#define PFA              MODBUS_DATA[40] //A�๦������
#define PFB              MODBUS_DATA[41] //B�๦������
#define PFC              MODBUS_DATA[42] //C�๦������ 
#define FUEL_COST        MODBUS_DATA[43] //��ǰȼ��������
#define FUEL_RATE        MODBUS_DATA[44] //��ǰȼ��������
#define FUEL_L           MODBUS_DATA[45] //��ʼ���� 
#define KWHH             MODBUS_DATA[46] //ǧ��ʱ��λ
#define KWHL             MODBUS_DATA[47] //ǧ��ʱ��λ          
#define KVARHH           MODBUS_DATA[48] //ǧ��ʱ��λ
#define KVARHL           MODBUS_DATA[49] //ǧ��ʱ��λ 
//#define KVARH          MODBUS_DATA[50]
#define RUNNINGHOUR      MODBUS_DATA[50] //������ʱ
#define RUNNINGMINUTE    MODBUS_DATA[51] //�����۷�
#define RUNNINGTIME      MODBUS_DATA[52] //���д��� 
#define MAINTAIN         MODBUS_DATA[53]
#define ESTOPNUM         MODBUS_DATA[54]
#define STOPNUM          MODBUS_DATA[55]
#define GEN_PA           MODBUS_DATA[56] //��ѹA���
#define GEN_PB           MODBUS_DATA[57] //��ѹB���
#define GEN_PC           MODBUS_DATA[58] //��ѹC���
#define REC_DATA1        MODBUS_DATA[60]
#define REC_DATA2        MODBUS_DATA[61]
#define REC_DATA3        MODBUS_DATA[62]
#define REC_DATA4        MODBUS_DATA[63]
#define REC_DATA5        MODBUS_DATA[64]
#define REC_DATA6        MODBUS_DATA[65]
#define REC_DATA7        MODBUS_DATA[66]
#define REC_DATA8        MODBUS_DATA[67]
#define REC_DATA9        MODBUS_DATA[68]
#define REC_DATA10       MODBUS_DATA[69]
#define REC_DETAIL       &MODBUS_DATA[70]

#define DES_ALA_DATA1    MODBUS_DATA[101]
#define DES_ALA_DATA2    MODBUS_DATA[102]
#define GEN_ALA_DATA1    MODBUS_DATA[103]
#define MAIN_ALA_DATA1   MODBUS_DATA[104]
#define LIGHTSTATUS      MODBUS_DATA[105]
#define COMMON_STATUS    MODBUS_DATA[106]
#define COMMON_STATUS2   MODBUS_DATA[107]
#define INPUTVALUE       MODBUS_DATA[108] //����������
#define OUTPUTVALUE      MODBUS_DATA[109] //���������
#define ECUSTATUS        MODBUS_DATA[110] //ECU״̬ 
#define ECUSTATUS2       MODBUS_DATA[111] //ECU״̬2

#define ATMOP            MODBUS_DATA[112]
#define FUELOHM          MODBUS_DATA[113] //��λ����ֵ
#define FORCEINPUT       MODBUS_DATA[114] //ǿ������
#define FORCEBTN         MODBUS_DATA[115] //ģ�ⰴť
#define FORCEMODE        MODBUS_DATA[116] //ǿ��ģʽ

#define OILPRESSURE1     MODBUS_DATA[120] //@@@@@@@@@@@@@@@ZCȼ��ѹ��
#define VALUER1          MODBUS_DATA[121]
#define VALUER2          MODBUS_DATA[122]
#define OFFSETAOV        MODBUS_DATA[123]
#define OFFSETAOA        MODBUS_DATA[124]




//�����趨
#define SYS_PASSWORD                          Params[1]   //������������������
#define SYS_SET_DEFAULT_PARAM                 Params[2]   //�ָ�Ĭ������
#define GEN_RATING_POWER                      Params[3]   //����� 
#define DES_RATING_FUELCAP                    Params[4]   //�����
#define GEN_CURRENT_CT                        Params[5]   //�������������   
#define GEN_VOLTAGE_PT                        Params[6]   //��ѹ��������� 
#define SYS_D4D2MODE                          Params[7]
#define GEN_RATING_VOLTAGE                    Params[8]   //���ѹ 
#define GEN_RATING_VOLTAGELINE                Params[9]   //��ߵ�ѹ
#define GEN_RATING_FREQ                       Params[10]  //�Ƶ��       
#define DES_ROTATIONSCALE                     Params[11]  //���ֳ���                         
#define DES_RATING_ROTATION                   Params[12]  //�ת��                      

//#define BATTCAP_FULL                          Params[13]
#define MANSTART_MODE                         Params[13]  //0������ 1�ֶ���
#define WP_SHOW                               Params[14]  //ˮѹ��ʾ 
#define SYS_ADDR                              Params[15]  //������ͨѶ��ַ
#define EMER_MODE                             Params[16]
#define COMMTYPE                              Params[18]  //ͨѶģʽ0-MODBUS 1-����
#define SAFESYSTEM_COMMALARM                  Params[17]
#define GENVOLT_SHOW                          Params[19]
#define CHARGE_SHOW                           Params[20]

//����������
#define DES_START_SUCC_SPEED                  Params[21]  //���ѿ�ת�٣�%��    
#define DES_START_SUCC_OP                     Params[22]  //����ѹ                       
#define DES_START_DELAY                       Params[23]  //Ԥ����ʱ��                        
#define DES_START_PULSE                       Params[24]  //����������ʱ��                 
#define DES_START_INTEVAL                     Params[25]  //����ʧ�����Լ��               
#define DES_START_TIMES                       Params[26]  //�����������                     
#define DES_START_IDLE_DELAY                  Params[27]  //��������ʱ��                
#define DES_MIN_STABLETIME                    Params[28]  //����ȶ�ʱ��                   
#define DES_MAX_STABLETIME                    Params[29]  //��ȶ�ʱ��                 
#define DES_COOL_SPEED                        Params[30]  //ͣ����ȴ�ٶ�ѡ�� (�/����)     
#define DES_STOP_IDLE_DELAY                   Params[31]  //ͣ������ʱ�� 
#define DES_STOP_OUTPUT_PULSE                 Params[32]  //ͣ���������ʱ��          
#define DES_FUELTYPE                          Params[33]  //ȼ�Ϸ�
#define DES_D_SELECTION                       Params[34]  //D+ѡ�� 
#define DES_ECU_DES_D_SELECTION               Params[35]  //ECUƵ��ѡ��
#define DES_ECU_SPEED_ADJUST                  Params[36]  //ECU�ٶȵ���
//#if FEIERTE_MODE
#define FET_LOWCAP_ON                         Params[37]  //��������Ϳ�
#define FET_HICAP_OFF                         Params[38]  //��������߹�
#define DES_FUEL_ON                           Params[37]  //���ͱÿ�
#define DES_FUEL_OFF                          Params[38]  //���ͱù�
//#endif
#define DES_TEMP_ON                           Params[39]  //�¶ȿ�
#define DES_TEMP_OFF                          Params[40]  //�¶ȹ�
#define DES_DPLUS_SPEED                       Params[41]  //�䷢���ת����Ч
#define DES_DPLUS_VOLT                        Params[42]  //�䷢������ϵ�ѹ

//����������
#define DES_NOPROTECT_SEC                     Params[43]  //��ͣ����
#define DES_BUZZ_TIME                         Params[44]  //����ʱ��                     
#define DES_OVERSPEED_ALA                     Params[45]  //���ٱ���ͣ��                 
#define DES_AI1_PRE                           Params[46]  //AI1����
#define DES_AI1_ALA                           Params[47]  //AI1����
#define DES_AI1_DELAY                         Params[48]  //AI1��ʱ
#define DES_AI2_PRE                           Params[49]  //AI2����
#define DES_AI2_ALA                           Params[50]  //AI2����
#define DES_AI2_DELAY                         Params[51]  //AI2��ʱ
#define DES_AI3_PRE                           Params[52]  //AI3����
#define DES_AI3_ALA                           Params[53]  //AI3����
#define DES_AI3_DELAY                         Params[54]  //AI3��ʱ
#define DES_BATT_HIGH_ALA                     Params[55]  //��ص�ѹ�߱���               
#define DES_BATT_LOW_ALA                      Params[56]  //��ص�ѹ�ͱ���                 
#define DES_BATT_DELAY                        Params[57]  //��ص�ѹ�����ʱ
#define DES_WATERP_LOW                        Params[58]  //



//�Զ���������ʱ                                                           //����0=���� 1=����
#define IO_INPUT_DEL1                         Params[60]//����������1��ʱ
#define IO_INPUT_POL1                         Params[61]//����������1����  
#define IO_INPUT_DEL2                         Params[62]//����������1��ʱ
#define IO_INPUT_POL2                         Params[63]//����������1����
#define IO_INPUT_DEL3                         Params[64]//����������1��ʱ
#define IO_INPUT_POL3                         Params[65]//����������1����
#define IO_INPUT_DEL4                         Params[66]//����������1��ʱ
#define IO_INPUT_POL4                         Params[67]//����������1����
#define IO_INPUT_DEL5                         Params[68]//����������1��ʱ
#define IO_INPUT_POL5                         Params[69]//����������1����
#define IO_INPUT_DEL6                         Params[70]//����������1��ʱ
#define IO_INPUT_POL6                         Params[71]//����������1����
#define IO_INPUT_DEL7                         Params[72]//����������1��ʱ
#define IO_INPUT_POL7                         Params[73]//����������1����
#define IO_INPUT_DEL8                         Params[74]//����������1��ʱ
#define IO_INPUT_POL8                         Params[75]//����������1����
#define IO_INPUT_DEL9                         Params[76]//����������1��ʱ
#define IO_INPUT_POL9                         Params[77]//����������1����
#define IO_INPUT_DEL10                        Params[78]//����������1��ʱ
#define IO_INPUT_POL10                        Params[79]//����������1����
#define IO_INPUT_DEL11                        Params[80]//����������1��ʱ
#define IO_INPUT_POL11                        Params[81]//����������1����


#define AI_OP_SELECT                          Params[82]//��ѹͨ��ѡ��   0     +1
#define AI_WT_SELECT                          Params[83]//ˮ��ͨ��ѡ��   6     +1
#define AI_OT_SELECT                          Params[84]//����ͨ��ѡ��   5     +1
#define AI_BV1_SELECT                         Params[85]//�����1ͨ��ѡ�� 1    +1
#define AI_BV2_SELECT                         Params[86]//�����2ͨ��ѡ�� 2    +1
#define AI_LV_SELECT                          Params[87]//Һλͨ��ѡ��    5    +1
#define AI_GENVOLT_SELECT                     Params[88]//�����ͨ��ѡ��  3    +1
#define AI_USEPOWERVOLT                       Params[89]//�Ƿ�ʹ�ÿ�������Դ��ѹ 0:��ʹ�� 1��ʹ��
#define AI_USEONECHANNEL                      Params[90]//�Ƿ�ʹ�õ�·��ѹ 0��˫· 1����·
#define AI_WP_SELECT                          Params[91]//ˮѹͨ��ѡ��  7    +1

#define EXTERN_COILTEMP                       Params[92]//�����¶ȸ߱���
#define EXTERN_BEARINGTEMP                    Params[93]//����¶ȸ߱���

#define AI_OP_SELECT1                         Params[94]//ȼ��ѹ��ͨ��ѡ��   0     +1//@@@@@@@@@@@ZC
#define DES_SENSOR_OP1                        Params[95] //ȼ��ѹ��������ѡ��   //@@@@@@@ZC
#define OP_SHOW1                              Params[97] //ȼ��ѹ����ʾ         //@@@@@@@ZC
//ʱ������

#define HistoryTrig                           Params[106] //��ʷӡ��
#define WeekPeriod                            Params[107] //���ڼ��
#define FET_MAINTAINPERIOD                    Params[107]

#define FET_MAINTAINTIME                      Params[110]
#define FET_MAINTAINFUNC                      Params[111]

#define Timer1Func                            Params[110] //��ʱ��1����
#define Timer1Repeat                          Params[111] //��ʱ��1�ظ�
#define Timer1Start                           Params[112] //��ʱ��1��ʱ��
#define Timer1Value                           Params[113] //��ʱ��1�ڼ�
#define Timer2Func                            Params[114] //��ʱ��2����
#define Timer2Repeat                          Params[115] //��ʱ��2�ظ�
#define Timer2Start                           Params[116] //��ʱ��2��ʱ��
#define Timer2Value                           Params[117] //��ʱ��2�ڼ�


#define FET_INHIBIT_TIME_ON                   Params[118] //��ֹʱ�俪
#define FET_INHIBIT_TIME_OFF                  Params[119] //��ֹʱ���
#define FET_INHIBIT_DAY                       Params[120] //��ֹ����




//�Զ����������
#define IO_INPUT_CONFIG1                      Params[125] //�Զ�������1                                
#define IO_INPUT_CONFIG2                      Params[126] //�Զ�������2                                
#define IO_INPUT_CONFIG3                      Params[127] //�Զ�������3                                
#define IO_INPUT_CONFIG4                      Params[128] //�Զ�������4                                
#define IO_INPUT_CONFIG5                      Params[129] //�Զ�������5                                
#define IO_INPUT_CONFIG6                      Params[130] //�Զ�������6                                
#define IO_INPUT_CONFIG7                      Params[131] //�Զ�������7                                                                                                  
#define IO_OUTPUT_CONFIG1                     Params[132] //�Զ������1                               
#define IO_OUTPUT_CONFIG2                     Params[133] //�Զ������2                               
#define IO_OUTPUT_CONFIG3                     Params[134] //�Զ������3                               
#define IO_OUTPUT_CONFIG4                     Params[135] //�Զ������4                               
#define IO_OUTPUT_CONFIG5                     Params[136] //�Զ������5                               
#define IO_OUTPUT_CONFIG6                     Params[137] //�Զ������6                              
#define IO_OUTPUT_CONFIG7                     Params[138] //�Զ������7       


#if B_MODE
#define IO_INPUT_CONFIG8                      Params[160]
#define IO_INPUT_CONFIG9                      Params[161]
#define IO_INPUT_CONFIG10                     Params[162]
#define IO_INPUT_CONFIG11                     Params[163]

#define IO_OUTPUT_CONFIG8                     Params[164]
#define IO_OUTPUT_CONFIG9                     Params[165]
#define IO_OUTPUT_CONFIG10                    Params[166]
#define IO_OUTPUT_CONFIG11                    Params[167]
#define IO_OUTPUT_CONFIG12                    Params[168]
#define IO_OUTPUT_CONFIG13                    Params[169]
#define IO_OUTPUT_CONFIG14                    Params[170]

#define DES_SENSOR_EP                         Params[171]
#define DES_SENSOR_ET                         Params[172]


#endif

                        

//������ѡ��
#define DES_SENSOR_OP                         Params[139] //��ѹ������ѡ��                   
#define DES_SENSOR_WT                         Params[140] //ˮ�´�����ѡ��                   
#define DES_SENSOR_FUEL                       Params[141] //Һλ������ѡ��                   
#define DES_SENSOR_OT                         Params[142] //���´�����ѡ�� 

//У׼
#define ADJUSTR1                              Params[143] //����1У׼
#define ADJUSTR2                              Params[144] //����2У׼
#define ADJUSTR3                              Params[145] //����3У׼  
#define ELECADJUST1                           Params[146] //�����ѹAУ׼
#define ELECADJUST2                           Params[147] //�����ѹBУ׼
#define ELECADJUST3                           Params[148] //�����ѹCУ׼
#define ELECADJUST4                           Params[149] //�����ѹAУ׼
#define ELECADJUST5                           Params[150] //�����ѹBУ׼
#define ELECADJUST6                           Params[151] //�����ѹCУ׼
#define ELECADJUST7                           Params[152] //����AУ׼
#define ELECADJUST8                           Params[153] //����BУ׼
#define ELECADJUST9                           Params[154] //����CУ׼
#define BATTADJUST                            Params[155] //��ص�ѹУ׼
#define CHARGEADJUST                          Params[156] //����ѹУ׼  
#define GENVOLTADJUST                         Params[157] //�����ѹУ׼ 
#define MODESAVE                              Params[158] //ģʽ����    




#define RUNHOUR                               Params[PN_RUNHOUR] //����Сʱ
#define RUNMINUTE                             Params[181] //���з���
#define RUNTIME                               Params[182] //�𶯴���
#define EPROM_KWHH                            Params[183] //ǧ��ʱ��λ
#define EPROM_KWHL                            Params[184] //ǧ��ʱ��λ
#define EPROM_KVARHH                          Params[185] //ǧ��ʱ��λ
#define EPROM_KVARHL                          Params[186] //ǧ��ʱ��λ
#define EPROM_KWS                             Params[187] //ǧ����
#define EPROM_KVARS                           Params[188] //ǧ����
#define EP_KWH_STARTH                         Params[189] //��ʼ��ȸ�λ
#define EP_KWH_STARTL                         Params[190] //��ʼ��ȵ�λ
#define EP_KWS_START                          Params[191] //��ʼ���ǧ����

#define MaintainDays                          Params[192] //ά������    

//#define DEBUG_MODE                            Params[197] //RUNHOUR
#define EPROM_UNSUCSTARTS                     Params[198]
#define EPROM_ESTOP                           Params[198] //��ͣ����  
#define RECPOINT                              Params[199] //��¼ָ��          
#define REC_ALANUM                            Params[210]
#define REC_WINDOW                            &Params[219]
#define REC_POINTER                           Params[220]



#define ECU_PCLASS      Params[201]
#define ECU_PNUM        Params[202]
#define ECU_NOWDATA     Params[203]

#define TIMESET_SECOND  Params[204]
#define TIMESET_MINUTE  Params[205]
#define TIMESET_HOUR    Params[206]

#define TIMESET_DATE    Params[207]
#define TIMESET_MONTH   Params[208]
#define TIMESET_YEAR    Params[209]



#define PNUM_STAT                 200
#define PNUM_CANPNUM              201
#define PNUM_CANPDATA             202

#if FEIERTE_MODE
#define DEBUG_MODE                0
#define PN_RUNHOUR                197
#define PN_RUNMINUTE              181
#else
#define DEBUG_MODE                0
#define PN_RUNHOUR                180
#define PN_RUNMINUTE              181
#endif

#define PN_MAINTAINDAY            192


#define NOREPEAT 0
#define MON      1
#define TUE      2
#define WEN      3
#define THU      4
#define FRI      5
#define SAT      6
#define SUN      7
#define MON_FRI  8
#define MON_SAT  9
#define MON_SUN  10
#define SAT_SUN  11

/*---------------*/

#define CHN_AI1           0
#define CHN_AI2           1
#define CHN_AI3           2

#define CHN_GENV          3
#define CHN_BATTSETV      4
#define CHN_GENCURRENT    5
#define CHN_BATTCURRENT   6
//#define CHN_GENC3         7
#define CHN_BATT          8
#define CHN_CHARGE        9

/*---------------*/




#define TMR_DES_SPEED_HI_PRE      0
#define TMR_DES_SPEED_HI_ALA      1
#define TMR_DES_SPEED_LO          2
#define TMR_DES_AI1_PRE           3
#define TMR_DES_AI1_ALA           4
#define TMR_DES_AI2_PRE           5
#define TMR_DES_AI2_ALA           6
#define TMR_DES_AI3_PRE           7
#define TMR_DES_AI3_ALA           8
#define TMR_BATT_HIGH             9
#define TMR_BATT_LOW              10
#define TMR_MAX_STABLETIME        11
#define TMR_MIN_STABLETIME        12
#define TMR_STOP_DETECT_DELAY     13
#define TMR_STOP_OUTPUT_PULSE     14
#define TMR_STOP_DELAY            15
#define TMR_STOP_IDLE_DELAY       16
#define TMR_START_DELAY           17
#define TMR_START_IDLE_DELAY      18
#define TMR_START_INTEVAL         19
#define TMR_START_PULSE           20
#define TMR_DISABLEPROT           21
#define TMR_GCB_PULSE_ON          22
#define TMR_GCB_PULSE_OFF         23
#define TMR_DISABLE_SPEEDADJUST   24
#define TMR_SECOND                25
#define TMR_MINUTERUN             26
#define TMR_BUZZER                27
#define TMR_FUELLOW_STOP          28
#define TMR_FUELCHECK             29
#define TMR_OVERLOADSTOP          30
#define TMR_OVERCURRENTRETRY      31
#define TMR_SHORTRETRY            32
#define TMR_OVERCURRENTRECHECK    33
#define TMR_SHORTRECHECK          34
#define TMR_COILTEMP              35
#define TMR_TIMER1                36
#define TMR_TIMER2                37
#define TMR_DI_AUTOSTARTON        38
#define TMR_DI_AUTOSTARTOFF       39
#define TMR_SPRINGINPUT           40
#define TMR_OPERR                 41
#define TMR_WTERR                 42
#define TMR_OTERR                 43
#define TMR_SPEEDADJUST_DUTY      44
#define TMR_SPEEDADJUST_FREQ      45
#define TMR_WPLOW                 46//��ˮѹ����
#define TMR_SWPLOW                47//��ˮѹ����
#define TMR_FUELLOW               48//ȼ��λ��
#define TMR_SPLOW                 49//��ѹ����
#define TMR_SPEED_CHECK           50
#define TMR_RESET_DELAY           51
#define TMR_IDLE_RESET            52
#define TMR_SPEEDERR2             53
#define TMR_FUEL_LEAK             54
#define TMR_LOW_LEVEL             55//��ˮ��
#define TMR_GENLEAK               56//���ˮй©
#define TMR_COOLFAN               57
#define TMR_GEN_GCB_DELAY         58

#define TMR_DI1_DEL               59
#define TMR_DI2_DEL               60
#define TMR_DI3_DEL               61
#define TMR_DI4_DEL               62
#define TMR_DI5_DEL               63
#define TMR_DI6_DEL               64
#define TMR_DI7_DEL               65
#define TMR_DI8_DEL               66
#define TMR_DI9_DEL               67
#define TMR_DI10_DEL              68
#define TMR_DI11_DEL              69

#define TMR_WP_DEL                70
#define TMR_DPLUSFAIL             71
#define TMR_BATT_LOW2             72
#define TMR_BATT_HIGH2            73
#define TMR_EXCOILTEMP            74
#define TMR_EXBEARINGTEMP         75


#endif /*_DEFS_H*/
