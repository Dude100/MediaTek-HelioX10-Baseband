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
 *   dcl_adc.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for ADC.
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
#ifndef __DCL_ADC_H_STRUCT__
#define __DCL_ADC_H_STRUCT__

#define DCL_ADC_ERR_CHANNEL_NO  50
/*******************************************************************************
 * DCL_OPTIONS for ADC
 *******************************************************************************/
#define ADC_OPTIONS

 /*******************************************************************************
 * DCL_CONFIGURE_T for ADC
 *******************************************************************************/

#define ADC_CONFIGS

/*******************************************************************************
 * DCL_EVENT for ADC
 *******************************************************************************/
#define ADC_EVENTS

/*******************************************************************************
 * DCL_CTRL_CMD for ADC
 *******************************************************************************/
#define ADC_CMDS \
   ADC_CMD_CREATE_OBJECT, \
   ADC_CMD_MODIFY_PARAM, \
   ADC_CMD_START_MEASURE, \
   ADC_CMD_STOP_MEASURE, \
   ADC_CMD_SET_TIMER_PAGE_ALIGN, \
   ADC_CMD_REGISTER_MEASURE_CB, \
   ADC_CMD_REGISTER_COMPLETE_CB, \
   ADC_CMD_GET_CHANNEL, \
   ADC_CMD_SCHE_ID_GET_HANDLE, \
   ADC_CMD_TRANSFORM_INTO_VOLT, \
   ADC_CMD_TRANSFORM_INTO_TEMP, \
   ADC_CMD_TRANSFORM_INTO_CURR, \
   ADC_CMD_GET_SCHEDULER_PARAMETER, \
   ADC_CMD_SET_CALIBRATION_DATA, \
   ADC_CMD_READ_CALIBRATION_DATA, \
   ADC_CMD_READ_CALIBRATION_INFORM_IN_USBBOOT,	\
   ADC_CMD_SET_MULTI_CHANNEL_READ,   

#define HADC_CMDS \
   ADC_CMD_IMM_MEASURE, \
   ADC_CMD_SYNC_MEASURE, \
   ADC_CMD_TDMA_SYNC_SETUP, \
   ADC_CMD_POWER, \
   ADC_CMD_GET_DATA_2_META, \
   ADC_CMD_GET_DATA, \
   ADC_CMD_GET_META_DATA, \
   ADC_CMD_GET_MAX_PHYSICAL_CH, \
   ADC_CMD_GET_IMM_DATA_ON_BOOTING, \
   ADC_CMD_GET_TEMP, \
   ADC_CMD_GET_PHYSICAL_CHANNEL,

/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/
/* For ADC_CMD_CREATE_OBJECT command. */
typedef struct
{
   DCL_UINT32 u4Period;				// Measurement period (Uint is in Tick)
   DCL_UINT32 u4Sapid;
   DCL_UINT8 u1OwnerId;				// Indicate the module to for ADC driver to notify the result
   DCL_UINT8 u1AdcChannel;			// To be measured physical ADC channel
   DCL_UINT8 u1EvaluateCount;		// Measurement count
   DCL_BOOL fgSendPrimitive;		// Whether to send message to owner module or NOT
} ADC_CTRL_CREATE_OBJECT_T;

/* For ADC_CMD_MODIFY_PARAM command. */
typedef struct
{
   DCL_UINT32 u4Period;				// Measurement period (Uint is in Tick)
   DCL_UINT8 u1EvaluateCount;		// Measurement count
} ADC_CTRL_MODIFY_PARAM_T;
/* For ADC_CMD_START_MEASURE command. */
// ADC_CMD_START_MEASURE does NOT need parameters
/* For ADC_CMD_STOP_MEASURE command. */
// ADC_CMD_STOP_MEASURE does NOT need parameters
/* For ADC_CMD_IMM_MEASURE command. */
typedef struct
{
   DCL_UINT16 u2Channel;				// The channel to be measured
   DCL_UINT16 u2ADCValue;			// Measured ADC value
} ADC_CTRL_IMM_MEASURE_T;
/* For ADC_CMD_SYNC_MEASURE command. */
typedef struct
{
   DCL_UINT16 u2Channel;				// The channel to be measured
   DCL_UINT16 u2ADCValue;			// Measured ADC value
} ADC_CTRL_SYNC_MEASURE_T;
/* For ADC_CMD_TDMA_SYNC_SETUP command. */
typedef struct
{
   DCL_UINT16 u2Event0;				// Event 0
   DCL_UINT16 u2Event1;				// Event 1
} ADC_CTRL_TDMA_SYNC_SETUP_T;
/* For ADC_CMD_POWER command. */
typedef struct
{
   DCL_BOOL fgEnable;		// TRUE: Power on ADC module, FALSE: Power off ADC module
} ADC_CTRL_POWER_T;

/* For ADC_CMD_GET_DATA_2_META command. */
typedef struct
{
   DCL_UINT8 u1Channel;  //measure physical channel
   DCL_UINT16 u2MeaCount; //the counts of measurement
   DCL_UINT32 u4ADCData;  //return ADC value
} ADC_CTRL_GET_DATA_2_META_T;

/* For ADC_CMD_GET_DATA command. */
typedef struct
{
   DCL_UINT8 u1Channel;  //measure physical channel
   DCL_UINT32 u4ADCData;  //return ADC value
} ADC_CTRL_GET_DATA_T;

/* For ADC_CMD_GET_META_DATA command. */
typedef struct
{
   DCL_UINT8 u1Channel;  //measure physical channel
   DCL_UINT16 u2MeaCount; //the counts of measurement
   DCL_UINT32 u4ADCData;  //return ADC value
} ADC_CTRL_GET_META_DATA_T;

/* For ADC_CMD_GET_IMM_DATA_ON_BOOTING command. */
typedef struct
{
   DCL_UINT32 u4Channel; // Measure physical channel
   DCL_UINT32 u4MeaCount; // The counts of measurement
   DCL_UINT16 *u2ADCData; // Store ADC Value
} ADC_CTRL_GET_IMM_DATA_ON_BOOTING_T;

/* For ADC_CMD_GET_TEMP command. */
typedef struct
{
    DCL_UINT16 u2Channel;
    DCL_INT16 i2Temp;   /* Signed integer for temperature show */
} ADC_CTRL_GET_TEMP_T;

//ADC_CMD_SET_TIMER_PAGE_ALIGN
typedef struct
{
   DCL_BOOL fgPageAlign;  // TRUE: set stack timer page alignment
} ADC_CTRL_TIMER_ALIGN_T;

//ADC_CMD_GET_CHANNEL
typedef enum {
   DCL_VBAT_ADC_CHANNEL = 0,
   DCL_VISENSE_ADC_CHANNEL,
   DCL_VBATTMP_ADC_CHANNEL,
   DCL_BATTYPE_ADC_CHANNEL,
   DCL_VCHARGER_ADC_CHANNEL,
   DCL_PCBTMP_ADC_CHANNEL,
   DCL_AUX_ADC_CHANNEL,
   DCL_CHR_USB_ADC_CHANNEL,
   DCL_OTG_VBUS_ADC_CHANNEL,
   DCL_RFTMP_ADC_CHANNEL,
   DCL_MDTMP_ADC_CHANNEL,
   DCL_PMICTMP_ADC_CHANNEL,
   DCL_MAX_ADC_CHANNEL
} DCL_ADC_CHANNEL_TYPE_ENUM;

typedef struct
{
   DCL_UINT8    u1AdcPhyCh;
   DCL_UINT16   u2AdcName;
} ADC_CTRL_GET_PHYSICAL_CHANNEL_T;

//ADC_CMD_TRANSFORM_INTO_VOLT
typedef struct
{
   DCL_DOUBLE   d8AdcValue;
   DCL_UINT32   u4Volt;
   DCL_UINT8    u1AdcPhyCh;
} ADC_CTRL_TRANSFORM_INTO_VOLT_T;

//ADC_CMD_TRANSFORM_INTO_TEMP
typedef struct
{
   DCL_UINT32   u4Volt;
   DCL_UINT32   u4Temp;
} ADC_CTRL_TRANSFORM_INTO_TEMP_T;

//ADC_CMD_TRANSFORM_INTO_CURR
typedef struct
{
   DCL_UINT32   u4Volt;
   DCL_UINT32   u4Curr;
} ADC_CTRL_TRANSFORM_INTO_CURR_T;

//typedef void (*PFN_DCLSADC_MEASURE_CALLBACK)(DCL_INT32 handle);
//ADC_CMD_REGISTER_MEASURE_CB
typedef struct
{
   kal_timer_func_ptr pfMeasure_cb;
} ADC_CTRL_REGISTER_MEASURE_CB_T;

typedef void (*PFN_DCLSADC_COMPLETE_CALLBACK)(DCL_INT32 handle, DCL_INT32 volt_result, DCL_DOUBLE adc_result);
typedef void (*PFN_DCLSADC_COMPLETE_MULTI_CALLBACK)(DCL_INT32 handle, DCL_INT32 *volt_array_result, DCL_DOUBLE *adc_array_result);
//ADC_CMD_REGISTER_COMPLETE_CB;
typedef struct
{
   PFN_DCLSADC_COMPLETE_CALLBACK pfComplete_cb;
} ADC_CTRL_REGISTER_COMPLETE_CB_T;

typedef struct
{
   PFN_DCLSADC_COMPLETE_MULTI_CALLBACK pfComplete_cb;
} ADC_CTRL_REGISTER_COMPLETE_MULTI_CB_T;


//ADC_CMD_GET_SCHEDULER_PARAMETER
typedef struct{
  DCL_UINT32     u4Ownerid;
  DCL_UINT32     u4Sapid;
	DCL_UINT32     u4Period;
	DCL_UINT8      u1Adc_phy_id;
	DCL_UINT8      u1Adc_logic_id;
	DCL_UINT8		   u1Evaluate_count;	/*how many to average*/
	DCL_BOOL       bSend_primitive;
	DCL_BOOL       bConti_measure;
	DCL_UINT32     u4Adc_sche_event_id;
	void (*complete)(DCL_INT32 adc_handle, DCL_INT32 volt_result, DCL_DOUBLE adc_result);/*callback for upper layer*/
}DCL_ADC_SCHEDULER_PARA_T;
typedef struct
{
   DCL_UINT32 u4Handle;
   DCL_ADC_SCHEDULER_PARA_T pPara;
} ADC_CTRL_GET_SCHEDULER_PARAMETER_T;

//ADC_CMD_GET_MAX_PHYSICAL_CH
typedef struct
{
	DCL_UINT32     u4Adc_max_ch;
} ADC_CTRL_GET_MAX_PHYSICAL_CH_T;

//ADC_CMD_SET_CALIBRATION_DATA:
typedef struct
{
	void  *ilm_ptr;
}ADC_CTRL_SET_CALIBRATION_DATA_T;

//ADC_CMD_READ_CALIBRATION_DATA
typedef struct
{
   DCL_INT32 i4ADCSlope[16]; //we do not want to include adc_hw.h here
   DCL_INT32 i4ADCOffset[16]; //use 16 instead of ADC_MAX_CHANNEL
}ADC_CTRL_READ_CALIBRATION_DATA_T;

//ADC_CMD_SCHE_ID_GET_HANDLE
typedef struct{
  DCL_UINT32     u4Handle;
   DCL_UINT32     u4Adc_sche_id;
}DCL_CTRL_SCHE_ID_GET_HANDLE_T;

typedef struct{
	DCL_UINT8      bEnable;
	DCL_UINT8     *u4ADC_ch_number;	
	DCL_UINT8     u4Adc_max_ch_number;
	PFN_DCLSADC_COMPLETE_MULTI_CALLBACK complete_multi_cb;
}DCL_MULTI_CHANNEL_PARA_T;

#define ADC_CTRLS \
   ADC_CTRL_CREATE_OBJECT_T rADCCreateObj; \
   ADC_CTRL_MODIFY_PARAM_T rADCModifyParam; \
   ADC_CTRL_IMM_MEASURE_T rADCImmMeasure; \
   ADC_CTRL_SYNC_MEASURE_T rADCSyncMeasure; \
   ADC_CTRL_TDMA_SYNC_SETUP_T rADCTDMASyncSetup; \
   ADC_CTRL_POWER_T rADCPower; \
   ADC_CTRL_TIMER_ALIGN_T rADCTimerAlign; \
   ADC_CTRL_REGISTER_MEASURE_CB_T rADCRegisterMeasureCB; \
   ADC_CTRL_REGISTER_COMPLETE_CB_T rADCRegisterCompleteCB; \
   ADC_CTRL_GET_PHYSICAL_CHANNEL_T rADCGetPhyChannel; \
   DCL_CTRL_SCHE_ID_GET_HANDLE_T rADCScheIdGetHandle; \
   ADC_CTRL_TRANSFORM_INTO_VOLT_T rADCTransformVolt; \
   ADC_CTRL_TRANSFORM_INTO_TEMP_T rADCTransformTemp; \
   ADC_CTRL_TRANSFORM_INTO_CURR_T rADCTransformCurr; \
   ADC_CTRL_GET_DATA_2_META_T rADCGetData2Meta; \
   ADC_CTRL_GET_DATA_T rADCGetData; \
   ADC_CTRL_GET_META_DATA_T rADCGetMetaData; \
   ADC_CTRL_GET_SCHEDULER_PARAMETER_T rGetSchedulerPara; \
   ADC_CTRL_GET_MAX_PHYSICAL_CH_T rADCGetMaxPhyCh; \
   ADC_CTRL_SET_CALIBRATION_DATA_T rSetCalibrationData; \
   ADC_CTRL_READ_CALIBRATION_DATA_T rReadCalibrationData; \
   ADC_CTRL_GET_IMM_DATA_ON_BOOTING_T rGetImmDataOnBooting; \
   ADC_CTRL_GET_TEMP_T rGetTempData; \
   DCL_MULTI_CHANNEL_PARA_T rMultiChannelPara;
#endif // #ifndef __DCL_ADC_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT   

#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_ADC_H_PROTOTYPE__
#define __DCL_ADC_H_PROTOTYPE__

/*************************************************************************
* FUNCTION
*  DclSADC_Initialize
*
* DESCRIPTION
*  This function is to initialize SW ADC module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclSADC_Initialize(void);
/*************************************************************************
* FUNCTION
*  DclSADC_Open
*
* DESCRIPTION
*  This function is to open the SW ADC module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_ADC
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed
*  Other value: A valid handle
*
*************************************************************************/
extern DCL_HANDLE DclSADC_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION
*  DclSADC_ReadData
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
extern DCL_STATUS DclSADC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclSADC_WriteData
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
extern DCL_STATUS DclSADC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclSADC_Configure
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
extern DCL_STATUS DclSADC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION
*  DclSADC_RegisterCallback
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
extern DCL_STATUS DclSADC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
/*************************************************************************
* FUNCTION
*  DclSADC_Control
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
extern DCL_STATUS DclSADC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION
*  DclSADC_Close
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
extern DCL_STATUS DclSADC_Close(DCL_HANDLE handle);

/*************************************************************************
* FUNCTION
*  DclHADC_Initialize
*
* DESCRIPTION
*  This function is to initialize Hardware ADC module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclHADC_Initialize(void);
/*************************************************************************
* FUNCTION
*  DclHADC_Open
*
* DESCRIPTION
*  This function is to open the Hardware ADC module and return a handle
*
* PARAMETERS
*  dev: only valid for Hardware DCL_ADC
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed
*  Other value: A valid handle
*
*************************************************************************/
extern DCL_HANDLE DclHADC_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION
*  DclHADC_ReadData
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
extern DCL_STATUS DclHADC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclHADC_WriteData
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
extern DCL_STATUS DclHADC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclHADC_Configure
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
extern DCL_STATUS DclHADC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION
*  DclHADC_RegisterCallback
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
extern DCL_STATUS DclHADC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
/*************************************************************************
* FUNCTION
*  DclHADC_Control
*
* DESCRIPTION
*  This function is to send command to control the Hardware ADC module.
*
* PARAMETERS
*  handle: A valid handle return by DclHADC_Open()
*  cmd: A control command for ADC module
*          1. ADC_CMD_IMM_MEASURE: to perform a immediate mode measurement (Register control only, not include power setting)
*          2. ADC_CMD_SYNC_MEASURE: to perform a sync mode measurement (Register control only, not include power setting)
*          3. ADC_CMD_TDMA_SYNC_SETUP: to setup TDMA sync mode parameters
*          4. ADC_CMD_POWER: to turn on/off ADC module power
*  data: The data of the control command
*          1. ADC_CMD_IMM_MEASURE: pointer to a ADC_CTRL_IMM_MEASURE_T structure
*          2. ADC_CMD_SYNC_MEASURE: pointer to a ADC_CTRL_SYNC_MEASURE_T structure
*          3. ADC_CMD_TDMA_SYNC_SETUP: pointer to a ADC_CTRL_TDMA_SYNC_SETUP_T structure
*          4. ADC_CMD_POWER: pointer to a ADC_CTRL_POWER_T structure
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
extern DCL_STATUS DclHADC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION
*  DclHADC_Close
*
* DESCRIPTION
*  This function is to close the Hardware ADC module.
*
* PARAMETERS
*  handle: the returned handle value of HDclADC_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclHADC_Close(DCL_HANDLE handle);

#endif // #ifndef __DCL_ADC_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE
