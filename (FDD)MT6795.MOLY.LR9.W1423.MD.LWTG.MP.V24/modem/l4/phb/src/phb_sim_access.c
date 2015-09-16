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
 * phb_sim_access.c
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
#include "sim_ps_msgid.h"

//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
//#include "stack_ltlcom.h" /* Task message communiction */
//#include "app_buff_alloc.h"     /* Declaration of buffer management API */

#include "kal_trace.h"
#include "phb_trc.h"

#include "sim_common_enums.h"
// #include "nvram_editor_data_item.h"
//#include "custom_nvram_editor_data_item.h"

//#include "l4_common.h"
#include "ps2sim_struct.h"

#include "l4c2phb_enums.h"
#include "l4c2phb_struct.h"

#include "l4_defs.h"
/* Prerequisite of phb_context.h */
#include "phb_defs.h"
#include "phb_control_block.h"
//#include "phb_config.h"
#include "phb_data_desc.h"
//#include "phb_data_entry_table.h"
//#include "phb_pindex.h"
//#include "phb_name_num_index.h"
//#include "phb_handler_startup.h"

#include "phb_context.h"

#include "phb_common.h"
#include "phb_ilm.h"
#include "phb_utils.h"
#include "phb_se.h"

//#include "phb_sim_access.h"

#include "kal_general_types.h"
#include "nvram_editor_data_item.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "ps_public_enum.h"
#include "mcd_l4_common.h"

#include "sim_ps_api.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_SIM_ACCESS_C_

/* SIM constants */
#define SIM_WRITE_OFFSET   5

/* Offset begun after alpha id, these are for write operation */
#define BCD_LEN_OFFSET     0
#define TON_NPI_OFFSET     1
#define TEL_NUMBER_OFFSET  2
#define CAP_CNF_OFFSET     12
#define SIM_EXT_ID_OFFSET  13

#define EF_EXT_TYPE_ADDITIONAL_DATA    0x02
#define EF_EXT_TYPE_SUBADDRESS         0x01

/* EFext types and constants */
typedef struct
{
    kal_uint8 record_type;
    kal_uint8 ext_data_length;
    kal_uint8 ext_data[EF_TEL_NUMBER_SIZE];
    kal_uint8 identifier;
} ef_ext_type;

#ifdef __PHB_USIM_SUPPORT__
#if defined(__GEMINI__) || defined(GEMINI_PLUS) || defined(__SGLTE__)
extern kal_bool is_usim_type(sim_interface_enum which_sim);
#else /* __GEMINI__ */
extern kal_bool is_usim_type(void);
#endif /* __GEMINI__ */
#endif /* __PHB_USIM_SUPPORT__ */

static void phb_sim_file_info_cnf(ilm_struct *ilm_ptr, control_block_type *control_block);
static kal_uint8 phb_sim_reassemble_tel_num(ef_ext_type *data_ptr, phb_entry_struct *phb_entry);

#if !defined(__PHB_NO_CALL_LOG__)
static kal_uint16 phb_sync_translate_ln_to_sim(
                    kal_uint8 *data,
                    nvram_ef_phb_ln_struct *record,
                    nvram_ef_phb_ln_struct *record1,
                    control_block_type *control_block);
#endif /* !defined(__PHB_NO_CALL_LOG__) */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_file_info
 * DESCRIPTION
 *  This function issues SIM_FILE_INFO_REQ to sim.
 * PARAMETERS
 *  control_block       [?]         
 *  info_type           [IN]        
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_sim_file_info(control_block_type *control_block, sim_info_type_enum info_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_FILE_INFO);

    ASSERT(control_block != NULL);

    if (control_block->IO_stage == IO_NONE)
    {
        sim_file_info_req_struct *sim_file_info_req;

        sim_file_info_req = (sim_file_info_req_struct*) construct_local_para(
                                                            sizeof(sim_file_info_req_struct),
                                                            TD_CTRL);
        sim_file_info_req->file_idx = control_block->primary_ID;
    #ifdef __PHB_USIM_SUPPORT__
        kal_mem_cpy(sim_file_info_req->path, control_block->path, 6);
    #endif 
        sim_file_info_req->info_type = info_type;
        sim_file_info_req->access_id = control_block->ID;

        phb_ptr->request_count++;

        control_block->IO_stage = IO_WAIT;
        control_block->IO_cnf_receive = phb_sim_file_info_cnf;
        phb_send_ilm(MOD_SIM, MSG_ID_SIM_FILE_INFO_REQ, sim_file_info_req, NULL);

        result = KAL_TRUE;
    }
    /* Abnormal, return false */
    else
    {
        result = KAL_FALSE;
    }

    return result;
}   /* end of module main function */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_file_info_cnf
 * DESCRIPTION
 *  This function issues SIM_FILE_INFO_REQ to sim.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_sim_file_info_cnf(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_file_info_cnf_struct *sim_file_info_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_FILE_INFO_CNF);

    phb_ptr->request_count--;

    //if (phb_ptr->request_count > 0) return;

    ASSERT(control_block != NULL);

    sim_file_info_cnf = (sim_file_info_cnf_struct*) ilm_ptr->local_para_ptr;

    if (sim_file_info_cnf->result == SIM_CMD_SUCCESS)
    {
        /* amanda add */
        if (sim_file_info_cnf->num_of_rec > 0)
        {
            if (sim_file_info_cnf->file_idx == FILE_FDN_IDX ||
                sim_file_info_cnf->file_idx == FILE_U_FDN_IDX)
            {
                phb_desc_set_alpha_len(DATA_DESC_FDN, (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec) - 14);
            }
            else if (sim_file_info_cnf->file_idx == FILE_BDN_IDX ||
                     sim_file_info_cnf->file_idx == FILE_U_BDN_IDX)
            {
                phb_desc_set_alpha_len(DATA_DESC_BDN, (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec) - 15);
            }
            else if (sim_file_info_cnf->file_idx == FILE_MSISDN_IDX ||
                     sim_file_info_cnf->file_idx == FILE_U_MSISDN_IDX)
            {
                phb_desc_set_alpha_len(DATA_DESC_MSISDN, (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec) - 14);
            }
        }

        if (control_block->IO_stage == IO_WAIT)
        {
            /* success */
            phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
            return;
        }
      /** 
       * Wrong state: currently it is not waiting. 
       * Abnormal, consume message.
       */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_FILE_INFO);
            return;
        }
    }
    /* error occured, call error handler */
    else
    {
        control_block->cause = sim_file_info_cnf->result;

        phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
        return;
    }
}   /* end of phb_sim_file_info_cnf */


#if !defined(__PHB_NO_CALL_LOG__)
/*****************************************************************************
 * FUNCTION
 *  phb_read_ln_from_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_read_ln_from_sim(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_read_req_struct *param_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    control_block->IO_stage = IO_WAIT;
    param_ptr = (sim_read_req_struct*) construct_local_para((kal_uint16) sizeof(sim_read_req_struct), TD_CTRL);

    param_ptr->file_idx = FILE_LND_IDX;
    param_ptr->para = control_block->index;
    param_ptr->length = control_block->length / control_block->seg_total;
    param_ptr->access_id = control_block->ID;

    phb_send_ilm(MOD_SIM, MSG_ID_SIM_READ_REQ, param_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  phb_write_ln_to_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  control_block       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void phb_write_ln_to_sim(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 length;
    sim_write_req_struct *param_ptr;
    nvram_ef_phb_ln_struct *pdu_data, *pdu_data1 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    control_block->IO_stage = IO_WAIT;

    pdu_data = (nvram_ef_phb_ln_struct*) get_peer_buff_pdu(control_block->peer_buf_ptr, &length);

    if (control_block->data != NULL)
    {
        /* second NVRAM LID */
        pdu_data1 = (nvram_ef_phb_ln_struct*) get_peer_buff_pdu((peer_buff_struct*) control_block->data, &length);
    }

    param_ptr = (sim_write_req_struct*) construct_local_para((kal_uint16) sizeof(sim_write_req_struct), TD_CTRL);

    param_ptr->file_idx = FILE_LND_IDX;
    param_ptr->para = 0;
    param_ptr->access_id = control_block->ID;
    param_ptr->length = phb_sync_translate_ln_to_sim(param_ptr->data, pdu_data, pdu_data1, control_block);

    phb_send_ilm(MOD_SIM, MSG_ID_SIM_WRITE_REQ, param_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  phb_sync_translate_ln_to_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data                [?]     
 *  record              [?]     
 *  record1             [?]     
 *  control_block       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint16 phb_sync_translate_ln_to_sim(
                    kal_uint8 *data,
                    nvram_ef_phb_ln_struct *record,
                    nvram_ef_phb_ln_struct *record1,
                    control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __VOIP__
    kal_uint8 flag;
    kal_uint16 index, back_index;
#endif /* !__VOIP__ */
    phb_ln_entry_struct *entry = NULL;

    kal_uint16 rec_size = control_block->seg_len;
    kal_uint16 alpha_size = rec_size - PHB_LENGTH_AFTER_ALPHA_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data += 5;

#ifdef __VOIP__
    if (control_block->index > PHB_MAX_LN_ENTRIES)
    {
        entry = &record1->array[control_block->index - PHB_MAX_LN_ENTRIES - 1];
        control_block->index--;
    }
    else
    {
        entry = &record->array[control_block->index - 1];
        control_block->index--;
    }
#else /* __VOIP__*/
    /* write LND to SIM should start from the oldest record, i.e the last one in NVRAM 
       LID2 if possible */

    /* flag(default): which NVRAM LID is to be written to SIM in this round */
    flag = 1;
    /* index(default): which record in the first NVRAM LID is to be written to SIM in this round */
    index = PHB_MAX_LN_ENTRIES - control_block->index - 1;

    /* LID2 if possible
       control_block->index: how many records has been written to SIM */
    if (record1 != NULL)
    {
        /* two NVRAM LIDs
           back_index: which record in total NVRAM LIDs is to be written to SIM in this round */
        /* if (control_block->seg_total <= record->no_entry + record1->no_entry) */
        back_index = control_block->seg_total - control_block->index - 1;
        //else
        //back_index = PHB_MAX_LNM_ENTRIES- control_block->index - 1;
        if (back_index >= PHB_MAX_LN_ENTRIES /* record->no_entry */ )
        {
            /* record to be written to SIM in this round is in the second NVRAM LID */
            flag = 2;
            /* index: which record in the second NVRAM LID is to be written to SIM in this round */
            index = back_index - PHB_MAX_LN_ENTRIES;
            if (index >= record1->no_entry)
            {
                /* the record in NVRAM to be written to SIM is empty */
                control_block->index++;
                kal_mem_set(data, 0xff, rec_size);
                return rec_size;
            }
            else
            {
                entry = &record1->array[index];
                control_block->index++;
            }
        }
        else
        {
            /* record to be written to SIM in this round is in the first NVRAM LID
               index: which record in the first NVRAM LID is to be written to SIM in this round */
            index = back_index;
        }

    }
#if (MAX_PHB_LN_ENTRY <= 10) || (MAX_PHB_LN_ENTRY > 20)
    else    /* only one LID */
    {
        /* back_index: which record in total NVRAM LIDs is to be written to SIM */
        back_index = control_block->seg_total - control_block->index - 1;
        if (back_index < PHB_MAX_LN_ENTRIES)
        {
            index = back_index;
        }
    }
#endif /* (MAX_PHB_LN_ENTRY <= 10) || (MAX_PHB_LN_ENTRY > 20) */

    if (flag == 1)
    {
        /* record to be written to SIM in this round is in the first NVRAM LID */
        if (index >= record->no_entry)
        {
            /* the record in NVRAM to be written to SIM is empty */
            control_block->index++;
            kal_mem_set(data, 0xff, rec_size);
            return rec_size;
        }
        else
        {
            entry = &record->array[index];
            control_block->index++;
        }
    }
#endif /* __VOIP__ */
    /* Now prepare the data content */
    if ((entry->name_length > 0) && (alpha_size > 0))
    {
        istring_type istr;

 		/* 
           istr.length should incude the head size of alpha_id in LND, 
		   alpha_id is a string in different encode fromat indeed, it may be ASCII, UCS2_80, UCS2_81, UCS2_82, 
		   the head size should be 0, 3, 4 for each one, so MMI layer can not remove the head size in
		   dataPtr->entry.alpha_id.name_length
        */

        istr.length = entry->name_length;
        istr.charset = entry->name_dcs;
        istr.data = &entry->name[0];

        /* Error occured when encoding alph-id field */
        if (istring_encode_to_sim(CODING_AUTO, (istring_type*) & istr, (kal_uint8) alpha_size, data) == 0)
        {
            return 0;
        }
    }
    else
    {
        kal_mem_set(data, 0xff, alpha_size);
    }

    data[alpha_size] = entry->addr_length;
    data[alpha_size + 1] = entry->addr_bcd[0];
    kal_mem_cpy(data + alpha_size + 2, &entry->addr_bcd[1], 10);
    data[alpha_size + 12] = 0;
    data[alpha_size + 13] = 0;

    return rec_size;
}
#endif /* !defined(__PHB_NO_CALL_LOG__) */


#ifdef __PHB_ACCESS_SIM_LN__
/*****************************************************************************
 * FUNCTION
 *  phb_sim_read_record
 * DESCRIPTION
 *  This function issues SIM_READ_REQ to sim.
 * PARAMETERS
 *  file_idx            [IN]        
 *  record_index        [IN]        
 *  length              [IN]        
 *  access_id           [IN]        
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_sim_read_record(kal_uint16 file_idx, kal_uint16 record_index, kal_uint16 length, kal_uint8 access_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_read_req_struct *sim_read_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, FUNC_PHB_SIM_READ_RECORD, file_idx, record_index);

    sim_read_req = (sim_read_req_struct*) construct_local_para(sizeof(sim_read_req_struct), TD_CTRL);
    sim_read_req->file_idx = file_idx;
    sim_read_req->para = (kal_uint8) record_index;
    sim_read_req->length = (kal_uint8) length;
    sim_read_req->access_id = (kal_uint8) access_id;

    phb_send_ilm(MOD_SIM, MSG_ID_SIM_READ_REQ, sim_read_req, NULL);
}   /* end of phb_sim_read_record */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_write_record
 * DESCRIPTION
 *  This function issues SIM_READ_REQ to sim.
 *  
 *  Prerequisite:
 *  data must not be NULL.
 * PARAMETERS
 *  file_idx            [IN]        
 *  record_index        [IN]        
 *  data                [?]         
 *  length              [IN]        
 *  access_id           [IN]        
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_sim_write_record(
                kal_uint16 file_idx,
                kal_uint16 record_index,
                kal_uint8 *data,
                kal_uint16 length,
                kal_uint8 access_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_write_req_struct *sim_write_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, PHB_TRC_SIM_WRT_REC, file_idx, record_index);

    sim_write_req = (sim_write_req_struct*) construct_local_para(sizeof(sim_write_req_struct), TD_CTRL);

    sim_write_req->file_idx = file_idx;
    sim_write_req->para = (kal_uint8) record_index;

    /* Clean data before write to SIM */
    kal_mem_set(&sim_write_req->data[0], (kal_uint8) PHB_INVALID_VALUE, SIM_MAX_DATA_LEN);

    if (data != NULL)
    {
        /* Set data */
        kal_mem_cpy(&sim_write_req->data[SIM_WRITE_OFFSET], (void const*)data, length);
    }

    sim_write_req->length = (kal_uint8) length;
    sim_write_req->access_id = access_id;

    phb_send_ilm(MOD_SIM, MSG_ID_SIM_WRITE_REQ, sim_write_req, NULL);
}/* end of phb_sim_write_record */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_prepare_ln_data_to_write
 * DESCRIPTION
 *  Prepare data stored in given phb_entry_struct to approprieate structure
 *  for raw data to write, depending on it is written to SIM or NVRAM.
 *  
 *  Prerequisite:
 *  1. phb_entry->tel_number.addr_length must be set.
 *  2. control_block->seg_total must be set.
 *  3. control_block->length must be set.
 * PARAMETERS
 *  control_block       [?]         
 *  buffer              [?]         
 *  chained_id          [IN]        
 * RETURNS
 *  Return corresponding sim_file_id of data descriptor type
 *****************************************************************************/
kal_bool phb_sim_prepare_ln_data_to_write(control_block_type *control_block, kal_uint8 *buffer, kal_uint8 chained_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phb_ef_mandatory_struct *phb_ef_mandatory = NULL;
    phb_ln_entry_struct *phb_ln_entry = (phb_ln_entry_struct*) control_block->data;

    kal_uint8 alpha_id_length = 0;
    kal_uint8 tel_number_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_PREPARE_LN_DATA_TO_WRITE);

    /* Referenced control_block shall not be NULL) */
    ASSERT(control_block != NULL);

    alpha_id_length = control_block->length - PHB_LENGTH_AFTER_ALPHA_ID;

    kal_mem_set(buffer, 0xFF, control_block->length);

    /* Now prepare the data content */
    if (phb_ln_entry->name_length > 0 && alpha_id_length > 0)
    {
        istring_type istr;
        kal_uint8 write_length;

        istr.length = phb_ln_entry->name_length;
        istr.charset = phb_ln_entry->name_dcs;
        istr.data = &phb_ln_entry->name[0];

        /* Error occured when encoding alph-id field */
        write_length = istring_encode_to_sim(CODING_AUTO, (istring_type*) & istr, alpha_id_length, buffer);

        if (phb_ln_entry->name_dcs == CHARSET_ASCII)
        {
            phb_ln_entry->name_length = write_length;
        }
    #ifdef __PHB_0x81_SUPPORT__     /* MTK 2004-04-20 Wisoln, support maximum length of 0x81 UCS2 */
        else if (phb_ln_entry->name_dcs == CHARSET_UCS2_81)
        {
            phb_ln_entry->name_length = write_length;
            phb_ln_entry->name[1] = write_length - 3;
        }
    #endif /* __PHB_0x81_SUPPORT__ */ 
        else
        {
            phb_ln_entry->name_length = write_length * 2;
        }

        phb_ln_entry->name[phb_ln_entry->name_length] = 0;
        phb_ln_entry->name[phb_ln_entry->name_length + 1] = 0;
    }
    else
    {
        
        kal_mem_set(buffer, 0xff, alpha_id_length);
    }

    phb_ef_mandatory = (phb_ef_mandatory_struct*) & buffer[alpha_id_length];

    if (phb_ln_entry->addr_length == 1) /* Empty number */
    {
        /* "+" character */
        if (phb_ln_entry->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] == 0x91)
        {
            phb_ef_mandatory->len = 1;
            phb_ef_mandatory->ton_npi = 0x91;
        }
        else
        {
            phb_ef_mandatory->len = 0xff;
            phb_ef_mandatory->ton_npi = 0xff;
        }
        kal_mem_set((kal_uint8*) phb_ef_mandatory->tel_number, 0xff, EF_TEL_NUMBER_SIZE);  /* 0x91 */
    }
    else
    {
        /* Length of telephone number is ensured to be less than EF_TEL_NUMBER_SIZE */
        phb_ef_mandatory->len = phb_ln_entry->addr_length - control_block->seg_total;
        if (phb_ef_mandatory->len > 0)
        {
            tel_number_size = phb_ef_mandatory->len - 1;
        }
        phb_ef_mandatory->ton_npi = phb_ln_entry->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET];
        kal_mem_cpy(
            &phb_ef_mandatory->tel_number[0],
            (void const*)&phb_ln_entry->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
            tel_number_size);
    }
    phb_ef_mandatory->cap_cnf_id = 0;
    phb_ef_mandatory->ext_id = chained_id;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  phb_sim_write_ln_cnf
 * DESCRIPTION
 *  This function handle SIM_WRITE_LN
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_sim_write_ln_cnf(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_write_cnf_struct *sim_write_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_WRITE_LN_CNF);

    ASSERT(control_block != NULL);

    sim_write_cnf = (sim_write_cnf_struct*) ilm_ptr->local_para_ptr;

    if (sim_write_cnf->result == SIM_CMD_SUCCESS)
    {
        /* Success */
        if (control_block->IO_stage == IO_WAIT)
        {
            control_block->IO_stage = IO_NONE;
            control_block->IO_cnf_receive = NULL;

            (*control_block->return_location) (NULL, control_block);
        }
        /* Wrong state: currently it is not waiting. Abnormal, consume message. */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_WRITE);
            return;
        }
    }
    /* error occured, call error handler */
    else
    {
        control_block->cause = sim_write_cnf->result;

        phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_sim_write_ln_first_record
 * DESCRIPTION
 *  This function prepares data content for the first part of telephone numbers then
 *  invokes sim_write_record() to write a record.
 *  
 *  Prerequisites:
 *  control_block->phb_entry must not be NULL.
 *  primary_ID and its data_desc_type must no be PHB_INVALID_VALUE
 *  control_block->data and length must be setup.
 * PARAMETERS
 *  control_block       [?]         
 *  chained_id          [IN]        
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_sim_write_ln_first_record(
            control_block_type *control_block,
            /* data_desc_enum type, */ kal_uint8 chained_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *ef_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_WRITE_LN_FIRST_RECORD);

    ASSERT(control_block != NULL);

    control_block->IO_stage = IO_WAIT;
    control_block->IO_cnf_receive = phb_sim_write_ln_cnf;

    ef_buffer = (kal_uint8*) get_ctrl_buffer(control_block->length);

    if (phb_sim_prepare_ln_data_to_write(control_block, ef_buffer, chained_id) == KAL_FALSE)
    {
        return KAL_FALSE;
    }

    /* Perparation of data content complete! */
    phb_sim_write_record(
        control_block->primary_ID,
        control_block->record_index,
        ef_buffer,
        control_block->length,
        control_block->ID);

    if (ef_buffer != NULL)
    {
        free_ctrl_buffer(ef_buffer);
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  phb_sim_write_ln
 * DESCRIPTION
 *  This function issues SIM_WRITE_REQ to sim.
 *  
 *  Prerequisite:
 *  control_block must be constructed, phb_control_block_set_IO(), and phb_se_set_control_block().
 *  So that primary_ID, secondary_ID, index and record_index are all set.
 *  
 *  Assumption:
 *  control_block->type, control_block->primary_ID is assumed to be valid.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_sim_write_ln(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_WRITE_LN);

    ASSERT(control_block != NULL);

    if (control_block->IO_stage == IO_NONE)
    {
        phb_ln_entry_struct *phb_ln_entry;

        /* Nothing to write? error! */
        if ((phb_ln_entry = (phb_ln_entry_struct*) control_block->data) == NULL)
        {
            return KAL_FALSE;
        }
        /* Segmentation is not supported on EF lnd */
        /* control_block->type, control_block->primary_ID is assumed to be valid. */
        else
        {
            control_block->seg_total = 0;
        
            if ((phb_ln_entry->addr_length - TON_NPI_SIZE) <= EF_TEL_NUMBER_SIZE)
            {
                /* will write empty content to ext1 */
                control_block->seg_len = 0;
            }
            else if ((control_block->seg_len = (phb_ln_entry->addr_length - TON_NPI_SIZE) % EF_TEL_NUMBER_SIZE) == 0)
            {
                control_block->seg_len = EF_TEL_NUMBER_SIZE;
            }
            control_block->seg_total += control_block->seg_len;

            result = phb_sim_write_ln_first_record(control_block, /* type, */ (kal_uint8) PHB_INVALID_VALUE);
        }
    }
    /* Error */
    else
    {
        result = KAL_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  phb_sim_read_ln_cnf
 * DESCRIPTION
 *  This function issues SIM_FILE_INFO_REQ to sim.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_sim_read_ln_cnf(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_read_cnf_struct *sim_read_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_READ_LN_CNF);

    ASSERT(control_block != NULL);

    sim_read_cnf = (sim_read_cnf_struct*) ilm_ptr->local_para_ptr;

    if (sim_read_cnf->result == SIM_CMD_SUCCESS)
    {
        /* success */
        if (control_block->IO_stage == IO_WAIT)
        {
            kal_uint8 *pdu_ptr;
            kal_uint16 pdu_length;
            phb_ef_struct phb_ef;
            phb_ln_entry_struct *phb_ln_entry;
            kal_uint8 alpha_id_length;
            ln_data_desc_enum desc_type = 0;

            if (control_block->primary_ID == FILE_LND_IDX)
            {
                desc_type = LN_DATA_DESC_LND;
            }

            ASSERT(control_block->primary_ID == FILE_LND_IDX);
            alpha_id_length = phb_ptr->ln_data_desc[desc_type].record_size -PHB_LENGTH_AFTER_ALPHA_ID;

            pdu_ptr = sim_read_cnf->data;
            pdu_length = sim_read_cnf->length;

            phb_ln_entry = control_block->temp_ln_entry;

            phb_ef.alpha_id = (kal_uint8*) pdu_ptr;
            phb_ef.mandatory = (phb_ef_mandatory_struct*) ((kal_uint8*) pdu_ptr + alpha_id_length);

            /* Clean area for storing data read from stroage. */
            kal_mem_set(phb_ln_entry, (kal_uint8) PHB_INVALID_VALUE, sizeof(phb_ln_entry_struct));

            phb_ln_entry->addr_type = PHB_LN_CALL; // as no address type info in SIM card, set it to default value.

            if (!is_empty(pdu_ptr, pdu_length))
            {
                istring_type istring;

                /* Set up phb_entry->alpha_id */
                istring.length = phb_ln_entry->name_length = L4_MAX_NAME;
                istring.data = (kal_uint8*) phb_ln_entry->name;
                phb_ln_entry->name_length = istring_decode_from_sim(alpha_id_length, phb_ef.alpha_id, &istring);

                if (phb_ln_entry->name_length == 0)
                {
                    istring.charset = PHB_ASCII;
                }
                phb_ln_entry->name_dcs = istring.charset;

                /**
                 *  No matter ASCII or UCS2 string, always makes last two byte 0
                 *  Because MMI maximum length is L4_MAX_NAME, 
                 *  and need two bytes null terminator at the end
                 */
                if (phb_ln_entry->name_length >= (L4_MAX_NAME - 2))
                {
                    phb_ln_entry->name_length = (L4_MAX_NAME - 2);
                    phb_ln_entry->name[L4_MAX_NAME - 1] = 0;
                    phb_ln_entry->name[L4_MAX_NAME - 2] = 0;
                }

                /* Set up phb_entry->tel_number */
                if (phb_ef.mandatory->len > 0 && phb_ef.mandatory->len != 0xff && phb_ef.mandatory->len <= (EF_TEL_NUMBER_SIZE + 1) && !(phb_ef.mandatory->len == 1 && phb_ef.mandatory->ton_npi != 0x91 && phb_ef.mandatory->tel_number[L4_ADDR_BCD_TON_NPI_OFFSET] != 0xff))  /* only accept + if length 1 */
                {
                    phb_ln_entry->addr_length = phb_ef.mandatory->len;
                    phb_ln_entry->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] = phb_ef.mandatory->ton_npi;
                    kal_mem_cpy(
                        &phb_ln_entry->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                        (void const*)&phb_ef.mandatory->tel_number,
                        /* TON_NPI_SIZE + */ phb_ef.mandatory->len - L4_ADDR_BCD_TEL_NUM_OFFSET);

                    phb_ln_entry->addr_bcd[phb_ef.mandatory->len] = 0xff;
                }
                else
                {
                    phb_ln_entry->addr_length = 0;

                    phb_ln_entry->addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] = 0xff;
                    phb_ln_entry->addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET] = 0xff;
                }

                /* Empty Record!!  - If Name and Number field are both empty, regard it as an empty record!! */
                if ((phb_ln_entry->name_length == 0) && (phb_ln_entry->addr_length == 0))
                {
                #if defined(__L4_MAX_NAME_60__)
                    kal_mem_set(&phb_ln_entry->name, 0, 62);
                #else
                    kal_mem_set(&phb_ln_entry->name, 0, 32);
                #endif
                  // should return error response to MMI 
                  //  phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                  //  return;
                }
            }
            /* Empty record!! */
            else
            {
                phb_ln_entry->name_length = 0;
                phb_ln_entry->name_dcs = 0;
            #if defined(__L4_MAX_NAME_60__)
                kal_mem_set(&phb_ln_entry->name, 0, 62);
            #else
                kal_mem_set(&phb_ln_entry->name, 0, 32);
            #endif
                phb_ln_entry->addr_length = 0;
            }

            /* read complete */
            (*control_block->return_location) (NULL, control_block);

            return;
        }

        /** 
          * Wrong state: currently it is not waiting. 
          * Abnormal, consume message.
          */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_READ);
            return;
        }
    }
    /* error occured, call error handler */
    else
    {
        control_block->cause = sim_read_cnf->result;
        control_block->IO_stage = IO_NONE;
        phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_sim_read_ln
 * DESCRIPTION
 *  This function issues SIM_READ_REQ to sim.
 *  Read SIM from control_block specified primary_ID, record_index, and length
 *  
 *  Prerequisite:
 *  pimary_ID, secondary_ID, record_index and length.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_sim_read_ln(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_READ_LN);

    ASSERT(control_block != NULL);

    if (control_block->IO_stage == IO_NONE)
    {
        control_block->IO_stage = IO_WAIT;
        control_block->IO_cnf_receive = phb_sim_read_ln_cnf;
        phb_sim_read_record(
            control_block->primary_ID,
            control_block->record_index,
            control_block->length,
            control_block->ID);
        result = KAL_TRUE;
    }
    /* Abnormal, return false */
    else
    {
        result = KAL_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  phb_sim_delete_cnf
 * DESCRIPTION
 *  This function issues SIM_FILE_INFO_REQ to sim.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_sim_delete_ln_cnf(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_write_cnf_struct *sim_write_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(control_block != NULL);

    sim_write_cnf = (sim_write_cnf_struct*) ilm_ptr->local_para_ptr;

    PHB_TRACE((MOD_PHB, "phb_sim_delete_cnf: IO_stage = %d, secondary_ID = %d", control_block->IO_stage, control_block->secondary_ID),
              (TRACE_GROUP_1, PHB_TRC_SIM_DEL_CNF, control_block->IO_stage, control_block->secondary_ID)); 

    if (sim_write_cnf->result == SIM_CMD_SUCCESS)
    {
        if (control_block->IO_stage == IO_WAIT)
        {
            /* success */
            phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
            return;
        }
      /** 
       * Wrong state: currently it is not waiting. 
       * Abnormal, consume message.
       */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_DELETE);
            return;
        }
    }
    /* error occured, call error handler */
    else
    {
        control_block->cause = sim_write_cnf->result;

        phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_sim_delete
 * DESCRIPTION
 *  This function issues SIM_WRITE_REQ to sim.
 *  
 *  Prerequisite:
 *  control_block must be constructed, phb_control_block_set_IO(), and phb_se_set_control_block().
 *  So that primary_ID, secondary_ID, index and record_index are all set.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_sim_delete_ln(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_DELETE);

    ASSERT(control_block != NULL);

    if (control_block->IO_stage == IO_NONE)
    {
        control_block->IO_cnf_receive = phb_sim_delete_ln_cnf;

        control_block->IO_stage = IO_WAIT;
        phb_sim_write_record(
            control_block->primary_ID,
            control_block->record_index,
            NULL,
            control_block->length,
            control_block->ID);
        result = KAL_TRUE;
    }
    /* Abnormal, return false */
    else
    {
        result = KAL_FALSE;
    }

    return result;
}
#endif /* __PHB_ACCESS_SIM_LN__ */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_reassemble_tel_num
 * DESCRIPTION
 *  This function reassembles data read from SIM.
 * PARAMETERS
 *  data_ptr            [IN]        Must be a EFext structure in SIM!!
 *  control_block       [?]         
 * RETURNS
 *  identifier of chained extension record.
 *****************************************************************************/
static kal_uint8 phb_sim_reassemble_tel_num(ef_ext_type *data_ptr, phb_entry_struct *phb_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 len;
    kal_uint8 sim_ext_record_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_REASSEMBLE_TEL_NUM);

    ASSERT(phb_entry != NULL);
    phb_entry->storage = phb_which_sim_storage();

    if ((phb_entry->tel_number.addr_length + data_ptr->ext_data_length) > L4_MAX_ADDR_BCD)
    {
        len = L4_MAX_ADDR_BCD - phb_entry->tel_number.addr_length;
        sim_ext_record_index = (kal_uint8) PHB_INVALID_VALUE;   /* truncate!! */
    }
    else
    {
        len = data_ptr->ext_data_length;
        sim_ext_record_index = data_ptr->identifier;
    }
    kal_mem_cpy(
        &phb_entry->tel_number.addr_bcd[phb_entry->tel_number.addr_length],
        (void const*)data_ptr->ext_data,
        len);
    phb_entry->tel_number.addr_length += len;

    return sim_ext_record_index;
}   /* end of phb_sim_reassemble */


/*****************************************************************************
 * FUNCTION
 *  phb_sim_read_cnf
 * DESCRIPTION
 *  This function issues SIM_FILE_INFO_REQ to sim.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool phb_IO_index_check(kal_uint16 file_idx, kal_uint8 occurrence, kal_uint16 record_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_desc_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_8, FUNC_PHB_SIM_IO_CHECK, file_idx, occurrence, record_index);

    switch (file_idx)
    {
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        case FILE_G_IAP_IDX:
        case FILE_U_IAP_IDX:
            type = DATA_DESC_ADN;
            break;
    
        case FILE_G_GRP_IDX:
        case FILE_U_GRP_IDX:
            type = DATA_DESC_ADN;
            break;
    
        case FILE_G_ANR_IDX:
        case FILE_U_ANR_IDX:
            if (occurrence == 0 ||
                occurrence > phb_ptr->anr_count)
            {
                return KAL_FALSE;
            }
            type = DATA_DESC_ADN;
            break;
    
        case FILE_G_SNE_IDX:
        case FILE_U_SNE_IDX:
            if (occurrence == 0 ||
                occurrence > phb_ptr->sne_count)
            {
                return KAL_FALSE;
            }
            type = DATA_DESC_ADN;
            break;
    
        case FILE_G_EMAIL_IDX:
        case FILE_U_EMAIL_IDX:
            if (occurrence == 0 ||
                occurrence > phb_ptr->email_count)
            {
                return KAL_FALSE;
            }
            type = DATA_DESC_ADN;
            break;
    #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */ 

        default:
            type = phb_data_desc_file_id_to_desc(file_idx, occurrence);
            break;

    }
    if (record_index <= phb_data_desc_get_record_num(type))
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  phb_sim_read_cnf
 * DESCRIPTION
 *  This function issues SIM_FILE_INFO_REQ to sim.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool phb_parse_sim_data(
                    kal_uint16 file_id,
                    kal_uint8 occurrence,
                    sim_read_cnf_struct *sim_read_cnf,
                    kal_uint8** out_data_p,
                    kal_uint8* seg_index,
                    kal_uint16 sort_index,
                    kal_uint16 record_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8* out_data = *out_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *seg_index = PHB_INVALID_VALUE;
    
    switch(file_id)
    {
    #ifdef __PHB_USIM_SUPPORT__
        /* Reading ECC or PBR. Return to return_location for reading pbr */
        case FILE_U_ECC_IDX:
        case FILE_G_PBR_IDX:
        case FILE_U_PBR_IDX:
    #ifdef __PHB_USIM_SYNC__
        case FILE_G_CC_IDX:
        case FILE_U_CC_IDX:
        case FILE_G_PUID_IDX:
        case FILE_U_PUID_IDX:
        case FILE_G_PSC_IDX:
        case FILE_U_PSC_IDX:
    #endif
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        case FILE_G_IAP_IDX:
        case FILE_U_IAP_IDX:
    #endif
    #endif /* __PHB_USIM_SUPPORT__ */ 
        case FILE_ECC_IDX:
        {
            *out_data_p = (kal_uint8*) sim_read_cnf->data;
            break;
        }
        
    #ifdef __PHB_USIM_SYNC__
        case FILE_G_PBC_IDX:
        case FILE_U_PBC_IDX:
        {
            kal_mem_set(out_data, 0xFF, sim_read_cnf->length);
            kal_mem_cpy(out_data, (void const*)sim_read_cnf->data, sim_read_cnf->length);
            break;
        }
    #endif /* __PHB_USIM_SYNC__ */

        case FILE_EXT1_IDX:
        case FILE_G_EXT1_IDX:
        case FILE_U_EXT1_IDX:
        case FILE_EXT2_IDX:
        case FILE_U_EXT2_IDX:
        case FILE_EXT3_IDX:
        case FILE_EXT4_IDX:
        case FILE_U_EXT5_IDX:
        {
            kal_uint16 len;
            ef_ext_type *ef_ext;

            ef_ext = (ef_ext_type*) sim_read_cnf->data;
            if ((len = sim_read_cnf->length) > sizeof(ef_ext_type))
            {
                len = sizeof(ef_ext_type);
            }

            if (ef_ext->ext_data_length && ef_ext->ext_data_length != 0xFF && ef_ext->ext_data[0] != 0xFF)
            {
                *out_data_p = (kal_uint8*) ef_ext;
            }
            else
            {
                *out_data_p = NULL;
                return KAL_FALSE;
            }
            break;
        }
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        case FILE_G_ANR_IDX:
        case FILE_U_ANR_IDX:
        {
            kal_uint8 anr_alpha_id_length = 1;
            kal_uint8 *pdu_ptr;
            kal_uint16 pdu_length;

            phb_ef_struct phb_ef;
            phb_entry_struct *phb_entry;

            pdu_ptr = sim_read_cnf->data;
            pdu_length = sim_read_cnf->length;

            phb_entry = (phb_entry_struct*) out_data;

            /* phb_ef.alpha_id = (kal_uint8*)pdu_ptr; */
            phb_ef.mandatory = (phb_ef_mandatory_struct*) ((kal_uint8*) pdu_ptr + anr_alpha_id_length);

            /* Clean area for storing data read from stroage. */
            kal_mem_set(phb_entry, (kal_uint8) PHB_INVALID_VALUE, sizeof(phb_entry_struct));
            phb_entry->aas_id = sim_read_cnf->data[0];
            phb_entry->num_index = occurrence;

            phb_entry->storage = phb_which_sim_storage();
            phb_entry->index = sort_index;
            phb_entry->record_index = record_index;
            phb_entry->type = PHB_ANR;
            
            kal_mem_set(&phb_entry->alpha_id, 0, sizeof(l4_name_struct));
            if (!is_empty(pdu_ptr, pdu_length))
            {
                /* Set up phb_entry->tel_number */
                if (phb_ef.mandatory->len > 0 &&
                    phb_ef.mandatory->len != 0xff &&
                    phb_ef.mandatory->len <= (EF_TEL_NUMBER_SIZE + 1) &&
                    !(phb_ef.mandatory->len == 1 && phb_ef.mandatory->ton_npi != 0x91) &&
                    (phb_ef.mandatory->tel_number[L4_ADDR_BCD_TON_NPI_OFFSET] != 0xff))  /* only accept + if length 1 */
                {
                    phb_entry->tel_number.addr_length = phb_ef.mandatory->len;
                    phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] = phb_ef.mandatory->ton_npi;
                    kal_mem_cpy(
                        &phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                        (void const*)&phb_ef.mandatory->tel_number,
                        /* TON_NPI_SIZE + */ phb_ef.mandatory->len - L4_ADDR_BCD_TEL_NUM_OFFSET);

                    phb_entry->tel_number.addr_bcd[phb_ef.mandatory->len] = 0xff;
                }
                else
                {
                    kal_mem_set(&phb_entry->tel_number, 0, sizeof(l4_addr_bcd_struct));
                    phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET] = 0xff;
                }

                /* Empty Record!! - If Number field is empty, regard it as an empty record!! */
                if (phb_entry->tel_number.addr_length == 0)
                {
                    kal_mem_set(&phb_entry->alpha_id, 0, sizeof(l4_name_struct));
                    return KAL_FALSE;
                }

                if ((phb_entry->tel_number.addr_length < L4_MAX_ADDR_BCD) &&
                    /* Only when address length is equal to PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN should need reassembly */
                    (phb_ef.mandatory->len == PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN))
                {
                    *seg_index = phb_ef.mandatory->ext_id;
                }
            }

            /* Empty record!! */
            else
            {
                phb_entry->tel_number.addr_length = 0;
                /* control_block->data cannot be NULL for 1 to 1 mapping */
                return KAL_FALSE;
            }
            break;
        }
        case FILE_G_EMAIL_IDX:
        case FILE_U_EMAIL_IDX:
        {
            kal_uint8 *pdu_ptr;
            kal_uint16 pdu_length;
            kal_uint8 email_length = (kal_uint8)phb_data_desc_get_record_size(phb_data_desc_file_id_to_desc(FILE_G_EMAIL_IDX, 1));
            phb_email_struct *email_entry;

            pdu_ptr     = sim_read_cnf->data;
            pdu_length  = sim_read_cnf->length;
            email_entry = (phb_email_struct*) out_data;

            /* Clean area for storing data read from stroage. */
            kal_mem_set(email_entry, (kal_uint8) PHB_INVALID_VALUE, sizeof(phb_email_struct));
            email_entry->adn_record_index = record_index;
            email_entry->record_index     = record_index;

            if (*pdu_ptr != 0xFF)
            {
                istring_type istring;

                if (phb_desc_get_file_type(phb_data_desc_file_id_to_desc(file_id, occurrence)) == 2)
                {
                    email_length -= 2;  // Due to ADN's SFI (X+1 byte) and ADN's Record ID(X+2 byte)
                }
                
                /* Set up email_entry->email_address */
                istring.length = PHB_EMAIL_MAX_LEN;
                istring.data   = (kal_uint8*) email_entry->email_address;
                
                email_entry->email_length = istring_decode_from_sim(email_length, pdu_ptr, &istring);

                /* need null terminator at the end */
                if (email_entry->email_length > PHB_EMAIL_MAX_LEN)
                {
                    email_entry->email_length                     = PHB_EMAIL_MAX_LEN;
                    email_entry->email_address[PHB_EMAIL_MAX_LEN] = 0;
                }
                if (phb_desc_get_file_type(phb_data_desc_file_id_to_desc(file_id, occurrence)) == 2)
                {
                    email_entry->adn_record_index = pdu_ptr[pdu_length - 1];
                }
            }
            else    /* Empty record!! */
            {
                kal_mem_set(email_entry, 0, sizeof(phb_email_struct));
                return KAL_FALSE;
            }
            break;
        }
        case FILE_G_GRP_IDX:
        case FILE_U_GRP_IDX:
        {
            kal_mem_cpy(out_data, (void const*)&(sim_read_cnf->data), PHB_MAX_ASSOCIATE_GRP);
            break;
        }
        case FILE_G_AAS_IDX:
        case FILE_U_AAS_IDX:
        case FILE_G_GAS_IDX:
        case FILE_U_GAS_IDX:
        case FILE_G_SNE_IDX:
        case FILE_U_SNE_IDX:
        {
            kal_uint8 alpha_id_length;

            l4_name_struct* phb_alpha_field;

            phb_alpha_field = (l4_name_struct*) out_data;

            alpha_id_length = (kal_uint8)phb_data_desc_get_record_size(phb_data_desc_file_id_to_desc(file_id, 1));
            
            if (!is_empty(sim_read_cnf->data, sim_read_cnf->length))
            {
                istring_type istring;

                /* Set up phb_entry->alpha_id */
                istring.length = phb_alpha_field->name_length = MAX_PS_NAME_SIZE ;
                istring.data = (kal_uint8*) phb_alpha_field->name;
                phb_alpha_field->name_length = istring_decode_from_sim(alpha_id_length, sim_read_cnf->data, &istring);

                if (phb_alpha_field->name_length == 0)
                {
                    istring.charset = PHB_ASCII;
                }
                phb_alpha_field->name_dcs = istring.charset;

                if (phb_alpha_field->name_length >= (MAX_PS_NAME_SIZE  - 2))
                {
                    phb_alpha_field->name_length = (MAX_PS_NAME_SIZE  - 2);
                    phb_alpha_field->name[MAX_PS_NAME_SIZE  - 1] = 0;
                    phb_alpha_field->name[MAX_PS_NAME_SIZE  - 2] = 0;
                }
                /* Empty Record!!  - If Name and Number field are both empty, regard it as an empty record!! */
                if (phb_alpha_field->name_length == 0)
                {
                    kal_mem_set(phb_alpha_field, 0, sizeof(l4_name_struct));
                    return KAL_FALSE;
                }
            }
			else
			{
			    kal_mem_set(phb_alpha_field, 0, sizeof(l4_name_struct));
                return KAL_FALSE;
			}

            break;
        }
    #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
    
        /* ADN-like structures */
        default:
        {
            kal_uint8 *pdu_ptr;
            kal_uint16 pdu_length;
            phb_ef_struct phb_ef;
            phb_entry_struct *phb_entry;
            kal_uint8 alpha_id_length;
            alpha_id_length = 
                phb_data_desc_get_record_size(phb_data_desc_file_id_to_desc(file_id, 1)) - PHB_LENGTH_AFTER_ALPHA_ID;

            /* Note that BDN is total 15 bytes after ALPHA_ID field */
            if (file_id == FILE_BDN_IDX ||
                file_id == FILE_U_BDN_IDX)
            {
                alpha_id_length--;
            }

            pdu_ptr = sim_read_cnf->data;
            pdu_length = sim_read_cnf->length;

            phb_entry = (phb_entry_struct*) out_data;

            phb_ef.alpha_id = (kal_uint8*) pdu_ptr;
            phb_ef.mandatory = (phb_ef_mandatory_struct*) ((kal_uint8*) pdu_ptr + alpha_id_length);

            /* Clean area for storing data read from stroage. */
            kal_mem_set(phb_entry, (kal_uint8) PHB_INVALID_VALUE, sizeof(phb_entry_struct));
            phb_entry->index = sort_index;
            phb_entry->record_index = record_index;
            phb_entry->storage = phb_which_sim_storage();
            
            /* amanda add */
            if (file_id == FILE_FDN_IDX ||
                file_id == FILE_U_FDN_IDX)
            {
                phb_entry->type = PHB_FDN;
            }
            else if (file_id == FILE_BDN_IDX ||
                     file_id == FILE_U_BDN_IDX)
            {
                phb_entry->type = PHB_BDN;
            }
            else if (file_id == FILE_ADN_IDX ||
                     file_id == FILE_G_ADN_IDX ||
                     file_id == FILE_U_ADN_IDX)
            {
                phb_entry->type = PHB_PHONEBOOK;
            }
            else
            {
                phb_entry->type = PHB_NONE;
            }
        
            if (!is_empty(pdu_ptr, pdu_length)      /* && 
                                                       (phb_ef.mandatory->len <= PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN) */ )
            {
                istring_type istring;

                /* Set up phb_entry->alpha_id */
                istring.length = phb_entry->alpha_id.name_length = MAX_PS_NAME_SIZE ;
                istring.data = (kal_uint8*) phb_entry->alpha_id.name;
                phb_entry->alpha_id.name_length = istring_decode_from_sim(alpha_id_length, phb_ef.alpha_id, &istring);

                if (phb_entry->alpha_id.name_length == 0)
                {
                    istring.charset = PHB_ASCII;
                }
                phb_entry->alpha_id.name_dcs = istring.charset;

           /**
           *  No matter ASCII or UCS2 string, always makes last two byte 0
           *  Because MMI maximum length is MAX_PS_NAME_SIZE , 
           *  and need two bytes null terminator at the end
           */
                if (phb_entry->alpha_id.name_length >= (MAX_PS_NAME_SIZE  - 2))
                {
                    phb_entry->alpha_id.name_length = (MAX_PS_NAME_SIZE  - 2);
                    phb_entry->alpha_id.name[MAX_PS_NAME_SIZE  - 1] = 0;
                    phb_entry->alpha_id.name[MAX_PS_NAME_SIZE  - 2] = 0;
                }

           /** 
            * If returned decoded length of alpha id is 0, 
            * it is either stored alpha id is empty, 
            * or alpha id encoding is erroneous 
            */

                /* Set up phb_entry->tel_number */
                if (phb_ef.mandatory->len > 0 && 
                    phb_ef.mandatory->len != 0xff && 
                    phb_ef.mandatory->len <= (EF_TEL_NUMBER_SIZE + 1) && 
                    !(phb_ef.mandatory->len == 1 && phb_ef.mandatory->ton_npi != 0x91 && phb_ef.mandatory->tel_number[L4_ADDR_BCD_TON_NPI_OFFSET] != 0xff))  /* only accept + if length 1 */
                {
                    phb_entry->tel_number.addr_length = phb_ef.mandatory->len;
                    phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] = phb_ef.mandatory->ton_npi;
                    kal_mem_cpy(
                        &phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                        (void const*)&phb_ef.mandatory->tel_number,
                        /* TON_NPI_SIZE + */ phb_ef.mandatory->len - L4_ADDR_BCD_TEL_NUM_OFFSET);

                    phb_entry->tel_number.addr_bcd[phb_ef.mandatory->len] = 0xff;
                }
                else
                {
                    kal_mem_set(&phb_entry->tel_number, 0, sizeof(l4_addr_bcd_struct));
                    phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET] = 0xff;
                }
                
            
                /* Empty Record!!  - If Name and Number field are both empty, regard it as an empty record!! */
                if ((phb_entry->alpha_id.name_length == 0) && (phb_entry->tel_number.addr_length == 0))
                {
                    kal_mem_set(&phb_entry->alpha_id, 0, sizeof(l4_name_struct));
                    return KAL_FALSE;
                }
           
            
                /* Set up phb_entry->cap_cnf_id */
                phb_entry->cap_cnf_id = phb_ef.mandatory->cap_cnf_id;
                if ((phb_entry->tel_number.addr_length < L4_MAX_ADDR_BCD) &&
                    /* Only when address length is equal to PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN should need reassembly */
                    (phb_ef.mandatory->len == PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN))
                {
                    *seg_index = phb_ef.mandatory->ext_id;
                }
            }

            /* Empty record!! */
            else
            {
                kal_mem_set(&phb_entry->alpha_id, 0, sizeof(l4_name_struct));
                phb_entry->tel_number.addr_length = 0;
                return KAL_FALSE;
            }
        }
    }
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  phb_sim_read_record
 * DESCRIPTION
 *  This function issues SIM_READ_REQ to sim.
 * PARAMETERS
 *  file_idx            [IN]        
 *  record_index        [IN]        
 *  length              [IN]        
 *  access_id           [IN]        
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_IO_sim_read_record(
                kal_uint16 file_idx,
                kal_uint16 record_index,
                kal_uint8 occurrence,
                kal_uint16 pbr_rec,
                kal_uint8 access_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_read_req_struct *sim_read_req;
    data_desc_enum type = phb_data_desc_file_id_to_desc(file_idx, occurrence);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, FUNC_PHB_SIM_READ_RECORD, file_idx, record_index);

    phb_ptr->request_count++;

    sim_read_req = (sim_read_req_struct*) construct_local_para(sizeof(sim_read_req_struct), TD_CTRL); 

    sim_read_req->file_idx = file_idx;
    sim_read_req->para = (kal_uint8) record_index;
    if (record_index)
    {
        sim_read_req->length = (kal_uint8) phb_data_desc_get_record_size(type);
    }
    else
    {
        sim_read_req->length = (kal_uint8)(phb_data_desc_get_record_size(type) * phb_data_desc_get_record_num(type));
    }
    sim_read_req->access_id = (kal_uint8) access_id;
#ifdef __PHB_USIM_SUPPORT__
    kal_mem_set(sim_read_req->path, 0x00, 6);
    phb_desc_get_file_path(file_idx, occurrence, pbr_rec, sim_read_req->path);
    if (!sim_read_req->path[0] && sim_read_req->length == 0)
    {
        sim_get_full_path(FILE_G_PHONEBOOK_IDX, sim_read_req->path);
//        kal_mem_cpy(sim_read_req->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
    }
#endif

    phb_send_ilm(MOD_SIM, MSG_ID_SIM_READ_REQ, sim_read_req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  phb_IO_sim_write_record
 * DESCRIPTION
 *  This function issues SIM_READ_REQ to sim.
 *  
 *  Prerequisite:
 *  data must not be NULL.
 * PARAMETERS
 *  file_idx            [IN]        
 *  record_index        [IN]        
 *  data                [?]         
 *  length              [IN]        
 *  access_id           [IN]        
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_IO_sim_write_record(
                kal_uint16 file_idx,
                kal_uint16 record_index,
                kal_uint8 occurrence,
                kal_uint16 pbr_rec,
                kal_uint8 *data,
                kal_uint8 access_id,
                kal_bool is_segmented)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_write_req_struct *sim_write_req;
    data_desc_enum type = phb_data_desc_file_id_to_desc(file_idx, occurrence);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, PHB_TRC_SIM_WRT_REC, file_idx, record_index);

    sim_write_req = (sim_write_req_struct*) construct_local_para(sizeof(sim_write_req_struct), TD_CTRL);
    sim_write_req->file_idx = file_idx;
    sim_write_req->para = (kal_uint8) record_index;
    sim_write_req->length = (kal_uint8) phb_data_desc_get_record_size(type);

    /* Clean data before write to SIM */
    kal_mem_set(&sim_write_req->data[0], (kal_uint8) PHB_INVALID_VALUE, SIM_MAX_DATA_LEN);
    if (is_segmented)
    {
        sim_write_req->data[5] = 0;
    }

    if (data != NULL)
    {
        /* Set data */
        kal_mem_cpy(&sim_write_req->data[SIM_WRITE_OFFSET], (void const*)data, sim_write_req->length);
    }
#ifdef __PHB_USIM_SUPPORT__
    kal_mem_set(sim_write_req->path, 0x00, 6);
    phb_desc_get_file_path(file_idx, occurrence, pbr_rec, sim_write_req->path);
    if (!sim_write_req->path[0] && sim_write_req->length == 0)
    {
        sim_get_full_path(FILE_G_PHONEBOOK_IDX, sim_write_req->path);
        //kal_mem_cpy(sim_write_req->path, usim_ef_info[FILE_G_PHONEBOOK_IDX].full_path, 4);
    }
#endif
    sim_write_req->access_id = access_id;

    phb_send_ilm(MOD_SIM, MSG_ID_SIM_WRITE_REQ, sim_write_req, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  phb_sim_read_cnf
 * DESCRIPTION
 *  This function issues SIM_FILE_INFO_REQ to sim.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_IO_sim_read_cnf(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_read_cnf_struct *sim_read_cnf;
    phb_IO_cntx* cntx = phb_IO_get_cntx(control_block);
    kal_bool result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_READ_CNF);

    phb_ptr->request_count--;

    //if (phb_ptr->request_count > 0) return;

    ASSERT(cntx != NULL);

    sim_read_cnf = (sim_read_cnf_struct*) ilm_ptr->local_para_ptr;

    if (sim_read_cnf->result == SIM_CMD_SUCCESS)
    {
        if (sim_read_cnf->file_idx != cntx->file_id)
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_READ);
            control_block->result = PHB_ERRNO_READ_FAIL;
            phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
            return;
        }
        /* success */
        switch (cntx->IO_stage)
        {
            case IO_WAIT:
                result = phb_parse_sim_data(
                                cntx->file_id,
                                cntx->occurrence,
                                sim_read_cnf,
                                &(control_block->data),
                                &(cntx->seg_record_index),
                                control_block->index,
                                control_block->record_index);
                if (result)
                {
                    phb_data_desc_mark_free(
                            phb_data_desc_file_id_to_desc(cntx->file_id, cntx->occurrence),
                            cntx->pbr_rec,
                            control_block->record_index,
                            cntx->record_index,
                            KAL_FALSE,
                            KAL_TRUE);
                    control_block->result = PHB_ERRNO_READ_SUCCESS;
                    if (control_block->secondary_ID != PHB_NULL_VALUE &&
                        phb_desc_index_check(
                            phb_data_desc_file_id_to_desc(control_block->secondary_ID, cntx->occurrence),
                            cntx->seg_record_index))
                    {
                        cntx->file_id = control_block->secondary_ID;
                        cntx->record_index = cntx->seg_record_index;
                        cntx->IO_stage = IO_SEGMENTATION;
                        break;
                    }
                }
                else
                {
                    phb_data_desc_mark_free(
                            phb_data_desc_file_id_to_desc(cntx->file_id, cntx->occurrence),
                            cntx->pbr_rec,
                            control_block->record_index,
                            cntx->record_index,
                            KAL_TRUE,
                            KAL_TRUE);
                    control_block->result = PHB_ERRNO_READ_EMPTY;
                }
                control_block->seg_record_index = (kal_uint8)PHB_INVALID_VALUE;
                phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                return;
                
        #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        #ifdef __PHB_IAP_CACHE_REMOVAL__
            case IO_READ_IAP:
                if (cntx->iap_pos >= sim_read_cnf->length)
                {
                    control_block->result = PHB_ERRNO_READ_EMPTY;
                    phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
                    return;
                }
                cntx->pri_record_index = sim_read_cnf->data[cntx->iap_pos];
                if (phb_desc_index_check(
                        phb_data_desc_file_id_to_desc(control_block->primary_ID, cntx->occurrence),
                        cntx->pri_record_index))
                {
                    cntx->file_id = control_block->primary_ID;
                    cntx->record_index = cntx->pri_record_index;
                    cntx->IO_stage = IO_WAIT;
                }
                else
                {
                    control_block->result = PHB_ERRNO_READ_EMPTY;
                    phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
                    return;
                }
                break;
        #endif /* __PHB_IAP_CACHE_REMOVAL__ */
        #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */

            case IO_SEGMENTATION:
            {
                phb_entry_struct *phb_entry;
                ef_ext_type *ef_ext;

                /* sim_read_cnf->data is a EFext */
                ef_ext = (ef_ext_type*) sim_read_cnf->data;

                if (ef_ext->ext_data_length <= PHB_EF_EXT_MAX_TEL_NUMBER_LEN)
                {
                    phb_entry = (phb_entry_struct*) control_block->data;
                    phb_sim_reassemble_tel_num(ef_ext, phb_entry);
                    phb_data_desc_mark_free(
                        phb_data_desc_file_id_to_desc(cntx->file_id, cntx->occurrence),
                        cntx->pbr_rec,
                        cntx->record_index,
                        cntx->record_index,
                        KAL_FALSE,
                        KAL_TRUE);
                    phb_se_set_ext_index(
                        control_block->primary_ID,
                        cntx->occurrence,
                        control_block->record_index,
                        cntx->record_index);
                    control_block->seg_record_index = cntx->seg_record_index;

                    /* need reassembly? */
                }
                phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                return;
            }
            
            default :
                /** 
                * Wrong state: currently it is not waiting. 
                * Abnormal, consume message.
                */
                kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_READ);
                control_block->result = PHB_ERRNO_READ_FAIL;
                phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
                return;
        }
        phb_IO_sim_read_record(
            cntx->file_id,
            cntx->record_index,
            cntx->occurrence,
            cntx->pbr_rec,
            control_block->ID);
    }
    /* error occured, call error handler */
    else
    {
        control_block->result = PHB_ERRNO_READ_FAIL;
        control_block->cause = sim_read_cnf->result;
        cntx->IO_stage = IO_NONE;
        phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_IO_sim_read
 * DESCRIPTION
 *  This function issues SIM_READ_REQ to sim.
 *  Read SIM from control_block specified primary_ID, record_index, and length
 *  
 *  Prerequisite:
 *  pimary_ID, secondary_ID, record_index and length.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_IO_sim_read(phb_IO_cntx* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    control_block_type *control_block;
#ifdef __PHB_USIM_SUPPORT__
    kal_bool result;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_READ);

    ASSERT(cntx != NULL);
    control_block = cntx->control_block;
    if (!phb_IO_index_check(
            control_block->primary_ID,
            cntx->occurrence,
            control_block->record_index))
    {
        control_block->result = PHB_ERRNO_READ_EMPTY;
        phb_IO_return(control_block, NULL, KAL_FALSE);
        return KAL_TRUE;
    }

#ifdef __PHB_USIM_SUPPORT__
    cntx->pbr_rec = phb_desc_get_pbr_rec(control_block->primary_ID, control_block->record_index);

    result = phb_desc_get_pri_index(
                control_block->primary_ID,
                control_block->record_index,
                cntx->occurrence,
                cntx->pbr_rec,
                &(cntx->pri_record_index),
                &(cntx->iap_pos));
    
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    if (!result)
    {
    #ifdef __PHB_IAP_CACHE_REMOVAL__
        cntx->IO_stage = IO_READ_IAP;
        cntx->file_id = phb_desc_get_used_file_id(FILE_G_IAP_IDX);
        cntx->record_index = cntx->pri_record_index;
    #else /* __PHB_IAP_CACHE_REMOVAL__ */
        cntx->file_id = phb_desc_get_used_file_id(FILE_G_IAP_IDX);
        cntx->record_index = control_block->record_index;
        if (cntx->iap_pos >= PHB_MAX_TYPE2_ENTRIES)
        {
            control_block->result = PHB_ERRNO_READ_EMPTY;
            phb_IO_return(control_block, NULL, KAL_FALSE);
            return KAL_TRUE;
        }
        cntx->pri_record_index = phb_ptr->iap_array[cntx->record_index - 1][cntx->iap_pos];
        if (phb_desc_index_check(
                phb_data_desc_file_id_to_desc(control_block->primary_ID, cntx->occurrence),
                cntx->pri_record_index))
        {
            cntx->file_id = control_block->primary_ID;
            cntx->record_index = cntx->pri_record_index;
            cntx->IO_stage = IO_WAIT;
        }
        else
        {
            control_block->result = PHB_ERRNO_READ_EMPTY;
            phb_IO_return(control_block, NULL, KAL_FALSE);
            return KAL_TRUE;
        }
    #endif /* __PHB_IAP_CACHE_REMOVAL__ */
    }
    else
#endif
    {
        cntx->IO_stage = IO_WAIT;
        cntx->file_id = control_block->primary_ID;
        cntx->record_index = cntx->pri_record_index;
    }
#else /* __PHB_USIM_SUPPORT__ */
    cntx->file_id = control_block->primary_ID;
    cntx->pri_record_index = control_block->record_index;
    cntx->record_index = cntx->pri_record_index;
    cntx->IO_stage = IO_WAIT;
#endif /* __PHB_USIM_SUPPORT__ */

    control_block->IO_cnf_receive = phb_IO_sim_read_cnf;
    phb_IO_sim_read_record(
        cntx->file_id,
        cntx->record_index,
        cntx->occurrence,
        cntx->pbr_rec,
        control_block->ID);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  phb_sim_read_cnf
 * DESCRIPTION
 *  This function issues SIM_FILE_INFO_REQ to sim.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_IO_sim_delete_cnf(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_write_cnf_struct *sim_write_cnf;
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
#ifdef __PHB_IAP_CACHE_REMOVAL__
    sim_read_cnf_struct *sim_read_cnf = NULL;
#endif
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
    phb_IO_cntx* cntx = phb_IO_get_cntx(control_block);
    kal_uint8* data = NULL;
    kal_uint16 file_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_DELETE_CNF);

    ASSERT(cntx != NULL);
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
#ifdef __PHB_IAP_CACHE_REMOVAL__
    if (cntx->IO_stage == IO_READ_IAP)
    {
        sim_read_cnf = (sim_read_cnf_struct*) ilm_ptr->local_para_ptr;
        control_block->cause = sim_read_cnf->result;
        file_id = sim_read_cnf->file_idx;
    }
    else
#endif /* __PHB_IAP_CACHE_REMOVAL__ */
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
    {
        sim_write_cnf = (sim_write_cnf_struct*) ilm_ptr->local_para_ptr;
        control_block->cause = sim_write_cnf->result;
        file_id = sim_write_cnf->file_idx;
    }

    if (control_block->cause == SIM_CMD_SUCCESS)
    {
        if (file_id != cntx->file_id)
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_DELETE);
            control_block->result = PHB_ERRNO_FAIL;
            phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
            return;
        }
        /* success */
        switch (cntx->IO_stage)
        {
            case IO_WAIT:
                phb_data_desc_mark_free(
                    phb_data_desc_file_id_to_desc(cntx->file_id, cntx->occurrence),
                    cntx->pbr_rec,
                    control_block->record_index,
                    cntx->record_index,
                    KAL_TRUE,
                    KAL_TRUE);
                control_block->result = PHB_ERRNO_SUCCESS;
                phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                return;
                
        #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        #ifdef __PHB_IAP_CACHE_REMOVAL__
            case IO_READ_IAP:
            {
                if (cntx->iap_pos >= sim_read_cnf->length)
                {
                    kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_DELETE);
                    control_block->result = PHB_ERRNO_DELETE_EMPTY;
                    phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
                    return;
                }
                cntx->pri_record_index = sim_read_cnf->data[cntx->iap_pos];
                if (phb_desc_index_check(
                        phb_data_desc_file_id_to_desc(control_block->primary_ID, cntx->occurrence),
                        cntx->pri_record_index))
                {
                    sim_read_cnf->data[cntx->iap_pos] = 0xFF;
                    data = sim_read_cnf->data;
                    cntx->IO_stage = IO_WRITE_IAP;
                }
                else
                {
                    kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_DELETE);
                    control_block->result = PHB_ERRNO_DELETE_EMPTY;
                    phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
                    return;
                }
                break;
            }
        #endif /* __PHB_IAP_CACHE_REMOVAL__ */

            case IO_WRITE_IAP:
            {
                if (control_block->secondary_ID != PHB_NULL_VALUE &&
                    phb_desc_index_check(
                        phb_data_desc_file_id_to_desc(control_block->secondary_ID, 0),
                        cntx->seg_record_index))
                {
                    cntx->file_id = control_block->secondary_ID;
                    cntx->record_index = cntx->seg_record_index;
                    cntx->IO_stage = IO_SEGMENTATION;
                }
                else
                {
                    cntx->file_id = control_block->primary_ID;
                    cntx->record_index = cntx->pri_record_index;
                    cntx->IO_stage = IO_WAIT;
                }
                break;
            }
        #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */

            case IO_SEGMENTATION:
            {
                /* not support more than one ext records for one record */
                phb_data_desc_mark_free(
                    phb_data_desc_file_id_to_desc(cntx->file_id, cntx->occurrence),
                    cntx->pbr_rec,
                    cntx->record_index,
                    cntx->record_index,
                    KAL_TRUE,
                    KAL_TRUE);
                phb_se_delete_ext_index(cntx->file_id, cntx->record_index);
                cntx->file_id = control_block->primary_ID;
                cntx->record_index = cntx->pri_record_index;
                cntx->IO_stage = IO_WAIT;
                break;
            }
            
            default :
                /** 
                * Wrong state: currently it is not waiting. 
                * Abnormal, consume message.
                */
                kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_DELETE);
                control_block->result = PHB_ERRNO_FAIL;
                phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
                return;
        }
        phb_IO_sim_write_record(
            cntx->file_id,
            cntx->record_index,
            cntx->occurrence,
            cntx->pbr_rec,
            data,
            control_block->ID,
            KAL_FALSE);
    }
    /* error occured, call error handler */
    else
    {
        cntx->IO_stage = IO_NONE;
        control_block->result = PHB_ERRNO_FAIL;
        phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  phb_IO_sim_delete
 * DESCRIPTION
 *  This function issues SIM_WRITE_REQ to sim.
 *  
 *  Prerequisite:
 *  control_block must be constructed, phb_control_block_set_IO(), and phb_se_set_control_block().
 *  So that primary_ID, secondary_ID, index and record_index are all set.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_IO_sim_delete(phb_IO_cntx* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    control_block_type *control_block;
#ifdef __PHB_USIM_SUPPORT__
    kal_bool result;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_DELETE);

    ASSERT(cntx != NULL);
    control_block = cntx->control_block;
    if (!phb_IO_index_check(
            control_block->primary_ID,
            cntx->occurrence,
            control_block->record_index))
    {
        kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_DELETE);
        control_block->result = PHB_ERRNO_DELETE_EMPTY;
        phb_IO_return(control_block, NULL, KAL_FALSE);
        return KAL_TRUE;
    }
    control_block->IO_cnf_receive = phb_IO_sim_delete_cnf;
    
    /* get seg_record_index */
    cntx->seg_record_index = phb_se_get_ext_index(
                                control_block->primary_ID,
                                cntx->occurrence,
                                control_block->index,
                                control_block->record_index
                                );

#ifdef __PHB_USIM_SUPPORT__
    cntx->pbr_rec = phb_desc_get_pbr_rec(control_block->primary_ID, control_block->record_index);

    result = phb_desc_get_pri_index(
                control_block->primary_ID,
                control_block->record_index,
                cntx->occurrence,
                cntx->pbr_rec,
                &(cntx->pri_record_index),
                &(cntx->iap_pos));
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    if (!result)
    {
    #ifdef __PHB_IAP_CACHE_REMOVAL__
        cntx->IO_stage = IO_READ_IAP;
        cntx->file_id = phb_desc_get_used_file_id(FILE_G_IAP_IDX);
        cntx->record_index = cntx->pri_record_index;
        phb_IO_sim_read_record(
            cntx->file_id,
            cntx->record_index,
            cntx->occurrence,
            cntx->pbr_rec,
            control_block->ID);
    #else /* __PHB_IAP_CACHE_REMOVAL__ */
        cntx->file_id = phb_desc_get_used_file_id(FILE_G_IAP_IDX);
        cntx->record_index = control_block->record_index;
        if (cntx->iap_pos >= PHB_MAX_TYPE2_ENTRIES)
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_DELETE);
            control_block->result = PHB_ERRNO_DELETE_EMPTY;
            phb_IO_return(control_block, NULL, KAL_FALSE);
            return KAL_TRUE;
        }
        cntx->pri_record_index = phb_ptr->iap_array[cntx->record_index - 1][cntx->iap_pos];
        if (phb_desc_index_check(
                phb_data_desc_file_id_to_desc(control_block->primary_ID, cntx->occurrence),
                cntx->pri_record_index))
        {
            phb_ptr->iap_array[cntx->record_index - 1][cntx->iap_pos] = 0xFF;
            cntx->IO_stage = IO_WRITE_IAP;
        }
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_DELETE);
            control_block->result = PHB_ERRNO_DELETE_EMPTY;
            phb_IO_return(control_block, NULL, KAL_FALSE);
            return KAL_TRUE;
        }
        phb_IO_sim_write_record(
            cntx->file_id,
            cntx->record_index,
            cntx->occurrence,
            cntx->pbr_rec,
            phb_ptr->iap_array[cntx->record_index - 1],
            control_block->ID,
            KAL_FALSE);
    #endif /* __PHB_IAP_CACHE_REMOVAL__ */
        return KAL_TRUE;
    }
#endif
#else /* __PHB_USIM_SUPPORT__ */
    cntx->pri_record_index = control_block->record_index;
#endif /* __PHB_USIM_SUPPORT__ */

    if (control_block->secondary_ID != PHB_NULL_VALUE &&
        phb_desc_index_check(
            phb_data_desc_file_id_to_desc(control_block->secondary_ID, cntx->occurrence),
            cntx->seg_record_index))
    {
        cntx->file_id = control_block->secondary_ID;
        cntx->record_index = cntx->seg_record_index;
        cntx->IO_stage = IO_SEGMENTATION;
    }
    else
    {
        cntx->file_id = control_block->primary_ID;
        cntx->record_index = cntx->pri_record_index;
        cntx->IO_stage = IO_WAIT;
    }
    phb_IO_sim_write_record(
        cntx->file_id,
        cntx->record_index,
        cntx->occurrence,
        cntx->pbr_rec,
        NULL,
        control_block->ID,
        ((cntx->seg_record_index > 0 && cntx->seg_record_index != (kal_uint8) PHB_INVALID_VALUE) ? KAL_TRUE : KAL_FALSE));
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  phb_sim_prepare_data_to_write
 * DESCRIPTION
 *  Prepare data stored in given phb_entry_struct to approprieate structure
 *  for raw data to write, depending on it is written to SIM or NVRAM.
 *  
 *  Prerequisite:
 *  1. phb_entry->tel_number.addr_length must be set.
 *  2. control_block->seg_total must be set.
 *  3. control_block->length must be set.
 * PARAMETERS
 *  control_block       [?]         
 *  buffer              [?]         
 *  chained_id          [IN]        
 * RETURNS
 *  Return corresponding sim_file_id of data descriptor type
 *****************************************************************************/
kal_uint8* phb_build_sim_data(
                kal_uint16 file_id,
                kal_uint8 occurrence,
                kal_uint8* in_data,
                kal_uint8 seg_index,
                kal_uint8 seg_length,
                kal_uint8 seg_total)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 length;
    kal_uint8* buffer;
    data_desc_enum type = phb_data_desc_file_id_to_desc(file_id, occurrence);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_PREPARE_DATA_TO_WRITE);
    length = (kal_uint8) phb_data_desc_get_record_size(type);
    buffer = get_ctrl_buffer(length);

    switch (file_id)
    {
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        case FILE_G_ANR_IDX:
        case FILE_U_ANR_IDX:
        {
            phb_ef_mandatory_struct *phb_ef_mandatory = NULL;
            phb_entry_struct *phb_entry = (phb_entry_struct*) in_data;

            kal_uint8 tel_number_size = 0;

            kal_uint8 pbr_pos = 0;
            kal_uint8 pbr_rec = 0;

            kal_mem_set(buffer, 0xFF, length);
            buffer[0] = phb_entry->aas_id;
            /* Now prepare the data content */
            phb_ef_mandatory = (phb_ef_mandatory_struct*) & buffer[1];

            if (phb_entry->tel_number.addr_length == 1) /* Empty number */
            {
                /* "+" character */
                if (phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] == 0x91)
                {
                    phb_ef_mandatory->len = 1;
                    phb_ef_mandatory->ton_npi = 0x91;
                }
                else
                {
                    phb_ef_mandatory->len = 0xff;
                    phb_ef_mandatory->ton_npi = 0xff;
                }
                kal_mem_set((kal_uint8*) phb_ef_mandatory->tel_number, 0xff, EF_TEL_NUMBER_SIZE);  /* 0x91 */
            }
            else
            {
                /* Length of telephone number is ensured to be less than EF_TEL_NUMBER_SIZE */
                phb_ef_mandatory->len = phb_entry->tel_number.addr_length - seg_total;
                if (phb_ef_mandatory->len > 0)
                {
                    tel_number_size = phb_ef_mandatory->len - 1;
                }
                phb_ef_mandatory->ton_npi = phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET];
                kal_mem_cpy(
                    &phb_ef_mandatory->tel_number[0],
                    (void const*)&phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                    tel_number_size);
            }
            phb_ef_mandatory->cap_cnf_id = phb_entry->cap_cnf_id;
            phb_ef_mandatory->ext_id = seg_index;

            if ((phb_desc_get_file_type(type) == 2) && (length > 16))
            {
                pbr_pos = phb_desc_get_pbr_pos(DATA_DESC_ADN);
                
                if (file_id == FILE_G_ANR_IDX)
                    pbr_rec = phb_desc_get_pbr_rec(FILE_G_ADN_IDX, phb_entry->record_index);
                else
                    pbr_rec = phb_desc_get_pbr_rec(FILE_U_ADN_IDX, phb_entry->record_index);
                
                buffer[15] = phb_ptr->phb_pbr_table[pbr_pos][pbr_rec-1].sfi;
                buffer[16] = phb_entry->record_index;
            }
            break;
        }
        
        case FILE_G_EMAIL_IDX:
        case FILE_U_EMAIL_IDX:
        {
            phb_email_struct *email_entry = (phb_email_struct*) in_data;
            kal_uint8 alpha_id_length = length;
            
            kal_uint8 pbr_pos = 0;
            kal_uint8 pbr_rec = 0;            
            
            if (phb_desc_get_file_type(type) == 2)
            {
                alpha_id_length -= 2;
            }
            kal_mem_set(buffer, 0xFF, length);

            /* Now prepare the data content */
            if (email_entry->email_length > 0 && alpha_id_length > 0)
            {
                istring_type istr;
                kal_uint8 write_length;

                istr.length = email_entry->email_length;
                istr.charset = CHARSET_ASCII;
                istr.data = &email_entry->email_address[0];

                /* Error occured when encoding alph-id field */
                write_length = istring_encode_to_sim(CODING_AUTO, (istring_type*) & istr, alpha_id_length, buffer);
                if (write_length == 0)
                {
                    return buffer;
                }
                email_entry->email_length = write_length;

                email_entry->email_address[email_entry->email_length] = 0;
                email_entry->email_address[email_entry->email_length + 1] = 0;
            }
            if (phb_desc_get_file_type(type) == 2)
            {
                pbr_pos = phb_desc_get_pbr_pos(DATA_DESC_ADN);
                
                if (file_id == FILE_G_EMAIL_IDX)
                    pbr_rec = phb_desc_get_pbr_rec(FILE_G_ADN_IDX, email_entry->record_index);
                else
                    pbr_rec = phb_desc_get_pbr_rec(FILE_U_ADN_IDX, email_entry->record_index);
                
                buffer[alpha_id_length]     = phb_ptr->phb_pbr_table[pbr_pos][pbr_rec-1].sfi;            
                buffer[alpha_id_length + 1] = (kal_uint8)email_entry->adn_record_index;
            }
            break;
        }
        
        case FILE_G_AAS_IDX:
        case FILE_U_AAS_IDX:
        case FILE_G_GAS_IDX:
        case FILE_U_GAS_IDX:
        case FILE_G_SNE_IDX:
        case FILE_U_SNE_IDX:
        {
            l4_name_struct *phb_alpha_field = (l4_name_struct*) in_data;

            kal_uint8 alpha_id_length = 0;

            /* Referenced control_block shall not be NULL) */

            alpha_id_length = length;
            kal_mem_set(buffer, 0xFF, length);

            /* Now prepare the data content */
            if (phb_alpha_field->name_length > 0 && alpha_id_length > 0)
            {
                istring_type istr;
                kal_uint8 write_length;

                istr.length = phb_alpha_field->name_length;
                istr.charset = phb_alpha_field->name_dcs;
                istr.data = &phb_alpha_field->name[0];

                /* Error occured when encoding alph-id field */
                write_length = istring_encode_to_sim(CODING_AUTO, (istring_type*) & istr, alpha_id_length, buffer);
                if (write_length == 0)
                {
                    return buffer;
                }
                /* amanda add */
                if (phb_alpha_field->name_dcs == CHARSET_ASCII)
                {
                    phb_alpha_field->name_length = write_length;
                }
            #ifdef __PHB_0x81_SUPPORT__     /* MTK 2004-04-20 Wisoln, support maximum length of 0x81 UCS2 */
                else if (phb_alpha_field->name_dcs == CHARSET_UCS2_81)
                {
                    phb_alpha_field->name_length = write_length;
                    phb_alpha_field->name[1] = write_length - 3;
                }
                else if (phb_alpha_field->name_dcs == CHARSET_UCS2_82)
                {
                    phb_alpha_field->name_length = write_length;
                    phb_alpha_field->name[1] = write_length - 4;
                }
            #endif /* __PHB_0x81_SUPPORT__ */ 
                else
                {
                    phb_alpha_field->name_length = write_length * 2;
                }
                
                if (phb_alpha_field->name_length >= (MAX_PS_NAME_SIZE - 1))
                {
                    kal_trace(TRACE_ERROR, FUNC_PHB_PREPARE_DATA_TO_WRITE);
                    return buffer;
                }   
                phb_alpha_field->name[phb_alpha_field->name_length] = 0;
                phb_alpha_field->name[phb_alpha_field->name_length + 1] = 0;
            }
            break;
        }
        
        case FILE_G_GRP_IDX:
        case FILE_U_GRP_IDX:
        {
            kal_mem_set(buffer, 0xFF, length);
            if (length > PHB_MAX_ASSOCIATE_GRP)
            {
                length = PHB_MAX_ASSOCIATE_GRP;
            }
            kal_mem_cpy(buffer, (void const*)in_data, length);
            break;
        }
    #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */

    #ifdef __PHB_USIM_SYNC__
        case FILE_G_CC_IDX:
        case FILE_U_CC_IDX:
        case FILE_G_PBC_IDX:
        case FILE_U_PBC_IDX:
		case FILE_G_UID_IDX:
        case FILE_U_UID_IDX:
        case FILE_G_PUID_IDX:
        case FILE_U_PUID_IDX:
        case FILE_G_PSC_IDX:
        case FILE_U_PSC_IDX:
        {
            kal_mem_set(buffer, 0xFF, length);
            kal_mem_cpy(buffer, (void const*)in_data, length);
            break;
        }
    #endif /* __PHB_USIM_SYNC__ */
    
        case FILE_EXT1_IDX:
        case FILE_G_EXT1_IDX:
        case FILE_U_EXT1_IDX:
        case FILE_EXT2_IDX:
        case FILE_U_EXT2_IDX:
        case FILE_EXT3_IDX:
        case FILE_U_EXT3_IDX:
        case FILE_EXT4_IDX:
        case FILE_U_EXT4_IDX:
        case FILE_U_EXT5_IDX:
        {
            phb_entry_struct *phb_entry = (phb_entry_struct*) in_data;
            ef_ext_type* ef_ext_buffer = (ef_ext_type*)buffer;
            kal_mem_set(ef_ext_buffer, (kal_uint8) PHB_INVALID_VALUE, sizeof(ef_ext_type));
            
            if (seg_length != 0)
            {
                /* Now prepare the data content in ext_buffer */
                ef_ext_buffer->record_type = EF_EXT_TYPE_ADDITIONAL_DATA;
                ef_ext_buffer->ext_data_length = seg_length;
                ef_ext_buffer->identifier = (kal_uint8)PHB_INVALID_VALUE;
            
                kal_mem_cpy(
                    ef_ext_buffer->ext_data,
                    (void const*)&phb_entry->tel_number.addr_bcd[phb_entry->tel_number.addr_length - seg_total - seg_length],
                    seg_length);
            }
            break;
        }

        default :
        {
            phb_ef_mandatory_struct *phb_ef_mandatory = NULL;
            phb_entry_struct *phb_entry = (phb_entry_struct*) in_data;

            kal_uint8 alpha_id_length = 0;
            kal_uint8 tel_number_size = 0;

            /* Referenced control_block shall not be NULL) */

            alpha_id_length = length - PHB_LENGTH_AFTER_ALPHA_ID;
            if (file_id == FILE_BDN_IDX ||
                file_id == FILE_U_BDN_IDX)
            {
                alpha_id_length--;
            }
            kal_mem_set(buffer, 0xFF, length);

            /* Now prepare the data content */
            if (phb_entry->alpha_id.name_length > 0 && alpha_id_length > 0)
            {
                istring_type istr;
                kal_uint8 write_length;

                istr.length = phb_entry->alpha_id.name_length;
                istr.charset = phb_entry->alpha_id.name_dcs;
                istr.data = &phb_entry->alpha_id.name[0];

                /* Error occured when encoding alph-id field */
                write_length = istring_encode_to_sim(CODING_AUTO, (istring_type*) & istr, alpha_id_length, buffer);
                if (write_length == 0)
                {
                    return buffer;
                }
                /* amanda add */
                if (phb_entry->alpha_id.name_dcs == CHARSET_ASCII)
                {
                    phb_entry->alpha_id.name_length = write_length;
                    if (phb_entry->alpha_id.name_length >= MAX_PS_NAME_SIZE)
                    {
                        kal_trace(TRACE_ERROR, FUNC_PHB_PREPARE_DATA_TO_WRITE);
                        return buffer;
                    }   

                    phb_entry->alpha_id.name[phb_entry->alpha_id.name_length] = 0;
                }
            #ifdef __PHB_0x81_SUPPORT__     /* MTK 2004-04-20 Wisoln, support maximum length of 0x81 UCS2 */
                else if (phb_entry->alpha_id.name_dcs == CHARSET_UCS2_81)
                {
                    phb_entry->alpha_id.name_length = write_length;
                    phb_entry->alpha_id.name[1] = write_length - 3;
                }
                else if (phb_entry->alpha_id.name_dcs == CHARSET_UCS2_82)
                {
                    phb_entry->alpha_id.name_length = write_length;
                    phb_entry->alpha_id.name[1] = write_length - 4;
                }
            #endif /* __PHB_0x81_SUPPORT__ */ 
                else
                {
                    phb_entry->alpha_id.name_length = write_length * 2;
                    if (phb_entry->alpha_id.name_length >= (MAX_PS_NAME_SIZE - 1))
                    {
                        kal_trace(TRACE_ERROR, FUNC_PHB_PREPARE_DATA_TO_WRITE);
                        return buffer;
                    }   

                    phb_entry->alpha_id.name[phb_entry->alpha_id.name_length] = 0;
                    phb_entry->alpha_id.name[phb_entry->alpha_id.name_length + 1] = 0;
                }
            }

            phb_ef_mandatory = (phb_ef_mandatory_struct*) & buffer[alpha_id_length];

            if (phb_entry->tel_number.addr_length == 1) /* Empty number */
            {
                /* "+" character */
                if (phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] == 0x91)
                {
                    phb_ef_mandatory->len = 1;
                    phb_ef_mandatory->ton_npi = 0x91;
                }
                else
                {
                    phb_ef_mandatory->len = 0xff;
                    phb_ef_mandatory->ton_npi = 0xff;
                }
                kal_mem_set((kal_uint8*) phb_ef_mandatory->tel_number, 0xff, EF_TEL_NUMBER_SIZE);  /* 0x91 */
            }
            else
            {
                /* Length of telephone number is ensured to be less than EF_TEL_NUMBER_SIZE */
                phb_ef_mandatory->len = phb_entry->tel_number.addr_length - seg_total;
                if (phb_ef_mandatory->len > 0)
                {
                    tel_number_size = phb_ef_mandatory->len - 1;
                }
                phb_ef_mandatory->ton_npi = phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET];
                kal_mem_cpy(
                    &phb_ef_mandatory->tel_number[0],
                    (void const*)&phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                    tel_number_size);
            }
            phb_ef_mandatory->cap_cnf_id = phb_entry->cap_cnf_id;
            phb_ef_mandatory->ext_id = seg_index;
            break;
        }
    }
	return buffer;
}


/*****************************************************************************
 * FUNCTION
 *  phb_IO_sim_write_cnf
 * DESCRIPTION
 *  This function issues SIM_FILE_INFO_REQ to sim.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_IO_sim_write_cnf(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_write_cnf_struct *sim_write_cnf;
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
#ifdef __PHB_IAP_CACHE_REMOVAL__
    sim_read_cnf_struct *sim_read_cnf = NULL;
#endif
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
    phb_IO_cntx* cntx = phb_IO_get_cntx(control_block);
    kal_uint8* data = NULL;
    kal_bool need_free = KAL_FALSE;
    kal_uint16 file_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_WRITE_CNF);

    ASSERT(cntx != NULL);
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
#ifdef __PHB_IAP_CACHE_REMOVAL__
    if (cntx->IO_stage == IO_READ_IAP)
    {
        sim_read_cnf = (sim_read_cnf_struct*) ilm_ptr->local_para_ptr;
        control_block->cause = sim_read_cnf->result;
        file_id = sim_read_cnf->file_idx;
    }
    else
#endif /* __PHB_IAP_CACHE_REMOVAL__ */
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
    {
        sim_write_cnf = (sim_write_cnf_struct*) ilm_ptr->local_para_ptr;
        control_block->cause = sim_write_cnf->result;
        file_id = sim_write_cnf->file_idx;
    }

    if (control_block->cause == SIM_CMD_SUCCESS)
    {
        if (file_id != cntx->file_id)
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_WRITE);
            control_block->result = PHB_ERRNO_FAIL;
            phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
            return;
        }
        /* success */
        switch (cntx->IO_stage)
        {
            case IO_WAIT:
                phb_data_desc_mark_free(
                    phb_data_desc_file_id_to_desc(cntx->file_id, cntx->occurrence),
                    cntx->pbr_rec,
                    control_block->record_index,
                    cntx->record_index,
                    KAL_FALSE,
                    KAL_TRUE);
            #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
                if (cntx->tmp_iap_data)
                {
                    data = cntx->tmp_iap_data;
                    cntx->file_id = phb_desc_get_used_file_id(FILE_G_IAP_IDX);
                    cntx->record_index = cntx->iap_index;
                    cntx->IO_stage = IO_WRITE_IAP;
                }
                else
            #endif
                {
                    control_block->result = PHB_ERRNO_SUCCESS;
                    phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                    return;
                }
                break;
                
        #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        #ifdef __PHB_IAP_CACHE_REMOVAL__
            case IO_READ_IAP:
            {
                if (cntx->iap_pos >= sim_read_cnf->length)
                {
                    kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_WRITE);
                    control_block->result = PHB_ERRNO_FAIL;
                    control_block->cause = PHB_CAUSE_CAPACITY_EXCEEDED;
                    phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
                    return;
                }
                cntx->pri_record_index = sim_read_cnf->data[cntx->iap_pos];
                if (!phb_desc_index_check(
                        phb_data_desc_file_id_to_desc(control_block->primary_ID, cntx->occurrence),
                        cntx->pri_record_index))
                {
                    cntx->pri_record_index =
                        phb_data_desc_find_next_free_ext(
                                phb_data_desc_file_id_to_desc(control_block->primary_ID, cntx->occurrence),
                                cntx->pbr_rec);
                    if (phb_desc_index_check(
                            phb_data_desc_file_id_to_desc(control_block->primary_ID, cntx->occurrence),
                            cntx->pri_record_index))
                    {
                        sim_read_cnf->data[cntx->iap_pos] = (kal_uint8)cntx->pri_record_index;
                    }
                    else
                    {
                        kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_WRITE);
                        control_block->result = PHB_ERRNO_FAIL;
                        control_block->cause = PHB_CAUSE_CAPACITY_EXCEEDED;
                        phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
                        return;
                    }
                }
                cntx->tmp_iap_data = get_ctrl_buffer(sim_read_cnf->length);
                memcpy(cntx->tmp_iap_data, sim_read_cnf->data, sim_read_cnf->length);
                
                if (control_block->secondary_ID != PHB_NULL_VALUE &&
                    phb_desc_index_check(
                        phb_data_desc_file_id_to_desc(control_block->secondary_ID,  0),
                        cntx->seg_record_index))
                {
                    cntx->file_id = control_block->secondary_ID;
                    cntx->record_index = cntx->seg_record_index;
                    cntx->IO_stage = IO_SEGMENTATION;
                }
                else
                {
                    cntx->file_id = control_block->primary_ID;
                    cntx->record_index = cntx->pri_record_index;
                    cntx->IO_stage = IO_WAIT;
                }
                break;
            }
        #endif /* __PHB_IAP_CACHE_REMOVAL__ */

            case IO_WRITE_IAP:
            {
                if (cntx->tmp_iap_data)
                {
                    free_ctrl_buffer(cntx->tmp_iap_data);
                    cntx->tmp_iap_data = NULL;
                }
                control_block->result = PHB_ERRNO_SUCCESS;
                phb_IO_return(control_block, ilm_ptr, KAL_TRUE);
                return;
            }
        #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */

            case IO_SEGMENTATION:
            {
                if (cntx->seg_len == 0)
                {
                    phb_data_desc_mark_free(
                        phb_data_desc_file_id_to_desc(cntx->file_id, cntx->occurrence),
                        cntx->pbr_rec,
                        cntx->record_index,
                        cntx->record_index,
                        KAL_TRUE,
                        KAL_TRUE);
                    phb_se_delete_ext_index(cntx->file_id, cntx->record_index);
                    cntx->seg_record_index = (kal_uint8)PHB_INVALID_VALUE;
                }
                else
                {
                    phb_data_desc_mark_free(
                        phb_data_desc_file_id_to_desc(cntx->file_id, cntx->occurrence),
                        cntx->pbr_rec,
                        cntx->record_index,
                        cntx->record_index,
                        KAL_FALSE,
                        KAL_TRUE);
                    phb_se_set_ext_index(
                        control_block->primary_ID,
                        cntx->occurrence,
                        control_block->record_index,
                        cntx->record_index);
                    cntx->seg_total += cntx->seg_len;
                }
                control_block->seg_record_index = cntx->seg_record_index;
                /* not support more than one ext records for one record */
                cntx->file_id = control_block->primary_ID;
                cntx->record_index = cntx->pri_record_index;
                cntx->IO_stage = IO_WAIT;
                break;
            }
            
            default :
                /** 
                * Wrong state: currently it is not waiting. 
                * Abnormal, consume message.
                */
                kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_WRITE);
                control_block->result = PHB_ERRNO_FAIL;
                phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
                return;
        }
        if (data == NULL)
        {
            data = phb_build_sim_data(
                        cntx->file_id,
                        cntx->occurrence,
						control_block->data,
                        cntx->seg_record_index,
                        cntx->seg_len,
                        cntx->seg_total);
            need_free = KAL_TRUE;
        }
        phb_IO_sim_write_record(
            cntx->file_id,
            cntx->record_index,
            cntx->occurrence,
            cntx->pbr_rec,
            data,
            control_block->ID,
            KAL_FALSE);
        if (need_free && data)
        {
            free_ctrl_buffer(data);
        }
    }
    /* error occured, call error handler */
    else
    {
        cntx->IO_stage = IO_NONE;
        control_block->result = PHB_ERRNO_FAIL;
        phb_IO_return(control_block, ilm_ptr, KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_IO_sim_write
 * DESCRIPTION
 *  This function issues SIM_WRITE_REQ to sim.
 *  
 *  Prerequisite:
 *  control_block must be constructed, phb_control_block_set_IO(), and phb_se_set_control_block().
 *  So that primary_ID, secondary_ID, index and record_index are all set.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_IO_sim_write(phb_IO_cntx* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    control_block_type *control_block;
    kal_uint8* data = NULL;
#ifdef __PHB_USIM_SUPPORT__
	kal_bool result;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SIM_WRITE);

    ASSERT(cntx != NULL);
    control_block = cntx->control_block;
    if (!phb_IO_index_check(
            control_block->primary_ID,
            cntx->occurrence,
            control_block->record_index))
    {
        kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_WRITE);
        control_block->result = PHB_ERRNO_FAIL;
        control_block->cause = PHB_CAUSE_CAPACITY_EXCEEDED;
        phb_IO_return(control_block, NULL, KAL_FALSE);
        return KAL_TRUE;
    }
    
    control_block->IO_cnf_receive = phb_IO_sim_write_cnf;
    /* get seg record index */
    cntx->seg_record_index = phb_se_get_ext_index(
                                    control_block->primary_ID,
                                    cntx->occurrence,
                                    control_block->index,
                                    control_block->record_index
                                    );

    if (control_block->secondary_ID != PHB_NULL_VALUE)
    {
        phb_entry_struct* phb_entry = (phb_entry_struct*) control_block->data;
		if (phb_entry->tel_number.addr_length - TON_NPI_SIZE > EF_TEL_NUMBER_SIZE)
		{
			cntx->seg_len = phb_entry->tel_number.addr_length - TON_NPI_SIZE - EF_TEL_NUMBER_SIZE;
		}
        
        if (cntx->seg_len > 0 && cntx->seg_len <= EF_TEL_NUMBER_SIZE)
        {
            if (!phb_desc_index_check(
                    phb_data_desc_file_id_to_desc(control_block->secondary_ID, cntx->occurrence),
                    cntx->seg_record_index))
            {
                cntx->seg_record_index = 
                    (kal_uint8)phb_data_desc_find_next_free(phb_data_desc_file_id_to_desc(control_block->secondary_ID, cntx->occurrence));
                if (cntx->seg_record_index == (kal_uint8)PHB_INVALID_VALUE)
                {
                    control_block->cause = SIM_EF_RECORD_FULL;
                }
            }
        }
        else if (cntx->seg_len > EF_TEL_NUMBER_SIZE)
        {
            control_block->cause = SIM_EF_RECORD_FULL;
        }

        if (control_block->cause == SIM_EF_RECORD_FULL)
        {
            return KAL_FALSE;
        }
    }
    cntx->pri_record_index = control_block->record_index; /* for SIM */
    
#ifdef __PHB_USIM_SUPPORT__
    cntx->pbr_rec = phb_desc_get_pbr_rec(control_block->primary_ID, control_block->record_index);

    result = phb_desc_get_pri_index(
                control_block->primary_ID,
                control_block->record_index,
                cntx->occurrence,
                cntx->pbr_rec,
                &(cntx->pri_record_index),
                &(cntx->iap_pos));
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    if (!result)
    {
    #ifdef __PHB_IAP_CACHE_REMOVAL__
        cntx->IO_stage = IO_READ_IAP;
        cntx->file_id = phb_desc_get_used_file_id(FILE_G_IAP_IDX);
        cntx->record_index = cntx->pri_record_index;
        cntx->iap_index = cntx->record_index;
        phb_IO_sim_read_record(
            cntx->file_id,
            cntx->record_index,
            cntx->occurrence,
            cntx->pbr_rec,
            control_block->ID);
        return KAL_TRUE;
    #else /* __PHB_IAP_CACHE_REMOVAL__ */
        cntx->file_id = phb_desc_get_used_file_id(FILE_G_IAP_IDX);
        cntx->record_index = control_block->record_index;
        cntx->iap_index = cntx->pri_record_index;
        if (cntx->iap_pos >= PHB_MAX_TYPE2_ENTRIES)
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_WRITE);
            control_block->result = PHB_ERRNO_FAIL;
            control_block->cause = PHB_CAUSE_CAPACITY_EXCEEDED;
            phb_IO_return(control_block, NULL, KAL_FALSE);
            return KAL_TRUE;
        }
        cntx->pri_record_index = phb_ptr->iap_array[cntx->record_index - 1][cntx->iap_pos];
        if (!phb_desc_index_check(
                phb_data_desc_file_id_to_desc(control_block->primary_ID, cntx->occurrence),
                cntx->pri_record_index))
        {
            cntx->pri_record_index =
                phb_data_desc_find_next_free_ext(
                        phb_data_desc_file_id_to_desc(control_block->primary_ID, cntx->occurrence),
                        cntx->pbr_rec);
            if (phb_desc_index_check(
                    phb_data_desc_file_id_to_desc(control_block->primary_ID, cntx->occurrence),
                    cntx->pri_record_index))
            {
                phb_ptr->iap_array[cntx->record_index - 1][cntx->iap_pos] = (kal_uint8)cntx->pri_record_index;
            }
            else
            {
                kal_trace(TRACE_ERROR, ERROR_PHB_SIM_IO_STATE_WRITE);
                control_block->result = PHB_ERRNO_FAIL;
                control_block->cause = PHB_CAUSE_CAPACITY_EXCEEDED;
                phb_IO_return(control_block, NULL, KAL_FALSE);
                return KAL_TRUE;
            }
        }
        cntx->tmp_iap_data = get_ctrl_buffer(PHB_MAX_TYPE2_ENTRIES);
        memcpy(cntx->tmp_iap_data, phb_ptr->iap_array[cntx->record_index - 1], PHB_MAX_TYPE2_ENTRIES);
    #endif /* __PHB_IAP_CACHE_REMOVAL__ */
    }
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
#endif /* __PHB_USIM_SUPPORT__ */

    if (control_block->secondary_ID != PHB_NULL_VALUE &&
        phb_desc_index_check(
            phb_data_desc_file_id_to_desc(control_block->secondary_ID, cntx->occurrence),
            cntx->seg_record_index))
    {
        cntx->file_id = control_block->secondary_ID;
        cntx->record_index = cntx->seg_record_index;
        cntx->IO_stage = IO_SEGMENTATION;
    }
    else
    {
        cntx->file_id = control_block->primary_ID;
        cntx->record_index = cntx->pri_record_index;
        cntx->seg_record_index = (kal_uint8)PHB_INVALID_VALUE;
        cntx->IO_stage = IO_WAIT;
    }
    data = phb_build_sim_data(
                cntx->file_id,
                cntx->occurrence,
				control_block->data,
                cntx->seg_record_index,
                cntx->seg_len,
                cntx->seg_total);

    phb_IO_sim_write_record(
        cntx->file_id,
        cntx->record_index,
        cntx->occurrence,
        cntx->pbr_rec,
        data,
        control_block->ID,
        KAL_FALSE);
    if (data)
    {
        free_ctrl_buffer(data);
    }
    return KAL_TRUE;
}

