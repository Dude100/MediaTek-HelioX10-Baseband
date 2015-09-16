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
 *   bl_loader.h
 *
 * Project:
 * --------
 *   NFB - Bootloader
 *
 * Description:
 * ------------
 *   Bootloader header, loading related.
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

#ifndef _BOOTLOADER_LOADER_H
#define _BOOTLOADER_LOADER_H

#ifdef __SV5_ENABLED__
#include "bl_BootInfo.h"
#include "br_GFH_maui_info.h"
#endif /* __SV5_ENABLED_ */

#include "kal_general_types.h"
#include "bl_nfi_wrapper.h"
#include "bl_FOTA.h"
#include "bl_setting.h"
#include "bl_status.h"

#define BL_SEARCH_IMAGE_BLOCK_RANGE   (0x200000)
#define FOTA_IMAGE_END_ID             (0x474D494C)   /* LIMG */

#define FOTA_ID_IMAGEHEADER           (0x41544F46)   /* FOTA */
#define ENFB_ID_IMAGEHEADER           (0x42464E45)   /* ENFB , Dynamic load Binary */
#define RESB_ID_IMAGEHEADER           (0x42534552)   /* RESB , NAND MBA Resource Binary */
#define FFBR_ID_IMAGEHEADER           (0x52424646)   /* FFBR , First FactoryBin ROM */

#define MTK_ILB_TAG_ELEMENTS (7)
#define MTK_ILB_TAG_SIZE     (MTK_ILB_TAG_ELEMENTS<<2)

#define BIT_ERROR_THRESHOLD 6

//The 4 tags for the ILB tails should be the same of length
#define MTK_ILB_TAIL_TAG {0xf83f03e0, 0xf83f03e0, 0x5f4b544d, 0x5f424c49, 0x4c494154, 0xf83f03e0, 0xf83f03e0}  /* MTK_ILB_TAIL */
#define MTK_ILB_TEMP_TAG {0x0000ffff, 0x0000ffff, 0x5f4b544d, 0x5f424c49, 0x504d4554, 0x0000ffff, 0x0000ffff}  /* MTK_ILB_TEMP */
#define MTK_ILB_BAK_TAG  {0xffc0fc00, 0xffc0fc00, 0x5f4b544d, 0x5f424c49, 0x004b4142, 0xffc0fc00, 0xffc0fc00}  /* MTK_ILB_BAK  */
#define MTK_ILB_FOTA_TAG {0x07ff001f, 0x07ff001f, 0x5f4b544d, 0x5f424c49, 0x41544f46, 0x07ff001f, 0x07ff001f}  /* MTK_ILB_FOTA */
#define MTK_ILB_DLPKG_TAG {0xf83f03e0, 0x0000ffff, 0x5f4b544d, 0x5f424c49, 0x47504c44, 0xf83f03e0, 0x0000ffff}  /* MTK_ILB_DLPG */

#define BL_INFO_V1  0x31564c42 /* "BLV1" */

#define BL_INFO_POWER_LATCHED           0x00000001
#define BL_INFO_FIRST_POWER_ON          0x00000002
#define BL_INFO_USBDL_IN_BL_CONNECTED   0x00000004
#define BL_INFO_SUSBDL_IN_BL_ENABLED    0x00000008
#define BL_FAST_META_TRIGGERED          0x00000010
#define BL_FAST_LOGO_DISPLAYED          0x00000020
#define BL_BROM_CMD_MODE_DISABLED       0x00000040

#define MTK_EXT_BL_END_MARK {0xb83701e7, 0x2894eaee, 0x5f4c4245, 0x5f444e45, 0x4b52414d, 0xb83701e7, 0x2894eaee}  /* EBL_END_MARK */

#ifdef __MTK_SECURE_PLATFORM__   
#define ROMINFO_INDEX 2
#else
#define ROMINFO_INDEX 0
#endif /*__MTK_SECURE_PLATFORM__*/

typedef enum
{
   ILB_HEADER_PAGE_INDEX   = 0,
   IMAGE_SPACE_PAGE_INDEX  = 1,
   IMAGE_LIST_PAGE_INDEX   = 2,
   VERSION_INFO_PAGE_INDEX = 3,
   EXTRA_INFO_PAGE_INDEX   = 4,

   VALID_PAGE_NUMBER
} ILB_PAGE_TYPE;

#if defined(__FOTA_DM__)
#define IMAGE_BUFFER_SIZE  (16384)
#define FOTA_WORK_BUFFER_NUM  (3)
#endif



typedef enum 
{
   NFB_ILB_MAUI              =  0xfd00,
   NFB_ILB_TEMP,
   NFB_ILB_BAKUP,
   NFB_ILB_FOTA,
   NFB_ILB_DLPKG,
   NFB_ILB_EMPTY             = 0xfffe,
   NFB_ILB_NONE              = 0xffff
} NFB_ILB_TYPE;


typedef struct {
   kal_uint32  m_load_addr;   /* destination address at shadow RAM */
   kal_uint32  m_length;      /* length of certain image */
   kal_uint32  m_start_block; /* the started block number */
   kal_uint32  m_reserved;    /* m_reserved field ; special types : ENFB , RESB , FOTA */
} Nand_ImageInfo_S;


typedef struct {
   Nand_ImageInfo_S  m_image[10];
   kal_uint32        m_image_count;
   Nand_ImageInfo_S  m_image_ext[10];
} Nand_ImageList_S;

#ifndef __SV5_ENABLED__

typedef struct _EXT_BOOTL_LINKADDR_ {
   kal_uint32  cs;
   kal_uint32  blockNo;                //Physical block number
} EXT_BOOTL_LINKADDR;

#ifdef __EBL_UPDATE_TOOL_SUPPORT_NAND__

typedef struct _EXT_BOOTL_HEADER_ {
   kal_char    ID[16];
   kal_char    version[4];
   kal_uint8   reserved[12];

   EXT_BOOTL_LINKADDR linkAddr[64];
   EXT_BOOTL_LINKADDR linkAddrBak[64];   
   kal_uint32  lastLogicalBlock;       //Logical number of the last block of Ext Bootlaoder
   
} EXT_BOOTL_HEADER;

#else

typedef struct _EXT_BOOTL_HEADER_ {
   kal_char    ID[16];
   kal_char    version[4];
   kal_uint32  length;
   kal_uint32  checksum;
   
   EXT_BOOTL_LINKADDR linkAddr[10];
   kal_uint32  lastLogicalBlock;       //Logical number of the last block of Ext Bootlaoder
   
   kal_uint8   reserved[144];
} EXT_BOOTL_HEADER;

#endif

typedef struct _NFIAccess
{
   kal_uint32  readAddr1;
   kal_uint32  readAddr2;
} NFI_ACCESS;
           
#endif

typedef kal_bool (* bl_Hash_Init_Fp)(void);
typedef kal_bool (* bl_Hash_Append_Fp)(kal_uint32 addr, kal_uint32 len);
typedef kal_bool (* bl_Hash_Finish_Fp)(kal_uint32 digest, kal_uint32 len);
typedef kal_bool (* bl_Sym_Decrypt_Fp)(kal_uint32 dest_addr, kal_uint32 src_addr, kal_uint32 len, kal_uint32 key, kal_uint32 key_len);
typedef kal_bool (* bl_Asym_Decrypt_Fp)(kal_uint32 dest_addr, kal_uint32 src_addr, kal_uint32 len, kal_uint32 key, kal_uint32 key_len);

#define FUNC_TABLE_ID      "MTK_FUN_TABL"

#define BL_MAX_ILB_COUNT 16
typedef struct _BL_FUNC_TABLE
{
   bl_Hash_Init_Fp         m_hash_init_fp;
   bl_Hash_Append_Fp       m_hash_append_fp;
   bl_Hash_Finish_Fp       m_hash_finish_fp;
   bl_Sym_Decrypt_Fp       m_sym_decrypt_fp;
   bl_Asym_Decrypt_Fp      m_asym_decrypt_fp;
   kal_uint32 m_table_size;
   kal_uint8 m_func_table_id[16];
} T_BL_FUNC_TABLE;

extern const T_BL_FUNC_TABLE g_BlFunc_Table;
                  
typedef struct {
   kal_uint32   m_ua_map_blk;
   kal_uint32   m_ua_img_size;
} UA_Misc_Info;

typedef struct {
   kal_uint32   m_bl_ilb_start;
   kal_uint32   m_bl_ilb_blk;
} BL_ILB_Info;

typedef struct {
   kal_uint32                  m_bl_magic_head;
   kal_uint32                  m_bl_random_seed;
   kal_uint32                  m_bl_bootup_flag;
   kal_uint8                   m_poweron_param;
   kal_uint8                   m_reserved[1];
   kal_uint8                   m_emi_param[2];   
   kal_uint8                   m_bl_version_str[16];
   kal_uint32                  m_bl_token[8];   
   kal_uint32                  m_reserved2[16];
   //Total 128 byte exactly
} BL_MAUI_ShareData;

#if defined(__SV5_ENABLED__)

typedef struct {
   kal_uint32         m_info_type_magic;  //The magic pattern to represent the update agent   
   GFH_MAUI_INFO_v1   m_maui_info;
   kal_uint32         m_reserve[1024>>2]; //The reserved 1kb region is used in CDL to backup BootCert
} UPDATING_RECORD;

#endif /* __SV5_ENABLED__ */

#if defined(__EXT_BL_UPDATE__)
typedef enum
{
   E_EXTBL_PRIMARY_REGION,
   E_EXTBL_BACKUP_REGION
} E_EXT_BL_REGION;

typedef struct
{
   E_EXT_BL_REGION   m_current_bl;
   kal_uint32        m_current_bl_size;
   
#if !defined(__SV5_ENABLED__)
   kal_uint32        m_ext_bl_addr;
   kal_uint32        m_ext_bl_max_size;
   kal_uint32        m_ext_bl_bak_addr;
   kal_uint32        m_ext_bl_bak_max_size;
#endif /* __SV5_ENABLED__ */
   
} BL_EXT_BL_UPDATE_INFO;

#endif /* __EXT_BL_UPDATE__ */

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
typedef struct {
#if defined(__SV5_ENABLED__)
   FlashLayout                 m_bl_flash_layout;
#else
   Nand_ImageList_S            m_bl_image_list;
#endif
   BL_MAUI_ShareData           m_bl_maui_share_data;
   BOOTL_HEADER                m_bl_header;
   Nand_ImageSpace_ST          m_bl_image_space;
   UA_Misc_Info                m_bl_ua_info;
   BL_ILB_Info                 m_bl_ilb_info;
#ifdef __FOTA_DM__   
   kal_uint32                  m_reserved[258]; 
#endif
} BL_Info_Wrapper_st;

#else

typedef struct {
   BL_MAUI_ShareData           m_bl_maui_share_data;
   //Total 128 byte exactly
} BL_Info_Wrapper_st;

#endif /* _NAND_FLASH_BOOTING_ */

/* Exported Functions & data structures */


extern Nand_ImageInfo_S *GetImageInfo(kal_uint32 n);
extern void*             GetVersionInfoAddress(void);
extern kal_bool          LoadImageListblock(kal_uint32 start_blk);
extern kal_uint32        LoadPrimariMAUI(void);
extern void              LoadDataForSecureUSBDL(void);
extern BOOTL_HEADER      BLHeader;


extern const kal_char   SUPER_BLOCK_PATTERN[];
extern const kal_uint32 IMAGE_LIST_BLOCK_TAIL_PATTERN[];
extern const kal_uint32 IMAGE_LIST_BLOCK_TEMP_PATTERN[];
extern const kal_uint32 IMAGE_LIST_BLOCK_BACKUP_PATTERN[];
extern const kal_uint32 IMAGE_LIST_BLOCK_FOTA_PATTERN[];

extern void InitFlashDriver(void);
extern kal_uint32 LoadMauiBody(void);
extern kal_uint32 GetMainRegionStartBlock(void);
extern BL_STATUS LoadMAUIFirstPart(void);

#if defined(__X_BOOTING__)
extern kal_bool XBOOT_BootEnd(void);
#endif

#ifndef __SV5_ENABLED__
extern EXT_BOOTL_HEADER  EBLHeader;
#define LOGICAL_BLOCK_ADDRESS  (0xffffffff)
#define PHYSICAL_BLOCK_ADDRESS (0x00000000)
#endif

#endif /* _BOOTLOADER_LOADER_H */

