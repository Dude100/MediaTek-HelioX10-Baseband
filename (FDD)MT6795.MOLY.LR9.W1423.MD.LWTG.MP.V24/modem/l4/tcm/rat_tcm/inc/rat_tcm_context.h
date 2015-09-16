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
 * RAT_TCM_CONTEXT.H
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   RAT_TCM module context h file
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


#ifndef _RAT_TCM_CONTEXT_H_
#define _RAT_TCM_CONTEXT_H_

#include "kal_public_defs.h"

#include "rat_tcm_enums.h"
#include "rat_tcm_defines.h"

// when interRAT is ongoing (23G4 or 4G23), upper layer request needed to be queued until interRAT finish
typedef struct rat_tcm_req_queue_for_single_sib_struct {
    ilm_struct act_req; // include TCM_PDP and TAF activate request
    ilm_struct deact_req;  // include TCM_PDP and TAF activate request
    ilm_struct mod_req; // TCM_PDP modify request

} rat_tcm_req_queue_for_single_sib_struct;

typedef struct rat_tcm_deact_triggered_flag_struct {
    kal_bool is_deact_by_user_deact;
    kal_bool is_deact_by_tft_conflict;
    kal_bool is_deact_by_enas_trigger;
    kal_bool is_deact_by_tft_validate_fail;
} rat_tcm_deact_triggered_flag_struct;

// context structure for a single context
typedef struct rat_tcm_session_info_block_struct {
    kal_uint8 context_id;      // Context identifier (cid)
    /**
     * Simply speaking, it means if context is active or inactive
     * User can be regarded as L4C (i.e, user_view == l4c_view)
     * - RAT_TCM_CONTEXT_USER_VIEW_INACTIVE
     *   1. event: rat_tcm_init
     *   2. event: ilm_type_deact_success
     *             ilm_type_deact_ind
     * - RAT_TCM_CONTEXT_USER_VIEW_ACTIVE
     *   1. event: ilm_type_act_success
     *             ilm_type_secondary_act_ind
     */
    rat_tcm_context_user_view_enum context_user_view_state;

    rat_tcm_req_progress_enum act_req_progress;
    rat_tcm_context_user_enum context_user;

    rat_tcm_req_progress_enum deact_req_progress;
    //rat_tcm_deact_triggerer_enum deact_req_triggerer;

    rat_tcm_req_progress_enum mod_req_progress;

    rat_tcm_req_queue_for_single_sib_struct app_req_queue; // when interRAT is ongoing (23G4 or 4G23), upper layer request needed to be queued

    kal_bool this_is_23g_mt_pdp_and_during_activating;

    rat_tcm_deact_triggered_flag_struct deact_triggered_flag;

    tcm_pdp_deact_reason_enum deact_triggered_by_enas_cause;

} rat_tcm_session_info_block_struct;

typedef struct rat_tcm_tst_inject_configuration_struct {
    kal_bool append_cid_2_modify_ind_embed_msg_to_next_msgs;
    kal_bool append_cid_3_deact_ind_embed_msg_to_next_msg;
    kal_bool append_cid_3_secondary_act_ind_embed_msg_to_next_msg;
} rat_tcm_tst_inject_configuration_struct;

// context structure for rat_tcm
typedef struct rat_tcm_context_struct {
    /** Context for each session (cid). */
    rat_tcm_session_info_block_struct rat_tcm_sib_tab[RAT_TCM_TOT_CONTEXT];

    rat_tcm_rat_state_enum rat_tcm_rat_state;

    kal_bool during_processing_embed_message;

    rat_tcm_tst_inject_configuration_struct tst_inj_config;

    //#ifdef __GEMINI__
    #if defined(__GEMINI__) || defined(__SGLTE__)
    /** Usage: 0x00: SIM1, 0x01: SIM2, etc. */
    kal_uint8 sim_interface;
    #endif /* __GEMINI__ */

    /* ALPS01294224
       If PS is in 2G, but 4G->3G RAT_CHANGE start, RAT_TCM not susupend UPCM,
       but then enter/leave flight mode, PS is not in 2G, When RAT_TCM receives RAT_CHANGE_COMPLETE_IND, 
       RAT_TCM sends RESUME_REQ to UPCM and UPCM assert.
       So need to check if the SUSPEND_REQ has been sent to UPCM */
    #ifdef __SGLTE__
    kal_bool is_suspend_req_sent_to_upcm;
    #endif /* __SGLTE__ */

    #ifdef __TCM_RAT_TCM_UT__
    kal_bool is_tft_validate_success_for_ut;
    #endif

} rat_tcm_context_struct;

#ifdef __SGLTE__
typedef struct {
    kal_uint8 context_id;
    rat_tcm_context_user_view_enum context_user_view_state;
    rat_tcm_context_user_enum context_user;

    rat_tcm_req_progress_enum deact_req_progress;
    rat_tcm_req_queue_for_single_sib_struct app_req_queue;
    rat_tcm_deact_triggered_flag_struct deact_triggered_flag;
} rat_tcm_context_transfer_info_struct;

typedef struct {
    LOCAL_PARA_HDR
    rat_enum source_rat;
    rat_enum target_rat;
    kal_uint8 total_transfer_number;
    rat_tcm_context_transfer_info_struct rat_tcm_context_transfer_tab[RAT_TCM_TOT_CONTEXT];
} rat_tcm_context_transfer_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool result;
} rat_tcm_context_transfer_cnf_struct;
#endif /* __SGLTE__ */


//#ifdef __GEMINI__
#if defined(__GEMINI__) || defined(__SGLTE__)
extern void rat_tcm_context_selection(kal_uint8 sim_interface);
#endif // ~ #ifdef __GEMINI__

extern void rat_tcm_change_rat_state(rat_tcm_rat_state_enum new_state);
extern void rat_tcm_change_during_processing_embed_message_state(kal_bool new_state);
extern void rat_tcm_change_sib_act_req_progress_state(kal_uint8 context_num, rat_tcm_req_progress_enum new_state);
extern void rat_tcm_change_sib_deact_req_progress_state(kal_uint8 context_num, rat_tcm_req_progress_enum new_state);
extern void rat_tcm_change_sib_mod_req_progress_state(kal_uint8 context_num, rat_tcm_req_progress_enum new_state);
extern void rat_tcm_change_sib_context_user_view_state(kal_uint8 context_num, rat_tcm_context_user_view_enum new_state);
//extern void rat_tcm_change_sib_context_deact_req_triggerer(kal_uint8 context_num, rat_tcm_deact_triggerer_enum new_triggerer);
extern void rat_tcm_change_sib_context_user(kal_uint8 context_num, rat_tcm_context_user_enum new_context_user);
extern void rat_tcm_change_sib_this_is_23g_mt_pdp_and_during_activating(kal_uint8 context_num, kal_bool new_state);
extern kal_bool rat_tcm_is_valid_rat_state_change(rat_tcm_rat_state_enum orig_state, rat_tcm_rat_state_enum new_state);
extern kal_bool rat_tcm_during_irat(void);
extern kal_bool rat_tcm_not_during_irat(void);
extern void rat_tcm_set_deact_triggered_flag(kal_uint8 context_num, rat_tcm_deact_triggerer_enum deact_trigger, kal_bool new_state);
extern kal_bool rat_tcm_get_deact_triggered_flag(kal_uint8 context_num, rat_tcm_deact_triggerer_enum deact_trigger);
extern void rat_tcm_clean_deact_triggered_flag(kal_uint8 context_num);
extern void rat_tcm_update_queued_deact_req_deact_reason(kal_uint8 context_num);
extern tcm_pdp_deact_reason_enum rat_tcm_select_deact_reason(kal_uint8 context_num);


#ifndef __MTK_TARGET__
void rat_tcm_check_context_consistency(void);
#endif // ~ #ifndef __MTK_TARGET__

#ifdef __SGLTE__
void rat_tcm_check_context_when_ps_change_complete(void);
#endif /* __SGLTE__ */

//#ifndef __GEMINI__
//extern rat_tcm_context_struct rat_tcm_context;
//extern rat_tcm_context_struct *rat_tcm_ptr_g;
//#else
//extern rat_tcm_context_struct rat_tcm_context[MOD_RAT_TCM_TOTAL_SIM];
//extern rat_tcm_context_struct *rat_tcm_ptr_g;
//#endif

//#ifndef __GEMINI__
#if defined(__GEMINI__) || defined(__SGLTE__)
extern rat_tcm_context_struct rat_tcm_context[MOD_RAT_TCM_TOTAL_SIM];
extern rat_tcm_context_struct *rat_tcm_ptr_g;
#else
extern rat_tcm_context_struct rat_tcm_context;
extern rat_tcm_context_struct *rat_tcm_ptr_g;
#endif


#endif /* _RAT_TCM_CONTEXT_H_ */
