#include "key.h"
#include "system.h"
#include "usart.h"

/* �������� */
static void KEY_Delay10ms(void);

/****************************************************************************
* Function Name  : KEY_Config
* Description    : ��ʼ���������õ�IO��
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void KEY_Config(void)
{
	/*��GPIOE��ʱ��*/
	RCC->APB2ENR |= 0x00000040;
    
    /* ����PE2/PE3/PE4Ϊ�������� */
    GPIOE->CRL &= 0xFFF000FF;
    GPIOE->CRL |= 0x00088800;
    GPIOE->ODR |= (0x07 << 2); 
    	          
    /* ��GPIOA��ʱ�� */  
    RCC->APB2ENR |= 0x00000004;
    
    /* PA0Ϊ�������� */
    GPIOA->CRL &= 0xFFFFFFF0;
    GPIOA->CRL |= 0x00000008;
    GPIOA->ODR &= 0xFFFFFFFE;
}

/****************************************************************************
* Function Name  : KEY_NVIC_Config
* Description    : ��ʼ���ⲿ�ж�
* Input          : key��ѡ��ʹ���ⲿ�жϵİ���
* Output         : None
* Return         : None
****************************************************************************/

void KEY_NVIC_Config(uint8_t key)
{
    /* ��ʱ��ʹ�� */
    if(key & KEY_UP)
    {
        /* ��GPIOA��ʱ�� */  
        RCC->APB2ENR |= 0x00000004;
    }
    if(key & (KEY_DOWN | KEY_LEFT | KEY_RIGHT))
    {
        /*��GPIOE��ʱ��*/
	    RCC->APB2ENR |= 0x00000040;     
    }
    /*��AFIO��ʱ��*/
	RCC->APB2ENR |= 0x00000001;

    /* ����GPIO���� */    
    if(key & KEY_UP)
    {
        /* PA0Ϊ�������� */
        GPIOA->CRL &= 0xFFFFFFF0;
        GPIOA->CRL |= 0x00000008;
        GPIOA->ODR &= 0xFFFFFFFE;
    }
    if(key & (KEY_DOWN | KEY_LEFT | KEY_RIGHT))
    {
        if(key & KEY_LEFT)
        {
            /* ����PE2/PE3/PE4Ϊ�������� */
            GPIOE->CRL &= 0xFFFFF0FF;
            GPIOE->CRL |= 0x00000800;
            GPIOE->ODR |= (0x01 << 2);
        }
        if(key & KEY_DOWN)
        {
            /* ����PE2/PE3/PE4Ϊ�������� */
            GPIOE->CRL &= 0xFFFF0FFF;
            GPIOE->CRL |= 0x00008000;
            GPIOE->ODR |= (0x01 << 3);        
        }
        if(key & KEY_RIGHT)
        {
            /* ����PE2/PE3/PE4Ϊ�������� */
            GPIOE->CRL &= 0xFFF0FFFF;
            GPIOE->CRL |= 0x00080000;
            GPIOE->ODR |= (0x01 << 4);
        }
    }

/***************************************************************************/
/**************************** �ж����� *************************************/
/***************************************************************************/
    
    if(key & KEY_UP)
    {
        NVIC_Config(0, 0, EXTI0_IRQn);    
    }
    if(key & KEY_LEFT)
    {
        NVIC_Config(0, 0, EXTI2_IRQn); 
    }
    if(key & KEY_DOWN)
    {
        NVIC_Config(0, 0, EXTI3_IRQn); 
    }
    if(key & KEY_RIGHT)
    {
        NVIC_Config(0, 0, EXTI4_IRQn); 
    }

	/* ѡ��EXTI */
    if(key & KEY_UP)
    {
        /* ʹ��PA0������ */
        AFIO->EXTICR[0] &= 0xFFFFFFF0;
        AFIO->EXTICR[0] |= 0x00000000;
    }
    if(key & KEY_LEFT)
    {
        /* ʹ��PE2������ */
        AFIO->EXTICR[0] &= 0xFFFFF0FF;
        AFIO->EXTICR[0] |= 0x00000400;
    }
    if(key & KEY_DOWN)
    {
        /* ʹ��PE3������ */
        AFIO->EXTICR[0] &= 0xFFFF0FFF;
        AFIO->EXTICR[0] |= 0x00004000;
    }
    if(key & KEY_RIGHT)
    {
        /* ʹ��PE4������ */
        AFIO->EXTICR[1] &= 0xFFFFFFF0;
        AFIO->EXTICR[1] |= 0x00000004;
    }

    if(key & KEY_UP)
    {
        EXTI->IMR |= 0x00000001;  //�����ж�������0������ж�
        EXTI->FTSR &= 0xFFFFFFFE; //����½��ش���
        EXTI->RTSR |= 0x00000001; //���������ش���
	}
    if(key & (KEY_DOWN | KEY_LEFT | KEY_RIGHT))
    {
        if(key & KEY_LEFT)
        {
            EXTI->IMR |= (uint32_t)0x01 << 2;     //�����ж�������2������ж�
            EXTI->RTSR &= ~((uint32_t)0x01 << 2); //��������ش���
            EXTI->FTSR |= (uint32_t)0x01 << 2;    //�����½��ش���
        }
        if(key & KEY_DOWN)
        {
            EXTI->IMR |= (uint32_t)0x01 << 3;     //�����ж�������2������ж�
            EXTI->RTSR &= ~((uint32_t)0x01 << 3); //��������ش���
            EXTI->FTSR |= (uint32_t)0x01 << 3;    //�����½��ش���
        }
        if(key & KEY_RIGHT)
        {
            EXTI->IMR |= (uint32_t)0x01 << 4;     //�����ж�������2������ж�
            EXTI->RTSR &= ~((uint32_t)0x01 << 4); //��������ش���
            EXTI->FTSR |= (uint32_t)0x01 << 4;    //�����½��ش���
        }
    }
}

/****************************************************************************
* Function Name  : EXTI0_IRQHandler
* Description    : �ⲿ�ж�0���жϺ���
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void EXTI0_IRQHandler(void)
{
	if (EXTI->PR & 0x00000001)
	{
        printf(" KEY_UP�����жϣ�\n");
	}
    /* ����жϱ�־��д��1��� */
	EXTI->PR |= 0x00000001;
}



/****************************************************************************
* Function Name  : EXTI2_IRQHandler
* Description    : �ⲿ�ж�2���жϺ���
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void EXTI2_IRQHandler(void)
{
	if (EXTI->PR & (0x00000001 << 2))
	{
        printf(" KEY_LEFT�����жϣ�\n");
	}
	/* ����жϱ�־��д��1��� */
	EXTI->PR |= (0x00000001 << 2);
}

/****************************************************************************
* Function Name  : EXTI3_IRQHandler
* Description    : �ⲿ�ж�3���жϺ���
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void EXTI3_IRQHandler(void)
{
	if (EXTI->PR & (0x00000001 << 3))
	{
        printf(" KEY_DOWN�����жϣ�\n");
	}
	/* ����жϱ�־��д��1��� */
	EXTI->PR |= (0x00000001 << 3);
}

/****************************************************************************
* Function Name  : EXTI4_IRQHandler
* Description    : �ⲿ�ж�4���жϺ���
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void EXTI4_IRQHandler(void)
{
	if (EXTI->PR & (0x00000001 << 4))
	{
        printf(" KEY_RIGHT�����жϣ�\n");
	}
	/* ����жϱ�־��д��1��� */
	EXTI->PR |= (0x00000001 << 4);
}

/****************************************************************************
* Function Name  : KEY_Delay10ms
* Description    : ����ʹ�õ�������ʱ������ע�⣺����ʱ����������ʱʱ���ǲ�ȷ
*                * ���ģ�������ľ���ʱ10ms��Ҫ��ȷ��ʱ��ʹ�ö�ʱ����
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

static void KEY_Delay10ms(void)
{
    uint16_t i;
    for(i=0; i<0x5FFF; i++);
}

/****************************************************************************
* Function Name  : KEY_Scan
* Description    : ����ɨ�裬ע��ð���ɨ��֧��һ�ΰ�1��������֧��ͬʱ�������
* Input          : None
* Output         : None
* Return         : keyValue�������ļ�ֵ
****************************************************************************/

uint8_t KEY_Scan(void)
{
    uint8_t keyValue = 0, timeCount = 0;

    if((KEY0 == 1) || (KEY1 == 0) || (KEY2 == 0) || (KEY3 == 0)) //����Ƿ��а�������
    {
        KEY_Delay10ms();                                      //��ʱ����

        /* ������ĸ��������� */
        if(KEY0 == 1)
        {
            keyValue = KEY_UP;
        }
        else if(KEY1 == 0)
        {
            keyValue = KEY_LEFT;
        }
        else if(KEY2 == 0)
        {
            keyValue = KEY_DOWN;
        }
        else if(KEY3 == 0)
        {
            keyValue = KEY_RIGHT;
        }
        else
        {
            keyValue = 0;
        }
        
        /* �а�������ʱ�������ּ�� */
        if(keyValue != 0)
        {
            while(((KEY0 == 1) || (KEY1 == 0) || (KEY2 == 0) || (KEY3 == 0)) && (timeCount < 150))
            {
                KEY_Delay10ms();
                timeCount++;        
            }
//            KEY_Delay10ms();//�����������г�����٣�����ɨ����ٶ�̫�죬��һ�����������������   
        }        
    }

    return keyValue;
}












