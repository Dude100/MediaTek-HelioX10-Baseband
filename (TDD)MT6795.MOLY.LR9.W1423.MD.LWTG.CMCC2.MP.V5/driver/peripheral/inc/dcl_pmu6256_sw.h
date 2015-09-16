/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *    dcl_pmu6256_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMU6256 s/w setting.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __DCL_PMU6256_SW_H_STRUCT__
#define __DCL_PMU6256_SW_H_STRUCT__

#include "dcl_pmic_features.h"

#if defined(PMIC_6256_REG_API)

/* Charger external interrupt is fixed. */
#define PMU_CHR_EINT_PIN         15
#define PMU_OC_EINT_PIN          16
#define PMU_CHR_OVP_EINT_PIN     17
#define PMU_CHR_LDO_EINT_PIN     19

/* adc number for measuring VBAT/VISENSE/VCHARGER is fixed internally. */
#define PMU_ADC_VBAT_CH_NUM      0
#define PMU_ADC_VISENSE_CH_NUM   1
#define PMU_ADC_VCHARGER_CH_NUM  2
#define PMU_ADC_VBATTEMP_CH_NUM  3

/* adc factor for VBAT/VISENSE/VCHARGER */
#define PMU_ADC_FACTOR_VBAT      100
#define PMU_ADC_FACTOR_VISENSE   100
#if defined(MT6256_S00)
#define PMU_ADC_FACTOR_VCHARGER  344  // (351/51 * 50)
#else
#define PMU_ADC_FACTOR_VCHARGER  473  // (369/39 * 50)
#endif // End of #if defined(MT6256_S00)
#define PMU_ADC_FACTOR_VBATTEMP  100

typedef enum
{
	LDO_BUCK_EN,
    LDO_BUCK_ON_SEL,
  	LDO_BUCK_RS,
	LDO_BUCK_VOL_SEL,
	LDO_BUCK_NDIS_EN,
    LDO_BUCK_STB_EN,  
	LDO_BUCK_OC_AUTO_OFF,
    LDO_BUCK_OCFB_EN,
    LDO_BUCK_OC_FLAG,
    LDO_BUCK_STATUS,
	LDO_CAL,
	LDO_STB_SEL,
	LDO_EN_FORCE,
	LDO_OC_TD,
	LDO_STB_TD,
	CCI_SRCLKEN,
	VA_LP_EN,
	VSIM_GPLDO_EN,
	VSIM2_GPLDO_EN,	
	SIM2_GPIO_EN,
	BUCK_VFBADJ_SLEEP,
	BUCK_EN_FORCE,
	BUCK_STB_TD,
	BUCK_OC_THD,
	BUCK_OC_WND,
	BUCK_ICAL_EN,
	BUCK_CSL,
	BUCK_BURST,
	VCDT_HV_EN,
//	CHR_LDO_DET,
	CSDAC_EN,
	CHR_EN,
	CHRDET,
	VCDT_HV_VTH,
    VBAT_CV_EN,
    VBAT_CV_DET,
    VBAT_CV_VTH,
    CS_VTH,
    CSDAC_STP_INC,
    CSDAC_STP_DEC,
    CSDAC_STP,
    CSDAC_DLY,
    VBAT_OV_VTH,
    BATON_EN,
    BATON_HT_EN,
	BATON_UNDET,
    OTG_BVALID_EN,
    OTG_BVALID,
	CHRWDT_TD,
	CHRWDT_EN,
	CHRWDT_INT_EN,
	CHRWDT_FLAG,
	ADC_EN,
	USBDL_RST,
	USBDL_SET,
	BC11_CMP_EN,
	BC11_VSRC_EN,
	BC11_IPD_EN,
	BC11_IPU_EN,
	BC11_VREF_VTH,
	BC11_BIAS_EN,
	BC11_BB_CTRL,
	BC11_RST,
	BC11_CMP_OUT,
	CV_MODE,
	VCDT_MODE,
	CSDAC_MODE,
	TRACKING_EN,
	HWCV_EN,
	ULC_DET_EN,
	LOW_ICH_DB,
	USBDL_EN,
	VBAT_CC_DET,
	ISINK_EN,
	ISINK_MODE,
	ISINK_STEP,
	KPLED_EN,
	KPLED_MODE,
	KPLED_SEL,
	SPK_EN,
	SPK_VOL,
    SPK_CCODE,	
    SPK_OC_EN,
	SPK_PG_SLEW_I,
	SPKAB_OC_EN,
    SPKAB_OBIAS,	
	SPKMODE,
    SPK_CALIBR_EN,
    SPK_CALIBR_SEL,
    ABIST_LMON_SEL,
    ABIST_HMON_SEL,    
    ABIST_LMON_DATA,
    ABIST_HMON_DATA,
    VRF_OC_INT_EN,
    VTCXO_OC_INT_EN,
    VA_OC_INT_EN,
    VCAMA_OC_INT_EN,
    VCAMD_OC_INT_EN,
    VIO28_OC_INT_EN,
    VUSB_OC_INT_EN,
    VBT_OC_INT_EN,
    VSIM_OC_INT_EN,
    VSIM2_OC_INT_EN,
    VRTC_OC_INT_EN,
    VIBR_OC_INT_EN,
    VMC_OC_INT_EN,
    VCORE_OC_INT_EN,
    VIO18_OC_INT_EN,
    SPK_OC_INT_EN,
    VRF_OC_FLAG,
    VTCXO_OC_FLAG,
    VA_OC_FLAG,
    VCAMA_OC_FLAG,
    VCAMD_OC_FLAG,
    VIO28_OC_FLAG,
    VUSB_OC_FLAG,
    VBT_OC_FLAG,
    VSIM_OC_FLAG,
    VSIM2_OC_FLAG,
    VRTC_OC_FLAG,
    VIBR_OC_FLAG,
    VMC_OC_FLAG,
    VCORE_OC_FLAG,
    VIO18_OC_FLAG,
    SPK_OC_FLAG, 
    VRF_OC_STATUS,
    VTCXO_OC_STATUS,    
	VA_OC_STATUS,
	VCAMA_OC_STATUS,
	VCAMD_OC_STATUS,
	VIO28_OC_STATUS,
	VUSB_OC_STATUS,
	VBT_OC_STATUS,
	VSIM_OC_STATUS,
	VSIM2_OC_STATUS,
	VRTC_OC_STATUS,
	VIBR_OC_STATUS,
	VMC_OC_STATUS,
	VCORE_OC_STATUS,
	VIO18_OC_STATUS,
	SPK_OC_STATUS,	       
	PMU_FLAGS_MAX
}PMU_FLAGS_LIST_ENUM;

#define LDO_GROUP (OFFSEL(BUCK_GROUP))
#if defined(MT6256_S00)
#define BUCK_GROUP (M(VCORE)|M(VIO18))
#else
#define BUCK_GROUP (M(VCORE))
#endif // End of #if defined(MT6256_S00)

#endif //#if defined(PMIC_6256_REG_API)

#endif //#ifndef __DCL_PMU6256_SW_H_STRUCT__

