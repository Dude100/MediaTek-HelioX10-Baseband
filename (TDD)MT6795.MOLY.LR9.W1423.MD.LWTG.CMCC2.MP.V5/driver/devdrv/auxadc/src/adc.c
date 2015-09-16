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
 *    adc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the auxiliary ADC driver and adaption layer.
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#include "drv_features.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "adc_hw.h"
#include "adc_sw.h"
#include "kal_public_api.h"
#include "syscomp_config.h"
#include "dcl.h"

// For RHR ADD
#include "adc_channel.h"
#include "init.h"

#include "nvram_struct.h"
#include "nvram_enums.h"
#include "nvram_data_items.h"
#include "nvram_interface.h"
#include "adc_nvram_def.h"

#if !defined(DRV_ADC_OFF)
#include "cust_temp_det_ntc_cfg.h"

extern kal_bool adc_sync_mode_on;
extern kal_uint16 adc_imm_mode_cnt;
extern kal_uint32 adc_sche_rw_status;

#define BASE_ADDR_AUXADC (0xB6F2F000)

#define AUXADC_CON0         (BASE_ADDR_AUXADC + 0x000)
#define AUXADC_CON1         (BASE_ADDR_AUXADC + 0x004)
#define AUXADC_CON1_SET     (BASE_ADDR_AUXADC + 0x008)
#define AUXADC_CON1_CLR     (BASE_ADDR_AUXADC + 0x00C)
#define AUXADC_CON2         (BASE_ADDR_AUXADC + 0x010)

#define AUXADC_DAT(n)       (BASE_ADDR_AUXADC + 0x014 + (n*4))

#define AUXADC_DAT0         (BASE_ADDR_AUXADC + 0x014)
#define AUXADC_DAT1         (BASE_ADDR_AUXADC + 0x018)
#define AUXADC_DAT2         (BASE_ADDR_AUXADC + 0x01C)
#define AUXADC_DAT3         (BASE_ADDR_AUXADC + 0x020)
#define AUXADC_DAT4         (BASE_ADDR_AUXADC + 0x024)
#define AUXADC_DAT5         (BASE_ADDR_AUXADC + 0x028)
#define AUXADC_DET_VOLT     (BASE_ADDR_AUXADC + 0x084)
#define AUXADC_DET_SEL      (BASE_ADDR_AUXADC + 0x088)
#define AUXADC_DET_PERIOD   (BASE_ADDR_AUXADC + 0x08C)
#define AUXADC_DET_DEBT     (BASE_ADDR_AUXADC + 0x090)
#define AUXADC_MISC         (BASE_ADDR_AUXADC + 0x094)
#define AUXADC_SAMPLE_LIST  (BASE_ADDR_AUXADC + 0x09C)
#define AUXADC_TST          (BASE_ADDR_AUXADC + 0x0A4)
#define AUXADC_SPL_EN       (BASE_ADDR_AUXADC + 0x0B0)
#define AUXADC_SPL_CFG0     (BASE_ADDR_AUXADC + 0x0B4)
#define AUXADC_SPL_CFG1     (BASE_ADDR_AUXADC + 0x0B8)
#define AUXADC_SPL_CFG2     (BASE_ADDR_AUXADC + 0x0BC)
#define AUXADC_SADC_CON     (BASE_ADDR_AUXADC + 0x300)

extern const kal_uint8 ADC_VBAT;
extern const kal_uint8 ADC_VISENSE;
extern const kal_uint8 ADC_VCHARGER;

#define ADC_AUTO_SAMPLE_MODE_EN     /* to enable auto sample mode */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

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
		}
	},
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
	}
};

typedef struct {
    kal_uint32 Channel;
    kal_uint32 Pull_Vdd;
    kal_uint32 Pull_Res;
    NTC_RT *Rt_Tbl;
    kal_uint32 Rt_Tbl_Ent;
} TMP_DET_SETTING;

TMP_DET_SETTING auxadc_tmp_det_setting[2]; /*= {
    {Pmic_Ntc_ADC_Chan, Pmic_Ntc_Pull_Vdd, Pmic_Ntc_Pull_Res, Pmic_Ntc_Rt_Table, Pmic_Ntc_Rt_Table_Ent},
    {Asic_Ntc_ADC_Chan, Asic_Ntc_Pull_Vdd, Asic_Ntc_Pull_Res, Asic_Ntc_Rt_Table, Asic_Ntc_Rt_Table_Ent},
};*/

kal_uint32 auxadc_tmp_det_setting_ent = sizeof(auxadc_tmp_det_setting)/sizeof(auxadc_tmp_det_setting[0]);


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
void adc_read_calibration_data(void)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    int i;

    /* No calibration needed, so ... */
    for (i = 0; i < ADC_MAX_CHANNEL; i++) {
        adc_customized_para.adc_cali_param.ADCSlope[i]  = 1800000/4096;
        adc_customized_para.adc_cali_param.ADCOffset[i] = 0;
    }
#endif
}


/*
* FUNCTION                                                            
*	ADC_GetData
*
* DESCRIPTION                                                           
*   	This function is to run ADC, and obtain the measured data
*
* CALLS  
*
* PARAMETERS
*	sel :  selection of input signal source(0-4)
*	
* RETURNS
*	return the value of ADC output
*
* GLOBALS AFFECTED
*   external_global
*/
/*must add power on function before this function*/
#define ADC_MEA_TIMES       5
#define ADC_MEA_TMO_MS      20      /* 16T(4~5us) per channel */
kal_uint16 ADC_GetData(kal_uint8 chIdx)
{
    volatile kal_uint32 auxData[ADC_MEA_TIMES], sum = 0;
    kal_uint32 i;
    volatile kal_uint32 start_time;

#if defined(ADC_AUTO_SAMPLE_MODE_EN)
    for (i = 0; i < ADC_MEA_TIMES; i++) {
        start_time = drv_get_current_time();
        while(1)
        {
            /* Get ADC data */
            auxData[i] = DRV_Reg32(AUXADC_DAT(chIdx));

            /* Check if RDY bit is set */
            if ((auxData[i] & (1 << 12))) {
                break;
            }

            /* According to Designer's comment, RDY will be set after 16T */
            if (drv_get_duration_ms(start_time) > ADC_MEA_TMO_MS) {
                tst_sys_trace("Error: Wait ADC Data RDY Timeout!!!\r\n");
                break;
            }
        }

        auxData[i] &= ~(1<<12);
        sum += auxData[i];
    }
#else
    /* Select the ADC channel */
    DRV_SetBits32(AUXADC_CON1, (1 << chIdx));

    for (i = 0; i < ADC_MEA_TIMES; i++) {
        /* Set the immediate mode */
        DRV_SetBits32(AUXADC_CON1_SET, (1 << chIdx));

        /* Get ADC data */
        start_time = drv_get_current_time();
        auxData[i] = DRV_Reg32(AUXADC_DAT(chIdx));
        while((!(auxData[i] & (1 << 12))) && (drv_get_duration_ms(start_time) <= ADC_MEA_TMO_MS))
        {
            auxData[i] = DRV_Reg32(AUXADC_DAT(chIdx));            
        }
        auxData[i] &= ~(1<<12);
        sum += auxData[i];

        /* Clear the immediate mode */
        DRV_SetBits32(AUXADC_CON1_CLR, (1 << chIdx));
    }
    
    /* De-select the ADC channel */
    DRV_ClearBits32(AUXADC_CON1, (1 << chIdx));
#endif

    sum = sum / ADC_MEA_TIMES;
    
    dbg_print("[ADC] %s: chn = %d, result = %X\r\n", __FUNCTION__, chIdx, sum);
    return (kal_uint16)sum;
}

/*
* FUNCTION                                                            
*	ADC_GetMeaData
*
* DESCRIPTION                                                           
*   	This function is to run ADC, and obtain the average value of measured data
*     Note that: This function only called before other tasks are running.
*
* CALLS  
*
* PARAMETERS
*	sel :  selection of input signal source(0-4)
*  meacount: measure count
*	
* RETURNS
*	return the average value of ADC output
*
* GLOBALS AFFECTED
*   None
*/
kal_uint32 ADC_GetMeaData(kal_uint8 sel, kal_uint16 meacount)
{
   kal_uint32 index;
   kal_uint32 sum = 0;

   for(index = meacount; index != 0; index--)
   {
      sum += (kal_uint32)ADC_GetData(sel);
   }

   return sum;
}

/*
* FUNCTION                                                            
*	ADC_GetData2Meta
*
* DESCRIPTION                                                           
*   	This function is called by META, and return the sum value.
*
* CALLS  
*
* PARAMETERS
*	sel :  selection of input signal source(0-4)
*  meacount: measure count
*	
* RETURNS
*	return the average value of ADC output
*
* GLOBALS AFFECTED
*   None
*/
kal_uint32 ADC_GetData2Meta(kal_uint8 sel, kal_uint16 meacount)
{
    kal_uint32 index;
    kal_uint32 sum = 0;

    for(index = meacount; index != 0; index--)
    {
        sum += (kal_uint32)ADC_GetData(sel);
    }

    dbg_print("[ADC] %s: %X\r\n", __FUNCTION__, sum);
    
    return sum;
}

void ADC_Init(void)
{
    /* Enable source clock */
    DRV_ClearBits32(0xB6F2D208, (1 << 0));
    
    /* Change AUXADC from 1.5V to 1.8V */
    DRV_WriteReg32(0xB6F2F300, DRV_Reg32(0xB6F2F300)|(1<<12));

#if defined(ADC_AUTO_SAMPLE_MODE_EN)
    /* Enable auto-sample mode */
    DRV_WriteReg32(AUXADC_CON0, 0x3F);

    /* Enable immediate mode */
    DRV_WriteReg32(AUXADC_CON1, 0x3F);
#endif

    /* Initilize global variable */
    auxadc_tmp_det_setting[0].Channel   = Pmic_Ntc_ADC_Chan;
    auxadc_tmp_det_setting[0].Pull_Vdd  = Pmic_Ntc_Pull_Vdd; 
    auxadc_tmp_det_setting[0].Pull_Res  = Pmic_Ntc_Pull_Res;
    auxadc_tmp_det_setting[0].Rt_Tbl    = Pmic_Ntc_Rt_Table;
    auxadc_tmp_det_setting[0].Rt_Tbl_Ent= Pmic_Ntc_Rt_Table_Ent;
    
    auxadc_tmp_det_setting[1].Channel   = Asic_Ntc_ADC_Chan;
    auxadc_tmp_det_setting[1].Pull_Vdd  = Asic_Ntc_Pull_Vdd;
    auxadc_tmp_det_setting[1].Pull_Res  = Asic_Ntc_Pull_Res;
    auxadc_tmp_det_setting[1].Rt_Tbl    = Asic_Ntc_Rt_Table;
    auxadc_tmp_det_setting[1].Rt_Tbl_Ent= Asic_Ntc_Rt_Table_Ent;
}

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
kal_int32 adc_adc2vol(kal_uint8 chann, double adcVoltage)
{
    double result;

    if(chann >=  ADC_MAX_CHANNEL)
        ASSERT(0);

    /* Need get the Adc voltage firstly, or does the cali-data contain the conversion ??? */
    
    /* Do Calibration */
    result = (double)((adcVoltage*(double)adc_customized_para.adc_cali_param.ADCSlope[chann]) +
                     (double)adc_customized_para.adc_cali_param.ADCOffset[chann]);

    return (kal_int32)result;
    //return (kal_int32)(result/PMIC_ADC_FACTOR_VBAT*volt_factor);
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

/*
* FUNCTION
*	   ADC_Volt2Temp
*
* DESCRIPTION                                                           
*   	This function is to translate voltage to temperatrure
*
* CALLS  
*
* PARAMETERS
*	   chIdx : AUXADC Channel
*      uVolt : Calibrated Voltage Value, unit (uV)
*	
* RETURNS
*	   temperature(m'C)
*
* GLOBALS AFFECTED
*     None
*/
kal_int32 ADC_Volt2Temp(kal_uint8 chIdx, kal_uint32 uVolt)
{
    TMP_DET_SETTING *setting = (TMP_DET_SETTING *)NULL;
    NTC_RT *rt1 = (NTC_RT *)NULL;
    NTC_RT *rt2 = (NTC_RT *)NULL;
    double slope;
    double ntc_res;
    kal_int32 ntc_tmp = 0;
    int i;
    
    for (i = 0; i < auxadc_tmp_det_setting_ent; i++) {
        setting = &auxadc_tmp_det_setting[i];
        if (setting->Channel == chIdx)
            break;
    }

    if (i == auxadc_tmp_det_setting_ent) {
        /* No setting found */
        return 0;
    }

    ASSERT(uVolt <= setting->Pull_Vdd);
    
    if (uVolt < setting->Pull_Vdd) {
        ntc_res = ((double)uVolt)*setting->Pull_Res/(setting->Pull_Vdd-uVolt);
    } else {
        /* pull up too small, or temperature too low */
        ntc_res = (double)0x0FFFFFFF;  /* 268M ohm */
    }

    ASSERT(setting->Rt_Tbl_Ent >= 2);

    for (i = 0; i < setting->Rt_Tbl_Ent-1; i++) {
        rt1 = &setting->Rt_Tbl[i];       /* lower temp, bigger res */
        rt2 = &setting->Rt_Tbl[i+1];     /* higher temp, smaller res */
        
        if (ntc_res >= rt1->uRes)   /* temp too low */
            break;

        if (rt2->uRes <= ntc_res)   /* temp in range */
            break;
    }

    ASSERT(rt2->iTemp > rt1->iTemp);
    ASSERT(rt1->uRes > rt2->uRes);

    /* slope should be negative */
    slope = ((double)(rt1->iTemp - rt2->iTemp)) / ((double)(rt1->uRes - rt2->uRes));   

    ntc_tmp = rt2->iTemp*1000 + (kal_int32)(slope*(ntc_res - rt2->uRes)*1000);

    return ntc_tmp;
}


/*
* FUNCTION
*	   ADC_GetImmTemp
*
* DESCRIPTION                                                           
*   	This function is to get immediate temperature of specific channel
*
* CALLS  
*     adc_measureVoltage
*     adc_Volt2Temp
*
* PARAMETERS
*	   chann: ADC channel.
*	
* RETURNS
*	   immediate temperature(C)
*
* GLOBALS AFFECTED
*     None
*/
kal_int16 ADC_GetImmTemp(kal_uint8 chann)
{
    double adc_value;
    kal_uint32 uVolt;
    

    ASSERT(chann <  ADC_MAX_CHANNEL);

    uVolt = adc_measureVoltage(chann, &adc_value);

    return ADC_Volt2Temp(chann, uVolt)/1000;
}


/*
* FUNCTION
*	   ADC_GetPhysicalChannel
*
* DESCRIPTION                                                           
*   	This function is to get physical AUXADC Channel ID
*
* CALLS  
*
*
* PARAMETERS
*	   adcname: ADC channel name.
*	
* RETURNS
*      <0  means error
*      >=0 means AUXADC Channel ID
*
* GLOBALS AFFECTED
*     None
*/
kal_int16 ADC_GetPhysicalChannel(kal_uint16 adcname)
{
    kal_int16 iPhyChan = -1;

    if (adcname == DCL_MDTMP_ADC_CHANNEL) {
        iPhyChan = Asic_Ntc_ADC_Chan;
    } else if (adcname == DCL_PMICTMP_ADC_CHANNEL) {
        iPhyChan = Pmic_Ntc_ADC_Chan;
    } else {
        iPhyChan = -1;
        //ASSERT(0);
    }

    return iPhyChan;
}

#else   /* !defined(DRV_ADC_OFF) */

#endif

