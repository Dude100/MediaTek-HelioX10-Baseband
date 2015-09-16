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
 *   cccisrv_task.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements the CCCISRV Core for dispatch the ilm for CCCI services
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * a. Check-in cccifs new features (support 16KB I/O)
 * b. add __CCCIFS_SUPPORT__ option to related files
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * MT6290 Rename CCCI Services
 *
 * 01 11 2013 ap.wang
 * removed!
 * [CCCI_IPC] CCCI_IPC 1st Version
 *
 * removed!
 * removed!
 * check-in cccisrv, update msgid, modify make file path
 ****************************************************************************/
#include "syscomp_config.h"
#include "kal_public_api.h"
#include "cccisrv_debug.h"
#include "ccci_rpc_if.h"

#define CCCISRV_MOD_CNT ((sizeof(cccisrv_module_list_g) / sizeof(module_type)) - 1)

typedef kal_bool (*cccisrv_init_func_t)(void);
typedef void (*cccisrv_ilm_func_t)(ilm_struct *);

module_type cccisrv_module_list_g[] = {
    #undef CCCISRV_MODULE_ID
    #undef CCCISRV_MODULE_PREFIX
    #define CCCISRV_MODULE_ID(_id) _id,
    #define CCCISRV_MODULE_PREFIX(_prefix) 
    #include "cccisrv_config.h"

    MOD_NIL
};
/*
 * Note, each CCCI device with prefix xyz must implement the following functions:
 *
 * 1. module initializeation function:
 *    kal_bool xyz_init(task_indx_type type);
 *
 * 2. ilm handler:
 *    void xyz_main(ilm_struct *ilm);
 */
#undef CCCISRV_MODULE_ID
#undef CCCISRV_MODULE_PREFIX
#define CCCISRV_MODULE_ID(_id) 
#define CCCISRV_MODULE_PREFIX(_prefix) extern kal_bool _prefix ## _task_init (void);
#include "cccisrv_config.h"

const cccisrv_init_func_t cccisrv_init_func_list_g[] = {
    #undef CCCISRV_MODULE_ID
    #undef CCCISRV_MODULE_PREFIX
    #define CCCISRV_MODULE_ID(_id) 
    #define CCCISRV_MODULE_PREFIX(_prefix) _prefix ## _task_init,
    #include "cccisrv_config.h"

    NULL
};

#undef CCCISRV_MODULE_ID
#undef CCCISRV_MODULE_PREFIX
#define CCCISRV_MODULE_ID(_id) 
#define CCCISRV_MODULE_PREFIX(_prefix) extern void _prefix ## _main (ilm_struct *ilm);
#include "cccisrv_config.h"

cccisrv_ilm_func_t cccisrv_ilm_func_list_g[] = {
    #undef CCCISRV_MODULE_ID
    #undef CCCISRV_MODULE_PREFIX
    #define CCCISRV_MODULE_ID(_id) 
    #define CCCISRV_MODULE_PREFIX(_prefix) _prefix ## _main,
    #include "cccisrv_config.h"

    NULL
};

kal_bool cccisrv_task_init(void)
{
    kal_uint32  idx;
    kal_bool    ret = KAL_TRUE;

#if !defined(__MTK_TARGET__)
    /* 20130103 iwei MOLY_FIXME for MoDIS SYS_TEST, need to do the Application_Initialize by cccisrv task */
    lte_ccci_hw_init();
    lte_ccci_init_handshake_phase1();
    lte_ccci_init_handshake_phase2(0);
#endif

    /*
     * Per-module initialization.
     */
    for (idx = 0; idx < CCCISRV_MOD_CNT; ++idx) {
        ret = cccisrv_init_func_list_g[idx]();
        if (!ret) {
            break;
        }
    }
    
#if !defined(__MTK_TARGET__)
   /*
    * 20121226 ian
    * The lte_ccci_hal_init is called in Drv_Init_Phase1() in Target environment
    * The MoDIS initial flow won't call the driver initialized functions
    * Thus, we put the ccci device initialization here.
	* [20121227 iwei]Notes: This function shall be called after lte_ccci_hw_init() 
    */
	lte_ccci_hal_init();
#endif

    return ret;
}

void cccisrv_task_on_ilm(ilm_struct *ilm)
{
    kal_uint32  idx;

    for (idx = 0; idx < CCCISRV_MOD_CNT; ++idx) {
        if (ilm->dest_mod_id == cccisrv_module_list_g[idx]) {
            /* Switch to active module. */
            kal_set_active_module_id(ilm->dest_mod_id);
            /* Dispatch ILM according to dest_mod_id. */
            cccisrv_ilm_func_list_g[idx](ilm);
            break;
        }
    }
    if (CCCISRV_MOD_CNT == idx) {
        hif_trace_error(CCCISRV_TR_ILM_WRONG_DEST_MOD, ilm->dest_mod_id);
    }
    /* Free the ILM. */
    destroy_ilm(ilm);
}

/*******************************************************************
[MOLY_INT] move these functions to ccci_init
*******************************************************************/
extern kal_bool ccci_fs_task_main_init(void);
extern kal_bool ccci_ipc_task_main_init(void);

void cccisrv_task_main(task_entry_struct *task_entry_ptr)
{
    ilm_struct  current_ilm;
    ccci_rpc_task_main_init();
    ccci_ipc_task_main_init();
#if defined(__CCCIFS_SUPPORT__)    
    ccci_fs_task_main_init();
#endif
    kal_set_active_module_id(MOD_CCCISRV);
    while (1) {
        /*Receive message from ext queue, this may suspend.*/
        if (KAL_TRUE == msg_receive_extq(&current_ilm)) {
            cccisrv_task_on_ilm(&current_ilm);
        }
    }
}

/*------------------------------------------------------------------------------
 * Public fucntions.
 *----------------------------------------------------------------------------*/
kal_bool cccisrv_task_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct cccisrv_task_info =
    {
        cccisrv_task_main,          /* task entry function */
        cccisrv_task_init,          /* task initialization function */
        NULL                        /* task reset handler */
    };

    *handle = (comptask_handler_struct *)&cccisrv_task_info;
    return KAL_TRUE;
}
