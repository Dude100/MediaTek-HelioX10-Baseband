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
 *   dcl_otg_drv.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  This file defines the DCL common definitions for USB OTG driver.
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
#ifndef __DCL_OTG_DRV_H_STRUCT__
#define __DCL_OTG_DRV_H_STRUCT__


#include "dcl.h"
//#include "dcl_usb_drv.h"


typedef enum
{
	OTG_PLUG_B,
	OTG_PLUG_A
}OTG_PLUG_TYPE;


/* interrupt handler type*/
typedef enum
{
	OTG_DRV_HDLR_HOST_UP,
	OTG_DRV_HDLR_HOST_DOWN,
	OTG_DRV_HDLR_DEVICE_UP,
	OTG_DRV_HDLR_DEVICE_DOWN,
	OTG_DRV_HDLR_A_VRISE_FAIL,
	OTG_DRV_HDLR_A_HNP_FAIL,
	OTG_DRV_HDLR_A_HNP_STOP,
	OTG_DRV_HDLR_A_NO_RESPONSE,
	OTG_DRV_HDLR_B_HNP_FAIL,
	OTG_DRV_HDLR_B_SRP_FAIL,
	OTG_DRV_HDLR_B_SRP_STOP,
	OTG_DRV_HDLR_B_SRP_EXCEPTION_STOP,
	OTG_DRV_HDLR_A_HOST_STOP
}OTG_DRV_HDLR_TYPE;


typedef enum
{
	OTG_STATUS_A_BUS_REQUEST = 0,
	OTG_STATUS_A_DETECT_B_CONN,
	OTG_STATUS_A_DETECT_B_SUSPEND,
	OTG_STATUS_A_DETECT_B_RESUME,
	OTG_STATUS_A_DETECT_B_DATA_PLS,
	OTG_STATUS_A_SUSPEND_REQUEST,
	OTG_STATUS_A_RESUME_REQUEST,
	OTG_STATUS_A_SET_B_HNP_ENABLE,
	OTG_STATUS_B_SESSION_VALID,
	OTG_STATUS_B_SUSPEND_REQUEST,
	OTG_STATUS_B_DETECT_A_CONN,
	OTG_STATUS_B_DETECT_A_SUSPEND,
	OTG_STATUS_B_DETECT_A_RESUME,
	OTG_STATUS_B_DETECT_A_RESET,
	OTG_STATUS_B_SRP_REQUEST,
	OTG_STATUS_B_HNP_ENABLE
}OTG_STATUS_TYPE;


typedef enum
{
	 OTG_STATE_START,
	 OTG_STATE_A_IDLE,
	 OTG_STATE_A_WAIT_VRISE,
	 OTG_STATE_A_WAIT_BCON,
	 OTG_STATE_A_HOST,
	 OTG_STATE_A_SUSPEND,
	 OTG_STATE_A_PERIPHERAL,
	 OTG_STATE_A_WAIT_VFALL,

	 OTG_STATE_B_IDLE,
	 OTG_STATE_B_SRP_INIT,
	 OTG_STATE_B_PERIPHERAL,
	 OTG_STATE_B_WAIT_ACON,
	 OTG_STATE_B_HOST
}OTG_STATE;

/* interrupt handler function type */
typedef void (*otg_intr_handler_ptr)(void);

////////////DCL part ///////////////////

typedef enum
{
	DCL_OTG_PLUG_B,
	DCL_OTG_PLUG_A
}DCL_OTG_PLUG_TYPE;


/* interrupt handler type*/
typedef enum
{
	DCL_OTG_DRV_HDLR_HOST_UP,
	DCL_OTG_DRV_HDLR_HOST_DOWN,
	DCL_OTG_DRV_HDLR_DEVICE_UP,
	DCL_OTG_DRV_HDLR_DEVICE_DOWN,
	DCL_OTG_DRV_HDLR_A_VRISE_FAIL,
	DCL_OTG_DRV_HDLR_A_HNP_FAIL,
	DCL_OTG_DRV_HDLR_A_HNP_STOP,
	DCL_OTG_DRV_HDLR_A_NO_RESPONSE,
	DCL_OTG_DRV_HDLR_B_HNP_FAIL,	
	DCL_OTG_DRV_HDLR_B_SRP_FAIL,
	DCL_OTG_DRV_HDLR_B_SRP_STOP,
	DCL_OTG_DRV_HDLR_B_SRP_EXCEPTION_STOP,
	DCL_OTG_DRV_HDLR_A_HOST_STOP
}DCL_OTG_DRV_HDLR_TYPE;

typedef enum
{
	DCL_OTG_STATUS_A_BUS_REQUEST = 0,
	DCL_OTG_STATUS_A_DETECT_B_CONN,
	DCL_OTG_STATUS_A_DETECT_B_SUSPEND,
	DCL_OTG_STATUS_A_DETECT_B_RESUME,
	DCL_OTG_STATUS_A_DETECT_B_DATA_PLS,
	DCL_OTG_STATUS_A_SUSPEND_REQUEST,
	DCL_OTG_STATUS_A_RESUME_REQUEST,
	DCL_OTG_STATUS_A_SET_B_HNP_ENABLE,
	DCL_OTG_STATUS_B_SESSION_VALID,
	DCL_OTG_STATUS_B_SUSPEND_REQUEST,
	DCL_OTG_STATUS_B_DETECT_A_CONN,
	DCL_OTG_STATUS_B_DETECT_A_SUSPEND,
	DCL_OTG_STATUS_B_DETECT_A_RESUME,
	DCL_OTG_STATUS_B_DETECT_A_RESET,
	DCL_OTG_STATUS_B_SRP_REQUEST,
	DCL_OTG_STATUS_B_HNP_ENABLE
}DCL_OTG_STATUS_TYPE;

typedef enum
{
	DCL_OTG_STATE_START,
	DCL_OTG_STATE_A_IDLE,
	DCL_OTG_STATE_A_WAIT_VRISE,
	DCL_OTG_STATE_A_WAIT_BCON,
	DCL_OTG_STATE_A_HOST,
	DCL_OTG_STATE_A_SUSPEND,
	DCL_OTG_STATE_A_PERIPHERAL,
	DCL_OTG_STATE_A_WAIT_VFALL,

	DCL_OTG_STATE_B_IDLE,
	DCL_OTG_STATE_B_SRP_INIT,
	DCL_OTG_STATE_B_PERIPHERAL,
	DCL_OTG_STATE_B_WAIT_ACON,
	DCL_OTG_STATE_B_HOST
}DCL_OTG_STATE;


typedef void (*DCL_OTG_FUNC_TYPE_0)(void);
typedef void (*DCL_OTG_DRV_REGISTER_CALLBACK)(DCL_OTG_DRV_HDLR_TYPE type, DCL_OTG_FUNC_TYPE_0 hdlr);
typedef DCL_OTG_PLUG_TYPE (*DCL_OTG_DRV_PLUG_TYPE)(void);
typedef void (*DCL_OTG_SET_OTG_STATUS)(DCL_OTG_STATUS_TYPE type, DCL_BOOL set);
typedef DCL_OTG_STATE (*DCL_OTG_GET_OTG_STATE)(void);



/*******************************************************************************
 * DCL_OPTIONS for OTG_DRV
 *******************************************************************************/
#define OTG_DRV_OPTIONS


 /*******************************************************************************
 * DCL_CONFIGURE_T for OTG_DRV
 *******************************************************************************/
#define OTG_DRV_CONFIGS


/*******************************************************************************
 * DCL_EVENT for OTG_DRV
 *******************************************************************************/
#define OTG_DRV_EVENTS


/*******************************************************************************
 * DCL_CTRL_CMD for OTG_DRV
 *******************************************************************************/
#define OTG_DRV_CMDS \
	OTG_DRV_CMD_INIT_DRV_INFO = 0, \
	OTG_DRV_CMD_RELEASE_DRV_INFO, \
	OTG_DRV_CMD_REGISTER_DRV_INFO, \
	OTG_DRV_CMD_DRV_CREATE_ISR, \
	OTG_DRV_CMD_DRV_ACTIVATE_ISR, \
	OTG_DRV_CMD_DMA_DRV_CREATE_ISR, \
	OTG_DRV_CMD_DMA_DRV_ACTIVATE_ISR, \
	OTG_DRV_CMD_INIT_DRV, \
	OTG_DRV_CMD_GET_PLUG_TYPE, \
	OTG_DRV_CMD_A_SUSPEND_REQ, \
	OTG_DRV_CMD_A_RESUME_REQ, \
	OTG_DRV_CMD_A_STOP_HOST, \
	OTG_DRV_CMD_A_START_HNP, \
	OTG_DRV_CMD_B_EN_DIS_HNP, \
	OTG_DRV_CMD_B_START_SRP, \
	OTG_DRV_CMD_B_STOP_HOST, \
	OTG_DRV_CMD_B_SET_SESSION_VALID, \
	OTG_DRV_CMD_GET_STATE, \
	OTG_DRV_CMD_ENABLE_DEVICE, \
	OTG_DRV_CMD_INCR_DISCONNECT_COUNT,  \
	OTG_DRV_CMD_PROCESS_EXCEPTIONS, \
	OTG_DRV_CMD_INIT_A_PLUG_DETECT, \
	OTG_DRV_CMD_HOST_SET_VBUS_HIGH, \
	OTG_DRV_CMD_IS_HOST_TURN_ON_VBUS, \
	OTG_DRV_CMD_IS_A_CABLE_IN, \
	OTG_DRV_CMD_SRP_INIT, \
	OTG_DRV_CMD_SET_PLUG_TYPE, \




/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/

typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_OTG_DRV_HDLR_TYPE type;
	DCL_OTG_FUNC_TYPE_0 hdlr;
}OTG_DRV_CTRL_REGISTER_DRV_INFO_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_OTG_PLUG_TYPE  type;
}OTG_DRV_CTRL_GET_PLUG_TYPE_T;

/*
typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_OTG_STATUS_TYPE type;
	DCL_BOOL fgset;
}OTG_DRV_CTRL_SET_STATUS_T;
*/

typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_OTG_STATE state;
}OTG_DRV_CTRL_GET_STATE_T;


typedef struct
{
	DCL_BOOL	return_value;	
}OTG_DRV_CTRL_GET_Reg_T;



#define OTG_DRV_CTRLS \
  OTG_DRV_CTRL_REGISTER_DRV_INFO_T		rOTG_Drv_Info; \
  OTG_DRV_CTRL_GET_PLUG_TYPE_T			rOTG_Plug_Type; \
  OTG_DRV_CTRL_GET_STATE_T				rOTG_Get_State; \
  OTG_DRV_CTRL_GET_Reg_T			  rOTG_Get_State2; \



#endif // #ifndef __DCL_OTG_DRV_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT



#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_OTG_DRV_H_PROTOTYPE__
#define __DCL_OTG_DRV_H_PROTOTYPE__

/*************************************************************************
* FUNCTION
*  DclOTG_DRV_Initialize
*
* DESCRIPTION
*  This function is to initialize OTG_DRV module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclOTG_DRV_Initialize(void);
/*************************************************************************
* FUNCTION
*  DclOTG_DRV_Open
*
* DESCRIPTION
*  This function is to open the SW ADC module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_USB
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed
*  Other value: A valid handle
*
*************************************************************************/
extern DCL_HANDLE DclOTG_DRV_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION
*  DclOTG_DRV_ReadData
*
* DESCRIPTION
*  This function is not supported for the ADC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclOTG_DRV_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclOTG_DRV_WriteData
*
* DESCRIPTION
*  This function is not supported for the ADC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclOTG_DRV_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclOTG_DRV_Configure
*
* DESCRIPTION
*  This function is not supported for the ADC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclOTG_DRV_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION
*  DclOTG_DRV_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the ADC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclOTG_DRV_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
/*************************************************************************
* FUNCTION
*  DclOTG_DRV_Control
*
* DESCRIPTION
*  This function is to send command to control the SW ADC module.
*
* PARAMETERS
*  handle: A valid handle return by DclSADC_Open()
*  cmd: A control command for ADC module
*          1. ADC_CMD_CREATE_OBJECT: to create measurement object
*          2. ADC_CMD_MODIFY_PARAM: to change measurement parameters
*          3. ADC_CMD_START_MEASURE: to start measurement item
*          4. ADC_CMD_STOP_MEASURE: to stop measurement item
*  data: The data of the control command
*          1. ADC_CMD_CREATE_OBJECT: pointer to a ADC_CTRL_CREATE_OBJECT_T structure
*          2. ADC_CMD_MODIFY_PARAM: pointer to a ADC_CTRL_MODIFY_PARAM_T structure
*          3. ADC_CMD_START_MEASURE: a null pointer
*          4. ADC_CMD_STOP_MEASURE: a null pointer
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
extern DCL_STATUS DclOTG_DRV_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION
*  DclOTG_DRV_Close
*
* DESCRIPTION
*  This function is to close the SW ADC module.
*
* PARAMETERS
*  handle: the returned handle value of DclSADC_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclOTG_DRV_Close(DCL_HANDLE handle);

#ifdef __OTG_SRP_HNP_APP_FIXED__
extern void OTG_Set_Vbus_ON(void);
#endif


#endif // #ifndef __DCL_OTG_DRV_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE

