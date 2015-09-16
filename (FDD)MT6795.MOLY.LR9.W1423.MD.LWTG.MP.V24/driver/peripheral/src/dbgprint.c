/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    dbgprint.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines debug function for driver.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#define MAXCHARS	512
#define MAXFRACT    	10000
#define NumFract        4
#include "drv_comm.h"
#include "stdarg.h"
#include "bmd.h"
#include "uart_sw.h"
//#include "rtc_sw.h"

#include "dcl.h"
#include "uart_internal.h"

/*#include "uart_sw.h"*/
#ifdef  DRV_DEBUG
static void itoa(char **buf, int i, int base);
void itof(char **buf, int i);
void minprintf(char *fmt, ...);
char print_buf[MAXCHARS];
//extern kal_uint16 BMT_PutBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length);

#if defined(IC_BURNIN_TEST)
  // BURNIN test
  #if defined(MT6268)
  #define DBG_PRINT_PORT	0 // Use UART3 as debug port
  #elif (defined(MT6253) || defined(MT6253T))
  #define DBG_PRINT_PORT	1// Use UART2 as debug port
  #else // #if defined(MT6268)
  #define DBG_PRINT_PORT	0 // Use UART1 as debug port
  #endif // #if defined(MT6268)
#else // #if defined(IC_BURNIN_TEST)
  // Non BURNIN test 
  #define DBG_PRINT_PORT	0 // Use UART1 as debug port
#endif // #if defined(IC_BURNIN_TEST)


extern UARTStruct UARTPort[MAX_UART_PORT_NUM];

#if !defined(__SSDVT_TEST__)

void dbg_print(char *fmt,...)
{
#if (!defined(IC_MODULE_TEST))
   va_list ap;
   double dval;
   int ival;
   char *p, *sval;
   char *bp, cval;
   int fract;
   unsigned short len;
   UART_CTRL_PUT_BYTES_T BMTPutBytes;
   UART_CTRL_PUT_UART_BYTE_T data1;
   DCL_HANDLE handle;

	bp= print_buf;
	*bp= 0;
	
	va_start (ap, fmt);
	for (p= fmt; *p; p++)
	{
		if (*p != '%')
		{
			*bp++= *p;
			continue;
		}
		switch (*++p) {
		case 'd':
			ival= va_arg(ap, int);
			if (ival < 0){
				*bp++= '-';
			     ival= -ival;
			}
			itoa (&bp, ival, 10);
			break;
			
        	case 'o':
			ival= va_arg(ap, int);
			if (ival < 0){
				*bp++= '-';
			     ival= -ival;
			}
			*bp++= '0';
			itoa (&bp, ival, 8);
			break;
			
		case 'x':
			ival= va_arg(ap, int);
			if (ival < 0){
			     *bp++= '-';
			     ival= -ival;
			}
			*bp++= '0';
			*bp++= 'x';
			itoa (&bp, ival, 16);
			break;
			
		case 'c':
			cval= va_arg(ap, int);
			*bp++= cval;
			break;
			
		case 'f':
			dval= va_arg(ap, double);
			if (dval < 0){
				*bp++= '-';
				dval= -dval;
			}
			if (dval >= 1.0)
				itoa (&bp, (int)dval, 10);
		    	else
				*bp++= '0';
			*bp++= '.';
			fract= (int)((dval- (double)(int)dval)*(double)(MAXFRACT));
            		itof(&bp, fract);
			break;
			
		case 's':
			for (sval = va_arg(ap, char *) ; *sval ; sval++ )
			    *bp++= *sval;
			break;
		}
	}
	*bp= 0;
	len = (unsigned short)(bp - print_buf);
	handle = DclSerialPort_Open(DBG_PRINT_PORT,0);

	if(UARTPort[DBG_PRINT_PORT].power_on == KAL_FALSE)//add liming for( phase out UART port power on\off in EM)
			UART_TurnOnPower(DBG_PRINT_PORT,KAL_TRUE);

	#ifdef __DMA_UART_VIRTUAL_FIFO__
	for (bp= print_buf; *bp; bp++)
	{
		//PutUARTByte(DBG_PRINT_PORT,*bp);	
	data1.uData = *bp;
	DclSerialPort_Control(handle,SIO_CMD_PUT_UART_BYTE, (DCL_CTRL_DATA_T*)&data1);
	
	}
	#else
	BMTPutBytes.puBuffaddr = (kal_uint8 *)print_buf;
	BMTPutBytes.u2Length = len;
	DclSerialPort_Control( handle,UART_CMD_BMT_PUT_BYTES,(DCL_CTRL_DATA_T*)&BMTPutBytes);
	//	BMT_PutBytes(DBG_PRINT_PORT,(kal_uint8 *)print_buf,len);
	
	#endif
	va_end (ap);
#endif
}

char print_buf2[MAXCHARS];
void dbg_printWithTime(char *fmt,...)
{
#if (!defined(IC_MODULE_TEST))
   va_list ap;
   double dval;
   int ival;
   char *p, *sval;
   char *bp, cval;
   int fract;
  // t_rtc rtctime;
   unsigned short len;
   RTC_CTRL_GET_TIME_T rtc_cmd_data3;
   DCL_HANDLE rtc_handler;
   UART_CTRL_PUT_BYTES_T BMTPutBytes;
   UART_CTRL_PUT_UART_BYTE_T  data1;
	DCL_HANDLE handle;

	bp= print_buf2;
	*bp= 0;
	//RTC_GetTime(&rtctime);
	#if ! defined(DRV_RTC_NOT_EXIST)
	rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
	DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)&rtc_cmd_data3);
	
	dbg_print("(%d:%d:%d): ",rtc_cmd_data3.u1Hour,rtc_cmd_data3.u1Min,rtc_cmd_data3.u1Sec);
	#endif
	va_start (ap, fmt);
	for (p= fmt; *p; p++)
	{
		if (*p != '%')
		{
			*bp++= *p;
			continue;
		}
		switch (*++p) {
		case 'd':
			ival= va_arg(ap, int);
			if (ival < 0){
				*bp++= '-';
			     ival= -ival;
			}
			itoa (&bp, ival, 10);
			break;
			
        	case 'o':
			ival= va_arg(ap, int);
			if (ival < 0){
				*bp++= '-';
			     ival= -ival;
			}
			*bp++= '0';
			itoa (&bp, ival, 8);
			break;
			
		case 'x':
			ival= va_arg(ap, int);
			if (ival < 0){
			     *bp++= '-';
			     ival= -ival;
			}
			*bp++= '0';
			*bp++= 'x';
			itoa (&bp, ival, 16);
			break;
			
		case 'c':
			cval= va_arg(ap, int);
			*bp++= cval;
			break;
			
		case 'f':
			dval= va_arg(ap, double);
			if (dval < 0){
				*bp++= '-';
				dval= -dval;
			}
			if (dval >= 1.0)
				itoa (&bp, (int)dval, 10);
		    	else
				*bp++= '0';
			*bp++= '.';
			fract= (int)((dval- (double)(int)dval)*(double)(MAXFRACT));
            		itof(&bp, fract);
			break;
			
		case 's':
			for (sval = va_arg(ap, char *) ; *sval ; sval++ )
			    *bp++= *sval;
			break;
		}
	}
	*bp= 0;
	len = (unsigned short)(bp - print_buf2);
	
	if(UARTPort[DBG_PRINT_PORT].power_on == KAL_FALSE)//add liming for( phase out UART port power on\off in EM)
			UART_TurnOnPower(DBG_PRINT_PORT,KAL_TRUE);

	
	#ifdef __DMA_UART_VIRTUAL_FIFO__	
	for (bp= print_buf2; *bp; bp++)
	{
		//PutUARTByte(0,*bp);
		data1.uData = *bp;
	    DclSerialPort_Control(handle,SIO_CMD_PUT_UART_BYTE, (DCL_CTRL_DATA_T*)&data1);
	}
	#else
	BMTPutBytes.puBuffaddr = (kal_uint8 *)print_buf2;
	BMTPutBytes.u2Length = len;
	DclSerialPort_Control( handle,UART_CMD_BMT_PUT_BYTES,(DCL_CTRL_DATA_T*)&BMTPutBytes);
		//BMT_PutBytes(0,(kal_uint8 *)print_buf2,len);
	#endif
	va_end (ap);
#endif
}

void itof(char **buf, int i)
{
	char *s;
#define LEN	20
	int rem, j;
	static char rev[LEN+1];

	rev[LEN] = 0;
	s = &rev[LEN];
	for (j= 0 ; j < NumFract ; j++)
		{
		rem = i % 10;
			*--s = rem + '0';
		i /= 10;
		}
	while (*s)
		{
		(*buf)[0] = *s++;
		++(*buf);
		}
}

static void itoa(char **buf, int i, int base)
{
	char *s;
#define LEN	20
	int rem;
	static char rev[LEN+1];

	rev[LEN] = 0;
	if (i == 0)
		{
		(*buf)[0] = '0';
		++(*buf);
		return;
		}
	s = &rev[LEN];
	while (i)
		{
		rem = i % base;
		if (rem < 10)
			*--s = rem + '0';
		else if (base == 16)
			*--s = "abcdef"[rem - 10];
		i /= base;
		}
	while (*s)
		{
		(*buf)[0] = *s++;
		++(*buf);
		}
}

#endif    /* __SSDVT_TEST__ */

#else
static void itoa(char **buf, int i, int base);
void itof(char **buf, int i);
void minprintf(char *fmt, ...);
char print_buf[MAXCHARS];
void itof(char **buf, int i)
{
	char *s;
#define LEN	20
	int rem, j;
	static char rev[LEN+1];

	rev[LEN] = 0;
	s = &rev[LEN];
	for (j= 0 ; j < NumFract ; j++)
		{
		rem = i % 10;
			*--s = rem + '0';
		i /= 10;
		}
	while (*s)
		{
		(*buf)[0] = *s++;
		++(*buf);
		}
}

static void itoa(char **buf, int i, int base)
{
	char *s;
#define LEN	20
	int rem;
	static char rev[LEN+1];

	rev[LEN] = 0;
	if (i == 0)
		{
		(*buf)[0] = '0';
		++(*buf);
		return;
		}
	s = &rev[LEN];
	while (i)
		{
		rem = i % base;
		if (rem < 10)
			*--s = rem + '0';
		else if (base == 16)
			*--s = "abcdef"[rem - 10];
		i /= base;
		}
	while (*s)
		{
		(*buf)[0] = *s++;
		++(*buf);
		}
}
#if defined(IC_BURNIN_TEST)
  // BURNIN test
  #if defined(MT6268)
  #define DBG_PRINT_PORT	0 // Use UART3 as debug port
  #elif (defined(MT6253) || defined(MT6253T))
  #define DBG_PRINT_PORT	1// Use UART2 as debug port
  #else // #if defined(MT6268)
  #define DBG_PRINT_PORT	0 // Use UART1 as debug port
  #endif // #if defined(MT6268)
#else // #if defined(IC_BURNIN_TEST)
  // Non BURNIN test 
  #define DBG_PRINT_PORT	0 // Use UART1 as debug port
#endif // #if defined(IC_BURNIN_TEST)


extern UARTStruct UARTPort[MAX_UART_PORT_NUM];

#if !defined(__SSDVT_TEST__)

void dbg_print_MD2(char *fmt,...)
{
#if (!defined(IC_MODULE_TEST))
   va_list ap;
   double dval;
   int ival;
   char *p, *sval;
   char *bp, cval;
   int fract;
   unsigned short len;
   UART_CTRL_PUT_BYTES_T BMTPutBytes;
   UART_CTRL_PUT_UART_BYTE_T data1;
   DCL_HANDLE handle;

	bp= print_buf;
	*bp= 0;
	
	va_start (ap, fmt);
	for (p= fmt; *p; p++)
	{
		if (*p != '%')
		{
			*bp++= *p;
			continue;
		}
		switch (*++p) {
		case 'd':
			ival= va_arg(ap, int);
			if (ival < 0){
				*bp++= '-';
			     ival= -ival;
			}
			itoa (&bp, ival, 10);
			break;
			
        	case 'o':
			ival= va_arg(ap, int);
			if (ival < 0){
				*bp++= '-';
			     ival= -ival;
			}
			*bp++= '0';
			itoa (&bp, ival, 8);
			break;
			
		case 'x':
			ival= va_arg(ap, int);
			if (ival < 0){
			     *bp++= '-';
			     ival= -ival;
			}
			*bp++= '0';
			*bp++= 'x';
			itoa (&bp, ival, 16);
			break;
			
		case 'c':
			cval= va_arg(ap, int);
			*bp++= cval;
			break;
			
		case 'f':
			dval= va_arg(ap, double);
			if (dval < 0){
				*bp++= '-';
				dval= -dval;
			}
			if (dval >= 1.0)
				itoa (&bp, (int)dval, 10);
		    	else
				*bp++= '0';
			*bp++= '.';
			fract= (int)((dval- (double)(int)dval)*(double)(MAXFRACT));
            		itof(&bp, fract);
			break;
			
		case 's':
			for (sval = va_arg(ap, char *) ; *sval ; sval++ )
			    *bp++= *sval;
			break;
		}
	}
	*bp= 0;
	len = (unsigned short)(bp - print_buf);
	handle = DclSerialPort_Open(DBG_PRINT_PORT,0);

	if(UARTPort[DBG_PRINT_PORT].power_on == KAL_FALSE)//add liming for( phase out UART port power on\off in EM)
			UART_TurnOnPower(DBG_PRINT_PORT,KAL_TRUE);

	#ifdef __DMA_UART_VIRTUAL_FIFO__
	for (bp= print_buf; *bp; bp++)
	{
		//PutUARTByte(DBG_PRINT_PORT,*bp);	
	data1.uData = *bp;
	DclSerialPort_Control(handle,SIO_CMD_PUT_UART_BYTE, (DCL_CTRL_DATA_T*)&data1);
	
	}
	#else
	BMTPutBytes.puBuffaddr = (kal_uint8 *)print_buf;
	BMTPutBytes.u2Length = len;
	DclSerialPort_Control( handle,UART_CMD_BMT_PUT_BYTES,(DCL_CTRL_DATA_T*)&BMTPutBytes);
	//	BMT_PutBytes(DBG_PRINT_PORT,(kal_uint8 *)print_buf,len);
	
	#endif
	va_end (ap);
#endif
}
#endif
void dbg_printWithTime(char *fmt,...){}
void dbg_print(char *fmt,...){}
#endif /*DRV_DEBUG*/

