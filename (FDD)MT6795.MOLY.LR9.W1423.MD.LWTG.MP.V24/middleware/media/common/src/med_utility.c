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
 * med_utility.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes common used functions of media task.
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
 *
 * removed!
 * removed!
 * removed!
 *
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

/*==== INCLUDES =========*/
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"

/* global includes */
#include "l1audio.h"

/* local includes */
#include "med_main.h"
#include "med_global.h"
#include "med_mem.h"
#include "med_struct.h"
#include "med_context.h"
#include "med_smalloc.h"
#include "med_utility.h"
#include "med_trc.h"
#include "aud_main.h"

kal_mutexid med_mem_mutex;

/*****************************************************************************
 * FUNCTION
 *  med_alloc_ext_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *med_alloc_ext_mem_ext(kal_int32 size, kal_uint8 location, char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(med_mem_mutex);
    p = (void*)med_ext_smalloc_ext((size_type) size, location, file_p, line_p);
    kal_give_mutex(med_mem_mutex);

    return p;
}

/*****************************************************************************
 * FUNCTION
 *  med_free_aud_mem_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pointer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_free_aud_mem_ext(void **pointer,char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(med_mem_mutex);
    med_aud_sfree((address_t) * pointer);
    kal_give_mutex(med_mem_mutex);
    *pointer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  med_util_alloc_aud_mem
 * DESCRIPTION
 *  This function is to allocate memory from audio memory pool.
 * PARAMETERS
 *  size        [IN]        Memory size to be allocated.
 *  file_p      [IN]        File name.
 *  line        [IN]        Line number in the file.
 * RETURNS
 *  Allocated memory address
 *****************************************************************************/
static void* med_util_alloc_aud_mem(kal_uint32 size, char* file_p, long line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return med_alloc_ext_mem_ext(size, MED_EXT_MEMORY_TYPE_AUDIO_NONCACHEABLE, file_p, line);
}

/*****************************************************************************
 * FUNCTION
 *  med_util_alloc_aud_cacheable_mem
 * DESCRIPTION
 *  This function is to allocate cacheable memory from audio memory pool.
 * PARAMETERS
 *  void
 * RETURNS
 *  Allocated memory address
 *****************************************************************************/
static void* med_util_alloc_aud_cacheable_mem(kal_uint32 size, char* file_p, long line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return med_alloc_ext_mem_ext(size, MED_EXT_MEMORY_TYPE_AUDIO_CACHEABLE, file_p, line);
}

/*****************************************************************************
 * FUNCTION
 *  med_util_free_aud_mem
 * DESCRIPTION
 *  This function is to free audio memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  Allocated memory address
 *****************************************************************************/
static void med_util_free_aud_mem(void** mem_p, char* file_p, long line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_free_aud_mem_ext(mem_p, file_p, line);
}

/*****************************************************************************
 * FUNCTION
 *  med_utility_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_utility_init(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Func_Reg_Type media_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    med_mem_mutex = kal_create_mutex("MED MEM");
    
    /* Register callback functions to L1audio */
    media_func.alloc_mem           = med_util_alloc_aud_mem;
    media_func.alloc_mem_cacheable = med_util_alloc_aud_cacheable_mem;
    media_func.free_mem            = med_util_free_aud_mem;
    media_func.set_path_volume     = NULL;
    media_func.get_active_mode     = NULL;
#if defined(__VOLTE_SUPPORT__)    
    media_func.send_proc_call      = aud_send_in_proc_call_req;   // is only used in VoLTE DTMF MCU destroy functions
#else
    media_func.send_proc_call      = NULL;   
#endif    
    media_func.send_proc_call2     = NULL;
    media_func.get_meta_file       = NULL;
    media_func.get_meta_array      = NULL;
    
#if !defined(L1_NOT_PRESENT)
    Audio_MedFuncReg(&media_func);
#endif

    /* init audio memory */
    med_set_aud_memory_pool((unsigned char*)med_context_p->aud_mem_p, MED_AUD_MEM_SIZE);

    return KAL_TRUE;
}


#ifndef MED_NOT_PRESENT

/*****************************************************************************
 * FUNCTION
 *  med_timer_expiry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_timer_expiry_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_timer_struct *stack_timer_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_timer_ptr = (stack_timer_struct*) ilm_ptr->local_para_ptr;

    if (stack_timer_ptr->timer_indx == MED_BASE_TIMER_ID)
    {
        /* Execute event's timeout handler */
        evshed_timer_handler(med_context_p->event_scheduler_ptr);
    }
}

#endif /* MED_NOT_PRESENT */ 

