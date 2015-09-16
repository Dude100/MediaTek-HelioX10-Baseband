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
 *   SST_buff_trc.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
  
   /* -------------------- Phase 1: Exception Message, grouped according to type ------------------------- */
   /* KAL_ERROR_BUFFMNGR_CREATE_FAILED */
   TRC_MSG(SST_PHASE1_800_01, "In kal_create_buff_pool( ) failed to create a partitioned memory pool with zero Bytes buffer entry.")
   TRC_MSG(SST_PHASE1_800_02, "In kal_create_buff_pool( ) failed to create a partitioned memory pool with zero entry. ")
   TRC_MSG(SST_PHASE1_800_03, "In kal_create_buff_pool( ) failed to add entry in pool_info_g[]. ")

   /* KAL_ERROR_BUFFMNGR_CREATE_MEMFAILED */
   TRC_MSG(SST_PHASE1_801_01, "In kal_create_buff_pool( ), dynamic memory allocation failed for data type kal_internal_poolid of a partitioned memory")
   TRC_MSG(SST_PHASE1_801_02, "In kal_create_buff_pool( ), dynamic memory allocation failed for data buffer of a partitioned memory")
   TRC_MSG(SST_PHASE1_801_03, "In kal_create_buff_pool( ), dynamic memory allocation failed for statistical pool of a partitioned memory.")
   TRC_MSG(SST_PHASE1_801_04, "In kal_create_buff_pool( ), failed to allocate  history buffer from debug memory.")   
   TRC_MSG(SST_PHASE1_801_08, "In kal_create_buff_pool( ), temporary memory allocation failed while initializing buffer header and footer.")
   
   /* KAL_ERROR_BUFFMNGR_GETBUFF_FAILED */
   TRC_MSG(SST_PHASE1_820_01, "In get_int_ctrl_buffer(), the buffer size to be allocated should not be zero.")
   TRC_MSG(SST_PHASE1_820_02, "In kal_get_buffer(), the filename of buffer allocator should not be NULL.")

   /* KAL_ERROR_BUFFMNGR_GETBUFF_POOLINDX_OUT_OF_RANGE */
   TRC_MSG(SST_PHASE1_821_SIZE, "In get_int_ctrl_buffer(), the desired buffer size is too large.")
   TRC_MSG(SST_PHASE1_821_01, "%c%c%c%c%c%c%c%c wanna get a large buffer with size =0x%X .")

   /* KAL_ERROR_BUFFMNGR_GETBUFF_POOL_NOT_EXIST */
   TRC_MSG(SST_PHASE1_822_SIZE, "In get_int_ctrl_buffer(), the pool ID of the desired buffer may be corrupted.")

   /* KAL_ERROR_BUFFMNGR_GETBUFF_NOT_AVAILABLE */
   TRC_MSG(SST_PHASE1_823_SIZE, "In kal_get_buffer(), buffer entries have been fully allocated, run-out of free space.")

   /* KAL_ERROR_BUFFMNGR_RELEASEBUFF_FAILED */
   TRC_MSG(SST_PHASE1_830_01, "In kal_release_buffer(), the filename of buffer allocator should not be NULL.")
   
   /* KAL_ERROR_BUFFMNGR_FOOTER_FAILED */
   TRC_MSG(SST_PHASE1_840_PTR_P1, "In kal_release_buffer(), it is detected that the buffer footer is corrupted, it is no longer ((buff_number << 16) | 0xF2F2).")
   
   /* KAL_ERROR_BUFFMNGR_HEADER_FAILED */
   TRC_MSG(SST_PHASE1_841_PTR, "In kal_release_buffer(), it is detected that buffer header is corrupted, it is no longer 0xF1F1F1F1.")
   
   /* KAL_ERROR_BUFFMNGR_FOOTER_FAILED_GET */
   TRC_MSG(SST_PHASE1_842_PTR_P1, "In kal_get_buffer(), it is detected that buffer footer is no longer ((buff_number << 16) | 0xF2F2). It was previously")
   TRC_MSG(SST_PHASE1_842_PTR_P2, "successfully released and is now regarded as free entry.  It may be corrupted during the free period.")
   
   /* KAL_ERROR_BUFFMNGR_HEADER_FAILED_GET */
   TRC_MSG(SST_PHASE1_843_PTR_P1, "In kal_get_buffer(), it is detected that buffer header is no longer 0xF1F1F1F1. It was previously ")
   TRC_MSG(SST_PHASE1_843_PTR_P2, "successfully released and is now regarded as free entry.  It may be corrupted during the free period.")
   
   /* KAL_ERROR_BUFFMNGR_EXT_FOOTER_FAILED */
   TRC_MSG(SST_PHASE1_844_PTR_P1, "In kal_release_buffer(), it is detected that the extended buffer footer is corrupted ")
   TRC_MSG(SST_PHASE1_844_PTR_P2, "(appended at end of buffer size being requested), it is no longer 0xF2F2F2F2.")
   
   /* KAL_ERROR_BUFFMNGR_GETBUFF_NILPTR */
   TRC_MSG(SST_PHASE1_852_01, "%c%c%c%c%c%c%c%c gets a buffer by a NULL pointer along the call path.")
   
   /* KAL_ERROR_BUFFMNGR_RELEASEBUFF_NILPTR */
   TRC_MSG(SST_PHASE1_853_01, "%c%c%c%c%c%c%c%c releases a buffer by a NULL pointer along the call path.")
   
   /* KAL_ERROR_BUFFMNGR_ISVALID_FAILED */
   TRC_MSG(SST_PHASE1_880_PTR_P1, "In kal_release_buffer(), buffer pointer to be released belongs to neither of the partitioned memory pool,")
   TRC_MSG(SST_PHASE1_880_PTR_P2, "indexed by pool ID retrieved from KAL header or by address range.")
   
   /* KAL_ERROR_BUFFMNGR_POSSIBLE_LEAKAGE */
   TRC_MSG(SST_PHASE1_882_PTR_P0, "control buffer possible leakage, file name ptr=0x%X,\n")
   TRC_MSG(SST_PHASE1_882_PTR_P1, "                  owner_task = %c%c%c%c%c%c, module_id =%d, file_name =%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c")
   TRC_MSG(SST_PHASE1_882_PTR_P2, "                , user_ptr =0x%X, line =%d, size=%d, allocate_time=%d")
   TRC_MSG(SST_PHASE1_882_PTR_P3, "possible leakage: ")
   TRC_MSG(SST_PHASE1_882_PTR_P4, "whitelist in-used buffer: ")

   /* KAL_ERROR_BUFFMNGR_CREATE_INTERNAL_FAILED */
   TRC_MSG(SST_PHASE1_890_01, "In kal_create_buff_pool( ), NU_Create_Partition_Pool() does not return NU_SUCCESS.")
   
   /* KAL_ERROR_BUFFMNGR_GETBUFF_INTERNAL_FAILED */
   TRC_MSG(SST_PHASE1_892_01, "In kal_create_buff_pool()/kal_get_buffer, NU_Allocate_Partition() does not return NU_SUCCESS.")
   
   /* KAL_ERROR_BUFFMNGR_RELEASEBUFF_INTERNAL_FAILED (double free) */
   TRC_MSG(SST_PHASE1_893_PTR, "a de-allocated, corrupted or illegal pointer in kal_release_buffer()")
   
   /* -------------------- Phase 2: Detailed analysis ------------------------- */
   TRC_MSG(SST_PHASE2_BUFF_UNKNOWN, "It may be a corrupted or illegal pointer!")
   TRC_MSG(SST_PHASE2_NOT_MONITOR, "Control buffer is not monitored!")
   TRC_MSG(SST_PHASE2_NOT_ALIGNMENT, "User is processing with  a non-alignment %dB buffer pointer, it is absolutely prohibited")
   TRC_MSG(SST_PHASE2_INVALID_POINTER, "User is providing an illegal pointer 0x%08X, which is absolutely prohibited!")
   TRC_MSG(SST_PHASE2_POOL_INFO_G_CORRUPTED, "Data structure pool_info_g corrupted!")
   TRC_MSG(SST_PHASE2_BUFFER_CORRUPT_REASONS, "Buffer mya be corrupted by the owner of current, previous or next buffer entry!")
  
   /* KAL_ERROR_BUFFMNGR_CREATE_FAILED */
   TRC_MSG(SST_PHASE2_800_OVERFLOW, "Partitioned memory pool runs out of free space!")
   
   /* KAL_ERROR_BUFFMNGR_GETBUFF_NOT_AVAILABLE */
   TRC_MSG(SST_PHASE2_823_SIZE_NOT_MONITOR_P1, "My dear, buffer monitoring is not turned on at size %d,")
   TRC_MSG(SST_PHASE2_823_SIZE_NOT_MONITOR_P2, "system has no idea about history on buffer transaction!")
   TRC_MSG(SST_PHASE2_823_SIZE_MONITOR_P1, "There are totally %d entries at control buffer size %d (Bytes).")
   TRC_MSG(SST_PHASE2_823_SIZE_MONITOR_P2, "Owners distribution as below:")
   TRC_MSG(SST_PHASE2_823_SIZE_MONITOR_P3, "%c%c%c%c%c%c%c%c: Allocate %d entries at %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c line %d")
   TRC_MSG(SST_PHASE2_823_SIZE_MONITOR_P4, "Caller Address: 0x%08X Allocate %d entries")
   
   /* KAL_ERROR_BUFFMNGR_FOOTER_FAILED */   
   TRC_MSG(SST_PHASE2_840_PTR, "Please refer to buffer header listed above, KAL footer 0xF2F2F2F2 is missing!")
   
   /* KAL_ERROR_BUFFMNGR_HEADER_FAILED */   
   TRC_MSG(SST_PHASE2_841_PTR, "Please refer to buffer header listed above, KAL header 0xF1F1F1F1 is missing!")
   
   /* KAL_ERROR_BUFFMNGR_EXT_FOOTER_FAILED */   
   TRC_MSG(SST_PHASE2_844_PTR, "Please refer to buffer header listed above, KAL extended footer corrupted!")
   
   /* KAL_ERROR_BUFFMNGR_ISVALID_FAILED */
   TRC_MSG(SST_PHASE2_880_PTR, "Please refer to buffer header listed above, KAL header pool ID corrupted!")
   
   /* KAL_ERROR_BUFFMNGR_RELEASEBUFF_INTERNAL_FAILED */
   TRC_MSG(SST_PHASE2_893_PTR_MONITOR_P1, "Task %c%c%c%c%c%c%c%c is releasing a %dB buffer pointer 0x%X from file %c%c%c%c%c%c%c%c%c%c%c%c")
   TRC_MSG(SST_PHASE2_893_PTR_MONITOR_P2, "line %d, but it had been deallocated!")
   TRC_MSG(SST_PHASE2_893_PTR_MONITOR_P3, "Please refer to history records for more detailed!")
   TRC_MSG(SST_PHASE2_893_PTR_UNMONITOR_P1, "Task %c%c%c%c%c%c%c%c is releasing a %dB buffer pointer 0x%X,")
   TRC_MSG(SST_PHASE2_893_PTR_UNMONITOR_P2, "but it had been deallocated!")
   
    /* -------------------- Phase 3: Guideline ------------------------- */
   TRC_MSG(SST_PHASE3_823_SIZE_NOT_MONITOR_P1, "Please turn on buffer monitoring and reproduce again!")
   TRC_MSG(SST_PHASE3_823_SIZE_NOT_MONITOR_P2, "Input string *035670766*001*65535# via MMI; as long as")
   TRC_MSG(SST_PHASE3_823_SIZE_NOT_MONITOR_P3, "the value won't be saved to NVRAM, re-input is required")
   TRC_MSG(SST_PHASE3_823_SIZE_NOT_MONITOR_P4, "each time power-on!")

   
   /* Dump data structure */                    
   /* Control block of a partitioned pool */
   TRC_MSG(SST_PM_PCB, "Full content of partitioned memory control block as below:")
	TRC_MSG(SST_PM_PCB_CREATED, "   pm_created : 0x%08X")
	TRC_MSG(SST_PM_PCB_ID, "   pm_id : 0x%08X")
	TRC_MSG(SST_PM_PCB_NAME, "   pm_name : %c%c%c%c%c%c%c%c")
	TRC_MSG(SST_PM_PCB_START_ADDR, "   pm_start_address : 0x%08X")
	TRC_MSG(SST_PM_PCB_POOL_SIZE, "   pm_pool_size : %d")
	TRC_MSG(SST_PM_PCB_PART_SIZE, "   pm_partition_size : %d")
	TRC_MSG(SST_PM_PCB_AVAIL, "   pm_available : %d")
	TRC_MSG(SST_PM_PCB_ALLOCATED, "   pm_allocated : %d")
	TRC_MSG(SST_PM_PCB_AVAIL_LIST, "   pm_available_list : 0x%08X")
	TRC_MSG(SST_PM_PCB_FIFO_SUSPEND, "   pm_fifo_suspend : 0x%08X")
	TRC_MSG(SST_PM_PCB_TASK_WAIT, "   pm_tasks_waiting : 0x%08X")
	TRC_MSG(SST_PM_PCB_SUSP_LIST, "   pm_suspension_list : 0x%08X")
	
	
	/* History record of certain buffer entry */
	TRC_MSG(SST_HISTORY, "Complete history nodes of current buffer pointer [%d]:")
	TRC_MSG(SST_HISTORY_STATE, "   buffer_state : %Mkal_buff_state")
	TRC_MSG(SST_HISTORY_TASK, "   owner_task : %c%c%c%c%c%c%c%c")
	TRC_MSG(SST_HISTORY_FILE, "   file_name : %c%c%c%c%c%c%c%c%c%c%c%c")
	TRC_MSG(SST_HISTORY_LINE, "   line : %d")
	TRC_MSG(SST_HISTORY_SIZE, "   size : %d")
	TRC_MSG(SST_HISTORY_LR, "Buffer Allocator Caller Address : 0x%08X")
	
	
	/* Buffer header */
	TRC_MSG(SST_CURRENT_BUFFER_HEADER, "Header and footer of current buffer pointer as below :")
	TRC_MSG(SST_PREV_BUFFER_HEADER, "Header and footer of previous buffer pointer as below :")
	TRC_MSG(SST_NEXT_BUFFER_HEADER, "Header and footer of next buffer pointer as below :")

	TRC_MSG(SST_BUFFER_HEADER_RTOS1, "    RTOS header 1 = 0x%08X")
	TRC_MSG(SST_BUFFER_HEADER_RTOS2, "    RTOS header 2 = 0x%08X")
	TRC_MSG(SST_BUFFER_HEADER_KAL1, "    KAL header 1 (0xF1F1F1F1 originaly) = 0x%08X")
	TRC_MSG(SST_BUFFER_HEADER_KAL2, "    KAL header 2 (task ID) = 0x%08X")
	TRC_MSG(SST_BUFFER_FOOTER_KAL_EXT, "    KAL extended footer (0xF2F2F2F2 if monitoring) = 0x%02X%02X%02X%02X")
	TRC_MSG(SST_BUFFER_FOOTER_KAL_EXT_UNKNOWN, "    KAL extended footer (0xF2F2F2F2 if monitoring) : unknown")
	TRC_MSG(SST_BUFFER_FOOTER_KAL2, "    KAL footer (0xF2F2F2F2 originally) = 0x%08X")
	

	/* Content of pool_info_g */
	TRC_MSG(SST_POOL_INFO_G, "Full content of pool_info_g as below:")
	TRC_MSG(SST_POOL_INFO_G_NO, "   pool_info_g[%d]")
	TRC_MSG(SST_POOL_INFO_G_ID, "      pool_id : 0x%08X")
	TRC_MSG(SST_POOL_INFO_G_START, "      start_address : 0x%08X")
	TRC_MSG(SST_POOL_INFO_G_END, "      end_address : 0x%08X")
