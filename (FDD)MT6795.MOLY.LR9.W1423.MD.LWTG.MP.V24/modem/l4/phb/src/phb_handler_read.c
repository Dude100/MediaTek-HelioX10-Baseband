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
 * phb_handler_read.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is startup handler of PHB module.
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
 * removed!
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include "kal_release.h"        /* Basic data type */
#include "l4_msgid.h"

//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
//#include "stack_ltlcom.h" /* Task message communiction */
//#include "app_buff_alloc.h"

#include "kal_trace.h"
#include "phb_trc.h"

#include "sim_common_enums.h"
// #include "nvram_editor_data_item.h"
//#include "custom_nvram_editor_data_item.h"
//#include "nvram_struct.h"
//#include "nvram_enums.h"

//#include "l4_common.h"
#include "ps2sim_struct.h"

#include "l4c2phb_enums.h"
#include "l4c2phb_struct.h"

/* Prerequisite of phb_context.h */
#include "phb_defs.h"
#include "phb_control_block.h"
//#include "phb_config.h"
#include "phb_data_desc.h"
//#include "phb_data_entry_table.h"
//#include "phb_pindex.h"
//#include "phb_name_num_index.h"

#include "phb_context.h"
#include "phb_se.h"

#include "phb_common.h"
#include "phb_utils.h"
#include "phb_ilm.h"
/* SIM access */
//#include "phb_sim_access.h"
/* NVRAM access */
//#include "phb_nvram_access.h"

#include "phb_handler_read.h"

#include "phb_sap.h"
#include "phb_se.h"

#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "string.h"
#include "ps_public_struct.h"
#include "mcd_l4_common.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_HANDLER_READ_C_

extern kal_bool l4c_is_src_from_rmmi(kal_uint8 src_id);
static void phb_read_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block, int line);
static void phb_read_confirm(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                msg_type cnf_msg_id,
                control_block_type *control_block);
static void phb_read_confirm_no_cb(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                msg_type cnf_msg_id,
                kal_uint16 record_index,
                kal_uint8 occurrence,
                phb_type_enum type);

static kal_bool phb_is_read_param_valid(l4cphb_read_req_struct *l4cphb_read_req);


/*****************************************************************************
 * FUNCTION
 *  phb_read_handler
 * DESCRIPTION
 *  This is phb_read_handler function of PHB module.
 *  Read SOP:
 *  phb_control_block_set_param(),
 *  phb_control_block_set(),
 *  phb_control_block_set_IO(),
 *  se_control_block()
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_read_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_READ);

    if (ilm_ptr != NULL)
    {
        l4cphb_read_req_struct *l4cphb_read_req;

        l4cphb_read_req = (l4cphb_read_req_struct*) ilm_ptr->local_para_ptr;

        /* Cannot allocate, means that PHB is still operating. Reject request! */
        control_block = phb_alloc_control_block();
        if (control_block == NULL)
        {
            phb_read_confirm_no_cb(
                PHB_ERRNO_BUSY,
                0,
                l4cphb_read_req->src_id,
                ilm_ptr->msg_id,
                l4cphb_read_req->record_index,
                0,
                l4cphb_read_req->type);
            return;
        }

        control_block->src_id = l4cphb_read_req->src_id;
        /* Retain msg_id */
        control_block->cnf_msg_id = ilm_ptr->msg_id;

        if (phb_ptr->state == PHB_STATE_READY)
        {
            if (control_block->proc_stage == READ_NONE)
            {
                l4cphb_phb_entry_array_struct *phb_entry_array;
                phb_entry_struct *phb_entry;
                peer_buff_struct *peer_buf_ptr;

                /* Invalid parameters */
                if (phb_is_read_param_valid(l4cphb_read_req) == KAL_FALSE)
                {
                    control_block->actual_count = 0;
                    control_block->cause = PHB_ERRNO_READ_EMPTY;
                    phb_read_confirm(
                        PHB_ERRNO_READ_EMPTY,
                        control_block->actual_count,
                        control_block->src_id,
                        control_block->cnf_msg_id,
                        control_block);
                    return;
                }

                /* If request total is 0, or nothing can be read, return READ_SUCCESS with total = 0 */
                if (l4cphb_read_req->total == 0)
                {
                    control_block->actual_count = 0;
                    control_block->cause = PHB_ERRNO_READ_EMPTY;
                    phb_read_confirm(
                        PHB_ERRNO_READ_EMPTY,
                        control_block->actual_count,
                        control_block->src_id,
                        control_block->cnf_msg_id,
                        control_block);
                    return;
                }

            /**
             * Read SOP:
             * phb_control_block_set_param(),
             * phb_control_block_set(),
             * phb_control_block_set_IO(),
             * se_control_block()
             */
                control_block->total = l4cphb_read_req->total;
                phb_entry_array =
                    (l4cphb_phb_entry_array_struct*) l4cphb_alloc_peer_buf(&peer_buf_ptr, control_block->total);
                control_block->need_free_peer = KAL_TRUE;
                phb_control_block_set_param(control_block, READ_CONTINUE, NULL, peer_buf_ptr);

                phb_entry = &phb_entry_array->array[0];
                if (l4cphb_read_req->type == PHB_ECC)
                {
                    kal_uint8 i;
                    kal_uint8 index;
                    phb_entry_struct *phb_entry_ith = phb_entry;

                    if (l4c_is_src_from_rmmi(control_block->src_id))  // for CPBR (EN)
                    {
                    	  index = (kal_uint8) l4cphb_read_req->record_index - 1;
                    }
                    else
                    {
                        index = (kal_uint8) l4cphb_read_req->index - 1;
                    }
                    control_block->type = PHB_ECC;
                    control_block->total = 0;

                    /* phb_ptr->ecc.num_ecc now contains number of records */
                    for (i = index; (i < phb_ptr->ecc.num_ecc) && (control_block->total < l4cphb_read_req->total); ++i)
                    {
                        kal_uint16 len;
                        memset(phb_entry_ith, 0x00, sizeof(phb_entry_struct));

                        phb_entry_ith->storage = phb_which_sim_storage();

                        len = bcd_len(&phb_ptr->ecc.ecc_entry[i].ecc[0], NUM_OF_BYTE_ECC);
                        len = (len + 1) >> 1;

                        phb_entry_ith->tel_number.addr_length = len + L4_ADDR_BCD_TON_NPI_SIZE;
                        phb_entry_ith->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] = TON_NPI_DEFAULT;
                        kal_mem_cpy(
                            &phb_entry_ith->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                            (void const*)&phb_ptr->ecc.ecc_entry[i].ecc[0],
                            len);

                        ++control_block->total;
                        phb_entry_ith->tel_number.addr_bcd[phb_entry_ith->tel_number.addr_length] = 0xff;
                        phb_entry_ith->record_index = i + 1;
                       
                        ++phb_entry_ith;
                    }
                    phb_entry_array->no_array = (kal_uint8) (control_block->actual_count = control_block->total);

                    phb_read_confirm(
                        PHB_ERRNO_READ_SUCCESS,
                        control_block->actual_count,
                        control_block->src_id,
                        control_block->cnf_msg_id,
                        control_block);
                    return;
                }
                else
                {
                    phb_control_block_set(
                        control_block,
                        phb_read_continue,
                        phb_read_handler,
                        (err_handler_func_type)phb_read_err_handler,
                        READ_NONE);
                    /* This function sets actual_count */
                    phb_control_block_set_IO(
                        control_block,
                        l4cphb_read_req->type,
                        l4cphb_read_req->index,
                        l4cphb_read_req->total);

                    /* Set proc_stage, storage, record_index, primary_ID, and secondary_ID */
                    if (phb_se_set_control_block(
                            control_block,
                            OP_READ,
                            l4cphb_read_req->storage,
                            l4cphb_read_req->record_index) == KAL_FALSE)
                    {
                        control_block->result = PHB_ERRNO_READ_FAIL;
                        phb_read_err_handler(NULL, control_block, 0);
                        return;
                    }
                    control_block->data = (kal_uint8*) phb_entry;
                    control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));
                
                #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
                    if (l4cphb_read_req->type == PHB_ANR)
                    {
                        control_block->occurrence = (kal_uint8)l4cphb_read_req->num_index;
                    }
                #endif
                    phb_read_continue(NULL, control_block);
                }
            }
            /* error */
            else
            {
                control_block->result = PHB_ERRNO_READ_FAIL;
                phb_read_err_handler(NULL, control_block, 0);
                return;
            }
        }
        /* error */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_STATE);

            control_block->actual_count = 0;
            phb_read_confirm(
                PHB_ERRNO_NOT_READY,
                control_block->actual_count,
                control_block->src_id,
                control_block->cnf_msg_id,
                control_block);
            return;
        }

    }
    else
    {
        if (control_block->proc_stage == READ_CONTINUE ||
            control_block->proc_stage == READ_CONTINUE_SPECIFIC)
        {
            if (control_block->result == PHB_ERRNO_READ_EMPTY && (control_block->type == PHB_MSISDN || control_block->type == PHB_SDN))
            {
                control_block->result = PHB_ERRNO_READ_SUCCESS;
            }
            phb_read_confirm(
                control_block->result,
                control_block->actual_count,
                control_block->src_id,
                control_block->cnf_msg_id,
                control_block);
        }
        /* error */
        else
        {
            control_block->result = PHB_ERRNO_READ_FAIL;
            phb_read_err_handler(NULL, control_block, 0);
            return;
        }
    }
}   /* end of phb_read_handler */


/*****************************************************************************
 * FUNCTION
 *  phb_read_err_handler
 * DESCRIPTION
 *  This is phb_read_err_handler function of PHB module.
 *  
 *  Requirement:
 *  Error handlers should destruct control_block.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_read_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block, int line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_ERROR, FUNC_PHB_READ_ERR, line);

   /**
    * Shall we try to recover/continue handling,
    * or just reject the request in processing?
    * Currently, the latter is adpoted.
    */
   if (control_block->cnf_msg_id == MSG_ID_L4CPHB_READ_REQ)
   {
        kal_uint16 packed_peer_buff_len;
        kal_uint8 *pdu_ptr;
        l4cphb_phb_entry_array_struct *pdu_data = NULL;

        pdu_ptr = get_peer_buff_pdu(control_block->peer_buf_ptr, &packed_peer_buff_len);

        pdu_data = (l4cphb_phb_entry_array_struct*) get_32bits_aligned_val(pdu_ptr);
        pdu_data->no_array = control_block->actual_count;
        control_block->actual_count = 0;
    }
    phb_read_confirm(
        control_block->result,
        control_block->actual_count,
        control_block->src_id,
        control_block->cnf_msg_id,
        control_block);
}   /* end of phb_read_err_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_read_continue
 * DESCRIPTION
 *  This is phb_read_continue function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_read_continue(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PHB_TRACE((MOD_PHB, "phb_read_continue: actual_count = %d, total = %d, index = %d, record_index = %d", control_block->actual_count, control_block->total, control_block->index, control_block->record_index),
              (TRACE_GROUP_1, PHB_TRC_READ_CONT, control_block->actual_count, control_block->total, control_block->index, control_block->record_index)); 

    if (ilm_ptr == NULL)
    {
        if ((control_block->cnf_msg_id != MSG_ID_L4CPHB_READ_REQ) &&
            (control_block->actual_count >= control_block->total))
        {
            phb_read_confirm(
                PHB_ERRNO_SUCCESS,
                control_block->actual_count,
                control_block->src_id,
                control_block->cnf_msg_id,
                control_block);
        }

        else
        {
            phb_issue_IO_read(control_block);
        }
    }
    else
    {
        phb_entry_struct *phb_entry = (phb_entry_struct*) control_block->data;

        if (phb_entry != NULL)
        {
            phb_entry->type = control_block->type;
        }

        if (control_block->actual_count < control_block->total && 
            control_block->index != (kal_uint16) PHB_INVALID_VALUE)
        {
            control_block->record_index = (kal_uint16) PHB_INVALID_VALUE;
        }
      /**
       * User specifies physical location to read;
       * therefore, the read phb_entry could be NULL.
       */
        if (control_block->record_index != (kal_uint16) PHB_INVALID_VALUE)
        {
         /**
          * Here, control_block->data could be NULL, if read back data is empty.
          */
         /**
          * Since alpha_id's stored in index are truncated,
          * phb_entry->alpha_id must be truncated, too, if necessary;
          * so that comparison could work properly.
          */
            if (phb_entry != NULL)
            {
                phb_entry->index = phb_se_get_index_by_record_index(
                                    control_block->type,
                                    control_block->storage,
                                    control_block->record_index);
                /* phb_se_search_by_record_index_name(control_block->type,
                   control_block->storage,
                   control_block->record_index,
                   (alpha_id_type*)&phb_entry->alpha_id); */
                /* phb_entry->index++; */

                /* Read complete, now return control back to controller */
                control_block->actual_count = 1;
            }

            (*control_block->controller) (NULL, control_block);
        }

      /**
       * User doesn't specify physical location to read,
       * therefore, the read phb_entry is always valid!!
       */
        else
        {

         /**
          * Unless someone modifies the underlying storage
          * while PHB is reading, the phb_entry just read is always valid!
          * However, prevent this WEIRD case for safety.
          */
        #ifdef __PHB_SORT_ENABLE__
            kal_uint16 pos;
            data_entry_struct *data_entry;
        #endif

            if (phb_entry == NULL)
            {
                control_block->result = PHB_ERRNO_READ_FAIL;
                phb_read_err_handler(NULL, control_block, 0);
                return;
            }

            /* Set index field of next entry to read */
            phb_entry->index = (control_block->index)++;

        #ifdef __PHB_SORT_ENABLE__
            if (control_block->type == PHB_PHONEBOOK)
            {
            pos = phb_pindex_get_pos(&phb_ptr->indices.phb_index.name_index, control_block->index);
            data_entry = phb_det_get(&phb_ptr->indices.phb_index.data_entry_table, pos);
            if (data_entry != NULL)
            control_block->storage = data_entry->storage;
            }
        #endif

            /* Read complete, now return control back to controller */
            if (++control_block->actual_count >= control_block->total)
            {
                (*control_block->controller) (NULL, control_block);
            }
            /* Still others to read */
            else
            {
                /* set storage, record_index, primary_ID, and secondary_ID */
                phb_entry_struct* phb_entry;
                if (phb_se_set_control_block(
                        control_block,
                        OP_READ,
                        control_block->storage,
                        control_block->record_index) == KAL_FALSE)
                {
                    control_block->result = PHB_ERRNO_READ_FAIL;
                    phb_read_err_handler(NULL, control_block, 0);
                    return;
                }

                /* shift next read address */
                phb_entry = ((phb_entry_struct*) control_block->data) + 1;
                /* 20040918, Retreive lenght again in case file id change */
                control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));
                control_block->data = (kal_uint8*)phb_entry;
                phb_issue_IO_read(control_block);
            }
        }
    }
}   /* end of phb_read_continue */


/*****************************************************************************
 * FUNCTION
 *  phb_read_confirm
 * DESCRIPTION
 *  This is phb_read_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  actual_count        [IN]        
 *  src_id              [IN]        
 *  cnf_msg_id          [IN]        
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_read_confirm(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                msg_type cnf_msg_id,
                control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msg_type msg_id = MSG_ID_L4CPHB_READ_CNF;   /* avoid compilation warning */
    local_para_struct *local_param_ptr = NULL;
    peer_buff_struct *peer_buf_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, FUNC_PHB_READ_CNF, result, actual_count, src_id, cnf_msg_id);

    switch (control_block->cnf_msg_id)
    {
        case MSG_ID_L4CPHB_READ_REQ:
        {
            l4cphb_read_cnf_struct *l4cphb_read_cnf;

            l4cphb_read_cnf = (l4cphb_read_cnf_struct*) construct_local_para(sizeof(l4cphb_read_cnf_struct), TD_CTRL);
            l4cphb_read_cnf->total = actual_count;
            l4cphb_read_cnf->src_id = src_id;

            l4cphb_read_cnf->result = result;
            /* Field `cause' is meaningful when I/O occured by using control blocks */
            l4cphb_read_cnf->cause = control_block->cause;

            msg_id = MSG_ID_L4CPHB_READ_CNF;
            local_param_ptr = (local_para_struct*) l4cphb_read_cnf;
            break;
        }
        
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        case MSG_ID_L4CPHB_READ_USIM_REQ:
        {
            l4cphb_read_usim_cnf_struct *l4cphb_read_cnf;

            l4cphb_read_cnf = (l4cphb_read_usim_cnf_struct*) construct_local_para(sizeof(l4cphb_read_usim_cnf_struct), TD_CTRL);
            l4cphb_read_cnf->src_id = src_id;

            /* If result is PHB_ERRNO_BUSY, reject newly received request */
            l4cphb_read_cnf->result = result;
            l4cphb_read_cnf->record_index = control_block->record_index;
            l4cphb_read_cnf->occurrence = control_block->occurrence;
            l4cphb_read_cnf->type = control_block->type;
            msg_id = MSG_ID_L4CPHB_READ_USIM_CNF;
            local_param_ptr = (local_para_struct*) l4cphb_read_cnf;
            break;
        }
    #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
    
        case MSG_ID_L4CPHB_WRITE_REQ:
        {
            l4cphb_write_cnf_struct *l4cphb_write_cnf;

            kal_trace(TRACE_INFO, FUNC_PHB_WRITE_CNF, result, control_block->actual_count, control_block->src_id);

            l4cphb_write_cnf = (l4cphb_write_cnf_struct*) construct_local_para(sizeof(l4cphb_write_cnf_struct), TD_CTRL);
            l4cphb_write_cnf->result = result;

            /* Field `cause' is meaningful when I/O occured by using control blocks */
            l4cphb_write_cnf->cause = control_block->cause;

            l4cphb_write_cnf->total = control_block->actual_count;
            l4cphb_write_cnf->src_id = control_block->src_id;
            l4cphb_write_cnf->old_index = control_block->candidate;

            msg_id = MSG_ID_L4CPHB_WRITE_CNF;
            local_param_ptr = (local_para_struct*) l4cphb_write_cnf;
            break;
        }
        
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        case MSG_ID_L4CPHB_WRITE_USIM_REQ:
        {
            l4cphb_write_usim_cnf_struct *l4cphb_write_cnf;

            kal_trace(TRACE_INFO, FUNC_PHB_WRITE_CNF, result, control_block->actual_count, control_block->src_id);

            l4cphb_write_cnf = (l4cphb_write_usim_cnf_struct*) construct_local_para(
                                                                sizeof(l4cphb_write_usim_cnf_struct),
                                                                TD_CTRL);
            l4cphb_write_cnf->result = result;

            /* Field `cause' is meaningful when I/O occured by using control blocks */
            l4cphb_write_cnf->cause = control_block->cause;

            l4cphb_write_cnf->src_id = control_block->src_id;
            l4cphb_write_cnf->record_index = control_block->record_index;
            l4cphb_write_cnf->occurrence = control_block->occurrence;
            l4cphb_write_cnf->type = control_block->type;

            msg_id = MSG_ID_L4CPHB_WRITE_USIM_CNF;
            local_param_ptr = (local_para_struct*) l4cphb_write_cnf;
            break;
        }
    #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
    
        case MSG_ID_L4CPHB_DELETE_REQ:
        {
            l4cphb_delete_cnf_struct *l4cphb_delete_cnf;

            kal_trace(TRACE_FUNC, FUNC_PHB_DELETE_CNF, result, control_block->actual_count, control_block->src_id);

            l4cphb_delete_cnf = (l4cphb_delete_cnf_struct*) construct_local_para(
                                                                sizeof(l4cphb_delete_cnf_struct),
                                                                TD_CTRL);
            l4cphb_delete_cnf->result = result;

            /* Field `cause' is meaningful when I/O occured by using control blocks */
            l4cphb_delete_cnf->cause = control_block->cause;

            l4cphb_delete_cnf->total = control_block->actual_count;
            l4cphb_delete_cnf->src_id = control_block->src_id;
        #ifdef __PHB_WISDOM_SUPPORT__
            l4cphb_delete_cnf->type = control_block->type;
        #endif /* __PHB_WISDOM_SUPPORT__ */
            l4cphb_delete_cnf->old_index = control_block->candidate;

            msg_id = MSG_ID_L4CPHB_DELETE_CNF;
            local_param_ptr = (local_para_struct*) l4cphb_delete_cnf;
            break;
        }

    #ifdef __PHB_SORT_ENABLE__
        case MSG_ID_L4CPHB_SEARCH_REQ:
        {
            l4cphb_search_cnf_struct *l4cphb_search_cnf;

            kal_trace(
                TRACE_FUNC,
                FUNC_PHB_SEARCH_CNF,
                result,
                control_block->actual_count,
                control_block->src_id,
                control_block->cnf_msg_id);

            l4cphb_search_cnf = (l4cphb_search_cnf_struct*) construct_local_para(
                                                                sizeof(l4cphb_search_cnf_struct),
                                                                TD_CTRL);
            l4cphb_search_cnf->result = result;

            /* Field `cause' is meaningful when I/O occured by using control blocks */
            l4cphb_search_cnf->cause = control_block->cause;

            l4cphb_search_cnf->total = control_block->actual_count;
            l4cphb_search_cnf->src_id = control_block->src_id;

            msg_id = MSG_ID_L4CPHB_SEARCH_CNF;
            local_param_ptr = (local_para_struct*) l4cphb_search_cnf;
            break;
        }
    #endif /* __PHB_SORT_ENABLE__ */

        default:
            ASSERT(0);
    }
    /* Pack from control_block->peer_buf_ptr */
    if (control_block->peer_buf_ptr != NULL)
    {
        peer_buf_ptr = (peer_buff_struct*) control_block->peer_buf_ptr;
        control_block->peer_buf_ptr = NULL;
    }
    control_block->need_free_peer = KAL_FALSE;

    phb_free_control_block(control_block);

    phb_send_ilm(MOD_L4C, (kal_uint16) msg_id, local_param_ptr, peer_buf_ptr);
}   /* end of phb_read_confirm */


/*****************************************************************************
 * FUNCTION
 *  phb_read_confirm
 * DESCRIPTION
 *  This is phb_read_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  actual_count        [IN]        
 *  src_id              [IN]        
 *  cnf_msg_id          [IN]        
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_read_confirm_no_cb(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                msg_type cnf_msg_id,
                kal_uint16 record_index,
                kal_uint8 occurrence,
                phb_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, FUNC_PHB_READ_CNF, result, actual_count, src_id, cnf_msg_id);
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    if (cnf_msg_id == MSG_ID_L4CPHB_READ_USIM_REQ)
    {
        l4cphb_read_usim_cnf_struct *l4cphb_read_cnf;

        l4cphb_read_cnf = (l4cphb_read_usim_cnf_struct*) construct_local_para(sizeof(l4cphb_read_usim_cnf_struct), TD_CTRL);
        l4cphb_read_cnf->src_id = src_id;

        /* If result is PHB_ERRNO_BUSY, reject newly received request */
        l4cphb_read_cnf->result = result;
        l4cphb_read_cnf->record_index = record_index;
        l4cphb_read_cnf->occurrence = occurrence;
        l4cphb_read_cnf->type = type;

        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_READ_USIM_CNF, (local_para_struct*) l4cphb_read_cnf, NULL);
    }
    else
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
    {
        l4cphb_read_cnf_struct *l4cphb_read_cnf;

        l4cphb_read_cnf = (l4cphb_read_cnf_struct*) construct_local_para(sizeof(l4cphb_read_cnf_struct), TD_CTRL);
        l4cphb_read_cnf->total = actual_count;
        l4cphb_read_cnf->src_id = src_id;

        l4cphb_read_cnf->result = result;

        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_READ_CNF, (local_para_struct*) l4cphb_read_cnf, NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  phb_read_fake
 * DESCRIPTION
 *  This is phb_read_fake function of PHB module.
 *  Fakes reading state to meet piggyback requirement of write, delete operation.
 *  This function just fakes valid read operation by setting control_block
 *  correctly.
 *  
 *  It DOES NOT send any IO primitives. It is left for caller to judege which
 *  function to call for issueing prmitives.
 *  Also keep original prmitive ID.
 *  
 *  Once this function is called, caller should completely leave program
 *  control to phb_handler_read.c; that is, read handler will take over
 *  control, hance as long as caller encounters any error, just return,
 *  since read handler will handle them in advance.
 *  
 *  Prerequisite:
 *  // 1. control_block->length is not set. Caller should ensure to set length correctly.
 *  1. length will be set by this function. Caller should not set it.
 *  2. phb_control_block_set_IO() must be called in advance.
 *  3. Caller must set control_block->total.
 *  4. The given index MUST start from 1
 *  5. phb_se_is_in_range() should be called in advance.
 *  6. control_block->cnf_msg_id must be set!!
 * PARAMETERS
 *  control_block       [?]         
 *  cached_entry        [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool phb_read_fake(control_block_type *control_block, phb_entry_struct *cached_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* Now we have to transform the state to a *FAKE* read state. */
    l4cphb_phb_entry_array_struct *phb_entry_array;
    peer_buff_struct *peer_buf_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_READ_FAKE);

   /**
    * For write operation, the just written entry is still there!
    * It's in control_block->temp_entry and passed in as a cached_entry.
    */

    /* phb_se_is_in_range ?? */

    /* First, construct the array for piggyback reading */
    phb_entry_array = (l4cphb_phb_entry_array_struct*) l4cphb_alloc_peer_buf(&peer_buf_ptr, control_block->total);
    control_block->need_free_peer = KAL_TRUE;
    phb_control_block_set_param(control_block, READ_CONTINUE, NULL, peer_buf_ptr);

    phb_control_block_set(control_block, phb_read_continue, phb_read_handler, (err_handler_func_type)phb_read_err_handler, READ_CONTINUE);
   /**
    * Next, set_IO() is unnecessary, since it MUST be set by caller ALREADY.
    */

    /* This function is called for piggybacked write */
    if (cached_entry != NULL)
    {
        /* Copy the just written entry to array */
        kal_mem_cpy(&phb_entry_array->array[0], (void const*)cached_entry, sizeof(phb_entry_struct));

      /**
       * Since index of the just written entry is translated,
       * increment the index will make the reading from next entry of
       * the just written entry.
       */
        control_block->actual_count = 1;

        /* Reset record_index */
        control_block->record_index = (kal_uint16) PHB_INVALID_VALUE;
    }
    /* This function is called for piggybacked delete, or search */
    else
    {
        control_block->actual_count = 0;
    }

    /* Cannot but read physical storage for piggyback opeartion. */
    if (control_block->actual_count < control_block->total)
    {
      /**
       * Try to set control_block for next index; this is only needed when
       * cached_entry exists.
       */
        if (cached_entry != NULL)
        {
            control_block->index = cached_entry->index + 1;
        }

        /* Assign storage and record_index */
        /* set storage, record_index, primary_ID, and secondary_ID */
        if (phb_se_set_control_block(
                control_block,
                OP_READ,
                control_block->storage,
                control_block->record_index) == KAL_FALSE)
        {
            control_block->result = PHB_ERRNO_READ_FAIL;
            phb_read_err_handler(NULL, control_block, 0);
            return KAL_FALSE;
        }

        /* Assign control_block->data */
        /* This function is called for piggybacked write */
        if (cached_entry != NULL)
        {
            /* shift next read address */
            control_block->data = (kal_uint8*) & phb_entry_array->array[1];
        }
        else
        {
            control_block->data = (kal_uint8*) & phb_entry_array->array[0];
        }

        control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));
    }

   /**
    * If there is exactly only one to be piggybacked, which is already conveyed
    * in cache_entry, nothing is done here. Instead, read_continue() will
    * response back without reading phyiscal storage any further.
    */

    return KAL_TRUE;
}   /* end of phb_read_fake */


/*****************************************************************************
 * FUNCTION
 *  phb_is_read_param_valid
 * DESCRIPTION
 *  2 scenerio are allowed:
 *  read / write   index    total storage  record_index   Semantic
 *  READ           valid    n     ignored  0xFFFF         From PHB maintained index, read n entries.
 *  0xFFFF   1     valid    valid          Read a entry stored in {`storage', `record_index'}.The index of that entry,
 *  maintained by PHB, is also returned in confirmation primitive.
 * PARAMETERS
 *  l4cphb_read_req     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool phb_is_read_param_valid(l4cphb_read_req_struct *l4cphb_read_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Is type valid ? */
    if (!phb_is_type_valid(l4cphb_read_req->type))
    {
        return KAL_FALSE;
    }

    /* Should be scenario 1 */
    /* index must be valid, total must be valid */
    if (l4cphb_read_req->record_index == (kal_uint16) PHB_INVALID_VALUE)
    {
        /* Now check whether index, total fall into valid range of that type */
        return phb_se_is_in_range(l4cphb_read_req->type, l4cphb_read_req->index, &l4cphb_read_req->total);
    }
    /* Read specific record of certain storage is required */
    else
    {
        data_desc_enum type = DATA_DESC_PHB;

    #if !defined(__PHB_WISDOM_SUPPORT__) && !defined(PLUTO_MMI)
        /* Using case 2 of read to read ECC, MSISDN, and SDN is forbidden!  */
        if (((l4cphb_read_req->type == PHB_ECC) ||
            (l4cphb_read_req->type == PHB_MSISDN) || (l4cphb_read_req->type == PHB_SDN))
            && !l4c_is_src_from_rmmi(l4cphb_read_req->src_id))
    #else /* __PHB_WISDOM_SUPPORT__ */
        if (((l4cphb_read_req->type == PHB_ECC))
            && !l4c_is_src_from_rmmi(l4cphb_read_req->src_id))
    #endif /*  __PHB_WISDOM_SUPPORT__ */
        {
            return KAL_FALSE;
        }
    
        /* Total must be 1 for this operation */
        if (l4cphb_read_req->total != 1)
        {
            return KAL_FALSE;
        }

      /**
       * Since specific record is specified,
       * validity must be checked through data_desc
       */
        switch(l4cphb_read_req->type)       
        {
            case PHB_PHONEBOOK:
            {
                if (l4cphb_read_req->storage == PHB_STORAGE_NVRAM)
                {
                    type = DATA_DESC_PHB;
                }
                else
                {
                    type = DATA_DESC_ADN;
                }
                
                break;
            }
            case PHB_FDN:
            {
                type = DATA_DESC_FDN;
                break;
            }
            case PHB_BDN:
            {
                type = DATA_DESC_BDN;
                break;
            }
        #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
            case PHB_ANR:
            {
                if (l4cphb_read_req->num_index < 1 ||
                    l4cphb_read_req->num_index > phb_ptr->anr_count)
                {
                    return KAL_FALSE;
                }
                type = DATA_DESC_ADN;
                break;
            }
        #endif /* __PHB_USIM_SUPPORT__ */ 
            case PHB_MSISDN:
            {
                type = DATA_DESC_MSISDN;
                break;
            }
            default:
                break;
        }

        if (l4cphb_read_req->record_index > phb_data_desc_get_record_num(type))
        {
            return KAL_FALSE;
        }
    }
    return KAL_TRUE;
}   /* end of phb_is_read_param_valid */


#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  phb_is_read_param_valid
 * DESCRIPTION
 *  2 scenerio are allowed:
 *  read / write   index    total storage  record_index   Semantic
 *  READ           valid    n     ignored  0xFFFF         From PHB maintained index, read n entries.
 *  0xFFFF   1     valid    valid          Read a entry stored in {`storage', `record_index'}.The index of that entry,
 *  maintained by PHB, is also returned in confirmation primitive.
 * PARAMETERS
 *  l4cphb_read_req     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool phb_is_read_usim_param_valid(l4cphb_read_usim_req_struct *l4cphb_read_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_desc_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(l4cphb_read_req->type)       
    {
        case PHB_SNE:
            if (l4cphb_read_req->occurrence > phb_ptr->sne_count)
            {
                return KAL_FALSE;
            }
            type = DATA_DESC_ADN;
            break;
            
        case PHB_AAS:
            type = DATA_DESC_AAS;
            break;
            
        case PHB_GAS:
            type = DATA_DESC_GAS;
            break;

        case PHB_GRP:
            type = DATA_DESC_ADN;
            break;
        
        case PHB_EMAIL:
            if (l4cphb_read_req->occurrence > phb_ptr->email_count)
            {
                return KAL_FALSE;
            }
            type = DATA_DESC_ADN;
            break;
            
    #ifdef __PHB_USIM_SYNC__
        case PHB_PBC:
            type = DATA_DESC_PBC;
            break;
    #endif
        default:
            return KAL_FALSE;
    }
    
    if (l4cphb_read_req->record_index > phb_data_desc_get_record_num(type))
    {
        return KAL_FALSE;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  phb_read_usim_continue
 * DESCRIPTION
 *  This is phb_read_usim_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void* phb_read_usim_get_data(phb_type_enum type, l4c_phb_usim_field *phb_usim_field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (phb_usim_field)
    {
        switch (type)
        {
            case PHB_SNE:
                return &(phb_usim_field->sne);
                
            case PHB_AAS:
                return &(phb_usim_field->aas);
                
            case PHB_GAS:
                return &(phb_usim_field->gas);
                
            case PHB_GRP:
                return &(phb_usim_field->grp);
                
            case PHB_EMAIL:
                return &(phb_usim_field->email);
                
            case PHB_PBC:
                return &(phb_usim_field->pbc);

            default:
                break;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  phb_read_usim_fake
 * DESCRIPTION
 *  
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void phb_read_usim_fake(control_block_type *control_block, void *cached_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4c_phb_usim_field *phb_usim_field;
    kal_uint16 pdu_length;
    peer_buff_struct *peer_buf_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    peer_buf_ptr = construct_peer_buff(sizeof(l4c_phb_usim_field), 0, 0, TD_CTRL);
    phb_usim_field = (l4c_phb_usim_field*) get_32bits_aligned_val(get_peer_buff_pdu(peer_buf_ptr, &pdu_length));

    if (cached_data)
    {
        switch (control_block->type)
        {
            case PHB_SNE:
                kal_mem_cpy(&(phb_usim_field->sne), cached_data, sizeof(phb_sne_struct));
                break;

            case PHB_AAS:
                kal_mem_cpy(&(phb_usim_field->aas), cached_data, sizeof(phb_aas_struct));
                break;

            case PHB_GAS:
                kal_mem_cpy(&(phb_usim_field->gas), cached_data, sizeof(phb_gas_struct));
                break;

            case PHB_GRP:
                kal_mem_cpy(&(phb_usim_field->grp), cached_data, sizeof(phb_grp_struct));
                break;

            case PHB_EMAIL:
                kal_mem_cpy(&(phb_usim_field->email), cached_data, sizeof(phb_email_struct));
                break;

            case PHB_PBC:
                kal_mem_cpy(&(phb_usim_field->pbc), cached_data, sizeof(phb_pbc_struct));
                break;

            default:
                break;
        }
    }

    phb_control_block_set_param(control_block, READ_CONTINUE, NULL, peer_buf_ptr);
    phb_read_confirm(
        PHB_ERRNO_SUCCESS,
        control_block->actual_count,
        control_block->src_id,
        control_block->cnf_msg_id,
        control_block);
}


/*****************************************************************************
 * FUNCTION
 *  phb_read_usim_continue
 * DESCRIPTION
 *  This is phb_read_usim_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_read_usim_continue(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cblk->proc_stage != READ_CONTINUE)
    {
        cblk->result = PHB_ERRNO_READ_FAIL;
    }
    phb_read_confirm(
        cblk->result,
        cblk->actual_count,
        cblk->src_id,
        cblk->cnf_msg_id,
        cblk);
}


/*****************************************************************************
 * FUNCTION
 *  phb_read_usim_handler
 * DESCRIPTION
 *  This is phb_read_usim_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_read_usim_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    control_block_type *cblk;
    l4cphb_read_usim_req_struct *l4cphb_read_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_READ_USIM);

    l4cphb_read_req = (l4cphb_read_usim_req_struct*) ilm_ptr->local_para_ptr;

    /* Cannot allocate, means that PHB is still operating. Reject request! */
    cblk = phb_alloc_control_block();
    if (cblk == NULL)
    {
        phb_read_confirm_no_cb(
            PHB_ERRNO_BUSY,
            0,
            l4cphb_read_req->src_id,
            ilm_ptr->msg_id,
            l4cphb_read_req->record_index,
            l4cphb_read_req->occurrence,
            l4cphb_read_req->type);
        return;
    }

    cblk->src_id = l4cphb_read_req->src_id;

    /* Retain msg_id */
    cblk->cnf_msg_id = ilm_ptr->msg_id;

    if (phb_ptr->state == PHB_STATE_READY)
    {
        kal_uint16 pdu_length;
        peer_buff_struct *peer_buf_ptr;
        l4c_phb_usim_field *phb_usim_field;
        
        /* Invalid parameters */
        if (!phb_is_read_usim_param_valid(l4cphb_read_req))
        {
            phb_read_confirm_no_cb(
                PHB_ERRNO_READ_EMPTY,
                0,
                l4cphb_read_req->src_id,
                ilm_ptr->msg_id,
                l4cphb_read_req->record_index,
                l4cphb_read_req->occurrence,
                l4cphb_read_req->type);
            phb_free_control_block(cblk);
            return;
        }
        
        peer_buf_ptr = construct_peer_buff(sizeof(l4c_phb_usim_field), 0, 0, TD_CTRL);
        
        phb_usim_field = (l4c_phb_usim_field*) get_32bits_aligned_val(get_peer_buff_pdu(peer_buf_ptr, &pdu_length));
        cblk->need_free_peer = KAL_TRUE;
        phb_control_block_set_param(cblk, READ_CONTINUE, NULL, peer_buf_ptr);
        
        cblk->data = phb_read_usim_get_data(l4cphb_read_req->type, phb_usim_field);

        if (!(cblk->data))
        {
            phb_read_confirm(PHB_ERRNO_NOT_SUPPORT, 0, l4cphb_read_req->src_id, cblk->cnf_msg_id, cblk);
            return;
        }
        phb_control_block_set(
            cblk,
            phb_read_usim_continue,
            NULL,
            (err_handler_func_type)phb_read_err_handler,
            READ_CONTINUE);
        phb_control_block_set_IO(cblk, l4cphb_read_req->type, PHB_INVALID_VALUE, 1);
        phb_se_set_usim_control_block(
                cblk,
                PHB_STORAGE_SIM,
                l4cphb_read_req->record_index,
                l4cphb_read_req->occurrence);
        phb_issue_IO_read(cblk);
    }
    /* error */
    else
    {
        kal_trace(TRACE_ERROR, ERROR_PHB_STATE);

        cblk->actual_count = 0;
        phb_free_control_block(cblk);
        phb_read_confirm_no_cb(
            PHB_ERRNO_BUSY,
            0,
            l4cphb_read_req->src_id,
            ilm_ptr->msg_id,
            l4cphb_read_req->record_index,
            l4cphb_read_req->occurrence,
            l4cphb_read_req->type);
        return;
    }
}   /* end of phb_write_usim_handler */
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
