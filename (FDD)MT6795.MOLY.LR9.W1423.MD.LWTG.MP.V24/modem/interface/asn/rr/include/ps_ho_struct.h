/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : ps_ho_struct.h
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

#ifndef _PS_HO_STRUCT_H
#define _PS_HO_STRUCT_H

typedef struct {
    kal_uint8 rrc_container_length; /* RRC CONTAINER OFFSET*/
    kal_uint8* rrc_container_data;
} rrc_container_ie;

typedef struct {
    kal_uint8 nas_container_offset; /* NAS CONTAINER OFFSET*/
    kal_uint8 *nas_container_data; /* NAS CONTAINER OFFSET*/
} nas_container_ie;

typedef struct {
    global_pkt_tim_adv_struct g_pkt_tim_adv; /* GLOBAL PACKET TIMING ADVANCE*/
    ispresent extend_tim_adv_choice_tag;
    union {
        kal_uint8 p_extend_tim_adv;
    } extend_tim_adv_choice_value;
} global_and_extended_timing_adv_struct;

typedef struct {
    kal_uint8 timeslot_alloc; /* TIMESLOT ALLOCATION*/
    ispresent pfi_choice_tag;
    union {
        kal_uint8 p_pfi;
    } pfi_choice_value;
    kal_uint8 rlc_mode; /* RLC MODE*/
    kal_uint8 downlink_tfi; /* DOWN LINK TFI*/
    kal_uint8 ctrl_ack; /* CONTROL ACK*/
    egprs_window_size_struct egprs_window; /* EDGE Window Size*/
} ps_ho_downlink_tbf_assign_struct;

typedef struct {
    egprs_window_size_struct egprs_window; /* EDGE Window Size*/
    kal_uint8 link_quality_mode; /* LINK QUALITY MEASUREMENT MODE*/
    ispresent bep_period_choice_tag;
    union {
        kal_uint8 p_bep_period2;
    } bep_period_choice_value;
} ps_ho_edge_dl_struct;

typedef struct {
    ispresent ps_ho_edge_dl_choice_tag;
    union {
        ps_ho_edge_dl_struct p_ps_ho_edge_dl;
    } ps_ho_edge_dl_choice_value;
    unsigned int no_ps_ho_dl_tbf_assign;
    unsigned int ps_ho_dl_tbf_assign_size;
    ps_ho_downlink_tbf_assign_struct *ps_ho_dl_tbf_assign;
} ps_ho_edge_dl_exist;

typedef struct {
    ispresent cs_choice_tag;
    union {
        kal_uint8 p_coding_scheme;
    } cs_choice_value;
    ispresent global_tn_choice_tag;
    union {
        timeslot_desc_struct p_global_tn;
    } global_tn_choice_value;
    unsigned int no_ps_ho_dl_tbf_assign;
    unsigned int ps_ho_dl_tbf_assign_size;
    ps_ho_downlink_tbf_assign_struct *ps_ho_dl_tbf_assign;
} gprs_mode_struct;

typedef struct {
    ispresent egprs_window_size_choice_tag;
    union {
        kal_uint8 p_global_egprs_window_size;
    } egprs_window_size_choice_value;
    ispresent egprs_cs_choice_tag;
    union {
        kal_uint8 p_global_egprs_cs;
    } egprs_cs_choice_value;
    ispresent bep_period_choice_tag;
    union {
        kal_uint8 p_bep_period2;
    } bep_period_choice_value;
    ispresent global_tn_choice_tag;
    union {
        timeslot_desc_struct p_global_tn;
    } global_tn_choice_value;
    ispresent dl_tbf_choice_tag;
    union {
        ps_ho_edge_dl_exist p_dl_tbf;
    } dl_tbf_choice_value;
} egprs_mode_struct;

typedef struct {
    ispresent ho_ref_choice_tag;
    union {
        kal_uint8 p_ho_ref;
    } ho_ref_choice_value;
    kal_uint16 arfcn; /* ARFCN*/
    kal_uint8 si; /* SI*/
    kal_uint8 nci; /* NCI*/
    kal_uint8 BSIC; /* BSIC*/
    ispresent ccn_active_choice_tag;
    union {
        kal_uint8 p_ccn_active;
    } ccn_active_choice_value;
    ispresent utran_ccn_active_choice_tag;
    union {
        // need modify
        kal_uint8 p_3g_ccn_active;
    } utran_ccn_active_choice_value;
    ispresent ccn_desc_choice_tag;
    union {
        kal_uint8 p_ccn_desc;
    } ccn_desc_choice_value;
    freq_params_peer_struct freq_param; /* FREQUENCY PARAMETERS*/
    kal_uint8 NCO; /* NETWORK CONTROL MODE*/
    ispresent timing_adv_choice_tag;
    union {
        global_and_extended_timing_adv_struct p_timing_adv;
    } timing_adv_choice_value;
    kal_uint8 extended_da; /* EXTENDED DYNAMIC ALLOCATION*/
    kal_uint8 rlc_reset; /* RLC_RESET*/
    ispresent p0pr_choice_tag;
    union {
        p0pr_mode_struct p_p0pr;
    } p0pr_choice_value;
    ispresent ul_ctrl_tn_choice_tag;
    union {
        kal_uint8 p_ul_ctrl_tn;
    } ul_ctrl_tn_choice_value;
    ispresent tbf_mode_choice_tag;
    union {
        gprs_mode_struct a_gprs_mode;
        egprs_mode_struct p_egprs_mode;
    } tbf_mode_choice_value;
} ps_ho_radio_resource_struct;

typedef struct {
    ispresent rr_info_choice_tag;
    union {
        ps_ho_radio_resource_struct rr_info;
    } rr_info_choice_value;
    ispresent nas_container_choice_tag;
    union {
        nas_container_ie p_nas_container;
    } nas_container_choice_value;
} ps_ho_to_geran_struct;

typedef struct {
    header_struct header; /* HEADER*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    kal_uint8 msgesc1; /* MESSAGE ESCAPE*/
    global_tfistruct global_tfi; /* GLOBAL TFI*/
    kal_uint8 container_id; /* CONTAINER ID*/
    ispresent ps_ho_dir_choise_tag;
    union {
        ps_ho_to_geran_struct ps_ho_to_geran;
        rrc_container_ie ps_ho_to_utran;
    } ps_ho_dir_choise_value;
} ps_ho_command_struct;
#endif 
