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
 * l4c_sendmsg.h
 *
 * Project:
 * --------
 *   MT6208
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
 *             HISTORY
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

#ifndef _L4C_SENDMSG_H
#define _L4C_SENDMSG_H

#include "rmmi_context.h" /* for rmmi_string_struct */
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_general_types.h"
#include "l4c_lbs_struct.h"

extern void l4c_send_msg_to_csm(msg_type msg_name, void *param_ptr, kal_uint8 *buffer_ptr, kal_uint16 length);

extern void l4c_send_msg_to_csm_ciss(msg_type msg_name, void *param_ptr);

extern void l4c_send_msg_to_rac(msg_type msg_name, void *param_ptr);

extern void l4c_send_msg_to_smu(msg_type msg_name, void *param_ptr);

#if defined(__LTE_RAT__)
extern void l4c_send_msg_to_eval(msg_type msg_name, void *param_ptr);
#endif
extern void l4c_send_msg_to_sm(msg_type msg_name, void *param_ptr);

extern void l4c_send_msg_to_tcm(msg_type msg_name, void *param_ptr);

#ifdef __L4C_GPRS_UT__
extern void l4c_send_msg_to_dhl(msg_type msg_name, void *param_ptr);
#endif

extern void l4c_send_msg_to_tst_reader(msg_type msg_name, void * param_ptr); //RMMI_UT

extern void l4c_send_msg_to_med(msg_type msg_name, void *param_ptr);

#ifdef __MTK_TARGET__
extern void l4c_fake_rmmi_input_str_logging(rmmi_string_struct * source_string_ptr);
#endif

extern void l4c_send_msg_to_ratdm(msg_type msg_name, void *param_ptr);

extern void l4c_send_msg_to_ppp(msg_type msg_name, void *param_ptr);

extern void l4c_send_msg_to_wap(msg_type msg_name, void *param_ptr);    //030528 mtk00468 add for WAP profile set

extern void l4c_send_msg_to_abm(msg_type msg_name, void *param_ptr);

extern void l4c_send_msg_to_sim(msg_type msg_name, void *param_ptr, kal_uint8 *buffer_ptr);

extern void l4c_send_msg_to_irda(msg_type msg_name, void *param_ptr);   // mtk00468 add in 030829 for irda feature

extern void l4c_send_msg_to_nvm(msg_type msg_name, void *param_ptr, kal_uint8 *buffer_ptr, kal_uint16 length);

extern void l4c_send_msg_to_phb(msg_type msg_name, void *param_ptr, kal_uint8 *buffer_ptr);

extern void l4c_send_msg_to_smsal(msg_type msg_name, void *param_ptr, kal_uint8 *buffer_ptr, kal_uint16 length);

extern void l4c_send_msg_to_uem(msg_type msg_name, void *param_ptr, kal_uint8 *buffer_ptr);

#ifdef __UE_SIMULATOR__
extern void l4c_send_msg_to_uegw(msg_type msg_name, void *param_ptr);
#endif

#ifdef __CSD_FAX__
extern void l4c_send_msg_to_t30(msg_type msg_name, void *param_ptr);
#endif 

extern void l4c_send_msg_to_cmux(msg_type msg_name, void *param_ptr);

#ifdef __GEMINI__
extern void l4c_send_msg_to_rsvas(msg_type msg_name, void *param_ptr);
#endif 
#ifdef __EXT_MODEM__
extern void l4c_send_msg_to_ext_modem(msg_type msg_name, void *param_ptr);
#endif 

extern void l4c_send_queued_msg(kal_uint8 src_id, kal_uint8 operation); //MAUI_02626058

extern void l4c_clear_ss_parameter(kal_uint8 src_id);

extern void l4c_clear_cc_parameter(kal_uint8 src_id);

extern void l4c_clear_ss_queued_msg(kal_uint8 src_id);

extern void l4c_clear_cc_queued_msg(kal_uint8 src_id);

#if defined(__BT_SUPPORT__)
extern void rmmi_send_msg_to_bt(msg_type msg_name, void *param_ptr);
#endif 

#ifdef __TCPIP_OVER_CSD__
extern void l4c_clear_csd_parameter(void);
#endif

#ifdef __UAGPS_CP_SUPPORT__
extern void l4c_send_msg_to_uagps_cp(msg_type msg_name, void *param_ptr);
#endif

extern void l4c_send_msg_to_rrlp(msg_type msg_name, void *param_ptr);

extern void l4c_send_msg_to_meme(msg_type msg_name, void *param_ptr); //Thermal

#if defined(__ANDROID_RIL_SUPPORT__)

extern void l4c_send_ilm_ipc(kal_uint32 dest, msg_type msg_name, void *param_ptr);

extern void l4c_send_msg_to_lbs(msg_type msg_name, void *param_ptr);

extern void l4c_agps_reset_positioning_lind_lbs(void);

#if defined(__AGPS_CONTROL_PLANE__)
extern void l4c_ss_mtlr_begin_res_lrsp_lbs(kal_bool result, kal_uint8 ss_id);
extern void l4c_ss_aerq_begin_res_lrsp_lbs(kal_bool result, kal_uint8 ss_id);
extern void l4c_ss_aerp_begin_lrsp_lbs(kal_bool result, kal_uint16 cause, kal_uint8 ss_id);
extern void l4c_ss_aerp_end_lrsp_lbs(kal_bool result);
extern void l4c_ss_aecl_begin_res_lrsp_lbs(kal_bool result, kal_uint8 ss_id);
extern void l4c_ss_molr_begin_lrsp_lbs(kal_bool result, 
                                       kal_uint16 cause, 
                                       SS2_LCS_MOLRRes *molr_res, 
                                       kal_uint8 ss_id);
extern void l4c_ss_molr_end_lrsp_lbs(kal_bool result);
extern void l4c_ss_mtlr_begin_lind_lbs(SS2_LocationNotificationArg *notification, kal_uint8 ss_id);
extern void l4c_ss_aerq_begin_lind_lbs(SS2_LCS_AreaEventRequestArg *aerq, kal_uint8 ss_id);
extern void l4c_ss_aecl_begin_lind_lbs(SS2_LCS_AreaEventCancellationArg *aecl, kal_uint8 ss_id);
extern void l4c_agps_cp_start_lind_lbs(void);
extern void l4c_agps_cp_end_lind_lbs(void);
#ifdef __UAGPS_CP_SUPPORT__
extern void l4c_agps_new_key_needed_lind_lbs(void);
#endif /* __UAGPS_CP_SUPPORT__ */
#endif /* defined(__AGPS_CONTROL_PLANE__) */
#endif /* defined(__ANDROID_RIL_SUPPORT__) */

extern void l4c_send_msg(module_type dest, msg_type msg_name, sap_type sap, void *local_ptr, void *peer_ptr);

#endif /* _L4C_SENDMSG_H */
