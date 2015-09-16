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

/*******************************************************************************
 * Filename:
 * ---------
 * phb_data_desc.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is the data_descriptor.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _PHB_DATA_DESC_H
#define _PHB_DATA_DESC_H

//#include "stack_ltlcom.h"
#include "phb_defs.h"
#include "kal_general_types.h"
#include "sim_common_enums.h"
#include "kal_public_api.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /* Header files should be include before this one */
#ifndef _STACK_LTLCOM_H
//#error "stack_ltlcom.h should be included"
#endif 
#ifndef _PHB_DEFS_H
#error "phb_defs.h should be included"
#endif

#include "phb_config.h"

    typedef enum
    {                           //<USIM, SIM>
        DATA_DESC_ECC,          // = <00,00>
        DATA_DESC_ADN,          // = <01,01>
    #ifdef __PHB_USIM_SUPPORT__
        DATA_DESC_EXT5,         // = <02,XX>
        
        DATA_DESC_PBR,          // = <03,XX>

    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        DATA_DESC_IAP,                                                // = <XX,XX>
        DATA_DESC_SNE,                                                // = <XX,XX>
        DATA_DESC_ANR = DATA_DESC_SNE + PHB_MAX_SNE_OCC,              // = <XX,XX>
        DATA_DESC_GRP = DATA_DESC_ANR + PHB_MAX_ANR_OCC,              // = <XX,XX>
        DATA_DESC_EMAIL,                                              // = <XX,XX>
        DATA_DESC_AAS = DATA_DESC_EMAIL + PHB_MAX_EMAIL_OCC,          // = <XX,XX>
        DATA_DESC_GAS,                                                // = <XX,XX>
    #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */ 
    #ifdef __PHB_USIM_SYNC__
        DATA_DESC_PBC,          // = <XX,XX>
        DATA_DESC_CC,           // = <XX,XX>
        DATA_DESC_UID,          // = <XX,XX>
        DATA_DESC_PSC,          // = <XX,XX>
        DATA_DESC_PUID,         // = <XX,XX>
    #endif /* __PHB_USIM_SYNC__ */

    #endif /* __PHB_USIM_SUPPORT__*/
        DATA_DESC_EXT1,         // = <04,02>
        USIM_DATA_DESC_TOTAL,   // = <05,03>
        DATA_DESC_PHB = USIM_DATA_DESC_TOTAL,
        DATA_DESC_FDN,          // = <06,04>
        DATA_DESC_BDN,          // = <07,05>
        DATA_DESC_MSISDN,       // = <08,06>
        DATA_DESC_SDN,          // = <09,07>
        DATA_DESC_EXT2,         // = <10,08>
        DATA_DESC_EXT3,         // = <11,09>
        DATA_DESC_EXT4,         // = <12,10>
        DATA_DESC_TOTAL         // = <13,11>
    } data_desc_enum;

#ifdef  __PHB_ACCESS_SIM_LN__
    typedef enum
    {
        LN_DATA_DESC_LND,
        LN_DATA_DESC_TOTAL
    } ln_data_desc_enum;
#endif /* __PHB_ACCESS_SIM_LN__ */

    typedef struct
    {
        kal_uint16 record_size; /* size of record in storage */
        kal_uint16 record_num;  /* total record number in storage */
        kal_uint8 alpha_length; /* alpha_len: not useful for every EF */
        kal_bool is_support;
    #ifdef __PHB_USIM_SUPPORT__
        kal_uint8 pbr_pos; /* could combine with is_support */
    #endif
        kal_uint16 free_count;
        kal_uint16 free_bitmap_bits;
        kal_uint8 *free_bitmap;
    } data_desc_type;

    typedef struct
    {
        data_desc_enum desc;
        kal_uint8 filetype;
        kal_uint8 path[2];
        kal_uint8 sfi;
        kal_uint16 record_num;
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        kal_uint8 iap_pos; /* type2 file(other type always 0) mapping iap position */
        kal_uint16 free_count;
        kal_uint8 *free_bitmap;
    #endif
    }phb_pbr_tbl_struct;

#ifdef __PHB_USIM_SUPPORT__
    typedef struct
    {
        kal_int8 support_type;
        kal_int8 path[2];
        kal_uint16 record_num;  /* total record number in storage */
        kal_uint16 record_size; /* size of record in storage */
        kal_uint16 free_count;
        kal_uint16 free_bitmap_bits;
        kal_uint8 *free_bitmap;
    } pbr_data_desc_type;
#endif /* __PHB_USIM_SUPPORT__ */ 

    typedef enum
    {
        RECORD_INVALID,
        RECORD_OCCUPIED,
        RECORD_FREE
    } free_status_enum;

    extern void phb_data_desc_new(void);
    extern void phb_data_desc_reset(void);
    extern void phb_data_desc_reset_free_count(void);
    extern void phb_data_desc_set_is_support(data_desc_enum type, kal_bool is_support);
    extern kal_uint8 phb_desc_get_alpha_len(data_desc_enum type);
    extern void phb_desc_set_alpha_len(data_desc_enum type, kal_uint8 alpha_length);
    extern kal_uint16 phb_data_desc_get_record_size(data_desc_enum type);
    extern kal_uint16 phb_data_desc_get_record_num(data_desc_enum type);
    extern void phb_data_desc_set(data_desc_enum type, kal_uint16 record_num, kal_uint16 record_size);
    extern void phb_data_desc_mark_free(data_desc_enum type, kal_uint16 pbr_rec, kal_uint16 record_index, kal_uint16 cov_index, kal_bool is_free, kal_bool print_log);
    extern free_status_enum phb_data_desc_is_free(data_desc_enum type, kal_uint16 pos);
    extern kal_uint16 phb_data_desc_find_next_free(data_desc_enum type);
    extern kal_uint16 phb_data_desc_get_free_count(data_desc_enum type);
    extern data_desc_enum phb_data_desc_file_id_to_desc(kal_uint16 file_id, kal_uint8 occurrence);
    extern data_desc_enum phb_data_desc_get_desc_by_ID(kal_uint16 file_id, kal_uint8 storage);
    extern kal_uint16 phb_data_desc_get_ID_by_desc(data_desc_enum type);
    extern kal_bool phb_desc_index_check(data_desc_enum type, kal_uint16 record_index);
#ifdef __PHB_USIM_SUPPORT__
    extern kal_uint16 phb_desc_get_used_file_id(kal_uint16 g_file_id);
    extern kal_uint8 phb_desc_get_pbr_pos(data_desc_enum desc);
    extern void phb_desc_set_pbr_tbl(kal_uint8 count,
                                     kal_uint16 occurrence,
                                     data_desc_enum desc,
                                     kal_uint8 filetype,
                                     kal_uint8 iap_pos,
                                     kal_uint8 *path,
                                     kal_uint8 sfi);
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
extern kal_uint16 phb_data_desc_find_next_free_ext(data_desc_enum type, kal_uint16 pbr_rec);
extern kal_bool phb_desc_is_type2_file(data_desc_enum desc);
extern kal_uint8 phb_desc_get_file_type(data_desc_enum type);
#endif
extern kal_uint16 phb_desc_get_pbr_rec(kal_uint16 file_idx, kal_uint16 adn_index);
extern kal_bool phb_desc_get_pri_index(
                    kal_uint16 file_idx,
                    kal_uint16 adn_index,
                    kal_uint8 occurrence,
                    kal_uint16 pbr_rec,
                    kal_uint16* pri_index,
                    kal_uint8* iap_pos);
extern kal_uint16 phb_desc_convert_pri_index(kal_uint16 pbr_rec, kal_uint16 pri_index);

extern kal_bool phb_desc_get_file_path(sim_file_index_enum idx, kal_uint8 occurrence, kal_uint16 pbr_rec, kal_uint8 *path);
#endif /* __PHB_USIM_SUPPORT__ */

extern kal_uint16 phb_get_data_desc_bytes(data_desc_enum type);

#ifdef __cplusplus
}
#endif 

#endif /* _PHB_DATA_DESC_H */ 

