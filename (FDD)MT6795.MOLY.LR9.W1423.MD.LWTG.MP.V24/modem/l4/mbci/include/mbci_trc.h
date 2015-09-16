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
 *   mbci_trc.h
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

#ifndef _MBCI_TRC_H
#define _MBCI_TRC_H

#include "stack_config.h"
#include "kal_trace.h"

#ifndef GEN_FOR_PC
   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before tst_config.h"
   #endif
#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */

#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before tst_trace.h"
#endif

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "mbci_trc_gen.h"
#endif /* TST Trace Defintion */
#endif

BEGIN_TRACE_MAP(MOD_MBCI)

// TRACE_STATE
TRC_MSG(MBCI_STATE,"state: %Mmbci_state_enum")
TRC_MSG(MBCI_TRANS,"[%d] tid=%u src_id=%Ml4c_source_id_enum uuid=%u cid=%d type=%d")
TRC_MSG(MBCI_READY_STATE,"SIM state=%Mmbim_subscriber_ready_state_enum")
TRC_MSG(MBCI_CONNECT_STATE,"SessionId:%d State:%Mmbim_activation_state_enum %Mmbim_context_ip_type_enum")
TRC_MSG(MBCI_REG_STATE,"RegState:%Mmbim_register_state_enum mode:%Mmbim_register_mode_enum")
TRC_MSG(MBCI_PACKET_SERVICE_STATE,"PacketServiceState:%Mmbim_packet_service_state_enum DataClass:%x")

// TRACE_INFO
TRC_MSG(MBCI_BASIC_CONNECT_CID,"[%d]:%Mmbim_cid_basic_connect_enum [t_id]:%d [src_id]:%Ml4c_source_id_enum")
TRC_MSG(MBCI_SMS_CID,"[%d]:%Mmbim_cid_sms_enum [t_id]:%d [src_id]:%Ml4c_source_id_enum")
TRC_MSG(MBCI_USSD_CID,"[%d]:%Mmbim_cid_ussd_enum [t_id]:%d [src_id]:%Ml4c_source_id_enum")
TRC_MSG(MBCI_PHONEBOOK_CID,"[%d]:%Mmbim_cid_phonebook_enum [t_id]:%d [src_id]:%Ml4c_source_id_enum")
TRC_MSG(MBCI_STK_CID,"[%d]:Mmbim_cid_stk_enum [t_id]:%d [src_id]:%Ml4c_source_id_enum")
TRC_MSG(MBCI_AUTH_CID,"[%d]:%Mmbim_cid_auth_enum [t_id]:%d [src_id]:%Ml4c_source_id_enum")
TRC_MSG(MBCI_DSS_CID,"[%d]:%Mmbim_cid_dss_enum [t_id]:%d [src_id]:%Ml4c_source_id_enum")
TRC_MSG(MBCI_MS_HOSTSHUTDOWN_CID,"[%d]:%Mmbim_cid_ms_hostshutdown_enum [t_id]:%d [src_id]:%Ml4c_source_id_enum")
TRC_MSG(MBCI_MTK_VENDOR_CMD_CID,"[%d]:%Mmbim_cid_mtk_vendor_cmd_enum [t_id]:%d [src_id]:%Ml4c_source_id_enum")

TRC_MSG(MBCI_CONNECT_INFO,"SessionId:%d %Mmbim_activation_command_enum IPType:%Mmbim_context_ip_type_enum")
TRC_MSG(MBCI_PIN, "%Mmbim_pin_type_enum %Mmbim_pin_operation_enum")
TRC_MSG(MBCI_SET_REGISTER, "%Mmbim_register_action_enum %Mmbim_data_class_enum")
TRC_MSG(MBCI_REUSE_PDN, "Reuse cid:%d")

TRC_MSG(MBCI_START_TIMER_FUNC, "MBCI: start timer: timer_id=%d invoke_id=%d timeout=%d")
TRC_MSG(MBCI_STOP_TIMER_FUNC, "MBCI: stop timer: timer_id=%d invoke_id=%d")

// TRACE_WARNING
TRC_MSG(MBCI_UNKNOW_MSG,"Warning: unknow MSG")
TRC_MSG(MBCI_UNKNOW_UUID_CID,"Warning: unknow UUID:%Mmbim_uuid_enum, CID:%d")
TRC_MSG(MBCI_NOT_OPEN,"MBCI state is not open!")
TRC_MSG(MBCI_ERROR_CANCEL,"Warning: Cancel Transaction:%d")
TRC_MSG(MBCI_WARNING_SET_RADIO_FAIL,"Warning: set radio fail")

END_TRACE_MAP(MOD_MBCI)

#endif /* _MBCI_TRC_H */

