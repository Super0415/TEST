/*
*********************************************************************************************************
*                                             uC/GUI V5.24
*                        Universal graphic software for embedded applications
*
*                       (c) Copyright 2014, Micrium Inc., Weston, FL
*                       (c) Copyright 2014, SEGGER Microcontroller GmbH & Co. KG
*
*              �C/GUI is protected by international copyright laws. Knowledge of the
*              source code may not be used to write a similar product. This file may
*              only be used in accordance with a license and should not be redistributed
*              in any way. We appreciate your understanding and fairness.
*
----------------------------------------------------------------------
File        : WinMain.c
---------------------------END-OF-HEADER------------------------------
*/

#include <windows.h>

#include "GUI_SIM_Win32.h"

/*********************************************************************
*
*       Public data
*
**********************************************************************
*/

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       WinMain
*/
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,  LPSTR lpCmdLine, int nCmdShow) {
  return SIM_GUI_App(hInstance, hPrevInstance,  lpCmdLine, nCmdShow);
}

/*************************** End of file ****************************/
