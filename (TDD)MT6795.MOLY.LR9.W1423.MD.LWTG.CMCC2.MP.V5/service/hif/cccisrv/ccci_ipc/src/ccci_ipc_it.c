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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ccci_ipc_it.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file implements the CCCI_IPC IT functions for CCCI IT framework.
 *
 * Author:
 * -------
 * -------
 *
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [K2 MD2] Add CCCI/CCIF new feature for K2 MD2
 *
 * removed!
 * removed!
 * [CCCI IPC] Fix build CCCI IT load fail due to ilm msg id had been changed.
 *
 * 03 18 2013 ap.wang
 * removed!
 *
 * 03 11 2013 ap.wang
 * removed!
 * [CCCI_IPC] Modify for IT Loopback and compile warning fix
 ****************************************************************************/
#ifdef CCCI_IT_MODE_CONTROL_CCCI_IPC
/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "ccci_ipc_common.h"
#include "ccci_ipc_data.h"
/*******************************************************************************
 * Define macro
 *******************************************************************************/
#if _MSC_VER
#define snprintf _snprintf
#endif

/*******************************************************************************
 * Define functions.
 *******************************************************************************/
#include "md_mmi_sap.h"
extern CCCI_IPC_T ccci_ipc_ch;
kal_bool ccci_ipc_it_send_msg(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    kal_uint32 err_str_len = *p_ret_err_str_sz;
    ipc_ilm_t *ilm_ptr = NULL;
    kal_int32  ret = KAL_TRUE;

    ccci_ipc_ch.it_mode = CCCI_IPC_IT_DISABLE;
    
    /* allocate and fill cross message structure */
    ilm_ptr = ipc_msgsvc_allocate_ilm(MOD_L4C);
    ilm_ptr->src_mod_id = MOD_L4C;
    ilm_ptr->dest_mod_id = APMOD_AGPS;
    ilm_ptr->msg_id = (kal_uint32)IPC_EL1_MSG_ID_BEGIN;
    ilm_ptr->peer_buff_ptr = NULL; /* no peer message */
    ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ret =  ipc_msgsvc_send_ext_queue(ilm_ptr);

    if (ret == KAL_FALSE){
        *p_ret_err_str_sz = snprintf(p_ret_err_str, err_str_len, 
                                "error test\n"
                                ); 
        return KAL_FALSE;
    }
    kal_sleep_task(KAL_TICKS_1_SEC);
    return KAL_TRUE;
}


kal_bool ccci_ipc_it_loopback(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    kal_uint32 err_str_len = *p_ret_err_str_sz;
    
    ccci_ipc_ch.it_mode = CCCI_IPC_IT_LB;
    *p_ret_err_str_sz = snprintf(p_ret_err_str, err_str_len, 
                                "error test\n"
                                ); 
    
    return KAL_TRUE;
}

kal_bool ccci_ipc_it_normal(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    kal_uint32 err_str_len = *p_ret_err_str_sz;
    
    ccci_ipc_ch.it_mode = CCCI_IPC_IT_DISABLE;
    *p_ret_err_str_sz = snprintf(p_ret_err_str, err_str_len, 
                                "CCCI_IPC Normal mode\n"
                                ); 
    
    return KAL_TRUE;
}


#include "ccci_it_ctrl_if.h"
IT_MODE_T ccci_ipc_it_mode_table[] = {
    {"ccci_ipc_it_normal",      ccci_ipc_it_normal,         NULL},
    {"ccci_ipc_it_loopback",    ccci_ipc_it_loopback,       NULL},
    {"ccci_ipc_it_send_ilm",    ccci_ipc_it_send_msg,       NULL,   1},   
};

kal_bool ccci_ipc_it_create(){
return ccci_it_mode_control_table_reg("CCCI_IPC", 
                     ccci_ipc_it_mode_table, 
                     sizeof(ccci_ipc_it_mode_table) / sizeof(IT_MODE_T) 
                    );
}
 
#endif //CCCI_IT_MODE_CONTROL_CCCI_IPC

 
