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
 *   ratdm_sndcp_struct.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 ******************************************************************************/

#ifndef RATDM_SNDCP_STRUCT_H
#define RATDM_SNDCP_STRUCT_H

// Poying: 20101005. RHR.
// ------------------------------ suggest Add ------------------------------
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
//
// Poying: 20101105. RHR
//------------------------------ suggest Add ------------------------------    
#include "kal_general_types.h"
#include "kal_public_defs.h" 

#ifndef _MCD_L3_INC_GPRS_STRUCT_H
#error "Please include mcd_l3_inc_grps_struct.h before ratdm_sndcp_struct.h"
#endif

typedef enum {
    RATDM_SND_SEND_FROM_OLDEST,  //0
    RATDM_SND_SEND_FROM_SN          // 1
} ratdm_sndcp_transmit_type_enum;

typedef struct {
    kal_uint8       nsapi;
    kal_uint8	   is_NwRxSeq_valid; //valid only when it is ACK mode
    kal_uint16     nw_rx_seq;  //this is derived from SGSN's Received NPDU number
    kal_uint8       ms_rx_seq;  //this is MS's Received NPDU number, need to be passed to network.
} nsapi_npdu_number_list;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8       nsapi;
    kal_uint16      npdu_number;
} ratdm_sndcp_data_req_struct, ratdm_sndcp_data_ind_struct, ratdm_sndcp_data_cnf_struct;


typedef struct {
    LOCAL_PARA_HDR
    kal_uint8       nsapi;
    qos_struct      qos_negotiated;
    kal_uint32      p_comp_algo;
    kal_uint32      d_comp_algo;
    kal_uint8       pdp_addr_type;
    kal_uint8       llc_sapi;
    kal_uint8       dl_pool_id; //flc2_pool_id_enum
    kal_uint8       radio_priority;
    kal_uint16      rcv_seq_no;
    kal_uint16      send_seq_no;
    kal_uint8       pfi;    //erica 20060719
    pdp_auxinfo_struct      aux_info; //erica 20070112
} ratdm_sndcp_activate_req_struct;


typedef struct {
    LOCAL_PARA_HDR
    kal_uint8       nsapi;
} ratdm_sndcp_activate_cnf_struct;


typedef struct {
    LOCAL_PARA_HDR
    kal_uint8       nsapi;
    qos_struct      qos_negotiated;
    kal_uint8       llc_sapi;
    kal_uint8       radio_priority;
    kal_uint8       pfi;  //erica 20060719
} ratdm_sndcp_modify_req_struct;


typedef struct {
    LOCAL_PARA_HDR
    kal_uint8       nsapi;
} ratdm_sndcp_modify_cnf_struct;    
  

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8       no_of_valid_entries;
    kal_uint8       nsapi_list[11];
    kal_uint32      cause;
    kal_bool        xid_neg_indicator[11];
} ratdm_sndcp_deactivate_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8       no_of_valid_entries;
    kal_uint8       nsapi_list[11];
} ratdm_sndcp_deactivate_cnf_struct;


typedef struct {
    LOCAL_PARA_HDR
    kal_uint8       nsapi;
    kal_uint8       cause; //llsnd_cause_enum
} ratdm_sndcp_status_ind_struct;

/* RATDM_RABM_SUSPEND_DATA_PLANE_IND */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8       no_of_valid_entries;
    kal_uint8       nsapi_list[11];
} ratdm_sndcp_suspend_data_plane_ind_struct;

/* RATDM_RABM_RESUME_DATA_PLANE_IND */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8       no_of_valid_entries;
    kal_uint8       nsapi_list[11];
    kal_uint16     RetransmitFromSN[11];    
} ratdm_sndcp_resume_data_plane_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 no_of_valid_entries;
    kal_uint8 nsapi_list[11];
    kal_uint16 sequence_list[11];
} ratdm_sndcp_sequence_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8       no_of_valid_entries;
    nsapi_npdu_number_list       nsapi_list[11];
} ratdm_sndcp_sequence_cnf_struct;

/*
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8       nsapi;
} ratcm_sndcp_flush_ind_struct;
*/

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8       nsapi;
    kal_bool        set_send_to_0;
    kal_bool        set_recv_to_0;
} ratdm_sndcp_flush_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8       nsapi;
    kal_bool        set_send_to_0;
    kal_bool        set_recv_to_0;
} ratdm_sndcp_reset_npdu_seq_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8                                nsapi;
    ratdm_sndcp_transmit_type_enum                type;
    kal_uint16                               seq_no;
} ratdm_sndcp_transmit_ind_struct;

/*
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8       nsapi;
    kal_uint16       ack_seq_no;
} ratcm_sndcp_retransmit_ind_struct;
*/

#endif /* RATDM_SNDCP_STRUCT_H */
