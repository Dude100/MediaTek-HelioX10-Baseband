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
 *	smsal_sms.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is the header file of smsal_sms.c
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

#ifndef _SMSAL_SMS_H
#define _SMSAL_SMS_H

#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_general_types.h"

void smsal_sms_entry_func(ilm_struct *ilm_ptr);

void smsal_send_msg_to_sms(msg_type msg_id,
                           local_para_struct *local_ptr,
                           peer_buff_struct  *peer_ptr
                          );


/* This function prototype defines the handler function for SM
 * deliveries in connected state to SMSAL layer */
void smsal_deliver_handler(local_para_struct *local_para_ptr,
                           peer_buff_struct  *peer_buff_ptr);


/* This function prototype defines the handler function for successful
 * message submit report to SMSAL layer in connected state */
void smsal_submit_ack_handler(local_para_struct *local_para_ptr,
                              peer_buff_struct  *peer_buff_ptr);



/* This function prototype defines the handler function for unsuccessful
 * message submit report to SMSAL layer in connected state */
void smsal_submit_nack_handler(local_para_struct *local_para_ptr,
                               peer_buff_struct  *peer_buff_ptr);



/* This function prototype defines the handler function for status report
 * of previously submitted messages to SMSAL layer in connected state */
void smsal_status_report_handler(local_para_struct *local_para_ptr,
                                 peer_buff_struct  *peer_buff_ptr);

void smsal_mem_avl_notif_cnf(local_para_struct *local_para_ptr);

/*
 * Memory available notifications
 */
void smsal_send_mem_avl_notif_req(void);
void smsal_send_mem_avl_notif_abort(void);
void smsal_mem_avl_get_msg_ref_cnf(kal_uint8 id);

void smsal_prefer_sms_bearer_change(void);
void smsal_submit_abort_cnf(local_para_struct *local_para_ptr);
void smsal_update_mms_mode_handler(void);
#if defined(__SMS_STORAGE_BY_MMI__) && defined(WISDOM_MMI)
void smsal_mt_final_ack_ind(local_para_struct *local_para_ptr);
#endif

#ifdef __FIX_7BIT_EMPTY_CONTENT__
void smsal_mt_fix_7bit_empty_content(smsal_pdu_decode_struct *pdu_decode, kal_uint8 *pdu_ptr);
#endif /*__FIX_7BIT_EMPTY_CONTENT__*/

void smsal_tr2_expire_handler();

#endif /* _SMSAL_SMS_H */

