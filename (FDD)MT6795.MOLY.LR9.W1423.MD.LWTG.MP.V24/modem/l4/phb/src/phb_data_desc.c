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
 * phb_data_desc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the data descriptor. It maintains number of records, record size, free count,
 *   bits of the bitmap, free list implemented in bitmap.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#include "kal_release.h"        /* Basic data type */

//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "app_ltlcom.h" /* Task message communiction */

#include "kal_trace.h"
#include "phb_trc.h"

#include "sim_common_enums.h"
// #include "nvram_editor_data_item.h"
//#include "custom_nvram_editor_data_item.h"

//#include "l4_common.h"
#include "ps2sim_struct.h"

#include "l4c2phb_enums.h"
#include "l4c2phb_struct.h"

/* Prerequisite of phb_context.h */
#include "phb_defs.h"
//#include "phb_control_block.h"
#include "phb_config.h"
#include "phb_data_desc.h"
//#include "phb_data_entry_table.h"
//#include "phb_pindex.h"
//#include "phb_name_num_index.h"
#include "phb_context.h"
#include "phb_utils.h"

//#include "nvram_data_items.h"
//#include "nvram_user_defs.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "ps_public_enum.h"
#include "nvram_data_items.h"
#include "ps_public_struct.h"

#ifdef __PHB_USIM_SUPPORT__
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
extern kal_uint8 free_bitmap_ADN[PHB_SIM_NUM][PHB_MAX_PBR_ENTRIES][FREE_BITMAP_ADN_BYTES];
extern kal_uint8 free_bitmap_TYPE2_FILE[PHB_SIM_NUM][PHB_TYPE2_BITMAP_COUNT][FREE_BITMAP_TYPE2_FILE_BYTES];
#endif 
#endif

#ifdef __PHB_USIM_SUPPORT__
kal_uint16 phb_desc_get_used_file_id(kal_uint16 g_file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!phb_ptr->is_global)
    {
        switch (g_file_id)
        {
        #ifdef __PHB_USIM_SUPPORT__
            case FILE_G_EXT1_IDX:
                return FILE_U_EXT1_IDX;

            case FILE_G_ADN_IDX:
                return FILE_U_ADN_IDX;

            case FILE_G_PBR_IDX:
                return FILE_U_PBR_IDX;
                
        #ifdef __PHB_USIM_SYNC__                
            case FILE_G_PBC_IDX:
                return FILE_U_PBC_IDX;
                
            case FILE_G_PSC_IDX:
                return FILE_U_PSC_IDX;
                
            case FILE_G_CC_IDX:
                return FILE_U_CC_IDX;
                
            case FILE_G_UID_IDX:
                return FILE_U_UID_IDX;
                
            case FILE_G_PUID_IDX:
                return FILE_U_PUID_IDX;
        #endif /* __PHB_USIM_SYNC__ */
        
        #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
            case FILE_G_IAP_IDX:
                return FILE_U_IAP_IDX;

            case FILE_G_GRP_IDX:
                return FILE_U_GRP_IDX;

            case FILE_G_ANR_IDX:
                return FILE_U_ANR_IDX;

            case FILE_G_SNE_IDX:
                return FILE_U_SNE_IDX;

            case FILE_G_EMAIL_IDX:
                return FILE_U_EMAIL_IDX;

            case FILE_G_GAS_IDX:
                return FILE_U_GAS_IDX;

            case FILE_G_CCP1_IDX:
                return FILE_U_CCP1_IDX;
                
            case FILE_G_AAS_IDX:
                return FILE_U_AAS_IDX;
        #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */ 
        #endif /* __PHB_USIM_SUPPORT__ */
            default:
            break;
        }
    }
    else
    {
        switch (g_file_id)
        {
        #ifdef __PHB_USIM_SUPPORT__
            case FILE_U_EXT1_IDX:
                return FILE_G_EXT1_IDX;

            case FILE_U_ADN_IDX:
                return FILE_G_ADN_IDX;

            case FILE_U_PBR_IDX:
                return FILE_G_PBR_IDX;
                
        #ifdef __PHB_USIM_SYNC__                
            case FILE_U_PBC_IDX:
                return FILE_G_PBC_IDX;
                
            case FILE_U_PSC_IDX:
                return FILE_G_PSC_IDX;
                
            case FILE_U_CC_IDX:
                return FILE_G_CC_IDX;
                
            case FILE_U_UID_IDX:
                return FILE_G_UID_IDX;
                
            case FILE_U_PUID_IDX:
                return FILE_G_PUID_IDX;
        #endif /* __PHB_USIM_SYNC__ */
        
        #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
            case FILE_U_IAP_IDX:
                return FILE_G_IAP_IDX;

            case FILE_U_GRP_IDX:
                return FILE_G_GRP_IDX;

            case FILE_U_ANR_IDX:
                return FILE_G_ANR_IDX;

            case FILE_U_SNE_IDX:
                return FILE_G_SNE_IDX;

            case FILE_U_EMAIL_IDX:
                return FILE_G_EMAIL_IDX;

            case FILE_U_GAS_IDX:
                return FILE_G_GAS_IDX;

            case FILE_U_CCP1_IDX:
                return FILE_G_CCP1_IDX;
                
            case FILE_U_AAS_IDX:
                return FILE_G_AAS_IDX;
        #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */ 
        #endif /* __PHB_USIM_SUPPORT__ */
            default:
            break;
        }
    }
    return g_file_id;
}

kal_uint8 phb_desc_get_pbr_pos(data_desc_enum desc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return phb_ptr->data_desc[desc].pbr_pos & 0x7F;
}

void phb_desc_set_pbr_tbl(kal_uint8 count, kal_uint16 occurrence, data_desc_enum desc, kal_uint8 filetype, kal_uint8 iap_pos, kal_uint8 *path, kal_uint8 sfi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_ptr->phb_pbr_table[count][occurrence].filetype = filetype;
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    if (filetype == 2)
    {
        phb_ptr->phb_pbr_table[count][occurrence].iap_pos = iap_pos;
        phb_ptr->phb_pbr_table[count][occurrence].free_count = 0;
        phb_ptr->phb_pbr_table[count][occurrence].free_bitmap = 
            free_bitmap_TYPE2_FILE[phb_which_sim_ex()][(iap_pos * PHB_MAX_PBR_ENTRIES) + occurrence];
        memset(phb_ptr->phb_pbr_table[count][occurrence].free_bitmap, 0xff, FREE_BITMAP_TYPE2_FILE_BYTES);
    }

    if (desc == DATA_DESC_ADN)
    {
        phb_ptr->phb_pbr_table[count][occurrence].free_count = 0;
        phb_ptr->phb_pbr_table[count][occurrence].free_bitmap = 
            free_bitmap_ADN[phb_which_sim_ex()][occurrence];
        memset(phb_ptr->phb_pbr_table[count][occurrence].free_bitmap, 0, FREE_BITMAP_ADN_BYTES);
    }
#endif
    phb_ptr->phb_pbr_table[count][occurrence].desc = desc;
    phb_ptr->phb_pbr_table[count][occurrence].path[0] = path[0];
    phb_ptr->phb_pbr_table[count][occurrence].path[1] = path[1];
    phb_ptr->phb_pbr_table[count][occurrence].sfi = sfi;
    phb_ptr->data_desc[desc].pbr_pos |= (count & 0x7F);
}


#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
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
kal_uint8 phb_desc_get_iap_pos(sim_file_index_enum idx, kal_uint8 occurrence, kal_uint16 pbr_rec, kal_uint8* iap_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (idx)
    {
        case FILE_G_ANR_IDX:
        case FILE_U_ANR_IDX:
        case FILE_G_SNE_IDX:
        case FILE_U_SNE_IDX:
        case FILE_G_EMAIL_IDX:
        case FILE_U_EMAIL_IDX:
        {
            data_desc_enum desc = phb_data_desc_file_id_to_desc(idx, occurrence);
            kal_uint32 i = phb_desc_get_pbr_pos(desc);
            
            if (occurrence == 0 ||
                pbr_rec == 0 ||
                pbr_rec > phb_ptr->data_desc[DATA_DESC_PBR].record_num)
            {
                return 1;
            }

            if (i < PHB_MAX_PBR_TBL_SIZE)
            {
                if (phb_ptr->phb_pbr_table[i][pbr_rec - 1].desc == desc)
                {
                    *iap_pos = phb_ptr->phb_pbr_table[i][pbr_rec - 1].iap_pos;
                    return phb_ptr->phb_pbr_table[i][pbr_rec - 1].filetype;
                }
            }
            break;
        }
        case FILE_G_EXT1_IDX:
        case FILE_U_EXT1_IDX: 
        case FILE_G_AAS_IDX:
        case FILE_U_AAS_IDX:
        case FILE_G_GAS_IDX:
        case FILE_U_GAS_IDX:
        case FILE_G_CCP1_IDX:
        case FILE_U_CCP1_IDX:
            return 3;
            
        default :
            break;
    }
    return 1;
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
kal_uint16 phb_data_desc_find_next_free_ext(data_desc_enum desc, kal_uint16 pbr_rec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phb_pbr_tbl_struct* pbr_desc = &(phb_ptr->phb_pbr_table[phb_desc_get_pbr_pos(desc)][pbr_rec - 1]);
    kal_uint16 byte_counter;
    kal_uint16 bit_counter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_FIND_NEXT_FREE);

    if ((phb_ptr->data_desc[desc].is_support == KAL_FALSE) ||
        ((desc != DATA_DESC_ADN) &&
        !phb_desc_is_type2_file(desc)) ||
        (pbr_desc->free_count == 0) ||
        (pbr_desc->free_bitmap == NULL))
    {
        return (kal_uint16) PHB_INVALID_VALUE;
    }

    for (byte_counter = 0;
         byte_counter < phb_get_data_desc_bytes(desc); ++byte_counter)
    {
        if (pbr_desc->free_bitmap[byte_counter] != 0)
        {
            for (bit_counter = 0; (bit_counter < BYTE_SIZE) &&
                 (((byte_counter << BYTE_SIZE_SHIFT_ARITHMETIC) + bit_counter) < pbr_desc->record_num);
                 ++bit_counter)
            {
                if (pbr_desc->free_bitmap[byte_counter] & (1 << bit_counter))
                {
                    return (byte_counter << BYTE_SIZE_SHIFT_ARITHMETIC) + bit_counter + 1;
                }
            }
        }
    }
    return (kal_uint16) PHB_INVALID_VALUE;
}

kal_bool phb_desc_is_type2_file(data_desc_enum desc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_bool)(phb_ptr->data_desc[desc].pbr_pos & PHB_TYPE2_FILE_FLAG);
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
kal_uint8 phb_desc_get_file_type(data_desc_enum desc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((desc >= DATA_DESC_SNE && desc < DATA_DESC_ANR) ||
        (desc >= DATA_DESC_ANR && desc < DATA_DESC_GRP) ||
        (desc >= DATA_DESC_EMAIL && desc < DATA_DESC_AAS))
    {
        if (phb_desc_is_type2_file(desc))
        {
            return 2;
        }
    }
    else if ((desc == DATA_DESC_EXT1) ||
             (desc == DATA_DESC_AAS) ||
             (desc == DATA_DESC_GAS)) //(type == DATA_DESC_CCP1))
    {
        return 3;
    }
    return 1;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  phb_sim_read_record
 * DESCRIPTION
 *  This function issues SIM_READ_REQ to sim.
 * PARAMETERS
 *  file_idx           [IN]        
 *  adn_index          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 phb_desc_get_pbr_rec(kal_uint16 file_idx, kal_uint16 adn_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (file_idx)
    {
        case FILE_G_ADN_IDX:
        case FILE_U_ADN_IDX:
            
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        case FILE_G_ANR_IDX:
        case FILE_U_ANR_IDX:
            
        case FILE_G_SNE_IDX:
        case FILE_U_SNE_IDX:
            
        case FILE_G_EMAIL_IDX:
        case FILE_U_EMAIL_IDX:
            
        case FILE_G_IAP_IDX:
        case FILE_U_IAP_IDX:
    
        case FILE_G_GRP_IDX:
        case FILE_U_GRP_IDX:
    #endif
    
    #ifdef __PHB_USIM_SYNC__
        case FILE_G_UID_IDX:
        case FILE_U_UID_IDX:
	    case FILE_G_PBC_IDX:
        case FILE_U_PBC_IDX:
    #endif
        {
            kal_uint32 i = 0;
            kal_uint8 pbr_pos = phb_desc_get_pbr_pos(DATA_DESC_ADN);
            
            /* looking for PBR tble */
            for (; i < PHB_MAX_PBR_ENTRIES; i++)
            {
                if (adn_index > phb_ptr->phb_pbr_table[pbr_pos][i].record_num)
                {
                    adn_index -= phb_ptr->phb_pbr_table[pbr_pos][i].record_num;
                }
                else
                {
                    return ++i;
                }
            }           
            break;
        }
        default :
            break;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  phb_sim_read_record
 * DESCRIPTION
 *  This function issues SIM_READ_REQ to sim.
 * PARAMETERS
 *  file_idx           [IN]        
 *  adn_index          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool phb_desc_get_pri_index(
                    kal_uint16 file_idx,
                    kal_uint16 adn_index,
                    kal_uint8 occurrence,
                    kal_uint16 pbr_rec,
                    kal_uint16* pri_index,
                    kal_uint8* iap_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    kal_uint8 filetype;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (file_idx)
    {
        case FILE_G_ADN_IDX:
        case FILE_U_ADN_IDX:
            
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        case FILE_G_ANR_IDX:
        case FILE_U_ANR_IDX:
            
        case FILE_G_SNE_IDX:
        case FILE_U_SNE_IDX:
            
        case FILE_G_EMAIL_IDX:
        case FILE_U_EMAIL_IDX:
            
        case FILE_G_IAP_IDX:
        case FILE_U_IAP_IDX:
    
        case FILE_G_GRP_IDX:
        case FILE_U_GRP_IDX:
    #endif
    
    #ifdef __PHB_USIM_SYNC__
        case FILE_G_UID_IDX:
        case FILE_U_UID_IDX:
	    case FILE_G_PBC_IDX:
        case FILE_U_PBC_IDX:
    #endif
        {
            kal_uint32 i = 0;
            kal_uint8 pbr_pos = phb_desc_get_pbr_pos(DATA_DESC_ADN);
            
            /* looking for PBR tble */
            for (; i < PHB_MAX_PBR_ENTRIES; i++)
            {
                if (adn_index > phb_ptr->phb_pbr_table[pbr_pos][i].record_num)
                {
                    adn_index -= phb_ptr->phb_pbr_table[pbr_pos][i].record_num;
                }
                else
                {
                    kal_trace(TRACE_INFO, PHB_TRC_SIM_MULTI_EF, i + 1, adn_index);
                    break;
                }
            }
            *pri_index = adn_index;
            break;
        }
        default :
            *pri_index = adn_index;
            break;
    }
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    filetype = phb_desc_get_iap_pos(file_idx, occurrence, pbr_rec, iap_pos);
    if (filetype == 2)
    {
        return KAL_FALSE;
    }
#endif
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  phb_sim_read_record
 * DESCRIPTION
 *  This function issues SIM_READ_REQ to sim.
 * PARAMETERS
 *  file_idx           [IN]        
 *  adn_index          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 phb_desc_convert_pri_index(kal_uint16 pbr_rec, kal_uint16 pri_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 record_index = 0;
    kal_int32 i = 0;
    kal_uint8 pbr_pos = phb_desc_get_pbr_pos(DATA_DESC_ADN);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i < pbr_rec - 1; i++)
    {
        record_index += phb_ptr->phb_pbr_table[pbr_pos][i].record_num;
    }
    return pri_index + record_index;
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
kal_bool phb_desc_get_file_path(sim_file_index_enum idx, kal_uint8 occurrence, kal_uint16 pbr_rec, kal_uint8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (usim_ef_info[idx].file_id)
    {
//        kal_mem_cpy(path, usim_ef_info[idx].full_path, 6);
        sim_get_full_path(idx, path);
    }
    else
    {
        phb_pbr_tbl_struct *entry = NULL; 
        sim_file_index_enum fold_id;
        data_desc_enum desc;
        kal_uint32 i;
        
        if (pbr_rec == 0 ||
            pbr_rec > phb_ptr->data_desc[DATA_DESC_PBR].record_num)
        {
            return KAL_FALSE;
        }
        
        desc = phb_data_desc_file_id_to_desc(idx, occurrence);
        i = phb_desc_get_pbr_pos(desc);
        
        /* looking for PBR tble */
        if (i < PHB_MAX_PBR_TBL_SIZE)
        {
            entry = &phb_ptr->phb_pbr_table[i][pbr_rec - 1];
        }

        if (!entry || entry->desc != desc)
        {
            return KAL_FALSE;
        }
        
        if (phb_ptr->is_global)
        {
            fold_id = FILE_G_PHONEBOOK_IDX;
        }
        else
        {
            fold_id = FILE_U_PHONEBOOK_IDX;
        }
         /* folder */
//        kal_mem_cpy(path, usim_ef_info[fold_id].full_path, 4);
        sim_get_full_path(fold_id, path);
        kal_mem_cpy(path + 4, entry->path, 2);
    }
    return KAL_TRUE;
}
#endif /* __PHB_USIM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_entry_reset
 * DESCRIPTION
 *  Reset the data descriptor
 * PARAMETERS
 *  data_desc_entry     [?]         
 *  data_desc(?)        [IN]        The data descriptor
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_data_desc_entry_reset(data_desc_type *data_desc_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_ENTRY_RESET); */

    ASSERT(data_desc_entry != NULL);

    data_desc_entry->record_size = 0;
    data_desc_entry->record_num = 0;
    data_desc_entry->alpha_length = 0;
    data_desc_entry->is_support = KAL_FALSE;
#ifdef __PHB_USIM_SUPPORT__    
    data_desc_entry->pbr_pos = 0;
#endif
    data_desc_entry->free_count = 0;

    if (data_desc_entry->free_bitmap != NULL)
    {
        kal_mem_set(data_desc_entry->free_bitmap, 0, data_desc_entry->free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC);
    }
}   /* end of phb_data_desc_entry_reset */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_entry_new
 * DESCRIPTION
 *  Constructor of data descriptor
 * PARAMETERS
 *  data_desc_entry     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_data_desc_entry_new(data_desc_type *data_desc_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_ENTRY_NEW); */
    phb_data_desc_entry_reset(data_desc_entry);
}


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_new
 * DESCRIPTION
 *  Constructor of data descriptor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void phb_data_desc_new()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_NEW); */
    for (i = 0; i < DATA_DESC_TOTAL; ++i)
    {
        phb_ptr->data_desc[i].free_bitmap_bits = (kal_uint16) (phb_get_data_desc_bytes(i) << BYTE_SIZE_SHIFT_ARITHMETIC);
        phb_data_desc_entry_new(&phb_ptr->data_desc[i]);
    }
}   /* end of phb_data_desc_new */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_reset
 * DESCRIPTION
 *  Reset the data descriptor
 * PARAMETERS
 *  void
 *  data_desc(?)        [IN]        The data descriptor
 * RETURNS
 *  void
 *****************************************************************************/
void phb_data_desc_reset()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_RESET); */
    for (i = 0; i < DATA_DESC_TOTAL; ++i)
    {
        phb_data_desc_entry_reset(&phb_ptr->data_desc[i]);
    }
}   /* end of phb_data_desc_reset */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_reset_free_count
 * DESCRIPTION
 *  Reset free count of the data descriptor
 * PARAMETERS
 *  void
 *  data_desc(?)        [IN]        The data descriptor
 * RETURNS
 *  void
 *****************************************************************************/
void phb_data_desc_reset_free_count()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_RESET_FREE_COUNT); */
    for (i = 0; i < DATA_DESC_TOTAL; ++i)
    {
        phb_ptr->data_desc[i].free_count = 0;
        if (phb_ptr->data_desc[i].free_bitmap != NULL)
        {
            kal_mem_set(
                phb_ptr->data_desc[i].free_bitmap,
                0,
                phb_ptr->data_desc[i].free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC);
        }
    }
}   /* end of phb_data_desc_reset */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_set_is_support
 * DESCRIPTION
 *  Set the data-descriptor
 * PARAMETERS
 *  type                [IN]        
 *  is_support          [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  void
 *****************************************************************************/
void phb_data_desc_set_is_support(data_desc_enum type, kal_bool is_support)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_SET_IS_SUPPORT);

    phb_ptr->data_desc[type].is_support = is_support;
}   /* end of phb_data_desc_set_is_support */


/*****************************************************************************
 * FUNCTION
 *  phb_desc_get_alpha_len
 * DESCRIPTION
 *  get the data-descriptor
 * PARAMETERS
 *  type                [IN]        
 *  alpha_length        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 phb_desc_get_alpha_len(data_desc_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return phb_ptr->data_desc[type].alpha_length;
}


/*****************************************************************************
 * FUNCTION
 *  phb_desc_set_alpha_len
 * DESCRIPTION
 *  Set the data-descriptor
 * PARAMETERS
 *  type                [IN]        
 *  alpha_length        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void phb_desc_set_alpha_len(data_desc_enum type, kal_uint8 alpha_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_ptr->data_desc[type].alpha_length= alpha_length;
}

/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_get_record_size
 * DESCRIPTION
 *  Set the data-descriptor
 * PARAMETERS
 *  type                [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 phb_data_desc_get_record_size(data_desc_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_GET_RECORD_SIZE);

    return ((type == DATA_DESC_EXT1) ||
            (type == DATA_DESC_EXT2) || (type == DATA_DESC_EXT3)) ? 13 : phb_ptr->data_desc[type].record_size;
}   /* end of phb_data_desc_set */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_get_record_num
 * DESCRIPTION
 *  Set the data-descriptor
 * PARAMETERS
 *  type                [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 phb_data_desc_get_record_num(data_desc_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_GET_RECORD_NUM);

    return phb_ptr->data_desc[type].record_num;
}   /* end of phb_data_desc_set */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_set
 * DESCRIPTION
 *  Set the data-descriptor
 * PARAMETERS
 *  type                [IN]        
 *  record_num          [IN]        
 *  record_size         [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  void
 *****************************************************************************/
void phb_data_desc_set(data_desc_enum type, kal_uint16 record_num, kal_uint16 record_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_SET);

    phb_ptr->data_desc[type].record_num = record_num;
    phb_ptr->data_desc[type].record_size = record_size;
}   /* end of phb_data_desc_set */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_mark_free
 * DESCRIPTION
 *  Mark free to the data-descriptor.
 *  Note that a free record is marked as 1 in bitmap.
 * PARAMETERS
 *  type                [IN]        
 *  pos                 [IN]        
 *  is_free             [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  void
 *****************************************************************************/
void phb_data_desc_mark_free(data_desc_enum desc, kal_uint16 pbr_rec, kal_uint16 record_index, kal_uint16 cov_index, kal_bool is_free, kal_bool print_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_desc_type *data_desc_entry = &phb_ptr->data_desc[desc];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(data_desc_entry != NULL);
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    if (phb_util_is_usim(phb_which_sim_ex()) && 
        ((desc == DATA_DESC_ADN && phb_ptr->data_desc[DATA_DESC_PBR].record_num)
        || (phb_desc_is_type2_file(desc) &&
        ((desc >= DATA_DESC_ANR && desc < (DATA_DESC_ANR + PHB_MAX_ANR_OCC)) ||
        (desc >= DATA_DESC_SNE && desc < (DATA_DESC_SNE + PHB_MAX_SNE_OCC)) ||
        (desc >= DATA_DESC_EMAIL && desc < (DATA_DESC_EMAIL + PHB_MAX_EMAIL_OCC))))
        ))
    {
        phb_pbr_tbl_struct* pbr_desc = &(phb_ptr->phb_pbr_table[phb_desc_get_pbr_pos(desc)][pbr_rec - 1]);
        
        kal_trace(TRACE_INFO, PHB_TRC_DESC_MARK_FREE, desc, phb_get_data_desc_bytes(desc), cov_index, pbr_desc->record_num, is_free);

        if (!(pbr_desc->free_bitmap) || (--cov_index >= pbr_desc->record_num) ||
            ((cov_index >> BYTE_SIZE_SHIFT_ARITHMETIC) >= phb_get_data_desc_bytes(desc)))
        {
            return;
        }
        if (is_free)
        {
          /**
           * Only when 'pos' is not marked as free is allowed to be marked as free.
           */
            if (!(pbr_desc->free_bitmap[cov_index >> BYTE_SIZE_SHIFT_ARITHMETIC] & (1 << (cov_index % BYTE_SIZE))))
            {
        
                pbr_desc->free_bitmap[cov_index >> BYTE_SIZE_SHIFT_ARITHMETIC] |= 1 << (cov_index % BYTE_SIZE);
        
                if (pbr_desc->free_count < pbr_desc->record_num)
                {
                    pbr_desc->free_count++;
                    data_desc_entry->free_count++;
                #ifndef __LOW_COST_SUPPORT_COMMON__
                    kal_trace(TRACE_INFO, PHB_TRC_DESC_MARK_FREE_RESULT, pbr_desc->free_count, __LINE__);
                #endif
                }
            }
        }
        else
        {
          /**
           * Only when 'pos' is marked as free is allowed to be marked as not free.
           */
            if (pbr_desc->free_bitmap[cov_index >> BYTE_SIZE_SHIFT_ARITHMETIC] & (1 << (cov_index % BYTE_SIZE)))
            {
                pbr_desc->free_bitmap[cov_index >> BYTE_SIZE_SHIFT_ARITHMETIC] &= (kal_uint8) (~(1 << (cov_index % BYTE_SIZE)));
        
                if (pbr_desc->free_count > 0)
                {
                    pbr_desc->free_count--;
                    data_desc_entry->free_count--;
                #ifndef __LOW_COST_SUPPORT_COMMON__
                    kal_trace(TRACE_INFO, PHB_TRC_DESC_MARK_FREE_RESULT, pbr_desc->free_count, __LINE__);
                #endif
                }
            }
        }
    }
    else
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
    {
        kal_uint8 *free_bitmap = (kal_uint8*) data_desc_entry->free_bitmap;
        if (print_log)
        {
            kal_trace(TRACE_INFO, PHB_TRC_DESC_MARK_FREE, desc, phb_get_data_desc_bytes(desc), record_index, data_desc_entry->record_num, is_free); 
        }
        if (!free_bitmap || (--record_index >= data_desc_entry->record_num) ||
            ((record_index >> BYTE_SIZE_SHIFT_ARITHMETIC) >= phb_get_data_desc_bytes(desc)) || (desc == DATA_DESC_SDN))
        {
            return;
        }

        if (is_free)
        {
          /**
           * Only when 'pos' is not marked as free is allowed to be marked as free.
           */
            if (!(free_bitmap[record_index >> BYTE_SIZE_SHIFT_ARITHMETIC] & (1 << (record_index % BYTE_SIZE))))
            {

                free_bitmap[record_index >> BYTE_SIZE_SHIFT_ARITHMETIC] |= 1 << (record_index % BYTE_SIZE);

                if (data_desc_entry->free_count < data_desc_entry->record_num)
                {
                    data_desc_entry->free_count++;
                    if (print_log)
                    {
                    #ifndef __LOW_COST_SUPPORT_COMMON__
                        kal_trace(TRACE_INFO, PHB_TRC_DESC_MARK_FREE_RESULT, data_desc_entry->free_count, __LINE__);
                    #endif
                    }
                }
            }
        }
        else
        {
          /**
           * Only when 'pos' is marked as free is allowed to be marked as not free.
           */
            if (free_bitmap[record_index >> BYTE_SIZE_SHIFT_ARITHMETIC] & (1 << (record_index % BYTE_SIZE)))
            {
                free_bitmap[record_index >> BYTE_SIZE_SHIFT_ARITHMETIC] &= (kal_uint8) (~(1 << (record_index % BYTE_SIZE)));

                if (data_desc_entry->free_count > 0)
                {
                    data_desc_entry->free_count--;
                    if (print_log)
                    {
                    #ifndef __LOW_COST_SUPPORT_COMMON__
                        kal_trace(TRACE_INFO, PHB_TRC_DESC_MARK_FREE_RESULT, data_desc_entry->free_count, __LINE__);
                    #endif
                    }
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_find_next_free
 * DESCRIPTION
 *  Find record index of next free record
 * PARAMETERS
 *  type                [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  record index of next free record.
 *****************************************************************************/
kal_uint16 phb_data_desc_find_next_free(data_desc_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    if (phb_util_is_usim(phb_which_sim_ex()) && type == DATA_DESC_ADN && phb_ptr->data_desc[DATA_DESC_PBR].record_num)
    {
        kal_uint16 pbr_rec;
        kal_uint16 base_index = 0;
        kal_uint16 record_index;
        for (pbr_rec = 1; pbr_rec <= phb_ptr->data_desc[DATA_DESC_PBR].record_num; pbr_rec++)
        {
            record_index = phb_data_desc_find_next_free_ext(type, pbr_rec);
            if (record_index != (kal_uint16) PHB_INVALID_VALUE)
            {
                return (record_index + base_index);
            }
            base_index += 
                phb_ptr->phb_pbr_table[phb_desc_get_pbr_pos(DATA_DESC_ADN)][pbr_rec - 1].record_num;
        }
    }
    else
#endif
    {
        data_desc_type *data_desc_entry = &phb_ptr->data_desc[type];

        kal_uint16 byte_counter;
        kal_uint16 bit_counter;
        
        kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_FIND_NEXT_FREE);

        ASSERT(data_desc_entry != NULL);

        if ((data_desc_entry->is_support == KAL_FALSE) ||
            (data_desc_entry->free_count == 0) || (data_desc_entry->free_bitmap == NULL))
        {
            return (kal_uint16) PHB_INVALID_VALUE;
        }

        for (byte_counter = 0;
             byte_counter < (data_desc_entry->free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC); ++byte_counter)
        {
            if (data_desc_entry->free_bitmap[byte_counter] != 0)
            {
                for (bit_counter = 0; (bit_counter < BYTE_SIZE) &&
                     (((byte_counter << BYTE_SIZE_SHIFT_ARITHMETIC) + bit_counter) < data_desc_entry->record_num);
                     ++bit_counter)
                {
                    if (data_desc_entry->free_bitmap[byte_counter] & (1 << bit_counter))
                    {
                        return (byte_counter << BYTE_SIZE_SHIFT_ARITHMETIC) + bit_counter + 1;
                    }
                }
            }
        }
    }
    return (kal_uint16) PHB_INVALID_VALUE;
}   /* end of data_desc_append */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_get_free_count
 * DESCRIPTION
 *  Find record index of next free record
 * PARAMETERS
 *  type                [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  record index of next free record.
 *****************************************************************************/
kal_uint16 phb_data_desc_get_free_count(data_desc_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_desc_type *data_desc_entry = &phb_ptr->data_desc[type];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_GET_FREE_COUNT);

    ASSERT(data_desc_entry != NULL);

    return data_desc_entry->free_count;
}   /* end of data_desc_append */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_is_free
 * DESCRIPTION
 *  Tests whether a record is free
 * PARAMETERS
 *  type                [IN]        
 *  pos                 [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  void
 *****************************************************************************/
free_status_enum phb_data_desc_is_free(data_desc_enum desc, kal_uint16 pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    free_status_enum result = RECORD_OCCUPIED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    if (phb_util_is_usim(phb_which_sim_ex()) && desc == DATA_DESC_ADN && phb_ptr->data_desc[DATA_DESC_PBR].record_num)
    {
        kal_uint16 pbr_rec;
        kal_uint16 pbr_pos = phb_desc_get_pbr_pos(DATA_DESC_ADN);
        for (pbr_rec = 0; pbr_rec < phb_ptr->data_desc[DATA_DESC_PBR].record_num; pbr_rec++)
        {
            if (pos > phb_ptr->phb_pbr_table[pbr_pos][pbr_rec].record_num)
            {
                pos -= phb_ptr->phb_pbr_table[pbr_pos][pbr_rec].record_num;
            }
            else
            {
                break;
            }
        }
        if ((pbr_rec < phb_ptr->data_desc[DATA_DESC_PBR].record_num) &&
            (--pos < phb_ptr->phb_pbr_table[pbr_pos][pbr_rec].record_num))
        {
            if ((phb_ptr->phb_pbr_table[pbr_pos][pbr_rec].free_bitmap)[pos >> BYTE_SIZE_SHIFT_ARITHMETIC] & (1 << (pos % BYTE_SIZE)))
            {
                result = RECORD_FREE;
            }
        }
        else
        {
            result = RECORD_INVALID;
        }
    }
    else
#endif
    {
        data_desc_type *data_desc_entry = &phb_ptr->data_desc[desc];
        ASSERT(data_desc_entry != NULL);

        if ((data_desc_entry->is_support == KAL_FALSE) ||
            (--pos >= data_desc_entry->record_num) ||
            ((pos >> BYTE_SIZE_SHIFT_ARITHMETIC) >= phb_get_data_desc_bytes(desc)) || (desc == DATA_DESC_SDN))
        {
            result = RECORD_INVALID;
        }

        else if ((data_desc_entry->free_bitmap)[pos >> BYTE_SIZE_SHIFT_ARITHMETIC] & (1 << (pos % BYTE_SIZE)))
        {
            result = RECORD_FREE;
        }
    }

    kal_trace(TRACE_GROUP_8, FUNC_PHB_DATA_DESC_IS_FREE, result, desc, pos);
    return result;
}   /* end of phb_data_desc_is_free */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_file_id_to_desc
 * DESCRIPTION
 *  Return corresponding data descriptor type of sim_file_id
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  Return corresponding data descriptor type of sim_file_id
 *****************************************************************************/
data_desc_enum phb_data_desc_file_id_to_desc(kal_uint16 file_id, kal_uint8 occurrence)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_GET_DESC_BY_ID);
    switch (file_id)
    {
        case FILE_ECC_IDX:
        case FILE_U_ECC_IDX:
            return DATA_DESC_ECC;

        case FILE_ADN_IDX:
            return DATA_DESC_ADN;

        case FILE_FDN_IDX:
        case FILE_U_FDN_IDX:
            return DATA_DESC_FDN;

        case FILE_MSISDN_IDX:
        case FILE_U_MSISDN_IDX:
            return DATA_DESC_MSISDN;

        case FILE_SDN_IDX:
        case FILE_U_SDN_IDX:
            return DATA_DESC_SDN;

        case FILE_BDN_IDX:
        case FILE_U_BDN_IDX:
            return DATA_DESC_BDN;

        case FILE_EXT1_IDX:
            return DATA_DESC_EXT1;

        case FILE_EXT2_IDX:
        case FILE_U_EXT2_IDX:                
            return DATA_DESC_EXT2;

        case FILE_EXT3_IDX:
        case FILE_U_EXT3_IDX:
            return DATA_DESC_EXT3;

        case FILE_EXT4_IDX:
        case FILE_U_EXT4_IDX:
            return DATA_DESC_EXT4;
#ifdef __PHB_USIM_SUPPORT__
        case FILE_G_EXT1_IDX:
        case FILE_U_EXT1_IDX:
            return DATA_DESC_EXT1;
    
        case FILE_U_EXT5_IDX:
            return DATA_DESC_EXT5;
    
        case FILE_G_ADN_IDX:
        case FILE_U_ADN_IDX:
            return DATA_DESC_ADN;
    
        case FILE_G_PBR_IDX:
        case FILE_U_PBR_IDX:
            return DATA_DESC_PBR;
            
    #ifdef __PHB_USIM_SYNC__                
        case FILE_G_PBC_IDX:
        case FILE_U_PBC_IDX:
            return DATA_DESC_PBC;
            
        case FILE_G_PSC_IDX:
        case FILE_U_PSC_IDX:
            return DATA_DESC_PSC;
            
        case FILE_G_CC_IDX:
        case FILE_U_CC_IDX:
            return DATA_DESC_CC;
            
        case FILE_G_UID_IDX:
        case FILE_U_UID_IDX:
            return DATA_DESC_UID;
            
        case FILE_G_PUID_IDX:
        case FILE_U_PUID_IDX:
            return DATA_DESC_PUID;
            
    #endif /* __PHB_USIM_SYNC__ */
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        case FILE_G_IAP_IDX:
        case FILE_U_IAP_IDX:
            return DATA_DESC_IAP;
    
        case FILE_G_GRP_IDX:
        case FILE_U_GRP_IDX:
            return DATA_DESC_GRP;
    
        case FILE_G_ANR_IDX:
        case FILE_U_ANR_IDX:
            return DATA_DESC_ANR + occurrence - 1;
    
        case FILE_G_SNE_IDX:
        case FILE_U_SNE_IDX:
            return DATA_DESC_SNE + occurrence - 1;
    
        case FILE_G_EMAIL_IDX:
        case FILE_U_EMAIL_IDX:
            return DATA_DESC_EMAIL + occurrence - 1;
    
        case FILE_G_GAS_IDX:
        case FILE_U_GAS_IDX:
            return DATA_DESC_GAS;
    
        case FILE_G_CCP1_IDX:
        case FILE_U_CCP1_IDX:
            break;

        case FILE_G_AAS_IDX:
        case FILE_U_AAS_IDX:
            return DATA_DESC_AAS;
            break;
    #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */ 
    #endif /* __PHB_USIM_SUPPORT__ */
    }
    ASSERT(0);
    return (data_desc_enum) PHB_INVALID_VALUE;
}


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_get_desc_by_ID
 * DESCRIPTION
 *  Return corresponding data descriptor type of sim_file_id
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  Return corresponding data descriptor type of sim_file_id
 *****************************************************************************/
data_desc_enum phb_data_desc_get_desc_by_ID(kal_uint16 file_id, kal_uint8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_GET_DESC_BY_ID);

    if (storage == PHB_STORAGE_NVRAM)
    {
    #ifndef __PHB_STORAGE_BY_MMI__
        if (file_id == NVRAM_EF_PHB_LID)
        {
            return DATA_DESC_PHB;
        }
    #endif
        ASSERT(0);
        return (data_desc_enum) PHB_INVALID_VALUE;
    }
    else
    {
        switch (file_id)
        {
            case FILE_ECC_IDX:
            case FILE_U_ECC_IDX:
                return DATA_DESC_ECC;

            case FILE_ADN_IDX:
                return DATA_DESC_ADN;

            case FILE_FDN_IDX:
            case FILE_U_FDN_IDX:
                return DATA_DESC_FDN;

            case FILE_MSISDN_IDX:
            case FILE_U_MSISDN_IDX:
                return DATA_DESC_MSISDN;

            case FILE_SDN_IDX:
            case FILE_U_SDN_IDX:
                return DATA_DESC_SDN;

            case FILE_BDN_IDX:
            case FILE_U_BDN_IDX:
                return DATA_DESC_BDN;

            case FILE_EXT1_IDX:
                return DATA_DESC_EXT1;

            case FILE_EXT2_IDX:
            case FILE_U_EXT2_IDX:
                return DATA_DESC_EXT2;

            case FILE_EXT3_IDX:
            case FILE_U_EXT3_IDX:
                return DATA_DESC_EXT3;

            case FILE_EXT4_IDX:
            case FILE_U_EXT4_IDX:
                return DATA_DESC_EXT4;

        #ifdef __PHB_USIM_SUPPORT__
            case FILE_G_EXT1_IDX:
            case FILE_U_EXT1_IDX:
                return DATA_DESC_EXT1;

            case FILE_U_EXT5_IDX:
                return DATA_DESC_EXT5;

            case FILE_G_ADN_IDX:
            case FILE_U_ADN_IDX:
                return DATA_DESC_ADN;

            case FILE_G_PBR_IDX:
            case FILE_U_PBR_IDX:
                return DATA_DESC_PBR;
                
        #ifdef __PHB_USIM_SYNC__                
            case FILE_G_PBC_IDX:
            case FILE_U_PBC_IDX:
                return DATA_DESC_PBC;
                
            case FILE_G_PSC_IDX:
            case FILE_U_PSC_IDX:
                return DATA_DESC_PSC;
                
            case FILE_G_CC_IDX:
            case FILE_U_CC_IDX:
                return DATA_DESC_CC;
                
            case FILE_G_UID_IDX:
            case FILE_U_UID_IDX:
                return DATA_DESC_UID;
                
            case FILE_G_PUID_IDX:
            case FILE_U_PUID_IDX:
                return DATA_DESC_PUID;
                
        #endif /* __PHB_USIM_SYNC__ */
        #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
            case FILE_G_IAP_IDX:
            case FILE_U_IAP_IDX:
                return DATA_DESC_IAP;

            case FILE_G_GRP_IDX:
            case FILE_U_GRP_IDX:
                return DATA_DESC_GRP;

            case FILE_G_ANR_IDX:
            case FILE_U_ANR_IDX:
                return DATA_DESC_ANR;

            case FILE_G_SNE_IDX:
            case FILE_U_SNE_IDX:
                return DATA_DESC_SNE;

            case FILE_G_EMAIL_IDX:
            case FILE_U_EMAIL_IDX:
                return DATA_DESC_EMAIL;

            case FILE_G_GAS_IDX:
            case FILE_U_GAS_IDX:
                return DATA_DESC_GAS;

            case FILE_G_CCP1_IDX:
            case FILE_U_CCP1_IDX:

            case FILE_G_AAS_IDX:
            case FILE_U_AAS_IDX:
				return DATA_DESC_AAS;
        #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */ 
        #endif /* __PHB_USIM_SUPPORT__ */
            default:
                ASSERT(0);
                return (data_desc_enum) PHB_INVALID_VALUE;
        }
    }
}   /* end of phb_data_desc_get_desc_by_ID */





/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_get_ID_by_desc
 * DESCRIPTION
 *  Return corresponding ID of data descriptor type
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  Return corresponding sim_file_id of data descriptor type
 *****************************************************************************/
kal_uint16 phb_data_desc_get_ID_by_desc(data_desc_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_DATA_DESC_GET_ID_BY_DESC);

    switch (type)
    {
    #ifndef __PHB_STORAGE_BY_MMI__
        case DATA_DESC_PHB:
            return NVRAM_EF_PHB_LID;
    #endif

        case DATA_DESC_ADN:
            return FILE_ADN_IDX;

        case DATA_DESC_FDN:
            return FILE_FDN_IDX;

        case DATA_DESC_MSISDN:
            return FILE_MSISDN_IDX;

        case DATA_DESC_SDN:
            return FILE_SDN_IDX;

        case DATA_DESC_BDN:
            return FILE_BDN_IDX;

        case DATA_DESC_EXT1:
            return FILE_EXT1_IDX;

        case DATA_DESC_EXT2:
            return FILE_EXT2_IDX;

        case DATA_DESC_EXT3:
            return FILE_EXT3_IDX;

        case DATA_DESC_EXT4:
            return FILE_EXT4_IDX;

        default:
            break;
    }
    ASSERT(0);
    return (kal_uint16) PHB_INVALID_VALUE;
}   /* end of phb_data_desc_get_ID_by_desc */


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_get_ID_by_desc
 * DESCRIPTION
 *  Return corresponding ID of data descriptor type
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  Return corresponding sim_file_id of data descriptor type
 *****************************************************************************/
void phb_desc_convert_desc(phb_type_enum dest, l4c_phb_desc_struct *desc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_desc_enum src;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(dest + 1)
    {
        case PHB_ECC:
        #ifdef __PHB_USIM_SUPPORT__
            src = DATA_DESC_ECC;
            break;         
        #else

            if (phb_ptr->ecc.num_ecc)
            {
                desc->record_num = phb_ptr->ecc.num_ecc / NUM_OF_BYTE_ECC;
                desc->record_size = NUM_OF_BYTE_ECC;
                desc->is_support = KAL_TRUE;
            }
            return;
        #endif /* __PHB_USIM_SUPPORT__ */


        case PHB_FDN:
            src = DATA_DESC_FDN;
            break;
        case PHB_BDN:
            src = DATA_DESC_BDN;
            break;
        case PHB_MSISDN:
            src = DATA_DESC_MSISDN;
            break;
        case PHB_SDN:
            src = DATA_DESC_SDN;
            break;
        case PHB_PHONEBOOK:
            src = DATA_DESC_ADN;
            break;
            
        case PHB_EXT1:
            src = DATA_DESC_EXT1;
            break;
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        case PHB_SNE:
            desc->occurrence = phb_ptr->sne_count;
            src = DATA_DESC_SNE;
            break;
        case PHB_EMAIL:
            desc->occurrence = phb_ptr->email_count;
            src = DATA_DESC_EMAIL;
            break;
            
        case PHB_ANR:
            desc->occurrence = phb_ptr->anr_count;
            src = DATA_DESC_ANR;
            break;

        case PHB_AAS:
            src = DATA_DESC_AAS;
            break;
            
        case PHB_GAS:
            src = DATA_DESC_GAS;
            break;
            
        case PHB_GRP:
            src = DATA_DESC_GRP;
            break;
    #endif

    #ifdef __PHB_USIM_SYNC__
        case PHB_PBC:
            src = DATA_DESC_PBC;
            break;
    #endif

        default:
            return;
    }
    desc->record_num = phb_ptr->data_desc[src].record_num;
    desc->record_size = phb_ptr->data_desc[src].record_size;
    desc->alpha_length = phb_ptr->data_desc[src].alpha_length;
    desc->is_support = phb_ptr->data_desc[src].is_support;
}


/*****************************************************************************
 * FUNCTION
 *  phb_data_desc_is_free
 * DESCRIPTION
 *  Tests whether a record is free
 * PARAMETERS
 *  type                [IN]        
 *  pos                 [IN]        
 *  data_desc(?)        [IN]        The data-descriptor
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 phb_get_data_desc_bytes(data_desc_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    if ((type >= DATA_DESC_SNE && type < DATA_DESC_ANR) ||
        (type >= DATA_DESC_ANR && type < DATA_DESC_GRP) ||
        (type >= DATA_DESC_EMAIL && type < DATA_DESC_AAS))
    {
        return FREE_BITMAP_TYPE2_FILE_BYTES;
    }
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */

    switch (type)
    {
        case DATA_DESC_ECC:
            return FREE_BITMAP_ECC_BYTES;
            
        case DATA_DESC_ADN:
            return FREE_BITMAP_ADN_BYTES;
            
    #ifdef __PHB_USIM_SUPPORT__
        case DATA_DESC_EXT5:
            return FREE_BITMAP_EXT5_BYTES;
            
        case DATA_DESC_PBR:
            return FREE_BITMAP_PBR_BYTES;
            
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        case DATA_DESC_IAP:
            return FREE_BITMAP_IAP_BYTES;

        case DATA_DESC_GRP:
            return FREE_BITMAP_GRP_BYTES;
            
        case DATA_DESC_AAS:
            return FREE_BITMAP_AAS_BYTES;
            
        case DATA_DESC_GAS:
            return FREE_BITMAP_GAS_BYTES;
    #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */ 
    
    #ifdef __PHB_USIM_SYNC__
        case DATA_DESC_PBC:
            return FREE_BITMAP_PBC_BYTES;

        case DATA_DESC_CC:
            return FREE_BITMAP_CC_BYTES;

        case DATA_DESC_UID:
            return FREE_BITMAP_UID_BYTES;

        case DATA_DESC_PSC:
            return FREE_BITMAP_PSC_BYTES;

        case DATA_DESC_PUID:
            return FREE_BITMAP_PUID_BYTES;
    #endif /* __PHB_USIM_SYNC__ */

    #endif /* __PHB_USIM_SUPPORT__*/
        case DATA_DESC_EXT1:
            return FREE_BITMAP_EXT1_BYTES;

        case DATA_DESC_PHB:
            return FREE_BITMAP_NVRAM_PHB_BYTES;
            
        case DATA_DESC_FDN:
            return FREE_BITMAP_FDN_BYTES;
            
        case DATA_DESC_BDN:
            return FREE_BITMAP_BDN_BYTES;
            
        case DATA_DESC_MSISDN:
            return FREE_BITMAP_MSISDN_BYTES;
            
        case DATA_DESC_SDN:
            return FREE_BITMAP_SDN_BYTES;

        case DATA_DESC_EXT2:
            return FREE_BITMAP_EXT2_BYTES;
            
        case DATA_DESC_EXT3:
            return FREE_BITMAP_EXT3_BYTES;
            
        case DATA_DESC_EXT4:
            return FREE_BITMAP_EXT4_BYTES;
            
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_desc_index_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool phb_desc_index_check(data_desc_enum type, kal_uint16 record_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 record_num = phb_ptr->data_desc[DATA_DESC_PBR].record_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record_num == 0)
    {
        record_num = 1;
    }

    if (record_index != PHB_NULL_VALUE &&
        record_index > 0 &&
        record_index <= (phb_desc_is_type2_file(type) ? phb_data_desc_get_record_num(type) / record_num : phb_data_desc_get_record_num(type)))
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}

