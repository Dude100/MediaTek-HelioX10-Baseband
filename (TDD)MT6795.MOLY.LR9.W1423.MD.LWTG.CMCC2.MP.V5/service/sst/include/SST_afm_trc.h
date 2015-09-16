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
 *   SST_afm_trc.h
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
   /* KAL_ERROR_AFM_CREATE_FAILED */
   TRC_MSG(SST_PHASE1_1800_01, "In kal_afm_create(), AFM pool creation failed because the configuration is un-recognizable.")
   TRC_MSG(SST_PHASE1_1800_02, "In kal_afm_create(), AFM pool creation failed because the given array of sub-pool size or number is illegal.")
   TRC_MSG(SST_PHASE1_1800_03, "In kal_afm_create(), AFM pool creation failed because the given pool size is not large enough to create required sub-pools.")

   /* KAL_ERROR_AFM_DELETE_FAILED */

   /* KAL_ERROR_AFM_ALLOC_FAILED */
   TRC_MSG(SST_PHASE1_1820_05, "In kal_afm_internal_alloc_dbg(), allocation failed because users wrongly call _c/_nc API on non-cache-aligned creation AFM pool.")

   /* KAL_ERROR_AFM_ALLOC_DYNCACHE_FAILED */
   TRC_MSG(SST_PHASE1_1826_01, "In kal_afm_internal_alloc_cacheable(),allocation failed because the AFM pool is not cacheability switchable.")
   TRC_MSG(SST_PHASE1_1826_02, "In kal_afm_internal_alloc_noncacheable(),allocation failed because the AFM pool is not cacheability switchable.")

   /* KAL_ERROR_AFM_FREE_FAILED */
   
   /* KAL_ERROR_AFM_FREE_DOUBLEFREE */
   TRC_MSG(SST_PHASE1_1831_ADDR, "In kal_afm_free(), de-allocation failed because the given memory block is freed before; it's a double free problem.")

   /* KAL_ERROR_AFM_FOOTER_FAILED */
   TRC_MSG(SST_PHASE1_1840_ADDR, "In kal_afm_free()/kal_afm_check_integrity(), fatal occurs because the footer stamp of the memory block is corrupted.")

   /* KAL_ERROR_AFM_HEADER_FAILED */
   TRC_MSG(SST_PHASE1_1841_ADDR, "In kal_afm_free()/kal_afm_check_integrity(), fatal occurs because the header stamp of the memory block is corrupted.")

   /* KAL_ERROR_AFM_FOOTER_FAILED_GET */
   TRC_MSG(SST_PHASE1_1842_ADDR, "In kal_afm_internal_alloc_dbg(), allocation failed because the footer stamp of the memory block is corrupted.")

   /* KAL_ERROR_AFM_HEADER_FAILED_GET */
   TRC_MSG(SST_PHASE1_1843_ADDR, "In kal_afm_internal_alloc_dbg(), allocation failed because the header stamp of the memory block is corrupted.")

   /* KAL_ERROR_AFM_NILPTR */

   /* KAL_ERROR_AFM_DELETE_NILPTR */
   TRC_MSG(SST_PHASE1_1851_00, "In kal_afm_delete(), the given AFM control block pointer is NULL.")

   /* KAL_ERROR_AFM_ALLOC_NILPTR */
   TRC_MSG(SST_PHASE1_1852_00, "In kal_afm_internal_alloc_dbg(),the given AFM control block pointer is NULL.")

   /* KAL_ERROR_AFM_FREE_NILPTR */
   TRC_MSG(SST_PHASE1_1853_00, "In kal_afm_free(),the given AFM control block pointer is NULL.")

   /* KAL_ERROR_AFM_BADID */

   /* KAL_ERROR_AFM_DELETE_BADID */
   TRC_MSG(SST_PHASE1_1861_ID, "In kal_afm_delete(), the AFM ID of the given AFM control block is not valid (0x20100104).")

   /* KAL_ERROR_AFM_ALLOC_BADID */
   TRC_MSG(SST_PHASE1_1862_ID, "In kal_afm_internal_alloc_dbg(), the AFM ID of the given AFM control block is not valid (0x20100104).")

   /* KAL_ERROR_AFM_FREE_BADID */
   TRC_MSG(SST_PHASE1_1863_ID, "In kal_afm_free(), the AFM ID of the given AFM control block is not valid (0x20100104).")

   /* KAL_ERROR_AFM_BADPTR */
   
   /* ------------------- Phase 2: Detailed analysis (N/A) -------------------- */
   
   /* -------------------- Phase 3: Guideline ------------------------- */
   /* KAL_ERROR_AFM_CREATE_FAILED */
   TRC_MSG(SST_PHASE3_1800_01, "Unknow options are supplied. Please check every bit in options is defined as AFM_OPT_*.")
   TRC_MSG(SST_PHASE3_1800_02, "The subpool_size or subpool_nr is NULL, and you must supply correct subpool settings.")
   TRC_MSG(SST_PHASE3_1800_03, "There's no enough memory to create AFM pool. Please give a bigger memory to this AFM pool.")

   /* KAL_ERROR_AFM_DELETE_FAILED */

   /* KAL_ERROR_AFM_ALLOC_FAILED */
   TRC_MSG(SST_PHASE3_1820_05_P1, "Don't request a cache-line aligned memory from non-cache-line aligned AFM pool,")
   TRC_MSG(SST_PHASE3_1820_05_P2, "or you need to change to cache-line aligned pool.")

   /* KAL_ERROR_AFM_ALLOC_DYNCACHE_FAILED */
   TRC_MSG(SST_PHASE3_1826_01_P1, "The AFM pool is non-cacheable by default and its cacheability is not dynamic switchable, ")
   TRC_MSG(SST_PHASE3_1826_01_P2, "and thus you can't allocate a cacheable buffer from it.")
   TRC_MSG(SST_PHASE3_1826_01_P3, "Please put your AFM pool in cachebility dynamic switchable region, or don't require cacheable memory from it.")
   TRC_MSG(SST_PHASE3_1826_02_P1, "The AFM pool is cacheable by default and its cacheability is not dynamic switchable, ")
   TRC_MSG(SST_PHASE3_1826_02_P2, "and thus you can't allocate a non-cacheable buffer from it.")
   TRC_MSG(SST_PHASE3_1826_02_P3, "Please put your AFM pool in cachebility dynamic switchable region, or don't require non-cacheable memory from it.")

   /* KAL_ERROR_AFM_FREE_FAILED */
   
   /* KAL_ERROR_AFM_FREE_DOUBLEFREE */
   TRC_MSG(SST_PHASE3_1831_ADDR, "double free or dangling pointer? Please check where the previous free operation locates.")

   /* KAL_ERROR_AFM_FOOTER_FAILED */
   TRC_MSG(SST_PHASE3_1840_ADDR_P1, "In kal_afm_free(this_afm, ptr), the AFM guard pattern after ptr is corrupted.")
   TRC_MSG(SST_PHASE3_1840_ADDR_P2, "Please check memory blocks around, especially the case ptr overwritten.")

   /* KAL_ERROR_AFM_HEADER_FAILED */
   TRC_MSG(SST_PHASE3_1841_ADDR_P1, "In kal_afm_free(this_afm, ptr), the AFM guard pattern before ptr is corrupted.")
   TRC_MSG(SST_PHASE3_1841_ADDR_P2, "Please check memory blocks around, especially the case previous block corrupts ptr's header.")

   /* KAL_ERROR_AFM_FOOTER_FAILED_GET */
   TRC_MSG(SST_PHASE3_1842_ADDR_P1, "In kal_afm_alloc_*(this_afm, size), the AFM head guard pattern at 0x%X is corrupted (it should be 0x03F3F3F3).")
   TRC_MSG(SST_PHASE3_1842_ADDR_P2, "Please check users of memory blocks around 0x%X.")

   /* KAL_ERROR_AFM_HEADER_FAILED_GET */
   TRC_MSG(SST_PHASE3_1843_ADDR_P1, "In kal_afm_alloc_*(this_afm, size), the AFM foot guard pattern at 0x%X is corrupted (it should be 0x04F4F4F4).")
   TRC_MSG(SST_PHASE3_1843_ADDR_P2, "Please check users of memory blocks around 0x%X.")

   /* KAL_ERROR_AFM_NILPTR */

   /* KAL_ERROR_AFM_DELETE_NILPTR */
   TRC_MSG(SST_PHASE3_1851_00, "You past a NULL AFM ID to kal_afm_delete(). Please check your input.")

   /* KAL_ERROR_AFM_ALLOC_NILPTR */
   TRC_MSG(SST_PHASE3_1852_00, "You past a NULL AFM ID to kal_afm_alloc_*(). Please check your input.")

   /* KAL_ERROR_AFM_FREE_NILPTR */
   TRC_MSG(SST_PHASE3_1853_00, "You past a NULL AFM ID to kal_afm_free(), Please check your input.")

   /* KAL_ERROR_AFM_BADID */

   /* KAL_ERROR_AFM_DELETE_BADID */
   TRC_MSG(SST_PHASE3_1861_ID_P1, "No valid signature is found in kal_afm_delete(); the first word pointed by AFM ID should be 0x20100104, ")
   TRC_MSG(SST_PHASE3_1861_ID_P2, "but now it is 0x%X, Please check the pointer is valid or corrupted.")

   /* KAL_ERROR_AFM_ALLOC_BADID */
   TRC_MSG(SST_PHASE3_1862_ID_P1, "No valid signature is found in kal_afm_alloc_*(); the first word pointed by AFM ID should be 0x20100104, ")
   TRC_MSG(SST_PHASE3_1862_ID_P2, "but now it is 0x%X, Please check the pointer is valid or corrupted.")     

   /* KAL_ERROR_AFM_FREE_BADID */
   TRC_MSG(SST_PHASE3_1863_ID_P1, "No valid signature is found in kal_afm_free(); the first word pointed by AFM ID should be 0x20100104, ")
   TRC_MSG(SST_PHASE3_1863_ID_P2, "but now it is 0x%X, Please check the pointer is valid or corrupted.")

   /* KAL_ERROR_AFM_BADPTR */

