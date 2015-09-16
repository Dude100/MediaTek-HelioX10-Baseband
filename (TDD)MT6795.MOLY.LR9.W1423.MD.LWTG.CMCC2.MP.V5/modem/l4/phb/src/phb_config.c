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
 * phb_config.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_CONFIG_C_

//#include "kal_release.h"        /* Basic data type */

//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "app_ltlcom.h" /* Task message communiction */

//#include "sim_common_enums.h"
// #include "nvram_editor_data_item.h"
//#include "custom_nvram_editor_data_item.h"

//#include "l4_common.h"
//#include "ps2sim_struct.h"

//#include "l4c2phb_enums.h"
//#include "l4c2phb_struct.h"

#include "phb_defs.h"
#include "phb_config.h"
//#include "phb_data_desc.h"
//#include "phb_data_entry_table.h"
//#include "phb_pindex.h"
//#include "phb_name_num_index.h"
//#include "nvram_data_items.h"

#include "kal_general_types.h"

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __USIM_SUPPORT__
/* under construction !*/
/* under construction !*/
#ifdef __PHB_USIM_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __PHB_USIM_SUPPORT__ */ 
#ifdef __PHB_USIM_SYNC__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __PHB_USIM_SYNC__ */
#endif /* __USIM_SUPPORT__*/
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

#if (FREE_BITMAP_NVRAM_PHB_BYTES)
kal_uint8 free_bitmap_NVRAM_PHB[FREE_BITMAP_NVRAM_PHB_BYTES];
#else 
kal_uint8 free_bitmap_NVRAM_PHB[1];
#endif 

/* Since MSISDN is 1 to 1 mapping, and SDN, EXT3 is read only, free-bitmap is not needed, thus saves memory consumption */
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
kal_uint8 free_bitmap_ADN[PHB_SIM_NUM][PHB_MAX_PBR_ENTRIES][FREE_BITMAP_ADN_BYTES];
#else
kal_uint8 free_bitmap_ADN[PHB_SIM_NUM][FREE_BITMAP_ADN_BYTES];
#endif
kal_uint8 free_bitmap_FDN[PHB_SIM_NUM][FREE_BITMAP_FDN_BYTES];
kal_uint8 free_bitmap_BDN[PHB_SIM_NUM][FREE_BITMAP_BDN_BYTES];
kal_uint8 free_bitmap_MSISDN[PHB_SIM_NUM][FREE_BITMAP_MSISDN_BYTES];
kal_uint8 free_bitmap_EXT1[PHB_SIM_NUM][FREE_BITMAP_EXT1_BYTES];
kal_uint8 free_bitmap_EXT2[PHB_SIM_NUM][FREE_BITMAP_EXT2_BYTES];
kal_uint8 free_bitmap_EXT4[PHB_SIM_NUM][FREE_BITMAP_EXT4_BYTES];

#ifdef __PHB_USIM_SUPPORT__
kal_uint8 free_bitmap_EXT5[PHB_SIM_NUM][FREE_BITMAP_EXT5_BYTES];
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
kal_uint8 free_bitmap_TYPE2_FILE[PHB_SIM_NUM][PHB_TYPE2_BITMAP_COUNT][FREE_BITMAP_TYPE2_FILE_BYTES];
kal_uint8 free_bitmap_AAS[PHB_SIM_NUM][FREE_BITMAP_AAS_BYTES];
kal_uint8 free_bitmap_GAS[PHB_SIM_NUM][FREE_BITMAP_GAS_BYTES];
#endif 
#endif


