/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 *     dcl_pmic6331_sw.h
 *
 * Project:
 * --------
 *     MOLY Software
 *
 * Description:
 * ------------
 *     This file is for PMIC 6331
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 * HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DCL_PMIC6331_SW_H_STRUCT__
#define __DCL_PMIC6331_SW_H_STRUCT__

#include "dcl_pmic_features.h"

#ifdef PMIC_6331_REG_API

// Combinational functions
extern void pmic6331_customization_init(void);

typedef enum
{
    MT6331_HWCID,
    MT6331_SWCID,
    MT6331_RG_VTCXO2_LP_CTRL,
    MT6331_RG_VTCXO2_LP_SET,
    MT6331_RG_VTCXO2_EN,
    MT6331_RG_VTCXO2_ON_CTRL,
    MT6331_RG_VTCXO2_SRCLK_EN_SEL,
    MT6331_RG_VMIPI_EN,
    MT6331_RG_VMIPI_ON_CTRL,
    MT6331_RG_VMIPI_SRCLK_EN_SEL,
    MT6331_RG_VSIM1_LP_CTRL,
    MT6331_RG_VSIM1_LP_MODE_SET,
    MT6331_RG_VSIM1_EN,
    MT6331_RG_VSIM2_LP_CTRL,
    MT6331_RG_VSIM2_LP_MODE_SET,
    MT6331_RG_VSIM2_EN,
    MT6331_RG_VSIM1_VOSEL,
    MT6331_RG_VSIM2_VOSEL,
    MT6331_RG_VSIM1_OCFB_EN,
    MT6331_RG_VSIM2_OCFB_EN,
    MT6331_AUXADC_ADC_OUT_CH7_BY_MD,
    MT6331_AUXADC_ADC_RDY_CH7_BY_MD,
    MT6331_AUXADC_ADC_OUT_CH4_BY_MD,
    MT6331_AUXADC_ADC_RDY_CH4_BY_MD,
    MT6331_AUXADC_RQST1_SET,
    MT6331_AUXADC_RQST1_CLR,
}PMIC6331_FLAGS_LIST_ENUM;

#endif // #ifdef PMIC_6331_REG_API
#endif // #ifndef __DCL_PMIC6331_SW_H_STRUCT__

