/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *
 * Filename:
 * ---------
 * custom_flc_config.c
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   This file is used to define the FLC2 configuration.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_general_types.h"
#include "custom_flc_config.h"

#if (defined(__USB_TETHERING__) || (defined(__WIFI_SUPPORT__) || defined(__RLC_HSDPA_COPRO__))) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
/* If this option is on, URLC will use L2-accelator for DL */
//#pragma arm section zidata = "DYNAMICCACHEABLEZI_C", rwdata = "DYNAMICCACHEABLERW_C" 
__attribute__ ((zero_init, section ("DYNAMICCACHEABLEZI_C"))) kal_uint32 flc2_mm_block_12_g[FLC2_MM_BLOCK_12_SIZE/4];

#else
kal_uint32 flc2_mm_block_12_g[FLC2_MM_BLOCK_12_SIZE/4];
#endif

#if (defined(__USB_TETHERING__) || (defined(__WIFI_SUPPORT__) || (defined(__L2_HSUPA_COPRO__) && defined(__HSUPA_SUPPORT__)))) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
/* If these two options are on, URLC will use L2-accelator for UL */
//#pragma arm section zidata = "DYNAMICCACHEABLEZI_C", rwdata = "DYNAMICCACHEABLERW_C" 
__attribute__ ((zero_init, section ("DYNAMICCACHEABLEZI_C"))) kal_uint32 flc2_mm_block_11_g[FLC2_MM_BLOCK_11_SIZE/4];

#else
kal_uint32 flc2_mm_block_11_g[FLC2_MM_BLOCK_11_SIZE/4];
#endif




/*****************************************************************************
 * FUNCTION
 *  flc_get_profile_info_spdu_ul
 * DESCRIPTION
 *  This function is used to define the FLC2_PROFILE_INDEX_SPDU_UL pool info for SPDU_UL
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 flc_get_profile_info_spdu_ul(kal_uint32 *total_size_em_mode, kal_uint32 *max_grow_size)
{
    if(total_size_em_mode != NULL)
        *total_size_em_mode = FLC2_SPDU_UL_SIZE_EM;

    if(max_grow_size != NULL)
        *max_grow_size = FLC2_SPDU_UL_MAX_GROW_SIZE;

    return FLC2_SPDU_UL_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  flc_get_profile_info_spdu_dl
 * DESCRIPTION
 *  This function is used to define the FLC2_PROFILE_INDEX_SPDU_DL pool info for SPDU_DL
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 flc_get_profile_info_spdu_dl(kal_uint32 *max_grow_size)
{
    if(max_grow_size != NULL)
        *max_grow_size = 0;

    return FLC2_SPDU_DL_POOL_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  flc_get_profile_info_tpdu
 * DESCRIPTION
 *  This function is used to define the FLC2_PROFILE_INDEX_TPDU pool info for TPDU
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 flc_get_profile_info_tpdu(kal_uint32 *max_grow_size)
{
    if(max_grow_size != NULL)
        *max_grow_size = 0;

    return FLC2_TPDU_POOL_SIZE;
}




/*****************************************************************************
 * FUNCTION
 *  flc_get_mb_info_index_11
 * DESCRIPTION
 *  This function is used to define the FLC2_MB_INDEX_11 info for SPDU_UL
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32*
 *****************************************************************************/
kal_uint32* flc_get_mb_info_index_11(kal_uint32 *total_size, kal_uint32 *max_grow_size)
{
    if(total_size != NULL)
        *total_size = FLC2_MM_BLOCK_11_SIZE ;

    if(max_grow_size != NULL)
    {
        *max_grow_size = FLC2_MAX(FLC2_SPDU_UL_GROW_POOL_SIZE, FLC2_HS_POOL_MAX_GROW_SIZE);
    }

    return flc2_mm_block_11_g;
}


/*****************************************************************************
 * FUNCTION
 *  flc_get_mb_info_index_12
 * DESCRIPTION
 *  This function is used to define the FLC2_MB_INDEX_12 info for SPDU_DL
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
kal_uint32* flc_get_mb_info_index_12(kal_uint32 *total_size, kal_uint32 *max_grow_size)
{
    if(total_size != NULL)
        *total_size = FLC2_MM_BLOCK_12_SIZE ;

    if(max_grow_size != NULL)
        *max_grow_size = 0 ;

    return flc2_mm_block_12_g;
}

kal_bool flc2_get_spdu_info(kal_uint8 dir,
                            kal_uint32 *pdu_block_size,
                            kal_uint32 *pdu_total_size)
{

#ifdef __TCPIP__
   if(dir == GPRS_FLC_UL)
   {
       /* SSPDU */
       if(pdu_block_size !=NULL)
           *pdu_block_size = FLC2_SPDU_UL_SIZE;

       if(pdu_total_size !=NULL)
           *pdu_total_size = FLC2_SPDU_UL_GROW_POOL_SIZE ;

       return KAL_TRUE;
   }
   else if(dir == GPRS_FLC_DL)
   {
       /* SRPDU */
       if(pdu_block_size !=NULL)
           *pdu_block_size = FLC2_SPDU_UL_SIZE;

       if(pdu_total_size !=NULL)
           *pdu_total_size = FLC2_SPDU_DL_POOL_SIZE;

       return KAL_TRUE;
   }
#endif

   return KAL_FALSE;
}

