#ifndef __USART_H
#define __USART_H


#include <stm32f10x.h>

/* ʹ���жϽ��� */
#define USE_RX_INTERRUPT
/* ���ʹ��printf��� */
#define USE_PRINTF

#ifdef USE_PRINTF
#include<stdio.h>
int fputc(int ch, FILE *f);
#endif


/* ����ȫ�ֺ��� */
void USART1_Config(uint16_t baudRate);
void USART1_SendWord(uint8_t *wd);











































#endif
