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
 *		dcl_pmic6323_sw.h
 *
 * Project:
 * --------
 *   	Maui_Software
 *
 * Description:
 * ------------
 *		This file is for PMIC 6323
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __DCL_PMIC6323_SW_H_STRUCT__
#define __DCL_PMIC6323_SW_H_STRUCT__

#include "dcl_pmic_features.h"

#ifdef PMIC_6323_REG_API

#define PMIC6323_ECO_1_VERSION		0x01
#define PMIC6323_ECO_2_VERSION		0x02

// Combinational functions
extern void pmic6323_customization_init(void);

typedef enum
{
    RG_VPA_MODESET,
    VPA_EN,
    RG_STB_SIM1_SIO,
    RG_VSIM1_EN,
    VSIM1_LP_MODE_SET,
    VSIM1_LP_SEL,
    RG_VSIM2_EN,
    VSIM2_LP_MODE_SET,
    VSIM2_LP_SEL,
    RG_STB_SIM2_SIO,
    RG_VSIM1_VOSEL,
    RG_VSIM2_VOSEL,
    RG_VRF18_EN,
    VRF18_LP_MODE_SET,
    VRF18_LP_SEL,
    VRF18_ON_CTRL,
    RG_ADC_OUT_MD,
    RG_ADC_RDY_MD,
    RG_MD_RQST,
    GPIO15_DOUT_SET,
    GPIO15_DOUT_CLR,
    GPIO17_DOUT_SET,
    GPIO17_DOUT_CLR,    
}PMIC_FLAGS_LIST_ENUM;

#endif // #ifdef PMIC_6323_REG_API
#endif // #ifndef __DCL_PMIC6323_SW_H_STRUCT__

