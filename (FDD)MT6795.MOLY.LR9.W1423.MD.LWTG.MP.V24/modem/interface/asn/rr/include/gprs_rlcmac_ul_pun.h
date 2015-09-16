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
 *  gprs_rlcmac_ul_pun.h
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
 *  FILENAME : gprs_rlcmac_ul_pun.h
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
#ifndef _GPRS_RLCMAC_UL_PUN_H
#define _GPRS_RLCMAC_UL_PUN_H

/*Evelyn: Remove redundant header and file */
#include "kal_general_types.h"

IMP unsigned int utran_fdd_struct_bits(void *);
IMP void utran_fdd_struct_alloc(void *);
IMP void utran_fdd_struct_dealloc(void *);
IMP unsigned int utran_fdd_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int utran_fdd_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int add_3G_r99_struct_bits(void *);
IMP void add_3G_r99_struct_alloc(void *);
IMP void add_3G_r99_struct_dealloc(void *);
IMP unsigned int add_3G_r99_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int add_3G_r99_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pkt_cell_change_failure_msg_bits(void *);
IMP void pkt_cell_change_failure_msg_alloc(void *);
IMP void pkt_cell_change_failure_msg_dealloc(void *);
IMP unsigned int pkt_cell_change_failure_msg_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_cell_change_failure_msg_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int level_struct_bits(void *);
IMP void level_struct_alloc(void *);
IMP void level_struct_dealloc(void *);
IMP unsigned int level_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int level_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int interference_level_struct_bits(void *);
IMP void interference_level_struct_alloc(void *);
IMP void interference_level_struct_dealloc(void *);
IMP unsigned int interference_level_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int interference_level_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ext_meas_report_struct_bits(void *);
IMP void ext_meas_report_struct_alloc(void *);
IMP void ext_meas_report_struct_dealloc(void *);
IMP unsigned int ext_meas_report_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ext_meas_report_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define ba_used_struct_size(x) 1
IMP unsigned int ba_used_struct_bits(void *);
IMP void ba_used_struct_alloc(void *);
IMP void ba_used_struct_dealloc(void *);
IMP unsigned int ba_used_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ba_used_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pmo_used_struct_bits(void *);
IMP void pmo_used_struct_alloc(void *);
IMP void pmo_used_struct_dealloc(void *);
IMP unsigned int pmo_used_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pmo_used_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pmr_add_r99_struct_bits(void *);
IMP void pmr_add_r99_struct_alloc(void *);
IMP void pmr_add_r99_struct_dealloc(void *);
IMP unsigned int pmr_add_r99_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pmr_add_r99_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pkt_meas_report_struct_bits(void *);
IMP void pkt_meas_report_struct_alloc(void *);
/*
#ifdef __R99__
IMP void pkt_enh_meas_report_struct_alloc(void *);
#endif
*/
IMP void pkt_meas_report_struct_dealloc(void *);
IMP unsigned int pkt_meas_report_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_meas_report_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int serving_cell_data_struct_bits(void *);
IMP void serving_cell_data_struct_alloc(void *);
IMP void serving_cell_data_struct_dealloc(void *);
IMP unsigned int serving_cell_data_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int serving_cell_data_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define rp_bsic_struct_size(x) 3
IMP unsigned int rp_bsic_struct_bits(void *);
IMP void rp_bsic_struct_alloc(void *);
IMP void rp_bsic_struct_dealloc(void *);
IMP unsigned int rp_bsic_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rp_bsic_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int reporting_quantity_struct_bits(void *);
IMP void reporting_quantity_struct_alloc(void *, kal_uint8);
IMP void reporting_quantity_struct_dealloc(void *);
IMP unsigned int reporting_quantity_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int reporting_quantity_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int invalid_bsic_struct_bits(void *);
IMP void invalid_bsic_struct_alloc(void *);
IMP void invalid_bsic_struct_dealloc(void *);
IMP unsigned int invalid_bsic_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int invalid_bsic_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int enh_nc_meas_rep_struct_bits(void *);
IMP void enh_nc_meas_rep_struct_alloc(void *);
IMP void enh_nc_meas_rep_struct_dealloc(void *);
IMP unsigned int enh_nc_meas_rep_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int enh_nc_meas_rep_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pkt_enh_meas_report_struct_bits(void *);
IMP void pkt_enh_meas_report_struct_alloc(void *);
IMP void pkt_enh_meas_report_struct_dealloc(void *);
IMP unsigned int pkt_enh_meas_report_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_enh_meas_report_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define ch_request_desc_struct_size(x) 3
IMP unsigned int ch_request_desc_struct_bits(void *);
IMP void ch_request_desc_struct_alloc(void *);
IMP void ch_request_desc_struct_dealloc(void *);
IMP unsigned int ch_request_desc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ch_request_desc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ilevel_tn_struct_bits(void *);
IMP void ilevel_tn_struct_alloc(void *);
IMP void ilevel_tn_struct_dealloc(void *);
IMP unsigned int ilevel_tn_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ilevel_tn_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ch_quality_report_struct_bits(void *);
IMP void ch_quality_report_struct_alloc(void *);
IMP void ch_quality_report_struct_dealloc(void *);
IMP unsigned int ch_quality_report_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ch_quality_report_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pkt_dn_link_ack_nack_bits(void *);
IMP void pkt_dn_link_ack_nack_alloc(void *);
IMP void pkt_dn_link_ack_nack_dealloc(void *);
IMP unsigned int pkt_dn_link_ack_nack_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pkt_dn_link_ack_nack_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

/* Austin 040406: support PSI status */
IMP void pkt_psi_status_struct_alloc(void *);
IMP unsigned int pkt_psi_status_struct_pack(kal_uint8 *, void *, unsigned int);

#ifdef __REL4__  // chris, nacc_coding
IMP void pkt_cell_change_notification_struct_alloc(void *);
IMP unsigned int pkt_cell_change_notification_struct_pack(kal_uint8 *, void *, unsigned int);

/*Byron: Packet SI Status*/
IMP unsigned int pkt_si_status_struct_pack(kal_uint8 * frame, void * mtk_d,
            unsigned int bit_offset);
#endif

#endif 


