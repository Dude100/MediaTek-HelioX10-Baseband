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
 *   simple_memory_manager.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/*!
   @mainpage Simple Memory Manager
   @author  Rey Su
   @version 1.0
   @date    2008/07/31

   @section Simple Memory Manager
   SMM (Simple Memory Manager) is a set of API to provide simple memory management capability.
   SMM provides memory allocation (w/o alignment) and free space query APIs. \n
   Please notice that currently SMM does not provide memory free capability.
   Once the memory is allocated from the memory pool, there is no way to give it back to the pool.
*/

#ifndef __SIMPLE_MEMORY_MANAGER_H__
#define __SIMPLE_MEMORY_MANAGER_H__

#include "kal_general_types.h"


typedef struct
{
   kal_uint32 pool_size;   ///< The total size of the memory pool.
   void *pool_addr;        ///< The start address of the memory pool.
   void *current_ptr;      ///< The current pointer to the available memory block.
} STSMM;



/**
 * @brief            Initializa the STSMM structure.
 * @param smm        pointer to the STSMM structure
 * @param pool_addr  pointer to the memory pool
 * @param pool_size  size of the memory pool
 * @return           If the function succeeds, return 1; otherwise return 0.
 * @remarks
 */
kal_uint32 smmInit(STSMM *smm, void *pool_addr, kal_uint32 pool_size);



/**
 * @brief      Get the available free space of the STSMM structure.
 * @param smm  pointer to the STSMM structure
 * @return     This function will return the available free space of the STSMM structure.
 * @remarks
 */
kal_uint32 smmGetFreeSpace(STSMM *smm);



/**
 * @brief            Get the available free space of the STSMM structure with alignment constraint.
 * @param smm        pointer to the STSMM structure
 * @param alignment  the alignment constraint, must be 2^N
 * @return           This function will return the available free space of the STSMM structure with alignment constraint.
 *                   That is, the available free space from the first memory address matched the alignment constraint.
 * @remarks
 */
kal_uint32 smmGetFreeSpaceAligned(STSMM *smm, kal_uint32 alignment);


/**
 * @brief         Return the memory pointer to the allocated space.
 * @param smm     pointer to the STSMM structure
 * @param size    size of memory block to be allocated
 * @return        If the required memory is available, return the pointer the the allocated space; otherwise return NULL.
 * @remarks
 */
void *smmMalloc(STSMM *smm, kal_uint32 size);



/**
 * @brief            Return the memory pointer to the allocated space with alignment constraint.
 * @param smm        pointer to the STSMM structure
 * @param size       size of memory block to be allocated
 * @param alignment  the alignment constraint, must be 2^N
 * @return           If the required memory is available, return the pointer the the allocated space; otherwise return NULL.
 * @remarks          The returned address will be aligned as specified.
 */
void *smmMallocAligned(STSMM *smm, kal_uint32 size, kal_uint32 alignment);



/**
 * @brief      Get the total space the the STSMM structure.
 * @param smm  pointer to the STSMM structure
 * @return     Return the total space the the STSMM structure.
 * @remarks
 */
kal_uint32 smmGetTotalSpace(STSMM *smm);

#endif
