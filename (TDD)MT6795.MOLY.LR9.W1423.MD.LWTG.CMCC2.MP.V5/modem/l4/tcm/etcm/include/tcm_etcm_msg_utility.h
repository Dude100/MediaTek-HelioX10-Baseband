
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
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _TCM_ETCM_MSG_UTILITY_H_
#define _TCM_ETCM_MSG_UTILITY_H_

#include "tcm_etcm.h"
#include "kal_general_types.h"
#include "tcm_context.h"
#include "tcm_check.h"
#include "tcm_send_msg.h"
#include "l4c2tcm_struct.h"
#include "tcm2l4c_struct.h"
#include "ppp2tcm_struct.h"
#include "tcm2ppp_struct.h"
#include "tcm_rattcm_struct.h"

/*etcm headers */
#include "tcm_etcm_msg_container.h"
#include "tcm_etcm_utility.h"
#include "tcm_etcm_def.h"
#include "tcm_etcm_cid.h"
#include "tcm_upcm_struct.h"
#include "tcm_eval_struct.h"

#if __EVAL_UT__
#include "eval_ut.h"
#endif

/* if duplicate, compiler will be error on switch case for same ID */
/* TODO: need to check the id is reach boundary !!*/
/* for target build warning fixed, change MSG_ID_EVAL_CODE_END to MSG_ID_EVAL_EMM_SET_RAT_MODE_CNF */
#define ETCM_XTRAK_BEARER_RSC_ALLOC_IND (MSG_ID_EVAL_EMM_SET_RAT_MODE_CNF + 1)
#define ETCM_XTRAK_BEARER_RSC_MOD_IND   (MSG_ID_EVAL_EMM_SET_RAT_MODE_CNF + 2)
#define ETCM_XTRAK_EPSB_DEACT_PREEMPT   (MSG_ID_EVAL_EMM_SET_RAT_MODE_CNF + 3)
#define ETCM_XTRAK_BEARER_RSC_ALLOC_REJ (MSG_ID_ESMREG_BEARER_RSC_ALLOC_REJ)
#define ETCM_XTRAK_BEARER_RSC_MOD_REJ   (MSG_ID_ESMREG_BEARER_RSC_MOD_REJ)

typedef esmreg_bearer_rsc_alloc_rej_struct etcm_xtrkRscAllocRej_struct;
typedef esmreg_bearer_rsc_mod_rej_struct etcm_xtrkRscModRej_struct;

kal_bool etcm_msgRecvRedirect         (msg_type msg_id, void *local_para_ptr, etcm_msgCont_struct *msgCont);
kal_bool etcm_msgConcatEpsbProcesOne  (etcm_msgCont_struct *cont, tcmesm_updated_epsb_info_struct *epsbInfo);
kal_bool etcm_msgConcatEpsbProces     (etcm_msgCont_struct *cont, kal_uint8 epsb_num, tcmesm_updated_epsb_info_struct *epsbInfoList);

kal_bool  etcm_msgTriggerDeactivate         (etcm_msgCont_struct *cont, tft_deact_bearer_list_struct *deactList);

/* input checking */
kal_bool  etcm_cidChkPdpActivateReq         (tcm_pdp_activate_req_struct *msg_ptr, ps_cause_enum *internal_failure_cause);
kal_bool  etcm_cidChkPdpModifyReq           (tcm_pdp_modify_req_struct *msg_ptr, ps_cause_enum *internal_failure_cause);
kal_bool  etcm_cidChkPdpDeactivateReq       (tcm_pdp_deactivate_req_struct *msg_ptr, ps_cause_enum *internal_failure_cause);
kal_bool  etcm_cidChkTafExtPdpActivateInd   (mmi_ext_pdp_activate_ind_struct *msg_ptr, ps_cause_enum *internal_failure_cause);
kal_bool  etcm_cidChkTafExtPdpDeactivateInd (mmi_ext_pdp_deactivate_ind_struct *msg_ptr, ps_cause_enum *internal_failure_cause);
kal_bool  etcm_cidChkTafExtEnterDataModeReq (etcm_cid_struct cid, ps_cause_enum *return_cause);

/* out-gen message */
tcm_pdp_activate_cnf_struct         *etcm_cidGenPdpActivateCnf      (etcm_cid_struct cid);
tcm_pdp_activate_rej_struct         *etcm_cidGenPdpActivateRej      (etcm_cid_struct cid, ps_cause_enum cause);
tcm_pdp_activate_rej_struct         *etcm_cidGenPdpActivateRejByReq (tcm_pdp_activate_req_struct *msg_ptr, ps_cause_enum cause);
kal_bool                            etcm_cidGenPdpActivateInd       (etcm_cid_struct cid, void *msg_ptr, etcm_ptiElm_struct *pti);
tcm_pdp_modify_cnf_struct           *etcm_cidGenPdpModifyCnf        (etcm_cid_struct cid, kal_bool tft_present, kal_bool eps_qos_present, kal_bool apn_ambr_present);
tcm_pdp_modify_rej_struct           *etcm_cidGenPdpModifyRejByReq   (tcm_pdp_modify_req_struct *msg_ptr, ps_cause_enum cause);
tcm_pdp_modify_rej_struct           *etcm_cidGenPdpModifyRej        (etcm_cid_struct cid, ps_cause_enum cause);
tcm_pdp_modify_ind_struct           *etcm_cidGenPdpModifyInd        (etcm_cid_struct cid, kal_bool tft_present, kal_bool eps_qos_present, kal_bool apn_ambr_present);
tcm_pdp_deactivate_cnf_struct       *etcm_cidGenPdpDeactivateCnf    (etcm_cid_struct cid, l4c_result_enum l4c_result, ps_cause_enum cause);
tcm_pdp_deactivate_ind_struct       *etcm_cidGenPdpDeactivateInd    (etcm_cid_struct cid, ps_cause_enum cause);
tcm_upcm_pf_update_req_struct       *etcm_cidGenUpcmPfUpdateReq     (void *parent, etcm_cid_struct cid, tft_info_struct *tftInfo, kal_bool tft_present, kal_bool isESM_mo);
tcm_upcm_bearer_act_req_struct      *etcm_cidGenUpcmActReq          (void *parent, etcm_cid_struct cid, tft_info_struct *tftInfo, kal_bool tft_present, kal_bool isESM_mo);
tcm_upcm_bearer_deact_req_struct    *etcm_cidGenUpcmDeactReq        (etcm_cid_struct cid);
mmi_ext_pdp_activate_rej_rsp_struct *etcm_cidGenTafExtActivateRejRspByInd   (mmi_ext_pdp_activate_ind_struct *msg_ptr, ps_cause_enum cause);
mmi_ext_pdp_activate_rej_rsp_struct *etcm_cidGenTafExtActivateRejRsp(etcm_cid_struct cid, ps_cause_enum cause);
mmi_ext_pdp_activate_ack_rsp_struct *etcm_cidGenTafExtActivateAckRsp(etcm_cid_struct cid, kal_uint8 config_option_len, config_option_struct *config_option);
mmi_ext_pdp_deactivate_req_struct   *etcm_cidGenTafExtDeactivateReq (etcm_cid_struct cid);
mmi_ext_pdp_deactivate_ack_rsp_struct           *etcm_cidGenTafExtDeactivateAckRsp      (etcm_cid_struct cid, l4c_result_enum ppp_result, ps_cause_enum cause);
tcm_rat_tcm_init_deactivate_context_ind_struct  *etcm_cidGenTftConflictTriggerDeact     (etcm_cid_struct cid, tcm_pdp_deact_reason_enum deact_reason);

kal_bool  etcm_msgCleanTft                  (tft_info_struct **tft);
kal_bool  etcm_msgCleanPco                  (tcmesm_pco_struct **pco);

kal_bool etcm_msgPsInitBearerDeactIndHdlr (etcm_msgCont_struct *cont, void *local_para_ptr) ;

#endif
