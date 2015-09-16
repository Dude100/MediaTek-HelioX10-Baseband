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
 *  rmc_peer_struct.h
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *  FILENAME : rmc_peer_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _RMC_PEER_STRUCT_H
#define _RMC_PEER_STRUCT_H

#include "rmc_peer_dl.h"
#include "rmc_peer_dl_struct.h"
#include "rr_spare_bit.h"
#include "nstd_spare_bit_struct.h"
#include "l3_inc_enums.h"
#include "nstd_channel_rel_struct.h"
#include "rmc_peer.h"
#include "mcd_l3_inc_struct.h"
#ifdef __PS_SERVICE__
#include "gprs_rlcmac_peer_struct.h"
#endif /* __PS_SERVICE__ */

#ifndef _MS_MEAS_CAP_STRUCT
#define _MS_MEAS_CAP_STRUCT
typedef struct {
    kal_uint8 sms_value; /* SMS VALUE*/
    kal_uint8 sm_value; /* SM VALUE*/
} ms_meas_cap_struct;
#endif

typedef struct {
    kal_uint8 spare;
    kal_uint16 arfcn;
} spare_and_arfcn_struct;

typedef struct {
    kal_uint8 maio;
    kal_uint8 hsn;
} maio_and_hsn_struct;

typedef struct {
    kal_uint8 chan_type_tdmaoffset;
    kal_uint8 tn;
    kal_uint8 tsc;
    enum_is_present maio_tag;
    union {
        spare_and_arfcn_struct spare_and_arfcn;
        maio_and_hsn_struct maio_and_hsn;
    } maio_value;
} chan_desc_struct;

typedef struct {
    kal_uint8 spare;
    kal_uint8 maio;
    kal_uint8 ma_num;
    enum_is_present ch1_tag;
    union {
        kal_uint8 spare;
        kal_uint8 chngmark1;
    } ch1_value;
} rmc_maio_struct;

typedef struct {
    kal_uint8 spare;
    kal_uint16 arfcn;
} arfcn_struct;

typedef struct {
    enum_is_present ch1_tag;
    union {
        arfcn_struct arfcn;
        rmc_maio_struct maio;
    } ch1_value;
} non_hop_or_indirect_enc_struct;

typedef struct {
    kal_uint8 maio;
    kal_uint8 hsn;
} direct_enc_struct;

typedef struct {
    kal_uint8 chan_type; /* shall be ignored by the receiver.
                                       always set to the value 00001.*/
    kal_uint8 tn; /* time slot number*/
    kal_uint8 tsc; /* training sequence code*/
    chan_config ch_config_tag;
    union {
        non_hop_or_indirect_enc_struct non_hop_or_indirect_enc;
        direct_enc_struct direct_enc;
    } ch_config_value;
} pkt_chan_desc_struct;

typedef struct {
    kal_uint8 value; /* valid values for all bands other than
                                   GSM 400 are 0-63. for GSM 400, the valid
                                   values are 0-219.*/
} m_timing_advance_struct;

typedef struct {
    kal_uint8 random_acc_info; /* random access info. to be coded in the
                                    same way as the channel request message.*/
    kal_uint8 t1;
    kal_uint8 t3;
    kal_uint8 t2;
} rmc_request_reference_struct;

typedef struct {
    kal_uint8 no_mobile_alloc;
    kal_uint8 mobile_alloc_size;
    kal_uint8 *mobile_alloc;
} rmc_mobile_alloc_struct;

typedef struct {
    kal_uint8 mesg_type;
} mesg_type_struct;

typedef struct {
    kal_uint8 spare;
    kal_uint8 page_mode; /* indicates whether the paging mode
                                       is normal paging, extended paging,
                                       paging reorganization or same as
                                       before.*/
} rr_rmc_page_mode_struct;

typedef struct {
    kal_uint8 spare;
    kal_uint8 two_mesg_asgn_ind;
    kal_uint8 down_link;
    kal_uint8 tbf_or_dedicated_mode_ind;
} dedicated_mode_or_tbf_struct;

typedef struct {
    kal_uint8 proto_disc;
} rmc_rr_protocol_disc_struct;

typedef struct {
    kal_uint8 skip_ind;
} rmc_rr_skip_indicator_struct;

typedef struct {
    kal_uint8 length;
    kal_uint8 fixed_valuefield;
} rmc_l2_pseudo_length_struct;

typedef struct {
    rmc_l2_pseudo_length_struct l2pseudo_length;
    rmc_rr_skip_indicator_struct skip;
    rmc_rr_protocol_disc_struct proto_disc;
    mesg_type_struct mesg_type;
    dedicated_mode_or_tbf_struct ded_or_tbf;
    rr_rmc_page_mode_struct page_mode;
    pkt_chan_desc_struct pkt_chan_desc;
    rmc_request_reference_struct req_ref;
    m_timing_advance_struct time_adv;
    rmc_mobile_alloc_struct mob_alloc;
#ifdef __PS_SERVICE__    
    iarest_octets rest_oct;
#endif
} immediate_assign_message;

typedef struct {
    kal_uint8 spare;
} rmc_spare_half_octet_struct;

typedef struct {
    kal_uint8 time_out_value; /* T3122 or T3142 timeout value*/
} rmc_wait_indication_struct;

typedef struct {
    kal_uint32 spare; /* set to 0x0 always*/
} iarrest_octets;

typedef struct {
    rmc_l2_pseudo_length_struct length;
    rmc_rr_skip_indicator_struct skip_ind;
    rmc_rr_protocol_disc_struct protocol_disc;
    mesg_type_struct mesg_type;
    rmc_spare_half_octet_struct spare;
    rr_rmc_page_mode_struct page_mode;
    rmc_request_reference_struct req_ref1;
    rmc_wait_indication_struct wait_ind1;
    rmc_request_reference_struct req_ref2;
    rmc_wait_indication_struct wait_ind2;
    rmc_request_reference_struct req_ref3;
    rmc_wait_indication_struct wait_ind3;
    rmc_request_reference_struct req_ref4;
    rmc_wait_indication_struct wait_ind4;
    iarrest_octets rest_octets;
} imm_asgn_rej_msg_struct;

typedef struct {
    rmc_l2_pseudo_length_struct l2pseudo_length;
    rmc_rr_skip_indicator_struct skip;
    rmc_rr_protocol_disc_struct proto_disc;
    mesg_type_struct mesg_type;
    dedicated_mode_or_tbf_struct ded_or_tbf;
    rr_rmc_page_mode_struct page_mode;
    chan_desc_struct chan_desc; /* always ded description*/
    rmc_request_reference_struct req_ref;
    m_timing_advance_struct time_adv;
    rmc_mobile_alloc_struct mob_alloc;
#ifdef __PS_SERVICE__    
    iarest_octets rest_oct;
#endif
} immediate_assign_dedicated;

typedef struct {
    rmc_l2_pseudo_length_struct l2pseudo_length;
    rmc_rr_skip_indicator_struct skip;
    rmc_rr_protocol_disc_struct proto_disc;
    mesg_type_struct mesg_type;
    rmc_spare_half_octet_struct spare;
    rr_rmc_page_mode_struct page_mode;
    chan_desc_struct chan_desc1; /* channel description */
    rmc_request_reference_struct req_ref1;
    m_timing_advance_struct time_adv1;
    chan_desc_struct chan_desc2; /* channel description */
    rmc_request_reference_struct req_ref2;
    m_timing_advance_struct time_adv2;
    rmc_mobile_alloc_struct mob_alloc;
    kal_uint8 no_iax_rest_oct;
    kal_uint8 iax_rest_oct_size;
    kal_uint8 *iax_rest_oct; /* spare*/
} immediate_assign_ext_message;

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

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    kal_uint8 rr_cause;
} rr_status_struct;

typedef struct {
    kal_uint8 format_id;
    kal_uint8 spare;
    kal_uint8 ca_arfcn_1;
    kal_uint8 ca_arfcn_2[15];
} cell_channel_description_struct;

typedef struct {
    kal_uint8 bcch_arfcn_high; /* high part*/
    kal_uint8 ncc;
    kal_uint8 bcc;
    kal_uint8 bcch_arfcn_low; /* low part*/
} cell_description_struct;

typedef struct {
    kal_uint8 spare;
    kal_uint8 nc_mode;
} nc_mode_struct;

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    cell_description_struct cell_description;
    kal_uint8 spare_half_octet;
    nc_mode_struct nc_mode;
} rr_cell_change_order_struct;

typedef struct {
    kal_uint8 format_id;
    kal_uint8 spare;
    kal_uint8 seq_code;
    kal_uint8 ca_arfcn_1;
    kal_uint8 ca_arfcn_2[15];
} extended_measurement_freq_list_struct;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    extended_measurement_freq_list_struct ext_freq_list;
} extended_measurement_order_struct;

typedef struct {
    kal_uint8 ch_typeand_tdma;
    kal_uint8 tn;
    kal_uint8 training_seq; /* training sequence code*/
    is_present_enum hopping_ch_tag;
    union {
        field1_struct channel_select1;
        field2_struct channel_select2;
    } hopping_ch_value;
} channel_description_struct;

typedef struct {
    kal_uint8 no_ca_arfcn;
    kal_uint8 ca_arfcn_size;
    kal_uint8 *ca_arfcn;
} frequency_list_struct;

typedef struct {
    kal_uint8 no_ca_arfcn;
    kal_uint8 ca_arfcn_size;
    kal_uint8 *ca_arfcn;
} frequency_short_list_struct;

typedef struct {
    kal_uint8 spare;
    kal_uint8 lowest_arfcn;
    kal_uint8 inc_skip_arfcn[16];
} frequency_channel_sequence_struct;

typedef struct {
    kal_uint8 atc;
    kal_uint8 spare;
    kal_uint8 fpc;
    kal_uint8 power_level;
} power_command_struct;

typedef struct {
    kal_uint8 algo_identifier;
    kal_uint8 sc;
} cipher_mode_setting_struct;

typedef struct {
    kal_uint8 length;
    kal_uint8 target_mode;
    kal_uint8 group_cipher_key_no;
    kal_uint8 spare1;
    kal_uint8 spare2;
} vgcs_target_mode_indication_struct;

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    channel_description_struct channel_desc1;
    power_command_struct power_command;
    kal_uint8 freq_list1P;
    frequency_list_struct freq_list1;
    kal_uint8 cell_channel_descP;
    cell_channel_description_struct cell_channel_desc;
    kal_uint8 multi_slot_allocP;
    kal_uint8 no_multi_slot_alloc;
    kal_uint8 multi_slot_alloc_size;
    kal_uint8 *multi_slot_alloc;
    kal_uint8 channel_mode1P;
    kal_uint8 channel_mode1;
    kal_uint8 channel_mode2P;
    kal_uint8 channel_mode2;
    kal_uint8 channel_mode3P;
    kal_uint8 channel_mode3;
    kal_uint8 channel_mode4P;
    kal_uint8 channel_mode4;
    kal_uint8 channel_mode5P;
    kal_uint8 channel_mode5;
    kal_uint8 channel_mode6P;
    kal_uint8 channel_mode6;
    kal_uint8 channel_mode7P;
    kal_uint8 channel_mode7;
    kal_uint8 channel_mode8P;
    kal_uint8 channel_mode8;
    kal_uint8 channel_desc2P;
    channel_description_struct channel_desc2;
    kal_uint8 channel_mode9P;
    kal_uint8 channel_mode9;
    kal_uint8 mobile_alloc1P;
    kal_uint8 no_mobile_alloc1;
    kal_uint8 mobile_alloc1_size;
    kal_uint8 *mobile_alloc1;
    kal_uint8 starting_timeP;
    rmc_start_time_struct starting_time;
    kal_uint8 freq_list2P;
    frequency_list_struct freq_list2;
    kal_uint8 channel_desc3P;
    channel_description_struct channel_desc3;
    kal_uint8 channel_desc4P;
    channel_description_struct channel_desc4;
    kal_uint8 freq_channel_seqP;
    frequency_channel_sequence_struct freq_channel_seq;
    kal_uint8 mobile_alloc2P;
    kal_uint8 no_mobile_alloc2;
    kal_uint8 mobile_alloc2_size;
    kal_uint8 *mobile_alloc2;
    kal_uint8 cipher_modeP;
    cipher_mode_setting_struct cipher_mode;
    kal_uint8 vgcs_target_modeP;
    vgcs_target_mode_indication_struct vgcs_target_mode;
    kal_uint8 multi_rate_configP;
    kal_uint8 no_multi_rate_config;
    kal_uint8 multi_rate_config_size;
    /* kal_uint8 *multi_rate_config; */
	kal_uint8 multirate_speech_version;
	kal_uint8 nscb;
	kal_uint8 icmi;
	kal_uint8 start_mode;
	kal_uint8 active_codec_set;
	kal_uint8 threshold[3];
	kal_uint8 hysteresis[3];
} assignment_command_struct;

#ifdef __PS_SERVICE__
typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    channel_description_struct channel_desc1;
    kal_uint8 cell_channel_descP;
    cell_channel_description_struct cell_channel_desc;
    kal_uint8 freq_list1P;
    frequency_list_struct freq_list1;
    kal_uint8 mobile_alloc1P;
    kal_uint8 no_mobile_alloc1;
    kal_uint8 mobile_alloc1_size;
    kal_uint8 *mobile_alloc1;
    kal_uint8 starting_timeP;
    rmc_start_time_struct starting_time;
    kal_uint8 freq_list2P;
    frequency_list_struct freq_list2;
    kal_uint8 channel_desc2P;
    channel_description_struct channel_desc2;
    kal_uint8 freq_channel_seqP;
    frequency_channel_sequence_struct freq_channel_seq;
    kal_uint8 mobile_alloc2P;
    kal_uint8 no_mobile_alloc2;
    kal_uint8 mobile_alloc2_size;
    kal_uint8 *mobile_alloc2;
    kal_uint8 rr_packet_uplinkP;
    rr_packet_uplink_struct rr_packet_uplink;
    kal_uint8 rr_packet_downlinkP;
    rr_packet_downlink_struct rr_packet_downlink;
} pdch_assignment_command_struct;
#endif

typedef struct {
    kal_uint8 length; /* length of contents*/
    kal_uint8 spare_0; /* spare*/
    kal_uint8 rev_level; /* revision level*/
    kal_uint8 es_ind; /* ES IND*/
    kal_uint8 a5_1; /* A5/1 supported*/
    kal_uint8 rf_cap; /* Rf Power Capability*/
    kal_uint8 spare_1; /* spare*/
    kal_uint8 ps_cap; /* PS capability*/
    kal_uint8 ss_screen_ind; /* SS screen Indicator*/
    kal_uint8 sm_cap; /* SM capability*/
    kal_uint8 vbs; /* VBS*/
    kal_uint8 vgcs; /* VGCS*/
    kal_uint8 fc; /* FC*/
    kal_uint8 cm3; /* CM3*/
    kal_uint8 spare_2; /* spare*/
    kal_uint8 lcsva_cap; /* LCSVA capability*/
    kal_uint8 ucs2; /* UCS2*/
    kal_uint8 so_lsa; /* SoLSA*/
    kal_uint8 cmsp; /* CMSP*/
    kal_uint8 a5_3; /* A5/3*/
    kal_uint8 a5_2; /* A5/2*/
} classmark2_struct;

typedef struct {
    kal_uint8 a5_7; /* A5/7*/
    kal_uint8 a5_6; /* A5/6*/
    kal_uint8 a5_5; /* A5/5*/
    kal_uint8 a5_4; /* A5/4*/
} a5_bits_struct;

typedef struct {
    a5_bits_struct a5bits;
    kal_uint8 arc2; /* assoc radio cap 2*/
    kal_uint8 arc1; /* assoc radio cap 1*/
} a5_bits_1_struct;

typedef struct {
    a5_bits_struct a5bits;
    kal_uint8 spare; /* spare*/
    kal_uint8 arc1; /* assoc radio cap 1*/
} a5_bits_2_struct;

typedef struct {
    kal_uint8 mod_cap; /* modulation capability*/
    enum_is_present ch_rf_pwr_cap1_tag;
    union {
        kal_uint8 e_rf_pwr_cap1;
    } ch_rf_pwr_cap1_value;
    enum_is_present ch_rf_pwr_cap2_tag;
    union {
        kal_uint8 e_rf_pwr_cap2;
    } ch_rf_pwr_cap2_value;
} edge_struct;

typedef struct {
    kal_uint8 gsm_bnd_sup; /* GSM 400 bands supported*/
    kal_uint8 gsm_arc1; /* GSM 400 associated radio capability*/
} gsm_band_inf_struct;

typedef struct {
    kal_uint8 d_gmssc; /* DTM GPRS multi slot sub-class*/
    kal_uint8 mac_md_sup; /* MAC mode support*/
} gprs_mlt_slt_struct;

typedef struct {
    kal_uint8 length; /* length of classmark contents*/
    kal_uint8 spare; /* spare*/
    multi_band_enum ch1_tag;
    union {
        a5_bits_struct a5bits;
        a5_bits_1_struct a5bits_1;
        a5_bits_1_struct a5bits_1_1;
        a5_bits_2_struct a5bits_2;
        a5_bits_2_struct a5bits_2_1;
        a5_bits_2_struct a5bits_2_2;
    } ch1_value;
    enum_is_present ch2_tag;
    union {
        kal_uint8 r_support;
    } ch2_value;
    enum_is_present ch3_tag;
    union {
        kal_uint8 m_slot_cap;
    } ch3_value;
    kal_uint8 ucs2; /* UCS2 treatment*/
    kal_uint8 ext_meas_cap; /* extended meas capability*/
    enum_is_present ch4_tag;
    union {
        ms_meas_cap_struct meas_cap;
    } ch4_value;
    enum_is_present ch5_tag;
    union {
        kal_uint8 ms_pos_cap;
    } ch5_value;
    enum_is_present ch6_tag;
    union {
        kal_uint8 edgem_slot_cap;
    } ch6_value;
    enum_is_present ch7_tag;
    union {
        edge_struct edge_struct_inst;
    } ch7_value;
    enum_is_present ch8_tag;
    union {
        gsm_band_inf_struct gsm_bnd_inf;
    } ch8_value;
    enum_is_present ch9_tag;
    union {
        kal_uint8 gsm_arc2;
    } ch9_value;
    enum_is_present ch10_tag;
    union {
        kal_uint8 pcs_arc;
    } ch10_value;
    kal_uint8 umts_fratc; /* UMTS FDD radio access tech. cap.*/
    kal_uint8 umts_tratc; /* UMTS TDD radio access tech. cap.*/
    kal_uint8 cdma_ratc; /* CDMA 2000 radio access tech. cap.*/
    enum_is_present ch11_tag;
    union {
        gprs_mlt_slt_struct gprs_mslot;
    } ch11_value;
    enum_is_present ch12_tag;
    union {
        kal_uint8 egprs_mslot;
    } ch12_value;
    kal_uint8 spare1; /* spare*/
} classmark3_struct;

typedef struct {
    kal_uint8 classmark_length;
    kal_uint8 classmark_mask;
} classmark_enq_mask;

typedef struct {
    rmc_rr_skip_indicator_struct skip_ind;
    rmc_rr_protocol_disc_struct proto_disc;
    mesg_type_struct mesg_type;
    kal_uint8 classmark_enq_mask_instP;
    classmark_enq_mask classmark_enq_mask_inst;
} rr_peer_classmark_enquiry_struct;

typedef struct {
    rmc_rr_skip_indicator_struct skip_ind;
    rmc_rr_protocol_disc_struct proto_disc;
    mesg_type_struct mesg_type;
} rr_peer_partial_release_complete_struct;

typedef struct {
    rmc_rr_skip_indicator_struct skip_ind;
    rmc_rr_protocol_disc_struct proto_disc;
    mesg_type_struct mesg_type;
    chan_desc_struct chan_desc;
    kal_uint8 mobile_allocP;
    rmc_mobile_alloc_struct mobile_alloc; /* mobile allocation*/
    kal_uint8 start_timeP;
    rmc_start_time_struct start_time; /* starting time*/
} rr_peer_additional_assignment_struct;

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
    rmc_rr_skip_indicator_struct skip_ind;
    rmc_rr_protocol_disc_struct proto_disc;
    mesg_type_struct mesg_type;
    kal_uint8 rr_cause; /* RR cause*/
} rr_peer_rr_status_struct;

typedef struct {
    rmc_rr_skip_indicator_struct skip_ind;
    rmc_rr_protocol_disc_struct proto_disc;
    mesg_type_struct mesg_type;
    chan_desc_struct chan_desc; /* chan desc*/
} rr_peer_partial_release_struct;

typedef struct {
    kal_uint8 tn_slot;
    kal_uint8 mech;
    kal_uint8 chc;
} loop_type_struct;

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    kal_uint8 sub_channel;
} close_tch_loop_cmd_struct;

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    kal_uint8 ackP;
    kal_uint8 ack;
} open_loop_cmd_struct;

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    loop_type_struct loop_type;
} close_multi_loop_cmd_struct;

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
} open_multi_loop_cmd_struct;

typedef struct {
    kal_uint8 spare;
    kal_uint8 chc;
    kal_uint8 loop_mechanism;
    kal_uint8 error_ind;
} close_multi_loop_ack_result_struct;

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    close_multi_loop_ack_result_struct result;
} close_multi_loop_ack;

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    kal_uint8 cipherresponse;
    cipher_mode_setting_struct ciphermode;
} cipher_mode_command_struct;

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    kal_uint8 imeisvP;
    imeisv_struct imeisv;
} cipher_mode_complete_struct;

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    kal_uint8 no_multi_slot_alloc;
    kal_uint8 multi_slot_alloc_size;
    kal_uint8 *multi_slot_alloc;
    kal_uint8 channel_mode1P;
    kal_uint8 channel_mode1;
    kal_uint8 channel_mode2P;
    kal_uint8 channel_mode2;
    kal_uint8 channel_mode3P;
    kal_uint8 channel_mode3;
    kal_uint8 channel_mode4P;
    kal_uint8 channel_mode4;
    kal_uint8 channel_mode5P;
    kal_uint8 channel_mode5;
    kal_uint8 channel_mode6P;
    kal_uint8 channel_mode6;
    kal_uint8 channel_mode7P;
    kal_uint8 channel_mode7;
    kal_uint8 channel_mode8P;
    kal_uint8 channel_mode8;
} configuration_change_command_struct;

typedef struct {
    kal_uint8 nci;
    kal_uint8 rot;
    kal_uint8 si;
} sync_info_struct;

typedef struct {
    kal_uint8 length;
    kal_uint8 value;
} real_time_diff_struct;

typedef struct {
    kal_uint8 length;
    kal_uint32 value;
    kal_uint8 spare;
} mob_obs_time_diff_struct;

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    cell_description_struct cell_description;
    channel_description_struct channel_desc1;
    kal_uint8 handover_ref;
    power_command_struct power_command;
    kal_uint8 sync_indP;
    sync_info_struct sync_ind;
    kal_uint8 freq_short_list1P;
    frequency_short_list_struct freq_short_list1;
    kal_uint8 freq_list1P;
    frequency_list_struct freq_list1;
    kal_uint8 cell_channel_descP;
    cell_channel_description_struct cell_channel_desc;
    kal_uint8 multi_slot_allocP;
    kal_uint8 no_multi_slot_alloc;
    kal_uint8 multi_slot_alloc_size;
    kal_uint8 *multi_slot_alloc;
    kal_uint8 channel_mode1P;
    kal_uint8 channel_mode1;
    kal_uint8 channel_mode2P;
    kal_uint8 channel_mode2;
    kal_uint8 channel_mode3P;
    kal_uint8 channel_mode3;
    kal_uint8 channel_mode4P;
    kal_uint8 channel_mode4;
    kal_uint8 channel_mode5P;
    kal_uint8 channel_mode5;
    kal_uint8 channel_mode6P;
    kal_uint8 channel_mode6;
    kal_uint8 channel_mode7P;
    kal_uint8 channel_mode7;
    kal_uint8 channel_mode8P;
    kal_uint8 channel_mode8;
    kal_uint8 channel_desc2P;
    channel_description_struct channel_desc2;
    kal_uint8 channel_mode9P;
    kal_uint8 channel_mode9;
    kal_uint8 freq_channel_seq_aftP;
    frequency_channel_sequence_struct freq_channel_seq_aft;
    kal_uint8 mobile_alloc1P;
    kal_uint8 no_mobile_alloc1;
    kal_uint8 mobile_alloc1_size;
    kal_uint8 *mobile_alloc1;
    kal_uint8 starting_timeP;
    rmc_start_time_struct starting_time;
    kal_uint8 rtdP;
    real_time_diff_struct rtd;
    kal_uint8 timing_advP;
    kal_uint8 timing_adv;
    kal_uint8 freq_short_list2P;
    frequency_short_list_struct freq_short_list2;
    kal_uint8 freq_list2P;
    frequency_list_struct freq_list2;
    kal_uint8 channel_desc3P;
    channel_description_struct channel_desc3;
    kal_uint8 channel_desc4P;
    channel_description_struct channel_desc4;
    kal_uint8 freq_channel_seq_bfrP;
    frequency_channel_sequence_struct freq_channel_seq_bfr;
    kal_uint8 mobile_alloc2P;
    kal_uint8 no_mobile_alloc2;
    kal_uint8 mobile_alloc2_size;
    kal_uint8 *mobile_alloc2;
    kal_uint8 cipher_modeP;
    cipher_mode_setting_struct cipher_mode;
    kal_uint8 vgcs_target_modeP;
    vgcs_target_mode_indication_struct vgcs_target_mode;
    kal_uint8 multi_rate_configP;
    kal_uint8 no_multi_rate_config;
    kal_uint8 multi_rate_config_size;
    /* kal_uint8 *multi_rate_config; */
	kal_uint8 multirate_speech_version;
	kal_uint8 nscb;
	kal_uint8 icmi;
	kal_uint8 start_mode;
	kal_uint8 active_codec_set;
	kal_uint8 threshold[3];
	kal_uint8 hysteresis[3];
} handover_command_struct;

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    kal_uint8 motdP;
    mob_obs_time_diff_struct motd;
} handover_complete_struct;

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    kal_uint8 timing_adv;
} physical_information_struct;

typedef struct {
    kal_uint8 no_apdu_alloc;
    kal_uint8 *apdu_alloc;
} apdu_data_struct;

typedef enum {
    RRLP = 0,
    ETWS = 1
} enum_apdu_id;

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    kal_uint8 spare_bit;
	kal_uint8 first_seg;
	kal_uint8 last_seg;
	kal_uint8 cr_id;
	enum_apdu_id apdu_id;
	apdu_data_struct apdu_data;
} application_information_struct;

typedef struct {
    kal_uint8 random_acc_info; 
} channel_request_struct_1;
typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    channel_description_struct channel_desc;
    rmc_mobile_alloc_struct mob_alloc;
    rmc_start_time_struct starting_time;
    kal_uint8 cell_channel_descP;
    cell_channel_description_struct cell_channel_desc;
} frequency_redefinition_struct;

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    channel_description_struct channel_desc;
    kal_uint8 channel_mode;
    kal_uint8 vgcs_target_modeP;
    vgcs_target_mode_indication_struct vgcs_target_mode;
    kal_uint8 multi_rate_configP;
    kal_uint8 no_multi_rate_config;
    kal_uint8 multi_rate_config_size;
    /* kal_uint8 *multi_rate_config; */
	kal_uint8 multirate_speech_version;
	kal_uint8 nscb;
	kal_uint8 icmi;
	kal_uint8 start_mode;
	kal_uint8 active_codec_set;
	kal_uint8 threshold[3];
	kal_uint8 hysteresis[3];
} channel_mode_modify_struct;

typedef struct {
    kal_uint8 skip_indicator;
    kal_uint8 protocol_disc;
    kal_uint8 message_type;
    channel_description_struct channel_desc;
    kal_uint8 channel_mode;
} channel_mode_modify_ack_struct;
#endif 


