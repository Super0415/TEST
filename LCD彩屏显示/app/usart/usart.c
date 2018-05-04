#include "usart.h"

#ifdef USE_RX_INTERRUPT   
    #include "system.h"    
#endif


void USART1_NVIC_RxConfig(void);

/****************************************************************************
* Function Name  : USART1_Config
* Description    : Configurates the USART1.
* Input          : baudRate��������
* Output         : None
* Return         : None
****************************************************************************/

void USART1_Config(uint16_t baudRate)
{
    uint16_t mantissa, fraction;
    float tmpreg;

    /* ���㲨���ʵ����ò�����Ĭ��ϵͳʱ��Ϊ72MHZ */
    tmpreg=(float)(72000000)/(baudRate * 16);//�õ�USARTDIV
	mantissa = tmpreg;				          //�õ���������
	fraction = (tmpreg - mantissa) * 16;     //�õ�С������	 
    mantissa <<= 4;
	mantissa += fraction;

	/* ��RCCʱ�� */
    RCC->APB2ENR |= 0x00000004 | 0x00004000;

    /* ����PA9������������� PA10�������� */
    GPIOA->CRH &= 0xFFFFF00F;
    GPIOA->CRH |= 0x000008B0;
    GPIOA->ODR |= 0x00000400;

    /* ��λ */
    RCC->APB2RSTR |= (uint32_t)0x01<<14;   //��λ����1
	RCC->APB2RSTR &= ~((uint32_t)0x01<<14);//ֹͣ��λ	   	   

    //����������
 	USART1->BRR = mantissa; // ����������	 
	USART1->CR1 |= 0x200C;  //1λֹͣ,��У��λ,���򿪷��ͺͽ���ʹ��

#ifdef USE_RX_INTERRUPT   
    USART1_NVIC_RxConfig();
#endif 		
}

/****************************************************************************
* Function Name  : USART1_SetWord
* Description    : ͨ������1�����ַ���.
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void USART1_SendWord(uint8_t *wd)
{	
	while(*wd)                      //����Ƿ��������Ƿ�Ϊ��
	{
        USART1->DR = *wd;
        while((USART1->SR & (uint16_t)0x0040) == 0);
		wd++;
	}		
}

/* ���Ҫʹ��printf�����Ļ�Ҫ������´��� */
/* ����ʹ�Target Options�����Targetλ��ѡ��Use MicroLIB */
#ifdef USE_PRINTF

#pragma import(__use_no_semihosting)             
/* ��׼����Ҫ��֧�ֺ��� */                 
struct __FILE 
{ 
	int handle; 
	/* Whatever you require here. If the only file you are using is */ 
	/* standard output using printf() for debugging, no file handling */ 
	/* is required. */ 
}; 
/* FILE is typedef�� d in stdio.h. */ 
FILE __stdout; 
/* ����_sys_exit()�Ա���ʹ�ð�����ģʽ */    
_sys_exit(int x) 
{ 
	x = x; 
}

/****************************************************************************
* Function Name  : fputc
* Description    : ʹ��printf����Ҫ�ض������fputc����.
* Input          : ch , *f
* Output         : None
* Return         : ch
****************************************************************************/
 
//int fputc(int ch, FILE *f)
//{
//	
//	USART_SendData(USART1, (uint8_t) ch);
//	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET);
//	
//	return ch;	
//}
//* �Ĵ����� */
int fputc(int ch, FILE *f)
{      
	while((USART1->SR & 0X40)==0);//ѭ������,ֱ���������   
	USART1->DR = (u8) ch;      
	return ch;
}

#endif

#ifdef USE_RX_INTERRUPT

/****************************************************************************
* Function Name  : USART1_NVIC_RxConfig
* Description    : ���ý����жϵ��жϵȼ����������ж�
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void USART1_NVIC_RxConfig(void)
{
    NVIC_Config(0, 0, USART1_IRQn);//�����ж����ȼ�
    USART1->CR1 |= 0x10;           //���ж�
}

/****************************************************************************
* Function Name  : USART1_IRQHandler
* Description    : ����1���жϺ���
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void USART1_IRQHandler (void)
{
    uint8_t dat;
    if(USART1->SR & 0x20)
    {
        dat = USART1->DR;
        USART1->DR = dat;
        while((USART1->SR & 0X40) == 0);
    }
}

#endif















