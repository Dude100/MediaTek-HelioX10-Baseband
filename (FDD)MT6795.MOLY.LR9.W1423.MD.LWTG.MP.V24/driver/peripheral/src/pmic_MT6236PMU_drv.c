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
 *    pmic_MT6236PMU_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines functions exported by MT6236 for custom tool
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include  "kal_public_api.h"

/*
   We assume the parameters passed from custom tool are all correct
   and do NOT perform range check here
*/

// VCORE
void pmicMT6236PMU_VCORE_Enable(kal_bool enable){}

void pmicMT6236PMU_VCORE_Set_Volt(kal_uint32 volt){}

void pmicMT6236PMU_VCORE_Cal(kal_uint32 step){}

// VIO
void pmicMT6236PMU_VIO_Enable(kal_bool enable){}

void pmicMT6236PMU_VIO_Set_Volt(kal_uint32 volt){}

void pmicMT6236PMU_VIO_Cal(kal_uint32 step){}

// VRF
void pmicMT6236PMU_VRF_Enable(kal_bool enable){}

void pmicMT6236PMU_VRF_Set_Volt(kal_uint32 volt){}

void pmicMT6236PMU_VRF_Cal(kal_uint32 step){}

// VA
void pmicMT6236PMU_VA_Enable(kal_bool enable){}

void pmicMT6236PMU_VA_Set_Volt(kal_uint32 volt){}

void pmicMT6236PMU_VA_Cal(kal_uint32 step){}

// VTCXO
void pmicMT6236PMU_VTCXO_Enable(kal_bool enable){}

void pmicMT6236PMU_VTCXO_Set_Volt(kal_uint32 volt){}

void pmicMT6236PMU_VTCXO_Cal(kal_uint32 step){}

// VRTC
void pmicMT6236PMU_VRTC_Enable(kal_bool enable){}

void pmicMT6236PMU_VRTC_Set_Volt(kal_uint32 volt){}

void pmicMT6236PMU_VRTC_Cal(kal_uint32 step){}

// VM
void pmicMT6236PMU_VM_Enable(kal_bool enable){}

void pmicMT6236PMU_VM_Set_Volt(kal_uint32 volt){}

void pmicMT6236PMU_VM_Cal(kal_uint32 step){}


// VSIM
void pmicMT6236PMU_VSIM_Enable(kal_bool enable){}

void pmicMT6236PMU_VSIM_Set_Volt(kal_uint32 volt){}

void pmicMT6236PMU_VSIM_Cal(kal_uint32 step){}

void pmicMT6236PMU_VSIM2_Enable(kal_bool enable){}

void pmicMT6236PMU_VSIM2_Set_Volt(kal_uint32 volt){}

void pmicMT6236PMU_VSIM2_Cal(kal_uint32 step){}

void pmicMT6236PMU_VMC_Enable(kal_bool enable){}

void pmicMT6236PMU_VMC_Set_Volt(kal_uint32 volt){}

void pmicMT6236PMU_VMC_Cal(kal_uint32 step){}

void pmicMT6236PMU_VBT_Enable(kal_bool enable){}

void pmicMT6236PMU_VBT_Set_Volt(kal_uint32 volt){}

void pmicMT6236PMU_VBT_Cal(kal_uint32 step){}

void pmicMT6236PMU_VUSB_Enable(kal_bool enable){}

void pmicMT6236PMU_VUSB_Set_Volt(kal_uint32 volt){}

void pmicMT6236PMU_VUSB_Cal(kal_uint32 step){}

void pmicMT6236PMU_VCAMD_Enable(kal_bool enable){}

void pmicMT6236PMU_VCAMD_Set_Volt(kal_uint32 volt){}

void pmicMT6236PMU_VCAMD_Cal(kal_uint32 step){}

void pmicMT6236PMU_VCAMA_Enable(kal_bool enable){}

void pmicMT6236PMU_VCAMA_Set_Volt(kal_uint32 volt){}

void pmicMT6236PMU_VCAMA_Cal(kal_uint32 step){}

void pmicMT6236PMU_VIBR_Enable(kal_bool enable){}

void pmicMT6236PMU_VIBR_Set_Volt(kal_uint32 volt){}

void pmicMT6236PMU_VIBR_Cal(kal_uint32 step){}

