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
 * removed!
 *
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _TCM_ETCM_UTILITY_H_
#define _TCM_ETCM_UTILITY_H_


#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "tcm_context.h"

/*etcm headers */
#include "tcm_etcm_def.h"
#include "tcm_etcm_cid.h"
#include "tcm_upcm_struct.h"

/* PPP Dial-up */
#include "ppp2tcm_struct.h"

#if __EVAL_UT__
#include "eval_ut.h"
#endif

typedef struct {
    kal_uint8 context_id;
    kal_uint8 nsapi;
    kal_uint8 AT_definition;
    pdp_context_type_enum context_type;
    kal_uint8 primary_context_id;
    /* APN consistency */
    kal_uint8 user_defined_apn_len;
    kal_uint8 user_defined_apn[MAX_APN_LEN];
    kal_uint8 nw_applied_apn_len;
    kal_uint8 nw_applied_apn[MAX_APN_LEN];
    pdp_addr_type_enum user_defined_pdp_type;
    pdp_addr_len_enum user_defined_pdp_len;
    kal_uint8 user_defined_pdp_addr[IPV4V6_ADDR_LEN];
    pdp_addr_type_enum nw_applied_pdp_type;
    pdp_addr_len_enum nw_applied_pdp_len;
    kal_uint8 nw_applied_pdp_addr[IPV4V6_ADDR_LEN];    
    //tcm_addr_scheme_enum addr_scheme;
    kal_bool is_cgtft_set;
    kal_bool is_eglnkpf_set;
    kal_bool is_egdelpf_set;
    kal_bool is_cgqreq_set;
    kal_bool is_cgqmin_set;
    tcm_eps_qos_struct eps_req_qos; /* (via +CGEQOS) */
    tcm_eps_qos_struct eps_neg_qos;
    tcm_fsm_state_enum fsm_state;
    tcm_sib_usage_enum is_sib_defined;
    kal_bool dns_present;
    kal_uint8 dns[MAX_PDP_ADDR_LEN];
    kal_bool dns2_present;
    kal_uint8 dns2[MAX_PDP_ADDR_LEN];
    tcm_request_type_enum request_type;
    #if (defined(__IPV4V6__) || defined (__IPV6__))
    kal_bool ipv6_dns1_present;
    kal_uint8 ipv6_dns1[IPV6_ADDR_LEN];
    kal_bool ipv6_dns2_present;
    kal_uint8 ipv6_dns2[IPV6_ADDR_LEN];
    #endif /* (defined(__IPV4V6__) || defined (__IPV6__)) */

    #ifdef __IMS_SUPPORT__
    kal_bool p_cscf_prim_addr_present;
    kal_uint8 p_cscf_prim_addr[IPV4_ADDR_LEN];
    kal_bool p_cscf_sec_addr_present;
    kal_uint8 p_cscf_sec_addr[IPV4_ADDR_LEN];
    #if (defined(__IPV4V6__) || defined (__IPV6__))
    kal_bool ipv6_p_cscf_prim_addr_present;
    kal_uint8 ipv6_p_cscf_prim_addr[IPV6_ADDR_LEN];
    kal_bool ipv6_p_cscf_sec_addr_present;
    kal_uint8 ipv6_p_cscf_sec_addr[IPV6_ADDR_LEN];
    #endif /* (defined(__IPV4V6__) || defined (__IPV6__)) */
    tcm_p_cscf_discovery_enum p_cscf_discovery;
    tcm_im_cn_signalling_enum user_defined_im_cn_signalling_flag;
    tcm_im_cn_signalling_enum nw_im_cn_signalling_flag;
    #endif /* __IMS_SUPPORT__ */
    
#if __ETCM_UT__
		kal_bool etcm_ut;
#endif
    
} etcm_em_single_pdp_context_struct;

typedef struct {
    LOCAL_PARA_HDR
    etcm_em_single_pdp_context_struct context[TCM_TOT_CONTEXT];
} etcm_em_dump_pdp_context_ind_struct;

/* Setting function */
kal_bool                etcm_cidSetApn          (etcm_cid_struct cid, apn_struct *apn);
#if (defined(__IPV4V6__) || defined (__IPV6__))
kal_bool                etcm_cidSetActCause2    (etcm_cid_struct cid, ps_cause_enum cause, kal_bool cause_present);
#endif
kal_bool                etcm_cidSetCause        (etcm_cid_struct cid, ps_cause_enum cause);
/* [check BCM] check BCM for pco */
kal_bool                etcm_cidSetPco          (etcm_cid_struct cid, tcmesm_pco_struct *pco, kal_bool check_bcm, kal_bool handle_empty_bcm);
kal_bool                etcm_cidSetEpsQos       (etcm_cid_struct cid, eps_qos_struct *qos, kal_bool eps_qos_present);
/* [Multimode phase 3] #2 - NW QOS translation 4G <-> 2/3G */
kal_bool                etcm_cidTransNegQos     (kal_bool r99_qos_present, qos_struct *r99_qos, kal_bool eps_qos_present, eps_qos_struct *eps_qos);
kal_bool                etcm_cidSetR99Qos       (etcm_cid_struct cid, qos_struct *r99_qos, kal_bool r99_qos_present);
kal_bool                etcm_cidSetPdpAddr      (etcm_cid_struct cid, ip_addr_struct *pdpAddr);
kal_bool                etcm_cidSetSecPdpAddr   (etcm_cid_struct cid);

/* [Multimode phase 3] #5 - BCM Handling */
#if defined (__UMTS_RAT__) || defined (__GSM_RAT__)
kal_bool                etcm_cidSetBcmInfo      (etcm_cid_struct cid, bcm_enum bcm_info);
#endif

/* query function */
kal_bool                etcm_cidGetApn          (etcm_cid_struct cid, apn_struct *apn);
kal_bool                etcm_cidGetPco          (etcm_cid_struct cid, tcmesm_pco_struct *pco);
kal_bool                etcm_cidGetEpsQos       (etcm_cid_struct cid, eps_qos_struct *qos);

kal_bool                etcm_cidGetCompdActTft  (etcm_cid_struct cid, tft_info_struct *tft);
kal_bool                etcm_cidGetCompdModTft  (etcm_cid_struct cid, tft_info_struct *tft);
kal_bool                etcm_cidGetCompdDeactTft(etcm_cid_struct cid, tft_info_struct *tft);

kal_bool                etcm_cidGetPdnType      (etcm_cid_struct cid, eps_pdn_type_enum  *pdnType);
kal_bool                etcm_cidGetUpcmIpAddr   (etcm_cid_struct cid, void *ip_addr_ptr);
kal_bool                etcm_cidGetInfoTrans    (etcm_cid_struct cid, kal_bool *infoTrans);

kal_bool                etcm_cidClearTFTandQosFlag  (etcm_cid_struct cid);
kal_bool                etcm_cidQosFlagisSet        (etcm_cid_struct cid);
kal_bool                etcm_cidTFTFlagisSet        (etcm_cid_struct cid);

kal_bool                etcm_cidLegacyActivateReqSetting  (void *msg);

tcm_fsm_state_enum      etcm_cidGetFsmState     (etcm_cid_struct cid);
kal_bool                etcm_cidSetFsmState     (etcm_cid_struct cid, tcm_fsm_state_enum next_state);
kal_bool                etcm_cidChkContextState (irat_result_enum irat_result);
kal_bool                etcm_cidSetUpcmIsActFlag();
tcm_request_type_enum   etcm_cidGetRequestType (etcm_cid_struct cid);
kal_bool 				etcm_cidSibIsAtDef		(etcm_cid_struct cid, kal_uint8 at_def);

/* PPP Dial-up */
kal_bool                    etcm_cidUpdatedSib          (mmi_ext_pdp_activate_ind_struct *msg_ptr);
tcm_activated_from_enum     etcm_cidGetActSrcFlag       (etcm_cid_struct cid);
kal_bool                    etcm_cidSetActSrcFlag       (etcm_cid_struct cid, tcm_activated_from_enum activated_from);
kal_bool                    etcm_cidSetConfigProtocol   (etcm_cid_struct cid, kal_uint8 config_protocol);
kal_bool                    etcm_cidSetCntxtFlag        (etcm_cid_struct cid, tcm_cntxt_valid_enum cntxt_flag);

/* EM Mode */
kal_bool etcm_emDumpPdpContext();

void etcm_check_context_consistency();

#endif
