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
 *    drv_features_jpeg.h
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#ifndef __DRV_FEATURES_JPEG_H__
#define __DRV_FEATURES_JPEG_H__

#if defined(JPEG_CODEC_STANDALONE)
   #define __DRV_GRAPHICS_JPEG_6236_SERIES__

   #define __YUVCAM_INTERPOLATION_SW__
   #define JPG_ENCODE
   #define SW_JPEG_ENCODER_SUPPORT_WITH_DYNAMIC_QUALITY_ADJUSTMENT
   #define SW_JPEG_ENCODER_MAX_COMPRESSION_RATIO_WITH_DYNAMIC_QUALITY_ADJUSTMENT   2

   #define __SW_JPEG_DECODER_FULL_PROFILE_INTERNAL___
#else
   #include "drv_features_chip_select.h"
#endif

#define __SW_JPEG_ENCODER_SUPPORT__

#if defined(__DRV_GRAPHICS_JPEG_6253_SERIES__)
   #define __SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__
#endif

#if defined(__DRV_GRAPHICS_JPEG_6253_SERIES__) || defined(__DRV_GRAPHICS_JPEG_6252_SERIES__)
   #define __SW_JPEG_DECODER_BASIC_PROFILE_INTERNAL___
#else
   #define __SW_JPEG_DECODER_FULL_PROFILE_INTERNAL___
#endif

#if defined(__SW_JPEG_DECODER_BASIC_PROFILE_INTERNAL___)
   #define SW_JPEG_DECODER_SUPPORT_WITH_DST_ARGB8888
   #define SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV420
   #define SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV422
#endif

#if defined(__SW_JPEG_DECODER_FULL_PROFILE_INTERNAL___)
   #define SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE
   #define SW_JPEG_DECODER_SUPPORT_WITH_DST_RGB888
   #define SW_JPEG_DECODER_SUPPORT_WITH_DST_BGR888
   #define SW_JPEG_DECODER_SUPPORT_WITH_DST_ARGB8888
   #define SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV420
   #define SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV422
   #define SW_JPEG_DECODER_SUPPORT_WITH_ROTATION
#endif

#if defined(__DRV_GRAPHICS_JPEG_6253_SERIES__) || defined(__DRV_GRAPHICS_JPEG_6252_SERIES__)
   #define SW_JPEG_ENCODER_SUPPORT_WITH_DYNAMIC_QUALITY_ADJUSTMENT
   #define SW_JPEG_ENCODER_MAX_COMPRESSION_RATIO_WITH_DYNAMIC_QUALITY_ADJUSTMENT   2   
#endif

#if defined(__DRV_GRAPHICS_JPEG_6276_SERIES__) || defined(__DRV_GRAPHICS_JPEG_6236_SERIES__) || defined(__DRV_GRAPHICS_JPEG_6256_SERIES__)

   #define SW_JPEG_ENCODER_SUPPORT_WITH_SRC_RGB888
   ///#define SW_JPEG_ENCODER_SUPPORT_WITH_SRC_BGR888
   #define SW_JPEG_ENCODER_SUPPORT_WITH_SRC_UYVY
   #define SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422
   ///#define SW_JPEG_ENCODER_SUPPORT_WITH_RGB_RESIZER

#elif defined(__DRV_GRAPHICS_JPEG_6255_SERIES__)

   #define SW_JPEG_ENCODER_SUPPORT_WITH_SRC_UYVY
   #define SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422
   
#elif defined(__DRV_GRAPHICS_JPEG_6252_SERIES__)

   ///#if ((!defined(LOW_COST_SUPPORT)) || defined(__ATV_SUPPORT__))
   #define SW_JPEG_ENCODER_SUPPORT_WITH_SRC_UYVY
   ///#endif
   #define SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422

#elif defined(__DRV_GRAPHICS_JPEG_6253_SERIES__)

   #define __SW_JPEG_ENC_V2_USING_INTERNAL_MEMORY__
   #define SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422

#elif defined(__DRV_GRAPHICS_JPEG_6268_SERIES__) || defined(__DRV_GRAPHICS_JPEG_6235_SERIES__)

   #define SW_JPEG_ENCODER_SUPPORT_WITH_SRC_RGB888
   #define SW_JPEG_ENCODER_SUPPORT_WITH_DST_YUV422

#endif

/// Currently, we only support rotation on MT6253 series...
#ifdef __LANDSCAPE_UI_ON_PORTRAIT_LCM__
   #define SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT
#endif

#if defined(__YUVCAM_INTERPOLATION_SW__)
   #define SW_JPEG_ENCODER_SUPPORT_WITH_YUV_RESIZER
#endif

#if !defined(__MTK_TARGET__) || defined(__UL1_STANDALONE__) || defined(__L1_STANDALONE__)
   #undef __DRV_GRAPHICS_JPEG_6236_SERIES__
   #undef __DRV_GRAPHICS_JPEG_6276_SERIES__
   #undef __DRV_GRAPHICS_JPEG_6268_SERIES__
   #undef __DRV_GRAPHICS_JPEG_6256_SERIES__
   #undef __DRV_GRAPHICS_JPEG_6255_SERIES__
#endif

#if !defined(__LOW_COST_SUPPORT_ULC__)
   #define __JPEG_THUMBNAIL_SUPPORT__       
#endif

#define __JPEG_QUICK_VIEW_IMAGE_SUPPORT__
   

#if defined(__MTK_TARGET__)
   #if defined(__DRV_GRAPHICS_JPEG_6268_SERIES__)
      #define __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__
      #define __DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__
      #define __DRV_GRAPHICS_HW_DCT_CONTROL_NEEDED__
      #define __JPEG_ENC_PATCH_FOR_HQA00000392__                     /// Workaround for HW bug HQA00000392
      #define __JPEG_DEC_PATCH_FOR_HQA00000732__                     /// Workaround for HW bug HQA00000732
      #define __JPEG_DEC_PATCH_FOR_HQA00009744__                     /// Workaround for HW bug HQA00009744
      #define __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_PROGRESSIVE__
   #endif

   #if defined(__DRV_GRAPHICS_JPEG_6236_SERIES__)
      #define __DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__
      #define __DRV_GRAPHICS_HW_DCT_CONTROL_NEEDED__
      #define __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_PROGRESSIVE__
   #endif

   #if defined(__DRV_GRAPHICS_JPEG_6276_SERIES__)
      #define __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__
      #define __DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__
      #define __DRV_GRAPHICS_HW_DCT_CONTROL_NEEDED__
      #define __DRV_GRAPHICS_HW_JPEG_DECODE_ALWAYS_READ_FILE__       /// For MT6276 HW JPEG decoder, file address needs 8-bytes alignment.
      #define __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_SRC_YUV420__       /// MT6276 MDP could support yuv420 source format.
      #define __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_SRC_PACKED_UYVY422__       /// MT6276 MDP could support uyvy422 source format.

      #if defined(MT6276_S00)
         #define __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_PROGRESSIVE__
      #else
         #define __DRV_GRAPHICS_JPEG_6276_E2_SERIES__
      #endif
   #endif

   #if defined(__DRV_GRAPHICS_JPEG_6256_SERIES__)
      #define __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__
      #define __DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__
      #define __DRV_GRAPHICS_HW_DCT_CONTROL_NEEDED__
      #define __DRV_GRAPHICS_HW_JPEG_DECODE_ALWAYS_READ_FILE__       /// For MT6256 HW JPEG decoder, file address needs 8-bytes alignment.
      #define __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_SRC_YUV420__       /// MT6256 MDP could support yuv420 source format.
      #define __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_SRC_PACKED_UYVY422__       /// MT6256 MDP could support uyvy422 source format.

      #if defined(MT6256_S00)
         #define __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_PROGRESSIVE__
      #else
         #define __DRV_GRAPHICS_JPEG_6256_E2_SERIES__
      #endif
   #endif

   #if defined(__DRV_GRAPHICS_JPEG_6255_SERIES__)
      #define __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__
      #define __DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__
      #define __DRV_GRAPHICS_HW_DCT_CONTROL_NEEDED__
      #define __DRV_GRAPHICS_HW_JPEG_DECODE_ALWAYS_READ_FILE__                   /// For MT6255 HW JPEG decoder, file address needs 8-bytes alignment.
      #define __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_SRC_YUV420__            /// MT6255 HW JPEG could support yuv420 source format.
      #define __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_SRC_PACKED_UYVY422__    /// MT6255 HW JPEG could support uyvy422 source format.
      #define __DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__                 /// For MT6255 HW JPEG decoder, data pipe is separated from mdp
      #define __DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__       /// For MT6255 HW JPEG encoder, data pipe is separated from mdp

      #if defined(MT6255_S00)
         #define __JPEG_PATCH_FOR_HQA00010326__
      #endif
   #endif
#endif
   
#endif /// __DRV_FEATURES_JPEG_H__

