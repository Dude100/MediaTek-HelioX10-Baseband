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
 * PPP2L4C_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of TCM and L4C.
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

#ifndef _PPP2L4C_STRUCT_H
#define _PPP2L4C_STRUCT_H

#include "kal_general_types.h"
//#include "kal_non_specific_general_types.h"
#include "kal_public_defs.h"

typedef struct {
    /* Warning::
      * If result is PPPE_RESULT_FAILED, then only port and cause are valid in this struct
      * else if the result is success, then src_id,context_id, pdp_type, port, and cause are all valid value in this struct
      */
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 context_id; // PH 20050223 MPDP
    kal_uint8 result; /* success or failed*/
    kal_uint8 pdp_type;
    kal_uint8 port;
    kal_uint8 cause; /* abnormal case */
#ifdef __IPV4V6__    
    kal_uint8 context_id2; //L4CPPP_FB_2, if it does not exist, fill with INVALID_PDP_CONTEXT_ID
    kal_uint8 pdp_type2;   //L4CPPP_FB_2, if it does not exist, fill with NULL PDP type
#endif    
} l4cppp_activate_cnf_struct; 

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 context_id; // PH 20050223 MPDP
    kal_uint8 port;
    kal_uint8 result;
    kal_uint8 cause; /* abnormal case */
#ifdef __IPV4V6__        
    kal_uint8 context_id2; //L4CPPP_FB_2, if it does not exist, fill with INVALID_PDP_CONTEXT_ID    
#endif    
} l4cppp_deactivate_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 context_id; // PH 20050223 MPDP
    kal_uint8 port;
    kal_uint8 cause; /* abnormal case */
#ifdef __IPV4V6__        
    kal_uint8 context_id2; //L4CPPP_FB_2, if it does not exist, fill with INVALID_PDP_CONTEXT_ID    
#endif    
} l4cppp_deactivate_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result; /* success or failed*/
    kal_uint8 port;
} l4cppp_resume_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 result; /* success or failed*/
    kal_uint8 err_cause;   
    kal_uint8 ip_addr[4];
    kal_uint8 pri_dns_addr[4];
    kal_uint8 sec_dns_addr[4];
    kal_uint16 mtu;
} l4cppp_csd_activate_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 result; /* success or failed*/
    kal_uint8 err_cause;
} l4cppp_csd_deactivate_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 port;
} l4cppp_escape_ind_struct;

typedef struct {
    kal_uint16  id;
    kal_uint32  time_stamp;
    kal_uint32  time_100us;
    kal_uint16  frame_size;
    kal_uint16  data_size;
} frame_statistic_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 direction;
    frame_statistic_struct statistic[10];
    kal_uint32 time_in_ms;
} ppp_status_report_ind_struct;

// PPP Type PDP Dialup Feature
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 context_id;
    kal_uint8 port;
    kal_uint8 result; // success or fail
} l4cppp_ppptypepdp_activated_ind_struct;

//__IPV4V6__
typedef struct {
    LOCAL_PARA_HDR
    kal_bool   pdp_activate_rsp_accept;     // accept or reject
    kal_uint8  pdp_activate_rsp_pdp_type;   // IPV4V6, IPV4, IPV6 --> only need when accept
    kal_uint8  pdp_activate_rsp_cid;        // 1, 2, 3
    kal_uint16 pdp_activate_cause;          // only for reject
    kal_bool   pdp_activate_cause2_present; // only for accept
    kal_uint16 pdp_activate_cause2;         // only for accept
} l4cppp_ipv4v6_fallback_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8  src_id;
    kal_uint8  context_id;
    kal_uint8  pdp_type;
} l4cppp_initial_ip_type_ind_struct; //L4CPPP_FB
#endif 


