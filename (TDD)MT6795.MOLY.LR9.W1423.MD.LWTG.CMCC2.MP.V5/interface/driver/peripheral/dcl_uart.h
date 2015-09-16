/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dcl_uart.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for UART.
 *
 * Author:
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
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef DCL_DEFINITION_STRUCT
#ifndef  __DCL_UART_STRUCT__
#define   __DCL_UART_STRUCT__

#if defined(__CMUX_SUPPORT__)
#include "cmux_vp_num.h"
#define VIRTUAL_PORT_NUM  CMUX_VP_NUM
#else  // #if defined(__CMUX_SUPPORT__)
#define VIRTUAL_PORT_NUM  0
#endif // #if defined(__CMUX_SUPPORT__)

/*!
 *	@brief	it defines DCL UART Device port enumeration
 */
#define DCL_UART_DEV \
		uart_port1=0x00, \
		uart_port2, \
		uart_port3,	\
		/*uart_port_irda,*/\
		uart_port_usb,\
		uart_port_usb2,\
		uart_port_usb3,\
		uart_port_usb4,\
		uart_port_usb5,\
		/*uart_port_bluetooth,*/\
		/*uart_port_swdbg,*/\
		uart_port_dhl_sp_expt,\
        uart_port_dhl_ctrl_sp_expt,\
        uart_port_dhl_sp,\
        uart_port_dhl_ccci = uart_port_dhl_sp,\
        uart_port_ccci_start = uart_port_dhl_ccci,\
        uart_port_dhl_ctrl_sp,\
        uart_port_tst_ccci = uart_port_dhl_ctrl_sp,\
        uart_port_at_ccci,\
        uart_port_gps_ccci,\
        uart_port_sim_ccci,\
        uart_port_ccci_end = uart_port_sim_ccci,\
		start_of_virtual_port,\
		end_of_virtual_port = (VIRTUAL_PORT_NUM + start_of_virtual_port),\
		/*uart_port_dcc,*/\
		/*uart_port_lga1,*/\
		/*uart_port_lga2,*/\
		/*uart_port_lmu,*/\
		/*uart_port_sp_usb,*/\
		/*uart_port_sp_usb_dsp,*/\
		uart_port_mini_log,\
		uart_port_dual_talk,\
		uart_port_modis,/*only for modis*/\
		uart_max_port,\
		uart_port_null = 99,


/*******************************************************************************
 * DCL_CTRL_CMD for UART
 *******************************************************************************/
/*!
 *	@brief	it defines DCL UART commands, including SIO/UART/USB/TTY commands
 *			Since TTY architecture has been modified and enhanced, there are some summaries for UART commands:
 *			- Data related SIO commands, such as
 *				SIO_CMD_PUT_BYTES
 *				SIO_CMD_PUT_ISR_BYTES,
 *				SIO_CMD_PUT_UART_BYTE
 *				SIO_CMD_PUT_UART_BYTES
 *				SIO_CMD_GET_TX_AVAIL
 *				SIO_CMD_GET_ISR_TX_AVAIL
 *				-> only support for conventional Tx Path.
 *				SIO_CMD_GET_BYTES
 *				SIO_CMD_GET_UART_BYTE
 *				SIO_CMD_GET_RX_AVAIL
 *				-> only support for conventional Rx Path.
 *				SIO_CMD_SEND_ISR_DATA
 *				SIO_CMD_SEND_DATA
 *				-> not support for all path.
 *			    are not supported for new upper layer modules which use NEW TTY architecture.
 *			- TTY commands are added for new TTY architecture.
 *			    among these commands, TTY_CMD_PUT_BYTES_IOR is to put bytes with ior format.
 *			    But the upper layer modules don't need to take care TTY_CMD_PUT_BYTES_IOR commands. They only use DclSerialPort_UpModuleTransmit API to put data.
 *			- Driver must implement the following commands:
 *				SIO_CMD_INIT
 *				SIO_CMD_OPEN
 *				SIO_CMD_CLOSE
 *				SIO_CMD_PURGE
 *				SIO_CMD_SET_OWNER
 *				SIO_CMD_CLR_RX_BUF
 *				SIO_CMD_CLR_TX_BUF
 *				SIO_CMD_GET_OWNER_ID
 *				TTY_CMD_PUT_BYTES_IOR
 *				TTY_CMD_GET_CHUNK_SIZE
 *				TTY_CMD_ASSIGN_RX_IOR
 *				TTY_CMD_NEED_TX_DONE_CB
 *				, other commands 
 *			- UART commands UART_CMD_BOOT_PUTBYTES & UART_CMD_BMT_PUT_BYTES still use buffer/length instead of ior as parameter.
 *
 *			Notes of some commands:
 *			- SIO_CMD_CLR_TX_BUF : it would block and sleep before the command returns in conventional Tx mode.
 *			- SIO_CMD_CLR_RX_BUF : it would block and sleep before the command returns in conventional Rx mode.
 *			- SIO_CMD_SET_OWNER : it would block and sleep before the command returns in conventional Tx or Rx mode.
 *			- SIO_CMD_CLOSE : it would block and sleep before the command returns in conventional Tx or Rx mode.
 *			- SIO_CMD_PUT_ISR_BYTES : This command doesn't guarantee that all data can be sent successfully in conventional Tx mode since it won't send ReadyToWrite ilm.
 */
#define UART_CMDS \
	SIO_CMD_INIT = 0x00,\
	SIO_CMD_OPEN,\
	SIO_CMD_CLOSE,\
	SIO_CMD_GET_BYTES,\
	SIO_CMD_PUT_BYTES,\
	SIO_CMD_GET_RX_AVAIL,\
	SIO_CMD_GET_TX_AVAIL,\
	SIO_CMD_PUT_ISR_BYTES,\
	SIO_CMD_GET_ISR_TX_AVAIL,\
	SIO_CMD_PURGE,\
	SIO_CMD_SET_OWNER,\
	SIO_CMD_SET_FLOW_CTRL,\
	SIO_CMD_CONFIG_ESCAPE,\
	SIO_CMD_SET_DCB_CONFIG,\
	SIO_CMD_CTRL_DCD,\
	SIO_CMD_CTRL_BREAK, \
	SIO_CMD_CLR_RX_BUF,\
	SIO_CMD_CLR_TX_BUF, \
	SIO_CMD_SET_BAUDRATE, \
	SIO_CMD_SEND_ISR_DATA, \
	SIO_CMD_SEND_DATA, \
	SIO_CMD_GET_OWNER_ID, \
	SIO_CMD_SET_AUTOBAUD_DIV, \
	SIO_CMD_REG_TX_CB,\
	SIO_CMD_REG_RX_CB,\
	SIO_CMD_GET_UART_BYTE,\
	SIO_CMD_PUT_UART_BYTE,\
	SIO_CMD_PUT_UART_BYTES,\
	SIO_CMD_READ_DCB_CONFIG,\
	SIO_CMD_CTRL_RI,\
	SIO_CMD_GET_ESCAPE_INFO,\
	SIO_CMD_CTRL_DTR,\
	SIO_CMD_READ_HW_STATUS,\
	SIO_CMD_GET_UART_BYTE_WITH_TIMEOUT,\
	UART_CMD_UART_START = 0x100,\
	UART_CMD_SET_FIFO_TRIGGER,\
	UART_CMD_POWER_ON,\
	UART_CMD_CHECK_TX_BUF_EMPTY,\
	UART_CMD_CHECK_TX_SEND_OUT,\
	UART_CMD_GET_TX_BUF_SIZE,\
	UART_CMD_SLEEP_TX_ENABLE,\
	UART_CMD_CTRL_SLEEP_MODE,\
	UART_CMD_SWITCH_PORT,\
	UART_CMD_BOOTUP_INIT,\
	UART_CMD_BOOT_PUTBYTES,\
	UART_CMD_LOOPBACK,\
	UART_CMD_ASSERT_WAIT_SEND_OUT,\
	UART_CMD_CTRL_USE_VFIFO,\
	UART_CMD_GET_FLOW_CONTROL,\
	UART_CMD_REG_DEF_CB,\
	UART_CMD_BMT_PUT_BYTES,\
	UART_CMD_RECHANDLER_VFIFO,\
	UART_CMD_TRXHANDLER_VFIFO,\
	UART_CMD_RECTIMEOUTHANDLE,\
	UART_CMD_CTRL_TX_DMA,\
	UART_CMD_GET_MAX_BAUDRATE,\
	UART_CMD_UART_END,\
	USB_CMD_UART_START = 0x200,\
	USB_CMD_IS_CDCACM,\
	USB_CMD_HIGH_SPEED_IF_ENABLE, \
	USB_CMD_REG_TX_CB, \
	USB_CMD_TX_DATA_STATUS, \
	USB_CMD_SEND_DATA, \
	USB_CMD_GET_DATA, \
	USB_CMD_SEND_ISR_DATA, \
	USB_CMD_CTRL_SEND_DATA, \
	USB_CMD_CTRL_GET_DATA, \
	USB_CMD_HALT, \
	USB_CMD_FT_PORT, \
	USB_CMD_ACM_RING_BUFF_THRESHOLD_EN, \
	USB_CMD_USB2UART_TX_DMA_CBK, \
	USB_CMD_BOOT_PUTBYTES, \
    USB_CMD_IS_CDCACM_ACTIVE,\
	USB_CMD_UART_END, \
	TTY_CMD_UART_START = 0x300,\
	TTY_CMD_GET_CHUNK_SIZE,\
	TTY_CMD_ASSIGN_RX_IOR,\
	TTY_CMD_NEED_TX_DONE_CB,\
	TTY_CMD_GET_DRV_STATE,\
	TTY_CMD_PUT_BYTES_IOR,\
	TTY_CMD_PUT_BYTES_IOR_LIGHT,\
	TTY_CMD_GET_MTU_SIZE,\
	TTY_CMD_SET_INDICATION,\
	TTY_CMD_UART_END,\
	TTY_CMD_EXCEPTION_START = 0x400,\
	TTY_CMD_EXCEPTION_RESET,\
	TTY_CMD_EXCEPTION_HIF_INIT,\
	TTY_CMD_EXCEPTION_CLEAR_CHANNEL,\
	TTY_CMD_EXCEPTION_TX_GPD,\
	TTY_CMD_EXCEPTION_TX_DONE_INFO,\
	TTY_CMD_EXCEPTION_HIF_STATE,\
	TTY_CMD_EXCEPTION_ASSIGN_RX_GPD,\
	TTY_CMD_EXCEPTION_GET_RX_GPD,\
	TTY_CMD_EXCEPTION_HIF_POLL,\
	TTY_CMD_EXCEPTION_HIF_RESET_LINK,\
	TTY_CMD_EXCEPTION_FLUSH_TX,\
	TTY_CMD_EXCEPTION_FLUSH_RX,\
	TTY_CMD_EXCEPTION_END,

//
typedef enum
{
	DCL_UART_TYPE = 0x00,
	DCL_UART_USB_TYPE,
	DCL_UART_BLUETOOTH_TYPE,
	DCL_UART_CMUX_TYPE,
	DCL_UART_SPPA_TYPE,
	DCL_UART_CCCI_TYPE,
	DCL_UART_CCIF_TYPE,
	DCL_UART_DCC_TYPE,
	DCL_UART_LOGACC_TYPE,
	DCL_UART_LMU_TYPE,
	DCL_UART_SP_USB_TYPE,
	DCL_UART_MINI_LOG_TYPE,
	DCL_UART_DEV_TYPE_MAX
}SIO_TYPE_T;

typedef DCL_UINT32 UART_BAUDRATE_T;
typedef UART_BAUDRATE_T UART_baudrate;
typedef DCL_UINT16   UART_PORT;

#define     UART_BAUD_AUTO          0
#define     UART_BAUD_75            75
#define     UART_BAUD_150           150
#define     UART_BAUD_300           300
#define     UART_BAUD_600           600
#define     UART_BAUD_1200          1200
#define     UART_BAUD_2400          2400    
#define     UART_BAUD_4800          4800
#define     UART_BAUD_7200          7200
#define     UART_BAUD_9600          9600
#define     UART_BAUD_14400         14400
#define     UART_BAUD_19200         19200
#define     UART_BAUD_28800         28800
#define     UART_BAUD_33900         33900
#define     UART_BAUD_38400         38400
#define     UART_BAUD_57600         57600
#define     UART_BAUD_115200        115200
#define     UART_BAUD_230400        230400
#define     UART_BAUD_460800        460800
#define     UART_BAUD_921600        921600
#define     UART_BAUD_1500000       1500000 


typedef enum {
      LEN_5=5,
      LEN_6,
      LEN_7,
      LEN_8
} UART_BITS_PER_CHAR_T;

typedef enum {
      SB_1=1,
      SB_2,
      SB_1_5
} UART_STOP_BITS_T;

typedef enum {
      PA_NONE=0,
      PA_ODD,
      PA_EVEN,
      PA_SPACE
} UART_PARITY_T;

/*
#if defined(FC_NONE)
#undef FC_NONE
#endif
*/

typedef enum {
      FC_NONE=1,
      FC_HW,
      FC_SW
} UART_FLOW_CTRL_MODE_T;

typedef enum {
      DCL_NONE_VFIFO,
      DCL_RX_VFIFO,
      DCL_TX_VFIFO,
      DCL_TXRX_VFIFO
} UART_VFIFO_T;

typedef enum {
      uart_sleep_on_tx_allow = 0,
      uart_sleep_on_tx_forbid
} UART_SLEEP_ON_TX;



typedef struct
{
   UART_BAUDRATE_T      u4Baud; 
   DCL_UINT8            u1DataBits; //UART_BITS_PER_CHAR_T
   DCL_UINT8            u1StopBits; //UART_STOP_BITS_T
   DCL_UINT8            u1Parity; //UART_PARITY_T
   DCL_UINT8            u1FlowControl; //UART_FLOW_CTRL_MODE_T
   DCL_UCHAR            ucXonChar;
   DCL_UCHAR            ucXoffChar;
   DCL_BOOLEAN          fgDSRCheck;
} UART_CONFIG_T;

typedef enum 
{
	DCL_IO_Low=0,
	DCL_IO_High
} IO_LEVEL_T;


typedef enum {
      DCL_RX_BUF,
      DCL_TX_BUF
} UART_BUFFER_T;

typedef enum {
      DCL_UART_SLEEP_ON_TX_ALLOW = 0,
      DCL_UART_SLEEP_ON_TX_FORBID,
} UART_SLEEP_ON_TX_T;

typedef enum {
      DCL_UART_BY_VFIFO,
      DCL_UART_BY_DMA,
      DCL_UART_BY_MCU,
      DCL_UART_BY_UNKNOWN
} UART_WORK_MODE;


/*!
 *  @brief tty_io_request_t is a typedef of struct _tty_io_request
 */
typedef struct _tty_io_request_t tty_io_request_t;

/*!
 *  @brief struct _tty_io_request_t describe io request used to communicate
 *         between ap module & tty
 */
struct _tty_io_request_t{
    /*!
     *  @brief next io request
     */
    tty_io_request_t    *next_request;
    /*!
     *  @brief pointer to current gpd of this io request
     */
    void                *first_gpd;
    /*!
     *  @brief pointer to last gpd of this io request
     */
    void                *last_gpd;
};

//UART_CMD_INIT
typedef struct
{
	DCL_UINT32 u4Flag;
}UART_CTRL_INIT_T;

//UART_CMD_OPEN
typedef struct
{
  DCL_UINT32 u4OwenrId;
}UART_CTRL_OPEN_T;

//UART_CMD_CLOSE
typedef struct
{
  DCL_UINT32 u4OwenrId;
}UART_CTRL_CLOSE_T;

//UART_CMD_GET_BYTES
typedef struct
{
	DCL_UINT16 u2Length;
	DCL_UINT32 u4OwenrId;
	DCL_UINT16	u2RetSize;
	DCL_UINT8* puBuffaddr;
	DCL_UINT8*  pustatus;
	
}UART_CTRL_GET_BYTES_T;

//UART_CMD_PUT_BTYES
//UART_CMD_PUT_ISR_BYTES
typedef struct
{
	DCL_UINT16 u2Length;
	DCL_UINT32 u4OwenrId;
	DCL_UINT16	u2RetSize;
	DCL_UINT8* puBuffaddr;
}UART_CTRL_PUT_BYTES_T;

typedef struct
{
	DCL_UINT32 u4OwnerId;
	void *putIor;
}UART_CTRL_PUT_BYTES_IOR_T;

//UART_CMD_GET_RX_AVAIL
typedef struct
{
	DCL_UINT16 u2RetSize;
}UART_CTRL_RX_AVAIL_T;

//UART_CMD_GET_TX_AVAIL
//UART_CMD_GET_ISR_TX_AVAIL
typedef struct
{
	DCL_UINT16 u2RetSize;
}UART_CTRL_TX_AVAIL_T;

//UART_CMD_PURGE
typedef struct
{
	DCL_UINT32 u4OwenrId;
	UART_BUFFER_T dir;
}UART_CTRL_PURGE_T;

//UART_CMD_SET_OWNER
//UART_CMD_GET_OWNER_ID
typedef struct
{
	DCL_UINT32 u4OwenrId;
}UART_CTRL_OWNER_T;

//UART_CMD_SET_FLOW_CTRL
typedef struct
{
	DCL_UINT32 u4OwenrId;
	DCL_BOOL 	bXON;
}UART_CTRL_FLOW_CTRL_T;

//UART_CMD_CONFIG_ESCAPE
typedef struct
{
   DCL_UINT32 u4OwenrId;
   DCL_UINT8  uEscChar;
   DCL_UINT16 u2ESCGuardtime;
} UART_CTRL_CONFIG_ESP_T;

//UART_CMD_SET_DCB_COFIG
//UART_CMD_READ_DCB_CONFIG

typedef struct
{
	DCL_UINT32 u4OwenrId;
	UART_CONFIG_T  rUARTConfig;
} UART_CTRL_DCB_T;

//UART_CMD_CTRL_DCD

typedef struct
{
	DCL_UINT32 u4OwenrId;
	IO_LEVEL_T rIOLevelDCD;
} UART_CTRL_DCD_T;

//UART_CMD_GET_FLOW_CONTROL
typedef struct
{
	DCL_UINT32 u4OwenrId;
	UART_FLOW_CTRL_MODE_T FlowCtrlMode;
}UART_CTRL_GET_FC_T;

//TTY_CMD_GET_CHUNK_SIZE
typedef struct
{
	DCL_UINT32 chunkSize;
} UART_CTRL_GET_CHUNK_SIZE_T;

//TTY_CMD_NEED_TX_DONE_CB
typedef struct
{
	DCL_UINT32 u4OwnerId;
	DCL_BOOL needTxDoneCb;
} UART_CTRL_NEED_TX_DONE_CB_T;

//TTY_CMD_GET_MTU_SIZE
typedef struct
{
	DCL_UINT32 ulmtu_sz;
	DCL_UINT32 dlmtu_sz;
} UART_CTRL_GET_MTU_SIZE_T;

//TTY_CMD_SET_INDICATION
typedef struct
{
	DCL_BOOL need_indication;
} UART_CTRL_SET_INDICATION_T;

/*!
 *	@brief	TTY driver state
 */
typedef enum _tty_drv_state {
	  /*!
	   *  @brief  driver detached state
	   */
      DRV_ST_DETACHED = 0,
	  /*!
	   *  @brief  driver attached state
	   */
      DRV_ST_ATTACHED
} tty_drv_state_e;

//TTY_CMD_GET_DRV_STATE
typedef struct
{
	DCL_UINT32 u4OwnerId;
	tty_drv_state_e drv_state;
} UART_CTRL_GET_DRV_STATE_T;

//TTY_CMD_ASSIGN_RX_IOR
typedef struct
{
	DCL_UINT32 u4OwnerId;
	void *ior;
} UART_CTRL_ASSIGN_RX_IOR_T;

//UART_CMD_CTRL_BREAK
typedef struct
{
  DCL_UINT32 u4OwenrId;
   IO_LEVEL_T rIOLevelBRK;
} UART_CTRL_BREAK_T;

//UART_CMD_CLR_RX_BUF
//UART_CMD_CLR_TX_BUF
typedef struct
{
   DCL_UINT32 u4OwenrId;
} UART_CTRL_CLR_BUFFER_T;

//UART_CMD_SET_BAUDRATE
typedef struct
{
   DCL_UINT32 u4OwenrId;
   UART_BAUDRATE_T baudrate;
} UART_CTRL_BAUDRATE_T;

//UART_CMD_SEND_ISR_DATA
//UART_CMD_SEND_DATA
typedef struct
{
	DCL_UINT32 u4OwenrId;
	DCL_UINT8* puBuffaddr;
	DCL_UINT16 u2Length;
	DCL_UINT8 umode;
	DCL_UINT8 uescape_char;
	DCL_UINT16 u2RetSize;
}UART_CTRL_SEND_DATA_T;

//UART_CMD_SET_AUTOBAUD_DIV
typedef struct
{
   DCL_UINT32 u4OwenrId;
} UART_CTRL_AUTO_BAUDDIV_T;

typedef void (*DCL_UART_TX_FUNC)(DCL_UINT32 u4Port); 
typedef void (*DCL_UART_RX_FUNC)(DCL_UINT32 u4Port) ; 


//UART_CMD_REG_TX_CB
typedef struct
{
   DCL_UINT32 u4OwenrId;
   DCL_UART_TX_FUNC func;
} UART_CTRL_REG_TX_CB_T;

	
//UART_CMD_REG_RX_CB
typedef struct
{
	  DCL_UINT32 u4OwenrId;

   DCL_UART_RX_FUNC func;
} UART_CTRL_REG_RX_CB_T;

typedef enum
{
	UART_TX = 0,
	UART_RX,
	DSP_TX,
	DSP_RX
}UART_IO_DIR;

//UART_CMD_REG_DEF_CB
typedef struct
{
	UART_IO_DIR dir;
}UART_CTRL_REG_DEF_CB_T;

//UART_CMD_GET_UART_BYTE
typedef struct
{
	DCL_UINT8 uByte;
}UART_CTRL_GET_UART_BYTE_T;

//SIO_CMD_GET_UART_BYTE_WITH_TIMEOUT
typedef struct
{
	DCL_UINT8 u1retByte;  
	DCL_UINT8 uByte;
	DCL_UINT32 u4timeout_value;	
}UART_CTRL_GET_UART_BYTE_WITH_TIMEOUT_T;

//UART_CMD_PUT_UART_BYTE
typedef struct
{
	DCL_UINT8  uData;
}UART_CTRL_PUT_UART_BYTE_T;

//UART_CMD_PUT_UART_BYTES
typedef struct
{
	DCL_UINT8* puBuffaddr;
	DCL_UINT16 u2Length;
	
}UART_CTRL_PUT_UART_BYTES_T;

//UART_CMD_CTRL_RI
typedef struct
{
	 DCL_UINT32 u4OwenrId;
	IO_LEVEL_T rIOLevelSRI;

}UART_CTRL_RI_T;

//UART_CMD_CTRL_DTR
typedef struct
{
	 DCL_UINT32 u4OwenrId;
	IO_LEVEL_T rIOLevelDTR;
}UART_CTRL_DTR_T;

//UART_CMD_READ_HW_STATUS
typedef struct
{
	IO_LEVEL_T rIOLevelDSR;
	IO_LEVEL_T rIOLevelCTS;
}UART_CTRL_RHS_T;

//UART_CMD_SET_FIFO_TRIGGER
typedef struct
{
	DCL_UINT16 tx_level;
	DCL_UINT16 rx_level;
}UART_CTRL_SFT_T;

//UART_CMD_POWER_ON
typedef struct
{
	DCL_BOOL bFlag_Poweron;
}UART_CTRL_POWERON_T;

//UART_CMD_CHECK_TX_BUF_EMPTY
typedef struct
{
	DCL_BOOL bFlag;
}UART_CTRL_CHECK_TBE_T;

//	UART_CMD_CHECK_TX_SEND_OUT
typedef struct
{
	DCL_BOOL bFlag;
}UART_CTRL_CHECK_TSO_T;

//UART_CMD_GET_TX_BUF_SIZE
typedef struct
{
	DCL_UINT32* ptotal_size;
	DCL_UINT32* preturn_size;
}UART_CTRL_GET_TBS_T;


//UART_CMD_SLEEP_TX_ENABLE
typedef struct
{
	UART_SLEEP_ON_TX_T bFlag;
}UART_CTRL_SLEEP_ON_TX_ENABLE_T;

//UART_CMD_CTRL_SLEEP_MODE
typedef struct
{
	DCL_BOOL bFlag;
}UART_CTRL_SLEEP_ENABLE_T;


//UART_CMD_BOOT_PUTBYTES
typedef struct
{
	DCL_UINT8* puBuffaddr;
	DCL_UINT16 u2Length;
}UART_CTRL_BOOT_PUTBYTES_T;


//UART_CMD_CTRL_USE_VFIFO
typedef struct
{
	DCL_BOOL	bUseVFifo;
}UART_CTRL_USE_VFIFO_T;	

//UART_CMD_GET_MAX_BAUDRATE
typedef struct
{
	kal_uint32 max_baudrate;
}UART_CTRL_GET_MAXBAUDRATE_T;

//TTY_CMD_EXCEPTION_TX_GPD
typedef struct
{
	void *first_gpd;
	void *last_gpd;
}TTY_CTRL_EXCP_TX_GPD_T;

//TTY_CMD_EXCEPTION_TX_DONE_INFO
typedef struct
{
	void *first_gpd;
	void *last_gpd;
	DCL_UINT32 num;
}TTY_CTRL_EXCP_TX_DONE_INFO_T;

//TTY_CMD_EXCEPTION_HIF_STATE
typedef enum _tty_excp_hif_state {
	HIF_STATE_NORMAL = 0,
	HIF_STATE_TXERROR
} tty_excp_hif_state;
typedef struct
{
	tty_excp_hif_state hif_state;
}TTY_CTRL_EXCP_HIF_STATE_T;

//TTY_CMD_EXCEPTION_ASSIGN_RX_GPD
typedef struct
{
	void *first_gpd;
	void *last_gpd;
}TTY_CTRL_EXCP_ASSIGN_RX_GPD_T;

//TTY_CMD_EXCEPTION_GET_RX_GPD
typedef struct
{
	void *first_gpd;
	void *last_gpd;
	DCL_UINT32 num;
}TTY_CTRL_EXCP_GET_RX_GPD_T;

//TTY_CMD_EXCEPTION_FLUSH_TX
typedef struct
{
	void *first_gpd;
	void *last_gpd;
	DCL_UINT32 num;
}TTY_CTRL_EXCP_FLUSH_TX_T;

//TTY_CMD_EXCEPTION_FLUSH_RX
typedef struct
{
	void *first_gpd;
	void *last_gpd;
	DCL_UINT32 num;
}TTY_CTRL_EXCP_FLUSH_RX_T;

//TTY_CMD_EXCEPTION_HIF_POLL
typedef struct
{
	DCL_BOOL reset_event;
}TTY_CTRL_EXCP_HIF_POLL_T;

typedef enum {
      NONE_VFIFO,
      RX_VFIFO,
      TX_VFIFO,
      TXRX_VFIFO
} UART_TxRx_VFIFO_support;

typedef enum {
      RX_BUF,
      TX_BUF
} UART_buffer;

typedef enum {
   Compensate_None = 0,
   Compensate_Wait,
   Compensate_AT,
   Compensate_at
}UART_Compensate_enum;


typedef enum {
      len_5=5,
      len_6,
      len_7,
      len_8
} UART_bitsPerCharacter;

typedef enum {
      sb_1=1,
      sb_2,
      sb_1_5
} UART_stopBits;

typedef enum {
      pa_none=0,
      pa_odd,
      pa_even,
      pa_mark,      //k2 md2 6589, add for solving driver/peripheral uart module build error
      pa_space
} UART_parity;

typedef enum {
      fc_none=1,
      fc_hw,
      fc_sw
} UART_flowCtrlMode;

typedef struct
{
      UART_baudrate                 baud; 
      UART_bitsPerCharacter         dataBits;
      UART_stopBits                 stopBits;
      UART_parity                   parity;
      UART_flowCtrlMode             flowControl;
      kal_uint8                     xonChar;
      kal_uint8                     xoffChar;
      kal_bool                      DSRCheck;
} UARTDCBStruct;

typedef struct
{
      kal_uint8                      EscChar;
      kal_uint16                     GuardTime;
} UART_ESCDetectStruct;

typedef struct
{
      kal_uint8                      *rx_buffer;   /* data buffer */
      kal_uint8                      *tx_buffer;   /* data buffer */
      kal_uint8                      *txISR_buffer;  /* data buffer */
} UART_RingBufferStruct;


   typedef enum {
      uart_null_buffer=0,
      uart_isr_buffer,
      uart_normal_buffer
   } UART_RingBuffer_Type;

   typedef struct
   {
         UART_RingBuffer_Type            type;
         kal_uint16                      index;
   } UART_RingBuffer_SaveIndex;


typedef struct
{
	kal_uint16	       tst_port_ps;
	kal_uint16         ps_port;	
	UART_baudrate      tst_baudrate_ps;
	UART_baudrate      ps_baudrate;
	kal_bool           High_Speed_SIM_Enabled;
	kal_uint8          swdbg;	
   kal_uint8          uart_power_setting; /* For DCM, Start [Set UART POWER], CTI  */
   kal_uint8          cti_uart_port;
   UART_baudrate      cti_baudrate;
   kal_uint8           tst_port_l1;
   UART_baudrate       tst_baudrate_l1;
    kal_uint8          tst_output_mode;
    kal_uint8	      usb_logging_mode;
    kal_uint16 tst_port_dsp;
    UART_baudrate       tst_baud_rate_dsp;
	kal_uint8   usb_cdrom_config;
	kal_uint16	speech_port;
	kal_uint16	ndis_port;
} port_setting_struct;

/*start of local parameter struct */

typedef struct  
{  
    LOCAL_PARA_HDR          /*  LOCAL_PARA_HDR */
	DCL_UINT16 	port;
}uart_ready_to_read_ind_struct; 

typedef struct  
{       
    LOCAL_PARA_HDR          /*  LOCAL_PARA_HDR */
	DCL_UINT16 	port;
}uart_ready_to_write_ind_struct;
 
 typedef struct  
{       
    LOCAL_PARA_HDR          /*  LOCAL_PARA_HDR */
	DCL_UINT16 	port;
}uart_dsr_change_ind_struct;
 
 typedef struct  
{       
    LOCAL_PARA_HDR          /*  LOCAL_PARA_HDR */
	DCL_UINT16 	port;
}uart_escape_detected_ind_struct;

 typedef struct  
{       
    LOCAL_PARA_HDR          /*  LOCAL_PARA_HDR */
	DCL_UINT16 	port;
}uart_plugin_ind_struct;

 typedef struct  
{       
    LOCAL_PARA_HDR          /*  LOCAL_PARA_HDR */
	DCL_UINT16 	port;
}uart_plugout_ind_struct;  


#define UART_CTRLS \
	  UART_CTRL_INIT_T    rUARTCtrlInit;\
      UART_CTRL_OPEN_T    rUARTCtrlOPEN; \
      UART_CTRL_CLOSE_T	  rUARTCtrlCLOSE; \
      UART_CTRL_GET_BYTES_T rUARTCtrlGETBYTES; \
      UART_CTRL_PUT_BYTES_T rUARTCtrlPUTBYTES; \
      UART_CTRL_RX_AVAIL_T  rUARTCtrlRXAVAIL; \
      UART_CTRL_TX_AVAIL_T  rUARTCtrlTXAVAIL; \
      UART_CTRL_PURGE_T		rUARTCtrlPURGE; \
      UART_CTRL_OWNER_T		rUARTCtrlOWNER; \
      UART_CTRL_FLOW_CTRL_T rUARTCtrlFLOWCTRL; \
      UART_CTRL_CONFIG_ESP_T rUARTCtrlCONFIGESP; \
      UART_CTRL_DCB_T		rUARTCtrlDCB; \
      UART_CTRL_DCD_T       rUARTCtrlDCD;\
      UART_CTRL_BREAK_T      rUARTCtrlBREAK;\
      UART_CTRL_CLR_BUFFER_T	rUARTCtrlCLRBUFFER;\
      UART_CTRL_BAUDRATE_T     rUARTCtrlBAUDRATE;\
      UART_CTRL_SEND_DATA_T     rUARTCtrlSENDDATA;\
      UART_CTRL_AUTO_BAUDDIV_T  rUARTCtrlAUTOBAUDDIV;\
      UART_CTRL_REG_TX_CB_T     rUARTCtrlREGTXCB;\
      UART_CTRL_REG_RX_CB_T    rUARTCtrlREGRXCB;\
      UART_CTRL_GET_UART_BYTE_T  rUARTCtrlGETUARTBYTE;\
	UART_CTRL_GET_UART_BYTE_WITH_TIMEOUT_T rUARTCtrlGETUARTBYTEWithTimeOut;\
      UART_CTRL_PUT_UART_BYTE_T  rUARTCtrlPUTUARTBYTE;\
      UART_CTRL_PUT_UART_BYTES_T rUARTCtrlPUTUARTBYTES;\
      UART_CTRL_RI_T              rUARTCtrlRI;\
      UART_CTRL_DTR_T               rUARTCtrlDTR;\
      UART_CTRL_RHS_T                rUARTCtrlRHS;\
      UART_CTRL_SFT_T				rUARTCtrlSFT;\
	  UART_CTRL_POWERON_T           rUARTCtrlPoweron;\
	  UART_CTRL_CHECK_TBE_T			rUARTCtrlCheckBUFEMP;\
	  UART_CTRL_CHECK_TSO_T			rUARTCtrlCheckTXSendOut;\
	  UART_CTRL_GET_TBS_T			rUARTCtrlGetTxBufSize;\
	  UART_CTRL_SLEEP_ON_TX_ENABLE_T	rUARTCtrlSleepOnTxEnable;\
	  UART_CTRL_SLEEP_ENABLE_T		rUARTCtrlSleepEnable;\
	  UART_CTRL_BOOT_PUTBYTES_T		rUARTCtrlBootPutBytes;\
	  UART_CTRL_USE_VFIFO_T			rUARTCtrlUseVFifo;\
      UART_CTRL_REG_DEF_CB_T		rUARTCtrlRegDefCB;\
      UART_CTRL_GET_MAXBAUDRATE_T   rUARTCtrlGetMaxBaudrate;\
	  UART_CTRL_GET_FC_T			rUARTCtrlGetFC;\
	  UART_CTRL_NEED_TX_DONE_CB_T	rUARTCtrlNeedTxDoneCb; /*new*/\
	  UART_CTRL_GET_DRV_STATE_T		rUARTCtrlGetDrvState; /*new*/\
	  UART_CTRL_ASSIGN_RX_IOR_T		rUARTCtrlAssignRxIor; /*new*/ \
	  UART_CTRL_PUT_BYTES_IOR_T		rUARTCtrlPUTBYTESIOR; /*new*/ \
	  UART_CTRL_GET_CHUNK_SIZE_T	rUARTCtrlGETCHUNKSIZE; /*new*/\
	  UART_CTRL_GET_MTU_SIZE_T      rUARTCtrlGETMTUSIZE; /*new*/\
	  UART_CTRL_SET_INDICATION_T    rUARTCtrlSETINDICATION; /*new*/\
	  TTY_CTRL_EXCP_TX_GPD_T		rTTYCtrlExcpTxGPD; /*new*/\
	  TTY_CTRL_EXCP_TX_DONE_INFO_T	rTTYCtrlExcpTxDoneInfo; /*new*/\
	  TTY_CTRL_EXCP_HIF_STATE_T		rTTYCtrlExcpHifState; /*new*/\
	  TTY_CTRL_EXCP_ASSIGN_RX_GPD_T	rTTYCtrlExcpAssignRxGPD; /*new*/\
	  TTY_CTRL_EXCP_GET_RX_GPD_T	rTTYCtrlExcpGetRxGPD; /*new*/\
	  TTY_CTRL_EXCP_FLUSH_TX_T      rTTYCtrlExcpFlushTx; /*new*/\
	  TTY_CTRL_EXCP_FLUSH_RX_T	    rTTYCtrlExcpFlushRx; /*new*/\
      TTY_CTRL_EXCP_HIF_POLL_T	    rTTYCtrlExcpHifPoll; /*new*/

#endif
#endif


#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_UART_H_PROTOTYPE__
#define __DCL_UART_H_PROTOTYPE__

typedef DCL_STATUS(*SeriPort_HANLDER_CB)(DCL_DEV dev, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
typedef struct 
{
	SIO_TYPE_T DevType;
	SeriPort_HANLDER_CB SeriportHandlerCb;
}Seriport_HANDLER_T;

/*!
 *	@brief	TTY flag
 */
typedef enum _tty_flag {
   /*!
	*  @brief  use new TTY Tx path
	*/
   TTY_FLAG_NEW_TX		= (1 << 0),
   /*!
	*  @brief  use new TTY Rx path
	*/   
   TTY_FLAG_NEW_RX		= (1 << 1),
} tty_flag_e;

typedef DCL_STATUS(*tty_txdone_cb)(DCL_HANDLE handle, module_type source_id, tty_io_request_t *tx_ior);
typedef DCL_STATUS(*tty_rx_cb)(DCL_HANDLE handle, module_type source_id, tty_io_request_t *rx_ior);
typedef DCL_STATUS(*tty_drv_state_change_cb)(DCL_HANDLE handle, tty_drv_state_e state);



/*!
* 	@function	DclSerialPort_Open
*	@brief		This function is to open the UART module and get a handle.
*	@param		dev			Port number. it can take DCL_UART_DEV as reference
*	@param		flags		module_type | FLAGS_UART_USE_VFIFO
*							module_type: KAL module type enum value
*							FLAGS_UART_USE_VFIFO: flags that specifies to use Virtual FIFO or not for UART device. Note that it's only valide for eDev with DCL_UART1, DCL_UART2, DCL_UART3(if exists)
*							[Note] Currently TTY doesn't handle flags!! This parameter is kept for backward compatible.
*	@result		STATUS_FAIL				Open failed.
*	@result		STATUS_ALREADY_OPENED	This device has already been opened.
*	@result		STATUS_INVALID_DEVICE	The device is not valid.
*	@result		STATUS_SET_VFIFO_FAIL	Fail to use Vitual FIFO for the UART port.
*	@result		other value				a valid handle
*
*/
extern DCL_HANDLE DclSerialPort_Open(DCL_DEV dev, DCL_FLAGS flags);
 
/*!
* 	@function	DclSerialPort_Configure
*	@brief		This function is to configure for the UART module. [Note] Currenlty this function is not used.
*	@param		handle		a valid handle return by DclSerialPort_Open()
*	@param		configure	a ponter to UART_CONFIG_T structure which is a member of union DCL_CONFIGURE_T
*	@result		STATUS_OK				successfully configure.
*	@result		STATUS_INVALID_HANDLE	It's a invalid handle.
*	@result		STATUS_NOT_OPENED		The module has not been opened.
*	@result		STATUS_INVALID_CONFIGURATION	the configuration is not valid. 
*/
extern DCL_STATUS DclSerialPort_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
 
/*!
*	@function	DclSerialPort_Control
*	@brief		This function is support UART module commands. It is called to send command to control the UART module.
*	@param		handle 		a valid handle return by DclSerialPort_Open()
*	@param		cmd 		dcl uart commands
*	@param		data 		pointer to the corresponding data structure of command
*	@result 	STATUS_OK 				command is executed successfully.
*	@result 	STATUS_INVALID_CMD		It's a invalid command.
*	@result 	STATUS_INVALID_HANDLE	It's a invalid handle.
*/
extern DCL_STATUS DclSerialPort_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
 
/*!
*	@function	DclSerialPort_Close
*	@brief		This function is to close the UART module.
*	@param		handle 		hanlde previous got from DclSerialPort_Open()
*	@result 	STATUS_OK 				Successfully close the UART module.
*	@result 	STATUS_INVALID_HANDLE	It's invalid handle.
*	@result 	STATUS_NOT_OPENED		The UART module hasn't been opened yet.
*/
extern DCL_STATUS DclSerialPort_Close(DCL_HANDLE handle);

/* ---------------------------------------- General --------------------------------------------- */ 
/*!
*	@function	DclSerialPort_Initialize
*	@brief		This function is to initialize TTY module..
*	@param		none
*	@result 	STATUS_OK 				successfully initialize TTY module.
*	@result 	STATUS_FAIL				initialized failed..
*/
extern DCL_STATUS DclSerialPort_Initialize(void);

/* ----------------------------------- Export to upper layer --------------------------------------- */ 
/*!
*	@function	[New TTY API] DclSerialPort_UpModuleInit
*	@brief		This function is to initialize/start designated COM Port for upper module.
*	@param		handle					a valid handle return by DclSerialPort_Open()
*	@param		module_id				upper module id
*	@param		flag					TTY COM Port attribute. Currently they are TTY_FLAG_NEW_TX or TTY_FLAG_NEW_RX.
*										Upper module can initialize flag with new Tx/Rx flow (gpd based) or conventional Tx/Rx (buffer/length based) flow.
*										ex. New Tx and Conventional Rx - DclSerialPort_UpModuleReinit(handle, module_id, TTY_FLAG_NEW_TX);
*	@result 	STATUS_OK				Init COM Port device successfully.
*	@result 	STATUS_INVALID_HANDLE	It's a invalid handle.
*	@result 	STATUS_ALREADY_OPENED	The COM Port has been initialized by other module.
*	@result 	STATUS_DEVICE_NOT_EXIST The corresponding device driver of COM Port has not been initialized.
*/
extern DCL_STATUS DclSerialPort_UpModuleInit(DCL_HANDLE handle, module_type module_id, int flag);
 
/*!
*	@function	[New TTY API] DclSerialPort_UpModuleReinit
*	@brief		This function is to re-init TTY COM Port setting. This function is called when owner is changed.
*	@param		handle					a valid handle return by DclSerialPort_Open()
*	@param		module_id				upper module id
*	@param		flag					TTY COM Port attribute. Currently they are TTY_FLAG_NEW_TX or TTY_FLAG_NEW_RX.
*		 								Upper module can re-init flag with new Tx/Rx flow (gpd based) or conventional Tx/Rx (buffer/length based) flow.
*		 								ex. Reinit to New Tx and Conventional Rx - DclSerialPort_UpModuleReinit(handle, module_id, TTY_FLAG_NEW_TX);
*	@result 	STATUS_OK				Re-Init COM Port device successfully.
*	@result 	STATUS_INVALID_HANDLE	It's a invalid handle.
*	@result 	STATUS_NOT_OPENED		The COM Port has not been initialized.
*	@result 	STATUS_DEVICE_NOT_EXIST The corresponding device driver of COM Port has not been initialized.
*/
extern DCL_STATUS DclSerialPort_UpModuleReinit(DCL_HANDLE handle, module_type module_id, int flag);
 
/*!
*	@function	[New TTY API] DclSerialPort_UpModuleDeinit
*	@brief		This function is to de-init/de-register COM Port.
*	@param		handle					a valid handle return by DclSerialPort_Open()
*	@result 	STATUS_OK				Deinit COM Port device successfully.
*	@result 	STATUS_INVALID_HANDLE	It's a invalid handle.
*	@result 	STATUS_NOT_OPENED		The COM Port has not been initialized.
*	@result 	STATUS_DEVICE_NOT_EXIST The corresponding device driver of COM Port has not been initialized.
*/
extern DCL_STATUS DclSerialPort_UpModuleDeinit(DCL_HANDLE handle);
 
/*!
*	@function	[New TTY API] DclSerialPort_UpModuleRegisterCb
*	@brief		This function is for upper layer module to register callback function.
*	@param		handle				a valid handle return by DclSerialPort_Open()
*	@param		rx_cb 				rx callback function, driver send receiving data to upper layer through this rx callback function
*	@param		tx_done_cb 			tx done callback function, this callback function will be called when data has been sent
*	@param		drv_state_change_cb	driver state change callback function, it notify the upper layer module when driver state is changed, ex. USB disconnect
*	@result 	STATUS_OK				Register callback function successfully.
*	@result 	STATUS_INVALID_HANDLE	It's a invalid handle.
*	@result 	STATUS_NOT_OPENED 		The COM Port has not been initialized.
*	@result 	STATUS_DEVICE_NOT_EXIST The corresponding device driver of COM Port has not been initialized.
*	@result 	STATUS_FAIL 			Failed for other reasons.
*/
extern DCL_STATUS DclSerialPort_UpModuleRegisterCb(DCL_HANDLE handle, tty_rx_cb rx_cb, tty_txdone_cb tx_done_cb, tty_drv_state_change_cb drv_state_change_cb);
 
/*!
*	@function	[New TTY API] DclSerialPort_UpModuleTransmit
*	@brief		This function is to transmit data to COM Port in ior format.
*	@param		handle		a valid handle return by DclSerialPort_Open()
*	@param		ior			pointer to tx io request which is sent to COM Port driver
*	@result 	STATUS_OK				Transmit ior successfully.
*	@result 	STATUS_INVALID_HANDLE	It's a invalid handle.
*	@result 	STATUS_FAIL 			Failed for other reasons.
*/
extern DCL_STATUS DclSerialPort_UpModuleTransmit(DCL_HANDLE handle, tty_io_request_t *ior);

/*!
*	@function	[New TTY API] DclSerialPort_UpModuleTransmitLight
*	@brief		This function is to transmit data to COM Port in ior format and light-weight.
*				Before user use this Tx function, it must calculate tx checksum and flush GPD in advance.
*	@param		handle		a valid handle return by DclSerialPort_Open()
*	@param		ior			pointer to tx io request which is sent to COM Port driver
*	@result 	STATUS_OK				Transmit ior successfully.
*	@result 	STATUS_INVALID_HANDLE	It's a invalid handle.
*	@result 	STATUS_FAIL 			Failed for other reasons.
*/
extern DCL_STATUS DclSerialPort_UpModuleTransmitLight(DCL_HANDLE handle, tty_io_request_t *ior);

/*!
*	@function	[New TTY API] DclSerialPort_UpModuleAssignRxIor
*	@brief		This function is to assign empty Rx ior to driver for data receiving.
*	@param		handle		a valid handle return by DclSerialPort_Open()
*	@param		rx_ior		pointer to rx io request for data receiving
*	@result 	STATUS_OK				Assign Rx ior successfully.
*	@result 	STATUS_INVALID_HANDLE	It's a invalid handle.
*	@result 	STATUS_FAIL				Failed for other reasons.
*/
extern DCL_STATUS DclSerialPort_UpModuleAssignRxIor(DCL_HANDLE handle, tty_io_request_t *rx_ior);

/* ------------------------------------ Export to driver ------------------------------------------- */ 
/*!
*	@function	DclSerialPort_DrvRegisterCb
*	@brief		This function is to register callback funtion for the UART module or COM Port class driver.
*	@param		handle 		        a valid handle return by DclSerialPort_Open()
*	@param		seriport_handler	the structure contains callback function and device type. 
                                                TTY would send commands (SIO/UART/USB/TTY/...) to driver through this callback function when the corresponding event happens.
*	@result 	STATUS_OK 				successful.
*	@result 	STATUS_INVALID_HANDLE	It's a invalid handle.
*	@result 	STATUS_ALREADY_OPENED	This device has already been opened.
*	@result 	STATUS_INVALID_ARGUMENT	The parameter is invalid, ex. uart_handler_cb is NULL.
*/
extern DCL_STATUS DclSerialPort_DrvRegisterCb(DCL_HANDLE handle, Seriport_HANDLER_T* seriport_handler);

/*!
*	@function	DclSerialPort_DrvDeRegisterCb
*	@brief		This function is to De-register callback funtion for the UART module or COM Port class driver.
*	@param		handle 		        a valid handle return by DclSerialPort_Open()
*	
*	@result 	STATUS_OK 				 successful.
*	@result 	STATUS_INVALID_HANDLE	 It's a invalid handle.
*	@result 	STATUS_INVALID_OPERATION This device has already been de-registered or driver state is attached.
*/
extern DCL_STATUS DclSerialPort_DrvDeRegisterCb(DCL_HANDLE handle);

/*!
*	@function	[New TTY API] DclSerialPort_DrvAttach
*	@brief		This function is for driver to inform TTY that the device is attached/connected.
*	@param		handle		a valid handle return by DclSerialPort_Open()
*	@result 	STATUS_OK				successful.
*	@result 	STATUS_INVALID_HANDLE	It's a invalid handle.
*	@result 	STATUS_DEVICE_NOT_EXIST The corresponding device driver of COM Port has not been initialized.
*/
extern DCL_STATUS DclSerialPort_DrvAttach(DCL_HANDLE handle);
 
/*!
*	@function	[New TTY API] DclSerialPort_DrvDetach
*	@brief		This function is for driver to inform TTY that the device is detached/disconnected.
*	@param		handle		a valid handle return by DclSerialPort_Open()
*	@result 	STATUS_OK				successful.
*	@result 	STATUS_INVALID_HANDLE	It's a invalid handle.
*	@result 	STATUS_DEVICE_NOT_EXIST	The corresponding device driver of COM Port has not been initialized.
*/
extern DCL_STATUS DclSerialPort_DrvDetach(DCL_HANDLE handle);
 
/*!
*	@function	[New TTY API] DclSerialPort_DrvRx
*	@brief		This function is for driver to send back the received data to TTY/upper layer.
*	@param		handle		a valid handle return by DclSerialPort_Open()
*	@param		source_id	driver module id
*	@param		rx_ior		received data with ior format
*	@result 	STATUS_OK				successfully register the callback function.
*	@result 	STATUS_INVALID_HANDLE	It's a invalid handle.
*	@result 	STATUS_NOT_OPENED		The COM Port is not opened by upper layer.
*/
extern DCL_STATUS DclSerialPort_DrvRx(DCL_HANDLE handle, module_type source_id, void *rx_ior);
 
/*!
*	@function	[New TTY API] DclSerialPort_DrvTxDone
*	@brief		This function is for driver to send back the transmitted (tx done) data to TTY/upper layer.
*				This function is called if "need tx done callback" is configured YES.
*	@param		handle 		a valid handle return by DclSerialPort_Open()
*	@param		source_id	driver module id
*	@param		tx_ior		transmitted data with ior format
*	@result 	STATUS_OK 				successful.
*	@result 	STATUS_INVALID_HANDLE	It's a invalid handle.
*	@result 	STATUS_NOT_OPENED		The COM Port is not opened by upper layer.
*/
extern DCL_STATUS DclSerialPort_DrvTxDone(DCL_HANDLE handle, module_type source_id, void *tx_ior);


#endif // #ifndef __DCL_UART_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE

