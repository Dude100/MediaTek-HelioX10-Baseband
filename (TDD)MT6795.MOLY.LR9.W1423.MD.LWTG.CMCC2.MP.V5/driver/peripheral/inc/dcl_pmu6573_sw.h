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
 *    dcl_pmu6573_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMU 6573
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __DCL_PMU6573_SW_H_STRUCT__
#define __DCL_PMU6573_SW_H_STRUCT__

#include "dcl_pmic_features.h"

#if defined(PMIC_6573_REG_API)

/* Charger external interrupt is fixed. */
#define PMU_CHR_EINT_PIN      29


/* adc number for measuring VBAT/VISENSE/VCHARGER is fixed internally. */

#define PMU_ADC_VBAT_CH_NUM      0
#define PMU_ADC_VISENSE_CH_NUM   1
#define PMU_ADC_VCHARGER_CH_NUM  2


/* adc factor for VBAT/VISENSE/VCHARGER */
#define PMU_ADC_FACTOR_VBAT      100
#define PMU_ADC_FACTOR_VISENSE   100
#define PMU_ADC_FACTOR_VCHARGER  294  // 300/51 * 50

/*
typedef enum
{
	VTCXO,
	VRF,
	VSIM,
	VSIM2,
	VRF18,
	PMU_LDO_BUCK_MAX,
        CHR,
        VMC,
        VFM,
        VCAMA,
        VCAMD,
        VIBR
}PMU_LDO_BUCK_LIST_ENUM;

typedef enum
{
	VPA1,
	PMU_VPA_MAX
}PMU_VPA_LIST_ENUM;


typedef enum
{
	PMU_KPLED_MAX
}PMU_KPLED_LIST_ENUM;

typedef enum
{
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

#endif //#if defined(PMIC_6573_REG_API)

#endif //#ifndef __DCL_PMU6573_SW_H_STRUCT__


