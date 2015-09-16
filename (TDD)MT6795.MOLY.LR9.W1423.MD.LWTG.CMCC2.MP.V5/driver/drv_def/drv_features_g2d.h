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
 *    drv_features_g2d.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for all graphics driver feature options.
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
#ifndef __DRV_FEATURES_G2D_H__
#define __DRV_FEATURES_G2D_H__

#define SW_G2D_LT_PERFORMANCE_VERSION

#if defined(G2D_CODEC_STANDALONE)
   ///#define __DRV_GRAPHICS_G2D_6276_SERIES__
   #define __DRV_GRAPHICS_G2D_6236_SERIES__
#elif defined(G2D_FPGA)

#else
   #include "drv_features_chip_select.h"
#endif

#if defined(__DRV_GRAPHICS_G2D_6276_SERIES__)
   #if defined(MT6276_S00)
      #if (defined(__MTK_TARGET__) && defined(IC_BURNIN_TEST))
      #else
        #undef __DRV_GRAPHICS_G2D_6276_SERIES__
      #endif
   #endif
#endif 

#if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24)
   #define SW_G2D_LT_SUPPORT_WITH_SRC_RGB888
   #define SW_G2D_LT_SUPPORT_WITH_DST_RGB888
#endif

#if (defined(__DRV_GRAPHICS_G2D_6235_SERIES__) || defined(__DRV_GRAPHICS_G2D_6268_SERIES__))

   #if defined(__MTK_TARGET__)
      /// Target
      #define G2D_HW_SUPPORT
      #define G2D_HW_FONT_SUPPORT
      #define G2D_HW_TILT_FONT_SUPPORT
      #define G2D_HW_BITBLT_SUPPORT
      #define G2D_HW_RECT_FILL_SUPPORT
   #endif
#endif

#if defined(__DRV_GRAPHICS_G2D_6236_SERIES__)

   #define G2D_HW_SUPPORT
   #define G2D_HW_LT_SUPPORT

   #if defined(__MTK_TARGET__)
      /// Target
      #define G2D_HW_FONT_SUPPORT
      #define G2D_HW_TILT_FONT_SUPPORT
      #define G2D_HW_BITBLT_SUPPORT
      #define G2D_HW_RECT_FILL_SUPPORT

   #else
      #define G2D_HW_LT_C_MODEL_SUPPORT
   #endif
#endif

#if (defined(__DRV_GRAPHICS_G2D_6276_SERIES__))

   #define G2D_HW_SUPPORT
   #define G2D_HW_FONT_SUPPORT
   #define G2D_HW_AA_FONT_SUPPORT
   #define G2D_HW_BITBLT_SUPPORT
   #define G2D_HW_RECT_FILL_SUPPORT
   ///#define G2D_HW_SAD_SUPPORT
   #define G2D_HW_OVERLAY_SUPPORT
   #define G2D_HW_OVERLAY_TOTAL_LAYER   4

   #if defined(G2D_CODEC_STANDALONE)
      #define G2D_HW_LT_SUPPORT
      #define G2D_HW_LT_WITH_ALPHA_BLENDING_SUPPORT
      
      #define G2D_HW_C_MODEL_SUPPORT
      #define G2D_HW_LT_C_MODEL_SUPPORT
      
   #elif defined(__MTK_TARGET__)
      /// Target
      #define G2D_HW_LT_SUPPORT
      #define G2D_HW_LT_WITH_ALPHA_BLENDING_SUPPORT
   #else
      /// MODIS
      #define G2D_HW_C_MODEL_SUPPORT
      ///#define G2D_HW_LT_C_MODEL_SUPPORT
   #endif
#endif

#if (defined(__DRV_GRAPHICS_G2D_6255_SERIES__))

   #define G2D_HW_SUPPORT
   #define G2D_HW_FONT_SUPPORT
   #define G2D_HW_AA_FONT_SUPPORT
   #define G2D_HW_BITBLT_SUPPORT
   #define G2D_HW_RECT_FILL_SUPPORT
   ///#define G2D_HW_SAD_SUPPORT
   #define G2D_HW_OVERLAY_SUPPORT
   #define G2D_HW_OVERLAY_TOTAL_LAYER   4

   #define G2D_HW_SHARE_WITH_GOVL_SUPPORT

   #if defined(__MTK_TARGET__) || defined(G2D_FPGA)
      /// Target
      #define G2D_HW_LT_SUPPORT
      #define G2D_HW_LT_WITH_ALPHA_BLENDING_SUPPORT
   #else
      /// MODIS
      #define G2D_HW_C_MODEL_SUPPORT
      ///#define G2D_HW_LT_C_MODEL_SUPPORT
   #endif
#endif


#if defined(__MTK_TARGET__)
   #include "drv_features_mdp.h"
      
   #ifdef DRV_RGB_RESIZE_SUPPORT
      #if defined(MT6236) || defined(MT6236B)
         /// HW bug, Can not use resizer
      #else
         #define G2D_USING_HW_RESIZER
      #endif
   #endif

#endif
 
#endif /// __DRV_FEATURES_G2D_H__

