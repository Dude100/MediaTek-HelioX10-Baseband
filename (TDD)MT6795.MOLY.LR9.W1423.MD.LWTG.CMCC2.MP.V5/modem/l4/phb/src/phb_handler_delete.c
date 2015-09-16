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
 * phb_handler_delete.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is write handler of PHB module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include "kal_release.h"        /* Basic data type */

//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
//#include "stack_ltlcom.h" /* Task message communiction */
//#include "app_buff_alloc.h"

#include "kal_trace.h"
#include "phb_trc.h"

#include "sim_common_enums.h"
// #include "nvram_editor_data_item.h"
//#include "custom_nvram_editor_data_item.h"
#include "nvram_enums.h"
#include "nvram_struct.h"

//#include "l4_common.h"
//#include "ps2sim_struct.h"

#include "l4c2phb_enums.h"
#include "l4c2phb_struct.h"

/* Prerequisite of phb_context.h */
#include "phb_defs.h"
#include "phb_control_block.h"
//#include "phb_config.h"
#include "phb_data_desc.h"
//#include "phb_data_entry_table.h"
//#include "phb_pindex.h"
#include "phb_name_num_index.h"

#include "phb_context.h"
#include "phb_se.h"
//#include "phb_sap.h"

/* ErrorStruct */
//#include "asn-error.h"
#include "phb_common.h"
#include "phb_ilm.h"

#include "phb_handler_read.h"
#include "phb_handler_delete.h"
//#include "phb_nvram_access.h"

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
#include "phb_handler_write.h"
#endif 
#include "phb_utils.h"

#include "ps_public_enum.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "nvram_data_items.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "l4_msgid.h"
#include "nvram_msgid.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_HANDLER_DELETE_C_

static void phb_delete_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_delete_continue(ilm_struct *ilm_ptr, control_block_type *control_block);
static void phb_delete_confirm(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                control_block_type *control_block);
static void phb_delete_confirm_no_cb(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                msg_type cnf_msg_id,
                kal_uint16 record_index,
                kal_uint8 occurrence,
                phb_type_enum type);

#ifdef __PHB_USIM_SUPPORT__
#if defined(__GEMINI__) || defined(GEMINI_PLUS) || defined(__SGLTE__)
extern kal_bool is_usim_type(sim_interface_enum which_sim);
#else /* __GEMINI__ */
extern kal_bool is_usim_type(void);
#endif /* __GEMINI__ */
#endif /* __PHB_USIM_SUPPORT__ */

extern kal_bool l4c_is_src_from_rmmi(kal_uint8 src_id);

#ifndef __PHB_SORT_ENABLE__
/*****************************************************************************
 * FUNCTION
 *  phb_delete_find_next_deleted
 * DESCRIPTION
 *  Find record index of next occupied record
 * PARAMETERS
 *  storage             [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  record index of next free record.
 *****************************************************************************/
kal_uint16 phb_delete_find_next_deleted(phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_desc_enum type;
    data_desc_type *data_desc_entry;
    kal_uint16 byte_counter;
    kal_uint16 bit_counter, result = (kal_uint16) PHB_INVALID_VALUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_FIND_NEXT_FREE); */
    if (storage == PHB_STORAGE_NVRAM)
    {
        type = DATA_DESC_PHB;
    }
    else
    {
        type = DATA_DESC_ADN;
    }
    data_desc_entry = &phb_ptr->data_desc[type];
    ASSERT(data_desc_entry != NULL);

    if ((data_desc_entry->is_support == KAL_FALSE) ||
        (data_desc_entry->free_count == phb_data_desc_get_record_size(type)))
    {
        result = (kal_uint16) PHB_INVALID_VALUE;
    }
    else
    {
        for (byte_counter = 0;
             byte_counter < (data_desc_entry->free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC); ++byte_counter)
        {
            if (data_desc_entry->free_bitmap[byte_counter] != 0)
            {
                for (bit_counter = 0; (bit_counter < BYTE_SIZE) &&
                     (((byte_counter << BYTE_SIZE_SHIFT_ARITHMETIC) + bit_counter) < data_desc_entry->record_num);
                     ++bit_counter)
                {
                    if (!(data_desc_entry->free_bitmap[byte_counter] & (1 << bit_counter)))
                    {
                        result = (byte_counter << BYTE_SIZE_SHIFT_ARITHMETIC) + bit_counter + 1;
                    }
                }
            }
        }
    }
    
    PHB_TRACE((MOD_PHB, "phb_delete_find_next_deleted: %d", result),
              (TRACE_GROUP_2, PHB_TRC_DEL_FIND_NEXT, result)); 
    
    return result;
}   /* end of phb_delete_find_next_deleted */
#endif /* __PHB_SORT_ENABLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_delete_handler
 * DESCRIPTION
 *  This is phb_delete_handler function of PHB module.
 *  Handles write request from L4C.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_delete_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DELETE);

    if (ilm_ptr != NULL)
    {
        l4cphb_delete_req_struct *delete_req;

        delete_req = (l4cphb_delete_req_struct*) ilm_ptr->local_para_ptr;
        ASSERT(delete_req != NULL);

      /**
       * Delete should be exclusive from other operations, otherwise they could conflict.
       * Current PHB implementation doesn't prevent such conditions.
       * Such condition should happen at caller's own risk.
       */
        /* Cannot allocate, means that PHB is still operating. Reject request! */
        if (control_block == NULL)
        {
            control_block = phb_alloc_control_block();
            if (control_block == NULL)
            {
                phb_delete_confirm_no_cb(
                    PHB_ERRNO_BUSY,
                    0,
                    delete_req->src_id,
                    ilm_ptr->msg_id,
                    delete_req->index,
                    0,
                    delete_req->type);
                return;
            }

            control_block->src_id = delete_req->src_id;
            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;
        }

    #ifdef __PHB_WISDOM_SUPPORT__
        /* assign first for piggyback, if the result is fail,
           then maybe the index in control block is not assigned */
        control_block->index = delete_req->index;
    #endif /* __PHB_WISDOM_SUPPORT__ */

        if (phb_ptr->state == PHB_STATE_READY)
        {
            if (control_block->proc_stage == DELETE_NONE)
            {
                /* Reset actual count to zero */
                control_block->actual_count = 0;

                /* Error: ECC and SDN are read only */
                if (!phb_is_type_valid(delete_req->type) ||
                    (delete_req->type == PHB_ECC) ||
                    (delete_req->type == PHB_SDN) || (delete_req->type == PHB_GAS))

                {
                    phb_delete_confirm(PHB_ERRNO_FAIL, control_block->actual_count, control_block->src_id, control_block);
                    return;
                }

                if (delete_req->total == (kal_uint16) PHB_INVALID_VALUE)
                {
                    if (delete_req->index != 1)
                    {
                        phb_delete_confirm(
                            PHB_ERRNO_FAIL,
                            control_block->actual_count,
                            control_block->src_id,
                            control_block);
                        return;
                    }
                    
                #ifdef __PHB_DELETE_ALL_TURBO__
                    {
                    #ifndef __PHB_STORAGE_BY_MMI__
                        nvram_reset_req_struct *reset_req;
                        control_block->proc_stage = DELETE_ALL_CONTINUE;
                        control_block->IO_cnf_receive = phb_delete_handler;

                        reset_req = (nvram_reset_req_struct *)construct_local_para(sizeof(nvram_reset_req_struct), TD_CTRL);

                        reset_req->LID = (nvram_lid_enum) NVRAM_EF_PHB_LID;
                        reset_req->reset_category = NVRAM_RESET_CERTAIN;
                        reset_req->access_id = delete_req->src_id;
                        reset_req->rec_index = 1;
                        reset_req->rec_amount= NVRAM_EF_PHB_TOTAL;
                        phb_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_RESET_REQ, (local_para_struct *) reset_req, NULL);
                        return;
                    #endif
                    }
                #else /* __PHB_DELETE_ALL_TURBO__*/
                /* Delete all!! */
                    /* Ok, index = 1 and total = 0xFFFF, delete all! */
                    delete_req->total = phb_se_get_total_of_type(delete_req->type);
                    /* amanda add */
                    if (delete_req->type == PHB_PHONEBOOK)
                    {
                        control_block->storage = delete_req->storage;
                    #ifdef __PHB_SORT_ENABLE__
                        delete_req->index = phb_se_get_index_by_storage(control_block->storage);
                    #else 
                        delete_req->index = phb_delete_find_next_deleted(control_block->storage);
                    #endif 
                        if (delete_req->index == (kal_uint16)PHB_INVALID_VALUE)
                        {
                            phb_delete_confirm(PHB_ERRNO_SUCCESS, 0, delete_req->src_id, control_block);
                            return;
                        }
                    }
                #endif /* __PHB_DELETE_ALL_TURBO__ */
                }

                if (delete_req->index != (kal_uint16) PHB_INVALID_VALUE || 
                    delete_req->record_index != (kal_uint16) PHB_INVALID_VALUE)
                {
                    /* Since this is a delete operation, no need to prepare data for deletion. */
                    control_block->total = delete_req->total;

                    if (delete_req->type == PHB_PHONEBOOK ||
                        delete_req->type == PHB_FDN || // TODO: should not specify EF
                        delete_req->type == PHB_MSISDN || // TODO: should not specify EF
                    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
                        delete_req->type == PHB_ANR ||
                    #endif
                        phb_se_is_in_range(delete_req->type, delete_req->index, &delete_req->total) == KAL_TRUE)
                    {
                        /* This is for fectching necessary parameters from temp_entry */
                        delete_req->total = control_block->total;
                        phb_control_block_set_param(control_block, DELETE_CONTINUE, NULL, NULL);

                        phb_control_block_set(
                            control_block,
                            phb_delete_continue,
                            phb_delete_handler,
                            phb_delete_err_handler,
                            DELETE_CONTINUE);
                        phb_control_block_set_IO(
                            control_block,
                            delete_req->type,
                            delete_req->index,
                            delete_req->total);

                        control_block->record_index = delete_req->record_index;

                  /**
                   * Temporarily stores number of entries to be piggybacked.
                   * Don't forget to restore it back to control_block->total before
                   * read_fake(), if necessary.
                   */
                   #ifdef PLUTO_MMI
                        if (delete_req->record_index == (kal_uint16) PHB_INVALID_VALUE)
                        {
                            control_block->total_piggyback = delete_req->total_piggyback;
                        }
                   #endif
                   
                        /* set storage, record_index, primary_ID, and secondary_ID */
                        if (phb_se_set_control_block(
                                control_block,
                                OP_DELETE,
                                delete_req->storage,
                                delete_req->record_index) == KAL_FALSE)
                        {
                            phb_delete_confirm(PHB_ERRNO_FAIL, control_block->actual_count, control_block->src_id, control_block);
                            return;
                        }

                        /* Since this is a delete operation, no need to set data. */
                        control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

                        /*
                         * If it is a MSISDN entry, need to read the data from SIM first to see if the MSISDN uses extenstion 1
                         * *    So allocate buffer to store read data for phb_issue_IO_read() command here.
                         */
                    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
                        if (delete_req->type == PHB_ANR)
                        {
                            control_block->occurrence = (kal_uint8)delete_req->num_index;
                        }
                    #endif
                        phb_delete_continue(NULL, control_block);
                    }
                #ifdef __PHB_WISDOM_SUPPORT__
                    else if (delete_req->record_index != (kal_uint16) PHB_INVALID_VALUE && delete_req->type == PHB_FDN)
                    {
                        control_block->total = delete_req->total;
                        if (1)
                        {
                            /* This is for fectching necessary parameters from temp_entry */
                            delete_req->total = control_block->total;
                            phb_control_block_set_param(control_block, DELETE_CONTINUE, NULL, NULL);

                            phb_control_block_set(
                                control_block,
                                phb_delete_continue,
                                phb_delete_handler,
                                phb_delete_err_handler,
                                DELETE_CONTINUE);
                            phb_control_block_set_IO(
                                control_block,
                                delete_req->type,
                                delete_req->index,
                                delete_req->total);

                            control_block->record_index = delete_req->record_index;
                            /**
                             * Temporarily stores number of entries to be piggybacked.
                             * Don't forget to restore it back to control_block->total before
                             * read_fake(), if necessary.
                             */
                            control_block->total_piggyback = delete_req->total_piggyback;

                            /* set storage, record_index, primary_ID, and secondary_ID */

                            if (phb_se_set_control_block(
                                    control_block,
                                    OP_DELETE,
                                    delete_req->storage,
                                    (kal_uint16) PHB_INVALID_VALUE) == KAL_FALSE)
                            {
                                phb_delete_confirm(PHB_ERRNO_FAIL, control_block->actual_count, control_block->src_id, control_block);
                                return;
                            }

                            /* Since this is a delete operation, no need to set data. */
                            control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

                            phb_delete_continue(NULL, control_block);
                        }
                        else
                        {
                            phb_delete_confirm(
                                PHB_ERRNO_FAIL,
                                control_block->actual_count,
                                control_block->src_id,
                                control_block);
                            return;
                        }
                    }
                #endif /* __PHB_WISDOM_SUPPORT__ */
                    else
                    {
                        phb_delete_confirm(
                            PHB_ERRNO_FAIL,
                            control_block->actual_count,
                            control_block->src_id,
                            control_block);
                        return;
                    }
                }
                /* error */
                else
                {
                    phb_delete_confirm(PHB_ERRNO_FAIL, control_block->actual_count, control_block->src_id, control_block);
                    return;
                }
            }
        #ifdef __PHB_DELETE_ALL_TURBO__ 
            else if(control_block->proc_stage == DELETE_ALL_CONTINUE)
            {
                nvram_reset_cnf_struct *msg_ptr = NULL;
                msg_ptr = (nvram_reset_cnf_struct*) ilm_ptr->local_para_ptr;
                if (msg_ptr->result == NVRAM_ERRNO_SUCCESS)
                {
                    phb_delete_confirm(PHB_ERRNO_SUCCESS, 0xFFFF, control_block->src_id, control_block);
                    return;
                }
                else
                {
                    phb_delete_confirm(PHB_ERRNO_FAIL, 0xFFFF, control_block->src_id, control_block);
                    return;            
                }   
            }       
        #endif /* __PHB_DELETE_ALL_TURBO__ */
            /* error */
            else
            {
                phb_delete_confirm(PHB_ERRNO_FAIL, control_block->actual_count, control_block->src_id, control_block);
                return;
            }
        }
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_STATE);

            phb_delete_confirm(PHB_ERRNO_NOT_READY, control_block->actual_count, control_block->src_id, control_block);
            return;
        }
    }
    else
    {
        /* Delete confirmed */
        if (phb_ctrl_blk_get_state(control_block) == DELETE_CONTINUE)
        {
            /* Piggyback is not required. */
            if (control_block->total_piggyback < 1
            #ifndef __PHB_SORT_ENABLE__
                || control_block->type == PHB_PHONEBOOK
            #endif
            #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
                || control_block->type == PHB_ANR
            #endif
                )
            {
                phb_delete_confirm(
                    control_block->result,
                    control_block->actual_count,
                    control_block->src_id,
                    control_block);
            }
            /* Piggyback is required */
            else
            {
                /* Now we have to transform the state to a *FAKE* read state. */
                control_block->total = control_block->total_piggyback;
            #ifdef __PHB_WISDOM_SUPPORT__
                if (control_block->type == PHB_FDN)
                {
                    phb_delete_confirm(
                        control_block->result,
                        control_block->actual_count,
                        control_block->src_id,
                        control_block);
                    return;
                }
            #endif /* __PHB_WISDOM_SUPPORT__ */
            /**
             * Weird error happened. Anyway, the entry is already written
             * successfully.
             */
                if (phb_se_is_in_range(control_block->type, control_block->index, &control_block->total) == KAL_FALSE)
                {
                    phb_delete_confirm(
                        control_block->result,
                        control_block->actual_count,
                        control_block->src_id,
                        control_block);
                    return;
                }

                /* If any critial error occured. read_err_handler will handle it. */
                if (phb_read_fake(control_block, NULL) == KAL_FALSE)
                {
                    return;
                }

                /* Finally, faking complete....Now continue reading */
                phb_read_continue(NULL, control_block);
                return;
            }
        }
        /* error */
        else
        {
            phb_delete_confirm(PHB_ERRNO_FAIL, control_block->actual_count, control_block->src_id, control_block);
            return;
        }
    }
}   /* end of phb_delete_handler */


/*****************************************************************************
 * FUNCTION
 *  phb_delete_err_handler
 * DESCRIPTION
 *  This is phb_delete_err_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_delete_err_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DELETE_ERR);

   /**
    * Shall we try to recover/continue handling,
    * or just reject the request in processing?
    * Currently, the latter is adpoted.
    */
    phb_delete_confirm(control_block->result, control_block->actual_count, control_block->src_id, control_block);

    /*
     * if (ilm_ptr != NULL)
     * (*phb_ptr->control_block.controller)(ilm_ptr);
     */
}   /* end of phb_delete_err_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_delete_continue
 * DESCRIPTION
 *  This is phb_delete_continue function of PHB module.
 *  
 *  Since only exactly one entry can be written at a time, this function just issues write
 *  request if it's time to begin write prepared data, or give control back to controller.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_delete_continue(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DELETE_CONT);

    /* It's time to write prepared dat */
    if (ilm_ptr == NULL)
    {
        phb_issue_IO_delete(control_block);
    }
    /* Write confirmed. Give control back to contoller */
    else
    {
        kal_uint8 ext_index = (kal_uint8) PHB_INVALID_VALUE;

        control_block->candidate = control_block->index;
        /* First we have to sync the deleted entry into search engine */
        /* The deleted index is in control_block->index */
        if (control_block->index == (kal_uint16) PHB_INVALID_VALUE)
        {
            phb_se_delete(control_block->type, (kal_uint16) (control_block->record_index - 1), &ext_index, control_block->storage);
        }
        else
        {
            phb_se_delete(control_block->type, (kal_uint16) (control_block->index - 1), &ext_index, control_block->storage);
        }
    #if defined(__PHB_FDN_GET_NAME__) || defined(__ECALL_SUPPORT__)
        if (control_block->type == PHB_FDN)
        {
            phb_update_fdn_context(control_block->record_index, NULL, NULL);
        }
    #endif /* __PHB_FDN_GET_NAME__ */

        ++control_block->actual_count;

        PHB_TRACE((MOD_PHB, "    actual_count = %d, total = %d, index = %d", control_block->actual_count, control_block->total, control_block->index),
                  (TRACE_GROUP_1, PHB_TRC_DEL_CONT_TOTAL, control_block->actual_count, control_block->total, control_block->index)); 

        /* Delete complete, now return control back to controller */
        if (control_block->actual_count >= control_block->total)
        {
            (*control_block->controller) (NULL, control_block);
        }
      /**
       * Still others to delete
       * Since index, total is in ensured to be in range, tested in handler(), it is uncessary
       * to test it here.
       */
        else if (control_block->index != (kal_uint16) PHB_INVALID_VALUE)
        {
         /**
          * Index should NOT be decremented!!
          * Because entries will be shift into the deleted index!!
          */

            /* amanda add */
            if (control_block->type == PHB_PHONEBOOK)
            {
            #ifdef __PHB_SORT_ENABLE__
                control_block->index = phb_se_get_index_by_storage(control_block->storage);
            #else 
                control_block->index = phb_delete_find_next_deleted(control_block->storage);
            #endif 
                /* no more to delete */
                if (control_block->index == (kal_uint16) PHB_INVALID_VALUE)
                {
                    (*control_block->controller) (NULL, control_block);
                    return;
                }

            }
            /* set storage, record_index, primary_ID, and secondary_ID */
            if (phb_se_set_control_block(
                    control_block,
                    OP_DELETE,
                    PHB_STORAGE_NONE,
                    (kal_uint16) PHB_INVALID_VALUE) == KAL_FALSE)
            {
                phb_delete_confirm(PHB_ERRNO_FAIL, control_block->actual_count, control_block->src_id, control_block);
                return;
            }

            control_block->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(control_block->primary_ID, control_block->storage));

            phb_issue_IO_delete(control_block);
        }
        /* error */
        else
        {
            phb_delete_confirm(PHB_ERRNO_FAIL, control_block->actual_count, control_block->src_id, control_block);
            return;
        }
    }
}   /* end of phb_delete_continue */


/*****************************************************************************
 * FUNCTION
 *  phb_delete_confirm
 * DESCRIPTION
 *  This is phb_delete_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  actual_count        [IN]        
 *  src_id              [IN]        
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_delete_confirm(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    local_para_struct *local_param_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DELETE_CNF, result, actual_count, src_id);
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    if (control_block->cnf_msg_id == MSG_ID_L4CPHB_DELETE_USIM_REQ)
    {        
        l4cphb_delete_usim_cnf_struct *l4cphb_delete_cnf;
        
        l4cphb_delete_cnf = (l4cphb_write_usim_cnf_struct*) construct_local_para(sizeof(l4cphb_write_usim_cnf_struct), TD_CTRL);
        l4cphb_delete_cnf->src_id = src_id;

        local_param_ptr = (local_para_struct*) l4cphb_delete_cnf;

        /* If result is PHB_ERRNO_BUSY, reject newly received request */
        l4cphb_delete_cnf->result = result;
        l4cphb_delete_cnf->record_index = control_block->record_index;
        l4cphb_delete_cnf->occurrence = control_block->occurrence;
        l4cphb_delete_cnf->type = control_block->type;

        /* Field `cause' is meaningful when I/O occured by using control blocks */
        l4cphb_delete_cnf->cause = control_block->cause;

        phb_free_control_block(control_block);

        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_DELETE_USIM_CNF, local_param_ptr, NULL);
    }
    else
#endif /* __PHB_USIM_SUPPORT__ */ 
    {
        l4cphb_delete_cnf_struct *l4cphb_delete_cnf;

        l4cphb_delete_cnf = (l4cphb_delete_cnf_struct*) construct_local_para(sizeof(l4cphb_delete_cnf_struct), TD_CTRL);
        l4cphb_delete_cnf->total = actual_count;
        l4cphb_delete_cnf->src_id = src_id;

        local_param_ptr = (local_para_struct*) l4cphb_delete_cnf;

        /* If result is PHB_ERRNO_BUSY, reject newly received request */
        l4cphb_delete_cnf->result = result;

        /* Confirm to in-processing operation */
        /* Field `cause' is meaningful when I/O occured by using control blocks */
        l4cphb_delete_cnf->cause = control_block->cause;
    #ifndef __PHB_WISDOM_SUPPORT__
    #ifndef __PHB_STORAGE_BY_MMI__
        l4cphb_delete_cnf->old_index = control_block->candidate;
    #else
        if (!(control_block->type == PHB_FDN || control_block->type == PHB_FDN))
        {
            l4cphb_delete_cnf->old_index = control_block->candidate;
        }
        else
        {
            l4cphb_delete_cnf->old_index = control_block->record_index;
        }
    #endif
        
    #else /* __PHB_WISDOM_SUPPORT__ */
        if (control_block->type == PHB_FDN)
        {
            l4cphb_delete_cnf->old_index = control_block->record_index;
        }
        else
        {
            l4cphb_delete_cnf->old_index = control_block->index;
        }
    #endif /* __PHB_WISDOM_SUPPORT__ */
        l4cphb_delete_cnf->type = control_block->type;

        phb_free_control_block(control_block);

        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_DELETE_CNF, local_param_ptr, NULL);
    }
}   /* end of phb_delete_confirm */


/*****************************************************************************
 * FUNCTION
 *  phb_delete_confirm
 * DESCRIPTION
 *  This is phb_delete_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  actual_count        [IN]        
 *  src_id              [IN]        
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_delete_confirm_no_cb(
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
    local_para_struct *local_param_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DELETE_CNF, result, actual_count, src_id);
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    if (cnf_msg_id == MSG_ID_L4CPHB_DELETE_USIM_REQ)
    {        
        l4cphb_delete_usim_cnf_struct *l4cphb_delete_cnf;
        
        l4cphb_delete_cnf = (l4cphb_write_usim_cnf_struct*) construct_local_para(sizeof(l4cphb_write_usim_cnf_struct), TD_CTRL);
        l4cphb_delete_cnf->src_id = src_id;

        local_param_ptr = (local_para_struct*) l4cphb_delete_cnf;

        /* If result is PHB_ERRNO_BUSY, reject newly received request */
        l4cphb_delete_cnf->result = result;
        l4cphb_delete_cnf->record_index = record_index;
        l4cphb_delete_cnf->occurrence = occurrence;
        l4cphb_delete_cnf->type = type;

        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_DELETE_USIM_CNF, local_param_ptr, NULL);
    }
    else
#endif /* __PHB_USIM_SUPPORT__ */ 
    {
        l4cphb_delete_cnf_struct *l4cphb_delete_cnf;

        l4cphb_delete_cnf = (l4cphb_delete_cnf_struct*) construct_local_para(sizeof(l4cphb_delete_cnf_struct), TD_CTRL);
        l4cphb_delete_cnf->total = actual_count;
        l4cphb_delete_cnf->src_id = src_id;

        local_param_ptr = (local_para_struct*) l4cphb_delete_cnf;

        /* If result is PHB_ERRNO_BUSY, reject newly received request */
        l4cphb_delete_cnf->result = result;

        /* Confirm to in-processing operation */
        l4cphb_delete_cnf->old_index = record_index;
        l4cphb_delete_cnf->type = type;

        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_DELETE_CNF, local_param_ptr, NULL);
    }
}

#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  phb_delete_usim_continue
 * DESCRIPTION
 *  This is phb_delete_usim_continue function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_delete_usim_continue(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cblk->proc_stage != DELETE_CONTINUE)
    {
        cblk->result = PHB_ERRNO_FAIL;
    }
    phb_delete_confirm(
        cblk->result,
        cblk->actual_count,
        cblk->src_id,
        cblk);
}


/*****************************************************************************
 * FUNCTION
 *  phb_delete_usim_handler
 * DESCRIPTION
 *  This is phb_delete_usim_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_delete_usim_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    control_block_type *cblk;
    l4cphb_delete_usim_req_struct *l4cphb_delete_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DELETE_USIM);

    l4cphb_delete_req = (l4cphb_delete_usim_req_struct*) ilm_ptr->local_para_ptr;

    /* Cannot allocate, means that PHB is still operating. Reject request! */
    cblk = phb_alloc_control_block();
    if (cblk == NULL)
    {
        phb_delete_confirm_no_cb(
            PHB_ERRNO_BUSY,
            0,
            l4cphb_delete_req->src_id,
            ilm_ptr->msg_id,
            l4cphb_delete_req->record_index,
            l4cphb_delete_req->occurrence,
            l4cphb_delete_req->type);
        return;
    }

    cblk->src_id = l4cphb_delete_req->src_id;

    /* Retain msg_id */
    cblk->cnf_msg_id = ilm_ptr->msg_id;

    if (phb_ptr->state == PHB_STATE_READY)
    {
        phb_control_block_set(
            cblk,
            phb_delete_usim_continue,
            NULL,
            phb_delete_err_handler,
            DELETE_CONTINUE);
        phb_control_block_set_IO(cblk, l4cphb_delete_req->type, PHB_INVALID_VALUE, 1);

        /* set storage, record_index, primary_ID, and secondary_ID */
        phb_se_set_usim_control_block(
            cblk,
            PHB_STORAGE_SIM,
            l4cphb_delete_req->record_index,
            l4cphb_delete_req->occurrence);
        phb_issue_IO_delete(cblk);
    }
    /* error */
    else
    {
        kal_trace(TRACE_ERROR, ERROR_PHB_STATE);

        cblk->actual_count = 0;
        phb_free_control_block(cblk);
        phb_delete_confirm_no_cb(
            PHB_ERRNO_BUSY,
            0,
            l4cphb_delete_req->src_id,
            ilm_ptr->msg_id,
            l4cphb_delete_req->record_index,
            l4cphb_delete_req->occurrence,
            l4cphb_delete_req->type);
        return;
    }
}   /* end of phb_write_usim_handler */
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */ 


