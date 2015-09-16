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
 *   kal_error_code.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   KAL error code
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/*************************************************************************
 * Define macros.
 *************************************************************************/

#if defined(X_KAL_ERROR_CODE)
#define X_KAL_ERROR(code, str) code,
#define X_KAL_ERROR_ASSIGN(code, val, str) code = val,
#endif  /* X_KAL_ERROR_CODE */

#if defined(X_KAL_ERROR_STRING)
#define X_KAL_ERROR(code, str) str,
#define X_KAL_ERROR_ASSIGN(code, val, str) str = val,
#endif  /* X_KAL_ERROR_STRING */


/*************************************************************************
 * Define KAL error code and strings.
 *************************************************************************/

/* General KAL Error */
X_KAL_ERROR_ASSIGN(KAL_ERROR_KAL_INTERNAL_FAIL,                         0,       KAL_ERROR_KAL_INTERNAL_FAIL_)
X_KAL_ERROR_ASSIGN(KAL_ERROR_KAL_SUB_ERROR_CODE1,                       1,       KAL_ERROR_KAL_SUB_ERROR_CODE1_)
X_KAL_ERROR_ASSIGN(KAL_ERROR_KAL_SUB_ERROR_CODE2,                       2,       KAL_ERROR_KAL_SUB_ERROR_CODE2_)
X_KAL_ERROR_ASSIGN(KAL_ERROR_KAL_SUB_ERROR_CODE3,                       3,       KAL_ERROR_KAL_SUB_ERROR_CODE3_)
X_KAL_ERROR_ASSIGN(KAL_ERROR_KAL_SUB_ERROR_CODE4,                       4,       KAL_ERROR_KAL_SUB_ERROR_CODE4_)
X_KAL_ERROR_ASSIGN(KAL_ERROR_KAL_SUB_ERROR_CODE5,                       5,       KAL_ERROR_KAL_SUB_ERROR_CODE5_)
X_KAL_ERROR_ASSIGN(KAL_ERROR_KAL_SUB_ERROR_CODE6,                       6,       KAL_ERROR_KAL_SUB_ERROR_CODE6_)
X_KAL_ERROR_ASSIGN(KAL_ERROR_KAL_SUB_ERROR_CODE7,                       7,       KAL_ERROR_KAL_SUB_ERROR_CODE7_)
X_KAL_ERROR_ASSIGN(KAL_ERROR_KAL_SUB_ERROR_CODE8,                       8,       KAL_ERROR_KAL_SUB_ERROR_CODE8_)

/* ARM exception */
X_KAL_ERROR_ASSIGN(KAL_ERROR_UNDEF,                                     1,       Undefined_exception)
X_KAL_ERROR_ASSIGN(KAL_ERROR_SWI,                                       2,       SWI_exception)
X_KAL_ERROR_ASSIGN(KAL_ERROR_PABORT,                                    3,       Prefetch_abort)
X_KAL_ERROR_ASSIGN(KAL_ERROR_DABORT,                                    4,       Data_abort)
                                                                              
/* System Initialization */
X_KAL_ERROR_ASSIGN(KAL_ERROR_KALINIT_INIT_FAILED,                       0x0101,  KAL_ERROR_KALINIT_INIT_FAILED_)
X_KAL_ERROR(KAL_ERROR_KALINIT_INIT_CREATE_SEM_FAILED,                            initialize_KAL___fail_to_create_a_semaphore)
X_KAL_ERROR(KAL_ERROR_KALINIT_INIT_CREATE_QU_MUTEX_FAILED,                       initialize_KAL___fail_to_create_a_QUEUE_MUTEX)
X_KAL_ERROR(KAL_ERROR_KALINIT_INIT_CREATE_POOL_MUTEX_FAILED,                     initialize_KAL___fail_to_create_a_POOL_MUTEX)
X_KAL_ERROR(KAL_ERROR_KALINIT_INIT_CREATE_TIMER_MUTEX_FAILED,                    initialize_KAL___fail_to_create_a_TIMER_MUTEX)
X_KAL_ERROR(KAL_ERROR_KALINIT_INIT_CREATE_MEM_MUTEX_FAILED,                      initialize_KAL___fail_to_create_a_MEM_MUTEX)
X_KAL_ERROR(KAL_ERROR_KALINIT_INIT_MEMFAILED,                                    KAL_ERROR_KALINIT_INIT_MEMFAILED_)
X_KAL_ERROR(KAL_ERROR_KALINIT_MEMINIT_FAILED,                                    KAL_ERROR_KALINIT_MEMINIT_FAILED_)
X_KAL_ERROR(KAL_ERROR_KALINIT_CACHEINIT_FAILED,                                  KAL_ERROR_KALINIT_CACHEINIT_FAILED_)
X_KAL_ERROR(KAL_ERROR_KALINIT_CRCCHECK_FAILED,                                   check_CRC___CRC_error)
                                                                             
/* Task Management Error */                                                   
X_KAL_ERROR_ASSIGN(KAL_ERROR_TASKMNGT_CREATE_MEMFAILED,                 0x0201,  create_task___fail_to_allocate_memory)
X_KAL_ERROR(KAL_ERROR_TASKMNGT_CREATE_STACKFAILED,                               KAL_ERROR_TASKMNGT_CREATE_STACKFAILED_)
X_KAL_ERROR(KAL_ERROR_TASKMNGT_CREATE_FAILED,                                    create_task___fail)
X_KAL_ERROR(KAL_ERROR_TASKMNGT_DELETE_FAILED,                                    delete_task___fail)
X_KAL_ERROR(KAL_ERROR_TASKMNGT_SLEEP_FAILED,                                     KAL_ERROR_TASKMNGT_SLEEP_FAILED_)
X_KAL_ERROR(KAL_ERROR_TASKMNGT_GETID_FAILED,                                     KAL_ERROR_TASKMNGT_GETID_FAILED_)
X_KAL_ERROR(KAL_ERROR_TASKMNGT_STACKOVERFLOW,                                    thread_stack_is_overflow)
X_KAL_ERROR(KAL_ERROR_TASKMNGT_MODULE_ID_OUT_OF_RANGE,                           module_id_is_out_of_range)
X_KAL_ERROR(KAL_ERROR_TASKMNGT_STACKOVERFLOW_BY_MPU,                             stack_system_error__stack_overflow)
                                                                              
/* HISR Management Error */                                                   
X_KAL_ERROR_ASSIGN(KAL_ERROR_HISRMNGT_CREATE_MEMFAILED,                 0x0211,  create_HISR___fail_to_allocate_memory)
X_KAL_ERROR(KAL_ERROR_HISRMNGT_CREATE_STACKFAILED,                               KAL_ERROR_HISRMNGT_CREATE_STACKFAILED_)
X_KAL_ERROR(KAL_ERROR_HISRMNGT_CREATE_FAILED,                                    create_HISR___fail)
X_KAL_ERROR(KAL_ERROR_HISRMNGT_CREATE_TOO_MANY_HISR,                             create_HISR___fail_too_many_hisr)
X_KAL_ERROR(KAL_ERROR_HISRMNGT_SLEEP_FAILED,                                     KAL_ERROR_HISRMNGT_SLEEP_FAILED_)
X_KAL_ERROR(KAL_ERROR_HISRMNGT_ACTIVATE_FAILED,                                  activate_HISR___fail)
X_KAL_ERROR(KAL_ERROR_HISRMNGT_GETID_FAILED,                                     KAL_ERROR_HISRMNGT_GETID_FAILED_)
X_KAL_ERROR(KAL_ERROR_HISRMNGT_STACKOVERFLOW,                                    KAL_ERROR_HISRMNGT_STACKOVERFLOW_)
X_KAL_ERROR(KAL_HISRMNGT_REG_FAILED,                                             KAL_HISRMNGT_REG_FAILED_)
X_KAL_ERROR(KAL_ERROR_HISRMNGT_DELETE_FAILED,                                    delete_HISR___fail)                                                                              
	
/* task stack sharing */
X_KAL_ERROR_ASSIGN(KAL_ERROR_TASK_STACK_SHARING_WRONG_SP,				0x0221,  kal_prepare_stack_to_run___too_small_initial_stack_size)
X_KAL_ERROR(KAL_ERROR_TASK_STACK_SHARING_POOL_INSUFFICIENT, 					 kal_adm_realloc_for_stack___stack_pool_is_insufficient)	
X_KAL_ERROR(KAL_ERROR_TASK_STACK_SHARING_SP_UNALIGNED,							 kal_adm_realloc_for_stack___SP_is_not_8bytes_align)
X_KAL_ERROR(KAL_ERROR_TASK_STACK_SHARING_NULL_SP,								 __kal_adm_realloc_for_stack___wrong_input_null_sp)
X_KAL_ERROR(KAL_ERROR_TASK_STACK_SHARING_ZERO_SIZE, 							 __kal_adm_realloc_for_stack___wrong_input_0_size)
X_KAL_ERROR(KAL_ERROR_TASK_STACK_SHARING_WRONG_SP2, 							 kal_deque_msg_for_stack___too_small_initial_stack_size)
X_KAL_ERROR(KAL_ERROR_TASK_STACK_SHARING_STACKOVERFLOW, 						 kal_check_all_task_stacks___stack_overflow)
X_KAL_ERROR(KAL_ERROR_TASK_STACK_SHARING_ALLOW_TASK,							 kal_lock_current_stack___caller_is_not_a_task)
X_KAL_ERROR(KAL_ERROR_TASK_STACK_SHARING_ALLOW_TASK2,							 kal_unlock_current_stack___caller_is_not_a_task)	
X_KAL_ERROR(KAL_ERROR_TASK_STACK_SHARING_POOL_CORRUPTED,						 kal_adm_defragment_for_stack___correupted_stack_pool_linking_list)
X_KAL_ERROR(KAL_ERROR_TASK_STACK_SHARING_WRONG_OPTION,							 kal_adm_alloc_for_stack___wrong_option)
X_KAL_ERROR(KAL_ERROR_TASK_STACK_SHARING_POOL_CORRUPTED2,						 kal_adm_alloc_for_stack___correupted_stack_pool_linking_list)	
X_KAL_ERROR(KAL_ERROR_TASK_STACK_SHARING_POOL_CORRUPTED3,						 kal_adm_alloc_for_stack___correupted_stack_pool_linking_list2) 	  

/* Communication Management */                                                
X_KAL_ERROR_ASSIGN(KAL_ERROR_ITC_QCREATE_MEMFAILED,                     0x0301,  create_message_queue___fail_to_allocate_memory)
X_KAL_ERROR(KAL_ERROR_ITC_QCREATE_DATAMEMFAILED,                                 KAL_ERROR_ITC_QCREATE_DATAMEMFAILED_)
X_KAL_ERROR(KAL_ERROR_ITC_QCREATE_FAILED,                                        create_message_queue___fail)
X_KAL_ERROR(KAL_ERROR_ITC_QCREATE_FAILED_INT,                                    send_messages___internal_queue_is_not_created)
X_KAL_ERROR(KAL_ERROR_ITC_QENQUE_EXT_FAILED,                                     enqueue_to_extq___fail)
X_KAL_ERROR(KAL_ERROR_ITC_QENQUE_INT_FAILED,                                     enqueue_to_intq___fail)
X_KAL_ERROR(KAL_ERROR_ITC_QENQUE_NIL_FAILED,                                     enqueue___pointer_is_NULL)
X_KAL_ERROR(KAL_ERROR_ITC_QENQUE_SIG_FAILED,                                     enqueue___RTOS_fail)
X_KAL_ERROR(KAL_ERROR_ITC_QENQUE_SUS_FAILED,                                     enqueue___suspend_type_is_invalid)
X_KAL_ERROR(KAL_ERROR_ITC_QDEQUE_NIL_FAILED,                                     dequeue___pointer_is_NULL)
X_KAL_ERROR(KAL_ERROR_ITC_QDEQUE_SIG_FAILED,                                     dequeue___RTOS_fail)
X_KAL_ERROR(KAL_ERROR_ITC_QDEQUE_SUS_FAILED,                                     dequeue___suspend_type_is_invalid)
X_KAL_ERROR(KAL_ERROR_ITC_QDELETE_FAILED,                                        delete_message_queue___fail)
                                                                            
X_KAL_ERROR_ASSIGN(KAL_ERROR_ITC_MCREATE_MEMFAILED,                     0x0401,  create_MUTEX___fail_to_allocate_memory)
X_KAL_ERROR(KAL_ERROR_ITC_MDELETE_FAILED,                                        delete_MUTEX___fail)
X_KAL_ERROR(KAL_ERROR_ITC_MCREATE_FAILED,                                        create_MUTEX___fail)
X_KAL_ERROR(KAL_ERROR_ITC_MTAKE_FAILED,                                          take_MUTEX___fail)
X_KAL_ERROR(KAL_ERROR_ITC_MGIVE_FAILED,                                          give_MUTEX___fail)
X_KAL_ERROR(KAL_ERROR_ITC_MTAKE_INTERNAL_FAILED,                                 take_reentrant_MUTEX___fail)
X_KAL_ERROR(KAL_ERROR_ITC_MGIVE_INTERNAL_FAILED,                                 give_reentract_MUTEX___fail)
X_KAL_ERROR(KAL_ERROR_ITC_MCREATE_OUT_OF_RANGE,                                  create_enhance_MUTEX___create_too_many_mutex)
                                                                              
X_KAL_ERROR_ASSIGN(KAL_ERROR_ITC_SCREATE_MEMFAILED,                     0x0411,  create_semaphore___fail_to_allocate_memory)
X_KAL_ERROR(KAL_ERROR_ITC_SDELETE_FAILED,                                        delete_semaphore___fail)
X_KAL_ERROR(KAL_ERROR_ITC_SCREATE_FAILED,                                        create_semaphore___fail)
X_KAL_ERROR(KAL_ERROR_ITC_STAKE_FAILED,                                          take_semaphore___fail)
X_KAL_ERROR(KAL_ERROR_ITC_SGIVE_FAILED,                                          give_semaphore___fail)
                                                                              
X_KAL_ERROR_ASSIGN(KAL_ERROR_ITC_EGCREATE_MEMFAILED,                    0x0421,  create_event_group___fail_to_allocate_memory)
X_KAL_ERROR(KAL_ERROR_ITC_EGDELETE_FAILED,                                       delete_event_group___fail)
X_KAL_ERROR(KAL_ERROR_ITC_EGCREATE_FAILED,                                       create_event_group___fail)
X_KAL_ERROR(KAL_ERROR_ITC_EGSET_FAILED,                                          set_event_to_an_event_group___fail)
X_KAL_ERROR(KAL_ERROR_ITC_EGRETRIEVE_FAILED,                                     retrieve_event_from_an_event_group___fail)
                                                                              
X_KAL_ERROR_ASSIGN(KAL_ERROR_ITC_ILM_MULTIALLOC,                        0x0431,  allocate_ILM___ILM_is_already_allocated)
X_KAL_ERROR(KAL_ERROR_ITC_ILM_NOT_ALLOC,                                         send_messages___the_sending_ILM_is_not_allocated)
X_KAL_ERROR(KAL_ERROR_ITC_ILM_DOUBLE_FREE,                                       send_messages___the_sended_ILM_is_double_free_or_corruption)
X_KAL_ERROR(KAL_ERROR_ITC_ILM_WRONG_SAP_ID,                                      send_inline_messages___with_wrong_sap_id_in_task_context)  
X_KAL_ERROR(KAL_ERROR_ITC_ILM_APPEND_PEERBUF_FAILED,                             peerbuff_headspace_is_not_enough_or_inputlen_is_0_or_peerbuff_ptr_is_null)  
X_KAL_ERROR(KAL_ERROR_ITC_ILM_PREPEND_PEERBUF_FAILED,                            peerbuff_tailspace_is_not_enough_or_inputlen_is_0_or_peerbuff_ptr_is_null)  
X_KAL_ERROR(KAL_ERROR_ITC_ILM_REMOVE_TAIL_PEERBUF_FAILED,                        remove_tail_len_is_larger_than_pdu_len)
X_KAL_ERROR(KAL_ERROR_ITC_ILM_REMOVE_HEAD_PEERBUF_FAILED,                        remove_head_len_is_larger_than_pdu_len)
X_KAL_ERROR(KAL_ERROR_ITC_ILM_UPDATE_PEERBUF_FAILED,                             update_len_is_larger_than_orginal_peerbuff_len)  

                                                                              
X_KAL_ERROR_ASSIGN(KAL_ERROR_ITC_MSGID_CODE_EXCEED,                     0x0441,  check_message_ID_range___out_of_range)
X_KAL_ERROR(KAL_ERROR_PEERBUFF_EXTEND_FAILED,                                    extend_peer_buffer___fail)
                                                                              
/* Timer Management */                                                        
X_KAL_ERROR_ASSIGN(KAL_ERROR_TIMER_CREATE_MEMFAILED,                    0x0601,  create_timer___fail_to_allocate_memory)
X_KAL_ERROR(KAL_ERROR_TIMER_CREATE_FAILED,                                       create_timer___fail)
X_KAL_ERROR(KAL_ERROR_TIMER_DELETE_FAILED,                                       deletel_timer___fail)
X_KAL_ERROR(KAL_ERROR_TIMER_SET_FAILED,                                          set_timer___fail)
X_KAL_ERROR(KAL_ERROR_TIMER_CANCEL_FAILED,                                       cancel_timer___fail)
X_KAL_ERROR(KAL_ERROR_TIMER_GETTIME_FAILED,                                      KAL_ERROR_TIMER_GETTIME_FAILED_)
X_KAL_ERROR(KAL_ERROR_TIMER_GETTIMEREMAINING_FAILED,                             KAL_ERROR_TIMER_GETTIMEREMAINING_FAILED_)
X_KAL_ERROR(KAL_ERROR_TIMER_SCHED_FAILED,                                        KAL_ERROR_TIMER_SCHED_FAILED_)
X_KAL_ERROR(KAL_ERROR_TIMER_CONTROL_FAILED,                                      KAL_ERROR_TIMER_CONTROL_FAILED_)
X_KAL_ERROR(KAL_ERROR_TIMER_CALLBACK_OVERTIME_FAILED,                            KAL_ERROR_TIMER_CALLBACK_OVERTIME_FAILED_)
X_KAL_ERROR(KAL_ERROR_TIMER_HISR_OVERTIME_FAILED,                                KAL_ERROR_TIMER_HISR_OVERTIME_FAILED_)
                                                                             
/* Memory Management */                                                       
X_KAL_ERROR_ASSIGN(KAL_ERROR_MEMMNGT_ALLOC_FAILED,                      0x0701,  allocate_memory___out_of_memory)
X_KAL_ERROR(KAL_ERROR_MEMMNGT_GET_FREE_INDEX,                                    get_free_index___no_more_free_index)
X_KAL_ERROR(KAL_ERROR_MEMMNGT_ALLOC_DEBUGMEM_FAILED,                             KAL_ERROR_MEMMNGT_ALLOC_DEBUGMEM_FAILED_)
X_KAL_ERROR(KAL_ERROR_MEMMNGT_DEALLOC_FAILED_INDEX,                              free_memory___out_of_range)
X_KAL_ERROR(KAL_ERROR_MEMMNGT_DEALLOC_FAILED_MISMATCH,                           free_memory___pointer_is_not_matched)
X_KAL_ERROR(KAL_ERROR_MEMMNGT_DEALLOC_FAILED_DOUBLE_FREE,                        free_memory___double_free)
X_KAL_ERROR(KAL_ERROR_MEMMNGT_DEALLOC_FAILED_INVALID_PTR,                        free_memory___invalid_pointer)
X_KAL_ERROR(KAL_ERROR_MEMMNGT_DEALLOC_DEBUGMEM_FAILED,                           KAL_ERROR_MEMMNGT_DEALLOC_DEBUGMEM_FAILED_)
X_KAL_ERROR(KAL_ERROR_MEMMNGT_MEMCPY_FAILED,                                     KAL_ERROR_MEMMNGT_MEMCPY_FAILED_)
X_KAL_ERROR(KAL_ERROR_MEMMNGT_BUFFER_OVERRUN,                                    buffer_overrun)
X_KAL_ERROR(KAL_ERROR_MEMMNGT_MEM_OVERRUN,                                       memory_overrun)

X_KAL_ERROR(KAL_ERROR_APPMEM_INVALID_TYPE,                                       allocate_APPMEM___invalid_APPMEM_type)
X_KAL_ERROR(KAL_ERROR_APPMEM_ALLOC_FAIL,                                         allocate_APPMEM___out_of_memory)
X_KAL_ERROR(KAL_ERROR_APPMEM_FREE_NULL,                                          free_APPMEM___the_given_pointer_is_NULL)

/* buffer management */
/* 0. create */
X_KAL_ERROR_ASSIGN(KAL_ERROR_BUFFMNGR_CREATE_FAILED,                     0x0800, create_buffer_pool___failed)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_CREATE_MEMFAILED,                                 create_buffer_pool___fail_to_allocate_memory)
X_KAL_ERROR(KAL_ERROR_DATAPOOL_CREATE_FAILED,                                    create_data_buffer_pool___failed)
X_KAL_ERROR(KAL_ERROR_DATAPOOL_CREATE_MEMFAILED,                                 create_data_buffer_pool___fail_to_allocate_memory)
/* 1. delete */
X_KAL_ERROR_ASSIGN(KAL_ERROR_BUFFMNGR_DELETE_FAILED,                     0x0810, delete_buffer_pool___failed)
/* 2. allocate */
X_KAL_ERROR_ASSIGN(KAL_ERROR_BUFFMNGR_GETBUFF_FAILED,                    0x0820, get_buffer___failed)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_GETBUFF_POOLINDX_OUT_OF_RANGE,                    get_buffer___pool_index_is_out_of_range)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_GETBUFF_POOL_NOT_EXIST,                           get_buffer___inexistent_pool)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_GETBUFF_NOT_AVAILABLE,                            get_buffer___run_out_of_avaiable_buffer)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_GETBUFF_SIZE_FAILED,                              get_buffer___request_a_buffer_of_unspported_size)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_GET_DATABUFF_FAILED,                              get_data_buffer___incorrect_RLC_direction)
/* 3. free */
X_KAL_ERROR_ASSIGN(KAL_ERROR_BUFFMNGR_RELEASEBUFF_FAILED,                0x0830, release_buffer___failed)
X_KAL_ERROR_ASSIGN(KAL_ERROR_BUFFMNGR_RELEASE_DATABUFF_FAILED,           0x0832, release_data_buffer___failed)
/* 4. guard pattern */
X_KAL_ERROR_ASSIGN(KAL_ERROR_BUFFMNGR_FOOTER_FAILED,                     0x0840, validate_the_buffer_footer___footer_is_corrupted)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_HEADER_FAILED,                                    validate_the_buffer_header___header_is_corrupted)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_FOOTER_FAILED_GET,                                get_buffer___buffer_footer_is_corrupted)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_HEADER_FAILED_GET,                                get_buffer___buffer_header_is_corrupted)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_EXT_FOOTER_FAILED,                                validate_the_buffer_footer___extended_footer_is_corrupted)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_FREE_CORRUPTION,                                  get_or_release_buffer_FREE_is_corrupted)
/* 5. null pointer */
X_KAL_ERROR_ASSIGN(KAL_ERROR_BUFFMNGR_DELETE_NILPTR,                     0x0851, delete_buffer_pool___pool_is_nil_ptr)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_GETBUFF_NILPTR,                                   get_buffer___pool_is_nil_ptr)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_RELEASEBUFF_NILPTR,                               release_buffer___pool_is_nil_ptr)
/* 6. bad block ID */
/* 7. general */
/* 8. misc */
X_KAL_ERROR_ASSIGN(KAL_ERROR_BUFFMNGR_ISVALID_FAILED,                    0x0880, validate_the_buffer___invalid_buffer)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_POOLID_FAILED_GET,                                validate_the_buffer_poolid___poolid_is_corrupted)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_POSSIBLE_LEAKAGE,                                 kal_check_ctrl_buff_integrity_by_poolid___possible_leakage)
/* 9. NU+ related */
X_KAL_ERROR_ASSIGN(KAL_ERROR_BUFFMNGR_CREATE_INTERNAL_FAILED,            0x0890, NU_create_buffer_pool___failed)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_DELETE_INTERNAL_FAILED,                           NU_delete_buffer_pool___failed)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_GETBUFF_INTERNAL_FAILED,                          NU_get_buffer___failed)
X_KAL_ERROR(KAL_ERROR_BUFFMNGR_RELEASEBUFF_INTERNAL_FAILED,                      NU_release_buffer___failed)
X_KAL_ERROR(KAL_ERROR_DATAPOOL_CREATE_INTERNAL_FAILED,                           NU_create_data_buffer___failed)
X_KAL_ERROR(KAL_ERROR_DATAPOOL_GETBUFF_INTERNAL_FAILED,                          NU_get_data_buffer___failed)
X_KAL_ERROR(KAL_ERROR_DATAPOOL_RELEASEBUFF_INTERNAL_FAILED,                      NU_release_data_buffer___failed)
                                                                              
/* internal use */
X_KAL_ERROR_ASSIGN(KAL_ERROR_ERRORMNGR_FATALHANDLER_FAILED,             0x0901,  KAL_ERROR_ERRORMNGR_FATALHANDLER_FAILED_)
X_KAL_ERROR(KAL_ERROR_ERRORMNGR_REGISTERHANDLER_FAILED,                          KAL_ERROR_ERRORMNGR_REGISTERHANDLER_FAILED_)
                                                                                 
/* reserved for file system internal use */
X_KAL_ERROR_ASSIGN(KAL_ERROR_FILESYS_INTERNAL_FAILED,                   0x0a01,  file_system_internal_error)
X_KAL_ERROR(KAL_ERROR_FILESYS_NORMAL_FAILED,                                     file_system_normal_error)
X_KAL_ERROR(KAL_ERROR_FILESYS_CCCI_CONF_MISMATCH_FAILED,                         file_system_ccci_configuration_mismatch_error)
X_KAL_ERROR(KAL_ERROR_FILESYS_CCCI_PARA_ERROR_FAILED,                            file_system_ccci_parameter_error)
X_KAL_ERROR(KAL_ERROR_FILESYS_CCCI_NOPHY_FAILED,                                 file_system_ccci_no_phyiscal_channel_error)
X_KAL_ERROR(KAL_ERROR_FILESYS_CCCI_FS_SHUTDOWN_FAILED,                           file_system_ccci_shutdown_error)
X_KAL_ERROR_ASSIGN(KAL_ERROR_FILESYS_NAND_FDM_INTERNAL_FAILED,          0x0a10,  file_system_nand_fdm_internal_error)
X_KAL_ERROR_ASSIGN(KAL_ERROR_FILESYS_NOR_FDM_INTERNAL_FAILED,           0x0a20,  file_system_nor_fdm_internal_error)
                                                                                 
/* reserved for RTOS/LISR/Standard C/C++ Library internal use */
X_KAL_ERROR_ASSIGN(KAL_ERROR_SHOULD_NOT_EXECUTE,                        0x0b01,  the_dummy_function_should_not_be_invoked)
X_KAL_ERROR(KAL_ERROR_DIV_BY_0_FAILED,                                           sw_driven_divide_by_zero)
X_KAL_ERROR(KAL_ERROR_ABNORMAL_RESET_FAILED,                                     abnormal_reset)
X_KAL_ERROR(KAL_ERROR_CPU_DRIVEN_DIV_BY_0_FAILED,                                cpu_driven_divide_by_zero)
X_KAL_ERROR_ASSIGN(KAL_ERROR_NUCLEUS_INTERNAL_FAILED,                   0x0b10,  Nucleus_internal_error)
X_KAL_ERROR(KAL_ERROR_SYS_CALL_WHEN_LISR,                                        invoke_sys_call_when_in_lisr)
X_KAL_ERROR(KAL_ERROR_SYS_CALL_WHEN_TP_TAKEN,                                    invoke_sys_call_when_thread_protect_taken)
X_KAL_ERROR(KAL_ERROR_SYS_CALL_WHEN_INTERRUPT_DISABLED,                          invoke_sys_call_when_interrupt_disabled)
X_KAL_ERROR_ASSIGN(KAL_ERROR_DEMP_INVALID_LOCK_USER_FAILED,	        0x0b20,  invalid_demp_lock_user)
X_KAL_ERROR(KAL_ERROR_DEMP_EXHAUST_LOCK_QUOTA_FAILED,                            exhaust_the_given_demp_lock_quota)
X_KAL_ERROR(KAL_ERROR_DEMP_OVER_LOCK_UNLOCK_FAILED,                              demp_over_lock_or_unlock)
X_KAL_ERROR(KAL_ERROR_DEMP_HISR_MISUSE_DEMP_FAILED,                              hisr_demp_misuse)
X_KAL_ERROR(KAL_ERROR_DEMP_LISR_MISUSE_DEMP_FAILED,                              lisr_demp_misuse)
X_KAL_ERROR(KAL_ERROR_DEMP_LOCKOUT_IBIT_MISUSE_DEMP_FAILED,                      lockout_Ibit_demp_misuse)
X_KAL_ERROR(KAL_ERROR_DEMP_HOLD_PROTECT_MISUSE_DEMP_FAILED,                      hisr_lisr_demp_abuse)
X_KAL_ERROR_ASSIGN(KAL_ERROR_NON_REGISTERED_LISR,                       0x0b30,  the_LISR_is_not_registered)
X_KAL_ERROR(KAL_ERROR_OVER_60QBIT_FAILED,                                        over_60qbit)
X_KAL_ERROR(KAL_ERROR_DRV_EINT_INVALID_INDEX,                                    invalid_eint_index)
X_KAL_ERROR_ASSIGN(KAL_ERROR_INVALID_DMA_STATUS,                        0x0b50,  configure_unfinished_dma_channel_again)
X_KAL_ERROR(KAL_ERROR_INVALID_DMA_GDMA_GET,                                      generic_dma_not_release_yet)
X_KAL_ERROR(KAL_ERROR_INVALID_DMA_GDMA_FREE,                                     release_mismatch_generic_dma)
X_KAL_ERROR(KAL_ERROR_INVALID_DMA_PDMA_GET,                                      peripheral_dma_not_release_yet)
X_KAL_ERROR(KAL_ERROR_INVALID_DMA_PDMA_FREE,                                     release_mismatch_peripheral_dma)
X_KAL_ERROR(KAL_ERROR_INVALID_DMA_GDMA_COUNT,                                    violate_generic_dma_transfer_length)
X_KAL_ERROR(KAL_ERROR_INVALID_DMA_PDMA_COUNT,                                    violate_peripheral_dma_transfer_length)
X_KAL_ERROR(KAL_ERROR_INVALID_DMA_ZERO_COUNT,                                    transfer_length_should_not_be_zero)
X_KAL_ERROR(KAL_ERROR_INVALID_DMA_CACHE_ACCESS,                                  dma_cannot_access_cacheable_region)
X_KAL_ERROR(KAL_ERROR_INVALID_DMA_HWRX_FP,                                       not_support_fixed_pattern_in_hwrx)
X_KAL_ERROR(KAL_ERROR_INVALID_DMA_NO,                                            invalid_dma_no)
X_KAL_ERROR(KAL_ERROR_INVALID_DMA_UNALIGNMENT,                                   violate_8bytes_alignment)
X_KAL_ERROR(KAL_ERROR_INVALID_DMA_TYPE,                                          mismatch_dma_type)
X_KAL_ERROR(KAL_ERROR_INVALID_DMA_INTERRUPT_MODE,                                should_not_configure_interrupt_mode_for_shared_interrupt_design)

                                                                                 
/* Event Scheduler */
X_KAL_ERROR_ASSIGN(KAL_ERROR_EVTSCH_CREATE_MEMFAILED,                   0x0c01,  create_event_scheduler_pool___fail_to_allocate_memory)
X_KAL_ERROR(KAL_ERROR_EVTSCH_CREATE_FAILED,                                      create_event_schedulers_pool___fail_to_create_partition_memory)
X_KAL_ERROR(KAL_ERROR_EVTSCH_GETBUFF_FAILED,                                     fail_to_allocate_memory_for_event_scheduler)
X_KAL_ERROR(KAL_ERROR_EVTSCH_RELEASEBUFF_FAILED,                                 fail_to_free_memory_to_the_event_schedulers_pool)
X_KAL_ERROR(KAL_ERROR_EVTSCH_CANCEL_FAILED,                                      cancel_event___the_event_is_owned_by_another_event_scheduler_or_null_field)
X_KAL_ERROR(KAL_ERROR_EVTSCH_CANCEL_FAILED2,                                     cancel_event___the_event_id_is_out_of_event_pool_memory_range)
X_KAL_ERROR(KAL_ERROR_EVTSCH_ILLEGAL_PARAMETERS,                                 illegal_parameters_to_event_schedule_api)
X_KAL_ERROR(KAL_ERROR_EVTSCH_EVENT_POOL_CORRUPTED,                               allocate_or_release_event___event_pool_is_corrupted)
X_KAL_ERROR(KAL_ERROR_EVTSCH_INVALID_EVENT_SCHEDULER,                            set_event___input_invalid_event_scheduler)


/* reserved for IPC use */
X_KAL_ERROR_ASSIGN(KAL_ERROR_IPC_INTERNAL_FAILED,                      0x0d01,  ipc_internal_fatal_error)

/* general error */
X_KAL_ERROR_ASSIGN(KAL_ERROR_MODULE_ID_OUT_OF_RANGE,                   0x0e01,   general_error_module_id_out_of_range)
X_KAL_ERROR(KAL_ERROR_INVALID_PARAMETERS,                                        general_error_invalid_parameter)
                                                                              
/* reserved */
X_KAL_ERROR_ASSIGN(KAL_ERROR_DEBUGBUFFMNGR_GETPOOLSTAT_FAILED,          0x1001,  get_pool_statistics___pool_id_is_invalid)
X_KAL_ERROR(KAL_ERROR_DEBUGBUFFMNGR_RESETPOOLSTAT_FAILED,                        resset_pool_statistics___pool_id_is_invalid)
X_KAL_ERROR(KAL_ERROR_DEBUGBUFFMNGR_GETBUFFSTAT_FAILED,                          KAL_ERROR_DEBUGBUFFMNGR_GETBUFFSTAT_FAILED_)
X_KAL_ERROR(KAL_ERROR_DEBUGBUFFMNGR_RESETBUFFSTAT_FAILED,                        reset_buffer_statistics___buffer_is_not_valid)
X_KAL_ERROR(KAL_ERROR_DEBUGBUFFMNGR_POOLID_VALIDATION_FALIED,                    invalid_pool_id)
X_KAL_ERROR(KAL_ERROR_DEBUGBUFFMNGR_BUFF_OVERRUN_FAILED,                         check_buffer_overrun___the_given_buffer_is_not_allocated)
                                                                              
/* reserved */
X_KAL_ERROR_ASSIGN(KAL_ERROR_DEBUGERRORMNGR_REGISTERPRINT_FAILED,       0x1101,  KAL_ERROR_DEBUGERRORMNGR_REGISTERPRINT_FAILED_)
X_KAL_ERROR(KAL_ERROR_DEBUGERRORMNGR_PRINT_FAILED,                               KAL_ERROR_DEBUGERRORMNGR_PRINT_FAILED_)
                                                                              
/* reserved */
X_KAL_ERROR_ASSIGN(KAL_ERROR_DEBUGITC_GETQSTAT_FAILED,                  0x1201,  get_queue_statistics___queue_id_is_invaild)
X_KAL_ERROR(KAL_ERROR_DEBUGITC_RESETQSTAT_FAILED,                                reset_queue_statistics___queue_id_is_invalid)
                                                                              
/* reserved */
X_KAL_ERROR_ASSIGN(KAL_ERROR_DEBUGTIMER_GETTIMERSTAT_FAILED,            0x1301,  get_timer_statistics___timer_id_is_invalid)
X_KAL_ERROR(KAL_ERROR_DEBUGTIMER_RESETTIMERSTAT_FAILED,                          reset_timer_statistics___timer_id_is_invalid)

/* customization reserved */
X_KAL_ERROR_ASSIGN(KAL_ERROR_CUSTOMER_TASK_ID_EXCEED_UPPER_BOUND,       0x1501,  create_too_many_custom_tasks)
X_KAL_ERROR(KAL_ERROR_CUSTOMER_MOD_ID_EXCEED_UPPER_BOUND,                        add_too_many_custom_modules)
X_KAL_ERROR(KAL_ERROR_CUSTOMER_MEESAGE_ID_EXCEED_UPPER_BOUND,                    add_too_many_custom_messages)
X_KAL_ERROR(KAL_ERROR_CUSTOMER_SAP_ID_EXCEED_UPPER_BOUND,                        add_too_many_custom_SAP)

/* UAS FSM */
X_KAL_ERROR_ASSIGN(KAL_ERROR_ESM_ADD_INST_INVALID_SERVICE_ID,           0x1601,  fail_to_add_instance___invalid_service_id)
X_KAL_ERROR(KAL_ERROR_ESM_ADD_INST_NULL_CONTEXT,                                 fail_to_add_instance___null_context)
X_KAL_ERROR(KAL_ERROR_ESM_ADD_INST_INVALID_PROCESS_ID,                           fail_to_add_instance___invalid_process_id)
X_KAL_ERROR(KAL_ERROR_ESM_ADD_INST_ZERO_DATA_SIZE,                               fail_to_add_instance___zero_data_size)
X_KAL_ERROR(KAL_ERROR_ESM_ADD_INST_INVALID_INST_ID,                              fail_to_add_instance___invalid_instance_id)
X_KAL_ERROR(KAL_ERROR_ESM_ADD_INST_FAIL,                                         fail_to_add_instance)
X_KAL_ERROR(KAL_ERROR_ESM_ADD_FIRST_INST_NULL_COMP,                              fail_to_add_first_instance___null_component)
X_KAL_ERROR(KAL_ERROR_ESM_ADD_FIRST_INST_OVER_MAX_PROCESS,                       fail_to_add_first_instance___over_max_process)
X_KAL_ERROR(KAL_ERROR_ESM_ADD_FIRST_INST_INSERT_FAIL,                            fail_to_add_first_instance___fail_to_insert_instance_at_start)
X_KAL_ERROR(KAL_ERROR_ESM_DEL_INSTENTRY_INVALID_PROCESS_ID,                      fail_to_delete_instance_entry___invalid_process_id)
X_KAL_ERROR(KAL_ERROR_ESM_DEL_INSTENTRY_NULL_COMP_INFO,                          fail_to_delete_instance_entry___null_component_info)
X_KAL_ERROR(KAL_ERROR_ESM_DEL_INSTENTRY_OVER_MAX_PROCESS,                        fail_to_delete_instance_entry___over_max_process_number)
X_KAL_ERROR(KAL_ERROR_ESM_DEL_INSTENTRY_OVER_MAX_INST,                           fail_to_delete_instance_entry___over_max_instance)
X_KAL_ERROR(KAL_ERROR_ESM_DEL_INSTENTRY_INVALID_INST_ID,                         fail_to_delete_instance_entry___invalid_instance_id)
X_KAL_ERROR(KAL_ERROR_ESM_DEL_INSTENTRY_INACTIVE_INST,                           fail_to_delete_instance_entry___inactive_instance)
X_KAL_ERROR(KAL_ERROR_ESM_DEL_INSTENTRY_ROOT_INST,                               fail_to_delete_instance_entry___root_instance)
X_KAL_ERROR(KAL_ERROR_ESM_EXEC_CONTEXT_NULL_CONTEXT,                             fail_to_execute_context___null_context)
X_KAL_ERROR(KAL_ERROR_ESM_EXEC_CONTEXT_NULL_MSG,                                 fail_to_execute_context___null_message)
X_KAL_ERROR(KAL_ERROR_ESM_EXEC_CONTEXT_TRAN_NULL_MSG,                            fail_to_execute_context___translate_null_message)
X_KAL_ERROR(KAL_ERROR_ESM_EXEC_CONTEXT_NON_NULL_LAST_EVENT,                      fail_to_execute_context___last_event_is_not_null)
X_KAL_ERROR(KAL_ERROR_ESM_EXEC_CONTEXT_TRAN_MSG_FAIL,                            fail_to_execute_context___translate_message_failed)
X_KAL_ERROR(KAL_ERROR_ESM_GET_INSTPTR_NULL_COMP_INFO,                            fail_to_get_instance_pointer___null_component_info)
X_KAL_ERROR(KAL_ERROR_ESM_GET_INSTPTR_OVER_PROCESS_ID,                           fail_to_get_instance_pointer___over_process_id)
X_KAL_ERROR(KAL_ERROR_ESM_GET_INSTPTR_OVER_INST_ID,                              fail_to_get_instance_pointer___over_instance_id)
X_KAL_ERROR(KAL_ERROR_ESM_GET_INSTPTR_NULL_INST_ARRAY,                           fail_to_get_instance_pointer___null_instance_array)
X_KAL_ERROR(KAL_ERROR_ESM_GET_INSTPTR_NULL_INST,                                 fail_to_get_instance_pointer___null_instance)
X_KAL_ERROR(KAL_ERROR_ESM_POPULATE_NULL_SM,                                      fail_to_populate_state_machine___null_state_machine)
X_KAL_ERROR(KAL_ERROR_ESM_POPULATE_OVER_MAX_SERVICE_NAME,                        fail_to_populate_state_machine___over_max_service_name)
X_KAL_ERROR(KAL_ERROR_ESM_POPULATE_NULL_STATE_TBL,                               fail_to_populate_state_machine___null_state_table)
X_KAL_ERROR(KAL_ERROR_ESM_POPULATE_NULL_EVENT_DESC,                              fail_to_populate_state_machine___null_event_description)
X_KAL_ERROR(KAL_ERROR_ESM_POPULATE_NO_EVENT,                                     fail_to_populate_state_machine___no_event)
X_KAL_ERROR(KAL_ERROR_ESM_INIT_INST_ARRAY_NON_NULL_INST_ARRAY,                   fail_to_init_instance_array___non_instance_array)
X_KAL_ERROR(KAL_ERROR_ESM_INIT_INST_ARRAY_ZERO_PROCESS,                          fail_to_init_instance_array___zero_process)
X_KAL_ERROR(KAL_ERROR_ESM_INIT_INST_ARRAY_INVALID_MAX_INST,                      fail_to_init_instance_array___invalid_max_instance)
X_KAL_ERROR(KAL_ERROR_FSM_ADD_EVENTS_NULL_EVENT,                                 fail_to_add_events___null_event)
X_KAL_ERROR(KAL_ERROR_FSM_ADD_EVENTS_NULL_SERVICE,                               fail_to_add_events___null_service)
X_KAL_ERROR(KAL_ERROR_FSM_ADD_EVENTS_NULL_INST,                                  fail_to_add_events___null_instance)
X_KAL_ERROR(KAL_ERROR_FSM_ADD_EVENTS_NULL_EVENT_LIST,                            fail_to_add_events___null_event_list)
X_KAL_ERROR(KAL_ERROR_FSM_ADD_EVENTS_OVER_MAX_PROCESS,                           fail_to_add_events___over_max_process)
X_KAL_ERROR(KAL_ERROR_FSM_ADD_INSTENTRY_NULL_COMP_INFO,                          fail_to_add_instance_entry___null_component_info)
X_KAL_ERROR(KAL_ERROR_FSM_ADD_INSTENTRY_OVER_MAX_PROCESS,                        fail_to_add_instance_entry___over_max_process_number)
X_KAL_ERROR(KAL_ERROR_FSM_ADD_INSTENTRY_ZERO_DATA_SIZE,                          fail_to_add_instance_entry___zero_data_size)
X_KAL_ERROR(KAL_ERROR_FSM_ADD_INSTENTRY_INVALID_ID,                              fail_to_add_instance_entry___invalid_instance_id)
X_KAL_ERROR(KAL_ERROR_FSM_ADD_INSTENTRY_NULL_LINK,                               fail_to_add_instance_entry___null_link)
X_KAL_ERROR(KAL_ERROR_FSM_ADD_INSTENTRY_INSERT_FAIL,                             fail_to_add_instance_entry___fail_to_insert_instance_at_start)
X_KAL_ERROR(KAL_ERROR_FSM_DEL_INST_INVALID_SERVICE_ID,                           fail_to_delete_instance___invalid_service_id)
X_KAL_ERROR(KAL_ERROR_FSM_DEL_INST_INVALID_PROCESS_ID,                           fail_to_delete_instance___invalid_process_id)
X_KAL_ERROR(KAL_ERROR_FSM_EXEC_TRAN_NULL_CONTEXT,                                fail_to_execute_transition_function___null_context)
X_KAL_ERROR(KAL_ERROR_FSM_GET_FREEINST_NULL_COMP_INFO,                           fail_to_get_free_instance___null_component_info)
X_KAL_ERROR(KAL_ERROR_FSM_GET_FREEINST_NO_FREE_INST,                             fail_to_get_free_instance___no_free_instance)
X_KAL_ERROR(KAL_ERROR_FSM_GET_FREEINST_INVALID_SERVICE_ID,                       fail_to_get_free_instance___invalid_service_id)
X_KAL_ERROR(KAL_ERROR_FSM_GET_INSTDATA_NULL_CONTEXT,                             fail_to_get_instance_data___null_context)
X_KAL_ERROR(KAL_ERROR_FSM_GET_INSTDATA_INVALID_SERVICE_ID,                       fail_to_get_instance_data___invalid_service_id)
X_KAL_ERROR(KAL_ERROR_FSM_GET_INSTDATA_INVALID_INST_ID,                          fail_to_get_instance_data___invalid_instance_id)
X_KAL_ERROR(KAL_ERROR_FSM_GET_INSTDATA_INACTIVE_INST,                            fail_to_get_instance_data___inactive_instance)
X_KAL_ERROR(KAL_ERROR_FSM_HANDLE_SEVENT_NULL_EVENT,                              fail_to_handle_saved_events___null_event)
X_KAL_ERROR(KAL_ERROR_FSM_HANDLE_SEVENT_INVALID_SERVICE_ID,                      fail_to_handle_saved_events___invalid_service_id)
X_KAL_ERROR(KAL_ERROR_FSM_HANDLE_SEVENT_INVALID_INST_ID,                         fail_to_handle_saved_events___invalid_instance_id)
X_KAL_ERROR(KAL_ERROR_FSM_HANDLE_SEVENT_NULL_CONTEXT,                            fail_to_handle_saved_events___null_context)
X_KAL_ERROR(KAL_ERROR_FSM_HANDLE_SEVENT_TRAN_FAIL,                               fail_to_handle_saved_events___transition_failed)
X_KAL_ERROR(KAL_ERROR_FSM_PROCESS_EVENTS_NULL_EVENT,                             fail_to_process_events___null_event)
X_KAL_ERROR(KAL_ERROR_FSM_PROCESS_EVENTS_INVALID_PROCESS_ID,                     fail_to_process_events___invalid_process_id)
X_KAL_ERROR(KAL_ERROR_FSM_PROCESS_EVENTS_INVALID_INST_ID,                        fail_to_process_events___invalid_instance_id)
X_KAL_ERROR(KAL_ERROR_FSM_PROCESS_EVENTS_OVER_MAX_PROCESS,                       fail_to_process_events___over_max_process)
X_KAL_ERROR(KAL_ERROR_FSM_PROCESS_EVENTS_TRAN_FAIL,                              fail_to_process_events___transition_failed)
X_KAL_ERROR(KAL_ERROR_LSM_DEL_EVENTLIST_FAILED,                                  delete_a_non_empty_event_list)
X_KAL_ERROR(KAL_ERROR_LSM_UNDEL_LISTOBJ_FAILED,                                  dirty_count_not_consistent)
X_KAL_ERROR(KAL_ERROR_ESM_GET_INST_STATE_NULL_CONTEXT,                           fail_to_get_instance_state___null_context)
X_KAL_ERROR(KAL_ERROR_ESM_ADD_INST_ALLOC_SYSTEMMEM_FAILED,						 fail_to_add_instance___out_of_system_memory)
X_KAL_ERROR(KAL_ERROR_ESM_INIT_INST_ARRAY_ALLOC_SYSTEMMEM_FAILED,				 fail_to_init_instance_array___out_of_system_memory)
X_KAL_ERROR(KAL_ERROR_ESM_INIT_CONTEXT_ALLOC_SYSTEMMEM_FAILED,					 fail_to_init_context___out_of_system_memory)

/* ADM */
X_KAL_ERROR_ASSIGN(KAL_ERROR_ADM_CREATE_FAILED,                        0x1700,   create___adm_create_failed)
X_KAL_ERROR_ASSIGN(KAL_ERROR_ADM_DELETE_FAILED,                        0x1710,   delete___adm_delete_failed)
X_KAL_ERROR_ASSIGN(KAL_ERROR_ADM_ALLOC_FAILED,                         0x1720,   alloc___adm_alloc_failed)
X_KAL_ERROR_ASSIGN(KAL_ERROR_ADM_ALLOC_DYNCACHE_FAILED,                0x1726,   alloc___adm_switch_cache_failed)
X_KAL_ERROR_ASSIGN(KAL_ERROR_ADM_REALLOC_FAILED,                       0x172c,   realloc___adm_realloc_failed)
X_KAL_ERROR_ASSIGN(KAL_ERROR_ADM_FREE_FAILED,                          0x1730,   free___adm_free_failed)
X_KAL_ERROR_ASSIGN(KAL_ERROR_ADM_FREE_DOUBLEFREE,                      0x1732,   free___adm_double_free)
X_KAL_ERROR_ASSIGN(KAL_ERROR_ADM_FOOTER_FAILED,                        0x1740,   free___adm_footer_corrupted)
X_KAL_ERROR(KAL_ERROR_ADM_HEADER_FAILED,                                         free___adm_header_corrupted)
X_KAL_ERROR(KAL_ERROR_ADM_FREEPATTERN_CORRUPTION,                                alloc_or_free___adm_freepattern_corrupted)
X_KAL_ERROR_ASSIGN(KAL_ERROR_ADM_NILPTR,                               0x1750,   fail___adm_get_a_null_pointer)
X_KAL_ERROR(KAL_ERROR_ADM_DELETE_NILPTR,                                         delete___adm_delete_null_pool)
X_KAL_ERROR(KAL_ERROR_ADM_ALLOC_NILPTR,                                          alloc___adm_alloc_null_pool)
X_KAL_ERROR(KAL_ERROR_ADM_FREE_NILPTR,                                           free___adm_free_null_pool)
X_KAL_ERROR(KAL_ERROR_ADM_REALLOC_NILPTR,                                        realloc___adm_realloc_null_pool)
X_KAL_ERROR_ASSIGN(KAL_ERROR_ADM_BADID,                                0x1760,   fail___admid_in_cb_corrupted)
X_KAL_ERROR(KAL_ERROR_ADM_DELETE_BADID,                                          delete___admid_in_cb_corrupted)
X_KAL_ERROR(KAL_ERROR_ADM_ALLOC_BADID,                                           alloc___admid_in_cb_corrupted)
X_KAL_ERROR(KAL_ERROR_ADM_FREE_BADID,                                            free___admid_in_cb_corrupted)
X_KAL_ERROR(KAL_ERROR_ADM_REALLOC_BADID,                                         realloc___admid_in_cb_corrupted)
X_KAL_ERROR_ASSIGN(KAL_ERROR_ADM_CONCURRENT_OPERATION,                 0x1770,   concurrent___adm_concurrent_operation_detected)
X_KAL_ERROR(KAL_ERROR_ADM_BADPTR,                                                fail___adm_get_a_bad_pointer)
X_KAL_ERROR_ASSIGN(KAL_ERROR_ADM_GETEXTHEADER_FAILED,                  0x1781,   get_extheader___no_extheader_on_this_adm)

/* AFM */
X_KAL_ERROR_ASSIGN(KAL_ERROR_AFM_CREATE_FAILED,                        0x1800,   create___afm_create_failed)
X_KAL_ERROR_ASSIGN(KAL_ERROR_AFM_DELETE_FAILED,                        0x1810,   delete___afm_delete_failed)
X_KAL_ERROR_ASSIGN(KAL_ERROR_AFM_ALLOC_FAILED,                         0x1820,   alloc___afm_alloc_failed)
X_KAL_ERROR_ASSIGN(KAL_ERROR_AFM_ALLOC_DYNCACHE_FAILED,                0x1826,   alloc___afm_switch_cache_failed)
X_KAL_ERROR_ASSIGN(KAL_ERROR_AFM_FREE_FAILED,                          0x1830,   free___afm_free_failed)
X_KAL_ERROR(KAL_ERROR_AFM_FREE_DOUBLEFREE,                                       free___afm_double_free)
X_KAL_ERROR_ASSIGN(KAL_ERROR_AFM_FOOTER_FAILED,                        0x1840,   free___afm_footer_corrupted)
X_KAL_ERROR(KAL_ERROR_AFM_HEADER_FAILED,                                         free___afm_header_corrupted)
X_KAL_ERROR(KAL_ERROR_AFM_FOOTER_FAILED_GET,                                     alloc___afm_footer_corrupted)
X_KAL_ERROR(KAL_ERROR_AFM_HEADER_FAILED_GET,                                     alloc___afm_header_corrupted)
X_KAL_ERROR(KAL_ERROR_AFM_FREEPATTERN_CORRUPTION,                                alloc___afm_freepattern_corrupted)
X_KAL_ERROR_ASSIGN(KAL_ERROR_AFM_NILPTR,                               0x1850,   fail___afm_get_a_null_pointer)
X_KAL_ERROR(KAL_ERROR_AFM_DELETE_NILPTR,                                         fail___afm_delete_null_pool)
X_KAL_ERROR(KAL_ERROR_AFM_ALLOC_NILPTR,                                          fail___afm_alloc_null_pool)
X_KAL_ERROR(KAL_ERROR_AFM_FREE_NILPTR,                                           fail___afm_free_null_pool)
X_KAL_ERROR_ASSIGN(KAL_ERROR_AFM_BADID,                                0x1860,   fail___afmid_in_cb_corrupted)
X_KAL_ERROR(KAL_ERROR_AFM_DELETE_BADID,                                          delete___afmid_in_cb_corrupted)
X_KAL_ERROR(KAL_ERROR_AFM_ALLOC_BADID,                                           alloc___afmid_in_cb_corrupted)
X_KAL_ERROR(KAL_ERROR_AFM_FREE_BADID,                                            free___afmid_in_cb_corrupted)
X_KAL_ERROR_ASSIGN(KAL_ERROR_AFM_CONCURRENT_OPERATION,	               0x1870,   concurrent___afm_concurrent_operation_detected)
X_KAL_ERROR(KAL_ERROR_AFM_BADPTR,                                                fail___afm_bad_pointer)


#undef X_KAL_ERROR
#undef X_KAL_ERROR_ASSIGN

