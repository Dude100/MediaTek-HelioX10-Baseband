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
 *   SST_task_trc.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
  
	/* Phase 1: Exception Message grouped according to type */
	TRC_MSG(SST_PHASE1_201_01, "In kal_create_task( ), dynamic memory allocation failed for task stack.")
	TRC_MSG(SST_PHASE1_201_02, "In kal_create_task( ), dynamic memory allocation failed for kal_task_type.")
	TRC_MSG(SST_PHASE1_201_04, "In kal_create_task( ), dynamic debug memory allocation failed for kal_task_stat_type.")
	TRC_MSG(SST_PHASE1_201_07, "In kal_create_task( ), dynamic internal memory allocation failed for task stack.")
	
	TRC_MSG(SST_PHASE1_203_01, "Zero stack size is provided in task creation.")
	TRC_MSG(SST_PHASE1_203_02, "NULL entry function is provided in task creation.")
	TRC_MSG(SST_PHASE1_203_22_, "In kal_create_task(), failure due to insufficient stack size (less than 240Bytes).")
	TRC_MSG(SST_PHASE1_203_25_, "In kal_create_task(), failure due to duplicated creation.")
	
	TRC_MSG(SST_PHASE1_207_TASKID_P1, "In kal_deque_msg (), stack overflow is detected at TCC_Suspend_Task(),")
   TRC_MSG(SST_PHASE1_207_TASKID_P2, "where stack guard pattern 'STACKEND' had been corrupted, it becomes 0x%X 0x%X.")
   TRC_MSG(SST_PHASE1_209_TASKID_P1, "stack overflow is detected by MPU, please check ex_cp15_log")
   
   TRC_MSG(SST_PHASE1_211_01, "In kal_create_hisr( ), dynamic memory allocation failed for HISR's stack.")
	TRC_MSG(SST_PHASE1_211_02, "In kal_create_hisr( ), dynamic memory allocation failed for kal_hisr_type.")
	TRC_MSG(SST_PHASE1_211_04, "In kal_create_hisr( ), dynamic debug memory allocation failed for kal_hisr_stat_type.")
	TRC_MSG(SST_PHASE1_211_07, "In kal_create_hisr( ), dynamic internal memory allocation failed for HISR's stack!")
   
   TRC_MSG(SST_PHASE1_213_01, "In kal_create_hisr( ), zero stack size is provided!")
   TRC_MSG(SST_PHASE1_213_02, "In kal_create_hisr( ), HISR entry function is NULL!")
   TRC_MSG(SST_PHASE1_213_03, "In kal_create_hisr( ), illegal priority value is provided, only 0, 1 and 2 are valid!")
   TRC_MSG(SST_PHASE1_213_04, "In kal_create_hisr( ), priority 0 is assigned to an HISR other than L1_HISR!")
   TRC_MSG(SST_PHASE1_213_05, "In kal_create_hisr( ), number of HISR exceeding maximal boundary %d!")
   
   TRC_MSG(SST_PHASE1_216_9__P1, "In kal_activate_hisr(), HISR control block corrupted or incorrect")
      
   /* Phase 2: Detailed analysis */
   TRC_MSG(SST_PHASE2_203_01, "Notice that, stack size is referenced from array task_info_g, its content as below:")
   TRC_MSG(SST_PHASE2_203_02, "Notice that, task's entry function is referenced from array task_info_g, its content as below:")
   
   TRC_MSG(SST_PHASE2_207_TASKID_SUB1_P1, "No reasonable call path within 128words started from stack guard pattern")
   TRC_MSG(SST_PHASE2_207_TASKID_SUB1_P2, "pattern, perhaps unintentional corruption from somewhere.")

   TRC_MSG(SST_PHASE2_207_TASKID_SUB2_P1, "Task %c%c%c%c%c%c%c%c sufferes from stack overflow, and its stack size is %dBytes.")   
	TRC_MSG(SST_PHASE2_207_TASKID_SUB2_P2, "Possible call path traced back from stack guard pattern as above (max %d words).")
	                               
	TRC_MSG(SST_PHASE2_TASK_INFO_G_CORRUPTED_P1, "Serious error, memory corruption at address 0x%X, and please refer")
   TRC_MSG(SST_PHASE2_TASK_INFO_G_CORRUPTED_P2, "to task_info_g[ ] below for more detailed.")
   
   TRC_MSG(SST_PHASE2_216_9_1_P1, "My dear, pointer used in activating HISR is corrupted, where tc_id is no longer 0x48495352!")
	TRC_MSG(SST_PHASE2_216_9_1_P2, "Content of HISR as below;")
	
	TRC_MSG(SST_PHASE2_216_9_2, "HISR ID 0x48495352 is found, may fail at somewhere!")
	
	/* Phase 3: Guideline and follow-ups grouped according to type */
   TRC_MSG(SST_PHASE3_203_22__P1, "Please contact people in charge of task %c%c%c%c%c ")
   TRC_MSG(SST_PHASE3_203_22__P2, "to provide stack size larger than 240B.")
   
   TRC_MSG(SST_PHASE3_203_25__P1, "Please contact people in charge of task %c%c%c%c%c for bug fixing. And, control")
   TRC_MSG(SST_PHASE3_203_25__P2, "block of relative task control block as below,")
	
   TRC_MSG(SST_PHASE3_207_TASKID, "In case of reproducing, please set the write breakpoint at address 0x%X.")
		
		
   /* Dump data structure */
   TRC_MSG(SST_TC_HCB_CREATED, "tc_created : 0x%X")
	TRC_MSG(SST_TC_HCB_ID, "tc_id : 0x%X")
	TRC_MSG(SST_TC_HCB_NAME, "tc_name : %c%c%c%c%c%c%c%c")
	TRC_MSG(SST_TC_HCB_PRIORITY, "tc_priority : %d")
	TRC_MSG(SST_TC_HCB_SCHEDULED, "tc_scheduled : %d")
	TRC_MSG(SST_TC_HCB_TIMESLICE, "tc_cur_time_slice : %d")
	TRC_MSG(SST_TC_HCB_STACK_START, "tc_stack_start : 0x%X")
	TRC_MSG(SST_TC_HCB_STACK_END, "tc_stack_end : 0x%X")
	TRC_MSG(SST_TC_HCB_SP, "tc_stack_pointer : 0x%X")
	TRC_MSG(SST_TC_HCB_STACK_SIZE, "tc_stack_size : %d")
	TRC_MSG(SST_TC_HCB_STACK_MIN, "tc_stack_minimum : %d")
	TRC_MSG(SST_TC_HCB_CURR_PROTECT, "tc_current_protect : 0x%X")
	TRC_MSG(SST_TC_HCB_ACTIVE_NEXT, "tc_active_next : 0x%X")
	TRC_MSG(SST_TC_HCB_ACTIVATION, "tc_activation_count : %d")
	TRC_MSG(SST_TC_HCB_ENTRY, "tc_entry : 0x%X")
	
	/* Dump task status */
	TRC_MSG(SST_TASK_READY, "%c%c%c%c%c%c%c%c is in ready state, it is ready to execute or running!")
	TRC_MSG(SST_TASK_PURE_SUSPEND, "%c%c%c%c%c%c%c%c is in pure suspend state!")
	TRC_MSG(SST_TASK_SLEEP_SUSPEND , "%c%c%c%c%c%c%c%c is in sleep suspend state!")
	TRC_MSG(SST_TASK_QUEUE_SUSPEND , "%c%c%c%c%c%c%c%c is waiting for queue message!")
	TRC_MSG(SST_TASK_SEMAPHORE_SUSPEND , "%c%c%c%c%c%c%c%c is waiting for semaphore or mutex!")
	TRC_MSG(SST_TASK_ENH_MUTEX_SUSPEND , "%c%c%c%c%c%c%c%c is waiting for enh_mutex!")
	TRC_MSG(SST_TASK_EVENT_SUSPEND , "%c%c%c%c%c%c%c%c is waiting for event!")
	TRC_MSG(SST_TASK_PARTITION_SUSPEND , "%c%c%c%c%c%c%c%c is in waiting for available partitoned pool!")
	TRC_MSG(SST_TASK_FINISH, "%c%c%c%c%c%c%c%c is in finished state!")
	TRC_MSG(SST_TASK_TERMINATED, "%c%c%c%c%c%c%c%c is in terminated state!")
	TRC_MSG(SST_TASK_UNKOWN, "%c%c%c%c%c%c%c%c is in unknown state (%d)!")
