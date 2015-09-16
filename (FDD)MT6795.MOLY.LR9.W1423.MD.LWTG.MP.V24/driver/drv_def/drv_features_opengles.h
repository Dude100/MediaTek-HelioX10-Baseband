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
 *    drv_features_opengles.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for all opengles driver feature options.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DRV_FEATURES_OPENGLES_H__
#define __DRV_FEATURES_OPENGLES_H__

#include "drv_features_chip_select.h"

/* OPENGLES1.1 and OPENGLES2.0 FEATURES */
#if defined(__MTK_TARGET__) && defined(__DRV_GRAPHICS_OPENGLES_HW_SUPPORT__) && defined(__OPENGLES_SUPPORT__)               
        #define __DRV_MALI400MP_OPENGLES_SUPPORT__  /// compiler option use to wrap all mali driver
                    
        /// driver internal debug compiler option, 
        /// enable this compiler option and set debug level to log information to log buffer.
        /// #define MALI_DEBUG            
        #define MALI_DEBUG_LEVEL 4  /// debug        
        
        /// define the following flag to ensure some important pointer assert check
        /// if MALI_DEBUG is defined, this flag will not take effect.
        #define MALI_ASSERT_CHECK_ENABLE
        
        /// * Suggested range for the DEBUG-LEVEL is [1:6] where
        /// * [1:2] Is messages with highest priority, indicate possible errors.
        /// * [3:4] Is messages with medium priority, output important variables.
        /// * [5:6] Is messages with low priority, used during extensive debugging.              
        
        #if defined(MALI_DEBUG)
            #define MALI_TURN_ON_DBG_PRINT_BUFFER
        #endif 

        /// mali driver internal feature option
        #define USING_MALI400               
        #define MALI_USE_GLES_1             1
        #define MALI_USE_GLES_2             1
        
        #if defined(MALI_USE_GLES_1)
            #define USING_SHADER_GENERATOR        
        #endif
                
        #define MALI_EGL_GLES_MAJOR_VERSION 2
        
        #define MALI400_HWVER               0x0101  /// using driver r2p1 version     
        #define MALI300_HWVER               0x0000
        
        #define MAX_PP_SPLIT_COUNT          1        
        #define MALI_USE_UNIFIED_MEMORY_PROVIDER   0
        #define USING_MMU                   
        #define USING_MALI400_L2_CACHE      1
        #define MALI_HOSTLIB_INDIRECT       1     
        #define MALI_MONOLITHIC                        
        #define MALI_EGL_MAJOR_VERSION      1
        #define MALI_EGL_MINOR_VERSION      4
        #define MALI_GLES_1_MAJOR_VERSION   1
        #define MALI_GLES_1_MINOR_VERSION   1
        #define MALI_GLES_2_MAJOR_VERSION   2
        #define MALI_GLES_2_MINOR_VERSION   0
        #define MALI_VG_MAJOR_VERSION       1
        #define MALI_VG_MINOR_VERSION       1       
        
        /// EGL define
        #define EGL_MALI_GLES
        /// #define EGL_USE_VSYNC
        /// #define MALI_MONOLITHIC
        #define EGL_PLATFORM_LOCKSURFACE_SUPPORTED  1
        #define EGL_KHR_image_ENABLE                1
        #define EGL_KHR_reusable_sync_ENABLE        1
        #define EGL_KHR_lock_surface_ENABLE         1
        
        /// #define MALI_INSTRUMENTED           1
        /// #define MALI_MEMORY_PROFILING
        /// #define MALI_API_TRACE              1
        /// #define EGL_BACKEND_FBDEV           
        /// #define MALI_DUMP_ENABLE
        /// #define USING_MALI_PMM                
        /// #define __MALI_DRV_PROFILING_ENABLE__        
        /// #define __MALI_MAUI_SOFTWARE_LA_ANALYSIS__    
        /// #define __MALI_FBO_CHECK_ENABLE__
        /// #define __MALI_ENABLE_NULL_DRIVER_TEST__             
            
#else   /// For MoDIS platform development    
        #if defined(__DRV_GRAPHICS_OPENGLES_HW_SUPPORT__)
            #undef __DRV_MALI400MP_OPENGLES_SUPPORT__        
        #endif
        
        #define __GLES20_PC_EMULATOR_SUPPORT__     
        #define __GLES11_PC_EMULATOR_SUPPORT__                
#endif

#if !defined(__MTK_TARGET__) || defined(__UL1_STANDALONE__) || defined(__L1_STANDALONE__)
   #undef __DRV_GRAPHICS_OPENGLES_HW_SUPPORT__    
#endif   

#endif /// __DRV_FEATURES_OPENGLES_H__
