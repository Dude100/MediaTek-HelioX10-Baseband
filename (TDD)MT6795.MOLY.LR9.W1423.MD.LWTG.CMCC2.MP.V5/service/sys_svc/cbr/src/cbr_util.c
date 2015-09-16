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
 *   CBR_util.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Services for using CBR in the init flow
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__) 
#ifdef __MTK_TARGET__

#include "kal_general_types.h"
#include "cbr.h"
#include "FTL.h"
#include "bl_BootInfo.h"
#include "bl_loader.h"

extern kal_uint32 Image$$INTSRAM_MULTIMEDIA$$Base;

#if defined(_NAND_FLASH_BOOTING_)
#define MAX_PAGE_SIZE 4096
#elif defined(__EMMC_BOOTING__)
#define MAX_PAGE_SIZE 8192
#elif defined(MT6251)
#define MAX_PAGE_SIZE 512
#else
#define MAX_PAGE_SIZE 2048
#endif

static kal_bool cbrutl_inited = KAL_FALSE;

#if defined(__UBL__)

extern kal_uint32 GetMainRegionStartBlock(void);

kal_int32 CBRUtl_InitService(void)
{
   kal_int32 status = 0;
   
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)   

   //NAND and eMMC has already initialized in very early beginning
   
#else

   extern FTL_FuncTbl *g_ftlFuncTbl;
   
   static kal_uint32 page_buff[MAX_PAGE_SIZE/4];
   kal_uint32 cbrStartBlock;

   if(cbrutl_inited)
   {
      return CBR_INITIALIZED;
   }

   g_ftlFuncTbl->FTL_Init(NULL);
   
   CBR_SetEnv(E_CBR_IDX_CBR, page_buff, MAX_PAGE_SIZE, g_ftlFuncTbl);
   cbrStartBlock = GetMainRegionStartBlock();
   status = CBR_Init(E_CBR_IDX_CBR, cbrStartBlock);
   
#endif

   cbrutl_inited = KAL_TRUE;

   return status;
}

#elif defined(__FUE__)

//Not used in FUE

#else

kal_int32 CBRUtl_InitService(void)
{
   kal_int32 status = 0;
   
   static kal_uint32 page_buff[MAX_PAGE_SIZE/4];

   extern FTL_FuncTbl ftlFuncTbl;

   extern BL_Info_Wrapper_st g_pass_info;
   
   kal_uint32 cbrStartBlock;

   if(cbrutl_inited)
   {
      return CBR_INITIALIZED;
   }
   
   ftlFuncTbl.FTL_Init(NULL);

   CBR_SetEnv(E_CBR_IDX_CBR, page_buff, MAX_PAGE_SIZE, &ftlFuncTbl);

   {
      FlashLayout *flashLayoutPtr = (FlashLayout*)&g_pass_info.m_bl_flash_layout;
      cbrStartBlock = flashLayoutPtr->cbrStartBlock;
   }

   status = CBR_Init(E_CBR_IDX_CBR, cbrStartBlock);

   ASSERT(status == CBR_INITIALIZED || status == CBR_SUCCESS);
   
   cbrutl_inited = KAL_TRUE;
      
   return status;
}

#endif

#endif /* __MTK_TARGET__ */
#endif /* __SV5_ENABLED__ || __SV5X_ENABLE__ */

