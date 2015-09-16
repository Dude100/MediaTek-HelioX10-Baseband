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
 * smslib_decode.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _SMSLIB_DECODE_H
#define _SMSLIB_DECODE_H

#if defined(__SMS_STORAGE_BY_MMI__)

#include "smslib_def.h"
#include "smslib_enum.h"
#include "mcd_l4_common.h"
#include "kal_general_types.h"
#include "ps_public_struct.h"
#include "ps_public_utility.h"

#define smslib_deliver_peer_struct_unpack smsal_deliver_peer_struct_unpack
#define smslib_submit_peer_struct_unpack smsal_submit_peer_struct_unpack
#define smslib_status_report_peer_struct_unpack smsal_status_report_peer_struct_unpack

extern void smsal_gsm7_unpack(kal_uint8 *old_data_ptr, kal_uint8 *new_data_ptr, kal_uint16 data_len, kal_uint16 offset );
extern kal_uint16 smsal_compute_udh_offset(kal_uint8 udhl);
extern void smsal_unpack_msg(kal_uint8 dcs, kal_uint8 *msg_ptr, kal_uint8 *data, kal_uint16 length, kal_uint16 offset);
#define smslib_gsm7_unpack smsal_gsm7_unpack
#define smslib_compute_udh_offset smsal_compute_udh_offset
#define smslib_unpack_msg smsal_unpack_msg

#if 0
/* under construction !*/
#endif
smslib_status_enum smslib_decode_tpdu(kal_uint8 *, kal_uint16, smslib_general_struct *);
void smslib_reset_tpdu_decode_struct(smslib_tpdu_decode_struct *);
smslib_status_enum smslib_start_decode_tpdu(smslib_tpdu_decode_struct *, kal_uint8 *, kal_uint8);

void smslib_convert_TPAddr_to_RP(kal_uint8 *, l4_addr_bcd_struct *);
void smslib_convert_RP_to_MMI(l4_addr_bcd_struct *, l4c_number_struct *);

void smslib_message_waiting_handler(smslib_general_struct *);

/* The following is SMS 2.0 Phase 2 Part, message waiting handling move to MMI */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif // __SMS_STORAGE_BY_MMI__

#endif
