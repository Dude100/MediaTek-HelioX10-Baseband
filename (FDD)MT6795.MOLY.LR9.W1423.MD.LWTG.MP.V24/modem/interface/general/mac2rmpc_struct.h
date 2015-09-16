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
 *	max2rmpc_struct.h
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

#ifndef _MAC2RMPC_STRUCT_H
#define _MAC2RMPC_STRUCT_H

/* add RHR */
#include "rr_common_def.h"
#include "rr2mpal_struct.h"
#include "mac_context.h"

/* Evelyn 20090415: Merge R6 */
// Evelyn MTBF: Change the packet access structure
typedef struct multiple_res_req_struct mac_rmpc_pkt_access_req_struct;

typedef struct {
    kal_uint32 starting_frame;
    kal_uint8 measurement_interval;
    kal_uint8 measurement_bit_map;
} measurement_map_struct;

#if 0
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
    LOCAL_PARA_HDR
    kal_uint8 type;
    kal_uint8 cause;
} mac_rmpc_access_result_ind_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* Adeline: Relpace cs paging, PCCO, PMO, PCCC, PSCD, PNCD, PSCSI */
typedef struct {
    LOCAL_PARA_HDR
    mac_rmpc_ctrl_msg_type_enum msg_type;
    mac_state_enum mac_state;
    kal_uint8 no_ctrl_blk;
    kal_uint8 ctrl_blk_size;
    kal_uint8 *ctrl_blk;
    kal_uint8 bit_offset;
} mac_rmpc_ctrl_msg_ind_struct;


typedef struct {
    LOCAL_PARA_HDR
    tbf_rel_type_enum rel_type;
    kal_uint8 mac_state;
} mac_rmpc_enter_idle_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    measurement_map_struct measurement_map;
} mac_rmpc_meas_map_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint16 fn_offset;
    kal_uint8 type;
    kal_uint8 cause;
} mac_rmpc_dl_assign_result_ind_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 mac_state;
} mac_rmpc_suspend_done_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 is_tbf_exist;
    freq_params_struct *freq_params_ptr;
} mac_rmpc_tbf_status_ind_struct;


#if 0
#ifdef __REL4__
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
#endif


/* Evelyn 20090415: Merge R6 */
typedef struct {
    LOCAL_PARA_HDR
    rmpc_mac_ctrl_msg_type_enum msg_type;
    result_type_enum result;
    kal_uint8 req_id;
} mac_rmpc_ctrl_msg_cnf_struct;

#ifdef __PS_HO__

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 mac_msg_ptr_size;
    kal_uint8* mac_msg_ptr;
} mac_rmpc_ps_handover_msg_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    target_cell_timing_struct target_cell_timing;
} mac_rmpc_ps_handover_connect_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    ps_ho_result_enum ps_ho_result;
    ps_ho_failure_cause_enum failure_cause;
    gprs_mac_state_enum mac_state;
    tbf_rel_type_enum rel_type;
} mac_rmpc_ps_handover_result_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
} mac_rmpc_ps_handover_reconnect_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    gprs_mac_state_enum mac_state;
    tbf_rel_type_enum rel_type;
} mac_rmpc_ps_handover_error_rsp_struct;


#endif /* end of __PS_HO__*/

#ifdef __ETWS_SUPPORT__
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 mac_msg_ptr_size;
    kal_uint8 bit_offset;    
    kal_uint8* mac_msg_ptr;
} mac_rmpc_packet_application_info_msg_ind_struct;
#endif /* __ETWS_SUPPORT__ */


#endif


