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
 * ephy_rf_custom_func.c
 *
 * Project:
 * --------
 * MT6290
 *
 * Description:
 * ------------
 * EL1 RF Custom Function
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*===============================================================================*/

#include "kal_general_types.h"
#include "kal_public_api.h"

#include "el1_rf_public.h"
#include "el1_rf_common.h"
#include "ephy_rf_custom_data.h"

extern ERF_SPLIT_BAND_IND_T LTE_SPLIT_BAND_IND[LTE_ERF_SPLIT_BAND];
/*===============================================================================*/

kal_bool EPHY_RF_CHECK_WIFI_COEXISTENCE_BAND(LTE_Band lteBand)
{
   
   kal_bool pt2_band_match = KAL_FALSE;
   kal_uint32 i, lte_pdata_bypass_pt2[LTE_MIPI_BYPASS_MAX_SUPPORT_BAND_NUM] = {0};
   PDATA_SET_T *bypass_pt2;
   
   for (i=0; i<LTE_ERF_SPLIT_BAND;i++)
   {
      bypass_pt2 = &ERF_SPLIT_RFDATABASE[i*LTE_ERF_SPLIT_TABLE_SIZE+2].SplitRFdata.pt2;
      lte_pdata_bypass_pt2[i] = bypass_pt2->data_L;
      lte_pdata_bypass_pt2[i] |= (bypass_pt2->data_h)<<16;
   }
   
   for (i=0; i<LTE_ERF_SPLIT_BAND;i++)
   {   
      pt2_band_match = (pt2_band_match) || ((lteBand==LTE_SPLIT_BAND_IND[i].Band)&&(lte_pdata_bypass_pt2[i]!=0));
   }
   

   if((lteBand!=LTE_BandNone) && (pt2_band_match))
   {
      return KAL_TRUE;
   }
   /*** MIPI BYPASS Feature ***/
   else if ((lteBand!=LTE_BandNone) && (LTE_MIPI_BYPASS_FEATURE_ENABLE == 1))
   {
      for (i=0 ; i<LTE_MIPI_BYPASS_MAX_SUPPORT_BAND_NUM ; i++)
      {
         if (lteBand == LTE_MIPI_BYPASS_BandIndArray[i])
     	    { return KAL_TRUE; }
      }

      return KAL_FALSE;
   }
   else
   {
      return KAL_FALSE;
   }
}
