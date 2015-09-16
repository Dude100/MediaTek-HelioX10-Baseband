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
 *   fs_kal.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file system service abstraction layer for file system
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
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

#ifndef _FS_KAL_H
#define _FS_KAL_H

#if (!defined(CURR_MODULE) || (CURR_MODULE != MOD_FS)) && !defined(__FS_CARD_DOWNLOAD__)
#error "This header is for FS internal use only. Please include fs_gprot.h instead!"
#endif

#include "kal_public_defs.h"
#include "rtfiles.h"
#include "rtfex.h"
//#include "fs_utility.h"
#include "intrCtrl.h"   // GET_RETURN_ADDRESS()

#if defined(__MTK_TARGET__)
    #if defined(__GNUC__)
        #define FS_GET_RETURN_ADDRESS(a)  do { a = (kal_uint32) __builtin_return_address(0); } while(0)
    #else
        #define FS_GET_RETURN_ADDRESS(a)  GET_RETURN_ADDRESS(a)   // Use the definition in intrCtrl.h
    #endif
#else
#define FS_GET_RETURN_ADDRESS(a)  a= _ReturnAddress()     // MSC
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*************************************************************************
 * Constant Definition
 *************************************************************************/
#define RTF_NO_WAIT		0	/* if obtain fail return immediately*/
#define RTF_INFINITE 	1  /* timeout value to wait forever */

// system error code for FS (must align to MAUI exception handler's definition)
#define FS_ERR_USER_ERROR       (0xA01)
#define FS_ERR_INTERNAL_ERROR   (0xA02)

typedef enum
{
    FS_ERR_API_CLOSE_ALL    = 1,
    FS_ERR_HANDLE_01
} fs_sst_normal_error_code;

typedef enum
{
    FS_ERR_ASSERT           = 1,
    FS_ERR_BUFFER_01,
    FS_ERR_BUFFER_02,
    FS_ERR_BUFFER_03,
    FS_ERR_BUFFER_04,
    FS_ERR_BUFFER_05,
    FS_ERR_BUFFER_06,
    FS_ERR_BUFFER_07,
    FS_ERR_BUFFER_08,
    FS_ERR_BUFFER_09,
    FS_ERR_BUFFER_10,
    FS_ERR_BUFFER_11,
    FS_ERR_BUFFER_12,
    FS_ERR_BUFFER_13,
    FS_ERR_BUFFER_14,
    FS_ERR_BUFFER_15,
    FS_ERR_BUFFER_16,
    FS_ERR_BUFFER_17,
    FS_ERR_BUFFER_18,
    FS_ERR_BUFFER_19,
    FS_ERR_BUFFER_20,
    FS_ERR_BUFFER_21,
    FS_ERR_BUFFER_22,
    FS_ERR_BUFFER_23,
    FS_ERR_BUFFER_24,
    FS_ERR_BUFFER_25,
    FS_ERR_BUFFER_26,
    FS_ERR_BUFFER_27,
    FS_ERR_BUFFER_28,
    FS_ERR_BUFFER_29,
    FS_ERR_BUFFER_30,
    FS_ERR_BUFFER_31,
    FS_ERR_BUFFER_32,
    FS_ERR_BUFFER_33,
    FS_ERR_BUFFER_34,
    FS_ERR_BUFFER_35,
    FS_ERR_BUFFER_36,
    FS_ERR_BUFFER_37,
    FS_ERR_BUFFER_38,
    FS_ERR_BUFFER_39,
    FS_ERR_BUFFER_40,
    FS_ERR_BUFFER_41,
    FS_ERR_CLUSTER_01,
    FS_ERR_CLUSTER_02,
    FS_ERR_CLUSTER_03,
    FS_ERR_CLUSTER_04,
    FS_ERR_CLUSTER_05,
    FS_ERR_CLUSTER_06,
    FS_ERR_CLUSTER_07,
    FS_ERR_CLUSTER_08,
    FS_ERR_DIRENTRY_01,
    FS_ERR_DIRENTRY_02,
    FS_ERR_EXCEPTION_01,
    FS_ERR_EXCEPTION_02,
    FS_ERR_EXCEPTION_03,
    FS_ERR_EXCEPTION_04,
    FS_ERR_EXCEPTION_05,
    FS_ERR_EXCEPTION_06,
    FS_ERR_EXCEPTION_07,
    FS_ERR_EXCEPTION_08,
    FS_ERR_EXCEPTION_09,
    FS_ERR_EXCEPTION_10,
    FS_ERR_EXCEPTION_11,
    FS_ERR_EXCEPTION_12,
    FS_ERR_EXCEPTION_13,
    FS_ERR_EXCEPTION_14,
    FS_ERR_HANDLE_02,
    FS_ERR_HANDLE_03,
    FS_ERR_HANDLE_04,
    FS_ERR_INTERNAL_HINT_01,
    FS_ERR_LOCK_01,
    FS_ERR_MOUNT_01,
    FS_ERR_MUTEX_01,
    FS_ERR_SEEK_HINT_01,
    FS_ERR_TLS_01,
    FS_ERR_TLS_02,
    FS_ERR_WATERMARK_01
} fs_sst_internal_error_code;

typedef enum
{
    FS_LOCK_TYPE_DEFAULT = 0,
    FS_LOCK_TYPE_PRIORITY_INHERITANCE,
    FS_LOCK_TYPE_INVALID
} fs_lock_type_enum;

extern FS_Mutex *           _gfs_lock_common;

extern void *               _gfs_err_info;
extern kal_uint32           _gfs_err_assert_line;
extern fs_src_file_enum     _gfs_err_assert_file;
extern kal_uint32           _gfs_err_assert_param[];

/*************************************************************************
 * Function Declaration
 *************************************************************************/
#ifndef __FS_CARD_DOWNLOAD__
    /* get current date and time and store it in *DOSFileDateTime */
    RTTDLL void           RTFAPI RTFSYSGetDateTime(RTFDOSDateTime * DOSFileDateTime);

    /* allocate a mutex and return a reference to it */
    RTTDLL RTFMutex *     RTFAPI RTFSYSAllocMutex(const char * Name);

    /* lock a mutex with given timeout in milliseconds. The return value must
    * be RTF_NO_ERROR (mutex is locked) or RTF_TIMEOUT (failed) */
    RTTDLL int            RTFAPI RTFSYSLockMutex(RTFMutex * Mutex, UINT Timeout);

    /* release a locked mutex */
    RTTDLL void           RTFAPI RTFSYSFreeMutex(RTFMutex * Mutex);

    /* return 1 if the current task has looked the given mutex and 0 otherwise */
    RTTDLL int            RTFAPI RTFSYSOwnMutex(RTFMutex * Mutex);


    /* display an error message and abort the program with the given error
    * code. RTFiles calls this function on all fatal errors. */
    RTTDLL void           RTFAPI RTFSYSErrorExit(const char * Message, UINT ExitCode);


    RTTDLL int            RTFAPI SafeLock(DWORD Lock, RTFDevice * Dev, DWORD Timeout);

    RTTDLL int            RTFAPI SafeUnlock(DWORD Lock);

    RTTDLL void UnlockDevice(RTFDevice * Dev);

    RTTDLL void LockDevice(RTFDevice * Dev, UINT Flags);

    RTTDLL RTFMutex * FindDeviceLock(RTFDevice * Dev, RTFDriver * Driver, const char * Name);

    RTTDLL BYTE _rtfLock(BYTE * Lock);

    int RTFSYSGetThreadCount(void);

    void        fs_lock_init(void);
    FS_Mutex*   fs_lock_alloc_mutex(const char *name, fs_lock_type_enum type);
    void        fs_lock_free_mutex(FS_Mutex *mutex);
    int         fs_lock_get_mutex(FS_Mutex *mutex, kal_uint32 timeout);
#else
    #define RTFSYSGetDateTime(X)
    #define RTFSYSAllocMutex(X) 0
    #define RTFSYSLockMutex(X,Y)
    #define RTFSYSFreeMutex(X)
    #define RTFSYSOwnMutex(X)
    #define RTFSYSErrorExit(X,Y)
    #define SafeLock(X,Y,Z)
    #define SafeUnlock(X)
    #define UnlockDevice(X)
    #define LockDevice(X,Y)
    #define fs_lock_init()
    #define fs_lock_alloc_mutex(X,Y) 0
    #define fs_lock_free_mutex(X)
    #define fs_lock_get_mutex(X,Y) 0
#endif /* __FS_CARD_DOWNLOAD__ */

	/* allocate a TLS (task local storage) index. At least 4 such indexes
	 * should be available to RTFiles. Device drivers may required even more. */
	RTTDLL int            RTFAPI RTFSYSAllocTLS(void);

	/* set TLS data of the current task */
	RTTDLL void           RTFAPI RTFSYSSetTLS(int Index, void * Value);

	/* retrieve TLS data of the current task */
	RTTDLL void *         RTFAPI RTFSYSGetTLS(int Index);

    RTTDLL kal_uint8      RTFAPI RTFSYSGetTaskIndex(void);

	/* display an error message and abort the program with the given error
	 * code. RTFiles calls this function on all fatal errors. */
	RTTDLL void           RTFAPI RTFSYSErrorExit(const char * Message, UINT ExitCode);

    #if !defined(__UBL__)
    void fs_err_user_fatal(kal_int32 code, void *info);
    void fs_err_internal_fatal(kal_int32 code, void *info);
    void fs_err_assert(fs_src_file_enum file, kal_uint32 line);
    void fs_err_assert_ext(fs_src_file_enum file, kal_uint32 line, kal_uint32 e1, kal_uint32 e2, kal_uint32 e3);
    #else   // __UBL__ (Bootloader does not have kal_fatal_error_handler but it has ASSERT()
    #define fs_err_user_fatal(a, b)             ASSERT(0)
    #define fs_err_internal_fatal(a, b)         ASSERT(0)
    #define fs_err_assert(a, b)                 ASSERT(0)
    #define fs_err_assert_ext(a, b, c, d, e)    ASSERT(0)
    #endif  // !__UBL__

/*************************************************************************
 * External Function Declaration
 *************************************************************************/
        extern void*          kal_get_task_name_ptr(void *task_id);
#ifdef  __cplusplus
}
#endif

#endif /* _FS_KAL_H */


