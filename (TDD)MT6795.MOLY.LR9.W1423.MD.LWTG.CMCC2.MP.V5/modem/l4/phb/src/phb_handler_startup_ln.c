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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * phb_handler_startup_ln.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is startup ln handler of PHB module.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "l4_msgid.h"
#include "sim_ps_msgid.h"

#include "ps_public_enum.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_public_api.h"
#include "nvram_editor_data_item.h"
#include "nvram_data_items.h"

#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
//#include "stack_ltlcom.h"

#include "kal_trace.h"
#include "phb_trc.h"

#include "nvram_struct.h"
#include "nvram_enums.h"

#include "sim_common_enums.h"
#include "ps2sim_struct.h"
#include "smu_common_enums.h"

#include "l4_defs.h"

#include "l4c2phb_enums.h"
#include "l4c2phb_struct.h"

#include "phb_defs.h"
#include "phb_control_block.h"
#include "phb_data_desc.h"

#include "phb_context.h"

#include "phb_utils.h"
#include "phb_ilm.h"

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
#include "phb_handler_write_ln.h"
#endif 

#include "phb_sim_access.h"

/* NVRAM_EF_PHB_LID structure */
#include "phb_nvram_access.h"

#include "phb_handler_startup_ln.h"




#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_HANDLER_STARTUP_LN_C_

#if !defined(__PHB_NO_CALL_LOG__)
static void phb_startup_copy_ln(ilm_struct *ilm_ptr, control_block_type *control_block);

#ifndef __PHB_NVRAM_LN_ONLY__
static void phb_startup_translate_ln_from_sim(kal_uint8 *data, control_block_type *control_block);
#endif 

void phb_init_ln_confirm(phb_errno_enum result, control_block_type *control_block);
#endif /* !defined(__PHB_NO_CALL_LOG__) */


#ifdef __PHB_ACCESS_SIM_LN__
/*****************************************************************************
 * FUNCTION
 *  phb_is_ln_sim_file_support
 * DESCRIPTION
 *  To query sim module if phb ln related file support.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void phb_is_ln_sim_file_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_IS_LN_SIM_FILE_SUPPORT);

#if 0
#ifdef __USIM_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __USIM_SUPPORT__ */
#endif
    {
       //to check if support LND EF or not, just query the service table
    
#ifdef WISDOM_MMI
        /* Specially for WISE as WISE want to support LND in USIM even it doesn't follow spec critically,
           it will try to read LND and find if USIM card has this file really */
        phb_ptr->ln_data_desc[LN_DATA_DESC_LND].is_support = KAL_TRUE;
#else
        phb_ptr->ln_data_desc[LN_DATA_DESC_LND].is_support = PHB_SIM_SERVICE_TABLE_QUERY(SERVICE_LND);
#endif
    }
}
#endif /* __PHB_ACCESS_SIM_LN__ */


#if defined(__PHB_NO_CALL_LOG__)
/*****************************************************************************
 * FUNCTION
 *  phb_get_ln_info_set_value
 * DESCRIPTION
 *  This is get_ln_info_set_value function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_get_ln_info_set_value(ilm_struct *ilm_ptr, control_block_type *control_block)
{
#ifdef __PHB_ACCESS_SIM_LN__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_file_info_cnf_struct *sim_file_info_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_GET_LN_INFO_SET_VALUE);

    sim_file_info_cnf = (sim_file_info_cnf_struct*) ilm_ptr->local_para_ptr;

  //the descrption info of LND EF file is saved in phb_ptr which is read back together with all other PHB related PHB file,
  //it's not split very clearly from PHB sub-module.
  //parse the sim file info confirm primitive and get the description info and save it to phb_ptr.
    switch (control_block->proc_stage)
    {
        case startup_ln_info_lnd_record_info:
            phb_ptr->ln_data_desc[LN_DATA_DESC_LND].record_num = sim_file_info_cnf->num_of_rec;
            phb_ptr->ln_data_desc[LN_DATA_DESC_LND].record_size = sim_file_info_cnf->length;
            break;
    }
    
    (*control_block->controller) (NULL, control_block);
#endif /* __PHB_ACCESS_SIM_LN__ */

}


/*****************************************************************************
 * FUNCTION
 *  phb_get_ln_info_err_handler
 * DESCRIPTION
 *  This is get_ln_info_err_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_get_ln_info_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_GET_LN_INFO_ERR);

    /* Bypass error, and continue next step */
    control_block->IO_stage = IO_NONE;
    (*control_block->controller) (NULL, control_block);
}   /* end of phb_get_info_err_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_get_ln_info
 * DESCRIPTION
 *  This is get_ln_info function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_get_ln_info(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, FUNC_PHB_GET_LN_INFO);

    /* Get file size of LND */
    //async mode, just to read the sim file back via sim task
    //set parse handle and error handler and state machine handler
    if (control_block->proc_stage == startup_ln_none)
    {
        control_block->storage = phb_which_sim_storage();
        control_block->primary_ID = FILE_LND_IDX;
        phb_control_block_set(
            control_block,
            phb_get_ln_info_set_value,
            phb_get_ln_info,
            phb_get_ln_info_err_handler,
            startup_ln_info_lnd_record_info);
        phb_sim_file_info(control_block, SIM_REC_SIZE);
    }
    else
    {
        control_block->proc_stage = startup_ln_get_info_finish;
        control_block->controller = phb_no_call_log_init_ln_handler;
        (*control_block->controller) (NULL, control_block);
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_no_call_log_init_ln_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_no_call_log_init_ln_confirm(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cphb_init_ln_cnf_struct *l4cphb_init_ln_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l4cphb_init_ln_cnf = (l4cphb_init_ln_cnf_struct*) construct_local_para(
                                                        sizeof(l4cphb_init_ln_cnf_struct),
                                                        TD_CTRL);
    l4cphb_init_ln_cnf->result = KAL_TRUE;

    if (control_block != NULL)
    {
        phb_free_control_block(control_block);
    }

   //if not support calllog, just send the init response back not to block the next work flow
    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_INIT_LN_CNF, (local_para_struct*) l4cphb_init_ln_cnf, NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  phb_no_call_log_init_ln_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void phb_no_call_log_init_ln_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, FUNC_PHB_NO_CALL_LOG_INIT_LN);

   //just to read LND EF file description info back from SIM card
   
#ifdef __PHB_ACCESS_SIM_LN__
    if (ilm_ptr != NULL)
    {
        control_block = phb_alloc_control_block();
        ASSERT(control_block != NULL);

        /* Retain msg_id */
        control_block->cnf_msg_id = ilm_ptr->msg_id;
        //check if support LND EF file and set it to the global variable
        phb_is_ln_sim_file_support();
        control_block->proc_stage = startup_ln_none;
        phb_get_ln_info(ilm_ptr, control_block);
        return;
    }
    else
    {
        ASSERT(control_block->proc_stage == startup_ln_get_info_finish);
        phb_no_call_log_init_ln_confirm(control_block);
    }
#else /* __PHB_ACCESS_SIM_LN__ */
    phb_no_call_log_init_ln_confirm(NULL);
#endif /* __PHB_ACCESS_SIM_LN__ */
    return;
}


#else /* !defined(__PHB_NO_CALL_LOG__) */
#ifdef __PHB_RECORD_LN_TYPE_SEQ__
/*****************************************************************************
 * FUNCTION
 *  phb_startup_sync_ln_type_seq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr             [?]     
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_startup_sync_ln_type_seq(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    smu_sim_status_enum phb_sim_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_STARTUP_SYNC_LN_TYPE_SEQ);

    //when power on, get SIM status, to decide the next flow, skip or erase NVRAM and read log data from SIM to NVRAM
    phb_sim_status = check_sim_status(PHB_WHICH_SIM);

    kal_trace(TRACE_INFO, INFO_PHB_STARTUP_SYNC_LN_TYPE_SEQ_SIM_STATUS, phb_sim_status);

   //when call this first time, the SIM task must be ready
   //indeed, L4PHB doesn't run until SIM task is work, ex SIM PIN lock is unlock, user choice SIM card number
    if (phb_sim_status == SMU_SIM_NOT_READY)
    {
        ASSERT(0);
    }
    else if (phb_sim_status == SMU_SIM_REPLACED)
    {
     //SIM is changed, start the erase flow: erase NVRAM and read log data from SIM to NVRAM
        phb_set_ln_type_seq(PHB_TOTAL_LN_ENTRIES, 0xff);
        phb_startup_erase_ln(NULL, NULL);
        return;
    }

    if (control_block == NULL)
    {
        control_block = phb_alloc_control_block();
        ASSERT(control_block != NULL);
    }

    //if in idle status
    if (control_block->proc_stage == SYNC_LN_TYPE_SEQ_NONE)
    {
        //set callback handler
        control_block->IO_cnf_receive = phb_startup_sync_ln_type_seq;
        control_block->proc_stage = SYNC_LN_TYPE_SEQ_CONTINUE;

        //get the shift in gemini case
    #if defined(__GEMINI__) || defined(__SGLTE__)
        if (phb_current_mod == MOD_PHB_2)
        {
            control_block->secondary_ID = 2;
        }
        else
    #endif /* __GEMINI__ || __SGLTE__  */
        {
            control_block->secondary_ID = 1;
        }
        control_block->IO_stage = IO_WAIT;

        //read call log type order from NVRAM
        phb_read_ln_type_seq_from_nvram(control_block);
        return;
    }
    else if (control_block->proc_stage == SYNC_LN_TYPE_SEQ_CONTINUE)
    {
        kal_uint16 length;
        nvram_read_cnf_struct *msg_ptr = NULL;
        nvram_ef_phb_ln_type_seq_struct *pdu_data;
        int i;


        //copy the data to phb_ln_type_seq global variable
        msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;

        if (control_block->IO_stage == IO_WAIT && msg_ptr->result == NVRAM_IO_ERRNO_OK)
        {
            /* control_block->IO_cnf_receive = phb_read_ln_handler; */
            pdu_data = (nvram_ef_phb_ln_type_seq_struct*) get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &length);
            for (i = 0; i < length; i++)
            {
                phb_ln_type_seq[i] = pdu_data->type_seq[i];
            }
        }
        else
        {
            /* all is 0xff */
            phb_set_ln_type_seq(PHB_TOTAL_LN_ENTRIES, 0xff);
        }
        control_block->IO_stage = IO_NONE;
    }
    phb_free_control_block(control_block);

    //if define this option, each time power on, will always do the following case
    // 1. erase call log type NVRAM info
    //erase all log data in nvram
    //read log data from SIM card and write to NVRAM
    
#ifdef __PHB_ALWAYS_SYNC_SIM_LN__
    /* SIM isn't replaced. Clear lnd type seq */
    phb_clear_lnd_type_seq();
#endif /* __PHB_ALWAYS_SYNC_SIM_LN__ */ 

    //start erase work
    phb_startup_erase_ln(NULL, NULL);
}
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_startup_erase_ln
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr             [?]     
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_startup_erase_ln(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    smu_sim_status_enum phb_sim_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_STARTUP_ERASE_LN);

    //allocate control buffer
    if (control_block == NULL)
    {
        control_block = phb_alloc_control_block();
        ASSERT(control_block != NULL);
        control_block->cnf_msg_id = MSG_ID_L4CPHB_INIT_LN_REQ;
    }

   //get SIM status to see if replaced
    phb_sim_status = check_sim_status(PHB_WHICH_SIM);
    kal_trace(TRACE_STATE, INFO_PHB_STARTUP_ERASE_SIM_STATUS, phb_sim_status);

     //if define this option, always start the erase flow, if not, just return
#ifndef __PHB_ALWAYS_SYNC_SIM_LN__
    if (phb_sim_status == SMU_SIM_NOT_READY)
    {
        ASSERT(0);
    }
    else if (phb_sim_status != SMU_SIM_REPLACED)
    {
        phb_init_ln_confirm(PHB_ERRNO_SUCCESS, control_block);
        return;
    }
#endif /* __PHB_ALWAYS_SYNC_SIM_LN__ */ 

    //first in idle status before start erase work
    if (control_block->proc_stage == ERASE_LN_NONE)
    {
      //set nvram response callback handler, set next status
        control_block->IO_cnf_receive = phb_startup_erase_ln;
        control_block->proc_stage = ERASE_LN_CONTINUE;
        control_block->secondary_ID = PHB_LND_LID_START;

        //get the nvram record shift in gemini scenario
    #if defined(__GEMINI__) || defined(__SGLTE__)
        if (phb_current_mod == MOD_PHB_2)
        {
            control_block->secondary_ID += PHB_TOTAL_LN_LID;
        }
    #endif /* __GEMINI__ || __SGLTE__ */

       //prepare invalid dagta and write it to NVRAM
        control_block->data = get_ctrl_buffer(sizeof(nvram_ef_phb_ln_struct));
        kal_mem_set(control_block->data, 0, sizeof(nvram_ef_phb_ln_struct));
        phb_write_ln_to_nvram((nvram_ef_phb_ln_struct*) control_block->data, control_block);
        return;
    }
    else if (control_block->proc_stage == ERASE_LN_CONTINUE)
    {
     //when nvram response done, will callback here
        nvram_write_cnf_struct *msg_ptr = NULL;

        msg_ptr = (nvram_write_cnf_struct*) ilm_ptr->local_para_ptr;
        if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
        {
            if (phb_sim_status == SMU_SIM_NOT_READY)
            {
                ASSERT(0);
            }

          //check if more nvram record need to be erase to invalid value, if so, continue erase work, 
          //if not, start the copy work: copy log data from SIM card to nvram
            
        #if defined(__GEMINI__) || defined(__SGLTE__)
            if ((((phb_current_mod == MOD_PHB_2) && (control_block->secondary_ID > PHB_TOTAL_LN_LID) && (control_block->secondary_ID < 2* PHB_TOTAL_LN_LID)) || ((phb_current_mod == MOD_PHB) && (control_block->secondary_ID < PHB_TOTAL_LN_LID)))&& 
        #else /* __GEMINI__ || __SGLTE__  */
            if ((control_block->secondary_ID < PHB_TOTAL_LN_LID) && 
        #endif /* __GEMINI__ || __SGLTE__  */
                phb_sim_status == SMU_SIM_REPLACED)
            {
                control_block->secondary_ID++;
                phb_write_ln_to_nvram((nvram_ef_phb_ln_struct*) control_block->data, control_block);
                return;
            }
            else
            {
                /* copy LND from sim */
                control_block->proc_stage = COPY_LN_NONE;
                phb_startup_copy_ln(NULL, control_block);
                return;
            }
        }
        else  
        {
            //error handle, write the log data type order to nvram and return.
        
            free_ctrl_buffer(control_block->data);
        #ifdef __PHB_RECORD_LN_TYPE_SEQ__
            control_block->proc_stage = WRITE_LN_TYPE_SEQ;
            phb_write_ln_type_seq_to_nvram(control_block);
        #else /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
            phb_init_ln_confirm(PHB_ERRNO_SUCCESS, control_block);
        #endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
        }
    }
#ifdef __PHB_RECORD_LN_TYPE_SEQ__
    else if (control_block->proc_stage == WRITE_LN_TYPE_SEQ)
    {
        phb_init_ln_confirm(PHB_ERRNO_SUCCESS, control_block);
    }
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  phb_startup_copy_ln
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr             [?]     
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_startup_copy_ln(ilm_struct *ilm_ptr, control_block_type *control_block)
{
#ifndef __PHB_NVRAM_LN_ONLY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   //in idle status,
    if (control_block->proc_stage == COPY_LN_NONE)
    {
      //query if support LND EF file, if not, may need some error handling or it's impossiable not support when call this API
        if (PHB_SIM_SERVICE_TABLE_QUERY(SERVICE_LND) == KAL_TRUE)
        {
            sim_file_info_req_struct *param_ptr;

            control_block->proc_stage = COPY_LN_READ_FILE;
            control_block->IO_cnf_receive = phb_startup_copy_ln;
            control_block->IO_stage = IO_WAIT;

            param_ptr = (sim_file_info_req_struct*)
                construct_local_para((kal_uint16) sizeof(sim_file_info_req_struct), TD_CTRL);

            param_ptr->file_idx = FILE_LND_IDX;
            param_ptr->access_id = control_block->ID;
            param_ptr->info_type = SIM_REC_SIZE;

            phb_send_ilm(MOD_SIM, MSG_ID_SIM_FILE_INFO_REQ, param_ptr, NULL);
            return;
        }
    }
    else if (control_block->proc_stage == COPY_LN_READ_FILE)
    {
       //read log data from SIM card
        sim_file_info_cnf_struct *msg_ptr = NULL;

        msg_ptr = (sim_file_info_cnf_struct*) ilm_ptr->local_para_ptr;
        control_block->IO_stage = IO_NONE;

        if (msg_ptr->result == SIM_CMD_SUCCESS)
        {
            if (msg_ptr->num_of_rec > 0)
            {
                control_block->index = 1;
                control_block->length = msg_ptr->file_size;
                control_block->seg_total = msg_ptr->num_of_rec;
                control_block->proc_stage = COPY_LN_READ;
                control_block->secondary_ID = PHB_LND_LID_START;
            #if defined(__GEMINI__) || defined(__SGLTE__)
                if (phb_current_mod == MOD_PHB_2)
                {
                    control_block->secondary_ID += PHB_TOTAL_LN_LID;
                }
            #endif /* __GEMINI__ || __SGLTE__  */

                phb_read_ln_from_sim(control_block);
                return;
            }
        }
    }
    else if (control_block->proc_stage == COPY_LN_READ)
    {
       //read next log data from SIM card continually
        sim_read_cnf_struct *msg_ptr = NULL;

        msg_ptr = (sim_read_cnf_struct*) ilm_ptr->local_para_ptr;
        control_block->IO_stage = IO_NONE;

        if (msg_ptr->result == SIM_CMD_SUCCESS)
        {
           //parse log data samed in SIM to NVRAM record format
            phb_startup_translate_ln_from_sim((kal_uint8*) msg_ptr->data, control_block);

           //if already read 10 log data from SIM and can fullfill one NVRAM record, write it to NVRAM.
            if ((control_block->index % PHB_MAX_LN_ENTRIES) == 0)
            {
                /* has collected 10 entries, write one segment (10 records) to NVRAM first */
                control_block->proc_stage = COPY_LN_WRITE;
                phb_write_ln_to_nvram((nvram_ef_phb_ln_struct*) control_block->data, control_block);
                return;
            }
            //if the nvram record is not fullfilled and need read more log data from SIM to fullfill this record, continue to read
            if ((control_block->index < control_block->seg_total) && (control_block->index < PHB_MAX_LND_ENTRIES))
            {
                control_block->index++;
                phb_read_ln_from_sim(control_block);
                return;
            }
            else
            {   
               //if the nvram record is not fullfilled but all log data from SIM data is read, just save the nvram record
                control_block->proc_stage = COPY_LN_WRITE;
                phb_write_ln_to_nvram((nvram_ef_phb_ln_struct*) control_block->data, control_block);
                return;
            }
        }
    }
    else if (control_block->proc_stage == COPY_LN_WRITE)
    {
       //nvram write responose callback here
        nvram_write_cnf_struct *msg_ptr = NULL;

        msg_ptr = (nvram_write_cnf_struct*) ilm_ptr->local_para_ptr;
        control_block->IO_stage = IO_NONE;

        if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
        {
           //write one nvram record done, check if need to read more log data from SIM card, if so, continue read it
            if ((control_block->index < control_block->seg_total) && (control_block->index < PHB_MAX_LND_ENTRIES))
            {
                control_block->proc_stage = COPY_LN_READ;
                control_block->secondary_ID++;
                control_block->index++;
                kal_mem_set(control_block->data, 0, sizeof(nvram_ef_phb_ln_struct));
                phb_read_ln_from_sim(control_block);
                return;
            }
            else
            {
               //all log data from SIM card are read, and the nvram record is already saved,
               //just save the log data type sequence to nvram, and return
                free_ctrl_buffer(control_block->data);
            #ifdef __PHB_RECORD_LN_TYPE_SEQ__
                control_block->proc_stage = WRITE_LN_TYPE_SEQ;
                phb_write_ln_type_seq_to_nvram(control_block);
                control_block->IO_cnf_receive = phb_startup_erase_ln;
            #else /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
                phb_init_ln_confirm(PHB_ERRNO_SUCCESS, control_block);
            #endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
                return;
            }
        }
    }


    //for other case ? just do some post-handling work
    
#endif /* __PHB_NVRAM_LN_ONLY__ */ 
    free_ctrl_buffer(control_block->data);
#ifdef __PHB_RECORD_LN_TYPE_SEQ__
    control_block->proc_stage = WRITE_LN_TYPE_SEQ;
    phb_write_ln_type_seq_to_nvram(control_block);
    control_block->IO_cnf_receive = phb_startup_erase_ln;
#else /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
    phb_init_ln_confirm(PHB_ERRNO_SUCCESS, control_block);
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
}

#ifndef __PHB_NVRAM_LN_ONLY__


/*****************************************************************************
 * FUNCTION
 *  phb_startup_translate_ln_from_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data                [?]     
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_startup_translate_ln_from_sim(kal_uint8 *data, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 rec_size, alpha_size;
    nvram_ef_phb_ln_struct *record;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //this funcion is dependent on SIM spec clearly, can just loop through
    //note:
    //1 the format;  2 the default value and it's max length; 3 the string format ex ascii, UCS2...
    
    record = (nvram_ef_phb_ln_struct*) control_block->data;

    rec_size = control_block->length / control_block->seg_total;
    alpha_size = rec_size - PHB_LENGTH_AFTER_ALPHA_ID;

    if ((data[alpha_size] != 0) && (is_empty(data, rec_size) == KAL_FALSE))
    {
        istring_type istring;
        phb_ef_struct phb_ef;

        phb_ef.alpha_id = data;
        phb_ef.mandatory = (phb_ef_mandatory_struct*) ((kal_uint8*) data + alpha_size);

        /* Set up phb_entry->alpha_id */
        record->array[record->no_entry].name_dcs = 0;
        record->array[record->no_entry].name_length = 0;
        kal_mem_set((kal_uint8*) record->array[record->no_entry].name, 0, L4_MAX_NAME);
        istring.length = L4_MAX_NAME;
        istring.data = (kal_uint8*) record->array[record->no_entry].name;
        record->array[record->no_entry].name_length = istring_decode_from_sim((kal_uint8) alpha_size, phb_ef.alpha_id, &istring);
        if (record->array[record->no_entry].name_length == 0)
        {
            istring.charset = PHB_ASCII;
        }
        record->array[record->no_entry].name_dcs = istring.charset;
        if (record->array[record->no_entry].name_length >= L4_MAX_NAME)
        {
            if (record->array[record->no_entry].name_dcs == PHB_ASCII)
            {
                record->array[record->no_entry].name_length--;
                record->array[record->no_entry].name[L4_MAX_NAME - 1] = 0;
            }
            else if (record->array[record->no_entry].name_dcs == PHB_UCS2)
            {
                record->array[record->no_entry].name_length -= 2;
                record->array[record->no_entry].name[L4_MAX_NAME - 1] = 0;
                record->array[record->no_entry].name[L4_MAX_NAME - 2] = 0;
            }
        }

        /* if (alpha_size >= 30)
           {
           kal_mem_cpy (record->array[record->no_entry].name, data, 29);
           record->array[record->no_entry].name[29] = 0;
           record->array[record->no_entry].name_length =
           strlen ((char*)record->array[record->no_entry].name);
           }
           else
           {
           kal_mem_cpy (record->array[record->no_entry].name, data, alpha_size);
           record->array[record->no_entry].name[alpha_size] = 0;
           record->array[record->no_entry].name_length =
           strlen ((char*)record->array[record->no_entry].name);
           } */
        if (*(data + alpha_size) <= 10)
        {
            record->array[record->no_entry].addr_length = *(data + alpha_size);
        }
        else
        {
            record->array[record->no_entry].addr_length = 10;
        }

        kal_mem_cpy(&record->array[record->no_entry].addr_bcd[1], data + alpha_size + 2, 10);

        ASSERT((record->array[record->no_entry].addr_length + 1) < PHB_LN_NUM_SIZE);
        record->array[record->no_entry].addr_bcd[record->array[record->no_entry].addr_length + 1] = 0xff;
        record->array[record->no_entry].addr_bcd[0] = *(data + alpha_size + 1);

        record->array[record->no_entry].count = 1;
        record->no_entry++;
    #ifdef __PHB_RECORD_LN_TYPE_SEQ__
        phb_shift_ln_type_seq(0, PHB_LND);
    #endif 
    }
}
#endif /* __PHB_NVRAM_LN_ONLY__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_init_ln_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result              [IN]        
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_init_ln_confirm(phb_errno_enum result, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_STARTUP_CNF, result);

    if ((result == PHB_ERRNO_BUSY) || (control_block->cnf_msg_id == MSG_ID_L4CPHB_INIT_LN_REQ))
    {
        l4cphb_init_ln_cnf_struct *l4cphb_init_ln_cnf;

        l4cphb_init_ln_cnf = (l4cphb_init_ln_cnf_struct*) construct_local_para(
                                                            sizeof(l4cphb_init_ln_cnf_struct),
                                                            TD_CTRL);
        l4cphb_init_ln_cnf->result = result;

        if (result == PHB_ERRNO_BUSY)
        {
            phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_INIT_LN_CNF, (local_para_struct*) l4cphb_init_ln_cnf, NULL);
            return;
        }

        phb_free_control_block(control_block);

        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_INIT_LN_CNF, (local_para_struct*) l4cphb_init_ln_cnf, NULL);

        return;
    }
}   /* end of phb_init_ln_confirm */
#endif /* !defined(__PHB_NO_CALL_LOG__) */


#if defined(__CANCEL_LOCK_POWERON__)
/*****************************************************************************
 * FUNCTION
 *  phb_init_ln_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result              [IN]        
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_init_me_ln_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing, because the SIM could not be access, so don't need to do anything */
    phb_init_me_ln_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  phb_init_me_ln_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result              [IN]        
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_init_me_ln_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l4cphb_init_me_ln_cnf_struct *l4cphb_init_me_ln_cnf;

    l4cphb_init_me_ln_cnf = (l4cphb_init_me_ln_cnf_struct*) construct_local_para(
                                                        sizeof(l4cphb_init_me_ln_cnf_struct),
                                                        TD_CTRL);
    l4cphb_init_me_ln_cnf->result = PHB_ERRNO_SUCCESS;

    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_INIT_ME_LN_CNF, (local_para_struct*) l4cphb_init_me_ln_cnf, NULL);

    return;
}
#endif /* defined(__CANCEL_LOCK_POWERON__) */


