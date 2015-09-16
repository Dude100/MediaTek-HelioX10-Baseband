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
#include "kal_public_api.h"
#include "dcl.h"
#include "nvram_interface.h"
#include "adc_nvram_def.h"

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

static kal_bool fgHADCInit = KAL_FALSE;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			#if !defined(DRV_DISABLE_SAP_ID)
/* under construction !*/
			#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else

DCL_STATUS DclSADC_Initialize(void){return STATUS_OK;}
DCL_HANDLE DclSADC_Open(DCL_DEV dev, DCL_FLAGS flags){return STATUS_OK;}
DCL_STATUS DclSADC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options){return STATUS_OK;}
DCL_STATUS DclSADC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options){return STATUS_OK;}
DCL_STATUS DclSADC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure){return STATUS_OK;}
DCL_STATUS DclSADC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback){return STATUS_OK;}
DCL_STATUS DclSADC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data){return STATUS_OK;}
DCL_STATUS DclSADC_Close(DCL_HANDLE handle){return STATUS_OK;}

#endif



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
extern nvram_ltable_entry_struct logical_data_item_table_adc[];
extern void thermal_prot_init();
DCL_STATUS DclHADC_Initialize(void){

    dbg_print("[ADC] %s\r\n", __FUNCTION__);
    
    if(fgHADCInit == KAL_FALSE) 
    {
        nvram_ltable_register(logical_data_item_table_adc);
        
        ADC_Init();

        fgHADCInit = KAL_TRUE;
    }

    thermal_prot_init();

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
static kal_bool fgHADCOpen = KAL_FALSE;
DCL_HANDLE DclHADC_Open(DCL_DEV dev, DCL_FLAGS flags)
{
    if (!fgHADCOpen) {
        adc_read_calibration_data();
        fgHADCOpen = KAL_TRUE;
    }

	if( ( dev != DCL_ADC ) || (fgHADCInit == KAL_FALSE))
	{
	       ASSERT(0);
		return DCL_HANDLE_INVALID;		// Incorrecr device ID
	}

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
		    #if 1
			ADC_CTRL_IMM_MEASURE_T  *prIMMMeasure;
			prIMMMeasure = &(data->rADCImmMeasure);
			prIMMMeasure->u2ADCValue = (DCL_UINT16)adc_measureVoltage(prIMMMeasure->u2Channel,
			                                              (double *)&prIMMMeasure->u2ADCValue);
			#endif
			
			return STATUS_OK;
		}
		case ADC_CMD_SYNC_MEASURE:
		{
		    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			#endif
			
			return STATUS_OK;
		}
		case ADC_CMD_TDMA_SYNC_SETUP:
		{
            #if 0//defined(DRV_ADC_FULL_FUNC)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			#else // #if defined(DRV_ADC_FULL_FUNC)
			
			// Not supported
			return STATUS_INVALID_CMD;
			#endif
		}
		case ADC_CMD_POWER:
		{
		    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			#endif
			
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
		    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			#endif
			
			return STATUS_OK;
		}     
		case ADC_CMD_GET_TEMP:
		{
		    ADC_CTRL_GET_TEMP_T *prGetTemp;
		    prGetTemp = &(data->rGetTempData);

		    prGetTemp->i2Temp = ADC_GetImmTemp(prGetTemp->u2Channel);

		    return STATUS_OK;
		}

		case ADC_CMD_GET_PHYSICAL_CHANNEL:
		{
		    ADC_CTRL_GET_PHYSICAL_CHANNEL_T *prGetChannel;
		    kal_int16 iChannel; 
		    
            prGetChannel = &(data->rADCGetPhyChannel);
            iChannel = ADC_GetPhysicalChannel(prGetChannel->u2AdcName);

            if (iChannel >= 0) {
                prGetChannel->u1AdcPhyCh = (DCL_UINT8)iChannel;
                return STATUS_OK;
            } else {
                prGetChannel->u1AdcPhyCh = 0;
                return STATUS_INVALID_DEVICE;
            }
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
/***
For ALPS01480745, create a dummy LID in NVRAM to match LID in Database
***/
extern nvram_ltable_entry_struct logical_data_item_table_adc[];
DCL_STATUS DclHADC_Initialize(void)
{
#if defined(__MTK_TARGET__) && !defined(ATEST_ENABLE) && !defined(NVRAM_NOT_PRESENT)
    static kal_bool fgHADCInit = KAL_FALSE;
    
    /* create dummy NVRAM item */
    if(fgHADCInit == KAL_FALSE) 
    {
        nvram_ltable_register(logical_data_item_table_adc);
        fgHADCInit = KAL_TRUE;
    }
#endif

    return STATUS_OK;
}
DCL_HANDLE DclHADC_Open(DCL_DEV dev, DCL_FLAGS flags){return STATUS_OK;}
DCL_STATUS DclHADC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options){return STATUS_OK;}
DCL_STATUS DclHADC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options){return STATUS_OK;}
DCL_STATUS DclHADC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure){return STATUS_OK;}
DCL_STATUS DclHADC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback){return STATUS_OK;}
DCL_STATUS DclHADC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data){return STATUS_OK;}
DCL_STATUS DclHADC_Close(DCL_HANDLE handle){return STATUS_OK;}
#endif // #if defined(DRV_ADC_OFF)

