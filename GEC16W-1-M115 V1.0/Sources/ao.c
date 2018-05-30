#include "ao.h"



//************************************************************************************
//函数名称：  hrdao_init()
//功能描述：  analog output init
//输入参数：  none
//输出参数：  none
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
//函数名称：  ao_output()
//功能描述：  analog output
//输入参数：  none
//输出参数：  none
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