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
/*****************************************************************************
 *
 * Filename:
 * ---------
 * l2r2rlp_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for L2R to RLP interface.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

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
 *  FILENAME : l2r2rlp_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _L2R2RLP_STRUCT_H
#define _L2R2RLP_STRUCT_H

#include "data_xid_struct.h"

#include "kal_general_types.h"
#include "kal_public_defs.h"

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 rat;
    kal_uint8 user_rate;
    kal_uint8 is_FR;
} l2r_rlp_attach_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 is_successful;
} l2r_rlp_conn_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 is_successful;
} l2r_rlp_conn_resp_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 c_or_r; /* command or resp*/
    xid_params_struct xid_params;
} l2r_rlp_xid_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 c_or_r; /* command or resp*/
    xid_params_struct xid_params;
} l2r_rlp_xid_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 error_cause;
} l2r_rlp_error_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 is_successful;
} l2r_rlp_reset_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 num_of_frames_allowed;
} l2r_rlp_ready_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 is_next_followed;
} l2r_rlp_data_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 user_rate;
    kal_uint8 rat;
} l2r_rlp_change_rate_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 rat;
    kal_uint8 user_rate;
    kal_uint16 num_of_frames; /* no of frames to be remapped*/
} l2r_rlp_remap_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 is_successful;
} l2r_rlp_test_cnf_struct;

/* For UT environment. */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 dtx_allow;
    kal_uint8 rat;
    kal_uint8 user_rate;
    kal_uint8 is_FR;
    kal_uint8 tick_rate;
    kal_uint8 byte_cnt;
} csd_uplink_tick_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8  port;
    kal_uint16 byte_cnt;
} csd_uart_ready_to_read_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8  port;
} csd_uart_ready_to_write_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8  port;
} csd_uart_full_ind_struct;

#endif 


