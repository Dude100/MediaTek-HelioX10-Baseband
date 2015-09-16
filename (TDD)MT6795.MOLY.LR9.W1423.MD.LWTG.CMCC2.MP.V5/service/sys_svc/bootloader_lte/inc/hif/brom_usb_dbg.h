#ifndef __BROM_USB_DBG_H__
#define __BROM_USB_DBG_H__

//#include "kal_debug.h"

typedef enum _usbdev_uart_dbg_level {
	USBDEV_UARTDBG_TRACE = 0,
	USBDEV_UARTDBG_INFO,
	USBDEV_UARTDBG_WARN,
	USBDEV_UARTDBG_ERR,
	USBDEV_UARTDBG_OFF = 0xFF,	
}usbdev_uart_dbg_level;

#define USBDEV_UARTDBG_TH	USBDEV_UARTDBG_WARN
#define usbdev_printf(level,string_to_be_printed...)	\
	do{	\
		if (level >= USBDEV_UARTDBG_TH) {\
		}\
	}while(0)	\

#endif
