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
 *  gprs_rlcmac_peer_pun.h
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
 *  FILENAME : gprs_rlcmac_peer_pun.h
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
#ifndef _GPRS_RLCMAC_PEER_PUN_H
#define _GPRS_RLCMAC_PEER_PUN_H

#define access_tech_struct_size(x) 1
IMP unsigned int access_tech_struct_bits(void *);
IMP void access_tech_struct_alloc(void *);
IMP void access_tech_struct_dealloc(void *);
IMP unsigned int access_tech_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int access_tech_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int access_tech_list_bits(void *);
IMP void access_tech_list_alloc(void *);
IMP void access_tech_list_dealloc(void *);
IMP unsigned int access_tech_list_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int access_tech_list_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pkt_downlink_dummy_ctrl_blk_bits(void *);
IMP void pkt_downlink_dummy_ctrl_blk_alloc(void *);
IMP void pkt_downlink_dummy_ctrl_blk_dealloc(void *);
IMP unsigned int pkt_downlink_dummy_ctrl_blk_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_downlink_dummy_ctrl_blk_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int packet_pdchrelease_bits(void *);
IMP void packet_pdchrelease_alloc(void *);
IMP void packet_pdchrelease_dealloc(void *);
IMP unsigned int packet_pdchrelease_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int packet_pdchrelease_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pkt_mobile_tbfstatus_bits(void *);
IMP void pkt_mobile_tbfstatus_alloc(void *);
IMP void pkt_mobile_tbfstatus_dealloc(void *);
IMP unsigned int pkt_mobile_tbfstatus_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_mobile_tbfstatus_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pkt_ctrl_ack_struct_bits(void *);
IMP void pkt_ctrl_ack_struct_alloc(void *);
IMP void pkt_ctrl_ack_struct_dealloc(void *);
IMP unsigned int pkt_ctrl_ack_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_ctrl_ack_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pkt_uplink_dummy_bits(void *);
IMP void pkt_uplink_dummy_alloc(void *);
IMP void pkt_uplink_dummy_dealloc(void *);
IMP unsigned int pkt_uplink_dummy_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_uplink_dummy_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int prach_ctrl_params_struct_bits(void *);
IMP void prach_ctrl_params_struct_alloc(void *);
IMP void prach_ctrl_params_struct_dealloc(void *);
IMP unsigned int prach_ctrl_params_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int prach_ctrl_params_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pkt_prach_params_struct_bits(void *);
IMP void pkt_prach_params_struct_alloc(void *);
IMP void pkt_prach_params_struct_dealloc(void *);
IMP unsigned int pkt_prach_params_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_prach_params_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pkt_tbfrelease_struct_bits(void *);
IMP void pkt_tbfrelease_struct_alloc(void *);
IMP void pkt_tbfrelease_struct_dealloc(void *);
IMP unsigned int pkt_tbfrelease_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_tbfrelease_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define gprsmulslot1struct_size(x) 2
IMP unsigned int gprsmulslot1struct_bits(void *);
IMP void gprsmulslot1struct_alloc(void *);
IMP void gprsmulslot1struct_dealloc(void *);
IMP unsigned int gprsmulslot1struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gprsmulslot1struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define gprsmulslot_struct_size(x) 1
IMP unsigned int gprsmulslot_struct_bits(void *);
IMP void gprsmulslot_struct_alloc(void *);
IMP void gprsmulslot_struct_dealloc(void *);
IMP unsigned int gprsmulslot_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gprsmulslot_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int multi_cap_struct_bits(void *);
IMP void multi_cap_struct_alloc(void *);
IMP void multi_cap_struct_dealloc(void *);
IMP unsigned int multi_cap_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int multi_cap_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define ms_meas_cap_struct_size(x) 1
IMP unsigned int ms_meas_cap_struct_bits(void *);
IMP void ms_meas_cap_struct_alloc(void *);
IMP void ms_meas_cap_struct_dealloc(void *);
IMP unsigned int ms_meas_cap_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ms_meas_cap_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int paccess_tech_struct_bits(void *);
IMP void paccess_tech_struct_alloc(void *);
IMP void paccess_tech_struct_dealloc(void *);
IMP unsigned int paccess_tech_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int paccess_tech_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int eaccess_tech_struct_bits(void *);
IMP void eaccess_tech_struct_alloc(void *);
IMP void eaccess_tech_struct_dealloc(void *);
IMP unsigned int eaccess_tech_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int eaccess_tech_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int raccess_tech_struct_bits(void *);
IMP void raccess_tech_struct_alloc(void *);
IMP void raccess_tech_struct_dealloc(void *);
IMP unsigned int raccess_tech_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int raccess_tech_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int aaccess_tech_struct_bits(void *);
IMP void aaccess_tech_struct_alloc(void *);
IMP void aaccess_tech_struct_dealloc(void *);
IMP unsigned int aaccess_tech_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int aaccess_tech_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ms_racapability_struct_bits(void *);
IMP void ms_racapability_struct_alloc(void *);
IMP void ms_racapability_struct_dealloc(void *);
IMP unsigned int ms_racapability_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ms_racapability_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ms_radio_cap_struct_bits(void *);
IMP void ms_radio_cap_struct_alloc(void *);
IMP void ms_radio_cap_struct_dealloc(void *);
IMP unsigned int ms_radio_cap_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ms_radio_cap_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pkt_resource_request_struct_bits(void *);
IMP void pkt_resource_request_struct_alloc(void *);
IMP void pkt_resource_request_struct_dealloc(void *);
IMP unsigned int pkt_resource_request_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_resource_request_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define nc_list_struct_size(x) 2
IMP unsigned int nc_list_struct_bits(void *);
IMP void nc_list_struct_alloc(void *);
IMP void nc_list_struct_dealloc(void *);
IMP unsigned int nc_list_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int nc_list_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int nc_freq_list_struct_bits(void *);
IMP void nc_freq_list_struct_alloc(void *);
IMP void nc_freq_list_struct_dealloc(void *);
IMP unsigned int nc_freq_list_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int nc_freq_list_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int nc_meas_params_struct_bits(void *);
IMP void nc_meas_params_struct_alloc(void *);
IMP void nc_meas_params_struct_dealloc(void *);
IMP unsigned int nc_meas_params_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int nc_meas_params_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int int_freq_list_struct_bits(void *);
IMP void int_freq_list_struct_alloc(void *);
IMP void int_freq_list_struct_dealloc(void *);
IMP unsigned int int_freq_list_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int int_freq_list_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ncc_or_freq_struct_bits(void *);
IMP void ncc_or_freq_struct_alloc(void *);
IMP void ncc_or_freq_struct_dealloc(void *);
IMP unsigned int ncc_or_freq_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ncc_or_freq_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int em1struct_bits(void *);
IMP void em1struct_alloc(void *);
IMP void em1struct_dealloc(void *);
IMP unsigned int em1struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int em1struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ext_meas_params_struct_bits(void *);
IMP void ext_meas_params_struct_alloc(void *);
IMP void ext_meas_params_struct_dealloc(void *);
IMP unsigned int ext_meas_params_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ext_meas_params_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int measurement_peer_struct_bits(void *);
IMP void measurement_peer_struct_alloc(void *);
IMP void measurement_peer_struct_dealloc(void *);
IMP unsigned int measurement_peer_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int measurement_peer_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pkt_measurement_order_struct_bits(void *);
IMP void pkt_measurement_order_struct_alloc(void *);
IMP void pkt_measurement_order_struct_dealloc(void *);
IMP unsigned int pkt_measurement_order_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_measurement_order_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pkt_cell_change_order_bits(void *);
IMP void pkt_cell_change_order_alloc(void *);
IMP void pkt_cell_change_order_dealloc(void *);
IMP unsigned int pkt_cell_change_order_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_cell_change_order_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int mobile_idstruct_bits(void *);
IMP void mobile_idstruct_alloc(void *);
IMP void mobile_idstruct_dealloc(void *);
IMP unsigned int mobile_idstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int mobile_idstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ptmsistruct_bits(void *);
IMP void ptmsistruct_alloc(void *);
IMP void ptmsistruct_dealloc(void *);
IMP unsigned int ptmsistruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ptmsistruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int tmsistruct_bits(void *);
IMP void tmsistruct_alloc(void *);
IMP void tmsistruct_dealloc(void *);
IMP unsigned int tmsistruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int tmsistruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int repeated_page_info_struct_bits(void *);
IMP void repeated_page_info_struct_alloc(void *);
IMP void repeated_page_info_struct_dealloc(void *);
IMP unsigned int repeated_page_info_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int repeated_page_info_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int packet_paging_request_bits(void *);
IMP void packet_paging_request_alloc(void *);
IMP void packet_paging_request_dealloc(void *);
IMP unsigned int packet_paging_request_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int packet_paging_request_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define pdu_descript_struct_size(x) 2
IMP unsigned int pdu_descript_struct_bits(void *);
IMP void pdu_descript_struct_alloc(void *);
IMP void pdu_descript_struct_dealloc(void *);
IMP unsigned int pdu_descript_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pdu_descript_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define mode_flag_struct_size(x) 1
IMP unsigned int mode_flag_struct_bits(void *);
IMP void mode_flag_struct_alloc(void *);
IMP void mode_flag_struct_dealloc(void *);
IMP unsigned int mode_flag_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int mode_flag_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define gprs_test_mode_cmd_struct_size(x) 5
IMP unsigned int gprs_test_mode_cmd_struct_bits(void *);
IMP void gprs_test_mode_cmd_struct_alloc(void *);
IMP void gprs_test_mode_cmd_struct_dealloc(void *);
IMP unsigned int gprs_test_mode_cmd_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gprs_test_mode_cmd_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#endif 


