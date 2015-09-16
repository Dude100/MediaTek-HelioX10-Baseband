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
 *   maui_GFH_body.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contain the GFH body and content for all MAUI parts
 *
 * Author:
 * -------
 *
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
 *
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)

#include "br_GFH.h"
#include "br_GFH_file_info.h"
#include "br_GFH_maui_info.h"
#include "br_GFH_flash_info.h"
#include "br_GFH_cbr_info.h"
#include "br_GFH_maui_sec.h"
#include "br_GFH_secure_ro_info.h"
#include "br_GFH_binary_location.h"
#include "SST_init.h"

#include "GFH_defs.h"
#include "maui_GFH_body.h"

#include "feature_def.h"
#include "bl_features.h"
#include "Cbr_record_def.h"

#include "custom_img_config.h"
#include "custom_secure_config.h"

#include "kal_general_types.h"

#ifdef _NAND_FLASH_BOOTING_
#include "NAND_DAL_Version.h"
#endif

#ifdef __BOOT_CERT_V2__
#include "boot_cert_pattern.h"
#endif

//==============================================================================
// Linker symbols
//==============================================================================

extern kal_uint32 Image$$ROM$$Base;

extern kal_uint32 Image$$ROM_GFH$$Length;
extern kal_uint32 Load$$ROM_GFH$$Base;
#ifdef __USB_FW_DL_SUPPORT__
extern kal_uint32 Image$$EXTSRAM_DSP_DATA_ZI$$Base;
#endif

extern kal_uint32 Image$$SECONDARY_ROM_GFH$$Length;
extern kal_uint32 Load$$SECONDARY_ROM_GFH$$Base;

#ifdef __DEMAND_PAGING__
extern kal_uint32 Image$$DEMAND_PAGING_ROM0_GFH$$Length;
extern kal_uint32 Load$$DEMAND_PAGING_ROM0_GFH$$Base;
#endif /* __DEMAND_PAGING__ */

extern kal_uint32 Load$$LANG_PACK_ROM_GFH$$Base;
extern kal_uint32 Image$$LANG_PACK_ROM_GFH$$Length;
extern kal_uint32 Load$$CUSTPACK_ROM_GFH$$Base;
extern kal_uint32 Image$$CUSTPACK_ROM_GFH$$Length;
extern kal_uint32 Load$$JUMP_TABLE_GFH$$Base;
extern kal_uint32 Image$$JUMP_TABLE_GFH$$Length;
extern kal_uint32 Load$$THIRD_ROM_GFH$$Base;
extern kal_uint32 Image$$THIRD_ROM_GFH$$Length;


extern kal_uint32 Image$$SECURE_RO_S_GFH$$Length;
extern kal_uint32 Load$$SECURE_RO_S_GFH$$Base;

extern kal_uint32 Image$$SECURE_RO_ME_GFH$$Length;
extern kal_uint32 Load$$SECURE_RO_ME_GFH$$Base;

extern kal_uint32 Load$$VIVA_GFH$$Base;
extern kal_uint32 Image$$VIVA_GFH$$Length;

//==============================================================================
// Section definition
//==============================================================================

#ifdef __MTK_TARGET__
#define __section(S)                         __attribute__ ((used,section(#S)))
#else
#define __section(S)
#endif

#define __maui_gfh__                         __section(MAUI_GFH)
#define __maui_signature_section__           __section(MAUI_SIGNATURE_SECTION)
#define __s_maui_gfh__                       __section(S_MAUI_GFH)
#define __s_maui_signature_section__         __section(S_MAUI_SIGNATURE_SECTION)
#define __odp_gfh__                          __section(ODP_GFH)
#define __lang_pack_gfh__                    __section(LANG_PACK_GFH)
#define __custpack_gfh__                     __section(CUSTPACK_GFH)
#define __jump_table_gfh__                   __section(JUMP_TABLE_GFH)
#define __third_rom_gfh__                    __section(THIRD_ROM_GFH)
#define __secure_ro_s_gfh__                  __section(SECURE_RO_S_GFH)
#define __secure_ro_s_signature_section__    __section(SECURE_RO_S_SIGNATURE_SECTION)
#define __secure_ro_me_gfh__                 __section(SECURE_RO_ME_GFH)
#define __secure_ro_me_signature_section__   __section(SECURE_RO_ME_SIGNATURE_SECTION)

/* SECURE RO S is not ready yet, we use a macro to disable it first */
#define __SECURE_RO_S_DISABLE__

//==============================================================================
// MAUI parameters
//==============================================================================

//Define where the MAUI locates
#if defined (_NAND_FLASH_BOOTING_)

#define MAUI_DEVICE_TYPE           F_NAND_FDM50
#define BINARY_ATTRIBUTE           0

#elif defined (__EMMC_BOOTING__)

#define MAUI_DEVICE_TYPE           F_EMMC_DATA_REGION
#define BINARY_ATTRIBUTE           0

#elif defined(__X_BOOTING__)

#define MAUI_DEVICE_TYPE           F_XBOOT
#define BINARY_ATTRIBUTE           0

#else

#if defined(__SERIAL_FLASH_EN__)
#define MAUI_DEVICE_TYPE           F_SF
#else
#define MAUI_DEVICE_TYPE           F_NOR
#endif

#if defined(__XIP_SHADOWING__)
#define BINARY_ATTRIBUTE           0
#else
#endif
#define BINARY_ATTRIBUTE           FILE_INFO_ATTR_XIP

#endif

//Define the signature type of MAUI binaries
#ifdef __MTK_SECURE_PLATFORM__
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || defined(__X_BOOTING__)
#define P_MAUI_SIGNATURE_TYPE      SIG_SINGLE
#define P_MAUI_SIGNATURE_LEN       SIG_SINGLE_LEN
#define S_MAUI_SIGNATURE_TYPE      SIG_MULTI
#define S_MAUI_SIGNATURE_LEN       SIG_MULTI_LEN
#else
#define P_MAUI_SIGNATURE_TYPE      SIG_MULTI
#define P_MAUI_SIGNATURE_LEN       SIG_MULTI_LEN
#define S_MAUI_SIGNATURE_TYPE      SIG_NONE
#define S_MAUI_SIGNATURE_LEN       SIG_NONE_LEN
#endif //defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

#define SECURE_RO_SIGNATURE_TYPE   SIG_SINGLE_AND_PHASH
#define SECURE_RO_SIGNATURE_LEN    SIG_SINGLE_AND_PHASH_LEN

#else

#define P_MAUI_SIGNATURE_TYPE      SIG_NONE
#define P_MAUI_SIGNATURE_LEN       SIG_NONE_LEN
#define S_MAUI_SIGNATURE_TYPE      SIG_NONE
#define S_MAUI_SIGNATURE_LEN       SIG_NONE_LEN

#define SECURE_RO_SIGNATURE_TYPE   SIG_PHASH
#define SECURE_RO_SIGNATURE_LEN    SIG_PHASH_LEN

#endif /* __MTK_SECURE_PLATFORM__ */

//Constants
#define DUMMY_END (0xffffffff)

//Define the version of MAUI software
#define MAUI_VERSION               1
#define SECURE_RO_VERSION          1

//==============================================================================
// MAUI's GFH header body
//==============================================================================


__maui_gfh__ const MAUI_GFH g_maui_gfh =
{
      //GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,

         MAUI_VERSION,
#ifndef __FACTORY_BIN__
         PRIMARY_MAUI,
#else
         PRIMARY_FACTORY_BIN,
#endif
         MAUI_DEVICE_TYPE,
         P_MAUI_SIGNATURE_TYPE,

         (kal_uint32)(&Load$$ROM_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         MAX_LENGTH_ROM,
         (kal_uint32)(&Image$$ROM_GFH$$Length),
         P_MAUI_SIGNATURE_LEN,
         (kal_uint32)(&Image$$ROM$$Base),
         BINARY_ATTRIBUTE
      },

      //GFH_MAUI_INFO_v2
      {
         GFH_HEADER(GFH_MAUI_INFO, 2),

         //platform_id & project_id
         "N/A",
         "N/A",

         BL_MAUI_PAIRED_VER,
         FEATURE_COMBINATION,
         FEATURE_COMBINATINO_EX,
         0,
         SW_MINOR_VER,
#ifdef __SECURE_DATA_STORAGE__
         SDS_START_ADDR,
         SDS_TOTAL_SIZE,
#else
         0,
         0,
#endif
#ifdef MT6280
		2,
#else
         MIN_FLASHTOOL_VER_REQURIEMENT,
#endif
#ifdef __BOOT_CERT_V2__
         (kal_uint32)&g_SRD_INFO,
         (kal_uint32)sizeof(g_SRD_INFO),
#else
         0,0,
#endif
         {0},
#ifdef __USB_FW_DL_SUPPORT__
         (kal_uint32)(&Image$$EXTSRAM_DSP_DATA_ZI$$Base)
#endif

      },

      //GFH_FLASH_INFO_v1
      {
         GFH_HEADER(GFH_FLASH_INFO, 1),
#ifdef _NAND_FLASH_BOOTING_
         { 0x30, (FDM_MAJOR_VER+0x30), (FDM_MINOR_VER1+0x30), (FDM_MINOR_VER2+0x30),
           0x30, (DAL_MAJOR_VER+0x30), (DAL_MINOR_VER1+0x30), (DAL_MINOR_VER2+0x30)
         },
#endif
      },

      //GFH_CBR_INFO_v2
      {
         GFH_HEADER(GFH_CBR_INFO, 2),
         CBR_REGION_NORMAL_BLOCK_NUM,
         CBR_REGION_SPARE_BLOCK_NUM,
         0,
         0
      },

#ifdef __MTK_SECURE_PLATFORM__
      //GFH_MAUI_SEC_v1
      {
         GFH_HEADER(GFH_MAUI_SEC, 1),
      },

      //GFH_MAUI_CODE_KEY_v1, for Code binaries
      {
         GFH_HEADER(GFH_MAUI_CODE_KEY, 1),
      },

      //GFH_MAUI_SECURE_RO_KEY_v1, for Secure RO
      {
         GFH_HEADER(GFH_MAUI_SECURE_RO_KEY, 1),
      },
#endif /* __MTK_SECURE_PLATFORM__ */

#ifdef __FOTA_DM__
      //GFH_FOTA_INFO_v1
      {
         GFH_HEADER(GFH_FOTA_INFO, 1),
         FOTA_PACKAGE_STORAGE_BASE,
         FOTA_PACKAGE_STORAGE_SIZE,
         FOTA_BACKUP_STORAGE_BASE,
         FOTA_BACKUP_STORAGE_SIZE,
         FOTA_EXTRA_RESERVED_BLOCKS,
      },
#endif

#ifdef __XIP_SHADOWING__
      //GFH_BINARY_LOCATION_v1
      {
         GFH_HEADER(GFH_BINARY_LOCATION, 1),
#ifndef __FACTORY_BIN__
         MAUI_ROM_START_ADDR
#else
         FACTORY_ROM_START_ADDR
#endif
      },
#endif

};

//==============================================================================
// MAUI's Signature
//==============================================================================
#ifdef __MTK_SECURE_PLATFORM__
__maui_signature_section__ const unsigned long g_maui_sig[P_MAUI_SIGNATURE_LEN>>2] = {SIG_HASH_VER};
#else
__maui_signature_section__ const unsigned long g_maui_sig                          = DUMMY_END;
#endif /* __MTK_SECURE_PLATFORM__ */

#if (defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)) && !defined(__NFB_SINGLE_ROM__)
//==============================================================================
// Secondary MAUI GFH header body
//==============================================================================
__s_maui_gfh__ const S_MAUI_GFH g_s_maui_gfh =
{
      //GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,

         MAUI_VERSION,
#ifndef __FACTORY_BIN__
         SECONDARY_MAUI,
#else
         SECONDARY_FACTORY_BIN,
#endif
         MAUI_DEVICE_TYPE,
         S_MAUI_SIGNATURE_TYPE,

         (kal_uint32)(&Load$$SECONDARY_ROM_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         MAX_LENGTH_SECONDARY_ROM,
         (kal_uint32)(&Image$$SECONDARY_ROM_GFH$$Length),
         S_MAUI_SIGNATURE_LEN,
         0,
         BINARY_ATTRIBUTE
      },
};



//==============================================================================
// Secondary MAUI's Signature
//==============================================================================
#ifdef __MTK_SECURE_PLATFORM__
__s_maui_signature_section__ const unsigned long g_s_maui_sig[S_MAUI_SIGNATURE_LEN>>2]  = {SIG_HASH_VER};
#else
__s_maui_signature_section__ const unsigned long g_s_maui_sig                           = DUMMY_END;
#endif /* __MTK_SECURE_PLATFORM__ */

#ifdef __DEMAND_PAGING__
//==============================================================================
// On-demond paging GFH header body
//==============================================================================
__odp_gfh__ const ODP_GFH g_odp_gfh =
{
      //GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,

         MAUI_VERSION,
         ON_DEMAND_PAGING,
         MAUI_DEVICE_TYPE,
         SIG_NONE,

         (kal_uint32)(&Load$$DEMAND_PAGING_ROM0_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         MAX_LENGTH_DEMAND_PAGING_ROM0,
         (kal_uint32)(&Image$$DEMAND_PAGING_ROM0_GFH$$Length),
         0,
         0,
         BINARY_ATTRIBUTE
      },
};

#endif /* __DEMAND_PAGING__ */

#endif /* (defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)) && !defined(__NFB_SINGLE_ROM__)*/


#ifdef __MULTIPLE_BINARY_FILES__
//==============================================================================
// LANG PACK GFH header body
//==============================================================================
__lang_pack_gfh__ const LANG_PACK_GFH g_lang_pack_gfh =
{
      //GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,

         MAUI_VERSION,
         LANGUAGE_PACK,
         MAUI_DEVICE_TYPE,
         SIG_NONE,

         (kal_uint32)(&Load$$LANG_PACK_ROM_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         MAX_LENGTH_LANG_PACK_ROM,
         (kal_uint32)(&Image$$LANG_PACK_ROM_GFH$$Length),
         0,
         0,
         BINARY_ATTRIBUTE
      },
};

//==============================================================================
// CUSTPACK GFH header body
//==============================================================================
__custpack_gfh__ const CUSTPACK_GFH g_custpack_gfh =
{
      //GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,

         MAUI_VERSION,
         CUSTOM_PACK,
         MAUI_DEVICE_TYPE,
         SIG_NONE,

         (kal_uint32)(&Load$$CUSTPACK_ROM_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         MAX_LENGTH_CUSTPACK_ROM,
         (kal_uint32)(&Image$$CUSTPACK_ROM_GFH$$Length),
         0,
         0,
         BINARY_ATTRIBUTE
      },
};

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

#else

//==============================================================================
// JUMP TABLE GFH header body
//==============================================================================
__jump_table_gfh__ const JUMP_TABLE_GFH g_jump_table_gfh =
{
      //GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,

         MAUI_VERSION,
         JUMP_TABLE,
         MAUI_DEVICE_TYPE,
         SIG_NONE,

         (kal_uint32)(&Load$$JUMP_TABLE_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         MAX_LENGTH_JUMP_TABLE,
         (kal_uint32)(&Image$$JUMP_TABLE_GFH$$Length),
         0,
         0,
         BINARY_ATTRIBUTE
      },
};

#endif /* defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) */


#endif /* __MULTIPLE_BINARY_FILES__ */

//==============================================================================
// THIRD ROM GFH header body
//==============================================================================

#ifdef __NFB_THIRD_ROM_SUPPORT__
__third_rom_gfh__ const THIRD_ROM_GFH g_third_rom_gfh =
{
      //GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,

         MAUI_VERSION,
         THIRD_ROM,
         MAUI_DEVICE_TYPE,
         SIG_NONE,

         (kal_uint32)(&Load$$THIRD_ROM_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         MAX_LENGTH_THIRD_ROM,
         (kal_uint32)(&Image$$THIRD_ROM_GFH$$Length),
         0,
         0,
         BINARY_ATTRIBUTE
      },
};

#endif

#ifdef __SECURE_RO_ENABLE__
#if !(defined(__SMART_PHONE_MODEM__) && defined(__X_BOOTING__))
#ifndef __SECURE_RO_S_DISABLE__
//==============================================================================
// SecureRO_S's GFH header body
//==============================================================================
__secure_ro_s_gfh__ const SECURE_RO_GFH g_secure_s_gfh =
{
      //GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,

         SECURE_RO_VERSION,
         SECURE_RO_S,
         FLASH_DEV_NONE,
         SECURE_RO_SIGNATURE_TYPE,

         (kal_uint32)(&Load$$SECURE_RO_S_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         GFH_FILE_MAX_SIZE_IGNORED,
         (kal_uint32)(&Image$$SECURE_RO_S_GFH$$Length),
         SECURE_RO_SIGNATURE_LEN
      },

      //GFH_SECURE_RO_INFO_v1
      {
         GFH_HEADER(GFH_SECURE_RO_INFO, 1),
         FALSE,
         SECURE_RO_ENCRYPTED_BY_KEY
      },

      //GFH_CBR_RECORD_INFO_v1
      {
         GFH_HEADER(GFH_CBR_RECORD_INFO, 1),
         CBR_RECORD_SECURE_RO_S
      },
 };

//==============================================================================
// SecureRO_S's Signature
//==============================================================================
__secure_ro_s_signature_section__ const unsigned long g_secure_ro_s_sig[SECURE_RO_SIGNATURE_LEN>>2] = {SIG_HASH_VER};

#endif /* !__SECURE_RO_S_DISABLE__ */

//==============================================================================
// SecureRO_ME's GFH header body
//==============================================================================
__secure_ro_me_gfh__ const SECURE_RO_GFH g_secure_ro_me_gfh =
{
      //GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,

         SECURE_RO_VERSION,
         SECURE_RO_ME,
         FLASH_DEV_NONE,
         SECURE_RO_SIGNATURE_TYPE,

         (kal_uint32)(&Load$$SECURE_RO_ME_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         GFH_FILE_MAX_SIZE_IGNORED,
         (kal_uint32)(&Image$$SECURE_RO_ME_GFH$$Length),
         SECURE_RO_SIGNATURE_LEN
      },

      //GFH_SECURE_RO_INFO_v1
      {
         GFH_HEADER(GFH_SECURE_RO_INFO, 1),
         TRUE,
         SECURE_RO_ENCRYPTED_BY_KEY
      },

      //GFH_CBR_RECORD_INFO_v1
      {
         GFH_HEADER(GFH_CBR_RECORD_INFO, 1),
         CBR_RECORD_SECURE_RO_ME
      },

 };

//==============================================================================
// SecureRO_ME's Signature
//==============================================================================
__secure_ro_me_signature_section__ const unsigned long g_secure_ro_me_sig[SECURE_RO_SIGNATURE_LEN>>2] = {SIG_HASH_VER};

#endif /* !(__SMART_PHONE_MODEM__ && __X_BOOTING__) */
#endif /* __SECURE_RO_ENABLE__ */


//==============================================================================
// VIVA GFH header body
//==============================================================================

#ifdef __VI_ENABLED__

#pragma arm section rodata = "VIVA_GFH"

const VIVA_GFH g_viva_gfh =
{
      //GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,

         MAUI_VERSION,
         VIVA,
         MAUI_DEVICE_TYPE,
         SIG_NONE,

         (kal_uint32)(&Load$$VIVA_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         GFH_FILE_MAX_SIZE_IGNORED,
         (kal_uint32)(&Image$$VIVA_GFH$$Length),
         0,
         0,
         BINARY_ATTRIBUTE
      },
};

#pragma arm section rodata

#endif

//==============================================================================
// Misc
//==============================================================================
kal_uint32 DummyReference()
{
    kal_uint32 size = 0;

    size += (kal_uint32)(&g_maui_gfh)+(kal_uint32)(&g_maui_sig);

#if (defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)) && !defined(__NFB_SINGLE_ROM__)
    size += (kal_uint32)(&g_s_maui_gfh) + (kal_uint32)(&g_s_maui_sig);

#if defined(__DEMAND_PAGING__)
    size += (kal_uint32)(&g_odp_gfh);
#endif

#endif

#if defined(__SECURE_RO_ENABLE__)
#if !(defined(__SMART_PHONE_MODEM__) && defined(__X_BOOTING__))

#ifndef __SECURE_RO_S_DISABLE__
    size += (kal_uint32)(&g_secure_s_gfh)+(kal_uint32)(&g_secure_ro_s_sig) + (kal_uint32)(&g_secure_ro_me_gfh) + (kal_uint32)(&g_secure_ro_me_sig);
#else
    size += (kal_uint32)(&g_secure_ro_me_gfh) + (kal_uint32)(&g_secure_ro_me_sig);
#endif /* __SECURE_RO_S_DISABLE__ */

#endif /* !(__SMART_PHONE_MODEM__ && __X_BOOTING__) */
#endif /* __SECURE_RO_ENABLE__ */

    return size;
}

#endif /* __SV5_ENABLED__ || __SV5X_ENABLED__ */

