/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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

/*******************************************************************************
 * Filename:
 * ---------
 *   dbgprint.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   This Module defines debug function for driver.
 *
 * Author:
 * -------
 * -------
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Change MT6595 SLT log UART port to LTE UART port, this is for align with HVT.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * add dbgprint for ARM7 using SUART0 port.
 *
 * removed!
 * removed!
 * Integration change.
 *
 * removed!
 * removed!
 * temporary feature
 *
 * removed!
 * removed!
 * add dbg_flush and corresponding drvtest
 *
 * removed!
 * removed!
 * Add UART/HDMA driver
 ****************************************************************************/
#define MAXCHARS	512
#define MAXFRACT    	10000
#define NumFract        4

#include "drv_comm.h"
#include "stdarg.h"
#include "dcl.h"

#include "kal_public_api.h"
#include "uart_internal.h"
#include "uart_hw.h"

#ifdef  DRV_DEBUG

#if (defined(MT6290) || defined(MT6595) || (defined(MT6752)&&defined(__MD1__))) && defined(__ARM7EJ_S__)
#define DBG_PRINT_PORT		uart_port2 // Use UART2 as debug port (UART_SH0)
#else /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */
#define DBG_PRINT_PORT		uart_port1 // Use UART1 as debug port (UART_MD)
#endif /* end of else of "defined(MT6290) && defined(__ARM7EJ_S__)" */
#define DBG_PRINT_BAUD		UART_BAUD_115200


extern kal_bool INT_QueryExceptionStatus(); 
extern kal_uint32 UART_BaseAddr[MAX_UART_PORT_NUM];
extern UARTStruct UARTPort[MAX_UART_PORT_NUM];

static void itoa(char **buf, int i, int base);
void itof(char **buf, int i);

static kal_bool dbg_init_flag = KAL_FALSE;

char print_buf[MAXCHARS];


static DCL_STATUS dbg_print_tty_rx_cb(DCL_HANDLE handle, module_type source_id, tty_io_request_t *rx_ior)
{
	// RX call back should not be called since dbg port should not receive any data.
	ASSERT(0);
	return STATUS_OK;
}

DCL_STATUS dbg_print_tty_state_cb(DCL_HANDLE handle, tty_drv_state_e state)
{
	return STATUS_OK;
}

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
   DCL_HANDLE handle;

	// Initialize serial port
	if(dbg_init_flag!=KAL_TRUE){
		DCL_STATUS status;
		UART_CTRL_DCB_T data;

		// Bind COM port
		handle = DclSerialPort_Open(DBG_PRINT_PORT, 0);
		status = DclSerialPort_UpModuleInit(handle, MOD_DRV_DBG, TTY_FLAG_NEW_TX | TTY_FLAG_NEW_RX);
		if (status != STATUS_OK) {
			// Assert if dbg_print cannot bind the port
			ASSERT(0);
		}else{
			DclSerialPort_UpModuleRegisterCb(handle, dbg_print_tty_rx_cb, NULL, dbg_print_tty_state_cb);
			dbg_init_flag = KAL_TRUE;
		}

		data.u4OwenrId = MOD_DRV_DBG;
		data.rUARTConfig.u4Baud = DBG_PRINT_BAUD;
		data.rUARTConfig.u1DataBits = len_8;
		data.rUARTConfig.u1StopBits = sb_1;
		data.rUARTConfig.u1Parity = pa_none;
		data.rUARTConfig.u1FlowControl = fc_none;
		data.rUARTConfig.ucXonChar = 0x11;
		data.rUARTConfig.ucXoffChar = 0x13;
		data.rUARTConfig.fgDSRCheck = KAL_FALSE;

		DclSerialPort_Control(handle, SIO_CMD_SET_DCB_CONFIG, (DCL_CTRL_DATA_T*)&data);
	}

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
			
		case 'X':
			ival= va_arg(ap, int);
			bp += sprintf(bp, "0x%x", ival);
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
    
	handle = DclSerialPort_Open(DBG_PRINT_PORT, 0);

	#ifdef __DMA_UART_VIRTUAL_FIFO__
	UART_CTRL_PUT_UART_BYTE_T  data1;
	for (bp= print_buf; *bp; bp++)
	{
		data1.uData = *bp;
		DclSerialPort_Control(handle,SIO_CMD_PUT_UART_BYTE, (DCL_CTRL_DATA_T*)&data1);
	
	}
	#else
	BMTPutBytes.puBuffaddr = (kal_uint8 *)print_buf;
	BMTPutBytes.u2Length = len;
	DclSerialPort_Control( handle,UART_CMD_BMT_PUT_BYTES,(DCL_CTRL_DATA_T*)&BMTPutBytes);
	#endif

	// Flush the data in uart buffer when exception occurs
	if(INT_QueryExceptionStatus()){
		DclSerialPort_Control( handle, UART_CMD_ASSERT_WAIT_SEND_OUT, NULL);
	}

	va_end (ap);
#endif
}

char print_buf2[MAXCHARS];
void dbg_printWithTime(char *fmt,...)
{
#if !defined(__LTE_REMOVE_TEMPERAL__)

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
   DCL_HANDLE handle;


	// Initialize serial port
	if(dbg_init_flag!=KAL_TRUE){
		DCL_STATUS status;
		UART_CTRL_DCB_T data;

		// Bind COM port
		handle = DclSerialPort_Open(DBG_PRINT_PORT, 0);
		status = DclSerialPort_UpModuleInit(handle, MOD_DRV_DBG, TTY_FLAG_NEW_TX | TTY_FLAG_NEW_RX);
		if (status != STATUS_OK) {
			// Assert if dbg_print cannot bind the port
			ASSERT(0);
		}else{
			DclSerialPort_UpModuleRegisterCb(handle, dbg_print_tty_rx_cb, NULL, dbg_print_tty_state_cb);
			dbg_init_flag = KAL_TRUE;
		}

		data.u4OwenrId = MOD_DRV_DBG;
		data.rUARTConfig.u4Baud = DBG_PRINT_BAUD;
		data.rUARTConfig.u1DataBits = len_8;
		data.rUARTConfig.u1StopBits = sb_1;
		data.rUARTConfig.u1Parity = pa_none;
		data.rUARTConfig.u1FlowControl = fc_none;
		data.rUARTConfig.ucXonChar = 0x11;
		data.rUARTConfig.ucXoffChar = 0x13;
		data.rUARTConfig.fgDSRCheck = KAL_FALSE;

		DclSerialPort_Control(handle, SIO_CMD_SET_DCB_CONFIG, (DCL_CTRL_DATA_T*)&data);
	}

	bp= print_buf2;
	*bp= 0;
	//RTC_GetTime(&rtctime);
	rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
	DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)&rtc_cmd_data3);
	
	dbg_print("(%d:%d:%d): ",rtc_cmd_data3.u1Hour,rtc_cmd_data3.u1Min,rtc_cmd_data3.u1Sec);


	
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
	handle = DclSerialPort_Open(DBG_PRINT_PORT, 0);
	#ifdef __DMA_UART_VIRTUAL_FIFO__
	 UART_CTRL_PUT_UART_BYTE_T  data1;
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
#endif /* !defined(__LTE_REMOVE_TEMPERAL__) */

}

void dbg_flush(void)
{
	kal_uint32 uart_base = UART_BaseAddr[DBG_PRINT_PORT];
	UARTStruct *uart_data = &UARTPort[DBG_PRINT_PORT];

	kal_uint16 fifo_depth = 0, bytes_available = 0, expect_tx_num = 0;
	kal_uint8 tx_data = 0;
	kal_uint16 i = 0;

	DisableTxIntr(uart_base);	  

	if(DBG_PRINT_PORT == uart_port1) fifo_depth = UART1_TxFIFO_DEPTH;
	else if(DBG_PRINT_PORT == uart_port2) fifo_depth = UART2_TxFIFO_DEPTH;

	Buf_GetBytesAvail(&(uart_data->Tx_Buffer), bytes_available);
	while(bytes_available)
	{
		while(!(UART_LSR_TEMT & DRV_UART_Reg(UART_LSR(uart_base))));

		if(bytes_available > fifo_depth) expect_tx_num = fifo_depth;
		else expect_tx_num = bytes_available;
     	 
		for(i = 0; i < expect_tx_num; i++)
		{
			Buf_Pop(&(uart_data->Tx_Buffer), tx_data);
			DRV_UART_WriteReg(UART_THR(uart_base), (kal_uint16) tx_data);
		}
	
		Buf_GetBytesAvail(&(uart_data->Tx_Buffer), bytes_available);
	}

	return;
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
#else

void dbg_printWithTime(char *fmt,...){}
void dbg_print(char *fmt,...){}
void dbg_flush(void){}


#if defined(__IC_SLT__)
#if defined(MT6595) || (defined(MT6752)&&defined(__MD1__))
#define DBG_PRINT_PORT		uart_port2 // Use UART2 as debug port (UART_LTE)
#else
#define DBG_PRINT_PORT		uart_port1 // Use UART1 as debug port (UART_MD)
#endif

#define DBG_PRINT_BAUD		UART_BAUD_115200


extern kal_uint32 UART_BaseAddr[MAX_UART_PORT_NUM];
static kal_bool dbg_init_flag = KAL_FALSE;

extern void U_SetBaudRate(UART_PORT port, UART_baudrate baudrate, module_type ownerid);
static void itoa(char **buf, int i, int base);
static void dbg_uart_init(void); 
static void dbg_UARTPutByte(kal_uint8 data);
void dbg_gpio_mode_setting(UART_PORT uart);
void itof(char **buf, int i);

void slt_dbg_flush(void){};

void slt_dbg_print(char *fmt,...)
{
#if 1
	int i;
	va_list ap;
	double dval;
	int ival;
	char *p, *sval;
	char *bp, cval;
	int fract;
	unsigned short len;

	char print_buf[MAXCHARS];
	bp= print_buf;
	*bp= 0;
	if(dbg_init_flag == KAL_FALSE){
		 dbg_uart_init();
		 dbg_init_flag = KAL_TRUE;
	}

	va_start (ap, fmt);
	for(p= fmt; *p; p++)
	{
		if (*p != '%')
		{
			*bp++= *p;
			continue;
		}
		switch (*++p)
		{
			case 'd':
				ival= va_arg(ap, int);
				if (ival < 0)
				{
					*bp++= '-';
					ival= -ival;
				}
				itoa (&bp, ival, 10);
				break;

			case 'o':
				ival= va_arg(ap, int);
				if (ival < 0)
				{
					*bp++= '-';
					ival= -ival;
				}
				*bp++= '0';
				itoa (&bp, ival, 8);
				break;

			case 'x':
				ival= va_arg(ap, int);
				if(ival < 0)
				{
					*bp++= '-';
					ival= -ival;
				}
				*bp++= '0';
				*bp++= 'x';
				itoa (&bp, ival, 16);
				break;

			case 'X':
				ival= va_arg(ap, int);
				bp += sprintf(bp, "0x%x", ival);
				break;

			case 'c':
				cval= va_arg(ap, int);
				*bp++= cval;
				break;

			case 'f':
				dval= va_arg(ap, double);
				if(dval < 0)
				{
					*bp++= '-';
					dval= -dval;
				}
				if(dval >= 1.0)
					itoa (&bp, (int)dval, 10);
				else
					*bp++= '0';
				*bp++= '.';
				fract= (int)((dval- (double)(int)dval)*(double)(MAXFRACT));
				itof(&bp, fract);
				break;

			case 's':
				for(sval = va_arg(ap, char *) ; *sval ; sval++ )
					*bp++= *sval;
				break;
		}
	}
	*bp= 0;
	len = (unsigned short)(bp - print_buf);
	

	for(i = 0; i < len; i++)
	{
		dbg_UARTPutByte(print_buf[i]);		
	}
	
	va_end (ap);
#endif
}

static void dbg_uart_init(void){

	kal_uint32 uart_base = UART_BaseAddr[DBG_PRINT_PORT];
	dbg_gpio_mode_setting(DBG_PRINT_PORT);
	DRV_WriteReg(UART_IER(uart_base), UART_IER_ALLOFF);
	DRV_WriteReg32(UART_DMA_EN(uart_base), 0x0); //disable DMA
	DRV_WriteReg32(UART_LCR(uart_base), 0xBF);
	DRV_WriteReg32(UART_EFR(uart_base), 0x0);  //no flow control;
	DRV_WriteReg32(UART_LCR(uart_base), 0x03);  //word len = 8 bit;  stop bit =1; parity = false;
	DRV_WriteReg32(UART_FCR(uart_base), 0x05);  //set fifo enable ,and clear Tx and Rx  fifo.
	U_SetBaudRate(DBG_PRINT_PORT, DBG_PRINT_BAUD, (module_type)(DBG_PRINT_PORT));

}

static void dbg_UARTPutByte(kal_uint8 data)
{
   volatile kal_uint16 LSR;
   kal_uint32 uart_base = UART_BaseAddr[DBG_PRINT_PORT];
   while(1)
   {
   	  LSR = DRV_Reg32(UART_LSR(uart_base));
      if((LSR & UART_LSR_THRE))
      {
       	 DRV_WriteReg32(UART_THR(uart_base), data);
         break;
      }
   }
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
void dbg_gpio_mode_setting(UART_PORT uart){
#if defined(MT6752)&&defined(__MD1__)
kal_uint32 gpio_val,temp;
#define AP_IOCFG_R_BASE    (0xA0002800)
		if(uart == uart_port1){
			//set io mode : GPIO144,GPIO145 => MDUART mode
			gpio_val = 0xEE; //[2:0] target AUX mode; [3] mode set enable: 0: mode is not set; 1: mode is set;
			DRV_WriteReg32((GPIO_base+0x42C), gpio_val);
			/* Set MD_URXD PullEn */
            temp = DRV_Reg32(AP_IOCFG_R_BASE+0x090);
            temp &= ~(0x3);
            temp |= 0x1;
            DRV_WriteReg32(AP_IOCFG_R_BASE+0x090, temp);   
			/* Set MD_URXD PullSel */
            temp = DRV_Reg32(AP_IOCFG_R_BASE+0x0c0);
            temp &= ~(0x3);
            temp |= 0x1;
            DRV_WriteReg32(AP_IOCFG_R_BASE+0x0c0, temp);   
		}else if(uart == uart_port2){
			//set io mode : GPIO146,GPIO147 => LTEUART mode
			gpio_val = (0xEE<<8);//[2:0] target AUX mode; [3] mode set enable: 0: mode is not set; 1: mode is set;
			DRV_WriteReg32((GPIO_base+0x42C), gpio_val);
			 /* Set LTE_URXD PullEn */
            temp = DRV_Reg32(AP_IOCFG_R_BASE+0x090);
            temp &= ~(0xC);
            temp |= 0x4;
            DRV_WriteReg32(AP_IOCFG_R_BASE+0x090, temp);  
			 /* Set LTE_URXD PullSel */
            temp = DRV_Reg32(AP_IOCFG_R_BASE+0x0c0);
            temp &= ~(0xC);
            temp |= 0x4;
            DRV_WriteReg32(AP_IOCFG_R_BASE+0x0c0, temp);  
		}
#endif
}
#endif
#endif
