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
 *   bl_GFH_body.h
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   Data structure definition for Bootloader's GFH
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "br_GFH_file_info.h"
#include "br_GFH_bl_info.h"
#include "br_GFH_arm_bl_info.h"
#include "br_GFH_emmc_booting_info.h"
#include "GFH_defs.h"

typedef struct 
{
   GFH_FILE_INFO_v1           gfh_file_info;
   GFH_BROM_CFG_v3            gfh_brom_cfg;
   GFH_BL_INFO_v1             gfh_bl_info;
   GFH_ARM_BL_INFO_v1         gfh_arm_bl_info;
   
#ifdef __MTK_SECURE_PLATFORM__
   GFH_BL_SEC_KEY_v1          gfh_bl_sec_key;            //The key that bootrom uses to verify bootloader
#endif /* __MTK_SECURE_PLATFORM__ */   

#ifdef __EMMC_BOOTING__

   GFH_EMMC_BOOTING_INFO_v1   gfh_emmc_booting_info;
   
#endif

} BOOTLOADER_GFH;

typedef struct 
{
   GFH_FILE_INFO_v1  gfh_file_info;
   GFH_BL_INFO_v1    gfh_bl_info;
   GFH_ARM_BL_INFO_v1         gfh_arm_bl_info;
   
#ifdef __MTK_SECURE_PLATFORM__

   GFH_MAUI_CODE_KEY_v1 gfh_maui_sec_key;

#ifdef __SECURE_RO_ENABLE__
   GFH_MAUI_SECURE_RO_KEY_v1  gfh_maui_sec_key_secro;    //The key to verify SecureRO
#endif /* __SECURE_RO_ENABLE__ */

#endif /* __MTK_SECURE_PLATFORM__ */


} EXT_BOOTLOADER_GFH;


extern const BOOTLOADER_GFH g_bootloader_gfh;
extern const EXT_BOOTLOADER_GFH g_ext_bootloader_gfh;
extern kal_uint32 DummyReference();

