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
 *
 * Filename:
 * ---------
 *	csmss_context.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for define global context in CSM(SS) module.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#ifndef _CSMSS_CONTEXT_H
#define _CSMSS_CONTEXT_H

/* auto add by kw_check begin */
//#include "kal_non_specific_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "csmss_common_enums.h"
//#include "l4c_common_enum.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_general_types.h"
#include "mcd_l4_common.h"
/* auto add by kw_check end */
#include "global_def.h"

//MAUI_02857408, [AGPS][UP CP conflict] Support Parallel SS
//#define MMI_CS_MAX_CALLS                    1
#define MMI_CS_MAX_CALLS                    14 // MO + MT
//#define __CSMSS_CISS_USSD_SUPPORT_PARALLEL__
#define __CSMSS_AGPS_SUPPORT_PARALLEL__

//MAUI_03010164, [Call setting]The time shows incorrectly when divert if no answer
//MCD buffer size is changed to fit spec. Therefore, the end value(0xff) is in excess of MCD buffer size.
/*
According to ASN definition:
maxAddressLength                   INTEGER ::= 20
maxISDN-SubaddressLength     INTEGER ::= 21
maxISDN-AddressLength          INTEGER ::= 9
*/
#define CSMSS_MAX_FTN_NUM 22

#if defined(__GEMINI__) || defined(__SGLTE__)
#define CSMSS_SIM_ID  (csmss_cur_mod-MOD_CSM)
#else
#define CSMSS_SIM_ID 
#endif

typedef struct csm_ciss_context_struct
{
    kal_uint8 ti;
    kal_uint32 invoke_id;
    kal_uint8 op_code;
    kal_uint8 ss_code;
    msg_type msg_id;
    kal_uint8 src_id; //MAUI_01988887
    csmss_state_enum state;
    kal_uint8 bs_code;
#if defined(__SS_ERASURE_BEFORE_REGISTER__) || (defined(__REL4__) && defined(__CFU_FTN_IN_EFCFIS__))
    l4_addr_bcd_struct address;  // to hold Call Forwarding FTN given by L4C
#endif
#if defined(__SS_ERASURE_BEFORE_REGISTER__)
    kal_uint8 no_reply_timer;
#endif
} csm_ciss_context_struct;

typedef enum
{
    CLEAR_CFU, SET_CFU
} cfu_flag_nvram_action_enum;

typedef enum
{
    HIDE_CFU, SHOW_CFU
} cfu_flag_mmi_action_enum;

typedef enum
{
    ALS_LINE1, ALS_LINE2
} als_line_id_enum;


extern csm_ciss_context_struct csmss_g_ciss_tab[MMI_CS_MAX_CALLS];
extern kal_uint8 csmss_g_old_pw[4];
extern kal_uint8 csmss_g_new_pw1[4];
extern kal_uint8 csmss_g_new_pw2[4];
extern kal_uint8 csmss_g_call_id_pool[MMI_CS_MAX_CALLS];
//MAUI_02857408, [AGPS][UP CP conflict] Support Parallel SS
extern kal_uint8 csmss_g_ss_id_pool[MMI_CS_MAX_CALLS];
extern kal_uint8 csmss_g_src_id;
extern kal_uint8 csmss_g_call_id;
extern kal_uint8 *csmss_g_ussd_string;
extern kal_uint8 *csmss_g_msg_ptr;
extern kal_uint8 csmss_g_ussd_len;
extern kal_uint8 csmss_g_ussd_dcs;
extern kal_uint8 csmss_g_cf_number_length;
extern kal_bool csmss_g_change_phase_req;
/* erasusre before register */
extern kal_bool csmss_g_erase_reg_req;
/* interrogate after active */
extern kal_bool csmss_g_query_act_req;
extern kal_uint32 csmss_essp;

typedef struct csmss_context_struct
{
    kal_uint8 default_priority_level;
    kal_uint8 maximum_priority_level;
#if defined (__REL4__)
    kal_uint8 msp_num[4];
#endif
    kal_uint8 ori_ss_ctrl_type;
    kal_uint8 type_of_modification;
    kal_bool ss_ctrl_done;
#if defined (__CPHS__) || defined (__REL4__)
    kal_bool is_camp_on;
    kal_bool is_cfu_read;
    kal_bool is_sim_refresh; /* for re-reading cfu */
    kal_uint8 cfu_flag[2];
    kal_uint16 cfu_flag_len;
    kal_uint16 cfis_record_len;//EF_CFIS record length    
#endif
    //[ALPS00006144]
    //[MAUI_02553565] [YuSu] [L4 SS] explicit SS feature
#if defined(__CSMSS_EXPLICIT_SS_OPERATION__)
    kal_uint8 is_explicit_ss_op;
#endif
    csmss_rat_enum rat_info;//0:2/3G, 1:4G
} csmss_context_struct;

extern csmss_context_struct csmss_g[MAX_SIM_NUM];
extern csmss_context_struct *csmss_ptr_g;
extern module_type csmss_cur_mod;


#endif /* End of file csmss_context.h */


