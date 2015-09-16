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
 *	rac_others.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for miscellious functions.
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

#ifndef  _RAC_OTHERS_H
#define  _RAC_OTHERS_H

#include "kal_general_types.h"
#include "stack_config.h"
#include "stack_msgs.h"

#include "ps_public_enum.h"
#include "nvram_enums.h"
#include "l4crac_enums.h"

#include "mcd_l3_inc_struct.h"
#include "l3_inc_local.h"
#include "l3_inc_enums.h"

#include "rac_defs.h"

extern void rac_send_ilm(module_type dest_mod,
                         sap_type     sap_id,
                        msg_type msg_id,
                        local_para_struct *local_para_ptr);

extern void rac_read_from_nvrm(nvram_lid_enum nvram_id);
extern void rac_read_from_nvrm_svn(void);
extern kal_uint16 rac_get_nvram_record_id(void);

extern void rac_send_reg_cnf(mm_cause_enum cause);

/* mtk01778, 2007/07/31: Vary the function interface to pass parameter pointer instead of parameter value.
   This is due to passing parameter value will increase the RAC stack size. For example,
   if we receive GMMREG_PLMN_LIST_STOP_CNF triggering by timeout, we need to pass a fake plmn list
   (temp_plmn_list) to this function. That will enlarge RAC stack size with more than 224 bytes (32*7). { */
extern void rac_send_plmn_list_cnf(rac_plmn_list_struct *plmn_list, l4c_rac_response_enum response, mm_cause_enum cause, kal_uint8 num_of_hplmn);
/* } mtk01778, 2007/07/31 */
extern void rac_send_plmn_list_stop_cnf(void);

extern void rac_cmm_send_dereg_cnf(void);
extern void rac_send_plmn_search_cnf(l4c_rac_response_enum gsm_status, mm_cause_enum cause);
extern void rac_send_set_band_cnf(l4c_rac_response_enum response, l4c_source_id_enum src_id);

extern void rac_send_set_prefer_rat_cnf(kal_bool result, l4c_source_id_enum src_id);
extern void rac_send_set_rat_mode_cnf(kal_bool result, mm_cause_enum cause);
#ifdef __UE_EFOPLMN__
extern void rac_send_ue_oplmn_update(kal_bool is_update_needed, kal_uint16 no_oplmn_entry, kal_uint8 *oplmn_data);
#endif
void rac_abnormal_assert(void);

extern void rac_send_ps_reg_cnf(l4c_rac_gprs_status_enum response);
extern void rac_send_reg_ind(domain_id_enum service, rac_send_reg_ind_enum send_reg_ind, mm_cause_enum cause);
extern void rac_cmm_send_reg_ind();

/*extern void rac_send_nw_info_ind(void); */ /* Ripple: Remove this function */

//Tim
extern void rac_nwsel_send_attach_req(local_para_struct *local_para_ptr, domain_id_enum requested_service);
extern void rac_nwsel_send_detach_req(kal_bool is_poweroff);

extern void rac_send_attach_req(domain_id_enum service);
extern void rac_send_detach_req(domain_id_enum service,kal_bool is_poweroff);
#if 0
/* under construction !*/
#endif
extern void rac_copy_imei_imeisv(kal_uint8 *pdu_ptr);
extern void rac_copy_rac_preference(kal_uint8 *pdu_ptr);
extern void rac_save_preference(void);

extern void rac_copy_classmark1(kal_uint8 *pdu_ptr);
extern void rac_copy_classmark2(kal_uint8 *pdu_ptr);

extern void rac_set_action(rac_action_enum next_action);
extern kal_bool is_rac_activating(void);
extern void rac_send_ps_event_report_ind(mmi_event_enum event_id);

extern kal_bool rac_is_plmn_id_equal(plmn_id_struct *plmn1,plmn_id_struct *plmn2);
extern kal_bool rac_is_plmn_equal_to_cmcc(plmn_id_struct *plmn1);
extern kal_bool rac_is_plmn_id_rat_equal_to_current(plmn_id_rat_struct *plmn);
extern kal_bool rac_is_cell_info_equal(cell_info_struct *cell1, cell_info_struct *cell2);
extern kal_bool rac_is_cs_service_dereged(rac_mm_state_enum rac_mm_state);
extern kal_bool rac_is_ps_service_dereged(rac_gmm_state_enum rac_gmm_state);
#if 0
/* under construction !*/
#endif
extern void rac_reset_cell_info_rat(void);

extern void rac_make_imei(kal_uint8* imei);
extern void rac_make_imeisvn(kal_uint8* imeisvn);

#ifdef __SAT__
extern void rac_send_sat_location_info_ind(void);
extern kal_bool rac_current_equal_last_sat_location_info_ind(void);
#endif

#ifdef __GEMINI__
extern kal_bool	rac_is_gprs_always_attach_allowed(void);
#endif
#ifdef __HOMEZONE_SUPPORT__
extern void rac_send_cell_info_update_ind(void);
#endif
#ifdef __PS_SERVICE__
extern void rac_copy_ms_ra_cap(kal_uint8 *pdu_ptr,kal_uint16 length);
extern void rac_copy_ms_nw_cap(kal_uint8 *pdu_ptr,kal_uint16 length);
extern void rac_copy_drx_param(kal_uint8 *pdu_ptr);
#endif /* __PS_SERVICE__ */

extern void rac_start_retry_timer_hdlr(rac_timer_id_enum which_timer);
extern void rac_cancel_retry_timer_hdlr(rac_timer_id_enum which_timer);
extern void rac_start_timer_hdlr(rac_timer_id_enum which_timer);
extern void rac_cancel_timer(rac_timer_id_enum which_timer);
extern void rac_retry_plmn_search_timeout_hdlr(void);
extern void rac_retry_plmn_list_timeout_hdlr(void);

extern l4c_rac_response_enum rac_get_gsm_status(void);
extern reg_state_enum rac_get_gsm_state(void);
extern l4c_rac_gprs_status_enum rac_get_ps_status(void);
extern reg_state_enum rac_get_ps_state(void);


extern void rac_l4c_reg_req_cs(kal_bool *req_needed, kal_bool *response);

extern void update_service_to_be_reged(domain_id_enum service_type);
extern void update_service_to_be_dereged(domain_id_enum service_type);
extern void update_service_to_be(domain_id_enum *target_service, domain_id_enum service_type);


#ifdef __UMTS_FDD_MODE__
extern void rac_hardware_support_band_filter(kal_uint8 *umts_support_band); //mtk02475: UMTS band customization
#endif /* __UMTS_FDD_MODE__ */

#ifdef __RAC_GUARD_PLMN_LIST__
extern void rac_plmn_list_guard_timer_timeout_hdlr(void);
#endif

#ifdef __DYNAMIC_BAND_SEL__
extern void rac_send_set_band_req(rat_enum change_rat);
#endif

#ifdef __CSG_SUPPORT__
extern void rac_free_csg_list(rac_csg_list_struct *csg_list);
extern void rac_send_csg_list_cnf(rac_csg_list_struct *csg_list, l4c_rac_response_enum response, mm_cause_enum cause);
extern void rac_send_csg_list_stop_cnf(void);
extern void rac_retry_csg_list_timeout_hdlr(void);
extern void rac_start_csg_list_guard_timer_hdlr(void);
extern void rac_cancel_csg_list_guard_timer(void);
extern void rac_csg_list_guard_timer_timeout_hdlr(void);
extern kal_bool rac_is_cell_csg_info_equal(cell_info_struct *cell1, cell_info_struct *cell2);
#endif /* __CSG_SUPPORT__ */
//extern kal_bool is_rac_activating(void);

//Tim
#define RAC_SET_TARGET_RAT(rat)     (rac_ptr_global->target_rat_mode = (rat))
#define RAC_CLEAR_TARGET_RAT(rat)   (rac_ptr_global->target_rat_mode &= ~(rat))
#define RAC_ADD_TARGET_RAT(rat)     (rac_ptr_global->target_rat_mode |= (rat))

#ifdef __MTK_INTERNAL__
kal_uint32 rac_atoi(kal_uint8* asciiz);
#endif /* __MTK_INTERNAL__ */

extern void rac_send_to_all_target_rat();
extern void rac_callback_func_reg(rac_specific_mod_enum current_mod, void * func_ptr, rac_call_back_type_enum type);
extern void rac_callback_func_sync(rac_specific_mod_enum current_mod, kal_uint32 var, rac_call_back_type_enum type);

#ifdef __MODEM_EM_MODE__
/*****************************************************************************
 * FUNCTION
 *  rac_send_em_msg
 *
 * DESCRIPTION
 *  send MSG_ID_EM_RAC_INFO_IND for EM log
 *
 * PARAMETERS
 *  none
 *
 * RETURNS
 *  none
 *
 * GLOBALS AFFECTED
 *  none
 *
 *****************************************************************************/
void rac_send_em_msg();
#endif /* __MODEM_EM_MODE__ */

#ifdef __IMS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  rac_ims_reg_guard_timer_timeout_hdlr
 *
 * DESCRIPTION
 *  timeout handler of RAC_IMS_REG_GUARD_TIMER_ID
 *
 * PARAMETERS
 *  none
 *
 * RETURNS
 *  none
 *
 * GLOBALS AFFECTED
 *  none
 *
 *****************************************************************************/
void rac_ims_reg_guard_timer_timeout_hdlr(void);
#endif /* __IMS_SUPPORT__ */

#if defined(__LTE_RAT__)
/*****************************************************************************
 * FUNCTION
 *  rac_update_last_domain
 *
 * DESCRIPTION
 *  this function updates last_domain_in_attach_req
 *
 * PARAMETERS
 *  none
 *
 * RETURNS
 *  none
 *
 * GLOBALS AFFECTED
 *  special handling
 *
 *****************************************************************************/
void rac_update_last_domain(domain_id_enum service, kal_bool is_detach);
#endif /* __LTE_RAT__ */

#endif /* _RAC_OTHERS_H */


