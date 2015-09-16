/******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
*******************************************************************************/

/******************************************************************************
 * Filename:
 * ---------
 *   mrs_mm_capability.h
 *
 * Project:
 * --------
 *   Multimode
 *
 * Description:
 * ------------
 *   The MM capability stored in MRS context.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *===========================================================================
 * $Log:$
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * .
 * 
 *===========================================================================
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *
 *****************************************************************************/

#ifndef _MRS_MM_CAPABILITY_H
#define _MRS_MM_CAPABILITY_H

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "mrs_as_enums.h"
#include "mcd_l3_inc_struct.h"

/*****************************************************************************
 * Macros Without Parameters
 *****************************************************************************/

/*****************************************************************************
 * Macros With Parameters
 *****************************************************************************/


/*****************************************************************************
 * Enums without tags
 *****************************************************************************/



/*****************************************************************************
 * Type Definitions
 *****************************************************************************/
typedef struct {

    kal_bool isr_support;
    kal_bool epc_capability;
    kal_bool inject_ms_nw_cap_disable_lte_bit;
    kal_uint8 speech_version;              /*first byte for GSM supported speech codec*/
    kal_uint8 speech_version_byte2;        /*second byte for GSM supported speech codec*/
    kal_uint8 umts_supported_speech;       /*first byte for UMTS supported speech codec*/
    kal_uint8 umts_supported_speech_byte2; /*second byte for UMTS supported speech codec*/

} mm_capability_context_struct;


/*****************************************************************************
 * Declarations Of Exported Globals
 *****************************************************************************/
void mrs_mm_init_contx_default_value(void);
void mrs_mm_get_ms_nw_cap(MRS_SIM_INDEX sim_index, rat_enum rat_mode, rat_enum current_rat, kal_uint8 *data, kal_uint8 *len);
kal_uint8 mrs_mm_get_gea_supported(MRS_SIM_INDEX sim_index);
void mrs_mm_read_nvram_cnf_handler(kal_uint16 nvram_file_id, kal_uint8* data, kal_uint16 len);
void mrs_mm_get_supported_codec_list(MRS_SIM_INDEX sim_index, rat_enum rat_mode, plmn_id_struct *plmn_id, kal_uint8 *data, kal_uint8 *len);

#ifdef __LTE_RAT__
void mrs_mm_set_isr_support(MRS_SIM_INDEX sim_index, kal_bool is_isr);
kal_bool mrs_mm_get_isr_support(MRS_SIM_INDEX sim_index);
void mrs_mm_set_epc_cap(MRS_SIM_INDEX sim_index, kal_bool is_epc);
#endif

#endif /* _MRS_MM_CAPABILITY_H */

