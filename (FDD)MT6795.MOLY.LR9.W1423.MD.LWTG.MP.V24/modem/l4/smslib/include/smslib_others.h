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
 * smslib_others.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains prototype
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _SMSLIB_OTHERS_H
#define _SMSLIB_OTHERS_H

#if defined(__SMS_STORAGE_BY_MMI__)

#include "smslib_def.h"
#include "smslib_enum.h"
#include "kal_general_types.h"
#include "ps_public_utility.h"

#define smslib_deliver_peer_struct_alloc smsal_deliver_peer_struct_alloc
#define smslib_submit_peer_struct_alloc smsal_submit_peer_struct_alloc
#define smslib_status_report_peer_struct_alloc smsal_status_report_peer_struct_alloc

#define smslib_deliver_peer_struct_dealloc smsal_deliver_peer_struct_dealloc
#define smslib_submit_peer_struct_dealloc smsal_submit_peer_struct_dealloc
#define smslib_status_report_peer_struct_dealloc smsal_status_report_peer_struct_dealloc

void smslib_free_tpdu_decode_struct(smslib_tpdu_decode_struct *);

kal_bool smslib_is_len_in8bit(kal_uint8);
kal_uint16 smslib_msg_len_in_character(kal_uint8, kal_uint16, kal_uint8);
void smslib_decode_dcs(kal_uint8, smslib_alphabet_enum *, smslib_msg_class_enum *, kal_bool *, smslib_msg_waiting_struct *);

kal_bool smslib_detect_udh(kal_uint8 *);
kal_uint8 smslib_decode_udh(kal_uint8 *, smslib_concat_struct *, smslib_msg_waiting_struct *, smslib_port_struct *);
void smslib_start_decode_dcs_udh(kal_uint8 *, kal_uint8, kal_uint8 *, kal_uint8, kal_uint8 *, smslib_tpdu_decode_struct *, kal_uint8);

#ifdef __REL6__
#ifdef __SMS_R6_ENHANCED_VOICE_MAIL__
kal_uint8 smslib_decode_tpoa_to_MMI(kal_uint8 *, l4_addr_bcd_struct *);
void smslib_evm_free_evm(smslib_evmi_struct *);
kal_uint8 smslib_decode_evmi(kal_uint8 *, kal_uint16 , smslib_evmi_struct *);
#endif
#endif

#endif // __SMS_STORAGE_BY_MMI__

#endif
