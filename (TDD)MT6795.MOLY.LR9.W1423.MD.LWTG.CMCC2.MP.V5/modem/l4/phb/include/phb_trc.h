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

/*******************************************************************************
 * Filename:
 * ---------
 *	phb_trc.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is trace map definition.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _PHB_TRC_H
#define _PHB_TRC_H

#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_trace.h"
#ifndef GEN_FOR_PC

   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before tst_config.h"
   #endif

#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */


#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before tst_trace.h"
#endif

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "phb_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_PHB)

   /* TRACE_FUNC trace class */   
   TRC_MSG(FUNC_PHB_STARTUP, "[PHB] startup handler")
   TRC_MSG(FUNC_PHB_STARTUP_ERR, "[PHB] startup error handler")   
   TRC_MSG(FUNC_PHB_STARTUP_CNF, "[PHB] startup result: %02X")
   TRC_MSG(FUNC_PHB_IS_SIM_FILE_SUPPORT, "[PHB] is sim file support, chv1_status: %d")   

   TRC_MSG(FUNC_PHB_STARTUP_SYNC_LN_TYPE_SEQ, "[LN] startup sync ln type seq")
   TRC_MSG(FUNC_PHB_STARTUP_ERASE_LN, "[LN] startup erase ln")

   TRC_MSG(FUNC_PHB_READ, "[PHB] read handler")
   TRC_MSG(FUNC_PHB_READ_USIM, "[PHB] read usim handler")
   TRC_MSG(FUNC_PHB_READ_ERR, "phb_read_err_handler: %d")   
   TRC_MSG(FUNC_PHB_READ_CNF, "[PHB] read result: %02X, total: %02X, src_id: %02X, msg_id: %04X")
   TRC_MSG(FUNC_PHB_READ_FAKE, "[PHB] read piggyback")

   TRC_MSG(FUNC_PHB_WRITE, "[PHB] write handler")
   TRC_MSG(FUNC_PHB_WRITE_USIM, "[PHB] write usim handler")
   TRC_MSG(FUNC_PHB_WRITE_ERR, "[PHB] write error handler")   
   TRC_MSG(FUNC_PHB_WRITE_CONT, "[PHB] write continue handler")
   TRC_MSG(FUNC_PHB_WRITE_CNF, "[PHB] write result: %02X, total: %02X, src_id: %02X")

   TRC_MSG(FUNC_PHB_DELETE, "[PHB] delete handler")
   TRC_MSG(FUNC_PHB_DELETE_USIM, "[PHB] delete usim handler")
   TRC_MSG(FUNC_PHB_DELETE_ERR, "[PHB] delete error handler")   
   TRC_MSG(FUNC_PHB_DELETE_CONT, "phb_delete_continue")
   TRC_MSG(FUNC_PHB_DELETE_CNF, "[PHB] delete result: %02X, total: %2X, src_id: %2X")

   TRC_MSG(FUNC_PHB_SEARCH, "[PHB] search handler")
   TRC_MSG(FUNC_PHB_SEARCH_ERR, "[PHB] search error handler")   
   TRC_MSG(FUNC_PHB_SEARCH_CONT, "[PHB] search continue handler")
   TRC_MSG(FUNC_PHB_SEARCH_CNF, "[PHB] search result: %02X, total: %02X, src_id: %02X, msg_id: %04X")
   TRC_MSG(FUNC_PHB_SEARCH_FAKE, "[PHB] search fake")

   TRC_MSG(FUNC_PHB_APPROVE, "[PHB] approve handler")
   TRC_MSG(FUNC_PHB_APPROVE_ERR, "[PHB] approve error handler")   
   TRC_MSG(FUNC_PHB_APPROVE_CONT, "[PHB] approvecontinue handler")
   TRC_MSG(FUNC_PHB_APPROVE_CNF, "[PHB] approve result: %02X, type: %02X, src_id: %2X")
   TRC_MSG(FUNC_PHB_APPROVE_ECC_LENGTH_ONE, "[PHB] approve ecc length equal 1, false")
   TRC_MSG(FUNC_PHB_APPROVE_ECC_NW_ECC, "[PHB] approve ecc, enter nw ecc")
   TRC_MSG(FUNC_PHB_APPROVE_ECC_NW_ECC_LEN_COMP, "[PHB] approve ecc, enter nw ecc, nw_ecc_len[%d] = %d, dialing_number = %d")
   TRC_MSG(FUNC_PHB_APPROVE_ECC_NW_ECC_LEN_COMP_TRUE, "[PHB] approve ecc, nw ecc, compare_n_bcd: TRUE [%d]")   
   TRC_MSG(FUNC_PHB_APPROVE_ECC_NW_ECC_LEN_COMP_EQUAL, "[PHB] approve ecc, nw ecc, len = len2 [%d]")
   TRC_MSG(FUNC_PHB_APPROVE_ECC_IS_NW_ECC, "[PHB] approve ecc, is nw ecc, [%d]-th, esc = %d")
   TRC_MSG(FUNC_PHB_APPROVE_ECC_NOT_NW_ECC, "[PHB] approve ecc, not nw ecc")
   TRC_MSG(FUNC_PHB_UPDATE_NW_ECC_LIST, "[PHB] update nw ecc list handler")
   TRC_MSG(FUNC_PHB_UPDATE_NW_ECC_LIST_NUM, "[PHB] update nw ecc list handler, num: %d")
   TRC_MSG(FUNC_PHB_UPDATE_NW_ECC_LIST_CATEGORY, "[PHB] update nw ecc list handler, nw_ecc_esc[%d] = %d")

   TRC_MSG(FUNC_PHB_SAT_FILE_CHANGE, "[PHB] SAT file change handler")
   TRC_MSG(FUNC_PHB_SAT_FILE_CHANGE_CNF, "[PHB] SAT file change result: %02X, src_id: %2X")

   TRC_MSG(FUNC_PHB_IO_RETURN, "[PHB] phb_IO_return")
   TRC_MSG(FUNC_PHB_IS_TYPE_VALID, "[PHB] phb_is_type_valid")
   TRC_MSG(FUNC_PHB_ISSUE_IO_DELETE, "[PHB] phb_issue_IO_delete")
   TRC_MSG(FUNC_PHB_ISSUE_IO_READ, "[PHB] phb_issue_IO_read")
   TRC_MSG(FUNC_PHB_ISSUE_IO_WRITE, "[PHB] phb_issue_IO_write")
   TRC_MSG(FUNC_PHB_PREPARE_DATA_TO_WRITE, "[PHB] phb_prepare_data_to_write")
   TRC_MSG(FUNC_PHB_DATA_DESC_ENTRY_NEW, "[PHB] phb_data_desc_entry_new")
   TRC_MSG(FUNC_PHB_DATA_DESC_ENTRY_RESET, "[PHB] phb_data_desc_entry_reset")
   TRC_MSG(FUNC_PHB_DATA_DESC_FIND_NEXT_FREE, "[PHB] phb_data_desc_find_next_free")
   TRC_MSG(FUNC_PHB_DATA_DESC_GET_FREE_COUNT, "[PHB] phb_data_desc_get_free_count")
   TRC_MSG(FUNC_PHB_DATA_DESC_GET_DESC_BY_ID, "[PHB] phb_data_desc_get_desc_by_ID")
   TRC_MSG(FUNC_PHB_DATA_DESC_GET_ID_BY_DESC, "[PHB] phb_data_desc_get_ID_by_desc")
   TRC_MSG(FUNC_PHB_DATA_DESC_GET_RECORD_NUM, "[PHB] phb_data_desc_get_record_num")
   TRC_MSG(FUNC_PHB_DATA_DESC_GET_RECORD_SIZE, "[PHB] phb_data_desc_get_record_size")
   TRC_MSG(FUNC_PHB_DATA_DESC_IS_FREE, "[PHB] phb_data_desc_is_free:%d -type: %d, record_index: %d-")
   TRC_MSG(PHB_TRC_DESC_MARK_FREE, "[PHB] phb_data_desc_mark_free: desc_bytes[%d]:%d, --pos:%d, rec_num:%d, is_free:%d")
   TRC_MSG(PHB_TRC_DESC_MARK_FREE_RESULT, "________data_desc_entry->free_count:%d, line:%d")
   TRC_MSG(FUNC_PHB_DATA_DESC_NEW, "[PHB] phb_data_desc_new")
   TRC_MSG(FUNC_PHB_DATA_DESC_RESET, "[PHB] phb_data_desc_reset")
   TRC_MSG(FUNC_PHB_DATA_DESC_RESET_FREE_COUNT, "[PHB] phb_data_desc_reset_free_count")
   TRC_MSG(FUNC_PHB_DATA_DESC_SET, "[PHB] phb_data_desc_set")
   TRC_MSG(FUNC_PHB_DATA_DESC_SET_IS_SUPPORT, "[PHB] phb_data_desc_set_is_support")
   TRC_MSG(FUNC_PHB_DET_APPEND, "[PHB] phb_det_append: det->used_count=%d, det->slots=%d")
   TRC_MSG(FUNC_PHB_DET_DELETE, "[PHB] phb_det_delete: position=%d, det->used_count=%d")
   TRC_MSG(FUNC_PHB_DET_GET, "[PHB] phb_det_get")
   TRC_MSG(FUNC_PHB_DET_GET_SIZE, "[PHB] phb_det_get_size")
   TRC_MSG(FUNC_PHB_DET_NEW, "[PHB] phb_det_new")
   TRC_MSG(FUNC_PHB_DET_RESET, "[PHB] phb_det_reset")
   TRC_MSG(FUNC_PHB_DET_SET, "[PHB] phb_det_set")
   TRC_MSG(PHB_TRC_DET_SET_DETAILS, "________det->table[%d]: storage=%d, rec_index=%d, sig=%d, num=%d, ext_idx=%d")
   TRC_MSG(FUNC_PHB_DET_GET_POS_BY_RECORD_INDEX, "[PHB]phb_det_get_pos_by_record_index")
   TRC_MSG(FUNC_PHB_SEND_ILM, "[PHB] phb_send_ilm")
   TRC_MSG(FUNC_PHB_ISTRING_ICMP, "[PHB] phb_istring_icmp")
   TRC_MSG(FUNC_PHB_BINARY_SEARCH, "[PHB] phb_binary_search")
   TRC_MSG(FUNC_PHB_COMPARE_BY_ALPHA_ID, "[PHB] phb_compare_by_alpha_id")
   TRC_MSG(FUNC_PHB_COMPARE_BY_ALPHA_ID_FOR_SORT, "[PHB] phb_compare_by_alpha_id_for_sort")
   TRC_MSG(FUNC_PHB_COMPARE_BY_ALPHA_ID_STORAGE, "[PHB] phb_compare_by_alpha_id_storage")
   TRC_MSG(FUNC_PHB_COMPARE_BY_ALPHA_ID_STORAGE_FOR_SORT, "[PHB] phb_compare_by_alpha_id_storage_for_sort")
   TRC_MSG(FUNC_PHB_COMPARE_BY_KEY_ALPHA_ID, "[PHB] phb_compare_by_key_alpha_id")
   TRC_MSG(FUNC_PHB_COMPARE_BY_TEL_NUM_SIG, "[PHB] phb_compare_by_tel_num_sig")
   TRC_MSG(FUNC_PHB_COMPARE_BY_TEL_NUM_SIG_FOR_SORT, "[PHB] phb_compare_by_tel_num_sig_for_sort")
   TRC_MSG(FUNC_PHB_FAST_QUICKSORT, "[PHB] phb_fast_quicksort")
   TRC_MSG(FUNC_PHB_INSERTION_SORT, "[PHB] phb_insertion_sort")
   TRC_MSG(FUNC_PHB_NAME_NUM_INDEX_APPEND, "[PHB] phb_name_num_index_append")
   TRC_MSG(FUNC_PHB_NAME_NUM_INDEX_DELETE, "[PHB] phb_name_num_index_delete: index=%d")
   TRC_MSG(FUNC_PHB_NAME_NUM_INDEX_FIND_INDEX_BY_ALPHA_ID, "[PHB] phb_name_num_index_find_index_by_alpha_id")
   TRC_MSG(FUNC_PHB_NAME_NUM_INDEX_FIND_INDEX_BY_ALPHA_ID_STORAGE, "[PHB] phb_name_num_index_find_index_by_alpha_id_storage")
   TRC_MSG(FUNC_PHB_NAME_NUM_INDEX_FIND_INDEX_BY_NUM_SIG, "[PHB] phb_name_num_index_find_index_by_num_sig")
   TRC_MSG(FUNC_PHB_NAME_NUM_INDEX_FIND_INDEX_BY_NUM_SIG_EXACT_MATCH, "[PHB] phb_name_num_index_find_index_by_num_sig_exact_match")
   TRC_MSG(FUNC_PHB_NAME_NUM_INDEX_GET_DATA_ENTRY, "[PHB] phb_name_num_index_get_data_entry")
   TRC_MSG(FUNC_PHB_NAME_NUM_INDEX_GET_SIZE, "[PHB] phb_name_num_index_get_size")
   TRC_MSG(FUNC_PHB_NAME_NUM_INDEX_NEW, "[PHB] phb_name_num_index_new")
   TRC_MSG(FUNC_PHB_NAME_NUM_INDEX_RESET, "[PHB] phb_name_num_index_reset")
   TRC_MSG(FUNC_PHB_NAME_NUM_INDEX_SORT, "[PHB] phb_name_num_index_sort")
   TRC_MSG(FUNC_PHB_NAME_NUM_INDEX_UPDATE, "[PHB] phb_name_num_index_update")
   TRC_MSG(FUNC_PHB_QUICKSORT, "[PHB] phb_quicksort")
   TRC_MSG(FUNC_PHB_SWAP, "[PHB] phb_swap")
   TRC_MSG(FUNC_PHB_NVRAM_DELETE, "[PHB] phb_nvram_delete")
   TRC_MSG(FUNC_PHB_NVRAM_DELETE_CNF, "[PHB] phb_nvram_delete_cnf")
   TRC_MSG(FUNC_PHB_NVRAM_READ, "[PHB] phb_nvram_read")
   TRC_MSG(FUNC_PHB_NVRAM_READ_CNF, "[PHB] phb_nvram_read_cnf")
   TRC_MSG(FUNC_PHB_NVRAM_READ_RECORD, "[PHB] phb_nvram_read_record")
   TRC_MSG(FUNC_PHB_NVRAM_WRITE, "[PHB] phb_nvram_write")
   TRC_MSG(FUNC_PHB_NVRAM_WRITE_CNF, "[PHB] phb_nvram_write_cnf")
   TRC_MSG(FUNC_PHB_NVRAM_WRITE_RECORD, "[PHB] phb_nvram_write_record")
   TRC_MSG(FUNC_PHB_PINDEX_APPEND, "[PHB] phb_pindex_append")
   TRC_MSG(FUNC_PHB_PINDEX_DELETE, "[PHB] phb_pindex_delete: index=%d, pindex->used_count=%d")
   TRC_MSG(FUNC_PHB_PINDEX_GET_POS, "[PHB] phb_pindex_get_pos:%d ")
   TRC_MSG(FUNC_PHB_PINDEX_GET_SIZE, "[PHB] phb_pindex_get_size")
   TRC_MSG(FUNC_PHB_PINDEX_INSERT, "[PHB] phb_pindex_insert")
   TRC_MSG(FUNC_PHB_PINDEX_NEW, "[PHB] phb_pindex_new")
   TRC_MSG(FUNC_PHB_PINDEX_RELINK, "[PHB] phb_pindex_relink")
   TRC_MSG(FUNC_PHB_PINDEX_RESET, "[PHB] phb_pindex_reset")
   TRC_MSG(FUNC_PHB_PINDEX_UPDATE, "[PHB] phb_pindex_update")
   TRC_MSG(FUNC_PHB_PINDEX_GET_INDEX_BY_POSITION, "[PHB] phb_pindex_get_index_by_position")
   TRC_MSG(FUNC_L4CPHB_MODE_REQ, "[L4CPHB] l4cphb_mode_req")
   TRC_MSG(FUNC_L4CPHB_STATUS_REQ, "[L4CPHB] l4cphb_status_req")
   TRC_MSG(FUNC_L4CPHB_GET_FILE_INFO, "[L4CPHB] l4c_phb_get_file_info, type = %d, storage = %d")
   TRC_MSG(FUNC_L4CPHB_GET_FILE_INFO_DETAIL, "[L4CPHB] l4c_phb_get_file_info, name_len = %d, num_len = %d, free_num = %d, total_num = %d, ext_free_num = %d")
   TRC_MSG(FUNC_L4CPHB_TEST_INDEX, "[L4CPHB] l4cphb_test_index")
   TRC_MSG(FUNC_L4CPHB_TEST_STORAGE, "[L4CPHB] l4cphb_test_storage")
   TRC_MSG(FUNC_L4CPHB_TEST_TEXT, "[L4CPHB] l4cphb_test_text")
   TRC_MSG(FUNC_L4CPHB_TEST_WRITE_PARAMETER, "[L4CPHB] l4cphb_test_write_parameter")
   TRC_MSG(FUNC_L4CPHB_ALLOC_PEER_BUF, "[L4CPHB] l4cphb_alloc_peer_buf")
   TRC_MSG(FUNC_PHB_BINARY_SEARCH_COUNTRY_CODE, "[PHB] phb_binary_search_country_code")
   TRC_MSG(FUNC_PHB_COMPARE_COUNTRY_CODE, "[PHB] phb_compare_country_code")
   TRC_MSG(FUNC_PHB_SE_APPEND, "[PHB] phb_se_append")
   TRC_MSG(FUNC_PHB_SE_CAL_SIGNATURE_NUM, "[PHB] phb_se_cal_signature_num")
   TRC_MSG(FUNC_PHB_SE_DELETE, "[PHB] phb_se_delete")
   TRC_MSG(FUNC_PHB_SE_FINISH_BUILD, "[PHB] phb_se_finish_build")
   TRC_MSG(FUNC_PHB_SE_GET_DIFFERNTIABLE_DIGITS, "[PHB] phb_se_get_differntiable_digits")
   TRC_MSG(FUNC_PHB_SE_GET_INDEX_VALUES, "[PHB] phb_se_get_index_values")
   TRC_MSG(FUNC_PHB_SE_GET_RECORD_INDEX, "[PHB] phb_se_get_record_index")
   TRC_MSG(FUNC_PHB_SE_GET_TOTAL_OF_TYPE, "[PHB] phb_se_get_total_of_type")
   TRC_MSG(FUNC_PHB_SE_IS_IN_RANGE, "[PHB] phb_se_is_in_range:%d type = %d, index = %d, total = %d")
   TRC_MSG(FUNC_PHB_SE_IS_NEXT_ALSO_CANDIDATE, "[PHB] phb_se_is_next_also_candidate")
   TRC_MSG(FUNC_PHB_SE_NEW, "[PHB] phb_se_new")
   TRC_MSG(FUNC_PHB_SE_RESET, "[PHB] phb_se_reset")
   TRC_MSG(FUNC_PHB_SE_SEARCH_BY_NAME, "[PHB] phb_se_search_by_name")
   TRC_MSG(FUNC_PHB_SE_SEARCH_BY_RECORD_INDEX_NAME, "[PHB] phb_se_search_by_record_index_name")
   TRC_MSG(FUNC_PHB_SE_SEARCH_BY_TEL_NUM, "[PHB] phb_se_search_by_tel_num")
   TRC_MSG(FUNC_PHB_SE_SET_CONTROL_BLOCK, "[PHB] phb_se_set_control_block: op = %d, storage = %d, record_index = %d")
   TRC_MSG(FUNC_PHB_SE_SET_CONTROL_BLOCK_TRANSLATE_INDEX, "[PHB] phb_se_set_index: primary_ID = %d, secondary_ID = %d, storage = %d, index = %d")
   TRC_MSG(PHB_TRC_SE_SET_INDEX, "[PHB] phb_se_set_index:%d primary_ID = %d, storage = %d, index = %d, record_index = %d")
   TRC_MSG(PHB_TRC_SE_SET_INDEX_DEL, "[PHB] phb_se_set_index_delete")
   TRC_MSG(FUNC_PHB_SE_UPDATE, "[PHB] phb_se_update")
   TRC_MSG(FUNC_PHB_SE_BUILD_INDEX, "[PHB] phb_se_build_index")
   TRC_MSG(FUNC_PHB_SIM_DELETE, "[PHB] phb_sim_delete")
   TRC_MSG(FUNC_PHB_SIM_DELETE_CNF, "[PHB] phb_IO_sim_delete_cnf")
   TRC_MSG(FUNC_PHB_SIM_FILE_INFO, "[PHB] phb_sim_file_info")
   TRC_MSG(FUNC_PHB_SIM_FILE_INFO_CNF, "[PHB] phb_sim_file_info_cnf")
   TRC_MSG(FUNC_PHB_SIM_READ, "[PHB] phb_sim_read")
   TRC_MSG(FUNC_PHB_SIM_READ_CNF, "[PHB] phb_IO_sim_read_cnf")
   TRC_MSG(FUNC_PHB_SIM_READ_RECORD, "[PHB] phb_sim_read_record: %Msim_file_index_enum, rec:%d")
   TRC_MSG(FUNC_PHB_SIM_REASSEMBLE_TEL_NUM, "[PHB] phb_sim_reassemble_tel_num")
   TRC_MSG(FUNC_PHB_SIM_WRITE, "[PHB] phb_sim_write")
   TRC_MSG(PHB_TRC_SIM_WRT_EXT_REC, "________type = %Mdata_desc_enum, ext rec#=%d")
   TRC_MSG(FUNC_PHB_SIM_WRITE_CNF, "[PHB] phb_IO_sim_write_cnf")
   TRC_MSG(FUNC_PHB_SIM_WRITE_FIRST_RECORD, "[PHB] phb_sim_write_first_record")
   TRC_MSG(FUNC_PHB_SIM_WRITE_RECORD, "[PHB] phb_sim_write_record")
   TRC_MSG(PHB_TRC_SIM_WRT_REC, "[PHB] phb_sim_write_record: %Msim_file_index_enum, rec:%d")
   TRC_MSG(PHB_TRC_SIM_WRT_REC_MULTI, "[PHB] phb_sim_write_record: %Msim_file_index_enum, rec:%d")   
   TRC_MSG(FUNC_PHB_SIM_WRITE_SEGMENTED_RECORD, "[PHB] phb_sim_write_segmented_record")
   TRC_MSG(FUNC_PHB_CONTEXT_SELECTION, "[PHB] phb_context_selection, SIM: %d")
   TRC_MSG(FUNC_PHB_WHICH_SIM_EX, "[PHB] phb_which_sim_ex, PHB_MOD: %d")
   TRC_MSG(PHB_TRC_SIM_MULTI_EF, "________EF#: %d, record: %d")

   TRC_MSG(FUNC_PHB_SIM_IO_CHECK, "[PHB] phb_IO_index_check: file_idx = %d, occurrence = %d, record_index = %d")

   /* TRACE_STATE trace class */   
   TRC_MSG(STATE_PHB_NULL, "[PHB] State: NULL.")
   TRC_MSG(STATE_PHB_LN_NOT_READY, "[LN] State: Ln not ready.")
   TRC_MSG(STATE_PHB_NOT_READY, "[PHB] State: Not ready.")
   TRC_MSG(STATE_PHB_READY, "[PHB] State: Ready.")

   TRC_MSG(STATE_PHB_DEFINE_RECORD_LN_TYPE_SEQ, "[LN] Define ln type seq.")
   TRC_MSG(STATE_PHB_NOT_DEFINE_RECORD_LN_TYPE_SEQ, "[LN] Not define ln type seq.")

   /* TRACE_INFO trace class */   
   /* Startup related. */
   TRC_MSG(INFO_PHB_STARTUP_MODE, "[PHB] Startup dialing mode: %02X")
   TRC_MSG(INFO_PHB_FILE_INFO_BEGIN, "________ Get information for all EF's.")
   TRC_MSG(INFO_PHB_FILE_INFO_GOT, "________Information for all EF's got!")
   TRC_MSG(PHB_TRC_GET_INFO, "[PHB] phb_get_info: %Msim_file_index_enum")
   TRC_MSG(PHB_TRC_GET_INFO_NOT_SUPPORT, "________Not supportted: line = %d")
   TRC_MSG(PHB_TRC_GET_INFO_ADN, "[PHB] ADN records: Project support = %d, SIM = %d, result = %d")

   TRC_MSG(INFO_PHB_INDICES_BEGIN, "[PHB] Scanning for building indices.")
   TRC_MSG(INFO_PHB_INDICES_BUILT, "[PHB] Indices built!")
   TRC_MSG(INFO_PHB_APPROVE_ECC_SIM_CARD_STATUS, "[PHB] approve ecc sim status : %02X")
   
   TRC_MSG(INFO_PHB_STARTUP_SYNC_LN_TYPE_SEQ_SIM_STATUS, "[LN] phb_startup_sync_ln_type_seq, sim_status: %02X")
   TRC_MSG(INFO_PHB_STARTUP_ERASE_SIM_STATUS, "[LN] phb_startup_erase_ln, sim_status: %02X")

   /* TRACE_WARNING trace class */   
   TRC_MSG(WARNING_PHB, "[PHB] Warning")

   /* TRACE_ERROR trace class */   
   TRC_MSG(ERROR_PHB_SIM_IO_STATE_FILE_INFO, "[PHB] Not waiting this primitive. What's up?")
   TRC_MSG(ERROR_PHB_SIM_IO_STATE_READ, "[PHB] Not waiting this primitive. What's up?")
   TRC_MSG(ERROR_PHB_SIM_IO_STATE_WRITE, "[PHB] Not waiting this primitive. What's up?")
   TRC_MSG(ERROR_PHB_SIM_IO_STATE_DELETE, "[PHB] Not waiting this primitive. What's up?")

   TRC_MSG(ERROR_PHB_NVRAM_IO_STATE_READ, "[PHB] Not waiting this primitive. What's up?")
   TRC_MSG(ERROR_PHB_NVRAM_IO_STATE_WRITE, "[PHB] Not waiting this primitive. What's up?")
   TRC_MSG(ERROR_PHB_NVRAM_IO_STATE_DELETE, "[PHB] Not waiting this primitive. What's up?")

   TRC_MSG(ERROR_PHB_ABNORMAL, "[PHB] NOTICE: ABNORMAL CASE!")
   TRC_MSG(ERROR_PHB_STATE, "[PHB] State error")
   
   /* phb_handler_sat.c */
   TRC_MSG(FUNC_PHB_SAT_FILE_CHANGE_CONTROL_BLOCK, "[PHB] phb_sat_file_change_handler, control_block: %d")
   
   /* call log part */
   /* phb_common.c */
   TRC_MSG(FUNC_PHB_ISSUE_IO_WRITE_LN, "[LN] phb_issue_IO_write_ln")
   TRC_MSG(FUNC_PHB_ISSUE_IO_READ_LN, "[LN] phb_issue_IO_read_ln")
   
   /* phb_handler_delete_ln.c */
   TRC_MSG(FUNC_PHB_DELETE_SIM_LN, "[LN] phb_delete_sim_ln_handler")
   TRC_MSG(FUNC_PHB_DELETE_SIM_LN_ERR, "[LN] phb_delete_sim_ln_err_handler")
   
   /* phb_handler_read_ln.c */
   TRC_MSG(FUNC_PHB_READ_SIM_LN, "[LN] phb_read_sim_ln_handler")
   TRC_MSG(FUNC_PHB_READ_SIM_LN_ERR, "[LN] phb_read_sim_ln_err_handler")
   
   /* phb_handler_startup_ln.c */
   TRC_MSG(FUNC_PHB_IS_LN_SIM_FILE_SUPPORT, "[LN] phb_is_ln_sim_file_support")
   TRC_MSG(FUNC_PHB_GET_LN_INFO_SET_VALUE, "[LN] phb_get_ln_info_set_value")
   TRC_MSG(FUNC_PHB_GET_LN_INFO_ERR, "[LN] phb_get_ln_info_err_handler")
   TRC_MSG(FUNC_PHB_GET_LN_INFO, "[LN] phb_get_ln_info")
   TRC_MSG(FUNC_PHB_NO_CALL_LOG_INIT_LN, "[LN] phb_no_call_log_init_ln_handler")
   
   /* phb_handler_write_ln.c */
   TRC_MSG(FUNC_PHB_WRITE_SIM_LN_ERR, "[LN] phb_write_sim_ln_err_handler")
   TRC_MSG(FUNC_PHB_WRITE_SIM_LN, "[LN] phb_write_sim_ln_handler")
   
   /* phb_sap.c */
   TRC_MSG(FUNC_L4CPHB_GET_LN_FILE_INFO, "[LN] l4c_phb_get_ln_file_info")
   
   /* phb_se.c */
   TRC_MSG(FUNC_PHB_SE_SET_LN_CONTROL_BLOCK, "[LN] phb_se_set_ln_control_block, record_index: %d")

   /* phb_sim_access.c */
   TRC_MSG(FUNC_PHB_SIM_PREPARE_LN_DATA_TO_WRITE, "[LN] phb_sim_prepare_ln_data_to_write")
   TRC_MSG(FUNC_PHB_SIM_WRITE_LN_CNF, "[LN] phb_sim_write_ln_cnf")
   TRC_MSG(FUNC_PHB_SIM_WRITE_LN_FIRST_RECORD, "[LN] phb_sim_write_ln_first_record")
   TRC_MSG(FUNC_PHB_SIM_WRITE_LN, "[LN] phb_sim_write_ln")
   TRC_MSG(FUNC_PHB_SIM_READ_LN_CNF, "[LN] phb_sim_read_ln_cnf")
   TRC_MSG(FUNC_PHB_SIM_READ_LN, "[LN] phb_sim_read_ln")

   /* phb_utils.c */
   TRC_MSG(FUNC_PHB_COMPARE_BCD_FOR_WILD_CHAR, "[PHB] phb_compare_bcd_for_wild_char")

   TRC_MSG(PHB_TRC_DEL_FIND_NEXT, "[PHB] phb_delete_find_next_deleted: %d")
   TRC_MSG(PHB_TRC_DEL_CONT_MSISDN, "________continue MSISDN: candidate = %d, index = %d, seg_idx = %d")
   TRC_MSG(PHB_TRC_DEL_CONT_TOTAL, "________actual_count = %d, total = %d, index = %d")

   TRC_MSG(PHB_TRC_SE_GET_IDX, "[PHB] phb_se_get_index_by_storage: %d")
   TRC_MSG(PHB_TRC_SIM_DEL_CNF, "[PHB] phb_sim_delete_cnf: IO_stage = %d, secondary_ID = %d")

   TRC_MSG(PHB_TRC_READ_CONT, "[PHB] phb_read_continue: actual_count = %d, total = %d, index = %d, record_index = %d")
   TRC_MSG(PHB_TRC_CB_SET_STATE, "________proc_stage[%d]-> %d")
   TRC_MSG(PHB_TRC_CB_GET_STATE, "________proc_stage[%d] : %d")
   TRC_MSG(PHB_SE_SET_INDEX_TRACE, "[PHB] phb_se_set_index:%d")
   TRC_MSG(PHB_TRC_SE_C, "________phb_se.c: %d")

END_TRACE_MAP(MOD_PHB)
#endif


