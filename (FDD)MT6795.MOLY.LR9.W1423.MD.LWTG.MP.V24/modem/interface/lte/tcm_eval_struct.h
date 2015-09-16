/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   tcm_eval_struct.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   message and common structure definition between TCM and EVAL module
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * 	ESM trigger bearer deactivate
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * 01 22 2013 roy.lin
 * removed!
 * Multimode interface re-architecture.
 *
 * removed!
 * removed!
 * [EVAL] Add EVAL related interfaces and common strust
 ****************************************************************************/


#ifndef  _TCM_EVAL_STRUCT_INC
#define  _TCM_EVAL_STRUCT_INC


#include "tcm_eval_enums.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "tcm2sm_struct.h"
#include "tftlib_common_struct.h"

/* Multimode */
#include "irat_common_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_enums.h"

#define MAX_CONCATE_DEDEBC_NUM          10
//#define MAX_BEARER_CTXT_NUM             11


/***** common structure definition *****/
typedef struct
{
    kal_uint8                   length; // TODO: Roy: rename to "protocol_id_num"
    config_option_struct        pco_list[MAX_NUM_CONFIG_OPTION_PACKETS];
} tcmesm_pco_struct;


typedef struct
{
    kal_uint8                   qci;
    kal_bool                    bit_rate_present;
    kal_bool                    bit_rate_ext_present;
    kal_bool                    bit_rate_ext2_present;
    kal_uint8                   ul_mbr;
    kal_uint8                   dl_mbr;
    kal_uint8                   ul_gbr;
    kal_uint8                   dl_gbr;
    kal_uint8                   ul_mbr_ext;
    kal_uint8                   dl_mbr_ext;
    kal_uint8                   ul_gbr_ext;
    kal_uint8                   dl_gbr_ext;
    kal_uint8                   ul_mbr_ext2;
    kal_uint8                   dl_mbr_ext2;
    kal_uint8                   ul_gbr_ext2;
    kal_uint8                   dl_gbr_ext2;
} eps_qos_struct;

typedef struct
{
    kal_bool                    ext_present;
    kal_bool                    ext2_present;
    kal_uint8                   dl_apn_ambr;
    kal_uint8                   dl_apn_ambr_ext;
    kal_uint8                   dl_apn_ambr_ext2;
    kal_uint8                   ul_apn_ambr;
    kal_uint8                   ul_apn_ambr_ext;
    kal_uint8                   ul_apn_ambr_ext2;

} eps_apn_ambr_struct;


typedef struct
{
    kal_uint8                   ebi;
    tcmesm_epsb_act_enum        epsb_action;
    bcm_enum                    bcm_info;    
    kal_bool                    eps_qos_present;
    eps_qos_struct              eps_qos;
    kal_bool                    r99_qos_present;
    qos_struct                  r99_qos;
    kal_bool                    apn_ambr_present;
    eps_apn_ambr_struct         apn_ambr;
    kal_bool                    tft_present;
    tft_info_struct             *tft;
    tcmesm_pco_struct           *pco;

} tcmesm_updated_epsb_info_struct;


/***** message structure definition *****/
typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8                   pti;
    kal_uint8                   cid;
    tcmesm_req_reason_enum      req_reason;
    eps_req_type_enum           req_type;
    eps_pdn_type_enum           pdn_type;
    kal_bool                    pco_cipher_needed;
    apn_struct                  apn;
    tcmesm_pco_struct           *pco;
    
} esmreg_pdn_conn_est_req_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8                   pti;
    kal_uint8                   linked_ebi;
    kal_uint8                   cid;
    eps_qos_struct              eps_qos;
    tft_info_struct             *tft;
    tcmesm_pco_struct           *pco;
    
} esmreg_bearer_rsc_alloc_req_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8                   pti;
    kal_uint8                   ebi;
    kal_bool                    eps_qos_present;
    eps_qos_struct              eps_qos;
    tft_info_struct             *tft;
    tcmesm_pco_struct           *pco;
    
} esmreg_bearer_rsc_mod_req_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8                   pti;
    kal_uint8                   ebi;
    kal_uint8                   cid;
    tcmesm_req_reason_enum      req_reason;
    tcm_pdp_deact_reason_enum   deact_reason;
    tft_info_struct             *tft;
    tcmesm_pco_struct           *pco;
    
} esmreg_epsb_deact_req_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint16                  seq_id;

} esmreg_pdn_conn_est_rsp_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint16                  seq_id;

} esmreg_pdn_conn_update_rsp_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8                   pti;
    ps_cause_enum               failure_cause;
    tcmesm_pco_struct           *pco;

} esmreg_pdn_conn_est_rej_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8                   pti;
    ps_cause_enum               failure_cause;
    tcmesm_pco_struct           *pco;

} esmreg_bearer_rsc_alloc_rej_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8                   pti;
    ps_cause_enum               failure_cause;
    tcmesm_pco_struct           *pco;

} esmreg_bearer_rsc_mod_rej_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8                   pti;
    ps_cause_enum               failure_cause;
    tcmesm_pco_struct           *pco;

} esmreg_epsb_deact_rej_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8                       pti;
    kal_uint8                       linked_ebi;
    kal_uint16                      seq_id;
    apn_struct                      apn;
    ip_addr_struct                  ip_addr;
    kal_bool                        r99_qos_present;
    qos_struct                      r99_qos;
    eps_qos_struct                  eps_qos;
    kal_bool                        apn_ambr_present;
    eps_apn_ambr_struct             apn_ambr;
    kal_bool                        addr_type_limit_cause_present;
    ps_cause_enum                   addr_type_limit_cause;
    tcmesm_pco_struct               *pco;
    kal_uint8                       act_ded_epsb_num;
    tcmesm_updated_epsb_info_struct act_ded_epsb_info[MAX_CONCATE_DEDEBC_NUM];
    bcm_enum                        bcm_info;

} esmreg_pdn_conn_est_ind_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8                       pti;
    kal_uint8                       linked_ebi;
    kal_uint16                      seq_id;
    tcmesm_proc_result_enum         proc_result;
    tcmesm_updated_epsb_info_struct nw_res_epsb_info;
    kal_uint8                       nw_req_epsb_num;
    tcmesm_updated_epsb_info_struct nw_req_epsb_info[MAX_BEARER_CTXT_NUM];

} esmreg_pdn_conn_update_ind_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8                       pti;
    kal_uint8                       ebi;
    ps_cause_enum                   deact_cause;
    tcmesm_pco_struct               *pco;

} esmreg_epsb_deact_ind_struct;


/***** interRAT message structure *****/
typedef struct 
{
    LOCAL_PARA_HDR
    irat_type_enum irat_type;
    rat_type_enum source_rat;
    rat_type_enum target_rat;
    irat_result_enum irat_result;

} esmreg_rat_change_complete_ind_struct;

#ifdef __SGLTE__
typedef struct
{
    LOCAL_PARA_HDR
	rat_enum source_rat;
	rat_enum target_rat;
	kal_bool result;
} esmreg_ps_switch_complete_ind_struct;
#endif


typedef struct
{

    LOCAL_PARA_HDR
    kal_uint8                     ebi;
    tcm_pdp_deact_reason_enum     deact_reason;
} esmreg_ps_init_bearer_deact_ind_struct;

#if 0 /*(!defined(__EVAL_ENABLE__)) && (!defined(__ESM_ENABLE__))*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* no __EVAL_ENABLE__ */

#endif   /* ----- #ifndef _TCM_EVAL_STRUCT_INC ----- */

