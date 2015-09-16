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
 *    drv_features_mmsysmisc.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file defines driver feature options for 
 *      1. MM power control 
 *      2. MM internal memory manager
 *    According to chip series.
 *    This file should only be included by HAL modules and should not be 
 *    included by non-HAL modules.
 *    \todo consider to remove DRV_FEATURE__MM_POWER_CTRL_IF since API should be 
 *          the same in when HAL
 *    \todo consider to remove DRV_FEATURE__MM_INTMEM_IF since API should be the 
 *          same when in HAL
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
#ifndef __DRV_FEATURES_MMSYSMISC_H__
#define __DRV_FEATURES_MMSYSMISC_H__

/******************************************************************************
 * Documentation
 ******************************************************************************/

/******************************************************************************
 * Include directives
 ******************************************************************************/
#include "drv_features_chip_select.h"

/******************************************************************************
 * Section for MM power control
 ******************************************************************************/
#if defined(DRV_MM_POWER_CTRL_MT6236_SERIES)
  /**
   *  \def DRV_FEATURE__MM_POWER_CTRL_IF
   *  If this is defined, mm_power_ctrl driver exists in the project. 
   *  The interface defined interface\hwdrv\in mm_power_ctrl.h is supported on 
   *  this HW platform.
   */
  #define DRV_FEATURE__MM_POWER_CTRL_IF
  /**
   *  \def MM_POWER_CTRL_PATCH_WHQA_00003723
   *  Patch for WHQA_00003723.
   *  \remark We only put feature options here if it is used outside of 
   *          MM power control driver.
   */
  #define MM_POWER_CTRL_PATCH_WHQA_00003723
#endif  // #if defined(DRV_MM_POWER_CTRL_MT6236_SERIES)

#if defined(DRV_MM_POWER_CTRL_MT6252_SERIES)
  /**
   *  \def DRV_FEATURE__MM_POWER_CTRL_IF
   *  If this is defined, mm_power_ctrl driver exists in the project. 
   *  The interface defined interface\hwdrv\in mm_power_ctrl.h is supported on 
   *  this HW platform.
   */
  #define DRV_FEATURE__MM_POWER_CTRL_IF
#endif  // #if defined(DRV_MM_POWER_CTRL_MT6252_SERIES)

#if defined(DRV_MM_POWER_CTRL_MT6276_SERIES)
  /**
   *  \def DRV_FEATURE__MM_POWER_CTRL_IF
   *  If this is defined, mm_power_ctrl driver exists in the project. 
   *  The interface defined interface\hwdrv\in mm_power_ctrl.h is supported on 
   *  this HW platform.
   */
  #define DRV_FEATURE__MM_POWER_CTRL_IF
#endif  // #if defined(DRV_MM_POWER_CTRL_MT6276_SERIES)

#if defined(DRV_MMSYSMISC_MT6255_SERIES)
  /**
   *  \def DRV_FEATURE__MM_POWER_CTRL_IF
   *  If this is defined, mm_power_ctrl driver exists in the project. 
   *  The interface defined interface\hwdrv\in mm_power_ctrl.h is supported on 
   *  this HW platform.
   */
  #define DRV_FEATURE__MM_POWER_CTRL_IF
#endif  // #if defined(DRV_MMSYSMISC_MT6255_SERIES)
#if defined(DRV_MMSYSMISC_MT6256_SERIES)
  /**
   *  \def DRV_FEATURE__MM_POWER_CTRL_IF
   *  If this is defined, mm_power_ctrl driver exists in the project. 
   *  The interface defined interface\hwdrv\in mm_power_ctrl.h is supported on 
   *  this HW platform.
   */
  #define DRV_FEATURE__MM_POWER_CTRL_IF
#endif  // #if defined(DRV_MMSYSMISC_MT6256_SERIES)

/******************************************************************************
 * Section for MM internal memory
 ******************************************************************************/
#if defined(DRV_MM_INTMEM_MT6236_SERIES)
  /**
   *  \def DRV_FEATURE__MM_INTMEM_IF
   *  If this feature option is defined, mm_intmem driver IF and some 
   *  implementation exists (maybe dummy functions).
   *  This is not wrapped by __MTK_TARGET__ for build pass on MoDIS
   *  \remark Dummy functions are defined in mcu\MoDIS\drv_sim\src\w32_dummy_drv.c 
   *          under this feature option.
   */
  #define DRV_FEATURE__MM_INTMEM_IF

  // TODO: remove this segment
  #if defined(__MTK_TARGET__)
    /**
     *  \def DRV_FEATURE__MM_INTMEM_IMPL_MT6236
     *  If this feature option is defined, implementation for MT6236 BB exists.
     *  \remark The user of mm_intmem should not depends on this feature option!
     */
    #define DRV_FEATURE__MM_INTMEM_IMPL_MT6236
  #endif  // #if defined(__MTK_TARGET__)
#endif  // #if defined(DRV_MM_INTMEM_MT6236_SERIES)

#if defined(DRV_MM_INTMEM_MT6276_SERIES)
  /**
   *  \def DRV_FEATURE__MM_INTMEM_IF
   *  If this feature option is defined, mm_intmem driver IF and some 
   *  implementation exists (maybe dummy functions).
   *  This is not wrapped by __MTK_TARGET__ for build pass on MoDIS
   *  \remark Dummy functions are defined in mcu\MoDIS\drv_sim\src\w32_dummy_drv.c 
   *          under this feature option.
   */
  #define DRV_FEATURE__MM_INTMEM_IF

  // TODO: remove this segment
  #if defined(__MTK_TARGET__)
    /**
     *  \def DRV_FEATURE__MM_INTMEM_IMPL_MT6276
     *  If this feature option is defined, implementation for MT6276 BB exists.
     *  \remark The user of mm_intmem should not depends on this feature option!
     */
    #define DRV_FEATURE__MM_INTMEM_IMPL_MT6276
  #endif  // #if defined(__MTK_TARGET__)
#endif  // #if defined(DRV_MM_INTMEM_MT6276_SERIES)

#if defined(DRV_MMSYSMISC_MT6255_SERIES)
  /**
   *  \def DRV_FEATURE__MM_INTMEM_IF
   *  If this feature option is defined, mm_intmem driver IF and some 
   *  implementation exists (maybe dummy functions).
   *  This is not wrapped by __MTK_TARGET__ for build pass on MoDIS
   *  \remark Dummy functions are defined in 
   *          mcu\MoDIS\drv_sim\src\w32_dummy_drv.c under this feature option.
   */
  #define DRV_FEATURE__MM_INTMEM_IF

  // TODO: remove this segment
  #if defined(__MTK_TARGET__)
    /**
     *  \def DRV_FEATURE__MM_INTMEM_IMPL_MT6255
     *  If this feature option is defined, implementation for MT6255 BB exists.
     *  \remark The user of mm_intmem should not depends on this feature option!
     */
    #define DRV_FEATURE__MM_INTMEM_IMPL_MT6255
  #endif // #if defined(__MTK_TARGET__)
#endif  // #if defined(DRV_MMSYSMISC_MT6255_SERIES)

#if defined(DRV_MMSYSMISC_MT6256_SERIES)
  /**
   *  \def DRV_FEATURE__MM_INTMEM_IF
   *  If this feature option is defined, mm_intmem driver IF and some 
   *  implementation exists (maybe dummy functions).
   *  This is not wrapped by __MTK_TARGET__ for build pass on MoDIS
   *  \remark Dummy functions are defined in 
   *          mcu\MoDIS\drv_sim\src\w32_dummy_drv.c under this feature option.
   */
  #define DRV_FEATURE__MM_INTMEM_IF

  // TODO: remove this segment
  #if defined(__MTK_TARGET__)
    /**
     *  \def DRV_FEATURE__MM_INTMEM_IMPL_MT6256
     *  If this feature option is defined, implementation for MT6256 BB exists.
     *  \remark The user of mm_intmem should not depends on this feature option!
     */
    #define DRV_FEATURE__MM_INTMEM_IMPL_MT6256
  #endif // #if defined(__MTK_TARGET__)
#endif  // #if defined(DRV_MMSYSMISC_MT6256_SERIES)

/******************************************************************************
 * Section for MM visual hisr
 ******************************************************************************/

#if defined(MT6236) || defined(MT6236)
#define __MULTIMEDIA_HISR__
#endif

#if defined(MT6252) || defined(MT6252H)
#define __MULTIMEDIA_HISR__
#endif

#if defined(MT6256) 
#define __MULTIMEDIA_HISR__
#endif

#if defined(MT6255) 
#define __MULTIMEDIA_HISR__
#endif

#if defined(MT6276)
#define __MULTIMEDIA_HISR__
#endif

#endif  // __DRV_FEATURES_MMSYSMISC_H__

