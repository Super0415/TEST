#ifndef	_BTN_H
#define	_BTN_H
PUBLIC volatile FLAGSTR  FLAG_BTN;
#define F_BTN_ON_OFF_EN       FLAG_BTN.Bits.bit0
#define F_BTN_ON_OFF_GE				FLAG_BTN.Bits.bit1
#define F_BTN_PAGE_UP        	FLAG_BTN.Bits.bit2
#define F_BTN_PAGE       			FLAG_BTN.Bits.bit3
#define F_BTN_PAGE_DOWN      	FLAG_BTN.Bits.bit4
#define F_BTN_START      			FLAG_BTN.Bits.bit5
#define F_BTN_FAULT_RESET     FLAG_BTN.Bits.bit6
#define F_BTN_STOP      			FLAG_BTN.Bits.bit7
#define F_BTN_ENTER     			FLAG_BTN.Bits.bit8
#define F_BTN_HORN_RESET     	FLAG_BTN.Bits.bit9
#define F_BTN_MODE_LEFT     	FLAG_BTN.Bits.bita
#define F_BTN_MODE_RIGHT      FLAG_BTN.Bits.bitb
#define F_BTN_PAGE_ENTER      FLAG_BTN.Bits.bitc
#define F_BTN_LEFT_RIGHT      FLAG_BTN.Bits.bitd

PUBLIC uint  btn_buf;

PUBLIC void btn_process(void);
#endif
