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
 *  si_peer_pun.h
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
 *  FILENAME : si_peer_pun.h
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
#ifndef _SI_PEER_PUN_H
#define _SI_PEER_PUN_H

#define ctrl_chan_desc_struct_size(x) 3
IMP unsigned int ctrl_chan_desc_struct_bits(void *);
IMP void ctrl_chan_desc_struct_alloc(void *);
IMP void ctrl_chan_desc_struct_dealloc(void *);
IMP unsigned int ctrl_chan_desc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ctrl_chan_desc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define celloptions_size(x) 1
IMP unsigned int celloptions_bits(void *);
IMP void celloptions_alloc(void *);
IMP void celloptions_dealloc(void *);
IMP unsigned int celloptions_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int celloptions_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define cellselectionparams_size(x) 2
IMP unsigned int cellselectionparams_bits(void *);
IMP void cellselectionparams_alloc(void *);
IMP void cellselectionparams_dealloc(void *);
IMP unsigned int cellselectionparams_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int cellselectionparams_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define rachparams_size(x) 3
IMP unsigned int rachparams_bits(void *);
IMP void rachparams_alloc(void *);
IMP void rachparams_dealloc(void *);
IMP unsigned int rachparams_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rachparams_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si1restoct_bits(void *);
IMP void si1restoct_alloc(void *);
IMP void si1restoct_dealloc(void *);
IMP unsigned int si1restoct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si1restoct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define selectionparams_size(x) 2
IMP unsigned int selectionparams_bits(void *);
IMP void selectionparams_alloc(void *);
IMP void selectionparams_dealloc(void *);
IMP unsigned int selectionparams_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int selectionparams_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define pwroffset_size(x) 1
IMP unsigned int pwroffset_bits(void *);
IMP void pwroffset_alloc(void *);
IMP void pwroffset_dealloc(void *);
IMP unsigned int pwroffset_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pwroffset_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define gprsind_size(x) 1
IMP unsigned int gprsind_bits(void *);
IMP void gprsind_alloc(void *);
IMP void gprsind_dealloc(void *);
IMP unsigned int gprsind_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gprsind_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_3_rest_octet_struct_bits(void *);
IMP void si_3_rest_octet_struct_alloc(void *);
IMP void si_3_rest_octet_struct_dealloc(void *);
IMP unsigned int si_3_rest_octet_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_3_rest_octet_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int lsa_identity_struct_bits(void *);
IMP void lsa_identity_struct_alloc(void *);
IMP void lsa_identity_struct_dealloc(void *);
IMP unsigned int lsa_identity_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int lsa_identity_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int lsa_id_info_struct_bits(void *);
IMP void lsa_id_info_struct_alloc(void *);
IMP void lsa_id_info_struct_dealloc(void *);
IMP unsigned int lsa_id_info_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int lsa_id_info_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define mcc_mnc_struct_size(x) 3
IMP unsigned int mcc_mnc_struct_bits(void *);
IMP void mcc_mnc_struct_alloc(void *);
IMP void mcc_mnc_struct_dealloc(void *);
IMP unsigned int mcc_mnc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int mcc_mnc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int lsa_params_struct_bits(void *);
IMP void lsa_params_struct_alloc(void *);
IMP void lsa_params_struct_dealloc(void *);
IMP unsigned int lsa_params_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int lsa_params_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_4_rest_octet_s_struct_bits(void *);
IMP void si_4_rest_octet_s_struct_alloc(void *);
IMP void si_4_rest_octet_s_struct_dealloc(void *);
IMP unsigned int si_4_rest_octet_s_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_4_rest_octet_s_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si4restoct_bits(void *);
IMP void si4restoct_alloc(void *);
IMP void si4restoct_dealloc(void *);
IMP unsigned int si4restoct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si4restoct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define maio_size(x) 2
IMP unsigned int maio_bits(void *);
IMP void maio_alloc(void *);
IMP void maio_dealloc(void *);
IMP unsigned int maio_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int maio_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define arfcn_choice_size(x) 2
IMP unsigned int arfcn_choice_bits(void *);
IMP void arfcn_choice_alloc(void *);
IMP void arfcn_choice_dealloc(void *);
IMP unsigned int arfcn_choice_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int arfcn_choice_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int channeldesc_bits(void *);
IMP void channeldesc_alloc(void *);
IMP void channeldesc_dealloc(void *);
IMP unsigned int channeldesc_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int channeldesc_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define pchinf_size(x) 1
IMP unsigned int pchinf_bits(void *);
IMP void pchinf_alloc(void *);
IMP void pchinf_dealloc(void *);
IMP unsigned int pchinf_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pchinf_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si6restoct_bits(void *);
IMP void si6restoct_alloc(void *);
IMP void si6restoct_dealloc(void *);
IMP unsigned int si6restoct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si6restoct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rfl_number_struct_bits(void *);
IMP void rfl_number_struct_alloc(void *);
IMP void rfl_number_struct_dealloc(void *);
IMP unsigned int rfl_number_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rfl_number_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int rfl_number_list_struct_bits(void *);
IMP void rfl_number_list_struct_alloc(void *);
IMP void rfl_number_list_struct_dealloc(void *);
IMP unsigned int rfl_number_list_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rfl_number_list_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ma_struct_bits(void *);
IMP void ma_struct_alloc(void *);
IMP void ma_struct_dealloc(void *);
IMP unsigned int ma_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ma_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int arfcn_index_list1_struct_bits(void *);
IMP void arfcn_index_list1_struct_alloc(void *);
IMP void arfcn_index_list1_struct_dealloc(void *);
IMP unsigned int arfcn_index_list1_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int arfcn_index_list1_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_arfcn_index_list_struct_bits(void *);
IMP void si_arfcn_index_list_struct_alloc(void *);
IMP void si_arfcn_index_list_struct_dealloc(void *);
IMP unsigned int si_arfcn_index_list_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_arfcn_index_list_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int gprsmoballocstruct_bits(void *);
IMP void gprsmoballocstruct_alloc(void *);
IMP void gprsmoballocstruct_dealloc(void *);
IMP unsigned int gprsmoballocstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gprsmoballocstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int sinonhopppbcchcarr_bits(void *);
IMP void sinonhopppbcchcarr_alloc(void *);
IMP void sinonhopppbcchcarr_dealloc(void *);
IMP unsigned int sinonhopppbcchcarr_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int sinonhopppbcchcarr_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int sibcchcarstruct_bits(void *);
IMP void sibcchcarstruct_alloc(void *);
IMP void sibcchcarstruct_dealloc(void *);
IMP unsigned int sibcchcarstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int sibcchcarstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int sipbcchdescstruct_bits(void *);
IMP void sipbcchdescstruct_alloc(void *);
IMP void sipbcchdescstruct_dealloc(void *);
IMP unsigned int sipbcchdescstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int sipbcchdescstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int sippbcchstruct_bits(void *);
IMP void sippbcchstruct_alloc(void *);
IMP void sippbcchstruct_dealloc(void *);
IMP unsigned int sippbcchstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int sippbcchstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si13restoct_bits(void *);
IMP void si13restoct_alloc(void *);
IMP void si13restoct_dealloc(void *);
IMP unsigned int si13restoct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si13restoct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define CELL_CH_DESC_BITMAP0_size(x) 16
IMP unsigned int CELL_CH_DESC_BITMAP0_bits(void *);
IMP void CELL_CH_DESC_BITMAP0_alloc(void *);
IMP void CELL_CH_DESC_BITMAP0_dealloc(void *);
IMP unsigned int CELL_CH_DESC_BITMAP0_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int CELL_CH_DESC_BITMAP0_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define nch_position_struct_size(x) 1
IMP unsigned int nch_position_struct_bits(void *);
IMP void nch_position_struct_alloc(void *);
IMP void nch_position_struct_dealloc(void *);
IMP unsigned int nch_position_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int nch_position_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_1_rest_octet_struct_bits(void *);
IMP void si_1_rest_octet_struct_alloc(void *);
IMP void si_1_rest_octet_struct_dealloc(void *);
IMP unsigned int si_1_rest_octet_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_1_rest_octet_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_1_struct_bits(void *);
IMP void si_1_struct_alloc(void *);
IMP void si_1_struct_dealloc(void *);
IMP unsigned int si_1_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_1_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define neigh_cells_desc1_struct_size(x) 16
IMP unsigned int neigh_cells_desc1_struct_bits(void *);
IMP void neigh_cells_desc1_struct_alloc(void *);
IMP void neigh_cells_desc1_struct_dealloc(void *);
IMP unsigned int neigh_cells_desc1_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int neigh_cells_desc1_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define neigh_cells_desc2_struct_size(x) 16
IMP unsigned int neigh_cells_desc2_struct_bits(void *);
IMP void neigh_cells_desc2_struct_alloc(void *);
IMP void neigh_cells_desc2_struct_dealloc(void *);
IMP unsigned int neigh_cells_desc2_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int neigh_cells_desc2_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define si_2_struct_size(x) 23
IMP unsigned int si_2_struct_bits(void *);
IMP void si_2_struct_alloc(void *);
IMP void si_2_struct_dealloc(void *);
IMP unsigned int si_2_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_2_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define si_2bis_rest_octets_struct_size(x) 1
IMP unsigned int si_2bis_rest_octets_struct_bits(void *);
IMP void si_2bis_rest_octets_struct_alloc(void *);
IMP void si_2bis_rest_octets_struct_dealloc(void *);
IMP unsigned int si_2bis_rest_octets_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_2bis_rest_octets_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define si_2bis_struct_size(x) 23
IMP unsigned int si_2bis_struct_bits(void *);
IMP void si_2bis_struct_alloc(void *);
IMP void si_2bis_struct_dealloc(void *);
IMP unsigned int si_2bis_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_2bis_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define si_2ter_rest_octets_struct_size(x) 4
IMP unsigned int si_2ter_rest_octets_struct_bits(void *);
IMP void si_2ter_rest_octets_struct_alloc(void *);
IMP void si_2ter_rest_octets_struct_dealloc(void *);
IMP unsigned int si_2ter_rest_octets_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_2ter_rest_octets_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define si_2ter_struct_size(x) 23
IMP unsigned int si_2ter_struct_bits(void *);
IMP void si_2ter_struct_alloc(void *);
IMP void si_2ter_struct_dealloc(void *);
IMP unsigned int si_2ter_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_2ter_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define si_2quater_rest_octets_struct_size(x) 20
IMP unsigned int si_2quater_rest_octets_struct_bits(void *);
IMP void si_2quater_rest_octets_struct_alloc(void *);
IMP void si_2quater_rest_octets_struct_dealloc(void *);
IMP unsigned int si_2quater_rest_octets_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_2quater_rest_octets_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define si_2quater_struct_size(x) 23
IMP unsigned int si_2quater_struct_bits(void *);
IMP void si_2quater_struct_alloc(void *);
IMP void si_2quater_struct_dealloc(void *);
IMP unsigned int si_2quater_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_2quater_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define PLMN_size(x) 3
IMP unsigned int PLMN_bits(void *);
IMP void PLMN_alloc(void *);
IMP void PLMN_dealloc(void *);
IMP unsigned int PLMN_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int PLMN_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define LAI_size(x) 5
IMP unsigned int LAI_bits(void *);
IMP void LAI_alloc(void *);
IMP void LAI_dealloc(void *);
IMP unsigned int LAI_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int LAI_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_3_struct_bits(void *);
IMP void si_3_struct_alloc(void *);
IMP void si_3_struct_dealloc(void *);
IMP unsigned int si_3_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_3_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define si_4_part1of4_struct_size(x) 13
IMP unsigned int si_4_part1of4_struct_bits(void *);
IMP void si_4_part1of4_struct_alloc(void *);
IMP void si_4_part1of4_struct_dealloc(void *);
IMP unsigned int si_4_part1of4_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_4_part1of4_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_4_part2of4_struct_bits(void *);
IMP void si_4_part2of4_struct_alloc(void *);
IMP void si_4_part2of4_struct_dealloc(void *);
IMP unsigned int si_4_part2of4_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_4_part2of4_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_4_part3of4_struct_bits(void *);
IMP void si_4_part3of4_struct_alloc(void *);
IMP void si_4_part3of4_struct_dealloc(void *);
IMP unsigned int si_4_part3of4_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_4_part3of4_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_4_part4of4_struct_bits(void *);
IMP void si_4_part4of4_struct_alloc(void *);
IMP void si_4_part4of4_struct_dealloc(void *);
IMP unsigned int si_4_part4of4_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_4_part4of4_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_4_struct_bits(void *);
IMP void si_4_struct_alloc(void *);
IMP void si_4_struct_dealloc(void *);
IMP unsigned int si_4_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_4_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define si_5_struct_size(x) 19
IMP unsigned int si_5_struct_bits(void *);
IMP void si_5_struct_alloc(void *);
IMP void si_5_struct_dealloc(void *);
IMP unsigned int si_5_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_5_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define si_5bis_struct_size(x) 19
IMP unsigned int si_5bis_struct_bits(void *);
IMP void si_5bis_struct_alloc(void *);
IMP void si_5bis_struct_dealloc(void *);
IMP unsigned int si_5bis_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_5bis_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define si_5ter_struct_size(x) 19
IMP unsigned int si_5ter_struct_bits(void *);
IMP void si_5ter_struct_alloc(void *);
IMP void si_5ter_struct_dealloc(void *);
IMP unsigned int si_5ter_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_5ter_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_6_struct_bits(void *);
IMP void si_6_struct_alloc(void *);
IMP void si_6_struct_dealloc(void *);
IMP unsigned int si_6_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_6_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_7_struct_bits(void *);
IMP void si_7_struct_alloc(void *);
IMP void si_7_struct_dealloc(void *);
IMP unsigned int si_7_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_7_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_8_struct_bits(void *);
IMP void si_8_struct_alloc(void *);
IMP void si_8_struct_dealloc(void *);
IMP unsigned int si_8_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_8_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define si_9_part1of2_struct_size(x) 6
IMP unsigned int si_9_part1of2_struct_bits(void *);
IMP void si_9_part1of2_struct_alloc(void *);
IMP void si_9_part1of2_struct_dealloc(void *);
IMP unsigned int si_9_part1of2_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_9_part1of2_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_13_struct_bits(void *);
IMP void si_13_struct_alloc(void *);
IMP void si_13_struct_dealloc(void *);
IMP unsigned int si_13_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_13_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_16_struct_bits(void *);
IMP void si_16_struct_alloc(void *);
IMP void si_16_struct_dealloc(void *);
IMP unsigned int si_16_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_16_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_17_struct_bits(void *);
IMP void si_17_struct_alloc(void *);
IMP void si_17_struct_dealloc(void *);
IMP unsigned int si_17_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_17_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_non_gsm_msg_struct_bits(void *);
IMP void si_non_gsm_msg_struct_alloc(void *);
IMP void si_non_gsm_msg_struct_dealloc(void *);
IMP unsigned int si_non_gsm_msg_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_non_gsm_msg_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int SI18_REST_OCTETS_bits(void *);
IMP void SI18_REST_OCTETS_alloc(void *);
IMP void SI18_REST_OCTETS_dealloc(void *);
IMP unsigned int SI18_REST_OCTETS_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int SI18_REST_OCTETS_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_18_struct_bits(void *);
IMP void si_18_struct_alloc(void *);
IMP void si_18_struct_dealloc(void *);
IMP unsigned int si_18_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_18_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define SI_19_REST_OCTETS_size(x) 20
IMP unsigned int SI_19_REST_OCTETS_bits(void *);
IMP void SI_19_REST_OCTETS_alloc(void *);
IMP void SI_19_REST_OCTETS_dealloc(void *);
IMP unsigned int SI_19_REST_OCTETS_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int SI_19_REST_OCTETS_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define si_19_struct_size(x) 23
IMP unsigned int si_19_struct_bits(void *);
IMP void si_19_struct_alloc(void *);
IMP void si_19_struct_dealloc(void *);
IMP unsigned int si_19_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_19_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_20_struct_bits(void *);
IMP void si_20_struct_alloc(void *);
IMP void si_20_struct_dealloc(void *);
IMP unsigned int si_20_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_20_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#endif 


