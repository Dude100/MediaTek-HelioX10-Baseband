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
 * phb_context.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#undef  _FILE_CODE_
#define _FILE_CODE_  _PHB_CONTEXT_C_

//#include "kal_release.h"        /* Basic data type */

//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "app_ltlcom.h" /* Task message communiction */

#include "sim_common_enums.h"
// #include "nvram_editor_data_item.h"
//#include "custom_nvram_editor_data_item.h"

//#include "l4_common.h"
#include "ps2sim_struct.h"

//#include "l4c2phb_enums.h"
//#include "l4c2phb_struct.h"

//#include "kal_trace.h"
//#include "phb_trc.h"

/* Prerequisite of phb_context.h */
#include "phb_defs.h"
#include "phb_control_block.h"
#include "phb_config.h"
#include "phb_data_desc.h"
#include "phb_data_entry_table.h"
//#include "phb_pindex.h"
//#include "phb_name_num_index.h"

#include "phb_context.h"
#include "phb_config.h"

#if defined(__GEMINI__) || defined(GEMINI_PLUS) || defined(__SGLTE__)
#include  "sim_common_enums.h"
#endif /* defined(__GEMINI__) || defined(GEMINI_PLUS) */

#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

/* 
 * Dual SIM: phb_ptr assignment will be done in layer4_module_context_selection
 * Single SIM: phb_ptr assignment will be done in phb_init
 */

phb_context_type phb_context[PHB_SIM_NUM];
phb_context_type *phb_ptr;

#if defined(__GEMINI__) || defined(GEMINI_PLUS) || defined(__SGLTE__)
module_type phb_current_mod;

extern ext_index_struct *ext_index_table;
extern ext_index_struct ext_index_table_context[PHB_SIM_NUM][EXT1_MAX_ENTRIES_COUNT];

#ifdef __PHB_USIM_SUPPORT__
extern ext_index_struct ext5_index_table_context[PHB_SIM_NUM][EXT5_MAX_ENTRIES_COUNT];
extern ext_index_struct *ext5_index_table;
/*
extern kal_uint8 *anr_index_table;
extern kal_uint8 anr_index_table_context[PHB_SIM_NUM][ANR_INDEX_MAX_ENTRIES_COUNT];
extern kal_uint8 *email_index_table;
extern kal_uint8 email_index_table_context[PHB_SIM_NUM][EMAIL_INDEX_MAX_ENTRIES_COUNT];
extern kal_uint8 *sne_index_table;
extern kal_uint8 sne_index_table_context[PHB_SIM_NUM][SNE_INDEX_MAX_ENTRIES_COUNT];
*/
#endif /* __PHB_USIM_SUPPORT__ */ 

#if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)
extern alpha_id_type *alpha_id_pinyin_PHB;
extern alpha_id_type alpha_id_pinyin_PHB_context[PHB_SIM_NUM][PHB_INDEX_MAX_ENTRIES_COUNT];
#endif  /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */

#if defined(__PHB_FDN_GET_NAME__) || defined(__ECALL_SUPPORT__)
l4_addr_bcd_struct *fdn_num_ptr;
l4_addr_bcd_struct fdn_num_context[PHB_SIM_NUM][FDN_INDEX_MAX_ENTRIES_COUNT];
l4_name_struct *fdn_name_ptr;
l4_name_struct fdn_name_context[PHB_SIM_NUM][FDN_INDEX_MAX_ENTRIES_COUNT];
#endif /* __PHB_FDN_GET_NAME__ */

#if defined(__ECALL_SUPPORT__)
l4_addr_bcd_struct *sdn_num_ptr;
l4_addr_bcd_struct sdn_num_context[PHB_SIM_NUM][2];
#endif /* __PHB_FDN_GET_NAME__ */

#else /* __GEMINI__ */

#if defined(__PHB_FDN_GET_NAME__) || defined(__ECALL_SUPPORT__)
l4_addr_bcd_struct fdn_num_context[FDN_INDEX_MAX_ENTRIES_COUNT];
l4_addr_bcd_struct *fdn_num_ptr = fdn_num_context;
l4_name_struct fdn_name_context[FDN_INDEX_MAX_ENTRIES_COUNT];
l4_name_struct *fdn_name_ptr = fdn_name_context;
#endif /* __PHB_FDN_GET_NAME__ */

#if defined(__ECALL_SUPPORT__)
l4_addr_bcd_struct sdn_num_context[2];
l4_addr_bcd_struct *sdn_num_ptr = sdn_num_context;
#endif /* __PHB_FDN_GET_NAME__ */

#endif /* __GEMINI__ */

#if !defined(__PHB_NO_CALL_LOG__)
#ifdef __PHB_RECORD_LN_TYPE_SEQ__
#if defined(__GEMINI__) || defined(GEMINI_PLUS)
kal_uint8 phb_ln_type_seq_context[PHB_SIM_NUM][PHB_TOTAL_LN_ENTRIES];
kal_uint8 *phb_ln_type_seq;
#else /* __GEMINI__ */
kal_uint8 phb_ln_type_seq[PHB_TOTAL_LN_ENTRIES];
#endif /* __GEMINI__ */
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */

#if (MAX_PHB_LN_ENTRY > 20)
phb_ln_entry_struct shifted_entry;
#endif 
#endif /* !defined(__PHB_NO_CALL_LOG__) */


/*****************************************************************************
 * FUNCTION
 *  phb_context_reset
 * DESCRIPTION
 *  Reset context of PHB. Including:
 *  1. Clean ECC.
 *  2. Reset dn_type to TYPE_NONE.
 *  3. Construct control_blocks.
 *  4. Reset state to STATE_NOT_READY.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void phb_context_reset()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PHB context shall not be NULL) */
    ASSERT(phb_ptr != NULL);

    kal_mem_set(&phb_ptr->ecc, 0, sizeof(sim_ecc_struct));
    phb_ptr->dn_type = TYPE_NONE;

    for (i = 0; i < PHB_CONCURRENCY_DEGREE; ++i)
    {
        phb_control_block_construct(&phb_ptr->control_block[i], i);
    }

    phb_ptr->state = PHB_STATE_NOT_READY;

#ifdef __PHB_USIM_SUPPORT__
    // for Emergency Service Category
    phb_desc_set_alpha_len(DATA_DESC_ECC, 30);
    phb_ptr->is_global = KAL_TRUE;
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    phb_ptr->anr_count = 0;
    phb_ptr->sne_count= 0;
    phb_ptr->email_count= 0;
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */ 
#endif /* __PHB_USIM_SUPPORT__ */

    phb_desc_set_alpha_len(DATA_DESC_ADN, 30);
    phb_desc_set_alpha_len(DATA_DESC_FDN, 30);
    phb_desc_set_alpha_len(DATA_DESC_BDN, 30);
    phb_desc_set_alpha_len(DATA_DESC_MSISDN, 30);
    phb_ptr->compare_digit = 0;
}


#if defined(__PHB_FDN_GET_NAME__) || defined(__ECALL_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  phb_init_fdn_context
 * DESCRIPTION
 *  This is for init fdn context
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_init_fdn_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__GEMINI__) || defined(GEMINI_PLUS) || defined(__SGLTE__)
    kal_uint8 i;
    for (i = 0; i < PHB_SIM_NUM; i++)
    {
        fdn_name_ptr = fdn_name_context[i];
        fdn_num_ptr = fdn_num_context[i];
        memset((kal_uint8*) fdn_name_ptr, 0x00, sizeof(l4_name_struct) * FDN_INDEX_MAX_ENTRIES_COUNT);
        memset((kal_uint8*) fdn_num_ptr, 0x00, sizeof(l4_addr_bcd_struct) * FDN_INDEX_MAX_ENTRIES_COUNT);
    }
#else /* __GEMINI__ */
    memset((kal_uint8*) fdn_name_ptr, 0x00, sizeof(l4_name_struct) * FDN_INDEX_MAX_ENTRIES_COUNT);
    memset((kal_uint8*) fdn_num_ptr, 0x00, sizeof(l4_addr_bcd_struct) * FDN_INDEX_MAX_ENTRIES_COUNT);
#endif /* __GEMINI__ */
}


/*****************************************************************************
 * FUNCTION
 *  phb_update_fdn_context
 * DESCRIPTION
 *  This is for update fdn context
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_update_fdn_context(kal_uint16 record_index, l4_name_struct* alpha_id, l4_addr_bcd_struct* tel_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4_name_struct* name = &fdn_name_ptr[record_index - 1];
    l4_addr_bcd_struct* num = &fdn_num_ptr[record_index - 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alpha_id != NULL)
    {
        memcpy((kal_uint8*) name, (kal_uint8*) alpha_id, sizeof(l4_name_struct));
    }
    else
    {
        memset((kal_uint8*) name, 0x00, sizeof(l4_name_struct));
    }

    if (tel_number != NULL)
    {
        memcpy((kal_uint8*) num, (kal_uint8*) tel_number, sizeof(l4_addr_bcd_struct));
    }
    else
    {
        memset((kal_uint8*) num, 0x00, sizeof(l4_addr_bcd_struct));
    }
}
#endif /* __PHB_FDN_GET_NAME__ */


#if defined(__ECALL_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  phb_init_fdn_context
 * DESCRIPTION
 *  This is for init fdn context
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_init_sdn_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__GEMINI__) || defined(GEMINI_PLUS) || defined(__SGLTE__)
    kal_uint8 i;
    for (i = 0; i < PHB_SIM_NUM; i++)
    {
        sdn_num_ptr = sdn_num_context[i];
        memset((kal_uint8*) sdn_num_ptr, 0x00, sizeof(l4_addr_bcd_struct) * 2);
    }
#else /* __GEMINI__ */
    memset((kal_uint8*) sdn_num_ptr, 0x00, sizeof(l4_addr_bcd_struct) * 2);
#endif /* __GEMINI__ */
}


/*****************************************************************************
 * FUNCTION
 *  phb_update_fdn_context
 * DESCRIPTION
 *  This is for update fdn context
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_update_sdn_context(kal_uint16 record_index, l4_name_struct* alpha_id, l4_addr_bcd_struct* tel_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4_addr_bcd_struct* num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record_index == phb_ptr->data_desc[DATA_DESC_SDN].record_num)
    {
        num = &sdn_num_ptr[1];
    }
    else if (record_index == phb_ptr->data_desc[DATA_DESC_SDN].record_num - 1)
    {
        num = &sdn_num_ptr[0];
    }
    else
    {
        return;
    }

    if (tel_number != NULL)
    {
        memcpy((kal_uint8*) num, (kal_uint8*) tel_number, sizeof(l4_addr_bcd_struct));
    }
    else
    {
        memset((kal_uint8*) num, 0x00, sizeof(l4_addr_bcd_struct));
    }
}
#endif /* __PHB_FDN_GET_NAME__ */


#if !defined(__PHB_NO_CALL_LOG__)
#ifdef __PHB_RECORD_LN_TYPE_SEQ__
#ifdef __PHB_ALWAYS_SYNC_SIM_LN__
/*****************************************************************************
 * FUNCTION
 *  phb_clear_lnd_type_seq
 * DESCRIPTION
 *  Clear the lnd type sequence.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void phb_clear_lnd_type_seq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i = 0, j = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (j < PHB_TOTAL_LN_ENTRIES || phb_ln_type_seq[j] == 0xff)
    {
        if (phb_ln_type_seq[j] != PHB_LND)
        {
            phb_ln_type_seq[i] = phb_ln_type_seq[j];
            i++;
        }
        j++;
    }
    while (i < PHB_TOTAL_LN_ENTRIES)
    {
        phb_ln_type_seq[i] = 0xff;
        i++;
    }
}
#endif /* __PHB_ALWAYS_SYNC_SIM_LN__ */ 


/*****************************************************************************
 * FUNCTION
 *  phb_set_ln_type_seq
 * DESCRIPTION
 *  Set the ln type sequence by given type.
 * PARAMETERS
 *  num         [IN]        
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void phb_set_ln_type_seq(kal_uint16 num, kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num > PHB_TOTAL_LN_ENTRIES)
    {
        ASSERT(0);
        num = PHB_TOTAL_LN_ENTRIES;
    }
    for (i = 0; i < num; i++)
    {
        phb_ln_type_seq[i] = type;
    }
}

#if (MAX_PHB_LN_ENTRY > 20)


/*****************************************************************************
 * FUNCTION
 *  phb_get_ln_total_entry
 * DESCRIPTION
 *  Get the total number of ln entry by the given type.
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 phb_get_ln_total_entry(kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i = 0;
    kal_uint16 total = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < PHB_TOTAL_LN_ENTRIES && phb_ln_type_seq[i] != 0xff)
    {
        if (phb_ln_type_seq[i] == type)
        {
            total++;
        }
        i++;
    }
    return total;
}
#endif /* (MAX_PHB_LN_ENTRY > 20) */ /* MAX_PHB_LN_ENTRY > 20 */
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
#endif /* !defined(__PHB_NO_CALL_LOG__) */


/*****************************************************************************
 * FUNCTION
 *  phb_alloc_control_block
 * DESCRIPTION
 *  Allocate of control_block.
 * PARAMETERS
 *  void
 *  control_block(?)        [IN]        The control_block
 * RETURNS
 *  The allocated control_block is success, NULL otherwise.
 *****************************************************************************/
control_block_type *phb_alloc_control_block()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    control_block_type *control_block = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PHB context shall not be NULL) */
    ASSERT(phb_ptr != NULL);

    for (i = 0; i < PHB_CONCURRENCY_DEGREE; ++i)
    {

        if (phb_ptr->control_block[i].is_allocated == KAL_TRUE)
        {
            continue;
        }

        control_block = &phb_ptr->control_block[i];

        phb_control_block_construct(control_block, i);
        control_block->is_allocated = KAL_TRUE;

        break;
    }

    return control_block;
}


/*****************************************************************************
 * FUNCTION
 *  phb_free_control_block
 * DESCRIPTION
 *  Destructs / resets the control block.
 * PARAMETERS
 *  control_block       [IN]        The control_block to set
 * RETURNS
 *  void
 *****************************************************************************/
void phb_free_control_block(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(control_block->is_allocated == KAL_TRUE);

    kal_mem_set(control_block, 0, sizeof(control_block_type));
    /* control_block->is_allocated = KAL_FALSE; */
}   /* end of control_block_set_destruct */


/*****************************************************************************
 * FUNCTION
 *  phb_reset_all_control_blocks
 * DESCRIPTION
 *  Reset all control_blocks
 * PARAMETERS
 *  void
 *  control_block(?)        [IN]        The control_block
 * RETURNS
 *  First control_block.(?)
 *****************************************************************************/
void phb_reset_all_control_blocks()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    control_block_type *control_block = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PHB context shall not be NULL) */
    ASSERT(phb_ptr != NULL);

    for (i = 0; i < PHB_CONCURRENCY_DEGREE; ++i)
    {

        control_block = &phb_ptr->control_block[i];

        phb_control_block_construct(control_block, i);

        control_block->is_allocated = KAL_FALSE;
    }
}


#if defined(__GEMINI__) || defined(GEMINI_PLUS) || defined(__SGLTE__)
/*****************************************************************************
 * FUNCTION
 *  phb_context_selection
 * DESCRIPTION
 *  This is deinit() function of PHB module.
 *  This function finalize all the context variables required for PHB module
 * PARAMETERS
 *  void
 * RETURNS
 *  True if succeed.
 *****************************************************************************/
void phb_context_selection(kal_uint8 sim_interface)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 which_sim = sim_interface;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_current_mod = MOD_PHB + which_sim;
    
    /* assign context */
    phb_ptr = &phb_context[which_sim];
    #ifdef __PHB_RECORD_LN_TYPE_SEQ__
    phb_ln_type_seq = phb_ln_type_seq_context[which_sim];
    #endif

    ext_index_table = ext_index_table_context[which_sim];
    #ifdef __PHB_USIM_SUPPORT__
    ext5_index_table = ext5_index_table_context[which_sim];
    #endif /* __PHB_USIM_SUPPORT__ */

    #if defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__)
      alpha_id_pinyin_PHB = alpha_id_pinyin_PHB_context[which_sim];
    #endif  /* defined(__PINYIN_SORTING_ZI__) || defined(__PINYIN_SORTING_KA__) */
#if defined(__PHB_FDN_GET_NAME__) || defined(__ECALL_SUPPORT__)
    fdn_name_ptr = fdn_name_context[which_sim];
    fdn_num_ptr = fdn_num_context[which_sim];
#endif
#if defined(__ECALL_SUPPORT__)
    sdn_num_ptr = sdn_num_context[which_sim];
#endif
}
#endif /* __GEMINI__ */
