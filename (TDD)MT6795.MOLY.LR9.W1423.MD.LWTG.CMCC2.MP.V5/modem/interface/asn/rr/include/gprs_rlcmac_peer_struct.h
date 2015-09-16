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
 *  gprs_rlcmac_peer_struct.h
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
 *  FILENAME : gprs_rlcmac_peer_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _GPRS_RLCMAC_PEER_STRUCT_H
#define _GPRS_RLCMAC_PEER_STRUCT_H

/*Evelyn: Remove redundant header and file */
#include "gprs_rlcmac_common_struct.h"
#include "rr_common_def.h"
#include "gprs_rlcmac_dl_struct.h"
#include "gprs_rlcmac_ul_struct.h"
#include "nstd_pmo_struct.h"

typedef struct {
    kal_uint8 acc_tech_type; /* access tech. type*/
} access_tech_struct;

typedef struct {
    unsigned int no_acc_tech_list;
    unsigned int acc_tech_list_size;
    access_tech_struct *acc_tech_list;
} access_tech_list;

typedef struct {
    header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    ispresent persist_level_choice_tag;
    union {
        persist_level_struct p_persistence_level;
    } persist_level_choice_value;
} pkt_downlink_dummy_ctrl_blk;

typedef struct {
    header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    ispresent time_slot_alloc_choice_tag;
    union {
        kal_uint8 p_time_slot_alloted;
    } time_slot_alloc_choice_value;
} packet_pdchrelease;

typedef struct {
    header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    global_tfistruct global_tfi; /* GLOBAL TFI STRUCT*/
    kal_uint8 tbf_cause; /* TBF CAUSE*/
    ispresent status_choice_tag;
    union {
        kal_uint8 p_status_msg_type;
    } status_choice_value;
} pkt_mobile_tbfstatus;

typedef struct {
    header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint32 tlli; /* TLLI*/
    kal_uint8 ctrlack; /* CTRL-ACK*/
} pkt_ctrl_ack_struct;

typedef struct {
    header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint32 tlli; /* TLLI*/
} pkt_uplink_dummy;

typedef struct {
    kal_uint16 access_ctrl_class; /* ACC CONTROL CLASS*/
    kal_uint8 max_retrans[4];
    kal_uint8 s; /* S */
    kal_uint8 tx_int; /* TX INT*/
    ispresent persist_level_choice_tag;
    union {
        persist_level_struct p_persist_level;
    } persist_level_choice_value;
} prach_ctrl_params_struct;

typedef struct {
    header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    prach_ctrl_params_struct prach_ctrl_params; /* PRACHCONTPARASTRUCT*/
} pkt_prach_params_struct;

typedef struct {
    header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    kal_uint8 msg_escape; /* ESCAPE SEQ*/
    global_tfistruct global_tfi; /* GLOBAL TFI STRUCT*/
    kal_uint8 up_link_release; /* UP LINK RELEASE*/
    kal_uint8 dn_link_release; /* DN LINK RELEASE*/
    kal_uint8 tbf_release_cause; /* TBF RELEASE*/
} pkt_tbfrelease_struct;

typedef struct {
    kal_uint8 multi_slot; /* MULTI SLOT CLASS*/
    kal_uint8 gprs_mul_slot_class; /* GPRS MULTI SLOT CLASS*/
    kal_uint8 ext_dyna_capability; /* EXTENDED DYNAMIC CAPABILITY*/
} gprsmulslot1struct;

typedef struct {
    kal_uint8 mul_slot; /* MULTI SLOT CLASS*/
    kal_uint8 ext_dyn_capability; /* EXTENDED DYNAMIC CAPABILITY*/
} gprsmulslot_struct;

typedef struct {
    freq_enum multi_slot_choice_tag;
    union {
        gprsmulslot_struct gprs_mul_slot;
        kal_uint8 mul_slot_class;
        gprsmulslot1struct gprs_mul_slot1;
    } multi_slot_choice_value;
} multi_cap_struct;

#ifndef _MS_MEAS_CAP_STRUCT
#define _MS_MEAS_CAP_STRUCT
typedef struct {
    kal_uint8 sms_value; /* SMS VALUE*/
    kal_uint8 sm_value; /* SM VALUE*/
} ms_meas_cap_struct;
#endif

typedef struct {
    kal_uint8 p_type_len;
    kal_uint8 p_pseudosynch; /* PSEUDO SYCHRONISATION*/
    kal_uint8 p_cipher_algo5;
    kal_uint8 p_voice_grp_call_serv; /* VOICE GROUP CALL SERVICE*/
    kal_uint8 p_voice_broad_cast_serv; /* VOICE BROADCAST SERVICE*/
    kal_uint8 p_pwr_capability; /* POWER CAPABILITY*/
    ms_meas_cap_struct p_ms_meas_capability; /* MS MEASUREMENT CAPABILITY*/
    kal_uint8 p_rev_level; /* GSM REVISION LEVEL*/
    kal_uint8 p_es_ind; /* ES IND*/
    multi_cap_struct p_multi_capability; /* MULTI SLOT CAPABILITY*/
} paccess_tech_struct;

typedef struct {
    kal_uint8 e_type_len;
    kal_uint8 e_pseudo_synch; /* PSEUDO SYCHRONISATION*/
    kal_uint8 e_cipher_algo5;
    kal_uint8 e_voice_grp_call_serv; /* VOICE GROUP CALL SERVICE*/
    kal_uint8 e_voice_broad_cast_serv; /* VOICE BROADCAST SERVICE*/
    kal_uint8 e_pwr_capability; /* POWER CAPABILITY*/
    ms_meas_cap_struct e_ms_meascapability; /* MS MEASUREMENT CAPABILITY*/
    kal_uint8 e_rev_level; /* GSM REVISION LEVEL*/
    kal_uint8 e_es_ind; /* ES IND*/
    multi_cap_struct e_multi_capability; /* MULTI SLOT CAPABILITY*/
} eaccess_tech_struct;

typedef struct {
    kal_uint8 r_type_len;
    kal_uint8 r_pseudo_synch; /* PSEUDO SYCHRONISATION*/
    kal_uint8 r_cipher_algo5;
    kal_uint8 r_voice_grp_call_serv; /* VOICE GROUP CALL SERVICE*/
    kal_uint8 r_voice_broad_cast_serv; /* VOICE BROADCAST SERVICE*/
    kal_uint8 r_pwr_capability; /* POWER CAPABILITY*/
    ms_meas_cap_struct r_ms_meascapability; /* MS MEASUREMENT CAPABILITY*/
    kal_uint8 r_rev_level; /* GSM REVISION LEVEL*/
    kal_uint8 r_es_ind; /* ES IND*/
    multi_cap_struct r_multi_capability; /* MULTI SLOT CAPABILITY*/
} raccess_tech_struct;

typedef struct {
    kal_uint8 a_type_len;
    kal_uint8 a_pseudo_synch; /* PSEUDO SYCHRONISATION*/
    kal_uint8 a_cipher_algo5;
    kal_uint8 a_voice_grp_call_serv; /* VOICE GROUP CALL SERVICE*/
    kal_uint8 a_voice_broad_cast_serv; /* VOICE BROADCAST SERVICE*/
    kal_uint8 a_pwr_capability; /* POWER CAPABILITY*/
    ms_meas_cap_struct a_ms_meas_cap_struct; /* MS MEASUREMENT CAPABILITY*/
    kal_uint8 a_ms_meascapability; /* GSM REVISION LEVEL*/
    kal_uint8 a_rev_level; /* REVISION LEVEL*/
    kal_uint8 a_es_ind; /* ES IND*/
    multi_cap_struct a_multi_capability; /* MULTI SLOT CAPABILITY*/
} aaccess_tech_struct;

typedef struct {
    ispresent p_access_choice_tag;
    union {
        paccess_tech_struct p_paccess;
    } p_access_choice_value;
    ispresent e_access_choice_tag;
    union {
        eaccess_tech_struct p_eaccess;
    } e_access_choice_value;
    ispresent r_access_choice_tag;
    union {
        raccess_tech_struct p_raccess;
    } r_access_choice_value;
    ispresent a_access_short_tag;
    union {
        aaccess_tech_struct p_aaccess;
    } a_access_short_value;
} ms_racapability_struct;

typedef struct {
    kal_uint8 access_cap_iei; /* MS RADIO CAPABILITY IEI*/
    kal_uint8 length;
    ms_racapability_struct ms_racapability;
} ms_radio_cap_struct;

typedef struct {
    header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    ispresent access_type_choice_tag;
    union {
        kal_uint8 p_bacctype;
    } access_type_choice_value;
    ispresent tlli_tfi_choice_tag;
    union {
        global_tfistruct global_tfi;
        kal_uint32 tlli;
    } tlli_tfi_choice_value;
    ispresent ms_radio_cap_choice_tag;
    union {
        ms_radio_cap_struct p_msradio_cap;
    } ms_radio_cap_choice_value;
    ch_request_desc_struct channel_req; /* CHANNEL REQUEST DESCRIPTION */
    ispresent chng_mark_choice_tag;
    union {
        kal_uint8 p_chng_mark;
    } chng_mark_choice_value;
    kal_uint8 cvalue; /* C VALUE*/
    ispresent sigvar_choice_tag;
    union {
        kal_uint8 p_signvar;
    } sigvar_choice_value;
    ilevel_tn_struct i_level_tn_values[8];
} pkt_resource_request_struct;

typedef struct {
    kal_uint8 nc_non_drx_period;
    kal_uint8 nc_rep_perioid_i;
    kal_uint8 nc_rep_period_t;
} nc_list_struct;

typedef struct {
    ispresent rmvd_freq_choice_tag;
    union {
        rmvd_freq_list_struct p_rmvd_freq_list;
    } rmvd_freq_choice_value;
    unsigned int no_add_freq_list;
    unsigned int add_freq_list_size;
    add_freq_struct *add_freq_list;
} nc_freq_list_struct;

typedef struct {
    kal_uint8 nw_ctrl_order; /* NETWORK CONTROL ORDER*/
    ispresent nc_list_choice_tag;
    union {
        nc_list_struct p_nc_list;
    } nc_list_choice_value;
    ispresent nc_freq_list_choice_tag;
    union {
        nc_freq_list_struct p_nc_freq_list;
    } nc_freq_list_choice_value;
} nc_meas_params_struct;

typedef struct {
    ispresent ch227_tag;
    union {
        kal_uint8 pintfreqlist;
    } ch227_value;
} int_freq_list_struct;

typedef struct {
    twobit ch226_tag;
    union {
        kal_uint8 ncc_permit;
        int_freq_list_struct intfreq;
    } ch226_value;
} ncc_or_freq_struct;

typedef struct {
    ispresent ext_rep_type_choice_tag;
    union {
        ncc_or_freq_struct pext_rep_type;
    } ext_rep_type_choice_value;
    ispresent ext_rep_per_choice_tag;
    union {
        kal_uint8 pext_rep_period;
    } ext_rep_per_choice_value;
    ext_freq_list_struct first_ext_freq_list; /* FIRST EXT FREQ LIST STRUCT*/
    unsigned int no_ext_freq_list;
    unsigned int ext_freq_list_size;
    ext_freq_list_struct *ext_freq_list;
} em1struct;

typedef struct {
    twobit ext_meas_order_tag;
    union {
        em1struct EM1;
    } ext_meas_order_value;
} ext_meas_params_struct;

typedef struct {
    kal_uint8 pmo_index; /* PMO INDEX*/
    kal_uint8 pmo_count; /* PMO COUNT*/
    ispresent nc_meas_choice_tag;
    union {
        nc_meas_params_struct p_nc_meas_params;
    } nc_meas_choice_value;
    ispresent ext_meas_choice_tag;
    union {
        ext_meas_params_struct p_extmeas_params;
    } ext_meas_choice_value;
} measurement_peer_struct;

typedef struct {
    header_struct header; /* HEADER*/
    kal_uint8 msg_type; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    msid_enum tlli_tfi_choice_tag;
    union {
        global_tfistruct global_tfi;
        kal_uint32 tlli;
    } tlli_tfi_choice_value;
    measurement_peer_struct measurement_params; /* MEASUREMENT STRUCT*/
} pkt_measurement_order_struct;

typedef struct {
    header_struct header; /* HEADER*/
    kal_uint8 msg_type; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    msid_enum tlli_tfi_choice_tag;
    union {
        global_tfistruct global_tfi;
        kal_uint32 tlli;
    } tlli_tfi_choice_value;
    kal_uint8 msgescape; /* MESSAGE ESCAPE*/
    kal_uint8 immediaterel; /* IMMEDIATE REL*/
    kal_uint16 arfcn; /* ARFCN*/
    kal_uint8 bsic; /* BSIC*/
    nc_meas_params_struct nc_meas_params; /* NC MEASUREMENT PARAMETER STRUCTURE*/
} pkt_cell_change_order;

typedef struct {
    kal_uint8 no_mobile;
    kal_uint8 mobile_size;
    kal_uint8 *mobile; /* mobile identity*/
} mobile_idstruct;

typedef struct {
    ispresent ptmsi_choice_tag;
    union {
        kal_uint32 a_ch_ptmsi;
        mobile_idstruct p_ch_ptmsi;
    } ptmsi_choice_value;
} ptmsistruct;

typedef struct {
    ispresent tmsi_choice_tag;
    union {
        kal_uint32 a_ch_tmsi;
        mobile_idstruct p_ch_tmsi;
    } tmsi_choice_value;
    kal_uint8 channel_needed; /* CHANNEL_NEEDED*/
    ispresent e_mlpp_choice_tag;
    union {
        kal_uint8 p_emlpp_priority;
    } e_mlpp_choice_value;
} tmsistruct;

typedef struct {
    ispresent tmsi_ptmsi_choice_tag;
    union {
        ptmsistruct a_ptmsi;
        tmsistruct p_tmsi;
    } tmsi_ptmsi_choice_value;
} repeated_page_info_struct;

typedef struct {
    header_struct header; /* HEADER*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 page_mode; /* PAGE MODE*/
    ispresent persis_level_choice_tag;
    union {
        persist_level_struct p_persistance_level;
    } persis_level_choice_value;
    ispresent notif_list_num_choice_tag;
    union {
        kal_uint8 p_notif_list_num;
    } notif_list_num_choice_value;
    unsigned int no_repeated_page_info;
    unsigned int repeated_page_info_size;
    repeated_page_info_struct *repeated_page_info;
} packet_paging_request;

typedef struct {
    kal_uint8 pdu_length_indicator;
    kal_uint8 pdu_descript_spare;
    kal_uint16 no_of_pdus;
} pdu_descript_struct;

typedef struct {
    kal_uint8 mode_flag_spare;
    kal_uint8 dl_timeslot_offset;
    kal_uint8 mode;
} mode_flag_struct;

typedef struct {
    kal_uint8 skip_ind;
    kal_uint8 proto_disc;
    kal_uint8 msg_type;
    pdu_descript_struct pdu_descript;
    mode_flag_struct mode_flag; /* Mode Flag Struct*/
} gprs_test_mode_cmd_struct;
#endif 


