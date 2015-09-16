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
 *	rac_u_specific_hdlrs.h
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

#ifndef _RAC_UG_HDLRS_H
#define _RAC_UG_HDLRS_H

#include "kal_public_defs.h"
#include "l3_inc_enums.h"
#include "l4c2rac_struct.h"
#include "mm_mmi_enums.h"
#include "rac_defs.h"

kal_bool is_rac_gmm_state_att_req(rac_check_ps_reg_req_enum check_type);
kal_bool is_rac_gmm_state_null_dereg(void);
kal_bool is_rac_gmm_state_reg(void);
l4c_rac_gprs_status_enum rac_get_gprs_status(void);
reg_state_enum rac_get_gprs_state(void);

void rac_ug_read_from_nvrm();
void rac_ug_rfoff_req_msg_handler();
void rac_ug_mm_set_rat_mode_cnf_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
void rac_ug_nvram_read_cnf_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#if defined(__GSM_RAT__) || defined(__UMTS_RAT__)
void rac_ug_send_set_rat_mode_req(rat_enum target_rat, domain_id_enum detached_domain);
void rac_ug_send_attach_req(local_para_struct *local_para_ptr, domain_id_enum requested_service);
#endif /* defined(__GSM_RAT__) || defined(__UMTS_RAT__) */
void rac_ug_mm_attach_cnf_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
void rac_ug_mm_detach_ind_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
void rac_ug_send_attach_proc(domain_id_enum requested_service);
domain_id_enum rac_ug_get_service_domain(local_para_struct *local_para_ptr);
void rac_ug_send_detach_req(kal_bool is_poweroff);
void rac_ug_plmn_status_ind_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
void rac_mm_nw_info_ind_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
void rac_mm_nw_reject_ind_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
void rac_mm_cell_info_update_ind_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
kal_uint8 l4crac_get_preferred_gsm_band(void); //extern kal_uint8 l4crac_get_preferred_band(void);
/* 4.5 */
#ifdef __UMTS_RAT__
void l4crac_get_preferred_umts_band(kal_uint8 *umts_fdd_band);  /* 3G band change */
#endif
kal_uint16 l4crac_get_rac_prefer_nvram_ef(void);

kal_bool l4crac_is_deregistered(void);

#ifdef __MONITOR_PAGE_DURING_TRANSFER__
gprs_transfer_preference_enum l4crac_get_gprs_transfer_preference(void);
void l4crac_set_gprs_transfer_preference(gprs_transfer_preference_enum transfer_perference);
#endif

void rac_ug_plmn_search_req_msg_handler(l4crac_plmn_search_req_struct *sel_req);
void  rac_l4c_class_change_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

void rac_ug_update_gmm_state(proc_status_enum status, mm_cause_enum cause);
void rac_mm_dedicated_mode_ind_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
kal_bool rac_ug_ps_reg_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr, rac_check_ps_reg_req_enum check_type);
void rac_l4c_reg_req_ps(kal_bool *req_needed, kal_bool *response);
void rac_ug_set_preferred_band_req_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);


void rac_mm_cipher_ind_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr); /* Ripple add for cipher indicator */
#ifdef __REL5__
extern void rac_mm_nw_ecc_ind_msg_handler( ilm_struct *ilm_ptr );
#endif
void rac_mm_ps_service_info_ind_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

void rac_handle_class_change(ms_mobile_class_enum prev_ms_class);
void rac_send_class_change_cnf(void);

kal_bool rac_ug_is_cell_info_equal(cell_info_struct *cell1, cell_info_struct *cell2);

void rac_ug_sync_ps_state(kal_uint32 gmm_state);

#ifdef __SGLTE__
extern void rac_ug_ps_switch_suspend_cnf_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif

#ifdef __SAT__
#ifndef __SAT_LOWCOST_NW_DISABLE__
void rac_ug_get_sat_location_info(sat_location_info_ind_struct* loc_info);
#endif /* __SAT_LOWCOST_NW_DISABLE__ */
#endif /* __SAT__ */

void rac_ug_nw_feature_ind_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#ifdef __IMS_SUPPORT__
kal_bool rac_ug_set_ims_voice_domain_preference_req(l4_voice_domain_preference_enum user_vdp);
void rac_ug_set_ims_voice_availability_req(kal_bool is_ims_voice_available);
void rac_ug_set_ims_voice_availability_req_msg_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
void rac_ug_ims_config_req(kal_bool ims_support, ims_reg_service_enum service);
#endif /* __IMS_SUPPORT__ */
void rac_ug_sync_ps_cause(kal_uint32 emm_cause);

#endif /*end of _RAC_UG_HDLRS_H*/


