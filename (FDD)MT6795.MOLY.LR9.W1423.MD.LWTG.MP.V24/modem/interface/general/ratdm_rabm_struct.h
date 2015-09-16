/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 * --------------------------------------------------------
 *   ratdm_rabm_struct.h
 *
 * Project:
 * --------------------------------------------------------
 *   MONZA
 *
 * Description:
 * --------------------------------------------------------
 *
 *
 * Author:
 * --------------------------------------------------------
 * -------
 *
 * --------------------------------------------------------
 * $Log$
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
 * 	.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * LOCAL_PARA_HDR/PEER_BUF_HDR modification
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
 * Integration change.
 *
 * 01 24 2011 max.yin
 * removed!
 * .
 *
 * 01 21 2011 max.yin
 * removed!
 * .
 *
 * 01 03 2011 max.yin
 * removed!
 * .
 *
 * 12 31 2010 max.yin
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
 *
 * removed!
 * removed!
 * add to source control recursely
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
 * Add ratcm_rabm_retransmit_ind_struct
 *
 * removed!
 * removed!
 * 
 *
 ******************************************************************************/

#ifndef _RATDM_RABM_STRUCT_H
#define _RATDM_RABM_STRUCT_H

#include "flc2_config.h"                    
#include "mcd_l3_inc_gprs_struct.h"         
#include "ps_ratdm_struct.h"                
#include "l3_inc_enums.h"                   

#include "ps_public_enum.h"
#include "kal_general_types.h"        
#include "ps_public_enum.h"           
#include "uas_common_enums.h"
#include "kal_public_defs.h"
#include "mmi_l3_enums.h"

typedef kal_uint16 tPdcpSeqNumber;
typedef kal_uint8   tRabmNsapi;

/* Jeff Wu: Move from rabm_types.h */
typedef kal_uint32 tRabmContextsNum;

typedef enum
{
   TRAFFIC_CLASS_UNKNOWN,
   TRAFFIC_CLASS_CONVERSATIONAL,
   TRAFFIC_CLASS_STREAMING,
   TRAFFIC_CLASS_INTERACTIVE,
   TRAFFIC_CLASS_BACKGROUND
}tTrafficClass;

typedef enum
{
    RATDM_RABM_INVALID_CAUSE,
    //RABM_SUSPEND_RATDM_BY_PDCP_FLC,
    //RABM_RESUME_RATDM_BY_PDCP_FLC,
    RABM_RESUME_RATDM_BY_FLC_PDCP_NOT_EXIST,
    RABM_SUSPEND_RATDM_BY_PDCP_RELOC,
    RABM_RESUME_RATDM_BY_PDCP_RELOC,
    RABM_SUSPEND_RATDM_BY_NRT_RAB_REEST,
    RABM_RESUME_RATDM_BY_NRT_RAB_REEST_SUCCESS,
    RABM_RESUME_RATDM_BY_NRT_RAB_REEST_FAIL,
    RABM_RESUME_RATDM_BY_SR_SUCCESS_RAB_NOT_ESTABLISHED,
    RABM_TRIGGER_RATDM_RETRANSMIT_BY_RLC_RESET,
    RABM_TRIGGER_RATDM_RETRANSMIT_BY_RLC_REESTABLISH,
    RATDM_DEACTIVATE_RABM_BY_REGULAR,
#ifdef __SGLTE__
    RATDM_DEACTIVATE_RABM_MMDC_IRAT,
#endif
    RATDM_DEACTIVATE_RABM_BY_RAT_CHANGE,
    RATDM_RABM_TOTAL_CAUSE
}tRatcmRabmCause;

typedef struct
{
   tRabmNsapi        Nsapi;
   flc2_pool_id_enum    dl_pool_id;
   qos_struct   qos_negotiated;
   tPdcpSeqNumber    SendSeqNumber;
   tPdcpSeqNumber    ReceiveSeqNumber;
#ifdef __USE_LEGACY_23G_DATAPATH__
   kal_uint8 context_id;  // originally in tcm_ratdm_config_req_struct
#endif
   module_type module_id;  // originally in tcm_ratdm_config_req_struct
}tRabmContext;

/* RATDM_RABM_ACTIVATE_REQ */
typedef struct {
    LOCAL_PARA_HDR
    kal_bool RAT_Change;
    kal_uint8 NoOfContexts;
    tRabmContext RabmContexts[RABM_MAX_PS_RABS];
#ifndef __USE_LEGACY_23G_DATAPATH__
    kal_bool loopback;
#endif
} ratdm_rabm_activate_req_struct;

/* RATDM_RABM_ACTIVATE_CNF */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 NoOfContexts;
    kal_uint8 Nsapi[RABM_MAX_PS_RABS];
} ratdm_rabm_activate_cnf_struct;


/* RATDM_RABM_ACTIVATE_IND */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 NoOfContexts;
    kal_uint8 Nsapi[RABM_MAX_PS_RABS];
} ratdm_rabm_activate_ind_struct;

/* RATDM_RABM_ACTIVATE_RSP */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 Nsapi;
    kal_bool is_successful;
} ratdm_rabm_activate_rsp_struct;

/* RATDM_RABM_DEACTIVATE_REQ */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 Cause;
    kal_uint8 NoOfContexts;
    kal_uint8 Nsapi[RABM_MAX_PS_RABS];
} ratdm_rabm_deactivate_req_struct;

typedef ratdm_rabm_deactivate_req_struct ratdm_rabm_deactivate_cnf_struct;

/*  RATDM_RABM_DEACTIVATE_IND */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 NoOfContexts;
    kal_uint8 Nsapi[RABM_MAX_PS_RABS];
    kal_uint8 Cause[RABM_MAX_PS_RABS];
} ratdm_rabm_deactivate_ind_struct;

/* RATDM_RABM_MODIFY_REQ */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 Nsapi;
    kal_uint8 TrafficClass;
    kal_bool DeliveryOfErrorSdus;
} ratdm_rabm_modify_req_struct;

/* RATDM_RABM_MODIFY_CNF */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 Nsapi;
} ratdm_rabm_modify_cnf_struct;

/* RATDM_RABM_RESUME_REQ */
typedef struct {
    LOCAL_PARA_HDR
} ratdm_rabm_resume_req_struct;


/* RATDM_RABM_REESTABLISH_IND */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 TrafficClass;

#ifdef __REL7__
    kal_uint16 ul_data_status;		//24.008 clause 10.5.7.7 MSB: NSAPI15
#endif
} ratdm_rabm_reestablish_ind_struct;

/* RATDM_RABM_REESTABLISH_RSP */
typedef struct {
    LOCAL_PARA_HDR
    kal_bool Result;

#ifdef __REL7__	
    kal_uint16 ul_data_status;		//24.008 clause 10.5.7.7 MSB: NSAPI15
#endif
} ratdm_rabm_reestablish_rsp_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* RATDM_RABM_DATA_CNF */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 nsapi;  
    kal_uint16 npdu_num;   /* The send sequence number this data conf refers to */
} ratdm_rabm_data_cnf_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* RATDM_RABM_SUSPEND_DATA_PLANE_IND */
typedef struct {
    LOCAL_PARA_HDR
    tRatcmRabmCause cause;
    kal_uint8 NoOfContexts;
    kal_uint8 Nsapi[RABM_MAX_PS_RABS];
} ratdm_rabm_suspend_data_plane_ind_struct;

/* RATDM_RABM_RESUME_DATA_PLANE_IND */
typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_need_retransmit; /* Jeff Wu 2006-04-02: New */
    tRatcmRabmCause cause;
    kal_uint8 NoOfContexts;
    kal_uint8 Nsapi[RABM_MAX_PS_RABS];
    kal_uint16 RetransmitFromSN[RABM_MAX_PS_RABS];    
} ratdm_rabm_resume_data_plane_ind_struct;

/* RATDM_RABM_PDCP_RELOC_IND */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 NoOfContexts;
    kal_uint8 Nsapi[RABM_MAX_PS_RABS];
    kal_uint16 UtranNextReceiveSN[RABM_MAX_PS_RABS];    
} ratdm_rabm_pdcp_reloc_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 Nsapi;
    kal_uint16 RetransmitFromSN;
    tRatcmRabmCause cause;
} ratdm_rabm_retransmit_ind_struct;

/* RATDM-RABM-RAB-RELEASE-IND */
typedef struct {
    LOCAL_PARA_HDR
}ratdm_rabm_rab_release_ind_struct;

/* MSG_ID_RATDM_RABM_RAB_STATUS_IND */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 Nsapi;
    kal_bool need_data_cnf;
} ratdm_rabm_rb_config_ind_struct;

typedef ps_data_req_struct ratdm_rabm_data_req_struct;
typedef ps_data_ind_struct ratdm_rabm_data_ind_struct;
#ifdef __HSDPA_SUPPORT__
/* MSG_ID_RATDM_RABM_RAB_CAPABILITY_IND */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 NoOfContexts;
    kal_uint8 Nsapi[RABM_MAX_PS_RABS];
    data_speed_activate_enum Capability[RABM_MAX_PS_RABS];
} ratdm_rabm_rab_capability_ind_struct;
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* PS statistics */
typedef struct {  
    kal_uint8 nsapi;    
    kal_uint8 result;
} single_nsapi_info_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

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
#endif

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
#endif

typedef struct {
    kal_uint8 nsapi;
    kal_uint8 context_id;
    kal_bool reset_tx;
    kal_bool reset_rx;
} single_nsapi_reset_cmd_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 src_id;    
    kal_uint8 serial_num;
    kal_uint8 total_nsapi;
    single_nsapi_reset_cmd_struct reset_cmd[PS_TOT_CONTEXT+1];
} ratdm_pdcp_reset_statistics_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 src_id;    
    kal_uint8 serial_num;
    kal_uint8 total_nsapi;
	single_nsapi_reset_cmd_struct reset_cmd[PS_TOT_CONTEXT+1];	
    single_nsapi_info_struct reset_result[PS_TOT_CONTEXT+1];
} ratdm_pdcp_reset_statistics_rsp_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif /* _RATDM_RABM_STRUCT_H */


