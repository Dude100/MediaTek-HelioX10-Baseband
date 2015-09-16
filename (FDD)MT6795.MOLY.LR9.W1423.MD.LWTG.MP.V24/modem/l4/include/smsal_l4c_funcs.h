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
 *	smsal_l4c_funcs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is the header file of smsal_l4c_funcs.c  
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
 *
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

#ifndef _SMSAL_L4C_FUNCS_H
#define _SMSAL_L4C_FUNCS_H

#include "l4c2smsal_struct.h"
#include "mcd_l4_common.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "ps_public_struct.h"
#include "ps_public_utility.h"

extern void smsal_get_common_para(kal_uint8  *fo,
                           kal_uint8  *bearer,
                           kal_uint8  *reply_path,
                           kal_uint8  *status_report);

extern void smsal_get_mailbox_addr(kal_uint8 *mailbox_num, 
                                   kal_uint8 *alpha_length,
                                   kal_uint8 *max_num_length,
                                   smsal_mailbox_addr_struct *mailbox_addr);

#ifdef __REL4__
extern void smsal_get_mbi(kal_uint8 *mbi_rec_num, 
                          smsal_mbi_struct *mbi);

extern void smsal_get_selected_msp(kal_uint8 *selected_msp);
extern kal_uint16 smsal_set_selected_msp(kal_uint8 selected_msp);
#endif

extern void smsal_normal_service_ind(void);

extern smsal_inbox_list_struct *smsal_get_inbox_list(kal_uint16 start_msg,
                                                     kal_uint8 num_msg);

extern smsal_outbox_list_struct *smsal_get_outbox_list(kal_uint16 start_msg,
                                                       kal_uint8 num_msg);

extern 
kal_bool smsal_get_msgbox_num(kal_bool  *is_sms_ready,
                              kal_bool  *is_sim_card_change,
                              kal_uint16 *inbox_sim_num,
                              kal_uint16 *inbox_me_num,
                              kal_uint16 *outbox_sim_num,
                              kal_uint16 *outbox_me_num,
                              kal_uint16 *unread_msg_num,
                              kal_uint16 *total_sim_num,
                              kal_uint16 *total_me_num);                             
                                 
extern void smsal_get_profile_info(kal_uint8 *profile_num,
                                   kal_uint8 *profile_name_len);

extern kal_bool smsal_get_profile_name(kal_uint8 profile_no,
                                       l4_name_struct *profile_name);

/*
extern kal_uint16 smsal_set_bearer_service(
                     kal_uint8 bearer);
extern void smsal_get_bearer_service(kal_uint8 *bearer);
*/

/*****************************************************************************
 * 
 * Following functions are for fulfilling AT-Commands
 * 
 *  smsal_xxxx_set   : set parameters for command xxxx
 *  smsal_xxxx_query : get current parameters of command xxxx
 *  smsal_xxxx_test  : TEST for command xxxx, return string of supporting 
 *                     values of servies/parameter
 *  smsal_xxxx_exe   : EXECUTE for command xxxx
 *
 ****************************************************************************/

extern void smsal_cgsms_query(kal_uint8 *service);

extern void smsal_cgsms_test(kal_uint8 const **test_str);

extern kal_uint16 smsal_cnma_exe(kal_uint8 id,
                                      kal_uint8 mode,                                      
                                      peer_buff_struct *peer_buff_ptr);

extern kal_uint16 smsal_csms_set(
                            kal_uint8 service);

extern void smsal_csms_query(kal_uint8 *service, 
                      smsal_service_mode_struct *service_info);

extern void smsal_csms_test(kal_uint8 const **test_str);

/*
extern kal_uint16 smsal_cpms_set(  kal_uint8 mem1,
                                   kal_uint8 mem2,
                                   kal_uint8 mem3
                                 );
*/
extern void smsal_cpms_query(smsal_prefer_storage_struct *mem_info);
extern void smsal_cpms_test(kal_uint8 const **test_str);

#if defined(__SMS_STORAGE_BY_MMI__)
extern kal_uint16 smsal_force_at_cmgf_mode_set(kal_uint8 msg_format);
#endif

extern kal_uint16 smsal_cmgf_set(kal_uint8 msg_format);

extern void smsal_cmgf_query(kal_uint8 *msg_format);

extern void smsal_cmgf_test(kal_uint8 const **test_str);

extern kal_uint16 smsal_csca_set(l4_addr_bcd_struct sca); 

extern void smsal_csca_query(l4_addr_bcd_struct *sca, 
                      kal_uint8 profile_no);

extern kal_uint16 smsal_csmp_set(kal_uint8 profile_no,
                                      kal_uint8 para_ind,
                                      kal_uint8 fo,
                                      kal_uint8 vp,
                                      kal_uint8 pid,
                                      kal_uint8 dcs
                                     );

extern void smsal_csmp_query(kal_uint8 profile_no,
                      kal_uint8 *fo,
                      kal_uint8 *vp,
                      kal_uint8 *pid,
                      kal_uint8 *dcs
                     );

extern kal_uint16 smsal_csdh_set(kal_uint8 show);

extern void smsal_csdh_query(kal_uint8 *show);

extern void smsal_csdh_test(kal_uint8 const **test_str);

extern kal_uint16 smsal_cres_set(kal_uint8 profile_id);
extern void smsal_cres_test(kal_uint8 const **test_str);

extern void smsal_csas_test(kal_uint8 const **test_str);

extern kal_uint16 smsal_esmss_set(kal_uint8 esmss_val);
extern void smsal_esmss_test(kal_uint8 const **test_str);
extern void smsal_esmss_query(kal_uint8 *esmss_val);

extern kal_bool smsal_eqsi_query(kal_uint8  mem,
                          kal_uint16 *beg_index,
                          kal_uint16 *end_index,
                          kal_uint16 *used);

extern void smsal_emems_query(kal_uint8 storage_type, kal_uint8 *is_full);
extern void smsal_emems_set(kal_uint8 storage_type, kal_uint8 is_full);
#ifdef __IMS_SUPPORT__
extern void smsal_esmma_set(kal_uint8 smma);
#endif

extern kal_uint16 smsal_cnmi_set(
                               smsal_mt_msg_route_struct mt_route);

extern void smsal_cnmi_query(smsal_mt_msg_route_struct *mt_route);

extern void smsal_cnmi_test(kal_uint8 const **test_str);

extern void smsal_eqsi_test(kal_uint8 const **test_str);

extern void smsal_cmgl_test(kal_uint8 const **test_str);
extern void smsal_cmgd_test(kal_uint8 const **test_str);
extern kal_uint16 smsal_cmms_set(kal_uint8 mms);

extern void smsal_cmms_query(kal_uint8 *mms);

extern void smsal_cmms_test(kal_uint8 const **test_str);
extern void smsal_cnma_test(kal_uint8 const **test_str);
#if 0
/* under construction !*/
#endif

#ifdef __CB__
extern 
void smsal_cb_get_status(kal_uint8    *on_off,
                         kal_uint8    *mi_num,
		         kal_uint8    *mir_num,
		         kal_uint8    *dcs_num,                                   
                         l4c_cb_info_struct *cb_info); 

extern kal_uint16 smsal_cb_conver_ISO639_to_CBDCS(kal_uint16 ISO639);

#endif/*__CB__*/

extern kal_bool smsal_reg_port_num(kal_uint8 enable, kal_uint16 *cause, 
                                   kal_uint32 port_num, kal_uint16 mod_id ) ;   

#endif /* _SMSAL_L4C_FUNCS_H */


