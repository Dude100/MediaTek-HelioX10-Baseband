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
 *   mbci_utility.h
 *
 * Project:
 * --------
 *   MT6280
 *
 * Description:
 * ------------
 *   This file is intends for MBCI implementation.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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


#ifndef _MBCI_UTILITY_H
#define _MBCI_UTILITY_H

#include "stack_msgs.h"
#include "kal_general_types.h"

#include "mbim_defs.h"
#include "mbci_context.h"

#if 0
/* under construction !*/
#else
#define MBCI_PROMPT_TRACE(...)
#endif

#define MBCI_CID_FUNC(CID,HDLR) HDLR

#define MBCI_NULL_FUNC  mbci_null_function

#define MBCI_ALIGN_4(x) (((x+3) >> 2) << 2)

#define MBCI_ABS(x) ((x > 0)?(x):(-(x)))

//#define mbci_sid_to_cid(x)  (x + 1)

//#define mbci_cid_to_sid(x)  (x - 1)

//#define mbci_zero_init(addr,len)    kal_mem_set((void*)addr, 0x00, len)

extern void mbci_null_function(mbci_transaction_struct * trans_ptr,kal_uint32 cid_strcut_len,kal_uint8 * cid_strcut_ptr);

extern kal_uint32 mbci_get_max_cid_by_uuid(kal_uint32 uuid);

extern mbim_uuid_enum mbci_uuid_str_to_id(kal_uint8 *uuid_str);

extern kal_uint8 *mbci_uuid_id_to_str(mbim_uuid_enum i);

extern mbim_context_type_enum mbci_context_type_str_to_id(kal_uint8 *context_type_str);

extern kal_uint8 *mbci_context_type_id_to_str(mbim_context_type_enum i);

extern void mbci_send_msg(module_type dest, msg_type msg_name, sap_type sap, void *local_ptr, void *peer_ptr);

extern void mbci_status_ind(kal_uint32 cid,
                        mbim_uuid_enum mbim_uuid,
                        kal_uint32 infBuffSize,
                        kal_uint8 *infBuff);

extern void mbci_command_rsp(kal_uint8 result, 
                                mbim_status_code_enum status,
                                kal_uint32 cid,
                                mbim_uuid_enum mbim_uuid,
                                kal_uint32 infBuffSize,
                                kal_uint8 *infBuff,
                                kal_uint32 tid,
                                kal_uint32 command_type);

extern void mbci_command_trans_rsp(kal_uint8 result, 
                                mbim_status_code_enum status,
                                mbci_transaction_struct *trans_ptr,
                                kal_uint32 infBuffSize,
                                kal_uint8 *infBuff);


extern void *mbci_setup_transaction(kal_uint32 tid);

extern void *mbci_get_trans_by_src(kal_uint16 src_id);

extern void mbci_release_transaction(kal_uint32 tid);

extern kal_bool mbci_check_uuid_cid_supported(mbim_uuid_enum mbim_uuid, kal_uint8 type, kal_uint32 cid, kal_uint32 tid, kal_uint8 src_id);

extern kal_bool mbci_infBuff_cpy(kal_uint8 *to, kal_uint32 offset, kal_uint32 length, void *from);

extern kal_bool mbci_parse_infBuff(kal_uint8 *from, kal_uint32 offset, kal_uint32 length, void *to, kal_uint32 max_length);

extern kal_uint16 mbci_ascii_to_utf16(kal_uint8 *src, kal_wchar *dest);

extern kal_uint16 mbci_utf16_to_ascii(kal_wchar *ucs2_src, kal_uint8 *ascii_dest, kal_uint32 max_length);

extern mbim_subscriber_ready_state_enum mbci_get_subscriber_ready_state();

extern kal_uint16 mbci_get_subscriber_ready_info(kal_uint8 src_id, kal_uint8 *infBuff, kal_uint16 infBuffSize);

extern mbim_status_code_enum mbci_get_pin_info(kal_uint8 src_id, mbim_pin_info_struct *pin_info);

extern kal_uint16 mbci_pack_provider(kal_uint32 offset,
                        kal_uint8 *buf, 
                        kal_uint8 *ProviderId,
                        kal_uint32 ProviderState, 
                        kal_uint8 *ProviderName,
                        kal_uint32 CellularClass, 
                        kal_uint32 Rssi, 
                        kal_uint32 ErrorRate);

extern kal_uint16 mbci_get_registration_state_info(kal_uint8 src_id, kal_uint8 *infBuff);

extern kal_uint16 mbci_get_packet_service_info(kal_uint8 src_id, kal_uint8 *infBuff);

extern kal_uint16 mbci_get_signal_state_info(kal_uint8 src_id, kal_uint8 *infBuff);

extern kal_bool mbci_check_data_session_existence(void);

extern kal_bool mbci_deactivate_session(kal_uint8 src_id, kal_uint32 SessionId);

extern kal_uint8 mbci_get_available_pdp_cid(void);

extern kal_uint16 mbci_get_connect_info(kal_uint8 src_id, kal_uint8 *infBuff, kal_uint32 SessionId);

extern kal_bool mbci_get_home_provider(kal_uint8 *mcc_mnc);

extern kal_uint32 mbci_get_available_provisioned_context_id();

extern kal_uint8 mbci_query_provisioned_context_num(void);

extern kal_uint16 mbci_get_provisioned_context_info(kal_uint8 src_id, kal_uint8 *infBuff, kal_uint32 ElementCount);

extern kal_uint16 mbci_get_ip_configuration(kal_uint8 src_id, kal_uint8 *infBuff, kal_uint32 SessionId);

extern kal_uint16 mbci_get_sms_configuration_info(kal_uint8 src_id, kal_uint8 *infBuff, kal_uint16 infBuffSize);

extern void mbci_update_loopback_mode(kal_bool enter_loopback_mode);

extern kal_bool mbci_check_ongoing_transaction(kal_uint16 src_id);

extern kal_bool mbci_reuse_default_pdn(kal_uint8 src_id, kal_uint32 SessionId, kal_uint32 IPType, kal_uint8 *AccessString, kal_uint8 *UserName, kal_uint8 *Password);

#endif /* _MBCI_UTILITY_H */

