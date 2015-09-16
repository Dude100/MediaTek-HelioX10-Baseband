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
 *	l4crac_func.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *   This file is intends for functional interface between L4C and RAC.
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
 * removed!
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

#ifndef  _L4CRAC_FUNC_H
#define  _L4CRAC_FUNC_H

#include "kal_general_types.h"
#include "mcd_l3_inc_struct.h"
#include "l3_inc_enums.h"
#ifdef __GEMINI_3G_SWITCH__
#include "ps_public_enum.h"
#include "sim_public_enum.h"
#endif /* __GEMINI_3G_SWITCH__ */
#include "l4crac_enums.h"
#ifdef __VOLTE_SUPPORT__
#include "ims_common_def.h"
#endif /* __VOLTE_SUPPORT__ */

/* 4.1 */
extern void l4crac_get_attach_status (kal_uint8 * cs_status,kal_uint8 * ps_status,kal_uint8 *service);
extern l4c_rac_gprs_status_enum l4crac_get_gprs_status(void); // MAUI_02316028, support L4C to get gprs status when RAB changed

/* 4.2 */
extern kal_uint8 l4crac_get_egprs_status (void); /* Erica 20070319: for edge status */
extern data_speed_support_enum l4crac_get_cell_data_speed_support (void); /* mtk02475: for edge & hspa status */
extern ms_mobile_class_enum l4crac_get_mobile_class (void);

/* 4.3 */
extern void l4crac_get_current_plmn(plmn_id_rat_struct  *current_plmn);

/* 4.5 */
extern kal_uint8 l4crac_get_preferred_gsm_band(void); //extern kal_uint8 l4crac_get_preferred_band(void);
#ifdef __UMTS_RAT__
extern void l4crac_get_preferred_umts_band(kal_uint8 *umts_fdd_band);  /* 3G band change */
#endif

extern plmn_selection_mode_enum l4crac_get_sel_mode(void);

extern void l4crac_set_sel_mode(plmn_selection_mode_enum mode);

extern kal_bool l4crac_get_imei(kal_uint8 *imei_bcd, kal_uint8 *imei_svn_bcd);

extern kal_bool l4crac_test_mobile_class (kal_uint8 const ** buffer);

extern kal_bool l4crac_set_gprs_follow_on_request (kal_bool is_turn_on);

extern rat_enum l4crac_get_rat_mode(void);

extern kal_bool l4crac_set_rat_mode(rat_enum rat_mode);

extern rat_enum l4crac_get_prefer_rat(void);

extern kal_bool l4crac_update_auto_attach(kal_bool auto_attach);

extern kal_bool l4crac_get_auto_attach(void);

extern kal_bool l4crac_set_auto_attach(kal_bool auto_attach, kal_bool is_pdp_activate);

extern kal_bool l4crac_set_auto_attach_setting(kal_bool auto_attach);

extern kal_bool l4crac_save_auto_attach_context(kal_bool auto_attach);

extern kal_bool l4crac_set_irat_preference(rat_enum preferred_rat);

extern kal_bool l4crac_cancel_retry_action(void);

extern kal_bool l4crac_is_deregistered(void);

extern rat_enum l4crac_get_irat_preference(void);

#ifdef __MONITOR_PAGE_DURING_TRANSFER__
#if defined(__GSM_RAT__) || defined(__UMTS_RAT__)
extern gprs_transfer_preference_enum l4crac_get_gprs_transfer_preference(void);
extern void l4crac_set_gprs_transfer_preference(gprs_transfer_preference_enum transfer_perference);
#endif /* defined(__GSM_RAT__) || defined(__UMTS_RAT__) */
#endif

#ifdef __PLMN_LIST_PREF_SUPPORT__
extern plmn_list_preference_enum l4crac_get_plmn_list_preference(void);
extern void l4crac_set_plmn_list_preference(plmn_list_preference_enum preference);
#endif /* __PLMN_LIST_PREF_SUPPORT__ */

//#ifdef __HSPA_PREFERENCE_SETTING__
void l4crac_set_hspa_preference(hspa_preference_enum hspa_preference);
hspa_preference_enum l4crac_get_hspa_preference(void);
//#endif /* __HSPA_PREFERENCE_SETTING__ */

extern rat_enum l4crac_get_current_rat(void); //mtk02475: for ECC retry other RAT feature
extern rat_enum l4crac_get_nvram_rat_mode(void); //mtk02475: for ECC retry other RAT feature
#ifdef __GEMINI_3G_SWITCH__
extern void l4crac_update_nvram_rat_mode(l4c_rat_enum nvram_rat_mode, sim_interface_enum sim_id); //mtk02475: for 3G switchable feature
#endif /* __GEMINI_3G_SWITCH__ */
//mtk02475: for AT%CAMP, L4C need to query current CS domain service status
extern l4c_rac_response_enum l4crac_get_gsm_status(void); //rx_level need

extern kal_bool l4crac_is_on_hplmn(void); //mtk02475: for EHPLMN, modem will provide the information of roaming

#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
extern kal_bool l4crac_get_peer_gprs_transfer_preference(void);
extern void l4crac_set_peer_gprs_transfer_preference(kal_bool peer_transfer_perference);
#endif

extern kal_uint16 l4crac_get_rnc_id(void);

#ifdef __CSG_SUPPORT__
//mtk02475: for Rel8 CSG autonomous search
extern kal_bool l4crac_get_csg_auto_search_preference(void);
extern void l4crac_set_csg_auto_search_preference(kal_bool preference);
extern kal_bool l4crac_get_csg_info(csg_info_struct *csg_info);
#endif /* __CSG_SUPPORT__ */

#ifdef __DYNAMIC_ROAMING_SUPPORT__
extern kal_bool l4crac_get_roaming_mode(void);
#endif

#ifdef __LTE_RAT__
/*****************************************************************************
 * FUNCTION
 *  l4crac_get_ue_mode
 *
 * DESCRIPTION
 *  get the current UE mode of operation
 *
 * PARAMETERS
 *  runtime_ue_mode_ptr [OUT]   runtime ue mode
 *  nvram_ue_mode_ptr   [OUT]   nvram ue mode
 *
 * RETURNS
 *  KAL_TRUE        - success
 *  KAL_FALSE       - failure
 *
 * GLOBALS AFFECTED
 *  none
 *
 *****************************************************************************/
kal_bool l4crac_get_ue_mode(ue_mode_enum *runtime_ue_mode_ptr, ue_mode_enum *nvram_ue_mode_ptr);

/*****************************************************************************
 * FUNCTION
 *  l4crac_test_ue_mode
 *
 * DESCRIPTION
 *  get the supported UE mode of operation
 *
 * PARAMETERS
 *  is_basic    [IN]    if AT CMD is basic or not
 *                      basic - AT+CEMODE
 *                      exteneded - AT+EEMODE
 *  buffer      [OUT]   buffer pointer to pointer
 *
 * RETURNS
 *  KAL_TRUE        - success
 *  KAL_FALSE       - failure
 *
 * GLOBALS AFFECTED
 *  none
 *
 *****************************************************************************/
kal_bool l4crac_test_ue_mode(kal_bool is_basic, const kal_uint8 **buffer);

/*****************************************************************************
 * FUNCTION
 *  l4crac_get_sms_preference
 *
 * DESCRIPTION
 *  get the current SMS preference
 *
 * PARAMETERS
 *  sms_preference_ptr  [OUT]   SMS preference
 *
 * RETURNS
 *  KAL_TRUE        - success
 *  KAL_FALSE       - failure
 *
 * GLOBALS AFFECTED
 *  none
 *
 *****************************************************************************/
kal_bool l4crac_get_sms_preference(l4c_rac_sms_preference_enum *sms_preference_ptr);

/*****************************************************************************
 * FUNCTION
 *  l4crac_test_sms_preference
 *
 * DESCRIPTION
 *  get the supported SMS preference
 *
 * PARAMETERS
 *  buffer  [OUT]   buffer pointer to pointer
 *
 * RETURNS
 *  KAL_TRUE        - success
 *  KAL_FALSE       - failure
 *
 * GLOBALS AFFECTED
 *  none
 *
 *****************************************************************************/
kal_bool l4crac_test_sms_preference(const kal_uint8 **buffer);

/*****************************************************************************
 * FUNCTION
 *  l4crac_get_ue_usage_setting
 *
 * DESCRIPTION
 *  get the current UE's usage setting
 *
 * PARAMETERS
 *  ue_usage_setting_ptr    [OUT]   UE's usage setting
 *
 * RETURNS
 *  KAL_TRUE        - success
 *  KAL_FALSE       - failure
 *
 * GLOBALS AFFECTED
 *  none
 *
 *****************************************************************************/
kal_bool l4crac_get_ue_usage_setting(ue_usage_setting_enum *ue_usage_setting_ptr);

/*****************************************************************************
 * FUNCTION
 *  l4crac_test_ue_usage_setting
 *
 * DESCRIPTION
 *  get the supported UE's usage setting
 *
 * PARAMETERS
 *  buffer  [OUT]   buffer pointer to pointer
 *
 * RETURNS
 *  KAL_TRUE        - success
 *  KAL_FALSE       - failure
 *
 * GLOBALS AFFECTED
 *  none
 *
 *****************************************************************************/
kal_bool l4crac_test_ue_usage_setting(const kal_uint8 **buffer);

/*****************************************************************************
 * FUNCTION
 *  l4crac_get_ims_voice_availability
 *
 * DESCRIPTION
 *  get the current availability of IMS voice
 *
 * PARAMETERS
 *  ims_voice_availability_ptr  [OUT]   availability of IMS voice
 *
 * RETURNS
 *  KAL_TRUE        - success
 *  KAL_FALSE       - failure
 *
 * GLOBALS AFFECTED
 *  none
 *
 *****************************************************************************/
kal_bool l4crac_get_ims_voice_availability(kal_bool *ims_voice_availability_ptr);

/*****************************************************************************
 * FUNCTION
 *  l4crac_test_ims_voice_availability
 *
 * DESCRIPTION
 *  get the supported availability of IMS voice
 *
 * PARAMETERS
 *  buffer  [OUT]   buffer pointer to pointer
 *
 * RETURNS
 *  KAL_TRUE        - success
 *  KAL_FALSE       - failure
 *
 * GLOBALS AFFECTED
 *  none
 *
 *****************************************************************************/
kal_bool l4crac_test_ims_voice_availability(const kal_uint8 **buffer);

/*****************************************************************************
 * FUNCTION
 *  l4crac_get_ims_sms_availability
 *
 * DESCRIPTION
 *  get the current availability of IMS SMS
 *
 * PARAMETERS
 *  ims_voice_availability_ptr  [OUT]   availability of IMS SMS
 *
 * RETURNS
 *  KAL_TRUE        - success
 *  KAL_FALSE       - failure
 *
 * GLOBALS AFFECTED
 *  none
 *
 *****************************************************************************/
kal_bool l4crac_get_ims_sms_availability(kal_bool *ims_sms_availability_ptr);

/*****************************************************************************
 * FUNCTION
 *  l4crac_test_ims_sms_availability
 *
 * DESCRIPTION
 *  get the supported availability of IMS SMS
 *
 * PARAMETERS
 *  buffer  [OUT]   buffer pointer to pointer
 *
 * RETURNS
 *  KAL_TRUE        - success
 *  KAL_FALSE       - failure
 *
 * GLOBALS AFFECTED
 *  none
 *
 *****************************************************************************/
kal_bool l4crac_test_ims_sms_availability(const kal_uint8 **buffer);

#ifdef __VOLTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  l4crac_get_mm_ims_voice_termination
 *
 * DESCRIPTION
 *  get the support of mobile management for IMS voice termination
 *
 * PARAMETERS
 *  mm_ivt_ptr  [OUT]   MM IMS voice termination
 *
 * RETURNS
 *  KAL_TRUE        - success
 *  KAL_FALSE       - failure
 *
 * GLOBALS AFFECTED
 *  none
 *
 *****************************************************************************/
kal_bool l4crac_get_mm_ims_voice_termination(mm_ims_voice_termination *mm_ivt_ptr);
#endif /* __VOLTE_SUPPORT__ */

#endif /* __LTE_RAT__ */

/*****************************************************************************
 * FUNCTION
 *  l4crac_get_voice_domain_preference
 *
 * DESCRIPTION
 *  get the current voice domain preference
 *
 * PARAMETERS
 *  rat                         [IN]    indicate voice domain preference of UTRAN or E-UTRAN
 *  voice_domain_preference_ptr [OUT]   voice domain preference
 *
 * RETURNS
 *  KAL_TRUE        - success
 *  KAL_FALSE       - failure
 *
 * GLOBALS AFFECTED
 *  none
 *
 *****************************************************************************/
kal_bool l4crac_get_voice_domain_preference(rat_enum rat, l4_voice_domain_preference_enum *voice_domain_preference_ptr);

/*****************************************************************************
 * FUNCTION
 *  l4crac_test_voice_domain_preference
 *
 * DESCRIPTION
 *  get the supported voice domain preference
 *
 * PARAMETERS
 *  rat     [IN]    indicate voice domain preference of UTRAN or E-UTRAN
 *  buffer  [OUT]   buffer pointer to pointer
 *
 * RETURNS
 *  KAL_TRUE        - success
 *  KAL_FALSE       - failure
 *
 * GLOBALS AFFECTED
 *  none
 *
 *****************************************************************************/
kal_bool l4crac_test_voice_domain_preference(rat_enum rat, const kal_uint8 **buffer);

/*****************************************************************************
 * FUNCTION
 *  l4crac_send_attach_req
 *
 * DESCRIPTION
 *  force to send attach req to mm/emm
 *
 * PARAMETERS
 *  service [IN]    domain_id_enum to indicate domain_type
 *
 * RETURNS
 *  KAL_TRUE        - success
 *  KAL_FALSE       - failure
 *
 * GLOBALS AFFECTED
 *  none
 *
 *****************************************************************************/
kal_bool l4crac_send_attach_req(domain_id_enum service);

/*****************************************************************************
* FUNCTION
*  l4crac_set_ue_reattach_setting
* DESCRIPTION
*  Decide UE to stay EUTRAN or not when EUTRAN is disable
*
* PARAMETERS
*  is_user_ps_reattach: TRUE/FALSE
*
* RETURNS
*  none
* GLOBALS AFFECTED
*  none
*****************************************************************************/
kal_bool l4crac_set_ue_reattach_setting (kal_bool is_user_ps_reattach);

/*****************************************************************************
* FUNCTION
*  l4crac_get_ue_reattach_setting
* DESCRIPTION
*  Get the configure for UE stay EUTRAN or not when EUTRAN is disable
*
* PARAMETERS
*  none
*
* RETURNS
*  TRUE/FALSE
* GLOBALS AFFECTED
*  none
*****************************************************************************/
kal_bool l4crac_get_ue_reattach_setting (void);

/*****************************************************************************
* FUNCTION
*  l4crac_set_data_service_status
* DESCRIPTION
*  relay the user data connection setting to NWSEL
*
* PARAMETERS
*  status: on/off
*
* RETURNS
*  none
* GLOBALS AFFECTED
*  none
*****************************************************************************/
kal_bool l4crac_set_data_service_status(kal_bool status);

/*****************************************************************************
* FUNCTION
*  l4crac_is_ps_attach_always
* DESCRIPTION
*  reply auto_attach configure to L4
*
* PARAMETERS
*  none
*
* RETURNS
*  TRUE/FALSE
* GLOBALS AFFECTED
*  none
*****************************************************************************/
kal_bool l4crac_is_peer_ps_attach_always(kal_uint8 sim_interface);

#endif /* _L4CRAC_FUNC_H */

