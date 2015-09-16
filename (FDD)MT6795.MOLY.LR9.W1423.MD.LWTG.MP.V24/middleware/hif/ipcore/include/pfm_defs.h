/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2014
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
 *   pfm_defs.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file provides the filter set index for different features.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __INC_PFM_DEFS_H
#define __INC_PFM_DEFS_H

#include "kal_public_api.h"

/*------------------------------------------------------------------------------
 * Auto produced register parser function prototypes. DO NOT MODIFY!!
 *----------------------------------------------------------------------------*/
/* pfm_xxx_register_parser function prototype */
#undef PFM_FILTER_SET_FEATURE_NAME
#undef PFM_FILTER_SET_PREFIX
#define PFM_FILTER_SET_FEATURE_NAME(_name) 
#define PFM_FILTER_SET_PREFIX(_prefix) void pfm_ ## _prefix ## _register_parser(void *, kal_uint32, kal_bool);
#include "pfm_config.h"

/* pfm_xxx_deregister_callback function prototype */
#undef PFM_FILTER_SET_FEATURE_NAME
#undef PFM_FILTER_SET_PREFIX
#define PFM_FILTER_SET_FEATURE_NAME(_name) 
#define PFM_FILTER_SET_PREFIX(_prefix) void pfm_ ## _prefix ## _deregister_callback(kal_int32);
#include "pfm_config.h"

/*------------------------------------------------------------------------------
 * Configuration.
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * Constant definition.
 *----------------------------------------------------------------------------*/
#define PFM_ASSERT ASSERT               /* To completely bypass the overhead of ASSERT(), we could define PFM_ASSERT(...) to nothing. */

#define PFM_DEL_OBJECT_SLEEP_TICKS      KAL_TICKS_10_MSEC
#define PFM_W_LOCK_OBJECT_SLEEP_TICKS   1

#define PFM_FILTER_SET_MAX_SIZE         256

#define PFM_IPC_REGISTER_FILTER_FAIL    -1

#define PFM_FILTER_STRUCT_MAGIC_CODE    168

#define PFM_DROP_PACKET_DUMP_SIZE       40
/*------------------------------------------------------------------------------
 * Internal data structure defintion.
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * Global variables.
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * Internal function prototype.
 *----------------------------------------------------------------------------*/
void pfm_dispatch_register_cmd(local_para_struct *local_para_ptr);

void pfm_deregister_filters(local_para_struct *local_para_ptr);

kal_bool pfm_register_filter_cbk(
    kal_uint32              filter_set_id,
    kal_int32               filter_id,
    kal_bool                uplink,
    ipc_filter_rules_t     *rules,
    ipc_filter_callback_t   callback_func,
    void                   *callback_context);

kal_bool pfm_register_filter_msg(
    kal_uint32              filter_set_id,
    kal_int32               filter_id,
    kal_bool                uplink,
    ipc_filter_rules_t     *rules,
    module_type             callback_module,
    void                   *callback_context);

kal_bool pfm_register_filter_with_info_cbk(
    kal_uint32                        filter_set_id,
    kal_int32                         filter_id,
    kal_bool                          uplink,
    ipc_filter_rules_t               *rules,
    ipc_filter_with_info_callback_t   callback_func,
    void                             *callback_context);

kal_bool pfm_register_filter_with_info_msg(
    kal_uint32              filter_set_id,
    kal_int32               filter_id,
    kal_bool                uplink,
    ipc_filter_rules_t     *rules,
    module_type             callback_module,
    void                   *callback_context);

void pfm_drop_packet_trace(kal_int16 ebi, kal_uint8 *p_data, kal_uint32 bytes);

#endif /* __INC_PFM_DEFS_H */
