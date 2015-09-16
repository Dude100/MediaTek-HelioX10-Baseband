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

/******************************************************************************
 * Filename:
 * ---------
 *	rmpc2mac_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *
 *=============================================================================
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================================
 ******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _RMPC2MAC_STRUCT_H
#define _RMPC2MAC_STRUCT_H

/*Evelyn: Remove redundant header and file */
#include "kal_general_types.h"
#include "rmc_peer_struct.h"
#include "rr_common_def.h"

typedef struct {
    kal_uint8 is_valid;
    kal_uint8 length_of_list;
    kal_uint16 freq_list[64];
} freq_alloc_list_struct;

typedef struct {
    kal_uint8 bit_offset;
    kal_uint8 no_ul_assign_ptr;
    kal_uint8 ul_assign_ptr_size;
    kal_uint8 *ul_assign_ptr;
} rmpc_mac_pkt_ul_assign_ind_struct;

typedef struct {
    pkt_chan_desc_struct pkt_ch_desc;
    timing_advance_struct timing_adv;
    freq_alloc_list_struct freq_alloc;
    kal_uint8 no_ia_rest_octs;
    kal_uint8 ia_rest_octs_size;
    kal_uint8 *ia_rest_octs;
} rmpc_mac_imm_pkt_ul_assign_ind_struct;

typedef struct {
    kal_uint8 before_time_valid;
    channel_desc_struct chan_desc_before_time;
    freq_alloc_list_struct freq_alloc_before_time;
    STARTING_TIME_STRUCT_1 start_time;
    channel_desc_struct chan_desc_after_time;
    freq_alloc_list_struct freq_alloc_after_time;
    kal_uint8 no_ul_asgn;
    kal_uint8 ul_asgn_size;
    kal_uint8 *ul_asgn;
} rmpc_mac_pdch_pkt_ul_assign_ind_struct;

typedef struct {
    kal_uint8 bit_offset;
    kal_uint8 no_dl_assign_ptr;
    kal_uint8 dl_assign_ptr_size;
    kal_uint8 *dl_assign_ptr;
} rmpc_mac_pkt_dl_assign_ind_struct;

typedef struct {
    pkt_chan_desc_struct pkt_ch_desc;
    timing_advance_struct timing_adv;
    freq_alloc_list_struct freq_alloc;
    kal_uint8 no_ia_rest_octs;
    kal_uint8 ia_rest_octs_size;
    kal_uint8 *ia_rest_octs;
} rmpc_mac_imm_pkt_dl_assign_ind_struct;

typedef struct {
    kal_uint8 before_time_valid;
    channel_desc_struct chan_desc_before_time;
    freq_alloc_list_struct freq_alloc_before_time;
    STARTING_TIME_STRUCT_1 start_time;
    channel_desc_struct chan_desc_after_time;
    freq_alloc_list_struct freq_alloc_after_time;
    kal_uint8 no_dl_asgn;
    kal_uint8 dl_asgn_size;
    kal_uint8 *dl_asgn;
} rmpc_mac_pdch_pkt_dl_assign_ind_struct;

// Evelyn : merge control message indication ro RMPC as mac_rmpc_ctrl_msg_ind
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
#endif

/* Exce 030827: Change interface; RES_REQ fowarded back to MAC is kept in the primitive itself */
typedef struct {
    LOCAL_PARA_HDR
    /* Evelyn 20090415: Merge R6 */
    // Evelyn MTBF: Change the packet access structure
    multiple_res_req_struct res_req_msg;     /* Exce 030827: Note that forwarded back RES_REQ in the primitve is ALWAYS valid */
    ts_frame_no_struct ts_frame_no;
    kal_uint8 access_type;
    pkt_assign_type_enum pkt_assign_type_tag;
    union {
        rmpc_mac_pkt_ul_assign_ind_struct pkt_ul_assign;
        rmpc_mac_imm_pkt_ul_assign_ind_struct imm_ul_assign;
        rmpc_mac_pdch_pkt_ul_assign_ind_struct pdch_ul_assign;
    } pkt_assign_type_value;
} rmpc_mac_ul_assign_ind_struct;

/* Exce 030827: Change interface; RES_REQ fowarded back to MAC is kept in the primitive itself, also remove unnecessary fields. */
typedef struct {
    LOCAL_PARA_HDR
//    kal_uint8 no_res_req_msg;
//    kal_uint8 res_req_msg_size;
    kal_bool is_res_req_msg_valid;
/* Evelyn 20090415: Merge R6 */
    multiple_res_req_struct res_req_msg;
    ts_frame_no_struct ts_frame_no;
    pkt_assign_type_enum pkt_assign_type_tag;
    union {
        rmpc_mac_pkt_dl_assign_ind_struct pkt_dl_assign;
        rmpc_mac_imm_pkt_dl_assign_ind_struct imm_dl_assign;
        rmpc_mac_pdch_pkt_dl_assign_ind_struct pdch_dl_assign;
    } pkt_assign_type_value;
} rmpc_mac_dl_assign_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 ready_flag;
    kal_uint8 conf_reqd;
    kal_uint8 no_rmpc_msg_ptr;
    kal_uint8 rmpc_msg_ptr_size;
    kal_uint8 *rmpc_msg_ptr;
} rmpc_mac_si_info_ready_ind_struct;

/* Lanslo 20051102: for MNT */
#if  (!defined(__MTK_TARGET__)) || defined(__MAC_SHOW_TRANS_DATA__)
typedef struct {
    LOCAL_PARA_HDR
    tbf_rel_type_enum rel_cause;
    kal_bool  is_for_rmpc_test;
} rmpc_mac_cell_status_ind_struct;
#endif

// Evelyn : merge control message indication ro RMPC as mac_rmpc_ctrl_msg_ind
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
#endif

/* Evelyn 20090415: Merge R6 */
typedef struct{
    LOCAL_PARA_HDR
    rmpc_mac_ctrl_msg_type_enum msg_type;
    kal_uint8* enc_data_ptr;
    kal_uint8 req_id;
} rmpc_mac_ctrl_msg_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    rmpc_mac_ctrl_msg_type_enum msg_type;
    kal_uint8 req_id;
} rmpc_mac_ctrl_msg_delete_req_struct;

#ifdef __PS_HO__

typedef enum{
    NON_SYNC,
    SYNC,
    PRE_SYNC
} ps_ho_type_enum;

typedef struct{
    kal_uint16 arfcn;
    kal_uint8 bsic;
    kal_bool timing_info_valid;
    kal_int32 frame_offset;
    kal_int32 ebit_offset;
    kal_int8 tx_pwr;
    kal_bool is_tx_pwr_pccch_valid;
    kal_int8 tx_pwr_pccch;
#ifdef __GERAN_R6__ 
    kal_bool LB_valid;
    kal_int8 tx_pwr_LB;
#endif /*__GERAN_R6__ */
} target_cell_info_struct;

typedef struct{
    LOCAL_PARA_HDR
    ps_ho_dir_enum ps_ho_dir;
    #ifndef __MTK_TARGET__
    kal_uint8 mac_msg_ptr_size;
    kal_uint8* mac_msg_ptr;
    #endif
#ifdef __UMTS_R6__ 
    ps_ho_utran_status_enum utran_status;
#endif
    target_cell_info_struct target_cell;
} rmpc_mac_ps_handover_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    ps_ho_error_rsp_enum error_type;
} rmpc_mac_ps_handover_error_rsp_struct;

#endif /* end of __PS_HO__ */

typedef enum {
    SERV_SI_PTR,
    PS_HO_BEGIN_TARGET_CELL_SI_PTR,
    PS_HO_FAIL_OLD_SERV_SI_PTR
} mac_si_ptr_query_type_enum;

#endif
