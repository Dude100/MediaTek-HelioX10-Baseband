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
 *   SST_itc_trc.h 
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains definitions for trace on target.
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
  
	TRC_MSG(SST_ITC_COMMON_ILM1, "Content of ILM* being processed as below:")
	TRC_MSG(SST_ITC_COMMON_ILM2, "Content of ILM retrieved from module_ilm_g[%Mmodule_type] as below:")
	
	/* Phase 1: Exception Message, grouped according to type */
	TRC_MSG(SST_PHASE1_301_01, "In kal_create_msg_q( ), dynamic memory allocation failed for kal_queue_type..")
	TRC_MSG(SST_PHASE1_301_03, "In kal_create_msg_q( ), dynamic memory allocation failed for queue buffer.")
	TRC_MSG(SST_PHASE1_301_04, "In kal_create_msg_q( ), dynamic debug memory allocation failed for kal_queue_stat_type.")
	
	TRC_MSG(SST_PHASE1_303_9999_P1, "NULL internal queue pointer is provided in msg_send_int_queue")
	
	TRC_MSG(SST_PHASE1_303_6666_P1, "NULL external queue pointer is provided in stack_send_2_ext_q")
	
	TRC_MSG(SST_PHASE1_305_01, "While calling kal_enque_msg( ), NULL external queue is provided.")	
	TRC_MSG(SST_PHASE1_305_02, "While calling kal_enque_msg( ), source buffer pointer is NULL.")
	TRC_MSG(SST_PHASE1_305_19__P1, "In kal_enque_msg(), control block of destination queue was damaged, ")
	TRC_MSG(SST_PHASE1_305_19__P2, "which is no longer 0x51554555")
	TRC_MSG(SST_PHASE1_305_24_, "In kal_enque_msg(), suspension style is expected, but there is no running task currently.")
	
	TRC_MSG(SST_PHASE1_305_8888, "External queue full is encountered while message delivery.")	
	TRC_MSG(SST_PHASE1_305_7777, "Internal queue full is encountered while message delivery.")	
	
	TRC_MSG(SST_PHASE1_305_FF, "In kal_enque_msg(), operation failed!")	
	
	TRC_MSG(SST_PHASE1_307_0, "In kal_deque_msg(), queue ID should not be NULL.")	
	TRC_MSG(SST_PHASE1_307_1, "In kal_deque_msg(), destination buffer pointer should not be NULL.")	
	TRC_MSG(SST_PHASE1_307_19_, "In kal_deque_msg(), control block of destination queue was damaged,which is no longer 0x51554555.")	
	TRC_MSG(SST_PHASE1_307_24_, "In kal_deque_msg(), suspension style is expected, but there is no running task currently.")	
	
	TRC_MSG(SST_PHASE1_401_1, "In kal_create_mutex ( ), dynamic memory allocation failed for data type kal_mutex_type.")	
	TRC_MSG(SST_PHASE1_401_4, "In kal_create_mutex ( ), dynamic debug memory allocation failed for kal_internal_mutex_statistics.")	
	
	TRC_MSG(SST_PHASE1_403_FF, "In kal_create_mutex ( ), NU_Create_Semaphore not return NU_SUCCESS.")	
	
	TRC_MSG(SST_PHASE1_404_1, "In kal_take_mutex ( ), NULL pointer is provided for obtaining mutex.")	
	TRC_MSG(SST_PHASE1_404_21_, "In kal_take_mutex ( ),control block of semaphore may be corrupted or it is an illegal pointer.")	
	TRC_MSG(SST_PHASE1_404_24_, "In kal_take_mutex(), suspension style is expected, but there is no running task currently.")	
	
	TRC_MSG(SST_PHASE1_405_0, "In kal_give_mutex ( ), NULL pointer is provided for giving mutex.")	
	TRC_MSG(SST_PHASE1_405_MUID, "A MUTEX must be obtained and given by the same task.")	
	TRC_MSG(SST_PHASE1_405_FF, "In kal_give_mutex ( ),control block of semaphore may be corrupted or it is an illegal pointer.")	

	TRC_MSG(SST_PHASE1_411_1, "In kal_create_sem ( ), dynamic memory allocation failed for data type kal_sem_type.")
	TRC_MSG(SST_PHASE1_411_4, "In kal_create_sem ( ), dynamic debug memory allocation failed for kal_internal_sem_statistics.")
	
	TRC_MSG(SST_PHASE1_413_FF, "In kal_create_sem ( ), NU_Create_Semaphore not return NU_SUCCESS.")	
	
	TRC_MSG(SST_PHASE1_414_0, "In kal_take_sem ( ),NULL pointer is provid.")	
	TRC_MSG(SST_PHASE1_414_21_, "In kal_take_sem ( ),control block of semaphore may be corrupted or it is an illegal pointer.")	
	TRC_MSG(SST_PHASE1_414_24_, "In kal_take_sem(), suspension style is expected, but there is no running task currently.")
	
	TRC_MSG(SST_PHASE1_415_0, "In kal_give_sem ( ), NULL pointer is provided for giving mutex.")
	TRC_MSG(SST_PHASE1_415_FF, "In kal_give_sem ( ),control block of semaphore may be corrupted or it is an illegal pointer.")

	TRC_MSG(SST_PHASE1_421_1, "In kal_create_event_group ( ), dynamic memory allocation failed for data type kal_eventgrp_type.")
	
	TRC_MSG(SST_PHASE1_423_FF, "In kal_create_event_group ( ), NU_Create_Event_Group not return NU_SUCCESS.")	
	
	TRC_MSG(SST_PHASE1_424_21_, "In kal_set_eg_events ( ),control block of event group may be corrupted or it is an illegal pointer.")
	TRC_MSG(SST_PHASE1_424_13_, "In kal_set_eg_events (), event group operation is undefined, it is neither NU_AND nor NU_OR.")

   TRC_MSG(SST_PHASE1_425_13_, "In kal_retrieve_eg_events ( ), operation is not supported, they are nether NU_AND, NU_AND_CONSUME, NU_OR nor NU_OR_CONSUME.")
	TRC_MSG(SST_PHASE1_425_24_, "In kal_retrieve_eg_events (), suspension style is expected, but there is no running task currently.")

   TRC_MSG(SST_PHASE1_431, "In allocate_ilm(), module ILM %Mmodule_type has not yet been delivered or duplicated!")
   
   TRC_MSG(SST_PHASE1_432, "In msg_send_ext_queue(), %c%c%c%c%c%c%c%c is going to send an ILM without calling allocate_ilm() !")
   
   TRC_MSG(SST_PHASE1_441, "In stack_check_msgid_range(), message ID overflow is detected at %Mmsg_type!")
   
	
	/* Phase 2: Detailed analysis */
	TRC_MSG(SST_PHASE2_303_9999_P1, "My dear, %c%c%c%c%c%c%c%c is giving an illegal destination module ID for message delivery")
	TRC_MSG(SST_PHASE2_303_9999_P2, "destination module ID %d is out of range (max:%d).")
	
	TRC_MSG(SST_PHASE2_303_9999_P3, "My dear, %c%c%c%c%c%c%c%c is sending message via module ID, who has no internal queue.")
	TRC_MSG(SST_PHASE2_303_9999_P4, "Please refer to information above for debugging!")
		
	TRC_MSG(SST_PHASE2_303_9999_P5, "My dear, %c%c%c%c%c%c%c%c is sending message via module ID, whose relative task is not existed")
	TRC_MSG(SST_PHASE2_303_9999_P6, "in current boot mode. Please refer to information above for debugging!")
	
	TRC_MSG(SST_PHASE2_303_QUEUE_ID, "Illegal or may be corrupted pointer used to enqueue message!")
	
	TRC_MSG(SST_PHASE2_303_8888_P1, "While sending message to %c%c%c%c%c%c%c%c, %c%c%c%c%c%c%c%c found that,")
	TRC_MSG(SST_PHASE2_303_8888_P2, "external queue of %c%c%c%c%c%c%c%c is full!")
	TRC_MSG(SST_PHASE2_303_8888_P3, "Following is its complete content:")
	TRC_MSG(SST_PHASE2_303_8888_P4, "Task %c%c%c%c%c%c%c%c is in busy waiting, until fails to process message in external queue;")
	TRC_MSG(SST_PHASE2_303_8888_P5, "Following is its complete content:")
	TRC_MSG(SST_PHASE2_303_8888_P6, "My dear, Task %c%c%c%c%c%c%c%c may be blocked by thread listed below:")
	TRC_MSG(SST_PHASE2_303_8888_P7, "Task %c%c%c%c%c%c%c%c Task may be blocked by this enhanced mutex")
	TRC_MSG(SST_PHASE2_303_8888_P8, "The call stack of enhanced mutex owner: %c%c%c%c%c%c%c%c")
	TRC_MSG(SST_PHASE2_303_8888_P9, "Task %c%c%c%c%c%c%c%c Task may be blocked by this mutex")
	TRC_MSG(SST_PHASE2_303_8888_P10, "The call stack of mutex owner: %c%c%c%c%c%c%c%c")
	TRC_MSG(SST_PHASE2_303_8888_P11, "Task %c%c%c%c%c%c%c%c Task may be blocked by this semaphore")
	
	TRC_MSG(SST_PHASE2_QUEUE_LARGE_COUNT, "The Qneue size is larger than %d. We only parsing %d ILM in queue. Please reduce the queue size")
	TRC_MSG(SST_PHASE2_QUEUE_MESS_COUNT, "There are totally %d entries with same content,")

   TRC_MSG(SST_PHASE2_303_7777_P1, "While %c%c%c%c%c%c%c%c is running, %Mmodule_type sends msg to %Mmodule_type")

	TRC_MSG(SST_PHASE2_405_MUID, "Note that, mutex is now owned by %c%c%c%c%c%c%c%c, and could not be given by task %c%c%c%c%c%c%c%c.")	
	
	TRC_MSG(SST_PHASE2_305_QUEUE_TIME_STAMP_0, "The exception frame No: %d")
	TRC_MSG(SST_PHASE2_305_QUEUE_TIME_STAMP_1, "The last 3 ILM taken frame No: %d, %d, %d")
	TRC_MSG(SST_PHASE2_305_QUEUE_TIME_STAMP_2, "The last queue empry frame No %d")
	TRC_MSG(SST_PHASE2_305_QUEUE_TIME_STAMP_3, "Receiver External Queue Size %d ")
	TRC_MSG(SST_PHASE2_305_QUEUE_TIME_STAMP_4, "The last frame No when Queue Contains %d, %d, %d ILMs  %d, %d, %d")
	
	
	TRC_MSG(SST_PHASE2_305_QUEUE_CASE_I, "fatal 0x305 case I: blocked by high priority thread, %c%c%c%c%c%c%c%c")
	TRC_MSG(SST_PHASE2_305_QUEUE_CASE_II, "fatal 0x305 case II: receiver is suspended")
	TRC_MSG(SST_PHASE2_305_QUEUE_CASE_III, "fatal 0x305 case III: sender sent too many ILMs in short time")
	TRC_MSG(SST_PHASE2_305_QUEUE_CASE_III_Offender, "Offender %d")
	TRC_MSG(SST_PHASE2_305_QUEUE_CASE_IV, "fatal 0x305 case IV: receiver traps in infinite loops")
	TRC_MSG(SST_PHASE2_305_QUEUE_CASE_V, "fatal 0x305 case V: startation of receiver ")
	TRC_MSG(SST_PHASE2_305_QUEUE_CASE_UNDEF, "fatal 0x305 case X: Complicated and can not be defined by Online SST")
	
	
	
	/* Dump data structure */
	/* Queue */
	TRC_MSG(SST_QU_QCB, "Content of queue control block as below:")
   TRC_MSG(SST_QU_QCB_CREATED, "   qu_created : 0x%X")
	TRC_MSG(SST_QU_QCB_ID, "   qu_id : 0x%X")
	TRC_MSG(SST_QU_QCB_NAME, "   qu_name : %c%c%c%c%c%c%c%c")
	TRC_MSG(SST_QU_QCB_FIXED_SIZE, "   qu_fixed_size : %d")
	TRC_MSG(SST_QU_QCB_SUSP_F, "   qu_fifo_suspend : %d")
	TRC_MSG(SST_QU_QCB_SIZE, "   qu_queue_size : %d")
	TRC_MSG(SST_QU_QCB_MESS_COUNT, "   qu_messages : %d")
	TRC_MSG(SST_QU_QCB_MESS_SIZE, "   qu_message_size : %d")
	TRC_MSG(SST_QU_QCB_AVAIL, "   qu_available : %d")
	TRC_MSG(SST_QU_QCB_START_ADDR, "   qu_start : 0x%X")
	TRC_MSG(SST_QU_QCB_END_ADDR, "   qu_end : 0x%X")
	TRC_MSG(SST_QU_QCB_READ_PTR, "   qu_read : 0x%X")
	TRC_MSG(SST_QU_QCB_WRITE_PTR, "   qu_write : 0x%X")
	TRC_MSG(SST_QU_QCB_TASK_WAITING, "   qu_tasks_waiting : %d")
	TRC_MSG(SST_QU_QCB_URGENT_LIST, "   qu_urgent_list : 0x%X")
	TRC_MSG(SST_QU_QCB_SUSP_LIST, "   qu_suspension_list : 0x%X")

	/* Semaphore */
	TRC_MSG(SST_SM_SCB, "Content of semaphore control block as below:")
   TRC_MSG(SST_SM_SCB_CREATED, "   sm_created : 0x%X")
	TRC_MSG(SST_SM_SCB_ID, "   sm_id : 0x%X")
	TRC_MSG(SST_SM_SCB_NAME, "   sm_name : %c%c%c%c%c%c%c%c")
	TRC_MSG(SST_SM_SCB_COUNT, "   sm_semaphore_count : %d")
	TRC_MSG(SST_SM_SCB_FIFO_SUS, "   sm_fifo_suspend : %d")
	TRC_MSG(SST_SM_SCB_TASKS_WAIT, "   sm_tasks_waiting : %d")
	TRC_MSG(SST_SM_SCB_SUSP_LIST, "   sm_suspension_list : 0x%X")	

	/* Event group */
	TRC_MSG(SST_EV_GCB, "Content of event group control block as below:")
   TRC_MSG(SST_EV_GCB_CREATED, "   ev_created : 0x%X")
	TRC_MSG(SST_EV_GCB_ID, "   ev_id : 0x%X")
	TRC_MSG(SST_EV_GCB_NAME, "   ev_name : %c%c%c%c%c%c%c%c")
	TRC_MSG(SST_EV_GCB_CUR_EVENTS, "   ev_current_events : %d")
	TRC_MSG(SST_EV_GCB_TASKS_WAIT, "   ev_tasks_waiting : %d")
	TRC_MSG(SST_EV_GCB_SUSP_LIST, "   ev_suspension_list : 0x%X")	

	
	/* Enhanced mutex */
	TRC_MSG(SST_EMTX_EMCB, "Content of enhanced mutex control block as below:")
	TRC_MSG(SST_EMTX_EMCB_MAX_PRIO, "   emtx_max_wprio : %d")
	TRC_MSG(SST_EMTX_EMCB_SUSPEND_COUNT, "   emtx_suspension_count : %d")
	TRC_MSG(SST_EMTX_EMCB_OWNER_TASK_NAME, "   owner task name : %c%c%c%c%c%c%c%c")
	TRC_MSG(SST_EMTX_EMCB_EMTX_NAME, "   emtx_name : %c%c%c%c%c%c%c%c")	

	
