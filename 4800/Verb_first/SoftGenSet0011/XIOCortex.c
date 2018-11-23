/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File XIOCortex.c                        */
/*                            By: Wu Xuekui                             */
/*                             2014-10-14                               */
/* ******************************************************************** */

#define   XIO_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                              XIOInit()    初始化                     */
/* ******************************************************************** */
void XIOInit (void)
{   usXIOTimer = 0;
    usXIOStatus = 0;
    usXIOCalcTime = 0;
    usXIOAdcChEff0 = 0;
    usXIOAdcChEff1 = 0;
    usXIOAdcChEff2 = 0;
    usXIOAdcChEff3 = 0;
    usXIOAdcChEff4 = 0;
    usXIOAdcChEff5 = 0;
    usXIOAdcChEff6 = 0;
    usXIOAdcChEff7 = 0;
    usXIOAdcChEff8 = 0;
    usXIOAdcChEff03 = 0;
    usXIOAdcChEff06 = 0;
    usXIOAdcChEff36 = 0;
    usXIOAdcChEff14 = 0;
    usXIOAdcChEff17 = 0;
    usXIOAdcChEff47 = 0;
    usXIOAdcChEffGd = 0;
    siXIOCrossMac12 = 0;
    siXIOCrossMac45 = 0;
    siXIOCrossMac78 = 0;
    usXIOHardFreqMainA = 0;
    usXIOSoftFreqMainA = 0;
    usXIOSoftFreqMainB = 0;
    usXIOSoftFreqMainC = 0;
    usXIOHardFreqGensA = 0;
    usXIOSoftFreqGensA = 0;
    usXIOSoftFreqGensB = 0;
    usXIOSoftFreqGensC = 0;
    uiXIOActivePrdMain = 0;
    uiXIOHardPrdMainA = 0;
    uiXIOSoftPrdMainA = 0;
    uiXIOSoftPrdMainB = 0;
    uiXIOSoftPrdMainC = 0;
    uiXIOActivePrdGens = 0;
    uiXIOHardPrdGensA = 0;
    uiXIOSoftPrdGensA = 0;
    uiXIOSoftPrdGensB = 0;
    uiXIOSoftPrdGensC = 0;
    ssXIOSoftPhsDiffer = 0;
    ssXIOHardPhsDiffer = 0;
    usXIOMainSmpSiz = XIO_ADC_SMPL_SIZ;
    usXIOGensSmpSiz = XIO_ADC_SMPL_SIZ;
    pXIOAdcDmaBuf   = &usXIOAdcDmaBuf0[0];  //DMA读取ADC数据地址
    pXIOFftDatBuf   = &ssXIOAdcChDat0[0];
    usXIOAdcChRef0  =  usDBpAdcChRef0;     //固定基准值
    usXIOAdcChRef1  =  usDBpAdcChRef1;
    usXIOAdcChRef2  =  usDBpAdcChRef2;
    usXIOAdcChRef3  =  usDBpAdcChRef3;
    usXIOAdcChRef4  =  usDBpAdcChRef4;
    usXIOAdcChRef5  =  usDBpAdcChRef5;
    usXIOAdcChRef6  =  usDBpAdcChRef6;
    usXIOAdcChRef7  =  usDBpAdcChRef7;
    usXIOAdcChRef8  =  usDBpAdcChRef8;
                              //固定基准值   *  滤波点数
    uiXIOAdcRefSum0 = (INT32U)usXIOAdcChRef0 * XIO_ADC_REF_FILTER;
    uiXIOAdcRefSum1 = (INT32U)usXIOAdcChRef1 * XIO_ADC_REF_FILTER;
    uiXIOAdcRefSum2 = (INT32U)usXIOAdcChRef2 * XIO_ADC_REF_FILTER;
    uiXIOAdcRefSum3 = (INT32U)usXIOAdcChRef3 * XIO_ADC_REF_FILTER;
    uiXIOAdcRefSum4 = (INT32U)usXIOAdcChRef4 * XIO_ADC_REF_FILTER;
    uiXIOAdcRefSum5 = (INT32U)usXIOAdcChRef5 * XIO_ADC_REF_FILTER;
    uiXIOAdcRefSum6 = (INT32U)usXIOAdcChRef6 * XIO_ADC_REF_FILTER;
    uiXIOAdcRefSum7 = (INT32U)usXIOAdcChRef7 * XIO_ADC_REF_FILTER;
    uiXIOAdcRefSum8 = (INT32U)usXIOAdcChRef8 * XIO_ADC_REF_FILTER;
    SFIirFilterInit(&sXIOIirFilter0, usDBpAdcChFilter0);
    SFIirFilterInit(&sXIOIirFilter1, usDBpAdcChFilter1);
    SFIirFilterInit(&sXIOIirFilter2, usDBpAdcChFilter2);
    SFIirFilterInit(&sXIOIirFilter3, usDBpAdcChFilter3);
    SFIirFilterInit(&sXIOIirFilter4, usDBpAdcChFilter4);
    SFIirFilterInit(&sXIOIirFilter5, usDBpAdcChFilter5);
    SFIirFilterInit(&sXIOIirFilter6, usDBpAdcChFilter6);
    SFIirFilterInit(&sXIOIirFilter7, usDBpAdcChFilter7);
    SFIirFilterInit(&sXIOIirFilter8, usDBpAdcChFilter8);
    SFZeroCrossInit(&sXIOZeroCross0);
    SFZeroCrossInit(&sXIOZeroCross1);
    SFZeroCrossInit(&sXIOZeroCross2);
    SFZeroCrossInit(&sXIOZeroCross3);
    SFZeroCrossInit(&sXIOZeroCross4);
    SFZeroCrossInit(&sXIOZeroCross5);
    SFZeroCrossInit(&sXIOZeroCross6);
    SFZeroCrossInit(&sXIOZeroCross7);
    SFZeroCrossInit(&sXIOZeroCross8);
    SFHardPrdInit(&sXIOHardPeriod0);
    SFHardPrdInit(&sXIOHardPeriod1);
    SFSpdPulseInit(&sXIOSpdPulse0, usDBpTeethCrank1, usDBpSpeedFilter1);
    SFSpdPulseInit(&sXIOSpdPulse1, usDBpTeethCrank2, usDBpSpeedFilter2);
    (void)XIOResetGPIO(GPIOA);  //复位GPIOA
    (void)XIOResetGPIO(GPIOB);  //复位GPIOB
    (void)XIOResetGPIO(GPIOC);  //复位GPIOC
    (void)XIOResetGPIO(GPIOD);  //复位GPIOD
    (void)XIOResetGPIO(GPIOE);  //复位GPIOE
    (void)XIOInitDigInput();  //开关量输入初始化
    (void)XIOInitDigOutput();
    (void)XIOInitPwmOutput();
    (void)XIOInitADC1();      //ADC1初始化
    (void)XIOInitDma1Ch1Adc();
    (void)XIOInitTim1();
    (void)XIOInitTim2();
    (void)XIOInitTim2HardPrdIn();
    (void)XIOInitTim3();
    (void)XIOInitTim3SpeedIn();
    (void)XIOInitTim4();
    (void)XIOInitTim4Pwm();
    (void)CTLInit();
}

/* ******************************************************************** */
/*                              XIOStart()     任务循环前               */
/* ******************************************************************** */
void XIOStart (void)
{   (void)XIOInitTim1AdcTriger();
    (void)FWIrqEnable(DMA1_Channel1_IRQn, 0);
    (void)FWIrqEnable(TIM2_IRQn, 0);
}

/* ******************************************************************** */
/*                            XIOTaskLoop()      任务循环               */
/* ******************************************************************** */
int TESTZCADC[20];
void XIOTaskLoop (void)
{   INT16U usBeg, usSiz, usTim;
  //  (void)FWWatchdogInit();  //初始化看门狗
    while (1)
    {   (void)OSTaskSuspend(OS_PRIO_SELF);
  //      (void)FWWatchdogFeed();  //喂狗
        usTim = XIO_GET_FREE_TIMER();                                                   //读取计时器寄存器数值
        /* ************************************************************ */
        /*                     Read Analog Input 获取AD值数据           */
        /* ************************************************************ */
        (void)XIOGetAdcChanDat(pXIOAdcDmaBuf);  
        /* ************************************************************ */
        /*                    Get Channel Average 取其平均值过滤AD值    */
        /* ************************************************************ */
        usDBmAdcInput0  = SFGetAve16s(ssXIOAdcChDat0, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput1  = SFGetAve16s(ssXIOAdcChDat1, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput2  = SFGetAve16s(ssXIOAdcChDat2, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput3  = SFGetAve16s(ssXIOAdcChDat3, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput4  = SFGetAve16s(ssXIOAdcChDat4, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput5  = SFGetAve16s(ssXIOAdcChDat5, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput6  = SFGetAve16s(ssXIOAdcChDat6, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput7  = SFGetAve16s(ssXIOAdcChDat7, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput8  = SFGetAve16s(ssXIOAdcChDat8, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput9  = SFGetAve16s(ssXIOAdcChDat9, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput10 = SFGetAve16s(ssXIOAdcChDat10,XIO_ADC_SMPL_SIZ);
        usDBmAdcInput11 = SFGetAve16s(ssXIOAdcChDat11,XIO_ADC_SMPL_SIZ);//油压采集
        usDBmAdcInput12 = SFGetAve16s(ssXIOAdcChDat12,XIO_ADC_SMPL_SIZ);
        usDBmAdcInput13 = SFGetAve16s(ssXIOAdcChDat13,XIO_ADC_SMPL_SIZ);
        usDBmAdcInput14 = SFGetAve16s(ssXIOAdcChDat14,XIO_ADC_SMPL_SIZ);
        usDBmAdcInput15 = SFGetAve16s(ssXIOAdcChDat15,XIO_ADC_SMPL_SIZ);
        TESTZCADC[0] = usDBmAdcInput0;
        TESTZCADC[1] = usDBmAdcInput1;
        TESTZCADC[2] = usDBmAdcInput2;
        TESTZCADC[3] = usDBmAdcInput3;
        TESTZCADC[4] = usDBmAdcInput4;
        TESTZCADC[5] = usDBmAdcInput5;
        TESTZCADC[6] = usDBmAdcInput6;
        TESTZCADC[7] = usDBmAdcInput7;
        TESTZCADC[8] = usDBmAdcInput8;
        TESTZCADC[9] = usDBmAdcInput9;
        TESTZCADC[10] = usDBmAdcInput10;
        TESTZCADC[11] = usDBmAdcInput11;
        TESTZCADC[12] = usDBmAdcInput12;
        TESTZCADC[13] = usDBmAdcInput13;
        TESTZCADC[14] = usDBmAdcInput14;
        TESTZCADC[15] = usDBmAdcInput15;
        /* ************************************************************ */
        /*                    Get Channel Reference                     */
        /* ************************************************************ */
        if (usDBpAdcRefAutoOrFixed != 0)
        {
            usXIOAdcChRef0 = SFGetAdcRef16u(usDBmAdcInput0, &uiXIOAdcRefSum0);
            usXIOAdcChRef1 = SFGetAdcRef16u(usDBmAdcInput1, &uiXIOAdcRefSum1);
            usXIOAdcChRef2 = SFGetAdcRef16u(usDBmAdcInput2, &uiXIOAdcRefSum2);
            usXIOAdcChRef3 = SFGetAdcRef16u(usDBmAdcInput3, &uiXIOAdcRefSum3);
            usXIOAdcChRef4 = SFGetAdcRef16u(usDBmAdcInput4, &uiXIOAdcRefSum4);
            usXIOAdcChRef5 = SFGetAdcRef16u(usDBmAdcInput5, &uiXIOAdcRefSum5);
            usXIOAdcChRef6 = SFGetAdcRef16u(usDBmAdcInput6, &uiXIOAdcRefSum6);
            usXIOAdcChRef7 = SFGetAdcRef16u(usDBmAdcInput7, &uiXIOAdcRefSum7);
            usXIOAdcChRef8 = SFGetAdcRef16u(usDBmAdcInput8, &uiXIOAdcRefSum8);
        }
        /* ************************************************************ */
        /*                      Data Sub Reference                      */
        /* ************************************************************ */ 
        SFSubRef16s(ssXIOAdcChDat0, usXIOAdcChRef0, XIO_ADC_SMPL_SIZ);  //ADC采集数据
        SFSubRef16s(ssXIOAdcChDat1, usXIOAdcChRef1, XIO_ADC_SMPL_SIZ);
        SFSubRef16s(ssXIOAdcChDat2, usXIOAdcChRef2, XIO_ADC_SMPL_SIZ);
        SFSubRef16s(ssXIOAdcChDat3, usXIOAdcChRef3, XIO_ADC_SMPL_SIZ);
        SFSubRef16s(ssXIOAdcChDat4, usXIOAdcChRef4, XIO_ADC_SMPL_SIZ);
        SFSubRef16s(ssXIOAdcChDat5, usXIOAdcChRef5, XIO_ADC_SMPL_SIZ);
        SFSubRef16s(ssXIOAdcChDat6, usXIOAdcChRef6, XIO_ADC_SMPL_SIZ);
        SFSubRef16s(ssXIOAdcChDat7, usXIOAdcChRef7, XIO_ADC_SMPL_SIZ);
        SFSubRef16s(ssXIOAdcChDat8, usXIOAdcChRef8, XIO_ADC_SMPL_SIZ);
        /* ************************************************************ */
        /*                     Adjust Data Array                        */
        /* ************************************************************ */
        SFCopy16s(&ssXIOAdcArray0[XIO_ADC_SMPL_SIZ],
                  &ssXIOAdcArray0[0],
                  XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        SFCopy16s(&ssXIOAdcArray1[XIO_ADC_SMPL_SIZ],
                  &ssXIOAdcArray1[0],
                  XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        SFCopy16s(&ssXIOAdcArray2[XIO_ADC_SMPL_SIZ],
                  &ssXIOAdcArray2[0],
                  XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        SFCopy16s(&ssXIOAdcArray3[XIO_ADC_SMPL_SIZ],
                  &ssXIOAdcArray3[0],
                  XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        SFCopy16s(&ssXIOAdcArray4[XIO_ADC_SMPL_SIZ],
                  &ssXIOAdcArray4[0],
                  XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        SFCopy16s(&ssXIOAdcArray5[XIO_ADC_SMPL_SIZ],
                  &ssXIOAdcArray5[0],
                  XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        SFCopy16s(&ssXIOAdcArray6[XIO_ADC_SMPL_SIZ],
                  &ssXIOAdcArray6[0],
                  XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        SFCopy16s(&ssXIOAdcArray7[XIO_ADC_SMPL_SIZ],
                  &ssXIOAdcArray7[0],
                  XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        SFCopy16s(&ssXIOAdcArray8[XIO_ADC_SMPL_SIZ],
                  &ssXIOAdcArray8[0],
                  XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        /* ************************************************************ */
        /*                     Copy Adc Data To Array                   */
        /* ************************************************************ */
        SFCopy16s(&ssXIOAdcChDat0[0],    //ADC采集数据
                  &ssXIOAdcArray0[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                  XIO_ADC_SMPL_SIZ);
        SFCopy16s(&ssXIOAdcChDat1[0],
                  &ssXIOAdcArray1[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                  XIO_ADC_SMPL_SIZ);
        SFCopy16s(&ssXIOAdcChDat2[0],
                  &ssXIOAdcArray2[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                  XIO_ADC_SMPL_SIZ);
        SFCopy16s(&ssXIOAdcChDat3[0],
                  &ssXIOAdcArray3[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                  XIO_ADC_SMPL_SIZ);
        SFCopy16s(&ssXIOAdcChDat4[0],
                  &ssXIOAdcArray4[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                  XIO_ADC_SMPL_SIZ);
        SFCopy16s(&ssXIOAdcChDat5[0],
                  &ssXIOAdcArray5[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                  XIO_ADC_SMPL_SIZ);
        SFCopy16s(&ssXIOAdcChDat6[0],
                  &ssXIOAdcArray6[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                  XIO_ADC_SMPL_SIZ);
        SFCopy16s(&ssXIOAdcChDat7[0],
                  &ssXIOAdcArray7[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                  XIO_ADC_SMPL_SIZ);
        SFCopy16s(&ssXIOAdcChDat8[0],
                  &ssXIOAdcArray8[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                  XIO_ADC_SMPL_SIZ);
        /* ************************************************************ */
        /*                 IIR and Copy Data to IirBuf                  */
        /* ************************************************************ */
        (void)SFGetIir16s(&ssXIOAdcChDat0[0],  //ADC采集数据
                          &ssXIOAdcIirBuf0[0],
                          &sXIOIirFilter0, XIO_ADC_SMPL_SIZ);
        (void)SFGetIir16s(&ssXIOAdcChDat1[0],
                          &ssXIOAdcIirBuf1[0],
                          &sXIOIirFilter1, XIO_ADC_SMPL_SIZ);
        (void)SFGetIir16s(&ssXIOAdcChDat3[0],
                          &ssXIOAdcIirBuf3[0],
                          &sXIOIirFilter3, XIO_ADC_SMPL_SIZ);
        (void)SFGetIir16s(&ssXIOAdcChDat4[0],
                          &ssXIOAdcIirBuf4[0],
                          &sXIOIirFilter4, XIO_ADC_SMPL_SIZ);
        (void)SFGetIir16s(&ssXIOAdcChDat6[0],
                          &ssXIOAdcIirBuf6[0],
                          &sXIOIirFilter6, XIO_ADC_SMPL_SIZ);
        (void)SFGetIir16s(&ssXIOAdcChDat7[0],
                          &ssXIOAdcIirBuf7[0],
                          &sXIOIirFilter7, XIO_ADC_SMPL_SIZ);
        /* ************************************************************ */
        /*                    Find Zero Cross Points                    */
        /* ************************************************************ */
        (void)SFFindZeroCross(&ssXIOAdcIirBuf0[0],
                              &sXIOZeroCross0, XIO_ADC_SMPL_SIZ);
        (void)SFFindZeroCross(&ssXIOAdcIirBuf1[0],
                              &sXIOZeroCross1, XIO_ADC_SMPL_SIZ);
        (void)SFFindZeroCross(&ssXIOAdcIirBuf3[0],
                              &sXIOZeroCross3, XIO_ADC_SMPL_SIZ);
        (void)SFFindZeroCross(&ssXIOAdcIirBuf4[0],
                              &sXIOZeroCross4, XIO_ADC_SMPL_SIZ);
        (void)SFFindZeroCross(&ssXIOAdcIirBuf6[0],
                              &sXIOZeroCross6, XIO_ADC_SMPL_SIZ);
        (void)SFFindZeroCross(&ssXIOAdcIirBuf7[0],
                              &sXIOZeroCross7, XIO_ADC_SMPL_SIZ);
        /* ************************************************************ */
        /*                     Get Period and Phase                     */
        /* ************************************************************ */
        uiXIOSoftPrdMainA  = sXIOZeroCross0.uiPrd;
        usXIOSoftFreqMainA = sXIOZeroCross0.usFreq;
        usXIOSoftPhsMainA  = sXIOZeroCross0.usPhase;
        uiXIOSoftPrdMainB  = sXIOZeroCross3.uiPrd;
        usXIOSoftFreqMainB = sXIOZeroCross3.usFreq;
        usXIOSoftPhsMainB  = sXIOZeroCross3.usPhase;
        uiXIOSoftPrdMainC  = sXIOZeroCross6.uiPrd;
        usXIOSoftFreqMainC = sXIOZeroCross6.usFreq;
        usXIOSoftPhsMainC  = sXIOZeroCross6.usPhase;
        uiXIOSoftPrdGensA  = sXIOZeroCross1.uiPrd;
        usXIOSoftFreqGensA = sXIOZeroCross1.usFreq;
        usXIOSoftPhsGensA  = sXIOZeroCross1.usPhase;
        uiXIOSoftPrdGensB  = sXIOZeroCross4.uiPrd;
        usXIOSoftFreqGensB = sXIOZeroCross4.usFreq;
        usXIOSoftPhsGensB  = sXIOZeroCross4.usPhase;
        uiXIOSoftPrdGensC  = sXIOZeroCross7.uiPrd;
        usXIOSoftFreqGensC = sXIOZeroCross7.usFreq;
        usXIOSoftPhsGensC  = sXIOZeroCross7.usPhase;
        ssXIOSoftPhsDiffer = usXIOSoftPhsGensA - usXIOSoftPhsMainA;
        usDBmMainPhaseAB   = usXIOSoftPhsMainB - usXIOSoftPhsMainA;
        usDBmMainPhaseBC   = usXIOSoftPhsMainC - usXIOSoftPhsMainB;
        usDBmMainPhaseCA   = usXIOSoftPhsMainA - usXIOSoftPhsMainC;
        usDBmGensPhaseAB   = usXIOSoftPhsGensB - usXIOSoftPhsGensA;
        usDBmGensPhaseBC   = usXIOSoftPhsGensC - usXIOSoftPhsGensB;
        usDBmGensPhaseCA   = usXIOSoftPhsGensA - usXIOSoftPhsGensC;
        /* ************************************************************ */
        /*                     Get Hard Period                          */
        /* ************************************************************ */
        uiXIOHardPrdMainA  = SFHardPrdGetPeriod(&sXIOHardPeriod0);
        uiXIOHardPrdGensA  = SFHardPrdGetPeriod(&sXIOHardPeriod1);
        usXIOHardFreqMainA = SFHardPrdGetFreq(&sXIOHardPeriod0);
        usXIOHardFreqGensA = SFHardPrdGetFreq(&sXIOHardPeriod1);
        ssXIOHardPhsDiffer = SFHardPrdGetPhsDiff(&sXIOHardPeriod0,&sXIOHardPeriod1);
        /* ************************************************************ */
        /*             Get Main and Gens Period, Freq, Differ           */
        /* ************************************************************ */
        if (SFHardPrdCheckPeriod(&sXIOHardPeriod0) != SF_FALSE)
        {   XIO_STS_CLR_BIT(XIO_STS_HARDPRD0_ERR);
            uiXIOActivePrdMain = uiXIOHardPrdMainA;
            usDBmMainFreq      = usXIOHardFreqMainA;
        }   else
        {   XIO_STS_SET_BIT(XIO_STS_HARDPRD0_ERR);
            uiXIOActivePrdMain = uiXIOSoftPrdMainA;
            usDBmMainFreq      = usXIOSoftFreqMainA;
        }
        if (SFHardPrdCheckPeriod(&sXIOHardPeriod1) != SF_FALSE)
        {   XIO_STS_CLR_BIT(XIO_STS_HARDPRD1_ERR);
            uiXIOActivePrdGens = uiXIOHardPrdGensA;
            usDBmGensFreq      = usXIOHardFreqGensA;
        }   else
        {   XIO_STS_SET_BIT(XIO_STS_HARDPRD1_ERR);
            uiXIOActivePrdGens = uiXIOSoftPrdGensA;
            usDBmGensFreq      = usXIOSoftFreqGensA;
        }
        if (XIO_STS_GET_BIT(XIO_STS_HARDPRD_BOTH) == 0)
        {   ssDBmPhaseDiffer = ssXIOHardPhsDiffer;
            ssDBmFreqDiffer  = usXIOHardFreqGensA - usXIOHardFreqMainA;
        }   else
        {   ssDBmPhaseDiffer = ssXIOSoftPhsDiffer;
            ssDBmFreqDiffer  = usXIOSoftFreqGensA - usXIOSoftFreqMainA;
        }
        /* ************************************************************ */
        /*                         Get Main Voltage                     */
        /* ************************************************************ */
        usSiz = (INT16U)((uiXIOActivePrdMain+XIO_ADC_SMPL_TIM_US/2)/XIO_ADC_SMPL_TIM_US);
        if((usSiz < (XIO_ADC_SMPL_SIZ/2)) || (usSiz >= XIO_ADC_ARRAY_SIZ))
        {   usSiz =  XIO_ADC_SMPL_SIZ;
        }
        usBeg           = XIO_ADC_ARRAY_SIZ - usSiz;
        usXIOMainSmpSiz = usSiz;
        usXIOAdcChEff0  = SFGetEffAve(&ssXIOAdcArray0[usBeg], usSiz);
        usXIOAdcChEff3  = SFGetEffAve(&ssXIOAdcArray3[usBeg], usSiz);
        usXIOAdcChEff6  = SFGetEffAve(&ssXIOAdcArray6[usBeg], usSiz);
        usXIOAdcChEff03 = SFSubEffAve(&ssXIOAdcArray0[usBeg],
                                      &ssXIOAdcArray3[usBeg], usSiz);
        usXIOAdcChEff06 = SFSubEffAve(&ssXIOAdcArray0[usBeg],
                                      &ssXIOAdcArray6[usBeg], usSiz);
        usXIOAdcChEff36 = SFSubEffAve(&ssXIOAdcArray3[usBeg],
                                      &ssXIOAdcArray6[usBeg], usSiz);
        usDBmMainVoltA  = SF_GET_VOLT_LN(usXIOAdcChEff0, usDBpAmpMainVoltA);
        usDBmMainVoltB  = SF_GET_VOLT_LN(usXIOAdcChEff3, usDBpAmpMainVoltB);
        usDBmMainVoltC  = SF_GET_VOLT_LN(usXIOAdcChEff6, usDBpAmpMainVoltC);
        usDBmMainVoltAB = SF_GET_VOLT_LL(usXIOAdcChEff03,usDBpAmpMainVoltAB);
        usDBmMainVoltBC = SF_GET_VOLT_LL(usXIOAdcChEff06,usDBpAmpMainVoltBC);
        usDBmMainVoltCA = SF_GET_VOLT_LL(usXIOAdcChEff36,usDBpAmpMainVoltCA);
        /* ************************************************************ */
        /*                  Get Gens Voltage and Current                */
        /* ************************************************************ */
        usSiz = (INT16U)((uiXIOActivePrdGens+XIO_ADC_SMPL_TIM_US/2)/XIO_ADC_SMPL_TIM_US);
        if((usSiz < (XIO_ADC_SMPL_SIZ/2)) || (usSiz >= XIO_ADC_ARRAY_SIZ))
        {   usSiz =  XIO_ADC_SMPL_SIZ;
        }
        usBeg           = XIO_ADC_ARRAY_SIZ - usSiz;
        usXIOGensSmpSiz = usSiz;
        usXIOAdcChEff1  = SFGetEffAve(&ssXIOAdcArray1[usBeg], usSiz);
        usXIOAdcChEff4  = SFGetEffAve(&ssXIOAdcArray4[usBeg], usSiz);
        usXIOAdcChEff7  = SFGetEffAve(&ssXIOAdcArray7[usBeg], usSiz);
        usXIOAdcChEff2  = SFGetEffAve(&ssXIOAdcArray2[usBeg], usSiz);    //获取中心点电压？？
        usXIOAdcChEff5  = SFGetEffAve(&ssXIOAdcArray5[usBeg], usSiz);
        usXIOAdcChEff8  = SFGetEffAve(&ssXIOAdcArray8[usBeg], usSiz);
        usXIOAdcChEff14 = SFSubEffAve(&ssXIOAdcArray1[usBeg],
                                      &ssXIOAdcArray4[usBeg], usSiz);
        usXIOAdcChEff17 = SFSubEffAve(&ssXIOAdcArray1[usBeg],
                                      &ssXIOAdcArray7[usBeg], usSiz);
        usXIOAdcChEff47 = SFSubEffAve(&ssXIOAdcArray4[usBeg],
                                      &ssXIOAdcArray7[usBeg], usSiz);
        usXIOAdcChEffGd = SFTriEffAve(&ssXIOAdcArray2[usBeg],
                                      &ssXIOAdcArray5[usBeg],
                                      &ssXIOAdcArray8[usBeg], usSiz);
        usDBmGensVoltA  = SF_GET_VOLT_LN(usXIOAdcChEff1, usDBpAmpGensVoltA);     //获取A相电压
        usDBmGensVoltB  = SF_GET_VOLT_LN(usXIOAdcChEff4, usDBpAmpGensVoltB);     //获取B相电压
        usDBmGensVoltC  = SF_GET_VOLT_LN(usXIOAdcChEff7, usDBpAmpGensVoltC);     //获取C相电压
        usDBmGensVoltAB = SF_GET_VOLT_LL(usXIOAdcChEff14,usDBpAmpGensVoltAB);
        usDBmGensVoltBC = SF_GET_VOLT_LL(usXIOAdcChEff17,usDBpAmpGensVoltBC);
        usDBmGensVoltCA = SF_GET_VOLT_LL(usXIOAdcChEff47,usDBpAmpGensVoltCA);
        usDBmGensCurrA  = SF_GET_CURRENT(usXIOAdcChEff2, usDBpAmpGensCurrA, usDBpGensCtRatio);    //获取A相电流-   校验值？ 基准值？
        usDBmGensCurrB  = SF_GET_CURRENT(usXIOAdcChEff5, usDBpAmpGensCurrB, usDBpGensCtRatio);
        usDBmGensCurrC  = SF_GET_CURRENT(usXIOAdcChEff8, usDBpAmpGensCurrC, usDBpGensCtRatio);
        usBeg           = (usDBpAmpGensCurrA + usDBpAmpGensCurrB + usDBpAmpGensCurrC) / 3;
        usDBmGensCurrGd = SF_GET_CURRENT(usXIOAdcChEffGd, usBeg, usDBpGensCtRatio);
        ssDBmVoltDiffer = usDBmGensVoltA - usDBmMainVoltA;
        /* ************************************************************ */
        /*                        Get Active Power                      */
        /* ************************************************************ */
        usSiz           = usXIOGensSmpSiz;
        usBeg           = XIO_ADC_ARRAY_SIZ - usSiz;
        siXIOCrossMac12 = SFGetMacAve(&ssXIOAdcArray1[usBeg],
                                      &ssXIOAdcArray2[usBeg], usSiz);
        siXIOCrossMac45 = SFGetMacAve(&ssXIOAdcArray4[usBeg],
                                      &ssXIOAdcArray5[usBeg], usSiz);
        siXIOCrossMac78 = SFGetMacAve(&ssXIOAdcArray7[usBeg],
                                      &ssXIOAdcArray8[usBeg], usSiz);
        ssDBmActPowerA  = SF_GET_ACT_PWR(siXIOCrossMac12, usDBpAmpGensVoltA,
                                         usDBpAmpGensCurrA, usDBpGensCtRatio);
        ssDBmActPowerB  = SF_GET_ACT_PWR(siXIOCrossMac45, usDBpAmpGensVoltB,
                                         usDBpAmpGensCurrB, usDBpGensCtRatio);
        ssDBmActPowerC  = SF_GET_ACT_PWR(siXIOCrossMac78, usDBpAmpGensVoltC,
                                         usDBpAmpGensCurrC, usDBpGensCtRatio);
        ssDBmActPowerAll = ssDBmActPowerA + ssDBmActPowerB + ssDBmActPowerC;
        /* ************************************************************ */
        /*                        Get Apparent Power                    */
        /* ************************************************************ */
        usDBmAppPowerA  = SF_GET_APP_PWR(usDBmGensVoltA, usDBmGensCurrA);
        usDBmAppPowerB  = SF_GET_APP_PWR(usDBmGensVoltB, usDBmGensCurrB);
        usDBmAppPowerC  = SF_GET_APP_PWR(usDBmGensVoltC, usDBmGensCurrC);
        usDBmAppPowerAll = usDBmAppPowerA + usDBmAppPowerB + usDBmAppPowerC;
        /* ************************************************************ */
        /*                        Get Reactive Power                    */
        /* ************************************************************ */
        ssDBmReactPowerA = SF_GET_REACT_PWR(usDBmAppPowerA, ssDBmActPowerA);
        ssDBmReactPowerB = SF_GET_REACT_PWR(usDBmAppPowerB, ssDBmActPowerB);
        ssDBmReactPowerC = SF_GET_REACT_PWR(usDBmAppPowerC, ssDBmActPowerC);
        ssDBmReactPowerAll = ssDBmReactPowerA + ssDBmReactPowerB + ssDBmReactPowerC;
        /* ************************************************************ */
        /*                        Get Power Factor                      */
        /* ************************************************************ */
        ssDBmPowerFactorA = SF_GET_PWR_FACT(ssDBmActPowerA, usDBmAppPowerA);
        ssDBmPowerFactorB = SF_GET_PWR_FACT(ssDBmActPowerB, usDBmAppPowerB);
        ssDBmPowerFactorC = SF_GET_PWR_FACT(ssDBmActPowerC, usDBmAppPowerC);
        ssDBmPowerFactorAll = SF_GET_PWR_FACT(ssDBmActPowerAll, usDBmAppPowerAll);
        /* ************************************************************ */
        /*                 Read Switches, Keys, Analogs                 */
        /* ************************************************************ */
        usDBmSwitchesInput = XIOReadSwitchesInput();  //开关量输入
        usDBmBoardKeyInput = XIOReadBoardKeyInput();  //面板按键输入
        (void)SFUpdateSwitchesStatus(usDBmSwitchesInput);  //开关量状态更新
        (void)SFUpdateBoardKeyStatus(usDBmBoardKeyInput);  //面板按键状态更新
        (void)SFUpdateAnalogStatus(&usDBmAdcInput[0]);     //输入模拟量更新
        /* ************************************************************ */
        /*                          Control Loop                        */
        /* ************************************************************ */
        (void)CTLSysMonitor();
        (void)CTLSysController();
        /* ************************************************************ */
        /*                     Digital and PWM Outputs                  */
        /* ************************************************************ */
        (void)XIOUpdateSwitchesOutput(usDBmSwitchesOutput);
        (void)XIOUpdateBoardLedOutput(usDBmBoardLedOutput);
        (void)XIOUpdatePwmOutput();
        (void)SFUpdataStatistics(usDBmSpeed,usDBmAppPowerAll);
        uiDBhKwh32B += SFGetAccKwh(ssDBmActPowerAll);
        uiDBhKvarh32B += SFGetAccKvarh(ssDBmReactPowerAll);
        uiDBhRunTime32B += SFGetAccRunTime(usDBmEngineRunning);
        (void)SFCheckToSaveHstry();
        /* ************************************************************ */
        /*                          If FFT Needs                        */
        /* ************************************************************ */
        usBeg = usDBmAdcFftChannel;
        if ((usBeg <= 8) && (FFT_STS_GET_BIT(FFT_STS_BUFF_BUSY) == 0))
        {   if (usBeg == 0)
            {   pXIOFftDatBuf = &ssXIOAdcChDat0[0];             //ACD采集数据
            }   else if (usBeg == 1)
            {   pXIOFftDatBuf = &ssXIOAdcChDat1[0];
            }   else if (usBeg == 2)
            {   pXIOFftDatBuf = &ssXIOAdcChDat2[0];
            }   else if (usBeg == 3)
            {   pXIOFftDatBuf = &ssXIOAdcChDat3[0];
            }   else if (usBeg == 4)
            {   pXIOFftDatBuf = &ssXIOAdcChDat4[0];
            }   else if (usBeg == 5)
            {   pXIOFftDatBuf = &ssXIOAdcChDat5[0];
            }   else if (usBeg == 6)
            {   pXIOFftDatBuf = &ssXIOAdcChDat6[0];
            }   else if (usBeg == 7)
            {   pXIOFftDatBuf = &ssXIOAdcChDat7[0];
            }   else
            {   pXIOFftDatBuf = &ssXIOAdcChDat8[0];
            }
            FFT_STS_SET_BIT(FFT_STS_BUFF_BUSY);
            (void)SFCopy16sToCmplx(pXIOFftDatBuf, &fFFTDatBuffer[0], FFT_FFT_DAT_SIZE);
            (void)FFTPutCmdChar(FFT_CMD_DAT_RDY);
        }
        usXIOCalcTime = XIO_GET_FREE_TIMER() - usTim;
    }
}

/* ******************************************************************** */
/*                        XIODma1Ch1IntHook()      DMA中断              */
/* ******************************************************************** */
void XIODma1Ch1IntHook (void)
{   DMA1_Channel1->CCR  &= ~DMA_CCR1_EN;       /* 1: Channel disabled   */
    DMA1_Channel1->CPAR  = (INT32U)(&(ADC1->DR));
    DMA1_Channel1->CMAR  = (INT32U)pXIOAdcDmaBuf;                        //从DMA读取ADC数据的地址
    DMA1_Channel1->CNDTR =  XIO_ADC_DMA_BUF_SIZ;
    DMA1->IFCR           =  DMA_ISR_GIF1       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF1      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF1      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF1;     /* 1: clear TE flag      */
    DMA1_Channel1->CCR  |=  DMA_CCR1_EN;       /* 1: Channel enabled    */
    if (pXIOAdcDmaBuf   == &usXIOAdcDmaBuf0[0])   //读取ADC数据  pXIOAdcDmaBuf   = &usXIOAdcDmaBuf0[0];  //DMA读取ADC数据地址
    {   pXIOAdcDmaBuf    = &usXIOAdcDmaBuf1[0];    
    }   else
    {   pXIOAdcDmaBuf    = &usXIOAdcDmaBuf0[0];
    }
    (void)OSIntTaskResume(FW_TASK_PRIO_XIO);    //DMA中断产生一个信号量使任务运行一次。
}

/* ******************************************************************** */
/*                           XIOGetAdcChanDat()                         */
/* ******************************************************************** */
void XIOGetAdcChanDat (INT16U *pDmaBuf)
{   INT16U usNumb, usSize, *pData;
    pData  = pDmaBuf;
    usNumb = 0;
    usSize = XIO_ADC_SMPL_SIZ;
    while (usSize--)
    {   ssXIOAdcChDat0[usNumb]  = *pData++;  
        ssXIOAdcChDat1[usNumb]  = *pData++;
        ssXIOAdcChDat2[usNumb]  = *pData++;
        ssXIOAdcChDat3[usNumb]  = *pData++;
        ssXIOAdcChDat4[usNumb]  = *pData++;
        ssXIOAdcChDat5[usNumb]  = *pData++;
        ssXIOAdcChDat6[usNumb]  = *pData++;
        ssXIOAdcChDat7[usNumb]  = *pData++;
        ssXIOAdcChDat8[usNumb]  = *pData++;
        ssXIOAdcChDat9[usNumb]  = *pData++;
        ssXIOAdcChDat10[usNumb] = *pData++;
        ssXIOAdcChDat11[usNumb] = *pData++;
        ssXIOAdcChDat12[usNumb] = *pData++;
        ssXIOAdcChDat13[usNumb] = *pData++;
        ssXIOAdcChDat14[usNumb] = *pData++;
        ssXIOAdcChDat15[usNumb] = *pData++;
        usNumb++;
    }
}

/* ******************************************************************** */
/*                        XIOReadSwitchesInput()                        */
/* ******************************************************************** */
int TESTZC[10];
INT16U XIOReadSwitchesInput (void)
{   
  if(KEY_STOP == 0)TESTZC[0]++;
  
    return 0;
}

/* ******************************************************************** */
/*                        XIOReadSwitchesInput()                        */
/* ******************************************************************** */
INT16U XIOReadBoardKeyInput (void)
{   
    return 0;
}

/* ******************************************************************** */
/*                       XIOUpdateSwitchesOutput()                      */
/* ******************************************************************** */
void XIOUpdateSwitchesOutput (INT16U usOutput)
{
}

/* ******************************************************************** */
/*                       XIOUpdateBoardLedOutput()                      */
/* ******************************************************************** */
void XIOUpdateBoardLedOutput (INT16U usOutput)
{
}

/* ******************************************************************** */
/*                         XIOUpdatePwmOutput()                         */
/* ******************************************************************** */
void XIOUpdatePwmOutput (void)
{
}

/* ******************************************************************** */
/*                           XIOInitDigInput()                          */
/* ******************************************************************** */
void XIOInitDigInput (void)
{
 //PE6-停止按钮
  //打开GPIOE 的时钟
  RCC->APB2ENR |= 0x00000040;  
  //设置PE6为上拉输入
     GPIOE->CRL &= 0xF0FFFFFF;
    GPIOE->CRL |= 0x08000000;
    GPIOE->ODR |= (0x07 << 6);  
  
}

/* ******************************************************************** */
/*                           XIOInitDigOutput()                         */
/* ******************************************************************** */
void XIOInitDigOutput (void)
{
}

/* ******************************************************************** */
/*                           XIOInitPwmOutput()                         */
/* ******************************************************************** */
void XIOInitPwmOutput (void)
{
}

/* ******************************************************************** */
/*                              XIOInitADC1()                           */
/* ******************************************************************** */
void XIOInitADC1 (void)
{   XIOConfigGPIO(GPIOA, XIO_PT_BT0, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);//端口初始化-GEC4800悬空
    XIOConfigGPIO(GPIOA, XIO_PT_BT1, XIO_PT_GPI_ANALOG, XIO_PT_SET_0); //PA1发电电流A
    XIOConfigGPIO(GPIOA, XIO_PT_BT2, XIO_PT_GPI_ANALOG, XIO_PT_SET_0); //PA2发电电流B
    XIOConfigGPIO(GPIOA, XIO_PT_BT3, XIO_PT_GPI_ANALOG, XIO_PT_SET_0); //PA3发电电流C
    XIOConfigGPIO(GPIOA, XIO_PT_BT4, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT5, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);//PA5发电电压A
    XIOConfigGPIO(GPIOA, XIO_PT_BT6, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);//PA6发电电压B
    XIOConfigGPIO(GPIOA, XIO_PT_BT7, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);//PA7发电电压C
    XIOConfigGPIO(GPIOB, XIO_PT_BT0, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOB, XIO_PT_BT1, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT0, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT1, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT2, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT3, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT4, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT5, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    RCC->APB2ENR |=  RCC_APB2ENR_ADC1EN;       /* 1: ADC1 clock enable  *///ADC1时钟初始化
    ADC1->CR1    &= ~ADC_CR1_EOCIE             /* EOC Interrupt disable */
                 &  ~ADC_CR1_AWDIE             /* Analog Watchdog inter */
                 &  ~ADC_CR1_JEOCIE            /* Injected chan interru */
                 &  ~ADC_CR1_SCAN              /* Scan mode disable     */
                 &  ~ADC_CR1_AWDSGL            /* Disnable the watchdog */
                 &  ~ADC_CR1_JAUTO             /* Injected group conver */
                 &  ~ADC_CR1_DISCEN            /* Discontinuous mode    */
                 &  ~ADC_CR1_JDISCEN;          /* Discontinuous mode    */
    ADC1->CR2    &= ~ADC_CR2_ADON              /* A/D Converter OFF     */
                 &  ~ADC_CR2_CONT              /* Continuous Conversion */
                 &  ~ADC_CR2_CAL               /* A/D Calibration       */
                 &  ~ADC_CR2_DMA               /* DMA mode disable      */
                 &  ~ADC_CR2_ALIGN             /* Data Alignment right  */
                 &  ~ADC_CR2_EXTSEL            /* EXTSEL[2:0]=0: T1_CC1 */
                 &  ~ADC_CR2_EXTTRIG;          /* EXT triger Disabled   */
    ADC1->SMPR2   = (XIO_ADC1_SMPL_CYC << 0)   /* Chan 0  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 3)   /* Chan 1  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 6)   /* Chan 2  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 9)   /* Chan 3  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 12)  /* Chan 4  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 15)  /* Chan 5  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 18)  /* Chan 6  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 21)  /* Chan 7  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 24)  /* Chan 8  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 27); /* Chan 9  Sample Cycles */
    ADC1->SMPR1   = (XIO_ADC1_SMPL_CYC << 0)   /* Chan 10 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 3)   /* Chan 11 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 6)   /* Chan 12 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 9)   /* Chan 13 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 12)  /* Chan 14 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 15)  /* Chan 15 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 18)  /* Chan 16 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 21); /* Chan 17 Sample Cycles */
    ADC1->SQR3    = (XIO_ADC1_CH_1ST  << 0)    /* 1st  Chan in sequence */  //通道顺序
                 |  (XIO_ADC1_CH_2ND  << 5)    /* 2nd  Chan in sequence */ //通道顺序
                 |  (XIO_ADC1_CH_3RD  << 10)   /* 3rd  Chan in sequence */ //通道顺序
                 |  (XIO_ADC1_CH_4TH  << 15)   /* 4th  Chan in sequence */
                 |  (XIO_ADC1_CH_5TH  << 20)   /* 5th  Chan in sequence */ 
                 |  (XIO_ADC1_CH_6TH  << 25);  /* 6th  Chan in sequence */ 
    ADC1->SQR2    = (XIO_ADC1_CH_7TH  << 0)    /* 7th  Chan in sequence */ 
                 |  (XIO_ADC1_CH_8TH  << 5)    /* 8th  Chan in sequence */ 
                 |  (XIO_ADC1_CH_9TH  << 10)   /* 9th  Chan in sequence */ 
                 |  (XIO_ADC1_CH_10TH << 15)   /* 10th Chan in sequence */ 
                 |  (XIO_ADC1_CH_11TH << 20)   /* 11th Chan in sequence */ 
                 |  (XIO_ADC1_CH_12TH << 25);  /* 12th Chan in sequence */ 
    ADC1->SQR1    = (XIO_ADC1_CH_13TH << 0)    /* 13th Chan in sequence */ 
                 |  (XIO_ADC1_CH_14TH << 5)    /* 14th Chan in sequence */ 
                 |  (XIO_ADC1_CH_15TH << 10)   /* 15th Chan in sequence */ 
                 |  (XIO_ADC1_CH_16TH << 15)   /* 16th Chan in sequence */ 
                 | ((XIO_NUM_OF_ADC1-1)<<20);  /* Chan Size in sequence */ 
    ADC1->CR1    |=  ADC_CR1_SCAN;             /* Scan mode enable      */
    ADC1->CR2    |=  ADC_CR2_EXTTRIG           /* EXT triger Enabled    */
                 |   ADC_CR2_DMA;              /* DMA mode Enable       */
    ADC1->CR2    |=  ADC_CR2_ADON;             /* A/D Converter On      */
    ADC1->CR2    |=  ADC_CR2_RSTCAL;           /* Reset Calibration     */
    while((ADC1->CR2 & ADC_CR2_RSTCAL) != 0);  /* Wait for Calib reset  */
    ADC1->CR2    |=  ADC_CR2_CAL;              /* A/D Calibration       */
    while((ADC1->CR2 & ADC_CR2_CAL) != 0);     /* Wait for Calibration  */
}

/* ******************************************************************** */
/*                              XIOInitADC2()                           */
/* ******************************************************************** */
void XIOInitADC2 (void)
{   RCC->APB2ENR |=  RCC_APB2ENR_ADC2EN;       /* 1: ADC2 clock enable  */
    ADC2->CR1    &= ~ADC_CR1_EOCIE             /* EOC Interrupt disable */
                 &  ~ADC_CR1_AWDIE             /* Analog Watchdog inter */
                 &  ~ADC_CR1_JEOCIE            /* Injected chan interru */
                 &  ~ADC_CR1_SCAN              /* Scan mode disable     */
                 &  ~ADC_CR1_AWDSGL            /* Disnable the watchdog */
                 &  ~ADC_CR1_JAUTO             /* Injected group conver */
                 &  ~ADC_CR1_DISCEN            /* Discontinuous mode    */
                 &  ~ADC_CR1_JDISCEN;          /* Discontinuous mode    */
    ADC2->CR2    &= ~ADC_CR2_ADON              /* A/D Converter OFF     */
                 &  ~ADC_CR2_CONT              /* Continuous Conversion */
                 &  ~ADC_CR2_CAL               /* A/D Calibration       */
                 &  ~ADC_CR2_DMA               /* DMA mode disable      */
                 &  ~ADC_CR2_ALIGN             /* Data Alignment right  */
                 &  ~ADC_CR2_EXTSEL            /* EXTSEL[2:0] Sources   */
                 &  ~ADC_CR2_EXTTRIG;          /* EXT triger Disabled   */
    ADC2->SMPR2   = (XIO_ADC2_SMPL_CYC << 0)   /* Chan 0  Sample Cycles */
                 |  (XIO_ADC2_SMPL_CYC << 3)   /* Chan 1  Sample Cycles */
                 |  (XIO_ADC2_SMPL_CYC << 6)   /* Chan 2  Sample Cycles */
                 |  (XIO_ADC2_SMPL_CYC << 9)   /* Chan 3  Sample Cycles */
                 |  (XIO_ADC2_SMPL_CYC << 12)  /* Chan 4  Sample Cycles */
                 |  (XIO_ADC2_SMPL_CYC << 15)  /* Chan 5  Sample Cycles */
                 |  (XIO_ADC2_SMPL_CYC << 18)  /* Chan 6  Sample Cycles */
                 |  (XIO_ADC2_SMPL_CYC << 21)  /* Chan 7  Sample Cycles */
                 |  (XIO_ADC2_SMPL_CYC << 24)  /* Chan 8  Sample Cycles */
                 |  (XIO_ADC2_SMPL_CYC << 27); /* Chan 9  Sample Cycles */
    ADC2->SMPR1   = (XIO_ADC2_SMPL_CYC << 0)   /* Chan 10 Sample Cycles */
                 |  (XIO_ADC2_SMPL_CYC << 3)   /* Chan 11 Sample Cycles */
                 |  (XIO_ADC2_SMPL_CYC << 6)   /* Chan 12 Sample Cycles */
                 |  (XIO_ADC2_SMPL_CYC << 9)   /* Chan 13 Sample Cycles */
                 |  (XIO_ADC2_SMPL_CYC << 12)  /* Chan 14 Sample Cycles */
                 |  (XIO_ADC2_SMPL_CYC << 15)  /* Chan 15 Sample Cycles */
                 |  (XIO_ADC2_SMPL_CYC << 18)  /* Chan 16 Sample Cycles */
                 |  (XIO_ADC2_SMPL_CYC << 21); /* Chan 17 Sample Cycles */
    ADC2->SQR3    = (XIO_ADC2_CH_1ST  << 0)    /* 1st  Chan in sequence */
                 |  (XIO_ADC2_CH_2ND  << 5)    /* 2nd  Chan in sequence */
                 |  (XIO_ADC2_CH_3RD  << 10)   /* 3rd  Chan in sequence */
                 |  (XIO_ADC2_CH_4TH  << 15)   /* 4th  Chan in sequence */
                 |  (XIO_ADC2_CH_5TH  << 20)   /* 5th  Chan in sequence */
                 |  (XIO_ADC2_CH_6TH  << 25);  /* 6th  Chan in sequence */
    ADC2->SQR2    = (XIO_ADC2_CH_7TH  << 0)    /* 7th  Chan in sequence */
                 |  (XIO_ADC2_CH_8TH  << 5)    /* 8th  Chan in sequence */
                 |  (XIO_ADC2_CH_9TH  << 10)   /* 9th  Chan in sequence */
                 |  (XIO_ADC2_CH_10TH << 15)   /* 10th Chan in sequence */
                 |  (XIO_ADC2_CH_11TH << 20)   /* 11th Chan in sequence */
                 |  (XIO_ADC2_CH_12TH << 25);  /* 12th Chan in sequence */
    ADC2->SQR1    = (XIO_ADC2_CH_13TH << 0)    /* 13th Chan in sequence */
                 |  (XIO_ADC2_CH_14TH << 5)    /* 14th Chan in sequence */
                 |  (XIO_ADC2_CH_15TH << 10)   /* 15th Chan in sequence */
                 |  (XIO_ADC2_CH_16TH << 15)   /* 16th Chan in sequence */
                 | ((XIO_NUM_OF_ADC2-1)<<20);  /* Chan Size in sequence */
    ADC2->CR1    |=  ADC_CR1_SCAN;             /* Scan mode enable      */
    ADC2->CR2    |=  ADC_CR2_EXTSEL;           /* Triger=111: SWSTART   */
    ADC2->CR2    |=  ADC_CR2_ADON;             /* A/D Converter On      */
    ADC2->CR2    |=  ADC_CR2_RSTCAL;           /* Reset Calibration     */
    while((ADC2->CR2 & ADC_CR2_RSTCAL) != 0);  /* Wait for Calib reset  */
    ADC2->CR2    |=  ADC_CR2_CAL;              /* A/D Calibration       */
    while((ADC2->CR2 & ADC_CR2_CAL) != 0);     /* Wait for Calibration  */
}

/* ******************************************************************** */
/*                       XIOAdc2StartConversion()                       */
/* ******************************************************************** */
void XIOAdc2StartConversion (void)
{   ADC2->CR2   |= ADC_CR2_SWSTART
                |  ADC_CR2_ADON;
}

/* ******************************************************************** */
/*                         XIOAdc2ReadResult()                          */
/* ******************************************************************** */
INT16U XIOAdc2ReadResult (void)
{   return (ADC2->DR);
}

/* ******************************************************************** */
/*                          XIOInitDma1Ch1Adc()    DMA读取ADC初始化     */
/* ******************************************************************** */
void XIOInitDma1Ch1Adc (void)
{   RCC->AHBENR         |=  RCC_AHBENR_DMA1EN; /* 1: DMA clock enable   */
    DMA1_Channel1->CCR  &= ~DMA_CCR1_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR1_PL        /* 0: Priority low       */
                        &  ~DMA_CCR1_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR1_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR1_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR1_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR1_DIR       /* 0: Read from periphe  */
                        &  ~DMA_CCR1_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR1_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR1_TCIE;     /* 0: TC interrupt off   */
    DMA1_Channel1->CCR  |=  DMA_CCR1_MINC      /* Memory increment mode */
                        |   DMA_CCR1_MSIZE_0   /* 01: Memory size 16bit */
                        |   DMA_CCR1_PSIZE_0   /* 01: Peripheral siz 16 */
                        |   DMA_CCR1_PL_1;     /* 01: Priority High     */
    DMA1->IFCR           =  DMA_ISR_GIF1       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF1      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF1      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF1;     /* 1: clear TE flag      */
    DMA1_Channel1->CNDTR =  XIO_ADC_DMA_BUF_SIZ;
    DMA1_Channel1->CPAR  = (INT32U)&(ADC1->DR);
    DMA1_Channel1->CMAR  = (INT32U)pXIOAdcDmaBuf;
    DMA1_Channel1->CCR  |=  DMA_CCR1_TCIE
                        |   DMA_CCR1_EN;
    if (pXIOAdcDmaBuf   == &usXIOAdcDmaBuf0[0])
    {   pXIOAdcDmaBuf    = &usXIOAdcDmaBuf1[0];
    }   else
    {   pXIOAdcDmaBuf    = &usXIOAdcDmaBuf0[0];
    }
}

/* ******************************************************************** */
/*                             XIOInitTim1()                            */
/* ******************************************************************** */
void XIOInitTim1 (void)
{   RCC->APB2ENR  |=  RCC_APB2ENR_TIM1EN;    /* 1: TIM1 clock enable    */
    RCC->APB2RSTR |=  RCC_APB2RSTR_TIM1RST;  /* 1: TIM1 clock reset     */
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM1RST;  /* 0: TIM1 reset stop      */
    TIM1->CR1      =  0;                     /* TIM1 control register 1 */
    TIM1->CR2      =  0;                     /* TIM1 control register 2 */
    TIM1->SMCR     =  0;                     /* TIM1 slave mode control */
    TIM1->DIER     =  0;                     /* TIM1 DMA/Interrupt en   */
    TIM1->SR       =  0;                     /* TIM1 status register    */
    TIM1->EGR      =  0;                     /* TIM1 event generation   */
    TIM1->CCMR1    =  0;                     /* Capture/compare mode 1  */
    TIM1->CCMR2    =  0;                     /* Capture/compare mode 2  */
    TIM1->CCER     =  0;                     /* Capture/compare enable  */
    TIM1->CNT      =  0;                     /* TIM1 counter            */
    TIM1->PSC      =  71;                    /* Prescaler: 72(1us)      */
    TIM1->ARR      =  0xFFFF;                /* TIM1 auto-reload        */
    TIM1->RCR      =  0;                     /* TIM1 control register 1 */
    TIM1->CCR1     =  0;                     /* Capture/compare reg 1   */
    TIM1->CCR2     =  0;                     /* Capture/compare reg 2   */
    TIM1->CCR3     =  0;                     /* Capture/compare reg 3   */
    TIM1->CCR4     =  0;                     /* Capture/compare reg 4   */
    TIM1->BDTR     =  0;                     /* break and dead-time     */
    TIM1->DCR      =  0;                     /* DMA control register    */
    TIM1->DMAR     =  0;                     /* DMA address for full tr */
}

/* ******************************************************************** */
/*                       XIOInitTim1AdcTriger()                         */
/* ******************************************************************** */
void XIOInitTim1AdcTriger (void)
{   TIM1->CCMR1   |=  TIM_CCMR1_OC1M_2       /* CH1: 110, PWM mode 1    */
                  |   TIM_CCMR1_OC1M_1;      /* (111: PWM mode 2)       */
    TIM1->ARR      =  XIO_ADC_SMPL_TIM_US-1; /* Pwm Period              */
    TIM1->CCR1     =  XIO_ADC_SMPL_TIM_US/2; /* Pwm Duty                */
    TIM1->CCER    |=  TIM_CCER_CC1E;         /* OC1 enable              */
    TIM1->EGR      =  TIM_EGR_UG;            /* UG: Update generation   */
    TIM1->BDTR    |=  TIM_BDTR_MOE;          /* TIM1 Outputs enabled    */
    TIM1->CR1     |=  TIM_CR1_CEN;           /* 1: Counter enabled      */
}

/* ******************************************************************** */
/*                         XIOInitTim2()                                */
/* ******************************************************************** */
void XIOInitTim2 (void)
{   RCC->APB1ENR  |=  RCC_APB1ENR_TIM2EN;    /* 1: TIM2 clock enable    */
    RCC->APB1RSTR |=  RCC_APB1RSTR_TIM2RST;  /* 1: TIM2 clock reset     */
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM2RST;  /* 0: TIM2 reset stop      */
    TIM2->CR1      =  0;                     /* TIM2 control register 1 */
    TIM2->CR2      =  0;                     /* TIM2 control register 2 */
    TIM2->SMCR     =  0;                     /* TIM2 slave mode control */
    TIM2->DIER     =  0;                     /* TIM2 DMA/Interrupt en   */
    TIM2->SR       =  0;                     /* TIM2 status register    */
    TIM2->EGR      =  0;                     /* TIM2 event generation   */
    TIM2->CCMR1    =  0;                     /* Capture/compare mode 1  */
    TIM2->CCMR2    =  0;                     /* Capture/compare mode 2  */
    TIM2->CCER     =  0;                     /* Capture/compare enable  */
    TIM2->CNT      =  0;                     /* TIM2 counter            */
    TIM2->PSC      =  71;                    /* TIM2 prescaler          */
    TIM2->ARR      =  0xFFFF;                /* TIM2 auto-reload        */
    TIM2->RCR      =  0;                     /* TIM2 control register 1 */
    TIM2->CCR1     =  0;                     /* Capture/compare reg 1   */
    TIM2->CCR2     =  0;                     /* Capture/compare reg 2   */
    TIM2->CCR3     =  0;                     /* Capture/compare reg 3   */
    TIM2->CCR4     =  0;                     /* Capture/compare reg 4   */
    TIM2->BDTR     =  0;                     /* break and dead-time     */
    TIM2->DCR      =  0;                     /* DMA control register    */
    TIM2->DMAR     =  0;                     /* DMA address for full tr */
}

/* ******************************************************************** */
/*                        XIOInitTim2HardPrdIn()                        */
/* ******************************************************************** */
void XIOInitTim2HardPrdIn (void)
{   XIOConfigGPIO(GPIOA, XIO_PT_BT0, XIO_PT_GPI_FLOAT, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOB, XIO_PT_BT1, XIO_PT_GPI_FLOAT, XIO_PT_SET_0);
    TIM2->CCMR1   |=  TIM_CCMR1_CC1S_0       /* 01: CC1 as input        */
                  |   TIM_CCMR1_IC1F_0       /* 0011: fSAMPLING =       */
                  |   TIM_CCMR1_IC1F_1       /* fCK_INT, N = 8          */
                  |   TIM_CCMR1_CC2S_0       /* 01: CC2 as input        */
                  |   TIM_CCMR1_IC2F_0       /* 0011: fSAMPLING =       */
                  |   TIM_CCMR1_IC2F_1;      /* fCK_INT, N = 8          */
    TIM2->CCER    |=  TIM_CCER_CC1E          /* IC1 enable              */
                  |   TIM_CCER_CC2E;         /* IC2 enable              */
    TIM2->DIER    |=  TIM_DIER_CC1IE         /* CC1 interrupt enable    */
                  |   TIM_DIER_CC2IE;        /* CC2 interrupt enable    */
    TIM2->SR      &= ~TIM_SR_CC1IF           /* Clr CC1 interrupt Flag  */
                  &  ~TIM_SR_CC2IF;          /* Clr CC2 interrupt Flag  */
    TIM2->CR1     |=  TIM_CR1_CEN;           /* 1: Counter enabled      */
    TIM2->EGR      =  TIM_EGR_UG;            /* UG: Update generation   */
}

/* ******************************************************************** */
/*                         XIOInitTim3()                                */
/* ******************************************************************** */
void XIOInitTim3 (void)
{   RCC->APB1ENR  |=  RCC_APB1ENR_TIM3EN;    /* 1: TIM3 clock enable    */
    RCC->APB1RSTR |=  RCC_APB1RSTR_TIM3RST;  /* 1: TIM3 clock reset     */
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM3RST;  /* 0: TIM3 reset stop      */
    TIM3->CR1      =  0;                     /* TIM3 control register 1 */
    TIM3->CR2      =  0;                     /* TIM3 control register 2 */
    TIM3->SMCR     =  0;                     /* TIM3 slave mode control */
    TIM3->DIER     =  0;                     /* TIM3 DMA/Interrupt en   */
    TIM3->SR       =  0;                     /* TIM3 status register    */
    TIM3->EGR      =  0;                     /* TIM3 event generation   */
    TIM3->CCMR1    =  0;                     /* Capture/compare mode 1  */
    TIM3->CCMR2    =  0;                     /* Capture/compare mode 2  */
    TIM3->CCER     =  0;                     /* Capture/compare enable  */
    TIM3->CNT      =  0;                     /* TIM3 counter            */
    TIM3->PSC      =  71;                    /* TIM3 prescaler          */
    TIM3->ARR      =  0xFFFF;                /* TIM3 auto-reload        */
    TIM3->RCR      =  0;                     /* TIM3 control register 1 */
    TIM3->CCR1     =  0;                     /* Capture/compare reg 1   */
    TIM3->CCR2     =  0;                     /* Capture/compare reg 2   */
    TIM3->CCR3     =  0;                     /* Capture/compare reg 3   */
    TIM3->CCR4     =  0;                     /* Capture/compare reg 4   */
    TIM3->BDTR     =  0;                     /* break and dead-time     */
    TIM3->DCR      =  0;                     /* DMA control register    */
    TIM3->DMAR     =  0;                     /* DMA address for full tr */
}

/* ******************************************************************** */
/*                         XIOInitTim3SpeedIn()                         */
/* ******************************************************************** */
void XIOInitTim3SpeedIn (void)
{   XIOConfigGPIO(GPIOA, XIO_PT_BT0, XIO_PT_GPI_FLOAT, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOB, XIO_PT_BT1, XIO_PT_GPI_FLOAT, XIO_PT_SET_0);
    TIM3->CCMR1   |=  TIM_CCMR1_CC1S_0       /* 01: CC1 as input        */
                  |   TIM_CCMR1_IC1F_0       /* 0011: fSAMPLING =       */
                  |   TIM_CCMR1_IC1F_1       /* fCK_INT, N = 8          */
                  |   TIM_CCMR1_CC2S_0       /* 01: CC2 as input        */
                  |   TIM_CCMR1_IC2F_0       /* 0011: fSAMPLING =       */
                  |   TIM_CCMR1_IC2F_1;      /* fCK_INT, N = 8          */
    TIM3->CCER    |=  TIM_CCER_CC1E          /* IC1 enable              */
                  |   TIM_CCER_CC2E;         /* IC2 enable              */
    TIM3->DIER    |=  TIM_DIER_CC1IE         /* CC1 interrupt enable    */
                  |   TIM_DIER_CC2IE;        /* CC2 interrupt enable    */
    TIM3->SR      &= ~TIM_SR_CC1IF           /* Clr CC1 interrupt Flag  */
                  &  ~TIM_SR_CC2IF;          /* Clr CC2 interrupt Flag  */
    TIM3->CR1     |=  TIM_CR1_CEN;           /* 1: Counter enabled      */
    TIM3->EGR      =  TIM_EGR_UG;            /* UG: Update generation   */
}

/* ******************************************************************** */
/*                         XIOInitTim4()                                */
/* ******************************************************************** */
void XIOInitTim4 (void)
{   RCC->APB1ENR  |=  RCC_APB1ENR_TIM4EN;    /* 1: TIM4 clock enable    */
    RCC->APB1RSTR |=  RCC_APB1RSTR_TIM4RST;  /* 1: TIM4 clock reset     */
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM4RST;  /* 0: TIM4 reset stop      */
    TIM4->CR1      =  0;                     /* TIM4 control register 1 */
    TIM4->CR2      =  0;                     /* TIM4 control register 2 */
    TIM4->SMCR     =  0;                     /* TIM4 slave mode control */
    TIM4->DIER     =  0;                     /* TIM4 DMA/Interrupt en   */
    TIM4->SR       =  0;                     /* TIM4 status register    */
    TIM4->EGR      =  0;                     /* TIM4 event generation   */
    TIM4->CCMR1    =  0;                     /* Capture/compare mode 1  */
    TIM4->CCMR2    =  0;                     /* Capture/compare mode 2  */
    TIM4->CCER     =  0;                     /* Capture/compare enable  */
    TIM4->CNT      =  0;                     /* TIM4 counter            */
    TIM4->PSC      =  71;                    /* TIM4 prescaler          */
    TIM4->ARR      =  0xFFFF;                /* TIM4 auto-reload        */
    TIM4->RCR      =  0;                     /* TIM4 control register 1 */
    TIM4->CCR1     =  0;                     /* Capture/compare reg 1   */
    TIM4->CCR2     =  0;                     /* Capture/compare reg 2   */
    TIM4->CCR3     =  0;                     /* Capture/compare reg 3   */
    TIM4->CCR4     =  0;                     /* Capture/compare reg 4   */
    TIM4->BDTR     =  0;                     /* break and dead-time     */
    TIM4->DCR      =  0;                     /* DMA control register    */
    TIM4->DMAR     =  0;                     /* DMA address for full tr */
}

/* ******************************************************************** */
/*                         XIOInitTim4Pwm()                             */
/* ******************************************************************** */
void XIOInitTim4Pwm (void)
{   XIOConfigGPIO(GPIOA, XIO_PT_BT0, XIO_PT_ALT_PP, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOB, XIO_PT_BT1, XIO_PT_ALT_PP, XIO_PT_SET_0);
    TIM4->CR1     |=  TIM_CR1_ARPE;          /* 1: ARR preload enable   */
    TIM4->CCMR1   |=  TIM_CCMR1_OC1M_2       /* CH1: 110, PWM mode 1    */
                  |   TIM_CCMR1_OC1M_1       /* (111: PWM mode 2)       */
                  |   TIM_CCMR1_OC1PE        /* OC1 preload enabled     */
                  |   TIM_CCMR1_OC2M_2       /* CH2: 110, PWM mode 1    */
                  |   TIM_CCMR1_OC2M_1       /* (111: PWM mode 2)       */
                  |   TIM_CCMR1_OC2PE;       /* OC2 preload enabled     */
    TIM4->CCER    |=  TIM_CCER_CC1E          /* OC1 signal is output    */
                  |   TIM_CCER_CC2E;         /* OC2 signal is output    */
    TIM4->ARR      =  XIO_PWM_PERIOD_DEF;    /* Pwm Period              */
    TIM4->CCR1     =  0;                     /* PWM Duty 1              */
    TIM4->CCR2     =  0;                     /* PWM Duty 2              */
    TIM4->SR       =  0;                     /* Clear all flags         */
    TIM4->EGR      =  TIM_EGR_UG;            /* UG: Update generation   */
    while ((TIM4->EGR & TIM_EGR_UG) != 0);   /* Wait for UG Clear       */
    TIM4->CR1     |=  TIM_CR1_CEN;           /* 1: Counter enabled      */
}

/* ******************************************************************** */
/*                          XIOUpdateTim4Pwm()                          */
/* ******************************************************************** */
void XIOUpdateTim4Pwm (INT08U ucChan, INT16U usPeriod, INT16U usDuty)
{   TIM4->ARR = usPeriod;
    if (ucChan == 1)
    {   TIM4->CCR1 = usDuty;
    }   else if (ucChan == 2)
    {   TIM4->CCR2 = usDuty;
    }   else if (ucChan == 3)
    {   TIM4->CCR3 = usDuty;
    }   else if (ucChan == 4)
    {   TIM4->CCR4 = usDuty;
    }
    TIM4->EGR = TIM_EGR_UG;
}

/* ******************************************************************** */
/*                           XIOResetGPIO()                             */
/* ******************************************************************** */
void XIOResetGPIO (GPIO_TypeDef *pPt)          //复位通用口
{   if (pPt == GPIOA)
    {   RCC->APB2ENR  |=  RCC_APB2ENR_IOPAEN;
        RCC->APB2RSTR |=  RCC_APB2RSTR_IOPARST;
        RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPARST;
    }   else if (pPt ==  GPIOB)
    {   RCC->APB2ENR  |=  RCC_APB2ENR_IOPBEN;
        RCC->APB2RSTR |=  RCC_APB2RSTR_IOPBRST;
        RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPBRST;
    }   else if (pPt ==  GPIOC)
    {   RCC->APB2ENR  |=  RCC_APB2ENR_IOPCEN;
        RCC->APB2RSTR |=  RCC_APB2RSTR_IOPCRST;
        RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPCRST;
    }   else if (pPt ==  GPIOD)
    {   RCC->APB2ENR  |=  RCC_APB2ENR_IOPDEN;
        RCC->APB2RSTR |=  RCC_APB2RSTR_IOPDRST;
        RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPDRST;
    }   else if (pPt ==  GPIOE)
    {   RCC->APB2ENR  |=  RCC_APB2ENR_IOPEEN;
        RCC->APB2RSTR |=  RCC_APB2RSTR_IOPERST;
        RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPERST;
    }
   #ifdef RCC_APB2ENR_IOPFEN
    else if (pPt == GPIOF)
    {   RCC->APB2ENR  |=  RCC_APB2ENR_IOPFEN;
        RCC->APB2RSTR |=  RCC_APB2RSTR_IOPFRST;
        RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPFRST;
    }
   #endif
   #ifdef RCC_APB2ENR_IOPGEN
    else if (pPt == GPIOG)
    {   RCC->APB2ENR  |=  RCC_APB2ENR_IOPGEN;
        RCC->APB2RSTR |=  RCC_APB2RSTR_IOPGRST;
        RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPGRST;
    }
   #endif
}

/* ******************************************************************** */
/*                           XIOConfigGPIO()                            */
/* ******************************************************************** */
void XIOConfigGPIO (GPIO_TypeDef *pPt, INT08U ucBit, INT32U uiMod, INT16U usSet)
{   if (pPt == GPIOA)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; //IO端口A时钟使能
    }   else if (pPt == GPIOB)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; //IO端口B时钟使能
    }   else if (pPt == GPIOC)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; //IO端口C时钟使能
    }   else if (pPt == GPIOD)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPDEN; //IO端口D时钟使能
    }   else if (pPt == GPIOE)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPEEN; //IO端口E时钟使能
    }
   #ifdef RCC_APB2ENR_IOPFEN
    else if (pPt == GPIOF)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPFEN; //IO端口F时钟使能
    }
   #endif
   #ifdef RCC_APB2ENR_IOPGEN
    else if (pPt == GPIOG)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPGEN;//IO端口G时钟使能
    }
   #endif
    else
    {   return;
    }
    if (usSet    ==  0)
    {   pPt->BRR  = (INT32U)0x01 << ucBit;
    }   else
    {   pPt->BSRR = (INT32U)0x01 << ucBit;
    }
    uiMod        &= (INT32U)0x0F;
    ucBit        *=  4;
    if (ucBit    <=  31)
    {   pPt->CRL &= ~((INT32U)0x0F << ucBit);
        pPt->CRL |=  uiMod << ucBit;
    }   else if (ucBit <= 63)
    {   ucBit    -=  32;
        pPt->CRH &= ~((INT32U)0x0F << ucBit);
        pPt->CRH |=  uiMod << ucBit;
    }
}

/* ******************************************************************** */
/*                           XIOConfigAFIO()                            */
/* ******************************************************************** */
void XIOConfigAFIO (INT32U uiRemap)
{   INT32U uiTmp, uiReg;
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
    if ((uiRemap & 0x80000000) != 0)
    {   uiReg  = AFIO->MAPR2;
    }   else
    {   uiReg  = AFIO->MAPR;
    }
    uiTmp = uiRemap & 0x0000FFFF;
    if ((uiRemap & 0x00300000) == 0x00300000)
    {   uiReg &= ~0x0F000000;
        AFIO->MAPR &= ~0x0F000000;
    }
    else if ((uiRemap & 0x00100000) != 0)
    {   uiReg &= ~((INT32U)0x03 << ((uiRemap >> 16) & 0x0F));
        uiReg |=  0x0F000000;
    }
    else
    {   uiReg &= ~(uiTmp << ((uiRemap >> 21) * 16));
        uiReg |=  0x0F000000;
    }
    uiReg |= (uiTmp << ((uiRemap >> 21) * 16));
    if ((uiRemap & 0x80000000) != 0)
    {   AFIO->MAPR2 = uiReg;
    }   else
    {   AFIO->MAPR  = uiReg;
    }
}

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
