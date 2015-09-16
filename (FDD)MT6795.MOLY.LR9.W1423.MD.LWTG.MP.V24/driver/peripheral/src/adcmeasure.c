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
 *    adcmeasure.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements the adaption layer for KAL and HW interface.
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
#include    "drv_comm.h"
#include "kal_public_defs.h" //MSBB change #include 	"stack_msgs.h"
#include    "reg_base.h"
#include    "adc_hw.h"
#include    "adc_sw.h"
#include    "adcsche.h"
#include    "bmt_trc.h"
#include    "l1_interface.h"
#include	"drv_msgid.h"
// For RHR ADD Usage
#include "kal_public_defs.h" //MSBB change #include 	"stack_config.h"
#include 	"kal_trace.h"
#include    "adc_channel.h"
#include    "nvram_struct.h"
#include    "nvram_enums.h"
#include    "nvram_data_items.h"
#include    "nvram_interface.h"
#include    "dcl_pmu_sw.h"
#include    "adc_nvram_def.h"

#ifdef __MULTI_BOOT__
#endif   /*__MULTI_BOOT__*/

#include "dcl.h"
#if defined(DRV_ADC_VCHARGE_FACTOR_OVERWRITE)
#include "init.h"
#endif // End of #if defined(DRV_ADC_VCHARGE_FACTOR_OVERWRITE)
#include "kal_general_types.h"
#include "kal_public_api.h"
//#include "kal_internal_api.h"
#include "kal_public_defs.h"
#if defined(DRV_ADC_OFF)
   #if !defined(DRV_ADC_NOT_EXIST)
   #define DRV_ADC_NOT_EXIST
   #endif
#endif


#define ADC_INTERNAL_SRAM
#define ADC_DRVPDN_FAST
const kal_uint8 adc_timer_index=99;

extern void evshed_unset_aligned_timer(void *timer_id);
extern void evshed_set_aligned_timer(void *timer_id, kal_uint8 max_delay);
extern ADCScheMeasParameter adc_parameters[ADC_SCHE_MAX_CHANNEL];



event_scheduler     *adc_sche_event_scheduler_ptr;


VolToTempStruct vol_temp_slope = 
{
	ADC_TEMPV2_FACTOR,
	ADC_TEMPA12_FACTOR,
	ADC_TEMPA23_FACTOR,
	ADC_TEMPM12_FACTOR,
	ADC_TEMPM23_FACTOR,
	ADC_TEMPSCALE_FACTOR
};

adc_customized_struct  adc_customized_para = 
{
	ADC_ISENSE_FACTOR,
	{
		{
#if(ADC_MAX_CHANNEL >= 1)
			ADC_CALIBRATION_SLOPE_CH0
#endif
#if(ADC_MAX_CHANNEL >= 2)
			,ADC_CALIBRATION_SLOPE_CH1
#endif
#if(ADC_MAX_CHANNEL >= 3)
			,ADC_CALIBRATION_SLOPE_CH2  
#endif
#if(ADC_MAX_CHANNEL >= 4)
			,ADC_CALIBRATION_SLOPE_CH3
#endif
#if(ADC_MAX_CHANNEL >= 5)
			,ADC_CALIBRATION_SLOPE_CH4
#endif
#if(ADC_MAX_CHANNEL >= 6)
			,ADC_CALIBRATION_SLOPE_CH5
#endif
#if(ADC_MAX_CHANNEL >= 7)
			,ADC_CALIBRATION_SLOPE_CH6
#endif
#if(ADC_MAX_CHANNEL >= 8)
			,ADC_CALIBRATION_SLOPE_CH7
#endif
#if(ADC_MAX_CHANNEL >= 9)
			,ADC_CALIBRATION_SLOPE_CH8
#endif
#if(ADC_MAX_CHANNEL >= 10)
			,ADC_CALIBRATION_SLOPE_CH9
#endif
#if(ADC_MAX_CHANNEL >= 11)
			,ADC_CALIBRATION_SLOPE_CH10
#endif
#if(ADC_MAX_CHANNEL >= 12)
			,ADC_CALIBRATION_SLOPE_CH11
#endif
#if(ADC_MAX_CHANNEL >= 13)
			,ADC_CALIBRATION_SLOPE_CH12
#endif
#if(ADC_MAX_CHANNEL >= 14)
			,ADC_CALIBRATION_SLOPE_CH13
#endif
#if(ADC_MAX_CHANNEL >= 15)
			,ADC_CALIBRATION_SLOPE_CH14
#endif
#if(ADC_MAX_CHANNEL >= 16)
			,ADC_CALIBRATION_SLOPE_CH15
#endif
#if(ADC_MAX_CHANNEL >= 17)
			,ADC_CALIBRATION_SLOPE_CH16
#endif
#if(ADC_MAX_CHANNEL >= 18)
			,ADC_CALIBRATION_SLOPE_CH17
#endif
#if(ADC_MAX_CHANNEL >= 19)
			,ADC_CALIBRATION_SLOPE_CH18
#endif
#if(ADC_MAX_CHANNEL >= 20)
			,ADC_CALIBRATION_SLOPE_CH19
#endif
		},
		{
#if(ADC_MAX_CHANNEL >= 1)
			ADC_CALIBRATION_OFFSET_CH0
#endif
#if(ADC_MAX_CHANNEL >= 2)
			,ADC_CALIBRATION_OFFSET_CH1
#endif
#if(ADC_MAX_CHANNEL >= 3)
			,ADC_CALIBRATION_OFFSET_CH2
#endif
#if(ADC_MAX_CHANNEL >= 4)
			,ADC_CALIBRATION_OFFSET_CH3
#endif
#if(ADC_MAX_CHANNEL >= 5)
			,ADC_CALIBRATION_OFFSET_CH4
#endif
#if(ADC_MAX_CHANNEL >= 6)
			,ADC_CALIBRATION_OFFSET_CH5
#endif
#if(ADC_MAX_CHANNEL >= 7)
			,ADC_CALIBRATION_OFFSET_CH6
#endif
#if(ADC_MAX_CHANNEL >= 8)
			,ADC_CALIBRATION_OFFSET_CH7
#endif
#if(ADC_MAX_CHANNEL >= 9)
			,ADC_CALIBRATION_OFFSET_CH8
#endif
#if(ADC_MAX_CHANNEL >= 10)
			,ADC_CALIBRATION_OFFSET_CH9
#endif
#if(ADC_MAX_CHANNEL >= 11)
			,ADC_CALIBRATION_OFFSET_CH10
#endif
#if(ADC_MAX_CHANNEL >= 12)
			,ADC_CALIBRATION_OFFSET_CH11
#endif
#if(ADC_MAX_CHANNEL >= 13)
			,ADC_CALIBRATION_OFFSET_CH12
#endif
#if(ADC_MAX_CHANNEL >= 14)
			,ADC_CALIBRATION_OFFSET_CH13
#endif
#if(ADC_MAX_CHANNEL >= 15)
			,ADC_CALIBRATION_OFFSET_CH14
#endif
#if(ADC_MAX_CHANNEL >= 16)
			,ADC_CALIBRATION_OFFSET_CH15
#endif
#if(ADC_MAX_CHANNEL >= 17)
			,ADC_CALIBRATION_OFFSET_CH16
#endif
#if(ADC_MAX_CHANNEL >= 18)
			,ADC_CALIBRATION_OFFSET_CH17
#endif
#if(ADC_MAX_CHANNEL >= 19)
			,ADC_CALIBRATION_OFFSET_CH18
#endif
#if(ADC_MAX_CHANNEL >= 20)
			,ADC_CALIBRATION_OFFSET_CH19
#endif
		}
	},
  /*ratio = adc_volt_factor/100*/
  //const kal_uint16 adc_volt_factor[ADC_MAX_CHANNEL] 
	{
#if(ADC_MAX_CHANNEL >= 1)
			ADC_VOLT_FACTOR_CH0
#endif
#if(ADC_MAX_CHANNEL >= 2)
			,ADC_VOLT_FACTOR_CH1
#endif
#if(ADC_MAX_CHANNEL >= 3)
			,ADC_VOLT_FACTOR_CH2
#endif
#if(ADC_MAX_CHANNEL >= 4)
			,ADC_VOLT_FACTOR_CH3
#endif
#if(ADC_MAX_CHANNEL >= 5)
			,ADC_VOLT_FACTOR_CH4
#endif
#if(ADC_MAX_CHANNEL >= 6)
			,ADC_VOLT_FACTOR_CH5
#endif
#if(ADC_MAX_CHANNEL >= 7)
			,ADC_VOLT_FACTOR_CH6
#endif
#if(ADC_MAX_CHANNEL >= 8)
			,ADC_VOLT_FACTOR_CH7
#endif
#if(ADC_MAX_CHANNEL >= 9)
			,ADC_VOLT_FACTOR_CH8
#endif
#if(ADC_MAX_CHANNEL >= 10)
			,ADC_VOLT_FACTOR_CH9
#endif
#if(ADC_MAX_CHANNEL >= 11)
			,ADC_VOLT_FACTOR_CH10
#endif
#if(ADC_MAX_CHANNEL >= 12)
			,ADC_VOLT_FACTOR_CH11
#endif
#if(ADC_MAX_CHANNEL >= 13)
			,ADC_VOLT_FACTOR_CH12
#endif
#if(ADC_MAX_CHANNEL >= 14)
			,ADC_VOLT_FACTOR_CH13
#endif
#if(ADC_MAX_CHANNEL >= 15)
			,ADC_VOLT_FACTOR_CH14
#endif
#if(ADC_MAX_CHANNEL >= 16)
			,ADC_VOLT_FACTOR_CH15
#endif
#if(ADC_MAX_CHANNEL >= 17)
			,ADC_VOLT_FACTOR_CH16
#endif
#if(ADC_MAX_CHANNEL >= 18)
			,ADC_VOLT_FACTOR_CH17
#endif
#if(ADC_MAX_CHANNEL >= 19)
			,ADC_VOLT_FACTOR_CH18
#endif
#if(ADC_MAX_CHANNEL >= 20)
			,ADC_VOLT_FACTOR_CH19
#endif
	}
};



/*
* FUNCTION
*	   adc_adc2vol
*
* DESCRIPTION                                                           
*   	This function is to translate ADC value to voltage.(uV)
*
* CALLS  
*
* PARAMETERS
*	   chann: ADC channel.
*     adcVoltage: ADC value
*	
* RETURNS
*	   voltage value(uV)
*
* GLOBALS AFFECTED
*     None
*/
kal_int32 adc_adc2vol(kal_uint8 chann,double adcVoltage)
{
#if defined(DRV_ADC_VCHARGE_FACTOR_OVERWRITE)
#define MT6236_E2_ADC_FACTOR_VCHARGER 344 // 351/51*50
#define MT6236_E3_ADC_FACTOR_VCHARGER 473 // 369/39*50
   ECO_VERSION MT6236ChipVersion = MT6236_latest_chip;
#endif
	double result;
    kal_uint16 volt_factor=0;
   
   if(chann >=  ADC_MAX_CHANNEL)
      return 0;
   
   result = (double)((adcVoltage*(double)adc_customized_para.adc_cali_param.ADCSlope[chann])+(double)adc_customized_para.adc_cali_param.ADCOffset[chann]);
#if defined(PMIC_FIXED_3_ADC_CH)

   if (chann == PMIC_ADC_VBAT_CH_NUM)
   {
      volt_factor = PMIC_ADC_FACTOR_VBAT;
   }
   else if (chann == PMIC_ADC_VISENSE_CH_NUM)
   {
      volt_factor = PMIC_ADC_FACTOR_VISENSE;
   }
   else if (chann == PMIC_ADC_VCHARGER_CH_NUM)
   {
#if defined(DRV_ADC_VCHARGE_FACTOR_OVERWRITE)
      MT6236ChipVersion = INT_ecoVersion();
      if(MT6236ChipVersion <= ECO_E2)
      {
          volt_factor = MT6236_E2_ADC_FACTOR_VCHARGER;
      }
      else
      {
          volt_factor = MT6236_E3_ADC_FACTOR_VCHARGER;
      }  
#else
      volt_factor = PMIC_ADC_FACTOR_VCHARGER;
#endif
   }
   else
#endif /* PMIC_FIXED_3_ADC_CH */
   {
      if (chann >= ADC_MAX_CHANNEL){
         volt_factor = 0;
      }else{
         volt_factor = adc_customized_para.adc_volt_factor[chann];
      }
   }
 
#if defined(PMIC_FIXED_3_ADC_CH)
   return (kal_int32)(result/PMIC_ADC_FACTOR_VBAT*volt_factor);
#else
   {
	  DCL_HANDLE adc_handle;
	  ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_ch;
	 // DCL_STATUS status;
		
	  adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
	  if(adc_handle == DCL_HANDLE_INVALID)
	  {
	     ASSERT(0);   
	  }
	  adc_ch.u2AdcName = DCL_VBAT_ADC_CHANNEL;
	  DclSADC_Control(adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);     
	  DclSADC_Close(adc_handle);
   		   	
      return (kal_int32)(result/adc_customized_para.adc_volt_factor[adc_ch.u1AdcPhyCh]*volt_factor);
   }   
#endif //#if defined(PMIC_FIXED_3_ADC_CH)

}

/*
* FUNCTION
*	   adc_measureVoltage
*
* DESCRIPTION                                                           
*   	This function is to measure voltage of specific channel
*
* CALLS  
*     Call this API after Drv_Init_Phase1() -->Drv_Customize_Init() --> Finish adc_customized_para initial
*
* PARAMETERS
*	   chann: ADC channel.
*	
* RETURNS
*	   voltage value(uV)
*
* GLOBALS AFFECTED
*     None
*/
kal_int32 adc_measureVoltage(kal_uint8 chann, double *adc_value)
{
   *adc_value = (double)ADC_GetData(chann);
   return adc_adc2vol(chann, *adc_value);
}

void adc_sche_stop_timer(kal_uint8 adc_sche_id)
{
   #ifdef BMT_DEBUG
   //dbg_printWithTime("stop,%d\r\n",adc_sche_id);
   #endif
   evshed_cancel_event(adc_sche_event_scheduler_ptr,
                           &adc_parameters[adc_sche_id].adc_sche_event_id);
}

void adc_sche_set_timer(kal_uint8 adc_sche_id, kal_uint32 tick, kal_timer_func_ptr call_func)
{
   #ifdef BMT_DEBUG
   //dbg_printWithTime("set,%d, %d\r\n",adc_sche_id,tick);
   #endif
	adc_parameters[adc_sche_id].adc_sche_event_id = evshed_set_event(adc_sche_event_scheduler_ptr,
                                                        (kal_timer_func_ptr)call_func, &adc_parameters[adc_sche_id], tick);
}


/*
* FUNCTION
*	   adc_sche_timer_init
*
* DESCRIPTION                                                           
*   	This function is to initialize the timer of ADC scheduler.
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void adc_sche_timer_init(void)
{

	adc_sche_event_scheduler_ptr = evshed_create("ADC Sche Timer",MOD_BMT,0,255);
	evshed_set_index(adc_sche_event_scheduler_ptr,adc_timer_index);
}

#if (defined(DRV_ADC_FULL_FUNC) || defined(DRV_ADC_TDMA_TIME) )
void adc_tdma_time_setup(kal_uint16 idle_time, kal_uint16 trx_time)
   {
   HW_tdma_auxev_time_setup(trx_time, idle_time);
   }

/*Called in L1D*/
void adc_rach_measure_start(void)
{
}
#endif   /*DRV_ADC_FULL_FUNC*/

/*
* FUNCTION
*	   volt2temp
*
* DESCRIPTION                                                           
*   	This function is to translate voltage to temperatrure
*
* CALLS  
*
* PARAMETERS
*	   voltage(uV)
*	
* RETURNS
*	   temperature(m'C)
*
* GLOBALS AFFECTED
*     None
*/
kal_int32 volt2temp(kal_int32 _volt)
{
   if(_volt>vol_temp_slope.TEMPV2)
           return ((vol_temp_slope.TEMPA12+(_volt*vol_temp_slope.TEMPM12/vol_temp_slope.TEMPSCALE))/1000);
   else
           return ((vol_temp_slope.TEMPA23+(_volt*vol_temp_slope.TEMPM23/vol_temp_slope.TEMPSCALE))/1000);
}	 

/*
* FUNCTION
*	   volt2isense
*
* DESCRIPTION
*   	This function is to translate voltage to isense
*
* CALLS
*
* PARAMETERS
*	   voltage(uV)
*	
* RETURNS
*	   current(uA)
*
* GLOBALS AFFECTED
*     None
*/
kal_int32 volt2isense(kal_int32 _volt)
{
   return (kal_int32)(_volt*adc_customized_para.ADC_ISENSE_RESISTANCE_FACTOR);
}

/*
* FUNCTION
*	   adc_read_efuse_data
*
* DESCRIPTION
*   	This function is to get adc calibration data from EFUSE
*
* CALLS
*
* PARAMETERS
*	   slope: adc calibration slope
*	   offset: adc calibration offset
*	
* RETURNS
*	   KAL_TRUE: read data from efuse.
*
* GLOBALS AFFECTED
*     None
*/
void adc_read_efuse_data(double *slope, double *offset)
{
#if defined(ADC_CPU_TEMP_SENSOR_USE)
	kal_uint32 i;
	kal_uint32 Y_VBG,GE,OE,O_VBG;
	double a,b;

	// step 1
	DRV_ADC_WriteReg32(TS_CON1, 0x0002);
	DRV_ADC_WriteReg32(TS_CON2, 0x0200);

	// step 2 : read Temp sensor
	for(i=0;i<100;i++)
	{
		Y_VBG = ADC_GetData(5);		//  5 : CPU Temp Sensor
	}

	//step3 : read ADC_GE and calculate GE
	 GE = (((DRV_ADC_Reg32(EFUSE_ADC_GE) & EFUSE_ADC_GE_MASK) >> EFUSE_ADC_GE_SHIFT)- 128)*1000000/4096 ;

	//step4 : read ADC_OE and calculate OE
	 OE = ((DRV_ADC_Reg32(EFUSE_ADC_OE) & EFUSE_ADC_OE_MASK) >> EFUSE_ADC_OE_SHIFT)- 128;

	//step5: read O_VGB and calculate O_VBG
	O_VBG = (DRV_ADC_Reg32(EFUSE_O_VBG) & EFUSE_O_VBG_MASK) >> EFUSE_O_VBG_SHIFT;

	//setp6:
	a=1000000+(1000000+GE)*(Y_VBG-OE)/((O_VBG+1800)-OE);
	//b=((efuseB-128)*1000000)/4096;
	b=0;
	
	/* Y = (X/4096-b)*(2.8/a) */
	/* Y = (2.8/4096a)X - (2.8*b/a) */
	
	//slope  = ((2500000/4096)*1000000)/a;
	*slope  = ((25000000/a)*100000)/4096;
	//*offset = (-2500000/a)*b;
	*offset = 0;

#else
	kal_int32 efuseA, efuseB;
	double a,b;
	
	efuseA = (DRV_ADC_Reg32(EFUSE_ADC_A) & EFUSE_ADC_A_MASK) >> EFUSE_ADC_A_SHIFT;
	efuseB = (DRV_ADC_Reg32(EFUSE_ADC_B) & EFUSE_ADC_B_MASK) >> EFUSE_ADC_B_SHIFT;
	drv_trace2(TRACE_GROUP_1, BMT_MSG_ADC_EFUSE_AB, efuseA, efuseB);

#if defined(DRV_ADC_SAMPLE_12bIT)  
	/*(1 - 255/4096) <= a <= (1 + 256/4096)  --> +-5%  */
	/*   (-127/4096) <= b <=     (128/4096)  --> +-3%  */
	
	a=1000000+(((efuseA-256)*1000000)/4096);
	b=((efuseB-128)*1000000)/4096;
	
	/* Y = (X/4096-b)*(2.8/a) */
	/* Y = (2.8/4096a)X - (2.8*b/a) */
	
	//slope  = ((2800000/4096)*1000000)/a;
	*slope  = ((28000000/a)*100000)/4096;
	*offset = (-2800000/a)*b;
#else
	/*(1 - 63/1024) <= a <= (1 + 62/1024)  --> +-5%  */
	/*   (-31/1024) <= b <=     (31/1024)  --> +-3%  */
	
	a=1000000+(((efuseA-64)*1000000)/1024);
	b=((efuseB-32)*1000000)/1024;
	
	/* Y = (X/1024-b)*(2.8/a) */
	/* Y = (2.8/1024a)X - (2.8*b/a) */
	
	//slope  = ((2800000/1024)*1000000)/a;
	*slope  = ((28000000/a)*100000)/1024;
	*offset = (-2800000/a)*b;
#endif 
	drv_trace2(TRACE_GROUP_1, BMT_MSG_ADC_EFUSE_SLOPE_OFFSET, a, b);
	drv_trace2(TRACE_GROUP_1, BMT_MSG_ADC_EFUSE_ADC_SLOPE_OFFSET, *slope, *offset);
#endif	
}

/*
* FUNCTION
*	   adc_read_calibration_data
*
* DESCRIPTION
*   	This function is to get adc calibration data from EFUSE
*
* CALLS
*
* PARAMETERS
*	   adc_cali: adc calibration struct which used for saved ADC EFUSE calibration data
*	
* RETURNS
*	   KAL_TRUE: read data from efuse.
*
* GLOBALS AFFECTED
*     None
*/
kal_bool adc_read_calibration_data(ADC_CALIDATA *adc_cali)
{
#if defined(DRV_ADC_CALIBRATION_EFUSE)
   kal_int32 i;
   double slope,offset;
   
   if (DRV_ADC_Reg32(EFUSE_ADC_BASE) & EFUSE_ADC_ENABLE)
   {
      adc_read_efuse_data(&slope, &offset);
      for (i=0;i<ADC_MAX_CHANNEL;i++) //all channel use the same calibration value
      {
         adc_cali->ADCSlope[i]  = (double)slope * (100/50);  
         adc_cali->ADCOffset[i] = (double)offset * (100/50);
      }
      return KAL_TRUE;
   }
#endif //#if defined(DRV_ADC_CALIBRATION_EFUSE)
   return KAL_FALSE;
}

/*
* FUNCTION
*	   adc_set_adc_calibration_data
*
* DESCRIPTION                                                           
*   	This function is to set adc calibration data from NVRAM
*
* CALLS  
*
* PARAMETERS
*	   lim_ptr: adc calibration data, send from NVRAM
*	
* RETURNS
*	   void
*
* GLOBALS AFFECTED
*     None
*/
void adc_set_adc_calibration_data(ilm_struct *lim_ptr)
{
#if ( (!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL)) )
   kal_uint16     len;
   nvram_read_cnf_struct *parm_ptr = (nvram_read_cnf_struct *) lim_ptr->local_para_ptr;
   ADC_CALIDATA *pdu_ptr = (ADC_CALIDATA *)get_peer_buff_pdu(lim_ptr->peer_buff_ptr, &len);
   
#if defined(DRV_ADC_CALIBRATION_EFUSE)
   
   if (DRV_ADC_Reg32(EFUSE_ADC_BASE) & EFUSE_ADC_ENABLE)
   {
      adc_read_calibration_data(pdu_ptr);
      kal_mem_cpy( &adc_customized_para.adc_cali_param, pdu_ptr, sizeof(ADC_CALIDATA) );
      drv_trace2(TRACE_GROUP_1, BMT_MSG_ADC_EFUSE_ADC_SLOPE_OFFSET, adc_customized_para.adc_cali_param.ADCSlope[0], adc_customized_para.adc_cali_param.ADCOffset[0]);
   }
   else
#endif //#if defined(DRV_ADC_CALIBRATION_EFUSE)
   {
      if( ((nvram_errno_enum)parm_ptr->result == NVRAM_IO_ERRNO_OK) || ((nvram_errno_enum)parm_ptr->result == NVRAM_IO_ERRNO_INIT) )
      {
         if( parm_ptr->length != sizeof(ADC_CALIDATA) )
{
            ASSERT(0);
         }
         kal_mem_cpy( &adc_customized_para.adc_cali_param, pdu_ptr, sizeof(ADC_CALIDATA) );
         drv_trace2(TRACE_GROUP_1, BMT_MSG_ADC_NVRAM_SLOPE_OFFSET, adc_customized_para.adc_cali_param.ADCSlope[0], adc_customized_para.adc_cali_param.ADCOffset[0]);
      }
   else
      {
         ASSERT(0);
      }
   }
#endif  // #if ( (!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL)) )
	if(adc_customized_para.adc_cali_param.ADCSlope[0] == ADC_CALIBRATION_SLOPE_CH0 && adc_customized_para.adc_cali_param.ADCOffset[0]== ADC_CALIBRATION_OFFSET_CH0)
	{
		kal_brief_trace( TRACE_STATE, BMT_ADC_NO_CALIBRATION_TRC, adc_customized_para.adc_cali_param.ADCSlope[0], adc_customized_para.adc_cali_param.ADCOffset[0]);
	}

}

/*
* FUNCTION
*	   adc_read_calibration_data_inform
*
* DESCRIPTION
*   	This function is to set adc calibration data from NVRAM
*
* CALLS
*
* PARAMETERS
*	   lim_ptr: adc calibration data, send from NVRAM
*	
* RETURNS
*	   void
*
* GLOBALS AFFECTED
*     None
*/
void adc_read_calibration_data_inform(void)
{
#ifdef __USB_ENABLE__   
#ifndef __MEUT__ // UDVT option, When defined, this is basic load, do NOT need to access NVRAM (No NVRAM)
   extern boot_mode_type Drv_query_boot_mode(void);
   ADC_CALIDATA   pdu_ptr;
   ADC_CALIDATA   *adc_cali;
   kal_bool       result;   
   ilm_struct     ADC_CALI_ilm_local;
   ilm_struct     *ADC_CALI_ilm = &ADC_CALI_ilm_local;

   if(Drv_query_boot_mode()==USBMS_BOOT)
   {               
      result=nvram_external_read_data(NVRAM_EF_ADC_LID,1,(kal_uint8*) &pdu_ptr, sizeof(ADC_CALIDATA));            
      if(result==KAL_FALSE)
      {
         ASSERT(0);
}	 
      adc_read_calibration_data(&pdu_ptr);
      adc_cali=(ADC_CALIDATA *)&pdu_ptr;
      kal_mem_cpy( &adc_customized_para.adc_cali_param, adc_cali, sizeof(ADC_CALIDATA) );            
	  
	  if(adc_customized_para.adc_cali_param.ADCSlope[0] == ADC_CALIBRATION_SLOPE_CH0 && adc_customized_para.adc_cali_param.ADCOffset[0]== ADC_CALIBRATION_OFFSET_CH0)
		  {
			  kal_brief_trace( TRACE_STATE, BMT_ADC_NO_CALIBRATION_TRC, adc_customized_para.adc_cali_param.ADCSlope[0], adc_customized_para.adc_cali_param.ADCOffset[0]);
		  }
	  
      DRV_BuildPrimitive(ADC_CALI_ilm,
         MOD_BMT,
         MOD_USB,
         MSG_ID_BMT_USB_READ_CALI_DONE_IND,
         NULL);

      msg_send(ADC_CALI_ilm);
   }   
#endif // #ifndef __MEUT__ // UDVT option, When defined, this is basic load, do NOT need to access NVRAM (No NVRAM)
#endif // #ifdef __USB_ENABLE__
}

