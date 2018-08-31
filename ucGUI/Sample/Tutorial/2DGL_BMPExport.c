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
File        : 2DGL_BMPExport.c
Purpose     : Demonstrates the use of GUI_BMP_Serialize
Requirements: WindowManager - ( )
              MemoryDevices - ( )
              AntiAliasing  - ( )
              VNC-Server    - ( )
              PNG-Library   - ( )
              TrueTypeFonts - ( )

              Can be used in a MS Windows environment only!
---------------------------END-OF-HEADER------------------------------
*/

#ifndef SKIP_TEST

#include <windows.h>
#include "GUI.h"

#define FILE_DEST_PATH "C:\\GUI_BMP_Serialize.bmp"

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
static const GUI_POINT _aPointStar[] = {
  {   0, -36 },
  {   8,  -8 },
  {  36,   0 },
  {   8,   8 },
  {   0,  36 },
  {  -8,   8 },
  { -36,   0 },
  {  -8,  -8 }
};

static const GUI_POINT _aPointHexagon[] = {
  {   0, -30 },
  {  26, -15 },
  {  26,  15 },
  {   0,  30 },
  { -26,  15 },
  { -26, -15 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       _DrawSomething
*
* Function description
*   Draws something to LCD
*/
static void _DrawSomething(void) {
  int xSize;
  int ySize;

  xSize = LCD_GetXSize();
  ySize = LCD_GetYSize();
  GUI_SetFont(&GUI_Font24_ASCII);
  GUI_SetTextMode(GUI_TM_TRANS);
  GUI_DispStringHCenterAt("Demo of GUI_BMP_Serialize", xSize / 2, (ySize - GUI_GetFontSizeY()) / 2);
  GUI_SetColor(GUI_GREEN);
  GUI_FillPolygon (&_aPointHexagon[0], GUI_COUNTOF(_aPointHexagon), xSize / 2, ySize / 5);
  GUI_SetColor(GUI_RED);
  GUI_FillPolygon (&_aPointStar[0],    GUI_COUNTOF(_aPointStar),    xSize / 2, ySize / 5 * 4);
}

/*********************************************************************
*
*       _WriteByte2File
*
* Function description
*   This function will be called by GUI_BMP_Serialize to write the
*   bytes to the file
*/
static void _WriteByte2File(U8 Data, void * p) {
  U32 nWritten;

  WriteFile(*((HANDLE *)p), &Data, 1, &nWritten, NULL);
}

/*********************************************************************
*
*       _ExportToFile
*
* Function description
*   Demonstrates the use of GUI_BMP_Serialize
*/
static void _ExportToFile(void) {
  HANDLE hFile;

  hFile = CreateFile(FILE_DEST_PATH, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
  GUI_BMP_Serialize(_WriteByte2File, &hFile);
  CloseHandle(hFile);
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MainTask
*/
void MainTask(void) {
  int xSize;
  int ySize;

  GUI_Init();
  _DrawSomething();
  _ExportToFile();
  GUI_Delay(500);
  GUI_Clear();
  xSize = LCD_GetXSize();
  ySize = LCD_GetYSize();
  GUI_SetColor(0xF06060);
  GUI_DispStringHCenterAt("The image was stored in\n " FILE_DEST_PATH, xSize >> 1, ySize >> 1);
  while (1) {
    GUI_Delay(200);
  }
}

#endif

/*************************** End of file ****************************/
