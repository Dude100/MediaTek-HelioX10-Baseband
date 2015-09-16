/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 * l4c_ratdm_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct between L4C and RATDM
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

#ifndef _L4C_RATDM_STRUCT_H
#define _L4C_RATDM_STRUCT_H

#include "kal_general_types.h"
#include "ps_public_enum.h"

    
/* basic structures for gprs dialup call log */

typedef struct {  
    kal_uint64 tx;
    kal_uint64 rx;    
    kal_uint8 context_id;    
} single_pdp_call_history_info_struct;

typedef struct {
    kal_uint8 context_id;
    kal_bool reset_tx;
    kal_bool reset_rx;
} single_pdp_call_history_reset_cmd_struct;

typedef struct {
    single_pdp_call_history_reset_cmd_struct original_cmd;
    single_pdp_call_history_info_struct volume_before_reset;
} single_pdp_call_history_reset_result_struct;



/* local param structures for L4C/RATDM SAP */

typedef struct {
    kal_uint8 ref_count;
	kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 serial_num;
    kal_uint8 total_context_id;
    kal_uint8 context_id[MAX_GPRS_DIALUP_NUM];
} l4c_ps_query_ext_pdp_statistics_req_struct;

typedef struct {
    kal_uint8 ref_count;
	kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 serial_num;
    kal_uint8 total_context_id;
    single_pdp_call_history_info_struct query_result[MAX_GPRS_DIALUP_NUM];
} l4c_ps_query_ext_pdp_statistics_rsp_struct;

typedef struct {
    kal_uint8 ref_count;
	kal_uint16 msg_len;
    kal_uint8 src_id;    
    kal_uint8 serial_num;
    kal_uint8 total_reset_num;
    single_pdp_call_history_reset_cmd_struct reset_cmd[MAX_GPRS_DIALUP_NUM];
} l4c_ps_reset_ext_pdp_statistics_req_struct;

typedef struct {
    kal_uint8 ref_count;
	kal_uint16 msg_len;
    kal_uint8 src_id;    
    kal_uint8 serial_num;
    kal_uint8 total_reset_num;
    single_pdp_call_history_reset_result_struct result[MAX_GPRS_DIALUP_NUM];
} l4c_ps_reset_ext_pdp_statistics_rsp_struct;

typedef struct {
    kal_uint8 ref_count;
	kal_uint16 msg_len;
    kal_uint8 total_context_id;
    single_pdp_call_history_info_struct result[MAX_GPRS_DIALUP_NUM];
} l4c_ps_ext_pdp_statistics_ind_struct;

typedef struct {
    kal_uint8 ref_count;
	kal_uint16 msg_len;
    kal_uint8 context_id;
} l4c_ratdm_packets_flush_ind_struct;

#endif /* _L4C_RATDM_STRUCT_H */

