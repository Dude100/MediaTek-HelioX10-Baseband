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
 *  gprs_rlcmac_dl_struct.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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


/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : gprs_rlcmac_dl_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _GPRS_RLCMAC_DL_STRUCT_H
#define _GPRS_RLCMAC_DL_STRUCT_H

/*Evelyn: Remove redundant header and file */
#include "kal_general_types.h"
#include "rr_common_def.h"
#include "nstd_mobile_alloc_peer_struct.h"
#include "nstd_alloc_bitmap_struct.h"
#include "gprs_rlcmac_common_struct.h"
#include "nstd_extension_bit_struct.h"

typedef struct {
    kal_uint8 persist_level[4];
} persist_level_struct;

typedef struct {
    kal_uint8 timing_adv_index; /* TIMING ADV INDEX*/
    kal_uint8 timing_adv_time_slot_no; /* TIMING ADV TIMESLOT NUMBER*/
} timing_adv_idx_tslot_struct;

typedef struct {
    ispresent timing_adv_val_choice_tag;
    union {
        kal_uint8 p_timing_adv_val;
    } timing_adv_val_choice_value;
    ispresent timing_adv_idx_tslot_choice_tag;
    union {
        timing_adv_idx_tslot_struct p_timing_adv_index;
    } timing_adv_idx_tslot_choice_value;
} pkt_timing_advance_struct;

typedef struct {
    kal_uint8 chng_mark1; /* CHANGE MARK 1*/
    ispresent chng_mark2choice_tag;
    union {
        kal_uint8 p_chng_mark2;
    } chng_mark2choice_value;
} chng_mark1struct;

typedef struct {
    kal_uint8 maio; /* MAIO*/
    kal_uint8 ma_number; /* MA NUMBER*/
    ispresent chng_mark1choice_tag;
    union {
        chng_mark1struct p_chng_mark1;
    } chng_mark1choice_value;
} indirect_encode_struct;

typedef struct {
    kal_uint8 maio; /* MAIO*/
    rr_gprs_mobile_alloc_peer_struct gprs_mobile_alloc; /* GPRS MOBILE ALLOC STRUCT*/
} direct_encode1struct;

typedef struct {
    kal_uint8 tsc; /* TSC*/
    freq_enum freq_encoding_choice_tag;
    union {
        kal_uint16 arfcn;
        indirect_encode_struct indirect_encode;
        direct_encode1struct direct_encode1;
        direct_encode2struct direct_encode2;
    } freq_encoding_choice_value;
} freq_params_peer_struct;

typedef struct {
    ispresent frame_num_encode_choice_tag;
    union {
        kal_uint16 a_absolute;
        kal_uint16 p_relative;
    } frame_num_encode_choice_value;
} starting_frame_num_struct;

typedef struct {
    kal_uint16 random_access_info; /* RANDOM ACCESS INFORMATION*/
    kal_uint16 frame_no; /* FRAME NUMBER*/
} pkt_req_ref_struct;

typedef struct {
    ispresent usf_time_slot_choice_tag;
    union {
        kal_uint8 p_usf_time_slot;
    } usf_time_slot_choice_value;
} usf_struct;

typedef struct {
    usf_struct usf_alloc_struct[8];
} time_slot_alloc_struct;

typedef struct {
    kal_uint8 usf_val; /* usf value*/
    kal_uint8 gamma_tn; /* gamma value*/
} usf_gamma_struct;

typedef struct {
    ispresent usf_gamma_time_slot_choice_tag;
    union {
        usf_gamma_struct p_usf_pwr_ctrl_time_slot;
    } usf_gamma_time_slot_choice_value;
} rr_usf_pwr_ctrl_struct;

typedef struct {
    kal_uint8 alpha; /* ALPHA*/
    rr_usf_pwr_ctrl_struct usf_pwr_ctrl_struct[8];
} time_slot_pwr_ctrl_alloc_struct;

typedef struct {
    kal_uint8 p0; /* p0 BIT*/
    kal_uint8 pr_mode; /* PR MODE*/
} p0pr_mode_struct;

typedef struct {
    kal_uint8 extended_dyn_alloc; /* EXT DYNAMIC ALLOCATION*/
    ispresent p0pr_mode_choice_tag;
    union {
        p0pr_mode_struct p_p0pr;
    } p0pr_mode_choice_value;
    kal_uint8 usf_granularity; /* USF GRANULARITY*/
    ispresent tfi_assignment_choice_tag;
    union {
        kal_uint8 p_tfi_assignment;
    } tfi_assignment_choice_value;
    ispresent rlc_blks_granted_choice_tag;
    union {
        kal_uint8 p_rlc_blks_granted;
    } rlc_blks_granted_choice_value;
    ispresent tbf_starting_time_choice_tag;
    union {
        starting_frame_num_struct p_tbf_starting_time;
    } tbf_starting_time_choice_value;
    ispresent time_slot_pwr_ctrl_choice_tag;
    union {
        time_slot_alloc_struct a_time_slot_alloc;
        time_slot_pwr_ctrl_alloc_struct p_time_slot_alloc;
    } time_slot_pwr_ctrl_choice_value;
} dynamic_alloc_struct;

typedef struct {
    kal_uint8 alpha; /* ALPHA*/
    kal_uint8 gammatn; /* GAMMA*/
} alpha_gamma_struct;

typedef struct {
    kal_uint8 p0; /* P0*/
    kal_uint8 bts_mode; /* BTS MODE*/
    kal_uint8 pr_mode; /* PR_MODE*/
} bts_mode_struct;

typedef struct {
    kal_uint8 time_slot_no; /* TIME SLOT NUMBER*/
    ispresent alpha_gamma_choice_tag;
    union {
        alpha_gamma_struct p_alpha_gamma;
    } alpha_gamma_choice_value;
    ispresent pwr_ctrl_mode_choice_tag;
    union {
        bts_mode_struct p_pwr_ctrl_mode;
    } pwr_ctrl_mode_choice_value;
    starting_frame_num_struct tbf_starting_time; /* TBF STARTING TIME*/
} single_blk_alloc_struct;

/* Claire 041123 new : Add for decoding Multi Block Allocation struct in PUAS */
#ifdef __EGPRS_MODE__
typedef struct {
    kal_uint8 time_slot_no; /* TIME SLOT NUMBER*/
    ispresent alpha_gamma_choice_tag;
    union {
        alpha_gamma_struct p_alpha_gamma;
    } alpha_gamma_choice_value;
    ispresent pwr_ctrl_mode_choice_tag;
    union {
        bts_mode_struct p_pwr_ctrl_mode;
    } pwr_ctrl_mode_choice_value;
    starting_frame_num_struct tbf_starting_time; /* TBF STARTING TIME*/
    kal_uint8 no_of_blks_alloc;
} multi_blk_alloc_struct;
#endif

typedef struct {
    ispresent gamma_tn_val_choice_tag;
    union {
        kal_uint8 p_gamma_tn_value;
    } gamma_tn_val_choice_value;
} gamma_tn_value_struct;

typedef struct {
    kal_uint8 alpha; /* ALPHA*/
    gamma_tn_value_struct gamma_tn_val_struct[8];
} pwr_ctrl_params_peer_struct;

typedef struct {
    ispresent up_link_tfichoice_tag;
    union {
        kal_uint8 p_uplink_tfi_assgn;
    } up_link_tfichoice_value;
    kal_uint8 final_allocation; /* FINAL ALLOCATION*/
    kal_uint8 down_link_ctrl_time_slot; /* DOWN LINK CONTROL TIME SLOT*/
    ispresent pwr_ctrl_mode_choice_tag;
    union {
        bts_mode_struct p_pwr_ctrl_mode;
    } pwr_ctrl_mode_choice_value;
    ispresent pwr_ctrl_time_slot_choice_tag;
    union {
        kal_uint8 a_time_slot_allocation;
        pwr_ctrl_params_peer_struct p_pwr_ctrl_params;
    } pwr_ctrl_time_slot_choice_value;
    kal_uint8 half_duplex_mode; /* HALF DUPLEX MODE*/
    starting_frame_num_struct tbf_starting_time; /* TBF STARTING TIME*/
    kal_uint8 msgesc; /* MESSAGE ESCAPE*/
    alloc_struct alloc_bit_map; /* ALLOCATION BITMAP*/
} fixed_alloc_struct;

typedef struct {
    ispresent extend_timing_adv_choice_tag;
    union {
        kal_uint8 p_extend_timing_adv;
    } extend_timing_adv_choice_value;
} extend_timing_adv_struct;

/* Evelyn 20090415: Merge R6 */
#ifdef __MTBF__
typedef struct {
    ispresent PFI_choice_tag;
    union {
        kal_uint8 p_PFI;
    } PFI_choice_value;
    ispresent RLC_MODE_choice_tag;
    union {
        kal_uint8 p_RLC_MODE;
    } RLC_MODE_choice_value;
} rel_6_puas_struct;

typedef struct {
    ispresent G_RNTI_choice_tag;
    union {
        kal_uint8 p_G_RNTI;
    } G_RNTI_choice_value;
    ispresent RB_ID_choice_tag;
    union {
        kal_uint8 p_RB_ID;
    } RB_ID_choice_value;
    ispresent rel_6_choice_tag;
    union {
        rel_6_puas_struct p_rel_6;
    } rel_6_choice_value;
} rel_5_later_puas_struct;

#endif

typedef struct {
    kal_uint8 ch_code_cmd; /* CHANNEL CODING COMMAND*/
    kal_uint8 tlli_blk_ch_code; /* TLLI CODE*/
    pkt_timing_advance_struct pkt_time_advance; /* PACKET TIME ADVANCE STRUCTURE*/
    ispresent freq_params_choice_tag;
    union {
        freq_params_peer_struct p_freq_params;
    } freq_params_choice_value;
    challoc_enum alloc_type_choice_tag;
    union {
        dynamic_alloc_struct dynamic_alloc;
        single_blk_alloc_struct single_blk_alloc;
        fixed_alloc_struct fixed_alloc;
    } alloc_type_choice_value;
/* Evelyn 20090415: Merge R6 */
#ifdef __R99__
    ispresent rel99choice_tag;
    union {
        extend_timing_adv_struct p_rel99;
    } rel99choice_value;
#endif
#ifdef __MTBF__
    ispresent rel_5_later_choice_tag;
    union {
        rel_5_later_puas_struct p_rel5;
    } rel_5_later_choice_value;
#endif
} gprsuplnk_assign_struct;

#ifdef __EGPRS_MODE__

/* Claire 041123 test */
typedef struct {
    kal_uint8 access_tech_type;
} rmc_access_tech_req_elem_struct;

typedef struct {
    kal_uint8 access_tech_type;
    unsigned int no_access_tech_list;
    unsigned int access_tech_list_size;
    rmc_access_tech_req_elem_struct *access_tech_list;
} rmc_access_tech_req_struct;
/* End Claire 041123 test */

typedef struct {
    /* Claire 041123 change : Correct egprsuplnk_assign_struct pack unpack bug */
    //kal_uint8 msgescape1; /* message ESCAPE*/
    ispresent cont_res_tlli_choice_tag;
    union {
        kal_uint32 p_cont_resolution_tlli;
    } cont_res_tlli_choice_value;
    
    ispresent compact_reduce_ma_choice_tag;
    union {
        kal_uint8 p_compact_reduce_ma;
    } compact_reduce_ma_choice_value;
    kal_uint8 egprs_ch_coding_cmd; /* EGPRS channel coding command*/
    kal_uint8 resegment; /* resegment*/
    kal_uint8 window_size; /* EGPRS window size*/
    
/* Claire 041123 change : Correct egprsuplnk_assign_struct pack unpack bug */
   ispresent ch1_tag;
    union {
        rmc_access_tech_req_struct access_tech_req;
    } ch1_value;
    kal_uint8 arac_retxn_req;
/* End Claire 041123 change : Correct egprsuplnk_assign_struct pack unpack bug */    

    kal_uint8 tlli_blk_ch_coding; /* TLLI block channel coding*/
    ispresent bep_period_choice_tag;
    union {
        kal_uint8 p_bep_period2;
    } bep_period_choice_value;
    pkt_timing_advance_struct pkt_timing_advance; /* TIME ADV STRUCT*/
    ispresent ext_time_adv_choice_tag;
    union {
        kal_uint8 p_extend_timing_advance;
    } ext_time_adv_choice_value;
    ispresent freq_params_choice_tag;
    union {
        freq_params_peer_struct p_freq_params;
    } freq_params_choice_value;
    challoc_enum alloc_type_choice_tag;
    union {
        dynamic_alloc_struct dynamic_alloc;
/* Claire 041123 new : Add for decoding Multi Block Allocation struct in PUAS */
        //single_blk_alloc_struct single_blk_alloc;
        multi_blk_alloc_struct multi_blk_alloc;
        fixed_alloc_struct fixed_alloc;
    } alloc_type_choice_value;
/* Evelyn 20090415: Merge R6 */
#ifdef __MTBF__
    ispresent rel_5_later_choice_tag;
    union {
        rel_5_later_puas_struct p_rel5;
    } rel_5_later_choice_value;
#endif
} egprsuplnk_assign_struct;

typedef struct {
    header_struct header; /* HEADER*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    ispresent per_level_choice_tag;
    union {
        persist_level_struct p_persist_level;
    } per_level_choice_value;
    msid_enum ms_id_choice_tag;
    union {
        global_tfistruct global_tfi;
        kal_uint32 tlli;
        kal_uint16 tqi;
        pkt_req_ref_struct pkt_req_ref;
    } ms_id_choice_value;
    ispresent up_link_assgn_choice_tag;
    union {
        gprsuplnk_assign_struct a_gprs_up_lnk_assign;
        egprsuplnk_assign_struct p_egprs_up_lnk_assign;
    } up_link_assgn_choice_value;
} pkt_uplink_assignment_msg;
#else /* -------------------GPRS MODE-------------------------------*/
typedef struct {
    header_struct header; /* HEADER*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    ispresent per_level_choice_tag;
    union {
        persist_level_struct p_persist_level;
    } per_level_choice_value;
    msid_enum ms_id_choice_tag;
    union {
        global_tfistruct global_tfi;
        kal_uint32 tlli;
        kal_uint16 tqi;
        pkt_req_ref_struct pkt_req_ref;
    } ms_id_choice_value;
    kal_uint8 msgesc; /* MESSAGE ESCAPE*/
    gprsuplnk_assign_struct gprs_up_lnk_assign; /* GPRS uplink assignment*/
} pkt_uplink_assignment_msg;
#endif

typedef struct {
    starting_frame_num_struct measurement_start_time; /* startframe structure*/
    kal_uint8 measurement_interval; /* MEASUREMENT INTERVAL*/
    kal_uint8 measurement_bitmap; /* MEASUREMENT BIT MAP*/
} meas_map_peer_struct;

/* Evelyn 20090415: Merge R6 */
#ifdef __MTBF__

typedef struct {
    ispresent PFI_choice_tag;
    union {
        kal_uint8 p_PFI;
    } PFI_choice_value;
} rel_6_pdas_struct;

typedef struct {
    kal_uint8 RB_ID; /* G-RNTI extention*/
    ispresent G_RNTI_choice_tag;
    union {
        kal_uint8 p_G_RNTI;
    } G_RNTI_choice_value;
    ispresent ul_ctrl_tn_choice_tag;
    union {
        kal_uint8 p_ul_ctrl_tn;
    } ul_ctrl_tn_choice_value;
    ispresent hfn_lsb_choice_tag;
    union {
        kal_uint8 p_hfn_lsb;
    } hfn_lsb_choice_value;
} rel_5_content_pdas_struct;

typedef struct {
    ispresent rel_5_content_choice_tag;
    union {
        rel_5_content_pdas_struct p_rel_5_connet;
    } rel_5_content_choice_value;
    ispresent rel_6_choice_tag;
    union {
        rel_6_pdas_struct p_rel_6;
    } rel_6_choice_value;
} rel_5_later_pdas_struct;

#endif

#ifdef __EGPRS_MODE__
typedef struct {
    kal_uint8 window_size; /* EGPRS window size*/
    kal_uint8 link_quality_meas_mode; /* link quality measurement mode*/
    ispresent bep_period_choice_tag;
    union {
        kal_uint8 p_bep_period2;
    } bep_period_choice_value;
} egprsws_link_quality;

typedef struct {
    ispresent egprs_ws_link_quality_choice_tag;
    union {
        egprsws_link_quality p_egprs_ws_link_quality;
    } egprs_ws_link_quality_choice_value;
} egprsdl_assign_additions_struct;

typedef struct {
    header_struct header; /* HEADER*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    ispresent per_level_choice_tag;
    union {
        persist_level_struct p_persist_level;
    } per_level_choice_value;
    msid_enum ms_add_choice_tag;
    union {
        global_tfistruct global_tfi;
        kal_uint32 tlli;
    } ms_add_choice_value;
    kal_uint8 msgescape; /* MESSAGE ESCAPE*/
    kal_uint8 mac_mode; /* MAC MODE*/
    kal_uint8 rlc_mode; /* RLC MODE*/
    kal_uint8 ctrl_ack; /* CONTROL ACK*/
    kal_uint8 time_slotalloc; /* TIMESLOT ALLOCATION*/
    pkt_timing_advance_struct pkt_time_adv_value; /* PACKET TIMING ADVANCE STRUCTURE*/
    ispresent pwr_ctrl_mode_choice_tag;
    union {
        bts_mode_struct p_pwr_ctrl_mode;
    } pwr_ctrl_mode_choice_value;
    ispresent freq_params_choice_tag;
    union {
        freq_params_peer_struct p_freq_params;
    } freq_params_choice_value;
    ispresent down_link_tfi_choice_tag;
    union {
        kal_uint8 p_down_link_tfi_assign;
    } down_link_tfi_choice_value;
    ispresent pwr_ctrl_param_choice_tag;
    union {
        pwr_ctrl_params_peer_struct p_power_ctrl_param_value;
    } pwr_ctrl_param_choice_value;
    ispresent tbf_starting_time_choice_tag;
    union {
        starting_frame_num_struct p_tbf_starting_time;
    } tbf_starting_time_choice_value;
    ispresent meas_map_choice_tag;
    union {
        meas_map_peer_struct p_measurement_map;
    } meas_map_choice_value;
    ispresent rel99choice_tag;
    union {
        egprsdl_assign_additions_struct p_rel99;
    } rel99choice_value;
    ispresent extend_timing_adv_choice_tag;
    union {
        kal_uint8 p_extend_timng_adv;
    } extend_timing_adv_choice_value;
/* Evelyn 20090415: Merge R6 */
#ifdef __MTBF__
    kal_uint8 maescape; /* ESCAPTE COMPACT Reduced MA*/
    ispresent rel5_later_choice_tag;
    union {
        rel_5_later_pdas_struct p_rel5_later;
    } rel5_later_choice_value;
#endif
} pkt_downlink_assign;
#else
typedef struct {
    header_struct header; /* HEADER*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    ispresent per_level_choice_tag;
    union {
        persist_level_struct p_persist_level;
    } per_level_choice_value;
    msid_enum ms_add_choice_tag;
    union {
        global_tfistruct global_tfi;
        kal_uint32 tlli;
    } ms_add_choice_value;
    kal_uint8 msgescape; /* MESSAGE ESCAPE*/
    kal_uint8 mac_mode; /* MAC MODE*/
    kal_uint8 rlc_mode; /* RLC MODE*/
    kal_uint8 ctrl_ack; /* CONTROL ACK*/
    kal_uint8 time_slotalloc; /* TIMESLOT ALLOCATION*/
    pkt_timing_advance_struct pkt_time_adv_value; /* PACKET TIMING ADVANCE STRUCTURE*/
    ispresent pwr_ctrl_mode_choice_tag;
    union {
        bts_mode_struct p_pwr_ctrl_mode;
    } pwr_ctrl_mode_choice_value;
    ispresent freq_params_choice_tag;
    union {
        freq_params_peer_struct p_freq_params;
    } freq_params_choice_value;
    ispresent down_link_tfi_choice_tag;
    union {
        kal_uint8 p_down_link_tfi_assign;
    } down_link_tfi_choice_value;
    ispresent pwr_ctrl_param_choice_tag;
    union {
        pwr_ctrl_params_peer_struct p_power_ctrl_param_value;
    } pwr_ctrl_param_choice_value;
    ispresent tbf_starting_time_choice_tag;
    union {
        starting_frame_num_struct p_tbf_starting_time;
    } tbf_starting_time_choice_value;
    ispresent meas_map_choice_tag;
    union {
        meas_map_peer_struct p_measurement_map;
    } meas_map_choice_value;
/* Evelyn 20090415: Merge R6 */
#ifdef __R99__
    kal_uint8 egprsescape; /* ESCAPTE COMPACT Reduced MA*/
    ispresent extend_timing_adv_choice_tag;
    union {
        kal_uint8 p_extend_timng_adv;
    } extend_timing_adv_choice_value;
#endif
#ifdef __MTBF__
    kal_uint8 maescape; /* ESCAPTE COMPACT Reduced MA*/
    ispresent rel5_later_choice_tag;
    union {
        rel_5_later_pdas_struct p_rel5_later;
    } rel5_later_choice_value;
#endif
} pkt_downlink_assign;
#endif

typedef struct {
    kal_uint8 wait_indication;
    kal_uint8 wait_indication_size;
} wait_struct;

typedef struct {
    add_enum ms_id_choice_tag;
    union {
        kal_uint32 tlli;
        pkt_req_ref_struct pkt_req_ref;
        global_tfistruct global_tfi;
    } ms_id_choice_value;
    ispresent wait_ind_choice_tag;
    union {
        wait_struct p_wait_ind_val;
    } wait_ind_choice_value;
} reject_struct;

typedef struct {
    header_struct header; /* HEADER*/
    kal_uint8 msg_type; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    reject_struct reject; /* REJECT STRUCTURE*/
    unsigned int no_additional_reject;
    unsigned int additional_reject_size;
    reject_struct *additional_reject;
} packet_access_reject;

typedef struct {
    header_struct header; /* HEADER*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    msid_enum pkt_req_ref_choice_tag;
    union {
        pkt_req_ref_struct packet_request_ref;
    } pkt_req_ref_choice_value;
    kal_uint16 tqi; /* TQI*/
} packet_queing_notification;

typedef struct {
    starting_frame_num_struct tbf_starting; /* TBF STARTING TIME*/
    ispresent time_slot_choice_tag;
    union {
        kal_uint8 p_time_slot_alloc;
    } time_slot_choice_value;
    kal_uint8 msgesc; /* MESSAGE ESCAPE*/
    alloc_struct alloc_bit_map; /* ALLOCATION BITMAP*/
} alloc_bitmap_struct;

typedef struct {
    kal_uint8 final_alloc; /* FINAL ALLOCATION*/
    ispresent repeat_alloc_choice_tag;
    union {
        kal_uint8 a_ts_over_ride;
        alloc_bitmap_struct p_alloc_bitmap;
    } repeat_alloc_choice_value;
} ack_nack_fixed_alloc_struct;

typedef struct {
    kal_uint8 ch_coding_cmd; /* CHCODINGCMD*/
    ack_nack_desc_struct ack_nack_descrp; /* ACKNACKDESC*/
    ispresent cont_res_tlli_choice_tag;
    union {
        kal_uint32 p_cont_resolution_tlli;
    } cont_res_tlli_choice_value;
    ispresent pkt_timing_adv_choice_tag;
    union {
        pkt_timing_advance_struct p_pkt_timing_adv_value;
    } pkt_timing_adv_choice_value;
    ispresent pwr_ctrl_params_choice_tag;
    union {
        pwr_ctrl_params_peer_struct p_pwr_ctrl_param_value;
    } pwr_ctrl_params_choice_value;
    ispresent extend_bits_choice_tag;
    union {
        extension_bit_struct p_ext_bits_value;
    } extend_bits_choice_value;
    ispresent fixed_alloc_choice_tag;
    union {
        ack_nack_fixed_alloc_struct p_fixed_alloc_params;
    } fixed_alloc_choice_value;

#ifdef __R99__
    ispresent rel99choice_tag;
    union {
        extend_timing_adv_struct p_rel99;
    } rel99choice_value;
    kal_uint8 tbf_est; /* TBF_EST */
#endif
} gprsuplnk_ack_nack_struct;

#ifdef __EGPRS_MODE__

typedef struct {
    kal_uint8 msgescape1; /* message ESCAPE*/
    kal_uint8 egprs_ch_coding_cmd; /* EGPRS channel coding command*/
    kal_uint8 resegment; /* resegment*/
    kal_uint8 pre_emptive_txn; /* pre emptive transmission*/
    /* Claire 041104 change : Correct egprsuplnk_ack_nack_struct pack unpack bug */
    kal_uint8 prr_retxn_req;
    kal_uint8 arac_retxn_req;
    /* End Claire 041104 change : Correct egprsuplnk_ack_nack_struct pack unpack bug */
    ispresent cont_res_tlli_choice_tag;
    union {
        kal_uint32 p_cont_res_tlli;
    } cont_res_tlli_choice_value;
    /* Claire 041104 change : Correct egprsuplnk_ack_nack_struct pack unpack bug */
    kal_uint8 tbf_est;
    /* End Claire 041104 change : Correct egprsuplnk_ack_nack_struct pack unpack bug */    
    ispresent pkt_timing_adv_choice_tag;
    union {
        pkt_timing_advance_struct p_pkt_timing_advance;
    } pkt_timing_adv_choice_value;
    ispresent extend_timing_adv_choice_tag;
    union {
        kal_uint8 p_extend_timing_advance;
    } extend_timing_adv_choice_value;
    ispresent pwr_ctrl_params_choice_tag;
    union {
        pwr_ctrl_params_peer_struct p_pwr_ctrl_params_value;
    } pwr_ctrl_params_choice_value;
    ispresent extend_bits_choice_tag;
    union {
        extension_bit_struct p_ext_bits_value;
    } extend_bits_choice_value;
    egprsack_nack_description_struct egprs_ack_nack_desc_struct;
    ispresent fixed_alloc_choice_tag;
    union {
        ack_nack_fixed_alloc_struct p_fixed_allocation;
    } fixed_alloc_choice_value;
} egprsuplnk_ack_nack_struct;

typedef struct {
    header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGEMODE*/
    kal_uint8 msgescape1; /* message ESCAPE*/
    kal_uint8 up_link_tfi; /* UPLINKTFI*/
    ispresent gprs_ul_ack_nack_choice_tag;
    union {
        gprsuplnk_ack_nack_struct a_gprs_up_lnk_ack_nack;
        egprsuplnk_ack_nack_struct p_egprs_up_lnk_ack_nack;
    } gprs_ul_ack_nack_choice_value;
} pkt_uplink_ack_nack;

#else
typedef struct {
    header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGEMODE*/
    kal_uint8 msgescape1; /* message ESCAPE*/
    kal_uint8 up_link_tfi; /* UPLINKTFI*/
    kal_uint8 msgesc; /* MESSAGE ESCAPE*/
    gprsuplnk_ack_nack_struct gprs_up_lnk_ack_nack; /* GPRS uplink ack/nack*/
} pkt_uplink_ack_nack;
#endif

typedef struct {
    kal_uint8 timing_adv_index; /* UP LINK TIM ADV INDEX*/
    kal_uint8 timing_adv_ts_number; /* TIMING ADV TIMESLOT NUM*/
} timing_adv_index_tn_struct;

typedef struct {
    ispresent timing_adv_choice_tag;
    union {
        kal_uint8 p_timing_adv_val;
    } timing_adv_choice_value;
    ispresent ul_timing_adv_index_tn_choice_tag;
    union {
        timing_adv_index_tn_struct p_ul_timing_adv_index_tn;
    } ul_timing_adv_index_tn_choice_value;
    ispresent dl_timing_adv_index_tn_choice_tag;
    union {
        timing_adv_index_tn_struct p_dl_timing_adv_index_tn;
    } dl_timing_adv_index_tn_choice_value;
} global_pkt_tim_adv_struct;

typedef struct {
    kal_uint8 alpha; /* ALPHA*/
    kal_uint8 tavgw; /* T_AVG_W*/
    kal_uint8 tavgt; /* T_AVG_T*/
    kal_uint8 pb; /* PB*/
    kal_uint8 pc_meas_chan; /* PC MEAS CHAN*/
    kal_uint8 int_meas_ch_list; /* INT MEAS CHAN LIST AVAIL*/
    kal_uint8 navgi; /* N_AVG_I*/
} global_pwr_ctrl_params_struct;

typedef struct {
    global_pkt_tim_adv_struct g_pkt_tim_adv; /* GPKTTIMSTRUCT*/
    pwr_ctrl_params_peer_struct pwr_ctrl_params; /* PWRCONPARASTRUCT*/
} global_pwr_ctrl_pkt_tim_struct;

typedef struct {
    header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    msid1_enum tqi_tfi_choice_tag;
    union {
        global_tfistruct a_global_tfi;
        kal_uint16 a_tqi;
        pkt_req_ref_struct a_pkt_req_ref;
    } tqi_tfi_choice_value;
    kal_uint8 msgesc; /* MESSAGE ESCAPE*/
    ispresent gpwr_ctrlparams_choice_tag;
    union {
        global_pwr_ctrl_params_struct p_glo_pwr_ctrl_params;
    } gpwr_ctrlparams_choice_value;
    add_enum gpwr_ctrl_pkt_tim_choice_tag;
    union {
        global_pwr_ctrl_pkt_tim_struct gpwr_ctrl_pkt_timing;
        global_pkt_tim_adv_struct g_pkt_tim_adv_params;
        pwr_ctrl_params_peer_struct pwr_ctrl_params;
    } gpwr_ctrl_pkt_tim_choice_value;
} pkt_pwr_ctrl_tim_adv_struct;

typedef struct {
    kal_uint8 extended_dyn_alloc; /* EXT DYNAMIC ALLOCATION*/
    ispresent p0pr_mode_choice_tag;
    union {
        p0pr_mode_struct p_p0pr;
    } p0pr_mode_choice_value;
    kal_uint8 usf_granularity; /* USF GRANULARITY*/
    ispresent rlc_blks_granted_choice_tag;
    union {
        kal_uint8 p_rlc_blks_granted;
    } rlc_blks_granted_choice_value;
    ispresent tbf_starting_time_choice_tag;
    union {
        starting_frame_num_struct p_tbf_starting_time;
    } tbf_starting_time_choice_value;
    ispresent time_slot_pwr_ctrl_choice_tag;
    union {
        time_slot_alloc_struct a_time_slot_alloc;
        time_slot_pwr_ctrl_alloc_struct p_time_slot_alloc;
    } time_slot_pwr_ctrl_choice_value;
} ts_reconfig_dynamic_alloc_struct;

typedef struct {
    ispresent pwr_ctrl_time_slot_choice_tag;
    union {
        kal_uint8 a_time_slot_allocation;
        pwr_ctrl_params_peer_struct p_pwr_ctrl_params;
    } pwr_ctrl_time_slot_choice_value;
    kal_uint8 final_allocation; /* FINAL ALLOCATION*/
    kal_uint8 down_link_ctrl_time_slot; /* DOWN LINK CONTROL TIME SLOT*/
    ispresent pwr_ctrl_mode_choice_tag;
    union {
        bts_mode_struct p_pwr_ctrl_mode;
    } pwr_ctrl_mode_choice_value;
    ispresent meas_map_choice_tag;
    union {
        meas_map_peer_struct p_meas_map;
    } meas_map_choice_value;
    starting_frame_num_struct tbf_starting_time; /* TBF START TIME STRUCTURE*/
    kal_uint8 msgesc; /* MESSAGE ESCAPE*/
    alloc_struct alloc_bit_map; /* ALLOCATION BITMAP*/
} ts_reconfig_fixed_alloc_struct;
/* Evelyn 20090415: Merge R6 */
#ifdef __MTBF__
typedef struct {
    kal_uint8 dl_rb_id; /* MESSAGE ESCAPE*/
    kal_uint8 ul_rb_id; /* MESSAGE ESCAPE*/
} ul_dl_rb_id_struct;

typedef struct {
    ispresent dl_PFI_choice_tag;
    union {
        kal_uint8 p_dl_PFI;
    } dl_PFI_choice_value;
    ispresent ul_PFI_choice_tag;
    union {
        kal_uint8 p_ul_PFI;
    } ul_PFI_choice_value;
    ispresent ul_rlc_mode_choice_tag;
    union {
        kal_uint8 p_ul_rlc_mode;
    } ul_rlc_mode_choice_value;
} rel_6_ptr_struct;


typedef struct {
    ispresent RB_ID_choice_tag;
    union {
        ul_dl_rb_id_struct p_RB_ID;
    } RB_ID_choice_value;
    ispresent ul_ctrl_tn_choice_tag;
    union {
        kal_uint8 p_ul_ctrl_tn;
    } ul_ctrl_tn_choice_value;
    ispresent rel_6_choice_tag;
    union {
        rel_6_ptr_struct p_rel_6;
    } rel_6_choice_value;
} rel_5_later_ptr_struct;
#endif

typedef struct {
    kal_uint8 ch_coding_cmd; /* CHANNEL CODING COMMAND*/
    global_pkt_tim_adv_struct g_pkt_tim_adv; /* GLOBAL PACKET TIMING ADVANCE*/
    kal_uint8 dl_rlc_mode; /* DOWN LINK RLC MODE*/
    kal_uint8 ctrl_ack; /* CONTROL ACKNOWLEDGE*/
    ispresent dl_tfi_assgn_choice_tag;
    union {
        kal_uint8 p_dl_tfi;
    } dl_tfi_assgn_choice_value;
    ispresent ul_tfi_assgn_choice_tag;
    union {
        kal_uint8 p_ul_tfi;
    } ul_tfi_assgn_choice_value;
    kal_uint8 dl_timeslot_alloc; /* DOWNLINK ALLOCATION*/
    ispresent freq_params_choice_tag;
    union {
        freq_params_peer_struct p_freq_params;
    } freq_params_choice_value;
    ispresent alloc_type_choice_tag;
    union {
        ts_reconfig_dynamic_alloc_struct dynamic_alloc;
        ts_reconfig_fixed_alloc_struct fixed_alloc;
    } alloc_type_choice_value;
/* Evelyn 20090415: Merge R6 */
    ispresent rel99choice_tag;
    union {
        extend_timing_adv_struct p_rel99;
    } rel99choice_value;
#ifdef __MTBF__
    ispresent rel5_later_choice_tag;
    union {
        rel_5_later_ptr_struct p_rel5_later;
    } rel5_later_choice_value;
#endif
} gprs_timeslot_reconfig;

#ifdef __EGPRS_MODE__

typedef struct {
    kal_uint8 msgescape1; /* MESSAGE ESCAPE*/
    ispresent compact_choice_tag;
    union {
        kal_uint8 p_compact_reduced_ma;
    } compact_choice_value;
    kal_uint8 ch_coding_cmd; /* EGPRS CHANNEL CODING COMMAND*/
    kal_uint8 resegment; /* RESEGMENT*/
    /* Claire 041110 change : Solve egprs_timeslot_reconfig bug */
    #if 0
/* under construction !*/
    #endif
    ispresent dl_egprs_window_size_tag;
    union {
        kal_uint8 p_dl_egprs_window_size;
    } dl_egprs_window_size_value;
    ispresent ul_egprs_window_size_tag;
    union {
        kal_uint8 p_ul_egprs_window_size;
    } ul_egprs_window_size_value;
    /* End Claire 041110 change : Solve egprs_timeslot_reconfig bug */
    
    kal_uint8 lnk_quality_meas_mode; /* LINK QUALITY MEASUREMENT MODE*/
    global_pkt_tim_adv_struct g_pkt_tim_adv; /* GLOBAL PACKET TIMING ADVANCE*/
    ispresent extend_tim_adv_choice_tag;
    union {
        kal_uint8 pextend_tim_adv;
    } extend_tim_adv_choice_value;
    kal_uint8 dl_rlc_mode; /* DOWNLINK RLC MODE*/
    kal_uint8 control_ack; /* CONTROL ACK*/
    ispresent dl_tfi_assgn_tag;
    union {
        kal_uint8 p_dl_tfi_assgn;
    } dl_tfi_assgn_value;
    ispresent ul_tfi_assgn_tag;
    union {
        kal_uint8 p_ul_tfi_assgn;
    } ul_tfi_assgn_value;
    kal_uint8 dl_timeslot_alloc; /* DL TIMESLOT ALLOCATION*/
    ispresent freq_params_choice_tag;
    union {
        freq_params_peer_struct p_freq_params;
    } freq_params_choice_value;
    ispresent alloc_choice_tag;
    union {
        ts_reconfig_dynamic_alloc_struct a_dynamic_alloc;
        ts_reconfig_fixed_alloc_struct p_fixed_alloc;
    } alloc_choice_value;
/* Evelyn 20090415: Merge R6 */
#ifdef __MTBF__
    ispresent rel5_later_choice_tag;
    union {
        rel_5_later_ptr_struct p_rel5_later;
    } rel5_later_choice_value;
#endif
} egprs_timeslot_reconfig;

typedef struct {
    header_struct header; /* HEADER*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGEMODE*/
    ispresent global_tfi_tag;
    union {
        global_tfistruct global_tfi;
    } global_tfi_value;
    ispresent gprs_choice_tag;
    union {
        gprs_timeslot_reconfig a_gprs_timeslot_reconfig;
        egprs_timeslot_reconfig p_egprs_timeslot_reconfig;
    } gprs_choice_value;
} pkt_timeslot_reconfigure;
#else
typedef struct {
    header_struct header; /* HEADER*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGEMODE*/
    ispresent global_tfi_tag;
    union {
        global_tfistruct global_tfi;
    } global_tfi_value;
    kal_uint8 msgesc; /* MESSAGE ESCAPE*/
    gprs_timeslot_reconfig gprs_timeslot_reconfig_inst; /* TIMESLOT RECONFIG STRUCTURE*/
} pkt_timeslot_reconfigure;
#endif

typedef struct {
    header_struct header; /* HEADER*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    msid_enum ms_id_choice_tag;
    union {
        global_tfistruct global_tfi;
        kal_uint32 tlli;
        kal_uint16 tqi;
    } ms_id_choice_value;
    kal_uint8 typeof_ack; /* TYPE_OF_ACK*/
} packet_polling_request;
#endif 


