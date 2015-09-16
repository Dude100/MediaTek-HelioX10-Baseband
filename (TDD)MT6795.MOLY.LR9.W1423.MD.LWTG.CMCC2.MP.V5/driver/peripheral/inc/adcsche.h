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
 *    adcsche.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for ADC scheduler
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
 * removed!
 * removed!
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
#ifndef _ADCSCHE_H
#define _ADCSCHE_H

#include "adc_hw.h"
#include "dcl.h"

#define ADC_SCHE_MAX_CHANNEL  (ADC_MAX_CHANNEL*2+4) /*engineering mode, chargeing mode, and MMI mode*/

//typedef void (* ADC_FUNC)(kal_int32 handle, kal_int32 volt_result, double adc_result);


/*adcsche.h*/
typedef struct{
   module_type    ownerid;
  sap_type       sapid;
	kal_uint32     period;
	kal_uint8      adc_phy_id;
	kal_uint8      adc_logic_id;
	kal_uint8		evaluate_count;	/*how many to average*/
	kal_int32       send_primitive;
	kal_bool       conti_measure;
	eventid        adc_sche_event_id;
	void (*complete)(signed long adc_handle, signed long volt_result, double adc_result);/*callback for upper layer*/
}ADCScheMeasParameter;

typedef struct{
	kal_uint8      *multi_adc_phy_id;
	kal_uint8		max_multi_channel_number;
	void (*multi_complete)(signed long adc_handle, signed long *volt_result, double *adc_result);/*callback for upper layer*/
}ADCMultiChanParameter;


// The core functions for ADC
// adcsche.c
extern kal_uint32 adc_sche_create_object(ADC_CTRL_CREATE_OBJECT_T *prCreateObj);
extern void adc_sche_modify_parameters(kal_uint32 adc_sche_id, kal_uint32 period, kal_uint8 evaluate_count);
extern void adc_sche_add_item(kal_uint32 adc_sche_id, void (*mea_complete)(signed long handle, signed long volt_result, double adc_result), kal_timer_func_ptr mea_Callback);
extern void adc_sche_remove_item(kal_uint32 adc_sche_id);
extern void adc_sche_init(void);
extern void adc_sche_measure(void* msg_ptr);
extern void adc_sche_get_parameter(kal_uint32 adc_sche_id, ADCScheMeasParameter **para);
extern void adc_pwrdown_disable(void);
extern void adc_pwrdown_enable(void);
extern kal_uint8 adc_sche_get_channel(adc_channel_type type);
extern void adcsche_adc_measure_en(kal_bool adc_measure_enable);
extern void adc_multi_channel_set(DCL_UINT32 adc_sche_id, DCL_MULTI_CHANNEL_PARA_T* pMultiChannelPara);

// adcmeasure.c
#if defined(DRV_ADC_FULL_FUNC)
extern void adc_tdma_time_setup(kal_uint16 idle_time, kal_uint16 trx_time);
#endif // #if defined(DRV_ADC_FULL_FUNC)
extern void adc_measure_parameter_init(void);
extern void adc_sche_stop_timer(kal_uint8 adc_sche_id);
extern void adc_sche_set_timer(kal_uint8 adc_sche_id, kal_uint32 tick, kal_timer_func_ptr call_func);
extern void adc_read_efuse_data(double *slope, double *offset);
extern void adc_read_calibration_data_inform(void);
extern void adc_set_adc_calibration_data(ilm_struct *lim_ptr);
extern kal_int32 adc_adc2vol(kal_uint8 chann,double adcVoltage);
extern kal_int32 volt2temp(kal_int32 _volt);
extern kal_int32 volt2isense(kal_int32 _volt);

#endif	/*_ADCSCHE_H*/

