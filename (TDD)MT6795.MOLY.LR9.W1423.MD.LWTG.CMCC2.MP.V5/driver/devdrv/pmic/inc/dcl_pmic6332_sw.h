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
 *     dcl_pmic6332_sw.h
 *
 * Project:
 * --------
 *     MOLY Software
 *
 * Description:
 * ------------
 *     This file is for PMIC 6332
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DCL_PMIC6332_SW_H_STRUCT__
#define __DCL_PMIC6332_SW_H_STRUCT__

#include "dcl_pmic_features.h"

#ifdef PMIC_6332_REG_API

// Combinational functions
extern void pmic6332_customization_init(void);

typedef enum
{
    MT6332_HWCID,
    MT6332_SWCID,
    MT6332_TOP_CKPDN_CON2_RSV,
    MT6332_RG_VRF1_MODESET,
    MT6332_VRF1_EN_CTRL,
    MT6332_VRF1_VOSEL_CTRL,
    MT6332_VRF1_EN_SEL,
    MT6332_VRF1_VOSEL_SEL,
    MT6332_VRF1_EN,
    MT6332_VRF1_VOSEL,
    MT6332_VRF1_VOSEL_ON,
    MT6332_VRF1_VOSEL_SLEEP,
    MT6332_VRF1_VSLEEP_EN,
    MT6332_RG_VRF2_MODESET,
    MT6332_VRF2_EN_CTRL,
    MT6332_VRF2_VOSEL_CTRL,
    MT6332_VRF2_EN_SEL,
    MT6332_VRF2_VOSEL_SEL,
    MT6332_VRF2_EN,
    MT6332_VRF2_VOSEL,
    MT6332_VRF2_VOSEL_ON,
    MT6332_VRF2_VOSEL_SLEEP,
    MT6332_VRF2_VSLEEP_EN,
    MT6332_RG_VPA_MODESET,
    MT6332_VPA_EN,
    MT6332_VPA_VOSEL,
}PMIC6332_FLAGS_LIST_ENUM;

#endif // #ifdef PMIC_6332_REG_API
#endif // #ifndef __DCL_PMIC6332_SW_H_STRUCT__

