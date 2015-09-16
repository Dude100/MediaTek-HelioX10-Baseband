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
 *    dcl_pmu6252_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMU6252
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DCL_PMU6252_SW_H_STRUCT__
#define __DCL_PMU6252_SW_H_STRUCT__

#include "dcl_pmic_features.h"

#if defined(PMIC_6252_REG_API)


/* Charger external interrupt is fixed. */
#define PMU_CHR_EINT_PIN      7


/* adc number for measuring VBAT/VISENSE/VCHARGER is fixed internally. */

#define PMU_ADC_VBAT_CH_NUM      0
#define PMU_ADC_VISENSE_CH_NUM   1
#define PMU_ADC_VCHARGER_CH_NUM  2


/* adc factor for VBAT/VISENSE/VCHARGER */
#define PMU_ADC_FACTOR_VBAT      100
#define PMU_ADC_FACTOR_VISENSE   100
#define PMU_ADC_FACTOR_VCHARGER  473  // 369/39 * 50

typedef enum
{
	LDO_BUCK_EN,
	LDO_BUCK_VOL_SEL,
	LDO_BUCK_RS,
	LDO_BUCK_OC_AUTO_OFF,
	//LDO_BUCK_STB_EN,
	LDO_BUCK_ON_SEL,
	LDO_BUCK_NDIS_EN,
	//LDO_BUCK_OCFB_EN,
	LDO_CAL,
	LDO_STB_TD,
	LDO_OC_TD,
	BUCK_VFBADJ_SLEEP,
	BUCK_ICAL_EN,
	//BUCK_CSL,
	//BUCK_STB_TD,
	//BUCK_OC_THD,
	//BUCK_BURST,
	SPK_EN,
	SPK_OC_EN,
	SPK_OC_THD,
	SPK_OC_WND,
	SPK_VOL,
	ISINK_EN,
	ISINK_MODE,
	ISINK_STEP,
	ISINK_VREF_CAL,
	//BOOST_TYPE,
	//BOOST_HW_SEL,
	KPLED_EN,
	KPLED_MODE,
	KPLED_SEL,
	ADC_EN,
	BATON_UNDET,
	CSDAC_EN,
	VBAT_CV_DET,
	VBAT_CV_EN,
	VBAT_CV_VTH,
	CSDAC_DLY,
	CSDAC_STP,
	CHR_EN,
	CHRDET,
	CHRWDT_TD,
	CS_VTH,
	CHRWDT_EN,
	CHRWDT_INT_EN,
	VCDT_HV_VTH,
	BATON_HT_EN,
	OTG_BVALID_EN,
	USBDL_EN,
	CCI_SRCLKEN,
	VCDT_HV_EN,
	//BOOST_CKS_PRG,
	BC11_VREF_VTH,
	BC11_CMP_EN,
	BC11_IPD_EN,
	BC11_IPU_EN,
	BC11_BIAS_EN,
	BC11_BB_CTRL,
	BC11_RST,	
	BC11_VSRC_EN,
	BC11_CMP_OUT,		
	PMU_FLAGS_MAX
}PMU_FLAGS_LIST_ENUM;

#define LDO_GROUP (OFFSEL(BUCK_GROUP))
#define BUCK_GROUP (M(VCORE))

#endif //#if defined(PMIC_6252_REG_API)

#endif //#ifndef __DCL_PMU6252_SW_H_STRUCT__


