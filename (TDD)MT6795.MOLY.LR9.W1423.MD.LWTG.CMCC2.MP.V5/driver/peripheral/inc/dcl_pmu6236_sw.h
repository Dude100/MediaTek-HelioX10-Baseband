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
 *    dcl_pmu6236_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMU6236
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#ifndef __DCL_PMU6236_SW_H_STRUCT__
#define __DCL_PMU6236_SW_H_STRUCT__

#include "dcl_pmic_features.h"

#if defined(PMIC_6236_REG_API)

/* Charger external interrupt is fixed. */


#define PMU_CHR_EINT_PIN      15

/* adc number for measuring VBAT/VISENSE/VCHARGER is fixed internally. */

#if defined(DRV_MISC_PMU_ADC_CHANNEL_FROM_0)
#define PMU_ADC_VBAT_CH_NUM      0
#define PMU_ADC_VISENSE_CH_NUM   1
#define PMU_ADC_VCHARGER_CH_NUM  2
#else // #if defined(DRV_MISC_PMU_ADC_CHANNEL_FROM_0)
#define PMU_ADC_VBAT_CH_NUM      3
#define PMU_ADC_VISENSE_CH_NUM   4
#define PMU_ADC_VCHARGER_CH_NUM  5
#endif // #if defined(DRV_MISC_PMU_ADC_CHANNEL_FROM_0)


/* adc factor for VBAT/VISENSE/VCHARGER */
#define PMU_ADC_FACTOR_VBAT      100
#define PMU_ADC_FACTOR_VISENSE   100
#define PMU_ADC_FACTOR_VCHARGER  473  // 369/39 * 50


// Define to enable pmu6236 charger watch dog timer kick
// When enable charger, pmu6236 will enable a watch dog timer
// We need to kick the timer periodically, to ontify pmu6236 that BB is alive
// If timeout, pmu6236 will disable charge automatically
// #### If this is NOT enabled, we will disable the watch dog timer function at boot time
// This should be defined when PMU driver need to perform WDT clear 
// BMT already support charge WDT, so this should be comment
//#define pmu6236_ENABLE_DRIVER_CHARGE_WDT


// Define to disable charge WDT of pmu6236
// Define only for debug purpose
//#define DEBUG_DISABLE_CHARGE_WDT

#define LDO_ADDRESS_BIAS      0x10
#define CAL_MAX               0x10
#define PMU_START_BASE        MIXED_base



typedef enum{
    PMU6236_DEFAULT_LOCAL_SENSE=0,
    PMU6236_REMOTE_SENSE
}pmu6236_sense_enum;

typedef enum{
    VRF_ON_SEL_SRCLKENA=0,
    VRF_ON_SEL_VRF_EN
}pmu6236_vrf_on_sel_enum;


typedef enum{
    VTCXO_ON_SEL_SRCLKENA=0,
    VTCXO_ON_SEL_VTCXO_EN
}pmu6236_vtcxo_on_sel_enum;

typedef enum{
    pmu6236_VSIM_1_8V = 0,
    pmu6236_VSIM_3_0V
}pmu6236_vsim_vosel_enum;

typedef enum{
    pmu6236_VSIM2_1_3V = 0,
    pmu6236_VSIM2_1_5V,
    pmu6236_VSIM2_1_8V,
    pmu6236_VSIM2_2_5V,
    pmu6236_VSIM2_2_8V,
    pmu6236_VSIM2_3_0V,
    pmu6236_VSIM2_3_3V
//    pmu6236_VSIM2_3_3V     // ?????
}pmu6236_vsim2_vosel_enum;

typedef enum{
    pmu6236_VMC_1_3V = 0,
    pmu6236_VMC_1_5V,
    pmu6236_VMC_1_8V,
    pmu6236_VMC_2_5V,
    pmu6236_VMC_2_8V,
    pmu6236_VMC_3_0V,
    pmu6236_VMC_3_3V
}pmu6236_vmc_vosel_enum;

typedef enum{
    VBT_SEL_2_8V = 0,
    VBT_SEL_3_0V
}pmu6236_vbt_sel_enum;

typedef enum{
    VCAMD_SEL_1_3V = 0,
    VCAMD_SEL_1_5V,
    VCAMD_SEL_1_8V,
    VCAMD_SEL_2_8V,
    VCAMD_SEL_RSV1,     // reserved
    VCAMD_SEL_RSV2,
    VCAMD_SEL_RSV3,
    VCAMD_SEL_RSV4    
}pmu6236_vcamd_vosel_enum;

typedef enum{
    VCAMA_SEL_1_5V = 0,
    VCAMA_SEL_1_8V,
    VCAMA_SEL_2_5V,
    VCAMA_SEL_2_8V
}pmu6236_vcama_vosel_enum;

typedef enum{
    VCORE_VOSEL_1_2V = 0    
}pmu6236_vcore_vosel_enum;

typedef enum{
    VCORE_VFBADJ_1_2V      = 0,
    VCORE_VFBADJ_1_225V    = 1,         
    VCORE_VFBADJ_1_25V     = 2,
    VCORE_VFBADJ_1_275V    = 3,
    VCORE_VFBADJ_1_3V      = 4,
    VCORE_VFBADJ_1_3V_rev1 = 5,
    VCORE_VFBADJ_1_3V_rev2 = 6, 
    VCORE_VFBADJ_1_3V_rev3 = 7,
    VCORE_VFBADJ_1_3V_rev4 = 8, 
    VCORE_VFBADJ_1_3V_rev5 = 9,
    VCORE_VFBADJ_1_3V_rev6 = 10, 
    VCORE_VFBADJ_1_3V_rev7 = 11,
    VCORE_VFBADJ_1_3V_rev8 = 12, 
    VCORE_VFBADJ_1_3V_rev9 = 13,
    VCORE_VFBADJ_1_3V_rev10= 14, 
    VCORE_VFBADJ_1_3V_rev11= 15,
    VCORE_VFBADJ_0_8V      = 16,
    VCORE_VFBADJ_0_825V    = 17,
    VCORE_VFBADJ_0_85V     = 18,
    VCORE_VFBADJ_0_875V    = 19,
    VCORE_VFBADJ_0_9V      = 20,
    VCORE_VFBADJ_0_925V    = 21,
    VCORE_VFBADJ_0_95V     = 22,
    VCORE_VFBADJ_0_975V    = 23,
    VCORE_VFBADJ_1_0V      = 24,
    VCORE_VFBADJ_1_025V    = 25,
    VCORE_VFBADJ_1_05V     = 26,
    VCORE_VFBADJ_1_075V    = 27,
    VCORE_VFBADJ_1_1V      = 28,    
    VCORE_VFBADJ_1_125V    = 29,
    VCORE_VFBADJ_1_15V     = 30,
    VCORE_VFBADJ_1_175V    = 31
  
}pmu6236_vcore_vfbadj_enum;

typedef enum{
    VCORE_MODESET_AUTO = 0,
    VCORE_MODESET_PWM
}pmu6236_vcore_modeset_enum;

typedef enum{
    VCORE_CSL_130K = 0,
    VCORE_CSL_120K,
    VCORE_CSL_110K,
    VCORE_CSL_100K,
    VCORE_CSL_90K,
    VCORE_CSL_80K,
    VCORE_CSL_70K,
    VCORE_CSL_60K
}pmu6236_vcore_csl_enum;

typedef enum{
    VCORE_600_450 = 0,
    VCORE_650_500,
    VCORE_500_350,
    VCORE_550_400
}pmu6236_vcore_burst_enum;

typedef enum{
    VM_CSL_130K = 0,
    VM_CSL_120K,
    VM_CSL_110K,
    VM_CSL_100K,
    VM_CSL_90K,
    VM_CSL_80K,
    VM_CSL_70K,
    VM_CSL_60K
}pmu6236_vm_csl_enum;

typedef enum{
    VM_600_450 = 0,
    VM_650_500,
    VM_500_350,
    VM_550_400
}pmu6236_vm_burst_enum;

typedef enum{
    CHR_CURR_800_0MA = 0,
    CHR_CURR_700_0MA,
    CHR_CURR_600_0MA,
    CHR_CURR_500_0MA,
    CHR_CURR_400_0MA,
    CHR_CURR_300_0MA,
    CHR_CURR_200_0MA,
    CHR_CURR_100_0MA
}pmu6236_chr_current_enum;

typedef enum{
    CHR_VBAT_CC_3_250V = 0,
    CHR_VBAT_CC_3_275V,
    CHR_VBAT_CC_3_300V,
    CHR_VBAT_CC_3_325V
}pmu6236_chr_vbat_cc_enum;

typedef enum{
/*0x00*/    CHR_VBAT_CV_4_0000V = 0,
/*0x01*/    CHR_VBAT_CV_4_0125V,
/*0x02*/    CHR_VBAT_CV_4_0250V,
/*0x03*/    CHR_VBAT_CV_4_0375V,
/*0x04*/    CHR_VBAT_CV_4_0500V,
/*0x05*/    CHR_VBAT_CV_4_0625V,
/*0x06*/    CHR_VBAT_CV_4_0750V,
/*0x07*/    CHR_VBAT_CV_4_0875V,
/*0x08*/    CHR_VBAT_CV_4_1000V,
/*0x09*/    CHR_VBAT_CV_4_1125V,
/*0x0a*/    CHR_VBAT_CV_4_1250V,
/*0x0b*/    CHR_VBAT_CV_4_1375V,
/*0x0c*/    CHR_VBAT_CV_4_1500V,
/*0x0d*/    CHR_VBAT_CV_4_1625V,
/*0x0e*/    CHR_VBAT_CV_4_1750V,
/*0x0f*/    CHR_VBAT_CV_4_1875V,
/*0x10*/    CHR_VBAT_CV_4_2000V,
/*0x11*/    CHR_VBAT_CV_4_2125V,
/*0x12*/    CHR_VBAT_CV_4_2250V,
/*0x13*/    CHR_VBAT_CV_4_2375V,
/*0x14*/    CHR_VBAT_CV_4_2500V,
/*0x15*/    CHR_VBAT_CV_4_2625V,
/*0x16*/    CHR_VBAT_CV_4_2750V,
/*0x17*/    CHR_VBAT_CV_4_2875V
}pmu6236_chr_vbat_cv_enum;

typedef enum{
    CV_TUNE_1_205V = 0,
    CV_TUNE_1_210V,
    CV_TUNE_1_215V,
    CV_TUNE_1_180V,
    CV_TUNE_1_185V,
    CV_TUNE_1_190V,
    CV_TUNE_1_195V
}pmu6236_cv_tune_enum;

typedef enum{
    CAL_PRECC_50_0MA = 0,
    CAL_PRECC_87_5_MA,
    CAL_PRECC_150_0MA,
    CAL_PRECC_225_0MA
}pmu6236_cal_precc_enum;

typedef enum{
    SYSTEM_PWR_SRC_DEFAULT = 0,
    SYSTEM_PWR_SRC_REFER_PS_SET
}pmu6236_ps_sel_enum;

typedef enum{
    SYSTEM_PWR_SRC_VBAT = 0,
    SYSTEM_PWR_SRC_AC
}pmu6236_ps_set_enum;

typedef enum{
    CHR_OV_5_5V = 0,
    CHR_OV_6_0V,
    CHR_OV_6_5V,
    CHR_OV_7_0V
}pmu6236_chr_ov_enum;

typedef enum{
    CHR_WDT_4_SEC = 0,
    CHR_WDT_8_SEC,
    CHR_WDT_16_SEC,
    CHR_WDT_32_SEC,
    CHR_WDT_45_MIN
}pmu6236_chr_wdt_td_enum;

typedef enum{
    VIBR_SEL_1_3V = 0,
    VIBR_SEL_1_5V,
    VIBR_SEL_1_8V,
    VIBR_SEL_2_5V,
    VIBR_SEL_2_8V,
    VIBR_SEL_3_0V,
    VIBR_SEL_3_3V
}pmu6236_vibr_vosel_enum;

typedef enum{
    SPK_VOL_12DB = 0,
    SPK_VOL_18DB
}pmu6236_spk_vol_enum;

typedef enum{
    VBOOST_TYPE_VOLTAGE_CONTROLLER = 0,
    VBOOST_TYPE_CURRENT_CONVERTER
}pmu6236_vboost_type_enum;

typedef enum{
    VBOOST_DIMMING_MODE = 0,   // Controlled by PWM
    VBOOST_PWM_MODE = 0,
    VBOOST_REGISTER_CONTROL_MODE = 1,
    VBOOST_NORMAL_MODE = 1
}pmu6236_vboost_mode_enum;

//typedef enum{
//    VBOOST_PWM_MODE = 0,
//    VBOOST_REGISTER_CONTROL_MODE
//}pmu6236_vboost_mode_enum;

typedef enum{
    PMU6236_ISINK_PWM_MODE = 0,
    PMU6236_ISINK_REGISTER_CONTROL_MODE = 1
}pmu6236_isink_mode_enum;

typedef enum{
    ISINK_STEP_4MA = 0,
    ISINK_STEP_8MA,
    ISINK_STEP_12MA,
    ISINK_STEP_16MA,
    ISINK_STEP_20MA,
    ISINK_STEP_24MA
}pmu6236_isink_step_enum;


typedef enum{
    OC_TD_100_US = 0,
    OC_TD_200_US,
    OC_TD_400_US,
    OC_TD_800_US
}pmu6236_oc_td_enum;


typedef enum{
    STB_TD_100_US = 0,
    STB_TD_200_US,
    STB_TD_400_US,
    STB_TD_800_US
}pmu6236_stb_td_enum;

// (0xC80) KPLED CON0
typedef enum{
	PMU6236_KPLED_PWM_MODE = 0,
	PMU6236_KPLED_REGISTER_CONTROL_MODE = 1,
	PMU6236_KPLED_NORMAL_MODE = 1
}pmu6236_kpled_mode_enum;

// (0xC90) FLASH_CON0
typedef enum{
	FLASH_PWM_MODE = 0,
	FLASH_REGISTER_CONTROL_MODE = 1,
	FLASH_NORMAL_MODE = 1
}pmu6236_flash_mode_enum;

//typedef enum{
//	KPLED_1_WLED_1_RLED = 0,
//	KPLED_4_WLED_4_RLED = 3,
//	KPLED_4_WLED_8_RLED = 7
//}pmu6236_kpled_sel_enum;


// Used to fill PCHR_FLAG_SEL
typedef enum{
	PCHR_CMD_PCHR_STATE = 2
}pmu6236_pchr_cmd_enum;

typedef enum{
	PCHR_STATE_IDLE = 0
}pmu6236_pchr_state_enum;

/*
typedef enum{
	BL_MODE_1 = 0,
	BL_MODE_2,
	BL_MODE_3
}pmu6236_bl_mode_enum;
*/

/*
// =====================================================================================
// (0x800) VRF_CON0
extern void pmu6236_vrf_enable(kal_bool enable);
extern void pmu6236_vrf_on_sel(pmu6236_vrf_on_sel_enum sel);
extern void pmu6236_vrf_sense(pmu6236_sense_enum sel);
extern void pmu6236_vrf_ndis_enable(kal_bool enable);
extern void pmu6236_vrf_stb_enable(kal_bool enable);
extern void pmu6236_vrf_oc_auto_off(kal_bool enable);
extern void pmu6236_vrf_ocfb_enable(kal_bool enable);
extern kal_bool pmu6236_vrf_status(void);

//  (0x804) VRF_CON1
extern void pmu6236_vrf_cal(kal_uint8 val);

// (0x810) VTCXO_CON0
extern void pmu6236_vtcxo_enable(kal_bool enable);
extern void pmu6236_vtcxo_on_sel(pmu6236_vtcxo_on_sel_enum sel);
extern void pmu6236_vtcxo_ndis_enable(kal_bool enable);
extern void pmu6236_vtcxo_stb_enable(kal_bool enable);
extern void pmu6236_vtcxo_oc_auto_off(kal_bool enable);
extern void pmu6236_vtcxo_ocfb_enable(kal_bool enable);
extern kal_bool pmu6236_vtcxo_status(void);

// (0x814) VTCXO_CON1
extern void pmu6236_vtcxo_cal(kal_uint8 val);

// (0x820) VA_CON0
extern void pmu6236_va_sense(pmu6236_sense_enum sel);
extern void pmu6236_va_ndis_enable(kal_bool enable);
extern void pmu6236_va_stb_enable(kal_bool enable);
extern void pmu6236_va_oc_auto_off(kal_bool enable);
extern void pmu6236_va_ocfb_enable(kal_bool enable);
extern kal_bool pmu6236_va_status(void);

// (0x824) VA_CON1
extern void pmu6236_va_cal(kal_uint8 val);

// (0x830) VCAMA_CON0
extern void pmu6236_vcama_enable(kal_bool enable);
extern void pmu6236_vcama_vosel(pmu6236_vcama_vosel_enum sel);
extern void pmu6236_vcama_ndis_enable(kal_bool enable);
extern void pmu6236_vcama_stb_enable(kal_bool enable);
extern void pmu6236_vcama_oc_auto_off(kal_bool enable);
extern void pmu6236_vcama_ocfb_enable(kal_bool enable);
extern kal_bool pmu6236_vcama_status(void);

// (0x834) VCAMA_CON1
extern void pmu6236_vcama_cal(kal_uint8 val);

// (0x838) VCAMA CON2
extern void pmu6236_vcama_oc_td(pmu6236_oc_td_enum sel);
extern void pmu6236_vcama_stb_td(pmu6236_stb_td_enum sel);

// (0x840) VCAMD_CON0
extern void pmu6236_vcamd_enable(kal_bool enable);
extern void pmu6236_vcamd_vosel(pmu6236_vcamd_vosel_enum sel);
extern void pmu6236_vcamd_ndis_enable(kal_bool enable);
extern void pmu6236_vcamd_stb_enable(kal_bool enable);
extern void pmu6236_vcamd_oc_auto_off(kal_bool enable);
extern void pmu6236_vcamd_ocfb_enable(kal_bool enable);
extern kal_bool pmu6236_vcamd_status(void);

// (0x844) VCAMD_CON1
extern void pmu6236_vcamd_cal(kal_uint8 val);

// (0x850) VIO_CON0
extern void pmu6236_vio_sense(pmu6236_sense_enum sel);
extern void pmu6236_vio_ndis_enable(kal_bool enable);
extern void pmu6236_vio_stb_enable(kal_bool enable);
extern void pmu6236_vio_oc_auto_off(kal_bool enable);
extern void pmu6236_vio_ocfb_enable(kal_bool enable);
extern kal_bool pmu6236_vio_status(void);

// (0x854) VIO_CON1
extern void pmu6236_vio_cal(kal_uint8 val);

// (0x858) VIO_CON2
extern void pmu6236_vio_oc_td(pmu6236_oc_td_enum sel);

// (0x860) VUSB_CON0
extern void pmu6236_vusb_enable(kal_bool enable);
extern void pmu6236_vusb_ndis_enable(kal_bool enable);
extern void pmu6236_vusb_stb_enable(kal_bool enable);
extern void pmu6236_vusb_oc_auto_off(kal_bool enable);
extern void pmu6236_vusb_ocfb_enable(kal_bool enable);
extern kal_bool pmu6236_vusb_status(void);

// (0x864) VUSB_CON1
extern void pmu6236_vusb_cal(kal_uint8 val);

// (0x868) VUSB_CON2
extern void pmu6236_vusb_oc_td(pmu6236_oc_td_enum sel);

// (0x870) VBT_CON0
extern void pmu6236_vbt_enable(kal_bool enable);
extern void pmu6236_vbt_vosel(pmu6236_vbt_sel_enum sel);
extern void pmu6236_vbt_ndis_enable(kal_bool enable);
extern void pmu6236_vbt_stb_enable(kal_bool enable);
extern void pmu6236_vbt_oc_auto_off(kal_bool enable);
extern void pmu6236_vbt_ocfb_enable(kal_bool enable);
extern kal_bool pmu6236_vbt_status(void);

// (0x874) VBT_CON1
extern void pmu6236_vbt_cal(kal_uint8 val);

// (0x878) VBT_CON2
extern void pmu6236_vbt_oc_td(pmu6236_oc_td_enum sel);

// (0x880) VSIM_CON0
extern void pmu6236_vsim_enable(kal_bool enable);
extern void pmu6236_vsim_vosel(pmu6236_vsim_vosel_enum sel);
extern void pmu6236_vsim_ndis_enable(kal_bool enable);
extern void pmu6236_vsim_stb_enable(kal_bool enable);
extern void pmu6236_vsim_oc_auto_off(kal_bool enable);
extern void pmu6236_vsim_ocfb_enable(kal_bool enable);
extern kal_bool pmu6236_vsim_status(void);

// (0x884) VSIM_CON1
extern void pmu6236_vsim_cal(kal_uint8 val);

// (0x888) VSIM_CON2
extern void pmu6236_vsim_oc_td(pmu6236_oc_td_enum sel);

// (0x890) VSIM2_CON0
extern void pmu6236_vsim2_enable(kal_bool enable);
extern void pmu6236_vsim2_vosel(pmu6236_vsim2_vosel_enum sel);
extern void pmu6236_vsim2_ndis_enable(kal_bool enable);
extern void pmu6236_vsim2_stb_enable(kal_bool enable);
extern void pmu6236_vsim2_oc_auto_off(kal_bool enable);
extern void pmu6236_vsim2_ocfb_enable(kal_bool enable);
extern kal_bool pmu6236_vsim2_status(void);

// (0x894) VSIM2_CON1
extern void pmu6236_vsim2_cal(kal_uint8 val);

// (0x898) VSIM2_CON2
extern void pmu6236_vsim2_gpldo_en(kal_bool enable);

// (0x8A0) VBACKUP_CON0
extern void pmu6236_vbackup_enable(kal_bool enable);
extern void pmu6236_vbackup_ndis_enable(kal_bool enable);
extern void pmu6236_vbackup_stb_enable(kal_bool enable);
extern void pmu6236_vbackup_oc_auto_off(kal_bool enable);
extern void pmu6236_vbackup_ocfb_enable(kal_bool enable);
extern kal_bool pmu6236_vbackup_status(void);

// (0x8B0) VIBR_CON0
extern void pmu6236_vibr_enable(kal_bool enable);
extern void pmu6236_vibr_vosel(pmu6236_vibr_vosel_enum sel);
extern void pmu6236_vibr_ndis_enable(kal_bool enable);
extern void pmu6236_vibr_stb_enable(kal_bool enable);
extern void pmu6236_vibr_oc_auto_off(kal_bool enable);
extern void pmu6236_vibr_ocfb_enable(kal_bool enable);
extern kal_bool pmu6236_vibr_status(void);

// (0x8B4) VIBR_CON1
extern void pmu6236_vibr_cal(kal_uint8 val);

// (0x8C0) VMC_CON0
extern void pmu6236_vmc_enable(kal_bool enable);
extern void pmu6236_vmc_vosel(pmu6236_vmc_vosel_enum sel);
extern void pmu6236_vmc_ndis_enable(kal_bool enable);
extern void pmu6236_vmc_stb_enable(kal_bool enable);
extern void pmu6236_vmc_oc_auto_off(kal_bool enable);
extern void pmu6236_vmc_ocfb_enable(kal_bool enable);
extern kal_bool pmu6236_vmc_status(void);

// (0x8C4) VMC_CON1
extern void pmu6236_vmc_cal(kal_uint8 val);

// (0x900) VCORE_CON0
extern void pmu6236_vcore_enable(kal_bool enable);
extern void pmu6236_vcore_sense(pmu6236_sense_enum sel);
extern void pmu6236_vcore_vfbadj(pmu6236_vcore_vfbadj_enum sel);
extern kal_uint16 pmu6236_get_vcore_vfbadj(void);
extern void pmu6236_vcore_stb_enable(kal_bool enable);
extern void pmu6236_vcore_oc_auto_off(kal_bool enable);
extern void pmu6236_vcore_ocfb_enable(kal_bool enable);
extern kal_bool pmu6236_vcore_status(void);

// (0x904) VCORE_CON1
extern void pmu6236_vcore_modeset(pmu6236_vcore_modeset_enum mode);
extern void pmu6236_vcore_vfbadj_slp(pmu6236_vcore_vfbadj_enum sel);
extern kal_uint16 pmu6236_get_vcore_vfbadj_slp(void);

// (0x908) VCORE_CON2
extern void pmu6236_vcore_vosel(pmu6236_vcore_vosel_enum sel);
extern void pmu6236_vcore_cal(kal_uint8 val);

// (0x90C) VCORE_CON3
extern void pmu6236_vcore_ical_en(kal_uint8 sel);

// (0x914) VCORE_CON5
extern void pmu6236_vcore_csl(pmu6236_vcore_csl_enum sel);
extern void pmu6236_vcore_burst(pmu6236_vcore_burst_enum sel);

// (0x920) VM_CON0
extern void pmu6236_vm_sense(pmu6236_sense_enum sel);
extern void pmu6236_vm_stb_enable(kal_bool enable);
extern void pmu6236_vm_oc_auto_off(kal_bool enable);
extern void pmu6236_vm_ocfb_enable(kal_bool enable);
extern kal_bool pmu6236_vm_status(void);

// (0x928) VM_COM2
extern void pmu6236_vm_cal(kal_uint8 val);

// (0x92C) VM_CON3
extern void pmu6236_vm_ical_en(kal_uint8 sel);

// (0x934) VM_CON5
extern void pmu6236_vm_csl(pmu6236_vm_csl_enum val);
extern void pmu6236_vm_burst(pmu6236_vm_burst_enum val);

// (0xA00) CHR_CON0
extern void pmu6236_chr_vcdt_lv_vth(kal_uint8 val);
extern void pmu6236_chr_vcdt_hv_vth(kal_uint8 val);
extern void pmu6236_chr_vcdt_hv_enable(kal_bool enable);
extern void pmu6236_chr_enable(kal_bool enable);
extern kal_bool pmu6236_chr_chrdet(void);
extern kal_bool pmu6236_chr_ovp(void);

// (0xA04) CHR_CON1
extern void pmu6236_chr_vbat_cv_vth(pmu6236_chr_vbat_cv_enum cv);
extern void pmu6236_chr_vbat_cc_vth(pmu6236_chr_vbat_cc_enum cc);
extern void pmu6236_chr_vbat_cv_enable(kal_bool enable);
extern void pmu6236_chr_vbat_cc_enable(kal_bool enable);
extern kal_bool pmu6236_chr_cv_det(void);
extern kal_bool pmu6236_chr_cc_det(void);

// (0xA08) CHR_CON2
extern void pmu6236_chr_cs_enable(kal_bool enable);
extern void pmu6236_chr_current(pmu6236_chr_current_enum sel);

// (0xA0C) CHR_CON3
extern void pmu6236_chr_csdac_dly(kal_uint32 sel);
extern void pmu6236_chr_csdac_stp(kal_uint32 sel);

// (0xA14) CHR_CON5
extern kal_uint16 pmu6236_chr_control_state(kal_uint16 sel);
extern pmu6236_pchr_state_enum pmu6236_get_pchr_state(void);

// (0xA18) CHR_CON6
extern void pmu6236_chr_wdt_td(pmu6236_chr_wdt_td_enum sel);
extern void pmu6236_chr_wdt_enable(kal_bool enable);

// (0xA1C) CHR_CON7
extern void pmu6236_chr_wdt_intr_enable(kal_bool enable);
extern kal_bool pmu6236_chr_wdt_status(void);
extern void pmu6236_chr_wdt_clear(void);

// (0xA20) CHR_CON8
extern void pmic6236_chr_adc_meas_on(kal_bool enable);

// (0xB00) BOOST_CON0
extern void pmu6236_vboost_enable(kal_bool enable);
extern kal_bool pmu6236_get_vboost_enable(void);
extern void pmu6236_vboost_type(pmu6236_vboost_type_enum sel);
extern pmu6236_vboost_type_enum pmu6236_get_vboost_type(void);
extern void pmu6236_vboost_mode(pmu6236_vboost_mode_enum sel);
extern pmu6236_vboost_mode_enum pmu6236_get_vboost_mode(void);
extern void pmu6236_vboost_vrsel(kal_uint16 val);
extern kal_uint16 pmu6236_get_vboost_vrsel(void);

// (0xB0C) BOOST_CON3
extern void pmu6236_vboost_cks_prg(kal_uint8 val);

// (0xC00) ISINK0_CON0
extern void pmu6236_isink0_enable(kal_bool enable);
extern void pmu6236_isink0_mode(pmu6236_isink_mode_enum sel);
extern void pmu6236_isink0_step(pmu6236_isink_step_enum sel);
extern kal_bool pmu6236_isink0_status(void);

// (0xC10) ISINK1_CON0
extern void pmu6236_isink1_enable(kal_bool enable);
extern void pmu6236_isink1_mode(pmu6236_isink_mode_enum sel);
extern void pmu6236_isink1_step(pmu6236_isink_step_enum sel);
extern kal_bool pmu6236_isink1_status(void);

// (0xC20) ISINK2_CON0
extern void pmu6236_isink2_enable(kal_bool enable);
extern void pmu6236_isink2_mode(pmu6236_isink_mode_enum sel);
extern void pmu6236_isink2_step(pmu6236_isink_step_enum sel);
extern kal_bool pmu6236_isink2_status(void);

// (0xC30) ISINK3_CON0
extern void pmu6236_isink3_enable(kal_bool enable);
extern void pmu6236_isink3_mode(pmu6236_isink_mode_enum sel);
extern void pmu6236_isink3_step(pmu6236_isink_step_enum sel);
extern kal_bool pmu6236_isink3_status(void);

// (0xC40) ISINK4_CON0
extern void pmu6236_isink4_enable(kal_bool enable);
extern void pmu6236_isink4_mode(pmu6236_isink_mode_enum sel);
extern void pmu6236_isink4_step(pmu6236_isink_step_enum sel);
extern kal_bool pmu6236_isink4_status(void);

// (0x0C80) KPLED_CON0
extern void pmu6236_kpled_enable(kal_bool enable);
extern void pmu6236_kpled_mode(pmu6236_kpled_mode_enum sel);
extern void pmu6236_kpled_sel(kal_uint8 val);
extern kal_bool pmu6236_kpled_status(void);

// (0x0C90) FLASH_CON0
extern void pmu6236_flash_enable(kal_bool enable);
extern void pmu6236_flash_mode(pmu6236_flash_mode_enum sel);
extern void pmu6236_flash_sel(kal_uint8 sel);
extern kal_bool pmu6236_flash_status(void);

// (0xD00) SPK_CON0
extern void pmu6236_spk_enable(kal_bool enable);
extern kal_bool pmu6236_get_spk_enable(void);
extern void pmu6236_spk_vol(pmu6236_spk_vol_enum val);
extern pmu6236_spk_vol_enum pmu6236_get_spk_vol(void);
extern void pmu6236_spk_ocfb_enable(kal_bool enable);

// (0xE00) PMIC_OC_CON0
extern void pmu6236_vrf_oc_int_enable(kal_bool enable);
extern void pmu6236_vtcxo_oc_int_enable(kal_bool enable);
extern void pmu6236_va_oc_int_enable(kal_bool enable);
extern void pmu6236_vcama_oc_int_enable(kal_bool enable);
extern void pmu6236_vcamd_oc_int_enable(kal_bool enable);
extern void pmu6236_vio_oc_int_enable(kal_bool enable);
extern void pmu6236_vusb_oc_int_enable(kal_bool enable);
extern void pmu6236_vbt_oc_int_enable(kal_bool enable);
extern void pmu6236_vsim_oc_int_enable(kal_bool enable);
extern void pmu6236_vsim2_oc_int_enable(kal_bool enable);
extern void pmu6236_vbackup_oc_int_enable(kal_bool enable);
extern void pmu6236_vibr_oc_int_enable(kal_bool enable);
extern void pmu6236_vmc_oc_int_enable(kal_bool enable);

// (0xE04) PMIC_OC_CON1
extern void pmu6236_vcore_oc_int_enable(kal_bool enable);
extern void pmu6236_vm_oc_int_enable(kal_bool enable);

// Other exported APIs
extern void pmu6236_init(void);
extern pmu6236_chr_current_enum pmu6236_ret_chr_current(void);
extern pmu6236_chr_current_enum pmu6236_ret_usb_current(void);
extern void pmu6236_init_bl(pmu6236_bl_mode_enum bl_mode);
extern void pmu6236_enable_bl(kal_bool enable);
extern void pmu6236_EM_reg_write(kal_uint32 reg, kal_uint16 val);
extern kal_uint16 pmu6236_EM_reg_read(kal_uint32 reg);
#if defined(PMIC_6236_CV_TRIM_CALIBRATION)
extern pmu6236_chr_vbat_cv_enum mt6236_efuse_vbat_cv;
#endif // #if defined(PMIC_6236_CV_TRIM_CALIBRATION)
*/

// The following are implemented in custom files
// MoDIS parser skip start
// MoDIS parser skip end


/*
typedef enum
{
	PMU_FAKE_LDO_BUCK_MAX
}PMU_FAKE_LDO_BUCK_LIST_ENUM;


typedef enum
{
	VRF,
	VTCXO,
	VA,
	VCAMA,
	VCAMD,
	VIO,
	VUSB,
	VBT,
	VSIM,
	VSIM2,
	VBACKUP,
	VIBR,
	VMC,
	VCORE,
	VM,
	PMU_LDO_BUCK_MAX,
	VRF18,
	VFM
}PMU_LDO_BUCK_LIST_ENUM;

typedef enum
{
	VPA1,
	PMU_VPA_MAX
}PMU_VPA_LIST_ENUM;

typedef enum
{
	CHR,
	PMU_CHR_MAX
}PMU_CHR_LIST_ENUM;

typedef enum
{
	SPK,
	SPKL,
	SPKR,
	PMU_SPK_MAX
}PMU_SPK_LIST_ENUM;

typedef enum
{
	ISINK0,
	ISINK1,
	ISINK2,
	ISINK3,
	ISINK4,
	PMU_ISINK_MAX
}PMU_ISINK_LIST_ENUM;

typedef enum
{
	BOOST1,
	BOOST2,
	PMU_BOOST_MAX
}PMU_BOOST_LIST_ENUM;
*/


#endif // #ifdef PMIC_6236_REG_API
#endif // #ifndef __DCL_PMU6236_SW_H_STRUCT__



