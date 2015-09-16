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
 *    dcl_pmu6276_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMU6276
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __DCL_PMU6276_SW_H_STRUCT__
#define __DCL_PMU6276_SW_H_STRUCT__

#include "dcl_pmic_features.h"

#if defined(PMIC_6276_REG_API)

/* Charger external interrupt is fixed. */
#define PMU_CHR_EINT_PIN      29


/* adc number for measuring VBAT/VISENSE/VCHARGER is fixed internally. */

#define PMU_ADC_VBAT_CH_NUM      0
#define PMU_ADC_VISENSE_CH_NUM   1
#define PMU_ADC_VCHARGER_CH_NUM  2


/* adc factor for VBAT/VISENSE/VCHARGER */
#define PMU_ADC_FACTOR_VBAT      100
#define PMU_ADC_FACTOR_VISENSE   100
#if defined(MT6276_S00)
#define PMU_ADC_FACTOR_VCHARGER  344  // (351/51 * 50)
#endif //#if defined(MT6276_S00)
#if defined(MT6276_S01)
#define PMU_ADC_FACTOR_VCHARGER  473  // (369/39 * 50)
#endif //#if defined(MT6276_S01)

typedef enum
{
	PMU_VA12,
	PMU_VRTC,
	PMU_VMIC,
	PMU_VAUDN,
	PMU_VAUDP,
	PMU_VRF28,
	PMU_VTCXO,
	PMU_VA25,
	PMU_VCAMA,
	PMU_VCAMD,
	PMU_VIO28,
	PMU_VUSB,
	PMU_VBT,
	PMU_VSIM,
	PMU_VSIM2,
	PMU_VIBR,
	PMU_VMC,
	PMU_VCAMA2,
	PMU_VCAMD2,
	PMU_VFM,
	PMU_VM12,
	PMU_VCORE,
	PMU_VIO18,
	PMU_VPROC,
	PMU_VRF18,
	PMU_LDO_BUCK_INTERNAL_MAX
}PMU_LDO_BUCK_INTERNAL_LIST_ENUM;

/*
typedef enum
{
	VA12,
	VRTC,
	VMIC,
	VAUDN,
	VAUDP,
	VRF,
	VTCXO,
	VA25,
	VCAMA,
	VCAMD,
	VIO,
	VUSB,
	VBT,
	VSIM,
	VSIM2,
	VIBR,
	VMC,
	VCAMA2,
	VCAMD2,
	VFM,
	VM12,
	VCORE,
	VIO18,
	VPROC,
	VRF18,
	PMU_LDO_BUCK_MAX
}PMU_LDO_BUCK_LIST_ENUM;

typedef enum
{
	VPA,
	VPA1=VPA,
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

typedef enum
{
	LPOSC,
	PMU_LPOSC_MAX
}PMU_LPOSC_LIST_ENUM;

*/

#define LDO_GROUP (OFFSEL(BUCK_GROUP))
#define BUCK_GROUP (M(VCORE)|M(VIO18)|M(VPROC)|M(VRF18))


#if defined(__DRV_UPMU_SHARE_LDO__)
//function 相關設定
//multi users share the same LDO , enable multi user capability
#define LDO_SHARE_EN_BITMAP (M(VCAMA))
#define PMU_MULTIUSERS_HANDLE_NO 6 //vcama ctp fm
#endif //#if defined(__DRV_UPMU_SHARE_LDO__)


#define LDO_SET_VOLTAGE_BITMAP (M(VCAMA)|M(VCAMD)|M(VBT)|M(VSIM)|M(VSIM2)|M(VIBR)|M(VMC)|M(VCAMA2)|M(VCAMD2))


#endif //#if defined(PMIC_6276_REG_API)

#endif //#ifndef __DCL_PMU6276_SW_H_STRUCT__

