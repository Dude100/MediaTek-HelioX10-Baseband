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
 *  med_ext_smalloc.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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

#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "med_trc.h"
#include "med_global.h"
#include "med_mem.h"
#include "med_smalloc.h"
#include "init.h"


typedef struct{
    KAL_ADM_ID aud_mem_pool_id;
    kal_uint32 aud_mem_alloc_count;
    kal_uint32 aud_mem_left_size;
}med_ext_mem_struct;

med_ext_mem_struct g_med_ext_mem_cntx;

#if defined(__MED_MEM_CACHEABLE_SUPPORT__)
#define MED_MEM_CACHEABLE_ALIGN_SIZE  32
#else
#define MED_MEM_CACHEABLE_ALIGN_SIZE  4
#endif

#if defined(__MED_MEM_DEBUG_ON__)
    #define MED_MEM_ALLOC(adm_id,size,f,l)                          kal_adm_alloc_dbg(adm_id,size,f,l)
    #define MED_MEM_ALLOC_TOPMOST_CACHEABLE(adm_id, size, a, f, l)  kal_adm_alloc_c_topmost_dbg(adm_id, size, a, f, l)
    #define MED_MEM_ALLOC_TOPMOST(adm_id, size, a, f, l)            kal_adm_alloc_topmost_dbg(adm_id, size, a, f, l)
    #define MED_MEM_ALLOC_CACHEABLE(adm_id, size, option, f, l)     kal_adm_alloc_cacheable_dbg(adm_id, size, option, f, l)
    #define MED_MEM_ALLOC_FRAMEBUFFER(adm_id, size, a, f, l)        kal_adm_alloc_align_dbg(adm_id, size, a, f, l)
#else
    #define MED_MEM_ALLOC(adm_id,size,f,l)                          kal_adm_alloc(adm_id,size)
    #define MED_MEM_ALLOC_TOPMOST(adm_id, size, a, f, l)            kal_adm_alloc_topmost(adm_id, size, a)
    #define MED_MEM_ALLOC_TOPMOST_CACHEABLE(adm_id, size, a, f, l)  kal_adm_alloc_c_topmost(adm_id, size, a)
    #define MED_MEM_ALLOC_CACHEABLE(adm_id, size, option, f, l)     kal_adm_alloc_cacheable(adm_id, size, option)
    #define MED_MEM_ALLOC_FRAMEBUFFER(adm_id, size, a, f, l)        kal_adm_alloc_align(adm_id, size, a)
#endif

/*****************************************************************************
 * FUNCTION
 *  med_ext_smalloc_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
address_t med_ext_smalloc_ext(size_type size, unsigned short location, const char *file, int line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size == 0)
    {
        return NULL;
    }

    switch(location)
    {
        case MED_EXT_MEMORY_TYPE_AUDIO_NONCACHEABLE:
        case MED_EXT_MEMORY_TYPE_AUDIO_CACHEABLE:
            if (g_med_ext_mem_cntx.aud_mem_pool_id == 0)
                return NULL;
        break;
        default:
            return NULL;
    }

    if (location == MED_EXT_MEMORY_TYPE_AUDIO_NONCACHEABLE)
    {
        ptr = MED_MEM_ALLOC(g_med_ext_mem_cntx.aud_mem_pool_id, size,basename((char *)file), line);
    }
    else if (location == MED_EXT_MEMORY_TYPE_AUDIO_CACHEABLE)
    {
        ptr = MED_MEM_ALLOC_CACHEABLE(g_med_ext_mem_cntx.aud_mem_pool_id, size, MED_MEM_CACHEABLE_ALIGN_SIZE, basename((char *)file), line);
    }

    if (ptr!=NULL)
    {
        g_med_ext_mem_cntx.aud_mem_alloc_count++;
        g_med_ext_mem_cntx.aud_mem_left_size = kal_adm_get_total_left_size(g_med_ext_mem_cntx.aud_mem_pool_id);
        MED_MEM_INFO_AUD(MED_AUD_MEM_SIZE, size, g_med_ext_mem_cntx.aud_mem_left_size, ptr, g_med_ext_mem_cntx.aud_mem_alloc_count);
    }
    else
    {

        if (size < kal_adm_get_total_left_size(g_med_ext_mem_cntx.aud_mem_pool_id))
        {
            /* fragmentation */
            MED_MEM_FRAGMENTATION_AUD(MED_AUD_MEM_SIZE, size, g_med_ext_mem_cntx.aud_mem_left_size,g_med_ext_mem_cntx.aud_mem_alloc_count);
        }
        else
        {
            /* concurrent */
            MED_MEM_CONCURRENT_AUD(MED_AUD_MEM_SIZE, size, g_med_ext_mem_cntx.aud_mem_left_size,g_med_ext_mem_cntx.aud_mem_alloc_count);
        }
    }
    return (address_t) ptr;
}   /* malloc */

/*****************************************************************************
 * FUNCTION
 *  med_aud_sfree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_aud_sfree(address_t ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ptr!=NULL)
    {
        kal_adm_free(g_med_ext_mem_cntx.aud_mem_pool_id, ptr);
        g_med_ext_mem_cntx.aud_mem_alloc_count--;
        g_med_ext_mem_cntx.aud_mem_left_size = kal_adm_get_total_left_size(g_med_ext_mem_cntx.aud_mem_pool_id);
        MED_FREE_MEM_INFO_AUD(g_med_ext_mem_cntx.aud_mem_left_size, ptr, g_med_ext_mem_cntx.aud_mem_alloc_count );
    }
}

/*****************************************************************************
 * FUNCTION
 *  med_set_aud_memory_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  memory      [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_set_aud_memory_pool(address_t memory, size_type size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_med_ext_mem_cntx.aud_mem_pool_id = kal_adm_create(
                                            memory,
                                            size,
                                            NULL,
                                    #if defined(__MED_MEM_DEBUG_ON__)
                                            KAL_TRUE
                                    #else                                            
                                            KAL_FALSE
                                    #endif
                                            );
    g_med_ext_mem_cntx.aud_mem_alloc_count = 0;
    g_med_ext_mem_cntx.aud_mem_left_size = size;
}

