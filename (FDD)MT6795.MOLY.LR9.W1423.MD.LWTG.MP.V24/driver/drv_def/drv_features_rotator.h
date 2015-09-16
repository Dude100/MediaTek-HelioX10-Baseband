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
 *    drv_features_rotator.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DRV_FEATURES_ROTATOR_H__
#define __DRV_FEATURES_ROTATOR_H__

#if !defined(ROTATOR_STANDALONE)
   #include "drv_features_chip_select.h"
   #include "drv_features_g2d.h"
#endif

#if defined(G2D_HW_BITBLT_SUPPORT)
   #define RGB_ROTATOR_HW_SUPPORT
#endif

/// RGB Rotator
///#if defined(__DRV_GRAPHICS_RGB_ROTATOR_6253_SERIES__)
///   #define __SW_RGB_ROTATOR_BASIC_PROFILE_INTERNAL___
///#else
///   #define __SW_RGB_ROTATOR_FULL_PROFILE_INTERNAL___
///#endif

#if defined(__DRV_GRAPHICS_RGB_ROTATOR_6253_SERIES__)
#else
   #define RGB_ROTATOR_SW_SUPPORT_WITH_SRC_RGB888
#endif

#if defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__) || defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_ENCODE__)
   #define RGB_ROTATOR_SW_SUPPORT_WITH_SRC_GRAY
#endif

#define RGB_ROTATOR_SW_SUPPORT_WITH_SRC_ARGB8888

#define RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_000
#define RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_090

#if defined(__DRV_GRAPHICS_RGB_ROTATOR_6253_SERIES__)
#else
   #define RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_180
#endif

#define RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_270

///#define RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_000
///#define RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_090
///#define RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_180
///#define RGB_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_270



/// YUV Rotator
#if defined(__DRV_GRAPHICS_YUV_ROTATOR_6268_SERIES__)
   #define YUV_ROTATOR_SW_SUPPORT_WITH_SRC_YUV420B4X4P
#endif
                                           
///#define YUV_ROTATOR_SW_SUPPORT_WITH_SRC_YUV420B4X4P
///#define YUV_ROTATOR_SW_SUPPORT_WITH_SRC_UYVY422

#define YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_000
#define YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_090

#if defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__) || defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_ENCODE__)
   #define YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_180
#endif

#define YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_270   

#if defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__) || defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_ENCODE__) || defined(__ATV_SUPPORT__ )
   //#if defined(__DRV_GRAPHICS_YUV_ROTATOR_6276_SERIES__) || defined(__DRV_GRAPHICS_YUV_ROTATOR_6268_SERIES__) || defined(__DRV_GRAPHICS_YUV_ROTATOR_6252_SERIES__) || defined(__DRV_GRAPHICS_YUV_ROTATOR_6236_SERIES__)
      #define YUV_ROTATOR_SW_SUPPORT_WITH_SRC_UYVY422
   //#endif
#endif

#if defined(__DRV_GRAPHICS_YUV_ROTATOR_6253_SERIES__) || defined(__DRV_GRAPHICS_YUV_ROTATOR_6252_SERIES__)
#else
   #define YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_000
   #define YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_090

   #if defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__) || defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_ENCODE__)
      #define YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_180
   #endif

   #define YUV_ROTATOR_SW_SUPPORT_WITH_ROTATE_ANGLE_MIRROR_270
#endif
#endif /// __DRV_FEATURES_G2D_H__

