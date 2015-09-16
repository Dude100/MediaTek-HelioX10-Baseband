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
 * phb_sap.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines SAP functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <stdio.h>

//#include "kal_release.h"        /* Basic data type */

//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "stack_ltlcom.h" /* Task message communiction */

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
//#include "phb_control_block.h"
#include "phb_config.h"
#include "phb_data_desc.h"
#include "phb_data_entry_table.h"
#include "phb_pindex.h"
#include "phb_name_num_index.h"
//#include "nvram_data_items.h"

#include "phb_context.h"

#include "phb_pindex.h"
#include "phb_utils.h"

#include "phb_sap.h"

#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "string.h"
#include "kal_public_api.h"
#include "nvram_editor_data_item.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_SAP_C_

static char const *const PHB_AT_CPBS =
    "+CPBS: (\"DC\", \"EN\", \"FD\", \"LD\", \"MC\", \"ME\", \"MT\", \"ON\", \"RC\", \"SM\"";
static char PHB_AT_TEST_BUF[32];

#ifdef __PHB_USIM_SUPPORT__
#if defined(__GEMINI__) || defined(GEMINI_PLUS) || defined(__SGLTE__)
extern kal_bool is_usim_type(sim_interface_enum which_sim);
#else /* __GEMINI__ */
extern kal_bool is_usim_type(void);
#endif /* __GEMINI__ */
#endif /* __PHB_USIM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  l4cphb_phonebook_status_req
 * DESCRIPTION
 *  This is l4cphb_phonebook_status_req function of PHB module.
 *  Handles query phonebook memory satus.
 * PARAMETERS
 *  storage         [IN]        
 *  total           [?]         
 *  available       [?]         
 *  ilm_ptr(?)      [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
phb_errno_enum l4cphb_phonebook_status_req(phb_storage_enum storage, kal_uint16 *total, kal_uint16 *available)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_desc_type *data_desc_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*    kal_trace(TRACE_FUNC, FUNC_L4CPHB_STATUS_REQ); */

    if (storage == PHB_STORAGE_NVRAM)
    {
        data_desc_entry = &phb_ptr->data_desc[DATA_DESC_PHB];
    }
    else
    {
        data_desc_entry = &phb_ptr->data_desc[DATA_DESC_ADN];
    }

    *total = data_desc_entry->record_num;
    *available = data_desc_entry->free_count;

    return PHB_ERRNO_SUCCESS;
}   /* end of l4cphb_status_req */


/*****************************************************************************
 * FUNCTION
 *  l4cphb_status_req
 * DESCRIPTION
 *  This is phb_approve_handler function of PHB module.
 *  Handles write request from L4C.
 * PARAMETERS
 *  type            [IN]        
 *  total           [?]         
 *  available       [?]         
 *  ilm_ptr(?)      [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
phb_errno_enum l4cphb_status_req(phb_type_enum type, kal_uint16 *total, kal_uint16 *available)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_desc_type *data_desc_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*    kal_trace(TRACE_FUNC, FUNC_L4CPHB_STATUS_REQ); */

    switch (type)
    {
        case PHB_FDN:
            data_desc_entry = &phb_ptr->data_desc[DATA_DESC_FDN];
            break;

        case PHB_MSISDN:
            data_desc_entry = &phb_ptr->data_desc[DATA_DESC_MSISDN];
            break;

        case PHB_SDN:
            data_desc_entry = &phb_ptr->data_desc[DATA_DESC_SDN];
            break;

        case PHB_ECC:
            *total = phb_ptr->ecc.num_ecc;
            *available = 0;
            return PHB_ERRNO_SUCCESS;
        default:
            *total = 0;
            *available = 0;
            return PHB_ERRNO_FAIL;
    }

    *total = data_desc_entry->record_num;
    *available = data_desc_entry->free_count;

    return PHB_ERRNO_SUCCESS;
}   /* end of l4cphb_status_req */


/*****************************************************************************
 * FUNCTION
 *  l4c_phb_get_file_info
 * DESCRIPTION
 *  This is for L4C to get the information about phb related file
 * PARAMETERS
 *  type            [IN]        
 *  total           [?]         
 *  available       [?]         
 *  ilm_ptr(?)      [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
phb_errno_enum l4c_phb_get_file_info(kal_uint8 type, phb_storage_enum storage, l4cphb_file_info_struct* file_info, kal_uint8 occurrence)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_desc_type *data_desc_entry = NULL;
    data_desc_type *ext_data_desc_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_L4CPHB_GET_FILE_INFO, type, storage);

    if (phb_ptr->state != PHB_STATE_READY)
    {
        return PHB_ERRNO_FAIL;
    }

    memset(file_info, 0x00, sizeof(l4cphb_file_info_struct));

    if (storage == PHB_STORAGE_NVRAM)
    {
        if (type == PHB_PHONEBOOK)
        {
            data_desc_entry = &phb_ptr->data_desc[DATA_DESC_PHB];
            	
            if (data_desc_entry->is_support == KAL_TRUE)
            {
                file_info ->max_name_len = 40;
                file_info ->max_num_len = 20;
                file_info ->free_num = data_desc_entry->free_count;
                file_info ->total_num = data_desc_entry->record_num;
                file_info ->ext_free_num = 0;
            }

            kal_trace(TRACE_FUNC, FUNC_L4CPHB_GET_FILE_INFO_DETAIL, 
                file_info ->max_name_len,
                file_info ->max_num_len,
                file_info ->free_num,
                file_info ->total_num,
                file_info ->ext_free_num);
    		    	
            return PHB_ERRNO_SUCCESS;
        }
        else
        {
            ASSERT(0);
        }
    }
    else
    {
        switch (type)
        {
            case PHB_PHONEBOOK:
                /* SIM: ADN + EXT1; USIM: ADN + EXT1 */
                data_desc_entry = &phb_ptr->data_desc[DATA_DESC_ADN];
                ext_data_desc_entry = &phb_ptr->data_desc[DATA_DESC_EXT1];
                break;

            case PHB_FDN:
                /* SIM: FDN + EXT2; USIM: FDN + EXT2 */
                data_desc_entry = &phb_ptr->data_desc[DATA_DESC_FDN];
                ext_data_desc_entry = &phb_ptr->data_desc[DATA_DESC_EXT2];
                break;
            
            case PHB_MSISDN:
                /* SIM: MSISDN + EXT1; USIM: MSISDN + EXT5 */
                data_desc_entry = &phb_ptr->data_desc[DATA_DESC_MSISDN];
            #ifdef __PHB_USIM_SUPPORT__
                if (phb_util_is_usim(phb_which_sim_ex()))
                {
                    ext_data_desc_entry = &phb_ptr->data_desc[DATA_DESC_EXT5];
                }
                else
            #endif
                {
                    ext_data_desc_entry = &phb_ptr->data_desc[DATA_DESC_EXT1];
                }
                break;
            
            case PHB_BDN:
                /* SIM: BDN + EXT4; USIM: BDN + EXT4 */
                data_desc_entry = &phb_ptr->data_desc[DATA_DESC_BDN];
                ext_data_desc_entry = &phb_ptr->data_desc[DATA_DESC_EXT4];
                break;
            
            case PHB_SDN:
                /* SIM: SDN + EXT3; USIM: SDN + EXT3 */
                data_desc_entry = &phb_ptr->data_desc[DATA_DESC_SDN];
                ext_data_desc_entry = &phb_ptr->data_desc[DATA_DESC_EXT3];
                break;
                
            case PHB_EXT1:
                data_desc_entry = &phb_ptr->data_desc[DATA_DESC_EXT1];
                ext_data_desc_entry = NULL;
                break;
                
            case PHB_ECC:
            #ifdef __PHB_USIM_SUPPORT__
                if (is_usim_type(PHB_WHICH_SIM))
                {
                    file_info ->max_name_len = phb_ptr->data_desc[DATA_DESC_ECC].alpha_length;
                }
                else
            #endif /* __PHB_USIM_SUPPORT__ */
                {
                    file_info ->max_name_len = 0;
                }
                file_info ->max_num_len = 6;
                file_info ->free_num = 0; /* read only */
                file_info ->total_num = phb_ptr->ecc.num_ecc;
                file_info ->ext_free_num = 0; /* no ext file */

                kal_trace(TRACE_FUNC, FUNC_L4CPHB_GET_FILE_INFO_DETAIL, 
                    file_info ->max_name_len,
                    file_info ->max_num_len,
                    file_info ->free_num,
                    file_info ->total_num,
                    file_info ->ext_free_num);

                return PHB_ERRNO_SUCCESS;
                
        #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
            case PHB_SNE:
                data_desc_entry = &phb_ptr->data_desc[DATA_DESC_SNE + occurrence - 1];
                ext_data_desc_entry = NULL;
                if (!phb_desc_is_type2_file(DATA_DESC_SNE + occurrence - 1))
                {
                    data_desc_entry->free_count = phb_ptr->data_desc[DATA_DESC_ADN].free_count;
                }
                break;
                
            case PHB_AAS:
                data_desc_entry = &phb_ptr->data_desc[DATA_DESC_AAS];
                ext_data_desc_entry = NULL;
                break;
                
            case PHB_ANR:
                data_desc_entry = &phb_ptr->data_desc[DATA_DESC_ANR + occurrence - 1];
                ext_data_desc_entry = &phb_ptr->data_desc[DATA_DESC_EXT1];
                if (!phb_desc_is_type2_file(DATA_DESC_ANR + occurrence - 1))
                {
                    data_desc_entry->free_count = phb_ptr->data_desc[DATA_DESC_ADN].free_count;
                }
                break;
                
            case PHB_GAS:
                data_desc_entry = &phb_ptr->data_desc[DATA_DESC_GAS];
                ext_data_desc_entry = NULL;
                break;
                
            case PHB_GRP:
                data_desc_entry = &phb_ptr->data_desc[DATA_DESC_GRP];
                data_desc_entry->free_count = phb_ptr->data_desc[DATA_DESC_ADN].free_count;
                ext_data_desc_entry = NULL;
                break;
                
            case PHB_EMAIL:
                data_desc_entry = &phb_ptr->data_desc[DATA_DESC_EMAIL + occurrence - 1];
                if (!phb_desc_is_type2_file(DATA_DESC_EMAIL + occurrence - 1))
                {
                    data_desc_entry->free_count = phb_ptr->data_desc[DATA_DESC_ADN].free_count;
                }
                ext_data_desc_entry = NULL;
                break;
        #endif /* __PHB_USIM_SYNC__ */
        
        #ifdef __PHB_USIM_SYNC__
            case PHB_PBC:
                data_desc_entry = &phb_ptr->data_desc[DATA_DESC_PBC];
                data_desc_entry->free_count = phb_ptr->data_desc[DATA_DESC_ADN].free_count;
                ext_data_desc_entry = NULL;
                break;
        #endif /* __PHB_USIM_SYNC__ */

            default:
                return PHB_ERRNO_FAIL;
        }
    }

    if (data_desc_entry->is_support == KAL_TRUE && data_desc_entry->record_num != 0)
    {
        /* is_support only check the sim service table;
           and sim file info result may be false, so should check record_num != 0 */
        file_info ->max_name_len = data_desc_entry->alpha_length;
        file_info ->max_num_len = 20;
        file_info ->free_num = data_desc_entry->free_count;
        file_info ->total_num = data_desc_entry->record_num;
        if (ext_data_desc_entry != NULL)
        {
            file_info ->ext_free_num = ext_data_desc_entry->free_count;
        }
    }

    kal_trace(TRACE_FUNC, FUNC_L4CPHB_GET_FILE_INFO_DETAIL, 
        file_info ->max_name_len,
        file_info ->max_num_len,
        file_info ->free_num,
        file_info ->total_num,
        file_info ->ext_free_num);

    return PHB_ERRNO_SUCCESS;
}


/*****************************************************************************
* FUNCTION
 *  l4c_phb_get_ln_file_info
 * DESCRIPTION
 *  This is for L4C to get the information about phb ln related file
 * PARAMETERS
 *  type            [IN]        
 *  total           [?]         
 *  available       [?]         
 *  ilm_ptr(?)      [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
phb_errno_enum l4c_phb_get_ln_file_info(kal_uint8 type, phb_storage_enum storage, l4cphb_file_info_struct* file_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_desc_type *data_desc_entry = NULL;
    data_desc_type *ext_data_desc_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_L4CPHB_GET_LN_FILE_INFO, type, storage);

   /* Caller should call this after receive PHB ready indication, we have got the ln type at that time */
    if (phb_ptr->state == PHB_STATE_NULL)
    {
        return PHB_ERRNO_FAIL;
    }

    memset(file_info, 0x00, sizeof(l4cphb_file_info_struct));

    if (storage == PHB_STORAGE_NVRAM)
    {
        ASSERT(0);
    }
    else if (storage != PHB_STORAGE_NVRAM && storage != PHB_STORAGE_NONE)
    {
    #ifdef __PHB_ACCESS_SIM_LN__
        switch (type)
        {
            case PHB_LND: /* now only support SIM */
                /* SIM: LND + EXT1; USIM: OCI + EXT5 */
                data_desc_entry = &phb_ptr->ln_data_desc[LN_DATA_DESC_LND];
                ext_data_desc_entry = NULL; /* now not support EXT1 */
                break;
     
            default:
                return PHB_ERRNO_FAIL;
        }
    #else /* __PHB_ACCESS_SIM_LN__ */
        ASSERT(0);
    #endif /* __PHB_ACCESS_SIM_LN__ */
    }
    else
    {
        ASSERT(0);
    }

    if (data_desc_entry->is_support == KAL_TRUE && data_desc_entry->record_num != 0)
    {
        /* is_support only check the sim service table;
           and sim file info result may be false, so should check record_num != 0 */
        file_info->max_name_len = data_desc_entry->record_size - 14;
        file_info->max_num_len = 10;
        file_info->free_num = data_desc_entry->free_count;
        file_info->total_num = data_desc_entry->record_num;
        if (ext_data_desc_entry != NULL)
        {
            file_info->ext_free_num = ext_data_desc_entry->free_count;
        }
        else
        {
            file_info->ext_free_num = 0;
        }
    }

    kal_trace(TRACE_FUNC, FUNC_L4CPHB_GET_FILE_INFO_DETAIL, 
        file_info->max_name_len,
        file_info->max_num_len,
        file_info->free_num,
        file_info->total_num,
        file_info->ext_free_num);

    return PHB_ERRNO_SUCCESS;
}


/*****************************************************************************
* FUNCTION
*  l4cphb_mode_req
*
* DESCRIPTION
*   When dialling mode is switched to SIM by L4C, PHB must be also informed. 
*   L4C invokes l4c_mode_req() to inform PHB.
*
*   Note: This function should only be called after request of SIM_DIAL_MODE_REQ 
*        is successful.
*
* PARAMETERS
*  ilm_ptr     IN       The primitives
*
* RETURNS
*  none.
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  l4cphb_test_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool l4cphb_test_storage(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_L4CPHB_TEST_STORAGE);

    *buffer = (kal_uint8 const*)PHB_AT_CPBS;

    return KAL_TRUE;
}   /* end of l4cphb_test_storage */


/*****************************************************************************
 * FUNCTION
 *  l4cphb_test_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool l4cphb_test_index(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_L4CPHB_TEST_INDEX);

    kal_sprintf(PHB_AT_TEST_BUF, "+CPBR: (1-%d), %d, %d", PHB_INDEX_MAX_ENTRIES_COUNT, L4_MAX_ADDR_BCD, MAX_PS_NAME_SIZE );
    *buffer = (kal_uint8 const*)PHB_AT_TEST_BUF;

    return KAL_TRUE;
}   /* end of l4cphb_test_index */


/*****************************************************************************
 * FUNCTION
 *  l4cphb_test_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool l4cphb_test_text(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_L4CPHB_TEST_TEXT);

    kal_sprintf(PHB_AT_TEST_BUF, "+CPBF: %d, %d", L4_MAX_ADDR_BCD, MAX_PS_NAME_SIZE );
    *buffer = (kal_uint8 const*)PHB_AT_TEST_BUF;

    return KAL_TRUE;
}   /* end of l4cphb_test_text */


/*****************************************************************************
 * FUNCTION
 *  l4cphb_test_write_parameter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool l4cphb_test_write_parameter(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_L4CPHB_TEST_WRITE_PARAMETER);

    kal_sprintf(
        PHB_AT_TEST_BUF,
        "+CPBW: (%d), %d, (145, 129), %d",
        PHB_INDEX_MAX_ENTRIES_COUNT,
        L4_MAX_ADDR_BCD,
        MAX_PS_NAME_SIZE );
    *buffer = (kal_uint8 const*)PHB_AT_TEST_BUF;

    return KAL_TRUE;
}   /* end of l4cphb_test_write_parameter */


/*****************************************************************************
 * FUNCTION
 *  l4cphb_alloc_peer_buf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  peer_buf_ptr        [IN]        
 *  count               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 *l4cphb_alloc_peer_buf(peer_buff_struct **peer_buf_ptr, kal_uint16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cphb_phb_entry_array_struct *phb_entry_array;

    kal_uint8 *actual_pdu_ptr;
    kal_uint16 pdu_length;
    kal_uint16 size_l4cphb_phb_entry_array = sizeof(l4cphb_phb_entry_array_struct);
    kal_uint16 size_all_phb_entry = (sizeof(phb_entry_struct) * count);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_trace(TRACE_FUNC, FUNC_L4CPHB_ALLOC_PEER_BUF); */

   /**
    * Calculate size of peer buffer needed to allocate for storing 
    * phb_entry_struct array.
    *
    * Though construct_peer_buff() always returns a buffer aligned to 
    * the word-boundary (ie, 4), get_pdu_ptr() does not. Instead, 
    * get_pdu_ptr() returns 6 bytes offset to where construct_peer_buff() 
    * pointed. That introduces potential alignment problem which makes 
    * direct type-casting danger.
    * Due to this potential alignment problem, this function try to avoid
    * it by aligning the address before type-casting the allocated 
    * peer-buffer (ie, increment the address returned by get_pdu_ptr()
    * to 8, instead of 6).  But, before aligning the address, size of buffer
    * to be allocated should be incremented (ie, 2), if alignment is 
    * needed; otherwise allocated buffer will be short of 2 bytes and 
    * as a result the foot-print of peer-buffer is corrupted.
    */
    /* pdu_length needed to store entire phb_enty_struct array */
    pdu_length = size_l4cphb_phb_entry_array + size_all_phb_entry;
    /* pdu_length incremented due to un-aligned get_pdu_ptr() */
    pdu_length += (get_32bits_aligned_val(sizeof(peer_buff_struct)) - sizeof(peer_buff_struct));

    /* Construct peer buffer */
    *peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
    actual_pdu_ptr = (kal_uint8*) get_32bits_aligned_val(get_peer_buff_pdu(*peer_buf_ptr, &pdu_length));

    phb_entry_array = (l4cphb_phb_entry_array_struct*) actual_pdu_ptr;
    phb_entry_array->no_array = count;
    phb_entry_array->array = (phb_entry_struct*) (actual_pdu_ptr + size_l4cphb_phb_entry_array);

    return actual_pdu_ptr;
}   /* end of l4cphb_alloc_peer_buf */


#if !defined(__PHB_NO_CALL_LOG__)
/*****************************************************************************
 * FUNCTION
 *  l4cphb_alloc_ln_peer_buf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  peer_buf_ptr        [IN]        
 *  count               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *l4cphb_alloc_ln_peer_buf(peer_buff_struct **peer_buf_ptr, kal_uint16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cphb_phb_ln_entry_array_struct *phb_entry_array;
    kal_uint8 *actual_pdu_ptr;
    kal_uint16 pdu_length;
    kal_uint16 size_l4cphb_phb_entry_array = sizeof(l4cphb_phb_ln_entry_array_struct);

#if (MAX_PHB_LN_ENTRY > 10)
    kal_uint16 size_all_phb_entry = (sizeof(phb_ln_entry_struct) * PHB_MAX_LN_ENTRIES);
#else 
    kal_uint16 size_all_phb_entry = (sizeof(phb_ln_entry_struct) * PHB_MAX_LNM_ENTRIES);
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pdu_length = size_l4cphb_phb_entry_array + size_all_phb_entry;
    /* pdu_length incremented due to un-aligned get_pdu_ptr() */
    pdu_length += (get_32bits_aligned_val(sizeof(peer_buff_struct)) - sizeof(peer_buff_struct));

    /* Construct peer buffer */
    *peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
    actual_pdu_ptr = (kal_uint8*) get_32bits_aligned_val(get_peer_buff_pdu(*peer_buf_ptr, &pdu_length));

    phb_entry_array = (l4cphb_phb_ln_entry_array_struct*) actual_pdu_ptr;
    phb_entry_array->no_array = count;
    phb_entry_array->array = (phb_ln_entry_struct*) (actual_pdu_ptr + size_l4cphb_phb_entry_array);

    return actual_pdu_ptr;
}
#endif /* !defined(__PHB_NO_CALL_LOG__) */


/*****************************************************************************
 * FUNCTION
 *  l4cphb_get_index_by_location
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type                [IN]        
 *  storage             [IN]        
 *  record_index        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 l4cphb_get_index_by_location(kal_uint8 type, kal_uint8 storage, kal_uint16 record_index)
{
#ifdef __PHB_SORT_ENABLE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_entry_table_type *desc_table = NULL;
    pindex_type *name_index = NULL;
    kal_uint16 i, index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == PHB_PHONEBOOK)
    {
        desc_table = (data_entry_table_type*) & phb_ptr->indices.phb_index.data_entry_table;
        name_index = (pindex_type*) & phb_ptr->indices.phb_index.name_index;
    }

    if (desc_table && name_index->table)
    {
        for (i = 0; i < name_index->used_count; i++)
        {
            index = name_index->table[i].position;
            if (desc_table->table[index].storage == storage && desc_table->table[index].record_index == record_index)
            {
                return i + 1;
            }
        }
    }
    return (kal_uint16) PHB_INVALID_VALUE;
#else /* __PHB_SORT_ENABLE__ */ 
    return (kal_uint16) 1;  /* must be a valid value */
#endif /* __PHB_SORT_ENABLE__ */ 
}

#if defined(__PINYIN_SORTING_KA__)      /* Use propietary convert function to convert Chinese to PinYin. */
extern const signed char *GetPYString(unsigned char *HZ);
#endif 


/*****************************************************************************
 * FUNCTION
 *  l4cphb_get_alpha_list_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  list        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cphb_get_alpha_list_req(phb_type_enum type, kal_uint16 *list)
{
#ifdef __PHB_SORT_ENABLE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool valid_ch;
    kal_uint8 index = 0xff, j;
    kal_uint16 i;
    data_entry_table_type *data_table;
    pindex_type *name_index;
    alpha_id_type *alpha_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < 26; j++)
    {
        list[j] = 0;
    }

    if (type == PHB_PHONEBOOK || type == PHB_FDN || type == PHB_BDN)
    {
        if (type == PHB_PHONEBOOK)
        {
            data_table = &(phb_ptr->indices.phb_index.data_entry_table);
            name_index = &(phb_ptr->indices.phb_index.name_index);
        }
        else if (type == PHB_FDN)
        {
            data_table = &(phb_ptr->indices.fdn_index.data_entry_table);
            name_index = &(phb_ptr->indices.fdn_index.name_index);
        }
        else // if (type == PHB_BDN)
        {
            data_table = &(phb_ptr->indices.bdn_index.data_entry_table);
            name_index = &(phb_ptr->indices.bdn_index.name_index);
        }

        if (name_index->used_count == 0)
        {
            return KAL_FALSE;
        }
        for (i = 0; i < name_index->used_count; i++)
        {
            alpha_ptr = &(data_table->table[name_index->table[i].position].alpha_id);
            if (alpha_ptr->charset == CHARSET_ASCII)
            {
                if (alpha_ptr->data[0] >= 'a' && alpha_ptr->data[0] <= 'z')
                {
                    /* lower case */
                    index = alpha_ptr->data[0] - 'a';
                    valid_ch = KAL_TRUE;
                }
                else if (alpha_ptr->data[0] >= 'A' && alpha_ptr->data[0] <= 'Z')
                {
                    /* upper case */
                    index = alpha_ptr->data[0] - 'A';
                    valid_ch = KAL_TRUE;
                }
                else
                {
                    valid_ch = KAL_FALSE;
                }

                if (list[index] == 0 && valid_ch)
                {
                    for (j = 0; j < index; j++)
                        if (list[j] == 0)
                        {
                            list[j] = i + 1;
                        }
                    list[index] = i + 1;
                }
            }
            /* UCS2 String */
            else if (alpha_ptr->charset == CHARSET_UCS2)
            {
                if ((alpha_ptr->data[0] == 0x00) && (alpha_ptr->data[1] >= 'a') && (alpha_ptr->data[1] <= 'z'))
                {
                    /* lower case */
                    index = alpha_ptr->data[1] - 'a';
                    valid_ch = KAL_TRUE;
                }
                else if ((alpha_ptr->data[0] == 0x00) && (alpha_ptr->data[1] >= 'A') && (alpha_ptr->data[1] <= 'Z'))
                {
                    /* upper case */
                    index = alpha_ptr->data[1] - 'A';
                    valid_ch = KAL_TRUE;
                }
            #if defined(__PINYIN_SORTING_KA__)      // || defined(__PINYIN_SORTING_ZI__)   /*Use propietary convert function to convert Chinese to PinYin.*/
                else if ((alpha_ptr->data[0] != 0x00) && (alpha_ptr->data[1] != 0x00))
                {
                    kal_uint8 code[2];
                    const kal_int8 *pString;

                    valid_ch = KAL_FALSE;

                    code[0] = alpha_ptr->data[1];
                    code[1] = alpha_ptr->data[0];
                    if ((*((kal_uint16*) code) >= 0x4e00) &&
                        (*((kal_uint16*) code) <= 0x9fa5) && (pString = GetPYString(code)) != NULL)
                    {
                        if ((pString[0] >= 'a') && (pString[0] <= 'z'))
                        {
                            index = pString[0] - 'a';
                            valid_ch = KAL_TRUE;
                        }
                    }
                }
            #endif /* defined(__PINYIN_SORTING_KA__) */ 
                else
                {
                    valid_ch = KAL_FALSE;
                }

                if (list[index] == 0 && valid_ch)
                {
                    for (j = 0; j < index; j++)
                        if (list[j] == 0)
                        {
                            list[j] = i + 1;
                        }
                    list[index] = i + 1;
                }
            }
        }

        if (index != 0xff)
            for (j = index; j < 26; j++)
            {
                list[j] = list[index];
            }
        else
            for (j = 0; j < 26; j++)
            {
                list[j] = 1;
            }
    }
#endif /* __PHB_SORT_ENABLE__ */ 
    return KAL_TRUE;
}

