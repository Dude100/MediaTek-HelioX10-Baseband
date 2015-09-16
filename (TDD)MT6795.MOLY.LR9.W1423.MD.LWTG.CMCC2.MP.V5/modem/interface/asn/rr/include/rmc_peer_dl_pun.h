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
 *  rmc_peer_dl_pun.h
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
 *  FILENAME : rmc_peer_dl_pun.h
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
#ifndef _RMC_PEER_DL_PUN_H
#define _RMC_PEER_DL_PUN_H

IMP unsigned int rr_packet_downlink_struct_bits(void *);
IMP void rr_packet_downlink_struct_alloc(void *);
IMP void rr_packet_downlink_struct_dealloc(void *);
IMP unsigned int rr_packet_downlink_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rr_packet_downlink_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pdch_dynamic_alloc_struct_bits(void *);
IMP void pdch_dynamic_alloc_struct_alloc(void *);
IMP void pdch_dynamic_alloc_struct_dealloc(void *);
IMP unsigned int pdch_dynamic_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pdch_dynamic_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pdch_single_blk_alloc_struct_bits(void *);
IMP void pdch_single_blk_alloc_struct_alloc(void *);
IMP void pdch_single_blk_alloc_struct_dealloc(void *);
IMP unsigned int pdch_single_blk_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pdch_single_blk_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pdch_fixed_alloc_struct_bits(void *);
IMP void pdch_fixed_alloc_struct_alloc(void *);
IMP void pdch_fixed_alloc_struct_dealloc(void *);
IMP unsigned int pdch_fixed_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pdch_fixed_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rr_packet_uplink_struct_bits(void *);
IMP void rr_packet_uplink_struct_alloc(void *);
IMP void rr_packet_uplink_struct_dealloc(void *);
IMP unsigned int rr_packet_uplink_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rr_packet_uplink_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define rmc_start_time_struct_size(x) 2
IMP unsigned int rmc_start_time_struct_bits(void *);
IMP void rmc_start_time_struct_alloc(void *);
IMP void rmc_start_time_struct_dealloc(void *);
IMP unsigned int rmc_start_time_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_start_time_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int starting_time_bits(void *);
IMP void starting_time_alloc(void *);
IMP void starting_time_dealloc(void *);
IMP unsigned int starting_time_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int starting_time_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define rmc_p0_pwr_cntrl_mode_struct_size(x) 1
IMP unsigned int rmc_p0_pwr_cntrl_mode_struct_bits(void *);
IMP void rmc_p0_pwr_cntrl_mode_struct_alloc(void *);
IMP void rmc_p0_pwr_cntrl_mode_struct_dealloc(void *);
IMP unsigned int rmc_p0_pwr_cntrl_mode_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_p0_pwr_cntrl_mode_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rmc_single_block_alloc_struct_bits(void *);
IMP void rmc_single_block_alloc_struct_alloc(void *);
IMP void rmc_single_block_alloc_struct_dealloc(void *);
IMP unsigned int rmc_single_block_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_single_block_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define rmc_p0_pr_mode_struct_size(x) 1
IMP unsigned int rmc_p0_pr_mode_struct_bits(void *);
IMP void rmc_p0_pr_mode_struct_alloc(void *);
IMP void rmc_p0_pr_mode_struct_dealloc(void *);
IMP unsigned int rmc_p0_pr_mode_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_p0_pr_mode_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rmc_dyn_alloc_struct_bits(void *);
IMP void rmc_dyn_alloc_struct_alloc(void *);
IMP void rmc_dyn_alloc_struct_dealloc(void *);
IMP unsigned int rmc_dyn_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_dyn_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rmc_fixed_alloc_struct_bits(void *);
IMP void rmc_fixed_alloc_struct_alloc(void *);
IMP void rmc_fixed_alloc_struct_dealloc(void *);
IMP unsigned int rmc_fixed_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_fixed_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rmc_dyn_or_fixed_alloc_struct_bits(void *);
IMP void rmc_dyn_or_fixed_alloc_struct_alloc(void *);
IMP void rmc_dyn_or_fixed_alloc_struct_dealloc(void *);
IMP unsigned int rmc_dyn_or_fixed_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_dyn_or_fixed_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rmc_pkt_ul_asgn_struct_bits(void *);
IMP void rmc_pkt_ul_asgn_struct_alloc(void *);
IMP void rmc_pkt_ul_asgn_struct_dealloc(void *);
IMP unsigned int rmc_pkt_ul_asgn_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_pkt_ul_asgn_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#ifdef __EGPRS_MODE__
IMP unsigned int rmc_multi_blk_alloc_struct_bits(void *);
IMP void rmc_multi_blk_alloc_struct_alloc(void *);
IMP void rmc_multi_blk_alloc_struct_dealloc(void *);
IMP unsigned int rmc_multi_blk_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_multi_blk_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define rmc_egprs_mod_and_coding_struct_size(x) 1
IMP unsigned int rmc_egprs_mod_and_coding_struct_bits(void *);
IMP void rmc_egprs_mod_and_coding_struct_alloc(void *);
IMP void rmc_egprs_mod_and_coding_struct_dealloc(void *);
IMP unsigned int rmc_egprs_mod_and_coding_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_egprs_mod_and_coding_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define rmc_egprs_window_size_struct_size(x) 1
IMP unsigned int rmc_egprs_window_size_struct_bits(void *);
IMP void rmc_egprs_window_size_struct_alloc(void *);
IMP void rmc_egprs_window_size_struct_dealloc(void *);
IMP unsigned int rmc_egprs_window_size_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_egprs_window_size_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rmc_egprs_dyn_or_fixed_alloc_struct_bits(void *);
IMP void rmc_egprs_dyn_or_fixed_alloc_struct_alloc(void *);
IMP void rmc_egprs_dyn_or_fixed_alloc_struct_dealloc(void *);
IMP unsigned int rmc_egprs_dyn_or_fixed_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_egprs_dyn_or_fixed_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rmc_egprs_pkt_ul_asgn_struct_bits(void *);
IMP void rmc_egprs_pkt_ul_asgn_struct_alloc(void *);
IMP void rmc_egprs_pkt_ul_asgn_struct_dealloc(void *);
IMP unsigned int rmc_egprs_pkt_ul_asgn_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_egprs_pkt_ul_asgn_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#endif


IMP unsigned int rmc_freq_params_with_length_struct_bits(void *);
IMP void rmc_freq_params_with_length_struct_alloc(void *);
IMP void rmc_freq_params_with_length_struct_dealloc(void *);
IMP unsigned int rmc_freq_params_with_length_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_freq_params_with_length_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rmc_rlc_mode_alpha_gamma_struct_bits(void *);
IMP void rmc_rlc_mode_alpha_gamma_struct_alloc(void *);
IMP void rmc_rlc_mode_alpha_gamma_struct_dealloc(void *);
IMP unsigned int rmc_rlc_mode_alpha_gamma_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_rlc_mode_alpha_gamma_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rmc_pkt_dl_asgn_struct_bits(void *);
IMP void rmc_pkt_dl_asgn_struct_alloc(void *);
IMP void rmc_pkt_dl_asgn_struct_dealloc(void *);
IMP unsigned int rmc_pkt_dl_asgn_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_pkt_dl_asgn_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *, kal_uint8);

IMP unsigned int iarest_octets_bits(void *);
IMP void iarest_octets_alloc(void *);
IMP void iarest_octets_dealloc(void *);
IMP unsigned int iarest_octets_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int iarest_octets_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#endif 


