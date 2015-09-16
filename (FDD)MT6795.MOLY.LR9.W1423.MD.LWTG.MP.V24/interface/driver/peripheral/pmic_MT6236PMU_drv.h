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
 *    pmic_MT6236PMU_drv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for PMU 6236
 *   The PMIC/PMU driver APIs exported for custom tool
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PMIC_MT6236PMU_DRV_H__
#define __PMIC_MT6236PMU_DRV_H__
#include "kal_public_api.h"

#if defined(PMIC_6236_REG_API)

// VCORE
extern void pmicMT6236PMU_VCORE_Enable(kal_bool enable);
extern void pmicMT6236PMU_VCORE_Set_Volt(kal_uint32 volt);
extern void pmicMT6236PMU_VCORE_Cal(kal_uint32 step);
// VIO
extern void pmicMT6236PMU_VIO_Enable(kal_bool enable);
extern void pmicMT6236PMU_VIO_Set_Volt(kal_uint32 volt);
extern void pmicMT6236PMU_VIO_Cal(kal_uint32 step);
// VRF
extern void pmicMT6236PMU_VRF_Enable(kal_bool enable);
extern void pmicMT6236PMU_VRF_Set_Volt(kal_uint32 volt);
extern void pmicMT6236PMU_VRF_Cal(kal_uint32 step);
// VA
extern void pmicMT6236PMU_VA_Enable(kal_bool enable);
extern void pmicMT6236PMU_VA_Set_Volt(kal_uint32 volt);
extern void pmicMT6236PMU_VA_Cal(kal_uint32 step);
// VTCXO
extern void pmicMT6236PMU_VTCXO_Enable(kal_bool enable);
extern void pmicMT6236PMU_VTCXO_Set_Volt(kal_uint32 volt);
extern void pmicMT6236PMU_VTCXO_Cal(kal_uint32 step);
// VRTC
extern void pmicMT6236PMU_VRTC_Enable(kal_bool enable);
extern void pmicMT6236PMU_VRTC_Set_Volt(kal_uint32 volt);
extern void pmicMT6236PMU_VRTC_Cal(kal_uint32 step);
// VM
extern void pmicMT6236PMU_VM_Enable(kal_bool enable);
extern void pmicMT6236PMU_VM_Set_Volt(kal_uint32 volt);
extern void pmicMT6236PMU_VM_Cal(kal_uint32 step);
// VSIM
extern void pmicMT6236PMU_VSIM_Enable(kal_bool enable);
extern void pmicMT6236PMU_VSIM_Set_Volt(kal_uint32 volt);
extern void pmicMT6236PMU_VSIM_Cal(kal_uint32 step);
// VSIM2
extern void pmicMT6236PMU_VSIM2_Enable(kal_bool enable);
extern void pmicMT6236PMU_VSIM2_Set_Volt(kal_uint32 volt);
extern void pmicMT6236PMU_VSIM2_Cal(kal_uint32 step);
// VMC
extern void pmicMT6236PMU_VMC_Enable(kal_bool enable);
extern void pmicMT6236PMU_VMC_Set_Volt(kal_uint32 volt);
extern void pmicMT6236PMU_VMC_Cal(kal_uint32 step);
// VBT
extern void pmicMT6236PMU_VBT_Enable(kal_bool enable);
extern void pmicMT6236PMU_VBT_Set_Volt(kal_uint32 volt);
extern void pmicMT6236PMU_VBT_Cal(kal_uint32 step);
// VUSB
extern void pmicMT6236PMU_VUSB_Enable(kal_bool enable);
extern void pmicMT6236PMU_VUSB_Set_Volt(kal_uint32 volt);
extern void pmicMT6236PMU_VUSB_Cal(kal_uint32 step);
// VCAMD
extern void pmicMT6236PMU_VCAMD_Enable(kal_bool enable);
extern void pmicMT6236PMU_VCAMD_Set_Volt(kal_uint32 volt);
extern void pmicMT6236PMU_VCAMD_Cal(kal_uint32 step);
// VCAMA
extern void pmicMT6236PMU_VCAMA_Enable(kal_bool enable);
extern void pmicMT6236PMU_VCAMA_Set_Volt(kal_uint32 volt);
extern void pmicMT6236PMU_VCAMA_Cal(kal_uint32 step);
// VIBR
extern void pmicMT6236PMU_VIBR_Enable(kal_bool enable);
extern void pmicMT6236PMU_VIBR_Set_Volt(kal_uint32 volt);
extern void pmicMT6236PMU_VIBR_Cal(kal_uint32 step);



#endif  // PMIC_6236_REG_API

#endif // #ifndef __PMIC_MT6236PMU_DRV_H__

