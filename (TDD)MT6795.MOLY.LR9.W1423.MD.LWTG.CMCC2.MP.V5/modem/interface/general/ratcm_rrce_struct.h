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
 *   ratcm_rrce_struct.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log:$
 *
 * removed!
 * removed!
 * Merging 
 * 	//MOLY/Development_BRANCHES/LR9.W1423.MD.LWTG.MP.FPB.DEV/...
 * 	to //MOLY/BRANCHES_LR9/LR9.W1423.MD.LWTG.MP/...
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * 	re-check-in
 *
 * removed!
 * removed!
 * 	Back out changelist 591694
 *
 * removed!
 * removed!
 * [FDD][RRCE] Merge LTE Gemini to MOLY
 *
 * removed!
 * removed!
 * eAFR
 *
 * removed!
 * removed!
 * 	CC_DISCONNEC&Force Release Optimization Mobility Part.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * Network sharing compile option revise.
 *
 * removed!
 * removed!
 * Check-in interface.
 *
 * removed!
 * removed!
 * Part 2 - Other common files for Multimode
 * 
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * 11 09 2011 ryan.ou
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * 12 23 2010 jd.ni
 * removed!
 * .
 *
 * removed!
 * removed!
 * Integration change.
 *
 * removed!
 * removed!
 * [RATCM][RHR]Check in ratcm file in uas\interface
 *
 * removed!
 * removed!
 * [3G] Revise the handling of access control. (MAUI)
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
 * Add copyright header.
 ******************************************************************************/

#ifndef _RATCM_RRCE_STRUCT_H
#define _RATCM_RRCE_STRUCT_H

/* MAUI_02828210, redundant header removal */
#include "ratcm_rrce_enums.h"
#include "mcd_l3_inc_struct.h"
#include "ratcm_uas_struct.h"
//#include "app_ltlcom.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "l3_inc_enums.h"

//move LAC to ratcm_uas_struct.h since CSCE will also need it.
//typedef kal_uint16 LAC;
#if 0
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
#endif

//typedef kal_uint8 NAS_MUI;


#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
//UDC

typedef struct
{
   LOCAL_PARA_HDR

   kal_bool is_tmsi_lai_present;
   /*Note that bit 8 of tmsi[0] is MSB and bit 1 of tmsi[3] is LSB of TMSI */
   kal_uint8 tmsi[4];
   kal_bool is_lai_abnormal;  /* MAUI_01959495*/
   lai_struct   reg_lai;
   kal_bool  is_ptmsi_rai_present;
   /*Note that bit 8 of ptmsi[0] is MSB and bit 1 of ptmsi[3] is LSB of P-TMSI*/
   kal_uint8 ptmsi[4];
   kal_bool is_rai_abnormal;  /* MAUI_01959495 */
   rai_struct reg_rai;
   kal_uint8   PS_CNSpecificDRX_CLC;
} ratcm_rrce_paging_param_assign_req_struct ;

typedef struct
{
    LOCAL_PARA_HDR
    mmas_regn_status_enum   regn_status;
    kal_bool   PowerOff;
}ratcm_rrce_regn_status_update_req_struct;

typedef struct
{
   LOCAL_PARA_HDR

   RATCM_RRC_PagingCause pagingCause;
   /* Description: Identifies the type of core network domain. This an
      enumerated type (RRC_CN_DomainIdentity_cs_domain, RRC_CN_DomainIdentity_ps_domain). */
   domain_id_enum cn_DomainIdentity;
   ue_id_type_enum        pagingIdType;
} ratcm_rrce_page_ind_struct ;

/*2013/03/26, local release enhancement*/
typedef struct
{
   LOCAL_PARA_HDR

   RATCM_RRC_LocalReleaseType localReleaseType;
   kal_uint16 locally_released_PS_RAB_bitmap;
} ratcm_rrce_local_release_ind_struct;

typedef struct
{
   LOCAL_PARA_HDR
   
//   NAS_MUI                       MUI;
   kal_uint8                       MUI;
   gibi_tag_type                       gibiTag;   
   domain_id_enum         cnDomainID;
   RATCM_RRC_EstablishmentCause        cause;
   kal_bool                is_service_req;
#ifdef __R6_DSAC__  
   kal_bool                isDsacPresent;
   kal_uint16             selectedDsacInfo;
#endif
#if defined(__UMTS_FDD_MODE__) || defined(__TD_NETWORK_SHARING__)
   plmn_id_struct          selectedplmn;
#endif
#ifdef __PPACR_SUPPORT__
   ppac_checked_type_enum   PPACCheckedType;
   kal_uint16             selectedPPACInfo; //used by PPAC_LR_ALLOWED
#endif
#ifdef __LTE_RAT__  /* Ivy Ivy */
   kal_bool   is_csfb;
#endif /* __LTE_RAT__*/
} ratcm_rrce_conn_est_req_struct ;

typedef struct
{
   LOCAL_PARA_HDR

   domain_id_enum cnDomainID ;
   as_est_cnf_cause_enum   status;  /* status of the RRC connection */
   kal_bool   wait_gibi_flag;
   kal_bool  is_rrc_conn_already_existed;
} ratcm_rrce_conn_est_cnf_struct ;

typedef struct
{
   LOCAL_PARA_HDR
   
   //   NAS_MUI                       MUI;
   kal_uint8                       MUI;
   gibi_tag_type               gibiTag;   
   domain_id_enum cnDomainID ;
   DC_Priority           priority ;
   kal_bool                is_service_req;
} ratcm_rrce_data_transfer_req_struct ;

typedef struct
{
   LOCAL_PARA_HDR

   domain_id_enum cnDomainID ;
   /* This flag is used to inform RATCM that the integrity is applied on this NAS message. Note that at this time, 
   it is possible RRCE has not sent RATCM_RRCE_SECURITY_MODE_COMPLETE_IND.*/
   kal_bool   integrityApplied;
} ratcm_rrce_data_transfer_ind_struct ;

typedef struct
{
   LOCAL_PARA_HDR
   
   //   NAS_MUI                       MUI;
   kal_uint8                       MUI;
   DC_Status             status;
   domain_id_enum cnDomainID ;
   DC_Priority           priority ;
}ratcm_rrce_data_transfer_cnf_struct;

typedef struct
{
   LOCAL_PARA_HDR

   domain_id_enum cnDomainID ;
   as_rel_scope_enum       scope;
} ratcm_rrce_conn_rel_req_struct;

typedef struct
{
   LOCAL_PARA_HDR

   domain_id_enum cnDomainID ;
   RATCM_RRC_ReleaseCause      cause; /* cause of the connection release */
   kal_bool                 waitGibiFlag;
} ratcm_rrce_conn_rel_ind_struct;



typedef struct
{
   LOCAL_PARA_HDR

   domain_id_enum cnDomainID ;
   as_rel_scope_enum      scope;
   /* True means the signaling connection of this domain has been released successfully. 
   Otherwise, it means the release fails. Currently, it will report "failure" only during inter-RAT procedure. 
   RATCM should not resend the release of connection until the completion of inter-RAT procedure.*/
   kal_bool Is_successful;
   kal_bool  waitGibiFlag;
} ratcm_rrce_conn_rel_cnf_struct;

/*
typedef struct
{
   LOCAL_PARA_HDR

} ratcm_rrce_conn_loss_ind_struct;
*/

typedef struct
{
   LOCAL_PARA_HDR
   
   SRB_Priority          priority;
   domain_id_enum    cnDomainID;
}ratcm_rrce_rb_re_establishment_ind_struct;

typedef struct
{
   LOCAL_PARA_HDR

   SRB_Priority          priority;
   domain_id_enum    cnDomainID;
}ratcm_rrce_rb_re_establishment_rsp_struct;

typedef struct
{
   LOCAL_PARA_HDR

   kal_bool           newKeys;
   umts_security_key  security_key;
   kal_bool           is_power_on;
   kal_uint8          cksn;
} ratcm_rrce_security_mode_req_struct;

typedef struct
{
   LOCAL_PARA_HDR

   domain_id_enum cnDomainID;
   kal_bool          integrityEnabled;
   Ciphering_Status          cipheringStatus;
   kal_uint8 service_req_mui;
} ratcm_rrce_security_mode_complete_ind_struct;


typedef struct
{
   LOCAL_PARA_HDR

   domain_id_enum cnDomainID;
   Ciphering_Status  cipheringStatus;
} ratcm_rrce_security_mode_change_ind_struct;

typedef struct
{
   LOCAL_PARA_HDR
   
   kal_bool           cs_Domain_ResetKeys;
   kal_bool           ps_Domain_ResetKeys;
} ratcm_rrce_reset_keys_ind_struct;

/*
typedef struct
{
    LOCAL_PARA_HDR
}ratcm_rrce_cell_change_start_ind_struct;
*/

typedef struct
{
   LOCAL_PARA_HDR
} ratcm_rrce_force_rel_req_struct;


#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
typedef struct
{
   LOCAL_PARA_HDR

   kal_bool                 force_send_SCRI;
   end_session_cause_enum   cause;
} ratcm_rrce_end_ps_data_session_req_struct;

typedef struct
{
   LOCAL_PARA_HDR
   
   end_session_result_enum           result;
} ratcm_rrce_end_ps_data_session_cnf_struct;
#endif /* __NO_PSDATA_SEND_SCRI__ || __FAST_DORMANCY__ */

#if defined(__LTE_RAT__) && defined(__GEMINI__)
typedef struct
{
   LOCAL_PARA_HDR

   cs_status_enum  status;
} ratcm_rrce_cs_status_update_req_struct;
#endif

typedef struct
{
   LOCAL_PARA_HDR

   kal_bool is_pch_state;
} ratcm_rrce_rrc_state_ind_struct;

#endif /* _RATCM_RRCE_STRUCT_H */
