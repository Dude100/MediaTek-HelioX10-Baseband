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
 *   ipc_task.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   IP Core task implementation.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "syscomp_config.h"
#include "ipc_defs.h"
#include "ipc_debug.h"
#include "ipc_utils.h"

/*------------------------------------------------------------------------------
 * Global variables.
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * Helper macro.
 *----------------------------------------------------------------------------*/
#define IPC_MOD_CNT (sizeof(ipc_module_list_g) / sizeof(module_type))

/*------------------------------------------------------------------------------
 * Private data structure.
 *----------------------------------------------------------------------------*/
typedef kal_bool (*ipc_init_func_t)(void);
typedef void (*ipc_on_ilm_func_t)(ilm_struct *);
typedef kal_bool (*ipc_on_reset_func_t)(void);

/*------------------------------------------------------------------------------
 * Private variables.
 *----------------------------------------------------------------------------*/
module_type ipc_module_list_g[] = {
    #undef IPC_MODULE_ID
    #undef IPC_MODULE_PREFIX
    #define IPC_MODULE_ID(_id) _id,
    #define IPC_MODULE_PREFIX(_prefix) 
    #include "ipc_config.h"

    MOD_IPCORE,
};

/*
 * Note, each module in IP Core task with prefix xyz must implement the following functions:
 *
 * 1. module initializeation function:
 *    kal_bool xyz_init(void);
 *
 * 2. ilm handler:
 *    void xyz_on_ilm(ilm_struct *ilm);
 *
 * 3. reset handler:
 *    kal_bool xyz_reset(void);
 */
#undef IPC_MODULE_ID
#undef IPC_MODULE_PREFIX
#define IPC_MODULE_ID(_id) 
#define IPC_MODULE_PREFIX(_prefix) extern kal_bool _prefix ## _init (void);
#include "ipc_config.h"

const ipc_init_func_t ipc_init_func_list_g[] = {
    #undef IPC_MODULE_ID
    #undef IPC_MODULE_PREFIX
    #define IPC_MODULE_ID(_id) 
    #define IPC_MODULE_PREFIX(_prefix) _prefix ## _init,
    #include "ipc_config.h"

    ipc_init,
};

#undef IPC_MODULE_ID
#undef IPC_MODULE_PREFIX
#define IPC_MODULE_ID(_id) 
#define IPC_MODULE_PREFIX(_prefix) extern void _prefix ## _on_ilm (ilm_struct *ilm);
#include "ipc_config.h"

const ipc_on_ilm_func_t ipc_ilm_func_list_g[] = {
    #undef IPC_MODULE_ID
    #undef IPC_MODULE_PREFIX
    #define IPC_MODULE_ID(_id) 
    #define IPC_MODULE_PREFIX(_prefix) _prefix ## _on_ilm,
    #include "ipc_config.h"

    ipc_on_ilm,
};

#undef IPC_MODULE_ID
#undef IPC_MODULE_PREFIX
#define IPC_MODULE_ID(_id) 
#define IPC_MODULE_PREFIX(_prefix) extern kal_bool _prefix ## _reset (void);
#include "ipc_config.h"

const ipc_on_reset_func_t ipc_reset_func_list_g[] = {
    #undef IPC_MODULE_ID
    #undef IPC_MODULE_PREFIX
    #define IPC_MODULE_ID(_id) 
    #define IPC_MODULE_PREFIX(_prefix) _prefix ## _reset,
    #include "ipc_config.h"

    ipc_reset,
};

/*------------------------------------------------------------------------------
 * Private fucntions.
 *----------------------------------------------------------------------------*/
static kal_bool ipc_task_init(void)
{
    kal_uint32  idx;
    kal_bool    ret = KAL_TRUE;;

    for (idx = 0; idx < IPC_MOD_CNT; ++idx) {
        ret = ipc_init_func_list_g[idx]();
        if (!ret) {
            break;
        }
    }
    return ret;
}

void ipc_dispatch_ilm(ilm_struct *ilm)
{
    kal_uint32  idx;

    for (idx = 0; idx < IPC_MOD_CNT; ++idx) {
        if (ilm->dest_mod_id == ipc_module_list_g[idx]) {
            /*
             * Switch to active module.
             */
            kal_set_active_module_id(ilm->dest_mod_id);

            /*
             * Dispatch ILM according to dest_mod_id.
             */
            ipc_ilm_func_list_g[idx](ilm);
            break;
        }
    }

    if (IPC_MOD_CNT == idx) {
        /*
         * Wrong destination.
         */
        hif_trace_error(IPC_TR_ILM_WRONG_DEST_MOD, ilm->dest_mod_id);
    }

    /*
     * Free the ILM.
     */
    destroy_ilm(ilm);
}

static void ipc_task_main(task_entry_struct *task_entry_ptr)
{
    ilm_struct  current_ilm;

#if IPC_PEER==IPC_PEER_NULL_DROP || IPC_PEER==IPC_PEER_NULL_LOOPBACK
    ipc_notify_all_netif_link_change(IPC_IP_TYPE_MIXED, KAL_TRUE);
#endif

    while (1) {
        /* 
         * Receive message from ext queue, this may suspend.
         */
        if (KAL_TRUE == msg_receive_extq(&current_ilm)) {
            ipc_dispatch_ilm(&current_ilm);
            while (msg_receive_intq(&current_ilm)){
                ipc_dispatch_ilm(&current_ilm);
            }
        }
    }
}

#ifndef ATEST_SYS_IPCORE
static
#endif
kal_bool ipc_task_reset(void)
{
    kal_uint32  idx;
    kal_bool    ret = KAL_TRUE;

    for (idx = 0; idx < IPC_MOD_CNT; ++idx) {
        ret = ipc_reset_func_list_g[idx]();
        if (!ret) {
            break;
        }
    }
    return ret;
}

/*------------------------------------------------------------------------------
 * Public fucntions.
 *----------------------------------------------------------------------------*/
kal_bool ipc_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct info =
    {
        ipc_task_main,     /* task entry function */
        ipc_task_init,     /* task initialization function */
        ipc_task_reset,    /* task reset handler */
    };

    *handle = (comptask_handler_struct *)&info;
    return KAL_TRUE;
}


