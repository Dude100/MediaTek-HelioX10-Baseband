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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BL_NFI_DEF_WRAPPER_H__
#define __BL_NFI_DEF_WRAPPER_H__

#if defined(__SV5_ENABLED__) && defined(__NFI_SHARED_DRV__) && defined(__MINI_BOOTLOADER__)
#define __USE_NFI_SHARED_DRV__
#endif

#if !defined(__USE_NFI_SHARED_DRV__)
typedef enum 
{
   NFI_SUCCESS                =  0,      
   NFI_ECC_1BIT_CORRECT       =  1,   
   NFI_EMPTY_PAGE              =  2,   
   FUE_SUCCESS                 =  3,
   NFI_ZERO_POINTER           = -1,   
   NFI_READ_DATA_TIMEOUT      = -2,
   NFI_READ_SPARE_TIMEOUT     = -3,
   DMA_TRANSFER_DATA_TIMEOUT  = -4,
   DMA_TRANSFER_SPARE_TIMEOUT = -5,
   NFI_ECC_2BITS_ERR           = -6,
   NFI_WRITE_DATA_TIMEOUT      = -7,
   NFI_WRITE_SPARE_TIMEOUT     = -8,
   NFI_BUFFER_NOT_ALIGNED      = -9,   
   NFI_TRANSFER_DATA_TIMEOUT   = -10,
   NFI_TRANSFER_SPARE_TIMEOUT  = -11,
   NFI_ERASE_TIMEOUT           = -12,
   NFI_ERASE_FAILED            = -13,
   NFI_PROGRAM_FAILED          = -14,
   FUE_INVALID_MAPPING        = -15,
   FUE_MAPPING_TABLE_CORRUPT   = -16,
   FUE_NO_MORE_VALID_MAPPING   = -17,
   FUE_BACKUP_ERROR            = -18,
   FUE_IMGLIST_ERROR           = -19,
   FUE_FOTA_IMAGE_TOO_BIG      = -20,
   FUE_UNSUPPORTED_TYPE        = -21,
   NFI_GENERAL_ERR            =  -22
} _RET_CODE;
#endif

#if defined(__SV5_ENABLED__) || defined(__NFI_VERSION3__) || defined(__NFI_VERSION3_1__)
#define PAGE_SHIFT            (BLHeader.pageShift)
#else
#define PAGE_SHIFT            (BLHeader.NFIinfo.pageShift)
#endif

#define BLOCK_SHIFT           (BLHeader.blockShift)
#define PAGE_PER_BLOCK_SHIFT  (BLOCK_SHIFT - PAGE_SHIFT)
#define PAGE_SIZE             (BLHeader.NFIinfo.pageSize)
#define BLOCK_SIZE            (PAGE_SIZE << (BLOCK_SHIFT-PAGE_SHIFT))
#define PAGE_PER_BLOCK        (BLHeader.pagesPerBlock)


#define BOOTLOADER_BLOCK_COUNT    (6)

//NFI_SUBMENU
#if defined(__USE_NFI_SHARED_DRV__)
#include "nfi_sw.h"
#elif defined(__SV5_ENABLED__) || defined(__NFI_VERSION3__) || defined(__NFI_VERSION3_1__)

typedef struct _NFIInfo
{
   kal_uint16  spareSize;       /* 16, 26, 27, 28 */
   kal_uint16  blockSize;       /* in pages */
} NFI_SUBMENU;

#endif

//NFI_MENU & BOOTL_HEADER
#if defined(__SV5_ENABLED__)

#include "nfb_header.h"
typedef NFB_HEADER BOOTL_HEADER;

#elif defined(__NFI_VERSION3__) || defined(__NFI_VERSION3_1__)

typedef struct _NFIType
{
   kal_uint16  IOInterface;     /* IO_8BITS or IO_16BITS */
   kal_uint16  pageSize;        /* 512, 2048, 4096 bytes */
   kal_uint16  addressCycle;
} NFI_MENU;

typedef struct _BOOTLHeader_
{
   kal_char         ID1[12];
   kal_char         version[4];
   kal_uint32		length;
   kal_uint32		startAddr;
   kal_uint32		checksum;
   kal_char			ID2[8];
   NFI_MENU			NFIinfo;
   kal_uint16		spareSize;
   kal_uint16		pagesPerBlock;
   kal_uint16		totalBlocks;
   kal_uint16		pageShift;
   kal_uint16		blockShift;
   kal_uint16		linkAddr[BOOTLOADER_BLOCK_COUNT];
   kal_uint16		lastBlock; // The 1st block of MAUI 
   kal_uint16		Dummy16;   // Make this structure as 4 bytes multiple.
} BOOTL_HEADER;

#else // defined(__NFI_VERSION3__)

/* Data Structures */
typedef struct _NFIType
{
   kal_uint16  IOInterface;     /* IO_8BITS or IO_16BITS */
   kal_uint16  pageSize;        /* 512, 2048 */
   kal_uint16  addressCycle;
   kal_uint16  pageShift;
} NFI_MENU;

typedef struct _BOOTLHeader_
{
   kal_char    ID1[12];
   kal_char    version[4];
   kal_uint32  length;
   kal_uint32  startAddr;
   kal_uint32  checksum;
   kal_char    ID2[8];
   NFI_MENU    NFIinfo;
   kal_uint16  pagesPerBlock;   
   kal_uint16  totalBlocks;
   kal_uint16  blockShift;
   kal_uint16  linkAddr[BOOTLOADER_BLOCK_COUNT];
   kal_uint16  lastBlock;
} BOOTL_HEADER;

#endif

//IO_8BITS & NFI_Error_Code & SD necessary
#if defined(__USE_NFI_SHARED_DRV__)
#include "br_sd_flash_nand_export_v1.h"
#include "nfi_sw.h"
#else
#include "bl_NFI.h"
#endif

#endif /* __BL_NFI_DEF_WRAPPER_H__ */

