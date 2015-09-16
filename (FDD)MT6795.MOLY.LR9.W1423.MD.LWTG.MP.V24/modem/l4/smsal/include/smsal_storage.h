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
 *	smsal_storage.h
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

#ifndef _SMSAL_STORAGE_H
#define _SMSAL_STORAGE_H


#include "smsal_structs.h"
#include "smsal_l4c_enum.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_general_types.h"
#include "sim_common_enums.h"

/*****************************************************
 *
 * For Common function prototypes
 *
 *****************************************************/
void smsal_common_storage_cnf(kal_uint8  id,
                              kal_uint8  sub_act_code,
                              ilm_struct *ilm_ptr,
                              kal_bool   is_from_sim);

void smsal_common_storage_rej(kal_uint8  id,
                              kal_uint8  sub_act_code,
                              ilm_struct *ilm_ptr,
                              kal_bool   is_from_sim,
                              kal_uint16 cause);

/*****************************************************
 *
 * For Read File function prototypes
 *
 *****************************************************/
void smsal_init_file_info(smsal_read_file_aux_info_struct *file_ptr);

#ifndef EMPTY_MMI
#ifndef __SMS_STORAGE_BY_MMI__
void smsal_continue_read_nvram_sms(kal_uint8 id,
                                   smsal_read_file_aux_info_struct *aux_info);
#endif
#endif
void smsal_send_file_change_resp_to_sim(kal_uint8 id, kal_bool result);


void smsal_assign_file_list(smsal_read_file_aux_info_struct *file_ptr,
                            smsal_file_enum file_id);

kal_bool smsal_check_sim_service_table(smsal_file_enum file_id);

void smsal_skip_file(smsal_read_file_aux_info_struct *file_ptr, 
                     kal_uint8 index);

void smsal_read_files(kal_uint8 id,
                      smsal_read_file_aux_info_struct *file_ptr);

void smsal_read_files_cnf(kal_bool is_successful,
                          kal_uint8 id,
                          peer_buff_struct *peer_buff_ptr,
                          local_para_struct *local_para_ptr);

void smsal_reset_files_cnf(kal_bool result, kal_uint8 id);

kal_uint8 smsal_read_smss_cnf(kal_uint8 id,
                              smsal_read_file_aux_info_struct *aux_info,
                              peer_buff_struct *peer_buff_ptr,
                              local_para_struct *local_para_ptr);

kal_uint8 smsal_read_smsp_cnf(kal_uint8 id,
                              smsal_read_file_aux_info_struct *aux_info,
                              peer_buff_struct *peer_buff_ptr,
                              local_para_struct *local_para_ptr);

kal_uint8 smsal_read_smsp_rej(kal_uint8 id,
                              smsal_read_file_aux_info_struct *aux_info,
                              peer_buff_struct *peer_buff_ptr,
                              local_para_struct *local_para_ptr);

#ifndef __SMS_STORAGE_BY_MMI__
kal_uint8 smsal_read_sim_sms_cnf(kal_uint8 id,
                                 smsal_read_file_aux_info_struct *aux_info,
                                 peer_buff_struct *peer_buff_ptr,
                                 local_para_struct *local_para_ptr);

kal_uint8 smsal_read_sim_sms_rej(kal_uint8 id,
                                 smsal_read_file_aux_info_struct *aux_info,
                                 peer_buff_struct *peer_buff_ptr,
                                 local_para_struct *local_para_ptr);

/* Read/Write Message */
void smsal_read_short_msg(kal_uint8          sim_access_id,
                          smsal_storage_enum storage_type,
                          kal_uint16         record_no);

void smsal_write_short_msg(kal_uint8           sms_access_id,
                           smsal_storage_enum  storage_type,
                           kal_uint16          record_no,
                           kal_uint8           *data,
                           kal_uint8           *scts_ptr,
                           kal_uint8           length);

/* Delete Message */
void smsal_reset_short_msg(kal_uint8          sms_access_id,
                           smsal_storage_enum storage_type,
                           kal_uint16         record_no);
#endif

kal_bool smsal_reset_files_in_nvram(local_para_struct *local_para_ptr);

/*****************************************************
 *
 * For SIM function prototypes
 *
 *****************************************************/

/* SIM messages entry function */
void smsal_sim_entry_func(ilm_struct *ilm_ptr);

/* Unset 'SMS Memory Exceeded Flag' */
void smsal_clrexdflag(void);

/* Send ILM to SIM */
void smsal_send_msg_to_sim(msg_type   msg_id,
                           local_para_struct *local_para_ptr,
                           peer_buff_struct  *peer_buff_ptr);

/* updates the common change in NVRAM */
void smsal_set_common_change_to_nvram(kal_uint8 access_id);

/* Read EF from SIM */
void smsal_read_from_sim(kal_uint8        access_id,
                         smsal_file_enum  file_id,
                         kal_uint16       length,
                         kal_uint16       para);

/* Write EF to SIM */
void smsal_write_to_sim(kal_uint8        access_id,
                        smsal_file_enum  file_id,
                        kal_uint8        *data,
                        kal_uint16       length,
                        kal_uint16       para);

/*
 * Read File Info of an EF from SIM
 */
void smsal_read_fileinfo_from_sim(kal_uint8        access_id,
                                  smsal_file_enum  file_id,
                                  kal_uint8        info_type);

/*****************************************************
 *
 * For NVRAM function prototypes
 *
 *****************************************************/
/* NVRAM message entry function */
void smsal_nvram_entry_func(ilm_struct *ilm_ptr);

/* Send ILM to NVRAM */
void smsal_send_msg_to_nvram(msg_type          msg_id,
                             local_para_struct *local_para_ptr,
                             peer_buff_struct  *peer_buff_ptr);

/* Read EF from NVRAM */
void smsal_read_from_nvram(kal_uint8        access_id,
                           smsal_file_enum  file_id,
                           kal_uint16       para,
                           kal_uint16       rec_amount);

/* Write EF to NVRAM */
void smsal_write_to_nvram(kal_uint8        access_id,
                          smsal_file_enum  file_id,
                          kal_uint16       para,
                          peer_buff_struct *peer_buff_ptr);


#endif /* _SMSAL_STORAGE_H */


