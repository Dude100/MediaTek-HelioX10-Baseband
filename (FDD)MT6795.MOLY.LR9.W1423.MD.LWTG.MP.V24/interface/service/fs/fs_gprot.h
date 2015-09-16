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
 *   fs_gprot.h
 *
 * Project:
 * --------
 *   Maui Software
 *
 * Description:
 * ------------
 *   This file provides the header of MTK file system service.
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
 * removed!
 * removed!
 * removed!
 * removed!
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

#ifndef _FS_GPROT_H
#define _FS_GPROT_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*---------------------------------------------------------------------------
 * Included Header Files
 *---------------------------------------------------------------------------*/

//-- KAL headers
#include "kal_general_types.h"

//-- Extern headers for FS features
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"       // for module_type
#include "kal_public_api.h"

/*---------------------------------------------------------------------------
 * Error Codes
 *---------------------------------------------------------------------------*/
typedef enum
{
    FS_NO_ERROR                    =    0,    /* No error */
    FS_ERROR_RESERVED              =   -1,    /* Reserved error, not used currently */
    FS_PARAM_ERROR                 =   -2,    /* User */
    FS_INVALID_FILENAME            =   -3,    /* User */
    FS_DRIVE_NOT_FOUND             =   -4,    /* User or Fatal */
    FS_TOO_MANY_FILES              =   -5,    /* User or Normal: use over max file handle number or more than 256 files in sort */
    FS_NO_MORE_FILES               =   -6,    /* Normal */
    FS_WRONG_MEDIA                 =   -7,    /* Fatal */
    FS_INVALID_FILE_SYSTEM         =   -8,    /* Fatal */
    FS_FILE_NOT_FOUND              =   -9,    /* User or Normal */
    FS_INVALID_FILE_HANDLE         =  -10,    /* User or Normal */
    FS_UNSUPPORTED_DEVICE          =  -11,    /* User */
    FS_UNSUPPORTED_DRIVER_FUNCTION =  -12,    /* User or Fatal */
    FS_CORRUPTED_PARTITION_TABLE   =  -13,    /* fatal */
    FS_TOO_MANY_DRIVES             =  -14,    /* not use so far */
    FS_INVALID_FILE_POS            =  -15,    /* User */
    FS_ACCESS_DENIED               =  -16,    /* User or Normal */
    FS_STRING_BUFFER_TOO_SMALL     =  -17,    /* User */
    FS_GENERAL_FAILURE             =  -18,    /* Normal */
    FS_PATH_NOT_FOUND              =  -19,    /* User */
    FS_FAT_ALLOC_ERROR             =  -20,    /* Fatal: disk crash */
    FS_ROOT_DIR_FULL               =  -21,    /* Normal */
    FS_DISK_FULL                   =  -22,    /* Normal */
    FS_TIMEOUT                     =  -23,    /* Normal: FS_CloseMSDC with nonblock */
    FS_BAD_SECTOR                  =  -24,    /* Normal: NAND flash bad block */
    FS_DATA_ERROR                  =  -25,    /* Normal: NAND flash bad block */
    FS_MEDIA_CHANGED               =  -26,    /* Normal */
    FS_SECTOR_NOT_FOUND            =  -27,    /* Fatal */
    FS_ADDRESS_MARK_NOT_FOUND      =  -28,    /* not use so far */
    FS_DRIVE_NOT_READY             =  -29,    /* Normal */
    FS_WRITE_PROTECTION            =  -30,    /* Normal: only for MSDC */
    FS_DMA_OVERRUN                 =  -31,    /* not use so far */
    FS_CRC_ERROR                   =  -32,    /* not use so far */
    FS_DEVICE_RESOURCE_ERROR       =  -33,    /* Fatal: Device crash */
    FS_INVALID_SECTOR_SIZE         =  -34,    /* Fatal */
    FS_OUT_OF_BUFFERS              =  -35,    /* Fatal */
    FS_FILE_EXISTS                 =  -36,    /* User or Normal */
    FS_LONG_FILE_POS               =  -37,    /* User : FS_Seek new pos over sizeof int */
    FS_FILE_TOO_LARGE              =  -38,    /* User: filesize + pos over sizeof int */
    FS_BAD_DIR_ENTRY               =  -39,    /* Fatal */
    FS_ATTR_CONFLICT               =  -40,    /* User: Can't specify FS_PROTECTION_MODE and FS_NONBLOCK_MOD */
    FS_CHECKDISK_RETRY             =  -41,    /* System: don't care */
    FS_LACK_OF_PROTECTION_SPACE    =  -42,    /* Fatal: Device crash */
    FS_SYSTEM_CRASH                =  -43,    /* Normal */
    FS_FAIL_GET_MEM                =  -44,    /* Normal */
    FS_READ_ONLY_ERROR             =  -45,    /* User or Normal */
    FS_DEVICE_BUSY                 =  -46,    /* Normal */
    FS_ABORTED_ERROR               =  -47,    /* Normal */
    FS_QUOTA_OVER_DISK_SPACE       =  -48,    /* Normal: Configuration Mistake */
    FS_PATH_OVER_LEN_ERROR         =  -49,    /* Normal */
    FS_APP_QUOTA_FULL              =  -50,    /* Normal */
    FS_VF_MAP_ERROR                =  -51,    /* User or Normal */
    FS_DEVICE_EXPORTED_ERROR       =  -52,    /* User or Normal */
    FS_DISK_FRAGMENT               =  -53,    /* Normal */
    FS_DIRCACHE_EXPIRED            =  -54,    /* Normal */
    FS_QUOTA_USAGE_WARNING         =  -55,    /* Normal or Fatal: System Drive Free Space Not Enought */
    FS_ERR_DIRDATA_LOCKED          =  -56,    /* Normal */
    FS_INVALID_OPERATION           =  -57,    /* Normal */
    FS_ERR_VF_PARENT_CLOSED        =  -58,    /* Virtual file's parent is closed */
    FS_ERR_UNSUPPORTED_SERVICE     =  -59,    /* The specified FS service is closed in this project. */

    FS_ERR_INVALID_JOB_ID          =  -81,
    FS_ERR_ASYNC_JOB_NOT_FOUND     =  -82,

    FS_MSDC_MOUNT_ERROR            = -100,    /* Normal */
    FS_MSDC_READ_SECTOR_ERROR      = -101,    /* Normal */
    FS_MSDC_WRITE_SECTOR_ERROR     = -102,    /* Normal */
    FS_MSDC_DISCARD_SECTOR_ERROR   = -103,    /* Normal */
    FS_MSDC_PRESNET_NOT_READY      = -104,    /* System */
    FS_MSDC_NOT_PRESENT            = -105,    /* Normal */

    FS_EXTERNAL_DEVICE_NOT_PRESENT = -106,    /* Normal */
    FS_HIGH_LEVEL_FORMAT_ERROR     = -107,    /* Normal */

    FS_CARD_BATCHCOUNT_NOT_PRESENT = -110,    /* Normal */

    FS_FLASH_MOUNT_ERROR           = -120,    /* Normal */
    FS_FLASH_ERASE_BUSY            = -121,    /* Normal: only for nonblock mode */
    FS_NAND_DEVICE_NOT_SUPPORTED   = -122,    /* Normal: Configuration Mistake */
    FS_FLASH_OTP_UNKNOWERR         = -123,    /* User or Normal */
    FS_FLASH_OTP_OVERSCOPE         = -124,    /* User or Normal */
    FS_FLASH_OTP_WRITEFAIL         = -125,    /* User or Normal */
    FS_FDM_VERSION_MISMATCH        = -126,    /* System */
    FS_FLASH_OTP_LOCK_ALREADY      = -127,    /* User or Normal */
    FS_FDM_FORMAT_ERROR            = -128,    /* The format of the disk content is not correct */

    FS_FDM_USER_DRIVE_BROKEN       = -129,    /*User drive unrecoverable broken*/
    FS_FDM_SYS_DRIVE_BROKEN        = -130,    /*System drive unrecoverable broken*/
    FS_FDM_MULTIPLE_BROKEN         = -131,    /*multiple unrecoverable broken*/

    FS_LOCK_MUTEX_FAIL             = -141,    /* System: don't care */
    FS_NO_NONBLOCKMODE             = -142,    /* User: try to call nonblock mode other than NOR flash */
    FS_NO_PROTECTIONMODE           = -143,    /* User: try to call protection mode other than NOR flash */

    /*
     * If disk size exceeds FS_MAX_DISK_SIZE (unit is KB, defined in makefile),
     * FS_TestMSDC(), FS_GetDevStatus(FS_MOUNT_STATE_ENUM) and all access behaviors will
     * get this error code.
     */
    FS_DISK_SIZE_TOO_LARGE         = (FS_MSDC_MOUNT_ERROR),     /*Normal*/

    FS_MINIMUM_ERROR_CODE          = -65536 /* 0xFFFF0000 */
} fs_error_enum;

/*---------------------------------------------------------------------------
 * Definitions
 *---------------------------------------------------------------------------*/

//-- Type definitions
typedef unsigned short  WORD;
typedef unsigned char   BYTE;

#ifndef KAL_ON_THREADX
typedef unsigned int    UINT;
#endif

typedef void*           HANDLE;
typedef int             FS_HANDLE;

typedef kal_int16       fs_job_id;

//-- Attributes of files or folders
/* The entry is read only. Any attempt to open it with read/write access will return error "access denied". */
#define FS_ATTR_READ_ONLY        0x01

/* The entry is marked as hidden. This attribute has no effect on any FS function. */
#define FS_ATTR_HIDDEN           0x02

/* The entry is marked as being a system file. If a file in system drive brings this flag, file system will fix it if its size is abnormal instead of deleting it (default behavior). */
#define FS_ATTR_SYSTEM           0x04

/* The entry is a volume label. Only a directory entry on a logical drive in the root directory can have this attribute set. */
#define FS_ATTR_VOLUME           0x08

/* The entry is a directory. */
#define FS_ATTR_DIR              0x10

/* The entry is marked as being backed up. This attribute has no effect on any FS function, but it is set on every write operation. */
#define FS_ATTR_ARCHIVE          0x20

/* The entry is a long file name entry */
#define FS_LONGNAME_ATTR         0x0F

//-- Buffer (internal)
#define FS_BUFFER_SIZE           512

//-- Attributes of devices

//---- Device type (customized)
#define FS_DEVICE_REMOVABLE      0x0008     // removable device (e.g., memory card)
#define FS_DEVICE_EMMC           0x0010     // EMMC device
#define FS_DEVICE_RAM            0x0020     // RAM device (e.g., RAM disk)
#define FS_DEVICE_NOR_FLASH      0x0040     // NOR flash device
#define FS_DEVICE_NAND_FLASH     0x0080     // NAND flash device
#define FS_DEVICE_EXTERNAL       0x0800     // External device (e.g., OTG device)
#define FS_DEVICE_SIMPLUS        0x1000     // SIMPlus device
#define FS_DEVICE_MEMORY_STICK   0x4000     // Memory stick device

//---- Device characteristics (customized)
#define FS_DEVICE_WRITE_PROTECT  0x0100     // device is write-protected
#define FS_DEVICE_NO_EXPORT      0x0200     // device is not allowed to be exported
#define FS_DEVICE_AUTO_FORMAT    0x2000     // FS auto-format is supported on this device

//---- Flag for FS_DeviceData.Reserved (internal)
#define FS_DEVICE_ABORT_COUNT_FREE_CLUSTER  0x20    // In certain scenario, abort current BatchCountFreeCluster(). E.g., The device is exporting
#define FS_DEVICE_COUNT_FREE_CLUSTER    0x40    // let MountLogicalDrive count free space when leaving Mass Storage mode or hot-plug-in
#define FS_DEVICE_ENTER_CRITICAL_ERROR  0x80

//-- Drive letters
#define FS_DRV_SYSTEM_DRIVE      ('Z')  // [ram disk]
#define FS_DRV_RAM_DRIVE         ('Y')

//-- FS_Open flags
/* The file is opened for read and write access. */
#define FS_READ_WRITE           0x00000000L

/* The file is opened for read only access. */
#define FS_READ_ONLY            0x00000100L

/*
 * Opening the file multiple times should not generate an "access denied" error.
 * By default, FS will allow the same file to be opened several times only if all instances of the file are opened with
 * read only access.
 * However, if one or more instances also require write access and all instances specify this flag, the call succeeds.
 * Note that a drive file or device file spans one or more logical drives and thus conflicts with any other file on
 * the respective drive or device.
 */
#define FS_OPEN_SHARED          0x00000200L

/* Do not open directories. Use this flag to avoid accidentally opening directories. */
#define FS_OPEN_NO_DIR          0x00000400L

/*
 * Overrides flag FS_OPEN_NO_DIR and forces support for opening a directory.
 * <color red>Directories can only be opened with read only access.</color>
 */
#define FS_OPEN_DIR             0x00000800L
#define FS_CREATE               0x00010000L
#define FS_CREATE_ALWAYS        0x00020000L

/*
 * Specifies that all updates to the file should be written to the physical device immediately.
 * This includes the directory entry for the file as well as the drive's FAT when the file's size changes.
 * Use this flag with care, since the performance penalty can be severe.
 * By default, FS will flush data buffers when the file pointer leaves a sector and it will flush FAT
 * and directory data when the file is closed.
 */
#define FS_COMMITTED            0x01000000L

/*
 * Instructs FS not to discard data buffers for this file.
 * This option is useful during random access where small blocks are read with frequent interleaving seek operations.
 * In this case, FS's internal buffers will serve as a cache for the file.
 * By default, FS assumes that files are read or written sequentially and will therefore discard data buffers when
 * the file pointer leaves a sector. In this way, it is avoided that data sectors displace FAT and directory data in
 * the buffers.
 */
#define FS_CACHE_DATA           0x02000000L

/*
 * Instructs FS not to flush dirty (modified) data buffers when the file pointer leaves a sector.
 * This flag automatically also sets FS_CACHE_DATA. This flag can improve performance when the same data is written
 * several times, since data which would get overwritten will never actually be written to the disk.
 * Such unflushed (lazy) data buffers will be flushed when the file is closed, or when the last file on the same
 * drive is closed on drives with device option FS_DEVICE_LAZY_WRITE.
 */
#define FS_LAZY_DATA            0x04000000L

/*
 * Causes FS_Write and FS_Read unblocked while the driver indicates device busy or obtain Mutex fails.
 * <color red><b>Notes</b></color>: Only valid for those driver with NonBlockWriteSectors interface.
 */
#define FS_NONBLOCK_MODE        0x10000000L
/*
 * Make sure each modification on NOR flash will be atomic, i.e. even if abnormal power off, data should be entirely old or new.
 * <color red><b>Notes</b></color>: Only valid for those driver with RecoverableWriteSectors and ResumeSectorStates interface.
 */
#define FS_PROTECTION_MODE      0x20000000L
#define FS_NOBUSY_CHECK_MODE    0x40000000L

//-- FS_GetDrive parameter options
#define FS_NO_ALT_DRIVE         0x00000001
#define FS_ONLY_ALT_SERIAL      0x00000002
#define FS_DRIVE_I_SYSTEM       0x00000004      // system drive (invisible)
#define FS_DRIVE_I_RAM          0x00000080      // RAM drive (invisible)
#define FS_DRIVE_V_NORMAL       0x00000008      // non-removable drive (visible)
#define FS_DRIVE_V_REMOVABLE    0x00000010      // removable drive (visible)
#define FS_DRIVE_V_EXTERNAL     0x00000020      // external drive (visible)
#define FS_DRIVE_V_SIMPLUS      0x00000040      // SIM plus drive (visible)

//-- FS_GeneralFormat parameter options
#define FS_FORMAT_HIGH          0x00000001
#define FS_FORMAT_LOW           0x00000002

#define FS_FMT_SINGLE_FAT       0x00000100L
#define FS_FMT_FORCE_LOW_LEVEL  0x00000200L
#define FS_FMT_NO_LOW_LEVEL     0x00000400L
#define FS_FMT_GET_DATA_SECTOR  0x00000800L
#define FS_FMT_FAT_12           0x00001000L
#define FS_FMT_FAT_16           0x00002000L
#define FS_FMT_FAT_32           0x00004000L
#define FS_FMT_NO_FAT_32        0x00008000L

#define FS_FLASH_NO_HIGH_FMT     0x20000000L
#define FS_FLASH_NO_LOW_FMT      0x40000000L

//-- FS_Move, FS_Count, FS_GetFolderSize, FS_XDelete, FS_XFindReset (Sorting) Parameter and Flag Passing
#define FS_MOVE_COPY             0x00000001     // FS_Move only, Public
#define FS_MOVE_KILL             0x00000002     // FS_Move only, Public

#define FS_FILE_TYPE             0x00000004     // Recursive Type API Common, Public
#define FS_DIR_TYPE              0x00000008     // Recursive Type API Common, Public
#define FS_RECURSIVE_TYPE        0x00000010     // Recursive Type API Common, Public

#define FS_NO_SORT               0x00000020     // Sort Parameter, Public
#define FS_SORT_NAME             0x00000040     // Sort Parameter, Public
#define FS_SORT_SIZE             0x00000080     // Sort Parameter, Public
#define FS_SORT_ATTR             0x00000100     // Sort Parameter, Public
#define FS_SORT_TYPE             0x00000200     // Sort Parameter, Public
#define FS_SORT_TIME             0x00000400     // Sort Parameter, Public
#define FS_SORT_USER             0x00080000     // Sort Parameter, User

#define FS_COUNT_SIZE            0x00000800     // QM internal for RecFolderAction (DEPARTED)
#define FS_REMOVE_CHECK          0x00001000     // QM internal for RecFolderAction (DEPARTED)
#define FS_FILTER_SYSTEM_ATTR    0x00002000     // FS_Count only, Public
#define FS_REC_COPYRIGHT_DEL     0x00004000     // FS_SweepCopyrightFile only, <Private, APP SHOULD NOT USE>
#define FS_REC_COPYRIGHT_LIST    0x00008000     // FS_GetCopyrightList only, <Private, APP SHOULD NOT USE>
#define FS_MOVE_OVERWRITE        0x00010000     // FS_Move only, Public
#define FS_XDEL_ABORT_WATCH      0x00020000     // FS_XDelete only, <Private, APP SHOULD NOT USE>
#define FS_FILTER_HIDDEN_ATTR    0x00040000     // FS_Count only, Public

//-- FSSetTrace Parameter
#define FS_TRACE_API             0x00000001
#define FS_TRACE_ERROR           0x00000002
#define FS_TRACE_DISABLE         0x00000004
#define FS_TRACE_ALL_TASK        0x00000008

//-- Quota Management
#define FS_QMAX_NO_LIMIT         0xf1f2f3f4 //~3.8GB
#define FS_COUNT_IN_BYTE         0x00000001
#define FS_COUNT_IN_CLUSTER      0x00000002

//-- FS_Abort Parameter
#define FS_ABORT_CHECK_DRIVE     0x12345678
#define FS_ABORT_XDELETE         0x87654321
#define FS_ABORT_MOVE            0xFEDCBA09

//-- FS_ConfigExtDevice Parameter
#define FS_SETUP_EXT_DEVICE      0x02468ACE
#define FS_RELEASE_EXT_DEVICE    0x13579BDF

//-- FS_SwitchDriveMode Parameter
/* Set the device of the drive to read only mode. Before the mode switching, all opened files on this device will be closed and all cached data will be flushed to the device. */
#define FS_DRIVE_SOFT_UNMOUNT    0x00000001

/* set the soft-unmounted device to normal mode. This mode can be only used after the device was set to read only mode. */
#define FS_DRIVE_SOFT_MOUNT      0x00000002

//-- FS_CompactDir Parameter

/* Obsolete: compact without update direntry */
#define FS_CMPCT_READ_ONLY       0x00000001

/* Compact recursively */
#define FS_CMPCT_RECURSIVE       0x00000002

//-- Path and file name length limitation
#if defined(__FS_PATH_LENGTH_LIMITED__)
#define FS_MAX_PATH              64     // Max path length in FAT spec (for ultra-low cost projects)
#define FS_MAX_FILE_NAME_LENGTH (64 - (3 * 2) + 2) // The maximum file name length (minus "X:\\" and plus tailed NULL)
#else
#define FS_MAX_PATH              520    // Max path length in FAT spec (for general projects)
#define FS_MAX_FILE_NAME_LENGTH ((255 + 1) * 2) // The maximum file name length (defined in FAT spec)
#endif

#define FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B    (8 + 3 + 1) // "MAJOR_NAMR"."EXTENSION_NAME"
#define FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_W    (FS_MAX_SFN_NATIVE_FILE_NAME_LENGTH_B * 2)

//-- Size unit
#define FS_KB                   *1024
#define FS_MB                   *1024*1024

//-- Flag option of FS_SetSeekHintEx
#define FS_SEEKHINT_FLAG_INITIALIZE_HINT  (0x00000001)

//-- Sorting
#define FS_SORT_CB_SUCCESS      0
#define FS_SORT_CB_ABORT        (-1)

//-- FS_GetSysInfo options
#define FS_SI_BASIC_INFO        (0x00000001)
#define FS_SI_ALL               (FS_SI_BASIC_INFO)

//-- FS Asynchronous Interface
#define FS_TASK_PRIORITY_CHANGE_DEFAULT     (0x00000000)
#define FS_TASK_PRIORITY_CHANGE_ENFORCE_LOW (0x00000001)

//-- Virtual file
#define FS_GenVFN_SIZE          92 // buffer size for Virtual File (include NULL tail) (MoDIS only)

/*---------------------------------------------------------------------------
 * Enumerations
 *---------------------------------------------------------------------------*/

//-- FS_DirCtrl
typedef enum
{
    FS_DIRCTRL_DATA_SET             = 0x00000001L,
    FS_DIRCTRL_DATA_GET             = 0x00000002L,
    FS_DIRCTRL_DATA_EXPIRE          = 0x00000004L,
    FS_DIRCTRL_DATA_LOCK            = 0x00000010L,
    FS_DIRCTRL_DATA_UNLOCK          = 0x00000020L,
    FS_DIRCTRL_DATA_SET_LOCK        = (FS_DIRCTRL_DATA_SET | FS_DIRCTRL_DATA_LOCK),
    FS_DIRCTRL_DATA_GET_LOCK        = (FS_DIRCTRL_DATA_GET | FS_DIRCTRL_DATA_LOCK),
    FS_DIRCTRL_DATA_GET_UNLOCK      = (FS_DIRCTRL_DATA_GET | FS_DIRCTRL_DATA_UNLOCK),
    FS_DIRCTRL_DATA_EXPIRE_UNLOCK   = (FS_DIRCTRL_DATA_EXPIRE | FS_DIRCTRL_DATA_UNLOCK)
} fs_dirctrl_action_enum;

/* FS_GetDiskInfo Parameter */
typedef enum
{
    /*
     * Returns all fields in structure FS_DiskInfo except FreeClusters, BadClusters, Files, FileChains, FreeChains, LargestFreeChain.
     * <color Red><b>This flag never requires a FAT scan.</b></color>
     */
    FS_DI_BASIC_INFO     =  0x00000001L,

    /*
     * Returns field FreeClusters. This flags may require FS to scan the complete FAT if the amount of free space is not known.
     * In this case, FS_DI_FAT_STATISTICS is returned in addition to FS_DI_FREE_SPACE.
     */
    FS_DI_FREE_SPACE     =  0x00000002L,

    /*
     * Returns fields BadClusters, Files, FileChains, FreeChains, LargestFreeChain.
     * This flag will always cause FS to scan the complete FAT.
     */
    FS_DI_FAT_STATISTICS =  0x00000004L,

    /*
     * Get volume label of the target drive. The maximum length is 11 wide characters.
     * <color Red><b>This option must be used with FS_DI_BASIC_INFO.</b></color>
     */
    FS_DI_VOLUME_LABEL   =  0x00000008L,

    /*
     * Allow read-only file operation (open and read) during long operation like "counting free space"
     */
    FS_DI_OPT_READ_PERMITTED = 0x00000010L,

    FS_DI_INVALID
}fs_di_enum;

typedef enum
{
    FS_CONFIG_UTILITY_FUNC  = 0x00000001L,

    FS_CONFIG_INVALID
} fs_config_enum;

/* FS_GetFileInfo/FS_GetFileInfoEx Parameter */
typedef enum
{
    /* Get *DirEntry, FilePos, VolumeSerialNumber and *FullName. */
    FS_FI_BASIC_INFO        = 0x00000001L,

    /* Get AllocatedSize and ClusterChains.*/
    /* Note: This option may cost lots of time because target file¡¦s cluster chain will be completely parsed. */
    FS_FI_ALLOCATED_SPACE   = 0x00000002L,

    /* Combination of FS_FI_BASIC_INFO and FS_FI_ALLOCATED_SIZE flags. The results is the same as FS_GetFileInfo() */
    FS_FI_ALL               = (FS_FI_BASIC_INFO | FS_FI_ALLOCATED_SPACE)
} fs_fi_enum;

typedef enum
{
    FS_TBL_USR_PTR_NONE,

    FS_TBL_USR_PTR_MILESTONE,
    FS_TBL_USR_PTR_LISTCONTEXT,
    FS_TBL_USR_PTR_FINDATTR,

    FS_TBL_USR_PTR_INVALID

}fs_tbl_usr_ptr_type;

typedef enum
{
    FS_FH_INVALID,
    FS_FH_VALID,
    FS_FH_MEDIACHANGED,
    FS_FH_ABORTED,
    FS_FH_EXPORTED
} fs_fh_status;

typedef enum
{
    FS_NO_WAIT,
    FS_INFINITE
} FS_TIMEOUT_ENUM;

/* FS_Seek Parameter */
typedef enum
{
    FS_FILE_BEGIN,
    FS_FILE_CURRENT,
    FS_FILE_END
} FS_SEEK_POS_ENUM;

/* FS_GeneralFormat Callback Return Value */
typedef enum
{
    FS_FMT_PGS_DONE = -1,
    FS_FMT_PGS_FAIL,
    FS_FMT_PGS_LOW_FMT,
    FS_FMT_PGS_HIGH_FMT
} fs_format_pgs_enum;

/* FS_Move Callback Return Value */
typedef enum
{
   /* <color red>if something wrong, will call once</color>
    * Fail to do the move/copy action. Total and Completed will be zero.
    */
    FS_MOVE_PGS_FAIL = -1,

    /*
     * <color red>Always call once</color>
     * Prepare to do the move/copy action. Parameter checking and remove target will be done at this stage.
     * Total and Completed will be zero.
     */
    FS_MOVE_PGS_PREPARE,

   /*
    * <color red>If pass parameter checking, always call once.</color>
    * Start to do the move/copy action. Total and Completed will be zero.
    */
    FS_MOVE_PGS_START,

   /*
    * <color red>Not always call even if nothing wrong.</color>
    * If you move/copy a folder recursively, Total will be the number of files/folders to be moved/copied.
    * Completed will be the files/folders that had been copied/moved.
    * If you just move/copy a file, Total will be the size of this file and Completed will be the bytes that had been moved/copied.
    * <color red>Note</color> that if move/copy only one file, this callback will be triggered when interval is longer than 100ms around.
    */
    FS_MOVE_PGS_ING,

   /*
    * <color redIf nothing fail, always call once</color>
    * Move/copy action is done. Total and Completed will be zero.
    */
    FS_MOVE_PGS_DONE
} fs_move_pgs_enum;

typedef fs_move_pgs_enum FS_MOVE_PGS_ENUM;

//FS_XDelete Callback Return Value
typedef enum
{
    FS_XDELETE_PGS_FAIL = -1,
    FS_XDELETE_PGS_PREPARE,
    FS_XDELETE_PGS_START,
    FS_XDELETE_PGS_ING,
    FS_XDELETE_PGS_DONE
} FS_XDELETE_PGS_ENUM;

//FS_DeleteEx Callback Return Value
typedef enum
{
    FS_DELETE_PGS_FAIL = -1,
    FS_DELETE_PGS_PREPARE,
    FS_DELETE_PGS_START,
    FS_DELETE_PGS_ING,
    FS_DELETE_PGS_DONE
} FS_DELETE_PGS_ENUM;

//Find Series Return Value
typedef enum
{
    FS_NOT_MATCH,
    FS_LFN_MATCH,
    FS_SFN_MATCH
} FS_FIND_ENUM;

//FS_GetDevType Return Value
//FS_GetDevStatus Paramter, Cannot overlap with 'A'~'Z' 0x41~0x5f
typedef enum
{
    FS_DEVICE_TYPE_UNKNOWN  = 0,
    FS_DEVICE_TYPE_NOR      = 1,
    FS_DEVICE_TYPE_NAND,
    FS_DEVICE_TYPE_CARD,
    FS_DEVICE_TYPE_EXTERNAL,
    FS_DEVICE_TYPE_SIMPLUS,
    FS_DEVICE_TYPE_EMMC,
    FS_DEVICE_TYPE_MAX_VALUE
} FS_DEVICE_TYPE_ENUM;

//FS_XFindStart, FS_FindFirstN, FS_FindNextN Parameter
typedef enum
{
    FS_FIND_DEFAULT,
    FS_FIND_LFN_TRUNC
} FS_GET_NAME_ENUM;

//Quota management
typedef enum
{
    FS_QP_HIG_ENUM,
    FS_QP_MID_ENUM,
    FS_QP_LOW_ENUM,
    FS_QP_DEL_ENUM
} FS_QP_ENUM;

/* FS_GetDevStatus Parameter */
typedef enum
{
    FS_MOUNT_STATE_ENUM,             /* Query of mount state */
    FS_FEATURE_STATE_ENUM,           /* Working or not  */
    FS_EXPORT_STATE_ENUM,            /* Exported to PC or not */
    FS_CARD_BATCHCOUNT_STATE_ENUM,   /* Obsolete: Free cluster numer is ready or not */
    FS_DEVICE_PRESENCE_ENUM          /* Device exists or not */
} FS_GET_DEV_STATUS_ENUM;

/* FS_LockFAT Parameter */
typedef enum
{
    FS_LOCK_USB_ENUM,            /* lock file system for preventing access in USB mode. */
    FS_UNLOCK_USB_ENUM,          /* unlock file system for permitting access in USB mode. */
    FS_LOCK_BLOCK_ENUM,          /* configure file system to do blocking write operations on Single Bank NOR Flash. */
    FS_LOCK_NONBLOCK_ENUM,       /* configure file system to do non-blocking write operations on Single Bank NOR Flash. */
    FS_EXPORT_ENUM,              /* lock partial file system for preventing access on exporting device in Normal mode. */
    FS_PURGE_HANDLE_ENUM,        /* purge (invalidate) all file handles which are not belongs to system drive. When public drive and system drive on the same device, there may be some file handle created concurrency during (A) FS_EXPORT_ENUM to (B) FS_Open(WholePublicDrive). Purge Handle is required to help USB task to clear intruded file handles. */
    FS_REMOUNT_ENUM,             /* unlock partial file system for permitting access on exported device in Normal mode. */
#if defined(__MTP_ENABLE__)
    FS_TASK_EXPORT_ENUM,         /* */
    FS_TASK_PURGE_HANDLE_ENUM,   /* */
    FS_TASK_REMOUNT_ENUM,        /* */
#endif /* __MTP_ENABLE__ */
    FS_CARD_BUSY_NONBLOCK_ENUM,  /* Notify file system do not block FS APIs if card is busy */
    FS_EXPORT_FINISHED_ENUM      /* Notify file system that FS_Open(WholePublicDrive) is done. This is required after (A) FS_EXPORT_ENUM and (B) FS_PURGE_HANDLE_ENUM. */
} FS_LOCK_TYPE_ENUM;

typedef enum
{
    FS_NOT_EXPORTED = 0,
    FS_EXPORTING,
    FS_EXPORTED
} FS_LOCK_EXPORT_STATUS_ENUM;

//FS_CountUsedFH Parameter
typedef enum
{
    FS_FH_COUNT_CURRENT_TASK = 0,
    FS_FH_COUNT_AVAILABLE,
    FS_FH_COUNT_USED,
    FS_FH_COUNT_CONFIGURED
} FS_COUNT_USED_FH_ENUM;

// IO control
typedef enum
{
    FS_IOCTRL_DEVICE_UNKNOWN,
    FS_IOCTRL_DEVICE_CAS_CARD // CMMB CAS full card
} FS_IOCTRL_DEVICE_TYPE_ENUM;

/* IO control action */
typedef enum {
    /* To query device type */
    FS_IOCTRL_QUERY_DEVICE_TYPE,

    /*
     * Query NAND flash device¡¦s physical information,
     * like device ID, block size, page size or device
     * size. For this usage, user must allocate a FS_DeviceInfo
     * structure in advance and pass its pointer by CtrlData
     * for device drivers to fill in the information.
     */
    FS_IOCTRL_QUERY_NAND_INFO,

    /*
     * Query NOR flash device¡¦s physical information.
     */
    FS_IOCTRL_QUERY_NOR_INFO,

    /*
     * Query memory card's physical information.
     */
    FS_IOCTRL_QUERY_CARD_INFO,

    /* Query physical map of a specific file. It's for for Low-Power MP3 */
    FS_IOCTRL_QUERY_PHYSICAL_MAP,

    /* Query physical map of a specific file. It's for for Low-Power MP3 */
    FS_IOCTRL_QUERY_PHYSICAL_MAP_DEV_TYPE_ONLY,

    /*
     * Set the command sector number. Some memory card, like CAS full card,
     * requires a sector as the command sector for host to issue CAS commands.
     * For this usage, CtrlData is ignored and can be NULL.
     */
    FS_IOCTRL_SET_COMMAND_SECTOR,

    /* Control device power. User could switch on/off device power via this action. */
    FS_IOCTRL_CONTROL_DEV_POWER,
} fs_ioctrl_action_enum;

//FDM OTPAccess Parameter
typedef enum
{
    FS_OTP_READ = 1,
    FS_OTP_WRITE,
    FS_OTP_LOCK
} FS_OTPACCESS_TYPE_ENUM;

/* FS_Sort Callback Return Value */
typedef enum
{
    FS_SORT_PGS_FAIL = -1,   /* sorting failed. */
    FS_SORT_PGS_PREPARE,     /* Prepare to sort files. */
    FS_SORT_PGS_START,       /* Start to sort files. */
    FS_SORT_PGS_ING,         /* The sorting is in progress. */
    FS_SORT_PGS_DONE,        /* The sorting finished. */
    FS_SORT_PGS_ABORT        /* The sorting is aborted. */
} fs_sort_pgs_enum;

typedef fs_sort_pgs_enum FS_SORT_PGS_ENUM;

typedef enum
{
    FS_PGS_FAIL = -1,
    FS_PGS_PREPARE,
    FS_PGS_START,
    FS_PGS_ING,
    FS_PGS_DONE,
    FS_PGS_ABORT,

    FS_PGS_MAX
} fs_pgs_enum;

// FS API enumeration
typedef enum
{
    FS_API_OPEN      = 1,        // FS_Open
    FS_API_OPENHINT,
    FS_API_CLOSE,
    FS_API_CLOSEALL,
    FS_API_READ,                 // FS_Read
    FS_API_WRITE,                // FS_Write
    FS_API_SETSEEKHINT,
    FS_API_SEEK,                 // FS_Seek (FS_SeekLargeFile)
    FS_API_COMMIT,
    FS_API_RELEASEFH,
    FS_API_ABORT,
    FS_API_PARSEFH,
    FS_API_GETFILEINFO,
    FS_API_GETFILESIZE,
    FS_API_GETFILEPOSITION,
    FS_API_SETFILETIME,
    FS_API_GETATTRIBUTES,
    FS_API_GETFIRSTCLUSTER,
    FS_API_SETATTRIBUTES,
    FS_API_DELETE,
    FS_API_PSEUDOMERGE,
    FS_API_CHECKFILE,
    FS_API_GETCURRENTDIR,
    FS_API_SETCURRENTDIR,
    FS_API_CREATEDIR,
    FS_API_REMOVEDIR,
    FS_API_GETFOLDERSIZE,        // FS_GetFolderSize (FS_GetFolderSizeEx)
    FS_API_EXTEND,
    FS_API_TRUNCATE,
    FS_API_MAKEFILENAME,
    FS_API_RENAME,
    FS_API_MOVE,
    FS_API_COUNT,
    FS_API_XDELETE,
    FS_API_FINDFIRST,            // FS_FindFirst
    FS_API_FINDNEXT,
    FS_API_FINDFIRSTN,           // FS_FindFirstN
    FS_API_FINDNEXTN,
    FS_API_FINDCLOSE,
    FS_API_XFINDRESET,
    FS_API_XFINDSTART,
    FS_API_XFINDCLOSE,
    FS_API_CREATEBOOTSECTOR,
    FS_API_GETPARTITIONINFO,
    FS_API_COMMITALL,
    FS_API_GETDRIVE,
    FS_API_MAPPINGDRIVE,
    FS_API_GENERALFORMAT,
    FS_API_QMGETFREE,
    FS_API_GETCLUSTERSIZE,
    FS_API_CHECKDRIVE,
    FS_API_CREATEMASTERBOOTRECORD,
    FS_API_SPLITPARTITION,
    FS_API_GETDISKINFO,
    FS_API_SHUTDOWN,
    FS_API_UNLOCKALL,
    FS_API_SANITYCHECK,
    FS_API_SETDISKFLAG,
    FS_API_CHECKDISKFLAG,
    FS_API_CLEARDISKFLAG,
    FS_API_GETDEVTYPE,
    FS_API_GETDEVSTATUS,
    FS_API_LOCKFAT,
    FS_API_TESTMSDC,
    FS_API_CLOSEMSDC,
    FS_API_SETTRACE,
    FS_API_DUMPFHTABLE,
    FS_API_GENVIRTUALFILENAME,
    FS_API_CONFIGEXTDEVICE,
    FS_API_GETDIRCACHE,
    FS_API_SETDIRCACHE,
    FS_API_EXPIREDIRCACHE,
    FS_API_OTPREAD,
    FS_API_OTPWRITE,
    FS_API_OTPLOCK,
    FS_API_OTPQUERYLENGTH,
    FS_API_SWEEPDEVICE,
    FS_API_COUNTUSEDFH,
    FS_API_GETDEVPARTITIONS,
    FS_API_RECOVERDEVICE,
    FS_API_SETVOLUMELABEL,
    FS_API_SWITCHDRIVEMODE,
    FS_API_IOCTRL,
    FS_API_COMPACTDIR,
    FS_API_END
} fs_api_enum;

// Priority configuration of FS async job: (Deprecated)
typedef enum
{
    FS_PRIORITY_DEFAULT         = 0,        // Default: This job will use lower priority to run. Suitable to non-critical jobs.
    FS_PRIORITY_INHERITED       = 1,        // Inherited    : This job will inherites the priority of user. Suitable to critical jobs.
    FS_PRIORITY_ASSIGN          = 2,        // Assign       : This job will use a specific priority to run. Set priority value in overlapped->priority_value.
    FS_PRIORITY_INVALID         = 0xFF
} fs_prioity_enum;

// Response method when asynchronous job is done.
typedef enum
{
    FS_RESPONSE_MESSAGE   = 0,     // (Default): Sending ILM when job done, the user have to use fs_async_msg_handler() to execute the callback function.
    FS_RESPONSE_CALLBACK  = 1,     // Calling Call Back Function directedly without sending ILM, DO NOT call fs_async_msg_handler() when using this flag.
    FS_RESPONSE_INVALID   = 0xFF
} fs_response_enum;

typedef enum
{
    FS_JOB_STATE_NOT_STARTED    = 0,
    FS_JOB_STATE_RUNNING,
    FS_JOB_STATE_PAUSE,
    FS_JOB_STATE_FINISHED,
    FS_JOB_STATE_ABORTING,
    FS_JOB_STATE_INVALID        = 0xFF
} fs_job_state_enum;

/*---------------------------------------------------------------------------
 * Callback functions
 *---------------------------------------------------------------------------*/

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  FS_FormatCallback
 * DESCRIPTION
 *  This is the callback function type of FS_GeneralFormat.
 * PARAMETERS
 *  DriveName   : [IN] <P>Drive name
 *  Action      : [IN] <P>Please refer to fs_format_pgs_enu.
 *  Total       : [IN] <P>System total sectors before data sectors
 *  Completed   : [IN] <P>The sectors which had been formatted. <color red>Note:</color> if Action is FS_FMT_PGS_FAIL, Total and Completed will be zero.
 * RETURNS
 *  N/A
 *****************************************************************************/
typedef void (* FS_FormatCallback)(const char * DeviceName, int Action, kal_uint32 Total, kal_uint32 Completed);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  FS_ProgressCallback
 * DESCRIPTION
 *  This is the callback function type of FS_GeneralFormat.
 * PARAMETERS
 *  Action      : [IN] <P>Please refer to fs_move_pgs_enum.
 *  Total       : [IN] <P>Total bytes or number of file/folders needs to be moved/copied.
 *  Completed   : [IN] <P>Bytes or number of file/folders that had been moved/copied.
 *  Info        : [IN] <P>In this function, this field will give you a file handle. If you want to abort the action of FS_Move, please call FS_Abort to abort the action via this handle.
 * RETURN VALUES
 *  < 0     : Abort
 *  >= 0    : Continue
 *****************************************************************************/
typedef int FS_ProgressCallback(int Action, kal_uint32 Total, kal_uint32 Completed, kal_uint32 Info);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  SortingProgressCallback
 * DESCRIPTION
 *  This is the callback function type during sorting.
 * PARAMETERS
 *  Status        : [IN]    <P>Please refer to fs_sort_pgs_enum.
 *  Total         : [IN]    <P>This field is valid after receiving FS_SORT_PGS_START. It represents the total files and folders that will be sorted.
 *  Completed     : [IN]    <P>This identifies the number of files is sorted.
 *  CallbackParam : [OUT]   <P>The user parameter that is assigned by ProgressCallbackParam.
 * RETURN VALUES
 *  FS_SORT_CB_SUCCESS: Return normally.
 *  FS_SORT_CB_ABORT: This is used to indicate that user wants to abort the sorting operation.
 *****************************************************************************/
typedef int (*SortingProgressCallback)(FS_SORT_PGS_ENUM Status, int Total, kal_uint32 Completed, void *CallbackParam);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  SortingCompareFunc
 * DESCRIPTION
 *  This is the customized compare function.
 * PARAMETERS
 *  FileName1   : [IN] <P>This is the first filename that want to be compared to FileName2.
 *  Hint1       : [IN] <P>If Hint1 is not NULL, user can create an kal_uint32 value for FileName1. The sorting procedure will compare the hint value of each filename to speed up the sorting without invoking the CompareFunc. If the hint values of two FileName are the same, CompareFunc will be invoked.
 *  FileName2   : [IN] <P>This is the second filename.
 *  Hint2       : [IN] <P>If Hint2 is not NULL, user can create an kal_uint32 value for FileName2.
 * RETURN VALUES
 *  > 0 :   if FileName1 > FileName2
 *  == 0:  if FileName1 == FileName2
 *  < 0 :    if FileName1 < FileName2
 *****************************************************************************/
typedef int (*SortingCompareFunc)(WCHAR *FileName1, kal_uint32 *Hint1, WCHAR *FileName2, kal_uint32 *Hint2);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  fs_progress_callback_func
 * DESCRIPTION
 *  This is the general callback function type.
 * PARAMETERS
 *  status      : [IN]    <P>Please refer to fs_pgs_enum.
 *  total       : [IN]    <P>the total files and folders that will be found.
 *  completed   : [IN]    <P>This identifies how many files are found.
 *  param       : [OUT]   <P>The user data which will pass back to the caller without change.
 * RETURNS
 *  N/A
 *****************************************************************************/
typedef kal_int32 (*fs_progress_callback_func)(FS_HANDLE handle, fs_pgs_enum status, kal_int32 total, kal_uint32 completed, void *param);

// FS async I/F callback function
typedef kal_int32 (*fs_async_callback)(fs_job_id job_id, kal_int64 result, void *data);

typedef kal_int32 (*fs_progress_callback)(kal_int32 action, kal_uint32 total, kal_uint32 completed, kal_uint32 info);

typedef kal_uint16 (*fs_util_ucs_to_wchar_func)(kal_uint16 ucs2);

typedef kal_uint32 (*fs_util_get_default_encoding_length_func)(void);


/*---------------------------------------------------------------------------
 * Structures
 *---------------------------------------------------------------------------*/

//------------------------------------- Compiler Directive Conventions
#if !defined(__MTK_TARGET__) || defined(GEN_FOR_PC) || defined(__RESOURCE_GEN_) || defined(NVRAM_AUTO_GEN)
    #define __fs_packed_prefix
    #define __fs_packed_postfix
    #define __fs_align(x)
#elif defined(__ARMCC_VERSION)
    #define __fs_packed_prefix     __packed
    #define __fs_packed_postfix
    #define __fs_align(x)          __align(x)
#elif defined(__GNUC__)
    #define __fs_packed_prefix
    #define __fs_packed_postfix    __attribute__ ((__packed__))
    #define __fs_align(x)          __attribute__ ((aligned(x)))
#endif
// temporaly avoid build errors
#if defined(__ARMCC_VERSION)
#define ONE_BYTE_ALIGN_ADS __packed
#else
#define ONE_BYTE_ALIGN_ADS
#endif
//------------------------------------- Compiler Directive Conventions

//------------------------------------- Packed Structures
#if defined(WIN32)
#pragma pack(1)
#endif

/* Date/time that the dir entry is created or modified */
typedef __fs_packed_prefix struct
{
    kal_uint32 Second2:5; /* holds the seconds part of the desired time divided by 2. */
    kal_uint32 Minute:6;
    kal_uint32 Hour:5;
    kal_uint32 Day:5;
    kal_uint32 Month:4;
    kal_uint32 Year1980:7; /* holds the year part of the desired date minus 1980. */
} __fs_packed_postfix FS_DOSDateTime;

typedef __fs_packed_prefix struct
{
   char                 FileName[8];
   char                 Extension[3];
   kal_uint8            Attributes;
   kal_uint8            NTReserved;
   kal_uint8            CreateTimeTenthSecond;
   FS_DOSDateTime       CreateDateTime;
   kal_uint16           LastAccessDate;
   kal_uint16           FirstClusterHi;
   FS_DOSDateTime       DateTime ;
   kal_uint16           FirstCluster;
   kal_uint32           FileSize;
   // FS_FileOpenHint members (!Note that RTFDOSDirEntry structure is not changed!)
   kal_uint32           Cluster;
   kal_uint32           Index;
   kal_uint32           Stamp;
   kal_uint32           Drive;
   kal_uint32           SerialNumber;
}__fs_packed_postfix FS_DOSDirEntry;

/* Structure of partition record */
typedef __fs_packed_prefix struct
{
    kal_uint8   BootIndicator, /* 0x80 for bootable, 0 otherwise */
                StartHead,     /* 0 based */
                StartSector,   /* 1 based, bits 0-5 */
                StartTrack,    /* 0 based, bits 0-7, take bits 8,9 from StartSector */
                OSType,        /* FAT-12: 1, FAT-16: 4, 6, 14, FAT-32: 11, 12 */
                EndHead,       /* see StartHead */
                EndSector,     /* see StartSector */
                EndTrack;      /* see StartTrack */

                /*
                 * offset to first sector of partition data
                 * for primary partitions, this is the absolute
                 * LBA of the boot sector
                 */
    kal_uint32  RelativeSector,
                Sectors;       /* number of sectors in partition */
} __fs_packed_postfix FS_PartitionRecord;

typedef __fs_packed_prefix struct
{
    kal_uint8 BootCode[512-4*sizeof(FS_PartitionRecord)-sizeof(kal_uint16)];
    FS_PartitionRecord PTable[4];
    kal_uint16 Signature;
} __fs_packed_postfix FS_MasterBootRecord;

typedef __fs_packed_prefix struct
{
    kal_uint8     PhysicalDiskNumber;
    kal_uint8     CurrentHead;
    kal_uint8     Signature;
    kal_uint32     SerialNumber;
    kal_uint8     Label[11];
    char     SystemID[8];
} __fs_packed_postfix FS_ExtendedBIOSParameter;

typedef __fs_packed_prefix struct
{
    char     OEMName[8];
    kal_uint16     BytesPerSector;
    kal_uint8     SectorsPerCluster;
    kal_uint16     ReservedSectors;
    kal_uint8     NumberOfFATs;
    kal_uint16     DirEntries;
    kal_uint16     SectorsOnDisk;
    kal_uint8     MediaDescriptor;
    kal_uint16     SectorsPerFAT;
    kal_uint16     SectorsPerTrack;
    kal_uint16     NumberOfHeads;
    kal_uint32     NumberOfHiddenSectors;
    kal_uint32     TotalSectors;
    __fs_packed_prefix union
    {
        __fs_packed_prefix struct
        {
            FS_ExtendedBIOSParameter BPB;
        } __fs_packed_postfix _16;
        __fs_packed_prefix struct
        {
            kal_uint32     SectorsPerFAT;
            kal_uint16     Flags;
            kal_uint16     Version;
            kal_uint32     RootDirCluster;
            kal_uint16     FSInfoSector;
            kal_uint16     BackupBootSector;
            kal_uint8     Reserved[12];
            FS_ExtendedBIOSParameter BPB;
        } __fs_packed_postfix _32;
    } __fs_packed_postfix E;
}__fs_packed_postfix FS_BIOSParameter;

typedef __fs_packed_prefix struct
{
    kal_uint8 NearJump[3];
    FS_BIOSParameter BP;
    kal_uint8 BootCode[512-3-sizeof(FS_BIOSParameter)-sizeof(kal_uint16)];
    kal_uint16 Signature;
} __fs_packed_postfix FS_BootRecord;

#if defined(WIN32)
#pragma pack()
#endif
//------------------------------------- Packed Structures

typedef struct
{
    kal_uint32 Cluster;
    kal_uint32 Index;
    kal_uint32 Stamp;
    kal_uint32 Drive;
    kal_uint32 SerialNumber;
} FS_FileOpenHint;

/* Logical location */
typedef struct
{
    kal_uint32 Cluster;
    kal_uint32 Index;
} FS_FileLocationHint;

/* File information */
typedef struct
{
    const FS_DOSDirEntry * DirEntry;
    kal_uint32                  FilePos;
    kal_uint32                  AllocatedSize;
    kal_uint32                  ClusterChains;
    kal_uint32                  VolumeSerialNumber;
    const char           * FullName;
} FS_FileInfo;

/* Disk information */
typedef struct
{
    /* A zero-terminated <color Red><b>Short File Name</b></color> with the volume's label. */
    char            Label[24];

    /* The drive letter in <color Red><b>UPPER</b></color> case. */
    char            DriveLetter;

    /* Indicate the disk is in write protection or not. 1 for protect, 0 for not protect. */
    kal_uint8            WriteProtect;

    /* Reserved fields */
    char            Reserved[2];

    /* The volume's serial number. */
    kal_uint32            SerialNumber;

    /* The LBA address of the logical drive's boot record. For diskettes, this value will be 0. */
    kal_uint32            FirstPhysicalSector;

    /* 2, 16, or 32 for FAT-12, FAT-16, or FAT-32 */
    kal_uint32            FATType;

    /* The number of FATs on the volume. */
    kal_uint32            FATCount;

    /* The number of FATs on the volume. */
    kal_uint32            MaxDirEntries;

    /* The sector size. This value will usually be 512. */
    kal_uint32            BytesPerSector;

    /* Specifies the size of the smallest unit of storage that can be allocated to a file in sectors. */
    kal_uint32            SectorsPerCluster;

    /* Number of clusters for file storage on the volume. */
    kal_uint32            TotalClusters;

    /* The number of clusters, which are marked bad and are unavailable for file storage. */
    kal_uint32            BadClusters;

    /* The number of clusters currently available. */
    kal_uint32            FreeClusters;

    /* The number of files on the volume including directories, but not counting the root directory and files with an allocated file size of 0. */
    kal_uint32            Files;

    /* The number of contiguous cluster chains. On a completely unfragmented volume, this value would be identical to Files. */
    kal_uint32            FileChains;

    /* The number of contiguous cluster chains of free clusters. On a completely unfragmented volume, this value would be 1. */
    kal_uint32            FreeChains;

    /* The maximum allocated file size for a newly allocated contiguous file in clusters. On a completely unfragmented volume, this value would be identical to FreeClusters. */
    kal_uint32            LargestFreeChain;
} FS_DiskInfo;

typedef struct __fsdriver
{
    int  (* MountDevice)    (void * DriveData, int DeviceNumber, int DeviceType, kal_uint32 Flags);
    int  (* ShutDown)       (void * DriveData);
    int  (* ReadSectors)    (void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Buffer);
    int  (* WriteSectors)   (void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Buffer);
    int  (* MediaChanged)   (void * DriveData);
    int  (* DiscardSectors) (void * DriveData, kal_uint32 Sector, kal_uint32 Sectors);
    int  (* GetDiskGeometry)(void * DriveData, FS_PartitionRecord * DiskGeometry, kal_uint8 * MediaDescriptor);
    int  (* LowLevelFormat) (void * DriveData, const char * DeviceName, FS_FormatCallback Progress, kal_uint32 Flags);
    int  (* NonBlockWriteSectors)   (void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Buffer);
    int  (* RecoverableWriteSectors)(void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Buffer);
    int  (* ResumeSectorStates)     (void  * DriveData);
    int  (* HighLevelFormat)(void * DriveData, kal_uint32 BaseSector);
    int  (* RecoverDisk)    (void * DriveData);
    int  (* MessageAck)     (void * DriveData, int AckType);
    int  (* CopySectors)    (void * DriveData, kal_uint32 SrcSector, kal_uint32 DstSector, kal_uint32 Sectors);
    int  (* OTPAccess)      (void * DriveData, int type, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
    int  (* OTPQueryLength) (void * DriveData, kal_uint32 *Length);
    int  (* IOCtrl)         (void * DriveData, kal_uint32 CtrlAction, void * CtrlData); // For device IO control
} FS_Driver;

#ifndef MMI_ON_WIN32

typedef struct __fsMutex
{
    kal_semid   mt_sem;
    kal_taskid	mt_sem_owner;
    kal_uint32	mt_lock_count;
    int         DeviceNum_1;
    int         DeviceNum_2;
} FS_Mutex;

#else   // MMI_ON_WIN32

typedef kal_uint32 FS_Mutex;

#endif  // !MMI_ON_WIN32

struct __fsDrive;
struct __fsBuffer;

typedef struct __fsDeviceData
{
    FS_Mutex            * Lock;
    struct __fsDrive    * FirstDrive;
    kal_uint8           MediaPresent;
    kal_uint8           MediaRemovedReported;
    kal_uint8           Reserved;
    kal_uint8           MountState;
    int                 SectorSize;
    FS_PartitionRecord  Geometry;
    kal_uint32          SectorShift;
    kal_uint32          AccessCount;
    struct __fsBuffer   * B;
    struct __fsBuffer   * AltBuffer;
    int                 ErrorCondition;
    int                 PhysicalDiskIndex;
    char                FriendlyName[6];
    kal_uint8           MaxSectorPerBuffer;
    kal_uint8           MediaDescriptor;
} FS_DeviceData;

typedef struct __fsDevice
{
    int                 DeviceType;
    int                 DeviceNumber;
    kal_uint32          DeviceFlags;
    FS_Driver           * Driver;
    void                * DriverData;
    FS_DeviceData       DevData;
} FS_Device;

/* Direntry information */
typedef struct {
    kal_uint32          DirCluster;
    FS_FileLocationHint LongPos;
    FS_FileLocationHint ShortPos;
    FS_DOSDirEntry      Dir;
} FS_DirEntry;

typedef struct __fsDrive
{
    struct __fsDevice   * Dev;
    struct __fsDrive    * NextDrive;
    int                 MountState;
    FS_PartitionRecord  Geometry;
    kal_uint32          Clusters;
    kal_uint32          SectorsPerCluster;
    kal_uint32          ClusterSize;
    kal_uint32          ClusterShift;
    kal_uint32          SPerCShift;
    kal_uint32          FATType;
    kal_uint32          FATCount;
    kal_uint32          SectorsPerFAT;
    kal_uint32          ClusterWatermark;
    kal_uint32          FreeClusterCount;
    kal_uint32          InfoSector;
    kal_uint32          SerialNumber;
    kal_uint32          FirstSector;
    kal_uint32          FirstFATSector;
    kal_uint32          FirstDirSector;
    kal_uint32          FirstDataSector;
    kal_uint32          RootDirEntries;
    FS_DirEntry         CurrDirEntry;
    char                CurrDir[FS_MAX_PATH];
#ifdef __FS_QM_SUPPORT__
    kal_uint8           QuotaMgt;
    kal_uint8           Reserved[3];
#endif
} FS_Drive;

typedef struct __fsBuffer
{
    struct __fsBuffer   * Next;
    struct __fsBuffer   * Prev;
    FS_Device           * Dev;
    kal_uint8           * Data;
    kal_uint32          Sector;
    struct __fsDrive    * FATSectorInfo;
    kal_uint32          Flags;
    kal_uint32          FirstDirtyTime,
                        LastDirtyTime;
    int                 Num;
    kal_uint8           recoverable_flag;
    kal_uint8           SectorCount;
    kal_uint8           SectorOffset;
} FS_Buffer;

typedef struct
{
    WCHAR Pattern[8];
} FS_Pattern_Struct;

typedef struct __fsQuotaStruct
{
    kal_uint8           * Path;
    kal_uint32          Priority;
    kal_uint32          Qmin;
    kal_uint32          Qmax;
    kal_uint32          Uint;
} FS_QuotaStruct;

typedef struct __fsInternQStruct
{
    kal_uint32          Qmin;
    kal_uint32          Qmax;
    kal_uint32          Qnow;
} FS_InternQStruct;

typedef struct
{
    unsigned short      StaticHintCount;
    unsigned short      UsedStaticHintCount; // #static_hint + #classic_hint
    kal_uint32          StaticHintRange;
} FS_SeekHintData;

typedef struct __fsFile
{
    FS_Drive                * Drive;
    FS_Device               * Dev;
    kal_uint16              SpecialKind;
    kal_uint16              PrivateFlags;
    kal_uint32              Unique;
    kal_uint32              Flags;
    FS_DirEntry             DirEntry;
    kal_uint32              FilePointer;
    kal_uint32              LastCluster;
    kal_uint32              Cluster;
    kal_uint32              Offset;
    char                    FullName[FS_MAX_PATH + 2 * sizeof(WCHAR)];
    void                    * Task;
    kal_uint32              HintNum;
    FS_FileLocationHint     * Seek_Hint;
    fs_job_id               Job;
    fs_tbl_usr_ptr_type     usr_ptr_type;
    void                    * usr_ptr;
    kal_uint32              OwnerLR;
    kal_uint8               Lock;
    kal_uint8               Valid;
} FS_File;

// file table
#if   defined(NVRAM_AUTO_GEN)
#define fs_file_tbl_struct FS_File __attribute__((aligned(4))) __attribute__((__section__("_fs_filetable")))
#elif defined(__MTK_TARGET__)
#define fs_file_tbl_struct FS_File __attribute__((section("_fs_filetable")))
#else
#define fs_file_tbl_struct __pragma(section("_fs_filetable_content")) \
                            FS_File __declspec(allocate("_fs_filetable_content"))

#endif

// indirect init function (used for FS Quota structure only currently)
typedef void (*_indirect_init_func)(void);

#if   defined(NVRAM_AUTO_GEN)
#define sys_indirect_init_func _indirect_init_func __attribute__((aligned(4))) __attribute__((__section__("_indirect_init")))
#elif defined(__MTK_TARGET__)
#define sys_indirect_init_func _indirect_init_func __attribute__((section("_indirect_init")))
#else
#ifdef _MSC_VER
#define sys_indirect_init_func __pragma(section("_indirect_init_content")) \
                            _indirect_init_func __declspec(allocate("_indirect_init_content"))
#else
#define sys_indirect_init_func __attribute__((section("_indirect_init_content"))) \
                            _indirect_init_func __declspec(allocate("_indirect_init_content"))
#endif
#endif


typedef struct __fsTables
{
    FS_Drive    * DriveTable;
    FS_File     * FileTable;
    FS_Buffer   * BufferTable;
    kal_uint8   * BufferData;
} FS_Tables;

typedef struct __fsExceptionData
{
    kal_uint32  * Next;
    int         Data[11];
    int         XValue;
    int         State;
    int         IsHandled;
} FS_ExceptionData;

typedef struct __fsTaskIOStatistics
{
    kal_uint32 SectorCount;
    kal_uint32 AccessCount;
    kal_uint32 AccessTime;
} FS_TaskIOStatistics;

#define FS_GetIOStatisticsSize()  (sizeof(FS_TaskIOStatistics)*FS_MAX_THREAD)

/* Structure of FS_XFindReset parameters */
typedef struct
{
    /* The pattern needs to be found (Drive name must be the first word) */
    WCHAR *Pattern;

    /* Pattern array, such as {L".jpg", L".bmp"} or {L"*.*"} */
    FS_Pattern_Struct *PatternArray;

    /* The number of PatternArray */
    kal_uint32 PatternNum;

    /*
     * All the attributes in this mask will not match PatternArray but match default NamePattern.
     * If you don't want to specify it, please assign zero here.
     * Note:
     * 	1. If PatternNum is zero, NamePattern in FS_FindFirstN will be the default matching pattern.
     *  2. Don¡¦t mix this field, ArrayMask, with AttrMask of FS_XFindReset. The parameter in FS_XFindReset
     *     will filter out all the files/folders with such attributes!
     */
    kal_uint8 ArrayMask;

    /* Filter out the files/folders with such attributes */
    kal_uint8 AttrMask;

    /*
     * Choose at least one from Group1 to OR (|) one from Group2
     *      Group1: At Least one of the following two options should be chosen
     *              FS_FILE_TYPE (2): Sort file
     *              FS_DIR_TYPE (4): Sort folder
     *      Group2: Only one of the following six options should be chosen
     *              FS_NO_SORT (16): Do not sort
     *              FS_SORT_NAME (32): Sort by file name
     *              FS_SORT_SIZE (64): Sort by file size
     *              FS_SORT_ATTR (128): Sort by attribute
     *              FS_SORT_TYPE (256): Sort by creation time
     *              FS_SORT_TIME (512): Sort by update time
     *              FS_SORT_USER(1): Sort by user customized order.
     */
    kal_uint32 Flag;

    /*
     * Wait for lock or not (enum type)
     * 1. FS_NO_WAIT (0)
     * 2. FS_INFINITE (1)
     */
    kal_uint32 Timeout;

    /* Pointer to record the sorting result */
    kal_uint32 * Position;

    /* The progress callback that will be invoked during sorting procedure to notify the user the current sorting status. */
    SortingProgressCallback ProgressCallback;

    /* The user parameter that will be the input parameter of ProgressCallback. */
    void *ProgressCallbackParam;

    /* User specific compare function */
    SortingCompareFunc CompareFunc;

    /* The sorting buffer that is used to keep the sorting result. */
    kal_uint8 *SortingBuffer;

    /* This is used to identify the size of the sorting buffer. */
    int SortingBufferSize;

    /* This is the buffer that is used during sorting procedure. */
    kal_uint8 *WorkingBuffer;

    /* This is used to identify the size of the working buffer. */
    int WorkingBufferSize;
} FS_SortingParam;

/* Context of file list */
typedef struct
{
    FS_HANDLE handle;                   /* File Handle. It could be used for memory protection. Must set to 0 first */
    kal_uint8 attr_mask;
    kal_uint8 attr;

    kal_int32 index;                   /* Start index (count from 0) to fill into the list */
    kal_int32 used;                    /* Actual amount in the list */
    kal_int32 total;                   /* Max element amount that the list could carry */

    fs_progress_callback_func callback; /* user callback */
    void *param;                        /* user data */

    FS_FileLocationHint pos_buf[1];     /* Buffer of the list */
} fs_list_cntx_struct;

/* Parameters of FS_ListOpen */
typedef struct
{
    kal_wchar *path;                        /* which folder to list. format: <color Red><b>X:\\....\\ABC\\*.* </b></color>*/
    kal_uint8 attr_mask;                    /* attribute to match, for ex, ATTR_DIR */
    kal_uint8 attr;                         /* status of attr_mask, for ex, ATTR_DIR is on or off */

    /* option 2: select with attr_pattern */
    kal_uint8  attr_pattern;                /* attributes to match */

    /* option 1: select with pattern */
    FS_Pattern_Struct *name_pattern;        /* pattern to match. '*' or '?' are supported. Could be a list */
    kal_uint32 name_pattern_count;          /* count of pattern */

    kal_int32 index;                       /* Start index (count from 0) to fill into the list */

    fs_progress_callback_func callback;     /* user callback */
    void *param;                            /* user data */

    void *buff;                             /* buff for list context. MUST NOT release till FS_ListClose */
    kal_uint32 buff_size;                   /* size = FS_LIST_SIZE(N).  */
} fs_list_param_struct;

/*--------------------------------
 * Device Information (FS_IOCtrl)
 *--------------------------------*/

typedef struct
{
    kal_uint8   DeviceID[8];
    kal_uint32  BlockSize;
    kal_uint32  PageSize;
    kal_uint32  DeviceSize;
    kal_uint32  Flag;
} FS_NANDDeviceInfo;

typedef struct
{
    kal_uint8   DeviceID[8];
    kal_uint32  DeviceSize;
    kal_uint8   BootLocation;
} FS_NORDeviceInfo;

typedef struct
{
    kal_uint32  Flag;
    kal_uint32  PSN;
    kal_uint8   SerialMode;  // 1: 1-bit  0: 4-bits
} FS_CardDeviceInfo;

typedef struct
{
    union
    {
        FS_NANDDeviceInfo NAND;
        FS_NORDeviceInfo  NOR;
        FS_CardDeviceInfo Card;
    } DeviceInfo;
} FS_DeviceInfo;

/*-------------------------------
 * Physical Map Query (FS_IOCtrl)
 *-------------------------------*/

// PST Map Entry
typedef struct
{
    kal_uint32  SN;         // Sector No.
    kal_uint16  SecCnt;     // Number of continuous sectors
    kal_uint16  Reserved;
} FS_CardPMapEntry;

typedef struct
{
    kal_uint32  PPN;        // Physical Page No: 0 ~ 0x7FFFF (8192 Block x 64 Page)
    kal_uint16  SecOfs;     // The offset of starting sector in this page for required data (0 ~ 3)
    kal_uint16  SecCnt;     // Number of sectors in this page (1 ~ 4)
} FS_NANDPMapEntry;

// PST Map Header
typedef struct
{
    kal_uint8   ChipSel;    // Chip select (0 or 1)
    kal_uint8   Reserved[3];
} FS_NANDPMapHeader;

// PST Map
typedef struct
{
    FS_NANDPMapHeader   Header;
    FS_NANDPMapEntry   *Entry;
} FS_NANDPMap;

// for FS_IOCtrl's CtrlData
typedef struct
{
    FS_HANDLE           FH;             // [in]    : File handle of target file
    kal_uint32          Offset;         // [in]    : The beginning of file position for PST Map query
    kal_uint8          *pBuf;           // [in/out]: Please cast pBuf as FS_NANDPMap* for NAND or FS_CardPMapEntry* for memory card
    kal_uint32          BufSize;        // [in]    : Buffer size
    kal_uint16          ValidEntryCnt;  // [out]   : Number of valid PMap entry in pBuf
    kal_uint8           DevType;        // [out]   : Device type
    kal_uint8           Reserved;
} FS_PMapInfo;

// structure between FS and NAND device driver
typedef struct
{
    kal_uint32          LSN;            // [in]: Start sector no.
    kal_uint16          LSCnt;          // [in]: number of continuous sectors
    kal_uint16          ValidEntryCnt;  // [out]: number of buffer entries used by NAND driver
    kal_uint16          XferCnt;        // [out]: number of sectors transformed by NAND driver
    kal_uint8           ChipSel;        // [out]
    kal_uint8           Reserved;
    kal_uint32          BufSize;        // [in]
    FS_NANDPMapEntry   *pBuf;           // [in/out]
} FS_NANDPMapQuery;

typedef struct
{
    kal_uint8 initialized;
} fs_sysinfo_struct;

struct __fsJobApiStruct;
struct __fsJobStruct;
struct __fsAsyncCallbackDataStruct;

/*
 * Essential information of FS async I/F.
 *
 * User could allocate this structure locally and release it after FS async I/F is returned.
 */
typedef struct
{
    fs_prioity_enum         priority;   // priority configuration of this job (Deprecated)
    kal_uint8               priority_value;      // (Deprecated)
    kal_uint8               response_flag;       // refer to fs_response_enum
    fs_async_callback       callback;   // callback function pointer
    void                    *param;     // parameter of callback function
    void                    *buf;       // working buffer for FS aysnc I/F. Working buffer should be prepared by user.
    kal_uint32              buf_size;   // working buffer size. It should be at least <color Red><b>FS_ASYNC_WORKING_BUFFER_SIZE</b></color>.
} fs_overlapped_struct;  /* MUST SYNC */

/*
 * Data belongs to callback function.
 *
 * The address of this structure is exactly the <b>working buffer address</b>.
 * User could release working buffer in callback function.
 */
typedef struct __fsAsyncCallbackDataStruct
{
    fs_api_enum             api;        // The API enumeration of this job
    fs_job_state_enum       reserved1;  // Reserved
    kal_uint8               reserved2;  // Reserved
    kal_uint8               reserved3;  // Reserved
    fs_job_id               id;         // Job ID. It also appears in the 1st parameter of callback function.
    module_type             reserved4;  // Reserved
    kal_int64               result;     // Execution result of FS API. It also appears in the 2nd parameter of callback function.
    fs_async_callback       callback;   // Callback function pointer
    void                    *param;     // Parameter of callback function. It is defined in by user whenever FS async I/F is used.
} fs_async_callback_data_struct;  /* MUST SYNC with FS_JOB_STRUCT_HEADER_INTERNAL and fs_overlapped_struct */

/* DOM-NOT_FOR_SDK-BEGIN */

// fs_job_struct common header (totally 28 bytes)  /* MUST SYNC */
#define FS_JOB_STRUCT_HEADER_INTERNAL\
    fs_api_enum             api;\
    fs_job_state_enum       state;\
    kal_uint8               priority;\
    kal_uint8               response_flag;\
    fs_job_id               id;\
    module_type             mod_id;\
    kal_int64               result;\
    fs_async_callback       callback;\
    void                    * param;\
    struct __fsJobStruct    * next;

typedef struct __fsJobStruct
{
    FS_JOB_STRUCT_HEADER_INTERNAL
} fs_job_struct;

/* DOM-NOT_FOR_SDK-END */

typedef struct
{
    FS_JOB_STRUCT_HEADER_INTERNAL
    fs_job_id   job_id;
    kal_bool    aborted;
} fs_job_abort_struct;

typedef struct
{
    FS_JOB_STRUCT_HEADER_INTERNAL
    kal_wchar*  filename;   // !NOTE: Should we copy filename to our memory? or freed in user's callback?
    kal_uint32  flag;
    kal_uint32  caller_address;
} fs_job_open_struct;

typedef struct
{
    FS_JOB_STRUCT_HEADER_INTERNAL
    FS_HANDLE   handle;
    void        * data;
    kal_uint32  length;
    kal_uint32  * read;
    kal_uint32  chunksize;  // Separate the read operation to multiple small chunks in queue
} fs_job_read_struct;

typedef struct
{
    FS_JOB_STRUCT_HEADER_INTERNAL
    FS_HANDLE   handle;
    void        * data;
    kal_uint32  length;
    kal_uint32  * written;
} fs_job_write_struct;

typedef struct
{
    FS_JOB_STRUCT_HEADER_INTERNAL
    const kal_wchar * filename;
} fs_job_delete_struct;

typedef struct
{
    FS_JOB_STRUCT_HEADER_INTERNAL
    FS_HANDLE   handle;
    kal_int64   offset;
    kal_int32   whence;
} fs_job_seek_struct;

typedef struct
{
    FS_JOB_STRUCT_HEADER_INTERNAL
    const kal_wchar             * path;
    kal_int32                   flag;
    void                        * recursive_stack;
    kal_uint32                  stack_size;
    fs_progress_callback        progress;
} fs_job_get_folder_size_struct;

typedef struct
{
    FS_JOB_STRUCT_HEADER_INTERNAL
    kal_wchar           * name_pattern;
    kal_uint8           attr;
    kal_uint8           attr_mask;
    FS_DOSDirEntry      * file_info;
    kal_wchar           * file_name;
    kal_uint32          max_length;
} fs_job_find_first_struct;

typedef struct
{
    FS_JOB_STRUCT_HEADER_INTERNAL
    kal_wchar           * name_pattern;
    FS_Pattern_Struct   * pattern_array;
    kal_uint32          pattern_num;
    kal_uint8           array_mask;
    kal_uint8           attr;
    kal_uint8           attr_mask;
    FS_DOSDirEntry      * file_info;
    kal_wchar           * file_name;
    kal_uint32          max_length;
    kal_uint32          entry_index;
    kal_uint32          flag;
} fs_job_find_first_n_struct;

typedef struct __fsJobApiStruct
{
    union
    {
        fs_job_open_struct              open_struct;
        fs_job_read_struct              read_struct;
        fs_job_seek_struct              seek_struct;
        fs_job_write_struct             write_struct;
        fs_job_abort_struct             abort_struct;
        fs_job_delete_struct            delete_struct;
        fs_job_find_first_struct        find_first_struct;
        fs_job_find_first_n_struct      find_first_n_struct;
        fs_job_get_folder_size_struct   get_folder_size_struct;
    } api;
} fs_job_api_struct;

typedef enum
{
    FS_JOB_TYPE_ASYNC_API       = 0,
    FS_JOB_TYPE_INVALID         = 0xFF
} fs_job_type_enum;

typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;
    fs_job_type_enum    type;
    fs_job_struct       * job;
} fs_job_req_struct;

typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;
    fs_job_struct       * job;
} fs_job_rsp_struct;

/*----------------------------------------------------------
 * FS Async I/F Alone Version (internal structures)
 *----------------------------------------------------------*/

typedef struct
{
    kal_uint8                               ref_count;
    kal_uint16                              msg_len;
    fs_async_callback_data_struct           * data;
} fs_job_alone_rsp_struct;

typedef struct
{
    fs_util_ucs_to_wchar_func                   ucs_to_wchar_func;
    fs_util_get_default_encoding_length_func    get_default_encoding_length_func;
} fs_config_encoding_api_struct;

/*---------------------------------------------------------------------------
 * Macros
 *---------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * Retrieve FS_FileOpenHint structure from FS_DOSDirEntry structure
 *
 * Purpose: FS_FindFirst / FS_FindNext series APIs support open hint feature.
 * For minimum modification, we append FS_FileOpenHint members to FS_DOSDirEntry
 * structure.
 *-------------------------------------------------------------------- W09.19 --*/
#define FS_GetOpenHintByDOSDirEntry(DOSDirEntry) ((FS_FileOpenHint*)((kal_uint8*)&(((FS_DOSDirEntry*)(DOSDirEntry))->FileSize) + sizeof(kal_uint32)))

// get file table index from a file handle
#define FS_GetFileTableIdx(FileHandle) ((FileHandle) & ((1 << (4 * sizeof(int))) - 1))

/*-------------------------------
 * FS Smart File Seeker Support
 *-------------------------------*/
// buffer calculation
#define FS_SEEKHINT_BUFFER_SIZE_FOR_HINT_CNT(N) (sizeof(FS_SeekHintData) + (N) * sizeof(FS_FileLocationHint))

#define FS_LIST_ENTRY(X)        (X - 108)/sizeof(FS_FileLocationHint) /* To calculate size of buff with given entry count N. */

#define FS_LIST_SIZE(N)         (108 + N*sizeof(FS_FileLocationHint)) /* To get entry count with given buff_size X */

// The working buffer contains              1. HintList(4) 2. HintList2(4) 3. FileName(520) 4. TmpName1(520) 5. TmpName2(520)
//                                          6. FileInfo(RTFDOSDirEntry)
// The sorting buffer contains              1. Sizeof(FSSortingInternalS) 2. PosList(8)

#define FS_SORT_WORKING_BUFFER_SIZE                 ((FS_SORTING_MAX_FILES*(4+4))+3*(FS_MAX_PATH+4)+sizeof(FS_DOSDirEntry))
#define FS_SORT_SORTING_BUFFER_SIZE                 ((FS_SORTING_MAX_FILES*8)+(21*4) /* sizeof(FSSortingInternalS) */)

#define FS_SORT_WORKING_BUFFER_SIZE_FOR_FILES(x)    (((x+3)*(4+4))+3*(FS_MAX_PATH+4)+sizeof(FS_DOSDirEntry))
#define FS_SORT_SORTING_BUFFER_SIZE_FOR_FILES(x)    (((x+3)*8)+(21*4) /*sizeof(FSSortingInternalS)*/)
#define FS_SORT_FILES_FOR_TOTAL_BUFFER_SIZE(m)      (((m-84-(3*(FS_MAX_PATH+4))-sizeof(FS_DOSDirEntry))/16)-3)

#define FS_MOVE_BUFFER_SIZE_FOR_FOLDER_LEVEL(x)     (72+3*(FS_MAX_PATH+4+sizeof(int))+2048+x*52)
#define FS_XDELETE_BUFFER_SIZE_FOR_FOLDER_LEVEL(x)  (72+3*(FS_MAX_PATH+4+sizeof(int))+x*52)

// provide working buffer size for FS async I/F
#define FS_ASYNC_WORKING_BUFFER_SIZE                (sizeof(fs_job_api_struct))


/*---------------------------------------------------------------------------
 * File System APIs
 *---------------------------------------------------------------------------*/

#if !(defined(__CCCIFS_SUPPORT__) && defined(__MTK_TARGET__))

// Feature Phone Proto types

/*****************************************************************************
 * <GROUP  FileContent>
 *
 * FUNCTION
 *  FS_Open
 * DESCRIPTION
 *  FS_Open opens and possibly creates a file for subsequent read and/or write access.
 * PARAMETERS
 *  FileName  : [IN]<P>Must point to the name of the file to open/create.
 *                    File names are not case sensitive; they will be converted to
 *                    upper case when file system searches this file, and they should
 *                    be two-byte aligned and UCS2 encoded. The file name can have one
 *                    of the following formats:
 *                    [Drive:][\][Path\]Name[.Ext]  A data file or directory file name with optional drive and path information.
 *                    [Drive:]\                     A root directory.
 *                    \\.\Drive:                    A logical drive.
 *                    \\.\PHYSICALDRIVEx            A physical hard disk. x must be a digit (starting at '0') specifying the desired hard disk.
 *                    \\.\FMapF\[hexstrings]        A virtual file, the whole path name should be generated by the dedicated FS_GenVirtualFileName API.
 *  Flag      : [IN]<P>Can be a combination of the following flags:
 *                      FS_READ_WRITE       FS_READ_ONLY    FS_OPEN_SHARED      FS_OPEN_NO_DIR
 *                      FS_OPEN_DIR         FS_CREATE       FS_CREATE_ALWAYS    FS_COMMITTED
 *                      FS_CACHE_DATA       FS_LAZY_DATA    FS_ATTR_HIDDEN      FS_ATTR_SYSTEM
 *                      FS_ATTR_ARCHIVE     FS_NONBLOCK_MODE    FS_PROTECTION_MODE
 * RETURNS
 *  Please refer to fs_error_enum.
 * NOTE
 *  If the function succeeds, the return value is a file handle for the
 *  opened file and the file pointer of the file is set to 0. If the return
 *  value is less than 0, the function has failed and the return value is the
 *  error code. For data and directory files, the same rules for file name
 *  syntax apply as under MS-DOS. For logical drive and physical disk file
 *  names, the same rules as under Windows NT apply.
 * SEE ALSO
 *  fs_error_enum
 *****************************************************************************/
extern int FS_Open(const WCHAR * FileName, UINT Flag);

/*****************************************************************************
 * <GROUP  Obsolete >
 *
 * FUNCTION
 *  FS_OpenHint
 * DESCRIPTION
 *  Open a file with location hint to reduce the search time.
 * PARAMETERS
 *  FileName  : [IN]<P>refer to FS_Open
 *  Flag      : [IN]<P>refer to FS_Open
 *  DSR_Hint  : [IN]<P>FS_FileOpenHint.
 *      The first time that invoke open hint function, the Cluster and Index
 *      fields of DSR_Hint must be 0. If the file is opened successfully, it
 *      returns the opened file¡¦s location information by the DSR_Hint. Next
 *      time, if the same file needs to be opened, opening file with this
 *      DSR_Hint can reduce the searching time.
 *      It's not allowed to pass arbitrary Cluster and Index value of DSR_Hint
 *      to FS_OpenHint.
 *      If passing NULL as DSR_Hint, this function performs the same as FS_Open.
 * RETURNS
 *  Refer to FS_Open
 * SEE ALSO
 *  FS_Open
 *****************************************************************************/
extern int FS_OpenHint(const WCHAR * FileName, UINT Flag, FS_FileOpenHint * DSR_Hint);

/*****************************************************************************
 * <GROUP  FileContent>
 *
 * FUNCTION
 *  FS_Close
 * DESCRIPTION
 *  To close an open file and return a file handle back.
 * PARAMETERS
 *  FileHandle  : [IN]<P>the handle. Must have been assigned in a previous
 *                      successful call to FS_Open. FS_Close will write
 *                      any un-flushed file data to the disk (except for
 *                      FS_DEVICE_LAZY_WRITE devices) and release all
 *                      resources associated with the file handle.
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	Please refer to fs_error_enum.
 * SEE ALSO
 *  fs_error_enum
 *****************************************************************************/
extern int FS_Close(FS_HANDLE FileHandle);

/*****************************************************************************
 * <GROUP  FileContent>
 *
 * FUNCTION
 *  FS_Read
 * DESCRIPTION
 *  To read data from a opened file.
 * PARAMETERS
 *  FileHandle : [IN] <P>References the open file from which to read.
 *  DataPtr    : [OUT]<P>Specifies the address for the data to be read.
 *  Length     : [IN] <P>Specifies the number of bytes to read
 *  Read       : [OUT]<P>Pointer to an unsigned integer to receive the number of
 *                      bytes actually read. Usually, *Read will contain Length
 *                      after the call. However, in case of an error or if the
 *                      end of file is encountered during the read, the value may
 *                      be less. Read may be set to NULL if this information is
 *                      not required by an application.
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	Please refer to fs_error_enum.
 *              Details -   Reading past the end of file is not regarded as an error.
 *                          If FS_Read returns FS_NO_ERROR, but *Read is less than
 *                          Length, the end of file has been encountered. Reading on
 *                          a virtual file but its mapped file closed somehow,
 *                          FS_VF_MAP_ERROR error code is returned. This function
 *                          advances the file's file pointer by the amount given in
 *                          *Read. In case of an error and if parameter Read is NULL,
 *                          the new file pointer is undefined.
 *****************************************************************************/
extern int FS_Read(FS_HANDLE FileHandle, void * DataPtr, UINT Length, UINT * Read);

/*****************************************************************************
 * <GROUP  FileContent>
 *
 * FUNCTION
 *  FS_Write
 * DESCRIPTION
 *  To write data to a file.
 * PARAMETERS
 *  FileHandle : [IN] <P>References the open file to write to.
 *  DataPtr    : [IN] <P>Specifies the address of the data to be written.
 *  Length     : [IN] <P>Specifies the number of bytes to write.
 *  Written    : [OUT]<P>Pointer to an unsigned integer to receive the number of
 *                      bytes actually been written. Usually, *Written will contain
 *                      Length after the call. However, in case of an error, the
 *                      returned value may be less. Written may be set to NULL if
 *                      this information is not required by an application.
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	Please refer to fs_error_enum.
 *              Details -   Writing past the current end of file will automatically
 *                          extend the file. When the file size exceeds the current
 *                          allocated file size, new clusters are allocated for the
 *                          file. FS will allocate new clusters immediately following
 *                          the current last cluster, if possible. This function
 *                          advances the file's file pointer by the amount given in
 *                          *Written. In case of an error and if parameter Written
 *                          is NULL, the new file pointer is undefined.
 *****************************************************************************/
extern int FS_Write(FS_HANDLE FileHandle, void * DataPtr, UINT Length, UINT * Written);

/*****************************************************************************
 * <GROUP  FileContent>
 *
 * FUNCTION
 *  FS_SetSeekHint
 * DESCRIPTION
 *  This function provides user to specify several check points of file to speedup
 *  the seek function. FS_Seek will start to seek from these places.
 * PARAMETERS
 *  FileHandle : [IN]<P>The file handle to be seeked
 *  HintNum    : [IN]<P>Number of hint
 *  Hint       : [IN]<P>Pointer to user defined hint
 * RETURNS
 *  Success:    The number of hint that is successfully set
 *  Error:      FS_ACCESS_DENIED
 * NOTE
 *     1. User should specify the hint in "bytes".
 *     2. This function only provides hint. One should not call this to extend file.
 *        i.e. Hint in bytes cannot be larger than the file size.
 *     3. User should allocate and free the memory by himself
 *     4. User should sort the hint by himself (small to big), or hint setting will
 *        be stopped by the number not in sequence
 *     5. After processed, "index" in each hint entry is cluster-aligned and is a "absolute"
 *        file offset in bytes. "Cluster" is the corresponding cluster number of each index.
 *****************************************************************************/
extern int FS_SetSeekHint(FS_HANDLE FileHandle, UINT HintNum, FS_FileLocationHint * Hint);

/*****************************************************************************
 * <GROUP  FileContent>
 *
 * FUNCTION
 *  FS_SetSeekHintEx
 * DESCRIPTION
 *  A seek hint is a milestone to remember the physical address of a specified
 *  file offset. With seek hint, FS can seek from an installed milestone to save
 *  the seek time.
 *  This function provides a convenient and efficient way to enable this facility
 *  for a specified file handle. After this API is used for a specified file
 *  handle, FS will install¡§seek hints¡¨ automatically during any following
 *  FS_Seek, FS_Read and FS_Write operations on the same file handle.
 *  After file is extended or truncated, seek hints will also be adjusted
 *  automatically. Any seek hint operations are transparent to users.
 * PARAMETERS
 *  FileHandle : [IN]<P>The target file handle
 *  HintCount  : [IN]<P>Number of hint
 *  Flag       : [IN]<P>Flag for configuring the behavior of FS_SetSeekHintEx
 *      FS_SEEKHINT_FLAG_INITIALIZE_HINT - Setting the flag will let FS_SetSeekHintEx
 *                                         immediately install all hints.
 *      Otherwise - hints will be installed automatically during following file
 *                  operations, like FS_Write, FS_Read and FS_Seek.
 *  Buffer     : [IN]<P>User should allocate and free a buffer for FS_SetSeekHintEx.
 *                      Buffer address should be 4-byte alignment.
 *  BufferSize : [IN]<P>To have N seek hints, please use
 *                      FS_SEEKHINT_BUFFER_SIZE_FOR_HINT_CNT(N) to get the buffer
 *                      size for N seek hints.
 * RETURNS
 *  Success:    FS_NO_ERROR
 *  Error:      List below
 * RETURN VALUES
 *  FS_INVALID_FILE_HANDLE: File handle is invalid, or target file is not Normal File.
 *      (Only Normal File supports this facility, other file type like Virtual File,
 *      Volume File and Physical Disk does not support currently).
 *  FS_ACCESS_DENIED: Hint is NULL buffer or file system is not initialized
 *  FS_FAIL_GET_MEM:
 *      1. Buffer pointer is NULL or BufferSize is not enough for N seek hints.
 *      2. Buffer has been used by another file handle.
 *  FS_FAT_ALLOC_ERROR: Target file¡¦s cluster chain is broken.
 *  FS_DEVICE_EXPORTED_ERROR: The device on which the target file handle is exported.
 *  FS_MEDIA_CHANGED: The device on which the target file handle is removed or changed.
 * EXAMPLE
 * <code>
 *      #define MY_FILE_PATH    L"E:\\1.mp3"
 *      #define MY_HINT_NUM     5
 *      #define MY_HINT_BUFFER_SIZE (FS_SEEKHINT_BUFFER_SIZE_FOR_HINT_CNT(MY_HINT_NUM))
 *      #define MY_TARGET_BYTE ¡K
 *
 *      FS_HANDLE MyHandle;
 *      __align(4) char MyHint[MY_HINT_BUFFER_SIZE];
 *      int dRetval;
 *
 *      MyHandle = FS_Open(MY_FILE_PATH, FS_OPEN_NO_DIR);
 *      If (MyHandle > FS_NO_ERROR)
 *      {
 *          dRetval = FS_SetSeekHintEx(MyHandle, MY_HINT_NUM, 0, (void*)MyHint, MY_HINT_BUFFER_SIZE);
 *          if (dRetval > FS_NO_ERROR)
 *      	    dRetval = FS_Seek(MyHandle, MY_TARGET_BYTE, FS_FILE_BEGIN);
 *      }
 * </code>
 * NOTE
 *  1. Hint buffer memory should be allocated and freed by caller himself.
 *  2. Hint buffer memory should be unique for different file handle! Any conflict
 *     usage will get FS_FAIL_GET_MEM error code.
 *  3. Please use FS_SEEKHINT_BUFFER_SIZE_FOR_HINT_CNT(N) to get the buffer size for
 *     N seek hints.
 *  4. User could let seek hint be installed during following file operations (default),
 *     or be installed once this API is called (by set FS_SEEKHINT_FLAG_INITIALIZE_HINT
 *     flag in Flag parameter).
 *****************************************************************************/
extern int FS_SetSeekHintEx(FS_HANDLE FileHandle, UINT HintCount, UINT Flag, void *Buffer, UINT BufferSize);

/*****************************************************************************
 * <GROUP  FileContent>
 *
 * FUNCTION
 *  FS_SeekLargeFile
 * DESCRIPTION
 *  Extended version of FS_Seek.
 * PARAMETERS
 *  FileHandle  : [IN] <P>References the open file for which to reposition the file pointer.
 *  Offset      : [IN] <P>Specifies how far the file pointer should be moved. Please note that Offset is a signed long value.
 *  Whence      : [IN] <P>Specifies Offset's meaning. Please refer to FS_SEEK_POS_ENUM.
 * RETURNS
 *  Please refer to FS_Seek.
 *****************************************************************************/
extern kal_int64 FS_SeekLargeFile(FS_HANDLE FileHandle, kal_int64 Offset, int Whence);

/*****************************************************************************
 * <GROUP  FileContent>
 *
 * FUNCTION
 *  FS_Seek
 * DESCRIPTION
 *  Repositions a file pointer and possibly extends a file.
 * PARAMETERS
 *  FileHandle  : [IN] <P>References the open file for which to reposition the file pointer.
 *  Offset      : [IN] <P>Specifies how far the file pointer should be moved.
 *  Whence      : [IN] <P>Specifies Offset's meaning. Please refer to FS_SEEK_POS_ENUM.
 * RETURNS
 *  If the function succeeds, the return value is the new file pointer value, or,
 *  if the file pointer is larger than 231-1, FS_LONG_FILE_POS is returned.
 *  In this case, the actual file pointer can be queried using function FS_GetFileInfo.
 *  If the function fails, the return value is some other negative error code.
 *  Moving the file pointer before the beginning of the file is an error.
 *  However, moving it beyond the current file size is supported.
 *  In this case, the file is extended. The data between the previous file size
 *  and the new file size is undefined. This method to extend a file is much faster
 *  than actually writing data to it.
 *  Seeking on a virtual file but its mapped file closed somehow, FS_VF_MAP_ERROR error code is returned.
 *****************************************************************************/
extern int FS_Seek(FS_HANDLE FileHandle, int Offset, int Whence);

/*****************************************************************************
 * <GROUP  FileContent>
 *
 * FUNCTION
 *  FS_Commit
 * DESCRIPTION
 *  Immediately flushes all buffers associated with a file to disk.
 * PARAMETERS
 *  FileHandle  : [IN]<P>References the open file from which to read.
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	Please refer to fs_error_enum.
 * Details
 *  FS_Commit guarantees that all of the file's data is flushed. If the file
 *  was opened with flag FS_LAZY_DATA, all dirty buffers of the file's drive
 *  are flushed. Otherwise, the file's data buffer, directory entry, and the
 *  complete FAT are flushed.
 *****************************************************************************/
extern int FS_Commit(FS_HANDLE FileHandle);

/*****************************************************************************
 * <GROUP  AsyncIF>
 *
 * FUNCTION
 *  FS_Abort
 * DESCRIPTION
 *  This function can abort the action on specified file handle right away.
 * PARAMETERS
 *  ActionHandle : [IN]
 *      (1) The action on the specified file handle will be aborted.
 *      (2) FS_ABORT_CHECK_DRIVE (0x12345678): Special file handle to abort drive check
 *      (3) FS_ABORT_XDELETE (0x87654321): Special file handle to abort FS_XDelete
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	Please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_Abort(UINT ActionHandle);

/*****************************************************************************
 * <GROUP  FileOperation>
 *
 * FUNCTION
 *  FS_ParseFH
 * DESCRIPTION
 *  This function parse the file handle to a index between 0 to FS_MAX_FILES
 * PARAMETERS
 *  FileHandle : [IN] <P>File handle to be parsed
 * RETURNS
 *  The zero-based index or fs_error_enum.
 *****************************************************************************/
extern int FS_ParseFH(FS_HANDLE FileHandle);

/*****************************************************************************
 * <GROUP  VirtualOperation>
 *
 * FUNCTION
 *  FS_GenVirtualFileName
 * DESCRIPTION
 *  Some file formats pack multiple objects inside. This API is designed for programmers
 *  who want to process inside objects without copy overhead. Users call this API to
 *  generate a virtual file name (full-path string in fact) first. Then users can
 *  FS_Open(), FS_Read(), and FS_Seek() against virtual file just like a normal file.
 *  The generated virtual filename is a wide-character type, null-terminated string.
 *  The length (in byte unit) is defined as a MACRO named FS_GenVFN_SIZE. For user's
 *  convenience, it is allowed to replace the null-terminated character with a dot
 *  character and append arbitrary extension name such as ¡§.jpeg¡¨.
 *  Currently, APIs that support virtual file are FS_Open(), FS_Read(), FS_Seek(),
 *  FS_Close(), FS_GetFileInfo(), FS_GetFileSize(), and FS_GetFilePosition().
 * PARAMETERS
 *  FileHandle  : [IN] <P>The file-handler of the real-file that virtual-file mapped into.
 *  VFileNameBuf: [IN] <P>A pointer of the file name string buffer provided to store generated file name.
 *  BufLength   : [IN] <P>The available buffer length (in byte unit) of VFileNameBuf provided to prevent buffer overflow.
 *  VFBeginOffset:[IN] <P>Specify the segment beginning (in byte unit) in the real-file to be treated as virtual-file content.
 *  VFValidLength:[IN] <P>Specify the segment length (in byte unit) in the real-file to be treated as virtual-file content.
 * RETURNS
 *  Successful  : FS_NO_ERROR
 *  Failed      : Please refer to fs_error_enum.
 * EXAMPLE
 * <code>
 * </code>
 * NOTE
 *  There are 2 major constrictions you should keep in mind while using virtual-file.
 *  (1) The mapped file must be opened before FS_GenVirtualFileName() are called, and
 *      should be closed after all generated virtual file are closed. On the other word,
 *      once user close the mapped file, all virtual file name generated by
 *      FS_GenVirtualFileNmae() call are invalid.
 *  (2) Both mapped file and virtual file must FS_Open() with FS_READ_ONLY flag. User
 *      cannot update virtual file or mapped file by FS_Write().
 *****************************************************************************/
extern int FS_GenVirtualFileName(FS_HANDLE FileHandle, WCHAR * VFileNameBuf, UINT BufLength, UINT VFBeginOffset, UINT VFValidLength);

/*****************************************************************************
 * <GROUP  DirectoryEntry>
 *
 * FUNCTION
 *  FS_GetFileInfo
 * DESCRIPTION
 *  Return file information about an open file.
 * PARAMETERS
 *  FileHandle : [IN]   <P>References the open file from which to read.
 *  FileInfo   : [OUT]  <P>Refer to FS_FileInfo, FS_DOSDataTime and FS_DOSDirEntry
 * RETURNS
 *  Successful  : FS_NO_ERROR
 *  Failed      : Please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_GetFileInfo(FS_HANDLE FileHandle, FS_FileInfo * FileInfo);

/*****************************************************************************
 * <GROUP  DirectoryEntry>
 *
 * FUNCTION
 *  FS_GetFileInfoEx
 * DESCRIPTION
 *  Return file information about an open file.
 * PARAMETERS
 *  FileHandle : [IN]   <P>References the open file from which to read.
 *  FileInfo   : [OUT]  <P>Refer to FS_FileInfo, FS_DOSDataTime and FS_DOSDirEntry
 *  Flags      : [IN]   <P>Refer to fs_fi_enum *
 * RETURNS
 *  Successful  : FS_NO_ERROR
 *  Failed      : Please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_GetFileInfoEx(FS_HANDLE FileHandle, FS_FileInfo *FileInfo, UINT Flags);

/*****************************************************************************
 * <GROUP  DirectoryEntry>
 *
 * FUNCTION
 *  FS_GetFileSize
 * DESCRIPTION
 *  Retrieve the current size of an open file.
 * PARAMETERS
 *  FileHandle : [IN]   <P>References the open file for which to retrieve the file size.
 *  Size       : [OUT]  <P>Must point to the int to receive the file's size.
 * RETURNS
 *  Successful  : FS_NO_ERROR
 *  Failed      : Please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_GetFileSize(FS_HANDLE FileHandle, UINT * Size);

/*****************************************************************************
 * <GROUP  DirectoryEntry>
 *
 * FUNCTION
 *  FS_GetFilePosition
 * DESCRIPTION
 *  Retrieve the current file pointer position of an open file.
 *      Note:   We provide this function to save a lot of time if application just
 *              wants to know the file pointer information. Because FS_GetFileInfo
 *              will cost a lot of to traverse the file allocated cluster chain.
 * PARAMETERS
 *  FileHandle : [IN] <P>File handle to reference the open file for which to retrieve the file pointer.
 *  Position   : [OUT]<P>The current file pointer of the opened file
 * RETURNS
 *  This function always returns FS_NO_ERROR.
 * EXAMPLE
 * <code>
 *      kal_uint32 file_position;
 *
 *      FS_GetFilePosition(myHandle, &file_position);
 * </code>
 *****************************************************************************/
extern int FS_GetFilePosition(FS_HANDLE FileHandle, UINT * Position);

/*****************************************************************************
 * <GROUP  DirectoryEntry>
 *
 * FUNCTION
 *  FS_SetFileTime
 * DESCRIPTION
 *  Set the last modify information in a file's directory entry.
 * PARAMETERS
 *  FileHandle : [IN]  <P>References the open file for which to set the time and date.
 *  Time       : [OUT] <P>the time when this file is modified. Refer to FS_DOSDateTime
 * RETURNS
 *  FS will update the file's date and time on every write access. Thus, function
 *  FS_SetFileTime should not be followed by a call to FS_Write, since this would
 *  overwrite the date and time set by FS_SetFileTime.
 *****************************************************************************/
extern int FS_SetFileTime(FS_HANDLE FileHandle, const FS_DOSDateTime * Time);

/*****************************************************************************
 * <GROUP  DirectoryEntry>
 *
 * FUNCTION
 *  FS_GetAttributes
 * DESCRIPTION
 *  Returns the attributes set for a specific file.
 * PARAMETERS
 *  FileName : [IN]<P>It's the file path for which to retrieve the attributes.
 * RETURNS
 *  The value(s) below
 * RETURN VALUES
 *  FS_ATTR_READ_ONLY
 *  FS_ATTR_HIDDEN
 *  FS_ATTR_SYSTEM
 *  FS_ATTR_VOLUME
 *  FS_ATTR_DIR
 *  FS_ATTR_ARCHIVE
 *****************************************************************************/
extern int FS_GetAttributes(const WCHAR * FileName);

/*****************************************************************************
 * <GROUP  DirectoryEntry>
 *
 * FUNCTION
 *  FS_SetAttributes
 * DESCRIPTION
 *  Returns the attributes set for a specific file.
 * PARAMETERS
 *  FileName    : [IN] <P>It's the file path for which to retrieve the attributes.
 *  Attributes  : [IN] <P>
 *  FS_ATTR_READ_ONLY
 *  FS_ATTR_HIDDEN
 *  FS_ATTR_SYSTEM
 *  FS_ATTR_VOLUME
 *  FS_ATTR_DIR
 *  FS_ATTR_ARCHIVE
 * RETURNS
 *  Please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_SetAttributes(const WCHAR * FileName, BYTE Attributes);

/*****************************************************************************
 * <GROUP  FileOperation>
 *
 * FUNCTION
 *  FS_Delete
 * DESCRIPTION
 *  Delete a file.
 * PARAMETERS
 *  FileName    : [IN] <P>Must point to the name of the file to be deleted and may not contain wildcards. This function cannot delete directories.
 * RETURNS
 *  Please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_Delete(const WCHAR * FileName);

/*****************************************************************************
 * <GROUP  VirtualOperation>
 *
 * FUNCTION
 *  FS_PseudoMerge
 * DESCRIPTION
 *  This function provides facility for Multimedia task to merge audio and video
 *  files.
 * PARAMETERS
 *  FileName1: [IN]<P>File being extended
 *  FileName2: [IN]<P>Append to FileName1, and FileName2 will be deleted
 * RETURNS
 *  Successful  : FS_NO_ERROR
 *  Failed      : List below
 * RETURN VALUES
 *  FS_INVALID_FILENAME(-3): FileName1 or FileName2 are invalid.
 *  FS_ACCESS_DENIED(-16):
 *          1. FileName1 and FileName2 located on different drive
 *          2. FileName1 or FileName2 are opened by others
 *  FS_FILE_NOT_FOUND(-9): FileName1 not found
 *  FS_READ_ONLY_ERROR(-45): FileName1 or FileName2 contain read-only
 *                           or directory file attributes.
 *  FS_FAT_ALLOC_ERROR (-20): The cluster chains of FileName1 or FileName2
 *                            are incorrect.
 * EXAMPLE
 * <code>
 *      int reval;
 *      reval  = FS_PseudoMerge(L"E:\\2.mp3", L"E:\\3.mp3");
 * </code>
 * NOTE
 *  This function will
 *  (1) Check file size and cross link of the input files
 *  (2) Append File2 to File1 without caring the last cluster of
 *      File1 is not cluster alinged. One calling this API should
 *      be aware that FS_COMMITTED is the default setting of this call.
 *****************************************************************************/
extern int FS_PseudoMerge(const WCHAR * FileName1, const WCHAR * FileName2);


/******************************************************************************
 * <GROUP  FileOperation>
 *
 * FUNCTION
 *  FS_CheckFile
 * DESCRIPTION
 *  This function provides facility for user to check a file. It will check
 *  if this exists or not first and then check the cluster chain. If
 *  invalid cluster is allocated (for an example, 0), error code,
 *  FS_CHECKDISK_RETRY (-41), will be returned. Finally, it will check if
 *  the file size fit the allocation size. If not, the file size will be
 *  adjusted.
 * PARAMETERS
 *  FileName: [IN]<P>File to be checked
 * RETURNS
 *  If the function succeeds, the return value is FS_NO_ERROR. If the function fails, the return value is a negative error code. If FS_CHECKDISK_RETRY (-41) is returned, it means the file has allocated an invalid cluster. You should ask for check the whole drive to fix this error.
 * NOTE
 *  This function will adjust the allocated clusters to fit the file size
 *  automatically if needed.
 *
 * <xtable>
 * Allocated Cluster   Original File   FS_PseudoMerge                   FS_CheckFile
 *                      Size (Byte)
 * ------------------  --------------  -------------------------------  -------------------------------
 * 0 ( 0 bytes)        N/A             N/A                              0
 * 1 (1024 bytes)      100             100                              100
 * 1 (1024 bytes)      1024            1024                             1024
 * 2 (2048 bytes)      1024            <color Red><b>2048</b></color>   <color Red><b>1024</b></color>
 * 2 (2048 bytes)      1537            1537                             1537
 * 3 (3072 bytes)      3073            3072                             3072
 * 3 (3072 bytes)      2049            2049                             2049
 * </xtable>
 *****************************************************************************/
extern int FS_CheckFile(const WCHAR * FileName);

/*****************************************************************************
 * <GROUP  FolderOperation>
 *
 * FUNCTION
 *  FS_GetCurrentDir
 * DESCRIPTION
 *  Return the current drive and directory.
 * PARAMETERS
 *  DirName    : [OUT] <P>Must point to a string buffer to receive the full path
 *                        of the current directory.
 *  MaxLength  : [IN]  <P>Specifies the size of the buffer passed in DirName.
 *                        It is recommended to use a buffer with FS_MAX_PATH (520)
 *                        characters length. If the buffer is too small to hold
 *                        the current path, the function fails.
 * RETURNS
 *  If the function succeeds, the return value is FS_NO_ERROR and the current
 *  path has been copied to the specified buffer. If the function fails, the
 *  return value is a negative error code.
 *
 * NOTE
 *  This funciton returns the directory set by the nearest FS_SetCurrentDir(). To get
 *  current directory of a specified drive, please use FS_GetCurrentDirByDrive().
 *****************************************************************************/
extern int FS_GetCurrentDir(WCHAR * DirName, UINT MaxLength);

/*****************************************************************************
 * <GROUP  FolderOperation>
 *
 * FUNCTION
 *  FS_GetCurrentDirByDrive
 * DESCRIPTION
 *  Return the current drive and directory by given path.
 * PARAMETERS
 *  DirName    : [OUT]<P>Must point to a string buffer to receive the full path
 *                      of the current directory, including a drive letter.
 *  MaxLength  : [IN] <P>Specifies the size of the buffer passed in DirName.
 *                      It is recommended to use a buffer with FS_MAX_PATH (520)
 *                      characters length. If the buffer is too small to hold
 *                      the current path, the function fails.
 * RETURNS
 *  Please refer to FS_GetCurrentDir.
 *****************************************************************************/
extern int FS_GetCurrentDirByDrive(WCHAR * DirName, UINT MaxLength);

/*****************************************************************************
 * <GROUP  FolderOperation>
 *
 * FUNCTION
 *  FS_SetCurrentDir
 * DESCRIPTION
 *  Change the current directory and drive.
 * PARAMETERS
 *  DirName   : [IN] <P>DirName must point to the name of the new current directory.
 *                      The new directory can have any legal file name syntax. If
 *                      no drive is given, the current drive is not changed. In
 *                      other cases, both current drive and current directory are
 *                      changed as DirName.
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	Please refer to fs_error_enum.
 * NOTE
 *  FS maintains a default directory for each drive, but only one drive and its
 *  current directory can be active at any one time.
 *****************************************************************************/
extern int FS_SetCurrentDir(const WCHAR * DirName);

/*****************************************************************************
 * <GROUP  FolderOperation>
 *
 * FUNCTION
 *  FS_CreateDir
 * DESCRIPTION
 *  Create a new directory(folder).
 * PARAMETERS
 *  DirName: [IN] <P>It must point to the name of the directory to create. The
 *                  directory can have any legal file name syntax.
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	Please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_CreateDir(const WCHAR * DirName);

/*****************************************************************************
 * <GROUP  FolderOperation>
 *
 * FUNCTION
 *  FS_RemoveDir
 * DESCRIPTION
 *  Removes a directory.
 * PARAMETERS
 *  DirName: [IN] <P>It must point to the name of the directory to be removed.
 *                  The directory can have any legal file name syntax.
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	Please refer to fs_error_enum.
 * NOTE
 *  This function fails on an attempt to remove a current directory, a non-empty
 *  directory, or a root directory.
 *****************************************************************************/
extern int FS_RemoveDir(const WCHAR * DirName);

/*****************************************************************************
 * <GROUP  RecursiveOperation>
 *
 * FUNCTION
 *  FS_GetFolderSize
 * DESCRIPTION
 *  This function provides a facility to get folder size
 * PARAMETERS
 *  DirName        : [IN]<P>Full source path to be counted
 *  Flag           : [IN]<P>FS_COUNT_IN_BYTE, FS_COUNT_IN_CLUSTER
 *  RecursiveStack : [IN]<P>A memory pointer to store deep folder hierarchy recrusive data
 *  StackSize      : [IN]<P>The size of RecursiveStack
 * RETURNS
 *  >0       : Size in byte or cluster
 *  Error    : RTF_PATH_NOT_FOUND, RTF_PARAM_ERROR
 * NOTE
 *     1. The size here counts for FAT allocation, not only data setctor allocation
 *     2. This API leverage the Recursive Class
 *****************************************************************************/
extern int FS_GetFolderSize(const WCHAR *DirName, UINT Flag, BYTE *RecursiveStack, const UINT StackSize);

/*****************************************************************************
 * <GROUP  RecursiveOperation>
 *
 * FUNCTION
 *  FS_GetFolderSizeEx
 * DESCRIPTION
 *  This function provides a facility to get folder size with progress callback support
 * PARAMETERS
 *  DirName        : [IN]<P>Full source path to be counted
 *  Flag           : [IN]<P>FS_COUNT_IN_BYTE, FS_COUNT_IN_CLUSTER
 *  RecursiveStack : [IN]<P>A memory pointer to store deep folder hierarchy recrusive data
 *  StackSize      : [IN]<P>The size of RecursiveStack
 *  Progress       : [IN]<P>User callback. User can get progress of this API or abort this operation by returning a negative integer.
 * RETURNS
 *  >0       : Size in byte or cluster
 *  Error    : RTF_PATH_NOT_FOUND, RTF_PARAM_ERROR
 * NOTE
 *     1. The size here counts for FAT allocation, not only data setctor allocation
 *     2. This API leverage the Recursive Class
 *****************************************************************************/
extern int FS_GetFolderSizeEx(const WCHAR *DirName, UINT Flag, BYTE *RecursiveStack, const UINT StackSize, FS_ProgressCallback Progress);

/*****************************************************************************
 * <GROUP  FileContent>
 *
 * FUNCTION
 *  FS_Extend
 * DESCRIPTION
 *  To extend the allocated file size, but not the current file size of a file.
 * PARAMETERS
 *  FileHandle : [IN] <P>References the open file to be extended.
 *  Length     : [IN] <P>Specifies by how many bytes the file is to be extended relative to the current file pointer.
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	Please refer to fs_error_enum.
 * RETURN VALUES
 *  FS_DISK_FULL (-22): FS cannot find a continuous chain of free clusters
 *                      long enough to satisfy the request. Because disk really
 *                      full and no any available free cluster.
 *  FS_DISK_FRAGMENT (-53): FS cannot find a continuous chain of free clusters
 *                          long enough to satisfy the request. But some fragment
 *                          free clusters found.
 * EXAMPLE
 * <code>
 *      #include "kal_general_types.h"
 *      #include "fs_gprot.h"
 *
 *      #define CHUNK_SIZE (5 * 1024)
 *      kal_uint8 sample_extend_buff[6 * 1024];
 *
 *      static kal_int32 sample_extend_body(kal_uint8 *dirty_buffer_ptr, kal_uint32 dirty_buffer_size)
 *      {
 *          FS_HANDLE fp = FS_Open(L"e:\\temp.txt", FS_READ_WRITE);
 *
 *          if (fp > FS_NO_ERROR)
 *          {
 *              kal_int32 ret = FS_NO_ERROR;
 *
 *              while (dirty_buffer_size > CHUNK_SIZE)
 *              {
 *                  ret = FS_Extend(fp, CHUNK_SIZE);
 *                  if (ret < FS_NO_ERROR)
 *                      break;
 *
 *                  ret = FS_Write(fp, dirty_buffer_ptr, CHUNK_SIZE, &written);
 *                  if (ret < FS_NO_ERROR)
 *                      break;
 *
 *                  dirty_buffer_size -= CHUNK_SIZE;
 *              }
 *              FS_Close(fp);
 *          }
 *      }
 *
 *      void sample_extend_main(void)
 *      {
 *          kal_int32 result = FS_NO_ERROR;
 *
 *          kal_mem_set(sample_extend_buff, 0xFF, sizeof(sample_extend_buff));
 *          result = sample_extend_body(sample_extend_buff, sizeof(sample_extend_buff));
 *          if (result == FS_NO_ERROR)
 *          {
 *              USER_PROMPT("FS_Extend success!");
 *          }
 *          else
 *          {
 *              USER_PROMPT("FS_Extend faile! error code = %d", result);
 *          }
 *      }
 * </code>
 *****************************************************************************/
extern int FS_Extend(FS_HANDLE FileHandle, UINT Length);

/*****************************************************************************
 * <GROUP  FileContent>
 *
 * FUNCTION
 *  FS_Truncate
 * DESCRIPTION
 *  To set the current file size to the current file pointer position.
 * PARAMETERS
 *  FileHandle : [IN] <P>References the open file to be truncated.
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	Please refer to fs_error_enum.
 * NOTE
 *  Users must seek to the "point to trunck" first.
 *****************************************************************************/
extern int FS_Truncate(FS_HANDLE FileHandle);

/*****************************************************************************
 * <GROUP  DirectoryEntry>
 *
 * FUNCTION
 *  FS_MakeFileName
 * DESCRIPTION
 *  This function will provide a facility for user to get a short file name (SFN)
 *  or long file name (LFN) via specified file handle. However, if the length of
 *  file name buffer is not big enough to store the requested LFN, SFN will be
 *  returned.
 * PARAMETERS
 *  FileHandle : [IN]  <P>The file handle from successful FS_Open
 *  Flag       : [IN]  <P>FS_LONGNAME_ATTR: Get LFN from disk to FileName buffer
 *                     <P>0: Get SFN from disk to FileName buffer (default choice)
 *  FileName   : [OUT] <P>User provides wide character buffer for file system to store SFN or LFN
 *  MaxLength  : [IN]  <P>The length of the FileName buffer in ¡§byte¡¨
 * RETURNS
 *  If the function succeeds, the return value is FS_NO_ERROR. If the function fails
 *  (EX: file handle is invalid or input buffer is too small that cannot keep a SFN),
 *  the return value is a negative error code.
 *****************************************************************************/
extern int FS_MakeFileName(FS_HANDLE FileHandle, UINT Flag, WCHAR * FileName, UINT MaxLength);

/*****************************************************************************
 * <GROUP  DirectoryEntry>
 *
 * FUNCTION
 *  FS_Rename
 * DESCRIPTION
 *  Rename a file.
 * PARAMETERS
 *  FileName   : [IN]  <P>Must point to the name of the file to be renamed.
 *  NewName    : [OUT] <P>It points to the new name of the file. Both file names
 *                      must not contain wildcards and must reference the same
 *                      logical drive. However, they may reference different
 *                      directories. Data files and directory files (except
 *                      root directories) may be renamed or moved with this
 *                      call.
 * RETURNS
 *  If the function succeeds, the return value is FS_NO_ERROR. If the function
 *  fails, the return value is a negative error code. This function fails if a
 *  file with the name specified by NewName already exists, on an attempt to
 *  rename the current directory or a parent of the current directory, or on
 *  an attempt to rename a volume label.
 *****************************************************************************/
extern int FS_Rename(const WCHAR * FileName, const WCHAR * NewName);

/*****************************************************************************
 * <GROUP  RecursiveOperation>
 *
 * FUNCTION
 *  FS_Move
 * DESCRIPTION
 *  This function provides a facility to move/copy a file or folder
 * PARAMETERS
 *  SrcFullPath    : [IN] <P>Source path to be moved/copied
 *  DstFullPath    : [IN] <P>Destination path
 *  Flag           : [IN]
 *      FS_MOVE_OVERWRITE(4) - Overwrite the destination if it has already existed. This option should combine with FS_MOVE_COPY or FS_MOVE_KILL via ¡¥|¡¦.
 *      FS_MOVE_COPY (2) - Copy from source to destination and keep the source file/folder. This option cannot combine with FS_MOVE_KILL.
 *      FS_MOVE_KILL (1) - Move from source to destination and do not keep the source file/folder. This option cannot combine with FS_MOVE_COPY.
 *  RecursiveStack : [IN] <P>A memory pointer to store deep folder hierarchy recrusive data
 *                        Before W08.40: If NULL, only 39 levels supported. It¡¦s recommend
 *                        that foreground application should provide 6.6K bytes to support up
 *                        to maximum 128 levels in FAT specification.
 *                        After 08A W08.40 (Included): If NULL, only 39 levels supported.
 *                        To support deeper folders, user should assign the RecursiveStack
 *                        of proper size. The minimum space required for 128 levels is about
 *                        11K bytes. Here is a helper macro to calculate the required buffer
 *                        for different levels. -FS_MOVE_BUFFER_SIZE_FOR_FOLDER_LEVEL(x).
 *  StackSize      : [IN] <P>The size of RecursiveStack
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	As below
 * RETURN VALUES
 *  FS_PARAM_ERROR (-2): Neither FS_MOVE_COPY nor FS_MOVE_KILL is specified in parameter, Flag.
 *  FS_INVALID_FILENAME (-3): Either SrcFullPath or DstFullPath is wrong
 *  FS_PATH_NOT_FOUND (-19): Cannot find SrcFullPath specified in the first parameter.
 *  FS_FILE_EXISTS (-36): DstFullPath exists while FS_MOVE_OVERWRITE is not specified in the third parameter.
 *  FS_FAIL_GET_MEM (-44): Cannot get memory to do the operation
 *  FS_READ_ONLY_ERROR (-45): The SrcFullPath contain READ_ONLY file attribute that cannot be move across drive/partition.
 *  FS_ABORTED_ERROR (-47): This action has been aborted in the user¡¦s callback function.
  * NOTE
 *     1. Original RTFRename does not allow move to different drive
 *     2. Only can file to file or dir to dir
 *     3. This API leverage the Recursive Class
 * EXAMPLE
 * <code>
 *      (1)FS_Move(L"E:\\AUDIO", L"D:\\AUDIO", FS_MOVE_OVERWRITE | FS_MOVE_COPY, YourCallBack, NULL, 0);
 *      (2)FS_Move(L"E:\\AUDIO\test.txt", L"D:\\AUDIO\test.txt", FS_MOVE_COPY, YourCallBack, NULL, 0);
 *      (3)FS_Move(L"E:\\AUDIO\test.txt", L"D:\\AUDIO\test.txt", FS_MOVE_KILL, YourCallBack, NULL, 0);
 *      (4)FS_Move(L"E:\\AUDIO", L"D:\\AUDIO", FS_MOVE_OVERWRITE | FS_MOVE_KILL, YourCallBack, NULL, 0);
 *
 *
 *      int YourCallBack(int Action, UINT Total, UINT Completed, UINT MyHandle)
 *      {
 *          if (Action == FS_MOVE_PGS_PREPARE)
 *          //show preparing image
 *          else if (Action == FS_MOVE_PGS_START)
 *          //show empty progressing bar
 *          else if (Action == FS_MOVE_PGS_FAIL)
 *          //show error message
 *          else if (Action == FS_MOVE_PGS_DONE)
 *          //show full progressing bar and then show ¡§Done¡¨ image
 *          else if (Action == FS_MOVE_PGS_ING)
 *          {
 *              if (WantStop && (MyHandle > 0))
 *              {
 *                  FS_Abort(MyHandle);
 *              }
 *              else
 *              {
 *                  //show progressing percentage: (Completed/Total) *100%
 *                  //Be careful of the DIV BY ZERO problem here
 *              }
 *          }
 *      }
 * </code>
  *****************************************************************************/
extern int FS_Move(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, UINT Flag, FS_ProgressCallback Progress, BYTE *RecursiveStack, const UINT StackSize);

/*****************************************************************************
 * <GROUP  RecursiveOperation>
 *
 * FUNCTION
 *  FS_Move
 * DESCRIPTION
 *  This function provides a facility to count the number of files
 *  or folders recursively
 * PARAMETERS
 *  FullPath:      : [IN] <P>Source path to be counted
 *  Flag:          : [IN] <P>All the types as following can combine together
 *      FS_FILE_TYPE - Count files
 *      FS_DIR_TYPE - Count folders
 *      FS_RECURSIVE_TYPE - Count recursively including the sub-folder inside
 *                          the source folder. This option works only when
 *                          FS_DIR_TYPE is chosen.
 *      FS_FILTER_SYSTEM_ATTR - Count file/folder without ¡§SYSTEM¡¨ attribute.
 *      FS_FILTER_HIDDEN_ATTR - Count file/folder without ¡§HIDDEN¡¨ attribute.
 *  RecursiveStack:: [IN] <P>A memory pointer to store deep folder hierarchy recrusive data
 *  StackSize:     : [IN] <P>The size of RecursiveStack
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	As below
 * RETURN VALUES
 *  FS_PARAM_ERROR(-2): Neither FS_FILE_TYPE nor FS_DIR_TYPE nor FS_RECURSIVE_TYPE
 *                      is specified in parameter, Flag.
 *  FS_INVALID_FILENAME(-3): FullPath is wrong
 *  FS_PATH_NOT_FOUND(-19): Cannot find FullPath specified in the first parameter.
 *  FS_FAIL_GET_MEM(-44): Cannot get memory to do the operation
 * NOTE
 *  This API needs to get control buffer for operation.
 *  If it cannot get memory at that time, error code (-44) will be returned..
 * EXAMPLE
 * <code>
 *      (1) FS_Count(L"D:\\AUDIO", FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
 *      (2) FS_Count(L"D:\\AUDIO", FS_ DIR _TYPE | FS_RECURSIVE_TYPE, NULL, 0);
 *      (3) FS_Count(L"D:\\AUDIO", FS_FILE_TYPE, NULL, 0);
 *      (4) FS_Count(L"D:\\AUDIO", FS_FILE_TYPE | FS_DIR_TYPE, NULL, 0);
 * </code>
 *****************************************************************************/
extern int FS_Count(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize);


/*****************************************************************************
 * <GROUP  RecursiveOperation>
 *
 * FUNCTION
 *  FS_XDeleteEx
 * DESCRIPTION
 *  This function provides a facility to delete a file or folder recursively
 * PARAMETERS
 *  FullPath:      : [IN] <P>Source path to be counted
 *  Flag:          : [IN] <P>All the three types as following can combine together
 *          FS_FILE_TYPE(2) - Delete files
 *          FS_DIR_TYPE(4) - Delete folders
 *          FS_RECURSIVE_TYPE(8) -  Delete recursively including the sub-folder
 *                                  inside the source folder. This option works
 *                                  only when FS_DIR_TYPE is chosen.
 *  RecursiveStack:: [IN] <P>An external buffer for deep directory hierarchy processing.
 *                           Before W08.40, if NULL, only 39 levels supported. It's
 *                           recommend that foreground application should provide 6.6K
 *                           bytes to support up to maximum 128 levels in FAT specification.
 *                           After 08A W08.40 (Included), if NULL, only 39 levels supported.
 *                           To support deeper folders, user should assign the RecursiveStack
 *                           of proper size. The minimum space required for 128 levels is about
 *                           8.5K bytes. Here is a helper macro to calculate the required buffer
 *                           for different levels. - FS_XDELETE_BUFFER_SIZE_FOR_FOLDER_LEVEL (x).
 *  StackSize:     : [IN] <P>The size of RecursiveStack
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	As below
 * RETURN VALUES
 *  FS_PARAM_ERROR(-2): Neither FS_FILE_TYPE nor FS_DIR_TYPE nor FS_RECURSIVE_TYPE
 *                      is specified in parameter, Flag.
 *  FS_INVALID_FILENAME(-3): FullPath is wrong
 *  FS_PATH_NOT_FOUND(-19): Cannot find FullPath specified in the first parameter.
 *  FS_FAIL_GET_MEM(-44): Cannot get memory to do the operation
 * NOTE
 *  (1) This API needs to get control buffer for operation. If it cannot get memory
 *      at that time, error code (-44) will be returned..
 *  (2) if the target folder is an empty folder, an error string like ¡§[FS ERR]-10#4234@fs> Task(TASK) 65531th FH¡¨
 *      will show up in FS Trace. This is normal. It does NOT mean that FS_XDelete is failed.
 *****************************************************************************/
extern int FS_XDelete(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize);

/*****************************************************************************
 * <GROUP  RecursiveOperation>
 *
 * FUNCTION
 *  FS_XDeleteEx
 * DESCRIPTION
 *  This function provides a facility to delete a file or folder recursively
 * PARAMETERS
 *  FullPath      : [IN]<P>Source path to be counted
 *  Flag          : [IN]<P>All the three types as following can combine together
 *          FS_FILE_TYPE(2) - Delete files
 *          FS_DIR_TYPE(4) - Delete folders
 *          FS_RECURSIVE_TYPE(8) -  Delete recursively including the sub-folder
 *                                  inside the source folder. This option works
 *                                  only when FS_DIR_TYPE is chosen.
 *  Progress        : [IN] <P>User callback
 *  RecursiveStack  : [IN] <P>An external buffer for deep directory hierarchy processing.
 *                         Before W08.40, if NULL, only 39 levels supported. It's
 *                         recommend that foreground application should provide 6.6K
 *                         bytes to support up to maximum 128 levels in FAT specification.
 *                         After 08A W08.40 (Included), if NULL, only 39 levels supported.
 *                         To support deeper folders, user should assign the RecursiveStack
 *                         of proper size. The minimum space required for 128 levels is about
 *                         8.5K bytes. Here is a helper macro to calculate the required buffer
 *                         for different levels. - FS_XDELETE_BUFFER_SIZE_FOR_FOLDER_LEVEL (x).
 *  StackSize       : [IN] <P>The size of RecursiveStack
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	As below
 * RETURN VALUES
 *  FS_PARAM_ERROR(-2): Neither FS_FILE_TYPE nor FS_DIR_TYPE nor FS_RECURSIVE_TYPE
 *                      is specified in parameter, Flag.
 *  FS_INVALID_FILENAME(-3): FullPath is wrong
 *  FS_PATH_NOT_FOUND(-19): Cannot find FullPath specified in the first parameter.
 *  FS_FAIL_GET_MEM(-44): Cannot get memory to do the operation
 * NOTE
 *  (1) This API needs to get control buffer for operation. If it cannot get memory
 *      at that time, error code (-44) will be returned..
 *  (2) if the target folder is an empty folder, an error string like ¡§[FS ERR]-10#4234@fs> Task(TASK) 65531th FH¡¨
 *      will show up in FS Trace. This is normal. It does NOT mean that FS_XDelete is failed.
 *****************************************************************************/
extern int FS_XDeleteEx(const WCHAR * FullPath, UINT Flag, FS_ProgressCallback Progress, BYTE *RecursiveStack, const UINT StackSize);

/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  FS_CompactDir
 * DESCRIPTION
 *  This function provides a facility to release space of a folder which contains "deleted" files/folders.
 * PARAMETERS
 *  DirName : [IN] <P>the folder to compact.
 *  Flags   : [IN] <P> FS_CMPCT_RECURSIVE only
 * RETURNS
 *  Please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_CompactDir(const WCHAR* DirName, UINT Flags);

/*****************************************************************************
 * <GROUP  DirectoryEntry>
 *
 * FUNCTION
 *  FS_CheckVolumeLabel
 * DESCRIPTION
 *  This function provides a facility to check if the volume label is valid.
 * PARAMETERS
 *  Path : [IN] <P>The volume label.
 * RETURNS
 *  If volume label is valid, FS_NO_ERROR is returned.
 *  For error case, please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_CheckVolumeLabel(WCHAR *Label);

/*****************************************************************************
 * <GROUP  DirectoryEntry>
 *
 * FUNCTION
 *  FS_CheckFileName
 * DESCRIPTION
 *  This function provides a facility to check if the specified file name is valid.
 * PARAMETERS
 *  Path : [IN] <P>The file path. Both full path or file name only are acceptible.
 *                 If it is full path, FS will only check the file name, i.e., the last part after '\\'.
 * RETURNS
 *  If file name is valid, FS_NO_ERROR is returned.
 *  For error case, please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_CheckFileName(WCHAR *Path);

/*****************************************************************************
 * <GROUP  Enumerate>
 *
 * FUNCTION
 *  FS_FindFirst
 *
 * DESCRIPTION
 *  Search a directory for a file satisfying certain criteria.
 *
 * PARAMETERS
 *  NamePattern    : [IN]    <P>Pointer to a file name which may contain wildcard characters '*'
 *                              (match zero or more characters) and/or '?' (match exactly one
 *                              character), and can optionally be preceded by a path. If a path
 *                              is present, it must not contain any wildcard characters.
 *                              For compatibility with MS-DOS, Pattern "*.*" is silently converted
 *                              to "*". To search for file names containing one or more periods,
 *                              use "?*.*" or "*.?*".
 *  Attr           : [IN]    <P>Specifies a set of all file attributes a file must have to match
 *                              the request.
 *  AttrMask       : [IN]    <P>Specified the set of attributes, which are matched against Attr.
 *                              Attributes set in Attr are automatically added to AttrMask. Any
 *                              combination of the following flags can be specified for Attr and
 *                              AttrMask:
 *                                  FS_ATTR_READ_ONLY
 *                                  FS_ATTR_HIDDEN
 *                                  FS_ATTR_SYSTEM
 *                                  FS_ATTR_VOLUME
 *                                  FS_ATTR_DIR
 *                                  FS_ATTR_ARCHIVE
 *  FileInfo       : [IN/OUT] <P>It¡¦s a pointer to FS_DOSDirEntry structure. If the function succeeds,
 *                               this structure will be filled with the directory entry of the file
 *                               found. This parameter may be NULL. Refer to FS_FIND_ENUM.
 *  FileName       : [IN]    <P>Pointer to a string buffer to receive the file name without path if
 *                              a file is found.
 *  MaxLength      : [IN]    <P>Size in bytes of the buffer pointed to by FileName. Files with a file
 *                              name length larger than MaxLength-1 will not be found. Be careful that
 *                              it should be the length of wide-characters.
 * RETURNS
 *  If the function succeeds, at least one file satisfies the search criteria. *FileInfo contains the
 *  directory entry of the first file and the function return value is greater than or equal to 0. The
 *  return value is a file handle, which may be passed to subsequent calls to FS_FindNext. If the function
 *  fails, the return value is a negative error code. In this case, no handle is allocated and FS_FindClose
 *  need not be called.
 *  It is important to close the handle using FS_FindClose when no longer needed. Failing to do so will
 *  quickly exhaust the available file handles.
 *****************************************************************************/
extern int FS_FindFirst(const WCHAR * NamePattern, BYTE Attr, BYTE AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength);

/*****************************************************************************
 * <GROUP  Enumerate>
 *
 * FUNCTION
 *  FS_FindNext
 *
 * DESCRIPTION
 *  Find more files with the same search criteria as a preceding call to FS_FindFirst.
 *
 * PARAMETERS
 *  FileHandle     : [IN]    <P>Handle returned by a previous successful call to FS_FindFirst.
 *  FileInfo       : [IN/OUT]<P>It¡¦s a pointer to FS_DOSDirEntry structure (may be NULL).
 *  FileName       : [IN]    <P>It¡¦s a pointer to a string buffer to receive a file name without path.
 *  MaxLength      : [IN]    <P>Size in bytes of the buffer pointed to by FileName. Files with a file
 *                              name length larger than MaxLength-1 will not be found. Be careful that
 *                              it should be the length of wide-characters
 * RETURNS
 *  If the function succeeds, the return value is FS_NO_ERROR. If the function fails or no more files
 *  are found, the return value is a negative error code.If the function succeeds, *FileInfo and
 *  *FileName will be filled with the directory entry and name of the file found.
 *****************************************************************************/
extern int FS_FindNext(FS_HANDLE FileHandle, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength);

/*****************************************************************************
 * <GROUP  Enumerate>
 *
 * FUNCTION
 *  FS_FindFirstN
 *
 * DESCRIPTION
 *  This function provides a facility to find Nth matching file
 *  and multi-patterns are supported
 *
 * PARAMETERS
 *  NamePattern    : [IN]    <P>Find Pattern (Must have drive name)
 *  PatternArray   : [IN]    <P>Multi-patterns array (should not have drive name)
 *  PatternNum     : [IN]    <P>Indicate how many pattern in PatternArray
 *  ArrayMask      : [IN]    <P>The attributes that match default NamePattern only
 *  Attr           : [IN]    <P>The attributes must have
 *  AttrMask       : [IN]    <P>The attributes must not have
 *  FileInfo       : [IN/OUT]<P>File information
 *  FileName       : [IN]    <P>the long file name
 *  MaxLength      : [IN]    <P>The length of FileName
 *  EntryIndex     : [IN]    <P>Find Nth index
 *
 * RETURNS
 *  Success:       FS_NO_ERROR
 *  Error:         Please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_FindFirstN(const WCHAR * NamePattern, FS_Pattern_Struct * PatternArray, UINT PatternNum, BYTE ArrayMask, BYTE Attr, BYTE AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength, UINT EntryIndex, UINT Flag);

/*****************************************************************************
 * <GROUP  Enumerate>
 *
 * FUNCTION
 *  FS_FindNextN
 * DESCRIPTION
 *  This function provides a facility to find next matching file
 *  and multi-patterns are supported
 * PARAMETERS
 *  Handle         : [IN]    <P>The file handle record the find position
 *  PatternArray   : [IN]    <P>Multi-patterns array (should not have drive name)
 *  PatternNum     : [IN]    <P>Indicate how many pattern in PatternArray
 *  ArrayMask      : [IN]    <P>The attributes that match default NamePattern only
 *  FileInfo       : [IN/OUT]<P>File information
 *  FileName       : [IN]    <P>File name
 *  MaxLength      : [IN]    <P>The length of the file name buffer
 * RETURNS
 *  Success:       FS_NO_ERROR
 *  Error:         Please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_FindNextN(FS_HANDLE Handle, FS_Pattern_Struct * PatternArray, UINT PatternNum, BYTE ArrayMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength, UINT Flag);

/*****************************************************************************
 * <GROUP  Enumerate>
 *
 * FUNCTION
 *  FS_FindClose
 * DESCRIPTION
 *  To close the handle of FS_FindFirst or FS_FindFirstN
 * PARAMETERS
 *  handle  : [IN] <P>the handle of FS_FindFirst or FS_FindFirstN
 * RETURNS
 *  Successful: A non-negative value.
 *  Failed: 	Please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_FindClose(FS_HANDLE FileHandle);

/*****************************************************************************
 * <GROUP  Enumerate>
 *
 * FUNCTION
 *  FS_ListOpen
 * DESCRIPTION
 *  1. To open specific folder and loading file elements with given parameters
 *     into a backgroud list.
 *  2. Similar to opendir of Posix.
 * PARAMETERS
 *  param   : [IN]  <P>parameter set and list buffer; refer to fs_list_param_struct.
 *  handle  : [OUT] <P>special handle of List serial APIs.
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	Please refer to fs_error_enum.
 * NOTE
 *  only one of name_pattern and attr_pattern can be used at the same time
 * EXAMPLE
 * <code>
 *      //Intention:  to list the first 20 file names under e:\\Photos\\
 *      FS_HANDLE list;
 *      kal_int32 result, i = 0;
 *      kal_wchar wfn[10] = {0};
 *      kal_char  fn[10] = {0};
 *      fs_list_param_struct param = {0};
 *
 *      param.path = (kal_wchar *)get_ctrl_buffer(FS_MAX_PATH);
 *      kal_wsprintf(param.path, "E:\\Photos\\*.*");
 *
 *      param.index = 0;
 *      param.buff_size = FS_LIST_SIZE(20);
 *      param.buff = (fs_list_param_struct *)get_ctrl_buffer(param.buff_size);
 *
 *      result = FS_ListOpen(&param, &list);
 *
 *      while (result >= FS_NO_ERROR)
 *      {
 *          result = FS_ListNext(list, NULL, param.path, wfn, 10, i);
 *          if (result <FS_NO_ERROR)
 *              break;
 *
 *          kal_dchar2char(wfn, fn);
 *          kal_prompt_trace(MOD_USER, "%s", fn);
 *      }
 *      FS_ListClose(list);
 *
 *      free_ctrl_buffer(param.buff);
 *      free_ctrl_buffer(param.path);
 * </code>
  *****************************************************************************/
extern kal_int32 FS_ListOpen(fs_list_param_struct *param, FS_HANDLE *handle);

/*****************************************************************************
 * <GROUP  Enumerate>
 *
 * FUNCTION
 *  FS_ListReload
 * DESCRIPTION
 *  Continue to batch enumerate next N files after FS_ListOpen().
 * PARAMETERS
 *  param   : [IN]  <P>parameter set and list buffer; refer to fs_list_param_struct.
 *  handle  : [OUT] <P>special handle of List serial APIs.
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	Please refer to fs_error_enum.
 * NOTE
 *  The param and handle must be identical to those were passed to FS_ListOpen().
 * EXAMPLE
 * <code>
 * </code>
  *****************************************************************************/
extern kal_int32 FS_ListReload(fs_list_param_struct *param, FS_HANDLE *handle);

/*****************************************************************************
 * <GROUP  Enumerate>
 *
 * FUNCTION
 *  FS_ListNext
 * DESCRIPTION
 *  1. To retrive the Nth element of the background list.
 *  2. Similar to readdir of Posix
 *  3. optional parameters could be NULL or 0
 * PARAMETERS
 *  handle        : [IN]      <P>special handle of List serial APIs.
 *  info          : [IN/OUT]  <P>(optional)the DOS style information of an element if found. Such as short file name.
 *  path          : [IN]      <P>working diretory which will be filled into internal hint
 *  lfilename     : [IN/OUT]  <P>the buffer to carry long file name if found.
 *  lfilename_size: [IN]      <P>the buffer size of lfilename with includes null terminator
 *  index         : [IN]      <P>specific zero-based index in the list
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	Please refer to fs_error_enum.
 *****************************************************************************/
extern kal_int32 FS_ListNext(FS_HANDLE handle,
                             FS_DOSDirEntry *info, kal_wchar *path, kal_wchar *lfilename, kal_uint32 lfilename_size,
                             kal_int32 index);

/*****************************************************************************
 * <GROUP  Enumerate>
 *
 * FUNCTION
 *  FS_ListClose
 * DESCRIPTION
 *  1. To close the list.
 *  2. Similar to closedir of Posix.
 * PARAMETERS
 *  handle    : [IN] <P>special handle of List serial APIs.
 * RETURNS
 *  Successful: FS_NO_ERROR
 *  Failed: 	Please refer to fs_error_enum.
 *****************************************************************************/
extern kal_int32 FS_ListClose(FS_HANDLE handle);

extern void FS_Config(fs_config_enum type, void * data);

#ifdef __FS_SORT_SUPPORT__
/*****************************************************************************
 * <GROUP  Sort>
 *
 * FUNCTION
 *  FS_SortCompareFileName
 * DESCRIPTION
 *  The build-in compare function. Compare by name
 * PARAMETERS
 *  FileName1    : [IN] <P>source of the comparison.
 *  FileName2    : [IN] <P>target of the comparison.
 * RETURN VALUES
 *  -1  : char in FileName1 is less than that in FileName2
 *   1  : char in FileName1 is greater than that in FileName2
 *   0  : equal or no difference is found till all char in FileName1 is traversed.
 *****************************************************************************/
extern int FS_SortCompareFileName(WCHAR *FileName1, WCHAR *FileName2);

/*****************************************************************************
 * <GROUP  Sort>
 *
 * FUNCTION
 *  FS_SortCompareFileType
 * DESCRIPTION
 *  The build-in compare function. Compare by type
 * PARAMETERS
 *  FileName1    : [IN] <P>source of the comparison.
 *  FileName2    : [IN] <P>target of the comparison.
 * RETURN VALUES
 *  -1  : char in FileName1 is less than that in FileName2
 *   1  : char in FileName1 is greater than that in FileName2
 *   0  : equal or no difference is found till all char in FileName1 is traversed.
 *****************************************************************************/
extern int FS_SortCompareFileType(WCHAR *FileName1, WCHAR *FileName2);

/*****************************************************************************
 * <GROUP  Sort>
 *
 * FUNCTION
 *  FS_XFindReset
 * DESCRIPTION
 *  This function provides a facility to reset a sort list recursively
 * PARAMETERS
 *  Param   : [IN] <P>Please refer to FS_SortingParam.
 * RETURN VALUES
 *  >= 0: The number of folders/files that had been sorted.
 *  FS_PARAM_ERROR (-2): Some of the parameters are invalid.
 *  FS_NO_MORE_FILES (-6): Cannot find any file that matches the pattern anymore
 *  FS_ACCESS_DENIED (-16):  You didn't get the lock from FS_XFindReset. The passed buffer or data does not belong to this function.
 *  FS_FAIL_GET_MEM: Invalid buffer space or size.
 *  FS_ABORTED_ERROR: The sorting is aborted.
 *  FS_NO_MORE_FILES: No more files to be retrieved.
 *  FS_TOO_MANY_FILES: The sorting buffer or working buffer is too small.
 * NOTE
 *  (1) Please be care of the <b>MaxLength</b> input. If it¡¦s too small that FS cannot make short name for you, the sorting sequence will be corrupted, i.e. make sure your length must be greater than 22 characters (11 wide characters).
 *  (2) If you want to get specific sorting result, just put (index -1) into the input parameter.
 *  (3) If you get the sorted filename by this function with index from 0 to (the sorted file number -1), the result will be in ASC order. If you want to get the filename in DESC order, you can get the sorted filename with index from (the sorted file number -1) to 0.
 *****************************************************************************/
extern int FS_XFindReset(FS_SortingParam *Param);

/*****************************************************************************
 * <GROUP  Sort>
 *
 * FUNCTION
 *  FS_XFindStart
 * DESCRIPTION
 *  This function retrieves entry from the sorting list  got from FS_XFindReset one by one.
 * PARAMETERS
 *  Pattern     : [IN]  <P>Find Pattern
 *  FileInfo    : [OUT] <P>File information
 *  FileName    : [OUT] <P>File name
 *  MaxLength   : [IN]  <P>The length of FileName buffer
 *  Index       : [IN]  <P>Find index
 *  Position    : [IN]  <P>The sorted list
 * RETURN VALUES
 *  Value >= 0: The number of folders/files that had been sorted.
 *  FS_PARAM_ERROR (-2): Given an negative index number
 *  FS_NO_MORE_FILES (-6): Cannot find any file that matches the pattern anymore
 *  FS_ACCESS_DENIED (-16): You didn¡¦t get the lock from FS_XFindReset.
 *****************************************************************************/
extern int FS_XFindStart(const WCHAR * Pattern, FS_DOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength, UINT Index, UINT * Position, UINT Flag);

/*****************************************************************************
 * <GROUP  Sort>
 *
 * FUNCTION
 *  FS_XFindClose
 * DESCRIPTION
 *  This function closes the sorting list got from FS_XFindReset.
 * PARAMETERS
 *  Position    : [IN]  <P>The sorted list
 * RETURN VALUES
 *  FS_NO_ERROR: Successful
 *  FS_PARAM_ERROR (-2): Given an negative index number
 *  FS_ACCESS_DENIED (-16): You didn't get the lock from FS_XFindReset.
 *****************************************************************************/
extern int FS_XFindClose(UINT * Position);
#endif

/*****************************************************************************
 * <GROUP  VolumeManagement>
 *
 * FUNCTION
 *  FS_GetDrive
 * DESCRIPTION
 *  Our system support 1 NOR flash + 1 NAND flash + maximum 1 memory card concurrently (Maximum 5 drives). If it acts as a USB slave, we may have the ¡§partition¡¨ issue: Some private data, like NVRAM or files with digital right, should not be exposed to PC side.
 *  <img name="FlashConfig" />
 *  For the special need, we must create partition on our disk. And in order to reduce driver effort, we have to mark the first primary partition as visible and secondary primary partition as invisible. When system acts as USB slave, driver will fool PC side that the ¡¨whole disk¡¨ is just big as the visible partition size.
 *  PS. Memory card should not be partitioned.
 * <xtable>
 *  IDX     DRIVES  NOR     NAND    CARD    NORMAL 1    NORMAL 2    SYS 1   SYS 2   CARD
 *           Num
 * -----    ------  ---     ----    ----    --------    --------    -----   -----   ----
 *  1       5       2       2       1       C           D           E       F       G
 *  2       4       2       1       1       C           D           E               F
 *  3       4       2       2       0       C           D           E       F
 *  4       4       1       2       1       D                       C       E       F
 *  5       3       2       0       1       C                       D               E
 *  6       3       2       1       0       C           D           E
 *  7       3       1       1       1       D                       C               E
 *  8       3       1       2       0       D                       C       E
 *  9       3       0       2       1       C                       D               E
 *  10      2       2       0       0       C                       D
 *  11      2       1       0       1                               C               D
 *  12      2       1       1       0       D                       C
 *  13      2       0       1       1                               C               D
 *  14      2       0       2       0       C                       D
 *  15      1       1       0       0                               C
 *  16      1       0       1       0                               C
 * </xtable>
 *  SYS 1/2: Invisible drive when system acts as USB slave.
 *  Normal 1/2 and memory card: Visible drive when system acts as USB slave
 *
 *  In additional to those fixed and internal drives listed above, USB OTG Host support enable system to connect to external card reader with multiple card slots. File System reserved 1 drive to each slot and start from next drive letter of last internal drive index. The maximum number of external drives is customized configuration.
 * PARAMETERS
 *  Type   : [IN] <P>3 kinds of drive types
 *           <P>FS_DRIVE_I_SYSTEM     0x00000004
 *           <P>FS_DRIVE_V_NORMAL     0x00000008
 *           <P>FS_DRIVE_V_REMOVABLE  0x00000010
 *           <P>FS_DRIVE_V_EXTERNAL   0x00000020
 *  Serial : [IN] <P>drive number (SYSTEM: 1or 2, NORMAL: 1 or 2, REMOVABLE: 1, EXTERNAL: 1~N(customized) )
 *  AltMask: [IN] <P>3 ways to choose alternative drive
 *           <P>FS_NO_ALT_DRIVE       		0x00000001 (Can not combine other type)
 *           <P>FS_ONLY_ALT_SERIAL    		0x00000002 (Can not combine other type)
 *           <P>Combination of 3 types (FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL | FS_DRIVE_V_REMOVABLE)
 * RETURN VALUES
 *  Capital drive name:
 *      C=67, D=68, E=69, F=70
 *      G=72, H=73, I=74, J=75¡K
 *  FS_PARAM_ERROR (-2):
 *      Use special type not defined here
 *      Serial number over range
 *      AltMask use FS_NO_ALT_DRIVE | other type
 *      AltMask use FS_ONLY_ALT_SERIAL | other type
 *      AltMask contain FS_DRIVE_V_EXTERNAL
 *  FS_DRIVE_NOT_FOUND (-4):
 *      Cannot find user specified drive
 *      Serial out of pre-configured maximum number of external drives.
 *  Successful: FS_NO_ERROR
 *  Failed: 	Please refer to fs_error_enum.
 * NOTE
 *  (1) We always have a system drive. However, normal drive and removable device are not guaranteed in the customized combination. Task owner should be aware of each case and choose the best suit drive to use.
 *  (2) that FS_GetDrive() API always return consist drive index by given Serial parameter whether the external device present or not present.
 *  (3) the matching sequence of AltMask is:
 *      Normal 2 -> Normal 1 -> Card -> System 2 -> System 1
 *  (4) the external drive NOT included in matching sequence.
 * EXAMPLE
 * <code>
 *      Int         drvLetter;
 *      TCHAR       K_filename[50];
 *      FS_HANDLE   K_hFile;
 *      drvLetter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_REMOVABLE | FS_DRIVE_I_SYSTEM);
 *      if(drvLetter > 0)
 *      {
 *          kal_wsprintf(K_filename, "%c:\\ TestDir", drvLetter);
 *          K_hFile = FS_Open(K_filename, FS_READ_WRITE|FS_CREATE_ALWAYS|FS_OPEN_NO_DIR);
 *      }
 * </code>
 *****************************************************************************/
extern int FS_GetDrive(UINT Type, UINT Serial, UINT AltMask);

/*****************************************************************************
 * <GROUP  VolumeManagement>
 *
 * FUNCTION
 *  FS_GetDriveByHandle
 * DESCRIPTION
 *  Get capital drive letter by file handle.
 * RETURN VALUES
 *  Capital drive letter: Query is successful.
 *      C=67, D=68, E=69, F=70
 *      G=72, H=73, I=74, J=75¡K
 *  FS_INVALID_FILE_HANDLE (-10):
 *      User specify an invalid file handle.
 * NOTE
 * EXAMPLE
 * <code>
 *      int         drvLetter;
 *      TCHAR       K_filename[50];
 *      FS_HANDLE   K_hFile;
 *
 *      K_hFile = FS_Open(K_filename, FS_CREATE_ALWAYS);
 *
 *      drvLetter = FS_GetDriveByHandle(K_hFile);
 *
 *      if(drvLetter > 0)
 *      {
 *          // ......
 *      }
 * </code>
 *****************************************************************************/
extern int FS_GetDriveByHandle(FS_HANDLE handle);

/*****************************************************************************
 * <GROUP  VolumeManagement>
 *
 * FUNCTION
 *  FS_GeneralFormat
 * DESCRIPTION
 *  This function provides general format facility for File Manager.
 * PARAMETERS
 *  DriveName   : [IN]<P>   The drive that should be formatted (format: "\\\\.X:\\")
 *  Level       : [IN]<P>   FS_FORMAT_LOW (low-level format) or FS_FORMAT_HIGH (high-level format)
 *  Progress    : [IN]<P>   The callback function. Please refer to FS_FormatCallback.
 * RETURN VALUES
 *  12, 16 or 32: If format is successful, a positive integer will be returned. 12/16/32 means the target drive is formatted as FAT12/FAT16/FAT32.
 *  FS_PARAM_ERROR (-2): Use special format level not defined here
 *  FS_UNSUPPORTED_DRIVER_FUNCTION (-12): Call low-level format on removable device
 *  FS_MEDIA_CHANGED (-26): Try to format the removable device, which is not present
 *  FS_DEVICE_BUSY (-46): Only removable device, e.g., memory card, may return this error code. When file system is counting free space on devices in FS_LockFAT or FS_TestMSDC, this error code will be returned.
 *  FS_DEVICE_EXPORTED_ERROR (-52): Try to format an exporting drive. In this case, file handles will not be closed.
 * NOTE
 *  (1) High-level format will just clean up the FAT table of this drive while low-level format will scan the whole disk, re-partition the whole disk and re-build the driver structure. „» Even if you just low level format a drive, the whole disk will be low-level formatted.
 *  (2) Other restriction is that only NOR and NAND flash provide the low-level format function. In most cases, you should call high-level format for cleaning up drive purpose. But if you have ever received ¡§FS_SYSTEM_CRASH¡¨ error code when accessing that drive (NAND flash only), you should call low-level format to make NAND flash driver re-construct the whole system again.
 *  (3) Format may take a long time. Task should provide callback function for File System to report the format status.
 *  (4) Format function will close all the file handles on this disk automatically.
 *  (5) Low-level format may cost a lot of memory, please be careful of your task stack size.
 * EXAMPLE
 * <code>
 *      int 	drvLetter, reval=0;
 *      TCHAR	K_filename[50];
 *      drvLetter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_NO_ALT_DRIVE);
 *
 *      if(drvLetter > 0)
 *      {
 *          kal_wsprintf(K_filename, "\\\\.\\%c:", drvLetter); //please be careful of the format here
 *          reval = FS_GeneralFormat (K_filename, FS_FORMAT_HIGH, YourCallBack);
 *      }
 *      else
 *      {
 *           //check your code
 *      }
 *
 *      void YourCallBack(const char * DriveName, int Action, UINT Total, UINT Completed)
 *      {
 *          if (Action == FS_FMT_PGS_DONE)
 *              //show format done
 *          else if (Action == FS_FMT_PGS_FAIL)
 *              //check your error code return from FS_GeneralFormat
 *          else
 *              //show processing percentage: (Completed/Total) *100% //Be careful of the DIV BY ZERO problem here
 *      }
  * </code>
 *****************************************************************************/
extern int FS_GeneralFormat(const WCHAR * DriveName, UINT Level, FS_FormatCallback Progress);

/*****************************************************************************
 * <GROUP  VolumeManagement>
 *
 * FUNCTION
 *  FS_GetClusterSize
 * DESCRIPTION
 *  This function returns the cluster size of the specified drive.
 * PARAMETERS
 *  DriveIdx   : [IN] <P>The drive index ('Z' or 0x43, 0x44, ...etc.)
 * RETURN VALUES
 *  > 0: Cluster size in byte
 *  FS_DRIVE_NOT_FOUND (-4): Cannot get the specified drive
 *****************************************************************************/
extern int FS_GetClusterSize(UINT DriveIdx);

#ifdef __FS_QM_SUPPORT__
/*****************************************************************************
 * <GROUP  VolumeManagement>
 *
 * FUNCTION
 *  FS_QmGetFree
 * DESCRIPTION
 *  This function can query the free space left in QuotaSet (Quota Management only).
 *  User must register target path in QuotaSet, otherwise, FS_PATH_NOT_FOUND will be returned.
 *  If QMax is set as 0 (Infinite), then all free space left in system drive which allows user to use will be returned.
 * PARAMETERS
 *  Path   : [IN] <P>The full path defined in QuotaSet
 * RETURN VALUES
 *  >=0: Free space in bytes counted by (Number Application Free Cluster)*(Cluster Size)
 *  FS_PATH_NOT_FOUND (-19): Cannot find the path in QuotaSet
 *  FS_ACCESS_DENIED (-16): Quota Management is not enabled on this drive
 *  FS_DRIVE_NOT_FOUND (-4): Drive not found or not mounted, this is abnormal case
 *  FS_INVALID_FILE_SYSTEM (-8): Free cluster count of the drive is unknown, it is abnormal case
 * NOTE
 * (1)  Path name should be exactly the same as one in QuotaSet.
 * (2)  To save more resource, we use ¡§BYTE¡¨ (unsigned char) instead of FS traditional WCHAR here.
 *****************************************************************************/
extern int FS_QmGetFree(const BYTE * Path);
#endif

/*****************************************************************************
 * <GROUP  VolumeManagement>
 *
 * FUNCTION
 *  FS_CommitAll
 * DESCRIPTION
 *  This API will flush all currently dirty buffers to disk according to given drive.
 * PARAMETERS
 *  DriveName   : [IN] <P>Must either be a valid file name (e.g., a root directory name) or NULL. If DriveName is not NULL, only the drive information (possibly the current default drive) is determined. All of that drive's hosting device's dirty buffers are flushed. If the parameter is NULL, the buffers of all devices are flushed.
 * RETURNS
 *  Please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_CommitAll(const WCHAR * DriveName);

/*****************************************************************************
 * <GROUP  VolumeManagement>
 *
 * FUNCTION
 *  FS_SetVolumeLabel
 * DESCRIPTION
 *  This function is used to set the drive labe.
 * PARAMETERS
 *  DriveName   : [IN] <P>The Drive to be set volume label. It should be UCS2 encoded. For example, L¡§X:\¡¨
 *  Label       : [IN] <P>The label to be set to the specific drive. This label should be UCS2 encoded. In order to be compatible with windows, the maximum length should not exceed 11 bytes when it is converted to native encoding. The allowed character should follow the DOS 8.3 format.
 * RETURN VALUES
 *  FS_NO_ERROR : Successful
 *  FS_INVALID_FILENAME (-3): The file name is invalid.
 *  FS_INVALID_FILE_SYSTEM (-8): The specific drive doesn¡¦t contain a legal file system.
 *  FS_ROOT_DIR_FULL (-21): Root directory is full. The original name will be restored. (Since W09.35)
 *  FS_DISK_FULL (-22): Disk is full. The original name will be restored. (Since W09.35)
 * NOTE
 *  (1)File system can preserve the capital of volume name by creating LFN entry in FS_SetVolumeLabel(). However, Windows can only show ¡§upper case¡¨ volume name.
 *  (2)To get volume label, please use FS_GetDiskInfo() with FS_DI_BASIC_INFO and FS_DI_VOLUME_LABEL flags.
 *****************************************************************************/
extern int FS_SetVolumeLabel(const WCHAR * DriveName, const WCHAR * Label);

/*****************************************************************************
 * <GROUP  VolumeManagement>
 *
 * FUNCTION
 *  FS_SwitchDriveMode
 * DESCRIPTION
 *  This function provides formal plug out facility on MSDC (built-in or OTG external) for File Manager
 * PARAMETERS
 *  DriveIdx    : [IN] <P>The Drive to switch the mode
 *  Mode        : [IN] <P> FS_DRIVE_SOFT_UNMOUNT
 *                     <P> FS_DRIVE_SOFT_MOUNT
 * RETURN VALUES
 *  FS_NO_ERROR : success
 *  FS_DRIVE_NOT_FOUND (-4): The specified drive is not found.
 *  FS_INVALID_FILE_SYSTEM (-8): The specific drive doesn¡¦t contain a legal file system.
 *  FS_UNSUPPORTED_DEVICE (-11): It is an unsupported device.
 * HISTORY
 *  Since  W08.36
 * NOTE
 *  1. Only File Manager can call this function.
 *  2. Double lock in this function!
 *****************************************************************************/
extern int FS_SwitchDriveMode(UINT DriveIdx, UINT Mode);

/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  FS_CheckDiskFlag
 * DESCRIPTION
 *  This function provides NVRAM to check if last time power off is normal or abnormal. NVRAM can check the disk flag to decide do some action or not. (like advice end user to do sanity check or not)
 * PARAMETERS
 *  N/A
 * RETURNS
 *  0: Power off normally last time
 *  1: Power off abnormally last time
 *****************************************************************************/
extern int FS_CheckDiskFlag(void);

#ifdef __FS_CHECKDRIVE_SUPPORT__
/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  FS_CheckDrive
 * DESCRIPTION
 *  This function provides facility for user to check drive
 * PARAMETERS
 *  DriveIdx           : [IN] <P>The drive index ('Z' or 0x43, 0x44, ...etc.)
 *  CheckBuffer        : [IN] <P>The buffer get from caller
 *  CheckBufferLength  : [IN] <P>The buffer length, must > 2048
 * RETURNS
 *  Success: FS_NO_ERROR
 *  Error: list below
 * RETURN VALUES
 *  FS_NO_ERROR (0)
 *  FS_ACCESS_DENIED (-16): There¡¦s opened file in the drive.
 *  FS_FAIL_GET_MEM (-44): User provides a null buffer or smaller than 2048Byte
 *  FS_DRIVE_NOT_FOUND (-4): DriveIdx provide by caller not found
 *  FS_WRITE_PROTECTION (-30): the drive is on a write-protected media
 *  FS_INVALID_FILESYSTEM (-8): the drive not mounted
 *  FS_TOO_MANY_FILES (-5): the folders are too deep.
 * NOTE
 *  (1) This function is wrapped with compile option, __FS_CHECKDRIVE_SUPPORT__
 *  (2) This function requires a buffer as cluster-bit-map to process FAT file system internal data. The full size of cluster-bit-map can be retrieve by FS_GetCheckDrive(). For FAT16 disk, the maximum 8KB buffer size, and at least 16KB for FAT32. To break the growing RAM consumption by larger and larger disk size, this function still works if the check buffer size not fully provide. But the execution duration will longer. In worst case, execution duration will double if half buffer size provide.
 *  (3) File system does not allocate the buffer here. Caller could use ASM (Application Shared Memory) to get/free the memory by himself.
 *       Recommand Check Buffer Size : 128MB Disk Size ===>  8KB
 *                                   for 1GB Size Disk ===> 32KB
 *  (4) This function is non-recursive. However, if there is not enough file handles for file system to record the folders, file system will sweep the folders if they are too deep. Theoretically, file system support 20 levels of folders. In fact, it may be fewer if the some of the file handles are allocated by other application.
 *  (5) In this check function, invalid file/folder will be removed automatically.
 *  (6) Before invoking the FS_CheckDrive, please make sure there¡¦s no module that is initializing itself. FS_CheckDrive will block others task that tries to access the same drive.
 * EXAMPLE
 * <code>
 *      unsigned char *myPtr;
 *      kal_uint32 fullsize, maxsize;
 *      kal_uint32 DriveIdx = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
 *      fullsize = FS_ GetCheckBufferSize (DriveIdx);
 *      if (fullsize > FS_NO_ERROR)
 *      {
 *          maxsize = query_max_available_pool();//Caller should use ASM mechanism here
 *          maxsize = (maxsize > fullsize) ? fullsize : maxsize;
 *          myPtr = (unsigned char*)get_appshared_mem(maxsize); //Caller should use ASM mechanism here
 *          FS_CheckDrive(DriveIdx, myPtr, maxsize);
 *          if (myPtr) free_appshared_mem(myPtr); //Caller should use ASM mechanism
 *      }
 * </code>
 *****************************************************************************/
extern int FS_CheckDrive(const UINT DriveIdx, BYTE * CheckBuffer, const UINT CheckBufferSize);
#endif

/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  FS_GetDiskInfo
 * DESCRIPTION
 *  Return information about a logical drive
 * PARAMETERS
 *  DriveName   :   [IN] <P>Must be a valid file name, e.g., a root directory name. Only the drive information (possibly the current default drive) is determined.
 *  DiskInfo    :   [OUT]<P>Refer to FS_DiskInfo.
 *  Flags       :   [IN] <P>Refer to fs_di_enum.
 * RETURNS
 *  Please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_GetDiskInfo(const WCHAR * DriveName, FS_DiskInfo * DiskInfo, int Flags);

/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  FS_GetDevType
 * DESCRIPTION
 *  This function return the flash type for the corresponding path
 * PARAMETERS
 *  Path   : [IN] <P>The full-path which begin with drive letter
 * RETURN VALUES
 *  FS_DRIVE_NOT_FOUND(-4): Cannot find the drive described by user
 *  FS_DEVICE_TYPE_NOR (1): device type = NOR
 *  FS_DEVICE_TYPE_NAND (2): device type = NAND
 *  FS_DEVICE_TYPE_CARD (3): device type = memory card
 *  FS_DEVICE_TYPE_EXTERNAL (4): device type = OTG
 *****************************************************************************/
extern int FS_GetDevType(const WCHAR * Path);

/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  FS_GetDevStatus
 * DESCRIPTION
 *  This function provides a facility to let task looks up the device status.
 * PARAMETERS
 *  QueryTarget: [IN] <P>the index number get from FS_GetDrive, OR the type enum get from FS_GetDevType
 *  Flag       : [IN] <P>plesae refer to FS_GET_DEV_STATUS_ENUM. <color Red><b>Cannot set on simultaneously</b></color>
 * RETURN VALUES
 *  FS_NO_ERROR (0): Success.
 *  FS_PARAM_ERROR (-2): Over the drive range or flag error
 *  FS_DEVICE_BUSY (-46): Device is busy
 *  FS_FLASH_MOUNT_ERROR (-120): Fixed device is in un-mount state
 *  FS_MSDC_MOUNT_ERROR (-100): Removable device is in un-mount state (maybe not present or cannot be mounted)
 *  FS_EXTERNAL_DEVICE_NOT_PRESENT (-106): External device is not connected.
 *  FS_DEVICE_EXPORTED_ERROR (-52): Device is exported and controlled by USB
 * NOTE
 *  (1)This function cannot wait to get any lock!
 *  (2)The error code gives you a hint that the device is mounted, busy or exported now. If device is busy and you keep trying to access this device, you may hang there and wait for the device lock. If device is exported and you try to access this device, you will get FS_DEVICE_EXPORTED_ERROR (-52) again. For external card reader, if the device not connected yet, you will get FS_MSDC_MOUNT_ERROR (-100) return value when query for drive index and FS_EXTERNAL_DEVICE_NOT_PRESENT (-106) when query for device type.
 *  (3)If there are multiple devices with the same type, FS_GetDevStatus will return status of the 1st device matched to the input type.
 *****************************************************************************/
extern int FS_GetDevStatus(UINT DriveIdx, UINT Flag);

/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  FS_GetDevPartitions
 * DESCRIPTION
 *  This function provides a facility that user can query the number of partitions on the specific disk, and FS will return the number of partitions.
 * PARAMETERS
 *  QueryTarget: [IN] <P>The drive number (0x43~0x45(depended on customized configuration)) or device type enum (0x01~0x05) needs to lookup. The drive number can be retrieved by FS_GetDrive() API. Device type enum can be retrieved by FS_GetDevType() API.
 * RETURN VALUES
 *  Value > 0: number of partitions, at least 1.
 *  FS_PARAM_ERROR (-2): Over the drive range or device type range
 * NOTE
 *  (1)This function cannot wait to get any lock!
 *****************************************************************************/
extern int FS_GetDevPartitions(UINT QueryTarget);

/*****************************************************************************
 * <GROUP  FileOperation>
 *
 * FUNCTION
 *  FS_CountUsedFH
 * DESCRIPTION
 *  This function provide various kinds of query about number of file handles.
 * PARAMETERS
 *  flag : [IN] <P>indicate the query type for number of file handles
 *      <P>FS_FH_COUNT_CURRENT_TASK -  the number of file handles occupied by current task
 *      <P>FS_FH_COUNT_AVAILABLE -  the number of file handles available now
 *      <P>FS_FH_COUNT_USED -  the number of file handles that already in use.
 *      <P>FS_FH_COUNT_CONFIGURED -  the total number of file handles that static configured.
 * RETURNS
 *  Value >= 0 : the number of file handles queried.
 *  FS_PARAM_ERROR (-2): the input flag is invalid
 *****************************************************************************/
extern int FS_CountUsedFH(int flag);

/*****************************************************************************
 * <GROUP  Notification>
 *
 * FUNCTION
 *  FS_SetDirCache
 * DESCRIPTION
 *  This function provides facility for browsing type application to associate reusable value
 *  on the specific directory. Then get back the value or get miss error later.
 * PARAMETERS
 *  FileHandle : [IN]   <P>It¡¦s the file handle for specific directory. You can get the directory filehandle by FS_Open() with FS_OPEN_DIR flag or FS_FindFirst() API.
 *  NewValue   : [IN]   <P>The reusable value in 32-bit unsigned integer format is to be associated to specific directory. For example, number of files under the specific folder can be cached to speed up browsing application.
 * RETURNS
 *  Success: FS_NO_ERROR
 *  Error: refer to fs_error_enum.
 * HISTORY
 *  This API available since 06A Branch
 * EXAMPLE
 * <code>
 *      #define MY_PATH L¡¨Z:\\Folder1¡¨
 *
 *      FS_HANDLE fh;
 *      FS_DOSDirEntry FilInfo;
 *      kal_int32 result;
 *      kal_uint32 value;
 *      WCHAR FileNameBuf[260];
 *
 *      fh = FS_FindFirst(MY_PATH, 0, 0, &FileInfo, FileNameBuf, 520);
 *      // traverse process¡K come out a reusable value
 *      // for example, value = count_number_of_files_under_directories(fh);
 *      FS_SetDirCache(fh, value);
 *      FS_FindClose(fh);
 *
 *      ¡K..
 *
 *      // now we try to reuse the cached value
 *      kal_uint32 last_cached_value;
 *      FS_HANDLE fh;
 *      kal_int32 result;
 *
 *      fh = FS_Open(MY_PATH, FS_OPEN_DIR | FS_READ_ONLY);
 *      result = FS_GetDirCache(fh, &last_cached_value);
 *      FS_Close(fh);
 *
 *      if (result == FS_NO_ERROR)
 *      { // cache hit
 *        // process with last_cached_value is okay
 *      }
 *      else
 *      { // cache miss handling
 *        // sorry, we may have to redo it again.
 *      }
 * </code>
 *****************************************************************************/
extern int FS_SetDirCache(FS_HANDLE FileHandle, UINT NewValue);

/*****************************************************************************
 * <GROUP  Notification>
 *
 * FUNCTION
 *  FS_GetDirCache
 * DESCRIPTION
 *  This function provides facility for browsing type application to associate reusable value on the specific directory. File System will search on RAM to get the cache value set by latest FS_SetDirCache() with specific directory.
 * PARAMETERS
 *  FileHandle : [IN]   <P>It¡¦s the file handle for specific directory. You can get the directory filehandle by FS_Open() with FS_OPEN_DIR flag or FS_FindFirst() API.
 *  CurrValue  : [OUT]  <P>The reusable value in 32-bit unsigned integer format is to be associated to specific directory.
 * RETURNS
 * RETURN VALUES
 *  FS_NO_ERROR: Success
 *  FS_DIRCACHE_EXPIRED: the cached value not found
 *  Otherwise:  refer to fs_error_enum
 * HISTORY
 *  This API available since 06A Branch
 *****************************************************************************/
extern int FS_GetDirCache(FS_HANDLE FileHandle, UINT *CurrValue);

/*****************************************************************************
 * <GROUP  Notification>
 *
 * FUNCTION
 *  FS_ExpireDirCache
 * DESCRIPTION
 *  This function provides facility for browsing type application to associate reusable value on the specific directory. File System will expire the cache value set by latest FS_SetDirCache() with specific directory.
 * PARAMETERS
 *  FileHandle : [IN] <P>It¡¦s the file handle for specific directory. You can get the directory filehandle by FS_Open() with FS_OPEN_DIR flag or FS_FindFirst() API.
 * RETURNS
 * RETURN VALUES
 *  FS_NO_ERROR: Success
 *  FS_INVALID_FILE_HANDLE(-10): File handle invalid
 *  FS_ACCESS_DENIED(-16): File handle not associated to a directory
 *  Otherwise:  refer to fs_error_enum
 * HISTORY
 *  This API available since 06A Branch
 *****************************************************************************/
extern int FS_ExpireDirCache(FS_HANDLE FileHandle);

/*************************************************************************
 * <GROUP  DirectIOCtrl>
 *
 * FUNCTION
 *    FS_IOCtrl
 * DESCRIPTION
 *    Control or configure device, or read physical information of device by drive name
 * PARAMETERS
 *  DriveName   : [IN]      <P>DriveName could be any one drive name of the target memory device. It should be UCS2 encoded, e.g., L¡§X:\\¡¨.
 *  CtrlAction  : [IN]      <P>Please refer to fs_ioctrl_action_enum.
 *  CtrlData    : [IN/OUT]  <P>Control data. The usage is depended on the Control Action.
 * RETURN VALUES
 *  FS_NO_ERROR: Success
 *  FS_UNSUPPORTED_DRIVER_FUNCTION: The specified device does not support IOCtrl device driver.
 *  FS_PARAM_ERROR: Incorrect drive name
 *  FS_DRIVE_NOT_READY: Device is not in ready status or not mounted.
 *  FS_UNSUPPORTED_DEVICE: Device does not support the specified IO control action.
 * HISTORY
 *  Since W09.12
 *************************************************************************/
extern int FS_IOCtrl(const WCHAR* DriveName, UINT CtrlAction, void* CtrlData);

/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  FS_RecoverDevice
 * DESCRIPTION
 *  This function provides facility for user to recover flash disk,
 * PARAMETERS
 *  devtype     : [IN] <P>FS_DEVICE_TYPE_NOR or FS_DEVICE_TYPE_NAND can be assigned.
 * RETURN VALUES
 *  FS_NO_ERROR : success and finished
 *  FS_PARAM_ERROR (-2): No such device configured
 *****************************************************************************/
extern int FS_RecoverDevice(const int devtype);

#if defined(__MTP_ENABLE__)
/*****************************************************************************
 * <GROUP  MTP>
 *
 * FUNCTION
 *  FS_MakeFilePathByHint
 * DESCRIPTION
 *  Every file has its own directory entry for the file system to maintain the
 *  folder hierarchy. Every directory entry of a file can be located by the
 *  Cluster number of the file system and the offset in the cluster¡V(Cluster, Index).
 *  The coordinate (Cluster, Index) is called the Hint of the file. If the hint of a
 *  file is available, it can be used to perform some file operations without searching
 *  the file in the disk.
 *  If there is a hint belongs to a folder, this function can be used to get the full
 *  path of the folder. A file hint is not supported by this function. If a file hint
 *  is passed to this function, it returns FS_PATH_NOT_FOUND.
 * PARAMETERS
 *  DriveLetter : [IN] <P>Identify which drive the hint belongs to. E.g. ¡¥D¡¦, ¡¥E¡¦
 *  DirCluster  : [IN] <P>The cluster number of the folder hint.
 *  DirIndex    : [IN] <P>The Index of the folder hint.
 *  FileName    : [OUT]<P>The buffer to retrieve the file path
 *  MaxLength   : [IN] <P>The buffer size
 * RETURN VALUES
 *  FS_NO_ERROR : success and finished
 *  FS_PATH_NOT_FOUND (-19): The path doesn¡¦t exist
 *****************************************************************************/
extern int FS_MakeFilePathByHint(WCHAR DriveLetter, UINT DirCluster, UINT DirIndex, WCHAR * FileName, UINT MaxLength);

/*****************************************************************************
 * <GROUP  MTP>
 *
 * FUNCTION
 *  FS_OpenFileByHint
 * DESCRIPTION
 *  If a hint of a file or a folder is available, it can be used to open the file or the folder by the hint.
 * PARAMETERS
 *  DriveLetter : [IN] <P>Identify which drive the hint belongs to. E.g. ¡¥D¡¦, ¡¥E¡¦
 *  DirCluster  : [IN] <P>The cluster number of the folder hint.
 *  DirIndex    : [IN] <P>The Index of the folder hint.
 *  Flags       : [IN] <P>Can be a combination of the following flags:
 *          FS_READ_WRITE  FS_READ_ONLY   FS_OPEN_SHARED   FS_OPEN_NO_DIR
 *          FS_OPEN_DIR    FS_COMMITTED   FS_CACHE_DATA    FS_LAZY_DATA
 *          FS_NONBLOCK_MODE  FS_PROTECTION_MODE
 * RETURNS
 *  If the function succeeds, the return value is a file handle for the opened
 *  file and the file pointer of the file is set to 0. If the return value is less
 *  than 0, the function has failed and the return value is the error code.
 *****************************************************************************/
extern int FS_OpenFileByHint(WCHAR DriveLetter, UINT DirCluster, UINT DirIndex, UINT Flags);

/*****************************************************************************
 * <GROUP  MTP>
 *
 * FUNCTION
 *  FS_DeleteByHint
 * DESCRIPTION
 *  This function can be used to delete a file by the file hint. A folder hint
 *  is not supported by this function. If a hint of a folder is passed to this
 *  function, it returns FS_READ_ONLY_ERROR.
 * PARAMETERS
 *  DriveLetter : [IN] <P>Identify which drive the hint belongs to. E.g. ¡¥D¡¦, ¡¥E¡¦
 *  DirCluster  : [IN] <P>The cluster number of the folder hint.
 *  DirIndex    : [IN] <P>The Index of the folder hint.
 * RETURN VALUES
 *  FS_NO_ERROR : success
 *  FS_PATH_NOT_FOUND (-19): The path doesn¡¦t exist
 *  FS_READ_ONLY_ERROR (-45): A read-only file can¡¦t be deleted.
 *****************************************************************************/
extern int FS_DeleteByHint(WCHAR DriveLetter, UINT DirCluster, UINT DirIndex);

/*****************************************************************************
 * <GROUP  MTP>
 *
 * FUNCTION
 *  FS_GetAttributesByHint
 * DESCRIPTION
 *  This function can be used to retrieve the attribute of the file via a hint.
 * PARAMETERS
 *  DriveLetter : [IN] <P>Identify which drive the hint belongs to. E.g. ¡¥D¡¦, ¡¥E¡¦
 *  DirCluster  : [IN] <P>The cluster number of the folder hint.
 *  DirIndex    : [IN] <P>The Index of the folder hint.
 * RETURN VALUES
 *  FS_ATTR_READ_ONLY
 *  FS_ATTR_HIDDEN
 *  FS_ATTR_SYSTEM
 *  FS_ATTR_VOLUME
 *  FS_ATTR_DIR
 *  FS_ATTR_ARCHIVE
 *****************************************************************************/
extern int FS_GetAttributesByHint(WCHAR DriveLetter, UINT DirCluster, UINT DirIndex);

/*****************************************************************************
 * <GROUP  MTP>
 *
 * FUNCTION
 *  FS_SetAttributesByHint
 * DESCRIPTION
 *  This function can be used to set the attribute of the file via a hint.
 * PARAMETERS
 *  DriveLetter : [IN] <P>Identify which drive the hint belongs to. E.g. ¡¥D¡¦, ¡¥E¡¦
 *  DirCluster  : [IN] <P>The cluster number of the folder hint.
 *  DirIndex    : [IN] <P>The Index of the folder hint.
 *  Attributes  : [IN] <P>
 *  FS_ATTR_READ_ONLY
 *  FS_ATTR_HIDDEN
 *  FS_ATTR_SYSTEM
 *  FS_ATTR_VOLUME
 *  FS_ATTR_DIR
 *  FS_ATTR_ARCHIVE
 * RETURNS
 *  Please refer to fs_error_enum.
 * NOTE
 *  If you want to add/remove some attributes of a folder or volume, you should OR the
 *  FS_ATTR_DIR / FS_ATTR_VOLUME, too. Or you will get FS_ACCESS_DENIED failure.
 *****************************************************************************/
extern int FS_SetAttributesByHint(WCHAR DriveLetter, UINT DirCluster, UINT DirIndex, BYTE Attributes);

/*****************************************************************************
 * <GROUP  MTP>
 *
 * FUNCTION
 *  FS_HintGetParent
 * DESCRIPTION
 *  This function can be used to retrieve the parent¡¦s hint of a folder hint.
 * PARAMETERS
 *  DriveLetter   : [IN]  <P>Identify which drive the hint belongs to. E.g. ¡¥D¡¦, ¡¥E¡¦
 *  DirCluster    : [IN]  <P>The cluster number of the folder hint.
 *  DirIndex      : [IN]  <P>The Index of the folder hint.
 *  ParentCluster : [OUT] <P>The parent hint cluster of the folder hint
 *  ParentIndex   : [OUT] <P>The parent hint index of the folder hint
 * RETURNS
 *  Please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_HintGetParent(WCHAR DriveLetter, UINT DirCluster, UINT DirIndex, UINT *ParentCluster, UINT *ParentIndex);
#endif /* __MTP_ENABLE__ */

/*****************************************************************************
 * <GROUP InternalUse>
 *
 * FUNCTION
 *  FS_GetSysInfo
 *
 * DESCRIPTION
 *  This function provides facility for user to query file system status.
 *
 * PARAMETERS
 *  options :[IN]   Query options, it should be FS_SI_BASIC_INFO.
 *  info    :[IN]   Pointer to structure fs_sysinfo_struct.
 *
 * RETURNS
 * RETURN VALUES
 *  FS_NO_ERROR     : Success
 *  FS_PARAM_ERROR  : Parameter error
 *
 * HISTORY
 *  This API available since 10A.W10.52
 *****************************************************************************/
extern int FS_GetSysInfo(kal_uint32 options, fs_sysinfo_struct *info);

/*****************************************************************************
 * <GROUP  Notification>
 *
 * FUNCTION
 *  FS_DirCtrl
 * DESCRIPTION
 *  This function provides facility for browsing type application to associate reusable value
 *  on the specific directory. Then get back the value or get miss error later. Lock-down and un-lock features are also provided.
 * PARAMETERS
 *  handle : [IN]   <P>It¡¦s the file handle for specific directory. You can get the directory filehandle by FS_Open() with FS_OPEN_DIR flag or FS_FindFirst() API.
 *  action : [IN]   <P>It can be any of the following flags:
 *                  FS_DIRCTRL_DATA_SET
 *                  FS_DIRCTRL_DATA_GET
 *                  FS_DIRCTRL_DATA_EXPIRE
 *                  FS_DIRCTRL_DATA_LOCK
 *                  FS_DIRCTRL_DATA_UNLOCK
 *                  FS_DIRCTRL_DATA_SET_LOCK (Set and Lock)
 *                  FS_DIRCTRL_DATA_GET_LOCK (Get and Lock)
 *                  FS_DIRCTRL_DATA_GET_UNLOCK (Get and unlock)
 *                  FS_DIRCTRL_DATA_EXPIRE_UNLOCK (Expire and unlock)
 *  value  : [IN]   <P>The reusable value in 32-bit unsigned integer format is to be associated to specific directory. For example, number of files under the specific folder can be cached to speed up browsing application.
 * RETURNS
 *  Success: FS_NO_ERROR
 *  Error: refer to fs_error_enum.
 * HISTORY
 *  This API available since 11A Branch
 * EXAMPLE
 * <code>
 *      #define MY_PATH L¡¨Z:\\Folder1¡¨
 *
 *      FS_HANDLE fh;
 *      FS_DOSDirEntry FilInfo;
 *      kal_int32 result;
 *      kal_uint32 value;
 *      WCHAR FileNameBuf[260];
 *
 *      fh = FS_FindFirst(MY_PATH, 0, 0, &FileInfo, FileNameBuf, 520);
 *      // traverse process¡K come out a reusable value
 *      // for example, value = count_number_of_files_under_directories(fh);
 *      FS_DirCtrl(fh, FS_DIRCTRL_DATA_SET, value);
 *      FS_FindClose(fh);
 *
 *      ¡K..
 *
 *      // now we try to reuse the cached value
 *      kal_uint32 last_cached_value;
 *      FS_HANDLE fh;
 *      kal_int32 result;
 *
 *      fh = FS_Open(MY_PATH, FS_OPEN_DIR | FS_READ_ONLY);
 *      result = FS_DirCtrl(fh, FS_DIRCTRL_DATA_GET, value);
 *      FS_Close(fh);
 *
 *      if (result == FS_NO_ERROR)
 *      { // cache hit
 *        // process with last_cached_value is okay
 *      }
 *      else
 *      { // cache miss handling
 *        // sorry, we may have to redo it again.
 *      }
 * </code>
 *****************************************************************************/
extern int FS_DirCtrl(FS_HANDLE handle, kal_uint32 action, void *data);

extern void FS_SetFileTable(void *table);

/*****************************************************************************
 * <GROUP Asynchronous I/F>
 *
 * FUNCTION
 *    fs_aysnc_open
 *
 * DESCRIPTION
 *    Open a file
 *
 * PARAMETERS
 *  filename         :[IN]  Must point to the name of the file to open/create.
 *                          File names are not case sensitive; they will be converted to
 *                          upper case when file system searches this file, and they should
 *                          be two-byte aligned and UCS2 encoded. The file name can have one
 *                          of the following formats:
 *                          [Drive:][\][Path\]Name[.Ext]  A data file or directory file name with optional drive and path information.
 *                          [Drive:]\                     A root directory.
 *                          \\.\Drive:                    A logical drive.
 *                          \\.\PHYSICALDRIVEx            A physical hard disk. x must be a digit (starting at '0') specifying the desired hard disk.
 *                          \\.\FMapF\[hexstrings]        A virtual file, the whole path name should be generated by the dedicated FS_GenVirtualFileName API.
 *                          <Remarks> Absolute path is recommended because current dir may be changed by others before asynchronous API is executed!)
 *  flag             :[IN]  Can be a combination of the following flags:
 *                          FS_READ_WRITE       FS_READ_ONLY        FS_OPEN_SHARED      FS_OPEN_NO_DIR
 *                          FS_OPEN_DIR         FS_CREATE           FS_CREATE_ALWAYS    FS_COMMITTED
 *                          FS_CACHE_DATA       FS_LAZY_DATA        FS_ATTR_HIDDEN      FS_ATTR_SYSTEM
 *                          FS_ATTR_ARCHIVE     FS_NONBLOCK_MODE    FS_PROTECTION_MODE
 *  overlapped       :[IN]  Overlapped structure has 3 members,
 *                          1. callback :[IN]   (Optional) Call back function. This function will be executed just after response message is received by user.
 *                          2. param    :[IN]   (Optional) Parameters for call back function
 *                          3. priority :[IN]   (Deprecated) This function is replaced by KAL priority transfer, and the value will be ignored.
 *                                                           The users have to transfer the priority to the FS task on their own, if they have concerns about priority inversion.
 *                          4. buf      :[IN]   (*Required) Working buffer for FS asynchronous I/F. The buffer size should be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *                                                          Note that the working buffer should NOT be freed before response message of this FS asynchronous operation!
 *                                                          User could free it in callback function.
 *                          5. buf_size :[IN]   (*Required) Working buffer size. It shoud be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *                          6. response_flag [IN] (*Required) The response method when job done.
 *
 *                                                  1. FS_RESPONSE_MESSAGE:  Sending ILM when job done, the user must use fs_async_msg_handler() to execute the callback function.
 *
 *                                                                           For MMI task, File Manager Service will help register it. For other tasks, user must register message handler by themselves.
 *                                                  2. FS_RESPONSE_CALLBACK: Invoke callback function directly in the FS task when job done, and NO ILM sending back.
 * RETURNS
 *  Successful  : A positive integer. It is Job ID.
 *  Failed      : A negative integer. Please refer to fs_error_enum for details.
 *
 * NOTE
 *  1. User must assign the response flag in the overlapped structure,
 *  2. Pointer types in the overlapped structure, must be allocated from the memory poll, and freed in the callback function to avoid memory leak.
 *  3. DO NOT use pointer to local variables in overlapped structure, it will lead to memory corruption.
 *
 * EXAMPLE
 * <code>
 *  kal_int32               job_id;
 *  fs_overlapped_struct    overlapped;                     // !overlapped could be local variable
 *  void                    *buf;
 *  kal_wchar               *file_name = L"Z:\\folder\\file"
 *
 *  buf = xxx_malloc(FS_ASYNC_WORKING_BUFFER_SIZE);         // !working buffer should be prepared by users
 *
 *  kal_mem_set(&overlapped, 0, sizeof(fs_overlapped_struct));  // always clear the overlapped structure to zero
 *
 *  overlapped.callback = callback;
 *  overlapped.param    = param;
 *  overlapped.priority = FS_PRIORITY_DEFAULT;              // *Required: priority options
 *  overlapped.buf      = buf;                              // *Required: working buffer address
 *  overlapped.bufsize  = FS_ASYNC_WORKING_BUFFER_SIZE;     // *Required: working buffer size
 *  overlapped.response_flag = FS_RESPONSE_MESSAGE;         // *Required: response flag
 *
 *  job_id = fs_async_open(file_name, FS_CREATE, &overlapped);
 *
 *  if (job_id > FS_NO_ERROR)
 *  {
 *      // job is accepted by FS task.
 *      //
 *      // user could do other things.
 *      // Callback will be called in fs_async_msg_handler() after RSP message is received.
 *  }
 *  else
 *  {
 *      // job is rejected due to errors, and the FS API is not executed.
 *      //
 *      // Callback function will NOT be executed.
 *      // No response message in the future.
 *  }
 * </code>
 *
 * NOTE
 *
 *****************************************************************************/
extern kal_int32 fs_async_open(const kal_wchar *file_name, kal_int32 flag, fs_overlapped_struct *overlapped);

/*****************************************************************************
 * <GROUP Asynchronous I/F>
 *
 * FUNCTION
 *    fs_aysnc_write
 *
 * DESCRIPTION
 *    Write data to a file
 *
 * PARAMETERS
 *  handle          :[IN]   References the open file to write to.
 *  data            :[IN]   Specifies the address of the data to be written.
 *  length          :[IN]   Specifies the number of bytes to write.
 *  written         :[OUT]  Pointer to an unsigned integer to receive the number of
 *                          bytes actually been written. Usually, *Written will contain
 *                          Length after the call. However, in case of an error, the
 *                          returned value may be less. Written may be set to NULL if
 *                          this information is not required by an application.
 *  overlapped      :[IN]   Overlapped structure has 3 members,
 *                          1. callback :[IN]   (Optional) Call back function. This function will be executed just after response message is received by user.
 *                          2. param    :[IN]   (Optional) Parameters for call back function
 *                          3. priority :[IN]   (*Required) Priority of this job, it can be any one of following options,
 *                                                  1. FS_PRIORITY_DEFAULT  : User has no priority concern for this job)
 *                                                  2. FS_PRIORITY_INHERITED: FS task will be raised to a higher priorty to execute this job)
 *                          4. buf      :[IN]   (*Required) Working buffer for FS asynchronous I/F. The buffer size should be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *                                                          Note that the working buffer should NOT be freed before response message of this FS asynchronous operation!
 *                                                          User could free it in callback function.
 *                          5. buf_size :[IN]   (*Required) Working buffer size. It shoud be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *
 * RETURNS
 *  Successful  : A positive integer. It is Job ID.
 *  Failed      : A negative integer. Please refer to fs_error_enum for details.
 *
 * EXAMPLE
 * <code>
 * </code>
 *
 * NOTE
 *
 *****************************************************************************/
extern kal_int32 fs_async_write(FS_HANDLE handle, void *data, kal_uint32 length, kal_uint32 *written, fs_overlapped_struct *overlapped);

/*****************************************************************************
 * <GROUP Asynchronous I/F>
 *
 * FUNCTION
 *    fs_async_read
 *
 * DESCRIPTION
 *    Read data from a file
 *
 * PARAMETERS
 *  handle          :[IN]   References the open file to write to.
 *  data            :[IN]   Specifies the address of the data to be written.
 *  length          :[IN]   Specifies the number of bytes to write.
 *  read            :[OUT]  Pointer to an unsigned integer to receive the number of
 *                          bytes actually read. Usually, *Read will contain Length
 *                          after the call. However, in case of an error or if the
 *                          end of file is encountered during the read, the value may
 *                          be less. Read may be set to NULL if this information is
 *                          not required by an application.
 *  overlapped      :[IN]   Overlapped structure has 3 members,
 *                          1. callback :[IN]   (Optional) Call back function. This function will be executed just after response message is received by user.
 *                          2. param    :[IN]   (Optional) Parameters for call back function
 *                          3. priority :[IN]   (*Required) Priority of this job, it can be any one of following options,
 *                                                  1. FS_PRIORITY_DEFAULT  : User has no priority concern for this job)
 *                                                  2. FS_PRIORITY_INHERITED: FS task will be raised to a higher priorty to execute this job)
 *                          4. buf      :[IN]   (*Required) Working buffer for FS asynchronous I/F. The buffer size should be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *                                                          Note that the working buffer should NOT be freed before response message of this FS asynchronous operation!
 *                                                          User could free it in callback function.
 *                          5. buf_size :[IN]   (*Required) Working buffer size. It shoud be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *
 * RETURNS
 *  Successful  : A positive integer. It is Job ID.
 *  Failed      : A negative integer. Please refer to fs_error_enum for details.
 *
 * NOTE
 *  DO NOT assign pointer to local vaiable as 'written' in fs_job_write_struct, it will lead to memory corruption.
 *  The 'written' must be allocated from memory poll, or simply assign as NULL.
 *
 * EXAMPLE
 * <code>
 * </code>
 *
 * NOTE
 *
 *****************************************************************************/
extern kal_int32 fs_async_read(FS_HANDLE handle, void *data, kal_uint32 length, kal_uint32 *read, fs_overlapped_struct *overlapped);

/*****************************************************************************
 * <GROUP Asynchronous I/F>
 *
 * FUNCTION
 *    fs_async_read_interleave
 *
 * DESCRIPTION
 *    Read data from a file.
 *    Interleavely read the buffer to shorten the latency time when aborting.
 *
 * PARAMETERS
 *  handle          :[IN]   References the open file to write to.
 *  data            :[IN]   Specifies the address of the data to be written.
 *  length          :[IN]   Specifies the number of bytes to write.
 *  read            :[OUT]  Pointer to an unsigned integer to receive the number of
 *                          bytes actually read. Usually, *Read will contain Length
 *                          after the call. However, in case of an error or if the
 *                          end of file is encountered during the read, the value may
 *                          be less. Read may be set to NULL if this information is
 *                          not required by an application.
 *  chunksize       :[IN]   The buffer chunk size that read at a time, it must less than 'length'.
 *                          If chunksize is less than 32KB, the act of the function is idendical to fs_async_read().
 *  overlapped      :[IN]   Overlapped structure has 3 members,
 *                          1. callback :[IN]   (Optional) Call back function. This function will be executed just after response message is received by user.
 *                          2. param    :[IN]   (Optional) Parameters for call back function
 *                          3. priority :[IN]   (*Required) Priority of this job, it can be any one of following options,
 *                                                  1. FS_PRIORITY_DEFAULT  : User has no priority concern for this job)
 *                                                  2. FS_PRIORITY_INHERITED: FS task will be raised to a higher priorty to execute this job)
 *                          4. buf      :[IN]   (*Required) Working buffer for FS asynchronous I/F. The buffer size should be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *                                                          Note that the working buffer should NOT be freed before response message of this FS asynchronous operation!
 *                                                          User could free it in callback function.
 *                          5. buf_size :[IN]   (*Required) Working buffer size. It shoud be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *
 * RETURNS
 *  Successful  : A positive integer. It is Job ID.
 *  Failed      : A negative integer. Please refer to fs_error_enum for details.
 *
 * NOTE
 *  DO NOT assign pointer to local vaiable as 'read' in fs_job_read_struct, it will lead to memory corruption.
 *  The 'read' must be allocated from memory poll, or simply assign as NULL.
 *
 * EXAMPLE
 * <code>
 * </code>
 *
 * NOTE
 *
 *****************************************************************************/
extern kal_int32 fs_async_read_interleave(FS_HANDLE handle, void *data, kal_uint32 length, kal_uint32 *read, kal_uint32 chunksize, fs_overlapped_struct *overlapped);

/*****************************************************************************
 * <GROUP Asynchronous I/F>
 *
 * FUNCTION
 *    fs_async_seek
 *
 * DESCRIPTION
 *    Seek to a specific position of a file
 *
 * PARAMETERS
 *  handle          :[IN]   References the open file to seek to.
 *  offset          :[IN]   Specifies the offset (bytes) of the file to be seeked.
 *  whence          :[IN]   Specifies the method (start address) of the seek.
 *  overlapped      :[IN]   Overlapped structure has 3 members,
 *                          1. callback :[IN]   (Optional) Call back function. This function will be executed just after response message is received by user.
 *                          2. param    :[IN]   (Optional) Parameters for call back function
 *                          3. priority :[IN]   (*Required) Priority of this job, it can be any one of following options,
 *                                                  1. FS_PRIORITY_DEFAULT  : User has no priority concern for this job)
 *                                                  2. FS_PRIORITY_INHERITED: FS task will be raised to a higher priorty to execute this job)
 *                          4. buf      :[IN]   (*Required) Working buffer for FS asynchronous I/F. The buffer size should be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *                                                          Note that the working buffer should NOT be freed before response message of this FS asynchronous operation!
 *                                                          User could free it in callback function.
 *                          5. buf_size :[IN]   (*Required) Working buffer size. It shoud be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *
 * RETURNS
 *  Successful  : A positive integer. It is Job ID.
 *  Failed      : A negative integer. Please refer to fs_error_enum for details.
 *
 * EXAMPLE
 * <code>
 * </code>
 *
 * NOTE
 *
 *****************************************************************************/
extern kal_int32 fs_async_seek(FS_HANDLE handle, kal_int64 offset, kal_int32 whence, fs_overlapped_struct *overlapped);

/*****************************************************************************
 * <GROUP Asynchronous I/F>
 *
 * FUNCTION
 *    fs_async_delete
 *
 * DESCRIPTION
 *    Delete a file
 *
 * PARAMETERS
 *  filename        :[IN]   References the open file to seek to.
 *  overlapped      :[IN]   Overlapped structure has 3 members,
 *                          1. callback :[IN]   (Optional) Call back function. This function will be executed just after response message is received by user.
 *                          2. param    :[IN]   (Optional) Parameters for call back function
 *                          3. priority :[IN]   (*Required) Priority of this job, it can be any one of following options,
 *                                                  1. FS_PRIORITY_DEFAULT  : User has no priority concern for this job)
 *                                                  2. FS_PRIORITY_INHERITED: FS task will be raised to a higher priorty to execute this job)
 *                          4. buf      :[IN]   (*Required) Working buffer for FS asynchronous I/F. The buffer size should be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *                                                          Note that the working buffer should NOT be freed before response message of this FS asynchronous operation!
 *                                                          User could free it in callback function.
 *                          5. buf_size :[IN]   (*Required) Working buffer size. It shoud be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *
 * RETURNS
 *  Successful  : A positive integer. It is Job ID.
 *  Failed      : A negative integer. Please refer to fs_error_enum for details.
 *
 * EXAMPLE
 * <code>
 * </code>
 *
 * NOTE
 *
 *****************************************************************************/
kal_int32 fs_async_delete(const kal_wchar* filename, fs_overlapped_struct *overlapped);

/*****************************************************************************
 * <GROUP Asynchronous I/F>
 *
 * FUNCTION
 *    fs_async_get_folder_size
 *
 * DESCRIPTION
 *    This function provides a facility to get folder size
 *
 * PARAMETERS
 *  path            :[IN]   Full source path to be counted
 *  flag            :[IN]   FS_COUNT_IN_BYTE, FS_COUNT_IN_CLUSTER
 *  recursive_stack :[IN]   A memory pointer to store deep folder hierarchy recrusive data
 *  stack_size      :[IN]   The size of RecursiveStack
 *  overlapped      :[IN]   Overlapped structure has 3 members,
 *                          1. callback :[IN]   (Optional) Call back function. This function will be executed just after response message is received by user.
 *                          2. param    :[IN]   (Optional) Parameters for call back function
 *                          3. priority :[IN]   (*Required) Priority of this job, it can be any one of following options,
 *                                                  1. FS_PRIORITY_DEFAULT  : User has no priority concern for this job)
 *                                                  2. FS_PRIORITY_INHERITED: FS task will be raised to a higher priorty to execute this job)
 *                          4. buf      :[IN]   (*Required) Working buffer for FS asynchronous I/F. The buffer size should be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *                                                          Note that the working buffer should NOT be freed before response message of this FS asynchronous operation!
 *                                                          User could free it in callback function.
 *                          5. buf_size :[IN]   (*Required) Working buffer size. It shoud be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *
 * RETURNS
 *  Successful  : A positive integer. It is Job ID.
 *  Failed      : A negative integer. Please refer to fs_error_enum for details.
 *
 * EXAMPLE
 * <code>
 * </code>
 *
 * NOTE
 *
 *****************************************************************************/
extern kal_int32 fs_async_get_folder_size(const kal_wchar* path, kal_int32 flag, void* recursive_stack, kal_uint32 stack_size, FS_ProgressCallback callback, fs_overlapped_struct *overlapped);

/*****************************************************************************
 * <GROUP Asynchronous I/F>
 *
 * FUNCTION
 *  fs_async_find_first
 *
 * DESCRIPTION
 *  This function provides a facility to find Nth matching file
 *  and multi-patterns are supported
 *
 * PARAMETERS
 *  name_pattern    :[IN]       Find Pattern (Must have drive name. Must NOT use local variable!)
 *  attr            :[IN]       The attributes must have
 *  attr_mask       :[IN]       The attributes must not have
 *  file_info       :[IN/OUT]   File information (Must NOT use local variable!)
 *  file_name       :[IN/OUT]   the long file name (Must NOT use local variable!)
 *  max_length      :[IN]       The length of FileName
 *  overlapped       :[IN]  Overlapped structure has 3 members,
 *                          1. callback :[IN]   (Optional) Call back function. This function will be executed just after response message is received by user.
 *                          2. param    :[IN]   (Optional) Parameters for call back function
 *                          3. priority :[IN]   (*Required) Priority of this job, it can be any one of following options,
 *                                                  1. FS_PRIORITY_DEFAULT  : User has no priority concern for this job)
 *                                                  2. FS_PRIORITY_INHERITED: FS task will be raised to a higher priorty to execute this job)
 *                          4. buf      :[IN]   (*Required) Working buffer for FS asynchronous I/F. The buffer size should be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *                                                          Note that the working buffer should NOT be freed before response message of this FS asynchronous operation!
 *                                                          User could free it in callback function.
 *                          5. buf_size :[IN]   (*Required) Working buffer size. It shoud be at least FS_ASYNC_WORKING_BUFFER_SIZE.
*
 * RETURNS
 *  Successful  : A positive integer. It is Job ID.
 *  Failed      : A negative integer. Please refer to fs_error_enum for details.
 *
 * EXAMPLE
 * <code>
 * </code>
 *
 * NOTE
 *
 *****************************************************************************/
extern kal_int32 fs_async_find_first(const kal_wchar *name_pattern,
                              kal_uint8 attr, kal_uint8 attr_mask,
                              FS_DOSDirEntry *file_info, kal_wchar *file_name, kal_uint32 max_length,
                              fs_overlapped_struct *overlapped);

/*****************************************************************************
 * <GROUP Asynchronous I/F>
 *
 * FUNCTION
 *  fs_async_find_first_n
 *
 * DESCRIPTION
 *  This function provides a facility to find Nth matching file
 *  and multi-patterns are supported
 *
 * PARAMETERS
 *  name_pattern    :[IN]       Find Pattern (Must have drive name)
 *  pattern_array   :[IN]       Multi-patterns array (should not have drive name)
 *  pattern_num     :[IN]       Indicate how many pattern in PatternArray
 *  array_mask      :[IN]       The attributes that match default NamePattern only
 *  attr            :[IN]       The attributes must have
 *  attr_mask       :[IN]       The attributes must not have
 *  file_info       :[IN/OUT]   File information
 *  file_name       :[IN/OUT]   the long file name
 *  max_length      :[IN]       The length of FileName
 *  entry_index     :[IN]       Find Nth index
 *  overlapped      :[IN]       Overlapped structure has 3 members,
 *                              1. callback :[IN]   (Optional) Call back function. This function will be executed just after response message is received by user.
 *                              2. param    :[IN]   (Optional) Parameters for call back function
 *                              3. priority :[IN]   (*Required) Priority of this job, it can be any one of following options,
 *                                                  1. FS_PRIORITY_DEFAULT  : User has no priority concern for this job)
 *                                                  2. FS_PRIORITY_INHERITED: FS task will be raised to a higher priorty to execute this job)
 *                              4. buf      :[IN]   (*Required) Working buffer for FS asynchronous I/F. The buffer size should be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *                                                              Note that the working buffer should NOT be freed before response message of this FS asynchronous operation!
 *                                                              User could free it in callback function.
 *                              5. buf_size :[IN]   (*Required) Working buffer size. It shoud be at least FS_ASYNC_WORKING_BUFFER_SIZE.
 *
 * RETURNS
 *  Successful  : A positive integer. It is Job ID.
 *  Failed      : A negative integer. Please refer to fs_error_enum for details.
 *
 * EXAMPLE
 * <code>
 * </code>
 *
 * NOTE
 *
 *****************************************************************************/
extern kal_int32 fs_async_find_first_n(const kal_wchar *name_pattern,
                              FS_Pattern_Struct * pattern_array, kal_uint32 pattern_num,
                              kal_uint8 array_mask, kal_uint8 attr, kal_uint8 attr_mask,
                              FS_DOSDirEntry *file_info, kal_wchar *file_name, kal_uint32 max_length,
                              kal_uint32 entry_index, kal_uint32 flag,
                              fs_overlapped_struct *overlapped);

/*****************************************************************************
 * <GROUP Asynchronous I/F>
 *
 * FUNCTION
 *  fs_async_msg_handler
 *
 * DESCRIPTION
 *  This function provides following facilities,
 *  1. Execute user's callback function
 *  2. Clean FS internal resource for this job.
 *
 * PARAMETERS
 *  local_para  :[IN]   Local parameter of ILM message
 *
 * EXAMPLE
 * <code>
 *  ilm_struct current_ilm;
 *
 *  while (1)
 *  {
 *      receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
 *
 *      if (current_ilm.sap_id == FS_SAP)   // User could use SAP ID to identify if this message comes from FS task
 *      {
 *          fs_async_msg_handler(current_ilm.local_para_ptr);   // process FS response message
 *      }
 *      else
 *      {
 *          // not FS response message, do something else ...
 *      }
 *  }
 * </code>
 *
 * NOTE
 *
 *****************************************************************************/
extern void fs_async_msg_handler(local_para_struct *local_para);

/*****************************************************************************
 * <GROUP Asynchronous I/F>
 *
 * FUNCTION
 *  fs_async_abort
 *
 * DESCRIPTION
 *  This function provides the facility to abort a specific job by Job ID
 *
 * PARAMETERS
 *  job_id      :[IN]   Job ID
 *
 * EXAMPLE
 * <code>
 * fs_async_abort(job_id);
 * </code>
 *
 * NOTE
 *    1. This function only abort the asynchronous job in the job list, not the file handle.
 *       Use FS_Abort(), if you want to abort the handle.
 *    2. This function can not abort the job that is not yet recieved by the FS task.
 *       You can use fs_async_abort_ex(), and explicitly assign the buf address to abort non-recived jobs.
 *
 *****************************************************************************/
extern kal_int32 fs_async_abort(fs_job_id job_id);

/*****************************************************************************
 * <GROUP Asynchronous I/F>
 *
 * FUNCTION
 *  fs_async_abort_ex
 *
 * DESCRIPTION
 *  This function provides the facility to abort a specific job, even if it is not recieved by the FS task.
 *
 *
 * PARAMETERS
 *  job_id      :[IN]   Job ID
 *  buf         :[IN]   Pointer to the buffer, it can not be NULL.
 *
 * EXAMPLE
 * <code>
 * fs_async_abort_ex(job_id, overlapped.buf);
 * </code>
 *
 * NOTE
 *    1. This function only abort the asynchronous job in the job list, not the file handle.
 *
 *****************************************************************************/
extern kal_int32 fs_async_abort_ex(fs_job_id job_id, void *buf);

/* DOM-NOT_FOR_SDK-BEGIN */
/*
   NOTE!!!
   Following prototypes are not belong to MAUI SDK, and shall not be used.
*/
/*****************************************************************************
 * <GROUP  Statistics>
 *
 * FUNCTION
 *  FS_StartIOLog
 * DESCRIPTION
 *  Gathering the IO statistics of each task during a time period.
 *  Save current IO status of every task and start logging.
 * PARAMETERS
 *  Statistics  : [IN]<P>The pointer to the user allocated statistic buffer,
 *                       the size of the buffer must queried from FS_GetIOStatisticsSize().
 * RETURNS
 *  Successful: FS_NO_ERROR (0)
 *  Failed: 	FS_PARAM_ERROR (-2)
 *
 * EXAMPLE
 * <code>
 * FS_TaskIOStatistics *iostat=NULL;
 * iostat=(FS_TaskIOStatistics*)get_ctrl_buffer(FS_GetIOStatisticsSize());
 * FS_StartIOLog(fst_iostat);  // Start logging
 *
 * // ... Some File System Opeartion
 *
 * FS_EndIOLog(fst_iostat);  // End logging and print result to MOD_FS TRACE_ERROR
 * free_ctrl_buffer(fst_iostat);
 * </code>
 *
 * SEE ALSO
 *  FS_EndIOLog
 *  FS_GetIOStatisticsSize
 *****************************************************************************/
extern int FS_StartIOLog(FS_TaskIOStatistics *Statistics);

/*****************************************************************************
 * <GROUP  Statistics>
 *
 * FUNCTION
 *  FS_EndIOLog
 * DESCRIPTION
 *  Gathering the IO statistics of each task during a time period.
 *  End logging, caculate IO statistics and print result to MOD_FS TRACE_ERROR.
 * PARAMETERS
 *  Statistics  : [IN/OUT]<P>The pointer to the IO statistics saved by FS_StartIOLog()
 *
 * RETURNS
 *  Successful: FS_NO_ERROR (0)
 *  Failed: 	FS_PARAM_ERROR (-2)
 *
 * EXAMPLE
 * <code>
 * FS_TaskIOStatistics *iostat=NULL;
 * iostat=(FS_TaskIOStatistics*)get_ctrl_buffer(FS_GetIOStatisticsSize());
 * FS_StartIOLog(fst_iostat);
 *
 * // ... Some File System Opeartion
 *
 * FS_EndIOLog(fst_iostat);
 * free_ctrl_buffer(fst_iostat);
 * </code>
 *
 * SEE ALSO
 *  FS_StartIOLog
 *  FS_GetIOStatisticsSize
 *
 * NOTE
 *  FS_StartIOLog and FS_EndIOLog must come in pairs, using the same statistic buffer.
 *****************************************************************************/
extern int FS_EndIOLog(FS_TaskIOStatistics *Statistics);

/*****************************************************************************
 * <GROUP  CardManagement>
 *
 * FUNCTION
 *  FS_TestMSDC
 * DESCRIPTION
 *  This function provides mount/un-mount FS facility on MSDC Card Slots for File Manager
 * PARAMETERS
 *  slot_id    : [IN] <P>DriverData Pointer which points to a device.
 *  drive_list : [IN] <P>A list of DriveData. Applications could specify not only one drive.
 *  drive_num  : [IN] <P>Number of drive_list
 * RETURNS
 * RETURN VALUES
 *  FS_NO_ERROR (0): Card is present, and mount FS successfully.
 *  FS_MSDC_NOT_PRESENT (-105): Card is not present, and un-mount FS successfully.
 *  FS_EXTERNAL_NOT_PRESENT (-106): External card reader not present.
 *  FS_MSDC_MOUNT_ERROR (-100): Disk is formatting or mount driver fail.
 *  FS_UNSUPPORTED_DEVICE (-11): It should be task owner error at development stage.
 *  FS_UNSUPPORTED_DRIVER_FUNCTION (-12): It should be FS error at development stage.
 * NOTE
 *  (1) Only file management task can use this function.
 *  (2) If file system is not in mount state, other task cannot access removable device until file management task mount the device successfully. Actually, this is not the convention in file system. For other fixed devices, the first one accesses file system will trigger file system to mount the device if the status is not ready.
 *****************************************************************************/
int FS_TestMSDC(void * slot_id, BYTE * drive_list, UINT * drive_num);

/*****************************************************************************
 * <GROUP  Obsolete >
 *
 * FUNCTION
 *  FS_CloseMSDC
 * DESCRIPTION
 *  This function provides formal plug out facility on MSDC (built-in or OTG external) for File Manager
 * PARAMETERS
 *  MSDCIndex  : [IN] <P>The drive index (0x43, 0x44, ...etc.)
 *  Mode       : [IN] <P>block or not
 *                 0: block mode (get lock will wait forever)
 *  FS_NONBLOCK_MODE: non-block mode (if someone is taking the lock of FS or device, returns right away)
 * RETURNS
 * RETURN VALUES
 *  FS_PARAM_ERROR (-2): mode parameter error
 *  FS_DRIVE_NOT_FOUND (-4): cannot find the specific Drive Index.
 *  FS_UN SUPPORTED_DEVICE (-11): trying to close non-removable device.
 *  FS_INVALID_FILESYSTEM (-8): Call this function when FS is not initialized, but can remove device safely now
 *  FS_TIMEOUT (-23): Cannot get FS or device lock
 *****************************************************************************/
extern int FS_CloseMSDC(UINT MSDCIndex, UINT Mode);

/*****************************************************************************
 * <GROUP  OTG>
 *
 * FUNCTION
 *  FS_ConfigExtDevice
 * DESCRIPTION
 *  This function is designed to support external device that can contain variance number slots and drives such as card reader. FS_ConfigExtDevice() should be called after the external device cable connected on or plugged out.
 * PARAMETERS
 *  Action         : [IN] <P>accept FS_SETUP_EXT_DEVICE or FS_ RELEASE_EXT_DEVICE only
 *  DrvFuncs       : [IN] <P>The pointer of device driver callback function array, {MountDevice, Shutdown, ... }. Provided by device driver.
 *  Slots          : [IN] <P>Number of independent slots. Number of elements in SlotIdArray
 *  SlotIdArray    : [IN] <P>The DriverData (treat as slot identify) array to be filled on device list.
 *  SlotsConfiged  : [IN] <P>Pointer to an integer to receive the number of bytes actually configured. Usually, *SlotsConfiged will contain Slots after the call. However, in case of an error.
 * RETURNS
 * RETURN VALUES
 *  FS_PARAM_ERROR (-2): NULL DrvFuncs, SlotIdArray or 0 Slots.
 *  FS_UNSUPPORTED_DEVICE (-11): The device try to configure not found in the list.
 *  FS_ UNSUPPORTED_DRIVER_FUNCTION (-12): The device doesn¡¦t support hot plug IO mechanism.
 * NOTE
 *  Currently, No *allocate* operation commited, this API is design to keep FMT/FS/DRV iterface
 *  complete. But not real dynamic yet!
 *****************************************************************************/
extern int FS_ConfigExtDevice(int Action, FS_Driver *DrvFuncs, int Slots, void **SlotIdArray, int *SlotsConfiged);

extern int FS_MountRemovableDevice(void);

/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  FS_SanityCheck
 * DESCRIPTION
 *     This function provides a facility to handle the following critical jobs
 *     (1) RUN ONCE
 *         a. file system initialization, fixed device mount, system drive mount
 *         b. make 'Z' drive letter as system drive alias
 *         c. system drive power lose recovery
 *         d. file system trace/debug level default setting
 *         e. system drive quota sweep
 *         f. mount removable card device
 *     (2) RUN AFTER FILE SYSTEM INITIALIZED
 *         g. quota configure check
 * RETURNS
 *  Refer to fs_error_enum.
 * Note
 *  This function cannot wait to get any lock!
 *****************************************************************************/
extern int FS_SanityCheck(void);

/* DOM-NOT_FOR_SDK-END */

#else

// Smart Phone Modem Wrapper
//------------------------------------------------------------

/* DOM-NOT_FOR_SDK-BEGIN */

#include "ccci_fs_if.h"

#define MD_FS_API(n, ...) MD##_##n(__VA_ARGS__)

#define FS_CMPT_Read(...)			MD_FS_API(FS_CMPT_Read, __VA_ARGS__)

// General I/O
#define FS_Open(...)					MD_FS_API(FS_Open, __VA_ARGS__)
#define FS_OpenHint(...)				MD_FS_API(FS_OpenHint, __VA_ARGS__)
#define FS_Close(...)					MD_FS_API(FS_Close, __VA_ARGS__)
#define FS_CloseAll(...)				MD_FS_API(FS_CloseAll, __VA_ARGS__)
#define FS_Read(...)					MD_FS_API(FS_Read, __VA_ARGS__)
#define FS_Write(...)					MD_FS_API(FS_Write, __VA_ARGS__)
#define FS_EnableSmartSeek(...)     -255
#define FS_SetSeekHint(...)			-255//MD_FS_API(FS_SetSeekHint, __VA_ARGS__)
#define FS_SetSeekHintEx(...)			-255//MD_FS_API(FS_SetSeekHint, __VA_ARGS__)
#define FS_SeekLargeFile(...)    MD_FS_API(FS_Seek, __VA_ARGS__)
#define FS_Seek(...)					MD_FS_API(FS_Seek, __VA_ARGS__)
#define FS_Commit(...)				-255//MD_FS_API(FS_Commit, __VA_ARGS__)
#define FS_ReleaseFH(...)				-255//MD_FS_API(FS_ReleaseFH, __VA_ARGS__)
#define FS_Abort(...)					-255//MD_FS_API(FS_Abort, __VA_ARGS__)
#define FS_ParseFH(...)				-255//MD_FS_API(FS_ParseFH, __VA_ARGS__)
#define FS_GenVirtualFileName(...)		-255//MD_FS_API(FS_GenVirtualFileName, __VA_ARGS__)

//Information
#define FS_GetFileInfo(...)				-255//MD_FS_API(FS_GetFileInfo, __VA_ARGS__)
#define FS_GetFileInfoEx(...)				-255//MD_FS_API(FS_GetFileInfoEx, __VA_ARGS__)
#define FS_GetFileSize(...)				MD_FS_API(FS_GetFileSize, __VA_ARGS__)
#define FS_GetFilePosition(...)			-255//MD_FS_API(FS_GetFilePosition, __VA_ARGS__)
#define FS_SetFileTime(...)			-255//MD_FS_API(FS_SetFileTime, __VA_ARGS__)
#define FS_GetAttributes(...)			MD_FS_API(FS_GetAttributes, __VA_ARGS__) // Meta tool need this
#define FS_GetFirstCluster(...)			-255//MD_FS_API(FS_GetFirstCluster, __VA_ARGS__)
#define FS_GetSysInfo(...)			-255//MD_FS_API(FS_GetSysInfo, __VA_ARGS__)
#define FS_SetFileTable(...)        -255//MD_FS_API(FS_SetFileTable, __VA_ARGS__)
#define FS_Config(...)			-255//MD_FS_API(FS_Config, __VA_ARGS__)

//File Only Operation
#define FS_SetAttributes(...)			-255//MD_FS_API(FS_SetAttributes, __VA_ARGS__)
#define FS_Delete(...)					MD_FS_API(FS_Delete, __VA_ARGS__)
#define FS_DeleteEx(...)					-255//MD_FS_API(FS_DeleteEx, __VA_ARGS__)
#define FS_PseudoMerge(...)			-255//MD_FS_API(FS_PseudoMerge, __VA_ARGS__)
#define FS_CheckFile(...)				-255//MD_FS_API(FS_CheckFile, __VA_ARGS__)

//Folder Only Operation
#define FS_GetCurrentDir(...)			-255//MD_FS_API(FS_GetCurrentDir, __VA_ARGS__)
#define FS_GetCurrentDirByDrive(...) -255//MD_FS_API(FS_GetCurrentDirByDrive, __VA_ARGS__)
#define FS_SetCurrentDir(...)			-255//MD_FS_API(FS_SetCurrentDir, __VA_ARGS__)
#define FS_CreateDir(...)				MD_FS_API(FS_CreateDir, __VA_ARGS__)
#define FS_RemoveDir(...)				MD_FS_API(FS_RemoveDir, __VA_ARGS__)
#define FS_GetFolderSize(...)			MD_FS_API(FS_GetFolderSize, __VA_ARGS__)
#define FS_GetFolderSizeEx(...)			MD_FS_API(FS_GetFolderSizeEx, __VA_ARGS__)

//File and Folder Operations
#define FS_Extend(...)					-255//MD_FS_API(FS_Extend, __VA_ARGS__)
#define FS_Truncate(...)				-255//MD_FS_API(FS_Truncate, __VA_ARGS__)
#define FS_MakeFileName(...)			-255//MD_FS_API(FS_MakeFileName, __VA_ARGS__)
#define FS_Rename(...)				MD_FS_API(FS_Rename, __VA_ARGS__)

#define FS_Move(...)					MD_FS_API(FS_Move, __VA_ARGS__)

#define FS_Count(...)					MD_FS_API(FS_Count, __VA_ARGS__)
#define FS_XDelete(...)				MD_FS_API(FS_XDelete, __VA_ARGS__)
#define FS_XDeleteEx(...)				-255//MD_FS_API(FS_XDeleteEx, __VA_ARGS__)

#define FS_CompactDir(...)				-255//MD_FS_API(FS_XDeleteEx, __VA_ARGS__)

#define FS_CheckFileName(...)           -255//MD_FS_API(FS_CheckFileName, __VA_ARGS__)
#define FS_CheckVolumeLabel(...)        -255//MD_FS_API(FS_CheckVolumeLabel, __VA_ARGS__)

//Find File
#define FS_FindFirst(...)				MD_FS_API(FS_FindFirst, __VA_ARGS__)
#define FS_FindNext(...)				MD_FS_API(FS_FindNext, __VA_ARGS__)
#define FS_FindFirstN(...)				-255//MD_FS_API(FS_FindFirstN, __VA_ARGS__)
#define FS_FindNextN(...)				-255//MD_FS_API(FS_FindNextN, __VA_ARGS__)
#define FS_FindClose(...)				MD_FS_API(FS_FindClose, __VA_ARGS__)
#define FS_ListOpen(...)                -255
#define FS_ListReload(...)              -255
#define FS_ListNext(...)                -255
#define FS_ListClose(...)               -255

#ifdef __FS_SORT_SUPPORT__
#define FS_SortCompareFileName(...)     -255
#define FS_SortCompareFileType(...)     -255
#define FS_XFindReset(...)				-255//MD_FS_API(FS_XFindReset, __VA_ARGS__)
#define FS_XFindStart(...)				-255//MD_FS_API(FS_XFindStart, __VA_ARGS__)
#define FS_XFindClose(...)				-255//MD_FS_API(FS_XFindClose, __VA_ARGS__)
#endif

//Drive Management
#define FS_GetDrive(...)				MD_FS_API(FS_GetDrive, __VA_ARGS__)
#define FS_GetDriveByHandle(...)		-255//MD_FS_API(FS_GetDriveByHandle, __VA_ARGS__)
#define FS_GeneralFormat(...)			-255//MD_FS_API(FS_GeneralFormat, __VA_ARGS__)
#define FS_GetClusterSize(...)			MD_FS_API(FS_GetClusterSize, __VA_ARGS__)
#ifdef __FS_QM_SUPPORT__
#define FS_QmGetFree(...)				-255//MD_FS_API(FS_QmGetFree, __VA_ARGS__)
#endif
#define FS_CreateBootSector(...)		0//MD_FS_API(FS_CreateBootSector, __VA_ARGS__)
#define FS_GetPartitionInfo(...)		-255//MD_FS_API(FS_GetPartitionInfo, __VA_ARGS__)
#define FS_CommitAll(...)				-255//MD_FS_API(FS_CommitAll, __VA_ARGS__)
#define FS_MappingDrive(...)			-255//MD_FS_API(FS_MappingDrive, __VA_ARGS__)

//Power Lost Detection and Recovery
#define FS_SetDiskFlag(...)			MD_FS_API(FS_SetDiskFlag, __VA_ARGS__)
#define FS_CheckDiskFlag(...)			-255//MD_FS_API(FS_CheckDiskFlag, __VA_ARGS__)
#define FS_ClearDiskFlag(...)			MD_FS_API(FS_ClearDiskFlag, __VA_ARGS__)
#ifdef __FS_CHECKDRIVE_SUPPORT__
#define FS_CheckDrive(...)			-255//MD_FS_API(FS_CheckDrive, __VA_ARGS__)
#endif

//Disk Management
#define FS_CreateMasterBootRecord(...)	0//MD_FS_API(FS_CreateMasterBootRecord, __VA_ARGS__)
#define FS_SplitPartition(...)				0//MD_FS_API(FS_SplitPartition, __VA_ARGS__)
#define FS_GetDiskInfo(...)				MD_FS_API(FS_GetDiskInfo, __VA_ARGS__)
#define FS_GetDevType(...)				-255//MD_FS_API(FS_GetDevType, __VA_ARGS__)
#define FS_GetDevStatus(...)				-255//MD_FS_API(FS_GetDevStatus, __VA_ARGS__)
#define FS_GetDevPartitions(...)			-255//MD_FS_API(FS_GetDevPartitions, __VA_ARGS__)

//Card management
#define FS_TestMSDC(...)				-255//MD_FS_API(FS_TestMSDC, __VA_ARGS__)
#define FS_CloseMSDC(...)				-255//MD_FS_API(FS_CloseMSDC, __VA_ARGS__)
#define FS_MountRemovableDevice(...)	-255//MD_FS_API(FS_MountRemovableDevice, __VA_ARGS__)

//OTG Card Reader Management
#define FS_ConfigExtDevice(...)		-255//MD_FS_API(FS_ConfigExtDevice, __VA_ARGS__)

//File System Run-Time LifeCycle
#define FS_ShutDown(...)				MD_FS_API(FS_ShutDown, __VA_ARGS__)
#define FS_UnlockAll(...)				MD_FS_API(FS_UnlockAll, __VA_ARGS__)
#define FS_SanityCheck(...)			-255//MD_FS_API(FS_SanityCheck, __VA_ARGS__)
#define FS_LockFAT(...)				MD_FS_API(FS_LockFAT, __VA_ARGS__)

//File System Run-Time Debug
#define FS_CountUsedFH(...)			-255//MD_FS_API(FS_CountUsedFH, __VA_ARGS__)
#ifdef __FS_TRACE_SUPPORT__
#define FS_SetTrace(...)				-255//MD_FS_API(FS_SetTrace, __VA_ARGS__)
#define FS_DumpFHTable(...)			-255//MD_FS_API(FS_DumpFHTable, __VA_ARGS__)
#endif

//DirCache
#define FS_SetDirCache(...)			-255//MD_FS_API(FS_SetDirCache, __VA_ARGS__)
#define FS_GetDirCache(...)			-255//MD_FS_API(FS_GetDirCache, __VA_ARGS__)
#define FS_ExpireDirCache(...)			-255//MD_FS_API(FS_ExpireDirCache, __VA_ARGS__)
#define FS_DirCtrl(...)			-255//MD_FS_API(FS_DirCtrl, __VA_ARGS__)

//Flash Device Direct IO
#define FS_OTPWrite(...)		MD_FS_API(FS_OTPWrite, __VA_ARGS__)
#define FS_OTPRead(...)			MD_FS_API(FS_OTPRead, __VA_ARGS__)
#define FS_OTPQueryLength(...)		MD_FS_API(FS_OTPQueryLength, __VA_ARGS__)
#define FS_OTPLock(...)			MD_FS_API(FS_OTPLock, __VA_ARGS__)
#define FS_IOCtrl(...)              -255//MD_FS_API(FS_IOCtrl, __VA_ARGS__)

//Flash Sweep
#define FS_SweepDevice(...)			-255//MD_FS_API(FS_SweepDevice, __VA_ARGS__)

#define FS_StartIOLog(...)          -255
#define FS_EndIOLog(...)            -255

#if defined(__MTP_ENABLE__)
#define FS_MakeFilePathByHint(...)  -255//MD_FS_API(FS_MakeFilePathByHint, __VA_ARGS__)
#define FS_OpenFileByHint(...)      -255//MD_FS_API(FS_OpenFileByHint, __VA_ARGS__)
#define FS_DeleteByHint(...)        -255//MD_FS_API(FS_DeleteByHint, __VA_ARGS__)
#define FS_GetAttributesByHint(...) -255//MD_FS_API(FS_GetAttributesByHint, __VA_ARGS__)
#define FS_SetAttributesByHint(...) -255//MD_FS_API(FS_SetAttributesByHint, __VA_ARGS__)
#define FS_HintGetParent(...)       -255//MD_FS_API(FS_HintGetParent, __VA_ARGS__)
#endif // __MTP_ENABLE__

#define fs_async_abort(...)             -255
#define fs_async_find_first(...)        -255
#define fs_async_find_first_n(...)      -255
#define fs_async_get_folder_size(...)   -255
#define fs_async_open(...)              -255
#define fs_async_read(...)              -255
#define fs_async_read_interleave(...)   -255
#define fs_async_seek(...)              -255
#define fs_async_write(...)             -255

/* DOM-NOT_FOR_SDK-END */

#endif


#ifdef __cplusplus
}
#endif

#endif // _FS_GPROT_H


