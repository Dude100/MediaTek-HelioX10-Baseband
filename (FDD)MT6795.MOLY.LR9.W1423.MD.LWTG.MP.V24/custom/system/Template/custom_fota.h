/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   custom_fota.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the FOTA (Firmware Over the Air) related setting.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CUSTOM_FOTA_H__
#define __CUSTOM_FOTA_H__
#include "kal_general_types.h"
#include "flash_opt.h"

#define END_MAUI_INFO  {0xFFFFFFFF, 0xFFFFFFFF}
/*****************************************
 * Don't modify any code above this line *
 *****************************************/

#if defined(__FOTA_DM__)

#define FUE_CACHE_WAY     (1) /* must be power of 2 */
#define FUE_CACHE_ENTRIES (2) /* must be power of 2 */

#endif /* __FOTA_DM__ */

/*****************************************
 * Don't modify any code below this line *
 *****************************************/
#if defined(__MTK_TARGET__)

#define FOTA_SYSRAM_SHARED_BUFFER_SIZE  (0x1000)

extern const kal_uint32 FOTA_FUE_RESIDENT_SPACE;

typedef kal_uint16 FOTA_NFB_Table_Element_type;

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

#if defined(__FOTA_DM__)

typedef struct {
   kal_uint32 load_base;
   kal_uint32 load_length;
}FOTA_NFB_ROM_Image_Info;

kal_uint32 FOTA_Reserved_Area_Base_Address(void);
void FOTA_GetPackageStorage(kal_uint32 *base_addr, kal_uint32 *len);
kal_uint32 FOTA_GetPackageStorageBase(void);
kal_uint32 FOTA_GetPackageStorageSize(void);
kal_uint32 FOTA_GetRAMBaseAddr(void);
kal_uint32 FOTA_GetFATBaseAddr(void);

#endif /* __FOTA_DM__ */

#else /* !(_NAND_FLASH_BOOTING_||__EMMC_BOOTING__) */

#include "fat_fs.h"
#include "DrvFlash.h"

typedef struct {
   kal_uint32 BlockBase;
   kal_uint32 BlockSize;
} FlashBlockInfo;
#define EndBlockInfo  {0, 0}

#if defined(__FOTA_DM__)
/* For FOTA, these region information shoule be put on RAM */
extern FlashBlockInfo NORBlockInfo[];
extern FlashRegionInfo NORRegionInfo[];
extern FlashBankInfo FOTANORBankInfo[];
#endif /* __FOTA_DM__ */

#define FOTA_NOR_FLASH_PAGE_SIZE  (0x800)

#endif /* !(_NAND_FLASH_BOOTING_||__EMMC_BOOTING__) */

#else /* !__MTK_TARGET__ */

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

#else /* !(_NAND_FLASH_BOOTING_||__EMMC_BOOTING__) */

#if defined(__FOTA_DM__)

#define FOTA_NOR_FLASH_PAGE_SIZE  (0)

#endif /* __FOTA_DM__ */

#endif /* !(_NAND_FLASH_BOOTING_||__EMMC_BOOTING__) */

#endif /*__MTK_TARGET__ */

extern kal_int32 FOTA_CustomInitialize(void);

extern const kal_uint32  FOTA_MAX_PAGE_SIZE;

#endif /*__CUSTOM_FOTA_H__*/
