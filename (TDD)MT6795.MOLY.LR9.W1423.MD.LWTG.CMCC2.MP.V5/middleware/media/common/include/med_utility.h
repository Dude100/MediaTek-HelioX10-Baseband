/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 * Filename:
 * ---------
 * med_utility.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file of utiltiy of media task.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/

#ifndef _MED_UTILITY_H
#define _MED_UTILITY_H


#include "kal_general_types.h"
#include "kal_public_defs.h"

#include "med_main.h"
#include "med_smalloc.h"

/* DOM-NOT_FOR_SDK-BEGIN */

#define MED_BASE_TIMER_ID 0x0000
#define MED_ASSERT(expr)                \
   do {                                \
       if (!(expr)) { ASSERT(0); }     \
   } while (0)


extern void *med_alloc_ext_mem_ext(kal_int32 size,kal_uint8 location,char* file_p, long line_p);
extern void *med_alloc_temp_ext_mem_ext(kal_int32 size, void (*callback)(void*), char* file_p, long line_p);
extern void *med_alloc_temp_ext_mem_ext_nc(kal_int32 size, void (*callback)(void*), char* file_p, long line_p);
extern void med_free_ext_mem_ext(void **pointer,char* file_p, long line_p);
extern void med_free_aud_mem_ext(void **pointer,char* file_p, long line_p);
extern void med_free_temp_ext_mem_ext(void **pointer,char* file_p, long line_p);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  med_ext_left_size
 * DESCRIPTION
 *  Get MED left external memory size.
 * PARAMETERS
 *  void
 * RETURNS
 *  the left size
 *****************************************************************************/
extern size_type med_ext_left_size(void);

/*
 * Interface to allocate / free media external memory
 */

/*****************************************************************************
 * FUNCTION
 *  med_alloc_ext_mem
 * DESCRIPTION
 *  Allocate non-cacheable memory from MED external memory pool. Only for PLUTOMMI Package.
 * PARAMETERS
 *  size        : [IN]  the request memory size
 * RETURNS
 *  void*, memory pointer
 *****************************************************************************/
#define med_alloc_ext_mem(size)                              med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_NONCACHEABLE,__FILE__,__LINE__)


/*****************************************************************************
 * FUNCTION
 *  med_alloc_ext_mem_cacheable
 * DESCRIPTION
 *  Allocate cacheable memory from MED external memory pool. Only for PLUTOMMI Package.
 * PARAMETERS
 *  size        : [IN]  the request memory size
 * RETURNS
 *  void*, memory pointer
 *****************************************************************************/
#define med_alloc_ext_mem_cacheable(size)                    med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_CACHEABLE,__FILE__,__LINE__)


/*****************************************************************************
 * FUNCTION
 *  med_free_ext_mem
 * DESCRIPTION
 *  Free MED external memory. Only for PLUTOMMI Package.
 * PARAMETERS
 *  pointer     : [IN]  memory pointer
 * RETURNS
 *  void
 *****************************************************************************/
#define med_free_ext_mem(pointer)                            med_free_ext_mem_ext(pointer,__FILE__,__LINE__)

/* DOM-NOT_FOR_SDK-BEGIN */
#define med_alloc_ext_mem_framebuffer(size)                  med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_FRAMEBUFFER,__FILE__,__LINE__)
#define med_alloc_aud_mem(size)                              med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_AUDIO_NONCACHEABLE,__FILE__,__LINE__)
#define med_alloc_aud_mem_cacheable(size)                    med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_AUDIO_CACHEABLE,__FILE__,__LINE__)

/*
 * Interface to allocate / free application share memory
 */
#define med_alloc_asm_mem(id, size)                          med_alloc_ext_mem(size)
#define med_alloc_asm_mem_cacheable(id, size)                med_alloc_ext_mem_cacheable(size)
#define med_alloc_asm_mem_framebuffer(id, size)              med_alloc_ext_mem_framebuffer(size)
#define med_free_asm_mem(id, ptr)                            med_free_ext_mem(ptr)

/*
 * Interface to allocate / free application share memory
 */
#define med_alloc_mem(id, size, file, line)                  med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_NONCACHEABLE,file, line)
#define med_alloc_mem_cacheable(id, size, file, line)        med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_CACHEABLE,file,line)
#define med_alloc_mem_framebuffer(id, size, file, line)      med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_FRAMEBUFFER,file,line)
#define med_free_mem(id, ptr, file, line)                    med_free_ext_mem_ext(ptr,file,line)

#define med_alloc_temp_ext_mem(size,callback)                med_alloc_temp_ext_mem_ext(size,callback,__FILE__,__LINE__)
#define med_alloc_temp_ext_mem_noncacheable(size,callback)   med_alloc_temp_ext_mem_ext_nc(size,callback,__FILE__,__LINE__)
#define med_free_temp_ext_mem(pointer)                       med_free_temp_ext_mem_ext(pointer,__FILE__,__LINE__)

/*==== Functions =====*/

extern kal_bool med_utility_init(void);
/* DOM-NOT_FOR_SDK-END */
#endif /* _MED_UTILITY_H */

