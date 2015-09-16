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
 *	smsal_parameter.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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

#ifndef _SMSAL_PARAMETER_H
#define _SMSAL_PARAMETER_H

#include "smsal_structs.h"
#include "l4c2smsal_struct.h"
#include "smsal_l4c_enum.h"
#include "kal_general_types.h"
#include "ps_public_struct.h"

void smsal_encode_smsp(smsal_profile_element_struct *,
                       kal_uint8 data[]);
void smsal_decode_smsp(kal_uint8 id,
                       kal_uint8 data[],
                       kal_uint16 length);
void smsal_encode_common_param(smsal_nvm_common_param_struct *,
                               kal_uint8 *pdu_ptr);
void smsal_decode_common_param(kal_uint8 *pdu_ptr);

void smsal_encode_nvram_mwis_rec(kal_uint8 msp, kal_uint8 line_no, kal_uint8 * pdu_ptr);
void smsal_decode_nvram_mwis_rec(kal_uint8 msp, kal_uint8 line_no, kal_uint8 * pdu_ptr);

void smsal_encode_mailbox_addr(smsal_mailbox_addr_struct*,
                               kal_uint8 *pdu_ptr,
                               kal_bool  is_from_sim);

void smsal_encode_mailbox_ext_addr(smsal_mailbox_addr_struct *mb_addr, kal_uint8 *pdu_ptr);

void smsal_decode_mailbox_addr(kal_uint8 line_no,
                               kal_uint8 *pdu_ptr,
                               kal_bool  is_from_sim);

#ifdef __REL4__
void smsal_decode_r4mwis(kal_uint8 msp_no, kal_uint8 * pdu_ptr, kal_uint16 length);
void smsal_encode_mbi(smsal_mbi_struct *mbi, kal_uint8 *pdu_ptr, kal_uint16 length);
void smsal_decode_mbi(kal_uint8 msp_no, kal_uint8 *data, kal_uint16 length);
#endif

#ifdef __CPHS__
void smsal_decode_mwf(kal_uint8 *data);
void smsal_encode_mwf(kal_uint8 *data);
#endif

void smsal_update_mwis(kal_uint8 msp, kal_uint8 line_no, smsal_mwis_struct *mwis);


/*
 * For handling SET Parameter Request
 */
void smsal_fill_pending_profile_param(l4csmsal_set_profile_para_req_struct *set_req,
                                      kal_uint8 act_id);

void smsal_fill_pending_common_param(l4csmsal_set_common_para_req_struct *set_req,
                                     kal_uint8 act_id);

void smsal_set_common_param(smsal_nvm_common_param_struct *common,
                            kal_uint16 para_ind);

void smsal_save_parameter(kal_uint8 access_id);

void smsal_save_parameter_cnf(kal_uint8 id, kal_uint8 sub_act_code);


void smsal_save_parameter_rej(kal_uint8  id,
                              kal_uint8  sub_act_code,
                              kal_uint16 cause);


void smsal_write_nvm_params(smsal_file_enum  file_id,
                            kal_uint16       record_no,
                            kal_uint16       aux_data,
                            void             *data_to_write,
                            kal_uint8        access_id);

#endif /* _SMSAL_PARAMETER_H */


