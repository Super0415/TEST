#include "dido.h"

void hrddido_init(void)
{
  
hrdCONFIG_DIDO();
}

void refreshdido(void)
{
   DI[0]=!BIN00;
   DI[1]=!BIN01;
   DI[2]=!BIN02;
   DI[3]=!BIN03;
   DI[4]=!BIN04;
   DI[5]=!BIN05;
   DI[6]=!BIN06;   

   DI[7]=!BIN07;
   DI[8]=!BIN08;
   DI[9]=!BIN09;
   DI[10]=!BIN10;

   BOUT00=DO[0];
   BOUT01=DO[1];
   BOUT02=DO[2];
   BOUT03=DO[3];
   BOUT04=DO[4];
   BOUT05=DO[5];
   BOUT06=DO[6];

   BOUT07=DO[7];
   BOUT08=DO[8];
   BOUT09=DO[9];
   BOUT10=DO[10];
   BOUT11=DO[11];
   BOUT12=DO[12];
   BOUT13=DO[13]; 

   
    if(DO[0] == 1)
    {
        OUTPUTVALUE |= 1;
    }
    else
    {
        OUTPUTVALUE &= ~1;
    }
    if (DO[1] == 1)
    {
        OUTPUTVALUE |= 2;
    }
    else
    {
        OUTPUTVALUE &= ~2;
    }
    if (DO[2] == 1)
    {
        OUTPUTVALUE |= 4;
    }
    else
    {
        OUTPUTVALUE &= ~4;
    }
    if (DO[3] == 1)
    {
        OUTPUTVALUE |= 8;
    }
    else
    {
        OUTPUTVALUE &= ~8;
    }
    if (DO[4] == 1)
    {
        OUTPUTVALUE |= 16;
    }
    else
    {
        OUTPUTVALUE &= ~16;
    }
    if (DO[5] == 1)
    {
        OUTPUTVALUE |= 32;
    }
    else
    {
        OUTPUTVALUE &= ~32;
    }
    if (DO[6] == 1)
    {
        OUTPUTVALUE |= 64;
    }
    else
    {
        OUTPUTVALUE &= ~64;
    }
        if (DO[7] == 1)
    {
        OUTPUTVALUE |= 128;
    }
    else
    {
        OUTPUTVALUE &= ~128;
    }
        if (DO[8] == 1)
    {
        OUTPUTVALUE |= 256;
    }
    else
    {
        OUTPUTVALUE &= ~256;
    }
        if (DO[9] == 1)
    {
        OUTPUTVALUE |= 512;
    }
    else
    {
        OUTPUTVALUE &= ~512;
    }
        if (DO[10] == 1)
    {
        OUTPUTVALUE |= 1024;
    }
    else
    {
        OUTPUTVALUE &= ~1024;
    }
        if (DO[11] == 1)
    {
        OUTPUTVALUE |= 2048;
    }
    else
    {
        OUTPUTVALUE &= ~2048;
    }
        if (DO[12] == 1)
    {
        OUTPUTVALUE |= 4096;
    }
    else
    {
        OUTPUTVALUE &= ~4096;
    }
        if (DO[13] == 1)
    {
        OUTPUTVALUE |= 8192;
    }
    else
    {
        OUTPUTVALUE &= ~8192;
    }
    
      if (DI[0] == 1)
    {
        INPUTVALUE |= 1;
    }
    else
    {
        INPUTVALUE &= ~1;
    }
    if (DI[1] == 1)
    {
        INPUTVALUE |= 2;
    }
    else
    {
        INPUTVALUE &= ~2;
    }
    if (DI[2] == 1)
    {
        INPUTVALUE |= 4;
    }
    else
    {
        INPUTVALUE &= ~4;
    }
    if (DI[3] == 1)
    {
        INPUTVALUE |= 8;
    }
    else
    {
        INPUTVALUE &= ~8;
    }
    if (DI[4] == 1)
    {
        INPUTVALUE |= 16;
    }
    else
    {
        INPUTVALUE &= ~16;
    }
    if (DI[5] == 1)
    {
        INPUTVALUE |= 32;
    }
    else
    {
        INPUTVALUE &= ~32;
    }
    if (DI[6] == 1)
    {
        INPUTVALUE |= 64;
    }
    else
    {
        INPUTVALUE &= ~64;
    }
    if (DI[7] == 1)
    {
        INPUTVALUE |= 128;
    }
    else
    {
        INPUTVALUE &= ~128;
    }
        if (DI[8] == 1)
    {
        INPUTVALUE |= 256;
    }
    else
    {
        INPUTVALUE &= ~256;
    }
        if (DI[9] == 1)
    {
        INPUTVALUE |= 512;
    }
    else
    {
        INPUTVALUE &= ~512;
    }
        if (DI[10] == 1)
    {
        INPUTVALUE |= 1024;
    }
    else
    {
        INPUTVALUE &= ~1024;
    }

   
}