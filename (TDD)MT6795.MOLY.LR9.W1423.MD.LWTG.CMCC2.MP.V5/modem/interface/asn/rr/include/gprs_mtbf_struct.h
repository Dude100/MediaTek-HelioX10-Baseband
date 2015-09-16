/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : gprs_mtbf_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */

#include "kal_general_types.h"
#include "rr_common_def.h"
#include "gprs_rlcmac_dl_struct.h"
#include "gprs_rlcmac_common_struct.h"

 /* Evelyn 20090415: Merge R6 */

#ifndef _GPRS_MTBF_STRUCT_H
#define _GPRS_MTBF_STRUCT_H

typedef struct {
    kal_uint32 tlli_or_grnti; /* TLLI or G-RNTI*/
    kal_uint8 g_rnti_ext; /* G-RNTI EXTENTION*/
} tlli_g_rnti_struct;

typedef struct {
    kal_uint8 p0; /* P0*/
    kal_uint8 pr_mode; /* PR_MODE*/
} bts_mode_modify_struct;

typedef struct {
    ispresent egprs_window_size_choice_tag;
    union {
        kal_uint8 p_egprs_window_size;
    } egprs_window_size_choice_value;
} egprs_window_size_struct;

typedef struct {
    ispresent hfn_lsb_choice_tag;
    union {
        kal_uint8 p_hfn_lsb;
    } hfn_lsb_choice_value;
} hfn_lsb_struct;

typedef struct {
    kal_uint8 pfi; /* PFI*/
    kal_uint8 rlcmode; /* RLC MODE*/
} pfi_rlcmode_struct;

typedef struct {
    ispresent RB_PFI_choice_tag;
    union {
        kal_uint8 rb;
        pfi_rlcmode_struct pfi;
    } RB_PFI_choice_value;
} tbf_address_rel6_struct;

typedef struct {
    tbf_address_rel6_struct tbf_address; /* TBF addressed*/
    kal_uint8 downlink_tfi; /* DOWN LINK TFI*/
    kal_uint8 ctrl_ack; /* CONTROL ACK*/
    egprs_window_size_struct egprs_window; /* EDGE Window Size*/
    hfn_lsb_struct hfn_lsb; /* HFN_LSB*/
} downlink_tbf_assign_struct;

typedef struct {
    kal_uint8 timeslot; /* Timeslot allocation*/
    unsigned int no_downlink_tbf_assign;
    unsigned int downlink_tbf_assign_size;
    downlink_tbf_assign_struct *downlink_tbf_assign;
} mtbf_downlink_tbf_assign_struct;

typedef struct {
    ispresent egprs_ws_choice_tag;
    union {
        kal_uint8 p_egprs_ws;
    } egprs_ws_choice_value;
    kal_uint8 link_quality_meas_mode; /* link quality measurement mode*/
    ispresent bep_period_choice_tag;
    union {
        kal_uint8 p_bep_period2;
    } bep_period_choice_value;
} egprsdl_assign_additions_mtbf_struct;

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
        tlli_g_rnti_struct tlli_g_rnti;
    } ms_add_choice_value;
    kal_uint8 msgescape; /* MESSAGE ESCAPE*/
    pkt_timing_advance_struct pkt_time_adv_value; /* PACKET TIMING ADVANCE STRUCTURE*/
    ispresent pwr_ctrl_mode_choice_tag;
    union {
        bts_mode_modify_struct p_pwr_ctrl_mode;
    } pwr_ctrl_mode_choice_value;
    ispresent freq_params_choice_tag;
    union {
        freq_params_peer_struct p_freq_params;
    } freq_params_choice_value;
    ispresent pwr_ctrl_param_choice_tag;
    union {
        pwr_ctrl_params_peer_struct p_power_ctrl_param_value;
    } pwr_ctrl_param_choice_value;
    ispresent tbf_starting_time_choice_tag;
    union {
        starting_frame_num_struct p_tbf_starting_time;
    } tbf_starting_time_choice_value;
    ispresent rel99choice_tag;
    union {
        egprsdl_assign_additions_mtbf_struct p_rel99;
    } rel99choice_value;
    ispresent extend_timing_adv_choice_tag;
    union {
        kal_uint8 p_extend_timng_adv;
    } extend_timing_adv_choice_value;
    ispresent uplink_ctrl_tn_choice_tag;
    union {
        kal_uint8 p_uplink_ctrl_tn;
    } uplink_ctrl_tn_choice_value;
    unsigned int no_mtbf_downlink_tbf_assign;
    unsigned int mtbf_downlink_tbf_assign_size;
    mtbf_downlink_tbf_assign_struct *mtbf_downlink_tbf_assign;
} mtbf_downlink_assign;

typedef struct {
    ispresent gamma_choice_tag;
    union {
        kal_uint8 p_gamma;
    } gamma_choice_value;
} gamma_choise_struct;

typedef struct {
    kal_uint8 alpha; /* GAMMA*/
    gamma_choise_struct gamma_tn[8];
} alpha_gamma_choise_struct;

typedef struct {
    ispresent usf_alloc_choice_tag;
    union {
        kal_uint8 p_usf_alloc;
    } usf_alloc_choice_value;
} usf_alloc_struct;

typedef struct {
    kal_uint8 usf_alloc; /* USF ALLOCATION*/
    usf_alloc_struct nex_usf_alloc[7];
} different_usf_alloc_struct;

typedef struct {
    tbf_address_rel6_struct tbf_address; /* TBF addressed*/
    kal_uint8 uplink_tfi; /* UPLINK TFI*/
    ispresent cs_choice_tag;
    union {
        kal_uint8 p_coding_scheme;
    } cs_choice_value;
    ispresent egprs_cs_choice_tag;
    union {
        kal_uint8 p_global_egprs_cs;
    } egprs_cs_choice_value;
    ispresent egprs_window_size_choice_tag;
    union {
        kal_uint8 p_global_egprs_window_size;
    } egprs_window_size_choice_value;
    kal_uint8 usf_granularity; /* USF GRANULARITY*/
    ispresent tbf_tn_choice_tag;
    union {
        kal_uint8 p_tbf_tn;
    } tbf_tn_choice_value;
    ispresent usf_choice_tag;
    union {
        kal_uint8 global_usf;
        different_usf_alloc_struct diff_usf;
    } usf_choice_value;
    kal_uint8 tn_pos[8]; /* UL TN allocation based on 8 timeslot decription*/
    kal_uint8 usf_on_tn[8]; /* USF allocation based on 8 timeslot decription*/
} uplink_tbf_assign_struct;

typedef struct {
    ispresent timeslot_desc_choice_tag;
    union {
        kal_uint8 ms_tn_alloc;
        alpha_gamma_choise_struct tn_pwr_ctrl_alloc;
    } timeslot_desc_choice_value;
    unsigned int no_uplink_tbf_assign;
    unsigned int uplink_tbf_assign_size;
    uplink_tbf_assign_struct *uplink_tbf_assign;
    kal_uint8 ms_tn;
} timeslot_desc_struct;

typedef struct {
    kal_uint8 extended_dyn_alloc; /* EXT DYNAMIC ALLOCATION*/
    ispresent uplink_ctrl_tn_choice_tag;
    union {
        kal_uint8 p_uplink_ctrl_tn;
    } uplink_ctrl_tn_choice_value;
    ispresent p0pr_mode_choice_tag;
    union {
        p0pr_mode_struct p_p0pr;
    } p0pr_mode_choice_value;
    ispresent tbf_starting_time_choice_tag;
    union {
        starting_frame_num_struct p_tbf_starting_time;
    } tbf_starting_time_choice_value;
    ispresent global_tn_choice_tag;
    union {
        timeslot_desc_struct p_global_tn;
    } global_tn_choice_value;
} uplink_assign_struct;

typedef struct {
    ispresent global_cs_choice_tag;
    union {
        kal_uint8 p_coding_scheme;
    } global_cs_choice_value;
    kal_uint8 tlli_blk_ch_code; /* TLLI CODE*/
    pkt_timing_advance_struct pkt_time_adv_value; /* PACKET TIMING ADVANCE STRUCTURE*/
    ispresent extend_timing_adv_choice_tag;
    union {
        kal_uint8 p_extend_timng_adv;
    } extend_timing_adv_choice_value;
    ispresent freq_params_choice_tag;
    union {
        freq_params_peer_struct p_freq_params;
    } freq_params_choice_value;
    ispresent uplink_assign_choice_tag;
    union {
        uplink_assign_struct p_uplink_tbf;
    } uplink_assign_choice_value;
} gprs_uplink_assign_mtbf_struct;

typedef struct {
    kal_uint8 msgescape; /* MESSAGE ESCAPE*/
    ispresent global_egprs_window_size_choice_tag;
    union {
        kal_uint8 p_global_egprs_window_size;
    } global_egprs_window_size_choice_value;
    ispresent global_egprs_cs_choice_tag;
    union {
        kal_uint8 p_global_egprs_cs;
    } global_egprs_cs_choice_value;
    kal_uint8 resegment; /* RESEGMENT*/
    kal_uint8 tlli_blk_ch_code; /* TLLI CODE*/
    ispresent bep_period2_choice_tag;
    union {
        kal_uint8 p_bep_period2;
    } bep_period2_choice_value;
    pkt_timing_advance_struct pkt_time_adv_value; /* PACKET TIMING ADVANCE STRUCTURE*/
    ispresent extend_timing_adv_choice_tag;
    union {
        kal_uint8 p_extend_timng_adv;
    } extend_timing_adv_choice_value;
    ispresent freq_params_choice_tag;
    union {
        freq_params_peer_struct p_freq_params;
    } freq_params_choice_value;
    ispresent uplink_assign_choice_tag;
    union {
        uplink_assign_struct p_uplink_tbf;
    } uplink_assign_choice_value;
} egprs_uplink_assign_mtbf_struct;

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
        tlli_g_rnti_struct tlli_g_rnti;
    } ms_add_choice_value;
    ispresent uplink_assgn_mtbf_choice_tag;
    union {
        gprs_uplink_assign_mtbf_struct a_gprs_uplink_assign_mtbf;
        egprs_uplink_assign_mtbf_struct p_egprs_uplink_assign_mtbf;
    } uplink_assgn_mtbf_choice_value;
} mtbf_uplink_assign;

typedef struct {
    tbf_address_rel6_struct tbf_address; /* TBF addressed*/
    ispresent uplink_ctrl_tn_choice_tag;
    union {
        kal_uint8 p_uplink_ctrl_tn;
    } uplink_ctrl_tn_choice_value;
    kal_uint8 downlink_tfi; /* DOWN LINK TFI*/
    kal_uint8 ctrl_ack; /* CONTROL ACK*/
    egprs_window_size_struct egprs_window; /* EDGE Window Size*/
} ts_reconfig_dl_tbf_assign_struct;

typedef struct {
    kal_uint8 timeslot; /* Timeslot allocation*/
    ispresent uplink_ctrl_tn_choice_tag;
    union {
        kal_uint8 p_uplink_ctrl_tn;
    } uplink_ctrl_tn_choice_value;
    unsigned int no_downlink_tbf_assign;
    unsigned int downlink_tbf_assign_size;
    ts_reconfig_dl_tbf_assign_struct *downlink_tbf_assign;
} ts_reconfig_dl_tbf_assign_mtbf_struct;

typedef struct {
    kal_uint8 extended_dyn_alloc; /* EXT DYNAMIC ALLOCATION*/
    ispresent p0pr_mode_choice_tag;
    union {
        p0pr_mode_struct p_p0pr;
    } p0pr_mode_choice_value;
    ispresent tbf_starting_time_choice_tag;
    union {
        starting_frame_num_struct p_tbf_starting_time;
    } tbf_starting_time_choice_value;
    ispresent global_tn_choice_tag;
    union {
        timeslot_desc_struct p_global_tn;
    } global_tn_choice_value;
} ts_reconfig_ul_assign_struct;

typedef struct {
    ispresent global_cs_choice_tag;
    union {
        kal_uint8 p_coding_scheme;
    } global_cs_choice_value;
    global_pkt_tim_adv_struct g_pkt_tim_adv; /* GLOBAL PACKET TIMING ADVANCE*/
    ispresent freq_params_choice_tag;
    union {
        freq_params_peer_struct p_freq_params;
    } freq_params_choice_value;
    ispresent extend_timing_adv_choice_tag;
    union {
        kal_uint8 p_extend_timng_adv;
    } extend_timing_adv_choice_value;
    unsigned int no_ts_reconfig_dl_tbf_assign_mtbf;
    unsigned int ts_reconfig_dl_tbf_assign_mtbf_size;
    ts_reconfig_dl_tbf_assign_mtbf_struct *ts_reconfig_dl_tbf_assign_mtbf;
    ts_reconfig_ul_assign_struct uplink_tbf; /* Multiple Uplink Assignment*/
} gprs_ts_reconfig_mtbf_struct;

typedef struct {
    kal_uint8 msgescape; /* MESSAGE ESCAPE*/
    ispresent global_egprs_cs_choice_tag;
    union {
        kal_uint8 p_global_egprs_cs;
    } global_egprs_cs_choice_value;
    kal_uint8 resegment; /* RESEGMENT*/
    ispresent dl_egprs_window_size_choice_tag;
    union {
        kal_uint8 p_global_egprs_window_size;
    } dl_egprs_window_size_choice_value;
    ispresent rel99choice_tag;
    union {
        egprsdl_assign_additions_mtbf_struct p_rel99;
    } rel99choice_value;
    global_pkt_tim_adv_struct g_pkt_tim_adv; /* GLOBAL PACKET TIMING ADVANCE*/
    ispresent extend_timing_adv_choice_tag;
    union {
        kal_uint8 p_extend_timng_adv;
    } extend_timing_adv_choice_value;
    ispresent freq_params_choice_tag;
    union {
        freq_params_peer_struct p_freq_params;
    } freq_params_choice_value;
    unsigned int no_ts_reconfig_dl_tbf_assign_mtbf;
    unsigned int ts_reconfig_dl_tbf_assign_mtbf_size;
    ts_reconfig_dl_tbf_assign_mtbf_struct *ts_reconfig_dl_tbf_assign_mtbf;
    ts_reconfig_ul_assign_struct uplink_tbf; /* Multiple Uplink Assignment*/
} egprs_ts_reconfig_mtbf_struct;

typedef struct {
    header_struct header; /* HEADER*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    kal_uint8 msgesc1; /* MESSAGE ESCAPE*/
    global_tfistruct global_tfi; /* GLOBAL TFI*/
    ispresent ts_reconfig_mtbf_choice_tag;
    union {
        gprs_ts_reconfig_mtbf_struct a_gprs_ts_reconfig_mtbf;
        egprs_ts_reconfig_mtbf_struct p_egprs_ts_reconfig_mtbf;
    } ts_reconfig_mtbf_choice_value;
} mtbf_timeslot_reconfigure_assign;
#endif 
