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
 *	csmcc_utility.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for utility function declaration used in CSM(CC) module.
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

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _CSMCC_UTILITY_H
#define _CSMCC_UTILITY_H

//#include "kal_non_specific_general_types.h"
#include "csmcc_types.h"
#include "csmcc_common_enums.h"
#include "mncc_struct.h"
#include "mcd_l4_common.h"
#include "l4c2csm_cc_struct.h"
#include "csmcc_enums.h"
#include "ps2sat_struct.h"
#include "csm_data_enums.h"
#include "mcd_ss_parameters.h"
#include "kal_general_types.h"
#include "kal_public_api.h"


extern void csmcc_update_call_state(kal_uint8 call_id, 
                         csmcc_call_state_enum state);
                         
extern void csmcc_set_call_state(kal_uint8 call_id, csmcc_call_state_enum state);        

extern kal_bool csmcc_is_ccbs_invoked_call(kal_uint8 call_id);

extern kal_bool csmcc_is_any_call_exist(void);

extern kal_bool csmcc_is_the_only_call(kal_uint8 call_id);

extern void csmcc_attach_speech(void);

extern void csmcc_detach_speech(void);

/* MAUI_01643590 UK_FT_weird_sound, detach_ind should go prior than call_rel_ind */
extern void csmcc_check_if_detach_speech(kal_uint8 call_id);

extern csmcc_ret_t csmcc_alloc_call_context(kal_uint8* call_id_ptr);

extern void csmcc_reset_dtmf(csmcc_dtmf_struct *dtmf_ptr);

extern void csmcc_reset_inv_info(csmcc_inv_info_struct *inv_info_ptr);

extern void csmcc_reset_call_context(kal_uint8 call_id);

extern void csmcc_dealloc_call_context(kal_uint8 call_id);

extern csmcc_ret_t csmcc_find_call(csmcc_call_orig_enum orig,
                            kal_uint16 state,
                            kal_uint8 *call_id_ptr);

extern csmcc_ret_t csmcc_find_waiting_call(kal_uint8 *call_id_ptr);

extern kal_uint8 csmcc_find_call_id_from_ti(kal_uint8 ti);

#ifdef __CCBS_SUPPORT__
extern csmcc_ret_t csmcc_find_ccbs_call(csmcc_ccbs_status_enum ccbs_status,
                                        kal_uint8 *call_id_ptr);          
#endif                                  
extern csmcc_ret_t csmcc_find_other_call_to_be_accepted(kal_uint8 *accept_req,
                                                 kal_uint8 *accept_call_id);

extern csmcc_ret_t csmcc_find_in_call(kal_uint8 *call_id_ptr);

extern void csmcc_update_mo_call_context(mncc_setup_cnf_struct *setup_cnf_ptr);

extern void csmcc_start_dtmf_pause_timer(kal_uint8 call_id, kal_uint32 duration);

extern csmcc_ret_t csmcc_stop_auto_dtmf(kal_uint8 call_id);

extern csmcc_ret_t csmcc_send_auto_dtmf(kal_uint8 call_id);

extern void csmcc_start_rlc_timer(kal_uint8 call_id, kal_uint32 duration);

extern csmcc_ret_t csmcc_stop_rlc_timer(kal_uint8 call_id);

extern csmcc_ret_t csmcc_accept_mt_call(kal_uint8 call_id);

extern csmcc_ret_t csmcc_accept_ccbs_call(kal_uint8 call_id);

extern kal_bool csmcc_is_ts11_call(kal_uint8 call_id);

extern kal_uint8 csmcc_bcd_decode(kal_uint8 *bcd_num, 
                                  kal_uint8 *num, 
                                  kal_uint8 bcd_num_len);

extern kal_uint8 csmcc_bcd_encode(kal_uint8 *num, 
                                  kal_uint8 *bcd_num, 
                                  kal_uint8 num_len);

extern void csmcc_check_called_number(kal_uint8 call_id, l4_addr_bcd_struct *addr_bcd_ptr);

/*mtk01602, [MAUI_751970]*/
#ifdef __FWP_NC_LAI_INFO__  
extern void csmcc_insert_cell_lock_prefix(kal_uint8* prefix_ptr, kal_uint8 prefix_digit_count, l4_addr_bcd_struct *addr_bcd_ptr);
#endif /*__FWP_NC_LAI_INFO__*/

extern void csmcc_convert_bcd_dtmf_to_digit (kal_uint8 call_id, 
                                      kal_uint8 no_dtmf, kal_uint8 *dtmf);
                                      
extern void csmcc_fill_mo_call_context(kal_uint8 call_id, 
                  l4ccsm_cc_call_setup_req_struct *call_setup_req_ptr);

/* added for MAUI_01296840 */
extern void csmcc_fill_emergency_mo_call_context(kal_uint8 call_id, 
                  l4ccsm_cc_emergency_call_setup_req_struct *emergency_call_setup_req_ptr);

extern void csmcc_fill_mt_call_context(kal_uint8 call_id, 
                  mncc_setup_ind_struct *setup_ind_ptr);                  

extern csmcc_ret_t csmcc_prog_desc_hdlr(kal_uint8 call_id,
                                 csmcc_prog_desc_enum prog_desc);

extern kal_bool csmcc_is_allowed_accept_call(void);

extern kal_bool csmcc_is_allowed_setup_call(kal_bool full);

extern csmcc_ret_t csmcc_update_mpty_call_state(csmcc_call_state_enum call_state);

extern void csmcc_reset_cur_req(csmcc_req_enum cur_req);

extern void csmcc_reset_prev_req(csmcc_req_enum cur_req);

extern void csmcc_save_cur_req(csmcc_req_enum cur_req, 
                        kal_uint8 req_src_id,
                        kal_uint8 req_call_id);

extern void csmcc_save_prev_req(csmcc_req_enum prev_req, 
                        kal_uint8 prev_src_id,
                        kal_uint8 prev_req_call_id);
                        
extern void csmcc_update_cur_req(csmcc_req_enum cur_req, 
                          kal_uint8 req_src_id,
                          kal_uint8 req_call_id);
#ifdef __AOC_SUPPORT__
extern kal_bool csmcc_is_acm_exceed(void);
#endif/*__AOC_SUPPORT__*/
extern kal_bool csmcc_in_call_status(void);

#if (defined(__TCPIP_OVER_CSD__) && defined(__SATCE__))
extern void csmcc_compose_cbst_speed(kal_uint8 *speed);
extern void csmcc_compose_cbst_name(kal_uint8 *name);
#endif
#ifdef __SAT__

   extern kal_bool csmcc_is_emergency_num(kal_uint8 *num_ptr, kal_uint8 num_len);
   
   extern void csmcc_update_sat_call_context(kal_uint8 call_id,
                sat_call_ctrl_by_sim_cnf_struct *call_ctrl_cnf_ptr,
                peer_buff_struct *peer_buff_ptr);
            
   extern void csmcc_fill_sat_call_context(kal_uint8 call_id,
                l4ccsm_cc_sat_setup_req_struct *sat_setup_req_ptr,
                peer_buff_struct *peer_buff_ptr);
#endif
                
#if defined(__CSD_T__) || defined(__CSD_NT__)|| defined(__CSD_FAX__)
   extern kal_bool csmcc_csd_ur_mapping(kal_uint8 *csd_ur, kal_bool *isFR);                          
#endif /* __CSD_T__ || __CSD_NT__ */

#ifdef __CSD_T__
   extern csmcc_ret_t csmcc_activate_tdt_data(kal_uint8 call_type);
#endif /* __CSD_T__ */

#ifdef __CSD_NT__
   extern csmcc_ret_t csmcc_activate_rlp_data(kal_uint8 call_type);
#endif /* __CSD_NT__ */

#if defined(__CSD_T__) || defined(__CSD_NT__)

   extern csmcc_ret_t csmcc_activate_data(kal_uint8 call_type);
   extern csmcc_ret_t csmcc_deactivate_data(void);
   
#endif /* __CSD_T__ || __ CSD_NT__ */

#ifdef __CSD_FAX__
extern csmcc_ret_t csmcc_activate_fax(kal_uint8 call_id, CSD_FAX_DIRECTION_ENUM fax_direction);
extern csmcc_ret_t csmcc_deactivate_fax(void);
#endif

   extern void csmcc_disc_call(kal_uint8 call_id, kal_uint16 cause);

   extern void csmcc_form_l4c_rdn_addr(l4ccsm_cc_rdn_addr_struct *l4c_rdn_addr, 
                                    RemotePartyNumber *rdn_addr);       

   extern kal_uint8 csmcc_form_sat_cause(kal_uint8 *cause_ptr, kal_uint8 *sat_cause_ptr);
#ifdef __AOC_SUPPORT__
   extern csmcc_ret_t csmcc_find_other_aoc_call(kal_uint8 call_id);

   extern void csmcc_start_aoc_timer(kal_uint8 call_id, kal_uint32 duration);
   	
   extern csmcc_ret_t csmcc_stop_aoc_timer(kal_uint8 call_id);
#endif/*__AOC_SUPPORT__*/
#ifdef __VIDEO_CALL_SUPPORT__
csmcc_ret_t csmcc_activate_vt(kal_uint8 call_id);
csmcc_ret_t csmcc_deactivate_vt(kal_uint8 call_id, kal_uint8 call_end_type);
#endif

extern kal_uint8  csmcc_first_read_sim_flag(void);
#if defined(__GEMINI__) || defined(__SGLTE__)
extern kal_uint8 cc_get_csmcc_sim_interface(void);
#endif
#ifdef __CSMCC_CALLCONFIRM_TIMER__
extern csmcc_ret_t csmcc_stop_call_confirm_timer(kal_uint8 call_id);
#endif

#ifdef __IMS_SUPPORT__
extern csmcc_ret_t csmcc_update_srvcc_call_state(mncc_srvcc_transfer_cnf_struct *mncc_srvcc_transer_cnf_ptr);
#endif

#endif /* _CSMCC_UTILITY_H */


