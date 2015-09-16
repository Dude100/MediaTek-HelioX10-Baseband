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
 *    drv_sw_features_video.h
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
 * 08 29 2011 ct.fang
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
 ****************************************************************************/


#ifndef __DRV_SW_FEATURES_VIDEO_H__
#define __DRV_SW_FEATURES_VIDEO_H__

/** 
 *  Video Architecture v2 Video Renderer related feature options.
 *  Please contact Video Renderer owners for below macro definitions.
 *  
 *  \def VA2_RENDER_MODE_TOUCH_FROM_INSIDE_SUPPORTED
 *  If this macro is defined, Video playback renderer supports touch window 
 *  from inside mode.
 *  
 *  \def VA2_RENDER_MODE_TOUCH_FROM_OUTSIDE_SUPPORTED
 *  If this macro is defined, Video playback renderer supports touch window 
 *  from outside mode. 
 *  
 *  \def VA2_RENDERER_VP_VIDEO_PROCESSING_SUPPORTED
 *  If this macro is defined, Video processing is supported in video playback 
 *  renderer. The basic functions include brightness/darkness adjustment and 
 *  constrast adjustment. The users of Video playback renderer can use this 
 *  feature by accessing VIDEO_CONFIG_RENDERER_POST_PROCESS.
 *  
 *  \def VA2_RENDERER_VP_RENDER_DISPLAY_BUFFER_RGB888
 *  If this macro is defined, Video Renderer can output color format RGB888 when 
 *  MPL get parameter VIDEO_PARAM_RENDERER_RENDER_DISPLAY_BUFFER. 
 *  This does not imply Video Renderer can do playback with RGB888 as display 
 *  color format.
 *  Please remember to change it back to UYVY or RGB565 when starting playback.
 *
 *  \def VA2_RENDERER_VP_RENDER_DISPLAY_BUFFER_BGR888
 *  If this macro is defined, Video Renderer can output color format BGR888 when 
 *  MPL get parameter VIDEO_PARAM_RENDERER_RENDER_DISPLAY_BUFFER. 
 *  This does not imply Video Renderer can do playback with BGR888 as display 
 *  color format.
 *  Please remember to change it back to UYVY or RGB565 when starting playback.
 *
 *  \def VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED
 *  If this macro is defined, Video playback renderer supports on the fly stereo
 *  video.
 *  
 */
// MT6252
#if defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
#define VA2_RENDER_MODE_TOUCH_FROM_INSIDE_SUPPORTED
#define VA2_RENDER_MODE_TOUCH_FROM_OUTSIDE_SUPPORTED
#undef VA2_RENDERER_VP_VIDEO_PROCESSING_SUPPORTED
#undef VA2_RENDERER_VP_RENDER_DISPLAY_BUFFER_RGB888
#undef VA2_RENDERER_VP_RENDER_DISPLAY_BUFFER_BGR888
#undef VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED
#endif
// MT6236
#if defined(MT6236) || defined(MT6236B)
#define VA2_RENDER_MODE_TOUCH_FROM_INSIDE_SUPPORTED
#define VA2_RENDER_MODE_TOUCH_FROM_OUTSIDE_SUPPORTED
#define VA2_RENDERER_VP_VIDEO_PROCESSING_SUPPORTED
#define VA2_RENDERER_VP_RENDER_DISPLAY_BUFFER_RGB888
#define VA2_RENDERER_VP_RENDER_DISPLAY_BUFFER_BGR888
#undef VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED
#endif
// MT6276 and MT6256 and MT6255
#if defined(MT6276) || defined(MT6256) || defined(MT6255)
#define VA2_RENDER_MODE_TOUCH_FROM_INSIDE_SUPPORTED
#define VA2_RENDER_MODE_TOUCH_FROM_OUTSIDE_SUPPORTED
#define VA2_RENDERER_VP_VIDEO_PROCESSING_SUPPORTED
#define VA2_RENDERER_VP_RENDER_DISPLAY_BUFFER_RGB888
#define VA2_RENDERER_VP_RENDER_DISPLAY_BUFFER_BGR888
#if defined(__VIDEO_3D_SIDE_BY_SIDE__)
  #define VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED
#else
  #undef VA2_RENDERER_VP_STEREO_VIDEO_SUPPORTED
#endif
#endif

#endif   /*End __DRV_SW_FEATURES_VIDEO_H__*/
