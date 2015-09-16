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
 *   ccci_ipc_data.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This function implements inter-processor-communication message service.
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
 * [CCCI IPC] Fix cache co-herence problem
 *
 * removed!
 * removed!
 * [CCCI IPC] Support Clibtime feature
 *
 * removed!
 * removed!
 * [CCCI IPC] Change to get next gpd in ccci_ipc_receive_msg_cb
 *
 * removed!
 * removed!
 * [CCCI] CCCI new debug mechanism
 *
 * removed!
 * removed!
 * [CCCI] Add ROME chip version by API instead compile option
 *
 * removed!
 * removed!
 * 	[CCCI] Show CCCI IPC ILM's local parameter in ELT
 *
 * 04 01 2014 ap.wang
 * removed!
 * Fix MODIS build error
 *
 * 03 31 2014 ap.wang
 * removed!
 * remove IDC debug log
 *
 * 03 31 2014 ap.wang
 * removed!
 * Add local para initial value setting
 *
 * 03 31 2014 ap.wang
 * removed!
 * .
 *
 * 03 04 2014 ap.wang
 * removed!
 * Add  ipc_msgsvc_send_ext_queue_no_wait API
 *
 * removed!
 * removed!
 * [CCCI IPC] Fixed CCCI IPC LB test
 *
 * removed!
 * removed!
 * [CCCI] Solve polling gpd caused memory corruption in MT6595.
 * Solutiin: For MT6595_S00, increase static buffer size (add QBM_HEAD_SIZE) and polling
 *  gpd offeset to the size.
 *
 * 11 07 2013 ap.wang
 * removed!
 * 	Fix klocwork warning:Pointer checked for NULL  may be dereferenced .
 *
 * 11 07 2013 ap.wang
 * removed!
 * 	Fix klocwork warning:Pointer checked for NULL  may be dereferenced .
 *
 * 10 08 2013 ap.wang
 * removed!
 * 	Add MOD_EL1 and AP_MOD_WMT
 *
 * 09 12 2013 ap.wang
 * removed!
 * 	Add CCCI Log
 *
 * 07 05 2013 ap.wang
 * removed!
 * .
 *
 * 05 09 2013 ap.wang
 * removed!
 * [CCCI_IPC] Add allocate GPD fail error handling
 *
 * 04 22 2013 ap.wang
 * removed!
 * [CCCI_IPC] Modify ILM address calculate error
 *
 * 03 18 2013 ap.wang
 * removed!
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
#include "cache_sw.h"        //for CPU_CACHE_LINE_SIZE

/*******************************************************************************
 * Define import global variables.
 *******************************************************************************/


/*******************************************************************************
 * Define import function prototype.
 *******************************************************************************/

/*******************************************************************************
 * Define macro
 *******************************************************************************/
#define CCCI_IPC_ENTER_CRITICAL_SECTION  if (KAL_TRUE == kal_query_systemInit() ) \
                                           {                                                                                  \
                                              ccci_ipc_ch.fake_semaphore--;                                                   \
                                           }                                                                                  \
                                           else                                                                               \
                                           {                                                                                  \
                                              kal_take_sem(ccci_ipc_ch.semaphore, KAL_INFINITE_WAIT);                         \
                                           }                                                                                  \
                                 
#define CCCI_IPC_EXIT_CRITICAL_SECTION   if (KAL_TRUE == kal_query_systemInit() )    \
                                           {                                                                                  \
                                              ccci_ipc_ch.fake_semaphore++;                                                   \
                                           }                                                                                  \
                                           else                                                                               \
                                           {                                                                                  \
                                              kal_give_sem(ccci_ipc_ch.semaphore);                                            \
                                           }                                                          


/*******************************************************************************
 * Define global variables.
 *******************************************************************************/

/* The mapping table used for query */
#define X_IPC_MODULE_CONF(a,b,c,d) {c,b}
IPC_MSGSVC_TASKMAP_T ccci_ipc_maptbl[] = 
{
    #include "ccci_ipc_module_conf.h"
};

#define MAX_CCCI_IPC_TASKS (sizeof(ccci_ipc_maptbl) / sizeof(IPC_MSGSVC_TASKMAP_T))

/* ccci_ipc_ch channel config*/
CCCI_IPC_T ccci_ipc_ch = 
{ 
    CCCI_MSGSVC_SEND_CHANNEL, 
    CCCI_MSGSVC_SEND_ACK_CHANNEL, 
    CCCI_MSGSVC_RCV_CHANNEL, 
    CCCI_MSGSVC_RCV_ACK_CHANNEL, 
    0, //event
    0, //semaphore
    1, //fake_semaphore
    ccci_write_gpd,
    ccci_init_gpdior,
    ccci_deinit,
    NULL, // polling gpd
    0, // reload rgpd cnt
    CCCI_IPC_IT_DISABLE // default IT mode is disable
};

/* ipc_ilm arrary used for each task */
CCCI_IPC_ILM_T ccci_ipc_ilm_arr[MAX_CCCI_IPC_TASKS] = {{{0}}};

#define CCCI_IPC_POLLING_MODE_BUF_SZ QBM_SIZE_CCCI_COMM

// The reason + QBM_HEAD_SIZE is for ROME E1, cldma needs to record this buff whether is cacheable or non-cacheable
static kal_uint8 g_ccci_ipc_polling_buf[CCCI_IPC_POLLING_MODE_BUF_SZ + QBM_HEAD_SIZE];

static CCCI_IPC_DEBUG_STATUS_T ccci_ipc_debug_status;

#define CCCI_IPC_CB_TABLE_SIZE MSG_ID_CCCI_MSG_CODE_TAIL - MSG_ID_CCCI_MSG_CODE_BEGIN
static CCCI_IPC_CB_FUNP ccci_ipc_cb_table[CCCI_IPC_CB_TABLE_SIZE] = {0};

/*******************************************************************************
 * Define functions.
 *******************************************************************************/

/*************************************************************************
* FUNCTION
*  ccci_ipc_errcb
*
* DESCRIPTION
*  This function assert and only be used for channel which should not have callback
*
* PARAMETERS
*  CCCI_CHANNEL_T - ccci channel
*  ccci_io_request_t - ccci gpd ior list 
*
* RETURNS
*  none
*
*************************************************************************/
//	void ccci_ipc_error_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* ior)
//	{
//	    ccci_ipc_trace(CCCI_IPC_ERR, CCCI_IPC_MOD_DATA, CCCI_IPC_ERROR_CB_FUNC_ERR);
//	}


/*************************************************************************
* FUNCTION
*  kal_bool ccci_ipc_process_cb_funp
*
* DESCRIPTION
*  Process ilm directly in CCCI ipc, and return true to send ilm to upper layer 
*
*
* PARAMETERS
*  task_id : destination task id
*  ilm : the ilm ptr need to be handled 
* RETURNS
*  kal_bool : true: process cb function successfully ; false : no needs to process cb function
*
*************************************************************************/
kal_bool ccci_ipc_process_cb_funp(ipc_ilm_t *ilm)
{
    kal_uint32 msg_id_pos = GET_CCCI_IPC_MSGID_POS(ilm->msg_id);
    kal_uint32 start_time = 0, duration =0;
    ilm_struct ilm_user;
    if(ccci_ipc_cb_table[msg_id_pos]){ // needs to process cb function
        ccci_ipc_trace(CCCI_IPC_TRACE, CCCI_IPC_MOD_DATA, CCCI_IPC_PROCESS_CB_START, ilm->msg_id, msg_id_pos);
        start_time = ccci_ipc_get_current_time();
        /* construct kal ilm structure from ccci ipc ilm */
        ilm_user.src_mod_id     = (module_type) ilm->src_mod_id;
        ilm_user.dest_mod_id    = (module_type) ilm->dest_mod_id;
        ilm_user.sap_id         = (sap_type) ilm->sap_id;
        ilm_user.msg_id         = (msg_type) ilm->msg_id;
        ilm_user.local_para_ptr = ilm->local_para_ptr;
        ilm_user.peer_buff_ptr  = ilm->peer_buff_ptr;
        /* Callback */
        ccci_ipc_cb_table[msg_id_pos](&ilm_user);
        /* free local & peer parameter */
        free_local_para_r(ilm_user.local_para_ptr);
        free_peer_buff_r(ilm_user.peer_buff_ptr);
        duration = ccci_ipc_get_duration(start_time, ccci_ipc_get_current_time());
        ccci_ipc_trace(CCCI_IPC_TRACE, CCCI_IPC_MOD_DATA, CCCI_IPC_PROCESS_CB_PASS, ilm->msg_id, msg_id_pos, duration);
        return KAL_TRUE;
    }
    else{
        return KAL_FALSE;
    }
}

/*************************************************************************
* FUNCTION
*  kal_bool ccci_register_ipc_cb_funp
*
* DESCRIPTION
*  Register ccci ipc cb function
*
*
* PARAMETERS
*  funp : function pointer 
* RETURNS
*  kal_bool : true: Successful registration ; false : already registration 
*
*************************************************************************/
kal_bool ccci_register_ipc_cb_funp(kal_uint32 msg_id, CCCI_IPC_CB_FUNP funp)
{
    kal_uint32 msg_id_pos = GET_CCCI_IPC_MSGID_POS(msg_id);
    if(ccci_ipc_cb_table[msg_id_pos]) // cb is not null
        return KAL_FALSE; // already registration
    else{
        ccci_ipc_cb_table[msg_id_pos] = funp;
        return KAL_TRUE;
    }
}

/*************************************************************************
* FUNCTION
*  ccci_ipc_receive_msg_cb
*
* DESCRIPTION
*  This function will process the received data from AP side
*
* PARAMETERS
*  CCCI_CHANNEL_T - ccci channel
*  ccci_io_request_t - ccci gpd ior list 
*
* RETURNS
*  none
*
*************************************************************************/
#ifdef CCCI_IT_MODE_CONTROL_CCCI_IPC
kal_int32 ccci_ipc_reload_rgpds();
#endif
void ccci_ipc_receive_msg_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* ior)
{
    kal_uint32	i = 0;
    ipc_ilm_t	*temp_ipc_ilm = NULL;
    void        *local_param = NULL, *peer_buff = NULL;
    kal_uint32  len = 0;
    kal_uint32  gpd_num = 0;
    ccci_io_request_t *current_ior = ior;
    ccci_io_request_t *reload_ior = NULL;
    qbm_gpd           *current_gpd;
    qbm_gpd           *next_gpd;
    kal_bool    is_process_cb = KAL_FALSE;

    ccci_ipc_trace(CCCI_IPC_TRACE, CCCI_IPC_MOD_DATA, CCCI_RECEIVE_MSG_FUNC_TRA);
    while(current_ior != NULL){
        current_gpd = current_ior->first_gpd ;
        gpd_num = 0;
        while( current_gpd != NULL){
            CCCI_BUFF_T *bufp = CCCIDEV_GET_QBM_DATAPTR(current_gpd);
            next_gpd = current_gpd->p_next;
            local_param = NULL;
            peer_buff = NULL;
            ccci_ipc_trace(CCCI_IPC_TRACE, CCCI_IPC_MOD_DATA, CCCI_RECEIVE_MSG_TRA_CCCI,
                bufp->data[0], bufp->data[1], bufp->channel, bufp->reserved);
            ccci_debug_check_seq(bufp); // check ccci seq
            /* get task id from mapping table of ext queue id */
            for (i = 0; i < MAX_CCCI_IPC_TASKS; i++) 
            {
            	if ( ccci_ipc_maptbl[i].extq_id == bufp->reserved )
            	{
               	    break;
            	}
            }
        		
            /* check if the extquque id can not be found */
            if (i >= MAX_CCCI_IPC_TASKS) 
            {
        	    EXT_ASSERT(0, i, bufp->reserved, MAX_CCCI_IPC_TASKS);
            }

            /* check if the extquque id is to MD */
            if ((ccci_ipc_maptbl[i].extq_id & AP_UINFY_ID_FLAG) != 0)
            {
        	    EXT_ASSERT(0, i, bufp->reserved, ccci_ipc_maptbl[i].extq_id);
            }
        		
    	    temp_ipc_ilm = (ipc_ilm_t *)(bufp + 1);
            ccci_ipc_trace(CCCI_IPC_TRACE, CCCI_IPC_MOD_DATA, CCCI_RECEIVE_MSG_TRA_ILM,
                temp_ipc_ilm, temp_ipc_ilm->src_mod_id, temp_ipc_ilm->dest_mod_id,
                temp_ipc_ilm->sap_id, temp_ipc_ilm->msg_id,
                temp_ipc_ilm->local_para_ptr, temp_ipc_ilm->peer_buff_ptr);
		
    	    if(temp_ipc_ilm->local_para_ptr)
    	    {
    			// copy local_para_struct
    		    temp_ipc_ilm->local_para_ptr = 	(local_para_struct *)((char*)temp_ipc_ilm + sizeof(ipc_ilm_t));
                len += temp_ipc_ilm->local_para_ptr->msg_len; // need 4 bytes alignment or not??
                //assert if ilm size > CCCI_IPC_GPD size
	            EXT_ASSERT(len < CCCI_IPC_GPD_SIZE, len, CCCI_IPC_GPD_SIZE,0);
    			local_param = construct_local_para(temp_ipc_ilm->local_para_ptr->msg_len, 1);
    			kal_mem_cpy((kal_uint8 *)local_param, temp_ipc_ilm->local_para_ptr, temp_ipc_ilm->local_para_ptr->msg_len);
                ((local_para_struct *)local_param)->ref_count = 1 ; 
                temp_ipc_ilm->local_para_ptr = local_param;	    			
    	    }

    	    if (temp_ipc_ilm->peer_buff_ptr)
    	    {
                //copy peer_buff_struct
                if(temp_ipc_ilm->local_para_ptr)
    	        {
    		        temp_ipc_ilm->peer_buff_ptr = 	(peer_buff_struct *)((char*)temp_ipc_ilm->local_para_ptr 
    		                                                         + temp_ipc_ilm->local_para_ptr->msg_len);	
                }
                else
                {
                    temp_ipc_ilm->peer_buff_ptr = 	(peer_buff_struct *)((char*)temp_ipc_ilm + sizeof(ipc_ilm_t));
                }
                len += sizeof(peer_buff_struct) 
                       + temp_ipc_ilm->peer_buff_ptr->pdu_len 
                       + temp_ipc_ilm->peer_buff_ptr->free_header_space 
                       + temp_ipc_ilm->peer_buff_ptr->free_tail_space;
                //assert if ilm size > CCCI_IPC_GPD size 
                EXT_ASSERT(len < CCCI_IPC_GPD_SIZE, len, CCCI_IPC_GPD_SIZE, 0);
    			peer_buff = construct_peer_buff(temp_ipc_ilm->peer_buff_ptr->pdu_len, \
    			temp_ipc_ilm->peer_buff_ptr->free_header_space, \
    			temp_ipc_ilm->peer_buff_ptr->free_tail_space, 1);
    			kal_mem_cpy((kal_uint8 *)peer_buff, temp_ipc_ilm->peer_buff_ptr, 
                             sizeof(peer_buff_struct) 
                             + temp_ipc_ilm->peer_buff_ptr->pdu_len 
                             + temp_ipc_ilm->peer_buff_ptr->free_header_space 
                             + temp_ipc_ilm->peer_buff_ptr->free_tail_space);	
                temp_ipc_ilm->peer_buff_ptr = peer_buff;
    	    }

            CCCI_AP_MSG_TO_KAL_MSG(temp_ipc_ilm->msg_id, temp_ipc_ilm->msg_id);

	        if(ccci_ipc_ch.it_mode == CCCI_IPC_IT_DISABLE){ // if current is not IT mode, then need to send upper layer
                //4 <1> process ccci ipc cb function
                is_process_cb = ccci_ipc_process_cb_funp(temp_ipc_ilm);
                //4 <2> Determine send ilm to upper layer or destroy ilm
                if(!is_process_cb){ // no process cb, then send ilm to upper layer
    	            msg_send6 (MOD_CCCIIPC, ccci_ipc_maptbl[i].task_id, temp_ipc_ilm->sap_id, temp_ipc_ilm->msg_id, local_param, peer_buff);
	            }
            }
            #ifdef CCCI_IT_MODE_CONTROL_CCCI_IPC
            if(ccci_ipc_ch.it_mode == CCCI_IPC_IT_LB){
                CCCI_KAL_MSG_TO_AP_MSG(temp_ipc_ilm->msg_id, temp_ipc_ilm->msg_id);
                bufp->reserved |=  (AP_UINFY_ID_FLAG | temp_ipc_ilm->src_mod_id ); // for Loopback to ccci ipc port 1
                bufp->channel   =  ccci_ipc_ch.send_channel; // for Loopback
                ccci_debug_add_seq(bufp, CCCI_DEBUG_ASSERT_BIT); // add ccci seq
            }
            #endif 
            QBM_CACHE_INVALID(temp_ipc_ilm,sizeof(temp_ipc_ilm)); // prevent cache co-herence problem
            gpd_num++;
    	    if (current_gpd == current_ior->last_gpd){
                break;
    	    }
            else{    
                current_gpd = next_gpd;
            }   
            
        }// process gpds
        reload_ior = current_ior;
        current_ior = current_ior->next_request;
        reload_ior->next_request = NULL;
        
        #ifdef __SDIOC_PULL_Q_ENH_DL__
            reload_ior->num_gpd = gpd_num;
        #endif
        
        #ifdef __CCCI_IPC_UT__
            qbmt_dest_q(reload_ior->first_gpd, reload_ior->last_gpd);
        #else
            #ifdef CCCI_IT_MODE_CONTROL_CCCI_IPC
            if(ccci_ipc_ch.it_mode == CCCI_IPC_IT_LB){
                ccci_ipc_ch.ccci_write_gpd(ccci_ipc_ch.send_channel, reload_ior, NULL);
                ccci_ipc_ch.reload_rgpd_number -= gpd_num;
                ccci_ipc_reload_rgpds();
            }else
            #endif
            {
                CCCIDEV_RST_CCCI_COMM_GPD_LIST(reload_ior->first_gpd, reload_ior->last_gpd);
                ccci_ipc_ch.ccci_write_gpd(ccci_ipc_ch.receive_channel, reload_ior, NULL);
            }
        #endif 
    }//process iors
    ccci_ipc_trace(CCCI_IPC_TRACE, CCCI_IPC_MOD_DATA, CCCI_RECEIVE_MSG_FUNC_PASS_TRA);
}

/*************************************************************************
* FUNCTION
*  ipc_msgsvc_sendmsg_cb
*
* DESCRIPTION
*  This function is the cb of sendmsg
*
* PARAMETERS
*  bufp - ccci header
*
* RETURNS
*  none
*
*************************************************************************/
void ccci_ipc_send_msg_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* ior)
{
    kal_uint32 i = 0;
    ccci_io_request_t *current_ior = ior;
    qbm_gpd           *current_gpd;

    ccci_ipc_trace(CCCI_IPC_TRACE, CCCI_IPC_MOD_DATA, CCCI_SEND_MSG_CB_FUNC_TRA);
    while(current_ior != NULL){
        current_gpd = current_ior->first_gpd ;
        while( current_gpd != NULL){
            CCCI_BUFF_T *bufp = CCCIDEV_GET_QBM_DATAPTR(current_gpd);
            
            /* get task id from mapping table of ext queue id */
            for (i = 0; i < MAX_CCCI_IPC_TASKS; i++) 
            {
                if ( ccci_ipc_maptbl[i].extq_id == bufp->reserved )
                {
                    break;
                }
            }
            kal_set_eg_events(ccci_ipc_ch.event,  (1 << i) , KAL_OR);
            if (current_gpd == current_ior->last_gpd){
                break;
    	    }
            else{
                current_gpd = current_gpd->p_next;
            } 
        }
        qbmt_dest_q(ior->first_gpd, ior->last_gpd);
        current_ior = current_ior->next_request;
    }
    
    ccci_ipc_trace(CCCI_IPC_TRACE, CCCI_IPC_MOD_DATA, CCCI_SEND_MSG_CB_FUNC_PASS_TRA);
}


/*************************************************************************
* FUNCTION
*  ccci_ipc_send_msg
*
* DESCRIPTION
*  This function is the internal api to send message
*
* PARAMETERS
*  ipc_task_id     -  
*  buffer_ptr      -
*  msg_size        -
*  wait_mode       -
*  message_to_head -
*
* RETURNS
*  status - success/fail
*
*************************************************************************/
kal_bool ccci_ipc_send_msg(kal_uint32 ipc_task_id, void *buffer_ptr, kal_uint16 msg_size,	kal_wait_mode wait_mode, kal_bool message_to_head)
{
    kal_uint32 i, j ;
    kal_uint32 retrieved_events = 0, orig_local_addr = 0 , orig_peer_addr = 0, update_buff_addr=0;
    kal_int32 result = CCCI_SUCCESS;
    ipc_ilm_t	*temp_ipc_ilm = (ipc_ilm_t *)buffer_ptr;
    ccci_io_request_t ior = {0};
	CCCI_BUFF_T *p_ccci_buff;
    kal_uint32 len = 0;
	
		
	ccci_ipc_trace(CCCI_IPC_TRACE, CCCI_IPC_MOD_DATA, CCCI_SEND_MSG_FUNC_TRA);	
    ccci_ipc_trace(CCCI_IPC_TRACE, CCCI_IPC_MOD_DATA, CCCI_SEND_MSG_TRA_ILM,
                temp_ipc_ilm, temp_ipc_ilm->src_mod_id, temp_ipc_ilm->dest_mod_id,
                temp_ipc_ilm->sap_id, temp_ipc_ilm->msg_id,
                temp_ipc_ilm->local_para_ptr, temp_ipc_ilm->peer_buff_ptr);
		
    /* get ext queue id from mapping table of task id - destnation*/
    for (i = 0; i < MAX_CCCI_IPC_TASKS; i++) 
    {
        if ( ccci_ipc_maptbl[i].task_id == ipc_task_id )
        	{
                    break;
        	}
    }
	
    /* get ext queue id from mapping table of task id - source*/
    for (j = 0; j < MAX_CCCI_IPC_TASKS; j++) 
    {
        if ( ccci_ipc_maptbl[j].task_id == temp_ipc_ilm->src_mod_id )
        	{
                    break;
        	}
    }
  
    /* check src mod id, if it's not defined in CCCI IPC, don't set used bit */
    if(j >= MAX_CCCI_IPC_TASKS)
    {
        ccci_ipc_trace(CCCI_IPC_ERR, CCCI_IPC_MOD_DATA, CCCI_SEND_MSG_FUNC_TASKID_ERROR, ipc_task_id, temp_ipc_ilm->src_mod_id);
        return KAL_FALSE;
    }
 
    /* check if the extquque id can not be found */
    if (i >= MAX_CCCI_IPC_TASKS) 
    {
	    ccci_ipc_trace(CCCI_IPC_ERR, CCCI_IPC_MOD_DATA, CCCI_SEND_MSG_FUNC_TASKID_ERROR, ipc_task_id, temp_ipc_ilm->src_mod_id);
        ((CCCI_IPC_ILM_T*)buffer_ptr)->used = 0;  
        return KAL_FALSE;
    }
  
        /* check if the extquque id is to AP */
    if ((ccci_ipc_maptbl[i].extq_id & AP_UINFY_ID_FLAG) == 0)
    {
        ccci_ipc_trace(CCCI_IPC_ERR, CCCI_IPC_MOD_DATA, CCCI_SEND_MSG_FUNC_DESTID_ERROR, ipc_task_id);
        ((CCCI_IPC_ILM_T*)buffer_ptr)->used = 0;   
	    return KAL_FALSE;
    }

    /* check if the ilm buffer is from ipc_msgsvc_allocate_ilm or not */
    if (buffer_ptr != &ccci_ipc_ilm_arr[j].ipc_ilm){
        ccci_ipc_trace(CCCI_IPC_ERR, CCCI_IPC_MOD_DATA, CCCI_SEND_MSG_FUNC_ILM_ERROR);
        return KAL_FALSE;
    }
		    
	len = sizeof(CCCI_BUFF_T) + sizeof(ipc_ilm_t);
    if (temp_ipc_ilm->local_para_ptr != NULL){          
        len+= temp_ipc_ilm->local_para_ptr->msg_len ;
    }
    if( temp_ipc_ilm->peer_buff_ptr != NULL){
        len+= sizeof(peer_buff_struct) 
            + temp_ipc_ilm->peer_buff_ptr->pdu_len 
            + temp_ipc_ilm->peer_buff_ptr->free_header_space 
            + temp_ipc_ilm->peer_buff_ptr->free_tail_space;
    }
	//assert if ilm size > CCCI_IPC_GPD size
	EXT_ASSERT(len < CCCI_IPC_GPD_SIZE, len, CCCI_IPC_GPD_SIZE, 0);

    /* Use critical section to protect ENTER */
    CCCI_IPC_ENTER_CRITICAL_SECTION
    if (KAL_TRUE == kal_query_systemInit()){ // polling mode
        ior.first_gpd = ccci_ipc_ch.p_polling_gpd;
        ior.last_gpd  = ccci_ipc_ch.p_polling_gpd;
    }
    else{
#ifdef __SDIOC_PULL_Q_ENH_DL__
        ior.num_gpd = 
#endif 
        qbmt_alloc_q_no_tail( 
                            CCCI_IPC_GPD_TYPE,            /* type */
                            1,                            /* buff_num */
                            (void **)(&ior.first_gpd),    /* pp_head */
                            (void **)(&ior.last_gpd));    /* pp_tail */
        if(ior.first_gpd == NULL){
            ccci_ipc_trace(CCCI_IPC_ERR, CCCI_IPC_MOD_DATA, CCCI_SEND_MSG_FUNC_ALLOC_GPD_ERROR);
            return KAL_FALSE;
        }
    }
    
	//initialize GPD CCCI_Header content
	p_ccci_buff = CCCIDEV_GET_QBM_DATAPTR(ior.first_gpd);
	p_ccci_buff->data[1] = (kal_uint32)len;
	p_ccci_buff->channel = (kal_uint32)ccci_ipc_ch.send_channel;
	p_ccci_buff->reserved = (kal_uint32)ccci_ipc_maptbl[i].extq_id;
    ccci_debug_add_seq(p_ccci_buff, CCCI_DEBUG_ASSERT_BIT); // add ccci seq
    QBM_DES_SET_DATALEN(ior.first_gpd, p_ccci_buff->data[1]);
    QBM_DES_SET_DATALEN(ior.first_gpd->p_data_tbd,  p_ccci_buff->data[1]);
    qbm_cal_set_checksum((kal_uint8 *)ior.first_gpd);
    qbm_cal_set_checksum((kal_uint8 *)ior.first_gpd->p_data_tbd);
    QBM_CACHE_FLUSH(ior.first_gpd, sizeof(qbm_gpd));
    QBM_CACHE_FLUSH(ior.first_gpd->p_data_tbd, sizeof(qbm_gpd));
    
    
    //copy ilm to GPD
    temp_ipc_ilm->src_mod_id =	ccci_ipc_maptbl[j].extq_id; 
    update_buff_addr = (kal_uint32)p_ccci_buff;
	update_buff_addr += sizeof(CCCI_BUFF_T);	
    CCCI_KAL_MSG_TO_AP_MSG(temp_ipc_ilm->msg_id, temp_ipc_ilm->msg_id);
	kal_mem_cpy((kal_uint8 *)update_buff_addr ,(kal_uint8 *)temp_ipc_ilm, sizeof(ipc_ilm_t));
    
	if (temp_ipc_ilm->local_para_ptr != NULL){			
			//copy loca_para_struct to GPD
			update_buff_addr += sizeof(ipc_ilm_t); //24 bytes
			orig_local_addr = update_buff_addr;
			kal_mem_cpy((kal_uint8 *)update_buff_addr,(kal_uint8 *)temp_ipc_ilm->local_para_ptr, temp_ipc_ilm->local_para_ptr->msg_len);
    }
    
    if( temp_ipc_ilm->peer_buff_ptr != NULL){
			//copy peer buff_struct to GPD
			if (temp_ipc_ilm->local_para_ptr != NULL){	 
			    update_buff_addr += temp_ipc_ilm->local_para_ptr->msg_len;//should be 4 bytes alignment?? 
			}
            else{
                update_buff_addr += sizeof(ipc_ilm_t); //24 bytes
            }
			orig_peer_addr = update_buff_addr;
			kal_mem_cpy((kal_uint8 *)update_buff_addr,(kal_uint8 *)temp_ipc_ilm->peer_buff_ptr, 
                          sizeof(peer_buff_struct) 
                          + temp_ipc_ilm->peer_buff_ptr->pdu_len 
                          + temp_ipc_ilm->peer_buff_ptr->free_header_space 
                          + temp_ipc_ilm->peer_buff_ptr->free_tail_space);
    }

    free_local_para(temp_ipc_ilm->local_para_ptr);
	temp_ipc_ilm->local_para_ptr = (local_para_struct *)orig_local_addr;//assign not NULL ptr to indicate there have content 
			
	free_peer_buff(temp_ipc_ilm->peer_buff_ptr);
	temp_ipc_ilm->peer_buff_ptr = (peer_buff_struct *)orig_peer_addr;//assign not NULL ptr to indicate there have content			

    QBM_CACHE_FLUSH(p_ccci_buff, len);
    
    if (KAL_TRUE == kal_query_systemInit()){ // polling mode
        result = ccci_polling_io(ccci_ipc_ch.send_channel, ccci_ipc_ch.p_polling_gpd, KAL_TRUE);
        CCCIDEV_RST_CCCI_COMM_GPD_LIST(ccci_ipc_ch.p_polling_gpd,ccci_ipc_ch.p_polling_gpd);
    }
    else{		
        result = ccci_ipc_ch.ccci_write_gpd(ccci_ipc_ch.send_channel, &ior, NULL);	
    	
        if (KAL_INFINITE_WAIT == wait_mode && CCCI_SUCCESS == result){		
    	    /* Wait for feedabck by retrieve event */
    	    kal_retrieve_eg_events(ccci_ipc_ch.event, 1 << i, KAL_AND_CONSUME,  &retrieved_events, KAL_SUSPEND);
        }
    }				
	/* Exit critical section */ 
	CCCI_IPC_EXIT_CRITICAL_SECTION
    ((CCCI_IPC_ILM_T*)buffer_ptr)->used = 0;  

    ccci_ipc_trace(CCCI_IPC_TRACE, CCCI_IPC_MOD_DATA, CCCI_SEND_MSG_TRA_CCCI,
                p_ccci_buff->data[0], p_ccci_buff->data[1], p_ccci_buff->channel, p_ccci_buff->reserved);
    ccci_ipc_trace(CCCI_IPC_TRACE, CCCI_IPC_MOD_DATA, CCCI_SEND_MSG_FUNC_PASS_TRA);	
		
	/* Finish */	
    if (result == CCCI_SUCCESS){
    	return KAL_TRUE;
    }
    else{
        return KAL_FALSE;
    }
        
}

/*************************************************************************
* FUNCTION
*  ipc_msgsvc_allocate_ilm
*
* DESCRIPTION
*  This function will allocate ilm data structure.
*  Used to compatible with MT6280 API.
*
* PARAMETERS
*  module_id - 
*
* RETURNS
*  ipc_ilm_t - ilm structure ptr
*
*************************************************************************/
ipc_ilm_t* ipc_msgsvc_allocate_ilm(module_type module_id)
{
    kal_uint32 i=0;

    
    ccci_ipc_trace(CCCI_IPC_TRACE, CCCI_IPC_MOD_DATA, CCCI_ALLOC_ILM_FUNC, module_id);
    for (i = 0 ; i < MAX_CCCI_IPC_TASKS; i++)
    {
        if (module_id == ccci_ipc_maptbl[i].task_id)
        {
           
            if (ccci_ipc_ilm_arr[i].used == 0){
                ccci_ipc_ilm_arr[i].used = 1;
                return &(ccci_ipc_ilm_arr[i].ipc_ilm);
            }
            else{
                ASSERT(ccci_ipc_ilm_arr[i].used == 0);
                return NULL;
            }
        }

    }

    return NULL;
}


/*************************************************************************
* FUNCTION
*  ipc_msgsvc_send_ext_queue
*
* DESCRIPTION
*  This function will return if the owner need to check
*  compatible with MT6280
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
kal_bool ipc_msgsvc_send_ext_queue(ipc_ilm_t*ipc_ilm_t_ptr)
{
    return ccci_ipc_send_msg((kal_uint32)(ipc_ilm_t_ptr->dest_mod_id), (void *)(ipc_ilm_t_ptr), (kal_uint16)sizeof(ipc_ilm_t),  KAL_INFINITE_WAIT, KAL_FALSE);
}


/*************************************************************************
* FUNCTION
*  ipc_msgsvc_send_ext_queue_no_wait
*
* DESCRIPTION
*  This function will return if the owner need to check
*  compatible with MT6280
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
kal_bool ipc_msgsvc_send_ext_queue_no_wait(ipc_ilm_t*ipc_ilm_t_ptr)
{
    return ccci_ipc_send_msg((kal_uint32)(ipc_ilm_t_ptr->dest_mod_id), (void *)(ipc_ilm_t_ptr), (kal_uint16)sizeof(ipc_ilm_t),  KAL_NO_WAIT, KAL_FALSE);
}


/*************************************************************************
* FUNCTION
*  kal_uint32 ccci_ipc_get_debug_status
*
* DESCRIPTION
*  Get CCCI ipc debug status and write to the write_ptr
*
*
* PARAMETERS
*  write_ptr : the write address of CCCI debug status
*  available_size : the available size of CCCI debug status
* RETURNS
*  kal_uint32 : the used size of CCCI ipc debug status
*
*************************************************************************/
kal_uint32 ccci_ipc_get_debug_status(kal_uint32 *write_ptr, kal_uint32 available_size)
{
    // If the available size is not enough, return size 0 
    if(available_size < sizeof(CCCI_IPC_DEBUG_STATUS_T))
        return 0;
    
    ccci_ipc_debug_status.reload_rgpd_number = ccci_ipc_ch.reload_rgpd_number;
    
    kal_mem_cpy((void *)write_ptr, (void *)&ccci_ipc_debug_status, sizeof(CCCI_IPC_DEBUG_STATUS_T));

    return sizeof(CCCI_IPC_DEBUG_STATUS_T);
}

/*************************************************************************
* FUNCTION
*  ccci_ipc_init
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
#ifdef CCCI_IT_MODE_CONTROL_CCCI_IPC
extern void ccci_ipc_it_create();
#endif
void ccci_ipc_init(void)
{
    kal_uint32 p_cache_aligned; 
    
    //Send message does not need callback
    ccci_ipc_ch.ccci_init_gpdior(ccci_ipc_ch.send_channel ,  ccci_ipc_send_msg_cb);
    //send mesage ack need to implement callback
//	    ccci_ipc_ch.ccci_init_gpdior(ccci_ipc_ch.send_ack_channel , ccci_ipc_error_cb);
    //Receive mesage need to implement callback
    ccci_ipc_ch.ccci_init_gpdior(ccci_ipc_ch.receive_channel , ccci_ipc_receive_msg_cb);
    //Receive mesage ack does not need to implement callback
//	    ccci_ipc_ch.ccci_init_gpdior(ccci_ipc_ch.receive_ack_channel , ccci_ipc_error_cb);

    //Initialize the event for usage
    if (ccci_ipc_ch.event == 0){
        ccci_ipc_ch.event = kal_create_event_group("CCCI_IPC");
    }
    //Initialize the semaphore for critical section 
    if (ccci_ipc_ch.semaphore == 0){
        ccci_ipc_ch.semaphore = kal_create_sem("CCCI_IPC",1); 
    }

    /* initialize polling mode GPD */
    ASSERT(CCCI_IPC_POLLING_MODE_BUF_SZ >= 2*CPU_CACHE_LINE_SIZE);
    /*make p_gpd aligned to CPU_CACHE_LINE_SIZE_MASK*/
    p_cache_aligned = (kal_uint32)g_ccci_ipc_polling_buf;
    if(p_cache_aligned&CPU_CACHE_LINE_SIZE_MASK) { 
        p_cache_aligned = ((kal_uint32)(g_ccci_ipc_polling_buf)&~CPU_CACHE_LINE_SIZE_MASK);
        p_cache_aligned += CPU_CACHE_LINE_SIZE;
    }

    // The reason + QBM_HEAD_SIZE is for ROME E1, cldma needs to record this buff whether is cacheable or non-cacheable
	ccci_ipc_ch.p_polling_gpd = (qbm_gpd *)(p_cache_aligned + QBM_HEAD_SIZE);
    
    // register ccci debug get status cb funp
    ccci_debug_get_status_register(CCCI_DEBUG_GET_STATUS_MODULE_CCCIIPC, ccci_ipc_get_debug_status);    
    
    CCCIDEV_RST_CCCI_COMM_GPD_LIST(ccci_ipc_ch.p_polling_gpd,ccci_ipc_ch.p_polling_gpd);

#ifdef CCCI_IT_MODE_CONTROL_CCCI_IPC
    ccci_ipc_it_create();
#endif
}

