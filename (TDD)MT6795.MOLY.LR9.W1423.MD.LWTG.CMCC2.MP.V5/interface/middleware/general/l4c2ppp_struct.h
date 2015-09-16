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
 * L4C2PPP_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of TCM and PPP.
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

#ifndef _L4C2PPP_STRUCT_H
#define _L4C2PPP_STRUCT_H

#include "kal_general_types.h"
//#include "kal_non_specific_general_types.h"

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 context_id;
    kal_uint8 is_chap;
    kal_uint8 pdp_type;
    kal_uint8 port;
} l4cppp_activate_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id; 
    kal_uint8 src_id;
    kal_uint8 port;
    #ifdef __LOCAL_DEACTIVATE_PDP_SUPPORT__
    kal_bool local_deactivate_pdp; /* __LOCAL_DEACTIVATE_PDP_SUPPORT__ */
    #endif // ~ __LOCAL_DEACTIVATE_PDP_SUPPORT__
} l4cppp_deactivate_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 username[32];
    kal_uint8 password[32];
    kal_uint8 csd_mod_id;
    kal_uint8 default_pri_dns_addr[4]; /* __PPP_DEFAULT_DNS_SUPPORTED__  */
    kal_uint8 default_sec_dns_addr[4]; /* __PPP_DEFAULT_DNS_SUPPORTED__  */
} l4cppp_csd_activate_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;    
    kal_uint8 deact_cause;
} l4cppp_csd_deactivate_req_struct;

//mtk01616_080912
/* __GPRS_DIALUP_ESCAPE_ATO_SUPPORT__ */
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;    
    kal_uint8 port;
} l4cppp_resume_req_struct;
/* ~ __GPRS_DIALUP_ESCAPE_ATO_SUPPORT__ */

// PPP Type PDP Dialup Feature
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;    
    kal_uint8 src_id;
    kal_uint8 context_id;
    kal_uint8 port;
} l4cppp_ppptypepdp_uart_transfer_ind_struct;

//__IPV4V6__
typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;    
    //MUST be valid all the time --
    kal_uint8  activate_port;     //mtk02285, MAUI_03127025, IPV4V6 fallback: cid2 vs. ps_dialup_port[]    
    kal_bool   activate_next_pdp;
    //-- MUST be valid all the time

    //ONLY valid when activate_next_pdp==KAL_TRUE --
    kal_uint8  activate_pdp_cid;
    kal_uint8  activate_pdp_type;
    //-- ONLY valid when activate_next_pdp==KAL_TRUE    
} l4cppp_ipv4v6_fallback_rsp_struct;
#endif 


