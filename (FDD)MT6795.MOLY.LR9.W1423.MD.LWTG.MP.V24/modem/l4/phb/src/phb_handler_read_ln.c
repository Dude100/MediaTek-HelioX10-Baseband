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
 * phb_handler_read_ln.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is read ln handler of PHB module.
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
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "kal_public_defs.h"

#include "ps_public_enum.h"
#include "nvram_editor_data_item.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"

#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"

#include "kal_trace.h"
#include "phb_trc.h"

#include "sim_common_enums.h"
#include "nvram_struct.h"
#include "nvram_enums.h"


#include "l4c2phb_enums.h"
#include "l4c2phb_struct.h"

#include "phb_defs.h"
#include "phb_control_block.h"
#include "phb_data_desc.h"

#include "phb_context.h"
#include "phb_se.h"

#include "phb_common.h"
#include "phb_ilm.h"
#include "phb_nvram_access.h"

#include "phb_handler_read_ln.h"

#include "phb_sap.h"

#include "l4_msgid.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_HANDLER_READ_LN_C_

#if !defined(__PHB_NO_CALL_LOG__)
extern kal_bool l4c_is_src_from_rmmi(kal_uint8 src_id);

static void phb_read_ln_confirm(
                phb_errno_enum result,
                nvram_ef_phb_ln_struct *record2,
                kal_uint8 src_id,
                control_block_type *control_block);



/*****************************************************************************
 * FUNCTION
 *  phb_read_ln_err_handler
 * DESCRIPTION
 *  This is phb_read_ln_handler function of PHB module.
 *  Handles read last number request from L4C.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_read_ln_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    phb_read_ln_confirm(PHB_ERRNO_FAIL, NULL, control_block->src_id, control_block);
}


/*****************************************************************************
 * FUNCTION
 *  phb_read_ln_handler
 * DESCRIPTION
 *  This is phb_read_ln_handler function of PHB module.
 *  Handles read last number request from L4C.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_read_ln_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //1st idle status, start to read log data, do some prepare work
    if (ilm_ptr != NULL)
    {
        //1st work: prepare the context global variable used for this read task, 
        //it's share between phonebook task
        if (control_block == NULL)
        {
            l4cphb_read_ln_req_struct *msg_ptr = NULL;

            msg_ptr = (l4cphb_read_ln_req_struct*) ilm_ptr->local_para_ptr;
            control_block = phb_alloc_control_block();
            /* Cannot allocate, means that PHB is still operating. Reject request! */
            if (control_block == NULL)
            {
                phb_read_ln_confirm(PHB_ERRNO_BUSY, NULL, msg_ptr->src_id, control_block);
                return;
            }
            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;
            control_block->src_id = msg_ptr->src_id;
        }

        //first to read the data from NVRAM, it's idle (READ_LN_NONE) status,
        //need to check the start point to read
        if (control_block->proc_stage == READ_LN_NONE)
        {
            l4cphb_read_ln_req_struct *msg_ptr = NULL;

            msg_ptr = (l4cphb_read_ln_req_struct*) ilm_ptr->local_para_ptr;

            control_block->proc_stage = READ_LN_READ;  //change to next status
            //the callback is this API itself, but please note, when it's called second time,
            //the proc_stage is changed, so different status is handled
            control_block->IO_cnf_receive = phb_read_ln_handler;
            //set the error handler
            control_block->err_handler = phb_read_ln_err_handler;
            control_block->type = (phb_type_enum)msg_ptr->type;
            //the src_id is used for L4C to find the primitive from which task (it's MMI here),
            //just remember it here, not use it and only feedback to L4C layer
            control_block->src_id = msg_ptr->src_id;

            //seg_total is the total nvram record number of this log type
            //secondary_ID is the 1st nvram record index of this log type
            //read the 15th missed log,  seg_total = 2; secondary_ID = 3
            if (msg_ptr->type == PHB_LND)
            {
                control_block->seg_total = PHB_TOT_LND_LIDS;
                control_block->secondary_ID = PHB_LND_LID_START;
            }
            else if (msg_ptr->type == PHB_LNM)
            {
                control_block->seg_total = PHB_TOT_LNM_LIDS;
                control_block->secondary_ID = PHB_LNM_LID_START;
            }
            else if (msg_ptr->type == PHB_LNR)
            {
                control_block->seg_total = PHB_TOT_LNR_LIDS;
                control_block->secondary_ID = PHB_LNR_LID_START;
            }
            else
            {
                phb_read_ln_confirm(PHB_ERRNO_FAIL, NULL, control_block->src_id, control_block);
                return;
            }
            ASSERT(msg_ptr->seq_id <= 10);

            //seg_id is the NVRAM record to read, add this nvram record shift to secondary_ID,
            //so here secondary_ID is the right nvram record index to read.
            //ex.  read 15 dialled log data, secorndary_ID is 3+(2-1)=4; 
            //seq_id is count in MMI layer. (=15/10 + 1= 2)
            
            control_block->secondary_ID += (msg_ptr->seq_id - 1);
            //add gemini shift,  SIM2 data is just after SIM1 data, so does SIM3 and SIM4 
        #if defined(__GEMINI__) || defined(__SGLTE__)
            if (phb_current_mod == MOD_PHB_2)
            {
                control_block->secondary_ID += PHB_TOTAL_LN_LID;
            }
        #endif /* __GEMINI__ || __SGLTE__ */

          //check how must log data to read, actual_count is the total log number of this log type.
        #if (MAX_PHB_LN_ENTRY > 20)
        
            control_block->actual_count = (kal_uint16) phb_get_ln_total_entry((kal_uint8) control_block->type);
            if (control_block->actual_count < (msg_ptr->seq_id - 1) * PHB_MAX_LN_ENTRIES)
            {
                ASSERT(0);
            }
            else
            {
                control_block->actual_count -= ((msg_ptr->seq_id - 1) * PHB_MAX_LN_ENTRIES);
            }
        #endif /* (MAX_PHB_LN_ENTRY > 20) */ 

            //read log data from NVRAM 
            phb_read_ln_from_nvram(control_block);
            return;
        }
        else if (control_block->proc_stage == READ_LN_READ)
        {
        //read nvram record back, parse it and return to MMI layer via L4c
            kal_uint16 length;
            nvram_read_cnf_struct *msg_ptr = NULL;
            nvram_ef_phb_ln_struct *pdu_data;

            msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;
            control_block->IO_stage = IO_NONE;

            //check if read nvram record success
            if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
            {
               //set the data parser handler
                control_block->IO_cnf_receive = phb_read_ln_handler;

                //log data is saved in peer buffer
                pdu_data = (nvram_ef_phb_ln_struct*) get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &length);

                /* keep first read data in control_block->data */
                hold_peer_buff(ilm_ptr->peer_buff_ptr);
                control_block->data = (kal_uint8*) ilm_ptr->peer_buff_ptr;
                //save how many log data in a NVRAM record are read, it's log data number not 
                //nvram record number,  each nvram record has 10 log data in it
                control_block->total = pdu_data->no_entry;

                phb_read_ln_confirm(PHB_ERRNO_SUCCESS, NULL, control_block->src_id, control_block);
                return;
            }
            else
            {  //read nvram fail
                phb_read_ln_confirm(PHB_ERRNO_READ_FAIL, NULL, control_block->src_id, control_block);
            }
        }
        else
        {
            //error handling, may for some special API caller scenario
            phb_read_ln_confirm(PHB_ERRNO_FAIL, NULL, control_block->src_id, control_block);
        }
    }
    else
    {   //error handling, may for some special API caller scenario
        phb_read_ln_confirm(PHB_ERRNO_FAIL, NULL, control_block->src_id, control_block);
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_read_ln_confirm
 * DESCRIPTION
 *  This is phb_read_ln_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  record2             [?]         
 *  src_id              [IN]        
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_read_ln_confirm(
                phb_errno_enum result,
                nvram_ef_phb_ln_struct *record2,
                kal_uint8 src_id,
                control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cphb_read_ln_cnf_struct *param_ptr;
    peer_buff_struct *peer_buff_ptr = NULL;
    l4cphb_phb_ln_entry_array_struct *pdu_stream_ptr;
    nvram_ef_phb_ln_struct *src_ptr;
    kal_uint16 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param_ptr = (l4cphb_read_ln_cnf_struct*)
        construct_local_para((kal_uint16) sizeof(l4cphb_read_ln_cnf_struct), TD_RESET);

    param_ptr->src_id = src_id;
    param_ptr->result = result;
    param_ptr->cause = 0;
    param_ptr->total = 0;

    if (control_block != NULL)
    {
    //allocate control block success

     //get call log type by nvram record index, remove the gemini shift side affect
    #if defined(__GEMINI__) || defined(__SGLTE__)
        if (phb_current_mod == MOD_PHB_2)
        {
            control_block->secondary_ID -= PHB_TOTAL_LN_LID;
        }
    #endif /* __GEMINI__ || __SGLTE__  */

        //get log type by log index and it's position in NVRAM
        if (control_block->secondary_ID >= PHB_LND_LID_START && control_block->secondary_ID < PHB_LNM_LID_START)
        {
            param_ptr->type = PHB_LND;
        }
        else if (control_block->secondary_ID >= PHB_LNM_LID_START && control_block->secondary_ID < PHB_LNR_LID_START)
        {
            param_ptr->type = PHB_LNM;
        }
        else if (control_block->secondary_ID >= PHB_LNR_LID_START && control_block->secondary_ID <= PHB_TOTAL_LN_LID)
        {
            param_ptr->type = PHB_LNR;
        }

        //handle success case
        if ((result == PHB_ERRNO_SUCCESS) && (control_block->total > 0))
        {
            param_ptr->total = control_block->total;
            //allocate peer buffer to save the nvram record just read
            pdu_stream_ptr = (l4cphb_phb_ln_entry_array_struct*)
                l4cphb_alloc_ln_peer_buf(&peer_buff_ptr, param_ptr->total);

            //get NVRAM record data from peer buffer
            src_ptr = (nvram_ef_phb_ln_struct*) get_peer_buff_pdu((peer_buff_struct*) control_block->data, &length);

            /* pdu_stream_ptr->no_array = param_ptr->total;
               pdu_stream_ptr->array = (phb_ln_entry_struct *)get_ctrl_buffer
               (sizeof (phb_ln_entry_struct) * param_ptr->total); */


            ASSERT(src_ptr->no_entry <= param_ptr->total);

            //copy data to the log data buffer,  ex,  total dial log is 15, read the 15th log, src_ptr->no_entry is 5 
            //(the real log data number in this  nvram record, it may be <= 10 )
            kal_mem_cpy(pdu_stream_ptr->array, &src_ptr->array[0], sizeof(phb_ln_entry_struct) * src_ptr->no_entry);

            //can skip this as record2 is not used,  it's a common design in read/write/delete action: read 2 nvram record at one action,
            //but indeed, it's not used in read action here, you can just search it to make sure this
            if (record2 != NULL)
            {
                ASSERT((src_ptr->no_entry + record2->no_entry) <= param_ptr->total);
                kal_mem_cpy(
                    &pdu_stream_ptr->array[src_ptr->no_entry],
                    &record2->array[0],
                    sizeof(phb_ln_entry_struct) * record2->no_entry);
            }
        }

        //check if has more data to read again, a bad design to count by human,
   
    #if (MAX_PHB_LN_ENTRY >10)
        if (control_block && (control_block->total == PHB_MAX_LN_ENTRIES) &&
        #if (MAX_PHB_LN_ENTRY > 20)
            control_block->actual_count > control_block->total)
        #else
            (((control_block->secondary_ID == 1) && (control_block->type == (phb_type_enum)PHB_LND)) ||
            ((control_block->secondary_ID == 3) && (control_block->type == (phb_type_enum)PHB_LNM)) ||
            ((control_block->secondary_ID == 5) && (control_block->type == (phb_type_enum) PHB_LNR))))
        #endif
        {
            param_ptr->more_data = KAL_TRUE;
        }
        else
    #endif /* (MAX_PHB_LN_ENTRY >10) */
        {
            param_ptr->more_data = KAL_FALSE;
        }

        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_READ_LN_CNF, param_ptr, peer_buff_ptr);
        /* if (peer_buff_ptr != NULL)
           free_ctrl_buffer (pdu_stream_ptr->array); */

        if (control_block != NULL)
        {
            if (control_block->data != NULL)
            {
                free_peer_buff((peer_buff_struct*) control_block->data);
            }
            phb_free_control_block(control_block);
        }
    }
    else
    {
        //error handling for allocate control block fail case
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_READ_LN_CNF, param_ptr, peer_buff_ptr);
    }
}   /* end of phb_read_ln_confirm */
#endif /* !defined(__PHB_NO_CALL_LOG__) */


#ifdef __PHB_ACCESS_SIM_LN__
/*****************************************************************************
 * FUNCTION
 *  phb_read_sim_ln_confirm
 * DESCRIPTION
 *  This is phb_read_sim_ln_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]               
 *  src_id              [IN]        
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_read_sim_ln_confirm(
                phb_errno_enum result,
                kal_uint8 src_id,
                control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cphb_read_sim_ln_cnf_struct *param_ptr;
    phb_ln_entry_struct* phb_ln_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //allocate temp buffer
    param_ptr = (l4cphb_read_sim_ln_cnf_struct*)
        construct_local_para((kal_uint16) sizeof(l4cphb_read_sim_ln_cnf_struct), TD_CTRL);

    param_ptr->src_id = src_id;
    param_ptr->result = result;
    param_ptr->cause = 0;
    
    if (control_block != NULL)
    {
        param_ptr->type = control_block->type;
        param_ptr->record_index = control_block->record_index;
        param_ptr->cause = control_block->cause;

        if (result == PHB_ERRNO_SUCCESS)
        {
            phb_ln_entry = &param_ptr->entry;
            kal_mem_set(phb_ln_entry, (kal_uint8) PHB_INVALID_VALUE, sizeof(phb_ln_entry_struct));

            //copy data to high layer
            if (control_block->temp_ln_entry != NULL)
            {
                kal_mem_cpy(phb_ln_entry, control_block->temp_ln_entry, sizeof(phb_ln_entry_struct));
                free_ctrl_buffer(control_block->temp_ln_entry);
            }
        }
        phb_free_control_block(control_block);
    }
    
    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_READ_SIM_LN_CNF, param_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  phb_read_sim_ln_err_handler
 * DESCRIPTION
 *  This is phb_read_sim_ln_err_handler function of PHB module.
 *  
 *  Requirement:
 *  Error handlers should destruct control_block.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_read_sim_ln_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_READ_SIM_LN_ERR);

   /**
    * Shall we try to recover/continue handling,
    * or just reject the request in processing?
    * Currently, the latter is adpoted.
    */

    phb_read_sim_ln_confirm(
        PHB_ERRNO_READ_FAIL,
        control_block->src_id,
        control_block);
}


/*****************************************************************************
 * FUNCTION
 *  phb_read_sim_ln_handler
 * DESCRIPTION
 *  This is phb_read_sim_ln_handler function of PHB module.
 *  Handles read last number request from L4C only in SIM.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_read_sim_ln_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_READ_SIM_LN);

   //check if first status, if ilm_ptr is not NULL, it's first status, can check this by search it
    if (ilm_ptr != NULL)  
    {
       //allocate control buffer
        if (control_block == NULL)
        {
            l4cphb_read_sim_ln_req_struct *msg_ptr = NULL;

            msg_ptr = (l4cphb_read_sim_ln_req_struct*) ilm_ptr->local_para_ptr;
            control_block = phb_alloc_control_block();
            /* Cannot allocate, means that PHB is still operating. Reject request! */
            if (control_block == NULL)
            {
                phb_read_sim_ln_confirm(PHB_ERRNO_BUSY, msg_ptr->src_id, control_block);
                return;
            }
            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;
            control_block->src_id = msg_ptr->src_id;
        }

        //start to read log data from SIM card,  prepare some work
        if (control_block->proc_stage == READ_SIM_LN_NONE)
        {
            l4cphb_read_sim_ln_req_struct *msg_ptr = NULL;
            ln_data_desc_enum desc_type = LN_DATA_DESC_LND;

            msg_ptr = (l4cphb_read_sim_ln_req_struct*) ilm_ptr->local_para_ptr;

            //set callback handler 
            control_block->IO_cnf_receive = phb_read_sim_ln_handler;
            control_block->type = (phb_type_enum)msg_ptr->type;
            control_block->src_id = msg_ptr->src_id;
            //allocate temp buffer to save data
            control_block->temp_ln_entry = (phb_ln_entry_struct*)
                    get_ctrl_buffer(sizeof(phb_ln_entry_struct));
            //memset invalid value,  it's defined in SIM Spec
            kal_mem_set(control_block->temp_ln_entry, (kal_uint8) PHB_INVALID_VALUE, sizeof(phb_ln_entry_struct));

            //set some SIM EF file info
            //set primary_ID to EF file index: FILE_LND_IDX
            //set secondary_ID to annother EF file index: FILE_EXT1_IDX;
            //according to SIM spec, if log data is so many that EF_LND can not store it, can save the more data to EXT1 EF file
            //but indeed, we not support EXT1 EF file here, you can skip it
            //set record_index to the index of log data stored in SIM card
            phb_se_set_ln_control_block(control_block, msg_ptr->record_index);

            //set next status: read back handle status, set error handler and success handler (data parser)
            control_block->proc_stage = READ_SIM_LN_READ;
            control_block->err_handler = phb_read_sim_ln_err_handler;
            control_block->return_location = phb_read_sim_ln_handler;

            if (control_block->primary_ID == FILE_LND_IDX)
            {
                desc_type = LN_DATA_DESC_LND;
            }
            else
            {
                ASSERT(0);
            }

            //phb_ptr is phonebook context, it has ln_data_desc to store the EF_LND description info,
            //like record max num, total number, record size, if support this EF_LND feature...
            //note:
            //1. L4PHB is a module contain PHB/CallLog, may be before 09A, the code of PHB/CallLog is mixed together,
            //from 09A? or 09B, the original split calllog from PHB for most code, but not completely done this work, so still use phb_ptr->ln_data_desc yet,
            //because phb_ptr can read these info together with those EF files used by PHB only.
            //from SIM Spec,  SIM Spec has a special EF file named service table, it contain bit to decide if other feature(EF file) is enabled and supported
            //so before to access this EF, we need to make if it's really support and get its basic info, ex File type, record num, record size and so on
            control_block->length = phb_ptr->ln_data_desc[desc_type].record_size;
            if (phb_ptr->ln_data_desc[desc_type].is_support && control_block->length)
            {
               //if support, read it via SIM task
                phb_issue_IO_read_ln(control_block);
            }
            else
            {   //not support, return error
                phb_read_sim_ln_confirm(PHB_ERRNO_NOT_SUPPORT, msg_ptr->src_id, control_block);
            }
            return;
        }
    }
    else if (control_block->proc_stage == READ_SIM_LN_READ)
    {
       //read data back, parse it
        phb_read_sim_ln_confirm(PHB_ERRNO_SUCCESS, control_block->src_id, control_block);
    }
    else
    {
        phb_read_sim_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
    }
}
#endif /* __PHB_ACCESS_SIM_LN__ */


