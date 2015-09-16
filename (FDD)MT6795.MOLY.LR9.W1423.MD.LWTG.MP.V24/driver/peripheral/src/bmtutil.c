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
 *    bmtutil.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements the interface between BMT and ADC scheduler.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include    "drv_comm.h"
#include    "bmt.h"
#include	"bmt_trc.h"
// For RHR ADD Usage
#include "kal_public_defs.h" //MSBB change #include	"stack_config.h"
#include	"drvpdn.h"
#include	"kal_trace.h"
#include    "chr_parameter.h"
#include    "bmt_sw.h"
#include    "dcl.h"
#include    "kal_general_types.h"
#include    "kal_public_api.h"
#include    "multiboot_config.h"
#include    "adc_sw.h"
#include    "adcsche.h"
#include "l1sm_public.h"

PFN_DCLSADC_COMPLETE_CALLBACK  bmt_measure_complete1[BMT_ADC_MAX_CHANNEL_TOTAL];   //Drop one sample
kal_uint8  bmt_adc_handle;
kal_uint8  bmt_bmtid_adc_handle[BMT_ADC_MAX_CHANNEL_TOTAL];
static double BMT_ADC_RESULT[BMT_ADC_MAX_CHANNEL_TOTAL];
static kal_int32 BMT_VOL_RESULT[BMT_ADC_MAX_CHANNEL_TOTAL];
kal_uint8  bmt_multi_channel[BMT_ADC_MAX_CHANNEL_TOTAL];


#ifdef MTK_SLEEP_ENABLE
static kal_uint8 bmt_sm_handle;
#endif
extern void bmt_stop_timer_init(void);
#ifdef __BMT_CHARGE_GUARD_TIME__
extern void bmt_guardtimer_init(void);
#endif
#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)
extern void bmt_estimativetimer_init(void);
#endif //#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)

extern void bmt_measure_done(void);
extern void bmt_stop_stoptimer(void);
extern kal_bool USB_GetCableStatus(void);
extern BMTStruct BMT;

//extern const kal_uint32 bmt_measure_discard_time;
extern kal_uint8 SaftyTimer_Flag; 
extern kal_uint8 low_charger_count;
extern kal_uint8 low_current_count;
extern kal_uint8 low_temper_count;
extern kal_uint8 over_temper_count;
extern kal_uint32 VBAT_OFF;
extern double ADCBAT_OFF;

extern DCL_HANDLE bmt_PmuHandler;

#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
extern kal_uint32 bmt_high_vchg_current;
extern kal_bool First_Time_Charge_Enable;
#endif


void bmt_charge_enable_wdt(kal_bool enable);

#if defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__)
extern kal_int32 g_battery_pre_voltage;
#endif //defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__)

stack_timer_struct      stopcharge_timer;
stack_timer_struct      *timer_stopcharge;
stack_timer_struct      ChargeTimeout_timer;
#ifdef __BMT_CHARGE_GUARD_TIME__
stack_timer_struct      guardcharge_timer;
stack_timer_struct      *timer_guardcharge;
#endif
#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)
stack_timer_struct      estimative_timer;
stack_timer_struct      *timer_estimative;
#endif

extern kal_int32 adc_measureVoltage(kal_uint8 chann, double *adc_value);
/*
* FUNCTION
*	   BMT_Current_Voltage
*
* DESCRIPTION                                                           
*   	This function is used to obtain the Battery voltage of specific channel
*
* CALLS  
*
* PARAMETERS
*	   ch: specific channel
*	   voltage: pointer for read the voltage
*	
* RETURNS
*	   KAL_FALSE: invalid channel
*	   KAL_TRUE:  finish the measurement
*
* GLOBALS AFFECTED
*     None
*/
kal_bool BMT_Current_Voltage(DCL_ADC_CHANNEL_TYPE_ENUM ch, kal_uint32 *voltage, double *adc_value)
{
	kal_uint8 adc_channel;
   	DCL_HANDLE adc_handle;
   	ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_ch;

	if(ch > DCL_VCHARGER_ADC_CHANNEL)
		return KAL_FALSE;  
   
   	adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
   	if(adc_handle == DCL_HANDLE_INVALID)
   	{
    	ASSERT(0);   
   	}
   	adc_ch.u2AdcName = ch;
   	DclSADC_Control(adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);     

	adc_channel = adc_ch.u1AdcPhyCh;
	*voltage = adc_measureVoltage(adc_channel, adc_value);
    DclSADC_Close(adc_handle);
	return KAL_TRUE;
}


/*
* FUNCTION
*	   bmt_timer_config
*
* DESCRIPTION                                                           
*   	This function is to configure the measure timer
*
* CALLS  
*
* PARAMETERS
*	   time: on/off time interval. (1 tick = 4.615ms)
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void bmt_timer_config(kal_uint32 time) /*time unit is second*/
{
   kal_uint32  adc_bmt_tick;
   DCL_STATUS adc_status;
  
   ADC_CTRL_MODIFY_PARAM_T adc_para;   	
   
#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
   if(bmt_frequently_check_on_state() || bmt_frequently_check_off_state())
#else
   if(bmt_frequently_check_on_state())
#endif // End of #if defined(DRV_BMT_HW_PRECC_WORKAROUND)
   {
      time = 45; // 200ms/4.615 ~= 45 frames
   }
#endif //#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
	adc_bmt_tick = (kal_uint32)(time/BMT_EVALUATE_VALUE);
	adc_bmt_tick++;
	
 	adc_para.u4Period = adc_bmt_tick;
	adc_para.u1EvaluateCount = BMT_EVALUATE_VALUE;

	adc_status = DclSADC_Control(bmt_adc_handle, ADC_CMD_MODIFY_PARAM, (DCL_CTRL_DATA_T *)&adc_para);
	if(adc_status != STATUS_OK)
	{
		ASSERT(0);
	}
	
	adc_status = DclSADC_Control(bmt_adc_handle, ADC_CMD_START_MEASURE, NULL);
	if(adc_status != STATUS_OK)
	{
		ASSERT(0);  		
	}				   

}


/*
* FUNCTION
*	   bmt_measure_complete
*
* DESCRIPTION                                                           
*   	This function is the callback function when vbat is measured done.
*
* CALLS  
*
* PARAMETERS
*	   handle: logical channel id.
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void bmt_measure_complete(DCL_INT32 handle, DCL_INT32 *volt_array_result, DCL_DOUBLE *adc_array_result)
{
   	#ifdef BMT_DEBUG
      //dbg_printWithTime("bmt_measure_complete_vbat\r\n");	
	#endif
	DCL_STATUS adc_status;
	kal_uint32 i;
		
	adc_status = DclSADC_Control(handle, ADC_CMD_STOP_MEASURE, NULL);
	if(adc_status != STATUS_OK)
	{
		ASSERT(0);
	}   

	for(i=0;i<BMT_ADC_MAX_CHANNEL_TOTAL;i++)
	{
		BMT_VOL_RESULT[i] = *(volt_array_result+i);
		BMT_ADC_RESULT[i] = *(adc_array_result+i);
	}

	bmt_measure_done();
}


/*
* FUNCTION
*	   bmt_adc_init
*
* DESCRIPTION                                                           
*   	This function is the charge initial function
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
/*if add more measure parameters, just need modify bmt_adc_init*/
void bmt_adc_init(void)
{
   ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_ch;
   ADC_CTRL_CREATE_OBJECT_T adc_create;   
   DCL_STATUS adc_status;
   ADC_CTRL_REGISTER_MEASURE_CB_T registerMeasCB;
   DCL_MULTI_CHANNEL_PARA_T adc_multi_channel_para;
	
   #ifdef MTK_SLEEP_ENABLE
   bmt_sm_handle = L1SM_GetHandle();
   #endif
   bmt_stop_timer_init();
#ifdef __BMT_CHARGE_GUARD_TIME__
   bmt_guardtimer_init();
#endif
#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)
		bmt_estimativetimer_init();
#endif //#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)

   BMT.VBAT_UEM = VBAT_UEM_CHR_OUT;
   /*to get customized ADC channel*/

  
   bmt_adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
   if(bmt_adc_handle == DCL_HANDLE_INVALID)
   {
      ASSERT(0);   
   }

   adc_ch.u2AdcName = DCL_VBAT_ADC_CHANNEL;
   DclSADC_Control(bmt_adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);       
   bmt_multi_channel[BMT_ADC_VBAT] = adc_ch.u1AdcPhyCh;


   adc_ch.u2AdcName = DCL_VISENSE_ADC_CHANNEL;
   DclSADC_Control(bmt_adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);    
   bmt_multi_channel[BMT_ADC_VISENSE] = adc_ch.u1AdcPhyCh;	


   adc_ch.u2AdcName = DCL_VBATTMP_ADC_CHANNEL;
   DclSADC_Control(bmt_adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);      
   bmt_multi_channel[BMT_ADC_VBATTMP] = adc_ch.u1AdcPhyCh;	   


   adc_ch.u2AdcName = DCL_VCHARGER_ADC_CHANNEL;
   DclSADC_Control(bmt_adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);      
   bmt_multi_channel[BMT_ADC_VCHARGER] = adc_ch.u1AdcPhyCh;	

   adc_create.u4Period = 10; // Measurement period (Uint is in Tick)
   adc_create.u1OwnerId = MOD_BMT; // Indicate the module to for ADC driver to notify the result
   //adc_create.u1AdcChannel = ADC_VBAT_channel; // To be measured physical ADC channel
   adc_create.u1EvaluateCount = BMT_EVALUATE_VALUE; // Measurement count
   adc_create.fgSendPrimitive = KAL_FALSE; // Whether to send message to owner module or NOT
   adc_status = DclSADC_Control(bmt_adc_handle, ADC_CMD_CREATE_OBJECT, (DCL_CTRL_DATA_T *)&adc_create);
   if(adc_status != STATUS_OK)
   {
		ASSERT(0);   
   }
 
   registerMeasCB.pfMeasure_cb = adc_sche_measure;	
   adc_status = DclSADC_Control(bmt_adc_handle, ADC_CMD_REGISTER_MEASURE_CB, (DCL_CTRL_DATA_T *)&registerMeasCB);	
   if(adc_status != STATUS_OK)
   {
	   ASSERT(0);
   }	   

   adc_multi_channel_para.bEnable = KAL_TRUE;
   adc_multi_channel_para.u4ADC_ch_number = bmt_multi_channel;
   adc_multi_channel_para.u4Adc_max_ch_number = BMT_ADC_MAX_CHANNEL_TOTAL;
   adc_multi_channel_para.complete_multi_cb = bmt_measure_complete;
   adc_status = DclSADC_Control(bmt_adc_handle, ADC_CMD_SET_MULTI_CHANNEL_READ, (DCL_CTRL_DATA_T *)&adc_multi_channel_para);
   if(adc_status != STATUS_OK)
   {
	  ASSERT(0);  		
   }

}

/*
* FUNCTION
*	   bmt_charge_start
*
* DESCRIPTION                                                           
*   	This function is to start charging algorithm.
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
void bmt_charge_start(void)
{
#if defined(__EVB__) && defined(__MTK_INTERNAL__)
   return;
#elif defined(__DRV_BMT_NO_CHARGING__)
   return;
#else //#if defined(__EVB__)
   
#if defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__)
	double adc;
#endif //#if defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__)
    DCL_STATUS adc_status;
   // ADC_CTRL_REGISTER_MEASURE_CB_T registerMeasCB;	
   
	ADC_CTRL_MODIFY_PARAM_T adc_para;   
#if defined(MT6236)
   
  	PMU_CTRL_CHR_SET_CHR_CURRENT set_chr_current;
#endif

   BMT_Charge(KAL_FALSE);
   BMT.pmictrl_state = PMIC_CHARGEOFF;
#if defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__)
	if(g_battery_pre_voltage == 0)
	  BMT_Current_Voltage(DCL_VBAT_ADC_CHANNEL, &g_battery_pre_voltage,&adc);
	BMT.bat_state = CHR_PRE_FULL_CHECK;
#else //defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__)
   BMT.bat_state = CHR_PRE;
#endif //defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__)
   BMT.VBAT_UEM= VBAT_UEM_CHR_IN_FISRT;
   low_charger_count = 0;
   low_current_count = 0;
   low_temper_count = 0;
   over_temper_count = 0;
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
    SW_Workaround_Flag = KAL_TRUE;
    HW_Plug_Status = bmt_chr_uninit; 
    Manual_Disable_Charge_Flag = KAL_FALSE;
#endif
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
   First_Time_Charge_Enable = KAL_TRUE;
   bmt_high_vchg_current = 0xFFFFFFF;
   Pre_VCharge_AVG = 0;
   Cur_VCharge_MAX = 0;
#endif

   
   #ifdef MTK_SLEEP_ENABLE
   L1SM_SleepDisable(bmt_sm_handle);
   #endif
		

      adc_para.u4Period = 1;
	  adc_para.u1EvaluateCount = 1;
	  adc_status = DclSADC_Control(bmt_adc_handle, ADC_CMD_MODIFY_PARAM, (DCL_CTRL_DATA_T *)&adc_para);
	  if(adc_status != STATUS_OK)
	  {
			ASSERT(0);
	  }   	
	 
	  adc_status = DclSADC_Control(bmt_adc_handle, ADC_CMD_START_MEASURE, NULL);
	  if(adc_status != STATUS_OK)
	  {
			ASSERT(0);  		
	  }	      
	
#ifdef __BMT_CHARGE_GUARD_TIME__
	bmt_set_guardtimer(KAL_TICKS_1_MIN*BMT_CHARGE_GUARD_TIME_PERIOD);
	drv_trace2(TRACE_GROUP_10, BMT_SAFETY_AND_GUARD_TIMER_START_TRC, BMT_TOTAL_CHARGE_TIME, BMT_CHARGE_GUARD_TIME_PERIOD);
#else // __BMT_CHARGE_GUARD_TIME__

#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
    bmt_safety_timer_config = KAL_FALSE;
#else
	stack_start_timer(&ChargeTimeout_timer, 0, KAL_TICKS_1_MIN*BMT_TOTAL_CHARGE_TIME);
	drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_START_TRC, BMT_TOTAL_CHARGE_TIME);
	SaftyTimer_Flag = BMT_SAFETY_TIMER_ON; 
#endif //#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)

#endif // __BMT_CHARGE_GUARD_TIME__
	
   

#if defined(MT6236)  
    
    set_chr_current.current = PMU_CHARGE_CURRENT_200_00_MA; // Pre-CC 200mA
    DclPMU_Control(bmt_PmuHandler, CHR_SET_CHR_CURRENT, (DCL_CTRL_DATA_T *)&set_chr_current);
                  
#else   
   bmt_set_chr_current();
#endif
   
   #if defined(PMIC_CHARGE_WDT)  // Defined in pmic_features.h
   bmt_charge_enable_wdt(KAL_TRUE);
   #endif // #if defined(PMIC_CHARGE_WDT)
   
   drv_trace0(TRACE_GROUP_10, BMT_CHARGING_START_TRC);
#endif//#if defined(__EVB__)
}

/*
* FUNCTION
*	   bmt_charge_end
*
* DESCRIPTION                                                           
*   	This function is to stop charging when charger is plugged out 
*     or serious error in charging stage.
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
void bmt_charge_end(void)
{
#if defined(__EVB__) && defined(__MTK_INTERNAL__)
	return;
#elif defined(__DRV_BMT_NO_CHARGING__)
   return;
#else//#if defined(__EVB__)

    DCL_STATUS adc_status;

#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
	bmt_chr_force_enable(KAL_FALSE);
#endif
	BMT.pmictrl_state = PMIC_CHARGEOFF;
   	BMT.VBAT_UEM= VBAT_UEM_CHR_OUT_FIRST;
	BMT_Charge(KAL_FALSE);
		adc_status = DclSADC_Control(bmt_adc_handle, ADC_CMD_STOP_MEASURE, NULL);
		if(adc_status != STATUS_OK)
		{
			ASSERT(0);
		}

	bmt_stop_stoptimer();
	stack_stop_timer(&ChargeTimeout_timer);
#ifdef __BMT_CHARGE_GUARD_TIME__
	bmt_stop_guardtimer();
#endif
#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)
	bmt_stop_estimativetimer();
#endif //#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)
	drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, BMT_TOTAL_CHARGE_TIME);
   SaftyTimer_Flag = BMT_SAFETY_TIMER_OFF; 
   #ifdef MTK_SLEEP_ENABLE
   L1SM_SleepEnable(bmt_sm_handle);
   #endif
   
   #if defined(PMIC_CHARGE_WDT)  // Defined in pmic_features.h
   bmt_charge_enable_wdt(KAL_FALSE);
   #endif // #if defined(PMIC_CHARGE_WDT)
   
   drv_trace0(TRACE_GROUP_10, BMT_CHARGING_END_TRC);
 //  DclSADC_Close(adc_handle);
#endif//#if defined(__EVB__)
}

/*
* FUNCTION
*      bmt_charge_clear_wdt
*
* DESCRIPTION
*      Clear charge WDT (Registered as gpt callback function)
*
* PARAMETERS
*      parameter: Not used
*      
*/
#define BMT_CHARGE_CLEAR_WDT_PERIOD				200	// in (10ms) unit, 200 means 2 sec
DCL_HANDLE bmt_wdt_handle = 0xFF;
void bmt_charge_clear_wdt(void *parameter)
{
	
	DCL_STATUS status;
	SGPT_CTRL_START_T start;

   

	// Clear charge WDT
	drv_trace0(TRACE_GROUP_10, BMT_CHARGING_WDT_CLR_TRC);
	DclPMU_Control(bmt_PmuHandler, CHR_SET_WDT_CLEAR, NULL);	
	   

	if (bmt_wdt_handle != 0xFF)
	{
		start.u2Tick=BMT_CHARGE_CLEAR_WDT_PERIOD;
		start.pfCallback=bmt_charge_clear_wdt;
		start.vPara=NULL;
		//this is for handle type transfer between new and old API.
		status = DclSGPT_Control(bmt_wdt_handle, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
        
        if(status != STATUS_OK)
        {
        	ASSERT(0);  		
        }  	        
	}
}


/*
* FUNCTION
*      bmt_charge_enable_wdt
*
* DESCRIPTION
*      Enable/disable charging wdt functionality for safety
*
* PARAMETERS
*      KAL_TRUE: Enable charging WDT
*      KAL_TRUE: Disable charging WDT
*
*/
void bmt_charge_enable_wdt(kal_bool enable)
{
	// Don't need IRQMask protection, 
	// bmt_charge_start(), bmt_charge_end() are called in task level
	DCL_STATUS status;
	SGPT_CTRL_START_T start;

	if (enable)
	{
		if (bmt_wdt_handle == 0xFF)
		{
			bmt_wdt_handle = DclSGPT_Open(DCL_GPT_CB,0);

	        start.u2Tick = BMT_CHARGE_CLEAR_WDT_PERIOD;
	        start.pfCallback = bmt_charge_clear_wdt;
	        start.vPara = NULL;
			//this is for handle type transfer between new and old API.
			status = DclSGPT_Control(bmt_wdt_handle, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
            
            if(status != STATUS_OK)
            {
            	ASSERT(0);  		
            }  	             
		}
	}
	else
	{
		if (bmt_wdt_handle != 0xFF)
		{
		 	DclSGPT_Control(bmt_wdt_handle, SGPT_CMD_STOP, 0);
			DclSGPT_Close(&bmt_wdt_handle);
		}
		bmt_wdt_handle = 0xFF;
	}
}


/*
* FUNCTION
*	   bmt_IsUSBorCharger
*
* DESCRIPTION                                                           
*   	It tells whether the a AC charger or a USB cable  plugged in. 
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
#ifdef __USB_ENABLE__

bmt_usb_charger_enum bmt_IsUSBorCharger(void)
{

	#if defined(__DRV_EXT_CHARGER_DETECTION__)
	charger_usb_present_enum present;
	present = ext_charger_det->det_charger_present();
	if (present == NO_PRESENT)
	{
		ASSERT(0); // Don't know what value to return!!
	}
	else if (present == USB_PRESENT)
	{
		return BMT_USB_IN;
	}
	else
	{
		return BMT_AC_IN;
	}
	#endif // #if defined(__DRV_EXT_CHARGER_DETECTION__)


	#if (!defined(__DRV_EXT_CHARGER_DETECTION__))
	kal_bool isUSB;

	#if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	isUSB = USB_GetCableStatus();
	#else
	//isUSB = (chr_usb_detect.chr_usb_present == USB_PRESENT);
	isUSB = (chr_usb_detect.chr_usb_present == USB_PRESENT)?KAL_TRUE:KAL_FALSE;
	#endif
	
	return (isUSB)?BMT_USB_IN:BMT_AC_IN; 

	#endif // #if (!defined(__DRV_EXT_CHARGER_DETECTION__))

}
#endif

/*
* FUNCTION
*	   bmt_stop_timer_init
*
* DESCRIPTION
*   	This function is to stop the bmt_stop timer in bmt task.
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
/*charge mode*/
void bmt_stop_timer_init(void)
{
   timer_stopcharge = &stopcharge_timer;
   stack_init_timer(timer_stopcharge, "chrstop_timer", MOD_BMT);
}

/*
* FUNCTION
*	   bmt_stop_timer_init
*
* DESCRIPTION                                                           
*   	This function is to initialize the bmt_stop timer in bmt task.
*
* CALLS  
*
* PARAMETERS
*	   tick: timer tick(1 tick=4.615ms)
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void bmt_set_stoptimer(kal_uint32 tick)
{
   #ifdef BMT_KAL_DEBUG   
	   kal_trace(TRACE_FUNC, BMT_STOP_TIMER_START_TRC);
   #endif	
	drv_trace0(TRACE_GROUP_10, BMT_STOP_TIMER_START_TRC);
	stack_start_timer(timer_stopcharge, 0, tick);
}

#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)
void bmt_estimativetimer_init(void)
{
   timer_estimative = &estimative_timer;
   stack_init_timer(timer_estimative, "estimative_timer", MOD_BMT);
}

/*
* FUNCTION
*	   bmt_set_estimativetimer
*
* DESCRIPTION                                                           
*   	This function is to initialize the bmt_stop timer in bmt task.
*
* CALLS  
*
* PARAMETERS
*	   tick: timer tick(1 tick=4.615ms)
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void bmt_set_estimativetimer(kal_uint32 tick)
{
	drv_trace0(TRACE_GROUP_10, BMT_STOP_TIMER_START_TRC);
	stack_start_timer(timer_estimative, 0, tick);
}
/*
* FUNCTION
*	   bmt_stop_estimativetimer
*
* DESCRIPTION                                                           
*   	This function is to stop the bmt_stop timer in bmt task.
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
void bmt_stop_estimativetimer(void)
{
	drv_trace0(TRACE_GROUP_10, BMT_STOP_TIMER_STOP_TRC);
	stack_stop_timer(timer_estimative);
}
#endif //#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)

#ifdef __BMT_CHARGE_GUARD_TIME__ 
void bmt_guardtimer_init(void)
{
   timer_guardcharge = &guardcharge_timer;
   stack_init_timer(timer_guardcharge, "guardtime_timer", MOD_BMT);
}

/*
* FUNCTION
*	   bmt_set_guardtimer
*
* DESCRIPTION                                                           
*   	This function is to initialize the bmt_stop timer in bmt task.
*
* CALLS  
*
* PARAMETERS
*	   tick: timer tick(1 tick=4.615ms)
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void bmt_set_guardtimer(kal_uint32 tick)
{
   #ifdef BMT_KAL_DEBUG   
	   kal_trace(TRACE_FUNC, BMT_STOP_TIMER_START_TRC);
   #endif	
	drv_trace0(TRACE_GROUP_10, BMT_STOP_TIMER_START_TRC);
	stack_start_timer(timer_guardcharge, 0, tick);
}
/*
* FUNCTION
*	   bmt_stop_guardtimer
*
* DESCRIPTION                                                           
*   	This function is to stop the bmt_stop timer in bmt task.
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
void bmt_stop_guardtimer(void)
{
   #ifdef BMT_KAL_DEBUG    
   	kal_trace(TRACE_FUNC, BMT_STOP_TIMER_STOP_TRC);
   #endif 	
	drv_trace0(TRACE_GROUP_10, BMT_STOP_TIMER_STOP_TRC);
	stack_stop_timer(timer_guardcharge);
}

#endif //#ifdef __BMT_CHARGE_GUARD_TIME__
/*
* FUNCTION
*	   bmt_stop_stoptimer
*
* DESCRIPTION                                                           
*   	This function is to stop the bmt_stop timer in bmt task.
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
void bmt_stop_stoptimer(void)
{
   #ifdef BMT_KAL_DEBUG    
   	kal_trace(TRACE_FUNC, BMT_STOP_TIMER_STOP_TRC);
   #endif 	
	drv_trace0(TRACE_GROUP_10, BMT_STOP_TIMER_STOP_TRC);
	stack_stop_timer(timer_stopcharge);
}

/*
* FUNCTION
*		BMT_ObtainBMTPHYSTAT
*
* DESCRIPTION																			  
*		This function is used to obtain the ADC measure result.
*	  Average the received Phy. data
*
* CALLS  
*
* PARAMETERS
*		Data: None
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
kal_bool BMT_ObtainBMTPHYSTAT(BATPHYStruct *BATPHYS)
{
#ifndef __BMT_NO_ISENSE_RESISTOR__    
	DCL_HANDLE dcl_adc_handle;
	ADC_CTRL_TRANSFORM_INTO_CURR_T rTransformCurr;
#endif    

#if defined(__DRV_BMT_ISENSE_OFFSET_COMPENSATION__)
	static kal_int32 ISense_Offset;
#endif

    drv_trace0(TRACE_GROUP_10, BMT_OBTAIN_PHY_STAT_TRC);
	BATPHYS->VBAT = BMT_VOL_RESULT[BMT_ADC_VBAT];
	drv_trace1(TRACE_GROUP_10, BMT_VBAT_TRC, BATPHYS->VBAT);
			
#ifndef __BMT_NO_ISENSE_RESISTOR__
	dcl_adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);

#if defined(__DRV_BMT_ISENSE_OFFSET_COMPENSATION__)
	if(BMT.pmictrl_state == PMIC_CHARGEOFF)
	{	
		ISense_Offset = BMT_VOL_RESULT[BMT_ADC_VISENSE] - BMT_VOL_RESULT[BMT_ADC_VBAT];
	}
	BATPHYS->ISense_Offset = ISense_Offset;
	
	rTransformCurr.u4Volt = BMT_VOL_RESULT[BMT_ADC_VISENSE] - BMT_VOL_RESULT[BMT_ADC_VBAT]-BATPHYS->ISense_Offset;
#else
	rTransformCurr.u4Volt = BMT_VOL_RESULT[BMT_ADC_VISENSE] - BMT_VOL_RESULT[BMT_ADC_VBAT];
#endif
	DclSADC_Control(dcl_adc_handle, ADC_CMD_TRANSFORM_INTO_CURR, (DCL_CTRL_DATA_T *)&rTransformCurr);
	BATPHYS->ICHARGE = rTransformCurr.u4Curr;
	DclSADC_Close(dcl_adc_handle);

#if defined(__DRV_BMT_ISENSE_OFFSET_COMPENSATION__)
	drv_trace1(TRACE_GROUP_10, BMT_VSENSE_TRC, BMT_VOL_RESULT[BMT_ADC_VISENSE]);
	drv_trace1(TRACE_GROUP_10, BMT_ICHARGE_TRC, BATPHYS->ICHARGE);
	drv_trace1(TRACE_GROUP_10, BMT_VSENSE_VBAT_OFFSET_TRC, BATPHYS->ISense_Offset);
#else
	BATPHYS->ICHARGE -= bmt_charging_para->CurrOffset[BMT.call_state];
	drv_trace1(TRACE_GROUP_10, BMT_ICHARGE_TRC, BATPHYS->ICHARGE);
	if((BMT.pmictrl_state == PMIC_CHARGEOFF) && ((BATPHYS->ICHARGE + bmt_charging_para->CurrOffset[BMT.call_state]) > bmt_charging_para->ICHARGE_ON_LOW))
	{
		drv_trace1(TRACE_GROUP_10, BMT_ADC_CALIBRATION_FAIL_TRC, BATPHYS->ICHARGE + bmt_charging_para->CurrOffset[BMT.call_state]);
	}
#endif
#endif // #ifndef __BMT_NO_ISENSE_RESISTOR__
	
	if(bmt_charging_para->bmt_check_temp)
	{
		BATPHYS->BATTMP = BMT_VOL_RESULT[BMT_ADC_VBATTMP];
		drv_trace1(TRACE_GROUP_10, BMT_BATTMP_TRC, BATPHYS->BATTMP);
	}
	if(bmt_charging_para->bmt_check_charger)
	{
		BATPHYS->VCHARGER = BMT_VOL_RESULT[BMT_ADC_VCHARGER];
		drv_trace1(TRACE_GROUP_10, BMT_VCHARGER_TRC, BATPHYS->VCHARGER);
	}
			
	if ((BMT.pmictrl_state == PMIC_CHARGEOFF)  ||
		((BMT.pmictrl_state == PMIC_CHARGEON ) &&
		( (BMT.bat_state == CHR_TOPOFF) || (BMT.bat_state == CHR_BATFULL) )))
	{
		VBAT_OFF = BATPHYS->VBAT;
		ADCBAT_OFF = BMT_ADC_RESULT[BMT_ADC_VBAT];
	}
	return KAL_TRUE;
}

// DCL PMU/PWIC Interface
void BMT_Charge(kal_bool enable)
{
#if ( !defined(__DRV_NO_CHARGER__) && !defined(__MAUI_BASIC__) )
	kal_bool data = enable;

	PMU_CTRL_CHR_SET_WDT_TIMER CtrlWdtTd;
	PMU_CTRL_CHR_SET_CHR_EN CtrlChrEn;
	PMU_CTRL_CHR_GET_CHR_DET_STATUS ctrlChrStatus;
#ifdef __MULTI_BOOT__
#ifdef __TC01__
    extern kal_uint16 INT_BootMode(void);    
#endif // #ifdef __TC01__
#endif // #ifdef __MULTI_BOOT__
	
    drv_trace1(TRACE_GROUP_10, BMT_CHARGE_ENABLE_TRC, enable);


	#ifdef __MULTI_BOOT__
	#ifdef __TC01__
	if (INT_BootMode() == MTK_FACTORY_MODE)
	{
		data = KAL_TRUE;
	}
	#endif // #ifdef __TC01__
	#endif // #ifdef __MULTI_BOOT__

	#ifdef __CS_FAC_DET__
	// Check if fac det return force to IDLE
	{
		cs_fac_boot_mode_enum fac_boot_mode;
		fac_boot_mode = cs_fac_det->factory_det_get_boot_mode();
		switch (fac_boot_mode)
		{
			case CS_FAC_BOOT_IDLE:
				data = KAL_TRUE;
			    break;
			default:
			    break;
		}
	}
	#endif // #ifdef __CS_FAC_DET__
	data = KAL_FALSE;
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    

	if (data==KAL_TRUE)
	{	
		DclPMU_Control(bmt_PmuHandler, CHR_SET_WDT_CLEAR, NULL);
	    CtrlWdtTd.secs=PMU_CHR_WDT_TD_32SEC;
		DclPMU_Control(bmt_PmuHandler, CHR_SET_WDT_TIMER, (DCL_CTRL_DATA_T *)&CtrlWdtTd);	
	}


#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
		bmt_find_and_set_the_nearest_charger_high_voltage(bmt_high_vchg_para->VCHG_HV_VTH);
#else
		bmt_find_and_set_the_nearest_charger_high_voltage(bmt_charging_para->VCHARGER_HIGH);
#endif

	DclPMU_Control(bmt_PmuHandler, CHR_GET_CHR_DET_STATUS, (DCL_CTRL_DATA_T *)&ctrlChrStatus);

	if (ctrlChrStatus.enable==DCL_TRUE)
	{
		CtrlChrEn.enable=enable;
		DclPMU_Control(bmt_PmuHandler, CHR_SET_CHR_EN, (DCL_CTRL_DATA_T *)&CtrlChrEn);
	}

	

#if defined(__PMU_WITH_EXTERNL_CHARGER__)
	{
		kal_uint32 savedMask;
		savedMask = SaveAndSetIRQMask();
		if ((kal_bool)data == KAL_TRUE)
		{
			// Set CTRL pin to LOW to enable charging
			GPIO_WriteIO(0, gpio_ext_chr_ctrl_pin);
		}
		else
		{
			// Set CTRL pin to HIGH to enable charging
			GPIO_WriteIO(1, gpio_ext_chr_ctrl_pin);
		}
		RestoreIRQMask(savedMask);
	}
#endif // #if defined(__PMU_WITH_EXTERNL_CHARGER__)

#if defined(__GENERAL_EXTERNAL_CHARGER__)
	{
		ext_charger->charge_enable((kal_bool)data);
	}
#endif // #if defined(__GENERAL_EXTERNAL_CHARGER__)


#endif // #if ( !defined(__DRV_NO_CHARGER__) && !defined(__MAUI_BASIC__) )
}

	
DCL_UINT32 bmt_find_closest_level(const DCL_UINT32 *pList,DCL_UINT32 number,DCL_UINT32 level)
{
    kal_int32 i;

	for(i = (number - 1); i >=0; i--)
	{
	    if(pList[i] <= level)
        {
	        return pList[i];
	    }    
        }    

	return pList[0];

    }
    
void bmt_find_and_set_the_nearest_charger_high_voltage(DCL_UINT32 voltage)
	{
	PMU_CTRL_CHR_GET_HV_DETECTION_VOLTAGE_LIST hv_voltage_list;
	PMU_CTRL_CHR_SET_HV_DETECTION_VOLTAGE hv_voltage;
	DCL_STATUS  status;
	
	status=DclPMU_Control(bmt_PmuHandler, CHR_GET_HV_DETECTION_VOLTAGE_LIST, (DCL_CTRL_DATA_T *)&hv_voltage_list);

	if(status==STATUS_UNSUPPORTED)
	{
		drv_trace1(TRACE_GROUP_10, BMT_PMU_DO_NOT_SUPPORT_TRC, 0);
		return;
	}

	hv_voltage.voltage=(PMU_VOLTAGE_ENUM)bmt_find_closest_level(hv_voltage_list.pVoltageList
		,hv_voltage_list.number,(DCL_UINT32)voltage);
	
	DclPMU_Control(bmt_PmuHandler, CHR_SET_HV_DETECTION_VOLTAGE, (DCL_CTRL_DATA_T *)&hv_voltage);

	}

void bmt_find_and_set_the_nearest_current(PMU_CHR_CURRENT_ENUM SetCurrent)
{
	
	PMU_CTRL_CHR_GET_CHR_CURRENT_LIST get_chr_current_list;
	PMU_CTRL_CHR_SET_CHR_CURRENT set_chr_current;
	DCL_STATUS  status;
	
	status=DclPMU_Control(bmt_PmuHandler, CHR_GET_CHR_CURRENT_LIST, (DCL_CTRL_DATA_T *)&get_chr_current_list);

	if(status==STATUS_UNSUPPORTED)
	{
		drv_trace1(TRACE_GROUP_10, BMT_PMU_DO_NOT_SUPPORT_TRC, 1);
		return;
	}

	set_chr_current.current=(PMU_CHR_CURRENT_ENUM)bmt_find_closest_level(get_chr_current_list.pCurrentList
		,get_chr_current_list.number,(DCL_UINT32)SetCurrent);

    drv_trace1(TRACE_GROUP_10, BMT_FIND_AND_SET_THE_NEAREST_CURRENT_TRC, set_chr_current.current);
    DclPMU_Control(bmt_PmuHandler, CHR_SET_CHR_CURRENT, (DCL_CTRL_DATA_T *)&set_chr_current);
}

#if defined(__USB_ENABLE__)
extern PMU_CHR_CURRENT_ENUM bmt_usb_chr_current;
#endif //#if defined(__USB_ENABLE__)

void bmt_set_customized_current(CHR_DET_TYPE_ENUM charger_type)
{
   	PMU_CHR_CURRENT_ENUM chr_current = PMU_CHARGE_CURRENT_0_00_MA;

    drv_trace0(TRACE_GROUP_10, BMT_SET_CUSTOMIZED_CURRENT_TRC);
   
    switch (charger_type)
    {
		case PW_AC_CHR:
			chr_current = CHR_AC_CHARGE_CURRENT;
            drv_trace0(TRACE_GROUP_10, BMT_SET_AC_CHARGE_CURRENT_TRC);  
		break;
#if defined(__USB_ENABLE__)
		case PW_USB_CHR:
            		chr_current = bmt_usb_chr_current;
            drv_trace0(TRACE_GROUP_10, BMT_SET_USB_CHARGE_CURRENT_TRC);               
#endif //#if defined(__USB_ENABLE__)              
		break;
		case PW_AC_NON_STD_CHR:
			chr_current = PMU_CHARGE_CURRENT_450_00_MA;
		break;
		default:
			ASSERT(0);
		break;
	} 
    
    bmt_find_and_set_the_nearest_current(chr_current);
}

kal_bool bmt_chr_chrdet(void)
{
    
    PMU_CTRL_CHR_GET_CHR_DET_STATUS chr_det_status;
    
    
    DclPMU_Control(bmt_PmuHandler, CHR_GET_CHR_DET_STATUS, (DCL_CTRL_DATA_T *)&chr_det_status);
     
    return (kal_bool)chr_det_status.enable;
}

void bmt_set_chr_current(void)
{
#if defined(__PMU_WITH_EXTERNL_CHARGER__)
	charger_usb_present_enum charger_type = CHARGER_PRESENT;
#endif // #if defined(__PMU_WITH_EXTERNL_CHARGER__)

	#if defined(__PMU_WITH_EXTERNL_CHARGER__)
	if (bmt_chr_chrdet())
	{
		charger_type = chr_usb_detect.chr_usb_present;
	}
	else
	{
		charger_type = NO_PRESENT;
	}
	#endif // #if defined(__PMU_WITH_EXTERNL_CHARGER__)
    
	#if defined (__USB_ENABLE__)
	#if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
    /* UPMU didn't support this part? Start */
	if (bmt_chr_chrdet())
		bmt_set_customized_current(PW_AC_CHR);
	else
		bmt_set_customized_current(PW_USB_CHR);

    /* UPMU didn't support this part? End */
	#else // #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	if (bmt_chr_chrdet())
	{
		if (chr_usb_detect.chr_usb_present == CHARGER_PRESENT)
		{
			bmt_set_customized_current(PW_AC_CHR);
		}
		else if (chr_usb_detect.chr_usb_present == CHARGER_PRESENT_NON)
		{
#if defined(__CHINA_CHARGER_STANDARD__)		
			bmt_set_customized_current(PW_AC_NON_STD_CHR);
#else
			bmt_set_customized_current(PW_AC_CHR);
#endif //#if defined(__CHINA_CHARGER_STANDARD__)
		}
		else if (chr_usb_detect.chr_usb_present == USB_PRESENT)
		{
			bmt_set_customized_current(PW_USB_CHR);
		}
	}
	#endif // #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	
	#else // #if defined (__USB_ENABLE__)
	if (bmt_chr_chrdet())
{
		bmt_set_customized_current(PW_AC_CHR);
	}
	#endif // #if defined (__USB_ENABLE__)

	
#if ( defined(__PMU_WITH_EXTERNL_CHARGER__) || defined(__GENERAL_EXTERNAL_CHARGER__) )

    #if defined(__DRV_EXT_CHARGER_DETECTION__)
    charger_type = ext_charger_det->det_charger_present();
    #endif // #if defined(__DRV_EXT_CHARGER_DETECTION__)

	#if ( defined(__PMU_WITH_EXTERNL_CHARGER__) )
	{
        extern const char gpio_ext_chr_ctrl_pin;
        extern const char gpio_ext_chr_iset_ctrl_pin;
        
		kal_uint32 savedMask;
		savedMask = SaveAndSetIRQMask();

		if (charger_type == CHARGER_PRESENT)
		{

			// Set CTRL pin to HIGH for AC
			GPIO_WriteIO(1, gpio_ext_chr_iset_ctrl_pin);
		}
		else if (charger_type == NO_PRESENT)
		{
			// Do nothing
		}
		else
		{
			// Set CTRL pin to LOW for USB
			GPIO_WriteIO(0, gpio_ext_chr_iset_ctrl_pin);
		}
		RestoreIRQMask(savedMask);
	}
	#endif // #if ( defined(__PMU_WITH_EXTERNL_CHARGER__) )
	#if ( defined(__GENERAL_EXTERNAL_CHARGER__) )
	{
		if (charger_type == CHARGER_PRESENT)
		{
			ext_charger->set_charge_current(ext_charger->get_specific_chr_current(BMT_AC_CHR));
		}
		else if (charger_type == NO_PRESENT)
		{
			;
		}
		else
		{
			ext_charger->set_charge_current(ext_charger->get_specific_chr_current(BMT_USB_CHR));
		}
	}
	#endif // #if ( defined(__GENERAL_EXTERNAL_CHARGER__) )

#endif // #if ( defined(__PMU_WITH_EXTERNL_CHARGER__) || defined(__GENERAL_EXTERNAL_CHARGER__) )
}

#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
    extern bmt_customized_high_vchg_struct *bmt_high_vchg_para;
#endif

void bmt_initialize(void)
{  
    BMT.BatType = LIBAT;

	/*BMT struct initialize*/
	BMT.call_state = idle_mode;
	BMT.pmictrl_state = PMIC_CHARGEOFF;

	#if defined(__DRV_ALLOW_BOOT_ON_WITHOUT_BATTERY__)
	if (!bmt_is_bat_on())
	{
		BMT_Charge(KAL_TRUE);
	}
	#endif // #if defined(__DRV_ALLOW_BOOT_ON_WITHOUT_BATTERY__)


}

void bmt_chr_force_enable(kal_bool enable)
{
    
    PMU_CTRL_CHR_SET_CHR_FORCE_EN force_en;
   
    force_en.enable = enable;
    DclPMU_Control(bmt_PmuHandler, CHR_SET_CHR_FORCE_EN, (DCL_CTRL_DATA_T *)&force_en);
    
}

kal_bool bmt_check_if_bat_on(void)
{
	
	PMU_CTRL_CHR_GET_IS_BATTERY_ON chr;
    
	
	DclPMU_Control(bmt_PmuHandler, CHR_GET_IS_BATTERY_ON, (DCL_CTRL_DATA_T *)&chr);
	
    
	return (kal_bool)chr.enable;
}

#if defined(PMIC_DET_USB_CHR)
kal_bool bmt_is_chr_det(pmic_chr_type type)
{
    return KAL_FALSE;
}
#endif
kal_bool bmt_is_chr_valid(void)
{
    
    PMU_CTRL_CHR_GET_IS_CHR_VALID bIsChrValid;
	DclPMU_Control(bmt_PmuHandler, CHR_GET_IS_CHR_VALID, (DCL_CTRL_DATA_T *)&bIsChrValid);
	
    
    return (kal_bool)bIsChrValid.enable;
}

kal_bool bmt_get_chr_cv_det(void)
{
	
	PMU_CTRL_CHR_GET_CV_DETECTION_STATUS Get_CV_Detect_Status;
    
	
	DclPMU_Control(bmt_PmuHandler, CHR_GET_CV_DETECTION_STATUS, (DCL_CTRL_DATA_T *)&Get_CV_Detect_Status);
	
	return (kal_bool)Get_CV_Detect_Status.enable;
}

void bmt_Modify_PowerOn_Type(kal_uint8 power_type)
{
        PW_CTRL_SET_POWERON_REASON CtrlVal;
        DCL_HANDLE pmu_handle;
        CtrlVal.powerOnReason = (PW_CTRL_POWER_ON_REASON)power_type; 
        pmu_handle=DclPW_Open(DCL_PW, FLAGS_NONE);
        DclPW_Control(pmu_handle, PW_CMD_SET_POWERON_REASON, (DCL_CTRL_DATA_T *)&CtrlVal);
        DclPW_Close(pmu_handle);
}

kal_uint8 bmt_Get_PowerOn_Type(void)
{
        PW_CTRL_GET_POWERON_REASON CtrlVal;
        DCL_HANDLE pmu_handle;
        pmu_handle = DclPW_Open(DCL_PW, FLAGS_NONE);
        DclPW_Control(pmu_handle, PW_CMD_GET_POWERON_REASON, (DCL_CTRL_DATA_T *)&CtrlVal);
        DclPW_Close(pmu_handle);
        return CtrlVal.powerOnReason;
}

bmt_customized_struct bmt_custom_chr_def =
{
    (kal_int32)CHR_TYPICAL_LI_BATTYPE, /* kal_int32 TYPICAL_LI_BATTYPE */
    (kal_int32)CHR_TYPICAL_NI_BATTYPE, /* kal_int32 TYPICAL_NI_BATTYPE */
    (kal_uint32)CHR_BATT_EXIST_ADC_THRESHOLD, /* kal_uint32 BATT_EXIST_ADC_THRESHOLD */
    (kal_int32)CHR_VCHARGER_HIGH, /* kal_int32 VCHARGER_HIGH */
    (kal_int32)CHR_VCHARGER_LOW, /* kal_int32 VCHARGER_LOW */
    (kal_int32)CHR_BATTMP_MINUS_40C, /* kal_int32 BATTMP_MINUS_40C */
    (kal_int32)CHR_BATTMP_0C, /* kal_int32 BATTMP_0C */
    (kal_int32)CHR_BATTMP_45C, /* kal_int32 BATTMP_45C */
    (kal_int32)CHR_ICHARGE_ON_HIGH, /* kal_int32 ICHARGE_ON_HIGH */
    (kal_int32)CHR_ICHARGE_ON_LOW, /* kal_int32 ICHARGE_ON_LOW */
    (kal_int32)CHR_ICHARGE_OFF_HIGH, /* kal_int32 ICHARGE_OFF_HIGH */
  
    (kal_int32)CHR_V_PRE2FAST_THRES, /* kal_int32 V_PRE2FAST_THRES */ 
    (kal_int32)CHR_FAST_ICHARGE_HIGHLEVEL, /* kal_int32 FAST_ICHARGE_HIGHLEVEL */
    (kal_int32)CHR_FAST_ICHARGE_LOWLEVEL, /* kal_int32 FAST_ICHARGE_LOWLEVEL */
    (kal_int32)CHR_I_TOPOFF2FAST_THRES, /* kal_int32 I_TOPOFF2FAST_THRES */
    (kal_int32)CHR_I_TOPOFF2FULL_THRES, /* kal_int32 I_TOPOFF2FULL_THRES */

#if defined(CHR_WITH_LI_ION_BATTERY)   
    (kal_int32)CHR_V_FAST2TOPOFF_THRES_LI, /* kal_int32 V_FAST2TOPOFF_THRES */
    (kal_int32)CHR_V_FULL2FAST_THRES_LI, /* kal_int32 V_FULL2FAST_THRES */
    (kal_int32)CHR_MAX_VBAT_LI, /* kal_int32 MAX_VBAT_LI */
    (kal_int32)CHR_V_PROTECT_HIGH_LI, /* kal_int32 V_PROTECT_HIGH_LI */
    (kal_int32)CHR_V_PROTECT_LOW_LI, /* kal_int32 V_PROTECT_LOW_LI */
#endif
#if defined(CHR_WITH_NI_MH_BATTERY)
    (kal_int32)CHR_V_TEMP_FAST2FULL_THRES_NI, /* kal_int32 V_TEMP_FAST2FULL_THRES_NI */
    (kal_int32)CHR_V_FULL2FAST_THRES_NI, /* kal_int32 V_FULL2FAST_THRES_NI */
    (kal_int32)CHR_MAX_VBAT_NI, /* kal_int32 MAX_VBAT_NI */
#endif // End of #if defined(CHR_WITH_NI_MH_BATTERY)

    /* PRE CHARGE ,search table */
    (kal_uint32)PRE_TON_TIME, /* kal_uint32 PRE_TON */
    (kal_uint32)PRE_TOFF_TIME, /*  kal_uint32 PRE_TOFF */

    /* FAST CHARGE, search table */
    (kal_uint32)TOPOFF_TON_TIME, /* kal_uint32 TOPOFF_TON */
    (kal_uint32)TOPOFF_TOFF_TIME, /* kal_uint32 TOPOFF_TOFF */
    
#if defined(DRV_BMT_PULSE_CHARGING)
    (kal_uint32)PULSE_POSTFULL_TWAIT_TIME, /* kal_uint32 BATPOSTFULL_TWAIT_LI */
    (kal_uint32)PULSE_POSTFULL_TON_TIME, /* kal_uint32 BATPOSTFULL_TON_LI */
    (kal_uint32)PULSE_POSTFULL_TOFF_TIME, /* kal_uint32 BATPOSTFULL_TOFF_LI */
#endif
#if defined(CHR_WITH_LI_ION_BATTERY)
    (kal_uint32)BATFULL_TON_TIME_LI, /* kal_uint32 BATFULL_TON_LI */
    (kal_uint32)BATFULL_TOFF_TIME_LI, /* kal_uint32 BATFULL_TOFF_LI */
#else
    (kal_uint32)BATFULL_TON_TIME_NI;  /* unit : second */
    (kal_uint32)BATFULL_TOFF_TIME_NI;
#endif    
    (kal_uint32)CHR_STOP_TOFF_TIME, /* kal_uint32 BATFULL_TOFF */
    (kal_uint32)BATHOLD_TOFF_TIME, /* kal_uint32 BATHOLD_OFF */
    (kal_uint32)MEASURE_DISCARD_TIME, /* kal_uint32 bmt_measure_discard_time */    

    //  kal_int32 CurrOffset[3];
    {
      CURRENT_OFFSET_IDLE_MODE, // 100ma
      CURRENT_OFFSET_TALK_MODE,
      CURRENT_OFFSET_SWOFF_MODE
    },   

    /*GPIO control*/   
#ifndef  __CUST_NEW__
    (kal_uint8)CHR_GPIO_CHR_CTRL,      /* kal_uint8 GPIO_CHRCTRL */
    (kal_uint8)CHR_GPIO_BATDET,   
    (kal_uint8)CHR_GPIO_VIBRATOR,
#endif  /* __CUST_NEW__ */

    //  kal_uint8 TONOFFTABLE[6][2];   
    {
        {(kal_uint8)FAST_ICHARGE_HI_NORMAL_ON,     (kal_uint8)FAST_ICHARGE_HI_NORMAL_OFF},
        {(kal_uint8)FAST_ICHARGE_MID_NORMAL_ON,    (kal_uint8)FAST_ICHARGE_MID_NORMAL_OFF},
        {(kal_uint8)FAST_ICHARGE_LO_NORMAL_ON,     (kal_uint8)FAST_ICHARGE_LO_NORMAL_OFF},
        {(kal_uint8)FAST_ICHARGE_HI_TALK_ON,       (kal_uint8)FAST_ICHARGE_HI_TALK_OFF},
        {(kal_uint8)FAST_ICHARGE_MID_TALK_ON,      (kal_uint8)FAST_ICHARGE_MID_TALK_OFF},
        {(kal_uint8)FAST_ICHARGE_LO_TALK_ON,       (kal_uint8)FAST_ICHARGE_LO_TALK_OFF}
    },

    (kal_bool)CHR_CHECK_BATTERY,
    (kal_bool)CHR_CHECK_CHARGER_VOLTAGE,
    (kal_bool)CHR_CHECK_BATT_TEMP,
    (kal_bool)CHR_BATTERY_TYPE
};
bmt_customized_struct *bmt_charging_para = &bmt_custom_chr_def;

DCL_STATUS bmt_get_customized_para(BMT_CTRL_GET_CUSTOMIZED_PARA_T *GetCustomizedPara)
{
    DCL_STATUS return_status = STATUS_INVALID_CMD;
    switch (GetCustomizedPara->eGetParaCmd)
    {
        case DCL_GET_BATTERY_TYPE:
            GetCustomizedPara->u4ChargingParameter = bmt_custom_chr_def.bmt_battery_type;
            return_status = STATUS_OK;
            break;
        case DCL_GET_CHECK_BATTERY:
            GetCustomizedPara->u4ChargingParameter = bmt_custom_chr_def.bmt_check_battery;
            return_status = STATUS_OK;
            break;            
        case DCL_GET_CHECK_CHARGER_VOLTAGE:
            GetCustomizedPara->u4ChargingParameter = bmt_custom_chr_def.bmt_check_charger;
            return_status = STATUS_OK;
            break;
        case DCL_GET_CHECK_BATT_TEMP:
            GetCustomizedPara->u4ChargingParameter = bmt_custom_chr_def.bmt_check_temp;
            return_status = STATUS_OK;            
            break;
        case DCL_GET_MAX_VBAT_LI:
            return_status = STATUS_UNSUPPORTED;  
            break;
        default:
            ASSERT(0); // Unsupported Get Command
            return_status = STATUS_INVALID_CMD;   
            break;                
    }

    return return_status;
            
}
