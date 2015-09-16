/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   simple_memory_manager.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
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

#include "simple_memory_manager.h"
#include "kal_general_types.h"

#if defined(__MTK_TARGET__)
   #include "kal_public_api.h"
#else
   #if !defined(ASSERT)
   #include "assert.h"
   #define ASSERT assert
   #endif
#endif


static kal_uint32 _number_of_one(kal_uint32 value)
{
   kal_uint32 number_of_one = 0;

   while (value)
   {
      number_of_one++;
      value &= (value - 1);
   }

   return number_of_one;
}



kal_uint32 smmInit(STSMM *smm, void *pool_addr, kal_uint32 pool_size)
{
   if (NULL == smm)
   {
      ASSERT(0);
      return 0;
   }

   smm->pool_addr = pool_addr;
   smm->pool_size = pool_size;
   smm->current_ptr = pool_addr;
   return 1;
}



/// Return the available free space from the current_ptr.
kal_uint32 smmGetFreeSpace(STSMM *smm)
{
   kal_uint32 free_space;

   if (NULL == smm)
   {
      ASSERT(0);
      return 0;
   }

   free_space = (kal_uint32)smm->pool_addr + smm->pool_size - (kal_uint32)smm->current_ptr;

   if (free_space & 0x80000000)
   {
      /// the free_space is negative...
      ASSERT(0);
      return 0;
   }
   else
   {
      return free_space;
   }
}



/// Return the available free space from the current_ptr with alignment constraint.
/// Notice that the alignment parameter must be 2^N.
kal_uint32 smmGetFreeSpaceAligned(STSMM *smm, kal_uint32 alignment)
{
   kal_uint32 alignment_minus_one = alignment - 1;
   kal_uint32 free_space;
   kal_uint32 first_match_addr;

   if (NULL == smm || 1 != _number_of_one(alignment))
   {
      ASSERT(0);
      return 0;
   }
   
   first_match_addr = ((kal_uint32)(smm->current_ptr) + alignment_minus_one) & (~alignment_minus_one);
   
   free_space = (kal_uint32)smm->pool_addr + smm->pool_size - first_match_addr;

   if (free_space & 0x80000000)
   {
      /// the free_space is negative but we can not trigger assertion failure here.
      return 0;
   }
   else
   {
      return free_space;
   }
}



/// Memory allocation.
void *smmMalloc(STSMM *smm, kal_uint32 size)
{
   if (NULL == smm)
   {
      ASSERT(0);
      return NULL;
   }

   if ((0 == size) || (size > smmGetFreeSpace(smm)))
   {
      return NULL;
   }
   else
   {
      kal_uint8 *first_match_addr = (kal_uint8 *)smm->current_ptr;

      smm->current_ptr = first_match_addr + size;
      return first_match_addr;
   }
}



/// Memory allocation with alignment constraint.
/// Notice that the alignment parameter must be 2^N.
void *smmMallocAligned(STSMM *smm, kal_uint32 size, kal_uint32 alignment)
{
   if (NULL == smm)
   {
      ASSERT(0);
      return NULL;
   }

   if ((0 == size) || (size > smmGetFreeSpaceAligned(smm, alignment)))
   {
      return NULL;
   }
   else
   {
      kal_uint32 alignment_minus_one = alignment - 1;
      kal_uint8 *first_match_addr = (kal_uint8 *)(((kal_uint32)smm->current_ptr + alignment_minus_one) & (~alignment_minus_one));

      smm->current_ptr = first_match_addr + size;
      return first_match_addr;
   }
}



kal_uint32 smmGetTotalSpace(STSMM *smm)
{
   if (NULL == smm)
   {
      ASSERT(0);
      return 0;
   }
   else
   {
      return smm->pool_size;
   }
}

