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
 * phb_handler_write.c
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

// #include "nvram_editor_data_item.h"
//#include "custom_nvram_editor_data_item.h"
//#include "sim_common_enums.h"
//#include "l4c_common_enum.h"
//#include "mcd_l3_inc_struct.h"
#include "l4c_utility.h"  /* for l4c_is_src_from_rmmi */

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
//#include "phb_utils.h"

/* ErrorStruct */
//#include "asn-error.h"
#include "phb_common.h"
#include "phb_ilm.h"

#include "phb_sap.h"
#include "phb_handler_read.h"
#include "phb_handler_write.h"
//#include "phb_nvram_access.h"
#include "phb_sim_access.h"

//#include "nvram_enums.h"
//#include "nvram_struct.h"

#if defined(__PHB_FDN_GET_NAME__) || defined(__ECALL_SUPPORT__)
#include "phb_context.h"
#endif

#include "ps_public_enum.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_HANDLER_WRITE_C_

static void phb_write_err_handler(ilm_struct *ilm_ptr, control_block_type *cblk);
static void phb_write_continue(ilm_struct *ilm_ptr, control_block_type *cblk);
static void phb_write_confirm(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                control_block_type *cblk);
static void phb_write_confirm_no_cb(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                msg_type cnf_msg_id,
                kal_uint16 record_index,
                kal_uint8 occurrence,
                phb_type_enum type);

#ifdef __PHB_WISDOM_SUPPORT__
kal_bool phb_is_fdn_with_ext = KAL_FALSE;
#endif /* __PHB_WISDOM_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  phb_write_handler
 * DESCRIPTION
 *  This is phb_write_handler function of PHB module.
 *  Handles write request from L4C.
 *  3 scenerio are allowed:
 *  read / write   index    total storage  record_index   Semantic
 *  WRITE          0xFFFF         valid    valid          Write an entry to user-specified physical location - {`storage', `record_index'}
 *  This operation is `add'.
 *  valid          ignored  0xFFFF         Write an entry to `index'th entry maintained by PHB.
 *  This opeartion is `update'.
 *  0xFFFF         valid    0xFFFF         Write an entry to `storage'. The physical location written is a free record searched by PHB.
 *  This opeartion is `add'.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_write_handler(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_WRITE);

    if (ilm_ptr != NULL)
    {
        l4cphb_write_req_struct *l4cphb_write_req;

        l4cphb_write_req = (l4cphb_write_req_struct*) ilm_ptr->local_para_ptr;

        /* Cannot allocate, means that PHB is still operating. Reject request! */
        cblk = phb_alloc_control_block();
        if (cblk == NULL)
        {
            phb_write_confirm_no_cb(
                PHB_ERRNO_BUSY,
                0,
                l4cphb_write_req->src_id,
                ilm_ptr->msg_id,
                0,
                0,
                l4cphb_write_req->type);
            return;
        }

        cblk->src_id = l4cphb_write_req->src_id;

        /* Retain msg_id */
        cblk->cnf_msg_id = ilm_ptr->msg_id;

        if (phb_ptr->state == PHB_STATE_READY)
        {
            if (cblk->proc_stage == PHB_WRITE_STAGE_NONE)
            {
                kal_uint8 *pdu_ptr;
                kal_uint16 pdu_length;

                phb_entry_struct *phb_entry;
                l4cphb_phb_entry_array_struct *l4cphb_phb_entry_array;

                /* Error: ECC and SDN are read only */
                if (!phb_is_type_valid(l4cphb_write_req->type) ||
                    (l4cphb_write_req->type == PHB_ECC) || (l4cphb_write_req->type == PHB_SDN))
                {
                    cblk->result = PHB_ERRNO_FAIL;
                    phb_write_err_handler(NULL, cblk);
                    return;
                }

                /* First we have to unpack user's request */
            /**
             * Number of entries can be wriiten is exactly 1.
             * Hence, number of entries in peer buffer is expected to be 1.
             *
             * Since the entry to write is requested from L4C,
             * here a temporary l4cphb_phb_entry_array is allocated, so that user's
             * parameter can be unpacked to cblk->temp_entry.
             */

                pdu_ptr = (kal_uint8*) get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &pdu_length);
                l4cphb_phb_entry_array = (l4cphb_phb_entry_array_struct*) get_32bits_aligned_val(pdu_ptr);
                phb_entry = &l4cphb_phb_entry_array->array[0];

            /**
             * After copying user's parameter from peer buffer, temporary
             * l4cphb_phb_entry_array can be freed.
             *
             * The entry to be written is stored in temp_entry!!
             */
                kal_mem_cpy(&cblk->temp_entry, (void const*)phb_entry, sizeof(phb_entry_struct));

            /**
             * Finally, the data to write is prepared in cblk->temp_entry.
             * Now the prepared data can be written.
             */
                /* This is for fectching necessary parameters from temp_entry */
                phb_entry = (phb_entry_struct*) & cblk->temp_entry;
            #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
                if (l4cphb_write_req->type == PHB_ANR)
                {
                    cblk->occurrence = (kal_uint8)phb_entry->num_index;
                }
            #endif
                phb_control_block_set_param(cblk, PHB_WRITE_STAGE_CONTINUE, NULL, NULL);

                phb_control_block_set(
                    cblk,
                    phb_write_continue,
                    phb_write_handler,
                    phb_write_err_handler,
                    PHB_WRITE_STAGE_CONTINUE);
                phb_control_block_set_IO(cblk, l4cphb_write_req->type, phb_entry->index, 1);

                /**
                  * Temporarily stores number of entries to be piggybacked.
                  * Don't forget to restore it back to cblk->total before
                  * read_fake(), if necessary.
                  */
                cblk->total_piggyback = l4cphb_write_req->total;
            #ifdef __PHB_WISDOM_SUPPORT__
                phb_is_fdn_with_ext = KAL_FALSE;
            #endif /* __PHB_WISDOM_SUPPORT__ */
                /* set storage, record_index, primary_ID, and secondary_ID */
                if (phb_se_set_control_block(
                        cblk,
                        OP_WRITE,
                        phb_entry->storage,
                        phb_entry->record_index) == KAL_FALSE)
                {
                    cblk->result = PHB_ERRNO_FAIL;
                    phb_write_err_handler(NULL, cblk);
                    return;
                }
            #ifndef PLUTO_MMI
                if (l4c_is_src_from_rmmi(cblk->src_id))
            #endif
                {
                    phb_entry->index = cblk->index;
                }
            #ifdef __PHB_WISDOM_SUPPORT__
                if (phb_is_fdn_with_ext == KAL_TRUE)
                {
                    phb_is_fdn_with_ext = KAL_FALSE;
                    phb_entry->index = cblk->index;
                }
            #endif /* __PHB_WISDOM_SUPPORT__ */

                /* data stores data to be written, and length is record size of storage */
                cblk->data = (kal_uint8*) & cblk->temp_entry;
                cblk->length = phb_data_desc_get_record_size(phb_data_desc_get_desc_by_ID(cblk->primary_ID, cblk->storage));

                phb_write_continue(NULL, cblk);
            }
            /* error */
            else
            {
                cblk->result = PHB_ERRNO_FAIL;
                phb_write_err_handler(NULL, cblk);
                return;
            }
        }
        /* error */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_STATE);

            cblk->actual_count = 0;
            phb_write_confirm(PHB_ERRNO_BUSY, cblk->actual_count, cblk->src_id, cblk);
            return;
        }

    }
    /* Write confirmed */
    else if (cblk->proc_stage == PHB_WRITE_STAGE_DONE)
    {
        /* Piggyback is not required. */
        if (cblk->total_piggyback < 1)
        {
            phb_write_confirm(PHB_ERRNO_SUCCESS, cblk->actual_count, cblk->src_id, cblk);
        }
        /* Piggyback is required */
        else
        {
            /* Now we have to transform the state to a *FAKE* read state. */
            phb_entry_struct *phb_entry;

            /* Restore total_piggyback */
            cblk->total = cblk->total_piggyback;

            /* The just written entry is still there! */
            phb_entry = (phb_entry_struct*) & cblk->temp_entry;

            /* cblk->set_IO() need not be invoked, because type, total is already be set. */
            /* Weird error happened. Anyway, the entry is already written successfully. */
            if (
            #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
                cblk->type != PHB_ANR && 
            #endif
                phb_se_is_in_range(cblk->type, phb_entry->index, &cblk->total) == KAL_FALSE)
            {
                cblk->actual_count = 1;
                phb_write_confirm(PHB_ERRNO_SUCCESS, cblk->actual_count, cblk->src_id, cblk);
                return;
            }

            /* If any critial error occured. read_err_handler will handle it. */
            if (phb_read_fake(cblk, phb_entry) == KAL_FALSE)
            {
                return;
            }

            /* Finally, faking complete....Now continue reading */
            phb_read_continue(NULL, cblk);
            return;
        }
    }
    /* error */
    else
    {
        cblk->result = PHB_ERRNO_FAIL;
        phb_write_err_handler(NULL, cblk);
        return;
    }
}   /* end of phb_write_handler */


/*****************************************************************************
 * FUNCTION
 *  phb_write_err_handler
 * DESCRIPTION
 *  This is phb_write_err_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_write_err_handler(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_ERR);

   /**
    * Shall we try to recover/continue handling,
    * or just reject the request in processing?
    * Currently, the latter is adpoted.
    */
    cblk->actual_count = 0;
    phb_write_confirm(cblk->result, cblk->actual_count, cblk->src_id, cblk);

    /*
     * if (ilm_ptr != NULL)
     * (*phb_ptr->cblk.controller)(ilm_ptr);
     */
}   /* end of phb_write_err_handler function */


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
void phb_write_usim_continue(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cblk->proc_stage != PHB_WRITE_STAGE_CONTINUE)
    {
        cblk->result = PHB_ERRNO_FAIL;
    }
    if (cblk->result != PHB_ERRNO_SUCCESS)
    {
        phb_write_confirm(
            cblk->result,
            cblk->actual_count,
            cblk->src_id,
            cblk);
    }
    else
    {
        phb_read_usim_fake(cblk, &(cblk->temp_entry));
    }
        
}


/*****************************************************************************
 * FUNCTION
 *  phb_write_usim_handler
 * DESCRIPTION
 *  This is phb_write_usim_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_write_usim_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    control_block_type *cblk;
    l4cphb_write_usim_req_struct *l4cphb_write_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_USIM);

    l4cphb_write_req = (l4cphb_write_usim_req_struct*) ilm_ptr->local_para_ptr;

    /* Cannot allocate, means that PHB is still operating. Reject request! */
    cblk = phb_alloc_control_block();
    if (cblk == NULL)
    {
        phb_write_confirm_no_cb(
            PHB_ERRNO_BUSY,
            0,
            l4cphb_write_req->src_id,
            ilm_ptr->msg_id,
            l4cphb_write_req->record_index,
            l4cphb_write_req->occurrence,
            l4cphb_write_req->type);
        return;
    }

    cblk->src_id = l4cphb_write_req->src_id;

    /* Retain msg_id */
    cblk->cnf_msg_id = ilm_ptr->msg_id;

    if (phb_ptr->state == PHB_STATE_READY)
    {
        kal_uint8 *pdu_ptr;
        kal_uint16 pdu_length;

        l4c_phb_usim_field *phb_usim_field;
        if (ilm_ptr->peer_buff_ptr == NULL)
        {
            /* phb_write_usim_err_handler(NULL, cblk); */
            phb_write_confirm(PHB_ERRNO_FAIL, 0, cblk->src_id, cblk);
            return;
        }
        pdu_ptr = (kal_uint8*) get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &pdu_length);
        phb_usim_field = (l4c_phb_usim_field*) get_32bits_aligned_val(pdu_ptr);
        switch (l4cphb_write_req->type)
        {
            case PHB_SNE:
                kal_mem_cpy(&cblk->temp_entry, (void const*)&(phb_usim_field->sne), sizeof(phb_sne_struct));
                break;
                
            case PHB_AAS:
                kal_mem_cpy(&cblk->temp_entry, (void const*)&(phb_usim_field->aas), sizeof(phb_aas_struct));
                break;
                
            case PHB_GAS:
                kal_mem_cpy(&cblk->temp_entry, (void const*)&(phb_usim_field->gas), sizeof(phb_gas_struct));
                break;
                
            case PHB_GRP:
                kal_mem_cpy(&cblk->temp_entry, (void const*)&(phb_usim_field->grp), sizeof(phb_grp_struct));
                break;
                
            case PHB_EMAIL:
                kal_mem_cpy(&cblk->temp_entry, (void const*)&(phb_usim_field->email), sizeof(phb_email_struct));
                break;
                
            case PHB_PBC:
                kal_mem_cpy(&cblk->temp_entry, (void const*)&(phb_usim_field->pbc), sizeof(phb_pbc_struct));
                break;

            default:
                phb_write_confirm(PHB_ERRNO_NOT_SUPPORT, 0, l4cphb_write_req->src_id, cblk);
                return;
        }
        phb_control_block_set(
            cblk,
            phb_write_usim_continue,
            NULL,
            phb_write_err_handler,
            PHB_WRITE_STAGE_CONTINUE);
        phb_control_block_set_IO(cblk, l4cphb_write_req->type, PHB_INVALID_VALUE, 1);

        /* set storage, record_index, primary_ID, and secondary_ID */
        phb_se_set_usim_control_block(
            cblk,
            PHB_STORAGE_SIM,
            l4cphb_write_req->record_index,
            l4cphb_write_req->occurrence);

        /* data stores data to be written, and length is record size of storage */
        cblk->data = (kal_uint8*) & cblk->temp_entry;

        phb_issue_IO_write(cblk);
    }
    /* error */
    else
    {
        kal_trace(TRACE_ERROR, ERROR_PHB_STATE);
        phb_free_control_block(cblk);
        phb_write_confirm_no_cb(
            PHB_ERRNO_BUSY,
            0,
            l4cphb_write_req->src_id,
            ilm_ptr->msg_id,
            l4cphb_write_req->record_index,
            l4cphb_write_req->occurrence,
            l4cphb_write_req->type);
    }
}   /* end of phb_write_usim_handler */


/*****************************************************************************
 * FUNCTION
 *  phb_write_confirm
 * DESCRIPTION
 *  This is phb_write_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  actual_count        [IN]        
 *  src_id              [IN]        
 *  cblk       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_check_write_usim_confirm(
                phb_errno_enum result,
                kal_uint8 src_id,
                kal_uint16 record_index,
                data_desc_enum desc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    local_para_struct *local_param_ptr = NULL;
    l4cphb_check_write_usim_entry_cnf_struct *l4cphb_check_write_cnf;
    kal_uint8 occurrence = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_CNF, result, record_index, desc);

    l4cphb_check_write_cnf = 
        (l4cphb_check_write_usim_entry_cnf_struct*)construct_local_para(
                                                        sizeof(l4cphb_check_write_usim_entry_cnf_struct),
                                                        TD_CTRL);
    local_param_ptr = (local_para_struct*) l4cphb_check_write_cnf;
    if (result == PHB_ERRNO_FAIL && desc)
    {
        if (desc >= DATA_DESC_SNE && desc < DATA_DESC_ANR)
        {
            result = PHB_ERRNO_SNE_FULL;
            occurrence = (kal_uint8)(desc - DATA_DESC_SNE + 1);
        }
        else if (desc >= DATA_DESC_ANR && desc < DATA_DESC_GRP)
        {
            result = PHB_ERRNO_ANR_FULL;
            occurrence = (kal_uint8)(desc - DATA_DESC_ANR + 1);
        }
        else if (desc >= DATA_DESC_EMAIL && desc < DATA_DESC_AAS)
        {
            result = PHB_ERRNO_EMAIL_FULL;
            occurrence = (kal_uint8)(desc - DATA_DESC_EMAIL + 1);
        }
    }

    l4cphb_check_write_cnf->src_id = src_id;
    l4cphb_check_write_cnf->result = result;
    l4cphb_check_write_cnf->record_index = record_index;
    l4cphb_check_write_cnf->occurrence = occurrence;

    phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_CHECK_WRITE_USIM_ENTRY_CNF, local_param_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  phb_write_confirm
 * DESCRIPTION
 *  This is phb_write_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  actual_count        [IN]        
 *  src_id              [IN]        
 *  cblk       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int8 phb_verify_check_write_usim_param(l4cphb_check_write_usim_entry_req_struct* req, data_desc_enum* check_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 occurrence = 0, count = 0;
    phb_type_enum type = PHB_SNE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (((req->record_index == (kal_uint16)PHB_INVALID_VALUE) &&
        (!phb_ptr->data_desc[DATA_DESC_ADN].free_count)) ||
        ((req->record_index != (kal_uint16)PHB_INVALID_VALUE) &&
        (!phb_desc_index_check(DATA_DESC_ADN, req->record_index))))
    {
        check_array[0] = DATA_DESC_ADN;
        return -1;
    }

    while (1)
    {
        switch (type)
        {     
            case PHB_SNE:
                if (req->file_bitmap[PHB_SNE] & (1 << occurrence))
                {
                    if (phb_ptr->data_desc[DATA_DESC_SNE + occurrence].is_support)
                    {
                        if (phb_desc_is_type2_file(DATA_DESC_SNE + occurrence))
                        {
                            check_array[count++] = DATA_DESC_SNE + occurrence;
                        }
                    }
                    else
                    {
                        check_array[0] = DATA_DESC_SNE + occurrence;
                        return -1;
                    }
                }
                
                if (occurrence < phb_ptr->sne_count)
                {
                    occurrence++;
                }
                else
                {
                    type = PHB_ANR;
                    occurrence = 0;
                }
                break;                    
                
            case PHB_ANR:
                if (req->file_bitmap[PHB_ANR] & (1 << occurrence))
                {
                    if (phb_ptr->data_desc[DATA_DESC_ANR + occurrence].is_support)
                    {
                        if (phb_desc_is_type2_file(DATA_DESC_ANR + occurrence))
                        {
                            check_array[count++] = DATA_DESC_ANR + occurrence;
                        }
                    }
                    else
                    {
                        check_array[0] = DATA_DESC_ANR + occurrence;
                        return -1;
                    }
                }
                
                if (occurrence < phb_ptr->anr_count)
                {
                    occurrence++;
                }
                else
                {
                    type = PHB_EMAIL;
                    occurrence = 0;
                }
                break;
                
            default: /* case PHB_EMAIL: */
                if (req->file_bitmap[PHB_EMAIL] & (1 << occurrence))
                {
                    if (phb_ptr->data_desc[DATA_DESC_EMAIL + occurrence].is_support)
                    {
                        if (phb_desc_is_type2_file(DATA_DESC_EMAIL + occurrence))
                        {
                            check_array[count++] = DATA_DESC_EMAIL + occurrence;
                        }
                    }
                    else
                    {
                        check_array[0] = DATA_DESC_ANR + occurrence;
                        return -1;
                    }
                }
                
                if (occurrence < phb_ptr->email_count)
                {
                    occurrence++;
                }
                else
                {
                    return count;
                }
                break;
        }
    }
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  phb_write_err_handler
 * DESCRIPTION
 *  This is phb_write_err_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_check_write_usim_err_handler(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_ERR);

    phb_check_write_usim_confirm(
        PHB_ERRNO_FAIL,
        cblk->src_id,
        cblk->record_index,
        0);
}


/*****************************************************************************
 * FUNCTION
 *  phb_check_write_usim_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_check_write_usim_continue(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 pbr_rec, check_index, new_index = 0;
    data_desc_enum desc;
    kal_uint8 pbr_pos, iap_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_USIM);
    ASSERT(cblk);
    pbr_rec = phb_desc_get_pbr_rec(cblk->primary_ID, cblk->record_index);
    for (check_index = 0; check_index < PHB_MAX_TYPE2_ENTRIES; check_index++)
    {
        desc = cblk->check_array[check_index];
        pbr_pos = phb_desc_get_pbr_pos(desc);
        iap_pos = phb_ptr->phb_pbr_table[pbr_pos][pbr_rec - 1].iap_pos;
        if (!phb_desc_index_check(desc, cblk->data[iap_pos]))
        {
            cblk->check_array[new_index++] = cblk->check_array[check_index];
        }
    }
    if (new_index < PHB_MAX_TYPE2_ENTRIES)
    {
        cblk->check_array[new_index] = 0;
    }
    for (check_index = 0; check_index < PHB_MAX_TYPE2_ENTRIES; check_index++)
    {
        if (cblk->check_array[check_index])
        {
            pbr_pos = phb_desc_get_pbr_pos(cblk->check_array[check_index]);
            if (!(phb_ptr->phb_pbr_table[pbr_pos][pbr_rec - 1].free_count))
            {
                phb_check_write_usim_confirm(
                    PHB_ERRNO_FAIL,
                    cblk->src_id,
                    cblk->record_index,
                    cblk->check_array[check_index]);
                phb_free_control_block(cblk);
                return;
            }
        }
        else
        {
            break;
        }
    }
    phb_check_write_usim_confirm(
        PHB_ERRNO_SUCCESS,
        cblk->src_id,
        cblk->record_index,
        0);
    phb_free_control_block(cblk);
}


/*****************************************************************************
 * FUNCTION
 *  phb_check_write_usim_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_check_write_usim_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cphb_check_write_usim_entry_req_struct *l4cphb_check_req = 
            (l4cphb_check_write_usim_entry_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_USIM);

    if (phb_ptr->state != PHB_STATE_READY)
    {
        phb_check_write_usim_confirm(
            PHB_ERRNO_NOT_READY,
            l4cphb_check_req->src_id,
            l4cphb_check_req->record_index,
            0);
    }
    else
    {
        data_desc_enum check_array[PHB_MAX_TYPE2_ENTRIES];
        memset(check_array, 0, sizeof(data_desc_enum) * PHB_MAX_TYPE2_ENTRIES);
        
        switch (phb_verify_check_write_usim_param(l4cphb_check_req, (data_desc_enum *)&check_array))
        {
            case -1:
                phb_check_write_usim_confirm(
                    PHB_ERRNO_FAIL,
                    l4cphb_check_req->src_id,
                    l4cphb_check_req->record_index,
                    check_array[0]);
                return;

            case 0:
                if (l4cphb_check_req->record_index == (kal_uint16)PHB_INVALID_VALUE)
                {
                    l4cphb_check_req->record_index = phb_data_desc_find_next_free(DATA_DESC_ADN);
                }
                phb_check_write_usim_confirm(
                    PHB_ERRNO_SUCCESS,
                    l4cphb_check_req->src_id,
                    l4cphb_check_req->record_index,
                    0);
                return;

           default:
                break;
        }

        if (l4cphb_check_req->record_index == (kal_uint16)PHB_INVALID_VALUE) /* add op */
        {
            kal_uint16 pbr_rec, check_index;
            kal_bool continue_check;
            data_desc_enum fail_desc = 0;
            kal_uint8 pbr_pos;
            
            for (pbr_rec = 1; pbr_rec <= phb_ptr->data_desc[DATA_DESC_PBR].record_num; pbr_rec++)
            {
                pbr_pos = phb_desc_get_pbr_pos(DATA_DESC_ADN);
                if (!(phb_ptr->phb_pbr_table[pbr_pos][pbr_rec - 1].free_count))
                {
                    continue;
                }
                continue_check = KAL_TRUE;
                for (check_index = 0; continue_check && check_index < PHB_MAX_TYPE2_ENTRIES; check_index++)
                {
                    if (check_array[check_index])
                    {
                        pbr_pos = phb_desc_get_pbr_pos(check_array[check_index]);
                        if (!(phb_ptr->phb_pbr_table[pbr_pos][pbr_rec - 1].free_count))
                        {
                            continue_check = KAL_FALSE;
                            fail_desc = check_array[check_index];
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                if (continue_check)
                {
                    kal_uint16 record_index;
                    record_index = phb_data_desc_find_next_free_ext(DATA_DESC_ADN, pbr_rec);
                    if (record_index != (kal_uint16)PHB_INVALID_VALUE)
                    {
                        record_index = phb_desc_convert_pri_index(pbr_rec, record_index);

                        phb_check_write_usim_confirm(
                            PHB_ERRNO_SUCCESS,
                            l4cphb_check_req->src_id,
                            record_index,
                            0);
                    }
                    else
                    {
                        phb_check_write_usim_confirm(
                            PHB_ERRNO_FAIL,
                            l4cphb_check_req->src_id,
                            l4cphb_check_req->record_index,
                            0);
                    }
                    return;
                }
            }
            phb_check_write_usim_confirm(
                PHB_ERRNO_FAIL,
                l4cphb_check_req->src_id,
                l4cphb_check_req->record_index,
                fail_desc);
        }
        else /* update op */
        {
            kal_uint32 i;
            control_block_type *cblk = phb_alloc_control_block();
            if (cblk == NULL)
            {
                phb_check_write_usim_confirm(
                    PHB_ERRNO_BUSY,
                    l4cphb_check_req->src_id,
                    l4cphb_check_req->record_index,
                    0);
                return;
            }
            cblk->src_id = l4cphb_check_req->src_id;
            phb_control_block_set(
                cblk,
                phb_check_write_usim_continue,
                NULL,
                phb_check_write_usim_err_handler,
                0);

            /* set storage, record_index, primary_ID, and secondary_ID */
            cblk->storage = PHB_STORAGE_SIM;
            cblk->record_index = l4cphb_check_req->record_index;
            cblk->primary_ID = phb_desc_get_used_file_id(FILE_G_IAP_IDX); 
            cblk->secondary_ID = (kal_uint16) PHB_NULL_VALUE;
            for (i = 0; i < PHB_MAX_TYPE2_ENTRIES && check_array[i]; i++)
            {
                cblk->check_array[i] = check_array[i];
            }
            phb_issue_IO_read(cblk);
        }
    }
}

#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */ 


static void phb_write_notify_uicc(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    
    while (cblk->proc_stage <= PHB_WRITE_STAGE_DONE)
    {
        switch(cblk->proc_stage)
        {
            case PHB_WRITE_STAGE_CONTINUE:
            {
                phb_entry_struct *phb_entry = (phb_entry_struct*) cblk->data;

                /* Weird error occured!! */
                if (!phb_entry || phb_entry->index == (kal_uint16) PHB_INVALID_VALUE)
                {
                    cblk->result = PHB_ERRNO_FAIL;
                    phb_write_err_handler(NULL, cblk);
                    return;
                }
                cblk->temp_entry.index++;
                cblk->temp_entry.record_index = cblk->record_index;
                cblk->data = NULL;
                break;
            }

        #ifdef __PHB_USIM_SYNC__
            case PHB_WRITE_STAGE_UPDATE_UID:
            {
                if (phb_ptr->data_desc[DATA_DESC_UID].is_support && phb_data_desc_get_record_size(DATA_DESC_UID) > 0)
                {
                    kal_uint8 *ptr = NULL;
                    
                    cblk->type = PHB_NONE;
                    cblk->primary_ID = phb_desc_get_used_file_id(FILE_G_UID_IDX);
                    cblk->secondary_ID = (kal_uint16) PHB_NULL_VALUE;
                    cblk->length = phb_data_desc_get_record_size(DATA_DESC_UID);
                    cblk->data = (kal_uint8 *)get_ctrl_buffer(cblk->length);

                    if (phb_ptr->puid == 0xFFFF)
                        phb_ptr->puid = 0x0001;
                    else
                        phb_ptr->puid++;

                    ptr = (kal_uint8 *)&phb_ptr->puid;
                    
                    cblk->data[0] = ptr[1];
                    cblk->data[1] = ptr[0];
                }
                break;
            }
            case PHB_WRITE_STAGE_UPDATE_PUID:
            {
                if (phb_ptr->data_desc[DATA_DESC_PUID].is_support)
                {
                    cblk->primary_ID = phb_desc_get_used_file_id(FILE_G_PUID_IDX);
                    cblk->secondary_ID = (kal_uint16) PHB_NULL_VALUE;
                    cblk->record_index = 0;
                }
                break;
            }
            case PHB_WRITE_STAGE_UPDATE_CC:
            {
                if (phb_ptr->data_desc[DATA_DESC_CC].is_support)
                {
                    kal_uint8 *ptr = NULL;
                    
                    if (cblk->data)
                    {
                        free_ctrl_buffer(cblk->data);
                    }
                    cblk->primary_ID = phb_desc_get_used_file_id(FILE_G_CC_IDX);
                    cblk->secondary_ID = (kal_uint16) PHB_NULL_VALUE;
                    cblk->length = phb_data_desc_get_record_size(DATA_DESC_CC);
                    cblk->data = (kal_uint8 *)get_ctrl_buffer(cblk->length);

                    if (phb_ptr->cc == 0xFFFF)
                        phb_ptr->cc = 0x0001;
                    else
                        phb_ptr->cc++;

                    ptr = (kal_uint8 *)&phb_ptr->cc;

                    cblk->data[0] = ptr[1];
                    cblk->data[1] = ptr[0];
                    cblk->record_index = 0;
                }
                break;
            }
            case PHB_WRITE_STAGE_UPDATE_PSC:
            {
                if (phb_ptr->data_desc[DATA_DESC_PSC].is_support)
                {
                    if (cblk->data)
                    {
                        free_ctrl_buffer(cblk->data);
                        cblk->data = NULL;
                    }

                    if (phb_ptr->puid == 0x0001 || phb_ptr->cc == 0x0001)
                    {
                        kal_uint8 *ptr = NULL;
                        
                        cblk->primary_ID = phb_desc_get_used_file_id(FILE_G_PSC_IDX);
                        cblk->secondary_ID = (kal_uint16) PHB_NULL_VALUE;
                        cblk->length = phb_data_desc_get_record_size(DATA_DESC_PSC);
                        cblk->data = (kal_uint8 *)get_ctrl_buffer(cblk->length);

                        if (phb_ptr->psc == 0xFFFFFFFF)
                            phb_ptr->psc = 0x000000001;
                        else
                            phb_ptr->psc++;

                        
                        ptr = (kal_uint8 *)&phb_ptr->psc;

                        cblk->data[0] = ptr[3];
                        cblk->data[1] = ptr[2];
                        cblk->data[2] = ptr[1];
                        cblk->data[3] = ptr[0];
                        
                        cblk->record_index = 0;
                    }
                }
                break;

            }
        #endif /* __PHB_USIM_SYNC__ */
        
            case PHB_WRITE_STAGE_DONE:
            default:
            {
                if (cblk->data)
                {
                    free_ctrl_buffer(cblk->data);
                }

                cblk->type = PHB_PHONEBOOK;
                (*cblk->controller) (NULL, cblk);
                return;
            }
        }

        cblk->proc_stage++;

        /* something to update */
        if (cblk->data)
        {
            phb_IO_cntx* cntx;
            phb_control_block_set(
                cblk,
                phb_write_notify_uicc,
                phb_write_handler,
                phb_write_notify_uicc,
                cblk->proc_stage);
            cntx = phb_IO_create_cntx(cblk);
            cntx->control_block = cblk;
            phb_IO_sim_write(cntx);
            return;
        }
        
    }

}


/*****************************************************************************
 * FUNCTION
 *  phb_write_continue
 * DESCRIPTION
 *  This is phb_write_continue function of PHB module.
 *  
 *  Since only exactly one entry can be written at a time, this function just issues write
 *  request if it's time to begin write prepared data, or give control back to controller.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_write_continue(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_CONT);

    /* It's time to write prepared data */
    if (ilm_ptr == NULL)
    {
        if (phb_issue_IO_write(cblk) == KAL_FALSE)
        {
            /* Possibly because segemented data cannot be written */
            phb_write_confirm(PHB_ERRNO_FAIL, cblk->actual_count, cblk->src_id, cblk);
            return;
        }
    }
    /* Write confirmed. Give control back to contoller */
    else
    {
        phb_entry_struct *phb_entry = (phb_entry_struct*) cblk->data;
        phb_entry->type = cblk->type;

        /* For 1 to 1 mapping */
        if (cblk->type == PHB_MSISDN)
        {
            phb_entry->index = phb_entry->record_index = cblk->index;
            /*
            phb_data_desc_mark_free(
                phb_data_desc_get_desc_by_ID(cblk->primary_ID, cblk->storage),
                cblk->record_index,
                KAL_FALSE);
                */

        }
        /* First we have to sync the written entry into search engine */
        else if (cblk->type == PHB_FDN ||
                 cblk->type == PHB_BDN ||
                 cblk->type == PHB_PHONEBOOK)
        {
         /**
          * If this control path is reached, then one of the following
          * conditions is true:
          * 1. For `add' operation, a free record must be found and
          *   the requested entry is successfully written.
          * 2. For `update' operation, the record addressed by
          *   record_index must be occupied, and the requested
          *   entry is successfully updated.
          */

            /* This write is a add operation */
            cblk->candidate = cblk->index;

            if (cblk->index == (kal_uint16) PHB_INVALID_VALUE)
            {
                kal_uint16 total = 0, available = 0;
            #ifndef __PHB_SORT_ENABLE__
                if (cblk->type == PHB_PHONEBOOK)
                {
                    phb_entry->index = cblk->record_index;
                }
                else
            #endif /* __PHB_SORT_ENABLE__ */ 
                {
                    phb_entry->index = phb_se_append(
                                        cblk->type,
                                        cblk->record_index,
                                        cblk->seg_record_index,
                                        phb_entry);
                }
            
                /* Mark free-list as used! */
                /*
                phb_data_desc_mark_free(
                    phb_data_desc_get_desc_by_ID(cblk->primary_ID, cblk->storage),
                    cblk->record_index,
                    KAL_FALSE);
                    */
                
            /**
             * Since it's an add operation, MMI needs to be informed
             * whether this newly added entry causes storage full.
             */
                if (cblk->type == PHB_PHONEBOOK)
                {
                    l4cphb_phonebook_status_req(cblk->storage, &total, &available);
                }
                else
                {
                    l4cphb_status_req(cblk->type, &total, &available);
                }

                /* Storage full! */
                if ((total != 0) && (available == 0))
                {
                    cblk->cause = PHB_CAUSE_STORAGE_FULL;
                }
                
                if (cblk->type == PHB_PHONEBOOK)
                {
                    phb_write_notify_uicc(ilm_ptr, cblk);
                    return;
                }
            }
            /* This write is a overwrite/update operation */
            else
            {
                kal_uint8 old_ext_index = (kal_uint8) PHB_INVALID_VALUE;

                if (cblk->seg_record_index == 0)
                {
                    cblk->seg_record_index = (kal_uint8) PHB_INVALID_VALUE;
                }
            #ifndef __PHB_SORT_ENABLE__     /* seg_record_index could be Invalid for update */
                if (cblk->type == PHB_PHONEBOOK || cblk->type == PHB_ANR)
                {
                    phb_entry->index = cblk->record_index;
                }
                else
            #endif /* __PHB_SORT_ENABLE__ */ 
                {
                #ifdef __PHB_WISDOM_SUPPORT__
                    if (phb_entry->index == (kal_uint16) PHB_INVALID_VALUE)
                    {
                        phb_entry->index = cblk->index;
                    }
                #endif /* __PHB_WISDOM_SUPPORT__ */
                
                    phb_entry->index = phb_se_update(
                                        cblk->type,
                                        cblk->seg_record_index,
                                        phb_entry,
                                        --phb_entry->index,
                                        &old_ext_index);
                }
            }

            /* Weird error occured!! */
            if (phb_entry->index == (kal_uint16) PHB_INVALID_VALUE)
            {
                cblk->result = PHB_ERRNO_FAIL;
                phb_write_err_handler(NULL, cblk);
                return;
            }

            phb_entry->index++;
            phb_entry->record_index = cblk->record_index;
        #if defined(__PHB_FDN_GET_NAME__) || defined(__ECALL_SUPPORT__)
            if (cblk->type == PHB_FDN)
            {
                phb_update_fdn_context(phb_entry->record_index, &phb_entry->alpha_id, &phb_entry->tel_number);
            }
        #endif /* __PHB_FDN_GET_NAME__ */
        }

        phb_ctrl_blk_set_state(cblk, PHB_WRITE_STAGE_DONE);

        /* Then give control back to controller */
        (*cblk->controller) (NULL, cblk);
    }
}   /* end of phb_write_continue */


/*****************************************************************************
 * FUNCTION
 *  phb_write_confirm
 * DESCRIPTION
 *  This is phb_write_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  actual_count        [IN]        
 *  src_id              [IN]        
 *  cblk       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_write_confirm(
                phb_errno_enum result,
                kal_uint16 actual_count,
                kal_uint8 src_id,
                control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    local_para_struct *local_param_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    if (cblk->cnf_msg_id == MSG_ID_L4CPHB_WRITE_USIM_REQ)
    {        
        l4cphb_write_usim_cnf_struct *l4cphb_write_cnf;
        kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_CNF, result, actual_count, src_id);

        l4cphb_write_cnf = (l4cphb_write_usim_cnf_struct*) construct_local_para(sizeof(l4cphb_write_usim_cnf_struct), TD_CTRL);
        l4cphb_write_cnf->src_id = src_id;

        local_param_ptr = (local_para_struct*) l4cphb_write_cnf;

        /* If result is PHB_ERRNO_BUSY, reject newly received request */
        l4cphb_write_cnf->result = result;
        l4cphb_write_cnf->record_index = cblk->record_index;
        l4cphb_write_cnf->occurrence = cblk->occurrence;
        l4cphb_write_cnf->type = cblk->type;

        /* Confirm to in-processing operation */
        /* Field `cause' is meaningful when I/O occured by using control blocks */
        l4cphb_write_cnf->cause = cblk->cause;

        phb_free_control_block(cblk);

        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_WRITE_USIM_CNF, local_param_ptr, NULL);
    }
    else
#endif /* __PHB_USIM_SUPPORT__ */ 
    {
        l4cphb_write_cnf_struct *l4cphb_write_cnf;
    #ifdef __PHB_WISDOM_SUPPORT__
        l4cphb_phb_entry_array_struct *phb_entry_array;
        peer_buff_struct *peer_buf_ptr;
    #endif /* __PHB_WISDOM_SUPPORT__ */

        kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_CNF, result, actual_count, src_id);

        l4cphb_write_cnf = (l4cphb_write_cnf_struct*) construct_local_para(sizeof(l4cphb_write_cnf_struct), TD_CTRL);
        l4cphb_write_cnf->total = actual_count;
        l4cphb_write_cnf->src_id = src_id;

        local_param_ptr = (local_para_struct*) l4cphb_write_cnf;

        /* If result is PHB_ERRNO_BUSY, reject newly received request */
        l4cphb_write_cnf->result = result;

    #ifdef __PHB_WISDOM_SUPPORT__
        phb_entry_array = (l4cphb_phb_entry_array_struct*) l4cphb_alloc_peer_buf(&peer_buf_ptr, 1);
        phb_entry_array->array[0].type = cblk->type;
        phb_entry_array->array[0].record_index = cblk->record_index;
    #endif /* __PHB_WISDOM_SUPPORT__ */

        /* Confirm to in-processing operation */
        /* Field `cause' is meaningful when I/O occured by using control blocks */
        l4cphb_write_cnf->cause = cblk->cause;
    #ifndef __PHB_STORAGE_BY_MMI__
        l4cphb_write_cnf->old_index = cblk->candidate;
    #else
        if (!(cblk->type == PHB_FDN || cblk->type == PHB_FDN))
        {
            l4cphb_write_cnf->old_index = cblk->candidate;
        }
        else
        {
            l4cphb_write_cnf->old_index = cblk->record_index;
        }
    #endif

        phb_free_control_block(cblk);

    #ifdef __PHB_WISDOM_SUPPORT__
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_WRITE_CNF, local_param_ptr, peer_buf_ptr);
    #else /* __PHB_WISDOM_SUPPORT__ */
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_WRITE_CNF, local_param_ptr, NULL);
    #endif /* __PHB_WISDOM_SUPPORT__ */
    }
}   /* end of phb_write_confirm */


/*****************************************************************************
 * FUNCTION
 *  phb_write_confirm
 * DESCRIPTION
 *  This is phb_write_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  actual_count        [IN]        
 *  src_id              [IN]        
 *  cblk       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_write_confirm_no_cb(
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
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    if (cnf_msg_id == MSG_ID_L4CPHB_WRITE_USIM_REQ)
    {        
        l4cphb_write_usim_cnf_struct *l4cphb_write_cnf;
        kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_CNF, result, actual_count, src_id);

        l4cphb_write_cnf = (l4cphb_write_usim_cnf_struct*) construct_local_para(sizeof(l4cphb_write_usim_cnf_struct), TD_CTRL);
        l4cphb_write_cnf->src_id = src_id;

        local_param_ptr = (local_para_struct*) l4cphb_write_cnf;

        /* If result is PHB_ERRNO_BUSY, reject newly received request */
        l4cphb_write_cnf->result = result;
        l4cphb_write_cnf->record_index = record_index;
        l4cphb_write_cnf->occurrence = occurrence;
        l4cphb_write_cnf->type = type;

        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_WRITE_USIM_CNF, local_param_ptr, NULL);
    }
    else
#endif /* __PHB_USIM_SUPPORT__ */ 
    {
        l4cphb_write_cnf_struct *l4cphb_write_cnf;
    #ifdef __PHB_WISDOM_SUPPORT__
        l4cphb_phb_entry_array_struct *phb_entry_array;
        peer_buff_struct *peer_buf_ptr;
    #endif /* __PHB_WISDOM_SUPPORT__ */

        kal_trace(TRACE_FUNC, FUNC_PHB_WRITE_CNF, result, actual_count, src_id);

        l4cphb_write_cnf = (l4cphb_write_cnf_struct*) construct_local_para(sizeof(l4cphb_write_cnf_struct), TD_CTRL);
        l4cphb_write_cnf->total = actual_count;
        l4cphb_write_cnf->src_id = src_id;

        local_param_ptr = (local_para_struct*) l4cphb_write_cnf;

        /* If result is PHB_ERRNO_BUSY, reject newly received request */
        l4cphb_write_cnf->result = result;

    #ifdef __PHB_WISDOM_SUPPORT__
        phb_entry_array = (l4cphb_phb_entry_array_struct*) l4cphb_alloc_peer_buf(&peer_buf_ptr, 1);
        phb_entry_array->array[0].type = type;
        phb_entry_array->array[0].record_index = record_index;
    #endif /* __PHB_WISDOM_SUPPORT__ */

    #ifdef __PHB_WISDOM_SUPPORT__
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_WRITE_CNF, local_param_ptr, peer_buf_ptr);
    #else /* __PHB_WISDOM_SUPPORT__ */
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_WRITE_CNF, local_param_ptr, NULL);
    #endif /* __PHB_WISDOM_SUPPORT__ */
    }
}

