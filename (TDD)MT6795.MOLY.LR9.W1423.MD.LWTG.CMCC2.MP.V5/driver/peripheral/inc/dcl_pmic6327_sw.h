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
 *    dcl_pmic6327_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMIC 6327
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



#ifndef __DCL_PMU6327_SW_H_STRUCT__
#define __DCL_PMU6327_SW_H_STRUCT__

#include "dcl_pmic_features.h"

#ifdef PMIC_6327_REG_API

#define PMIC6327_ECO_1_VERSION		0x01
#define PMIC6327_ECO_2_VERSION		0x02

// Combinational functions
extern void pmic6327_customization_init(void);
/*
// The following are implemented in custom files
// MoDIS parser skip start
extern void pmic6327_customization_init(void);
extern void pmic6327_cust_vspk_enable(kal_bool enable);
extern void pmic6327_csut_vsim_enable(kal_bool enable);
extern void pmic6327_csut_vsim_sel(pmic_adpt_vsim_volt volt);
extern void pmic6327_csut_vsim2_enable(kal_bool enable);
extern void pmic6327_csut_vsim2_sel(pmic_adpt_vsim_volt sel);
extern void pmic6327_csut_vusb_enable(kal_bool enable);
extern void pmic6327_csut_vcama_enable(kal_bool enable);
extern void pmic6327_csut_vcama_sel(pmic_adpt_vcama_volt vol);
extern void pmic6327_csut_vcamd_enable(kal_bool enable);
extern void pmic6327_csut_vcamd_sel(pmic_adpt_vcamd_volt volt);
// MoDIS parser skip end
*/

typedef enum
{
    VIO18_STATUS,
    VRF18_STATUS,
    VTCXO_STATUS,
    PMU_THR_STATUS,
    RG_VRF18_EN,
    RG_VRF18_VOSEL,
    RG_VRF18_ON_CTRL,
    RG_VRF18_MODESET,
    RG_VIO18_EN,
    RG_VSIM_CAL,
    RG_VSIM_VOSEL,
    RG_VSIM_EN,
    RG_VMC_CAL,
    RG_VMC_VOSEL,
    RG_VMC_EN,
    RG_VTCXO_CAL,
    VTCXO_ON_CTRL,
    RG_VTCXO_EN,
}PMU_FLAGS_LIST_ENUM;

typedef enum
{
	PMIC6327_VMC_SET_ENABLE = 0,
	PMIC6327_VMC_SET_VOLTAGE = 1,
	PMIC6327_MAX
}pmic6327_ccci_op;

typedef struct{
    kal_uint8   pmic6327_op;
    kal_uint8   pmic6327_param1;
    kal_uint8   pmic6327_param2;
    kal_uint8   pmic6327_param3;
}PMIC6327_CCCI_DATA;

#endif // #ifdef PMIC_6327_REG_API
#endif // #ifndef __DCL_PMU6327_SW_H_STRUCT__

