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
 *   SST_timer_trc.h
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
  
	/* Phase 1: Exception Message, grouped according to type */
	TRC_MSG(SST_PHASE1_601_01, "In kal_create_timer ( ), dynamic memory allocation failed for data type kal_timer_type.")
	TRC_MSG(SST_PHASE1_601_02, "In stack_create_timer ( ), dynamic memory allocation failed for data type stack_timer_struct.")
	TRC_MSG(SST_PHASE1_601_04, "In kal_create_timer ( ), dynamic debug memory allocation failed for kal_timer_stat_type.")
	TRC_MSG(SST_PHASE1_602_FF, "Create timer failed!")
	TRC_MSG(SST_PHASE1_604_01, "Hi dear, system fails to set a NULL timer pointer.")
	TRC_MSG(SST_PHASE1_604_02, "Hi dear, system fails to recover the clock at Timer HISR.")
	TRC_MSG(SST_PHASE1_604_FF, "In kal_set_timer (), timer reset is not success; please refer to timer control block if corruption.")
	TRC_MSG(SST_PHASE1_605_01, "Hi dear, system fails to cancel a NULL timer pointer.")
	TRC_MSG(SST_PHASE1_605_FF, "In kal_cancel_timer (), timer control block may be corrupted.")
	TRC_MSG(SST_PHASE1_609_26_, "In kal_set_timer (), timer disable failed, please refer to timer control block if corruption.")
	TRC_MSG(SST_PHASE1_60A_FF, "In kal_timer_routine_wraper (), timer hisr callback function 0x%08X executes too long.")
	TRC_MSG(SST_PHASE1_60B_FF, "System fails for timer hisr executes too long, and longest callback function ptr is 0x%08X.")
	
	
	/* Phase 2: Detailed analysis */
	TRC_MSG(SST_PHASE1_TIMER_FF_1, "Timer to be created is existed, could not duplicate it!")
	TRC_MSG(SST_PHASE1_TIMER_FF_2, "Timer control block is corrupted!")
	TRC_MSG(SST_PHASE2_60A_CALLBACK_EXECUTE_TIME_P11, "Callback execution time: %d, preempted time: %d")
	TRC_MSG(SST_PHASE2_60A_CALLBACK_EXECUTE_TIME_P12, "Callback execution time: %d")
	TRC_MSG(SST_PHASE2_60B_CALLBACK_EXECUTE_TIME_P1, "Callback execution time are as following (from latest to oldest):")
	TRC_MSG(SST_PHASE2_60B_CALLBACK_EXECUTE_TIME_P21, "Callback ptr: 0x%08X, execution time: %d, preempted time: %d")
	TRC_MSG(SST_PHASE2_60B_CALLBACK_EXECUTE_TIME_P22, "Callback ptr: 0x%08X, execution time: %d")

   /* Dump data structure */                   
	TRC_MSG(SST_TM_APP_TCB, "Content of timer control block as below:")
   TRC_MSG(SST_TM_APP_TCB_CREATED, "   tm_created : 0x%X")
   TRC_MSG(SST_TM_APP_TCB_ID, "   tm_id : 0x%X")
   TRC_MSG(SST_TM_APP_TCB_NAME, "   tm_name : %c%c%c%c%c%c%c%c")
   TRC_MSG(SST_TM_APP_TCB_FUNC, "   tm_expiration_routine : 0x%X")
   TRC_MSG(SST_TM_APP_TCB_EXP_ID, "   tm_expiration_id : %d")
   TRC_MSG(SST_TM_APP_TCB_ENABLED, "   tm_enabled : %d")
   TRC_MSG(SST_TM_APP_TCB_EXP_COUNT, "   tm_expirations : %d")
   TRC_MSG(SST_TM_APP_TCB_INIT_TIME, "   tm_initial_time : %d")
   TRC_MSG(SST_TM_APP_TCB_RESCHEDULE, "   tm_reschedule_time : %d")
   TRC_MSG(SST_TM_APP_TCB_ACTUAL_LIST, "   tm_actual_timer : 0x%X")
