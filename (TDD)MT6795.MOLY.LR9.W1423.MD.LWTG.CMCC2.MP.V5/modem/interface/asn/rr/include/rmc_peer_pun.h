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
 *  rmc_peer_pun.h
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
 *  FILENAME : rmc_peer_pun.h
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
#ifndef _RMC_PEER_PUN_H
#define _RMC_PEER_PUN_H

#define spare_and_arfcn_struct_size(x) 2
IMP unsigned int spare_and_arfcn_struct_bits(void *);
IMP void spare_and_arfcn_struct_alloc(void *);
IMP void spare_and_arfcn_struct_dealloc(void *);
IMP unsigned int spare_and_arfcn_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int spare_and_arfcn_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define maio_and_hsn_struct_size(x) 2
IMP unsigned int maio_and_hsn_struct_bits(void *);
IMP void maio_and_hsn_struct_alloc(void *);
IMP void maio_and_hsn_struct_dealloc(void *);
IMP unsigned int maio_and_hsn_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int maio_and_hsn_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int chan_desc_struct_bits(void *);
IMP void chan_desc_struct_alloc(void *);
IMP void chan_desc_struct_dealloc(void *);
IMP unsigned int chan_desc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int chan_desc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rmc_maio_struct_bits(void *);
IMP void rmc_maio_struct_alloc(void *);
IMP void rmc_maio_struct_dealloc(void *);
IMP unsigned int rmc_maio_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_maio_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define arfcn_struct_size(x) 2
IMP unsigned int arfcn_struct_bits(void *);
IMP void arfcn_struct_alloc(void *);
IMP void arfcn_struct_dealloc(void *);
IMP unsigned int arfcn_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int arfcn_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int non_hop_or_indirect_enc_struct_bits(void *);
IMP void non_hop_or_indirect_enc_struct_alloc(void *);
IMP void non_hop_or_indirect_enc_struct_dealloc(void *);
IMP unsigned int non_hop_or_indirect_enc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int non_hop_or_indirect_enc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define direct_enc_struct_size(x) 2
IMP unsigned int direct_enc_struct_bits(void *);
IMP void direct_enc_struct_alloc(void *);
IMP void direct_enc_struct_dealloc(void *);
IMP unsigned int direct_enc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int direct_enc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pkt_chan_desc_struct_bits(void *);
IMP void pkt_chan_desc_struct_alloc(void *);
IMP void pkt_chan_desc_struct_dealloc(void *);
IMP unsigned int pkt_chan_desc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_chan_desc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define m_timing_advance_struct_size(x) 1
IMP unsigned int m_timing_advance_struct_bits(void *);
IMP void m_timing_advance_struct_alloc(void *);
IMP void m_timing_advance_struct_dealloc(void *);
IMP unsigned int m_timing_advance_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int m_timing_advance_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define rmc_request_reference_struct_size(x) 3
IMP unsigned int rmc_request_reference_struct_bits(void *);
IMP void rmc_request_reference_struct_alloc(void *);
IMP void rmc_request_reference_struct_dealloc(void *);
IMP unsigned int rmc_request_reference_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_request_reference_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rmc_mobile_alloc_struct_bits(void *);
IMP void rmc_mobile_alloc_struct_alloc(void *);
IMP void rmc_mobile_alloc_struct_dealloc(void *);
IMP unsigned int rmc_mobile_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_mobile_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define mesg_type_struct_size(x) 1
IMP unsigned int mesg_type_struct_bits(void *);
IMP void mesg_type_struct_alloc(void *);
IMP void mesg_type_struct_dealloc(void *);
IMP unsigned int mesg_type_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int mesg_type_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define rr_rmc_page_mode_struct_size(x) 1
IMP unsigned int rr_rmc_page_mode_struct_bits(void *);
IMP void rr_rmc_page_mode_struct_alloc(void *);
IMP void rr_rmc_page_mode_struct_dealloc(void *);
IMP unsigned int rr_rmc_page_mode_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rr_rmc_page_mode_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define dedicated_mode_or_tbf_struct_size(x) 1
IMP unsigned int dedicated_mode_or_tbf_struct_bits(void *);
IMP void dedicated_mode_or_tbf_struct_alloc(void *);
IMP void dedicated_mode_or_tbf_struct_dealloc(void *);
IMP unsigned int dedicated_mode_or_tbf_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int dedicated_mode_or_tbf_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define rmc_rr_protocol_disc_struct_size(x) 1
IMP unsigned int rmc_rr_protocol_disc_struct_bits(void *);
IMP void rmc_rr_protocol_disc_struct_alloc(void *);
IMP void rmc_rr_protocol_disc_struct_dealloc(void *);
IMP unsigned int rmc_rr_protocol_disc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_rr_protocol_disc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define rmc_rr_skip_indicator_struct_size(x) 1
IMP unsigned int rmc_rr_skip_indicator_struct_bits(void *);
IMP void rmc_rr_skip_indicator_struct_alloc(void *);
IMP void rmc_rr_skip_indicator_struct_dealloc(void *);
IMP unsigned int rmc_rr_skip_indicator_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_rr_skip_indicator_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define rmc_l2_pseudo_length_struct_size(x) 1
IMP unsigned int rmc_l2_pseudo_length_struct_bits(void *);
IMP void rmc_l2_pseudo_length_struct_alloc(void *);
IMP void rmc_l2_pseudo_length_struct_dealloc(void *);
IMP unsigned int rmc_l2_pseudo_length_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_l2_pseudo_length_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int immediate_assign_message_bits(void *);
IMP void immediate_assign_message_alloc(void *);
IMP void immediate_assign_message_dealloc(void *);
IMP unsigned int immediate_assign_message_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int immediate_assign_message_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define rmc_spare_half_octet_struct_size(x) 1
IMP unsigned int rmc_spare_half_octet_struct_bits(void *);
IMP void rmc_spare_half_octet_struct_alloc(void *);
IMP void rmc_spare_half_octet_struct_dealloc(void *);
IMP unsigned int rmc_spare_half_octet_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_spare_half_octet_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define rmc_wait_indication_struct_size(x) 1
IMP unsigned int rmc_wait_indication_struct_bits(void *);
IMP void rmc_wait_indication_struct_alloc(void *);
IMP void rmc_wait_indication_struct_dealloc(void *);
IMP unsigned int rmc_wait_indication_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rmc_wait_indication_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define iarrest_octets_size(x) 3
IMP unsigned int iarrest_octets_bits(void *);
IMP void iarrest_octets_alloc(void *);
IMP void iarrest_octets_dealloc(void *);
IMP unsigned int iarrest_octets_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int iarrest_octets_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define imm_asgn_rej_msg_struct_size(x) 23
IMP unsigned int imm_asgn_rej_msg_struct_bits(void *);
IMP void imm_asgn_rej_msg_struct_alloc(void *);
IMP void imm_asgn_rej_msg_struct_dealloc(void *);
IMP unsigned int imm_asgn_rej_msg_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int imm_asgn_rej_msg_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int immediate_assign_dedicated_bits(void *);
IMP void immediate_assign_dedicated_alloc(void *);
IMP void immediate_assign_dedicated_dealloc(void *);
IMP unsigned int immediate_assign_dedicated_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int immediate_assign_dedicated_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int immediate_assign_ext_message_bits(void *);
IMP void immediate_assign_ext_message_alloc(void *);
IMP void immediate_assign_ext_message_dealloc(void *);
IMP unsigned int immediate_assign_ext_message_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int immediate_assign_ext_message_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

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
#endif

#define rr_status_struct_size(x) 3
IMP unsigned int rr_status_struct_bits(void *);
IMP void rr_status_struct_alloc(void *);
IMP void rr_status_struct_dealloc(void *);
IMP unsigned int rr_status_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rr_status_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define cell_channel_description_struct_size(x) 16
IMP unsigned int cell_channel_description_struct_bits(void *);
IMP void cell_channel_description_struct_alloc(void *);
IMP void cell_channel_description_struct_dealloc(void *);
IMP unsigned int cell_channel_description_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int cell_channel_description_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define cell_description_struct_size(x) 2
IMP unsigned int cell_description_struct_bits(void *);
IMP void cell_description_struct_alloc(void *);
IMP void cell_description_struct_dealloc(void *);
IMP unsigned int cell_description_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int cell_description_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define nc_mode_struct_size(x) 1
IMP unsigned int nc_mode_struct_bits(void *);
IMP void nc_mode_struct_alloc(void *);
IMP void nc_mode_struct_dealloc(void *);
IMP unsigned int nc_mode_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int nc_mode_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define rr_cell_change_order_struct_size(x) 5
IMP unsigned int rr_cell_change_order_struct_bits(void *);
IMP void rr_cell_change_order_struct_alloc(void *);
IMP void rr_cell_change_order_struct_dealloc(void *);
IMP unsigned int rr_cell_change_order_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rr_cell_change_order_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define extended_measurement_freq_list_struct_size(x) 16
IMP unsigned int extended_measurement_freq_list_struct_bits(void *);
IMP void extended_measurement_freq_list_struct_alloc(void *);
IMP void extended_measurement_freq_list_struct_dealloc(void *);
IMP unsigned int extended_measurement_freq_list_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int extended_measurement_freq_list_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define extended_measurement_order_struct_size(x) 19
IMP unsigned int extended_measurement_order_struct_bits(void *);
IMP void extended_measurement_order_struct_alloc(void *);
IMP void extended_measurement_order_struct_dealloc(void *);
IMP unsigned int extended_measurement_order_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int extended_measurement_order_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int channel_description_struct_bits(void *);
IMP void channel_description_struct_alloc(void *);
IMP void channel_description_struct_dealloc(void *);
IMP unsigned int channel_description_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int channel_description_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int frequency_list_struct_bits(void *);
IMP void frequency_list_struct_alloc(void *);
IMP void frequency_list_struct_dealloc(void *);
IMP unsigned int frequency_list_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int frequency_list_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int frequency_short_list_struct_bits(void *);
IMP void frequency_short_list_struct_alloc(void *);
IMP void frequency_short_list_struct_dealloc(void *);
IMP unsigned int frequency_short_list_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int frequency_short_list_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define frequency_channel_sequence_struct_size(x) 9
IMP unsigned int frequency_channel_sequence_struct_bits(void *);
IMP void frequency_channel_sequence_struct_alloc(void *);
IMP void frequency_channel_sequence_struct_dealloc(void *);
IMP unsigned int frequency_channel_sequence_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int frequency_channel_sequence_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define power_command_struct_size(x) 1
IMP unsigned int power_command_struct_bits(void *);
IMP void power_command_struct_alloc(void *);
IMP void power_command_struct_dealloc(void *);
IMP unsigned int power_command_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int power_command_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define cipher_mode_setting_struct_size(x) 1
IMP unsigned int cipher_mode_setting_struct_bits(void *);
IMP void cipher_mode_setting_struct_alloc(void *);
IMP void cipher_mode_setting_struct_dealloc(void *);
IMP unsigned int cipher_mode_setting_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int cipher_mode_setting_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define vgcs_target_mode_indication_struct_size(x) 2
IMP unsigned int vgcs_target_mode_indication_struct_bits(void *);
IMP void vgcs_target_mode_indication_struct_alloc(void *);
IMP void vgcs_target_mode_indication_struct_dealloc(void *);
IMP unsigned int vgcs_target_mode_indication_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int vgcs_target_mode_indication_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int assignment_command_struct_bits(void *);
IMP void assignment_command_struct_alloc(void *);
IMP void assignment_command_struct_dealloc(void *);
IMP unsigned int assignment_command_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int assignment_command_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pdch_assignment_command_struct_bits(void *);
IMP void pdch_assignment_command_struct_alloc(void *);
IMP void pdch_assignment_command_struct_dealloc(void *);
IMP unsigned int pdch_assignment_command_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pdch_assignment_command_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define classmark2_struct_size(x) 4
IMP unsigned int classmark2_struct_bits(void *);
IMP void classmark2_struct_alloc(void *);
IMP void classmark2_struct_dealloc(void *);
IMP unsigned int classmark2_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int classmark2_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define a5_bits_struct_size(x) 1
IMP unsigned int a5_bits_struct_bits(void *);
IMP void a5_bits_struct_alloc(void *);
IMP void a5_bits_struct_dealloc(void *);
IMP unsigned int a5_bits_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int a5_bits_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define a5_bits_1_struct_size(x) 2
IMP unsigned int a5_bits_1_struct_bits(void *);
IMP void a5_bits_1_struct_alloc(void *);
IMP void a5_bits_1_struct_dealloc(void *);
IMP unsigned int a5_bits_1_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int a5_bits_1_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define a5_bits_2_struct_size(x) 2
IMP unsigned int a5_bits_2_struct_bits(void *);
IMP void a5_bits_2_struct_alloc(void *);
IMP void a5_bits_2_struct_dealloc(void *);
IMP unsigned int a5_bits_2_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int a5_bits_2_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int edge_struct_bits(void *);
IMP void edge_struct_alloc(void *);
IMP void edge_struct_dealloc(void *);
IMP unsigned int edge_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int edge_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define gsm_band_inf_struct_size(x) 1
IMP unsigned int gsm_band_inf_struct_bits(void *);
IMP void gsm_band_inf_struct_alloc(void *);
IMP void gsm_band_inf_struct_dealloc(void *);
IMP unsigned int gsm_band_inf_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gsm_band_inf_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define gprs_mlt_slt_struct_size(x) 1
IMP unsigned int gprs_mlt_slt_struct_bits(void *);
IMP void gprs_mlt_slt_struct_alloc(void *);
IMP void gprs_mlt_slt_struct_dealloc(void *);
IMP unsigned int gprs_mlt_slt_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gprs_mlt_slt_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int classmark3_struct_bits(void *);
IMP void classmark3_struct_alloc(void *);
IMP void classmark3_struct_dealloc(void *);
IMP unsigned int classmark3_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int classmark3_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define classmark_enq_mask_size(x) 2
IMP unsigned int classmark_enq_mask_bits(void *);
IMP void classmark_enq_mask_alloc(void *);
IMP void classmark_enq_mask_dealloc(void *);
IMP unsigned int classmark_enq_mask_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int classmark_enq_mask_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rr_peer_classmark_enquiry_struct_bits(void *);
IMP void rr_peer_classmark_enquiry_struct_alloc(void *);
IMP void rr_peer_classmark_enquiry_struct_dealloc(void *);
IMP unsigned int rr_peer_classmark_enquiry_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rr_peer_classmark_enquiry_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define rr_peer_partial_release_complete_struct_size(x) 2
IMP unsigned int rr_peer_partial_release_complete_struct_bits(void *);
IMP void rr_peer_partial_release_complete_struct_alloc(void *);
IMP void rr_peer_partial_release_complete_struct_dealloc(void *);
IMP unsigned int rr_peer_partial_release_complete_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rr_peer_partial_release_complete_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rr_peer_additional_assignment_struct_bits(void *);
IMP void rr_peer_additional_assignment_struct_alloc(void *);
IMP void rr_peer_additional_assignment_struct_dealloc(void *);
IMP unsigned int rr_peer_additional_assignment_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rr_peer_additional_assignment_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#define rr_peer_rr_status_struct_size(x) 3
IMP unsigned int rr_peer_rr_status_struct_bits(void *);
IMP void rr_peer_rr_status_struct_alloc(void *);
IMP void rr_peer_rr_status_struct_dealloc(void *);
IMP unsigned int rr_peer_rr_status_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rr_peer_rr_status_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rr_peer_partial_release_struct_bits(void *);
IMP void rr_peer_partial_release_struct_alloc(void *);
IMP void rr_peer_partial_release_struct_dealloc(void *);
IMP unsigned int rr_peer_partial_release_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rr_peer_partial_release_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define loop_type_struct_size(x) 1
IMP unsigned int loop_type_struct_bits(void *);
IMP void loop_type_struct_alloc(void *);
IMP void loop_type_struct_dealloc(void *);
IMP unsigned int loop_type_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int loop_type_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define close_tch_loop_cmd_struct_size(x) 3
IMP unsigned int close_tch_loop_cmd_struct_bits(void *);
IMP void close_tch_loop_cmd_struct_alloc(void *);
IMP void close_tch_loop_cmd_struct_dealloc(void *);
IMP unsigned int close_tch_loop_cmd_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int close_tch_loop_cmd_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int open_loop_cmd_struct_bits(void *);
IMP void open_loop_cmd_struct_alloc(void *);
IMP void open_loop_cmd_struct_dealloc(void *);
IMP unsigned int open_loop_cmd_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int open_loop_cmd_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define close_multi_loop_cmd_struct_size(x) 3
IMP unsigned int close_multi_loop_cmd_struct_bits(void *);
IMP void close_multi_loop_cmd_struct_alloc(void *);
IMP void close_multi_loop_cmd_struct_dealloc(void *);
IMP unsigned int close_multi_loop_cmd_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int close_multi_loop_cmd_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define open_multi_loop_cmd_struct_size(x) 2
IMP unsigned int open_multi_loop_cmd_struct_bits(void *);
IMP void open_multi_loop_cmd_struct_alloc(void *);
IMP void open_multi_loop_cmd_struct_dealloc(void *);
IMP unsigned int open_multi_loop_cmd_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int open_multi_loop_cmd_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define close_multi_loop_ack_result_struct_size(x) 1
IMP unsigned int close_multi_loop_ack_result_struct_bits(void *);
IMP void close_multi_loop_ack_result_struct_alloc(void *);
IMP void close_multi_loop_ack_result_struct_dealloc(void *);
IMP unsigned int close_multi_loop_ack_result_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int close_multi_loop_ack_result_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define close_multi_loop_ack_size(x) 3
IMP unsigned int close_multi_loop_ack_bits(void *);
IMP void close_multi_loop_ack_alloc(void *);
IMP void close_multi_loop_ack_dealloc(void *);
IMP unsigned int close_multi_loop_ack_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int close_multi_loop_ack_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define cipher_mode_command_struct_size(x) 3
IMP unsigned int cipher_mode_command_struct_bits(void *);
IMP void cipher_mode_command_struct_alloc(void *);
IMP void cipher_mode_command_struct_dealloc(void *);
IMP unsigned int cipher_mode_command_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int cipher_mode_command_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int cipher_mode_complete_struct_bits(void *);
IMP void cipher_mode_complete_struct_alloc(void *);
IMP void cipher_mode_complete_struct_dealloc(void *);
IMP unsigned int cipher_mode_complete_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int cipher_mode_complete_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int configuration_change_command_struct_bits(void *);
IMP void configuration_change_command_struct_alloc(void *);
IMP void configuration_change_command_struct_dealloc(void *);
IMP unsigned int configuration_change_command_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int configuration_change_command_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define sync_info_struct_size(x) 1
IMP unsigned int sync_info_struct_bits(void *);
IMP void sync_info_struct_alloc(void *);
IMP void sync_info_struct_dealloc(void *);
IMP unsigned int sync_info_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int sync_info_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define real_time_diff_struct_size(x) 2
IMP unsigned int real_time_diff_struct_bits(void *);
IMP void real_time_diff_struct_alloc(void *);
IMP void real_time_diff_struct_dealloc(void *);
IMP unsigned int real_time_diff_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int real_time_diff_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define mob_obs_time_diff_struct_size(x) 4
IMP unsigned int mob_obs_time_diff_struct_bits(void *);
IMP void mob_obs_time_diff_struct_alloc(void *);
IMP void mob_obs_time_diff_struct_dealloc(void *);
IMP unsigned int mob_obs_time_diff_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int mob_obs_time_diff_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int handover_command_struct_bits(void *);
IMP void handover_command_struct_alloc(void *);
IMP void handover_command_struct_dealloc(void *);
IMP unsigned int handover_command_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int handover_command_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int handover_complete_struct_bits(void *);
IMP void handover_complete_struct_alloc(void *);
IMP void handover_complete_struct_dealloc(void *);
IMP unsigned int handover_complete_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int handover_complete_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define physical_information_struct_size(x) 3
IMP unsigned int physical_information_struct_bits(void *);
IMP void physical_information_struct_alloc(void *);
IMP void physical_information_struct_dealloc(void *);
IMP unsigned int physical_information_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int physical_information_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int apdu_data_struct_bits(void *);
IMP void apdu_data_struct_alloc(void * );
IMP void apdu_data_struct_dealloc(void * );
IMP unsigned int apdu_data_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int apdu_data_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);
IMP unsigned int application_information_struct_bits(void *);
IMP void application_information_struct_alloc(void *);
IMP void application_information_struct_dealloc(void *);
IMP unsigned int application_information_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int application_information_struct_unpack(void * , kal_uint8 * ,unsigned int , unsigned int , void * );
IMP unsigned int channel_request_struct_bits(void * );
IMP void channel_request_struct_alloc(void * );
IMP void channel_request_struct_dealloc(void * );
IMP unsigned int channel_request_struct_pack(kal_uint8 * , void * ,unsigned int );
IMP unsigned int channel_request_struct_unpack(void * , kal_uint8 * ,unsigned int , unsigned int , void * );
IMP unsigned int frequency_redefinition_struct_bits(void *);
IMP void frequency_redefinition_struct_alloc(void *);
IMP void frequency_redefinition_struct_dealloc(void *);
IMP unsigned int frequency_redefinition_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int frequency_redefinition_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int channel_mode_modify_struct_bits(void *);
IMP void channel_mode_modify_struct_alloc(void *);
IMP void channel_mode_modify_struct_dealloc(void *);
IMP unsigned int channel_mode_modify_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int channel_mode_modify_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int channel_mode_modify_ack_struct_bits(void *);
IMP void channel_mode_modify_ack_struct_alloc(void *);
IMP void channel_mode_modify_ack_struct_dealloc(void *);
IMP unsigned int channel_mode_modify_ack_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int channel_mode_modify_ack_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#ifdef __ETWS_SUPPORT__
extern void rr_decode_group_call_info(bit_stream *bs_ptr, kal_uint16 *length, kal_bool *result);
extern void rr_decode_cell_global_count(bit_stream *bs_ptr, kal_uint16 *length, kal_bool *result);
extern void rr_decode_mbms_para(bit_stream *bs_ptr, kal_uint16 *length, kal_bool *result);
extern void rr_decode_mbms_channel_para_ie(bit_stream *bs_ptr, kal_uint16 *length, kal_bool *result);
extern void rr_decode_mbms_session_list_ie(bit_stream *bs_ptr, kal_uint16 *length, kal_bool *result);
extern void rr_decode_mbms_freq_para_ie(bit_stream *bs_ptr, kal_uint16 *length, kal_bool *result);
#ifdef __PS_SERVICE__
extern void rr_decode_page_info_struct(bit_stream *bs_ptr, kal_uint16 *length);
extern void rr_decode_repeated_iu_page_info(bit_stream *bs_ptr, kal_uint16 *length);
#endif /* __PS_SERVICE__ */
#endif /* __ETWS_SUPPORT__ */

#endif 


