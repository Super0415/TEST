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
File        : BitmapBar.c
Purpose     : Sample bitmap for checkbox 11x11
----------------------------------------------------------------------
*/

#include "GUI.h"
#include "Main.h"

/* Colors */
static const GUI_COLOR _aColorDisabled[] = {0x808080, 0x101010};
static const GUI_COLOR _aColorEnabled[]  = {GUI_WHITE, GUI_BLACK};

/* Palettes */
static const GUI_LOGPALETTE _PalCheckDisabled = {
  2,	/* number of entries */
  1, 	/* transparency flag */
  _aColorDisabled
};

static const GUI_LOGPALETTE _PalCheckEnabled = {
  2,	/* number of entries */
  1, 	/* transparency flag */
  _aColorEnabled
};

/* Pixel data */
static const unsigned char _acBar[] = {
  ________, ________,
  ________, ________,
  ________, ________,
  ________, ________,
  ________, ________,
  __XXXXXX, X_______,
  __XXXXXX, X_______,
  ________, ________,
  ________, ________,
  ________, ________,
  ________, ________,
};

/* Bitmaps */
const GUI_BITMAP _abmBar[2] = {
  { 11, 11, 2, 1, _acBar, &_PalCheckDisabled },
  { 11, 11, 2, 1, _acBar, &_PalCheckEnabled },
};

/*************************** End of file ****************************/
