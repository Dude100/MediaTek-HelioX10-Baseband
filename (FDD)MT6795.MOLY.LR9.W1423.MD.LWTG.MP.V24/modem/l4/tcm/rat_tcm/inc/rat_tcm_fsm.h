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
 * RAT_TCM_FSM.H
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   RAT_TCM module fsm h file
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


#ifndef _RAT_TCM_FSM_H_
#define _RAT_TCM_FSM_H_

#include "kal_public_defs.h"
#include "irat_common_struct.h"

extern void rat_tcm_handler_for_pdp_fsm_msgs(rat_tcm_incomming_ilm_type_enum incomming_ilm_type, ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_relay_msgs(rat_tcm_incomming_ilm_type_enum incomming_ilm_type, ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_inter_rat_msgs(rat_tcm_incomming_ilm_type_enum incomming_ilm_type, ilm_struct *ilm_ptr);
#ifdef __SGLTE__
extern void rat_tcm_handler_for_ps_change_msgs(rat_tcm_incomming_ilm_type_enum incomming_ilm_type, ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_ps_change_complete(ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_context_transfer_req(ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_context_transfer_cnf(ilm_struct *ilm_ptr);
//extern void rat_tcm_fill_transferred_to_another_mode_context(rat_tcm_context_transfer_req_struct *rat_tcm_context_transfer_req_ptr);
#endif /* __SGLTE__ */
extern void rat_tcm_handler_for_mt_primary_pdp_initialization_msgs(rat_tcm_incomming_ilm_type_enum incomming_ilm_type, ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_start_up_msgs(rat_tcm_incomming_ilm_type_enum incomming_ilm_type, ilm_struct *ilm_ptr);

extern void rat_tcm_handler_for_rat_change_start(ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_rat_change_finish(ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_rat_change_complete(ilm_struct *ilm_ptr);

extern void rat_tcm_delete_pending_23g_mt_primary_pdp(void);
extern void rat_tcm_retry_failed_req_and_process_queued_req_during_irat(irat_result_enum irat_result, rat_type_enum target_rat);

#ifdef __SGLTE__
extern void rat_tcm_retry_failed_deact_req_during_ps_switch(rat_enum target_rat);
#endif /* __SGLTE__ */

extern void rat_tcm_handler_for_ilm_type_act_req(ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_ilm_type_deact_req(ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_ilm_type_mod_req(ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_ilm_type_act_success(ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_ilm_type_deact_success(ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_ilm_type_mod_success(ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_ilm_type_act_fail(ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_ilm_type_deact_fail(ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_ilm_type_mod_fail(ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_ilm_type_secondary_act_ind(ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_ilm_type_deact_ind(ilm_struct *ilm_ptr);
extern void rat_tcm_handler_for_ilm_type_mod_ind(ilm_struct *ilm_ptr);


#endif /* _RAT_TCM_FSM_H_ */
