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
 *	smsal_other_funcs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is the header file of smsal_other_funcs.c
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

#ifndef _SMSAL_OTHER_FUNCS_H
#define _SMSAL_OTHER_FUNCS_H

#include "mnsms_struct.h"
#include "smsal_l4c_enum.h"
#include "l4c2smsal_struct.h"
#include "l3_inc_enums.h"
#include "smsal_enums.h"
#include "smsal_structs.h"
#include "mcd_l4_common.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "ps_public_struct.h"

#define smsal_get_msg_dest_addr_from_pdu(_ptr, _addr) \
    smsal_get_dest_addr_from_pdu(SMSAL_MTI_SUBMIT, _ptr, _addr);

#define smsal_get_cmd_dest_addr_from_pdu(_ptr, _addr) \
    smsal_get_dest_addr_from_pdu(SMSAL_MTI_COMMAND, _ptr, _addr);

#define smsal_modify_da_in_msg_pdu(_ptr, _len, _addr_len, _addr_bcd) \
    smsal_modify_da_in_pdu(SMSAL_MTI_SUBMIT, _ptr, _len, _addr_len, _addr_bcd);

#define smsal_modify_da_in_cmd_pdu(_ptr, _len, _addr_len, _addr_bcd) \
    smsal_modify_da_in_pdu(SMSAL_MTI_COMMAND, _ptr, _len, _addr_len,_addr_bcd);

typedef struct
{
    kal_uint16   index;
    kal_uint8    year;
    kal_uint8    month;
    kal_uint8    day;
    kal_uint32   sec;
} smsal_sort_inbox_struct;

typedef struct
{
    smsal_sort_inbox_struct *item;
} smsal_sort_inbox_list_struct;

typedef enum
{
    SMSAL_SORT_BY_YEAR,  /* 0~99     */
    SMSAL_SORT_BY_MONTH, /* 1~12     */
    SMSAL_SORT_BY_DAY,   /* 1 ~31    */
    SMSAL_SORT_BY_SEC    /* sec      */
} inbox_list_sort_key;

#ifndef __SMS_STORAGE_BY_MMI__
kal_bool smsal_is_index_valid(kal_uint16 index);
kal_uint16 smsal_find_mb_entry_by_status(kal_uint8 src_id,
                                         kal_uint16 start,
                                         kal_uint8 status);
kal_uint16 smsal_find_mb_entry_by_del_flag(kal_uint8 src_id,
                                           kal_uint16 start,
                                           kal_uint8 del_flag);
kal_bool smsal_find_mb_storage_type_by_index(kal_uint16 index,
                                             smsal_storage_enum *storage_type);
#endif

#if !defined (__SMS_ME_STORAGE__)
kal_bool smsal_is_storage_available(kal_uint16 msg_num);
#else
kal_bool smsal_is_storage_available(smsal_storage_enum storage_type,
                                    kal_uint16 msg_num,
                                    kal_uint16 *sim_num,
                                    kal_uint16 *me_num);
#endif
kal_bool smsal_check_mem_full_status(void);

#if !defined(__SMS_STORAGE_BY_MMI__)
/*
 * status transform
 */
kal_bool smsal_get_ext_status(kal_uint8  int_status, kal_uint8 *status);
kal_bool smsal_get_int_status(smsal_status_enum status,
                              kal_uint8 *int_status);
#endif

/*
 * Pending Act Struct
 */
kal_bool smsal_is_pending_act_available(kal_uint8 *id);
kal_bool smsal_get_pending_act_id(kal_uint8 *id);
void smsal_free_pending_act(kal_uint8 id);
kal_bool smsal_find_pending_act(kal_uint8 id);

/*
 * Error handlers
 */
void smsal_send_error(kal_uint8  src_id,
                      kal_uint8  seq_num,
                      smsal_concat_struct    *concat_info,
                      smsal_error_cause_enum error_cause);

#if !defined(__SMS_STORAGE_BY_MMI__)
void smsal_read_error(kal_uint8 src_id,
                      smsal_error_cause_enum error_cause) ;
#endif

#ifdef __SMS_RAW_DATA_ACCESS_SUPPORT__
void smsal_read_raw_data_error(kal_uint8 src_id,
                               smsal_error_cause_enum error_cause) ;
#endif


/*------------------------------------
 * Common functions for handling
 * 1. requests from MMI or
 * 2. message from network
 *------------------------------------*/
#if defined(__SMS_STORAGE_BY_MMI__)
#else
void smsal_reset_tpdu_decode_struct(smsal_tpdu_decode_struct *tpdu_decode_ptr);
void smsal_free_tpdu_decode_struct(smsal_tpdu_decode_struct *tpdu_decode_ptr);


kal_uint8 smsal_decode_udh(kal_uint8                 *data,
                           smsal_concat_struct       *concat_info,
                           smsal_msg_waiting_struct  *msg_wait,
                           smsal_port_struct         *port);

#endif

#ifdef __SMS_R6_ENHANCED_VOICE_MAIL__
kal_uint8 smsal_decode_tpoa_to_MMI(kal_uint8 *input, l4_addr_bcd_struct *output);
void smsal_evm_free_evm(smsal_evmi_struct *evmi);
kal_uint8 smsal_decode_evmi(kal_uint8 * rawdata, kal_uint16 total_len, smsal_evmi_struct *evmi);
#endif

kal_bool smsal_detect_udh(kal_uint8 *data);

kal_bool smsal_get_concat_info(kal_uint8 *data, smsal_concat_struct *concat_info);

#if !defined(__SMS_STORAGE_BY_MMI__)
kal_bool smsal_decode_tpdu(smsal_tpdu_decode_struct *tpdu_decode_ptr,
                           kal_uint8 *data,
                           kal_uint8 len);

kal_bool smsal_decode_sms_pdu(kal_uint8 *pdu,
                              kal_uint8 pdu_len,
                              smsal_pdu_decode_struct *sms_pdu);


kal_bool smsal_tp_addr_cmp(sms_addr_struct *addr1,
                           kal_uint8 addr2[]);
#endif

#if !defined(__SMS_STORAGE_BY_MMI__)
kal_bool smsal_rp_addr_cmp(sms_addr_struct *addr1,
                           sms_addr_struct *addr2);
#endif

kal_uint32 smsal_scts_to_local(kal_uint8 timestamp[]);
void smsal_local_to_scts(kal_uint32 scts_utc_sec ,kal_uint8 timestamp[]);

/* for sorting inbox list */
void smsal_sort_inbox_list(kal_uint16 index[], kal_uint16 *tot_msg);

kal_uint16 smsal_get_storage_info(smsal_storage_info_enum type,
                                  smsal_storage_enum mem_type);
kal_uint8 smsal_get_free_cnmi_id(void);


kal_bool smsal_get_pending_send(kal_uint8  start_idx,
                                kal_uint8  *access_id,
                                kal_uint8  *src_id,
                                kal_uint8  *msg_ref,
                                kal_uint8  *seq_num);


kal_bool smsal_find_pending_send(kal_uint8           smi,
                                 kal_uint8           *src_id,
                                 kal_uint8           *access_id,
                                 kal_uint8           *seq_num);


void smsal_get_msg_sc_addr(kal_uint8                  src_id,
                           kal_uint16                 reply_index,
                           smsal_send_msg_req_hdr_struct *send_msg_ptr,
                           l4csmsal_send_from_storage_req_struct *send_msg_from_storage_ptr,
                           sms_addr_struct           *sc_addr_ptr) ;

kal_bool smsal_get_sc_addr_from_pdu(kal_uint8       *pdu_ptr,
                                    sms_addr_struct *tp_addr);

void smsal_get_msg_dest_addr(kal_uint16          reply_index,
                             kal_bool           da_tag,
                             l4_addr_bcd_struct *l4_addr,
                             sms_addr_struct    *tp_addr);


kal_bool smsal_get_dest_addr_from_pdu(smsal_mti_enum  mti,
                                      kal_uint8       *pdu_ptr,
                                      sms_addr_struct *tp_addr);

kal_bool smsal_get_dest_addr_from_tpdu(smsal_mti_enum  mti,
                                       kal_uint8         *tpdu_ptr,
                                       sms_addr_struct   *tp_addr);

smsal_msg_format_enum smsal_get_msg_format(kal_uint8 src_id);

peer_buff_struct *smsal_modify_da_in_pdu(smsal_mti_enum   mti,
                                         kal_uint8  *pdu_ptr,
                                         kal_uint16 pdu_len,
                                         kal_uint8  addr_length,
                                         kal_uint8  addr_bcd[]);

peer_buff_struct *smsal_modify_da_in_tpdu(smsal_mti_enum   mti,
                                          kal_uint8  *tpdu_ptr,
                                          kal_uint16 tpdu_len,
                                          kal_uint8  addr_length,
                                          kal_uint8  addr_bcd[]);

void smsal_prepare_stored_data(kal_uint8       data[],
                               kal_uint8       status,
                               kal_uint8       *pdu_ptr,
                               kal_uint16      pdu_len,
                               sms_addr_struct *sca);

void smsal_reset_mailbox_info(smsal_mailbox_info_struct  *mb,
                              kal_uint8                  line_no);

/*
 * Address conversion
 */
kal_uint8 compute_tp_addr_len(kal_uint8 len_in_octet,
                              kal_uint8 bcd[]);

void sms_rp_addr2_l4_addr(sms_addr_struct    *tp_addr,
                          l4_addr_bcd_struct *l4_addr);

void l4_addr2_sms_rp_addr(l4_addr_bcd_struct *l4_addr,
                          sms_addr_struct    *rp_addr);

void sms_tp_addr2_l4_addr(sms_addr_struct    *tp_addr,
                          l4_addr_bcd_struct *l4_addr);

void sms_tpdu_addr2_l4_addr(kal_uint8  *tpdu_addr,
                            l4_addr_bcd_struct *l4_addr);

void l4_addr2_sms_tp_addr(l4_addr_bcd_struct *l4_addr,
                          sms_addr_struct    *tp_addr);

void sms_tpdu_addr2_sms_tp_addr(kal_uint8  *tpdu_addr,
                                sms_addr_struct *tp_addr);
#if 0
/* under construction !*/
/* under construction !*/
#endif

kal_bool smsal_where_to_save_concat_msg(smsal_concat_struct *concat_info,
                                        kal_uint16 hash,
                                        kal_uint8 preferred_mem,
                                        smsal_storage_enum *stroage_type);


kal_uint8 smsal_check_is_me_full(void);

/* __IMS_SUPPORT__ */
void smsal_ims_send_error(kal_uint8 src_id, kal_uint8 seq_num, smsal_error_cause_enum error_cause);

void smsal_ims_send_cnf(kal_uint8 result, kal_uint8 src_id, kal_uint8 msg_ref, sms_addr_struct *sc_addr_ptr, peer_buff_struct *peer_buff_ptr);
#endif /* _SMSAL_OTHER_FUNCS_H */


