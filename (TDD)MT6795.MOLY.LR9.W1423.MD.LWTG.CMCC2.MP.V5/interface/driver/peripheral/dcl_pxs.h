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
 *   dcl_pxs.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for proximity sensor.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_PXS_H_STRUCT__
#define __DCL_PXS_H_STRUCT__

/*******************************************************************************
 * DCL_OPTIONS for PXS
 *******************************************************************************/
#define PXS_OPTIONS

/*******************************************************************************
 * DCL_CONFIGURE_T for PXS
 *******************************************************************************/
typedef void (*PFN_DCL_PXS_NOTIFY_CALLBACK)(DCL_BOOL fgObjectDetected);

typedef enum
{
	PXS_COMPARE_WINDOW,  // Comparing window of PXS thresold algorithm
	PXS_HILO_THRESHOLD,  // HIGH/LOW thresold methodology
	PXS_ADV_ALGO_MAX
} PXS_ADV_ALGO_ENUM;

typedef struct
{
   DCL_BOOL fgNotify;
   PFN_DCL_PXS_NOTIFY_CALLBACK NotifyCallback;
} PXS_CONFIG_T, PXS_CTRL_CONFIG_T;

#define PXS_CONFIGS \
   PXS_CONFIG_T rPXSConfig;

/*******************************************************************************
 * DCL_EVENT for PXS
 *******************************************************************************/
#define PXS_EVENTS

/*******************************************************************************
 * DCL_CTRL_CMD for PXS
 *******************************************************************************/
#define PXS_CMDS \
   PXS_CMD_ENABLE, \
   PXS_CMD_GET_RAW_DATA, \
   PXS_CMD_EM_READ, \
   PXS_CMD_EM_WRITE, \
   PXS_CMD_GET_ADV_ALGO_WINDOWING, \
   PXS_CMD_GET_ADV_ALGO_THRESHOLD, \
   PXS_CMD_MODIFY_CONFIG, \
   PXS_CMD_GET_SENSITIVITY_LEVEL_NUM, \
   PXS_CMD_SET_SENSITIVITY_LEVEL, \
   PXS_CMD_GET_DETECT_STATUS, \
   PXS_CMD_SET_DEBOUNCE, \


/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/


typedef enum
{
	PXS_HW_CMD_POWER_ENABLE,
	PXS_HW_CMD_GET_SENSITIVITY_LEVEL_NUM,
	PXS_HW_CMD_GET_SENSITIVITY_TABLE,
}PXS_HW_CMD_ENUM;

/* For PXS_CMD_ENABLE command. */
typedef struct
{
   DCL_BOOL fgEnable;
}PXS_CTRL_ENABLE_T;

/* For PXS_CMD_GET_RAW_DATA command. */
typedef struct
{
   DCL_UINT16 u2Data;
}PXS_CTRL_RAW_DATA_T;

/* For PXS_CMD_EM_ADV_ALGO_WINDOWING command. */
//typedef struct
//{
//   DCL_UINT16 u2Count;
//}PXS_CTRL_EM_WINDOWING_T;

/* For PXS_CMD_EM_ADV_ALGO_THRESHOLD command. */
//typedef struct
//{
//   DCL_UINT16 u2HiThreshold;
//   DCL_UINT16 u2LoThreshold;
//}PXS_CTRL_EM_THRESHOLD_T;

/* For PXS_CMD_EM_READ, PXS_CMD_EM_WRITE command. */
typedef struct
{
   DCL_UINT32 u4P1;
   DCL_UINT32 u4P2;
   DCL_UINT32 u4P3;
   DCL_UINT32 u4P4;
   DCL_UINT32 u4P5;
   DCL_UINT32 u4P6;
   DCL_UINT32 u4P7;
   DCL_UINT32 u4P8;
   DCL_UINT32 u4PollingPeriod;   // EM polling period, unit by ms
}PXS_CTRL_EM_PARAM_T;

/* For PXS_CMD_GET_ADV_ALGO_WINDOWING command. */
typedef struct
{
   DCL_UINT16 u2Count;
}PXS_CTRL_GET_ADV_ALGO_WINDOWING_T;

/* For PXS_CMD_GET_ADV_ALGO_THRESHOLD command. */
typedef struct
{
   DCL_UINT16 u2HiThreshold;
   DCL_UINT16 u2LoThreshold;
}PXS_CTRL_GET_ADV_ALGO_THRESHOLD_T;

/* For PXS_CMD_GET_SENSITIVITY_LEVEL_NUM command. */
typedef struct
{
   DCL_UINT16 u2LevelNum;
}PXS_CTRL_GET_SENSITIVITY_LEVEL_NUM_T;

/* For PXS_CMD_SET_SENSITIVITY_LEVEL command. */
typedef struct
{
   DCL_UINT16 u2Level;
}PXS_CTRL_SET_SENSITIVITY_LEVEL_T;

/* For PXS_CMD_GET_DETECT_STATUS command. */
typedef struct
{
   DCL_BOOL fgDetected;
}PXS_CTRL_GET_DETECT_STATUS_T;


/* For PXS_CMD_SET_DEBOUNCE command. */
typedef struct
{
	DCL_UINT32 u4TopAreaDebounce; //ms
	DCL_UINT32 u4LargerAreaDebounce; //ms
}PXS_CTRL_SET_DEBOUNCE_T;

#define PXS_CTRLS \
   PXS_CTRL_ENABLE_T   rPXSEnable; \
   PXS_CTRL_RAW_DATA_T rPXSRawData; \
   PXS_CTRL_EM_PARAM_T rPXSEMParam; \
   PXS_CTRL_GET_ADV_ALGO_WINDOWING_T rPXSAdvAlgoWindowing; \
   PXS_CTRL_GET_ADV_ALGO_THRESHOLD_T rPXSAdvAlgoThreshold; \
   PXS_CTRL_CONFIG_T rPXSConfig; \
   PXS_CTRL_GET_SENSITIVITY_LEVEL_NUM_T rPXSSensitivityLevelNum; \
   PXS_CTRL_SET_SENSITIVITY_LEVEL_T rPXSSensitivityLevel; \
   PXS_CTRL_GET_DETECT_STATUS_T rPXSDetectStatus; \
   PXS_CTRL_SET_DEBOUNCE_T rPXSSetDebounce;



#endif // #ifndef __DCL_PXS_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT


#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_PXS_H_PROTOTYPE__
#define __DCL_PXS_H_PROTOTYPE__

/*************************************************************************
* FUNCTION
*  DclPXS_Initialize
*
* DESCRIPTION
*  This function is to initialize PXS module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclPXS_Initialize(void);
/*************************************************************************
* FUNCTION
*  DclPXS_Open
*
* DESCRIPTION
*  This function is to open the PXS module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_PXS
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed
*  Other value: A valid handle
*
*************************************************************************/
extern DCL_HANDLE DclPXS_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION
*  DclPXS_ReadData
*
* DESCRIPTION
*  This function is not supported for the PXS module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPXS_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclPXS_WriteData
*
* DESCRIPTION
*  This function is not supported for the PXS module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPXS_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclPXS_Configure
*
* DESCRIPTION
*  This function is to configure the PXS module.
*
* PARAMETERS
*  handle: the returned handle value of DclPXS_Open
*  configure: a structure which include the PXS configuration.
*
* RETURNS
*  STATUS_OK: Successfully configure PXS module.
*  STATUS_INVALID_HANDLE: It's a invalid handle.
*  STATUS_NOT_OPENED: The module has not been opened.
*  STATUS_INVALID_CONFIGURATION: The configuration is invalid.
*
*************************************************************************/
extern DCL_STATUS DclPXS_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION
*  DclPXS_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the PXS module.
*
* PARAMETERS
*  handle: the returned handle value of DclPXS_Open
*  event: Supported events:
*  callback: the callback function for registered events
*
* RETURNS
*  STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPXS_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
/*************************************************************************
* FUNCTION
*  DclPXS_Control
*
* DESCRIPTION
*  This function is to send command to control the PXS module.
*
* PARAMETERS
*  handle: The handle value returned from DclPXS_Open
*  cmd: A control command for PXS module
*          1. PXS_CMD_ENABLE: to enable/disable PXS function
*          2. PXS_CMD_GET_RAW_DATA: to get PXS sampled raw data
*          3. PXS_CMD_EM_READ: to read EM parameters
*          4. PXS_CMD_EM_WRITE: to write EM parameters
*          5. PXS_CMD_GET_DETECT_STATUS: to get PXS detected status
*  data: The data of the control command
*          1. PXS_CMD_ENABLE: pointer to a PXS_CTRL_ENABLE_T structure
*          2. PXS_CMD_GET_RAW_DATA: pointer to a PXS_CTRL_RAW_DATA_T structure
*          3. PXS_CMD_EM_READ: pointer to a PXS_CTRL_EM_PARAM_T structure
*          4. PXS_CMD_EM_WRITE: pointer to a PXS_CTRL_EM_PARAM_T structure
*          5. PXS_CMD_GET_DETECT_STATUS: pointer to a PXS_CTRL_GET_DETECT_STATUS_T structure
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*  STATUS_UNSUPPORTED: The command is NOT supported
*
*************************************************************************/
extern DCL_STATUS DclPXS_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION
*  DclPXS_Close
*
* DESCRIPTION
*  This function is to close the PXS module.
*
* PARAMETERS
*  handle: the returned handle value of DclPXS_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclPXS_Close(DCL_HANDLE handle);



// Low level PXS driver (DclHPXS_XXX interfaces)
extern DCL_STATUS DclHPXS_Initialize(void);
extern DCL_HANDLE DclHPXS_Open(DCL_DEV dev, DCL_FLAGS flags);
extern DCL_STATUS DclHPXS_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
extern DCL_STATUS DclHPXS_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
extern DCL_STATUS DclHPXS_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
extern DCL_STATUS DclHPXS_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
extern DCL_STATUS DclHPXS_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
extern DCL_STATUS DclHPXS_Close(DCL_HANDLE handle);





#endif // #ifndef __DCL_PXS_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE


