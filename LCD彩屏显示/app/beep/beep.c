#include "beep.h"
#include "system.h"

/****************************************************************************
* Function Name  : BEEP_Config
* Description    : ��ʼ����������IO����
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void BEEP_Config(void)
{
    /*��GPIOB��ʱ��*/
    RCC->APB2ENR |= 0x00000008;
    
    /* ����GPIOC�ĵ�8λΪͨ��������� */
    GPIOB->CRL &= 0xFF0FFFFF;
    GPIOB->CRL |= 0x00300000;	                       
}

/****************************************************************************
* Function Name  : BEEP_Work
* Description    : ���������һ��
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void BEEP_Work(void)
{
    uint16_t i;
    uint8_t j;

    for(j=0; j<50; j++)           //����һ��ʱ���PWM����ʹ������������һ��
    {
        PBout(5) = 1;             //ͨ�����Ƕ����λ���������PB5������ߵ�ƽ
        for(i=0; i<4500; i++);    //��ʱ����PWM��Ƶ��
        PBout(5) = 0; 
        for(i=0; i<4500; i++);   
    }
}

