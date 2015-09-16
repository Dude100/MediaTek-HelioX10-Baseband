/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *    dcl_idc.h
 *
 * Project:
 * --------
 *   MOLY_Software
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for IDC.
 *
 * Author:
 * -------
 *
 *  Ansel Liao
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_IDC_H_STRUCT__
#define __DCL_IDC_H_STRUCT__

#include "kal_general_types.h"

#define	MAX_NUM_EVENT	20



/*******************************************************************************
 * DCL_OPTIONS for IDC
 *******************************************************************************/
#define IDC_OPTIONS


/*******************************************************************************
 * DCL_CONFIGURE_T for IDC
 *******************************************************************************/
#define IDC_CONFIGS


/*******************************************************************************
 * DCL_EVENT for IDC
 *******************************************************************************/
#define IDC_EVENTS


/*******************************************************************************
 * DCL_CTRL_CMD for IDC
 *******************************************************************************/
/* The IDC Command Values in DCL_CTRL_CMD_T Enum of dcl.h */
#ifdef __BUILD_DOM__
typedef enum {
	IDC_CMD_SET_DCB_CONFIG,
	IDC_CMD_GET_DCB_CONFIG,
	IDC_CMD_SET_BAUDRATE,
	IDC_CMD_GET_MAX_BAUDRATE,
	IDC_CMD_SET_FIFO_TRIGGER,
	IDC_CMD_SET_PM_CONFIG,
	IDC_CMD_GET_PM_CONFIG,
	IDC_CMD_SCHEDULE_EVENT,
	IDC_CMD_SCHEDULE_START,
	IDC_CMD_STOP_EVENT,
	IDC_CMD_PURGE,
	IDC_CMD_GET_SCHEDULE_STATUS,
	IDC_CMD_CHECK_EVENT_SEND_OUT,
	IDC_CMD_SET_PIN_CONFIG,
	IDC_CMD_GET_PIN_CONFIG,
} DCL_CTRL_CMD_T;
#else	// __BUILD_DOM__
#define IDC_CMDS			\
	IDC_CMD_SET_DCB_CONFIG,		\
	IDC_CMD_GET_DCB_CONFIG,		\
	IDC_CMD_SET_BAUDRATE,		\
	IDC_CMD_GET_MAX_BAUDRATE,	\
	IDC_CMD_SET_FIFO_TRIGGER,	\
	IDC_CMD_SET_PM_CONFIG,		\
	IDC_CMD_GET_PM_CONFIG,		\
	IDC_CMD_SCHEDULE_EVENT,		\
	IDC_CMD_SCHEDULE_START,		\
	IDC_CMD_STOP_EVENT,		\
	IDC_CMD_PURGE,			\
	IDC_CMD_GET_SCHEDULE_STATUS,	\
	IDC_CMD_CHECK_EVENT_SEND_OUT,	\
	IDC_CMD_SET_PIN_CONFIG,		\
	IDC_CMD_GET_PIN_CONFIG,
#endif	// __BUILD_DOM__


/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/
// For IDC_CMD_SET_DCB_CONFIG command
// For IDC_CMD_GET_DCB_CONFIG command
typedef struct
{
	kal_uint32	u4Baud;		// baudrate
	kal_uint8	u1DataBits;	// UART_BITS_PER_CHAR_T
	kal_uint8	u1StopBits;	// UART_STOP_BITS_T
	kal_uint8	u1Parity;	// UART_PARTIY_T
} IDC_CTRL_DCB_CONFIG_T;

// For IDC_CMD_SET_BAUDRATE command
// For IDC_CMD_GET_MAX_BAUDRATE command
typedef struct 
{
	kal_uint32	baudrate;	// baudrate
} IDC_CTRL_BAUDRATE_T;

// For IDC_CMD_SET_FIFO_TRIGGER command
typedef struct 
{
	kal_uint8	rx_threshold;	// threshold of RX FIFO
} IDC_CTRL_SET_FIFO_TRIGGER_T;

// For IDC_CMD_SET_PM_CONFIG command
// For IDC_CMD_GET_PM_CONFIG command
typedef struct 
{
	kal_bool	start;		// 0: finish; 1: start
	kal_uint8	priority;	// priority
	kal_uint8	priority_bit_en;// priority bit enable
	kal_uint8	pattern;	// pattern
	kal_uint8	pattern_bit_en;	// pattern bit enable
} IDC_CTRL_PM_CONFIG_T;

// For IDC_CMD_SCHEDULE_EVENT command
typedef struct
{
	kal_uint8 data[2];		// 2-byte data per event
	kal_uint16 offset;		// time offset
} IDC_EVENT_T;

typedef struct 
{
	kal_uint8	schedule_num;	// schedule 0/1
	kal_uint8	num_event;	// number of events
	IDC_EVENT_T	schedule_event[MAX_NUM_EVENT];	// event columns
} IDC_CTRL_SCHEDULE_EVENT_T;

// For IDC_CMD_SCHEDULE_START command
typedef struct 
{
	kal_uint8	schedule_num;	// schedule 0/1
	kal_uint32	base_time;	// base time
} IDC_CTRL_SCHEDULE_START_T;

// For IDC_CMD_STOP_EVENT command
typedef struct
{
	kal_uint8 schedule_num;		// schedule 0/1
	kal_uint32 bitmap;		// events need to be stopped
} IDC_CTRL_STOP_EVENT_T;

// For IDC_CMD_PURGE
typedef struct
{
	UART_buffer dir;
} IDC_CTRL_PURGE_T;

// For IDC_CMD_GET_SCHEDULE_STATUS
typedef struct
{
	kal_uint32 schedule_status[2];	// schedule_status[n] is for schedule n (bitmap)
} IDC_CTRL_GET_SCHEDULE_STATUS_T;

// For IDC_CMD_CHECK_EVENT_SEND_OUT
typedef struct
{
	kal_bool send_out;		// all events are sent out
} IDC_CTRL_CHECK_EVENT_SEND_OUT_T;

// For IDC_CMD_SET_PIN_CONFIG
typedef enum
{
	IDC_INTERNAL_PIN,
	IDC_EXTERNAL_PIN,
} IDC_PIN_MODE_T;

typedef struct
{
	IDC_PIN_MODE_T pin_mode;
} IDC_CTRL_PIN_CONFIG_T;

/* The IDC Command Parameter Data Structure for Each Command in DCL_CTRL_DATA_T Enum of dcl.h */
#ifdef __BUILD_DOM__
typedef union 
{
	IDC_CTRL_DCB_CONFIG_T		r_idc_ctrl_dcb_config;			// Data Structure for IDC_CMD_SET_DCB_CONFIG, IDC_CMD_GET_DCB_CONFIG
	IDC_CTRL_BAUDRATE_T		r_idc_ctrl_baudrate;			// Data Structure for IDC_CMD_SET_BAUDRATE, IDC_CMD_GET_MAX_BAUDRATE
	IDC_CTRL_SET_FIFO_TRIGGER_T	r_idc_ctrl_set_fifo_trigger;		// Data Structure for IDC_CMD_SET_FIFO_TRIGGER
	IDC_CTRL_PM_CONFIG_T		r_idc_ctrl_pm_config;			// Data Structure for IDC_CMD_SET_PM_CONFIG, IDC_CMD_GET_PM_CONFIG
	IDC_CTRL_SCHEDULE_EVENT_T	r_idc_ctrl_schedule_event;		// Data Structure for IDC_CMD_SCHEDULE_EVENT
	IDC_CTRL_SCHEDULE_START_T	r_idc_ctrl_schedule_start;		// Data Structure for IDC_CMD_SCHEDULE_EVENT
	IDC_CTRL_STOP_EVENT_T		r_idc_ctrl_stop_event;			// Data Structure for IDC_CMD_STOP_EVENT
	IDC_CTRL_PURGE_T		r_idc_ctrl_purge;			// Data Structure for IDC_CMD_PURGE
	IDC_CTRL_GET_SCHEDULE_STATUS_T	r_idc_ctrl_get_schedule_status;		// Data Structure for IDC_CMD_GET_SCHEDULE_STATUS
	IDC_CTRL_CHECK_EVENT_SEND_OUT_T	r_idc_ctrl_check_event_send_out;	// Data Structure for IDC_CMD_CHECK_EVENT_SEND_OUT
	IDC_CTRL_PIN_CONFIG_T		r_idc_ctrl_pin_config;			// Data Structure for IDC_CTRL_PIN_CONFIG_T
} DCL_CTRL_DATA_T;
#else /* __BUILD_DOM__ */
#define IDC_CTRLS \
	IDC_CTRL_DCB_CONFIG_T		r_idc_ctrl_dcb_config; \
	IDC_CTRL_BAUDRATE_T		r_idc_ctrl_baudrate; \
	IDC_CTRL_SET_FIFO_TRIGGER_T	r_idc_ctrl_set_fifo_trigger; \
	IDC_CTRL_PM_CONFIG_T		r_idc_ctrl_pm_config; \
	IDC_CTRL_SCHEDULE_EVENT_T	r_idc_ctrl_schedule_event; \
	IDC_CTRL_SCHEDULE_START_T	r_idc_ctrl_schedule_start; \
	IDC_CTRL_STOP_EVENT_T		r_idc_ctrl_stop_event; \
	IDC_CTRL_PURGE_T		r_idc_ctrl_purge; \
	IDC_CTRL_GET_SCHEDULE_STATUS_T	r_idc_ctrl_get_schedule_status; \
	IDC_CTRL_CHECK_EVENT_SEND_OUT_T	r_idc_ctrl_check_event_send_out; \
	IDC_CTRL_PIN_CONFIG_T		r_idc_ctrl_pin_config;
#endif /* __BUILD_DOM__ */

// Support list of IDC driver
typedef struct
{
	kal_bool idc;
	kal_bool gpio;
	kal_bool uart;
} IDC_SUPPORT_T;

#endif // #ifndef __DCL_IDC_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT   

#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_IDC_H_PROTOTYPE__
#define __DCL_IDC_H_PROTOTYPE__

/*************************************************************************
* FUNCTION
*  DclIDC_GetSupport
*
* DESCRIPTION
*  This function is to get the support list of IDC driver.
*
* PARAMETERS
*  support: [IN] IDC_SUPPORT_T *support
*	1. idc:		Indicate whether or not idc driver is supported
*	2. gpio:	Indicate whether or not GPIO Co-Exist will be used after idc_init
*	3. uart:	Indicate whether or not UART will be used after idc_init
*
* RETURNS
*  Return the support list
*
* RETURN VALUES
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclIDC_GetSupport(IDC_SUPPORT_T *support);

/*************************************************************************
* FUNCTION
*  DclIDC_Initialize
*
* DESCRIPTION
*  This function is to initialize IDC module
*
* RETURNS
*  Return the status of DclIDC_Initialize
*
* RETURN VALUES
*  STATUS_OK: Initialize Finished
*
*************************************************************************/
extern DCL_STATUS DclIDC_Initialize(void);


/*************************************************************************
* FUNCTION
*  DclIDC_Open
*
* DESCRIPTION
*  This function is to open the IDC module and return a handle
*
* PARAMETERS
*  dev: [IN] Only valid for DCL_IDC
*  flags: [IN] No sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  Return DCL_HANDLE of IDC
*
* RETURN VALUES
*  DCL_HANDLE_INVALID : Open failed
*  Other value : A valid handle
*
*************************************************************************/
extern DCL_HANDLE DclIDC_Open(DCL_DEV dev, kal_uint32 flags);


/*************************************************************************
* FUNCTION
*  DclIDC_ReadData
*
* DESCRIPTION
*  This function is not supported for the IDC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclIDC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);


/*************************************************************************
* FUNCTION
*  DclIDC_WriteData
*
* DESCRIPTION
*  This function is not supported for the IDC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclIDC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);


/*************************************************************************
* FUNCTION
*  DclIDC_Configure
*
* DESCRIPTION
*  This function is not supported for the IDC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclIDC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);


/*************************************************************************
* FUNCTION
*  DclIDC_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the IDC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclIDC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);


/*************************************************************************
* FUNCTION
*  DclIDC_Control
*
* DESCRIPTION
*  This function is to send command to control the IDC module.
*
* PARAMETERS
*  handle: [IN] The handle value returned from DclIDC_Open
*  cmd: [IN] A control command for IDC module
*	1. IDC_CMD_SET_DCB_CONFIG:		to config DCB (baudrate, data bits, stop bits, and parity bits)
*	2. IDC_CMD_GET_DCB_CONFIG:		to get DCB config from driver
*	3. IDC_CMD_SET_BAUDRATE:		to set baud rate
*	4. IDC_CMD_GET_MAX_BAUDRATE:		to get max baudrate
*	5. IDC_CMD_SET_FIFO_TRIGGER:		to set threshold of idc rx fifo
*	6. IDC_CMD_SET_PM_CONFIG:		to set pattern matching confg (start/finish priority/pattern, pariority/pattern bit enable)
*	7. IDC_CMD_GET_PM_CONFIG:		to get pattern matching
*	8. IDC_CMD_SCHEDULE_EVENT:		to schedule events
*	9. IDC_CMD_SCHEDULE_START:		to run schedule
*	10. IDC_CMD_STOP_EVENT:			to stop specific event from specific schedule
*	11. IDC_CMD_PURGE:			to clean IDC RX FIFO
*	12. IDC_CMD_GET_SCHEDULE_STATUS:	to get status of schedule (bitmap, busy:1, idle:0)
*	13. IDC_CMD_CHECK_EVENT_SEND_OUT:	to check all events are sent out from IDC or not
*	14. IDC_CMD_SET_PIN_CONFIG:		to set pinmux beteen internal and external pins (K2 Only)
*	15. IDC_CMD_GET_PIN_CONFIG:		to get pinumx config (K2 Only)
*
*  data: [IN] The data of the control command
*	1. IDC_CTRL_DCB_CONFIG_T:		pointer to an IDC_CTRL_DCB_CONFIG_T structure
*	2. IDC_CTRL_BAUDRATE_T:			pointer to an IDC_CTRL_BAUDRATE_T structure 
*	3. IDC_CTRL_SET_FIFO_TRIGGER_T:		pointer to an IDC_CTRL_SET_FIFO_TRIGGER_T structure 
*	4. IDC_CTRL_PM_CONFIG_T:		pointer to an IDC_CTRL_PM_CONFIG_T structure
*	5. IDC_CTRL_SCHEDULE_EVENT_T:		pointer to an IDC_CTRL_SCHEDULE_EVENT_T structure
*	6. IDC_CTRL_SCHEDULE_START_T:		pointer to an IDC_CTRL_SCHEDULE_START_T structure
*	7. IDC_CTRL_STOP_EVENT_T:		pointer to an IDC_CTRL_STOP_EVENT_T structure
*	8. IDC_CTRL_PURGE_T:			pointer to an IDC_CTRL_PURGE structure
*	9. IDC_CTRL_GET_SCHEDULE_STATUS_T:	pointer to an IDC_CTRL_GET_SCHEDULE_STATUS_T structure
*	10. IDC_CTRL_CHECK_EVENT_SEND_OUT_T:	pointer to an IDC_CTRL_CHECK_EVENT_SEND_OUT_T structure
*	11. IDC_CTRL_PIN_CONFIG_T:		pointer to an IDC_CTRL_PIN_CONFIG_T structure
*
* RETURNS
*  Return the status of DclIDC_Control
*
* RETURN VALUES
*  STATUS_OK: Command is executed successfully.
*  STATUS_FAIL: Command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
extern DCL_STATUS DclIDC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);

/*************************************************************************
* FUNCTION
*  DclIDC_conn_txrx_count
*
* DESCRIPTION
*  This function is to start/end counting BT_80211_RX and BT_80211_TX
*
* PARAMETERS
*  is_start: [IN]	KAL_TRUE: Start counting
*			KAL_FALSE: End counting
*
* RETURNS
*  Return the status of DclIDC_conn_txrx_count
*
* RETURN VALUES
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclIDC_conn_txrx_count(kal_bool is_start);

/*************************************************************************
* FUNCTION
*  DclIDC_Close
*
* DESCRIPTION
*  This function is to close the IDC module.
*
* PARAMETERS
*  handle: [IN] The returned handle value of DclIDC_Open
*
* RETURNS
*  Return the status of DclIDC_Close
*
* RETURN VALUES
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclIDC_Close(DCL_HANDLE handle);

// MoDIS parser skip end

#endif // #ifndef __DCL_IDC_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE
