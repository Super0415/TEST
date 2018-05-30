#include "ao.h"



//************************************************************************************
//�������ƣ�  hrdao_init()
//����������  analog output init
//���������  none
//���������  none
//************************************************************************************
void hrdao_init(void)
{	
    PWME=0x0F;
    PWMPRCLK=0x44;
    PWMCTL=0x30;
    PWMPOL=0x0F;
    PWMPER01=0xFFFF;
    PWMPER23=0xFFFF;        
}

//************************************************************************************
//�������ƣ�  ao_output()
//����������  analog output
//���������  none
//���������  none
//************************************************************************************
void ao_output(void)
{
    if(AO1PERCENT>1000)
    {      
        AO1PERCENT=1000;
    }
    
    if(AO2PERCENT>1000)
    {      
        AO2PERCENT=1000;
    }
    
    PWMDTY01=(ulong)(AO1PERCENT)*0xFFFF/1000;
    PWMDTY23=(ulong)(AO2PERCENT)*0xFFFF/1000;
}