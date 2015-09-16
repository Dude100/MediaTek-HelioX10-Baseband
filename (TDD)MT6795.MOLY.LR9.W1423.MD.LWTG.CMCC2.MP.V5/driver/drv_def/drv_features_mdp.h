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
 *    drv_features_mdp.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for all driver features.
 *
 * Author:
 * -------
 * 
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * add MT6256 E1, E2 chip features.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * NULL
 * .
 *
 * removed!
 * NULL
 * .
 *
 * removed!
 * NULL
 * .
 *
 * removed!
 * NULL
 * .
 *
 ****************************************************************************/


#ifndef __DRV_FEATURES_MDP_H__
#define __DRV_FEATURES_MDP_H__

#include "drv_features_chip_select.h"

/**********************************
 * Chip-independent IDP driver definition section
 **********************************/
#undef DRV_RGB_RESIZE_SUPPORT
#undef DRV_BLOCK_EFFECT_SUPPORT
#undef DRV_PIXEL_EFFECT_SUPPORT

/**
 *  \def MDP_SUPPORT_FAST_POWER_ON_OFF
 *  If this is defined, it means video renderer will power on/off mdp engines
 *  when mdp frame start/end to save power
 */
#undef MDP_SUPPORT_FAST_POWER_ON_OFF

/**
 *  \def MDP_SUPPORT_VP_EMI_BW_SWITCH
 *  If this is defined, it means video renderer will switch EMI BW 
 *  when renderer start/stop to release EMI BW to other modules.
 */
#undef MDP_SUPPORT_VP_EMI_BW_SWITCH



#if defined(DRV_IDP_MT6236_SERIES)
#define DRV_IDP_SUPPORT

#define DRV_RGB_RESIZE_SUPPORT
#define DRV_BLOCK_EFFECT_SW_SUPPORT

#if defined(ISP_SUPPORT)
  #define DRV_PIXEL_EFFECT_SUPPORT
#endif /* #if defined(ISP_SUPPORT) */

#define MDP_SUPPORT_RGB565_FMT_INTERNAL
#define USE_UYVY422_BETWEEN_MDP_LCD_INTERNAL  //MDP -> UYVY422 buffer -> LCD
#define MDP_SUPPORT_IMAGE_EFFECT_INTERNAL
#define MDP_SUPPORT_HW_OVERLAP_INTERNAL

#define MDP_SUPPORT_FAST_POWER_ON_OFF

#if defined(__MTK_TARGET__)
/**
 *  \def DRV_IDP_THUMBNAIL_COLOR_FORMAT_BGR888
 *  This option describes the thumbnail color format supported by IDP is BGR888. 
 *  B in high byte. This or DRV_IDP_THUMBNAIL_COLOR_FORMAT_RGB888 must be 
 *  defined in any chip IDP supports JPEG encoding.
 */
#define DRV_IDP_THUMBNAIL_COLOR_FORMAT_BGR888
#endif  // #if defined(__MTK_TARGET__)

/**
 *  \def DRV_IDP_FEATURE__VT_RECORD_DISPLAY_ROTATION_MIRROR
 *  When this option is defined, MDP driver supports rotation and mirror 
 *  functions on display output path. In MT6236, it needs resource manager.
 */
#if defined(__RESOURCE_MANAGER__)
#define DRV_IDP_FEATURE__VT_RECORD_DISPLAY_ROTATION_MIRROR
#else   // #if defined(__RESOURCE_MANAGER__)
#undef DRV_IDP_FEATURE__VT_RECORD_DISPLAY_ROTATION_MIRROR
#endif  // #if defined(__RESOURCE_MANAGER__)

/**
 *  \def DRV_IDP_FEATURE__VT_RECORD_VIDEO_FRAME_ROTATION_MIRROR
 *  If defined, MDP driver supports rotation and mirror functions on video 
 *  frame buffer output.
 */
//#define DRV_IDP_FEATURE__VT_RECORD_VIDEO_FRAME_ROTATION_MIRROR
#endif // #if defined(DRV_IDP_MT6236_SERIES)


#if defined(DRV_IDP_6252_SERIES)
#define DRV_IDP_SUPPORT            
#define MDP_FW_TRIGGER_LCD             

#undef DRV_RGB_RESIZE_SUPPORT
#undef DRV_BLOCK_EFFECT_SUPPORT
#undef DRV_PIXEL_EFFECT_SUPPORT

#undef MDP_SUPPORT_RGB565_FMT_INTERNAL
#define USE_UYVY422_BETWEEN_MDP_LCD_INTERNAL  //MDP -> UYVY422 buffer -> LCD
#undef MDP_SUPPORT_IMAGE_EFFECT_INTERNAL
#undef MDP_SUPPORT_HW_OVERLAP_INTERNAL
#define MDP_SUPPORT_FAST_POWER_ON_OFF

/* USE 2 pass to break ROTDMA 90 degree source width cannot > 320(MT6252) or 480(MT6250) */
#define IDP_VIDEO_DECODE_2PASS_ROTATE_TRICK
#endif // #if defined(DRV_IDP_6252_SERIES)



#if defined(DRV_IDP_MT6256_SERIES)

#if defined(MT6256_S00)             // E1 series
  #define DRV_IDP_MT6256_E1_SERIES
#else                               // E2 and later series 
  #define DRV_IDP_MT6256_E2_SERIES
#endif

#define DRV_IDP_SUPPORT    

#define DRV_RGB_RESIZE_SUPPORT
#define DRV_BLOCK_EFFECT_SW_SUPPORT
  
#if defined(ISP_SUPPORT)
  #define DRV_PIXEL_EFFECT_SUPPORT
#endif /* #if defined(ISP_SUPPORT) */

#define MDP_SUPPORT_RGB565_FMT_INTERNAL
#define USE_UYVY422_BETWEEN_MDP_LCD_INTERNAL  //MDP -> UYVY422 buffer -> LCD
#define MDP_SUPPORT_IMAGE_EFFECT_INTERNAL
#define MDP_SUPPORT_HW_OVERLAP_INTERNAL
#define MDP_SUPPORT_FAST_POWER_ON_OFF
#define MDP_SUPPORT_VP_EMI_BW_SWITCH

#endif // #if defined(DRV_IDP_MT6256_SERIES)


#if defined(DRV_IDP_MT6255_SERIES)

#define DRV_IDP_SUPPORT    

#define DRV_RGB_RESIZE_SUPPORT
#define DRV_BLOCK_EFFECT_SW_SUPPORT
  
#if defined(ISP_SUPPORT)
  #define DRV_PIXEL_EFFECT_SUPPORT
#endif /* #if defined(ISP_SUPPORT) */

#define MDP_SUPPORT_RGB565_FMT_INTERNAL
#define USE_UYVY422_BETWEEN_MDP_LCD_INTERNAL  //MDP -> UYVY422 buffer -> LCD
#define MDP_SUPPORT_IMAGE_EFFECT_INTERNAL

#define MDP_SUPPORT_FAST_POWER_ON_OFF
#endif // #if defined(DRV_IDP_MT6255_SERIES)



#if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES)
#define DRV_IDP_SUPPORT         

#define DRV_RGB_RESIZE_SUPPORT
#define DRV_BLOCK_EFFECT_SW_SUPPORT
  
#if defined(ISP_SUPPORT)
  #define DRV_PIXEL_EFFECT_SUPPORT
#endif /* #if defined(ISP_SUPPORT) */

#define MDP_SUPPORT_RGB565_FMT_INTERNAL
#define USE_UYVY422_BETWEEN_MDP_LCD_INTERNAL  //MDP -> UYVY422 buffer -> LCD
#define  MDP_SUPPORT_IMAGE_EFFECT_INTERNAL
#define MDP_SUPPORT_HW_OVERLAP_INTERNAL

#define MDP_SUPPORT_FAST_POWER_ON_OFF

#endif // #if defined(DRV_IDP_MT6276_SERIES)

#endif   /*End __DRV_FEATURES_MDP_H__*/
