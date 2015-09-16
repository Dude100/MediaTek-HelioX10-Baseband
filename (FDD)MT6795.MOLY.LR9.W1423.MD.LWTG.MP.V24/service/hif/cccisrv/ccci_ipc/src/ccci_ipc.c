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
 *   ccci_ipc.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file implement the function for ccci servie initialization 
 *   and main to hanle ilm.
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
 * 	[CCCI] Show CCCI IPC ILM's local parameter in ELT
 *
 * 04 22 2013 ap.wang
 * removed!
 * [CCCI_IPC] Modify ILM address calculate error
 *
 * 03 11 2013 ap.wang
 * removed!
 * [CCCI_IPC] Modify for IT Loopback and compile warning fix
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/


#include "ccci_ipc_common.h"
#include "ccci_ipc_data.h"
#include "ccci_if.h"


/*******************************************************************************
 * Define functions.
 *******************************************************************************/


/*************************************************************************
* FUNCTION
*  ccci_ipc_reload_rgpds
*
* DESCRIPTION
*  This function is to initialize ipc message passing service
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
extern CCCI_IPC_T ccci_ipc_ch;
kal_int32 ccci_ipc_reload_rgpds(){
    ccci_io_request_t ior = {0};
    kal_uint32 num_gpd = ccci_ipc_ch.reload_rgpd_number;
    kal_uint32 to_alloc = CCCI_IPC_RGPD_NUMBER - num_gpd;
    kal_uint32 num_alloc =0;
    if(ccci_ipc_ch.reload_rgpd_number < CCCI_IPC_RGPD_NUMBER){
        num_alloc = qbmt_alloc_q_no_tail( 
                            CCCI_IPC_GPD_TYPE,            /* type */
                            to_alloc,         /* buff_num */
                            (void **)(&ior.first_gpd),    /* pp_head */
                            (void **)(&ior.last_gpd));    /* pp_tail */
#ifdef __SDIOC_PULL_Q_ENH_DL__
        ior.num_gpd = num_gpd;
#endif 
        EXT_ASSERT(num_alloc == to_alloc, num_gpd, to_alloc, num_alloc);
        
        ccci_ipc_ch.reload_rgpd_number += num_alloc;
        ccci_ipc_ch.ccci_write_gpd(ccci_ipc_ch.receive_channel, &ior, NULL);
    }
    return 0;
}

/*************************************************************************
* FUNCTION
*  ccci_ipc_main
*
* DESCRIPTION
*  This function is to handle CCCI_IPC ILM
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/

void ccci_ipc_main(ilm_struct *ilm){
    switch (ilm->msg_id) {
        default:
            ccci_ipc_trace(CCCI_IPC_ERR, CCCI_IPC_MOD_MAIN, CCCI_IPC_ERROR_ILM_MSGID_ERR, ilm->msg_id);
        break;           
    }
}



/*************************************************************************
* FUNCTION
*  ccci_ipc_task_init
*
* DESCRIPTION
*  This function is to init ccci_ipc
*
* PARAMETERS
*  none
*
* RETURNS
*  KAL_TRUE
*
*************************************************************************/

kal_bool ccci_ipc_task_init(){
    ccci_ipc_init();
    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  ccci_ipc_main_init
*
* DESCRIPTION
*  This function is to reload the RGPD before main 
*
* PARAMETERS
*  none
*
* RETURNS
*  KAL_TRUE
*
*************************************************************************/

kal_bool ccci_ipc_task_main_init(){
    ccci_ipc_reload_rgpds();
    return KAL_TRUE;
}

