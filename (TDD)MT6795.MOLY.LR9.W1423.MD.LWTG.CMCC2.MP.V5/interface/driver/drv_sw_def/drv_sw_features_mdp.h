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
 *    drv_sw_features_mdp.h
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
 * -------
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
 * 08 08 2011 ct.fang
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
 * 12 25 2010 ct.fang
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
 *
 ****************************************************************************/


#ifndef __DRV_SW_FEATURES_MDP_H__
#define __DRV_SW_FEATURES_MDP_H__

#include "drv_features_mdp.h"

//MT6252 only support yuv format
#if defined(MDP_SUPPORT_RGB565_FMT_INTERNAL)
#define MDP_SUPPORT_RGB565_FMT
#endif

//MT6236 MT6276 MT6252 supports UYVY format for display
#if defined(USE_UYVY422_BETWEEN_MDP_LCD_INTERNAL)
#define USE_UYVY422_BETWEEN_MDP_LCD     //MDP -> UYVY422 buffer -> LCD
#endif

//MT6276 MT6236 MT6256 MT6268 Has HW Image Effect Engine
#if defined(MDP_SUPPORT_IMAGE_EFFECT_INTERNAL)
#define MDP_SUPPORT_IMAGE_EFFECT    
#endif

//MT6276 MT6236 MT6256 MT6268 Has HW Overlay Engine
#if defined(MDP_SUPPORT_HW_OVERLAP_INTERNAL)
#define MDP_SUPPORT_HW_OVERLAP    
#endif

//MT6235 MT6252 MT6253 for 2 pass video encode
#if defined(VIDEO_ENCODE_USE_DOUBLE_SENSOR_FPS_INTERNAL)
#define VIDEO_ENCODE_USE_DOUBLE_SENSOR_FPS    
#endif

//MT6236 MT6268 MT6256 MT6276 Has HW RGB Resize Support
//This macro is exported from DRV_RGB_RESIZE_SUPPORT defined at drv_features_mdp.h
//and is used for GDI to reference about HW RGB resizer support capability.
#if defined(DRV_RGB_RESIZE_SUPPORT)
#define MDP_SUPPORT_RGB_RESIZE    
#endif

/**
 * This compile option(in option.make) defines the multiple display buffer support capability of AP.
 * In newer version HAL part, MDP driver will support multiple display buffer. 
 * But in old version of Non-HAL AP, FramebufferN(N > 2) is unavailable and uninitialized(risk). 
 * To keep HAL backward compatiblity, this compile option is added to sync driver and AP.
 */
#if defined(__MDP_MULTIPLE_DISPLAY_BUFFER_SUPPORT__)
//all chip can supportm default turn OFF except MT6268
#if defined(DRV_IDP_6238_SERIES)
#define MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER
#else
#undef MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER
#endif

//all chip can support, default turn OFF
#undef MDP_SUPPORT_VR_TRIPLE_DISPLAY_BUFFER    

//MT6236 MT6268 MT6276 MT6256, default turn OFF
#undef MDP_SUPPORT_VTR_TRIPLE_DISPLAY_BUFFER    
#endif

#if defined(DRV_IDP_6238_SERIES)
/**
 *  \def DRV_MDP_HW_RGB_2_BLOCK_YUV_SUPPORT
 *  When this drv sw feature option is defined, idp_rgb2yuv API is supported.
 *  This API on MT6238/MT6268 series will serve to convert RGB565 color format to 
 *  4x4 block-based YUV420 planar color format, and it is mainly used in VT 
 *  to convert a display layer buffer for HW MP4 encoder to input.
 */
#define DRV_MDP_HW_RGB_2_BLOCK_YUV_SUPPORT
#endif // #if defined(DRV_IDP_MT6238_SERIES)

#if defined(DRV_IDP_6252_SERIES)
/**
 *  The following three macros define the max size of HW layer in multimedia scenarios on MT6252 series. 
 *  The longer side of HW layer should be equal to or smaller than this value.
 *  This is for MT6252+WQVGA display feature to limit multimedia HW layer size smaller than QVGA. 
 *  The limitation comes from MT6252 MDP HW does not have big enough line buffer.
 *  If customers like to expand HW layer size to occupy full screen, the customers should 
 *  try to find a compromise in frame rate or bit rate to make the scenarios work on their own.
 */
#if defined(MT6252H) || defined(MT6252)
#define DRV_MDP_CAMERA_PREVIEW_MAX_HW_LAYER_SIZE    (320)
#define DRV_MDP_VIDEO_PREVIEW_MAX_HW_LAYER_SIZE     (320)
#define DRV_MDP_VIDEO_PLAYBACK_MAX_HW_LAYER_SIZE    (320)
#elif defined(MT6250)
#define DRV_MDP_CAMERA_PREVIEW_MAX_HW_LAYER_SIZE    (480)
#define DRV_MDP_VIDEO_PREVIEW_MAX_HW_LAYER_SIZE     (480)
#define DRV_MDP_VIDEO_PLAYBACK_MAX_HW_LAYER_SIZE    (480)
#endif
#endif  // #if defined(DRV_IDP_6252_SERIES)

#if defined(DRV_IDP_MT6236_SERIES)
/**
 *  The following three macros define the max size of HW layer in multimedia scenarios on MT6236 series. 
 *  The longer side of HW layer should be equal to or smaller than this value.
 *  This is for MT6236+nHD or WVGA display feature to limit multimedia HW layer size smaller than HVGA. 
 *  The limitation comes from MT6236 cannot support enough EMI BW and line buffer.
 *  If customers like to expand HW layer size to occupy full screen, the customers should 
 *  try to find a compromise in frame rate or bit rate to make the scenarios work on their own.
 */
#define DRV_MDP_CAMERA_PREVIEW_MAX_HW_LAYER_SIZE    (480)
#define DRV_MDP_VIDEO_PREVIEW_MAX_HW_LAYER_SIZE     (480)
#define DRV_MDP_VIDEO_PLAYBACK_MAX_HW_LAYER_SIZE    (480)
#endif  // #if defined(DRV_IDP_MT6236_SERIES)

#if defined(DRV_IDP_6238_SERIES)
/**
 *  The following three macros define the max size of HW layer in multimedia scenarios on MT6268 series. 
 *  The longer side of HW layer should be equal to or smaller than this value.
 *  This is for MT6268+nHD or WVGA display feature to limit multimedia HW layer size smaller than HVGA. 
 *  The limitation comes from MT6268 cannot support enough EMI BW and line buffer.
 *  If customers like to expand HW layer size to occupy full screen, the customers should 
 *  try to find a compromise in frame rate or bit rate to make the scenarios work on their own.
 */
#define DRV_MDP_CAMERA_PREVIEW_MAX_HW_LAYER_SIZE    (480)
#define DRV_MDP_VIDEO_PREVIEW_MAX_HW_LAYER_SIZE     (480)
#define DRV_MDP_VIDEO_PLAYBACK_MAX_HW_LAYER_SIZE    (480)
#endif  // #if defined(DRV_IDP_6238_SERIES)

#if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES)
/**
 *  The following three macros define the max size of HW layer in multimedia scenarios on MT6276 series. 
 *  The longer side of HW layer should be equal to or smaller than this value.
 *  This is for MT6276+FWVGA or DVGA or qHD display feature to limit multimedia HW layer size smaller than WVGA. 
 *  The limitation comes from MT6276 cannot support enough EMI BW and line buffer.
 *  If customers like to expand HW layer size to occupy full screen, the customers should 
 *  try to find a compromise in frame rate or bit rate to make the scenarios work on their own.
 */
#define DRV_MDP_CAMERA_PREVIEW_MAX_HW_LAYER_SIZE    (800)
#define DRV_MDP_VIDEO_PREVIEW_MAX_HW_LAYER_SIZE     (800)
#define DRV_MDP_VIDEO_PLAYBACK_MAX_HW_LAYER_SIZE    (800)
#endif  // #if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES)

#if defined(DRV_IDP_MT6255_SERIES)
/**
 *  The following three macros define the max size of HW layer in multimedia scenarios on MT6255 series. 
 *  The longer side of HW layer should be equal to or smaller than this value.
 *  This is for MT6255+FWVGA or DVGA or qHD display feature to limit multimedia HW layer size smaller than HVGA. 
 *  The limitation comes from MT6255 cannot support enough EMI BW and line buffer.
 *  If customers like to expand HW layer size to occupy full screen, the customers should 
 *  try to find a compromise in frame rate or bit rate to make the scenarios work on their own.
 */
#define DRV_MDP_CAMERA_PREVIEW_MAX_HW_LAYER_SIZE    (864)
#define DRV_MDP_VIDEO_PREVIEW_MAX_HW_LAYER_SIZE     (864)
#define DRV_MDP_VIDEO_PLAYBACK_MAX_HW_LAYER_SIZE    (864)
#endif  // #if defined(DRV_IDP_MT6255_SERIES)
#if defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6256E2_SERIES)
/**
 *  The following three macros define the max size of HW layer in multimedia scenarios on MT6256 series. 
 *  The longer side of HW layer should be equal to or smaller than this value.
 *  This is for MT6256+FWVGA or DVGA or qHD display feature to limit multimedia HW layer size smaller than WVGA. 
 *  The limitation comes from MT6256 cannot support enough EMI BW and line buffer.
 *  If customers like to expand HW layer size to occupy full screen, the customers should 
 *  try to find a compromise in frame rate or bit rate to make the scenarios work on their own.
 */
#define DRV_MDP_CAMERA_PREVIEW_MAX_HW_LAYER_SIZE    (800)
#define DRV_MDP_VIDEO_PREVIEW_MAX_HW_LAYER_SIZE     (800)
#define DRV_MDP_VIDEO_PLAYBACK_MAX_HW_LAYER_SIZE    (800)
#endif  // #if defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6256E2_SERIES)

#ifndef DRV_MDP_CAMERA_PREVIEW_MAX_HW_LAYER_SIZE
#define DRV_MDP_CAMERA_PREVIEW_MAX_HW_LAYER_SIZE    (320)   // default value QVGA
#endif  // #ifndef DRV_MDP_CAMERA_PREVIEW_MAX_HW_LAYER_SIZE

#ifndef DRV_MDP_VIDEO_PREVIEW_MAX_HW_LAYER_SIZE
#define DRV_MDP_VIDEO_PREVIEW_MAX_HW_LAYER_SIZE     (320)   // default value QVGA
#endif  // #ifndef DRV_MDP_VIDEO_PREVIEW_MAX_HW_LAYER_SIZE

#ifndef DRV_MDP_VIDEO_PLAYBACK_MAX_HW_LAYER_SIZE
#define DRV_MDP_VIDEO_PLAYBACK_MAX_HW_LAYER_SIZE    (320)   // default value QVGA
#endif  // #ifndef DRV_MDP_VIDEO_PLAYBACK_MAX_HW_LAYER_SIZE

#endif   /*End __DRV_SW_FEATURES_MDP_H__*/
