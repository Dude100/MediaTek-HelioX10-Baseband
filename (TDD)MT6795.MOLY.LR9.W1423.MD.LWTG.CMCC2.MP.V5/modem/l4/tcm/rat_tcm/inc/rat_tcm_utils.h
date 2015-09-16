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
 * RAT_TCM_UTILS.H
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   RAT_TCM module utility h file
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


#ifndef _RAT_TCM_UTILS_H_
#define _RAT_TCM_UTILS_H_

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"

#include "rat_tcm_trc.h"
#include "rat_tcm_enums.h"
#include "rat_tcm_defines.h"

extern rat_tcm_rat_state_enum rat_tcm_get_current_rat_when_rat_unknown(void);
extern rat_tcm_incomming_ilm_type_enum rat_tcm_judge_ilm_type(msg_type incomming_msg, module_type sender, local_para_struct *local_para_ptr);
extern rat_tcm_incomming_ilm_type_enum rat_tcm_judge_embedded_ilm_type(msg_type incomming_msg);
extern rat_tcm_incomming_ilm_type_enum rat_tcm_judge_relay_ilm_type(msg_type incomming_msg, module_type sender);
extern module_type rat_tcm_judge_msg_sender(module_type sender_module_id);
extern void rat_tcm_queue_an_ilm(kal_uint8 context_num, rat_tcm_incomming_ilm_type_enum ilm_type, ilm_struct *ilm_ptr);
extern void rat_tcm_print_all_queued_ilm(kal_uint8 context_num);
extern void rat_tcm_print_a_queued_ilm(ilm_struct *ilm_ptr);
extern void rat_tcm_print_possible_memory_leak_warning(ilm_struct *ilm_ptr);
extern void rat_tcm_drop_queued_ilm(kal_uint8 context_num, rat_tcm_queue_enum which_queue);
extern void rat_tcm_dereference_ilm_local_para_and_peer_buffer(ilm_struct *ilm_ptr);
extern void rat_tcm_copy_a_new_req_and_send_to_tcm(ilm_struct *ilm_ptr);
extern kal_bool rat_tcm_no_pending_act(kal_uint8 context_num);
extern kal_bool rat_tcm_no_pending_deact(kal_uint8 context_num);
extern kal_bool rat_tcm_no_pending_mod(kal_uint8 context_num);
extern void rat_tcm_print_embedded_message_on_catcher(ilm_struct *ilm_ptr);
extern kal_bool rat_tcm_irat_tftlib_tft_validate(kal_uint8 context_num, rat_type_enum target_rat);
extern kal_bool rat_tcm_ps_switch_tftlib_tft_validate(kal_uint8 context_num, rat_enum target_rat);
extern void rat_tcm_check_if_need_to_fake_embed_msg_to_current_ilm(ilm_struct *ilm_ptr);
extern void rat_tcm_tst_inject_string_handler(ilm_struct *ilm_ptr);

extern void rat_tcm_fill_new_deact_req_ilm_ptr(ilm_struct *ilm_ptr, local_para_struct * msg_ptr);
extern local_para_struct * rat_tcm_compose_tcm_pdp_activate_rej(kal_uint8 context_num, ps_cause_enum cause);
extern local_para_struct * rat_tcm_compose_tcm_pdp_deactivate_req(kal_uint8 context_num);
extern local_para_struct * rat_tcm_compose_tcm_pdp_deactivate_cnf(kal_uint8 context_num, l4c_result_enum result, ps_cause_enum cause);
extern local_para_struct * rat_tcm_compose_tcm_pdp_deactivate_ind(kal_uint8 context_num, ps_cause_enum cause, kal_uint8 primary_context_id);

#endif /* _RAT_TCM_UTILS_H_ */
