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
 *	rac_hdlrs.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is defines the message handlers of rac.
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
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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

#ifndef _RAC_HDLRS_H
#define _RAC_HDLRS_H

#include "kal_public_defs.h"
#include "l3_inc_enums.h"

/*****************************/
/*      L4C Message          */
/*****************************/

extern void  rac_l4c_rfoff_req_handler(void);
extern void  rac_l4c_act_req_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void  rac_l4c_reg_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void  rac_l4c_dereg_req_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void  rac_l4c_plmn_list_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void  rac_l4c_plmn_search_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_l4c_plmn_list_stop_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rac_l4c_set_rat_mode_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_l4c_set_rat_mode_req_proc();

extern void  rac_l4c_set_roaming_mode_req_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

#ifdef __UE_EFOPLMN__
extern void  rac_l4c_set_ue_oplmn_update_req_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif

extern void rac_l4c_set_prefer_rat_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_l4c_set_preferred_band_req_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_l4c_ps_reg_req_msg_handler( local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr );

/*****************************/
/*      NVRAM Message        */
/*****************************/

extern void rac_nvram_read_cnf_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_nvram_read_ready_handler(rat_enum ready_rat, kal_bool is_common);

extern void rac_nvram_write_cnf_msg_handler( local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr );

/*****************************/
/*      MM Message           */
/*****************************/
extern void rac_rfoff_cnf_msg_handler(rat_enum target_rat, kal_bool is_nwsel);
extern void rac_attach_cnf_msg_handler(ilm_struct *ilm_ptr);
//extern void rac_e_mm_attach_cnf_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rac_detach_ind_msg_handler(ilm_struct *ilm_ptr);


extern void rac_send_set_rat_mode_req(rat_enum src_rat);
extern void rac_set_rat_mode_cnf_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr, rat_enum target_rat, kal_bool is_nwsel);


#if defined(__GSM_RAT__) || defined(__UMTS_RAT__)
extern mm_cause_enum rac_get_nw_reg_cause(mm_cause_enum cause, mm_cause_enum abnormal_lu_cause);
#endif /* defined(__GSM_RAT__) || defined(__UMTS_RAT__) */

#ifdef __DYNAMIC_ROAMING_SUPPORT__
extern void rac_mm_set_roaming_mode_cnf_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif

extern void  rac_nwsel_set_prefer_rat_cnf_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rac_l4c_class_chagne_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

#ifdef __HOMEZONE_SUPPORT__
extern void rac_rr_pkt_transfer_mode_ind_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif


#if defined(__GEMINI__) || defined(__SGLTE__)
extern void rac_l4c_sim_status_update_req_handler(ilm_struct *ilm_ptr); //20071211
#endif

#ifdef __GEMINI__
extern void rac_mm_search_normal_finish_ind_handler(ilm_struct *ilm_ptr);
extern void rac_mm_rr_service_status_ind_handler(ilm_struct *ilm_ptr);//20080217
#endif


#ifdef __SAT__
extern void rac_sat_imei_info_req_msg_handler(ilm_struct *ilm_ptr);
extern void rac_sat_time_zone_req_msg_handler(void);
#endif

#if defined(__FAST_DORMANCY__) || defined(__NO_PSDATA_SEND_SCRI__)
//mtk02475: for Fast Dormancy, allow upperlayer explicitly disconnect data channel
extern void rac_l4c_end_ps_data_session_req_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_mm_end_ps_data_session_cnf_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_mm_end_ps_data_session_ind_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif

#ifdef __CSG_SUPPORT__
//mtk02475: for Rel8 CSG feature
extern void rac_l4c_csg_list_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_l4c_csg_list_stop_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_nwsel_csg_list_cnf_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_nwsel_csg_list_stop_cnf_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif /* __CSG_SUPPORT__ */

/*****************************/
/*      NWSEL Message        */
/*****************************/
extern void rac_nwsel_plmn_search_cnf_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_nwsel_plmn_list_cnf_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_nwsel_set_rat_mode_cnf_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_nwsel_plmn_status_ind_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_nwsel_plmn_list_stop_cnf_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

/*****************************/
/*      MRS Message          */
/*****************************/
extern void rac_mrs_init_cnf_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);


/*****************************/
/*      L4 Message           */
/*****************************/
extern void rac_l4c_rat_change_start_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_l4c_rat_change_finish_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_forward_ilm(module_type dest_mod_id, sap_type sap_id, msg_type msg_id, local_para_struct *local_para_ptr);

#ifdef __MTK_INTERNAL__
void rac_process_tst_command(ilm_struct * ilm_ptr);
#endif /* __MTK_INTERNAL__ */

extern void rac_l4c_sim_ready_ind_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

void rac_em_config_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rac_l4c_set_recovery_search_timer_req_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_l4c_get_recovery_search_timer_req_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_nwsel_set_recovery_search_timer_cnf_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_nwsel_get_recovery_search_timer_cnf_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

#ifdef __SGLTE__
extern void rac_l4c_ps_switch_req_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rac_send_rat_mode_or_flight_mode_to_gas(rat_enum target_rat_mode);
#endif

#ifdef __MODEM_EM_MODE__
void rac_em_update_req_msg_handler(ilm_struct * ilm_ptr);
#endif /* __MODEM_EM_MODE__ */

#ifdef __VOLTE_SUPPORT__
void rac_l4c_ims_set_mm_voice_termination_req_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif /* __VOLTE_SUPPORT__ */

#ifdef __IMS_SUPPORT__
void rac_l4c_ims_set_voice_domain_preference_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
void rac_l4c_ims_reg_start_req_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
void rac_l4c_ims_config_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
void rac_l4c_ims_reg_status_update_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif /* __IMS_SUPPORT__ */


#ifdef __SGLTE_DSDS__
extern void rac_l4c_active_sim_ind_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif
extern kal_bool nas_is_display_hplmn(kal_uint8 simInterface, const plmn_id_struct *plmn);
#endif /* _RAC_HDLRS_H */


