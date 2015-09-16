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
 *   FTL.h
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   Abstraction layer preparing for FTL
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __BL_FTL_H__
#define __BL_FTL_H__

#include "kal_general_types.h"

typedef enum 
{
   FTL_SUCCESS = 0,
   FTL_ERROR_READ_FAILURE = -10000,
   FTL_ERROR_WRITE_FAILURE,
   FTL_ERROR_BAD_BLOCK,
   FTL_ERROR_OPERATION_RETRY,
   FTL_ERROR_INVALID_PARAMETER,
   FTL_ERROR_ERASE_FAILURE,
   FTL_ERROR_NON_EMPTY,
   FTL_ERROR_NON_EMPTY_CHECK,
   FTL_ERROR_ECC_FAILURE,
   FTL_ERROR_ECC_CORRECTED,
   FTL_ERROR_OTHER_ERROR
} FTL_STATUS_CODE;

/*****************************************************************************
 * Macro definition
 *****************************************************************************/

/*****************************************************************************
 * Structure definition
 *****************************************************************************/
typedef struct FTL_OptParam
{
    kal_bool bypass_dal; /* NAND only */
    kal_bool is_polling;   /* NAND & eMMC */
} FTL_OptParam, *FTL_OptParamPtr;

/*************************************************************************
 * Type definition
 *************************************************************************/
typedef FTL_STATUS_CODE (*FTL_InitFunc)(void *pArgv);
typedef FTL_STATUS_CODE (*FTL_DeInitFunc)(void *pArgv);
typedef FTL_STATUS_CODE (*FTL_ReadPageFunc)(kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param);
typedef FTL_STATUS_CODE (*FTL_QueryInfoFunc)(void *pArgv);
typedef FTL_STATUS_CODE (*FTL_WritePageFunc)(kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param);
typedef FTL_STATUS_CODE (*FTL_CheckGoodBlockFunc)(kal_uint32 block, FTL_OptParam *opt_param);
typedef FTL_STATUS_CODE (*FTL_MarkBadBlockFunc)(kal_uint32 block, FTL_OptParam *opt_param);
typedef FTL_STATUS_CODE (*FTL_EraseBlockFunc)(kal_uint32 block, FTL_OptParam *opt_param);
typedef kal_uint32      (*FTL_GetBlockSizeFunc)(kal_uint32 block, FTL_OptParam *opt_param);
typedef kal_uint32      (*FTL_GetPageSizeFunc)(void);
typedef kal_uint32      (*FTL_AddrToBlockPageFunc)(kal_uint32 addr, kal_uint32 *pBlock, kal_uint32 *pPage, FTL_OptParam *opt_param);
typedef kal_uint32      (*FTL_BlockPageToAddrFunc)(kal_uint32 block, kal_uint32 page, kal_uint32 *pAddr, FTL_OptParam *opt_param);

/*************************************************************************
 * Type definition
 *************************************************************************/

typedef struct FTL_FuncTbl
{
   FTL_InitFunc                FTL_Init;
   FTL_InitFunc                FTL_DeInit;   
   FTL_ReadPageFunc            FTL_ReadPage;
   FTL_QueryInfoFunc           FTL_QueryInfo;
   FTL_WritePageFunc           FTL_WritePage;
   FTL_CheckGoodBlockFunc      FTL_CheckGoodBlock;
   FTL_MarkBadBlockFunc        FTL_MarkBadBlock;
   FTL_EraseBlockFunc          FTL_EraseBlock;
   FTL_GetBlockSizeFunc        FTL_GetBlockSize;
   FTL_GetPageSizeFunc         FTL_GetPageSize;
   FTL_AddrToBlockPageFunc     FTL_AddrToBlockPage;
   FTL_BlockPageToAddrFunc     FTL_BlockPageToAddr;
} FTL_FuncTbl, *FTL_FuncTblPtr;

#if defined(__EMMC_BOOTING__)
#define FTL_EMMC_PAGE_SIZE    (8*1024) // 8KB page
#define FTL_EMMC_BLOCK_SIZE   (512*1024) // 512KB block

#if !defined(__FUE__) && !defined(__UBL__)
#define get_FTL_lock() \
    do { \
        extern kal_bool kal_query_systemInit(void); \
        extern kal_bool INT_QueryExceptionStatus(void); \
        if (!kal_query_systemInit() && !INT_QueryExceptionStatus()) \
        { \
            kal_take_mutex(ftl_lock); \
        } \
    } while(0)

#define free_FTL_lock() \
    do { \
        extern kal_bool kal_query_systemInit(void); \
        extern kal_bool INT_QueryExceptionStatus(void); \
        if (!kal_query_systemInit() && !INT_QueryExceptionStatus()) \
        { \
            kal_give_mutex(ftl_lock); \
        } \
    } while(0)

extern kal_bool FTL_isPollingMode();
#endif /* !__FUE__ && !__UBL__ */

#endif /* __EMMC_BOOTING__ */

#endif /* __BL_FTL_H__ */

