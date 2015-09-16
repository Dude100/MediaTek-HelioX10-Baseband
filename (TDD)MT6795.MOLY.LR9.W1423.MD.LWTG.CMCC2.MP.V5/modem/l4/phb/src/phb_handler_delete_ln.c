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
 * phb_handler_delete_ln.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is delete ln handler of PHB module.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "kal_public_defs.h"

#include "ps_public_enum.h"
#include "nvram_editor_data_item.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_public_api.h"


#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"

#include "kal_trace.h"
#include "phb_trc.h"

#include "sim_common_enums.h"
#include "nvram_enums.h"
#include "nvram_struct.h"


#include "l4c2phb_enums.h"
#include "l4c2phb_struct.h"

/* Prerequisite of phb_context.h */
#include "phb_defs.h"
#include "phb_control_block.h"
#include "phb_data_desc.h"

#include "phb_context.h"
#include "phb_se.h"

#include "phb_common.h"
#include "phb_ilm.h"

#include "phb_handler_delete_ln.h"
#include "phb_nvram_access.h"
#include "l4_msgid.h"

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
#include "phb_handler_write_ln.h"
#endif 


#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_HANDLER_DELETE_LN_C_

#if !defined(__PHB_NO_CALL_LOG__)
#if (MAX_PHB_LN_ENTRY > 20)
static kal_bool first_round;
#endif 
#endif /* !defined(__PHB_NO_CALL_LOG__) */

#ifdef __PHB_USIM_SUPPORT__
#if defined(__GEMINI__) || defined(GEMINI_PLUS) || defined(__SGLTE__)
extern kal_bool is_usim_type(sim_interface_enum which_sim);
#else /* __GEMINI__ */
extern kal_bool is_usim_type(void);
#endif /* __GEMINI__ */
#endif /* __PHB_USIM_SUPPORT__ */

#if !defined(__PHB_NO_CALL_LOG__)
static void phb_delete_ln_confirm(phb_errno_enum result, kal_uint8 src_id, control_block_type *control_block);
static kal_bool phb_delete_ln(nvram_ef_phb_ln_struct *record, control_block_type *control_block);
static void phb_ln_delete_entry(kal_uint8 index, nvram_ef_phb_ln_struct *record);

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
static void phb_delete_ln_type_seq(kal_uint16 del_seq_index, kal_uint8 type);
#endif 

extern kal_bool l4c_is_src_from_rmmi(kal_uint8 src_id);


/*****************************************************************************
 * FUNCTION
 *  phb_delete_ln_err_handler
 * DESCRIPTION
 *  Error handler
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_delete_ln_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    phb_delete_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
}


/*****************************************************************************
 * FUNCTION
 *  phb_delete_ln_handler
 * DESCRIPTION
 *  This is phb_delete_ln_handler function of PHB module.
 *  Handles delete last number request from L4C.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_delete_ln_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //in idle status
    if (ilm_ptr != NULL)
    {
        /* Cannot allocate, means that PHB is still operating. Reject request! */
        if (control_block == NULL)
        {
            l4cphb_delete_ln_req_struct *msg_ptr;

            msg_ptr = (l4cphb_delete_ln_req_struct*) ilm_ptr->local_para_ptr;
        #if (MAX_PHB_LN_ENTRY > 20)
            first_round = KAL_TRUE;
        #endif 
            control_block = phb_alloc_control_block();

            if (control_block == NULL)
            {
                phb_delete_ln_confirm(PHB_ERRNO_BUSY, msg_ptr->src_id, control_block);
                return;
            }
            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;
            control_block->src_id = msg_ptr->src_id;
        }

        /* if (phb_ptr->state == PHB_STATE_READY) */
        {
            if (control_block->proc_stage == DEL_LN_NONE)
            {
               //start delete work, do some prepare work, ex find the nvram record and the index of the log in it
               //when delete the log in it, need shift all log data after it to their previous position, so need to read all nvram and shift all log data 
               //and then write back again.
                l4cphb_delete_ln_req_struct *msg_ptr = (l4cphb_delete_ln_req_struct*) ilm_ptr->local_para_ptr;

            #if (MAX_PHB_LN_ENTRY > 20)
                kal_uint8 no_skip;
                kal_uint8 seg_total;

                if (msg_ptr->index == 0xff)
                {
                    no_skip = 0;
                }
                else
                {
                    no_skip = msg_ptr->index / PHB_MAX_LN_ENTRIES;      /* 0-based */
                }
                seg_total = ((phb_get_ln_total_entry(msg_ptr->type) + PHB_MAX_LN_ENTRIES - 1)
                             / PHB_MAX_LN_ENTRIES) - no_skip;
                control_block->index = msg_ptr->index;
            #endif /* (MAX_PHB_LN_ENTRY > 20) */ 

                /* save req info */
                //set nvram response handler(parse handler), error handler and log index...
                control_block->IO_cnf_receive = phb_delete_ln_handler;
                control_block->err_handler = phb_delete_ln_err_handler;
                
                control_block->seg_record_index = msg_ptr->index;
                control_block->src_id = msg_ptr->src_id;
                control_block->type = (phb_type_enum)msg_ptr->type;

                //seq_total: the max number of nvram record of the log type to delete
                //secondary_ID: the first nvram index of this log type
                if (control_block->type == (phb_type_enum) PHB_LND)
                {
                    control_block->seg_total = PHB_TOT_LND_LIDS;
                    control_block->secondary_ID = PHB_LND_LID_START;
                }
                else if (control_block->type == (phb_type_enum) PHB_LNM)
                {
                    control_block->seg_total = PHB_TOT_LNM_LIDS;
                    control_block->secondary_ID = PHB_LNM_LID_START;
                }
                else if (control_block->type == (phb_type_enum) PHB_LNR)
                {
                    control_block->seg_total = PHB_TOT_LNR_LIDS;
                    control_block->secondary_ID = PHB_LNR_LID_START;
                }
                else
                {
                    phb_delete_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
                }
                 //add the shift caused by gemini scenario

            #if defined(__GEMINI__) || defined(__SGLTE__)
                if (phb_current_mod == MOD_PHB_2)
                {
                    control_block->secondary_ID += PHB_TOTAL_LN_LID;
                }
            #endif /* __GEMINI__ || __SGLTE__ */

                //check if it's delete all case, if so, prepare the default invalid value and write it to all related nvram record one by one
                //from the start nvram record index of this log type
                if (msg_ptr->index == 0xff)
                {
                    /* delete all */
                    control_block->total_piggyback = 0;
                    control_block->data = get_ctrl_buffer(sizeof(nvram_ef_phb_ln_struct));
                    kal_mem_set(control_block->data, 0, sizeof(nvram_ef_phb_ln_struct));

                    if (control_block->seg_total > 1)
                    {
                        control_block->proc_stage = DEL_LN_WRITE_CONTINUE;
                    }
                    else
                    {
                        control_block->proc_stage = DEL_LN_WRITE;
                    }

                    phb_write_ln_to_nvram((nvram_ef_phb_ln_struct*) control_block->data, control_block);
                #ifdef __PHB_RECORD_LN_TYPE_SEQ__
                    phb_delete_ln_type_seq(0, (kal_uint8) control_block->type);
                #endif 

                    free_ctrl_buffer(control_block->data);
                    control_block->data = NULL;
                    return;
                }


                //if delete one log data, do work from here
                //add the shift of this log data to make sure which nvram record need to be revised
            #if (MAX_PHB_LN_ENTRY > 20)
                control_block->seg_total = seg_total;
                if (seg_total <= 2)
                {
                    control_block->secondary_ID += no_skip;
                }
                else    /* need backward read */
                {
                    control_block->secondary_ID +=
                        (PHB_TOT_LNM_LIDS - (PHB_TOT_LNM_LIDS - seg_total) - 1 - 1 + no_skip);
                }
                control_block->seg_record_index -= (PHB_MAX_LN_ENTRIES * no_skip);
            #endif /* (MAX_PHB_LN_ENTRY > 20) */ 

                control_block->proc_stage = DEL_LN_READ;
                control_block->total_piggyback = msg_ptr->total;
                //find this nvram record and read it
                phb_read_ln_from_nvram(control_block);
                return;
            }
            else if (control_block->proc_stage == DEL_LN_READ)
            {
                kal_bool updated;
                //kal_uint16 length;
                nvram_read_cnf_struct *msg_ptr = NULL;
                //nvram_ef_phb_ln_struct *pdu_data;

                msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;
                control_block->IO_stage = IO_NONE;

                 //read this nvram record doen, check if more nvram record follow it, if so, just read next nvram record together
                if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
                {
                    //pdu_data = (nvram_ef_phb_ln_struct*) get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &length);

                    /* keep first read data in control_block->data */
                    hold_peer_buff(ilm_ptr->peer_buff_ptr);
                    control_block->data = (kal_uint8*) ilm_ptr->peer_buff_ptr;

                    /* if (control_block->type != PHB_LND)
                       {
                       control_block->secondary_ID ++;
                       control_block->proc_stage = DEL_LN_READ_CONTINUE;
                       
                       phb_read_ln_from_nvram (control_block);
                       return;
                       }
                       else
                       { */

                    //if more than one nvram records are found behind this nvram record, read next one
                    if (control_block->seg_total > 1)
                    {
                        control_block->secondary_ID++;
                        control_block->seg_total--;
                        control_block->proc_stage = DEL_LN_READ_CONTINUE;

                        phb_read_ln_from_nvram(control_block);
                        return;
                    }
                    else
                    {  
                       //if it's the last nvram record, delete the log data and shift all other log data just after it to their previous position
                        control_block->proc_stage = DEL_LN_WRITE;
                        updated = phb_delete_ln(NULL, control_block);

                        if (updated == KAL_TRUE)
                        {
                            /* write LND file */
                            phb_write_ln_to_nvram(NULL, control_block);
                            return;
                        }
                    }
                    /* } */
                }
                phb_delete_ln_confirm(PHB_ERRNO_READ_FAIL, control_block->src_id, control_block);
            }
            else if (control_block->proc_stage == DEL_LN_READ_CONTINUE)
            {
                kal_bool updated;
                kal_uint16 length;
                nvram_read_cnf_struct *msg_ptr = NULL;
                nvram_ef_phb_ln_struct *pdu_data;

                msg_ptr = (nvram_read_cnf_struct*) ilm_ptr->local_para_ptr;
                control_block->IO_stage = IO_NONE;

                //read the 2nd nvram record done, parse it
                if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
                {
                    pdu_data = (nvram_ef_phb_ln_struct*) get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &length);

                    /* keep second read data in control_block->peer_buf_ptr */
                    hold_peer_buff(ilm_ptr->peer_buff_ptr);
                    control_block->peer_buf_ptr = ilm_ptr->peer_buff_ptr;

                    //delete the log data and check if this nvram record are also affected, if so updated flag is true
                    //means need to write next nvram record back 
                    updated = phb_delete_ln(pdu_data, control_block);

                    if (updated == KAL_TRUE)
                    {
                        control_block->proc_stage = DEL_LN_WRITE_CONTINUE;

                        /* write second file */
                        phb_write_ln_to_nvram(pdu_data, control_block);
                        return;
                    }
                }
                phb_delete_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
            }
            else if (control_block->proc_stage == DEL_LN_WRITE_CONTINUE)
            {
             //write the 1st nvram record done, check if need write 2nd nvram record back also
                nvram_write_cnf_struct *msg_ptr = NULL;

                msg_ptr = (nvram_write_cnf_struct*) ilm_ptr->local_para_ptr;
                control_block->IO_stage = IO_NONE;

                if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
                {
                    if (control_block->seg_record_index == 0xff)
                    {
                        /* delete all */
                        control_block->data = get_ctrl_buffer(sizeof(nvram_ef_phb_ln_struct));
                        kal_mem_set(control_block->data, 0, sizeof(nvram_ef_phb_ln_struct));

                        control_block->secondary_ID++;
                        control_block->seg_total--;
                        if (control_block->seg_total <= 1)
                        {
                            control_block->proc_stage = DEL_LN_WRITE;
                        }
                        phb_write_ln_to_nvram((nvram_ef_phb_ln_struct*) control_block->data, control_block);

                        free_ctrl_buffer(control_block->data);
                        control_block->data = NULL;
                        return;
                    }
                    control_block->proc_stage = DEL_LN_WRITE;
                    control_block->secondary_ID--;

                    /* write first file */
                    phb_write_ln_to_nvram(NULL, control_block);
                    return;
                }
                else
                {
                    /* error */
                    phb_delete_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
                }
            }
            else if (control_block->proc_stage == DEL_LN_WRITE)
            {
               //write 1st nvram record done, check if next 2 nvram record are affected, if so, do next round work
                nvram_write_cnf_struct *msg_ptr = NULL;

                msg_ptr = (nvram_write_cnf_struct*) ilm_ptr->local_para_ptr;
                control_block->IO_stage = IO_NONE;
            #if (MAX_PHB_LN_ENTRY > 20)
                if (control_block->seg_total > 1)
                {
                    control_block->seg_total--;
                    if (control_block->seg_total == 1)
                    {
                        control_block->secondary_ID -= 1;
                    }
                    else
                    {
                        control_block->secondary_ID -= 2;
                    }
                    control_block->proc_stage = DEL_LN_READ;
                    if (control_block != NULL)
                    {
                        if (control_block->data != NULL)
                        {
                            free_peer_buff((peer_buff_struct*) control_block->data);
                            control_block->data = NULL;
                        }
                        if (control_block->peer_buf_ptr != NULL)
                        {
                            free_peer_buff(control_block->peer_buf_ptr);
                            control_block->peer_buf_ptr = NULL;
                        }
                    }
                    first_round = KAL_FALSE;
                    phb_read_ln_from_nvram(control_block);
                    return;
                }
            #endif /* (MAX_PHB_LN_ENTRY > 20) */ /* MAX_PHB_LN_ENTRY > 20 */

                if (msg_ptr->result == NVRAM_IO_ERRNO_OK)
                {
                    phb_delete_ln_confirm(PHB_ERRNO_SUCCESS, control_block->src_id, control_block);
                }
                else
                {
                    phb_delete_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
                }
            }
            else
                /* wrong state */
            {
                phb_delete_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
            }
        }
        /* else
           phb_delete_ln_confirm (PHB_ERRNO_BUSY,
           control_block->src_id, control_block); */
    }
    else
    {
        phb_delete_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_delete_ln_confirm
 * DESCRIPTION
 *  This is phb_delete_ln_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  src_id              [IN]        
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_delete_ln_confirm(phb_errno_enum result, kal_uint8 src_id, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cphb_write_ln_cnf_struct *param_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param_ptr = (l4cphb_write_ln_cnf_struct*)
        construct_local_para((kal_uint16) sizeof(l4cphb_write_ln_cnf_struct), TD_CTRL);

    param_ptr->src_id = src_id;
    param_ptr->result = result;
    param_ptr->cause = 0;
    param_ptr->total = 0;

    if ((result == PHB_ERRNO_SUCCESS) && (control_block->total_piggyback > 0))
    {
        param_ptr->total = control_block->total_piggyback;
    }
    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_DELETE_LN_CNF, param_ptr, NULL);
    if (control_block != NULL)
    {
        if (control_block->data != NULL)
        {
            free_peer_buff((peer_buff_struct*) control_block->data);
        }
        if (control_block->peer_buf_ptr != NULL)
        {
            free_peer_buff(control_block->peer_buf_ptr);
        }
        phb_free_control_block(control_block);
    }

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
    if (result == PHB_ERRNO_SUCCESS)
    {
        phb_write_ln_type_seq_handler(NULL, NULL);
    }
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
}   /* end of phb_delete_ln_confirm */


#ifdef __PHB_RECORD_LN_TYPE_SEQ__
/*****************************************************************************
 * FUNCTION
 *  phb_shift_left_ln_type_seq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  del_seq_index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_shift_left_ln_type_seq(kal_uint16 del_seq_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (del_seq_index >= PHB_TOTAL_LN_ENTRIES - 1)
    {
        phb_ln_type_seq[PHB_TOTAL_LN_ENTRIES - 1] = 0xff;
    }
    else
    {
        while (del_seq_index < PHB_TOTAL_LN_ENTRIES - 1 && phb_ln_type_seq[del_seq_index + 1] != 0xff)
        {
            phb_ln_type_seq[del_seq_index] = phb_ln_type_seq[del_seq_index + 1];
            del_seq_index++;
        }
        /* last one should be 0xff */
        phb_ln_type_seq[del_seq_index] = 0xff;
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_delete_ln_type_seq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  del_seq_index       [IN]        
 *  type                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_delete_ln_type_seq(kal_uint16 del_seq_index, kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i = 0;
    kal_uint16 j = 0;
    kal_uint16 del_index = (PHB_TOTAL_LN_ENTRIES - 1);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //kal_uint8 update_type = phb_ln_type_seq[0];
    //kal_uint8 tmp_type;
    if (del_seq_index > 0)
    {
        for (del_index = PHB_TOTAL_LN_ENTRIES - 1; del_seq_index > 0; del_index--)
        {
            if (phb_ln_type_seq[del_index] == type)
            {
                del_seq_index--;
            }
        }
        del_index++;
        phb_shift_left_ln_type_seq(del_index);
    }
    else
    {
        while (i < del_index && phb_ln_type_seq[i] != 0xff)
        {
            if (phb_ln_type_seq[i] == type)
            {
                phb_ln_type_seq[i] = 0xff;
                j = i;
                phb_shift_left_ln_type_seq(i);
                while (phb_ln_type_seq[j] == type)
                {
                    phb_shift_left_ln_type_seq(j);
                }
            }
            i++;
        }
    }
}
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_delete_ln
 * DESCRIPTION
 *  
 * PARAMETERS
 *  record              [?]     
 *  control_block       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool phb_delete_ln(nvram_ef_phb_ln_struct *record, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 total, i;
    kal_uint16 len;
    nvram_ef_phb_ln_struct *record0 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //the work of this API is
    //example: MAX_PHB_LN_ENTRY = 50, the dialed log nvram records are 1~5, now to delete 15th dialed log adn total dialed log is 50 now
    //1. find the nvram record to read: 15/10+1=2, read the nvram record 2 and next record 3 to memory
    //2. delete log 15th in record2, and shift left all log data just after it, ex shift 16th log data to the 5 slot of record1, it's the new 15th log data now
    //3. shift the 1st log data or record2 to the last log data of record1
    //4. shift left all log data in record2
    //5. read next nvram record and start 3~5 step untill no nvram record to read

    
    record0 = (nvram_ef_phb_ln_struct*) get_peer_buff_pdu((peer_buff_struct*) control_block->data, &len);

    if (record != NULL)
    {
        total = record0->no_entry + record->no_entry;
    }
    else
    {
        total = record0->no_entry;
    }

    if (total - 1 < control_block->seg_record_index)
    {
        return KAL_FALSE;
    }

#if (MAX_PHB_LN_ENTRY > 20)
#ifdef __PHB_RECORD_LN_TYPE_SEQ__
    if (first_round)
    {
        phb_delete_ln_type_seq(
            (kal_uint16) (phb_get_ln_total_entry((kal_uint8) control_block->type) - control_block->index),
            (kal_uint8) control_block->type);
    }
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
    if (!first_round)   /* need use shiftedEntry */
    {
        phb_ln_entry_struct buffer_entry;

        kal_mem_cpy(&buffer_entry, &shifted_entry, sizeof(phb_ln_entry_struct));
        if (record == NULL)
        {
            /* del entry in file 1 */
            i = control_block->seg_record_index;
            phb_ln_delete_entry(i, record0);
            control_block->seg_total = 0;
            kal_mem_cpy(&record0->array[PHB_MAX_LN_ENTRIES - 1], &shifted_entry, sizeof(phb_ln_entry_struct));
            record0->no_entry++;
        }
        else if (record->no_entry > 0)
        {
            /* del entry in file 1 and push one entry from file 2 to file 1 */
            i = control_block->seg_record_index;
            if (control_block->seg_total > 1)   /* at least 2 (one is itself) */
            {
                kal_mem_cpy(&shifted_entry, &record0->array[0], sizeof(phb_ln_entry_struct));
                phb_ln_delete_entry(0, record0);
            }
            else
            {
                phb_ln_delete_entry(i, record0);
            }
            kal_mem_cpy(&record0->array[PHB_MAX_LN_ENTRIES - 1], &record->array[0], sizeof(phb_ln_entry_struct));
            record0->no_entry++;
            phb_ln_delete_entry(0, record);
            kal_mem_cpy(&record->array[PHB_MAX_LN_ENTRIES - 1], &buffer_entry, sizeof(phb_ln_entry_struct));
            record->no_entry++;
        }
        else
        {
            /* del entry in file 1 */
            i = control_block->seg_record_index;
            phb_ln_delete_entry(i, record0);
            control_block->seg_total = 0;
            kal_mem_cpy(&record0->array[PHB_MAX_LN_ENTRIES - 1], &shifted_entry, sizeof(phb_ln_entry_struct));
            record0->no_entry++;
        }

    }
    else if (control_block->seg_record_index >= PHB_MAX_LN_ENTRIES)
#else /* (MAX_PHB_LN_ENTRY > 20) */ 

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
    phb_delete_ln_type_seq((kal_uint16) (total - control_block->seg_record_index), control_block->type);
#endif 

    if (control_block->seg_record_index >= PHB_MAX_LN_ENTRIES && record != NULL)
#endif /* MAX_PHB_LN_ENTRY > 20 */
    {
        /* del entry in file2 */
        i = control_block->seg_record_index - PHB_MAX_LN_ENTRIES;
        phb_ln_delete_entry(i, record);
    }
    else if (record == NULL)
    {
        /* del entry in file 1 */
        i = control_block->seg_record_index;
        phb_ln_delete_entry(i, record0);
    }
    else if (record->no_entry > 0)
    {
        /* del entry in file 1 and push one entry from file 2 to file 1 */
        i = control_block->seg_record_index;
    #if (MAX_PHB_LN_ENTRY > 20)
        if (control_block->seg_total > 1)   /* at least 2 (one is itself) */
        {
            kal_mem_cpy(&shifted_entry, &record0->array[0], sizeof(phb_ln_entry_struct));
            phb_ln_delete_entry(0, record0);
        }
        else
    #endif /* (MAX_PHB_LN_ENTRY > 20) */ 
            phb_ln_delete_entry(i, record0);
        kal_mem_cpy(&record0->array[PHB_MAX_LN_ENTRIES - 1], &record->array[0], sizeof(phb_ln_entry_struct));
        record0->no_entry++;
        phb_ln_delete_entry(0, record);
    }
    else
    {
        /* del entry in file 1 */
        i = control_block->seg_record_index;
        phb_ln_delete_entry(i, record0);
    }

    if ((total - control_block->seg_record_index - 1) < control_block->total_piggyback)
    {
        control_block->total_piggyback = total - control_block->seg_record_index - 1;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  phb_ln_delete_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  record      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_ln_delete_entry(kal_uint8 index, nvram_ef_phb_ln_struct *record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = index + 1; i < record->no_entry; i++)
    {
        kal_mem_cpy(&record->array[i - 1], &record->array[i], sizeof(phb_ln_entry_struct));
    }
    record->no_entry--;
    return;
}
#endif /* !defined(__PHB_NO_CALL_LOG__) */


#ifdef __PHB_ACCESS_SIM_LN__
/*****************************************************************************
 * FUNCTION
 *  phb_delete_sim_ln_confirm
 * DESCRIPTION
 *  This is phb_delete_sim_ln_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  src_id              [IN]        
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_delete_sim_ln_confirm(phb_errno_enum result, kal_uint8 src_id, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cphb_delete_sim_ln_cnf_struct *param_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param_ptr = (l4cphb_delete_sim_ln_cnf_struct*)
        construct_local_para((kal_uint16) sizeof(l4cphb_delete_sim_ln_cnf_struct), TD_CTRL);

    param_ptr->src_id = src_id;
    param_ptr->result = result;
    param_ptr->cause = 0;

    if (control_block != NULL)
    {
        param_ptr->cause = control_block->cause;
        phb_free_control_block(control_block);
    }

    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_DELETE_SIM_LN_CNF, param_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  phb_delete_sim_ln_err_handler
 * DESCRIPTION
 *  This is phb_delete_err_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_delete_sim_ln_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DELETE_SIM_LN_ERR);

   /**
    * Shall we try to recover/continue handling,
    * or just reject the request in processing?
    * Currently, the latter is adpoted.
    */
    phb_delete_sim_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
}


/*****************************************************************************
 * FUNCTION
 *  phb_delete_sim_ln_handler
 * DESCRIPTION
 *  This is phb_delete_sim_ln_handler function of PHB module.
 *  Handles delete last number request from L4C only in SIM.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_delete_sim_ln_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DELETE_SIM_LN);

    if (ilm_ptr != NULL)
    {
        /* Cannot allocate, means that PHB is still operating. Reject request! */
        if (control_block == NULL)
        {
            l4cphb_delete_sim_ln_req_struct *msg_ptr;

            msg_ptr = (l4cphb_delete_sim_ln_req_struct*) ilm_ptr->local_para_ptr;

            control_block = phb_alloc_control_block();

            if (control_block == NULL)
            {
                phb_delete_sim_ln_confirm(PHB_ERRNO_BUSY, msg_ptr->src_id, control_block);
                return;
            }
            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;
            control_block->src_id = msg_ptr->src_id;
        }

        if (phb_ptr->state >= PHB_STATE_LN_NOT_READY)
        {
            if (control_block->proc_stage == DEL_SIM_LN_NONE)
            {
                l4cphb_delete_sim_ln_req_struct *msg_ptr = (l4cphb_delete_sim_ln_req_struct*) ilm_ptr->local_para_ptr; 
                ln_data_desc_enum desc_type = LN_DATA_DESC_LND;

                /* save req info */
                control_block->IO_cnf_receive = phb_delete_sim_ln_handler;
                control_block->src_id = msg_ptr->src_id;
                control_block->type = (phb_type_enum)msg_ptr->type;

                phb_se_set_ln_control_block(control_block, 0);
                control_block->proc_stage = DEL_SIM_LN_WRITE;
                control_block->err_handler = phb_delete_sim_ln_err_handler;
                control_block->return_location = phb_delete_sim_ln_handler;
                
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
                    phb_issue_IO_delete_ln(control_block);
                }
                else
                {
                    phb_delete_sim_ln_confirm(PHB_ERRNO_NOT_SUPPORT, control_block->src_id, control_block);
                }
                return;
            }
            else if (control_block->proc_stage == DEL_SIM_LN_WRITE)
            {
                phb_delete_sim_ln_confirm(PHB_ERRNO_SUCCESS, control_block->src_id, control_block);
            }
            /* wrong state */
            else
            {
                phb_delete_sim_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
            }
        }
        else
        {
           phb_delete_sim_ln_confirm (PHB_ERRNO_BUSY, control_block->src_id, control_block);
        }
    }
    else
    {
        phb_delete_sim_ln_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
    }
}
#endif /* __PHB_ACCESS_SIM_LN__ */


