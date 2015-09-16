/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   ipc_ut.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   IPCORE unit test defines and helper macros.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                 HISTORY
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
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __INC_IPC_UT_H
#define __INC_IPC_UT_H

#include "upcm.h"

typedef enum {
    IPC_UT_NO_ERROR = 0,
    IPC_UT_SESSION_BIND_NEW_SESSION_FAIL,
    IPC_UT_SESSION_DEACTIVATE_NO_SESSION_FOUND,
    IPC_UT_REGISTER_FILTER_VALIDATE_FAIL,
    IPC_UT_REGISTER_FILTER_NG,
    IPC_UT_DEREGISTER_FILTER_WITH_INVALID_ID,
    IPC_UT_DEREGISTER_FILTER_NOT_FOUND,
    IPC_UT_NEW_NTFY_NG,
    IPC_UT_DEL_NTFY_WITH_INVALID_ID,
    IPC_UT_DEL_NTFY_NOT_FOUND,
    IPC_UT_DL_PKT_NETIF_NOT_FOUND,
} ipc_ut_error_e;

#ifdef ATEST_SYS_IPCORE
    extern ipc_ut_error_e ipc_ut_error_g;

    #define ipc_ut_set_error(_ut_error) \
                ipc_ut_error_g = (_ut_error)

    #define ipc_ut_get_error() \
                ipc_ut_error_g

    #define IPC_UT_ASSERT(_cond, _ut_error) \
            if (!(_cond)) ipc_ut_set_error(_ut_error)

    void ipc_ut_on_ul_packet_filtered_req(void *req_ptr);
    void ipc_ut_on_dl_packet_filtered_req(void *req_ptr);
    void ipc_ut_on_ul_packet_filtered_with_info_req(void *req_ptr);
    void ipc_ut_on_dl_packet_filtered_with_info_req(void *req_ptr);
    kal_bool ipc_ut_msg_send6(module_type _src_mod_id, module_type _dest_mod_id, sap_type _sap_id, msg_type _msg_id,
                   local_para_struct *_local_para_ptr, peer_buff_struct *_peer_buff_ptr);
    void ipc_ut_rcv_ul_sdu(ip_type_e ip_type, kal_uint32 pdn_id, qbm_gpd *p_head, qbm_gpd *p_tail);
    void ipc_ut_rcv_ul_sdu_by_ebi(kal_uint32 ebi, qbm_gpd *p_head, qbm_gpd *p_tail);
    void ipc_ut_reg_cbk_notify_tick_source(upcm_nofify_lte_tick_f pf_notify);
    void ipc_ut_reg_cbk_dlvr_dl_sdu(upcm_dlvr_dl_sdu_f pf_dlvr_sdu);
#else /* not defined(ATEST_SYS_IPCORE) */
    #define ipc_ut_set_error(_ut_error)

    #define ipc_ut_get_error() \
                IPC_UT_NO_ERROR

    #define IPC_UT_ASSERT(_cond, _ut_error) \
            IPC_ASSERT(_cond)

#endif /* ATEST_SYS_IPCORE */

#endif /* __INC_IPC_UT_H */
