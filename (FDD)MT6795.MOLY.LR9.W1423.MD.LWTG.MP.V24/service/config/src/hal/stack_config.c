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
 *   stack_config.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides a template for .c files. This space
 *   should be used to describe the file contents.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*********************************************************************
    (C) _____ (year of first publication) Sasken communication
    Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

/*************************************************************************
 * Included header files
 *************************************************************************/
//#include "kal_release.h"
//#include "init_time_cfg.h"

//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "app_ltlcom.h"
#include "lcd_ip_cqueue.h"
//#include "stack_types.h"
#include "task_config.h"

#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"

#if defined(KAL_ON_NUCLEUS)
#include "tc_defs.h"
#elif defined(KAL_ON_THREADX)
#include "tx_api.h"
#endif

#include "sysconf_statistics.h"
#include "dspsys_statistics.h"

//#if defined(DEBUG_KAL) && ( defined(DEBUG_BUF1) || defined(DEBUG_BUF2) )
//#include "kal_debug.h"
//#endif /* DEBUG_KAL && ( DEBUG_BUF1 || DEBUG_BUF2 ) */
/*RHR*/
#include "kal_general_types.h"
#include "kal_internal_api.h"
#include "kal_internal_def.h"
//#include "kal_common_defs.h"
#include "stack_config.h"
#include "kal_public_defs.h"
#include "stdlib.h"
/*RHR*/
#include "event_shed.h"

/*************************************************************************
 * Global data definitions
 *************************************************************************/
 stack_statistics_struct sys_stats;

/*************************************************************************
 * Definitions of Imported Globals
 *************************************************************************/
extern kal_uint32  KALTotalTasks;
extern kal_uint32  KALTotalModules;

extern kal_uint32 sys_mem_total_size;
extern kal_uint32 sys_mem_left_size;

#ifdef DEBUG_KAL
extern kal_uint32 debug_mem_total_size;
extern kal_uint32 debug_mem_left_size;
#endif /* DEBUG_KAL */

extern kal_internal_hisrid kal_hisr_ptrs_g[];
extern kal_uint8 num_hisr_created_g;


/*************************************************************************
* FUNCTION
*  stack_config
*
* DESCRIPTION
*  This function implements to config Protocol Stack's configuration
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
stack_config(void)
{
#if defined(__TST_MODULE__) && defined(__DSP_FCORE4__)
    init_dspsys_stat();
#endif

    return KAL_TRUE;
}


/*************************************************************************
* FUNCTION
*  stack_get_statistics_struct_size
*
* DESCRIPTION
*  This function implements to get stack_statistics_struct size
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/

kal_uint32 stack_get_statistics_struct_size(void)
{
	kal_uint32 nSize = 0;

	nSize = sizeof(stack_statistics_struct);
	
	return nSize;
}


/*************************************************************************
* FUNCTION
*  stack_update_sys_statistics
*
* DESCRIPTION
*  This function implements to compare with statistics saved in FLASH, and 
*  update if necessary. 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef DEBUG_KAL
kal_uint32 kal_stack_timer_g;
kal_uint32 kal_kal_timer_g;
kal_uint32 kal_es_timer_g;
kal_uint32 kal_max_event_number;
kal_uint32 kal_max_mutex_number;
kal_uint32 kal_max_eventgroup_number;
#endif

#if defined(DEBUG_KAL) && defined(DEBUG_TIMER2)
kal_uint16 kal_timer_count_debug[LAST_MOD_ID];
kal_uint16 kal_timer_count_debug_tmp[LAST_MOD_ID];


/*Sort in decresing order*/
static kal_int32 timer_count_cmp(const void *a, const void *b)
{
   kal_uint16 a_int16 = *((kal_uint16 *)a);
   kal_uint16 b_int16 = *((kal_uint16 *)b);

   if (a_int16 > b_int16)
   {
       return -1;
   }
   else if(a_int16 == b_int16)
   {
       return 0;
   }
   else
   {
       return 1;
   }
}
#endif

kal_bool
stack_update_sys_statistics(stack_statistics_struct *prev_stats)
{
    kal_bool f_modified = KAL_FALSE;
    kal_uint32 i, *stack_start, *stack_ptr, *stack_end;
    /* kal_uint32 stack_size; fix compile warning */
#if defined(DEBUG_KAL) && defined(DEBUG_TIMER2)
	kal_int32 key = 0;
    kal_int32 count = 0;
#endif
#if defined(FURTHER_STATISTIC) && defined(__MTK_TARGET__)
    kal_internal_taskid taskid = NULL;
    extern kal_uint8 system_resource_amount[];
#endif
    
#if defined(DEBUG_KAL) && ( defined(DEBUG_BUF1) || defined(DEBUG_BUF2) )
    kal_pool_statistics pool_stats;
    buff_pool_info_struct *pool_info;
#endif /* DEBUG_KAL && ( DEBUG_BUF1 || DEBUG_BUF2 ) */

    /* memory management statistics */

    sys_stats.max_sys_mem_used = sys_mem_total_size - sys_mem_left_size;
    if (sys_stats.max_sys_mem_used > prev_stats->max_sys_mem_used)
    {
        prev_stats->max_sys_mem_used = sys_stats.max_sys_mem_used;
        f_modified = KAL_TRUE;
    }
    
    clib_get_heap_statistics(&sys_stats.clib_heap_stats);
    if (sys_stats.clib_heap_stats.curr_alloc_mem != prev_stats->clib_heap_stats.curr_alloc_mem
        || sys_stats.clib_heap_stats.max_alloc_mem != prev_stats->clib_heap_stats.max_alloc_mem
        || sys_stats.clib_heap_stats.alloc_count != prev_stats->clib_heap_stats.alloc_count
        || sys_stats.clib_heap_stats.alloc_fail_count != prev_stats->clib_heap_stats.alloc_fail_count
        || sys_stats.clib_heap_stats.config_size != prev_stats->clib_heap_stats.config_size) {
        prev_stats->clib_heap_stats = sys_stats.clib_heap_stats;
        f_modified = KAL_TRUE;
    }

#ifdef DEBUG_KAL
    sys_stats.max_sysdebug_mem_used = debug_mem_total_size - debug_mem_left_size;

    if (sys_stats.max_sysdebug_mem_used > prev_stats->max_sysdebug_mem_used) {
        prev_stats->max_sysdebug_mem_used = sys_stats.max_sysdebug_mem_used;
        f_modified = KAL_TRUE;
    }
#endif /* DEBUG_KAL */

    /* task stack size statistics */
    for (i = 0; i < KALTotalTasks; i++) {
        
        if (task_info_g[i].task_id == NULL)
            continue;

#if defined(KAL_ON_NUCLEUS)
        stack_start = ((TC_TCB *)task_info_g[i].task_id)->tc_stack_start;
        /* stack_size = ((TC_TCB *)task_info_g[i].task_id)->tc_stack_size;fix compile warning */
        stack_end = ((TC_TCB *)task_info_g[i].task_id)->tc_stack_end;
        stack_ptr = (kal_uint32 *)(((kal_uint32)((TC_TCB *)task_info_g[i].task_id)->tc_stack_pointer) & 0xfffffff8);
        if ((stack_ptr > stack_end) || (stack_ptr < stack_start))
        {
            stack_ptr = stack_end;
        }

        for (; stack_ptr > stack_start; stack_ptr -= 8) {
            if ((*stack_ptr == 0xffffffff) && (*(stack_ptr-1) == 0xffffffff) &&
                 (*(stack_ptr-2) == 0xffffffff) && (*(stack_ptr-3) == 0xffffffff) &&
                 (*(stack_ptr-4) == 0xffffffff) && (*(stack_ptr-5) == 0xffffffff) &&
                 (*(stack_ptr-6) == 0xffffffff) && (*(stack_ptr-7) == 0xffffffff)) {
                break;
            }
        }

        sys_stats.max_task_stack_used[i] = (kal_uint32)stack_end - (kal_uint32)stack_ptr;
#elif defined(KAL_ON_THREADX)
        stack_start = ((TX_THREAD *)task_info_g[i].task_id)->tx_thread_stack_start;
        /* stack_size = ((TX_THREAD *)task_info_g[i].task_id)->tx_thread_stack_size; fix compile warning */
        stack_end = ((TX_THREAD *)task_info_g[i].task_id)->tx_thread_stack_end;
        stack_ptr = (kal_uint32 *)(((kal_uint32)((TX_THREAD *)task_info_g[i].task_id)->tx_thread_stack_ptr) & 0xfffffff8);

        if ((stack_ptr > stack_end) || (stack_ptr < stack_start))
        {
            stack_ptr = stack_end;
        }

        for (; stack_ptr > stack_start; stack_ptr -= 8) {
            if ((*stack_ptr == 0xffffffff) && (*(stack_ptr-1) == 0xffffffff) &&
                 (*(stack_ptr-2) == 0xffffffff) && (*(stack_ptr-3) == 0xffffffff) &&
                 (*(stack_ptr-4) == 0xffffffff) && (*(stack_ptr-5) == 0xffffffff) &&
                 (*(stack_ptr-6) == 0xffffffff) && (*(stack_ptr-7) == 0xffffffff)) {
                break;
            }
        }

        sys_stats.max_task_stack_used[i] = (kal_uint32)stack_end - (kal_uint32)stack_ptr;
#elif defined(KAL_ON_OSCAR)
        sys_stats.max_task_stack_used[i] = 0;
#endif

        if (sys_stats.max_task_stack_used[i] > prev_stats->max_task_stack_used[i] ) {
            prev_stats->max_task_stack_used[i] = sys_stats.max_task_stack_used[i];
            f_modified = KAL_TRUE;
        }
    }

    /* HISR stack size statistics */
    for (i = 0; i < KAL_MAX_NUM_HISRS; i++) {
		
        if (kal_hisr_ptrs_g[i] == NULL)
            continue;

#if defined(KAL_ON_NUCLEUS)
        stack_start = ((TC_HCB *)kal_hisr_ptrs_g[i])->tc_stack_start;
        /* stack_size = ((TC_HCB *)kal_hisr_ptrs_g[i])->tc_stack_size; fix compile warning */
        stack_end = ((TC_HCB *)kal_hisr_ptrs_g[i])->tc_stack_end;
        stack_ptr = (kal_uint32 *)(((kal_uint32)((TC_HCB *)kal_hisr_ptrs_g[i])->tc_stack_pointer) & 0xfffffff8);
        if ((stack_ptr > stack_end) || (stack_ptr < stack_start))
        {
            stack_ptr = stack_end;
        }

        for (; stack_ptr > stack_start; stack_ptr -= 8) {
            if ((*stack_ptr == 0xffffffff) && (*(stack_ptr-1) == 0xffffffff) &&
                (*(stack_ptr-2) == 0xffffffff) && (*(stack_ptr-3) == 0xffffffff) &&
                (*(stack_ptr-4) == 0xffffffff) && (*(stack_ptr-5) == 0xffffffff) &&
                (*(stack_ptr-6) == 0xffffffff) && (*(stack_ptr-7) == 0xffffffff))
            {
                break;
            }
        }

        sys_stats.max_hisr_stack_used[i] = (kal_uint32)stack_end - (kal_uint32)stack_ptr;
#elif defined(KAL_ON_THREADX)
        stack_start = ((TX_THREAD *)kal_hisr_ptrs_g[i])->tx_thread_stack_start;
        /* stack_size = ((TX_THREAD *)kal_hisr_ptrs_g[i])->tx_thread_stack_size; fix compile warning */
        stack_end = ((TX_THREAD *)kal_hisr_ptrs_g[i])->tx_thread_stack_end;
        stack_ptr = (kal_uint32 *)(((kal_uint32)((TX_THREAD *)kal_hisr_ptrs_g[i])->tx_thread_stack_ptr) & 0xfffffff8);
        if ((stack_ptr > stack_end) || (stack_ptr < stack_start))
        {
            stack_ptr = stack_end;
        }

        for (; stack_ptr > stack_start; stack_ptr -= 8) {
            if ((*stack_ptr == 0xffffffff) && (*(stack_ptr-1) == 0xffffffff) &&
                (*(stack_ptr-2) == 0xffffffff) && (*(stack_ptr-3) == 0xffffffff) &&
                (*(stack_ptr-4) == 0xffffffff) && (*(stack_ptr-5) == 0xffffffff) &&
                (*(stack_ptr-6) == 0xffffffff) && (*(stack_ptr-7) == 0xffffffff))
            {
                break;
            }
        }

        sys_stats.max_hisr_stack_used[i] = (kal_uint32)stack_end - (kal_uint32)stack_ptr;
#elif defined(KAL_ON_OSCAR)
        sys_stats.max_hisr_stack_used[i] = 0;
#endif

        if (sys_stats.max_hisr_stack_used[i] > prev_stats->max_hisr_stack_used[i] ) {
            prev_stats->max_hisr_stack_used[i] = sys_stats.max_hisr_stack_used[i];
            f_modified = KAL_TRUE;
        }
    }

    /* Queue management statistics */
#if defined(DEBUG_ITC) && defined(DEBUG_KAL)
    for (i=0; i<KALTotalTasks; i++) {
        if (task_info_g[i].task_ext_qid == NULL)
            continue;

        sys_stats.max_task_extq_enqued[i] = 
            ((kal_internal_msgqid)task_info_g[i].task_ext_qid)->q_stat->max_num_msgs_enqued;

        if (sys_stats.max_task_extq_enqued[i] > prev_stats->max_task_extq_enqued[i]) {
            prev_stats->max_task_extq_enqued[i] = sys_stats.max_task_extq_enqued[i];
            f_modified = KAL_TRUE;
        }
    }
	for (i=0; i<KALTotalTasks; i++)
	{
		if (task_info_g[i].task_int_qid_ptr == NULL)
		{
			continue;
	   }

      sys_stats.max_task_intq_enqued[i] = 0;

      LCD_UP_CQUEUE_UPDATE_MAX((*(int_q_type *)task_info_g[i].task_int_qid_ptr),
                               sys_stats.max_task_intq_enqued[i]);

		if (sys_stats.max_task_intq_enqued[i] > prev_stats->max_task_intq_enqued[i])
		{
			prev_stats->max_task_intq_enqued[i] = sys_stats.max_task_intq_enqued[i];
			f_modified = KAL_TRUE;
		}
	}

#endif /* DEBUG_ITC && DEBUG_KAL */

    /* Buffer management statistics */
#if defined(DEBUG_KAL) && ( defined(DEBUG_BUF1) || defined(DEBUG_BUF2) )
    for (i=0; i<RPS_CREATED_CTRL_BUFF_POOLS; i++) {
        pool_info = &ctrl_buff_pool_info_g[i];
        if (pool_info->pool_id == NULL)
            continue;

        pool_stats = KAL_GET_POOL_STATISTICS_ADDR( pool_info->pool_id );
        sys_stats.max_ctrl_buff_num_allocated[i] = pool_stats->max_num_allocated;

        if (sys_stats.max_ctrl_buff_num_allocated[i] > prev_stats->max_ctrl_buff_num_allocated[i]) {
            prev_stats->max_ctrl_buff_num_allocated[i] = sys_stats.max_ctrl_buff_num_allocated[i];
            f_modified = KAL_TRUE;
        }
    }

#endif /* DEBUG_KAL && ( DEBUG_BUF1 || DEBUG_BUF2 ) */

#if defined(__TST_MODULE__) && defined(__DSP_FCORE4__)
    if (get_dspsys_stat(&(prev_stats->dspsys_stat))) {
        f_modified = KAL_TRUE;
    }
#endif

#ifdef DEBUG_KAL
    f_modified = KAL_TRUE;
    prev_stats->timers_stat.kal_timer_no = kal_kal_timer_g - kal_stack_timer_g;
    prev_stats->timers_stat.es_timer_no = kal_es_timer_g;
    prev_stats->timers_stat.stack_timer_no = kal_stack_timer_g - kal_es_timer_g;
    prev_stats->max_mutex_number = kal_max_mutex_number;
    prev_stats->max_event_number = kal_max_event_number;
    prev_stats->max_eventgroup_number = kal_max_eventgroup_number;
#endif

#if defined(DEBUG_KAL) && defined(DEBUG_TIMER2)
    /*find the top KAL_TIMER_COUNT_STAT timer occupier*/

    /*qsort will modify the array. so create a tmp one and then discard it*/
    kal_mem_cpy(kal_timer_count_debug_tmp,  kal_timer_count_debug,
            sizeof(kal_timer_count_debug));

    /*module id index -> timer count*/
    qsort(kal_timer_count_debug_tmp, 
            sizeof(kal_timer_count_debug)/sizeof(kal_int16), 
            sizeof(kal_int16),
            timer_count_cmp); 

    if(KAL_TIMER_COUNT_STAT > LAST_MOD_ID )
    {
        ASSERT(0);
    }
    
    key = kal_timer_count_debug_tmp[KAL_TIMER_COUNT_STAT - 1];

    f_modified = KAL_TRUE;
   
   /*There is no need to compare nvram data with the memory snapshot 
    * to get the biggest number.*/ 
    for(i = 0; i < LAST_MOD_ID; i++)
    {
        if (kal_timer_count_debug[i] >= key)
        {
            if (count < KAL_TIMER_COUNT_STAT)
            {
                prev_stats->timers_stat.kal_all_timers_stat[count].owner_module 
                                                       = (module_type)i;

                prev_stats->timers_stat.kal_all_timers_stat[count].count
                                                       = kal_timer_count_debug[i];
                count++;
            }
        }
    }
#endif 

    /* runtime resource sysmem statistics */
#if defined(FURTHER_STATISTIC) && defined(__MTK_TARGET__)
    prev_stats->runtime_sysmem_size.evshed 
        = sys_stats.runtime_sysmem_size.evshed = KAL_RT_SYSMEM_SIZE_EVSHED;
    prev_stats->runtime_sysmem_size.mutex 
        = sys_stats.runtime_sysmem_size.mutex = KAL_RT_SYSMEM_SIZE_MUTEX;
    prev_stats->runtime_sysmem_size.sem 
        = sys_stats.runtime_sysmem_size.sem = KAL_RT_SYSMEM_SIZE_SEM;
    prev_stats->runtime_sysmem_size.event_group 
        = sys_stats.runtime_sysmem_size.event_group = KAL_RT_SYSMEM_SIZE_EVENT_GROUP;
    prev_stats->runtime_sysmem_size.stack_timer 
        = sys_stats.runtime_sysmem_size.stack_timer = KAL_RT_SYSMEM_SIZE_STACK_TIMER;
    prev_stats->runtime_sysmem_size.kal_timer 
        = sys_stats.runtime_sysmem_size.kal_timer = KAL_RT_SYSMEM_SIZE_KAL_TIMER;
#if defined(KAL_ON_NUCLEUS)
    prev_stats->runtime_sysmem_size.enh_mutex 
        = sys_stats.runtime_sysmem_size.enh_mutex = KAL_RT_SYSMEM_SIZE_ENH_MUTEX;
#endif
    prev_stats->system_runtime_max_amount.evshed
    = sys_stats.system_runtime_max_amount.evshed
    = system_resource_amount[KAL_RT_RESOURCE_EVSHED];
    prev_stats->system_runtime_max_amount.mutex
    = sys_stats.system_runtime_max_amount.mutex
    = system_resource_amount[KAL_RT_RESOURCE_MUTEX];
    prev_stats->system_runtime_max_amount.sem
    = sys_stats.system_runtime_max_amount.sem
    = system_resource_amount[KAL_RT_RESOURCE_SEM];
    prev_stats->system_runtime_max_amount.event_group
    = sys_stats.system_runtime_max_amount.event_group
    = system_resource_amount[KAL_RT_RESOURCE_EVENT_GROUP];
    prev_stats->system_runtime_max_amount.stack_timer
    = sys_stats.system_runtime_max_amount.stack_timer
    = system_resource_amount[KAL_RT_RESOURCE_STACK_TIMER];
    prev_stats->system_runtime_max_amount.kal_timer
    = sys_stats.system_runtime_max_amount.kal_timer
    = system_resource_amount[KAL_RT_RESOURCE_KAL_TIMER];
#if defined(KAL_ON_NUCLEUS)
    prev_stats->system_runtime_max_amount.enh_mutex
    = sys_stats.system_runtime_max_amount.enh_mutex
    = system_resource_amount[KAL_RT_RESOURCE_ENH_MUTEX];
#endif

    for (i = 0; i < KALTotalTasks; i++) 
    {        
        if (task_info_g[i].task_id == NULL)
            continue;
		
        taskid = (kal_internal_taskid)(task_info_g[i].task_id);
		
        memcpy(&(sys_stats.task_runtime_max_amount[i].task_name), \
            task_info_g[i].task_name_ptr
            , sizeof(sys_stats.task_runtime_max_amount[i].task_name)); 
        memcpy(&(prev_stats->task_runtime_max_amount[i].task_name), \
            task_info_g[i].task_name_ptr
            , sizeof(prev_stats->task_runtime_max_amount[i].task_name));  
		
        prev_stats->task_runtime_max_amount[i].evshed 
        = sys_stats.task_runtime_max_amount[i].evshed 
        = taskid->task_runtime_resource_amount[KAL_RT_RESOURCE_EVSHED];
        prev_stats->task_runtime_max_amount[i].mutex 
        = sys_stats.task_runtime_max_amount[i].mutex 
        = taskid->task_runtime_resource_amount[KAL_RT_RESOURCE_MUTEX];
        prev_stats->task_runtime_max_amount[i].sem 
        = sys_stats.task_runtime_max_amount[i].sem 
        = taskid->task_runtime_resource_amount[KAL_RT_RESOURCE_SEM];
        prev_stats->task_runtime_max_amount[i].event_group 
        = sys_stats.task_runtime_max_amount[i].event_group 
        = taskid->task_runtime_resource_amount[KAL_RT_RESOURCE_EVENT_GROUP];
        prev_stats->task_runtime_max_amount[i].stack_timer 
        = sys_stats.task_runtime_max_amount[i].stack_timer 
        = taskid->task_runtime_resource_amount[KAL_RT_RESOURCE_STACK_TIMER];
        prev_stats->task_runtime_max_amount[i].kal_timer 
        = sys_stats.task_runtime_max_amount[i].kal_timer 
        = taskid->task_runtime_resource_amount[KAL_RT_RESOURCE_KAL_TIMER];
#if defined(KAL_ON_NUCLEUS)
        prev_stats->task_runtime_max_amount[i].enh_mutex 
        = sys_stats.task_runtime_max_amount[i].enh_mutex 
        = taskid->task_runtime_resource_amount[KAL_RT_RESOURCE_ENH_MUTEX];
#endif

        f_modified = KAL_TRUE;
    }
#endif

    if (f_modified == KAL_TRUE) {
       prev_stats->stack_stats_status = STACK_STATS_UPDATE;
    }

    return f_modified;
}

/*************************************************************************
* FUNCTION
*  stack_query_stat_info
*
* DESCRIPTION
*  This function gets system statistics related informations such as
*  HISR name.
*
* PARAMETERS
*  stat        -   flag to indicate the querying statsitic
*  buff        -   user buffer to store informations
*  buff_size   -   user buffer's size
*
* RETURNS
*  -1 for failure, other nonzero value for success
*
*************************************************************************/
kal_int32 stack_get_stats_info(kal_uint32 stats, void *buff, kal_uint32 buff_size)
{
    kal_int32 ret;
    kal_char *chp;
    kal_uint32 i, j;


    ret = -1;

    switch (stats) {
    case STACK_STATS_HISR_NAME:
        /* check buffer size */
        if (buff_size < (num_hisr_created_g * STACK_STATS_HISR_MAX_NAME * sizeof(kal_char))) {
            break;
        } else {
            ret = num_hisr_created_g * STACK_STATS_HISR_MAX_NAME * sizeof(kal_char);
        }

        /* copy HISR names into the buffer */
        chp = (kal_char *)buff;
        for (i = 0; i < num_hisr_created_g; i++) {
            for (j = 0; j < STACK_STATS_HISR_MAX_NAME; j++, chp++) {
#if defined(KAL_ON_NUCLEUS)
                *chp = ((TC_HCB *)kal_hisr_ptrs_g[i])->tc_name[j];
#elif defined(KAL_ON_THREADX)
                *chp = ((TX_THREAD *)kal_hisr_ptrs_g[i])->tx_thread_name[j];
#elif defined(KAL_ON_OSCAR)
                *chp = '0';
#endif
            }
        }

        break;

    default:
        /* unknown statistic type */
        break;
    }

    return ret;
}
