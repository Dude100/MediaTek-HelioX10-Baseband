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
 *  rmc_peer_dl_struct.h
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
 *  FILENAME : rmc_peer_dl_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _RMC_PEER_DL_STRUCT_H
#define _RMC_PEER_DL_STRUCT_H

#ifdef __PS_SERVICE__
#include "gprs_rlcmac_dl_struct.h"
#endif
#include "rmc_peer_dl.h"
#include "rr_common_def.h"
#include "nstd_alloc_bitmap_struct.h"
#include "rr_spare_bit.h"

#ifdef __PS_SERVICE__
typedef struct {
    kal_uint8 length;
    kal_uint8 mac_mode;
    kal_uint8 rlc_mode;
    kal_uint8 timeslot_alloc;
    pkt_timing_advance_struct pkt_time_adv_value; /* PACKET TIMING ADVANCE STRUCTURE*/
    enum_is_present p0pr_choice_tag;
    union {
        bts_mode_struct p0pwr_mode;
    } p0pr_choice_value;
    enum_is_present pwr_ctrl_param_choice_tag;
    union {
        pwr_ctrl_params_peer_struct p_power_ctrl_param_value;
    } pwr_ctrl_param_choice_value;
    enum_is_present downlink_choice_tag;
    union {
        kal_uint8 downlink_assignment;
    } downlink_choice_value;
    enum_is_present meas_map_choice_tag;
    union {
        meas_map_peer_struct p_measurement_map;
    } meas_map_choice_value;
    enum_is_present pkt_choice_tag;
    union {
        kal_uint8 pkttime_advance;
    } pkt_choice_value;
} rr_packet_downlink_struct;

typedef struct {
    kal_uint8 extended_dyn_alloc; /* EXT DYNAMIC ALLOCATION*/
    enum_is_present p0pr_mode_choice_tag;
    union {
        p0pr_mode_struct p_p0pr;
    } p0pr_mode_choice_value;
    kal_uint8 usf_granularity; /* USF GRANULARITY*/
    enum_is_present tfi_assignment_choice_tag;
    union {
        kal_uint8 p_tfi_assignment;
    } tfi_assignment_choice_value;
    enum_is_present rlc_blks_granted_choice_tag;
    union {
        kal_uint8 p_rlc_blks_granted;
    } rlc_blks_granted_choice_value;
    enum_is_present time_slot_pwr_ctrl_choice_tag;
    union {
        time_slot_alloc_struct a_time_slot_alloc;
        time_slot_pwr_ctrl_alloc_struct p_time_slot_alloc;
    } time_slot_pwr_ctrl_choice_value;
} pdch_dynamic_alloc_struct;

typedef struct {
    kal_uint8 time_slot_no; /* TIME SLOT NUMBER*/
    enum_is_present alpha_gamma_choice_tag;
    union {
        alpha_gamma_struct p_alpha_gamma;
    } alpha_gamma_choice_value;
    enum_is_present pwr_ctrl_mode_choice_tag;
    union {
        bts_mode_struct p_pwr_ctrl_mode;
    } pwr_ctrl_mode_choice_value;
} pdch_single_blk_alloc_struct;

typedef struct {
    enum_is_present up_link_tfichoice_tag;
    union {
        kal_uint8 p_uplink_tfi_assgn;
    } up_link_tfichoice_value;
    kal_uint8 final_allocation; /* FINAL ALLOCATION*/
    kal_uint8 down_link_ctrl_time_slot; /* DOWN LINK CONTROL TIME SLOT*/
    enum_is_present pwr_ctrl_mode_choice_tag;
    union {
        bts_mode_struct p_pwr_ctrl_mode;
    } pwr_ctrl_mode_choice_value;
    ispresent pwr_ctrl_time_slot_choice_tag;
    union {
        kal_uint8 a_time_slot_allocation;
        pwr_ctrl_params_peer_struct p_pwr_ctrl_params;
    } pwr_ctrl_time_slot_choice_value;
    kal_uint8 half_duplex_mode; /* HALF DUPLEX MODE*/
    kal_uint8 msgesc; /* MESSAGE ESCAPE*/
    alloc_struct alloc_bit_map; /* ALLOCATION BITMAP*/
} pdch_fixed_alloc_struct;

typedef struct {
    kal_uint8 length;
    kal_uint8 ch_coding_command;
    kal_uint8 tlli_block_ch_coding;
    pkt_timing_advance_struct pkt_time_adv_value; /* PACKET TIMING ADVANCE STRUCTURE*/
    challoc_enum alloc_type_choice_tag;
    union {
        pdch_dynamic_alloc_struct dynamic_alloc;
        pdch_single_blk_alloc_struct single_blk_alloc;
        pdch_fixed_alloc_struct fixed_alloc;
    } alloc_type_choice_value;
    enum_is_present time_choice_tag;
    union {
        kal_uint8 packet_ext_time_advance;
    } time_choice_value;
} rr_packet_uplink_struct;

#endif
typedef struct {
    kal_uint8 t1;
    kal_uint8 t3;
    kal_uint8 t2;
} rmc_start_time_struct;

typedef struct {
    kal_uint8 start_time_structP;
    rmc_start_time_struct start_time_struct;
} starting_time;

#ifdef __PS_SERVICE__
typedef struct {
    kal_uint8 p0;
    kal_uint8 bts_pwr_cntrl_mode;
    kal_uint8 pr_mode;
} rmc_p0_pwr_cntrl_mode_struct;

typedef struct {
    enum_is_present alpha_tag;
    union {
        kal_uint8 alpha;
    } alpha_value;
    kal_uint8 gamma;
    kal_uint8 control_bits; /* always set to 01 for compatibility with
                                      rel '97.*/
    rmc_start_time_struct tbf_start_time;
    rr_spare_bit_enum pwr_cntrl_mode_tag;
    union {
        rmc_p0_pwr_cntrl_mode_struct pwr_cntrl_mode;
    } pwr_cntrl_mode_value;
} rmc_single_block_alloc_struct;

typedef struct {
    kal_uint8 p0;
    kal_uint8 pr_mode;
} rmc_p0_pr_mode_struct;

typedef struct {
    kal_uint8 usf;
    kal_uint8 usf_gran;
    enum_is_present p0pr_mode_tag;
    union {
        rmc_p0_pr_mode_struct p0pr_mode;
    } p0pr_mode_value;
} rmc_dyn_alloc_struct;

typedef struct {
    kal_uint32 alloc_bit_map_bits:5;
    kal_uint32 alloc_bit_map;
    enum_is_present p0pwr_cntrl_mode_tag;
    union {
        rmc_p0_pwr_cntrl_mode_struct p0pwr_cntrl_mode;
    } p0pwr_cntrl_mode_value;
} rmc_fixed_alloc_struct;

typedef struct {
    kal_uint8 tfi_assign;
    kal_uint8 polling;
    enum_is_present alloc_info_tag;
    union {
        rmc_dyn_alloc_struct dyn;
        rmc_fixed_alloc_struct fixed;
    } alloc_info_value;
    kal_uint8 chan_coding_command;
    kal_uint8 tlli_blk_chan_coding;
    enum_is_present alpha_tag;
    union {
        kal_uint8 alpha;
    } alpha_value;
    kal_uint8 gamma;
    enum_is_present timing_adv_tag;
    union {
        kal_uint8 timing_adv_index;
    } timing_adv_value;
    enum_is_present tbf_start_time_tag;
    union {
        rmc_start_time_struct tbf_start_time;
    } tbf_start_time_value;
} rmc_dyn_or_fixed_alloc_struct;

typedef struct {
    enum_is_present alloc_info_tag;
    union {
        rmc_single_block_alloc_struct single_blk_alloc;
        rmc_dyn_or_fixed_alloc_struct dyn_or_fixed_alloc;
    } alloc_info_value;
} rmc_pkt_ul_asgn_struct;

#ifdef __EGPRS_MODE__
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
#endif

typedef struct {
    enum_is_present ch1_tag;
    union {
        kal_uint8 alpha;
    } ch1_value;
    kal_uint8 gamma;
    rmc_start_time_struct tbf_start_time;
    kal_uint8 no_of_blks_alloc;
    enum_is_present ch2_tag;
    union {
        rmc_p0_pwr_cntrl_mode_struct p0;
    } ch2_value;
} rmc_multi_blk_alloc_struct;

typedef struct {
    kal_uint8 mod_and_coding_scheme;
} rmc_egprs_mod_and_coding_struct;

typedef struct {
    kal_uint8 window_size;
} rmc_egprs_window_size_struct;

typedef struct {
    kal_uint8 tfi_assign;
    kal_uint8 polling;
    enum_is_present ch1_tag;
    union {
        rmc_dyn_alloc_struct dyn;
        rmc_fixed_alloc_struct fixed;
    } ch1_value;
    rmc_egprs_mod_and_coding_struct chan_coding_command;
    kal_uint8 tlli_blk_chan_coding;
    enum_is_present ch2_tag;
    union {
        kal_uint8 bep_period2;
    } ch2_value;
    kal_uint8 resegment;
    rmc_egprs_window_size_struct window_size;
    enum_is_present ch3_tag;
    union {
        kal_uint8 alpha;
    } ch3_value;
    kal_uint8 gamma;
    enum_is_present ch4_tag;
    union {
        kal_uint8 timing_adv;
    } ch4_value;
    enum_is_present ch5_tag;
    union {
        rmc_start_time_struct tbf_start_time;
    } ch5_value;
} rmc_egprs_dyn_or_fixed_alloc_struct;

typedef struct {
    /* Claire 041217 change : Solve IA EGPRS PUAS unpack missing extended_ra bug */
    kal_uint8 extended_ra;    
    enum_is_present ch1_tag;
    union {
        rmc_access_tech_req_struct access_tech_req;
    } ch1_value;
    enum_is_present ch2_tag;
    union {
        rmc_multi_blk_alloc_struct multi_blk_alloc;
        rmc_egprs_dyn_or_fixed_alloc_struct egprs_dyn_or_fixed_alloc;
    } ch2_value;
} rmc_egprs_pkt_ul_asgn_struct;

#endif

typedef struct {
    kal_uint8 no_freq_params;
    kal_uint8 freq_params_size;
    kal_uint8 *freq_params; /* the first six bits indicate the
                                        length which could be anywhere
                                        between 0 and 61. the lease
                                        significant 6 bits of the first octet
                                        that follows the length bits is 
                                        the MAIO field.*/
} rmc_freq_params_with_length_struct;

typedef struct {
    kal_uint8 tfi_assign;
    kal_uint8 rlc_mode;
    enum_is_present ch1_tag;
    union {
        kal_uint8 alpha;
    } ch1_value;
    kal_uint8 gamma;
    kal_uint8 polling;
    kal_uint8 ta_valid;
} rmc_rlc_mode_alpha_gamma_struct;

/* Claire 041127 change : Correct rmc_pkt_dl_asgn_struct pack unpack bug */
#ifdef __EGPRS_MODE__
typedef struct {
    kal_uint32 tlli;
    enum_is_present rlc_mode_tag;
    union {
        rmc_rlc_mode_alpha_gamma_struct rlc_mode_pwr_cntrl;
    } rlc_mode_value;
    enum_is_present timing_adv_tag;
    union {
        kal_uint8 timing_adv_index;
    } timing_adv_value;
    enum_is_present tbf_start_time_tag;
    union {
        rmc_start_time_struct tbf_start_time;
    } tbf_start_time_value;
    enum_is_present pwr_cntrl_tag;
    union {
        rmc_p0_pwr_cntrl_mode_struct p0pwr_cntrl_mode;
    } pwr_cntrl_value;
    enum_is_present egprs_ws_link_quality_choice_tag;
    union {
        egprsws_link_quality p_egprs_ws_link_quality;
    } egprs_ws_link_quality_choice_value;
 } rmc_pkt_dl_asgn_struct;

#else
typedef struct {
    kal_uint32 tlli;
    enum_is_present rlc_mode_tag;
    union {
        rmc_rlc_mode_alpha_gamma_struct rlc_mode_pwr_cntrl;
    } rlc_mode_value;
    enum_is_present timing_adv_tag;
    union {
        kal_uint8 timing_adv_index;
    } timing_adv_value;
    enum_is_present tbf_start_time_tag;
    union {
        rmc_start_time_struct tbf_start_time;
    } tbf_start_time_value;
    enum_is_present pwr_cntrl_tag;
    union {
        rmc_p0_pwr_cntrl_mode_struct p0pwr_cntrl_mode;
    } pwr_cntrl_value;
} rmc_pkt_dl_asgn_struct;
#endif

#ifdef __EGPRS_MODE__
typedef struct {
    chan_asgn_type chan_asgn_tag;
    union {
        rmc_egprs_pkt_ul_asgn_struct egprs_pkt_ul_asgn;
        rmc_freq_params_with_length_struct freq_params;
        rmc_pkt_ul_asgn_struct pkt_ul_asgn;
        rmc_pkt_dl_asgn_struct pkt_dl_asgn;
    } chan_asgn_value;
} iarest_octets;
#else
typedef struct {
    chan_asgn_type chan_asgn_tag;
    union {
        rmc_freq_params_with_length_struct freq_params;
        rmc_pkt_ul_asgn_struct pkt_ul_asgn;
        rmc_pkt_dl_asgn_struct pkt_dl_asgn;
    } chan_asgn_value;
} iarest_octets;
#endif 
#endif   //simon
#endif 


