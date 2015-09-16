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
 *   SST_common_trc.h
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
  
	/* Common information */
	TRC_MSG(SST_NEWLINE, "")
	TRC_MSG(SST_NO, "[%d]:")
	TRC_MSG(SST_4_HEX_VALUES, "0x%X << 0x%X << 0x%X << 0x%X <<")
	TRC_MSG(SST_3_HEX_VALUES, "0x%X << 0x%X << 0x%X")
	TRC_MSG(SST_2_HEX_VALUES, "0x%X << 0x%X")
	TRC_MSG(SST_1_HEX_VALUES, "0x%X")
	TRC_MSG(SST_NAME, "%c%c%c%c%c%c%c%c")
	
	TRC_MSG(SST_TITLE1, "System Stability Tracker (SST) V0.00 ")
	TRC_MSG(SST_TITLE2, "=====================================")	
	
	TRC_MSG(SST_ENDING1, "End of SST!")
	TRC_MSG(SST_ENDING2, "============!!!!!!!!!!!!")
	
	TRC_MSG(SST_DESCRIPTION, "<<Descriptions>>")
   
	TRC_MSG(SST_BOOTMODE_FACTORY_BOOT, "Oh dear! system exception under META/FACTORY mode,")
	TRC_MSG(SST_BOOTMODE_NORMAL, "Oh dear! system exception under NORMAL mode,")
	TRC_MSG(SST_BOOTMODE_USBMS_BOOT, "Oh dear! system exception under USB BOOT mode,")
	
	TRC_MSG(SST_RUNNING_TASK, "while processing TASK %c%c%c%c%c%c%c%c")
	TRC_MSG(SST_RUNNING_HISR, "while processing HISR %c%c%c%c%c%c%c%c")
	TRC_MSG(SST_RUNNING_LISR, "while processing LISR %%MLISR_IRQ_NO")
	TRC_MSG(SST_RUNNING_INITIAL, "while in initial stage.")
	TRC_MSG(SST_RUNNING_UNKNOWN, "at the mean time, system is processing neither task, HISR nor LISR, unknown state!")

	TRC_MSG(SST_EXCEPTION_ANALYSIS, "<<Detailed Information and Analysis>>")
	TRC_MSG(SST_EXCEPTION_GUIDELINE, "<<Guideline>>")
	
	TRC_MSG(SST_MEMORY_CORRUPTION, "Memory corruption!")
	TRC_MSG(SST_LOOKS_GOOD, "Everything looks good!")

	TRC_MSG(SST_CPU_EXCEPTIONS, "This is the CPU triggered exception, type %Mexception_type!")
   
	/* Phase 1: Exception Message grouped according to type */
	TRC_MSG(SST_PHASE1_UNDEFINED, "Error code 0x%X and 0x%X are not defined in SST engine, Quit the SST engine. Bye-bye!")
	TRC_MSG(SST_PHASE1_CONSTRUCTION, "Error code 0x%X and 0x%X are under construction now! Quit the SST engine. Bye-bye!")
	TRC_MSG(SST_PHASE1_UNDEFINED_ERROR_CODE, "Undefined fatal error code of class %c%c%c%c%c, error code 1=0x%X, error code 2=0x%X")

	/* Phase 2: Analysis */
	TRC_MSG(SST_DUMP_STACK, "Active call path from given stack pointer (0x%X) as above.")
	TRC_MSG(SST_DUMP_PROBLEM_STACK, "Call path of problematic task %c%c%c%c%c%c%c%c as below.")
	TRC_MSG(SST_DUMP_STACK_FAILED, "No reasonable call path retreivable from given stack pointer!")
	TRC_MSG(SST_IRREGULAR_STACK_POINTER, "The stack pointer was out of bounded range!") 
	TRC_MSG(SST_IRREGULAR_STACK_POINTER_PRINT, "SST sp(0x%X) sp_start(0x%X) sp_end(0x%X)!") 
	TRC_MSG(SST_SUSPEND_DISALLOWED_P1, "Not allowed to suspend because of no active task")
	TRC_MSG(SST_REFER_TO_ERROR_CODE, "Error code returned by NUCLEUS PLUS %d")
	TRC_MSG(SST_DUMP_RECEIVER_STACK, "Call path of receiver task as below.")
	TRC_MSG(SST_DUMP_SENDER_STACK, "Call path of sender task %c%c%c%c%c%c%c%c as below.")

	/* Phase 3: Guideline and follow-ups grouped according to type */
	TRC_MSG(SST_PHASE3_JTAG_WB, "Please reproduce on JTAG, and set the write breakpoint at address 0x%X.")
	TRC_MSG(SST_PHASE3_JTAG_WBS, "Please reproduce on JTAG, and set the write breakpoint at any of the above error addresses!")
	TRC_MSG(SST_PHASE3_OWNER, "Please contact people in-charge of %c%c%c%c%c%c%c%c to resolve the problem!")
	TRC_MSG(SST_PHASE3_OWNER_MSGID, "Please contact people in-charge of %Mmsg_type to resolve the problem!")
	TRC_MSG(SST_PHASE3_OWNER_MOD, "Please contact people in-charge of %c%c%c%c%c%c%c%c module %Mmodule_type to resolve the problem!")
	TRC_MSG(SST_PHASE3_OWNER_FILE, "Please contact people in-charge of file %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c to resolve the problem!")
	TRC_MSG(SST_PHASE3_OWNER_LR, "Please contact people in-charge of caller address 0x%08X to resolve the problem!")
	TRC_MSG(SST_PHASE3_OWNER_TASK, "Please contact people in-charge of task %c%c%c%c%c%c%c%c to resolve the problem!")
	TRC_MSG(SST_PHASE3_MAKE_SURE, "Please contact owner of %c%c%c%c%c%c%c%c to make sure the procedure is correct!")
	TRC_MSG(SST_PHASE3_CALL_SST, "Please dump memory and let system service member to give you a hand!")
	TRC_MSG(SST_PHASE3_DUMP_MEMORY, "Serious error, please dump memory and let system service member to give you a hand!")
	TRC_MSG(SST_PHASE3_DUMP_MEMORY_PR, "Serious error, please dump memory!")
	TRC_MSG(SST_PHASE3_REMIND_DUMP_MEMORY, "Remember to dump memory!")
	TRC_MSG(SST_PHASE3_FOLLOW_RULE_CUSTOMIZATION, "Please stricly follow the rule for customization!")
	TRC_MSG(SST_PHASE3_SENDER_IS_OFFENDER, "Sender is offender, please saw above call path!")

	
	/* Dump Data Structure */
	
	/* TASK_INFO_G */
	TRC_MSG(SST_PHASE2_TASK_INFO, "Content of task_info_g[%03d] as below:")
	TRC_MSG(SST_PHASE2_TASK_INFO_G1, "       task_name_ptr = %c%c%c%c%c%c")
	TRC_MSG(SST_PHASE2_TASK_INFO_G2, "       task_qname_ptr = %c%c%c%c%c%c")
	TRC_MSG(SST_PHASE2_TASK_INFO_G3, "       task_priority = %d")
	TRC_MSG(SST_PHASE2_TASK_INFO_G4, "       task_stack_size = %d")
	TRC_MSG(SST_PHASE2_TASK_INFO_G5, "       task_entry_func = 0x%X")
	TRC_MSG(SST_PHASE2_TASK_INFO_G6, "       task_ext_qsize = %d")
	TRC_MSG(SST_PHASE2_TASK_INFO_G7, "       task_int_qsize = %d")
	TRC_MSG(SST_PHASE2_TASK_INFO_G8_1, "       task_internal_ram_stack = KAL_TRUE")
	TRC_MSG(SST_PHASE2_TASK_INFO_G8_2, "       task_internal_ram_stack = KAL_FALSE")
	TRC_MSG(SST_PHASE2_TASK_INFO_G9, "       task_id = 0x%X")
	TRC_MSG(SST_PHASE2_TASK_INFO_G10, "      task_ext_qid = 0x%X")
	TRC_MSG(SST_PHASE2_TASK_INFO_G11, "      task_int_qid_ptr = 0x%X")
	
	TRC_MSG(SST_PHASE2_TASK_INFO_STACK_ERROR, "       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Error (Address=0x%X)! Should not be 0!")
	TRC_MSG(SST_PHASE2_TASK_INFO_ENTRY_ERROR, "       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Error (Address=0x%X)! Should not be NULL!")

	
	/* ILM_STRUCT */
	TRC_MSG(SST_ILM_STRUCT, "Content of ILM structure relative to %Mmodule_type as below")
	TRC_MSG(SST_ILM_STRUCT_SOURCE, "   src_mod_id: %Mmodule_type")
	TRC_MSG(SST_ILM_STRUCT_DESTINATION, "   dest_mod_id: %Mmodule_type")
	TRC_MSG(SST_ILM_STRUCT_SAP, "   sap_id: %Msap_type")
	TRC_MSG(SST_ILM_STRUCT_MESSID, "   msg_id: %Mmsg_type")
	TRC_MSG(SST_ILM_STRUCT_LOCAL, "   local_para_ptr: 0x%X")
	TRC_MSG(SST_ILM_STRUCT_PEER, "   peer_buff_ptr: 0x%X")
