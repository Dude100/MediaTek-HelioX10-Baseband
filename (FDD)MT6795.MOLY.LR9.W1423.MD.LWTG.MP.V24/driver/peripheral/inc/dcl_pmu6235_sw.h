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
 *    dcl_pmu6235_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMU6235
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __DCL_PMU6235_SW_H_STRUCT__
#define __DCL_PMU6235_SW_H_STRUCT__


#if defined(PMIC_6235_REG_API) || defined(PMIC_6238_REG_API)

//workaround till pmu_sw.h is removed
#if !defined(PMU6235_OLD_STR)
#define PMU6235_OLD_STR

typedef enum 
{
	ICAL_RF_1_0=0,
	ICAL_RF_0_5=1,
	ICAL_RF_2_0=2,
	ICAL_RF_3_0=3
}pmu_icalrf_code;

typedef enum 
{
	ICAL_CORE_1_0=0,
	ICAL_CORE_0_5=1,
	ICAL_CORE_2_0=2,
	ICAL_CORE_3_0=3
}pmu_icalcore_code;

typedef enum 
{
	ICAL_IO_1_0=0,
	ICAL_IO_0_5=1,
	ICAL_IO_2_0=2,
	ICAL_IO_3_0=3
}pmu_icalio_code;

typedef enum 
{
	ICAL_M_1_0=0,
	ICAL_M_0_5=1,
	ICAL_M_2_0=2,
	ICAL_M_3_0=3
}pmu_icalm_code;

typedef enum 
{
	ICAL_SIM_1_0=0,
	ICAL_SIM_0_5=1,
	ICAL_SIM_2_0=2,
	ICAL_SIM_3_0=3
}pmu_icalsim_code;

typedef enum 
{   
   VSIM_SEL_1_8=0,
   VSIM_SEL_3_0
}pmu_vsim_volt;



typedef enum 
{
   CHR_CUR_OFFSET_NONE=0,
   CHR_CUR_OFFSET_PLUS_1=1,
   CHR_CUR_OFFSET_PLUS_2=2,
   CHR_CUR_OFFSET_MINUS_2=6,
   CHR_CUR_OFFSET_MINUS_1=7
}pmu_chr_cur_offset;

typedef enum 
{
   CHR_CUR_50=0,
   CHR_CUR_87_5=1,
   CHR_CUR_150=2,
   CHR_CUR_225=3,
   CHR_CUR_300=4,
   CHR_CUR_450=5,
   CHR_CUR_650=6,
   CHR_CUR_800=7
}pmu_chr_cur_level;


typedef enum 
{
   THERMAL_THRES_INIT=0x0000,
   THERMAL_THRES_PLUS_10C=0x0001,
   THERMAL_THRES_MINUS_20C=0x0010,
   THERMAL_THRES_MINUS_10C=0x0011
}pmu_chr_thermal_thres;

typedef enum 
{
   VOLT_STEP_INIT=0,
   VOLT_STEP_MINUS_1=1,
   VOLT_STEP_MINUS_2=2,
   VOLT_STEP_MINUS_3=3,
   VOLT_STEP_PLUS_4=4,
   VOLT_STEP_PLUS_3=5,
   VOLT_STEP_PLUS_2=6,
   VOLT_STEP_PLUS_1=7
}pmu_ref_volt_step;

typedef enum 
{
   VBG_VOLT_1_2_V = 0,
   VBG_VOLT_1_205_V = 1,
   VBG_VOLT_1_210_V = 2,
   VBG_VOLT_1_215_V = 3,
   VBG_VOLT_1_180_V = 4,
   VBG_VOLT_1_185_V = 5,
   VBG_VOLT_1_190_V = 6,
   VBG_VOLT_1_195_V = 7
}pmu_vbg_volt;

typedef enum 
{
   GPIO_DRV_8MA = 0,
   GPIO_DRV_4MA = 1
}pmu_gpio_drv_strength;

typedef enum 
{
   UVLO_VOLT_2_9_V=0,
   UVLO_VOLT_2_75_V=1,
   UVLO_VOLT_2_6_V=2,
   UVLO_VOLT_AS_DDLO=3
}pmu_uvlo_volt;

typedef enum 
{
   RBGSEL_INIT=0,
   RBGSEL_PLUS_1_STEP=1,
   RBGSEL_PLUS_2_STEP=2,
   RBGSEL_PLUS_3_STEP=3,
   RBGSEL_MINUS_4_STEP=4,
   RBGSEL_MINUS_3_STEP=5,
   RBGSEL_MINUS_2_STEP=6,
   RBGSEL_MINUS_1_STEP=7
}pmu_rbgsel;

typedef enum 
{
   IBGSEL_INIT=0,
   IBGSEL_PLUS_1_STEP=1,
   IBGSEL_MINUS_2_STEP=2,
   IBGSEL_MINUS_1_STEP=3
}pmu_ibgsel;

typedef enum 
{
   CK_SEL_10KHZ=0,
   CK_SEL_5KHZ=1
}pmu_cksel;

typedef enum 
{
   VBS_SEL_1200K=0,
   VBS_SEL_1320K=1,
   VBS_SEL_960K=2,
   VBS_SEL_1080K=3
}pmu_vbssel;

typedef enum 
{
   OV_HYS_ENB_LOWER=0,
   OV_HYS_ENB_HIGHER=1
}pmu_ov_hys_enb;

typedef enum 
{
   OV_THFREEZE_AUTO=0,
   OV_THFREEZE_FIXED=1
}pmu_ov_thfreeze;

typedef enum 
{
   SDM_1ST_ORDER = 0,
   SDM_2ND_ORDER = 1
}pmu_sdm_order;

typedef enum 
{
   PID_GAIN_P_0_25 = 0,
   PID_GAIN_P_0_375 = 1,
   PID_GAIN_P_0_5 = 2,
   PID_GAIN_P_0_75 = 3,
   PID_GAIN_P_1 = 4,
   PID_GAIN_P_1_5 = 5,
   PID_GAIN_P_2 = 6,
   PID_GAIN_P_3 = 7
}pmu_pid_gain_p;

typedef enum 
{
   PID_GAIN_0_015625 = 0,
   PID_GAIN_0_0234375 = 1,
   PID_GAIN_0_03125 = 2,
   PID_GAIN_0_046875 = 3,
   PID_GAIN_0_0625 = 4,
   PID_GAIN_0_09375 = 5,
   PID_GAIN_0_125 = 6,
   PID_GAIN_0_1875 = 7
}pmu_pid_gain;

typedef enum 
{
   PID_GAIN_D_2 = 0,
   PID_GAIN_D_3 = 1,
   PID_GAIN_D_4 = 2,
   PID_GAIN_D_6 = 3,
   PID_GAIN_D_8 = 4,
   PID_GAIN_D_12 = 5,
   PID_GAIN_D_16 = 6,
   PID_GAIN_D_24 = 7
}pmu_pid_gain_d;

typedef enum 
{
   VCORE_1_8V = 0,
   VCORE_1_2V = 1
}pmu_vcore_volt;

typedef enum 
{
   DCV_INTERNAL = 0,
   DCV_CLK_TCXO = 1
}pmu_dcv_ck;

typedef enum 
{
   ISEL_0_25 = 0,
   ISEL_1_5 = 1,
   ISEL_1 = 2,
   ISEL_2 = 3
}pmu_isel;

typedef enum 
{
   MODE_SET_PWM = 0,
   MODE_SET_PFM = 1
}pmu_mode_set;

typedef enum 
{
   MODE_CMP_LOW_OFFSET = 0,
   MODE_CMP_AUTO_ZERO = 1
}pmu_mode_cmp;

typedef enum 
{
   MODE_NDC = 0,
   MODE_AVE_CURRENT = 1
}pmu_mode_ave_current;

#endif //#if !defined(PMU6235_OLD_STR)

/* PFM max load current select. Can OR together. */
#define   PFM_MAX_160_MA_EN  0x08
#define   PFM_MAX_80_MA_EN   0x04
#define   PFM_MAX_40_MA_EN   0x02
#define   PFM_MAX_20_MA_EN   0x01

/* PFM max load resistor select. Can OR together*/
#define   PFM_RESISTOR_50_OHM 0x04
#define   PFM_RESISTOR_100_OHM 0x02
#define   PFM_RESISTOR_200_OHM 0x01

typedef enum 
{
   NDC_OFFSET_MINUS_3mV = 0,
   NDC_OFFSET_5mV = 1,
   NDC_OFFSET_12mV = 2,
   NDC_OFFSET_17mV = 3
}pmu_ndc_offset;

typedef enum 
{
   IASEL_50mV = 0,
   IASEL_100mV = 1,
   IASEL_150mV = 2,
   IASEL_200mV = 3
}pmu_iasel;

typedef enum 
{
   RSEL_32k = 0,
   RSEL_28k = 1,
   RSEL_24k = 2,
   RSEL_18k = 3
}pmu_rsel;

typedef enum 
{
	ICAL_USB_1_0=0,
	ICAL_USB_0_5=1,
	ICAL_USB_2_0=2,
	ICAL_USB_3_0=3
}pmu_icalusb_code;

typedef enum 
{
	CLK_SRC_FROM_CLKSQ=0,
	CLK_SRC_FROM_TCXO26M_CK=1
}pmu_clk_src_sel;

typedef enum 
{
	VTCXO_LDO_WITH_VTCXO_EN=0,
	VTCXO_LDO_WITH_RG_VTCXO_EN=1
}pmu_vtcxo_on_sel;

typedef enum 
{
	ICAL_SIM2_1_0=0,
	ICAL_SIM2_0_5=1,
	ICAL_SIM2_2_0=2,
	ICAL_SIM2_3_0=3
}pmu_icalsim2_code;

//typedef enum 
//{
//	ICAL_MC_1_0=0,
//	ICAL_MC_0_5=1,
//	ICAL_MC_2_0=2,
//	ICAL_MC_3_0=3
//}pmu_icalmc_code;
// vmc related items are changed as vbt
typedef enum 
{
	ICAL_BT_1_0=0,
	ICAL_BT_0_5=1,
	ICAL_BT_2_0=2,
	ICAL_BT_3_0=3
}pmu_icalbt_code;

//typedef enum 
//{   
//   VMC_SEL_1_8=0,
//   VMC_SEL_3_0
//}pmu_vmc_volt;
// vmc related items are changed as vbt
typedef enum 
{   
   VBT_SEL_2_8=0,
   VBT_SEL_3_0
}pmu_vbt_volt;

//typedef enum 
//{
//	ICAL_CAMERA_1_0=0,
//	ICAL_CAMERA_0_5=1,
//	ICAL_CAMERA_2_0=2,
//	ICAL_CAMERA_3_0=3
//}pmu_icalcamera_code;
// vcamera ==> vcam_d
typedef enum 
{
	ICAL_CAM_D_1_0=0,
	ICAL_CAM_D_0_5=1,
	ICAL_CAM_D_2_0=2,
	ICAL_CAM_D_3_0=3
}pmu_icalcam_d_code;

//typedef enum 
//{   
//   VCAMERA_SEL_1_3=0,
//   VCAMERA_SEL_1_5=1,
//   VCAMERA_SEL_1_8=2,
//   VCAMERA_SEL_2_8=3
//}pmu_vcamera_volt;
// vcamera ==> vcam_d
typedef enum 
{   
   VCAM_D_SEL_1_3=0,
   VCAM_D_SEL_1_5=1,
   VCAM_D_SEL_1_8=2,
   VCAM_D_SEL_2_8=3
}pmu_vcam_d_volt;

//typedef enum 
//{
//	ICAL_SW_1_0=0,
//	ICAL_SW_0_5=1,
//	ICAL_SW_2_0=2,
//	ICAL_SW_3_0=3
//}pmu_icalsw_code;
typedef enum 
{
	ICAL_CAM_A_1_0=0,
	ICAL_CAM_A_0_5=1,
	ICAL_CAM_A_2_0=2,
	ICAL_CAM_A_3_0=3
}pmu_icalcam_a_code;

//typedef enum 
//{   
//   VSW_A_SEL_1_3=0,
//   VSW_A_SEL_1_5=1,
//   VSW_A_SEL_1_8=2,
//   VSW_A_SEL_2_8=3
//}pmu_vsw_a_volt;
typedef enum 
{   
   VCAM_A_SEL_1_3=0,
   VCAM_A_SEL_1_5=1,
   VCAM_A_SEL_1_8=2,
   VCAM_A_SEL_2_8=3
}pmu_vcam_a_volt;

typedef enum 
{
	ICAL_A_1_0=0,
	ICAL_A_0_5=1,
	ICAL_A_2_0=2,
	ICAL_A_3_0=3
}pmu_icala_code;

typedef enum 
{
	ICAL_TCXO_1_0=0,
	ICAL_TCXO_0_5=1,
	ICAL_TCXO_2_0=2,
	ICAL_TCXO_3_0=3
}pmu_icaltcxo_code;

typedef enum 
{
	VREF_BG_INIT=0,
	VREF_BG_PLUS_1_STEP=1,
	VREF_BG_PLUS_2_STEP=2,
	VREF_BG_PLUS_3_STEP=3,
   VREF_BG_MINUS_4_STEP=4,
   VREF_BG_MINUS_3_STEP=5,
   VREF_BG_MINUS_2_STEP=6,
   VREF_BG_MINUS_1_STEP=7
}pmu_vref_bg;

typedef enum 
{
	THR_SEL_INIT=0,
	THR_SEL_PLUS_10C=1,
	THR_SEL_MINUS_20C=2,
	THR_SEL_MINUS_10C=3
}pmu_thr_sel;

#define PMU_ADC_VISENSE_CH_NUM   4
#define PMU_ADC_VBAT_CH_NUM      5
#define PMU_ADC_VCHARGER_CH_NUM  6

#define PMU_ADC_FACTOR_VBAT      100
#define PMU_ADC_FACTOR_VISENSE   100
#define PMU_ADC_FACTOR_VCHARGER  250

#define PMU_BMT_CV_TARGET_VOLTAGE	PMU_VOLT_04_200000_V	

#if defined(PMIC_FIXED_CHR_EINT)
#define PMU_CHR_EINT_PIN      8
#endif // #if defined(PMIC_FIXED_CHR_EINT)

/*
typedef enum
{
	VCORE,
	VIO,
	VRF,
	VA,
	VRTC,
	VM,
	VSIM,
	VTCXO,
	VSIM2,
	VUSB,
	VBT,
	VCAMA,
	VCAMD,
	PMU_LDO_BUCK_MAX,
	VMC,
	VIBR,
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
	KPLED,
	PMU_KPLED_MAX
}PMU_KPLED_LIST_ENUM;

typedef enum
{
	CHR,
	PMU_CHR_MAX
}PMU_CHR_LIST_ENUM;

typedef enum
{
	PMU_ISINK_MAX
}PMU_ISINK_LIST_ENUM;

typedef enum
{
	PMU_BOOST_MAX
}PMU_BOOST_LIST_ENUM;

typedef enum
{
	PMU_SPK_MAX
}PMU_SPK_LIST_ENUM;
*/

#endif //#if defined(PMIC_6235_REG_API)
#endif //#ifndef __DCL_PMU6255_SW_H_STRUCT__








