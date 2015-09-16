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
 *   bl_GFH_body.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   Body for Bootloader's GFH
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

#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)

#include "kal_general_types.h"
#include "bl_GFH_body.h"
#include "br_GFH_file_info.h"
#include "br_GFH.h"
#include "br_GFH_bl_info.h"
#include "br_GFH_arm_bl_info.h"
#include "GFH_defs.h"
#include "bl_features.h"
#include "feature_def.h"
#if defined (_NAND_FLASH_BOOTING_)
#include "NAND_DAL_Version.h"
#elif defined (__EMMC_BOOTING__)
#include "FTL.h"
#endif
#include "custom_img_config.h"
#include "flash_opt.h"
#include "bl_sectiondef.h"

//==============================================================================
// Linker symbols
//==============================================================================

extern kal_uint32 Image$$BL_GFH_SECTION$$Length;
extern kal_uint32 Load$$BL_GFH_SECTION$$Base;
extern kal_uint32 Image$$EXT_BL_GFH_SECTION$$Length;
extern kal_uint32 Load$$EXT_BL_GFH_SECTION$$Base;
extern kal_uint32 Image$$READ_ONLY$$Base;
extern kal_uint32 Image$$EXT_READ_ONLY$$Base;

//==============================================================================
// Bootloader parameters
//==============================================================================

#if defined (_NAND_FLASH_BOOTING_)

#define BL_DEVICE_TYPE           F_NAND_SEQUENTIAL
#define EXT_BL_DEVICE_TYPE       F_NAND_SEQUENTIAL
#define BL_MAX_SIZE              128*1024
#define EXT_BL_MAX_SIZE          BL_IMG_MAX_SIZE
#define BL_BINARY_ATTRIBUTE      0
#define EXT_BL_BINARY_ATTRIBUTE  0

#elif defined (__EMMC_BOOTING__)

#define BL_DEVICE_TYPE           F_EMMC_BOOT_REGION
#define EXT_BL_DEVICE_TYPE       F_EMMC_BOOT_REGION
#define BL_MAX_SIZE              128*1024
#define EXT_BL_MAX_SIZE          BL_IMG_MAX_SIZE
#define BL_BINARY_ATTRIBUTE      0
#define EXT_BL_BINARY_ATTRIBUTE  0

#elif defined(__X_BOOTING__)

#define BL_DEVICE_TYPE           F_XBOOT
#define EXT_BL_DEVICE_TYPE       F_XBOOT
#define BL_MAX_SIZE              GFH_FILE_MAX_SIZE_IGNORED
#define EXT_BL_MAX_SIZE          GFH_FILE_MAX_SIZE_IGNORED
#define BL_BINARY_ATTRIBUTE      0
#define EXT_BL_BINARY_ATTRIBUTE  0

#else

#if defined(__SERIAL_FLASH_EN__)
#define BL_DEVICE_TYPE           F_SF
#define EXT_BL_DEVICE_TYPE       F_SF
#else
#define BL_DEVICE_TYPE           F_NOR
#define EXT_BL_DEVICE_TYPE       F_NOR
#endif /* __SERIAL_FLASH_EN__ */
#define BL_MAX_SIZE              GFH_FILE_MAX_SIZE_IGNORED
#ifdef __EXT_BL_UPDATE__
#define EXT_BL_MAX_SIZE          BL_IMG_MAX_SIZE
#else
#define EXT_BL_MAX_SIZE          GFH_FILE_MAX_SIZE_IGNORED
#endif /* __EXT_BL_UPDATE__ */
#define BL_BINARY_ATTRIBUTE      0
#ifdef __EXT_BL_UPDATE__
#define EXT_BL_BINARY_ATTRIBUTE  0
#else
#define EXT_BL_BINARY_ATTRIBUTE  FILE_INFO_ATTR_XIP
#endif

#endif

#ifdef __MTK_SECURE_PLATFORM__
#define SIGNATURE_TYPE           SIG_SINGLE_AND_PHASH
#define SIGNATURE_LEN            SIG_SINGLE_AND_PHASH_LEN
#else
#define SIGNATURE_TYPE           SIG_PHASH
#define SIGNATURE_LEN            SIG_PHASH_LEN
#endif /* __MTK_SECURE_PLATFORM__ */

#define BL_VERSION               1

#ifdef __MINI_BOOTLOADER__
//==============================================================================
// Bootloader's GFH header body
//==============================================================================

__bootloader_gfh__ const BOOTLOADER_GFH g_bootloader_gfh = 
{
      //GFH_FILE_INFO_v1
      {  
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,
         
         BL_VERSION,
         ARM_BL,
         BL_DEVICE_TYPE,
         SIGNATURE_TYPE,
         
         (kal_uint32)(&Load$$BL_GFH_SECTION$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD, 
         BL_MAX_SIZE,
         (kal_uint32)(&Image$$BL_GFH_SECTION$$Length),
         SIGNATURE_LEN,
         (kal_uint32)(&Image$$READ_ONLY$$Base), 
         BL_BINARY_ATTRIBUTE,
      },

      //GFH_BROM_CFG_v3
      {
         GFH_HEADER(GFH_BROM_CFG, 3),
      },
      
      //GFH_BL_INFO_v1
      {
         GFH_HEADER(GFH_BL_INFO, 1),
         BL_ATTR_LOAD_BY_BOOTROM,
      },

      //GFH_ARM_BL_INFO_v1
      {
         GFH_HEADER(GFH_ARM_BL_INFO, 1),
         BL_MAUI_PAIRED_VER,
         (FEATURE_COMBINATION | FEATURE_BL_ALWAYS_SUPPORT),
         FEATURE_COMBINATINO_EX,
#if defined (_NAND_FLASH_BOOTING_)
         { FDM_MAJOR_VER, FDM_MINOR_VER1, FDM_MINOR_VER2, 0x00, 
           DAL_MAJOR_VER, DAL_MINOR_VER1, DAL_MINOR_VER2, 0x00 },
#endif
      },
      
#ifdef __MTK_SECURE_PLATFORM__

      //GFH_BL_SEC_KEY_v1
      {  
         GFH_HEADER(GFH_BL_SEC_KEY, 1),
      },


#endif /* __MTK_SECURE_PLATFORM__ */  

#ifdef __EMMC_BOOTING__

      //GFH_EMMC_BOOTING_INFO_v1
      {
         GFH_HEADER(GFH_EMMC_BOOTING_INFO, 1),
         FTL_EMMC_PAGE_SIZE,
         FTL_EMMC_BLOCK_SIZE,
         EMMC_CODE_PARTITION_SIZE/512,
         0,
         0,
         0
      },
      
#endif

};

//==============================================================================
// Bootloader's Signature
//==============================================================================

__bl_signature_section__ const kal_uint32 g_bootloader_sig[SIGNATURE_LEN>>2] = {SIG_HASH_VER};

kal_uint32 DummyReference()
{
   return (kal_uint32)(&g_bootloader_gfh)+(kal_uint32)(&g_bootloader_sig);
}

#endif /* __MINI_BOOTLOADER__ */

//==============================================================================
// Ext Bootloader's GFH header definition
//==============================================================================

#ifdef __EXT_BOOTLOADER__

__ext_bootloader_gfh__ const EXT_BOOTLOADER_GFH g_ext_bootloader_gfh = 
{
      //FILE_INFO
      {  
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,
         
         BL_VERSION,
         ARM_EXT_BL,
         EXT_BL_DEVICE_TYPE,
         SIGNATURE_TYPE,
         
         (kal_uint32)(&Load$$EXT_BL_GFH_SECTION$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         EXT_BL_MAX_SIZE,
         (kal_uint32)(&Image$$EXT_BL_GFH_SECTION$$Length),
         SIGNATURE_LEN,
         (kal_uint32)(&Image$$EXT_READ_ONLY$$Base),
         EXT_BL_BINARY_ATTRIBUTE
      },
      
      
      //GFH_BL_INFO_v1
      {
         GFH_HEADER(GFH_BL_INFO, 1),
         0
      },

      //GFH_ARM_BL_INFO_v1
      {
         GFH_HEADER(GFH_ARM_BL_INFO, 1),
         BL_MAUI_PAIRED_VER,
         (FEATURE_COMBINATION | FEATURE_BL_ALWAYS_SUPPORT),
         FEATURE_COMBINATINO_EX,
#if defined (_NAND_FLASH_BOOTING_)
         { FDM_MAJOR_VER, FDM_MINOR_VER1, FDM_MINOR_VER2, 0x00, 
           DAL_MAJOR_VER, DAL_MINOR_VER1, DAL_MINOR_VER2, 0x00 },
#endif
      },
      
#ifdef __MTK_SECURE_PLATFORM__      
      //GFH_MAUI_CODE_KEY_v1
      {
         GFH_HEADER(GFH_MAUI_CODE_KEY, 1),      
      },

#ifdef __SECURE_RO_ENABLE__      

      //GFH_MAUI_SECURE_RO_KEY_v1, for Secure RO
      {  
         GFH_HEADER(GFH_MAUI_SECURE_RO_KEY, 1),
      },
      
#endif /* __SECURE_RO_ENABLE__ */

#endif /* __MTK_SECURE_PLATFORM__ */      
};

//==============================================================================
// Ext Bootloader's Signature
//==============================================================================

__ext_bl_signature_section__ const kal_uint32 g_ext_bootloader_sig[SIGNATURE_LEN>>2] = {SIG_HASH_VER};

kal_uint32 DummyReference()
{
   return (kal_uint32)(&g_ext_bootloader_gfh) + (kal_uint32)(&g_ext_bootloader_sig);
}

#endif /* __EXT_BOOTLOADER__ */

//==============================================================================
// Misc
//==============================================================================


#endif /* __SV5_ENABLED__ || __SV5X_ENABLED__ */

