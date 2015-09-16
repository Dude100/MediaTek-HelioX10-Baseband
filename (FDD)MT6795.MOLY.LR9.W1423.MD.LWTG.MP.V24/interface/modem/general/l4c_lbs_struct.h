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
 *	l4c_lbs_struct.h
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *   This file is intends for ...
 *
 * Author:
 * -------
 * -------
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



#ifndef _L4C_LBS_STRUCT_H
#define _L4C_LBS_STRUCT_H

#include "kal_general_types.h"
#if defined(__AGPS_CONTROL_PLANE__) && !defined(__MMI_FMI__)
#include "ss_asn.h"
#endif

/* A-GPS Control Plane LCS Service */
#if defined(__AGPS_CONTROL_PLANE__) && !defined(__MMI_FMI__)
typedef struct
{
	LOCAL_PARA_HDR
	SS2_LocationNotificationArg	notification;
	kal_uint8	ss_id;
} lbs_mtlr_begin_ind_struct;
typedef struct
{
	LOCAL_PARA_HDR
	SS2_LocationNotificationRes	response;
	kal_uint8	ss_id;
} lbs_mtlr_begin_res_req_struct;
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8	result;
	kal_uint8	ss_id;
} lbs_mtlr_begin_res_rsp_struct;
typedef struct
{
	LOCAL_PARA_HDR
	SS2_LCS_AreaEventRequestArg	aerq;
	kal_uint8	ss_id;
} lbs_aerq_begin_ind_struct;
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8	cause;
	kal_uint8	ss_id;
} lbs_aerq_begin_res_req_struct;
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8	result;
	kal_uint8	ss_id;
} lbs_aerq_begin_res_rsp_struct;
typedef struct
{
    LOCAL_PARA_HDR
    SS2_LCS_AreaEventReportArg	aerp;
    kal_uint8	ss_id;
    kal_uint8	is_initial;
    kal_uint8   rat_info; //for CISS to recognize the operating rat: 0:2/3G, 1:4G
} lbs_aerp_begin_req_struct;
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8	result;
	kal_uint16	cause;
	kal_uint8	ss_id;
} lbs_aerp_begin_rsp_struct;
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8	cause;
	kal_uint8	ss_id;
} lbs_aerp_end_req_struct;
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8	result;
} lbs_aerp_end_rsp_struct;
typedef struct
{
	LOCAL_PARA_HDR
	SS2_LCS_AreaEventCancellationArg	aecl;
	kal_uint8	ss_id;
} lbs_aecl_begin_ind_struct;
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8	cause;
	kal_uint8	ss_id;
} lbs_aecl_begin_res_req_struct;
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8	result;
	kal_uint8	ss_id;
} lbs_aecl_begin_res_rsp_struct;
typedef struct
{
    LOCAL_PARA_HDR
    SS2_LCS_MOLRArg molr;
    kal_uint8	ss_id;
    kal_uint8	is_initial;
    kal_uint8   rat_info; //for CISS to recognize the operating rat: 0:2/3G, 1:4G
} lbs_molr_begin_req_struct;
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8	result;
	kal_uint16	cause;
	SS2_LCS_MOLRRes	molr_res;
	kal_uint8	ss_id;
} lbs_molr_begin_rsp_struct;
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8	cause;
	kal_uint8	ss_id;
} lbs_molr_end_req_struct;
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8	result;
} lbs_molr_end_rsp_struct;
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8	enable;
} agps_enable_disable_req_struct;
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8	sib15_current_deciphering_key[7];
	kal_uint8	sib15_next_deciphering_key[7];
	kal_uint8	sib15_ciphering_key_flag;
} agps_key_update_req_struct;
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8	is_abort_molr;
} agps_cp_abort_req_struct;
#endif /* defined(__AGPS_CONTROL_PLANE__) */

#ifdef __AGPS_SUPPORT__
/* below codes are for auto-test */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
} agps_auto_test_ind_struct;

typedef agps_auto_test_ind_struct agps_cp_up_status_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 response;
} agps_mtlr_response_ind_struct;
/* above are for GPS auto test */
#endif

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 state;//0=out of service  1=in service
} l4c_lbs_service_state_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 state;//0=local or unknown  1=roaming
} l4c_lbs_roaming_state_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 state;//0=disconnected or unknown  1=connected
} l4c_lbs_data_conn_state_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 rat_mode;//0=non-4G , 1=4G
} l4c_lbs_current_rat_rsp_struct;

#endif /* l4c_lbs_struct.h*/


