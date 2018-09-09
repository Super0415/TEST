/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File SCI2Cortex.c                       */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   SCI2_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                              SCI2Init ()                             */
/* ******************************************************************** */
#if (SCI2_FUNCTION_ON == 1)
void SCI2Init (void)
{   MODInit();
    SCI2HardInit();
}
#endif

/* ******************************************************************** */
/*                              SCI2Start ()                            */
/* ******************************************************************** */
#if (SCI2_FUNCTION_ON == 1)
void SCI2Start (void)
{   MODStart();
    SCI2_SCI_RX_EN();
    SCI2_SCI_TX_EN();
    SCI2_SCI_RX_INT_EN();
    SCI2_SCI_TC_INT_DIS();
}
#endif

/* ******************************************************************** */
/*                            SCI2TaskLoop ()                           */
/* ******************************************************************** */
#if (SCI2_FUNCTION_ON == 1)
void SCI2TaskLoop (void)
{   MODTaskLoop();
}
#endif

/* ******************************************************************** */
/*                           SCI2TxRxIntHook ()                         */
/* ******************************************************************** */
#if (SCI2_FUNCTION_ON == 1)
void SCI2TxRxIntHook (void)
{   MODTxRxIntHook();
}
#endif

/* ******************************************************************** */
/*                             SCI2HardInit ()                          */
/* ******************************************************************** */
#if (SCI2_FUNCTION_ON == 1)
void SCI2HardInit (void)
{   
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */