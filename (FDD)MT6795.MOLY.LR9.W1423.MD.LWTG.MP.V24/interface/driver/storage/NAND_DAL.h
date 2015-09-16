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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *  NAND_DAL.H
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This is a NAND Flash Device Abstraction Layer file.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef NAND_DAL_H
#define NAND_DAL_H

/****************************
 * Include Header Files     *
 ****************************/
#if defined(__DOWNLOAD_AGENT__) 
#include "NAND_DA_internal.h"
#include "NAND_DAL_internal.h"
#endif
#include "fota_error.h"
// Add for RHR
// RHR Remove    #include "kal_non_specific_general_types.h"
#include "kal_general_types.h"
// Add for RHR
/*******************************************************************************
 *  Operation error code for NFB functions
 *******************************************************************************/
#define ERROR_NFB_SUCCESS             (ERROR_FOTA_SUCCESS)
#define ERROR_NFB_READ                (ERROR_FOTA_READ)
#define ERROR_NFB_PROGRAM             (ERROR_FOTA_PROGRAM)
#define ERROR_NFB_ERASE               (ERROR_FOTA_ERASE)
#define ERROR_NFB_BAD_BLOCK           (ERROR_FOTA_BAD_BLOCK)
#define ERROR_NFB_CHECKSUM            (ERROR_FOTA_NFB_CHECKSUM)
#define ERROR_NFB_ECC_CORRECTED       (ERROR_FOTA_ECC_CORRECTED)
#define ERROR_NFB_INVALID_PARAMETER	  (ERROR_FOTA_INVALID_PARAMETER)
#define ERROR_NFB_NOT_INITIALIZED     (ERROR_FOTA_NOT_INITIALIZED)
#define ERROR_NFB_CUSTOMIZATION       (ERROR_FOTA_CUSTOMIZATION)
#define ERROR_NFB_MASK                (0x80000000)

/**************************************
 * Returns:     FS_NO_ERROR
 *              FS_NAND_DEVICE_NOT_SUPPORTED
 *              FS_FLASH_MOUNT_ERROR
 *************************************/
kal_int32 DAL_init (void);
kal_uint32 DAL_GetBlockSize(void);
kal_uint32 DAL_GetPageSize(void);
kal_bool NANDsanitycheck_Factory(void);

typedef enum
{
	NFB_READ_PAGE_ONLY_WITH_ECC = 0,
	NFB_READ_PAGE_ONLY_WITHOUT_ECC,
	NFB_READ_SPARE_ONLY_WITHOUT_ECC,
	NFB_READ_PAGE_SPARE_WITHOUT_ECC,
	NFB_READ_PAGE_FLAG_END
}NFB_ReadPage_t;

#ifdef _NAND_FLASH_BOOTING_

int NFB_ProgramPhysicalPage(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data, kal_bool DALRemap);

int NFB_ProgramPhysicalSpare(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data, kal_bool chksum, kal_bool DALRemap);

int NFB_ErasePhysicalBlock(kal_uint32 PhyBlock, kal_bool DALRemap);

int	NFB_MarkBadBlock(kal_uint32 PhyBlock, kal_bool DALRemap);

int	NFB_ProgramPhysicalPageWithSpare(kal_uint32 PhyBlock, kal_uint32 PhyPage, void *Data, void *Spare, kal_bool DALRemap);

kal_int32 NFB_ReadPhysicalPage(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data);

int NFB_ReadPhysicalSpare(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data, kal_bool chksum);

#if defined(__DOWNLOAD_AGENT__)
int NFB_ForceEraseBlock(kal_uint32 PhyBlock, kal_bool DALRemap);
kal_int32 NFB_ReadPhysicalPageSpareECC(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data, void *Spare, NFB_ReadPage_t flag);
kal_int32 NFB_GetFlashInfo(NFB_FLASH_INFO* flash_info_p);
kal_uint32 NFB_HB_init(void * BufferPtr, kal_uint32 Length, kal_bool Scramble);
kal_uint32 NFB_HB_QueryBlock(kal_uint32 Block, kal_uint32 QueryType);
kal_uint32 NFB_HB_UpdateBadBlock(kal_uint32 phyBlock);
kal_uint32 NFB_HB_WriteBack();
#endif

#if defined(__UBL__)
kal_int32 NFB_SyncFlashInfo(void* flash_info_p, kal_uint32 len);
#endif

#if defined(__FOTA_DM__)
kal_int32 NFB_ReadPhysicalPageWithSpare(kal_uint32 PhyBlock, kal_uint32 PhyPage, kal_uint8* Data);
#endif // defined(__FOTA_DM__)

kal_int32 NFB_CheckGoodBlock(kal_uint32 Block);

kal_int32 NFB_CheckGoodBlock2(kal_uint32 Block, kal_bool DALRemap);

kal_int32 demp_CheckGoodBlock(kal_uint32 Block);

kal_int32 demp_ReadPhysicalPage(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data);

#endif //_NAND_FLASH_BOOTING_

#endif /*NAND_DAL_H*/
