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
 * RAT_TCM_TRC.H
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   RAT_TCM module trace definition
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _RAT_TCM_TRC_H
#define _RAT_TCM_TRC_H

#include "kal_public_defs.h"
#include "kal_trace.h"

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
#include "rat_tcm_trc_gen.h"
#endif /* TST Trace Defintion */
#endif

BEGIN_TRACE_MAP(MOD_RAT_TCM)

/* TRACE_FUNC */
TRC_MSG(TRC_RAT_TCM_MAIN_FUNCTION, "rat_tcm_main()")

/* TRACE_STATE */
TRC_MSG(RAT_TCM_CHANGE_RAT_STATE, "rat_tcm_rat_state change from %Mrat_tcm_rat_state_enum to %Mrat_tcm_rat_state_enum")
TRC_MSG(RAT_TCM_CHANGE_DURING_PROCESSING_EMBED_MESSAGE_STATE, "during_processing_embed_message change from %Mkal_bool to %Mkal_bool")
TRC_MSG(RAT_TCM_CHANGE_SIB_ACT_REQ_PROGRESS_STATE, "context id [%d].act_req_progress change from %Mrat_tcm_req_progress_enum to %Mrat_tcm_req_progress_enum")
TRC_MSG(RAT_TCM_CHANGE_SIB_DEACT_REQ_PROGRESS_STATE, "context id [%hd].deact_req_progress change from %Mrat_tcm_req_progress_enum to %Mrat_tcm_req_progress_enum")
TRC_MSG(RAT_TCM_CHANGE_SIB_MOD_REQ_PROGRESS_STATE, "context id [%hd].mod_req_progress change from %Mrat_tcm_req_progress_enum to %Mrat_tcm_req_progress_enum")
TRC_MSG(RAT_TCM_CHANGE_SIB_CONTEXT_USER_VIEW_STATE, "context id [%hd].context_user_view_state change from %Mrat_tcm_context_user_view_enum to %Mrat_tcm_context_user_view_enum")
TRC_MSG(RAT_TCM_CHANGE_SIB_CONTEXT_DEACT_REQ_TRIGGERER, "context id [%hd].deact_req_triggerer change from %Mrat_tcm_deact_triggerer_enum to %Mrat_tcm_deact_triggerer_enum")
TRC_MSG(RAT_TCM_CHANGE_SIB_CONTEXT_USER, "context id [%hd].context_user change from %Mrat_tcm_context_user_enum to %Mrat_tcm_context_user_enum")
TRC_MSG(RAT_TCM_CHANGE_SIB_THIS_IS_23G_MT_PDP_AND_DURING_ACTIVATING, "context id [%hd].this_is_23g_mt_pdp_and_during_activating change from %Mkal_bool to %Mkal_bool")
TRC_MSG(RAT_TCM_CHECK_IS_VALID_RAT_STATE_CHANGE, "rat_tcm_is_valid_rat_state_change() orig:%Mrat_tcm_rat_state_enum new:%Mrat_tcm_rat_state_enum")
TRC_MSG(RAT_TCM_CHECK_GET_CURRENT_RAT_WHEN_RAT_UNKNOWN, "rat_tcm_get_current_rat_when_rat_unknown():%Mrat_tcm_rat_state_enum")
TRC_MSG(RAT_TCM_CHECK_GET_CURRENT_RAT_TCM, "tcm_rat_tcm_get_current_rat():%Mrat_tcm_rat_state_enum")


TRC_MSG(RAT_TCM_DEACT_TRIGGERED_FLAG_USER_DEACT_STATE, "context id [%hd].deact_triggered_flag.is_deact_by_user_deact %Mkal_bool >> %Mkal_bool")
TRC_MSG(RAT_TCM_DEACT_TRIGGERED_FLAG_TFT_CONFLICT_STATE, "context id [%hd].deact_triggered_flag.is_deact_by_tft_conflict %Mkal_bool >> %Mkal_bool")
TRC_MSG(RAT_TCM_DEACT_TRIGGERED_FLAG_ENSA_TRIGGER_STATE, "context id [%hd].deact_triggered_flag.is_deact_by_enas_trigger %Mkal_bool >> %Mkal_bool")
TRC_MSG(RAT_TCM_DEACT_TRIGGERED_FLAG_TFT_VALIDATE_FAIL_STATE, "context id [%hd].deact_triggered_flag.is_deact_by_tft_validate_fail %Mkal_bool >> %Mkal_bool")
TRC_MSG(RAT_TCM_DEACT_TRIGGERED_FLAG_ALL_STATE, "context id [%hd].deact_triggered_flag => user_deact:%Mkal_bool, tft_conflict:%Mkal_bool, enas_trigger:%Mkal_bool, tft_validate_fail:%Mkal_bool")
TRC_MSG(RAT_TCM_PRINT_CURRENT_DEACT_REASON, "context id [%hd] deact_reason:%Mkal_bool, tft_conflict:%Mtcm_pdp_deact_reason_enum")
TRC_MSG(RAT_TCM_PRINT_NEED_RETRY_FLAG_FOR_IRAT, "cid: %d, need_retry_act: %d, need_retry_deact: %d, need_retry_mod: %d")

/* TRACE_ERROR */

/* TRACE_WARNING */
TRC_MSG(RAT_TCM_IGNORE_TAF_EXT_DEACT_REQ_BECAUSE_CONTEXT_IS_INACTIVE, "context id [%hd] MSG_ID_TAF_EXT_PDP_DEACTIVATE_REQ is ignored because this context was already INACTIVE")
TRC_MSG(RAT_TCM_IGNORE_TCM_PDP_DEACT_IND_BECAUSE_CONTEXT_IS_INACTIVE, "context id [%hd] MSG_ID_TCM_PDP_DEACTIVATE_IND is ignored because this context was already INACTIVE")
TRC_MSG(RAT_TCM_DO_NOT_SEND_DEACT_IND_BECAUSE_CONTEXT_IS_INACTIVE, "context id [%hd] DEACT_IND (TAF_EXT_PDP_DEACTIVATE_REQ or TCM_PDP_DEACTIVATE_IND) is ignored because this context was already INACTIVE")
TRC_MSG(RAT_TCM_SEE_UNKNOWN_EMBEDDED_MESSAGE_ID, "rat_tcm see unknown embed msg id: %Mmsg_type")


/* TRACE_ERROR */

/* TRACE_INFO */

/* TRACE_GROUP_1 */

/* TRACE_GROUP_2 */

/* TRACE_GROUP_3 msgs */
TRC_MSG(RAT_TCM_HANDLER_FOR_PDP_FSM_MSGS, "rat_tcm_handler_for_pdp_fsm_msgs(ilm_type: %Mrat_tcm_incomming_ilm_type_enum)")
TRC_MSG(RAT_TCM_HANDLER_FOR_RELAY_MSGS, "rat_tcm_handler_for_relay_msgs(ilm_type: %Mrat_tcm_incomming_ilm_type_enum)")
TRC_MSG(RAT_TCM_HANDLER_FOR_INTER_RAT_MSGS, "rat_tcm_handler_for_inter_rat_msgs(ilm_type: %Mrat_tcm_incomming_ilm_type_enum)")
#ifdef __SGLTE__
TRC_MSG(RAT_TCM_HANDLER_FOR_PS_CHANGE_MSGS, "rat_tcm_handler_for_ps_change_msgs(ilm_type: %Mrat_tcm_incomming_ilm_type_enum)")
TRC_MSG(RAT_TCM_HANDLER_FOR_PS_CHANGE_COMPLETE, "rat_tcm_handler_for_ps_change_complete()")
TRC_MSG(RAT_TCM_HANDLER_FOR_CONTEXT_TRANSFER_REQ, "rat_tcm_handler_for_context_transfer_req()")
TRC_MSG(RAT_TCM_HANDLER_FOR_CONTEXT_TRANSFER_CNF, "rat_tcm_handler_for_context_transfer_cnf()")
TRC_MSG(RAT_TCM_HANDLER_FOR_RAT_TCM_CONTEXT_TRANSFER, "rat_tcm_fill_transferred_to_another_mode_context()")
#endif /* __SGLTE__ */
TRC_MSG(RAT_TCM_HANDLER_FOR_MT_PRIMARY_PDP_INITIALIZATION_MSGS, "rat_tcm_handler_for_mt_primary_pdp_initialization_msgs(ilm_type: %Mrat_tcm_incomming_ilm_type_enum)")
TRC_MSG(RAT_TCM_HANDLER_FOR_START_UP_MSGS, "rat_tcm_handler_for_start_up_msgs(ilm_type: %Mrat_tcm_incomming_ilm_type_enum)")
TRC_MSG(RAT_TCM_HANDLER_FOR_RAT_CHANGE_START, "rat_tcm_handler_for_rat_change_start()")
TRC_MSG(RAT_TCM_HANDLER_FOR_RAT_CHANGE_FINISH, "rat_tcm_handler_for_rat_change_finish()")
TRC_MSG(RAT_TCM_HANDLER_FOR_RAT_CHANGE_COMPLETE, "rat_tcm_handler_for_rat_change_complete()")
TRC_MSG(RAT_TCM_RETRY_FAILED_REQ_DURING_IRAT, "rat_tcm_retry_failed_req_during_irat()")
TRC_MSG(RAT_TCM_RETRY_FAILED_DEACT_REQ_DURING_PS_SWITCH, "rat_tcm_retry_failed_deact_req_during_ps_switch()")
TRC_MSG(RAT_TCM_PROCESS_QUEUED_REQ_DURING_IRAT, "rat_tcm_process_queued_req_during_irat()")
TRC_MSG(RAT_TCM_HANDLER_FOR_ILM_TYPE_ACT_REQ, "rat_tcm_handler_for_ilm_type_act_req()")
TRC_MSG(RAT_TCM_HANDLER_FOR_ILM_TYPE_DEACT_REQ, "rat_tcm_handler_for_ilm_type_deact_req()")
TRC_MSG(RAT_TCM_HANDLER_FOR_ILM_TYPE_MOD_REQ, "rat_tcm_handler_for_ilm_type_mod_req()")
TRC_MSG(RAT_TCM_HANDLER_FOR_ILM_TYPE_ACT_SUCCESS, "rat_tcm_handler_for_ilm_type_act_success()")
TRC_MSG(RAT_TCM_HANDLER_FOR_ILM_TYPE_DEACT_SUCCESS, "rat_tcm_handler_for_ilm_type_deact_success()")
TRC_MSG(RAT_TCM_HANDLER_FOR_ILM_TYPE_MOD_SUCCESS, "rat_tcm_handler_for_ilm_type_mod_success()")
TRC_MSG(RAT_TCM_HANDLER_FOR_ILM_TYPE_ACT_FAIL, "rat_tcm_handler_for_ilm_type_act_fail()")
TRC_MSG(RAT_TCM_HANDLER_FOR_ILM_TYPE_DEACT_FAIL, "rat_tcm_handler_for_ilm_type_deact_fail()")
TRC_MSG(RAT_TCM_HANDLER_FOR_ILM_TYPE_MOD_FAIL, "rat_tcm_handler_for_ilm_type_mod_fail()")
TRC_MSG(RAT_TCM_HANDLER_FOR_ILM_TYPE_DEACT_IND, "rat_tcm_handler_for_ilm_type_deact_ind()")
TRC_MSG(RAT_TCM_HANDLER_FOR_ILM_TYPE_SECONDARY_ACT_IND, "rat_tcm_handler_for_ilm_type_secondary_act_ind()")
TRC_MSG(RAT_TCM_HANDLER_FOR_ILM_TYPE_MOD_IND, "rat_tcm_handler_for_ilm_type_mod_ind()")
TRC_MSG(RAT_TCM_RESET, "rat_tcm_reset()")
TRC_MSG(RAT_TCM_QUEUE_AN_ILM, "rat_tcm_queue_an_ilm(context_num: %d, ilm_type: %Mrat_tcm_incomming_ilm_type_enum, ilm_ptr: %x)")
TRC_MSG(RAT_TCM_PRINT_ALL_QUEUED_ILM_FOR_A_CID, " rat_tcm_print_all_queued_ilm(context_num: %hd)")
TRC_MSG(RAT_TCM_PRINT_AN_QUEUED_ILM, "  currently queued ilm: msg_id: %Mmsg_type, local_para_ptr: %x (ref_count:%d), peer_buff_ptr: %x (ref_count:%d)")
TRC_MSG(RAT_TCM_PRINT_POSSIBLE_MEMORY_LEAK_WARNING, "possible memory leak for msg_id: %Mmsg_type, local_para_ptr: %x (ref_count:%d), peer_buff_ptr: %x (ref_count:%d)")
TRC_MSG(RAT_TCM_DROP_QUEUED_ILM, "rat_tcm_drop_queued_ilm() msg_id: %Mmsg_type, local_para_ptr: %x (ref_count:%d), peer_buff_ptr: %x (ref_count:%d)")
TRC_MSG(RAT_TCM_DEREFERENCE_ILM_LOCAL, "rat_tcm_deference_ilm_local_para_and_peer_buffer(): local_para_ptr: %x")
TRC_MSG(RAT_TCM_DEREFERENCE_ILM_PEER, "rat_tcm_deference_ilm_local_para_and_peer_buffer(): peer_buff_ptr: %x")
TRC_MSG(RAT_TCM_JUDGE_RELAY_ILM_TYPE, "rat_tcm_judge_relay_ilm_type(%Mmsg_type, %Mmodule_type) result: %Mrat_tcm_incomming_ilm_type_enum")




END_TRACE_MAP(MOD_RAT_TCM)

#endif /* _RAT_TCM_TRC_H */

