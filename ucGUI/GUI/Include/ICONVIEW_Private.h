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
File        : ICONVIEW_Private.h
Purpose     : ICONVIEW private header file
--------------------END-OF-HEADER-------------------------------------
*/

#ifndef ICONVIEW_PRIVATE_H
#define ICONVIEW_PRIVATE_H

#include "WM.h"
#include "GUI_ARRAY.h"
#include "ICONVIEW.h"

#if GUI_WINSUPPORT

/*********************************************************************
*
*       Types
*
**********************************************************************
*/
typedef struct {
  const GUI_FONT * pFont;
  GUI_COLOR        aBkColor[3];
  GUI_COLOR        aTextColor[3];
  int              FrameX, FrameY;
  int              SpaceX, SpaceY;
  int              TextAlign;
  int              IconAlign;
  GUI_WRAPMODE     WrapMode;
} ICONVIEW_PROPS;

typedef struct {
  WIDGET          Widget;
  WM_SCROLL_STATE ScrollStateV;
  WM_SCROLL_STATE ScrollStateH;
  ICONVIEW_PROPS  Props;
  GUI_ARRAY       ItemArray;
  int             xSizeItems;
  int             ySizeItems;
  int             Sel;
  U16             Flags;
  /* Type check in debug version */
  #if GUI_DEBUG_LEVEL >= GUI_DEBUG_LEVEL_CHECK_ALL
    U32 DebugId;
  #endif  
} ICONVIEW_OBJ;

typedef void tDrawImage    (const void * pData, int xPos, int yPos);
typedef void tDrawText     (ICONVIEW_OBJ * pObj, GUI_RECT * pRect, const char * s);
typedef void tGetImageSizes(const void * pData, int * xSize, int * ySize);

typedef struct {
  tDrawImage     * pfDrawImage;
  tDrawText      * pfDrawText;
  tGetImageSizes * pfGetImageSizes;
  const void     * pData;
  U32              UserData;
  int              SizeofData;
  char             acText[1];
} ICONVIEW_ITEM;

/*********************************************************************
*
*       Function pointer(s)
*
**********************************************************************
*/
extern void (* ICONVIEW__pfDrawStreamedBitmap)(const void * p, int x, int y);

/*********************************************************************
*
*       Macros for internal use
*
**********************************************************************
*/
#if GUI_DEBUG_LEVEL >= GUI_DEBUG_LEVEL_CHECK_ALL
  #define ICONVIEW_INIT_ID(p) (p->DebugId = ICONVIEW_ID)
#else
  #define ICONVIEW_INIT_ID(p)
#endif

#if GUI_DEBUG_LEVEL >= GUI_DEBUG_LEVEL_CHECK_ALL
  ICONVIEW_OBJ * ICONVIEW_LockH(ICONVIEW_Handle h);
  #define ICONVIEW_LOCK_H(h)   ICONVIEW_LockH(h)
#else
  #define ICONVIEW_LOCK_H(h)   (ICONVIEW_OBJ *)GUI_LOCK_H(h)
#endif

#endif   /* GUI_WINSUPPORT */
#endif   /* ICONVIEW_H */

/*************************** End of file ****************************/
