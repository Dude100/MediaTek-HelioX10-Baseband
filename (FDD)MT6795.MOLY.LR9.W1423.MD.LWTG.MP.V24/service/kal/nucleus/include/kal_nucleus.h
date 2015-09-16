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
 *   kal_nucleus.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains the type definations related to nucleus.
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

#if !defined(_KAL_NUCLEUS_H)
#define _KAL_NUCLEUS_H

#ifdef KAL_ON_NUCLEUS

/*************************************************************************
 * Constant definition
 *************************************************************************/
#define KAL_NU_POOLID_PTR_SIZE            4
#define KAL_NU_BUFF_OVERHEAD              8

#define KAL_GET_POOLID_PTR_IN_BUFF_HEADER(buf_ptr) ((kal_char*)buf_ptr \
                                        - KAL_BUFF_HEADER_SIZE \
                                        - KAL_NU_POOLID_PTR_SIZE)


#if defined(DEBUG_KAL) && ( defined(DEBUG_BUF1) || defined(DEBUG_BUF2) )
#define KAL_BUFFER_OVERHEAD (KAL_BUFF_HEADER_SIZE + KAL_BUFF_FOOTER_SIZE)
#else	/* DEBUG_KAL && ( DEBUG_BUF1 || DEBUG_BUF2 ) */
#define KAL_BUFFER_OVERHEAD 0
#endif /* DEBUG_KAL && ( DEBUG_BUF1 || DEBUG_BUF2 ) */

#define KAL_MAX_ALLOC_ID 64
#define KAL_TOTAL_BUFF_OVERHEAD (KAL_NU_BUFF_OVERHEAD + KAL_BUFFER_OVERHEAD)
#define KAL_MAX_NUM_TIMERS 500

#define SYSINFOSTR_BUFFLEN  256

//macros for priority transfer
//#define KAL_TASK_INVALID_PRIORITY 0x100  //256
#define KAL_PRIORITY_TRANSFER_SPECIAL_PATTERN1	0xFFFFFFFF
#define KAL_PRIORITY_TRANSFER_SPECIAL_PATTERN2	0xEEEEEEEE
#define KAL_PRIORITY_TRANSFER_SPECIAL_PATTERN3	0xDDDDDDDD
#define KAL_PRIORITY_TRANSFER_SPECIAL_PATTERN4	0xCCCCCCCC
#define KAL_GET_FIRST_PRIORITY(x)  ((x)>>16)
#define KAL_GET_SECOND_PRIORITY(x)	((x)&0x0000ffff)
#define KAL_INVALID_MINUS_PRIORITY	(256)
//the end

/*************************************************************************
 * Types used by run-time sysmem statistic
 *************************************************************************/
typedef enum {
   KAL_RT_RESOURCE_ENH_MUTEX,
   KAL_RT_RESOURCE_EVENT_GROUP,
   KAL_RT_RESOURCE_EVSHED,
   KAL_RT_RESOURCE_MUTEX,
   KAL_RT_RESOURCE_SEM,
   KAL_RT_RESOURCE_STACK_TIMER,
   KAL_RT_RESOURCE_KAL_TIMER,
   KAL_RT_RESOURCE_MAX,
   KAL_RT_RESOURCE_MAX_ALIGN = (((KAL_RT_RESOURCE_MAX+(sizeof(int)-1))/sizeof(int))*sizeof(int)),
} kal_runtime_reource_e;

struct kal_int_enhmutex;
struct kal_int_enhmutex_suspend;
struct kal_int_prio_list_s;

/*************************************************************************
 * Types used for task manager
 *************************************************************************/
#if defined(DEBUG_KAL)

typedef struct kal_int_task_struct {
   kal_os_task_type task_id;
   kal_char *task_name;
   kal_uint16 task_index;
   kal_uint16 task_enhmutex_count;
   kal_uint32 priority_record;
   struct kal_int_prio_list_s *prio_list;

   struct kal_int_enhmutex_suspend *task_enhmutex_blockon;
   kal_uint8 task_runtime_resource_amount[KAL_RT_RESOURCE_MAX_ALIGN];
} *kal_internal_taskid, kal_task_type;

typedef struct kal_int_hisr_struct {
   kal_os_hisr_type hisr_id;
   kal_char *hisr_name;
   kal_uint16 hisr_index;
} *kal_internal_hisrid, kal_hisr_type;

#else	/* defined(DEBUG_KAL) */

typedef struct kal_int_task_struct {
   kal_os_task_type task_id;
   kal_uint16 task_index;
   kal_uint16 task_enhmutex_count;
   kal_uint32 priority_record;
   struct kal_int_prio_list_s *prio_list;

   struct kal_int_enhmutex_suspend *task_enhmutex_blockon;
} *kal_internal_taskid, kal_task_type;

typedef struct kal_int_hisr_struct {
   kal_os_hisr_type hisr_id;
   kal_uint16 hisr_index;
} *kal_internal_hisrid, kal_hisr_type;

#endif /* defined(DEBUG_KAL) */

typedef enum {
   KAL_STACK_ERAM,
   KAL_STACK_IRAM,
   KAL_STACK_LOCATION
} kal_stack_location;

typedef struct kal_hisr_stack_info_struct {
   void* stack_address[KAL_STACK_LOCATION];
   kal_uint32 stack_expected_size[KAL_STACK_LOCATION];
   kal_uint32 stack_real_size[KAL_STACK_LOCATION];
} *kal_hisr_stack_info_p, kal_hisr_stack_info_s;

/*************************************************************************
 * Types used by ITC
 *************************************************************************/
#if defined(DEBUG_KAL) && defined(DEBUG_ITC)

typedef struct kal_int_queue_statistics_struct {
   kal_uint32    last_empty_time_stamp;
   kal_uint32    last_taken_ticks[3];
   kal_uint32    last_rece_ticks[6];

   kal_uint16    current_num_msgs;
   kal_uint16    max_num_msgs_enqued;

   kal_uint8     queue_slots_tenth;     
   kal_uint8     last_taken_tick_idx;
   kal_uint8     pading[2];
} *kal_internal_queue_statistics, kal_queue_stat_type;

typedef struct {
   kal_os_queue_type    queue_id;
   kal_uint16           max_msg_size;
   kal_internal_queue_statistics    q_stat;
} *kal_internal_msgqid, kal_queue_type;

#else	/* defined(DEBUG_KAL) && defined(DEBUG_ITC) */

typedef struct {
   kal_os_queue_type    queue_id;
   kal_uint16           max_msg_size;
}* kal_internal_msgqid, kal_queue_type;

#endif /* defined(DEBUG_KAL) && defined(DEBUG_ITC) */

typedef struct {
   kal_os_mutex_type    mutex_id;
   kal_os_task_type     *owner_task;
   kal_mutex_state      mutex_state;
} *kal_internal_mutexid, kal_mutex_type;

typedef kal_os_sem_type *kal_internal_semid, kal_sem_type;

typedef kal_os_eventgrp_type *kal_internal_eventgrpid, kal_eventgrp_type;


/*************************************************************************
 * Types related to timers
 *************************************************************************/
typedef struct {
   kal_os_timer_type       timer_id;
   kal_timer_func_ptr      func_ptr;
   void *                  timer_param_ptr;
   kal_uint32              set_time;
} * kal_internal_timerid, kal_timer_type;

typedef enum {
   NO_TIMER,
   UNLIMITED_SLEEP_TIME,
   LIMITED_SLEEP_TIME
} kal_sleep_state;

typedef struct
{
    kal_uint32 sleep_time;
    kal_uint32 first_timer_time;
    kal_sleep_state sleep_status;
}Sleep_Time;

#define MAX_SLEEP_TIME (kal_uint32)(3.8*1000/KAL_MILLISECS_PER_TICK)



/*************************************************************************
 * Types used for buffer manager
 * NoteXXX: Below data strucutre cannot be modified.
 *          Buffer-relative ROM code will reference them.
 *************************************************************************/
#if defined(DEBUG_KAL) && ( defined(DEBUG_BUF1) || defined(DEBUG_BUF2) )

typedef struct kal_int_pool_struct {
   kal_os_pool_type        pool_id;
   kal_uint32              buff_size;
   struct kal_int_pool_statistics_struct    *pool_stat;
#ifdef DEBUG_BUF2
   kal_bool          pool_debug_mask;
   kal_uint16              num_buffs;
#endif /* DEBUG_BUF2 */
} *kal_internal_poolid, kal_pool_type;

#else	/* defined(DEBUG_KAL) && ( defined(DEBUG_BUF1) || defined(DEBUG_BUF2) ) */

typedef struct kal_int_pool_struct {
   kal_os_pool_type        pool_id;
} *kal_internal_poolid, kal_pool_type;

#endif /* defined(DEBUG_KAL) && ( defined(DEBUG_BUF1) || defined(DEBUG_BUF2) ) */


#define KAL_ENHMUTEX_MAGIC 0x20091113

struct kal_int_enhmutex_suspend {
    /* circular linked-list pointer */
    /* emts_prev, emts_next must be the first 2 elements */
    /* and in the correct order with struct kal_enhmutex */
    struct kal_int_enhmutex_suspend *emts_prev;
    struct kal_int_enhmutex_suspend *emts_next;
    
    struct kal_int_enhmutex *emts_mutex;
    kal_internal_taskid  emts_task;
};

typedef struct kal_int_enhmutex {
    /* circular linked-list pointer */
    /* emtx_prev, emtx_next must be the first 2 elements */
    /* and in the correct order with struct kal_enhmutex_suspend */
    struct kal_int_enhmutex_suspend *emtx_prev;
    struct kal_int_enhmutex_suspend *emtx_next;
    
    kal_uint8    emtx_max_wprio;           // maximum(highest) waiting task priority
    kal_uint16   emtx_suspension_count;    // how many task suspended on it
    kal_internal_taskid emtx_ownertask;
    
    /* most readonly part */
    kal_uint32   emtx_magic;               // KAL_ENHMUTEX_MAGIC
    kal_char     emtx_name[NU_MAX_NAME];
#ifdef KAL_ENHMUTEX_CREATEDLIST
    CS_NODE      emtx_created;
#endif
} *kal_internal_enhmutexid, kal_internal_enhmutex_type;

/*************************************************************************
* types used for priority transfer
*************************************************************************/
typedef struct kal_int_prio_list_s{
   kal_uint32 priority;
   struct kal_int_prio_list_s *next;
}kal_int_prio_list_t;


/*************************************************************************
 * Exported Data Declaration
 *************************************************************************/

extern kal_char sys_info_str[SYSINFOSTR_BUFFLEN];


/*************************************************************************
 * Exported Function Prototypes
 *************************************************************************/
#if defined(__EVENT_BASED_TIMER__)
extern void kal_get_sleep_time(Sleep_Time *cal_ticks);
extern kal_uint32 kal_is_valid_sleep_time(Sleep_Time *sl);
#endif /* __EVENT_BASED_TIMER__ */

#endif  /* KAL_ON_NUCLEUS */

#endif /* _KAL_NUCLEUS_H */

