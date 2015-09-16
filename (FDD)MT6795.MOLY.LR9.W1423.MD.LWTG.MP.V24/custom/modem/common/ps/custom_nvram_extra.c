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
 * custom_nvram_extra.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file is the implementation of the methods to manuplate the file object defined 
 *    in NVRAM data items.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
* Include
*****************************************************************************/
#include "custom_nvram_extra.h"
#include "custom_nvram_sec.h"
//#include "common_nvram_editor_data_item.h"
#include "kal_general_types.h"
//#include "kal_internal_api.h"
#include "kal_public_api.h"
//#include "nvram_editor_data_item.h"
#include "nvram_data_items.h"
#include "kal_trace.h"
#include "sim_public_enum.h"
#include "global_def.h"
#include "smu_trc.h"
#include "smu_def.h"
#include "ps_public_utility.h"

#include "cust_chl_interface.h"

#if !defined(__MAUI_BASIC__)

/*****************************************************************************
* Define of SMU
*****************************************************************************/
/* 
 *   BEGIN:PH add for smu_security_info_struct (NVRAM_EF_MS_SECURITY_LID)
 * typedef struct
 * {
 *     kal_uint8                reg_ps_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                security_indication;
 *     kal_uint8                auto_lock_item;
 *     kal_uint8                np_code[NVRAM_EDITOR_NUM_OF_BYTE_NP * NVRAM_EDITOR_NUM_NP];
 *     kal_uint8                np_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                nsp_code[NVRAM_EDITOR_NUM_OF_BYTE_NSP * NVRAM_EDITOR_NUM_NSP];
 *     kal_uint8                nsp_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                np_of_sp[NVRAM_EDITOR_NUM_OF_BYTE_NP];
 *     kal_uint8                np_of_cp[NVRAM_EDITOR_NUM_OF_BYTE_NP];
 *     kal_uint8                gid1[NVRAM_EDITOR_NUM_GID];
 *     kal_uint8                gid2[NVRAM_EDITOR_NUM_GID];
 *     kal_uint8                sp_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                cp_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                imsi_code[NVRAM_EDITOR_NUM_OF_BYTE_IMSI];
 *     kal_uint8                imsi_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                phone_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                last_imsi[NVRAM_EDITOR_NUM_OF_BYTE_IMSI];
 *     kal_uint8                pin1[NVRAM_EDITOR_NUM_PIN1];
 *     kal_uint8                pin1_valid;
 *     kal_uint8                phone_lock_verified;
 *  }smu_security_info_struct;
 *
 */

/* Load a new data object */
static kal_bool smu_load(void *, kal_uint8);   /* pobjFromlid */
/* Update a the data object */
static kal_bool smu_update(void *, kal_uint8); /* pobjTolid */
/* Release the data object */
static kal_bool smu_destory(kal_uint8);
/* Query the value of the item in kal_uint8 */
static kal_uint8 smu_query_u8(smu_item_enum, kal_uint8);   /* eItem */
/* Query the value of the item in kal_uint8[] */
static void smu_query_a(
                /* eItem */ smu_item_enum,
                /* pstrTo */ kal_uint8 *,
                /* chlen */ kal_uint8, kal_uint8);
/* Assign the value of the item in kal_uint8 */
static void smu_assign_u8(
                /* eItem */ smu_item_enum,
                /* chValue */ kal_uint8, kal_uint8);
/* Assign the value of the item in string with length */
static void smu_assign_a(
                /* eItem */ smu_item_enum,
                /* pstrValue */ kal_uint8 *,
                /* chlen */ kal_uint8, kal_uint8);
/* Compare the string with the data item */
static kal_bool smu_match(
                    /* eItem */ smu_item_enum,
                    /* pstrValue */ kal_uint8 *,
                    /* chlen */ kal_uint8, kal_uint8);

 /***************************************************************************** 
* Typedef of SMU
*****************************************************************************/

/***************************************************************************** 
* Local Variable of SMU
*****************************************************************************/
static nvram_ef_ms_security_struct nvram_ef_ms_security_obj_g[MAX_SIM_NUM];

/***************************************************************************** 
* Local Variable of SMU object
*****************************************************************************/
static smu_security_info_struct smu_security_info_obj[MAX_SIM_NUM];

/***************************************************************************** 
* Global Variable of SMU
*****************************************************************************/

nvram_ef_ms_security_struct *pSmuSecurityInfog = &nvram_ef_ms_security_obj_g[0];

/***************************************************************************** 
* Global Function of SMU
*****************************************************************************/
void smu_init_ms_security_obj(kal_uint8 source)
{
    nvram_ef_ms_security_struct ms_security_obj = {
        NULL,
        smu_load,
        smu_update,
        smu_destory,
        smu_query_u8,
        smu_query_a,
        smu_assign_u8,
        smu_assign_a,
        smu_match        
    };
    
    smu_destory(source);
    kal_mem_cpy(&nvram_ef_ms_security_obj_g[source], &ms_security_obj, sizeof(nvram_ef_ms_security_struct));
}

kal_uint8 sim_terminal_profile_length(void)
{
    return MAX_SIM_PROFILE_LEN;

    /* support old SIM card, please return this value. 
       NOTE: the value shall be less than MAX_SIM_PROFILE_LEN */
    // return 9;
}

/* Virtual SIM File content 
   meta data (32 bytes) = FCP data length(1 byte) + FCP data (31 bytes)
   FCP data is the response data of selecting this file. 
   Please refer to SIM spec , to check the format of response data of "SELECT" command */
#ifdef __VSIM__ 
/*35+256 = 291*/
const kal_uint8 DF_GSM_data[64] = 
{
/* The first 32 is meta data : start*/
0x17, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x20, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0a, 0x93, 0x00, 
0x1c, 0x04, 0x00, 0x83, 0x8a, 0x83, 0x8a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
/* File content data : end*/
};

const kal_uint8 EF_ICCID_data[64] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x0A, 0x2F, 0xE2, 0x04, 0x00, 0x04, 0x00, 0x44, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x98, 0x88, 0x96, 0x07, 0x02, 0X05, 0x27, 0x01, 0x01, 0x22, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

const kal_uint8 EF_LP_data[64] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x04, 0x6F, 0x05, 0x04, 0x00, 0x01, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x11, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

const kal_uint8 EF_SST_data[64] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x0A, 0x6F, 0x38, 0x04, 0x00, 0x15, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0xFF, 0x3F, 0xFF, 0xFF, 0x00, 0x00, 0xFC, 0x33, 0x00, 0x0C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

const kal_uint8 EF_PHASE_data[64] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x01, 0x6F, 0xAE, 0x04, 0x00, 0x05, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

const kal_uint8 EF_IMSI_data[64] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x09, 0x6F, 0x07, 0x04, 0x00, 0x15, 0x00, 0x15, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x08, 0x09, 0x10, 0x10, 0x10, 0x32, 0x54, 0x06, 0x36, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

const kal_uint8 EF_AD_data[64] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x03, 0x6F, 0xAD, 0x04, 0x00, 0x05, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

const kal_uint8 EF_ACC_data[64] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x02, 0x6F, 0x78, 0x04, 0x00, 0x15, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x00, 0x40, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

const kal_uint8 EF_KC_data[64] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x09, 0x6F, 0x20, 0x04, 0x00, 0x11, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0xCD, 0xB4, 0x71, 0xF9, 0x09, 0x2F, 0x6C, 0x00, 0x02, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

const kal_uint8 EF_LOCI_data[64] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x0B, 0x6F, 0x7E, 0x04, 0x00, 0x11, 0x00, 0x15, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x5B, 0x22, 0x8E, 0x1B, 0x64, 0xF6, 0x79, 0x2C, 0x27, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

const kal_uint8 EF_HPPLMN_data[64] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x01, 0x6F, 0x31, 0x04, 0x00, 0x15, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x05, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

/*MoDIS doesn't have this file!*/
const kal_uint8 EF_BCCH_data[64] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x10, 0x6F, 0x74, 0x04, 0x00, 0x11, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

const kal_uint8 EF_FPLMN_data[64] = 
{
/* The first 32 is meta data : start*/
0x0F, 0x00, 0x00, 0x00, 0x0C, 0x6F, 0x7B, 0x04, 0x00, 0x11, 0x00, 0x55, 0x01, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
/* The first 32 is meta data : end*/
/* File content data : start*/
0x64, 0xF6, 0x10, 0x64, 0xF6, 0x29, 0x64, 0xF6, 0x88, 0x44, 0xF0, 0x01, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
/* File content data : end*/
};

#endif


/* This is SAT terminal profile content.
 * NOTE: Please do NOT MODIFY it by yourself !!!                                               
 * If you want to customize SAT terminal profile content, please consult with MTK first. */
#ifdef __SAT_ADDITIONAL_LOCK__
kal_uint8 sim_profile[MAX_SIM_PROFILE_LEN + SAT_ADDITIONAL_TER_PROFILE] =
#else 
kal_uint8 sim_profile[MAX_SIM_PROFILE_LEN] =
#endif 
{           /* develope value */
    0xF7    /* 1st */
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0x08      /*MENU SELECTION*/
    #endif
    , 
        
    0x17    /* 2nd */
    #ifndef __DISABLE_SMS_CONTROLLED_BY_SIM__
    | 0x08    //MO short message control support
    #endif
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0xE0
    #endif
    ,

    0xC8       /* 3rd */
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0x37
    #endif
    ,
    0x8E       /* 4th */
    #if !defined(__SAT_LOWCOST_NW_DISABLE__)
    | 0x40      // 0x40: PROVIDE LOCAL INFORMATION (MCC, MNC, LAV, Cell ID, IMEI)
    #endif
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0x21
    #ifndef __DISABLE_CSCALL__
    | 0x10  // 0x10: Proactive SIM: SET UP CALL
    #endif
    #endif
    ,

    0x01    /*5th*/  //Proactive UICC: SET UP EVENT LIST
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    #ifndef __SAT_LOWCOST_UI_DISABLE__
    | 0x60  // 0x20: Event: User activity
               // 0x40: Event: Idle screen available
    #endif
    #endif
    #ifndef __SAT_LOWCOST_NW_DISABLE__
    | 0x1E   // 0x02: Event: MT call
                // 0x04: Event: Call connected
                // 0x08: Event: Call disconnected
                // 0x10: Event: Location status
    #endif
    ,

    0x90    /* 6th */  //0x10:  Event: Access Technology Change
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    #if !defined(__SAT_LOWCOST_UI_DISABLE__)
    | 0x01  // Event: Language selection
    #endif
    #endif
    #if defined(__SATCC__)
    | 0x02  // Event: Browser Termination
    #endif
    #if defined(__SATCE__)
    | 0x0C  // 0x04: Event: Data available
               // 0x08: Event: Channel status
    #endif
    ,

    0x00,   /* 7th */
    0x87 /* 8th */
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0x58
    #endif
    #ifdef __SATCB__
    | 0x20      // RUN AT COMMAND (i.e. class "b" is supported)
    #endif
    ,

    0x06        /* 9th */
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0x01      // 0x01: Sustained DISPLAY TEXT 
    #if !defined(__SAT_LOWCOST_UI_DISABLE__)
    | 0x20      // 0x20: LANGUAGE NOTIFICATION
    #endif
    #endif
    #if !defined(__SAT_LOWCOST_NW_DISABLE__)
    | 0x08      // 0x08: PROVIDE LOCAL INFORMATION (language)
    #endif
    #if !defined(__SAT_LOWCOST_NW_DISABLE__)
    | 0x10      // 0x10: PROVIDE LOCAL INFORMATION (Timing Advance)
    #endif
    #if defined(__SATCC__)
    | 0x40     // 0x40: LAUNCH BROWSER
    #endif
    #if !defined(__SAT_LOWCOST_NW_DISABLE__)
    | 0x80      // 0x80: PROVIDE LOCAL INFORMATION (Access Technology)
    #endif    
    ,

    0x00,   /* 10th *//* No other Softkeys supported */
    0x00,   /* 11th */
    
    0x00    /* 12th */
    #ifdef __SATCE__
    | 0x1F
    #endif
    ,
    
    0x00    /* 13th */
    #ifdef __SATCE__
    | 0x42
    #if defined(CSD_SUPPORT)
    | 0x01   //0x01: CSD
    #endif
    #endif
    ,

    0x00    /* 14th */
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0x08
    #else
    | 0x60
    #endif
    ,

    0x00    /* 15th */
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0x11
    #endif
    ,
    
    0x00   /* 16th */
    #if !defined(__MODEM_CARD__) && !defined(__SAT_AP_NOT_SUPPORT__)
    | 0x06
    #endif
    ,

    0x80    /* 17th */
    #ifdef __LTE_RAT__
    | 0x40          //0x40: E-UTRAN (i.e. if class "e" is supported)
    #endif
    #ifdef __SATCE__    
    | 0x07
    #endif
    ,

    0xC0    /* 18th */ /* MAUI_02883701 GET INKEY HELP */

#if defined(__REL7__) || defined(__SATCL__) || defined(__SATCM__) || defined(__SATCR__)
        ,
    0x00,   /* 19th */
    0x00,   /* 20th */
    0x00,   /* 21th */
    0x00,   /* 22th */
    0x40,   /* 23th */  // PROVIDE LOCAL INFORMATION (NMR (UTRAN/E-UTRAN))
    0x00,   /* 24th */
    0x00    /* 25th */
    | 0x10          // 0x10: Event Network Rejection 
#ifdef __LTE_RAT__
    | 0x40          // 0x40: Event: E-UTRAN support in Event Network Rejection
#endif
#if defined(__SATCM__)    
    | 0x20          // 0x20: HCI connectivity event (if class "m" is supported)
#endif 
    ,

    0x00    /* 26th */
#if defined(__SATCR__) 
    | 0x02 /* Event: Contactless state request */
#endif 
    ,

    0x00,   /* 27th */    
    0x00,   /* 28th */
    0x00,   /* 29th */
   
    0x00    /* 30th */
#if defined(__REL7__) 
    | 0x08 /* Steering of Roaming" REFRESH support */
#endif
#if defined(__SATCL__)
    | 0x10 /* Proactive UICC: ACTIVATE (i.e class "l" is supported) */
#endif    
    ,

    0x00     /* 31th */
#if defined(__SATCR__)
    | 0x01  /* Proactive UICC: Contactless State Changed */
#endif
    ,
    0x00,    /* 32th */

#endif    
#ifdef __SAT_ADDITIONAL_LOCK__
        ,
    0x00,   /* 31th: 1 */
    0x00,   /* 32th: 2 */
    0x00,   /* 33th: 3 */
    0x00,   /* 34th: 4 */
    0x00,   /* 35th: 5 */
    0x00,   /* 36th: 6 */
    0x00,   /* 37th: 7 */
    0x00,   /* 38th: 8 */
    0x00    /* 39th: 9 */
#endif /* __SAT_ADDITIONAL_LOCK__ */ 
};


/* AT&T V5.6 [MAUI_02356244] make EF_Terminal_support_table customized */
 const kal_uint8 terminal_support_table[8] = 
{
    0x01, /* Byte1: scan control application */

    0x01, /* Byte2: network selection menu control application */

    0x01, /* Byte3: acting HPLMN feature */

#ifdef __UMTS_RAT__
    0x01, /* Byte4: 3G Access */
#else
    0x00, 
#endif

    0x00, /* Byte5: RAT Balancing is Not supported. set as 0x00 */
    
    0x00, /* Byte6: According to the AT&T spec. V5.6, we should always set this byte to 0 even if we support BIP*/

#ifdef __LTE_RAT__
    #if defined(__GSM_RAT__) || defined(__UMTS_RAT__)
        #ifdef __VOLTE_SUPPORT__
            0x03, /* Byte7: If LTE Data and Voice using IMS and CSFB then set 0x03 */
        #else
            0x02, /* If LTE Data and Voice using CSFB only then set 0x02 */
        #endif
    #else
        0x01,     /* If LTE Data only then set value 0x01 */
    #endif
#else
    0x00,
#endif

#ifdef __CSG_SUPPORT__
    0x01  /* Byte8: CSG functionality */
#else
    0x00
#endif
};

 /*****************************************************************************
 * FUNCTION
 *  sim_ens_terminal_support_flag
 * DESCRIPTION
 *  make EF_Terminal_support_table customized
 * PARAMETERS
 *  pProfile        [?]     
 * RETURNS
 *  void
 * GLOBALS AFFECTED
 *  void
 *****************************************************************************/
void sim_ens_terminal_support_flag(kal_uint8 *table_ptr, kal_uint8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    if (NULL != table_ptr)
    {    
        if(len > sizeof(terminal_support_table))
        {
            kal_sys_trace("Exceed terminal_support_table size");
            len = sizeof(terminal_support_table);
        }
        
        kal_mem_cpy(table_ptr, terminal_support_table, len);
    }

    if (sbp_query_md_feature(SBP_ENS_RAT_BALANCING) == KAL_TRUE)
    {
        table_ptr[3] = 0x01;
        table_ptr[4] = 0x01;
    }

}


 /*****************************************************************************
 * FUNCTION
 *  custom_sim_reset_method
 * DESCRIPTION
 *  Determine the SIM card reset method to detch the card is USIM or SIM.
 *      SIM_RESET_SMART_DETECTION : judge the card is USIM or SIM according to the spec.
 *      SIM_RESET_USIM_PREFER : always try USIM first. Try SIM if trying USIM failed.
 *      SIM_RESET_SIM_PREFER : always try SIM first. Try USIM if trying SIM failed.
 * PARAMETERS
 *  none
 * RETURNS
 *  sim_reset_method_enum
 *****************************************************************************/
sim_reset_method_enum custom_sim_reset_method(void) //mtk02514_reset
{
#if defined(__UMTS_TDD128_MODE__) || defined(__TDD_MODEM__) || defined(__TDD_2G_OP01__)
    return SIM_RESET_USIM_PREFER;
#else
    return SIM_RESET_SMART_DETECTION;
#endif
}


 /*****************************************************************************
 * FUNCTION
 *  custom_sat_provide_cell_in_sim
 * DESCRIPTION
 *  Let PROVIDE LOCAL INFORMATION - location stauts
 *   return cell ID instead of E-Cell ID when using SIM
 * PARAMETERS
 *  none
 * RETURNS
 *  KAL_FALSE or KAL_TRUE
 * NOTE:
 *      Based on SAT spec 102.221 or 51.014, we should NOT provide eCell ID in SIM.
 *      Only USAT should carry eCell ID in LOCATION INFO field in USIM
 *****************************************************************************/
kal_bool custom_sat_provide_cell_in_sim(void)
{
#if 1
    return KAL_TRUE;
#else
    #ifdef __SAT_PROVIDE_CELL_IN_SIM__
/* under construction !*/
    #else
/* under construction !*/
    #endif
#endif    
}

/*****************************************************************************
* FUNCTION
*  custom_sat_auto_startup
* DESCRIPTION
*  Auto startup SAT application
*   
* PARAMETERS
*  none
* RETURNS
*  KAL_FALSE or KAL_TRUE
*****************************************************************************/
kal_bool custom_sat_auto_startup(void)
{
    return KAL_TRUE;
}

/***************************************************************************** 
* The determination of Test SIM has two ways:
* CondA is MCC/MNC = 001/01,  CondB is EF_AD's ms_operation 0x80, 0x81, 0x02, 0x04
*       
*      If (CondA || CondB), then return 0
*      If (CondA && CondB), then return 1
* 
*      The default value returns 0
 *****************************************************************************/
kal_uint8 test_SIM_relation(void)
{
    /* [MAUI_03181345] mtk81143: set test sim relation default OR for TD project*/

    kal_sys_trace("TestSIM_OR");
    return 0;

/*
    kal_sys_trace("TestSIM_AND");
    return 1;
*/
}

#ifdef __SIM_RECOVERY_ENHANCEMENT__
/***************************************************************************
* This function configs how many times fast sim recovery trial could be performed
* before MMI notify user that SIM card is lost.
***************************************************************************/
kal_uint8 custom_num_fast_recovery(void)
{
    return 3;
}

/***************************************************************************
* After user is notifed SIM lost, ME will try to recover the SIM card at frequent intervals.
* This function configs the time interval for each recovery trial.
***************************************************************************/
kal_uint8 custom_recovery_time_interval(void)
{
    return 30;
    // The time unit is second.
    // 30: the time interval for a SIM recovery trial is 30 seconds.
}

/***************************************************************************
* After user is notifed SIM lost, ME will try to recover the SIM card at frequent intervals.
* This function configs the maximum count of recovery trial.
***************************************************************************/
kal_uint16 custom_max_recovery_count(void)
{
    return 0xFFFF;
    // 0: no recovery trial after MMI is notified SIM lost.
    // 100: there will be at most 100 recovery tial after MMI is notified SIM lost.
    // 0xFFFF: there is no limit of SIM recovery trial.
}

/***************************************************************************
* After user is notifed SIM ACCESS ERROR(card existed but detect fail), 
* ME will try to recover the SIM card at frequent intervals.
* This function configs the function is enabled or disalbed.
***************************************************************************/
kal_uint8 custom_retry_sim_when_card_detect_fail()
{
#ifdef __RETRY_SIM_WHEN_CARD_DETECT_FAIL__
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}
#endif

/*****************************************************************************
 * FUNCTION
 *  custom_set_p2_to_zero_value()
 * DESCRIPTION
 *  Determine if set p2 value to 0x00 or not when select aid in +CCHO
 *      KAL_TRUE: set p2 to 0x00
 *      KAL_FALSE : set p2 follow the previous implementation
 * PARAMETERS
 *  none
 * RETURNS
 *  KAL_FALSE or KAL_TRUE
 *****************************************************************************/
kal_bool custom_set_p2_to_zero_value(void) 
{
#if !defined(__UMTS_TDD128_MODE__) && !defined(__TDD_2G_OP01__)  /*based on [ALPS00383584]*/
    return KAL_TRUE;
#else
	return KAL_FALSE;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  custom_select_aid_by_default()
 * DESCRIPTION
 *  Determine to set p2 value when select aid in +CCHO
 *      KAL_TRUE: (default) set p2 to 0x0C then 0x00 
 *      KAL_FALSE : set p2 to 0x00 then 0x0c
 * PARAMETERS
 *  none
 * RETURNS
 *  KAL_FALSE or KAL_TRUE
 *****************************************************************************/
kal_bool custom_select_aid_by_default(void)
{
#ifdef __SELECT_AID_CUSTOMIZE__
    return KAL_FALSE;
#else
    return KAL_TRUE;
#endif /* __SELECT_AID_CUSTOMIZE__ */
}


/*  UICC driver need to know the 'le' field in APDU before processing the APDU command. 
  *  For proprietary UICC command, please parse the 'le' value in this function.
  *  If le is present : value shall be 0~256 at most                                                             
  *  if le is not present : rx_data_size set to 0                                                                   */
/*MOLY00003203 AT+CGLA extension support for customized INS for NFC, by mtk81143*/
kal_bool custom_apdu_cmd_le( kal_uint8 *tx_data,kal_uint16 *tx_data_size, kal_uint32 *rx_data_size)
{
	kal_bool  result = KAL_TRUE;
	*rx_data_size = 0;
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
#endif 
    return result;
}
#ifdef __SIM_HOT_SWAP_POLL_TIMER__
kal_uint8 custom_hot_swap_poll_time_interval(void)
{
    return 2;
    // The time unit is second.
    // 2: the time interval for a SIM hotswap to temporarily change the polling time to 2 seconds.
}
#endif

 /*****************************************************************************
 * FUNCTION
 *  custom_sim_terminal_capability_power_supply
 * DESCRIPTION
 *  This function is used to indicate that terminal needs more power
 *  than the minmum power supply.
 * PARAMETERS
 *  actual_voltage_class        [IN]
 *  power_data                    [OUT]
 *      power_data[0] :  Actual used Supply voltage class
 *      power_data[1] :  Maximum available power supply of the terminal
 *      power_data[2] :  Actual used clock frequency
 * RETURNS
 *  KAL_FALSE or KAL_TRUE : need this TLV or not
 *****************************************************************************/
kal_bool custom_sim_terminal_capability_power_supply(kal_uint8 *power_supply_data)
{

    power_supply_data[1] = 0x0A;
    power_supply_data[2] = 0x0A;

    /*
    * Please don't switch this return to KAL_TRUE, 
    * if you have requirement about this item, please contact with SIM owner
    */

    return KAL_FALSE;
}

 /*****************************************************************************
 * FUNCTION
 *  custom_sim_extended_logical_channel_support
 * DESCRIPTION
 *  This function is used to indicate that terminal support extended logical channel or not
 * PARAMETERS
 *  N/A
 * RETURNS
 *  KAL_FALSE or KAL_TRUE : need this TLV or not
 *****************************************************************************/
kal_bool custom_sim_extended_logical_channel_support(void)
{
    return KAL_TRUE;
}

 /*****************************************************************************
 * FUNCTION
 *  custom_sim_addition_interfaces_support
 * DESCRIPTION
 *  This function is used to indicate that terminal support additional interfaces
 * PARAMETERS
 *  N/A
 * RETURNS
 *  KAL_FALSE or KAL_TRUE : need this TLV or not
 *****************************************************************************/
kal_bool custom_sim_addition_interfaces_support(kal_uint8 *interfaces)
{
    interfaces[0] = 0x00;   // UICC-CLF supportted

    return KAL_TRUE;
}




/***************************************************************************** 
* Some SIM cards do not follow the rule to invalidate IMSI, and LOCI when FDN/BDN is 
* enabled, to compatible with these type of SIM cards, function shall return KAL_TRUE to 
* bypass invalid check.Tthe default value shall return KAL_TRUE
 *****************************************************************************/
kal_bool bypass_invalid_check(void)
{
    return KAL_TRUE;
}


kal_uint8 custom_sat_additional_lock_switch(void)
{
    return 1; /*
               * 1: turn on
               * 0: turn off
               */
                  
}

 /*****************************************************************************
 * FUNCTION
 *  custom_sim_get_first_aid
 * DESCRIPTION
 *  This function is used to make sure the first USIM AID is seleceted
 *   KAL_TRUE: select first USIM AID
 *   KAL_FALSE: select last USIM AID
 * PARAMETERS
 *  N/A
 * RETURNS
 *  KAL_FALSE or KAL_TRUE
 *****************************************************************************/
kal_bool custom_sim_get_first_aid(void)
{
    return KAL_FALSE;
}

/***************************************************************************** 
*  
*****************************************************************************/
kal_uint8 is_HW_VERIFICATION_enabled(void)
{
    return 0;
    // 0 - disable HW verification
    // 1 - enable for SIM1 only
    // 2 - enable for SIM2 only
}


/***************************************************************************** 
 * According to spec ,when processing SAT PALY TONE proactive command
 * "If no duration is specified, the ME shall default to a duration determined by the ME manufacturer."
 * Customer can define default duration for PLAY TONE command in this function
 * For FTA testcase 27.22.4.5 PLAY TONE SEQ 1.1 Step61, it might need to enlarge the default duration
 * time unit : 1ms
 *****************************************************************************/
kal_uint32 sat_PLAY_TONE_default_duration(void)
{
    return 5000; // 5 sec 
}

#if defined(__SAT_CUSTOM_POLL_TIMER__) //MAUI_02931261
/***************************************************************************** 
 * The feature proposes is to change the status poll interval to a value greater then the one
 * requested by the SIM card, in the case that it is shorter then a pre-defined customized value. 
 * Therefore, if the poll interval time requested by SIM card is less than the customized time value, 
 * then the latter shall be used as the poll interval. 
 * If, instead, the requested poll interval is greater than the flex value, then
 * the time provided in the request command shall be used as the poll interval.
 * The default value return 0 is to disable the feature
 * time unit : TICKS (Please use KAL_TICKS_xxx marco)
 *****************************************************************************/
kal_uint32 sat_custom_poll_timer(void)
{
    //return (KAL_TICKS_30_SEC-KAL_TICKS_1_SEC*3-KAL_TICKS_500_MSEC); //current MTK default value is within 30 seconds (about 26.5 seconds)
    return  (KAL_TICKS_30_SEC + KAL_TICKS_5_SEC +KAL_TICKS_1_SEC); //36 seconds
    //return (KAL_TICKS_1_MIN + KAL_TICKS_3_SEC); // 1 minute and 3 seconds
    //return 0;  //to disable this feature
}
#endif 

 /*****************************************************************************
 * FUNCTION
 *  custom_sim_verify_adm_support
 * DESCRIPTION
 *  This function is used to indicate that terminal support verify ADM or not
 * PARAMETERS
 *  N/A
 * RETURNS
 *  KAL_FALSE or KAL_TRUE : need this feature or not
 *****************************************************************************/
kal_bool custom_sim_verify_adm_support(void)
{
    return KAL_FALSE;
}

/***************************************************************************** 
* Local Function of SMU
*****************************************************************************/

/* Load a new data object */


/*****************************************************************************
 * FUNCTION
 *  smu_load
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pobjFromlid     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool smu_load(void *pobjFromlid, kal_uint8 source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (smu_destory(source))
    {
        kal_sys_trace("SMU: previous obj not free!");
    }

//    nvram_ef_ms_security_obj_g[source].smu_security_info_ptr = get_ctrl_buffer(sizeof(smu_security_info_struct));
//    kal_mem_set((kal_uint8*) nvram_ef_ms_security_obj_g[source].smu_security_info_ptr, 0xFF, sizeof(smu_security_info_struct));
    nvram_ef_ms_security_obj_g[source].smu_security_info_ptr = &(smu_security_info_obj[source]);

    kal_mem_cpy(
        (kal_uint8*) nvram_ef_ms_security_obj_g[source].smu_security_info_ptr,
        (kal_uint8*) pobjFromlid,
        sizeof(smu_security_info_struct));
    return KAL_TRUE;
}

/* Update a the data object */


/*****************************************************************************
 * FUNCTION
 *  smu_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pobjTolid       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool smu_update(void *pobjTolid, kal_uint8 source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(nvram_ef_ms_security_obj_g[source].smu_security_info_ptr != NULL);
    kal_mem_cpy(
        (kal_uint8*) pobjTolid,
        (kal_uint8*) nvram_ef_ms_security_obj_g[source].smu_security_info_ptr,
        sizeof(smu_security_info_struct));
    return KAL_TRUE;
}

/* Release the data object */


/*****************************************************************************
 * FUNCTION
 *  smu_destory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool smu_destory(kal_uint8 source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
    return KAL_FALSE;
}

/* Query the value of the item in kal_uint8 */


/*****************************************************************************
 * FUNCTION
 *  smu_query_u8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eItem       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint8 smu_query_u8(smu_item_enum eItem, kal_uint8 source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    smu_security_info_struct *info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g[source].smu_security_info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != info_ptr);
    switch (eItem)
    {
        case SMU_SECURITY_INDICATION_U8:
            return info_ptr->security_indication;
            break;
/*			
        case SMU_AUTO_LOCK_ITEM_U8:
            return info_ptr->auto_lock_item;
            break;
*/
        case SMU_PIN1_VALID_U8:
            return info_ptr->pin1_valid;
            break;
        case SMU_PHONE_LOCK_VERIFIED_U8:
            return info_ptr->phone_lock_verified;
            break;
/*			
        case SMU_REG_PS_KEY_A:
        case SMU_NP_CODE_A:
        case SMU_NP_KEY_A:
        case SMU_NSP_CODE_A:
        case SMU_NSP_KEY_A:
        case SMU_NP_OF_SP_A:
        case SMU_NP_OF_CP_A:
        case SMU_GID1_A:
        case SMU_GID2_A:
        case SMU_SP_KEY_A:
        case SMU_CP_KEY_A:
        case SMU_IMSI_CODE_A:
        case SMU_IMSI_KEY_A:
*/
        case SMU_PHONE_KEY_A:
        case SMU_LAST_IMSI_A:
        case SMU_PIN1_A:
        default:
            //ASSERT(0);  /* drop through! Wrong items */
            break;
    }
    return 0;
}

/* Query the value of the item in kal_uint8[] */


/*****************************************************************************
 * FUNCTION
 *  smu_query_a
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eItem       [IN]        
 *  pstrTo      [?]         
 *  chlen       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void smu_query_a(smu_item_enum eItem, kal_uint8 *pstrTo, kal_uint8 chlen, kal_uint8 source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    smu_security_info_struct *info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g[source].smu_security_info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != info_ptr);
    switch (eItem)
    {
        case SMU_SECURITY_INDICATION_U8:
/*			
        case SMU_AUTO_LOCK_ITEM_U8:
*/        
        case SMU_PIN1_VALID_U8:
        case SMU_PHONE_LOCK_VERIFIED_U8:
            //ASSERT(0);
            break;
/*			
        case SMU_REG_PS_KEY_A:
        case SMU_NP_CODE_A:
        case SMU_NP_KEY_A:
        case SMU_NSP_CODE_A:
        case SMU_NSP_KEY_A:
        case SMU_NP_OF_SP_A:
        case SMU_NP_OF_CP_A:
        case SMU_GID1_A:
        case SMU_GID2_A:
        case SMU_SP_KEY_A:
        case SMU_CP_KEY_A:
        case SMU_IMSI_CODE_A:
        case SMU_IMSI_KEY_A:
*/
        case SMU_PHONE_KEY_A:
            break;
        case SMU_LAST_IMSI_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            kal_mem_cpy(pstrTo, info_ptr->last_imsi, NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            break;
        case SMU_PIN1_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_PIN1);
            kal_mem_cpy(pstrTo, info_ptr->pin1, NVRAM_EDITOR_NUM_PIN1);
            break;
	 case SMU_ICCID_A:
	     kal_mem_cpy(pstrTo, info_ptr->iccid, NVRAM_EDITOR_NUM_OF_BYTE_ICCID);
	     break;
        default:
            //ASSERT(0);  /* drop through! Wrong items */
            break;
    }
}

/* Assign the value of the item in kal_uint8 */


/*****************************************************************************
 * FUNCTION
 *  smu_assign_u8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eItem       [IN]        
 *  chValue     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void smu_assign_u8(smu_item_enum eItem, kal_uint8 chValue, kal_uint8 source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    smu_security_info_struct *info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g[source].smu_security_info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != info_ptr);
    switch (eItem)
    {
        case SMU_SECURITY_INDICATION_U8:
            info_ptr->security_indication = chValue;
            break;
/*			
        case SMU_AUTO_LOCK_ITEM_U8:
            info_ptr->auto_lock_item = chValue;
            break;
*/            
        case SMU_PIN1_VALID_U8:
            info_ptr->pin1_valid = chValue;
            break;
        case SMU_PHONE_LOCK_VERIFIED_U8:
            info_ptr->phone_lock_verified = chValue;
            break;
/*			
        case SMU_REG_PS_KEY_A:
        case SMU_NP_CODE_A:
        case SMU_NP_KEY_A:
        case SMU_NSP_CODE_A:
        case SMU_NSP_KEY_A:
        case SMU_NP_OF_SP_A:
        case SMU_NP_OF_CP_A:
        case SMU_GID1_A:
        case SMU_GID2_A:
        case SMU_SP_KEY_A:
        case SMU_CP_KEY_A:
        case SMU_IMSI_CODE_A:
        case SMU_IMSI_KEY_A:
*/
        case SMU_PHONE_KEY_A:
        case SMU_LAST_IMSI_A:
        case SMU_PIN1_A:
        default:
            //ASSERT(0);  /* drop through! Wrong items */
            break;
    }
}

/* Assign the value of the item in string with length */


/*****************************************************************************
 * FUNCTION
 *  smu_assign_a
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eItem           [IN]        
 *  pstrValue       [?]         
 *  chlen           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void smu_assign_a(smu_item_enum eItem, kal_uint8 *pstrValue, kal_uint8 chlen, kal_uint8 source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    smu_security_info_struct *info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g[source].smu_security_info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != info_ptr);
    switch (eItem)
    {
        case SMU_SECURITY_INDICATION_U8:
/*			
        case SMU_AUTO_LOCK_ITEM_U8:
*/
        case SMU_PIN1_VALID_U8:
        case SMU_PHONE_LOCK_VERIFIED_U8:
            //ASSERT(0);
            break;
/*			
        case SMU_REG_PS_KEY_A:
            break;
        case SMU_NP_CODE_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            kal_mem_cpy(info_ptr->np_code, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_NP);
            break;
        case SMU_NP_KEY_A:
            break;
        case SMU_NSP_CODE_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NSP);
            kal_mem_cpy(info_ptr->nsp_code, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_NSP);
        case SMU_NSP_KEY_A:
            break;
        case SMU_NP_OF_SP_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            kal_mem_cpy(info_ptr->np_of_sp, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_NP);
            break;
        case SMU_NP_OF_CP_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            kal_mem_cpy(info_ptr->np_of_cp, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_NP);
            break;
        case SMU_GID1_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_GID);
            kal_mem_cpy(info_ptr->gid1, pstrValue, chlen);
            break;
        case SMU_GID2_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_GID);
            kal_mem_cpy(info_ptr->gid2, pstrValue, chlen);
            break;
        case SMU_SP_KEY_A:
            break;
        case SMU_CP_KEY_A:
            break;
        case SMU_IMSI_CODE_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            kal_mem_cpy(info_ptr->imsi_code, pstrValue, chlen);
            break;
        case SMU_IMSI_KEY_A:
            break;
*/            
        case SMU_PHONE_KEY_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            kal_mem_cpy(info_ptr->phone_key, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            break;
        case SMU_LAST_IMSI_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            kal_mem_cpy(info_ptr->last_imsi, pstrValue, chlen);
            break;
        case SMU_PIN1_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_PIN1);
            kal_mem_cpy(info_ptr->pin1, pstrValue, NVRAM_EDITOR_NUM_PIN1);
            break;
	 case SMU_ICCID_A:
	     kal_mem_cpy(info_ptr->iccid, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_ICCID);
	     break;
        default:
            //ASSERT(0);
            break;
    }
}

/* Compare the string with the data item */

/*****************************************************************************
 * FUNCTION
 *  smu_match
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eItem           [IN]        
 *  pstrValue       [?]         
 *  chlen           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool smu_match(smu_item_enum eItem, kal_uint8 *pstrValue, kal_uint8 chlen, kal_uint8 source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

//    kal_uint8 idx = 0;

    smu_security_info_struct *info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g[source].smu_security_info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != info_ptr);
    switch (eItem)
    {
        case SMU_SECURITY_INDICATION_U8:
            //ASSERT(chlen == sizeof(kal_uint8));
            if (info_ptr->security_indication == *pstrValue)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
/*			
        case SMU_AUTO_LOCK_ITEM_U8:
            //ASSERT(chlen == sizeof(kal_uint8));
            if (info_ptr->auto_lock_item == *pstrValue)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
*/            
        case SMU_PIN1_VALID_U8:
            //ASSERT(chlen == sizeof(kal_uint8));
            if (info_ptr->pin1_valid == *pstrValue)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_PHONE_LOCK_VERIFIED_U8:
            //ASSERT(chlen == sizeof(kal_uint8));
            if (info_ptr->phone_lock_verified == *pstrValue)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
/*			
        case SMU_REG_PS_KEY_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->reg_ps_key, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_KEY) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_NP_CODE_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            for (idx = 0; idx < NVRAM_EDITOR_NUM_NP; idx++)
            {
                if (kal_mem_cmp(
                        pstrValue,
                        (kal_uint8*) & (info_ptr->np_code[idx * NVRAM_EDITOR_NUM_OF_BYTE_NP]),
                        NVRAM_EDITOR_NUM_OF_BYTE_NP) == 0)
                {
                    return KAL_TRUE;    // Find one! 
                }
            }
            return KAL_FALSE;
            break;
        case SMU_NP_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->np_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_NSP_CODE_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NSP);
            for (idx = 0; idx < NVRAM_EDITOR_NUM_NSP; idx++)
            {
                if (kal_mem_cmp(
                        pstrValue,
                        (kal_uint8*) & (info_ptr->nsp_code[idx * NVRAM_EDITOR_NUM_OF_BYTE_NSP]),
                        NVRAM_EDITOR_NUM_OF_BYTE_NSP) == 0)
                {
                    return KAL_TRUE;    // Find one! 
                }
            }
            return KAL_FALSE;
            break;
        case SMU_NSP_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->nsp_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_NP_OF_SP_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            if (kal_mem_cmp(pstrValue, info_ptr->np_of_sp, NVRAM_EDITOR_NUM_OF_BYTE_NP) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_NP_OF_CP_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            if (kal_mem_cmp(pstrValue, info_ptr->np_of_cp, NVRAM_EDITOR_NUM_OF_BYTE_NP) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_GID1_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_GID);
            if (kal_mem_cmp(info_ptr->gid1, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_GID2_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_GID);
            if (kal_mem_cmp(info_ptr->gid2, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_SP_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->sp_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_CP_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->cp_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_IMSI_CODE_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            if (kal_mem_cmp(info_ptr->imsi_code, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_IMSI) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_IMSI_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->imsi_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
*/            
        case SMU_PHONE_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->phone_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_LAST_IMSI_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            if (kal_mem_cmp(info_ptr->last_imsi, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_IMSI) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_PIN1_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_PIN1);
            if (kal_mem_cmp(info_ptr->pin1, pstrValue, NVRAM_EDITOR_NUM_PIN1) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;

	 case SMU_ICCID_A:
	     if(kal_mem_cmp(info_ptr->iccid,
			           pstrValue,
			           NVRAM_EDITOR_NUM_OF_BYTE_ICCID) == 0)
		    return KAL_TRUE;
	     else
		    return KAL_FALSE;
		break;

        default:
            //ASSERT(0);
            break;
    }
    return KAL_FALSE;
}

/* END: PH smu_security_info_struct (NVRAM_EF_MS_SECURITY_LID)  */

/*******************************************************************************
 * FUNCTION  
 *  sml_Nvram_get_size
 * DESCRIPTION
 *  This function is used to query the status of the category
 * PARAMETERS
 *  IN          file_idx
 * RETURN
 *  kal_uint16 file size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_uint16 sml_Nvram_get_lid_size(kal_uint8 file_idx)
{

    switch(file_idx)
    {
        case NVRAM_EF_MS_SECURITY_LID:
            
            return sizeof(smu_security_info_struct);

            break;

        case NVRAM_EF_SML_LID:

            return sizeof(sml_context_struct);

            break;

        case NVRAM_EF_SML_TMO_LID:

            return sizeof(sml_tmo_context_struct);

            break;

        default:

            return 0;

            break;

    }

}

#ifdef __SIM_ME_LOCK__

/* Define your GID1 code here!! */
/***************************************************************************** 
 * The maximum length supported of GID1 is 20 bytes, represented as sim_gid1[20]
 * Modify gid1[20] array to support multiple sets of GID1 code
 * For example,
 *     With GID1 length 5 bytes, if there are 2 sets of GID1 code, 
 *       1st GID1:  0x11, 0x22, 0x33, 0x44, 0x55
 *      2nd GID1:  0x66, 0x77, 0x88, 0x99, 0xAA
 *       You should set gid1_length = 5, gid1_set = 2, and assign gid1[20] as followed:
 *       gid1[20] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 
 *                        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
 * Important: Use '0xFF' as the rest element of gid1 array
 * 
 * You may extend the size of gid1[] array to support plenty sets of GID1 code as you want
 *****************************************************************************/
kal_bool is_gid1_matched(kal_uint8 *sim_gid1)
{
    /* Open GID1_SECURITY_CHECK */
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
#endif       


    /* Close GID1_SECURITY_CHECK, return KAL_TRUE */
//#if 0
      	return KAL_TRUE;
//#endif
    
}

/*[MAUI_01634719] mtk01612*/
/***************************************************************************** 
*
 *****************************************************************************/
kal_bool is_mcc_mnc_matched(kal_uint8 *sim_code, kal_uint8 len)
{
    /* Open MCC/MNC check for N category */
/*[MAUI_01634719] mtk01612: test*/
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
#endif

    /* Close MCC/MNC check for N category, return KAL_TRUE */
//#if 0
      	return KAL_TRUE;
//#endif
    
}

/* Define your Block list here!! */
/***************************************************************************** 
 * For example 2 digits MNC case: MCC\MNC 466 97 => 0x46 0x69 0x7F 
 *             3 digits MNC case: MCC\MNC 466 285 => 0x46 0x62 0x85
 * !!!IMPORTANT: USE three 0xFF at the end of array to terminate !!! 
 *****************************************************************************/
static const kal_uint8 smlVISA[] = {
/* Insert your items here */

//0x46, 0x61, 0x1F,   // Item 1
//0x46, 0x69, 0x2F,   // Item 2

/* Do not modify the 0xFF 0xFF 0xFF below */
0xFF, 0xFF, 0xFF }; // Do not modify this line!



/* BEGIN: PH sml_context_struct (NVRAM_EF_SML_LID) */
/******************************************************************************
 * New SML Architecture
 *****************************************************************************/
/******************************************************************************
 *    typedef struct {
 *        kal_uint32  magic_head;
 *        sml_category_meta_struct    cat[SML_CAT_SIZE];
 *        sml_control_key_struct      key[SML_CAT_SIZE];
 *        kal_uint8   code_cat_n[SML_CFG_CAT_N_SIZE];
 *        kal_uint8   code_cat_ns[SML_CFG_CAT_NS_SIZE];
 *        kal_uint8   code_cat_sp[SML_CFG_CAT_SP_SIZE];
 *        kal_uint8   code_cat_c[SML_CFG_CAT_C_SIZE];
 *        kal_uint8   code_cat_sim[SML_CFG_CAT_SIM_SIZE];
 *        kal_uint8   code_cat_ns_sp[SML_CFG_CAT_NS_SP_SIZE];
 *        kal_uint8   code_cat_sim_c[SML_CFG_CAT_SIM_C_SIZE];
 *        kal_uint8   range_cat_ns[SML_CAT_NS_RANGE_SIZE]
 *        kal_uint32 magic_tail;         
 *    } sml_context_struct;
 *****************************************************************************/ 

/***************************************************************************** 
 * Typedef of SML
 *****************************************************************************/
static void sml_give( void * pLidToObj, kal_uint8 source );
static void sml_take( void * pObjToLid, kal_uint8 source );
static void sml_destory( kal_uint8 source );
static void * sml_getItem( sml_cat_enum cat, 
                           sml_ctx_enum item, 
                           kal_uint16 * plength,
                           kal_uint8 source
                         );
static void sml_putItem( sml_cat_enum cat, 
                         sml_ctx_enum item, 
                         void * pItem, 
                         kal_uint16 * plength,
                         kal_uint8 source
                       );

/* TMO SML */
static void sml_tmo_give( void * pLidToObj, kal_uint8 source );
static void sml_tmo_take( void * pObjToLid, kal_uint8 source );
static void sml_tmo_destory( kal_uint8 source );
static void * sml_tmo_getItem( sml_cat_enum cat, 
                           sml_ctx_enum item, 
                           kal_uint16 * plength,
                           kal_uint8 source
                         );
static void sml_tmo_putItem( sml_cat_enum cat, 
                         sml_ctx_enum item, 
                         void * pItem, 
                         kal_uint16 * plength,
                         kal_uint8 source
                       );


/* define the Local variable of SML */
static nvram_ef_sml_obj_struct SMLOBJ[MAX_SIM_NUM];

/* define the Local variable of SML object */
static sml_context_struct sml_cntxt_obj[MAX_SIM_NUM];

/* define the Local variable of SML TMO object */
static sml_tmo_context_struct sml_tmo_cntxt_obj[MAX_SIM_NUM];

/* define the Global access pointer of SML object */
nvram_ef_sml_obj_struct * pSMLg = &SMLOBJ[0];


/*******************************************************************************
 * Define the method of the object
 *******************************************************************************/
void sml_init_sml_obj(kal_uint8 source)
{
    nvram_ef_sml_obj_struct sml_obj = {
        NULL,    
        sml_give,
        sml_take,
        sml_destory,
        sml_getItem,
        sml_putItem
    };

    nvram_ef_sml_obj_struct sml_tmo_obj = {
        NULL,    
        sml_tmo_give,
        sml_tmo_take,
        sml_tmo_destory,
        sml_tmo_getItem,
        sml_tmo_putItem
    };

    if (sbp_query_md_feature(SBP_TMO_REMOTE_SIM_LOCK) == KAL_TRUE)
    {
        sml_tmo_destory(source);
        kal_mem_cpy(&pSMLg[source], &sml_tmo_obj, sizeof(nvram_ef_sml_obj_struct));
    }
    else
    {
        sml_destory(source);
        kal_mem_cpy(&pSMLg[source], &sml_obj, sizeof(nvram_ef_sml_obj_struct));
    }
}


// TMO SML

/* time to temporary unlock expiry in seconds */
kal_uint32 sml_tmo_seconds_to_expire = 0;
extern kal_bool smu_sml_tmo_timer_expiry_callback(void *param);

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_printkey
 * DESCRIPTION
 *  This method print the key for debugging
 * PARAMETERS
 *  IN          * key
 * RETURN
 *  void
*******************************************************************************/
void sml_tmo_printkey(t_cust_chl_sym_key *key)
{
#if 0
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

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_give
 * DESCRIPTION
 *  This method copys the LID files read from NVRAM to the SML obj
 * PARAMETERS
 *  IN          * pLidToObj
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
*******************************************************************************/
static void sml_tmo_give( void *pLidToObj, kal_uint8 source )
{
    sml_tmo_context_struct * pObj = NULL;
  
    if(NULL != pSMLg[source].pObj)
    {
    
        kal_sys_trace("SML: object is exist!");
    
        pSMLg[source].pObj = NULL;
    
    }
       
    pObj = &(sml_tmo_cntxt_obj[source]);
    
    kal_mem_cpy(pObj,
                pLidToObj,
                sizeof(sml_tmo_context_struct)
                ); 
   
    pSMLg[source].pObj = pObj;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_take
 * DESCRIPTION
 *  This method copys the contex of the SML object to the provided NVRAM LID.
 * PARAMETERS
 *  OUT         * pObjToLid
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
static void sml_tmo_take( void *pObjToLid, kal_uint8 source )
{
    sml_tmo_context_struct * pObj = (sml_tmo_context_struct *) pSMLg[source].pObj;
          
    kal_mem_cpy(pObjToLid,
                pObj,
                sizeof(sml_tmo_context_struct)
                );
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_destory
 * DESCRIPTION
 *  This method free the SML object in memory if it is not used.
 * PARAMETERS
 *  void
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/    
static void sml_tmo_destory(kal_uint8 source)
{
    pSMLg[source].pObj = NULL;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_getItem
 * DESCRIPTION
 *  This method returns the structure pointer and length of the structure
 *  of the desired SML object items.
 * PARAMETERS
 *  IN          cat
 *  IN          item
 *  OUT         *length
 * RETURN
 *  void *
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
static void * sml_tmo_getItem( sml_cat_enum category, 
                           sml_ctx_enum item, 
                           kal_uint16 *plength,
                           kal_uint8 source)
{
    sml_tmo_context_struct *pObj = (sml_tmo_context_struct *) pSMLg[source].pObj;
    
    ASSERT(NULL != pObj);
    
    switch(item)
    {
        case SML_TMO_CAT_VERSION:
            *plength = SML_TMO_SIZE_OF_VERSION;
            return (kal_uint32 *) &(pObj->version[0]);
        
        case SML_TMO_CAT_PERTECTION_SCHEME:
            *plength = sizeof(kal_uint8);
            return (kal_uint32 *) &(pObj->protection_scheme);
        
        case SML_TMO_CAT_STATE:
            *plength = sizeof(kal_uint8);
             return (kal_uint8 *) &(pObj->state);
        
        case SML_TMO_CAT_LENGTH:
            *plength = SML_TMO_SIZE_OF_LENGTH;
            return (kal_uint16 *) &(pObj->length[0]);
        
        case SML_TMO_CAT_MCC_MNC_GID:
            *plength = SML_TMO_SIZE_OF_MCC_MNC_GID;
            return (kal_uint8 *) &(pObj->mcc_mnc_gid[0]);

        case SML_TMO_CAT_START_TIME:
            *plength = SML_TMO_SIZE_OF_START_TIME;
            return (kal_uint32 *) &(pObj->start_time[0]);
            
        case SML_TMO_CAT_END_TIME:
            *plength = SML_TMO_SIZE_OF_END_TIME;
            return (kal_uint32 *) &(pObj->end_time[0]);

        case SML_TMO_CAT_VERIFICATION_CODE:
            *plength = SML_TMO_SIZE_OF_VERIFICATION_CODE;
            return (kal_uint8 *) &(pObj->verification_code[0]);

        case SML_TMO_CAT_TEMP_LOCK_TIME_COUNTER:
            *plength = 4;
            return (kal_uint32 *) &(pObj->verification_code[252]);

        default:
            break;   
    }

    return NULL;
    
}


/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_putItem
 * DESCRIPTION
 *  This method set the desired items of the SML object.
 * PARAMETERS
 *  IN          cat
 *  IN          item
 *  IN          *pItem
 *  IN          *plength
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
static void sml_tmo_putItem( sml_cat_enum cat, 
                         sml_ctx_enum item, 
                         void *pItem, 
                         kal_uint16 *plength,
                         kal_uint8 source)
{
    sml_tmo_context_struct *pObj = (sml_tmo_context_struct *) pSMLg[source].pObj;
    
    ASSERT(NULL != pObj);
    
    switch(item)
    {
        case SML_TMO_CAT_TEMP_LOCK_TIME_COUNTER:
                  
            kal_mem_cpy(&(pObj->verification_code[252]),
                        pItem,
                        4
                        );        
            break;
                
        default:
            break;
    }
}


/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_checkValidity
 * DESCRIPTION
 *  This method is to check the validity of the SML object
 * PARAMETERS
 *  IN          pObj    SML object
 * RETURN
 *  TRUE        Pass the validity check
 *  FALSE       Fail the validity check
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_tmo_checkValidity(void *pObj)
{
    sml_tmo_context_struct *pSmlObj = (sml_tmo_context_struct *) pObj;
    kal_bool result;
    kal_uint32 obj_len, data_len;

    if (pSmlObj == NULL)
    {
        return KAL_FALSE;
    }

    obj_len = (((kal_uint32)pSmlObj->length[0]) << 8) + pSmlObj->length[1];

    if (pSmlObj->protection_scheme == SML_PROTECTION_SCHEME_HMAC_SHA256)
    {
        t_cust_chl_sym_key key = {0};
        kal_uint32 ret;

        data_len = obj_len - SML_TMO_SIZE_OF_MAC;

        ret = CustCHL_Get_Sym_Key(CUST_TM_SHARED_KEY2, &key);
        if (ret == CUST_CHL_ERROR_NONE)
        {
            ret = CustCHL_Verify_MAC(CUST_CHL_ALG_MAC_SHA256, (kal_uint8 *) pSmlObj, data_len, 
                                     &pSmlObj->verification_code[0], &key.m_key[0], key.m_key_len);

            sml_tmo_printkey(&key);
        }
        result = (ret == CUST_CHL_ERROR_NONE) ? KAL_TRUE : KAL_FALSE;

    }
    else if (pSmlObj->protection_scheme == SML_PROTECTION_SCHEME_RSA2048)
    {
        t_cust_chl_asym_key key;
        kal_uint32 ret;

        data_len = obj_len - SML_TMO_SIZE_OF_SIGNATURE;

        ret = CustCHL_Get_Asym_Key(CUST_TM_PUB_KEY1, &key);
        if (ret == CUST_CHL_ERROR_NONE)
        {
            ret = CustCHL_Verify_PSS_Signature(CUST_CHL_ALG_RSA_PSS_SHA256, (kal_uint8 * )pSmlObj, data_len, 
                                               &pSmlObj->verification_code[0], &key);
        }
        result = (ret == CUST_CHL_ERROR_NONE) ? KAL_TRUE : KAL_FALSE;
    }
    else
    {
        result = KAL_FALSE;
    }

    return result;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_nwTimeToSeconds
 * DESCRIPTION
 *  This method is to convert network time to seconds that have elapsed since 1970/1/1,00:00:00
 * PARAMETERS
 *  IN          nw_time_zone
 *  IN          nw_time
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_uint32 sml_tmo_nwTimeToSeconds(kal_uint8 nw_time_zone, nw_time_zone_time_struct *nw_time)
{
    kal_uint32 seconds = 0;
    kal_uint8 year_diff = 0, month_diff = 0, hour_diff = 0, min_diff = 0, sec_diff = 0;
    kal_uint16 day_diff = 0;
    kal_uint8 leap_years = 0;
    kal_uint8 time_diff = 0;
    kal_uint8 month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    kal_uint8 i;
    //kal_uint8 timezone = nw_time->time_zone;

    /* base time: 1970/1/1,00:00:00 */
    year_diff = 2000 + (nw_time->year & 0x0F)*10 + (nw_time->year >> 4) - 1970;
    if (year_diff >= 100)
    {
        year_diff -= 100;
    }
    /* there is a leap year every four years */
    leap_years = (year_diff+2)/4;

    month_diff = (nw_time->month & 0x0F)*10 + (nw_time->month >> 4) - 1;
    day_diff = (nw_time->day & 0x0F)*10 + (nw_time->day >> 4) - 1;
    hour_diff = (nw_time->hour & 0x0F)*10 + (nw_time->hour >> 4);
    min_diff = (nw_time->min & 0x0F)*10 + (nw_time->min >> 4);
    sec_diff = (nw_time->sec & 0x0F)*10 + (nw_time->sec >> 4);

    day_diff += leap_years;
    for (i = 0; i < month_diff; i++)
    {
        day_diff += month_days[i];
    }

    seconds = 365*24*60*60*year_diff + 24*60*60*day_diff + 60*60*hour_diff + 60*min_diff + sec_diff;

    // start_time in TMO SLB is UTC (GMT+0) time, thus no need adjust timezone
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
#endif

    //kal_prompt_trace(MOD_SMU,"year_diff:%d",year_diff);
    //kal_prompt_trace(MOD_SMU,"leap_years:%d month_diff:%d day_diff:%d",leap_years,month_diff,day_diff);
    //kal_prompt_trace(MOD_SMU,"hour_diff:%d",hour_diff);
    //kal_prompt_trace(MOD_SMU,"min_diff:%d",min_diff);
    //kal_prompt_trace(MOD_SMU,"sec_diff:%d",sec_diff);
    //kal_prompt_trace(MOD_SMU,"timezone_diff:%d",time_diff);
    //kal_prompt_trace(MOD_SMU,"[Total seconds]= %x",(kal_uint32)seconds);

    return seconds;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_UpdaetNwTimeAndCheckTempLock
 * DESCRIPTION
 *  This method is to update newtork time and check if temporary lock expires
 * PARAMETERS
 *  IN          source
 *  IN          nw_time_zone
 *  IN          nw_time
 * RETURN
 *  TRUE        Temporary unlock expires
 *  FALSE       Temporary unlock does not expire
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_tmo_UpdaetNwTimeAndCheckTempLock(kal_uint8 source, kal_uint8 nw_time_zone, nw_time_zone_time_struct *nw_time)
{
    nvram_ef_sml_obj_struct *p = &pSMLg[source];
    kal_uint8 *start_time, *end_time;
    kal_uint8 *state = NULL;
    kal_uint16 length;
    kal_uint32 current_seconds = 0;
    kal_uint64 start_seconds = 0;
    kal_uint32 start_seconds_u32 = 0;
    kal_uint32 duration_seconds = 0;
    kal_uint8 i;

    state = (kal_uint8 *)(*p->getItem)(SML_CAT_C, SML_TMO_CAT_STATE, &length, source);
    start_time = (kal_uint8 *)(*p->getItem)(SML_CAT_C, SML_TMO_CAT_START_TIME, &length, source);
    end_time = (kal_uint8 *)(*p->getItem)(SML_CAT_C, SML_TMO_CAT_END_TIME, &length, source);

    if (*state != SML_TMO_STATE_TEMPORARY_UNLOCK)
    {
        return KAL_FALSE;
    }

    /* calculate start time and duration in seconds */
    start_seconds = 0;
    for (i = 0; i < SML_TMO_SIZE_OF_START_TIME-1; i++)
    {
        start_seconds += start_time[i];
        start_seconds = (start_seconds << 8);
    }
    start_seconds += start_time[SML_TMO_SIZE_OF_START_TIME-1];
    start_seconds /= 1000;  /* from milliseconds to seconds */

    start_seconds_u32 = (kal_uint32)start_seconds;

    duration_seconds = 0;
    for (i = 0; i < SML_TMO_SIZE_OF_END_TIME-1; i++)
    {
        duration_seconds += end_time[i];
        duration_seconds = (duration_seconds << 8);
    }
    duration_seconds += end_time[SML_TMO_SIZE_OF_END_TIME-1];

    /* calculate current time in seconds */
    current_seconds = sml_tmo_nwTimeToSeconds(nw_time_zone, nw_time);

    SML_TRACE(TRACE_INFO, INFO_SML_TEMP_UNLOCK_TIME, start_seconds_u32, duration_seconds, current_seconds);

    //kal_prompt_trace(MOD_SMU,"start_seconds_u32= %x", start_seconds_u32);
    //kal_prompt_trace(MOD_SMU,"duration_seconds= %x", (kal_uint32)duration_seconds);
    //kal_prompt_trace(MOD_SMU,"current_seconds= %x", (kal_uint32)current_seconds);

    if (current_seconds >= (start_seconds_u32+duration_seconds))
    {
        SML_TRACE(TRACE_INFO, INFO_SML_NW_TIME_EXPIRED);
        /* expired */
        //*state = SML_STATE_PERMANENT_LOCK;
        //sml_tmo_seconds_to_expire = 0;       
        return KAL_TRUE;
    }
    else
    {
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        return KAL_FALSE;
    }
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_CheckTempUnlock
 * DESCRIPTION
 *  This method is to check if temporary unlock expires
 * PARAMETERS
 *  IN          source
 * RETURN
 *  TRUE        Temporary unlock expires
 *  FALSE       Temporary unlock does not expire
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_tmo_CheckTempUnlock(kal_uint8 source)
{
    nvram_ef_sml_obj_struct *p = &pSMLg[source];    
    kal_uint8 *state, *end_time;
    kal_uint16 length;
    kal_uint32 duration_seconds = 0;
    kal_uint8 i;

    state = (kal_uint8 *)(*p->getItem)(SML_CAT_C, SML_TMO_CAT_STATE, &length, source);
    end_time = (kal_uint8 *)(*p->getItem)(SML_CAT_C, SML_TMO_CAT_END_TIME, &length, source);

    for (i = 0; i < SML_TMO_SIZE_OF_END_TIME-1; i++)
    {
        duration_seconds += end_time[i];
        duration_seconds = (duration_seconds << 8);
    }
    duration_seconds += end_time[SML_TMO_SIZE_OF_END_TIME-1];

    SML_TRACE(TRACE_INFO, INFO_SML_CHECK_TEMP_UNLOCK, sml_tmo_seconds_to_expire, duration_seconds);

    //kal_prompt_trace(MOD_SMU, "counter: %d duration_seconds:%d", 
    //    sml_tmo_seconds_to_expire + (SML_TMO_TIMEOUT_PERIODIC_CHECK/KAL_TICKS_1_SEC),duration_seconds);

    if ((sml_tmo_seconds_to_expire + (SML_TMO_TIMEOUT_PERIODIC_CHECK/KAL_TICKS_1_SEC)) >= duration_seconds)
    {
        *state = SML_TMO_STATE_PERMANENT_LOCK;
        // Should reset SLB/NVRAM in following action
        return KAL_TRUE;
    }
    else
    {
        sml_tmo_seconds_to_expire += (SML_TMO_TIMEOUT_PERIODIC_CHECK/KAL_TICKS_1_SEC);
        (*p->putItem)(SML_CAT_C, SML_TMO_CAT_TEMP_LOCK_TIME_COUNTER, &sml_tmo_seconds_to_expire, &length, source);
        // Should write back to NVRAM in following action
        return KAL_FALSE;
    }
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_FirstLoad
 * DESCRIPTION
 *  This function check if it is the first loads of SML obj from NVRAM LID. If so,
 *  calculate the verification code and store it
 * PARAMETERS
 *  IN          pLid
 * RETURN
 *  kal_bool    TRUE: first load
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_tmo_FirstLoad( void *pLid, kal_uint8 source )
{
    nvram_ef_sml_obj_struct *p = &pSMLg[source];
    kal_uint32 i;
    kal_uint16 length = sizeof(sml_tmo_context_struct);
    sml_tmo_context_struct * pObj = NULL;
    kal_bool isFirstLoad = KAL_TRUE;

    pObj = (sml_tmo_context_struct *) pLid;

    /* the verification code will be all zero if it is the first time to load */
    for (i = 0; i < SML_TMO_SIZE_OF_VERIFICATION_CODE; i++)
    {
        if (pObj->verification_code[i] != 0)
        {
            isFirstLoad = KAL_FALSE;
            break;
        }
    }

    if (isFirstLoad == KAL_TRUE)
    {
        kal_uint32 ret = CUST_CHL_ERROR_NONE;

        if (pObj->protection_scheme == SML_PROTECTION_SCHEME_HMAC_SHA256)
        {
            t_cust_chl_sym_key key = {0};
            kal_uint16 data_len;
            
            data_len = length - SML_TMO_SIZE_OF_VERIFICATION_CODE;
            
            ret = CustCHL_Get_Sym_Key(CUST_TM_SHARED_KEY2, &key);
            if (ret == CUST_CHL_ERROR_NONE)
            {
                t_cust_chl_mac_u mac;

                pObj->length[0] = 0x00;
                pObj->length[1] = 0x3C; // 60

                ret = CustCHL_Calculate_MAC(CUST_CHL_ALG_MAC_SHA256, (kal_uint8 *) pObj, data_len, 
                                            &key.m_key[0], key.m_key_len, &mac);
                if (ret == CUST_CHL_ERROR_NONE)
                {
                    kal_mem_cpy(&pObj->verification_code[0], &mac.m_u8[0], mac.m_len);

                    // Test validation
                    if (sml_tmo_checkValidity((void*)pObj) == KAL_FALSE)
                    {
                        SML_TRACE(TRACE_WARNING, WARNING_SML_LOAD_CHECK_VALIDITY_FAILED);
                    }
                }
            }
        }
        else
        {
            /* To-Do for signature */
        }

        if (ret == CUST_CHL_ERROR_NONE)
        {
            /* Clean the old ones */
            (*p->destory)(source);

            /* Load the new one */
            (*p->give)((void *)pObj, source);
        }
    }

    return isFirstLoad;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_Load
 * DESCRIPTION
 *  This function loads the SML obj from NVRAM LID (NVRAM_READ_CNF)
 * PARAMETERS
 *  IN          pLid
 * RETURN
 *  kal_uint16  Obj size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_uint16 sml_tmo_Load( void *pLid, kal_uint8 source )
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    kal_uint16 length = sizeof(sml_tmo_context_struct);

    if (sml_tmo_checkValidity(pLid) == KAL_FALSE)
    {
        SML_TRACE(TRACE_WARNING, WARNING_SML_LOAD_CHECK_VALIDITY_FAILED);
        return SML_TMO_INVALID_CONTEXT_OBJ_LENGTH;
    }

    /* Clean the old ones */
    (*p->destory)(source);

    /* Load the new one */
    (*p->give)(pLid, source);

    return length;

}


/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_Save
 * DESCRIPTION
 *  This function saves the SML obj to NVRAM LID (NVRAM_WRITE_REQ)
 * PARAMETERS
 *  OUT          pLid
 * RETURN
 *  kal_uint16  Obj size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_uint16 sml_tmo_Save( void *pLid, kal_uint8 source )
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    kal_uint16 length = sizeof(sml_tmo_context_struct);

    (*p->take)(pLid, source);

    return length;
    
}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_Check
 * DESCRIPTION
 *  This function is used to check if the code is in the Pass list
 * PARAMETERS
 *  IN          cat
 *  IN          *code
 *  IN          len
 *  OUT          *remain
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
kal_bool sml_tmo_Check( sml_cat_enum cat, 
                    kal_uint8 *imsi, 
                    kal_uint8 *gid1,
                    kal_uint8 *gid2,
                    kal_uint8 sim_mnc_len,
                    kal_uint8 *remain,
                    kal_uint8 source)
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];
    kal_uint8 *pState = NULL;
    kal_uint8 *pData = NULL;
    kal_uint16 length = 0;
    kal_uint8 code[SML_TMO_SIZE_OF_MCC_MNC_GID] = {0};
    kal_uint8 code_len = 0;
    kal_uint8 compare_length = 0;

    /* Check the integration of SIM Lock blob first */
    if ((p == NULL) || (p != NULL && sml_tmo_checkValidity(p->pObj) == KAL_FALSE))
    {
        SML_TRACE(TRACE_WARNING, WARNING_SML_CHECK_VALIDITY_FAILED);
        return KAL_FALSE;
    }
    
    pState = (kal_uint8 *)(*p->getItem)(cat, SML_TMO_CAT_STATE, &length, source);
    pData = (kal_uint8 *)(*p->getItem)(cat, SML_TMO_CAT_MCC_MNC_GID, &length, source);

    *remain = 0xFF;    /* TMO SIM lock doesn't need retry counter */

    if (*pState == SML_TMO_STATE_TEMPORARY_UNLOCK)
    {
        kal_uint32 *counter = (kal_uint32 *)(*p->getItem)(cat, SML_TMO_CAT_TEMP_LOCK_TIME_COUNTER, &length, source);

        sml_tmo_seconds_to_expire += *counter;

        if (smu_sml_tmo_timer_expiry_callback(NULL) == KAL_TRUE)
        {
            // Time expired -> back to LOCK , reset counter
            *pState = SML_TMO_STATE_PERMANENT_LOCK;
            //return KAL_FALSE;
        }
        else
        {
            return KAL_TRUE;
        }
    }

    if (*pState == SML_TMO_STATE_PERMANENT_UNLOCK)
    {
        /* always pass if it is not locked! */
        return KAL_TRUE;
    }

    if (*pState == SML_TMO_STATE_PERMANENT_LOCK)
    {
        code_len = sml_tmo_GetCode(cat, imsi, gid1, gid2, sim_mnc_len, NULL, code);
        compare_length = SML_TMO_SIZE_OF_MCC_MNC_GID;       

    }
    else /* SML_STATE_PARTIAL_UNLOCK */
    {
        /* GID is not necessary in partial unlock */
        code_len = sml_tmo_GetCode(cat, imsi, NULL, NULL, sim_mnc_len, NULL, code);
        compare_length = SML_TMO_SIZE_OF_MCC_MNC;       
    }

    //kal_prompt_trace(MOD_SMU,"code : %02x %02x %02x %02x %02x %02x", code[0], code[1], code[2], code[3], code[4], code[5]);
    //kal_prompt_trace(MOD_SMU,"pData: %02x %02x %02x %02x %02x %02x", pData[0], pData[1], pData[2], pData[3], pData[4], pData[5]);
    //kal_prompt_trace(MOD_SMU,"code_len:%d compare_length:%d",code_len,compare_length);

    if (code_len != compare_length)
    {
        return KAL_FALSE;
    }

    if (kal_mem_cmp(code, pData, compare_length) == 0)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }

}

/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_Catcode
 * DESCRIPTION
 *  This function is used to compose the code of each category
 * PARAMETERS
 *  IN          cat
 *  IN          *imsi
 *  IN          *gid1
 *  IN          *gid2
 *  IN          mnc_len
 *  OUT          *code
 * RETURN
 *  kal_uint8   code length
 * GLOBALS AFFECTED
 *  NONE
 *******************************************************************************/ 
kal_uint8 sml_tmo_Catcode( sml_cat_enum cat,
                       kal_uint8 *imsi,
                       kal_uint8 *gid1,
                       kal_uint8 *gid2,
                       kal_uint8 mnc_len,
                       kal_uint8 *code )
{
    kal_uint8 code_len = 0;

    if (imsi == NULL)
    {
        return 0;
    }

    if(mnc_len == 3)
    {
        /* MCC/MNC */
        code[0] = (imsi[1]&0xF0) | (imsi[2]&0x0F);
        code[1] = (imsi[2]&0xF0) | (imsi[3]&0x0F);
        code[2] = (imsi[3]&0xF0) | (imsi[4]&0x0F);
        code[3] = 0;

    }
    else
    {
        /* MCC/MNC */
        code[0] = (imsi[1]&0xF0) | (imsi[2]&0x0F);
        code[1] = (imsi[2]&0xF0) | (imsi[3]&0x0F);
        code[2] = (imsi[3]&0xF0);
        code[3] = 0;
    }

    // TMO use 2 byte GID1
    // if (gid1 != NULL && gid2 != NULL)
    if (gid1 != NULL)
    {
        /* GID */
        code[4] = gid1[0];
        code[5] = gid1[1];
        //code[5] = gid2[0];
        code_len = SML_TMO_SIZE_OF_MCC_MNC_GID;
    }
    else
    {
        code_len = SML_TMO_SIZE_OF_MCC_MNC;
    }

    return code_len;
    
}

/*******************************************************************************
 * FUNCTION
 *  sml_tmo_GetCode
 * DESCRIPTION
 *  This function is used to compose the code of each category  whether 
 *  mnc length is 2 or 3
 * PARAMETERS
 *  cat         [IN]    category of the SIM-ME-Lock
 *  imsi        [IN]    imsi of the code source 
 *  gid1        [IN]    gid1 of the code source
 *  gid2        [IN]    gid2 of the code source
 *  sim_mnc_len [IN]    the mnc length decided by SIM
 *  pdata       [IN]    the saved code for comparing
 *  code        [OUT]   the composed code according to all input parameters
 *
 * RETURN
 *  kal_uint16 file size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/

kal_uint8 sml_tmo_GetCode( sml_cat_enum cat, 
                       kal_uint8 * imsi, 
                       kal_uint8 * gid1, 
                       kal_uint8 * gid2, 
                       kal_uint8 sim_mnc_len, 
                       kal_uint8 * pdata,
                       kal_uint8 * code)
{
    kal_uint8 mnc_len=0;

    if (SML_MNC_LENGTH_NEST == 1)
    {
        mnc_len = sim_mnc_len;
    }
    else
    {
        ASSERT(0); /* It is not possible to tell the MNC lengh in TMO SIM lock blob */
    }

    return sml_tmo_Catcode(cat, imsi, gid1, gid2, mnc_len, code);
}


/*******************************************************************************
 * FUNCTION  
 *  sml_tmo_GetVersion
 * DESCRIPTION
 *  This method is used to get SLB version
 * PARAMETERS
 *  OUT         SLB version
 *  IN          source
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  none
 *******************************************************************************/ 
void sml_tmo_GetVersion(kal_uint8 *version, kal_uint8 source)
{
    nvram_ef_sml_obj_struct *p = &pSMLg[source];
    kal_uint16 length;
    kal_uint8 *slb_ver;

    slb_ver = (kal_uint8 *) (*p->getItem)(SML_CAT_C, SML_TMO_CAT_VERSION, &length, source);

    kal_mem_cpy(version, slb_ver, SML_TMO_SIZE_OF_VERSION);
}


// TMO SML --- end


/*******************************************************************************
 * FUNCTION  
 *  sml_give
 * DESCRIPTION
 *  This method copys the LID files read from NVRAM to the SML obj
 * PARAMETERS
 *  IN          * pLidToObj
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
static void sml_give( void *pLidToObj, kal_uint8 source )
{
    
    kal_uint32 magic_head = 0;
    
    kal_uint32 magic_tail = 0;
    
    sml_context_struct * pObj = NULL;
  
    if(NULL != pSMLg[source].pObj)
    {
    
        kal_sys_trace("SML: object is exist!");
    
//        free_ctrl_buffer(pSMLg[source].pObj);
        
        pSMLg[source].pObj = NULL;
    
    }
       
//  pObj = (sml_context_struct *) get_ctrl_buffer(sizeof(sml_context_struct));
    pObj = &(sml_cntxt_obj[source]);
    
    kal_mem_cpy(pObj,
                pLidToObj,
                sizeof(sml_context_struct)
                ); 
    
    /* Check magic head and tail */
    magic_head = pObj->magic_head;
    
    magic_tail = pObj->magic_tail;

#ifdef __MTK_TARGET__
//  Mark for temporary solution of SIM-ME-Lock
    ASSERT((magic_head == sizeof(sml_context_struct))
           && (magic_tail == SML_MAGIC_TAIL_VALUE));
#endif
    pSMLg[source].pObj = pObj;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_take
 * DESCRIPTION
 *  This method copys the contex of the SML object to the provided NVRAM LID.
 * PARAMETERS
 *  OUT         * pObjToLid
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
static void sml_take( void *pObjToLid, kal_uint8 source )
{
    
//    kal_uint32 magic_head = 0;
    
//    kal_uint32 magic_tail = 0;
   
    sml_context_struct * pObj = (sml_context_struct *) pSMLg[source].pObj;
     
    /* Check magic head and tail */
//    magic_head = pObj->magic_head;
    
//    magic_tail = pObj->magic_tail;

//  Mark for temporary solution of SIM-ME-Lock
//    ASSERT((magic_head == SML_MAGIC_HEAD_VALUE)
//           && (magic_tail == SML_MAGIC_TAIL_VALUE));
           
    kal_mem_cpy(pObjToLid,
                pObj,
                sizeof(sml_context_struct)
                );

} 

/*******************************************************************************
 * FUNCTION  
 *  sml_destory
 * DESCRIPTION
 *  This method free the SML object in memory if it is not used.
 * PARAMETERS
 *  void
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/    
static void sml_destory(kal_uint8 source)
{
#if 0
/* under construction !*/
/* under construction !*/
#endif

    pSMLg[source].pObj = NULL;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_getItem
 * DESCRIPTION
 *  This method returns the structure pointer and length of the structure
 *  of the desired SML object items.
 * PARAMETERS
 *  IN          cat
 *  IN          item
 *  OUT         *length
 * RETURN
 *  void *
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
static void * sml_getItem( sml_cat_enum category, 
                           sml_ctx_enum item, 
                           kal_uint16 *plength,
                           kal_uint8 source)
{
    sml_context_struct *pObj = (sml_context_struct *) pSMLg[source].pObj;
    
    ASSERT(NULL != pObj);
    
    switch(item)
    {
        
        case SML_MAGIC_HEAD:
        
        case SML_MAGIC_TAIL:
        
            //ASSERT(0);
        
            break;
        
        case SML_CAT_META:
        
            *plength = sizeof(sml_category_meta_struct);
        
            return (sml_category_meta_struct *) &(pObj->cat[category]);
        
            break;
        
        case SML_CAT_KEY:
        
            *plength = sizeof(sml_control_key_struct);
        
            return (sml_control_key_struct *) &(pObj->key[category]);
        
            break;
        
        case SML_CAT_CODE:
        
            switch(category)
            {
        
                case SML_CAT_N:
        
                    *plength = SML_CFG_CAT_N_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_n[0]);
        
                    break;
        
                case SML_CAT_NS:
        
                    *plength = SML_CFG_CAT_NS_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_ns[0]);
        
                    break;
        
                case SML_CAT_SP:
        
                    *plength = SML_CFG_CAT_SP_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_sp[0]);
        
                    break;
        
                case SML_CAT_C:
        
                    *plength = SML_CFG_CAT_C_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_c[0]);
        
                    break;
        
                case SML_CAT_SIM:
        
                    *plength = SML_CFG_CAT_SIM_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_sim[0]);
        
                    break;
        
                case SML_CAT_NS_SP:
        
                    *plength = SML_CFG_CAT_NS_SP_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_ns_sp[0]);
        
                    break;
        
                case SML_CAT_SIM_C:
        
                    *plength = SML_CFG_CAT_SIM_C_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_sim_c[0]);
        
                    break;

                default:
                    /* do nothing */
                    break;
            }
        
            break;
        
        case SML_CAT_RANGE:
        
            switch(category)
            {

                case SML_CAT_N:
                    
                    *plength = 0;
                    
                    return NULL;
                    
                    break;

                case SML_CAT_NS:
                    
                    *plength = SML_CAT_NS_RANGE_SIZE;
                    
                    return (kal_uint8 *) &(pObj->range_cat_ns[0]);

                    break;

                case SML_CAT_SP:

                    *plength = 0;
                    
                    return NULL;
                    
                    break;

                case SML_CAT_C:
                    
                    *plength = 0;
                    
                    return NULL;

                    break;

                case SML_CAT_SIM:
                    
                    *plength = 0;
                    
                    return NULL;

                    break;

                case SML_CAT_NS_SP:
                    
                    *plength = 0;
                    
                    return NULL;

                    break;

                case SML_CAT_SIM_C:
                    
                    *plength = 0;
                    
                    return NULL;

                    break;

                default:
                    /* do nothing */
                    break;

            }            

            break;

        default:
                
            break;   

    }

    return NULL;
    
}

/*******************************************************************************
 * FUNCTION  
 *  sml_putItem
 * DESCRIPTION
 *  This method set the desired items of the SML object.
 * PARAMETERS
 *  IN          cat
 *  IN          item
 *  IN          *pItem
 *  IN          *plength
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
static void sml_putItem( sml_cat_enum cat, 
                         sml_ctx_enum item, 
                         void *pItem, 
                         kal_uint16 *plength,
                         kal_uint8 source)
{
    sml_context_struct *pObj = (sml_context_struct *) pSMLg[source].pObj;
    
    ASSERT(NULL != pObj);
    
    switch(item)
    {
        
        case SML_MAGIC_HEAD:
        
        case SML_MAGIC_TAIL:
        
            //ASSERT(0);
        
            break;
        
        case SML_CAT_META:
        
            //ASSERT(*plength == sizeof(sml_category_meta_struct));
            
            kal_mem_cpy(&(pObj->cat[cat]),
                        pItem,
                        *plength
                        );
        
            break;
        
        case SML_CAT_KEY:
        
            //ASSERT(*plength == sizeof(sml_control_key_struct));
        
            kal_mem_cpy(&(pObj->key[cat]),
                        pItem,
                        *plength
                        );
        
            break;
        
        case SML_CAT_CODE:
        
            switch(cat)
            {
        
                case SML_CAT_N:
        
                    //ASSERT(*plength <= SML_CFG_CAT_N_SIZE);
        
                    kal_mem_cpy(&(pObj->code_cat_n[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_NS:
        
                    //ASSERT(*plength <= SML_CFG_CAT_NS_SIZE);
                    
                    kal_mem_cpy(&(pObj->code_cat_ns[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_SP:
        
                    //ASSERT(*plength <= SML_CFG_CAT_SP_SIZE);
        
                    kal_mem_cpy(&(pObj->code_cat_sp[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_C:
        
                    //ASSERT(*plength <= SML_CFG_CAT_C_SIZE);
                            
                    kal_mem_cpy(&(pObj->code_cat_c[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_SIM:
        
                    //ASSERT(*plength <= SML_CFG_CAT_SIM_SIZE);
        
                    kal_mem_cpy(&(pObj->code_cat_sim[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_NS_SP:
        
                    //ASSERT(*plength <= SML_CFG_CAT_NS_SP_SIZE);
        
                    kal_mem_cpy(&(pObj->code_cat_ns_sp[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_SIM_C:
        
                    //ASSERT(*plength <= SML_CFG_CAT_SIM_C_SIZE);
        
                    kal_mem_cpy(&(pObj->code_cat_sim_c[0]),
                                pItem,
                                *plength
                                );
        
                    break;

                default:
                    /* do nothing */
                    break;
            }
        
            break;
        
        case SML_CAT_RANGE:
        
            switch(cat)
            {

                case SML_CAT_N:

                    break;

                case SML_CAT_NS:

                    //ASSERT(*plength <= SML_CAT_NS_RANGE_SIZE);
                    
                    kal_mem_cpy(&(pObj->range_cat_ns[0]),
                                pItem,
                                *plength
                                );

                    break;

                case SML_CAT_SP:

                    break;

                case SML_CAT_C:

                    break;

                case SML_CAT_SIM:

                    break;

                case SML_CAT_NS_SP:

                    break;

                case SML_CAT_SIM_C:

                    break;

                default:
                    /* do nothing */
                    break;

            }            

            break;

        default:

            break;   

    }
    
}

/* Define the Global handler of SML */
/*******************************************************************************
 * FUNCTION  
 *  sml_Load
 * DESCRIPTION
 *  This function loads the SML obj from NVRAM LID (NVRAM_READ_CNF)
 * PARAMETERS
 *  IN          pLid
 * RETURN
 *  kal_uint16  Obj size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_uint16 sml_Load( void *pLid, kal_uint8 source )
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    kal_uint16 length = sizeof(sml_context_struct);

    /* Clean the old ones */
    (*p->destory)(source);

    /* Load the new one */
    (*p->give)(pLid, source);

    return length;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_Save
 * DESCRIPTION
 *  This function saves the SML obj to NVRAM LID (NVRAM_WRITE_REQ)
 * PARAMETERS
 *  OUT          pLid
 * RETURN
 *  kal_uint16  Obj size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_uint16 sml_Save( void *pLid, kal_uint8 source )
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    kal_uint16 length = sizeof(sml_context_struct);

    (*p->take)(pLid, source);

    return length;
    
}


/*******************************************************************************
 * FUNCTION  
 *  sml_Unlock
 * DESCRIPTION
 *  This function unlock the desired category
 * PARAMETERS
 *  IN          cat
 *  IN          * key
 *  IN          key_len
 *  IN          source
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Unlock( sml_cat_enum cat,      // category
                     kal_uint8 *key, 
                     kal_uint8 key_len,
                     kal_uint8 source)      // 0:SIM1, 1:SIM2
{
    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_uint16 length = 0; 

    kal_bool result = KAL_FALSE;
    
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
 
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source);
    
    if((meta->state == SML_STATE_LOCK)&&(meta->retry_count > 0))
    {
        
        if(kal_mem_cmp(&(catkey->key[0]),key,key_len))
        {
            
            meta->retry_count--;
            
            /* Fail! Passwd not match! return KAL_FALSE; */
            
        }
        else
        {
            
            /* Success! return KAL_TRUE; */

            result = KAL_TRUE;

            meta->state = SML_STATE_UNLOCK;

            switch(cat)
            {
                
                case SML_CAT_N:
                
                    meta->retry_count = SML_RETRY_COUNT_N_CAT;
                    
                break;
                case SML_CAT_NS:
 
                    meta->retry_count = SML_RETRY_COUNT_NS_CAT;                    
                    
                break;
                case SML_CAT_SP:
                    
                    meta->retry_count = SML_RETRY_COUNT_SP_CAT;
                    
                break;
                case SML_CAT_C:
                    
                    meta->retry_count = SML_RETRY_COUNT_C_CAT;                    
                    
                break;
                case SML_CAT_SIM:
                   
                    meta->retry_count = SML_RETRY_COUNT_SIM_CAT;     
                    
                break;
                case SML_CAT_NS_SP:
                    
                    meta->retry_count = SML_RETRY_COUNT_NS_CAT;
                    
                break;
                case SML_CAT_SIM_C:
                    
                    meta->retry_count = SML_RETRY_COUNT_SIM_CAT;
                    
                break;    
                default:
                break;
                
            }           
                      
        }
        
    }

    return result;
}
 
/*******************************************************************************
 * FUNCTION  
 *  sml_Lock
 * DESCRIPTION
 *  This function Lock the desired category
 * PARAMETERS
 *  IN          cat
 *  IN          * key
 *  IN          key_len
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Lock( sml_cat_enum cat, 
                   kal_uint8 *key, 
                   kal_uint8 key_len,
                   kal_uint8 source)
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_uint16 length = 0; 

    kal_bool result = KAL_FALSE;
    
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
 
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 

    /* 
     * Perform Key state check. If the key is default SET, it must be equal 
     * to the key provided by the user. If it is not, the key will be set as 
     * the key provided by the user.
     */

    ASSERT( key_len <= SML_MAX_SUPPORT_KEY_LEN );
    
    if( SML_KEY_SET == catkey->state )
    {
    
        if( 0 == kal_mem_cmp(catkey->key,key,key_len) ) 
            result = KAL_TRUE;

    }
    else
    {
    
        result = KAL_TRUE;

    }

    /* Change the SML state if the category is not empty */
    
    if( (SML_STATE_UNLOCK == meta->state) 
        &&(KAL_TRUE == result) )
    {
    
        if( meta->num > 0 )
        {
        
            if( SML_KEY_EMPTY == catkey->state )
            {
            
                kal_mem_cpy(catkey->key,key,key_len);

            }

            meta->state = SML_STATE_LOCK;

        }
        else
        {
        
            kal_sys_trace("SML: The category is empty!");

            result = KAL_FALSE;

        }

    }
    else
    {

        result = KAL_FALSE;
    
    }
 
    return result;
    
}
 
/*******************************************************************************
 * FUNCTION  
 *  sml_Add
 * DESCRIPTION
 *  This function is used to add code into the desired category
 * PARAMETERS
 *  IN          cat
 *  IN          * code
 *  IN          len
 *  IN          * key
 *  IN          key_len
 *  OUT         * remain
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Add( sml_cat_enum cat, 
                  kal_uint8 *code, 
                  kal_uint8 len,
                  kal_uint8 *key,
                  kal_uint8 key_len,
                  kal_uint8 *remain,
                  kal_uint8 source)
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_uint8 *pdata = NULL;

    kal_uint16 length = 0, offset = 0; 

    kal_bool result = KAL_FALSE;
    
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 
    pdata = (kal_uint8 *) (*p->getItem)(cat,SML_CAT_CODE,&length, source);

    switch(cat)
    {
        
        case SML_CAT_N:

            //ASSERT(SML_SIZE_OF_CAT_N == len);

            offset = (meta->num) * SML_SIZE_OF_CAT_N;
            
            *remain = (length - offset) / SML_SIZE_OF_CAT_N;
                    
        break;
        
        case SML_CAT_NS:

            //ASSERT(SML_SIZE_OF_CAT_NS == len);

            offset = (meta->num) * SML_SIZE_OF_CAT_NS;        

            *remain = (length - offset) / SML_SIZE_OF_CAT_NS;        
            
        break;
        
        case SML_CAT_SP:
            
            //ASSERT(SML_SIZE_OF_CAT_SP == len);

            offset = (meta->num) * SML_SIZE_OF_CAT_SP;        

            *remain = (length - offset) / SML_SIZE_OF_CAT_SP;        
            
        break;

        case SML_CAT_C:

            //ASSERT(SML_SIZE_OF_CAT_C == len);
                        
            offset = (meta->num) * SML_SIZE_OF_CAT_C;   

            *remain = (length - offset) / SML_SIZE_OF_CAT_C;                
            
        break;
        
        case SML_CAT_SIM:

           //ASSERT(SML_SIZE_OF_CAT_SIM == len);
           
           offset = (meta->num) * SML_SIZE_OF_CAT_SIM;  

            *remain = (length - offset) / SML_SIZE_OF_CAT_SIM;               
            
        break;
        
        case SML_CAT_NS_SP:

            //ASSERT(SML_SIZE_OF_LINK_NS_SP == len);

            offset = (meta->num) * SML_SIZE_OF_LINK_NS_SP;   

            *remain = (length - offset) / SML_SIZE_OF_LINK_NS_SP;                    
            
        break;
        
        case SML_CAT_SIM_C:
            
            //ASSERT(SML_SIZE_OF_LINK_SIM_C == len);
            
            offset = (meta->num) * SML_SIZE_OF_LINK_SIM_C;   

            *remain = (length - offset) / SML_SIZE_OF_LINK_SIM_C;                
            
        break;    
        
        default:
            
        break;
        
    }           

    /* 
     * Perform Key state check. If the key is default SET, it must be equal 
     * to the key provided by the user. If it is not, the key will be set as 
     * the key provided by the user.
     */

    //ASSERT( key_len <= SML_MAX_SUPPORT_KEY_LEN );
    
    if( SML_KEY_SET == catkey->state )
    {
    
        if( 0 == kal_mem_cmp(catkey->key,key,key_len) ) 
            result = KAL_TRUE;

    }
    else
    {
    
        result = KAL_TRUE;

    }    
    
    /* Check if the space is available */
    if( (*remain > 0)
        && (SML_STATE_UNLOCK == meta->state)
        && (KAL_TRUE == result) )
    {

        if(SML_KEY_EMPTY == catkey->state)
        {
        
            kal_mem_cpy(catkey->key,key,key_len);
            
        }

        kal_mem_cpy((kal_uint8 *)(pdata+offset),
                    code,
                    len
                    );
        
        meta->num ++;

        (*remain)--;

        meta->state = SML_STATE_LOCK;
        
    }
    else
    {

        kal_sys_trace("SML: Add fail!");
    
        result = KAL_FALSE;

    }
    
    return result;

}
 
/*******************************************************************************
 * FUNCTION  
 *  sml_Remove
 * DESCRIPTION
 *  This function is used to remove the desired category
 * PARAMETERS
 *  IN          cat
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Remove( sml_cat_enum cat, kal_uint8 source )
{

    nvram_ef_sml_obj_struct * p = &pSMLg[source];

    sml_category_meta_struct * meta = NULL;

    sml_control_key_struct * catkey = NULL;

    kal_uint8 * pdata = NULL;

    kal_uint16 length = 0; 

    kal_bool result = KAL_FALSE;
    
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source);
    pdata = (kal_uint8 *) (*p->getItem)(cat,SML_CAT_CODE,&length, source);

    if( SML_STATE_UNLOCK == meta->state )
    {

        kal_mem_set(pdata,0xFF,length);

        if( SML_KEY_EMPTY == catkey->state )
        {

            kal_mem_set(catkey->key,0xFF,SML_MAX_SUPPORT_KEY_LEN);
            
        }

        meta->num = 0;

        result = KAL_TRUE;

    }
    
    return result;
    
}
 
/*******************************************************************************
 * FUNCTION  
 *  sml_Disable
 * DESCRIPTION
 *  This function is used to disable the desired category
 * PARAMETERS
 *  IN          cat
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Disable( sml_cat_enum cat, kal_uint8 source )
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    sml_category_meta_struct *meta = NULL;

    kal_uint16 length = 0; 

    kal_bool result = KAL_FALSE;
    
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
 
    if( SML_STATE_UNLOCK == meta->state )
    {
    
        meta->state = SML_STATE_DISABLE;

        result = KAL_TRUE;
        
    }
    
    return result;

}
 
/*******************************************************************************
 * FUNCTION  
 *  sml_Reset
 * DESCRIPTION
 *  This function is used to reset the retry counter
 * PARAMETERS
 *  IN          cat
 *  IN          * key
 *  IN          key_len
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Reset( sml_cat_enum cat, 
                    kal_uint8 *key, 
                    kal_uint8 key_len,
                    kal_uint8 source)
{
    kal_bool result = KAL_FALSE;
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
#endif
    return result;
    
}

/*******************************************************************************
 * FUNCTION  
 *  sml_Status
 * DESCRIPTION
 *  This function is used to query the status of the category
 * PARAMETERS
 *  IN          cat
 *  OUT         *state 
 *  OUT         *retry_count
 *  OUT         *num_of_sets
 *  OUT         *space_of_sets
 *  OUT         *key_state
 *  OUT         *auto_lock_count
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
void sml_Status( sml_cat_enum cat, 
                 kal_uint8 *state,
                 kal_uint8 *retry_count,
                 kal_uint8 *num_of_sets,
                 kal_uint8 *space_of_sets,
                 kal_uint8 *key_state,
                 kal_uint8 *auto_lock_count,
                 kal_uint8 source)
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

//    kal_uint8 *pdata = NULL;

    kal_uint16 length = 0, offset = 0; 
   
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 
    (*p->getItem)(cat,SML_CAT_CODE,&length, source); //to get the code length for later use

    if(state)
        *state = meta->state;
    
    if(retry_count)
        *retry_count = meta->retry_count;
    
    if(num_of_sets)
        *num_of_sets = meta->num;
    
    if(key_state)
        *key_state = catkey->state;

    if(auto_lock_count)
        *auto_lock_count = meta->autolock_count;

    if(space_of_sets)
    {
        switch(cat)
        {
        
            case SML_CAT_N:

            offset = (meta->num) * SML_SIZE_OF_CAT_N;
            
            *space_of_sets = (length - offset) / SML_SIZE_OF_CAT_N;
                    
            break;
        
            case SML_CAT_NS:

            offset = (meta->num) * SML_SIZE_OF_CAT_NS;        

            *space_of_sets  = (length - offset) / SML_SIZE_OF_CAT_NS;        
            
            break;
        
            case SML_CAT_SP:
            
            offset = (meta->num) * SML_SIZE_OF_CAT_SP;        

            *space_of_sets  = (length - offset) / SML_SIZE_OF_CAT_SP;        
            
            break;

            case SML_CAT_C:
                        
            offset = (meta->num) * SML_SIZE_OF_CAT_C;   

            *space_of_sets  = (length - offset) / SML_SIZE_OF_CAT_C;                
            
            break;
        
            case SML_CAT_SIM:
           
            offset = (meta->num) * SML_SIZE_OF_CAT_SIM;  

            *space_of_sets  = (length - offset) / SML_SIZE_OF_CAT_SIM;               
            
            break;
        
            case SML_CAT_NS_SP:

            offset = (meta->num) * SML_SIZE_OF_LINK_NS_SP;   

            *space_of_sets  = (length - offset) / SML_SIZE_OF_LINK_NS_SP;                    
            
            break;
        
            case SML_CAT_SIM_C:
                        
            offset = (meta->num) * SML_SIZE_OF_LINK_SIM_C;   

            *space_of_sets  = (length - offset) / SML_SIZE_OF_LINK_SIM_C;                
            
            break;    
        
            default:
            
            break; 
            
        }         
    }

}

/*******************************************************************************
 * FUNCTION  
 *  sml_Autolock
 * DESCRIPTION
 *  This function is used to autolock the desired category
 * PARAMETERS
 *  IN          cat
 *  IN          *code
 *  IN          len
 *  OUT          *remain
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Autolock( sml_cat_enum cat, 
                       kal_uint8 *code,
                       kal_uint8 len,
                       kal_uint8 *remain,
                       kal_uint8 source)
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    sml_category_meta_struct *meta = NULL;

    kal_uint8 *pdata = NULL;

    kal_uint16 length = 0, offset = 0; 

    kal_bool result = KAL_FALSE;
    
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    pdata = (kal_uint8 *) (*p->getItem)(cat,SML_CAT_CODE,&length, source);

    if((meta->state != SML_STATE_AUTOLOCK)||
       (meta->autolock_count == 0))
    {
    
        *remain = 0;

        return KAL_FALSE;

    }
    
    switch(cat)
    {
        
        case SML_CAT_N:

            if(SML_SIZE_OF_CAT_N == len)
            {
            
                offset = (meta->num) * SML_SIZE_OF_CAT_N;
            
                *remain = (length - offset) / SML_SIZE_OF_CAT_N;

                result = KAL_TRUE;

            }
                    
        break;
        
        case SML_CAT_NS:

            if(SML_SIZE_OF_CAT_NS == len)
            {
                
                offset = (meta->num) * SML_SIZE_OF_CAT_NS;        

                *remain = (length - offset) / SML_SIZE_OF_CAT_NS;    

                result = KAL_TRUE;

            }
            
        break;
        
        case SML_CAT_SP:
            
            if(SML_SIZE_OF_CAT_SP == len)
            {

                offset = (meta->num) * SML_SIZE_OF_CAT_SP;        

                *remain = (length - offset) / SML_SIZE_OF_CAT_SP;        
            
                result = KAL_TRUE;

            }

        break;

        case SML_CAT_C:

            if(SML_SIZE_OF_CAT_C == len)
            {
            
                offset = (meta->num) * SML_SIZE_OF_CAT_C;   

                *remain = (length - offset) / SML_SIZE_OF_CAT_C;                

                result = KAL_TRUE;

            }

        break;
        
        case SML_CAT_SIM:

           if(SML_SIZE_OF_CAT_SIM == len)
           {

                offset = (meta->num) * SML_SIZE_OF_CAT_SIM;  

                *remain = (length - offset) / SML_SIZE_OF_CAT_SIM; 
                
                result = KAL_TRUE;
           }            

        break;
        
        case SML_CAT_NS_SP:

            if(SML_SIZE_OF_LINK_NS_SP == len)
            {

                offset = (meta->num) * SML_SIZE_OF_LINK_NS_SP;   

                *remain = (length - offset) / SML_SIZE_OF_LINK_NS_SP; 

                result = KAL_TRUE;
                
            }
            
        break;
        
        case SML_CAT_SIM_C:
            
            if(SML_SIZE_OF_LINK_SIM_C == len)
            {

                offset = (meta->num) * SML_SIZE_OF_LINK_SIM_C;   

                *remain = (length - offset) / SML_SIZE_OF_LINK_SIM_C;  
                
                result = KAL_TRUE;

            }
            
        break;    
        
        default:
            
        break;
        
    }           

    if(result == KAL_FALSE)
    {

        *remain = meta->autolock_count;
        
        return KAL_FALSE;
        
    }
    
    /* Check if the space is available */
    if(*remain > 0)
    {

        kal_mem_cpy((kal_uint8 *)(pdata+offset),
                    code,
                    len
                    );
        
        meta->num ++;

        meta->autolock_count--;

        if(meta->autolock_count == 0)
        {

            meta->state = SML_STATE_LOCK;

            kal_sys_trace("SML: Autolock finished!");

        }

        *remain = meta->autolock_count;

        result = KAL_TRUE;
        
    }
    else
    {

        kal_sys_trace("SML: Autolock fail! Clean remain count!");

        meta->autolock_count = 0;
        
        meta->state = SML_STATE_LOCK;

        result = KAL_TRUE;
        
    }
    
    return result;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_Check
 * DESCRIPTION
 *  This function is used to check if the code is in the Pass list
 * PARAMETERS
 *  IN          cat
 *  IN          *imsi
 *  IN          *gid1
 *  IN          *gid2
 *  IN          num_cnl
 *  IN          *cnl
 *  IN          *dck
 *  IN          sim_mnc_len
 *  IN          *remain
 *  IN          source
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Check( sml_cat_enum cat,       // category
                    kal_uint8 *imsi,        // 9 bytes array, read from SIM, mandatory file
                    kal_uint8 *gid1,        // 20 bytes array, read from SIM, NULL means gid1 invalid(file not exist)
                    kal_uint8 *gid2,        // 20 bytes array, read from SIM, NULL means gid2 invalid(file not exist)
                    kal_uint16 num_cnl,     // How many bytes of cnl, read from SIM, 0 means cnl invalid(file not exist)
                    kal_uint8 *cnl,         // 240 bytes array, length is depend on num_cnl, read from SIM
                    kal_uint8 *dck,         // 4 bytes array, read from SIM, NULL means dck invalid(file not exist)
                    kal_uint8 sim_mnc_len,  // MNC length, read from SIM
                    kal_uint8 *remain,      // remain retry count
                    kal_uint8 source)       // 0:SIM1, 1:SIM2
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];
    sml_category_meta_struct *meta = NULL;
    kal_uint8 *pdata = NULL;
    kal_uint8 idx = 0;
    kal_uint16 length = 0, offset = 0; 
    kal_bool result = KAL_FALSE;
    kal_uint8 code_len = 0;
    kal_uint8 code[10] = {0xFF};
    kal_uint8 size_of_cat = 0;
    
    meta = (sml_category_meta_struct *) (*p->getItem)(cat, SML_CAT_META, &length, source);
    pdata = (kal_uint8 *) (*p->getItem)(cat, SML_CAT_CODE, &length, source);

    *remain = meta->retry_count;

    if (SML_STATE_LOCK != meta->state)
    {
        /* ALWAYS PASSED if the category is not locked! */
        return KAL_TRUE;
    }
    
    switch(cat)
    {
        case SML_CAT_N:
        {
            size_of_cat = SML_SIZE_OF_CAT_N;
            break;
        }
        case SML_CAT_NS:
        {
            size_of_cat = SML_SIZE_OF_CAT_NS;
            break;
        }
        case SML_CAT_SP:
        {
            size_of_cat = SML_SIZE_OF_CAT_SP;
            break;
        }
        case SML_CAT_C:
        {
            size_of_cat = SML_SIZE_OF_CAT_C;
            break;
        }
        case SML_CAT_SIM:
        {
            size_of_cat = SML_SIZE_OF_CAT_SIM;
            break;
        }
        case SML_CAT_NS_SP:
        {
            size_of_cat = SML_SIZE_OF_LINK_NS_SP;
            break;
        }
        case SML_CAT_SIM_C:
        {
            size_of_cat = SML_SIZE_OF_LINK_SIM_C;
            break;
        }
        default:
            break;
    }           

    for (idx = 0; idx < meta->num; idx++)
    {
        offset = idx * size_of_cat;
        code_len = sml_GetCode(cat,
                               imsi,
                               gid1,
                               gid2,
                               sim_mnc_len, 
                               (pdata+offset),
                               code);
        
        if (size_of_cat == code_len)
        {
            if (kal_mem_cmp(code, (pdata+offset), code_len)==0)
            {
                result = KAL_TRUE;
                break;
            }
        }
    }
    
    return result;
}

/*******************************************************************************
 * FUNCTION  
 *  sml_Catcode
 * DESCRIPTION
 *  This function is used to compose the code of each category
 * PARAMETERS
 *  IN          cat
 *  IN          *imsi
 *  IN          *gid1
 *  IN          *gid2
 *  IN          mnc_len
 *  OUT          *code
 * RETURN
 *  kal_uint8   code length
 * GLOBALS AFFECTED
 *  NONE
 *******************************************************************************/ 
kal_uint8 sml_Catcode( sml_cat_enum cat,
                       kal_uint8 *imsi,
                       kal_uint8 *gid1,
                       kal_uint8 *gid2,
                       kal_uint8 mnc_len,
                       kal_uint8 *code )
{

    if(mnc_len == 3)
    {
        code[0] = (imsi[1] & 0xF0) | (imsi[2] & 0x0F);
        code[1] = (imsi[2] & 0xF0) | (imsi[3] & 0x0F);
        code[2] = (imsi[3] & 0xF0) | (imsi[4] & 0x0F);
        code[3] = (imsi[4] & 0xF0) | (imsi[5] & 0x0F);
    }
    else
    {
        code[0] = (imsi[1] & 0xF0) | (imsi[2] & 0x0F);
        code[1] = (imsi[2] & 0xF0) | (imsi[3] & 0x0F);
        code[2] = (imsi[3] & 0xF0) | 0x0F;
        code[3] = ((imsi[4] & 0x0F) << 4) | ((imsi[4] & 0xF0) >> 4);
    }

    switch(cat)
    {
        
        case SML_CAT_N:

            return SML_SIZE_OF_CAT_N;
                    
        break;
        
        case SML_CAT_NS:

            return SML_SIZE_OF_CAT_NS;
            
        break;
        
        case SML_CAT_SP:

            if(gid1)
            {
                code[3] = gid1[0];
                
                return SML_SIZE_OF_CAT_SP;

            }

        break;

        case SML_CAT_C:
            
            if (gid1 && gid2 )
            {
                code[3] = gid1[0];
                code[4] = gid2[0];

                return SML_SIZE_OF_CAT_C;
            }
                               
        break;
        
        case SML_CAT_SIM:

            kal_mem_cpy(code,&(imsi[1]),8);
            
            return SML_SIZE_OF_CAT_SIM;          
            
        break;
        
        case SML_CAT_NS_SP:

            if(gid1)
            {            

                code[4] = gid1[0];

                return SML_SIZE_OF_LINK_NS_SP;

            }  

        break;
        
        case SML_CAT_SIM_C:

            kal_mem_cpy(code,&(imsi[1]),8);

            if(gid1 && gid2)
            {

                code[8] = gid1[0];

                code[9] = gid2[0];
                
                return SML_SIZE_OF_LINK_SIM_C;

            }
                  
        break;    
        
        default:
            
        break;
        
    }           

    return 0;
    
}


/*******************************************************************************
 * FUNCTION
 *  sml_GetCode
 * DESCRIPTION
 *  This function is used to compose the code of each category  whether 
 *  mnc length is 2 or 3
 * PARAMETERS
 *  cat         [IN]    category of the SIM-ME-Lock
 *  imsi        [IN]    imsi of the code source 
 *  gid1        [IN]    gid1 of the code source
 *  gid2        [IN]    gid2 of the code source
 *  sim_mnc_len [IN]    the mnc length decided by SIM
 *  pdata       [IN]    the saved code for comparing
 *  code        [OUT]   the composed code according to all input parameters
 *
 * RETURN
 *  kal_uint16 file size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
kal_uint8 sml_GetCode( sml_cat_enum cat, 
                       kal_uint8 * imsi, 
                       kal_uint8 * gid1, 
                       kal_uint8 * gid2, 
                       kal_uint8 sim_mnc_len, 
                       kal_uint8 * pdata,
                       kal_uint8 * code)
{
    kal_uint8 mnc_len=0;

    if (SML_MNC_LENGTH_NEST == 1)
    {
        mnc_len = sim_mnc_len;
    }
    else
    {
        if(((*(pdata+2)) & 0x0F) == 0x0F)
        {
            mnc_len = 2;
        }
        else
        {
            mnc_len = 3;
        }
    }
    return sml_Catcode(cat, imsi, gid1, gid2, mnc_len, code);
}


/*******************************************************************************
 * FUNCTION  
 *  sml_Process_autolock
 * DESCRIPTION
 *  This function is used process autolock function
 * PARAMETERS
 *  IN          cat
 *  OUT         *state 
 *  OUT         *retry_count
 *  OUT         *num_of_sets
 *  OUT         *space_of_sets
 *  OUT         *key_state
 *  OUT         *auto_lock_count
 * RETURN
 *  kal_bool    result
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Process_autolock( kal_uint8 * imsi,
                               kal_uint8 * gid1,
                               kal_uint8 * gid2,
                               kal_uint8 num_mnc,
                               kal_uint8 * remain_count,
                               kal_uint8 source)
{

    kal_bool result = KAL_FALSE;

    sml_cat_enum cat = SML_CAT_N;

    kal_uint8 code[10] = {0xFF}, len = 0, count = 0;

    kal_mem_set( (kal_uint8 *) &(code[0]), 
                  0xFF, 
                  10 
                  );
    
    *remain_count = 0;

    for(cat = SML_CAT_N; cat < SML_CAT_SIZE; cat++)
    {
        /* Because this is ADD operation, there is no code in NVRAM for sml_GetCode to refer mnc length.
           This function just uses num_mnc from SIM to construct the code
        */
        len = sml_Catcode( cat,
                           imsi,
                           gid1, 
                           gid2, 
                           num_mnc, 
                           code );

        if(KAL_TRUE == sml_Autolock( cat, 
                                     code, 
                                     len, 
                                     &count,
                                     source
                                     ))
        {

            result = KAL_TRUE;

        }

        if(count > *remain_count)
        {
        
            *remain_count = count; 

        }
            
    }

    return result;
    
}

/*******************************************************************************
 * FUNCTION  
 *  sml_Is_autolock
 * DESCRIPTION
 *  This function is used to query if there is autolock shall be processed
 * PARAMETERS
 *  void
 * RETURN
 *  kal_uint8    result
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_uint8 sml_Is_autolock(kal_uint8 *imsi, kal_uint8 source )
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];

    sml_category_meta_struct *meta = NULL;

    sml_cat_enum cat = SML_CAT_N;

    kal_uint16 length = 0;

    kal_uint8 result = 0;

    for(cat = SML_CAT_N; cat < SML_CAT_SIZE; cat++)
    {
        meta = (sml_category_meta_struct *) (*p->getItem)(cat,
                                                          SML_CAT_META,
                                                          &length,
                                                          source);

        if(meta->state == SML_STATE_AUTOLOCK)
        {
            result++;
        }
    }

    return result;    
}

/*******************************************************************************
 * FUNCTION  
 *  sml_Verify
 * DESCRIPTION
 *  This function is used to verify the SML lock keys
 * PARAMETERS
 *  void
 * RETURN
 *  kal_bool    result
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Verify( sml_cat_enum cat,
                      kal_uint8 * key,
                      kal_uint8 len,
                      kal_uint8 * retry_count,
                      kal_uint8 source)
{

    nvram_ef_sml_obj_struct *p = &pSMLg[source];
    
    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_bool result = KAL_FALSE;

    kal_uint16 length = 0;

    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 

    if(kal_mem_cmp(catkey->key,key,len)==0)
    {

        result = KAL_TRUE;
        
        switch(cat)
        {
            
            case SML_CAT_N:
            
                meta->retry_count = SML_RETRY_COUNT_N_CAT;
                
            break;
            case SML_CAT_NS:
        
                meta->retry_count = SML_RETRY_COUNT_NS_CAT;                    
                
            break;
            case SML_CAT_SP:
                
                meta->retry_count = SML_RETRY_COUNT_SP_CAT;
                
            break;
            case SML_CAT_C:
                
                meta->retry_count = SML_RETRY_COUNT_C_CAT;                    
                
            break;
            case SML_CAT_SIM:
               
                meta->retry_count = SML_RETRY_COUNT_SIM_CAT;     
                
            break;
            case SML_CAT_NS_SP:
                
                meta->retry_count = SML_RETRY_COUNT_NS_CAT;
                
            break;
            case SML_CAT_SIM_C:
                
                meta->retry_count = SML_RETRY_COUNT_SIM_CAT;
                
            break;    
            default:
            break;
            
        }           

    }
    else
    {

        meta->retry_count--;

        result = KAL_FALSE;
        
    }

    *retry_count = meta->retry_count;
    
    return result;
    
}

/* END: PH sml_context_struct (NVRAM_EF_SML_LID) */

/*******************************************************************************
 * FUNCTION  
 *  sml_Testsim_op_mode
 * DESCRIPTION
 *  This function is used to query the testsim handling rule
 * PARAMETERS
 *  void
 * RETURN
 *  SML_TESTSIM_ALW_REJECT  0
 *  SML_TESTSIM_ALW_ALLOW   1
 *  SML_TESTSIM_INI_ALLOW   2
 * GLOBALS AFFECTED
 *  NONE
 *******************************************************************************/ 
kal_uint8 sml_Testsim_op_mode(void)
{

    return SML_TESTSIM_OP_MODE;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_is_Masterkey_enable
 * DESCRIPTION
 *  This function is used to query the Masterkey handling rule
 * PARAMETERS
 *  void
 * RETURN
 * kal_bool
 * GLOBALS AFFECTED
 *  NONE
 *******************************************************************************/ 

kal_bool sml_is_Masterkey_enable(void)
{

    return SML_MASTER_KEY_ENABLE;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_Verify_OTA
 * DESCRIPTION
 *  This function is used to process OTA
 * PARAMETERS
 *  void
 * RETURN
 *  kal_bool    result
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_bool sml_Verify_OTA( sml_cat_enum cat,
                          kal_uint8 * key,
                          kal_uint8 len,
                          kal_uint8 source)
{
    nvram_ef_sml_obj_struct *p = &pSMLg[source];
    
    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_bool result = KAL_FALSE;

    kal_uint16 length = 0;

    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 

    if(kal_mem_cmp(catkey->key,key,len)==0)
    {

        result = KAL_TRUE;

        if(SML_STATE_LOCK == meta->state)
            meta->state = SML_STATE_UNLOCK;
        
        switch(cat)
        {
            
            case SML_CAT_N:
            
                meta->retry_count = SML_RETRY_COUNT_N_CAT;
                
            break;
            case SML_CAT_NS:
        
                meta->retry_count = SML_RETRY_COUNT_NS_CAT;                    
                
            break;
            case SML_CAT_SP:
                
                meta->retry_count = SML_RETRY_COUNT_SP_CAT;
                
            break;
            case SML_CAT_C:
                
                meta->retry_count = SML_RETRY_COUNT_C_CAT;                    
                
            break;
            case SML_CAT_SIM:
               
                meta->retry_count = SML_RETRY_COUNT_SIM_CAT;     
                
            break;
            case SML_CAT_NS_SP:
                
                meta->retry_count = SML_RETRY_COUNT_NS_CAT;
                
            break;
            case SML_CAT_SIM_C:
                
                meta->retry_count = SML_RETRY_COUNT_SIM_CAT;
                
            break;    
            default:
            break;
            
        }           

    }
    else
    {

        result = KAL_FALSE;
        
    }
    
    return result;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_CheckVisa
 * DESCRIPTION
 *  This function is used to handle special Block SIM cards 
 * PARAMETERS
 *  IN          *imsi
 *  IN          mnc_len
 * RETURN
 *  kal_bool  
 * GLOBALS AFFECTED
 *  NONE
 *******************************************************************************/ 
kal_bool sml_CheckVisa(const kal_uint8 * imsi, kal_uint8 mnc_len)
{

    const kal_uint8 *  code_ptr = &(smlVISA[0]);

    kal_uint8 code[3] = {0};
    

    code[0] = (imsi[1] & 0xF0) | (imsi[2] & 0x0F);

    code[1] = (imsi[2] & 0xF0) | (imsi[3] & 0x0F);

    if(3 == mnc_len)
    {

        code[2] = (imsi[3] & 0xF0) | (imsi[4] & 0x0F);

    }
    else
    {
    
        code[2] = (imsi[3] & 0xF0) | 0x0F;

    }

    while(0xFF != *code_ptr) /* Break if first byte is 0xFF */
    {

        if(0==kal_mem_cmp(code_ptr,code,3))
        {
            
            return KAL_TRUE;
            
        }

        code_ptr += 3;

    }

    return KAL_FALSE;


}


/*[MAUI_01634719] mtk01612: common API to query state*/
kal_uint8 sml_query_state( sml_cat_enum cat, kal_uint8 source)
{
    nvram_ef_sml_obj_struct *p = pSMLg;
	
    sml_category_meta_struct *meta = NULL;

//    sml_control_key_struct *catkey = NULL;

    kal_uint16 length = 0;	

    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
//    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 

    return meta->state;
}

#ifdef __CHANGE_SML_KEY__
extern kal_bool sml_ChangePW(sml_cat_enum cat,
                              kal_uint8 * lock_count,
	                    kal_uint8 *key1,
	                    kal_uint8 *key2,
	                    kal_uint8 len,
	                    kal_uint8 source)
{
        nvram_ef_sml_obj_struct *p = &pSMLg[source];
        sml_category_meta_struct * meta = NULL;
        sml_control_key_struct * catkey = NULL;
        kal_uint8 * pdata = NULL;
        kal_uint16 length = 0;
        kal_bool result = KAL_FALSE;

        meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
        catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source);

       if(meta->retry_count>0 && SML_KEY_SET==catkey->state && SML_STATE_UNLOCK ==meta->state)
       {
             if(kal_mem_cmp(&(catkey->key[0]),key1,len))
        {

            meta->retry_count--;
        }
        else
        {
            result = KAL_TRUE;
	   kal_mem_cpy(catkey->key,key2,len);//change key

            switch(cat)
            {

                case SML_CAT_N:

                    meta->retry_count = SML_RETRY_COUNT_N_CAT;

                break;
                case SML_CAT_NS:

                    meta->retry_count = SML_RETRY_COUNT_NS_CAT;

                break;
                case SML_CAT_SP:

                    meta->retry_count = SML_RETRY_COUNT_SP_CAT;

                break;
                case SML_CAT_C:

                    meta->retry_count = SML_RETRY_COUNT_C_CAT;

                break;
                case SML_CAT_SIM:

                    meta->retry_count = SML_RETRY_COUNT_SIM_CAT;

                break;
                case SML_CAT_NS_SP:

                    meta->retry_count = SML_RETRY_COUNT_NS_CAT;

                break;
                case SML_CAT_SIM_C:

                    meta->retry_count = SML_RETRY_COUNT_SIM_CAT;

                break;
                default:
                break;
            }
         	 }
        }
	
        *lock_count  = meta->retry_count;
        return result;
}
#endif


#endif /* __SIM_ME_LOCK__ */ 

#endif /* !defined(__MAUI_BASIC__) */ 
