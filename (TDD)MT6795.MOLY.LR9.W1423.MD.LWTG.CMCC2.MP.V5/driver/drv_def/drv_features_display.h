/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *    drv_features_display.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file defines driver feature options for Display Drivers: 
 *      1. LCD driver
 *      2. GOVL driver
 *      3. TV out driver
 *    According to chip series.
 *    
 *    This file should only be included by HAL modules and should not be 
 *    included by non-HAL modules.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DRV_FEATURES_DISPLAY_H__
#define __DRV_FEATURES_DISPLAY_H__

/******************************************************************************
 * Documentation
 ******************************************************************************/

/******************************************************************************
 * Include directives
 ******************************************************************************/
#include "drv_features_chip_select.h"
/******************************************************************************
 * Section of LCD Driver
 ******************************************************************************/

#if defined(__MTK_TARGET__)

// TODO: We can put common at the top of this section to reduce options in each 
// TODO: chip sub-section.

#if defined(__MTK_INTERNAL__)
/**
 *  WARNING! This option can only be defined when __MTK_INTERNAL__ is defined.
 */
//#define LCD_PROFILING_SUPPORT
#endif

/**
 *  \def LCD_TE_INTERRUPT_CLEAR_FRAME_TRANSFER_COMPLETE_INTERRUPT_ISSUE_WORKAROUND
 *  This option is effective for platform:MT6235,MT6236,MT6253,MT6268
 *  This option is defined for HW bug:small ROI update,TE INT and FRAME complete INT arrive very close,
 *  read TE INT will clear FRAME complete INT,so LCD driver will hang for waiting FRAME complete INT.
 *  \remark NONE.
 */

#if defined(MT6236) || defined(MT6236B) || defined(TK6280)
    
    #define LCD_TE_INTERRUPT_CLEAR_FRAME_TRANSFER_COMPLETE_INTERRUPT_ISSUE_WORKAROUND
	
#endif
#define LCD_POWER_CTRL_MOD_SUPPORT
/**
 *  \def DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT
 *  If this is defined, DDv2 TearingFree Manager is working to avoid partial update tearing. 
 *  This option is effective when DRV_DISPLAY_DRIVER_V2 is also defined.
 *  \remark NONE.
 */
#undef DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT
//#if !(defined(MT6252) || defined(MT6252H))
#define DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT
//#endif


#if !(defined(IC_BURNIN_TEST) || defined(IC_MODULE_TEST))
  #define DRV_LCD_DEBUG_SUPPORT
#endif

// ---------- MT6236 series  ---------- //
#if defined(DRV_LCD_MT6236_SERIES)
  #define DRV_DISPLAY_DRIVER_V2_SLIM_SUPPORT
  #if defined(MT6236)
    #define LCD_POWER_CTRL_MOD_SUPPORT
  #elif defined(MT6236B)
    /* dummy */
  #endif

  #define LCD_DRIVER_CHIP_SEPARATE

  //#define WFD_LCD_ADAPTER_SUPPORT

  /* Features for LCD */
  #define LCD_ROI_MAX_WIDTH                   (0x7FF)
  #define LCD_ROI_MAX_HEIGHT                  (0x7FF)
  #define LCD_ROI_MAX_OFFSETX                 (0x7FF)
  #define LCD_ROI_MAX_OFFSETY                 (0x7FF)
  #define LCD_LAYER_ORIGIN_X                  (0)
  #define LCD_LAYER_ORIGIN_Y                  (0)

  #define LCD_LAYER_MEM_MAX_OFFSETX           (0x7FF)
  #define LCD_LAYER_MEM_MAX_OFFSETY           (0x7FF)
  #define LCD_LAYER_MEM_MAX_PITCH             (0x7FF)

  #define LCD_MEM_OUT_MAX_MAIN_WINDOW_WIDTH   (0x7FF)
  #define LCD_MEM_OUT_MAX_MAIN_WINDOW_HEIGHT  (0x7FF)
  #define LCD_MEM_OUT_MAX_OFFSETX             (0x7FF)
  #define LCD_MEM_OUT_MAX_OFFSETY             (0x7FF)

  #define LCD_BYTE_ALIGN_CNT                  (4)
  #define DRV_GOVL_LAYER_TOTAL_COUNT          (4)
  #define DRV_PARALLEL_INTERFACE_COUNT        (3)
  #define DRV_SERIAL_INTERFACE_COUNT          (1)
  #define DRV_LCD_CMD_QUEUE_COUNT             (2)
  #define DRV_LCD_CMD_QUEUE_NUMBER            (32)

  //Don't remove the 2 options. FOTA will use them.
  #define DRV_LCD_ROI_BACKGROUND_COLOR_RGB888
  #undef DRV_LCD_ROI_BACKGROUND_COLOR_RGB565
  //#define DRV_LAYER_DITHER

  #define DRV_LCD_GAMMA_CORRECTION_SUPPORT
  #define DRV_LCD_GAMMA_CORRECTION_QUEUE_NUMBER (256)

  // TODO: The following To be removed:
  //#define DRV_LCD_SW_MEMORY_OUTPUT_OFFSET_SUPPORT

  /* Features for Image Data Path */
  //#define DRV_LCD_FW_UPDATE_SUPPORT
  #define DRV_LCD_HW_TRIGGER_SUPPORT
  //#define DRV_LCD_DC_TRIGGER_SUPPORT 

  // Feature options for MT6236
  #define LCD_WMEM_PARGB8888 LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA
  //#define LCD_LAYER_SOURCE_COLOR_YUYV422
  //#define LCD_LAYER_SOURCE_COLOR_PARGB8888
  #define LCD_LAYER_SUPPORT_HW_DITHER
  #define LCD_LAYER_SUPPORT_PITCH

  //#define __GOVL_SUPPORT__
  //#define DRV_ROT1_DEBUG_SUPPORT
  //#define DRV_GOVL_DEBUG_SUPPORT

  // Tearing free capability define
  #define DRV_LCD_TEARING_VSYNC_MODE_SUPPORT
  #define DRV_LCD_TEARING_VHSYNC_MODE_SUPPORT
  #define DRV_LCD_TEARING_VSYNC_HW_DELAY_MODE_SUPPORT
  //#define DRV_LCD_TEARING_SCANLINE_MODE_SUPPORT

#endif  // #if defined(DRV_LCD_MT6236_SERIES)


// ---------- MT6276 series  ---------- //
#if defined(DRV_LCD_MT6276_SERIES)

  #define LCD_DRIVER_CHIP_SEPARATE
  #define DRV_DISPLAY_DRIVER_V2_SLIM_SUPPORT

  /* Features for LCD */
  #define LCD_ROI_MAX_WIDTH                   (0x7FF)
  #define LCD_ROI_MAX_HEIGHT                  (0x7FF)
  #define LCD_ROI_MAX_OFFSETX                 (0x7FF)
  #define LCD_ROI_MAX_OFFSETY                 (0x7FF)
  #define LCD_LAYER_ORIGIN_X                  (0)
  #define LCD_LAYER_ORIGIN_Y                  (0)
  
  #define LCD_LAYER_MEM_MAX_OFFSETX           (0x7FF)
  #define LCD_LAYER_MEM_MAX_OFFSETY           (0x7FF)
  #define LCD_LAYER_MEM_MAX_PITCH             (0x7FF)

  #define LCD_MEM_OUT_MAX_MAIN_WINDOW_WIDTH   (0x7FF)
  #define LCD_MEM_OUT_MAX_MAIN_WINDOW_HEIGHT  (0x7FF)
  #define LCD_MEM_OUT_MAX_OFFSETX             (0x7FF)
  #define LCD_MEM_OUT_MAX_OFFSETY             (0x7FF)

  #define LCD_BYTE_ALIGN_CNT                  (4)
  #define DRV_GOVL_LAYER_TOTAL_COUNT          (4)
  #define DRV_PARALLEL_INTERFACE_COUNT        (3)
  #define DRV_SERIAL_INTERFACE_COUNT          (1)
  #define DRV_LCD_CMD_QUEUE_COUNT             (2)
  #define DRV_LCD_CMD_QUEUE_NUMBER            (32)

  //Don't remove the 2 options. FOTA will use them.
  #define DRV_LCD_ROI_BACKGROUND_COLOR_RGB888
  #undef DRV_LCD_ROI_BACKGROUND_COLOR_RGB565
  #define DRV_LAYER_DITHER

  #define DRV_LCD_GAMMA_CORRECTION_SUPPORT
  #define DRV_LCD_GAMMA_CORRECTION_QUEUE_NUMBER (256)

  // TODO: To be removed.
  //#define DRV_LCD_SW_MEMORY_OUTPUT_OFFSET_SUPPORT


  /* Features for Image Data Path */
  //#define DRV_LCD_FW_UPDATE_SUPPORT
  #define DRV_LCD_HW_TRIGGER_SUPPORT
  //#define DRV_LCD_DC_TRIGGER_SUPPORT 

  // Feature options for MT6276
  #define LCD_WMEM_PARGB8888 LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA
  //#define LCD_LAYER_SOURCE_COLOR_YUYV422
  //#define LCD_LAYER_SOURCE_COLOR_PARGB8888
  //#define LCD_LAYER_SUPPORT_HW_DITHER
  //#define LCD_LAYER_SUPPORT_PITCH

  //#define __GOVL_SUPPORT__
  //#define DRV_ROT1_DEBUG_SUPPORT
  //#define DRV_GOVL_DEBUG_SUPPORT

   //tearing free capabilities
  #define DRV_LCD_TEARING_VSYNC_MODE_SUPPORT
  #define DRV_LCD_TEARING_VSYNC_HW_DELAY_MODE_SUPPORT

#endif  // #if defined(DRV_LCD_MT6276_SERIES)

#if defined(DRV_LCD_MT6256_SERIES)
  #define DRV_DISPLAY_DRIVER_V2_SLIM_SUPPORT
  
  #define LCD_DRIVER_CHIP_SEPARATE
  
  #define LCD_ROI_MAX_WIDTH                   (0x7FF)
  #define LCD_ROI_MAX_HEIGHT                  (0x7FF)
  #define LCD_ROI_MAX_OFFSETX                 (0x7FF)
  #define LCD_ROI_MAX_OFFSETY                 (0x7FF)
  #define LCD_LAYER_ORIGIN_X                  (0)
  #define LCD_LAYER_ORIGIN_Y                  (0)
  
  #define LCD_LAYER_MEM_MAX_OFFSETX           (0x7FF)
  #define LCD_LAYER_MEM_MAX_OFFSETY           (0x7FF)
  #define LCD_LAYER_MEM_MAX_PITCH             (0x7FF)
  
  #define LCD_MEM_OUT_MAX_MAIN_WINDOW_WIDTH   (0x7FF)
  #define LCD_MEM_OUT_MAX_MAIN_WINDOW_HEIGHT  (0x7FF)
  #define LCD_MEM_OUT_MAX_OFFSETX             (0x7FF)
  #define LCD_MEM_OUT_MAX_OFFSETY             (0x7FF)
  
  #define LCD_BYTE_ALIGN_CNT                  (4)
  #define DRV_GOVL_LAYER_TOTAL_COUNT          (4)
  #define DRV_PARALLEL_INTERFACE_COUNT        (3)
  #define DRV_SERIAL_INTERFACE_COUNT          (2)
  #define  DRV_LCD_CMD_QUEUE_COUNT             1  ///MT6256E2 has only one command queue
  #define  DRV_LCD_CMD_QUEUE_NUMBER            64 ///but queue size is enlarged to 64
  
  
  //Don't remove the 2 options. FOTA will use them.
  #define DRV_LCD_ROI_BACKGROUND_COLOR_RGB888
  #undef DRV_LCD_ROI_BACKGROUND_COLOR_RGB565
  #define DRV_LAYER_DITHER

  //#define DRV_LCD_GAMMA_CORRECTION_SUPPORT
  #define DRV_LCD_GAMMA_CORRECTION_QUEUE_NUMBER (0)
  
  /* Features for Image Data Path */
  //#define DRV_LCD_FW_UPDATE_SUPPORT
  #define DRV_LCD_HW_TRIGGER_SUPPORT
  //#define DRV_LCD_DC_TRIGGER_SUPPORT 
  
  //#define LCD_WMEM_PARGB8888                0x6
  //#define LCD_LAYER_SOURCE_COLOR_YUYV422
  //#define LCD_LAYER_SOURCE_COLOR_PARGB8888
  //#define LCD_LAYER_SUPPORT_HW_DITHER
  //#define LCD_LAYER_SUPPORT_PITCH
  
  //#define __GOVL_SUPPORT__
  //#define DRV_ROT1_DEBUG_SUPPORT
  //#define DRV_GOVL_DEBUG_SUPPORT
  
  /// tearing free capabilities
  #define DRV_LCD_TEARING_VSYNC_MODE_SUPPORT
  //#define DRV_LCD_TEARING_VHSYNC_MODE_SUPPORT
  #define DRV_LCD_TEARING_VSYNC_HW_DELAY_MODE_SUPPORT
  //#define DRV_LCD_TEARING_SCANLINE_MODE_SUPPORT
    
#endif

// ---------- MT6255 series  ---------- //
#if defined(DRV_LCD_MT6255_SERIES)
  #define DRV_DISPLAY_DRIVER_V2_SLIM_SUPPORT
  
  #define LCD_DRIVER_CHIP_SEPARATE
  
  #define LCD_ROI_MAX_WIDTH                   (0x7FF)
  #define LCD_ROI_MAX_HEIGHT                  (0x7FF)
  #define LCD_ROI_MAX_OFFSETX                 (0x7FF)
  #define LCD_ROI_MAX_OFFSETY                 (0x7FF)
  #define LCD_LAYER_ORIGIN_X                  (0)
  #define LCD_LAYER_ORIGIN_Y                  (0)
  
  #define LCD_LAYER_MEM_MAX_OFFSETX           (0x7FF)
  #define LCD_LAYER_MEM_MAX_OFFSETY           (0x7FF)
  #define LCD_LAYER_MEM_MAX_PITCH             (0x7FF)
  
  #define LCD_MEM_OUT_MAX_MAIN_WINDOW_WIDTH   (0x7FF)
  #define LCD_MEM_OUT_MAX_MAIN_WINDOW_HEIGHT  (0x7FF)
  #define LCD_MEM_OUT_MAX_OFFSETX             (0x7FF)
  #define LCD_MEM_OUT_MAX_OFFSETY             (0x7FF)
  
  #define LCD_BYTE_ALIGN_CNT                  (4)
  #define DRV_GOVL_LAYER_TOTAL_COUNT          (4)
  #define DRV_PARALLEL_INTERFACE_COUNT        (3)
  #define DRV_SERIAL_INTERFACE_COUNT          (2)
  #define  DRV_LCD_CMD_QUEUE_COUNT             1  ///E2 has only one command queue
  #define  DRV_LCD_CMD_QUEUE_NUMBER            64 ///but queue size is enlarged to 64  
  
  //Don't remove the 2 options. FOTA will use them.
  #define DRV_LCD_ROI_BACKGROUND_COLOR_RGB888
  #undef DRV_LCD_ROI_BACKGROUND_COLOR_RGB565
  #define DRV_LAYER_DITHER

  //#define DRV_LCD_GAMMA_CORRECTION_SUPPORT
  #define DRV_LCD_GAMMA_CORRECTION_QUEUE_NUMBER (0)
  
  /* Features for Image Data Path */
  //#define DRV_LCD_FW_UPDATE_SUPPORT
  #define DRV_LCD_HW_TRIGGER_SUPPORT
  //#define DRV_LCD_DC_TRIGGER_SUPPORT 
  
  //#define LCD_WMEM_PARGB8888                0x6
  //#define LCD_LAYER_SOURCE_COLOR_YUYV422
  //#define LCD_LAYER_SOURCE_COLOR_PARGB8888
  //#define LCD_LAYER_SUPPORT_HW_DITHER
  //#define LCD_LAYER_SUPPORT_PITCH
  
  //#define __GOVL_SUPPORT__
  //#define DRV_ROT1_DEBUG_SUPPORT
  //#define DRV_GOVL_DEBUG_SUPPORT
  
  /// tearing free capabilities
  #define DRV_LCD_TEARING_VSYNC_MODE_SUPPORT
  //#define DRV_LCD_TEARING_VHSYNC_MODE_SUPPORT
  #define DRV_LCD_TEARING_VSYNC_HW_DELAY_MODE_SUPPORT
  //#define DRV_LCD_TEARING_SCANLINE_MODE_SUPPORT
    
#endif //#if defined(DRV_LCD_MT6255_SERIES)


// ---------- MT6252 series  ---------- //
#if defined(DRV_LCD_MT6252_SERIES)
  
  #define LCD_DRIVER_CHIP_SEPARATE
  #define _WFC_USE_GDI_WORKING_BUFFER // used when landscape UI on portrait LCM, WFC need GDI's working buffer
  #define DRV_DISPLAY_DRIVER_V2_SLIM_SUPPORT

  #if ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__))
  #define SPEECH_LCD_INTERFEFENCE
  #endif

  #define DRV_DISPLAY_FRAMEBUF_32BYTES_ALIGNMENT

  #define LCD_ROI_MAX_WIDTH                  (0x3FF)
  #define LCD_ROI_MAX_HEIGHT                 (0x3FF)
  #define LCD_ROI_MAX_OFFSETX                (0x3FF)
  #define LCD_ROI_MAX_OFFSETY                (0x3FF)
  #define LCD_LAYER_ORIGIN_X                 (0)
  #define LCD_LAYER_ORIGIN_Y                 (0)
  
  #define LCD_LAYER_MEM_MAX_OFFSETX          // useless
  #define LCD_LAYER_MEM_MAX_OFFSETY          // useless
  #define LCD_LAYER_MEM_MAX_PITCH            // useless

  #define LCD_MEM_OUT_MAX_MAIN_WINDOW_WIDTH  (0x3FF)
  #define LCD_MEM_OUT_MAX_MAIN_WINDOW_HEIGHT (0x3FF)
  #define LCD_MEM_OUT_MAX_OFFSETX            (0x3FF)
  #define LCD_MEM_OUT_MAX_OFFSETY            (0x3FF)

  #define LCD_BYTE_ALIGN_CNT                 (4)
  #define DRV_PARALLEL_INTERFACE_COUNT       (2)
  #define DRV_SERIAL_INTERFACE_COUNT         (2)
  #define DRV_LCD_CMD_QUEUE_COUNT            (1)
  #define DRV_LCD_CMD_QUEUE_NUMBER           (32)
  
  #define DRV_LCD_ROI_BACKGROUND_COLOR_RGB888
  #undef DRV_LCD_ROI_BACKGROUND_COLOR_RGB565

  #define DRV_LCD_GAMMA_CORRECTION_QUEUE_NUMBER (64)
  #undef DRV_LCD_FW_UPDATE_SUPPORT
  #define DRV_LCD_HW_TRIGGER_BUG
  #define LCD_LAYER_SUPPORT_HW_DITHER

  /* MT6238/6238 alignment issue */
  #define DRV_LCD_HW_MEMORY_OUTPUT_OFFSET_SUPPORT

  // Default is FW update, No HW Trigger
  #define MDP_FW_TRIGGER_LCD                
  #define DRV_LCD_FW_UPDATE_SUPPORT       

  // TODO : move to sw feature
  #define LCD_LANDSCAPE_UI_ROT_ANGLE_90                      (1)
  #define LCD_LANDSCAPE_UI_ROT_ANGLE_90_PLUS_FLIP            (2)
  #define LCD_LANDSCAPE_UI_ROT_ANGLE_270                     (3)
  #define LCD_LANDSCAPE_UI_ROT_ANGLE_270_PLUS_FLIP           (4)

  #define _WFC_USE_GDI_WORKING_BUFFER
  #if defined(__LANDSCAPE_UI_ON_PORTRAIT_LCM_CCW_ROTATION_ANGLE_270__)
    #define LCD_LANDSCAPE_UI_ROT_ANGLE LCD_LANDSCAPE_UI_ROT_ANGLE_270
  #elif defined(__LANDSCAPE_UI_ON_PORTRAIT_LCM_CCW_ROTATION_ANGLE_90__)
    #define LCD_LANDSCAPE_UI_ROT_ANGLE LCD_LANDSCAPE_UI_ROT_ANGLE_90
  #else
    #define LCD_LANDSCAPE_UI_ROT_ANGLE LCD_LANDSCAPE_UI_ROT_ANGLE_270
  #endif

  //#define DRV_LCD_DIRECT_SENSOR_PER_FRAME_ROI_COMMANDS

  /* Tearing free capability */
  #define DRV_LCD_TEARING_VSYNC_MODE_SUPPORT
  //#define DRV_LCD_TEARING_VHSYNC_MODE_SUPPORT
  #define DRV_LCD_TEARING_VSYNC_HW_DELAY_MODE_SUPPORT
  //#define DRV_LCD_TEARING_SCANLINE_MODE_SUPPORT
  
#endif  // #if defined(DRV_LCD_MT6252_SERIES)

// ---------- MT6280 series  ---------- //
#if defined(DRV_LCD_MT6280_SERIES)
  #define DRV_LCD_NOT_EXIST
  
  #define LCD_DRIVER_CHIP_SEPARATE
  #define _WFC_USE_GDI_WORKING_BUFFER // used when landscape UI on portrait LCM, WFC need GDI's working buffer
  #define DRV_DISPLAY_DRIVER_V2_SLIM_SUPPORT

  #if ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__))
  #define SPEECH_LCD_INTERFEFENCE
  #endif

  #define DRV_DISPLAY_FRAMEBUF_32BYTES_ALIGNMENT

  #define LCD_ROI_MAX_WIDTH                  (0x3FF)
  #define LCD_ROI_MAX_HEIGHT                 (0x3FF)
  #define LCD_ROI_MAX_OFFSETX                (0x3FF)
  #define LCD_ROI_MAX_OFFSETY                (0x3FF)
  #define LCD_LAYER_ORIGIN_X                 (0)
  #define LCD_LAYER_ORIGIN_Y                 (0)
  
  #define LCD_LAYER_MEM_MAX_OFFSETX          // useless
  #define LCD_LAYER_MEM_MAX_OFFSETY          // useless
  #define LCD_LAYER_MEM_MAX_PITCH            // useless

  #define LCD_MEM_OUT_MAX_MAIN_WINDOW_WIDTH  (0x3FF)
  #define LCD_MEM_OUT_MAX_MAIN_WINDOW_HEIGHT (0x3FF)
  #define LCD_MEM_OUT_MAX_OFFSETX            (0x3FF)
  #define LCD_MEM_OUT_MAX_OFFSETY            (0x3FF)

  #define LCD_BYTE_ALIGN_CNT                 (4)
  #define DRV_PARALLEL_INTERFACE_COUNT       (2)
  #define DRV_SERIAL_INTERFACE_COUNT         (2)
  #define DRV_LCD_CMD_QUEUE_COUNT            (1)
  #define DRV_LCD_CMD_QUEUE_NUMBER           (32)
  
  #define DRV_LCD_ROI_BACKGROUND_COLOR_RGB888
  #undef DRV_LCD_ROI_BACKGROUND_COLOR_RGB565

  #define DRV_LCD_GAMMA_CORRECTION_QUEUE_NUMBER (64)
  #undef DRV_LCD_FW_UPDATE_SUPPORT
  #define DRV_LCD_HW_TRIGGER_BUG
  #define LCD_LAYER_SUPPORT_HW_DITHER

  /* MT6238/6238 alignment issue */
  #define DRV_LCD_HW_MEMORY_OUTPUT_OFFSET_SUPPORT

  // Default is FW update, No HW Trigger
  #define MDP_FW_TRIGGER_LCD                
  #define DRV_LCD_FW_UPDATE_SUPPORT       

  // TODO : move to sw feature
  #define LCD_LANDSCAPE_UI_ROT_ANGLE_90                      (1)
  #define LCD_LANDSCAPE_UI_ROT_ANGLE_90_PLUS_FLIP            (2)
  #define LCD_LANDSCAPE_UI_ROT_ANGLE_270                     (3)
  #define LCD_LANDSCAPE_UI_ROT_ANGLE_270_PLUS_FLIP           (4)

  #define _WFC_USE_GDI_WORKING_BUFFER
  #if defined(__LANDSCAPE_UI_ON_PORTRAIT_LCM_CCW_ROTATION_ANGLE_270__)
    #define LCD_LANDSCAPE_UI_ROT_ANGLE LCD_LANDSCAPE_UI_ROT_ANGLE_270
  #elif defined(__LANDSCAPE_UI_ON_PORTRAIT_LCM_CCW_ROTATION_ANGLE_90__)
    #define LCD_LANDSCAPE_UI_ROT_ANGLE LCD_LANDSCAPE_UI_ROT_ANGLE_90
  #else
    #define LCD_LANDSCAPE_UI_ROT_ANGLE LCD_LANDSCAPE_UI_ROT_ANGLE_270
  #endif

  //#define DRV_LCD_DIRECT_SENSOR_PER_FRAME_ROI_COMMANDS

  /* Tearing free capability */
  #define DRV_LCD_TEARING_VSYNC_MODE_SUPPORT
  //#define DRV_LCD_TEARING_VHSYNC_MODE_SUPPORT
  #define DRV_LCD_TEARING_VSYNC_HW_DELAY_MODE_SUPPORT
  //#define DRV_LCD_TEARING_SCANLINE_MODE_SUPPORT
  
#endif  // #if defined(DRV_LCD_MT6280_SERIES)


// ---------- TK6280 series  ---------- //
#if defined(DRV_LCD_TK6280_SERIES)
  
  // chip separate option
  #if defined(MT6270A)
    #undef LCD_DRIVER_CHIP_SEPARATE
  #else   // default case
    #define LCD_DRIVER_CHIP_SEPARATE
    #define DRV_DISPLAY_DRIVER_V2_SLIM_SUPPORT
  #endif  // chip options

  #if defined(MT6270A)
    // For No LCM included in MT6270A load. If LCM is included, we shall remove the definition.
    #define  MAIN_LCD_OUTPUT_FORMAT LCM_18BIT_18_BPP_RGB666_1
  #endif

  #define LCD_ROI_MAX_WIDTH                  (0x3FF)
  #define LCD_ROI_MAX_HEIGHT                 (0x3FF)
  #define LCD_ROI_MAX_OFFSETX                (0x3FF)
  #define LCD_ROI_MAX_OFFSETY                (0x3FF)
  #define LCD_LAYER_ORIGIN_X                 (0)
  #define LCD_LAYER_ORIGIN_Y                 (0)
  
  #define LCD_LAYER_MEM_MAX_OFFSETX          // useless
  #define LCD_LAYER_MEM_MAX_OFFSETY          // useless
  #define LCD_LAYER_MEM_MAX_PITCH            // useless
  
  #define LCD_MEM_OUT_MAX_MAIN_WINDOW_WIDTH  (0x3FF)
  #define LCD_MEM_OUT_MAX_MAIN_WINDOW_HEIGHT (0x3FF)
  #define LCD_MEM_OUT_MAX_OFFSETX            (0x3FF)
  #define LCD_MEM_OUT_MAX_OFFSETY            (0x3FF)

  #define DRV_PARALLEL_INTERFACE_COUNT       (3)
  #define DRV_SERIAL_INTERFACE_COUNT         (1)
  #define DRV_LCD_CMD_QUEUE_COUNT            (2)
  #define DRV_LCD_CMD_QUEUE_NUMBER           (32)
  
  #define DRV_LCD_ROI_BACKGROUND_COLOR_RGB888
  #undef DRV_LCD_ROI_BACKGROUND_COLOR_RGB565
  #define DRV_LCD_HW_TRIGGER_BUG
  #define DRV_LCD_LOW_FRAME_RATE_ISSUE

  #define DRV_LCD_GAMMA_CORRECTION_SUPPORT
  #define DRV_LCD_GAMMA_CORRECTION_QUEUE_NUMBER (256)
  #define DRV_LCD_HW_TRIGGER_SUPPORT
  #define DRV_LCD_DC_TRIGGER_SUPPORT
  #undef DRV_LCD_FW_UPDATE_SUPPORT
  
  /* MT6238/6238 alignment issue */
  // TODO: MT6268 LCD Driver owner please help to check this!

 //Dong: need to check this for TK6280
 /*
  #if defined(MT6268)
    #undef DRV_LCD_SW_MEMORY_OUTPUT_OFFSET_SUPPORT
    #define DRV_LCD_HW_MEMORY_OUTPUT_OFFSET_SUPPORT
  #elif defined(MT6268A) || defined(MT6268H) || defined(MT6268T)
    #define DRV_LCD_SW_MEMORY_OUTPUT_OFFSET_SUPPORT
  #else   // default case
  */
    #define DRV_LCD_SW_MEMORY_OUTPUT_OFFSET_SUPPORT
//  #endif  // chip options

  /* Tearing free capability */
  #define DRV_LCD_TEARING_VSYNC_MODE_SUPPORT
  #define DRV_LCD_TEARING_VHSYNC_MODE_SUPPORT
  //#define DRV_LCD_TEARING_VSYNC_HW_DELAY_MODE_SUPPORT
  //#define DRV_LCD_TEARING_SCANLINE_MODE_SUPPORT
#endif  // #if defined(DRV_LCD_TK6280_SERIES)


// ---------- MT6573 series ---------- //
#if defined(DRV_LCD_MT6573_SERIES)

  #undef LCD_DRIVER_CHIP_SEPARATE
  #define DRV_LCD_NOT_EXIST
  //#define __GOVL_SUPPORT__
  //#define DRV_ROT1_DEBUG_SUPPORT
  //#define DRV_GOVL_DEBUG_SUPPORT
  #define LCD_DRIVER_STANDALONE
  /* Features for LCD */
  #define  LCD_ROI_MAX_WIDTH                   0x7FF
  #define  LCD_ROI_MAX_HEIGHT                  0x7FF
  #define  LCD_ROI_MAX_OFFSETX                 0x7FF
  #define  LCD_ROI_MAX_OFFSETY                 0x7FF
  #define  LCD_LAYER_MEM_MAX_OFFSETX           0x7FF
  #define  LCD_LAYER_MEM_MAX_OFFSETY           0x7FF
  #define  LCD_LAYER_MEM_MAX_PITCH             0x7FF
  
  #define  LCD_MEM_OUT_MAX_MAIN_WINDOW_WIDTH   0x7FF
  #define  LCD_MEM_OUT_MAX_MAIN_WINDOW_HEIGHT  0x7FF
  #define  LCD_MEM_OUT_MAX_OFFSETX             0x7FF
  #define  LCD_MEM_OUT_MAX_OFFSETY             0x7FF
  
  #define DRV_GOVL_LAYER_TOTAL_COUNT   4
  #define DRV_PARALLEL_INTERFACE_COUNT  1
  #define DRV_LCD_CMD_QUEUE_COUNT 2
  #define DRV_LCD_CMD_QUEUE_NUMBER 32
  
  // To be removed:
  //#define DRV_LCD_ROI_BACKGROUND_COLOR_RGB888
  //#undef DRV_LCD_ROI_BACKGROUND_COLOR_RGB565
  
  #define DRV_LCD_GAMMA_CORRECTION_SUPPORT
  #define DRV_LCD_GAMMA_CORRECTION_QUEUE_NUMBER 256
  
  // To be removed:
  //#define DRV_LCD_SW_MEMORY_OUTPUT_OFFSET_SUPPORT
  
  /* Features for Image Data Path */
  //#define DRV_LCD_FW_UPDATE_SUPPORT
  #define DRV_LCD_HW_TRIGGER_SUPPORT
  //#define DRV_LCD_DC_TRIGGER_SUPPORT 

#endif  // #if defined(DRV_LCD_MT6573_SERIES)


/******************************************************************************
 * Section for GOVL
 ******************************************************************************/
// ---------- MT6236 series ---------- //
#if defined(DRV_LCD_MT6236_SERIES)

  #define GOVL_ROI_COORDINATE_ORIGIN_X         (1024)
  #define GOVL_ROI_COORDINATE_ORIGIN_Y         (1024)
  #define GOVL_ROI_MAX_WIDTH                   (0x7FF)
  #define GOVL_ROI_MAX_HEIGHT                  (0x7FF)
  #define GOVL_ROI_MAX_OFFSETX                 (0x7FF)
  #define GOVL_ROI_MAX_OFFSETY                 (0x7FF)
  #define GOVL_LAYER_MAX_WIDTH                 (0x7FF)
  #define GOVL_LAYER_MAX_HEIGHT                (0x7FF)
  #define GOVL_LAYER_MAX_OFFSETX               (0x7FF)
  #define GOVL_LAYER_MAX_OFFSETY               (0x7FF)
  #define GOVL_LAYER_MAX_ALPHA                 (0xFF)

  #define GOVL_LAYER_MEM_MAX_OFFSETX           (0x7FF)
  #define GOVL_LAYER_MEM_MAX_OFFSETY           (0x7FF)
  #define GOVL_LAYER_MEM_MAX_PITCH             (0x7FF)         
  #define GOVL_MEM_OUT_MAX_MAIN_WINDOW_WIDTH   (0x7FF)
  #define GOVL_MEM_OUT_MAX_MAIN_WINDOW_HEIGHT  (0x7FF)
  #define GOVL_MEM_OUT_MAX_OFFSETX             (0x7FF)
  #define GOVL_MEM_OUT_MAX_OFFSETY             (0x7FF)
  #define GOVL_LAYER_MIN_OFFSETX               (0)
  #define GOVL_LAYER_MIN_OFFSETY               (0)
  
  #define DRV_GOVL_LAYER_TOTAL_COUNT           (4)
  #define GOVL_BYTE_ALIGN_COUNT                (4)

#endif  // #if defined(DRV_LCD_MT6236_SERIES)


// ---------- MT6276 series ---------- //
#if defined(DRV_LCD_MT6276_SERIES)

  #define GOVL_ROI_COORDINATE_ORIGIN_X          (0)
  #define GOVL_ROI_COORDINATE_ORIGIN_Y          (0)
  #define GOVL_ROI_MAX_WIDTH                    (0x7FF)
  #define GOVL_ROI_MAX_HEIGHT                   (0x7FF)
  #define GOVL_ROI_MAX_OFFSETX                  (0x7FF)
  #define GOVL_ROI_MAX_OFFSETY                  (0x7FF)
  #define GOVL_LAYER_MAX_WIDTH                  (0x7FF)
  #define GOVL_LAYER_MAX_HEIGHT                 (0x7FF)
  #define GOVL_LAYER_MAX_OFFSETX                (0x7FF)
  #define GOVL_LAYER_MAX_OFFSETY                (0x7FF)
  #define GOVL_LAYER_MIN_OFFSETX                (-2048)
  #define GOVL_LAYER_MIN_OFFSETY                (-2048)

  #define GOVL_LAYER_MAX_ALPHA                  (0xFF)

  #define GOVL_LAYER_MEM_MAX_OFFSETX            (0x7FF) // Layer memory offset is not in use in MT6276 GOVL
  #define GOVL_LAYER_MEM_MAX_OFFSETY            (0x7FF) // Layer memory offset is not in use in MT6276 GOVL
  #define GOVL_LAYER_MEM_MAX_PITCH              (0x7FF) // The unit is pixel not byte
  #define GOVL_MEM_OUT_MAX_MAIN_WINDOW_WIDTH    (0x7FF)
  #define GOVL_MEM_OUT_MAX_MAIN_WINDOW_HEIGHT   (0x7FF)
  #define GOVL_MEM_OUT_MAX_OFFSETX              (0x7FF)
  #define GOVL_MEM_OUT_MAX_OFFSETY              (0x7FF)
  #define DRV_GOVL_LAYER_TOTAL_COUNT            (4)
  #define GOVL_BYTE_ALIGN_COUNT                 (4)

#endif  // #if defined(DRV_LCD_MT6276_SERIES)

// ---------- MT6255 series ---------- //
#if defined(DRV_LCD_MT6255_SERIES)

  #define GOVL_ROI_COORDINATE_ORIGIN_X          (0)
  #define GOVL_ROI_COORDINATE_ORIGIN_Y          (0)
  #define GOVL_ROI_MAX_WIDTH                    (0x7FF)
  #define GOVL_ROI_MAX_HEIGHT                   (0x7FF)
  #define GOVL_ROI_MAX_OFFSETX                  (0x7FF)
  #define GOVL_ROI_MAX_OFFSETY                  (0x7FF)
  #define GOVL_LAYER_MAX_WIDTH                  (0x7FF)
  #define GOVL_LAYER_MAX_HEIGHT                 (0x7FF)
  #define GOVL_LAYER_MAX_OFFSETX                (0x7FF)
  #define GOVL_LAYER_MAX_OFFSETY                (0x7FF)
  #define GOVL_LAYER_MIN_OFFSETX                (-2048)
  #define GOVL_LAYER_MIN_OFFSETY                (-2048)

  #define GOVL_LAYER_MAX_ALPHA                  (0xFF)

  #define GOVL_LAYER_MEM_MAX_OFFSETX            (0x7FF) // Layer memory offset is not in use in MT6276 GOVL
  #define GOVL_LAYER_MEM_MAX_OFFSETY            (0x7FF) // Layer memory offset is not in use in MT6276 GOVL
  #define GOVL_LAYER_MEM_MAX_PITCH              (0x7FF) // The unit is pixel not byte
  #define GOVL_MEM_OUT_MAX_MAIN_WINDOW_WIDTH    (0x7FF)
  #define GOVL_MEM_OUT_MAX_MAIN_WINDOW_HEIGHT   (0x7FF)
  #define GOVL_MEM_OUT_MAX_OFFSETX              (0x7FF)
  #define GOVL_MEM_OUT_MAX_OFFSETY              (0x7FF)
  #define DRV_GOVL_LAYER_TOTAL_COUNT            (4)
  #define GOVL_BYTE_ALIGN_COUNT                 (4)

#endif  // #if defined(DRV_LCD_MT6255_SERIES)



/******************************************************************************
 * Section for TV OUT
 ******************************************************************************/
#if defined(DRV_TVOUT_6238_SERIES)

#endif  // #if defined(DRV_TVOUT_6238_SERIES)

/*For Modis*/
#else  //#if defined(__MTK_TARGET__)

#define DRV_DISPLAY_DRIVER_V2_SLIM_SUPPORT

//#define WFD_LCD_ADAPTER_SUPPORT

/* Features for LCD */
#define LCD_ROI_MAX_WIDTH                   (0x7FF)
#define LCD_ROI_MAX_HEIGHT                  (0x7FF)
#define LCD_ROI_MAX_OFFSETX                 (0x7FF)
#define LCD_ROI_MAX_OFFSETY                 (0x7FF)
#define LCD_LAYER_ORIGIN_X                  (0)
#define LCD_LAYER_ORIGIN_Y                  (0)

#define LCD_LAYER_MEM_MAX_OFFSETX           (0x7FF)
#define LCD_LAYER_MEM_MAX_OFFSETY           (0x7FF)
#define LCD_LAYER_MEM_MAX_PITCH             (0x7FF)

#define LCD_MEM_OUT_MAX_MAIN_WINDOW_WIDTH   (0x7FF)
#define LCD_MEM_OUT_MAX_MAIN_WINDOW_HEIGHT  (0x7FF)
#define LCD_MEM_OUT_MAX_OFFSETX             (0x7FF)
#define LCD_MEM_OUT_MAX_OFFSETY             (0x7FF)

#define LCD_BYTE_ALIGN_CNT                  (4)
#define DRV_PARALLEL_INTERFACE_COUNT        (3)
#define DRV_SERIAL_INTERFACE_COUNT          (1)
#define DRV_LCD_CMD_QUEUE_COUNT             (2)
#define DRV_LCD_CMD_QUEUE_NUMBER            (32)

//Don't remove the 2 options. FOTA will use them.
#define DRV_LCD_ROI_BACKGROUND_COLOR_RGB888
#undef DRV_LCD_ROI_BACKGROUND_COLOR_RGB565
//#define DRV_LAYER_DITHER

#define DRV_LCD_GAMMA_CORRECTION_SUPPORT
#define DRV_LCD_GAMMA_CORRECTION_QUEUE_NUMBER (256)

// TODO: The following To be removed:
//#define DRV_LCD_SW_MEMORY_OUTPUT_OFFSET_SUPPORT

/* Features for Image Data Path */
//#define DRV_LCD_FW_UPDATE_SUPPORT
#define DRV_LCD_HW_TRIGGER_SUPPORT
//#define DRV_LCD_DC_TRIGGER_SUPPORT 

// Feature options for MT6236
#define LCD_WMEM_PARGB8888 LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA
//#define LCD_LAYER_SOURCE_COLOR_YUYV422
//#define LCD_LAYER_SOURCE_COLOR_PARGB8888
#define LCD_LAYER_SUPPORT_HW_DITHER
#define LCD_LAYER_SUPPORT_PITCH

//#define __GOVL_SUPPORT__
//#define DRV_ROT1_DEBUG_SUPPORT
//#define DRV_GOVL_DEBUG_SUPPORT

// Tearing free capability define

//#define DRV_LCD_TEARING_SCANLINE_MODE_SUPPORT

#endif  //#if defined(__MTK_TARGET__)

#endif  // __DRV_FEATURES_DISPLAY_H__
