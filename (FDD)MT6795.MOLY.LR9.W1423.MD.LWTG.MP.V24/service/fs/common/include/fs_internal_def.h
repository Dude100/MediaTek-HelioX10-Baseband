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
 *   fs_internal_def.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides MTK file system internal definitions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _FS_INTERNAL_DEF_H
#define _FS_INTERNAL_DEF_H

/*-----------------------------------
 * Included Header Files
 *-----------------------------------*/

#if defined(__ARM_FPUV2__) && !defined(__FS_CARD_DOWNLOAD__)
    #define __FS_XDATA_MEMORY_NOT_IN_STACK__
#endif

#if !defined(__FS_CARD_DOWNLOAD__) && !defined(LOW_COST_SUPPORT) && !defined(__FS_IO_STATISTICS__)
    #define __FS_IO_STATISTICS__
#endif

#ifdef __FS_OPEN_HINT__
    #ifdef __FS_CARD_DOWNLOAD__
        #undef __FS_OPEN_HINT__
    #endif
#endif

#ifdef __FS_DEDICATED_BUFFER__
    #define __FS_INTERVAL_BUFFER__
    #ifdef __FS_CARD_DOWNLOAD__
        #undef __FS_DEDICATED_BUFFER__
    #endif
#endif

#ifdef FS_MAX_DISK_SIZE
    #if (FS_MAX_DISK_SIZE > 0)
        #define __FS_LIMITED_DISK_SIZE__
    #endif
#endif


/*-------------------------------------
 * Definitions by Segmentation
 *-------------------------------------*/

//--- Slim ---
#if defined(LOW_COST_SUPPORT)   // Defined for both common and ULC low-cost projects
    #if !defined(__FS_SLIM__)
    #define __FS_SLIM__
    #endif
#endif  // LOW_COST_SUPPORT

#ifdef __FS_SLIM__  // for slim development

    // Slim FMGR
    #if !defined(__FS_CARD2_SUPPORT__)  // disable Slim FMGR for Dual T-Card SQC (Will be reviewed in MP version)
    #define __FS_SLIM_VOLUME_LABEL__
    #define __FS_SLIM_SOFT_UNMOUNT__
    #endif

    // Static compile option
    #define __FS_SLIM_RTFINIT__
    #define __FS_SLIM_CHECKSTACK__

    // De-feature (Keep the compile options and codes)
    #define __FS_SLIM_PHYSICAL_DRIVE__
    #define __FS_SLIM_EXTENDED_PARTITION__
    #define __FS_SLIM_CHECK_DIR__
    #define __FS_SLIM_CRITICAL_ERROR_HDR__

    // Change feature (Keep the compile options and codes)
    #if !defined(__BOOT_FAT_RESET__)
    #define __FS_SLIM_LOW_LEVEL_FORMAT__
    #endif

    #if !defined(__OTG_ENABLE__)
    #define __FS_SLIM_OTG__
    #endif

    // Wait for related design
    //#define __FS_SLIM_QUOTA_CONFIG_CHECK__

#endif // __FS_SLIM__

//--- Ultra low-cost ---

#ifdef __LOW_COST_SUPPORT_ULC__
   #define __FS_PROPRIETARY_SET__

   #if !defined(__FS_CARD_SUPPORT__)
      #define __FS_PATH_LENGTH_LIMITED__
      #define __NOT_SUPPORT_FAT32__         // FAT32 can be disabled only if memory card is NOT supported.
   #endif
#endif

//--- FMT service ---

#ifndef FMT_NOT_PRESENT
    #define __FS_FMT_SERVICE__ // File Manager is supported
#endif

//--- USB Mass Storage Service ---

#if defined(__USB_ENABLE__) && defined(__USB_MASS_STORAGE_ENABLE__)
    #define __FS_USB_MASS_STORAGE_SERVICE__
#endif

//--- Memory Card Service ---

#if defined(__FS_CARD_SUPPORT__)
    #define __FS_MEMORY_CARD_SERVICE__
#endif

/*-------------------------------------
 * Definitions by Features
 *-------------------------------------*/

//--- Asynchronous Interface ---

/*
 * Feature option in makefile: FS_ASYNC_SERVICE = TRUE / FALSE
 * compile option: __FS_ASYNC_SUPPORT__
 * Dependency rule:
 */

#if defined(__FS_ASYNC_SUPPORT__)
    #define __FS_ASYNC_SUPPORT_TASK__
#else
    #define __FS_ASYNC_SUPPORT_ALONE__
#endif
//--- Encoding ---

/*---------------------------------------------------------------------------
 * FS Native Encoding Transparent
 *
 * If this feature is enabled, FS will generate valid ASCII characters by formula
 * for SFN and ignore any native encoding settings.
 *
 * FS will assume that applications always use enough buffer, say 260 WCHAR, to
 * retrieve file names. If buffer for file name is suffiecient, FS will always
 * returns LFN if it is existed. Note that if applications use insufficient buffer,
 * it will get SFN and users may be confused because SFN and LFN may look different.
 ----------------------------------------------------------------------------*/

#ifdef WISDOM_MMI
   #ifndef __FS_NATIVE_ENCODING_TRANSPARENT__
   #define __FS_NATIVE_ENCODING_TRANSPARENT__
   #endif
#endif

//--- NOR Idle Sweep ---
#ifdef __NOR_IDLE_SWEEP__
    #define __FS_NOR_IDLE_SWEEP__
#endif

//--- Cacheability ---

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
   #define FS_CACHE_ALIGNMENT_OFFSET  (32)
#else
   #define FS_CACHE_ALIGNMENT_OFFSET  (4)
#endif

//--- Smart File Seek ---

/*---------------------------------------------------------------------------
 * FS Smart File Seek
 *
 * If this option is defined, FS supports smart file seek feature and exports a new API
 * FS_SetSeekHintEx() for users to enhance file seek performance.
 *
 * FS smart file seeker is (Applied on both FS_Seek and FS_SeekLargeFile).
 ----------------------------------------------------------------------------*/
#if !defined(__FS_PROPRIETARY_SET__) && !defined(__FS_CARD_DOWNLOAD__) && !defined(__FS_SLIM__)

    #if !defined(__FS_SMART_FILE_SEEKER__)
    #define __FS_SMART_FILE_SEEKER__
    #endif

#endif

#endif // !_FS_INTERNAL_DEF_H
