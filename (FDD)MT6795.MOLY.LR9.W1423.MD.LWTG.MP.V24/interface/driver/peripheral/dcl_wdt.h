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
 *   dcl_wdt.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for WDT.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_WDT_H_STRUCT__
#define __DCL_WDT_H_STRUCT__


#define DCL_WDT_RSTINTERVAL_VALUE    0xffa

/*******************************************************************************
 * DCL_OPTIONS for WDT
 *******************************************************************************/
#define WDT_OPTIONS

 /*******************************************************************************
 * DCL_CONFIGURE_T for WDT
 *******************************************************************************/

#define WDT_CONFIGS

/*******************************************************************************
 * DCL_EVENT for WDT
 *******************************************************************************/
#ifdef __BUILD_DOM__
/*The WDT EVENT is part of DCL_EVENT_T Enum of dcl.h*/
/*WDT_EVENTS_T Define the event type that wdt support to register a callback function*/
typedef enum
{
	EVENT_WDT_TIMEOUT =         0x00000001
}DCL_EVENT_T;
#else
#define WDT_EVENTS \
   EVENT_WDT_TIMEOUT =         0x00000001,
#endif
/*******************************************************************************
 * DCL_CTRL_CMD for WDT
 *******************************************************************************/
#ifdef __BUILD_DOM__
/*The WDT Command values is part of DCL_CTRL_CMD_T Enum of dcl.h*/
/*DCL_CTRL_DATA_T Define the Control data structure for each module's command*/
typedef enum
{
	 WDT_CMD_ENABLE ,  /*to enable/disable WDT*/
   WDT_CMD_SET_EXT_POL, /*to set ploarity of external pin when WDT expired */
   WDT_CMD_SET_EXT_RESET, /*to generate an external watchdog reset signal when WDT expired*/
   WDT_CMD_SET_VALUE, /*to set WDT count value*/
   WDT_CMD_RESTART, /*to restart counter*/
   WDT_CMD_DRV_RESET, /*to reset device*/
   WDT_CMD_ABN_RESET, /*to reset device with abnormal flag set to indicate it is a abnormal reset*/
   WDT_CMD_IRQ, /*to generate interrupt instead of resetting device*/
   WDT_CMD_ENABLE_DEBUG,
}DCL_CTRL_CMD_T;
#else
#define WDT_CMDS \
   WDT_CMD_ENABLE , \
   WDT_CMD_SET_EXT_POL, \
   WDT_CMD_SET_EXT_RESET, \
   WDT_CMD_SET_VALUE, \
   WDT_CMD_RESTART, \
   WDT_CMD_DRV_RESET, \
   WDT_CMD_ABN_RESET, \
   WDT_CMD_IRQ, \
   WDT_CMD_GET_RSTINTERVAL, \
   WDT_CMD_ENABLE_DEBUG,
#endif
/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/
 typedef struct
 {
 	DCL_UINT16 rstInterval;	
 }WDT_CTRL_GET_RSTINTERVAL_T;
 
/* For WDT_CMD_ENABLE command. */
typedef struct
{
   DCL_BOOL fgEnable;		// TRUE: Enable WDT, FALSE: Disable WDT
} WDT_CTRL_ENABLE_T;
/* For WDT_CMD_SET_EXT_POL command. */
typedef struct
{
   DCL_BOOL fgIOHigh;		// TRUE: IO high, FALSE: IO low
} WDT_CTRL_SET_EXT_POL_T;
/* For WDT_CMD_SET_EXT_RESET command. */
typedef struct
{
   DCL_BOOL fgEnable;		// TRUE: Generate reset signal, FALSE: Do NOT generate reset signal
} WDT_CTRL_SET_EXT_RESET_T;
/* For WDT_CMD_SET_VALUE command. */
typedef struct
{
   DCL_UINT16 u2Value;		// Set WDT count down value, the unit is 15.6ms
} WDT_CTRL_SET_VALUE_T;
/* For WDT_CMD_RESTART command. */
// WDT_CMD_RESTART does NOT need parameters
/* For WDT_CMD_DRV_RESET command. */
// WDT_CMD_DRV_RESET does NOT need parameters
/* For WDT_CMD_ABN_RESET command. */
// WDT_CMD_ABN_RESET does NOT need parameters
/* For WDT_CMD_IRQ command. */
typedef struct
{
   DCL_BOOL fgEnable;		// TRUE: Enable interrupt instread of generating reset, FALSE: Do NOT enable interrupt
} WDT_CTRL_IRQ_T;
/*For WDT_CMD_ENABLE_DEBUG command*/
typedef struct
{
   DCL_BOOL fgEnable;	//enable or disable debug 
}WDT_CTRL_DEBUG_T;

#ifdef __BUILD_DOM__
/*The GPIO command prarmeter data structure for each command. that's enum in in DCL_CTRL_DATA_T*/
typedef struct
{
   WDT_CTRL_ENABLE_T rWDTEnable;  					 /*data structure for WDT_CMD_ENABLE control command */
   WDT_CTRL_SET_EXT_POL_T rWDTSetExtPol; 		 /*data structure for WDT_CMD_SET_EXT_POL control command */
   WDT_CTRL_SET_EXT_RESET_T rWDTSetExtReset; /*data structure for WDT_CMD_SET_EXT_RESET control command */
   WDT_CTRL_SET_VALUE_T rWDTSetValue; 			 /*data structure for WDT_CMD_SET_VALUE control command */
   WDT_CTRL_IRQ_T rWDTIRQ;									 /*data structure for WDT_CMD_IRQ control command */
   WDT_CTRL_DEBUG_T rWDTDebug;							 /*data structure for WDT_CMD_ENABLE_DEBUG control command */
}DCL_CTRL_DATA_T;
#else
#define WDT_CTRLS \
   WDT_CTRL_ENABLE_T rWDTEnable; \
   WDT_CTRL_SET_EXT_POL_T rWDTSetExtPol; \
   WDT_CTRL_SET_EXT_RESET_T rWDTSetExtReset; \
   WDT_CTRL_SET_VALUE_T rWDTSetValue; \
   WDT_CTRL_IRQ_T rWDTIRQ;	\
   WDT_CTRL_DEBUG_T rWDTDebug; \
   WDT_CTRL_GET_RSTINTERVAL_T rRstValue;
#endif

#endif // #ifndef __DCL_I2C_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT


#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_WDT_H_PROTOTYPE__
#define __DCL_WDT_H_PROTOTYPE__

/*************************************************************************
* FUNCTION
*  DclWDT_Initialize
*
* DESCRIPTION
*  This function is to initialize WDT module
*
* PARAMETERS
*  None
*
* RETURN VALUES
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclWDT_Initialize(void);
/*************************************************************************
* FUNCTION
*  DclWDT_Open
*
* DESCRIPTION
*  This function is to open the WDT module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_WDT
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURN VALUES
*  DCL_HANDLE_INVALID: Open failed.
*  other value: a valid handle
*
*************************************************************************/
extern DCL_HANDLE DclWDT_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION
*  DclWDT_ReadData
*
* DESCRIPTION
*  This function is not supported for the WDT module now.
*
* PARAMETERS
*	N/A
*
* RETURN VALUES
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclWDT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclWDT_WriteData
*
* DESCRIPTION
*  This function is not supported for the WDT module now.
*
* PARAMETERS
*	N/A
*
* RETURN VALUES
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclWDT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclWDT_Configure
*
* DESCRIPTION
*  This function is not supported for the WDT module now.
*
* PARAMETERS
*	N/A
*
* RETURN VALUES
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclWDT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION
*  DclWDT_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the WDT module.
*
* PARAMETERS
*  handle: the returned handle value of DclWDT_Open
*  event: Supported events:
*         EVENT_WDT_TIMEOUT: Watch dog time out interrupt
*  callback: the callback function for registered events
*
* RETURN VALUES
*  STATUS_OK: Successfully register the callback function.
*  STATUS_INVALID_DCL_HANDLE: It's a invalid handle.
*  STATUS_NOT_OPENED: The module has not been opened.
*  STATUS_INVALID_EVENT: The event parameter is invalid.
*
*************************************************************************/
extern DCL_STATUS DclWDT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
/*************************************************************************
* FUNCTION
*  DclWDT_Control
*
* DESCRIPTION
*  This function is to send command to control the WDT module.
*
* PARAMETERS
*  handle: The handle value returned from DclWDT_Open
*  cmd: a control command for WDT module
*          1. WDT_CMD_ENABLE: to enable/disable WDT
*          2. WDT_CMD_SET_EXT_POL: to set ploarity of external pin when WDT expired
*          3. WDT_CMD_SET_EXT_RESET: to generate an external watchdog reset signal when WDT expired
*          4. WDT_CMD_SET_VALUE: to set WDT count value
*          5  WDT_CMD_RESTART: to restart counter
*          6. WDT_CMD_DRV_RESET: to reset device
*          7. WDT_CMD_ABN_RESET: to reset device with abnormal flag set to indicate it is a abnormal reset
*          8. WDT_CMD_IRQ: to generate interrupt instead of reseting device
*  data: The data of the control command
*          1. WDT_CMD_ENABLE: pointer to a WDT_CTRL_ENABLE_T structure
*          2. WDT_CMD_SET_EXT_POL: pointer to a WDT_CTRL_SET_EXT_POL_T structure
*          3. WDT_CMD_SET_EXT_RESET: pointer to a WDT_CTRL_SET_EXT_RESET_T structure
*          4. WDT_CMD_SET_VALUE: pointer to a WDT_CTRL_SET_VALUE_T structure
*          5  WDT_CMD_RESTART: A null pointer
*          6. WDT_CMD_DRV_RESET: A null pointer
*          7. WDT_CMD_ABN_RESET: A null pointer
*          8. WDT_CMD_IRQ: pointer to a WDT_CTRL_IRQ_T structure
*
* RETURN VALUES
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
extern DCL_STATUS DclWDT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION
*  DclWDT_Close
*
* DESCRIPTION
*  This function is to close the WDT module.
*
* PARAMETERS
*  handle: the returned handle value of DclWDT_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclWDT_Close(DCL_HANDLE handle);


#endif // #ifndef __DCL_WDT_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE






