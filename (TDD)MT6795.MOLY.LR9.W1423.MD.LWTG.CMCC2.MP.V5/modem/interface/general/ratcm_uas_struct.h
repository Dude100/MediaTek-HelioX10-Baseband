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
 *   ratcm_uas_struct.h
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
 * 	.
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Remove inactive code that use PLMN_Identity strcture to prevent definition conflicted
 *
 * removed!
 * removed!
 * .
 *
 * 05 31 2013 ye.yuan
 * removed!
 * <saved by Perforce>
 *
 * removed!
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
 * removed!
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
 * removed!
 * removed!
 * recover "the missing modification of [MAUI_03037536] inter-RAT revision "in MSBB merger in
 *
 * removed!
 * removed!
 * Remove the private header files
 *
 * removed!
 * removed!
 * .mege MSBB's "dbme, tools, uas_tdd 128 common" modification  into maui branch
 *
 * removed!
 * removed!
 * aligned ratcm_uas_sys_info_ind_struct's field order to FDD implementation
 *
 * removed!
 * removed!
 * add the ratcm_uas_struct.h to modem\interface
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Check in RHR for build error.
 *
 * removed!
 * removed!
 * RHR according to TK's suggestion table.
 *
 * removed!
 * removed!
 * RHR for interface with RRCE and RATCM.
 *
 * removed!
 * removed!
 * Code back to MAUI from 10A32MP_ASTRO.W1048.Tue.
 *
 * removed!
 * removed!
 * fix build error
 *
 * removed!
 * removed!
 * .
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
 * Code Synch to MAUI, 09A, A-GPS, 3G Gemini for W09.29
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

#ifndef _RATCM_UAS_STRUCT_H
#define _RATCM_UAS_STRUCT_H

/* MAUI_02828210, redundant header removal */
#include "ratcm_uas_enums.h"
#include "mcd_l3_inc_struct.h"
#include "kal_general_types.h"
#include "l3_inc_enums.h"
#include "kal_public_api.h"
#include "ps_public_enum.h"
#include "l3_inc_local.h"
#include "ps_public_struct.h"
#include "irat_common_struct.h"

typedef kal_uint16 LAC;
typedef kal_uint16 gibi_tag_type;
/*typedef kal_uint8 PLMN_Identity[MAX_PLMN_ID_DIGIT];*/
typedef kal_uint32 cell_identity_type;

typedef struct nas_sys_info_gsm_map_struct
{
   kal_uint8 numOctets;
   kal_uint8 stringData[8];
} nas_sys_info_gsm_map_struct;

typedef struct CN_DomainSysInfo
{
   /* Description: Identifies the type of core network domain. This an
      enumerated type (RRC_CN_DomainIdentity_cs_domain, RRC_CN_DomainIdentity_ps_domain). */
   domain_id_enum                cn_DomainIdentity;
   /* Description: NAS system information (GSM-MAP) This information
      element contains system information that belongs to the
      non-access stratum for a GSM-MAP type of PLMN. This information
      is transparent to RRC. It may contain either information
      specific to one CN domain (CS or PS) or information common for
      both CN domains (Ref: [25.331;10.3.1.9]).
      RRC_NAS_SystemInformationGSM_MAP information element description:
       - length   - Number of bytes
       - value[8] - Array of bytes (maximum is 8). */
   nas_sys_info_gsm_map_struct   cn_specificGSM_MAP_NAS_SysInfo;
} CN_DomainSysInfo;

typedef struct CN_DomainSysInfoList
{
   kal_uint8        count;
   CN_DomainSysInfo value[MAX_CN_DOMAIN];
} CN_DomainSysInfoList;

/* UMTS security keys data structure originally used by RATCM and RRCE.
 * Now it's reused in multimode development.
 */
typedef struct {
    domain_id_enum  cnDomainID;
    kal_uint8       umts_cipheringKey[CK_LEN];
    kal_uint8       umts_integrityKey[IK_LEN];
} umts_security_key;

typedef struct{
    kal_bool       is_valid;
    gibi_tag_type  gibi_tag; 
} gibiTag_info;

/****************************/
/* UGC_INFORMATION_BROADCAST */
/****************************/
/* Description: this operation consists in the broadcast from IF
 * toward User Equipment of some information in some geographical
 * area.
 *
 * a GC Information broadcast indication primitive is issued to the
 * NAS entity UE over the General Control (GC) SAP when the RRC layer
 * finds out that the non-access part of the system information has
 * been changed.
 *
 * This information is to be used by the User Equipment for instance
 * to choose among access points or to be taken into account during
 * initial access. The information can also be destinated to an
 * application.
 *
 * UGC Information broadcast is sent to the NAS whenever the UE, in idle mode,
 * has started camping on a cell, and has sufficient SIBs for a connection, or 
 * if the NAS data in SIB 1 changes.In addition NAS updates optionally contained
 * in Radio Bearer Setup, Active Set Update, etc. shall be reported using this 
 * primitive. The primitive is also used subsequently to an Inter-RAT cell re-
 * selection / change over or Inter-RAT handover to UMTS. In that case, the 
 * primitive may be issued with "additional info flag= FALSE" to indicate that 
 * no CN information is included.
 *
 * Note 1: GSM-MAP NAS contains LAC & RAC with the PLMN id and UTRAN cell id.
 * The NAS should be able to map UTRAN cell id and Location Area/Routing Area.
 *
 * Note 2: In connected mode, e.g. subsequently to a cell reselection, CN Common
 * GSM_MAP NAS SysInfo is not forwarded to upper layer.
 * Ref: [23.110-340;6.2.2.1.1] & [25.304;10.1,10.2].
 */
typedef struct
{
    LOCAL_PARA_HDR

    kal_bool                 is_cn_info_valid;
    kal_bool                 cn_CommonGSM_MAP_NAS_SysInfo_present;
    kal_bool                 is_access_class_present;

#if 0 /* Maruco20110819, AS notifies it by CELL_CHANGE_FINISH_IND(PS_domain) */
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
    kal_uint8                extra_info_bitmask; /* MAUI_02565126, DSAC/data_speed_support */
    data_speed_support_enum  data_speed_support; /* MAUI_02361221: H-icon display */

#if defined(__UMTS_FDD_MODE__) || defined(__TD_NETWORK_SHARING__)
    as_cell_type_enum        multi_plmn_cell_type[MAX_NUM_MULTI_PLMN];
#endif
    as_cell_type_enum        cell_type;  /* Reserved for before R6 compatible */

#if defined(__UMTS_FDD_MODE__) || defined(__TD_NETWORK_SHARING__)
    kal_uint8                multi_plmn_count;           
    /* Range: 1 to MAX_NUM_MULTI_PLMN. */
    plmn_id_struct           multi_plmn_id[MAX_NUM_MULTI_PLMN];
#endif

#ifdef __R6_DSAC__    
    //kal_bool               is_dsac_present; //MAUI_02565126, remove is_dsac_present
    kal_uint8                dsac_plmn_bitmask;
    /* "1" in LSB bit for 1st PLMN CS/PS domain DSAC valid */
    kal_uint16               cs_dsac[MAX_NUM_MULTI_PLMN];
    kal_uint16               ps_dsac[MAX_NUM_MULTI_PLMN];    
#endif

    kal_uint16               access_class;
    gibi_tag_type            gibi_tag;
    plmn_id_struct           plmn_id;  /* Reserved for before R6 compatible */

    cell_identity_type       cell_id;

#if defined(__3G_CSG_SUPPORT__) || defined(__LTE_RAT__)
#ifdef __UMTS_FDD_MODE__
    csg_access_mode_enum     csg_access_mode;
    csg_info_struct          csg_info;
#endif
#endif

    nas_sys_info_gsm_map_struct  cn_CommonGSM_MAP_NAS_SysInfo;
    CN_DomainSysInfoList     cn_DomainSysInfoList;

#ifdef __PPACR_SUPPORT__
    kal_uint8                ppacr_plmn_bitmask;
    ppacr_info_struct        ppacr_info_plmn_list[MAX_NUM_MULTI_PLMN];
#endif
} ratcm_uas_sys_info_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 

    kal_bool is_usim_inserted;
    kal_bool is_delete_pending;
} ratcm_uas_usim_info_reset_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    domain_id_enum connection_domain;
    rat_type_enum  active_rat;

    /* 20140715 Ming: Add this field in CELL_CHANGE_FINISH_IND and RAT_CHANGE_CNF
     * to sync the gibi_tag value between NAS and AS after interRAT procedure.
     * (Avoid NAS sends previous rat's gibi_tag to current rat)
     * 
     * Related issues: MOLY00051065, ALPS01461467 and ALPS01537397
     *
     * Note that since only problems may happen after xG3HO now, only RRCE carries this field.
     */
    gibiTag_info  gibiTag_sync;
} ratcm_rrce_cell_change_finish_ind_struct;

#ifdef __GEMINI__
typedef struct
{
    LOCAL_PARA_HDR 
} ratcm_rrce_no_ir_sig_proc_req_struct;
#endif

#ifdef __LTE_RAT__
/* RATCM -> RRCE */
/* CSCE and RRCE uses ratcm_uas_rat_change_req_struct jointly */
typedef struct {
    LOCAL_PARA_HDR
    irat_type_enum       irat_type;
    rat_type_enum        source_rat;
    rat_type_enum        target_rat;
    void                *as_info_ptr;
    umts_security_key    security_key[2];
    csfb_indicator_enum  csfb_indicator;
    kal_bool             is_lai_valid;  //CSFB enhancement
    lai_struct           lai;           //CSFB enhancement
} ratcm_uas_rat_change_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    irat_type_enum    irat_type;
    rat_type_enum     source_rat;
    rat_type_enum     target_rat;
    irat_result_enum  irat_result;
    irat_reject_cause_enum irat_reject_cause; //Reject cause when irat_result is equal to IR_RESULT_REJECT.
    void             *as_info_ptr;
} ratcm_uas_rat_change_res_struct;

/* RRCE -> RATCM */
typedef struct {
    LOCAL_PARA_HDR
    irat_type_enum  irat_type;
    rat_type_enum   source_rat;
    rat_type_enum   target_rat;
    void           *as_info_ptr;
    kal_uint8       nas_sec_param_to_eutra[NAS_SECURITY_PARAM_LEN];
} ratcm_uas_rat_change_ind_struct;

/* CSCE and RRCE uses ratcm_uas_rat_change_cnf_struct jointly */
typedef struct {
    LOCAL_PARA_HDR
    irat_type_enum    irat_type;
    rat_type_enum     source_rat;
    rat_type_enum     target_rat;
    irat_result_enum  irat_result;
    void             *as_info_ptr;
    domain_id_enum    connection_domain;

    /* 20140715 Ming: Add this field in CELL_CHANGE_FINISH_IND and RAT_CHANGE_CNF
     * to sync the gibi_tag value between NAS and AS after interRAT procedure.
     * (Avoid NAS sends previous rat's gibi_tag to current rat)
     * 
     * Related issues: MOLY00051065, ALPS01461467 and ALPS01537397
     *
     * Note that since only problems may happen after xG3HO now, only RRCE carries this field.
     */
    gibiTag_info      gibiTag_sync;
} ratcm_uas_rat_change_cnf_struct;
#endif

#endif /* _RATCM_UAS_STRUCT_H */
