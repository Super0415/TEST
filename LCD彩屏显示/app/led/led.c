#include "led.h"


/****************************************************************************
* Function Name  : LED_Config
* Description    : ��LEDʹ�õ�IO������Ϊͨ���������
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void LED_Config(void)
{

	/*��GPIOC��ʱ��*/
	RCC->APB2ENR |= 0x00000010;

    /* ����GPIOC�ĵ�8λΪͨ��������� */
    GPIOC->CRL = 0x33333333;
    
    /* ��ʼ��ΪIo�� */
    GPIOC->ODR |= 0xFFFF; 
}

/****************************************************************************
* Function Name  : LED_SetState
* Description    : ����LED��״̬��0������Ӧ��LED������1��ʾ��Ӧ��LEDϨ��
* Input          : stateValue��LED��״̬
* Output         : None
* Return         : None
****************************************************************************/

void LED_SetState(uint8_t stateValue)
{    
    /* ����LED�Ƶ�״̬, GPIOһ������16λ������ֵǿ��ת��λ16λ */
    GPIOC->BSRR = (uint16_t)stateValue & 0x00FF;
    GPIOC->BRR =  ~((uint16_t)stateValue & 0x00FF);                  
}



