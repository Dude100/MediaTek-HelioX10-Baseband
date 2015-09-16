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
 *    dcl_adc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the ADC driver.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features.h"
#include "drv_comm.h"
#include "syscomp_config.h"   /*MOD_BMT*/
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
#include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"       /* Event scheduler */
#include "stack_timer.h"     /*Timer*/
#include "adc_hw.h"
#include "adc_sw.h"
#include "adcsche.h"
#include "kal_public_api.h"
#include "dcl.h"


#if !defined(DRV_ADC_OFF)

// Variables for DCL
#define DCL_ADC_DEV_MAGIC_NUM		(0x20000000) //do not use MAGIC NUM, because it is not used in old API and callback function
#define MAX_DCL_ADC_HANDLE		(120)
#define MAX_DCL_ADC_SCHE_ID		(30)

typedef struct{
	DCL_HANDLE handle;
#if !defined(DRV_DISABLE_SAP_ID)
	DCL_UINT32 adc_sap_id;
#endif
//	DCL_UINT8 adc_sche_id;
//	DCL_BOOL active;
	kal_timer_func_ptr measure_cb;
	PFN_DCLSADC_COMPLETE_CALLBACK complete_cb;
}dcl_adc_sche_mgr;

dcl_adc_sche_mgr dcl_adc_sche_id[MAX_DCL_ADC_SCHE_ID];
DCL_UINT8 dcl_adc_handle_used[MAX_DCL_ADC_HANDLE];

static kal_bool fgHADCInit = KAL_FALSE;


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
DCL_STATUS DclSADC_Initialize(void){
	DCL_UINT32 i;

	// Set all mapping to invalid IDs
	for (i=0;i<MAX_DCL_ADC_HANDLE;i++){
		dcl_adc_handle_used[i] = 0;
	}
	adc_sche_init();

	return STATUS_OK;
}


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
DCL_HANDLE DclSADC_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	DCL_UINT32 savedMask;
	DCL_UINT32 i;

	if (dev != DCL_ADC){
		return DCL_HANDLE_INVALID;		// Incorrecr device ID
	}
	for (i=0;i<MAX_DCL_ADC_HANDLE;i++)
	{
		savedMask = SaveAndSetIRQMask();
		if(dcl_adc_handle_used[i] == 0)
		{
			dcl_adc_handle_used[i] = 1;
			RestoreIRQMask(savedMask);
			break;
		}
		RestoreIRQMask(savedMask);
	}

	if(i >= MAX_DCL_ADC_HANDLE)
	{
		return DCL_HANDLE_INVALID;
	}
	
	return (DCL_HANDLE)i;
}

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
DCL_STATUS DclSADC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options){
	return STATUS_UNSUPPORTED;
}

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
DCL_STATUS DclSADC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options){
	return STATUS_UNSUPPORTED;
}

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
DCL_STATUS DclSADC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure){
	return STATUS_UNSUPPORTED;
}

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
DCL_STATUS DclSADC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback){
	return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclSADC_GetScheId
*
* DESCRIPTION
*  This function is to get schedule id from DCL HANDLE.
*
* PARAMETERS
*  void
*
* RETURNS
*  DCL_UINT8: adc schedule id.
*
*************************************************************************/
DCL_UINT32 dclsadc_GetScheId(DCL_HANDLE handle)
{
	DCL_UINT32 i;
	
	if(dcl_adc_handle_used[handle] == 0)
	{
		ASSERT(0);		// Error!! The value shouldn't be 0
	}
	for (i=0;i<MAX_DCL_ADC_SCHE_ID;i++)
	{
		//index of dcl_adc_sche_id means adc schedule id
		if (dcl_adc_sche_id[i].handle == handle)
		{
			break;
		}
	}
	return i;
}

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
DCL_STATUS DclSADC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	if(handle >= MAX_DCL_ADC_HANDLE || handle <= DCL_HANDLE_INVALID)
	{
		ASSERT(0);
	}

	switch (cmd)
	{
		case ADC_CMD_CREATE_OBJECT:
		{
			DCL_UINT32 sche_id;
			ADC_CTRL_CREATE_OBJECT_T  *prCreateObj;
			
			if(dcl_adc_handle_used[handle] == 0)
			{
				ASSERT(0);		// Error!! The value shouldn't be 0
			}
			prCreateObj = &(data->rADCCreateObj);
			// Call into core function
			sche_id = adc_sche_create_object(prCreateObj);
			if(sche_id == 0xFF)
				return STATUS_OK;
			dcl_adc_sche_id[sche_id].handle = handle;
			#if !defined(DRV_DISABLE_SAP_ID)
			dcl_adc_sche_id[sche_id].adc_sap_id = prCreateObj->u4Sapid;
			#endif
			dcl_adc_sche_id[sche_id].complete_cb = NULL;
			dcl_adc_sche_id[sche_id].measure_cb = NULL;
			return STATUS_OK;
		}
	
		case ADC_CMD_MODIFY_PARAM:
		{
			ADC_CTRL_MODIFY_PARAM_T  *prModifyParam;
			DCL_UINT32 sche_id;

			sche_id = dclsadc_GetScheId(handle);
			if(sche_id == MAX_DCL_ADC_SCHE_ID) //not find correct sche_id //MODEM_ONLY load only allow RFTMP to access
				return STATUS_OK;	
			prModifyParam = &(data->rADCModifyParam);
			adc_sche_modify_parameters(sche_id , prModifyParam->u4Period, prModifyParam->u1EvaluateCount);
			return STATUS_OK;
		}
		
		case ADC_CMD_START_MEASURE:
		{
			DCL_UINT32 sche_id;

			sche_id = dclsadc_GetScheId(handle);
			if(sche_id == MAX_DCL_ADC_SCHE_ID) //not find correct sche_id //MODEM_ONLY load only allow RFTMP to access
				return STATUS_OK;	
			adc_sche_add_item(sche_id,
					dcl_adc_sche_id[sche_id].complete_cb,
					dcl_adc_sche_id[sche_id].measure_cb);
			return STATUS_OK;

		}
		
		case ADC_CMD_STOP_MEASURE:
		{
			DCL_UINT32 sche_id;

			sche_id = dclsadc_GetScheId(handle);
			if(sche_id == MAX_DCL_ADC_SCHE_ID) //not find correct sche_id //MODEM_ONLY load only allow RFTMP to access
				return STATUS_OK;	
			adc_sche_remove_item(sche_id);
			return STATUS_OK;
		}
		
		case ADC_CMD_SET_TIMER_PAGE_ALIGN:
		{
			return STATUS_UNSUPPORTED;
		}
		
		case ADC_CMD_REGISTER_MEASURE_CB:
		{
			ADC_CTRL_REGISTER_MEASURE_CB_T  *prRegisterMeasureCB;
			DCL_UINT32 sche_id;
			
			sche_id = dclsadc_GetScheId(handle);
			if(sche_id == MAX_DCL_ADC_SCHE_ID) //not find correct sche_id //MODEM_ONLY load only allow RFTMP to access
				return STATUS_OK;	
			prRegisterMeasureCB = &(data->rADCRegisterMeasureCB);
			dcl_adc_sche_id[sche_id].measure_cb = prRegisterMeasureCB->pfMeasure_cb;
			return STATUS_OK;
		}
		
		case ADC_CMD_REGISTER_COMPLETE_CB:
		{
			ADC_CTRL_REGISTER_COMPLETE_CB_T  *prRegisterCompleteCB;
			DCL_UINT32 sche_id;
			
			sche_id = dclsadc_GetScheId(handle);
			if(sche_id == MAX_DCL_ADC_SCHE_ID) //not find correct sche_id //MODEM_ONLY load only allow RFTMP to access
				return STATUS_OK;	
			prRegisterCompleteCB = &(data->rADCRegisterCompleteCB);
			dcl_adc_sche_id[sche_id].complete_cb = prRegisterCompleteCB->pfComplete_cb;
			return STATUS_OK;
		}
		
		case ADC_CMD_GET_CHANNEL:
		{
			ADC_CTRL_GET_PHYSICAL_CHANNEL_T  *prGetChannel;
			prGetChannel = &(data->rADCGetPhyChannel);
			
			prGetChannel->u1AdcPhyCh = adc_sche_get_channel((adc_channel_type)prGetChannel->u2AdcName);
			return STATUS_OK;
		}
		
		case ADC_CMD_TRANSFORM_INTO_VOLT:
		{
			ADC_CTRL_TRANSFORM_INTO_VOLT_T  *prTransformVolt;
			prTransformVolt = &(data->rADCTransformVolt);
			
			prTransformVolt->u4Volt = adc_adc2vol(prTransformVolt->u1AdcPhyCh, prTransformVolt->d8AdcValue);
			return STATUS_OK;
		}
		
		case ADC_CMD_TRANSFORM_INTO_TEMP:
		{
			ADC_CTRL_TRANSFORM_INTO_TEMP_T  *prTransformTemp;
			prTransformTemp = &(data->rADCTransformTemp);
			
			prTransformTemp->u4Temp = volt2temp(prTransformTemp->u4Volt);
			return STATUS_OK;
		}
		
		case ADC_CMD_TRANSFORM_INTO_CURR:
		{
			ADC_CTRL_TRANSFORM_INTO_CURR_T  *prTransformCurr;
			prTransformCurr = &(data->rADCTransformCurr);
			
			prTransformCurr->u4Curr = volt2isense(prTransformCurr->u4Volt);
			return STATUS_OK;
		}
		
		case ADC_CMD_GET_SCHEDULER_PARAMETER:
		{
			ADC_CTRL_GET_SCHEDULER_PARAMETER_T  *prGetSchedulerPara;
			ADCScheMeasParameter *adc_para;
			DCL_UINT32 sche_id;
			
			sche_id = dclsadc_GetScheId(handle);
			if(sche_id == MAX_DCL_ADC_SCHE_ID) //not find correct sche_id //MODEM_ONLY load only allow RFTMP to access
				return STATUS_OK;	
			prGetSchedulerPara = &(data->rGetSchedulerPara);
			adc_sche_get_parameter(sche_id, &adc_para);
			prGetSchedulerPara->pPara.u4Ownerid           = (DCL_UINT32)adc_para->ownerid;
			prGetSchedulerPara->pPara.u4Sapid             = (DCL_UINT32)adc_para->sapid;
			prGetSchedulerPara->pPara.u4Period            = (DCL_UINT32)adc_para->period;
			prGetSchedulerPara->pPara.u1Adc_phy_id        = (DCL_UINT8) adc_para->adc_phy_id;
			prGetSchedulerPara->pPara.u1Adc_logic_id      = (DCL_UINT8) adc_para->adc_logic_id;
			prGetSchedulerPara->pPara.u1Evaluate_count    = (DCL_UINT8) adc_para->evaluate_count;
			prGetSchedulerPara->pPara.bSend_primitive     = (DCL_BOOL)  adc_para->send_primitive;
			prGetSchedulerPara->pPara.bConti_measure      = (DCL_BOOL)  adc_para->conti_measure;
			prGetSchedulerPara->pPara.u4Adc_sche_event_id = (DCL_UINT32)adc_para->adc_sche_event_id;
			prGetSchedulerPara->pPara.complete            = adc_para->complete;

			return STATUS_OK;
		}
		case ADC_CMD_SET_CALIBRATION_DATA:
		{
#ifdef DRV_ADC_NO_CALIBRATION
#else
			ADC_CTRL_SET_CALIBRATION_DATA_T  *prSetCalibrationData;
			prSetCalibrationData = &(data->rSetCalibrationData);

			adc_set_adc_calibration_data((ilm_struct*)prSetCalibrationData->ilm_ptr);
#endif //#ifdef DRV_ADC_NO_CALIBRATION			
			return STATUS_OK;

		}
		case ADC_CMD_READ_CALIBRATION_DATA:
		{
			ADC_CTRL_READ_CALIBRATION_DATA_T  *prReadCalibrationData;
			DCL_UINT32 i;
			DCL_DOUBLE slope, offset;
			
			prReadCalibrationData = &(data->rReadCalibrationData);
			adc_read_efuse_data(&slope, &offset);
			if(ADC_MAX_CHANNEL > 16) // we only define 16 unit in i4ADCSlope[]
				ASSERT(0);
			for(i=0;i<ADC_MAX_CHANNEL;i++)
			{
				prReadCalibrationData->i4ADCSlope[i] = slope;
				prReadCalibrationData->i4ADCOffset[i] = offset;
			}
			return STATUS_OK;
		}
		case ADC_CMD_READ_CALIBRATION_INFORM_IN_USBBOOT:
		{
			adc_read_calibration_data_inform();
			return STATUS_OK;
		}
		case ADC_CMD_SCHE_ID_GET_HANDLE:
		{
			DCL_CTRL_SCHE_ID_GET_HANDLE_T  *prADCScheIdGetHandle;
			prADCScheIdGetHandle = &(data->rADCScheIdGetHandle);
			
			prADCScheIdGetHandle->u4Handle = dcl_adc_sche_id[prADCScheIdGetHandle->u4Adc_sche_id].handle;
			return STATUS_OK;
		}

		case ADC_CMD_SET_MULTI_CHANNEL_READ:
		{
			DCL_UINT32 sche_id;	
			DCL_MULTI_CHANNEL_PARA_T *prADCMultiChannelPara;

			prADCMultiChannelPara = &(data->rMultiChannelPara);
			sche_id = dclsadc_GetScheId(handle);

			adc_multi_channel_set(sche_id,prADCMultiChannelPara);
			
			return STATUS_OK;
		}
	
		default:
			return STATUS_INVALID_CMD;
	}
//	return STATUS_FAIL;
}

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
DCL_STATUS DclSADC_Close(DCL_HANDLE handle)
{
	ASSERT(handle >= 0);
	if (dcl_adc_handle_used[handle] == 0)
	{
		ASSERT(0);
		return STATUS_NOT_OPENED;		// Can NOT close an un-opend handle
	}

	dcl_adc_handle_used[handle] = 0;
	// Currently, adc_sche_XXX APis does NOT provide remove object capability
	// So, we just return without doing anything
	return STATUS_OK;
}




///////////////////////////////////////////////////////////////////////////////
#define MAX_DCL_HADC_HANDLE			(1)



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
DCL_STATUS DclHADC_Initialize(void){

   if(fgHADCInit == KAL_FALSE) 
   {
	ADC_Init();

	fgHADCInit = KAL_TRUE;
   }

	return STATUS_OK;
}


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
DCL_HANDLE DclHADC_Open(DCL_DEV dev, DCL_FLAGS flags)
{
//	DCL_HANDLE  ret_handle = 0;
//	DCL_UINT32 savedMask;

	if( ( dev != DCL_ADC ) || (fgHADCInit == KAL_FALSE))
	{
	       ASSERT(0);
		return DCL_HANDLE_INVALID;		// Incorrecr device ID
	}

//	if (dcl_hadc_handle_count >= MAX_DCL_HADC_HANDLE){
//		ASSERT(0);
//		return DCL_HANDLE_INVALID;		// Too many opened handles
//	}

	//savedMask = SaveAndSetIRQMask();
	//dcl_hadc_handle_count++;
	//ret_handle = dcl_hadc_handle_count;
	//RestoreIRQMask(savedMask);
	//return ret_handle;
	return DCL_ADC_DEV_MAGIC_NUM;
}

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
DCL_STATUS DclHADC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

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
DCL_STATUS DclHADC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

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
DCL_STATUS DclHADC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

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
DCL_STATUS DclHADC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_UNSUPPORTED;
}


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
kal_bool dcl_hadc_power_state = KAL_FALSE;
DCL_STATUS DclHADC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	switch (cmd)
	{
		case ADC_CMD_IMM_MEASURE:
		{
			ADC_CTRL_IMM_MEASURE_T  *prIMMMeasure;
			prIMMMeasure = &(data->rADCImmMeasure);
	
			if (!dcl_hadc_power_state){
				ASSERT(0);
				return STATUS_FAIL;
			}

			prIMMMeasure->u2ADCValue = ADC_IMM_Data(prIMMMeasure->u2Channel);
			return STATUS_OK;
		}
		case ADC_CMD_SYNC_MEASURE:
		{
			ADC_CTRL_SYNC_MEASURE_T  *prSYNCMeasure;
			prSYNCMeasure = &(data->rADCSyncMeasure);

			if (!dcl_hadc_power_state){
				ASSERT(0);
				return STATUS_FAIL;
			}

			prSYNCMeasure->u2ADCValue = ADC_SYNC_Data(prSYNCMeasure->u2Channel);
			return STATUS_OK;
		}
		case ADC_CMD_TDMA_SYNC_SETUP:
		{
                        #if defined(DRV_ADC_FULL_FUNC)
			ADC_CTRL_TDMA_SYNC_SETUP_T  *prTDMASyncSetup;
			prTDMASyncSetup = &(data->rADCTDMASyncSetup);
			adc_tdma_time_setup(prTDMASyncSetup->u2Event0, prTDMASyncSetup->u2Event1);
			return STATUS_OK;
			#else // #if defined(DRV_ADC_FULL_FUNC)
			
			// Not supported
			return STATUS_INVALID_CMD;
			#endif
		}
		case ADC_CMD_POWER:
		{
			ADC_CTRL_POWER_T  *prPower;
			prPower = &(data->rADCPower);
			if (prPower->fgEnable == DCL_TRUE){
				// Enable ADC power
				adc_pwrdown_disable();
				dcl_hadc_power_state = KAL_TRUE;
			}else{
				// Disable ADC power
				dcl_hadc_power_state = KAL_FALSE;
				adc_pwrdown_enable();
			}
			return STATUS_OK;
		}
		case ADC_CMD_GET_DATA_2_META:
		{
			ADC_CTRL_GET_DATA_2_META_T  *prGetData2Meta;
			prGetData2Meta = &(data->rADCGetData2Meta);
			
			prGetData2Meta->u4ADCData = ADC_GetData2Meta(prGetData2Meta->u1Channel, prGetData2Meta->u2MeaCount);
			return STATUS_OK;
		}
		case ADC_CMD_GET_DATA:
		{
			ADC_CTRL_GET_DATA_T  *prGetData;
			prGetData = &(data->rADCGetData);
			
			prGetData->u4ADCData = ADC_GetData(prGetData->u1Channel);
			return STATUS_OK;
		}
		case ADC_CMD_GET_META_DATA:
		{
			ADC_CTRL_GET_META_DATA_T  *prGetMetaData;
			prGetMetaData = &(data->rADCGetMetaData);
			
			prGetMetaData->u4ADCData = ADC_GetMeaData(prGetMetaData->u1Channel, prGetMetaData->u2MeaCount);
			return STATUS_OK;
		}
		case ADC_CMD_GET_MAX_PHYSICAL_CH:
		{
			ADC_CTRL_GET_MAX_PHYSICAL_CH_T  *prGetMaxPhyCh;
			prGetMaxPhyCh = &(data->rADCGetMaxPhyCh);
			
			prGetMaxPhyCh->u4Adc_max_ch = ADC_MAX_CHANNEL;
			return STATUS_OK;
		}
		case ADC_CMD_GET_IMM_DATA_ON_BOOTING:
		{
			ADC_CTRL_GET_IMM_DATA_ON_BOOTING_T  *prGetImmDataOnBooting;
			prGetImmDataOnBooting = &(data->rGetImmDataOnBooting);
	
			ADC_IMM_Data_on_Booting((kal_uint32)prGetImmDataOnBooting->u4Channel, (kal_uint32)prGetImmDataOnBooting->u4MeaCount, (kal_uint16 *)prGetImmDataOnBooting->u2ADCData);
			return STATUS_OK;
		}        
		default:
			return STATUS_INVALID_CMD;
	}
	//return STATUS_FAIL;
}

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
DCL_STATUS DclHADC_Close(DCL_HANDLE handle)
{
//	DCL_UINT32 savedMask;

	// Error check
//	if (dcl_hadc_handle_count == 0){
//		ASSERT(0);
//		return STATUS_NOT_OPENED;
//	}

	// Extract handle idx

//	savedMask = SaveAndSetIRQMask();
//	dcl_hadc_handle_count --;
//	RestoreIRQMask(savedMask);	
//	fgHADCInit = KAL_FALSE;	

	return STATUS_OK;
}

// Only empty APIs
#else // DRV_ADC_OFF is defined
DCL_STATUS DclSADC_Initialize(void){return STATUS_OK;}
DCL_HANDLE DclSADC_Open(DCL_DEV dev, DCL_FLAGS flags){return STATUS_OK;}
DCL_STATUS DclSADC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options){return STATUS_OK;}
DCL_STATUS DclSADC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options){return STATUS_OK;}
DCL_STATUS DclSADC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure){return STATUS_OK;}
DCL_STATUS DclSADC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback){return STATUS_OK;}
DCL_STATUS DclSADC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data){return STATUS_OK;}
DCL_STATUS DclSADC_Close(DCL_HANDLE handle){return STATUS_OK;}
DCL_STATUS DclHADC_Initialize(void){return STATUS_OK;}
DCL_HANDLE DclHADC_Open(DCL_DEV dev, DCL_FLAGS flags){return STATUS_OK;}
DCL_STATUS DclHADC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options){return STATUS_OK;}
DCL_STATUS DclHADC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options){return STATUS_OK;}
DCL_STATUS DclHADC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure){return STATUS_OK;}
DCL_STATUS DclHADC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback){return STATUS_OK;}
DCL_STATUS DclHADC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data){return STATUS_OK;}
DCL_STATUS DclHADC_Close(DCL_HANDLE handle){return STATUS_OK;}
#endif // #if defined(DRV_ADC_OFF)

