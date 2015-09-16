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
 *    adcsche.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines ADC scheduler.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include    "drv_features.h"
#include    "drv_comm.h"
#include    "kal_public_defs.h" //MSBB change #include 	"stack_msgs.h"
#include    "reg_base.h"
#include    "adc_hw.h"
#include    "adc_sw.h"
#include    "adcsche.h"
#include    "bmt_trc.h"
// #include    "ccci_rpcsvc.h" //ccci
#include	"drv_msgid.h"
// For RHR ADD Usage
#include	"kal_trace.h"
#include    "kal_public_defs.h" //MSBB change #include	"stack_config.h"
#include    "drvsignals.h"
#include    "dcl.h"
#include    "kal_general_types.h"
#include    "bmt.h"
#include    "kal_public_api.h"
#include    "bmt_sw.h"
#if defined(__SMART_PHONE_MODEM__)
// #include    "ipc_rpc.h"
#endif

#if defined(DRV_ADC_OFF)
   #if !defined(DRV_ADC_NOT_EXIST)
   #define DRV_ADC_NOT_EXIST
   #endif
#endif

#ifndef DRV_ADC_NOT_EXIST
static kal_uint8 adc_sche_id_no=0;
static kal_uint32 adc_reg_status=0;
#endif //#ifndef DRV_ADC_NOT_EXIST

#ifndef DRV_ADC_NOT_EXIST
static void adc_sche_readback(void* msg_ptr);
#endif //#ifndef DRV_ADC_NOT_EXIST

/*compute from adc_sche_sum and adc_sche_count*/
double ADC_RESULT[ADC_SCHE_MAX_CHANNEL];
kal_int32 VOL_RESULT[ADC_SCHE_MAX_CHANNEL];

ADCScheMeasParameter adc_parameters[ADC_SCHE_MAX_CHANNEL];
kal_uint32 adc_sche_sum[ADC_SCHE_MAX_CHANNEL];	
kal_uint32 adc_sche_count[ADC_SCHE_MAX_CHANNEL];

// for multi channel read
ADCMultiChanParameter adc_multichan_paramters;
double ADC_MULTI_RESULT[BMT_ADC_MAX_CHANNEL_TOTAL];
signed long VOL_MULTI_RESULT[BMT_ADC_MAX_CHANNEL_TOTAL];
kal_uint32 adc_sche_multi_sum[BMT_ADC_MAX_CHANNEL_TOTAL];	
kal_uint8  adc_multichan_enable[ADC_SCHE_MAX_CHANNEL];

kal_uint32 adc_sche_rw_status;
volatile kal_bool adc_sync_mode_on = KAL_TRUE;
volatile kal_uint16 adc_imm_mode_cnt = 0;


extern void adc_sche_timer_init(void);
extern kal_int32 adc_adc2vol(kal_uint8 chann,double adcVoltage);
//extern const kal_uint16 adc_volt_factor[ADC_MAX_CHANNEL];


extern const kal_uint8 ADC_VBAT;
extern const kal_uint8 ADC_VISENSE;
extern const kal_uint8 ADC_VCHARGER;
extern const kal_uint8 ADC_VBATTMP;
extern const kal_uint8 ADC_PCBTMP;
extern const kal_uint8 ADC_ACCESSORYID;
extern const kal_uint8 ADC_CHR_USB;
extern const kal_uint8 ADC_OTG_VBUS;
extern const kal_uint8 ADC_RFTMP;
extern const kal_uint8 ADC_JACK_TYPE;
#if defined(DRV_ADC_GET_CHANNEL_NUMBER_FROM_AP)
#if defined(__EVB__)
kal_uint8 ADC_SP_RFTMP = DRV_ADC_EVB_RFTMP_CHANNEL_NUMBER;
#else
kal_uint8 ADC_SP_RFTMP = DRV_ADC_RFTMP_CHANNEL_NUMBER;
#endif
#endif


kal_uint8 adc_sche_get_channel(adc_channel_type type)
{
   kal_uint8 VBAT, VISENSE, VCHARGER;
   
#if defined(PMIC_FIXED_3_ADC_CH)
   VBAT = PMIC_ADC_VBAT_CH_NUM;
   VISENSE = PMIC_ADC_VISENSE_CH_NUM;
   VCHARGER = PMIC_ADC_VCHARGER_CH_NUM;
#else
   VBAT = ADC_VBAT;
   VISENSE = ADC_VISENSE;
   VCHARGER = ADC_VCHARGER;
#endif //#if defined(PMIC_FIXED_3_ADC_CH)

   switch(type)
   {
      case vbat_adc_channel:
         return ((kal_uint8)VBAT);
      case visense_adc_channel:
         return ((kal_uint8)VISENSE);
      case vbattmp_adc_channel:
         return ((kal_uint8)ADC_VBATTMP);
      case aux_adc_channel:
         return ((kal_uint8)ADC_ACCESSORYID);
      case vcharger_adc_channel:
         return ((kal_uint8)VCHARGER);     
      case pcbtmp_adc_channel:
         return ((kal_uint8)ADC_PCBTMP);
      case chr_usb_adc_channel:
         return ((kal_uint8)ADC_CHR_USB);        
      case otg_vbus_adc_channel:
         return ((kal_uint8)ADC_OTG_VBUS);	
      case rftmp_adc_channel:
#if defined(DRV_ADC_GET_CHANNEL_NUMBER_FROM_AP)
		return ADC_SP_RFTMP;
#else	  	
         return ((kal_uint8)ADC_RFTMP);
#endif
      default:
         ASSERT(0);         
         return 100;
   }
}


void adc_sche_get_parameter(kal_uint32 adc_sche_id, ADCScheMeasParameter **para)
{
	*para = &adc_parameters[adc_sche_id];
}


//default adc scheduler complete call back
void adc_sche_complete_callback(signed long handle, signed long volt_result, double adc_result)
{
#ifndef L4_NOT_PRESENT
	ilm_struct adc_sche_ilm_local;
	ilm_struct *adc_sche_ilm = &adc_sche_ilm_local;
	bmt_adc_measure_done_conf_struct *adc_sche_Prim;
	ADC_CTRL_GET_SCHEDULER_PARAMETER_T  SchedulerPara;
	kal_uint32 adc_sche_id;
	
	DclSADC_Control(handle, ADC_CMD_GET_SCHEDULER_PARAMETER, (DCL_CTRL_DATA_T *)&SchedulerPara);
	adc_sche_id = SchedulerPara.pPara.u1Adc_logic_id;
   
	if (adc_parameters[adc_sche_id].send_primitive)
	{
		adc_sche_Prim = (bmt_adc_measure_done_conf_struct*)
			   construct_local_para(sizeof(bmt_adc_measure_done_conf_struct), TD_CTRL);
		adc_sche_Prim->adc_handle = handle;
			
		adc_sche_Prim->volt= volt_result;
		adc_sche_Prim->adc_value = adc_result;

		DRV_SendPrimitive(adc_sche_ilm,
		   MOD_BMT,
		   adc_parameters[adc_sche_id].ownerid,
		   MSG_ID_BMT_ADC_MEASURE_DONE_CONF,
		   adc_sche_Prim,
		   adc_parameters[adc_sche_id].sapid);
		msg_send(adc_sche_ilm);
   }
#endif // #ifndef L4_NOT_PRESENT
}

void adc_sche_callback_send(ADCScheMeasParameter *adc_param)
{
#ifndef DRV_ADC_NOT_EXIST
	DCL_HANDLE adc_handle;
	DCL_CTRL_SCHE_ID_GET_HANDLE_T   adc_sche_id_to_handle;
	
	adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
	if(adc_handle == DCL_HANDLE_INVALID)
	{
		ASSERT(0);   
	}
	adc_sche_id_to_handle.u4Adc_sche_id = adc_param->adc_logic_id;
	DclSADC_Control(adc_handle, ADC_CMD_SCHE_ID_GET_HANDLE, (DCL_CTRL_DATA_T *)&adc_sche_id_to_handle); 

	if(KAL_TRUE == adc_multichan_enable[adc_param->adc_logic_id])
	{
		if(adc_multichan_paramters.multi_complete != NULL)
		{
			adc_multichan_paramters.multi_complete(adc_sche_id_to_handle.u4Handle,&VOL_MULTI_RESULT[0], &ADC_MULTI_RESULT[0]);
		}	
	}
	else				
	{
		if(adc_parameters[adc_param->adc_logic_id].complete != NULL)
		{
			kal_brief_trace(TRACE_INFO, BMT_ADC_CALLBACK_INFO_TRC,adc_parameters[adc_param->adc_logic_id].adc_phy_id,
			adc_parameters[adc_param->adc_logic_id].period,adc_parameters[adc_param->adc_logic_id].evaluate_count);
			
			adc_parameters[adc_param->adc_logic_id].complete(adc_sche_id_to_handle.u4Handle,VOL_RESULT[adc_param->adc_logic_id], ADC_RESULT[adc_param->adc_logic_id]);
		}
	}	
	DclSADC_Close(adc_handle);
#endif	
}


void adcsche_adc_measure_en(kal_bool adc_measure_enable)
{
#ifndef DRV_ADC_NOT_EXIST
    DCL_HANDLE pmu_handle;
    PMU_CTRL_CHR_SET_ADC_MEASURE_EN val;
    val.enable = adc_measure_enable;
    pmu_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    DclPMU_Control(pmu_handle, CHR_SET_ADC_MEASURE_EN, (DCL_CTRL_DATA_T *)&val);
    DclPMU_Close(pmu_handle);    
#endif	
}

/*
* FUNCTION
*	   adc_sche_measure
*
* DESCRIPTION                                                           
*   	This function is to measure ADC channel.
*
* CALLS  
*
* PARAMETERS
*	   adc_sche_id: logical channel id
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void adc_sche_measure(void* msg_ptr)
{
#ifndef DRV_ADC_NOT_EXIST
   ADCScheMeasParameter *adc_param = (ADCScheMeasParameter *)msg_ptr;

#if defined(ADC_RACE_CONDITION_CHECK)
	ADCRCCheckAndLock();
#endif // #if defined(ADC_RACE_CONDITION_CHECK)


#if defined(DRV_ADC_FULL_FUNC)
   adc_parameters[adc_param->adc_logic_id].adc_sche_event_id = NULL;
   
   if (adc_parameters[adc_param->adc_logic_id].conti_measure)
   {
      #if !defined(__CHARGER_WITH_IMMEDIMATE_ADC__)   
      #if !defined(ADC_REMOVE_IRQMASK)
      kal_uint32 savedMask;
      #endif //#if !defined(ADC_REMOVE_IRQMASK)
      ADCSAVEANDSETIRQMASK(savedMask);	//savedMask = SaveAndSetIRQMask();	
      adc_sync_mode_on = KAL_TRUE;
      adcsche_adc_measure_en(KAL_TRUE);
      ADCRESTOREIRQMASK(savedMask); //RestoreIRQMask(savedMask);
      ADCSAVEANDSETIRQMASK(savedMask);	//savedMask = SaveAndSetIRQMask();	
      adc_sync_mode_on = KAL_TRUE;
      adc_pwrdown_disable();
		// Don't care if adc_phy_id is illegal, it will be shifted out

		if(KAL_TRUE == adc_multichan_enable[adc_param->adc_logic_id])
		{
			kal_uint32 multi_channel = 0;
			kal_uint32 i;

			for(i=0;i<adc_multichan_paramters.max_multi_channel_number;i++)
			{
				multi_channel |= (1 << adc_multichan_paramters.multi_adc_phy_id[i]);
			}
	        DRV_ADC_SetBits(AUXADC_SYNC, multi_channel);
		}
		else
		{
	      DRV_ADC_SetBits(AUXADC_SYNC, (1<<adc_param->adc_phy_id));
		} 
      //DRV_ADC_Reg(AUXADC_SYNC) |= (1<<adc_param->adc_phy_id);
      ADCRESTOREIRQMASK(savedMask); //RestoreIRQMask(savedMask);
      #endif/* !defined(__CHARGER_WITH_IMMEDIMATE_ADC__)    */
      adc_sche_rw_status |= (1 << adc_param->adc_logic_id);
      adc_sche_set_timer(adc_param->adc_logic_id,1,adc_sche_readback);
   }
#endif      /*DRV_ADC_FULL_FUNC*/

#if defined(ADC_RACE_CONDITION_CHECK)
	ADCRCRelease();
#endif // #if defined(ADC_RACE_CONDITION_CHECK)

#endif // #ifndef DRV_ADC_NOT_EXIST
}
/*Specific measure function for BMT*/



void adc_multi_channel_set(DCL_UINT32 adc_sche_id, DCL_MULTI_CHANNEL_PARA_T* pMultiChannelPara)
{
#ifndef DRV_ADC_NOT_EXIST
	static kal_uint8 adc_multi_id=0;

	adc_multi_id++;

	ASSERT(adc_multi_id < 2);	//only for BMT use
	
	adc_multichan_enable[adc_sche_id] =  pMultiChannelPara->bEnable;
	adc_multichan_paramters.max_multi_channel_number = pMultiChannelPara->u4Adc_max_ch_number;
	adc_multichan_paramters.multi_adc_phy_id = pMultiChannelPara->u4ADC_ch_number;
	adc_multichan_paramters.multi_complete = pMultiChannelPara->complete_multi_cb;
#endif
}
/*
* FUNCTION
*	   adc_sche_readback
*
* DESCRIPTION                                                           
*   	This function is to readback the value from ADC channel.
*
* CALLS  
*
* PARAMETERS
*	   adc_sche_id: logical channel id
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
#if defined(__CHARGER_WITH_IMMEDIMATE_ADC__)
static kal_int32 Pre_VOL_RESULT[ADC_MAX_CHANNEL]={0};
static kal_uint16 adc_filter_count[ADC_MAX_CHANNEL]={0};
#define ADC_FILTER_RANGE 300000
#define ADC_FILTER_COUNT 10

kal_bool adc_sche_imm_readback(ADCScheMeasParameter *adc_param, kal_uint16 *data,  kal_uint16 *multi_data)
{
#ifndef DRV_ADC_NOT_EXIST
	kal_int32 volt, diff;

	adc_sche_rw_status |= (1 << adc_param->adc_logic_id);
	if(KAL_TRUE == adc_multichan_enable[adc_param->adc_logic_id])
   	{
   		 kal_uint32 i;
		 
    	 for(i=0;i<adc_multichan_paramters.max_multi_channel_number;i++)
    	 {
			if(adc_multichan_paramters.multi_adc_phy_id[i] >= BMT_ADC_MAX_CHANNEL_TOTAL)
			{
				drv_trace0(TRACE_GROUP_10, BMT_ILLEGAL_PHY_ADC_CHANNEL_TRC);
				*(multi_data + i) = 0;
			}
			else
			{
				*(multi_data + i) = ADC_GetData(adc_multichan_paramters.multi_adc_phy_id[i]);
				volt = (kal_int32)adc_adc2vol(adc_param->adc_phy_id, (double)(*(multi_data + i)));
				
				if(Pre_VOL_RESULT[adc_multichan_paramters.multi_adc_phy_id[i]]==0)
				{
					Pre_VOL_RESULT[adc_multichan_paramters.multi_adc_phy_id[i]]=volt;
				}
				else
				{
					diff=Pre_VOL_RESULT[adc_multichan_paramters.multi_adc_phy_id[i]]-volt;
					if(diff>ADC_FILTER_RANGE||diff<-ADC_FILTER_RANGE)
					{
						adc_filter_count[adc_multichan_paramters.multi_adc_phy_id[i]]++;						
						
						drv_trace4(TRACE_GROUP_10, BMT_ADC_MEASURE_WARNING_TRC, adc_multichan_paramters.multi_adc_phy_id[i], Pre_VOL_RESULT[adc_multichan_paramters.multi_adc_phy_id[i]], volt, 0);
						if(adc_filter_count[adc_multichan_paramters.multi_adc_phy_id[i]]>=ADC_FILTER_COUNT)
							Pre_VOL_RESULT[adc_multichan_paramters.multi_adc_phy_id[i]]=0;
						adc_sche_set_timer(adc_param->adc_logic_id,1,adc_sche_readback);				
#if defined(ADC_RACE_CONDITION_CHECK)
						ADCRCRelease();
#endif // #if defined(ADC_RACE_CONDITION_CHECK)
						return KAL_FALSE;
					}
					adc_filter_count[adc_multichan_paramters.multi_adc_phy_id[i]]=0;								
					Pre_VOL_RESULT[adc_multichan_paramters.multi_adc_phy_id[i]]=volt;
				}
	   
				
			}
    	 }
   	}
   else
   	{
	   //adc_pwrdown_disable();
		if (adc_param->adc_phy_id >= ADC_MAX_CHANNEL){
			// If the phy_id is illegal, we just return 0 and show up warning message
			//kal_prompt_trace(MOD_BMT,"ADC phy id is illegal, return 0 value only", adc_param->adc_phy_id);
			drv_trace0(TRACE_GROUP_10, BMT_ILLEGAL_PHY_ADC_CHANNEL_TRC);
			(*data) = 0;
			volt = 0;
		}else{
	      (*data) = ADC_GetData(adc_param->adc_phy_id);	
	   	volt = (kal_int32)adc_adc2vol(adc_param->adc_phy_id, (double)*data);
	   
		if(Pre_VOL_RESULT[adc_param->adc_phy_id]==0)
		{
			Pre_VOL_RESULT[adc_param->adc_phy_id]=volt;
		}
		else
		{
			diff=Pre_VOL_RESULT[adc_param->adc_phy_id]-volt;
			if(diff>ADC_FILTER_RANGE||diff<-ADC_FILTER_RANGE)
			{
				adc_filter_count[adc_param->adc_phy_id]++;						
				
				//kal_prompt_trace(MOD_BMT,"phy id: %d", adc_param->adc_phy_id);
				//kal_prompt_trace(MOD_BMT,"volt: %d", Pre_VOL_RESULT[adc_param->adc_phy_id]);
				//kal_prompt_trace(MOD_BMT,"curr volt: %d", volt);
				drv_trace4(TRACE_GROUP_10, BMT_ADC_MEASURE_WARNING_TRC, adc_param->adc_phy_id, Pre_VOL_RESULT[adc_param->adc_phy_id], volt, 0);
				if(adc_filter_count[adc_param->adc_phy_id]>=ADC_FILTER_COUNT)
					Pre_VOL_RESULT[adc_param->adc_phy_id]=0;
				adc_sche_set_timer(adc_param->adc_logic_id,1,adc_sche_readback);				
#if defined(ADC_RACE_CONDITION_CHECK)
				ADCRCRelease();
#endif // #if defined(ADC_RACE_CONDITION_CHECK)
				return KAL_FALSE;
			}
			adc_filter_count[adc_param->adc_phy_id]=0;								
			Pre_VOL_RESULT[adc_param->adc_phy_id]=volt;
		}		
		}
   	}
   return KAL_TRUE;
#endif   
}
#endif


void adc_sche_sync_readback(ADCScheMeasParameter *adc_param, kal_uint16 *data,  kal_uint16 *multi_data)
{
#ifndef DRV_ADC_NOT_EXIST
	 if(KAL_TRUE == adc_multichan_enable[adc_param->adc_logic_id])
	  {
	  	 kal_uint32 i;
	 
    	 for(i=0;i<adc_multichan_paramters.max_multi_channel_number;i++)
    	 {

			if(adc_multichan_paramters.multi_adc_phy_id[i] >= BMT_ADC_MAX_CHANNEL_TOTAL)
			{
				drv_trace0(TRACE_GROUP_10, BMT_ILLEGAL_PHY_ADC_CHANNEL_TRC);
				*(multi_data+i) = 0;
			}
			else
			{
		 		 while(DRV_ADC_Reg(AUXADC_SYNC)&(1<<adc_multichan_paramters.multi_adc_phy_id[i]));
         		 *(multi_data+i) = DRV_ADC_Reg(AUXADC_DAT(adc_multichan_paramters.multi_adc_phy_id[i]));
			}
    	 }
	  }
	  else
	  {
	  	   if (adc_param->adc_phy_id >= ADC_MAX_CHANNEL)
		   {
				// If the phy_id is illegal, we just return 0 and show up warning message
				//kal_prompt_trace(MOD_BMT,"ADC phy id is illegal, return 0 value only", adc_param->adc_phy_id);
				drv_trace0(TRACE_GROUP_10, BMT_ILLEGAL_PHY_ADC_CHANNEL_TRC);
				(*data) = 0;
		   }
		   else
		   {
		   		while(DRV_ADC_Reg(AUXADC_SYNC)&(1<<adc_param->adc_phy_id));
		   		(*data) = DRV_ADC_Reg(AUXADC_DAT(adc_param->adc_phy_id));
	  	   }
	   }
#endif	  
}


void adc_sche_accumulate_adc_result(ADCScheMeasParameter *adc_param, kal_uint16 *data,  kal_uint16 *multi_data)
{
#ifndef DRV_ADC_NOT_EXIST
	if (adc_parameters[adc_param->adc_logic_id].conti_measure)
 	{
		if(KAL_TRUE == adc_multichan_enable[adc_param->adc_logic_id])
	    {
	  		 kal_uint32 i;
			 
			 for(i=0;i<adc_multichan_paramters.max_multi_channel_number;i++)
			 {
			 	adc_sche_multi_sum[i] += *(multi_data+i);
			 }	
 		}
	    else
	 	{
 	 	  adc_sche_sum[adc_param->adc_logic_id] += (*data);
	 	}
 	   adc_sche_count[adc_param->adc_logic_id]++;
	  
	  // #if defined(__CHARGER_WITH_IMMEDIMATE_ADC__)
	  //	adc_sche_set_timer(adc_param->adc_logic_id,adc_parameters[adc_param->adc_logic_id].period,adc_sche_readback);
	  // #else
 	   	adc_sche_set_timer(adc_param->adc_logic_id,adc_parameters[adc_param->adc_logic_id].period,adc_sche_measure);
	 //  #endif
	   
 	}
#endif	
}


void adc_sche_calculate_voltage_result(ADCScheMeasParameter *adc_param)
{
#ifndef DRV_ADC_NOT_EXIST
   if(KAL_TRUE == adc_multichan_enable[adc_param->adc_logic_id])
   {
  		kal_uint32 i;

		for(i=0;i<adc_multichan_paramters.max_multi_channel_number;i++)
		{
			ADC_MULTI_RESULT[i] = (double)((double)adc_sche_multi_sum[i]/(double)adc_sche_count[adc_param->adc_logic_id] );
			
 	  		if(adc_multichan_paramters.multi_adc_phy_id[i] >= BMT_ADC_MAX_CHANNEL_TOTAL)
			{
		 	    VOL_MULTI_RESULT[i] = 0;
	 	    }else
	 	    {
	 	   		VOL_MULTI_RESULT[i] = (kal_int32)adc_adc2vol(adc_multichan_paramters.multi_adc_phy_id[i],ADC_MULTI_RESULT[i]);
	 	   	}
		}
	   }
   else
   {
 	   ADC_RESULT[adc_param->adc_logic_id] = (double)((double)adc_sche_sum[adc_param->adc_logic_id]/(double)adc_sche_count[adc_param->adc_logic_id] );
 	   if (adc_param->adc_phy_id >= ADC_MAX_CHANNEL){
 	      VOL_RESULT[adc_param->adc_logic_id] = 0;
 	   }else{
	   VOL_RESULT[adc_param->adc_logic_id] = (kal_int32)adc_adc2vol(adc_param->adc_phy_id,ADC_RESULT[adc_param->adc_logic_id]);
 	   }
   }
#endif   
}

void adc_sche_fixed_vbat(ADCScheMeasParameter *adc_param)
{
#ifndef DRV_ADC_NOT_EXIST
   DCL_HANDLE adc_handle;
   ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_ch;
  
   adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
   if(adc_handle == DCL_HANDLE_INVALID)
   {
      ASSERT(0);   
   }
   adc_ch.u2AdcName = DCL_VBAT_ADC_CHANNEL;
   DclSADC_Control(adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);     
   DclSADC_Close(adc_handle);

	if (adc_param->adc_phy_id == adc_ch.u1AdcPhyCh){
		VOL_RESULT[adc_param->adc_logic_id] = (kal_int32)(3800000);
	}
#endif	
}

#ifndef DRV_ADC_NOT_EXIST
void adc_sche_readback(void* msg_ptr)
{

   #if !defined(ADC_REMOVE_IRQMASK)
   kal_uint32 savedMask;
   #endif //#if !defined(ADC_REMOVE_IRQMASK)
   ADCScheMeasParameter *adc_param = (ADCScheMeasParameter *)msg_ptr;
   kal_uint16 data;
   kal_uint16 multi_data[ADC_MAX_CHANNEL];
  
 
#if defined(ADC_RACE_CONDITION_CHECK)
	ADCRCCheckAndLock();
#endif // #if defined(ADC_RACE_CONDITION_CHECK)

#if defined(DRV_ADC_FULL_FUNC)

   adc_parameters[adc_param->adc_logic_id].adc_sche_event_id = NULL;
   #if defined(__CHARGER_WITH_IMMEDIMATE_ADC__)   
  		if(KAL_FALSE == adc_sche_imm_readback(adc_param, &data, &multi_data[0]))	// return false : ADC value > ADC_FILTER_RANGE
			return;
   #else
		adc_sche_sync_readback(adc_param, &data, &multi_data[0]);	
   #endif
   
   adc_sche_rw_status &= ~(1 << adc_param->adc_logic_id);

   ADCSAVEANDSETIRQMASK(savedMask);	//savedMask = SaveAndSetIRQMask();
#if !defined(DRV_ADC_NO_SYNC_MODE)   
   if ((DRV_ADC_Reg(AUXADC_SYNC)==0) && 
       ((DRV_ADC_Reg(AUXADC_SYN) & AUXADC_SYN_BIT)==0)
      )
#endif //#if defined(DRV_ADC_NO_SYNC_MODE) 
   {
      adc_sync_mode_on = KAL_FALSE;
      if (adc_imm_mode_cnt == 0)
      {
         adc_pwrdown_enable();
      }
   }
   ADCRESTOREIRQMASK(savedMask); //RestoreIRQMask(savedMask);
   ADCSAVEANDSETIRQMASK(savedMask);	//savedMask = SaveAndSetIRQMask();	
   //if ((((volatile kal_uint16)adc_imm_mode_cnt) == 0) && (((volatile kal_bool)adc_sync_mode_on) == KAL_FALSE))  build warning
   if (((adc_imm_mode_cnt) == 0) && ((adc_sync_mode_on) == KAL_FALSE))
   {
      #if !defined(DRV_ADC_MODEM_SIDE)	//don't write pmu bit to 0	
      adcsche_adc_measure_en(KAL_FALSE);
	  #endif
   }
   ADCRESTOREIRQMASK(savedMask); //RestoreIRQMask(savedMask);

   adc_sche_accumulate_adc_result(adc_param, &data,  &multi_data[0]);
#endif      /*DRV_ADC_FULL_FUNC*/
   
 	if (adc_sche_count[adc_param->adc_logic_id] >= adc_parameters[adc_param->adc_logic_id].evaluate_count)
   {
	   adc_sche_calculate_voltage_result(adc_param);

#ifdef DRV_MISC_ADC_FIXED_VBAT_WA 
	   adc_sche_fixed_vbat(adc_param);
#endif // #ifdef DRV_MISC_ADC_FIXED_VBAT_WA
		adc_sche_count[adc_param->adc_logic_id] = 0;
		adc_sche_sum[adc_param->adc_logic_id] = 0;

		if (adc_parameters[adc_param->adc_logic_id].conti_measure == KAL_TRUE)
		{
			adc_sche_callback_send(adc_param);	
		}
			/* VOL_RESULT[adc_sche_id],ADC_RESULT[adc_sche_id] */
 	}

#if defined(ADC_RACE_CONDITION_CHECK)
	ADCRCRelease();
#endif // #if defined(ADC_RACE_CONDITION_CHECK)

}
#endif // #ifndef DRV_ADC_NOT_EXIST

/*
* FUNCTION
*	   adc_sche_create_object
*
* DESCRIPTION                                                           
*   	This function is to create a measure object and 
*  return a logical channel id.
*
* CALLS  
*
* PARAMETERS
*	   msgid: owner id;
*	   adc_channel: ADC channel no.
*	   period: The period of ADC measure.
*	   evaluate_count: Evaluate Count;
*	   send_primitive: Decide whether send primitive
*           (MSG_ID_BMT_ADC_MEASURE_DONE_CONF) to owner task.
*	
* RETURNS
*	   logical channel id.
*
* GLOBALS AFFECTED
*     None
*/
/*return the adc_sche_id*/
kal_uint32 adc_sche_create_object(ADC_CTRL_CREATE_OBJECT_T *prCreateObj)
{
#ifndef DRV_ADC_NOT_EXIST

   kal_uint32 adc_id;
   
	/*lint -e661*/   
   
   adc_id = adc_sche_id_no++;

#if defined(DRV_ADC_MODEM_SIDE)
   if (prCreateObj->u1AdcChannel != adc_sche_get_channel(rftmp_adc_channel))
   {
       return 0xFF;
   }
#endif // #if defined(DRV_ADC_MODEM_SIDE)   

   ASSERT(adc_id < ADC_SCHE_MAX_CHANNEL);
      
   adc_parameters[adc_id].adc_phy_id = prCreateObj->u1AdcChannel;
   adc_parameters[adc_id].adc_logic_id = adc_id;
   adc_parameters[adc_id].ownerid = (module_type)prCreateObj->u1OwnerId;
   adc_parameters[adc_id].period =  prCreateObj->u4Period;
   adc_parameters[adc_id].evaluate_count = prCreateObj->u1EvaluateCount;
   adc_parameters[adc_id].send_primitive = prCreateObj->fgSendPrimitive;
   adc_parameters[adc_id].complete = NULL;
   adc_parameters[adc_id].adc_sche_event_id = 0;
   
   adc_sche_sum[adc_id] = 0;
   adc_sche_count[adc_id] = 0;
   return adc_id;

	/*lint +e661*/
#endif // #ifndef DRV_ADC_NOT_EXIST

#if defined(DRV_ADC_NOT_EXIST)
	return 0;
#endif // #if defined(DRV_ADC_NOT_EXIST)
}

/*
* FUNCTION
*	   adc_sche_modify_parameters
*
* DESCRIPTION                                                           
*   	This function is to modify the parameter of the measure object.
*
* CALLS  
*
* PARAMETERS
*	   adc_sche_id: logical channel id
*	   period: measure period.
*	   evaluate_count: Evaluate Count;
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void adc_sche_modify_parameters(kal_uint32 adc_sche_id, kal_uint32 period, kal_uint8 evaluate_count)
{
#ifndef DRV_ADC_NOT_EXIST

   ASSERT(adc_sche_id < adc_sche_id_no);
   adc_parameters[adc_sche_id].period = period;
   adc_parameters[adc_sche_id].evaluate_count = evaluate_count;

#endif // #ifndef DRV_ADC_NOT_EXIST
}

/*
* FUNCTION
*	   adc_sche_add_item
*
* DESCRIPTION                                                           
*   	This function is to add a measure object to adc scheduler.
*
* CALLS  
*
* PARAMETERS
*	   adc_sche_id: logical channel id
*	   mea_complete: callback when measure complete.
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void adc_sche_add_item(kal_uint32 adc_sche_id, void (*mea_complete)(signed long handle, signed long volt_result, double adc_result), kal_timer_func_ptr mea_Callback)
{
#ifndef DRV_ADC_NOT_EXIST

#if defined(DRV_ADC_MODEM_SIDE)
   if (adc_sche_id == 0xff)
   {
       return;
   }
#endif // #if defined(DRV_ADC_MODEM_SIDE)  

   ASSERT(adc_sche_id < adc_sche_id_no);

	if (adc_reg_status & (1<<adc_sche_id))
	   return;

	if(mea_complete == NULL)
		mea_complete = adc_sche_complete_callback; //default complete callback
	if(mea_Callback == NULL)
		mea_Callback = adc_sche_measure;         //default measure callback

	adc_reg_status |= (1<<adc_sche_id);
	adc_parameters[adc_sche_id].conti_measure = KAL_TRUE;
	adc_parameters[adc_sche_id].complete = mea_complete;
	adc_sche_sum[adc_sche_id] = 0;
   adc_sche_count[adc_sche_id] = 0;
	if(KAL_TRUE == adc_multichan_enable[adc_sche_id])
	{
		kal_uint32 i;
		for(i=0;i<BMT_ADC_MAX_CHANNEL_TOTAL;i++)
		{
			adc_sche_multi_sum[i] = 0;
		}
	}
//#if defined(__CHARGER_WITH_IMMEDIMATE_ADC__)
//   adc_sche_set_timer(adc_sche_id,1,adc_sche_readback);	
//#else
   adc_sche_set_timer(adc_sche_id,1,mea_Callback);
//#endif

#endif // #ifndef DRV_ADC_NOT_EXIST
}

/*
* FUNCTION
*	   adc_sche_remove_item
*
* DESCRIPTION                                                           
*   	This function is to remove a measure object from adc scheduler.
*
* CALLS  
*
* PARAMETERS
*	   adc_sche_id: logical channel id
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void adc_sche_remove_item(kal_uint32 adc_sche_id)
{
#ifndef DRV_ADC_NOT_EXIST
   ASSERT(adc_sche_id < adc_sche_id_no);
   if (adc_reg_status & (1<<adc_sche_id))
   {
      adc_parameters[adc_sche_id].conti_measure = KAL_FALSE;
      adc_reg_status &= ~(1<<adc_sche_id);
      adc_sche_sum[adc_sche_id] = 0;
      adc_sche_count[adc_sche_id] = 0;
	if(KAL_TRUE == adc_multichan_enable[adc_sche_id])
	{
		
		kal_uint32 i;
		for(i=0;i<BMT_ADC_MAX_CHANNEL_TOTAL;i++)
		{
			adc_sche_multi_sum[i]=0;
		}
	}
      adc_sche_rw_status &= ~(1 << adc_parameters[adc_sche_id].adc_logic_id);
      adc_sche_stop_timer(adc_sche_id);
	}

#endif // #ifndef DRV_ADC_NOT_EXIST
}

/*
* FUNCTION
*	   adc_sche_init
*
* DESCRIPTION                                                           
*   	This function is to initialize the adc scheduler.
*
* CALLS  
*
* PARAMETERS
*	   adc_sche_id: logical channel id
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void adc_sche_init(void)
{
#ifndef DRV_ADC_NOT_EXIST

	kal_uint32 index;
#if defined(__SMART_PHONE_MODEM__)
#if defined(DRV_ADC_GET_CHANNEL_NUMBER_FROM_AP)
	kal_uint8 channel_name[] = "ADC_RFTMP";
	kal_uint32 ADC_RFTMP_ChannelNum;
	kal_int32 status;
#endif	
#endif
	
	adc_sche_timer_init();
	for(index=0;index<ADC_SCHE_MAX_CHANNEL;index++)
	{
	   VOL_RESULT[index] = 0x7fffffff;//0xffffffff;
		adc_sche_sum[index] = 0;
		adc_sche_count[index] = 0;
		adc_multichan_enable[index] = 0;
		
	}

	adc_sche_rw_status  = 0;

#if defined(__SMART_PHONE_MODEM__)
#if defined(DRV_ADC_GET_CHANNEL_NUMBER_FROM_AP)
	status = IPC_RPC_ADC_GetChannelNumber(channel_name,sizeof(channel_name), &ADC_RFTMP_ChannelNum);
	
	if(status < 0)
	{	
		char buf[50];
		sprintf(buf,"get rf tmp channel fail:%d",ADC_RFTMP_ChannelNum);
		kal_prompt_trace(MOD_BMT,buf);
		kal_brief_trace(TRACE_ERROR, BMT_ADC_GET_ADC_INFO_TRC,status,ADC_RFTMP_ChannelNum);
	}
	else
	{
		ADC_SP_RFTMP = ADC_RFTMP_ChannelNum;
	}
#endif
#endif
#endif // #ifndef DRV_ADC_NOT_EXIST
}

#if defined(__RTL_SIMULATION_FOR_60QBIT__)
void pmic_adpt_adc_measure_TTT(kal_bool Measure)
{
	// Delay 25 us
}


#include "ebm_if.h"

static EBM_LOG_T adc_ibus_log, adc_dbus_log;
static EBM_LOG_T adc_ibus_log2, adc_dbus_log2;

void bmt_adc_sche_readback_TTT()
{
#ifndef DRV_ADC_NOT_EXIST

   ADCScheMeasParameter adc_meas_param;
   kal_uint32 savedMask;
   ADCScheMeasParameter *adc_param = &adc_meas_param;
   kal_uint16 data;
   #if defined(__CHARGER_WITH_IMMEDIMATE_ADC__)
   kal_int32 volt, diff;
   #endif

	adc_meas_param.adc_logic_id = 0;
	adc_meas_param.adc_phy_id = 0;

#if defined(DRV_ADC_FULL_FUNC)


	// Turn on ADC power
	// Trigger ADC sample (SYNC mode)
	savedMask = SaveAndSetIRQMask();
	adc_sync_mode_on = KAL_TRUE;
	adc_pwrdown_disable();
	DRV_ADC_SetBits(AUXADC_SYNC, (1 << adc_meas_param.adc_phy_id));
	//DRV_ADC_Reg(AUXADC_SYNC) |= (1 << adc_meas_param.adc_phy_id);
	RestoreIRQMask(savedMask);


	if (adc_param->adc_phy_id >= MAX_CHANNEL){
		data = 0;
	}else{
      //while(DRV_ADC_Reg(AUXADC_SYNC)&(1<<adc_param->adc_phy_id));
      //   data = DRV_ADC_Reg(AUXADC_DAT(adc_param->adc_phy_id));
      DRV_ADC_WriteReg(AUXADC_SYNC, 0);
      //DRV_ADC_Reg(AUXADC_SYNC) = 0;
	}


	EBM_INIT();
	EBM_START();

   savedMask = SaveAndSetIRQMask();
   if ((DRV_ADC_Reg(AUXADC_SYNC)==0) && 
       ((DRV_ADC_Reg(AUXADC_SYN) & AUXADC_SYN_BIT)==0)
      )
   {
      adc_sync_mode_on = KAL_FALSE;
      if (adc_imm_mode_cnt == 0)
      {
         adc_pwrdown_enable();
      }
   }
   RestoreIRQMask(savedMask);
   
	EBM_PAUSE();
	EBM_GET_MCU_IBUS_LOG(&adc_ibus_log);
	EBM_GET_MCU_DBUS_LOG(&adc_dbus_log);
	EBM_STOP();

#endif      /*DRV_ADC_FULL_FUNC*/
#endif // #ifndef DRV_ADC_NOT_EXIST
}

void bmt_adc_sche_readback_TTT2()
{
#ifndef DRV_ADC_NOT_EXIST
   kal_uint32 savedMask;

#if defined(DRV_ADC_FULL_FUNC)
	EBM_INIT();
	EBM_START();
   
   savedMask = SaveAndSetIRQMask();
   //if ((((volatile kal_uint16)adc_imm_mode_cnt) == 0) && (((volatile kal_bool)adc_sync_mode_on) == KAL_FALSE)) build warning
   if (((adc_imm_mode_cnt) == 0) && ((adc_sync_mode_on) == KAL_FALSE))
   {
      pmic_adpt_adc_measure_TTT(KAL_FALSE);
   }
   RestoreIRQMask(savedMask);
   
	EBM_PAUSE();
	EBM_GET_MCU_IBUS_LOG(&adc_ibus_log2);
	EBM_GET_MCU_DBUS_LOG(&adc_dbus_log2);
	EBM_STOP();
#endif      /*DRV_ADC_FULL_FUNC*/
#endif // #ifndef DRV_ADC_NOT_EXIST

}
#endif // #if defined(__RTL_SIMULATION_FOR_60QBIT__)

