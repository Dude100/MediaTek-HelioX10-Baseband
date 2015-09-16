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
 *   SST_misc_trc.h
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
   TRC_MSG(SST_PHASE1_c01_00, "In kal_evshed_create_pool(), malloc failed for total memory required by evshed pool.")
   TRC_MSG(SST_PHASE1_c01_01, "In evshed_create(), malloc failed for a stack timer required by an event scheduler.")
   TRC_MSG(SST_PHASE1_c01_02, "In evshed_create(), malloc failed for an event scheduler.")
   TRC_MSG(SST_PHASE1_c01_03, "In evshed_enable_protect_property(), malloc failed for an event scheduler protect.")
   TRC_MSG(SST_PHASE1_c02_FF, "In kal_evshed_create_pool(), system fails to create partitioned-memory pool for an event scheduler.")
   TRC_MSG(SST_PHASE1_c03_00, "In kal_evshed_get_mem(), memory size being requested is larger than partitioned size.")
   TRC_MSG(SST_PHASE1_c03_FF, "In kal_evshed_get_mem(), system fails to get buffer from evshed_pool_id")
   TRC_MSG(SST_PHASE1_c04_FF, "In kal_evshed_free_mem(), system fails to free buffer to evshed_pool_id, ptr=0x%X.")
   TRC_MSG(SST_PHASE1_c05_ID, "In evshed_cancel_event(), canceling event scheduler owned by others is absolutely prohibited, eventid=0x%X.")
   TRC_MSG(SST_PHASE1_c06_FF, "In evshed_cancel_event(), parameter eventid is a null pointer.")

   TRC_MSG(SST_PHASE1_b02, "Dividend is zero now!")
   TRC_MSG(SST_PHASE1_b03, "Oh No! Software abnormal reset is encountered.")
   TRC_MSG(SST_PHASE1_b04, "MCU is now servicing an unregistered IRQ.")
   TRC_MSG(SST_PHASE1_b31, "IRQ is disabled over 60 QBs !")
   
   TRC_MSG(SST_PHASE1_1501, "Customer had defined %d task IDs, violates the default value %d!")
   TRC_MSG(SST_PHASE1_1502, "Customer had defined %d module IDs, violates the default value %d!")
   TRC_MSG(SST_PHASE1_1503, "Customer had defined %d message IDs, violates the default value %d!")
   TRC_MSG(SST_PHASE1_1504, "Customer had defined %d SAP IDs, violates the default value %d!")
   
   
   /* Phase 2: Detailed analysis */
   TRC_MSG(SST_PHASE1_b04_OutOfRange, "IRQ number being serviced is out of range; it is an illegal IRQ!")
   TRC_MSG(SST_PHASE1_b04_NOT_REG, "IRQ number %d is an un-registered interrupt!")
   TRC_MSG(SST_PHASE1_b04_MEMORY_CORRUPTION, "Memory corruption at lisr_dispatch_tbl[%d]!")
   
   TRC_MSG(SST_PHASE2_b04_LISR_DISPATCH_TBL, "Content of lisr_dispatch_tbl[%d]:")
   TRC_MSG(SST_PHASE2_b04_LISR_DISPATCH_TBL_V, "   lisr_dispatch_tbl.vector : %d")
   TRC_MSG(SST_PHASE2_b04_LISR_DISPATCH_TBL_H, "   lisr_dispatch_tbl.lisr_handler : 0x%X")
   TRC_MSG(SST_PHASE2_b04_LISR_DISPATCH_TBL_D, "   lisr_dispatch_tbl.description : %c%c%c%c%c%c%c%c")
   TRC_MSG(SST_PHASE2_c03_POOL_MONITOR_P1, "There are totally %d entries with event scheduler buffer size %d (Bytes).")
   TRC_MSG(SST_PHASE2_c03_POOL_MONITOR_P2, "Owners distribution as below:")
   TRC_MSG(SST_PHASE2_c03_POOL_MONITOR_P3, "There are %d events which handler func addr is 0x%08X in event scheduler %c%c%c%c%c%c%c%c")
   TRC_MSG(SST_PHASE2_c03_POOL_MONITOR_P4, "which dest module is %Mmodule_type (task: %c%c%c%c%c%c%c%c).")
   TRC_MSG(SST_PHASE1_b31_irq_disabled_duration, "IRQ is disabled %d QBs: locked by caller address 0x%08X, unlocked by caller address 0x%08X!!")
