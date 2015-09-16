/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *		dcl_pmic6320_sw.h
 *
 * Project:
 * --------
 *   	Maui_Software
 *
 * Description:
 * ------------
 *		This file is for PMIC 6320
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __DCL_PMIC6320_SW_H_STRUCT__
#define __DCL_PMIC6320_SW_H_STRUCT__

#include "dcl_pmic_features.h"

#ifdef PMIC_6320_REG_API

#define PMIC6320_ECO_1_VERSION		0x01
#define PMIC6320_ECO_2_VERSION		0x02

// Combinational functions
extern void pmic6320_customization_init(void);

typedef enum
{
    STATUS_VSIM1_EN,
    STATUS_VSIM2_EN,
    OC_STATUS_VSIM1,
    OC_STATUS_VSIM2,
    RG_SIMLS2_SRST_CONF,
    RG_SIMLS2_SCLK_CONF,
    RG_SIMLS1_SRST_CONF,
    RG_SIMLS1_SCLK_CONF,
    RG_SIMLS_TDSEL,
    RG_SIMAP_TDSEL,
    RG_SIMLS_RDSEL,
    RG_SIMAP_RDSEL,
    RG_OCTL_SIM1_AP_SRST,
    RG_OCTL_SIM1_AP_SCLK,
    RG_OCTL_SIMLS1_SRST,
    RG_OCTL_SIMLS1_SCLK,
    RG_OCTL_SIM2_AP_SRST,
    RG_OCTL_SIM2_AP_SCLK,
    RG_OCTL_SIMLS2_SRST,
    RG_OCTL_SIMLS2_SCLK,
    RG_VIO18_MODESET,
    RG_VPA_MODESET,
    VPA_EN,
    RG_VRF18_MODESET,
    RG_VRF18_BK_LDO,
    VRF18_EN_CTRL,
    VRF18_EN,
    RG_VRF18_2_MODESET,
    RG_VRF18_2_BK_LDO,
    VRF18_2_EN_CTRL,
    VRF18_2_EN_SEL,
    VRF18_2_EN,
    VRF28_ON_CTRL,
    RG_VRF28_EN,
    VRF28_SRCLK_EN_SEL,
    VRF28_ON_2_CTRL,
    RG_VRF28_2_EN,
    VRF28_2_SRCLK_EN_SEL,
    RG_VSIM1_EN,
    RG_VSIM1_STBTD,
    QI_VSIM1_MODE,
    VSIM1_SRCLK_MODE_SEL,
    VSIM1_LP_MODE_SET,
    VSIM1_LP_SEL,
    RG_VSIM2_EN,
    RG_VSIM2_STBTD,
    QI_VSIM2_MODE,
    VSIM2_SRCLK_MODE_SEL,
    VSIM2_THER_SHDN_EN,
    VSIM2_LP_MODE_SET,
    VSIM2_LP_SEL,
    QI_VSIM1_OC_STATUS,
    QI_VSIM2_OC_STATUS,
    RG_VSIM1_CAL,
    RG_VSIM1_VOSEL,
    RG_VSIM1_STB_SEL,
    RG_VSIM1_OCFB,
    RG_VSIM1_NDIS_EN,
    RG_VSIM2_CAL,
    RG_VSIM2_VOSEL,
    RG_VSIM2_STB_SEL,
    RG_VSIM2_OCFB,
    RG_VSIM2_NDIS_EN,
    VSIM1_ON_CTRL,
    VSIM2_ON_CTRL,
}PMIC_FLAGS_LIST_ENUM;

#endif // #ifdef PMIC_6320_REG_API
#endif // #ifndef __DCL_PMIC6320_SW_H_STRUCT__

