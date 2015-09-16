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
 * phb_handler_startup.c
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "l4_msgid.h"
#include "sim_ps_msgid.h"

//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
//#include "stack_ltlcom.h" /* Task message communiction */
//#include "app_buff_alloc.h"

#include "kal_trace.h"
#include "phb_trc.h"

//#include "nvram_user_defs.h"
//#include "custom_nvram_editor_data_item.h"

#include "ps2sim_struct.h"
#include "sim_common_enums.h"
#include "smu_common_enums.h"
#ifdef __SAT__
//#include "ps2sat_struct.h"
#endif 

//#include "l4_defs.h"
//#include "l4_common.h"

#include "l4c2phb_enums.h"
#include "l4c2phb_struct.h"

/* Prerequisite of phb_context.h */
#include "phb_defs.h"
#include "phb_control_block.h"
#include "phb_config.h"
#include "phb_data_desc.h"
//#include "phb_data_entry_table.h"
//#include "phb_pindex.h"
#include "phb_name_num_index.h"

#include "phb_context.h"
#include "phb_se.h"

#include "phb_common.h"
#include "phb_utils.h"
#include "phb_ilm.h"


/* SIM access */
#include "phb_sim_access.h"

#include "phb_nvram_access.h"

#include "phb_handler_startup.h"

#include "custom_ecc.h"

#include "nvram_interface.h"

#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "nvram_data_items.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "nvram_enums.h"
#include "mcd_l4_common.h"
#include "string.h"
#include "l4_ps_api.h"

#define SIM_EF_EXT_SIZE 13
#ifdef __PHB_USIM_SUPPORT__
#define PHB_TYPE_1_FILE 0xA8
#define PHB_TYPE_2_FILE 0xA9
#define PHB_TYPE_3_FILE 0xAA
#define PHB_ADN_DO 0xC0
#define PHB_EXT1_DO 0xC2
#ifdef __PHB_USIM_SYNC__
#define PHB_PBC_DO 0xC5
#define PHB_UID_DO 0xC9
#endif /* __PHB_USIM_SYNC__ */
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
#define PHB_IAP_DO 0xC1
#define PHB_SNE_DO 0xC3
#define PHB_ANR_DO 0xC4
#define PHB_GRP_DO 0xC6
#define PHB_AAS_DO 0xC7
#define PHB_GAS_DO 0xC8
#define PHB_EMAIL_DO 0xCA
#define PHB_CCP1_DO 0xCB
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */


/*
 * local functions
 */
static kal_bool phb_read_pbr_req(control_block_type *cblk);
static void phb_read_pbr_cnf(ilm_struct *ilm_ptr, control_block_type *cblk);

static void phb_get_adn_info_cnf(ilm_struct *ilm_ptr, control_block_type *cblk);
static kal_bool phb_get_adn_info_req(control_block_type *cblk);
#endif /* __PHB_USIM_SUPPORT__ */

#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
#ifndef __PHB_IAP_CACHE_REMOVAL__
static kal_bool phb_read_iap_req(control_block_type *cblk);
static void phb_read_iap_cnf(ilm_struct *ilm_ptr, control_block_type *cblk);
#endif /* __PHB_IAP_CACHE_REMOVAL__ */

static void phb_get_addition_info_cnf(ilm_struct *ilm_ptr, control_block_type *cblk);
static kal_bool phb_get_addition_info_req(control_block_type *cblk);

//static void phb_build_gas_index(ilm_struct *ilm_ptr, control_block_type *cblk);
//static void phb_build_grp_index(ilm_struct *ilm_ptr, control_block_type *cblk);
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */ 



static void phb_startup_err_handler(ilm_struct *ilm_ptr, control_block_type *cblk);
static void phb_get_info_set_value(ilm_struct *ilm_ptr, control_block_type *cblk);
static void phb_get_info_err_handler(ilm_struct *ilm_ptr, control_block_type *cblk);
#ifdef _SPEEDUP_PHB
static l4cphb_startup_read_ind_struct phb_startup_waiting_ind;
static kal_bool phb_startup_waiting_flag;
#endif
static void phb_startup_build_index(ilm_struct *ilm_ptr, control_block_type *cblk);
static void phb_build_ecc(ilm_struct * ilm_ptr, control_block_type * cblk);
static void phb_build_me(ilm_struct * ilm_ptr, control_block_type * cblk);
static void phb_build_adn(ilm_struct * ilm_ptr, control_block_type * cblk);
static void phb_build_fdn(ilm_struct * ilm_ptr, control_block_type * cblk);
#ifdef __ECALL_SUPPORT__
static void phb_build_sdn(ilm_struct * ilm_ptr, control_block_type * cblk);
#endif
static void phb_build_bdn(ilm_struct * ilm_ptr, control_block_type * cblk);
#ifdef __PHB_USIM_SYNC__
static void phb_build_pbc(ilm_struct *ilm_ptr, control_block_type *cblk);
static void phb_build_transfm(ilm_struct *ilm_ptr, control_block_type *cblk);
#endif
void phb_build_next(ilm_struct *ilm_ptr, control_block_type *cblk);
static void phb_startup_confirm(phb_errno_enum result, control_block_type *cblk);
void phb_get_info(ilm_struct *ilm_ptr, control_block_type *cblk);

extern void phb_desc_convert_desc(phb_type_enum dest, l4c_phb_desc_struct *desc);
extern void l4csmu_get_chv_info_status(sim_chv_info_struct *chv_info, sim_chv_status_struct *chv_status);

sim_chv_status_struct chv_status[PHB_SIM_NUM];


// TODO: reorg the structure to make size small
typedef enum
{
    PHB_INFO_CHK_SIM,
    PHB_INFO_CHK_USIM,
    PHB_INFO_READ_SIM,
    PHB_INFO_READ_USIM,
    PHB_INFO_READ_ME,
    PHB_INFO_CHK_TOTAL
}phb_info_chk_enum;

typedef struct
{
   sim_file_index_enum primary_ID; 
   sim_file_index_enum secondary_ID;    
   phb_info_chk_enum is_usim;
   sim_file_structure_enum file_type;
   void (*child_cnf)(ilm_struct *ilm_ptr, control_block_type *cblk);
#if 0   
/* under construction !*/
#endif
}phb_build_entry_struct;


typedef struct
{
   sim_file_index_enum primary_ID; 
   phb_info_chk_enum is_usim;
   data_desc_enum desc;
   sim_service_enum sst_id;
   sim_info_type_enum info_type;
   kal_bool (*child_req)(control_block_type *cblk);
   void (*child_cnf)(ilm_struct *ilm_ptr, control_block_type *cblk);
#if 0   
/* under construction !*/
#endif
}phb_query_entry_struct;

#if 1
#define SIMU_DESC(X)
#else
/* under construction !*/
#endif

kal_int32 phb_query_count[PHB_SIM_NUM];

static phb_query_entry_struct phb_sim_info_tbl[] =
{
    /* ECC info */
#ifdef __PHB_USIM_SUPPORT__
    {
        FILE_U_ECC_IDX,   
        PHB_INFO_CHK_USIM, 
        DATA_DESC_ECC, 
        SERVICE_END,
        SIM_REC_SIZE,  
        NULL, 
        NULL, 
        SIMU_DESC(FILE_U_ECC_IDX)
    
     },
#endif /* __PHB_USIM_SUPPORT__ */
    {
        FILE_ECC_IDX,    
        PHB_INFO_CHK_SIM, 
        DATA_DESC_ECC, 
        SERVICE_END,        
        SIM_FILE_SIZE, 
        NULL, 
        NULL, 
        SIMU_DESC(FILE_ECC_IDX)
    
     },
#ifdef __PHB_USIM_SUPPORT__
    {
        FILE_G_PBR_IDX,   
        PHB_INFO_CHK_USIM, 
        DATA_DESC_PBR, 
        SERVICE_END,
        SIM_REC_SIZE,  
        NULL, 
        NULL, 
        SIMU_DESC(FILE_G_PBR_IDX)
    
    },
    {
        FILE_G_PBR_IDX,   
        PHB_INFO_READ_USIM, 
        DATA_DESC_PBR, 
        SERVICE_END,
        SIM_REC_SIZE,  
        phb_read_pbr_req,
        phb_read_pbr_cnf, 
        SIMU_DESC(FILE_G_PBR_IDX)
    
    },
#endif /* __PHB_USIM_SUPPORT__ */

#ifdef __PHB_USIM_SUPPORT__
    {
        FILE_G_ADN_IDX,   
        PHB_INFO_READ_USIM, 
        DATA_DESC_ADN,   
        SERVICE_ADN,
        SIM_REC_NUM,   
        phb_get_adn_info_req, 
        phb_get_adn_info_cnf, 
        SIMU_DESC(FILE_G_ADN_IDX)
    },
#endif        
    {
        FILE_ADN_IDX,
        PHB_INFO_CHK_SIM, 
        DATA_DESC_ADN, 
        SERVICE_ADN,
        SIM_REC_NUM,   
        NULL, 
        NULL, 
        SIMU_DESC(FILE_ADN_IDX)
    
    },
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    {
        FILE_G_IAP_IDX,   
        PHB_INFO_CHK_USIM,   
        DATA_DESC_IAP,   
        SERVICE_END,
        SIM_REC_SIZE,   
        NULL,   
        NULL,   
        SIMU_DESC(FILE_G_IAP_IDX)
    },
#ifndef __PHB_IAP_CACHE_REMOVAL__
    {
        FILE_G_IAP_IDX,   
        PHB_INFO_READ_USIM, 
        DATA_DESC_IAP, 
        SERVICE_END,
        SIM_REC_SIZE,  
        phb_read_iap_req,
        phb_read_iap_cnf, 
        SIMU_DESC(FILE_G_IAP_IDX)
    
    },
#endif /* __PHB_IAP_CACHE_REMOVAL__ */
    {
        FILE_G_ANR_IDX,   
        PHB_INFO_READ_USIM, 
        DATA_DESC_ANR,   
        SERVICE_END,
        SIM_REC_SIZE,   
        phb_get_addition_info_req,
        phb_get_addition_info_cnf,
        SIMU_DESC(FILE_G_ANR_IDX)
    },
    {
        FILE_G_AAS_IDX,   
        PHB_INFO_CHK_USIM,   
        DATA_DESC_AAS,   
        SERVICE_END,        
        SIM_REC_SIZE,   
        NULL,   
        NULL,   
        SIMU_DESC(FILE_G_AAS_IDX)
    },
    {
        FILE_G_EMAIL_IDX,   
        PHB_INFO_READ_USIM,   
        DATA_DESC_EMAIL,   
        SERVICE_END,        
        SIM_REC_SIZE,   
        phb_get_addition_info_req,
        phb_get_addition_info_cnf,
        SIMU_DESC(FILE_G_EMAIL_IDX)
    },
    {
        FILE_G_SNE_IDX,   
        PHB_INFO_READ_USIM,   
        DATA_DESC_SNE,   
        SERVICE_END,        
        SIM_REC_SIZE,   
        phb_get_addition_info_req,
        phb_get_addition_info_cnf,
        SIMU_DESC(FILE_G_SNE_IDX)
    },
    {
        FILE_G_GAS_IDX,   
        PHB_INFO_CHK_USIM,   
        DATA_DESC_GAS,   
        SERVICE_END,        
        SIM_REC_SIZE,   
        NULL,   
        NULL,   
        SIMU_DESC(FILE_G_GAS_IDX)
    },
    {
        FILE_G_GRP_IDX,   
        PHB_INFO_CHK_USIM,   
        DATA_DESC_GRP,   
        SERVICE_END,        
        SIM_REC_SIZE,   
        NULL,   
        NULL,   
        SIMU_DESC(FILE_G_GRP_IDX)
    },
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
#ifdef __PHB_USIM_SUPPORT__
    {
        FILE_U_FDN_IDX,   
        PHB_INFO_CHK_USIM, 
        DATA_DESC_FDN, 
        SERVICE_U_FDN,
        SIM_REC_SIZE,  
        NULL, 
        NULL, 
        SIMU_DESC(FILE_U_FDN_IDX)
     },
#endif /* __PHB_USIM_SUPPORT__ */
    {
        FILE_FDN_IDX,   
        PHB_INFO_CHK_SIM,   
        DATA_DESC_FDN,   
        SERVICE_FDN,
        SIM_REC_SIZE,   
        NULL,   
        NULL,   
        SIMU_DESC(FILE_FDN_IDX)
    },
#if !(defined(LOW_COST_SUPPORT) && defined(PLUTO_MMI))
#ifdef __PHB_USIM_SUPPORT__
    {
        FILE_U_BDN_IDX,   
        PHB_INFO_CHK_USIM, 
        DATA_DESC_BDN, 
        SERVICE_U_BDN,
        SIM_REC_SIZE,  
        NULL, 
        NULL, 
        SIMU_DESC(FILE_U_BDN_IDX)
     },
#endif /* __PHB_USIM_SUPPORT__ */
    {
        FILE_BDN_IDX,   
        PHB_INFO_CHK_SIM,   
        DATA_DESC_BDN,   
        SERVICE_BDN,
        SIM_REC_SIZE,   
        NULL,   
        NULL,   
        SIMU_DESC(FILE_BDN_IDX)
    },
#endif /* !(defined(LOW_COST_SUPPORT) && defined(PLUTO_MMI)) */
#ifdef __PHB_USIM_SUPPORT__
    {
        FILE_U_MSISDN_IDX,   
        PHB_INFO_CHK_USIM,   
        DATA_DESC_MSISDN,   
        SERVICE_U_MSISDN,
        SIM_REC_SIZE,   
        NULL,   
        NULL,   
        SIMU_DESC(FILE_U_MSISDN_IDX)
    },
#endif        
    {
        FILE_MSISDN_IDX,   
        PHB_INFO_CHK_SIM,   
        DATA_DESC_MSISDN,   
        SERVICE_MSISDN,
        SIM_REC_SIZE,   
        NULL,   
        NULL,   
        SIMU_DESC(FILE_MSISDN_IDX)
    },
#if !(defined(LOW_COST_SUPPORT) && defined(PLUTO_MMI))
#ifdef __PHB_USIM_SUPPORT__
    {
        FILE_U_SDN_IDX,   
        PHB_INFO_CHK_USIM, 
        DATA_DESC_SDN, 
        SERVICE_U_SDN,
        SIM_REC_SIZE,  
        NULL, 
        NULL, 
        SIMU_DESC(FILE_U_SDN_IDX)
     },
#endif /* __PHB_USIM_SUPPORT__ */
    {
        FILE_SDN_IDX,   
        PHB_INFO_CHK_SIM,   
        DATA_DESC_SDN, 
        SERVICE_SDN,
        SIM_REC_SIZE,   
        NULL,   
        NULL,   
        SIMU_DESC(FILE_SDN_IDX)
    },
#endif /* !(defined(LOW_COST_SUPPORT) && defined(PLUTO_MMI)) */
#ifdef __PHB_USIM_SUPPORT__
    {
        FILE_G_EXT1_IDX,   
        PHB_INFO_CHK_USIM,   
        DATA_DESC_EXT1,   
        SERVICE_EXT1,
        SIM_REC_SIZE,   
        NULL,   
        NULL,   
        SIMU_DESC(FILE_G_EXT1_IDX)
    },
#endif        
    {
        FILE_EXT1_IDX,   
        PHB_INFO_CHK_SIM,   
        DATA_DESC_EXT1,
        SERVICE_EXT1,
        SIM_REC_SIZE,   
        NULL,   
        NULL,   
        SIMU_DESC(FILE_EXT1_IDX)
    },
#ifdef __PHB_USIM_SUPPORT__
    {
        FILE_U_EXT2_IDX,   
        PHB_INFO_CHK_USIM,   
        DATA_DESC_EXT2,   
        SERVICE_U_EXT2,
        SIM_REC_SIZE,   
        NULL,   
        NULL,   
        SIMU_DESC(FILE_U_EXT2_IDX)
    },
#endif        
    {
        FILE_EXT2_IDX,   
        PHB_INFO_CHK_SIM,   
        DATA_DESC_EXT2,
        SERVICE_EXT2,
        SIM_REC_SIZE,   
        NULL,   
        NULL,   
        SIMU_DESC(FILE_EXT2_IDX)
    },
#if !(defined(LOW_COST_SUPPORT) && defined(PLUTO_MMI))
#ifdef __PHB_USIM_SUPPORT__
    {
        FILE_U_EXT3_IDX,   
        PHB_INFO_CHK_USIM, 
        DATA_DESC_EXT3, 
        SERVICE_U_EXT3,
        SIM_REC_SIZE,  
        NULL, 
        NULL, 
        SIMU_DESC(FILE_EXT3_IDX)
     },
#endif /* __PHB_USIM_SUPPORT__ */
    {
        FILE_EXT3_IDX,   
        PHB_INFO_CHK_SIM,   
        DATA_DESC_EXT3,   
        SERVICE_EXT3,
        SIM_REC_SIZE,   
        NULL,   
        NULL,   
        SIMU_DESC(FILE_EXT3_IDX)
    },
#ifdef __PHB_USIM_SUPPORT__
    {
        FILE_U_EXT4_IDX,   
        PHB_INFO_CHK_USIM, 
        DATA_DESC_EXT4, 
        SERVICE_U_EXT4,
        SIM_REC_SIZE,  
        NULL, 
        NULL, 
        SIMU_DESC(FILE_EXT4_IDX)
     },
#endif /* __PHB_USIM_SUPPORT__ */
    {
        FILE_EXT4_IDX,   
        PHB_INFO_CHK_SIM,   
        DATA_DESC_EXT4,   
        SERVICE_EXT4,
        SIM_REC_SIZE,   
        NULL,   
        NULL,   
        SIMU_DESC(FILE_EXT4_IDX)
    },
#endif /* !(defined(LOW_COST_SUPPORT) && defined(PLUTO_MMI)) */
#ifdef __PHB_USIM_SUPPORT__    
    {
        FILE_U_EXT5_IDX,   
        PHB_INFO_CHK_USIM,   
        DATA_DESC_EXT5,   
        SERVICE_U_EXT5,
        SIM_REC_SIZE,   
        NULL,   
        NULL,   
        SIMU_DESC(FILE_U_EXT5_IDX)
    },
#ifdef __PHB_USIM_SYNC__  
    {
        FILE_G_PBC_IDX,   
        PHB_INFO_CHK_USIM, 
        DATA_DESC_PBC, 
        SERVICE_END,
        SIM_REC_SIZE,  
        NULL,
        NULL,
        SIMU_DESC(FILE_G_PBC_IDX)
    
    },
    {
        FILE_G_CC_IDX,   
        PHB_INFO_CHK_USIM, 
        DATA_DESC_CC, 
        SERVICE_END,
        SIM_FILE_SIZE,  
        NULL,
        NULL,
        SIMU_DESC(FILE_G_CC_IDX)
    
    },
    {
        FILE_G_UID_IDX,   
        PHB_INFO_CHK_USIM, 
        DATA_DESC_UID, 
        SERVICE_END,
        SIM_REC_SIZE,  
        NULL,
        NULL,
        SIMU_DESC(FILE_G_UID_IDX)
    
    },
    {
        FILE_G_PSC_IDX,   
        PHB_INFO_CHK_USIM, 
        DATA_DESC_PSC, 
        SERVICE_END,
        SIM_FILE_SIZE,  
        NULL,
        NULL,
        SIMU_DESC(FILE_G_PSC_IDX)
    
    },
    {
        FILE_G_PUID_IDX,   
        PHB_INFO_CHK_USIM, 
        DATA_DESC_PUID, 
        SERVICE_END,
        SIM_FILE_SIZE,  
        NULL,
        NULL,
        SIMU_DESC(FILE_G_PUID_IDX)
    
    },
#endif /* __PHB_USIM_SYNC__ */   
#endif /* __PHB_USIM_SUPPORT__ */
    {0, KAL_FALSE, DATA_DESC_TOTAL, SERVICE_END, 0, NULL, NULL, SIMU_DESC(END)}
}; 

static phb_build_entry_struct *phb_build_index_tbl = NULL;

#ifdef __CANCEL_LOCK_POWERON__
static phb_build_entry_struct phb_build_index_tbl_me[] =
{
    {
        NVRAM_EF_PHB_LID,    
        FILE_NONE,
        PHB_INFO_READ_ME,
        SIM_FILE_NO_STRUCTURE,
        phb_build_me,
        SIMU_DESC(NVRAM_EF_PHB_LID)
     },
     
    {FILE_NONE, FILE_NONE, PHB_INFO_CHK_TOTAL, SIM_FILE_NO_STRUCTURE, NULL, SIMU_DESC(END)},
         
};
#endif /* __CANCEL_LOCK_POWERON__ */

static phb_build_entry_struct phb_build_index_tbl_full[] =
{
#ifdef __PHB_USIM_SUPPORT__
        {
            FILE_U_ECC_IDX,
            FILE_NONE,
            PHB_INFO_READ_USIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_ecc,
            SIMU_DESC(FILE_U_ECC_IDX)
         },
#endif /* __PHB_USIM_SUPPORT__ */
        {
            FILE_ECC_IDX,    
            FILE_NONE,
            PHB_INFO_READ_SIM, 
            SIM_FILE_TRANSP,
            phb_build_ecc,
            SIMU_DESC(FILE_ECC_IDX)
         },
#ifdef __PHB_USIM_SUPPORT__
        {
            FILE_U_FDN_IDX,
            FILE_U_EXT2_IDX,
            PHB_INFO_READ_USIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_fdn,
            SIMU_DESC(FILE_U_FDN_IDX)
         },
#endif /* __PHB_USIM_SUPPORT__ */
        {
            FILE_FDN_IDX,    
            FILE_EXT2_IDX,
            PHB_INFO_READ_SIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_fdn,
            SIMU_DESC(FILE_FDN_IDX)
         },
#ifdef __ECALL_SUPPORT__
#ifdef __PHB_USIM_SUPPORT__
        {
            FILE_U_SDN_IDX,
            FILE_U_EXT3_IDX,
            PHB_INFO_READ_USIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_sdn,
            SIMU_DESC(FILE_U_SDN_IDX)
         },
#endif /* __PHB_USIM_SUPPORT__ */
        {
            FILE_SDN_IDX,    
            FILE_EXT3_IDX,
            PHB_INFO_READ_SIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_sdn,
            SIMU_DESC(FILE_SDN_IDX)
         },
#endif /* __ECALL_SUPPORT__ */
#ifndef __PHB_STORAGE_BY_MMI__
        {
            NVRAM_EF_PHB_LID,    
            FILE_NONE,
            PHB_INFO_READ_ME,
            SIM_FILE_NO_STRUCTURE,
            phb_build_me,
            SIMU_DESC(NVRAM_EF_PHB_LID)
         },
#endif /* __PHB_STORAGE_BY_MMI__ */
#ifdef __PHB_USIM_SUPPORT__
        {
            FILE_G_ADN_IDX,
            FILE_G_EXT1_IDX,
            PHB_INFO_READ_USIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_adn,
            SIMU_DESC(FILE_G_ADN_IDX)
         },
#endif /* __PHB_USIM_SUPPORT__ */
        {
            FILE_ADN_IDX,    
            FILE_EXT1_IDX,
            PHB_INFO_READ_SIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_adn,
            SIMU_DESC(FILE_ADN_IDX)
         },
#if !(defined(LOW_COST_SUPPORT) && defined(PLUTO_MMI))
#ifdef __PHB_USIM_SUPPORT__
        {
            FILE_U_BDN_IDX,
            FILE_U_EXT4_IDX,
            PHB_INFO_READ_USIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_bdn,
            SIMU_DESC(FILE_U_BDN_IDX)
         },
#endif /* __PHB_USIM_SUPPORT__ */
        {
            FILE_BDN_IDX,    
            FILE_EXT4_IDX,
            PHB_INFO_READ_SIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_bdn,
            SIMU_DESC(FILE_BDN_IDX)
         },
#endif /* !(defined(LOW_COST_SUPPORT) && defined(PLUTO_MMI)) */
        {
            FILE_MSISDN_IDX,    
            FILE_EXT1_IDX,
            PHB_INFO_READ_SIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_next,
            SIMU_DESC(FILE_MSISDN_IDX)
         },
#ifdef __PHB_USIM_SUPPORT__
        {
            FILE_U_MSISDN_IDX,
            FILE_U_EXT5_IDX,
            PHB_INFO_READ_USIM,
            SIM_FILE_LINEAR_FIXED,
            phb_build_next,
            SIMU_DESC(FILE_U_MSISDN_IDX)
         },
        {
            FILE_G_EXT1_IDX,
            FILE_NONE,
            PHB_INFO_READ_USIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_next,
            SIMU_DESC(FILE_G_EXT1_IDX)
         },
#endif /* __PHB_USIM_SUPPORT__ */
        {
            FILE_EXT1_IDX,    
            FILE_NONE,
            PHB_INFO_READ_SIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_next,
            SIMU_DESC(FILE_EXT1_IDX)
         },
#ifdef __PHB_USIM_SUPPORT__
        {
            FILE_U_EXT2_IDX,
            FILE_NONE,
            PHB_INFO_READ_USIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_next,
            SIMU_DESC(FILE_U_EXT2_IDX)
         },
#endif /* __PHB_USIM_SUPPORT__ */
        {
            FILE_EXT2_IDX,    
            FILE_NONE,
            PHB_INFO_READ_SIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_next,
            SIMU_DESC(FILE_EXT2_IDX)
         },
#if !(defined(LOW_COST_SUPPORT) && defined(PLUTO_MMI))
#ifdef __PHB_USIM_SUPPORT__
        {
            FILE_U_EXT4_IDX,
            FILE_NONE,
            PHB_INFO_READ_USIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_next,
            SIMU_DESC(FILE_EXT4_IDX)
         },
#endif /* __PHB_USIM_SUPPORT__ */
         {
            FILE_EXT4_IDX,    
            FILE_NONE,
            PHB_INFO_READ_SIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_next,
            SIMU_DESC(FILE_EXT4_IDX)
         },
#endif /* !(defined(LOW_COST_SUPPORT) && defined(PLUTO_MMI)) */
#ifdef __PHB_USIM_SUPPORT__
         {
            FILE_U_EXT5_IDX,    
            FILE_NONE,
            PHB_INFO_READ_USIM, 
            SIM_FILE_LINEAR_FIXED,
            phb_build_next,
            SIMU_DESC(FILE_U_EXT5_IDX)
         },
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__    
        {
            FILE_G_AAS_IDX,   
            FILE_NONE, 
            PHB_INFO_READ_USIM, 
            SIM_FILE_LINEAR_FIXED,  
            phb_build_next,
            SIMU_DESC(FILE_G_AAS_IDX)
        
        },
        {
            FILE_G_GAS_IDX,   
            FILE_NONE, 
            PHB_INFO_READ_USIM, 
            SIM_FILE_LINEAR_FIXED,  
            phb_build_next,
            SIMU_DESC(FILE_G_GAS_IDX)
        
        },
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */   
#ifdef __PHB_USIM_SYNC__    
        {
            FILE_G_PBC_IDX,   
            FILE_NONE, 
            PHB_INFO_READ_USIM, 
            SIM_FILE_LINEAR_FIXED,  
            phb_build_pbc,
            SIMU_DESC(FILE_G_PBC_IDX)
        
        },
        {
            FILE_G_CC_IDX,   
            FILE_NONE, 
            PHB_INFO_READ_USIM, 
            SIM_FILE_TRANSP,  
            phb_build_transfm,
            SIMU_DESC(FILE_G_CC_IDX)
        
        },
/*        
        {
            FILE_G_UID_IDX,   
            FILE_NONE, 
            PHB_INFO_READ_USIM, 
            SIM_FILE_LINEAR_FIXED,  
            phb_build_next,
            SIMU_DESC(FILE_G_UID_IDX)
        },
*/        
        {
            FILE_G_PSC_IDX,   
            FILE_NONE, 
            PHB_INFO_READ_USIM, 
            SIM_FILE_TRANSP,  
            phb_build_transfm,
            SIMU_DESC(FILE_G_PSC_IDX)
        
        },
        {
            FILE_G_PUID_IDX,   
            FILE_NONE, 
            PHB_INFO_READ_USIM, 
            SIM_FILE_TRANSP,  
            phb_build_transfm,
            SIMU_DESC(FILE_G_PUID_IDX)
        
        },
#endif /* __PHB_USIM_SYNC__ */   
         
#endif /* __PHB_USIM_SUPPORT__ */
        {FILE_NONE, FILE_NONE, PHB_INFO_CHK_TOTAL, SIM_FILE_NO_STRUCTURE, NULL, SIMU_DESC(END)},
         
};


#ifdef __PHB_USIM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  phb_read_pbr_cnf
 * DESCRIPTION
 *  This is phb_read_pbr function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/

static void phb_read_pbr_cnf(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Reading PBR */
    kal_uint8 pos = 0;
    kal_uint8 count = 0;
    kal_uint8 adn = 0, ext1 = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (phb_ptr->is_fdn_change == KAL_TRUE)
    {
        kal_trace(TRACE_INFO, INFO_PHB_INDICES_BUILT);
        phb_ptr->state = PHB_STATE_READY;
        kal_trace(TRACE_STATE, STATE_PHB_READY);
        phb_startup_confirm(PHB_ERRNO_SUCCESS, cblk);
        phb_query_count[phb_which_sim_ex()] = 0;
        return;
    }
    if (cblk->actual_count < PHB_MAX_PBR_ENTRIES)
    {
    #ifdef __PHB_USIM_SYNC__                      
        kal_uint8 uid = 0, pbc = 0;
    #endif    
    #ifdef __PHB_USIM_SUPPORT__
        kal_uint8 aas = 0, gas = 0, anr = 0, sne = 0, email = 0;
		kal_int16 iap_pos = -1;
    #endif
        kal_uint16 i = cblk->actual_count;
        kal_uint8 fileType = 0;

        while (pos < phb_ptr->data_desc[DATA_DESC_PBR].record_size)
        {
            data_desc_enum do_type = 0xFE;
            kal_uint8 jmp_len = 0;

            switch (cblk->data[pos])
            {
            /* looking for file type first */
                case PHB_TYPE_1_FILE:
                    fileType = 1;
                    break;
                case PHB_TYPE_2_FILE:
                    fileType = 2;
                    break;
                case PHB_TYPE_3_FILE:
                    fileType = 3;
                    break;

             /* EF info */
                case PHB_ADN_DO:
                    if (fileType == 2)
                    {
                        goto error_handling;
                    }
                    do_type = DATA_DESC_ADN;
                    if (++adn > 1)
                    {
                        do_type = 0xFF;
                    }
                    break;
            #ifdef __PHB_USIM_SYNC__                      
                case PHB_PBC_DO:
                    do_type = DATA_DESC_PBC;
                    if (++pbc > 1)
                    {
                        do_type = 0xFF;
                    }
                    break;
                case PHB_UID_DO:
                    do_type = DATA_DESC_UID;
                    if (++uid > 1)
                    {
                        do_type = 0xFF;
                    }
                    break;
            #endif /* __PHB_USIM_SYNC__ */                   
                case PHB_EXT1_DO:
                    do_type = DATA_DESC_EXT1;
                    if (++ext1 > 1)
                    {
                        do_type = 0xFF;
                    }
                    break;
            #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
                case PHB_IAP_DO:
                    do_type = DATA_DESC_IAP;
                    break;
                    
                case PHB_SNE_DO:
                    do_type = DATA_DESC_SNE + sne;
                    if (++sne > PHB_MAX_SNE_OCC)
                    {
                        do_type = 0xFF;
                    }
                    break;
                    
                case PHB_ANR_DO:
                    do_type = DATA_DESC_ANR + anr;
                    if (++anr > PHB_MAX_ANR_OCC)
                    {
                        do_type = 0xFF;
                    }
                    break;
                    
                case PHB_EMAIL_DO:
                    do_type = DATA_DESC_EMAIL + email;
                    if (++email > PHB_MAX_EMAIL_OCC)
                    {
                        do_type = 0xFF;
                    }
                    break;
                    
                case PHB_GRP_DO:
                    do_type = DATA_DESC_GRP;
                    break;
                    
                case PHB_AAS_DO:
                    do_type = DATA_DESC_AAS;
                    if (++aas > 1)
                    {
                        do_type = 0xFF;
                    }
                    break;
                case PHB_GAS_DO:
                    do_type = DATA_DESC_GAS;
                    if (++gas > 1)
                    {
                        do_type = 0xFF;
                    }
                    break;
                case PHB_CCP1_DO:
                    // TODO: CCP1 support
            #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
            
                default:
                    do_type = 0xFF;
                    break;
            }


            if (do_type == 0xFE) /* file type tag */
            {
                jmp_len = 2;
            }
            else 
            {
                do
                {
                    if(do_type != 0xFF)
                    {
                        if (fileType == 2)
                        {
                            /* 1 sne, 3 anr, 1 email */
                            if (iap_pos < (PHB_MAX_TYPE2_ENTRIES + 1))
                            {
                                iap_pos++;
                            }
                            else
                            {
                                break;
                            }
                        }

                        if (cblk->data[pos + 1] == 3)  /* add length + 1 */
                        {
                            phb_desc_set_pbr_tbl(
                                        count,
                                        i,
                                        do_type,
                                        fileType,
                                        (kal_uint8)iap_pos,
                                        &cblk->data[pos + 2],
                                        cblk->data[pos + 4]);
                        }
                        else
                        {
                            phb_desc_set_pbr_tbl(
                                        count,
                                        i,
                                        do_type,
                                        fileType,
                                        (kal_uint8)iap_pos,
                                        &cblk->data[pos + 2],
                                        0);
                        }
                        count++;
                        
                        /* 
                         * according to 4.4.2.14, 
                         * if an EFPBR file contains more than one record, then they 
                         * shall all be formatted identically on a type-by-type basis
                         */
                        if (!i)
                        {
                            phb_ptr->data_desc[do_type].is_support = KAL_TRUE;
                            
                        #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
                            if (fileType == 2)                            
                            {
                                phb_ptr->data_desc[do_type].pbr_pos |= PHB_TYPE2_FILE_FLAG;
                            }
                        #endif
                        } 
                    }
                }while(0);
                jmp_len = cblk->data[pos + 1] + 2;
            }
            pos += jmp_len;
        }
        if (!i)
        {
        #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
            phb_ptr->anr_count = anr;
            phb_ptr->sne_count = sne;
            phb_ptr->email_count = email;
        #endif
        }
    }

error_handling:
    cblk->actual_count++;
    
    if (!adn)
    {
        phb_ptr->data_desc[DATA_DESC_PBR].record_num--;
    }

    if (cblk->actual_count < cblk->total &&
        cblk->actual_count < PHB_MAX_PBR_ENTRIES)
    {
        ++cblk->record_index;
        phb_issue_IO_read(cblk);
    }
    else
    {
        /* phb_startup_handler */
        (*cblk->controller) (NULL, cblk);
    }
}


static kal_bool phb_read_pbr_req(control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (phb_ptr->data_desc[DATA_DESC_PBR].record_num > 0)
    {
        cblk->record_index = 1;
        cblk->length = phb_ptr->data_desc[DATA_DESC_PBR].record_size;
        phb_control_block_set_IO(cblk, PHB_NONE, 1, phb_ptr->data_desc[DATA_DESC_PBR].record_num);
        cblk->storage = phb_which_sim_storage();

        phb_issue_IO_read(cblk);
        return KAL_TRUE;
    }
    return KAL_FALSE;
}


#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
#ifndef __PHB_IAP_CACHE_REMOVAL__
static void phb_read_iap_cnf(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cblk->actual_count < ADN_INDEX_MAX_ENTRIES_COUNT)
    {
        kal_mem_cpy(phb_ptr->iap_array[cblk->actual_count], cblk->data, PHB_MAX_TYPE2_ENTRIES);
    }

    cblk->actual_count++;

    if (cblk->actual_count < cblk->total &&
        cblk->actual_count < ADN_INDEX_MAX_ENTRIES_COUNT)
    {
        ++cblk->record_index;
        phb_issue_IO_read(cblk);
    }
    else
    {
        /* phb_startup_handler */
        (*cblk->controller) (NULL, cblk);
    }
}


static kal_bool phb_read_iap_req(control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (phb_ptr->data_desc[DATA_DESC_IAP].record_num > 0)
    {
        cblk->record_index = 1;
        cblk->length = phb_ptr->data_desc[DATA_DESC_IAP].record_size;
        phb_control_block_set_IO(cblk, PHB_NONE, 1, phb_ptr->data_desc[DATA_DESC_IAP].record_num);
        cblk->storage = phb_which_sim_storage();

        phb_issue_IO_read(cblk);
        return KAL_TRUE;
    }
    return KAL_FALSE;
}
#endif /* __PHB_IAP_CACHE_REMOVAL__ */
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */


static void phb_get_adn_info_cnf(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_file_info_cnf_struct *sim_file_info_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_file_info_cnf = (sim_file_info_cnf_struct*) ilm_ptr->local_para_ptr;

    if (cblk->actual_count <= phb_ptr->data_desc[DATA_DESC_PBR].record_num)
    {
        kal_uint8 pos = phb_desc_get_pbr_pos(DATA_DESC_ADN);
        /* all record size is same, only set once */
        if (!phb_ptr->data_desc[DATA_DESC_ADN].record_size && (sim_file_info_cnf->num_of_rec > 0))
        {
            phb_ptr->data_desc[DATA_DESC_ADN].record_size = 
                (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec);
        
            phb_desc_set_alpha_len(DATA_DESC_ADN, phb_ptr->data_desc[DATA_DESC_ADN].record_size - 14);
            /* 
             * Sad. can't count on service table.
             * Supported either ADN or U_ADN is supported and record_num * record_size > 0
             */
        #if 0 /* USIM spec does not mention it, also should not parse the USIM response data as SIM response data!! */
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
        #endif
        }

        if ((sim_file_info_cnf->num_of_rec > 0) && phb_ptr->data_desc[DATA_DESC_ADN].record_size != (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec))
        {
            phb_ptr->data_desc[DATA_DESC_PBR].record_num = (kal_uint8)(cblk->actual_count - 1);
            (*cblk->controller) (NULL, cblk);
            return;
        }
    
        if ((phb_ptr->data_desc[DATA_DESC_ADN].record_num + sim_file_info_cnf->num_of_rec) < MAX_PHB_SIM_ENTRY)
        {
            phb_ptr->data_desc[DATA_DESC_ADN].record_num += sim_file_info_cnf->num_of_rec;
            phb_ptr->phb_pbr_table[pos][cblk->actual_count - 1].record_num = sim_file_info_cnf->num_of_rec;
        }
        else
        {
            phb_ptr->phb_pbr_table[pos][cblk->actual_count - 1].record_num = MAX_PHB_SIM_ENTRY - phb_ptr->data_desc[DATA_DESC_ADN].record_num;
            phb_ptr->data_desc[DATA_DESC_ADN].record_num = MAX_PHB_SIM_ENTRY;
            
            phb_ptr->data_desc[DATA_DESC_PBR].record_num = (kal_uint8)cblk->actual_count;
            (*cblk->controller) (NULL, cblk);
            return;
        }
    }
    
    cblk->actual_count++;

    if (cblk->actual_count <= cblk->total &&
        cblk->actual_count <= phb_ptr->data_desc[DATA_DESC_PBR].record_num)
    {
        phb_desc_get_file_path(cblk->primary_ID, 1, (kal_uint8)cblk->actual_count, cblk->path);

        phb_sim_file_info(cblk, SIM_REC_SIZE);
    }
    else
    {
        /* phb_startup_handler */
        (*cblk->controller) (NULL, cblk);
    }
}


static kal_bool phb_get_adn_info_req(control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (phb_ptr->data_desc[DATA_DESC_PBR].record_num > 0)
    {
        cblk->actual_count = 1;
        cblk->total = phb_ptr->data_desc[DATA_DESC_PBR].record_num;
        if (phb_desc_get_file_path(cblk->primary_ID, 1, (kal_uint8)cblk->actual_count, cblk->path))
		{
            phb_sim_file_info(cblk, SIM_REC_SIZE);
            return KAL_TRUE;
		}
    }
    return KAL_FALSE;
}


#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  phb_read_pbr_cnf
 * DESCRIPTION
 *  This is phb_read_pbr function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_get_addition_info_cnf(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_file_info_cnf_struct *sim_file_info_cnf;
    data_desc_enum file;
    kal_uint8 pos;
    phb_pbr_tbl_struct* pbr_tbl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_file_info_cnf = (sim_file_info_cnf_struct*) ilm_ptr->local_para_ptr;

    switch (cblk->primary_ID)
    {
        case FILE_G_ANR_IDX:
        case FILE_U_ANR_IDX:
            file = DATA_DESC_ANR + cblk->occurrence - 1;
            break;

        case FILE_G_EMAIL_IDX:
        case FILE_U_EMAIL_IDX:
            file = DATA_DESC_EMAIL + cblk->occurrence - 1;
            break;
        
        case FILE_G_SNE_IDX:
        case FILE_U_SNE_IDX:
            file = DATA_DESC_SNE + cblk->occurrence - 1;
            break;
            
        default:
            ASSERT(0);
            return;
    }
    
    pos = phb_desc_get_pbr_pos(file);
    pbr_tbl = &(phb_ptr->phb_pbr_table[pos][cblk->actual_count - 1]);
    /* all record size is same, only set once */
    if (!phb_ptr->data_desc[file].record_size && (sim_file_info_cnf->num_of_rec > 0))
    {
        phb_ptr->data_desc[file].record_size = 
            (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec);
    }

    if (pbr_tbl->filetype == 2)
    {
        pbr_tbl->record_num =
            (sim_file_info_cnf->num_of_rec < TYPE2_FILE_MAX_ENTRIES_COUNT) ?
            sim_file_info_cnf->num_of_rec : TYPE2_FILE_MAX_ENTRIES_COUNT;
        pbr_tbl->free_count = pbr_tbl->record_num;
        phb_ptr->data_desc[file].record_num += pbr_tbl->record_num;
        if (!phb_desc_get_alpha_len(file))
        {
            phb_desc_set_alpha_len(file, phb_ptr->data_desc[file].record_size - 2);
        }
    }
    else
    {
        phb_ptr->data_desc[file].record_num = phb_ptr->data_desc[DATA_DESC_ADN].record_num;
        if (!phb_desc_get_alpha_len(file))
        {
            phb_desc_set_alpha_len(file, (kal_uint8)phb_ptr->data_desc[file].record_size);
        }
    }
    
    if (pbr_tbl->filetype == 2 && cblk->actual_count <= phb_ptr->data_desc[DATA_DESC_PBR].record_num)
    {
        cblk->actual_count++;
		phb_ptr->data_desc[file].free_count = phb_ptr->data_desc[file].record_num;
    }
    else
    {
        cblk->actual_count = 1;
        cblk->occurrence++;
    }
    if (cblk->occurrence <= cblk->total)
    {
        if (phb_desc_get_file_path(cblk->primary_ID, (kal_uint8)cblk->occurrence, cblk->actual_count, cblk->path))
        {
            phb_sim_file_info(cblk, SIM_REC_SIZE);
            return;
        }
    }
    /* phb_startup_handler */
    (*cblk->controller) (NULL, cblk);
}

static kal_bool phb_get_addition_info_req(control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cblk->actual_count = 1;
    switch (cblk->primary_ID)
    {
        case FILE_G_ANR_IDX:
            cblk->total = phb_ptr->anr_count;
            break;
            
        case FILE_G_SNE_IDX:
            cblk->total = phb_ptr->sne_count;
            break;
            
        case FILE_G_EMAIL_IDX:
            cblk->total = phb_ptr->email_count;
            break;
        default:
            return KAL_FALSE;
    }
    cblk->occurrence = 1;
    while (cblk->occurrence <= cblk->total &&
           cblk->actual_count <= phb_ptr->data_desc[DATA_DESC_PBR].record_num)
    {
        if (!phb_desc_get_file_path(cblk->primary_ID, (kal_uint8)cblk->occurrence, cblk->actual_count, cblk->path))
        {
            return KAL_FALSE;
        }
        phb_sim_file_info(cblk, SIM_REC_SIZE);
        return KAL_TRUE;
    }
    return KAL_FALSE;
}
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
#endif /* _USIM_SUPPORT__ */



/*****************************************************************************
 * FUNCTION
 *  phb_is_sim_file_support
 * DESCRIPTION
 *  To query sim module if phb related file support.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void phb_is_sim_file_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__GEMINI__) || defined(GEMINI_PLUS) || defined(__SGLTE__)
    kal_trace(TRACE_INFO, FUNC_PHB_IS_SIM_FILE_SUPPORT, chv_status[phb_current_mod - MOD_PHB].chv1_status);
    if (chv_status[phb_current_mod - MOD_PHB].chv1_status == CHV_BLOCKED || chv_status[phb_current_mod - MOD_PHB].chv1_status == CHV_DEAD)
#else
    kal_trace(TRACE_INFO, FUNC_PHB_IS_SIM_FILE_SUPPORT, chv_status[0].chv1_status);
    if (chv_status[0].chv1_status == CHV_BLOCKED || chv_status[0].chv1_status == CHV_DEAD)
#endif
    {
        /* SIM is blocked, then all phb related file set to be not supported */
        phb_data_desc_set_is_support(DATA_DESC_ADN, KAL_FALSE);

        phb_data_desc_set_is_support(DATA_DESC_EXT1, KAL_FALSE);

        phb_data_desc_set_is_support(DATA_DESC_FDN, KAL_FALSE);

        phb_data_desc_set_is_support(DATA_DESC_BDN, KAL_FALSE);

        phb_data_desc_set_is_support(DATA_DESC_MSISDN, KAL_FALSE);

        phb_data_desc_set_is_support(DATA_DESC_SDN, KAL_FALSE);

        phb_data_desc_set_is_support(DATA_DESC_EXT2, KAL_FALSE);

        phb_data_desc_set_is_support(DATA_DESC_EXT3, KAL_FALSE);
    }
    else
    {

        phb_data_desc_set_is_support(DATA_DESC_ADN, PHB_SIM_SERVICE_TABLE_QUERY(SERVICE_ADN));
        phb_data_desc_set_is_support(DATA_DESC_EXT1, PHB_SIM_SERVICE_TABLE_QUERY(SERVICE_EXT1));

        phb_data_desc_set_is_support(DATA_DESC_FDN, PHB_SIM_SERVICE_TABLE_QUERY(SERVICE_FDN));

        phb_data_desc_set_is_support(DATA_DESC_BDN, PHB_SIM_SERVICE_TABLE_QUERY(SERVICE_BDN));

        phb_data_desc_set_is_support(DATA_DESC_MSISDN, PHB_SIM_SERVICE_TABLE_QUERY(SERVICE_MSISDN));

        phb_data_desc_set_is_support(DATA_DESC_SDN, PHB_SIM_SERVICE_TABLE_QUERY(SERVICE_SDN));

        phb_data_desc_set_is_support(DATA_DESC_EXT2, PHB_SIM_SERVICE_TABLE_QUERY(SERVICE_EXT2));

        phb_data_desc_set_is_support(DATA_DESC_EXT3, PHB_SIM_SERVICE_TABLE_QUERY(SERVICE_EXT3));
        
    }
}


void phb_get_info(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // TODO: is this function thread-safe?, i.e. access by PHB1 and PHB2
    kal_uint8 curr_sim = phb_which_sim_ex();
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    while (phb_query_count[curr_sim] >=0 && phb_sim_info_tbl[phb_query_count[curr_sim]].primary_ID)
    {
        data_desc_enum desc = phb_sim_info_tbl[phb_query_count[curr_sim]].desc;
        sim_service_enum sst_id = phb_sim_info_tbl[phb_query_count[curr_sim]].sst_id;
    #ifdef __PHB_USIM_SUPPORT__
        phb_sim_info_tbl[phb_query_count[curr_sim]].primary_ID = 
            phb_desc_get_used_file_id(phb_sim_info_tbl[phb_query_count[curr_sim]].primary_ID);
    #endif
        kal_trace(TRACE_INFO, PHB_TRC_GET_INFO, phb_sim_info_tbl[phb_query_count[curr_sim]].primary_ID);
        
        if (sst_id != SERVICE_END)
        {
        #if defined(__GEMINI__) || defined(GEMINI_PLUS) || defined(__SGLTE__)
            if (chv_status[phb_current_mod - MOD_PHB].chv1_status == CHV_BLOCKED || chv_status[phb_current_mod - MOD_PHB].chv1_status == CHV_DEAD)
        #else
            if (chv_status[0].chv1_status == CHV_BLOCKED || chv_status[0].chv1_status == CHV_DEAD)
        #endif
            {
                phb_data_desc_set_is_support(desc, KAL_FALSE);
            }
            else
            {
                phb_data_desc_set_is_support(desc, PHB_SIM_SERVICE_TABLE_QUERY(sst_id));
            }

            if (!phb_ptr->data_desc[desc].is_support)
            {
            #ifdef __PHB_USIM_SUPPORT__
                if (desc == DATA_DESC_PBR && phb_ptr->is_global)
                {
                    phb_ptr->is_global = KAL_FALSE;
                    continue;
                }
            #endif
                phb_query_count[curr_sim]++;
            #ifndef __LOW_COST_SUPPORT_COMMON__
                kal_trace(TRACE_INFO, PHB_TRC_GET_INFO_NOT_SUPPORT, __LINE__);
            #endif
                continue;
            }
        }

    #ifdef __PHB_USIM_SUPPORT__
        if (phb_sim_info_tbl[phb_query_count[curr_sim]].is_usim != PHB_INFO_CHK_TOTAL)
        {
            kal_bool usim = phb_util_is_usim(curr_sim);
            if ((phb_sim_info_tbl[phb_query_count[curr_sim]].is_usim == PHB_INFO_CHK_USIM && !usim) ||
                (phb_sim_info_tbl[phb_query_count[curr_sim]].is_usim == PHB_INFO_READ_USIM && !usim) ||
                (phb_sim_info_tbl[phb_query_count[curr_sim]].is_usim == PHB_INFO_CHK_SIM && usim))
            {
                if (usim && phb_sim_info_tbl[phb_query_count[curr_sim]].primary_ID == FILE_ADN_IDX &&
                    phb_ptr->data_desc[DATA_DESC_PBR].record_num == 0)
                {
                    /* This is special USIM card which does not support USIM phonebook */
                    /* So we read SIM phonebook and make SIM storage accessible */
                }
                else
                {
                    phb_query_count[curr_sim]++;
                #ifndef __LOW_COST_SUPPORT_COMMON__
                    kal_trace(TRACE_INFO, PHB_TRC_GET_INFO_NOT_SUPPORT, __LINE__);
                #endif
                    continue;
                }
            }
        }
    #endif
        cblk->primary_ID = phb_sim_info_tbl[phb_query_count[curr_sim]].primary_ID;
        cblk->secondary_ID = PHB_NULL_VALUE;
        cblk->storage = phb_which_sim_storage();

        if (phb_sim_info_tbl[phb_query_count[curr_sim]].is_usim == PHB_INFO_READ_USIM)
        {
            phb_control_block_set(
                cblk,
                phb_sim_info_tbl[phb_query_count[curr_sim]].child_cnf,
                phb_get_info,
                phb_get_info_err_handler,
                startup_info_sim);
            
            if (phb_sim_info_tbl[phb_query_count[curr_sim]++].child_req(cblk))
            {
                return;
            }
            else
            {
                continue;
            }
        }
    #ifdef __PHB_USIM_SUPPORT__
        if (phb_util_is_usim(curr_sim) && phb_sim_info_tbl[phb_query_count[curr_sim]].is_usim == PHB_INFO_CHK_USIM)
        {
            /* 
             * according to 4.4.2.14, 
             * if an EFPBR file contains more than one record, then they 
             * shall all be formatted identically on a type-by-type basis
             */
        #if 1
            if (!phb_desc_get_file_path(cblk->primary_ID, 1, 1, cblk->path))
            {
                phb_query_count[curr_sim]++;
            #ifndef __LOW_COST_SUPPORT_COMMON__
                kal_trace(TRACE_INFO, PHB_TRC_GET_INFO_NOT_SUPPORT, __LINE__);
            #endif
                continue;
            }
        #else
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
        #endif
        }
    #endif        
        phb_control_block_set(
            cblk,
            phb_get_info_set_value,
            phb_get_info,
            phb_get_info_err_handler,
            startup_info_sim);
        
        phb_sim_file_info(cblk, phb_sim_info_tbl[phb_query_count[curr_sim]++].info_type);
        return;
    }
   
   // TODO: Should be another FSM
   if (phb_query_count[curr_sim] > 0)
   {
   #ifndef __PHB_STORAGE_BY_MMI__
       phb_query_count[curr_sim] = -1;
       phb_control_block_set(
           cblk,
           phb_get_info,
           phb_startup_handler,
           phb_get_info_err_handler,
           startup_info_compare_digit);
   
       phb_nvram_read_compare_digit(cblk);
       return;
   #else /* __PHB_STORAGE_BY_MMI__ */
       cblk->controller = phb_startup_handler;
   #endif /* __PHB_STORAGE_BY_MMI__ */
   }
    phb_query_count[curr_sim] = 0;
    kal_trace(TRACE_INFO, INFO_PHB_FILE_INFO_GOT);
    (*cblk->controller) (NULL, cblk);
}   /* end of phb_get_info function */


/*****************************************************************************
 * FUNCTION
 *  phb_get_info_set_value
 * DESCRIPTION
 *  This is get_info_set_value function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_get_info_set_value(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_file_info_cnf_struct *sim_file_info_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_file_info_cnf = (sim_file_info_cnf_struct*) ilm_ptr->local_para_ptr;

    switch (cblk->primary_ID)
    {
        case FILE_ECC_IDX:
            phb_ptr->data_desc[DATA_DESC_ECC].is_support= KAL_TRUE;
            phb_data_desc_set(DATA_DESC_ECC, sim_file_info_cnf->length/NUM_OF_BYTE_ECC, NUM_OF_BYTE_ECC);
            break;

    #ifdef __PHB_USIM_SUPPORT__    
        case FILE_U_ECC_IDX:
            if (sim_file_info_cnf->length >= 4)
            {
                phb_ptr->data_desc[DATA_DESC_ECC].is_support= KAL_TRUE;
                
                phb_ptr->data_desc[DATA_DESC_ECC].record_num =
                    (sim_file_info_cnf->num_of_rec <= ECC_MAX_ENTRIES_COUNT) ? 
                    sim_file_info_cnf->num_of_rec : ECC_MAX_ENTRIES_COUNT;
                /* Record size = X + 4 */
                phb_ptr->data_desc[DATA_DESC_ECC].record_size = sim_file_info_cnf->length;
            
                /* Alpha ID length = (X + 4) - 3 - 4; 3:ECC code, 4: Emergency Service Category */
                phb_ptr->data_desc[DATA_DESC_ECC].alpha_length = phb_ptr->data_desc[DATA_DESC_ECC].record_size - 4;
            
                /* SIM module max name length needs to check */
                if (MAX_SIM_NAME_LEN < phb_ptr->data_desc[DATA_DESC_ECC].alpha_length)
                {
                    phb_ptr->data_desc[DATA_DESC_ECC].alpha_length = MAX_SIM_NAME_LEN;
                }
            }
            break;

    #ifdef __PHB_USIM_SYNC__
        /* transparent */
        case FILE_G_PSC_IDX:
        case FILE_U_PSC_IDX:
        {
            if (sim_file_info_cnf->length == 4) /* PSCC length must be 4*/
            {
                data_desc_enum des_id = phb_data_desc_file_id_to_desc(cblk->primary_ID, 1);
                
                phb_ptr->data_desc[des_id].is_support = KAL_TRUE;
                phb_ptr->data_desc[des_id].record_num = 1;
                phb_ptr->data_desc[des_id].record_size = sim_file_info_cnf->length;
            }
            break;
        }
        
        case FILE_G_CC_IDX:
        case FILE_U_CC_IDX:
        case FILE_G_PUID_IDX:
        case FILE_U_PUID_IDX:
        {
            if (sim_file_info_cnf->length == 2) /* CC & PUID length must be 2*/
            {
                data_desc_enum des_id = phb_data_desc_file_id_to_desc(cblk->primary_ID, 1);
                
                phb_ptr->data_desc[des_id].is_support = KAL_TRUE;
                phb_ptr->data_desc[des_id].record_num = 1;
                phb_ptr->data_desc[des_id].record_size = sim_file_info_cnf->length;
            }
            break;
        }            
        
        /* linear fixed */
        case FILE_G_PBC_IDX:
        case FILE_U_PBC_IDX:
        case FILE_G_UID_IDX:
        case FILE_U_UID_IDX:
        {
            if (sim_file_info_cnf->length == 2) /* PBC & UID length must be 2*/
            {
                data_desc_enum des_id = phb_data_desc_file_id_to_desc(cblk->primary_ID, 1);
                
                phb_ptr->data_desc[des_id].is_support = KAL_TRUE;
                phb_ptr->data_desc[des_id].record_num =  phb_ptr->data_desc[DATA_DESC_ADN].record_num;
                phb_ptr->data_desc[des_id].record_size = sim_file_info_cnf->length;
            }
            break;
        }            
    #endif /* __PHB_USIM_SYNC__ */
        case FILE_U_EXT5_IDX:
        {
            phb_ptr->data_desc[DATA_DESC_EXT5].is_support = KAL_TRUE;
            phb_ptr->data_desc[DATA_DESC_EXT5].record_num =
                (sim_file_info_cnf->num_of_rec < EXT5_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->num_of_rec : EXT5_MAX_ENTRIES_COUNT;
            phb_ptr->data_desc[DATA_DESC_EXT5].record_size = sim_file_info_cnf->length;
            phb_ptr->data_desc[DATA_DESC_EXT5].free_count = phb_ptr->data_desc[DATA_DESC_EXT5].record_num;
            if (phb_ptr->data_desc[DATA_DESC_EXT5].free_bitmap != NULL)
            {
                kal_mem_set(
                    phb_ptr->data_desc[DATA_DESC_EXT5].free_bitmap,
                    0xff,
                    phb_ptr->data_desc[DATA_DESC_EXT5].free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC);
            }
            break;
        }
        case FILE_G_PBR_IDX:
        case FILE_U_PBR_IDX:
        {
            data_desc_enum des_id = phb_data_desc_file_id_to_desc(cblk->primary_ID, 1);

            phb_ptr->data_desc[des_id].is_support = KAL_TRUE;     
            phb_ptr->data_desc[des_id].record_num =
                (sim_file_info_cnf->num_of_rec < PHB_MAX_PBR_ENTRIES) ?
                sim_file_info_cnf->num_of_rec : PHB_MAX_PBR_ENTRIES;

            phb_ptr->data_desc[des_id].record_size = sim_file_info_cnf->length;
            break;
        }
        case FILE_G_ADN_IDX:
        case FILE_U_ADN_IDX:
    #endif /* __PHB_USIM_SUPPORT__ */

        case FILE_ADN_IDX:
        {
             /**
              * Actual record number should be controlled by evaluating
              * MAX_ENTRIES_COUNT values.
              * This prevents a free record to be found when attempting
              * write a record that exceeds maximum capacity allocated
              * for management data structure.
              * Since it exceeds maximum capacity, write such a record is
              * meaningless, because it cannot be read by PHB module.
              * Further, if write such a record could result in failure of PHB
              * module. >=P
              */
            kal_uint16 times = 1;
            phb_ptr->data_desc[DATA_DESC_ADN].record_num =
                (sim_file_info_cnf->num_of_rec < ADN_INDEX_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->num_of_rec : ADN_INDEX_MAX_ENTRIES_COUNT;
            kal_trace(TRACE_INFO, PHB_TRC_GET_INFO_ADN, ADN_INDEX_MAX_ENTRIES_COUNT, sim_file_info_cnf->num_of_rec * times, phb_ptr->data_desc[DATA_DESC_ADN].record_num);
        
            if (sim_file_info_cnf->num_of_rec > 0)
            {
                phb_ptr->data_desc[DATA_DESC_ADN].record_size = 
                    (sim_file_info_cnf->file_size / sim_file_info_cnf->num_of_rec);

                phb_desc_set_alpha_len(DATA_DESC_ADN, phb_ptr->data_desc[DATA_DESC_ADN].record_size - 14);

            }
            /* 
             * Sad. can't count on service table.
             * Supported either ADN or U_ADN is supported and record_num * record_size > 0
             */
            if (phb_ptr->data_desc[DATA_DESC_ADN].is_support && (phb_ptr->dn_type == TYPE_FDN || phb_ptr->dn_type == TYPE_FDN_BDN))
            {
                if (sim_file_info_cnf->res_data[0x0B] & 0xFA) /* RFU != 0 */
                {
                    phb_ptr->data_desc[DATA_DESC_ADN].is_support = KAL_FALSE;
                }
                else if ((sim_file_info_cnf->res_data[0x0B] & 0x01) != 0x01)
                {
                    if ((sim_file_info_cnf->res_data[0x0B] & 0x04) == 0x04)
                    {
                        phb_ptr->data_desc[DATA_DESC_ADN].is_support = KAL_TRUE;
                    }
                    else
                    {
                        phb_ptr->data_desc[DATA_DESC_ADN].is_support = KAL_FALSE;
                    }
                }
            }
            break;

        }
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        case FILE_G_IAP_IDX:
        case FILE_U_IAP_IDX:
            phb_ptr->data_desc[DATA_DESC_IAP].record_num =
                phb_ptr->data_desc[DATA_DESC_ADN].record_num;
            phb_ptr->data_desc[DATA_DESC_IAP].record_size = 
                sim_file_info_cnf->length;
        break;
        
        case FILE_G_AAS_IDX:
        case FILE_U_AAS_IDX:
            phb_ptr->data_desc[DATA_DESC_AAS].record_num =
                (sim_file_info_cnf->num_of_rec < AAS_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->num_of_rec : AAS_MAX_ENTRIES_COUNT;
            phb_ptr->data_desc[DATA_DESC_AAS].record_size = sim_file_info_cnf->length;
            phb_desc_set_alpha_len(DATA_DESC_AAS, (kal_uint8)phb_ptr->data_desc[DATA_DESC_AAS].record_size);
            break;

        case FILE_G_GAS_IDX:
        case FILE_U_GAS_IDX:
            phb_ptr->data_desc[DATA_DESC_GAS].record_num =
                (sim_file_info_cnf->num_of_rec < GAS_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->num_of_rec : GAS_MAX_ENTRIES_COUNT;

            phb_ptr->data_desc[DATA_DESC_GAS].record_size = sim_file_info_cnf->length;
            phb_desc_set_alpha_len(DATA_DESC_GAS, (kal_uint8)phb_ptr->data_desc[DATA_DESC_GAS].record_size);
            break;

        case FILE_G_GRP_IDX:
        case FILE_U_GRP_IDX:
            phb_ptr->data_desc[DATA_DESC_GRP].record_size = sim_file_info_cnf->length;

            phb_ptr->data_desc[DATA_DESC_GRP].record_num =
                (sim_file_info_cnf->num_of_rec < ADN_INDEX_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->num_of_rec : ADN_INDEX_MAX_ENTRIES_COUNT;
            break;
    #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
    
        case FILE_U_FDN_IDX:
        case FILE_FDN_IDX:
            if (sim_file_info_cnf->length >= 14)
            {
                phb_ptr->data_desc[DATA_DESC_FDN].is_support = KAL_TRUE;
                phb_ptr->data_desc[DATA_DESC_FDN].record_num =
                    (sim_file_info_cnf->num_of_rec < FDN_INDEX_MAX_ENTRIES_COUNT) ?
                    sim_file_info_cnf->num_of_rec : FDN_INDEX_MAX_ENTRIES_COUNT;
                phb_ptr->data_desc[DATA_DESC_FDN].record_size = sim_file_info_cnf->length;
                phb_desc_set_alpha_len(DATA_DESC_FDN, phb_ptr->data_desc[DATA_DESC_FDN].record_size - 14);
            }
            break;
            
        case FILE_U_BDN_IDX:
        case FILE_BDN_IDX:
            if (sim_file_info_cnf->length >= 15)
            {
                phb_ptr->data_desc[DATA_DESC_BDN].is_support = KAL_TRUE;
                phb_ptr->data_desc[DATA_DESC_BDN].record_num =
                    (sim_file_info_cnf->num_of_rec < BDN_INDEX_MAX_ENTRIES_COUNT) ?
                    sim_file_info_cnf->num_of_rec : BDN_INDEX_MAX_ENTRIES_COUNT;
                phb_ptr->data_desc[DATA_DESC_BDN].record_size = sim_file_info_cnf->length;
                phb_desc_set_alpha_len(DATA_DESC_BDN, phb_ptr->data_desc[DATA_DESC_BDN].record_size - 15);
            }
            break;

        case FILE_MSISDN_IDX:
        case FILE_U_MSISDN_IDX:
            if (sim_file_info_cnf->length >= 14)
            {
                phb_ptr->data_desc[DATA_DESC_MSISDN].is_support = KAL_TRUE;
                phb_ptr->data_desc[DATA_DESC_MSISDN].record_num =
                    (sim_file_info_cnf->num_of_rec < MSISDN_INDEX_MAX_ENTRIES_COUNT) ?
                    sim_file_info_cnf->num_of_rec : MSISDN_INDEX_MAX_ENTRIES_COUNT;
                phb_ptr->data_desc[DATA_DESC_MSISDN].record_size = sim_file_info_cnf->length;
                phb_desc_set_alpha_len(DATA_DESC_MSISDN, phb_ptr->data_desc[DATA_DESC_MSISDN].record_size - 14);
            }
            break;
            
        case FILE_U_SDN_IDX:
        case FILE_SDN_IDX:
            if (sim_file_info_cnf->length >= 14)
            {
                phb_ptr->data_desc[DATA_DESC_SDN].is_support = KAL_TRUE;
                phb_ptr->data_desc[DATA_DESC_SDN].record_num =
                    (sim_file_info_cnf->num_of_rec < SDN_INDEX_MAX_ENTRIES_COUNT) ?
                    sim_file_info_cnf->num_of_rec : SDN_INDEX_MAX_ENTRIES_COUNT;
                phb_ptr->data_desc[DATA_DESC_SDN].record_size = sim_file_info_cnf->length;
                phb_desc_set_alpha_len(DATA_DESC_SDN, phb_ptr->data_desc[DATA_DESC_SDN].record_size - 14);
            }
            break;
        case FILE_G_EXT1_IDX:
        case FILE_U_EXT1_IDX:
        case FILE_EXT1_IDX:
            phb_ptr->data_desc[DATA_DESC_EXT1].is_support = KAL_TRUE;
            phb_ptr->data_desc[DATA_DESC_EXT1].record_num =
                (sim_file_info_cnf->num_of_rec < EXT1_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->num_of_rec : EXT1_MAX_ENTRIES_COUNT;

            
            phb_ptr->data_desc[DATA_DESC_EXT1].record_size = sim_file_info_cnf->length;
            phb_ptr->data_desc[DATA_DESC_EXT1].free_count = phb_ptr->data_desc[DATA_DESC_EXT1].record_num;
            if (phb_ptr->data_desc[DATA_DESC_EXT1].free_bitmap != NULL)
            {
                kal_mem_set(
                    phb_ptr->data_desc[DATA_DESC_EXT1].free_bitmap,
                    0xff,
                    phb_ptr->data_desc[DATA_DESC_EXT1].free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC);
            }
            break;
            
        case FILE_U_EXT2_IDX:
        case FILE_EXT2_IDX:
            phb_ptr->data_desc[DATA_DESC_EXT2].is_support = KAL_TRUE;
            phb_ptr->data_desc[DATA_DESC_EXT2].record_num =
                (sim_file_info_cnf->num_of_rec < EXT2_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->num_of_rec : EXT2_MAX_ENTRIES_COUNT;
            phb_ptr->data_desc[DATA_DESC_EXT2].record_size = sim_file_info_cnf->length;
            phb_ptr->data_desc[DATA_DESC_EXT2].free_count = phb_ptr->data_desc[DATA_DESC_EXT2].record_num;
            if (phb_ptr->data_desc[DATA_DESC_EXT2].free_bitmap != NULL)
            {
                kal_mem_set(
                    phb_ptr->data_desc[DATA_DESC_EXT2].free_bitmap,
                    0xff,
                    phb_ptr->data_desc[DATA_DESC_EXT2].free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC);
            }
            break;
            
        case FILE_U_EXT3_IDX:
        case FILE_EXT3_IDX:
            phb_ptr->data_desc[DATA_DESC_EXT3].is_support = KAL_TRUE;
            phb_ptr->data_desc[DATA_DESC_EXT3].record_num =
                (sim_file_info_cnf->num_of_rec < EXT3_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->num_of_rec : EXT3_MAX_ENTRIES_COUNT;
            phb_ptr->data_desc[DATA_DESC_EXT3].record_size = sim_file_info_cnf->length;
            phb_ptr->data_desc[DATA_DESC_EXT3].free_count = phb_ptr->data_desc[DATA_DESC_EXT3].record_num;
            if (phb_ptr->data_desc[DATA_DESC_EXT3].free_bitmap != NULL)
            {
                kal_mem_set(
                    phb_ptr->data_desc[DATA_DESC_EXT3].free_bitmap,
                    0xff,
                    phb_ptr->data_desc[DATA_DESC_EXT3].free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC);
            }
            break;
            
        case FILE_U_EXT4_IDX:
        case FILE_EXT4_IDX:
            phb_ptr->data_desc[DATA_DESC_EXT4].is_support = KAL_TRUE;
            phb_ptr->data_desc[DATA_DESC_EXT4].record_num =
                (sim_file_info_cnf->num_of_rec < EXT4_MAX_ENTRIES_COUNT) ?
                sim_file_info_cnf->num_of_rec : EXT4_MAX_ENTRIES_COUNT;
            phb_ptr->data_desc[DATA_DESC_EXT4].record_size = sim_file_info_cnf->length;
            phb_ptr->data_desc[DATA_DESC_EXT4].free_count = phb_ptr->data_desc[DATA_DESC_EXT4].record_num;
            if (phb_ptr->data_desc[DATA_DESC_EXT4].free_bitmap != NULL)
            {
                kal_mem_set(
                    phb_ptr->data_desc[DATA_DESC_EXT4].free_bitmap,
                    0xff,
                    phb_ptr->data_desc[DATA_DESC_EXT4].free_bitmap_bits >> BYTE_SIZE_SHIFT_ARITHMETIC);
            }
            break;
    }

    (*cblk->controller) (NULL, cblk);
}   /* end of phb_get_info_set_value function */
/*****************************************************************************
 * FUNCTION
 *  phb_startup_handler
 * DESCRIPTION
 *  This is startup function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_startup_handler(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_STARTUP);

    if (ilm_ptr != NULL) // TODO: replace with STATE (startup_none --> startup_compare_digit)
    {
        phb_build_index_tbl = &phb_build_index_tbl_full[0];
        
        if (phb_ptr->state == PHB_STATE_NOT_READY)
        {
            kal_uint16 i;
            l4cphb_startup_req_struct *l4cphb_startup_req;
            l4cphb_startup_req = (l4cphb_startup_req_struct*) ilm_ptr->local_para_ptr;

            phb_ptr->is_fdn_change = l4cphb_startup_req->is_fdn_change;
            phb_ptr->is_adn_support = phb_ptr->data_desc[DATA_DESC_ADN].is_support;

         /**
          * Since startup is an implicit reset, there 2 ways to implement this:
          *
          * 1. Forbidden other operations to PHB except approve and search:
          *   In this implementation,
          *   startup handler should always uses the first cblk,
          *   and lock all control_blocks are locked temporarily;
          *   thus prevent other operations, except approve and search,
          *   from accessing PHB while it is busy.
          *
          * 2. Allow all other operations to provide maximum possible
          *   concurrency degrees.
          *
          * Curretly, solution 1 is implemented.
          * Control_blocks are all locked to interrupt all other in-processing
          * operations and reject all further requests, to prevent
          * multiple access to PHB when it is not ready.
          *
          * However, FDN is required to be approved even when PHB
          * is not ready. That means a cblk is required to
          * approve an FDN, even during startup procedure, which locks
          * all control_blocks. To solve this problem, solution 1 cannot
          * be adopted directly. The modified solution is:
          *
          * 1. Reset all control block which stops all current actions.
          * 2. Allocate one control block for startup procedure, and
          *   allows FDN approval only. All other request will be
          *   rejected even a free control block is found, since
          *   PHB state is not ready.
          */

            for (i = 0; i < PHB_CONCURRENCY_DEGREE; i++)
            {
                if (phb_ptr->control_block[i].is_allocated == KAL_TRUE)
                {
                    //phb_ptr->control_block[i].err_handler(NULL, &(phb_ptr->control_block[i]));
                }
            }

            phb_reset_all_control_blocks();

            cblk = phb_alloc_control_block();
            ASSERT(cblk != NULL);

            /* Retain msg_id */
            cblk->cnf_msg_id = ilm_ptr->msg_id;

            phb_ptr->dn_type = l4cphb_startup_req->dn_type;
            
            if (phb_ptr->is_fdn_change == KAL_FALSE)
            {
                phb_data_desc_reset();
            }
            kal_trace(TRACE_INFO, INFO_PHB_STARTUP_MODE, phb_ptr->dn_type);

        #if defined(__GEMINI__) || defined(GEMINI_PLUS) || defined(__SGLTE__)
            if (phb_current_mod != MOD_PHB)
            {
                phb_data_desc_set_is_support(DATA_DESC_PHB, KAL_FALSE);
            }
            else
        #endif /* __GEMINI__ */
            {
            #if !defined(__PHB_STORAGE_BY_MMI__)
                kal_uint16 phb_total, phb_size;

                if (nvram_get_info(NVRAM_EF_PHB_LID, &phb_total, &phb_size) == NVRAM_ERRNO_SUCCESS)
                {
                    phb_data_desc_set_is_support(DATA_DESC_PHB, KAL_TRUE);

                /*
                 * MAX_ENTRIES_COUNT must NOT be exceeded. See comment
                 * of phb_get_info_set_value() for detail.
                 */
                    if (phb_total > NVRAM_PHB_INDEX_MAX_ENTRIES_COUNT)
                    {
                        phb_total = NVRAM_PHB_INDEX_MAX_ENTRIES_COUNT;
                    }
                    phb_data_desc_set(DATA_DESC_PHB, phb_total, phb_size);
                }
                else
            #endif /* __PHB_STORAGE_BY_MMI__ */
                {
                    phb_data_desc_set_is_support(DATA_DESC_PHB, KAL_FALSE);
                }
            }

        #if defined(__GEMINI__) || defined(GEMINI_PLUS) || defined(__SGLTE__)
            l4csmu_get_chv_info_status(NULL, &chv_status[phb_current_mod - MOD_PHB]);
        #else
            l4csmu_get_chv_info_status(NULL, &chv_status[0]);
        #endif

            kal_trace(TRACE_INFO, FUNC_PHB_SIM_FILE_INFO);
            
            phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_STARTUP_BEGIN_IND, NULL, NULL);
            
        #if defined(__SGLTE__)
            if (ilm_ptr->dest_mod_id == MOD_PHB && is_mmdc_mode(SIM1) == KAL_TRUE)
            {
                kal_trace(TRACE_INFO, INFO_PHB_INDICES_BUILT);
                phb_ptr->state = PHB_STATE_READY;
                kal_trace(TRACE_STATE, STATE_PHB_READY);
                phb_startup_confirm(PHB_ERRNO_SUCCESS, cblk);
                phb_query_count[phb_which_sim_ex()] = 0;
                return;
            }
        #endif /* defined(__SGLTE__) */
            
            phb_get_info(ilm_ptr, cblk);
        }
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_STATE);
            return;
        }
    }
    else  // TODO: replace with STATE (startup_compare_digit --> startup_build_finish)
    {
        //l4cphb_startup_begin_ind_struct *l4cphb_startup_ind;
        //kal_int32 i = 0;
        //l4cphb_startup_ind = (l4cphb_startup_begin_ind_struct*) construct_local_para(sizeof(l4cphb_startup_begin_ind_struct), TD_RESET);

        if (phb_ptr->is_fdn_change == KAL_TRUE && phb_ptr->data_desc[DATA_DESC_ADN].is_support == phb_ptr->is_adn_support)
        {
            kal_trace(TRACE_INFO, INFO_PHB_INDICES_BUILT);
            phb_ptr->state = PHB_STATE_READY;
            kal_trace(TRACE_STATE, STATE_PHB_READY);
            phb_startup_confirm(PHB_ERRNO_SUCCESS, cblk);
            phb_query_count[phb_which_sim_ex()] = 0;
            return;
        }
        //for (; i < PHB_TYPE_TOTAL; i++)
        //{
        //    phb_desc_convert_desc(i, &l4cphb_startup_ind->desc[i]);
        //}
        kal_trace(TRACE_INFO, INFO_PHB_FILE_INFO_GOT);
        /* Send begin indication to MMI, MMI will clear it's variable and reload phonebook. */
        //phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_STARTUP_BEGIN_IND, l4cphb_startup_ind, NULL);
        kal_trace(TRACE_INFO, INFO_PHB_INDICES_BEGIN);

        phb_build_index_tbl = &phb_build_index_tbl_full[0];

        phb_startup_build_index(ilm_ptr, cblk);
    }
}   /* end of phb_startup_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_prepare_phb_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cblk       [?]     
 *  pdu_ptr             [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_prepare_phb_entry(control_block_type *cblk, kal_uint8 *pdu_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 alpha_id_length = phb_data_desc_get_record_size(DATA_DESC_PHB) - NVRAM_PHB_LENGTH_AFTER_ALPHA_ID;
    phb_nvram_ef_struct phb_nvram_ef;
    phb_entry_struct *phb_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cblk != NULL);

    /* Now unpack the data read from peer buffer */
    phb_entry = (phb_entry_struct*) cblk->data;

    phb_nvram_ef.alpha_id = pdu_ptr;
    phb_nvram_ef.mandatory = (phb_nvram_ef_mandatory_struct*) ((kal_uint8*) pdu_ptr + alpha_id_length);

    /* Clean area for storing data read from storage. */
    kal_mem_set(phb_entry, (kal_uint8) PHB_INVALID_VALUE, sizeof(phb_entry_struct));

    phb_entry->index = cblk->index;
    phb_entry->record_index = cblk->record_index;
    phb_entry->storage = PHB_STORAGE_NVRAM;
    /* amanda add */
    phb_entry->type = PHB_PHONEBOOK;

    if (!is_empty(pdu_ptr, cblk->length))
    {
        istring_type istring;

        /* Set up phb_entry->alpha_id */
        istring.length = phb_entry->alpha_id.name_length = MAX_PS_NAME_SIZE ;
        istring.data = (kal_uint8*) phb_entry->alpha_id.name;
        phb_entry->alpha_id.name_length = istring_decode_from_sim(alpha_id_length, phb_nvram_ef.alpha_id, &istring);
        if (phb_entry->alpha_id.name_length == 0)
        {
            istring.charset = PHB_ASCII;
        }

      /** 
       * If returned decoded length of alpha id is 0, 
       * it is either stored alpha id is empty, 
       * or alpha id encoding is erroneous 
       */

        phb_entry->alpha_id.name_dcs = istring.charset;
        if (phb_entry->alpha_id.name_length >= MAX_PS_NAME_SIZE )
        {
            if (phb_entry->alpha_id.name_dcs == PHB_ASCII)
            {
                phb_entry->alpha_id.name_length--;
                phb_entry->alpha_id.name[MAX_PS_NAME_SIZE  - 1] = 0;
            }
            else if (phb_entry->alpha_id.name_dcs == PHB_UCS2)
            {
                phb_entry->alpha_id.name_length -= 2;
                phb_entry->alpha_id.name[MAX_PS_NAME_SIZE  - 1] = 0;
                phb_entry->alpha_id.name[MAX_PS_NAME_SIZE  - 2] = 0;
            }
        }

      /**
       * Truncate read back DIALLING_NUMBER, if necessary, 
       * before it is stored into phb_entry.
       */
        if (phb_nvram_ef.mandatory->len > NVRAM_PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN)
        {
            phb_nvram_ef.mandatory->len = NVRAM_PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN;
        }

        if (phb_nvram_ef.mandatory->len > 0 && phb_nvram_ef.mandatory->len != 0xff)
        {
            /* Set up phb_entry->tel_number */
            /* LENGTH */
            phb_entry->tel_number.addr_length = phb_nvram_ef.mandatory->len;
            /* TON/NPI */
            phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TON_NPI_OFFSET] = phb_nvram_ef.mandatory->ton_npi;
            /* DIALLING_NUMBER/SSC_STRING */
            kal_mem_cpy(
                &phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET],
                (void const*)&phb_nvram_ef.mandatory->tel_number,
                /* TON_NPI_SIZE + */ phb_nvram_ef.mandatory->len - L4_ADDR_BCD_TEL_NUM_OFFSET);

            phb_entry->tel_number.addr_bcd[phb_nvram_ef.mandatory->len] = 0xff;
        }

        else
        {
            kal_mem_set(&phb_entry->tel_number, 0, sizeof(l4_addr_bcd_struct));
            phb_entry->tel_number.addr_bcd[L4_ADDR_BCD_TEL_NUM_OFFSET] = 0xff;
        }
        /* Set up phb_entry->cap_cnf_id */
        phb_entry->cap_cnf_id = phb_nvram_ef.mandatory->cap_cnf_id;
    }

    /* Incorrect LENGTH field */
    else
    {
        kal_mem_set(&phb_entry->alpha_id, 0, sizeof(l4_name_struct));
        phb_entry->tel_number.addr_length = 0;
        cblk->data = NULL;
    }
}


void phb_build_next(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    
    if (++cblk->actual_count >= cblk->total)
    {
        (*cblk->controller) (NULL, cblk);
    }
    else
    {
        ++cblk->record_index;
        phb_issue_IO_read(cblk);
    }        
}
#ifdef __PHB_USIM_SYNC__
static void phb_build_transfm(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    if (cblk->data)
    {
        
        switch(cblk->primary_ID)
        {
            case FILE_G_PUID_IDX:
            case FILE_U_PUID_IDX:
            {
                kal_uint8 *ptr = (kal_uint8 *)&phb_ptr->puid;                

                ptr[1] = cblk->data[0];
                ptr[0] = cblk->data[1];

                break;
            }
            case FILE_G_PSC_IDX:
            case FILE_U_PSC_IDX:
            {
                kal_uint8 *ptr = (kal_uint8 *)&phb_ptr->psc;                

                ptr[3] = cblk->data[0];
                ptr[2] = cblk->data[1];
                ptr[1] = cblk->data[2];
                ptr[0] = cblk->data[3];

                break;
            }
            case FILE_G_CC_IDX:
            case FILE_U_CC_IDX:
            {
                kal_uint16 data = 0;
                kal_uint8 *ptr = (kal_uint8 *)&data;                
                
                ptr[1] = cblk->data[0];
                ptr[0] = cblk->data[1];


                phb_ptr->cc += data;

                if (phb_ptr->cc == 0x0000)
                    phb_ptr->cc = 0x0001;

                ptr = (kal_uint8 *)&phb_ptr->cc;

                cblk->data[0] = ptr[1];
                cblk->data[1] = ptr[0];

                phb_issue_IO_write(cblk);
                cblk->data = NULL;
                return;
            }
            default:
                ASSERT(0);
        }
    }

    (*cblk->controller) (NULL, cblk);

}

static void phb_build_pbc(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    if (cblk->data)
    {
        if (cblk->data[0] == 1)
        {
            phb_ptr->cc++;

            cblk->data[0] = 0;
            phb_issue_IO_write(cblk);
            return;
        }
    }

    phb_build_next(ilm_ptr, cblk);

}
#endif /* __PHB_USIM_SYNC__ */
/*****************************************************************************
 * FUNCTION
 *  phb_read_ecc
 * DESCRIPTION
 *  This is phb_read_ecc function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_build_ecc(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 num_of_rec = phb_data_desc_get_record_num(DATA_DESC_ECC);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Reading ECC */
#ifdef __PHB_USIM_SUPPORT__
    if (phb_util_is_usim(phb_which_sim_ex()))
    {
        if (cblk->data[0] != 0xff)
        {
            istring_type istring;
            kal_uint16 record_index = cblk->record_index - 1;
            kal_mem_cpy(&phb_ptr->ecc.ecc_entry[record_index].ecc,
                (void const*)(cblk->data),
                NUM_OF_BYTE_ECC);

            istring.length = phb_ptr->ecc.ecc_entry[record_index].name_length = MAX_SIM_NAME_LEN;
            
            kal_mem_cpy(&phb_ptr->ecc.ecc_entry[record_index].name,
                (void const*)(cblk->data + NUM_OF_BYTE_ECC),
                phb_ptr->data_desc[DATA_DESC_ECC].alpha_length);                  

            istring.data = (kal_uint8*) phb_ptr->ecc.ecc_entry[record_index].name;

            phb_ptr->ecc.ecc_entry[record_index].name_length = istring_decode_from_sim(phb_ptr->data_desc[DATA_DESC_ECC].alpha_length, (kal_uint8*)(cblk->data + NUM_OF_BYTE_ECC), &istring);

            if (phb_ptr->ecc.ecc_entry[record_index].name_length == 0)
            {
                istring.charset = PHB_ASCII;
            }

            phb_ptr->ecc.ecc_entry[record_index].name_dcs = istring.charset;

            /* MAX_SIM_NAME_LEN is the max len of ecc name */
            if (phb_ptr->ecc.ecc_entry[record_index].name_length >= MAX_SIM_NAME_LEN)
            {
                phb_ptr->ecc.ecc_entry[record_index].name_length = 30;
                phb_ptr->ecc.ecc_entry[record_index].name[MAX_SIM_NAME_LEN - 1] = 0;
                phb_ptr->ecc.ecc_entry[record_index].name[MAX_SIM_NAME_LEN - 2] = 0;
           }
           
            kal_mem_cpy(&phb_ptr->ecc.ecc_entry[record_index].esc,
                (void const*)(cblk->data + NUM_OF_BYTE_ECC + phb_ptr->data_desc[DATA_DESC_ECC].alpha_length),
                1);

            phb_ptr->ecc.num_ecc++;
        }
    }
    else
#endif /* __PHB_USIM_SUPPORT__ */ 
    {
        kal_uint8 i;

        for (i = 0; i < num_of_rec; i++)
        {
            if (cblk->data[i * NUM_OF_BYTE_ECC] != 0xff)
            {
                kal_mem_cpy(&phb_ptr->ecc.ecc_entry[i].ecc,
                    (void const*)(&cblk->data[i * NUM_OF_BYTE_ECC]),
                    NUM_OF_BYTE_ECC);
                phb_ptr->ecc.num_ecc++;
            }
        }
        cblk->total = 0;
    }

    if (++cblk->actual_count >= cblk->total)
    {
        kal_uint8 i, ecc_src;
        sim_ecc_entry_struct* ecc;

        ecc_src = ECC_SRC_SIM1 + phb_which_sim_ex();

        if (phb_ptr->ecc.num_ecc)
        {
            /* update ecc to applib */
            for (i = 0; i < num_of_rec; i++)
            {
                ecc = &phb_ptr->ecc.ecc_entry[i];

                ecc_custom_update_emergency_number(
                    ecc->ecc,
                    ECC_ENCODING_BCD,
                    ecc_src,
                    ecc->esc,
                    NULL,
                    i + 1,
                    (kal_uint8)num_of_rec);
            }
        }
        else
        {
            phb_ptr->data_desc[DATA_DESC_ECC].is_support = KAL_FALSE;
        }

        phb_ptr->data_desc[DATA_DESC_ECC].record_num = phb_ptr->ecc.num_ecc;

        (*cblk->controller) (NULL, cblk);
        
    }
    else
    {
        ++cblk->record_index;
        phb_issue_IO_read(cblk);
    }

}   /* end of phb_build_ecc_index function */

#if !defined( __PHB_STORAGE_BY_MMI__) || defined(__CANCEL_LOCK_POWERON__)
static void phb_build_me(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    kal_uint8 *pdu_ptr;
    kal_uint16 pdu_length, total;
    kal_uint16 i;
#if !defined(__PHB_NOT_READ_ADN__) && defined(__MMI_FMI__)
    kal_uint8 count = 0;
    l4cphb_startup_read_ind_struct *l4cphb_startup_read_ind = NULL;
#endif

    phb_entry_struct *phb_entry = (phb_entry_struct*) cblk->data;
    
    /* Get the Pointer to the Message from the Peer Buffer Ptr */
    pdu_ptr = (kal_uint8*) get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &pdu_length);
    total = pdu_length / cblk->length;

    /* there are 2 loops here */
    if (is_empty(pdu_ptr, pdu_length))  /* check all record first */
    {
        kal_mem_set(&phb_entry->alpha_id, 0, sizeof(l4_name_struct));
        phb_entry->tel_number.addr_length = 0;
        cblk->actual_count += total - 1; /* because phb_build_next will ++ */
        cblk->total_piggyback = total;
        for (i = 0; i < total; i++)
        {
            phb_data_desc_mark_free(
                DATA_DESC_PHB,
                0,
                cblk->record_index,
                0,
                KAL_TRUE,
                KAL_FALSE);
            cblk->record_index++;
        }

        cblk->record_index -= 1; /* because phb_build_nex will ++ */

        /* Reset cblk->data */
        cblk->data = (kal_uint8*) & cblk->temp_entry;
        phb_build_next(NULL, cblk);
        return;
    }
    for (i = 0; i < total; i++)
    {
        if (i != 0)
        {
            pdu_ptr += cblk->length;
        }
        phb_prepare_phb_entry(cblk, pdu_ptr);

        if ((phb_entry != NULL) &&
            ((phb_entry->alpha_id.name_length != 0) || (phb_entry->tel_number.addr_length != 0)))
        {
        #if !defined(__PHB_NOT_READ_ADN__) && defined(__MMI_FMI__)
            if (!l4cphb_startup_read_ind)
            {
                l4cphb_startup_read_ind = (l4cphb_startup_read_ind_struct*) construct_local_para(
                                                        sizeof(l4cphb_startup_read_ind_struct),
                                                        TD_CTRL);
            }
            
            memcpy(
                &l4cphb_startup_read_ind->phb_entry[count],
                (phb_entry_struct*) cblk->data,
                sizeof(phb_entry_struct));
            count++;
        #endif /* defined(__MMI_FMI__) */ 
            phb_se_build_index(
                PHB_PHONEBOOK,
                cblk->record_index,
                cblk->seg_record_index,
                (phb_entry_struct*) cblk->data);
        }
        /* an invalid record */
        else
        {
            phb_data_desc_mark_free(
                DATA_DESC_PHB,
                0,
                cblk->record_index,
                0,
                KAL_TRUE,
                KAL_FALSE);
            /* Reset cblk->data */
            cblk->data = (kal_uint8*) & cblk->temp_entry;
        }
        cblk->actual_count++;
        cblk->total_piggyback++;
        cblk->record_index++;
    }

    /* because phb_build_next will ++ */
    cblk->actual_count -= 1;
    cblk->record_index -= 1;

    #if !defined(__PHB_NOT_READ_ADN__) && defined(__MMI_FMI__)
    if (l4cphb_startup_read_ind)
    {
        l4cphb_startup_read_ind->access_id = cblk->ID;
        l4cphb_startup_read_ind->num_of_entry = count;
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_STARTUP_READ_IND, (local_para_struct*) l4cphb_startup_read_ind, NULL);
        return;
    }
    #endif /* !__PHB_NOT_READ_ADN__ && __MMI_FMI__ */ 

    phb_build_next(ilm_ptr, cblk);
    
}
#endif /* !defined( __PHB_STORAGE_BY_MMI__) || defined(__CANCEL_LOCK_POWERON__) */

static void phb_build_adn(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    l4cphb_startup_read_ind_struct *l4cphb_startup_read_ind = NULL;
    phb_entry_struct* entry = (phb_entry_struct*) cblk->data;
    
    if (entry && (entry->alpha_id.name_length || entry->tel_number.addr_length))
    {
    #if !defined(__PHB_NOT_READ_ADN__) && defined(__MMI_FMI__)
        /*
         *  Send out indication for each record for ADN and NVRAM entries.
         *  and wait response to read next.
         */
        l4cphb_startup_read_ind = (l4cphb_startup_read_ind_struct*) construct_local_para(sizeof(l4cphb_startup_read_ind_struct), TD_CTRL);

        memcpy(
            &l4cphb_startup_read_ind->phb_entry,
            (phb_entry_struct*) cblk->data,
            sizeof(phb_entry_struct));
        
        l4cphb_startup_read_ind->access_id = cblk->ID;
        l4cphb_startup_read_ind->num_of_entry = 1;  /* ADN doesn't have multiple read */
        
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_STARTUP_READ_IND, (local_para_struct *) l4cphb_startup_read_ind, NULL);
    #endif /* !__PHB_NOT_READ_ADN__ && __MMI_FMI__ */ 

        phb_se_build_index(
            PHB_PHONEBOOK,
            cblk->record_index,
            cblk->seg_record_index,
            (phb_entry_struct*) cblk->data);

    }
    
    
    if (l4cphb_startup_read_ind)
    {
        /*
         *   If it a ADN record, wait for MMI response to continue to read next entry.
         *   So does not read next entry until MMI confirm.
         *   As for other record( BDN, FDN...), it remains the old way to read next entry.
         */

        return;
    }

    phb_build_next(ilm_ptr, cblk);
}

static void phb_build_fdn(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    phb_entry_struct* entry = (phb_entry_struct*) cblk->data;

    if (entry && (entry->alpha_id.name_length || entry->tel_number.addr_length))
    {
    #if defined(__PHB_FDN_GET_NAME__) || defined(__ECALL_SUPPORT__)
        phb_update_fdn_context(cblk->record_index, &(((phb_entry_struct*) cblk->data)->alpha_id), &(((phb_entry_struct*) cblk->data)->tel_number));
        /* should add to name pool before build_index, because if the name is null, then in se_build_index, the number context will be filled into name field */
    #endif /* __PHB_FDN_GET_NAME__ */
        phb_se_build_index(
            PHB_FDN,
            cblk->record_index,
            cblk->seg_record_index,
            (phb_entry_struct*) cblk->data);
    } 
    if (++cblk->actual_count >= cblk->total)
    {
    #ifndef __PHB_STORAGE_BY_MMI__
        phb_name_num_index_sort(&phb_ptr->indices.fdn_index);
    #endif
        phb_ptr->state = PHB_STATE_NOT_READY_FDN_READY;
        (*cblk->controller) (NULL, cblk);
    }
    else
    {
        ++cblk->record_index;
        phb_issue_IO_read(cblk);
    }    
}

#if defined(__ECALL_SUPPORT__)
static void phb_build_sdn(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    phb_entry_struct* entry = (phb_entry_struct*) cblk->data;

    if (entry && (entry->alpha_id.name_length || entry->tel_number.addr_length))
    {
        phb_update_sdn_context(cblk->record_index, &(((phb_entry_struct*) cblk->data)->alpha_id), &(((phb_entry_struct*) cblk->data)->tel_number));
        /* should add to name pool before build_index, because if the name is null, then in se_build_index, the number context will be filled into name field */
    } 
    if (++cblk->actual_count >= cblk->total)
    {
        (*cblk->controller) (NULL, cblk);
    }
    else
    {
        ++cblk->record_index;
        phb_issue_IO_read(cblk);
    }    
}
#endif /* __PHB_FDN_GET_NAME__ */

#if !(defined(LOW_COST_SUPPORT) && defined(PLUTO_MMI))
static void phb_build_bdn(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    phb_entry_struct* entry = (phb_entry_struct*) cblk->data;
    
    if (entry && (entry->alpha_id.name_length || entry->tel_number.addr_length))
    {
        phb_se_build_index(
            PHB_BDN,
            cblk->record_index,
            cblk->seg_record_index,
            (phb_entry_struct*) cblk->data);
    }
    /*
    else
    {
        phb_data_desc_mark_free(
            phb_data_desc_get_desc_by_ID(cblk->primary_ID, cblk->storage),
            cblk->record_index,
            KAL_TRUE);
        cblk->data = (kal_uint8*) & cblk->temp_entry;
    }        
    */
    phb_build_next(ilm_ptr, cblk);

}
#endif /* !(defined(LOW_COST_SUPPORT) && defined(PLUTO_MMI)) */

/*****************************************************************************
 * FUNCTION
 *  phb_build_index
 * DESCRIPTION
 *  This is build_index function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_startup_build_index(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    kal_uint8 curr_sim = phb_which_sim_ex();
    kal_bool usim = phb_util_is_usim(curr_sim);

    while (phb_query_count[curr_sim] >=0 && phb_build_index_tbl[phb_query_count[curr_sim]].primary_ID)
    {
        data_desc_enum desc_id;
    #ifdef __PHB_USIM_SUPPORT__
        if (phb_build_index_tbl[phb_query_count[curr_sim]].is_usim != PHB_INFO_READ_ME)
        {
        phb_build_index_tbl[phb_query_count[curr_sim]].primary_ID = 
            phb_desc_get_used_file_id(phb_build_index_tbl[phb_query_count[curr_sim]].primary_ID);
        }
        if ((phb_build_index_tbl[phb_query_count[curr_sim]].is_usim == PHB_INFO_READ_USIM && !usim) ||
            (phb_build_index_tbl[phb_query_count[curr_sim]].is_usim == PHB_INFO_READ_SIM && usim))
        {
            if (usim && phb_build_index_tbl[phb_query_count[curr_sim]].primary_ID == FILE_ADN_IDX &&
                phb_ptr->data_desc[DATA_DESC_PBR].record_num == 0)
            {
                /* This is special USIM card which does not support USIM phonebook */
                /* So we read SIM phonebook and make SIM storage accessible */
            }
            else
            {
                phb_query_count[curr_sim]++;
                continue;
            }
        }
    #endif

        cblk->primary_ID = phb_build_index_tbl[phb_query_count[curr_sim]].primary_ID;
        cblk->secondary_ID = phb_build_index_tbl[phb_query_count[curr_sim]].secondary_ID;

        if (phb_build_index_tbl[phb_query_count[curr_sim]].is_usim == PHB_INFO_READ_ME)
        {
            cblk->storage = PHB_STORAGE_NVRAM;
        }
        else
        {
            cblk->storage = phb_which_sim_storage();
            cblk->cause = SIM_CMD_SUCCESS;
        }
        
        desc_id = phb_data_desc_get_desc_by_ID(cblk->primary_ID, cblk->storage);

        if (!phb_ptr->data_desc[desc_id].is_support || phb_ptr->data_desc[desc_id].record_num == 0)
        {
            phb_query_count[curr_sim]++;
            continue;
        }
    

    #ifdef __PHB_USIM_SUPPORT__
        if (phb_util_is_usim(curr_sim) && 
            phb_build_index_tbl[phb_query_count[curr_sim]].is_usim == PHB_INFO_READ_USIM)
        {
            /*
             * for 2nd or later PHB, will be handled in phb_build_adn
             */
            if (!phb_desc_get_file_path(cblk->primary_ID, 1, 1, cblk->path))
            {
                phb_query_count[curr_sim]++;
                continue;
            }
        }
    #endif        

        if (phb_build_index_tbl[phb_query_count[curr_sim]].file_type == SIM_FILE_TRANSP)
        {
            cblk->record_index = 0;
            cblk->length = phb_ptr->data_desc[desc_id].record_num * phb_ptr->data_desc[desc_id].record_size;
            
        }
        else if (phb_build_index_tbl[phb_query_count[curr_sim]].file_type == SIM_FILE_LINEAR_FIXED || 
                 cblk->storage == PHB_STORAGE_NVRAM)
        {
            cblk->record_index = 1;
            cblk->length = phb_ptr->data_desc[desc_id].record_size;
            cblk->data = (void *)&cblk->temp_entry;
        }

        phb_control_block_set_IO(
            cblk, 
            phb_util_get_type(cblk->primary_ID), 
            cblk->record_index, 
            phb_ptr->data_desc[desc_id].record_num);

        phb_control_block_set(
            cblk,
            phb_build_index_tbl[phb_query_count[curr_sim]].child_cnf,
            phb_startup_build_index,
            phb_startup_err_handler,
            startup_build_index);
        
        phb_query_count[curr_sim]++;
        phb_issue_IO_read(cblk);
        return;
    }    

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __PHB_USIM_SUPPORT__ */ 
    {
        /* Build all indices */
        phb_se_finish_build();

        kal_trace(TRACE_INFO, INFO_PHB_INDICES_BUILT);
        phb_ptr->state = PHB_STATE_READY;
        kal_trace(TRACE_STATE, STATE_PHB_READY);
        phb_startup_confirm(PHB_ERRNO_SUCCESS, cblk);
    }

    phb_query_count[curr_sim] = 0;
}

/*****************************************************************************
 * FUNCTION
 *  phb_build_index_continue_adn
 * DESCRIPTION
 *  Send out indication for each record for ADN and NVRAM entries.
 *  and wait response to read next. Only turn on when LMMI exists.
 * PARAMETERS
 *  cblk       [IN]        Current control block
 * RETURNS
 *  void
 *****************************************************************************/
void phb_build_index_continue_adn(control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Must be an ADN record. */
    ASSERT(cblk->proc_stage <= startup_build_index);

    if (++cblk->actual_count >= cblk->total)
    {
        (*cblk->controller) (NULL, cblk);
    }
    else
    {
        phb_issue_IO_read(cblk);
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_startup_confirm
 * DESCRIPTION
 *  This is phb_startup_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  cblk       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_startup_confirm(phb_errno_enum result, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4cphb_startup_cnf_struct *l4cphb_startup_cnf;
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_STARTUP_CNF, result);

    l4cphb_startup_cnf = (l4cphb_startup_cnf_struct*) construct_local_para(sizeof(l4cphb_startup_cnf_struct), TD_RESET);
    l4cphb_startup_cnf->result = result;
    
    phb_ptr->is_fdn_change = KAL_FALSE;
    phb_ptr->is_adn_support = phb_ptr->data_desc[DATA_DESC_ADN].is_support;

    l4cphb_startup_cnf->adn_size = phb_ptr->data_desc[DATA_DESC_ADN].record_num;
    l4cphb_startup_cnf->phb_size = phb_ptr->data_desc[DATA_DESC_PHB].record_num;
    l4cphb_startup_cnf->adn_alpha_length = phb_desc_get_alpha_len(DATA_DESC_ADN);
    l4cphb_startup_cnf->fdn_alpha_length = phb_desc_get_alpha_len(DATA_DESC_FDN);
    l4cphb_startup_cnf->bdn_alpha_length = phb_desc_get_alpha_len(DATA_DESC_BDN);
    l4cphb_startup_cnf->msisdn_alpha_length = phb_desc_get_alpha_len(DATA_DESC_MSISDN);
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    l4cphb_startup_cnf->email_length = phb_desc_get_alpha_len(DATA_DESC_EMAIL);
#else
    l4cphb_startup_cnf->email_length = 0;
#endif
    l4cphb_startup_cnf->is_sim_refresh = 0;

    for (; i < PHB_TYPE_TOTAL; i++)
    {
        phb_desc_convert_desc(i, &l4cphb_startup_cnf->desc[i]);
    }
    
#ifdef __PHB_USIM_SUPPORT__
    if (phb_util_is_usim(phb_which_sim_ex()))    
    {
        /* phb_ptr->state = PHB_STATE_READY; //already set after finish to read grp */
    }
    else
    {
        phb_ptr->state = PHB_STATE_READY;
        kal_trace(TRACE_STATE, STATE_PHB_READY);
    }
#endif /* __PHB_USIM_SUPPORT__ */ 

    if ((result == PHB_ERRNO_BUSY) || (cblk->cnf_msg_id == MSG_ID_L4CPHB_STARTUP_REQ))
    {
        if (result == PHB_ERRNO_BUSY)
        {
            phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_STARTUP_CNF, (local_para_struct*) l4cphb_startup_cnf, NULL);
            return;
        }
        phb_free_control_block(cblk);
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_STARTUP_CNF, (local_para_struct*) l4cphb_startup_cnf, NULL);
        return;
    }
#ifdef __CANCEL_LOCK_POWERON__
    else if ((result == PHB_ERRNO_BUSY) || (cblk->cnf_msg_id == MSG_ID_L4CPHB_INIT_ME_PHB_REQ))
    {
        if (result == PHB_ERRNO_BUSY)
        {
            phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_INIT_ME_PHB_CNF, (local_para_struct*) l4cphb_startup_cnf, NULL);
            return;
        }
        phb_free_control_block(cblk);
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_INIT_ME_PHB_CNF, (local_para_struct*) l4cphb_startup_cnf, NULL);
        return;
    }
#endif /* __CANCEL_LOCK_POWERON__ */
    else
    {
    #ifdef __SAT__
        if (cblk->cnf_msg_id == MSG_ID_SAT_FILE_CHANGE_IND)
        {
            l4cphb_startup_cnf->is_sim_refresh = 1; /* SIM refresh */
            phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_STARTUP_CNF, (local_para_struct*) l4cphb_startup_cnf, NULL);
            phb_sat_file_change_confirm(result, cblk->src_id, cblk);
            return;
        }
    #endif /* __SAT__ */ 
        /* Abnormal! */
        kal_trace(TRACE_ERROR, ERROR_PHB_ABNORMAL);
    }
}   /* end of phb_startup_confirm */


/*****************************************************************************
 * FUNCTION
 *  phb_get_info_err_handler
 * DESCRIPTION
 *  This is get_info_err_handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_get_info_err_handler(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Bypass error, and continue next step */
    cblk->IO_stage = IO_NONE;
    
#ifdef __PHB_USIM_SUPPORT__
    if (cblk->primary_ID == FILE_G_PBR_IDX)
    {
        if (cblk->actual_count <= 1)
        {
            phb_ptr->is_global = KAL_FALSE;
            phb_query_count[phb_which_sim_ex()]--;
        }
        else
        {
            phb_ptr->data_desc[DATA_DESC_PBR].record_num--;
            (*cblk->controller) (NULL, cblk);
            return;
        }
    }
#endif
    phb_data_desc_set_is_support(phb_data_desc_get_desc_by_ID(cblk->primary_ID, cblk->storage), KAL_FALSE);
    (*cblk->controller) (NULL, cblk);
}   /* end of phb_get_info_err_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_startup_err_handler
 * DESCRIPTION
 *  This is startup error handler function of PHB module.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void phb_startup_err_handler(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_STARTUP_ERR);

    /* Bypass error, and continue next step */
    if (cblk)
        cblk->IO_stage = IO_NONE;
        
    if (cblk != NULL)
    {
    #ifdef __PHB_USIM_SUPPORT__

        if (cblk->proc_stage == startup_info_sim)
        {
            kal_uint16 i;

            for (i = 0; i < DATA_DESC_PBR; i++)
            {
                /* could only reset the support value of SIM related file */
                if (i != DATA_DESC_PHB)
                {
                    phb_ptr->data_desc[i].is_support = KAL_FALSE;
                }
            }
        }
    #endif
        if (cblk->proc_stage <= startup_info_sim)
        {
            (*cblk->controller) (ilm_ptr, cblk);
        }
        else
        {
            (*cblk->controller) (NULL, cblk);
        }
    }
}   /* end of phb_startup_err_handler function */

#ifdef __CANCEL_LOCK_POWERON__

/*****************************************************************************
 * FUNCTION
 *  phb_init_me_phb_handler
 * DESCRIPTION
 *  This is init function of "mobile equipment" phb.
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  cblk       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_init_me_phb_handler(ilm_struct *ilm_ptr, control_block_type *cblk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_STARTUP);

    if (ilm_ptr != NULL)
    {
        phb_build_index_tbl = &phb_build_index_tbl_me[0];
        if (phb_ptr->state == PHB_STATE_NOT_READY)
        {
            kal_uint16 phb_total, phb_size;
            l4cphb_startup_req_struct *l4cphb_startup_req;
            l4cphb_startup_req = (l4cphb_startup_req_struct*) ilm_ptr->local_para_ptr;

            cblk = phb_alloc_control_block();
            ASSERT(cblk != NULL);

            /* Retain msg_id */
            cblk->cnf_msg_id = ilm_ptr->msg_id;

            phb_ptr->dn_type = l4cphb_startup_req->dn_type;

            kal_trace(TRACE_INFO, INFO_PHB_STARTUP_MODE, phb_ptr->dn_type);

            /* Send begin indication to MMI, MMI will clear it's variable and reload phonebook. */

        #if defined(__GEMINI__) || defined(GEMINI_PLUS) || defined(__SGLTE__)
            if (phb_current_mod != MOD_PHB)
            {
                phb_data_desc_set_is_support(DATA_DESC_PHB, KAL_FALSE);
            }
            else
        #endif /* __GEMINI__ */
            {
            #if !defined(__PHB_STORAGE_BY_MMI__)
                if (nvram_get_info(NVRAM_EF_PHB_LID, &phb_total, &phb_size) == NVRAM_ERRNO_SUCCESS)
                {
                    phb_data_desc_set_is_support(DATA_DESC_PHB, KAL_TRUE);

                /*
                 * MAX_ENTRIES_COUNT must NOT be exceeded. See comment
                 * of phb_get_info_set_value() for detail.
                 */
                    if (phb_total > NVRAM_PHB_INDEX_MAX_ENTRIES_COUNT)
                    {
                        phb_total = NVRAM_PHB_INDEX_MAX_ENTRIES_COUNT;
                    }
                    phb_data_desc_set(DATA_DESC_PHB, phb_total, phb_size);
                }
                else
            #endif
                {
                    phb_data_desc_set_is_support(DATA_DESC_PHB, KAL_FALSE);
                }
            }

            phb_is_sim_file_support();

            cblk->proc_stage = startup_info_compare_digit;
            cblk->controller = phb_init_me_phb_handler;
            (*cblk->controller) (NULL, cblk);
        }
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_STATE);
            return;
        }
    }
    else
    {
        l4cphb_startup_begin_ind_struct *l4cphb_startup_ind;
        kal_int32 i = 0;
        l4cphb_startup_ind = (l4cphb_startup_begin_ind_struct*) construct_local_para(sizeof(l4cphb_startup_begin_ind_struct), TD_RESET);

        for (; i < PHB_TYPE_TOTAL; i++)
        {
            phb_desc_convert_desc(i, &l4cphb_startup_ind->desc[i]);
        }
        /* Send begin indication to MMI, MMI will clear it's variable and reload phonebook. */
        phb_send_ilm(MOD_L4C, MSG_ID_L4CPHB_STARTUP_BEGIN_IND, l4cphb_startup_ind, NULL);
        kal_trace(TRACE_INFO, INFO_PHB_FILE_INFO_GOT);
        kal_trace(TRACE_INFO, INFO_PHB_INDICES_BEGIN);

        phb_startup_build_index(ilm_ptr, cblk);

    }
}   /* end of phb_startup_handler function */

#endif /* __CANCEL_LOCK_POWERON__ */



