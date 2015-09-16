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
 *   ccci_rpc.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file implement the function for ccci servie initialization. 
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
 * [CCCI & RPC & FS] ASSERT enhancement
 *
 * removed!
 * removed!
 * 	[CCCI RPC] Add init gpd list in wrapper function.
 *
 * 05 09 2013 ap.wang
 * removed!
 * [CCCI RPC] CCCI RPC IT modify and rx callback rule modify
 *
 * removed!
 * removed!
 * Integration change.
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/


#include "ccci_rpc_common.h"
#include "ccci_rpc_data.h"
#include "ccci_if.h"

/*******************************************************************************
 * Global parameters
 *******************************************************************************/



/*******************************************************************************
 * Define functions.
 *******************************************************************************/


/*************************************************************************
* FUNCTION
*  ccci_rpc_allocate_gpds
*
* DESCRIPTION
*  This function is to initialize rpc remote procedure call service
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
extern CCCI_RPC_T ccci_rpc_ch;  //structure in ccci_rpc_data.c
RPC_GPDS_POOL_T rpc_gpd_pool[CCCI_RPC_GPD_NUMBER];
// GPDs for RPC
//qbm_gpd *rpc_gpd[CCCI_RPC_GPD_NUMBER];

kal_int32 ccci_rpc_allocate_gpds(){
    ccci_io_request_t ior = {0};
    kal_uint32 num_gpd = 0;
    kal_uint32 gpd_index = 0;
	kal_uint32 rpc_tail_gpd_allocated_flag = 0;
	kal_uint32 result = 0;
	//allocate tail gpd for rpc receive channel first
	while(rpc_tail_gpd_allocated_flag!=1){
		num_gpd = qbmt_alloc_q_no_tail( 
							CCCI_RPC_GPD_TYPE,			  /* type */
							1,		   /* buff_num */
							(void **)(&ior.first_gpd),	  /* pp_head */
							(void **)(&ior.last_gpd));	  /* pp_tail */
		if(num_gpd == 0){
			continue;
		}

#ifdef __SDIOC_PULL_Q_ENH_DL__
    	ior.num_gpd = 1;
#endif
        result = ccci_rpc_ch.ccci_write_gpd(ccci_rpc_ch.receive_channel, &ior, NULL);	
		//after initialization, wait for event in IPC_RPC_Process_CMD
        				
        if(result == CCCI_SUCCESS){
    	    rpc_tail_gpd_allocated_flag = 1;
        }
        else{
            EXT_ASSERT(0,result,0,0);
        }        
	    
		
	}
	
    while(ccci_rpc_ch.allocated_gpd_number < CCCI_RPC_GPD_NUMBER){
        num_gpd = qbmt_alloc_q_no_tail( 
                            CCCI_RPC_GPD_TYPE,            /* type */
                            1,         /* buff_num */
                            (void **)(&ior.first_gpd),    /* pp_head */
                            (void **)(&ior.last_gpd));    /* pp_tail */
		if(num_gpd == 0){
			continue;
		}
		rpc_gpd_pool[gpd_index].gpd_ptr =  ior.first_gpd;
		rpc_gpd_pool[gpd_index].gpd_occupied = 0;
		gpd_index++;
        ccci_rpc_ch.allocated_gpd_number += 1;
    }
	//check if gpd_index == CCCI_RPC_GPD_NUMBER-1
    return 0;
}


/*************************************************************************
* FUNCTION
*  ccci_ipc_main_init
*
* DESCRIPTION
*  This function is to allocate the RGPD before main 
*
* PARAMETERS
*  none
*
* RETURNS
*  KAL_TRUE
*
*************************************************************************/

kal_bool ccci_rpc_task_main_init(){
    if(ccci_rpc_ch.allocated_gpd_number==0)
    	ccci_rpc_allocate_gpds();
    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  ccci_rpc_svc_init
*
* DESCRIPTION
*  This function is to initial ccci rpc channel and register call back funtion
*
* PARAMETERS
*  none
*
* RETURNS
*  KAL_TRUE
*
*************************************************************************/
extern void ccci_rpc_init(void);
kal_bool ccci_rpc_svc_init(void){
    ccci_rpc_init();
    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  ccci_rpc_task_init
*
* DESCRIPTION
*  This function is to initial ccci rpc channel and register call back funtion
*
* PARAMETERS
*  none
*
* RETURNS
*  KAL_TRUE
*
*************************************************************************/
kal_bool ccci_rpc_task_init(){
    //ccci_rpc_init();
    return KAL_TRUE;
}




/*************************************************************************
* FUNCTION
*  ccci_rpc_main
*
* DESCRIPTION
*
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/

//void ccci_rpc_main(ilm_struct *ilm){
void ccci_rpc_main(void){

  /*
	switch (ilm->msg_id) {
        default:
            ccci_ipc_trace(CCCI_IPC_ERR, CCCI_IPC_MOD_MAIN, CCCI_IPC_ERROR_ILM_MSGID_ERR, ilm->msg_id);
        break;           
    }
   */
}
#if 0
/* under construction !*/
#endif
