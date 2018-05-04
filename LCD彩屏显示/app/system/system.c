#include "system.h"

#ifdef USE_UCOSII_OS
#include "os_includes.h"
#endif

/****************************************************************************
* Function Name  : RCC_Reset
* Description    : ��λRCCʱ��
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

static void RCC_Reset(void)
{
  /* Set HSION bit */
  RCC->CR |= (uint32_t)0x00000001;

  /* Reset SW, HPRE, PPRE1, PPRE2, ADCPRE and MCO bits */
  RCC->CFGR &= (uint32_t)0xF0FF0000;
  
  /* Reset HSEON, CSSON and PLLON bits */
  RCC->CR &= (uint32_t)0xFEF6FFFF;

  /* Reset HSEBYP bit */
  RCC->CR &= (uint32_t)0xFFFBFFFF;

  /* Reset PLLSRC, PLLXTPRE, PLLMUL and USBPRE/OTGFSPRE bits */
  RCC->CFGR &= (uint32_t)0xFF80FFFF;

  /* Disable all interrupts and clear pending bits  */
  RCC->CIR = 0x009F0000;

}
/****************************************************************************
* Function Name  : SYSTEM_SetClock
* Description    : �����ⲿʱ����ΪPLL���룬��������Ӧ��ʱ��Ƶ�ʡ�ע��ʱ��Ƶ��
*                * Ҫ��8�ı������ú���ֻ�ṩ32MHZ��72MHZ�����á�
* Input          : freq��Ƶ�ʲ������ò���ֻ������Ϊ8�ı�������4����9����
* Output         : None
* Return         : 0xFF����ʾ����ʧ�ܣ�ʱ�ӷ��س�ʼ��״̬
*                * 0����ʾ��ʼ���ɹ�
****************************************************************************/

uint8_t SYSTEM_SetClock(uint8_t freq)
{
	uint32_t rccCrHserdy = 0;
	uint32_t faultTime = 0, RCC_CFGR_PLL;

    /* ѡ��Ƶϵ�� */
    switch(freq)
    {
        case(32):
            RCC_CFGR_PLL = RCC_CFGR_PLLMULL4;
            break;
        case(40):
            RCC_CFGR_PLL = RCC_CFGR_PLLMULL5;
            break;
        case(48):
            RCC_CFGR_PLL = RCC_CFGR_PLLMULL6;
            break;
        case(56):
            RCC_CFGR_PLL = RCC_CFGR_PLLMULL7;
            break;
        case(64):
            RCC_CFGR_PLL = RCC_CFGR_PLLMULL8;
            break;
        case(72):
            RCC_CFGR_PLL = RCC_CFGR_PLLMULL9;
            break;
        default:
            return 0xFF;
    }

	/*��λRCC_CR�Ĵ���*/
	RCC_Reset();

	/*�����ⲿʱ��*/
	RCC->CR &= (~RCC_CR_HSEON);
	RCC->CR |= RCC_CR_HSEON;//���õ�16λ

	/*����ⲿʱ�ӿ����ɹ�*/
	do
	{
		rccCrHserdy = RCC->CR & RCC_CR_HSERDY;//����17λ�Ƿ�Ϊ1
		faultTime++;//���ʱ��
	}
	while ((faultTime<0x0FFFFFFF) && (rccCrHserdy==0));
	/* ����ⲿʱ�ӿ����ɹ�*/
	if ((RCC->CR & RCC_CR_HSERDY) != 0)
	{
		/* Enable Prefetch Buffer */
	    FLASH->ACR |= FLASH_ACR_PRFTBE;

	    /* Flash 2 wait state */
	    FLASH->ACR &= (~(uint32_t)FLASH_ACR_LATENCY);
	    FLASH->ACR |= (uint32_t) FLASH_ACR_LATENCY_2;  

		/*AHB��0000����APB2��000������Ƶ����PLL���ʱ�ӣ�*/
		/*APB1��100��Ҫ2��Ƶ�������ֻ��36MHZ��*/
		RCC->CFGR &= (~(RCC_CFGR_HPRE | RCC_CFGR_PPRE1 | RCC_CFGR_PPRE2));
		RCC->CFGR |= (RCC_CFGR_HPRE_DIV1 | RCC_CFGR_PPRE1_DIV2
		              | RCC_CFGR_PPRE2_DIV1);

		/*����HSEΪ����ʱ�ӣ�ͬ��HSE����Ƶ*/
		RCC->CFGR &= (~(uint32_t)(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE ));
		RCC->CFGR |= (RCC_CFGR_PLLSRC);

		/*����PLL��Ƶϵ��Ϊ9��*/
		RCC->CFGR &= (~RCC_CFGR_PLLMULL);//�����ԭ��������
		RCC->CFGR |= (RCC_CFGR_PLL);//���ñ�Ƶϵ��

		/*��PLLʹ��*/
		RCC->CR |= RCC_CR_PLLON;

		/*�ȴ�����PLL�����ɹ�*/
		while ((RCC->CR & RCC_CR_PLLRDY) == 0)
		{
		}

		/*��PLL��ΪSYSCLK��ʱ����Դ*/
		RCC->CFGR &= (~RCC_CFGR_SW);//�������ǰ������
		RCC->CFGR |= RCC_CFGR_SW_PLL;

		/*�ȴ�PLL��ΪSYSCLKʱ�������ɹ�*/
		while ((RCC->CFGR & RCC_CFGR_SWS) != (uint32_t)RCC_CFGR_SWS_PLL)
		{
		}
	}/*end of if((RCC->CR & RCC_CR_HSERDY) != 0)*/
	/*����ⲿʱ�ӿ���ʧ��*/
	else
	{
	    RCC_Reset();
        return 0xFF;
	}

    return 0;	
}

/****************************************************************************
* Function Name  : NVIC_PriorityGroupConfig
* Description    : ����NVIC�ж�ϵͳ��ռ���Ⱥʹ����ȵ����ã�ע:������Ϊ3λ��ռ
*                * ���ȣ�1λ�����ȡ���
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void NVIC_SetPriorityGroup(uint8_t group)
{
    uint32_t reg;

    /* ���ֻ����λ���� */
    reg = (~(uint32_t)group) & 0x00000007;
    reg <<= 8;
    /* Set the PRIGROUP[10:8] bits according to NVIC_PriorityGroup value */
    /* 0x05FA0000�Ƿ���Կ�ף�group�Ƿ������� */
    SCB->AIRCR = 0x05FA0000 | reg;
    
}

/****************************************************************************
* Function Name  : NVIC_Config
* Description    : ������ӦNVIC���ж����ȼ�.
* Input          : preemptionPriority����ռ���ȼ���
*                * subPriority�������ȼ���
*                * Channel�����õ��ж�ͨ��
* Output         : None
* Return         : None
****************************************************************************/

void NVIC_Config(uint8_t preemptionPriority,uint8_t subPriority,uint8_t Channel)
{
    uint32_t tmppriority = 0x00, tmppre = 0x00, tmpsub = 0x0F;

    /* Compute the Corresponding IRQ Priority --------------------------------*/
    /* ��ȡNVIC�������� */    
    tmppriority = (0x700 - ((SCB->AIRCR) & (uint32_t)0x700))>> 0x08;
    tmppre = (0x4 - tmppriority);
    tmpsub = tmpsub >> tmppriority;

    /* �����ж����ȼ� */
    tmppriority = (uint32_t)preemptionPriority << tmppre;
    tmppriority |=  subPriority & tmpsub;
    tmppriority = tmppriority << 0x04;
        
    NVIC->IP[Channel] = tmppriority;
    
    /* ʹ����Ӧ���ж� */
    /* Enable the Selected IRQ Channels --------------------------------------*/
    NVIC->ISER[Channel >> 0x05] = (uint32_t)0x01 << (Channel & (uint8_t)0x1F);
}

#ifndef USE_UCOSII_OS
/****************************************************************************
* Function Name  : SYSTICK_Init
* Description    : ��ʼϵͳ�δ�ʱ���������ö�ʱʱ�䡣
*                * �����жϺ�����stm32f10x_it.c��139�С�
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void SYSTICK_Config(void)
{
    /* ʱ����72MHZʱ�����Լ���72��(���Ϊ16777215)������1us */
	/* ��Ҫ��Ϊ������ʱ�� */
	if(SysTick_Config(72) == 0)//�����ɹ�����0
	{
		/* ����������ú�����ʱ��Ĭ����ֱ�Ӵ򿪼������ģ����ڰ����ص��� */
		/* �ر��ж� */	
		 SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk);		 	
	}    
}

/****************************************************************************
* Function Name  : SYSTICK_Delay1us
* Description    : ��ʱ������
* Input          : us����ʱ��ʱ��
* Output         : None
* Return         : None
****************************************************************************/

void SYSTICK_Delay1us(uint16_t us)
{
	uint32_t countValue;

	SysTick->LOAD  = (us * 72) - 1;             //������װ��ֵ, 72MHZʱ
	SysTick->VAL   = 0;	                        //���������
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;	//�򿪼�ʱ��

	do
	{
		countValue = SysTick->CTRL; 	
	}
	while(!(countValue & (1 << 16)));			//�ȴ�ʱ�䵽��

	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;	//�رռ�����	
}

/****************************************************************************
* Function Name  : SYSTICK_Delay1ms
* Description    : ��ʱ������
* Input          : ms����ʱ��ʱ��
* Output         : None
* Return         : None
****************************************************************************/

void SYSTICK_Delay1ms(uint16_t ms)
{
	uint32_t countValue;

	SysTick->LOAD  = 72000 - 1;                 //������װ��ֵ, 72MHZʱ��ʱ1ms
	SysTick->VAL   = 0;	                        //���������
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;	//�򿪼�ʱ��

	do
	{
		countValue = SysTick->CTRL;
		if(countValue & (1 << 16))              //����1ms�Ǽ�����1
		{
			ms--;
		} 	
	}
	while(ms);			                        //�ȴ�ʱ�䵽��

	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;	//�رռ�����	
}

/****************************************************************************
* Function Name  : SYSTICK_Delay1s
* Description    : ��ʱ������
* Input          : s����ʱ��ʱ��
* Output         : None
* Return         : None
****************************************************************************/

void SYSTICK_Delay1s(uint16_t s)
{
	uint32_t countValue;

	s *= 5; 
	SysTick->LOAD  = 72000 * 200 - 1;           //������װ��ֵ, 72MHZʱ��ʱ200ms
	SysTick->VAL   = 0;	                        //���������
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;	//�򿪼�ʱ��

	do
	{
		countValue = SysTick->CTRL;
		if(countValue & (1 << 16))              //����200ms�Ǽ�����1
		{
			s--;
		} 	
	}
	while(s);			                        //�ȴ�ʱ�䵽��

	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;	//�رռ�����	
}

#else


/****************************************************************************
* Function Name  : SYSTICK_Delay1us
* Description    : ��ʱ������
* Input          : us����ʱ��ʱ��
* Output         : None
* Return         : None
****************************************************************************/

void SYSTICK_Delay1us(uint16_t us)
{
    uint32_t oldValue, newValue, ticks, reloadValue, countValue = 0;

    /* ��ȡ��װֵ */
    reloadValue = SysTick->LOAD;
    
    /* ������ʱ��Ҫ���ٸ��δ��������õ���ʱ����ʱ��Ϊ72MHZ�Ļ��������õ� */
    ticks = us * 72;

    oldValue = SysTick->VAL;  //�ս���ʱ�ļ�����ֵ
    while(1)
    {
        newValue = SysTick->VAL;
        if(newValue != oldValue)
        {
            if(newValue < oldValue)    //�δ�������ǵ���������
            {
                countValue += oldValue - newValue;
            }
            else
            {
                countValue += reloadValue - newValue + oldValue;
            }
            if(countValue >= ticks)
            {
                break;
            }    
        }
    }   	
}

/****************************************************************************
* Function Name  : SYSTICK_Delay1ms
* Description    : ��ʱ������
* Input          : ms����ʱ��ʱ��
* Output         : None
* Return         : None
****************************************************************************/

void SYSTICK_Delay1ms(uint16_t ms)
{
    if(OSRunning != 0)
    {
        OSTimeDlyHMSM(0, 0, 0, ms); 
    }
    else
    {
        while(ms--)
        {
            SYSTICK_Delay1us(1000);    
        }    
    }   	
}

/****************************************************************************
* Function Name  : SYSTICK_Delay1s
* Description    : ��ʱ������
* Input          : s����ʱ��ʱ��
* Output         : None
* Return         : None
****************************************************************************/

void SYSTICK_Delay1s(uint16_t s)
{
    OSTimeDlyHMSM(0, 0, s, 0);    	
}

#endif

