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
 * rmmi_rspfmttr.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for �K.
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

#ifndef _RMMI_RSPFMTTR_H
#define _RMMI_RSPFMTTR_H

//#include "kal_non_specific_general_types.h"
#include "csmcc_atfunc.h"
//#include "l4c_aux_struct.h"
#include "mcd_l4_common.h"
//#include "l4c2smsal_struct.h"
#include "kal_general_types.h"
#include "ps_public_struct.h"

extern void rmmi_result_code_fmttr(kal_uint8 rsp_type, kal_uint16 cause);

extern void rmmi_final_rsp_generator(kal_uint8 src_id, kal_bool ret_val, kal_uint8 *buffer, kal_uint16 string_length);

extern void rmmi_sms_result_code_fmttr(kal_uint8 rsp_type, kal_uint16 cause, kal_bool cause_present);

extern void rmmi_sms_final_rsp_generator(
                kal_uint8 src_id,
                kal_bool ret_val,
                kal_uint8 *buffer,
                kal_uint16 string_length);

extern void rmmi_cring_unsolicited_rsp_fmttr(kal_uint8 *buffer);

extern void rmmi_ccsr_ind_fmttr(kal_int32 em_info, void *info); //mtk00468 add for give the unsoliceted result code to RMMI with CCSP on

extern void rmmi_clcc_read_rsp_fmttr(l4c_call_entry_struct call_entry, l4c_number_struct addr);

extern void rmmi_caemlpp_read_rsp_fmttr(kal_uint8 default_priority, kal_uint8 max_priority);

extern void rmmi_ccfc_interrogate_rsp_fmttr(kal_uint8 status, kal_uint8 classx, kal_uint8 timer, kal_uint8 *address);

extern void rmmi_ccwa_interrogate_rsp_fmttr(kal_uint8 status, kal_uint8 classx);

extern void rmmi_cdip_read_rsp_fmttr(kal_uint8 report_mode, kal_uint8 status);

extern void rmmi_clip_read_rsp_fmttr(kal_uint8 report_mode, kal_uint8 status);

extern void rmmi_clip_unsolicited_rsp_fmttr(kal_uint8 *buffer);

extern void rmmi_colp_unsolicited_rsp_fmttr(
                l4c_number_struct *num,
                l4c_sub_addr_struct *sub_addr,
                kal_uint8 *name);

extern void rmmi_clir_read_rsp_fmttr(kal_uint8 report_mode, kal_uint8 status);

extern void rmmi_cnap_read_rsp_fmttr(kal_uint8 report_mode, kal_uint8 status);

 /* mtk00468 add for csim error response from sim task */
extern void rmmi_csim_error_rsp_fmttr(kal_uint16 cause);

/* mtk00468 add for cnvrm error response from nvram task */
extern void rmmi_ccsp_error_rsp_fmttr(kal_uint16 cause);

/* mtk00468 add for ccsp error response from SIM task */
extern void rmmi_cnvrm_error_rsp_fmttr(kal_uint16 cause);

#ifdef __MOD_RAC__

extern void rmmi_cops_test_rsp_fmttr(l4c_rat_plmn_info_struct *list);

#endif /* __MOD_RAC__ */ 

extern void rmmi_colp_read_rsp_fmttr(kal_uint8 report_mode, kal_uint8 status);

extern void rmmi_colr_read_rsp_fmttr(kal_uint8 report_mode, kal_uint8 status);

extern void rmmi_clck_interrogate_rsp_fmttr(kal_uint8 status, kal_uint8 classx);

extern void rmmi_crsm_exe_rsp_fmttr(kal_uint8 sw1, kal_uint8 sw2, kal_uint16 length, kal_uint8 *response);

extern void rmmi_phb_msisdn_rsp_fmttr(l4c_phb_entry_struct *entry); 

extern void rmmi_phb_entry_rsp_fmttr(l4c_phb_entry_struct *entry);

extern void rmmi_cr_result_code_fmttr(void);    //mtk00714 20040303 add for +CR

#ifdef __MOD_SMSAL__
extern void rmmi_sms_send_rsp_fmttr(kal_uint8 mr, kal_uint8 *scts,kal_uint8 src_id);

extern void rmmi_sms_read_rsp_fmttr(
                kal_uint16 length,
                kal_uint8 mti,
                kal_uint8 status,
                kal_uint8 hex_dspl,
                l4_name_struct alpha_id,
                void *msg_header,
                void *data);

extern void rmmi_sms_list_rsp_fmttr(
                kal_uint16 length,
                kal_uint8 mti,
                kal_uint8 status,
                kal_uint16 index,
                kal_uint8 hex_dspl,
                l4_name_struct alpha_id,
                void *msg_header,
                void *data);

extern void rmmi_sms_write_rsp_fmttr(kal_uint16 index);

extern void rmmi_sms_storage_rsp_fmttr(smsal_prefer_storage_struct *mem);
#endif /* __MOD_SMSAL__ */ 

extern kal_uint16 rmmi_fast_string_print(kal_uint8 *buff_ptr, kal_uint8 *fmt, void *arg_list[], kal_uint8 nos_arg);

extern void rmmi_int_to_ascii_converter(kal_uint32 digit, kal_uint8 *buff_ptr);

extern kal_uint16 rmmi_ecell_result_code_fmttr(kal_uint8 *buffer, kal_uint16 string_length,
                                            kal_uint8 Act,
                                            kal_uint32 cid,
                                            kal_uint16 lac_or_tac,
                                            kal_uint32 mcc,
                                            kal_uint32 mnc,
                                            kal_uint32 psc_or_pci,
                                            kal_uint8 sig1,
                                            kal_uint8 sig2,
                                            kal_int32 sig1_in_qdbm,
                                            kal_int32 sig2_in_qdbm,
                                            kal_uint32 ta,
                                            kal_uint32 ext1,
                                            kal_uint32 ext2);


/* __IMS_SUPPORT__ */
extern void rmmi_sms_ims_send_rsp_fmttr(kal_uint8 mr, l4_addr_bcd_struct *sca, peer_buff_struct *peer_buff_ptr, kal_uint8 src_id);

extern void rmmi_sms_ims_result_code_fmttr(kal_uint8 cmd_type, kal_uint8 src_id);

extern void rmmi_sms_ims_recv_ind_fmttr(kal_uint8 ack, peer_buff_struct *peer_buff_ptr);

extern void rmmi_sms_ims_smma_rsp_fmttr(kal_uint8 mr, kal_uint8 src_id);

extern void rmmi_sms_ims_smma_ind_fmttr(kal_uint8 smma);
#endif /* _RMMI_RSPFMTTR_H */ /* rmmi_rspfmttr.h */

