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

/******************************************************************************
 * Filename:
 * ---------
 *	mac2rlc_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *
 *=============================================================================
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================================
 ******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _MAC2RLC_STRUCT_H
#define _MAC2RLC_STRUCT_H

/*Evelyn: Remove redundant header and file */
#include "rlcmac_struct.h"
#include "kal_general_types.h"
#include "rr_common_def.h"
#include "gprs_rlcmac_common_struct.h"
#include "rlc_mac_enums.h"

typedef struct tbf_rel_struct mac_rlc_tbf_rel_ind_struct;

typedef struct {
    kal_uint8 cs;
    kal_uint8 *data_ptr;
    #ifdef __EGPRS_MODE__
    kal_uint8 *data2_ptr;
    kal_uint8 header[6];
    #endif
/* Evelyn 20090415: Merge R6 */
    #ifdef __MTBF__
    kal_uint8 dl_pfi;
    #endif

    #ifdef __GERAN_FANR__
    kal_bool is_data_valid;
    kal_bool is_pan_valid;
    kal_uint8 pan[4];
    #endif
} dl_block_struct;

/* Evelyn 20090415: Merge R6 */
typedef struct {
    kal_uint8 mac_mode;
    kal_uint8 cs;
    kal_uint8 timeslots_allocation;
#if 0
/* under construction !*/
#endif
    /* Claire 041117 change : Revise GPRS header partition between RLC and MAC */
    kal_uint8 tfi;      /*Simon use tfi to fill header*/

    #ifdef __EGPRS_MODE__
    kal_uint16 egprs_window_size;
    kal_uint8 resegment; /* resegment bit */
    #endif
    kal_uint8 rlc_mode;
    #ifdef __MTBF__
    kal_uint8 pfi;
    #endif
    /* Evelyn: To slove [MAUI_01619453] Kenya FT T3168 restart issue  */
    /* Evelyn: To slove the non-sync problem that MAC clean res_req when receiving assignment 
     *         But RLC think res_req already sent after RLC_MAC_RES_REQ in UL state. 
     *         So tell RLC res_req is sent or not. */
    kal_bool res_req_is_sent;

/* Evelyn: R7 Latency Reducation Development */
#ifdef __GERAN_RTTI__
    tti_config_enum tti_mode;
#endif
} ul_con_ind_struct;

typedef struct mac_rlc_ul_con_ind_struct{
    LOCAL_PARA_HDR
    kal_uint8 tlli_channel_coding;

    #ifndef __REMOVE_FA__
    kal_uint8 final_allocation;
    #endif
    #ifndef __REL5__
    kal_uint16 blks_granted;
    #endif

    kal_uint8 ph_cont;

    #ifdef __EGPRS_MODE__
    kal_uint8 tbf_type;
    #endif

    kal_uint8 no_ul_con_ind;
    ul_con_ind_struct multi_ul_con_ind[MULTIPLE_TBF_NUM];
    #ifdef __GERAN_FANR__
    kal_bool is_fanr_active;
    kal_uint8 tan_type;
    kal_uint32 tsh;
    kal_uint8 Reported_timeslot;
    #endif
} mac_rlc_ul_con_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 type;
} mac_rlc_failure_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 no_blks;
    kal_uint8 blks_sent;
    kal_uint16 frame_number;
/* Evelyn 20090415: Merge R6 */
    kal_uint8 pfi;
} mac_rlc_data_req_struct;

typedef struct {
    LOCAL_PARA_HDR
  
    kal_uint8 cs;
    kal_uint8 final_allocation;
    kal_uint8 data_blks_granted;
    kal_uint16 frame_number;
#ifdef __EGPRS_MODE__
    kal_uint8           resegment; /* re-segment bit */
    kal_uint8           pre_emptive_retrans; /* pre-emptive */
    TBF_TYPE            tbf_type_tag;   
    union
    {
    ack_nack_desc_struct gprs_ie;
    egprsack_nack_description_struct egprs_ie; /*  */
    }ack_nack_struct;
#else
  union
    {
        ack_nack_desc_struct gprs_ie;
  }ack_nack_struct;
#endif

#ifdef __TBF_EST__
   kal_uint8 tbf_est;
#endif
    
    /* Lanslo 20050825: for CRTU-G 52.1.2.1.8.1.8 
     * PUAN without contention TLLI should be accepted 
     * to process request of re-tx of PRR (and ARAC) 
     * and ack/nack description during contention */
    kal_bool is_contention_success;
    /* eo Lanslo 20050825 */
/* Evelyn 20090415: Merge R6 */
    #ifdef __MTBF__
    kal_uint8 pfi;
    #endif
} mac_rlc_ack_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 rlc_mode;
#ifdef __EGPRS_MODE__
    kal_uint16 window_size;
    kal_uint8 tbf_type;
#endif
} mac_rlc_switch_to_dl_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 ask_res_req;
    kal_uint8 cause;
} mac_rlc_ready_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint16 blks_granted;
/* Evelyn 20090415: Merge R6 */
    #ifdef __MTBF__
    kal_uint8 no_of_modify_tbf;
    kal_uint8 no_of_ul_ts_alloc[MULTIPLE_TBF_NUM];
    kal_uint8 pfi[MULTIPLE_TBF_NUM];
    #else
    kal_uint8 no_of_ul_ts_alloc;
    #endif
} mac_rlc_pdch_rel_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 mac_mode;
    kal_uint8 cs;
    kal_uint8 tlli_channel_coding;
    kal_uint8 final_allocation;
    kal_uint8 ph_cont;
    kal_uint8 timeslots_allocation;
    kal_uint16 blks_granted;
    #ifdef __EGPRS_MODE__
    kal_uint8   resegment; /* resegment bit */
    kal_uint8   window_size; /* window size */
    kal_uint8   tbf_type; /* tbf type */
    #endif

} mac_rlc_switch_to_ul_struct;

/* Evelyn 20090415: Merge R6 */
typedef struct {
    kal_uint8 rlc_mode;
    #ifdef __EGPRS_MODE__
    kal_uint16  window_size; /* downlink window size */
    #endif
    #ifdef __MTBF__
    kal_uint8 pfi;
    #endif
/* Evelyn: R7 Latency Reducation Development */
#ifdef __GERAN_RTTI__
    tti_config_enum tti_mode;
#endif

#ifdef __GERAN_FANR__
    kal_bool is_fanr_activated;
    kal_bool is_event_based_fanr;
#endif
} dl_con_ind_struct;
/* Evelyn 20090415: Merge R6 */
typedef struct {
    LOCAL_PARA_HDR

    #ifdef __EGPRS_MODE__
    kal_uint8   tbf_type;
    #endif

    kal_uint8 no_dl_con_ind;
    dl_con_ind_struct multi_dl_con_ind[MULTIPLE_TBF_NUM];
} mac_rlc_dl_con_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 no_dl_blocks;
    /* Evelyn 20090905: Modify for High multislot class */
    dl_block_struct dl_blocks[MAX_TX_TIMESLOTS];
    #ifndef __MTK_TARGET__
    kal_bool enable_dl_loop;
    kal_uint16 bsn1;
    kal_uint16 bsn2;
    #endif
    /* Claire 041216 change : Tell RLC DSP V(Q) from transfer_data_ind */
    #ifdef __EGPRS_MODE__
    #ifdef __MTBF__
    kal_uint16 dsp_vq[MULTIPLE_TBF_NUM];
    #else
    kal_uint16 dsp_vq;
    #endif
    #endif
    #ifdef __PS_HO__
    kal_bool received_in_old_cell;
    #endif
} mac_rlc_dl_data_ind_struct;

/* Lanslo 20070720: should replace MTK_KAL_MNT with __MTK_TARGET__ for MODIS */
#ifndef __MTK_TARGET__
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 *packed_PDAN_msg;
    kal_uint8 *egprs_ack_nack_ie_ptr;
    kal_uint8 avail_len;
    kal_uint8 s_or_p;
    kal_bool  reconstruct;
/* Evelyn 20090415: Merge R6 */
    #ifdef __MTBF__
    kal_uint8 dl_pfi;
    #endif
} mac_rlc_ack_req_struct;
#endif
/* Exce 030806: After this primitive is received should RES_REQ be sent from RLC */
typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_dl_exist;  /** 
                            * Exce 20040528:
                            * Notify RLC that whether downlink TBF (either it 
                            * is onging or pending) exists when confirming 
                            * uplink TBF is released. Thus to resolve the problem
                            * that RLC does not send RES_REQ when REL_CNF
                            * is received during the time that ongoing downlink 
                            * TBF is released and another one is pending to
                            * start.
                            */
/* Evelyn 20090415: Merge R6 */
    #ifdef __MTBF__
    kal_uint8 no_ul_pfi;
    kal_uint8 pfi[MULTIPLE_TBF_NUM];
    #endif
} mac_rlc_rel_cnf_struct;

/* Evelyn 20090415: Merge R6 */
#ifdef __PS_HO__

typedef struct{
    kal_uint8 is_valid;
    kal_uint8 length;
    kal_uint8 *data;
} nas_container_struct;

typedef struct{

    LOCAL_PARA_HDR
    kal_bool is_reset;
    kal_bool is_queuing;
    ps_ho_dir_enum ps_ho_dir;
} mac_rlc_ps_ho_start_ind_struct;

typedef struct{
    LOCAL_PARA_HDR
    mac_rlc_dl_con_ind_struct mac_rlc_dl_con_ind;
    mac_rlc_ul_con_ind_struct mac_rlc_ul_con_ind;
    nas_container_struct nas_container;
} mac_rlc_ps_ho_success_ind_struct;

typedef struct{
    LOCAL_PARA_HDR
} mac_rlc_ps_ho_fail_ind_struct;

#endif /* end of __PS_HO__ */

#ifdef __MTBF__
typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 no_pfi;
    kal_uint8 pfi[MULTIPLE_TBF_NUM];
    kal_uint8 cause;
} mac_rlc_access_reject_ind_struct;
#endif

// Matt merge for R6
typedef struct {
    #ifdef __EGPRS_MODE__
    kal_uint8 tbf_type;
    kal_uint8 resegment; /* resegment bit */
    kal_uint16 egprs_window_size;
    #endif 
    kal_uint8 mac_mode;	
    kal_uint8 cs;
    kal_uint8 tlli_channel_coding;
    kal_uint8 final_allocation;
    kal_uint8 ph_cont;
    kal_uint8 timeslots_allocation;
    kal_uint16 blks_granted;
#if 0
/* under construction !*/
#endif
    /* Claire 041117 change : Revise GPRS header partition between RLC and MAC */
    kal_uint8 tfi;      /*Simon use tfi to fill header*/
    rlc_mode_enum rlc_mode;
    #ifdef __MTBF__
    kal_uint8 pfi;

#endif
    kal_bool res_req_is_sent;
}rlc_ul_con_ind_struct;

typedef struct {
    kal_uint8 rlc_mode;
    #ifdef __EGPRS_MODE__    
    kal_uint16  window_size; /* downlink window size */
    kal_uint8 tbf_type;    
#endif
    kal_uint8 pfi;   
}rlc_dl_con_ind_struct;

typedef struct{
    kal_uint8 no_of_ul_ts_alloc;
    kal_uint16 blks_granted; // for fix allocation
    kal_uint8 pfi;
}pdch_rel_ind_struct;

#ifdef __MAC_SHOW_TRANS_DATA__

typedef struct{
    kal_uint8 is_data_valid;
    kal_uint8 data[78];
#ifdef __EGPRS_MODE__
    kal_uint8 data2[78];
    kal_uint8 is_data2_valid;
#endif
} mac_trans_data_content_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 no_of_data;
    mac_trans_data_content_struct data[MAX_RX_TIMESLOTS];
} mac_mac_trans_data_ind_struct;
#endif

#ifndef __MTK_TARGET__
typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 timer_index;
    kal_uint8 timer_action;
    kal_uint32 timeout_value;
    kal_uint8 sim_index;
    kal_uint8 tbf_index;
} mac_timer_event_ind_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 pca_give_in_count;
    kal_uint8 pdan_give_in_count;
    kal_uint8 pca_give_in_max;
    kal_uint8 pdan_give_in_max;
    kal_uint8 pca_give_in_max_learned;
    kal_uint8 pdan_give_in_max_learned;
    kal_uint32 next_outgoing_real_polling_frame;
    kal_uint32 last_reported_polling_frame;

    kal_uint8 is_ps_starvation_protect_activated;
    kal_uint8 ps_starvation_protect_ul_blk_count;
    kal_uint8 ul_blk_successive_conflict_count;
    kal_uint32 ps_starvation_protect_frame;

} mac_next_outgoing_rrbp_ind_struct;
#endif

#endif



