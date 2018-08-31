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
File        : 320_Overview_Barrel.c
Content     : Bitmap 37 * 49
---------------------------END-OF-HEADER------------------------------
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif


static GUI_CONST_STORAGE unsigned short ac320_Overview_Barrel[] = {
  0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x6319, 0x6319, 0x4A32, 0x4A32, 0x4A32, 0x4211, 0x2D6E, 0x2D6E, 0x2D6E, 0x2D6E, 0x35AF, 0x4A32, 0x4A32, 0x4A32, 0x4E73, 0x6319, 0x6B5A, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 
        0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x6319, 0x39CF, 0x20E9, 0x1087, 0x1087, 0x1087, 0x1489, 0x1489, 0x14A9, 0x14A9, 0x14A9, 0x14A9, 0x14A9, 0x14A9, 0x14A9, 0x14A9, 0x1489, 0x14A9, 0x1488, 0x1087, 0x1087, 0x1086, 0x252C, 0x4210, 0x739C, 
        0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x56B5, 0x14A9, 0x1488, 0x1489, 0x18AC, 0x18AD, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x14AB, 0x1087, 0x14AA, 0x18C9, 
        0x6319, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x5EF7, 0x1064, 0x1085, 0x1087, 0x1087, 0x14A9, 0x1489, 0x14A9, 0x14A9, 0x14AB, 0x18AC, 0x18AC, 0x18AC, 0x18AC, 0x18AC, 0x18AC, 0x18AC, 0x18AC, 0x18AC, 0x14AA, 0x14A9, 0x14A9, 0x1489, 0x1489, 0x1087, 0x1087, 0x1085, 
        0x14A6, 0x739C, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x7FFF, 0x7BDE, 0x14A6, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1087, 0x1087, 0x14A9, 0x1488, 0x1087, 0x1489, 0x14A9, 0x14A9, 0x14A9, 0x14A9, 0x14A9, 0x1488, 0x1087, 0x1489, 0x1489, 0x1087, 0x1086, 0x1064, 0x1064, 0x1064, 0x1064, 
        0x1064, 0x2D4B, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x7FFF, 0x4632, 0x1087, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 
        0x1064, 0x1087, 0x6319, 0x7FFF, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x7FFF, 0x18CA, 0x18CF, 0x18AD, 0x14A9, 0x1086, 0x1085, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1085, 0x1087, 0x14AA, 
        0x18CD, 0x18CF, 0x358E, 0x7FFF, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x56B5, 0x18AC, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CD, 0x18AC, 0x14AA, 0x14AB, 0x14A9, 0x14A9, 0x14A9, 0x14A9, 0x1488, 0x14A9, 0x14A9, 0x14A9, 0x14A9, 0x18AC, 0x14AA, 0x18AC, 0x18CE, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 
        0x18CF, 0x18CF, 0x14A9, 0x739C, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x358E, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 
        0x18CF, 0x18CF, 0x18CD, 0x4E73, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x1489, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CD, 0x18CD, 
        0x18CF, 0x18CF, 0x18CF, 0x2D6D, 0x7FFF, 0x7FFF,
  0x7FFF, 0x5EF7, 0x14AB, 0x18CF, 0x18CF, 0x18AD, 0x18CE, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 
        0x18CF, 0x18CF, 0x18CF, 0x1489, 0x7BDE, 0x7FFF,
  0x7FFF, 0x4A32, 0x18CE, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 
        0x18CF, 0x18CF, 0x18CF, 0x14AB, 0x6319, 0x7FFF,
  0x7FFF, 0x2D6D, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 
        0x18CF, 0x18CF, 0x18CF, 0x18CE, 0x4A32, 0x7FFF,
  0x7FFF, 0x18CA, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 
        0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x358E, 0x7FFF,
  0x739C, 0x14AA, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CE, 
        0x18AD, 0x18CF, 0x18CF, 0x18CF, 0x210B, 0x7FFF,
  0x6319, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AD, 0x18CE, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 
        0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x14A9, 0x7FFF,
  0x4E73, 0x14AB, 0x18CF, 0x18CF, 0x18AD, 0x18CE, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 
        0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x1489, 0x6B5A,
  0x4A32, 0x1064, 0x1086, 0x14A9, 0x14A9, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CE, 
        0x14AA, 0x14AB, 0x1489, 0x1085, 0x1064, 0x6319,
  0x4210, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1086, 0x1087, 0x1086, 0x1087, 0x14A9, 0x14A9, 0x14A9, 0x14A9, 0x14A9, 0x14A9, 0x1488, 0x14A9, 0x14A9, 0x14A9, 0x14A9, 0x14A9, 0x14A9, 0x1086, 0x1087, 0x1087, 0x1085, 0x1064, 0x1064, 
        0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x5EF7,
  0x2D4B, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 
        0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x4A32,
  0x2D6C, 0x1087, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 
        0x1064, 0x1064, 0x1064, 0x1085, 0x1488, 0x4A32,
  0x2D6E, 0x18CF, 0x18CF, 0x18AC, 0x1489, 0x14A9, 0x1488, 0x1087, 0x1087, 0x1085, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1086, 0x1087, 0x1087, 0x1489, 
        0x1488, 0x14AB, 0x18AD, 0x18CF, 0x18CF, 0x4A32,
  0x2D6E, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AD, 0x18AC, 0x18AC, 0x14AA, 0x18AC, 0x18AC, 0x18CD, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 
        0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x4A32,
  0x2D6E, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 
        0x18AD, 0x18CE, 0x18CF, 0x18CF, 0x18CF, 0x4A32,
  0x2D6E, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 
        0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x318D,
  0x2D6E, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 
        0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x4A32,
  0x2D6E, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 
        0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x4A32,
  0x2D6E, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 
        0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x4A32,
  0x2D6E, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 
        0x18AD, 0x18CE, 0x18CF, 0x18CF, 0x18CF, 0x4A32,
  0x2D6D, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 
        0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CE, 0x4A32,
  0x39CE, 0x1085, 0x1489, 0x14AB, 0x14AA, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 
        0x18AC, 0x18AC, 0x14AA, 0x1488, 0x1085, 0x56B5,
  0x4A32, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1087, 0x1087, 0x1087, 0x1488, 0x14A9, 0x14A9, 0x14A9, 0x14A9, 0x14AB, 0x18AC, 0x18AC, 0x14AA, 0x18AC, 0x18AC, 0x14AA, 0x14A9, 0x14A9, 0x14A9, 0x1488, 0x1489, 0x1087, 0x1087, 0x1086, 0x1064, 
        0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x6319,
  0x4A32, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 
        0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x6319,
  0x6319, 0x1086, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 
        0x1064, 0x1064, 0x1064, 0x1085, 0x1085, 0x7FFF,
  0x6B5A, 0x14AB, 0x18CE, 0x18AC, 0x1488, 0x1489, 0x1087, 0x1087, 0x1085, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1085, 0x1087, 0x1087, 
        0x1488, 0x14AA, 0x18AC, 0x18CF, 0x18CA, 0x7FFF,
  0x7FFF, 0x1489, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18AC, 0x18AC, 0x18AC, 0x18AC, 0x18AC, 0x18AC, 0x14AA, 0x18AC, 0x18AC, 0x18AC, 0x18AC, 0x18AC, 0x18AD, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 
        0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x2D6D, 0x7FFF,
  0x7FFF, 0x2D6E, 0x18CF, 0x18CF, 0x18AD, 0x18CE, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 
        0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x4210, 0x7FFF,
  0x7FFF, 0x4210, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CE, 
        0x18AD, 0x18CF, 0x18CF, 0x18AC, 0x5EF7, 0x7FFF,
  0x7FFF, 0x56B5, 0x18AD, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CE, 0x18AD, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 
        0x18CF, 0x18CF, 0x18CF, 0x14AA, 0x739C, 0x7FFF,
  0x7FFF, 0x739C, 0x14A9, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CD, 0x18CD, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 
        0x18CF, 0x18CF, 0x18CF, 0x210A, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x252B, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 
        0x18CF, 0x18CF, 0x18CE, 0x4210, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x4E73, 0x18CD, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 
        0x18CF, 0x18CF, 0x14AB, 0x6B5A, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x739C, 0x1489, 0x18CF, 0x18CE, 0x18AD, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 
        0x18CF, 0x18CF, 0x20E9, 0x7FFF, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x7FFF, 0x39CF, 0x18CE, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 
        0x18CF, 0x18AC, 0x56B5, 0x7FFF, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x7FFF, 0x739C, 0x1488, 0x18CE, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 
        0x18CD, 0x20E9, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x4632, 0x1064, 0x1086, 0x14A9, 0x14AB, 0x18AC, 0x18CF, 0x18CE, 0x18AD, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18CF, 0x18AC, 0x18CF, 0x18CE, 0x18AC, 0x14AB, 0x1087, 0x1086, 
        0x1064, 0x6319, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x2D4B, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1085, 0x1087, 0x1087, 0x1087, 0x1087, 0x1087, 0x1086, 0x1087, 0x1087, 0x1087, 0x1087, 0x1086, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 
        0x4632, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x4632, 0x1CE7, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x2529, 0x5EF7, 
        0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
  0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x739C, 0x5EF7, 0x4A32, 0x39CE, 0x2D4B, 0x2D4B, 0x2529, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x1064, 0x14A6, 0x2D4B, 0x2D4B, 0x2D4B, 0x4210, 0x4A32, 0x6319, 0x7BDE, 0x7FFF, 0x7FFF, 
        0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF
};

extern GUI_CONST_STORAGE GUI_BITMAP bm320_Overview_Barrel;

GUI_CONST_STORAGE GUI_BITMAP bm320_Overview_Barrel = {
  37, /* XSize */
  49, /* YSize */
  74, /* BytesPerLine */
  16, /* BitsPerPixel */
  (unsigned char *)ac320_Overview_Barrel,  /* Pointer to picture data */
  NULL  /* Pointer to palette */
 ,GUI_DRAW_BMP555
};

/*************************** End of file ****************************/
