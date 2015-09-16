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
 *   ccci_rpc_data.c
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
 * [CCCI IPC] Support Clibtime feature
 *
 * removed!
 * removed!
 * [CCCI RPC] Fix CCCI seq check potential issue when multi UL gpds case
 *
 * removed!
 * removed!
 * [CCCI RPC] Fix CCCI seq check potential issue when multi UL gpds case
 *
 * removed!
 * removed!
 * [CCCI RPC] Fix RPC receive callback bug
 *
 * removed!
 * removed!
 * [CCCI] CCCI new debug mechanism
 *
 * removed!
 * removed!
 * [CCCI RPC] Fix ccci rpc coding defect in ccci_rpc_receive_cb
 *
 * removed!
 * removed!
 * [CCCI] Add ROME chip version by API instead compile option
 *
 * removed!
 * removed!
 * [CCCI] Add & Maintain UT code
 *
 * removed!
 * removed!
 * [CCCI & RPC & FS] ASSERT enhancement
 *
 * removed!
 * removed!
 * [CCCI RPC] Debug enhancement & Add log.
 *
 * 03 29 2014 ap.wang
 * removed!
 * Add RPC write lock and fix error_ior error
 *
 * removed!
 * removed!
 * 	[CCCI RPC] Add init gpd list in wrapper function.
 *
 * removed!
 * removed!
 * [CCCI RPC] Add CCCI RPC general query function.
 *
 * removed!
 * removed!
 * [CCCI] Solve polling gpd caused memory corruption in MT6595.
 * Solutiin: For MT6595_S00, increase static buffer size (add QBM_HEAD_SIZE) and polling
 *  gpd offeset to the size.
 *
 * 09 23 2013 ap.wang
 * removed!
 * 	Fix CCC_RPC RX data none invalid problem
 *
 * 09 23 2013 ap.wang
 * removed!
 * 	.
 *
 * 06 27 2013 ap.wang
 * removed!
 * [CCCI_RPC] Modify for sceurity RPC service
 *
 * 05 14 2013 ap.wang
 * removed!
 * [CCCI RPC] Add trace log
 *
 * 05 14 2013 ap.wang
 * removed!
 * [CCCI RPC] Add trace log
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
#include "cache_sw.h"        //for CPU_CACHE_LINE_SIZE

#include <stdarg.h>

#include "kal_public_api.h"
#include "ccci_rpc_if.h"


/*******************************************************************************
 * Define import global variables.
 *******************************************************************************/
extern kal_bool  ccci_debug_phychan_full;

/*******************************************************************************
 * Define import function prototype.
 *******************************************************************************/
extern void CCCI_Invalid_Callback(CCCI_BUFF_T *bufp);

/*******************************************************************************
 * Define global variables.
 *******************************************************************************/

pIPC_RPC_StreamBuffer_T IPC_RPC_REQ_BUF[IPC_RPC_REQ_BUFFER_NUM];
extern RPC_GPDS_POOL_T rpc_gpd_pool[CCCI_RPC_GPD_NUMBER];

// separate variables in AP and MD sides
kal_uint32 IPC_RPC_ReadIndex = 0;
kal_uint32 IPC_RPC_WriteIndex = 0;
kal_uint32 IPC_RPC_BufCount = 0;
kal_semid  g_IPC_RPC_SemId = NULL;

kal_uint32 IPC_RPC_ShareBuffer_BlockSize;

extern kal_bool kal_query_systemInit(void);
extern kal_bool INT_QueryExceptionStatus(void);

/* Separate to AP or MD side */

/* Modem part */

//static kal_bool lock_RW = (kal_bool)1;

/*******************************************************************************
 * Define import global variables.
 *******************************************************************************/


/*******************************************************************************
 * Define import function prototype.
 *******************************************************************************/

/*******************************************************************************
 * Define macro
 *******************************************************************************/
#define CCCI_RPC_ENTER_CRITICAL_SECTION  if (KAL_TRUE == ccci_rpc_ch.check_kal_systemInit()  || INT_QueryExceptionStatus() == KAL_TRUE) \
                                           {                                                                                  \
                                              ccci_rpc_ch.fake_semaphore--;                                                           \
                                           }                                                                                  \
                                           else                                                                               \
                                           {                                                                                  \
                                              kal_take_sem(ccci_rpc_ch.semaphore, KAL_INFINITE_WAIT);                              \
                                           }                                                                                  \
                                 
#define CCCI_RPC_EXIT_CRITICAL_SECTION   if (KAL_TRUE == ccci_rpc_ch.check_kal_systemInit()  || INT_QueryExceptionStatus() == KAL_TRUE)    \
                                           {                                                                                  \
                                              ccci_rpc_ch.fake_semaphore++;                                                           \
                                           }                                                                                  \
                                           else                                                                               \
                                           {                                                                                  \
                                              kal_give_sem(ccci_rpc_ch.semaphore);                                                 \
                                           }                                                          


/*******************************************************************************
 * Define global variables.
 *******************************************************************************/

/* The mapping table used for query */
#define X_RPC_MODULE_CONF(a,b,c,d) {c,b}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#define MAX_CCCI_RPC_TASKS (sizeof(ccci_rpc_maptbl) / sizeof(RPC_MSGSVC_TASKMAP_T))

/* ccci_rpc_ch channel config*/
CCCI_RPC_T ccci_rpc_ch = 
{ 
    CCCI_IPC_RPC_CHANNEL,  
    CCCI_IPC_RPC_ACK_CHANNEL,  
    0, //event
    0, //semaphore
    1, //fake_semaphore
    ccci_write_gpd,
    ccci_init_gpdior,
    ccci_deinit,
	ccci_polling_io,
    kal_query_systemInit,
    IPC_RPC_CCCI_WRITE_ONLY_UT //ut flag code
};


#define CCCI_RPC_POLLING_MODE_BUF_SZ QBM_SIZE_CCCI_COMM

// The reason + QBM_HEAD_SIZE is for ROME E1, cldma needs to record this buff whether is cacheable or non-cacheable
static kal_uint8 g_ccci_rpc_polling_buf[CCCI_RPC_POLLING_MODE_BUF_SZ + QBM_HEAD_SIZE];

// Record ccci rpc debug status
static CCCI_RPC_DEBUG_STATUS_T ccci_rpc_debug_status;

/*******************************************************************************
 * Define functions.
 *******************************************************************************/

/*************************************************************************
* FUNCTION
*  ccci_rpc_receive_cb
*
* DESCRIPTION
*  This function will send event to KAL
*
* PARAMETERS
*  CCCI_CHANNEL_T - ccci channel
*  ccci_io_request_t - ccci gpd ior list 
*
* RETURNS
*  none
*
*************************************************************************/
void ccci_rpc_receive_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* ior)
{
    ccci_io_request_t *current_ior = ior;
    qbm_gpd           *current_gpd;
    qbm_gpd           *next_gpd;
    
    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_ccci_rpc_receive_cb_FUNC_TRA);
	while(current_ior != NULL){
		current_gpd = current_ior->first_gpd ;
		while( current_gpd != NULL){
			CCCI_BUFF_T *bufp = CCCIDEV_GET_QBM_DATAPTR(current_gpd);
			next_gpd = current_gpd->p_next;
            ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_CCCI_HEADER_TRA
                           , bufp->data[0], bufp->data[1], bufp->channel, bufp->reserved);
            ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_HEADER_TRA
                          , (bufp+1)->data[0], (bufp+1)->data[1]);
			ccci_debug_check_seq(bufp); // check ccci seq
            if(rpc_gpd_pool[bufp->reserved].gpd_ptr == NULL){
                ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_EVENT_WAKEUP_FUNC_TRA, bufp->reserved);
			    //get rpc gpd ptr, bufp->reserved is the gpd_index for this rpc transmission
			    rpc_gpd_pool[bufp->reserved].gpd_ptr = current_gpd;
                kal_set_eg_events(ccci_rpc_ch.event,  (1 << (bufp->reserved)) , KAL_OR);
            }
            else{
                ccci_io_request_t error_ior;
                ccci_rpc_trace(CCCI_RPC_ERR, CCCI_RPC_MOD_DATA, CCCI_RPC_GPD_POOL_FULL_ERR, bufp->reserved);
                // need to prevent the upper layer task is infinity wait
                EXT_ASSERT(KAL_FALSE, (kal_uint32)rpc_gpd_pool[bufp->reserved].gpd_ptr, (kal_uint32)(bufp+1)->data[0], (kal_uint32)(bufp+1)->data[1]);
                error_ior.first_gpd = current_gpd;
                error_ior.last_gpd = current_gpd;
                error_ior.next_request = NULL;
                #ifdef __SDIOC_PULL_Q_ENH_DL__
	                error_ior.num_gpd = 1;
                #endif
                ccci_rpc_ch.ccci_write_gpd(ccci_rpc_ch.receive_channel, &error_ior, NULL);
            }
		    if (current_gpd == current_ior->last_gpd){
                break;
			}
            current_gpd = next_gpd;
		}
		current_ior = current_ior->next_request;
	}
    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_ccci_rpc_receive_cb_FUNC_PASS_TRA);
}


/*************************************************************************
* FUNCTION
*  ccci_rpc_send_cb
*
* DESCRIPTION
*  This function is the cb of rpc send 
*  Reset gpd and add this gpd to Rx channel
* PARAMETERS
*  bufp - ccci header
*
* RETURNS
*  none
*
*************************************************************************/
void ccci_rpc_send_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* ior)
{
    ccci_io_request_t *current_ior = ior;
    qbm_gpd           *current_gpd;
    qbm_gpd           *prev_gpd;

    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_ccci_rpc_send_cb_FUNC_TRA);
    //deal with ior not contain one gpd issue (many users to send gpd at the same time)
    while(current_ior != NULL){
#ifdef __SDIOC_PULL_Q_ENH_DL__
		current_ior->num_gpd = 1;
#endif		
        current_gpd = current_ior->first_gpd;
        while( current_gpd != NULL){	
   		    // reset gpd and write gpd to Rx channel		  
			if (current_gpd == current_ior->last_gpd){
			    CCCIDEV_RST_CCCI_COMM_GPD_LIST(current_gpd, current_gpd);
				ccci_rpc_ch.ccci_write_gpd(ccci_rpc_ch.receive_channel, current_ior, NULL);						
				break;
		    }
		    else{	  //shift next gpd
			    prev_gpd = current_gpd;
				current_gpd = current_gpd->p_next;
			    CCCIDEV_RST_CCCI_COMM_GPD_LIST(prev_gpd, prev_gpd);
				ccci_rpc_ch.ccci_write_gpd(ccci_rpc_ch.receive_channel, current_ior, NULL);
		    }	 		
        }
        current_ior = current_ior->next_request;
    }
    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_ccci_rpc_send_cb_FUNC_PASS_TRA);
}

/*************************************************************************
* FUNCTION
*  void IPC_RPC_CCCI_Write
*
* DESCRIPTION
*
* PARAMETERS
*  *
* RETURNS
*  NA
*
*************************************************************************/
extern RPC_GPDS_POOL_T rpc_gpd_pool[CCCI_RPC_GPD_NUMBER];

kal_int32 IPC_RPC_CCCI_Write(kal_int32 *index, kal_uint32 op, IPC_RPC_LV_T *pLV, kal_uint32 num)
{
    kal_uint32 i, len = 0, tlen, gpd_index;
    kal_uint8 *ptr;
    kal_uint8 *ptr_buf_boundary;
    IPC_RPC_LV_T *pTmp;
    kal_int32 windex = IPC_RPC_USE_DEFAULT_INDEX;
   
    kal_int32 result = CCCI_SUCCESS;
    pIPC_RPC_StreamBuffer_T temp_rpc_buffer;
    ccci_io_request_t ior = {0};

    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_IPC_RPC_CCCI_Write_FUNC_TRA);
  	/* Use critical section to protect ENTER */
	CCCI_RPC_ENTER_CRITICAL_SECTION
    if (KAL_TRUE == ccci_rpc_ch.check_kal_systemInit()){ // polling mode
    //in init - use local gpd
	    ior.first_gpd = ccci_rpc_ch.p_polling_gpd;
	    ior.last_gpd  = ccci_rpc_ch.p_polling_gpd;
        windex = 0; // for polling io
    }
    else{ 
	//after init - use gpd alloc from QBM
	    for (gpd_index = 0; gpd_index < CCCI_RPC_GPD_NUMBER; gpd_index++){
			if(rpc_gpd_pool[gpd_index].gpd_occupied == 0){
				windex = gpd_index;
				*index = gpd_index;
				rpc_gpd_pool[gpd_index].gpd_occupied = 1;
				break;
			}
		}
        
        if (gpd_index == CCCI_RPC_GPD_NUMBER){
            ccci_rpc_trace(CCCI_RPC_ERR, CCCI_RPC_MOD_DATA, CCCI_RPC_ALLOC_GPD_ERROR);
            return CCCI_FAIL;
        }

		ior.first_gpd = rpc_gpd_pool[windex].gpd_ptr;
		ior.last_gpd  = rpc_gpd_pool[windex].gpd_ptr;
		
    }
    //already get gpd
	/* Exit critical section */ 
	CCCI_RPC_EXIT_CRITICAL_SECTION
	ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_GET_FREE_INDEX_TRA, *index);
	
    //get ccci header pointer
	temp_rpc_buffer = CCCIDEV_GET_QBM_DATAPTR(ior.first_gpd);
    //copy opid, number of LV, LV[]  into ccci data field
   	temp_rpc_buffer->rpc_opid = op;
	temp_rpc_buffer->num_para = num;
	//get buf boundary pointer
	ptr_buf_boundary = (kal_uint8*)(temp_rpc_buffer) + sizeof(IPC_RPC_StreamBuffer_T) ;
    //to get accurate length for header     
    len = sizeof(CCCI_BUFF_T) +2*sizeof(kal_uint32); 
	//- point to LV[0]
    ptr = (kal_uint8*)(temp_rpc_buffer) + sizeof(CCCI_BUFF_T) +2*sizeof(kal_uint32);
    for(i=0; i<num; i++)
    {
        // adjusted to be 4-byte aligned
        tlen = ((pLV[i].len + 3) >> 2) << 2; //tlen store size of LV[i].value

        if ((ptr + sizeof(kal_uint32) + tlen) > ptr_buf_boundary)
        {
            //EXT_ASSERT(0, IPC_RPC_CCCI_ERROR_INPUT_PARAM_LEN_TO_LONG, op, (sizeof(IPC_RPC_StreamBuffer_T) -sizeof(CCCI_BUFF_T)));
			ASSERT(0);
        }

        //- point to LV[i]
        pTmp = (IPC_RPC_LV_T *)ptr;

        pTmp->len = pLV[i].len;
        kal_mem_cpy(ptr + sizeof(kal_uint32), pLV[i].val, pLV[i].len);

        //- adjust pointer to LV[i+1]
        ptr = ptr + sizeof(kal_uint32) + tlen;
		//calculate accurate length for header   
		len = len + sizeof(kal_uint32) + tlen;
		
    }

    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_HEADER_TRA
                  , temp_rpc_buffer->rpc_opid, temp_rpc_buffer->num_para);

	//fill ccci header 
    temp_rpc_buffer->ccci_header.data[1]  = (kal_uint32)len;
	temp_rpc_buffer->ccci_header.channel  = (kal_uint32)ccci_rpc_ch.send_channel;
	temp_rpc_buffer->ccci_header.reserved = (kal_uint32)windex;
    if (KAL_TRUE == ccci_rpc_ch.check_kal_systemInit()){ // polling mode
        ccci_debug_add_seq(&temp_rpc_buffer->ccci_header, CCCI_DEBUG_ASSERT_BIT); // add ccci seq
    }
    else{ // due to rpc is a preemptive module, can't gureen guarantee the seq is sequenced
        ccci_debug_add_seq(&temp_rpc_buffer->ccci_header, CCCI_DEBUG_NOT_ASSERT_BIT); // add ccci seq
    }
    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_CCCI_HEADER_TRA
                  , temp_rpc_buffer->ccci_header.data[1], temp_rpc_buffer->ccci_header.data[1]
                  , temp_rpc_buffer->ccci_header.channel, temp_rpc_buffer->ccci_header.reserved);
	//set len in gpd header 
    QBM_DES_SET_DATALEN(ior.first_gpd, temp_rpc_buffer->ccci_header.data[1]);
	QBM_DES_SET_DATALEN(ior.first_gpd->p_data_tbd,  temp_rpc_buffer->ccci_header.data[1]);
    qbm_cal_set_checksum((kal_uint8 *)ior.first_gpd);
    qbm_cal_set_checksum((kal_uint8 *)ior.first_gpd->p_data_tbd);
    QBM_CACHE_FLUSH(ior.first_gpd, sizeof(qbm_gpd));
    QBM_CACHE_FLUSH(ior.first_gpd->p_data_tbd, sizeof(qbm_gpd));
    QBM_CACHE_FLUSH(temp_rpc_buffer, len);
#ifdef __SDIOC_PULL_Q_ENH_DL__
	ior.num_gpd = 1;
#endif
    //send gpd
    if (KAL_TRUE == ccci_rpc_ch.check_kal_systemInit()){ // polling mode
	ccci_rpc_ch.polling_step_trace = IPC_RPC_TRACE_FORMAT(op, IPC_RPC_CCCI_TRACE_WRITE_POLLING_START);
	ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_RPC_TRACE, (void *)&ccci_rpc_ch.polling_step_trace);
	
        result = ccci_rpc_ch.ccci_rpc_polling_io(ccci_rpc_ch.send_channel, ccci_rpc_ch.p_polling_gpd, KAL_TRUE);
        CCCIDEV_RST_CCCI_COMM_GPD_LIST(ccci_rpc_ch.p_polling_gpd, ccci_rpc_ch.p_polling_gpd);

	ccci_rpc_ch.polling_step_trace = IPC_RPC_TRACE_FORMAT(op, IPC_RPC_CCCI_TRACE_WRITE_POLLING_END);
	ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_RPC_TRACE, (void *)&ccci_rpc_ch.polling_step_trace);
    }
    else{
	rpc_gpd_pool[windex].gpd_ptr = NULL;
	result = ccci_rpc_ch.ccci_write_gpd(ccci_rpc_ch.send_channel, &ior, NULL);	
        if (result != CCCI_SUCCESS){
            rpc_gpd_pool[windex].gpd_ptr = ior.first_gpd;
	    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_WRITE_FAIL_TRA);
        }
		//after initialization, wait for event in IPC_RPC_Process_CMD
    }				

    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_IPC_RPC_CCCI_Write_FUNC_PASS_TRA);
	/* Finish */	
    if (result == CCCI_SUCCESS){
    	return CCCI_SUCCESS;
    }
    else{
        return CCCI_FAIL;
    }
}


/*************************************************************************
* FUNCTION
*  void IPC_RPC_Process_CMD
*
* DESCRIPTION
*
* PARAMETERS
*  gpd index
* RETURNS
*  NA
*
*************************************************************************/
void IPC_RPC_Process_CMD(kal_int32 index)
{
  
    kal_uint32 retrieved_events =0;
    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_IPC_RPC_Process_CMD_FUNC_TRA);

    if (KAL_TRUE != ccci_rpc_ch.check_kal_systemInit() )
    {
        kal_retrieve_eg_events(ccci_rpc_ch.event, 1 << index, KAL_AND_CONSUME ,  &retrieved_events, KAL_SUSPEND);
    }
    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_IPC_RPC_Process_CMD_FUNC_PASS_TRA);
}


/*************************************************************************
* FUNCTION
*  void IPC_RPC_CCCI_Read
*
* DESCRIPTION
*
* PARAMETERS
*  *
* RETURNS
*  NA
*
*************************************************************************/
kal_int32 IPC_RPC_CCCI_Read(kal_int32 index, kal_uint32 op, IPC_RPC_LV_T *pLV, kal_uint32 *num)
{
    kal_uint32 i, no_copy = 0;
    kal_uint8 *ptr;
    kal_uint32 num_read;
    IPC_RPC_LV_T *pTmp;
    kal_uint32 v_tmp1, v_tmp2;
    kal_int32  ret = CCCI_FAIL, status;
    #ifndef __CCCI_RPC_UT__
    kal_int32 result=CCCI_FAIL;
    #endif
	pIPC_RPC_StreamBuffer_T bufp;

	ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_IPC_RPC_CCCI_Read_FUNC_TRA);

	if (KAL_TRUE == ccci_rpc_ch.check_kal_systemInit()){ // polling mode
	    QBM_CACHE_INVALID(ccci_rpc_ch.p_polling_gpd, CCCI_RPC_POLLING_MODE_BUF_SZ);
	    
	    ccci_rpc_ch.polling_step_trace = IPC_RPC_TRACE_FORMAT(op, IPC_RPC_CCCI_TRACE_READ_POLLING_START);
	    ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_RPC_TRACE, (void *)&ccci_rpc_ch.polling_step_trace);

	#ifndef __CCCI_RPC_UT__
	result = 
        #endif
        ccci_rpc_ch.ccci_rpc_polling_io(ccci_rpc_ch.send_channel, ccci_rpc_ch.p_polling_gpd, KAL_FALSE);

	ccci_rpc_ch.polling_step_trace = IPC_RPC_TRACE_FORMAT(op, IPC_RPC_CCCI_TRACE_READ_POLLING_END);
	ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_RPC_TRACE, (void *)&ccci_rpc_ch.polling_step_trace);
	
        #ifndef __CCCI_RPC_UT__
	if(result != CCCI_SUCCESS)
	{
		EXT_ASSERT(0,result,0,0);
	}
        #endif

	    bufp = CCCIDEV_GET_QBM_DATAPTR(ccci_rpc_ch.p_polling_gpd);
		ccci_debug_check_seq(&bufp->ccci_header); // check ccci seq
	}
    else{
	    bufp = CCCIDEV_GET_QBM_DATAPTR(rpc_gpd_pool[index].gpd_ptr);		
    }
    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_CCCI_HEADER_TRA
                  , bufp->ccci_header.data[0], bufp->ccci_header.data[1]
                  , bufp->ccci_header.channel, bufp->ccci_header.reserved);
    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_HEADER_TRA
                  , bufp->rpc_opid, bufp->num_para);
	
	//check opid
    v_tmp1 = bufp->rpc_opid;
    if (op && (v_tmp1 != (IPC_RPC_API_RESP_ID | op)))
    {
        ccci_rpc_trace(CCCI_RPC_ERR, CCCI_RPC_MOD_DATA, CCCI_RPC_RECEIVE_OPID_ERR
                       , op, bufp->rpc_opid);
        ret = CCCI_FAIL;
		
        // if received opid isn't equal to expected opid, need to assert 
        EXT_ASSERT(KAL_FALSE,v_tmp1,(IPC_RPC_API_RESP_ID | op),index);
        goto __exit;
    }
	//check return LV number
	
	num_read = bufp->num_para;
	if (op)
	{
        v_tmp1 = num_read;
	    if (*num != num_read) //number of lv mismatch 
	    {
                ccci_rpc_trace(CCCI_RPC_ERR, CCCI_RPC_MOD_DATA, CCCI_RPC_PRAR_NUM_ERR
                            ,  *num, bufp->num_para);
                ret = CCCI_FAIL;

		status = (kal_int32)(bufp->buffer);

		if ((num_read == 1) && ((status < 0) && (status >= -10)))  //the entry of op id will store status when there is issue in the RPC at AP
		{
		    ret = status;
		}

                goto __exit;
	    }
	}
	else  //if op id <0
	{
		*num = num_read;
		no_copy = 1;
	}
	
    //- point to LV[0]
    ptr = (kal_uint8*)bufp + sizeof(CCCI_BUFF_T) + 2*sizeof(kal_uint32);
    for(i = 0; i < *num; i++)
    {
        //- point to LV[i];
        pTmp = (IPC_RPC_LV_T *)ptr;

        v_tmp1 = pLV[i].len;
        v_tmp2 = pTmp->len;
        if (op && (v_tmp1 < v_tmp2)) // compare length
        {
            ccci_rpc_trace(CCCI_RPC_ERR, CCCI_RPC_MOD_DATA, CCCI_RPC_PRAR_LENGTH_ERR
                            , i, pLV[i].len, pTmp->len);
            ret = CCCI_FAIL;
            goto __exit;
        }

        pLV[i].len = pTmp->len;
        if (no_copy)
        {
            pLV[i].val = (void *)(ptr + sizeof(kal_uint32));
        }
        else
        {
            kal_mem_cpy(pLV[i].val, ptr + sizeof(kal_uint32), pLV[i].len);
        }

        // adjusted to be 4-byte aligned
        ptr = ptr + (sizeof(kal_uint32) + (((pTmp->len + 3) >> 2) << 2));
    }
    ret = CCCI_SUCCESS;
		
__exit:
	//reset gpd, free gpd in rpc gpd pool
    if (KAL_TRUE == ccci_rpc_ch.check_kal_systemInit()) // polling mode
    {
    	CCCIDEV_RST_CCCI_COMM_GPD_LIST (ccci_rpc_ch.p_polling_gpd, ccci_rpc_ch.p_polling_gpd);
    }
	else
	{
		CCCIDEV_RST_CCCI_COMM_GPD_LIST(rpc_gpd_pool[index].gpd_ptr,rpc_gpd_pool[index].gpd_ptr);
		rpc_gpd_pool[index].gpd_occupied = 0;
	}

    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_IPC_RPC_CCCI_Read_FUNC_PASS_TRA);
    return ret;
}


/*************************************************************************
* FUNCTION
*  void IPC_RPC_Wrapper
*
* DESCRIPTION
*  This function use to handle real RPC between AP/MD
*
*
* PARAMETERS
*  *
* RETURNS
*  NA
*
*************************************************************************/
kal_int32 IPC_RPC_Wrapper(IPC_RPC_OP_ID_T rpc_op,...)
{
    kal_int32 index = IPC_RPC_USE_DEFAULT_INDEX;
    IPC_RPC_LV_T LV[IPC_RPC_MAX_ARG_NUM];
    kal_int32 	ret, count = 0 , size_val = 0;
    kal_uint32	num = 0;
    va_list ap;
    kal_uint32 start_time =0, end_time =0, duration = 0; 
    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_IPC_RPC_Wrapper_FUNC_TRA);

    start_time = ccci_rpc_get_current_time();
    // Start to trace polling mode
    if (KAL_TRUE == kal_query_systemInit()){ 
        ccci_rpc_ch.polling_step_trace = IPC_RPC_TRACE_FORMAT(rpc_op, IPC_RPC_CCCI_TRACE_START);
 	ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_RPC_TRACE, (void *)&ccci_rpc_ch.polling_step_trace);	
    }

    /* Reload rgpd to prevent that ccci rpc task init is not to do */
    if(ccci_rpc_ch.allocated_gpd_number==0 && ccci_rpc_ch.check_kal_systemInit() == KAL_FALSE)
	ccci_rpc_allocate_gpds();

    va_start(ap, rpc_op);
    while ( (size_val = va_arg(ap,int)) != IPC_RPC_EOF_TERM_PATTERN )
    {
        /* If terminate pattern is found, that means the input is end */
        if (size_val == IPC_RPC_INPUT_TERM_PATTERN)
        {
            break;
        }

        if (count >= IPC_RPC_MAX_ARG_NUM)
        {
            ccci_rpc_trace(CCCI_RPC_ERR, CCCI_RPC_MOD_DATA, CCCI_RPC_PARA_NUM_FULL_ERROR
                            , IPC_RPC_MAX_ARG_NUM, count);
			ASSERT(0);
        }

        LV[count].len = (kal_uint32)size_val;
        LV[count++].val = (void *)(va_arg(ap,void *));

    }

    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_HEADER_TRA
                  , rpc_op, count);
    /* Pass the parameter to gpd */
    ret = IPC_RPC_CCCI_Write(&index, rpc_op, LV, count); // Ipc_Cpsvc_Read request

#ifdef __CCCI_RPC_UT__
    if(ccci_rpc_ch.ut_flag == IPC_RPC_CCCI_WRITE_ONLY_UT){
        if (ret != CCCI_SUCCESS)
        {
            return ret;
        }
	    else{
            return CCCI_SUCCESS;
        }	
    }
    else if(ccci_rpc_ch.ut_flag == IPC_RPC_CCCI_WHOLE_PATH_UT && ccci_rpc_ch.check_kal_systemInit() == KAL_FALSE){
    	kal_set_eg_events(ccci_rpc_ch.event,  (1 << index) , KAL_OR);
    }
#endif

    /* Chceck the result */
    if (ret != CCCI_SUCCESS)
    {
        return ret;
    }

	
    /* Wait for AP response the RPC is finished */
    IPC_RPC_Process_CMD(index);


    /* fill the returen code - first LV pair stores the return code from AP*/
    LV[num].len = sizeof(kal_int32);
    LV[num++].val = (void *)&count;

    /* Start to get the return parameter */
    while ( (size_val = va_arg(ap,int)) != IPC_RPC_EOF_TERM_PATTERN )
    {
        if (num >= IPC_RPC_MAX_ARG_NUM)
        {
            ccci_rpc_trace(CCCI_RPC_ERR, CCCI_RPC_MOD_DATA, CCCI_RPC_PARA_NUM_FULL_ERROR
                            , IPC_RPC_MAX_ARG_NUM, num);
			ASSERT(0);
        }


        LV[num].len = (kal_uint32)size_val;
        LV[num++].val = (void *)(va_arg(ap,void *));

    }

    /* Get the return information */
    ret = IPC_RPC_CCCI_Read(index, rpc_op, LV, &num);
    ccci_rpc_trace(CCCI_RPC_TRACE, CCCI_RPC_MOD_DATA, CCCI_RPC_IPC_RPC_Wrapper_FUNC_PASS_TRA);
    
    // Accumulate wait ap time
    end_time = ccci_rpc_get_current_time();
    duration = ccci_rpc_get_duration(start_time, end_time);

    // Start to trace polling mode
    if (KAL_TRUE == kal_query_systemInit()){ 
	    ccci_rpc_ch.wait_ap_time_polling += duration;
	    ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_RPC_WAIT_TIME_POLLING, (void *)&ccci_rpc_ch.wait_ap_time_polling);

        ccci_rpc_ch.polling_step_trace = IPC_RPC_TRACE_FORMAT(rpc_op, IPC_RPC_CCCI_TRACE_END);
 	    ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_RPC_TRACE, (void *)&ccci_rpc_ch.polling_step_trace);
    }
    else{
        CCCI_RPC_ADD_CARRY(ccci_rpc_ch.wait_ap_time_normal, duration, ccci_rpc_ch.wait_ap_time_normal_carry);
 	    ccci_rpc_ch.wait_ap_time_normal += duration;
	    ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_RPC_WAIT_TIME_NORMAL_CARRY, (void *)&ccci_rpc_ch.wait_ap_time_normal_carry);
        ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_RPC_WAIT_TIME_NORMAL, (void *)&ccci_rpc_ch.wait_ap_time_normal);
    }

    if (ret != CCCI_SUCCESS)
    {
        return ret;
    }
    else
    {
        return count;  //return return code from AP;  takes the space of "count" to store   
    }

}

/*************************************************************************
* FUNCTION
*  kal_uint32 ccci_rpc_get_debug_status
*
* DESCRIPTION
*  Get CCCI rpc debug status and write to the write_ptr
*
*
* PARAMETERS
*  write_ptr : the write address of CCCI debug status
*  available_size : the available size of CCCI debug status
* RETURNS
*  kal_uint32 : the used size of CCCI rpc debug status
*
*************************************************************************/
kal_uint32 ccci_rpc_get_debug_status(kal_uint32 *write_ptr, kal_uint32 available_size)
{
    // If the available size is not enough, return size 0 
    if(available_size < sizeof(CCCI_RPC_DEBUG_STATUS_T))
        return 0;
    
    // set allocated gpd
    ccci_rpc_debug_status.allocated_gpd_number = ccci_rpc_ch.allocated_gpd_number;
    // set gpd poll
    kal_mem_cpy((void *)ccci_rpc_debug_status.rpc_gpd_pool, (void *)rpc_gpd_pool, sizeof(rpc_gpd_pool));
    kal_mem_cpy((void *)write_ptr, (void *)&ccci_rpc_debug_status, sizeof(ccci_rpc_debug_status));
    
    return sizeof(ccci_rpc_debug_status);
}

/*************************************************************************
* FUNCTION
*  ccci_rpc_init
*
* DESCRIPTION
*  This function is to initialize rpc channel and register call back function
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void ccci_rpc_init(void)
{
    kal_uint32 p_cache_aligned; 
    
    //Send message does not need callback
    ccci_rpc_ch.ccci_init_gpdior(ccci_rpc_ch.send_channel ,  ccci_rpc_send_cb);
    //Receive mesage need to implement callback
    ccci_rpc_ch.ccci_init_gpdior(ccci_rpc_ch.receive_channel , ccci_rpc_receive_cb);

    //Initialize the event for usage
    if (ccci_rpc_ch.event == 0){
        ccci_rpc_ch.event = kal_create_event_group("CCCI_RPC");
    }
    //Initialize the semaphore for critical section 
    if (ccci_rpc_ch.semaphore == 0){
        ccci_rpc_ch.semaphore = kal_create_sem("CCCI_RPC",1); 
    }

    /* initialize polling mode GPD */
    ASSERT(CCCI_RPC_POLLING_MODE_BUF_SZ >= 2*CPU_CACHE_LINE_SIZE);
    /*make p_gpd aligned to CPU_CACHE_LINE_SIZE_MASK*/
    p_cache_aligned = (kal_uint32)g_ccci_rpc_polling_buf;
    if(p_cache_aligned&CPU_CACHE_LINE_SIZE_MASK) { 
        p_cache_aligned = ((kal_uint32)(g_ccci_rpc_polling_buf)&~CPU_CACHE_LINE_SIZE_MASK);
        p_cache_aligned += CPU_CACHE_LINE_SIZE;
    }

    // The reason + QBM_HEAD_SIZE is for ROME E1, cldma needs to record this buff whether is cacheable or non-cacheable
	ccci_rpc_ch.p_polling_gpd = (qbm_gpd *)(p_cache_aligned + QBM_HEAD_SIZE);

    qbm_reset_pd(CCCI_RPC_GPD_TYPE, ccci_rpc_ch.p_polling_gpd);
	
    ccci_rpc_ch.polling_step_trace = (kal_uint32)IPC_RPC_CCCI_TRACE_RPC_INIT;
    ccci_rpc_ch.wait_ap_time_polling= 0;
    ccci_rpc_ch.wait_ap_time_normal=0;
    ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_RPC_TRACE, (void *)&ccci_rpc_ch.polling_step_trace);

    // register ccci debug get status cb funp
    ccci_debug_get_status_register(CCCI_DEBUG_GET_STATUS_MODULE_CCCIRPC, ccci_rpc_get_debug_status);    
#ifdef __CCCI_IT_CTRL__
    ccci_rpc_it_create();
    //ccci_ipc_it_create();
#endif
}

