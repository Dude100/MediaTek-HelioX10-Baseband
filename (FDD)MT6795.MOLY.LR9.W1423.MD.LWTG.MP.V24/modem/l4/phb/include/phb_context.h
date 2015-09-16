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
 * phb_context.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is context declarations.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _PHB_CONTEXT_H
#define _PHB_CONTEXT_H

//#include "kal_release.h"
#include "kal_public_api.h"
#include "ps2sim_struct.h"
#include "phb_control_block.h"
#include "phb_data_desc.h"
#include "phb_data_entry_table.h"
#include "phb_name_num_index.h"
#include "phb_pindex.h"
#include "kal_general_types.h"
#include "phb_defs.h"
#include "sim_common_enums.h"
#include "phb_config.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */

#ifndef _PS2SIM_STRUCT_H
#error "ps2sim_struct.h should be included"
#endif 
#ifndef _PHB_CONTROL_BLOCK_H
#error "phb_control_block.h should be included"
#endif 
#ifndef _PHB_DATA_DESC_H
#error "phb_data_desc.h should be included"
#endif 
#ifndef _PHB_DATA_ENTRY_TABLE_H
#error "phb_data_entry_table.h should be included"
#endif 
#ifndef _PHB_NAME_NUM_INDEX_H
#error "phb_name_num_index.h should be included"
#endif 
#ifndef _PHB_PINDEX_H
#error "phb_pindex.h should be included"
#endif 


typedef enum
{
    PHB_STATE_NULL,                 /* NULL state */
    PHB_STATE_LN_NOT_READY,         /* PHB and LN both not ready */
    PHB_STATE_NOT_READY,            /* PHB not ready and FDN not ready */
    PHB_STATE_NOT_READY_FDN_READY,  /* PHB still not ready, but FDN ready. */
    PHB_STATE_READY                 /* PHB ready */
} phb_state_enum;

typedef struct
{
    kal_uint16              file_id;           /* Primary EF ID */
    kal_uint16              record_index;
    
    kal_uint16              pbr_rec;
    kal_uint8               occurrence;        /* occurrence times of ANR, SNE, EMAIL */
    
#ifdef __PHB_USIM_SUPPORT__
    kal_uint8               iap_pos;           /* type2 file(other type always 0) mapping iap position */
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    kal_uint16              iap_index;
    kal_uint8*              tmp_iap_data;
#endif
#endif

    kal_uint16              pri_record_index; /* IO Primary record ID */
    kal_uint8               seg_record_index; /* Location to write segmented telephone number, in secondary_ID */
    kal_uint8               seg_len;          /* Length of segmented telephone number to write in this iteration. */
    kal_uint8               seg_total;        /* Accumulated total length of segmented telephone number already written */
    
    IO_state_enum           IO_stage;
    
    control_block_type *control_block;
} phb_IO_cntx;

/* The indexing structure */
typedef struct
{
#ifdef __PHB_SORT_ENABLE__
    name_num_index_type phb_index;
#endif 
    name_num_index_type fdn_index;
#if !(defined(LOW_COST_SUPPORT) && defined(PLUTO_MMI))
    name_num_index_type bdn_index;
#endif
} indices_type;

typedef struct
{
    phb_state_enum      state;
    sim_dn_enum         dn_type;
    kal_bool            is_fdn_change;
    kal_bool            is_adn_support;
#if defined(__SGLTE__)
    module_type         src_mod_id;
    module_type         dest_mod_id;
#endif
    kal_bool            drop_cnf;
    kal_uint8           compare_digit;
#ifdef __PHB_USIM_SUPPORT__
    kal_bool            is_global;
    phb_pbr_tbl_struct  phb_pbr_table[PHB_MAX_PBR_TBL_SIZE][PHB_MAX_PBR_ENTRIES];
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    kal_uint8           anr_count;
    kal_uint8           sne_count;
    kal_uint8           email_count;
#ifndef __PHB_IAP_CACHE_REMOVAL__
    kal_uint8           iap_array[ADN_INDEX_MAX_ENTRIES_COUNT][PHB_MAX_TYPE2_ENTRIES];
#endif
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
    //kal_uint8           path[USIM_DATA_DESC_TOTAL][2];
#ifdef __PHB_USIM_SYNC__
    kal_uint16          puid;
    kal_uint16          cc;
    kal_uint32          psc;
#endif /* __PHB_USIM_SYNC__ */
#endif /* __PHB_USIM_SUPPORT__ */

    control_block_type    control_block[PHB_CONCURRENCY_DEGREE];

    phb_IO_cntx IO_cntx[PHB_CONCURRENCY_DEGREE];

    /* to solve multi request problem */
    kal_uint8           request_count;

    /* The data descriptor */
    data_desc_type        data_desc[DATA_DESC_TOTAL];

    /* The indexing structure */
    indices_type          indices;

    sim_ecc_struct        ecc;
    #ifdef __PHB_ACCESS_SIM_LN__
        data_desc_type        ln_data_desc[LN_DATA_DESC_TOTAL];
    #endif /* __PHB_ACCESS_SIM_LN__ */
} phb_context_type;

    extern phb_context_type *phb_ptr;
#if !defined(__PHB_NO_CALL_LOG__)
#ifdef __PHB_RECORD_LN_TYPE_SEQ__
#if defined(__GEMINI__) || defined(GEMINI_PLUS)
    extern kal_uint8 *phb_ln_type_seq;
#else /* __GEMINI__ */
    extern kal_uint8 phb_ln_type_seq[PHB_TOTAL_LN_ENTRIES];
#endif /* __GEMINI__ */
#ifdef __PHB_ALWAYS_SYNC_SIM_LN__
    extern void phb_clear_lnd_type_seq(void);
#endif 
    extern void phb_set_ln_type_seq(kal_uint16 num, kal_uint8 type);
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 
#if (MAX_PHB_LN_ENTRY > 20)
    extern kal_uint16 phb_get_ln_total_entry(kal_uint8 type);
    extern phb_ln_entry_struct shifted_entry;
#endif /* (MAX_PHB_LN_ENTRY > 20) */ 
#endif /* !defined(__PHB_NO_CALL_LOG__) */

    extern void phb_context_reset(void);

#if defined(__PHB_FDN_GET_NAME__) || defined(__ECALL_SUPPORT__)
    extern void phb_init_fdn_context(void);
    extern void phb_update_fdn_context(kal_uint16 record_index, l4_name_struct* alpha_id, l4_addr_bcd_struct* tel_number);
#endif /* __PHB_FDN_GET_NAME__ */

#if defined(__ECALL_SUPPORT__)
    extern void phb_init_sdn_context(void);
    extern void phb_update_sdn_context(kal_uint16 record_index, l4_name_struct* alpha_id, l4_addr_bcd_struct* tel_number);
#endif /* __PHB_FDN_GET_NAME__ */

    extern control_block_type *phb_alloc_control_block(void);
    extern void phb_free_control_block(control_block_type *control_block);

    extern void phb_reset_all_control_blocks(void);
#if defined(__GEMINI__) || defined(GEMINI_PLUS) || defined(__SGLTE__)
    extern void phb_context_selection(kal_uint8 sim_interface);
#endif

#ifdef __cplusplus
}
#endif 

#endif /* _PHB_CONTEXT_H */ 
/* End of file phb_context.h */

