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
 *  gprs_rlcmac_dl_pun.h
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
 *  FILENAME : gprs_rlcmac_dl_pun.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifdef MTK_PEER 
#define IMP __declspec(dllimport) 
#else 
#define IMP 
#endif 
#ifndef _GPRS_RLCMAC_DL_PUN_H
#define _GPRS_RLCMAC_DL_PUN_H

/*Evelyn: Remove redundant header and file */
#include "kal_general_types.h"

#define persist_level_struct_size(x) 2
IMP unsigned int persist_level_struct_bits(void *);
IMP void persist_level_struct_alloc(void *);
IMP void persist_level_struct_dealloc(void *);
IMP unsigned int persist_level_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int persist_level_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int global_tfistruct_bits(void *);
IMP void global_tfistruct_alloc(void *);
IMP void global_tfistruct_dealloc(void *);
IMP unsigned int global_tfistruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int global_tfistruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define timing_adv_idx_tslot_struct_size(x) 1
IMP unsigned int timing_adv_idx_tslot_struct_bits(void *);
IMP void timing_adv_idx_tslot_struct_alloc(void *);
IMP void timing_adv_idx_tslot_struct_dealloc(void *);
IMP unsigned int timing_adv_idx_tslot_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int timing_adv_idx_tslot_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pkt_timing_advance_struct_bits(void *);
IMP void pkt_timing_advance_struct_alloc(void *);
IMP void pkt_timing_advance_struct_dealloc(void *);
IMP unsigned int pkt_timing_advance_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_timing_advance_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int chng_mark1struct_bits(void *);
IMP void chng_mark1struct_alloc(void *);
IMP void chng_mark1struct_dealloc(void *);
IMP unsigned int chng_mark1struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int chng_mark1struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int indirect_encode_struct_bits(void *);
IMP void indirect_encode_struct_alloc(void *);
IMP void indirect_encode_struct_dealloc(void *);
IMP unsigned int indirect_encode_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int indirect_encode_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int direct_encode1struct_bits(void *);
IMP void direct_encode1struct_alloc(void *);
IMP void direct_encode1struct_dealloc(void *);
IMP unsigned int direct_encode1struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int direct_encode1struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int freq_params_peer_struct_bits(void *);
IMP void freq_params_peer_struct_alloc(void *);
IMP void freq_params_peer_struct_dealloc(void *);
IMP unsigned int freq_params_peer_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int freq_params_peer_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int starting_frame_num_struct_bits(void *);
IMP void starting_frame_num_struct_alloc(void *);
IMP void starting_frame_num_struct_dealloc(void *);
IMP unsigned int starting_frame_num_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int starting_frame_num_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define pkt_req_ref_struct_size(x) 4
IMP unsigned int pkt_req_ref_struct_bits(void *);
IMP void pkt_req_ref_struct_alloc(void *);
IMP void pkt_req_ref_struct_dealloc(void *);
IMP unsigned int pkt_req_ref_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_req_ref_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int usf_struct_bits(void *);
IMP void usf_struct_alloc(void *);
IMP void usf_struct_dealloc(void *);
IMP unsigned int usf_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int usf_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int time_slot_alloc_struct_bits(void *);
IMP void time_slot_alloc_struct_alloc(void *);
IMP void time_slot_alloc_struct_dealloc(void *);
IMP unsigned int time_slot_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int time_slot_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define usf_gamma_struct_size(x) 1
IMP unsigned int usf_gamma_struct_bits(void *);
IMP void usf_gamma_struct_alloc(void *);
IMP void usf_gamma_struct_dealloc(void *);
IMP unsigned int usf_gamma_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int usf_gamma_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rr_usf_pwr_ctrl_struct_bits(void *);
IMP void rr_usf_pwr_ctrl_struct_alloc(void *);
IMP void rr_usf_pwr_ctrl_struct_dealloc(void *);
IMP unsigned int rr_usf_pwr_ctrl_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rr_usf_pwr_ctrl_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int time_slot_pwr_ctrl_alloc_struct_bits(void *);
IMP void time_slot_pwr_ctrl_alloc_struct_alloc(void *);
IMP void time_slot_pwr_ctrl_alloc_struct_dealloc(void *);
IMP unsigned int time_slot_pwr_ctrl_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int time_slot_pwr_ctrl_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define p0pr_mode_struct_size(x) 1
IMP unsigned int p0pr_mode_struct_bits(void *);
IMP void p0pr_mode_struct_alloc(void *);
IMP void p0pr_mode_struct_dealloc(void *);
IMP unsigned int p0pr_mode_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int p0pr_mode_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int dynamic_alloc_struct_bits(void *);
IMP void dynamic_alloc_struct_alloc(void *);
IMP void dynamic_alloc_struct_dealloc(void *);
IMP unsigned int dynamic_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int dynamic_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define alpha_gamma_struct_size(x) 2
IMP unsigned int alpha_gamma_struct_bits(void *);
IMP void alpha_gamma_struct_alloc(void *);
IMP void alpha_gamma_struct_dealloc(void *);
IMP unsigned int alpha_gamma_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int alpha_gamma_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define bts_mode_struct_size(x) 1
IMP unsigned int bts_mode_struct_bits(void *);
IMP void bts_mode_struct_alloc(void *);
IMP void bts_mode_struct_dealloc(void *);
IMP unsigned int bts_mode_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int bts_mode_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int single_blk_alloc_struct_bits(void *);
IMP void single_blk_alloc_struct_alloc(void *);
IMP void single_blk_alloc_struct_dealloc(void *);
IMP unsigned int single_blk_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int single_blk_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

/* Claire 041123 new : Add for decoding Multi Block Allocation struct in PUAS */
#ifdef __EGPRS_MODE__
IMP unsigned int multi_blk_alloc_struct_bits(void *);
IMP void multi_blk_alloc_struct_alloc(void *);
IMP void multi_blk_alloc_struct_dealloc(void *);
IMP unsigned int multi_blk_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int multi_blk_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);
#endif

IMP unsigned int gamma_tn_value_struct_bits(void *);
IMP void gamma_tn_value_struct_alloc(void *);
IMP void gamma_tn_value_struct_dealloc(void *);
IMP unsigned int gamma_tn_value_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gamma_tn_value_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pwr_ctrl_params_peer_struct_bits(void *);
IMP void pwr_ctrl_params_peer_struct_alloc(void *);
IMP void pwr_ctrl_params_peer_struct_dealloc(void *);
IMP unsigned int pwr_ctrl_params_peer_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pwr_ctrl_params_peer_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int fixed_alloc_struct_bits(void *);
IMP void fixed_alloc_struct_alloc(void *);
IMP void fixed_alloc_struct_dealloc(void *);
IMP unsigned int fixed_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int fixed_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int extend_timing_adv_struct_bits(void *);
IMP void extend_timing_adv_struct_alloc(void *);
IMP void extend_timing_adv_struct_dealloc(void *);
IMP unsigned int extend_timing_adv_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int extend_timing_adv_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);
/* Evelyn 20090415: Merge R6 */
#ifdef __MTBF__
IMP unsigned int rel_5_later_puas_struct_bits(void *);
IMP void rel_5_later_puas_struct_alloc(void *);
IMP void rel_5_later_puas_struct_dealloc(void *);
IMP unsigned int rel_5_later_puas_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rel_5_later_puas_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rel_6_puas_struct_bits(void *);
IMP void rel_6_puas_struct_alloc(void *);
IMP void rel_6_puas_struct_dealloc(void *);
IMP unsigned int rel_6_puas_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rel_6_puas_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);
#endif
IMP unsigned int gprsuplnk_assign_struct_bits(void *);
IMP void gprsuplnk_assign_struct_alloc(void *);
IMP void gprsuplnk_assign_struct_dealloc(void *);
IMP unsigned int gprsuplnk_assign_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gprsuplnk_assign_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#ifdef __EGPRS_MODE__
#define rmc_access_tech_req_elem_struct_size(x) 1
IMP unsigned int rmc_access_tech_req_elem_struct_bits(void *);
IMP void rmc_access_tech_req_elem_struct_alloc(void *);
IMP void rmc_access_tech_req_elem_struct_dealloc(void *);
IMP unsigned int rmc_access_tech_req_elem_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_access_tech_req_elem_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rmc_access_tech_req_struct_bits(void *);
IMP void rmc_access_tech_req_struct_alloc(void *);
IMP void rmc_access_tech_req_struct_dealloc(void *);
IMP unsigned int rmc_access_tech_req_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_access_tech_req_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int egprsuplnk_assign_struct_bits(void *);
IMP void egprsuplnk_assign_struct_alloc(void *);
IMP void egprsuplnk_assign_struct_dealloc(void *);
IMP unsigned int egprsuplnk_assign_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int egprsuplnk_assign_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);
#endif

IMP unsigned int pkt_uplink_assignment_msg_bits(void *);
IMP void pkt_uplink_assignment_msg_alloc(void *);
IMP void pkt_uplink_assignment_msg_dealloc(void *);
IMP unsigned int pkt_uplink_assignment_msg_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_uplink_assignment_msg_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int meas_map_peer_struct_bits(void *);
IMP void meas_map_peer_struct_alloc(void *);
IMP void meas_map_peer_struct_dealloc(void *);
IMP unsigned int meas_map_peer_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int meas_map_peer_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#ifdef __EGPRS_MODE__
IMP unsigned int egprsws_link_quality_bits(void *);
IMP void egprsws_link_quality_alloc(void *);
IMP void egprsws_link_quality_dealloc(void *);
IMP unsigned int egprsws_link_quality_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int egprsws_link_quality_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int egprsdl_assign_additions_struct_bits(void *);
IMP void egprsdl_assign_additions_struct_alloc(void *);
IMP void egprsdl_assign_additions_struct_dealloc(void *);
IMP unsigned int egprsdl_assign_additions_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int egprsdl_assign_additions_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);
#endif
/* Evelyn 20090415: Merge R6 */
#ifdef __MTBF__
IMP unsigned int rel_5_content_pdas_struct_bits(void *);
IMP void rel_5_content_pdas_struct_alloc(void *);
IMP void rel_5_content_pdas_struct_dealloc(void *);
IMP unsigned int rel_5_content_pdas_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rel_5_content_pdas_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rel_5_later_pdas_struct_bits(void *);
IMP void rel_5_later_pdas_struct_alloc(void *);
IMP void rel_5_later_pdas_struct_dealloc(void *);
IMP unsigned int rel_5_later_pdas_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rel_5_later_pdas_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rel_6_pdas_struct_bits(void *);
IMP void rel_6_pdas_struct_alloc(void *);
IMP void rel_6_pdas_struct_dealloc(void *);
IMP unsigned int rel_6_pdas_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rel_6_pdas_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);
#endif
IMP unsigned int pkt_downlink_assign_bits(void *);
IMP void pkt_downlink_assign_alloc(void *);
IMP void pkt_downlink_assign_dealloc(void *);
IMP unsigned int pkt_downlink_assign_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_downlink_assign_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define wait_struct_size(x) 2
IMP unsigned int wait_struct_bits(void *);
IMP void wait_struct_alloc(void *);
IMP void wait_struct_dealloc(void *);
IMP unsigned int wait_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int wait_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int reject_struct_bits(void *);
IMP void reject_struct_alloc(void *);
IMP void reject_struct_dealloc(void *);
IMP unsigned int reject_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int reject_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int packet_access_reject_bits(void *);
IMP void packet_access_reject_alloc(void *);
IMP void packet_access_reject_dealloc(void *);
IMP unsigned int packet_access_reject_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int packet_access_reject_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int packet_queing_notification_bits(void *);
IMP void packet_queing_notification_alloc(void *);
IMP void packet_queing_notification_dealloc(void *);
IMP unsigned int packet_queing_notification_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int packet_queing_notification_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int alloc_bitmap_struct_bits(void *);
IMP void alloc_bitmap_struct_alloc(void *);
IMP void alloc_bitmap_struct_dealloc(void *);
IMP unsigned int alloc_bitmap_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int alloc_bitmap_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ack_nack_fixed_alloc_struct_bits(void *);
IMP void ack_nack_fixed_alloc_struct_alloc(void *);
IMP void ack_nack_fixed_alloc_struct_dealloc(void *);
IMP unsigned int ack_nack_fixed_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ack_nack_fixed_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int gprsuplnk_ack_nack_struct_bits(void *);
IMP void gprsuplnk_ack_nack_struct_alloc(void *);
IMP void gprsuplnk_ack_nack_struct_dealloc(void *);
IMP unsigned int gprsuplnk_ack_nack_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gprsuplnk_ack_nack_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#ifdef __EGPRS_MODE__
IMP unsigned int egprsuplnk_ack_nack_struct_bits(void *);
IMP void egprsuplnk_ack_nack_struct_alloc(void *);
IMP void egprsuplnk_ack_nack_struct_dealloc(void *);
IMP unsigned int egprsuplnk_ack_nack_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int egprsuplnk_ack_nack_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);
#endif

IMP unsigned int pkt_uplink_ack_nack_bits(void *);
IMP void pkt_uplink_ack_nack_alloc(void *);
IMP void pkt_uplink_ack_nack_dealloc(void *);
IMP unsigned int pkt_uplink_ack_nack_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_uplink_ack_nack_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define timing_adv_index_tn_struct_size(x) 1
IMP unsigned int timing_adv_index_tn_struct_bits(void *);
IMP void timing_adv_index_tn_struct_alloc(void *);
IMP void timing_adv_index_tn_struct_dealloc(void *);
IMP unsigned int timing_adv_index_tn_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int timing_adv_index_tn_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int global_pkt_tim_adv_struct_bits(void *);
IMP void global_pkt_tim_adv_struct_alloc(void *);
IMP void global_pkt_tim_adv_struct_dealloc(void *);
IMP unsigned int global_pkt_tim_adv_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int global_pkt_tim_adv_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define global_pwr_ctrl_params_struct_size(x) 3
IMP unsigned int global_pwr_ctrl_params_struct_bits(void *);
IMP void global_pwr_ctrl_params_struct_alloc(void *);
IMP void global_pwr_ctrl_params_struct_dealloc(void *);
IMP unsigned int global_pwr_ctrl_params_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int global_pwr_ctrl_params_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int global_pwr_ctrl_pkt_tim_struct_bits(void *);
IMP void global_pwr_ctrl_pkt_tim_struct_alloc(void *);
IMP void global_pwr_ctrl_pkt_tim_struct_dealloc(void *);
IMP unsigned int global_pwr_ctrl_pkt_tim_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int global_pwr_ctrl_pkt_tim_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pkt_pwr_ctrl_tim_adv_struct_bits(void *);
IMP void pkt_pwr_ctrl_tim_adv_struct_alloc(void *);
IMP void pkt_pwr_ctrl_tim_adv_struct_dealloc(void *);
IMP unsigned int pkt_pwr_ctrl_tim_adv_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_pwr_ctrl_tim_adv_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ts_reconfig_dynamic_alloc_struct_bits(void *);
IMP void ts_reconfig_dynamic_alloc_struct_alloc(void *);
IMP void ts_reconfig_dynamic_alloc_struct_dealloc(void *);
IMP unsigned int ts_reconfig_dynamic_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ts_reconfig_dynamic_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ts_reconfig_fixed_alloc_struct_bits(void *);
IMP void ts_reconfig_fixed_alloc_struct_alloc(void *);
IMP void ts_reconfig_fixed_alloc_struct_dealloc(void *);
IMP unsigned int ts_reconfig_fixed_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ts_reconfig_fixed_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);
/* Evelyn 20090415: Merge R6 */
#ifdef __MTBF__
#define ul_dl_rb_id_struct_size(x) 2
IMP unsigned int ul_dl_rb_id_struct_bits(void *);
IMP void ul_dl_rb_id_struct_alloc(void *);
IMP void ul_dl_rb_id_struct_dealloc(void *);
IMP unsigned int ul_dl_rb_id_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ul_dl_rb_id_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rel_5_later_ptr_struct_bits(void *);
IMP void rel_5_later_ptr_struct_alloc(void *);
IMP void rel_5_later_ptr_struct_dealloc(void *);
IMP unsigned int rel_5_later_ptr_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rel_5_later_ptr_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rel_6_ptr_struct_bits(void *);
IMP void rel_6_ptr_struct_alloc(void *);
IMP void rel_6_ptr_struct_dealloc(void *);
IMP unsigned int rel_6_ptr_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rel_6_ptr_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);
#endif
IMP unsigned int gprs_timeslot_reconfig_bits(void *);
IMP void gprs_timeslot_reconfig_alloc(void *);
IMP void gprs_timeslot_reconfig_dealloc(void *);
IMP unsigned int gprs_timeslot_reconfig_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gprs_timeslot_reconfig_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#ifdef __EGPRS_MODE__
IMP unsigned int egprs_timeslot_reconfig_bits(void *);
IMP void egprs_timeslot_reconfig_alloc(void *);
IMP void egprs_timeslot_reconfig_dealloc(void *);
IMP unsigned int egprs_timeslot_reconfig_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int egprs_timeslot_reconfig_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);
#endif

IMP unsigned int pkt_timeslot_reconfigure_bits(void *);
IMP void pkt_timeslot_reconfigure_alloc(void *);
IMP void pkt_timeslot_reconfigure_dealloc(void *);
IMP unsigned int pkt_timeslot_reconfigure_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_timeslot_reconfigure_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int packet_polling_request_bits(void *);
IMP void packet_polling_request_alloc(void *);
IMP void packet_polling_request_dealloc(void *);
IMP unsigned int packet_polling_request_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int packet_polling_request_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#endif 


