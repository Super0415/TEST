#include "nixietube.h"

/*  ����ܴ�1~F��λ�� */
const uint8_t NixieTube_code[16] = {
0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

/****************************************************************************
* Function Name  : NIXIETUBE_Config
* Description    : ��ʼ������ܵ�IO��.
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void NIXIETUBE_Config(void)
{   
    /* ����GPIOC��GPIOFʱ�� */
    RCC->APB2ENR |= 0x00000010 | 0x00000080; 

    /* PC0~PC7����Ϊͨ�����������50MHZ�ٶ� */
    GPIOC->CRL &= 0x00000000;
    GPIOC->CRL |= 0x33333333;
    
    /* PF6~PF9����Ϊͨ�ÿ�©��� */
    GPIOF->CRL &= 0x00FFFFFF;
    GPIOF->CRL |= 0x77000000;
    GPIOF->CRH &= 0xFFFFFF00;
    GPIOF->CRH |= 0x00000077;
    
}

/****************************************************************************
* Function Name  : NIXIETUBE_Display
* Description    : �������ʾ4λ����
* Input          : *num���������ʾ����λ����ָ��
* Output         : None
* Return         : None
****************************************************************************/

void NIXIETUBE_Display(uint8_t *num)
{
    uint8_t st;

    /* ��ʼ��IO */
    NixieTube_1_SET;
    NixieTube_2_SET;
    NixieTube_3_SET;
    NixieTube_4_SET;

    /* ѡ��ʼ��ʾλ�����������ø�λΪ0ʱ����ʾ */
    if(num[3] != 0)
    {
        st = 4;    
    }
    else if(num[2] != 0)
    {
        st = 3;
    }
    else if(num[1] != 0)
    {
        st = 2;
    }
    else if(num[0] != 0)
    {
        st = 1;
    }
    else
    {
        st = 0;
    }

    /* ��ʼ��ʾ */
    switch (st)
    {
        case(4):   
            /* ��ʾ����λ����� */
            NixieTube(0x00);    //����
            NixieTube_4_CLR;
            NixieTube(NixieTube_code[num[3]]);
            NixieTube_4_SET;

        case(3):
            /* ��ʾ����λ����� */
            NixieTube(0x00);    //����
            NixieTube_3_CLR;
            NixieTube(NixieTube_code[num[2]]);
            NixieTube_3_SET;

        case(2):
            /* ��ʾ�ڶ�λ����� */
            NixieTube(0x00);    //����
            NixieTube_2_CLR;
            NixieTube(NixieTube_code[num[1]]);
            NixieTube_2_SET;

       case(1):    
            /* ��ʾ��һλ����� */
            NixieTube(0x00);    //����
            NixieTube_1_CLR;
            NixieTube(NixieTube_code[num[0]]);
            NixieTube_1_SET;

       default:
            break;       
    }      
}












