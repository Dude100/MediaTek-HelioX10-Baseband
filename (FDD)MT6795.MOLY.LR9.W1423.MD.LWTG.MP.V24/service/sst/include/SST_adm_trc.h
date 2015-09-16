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
 *   SST_adm_trc.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
  
   /* -------------------- Phase 1: Exception Message, grouped according to type ------------------------- */
   /* KAL_ERROR_ADM_CREATE_FAILED */
   TRC_MSG(SST_PHASE1_1700_01, "In kal_adm_create2(), the given flag set is invalid.")
   TRC_MSG(SST_PHASE1_1700_02, "In kal_adm_create2(), the given sub-pool size array is invalid.")

   /* KAL_ERROR_ADM_DELETE_FAILED */
   TRC_MSG(SST_PHASE1_1710_01, "In kal_adm_delete(), the ADM pool to be deleted is invalid: the ADM pool is set as clean deletion, and there are still occupied ADM buffer.")
      
   /* KAL_ERROR_ADM_ALLOC_FAILED */
   TRC_MSG(SST_PHASE1_1720_01, "In __kal_adm_alloc(), allocation failed because there is no enough MTK cache channel.")
   TRC_MSG(SST_PHASE1_1720_04, "In __kal_adm_alloc_core(), allocation failed because the given alignment value is not 4B aligned.")

   /* KAL_ERROR_ADM_ALLOC_DYNCACHE_FAILED */
   TRC_MSG(SST_PHASE1_1726_01, "In __kal_adm_alloc_c(), allocation failed because the ADM pool is not cacheability switchable.")
   TRC_MSG(SST_PHASE1_1726_02, "In __kal_adm_alloc_nc(), allocation failed because the ADM pool is not cacheability switchable.")
   
   /* KAL_ERROR_ADM_REALLOC_FAILED */
   TRC_MSG(SST_PHASE1_172C_01, "In __kal_adm_realloc(), re-allocation failed and the flag indicating fatal is set.")
   TRC_MSG(SST_PHASE1_172C_04, "In __kal_adm_realloc(), re-allocation failed because the given alignment is not 4B aligned.")

   /* KAL_ERROR_ADM_FREE_FAILED */
   TRC_MSG(SST_PHASE1_1730_01, "In __kal_adm_free(), de-allocation failed because the memory block to be freed does not belong to the ADM pool.")
   TRC_MSG(SST_PHASE1_1730_02, "In __kal_adm_free(), de-allocation failed because prev or next pointers of the memory block to be freed is invalid; corruption may occurs.")

   /* KAL_ERROR_ADM_FREE_DOUBLEFREE */
   TRC_MSG(SST_PHASE1_1732_ADDR, "In __kal_adm_free(), de-allocation failed because the given memory block is freed before; it's a double free problem.")

   /* KAL_ERROR_ADM_FOOTER_FAILED */
   TRC_MSG(SST_PHASE1_1740_ADDR, "In __kal_adm_free(), de-allocation failed because the footer stamp of the memory block to be freed is corrupted.")

   /* KAL_ERROR_ADM_HEADER_FAILED */
   TRC_MSG(SST_PHASE1_1741_ADDR, "In __kal_adm_free(), de-allocation failed because the header stamp of the memory block to be freed is corrupted.")

   /* KAL_ERROR_ADM_NILPTR */
   TRC_MSG(SST_PHASE1_1750_00, "The given ADM control block pointer is NULL.")

   /* KAL_ERROR_ADM_DELETE_NILPTR */
   TRC_MSG(SST_PHASE1_1751_00, "In __kal_adm_delete(), the given ADM control block pointer is NULL.")

   /* KAL_ERROR_ADM_ALLOC_NILPTR */
   TRC_MSG(SST_PHASE1_1752_00, "In __kal_adm_alloc_core(), the given ADM control block pointer is NULL.")

   /* KAL_ERROR_ADM_FREE_NILPTR */
   TRC_MSG(SST_PHASE1_1753_00, "In __kal_adm_free(),the given ADM control block pointer is NULL.")

   /* KAL_ERROR_ADM_REALLOC_NILPTR */
   TRC_MSG(SST_PHASE1_1754_00, "In __kal_adm_realloc(), the given ADM control block pointer is NULL.")

   /* KAL_ERROR_ADM_BADID */
   TRC_MSG(SST_PHASE1_1760_ID, "The ADM ID of the given ADM control block is not valid (0x20101027).")

   /* KAL_ERROR_ADM_DELETE_BADID */
   TRC_MSG(SST_PHASE1_1761_ID, "In __kal_adm_delete(), the ADM ID of the given ADM control block is not valid (0x20101027).")

   /* KAL_ERROR_ADM_ALLOC_BADID */
   TRC_MSG(SST_PHASE1_1762_ID, "In __kal_adm_alloc_core(), the ADM ID of the given ADM control block is not valid (0x20101027).")

   /* KAL_ERROR_ADM_FREE_BADID */
   TRC_MSG(SST_PHASE1_1763_ID, "In __kal_adm_free (), the ADM ID of the given ADM control block is not valid (0x20101027).")

   /* KAL_ERROR_ADM_REALLOC_BADID */
   TRC_MSG(SST_PHASE1_1764_ID, "In __kal_adm_realloc (), the ADM ID of the given ADM control block is not valid (0x20101027).")

   /* KAL_ERROR_ADM_CONCURRENT_OPERATION */
   TRC_MSG(SST_PHASE1_1770_TASK, "Fatal occurs because somebody is using the ADM pool at the same time; concurrency usage is forbidden.")

   /* KAL_ERROR_ADM_BADPTR */
   TRC_MSG(SST_PHASE1_1771_PTR, "In kal_adm_get_prev_block_ptr()/kal_adm_get_next_block_ptr(), the given ADM buffer pointer is not inside the ADM pool.")

   /* KAL_ERROR_ADM_GETEXTHEADER_FAILED */
   TRC_MSG(SST_PHASE1_1781_ADDR, "In kal_adm_get_extheader(), it failed to get ext-header because the ADM pool is not configured as ext-header embedded.")
   
   /* ------------------- Phase 2: Detailed analysis (N/A) -------------------- */
   
   /* -------------------- Phase 3: Guideline ------------------------- */
   /* KAL_ERROR_ADM_CREATE_FAILED */
   TRC_MSG(SST_PHASE3_1700_01, "Invalidate flags in kal_adm_create2, please use KAL_ADM_*_FLAG")
   TRC_MSG(SST_PHASE3_1700_02_P1, "The subpool_size in kal_adm_create/kal_adm_create2 is invalid.")
   TRC_MSG(SST_PHASE3_1700_02_P2, "Please check if it is NULL, or the elemnts are monotone increasing and end with {0xffffffff, 0}")

   /* KAL_ERROR_ADM_DELETE_FAILED */
   TRC_MSG(SST_PHASE3_1710_01, "Some buffers in the ADM pool are not freed when deleting ADM.")
      
   /* KAL_ERROR_ADM_ALLOC_FAILED */
   TRC_MSG(SST_PHASE3_1720_01_P1, "There's insufficient MTKL1Cache channle for cache memory setting.")
   TRC_MSG(SST_PHASE3_1720_01_P2, "Please check no memory leakage for MTKL1Cache buffer.")
   TRC_MSG(SST_PHASE3_1720_04, "Alignment is not a multiple of 4, and please check your alignment requirement.")

   /* KAL_ERROR_ADM_ALLOC_DYNCACHE_FAILED */
   TRC_MSG(SST_PHASE3_1726_01_P1, "The ADM pool is non-cacheable by default and its cacheability is not dynamic switchable.")
   TRC_MSG(SST_PHASE3_1726_01_P2, "You cannot allocate a cacheable buffer from it. ")
   TRC_MSG(SST_PHASE3_1726_02_P1, "The ADM pool is cacheable default and its cacheability is not dynamic switchable.")
   TRC_MSG(SST_PHASE3_1726_02_P2, "You cannot allocate a non-cacheable buffer from it. ")
   
   /* KAL_ERROR_ADM_REALLOC_FAILED */
   TRC_MSG(SST_PHASE3_172C_01_P1, "It's unable realloc new memory block for data.")
   TRC_MSG(SST_PHASE3_172C_01_P2, "The behavior is controlled by KAL_ADM_REALLOCFAIL_FATAL_FLAG specified on kal_adm_create2.")
   TRC_MSG(SST_PHASE3_172C_01_P3, "Please ensure you have enough memory when realloc new memory block,")
   TRC_MSG(SST_PHASE3_172C_01_P4, "maybe you need to read ADM_public_api.ppt about how to handle realloc failure")   
   TRC_MSG(SST_PHASE3_172C_04, "Alignment is not a multiple of 4, and please check your alignment requirement.")

   /* KAL_ERROR_ADM_FREE_FAILED */
   TRC_MSG(SST_PHASE3_1730_01_P1, "In kal_adm_free(this_adm, ptr), the ptr is not in the range of this_adm pool.")
   TRC_MSG(SST_PHASE3_1730_01_P2, "Please check your input.")
   TRC_MSG(SST_PHASE3_1730_02_P1, "In kal_adm_free(this_adm, ptr), the ADM internal header previous to ptr is corrupted.")
   TRC_MSG(SST_PHASE3_1730_02_P2, "Please check memory blocks around it, especially the previous one.")

   /* KAL_ERROR_ADM_FREE_DOUBLEFREE */
   TRC_MSG(SST_PHASE3_1732_ADDR, "Double free, or dangling pointer? Please check the last free.")

   /* KAL_ERROR_ADM_FOOTER_FAILED */
   TRC_MSG(SST_PHASE3_1740_ADDR_P1, "In kal_adm_free(this_adm, ptr), the footer guard pattern is corrupted.")
   TRC_MSG(SST_PHASE3_1740_ADDR_P2, "Please check memory blocks around it, especially the previous one.")   

   /* KAL_ERROR_ADM_HEADER_FAILED */
   TRC_MSG(SST_PHASE3_1741_ADDR_P1, "In kal_adm_free(this_adm, ptr), the header guard pattern is corrupted.")
   TRC_MSG(SST_PHASE3_1741_ADDR_P2, "Please check memory blocks around, especially the previous block.")

   /* KAL_ERROR_ADM_NILPTR */
   TRC_MSG(SST_PHASE3_1750_00, "You past a NULL ADM ID to ADM functions. Please check your input.")

   /* KAL_ERROR_ADM_DELETE_NILPTR */
   TRC_MSG(SST_PHASE3_1751_00, "You past a NULL ADM ID to kal_adm_delete. Please check your input.")

   /* KAL_ERROR_ADM_ALLOC_NILPTR */
   TRC_MSG(SST_PHASE3_1752_00, "You past a NULL ADM ID to kal_adm_alloc_*. Please check your input.")

   /* KAL_ERROR_ADM_FREE_NILPTR */
   TRC_MSG(SST_PHASE3_1753_00, "You past a NULL ADM ID to kal_adm_realloc. Please check your input.")

   /* KAL_ERROR_ADM_REALLOC_NILPTR */
   TRC_MSG(SST_PHASE3_1754_00, "You past a NULL ADM ID to ADM functions. Please check your input.")

   /* KAL_ERROR_ADM_BADID */
   TRC_MSG(SST_PHASE3_1760_ID_P1, "No signature is found; the first word pointed by ADM ID should be 0x20101027.")
   TRC_MSG(SST_PHASE3_1760_ID_P2, "Please check whether the pointer is valid or corrupted")

   /* KAL_ERROR_ADM_DELETE_BADID */
   TRC_MSG(SST_PHASE3_1761_ID_P1, "No signature is found in kal_adm_delete(); the first word pointed by ADM ID should be 0x20101027, ")
   TRC_MSG(SST_PHASE3_1761_ID_P2, "but now it is 0x%X. Please check whether the pointer is valid or corrupted")

   /* KAL_ERROR_ADM_ALLOC_BADID */
   TRC_MSG(SST_PHASE3_1762_ID_P1, "No signature is found in kal_adm_alloc_*(); the first word pointed by ADM ID should be 0x20101027, ")
   TRC_MSG(SST_PHASE3_1762_ID_P2, "but now it is 0x%X. Please check whether the pointer is valid or corrupted")

   /* KAL_ERROR_ADM_FREE_BADID */
   TRC_MSG(SST_PHASE3_1763_ID_P1, "No signature is found in kal_adm_free(); the first word pointed by ADM ID should be 0x20101027, ")
   TRC_MSG(SST_PHASE3_1763_ID_P2, "but now it is 0x%X. Please check whether the pointer is valid or corrupted")

   /* KAL_ERROR_ADM_REALLOC_BADID */
   TRC_MSG(SST_PHASE3_1764_ID_P1, "No signature is found in kal_adm_realloc(); the first word pointed by ADM ID should be 0x20101027, ")
   TRC_MSG(SST_PHASE3_1764_ID_P2, "but now it is 0x%X. Please check whether the pointer is valid or corrupted")

   /* KAL_ERROR_ADM_CONCURRENT_OPERATION */
   TRC_MSG(SST_PHASE3_1770_TASK_P1, "Two or more tasks are operating at the same ADM pool (the other task index is %d).")
   TRC_MSG(SST_PHASE3_1770_TASK_P2, "Please check current task & task %d activities.")

   /* KAL_ERROR_ADM_BADPTR */
   TRC_MSG(SST_PHASE3_1771_PTR, "The given pinter is invalid. Please check your input ADM buffer pointer.")

   /* KAL_ERROR_ADM_GETEXTHEADER_FAILED */
   TRC_MSG(SST_PHASE3_1781_ADDR_P1, "This ADM pool has no extheader.")
   TRC_MSG(SST_PHASE3_1781_ADDR_P2, "Please specify KAL_ADM_EXTHEADER_FLAG in kal_adm_create2 if you want an extheader.")

