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
 *    dcl_dhl.c
 *
 * Project:
 * --------
 *   MOLY_Software
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the IDC driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#define DCL_IDC_INTERFACE

#include "drv_features.h"
#include "dcl.h"
#ifdef DCL_IDC_INTERFACE
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "dcl_idc.h"
#include "drv_idc.h"

// Global variable for DCL DCL API usage
#define DCL_IDC_MAGIC_NUM			(0x40000000)
#define DCL_IDC_IS_HANDLE_MAGIC(handle_)	((handle_) & DCL_IDC_MAGIC_NUM)
#define DCL_IDC_GET_DEV(handle_)		((handle_) & (~DCL_IDC_MAGIC_NUM))

/*************************************************************************
* FUNCTION
*  DclIDC_GetSupport
*
* DESCRIPTION
*  This function is to get the support list of IDC driver.
*
* PARAMETERS
*  support: [IN]
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
DCL_STATUS DclIDC_GetSupport(IDC_SUPPORT_T *support)
{
	drv_idc_get_support(support);
	
	return STATUS_OK;
}

/*************************************************************************
* FUNCTION
*  DclIDC_Initialize
*
* DESCRIPTION
*  This function is to initialize IDC module
*
* PARAMETERS
*  None
*
* RETURNS
*  Return the status of DclIDC_Initialize
*
* RETURN VALUES
*  STATUS_OK: Initialize Finished
*
*************************************************************************/
DCL_STATUS DclIDC_Initialize(void)
{
	DCL_STATUS status = STATUS_UNSUPPORTED;

	drv_idc_init();

	status = STATUS_OK;

	return status;
}

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
DCL_HANDLE DclIDC_Open(DCL_DEV dev, kal_uint32 flags)
{
	if (dev != DCL_IDC)
	{
		ASSERT(0);
		return DCL_HANDLE_INVALID;		// Incorrecr device ID
	}

	drv_idc_open(flags);

	return (DCL_IDC_MAGIC_NUM | dev);
}

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
DCL_STATUS DclIDC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

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
DCL_STATUS DclIDC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

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
DCL_STATUS DclIDC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclIDC_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the IDC module.
*
* PARAMETERS
*  handle: the returned handle value of DclIDC_Open
*  event: Supported events:
*  callback: the callback function for registered events
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclIDC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_UNSUPPORTED;
}


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
DCL_STATUS DclIDC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_STATUS return_value = STATUS_INVALID_DCL_HANDLE;
	// Check magic number
	if(DCL_IDC_IS_HANDLE_MAGIC(handle) == 0)
	{
		ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}

	switch(cmd)
	{
		case IDC_CMD_SET_DCB_CONFIG:
		{
			IDC_CTRL_DCB_CONFIG_T *pr_ctrl_dcb_config;
			pr_ctrl_dcb_config = &(data->r_idc_ctrl_dcb_config);
			drv_idc_set_dcb_config(*pr_ctrl_dcb_config);
			return_value = STATUS_OK;
			break;
		}
		case IDC_CMD_GET_DCB_CONFIG:
		{
			IDC_CTRL_DCB_CONFIG_T *pr_ctrl_dcb_config;
			pr_ctrl_dcb_config = &(data->r_idc_ctrl_dcb_config);
			drv_idc_get_dcb_config(pr_ctrl_dcb_config);
			return_value = STATUS_OK;
			break;
		}
		case IDC_CMD_SET_BAUDRATE:
		{
			IDC_CTRL_BAUDRATE_T *pr_ctrl_baudrate;
			pr_ctrl_baudrate = &(data->r_idc_ctrl_baudrate);
			drv_idc_set_baudrate(pr_ctrl_baudrate->baudrate);
			return_value = STATUS_OK;
			break;
		}
		case IDC_CMD_GET_MAX_BAUDRATE:
		{
			IDC_CTRL_BAUDRATE_T *pr_ctrl_baudrate;
			pr_ctrl_baudrate = &(data->r_idc_ctrl_baudrate);
			pr_ctrl_baudrate->baudrate = 4000000;
			return_value = STATUS_OK;
			break;
		}
		case IDC_CMD_SET_FIFO_TRIGGER:
		{
			IDC_CTRL_SET_FIFO_TRIGGER_T *pr_ctrl_set_fifo_trigger;
			pr_ctrl_set_fifo_trigger = &(data->r_idc_ctrl_set_fifo_trigger);
			drv_idc_set_fifo_trigger(pr_ctrl_set_fifo_trigger->rx_threshold);
			return_value = STATUS_OK;
			break;
		}
		case IDC_CMD_SET_PM_CONFIG:
		{
			IDC_CTRL_PM_CONFIG_T *pr_ctrl_pm_config;
			pr_ctrl_pm_config = &(data->r_idc_ctrl_pm_config);
			drv_idc_set_pm_config(pr_ctrl_pm_config->start, pr_ctrl_pm_config->priority, pr_ctrl_pm_config->priority_bit_en, pr_ctrl_pm_config->pattern, pr_ctrl_pm_config->pattern_bit_en);
			return_value = STATUS_OK;
			break;
		}
		case IDC_CMD_GET_PM_CONFIG:
		{
			IDC_CTRL_PM_CONFIG_T *pr_ctrl_pm_config;
			pr_ctrl_pm_config = &(data->r_idc_ctrl_pm_config);
			drv_idc_get_pm_config(pr_ctrl_pm_config->start, &(pr_ctrl_pm_config->priority),
				&(pr_ctrl_pm_config->priority_bit_en), &(pr_ctrl_pm_config->pattern), &(pr_ctrl_pm_config->pattern_bit_en));
			return_value = STATUS_OK;
			break;
		}
		case IDC_CMD_SCHEDULE_EVENT:
		{
			IDC_CTRL_SCHEDULE_EVENT_T *pr_ctrl_schedule_event;
			pr_ctrl_schedule_event = &(data->r_idc_ctrl_schedule_event);
			drv_idc_schedule_event(pr_ctrl_schedule_event->schedule_num, pr_ctrl_schedule_event->num_event, (IDC_EVENT_T *) &(pr_ctrl_schedule_event->schedule_event));
			return_value = STATUS_OK;
			break;
		}
		case IDC_CMD_SCHEDULE_START:
		{
			IDC_CTRL_SCHEDULE_START_T *pr_ctrl_schedule_start;
			pr_ctrl_schedule_start = &(data->r_idc_ctrl_schedule_start);
			drv_idc_schedule_start(pr_ctrl_schedule_start->schedule_num, pr_ctrl_schedule_start->base_time);
			return_value = STATUS_OK;
			break;
		}
		case IDC_CMD_STOP_EVENT:
		{
			IDC_CTRL_STOP_EVENT_T *pr_ctrl_stop_event;
			pr_ctrl_stop_event = &(data->r_idc_ctrl_stop_event);
			drv_idc_stop_event(pr_ctrl_stop_event->schedule_num, pr_ctrl_stop_event->bitmap);
			return_value = STATUS_OK;
			break;
		}
		case IDC_CMD_PURGE:
		{
			IDC_CTRL_PURGE_T *pr_ctrl_purge;
			pr_ctrl_purge = &(data->r_idc_ctrl_purge);
			drv_idc_purge(pr_ctrl_purge->dir);
			return_value = STATUS_OK;
			break;
		}
		case IDC_CMD_GET_SCHEDULE_STATUS:
		{	
			IDC_CTRL_GET_SCHEDULE_STATUS_T *pr_ctrl_get_schedule_status;
			pr_ctrl_get_schedule_status = &(data->r_idc_ctrl_get_schedule_status);
			drv_idc_get_schedule_status(pr_ctrl_get_schedule_status->schedule_status);
			return_value = STATUS_OK;
			break;
		}
		case IDC_CMD_CHECK_EVENT_SEND_OUT:
		{
			IDC_CTRL_CHECK_EVENT_SEND_OUT_T *pr_ctrl_check_event_send_out;
			pr_ctrl_check_event_send_out = &(data->r_idc_ctrl_check_event_send_out);
			pr_ctrl_check_event_send_out->send_out = drv_idc_check_event_send_out();
			return_value = STATUS_OK;
			break;
		}
		case IDC_CMD_SET_PIN_CONFIG:
		{
			IDC_CTRL_PIN_CONFIG_T *pr_ctrl_pin_config;
			pr_ctrl_pin_config = &(data->r_idc_ctrl_pin_config);
			return_value = drv_idc_set_pin_config(pr_ctrl_pin_config->pin_mode);
			break;
		}
		case IDC_CMD_GET_PIN_CONFIG:
		{
			IDC_CTRL_PIN_CONFIG_T *pr_ctrl_pin_config;
			pr_ctrl_pin_config = &(data->r_idc_ctrl_pin_config);
			return_value = drv_idc_get_pin_config(&(pr_ctrl_pin_config->pin_mode));
			break;
		}
		default:
			ASSERT(0);
			return_value = STATUS_INVALID_CMD;
			break;
	}

	return return_value;
}

/*************************************************************************
* FUNCTION
*  DclIDC_conn_txrx_count
*
* DESCRIPTION
*  This function is to start/end counting BT_80211_RX and BT_80211_TX
*
* PARAMETERS
*  is_start: [IN]       KAL_TRUE: Start counting
*                       KAL_FALSE: End counting
*
* RETURNS
*  Return the status of DclIDC_conn_txrx_count
*
* RETURN VALUES
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclIDC_conn_txrx_count(kal_bool is_start)
{
	drv_idc_conn_txrx_count(is_start);

	return STATUS_OK;
}

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
DCL_STATUS DclIDC_Close(DCL_HANDLE handle)
{
	// Check magic number
	if(DCL_IDC_IS_HANDLE_MAGIC(handle) == 0)
	{
		ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}

	drv_idc_close();

	return STATUS_OK;
}

#else // Else of #ifdef DCL_IDC_INTERFACE
DCL_STATUS DclIDC_Initialize(void)
{
	return STATUS_UNSUPPORTED;
}

DCL_HANDLE DclIDC_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclIDC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclIDC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclIDC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclIDC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclIDC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclIDC_Close(DCL_HANDLE handle)
{
	return STATUS_UNSUPPORTED;
}

#endif // End of #ifdef DCL_IDC_INTERFACE
