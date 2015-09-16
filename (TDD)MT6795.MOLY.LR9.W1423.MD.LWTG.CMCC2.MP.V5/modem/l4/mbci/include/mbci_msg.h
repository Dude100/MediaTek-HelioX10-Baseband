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
 *   mbci_msg.h
 *
 * Project:
 * --------
 *   MT6280
 *
 * Description:
 * ------------
 *   This file is intends for MBCI implementation.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef _MBCI_MSG_H
#define _MBCI_MSG_H

#include "kal_general_types.h"
#include "ps_public_struct.h"
#include "ps_public_enum.h"
#include "l4crac_enums.h"


extern void l4c_nw_cfun_state_mrsp(kal_uint16 src_id, kal_bool result);

extern void l4c_sim_general_mrsp(kal_uint16 src_id, kal_bool result);

extern void l4c_smu_exe_lock_mrsp(kal_uint16 src_id, kal_bool result, sim_chv_info_struct chv_info, smu_security_type_enum type);

extern void l4c_smu_exe_change_password_mrsp(kal_uint16 src_id, kal_bool result, kal_uint8 type, sim_chv_info_struct chv_info);

extern void l4c_nw_get_plmn_list_mrsp(kal_uint16 src_id, kal_bool result, kal_uint8 plmn_count, l4c_rat_plmn_info_struct *plmn_list);

extern void l4c_nw_exe_cops_mrsp(kal_uint8 src_id, l4c_rac_response_enum gsm_status, kal_uint32 cause);

extern void l4c_nw_exe_att_mrsp(kal_uint8 src_id, kal_bool result);

extern void l4c_ps_exe_deact_mrsp(kal_uint8 src_id, kal_bool result, kal_uint8 cid, kal_uint16 cause);

extern void l4c_ps_set_definition_mrsp(kal_uint8 src_id, kal_bool result);

extern void l4c_ps_set_config_option_mrsp(kal_uint8 src_id, kal_bool result);

extern void l4c_ps_exe_act_mrsp(kal_uint8 src_id, kal_bool result);

extern void l4c_ps_exe_enter_data_state_mrsp(kal_uint8 src_id, kal_bool result);

extern void l4c_ps_set_provision_context_mrsp(kal_uint8 src_id, kal_bool result);

extern void l4c_sms_set_profile_params_mrsp(kal_uint8 src_id, kal_bool result);

extern void l4c_sms_exe_post_msg_mrsp(kal_uint8 src_id, kal_bool result, kal_uint8 MessageRefernce);

extern void l4c_sms_exe_delete_msg_mrsp(kal_uint8 src_id, kal_bool result);

extern void l4c_sms_exe_read_msg_list_pdu_mrsp(kal_uint8 src_id, kal_bool result,
                                                kal_uint16 index,
                                                kal_uint16 next_index,
                                                kal_uint8 status,
                                                peer_buff_struct *data);

extern void l4c_sms_exe_read_msg_pdu_mrsp(kal_uint8 src_id, kal_bool result,
                                                kal_uint16 index,
                                                kal_uint8 status,
                                                peer_buff_struct *data);

extern void l4c_ss_ussd_mrsp(kal_uint16 src_id, kal_uint8 dcs, mbim_ussd_response_enum response, kal_uint8 *ussd_string, kal_uint8 ussd_string_length);

#endif /* _MBCI_INIT_H */

