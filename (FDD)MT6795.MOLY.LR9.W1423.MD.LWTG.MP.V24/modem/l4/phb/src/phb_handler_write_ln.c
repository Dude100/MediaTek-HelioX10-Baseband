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
 * phb_handler_write_ln.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is write ln handler of PHB module.
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
#include "sim_ps_msgid.h"
#include "l4_msgid.h"

#include "ps_public_enum.h"
#include "nvram_editor_data_item.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_public_api.h"
//#include "stack_ltlcom.h"
#include "string.h"
#include "nvram_data_items.h"

#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"

#include "kal_trace.h"
#include "phb_trc.h"

#include "sim_common_enums.h"

#include "ps2sim_struct.h"

#include "l4c2phb_enums.h"
#include "l4c2phb_struct.h"

#include "phb_defs.h"
#include "phb_control_block.h"
#include "phb_data_desc.h"

#include "phb_context.h"
#include "phb_se.h"
#include "phb_utils.h"

#include "phb_common.h"
#include "phb_ilm.h"

#include "phb_sap.h"
#include "phb_handler_write_ln.h"
#include "phb_nvram_access.h"
#include "phb_sim_access.h"

#include "nvram_enums.h"
#include "nvram_struct.h"




#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_HANDLER_WRITE_LN_C_

#if !defined(__PHB_NO_CALL_LOG__)
static void phb_write_ln_confirm(phb_errno_enum result, kal_uint8 src_id, control_block_type *control_block);
static kal_bool phb_update_ln(nvram_ef_phb_ln_struct *record, control_block_type *control_block);

static kal_bool phb_edit_ln(control_block_type *control_block);

#if (MAX_PHB_LN_ENTRY <= 20)
static void phb_ln_renew_entry1(kal_uint8 index, phb_ln_entry_struct *entry, nvram_ef_phb_ln_struct *record);

#ifndef __PHB_LN_CONSECUTIVE_MERGE__

static void phb_ln_renew_entry2(
                kal_uint8 index,
                phb_ln_entry_struct *entry,
                nvram_ef_phb_ln_struct *record,
                nvram_ef_phb_ln_struct *record2);
#endif /* __PHB_LN_CONSECUTIVE_MERGE__ */

#endif /* (MAX_PHB_LN_ENTRY <= 20) */ 

static void phb_ln_push_new_entry(
                phb_ln_entry_struct *entry,
                nvram_ef_phb_ln_struct *record,
                nvram_ef_phb_ln_struct *record2);
#endif /* !defined(__PHB_NO_CALL_LOG__) */


/*****************************************************************************
 * FUNCTION
 *  phb_sync_confirm
 * DESCRIPTION
 *  This is phb_sync_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_sync_confirm(phb_errno_enum result, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (control_block != NULL)
    {
        if (control_block->peer_buf_ptr != NULL)
        {
            free_peer_buff(control_block->peer_buf_ptr);
        }
        if (control_block->data != NULL)
        {
            free_peer_buff((peer_buff_struct*) control_block->data);
        }
        phb_free_control_block(control_block);
    }

    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_SYNC_CNF, NULL, NULL);
}   /* end of phb_sync_confirm */


#if defined(__PHB_NO_CALL_LOG__)
/*****************************************************************************
 * FUNCTION
 *  phb_sync_handler
 * DESCRIPTION
 *  This is phb_sync_handler function of PHB module.
 *  Handles sync request from L4C when power off.
 *  Copyies LND records from NVRAM to SIM, if supported
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [IN/OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_sync_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if not support call log storagement feature, just return back
    if (ilm_ptr != NULL)
    {
        phb_sync_confirm(PHB_ERRNO_SUCCESS, NULL);
        return;
    }
    else
    {
        ASSERT(0);
    }
}


#else /* !defined(__PHB_NO_CALL_LOG__) */
/*****************************************************************************
 * FUNCTION
 *  phb_write_ln_to_erase_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_write_ln_to_erase_sim(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_write_req_struct *param_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    control_block->IO_stage = IO_WAIT;
    param_ptr = (sim_write_req_struct*) construct_local_para((kal_uint16) sizeof(sim_write_req_struct), TD_CTRL);

    param_ptr->file_idx = FILE_LND_IDX;
    param_ptr->para = 0;
    param_ptr->access_id = control_block->ID;

    /* the record to be written to SIM is empty */
    //control_block->index--;
    kal_mem_set((kal_uint8 *)&param_ptr->data[5], 0xff, control_block->seg_len <= 255 ? control_block->seg_len : 255);
    param_ptr->length = control_block->seg_len;
    phb_send_ilm(MOD_SIM, MSG_ID_SIM_WRITE_REQ, param_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  phb_sync_err_handler
 * DESCRIPTION
 *  Error handler
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_sync_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    phb_sync_confirm(PHB_ERRNO_FAIL, control_block);
}


#ifdef __VOIP__
/*****************************************************************************
 * FUNCTION
 *  phb_set_last_voice_ln_index
 * DESCRIPTION
 *  skip the voip record and get the last voice call ln index
 * PARAMETERS
 *  control_block       [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void phb_set_last_voice_ln_index(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_phb_ln_struct *pdu_data, *pdu_data1 = NULL;
    kal_uint16 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //control_block->IO_stage = IO_WAIT;

    pdu_data = (nvram_ef_phb_ln_struct*) get_peer_buff_pdu(control_block->peer_buf_ptr, &length);
    if (control_block->data != NULL)
    {
        //ASSERT(pdu_data->no_entry == PHB_MAX_LN_ENTRIES);
        /* second NVRAM LID: 20 Entries will read 2nd data, too */
        pdu_data1 = (nvram_ef_phb_ln_struct*) get_peer_buff_pdu((peer_buff_struct*) control_block->data, &length);
    }
    if (control_block->index == 0xFFFF)
    {
        if (control_block->data)
        {
            control_block->index = pdu_data->no_entry + pdu_data1->no_entry;
        }
        else
        {
            control_block->index = pdu_data->no_entry;
        }
    }

    if (pdu_data1 && control_block->index > PHB_MAX_LN_ENTRIES)
    {
        while (control_block->index > PHB_MAX_LN_ENTRIES)
        {
            if (pdu_data1->array[control_block->index - PHB_MAX_LN_ENTRIES -1].addr_type == PHB_LN_CALL)
            {
                return;
            }
            control_block->index--; /* skip voip ln */
        }
    }
    
    while (control_block->index > 0)
    {
        if (pdu_data->array[control_block->index-1].addr_type == PHB_LN_CALL)
        {
            return;
        }
        control_block->index--; /* skip voip ln */
    }
    //if (pdu_data->array[control_block->index].addr_type == PHB_LN_CALL)
    //{
    //    return;
    //}
}


/*****************************************************************************
 * FUNCTION
 *  phb_sync_handler
 * DESCRIPTION
 *  This is phb_sync_handler function of PHB module.
 *  Handles sync request from L4C when power off.
 *  Copyies LND records from NVRAM to SIM, if supported
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_sync_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //check if first idle status
    if (ilm_ptr != NULL)
    {
     
    #ifdef __PHB_NVRAM_LN_ONLY__
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_SYNC_CNF, NULL, NULL);
        return;
    #else /* __PHB_NVRAM_LN_ONLY__ */ 
        /* Cannot allocate, means that PHB is still operating. Reject request! */
        if (control_block == NULL)
        {
            control_block = phb_alloc_control_block();
            if (control_block == NULL)
            {
                phb_sync_confirm(PHB_ERRNO_BUSY, control_block);
                return;
            }
            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;
        }

        //start to work here, do prepare work, its main work is read log data from NVRAM and write it back to SIM
    

        if (control_block->proc_stage == SYNC_NONE)
        {
           //first status: to read SIM info: record number, record size..  
            control_block->proc_stage = SYNC_READ_FILE;
            control_block->IO_cnf_receive = phb_sync_handler;
            control_block->err_handler = phb_sync_err_handler;

            //check if support EF_LND feature, just to query the service table, if support read it. 
            if (PHB_SIM_SERVICE_TABLE_QUERY(SERVICE_LND) == KAL_TRUE)
            {
                sim_file_info_req_struct *param_ptr;

                /* SIM card supports LND, get file info */
                param_ptr = (sim_file_info_req_struct*)
                    construct_local_para((kal_uint16) sizeof(sim_file_info_req_struct), TD_CTRL);

                param_ptr->file_idx = FILE_LND_IDX;
                param_ptr->access_id = control_block->ID;
                param_ptr->info_type = SIM_REC_SIZE;
            
                phb_send_ilm(MOD_SIM, MSG_ID_SIM_FILE_INFO_REQ, param_ptr, NULL);
                return;
            }
            else
            {
                /* SIM card doesn't support LND, no need to sync */
                phb_sync_confirm(PHB_ERRNO_SUCCESS, control_block);
                return;
            }
        }
        else if (control_block->proc_stage == SYNC_READ_FILE)
        {
            sim_file_info_cnf_struct *msg_ptr = NULL;

            msg_ptr = (sim_file_info_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == SIM_CMD_SUCCESS)
            {
                if (msg_ptr->num_of_rec == 0)
                {
                    /* SIM card LND num is 0l, stop writing */
                    phb_sync_confirm(PHB_ERRNO_SUCCESS, control_block);
                    return;
                }
                control_block->seg_len = msg_ptr->file_size / msg_ptr->num_of_rec;
            #if (MAX_PHB_LN_ENTRY > 20)
                control_block->total = phb_get_ln_total_entry(PHB_LND);
                control_block->seg_total = 2 * PHB_MAX_LN_ENTRIES;
            #else
                control_block->seg_total = MAX_PHB_LN_ENTRY;            
            #endif /* MAX_PHB_LN_ENTRY > 20 */
                control_block->length = msg_ptr->file_size;
                control_block->index = msg_ptr->num_of_rec;
                control_block->proc_stage = SYNC_ERASE_SIM; /* index will used to indicate the SIM index */
            #if (MAX_PHB_LN_ENTRY > 20)
                control_block->total = (control_block->total + PHB_MAX_LN_ENTRIES - 1) / PHB_MAX_LN_ENTRIES;
                if (control_block->total > 2)
                {
                    control_block->secondary_ID = PHB_LND_LID_START + control_block->total - 2;
                }
                else
                {
                    control_block->secondary_ID = PHB_LND_LID_START;
                }
            #else /* (MAX_PHB_LN_ENTRY > 20) */ 
                control_block->secondary_ID = PHB_LND_LID_START;
                control_block->total = PHB_TOT_LND_LIDS;
            #endif /* MAX_PHB_LN_ENTRY > 20 */
            #if defined(__GEMINI__) || defined(__SGLTE__)
                if (phb_current_mod == MOD_PHB_2)
                {
                    control_block->secondary_ID += PHB_TOTAL_LN_LID;
                }
            #endif /* __GEMINI__ || __SGLTE__ */
                control_block->data = NULL;
              //as SIM EF LND is record, need to erase data in it one by one.
              //ex it has max 10 record, we need to erase all the 10 record one by one with invalid data
                phb_write_ln_to_erase_sim(control_block);
                return;
            }
            else
            {
                /* SIM card fail, don't write to SIM */
                phb_sync_confirm(PHB_ERRNO_READ_FAIL, control_block);
                return;
            }
        }
        else if (control_block->proc_stage == SYNC_ERASE_SIM)
        {
            sim_write_cnf_struct *msg_ptr = NULL;

            msg_ptr = (sim_write_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == SIM_CMD_SUCCESS)
            {
                control_block->index--;
                if (control_block->index > 0)
                {
                    //continue to erase it untill all EF record(log data) is erased
                    phb_write_ln_to_erase_sim(control_block);
                    return;
                }
                else
                {
                   //erase done, start to read log data from NVRAM, only read dial log data as LND only for dial log
                   //should read the oldest log data in NVRAM and write it to EF file fist,
                   //the read the second oldest log data in NVRAM and write it to EM file second,
                   //the reason is EF LND is FILO file type and we need the keep the latest log data is the first one in EF LND file
                    control_block->proc_stage = SYNC_READ; /* index will be set to 0xFFFF */
                    control_block->data = NULL;
                    phb_read_ln_from_nvram(control_block);
                    return;
                }
            }
            else
            {
                /* SIM card fail, don't write to SIM */
                phb_sync_confirm(PHB_ERRNO_FAIL, control_block);
                return;
            }
        }
        else if (control_block->proc_stage == SYNC_READ)
        {
           //read NVRAM record from NVRAM which may contain <10 log data,
            nvram_read_cnf_struct *msg_ptr = NULL;

            msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
            {
                hold_peer_buff(ilm_ptr->peer_buff_ptr);
                control_block->peer_buf_ptr = ilm_ptr->peer_buff_ptr;
                control_block->index = 0xFFFF;

                //if dial log data number is larger than 10 (more than one NVRAM record), 
                //read next NVRAM record tegether first.
                //this a a bad design based on the old old old limitation designed done on 2004?: only support no more than 20 log data for each log type?
                if (control_block->total > 1)
                {
                    /* NVRAM has more than one LND LID, continue to read */
                    control_block->proc_stage = SYNC_READ_CONTINUE;
                    control_block->secondary_ID++;
                    //read next nvram record
                    phb_read_ln_from_nvram(control_block);
                    return;
                }
                else //if only one NVRAM record need to read (dail log number <=10, but may be max nuber >10)
                {
                    /* NVRAM only has one LND LID, prepare to write to SIM */
                    //Jo: here. to determine if all are voip entry.
                    //do some special case for VOIP, just skip VOIP log data, as EF LND not support VOIP log which use IP address instead of phone number
                    phb_set_last_voice_ln_index(control_block);
                    if (control_block->index == 0)
                    {
                        /* No Voice Call LN, stop writing */
                        phb_sync_confirm(PHB_ERRNO_SUCCESS, control_block);
                        return;
                    }
                    //two NVRAM record is read, start to write them to SIM card
                    //as most SIM card only support 10 or 20 log data, may no need read more NVRAM record now even dail log number may be >20
                    control_block->proc_stage = SYNC_WRITE_CONTINUE;
                    phb_write_ln_to_sim(control_block);
                    return;
                }
            }
            else
            {
                /* read NVRAM fail, don't write to SIM */
                phb_sync_confirm(PHB_ERRNO_READ_FAIL, control_block);
                return;
            }
        }
        else if (control_block->proc_stage == SYNC_READ_CONTINUE)
        {
          //need to read next nvram record, read it here
            nvram_read_cnf_struct *msg_ptr = NULL;

            msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
            {
                hold_peer_buff(ilm_ptr->peer_buff_ptr);
                control_block->data = (void*)ilm_ptr->peer_buff_ptr;
            }
            /* all NVRAM LND LIDs are read, prepare to write to SIM */
            //skip VOIP log data
            phb_set_last_voice_ln_index(control_block);
            if (control_block->index == 0)
            {
            #if (MAX_PHB_LN_ENTRY > 20)
                if (control_block->total > 2)
                {
                    if (control_block != NULL)
                    {
                        if (control_block->peer_buf_ptr != NULL)
                        {
                            free_peer_buff(control_block->peer_buf_ptr);
                            control_block->peer_buf_ptr = NULL;
                        }
                        if (control_block->data != NULL)
                        {
                            free_peer_buff((peer_buff_struct*) control_block->data);
                            control_block->data = NULL;
                        }
                    }
                    control_block->proc_stage = SYNC_READ; /* index will be set 0xFFFF */
                    control_block->total -= 2;
                    if (control_block->total > 1)
                    {
                        control_block->seg_total = 2 * PHB_MAX_LN_ENTRIES;
                        control_block->secondary_ID -= 3;
                    }
                    else
                    {
                        control_block->secondary_ID -= 2;
                        control_block->seg_total = PHB_MAX_LN_ENTRIES;
                    }
                    control_block->data = NULL;
                    phb_read_ln_from_nvram(control_block);
                    return;
                }
                else
            #endif /* (MAX_PHB_LN_ENTRY > 20) */
                {
                    /* No Voice Call LN, stop writing */
                    phb_sync_confirm(PHB_ERRNO_SUCCESS, control_block);
                    return;
                }
            }
            else
            {
                //start to write
                control_block->proc_stage = SYNC_WRITE_CONTINUE;
                phb_write_ln_to_sim(control_block);
            }
            return;
        }
        else if (control_block->proc_stage == SYNC_WRITE_CONTINUE)
        {
          //do the write to SIM work here, it may be called several time
            sim_write_cnf_struct *msg_ptr = NULL;

            msg_ptr = (sim_write_cnf_struct*) ilm_ptr->local_para_ptr;

            //check if the last write action is OK, if OK, do next write work,
            //the log data is write one by one in async mode
            if (msg_ptr->result == SIM_CMD_SUCCESS)
            {
                //control_block->index--;
                if (control_block->index > 0)
                {
                    phb_set_last_voice_ln_index(control_block);
                }
                if (control_block->index == 0)
                {
                #if (MAX_PHB_LN_ENTRY > 20)
                    if (control_block->total > 2)
                    {
                        if (control_block != NULL)
                        {
                            if (control_block->peer_buf_ptr != NULL)
                            {
                                free_peer_buff(control_block->peer_buf_ptr);
                                control_block->peer_buf_ptr = NULL;
                            }
                            if (control_block->data != NULL)
                            {
                                free_peer_buff((peer_buff_struct*) control_block->data);
                                control_block->data = NULL;
                            }
                        }
                        //if need read more data from NVRAM and write to SIM, do it again.
                        control_block->proc_stage = SYNC_READ; /* index will be set 0xFFFF */
                        control_block->total -= 2;
                        if (control_block->total > 1)
                        {
                            control_block->seg_total = 2 * PHB_MAX_LN_ENTRIES;
                            control_block->secondary_ID -= 3;
                        }
                        else
                        {
                            control_block->secondary_ID -= 2;
                            control_block->seg_total = PHB_MAX_LN_ENTRIES;
                        }
                        control_block->data = NULL;
                        phb_read_ln_from_nvram(control_block);
                        return;
                    }
                    else
                #endif /* (MAX_PHB_LN_ENTRY > 20) */
                    /* No Voice Call LN, stop writing */
                    {
                        phb_sync_confirm(PHB_ERRNO_SUCCESS, control_block);
                        return;
                    }
                }
                else
                {
                    phb_write_ln_to_sim(control_block);
                return;
                }
            }
            else
            {
                /* SIM card fail, don't write to SIM */
                phb_sync_confirm(PHB_ERRNO_FAIL, control_block);
                return;
            }
        }
    }
    #endif /* __PHB_NVRAM_LN_ONLY__ */ 
}
#else /* __VOIP__ */


/*****************************************************************************
 * FUNCTION
 *  phb_sync_handler
 * DESCRIPTION
 *  This is phb_sync_handler function of PHB module.
 *  Handles sync request from L4C when power off.
 *  Copyies LND records from NVRAM to SIM, if supported
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [IN/OUT]         
 * RETURNS
 *  void
 *****************************************************************************/

//its a copy and is bad habit to do this
void phb_sync_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr != NULL)
    {
    #ifdef __PHB_NVRAM_LN_ONLY__
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_SYNC_CNF, NULL, NULL);
        return;
    #else /* __PHB_NVRAM_LN_ONLY__ */ 
        /* Cannot allocate, means that PHB is still operating. Reject request! */
        if (control_block == NULL)
        {
            control_block = phb_alloc_control_block();
            if (control_block == NULL)
            {
                phb_sync_confirm(PHB_ERRNO_BUSY, control_block);
                return;
            }
            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;
        }

        if (control_block->proc_stage == SYNC_NONE)
        {
            control_block->proc_stage = SYNC_READ_FILE;
            control_block->IO_cnf_receive = phb_sync_handler;
            control_block->err_handler = phb_sync_err_handler;
            
            if (PHB_SIM_SERVICE_TABLE_QUERY(SERVICE_LND) == KAL_TRUE)
            {
                sim_file_info_req_struct *param_ptr;

                /* SIM card supports LND, get file info */
                param_ptr = (sim_file_info_req_struct*)
                    construct_local_para((kal_uint16) sizeof(sim_file_info_req_struct), TD_CTRL);

                param_ptr->file_idx = FILE_LND_IDX;
                param_ptr->access_id = control_block->ID;
                param_ptr->info_type = SIM_REC_SIZE;
            
                phb_send_ilm(MOD_SIM, MSG_ID_SIM_FILE_INFO_REQ, param_ptr, NULL);
                return;
            }
            else
            {
                /* SIM card doesn't support LND, no need to sync */
                phb_sync_confirm(PHB_ERRNO_SUCCESS, control_block);
                return;
            }
        }
        else if (control_block->proc_stage == SYNC_READ_FILE)
        {
            sim_file_info_cnf_struct *msg_ptr = NULL;

            msg_ptr = (sim_file_info_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == SIM_CMD_SUCCESS)
            {
            #if (MAX_PHB_LN_ENTRY > 20)
                kal_uint8 total;
            #endif 
                if (msg_ptr->num_of_rec == 0)
                {
                    /* SIM card LND num is 0l, stop writing */
                    phb_sync_confirm(PHB_ERRNO_SUCCESS, control_block);
                    return;
                }
                control_block->seg_len = msg_ptr->file_size / msg_ptr->num_of_rec;
            #if (MAX_PHB_LN_ENTRY > 20)
                total = phb_get_ln_total_entry(PHB_LND);
                if (total < msg_ptr->num_of_rec)
                {
                    control_block->seg_total = total;
                }
                else
            #endif /* MAX_PHB_LN_ENTRY > 20 */
                    /* save SIM card LND file info, read NVRAM LND data */
                    control_block->seg_total = msg_ptr->num_of_rec;
                control_block->length = msg_ptr->file_size;

                control_block->index = msg_ptr->num_of_rec;
                control_block->proc_stage = SYNC_ERASE_SIM;
            #if (MAX_PHB_LN_ENTRY > 20)
                control_block->total = (control_block->seg_total + PHB_MAX_LN_ENTRIES - 1) / PHB_MAX_LN_ENTRIES;
                if (control_block->total > 2)
                {
                    control_block->secondary_ID = PHB_LND_LID_START + control_block->total - 2;
                }
                else
                {
                    control_block->secondary_ID = PHB_LND_LID_START;
                }
                control_block->actual_count = control_block->seg_total;
                control_block->seg_total -=
                    ((control_block->secondary_ID - PHB_LND_LID_START) * PHB_MAX_LN_ENTRIES);
            #else /* (MAX_PHB_LN_ENTRY > 20) */ 
                control_block->secondary_ID = PHB_LND_LID_START;
                control_block->total = PHB_TOT_LND_LIDS;
            #endif /* MAX_PHB_LN_ENTRY > 20 */
            #if defined(__GEMINI__) || defined(__SGLTE__)
                if (phb_current_mod == MOD_PHB_2)
                {
                    control_block->secondary_ID += PHB_TOTAL_LN_LID;
                }
            #endif /* __GEMINI__ || __SGLTE__ */
                control_block->data = NULL;
                phb_write_ln_to_erase_sim(control_block);
                return;
            }
            else
            {
                /* SIM card fail, don't write to SIM */
                phb_sync_confirm(PHB_ERRNO_READ_FAIL, control_block);
                return;
            }
        }
        else if (control_block->proc_stage == SYNC_ERASE_SIM)
        {
            sim_write_cnf_struct *msg_ptr = NULL;

            msg_ptr = (sim_write_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == SIM_CMD_SUCCESS)
            {
                control_block->index--;
                if (control_block->index > 0)
                {
                    phb_write_ln_to_erase_sim(control_block);
                    return;
                }
                else
                {
                    control_block->proc_stage = SYNC_READ; /* index will be set to 0xFFFF */
                    control_block->data = NULL;
                    phb_read_ln_from_nvram(control_block);
                    return;
                }
            }
            else
            {
                /* SIM card fail, don't write to SIM */
                phb_sync_confirm(PHB_ERRNO_FAIL, control_block);
                return;
            }
        }
        else if (control_block->proc_stage == SYNC_READ)
        {
            nvram_read_cnf_struct *msg_ptr = NULL;

            msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
            {
                hold_peer_buff(ilm_ptr->peer_buff_ptr);
                control_block->peer_buf_ptr = ilm_ptr->peer_buff_ptr;

                if (control_block->total > 1)
                {
                    /* NVRAM has more than one LND LID, continue to read */
                    control_block->proc_stage = SYNC_READ_CONTINUE;
                    control_block->secondary_ID++;
                    phb_read_ln_from_nvram(control_block);
                    return;
                }
                else
                {
                    /* NVRAM only has one LND LID, prepare to write to SIM */
                    control_block->index = 0;
                    control_block->proc_stage = SYNC_WRITE_CONTINUE;
                    phb_write_ln_to_sim(control_block);
                    return;
                }
            }
            else
            {
                /* read NVRAM fail, don't write to SIM */
                phb_sync_confirm(PHB_ERRNO_READ_FAIL, control_block);
                return;
            }
        }
        else if (control_block->proc_stage == SYNC_READ_CONTINUE)
        {
            nvram_read_cnf_struct *msg_ptr = NULL;

            msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
            {
                hold_peer_buff(ilm_ptr->peer_buff_ptr);
                control_block->data = (void*)ilm_ptr->peer_buff_ptr;
            }
            /* all NVRAM LND LIDs are read, prepare to write to SIM */
            control_block->index = 0;
            control_block->proc_stage = SYNC_WRITE_CONTINUE;
            phb_write_ln_to_sim(control_block);
            return;
        }
        else if (control_block->proc_stage == SYNC_WRITE_CONTINUE)
        {
            sim_write_cnf_struct *msg_ptr = NULL;

            msg_ptr = (sim_write_cnf_struct*) ilm_ptr->local_para_ptr;
            if (msg_ptr->result == SIM_CMD_SUCCESS)
            {
                if (control_block->index < control_block->seg_total)
                {
                    /* SIM card LND still has space, continue to write */
                    phb_write_ln_to_sim(control_block);
                    return;
                }
            #if (MAX_PHB_LN_ENTRY > 20)
                if (control_block->index < control_block->actual_count)
                {
                    if (control_block != NULL)
                    {
                        if (control_block->peer_buf_ptr != NULL)
                        {
                            free_peer_buff(control_block->peer_buf_ptr);
                            control_block->peer_buf_ptr = NULL;		
                        }
                        if (control_block->data != NULL)
                        {
                            free_peer_buff((peer_buff_struct*) control_block->data);
                            control_block->data = NULL;
                        }
                    }
                    control_block->proc_stage = SYNC_READ;
                    control_block->actual_count -= control_block->seg_total;
                    control_block->total = control_block->actual_count / PHB_MAX_LN_ENTRIES;
                    if (control_block->total > 1)
                    {
                        control_block->secondary_ID -= 3;
                    }
                    else
                    {
                        control_block->secondary_ID -= 2;
                    }
                    if (control_block->actual_count > PHB_MAX_LN_ENTRIES)
                    {
                        control_block->seg_total = 2 * PHB_MAX_LN_ENTRIES;
                    }
                    else
                    {
                        control_block->seg_total = PHB_MAX_LN_ENTRIES;
                    }
                    control_block->data = NULL;
                    phb_read_ln_from_nvram(control_block);
                    return;
                }
            #endif /* MAX_PHB_LN_ENTRY > 20 */
                else
                {
                    /* SIM card LND full, stop writing */
                    phb_sync_confirm(PHB_ERRNO_SUCCESS, control_block);
                    return;
                }
            }
            else
            {
                /* SIM card fail, don't write to SIM */
                phb_sync_confirm(PHB_ERRNO_FAIL, control_block);
                return;
            }
        }
    }
    #endif /* __PHB_NVRAM_LN_ONLY__ */ 
}
#endif /* __VOIP__ */

/*****************************************************************************
 * FUNCTION
 *  phb_write_ln_err_handler
 * DESCRIPTION
 *  Error handle
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_write_ln_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    phb_write_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
}


/*****************************************************************************
 * FUNCTION
 *  phb_write_ln_handler
 * DESCRIPTION
 *  This is phb_write_ln_handler function of PHB module.
 *  Handles write last number request from L4C.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_write_ln_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr != NULL) //check if first idle status
    {
        if (control_block == NULL)  //first to allocate control buffer
        {
            l4cphb_write_ln_req_struct *msg_ptr = NULL;

            msg_ptr = (l4cphb_write_ln_req_struct*) ilm_ptr->local_para_ptr;

            control_block = phb_alloc_control_block();
            /* Cannot allocate, means that PHB is still operating. Reject request! */
            if (control_block == NULL)
            {
                phb_write_ln_confirm(PHB_ERRNO_BUSY, msg_ptr->src_id, control_block);
                return;
            }
            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;
            control_block->src_id = msg_ptr->src_id;
        }
        //start the write work first time, first to read the nvram record back to check if need to merge
        //for MAX_PHB_LN_ENTRY <=20 which means there no more than 2 nvram record for each log type (ex missed call),
        //just need to read these two nvram record back and check if has the same phone number log data exists already,
        //if so, just merge it and shift it to the first position and shift others.
        //but if MAX_PHB_LN_ENTRY > 20, not support merge here due to performace and storage design limiation 
        if (control_block->proc_stage == WRITE_LN_NONE)
        {
            kal_uint16 length;
            l4cphb_write_ln_req_struct *msg_ptr = (l4cphb_write_ln_req_struct*) ilm_ptr->local_para_ptr;
            l4cphb_phb_ln_entry_array_struct *pdu_data;

            pdu_data = (l4cphb_phb_ln_entry_array_struct*) get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &length);

            ASSERT(msg_ptr->total <= PHB_MAX_LN_ENTRIES);
            /* save req info */
            //set to next status and set the parse handler and error handler...
            control_block->proc_stage = WRITE_LN_READ;
            control_block->IO_cnf_receive = phb_write_ln_handler;
            control_block->err_handler = phb_write_ln_err_handler;
            control_block->type = (phb_type_enum)msg_ptr->type;
            control_block->src_id = msg_ptr->src_id;
            control_block->total_piggyback = msg_ptr->total;
            control_block->index = msg_ptr->index;

            /* keep entry to be written in peer_buf_ptr */
            hold_peer_buff(ilm_ptr->peer_buff_ptr);
            control_block->need_free_peer = KAL_TRUE;
            control_block->peer_buf_ptr = ilm_ptr->peer_buff_ptr;

            control_block->temp_ln_entry = (phb_ln_entry_struct*)
                    get_ctrl_buffer(sizeof(phb_ln_entry_struct));
            
            memcpy((kal_uint8*) control_block->temp_ln_entry, (kal_uint8*) pdu_data->array, sizeof(phb_ln_entry_struct));

            //get the nvram record start index
            //ex: MAX_PHB_LN_ENTRY = 30, missed log NVRAM record is 4~6(from 1, no 0), 
            //seg_total =: 30/10 = 3, secondary_ID = 4 (the first index is 1 not 0 for NVRAM)
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

            //add the nvram record shift of the log data to write
            //ex: MAX_PHB_LN_ENTRY = 30, missed log NVRAM record is 4~6(from 1, no 0), 
            //if want to read 26 missed log,  the shift it 26/10 = 2, so, secondary_ID += 2 is 6
            if (msg_ptr->index != 0xff)
            {
                control_block->seg_total = 1;
                control_block->secondary_ID += msg_ptr->index / PHB_MAX_LN_ENTRIES;
            }

            //for gemini, add the SIM shift (it's 6 in this example)
        #if defined(__GEMINI__) || defined(__SGLTE__)
            if (phb_current_mod == MOD_PHB_2)
            {
                control_block->secondary_ID += PHB_TOTAL_LN_LID;
            }
        #endif /* __GEMINI__ || __SGLTE__  */
            phb_read_ln_from_nvram(control_block);
            return;
        }
        else if (control_block->proc_stage == WRITE_LN_READ)
        {
          //read the 1st nvram record
            kal_bool updated;
            //kal_uint16 length;
            nvram_read_cnf_struct *msg_ptr = NULL;
            //nvram_ef_phb_ln_struct *pdu_data;

            msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;
            control_block->IO_stage = IO_NONE;

            if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
            {
                //pdu_data = (nvram_ef_phb_ln_struct*) get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &length);

                /* keep first read data in control_block->data */
                hold_peer_buff(ilm_ptr->peer_buff_ptr);
                control_block->data = (kal_uint8*) ilm_ptr->peer_buff_ptr;

               //check if need to read more nvram record
                if (control_block->seg_total > 1)
                {
                    control_block->secondary_ID++;
                    control_block->proc_stage = WRITE_LN_READ_CONTINUE;
                    control_block->seg_total--;
                    phb_read_ln_from_nvram(control_block);
                    return;
                }
                else
                {
                   // if one one nvram record need to read, just check if need to merge and update it
                    control_block->proc_stage = WRITE_LN_WRITE;

                    if (control_block->index == 0xff)
                    {
                        updated = phb_update_ln(NULL, control_block);   /* for ln_10 or not full ln_50 */
                    }
                    else
                    {
                        updated = phb_edit_ln(control_block);
                    }

                    //if just update, the order of nvram record is already shifted reorder finished, just write 
                    //this nvram record back

                    if (updated == KAL_TRUE)
                    {
                        /* write LND file */
                        phb_write_ln_to_nvram(NULL, control_block);
                        return;
                    }
                }
            }
            /* 1. NVRAM IO Err      2. se_total is 1 and updated is FALSE */
            phb_write_ln_confirm(PHB_ERRNO_READ_FAIL, control_block->src_id, control_block);
        }
        else if (control_block->proc_stage == WRITE_LN_READ_CONTINUE)
        {
        // read next nvram record done
            kal_bool updated;
            kal_uint16 length;
            nvram_read_cnf_struct *msg_ptr = NULL;
            nvram_ef_phb_ln_struct *pdu_data;

            msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;
            control_block->IO_stage = IO_NONE;

            if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
            {
                pdu_data = (nvram_ef_phb_ln_struct*) get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &length);

               //check if update it
                updated = phb_update_ln(pdu_data, control_block);
                if (control_block->seg_total > 0)
                {
                    control_block->seg_total--;
                }

                 //if can update, write it back to NVRAM

                if (updated == KAL_TRUE)
                {
                    control_block->proc_stage = WRITE_LN_WRITE_CONTINUE;

                    /* write second file */
                    phb_write_ln_to_nvram(pdu_data, control_block);
                    return;
                }
            }
            /* 1. NVRAM IO Err      2. updated is FALSE */
            phb_write_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
        }
        else if (control_block->proc_stage == WRITE_LN_WRITE_CONTINUE)
        {
            nvram_write_cnf_struct *msg_ptr = NULL;

            msg_ptr = (nvram_write_cnf_struct*) ilm_ptr->local_para_ptr;
            control_block->IO_stage = IO_NONE;

            if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
            {
                control_block->proc_stage = WRITE_LN_WRITE;
                control_block->secondary_ID--;

                /* write first file */
                phb_write_ln_to_nvram(NULL, control_block);
                return;
            }
            /* NVRAM IO Err */
            phb_write_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
        }
        else if (control_block->proc_stage == WRITE_LN_WRITE)
        {
           //start to write the 1st nvram record read to NVRAM
            nvram_write_cnf_struct *msg_ptr = NULL;

            msg_ptr = (nvram_write_cnf_struct*) ilm_ptr->local_para_ptr;
            control_block->IO_stage = IO_NONE;

            if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
            {
              //if more record and more log data need to shift, need to read 3rd or next nvram record back
              //read it.
              //ex MAX_PHB_LN_ENTRY = 50, total 45 log now, when a new log data is added
              // this new log should be the the 1st postion of the 1st nvram record of this log type
              //so all the existing 46 log data should be shift to next position, to do this, we need
              //to read each nvram record and move it's last log data to next nvram record and move the last log
              //data of the preview record to it's first log data slot.
              //a bad design with very low performance
              
            #if (MAX_PHB_LN_ENTRY > 20)
                if (control_block->seg_total > 0)
                {
                    control_block->secondary_ID += 2;   /* back to second from first and then plus 1 to 3 */
                    control_block->proc_stage = WRITE_LN_READ;
                    if (control_block->data != NULL)
                    {
                        free_peer_buff((peer_buff_struct*) control_block->data);
                        control_block->data = NULL;
                    }
                    phb_read_ln_from_nvram(control_block);
                }
                else
            #endif /* MAX_PHB_LN_ENTRY > 20 */
                    phb_write_ln_confirm(PHB_ERRNO_SUCCESS, control_block->src_id, control_block);
            }
            else
            {
                phb_write_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
            }
        }
        else
        {
            /* wrong proc_stage for write_ln_handler */
            phb_write_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
        }
    }
    else
    {
        phb_write_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
    }
}


#if (MAX_PHB_LN_ENTRY > 20)
/*****************************************************************************
 * FUNCTION
 *  phb_ln_push_old_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  record      [?]     
 *  record2     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_ln_push_old_entry(nvram_ef_phb_ln_struct *record, nvram_ef_phb_ln_struct *record2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phb_ln_entry_struct buffer_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //here,  record is the previous nvram record,  record2 is current nvram record

    //copy the last log data to buffer_entry
    kal_mem_cpy(&buffer_entry, &record2->array[PHB_MAX_LN_ENTRIES - 1], sizeof(phb_ln_entry_struct));
    //shift all the log data to next position in this nvram record to make 1st slot empty
    if (record2->no_entry > 0)
    {
        phb_shift_ln((kal_uint8) (record2->no_entry - 1), record2);
    }
    //copy the last log data of the previous nvram record to the first slot of current nvram record
    kal_mem_cpy(&record2->array[0], &record->array[PHB_MAX_LN_ENTRIES - 1], sizeof(phb_ln_entry_struct));

    //shift all the log data to next position in the previous nvram record to make 1st slot empty
    phb_shift_ln((kal_uint8) (record->no_entry - 1), record);

    //copy shifted_entry to the 1st slot of the previous nvram record
    kal_mem_cpy(&record->array[0], &shifted_entry, sizeof(phb_ln_entry_struct));

    //copy bufer_entry to shifted_entry.
    kal_mem_cpy(&shifted_entry, &buffer_entry, sizeof(phb_ln_entry_struct));

    //set count to 1 as not support merge here, reget the number of log data in the current record
    record->array[0].count = 1;
    if (record2->no_entry < PHB_MAX_LN_ENTRIES)
    {
        record2->no_entry++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_ln_push_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  entry       [?]     
 *  record      [?]     
 *  record2     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_ln_push_entry(
                phb_ln_entry_struct *entry,
                nvram_ef_phb_ln_struct *record,
                nvram_ef_phb_ln_struct *record2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (entry)
    {
       //copy the last log data in this NVRAM record(next record) to shifted_entry
        kal_mem_cpy(&shifted_entry, &record2->array[PHB_MAX_LN_ENTRIES - 1], sizeof(phb_ln_entry_struct));

       //shift all log data in the nvram record and make the 1st slot of it empty
        phb_shift_ln((kal_uint8) (record2->no_entry - 1), record2);

       //copy  the last log data of the previous nvram record to the first slot of this nvram record
        kal_mem_cpy(&record2->array[0], &record->array[PHB_MAX_LN_ENTRIES - 1], sizeof(phb_ln_entry_struct));

       //shift all log of the previous record to make the 1st slot of it empty
        phb_shift_ln((kal_uint8) (record->no_entry - 1), record);

       //copy the entry to its 1st slot
        kal_mem_cpy(&record->array[0], entry, sizeof(phb_ln_entry_struct));

       //set log data count, no merge here, so count always is 1
        record->array[0].count = 1;

       //recount the log data entry number
        if (record2->no_entry < PHB_MAX_LN_ENTRIES)
        {
            record2->no_entry++;
        }
    }
    else
    {
        phb_ln_push_old_entry(record, record2);
    }
}
#endif /* MAX_PHB_LN_ENTRY > 20 */


/*****************************************************************************
 * FUNCTION
 *  phb_shift_ln
 * DESCRIPTION
 *  To shift all log data in the record to next position, 
 *  please note, the last log data is erased and should be copied before this action
 * PARAMETERS
 *  end_index       [IN]        
 *  data            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_shift_ln(kal_uint8 end_index, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 i;
    nvram_ef_phb_ln_struct *record;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    record = (nvram_ef_phb_ln_struct*) data;

    /* handle the last entry */
    if (end_index + 1 < PHB_MAX_LN_ENTRIES)
    {
        kal_mem_cpy(&record->array[end_index + 1], &record->array[end_index], sizeof(phb_ln_entry_struct));
    }
    for (i = end_index - 1; (i >= 0 && (i + 1) < NVRAM_EF_PHB_LN_SIZE); i--)
    {
        kal_mem_cpy(&record->array[i + 1], &record->array[i], sizeof(phb_ln_entry_struct));
    }
}


#ifdef __PHB_RECORD_LN_TYPE_SEQ__
/*****************************************************************************
 * FUNCTION
 *  phb_shift_ln_type_seq
 * DESCRIPTION
 *  This is phb_shift_ln_type_seq function of PHB module.
 *  Shift the ln type sequence to the right position
 *  from latest(0) to oldest(PHB_TOTAL_LN_ENTRIES-1).
 * PARAMETERS
 *  del_seq_index       [IN]        
 *  type                [IN]        
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void phb_shift_ln_type_seq(kal_uint16 del_seq_index, kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i = 0;
    kal_uint16 del_index = PHB_TOTAL_LN_ENTRIES - 1;
    kal_uint8 update_type = phb_ln_type_seq[0];
    kal_uint8 tmp_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (del_seq_index > 0)
    {
        for (del_index = PHB_TOTAL_LN_ENTRIES - 1; del_seq_index > 0; del_index--)
        {
            if (phb_ln_type_seq[del_index] == type)
            {
                del_seq_index--;
            }
            if (del_index == 0) /* in case the nvram data item is missing */
            {
                break;
            }
        }
        del_index++;
    }
    while (i < del_index && phb_ln_type_seq[i] != 0xff)
    {
        tmp_type = phb_ln_type_seq[i + 1];
        phb_ln_type_seq[i + 1] = update_type;
        update_type = tmp_type;
        i++;
    }
    phb_ln_type_seq[0] = type;
}


/*****************************************************************************
 * FUNCTION
 *  phb_write_ln_type_seq_handler
 * DESCRIPTION
 *  This is phb_write_ln_type_seq_handler function of PHB module.
 *  Handles write last number type seqence for mixed call log.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_write_ln_type_seq_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (control_block == NULL)
    {
        control_block = phb_alloc_control_block();
        ASSERT(control_block != NULL);
    }

    if (control_block->proc_stage == WRITE_LN_TYPE_SEQ_NONE)
    {
        control_block->IO_cnf_receive = phb_write_ln_type_seq_handler;
        control_block->proc_stage = WRITE_LN_TYPE_SEQ_CONTINUE;
        /* control_block->secondary_ID = 1; */
        phb_write_ln_type_seq_to_nvram(control_block);
        return;
    }
    else if (control_block->proc_stage == WRITE_LN_TYPE_SEQ_CONTINUE)
    {
        nvram_write_cnf_struct *msg_ptr = NULL;

        msg_ptr = (nvram_write_cnf_struct*) ilm_ptr->local_para_ptr;
        control_block->IO_stage = IO_NONE;
        //if (control_block->data != NULL)
        //   free_peer_buff ((peer_buff_struct *)control_block->data);
        if (control_block->need_free_peer == KAL_TRUE)
        {
            free_peer_buff(control_block->peer_buf_ptr);
            control_block->peer_buf_ptr = NULL;
        }
        phb_free_control_block(control_block);
        if (msg_ptr->result != NVRAM_IO_ERRNO_OK)
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_ABNORMAL);
        }
    }
}
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_write_ln_confirm
 * DESCRIPTION
 *  This is phb_write_ln_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  src_id              [IN]        
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_write_ln_confirm(phb_errno_enum result, kal_uint8 src_id, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cphb_write_ln_cnf_struct *param_ptr;
    peer_buff_struct *peer_buf_ptr = NULL;
    l4cphb_phb_ln_entry_array_struct *pdu_stream_ptr;
#ifdef __PHB_RECORD_LN_TYPE_SEQ__
   	kal_uint16 index;
#endif
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     //this API so to do some post-handling work, ex free control buffer, free peer buffer,
     //save log data type order to nvram, return error code to higher layer...

    param_ptr = (l4cphb_write_ln_cnf_struct*)
        construct_local_para((kal_uint16) sizeof(l4cphb_write_ln_cnf_struct), TD_CTRL);

    param_ptr->src_id = src_id;
    param_ptr->result = result;
    param_ptr->cause = 0;
    param_ptr->total = 0;
    param_ptr->type = 0;

    if (result != PHB_ERRNO_BUSY)
    {
        ASSERT(control_block != NULL);
        param_ptr->type = (kal_uint8) control_block->type;

        param_ptr->total = control_block->total;

        if ((result == PHB_ERRNO_SUCCESS) && (control_block->total_piggyback > 0))
        {
            param_ptr->total = control_block->total_piggyback;
        }

        if (control_block->data != NULL)
        {
            free_peer_buff((peer_buff_struct*) control_block->data);
        }
        if (control_block->need_free_peer == KAL_TRUE)
        {
            free_peer_buff(control_block->peer_buf_ptr);
        }
        if (control_block->temp_ln_entry != NULL)
        {
            pdu_stream_ptr = (l4cphb_phb_ln_entry_array_struct*)
                l4cphb_alloc_ln_peer_buf(&peer_buf_ptr, 1);

            kal_mem_cpy(&pdu_stream_ptr->array[0], (kal_uint8*)control_block->temp_ln_entry, sizeof(phb_ln_entry_struct));
            free_ctrl_buffer(control_block->temp_ln_entry);
        }

    #ifdef __PHB_RECORD_LN_TYPE_SEQ__
    	index = control_block->index;
    #endif 
        phb_free_control_block(control_block);
      
    #ifdef __PHB_RECORD_LN_TYPE_SEQ__
        if (result == PHB_ERRNO_SUCCESS && index == 0xff)
        /* only update when "add new", no update for :edit" */
        {
        #ifdef __PHB_LN_SINGLE_COUNT__
            if (phb_get_ln_total_entry(param_ptr->type) == PHB_MAX_LNM_ENTRIES)
            {
                /* full */
                phb_shift_ln_type_seq(1, param_ptr->type);
            }
            else
            {
                /* add new entry for type seq */
                phb_shift_ln_type_seq(0, param_ptr->type);
            }
        #endif /* __PHB_LN_SINGLE_COUNT__ */ 

            phb_write_ln_type_seq_handler(NULL, NULL);
        }
    #endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
    }
    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_WRITE_LN_CNF, param_ptr, peer_buf_ptr);
}   /* end of phb_write_ln_confirm */


#ifndef __PHB_LN_SINGLE_COUNT__
#ifdef __PHB_RECORD_LN_TYPE_SEQ__


/*****************************************************************************
 * FUNCTION
 *  phb_update_ln_type_seq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos         [IN]        
 *  total       [IN]        
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static phb_update_ln_type_seq(kal_uint16 pos, kal_uint16 total, kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pos == total)
    {
        if (total == PHB_MAX_LNM_ENTRIES)
        {
            /* full */
            phb_shift_ln_type_seq(1, type);
        }
        else
        {
            /* add new entry for type seq */
            phb_shift_ln_type_seq(0, type);
        }
    }
    else if (pos == 0 && total > 0) /* itself */
    {
        phb_shift_ln_type_seq(total, type);
    }
    else
    {
        phb_shift_ln_type_seq(pos, type);
    }
}
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 

#endif /* __PHB_LN_SINGLE_COUNT__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_update_ln
 * DESCRIPTION
 *  
 * PARAMETERS
 *  record              [?]     
 *  control_block       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool phb_update_ln(nvram_ef_phb_ln_struct *record, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 total, i;
    kal_uint8 *pdu_ptr;
    kal_uint16 len;
    phb_ln_entry_struct *entry = NULL;
    l4cphb_phb_ln_entry_array_struct *pdu_data = NULL;
    nvram_ef_phb_ln_struct *record0 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* The entry to by update is saved in this peer buffer, so it never by NULL here */
    if (control_block->need_free_peer)
    {
        /* get entry to be written */
        pdu_ptr = get_peer_buff_pdu(control_block->peer_buf_ptr, &len);

        pdu_data = (l4cphb_phb_ln_entry_array_struct*) get_32bits_aligned_val(pdu_ptr);

        entry = (phb_ln_entry_struct*) & pdu_data->array[0]; /* Only one entry updated one time, so only get array[0] */
        ASSERT(entry != NULL);
		//Fixed MAUI_02963900 - MTK60048 Victor.Ju
        //entry->call_duration = 0;
    }

    /* When update, L4PHB will read two records, the record with the entry to be updated and the next record */
    record0 = (nvram_ef_phb_ln_struct*) get_peer_buff_pdu((peer_buff_struct*) control_block->data, &len);

    ASSERT(record0 != NULL);
    if (record != NULL)
    {
        total = record->no_entry + record0->no_entry;
    }
    else
    {
        total = record0->no_entry;
    }

#ifdef __PHB_LN_SINGLE_COUNT__  /* Non-Merge scenario: don't need to find the same record */

    i = total;

#else /* __PHB_LN_SINGLE_COUNT__ */ 

    /* Find the one can be merged */
    for (i = 0; i < total; i++)
    {
        if (i < PHB_MAX_LN_ENTRIES) /* First to traverse the first record */
        {
#ifdef __VOIP__
            if (entry->addr_type == PHB_LN_VOIP && record0->array[i].addr_type == PHB_LN_VOIP &&
                strcmp((char*)entry->addr_bcd, (char*)record0->array[i].addr_bcd) == 0)
            {
                break;
            }
            else if (entry->addr_type == PHB_LN_CALL&& record0->array[i].addr_type == PHB_LN_CALL)
#endif /* __VOIP__ */
            if (phb_compare_bcd_for_wild_char(
                    entry->addr_length,
                    record0->array[i].addr_length,
                    (kal_uint8*) entry->addr_bcd,
                    (kal_uint8*) record0->array[i].addr_bcd) == KAL_TRUE)
            {
                //kal_mem_cpy((kal_uint8*) record0->array[i].addr_bcd, (kal_uint8*) entry->addr_bcd, MAX_CC_ADDR_LEN);
                break;
            }
        }
        else if (record != NULL) /* Can  not find it in the first record, try to traverse the second record */
        {
#ifdef __VOIP__
            if (entry->addr_type == PHB_LN_VOIP && record0->array[i - PHB_MAX_LN_ENTRIES].addr_type == PHB_LN_VOIP &&
                strcmp((char*)entry->addr_bcd, (char*)record0->array[i - PHB_MAX_LN_ENTRIES].addr_bcd) == 0)
            {
                break;
            }
            else if (entry->addr_type == PHB_LN_CALL&& record0->array[i].addr_type == PHB_LN_CALL)
#endif /* __VOIP__ */
            {
                if (phb_compare_bcd_for_wild_char(
                        entry->addr_length,
                        record->array[i - PHB_MAX_LN_ENTRIES].addr_length,
                        (kal_uint8*) entry->addr_bcd,
                        (kal_uint8*) record->array[i - PHB_MAX_LN_ENTRIES].addr_bcd) == KAL_TRUE)
                {
                    //kal_mem_cpy((kal_uint8*) record0->array[i - PHB_MAX_LN_ENTRIES].addr_bcd, (kal_uint8*) entry->addr_bcd, MAX_CC_ADDR_LEN);
                    break;
                }
            }
        }
        else /* Both two records (at most 20 entries) are checked, not find anyone can be merged, the i is total now, just need to add a new entry */
        {
            break;
        }
    }

#ifdef __PHB_RECORD_LN_TYPE_SEQ__

    /* Update the LN type sequence */ 
    phb_update_ln_type_seq((kal_uint16)i, (kal_uint16)total, (kal_uint8) control_block->type);

#endif

#endif /* __PHB_LN_SINGLE_COUNT__ */ 

#if (MAX_PHB_LN_ENTRY > 20)

#if 0  /* Not support here as not know which is the readly 1st here as this API can be re-called for more than one time */
/* under construction !*/
#ifdef __PHB_LN_CONSECUTIVE_MERGE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__PHB_LN_CONSECUTIVE_MERGE__ */
/* under construction !*/
#endif //0

    if (control_block->seg_total > 1 && total == PHB_MAX_LN_ENTRIES * 2)
    {
        /* no empty space, update the first 2 LN entries first. */
        phb_ln_push_entry(entry, record0, record);
    }
    else if (total < PHB_MAX_LN_ENTRIES)
    {
        /* file still has space, add new entry and update in file 1 */
        if (record0->no_entry > 0)
        {
            phb_shift_ln((kal_uint8) (record0->no_entry - 1), record0);
        }
        if (!entry) /* The entry is released. Not the first round. */
        {
            kal_mem_cpy(&record0->array[0], &shifted_entry, sizeof(phb_ln_entry_struct));
            control_block->seg_total = 0;
        }
        else
        {
            kal_mem_cpy(&record0->array[0], entry, sizeof(phb_ln_entry_struct));
        }
        record0->array[0].count = 1;
        record0->no_entry++;
        total++;
    }
    else if (total > PHB_MAX_LN_ENTRIES && total < (PHB_MAX_LN_ENTRIES * 2))
    {
        /* file 1 is full, file 2 still has stpace, over write to file 2 */
        if (control_block->seg_total > 0)
        {
            /* not found, add new in file 1 and over write file 2 */
            phb_ln_push_entry(entry, record0, record);
            total++;
            control_block->seg_total = 0;
        }
        else
        {
            /* not found, add new in file 1 and over write file 2 */
            phb_ln_push_new_entry(entry, record0, record);
            total++;
        }
    }
    else if (total == PHB_MAX_LN_ENTRIES)
    {
        if (record != NULL)
        {
            if (control_block->seg_total > 1 || (!entry && record->no_entry == 0))
            {
                phb_ln_push_entry(entry, record0, record);
            }
            else
            {
                /* file 1 is full, file 2 still has stpace, over write to file 2 */
                phb_ln_push_new_entry(entry, record0, record);
            }
            total++;
        }
        else
        {
            /* file 1 is full, corrupt last */
            phb_shift_ln((kal_uint8) (record0->no_entry - 1), record0);
            if (!control_block->need_free_peer)
            {
                /* the last entry */
                kal_mem_cpy(&record0->array[0], &shifted_entry, sizeof(phb_ln_entry_struct));
                if (control_block->seg_total == 1)  /* last one */
                {
                    control_block->seg_total = 0;
                }
            }
            else
            {
                kal_mem_cpy(&record0->array[0], entry, sizeof(phb_ln_entry_struct));
            }
            record0->array[0].count = 1;
        }
    }
    else if (total == PHB_MAX_LN_ENTRIES * 2)
    {
        if (!entry) /* not first round */
        {
            phb_ln_push_entry(entry, record0, record);
        }
        else
        {
            phb_ln_push_new_entry(entry, record0, record);
        }
    }
    record0->array[0].accu_times = 1;
    record0->array[0].is_new_event = 1;
    if (control_block->seg_total > 1 && total < PHB_MAX_LN_ENTRIES * 2) /* treat as only 2 ln records */
    {
        control_block->seg_total = 0;
    }


#else /* (MAX_PHB_LN_ENTRY > 20) */ /* Case: <= 20 */

#ifdef __PHB_LN_CONSECUTIVE_MERGE__

    if (total > 0 && i == 0)
    {
        /* Find it, it must be the first element */
        phb_ln_renew_entry1(i, entry, record0);
    }
    else
    {
        if (total < PHB_MAX_LN_ENTRIES)
        {
            if (record0->no_entry > 0)
            {
                phb_shift_ln((kal_uint8) (record0->no_entry - 1), record0);
            }
            kal_mem_cpy(&record0->array[0], entry, sizeof(phb_ln_entry_struct));
            record0->array[0].accu_times = 1;
            record0->array[0].is_new_event = 1;
            record0->array[0].count = 1;
            record0->no_entry++;
            total++;
        }
        else if (total > PHB_MAX_LN_ENTRIES && total < (PHB_MAX_LN_ENTRIES * 2))
        {
            ASSERT(record != NULL);
            /* not found, add new in file 1 and over write file 2 */
            phb_ln_push_new_entry(entry, record0, record);
            record0->array[0].accu_times = 1;
            record0->array[0].is_new_event = 1;
            total++;

        }
        else if (total == PHB_MAX_LN_ENTRIES)
        {
            if (record != NULL)
            {
                /* file 1 is full, file 2 still has stpace, over write to file 2 */
                phb_ln_push_new_entry(entry, record0, record);
                total++;
            }
            else
            {
                /* file 1 is full, corrupt last */
                phb_shift_ln((kal_uint8) (record0->no_entry - 1), record0);
                kal_mem_cpy(&record0->array[0], entry, sizeof(phb_ln_entry_struct));
                record0->array[0].count = 1;
            }
            record0->array[0].accu_times = 1;
            record0->array[0].is_new_event = 1;
        }
        else if (total == PHB_MAX_LN_ENTRIES * 2)
        {
            ASSERT(record != NULL);
            phb_ln_push_new_entry(entry, record0, record);
            record0->array[0].accu_times = 1;
            record0->array[0].is_new_event = 1;
        }
    }

#else /* __PHB_LN_CONSECUTIVE_MERGE__ */


    if (total < PHB_MAX_LN_ENTRIES)
    {
        /* file still has space, update in file 1 */
        if (i == total)
        {
            /* not found, add new entry in file 1 */
            if (record0->no_entry > 0)
            {
                phb_shift_ln((kal_uint8) (record0->no_entry - 1), record0);
            }
            kal_mem_cpy(&record0->array[0], entry, sizeof(phb_ln_entry_struct));
            record0->array[0].accu_times = 1;
            record0->array[0].is_new_event = 1;
            record0->array[0].count = 1;
            record0->no_entry++;
            total++;
        }
        else
            /* found, renew old entry in file 1 */
        {
            phb_ln_renew_entry1(i, entry, record0);
        }
    }
    else if (total > PHB_MAX_LN_ENTRIES && total < (PHB_MAX_LN_ENTRIES * 2))
    {
        /* file 1 is full, file 2 still has stpace, over write to file 2 */
        if (i == total)
        {
            ASSERT(record != NULL);
            /* not found, add new in file 1 and over write file 2 */
            phb_ln_push_new_entry(entry, record0, record);
            record0->array[0].accu_times = 1;
            record0->array[0].is_new_event = 1;
            total++;
        }
        else if (i < PHB_MAX_LN_ENTRIES)
            /* found in file 1, renew old entry */
        {
            phb_ln_renew_entry1(i, entry, record0);
        }
        else
            /* found in file 2, renew old entry */
        {
            ASSERT(record != NULL);
            phb_ln_renew_entry2((kal_uint8) (i - PHB_MAX_LN_ENTRIES), entry, record0, record);
        }
    }
    else if (total == PHB_MAX_LN_ENTRIES)
    {
        if (i == total) /* not found, add new entry */
        {
            if (record != NULL)
            {
                /* file 1 is full, file 2 still has stpace, over write to file 2 */
                phb_ln_push_new_entry(entry, record0, record);
                total++;
            }
            else
            {
                /* file 1 is full, corrupt last */
                phb_shift_ln((kal_uint8) (record0->no_entry - 1), record0);
                kal_mem_cpy(&record0->array[0], entry, sizeof(phb_ln_entry_struct));
                record0->array[0].count = 1;
            }
            record0->array[0].accu_times = 1;
            record0->array[0].is_new_event = 1;
        }
        else
            /* found in file 1, renew old entry */
        {
            phb_ln_renew_entry1(i, entry, record0);
        }
    }
    else if (total == PHB_MAX_LN_ENTRIES * 2)
    {
        /* no empty space */
        if (i == total)
        {
            /* not found */
            ASSERT(record != NULL);
            phb_ln_push_new_entry(entry, record0, record);
            record0->array[0].accu_times = 1;
            record0->array[0].is_new_event = 1;
        }
        else if (i < PHB_MAX_LN_ENTRIES)
            /* found in file 1, renew old entry */
        {
            phb_ln_renew_entry1(i, entry, record0);
        }
        else
            /* found in file 2, renew old entry */
        {
            ASSERT(record != NULL);
            phb_ln_renew_entry2((kal_uint8) (i - PHB_MAX_LN_ENTRIES), entry, record0, record);
        }
    }

#endif /* __PHB_LN_CONSECUTIVE_MERGE__ */

#endif /* MAX_PHB_LN_ENTRY > 20 */ /* Case: <= 20 */



    control_block->total = total;
    if (total < control_block->total_piggyback)
    {
        control_block->total_piggyback = total;
    }

    if (control_block->need_free_peer)
    {
        free_peer_buff(control_block->peer_buf_ptr);
        control_block->peer_buf_ptr = NULL;
        control_block->need_free_peer = KAL_FALSE;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  phb_edit_ln
 * DESCRIPTION
 *  
 * PARAMETERS
 *  control_block       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool phb_edit_ln(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    kal_uint8 *pdu_ptr;
    kal_uint16 len;
    phb_ln_entry_struct *entry;
    l4cphb_phb_ln_entry_array_struct *pdu_data;
    nvram_ef_phb_ln_struct *record = NULL;
    kal_uint8 original_accu_times;
    kal_uint8 original_is_new_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get entry to be edit */
    pdu_ptr = get_peer_buff_pdu(control_block->peer_buf_ptr, &len);

    pdu_data = (l4cphb_phb_ln_entry_array_struct*) get_32bits_aligned_val(pdu_ptr);

    entry = (phb_ln_entry_struct*) & pdu_data->array[0];

    record = (nvram_ef_phb_ln_struct*) get_peer_buff_pdu((peer_buff_struct*) control_block->data, &len);

    i = control_block->index % PHB_MAX_LN_ENTRIES;
    original_accu_times = record->array[i].accu_times;
    original_is_new_event = record->array[i].is_new_event;
    kal_mem_cpy(&record->array[i], entry, sizeof(phb_ln_entry_struct));
    record->array[i].accu_times = original_accu_times;
    record->array[i].is_new_event = original_is_new_event;
    control_block->total = 0;
#if (MAX_PHB_LN_ENTRY > 20)
    control_block->seg_total = 0;
#endif 
    return KAL_TRUE;
}


#if (MAX_PHB_LN_ENTRY <= 20)
/*****************************************************************************
 * FUNCTION
 *  phb_ln_renew_entry1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  entry       [?]         
 *  record      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_ln_renew_entry1(kal_uint8 index, phb_ln_entry_struct *entry, nvram_ef_phb_ln_struct *record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record->array[index].count < 255)
    {
        entry->count = record->array[index].count + 1;
    }

    if (record->array[index].accu_times < 255)
    {
        entry->accu_times = record->array[index].accu_times + 1;
    }
    entry->is_new_event = 1;

    phb_shift_ln((kal_uint8) (index - 1), record);
    kal_mem_cpy(&record->array[0], entry, sizeof(phb_ln_entry_struct));
}


#ifndef __PHB_LN_CONSECUTIVE_MERGE__

/*****************************************************************************
 * FUNCTION
 *  phb_ln_renew_entry2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  entry       [?]         
 *  record      [?]         
 *  record2     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_ln_renew_entry2(
                kal_uint8 index,
                phb_ln_entry_struct *entry,
                nvram_ef_phb_ln_struct *record,
                nvram_ef_phb_ln_struct *record2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record->array[index].count < 255)
    {
        entry->count = record2->array[index].count + 1;
    }
    if (record->array[index].accu_times < 255)
    {
        entry->accu_times = record->array[index].accu_times + 1;
    }
    entry->is_new_event = 1;

    phb_shift_ln((kal_uint8) (index - 1), record2);
    kal_mem_cpy(&record2->array[0], &record->array[PHB_MAX_LN_ENTRIES - 1], sizeof(phb_ln_entry_struct));
    phb_shift_ln((kal_uint8) (record->no_entry - 1), record);
    kal_mem_cpy(&record->array[0], entry, sizeof(phb_ln_entry_struct));
}
#endif /* __PHB_LN_CONSECUTIVE_MERGE__ */


#endif /* (MAX_PHB_LN_ENTRY <= 20) */ /* MAX_PHB_LN_ENTRY <= 20 */


/*****************************************************************************
 * FUNCTION
 *  phb_ln_push_new_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  entry       [?]     
 *  record      [?]     
 *  record2     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_ln_push_new_entry(
                phb_ln_entry_struct *entry,
                nvram_ef_phb_ln_struct *record,
                nvram_ef_phb_ln_struct *record2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record2->no_entry >= 1)
    {
        phb_shift_ln((kal_uint8) (record2->no_entry - 1), record2);
    }
    kal_mem_cpy(&record2->array[0], &record->array[PHB_MAX_LN_ENTRIES - 1], sizeof(phb_ln_entry_struct));
    phb_shift_ln((kal_uint8) (record->no_entry - 1), record);
    kal_mem_cpy(&record->array[0], entry, sizeof(phb_ln_entry_struct));
    record->array[0].count = 1;
#if PHB_MAX_LNM_ENTRIES > PHB_MAX_LN_ENTRIES
    if (record2->no_entry < PHB_MAX_LNM_ENTRIES - PHB_MAX_LN_ENTRIES)
    {
        record2->no_entry++;
    }
#endif
}
#endif /* !defined(__PHB_NO_CALL_LOG__) */


#ifdef __PHB_ACCESS_SIM_LN__
/*****************************************************************************
 * FUNCTION
 *  phb_write_sim_ln_confirm
 * DESCRIPTION
 *  This is phb_write_sim_ln_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  src_id              [IN]        
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_write_sim_ln_confirm(phb_errno_enum result, kal_uint8 src_id, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cphb_write_sim_ln_cnf_struct *param_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param_ptr = (l4cphb_write_sim_ln_cnf_struct*) construct_local_para((kal_uint16) sizeof(l4cphb_write_sim_ln_cnf_struct), TD_CTRL);

    param_ptr->src_id = src_id;
    param_ptr->result = result;
    param_ptr->cause = 0;

    if (control_block != NULL)
    {
        param_ptr->type = control_block->type;
        param_ptr->cause = control_block->cause;

        if (control_block->temp_ln_entry != NULL)
        {
            free_ctrl_buffer(control_block->temp_ln_entry);
        }
        
        phb_free_control_block(control_block);
    }

    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_WRITE_SIM_LN_CNF, param_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  phb_write_sim_ln_err_handler
 * DESCRIPTION
 *  This is phb_write_err_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_write_sim_ln_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_SIM_LN_ERR);

   /**
    * Shall we try to recover/continue handling,
    * or just reject the request in processing?
    * Currently, the latter is adpoted.
    */
    phb_write_sim_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
}


/*****************************************************************************
 * FUNCTION
 *  phb_write_sim_ln_handler
 * DESCRIPTION
 *  This is phb_write_sim_ln_handler function of PHB module.
 *  Handles write last number request from L4Conly in SIM.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_write_sim_ln_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_SIM_LN);

    if (ilm_ptr != NULL)
    {
        l4cphb_write_sim_ln_req_struct *l4cphb_write_sim_ln_req;

        l4cphb_write_sim_ln_req = (l4cphb_write_sim_ln_req_struct*) ilm_ptr->local_para_ptr;

        /* Cannot allocate, means that PHB is still operating. Reject request! */
        control_block = phb_alloc_control_block();
        if (control_block == NULL)
        {
            phb_write_sim_ln_confirm(PHB_ERRNO_BUSY, l4cphb_write_sim_ln_req->src_id, control_block);
            return;
        }

        control_block->src_id = l4cphb_write_sim_ln_req->src_id;

        /* Retain msg_id */
        control_block->cnf_msg_id = ilm_ptr->msg_id;

        if (phb_ptr->state >= PHB_STATE_LN_NOT_READY)
        {
            if (control_block->proc_stage == WRITE_SIM_LN_NONE)
            {
                phb_ln_entry_struct* ln_entry = &l4cphb_write_sim_ln_req->entry;
                ln_data_desc_enum desc_type = LN_DATA_DESC_LND;

                control_block->IO_cnf_receive = phb_write_sim_ln_handler;
                control_block->type = (phb_type_enum)l4cphb_write_sim_ln_req->type;
                control_block->temp_ln_entry = (phb_ln_entry_struct*)
                        get_ctrl_buffer(sizeof(phb_ln_entry_struct));
            
                kal_mem_cpy(control_block->temp_ln_entry, (void const*)ln_entry, sizeof(phb_ln_entry_struct));
                control_block->data = (kal_uint8*) control_block->temp_ln_entry;

                phb_se_set_ln_control_block(control_block, 0);

                control_block->proc_stage = WRITE_SIM_LN_WRITE;
                control_block->err_handler = phb_write_sim_ln_err_handler;
                control_block->return_location = phb_write_sim_ln_handler;

                if (control_block->primary_ID == FILE_LND_IDX)
                {
                    desc_type = LN_DATA_DESC_LND;
                }
                else
                {
                    ASSERT(0);
                }

                control_block->length = phb_ptr->ln_data_desc[desc_type].record_size;
                if (phb_ptr->ln_data_desc[desc_type].is_support && control_block->length)
                {
                    phb_issue_IO_write_ln(control_block);
                }
                else
                {
                    phb_write_sim_ln_confirm(PHB_ERRNO_NOT_SUPPORT, control_block->src_id, control_block);
                }
                return;
            }
            /* error */
            else
            {
                phb_write_sim_ln_err_handler(NULL, control_block);
                return;
            }
        }
        /* error */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_STATE);

            phb_write_sim_ln_confirm(PHB_ERRNO_BUSY, control_block->src_id, control_block);
            return;
        }

    }
    else if (control_block->proc_stage == WRITE_SIM_LN_WRITE)
    {
        phb_write_sim_ln_confirm(PHB_ERRNO_SUCCESS, control_block->src_id, control_block);
        return;
    }
    /* error */
    else
    {
        phb_write_sim_ln_err_handler(NULL, control_block);
        return;
    }
}
#endif /* __PHB_ACCESS_SIM_LN__ */


