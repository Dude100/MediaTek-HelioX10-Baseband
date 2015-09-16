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

/*******************************************************************************
 * Filename:
 * ---------
 *   fs_trc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is trace map definition for FS.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _FS_TRC_H
#define _FS_TRC_H

#ifndef __FS_CARD_DOWNLOAD__
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_trace.h"

#ifndef GEN_FOR_PC

   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before tst_config.h"
   #endif

#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */

#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before tst_trace.h"
#endif

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "fs_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_FS)

   /* FS APIs */
   TRC_MSG(FS_API_FS_OPEN_S,    "[%Mmodule_type] FS_Open <- Caller: 0x%X, Flag: 0x%X, FileName:")
   TRC_MSG(FS_API_FS_OPEN_E,    "[%Mmodule_type] FS_Open -> Return: 0x%X")
   TRC_MSG(FS_API_FS_OPEN_E_TIME,   "[%Mmodule_type] FS_Open -> Return: 0x%X, Duration: %d us")
   TRC_MSG(FS_API_FS_OPEN_E_TIME_0, "[%Mmodule_type] FS_Open -> Return: 0x%X, Duration: 0 us")
   TRC_MSG(FS_API_FS_CLOSE_S,   "[%Mmodule_type] FS_Close <- FileHandle: 0x%X")
   TRC_MSG(FS_API_FS_CLOSE_E,   "[%Mmodule_type] FS_Close -> Return: %Mfs_error_enum, Duration: %d us")
   TRC_MSG(FS_API_FS_READ_S,    "[%Mmodule_type]    FS_Read <- File(SFN): %c%c%c%c%c%c%c%c.%c%c%c, Dev: %MFS_DEVICE_TYPE_ENUM, FileHandle: 0x%X, DataPtr: 0x%X, Length: %u")
   TRC_MSG(FS_API_FS_READ_E,    "[%Mmodule_type]    FS_Read -> Return: %Mfs_error_enum, Length: %u, Duration: %u us, Throughput: %u KB/s")
   TRC_MSG(FS_API_FS_WRITE_S,   "[%Mmodule_type]    FS_Write <- File(SFN): %c%c%c%c%c%c%c%c.%c%c%c, Dev: %MFS_DEVICE_TYPE_ENUM, FileHandle: 0x%X, DataPtr: 0x%X, Length: %d")
   TRC_MSG(FS_API_FS_WRITE_E,   "[%Mmodule_type]    FS_Write -> Return: %Mfs_error_enum, Length: %d, Duration: %u us, Throughput: %d KB/s")
   TRC_MSG(FS_API_FS_SEEK_S,    "[%Mmodule_type]    FS_Seek <- FileHandle: 0x%X, Offset: %d, Whence: %MFS_SEEK_POS_ENUM")
   TRC_MSG(FS_API_FS_SEEK_E,    "[%Mmodule_type]    FS_Seek -> Return: %d, Duration: %d us")
   TRC_MSG(FS_API_FS_SEEKLARGEFILE_S,    "[%Mmodule_type]    FS_SeekLargeFile <- FileHandle: 0x%X, Offset: 0x%X (%d), Whence: %MFS_SEEK_POS_ENUM")
   TRC_MSG(FS_API_FS_SEEKLARGEFILE_E,    "[%Mmodule_type]    FS_SeekLargeFile -> Return: %d")
   TRC_MSG(FS_API_FS_COMMIT_S,  "[%Mmodule_type]    FS_Commit <- File(SFN): %c%c%c%c%c%c%c%c.%c%c%c, Dev: %MFS_DEVICE_TYPE_ENUM, FileHandle: 0x%X")
   TRC_MSG(FS_API_FS_COMMIT_E,  "[%Mmodule_type]    FS_Commit -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_GETFILESIZE_S, "[%Mmodule_type]    FS_GetFileSize <- FileHandle: 0x%X")
   TRC_MSG(FS_API_FS_GETFILESIZE_E, "[%Mmodule_type]    FS_GetFileSize -> Return (Size): %u")
   TRC_MSG(FS_API_FS_DELETEEX_S,    "[%Mmodule_type] FS_DeleteEx <-")
   TRC_MSG(FS_API_FS_DELETEEX_E,    "[%Mmodule_type] FS_DeleteEx -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_DELETE_S,      "[%Mmodule_type]    FS_Delete <-")
   TRC_MSG(FS_API_FS_DELETE_E,      "[%Mmodule_type]    FS_Delete -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_CREATEDIR_S,   "[%Mmodule_type] FS_CreateDir <-")
   TRC_MSG(FS_API_FS_CREATEDIR_E,   "[%Mmodule_type] FS_CreateDir -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_GETCLUSTERSIZE_S,  "[%Mmodule_type]    FS_GetClusterSize <- Drive Index: %d")
   TRC_MSG(FS_API_FS_GETCLUSTERSIZE_E,  "[%Mmodule_type]    FS_GetClusterSize -> Return (Size): %d")
   TRC_MSG(FS_API_FS_SHUTDOWN_S,        "[%Mmodule_type]    FS_ShutDown")
   TRC_MSG(FS_API_FS_CLEARDISKFLAG_S,   "[%Mmodule_type]    FS_ClearDiskFlag")
   TRC_MSG(FS_API_FS_UNLOCKALL_S,       "[%Mmodule_type]    FS_UnlockAll")
   TRC_MSG(FS_API_FS_GETDISKINFO_S,     "[%Mmodule_type] FS_GetDiskInfo <- DriveName: %c, Flag: 0x%X")
   TRC_MSG(FS_API_FS_GETDISKINFO_E,     "[%Mmodule_type] FS_GetDiskInfo -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_GETDISKINFO_E_DEV, "[%Mmodule_type] FS_GetDiskInfo -> Return: %Mfs_error_enum, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_API_FS_OPENHINT_S,        "[%Mmodule_type] FS_OpenHint <- Caller: 0x%X, Flag: 0x%X, FileName:")
   TRC_MSG(FS_API_FS_OPENHINT_S_HINT,   "[%Mmodule_type] FS_OpenHint <- Caller: 0x%X, Flag: 0x%X, Cluster: %d, Index: %d, FileName:")
   TRC_MSG(FS_API_FS_OPENHINT_E,        "[%Mmodule_type] FS_OpenHint -> Return: 0x%X")
   TRC_MSG(FS_API_FS_FINDFIRST_S,       "[%Mmodule_type] FS_FindFirst <- Caller: 0x%X, Attr: 0x%X, AttrMask: 0x%X, MaxLength: %d")
   TRC_MSG(FS_API_FS_FINDFIRST_E,       "[%Mmodule_type] FS_FindFirst -> FileHandle: 0x%X")
   TRC_MSG(FS_API_FS_FINDFIRST_E_INFO,  "[%Mmodule_type] FS_FindFirst -> FileHandle: 0x%X, Attr: 0x%X, Reserved: 0x%X")
   TRC_MSG(FS_API_FS_FINDNEXT_S,        "[%Mmodule_type] FS_FindNext <- FileHandle: 0x%X, MaxLength: %d")
   TRC_MSG(FS_API_FS_FINDNEXT_E,        "[%Mmodule_type] FS_FindNext ->")
   TRC_MSG(FS_API_FS_FINDNEXT_E_INFO,   "[%Mmodule_type] FS_FindNext -> Attr: 0x%X, Reserved: 0x%X")
   TRC_MSG(FS_API_FS_FINDCLOSE_S,       "[%Mmodule_type] FS_FindClose <- FileHandle: 0x%X")
   TRC_MSG(FS_API_FS_GETDEVSTATUS_S_DRIVE,  "[%Mmodule_type] FS_GetDevStatus <- Target: %c, Type: %MFS_GET_DEV_STATUS_ENUM")
   TRC_MSG(FS_API_FS_GETDEVSTATUS_S_TYPE,   "[%Mmodule_type] FS_GetDevStatus <- Target: %d, Type: %MFS_GET_DEV_STATUS_ENUM")
   TRC_MSG(FS_API_FS_GETDEVSTATUS_E,        "[%Mmodule_type] FS_GetDevStatus -> Result: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_XDELETEEX_S,       "[%Mmodule_type] FS_XDeleteEx <- Flag: 0x%X, FolderName:")
   TRC_MSG(FS_API_FS_XDELETEEX_E,       "[%Mmodule_type] FS_XDeleteEx -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_GETDRIVE_S,        "[%Mmodule_type] FS_GetDrive <- Type: 0x%X, Serial: %d, AltMask: 0x%X")
   TRC_MSG(FS_API_FS_GETDRIVE_E,        "[%Mmodule_type] FS_GetDrive -> Return: %c")
   TRC_MSG(FS_API_FS_GETFILEPOSITION_S, "[%Mmodule_type]    FS_GetFilePosition <- FileHandle: 0x%X")
   TRC_MSG(FS_API_FS_GETFILEPOSITION_E, "[%Mmodule_type]    FS_GetFilePosition -> Position: %d")
   TRC_MSG(FS_API_FS_GETATTRIBUTES_S,   "[%Mmodule_type] FS_GetAttributes <-")
   TRC_MSG(FS_API_FS_GETATTRIBUTES_E,   "[%Mmodule_type] FS_GetAttributes -> Attr: 0x%X")
   TRC_MSG(FS_API_FS_GETFILEINFO_S,     "[%Mmodule_type] FS_GetFileInfo <- FileHandle: 0x%X, FileInfo: 0x%X")
   TRC_MSG(FS_API_FS_GETFILEINFO_E,     "[%Mmodule_type] FS_GetFileInfo ->")
   TRC_MSG(FS_API_FS_GETDEVTYPE_S,      "[%Mmodule_type] FS_GetDevType <-")
   TRC_MSG(FS_API_FS_GETDEVTYPE_E,      "[%Mmodule_type] FS_GetDevType -> Type: %d")
   TRC_MSG(FS_API_FS_SETSEEKHINT_S,     "[%Mmodule_type]    FS_SetSeekHint <- FileHandle: 0x%X, HintNum: %d")
   TRC_MSG(FS_API_FS_SETSEEKHINT_E,     "[%Mmodule_type]    FS_SetSeekHint -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_SETSEEKHINTEX_S,   "[%Mmodule_type]    FS_SetSeekHintEx <- FileHandle: 0x%X, HintCount: %d, Flag: 0x%X, Buffer: 0x%X")
   TRC_MSG(FS_API_FS_SETSEEKHINTEX_E,   "[%Mmodule_type]    FS_SetSeekHintEx -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_ENABLESMARTSEEK_S, "[%Mmodule_type] FS_EnableSmartSeek <- Option: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_TRUNCATE_S,        "[%Mmodule_type]    FS_Truncate <- FileHandle: 0x%X")
   TRC_MSG(FS_API_FS_TRUNCATE_E,        "[%Mmodule_type]    FS_Truncate ->")
   TRC_MSG(FS_API_FS_RENAME_S_OLDNAME,  "[%Mmodule_type] FS_Rename <- Old Name:")
   TRC_MSG(FS_API_FS_RENAME_S_NEWNAME,  "[%Mmodule_type] FS_Rename <- New Name:")
   TRC_MSG(FS_API_FS_RENAME_E,          "[%Mmodule_type] FS_Rename -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_IOCTRL_S,          "[%Mmodule_type] FS_IOCtrl <- DriveName: %c, Action: %d")
   TRC_MSG(FS_API_FS_IOCTRL_E,          "[%Mmodule_type] FS_IOCtrl <- Result: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_COMPACTDIR_S,      "[%Mmodule_type] FS_CompactDir <- Flags: %d, DirName:")
   TRC_MSG(FS_API_FS_COMPACTDIR_E,      "[%Mmodule_type] FS_CompactDir -> Result: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_CLOSEALL_S,        "[%Mmodule_type] FS_CloseAll <-")
   TRC_MSG(FS_API_FS_CLOSEALL_E,        "[%Mmodule_type] FS_CloseAll ->")
   TRC_MSG(FS_API_FS_RELEASEFH_S_TASKID,    "[%Mmodule_type] FS_ReleaseFH <- TaskID: 0x%X")
   TRC_MSG(FS_API_FS_RELEASEFH_S_ALLTASK,   "[%Mmodule_type] FS_ReleaseFH <- TaskID: ALL")
   TRC_MSG(FS_API_FS_RELEASEFH_E,           "[%Mmodule_type] FS_ReleaseFH -> Return: 0")
   TRC_MSG(FS_API_FS_ABORT_S,           "[%Mmodule_type]    FS_Abort <- ActionHandle: 0x%X")
   TRC_MSG(FS_API_FS_ABORT_E,           "[%Mmodule_type]    FS_Abort -> Return: 0")
   TRC_MSG(FS_API_FS_PARSEFH_S,         "[%Mmodule_type]    FS_ParseFH <- FileHandle: 0x%X")
   TRC_MSG(FS_API_FS_PARSEFH_E,         "[%Mmodule_type]    FS_ParseFH -> Return: %d")
   TRC_MSG(FS_API_FS_SETFILETIME_S,     "[%Mmodule_type]    FS_SetFileTime <- FileHandle: 0x%X, Time: 0x%X")
   TRC_MSG(FS_API_FS_SETFILETIME_E,     "[%Mmodule_type]    FS_SetFileTime -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_PSEUDOMERGE_S_FILE1,   "[%Mmodule_type] FS_PseudoMerge <- File1:")
   TRC_MSG(FS_API_FS_PSEUDOMERGE_S_FILE2,   "[%Mmodule_type] FS_PseudoMerge <- File2:")
   TRC_MSG(FS_API_FS_PSEUDOMERGE_E,         "[%Mmodule_type] FS_PseudoMerge -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_CHECKFILE_S,       "[%Mmodule_type] FS_CheckFile <- FileName:")
   TRC_MSG(FS_API_FS_CHECKFILE_E,       "[%Mmodule_type] FS_CheckFile -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_GETCURRENTDIR_S,   "[%Mmodule_type] FS_GetCurrentDir <- MaxLength: %d")
   TRC_MSG(FS_API_FS_GETCURRENTDIR_E,   "[%Mmodule_type] FS_GetCurrentDir -> Return: %Mfs_error_enum, CurrDir:")
   TRC_MSG(FS_API_FS_GETCURRENTDIRBYDRIVE_S,   "[%Mmodule_type] FS_GetCurrentDirByDrive <- Drive: %c, MaxLength: %d")
   TRC_MSG(FS_API_FS_GETCURRENTDIRBYDRIVE_E,   "[%Mmodule_type] FS_GetCurrentDirByDrive -> Return: %Mfs_error_enum, CurrDir:")
   TRC_MSG(FS_API_FS_SETCURRENTDIR_S,   "[%Mmodule_type] FS_SetCurrentDir <- DirName:")
   TRC_MSG(FS_API_FS_SETCURRENTDIR_E,   "[%Mmodule_type] FS_SetCurrentDir -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_EXTEND_S,          "[%Mmodule_type]    FS_Extend <- FileHandle: 0x%X, Length: %d")
   TRC_MSG(FS_API_FS_EXTEND_E,          "[%Mmodule_type]    FS_Extend -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_MAKEFILENAME_S,    "[%Mmodule_type]    FS_MakeFileName <- FileHandle: 0x%X, Flag: %d, MaxLength: %d")
   TRC_MSG(FS_API_FS_MAKEFILENAME_E,    "[%Mmodule_type]    FS_MakeFileName -> Return: %d, FileName:")
   TRC_MSG(FS_API_FS_FINDFIRSTN_S,      "[%Mmodule_type] FS_FindFirstN <- Caller: 0x%X, PatternNum: %d, MaxLength: %d, EntryIndex: %d, Flag: 0x%X, Pattern:")
   TRC_MSG(FS_API_FS_FINDFIRSTN_E,      "[%Mmodule_type] FS_FindFirstN -> Return: 0x%X, FileName:")
   TRC_MSG(FS_API_FS_FINDFIRSTN_E_HINT, "[%Mmodule_type] FS_FindFirstN -> Attr: %X, Cluster: %d, Index: %d, FileName:")
   TRC_MSG(FS_API_FS_FINDNEXTN_S,       "[%Mmodule_type] FS_FindNextN <- FileHandle: 0x%X, PatternNum: %d, MaxLength: %d, Flag: 0x%X")
   TRC_MSG(FS_API_FS_FINDNEXTN_E,       "[%Mmodule_type] FS_FindNextN -> Attr: 0x%X, FileName:")
   TRC_MSG(FS_API_FS_FINDNEXTN_E_HINT,  "[%Mmodule_type] FS_FindNextN -> Attr: 0x%X, Cluster: %d, Index: %d, FileName:")
   TRC_MSG(FS_API_FS_XFINDRESET_S,      "[%Mmodule_type] FS_XFindReset <- PatternNum: %d, Flag: 0x%X, Pattern:")
   TRC_MSG(FS_API_FS_XFINDRESET_E,      "[%Mmodule_type] FS_XFindReset -> Count: %d")
   TRC_MSG(FS_API_FS_XFINDSTART_S,      "[%Mmodule_type] FS_XFindStart <- Index: %d, MaxLength: %d, Flag: 0x%X, Pattern:")
   TRC_MSG(FS_API_FS_XFINDSTART_E_INFO, "[%Mmodule_type] FS_XFindStart -> Attr: 0x%X, FileName:")
   TRC_MSG(FS_API_FS_XFINDSTART_E,      "[%Mmodule_type] FS_XFindStart -> FileName:")
   TRC_MSG(FS_API_FS_XFINDCLOSE_S,      "[%Mmodule_type] FS_XFindClose <- Position: 0x%X")
   TRC_MSG(FS_API_FS_XFINDCLOSE_E,      "[%Mmodule_type] FS_XFindClose -> Return: 0")
   TRC_MSG(FS_API_FS_GETPARTITIONINFO_S,"[%Mmodule_type] FS_GetPartitionInfo <- DriveName: %c, PartitionInfo: 0x%X")
   TRC_MSG(FS_API_FS_GETPARTITIONINFO_E,"[%Mmodule_type] FS_GetPartitionInfo -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_COMMITALL_S,       "[%Mmodule_type] FS_CommitAll <- DriveName: %c")
   TRC_MSG(FS_API_FS_COMMITALL_E,       "[%Mmodule_type] FS_CommitAll -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_MAPPINGDRIVE_S,    "[%Mmodule_type] FS_MappingDrive <- Old Drive: %c, New Drive: %c")
   TRC_MSG(FS_API_FS_MAPPINGDRIVE_E,    "[%Mmodule_type] FS_MappingDrive <- Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_GENERALFORMAT_S,   "[%Mmodule_type] FS_GeneralFormat <- Caller: 0x%X, DriveName: %c, Level: 0x%X")
   TRC_MSG(FS_API_FS_GENERALFORMAT_E,   "[%Mmodule_type] FS_GeneralFormat <- Return: %d")
   TRC_MSG(FS_API_FS_QMGETFREE_S,       "[%Mmodule_type] FS_QmGetFree <- Path:")
   TRC_MSG(FS_API_FS_QMGETFREE_E,       "[%Mmodule_type] FS_QmGetFree -> Return: %d")
   TRC_MSG(FS_API_FS_CHECKDISKFLAG_S,   "[%Mmodule_type] FS_CheckDiskFlag <-")
   TRC_MSG(FS_API_FS_CHECKDISKFLAG_E,   "[%Mmodule_type] FS_CheckDiskFlag ->")
   TRC_MSG(FS_API_FS_LOCKFAT_S,         "[%Mmodule_type] FS_LockFAT <-")
   TRC_MSG(FS_API_FS_LOCKFAT_E,         "[%Mmodule_type] FS_LockFAT -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_TESTMSDC_S,            "[%Mmodule_type] FS_TestMSDC <- SlotID: 0x%X")
   TRC_MSG(FS_API_FS_TESTMSDC_S_DRIVELIST,  "[%Mmodule_type] FS_TestMSDC <- SlotID: 0x%X, DriveList: 0x%X, DriveNum: %d")
   TRC_MSG(FS_API_FS_TESTMSDC_E,            "[%Mmodule_type] FS_TestMSDC -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_TESTMSDC_E_DRIVELIST,  "[%Mmodule_type] FS_TestMSDC -> Return, %Mfs_error_enum, DriveNum: %d")
   TRC_MSG(FS_API_FS_CLOSEMSDC_S,           "[%Mmodule_type] FS_CloseMSDC <- DriveLetter: %c, Mode: 0x%X")
   TRC_MSG(FS_API_FS_CLOSEMSDC_E,           "[%Mmodule_type] FS_CloseMSDC -> Result: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_SWITCHDRIVEMODE_S,     "[%Mmodule_type] FS_SwitchDriveMode <- DriveLetter: %c, Mode: 0x%X")
   TRC_MSG(FS_API_FS_SWITCHDRIVEMODE_E,     "[%Mmodule_type] FS_SwitchDriveMode -> Result: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_GENVIRTUALFILENAME_S,  "[%Mmodule_type]    FS_GenVirtualFileName <- FileHandle: 0x%X, VFBeginOffset: %d, VFValidLength: %d, BufLength: %d")
   TRC_MSG(FS_API_FS_GENVIRTUALFILENAME_E,  "[%Mmodule_type]    FS_GenVirtualFileName -> Result: %Mfs_error_enum, VFileName:")
   TRC_MSG(FS_API_FS_CONFIGEXTDEVICE_S,     "[%Mmodule_type] FS_ConfigExtDevice <- Action: 0x%X, DrvFuncs: %X, Slots: %d")
   TRC_MSG(FS_API_FS_CONFIGEXTDEVICE_E,     "[%Mmodule_type] FS_ConfigExtDevice -> Result: %Mfs_error_enum, VFileName:")
   TRC_MSG(FS_API_FS_CHECKDRIVE_S,      "[%Mmodule_type] FS_CheckDrive <- DriveLetter: %c, CheckBuffer: 0x%X, BufferSize: %d")
   TRC_MSG(FS_API_FS_CHECKDRIVE_E,      "[%Mmodule_type] FS_CheckDrive -> Result: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_SETDIRCACHE_S,     "[%Mmodule_type]    FS_SetDirCache <- FileHandle: 0x%X, NewValue: 0x%X")
   TRC_MSG(FS_API_FS_SETDIRCACHE_E,     "[%Mmodule_type]    FS_SetDirCache -> Result: 0")
   TRC_MSG(FS_API_FS_GETDIRCACHE_S,     "[%Mmodule_type]    FS_GetDirCache <- FileHandle: 0x%X")
   TRC_MSG(FS_API_FS_GETDIRCACHE_E,     "[%Mmodule_type]    FS_GetDirCache -> Result: %Mfs_error_enum, Value: 0x%X")
   TRC_MSG(FS_API_FS_EXPIREDIRCACHE_S,  "[%Mmodule_type]    FS_ExpireDirCache <- FileHandle: 0x%X")
   TRC_MSG(FS_API_FS_EXPIREDIRCACHE_E,  "[%Mmodule_type]    FS_ExpireDirCache -> Return: 0")
   TRC_MSG(FS_API_FS_GETFOLDERSIZE_S,   "[%Mmodule_type] FS_GetFolderSize <- Flag: 0x%X, RecStack: 0x%X, StackSize: %d, Path:")
   TRC_MSG(FS_API_FS_GETFOLDERSIZE_E,   "[%Mmodule_type] FS_GetFolderSize -> Return: %d")
   TRC_MSG(FS_API_FS_MOVE_S_SRCFILE,    "[%Mmodule_type] FS_Move <- Caller: 0x%X, Src File:")
   TRC_MSG(FS_API_FS_MOVE_S_DSTFILE,    "[%Mmodule_type] FS_Move <- Dst File:")
   TRC_MSG(FS_API_FS_MOVE_E,            "[%Mmodule_type] FS_Move -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_GETFIRSTCLUSTER_S, "[%Mmodule_type]    FS_GetFirstCluster <- FileHandle: 0x%X")
   TRC_MSG(FS_API_FS_GETFIRSTCLUSTER_E, "[%Mmodule_type]    FS_GetFirstCluster -> Return: %d, Cluster: %d")
   TRC_MSG(FS_API_FS_OTPREAD_S,         "[%Mmodule_type] FS_OTPRead <- DevType: 0x%X, Offset: %u, BufferPtr: 0x%X, Length: %u")
   TRC_MSG(FS_API_FS_OTPREAD_E,         "[%Mmodule_type] FS_OTPRead -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_OTPWRITE_S,        "[%Mmodule_type] FS_OTPWrite <- DevType: 0x%X, Offset: %u, BufferPtr: 0x%X, Length: %u")
   TRC_MSG(FS_API_FS_OTPWRITE_E,        "[%Mmodule_type] FS_OTPWrite -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_OTPLOCK_S,         "[%Mmodule_type] FS_OTPLock <- DevType: 0x%X")
   TRC_MSG(FS_API_FS_OTPLOCK_E,         "[%Mmodule_type] FS_OTPLock -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_OTPQUERYLENGTH_S,  "[%Mmodule_type] FS_OTPQueryLength <- DevType: 0x%X")
   TRC_MSG(FS_API_FS_OTPQUERYLENGTH_E,  "[%Mmodule_type] FS_OTPQueryLength -> Return: %Mfs_error_enum, Length: %d")
   TRC_MSG(FS_API_FS_SWEEPDEVICE_S,     "[%Mmodule_type] FS_SweepDevice <- DevType: 0x%X")
   TRC_MSG(FS_API_FS_SWEEPDEVICE_E_DONE,    "[%Mmodule_type] FS_SweepDevice -> Return: 0 (Done)")
   TRC_MSG(FS_API_FS_SWEEPDEVICE_E_RETRY,   "[%Mmodule_type] FS_SweepDevice -> Return: -41 (FS_CHECKDISK_RETRY)")
   TRC_MSG(FS_API_FS_COUNTUSEDFH_S,         "[%Mmodule_type] FS_CountUsedFH <- Flag: %d")
   TRC_MSG(FS_API_FS_COUNTUSEDFH_E,         "[%Mmodule_type] FS_CountUsedFH -> Return: %d, Length: %d")
   TRC_MSG(FS_API_FS_GETDEVPARTITIONS_S_DRIVE,  "[%Mmodule_type] FS_GetDevPartitions <- DriveLetter: %c")
   TRC_MSG(FS_API_FS_GETDEVPARTITIONS_S_TYPE,   "[%Mmodule_type] FS_GetDevPartitions <- DeviceType: %d, Type: %MFS_GET_DEV_STATUS_ENUM")
   TRC_MSG(FS_API_FS_GETDEVPARTITIONS_E,        "[%Mmodule_type] FS_GetDevPartitions -> Result: %d")
   TRC_MSG(FS_API_FS_RECOVERDEVICE_S,   "[%Mmodule_type] FS_RecoverDevice <- DeviceType: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_API_FS_RECOVERDEVICE_E,   "[%Mmodule_type] FS_RecoverDevice -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_SETVOLUMELABEL_S,  "[%Mmodule_type] FS_SetVolumeLabel <- DriveLetter: %c, Label:")
   TRC_MSG(FS_API_FS_SETVOLUMELABEL_E,  "[%Mmodule_type] FS_SetVolumeLabel -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_REMOVEDIR_S,       "[%Mmodule_type] FS_RemoveDir <- DirName:")
   TRC_MSG(FS_API_FS_REMOVEDIR_E,       "[%Mmodule_type] FS_RemoveDir -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_SETATTRIBUTES_S,   "[%Mmodule_type] FS_SetAttributes <- Attr: 0x%X, FileName:")
   TRC_MSG(FS_API_FS_SETATTRIBUTES_E,   "[%Mmodule_type] FS_SetAttributes -> Return: %Mfs_error_enum")
   TRC_MSG(FS_API_FS_COUNT_S,           "[%Mmodule_type] FS_Count <- Flag: 0x%X, RecStack: 0x%X, StackSize: %u, FullPath:")
   TRC_MSG(FS_API_FS_COUNT_E,           "[%Mmodule_type] FS_Count -> Return: %d")
   TRC_MSG(FS_API_FS_MAKEFILEPATHBYHINT_S,  "[%Mmodule_type] FS_MakeFilePathByHint <- DriveLetter: %c, DirCluster: %u, DirIndex: %u, MaxLength: %d")
   TRC_MSG(FS_API_FS_MAKEFILEPATHBYHINT_E,  "[%Mmodule_type] FS_MakeFilePathByHint -> Result: %Mfs_error_enum, FileName:")
   TRC_MSG(FS_API_FS_OPENFILEPATHBYHINT_S,  "[%Mmodule_type] FS_OpenFileByHint <- Caller: 0x%X, DriveLetter: %c, DirCluster: %u, DirIndex: %u, Flags: 0x%X")
   TRC_MSG(FS_API_FS_OPENFILEPATHBYHINT_E,  "[%Mmodule_type] FS_OpenFileByHint -> FileHandle: 0x%X")
   TRC_MSG(FS_API_FS_DELETEBYHINT_S,        "[%Mmodule_type] FS_DeleteByHint <- DriveLetter: %c, DirCluster: %u, DirIndex: %u")
   TRC_MSG(FS_API_FS_DELETEBYHINT_E,        "[%Mmodule_type] FS_DeleteByHint -> FileHandle: 0x%X")
   TRC_MSG(FS_API_FS_GETATTRIBUTESBYHINT_S, "[%Mmodule_type] FS_GetAttributesByHint <- DriveLetter: %c, DirCluster: %u, DirIndex: %u")
   TRC_MSG(FS_API_FS_GETATTRIBUTESBYHINT_E, "[%Mmodule_type] FS_GetAttributesByHint -> Attr: 0x%X")
   TRC_MSG(FS_API_FS_SETATTRIBUTESBYHINT_S, "[%Mmodule_type] FS_SetAttributesByHint <- DriveLetter: %c, DirCluster: %u, DirIndex: %u, Attr: 0x%X")
   TRC_MSG(FS_API_FS_SETATTRIBUTESBYHINT_E, "[%Mmodule_type] FS_SetAttributesByHint -> Attr: 0x%X")
   TRC_MSG(FS_API_FS_HINTGETPARENT_S,       "[%Mmodule_type] FS_HintGetParent <- DriveLetter: %c, DirCluster: %u, DirIndex: %u")
   TRC_MSG(FS_API_FS_HINTGETPARENT_E,       "[%Mmodule_type] FS_HintGetParent -> Return: %d, ParentCluster: %u, ParentCluster: %u")
   TRC_MSG(FS_API_FS_DUMPFHTABLE_S,         "[%Mmodule_type] FS_DumpFHTable <-")
   TRC_MSG(FS_API_FS_DUMPFHTABLE_E,         "[%Mmodule_type] FS_DumpFHTable ->")
   TRC_MSG(FS_API_FS_DIRCTRL_E,         "[%Mmodule_type]    FS_DirCtrl -> Handle: 0x%X, Action: %Mfs_dirctrl_action_enum, Data: %u")
   TRC_MSG(FS_API_FS_CHECKFILENAME_E,   "[%Mmodule_type] FS_CheckFileName -> Path: ")
   TRC_MSG(FS_API_FS_CHECKVOLUMELABEL_E,    "[%Mmodule_type] FS_CheckVolumeLabel -> Label: ")

    TRC_MSG(FS_API_FS_ASYNC_OPEN_S,     "[%Mmodule_type] fs_async_open <- Priority: %Mfs_prioity_enum, Flag: 0x%X, FileName:")
    TRC_MSG(FS_API_FS_ASYNC_OPEN_E,     "[%Mmodule_type] fs_async_open -> Return: %d")
    TRC_MSG(FS_API_FS_ASYNC_READ_S,     "[%Mmodule_type]    fs_async_read <- File(SFN): %c%c%c%c%c%c%c%c.%c%c%c, Dev: %MFS_DEVICE_TYPE_ENUM Priority: %Mfs_prioity_enum, FileHandle: 0x%X, DataPtr: 0x%X, Length: %u")
    TRC_MSG(FS_API_FS_ASYNC_READ_E,     "[%Mmodule_type]    fs_async_read -> Return: %d")
    TRC_MSG(FS_API_FS_ASYNC_WRITE_S,    "[%Mmodule_type]    fs_async_write <- File(SFN): %c%c%c%c%c%c%c%c.%c%c%c, Dev: %MFS_DEVICE_TYPE_ENUM, Priority: %Mfs_prioity_enum, FileHandle: 0x%X, DataPtr: 0x%X, Length: %d")
    TRC_MSG(FS_API_FS_ASYNC_WRITE_E,    "[%Mmodule_type]    fs_async_write -> Return: %d")
    TRC_MSG(FS_API_FS_ASYNC_SEEK_S,     "[%Mmodule_type]    fs_async_seek <- Priority: %Mfs_prioity_enum, FileHandle: 0x%X, Offset: %d, Whence: %MFS_SEEK_POS_ENUM")
    TRC_MSG(FS_API_FS_ASYNC_SEEK_E,     "[%Mmodule_type]    fs_async_seek -> Return: %d")
    TRC_MSG(FS_API_FS_ASYNC_DELETE_S,   "[%Mmodule_type] fs_async_delete <- Priority: %Mfs_prioity_enum, FileName: ")
    TRC_MSG(FS_API_FS_ASYNC_DELETE_E,   "[%Mmodule_type] fs_async_delete -> Return: %d")
    TRC_MSG(FS_API_FS_ASYNC_FINDFIRST_S,    "[%Mmodule_type] fs_async_find_first <- Priority: %Mfs_prioity_enum, Attr: 0x%X, AttrMask: 0x%X, MaxLength: %d")
    TRC_MSG(FS_API_FS_ASYNC_FINDFIRST_E,    "[%Mmodule_type] fs_async_find_first -> Return: %d")
    TRC_MSG(FS_API_FS_ASYNC_FINDFIRSTN_S,   "[%Mmodule_type] fs_async_find_first_n <- Priority: %Mfs_prioity_enum, MaxLength: %d, EntryIndex: %d, Flag: 0x%X, Pattern:")
    TRC_MSG(FS_API_FS_ASYNC_FINDFIRSTN_E,   "[%Mmodule_type] fs_async_find_first_n -> Return: %d")
    TRC_MSG(FS_API_FS_ASYNC_GETFOLDERSIZE_S,    "[%Mmodule_type] fs_async_get_folder_size <- Priority: %Mfs_prioity_enum, Flag: 0x%X, RecStack: 0x%X, StackSize: %d, Path:")
    TRC_MSG(FS_API_FS_ASYNC_GETFOLDERSIZE_E,    "[%Mmodule_type] fs_async_get_folder_size -> Return: 0")
    TRC_MSG(FS_API_FS_ASYNC_ABORT_S,            "[%Mmodule_type] fs_async_abort <- JobID: %d")


    TRC_MSG(FS_API_FS_ASYNC_JOB_REGISTER,         "[%Mmodule_type] [AsynJob] fs_async_int_register_job: <Register>: JobID: %d, JobPtr: 0x%X, State: %Mfs_job_state_enum, FS_API: %Mfs_api_enum")
    TRC_MSG(FS_API_FS_ASYNC_JOB_DISPATCH_START,   "[%Mmodule_type] [AsynJob] fs_job_dipatch: <Start>: JobID: %d, JobPtr: 0x%X, State: %Mfs_job_state_enum, FS_API: %Mfs_api_enum")
    TRC_MSG(FS_API_FS_ASYNC_JOB_DISPATCH_FINISH,  "[%Mmodule_type] [AsynJob] fs_job_dipatch: <Finished>: JobID: %d, JobPtr: 0x%X, State: %Mfs_job_state_enum, FS_API: %Mfs_api_enum")
    TRC_MSG(FS_API_FS_ASYNC_JOB_DISPATCH_ABORT,   "[%Mmodule_type] [AsynJob] fs_job_dipatch: <Aborted>: JobID: %d, JobPtr: 0x%X, State: %Mfs_job_state_enum, FS_API: %Mfs_api_enum")
    TRC_MSG(FS_API_FS_ASYNC_JOB_INSERT_S,         "[%Mmodule_type] [AsynJob] fs_job_insert <- JobID: %d, JobPtr: 0x%X")
    TRC_MSG(FS_API_FS_ASYNC_JOB_INSERT_E,         "[%Mmodule_type] [AsynJob] fs_job_insert -> ")
    TRC_MSG(FS_API_FS_ASYNC_JOB_REMOVE_S,         "[%Mmodule_type] [AsynJob] fs_job_remove <- JobID: %d")
    TRC_MSG(FS_API_FS_ASYNC_JOB_REMOVE_E,         "[%Mmodule_type] [AsynJob] fs_job_remove -> JobPtr: 0x%X")
    TRC_MSG(FS_API_FS_ASYNC_JOB_GET_FIRST_S,      "[%Mmodule_type] [AsynJob] fs_job_get_first <- Option: %d")
    TRC_MSG(FS_API_FS_ASYNC_JOB_GET_FIRST_E,      "[%Mmodule_type] [AsynJob] fs_job_get_first -> JobPtr: 0x%X")
    TRC_MSG(FS_API_FS_ASYNC_JOB_RUNNING_JOB,      "[%Mmodule_type] [AsynJob] Current Running JobID: %d, JobPtr: 0x%X")
    TRC_MSG(FS_API_FS_ASYNC_JOB_LIST_ENTRY,       "[%Mmodule_type] [AsynJob] ListEntry, JobID: %d, JobPtr: 0x%X -> ")
    TRC_MSG(FS_API_FS_ASYNC_JOB_RESPONSE_ILM,     "[%Mmodule_type] [AsynJob] fs_job_response: <ILM>: JobID: %d, JobPtr: 0x%X, State: %Mfs_job_state_enum, FS_API: %Mfs_api_enum")
    TRC_MSG(FS_API_FS_ASYNC_JOB_RESPONSE_CBF,     "[%Mmodule_type] [AsynJob] fs_job_response: <CBF>: JobID: %d, JobPtr: 0x%X, State: %Mfs_job_state_enum, FS_API: %Mfs_api_enum")
    TRC_MSG(FS_API_FS_ASYNC_JOB_LIST_ERROR_JOBPTR_RUNNING, "[%Mmodule_type] [AsynJob] Error: illegal user buffer, JobPtr 0x%X is already running")
    TRC_MSG(FS_API_FS_ASYNC_JOB_LIST_ERROR_JOBPTR_EXIST,   "[%Mmodule_type] [AsynJob] Error: illegal user buffer, JobPtr 0x%X is already existed in the job list")
    TRC_MSG(FS_API_FS_ASYNC_JOB_LIST_ERROR_ENDLESS_LINK,   "[%Mmodule_type] [AsynJob] Error: endless job links")
    TRC_MSG(FS_API_FS_ASYNC_JOB_ERROR_UNEXPECTED_STATE, "[%Mmodule_type] [AsynJob] Error: fs_job_abort()- Unexpected job state %Mfs_job_state_enum, JobID: %d, JobPtr: 0x%X")
    TRC_MSG(FS_API_FS_ASYNC_JOB_ERROR_UNKNOW_API,       "[%Mmodule_type] [AsynJob] Error: fs_job_dipatch()- Unkown API %d (%Mfs_api_enum), JobID: %d, JobPtr: 0x%X")

/*
 * Statistics API
 */
    TRC_MSG(FS_API_FS_STARTIOLOG_S, "[%Mmodule_type] FS_StartIOLog <- TaskIOStatistics: 0x%X ")
    TRC_MSG(FS_API_FS_STARTIOLOG_E, "[%Mmodule_type] FS_StartIOLog -> Return: %Mfs_error_enum ")
    TRC_MSG(FS_API_FS_ENDIOLOG_S,   "[%Mmodule_type] FS_EndIOLog <- TaskIOStatistics: 0x%X ")
    TRC_MSG(FS_API_FS_ENDIOLOG_E,   "[%Mmodule_type] FS_EndIOLog -> Return: %Mfs_error_enum ")

/*
 * Common API
 */
    TRC_MSG(FS_TRC_FS_LISTOPEN_S,       "[%Mmodule_type] FS_ListOpen <- Caller: 0x%X, Param: 0x%x, Path:")
    TRC_MSG(FS_TRC_FS_LISTOPEN_E,       "[%Mmodule_type] FS_ListOpen -> Result: %Mfs_error_enum, FileHandle: 0x%x")
    TRC_MSG(FS_TRC_FS_LISTNEXT_S,       "[%Mmodule_type] FS_ListNext <- Handle: 0x%x, Index: %d")
    TRC_MSG(FS_TRC_FS_LISTNEXT_E,       "[%Mmodule_type] FS_ListNext -> Result: %Mfs_error_enum, FileName: ")
    TRC_MSG(FS_TRC_FS_LISTCLOSE_S,      "[%Mmodule_type] FS_ListClose <- Handle: 0x%x")

    /* Info */
    TRC_MSG(FS_TRC_FS_LISTOPEN_FILL,    "[%Mmodule_type] ________ pos_buf[%d] = (%d, %d)")

/*
 * FS insight
 */
    /* Dir Cache (TRACE_FUNC) */
    TRC_MSG(FS_TRC_DIRCACHE_SET,        "[%Mmodule_type] DirData(S): Index: %d, Drive: 0x%x, Cluster: %d, Value: 0x%x")
    TRC_MSG(FS_TRC_DIRCACHE_GET,        "[%Mmodule_type] DirData(G): Index: %d, Drive: 0x%x, Cluster: %d, Value: 0x%x")

    /* Dir Cache (Level 6) */
    TRC_MSG(FS_TRC_DIRCACHE_EXPIRE,     "[%Mmodule_type] DirData(E): Index: %d, Drive: 0x%x, Cluster: %d, Value: 0x%x")

    /* Level 7 */
    /* +Info */
    TRC_MSG(FS_TRC_RTF_OPEN_FILE_HINT,  "[%Mmodule_type] RTFOpenFile: Internal Hint:%Mkal_bool")


    /* Level 8 */
    TRC_MSG(FS_TRC_RTF_FIRST_S,         "[%Mmodule_type] RTFFindFirst <- PatternNum: %d, MaxLength: %d, EntryIndex: %d, Flag: 0x%X, Pattern:")
    TRC_MSG(FS_TRC_RTF_NEXT,            "[%Mmodule_type] RTFFindNext")
    /* +Info */
    TRC_MSG(FS_TRC_RTF_NEXT_DIR,        "[%Mmodule_type] ________ Cluster = %d, Index = %d, EntryType = %MEntryType")
    TRC_MSG(FS_TRC_RTF_NEXT_E,          "[%Mmodule_type] ________  Attr: 0x%X, FileName:")
    TRC_MSG(FS_TRC_RTF_NEXT_E_HINT,     "[%Mmodule_type] ________ Cluster: %d, Index: %d, Attr: %X, FileName:")

    /* Level 9 */
    TRC_MSG(FS_TRC_RTF_GETNAMEBYPOS,    "[%Mmodule_type] GetNameByPos: MaxLength =%d, Pos<-(Cluster, Index) = (%d, %d)")
    TRC_MSG(FS_TRC_RTF_SEARCHFILE,      "[%Mmodule_type] SearchFile: Result = %Mrtf_search_ret_enum, line = %d")

    /* Level 10 */
    TRC_MSG(FS_TRC_RTF_GETBUFFER,       "[%Mmodule_type] GetBuffer: Sector = %d")
    TRC_MSG(FS_TRC_RTF_GETCLUSTERVALUE, "[%Mmodule_type] GetClusterValue: Next Culster = %d")
    TRC_MSG(FS_TRC_RTF_NEXTDIR,         "[%Mmodule_type] NextDir")
    TRC_MSG(FS_TRC_RTF_GETDIR,          "[%Mmodule_type] GetDir: Sector = %d")
    TRC_MSG(FS_TRC_RTF_INCDIR,          "[%Mmodule_type] IncDir: Culster:%d, Index:%d")

   /* FS Errors */
   TRC_MSG(FS_API_FS_ERR,       "[%Mmodule_type] %Mfs_error_enum # %Mfs_src_file_enum, line: %d")
   TRC_MSG(FS_API_FS_ERR_FILE,  "[%Mmodule_type] %Mfs_error_enum # %Mfs_src_file_enum, line: %d, FileName(SFN): %c%c%c%c%c%c%c%c.%c%c%c, Dev: %MFS_DEVICE_TYPE_ENUM")

   /* FS Errors with Infomation*/
   TRC_MSG(FS_TRC_ERR_VF_PARENT_CLOSED, "[%Mmodule_type]    FS_Open: Virtual file's parent may be closed before!")
   TRC_MSG(FS_ERR_DRIVER_NOT_FOUND,     "[%Mmodule_type]    Driver function is NOT FOUND!")
   TRC_MSG(FS_ERR_MESSAGEACK_NOT_FOUND, "[%Mmodule_type]    MessageAck is required in driver!")
   TRC_MSG(FS_ERR_FS_MOVE_DELETE_FILE_ERROR,    "[%Mmodule_type]    Error happens when deleting file after FS_Move is failed! Target FileName:")
   TRC_MSG(FS_ERR_QMAX_OVER_DISK,       "[%Mmodule_type]    Quota Configuration Error! Qmax exceeds disk space! Disk Total Space: %u, Qmax: %u (Unit: Cluster)")
   TRC_MSG(FS_ERR_QMIN_OVER_DISK,       "[%Mmodule_type]    Quota Configuration Error! Quota MRS (Minimum Required Space) exceeds total disk space! Disk Total Space: %u, MRS: %u (Unit: Cluster)")
   TRC_MSG(FS_ERR_QRFS_OVER_DFS,        "[%Mmodule_type]    Quota Run-time Warning! Quota RFS (Required Free Space) exceeds total disk free space! Disk Free Space: %u, RFS: %u (Unit: Cluster)")
   TRC_MSG(FS_ERR_ACCESS_DENIED,        "[%Mmodule_type]    Access Denied! The file is already opened by Task: %c%c%c, LR: 0x%x, FileHandle: 0x%x")
   TRC_MSG(FS_ERR_NULL_PTR_1,           "[%Mmodule_type]    %Mfs_src_file_enum, line: %u, NULL NamePtr! Could not find 0x005c!")
   TRC_MSG(FS_ERR_REC_TRAV_START,       "[%Mmodule_type]    Recursive Engine Error! RecTravStart Error!")
   TRC_MSG(FS_ERR_REC_TRAV_CORE,        "[%Mmodule_type]    Recursive Engine Error! RecTravCore Error!")
   TRC_MSG(FS_ERR_REC_TRAV_ACTION,      "[%Mmodule_type]    Recursive Engine Error! RecTravAction Error!")
   TRC_MSG(FS_ERR_MEDIA_NOT_PRESENT,    "[%Mmodule_type]    Media is not present! Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_MOUNTDEVICE_DRIVER_MOUNT_FAIL,    "[%Mmodule_type]    MountDevice: Disk driver \"MountDevice\" is failed! Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_MOUNTDEVICE_INVALID_SECTOR_SIZE,  "[%Mmodule_type]    MountDevice: Invalid sector size! Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_MOUNTDEVICE_MSDC_NOT_PRESENT,     "[%Mmodule_type]    MountDevice: MSDC card is not present!")
   TRC_MSG(FS_ERR_READSECTORS_DEVICE_ERROR,         "[%Mmodule_type]    ReadSectors: Device ERROR! Sector: %u, Sectors: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_READSECTORS_DEV_NOT_READY,        "[%Mmodule_type]    ReadSectors: Device is NOT ready! Sector: %u, Sectors: %u, MountState: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_READSECTORS_OUT_OF_RANGE,         "[%Mmodule_type]    ReadSectors: Out of range! Sector: %u, Sectors: %u, Geometry: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_READSECTORS_DRIVER_FAIL,          "[%Mmodule_type]    ReadSectors: Driver read failed! Sector: %u, Sectors: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_WRITESECTORS_DEVICE_ERROR,        "[%Mmodule_type]    WriteSectors: Device ERROR! Sector: %u, Sectors: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_WRITESECTORS_DEV_NOT_READY,       "[%Mmodule_type]    WriteSectors: Device is NOT ready! Sector: %u, Sectors: %u, MountState: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_WRITESECTORS_OUT_OF_RANGE,        "[%Mmodule_type]    WriteSectors: Out of range! Sector: %u, Sectors: %u, Geometry: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_WRITESECTORS_NO_PROTECTION_MODE,  "[%Mmodule_type]    WriteSectors: Driver does not support RecoverableWrite, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_WRITESECTORS_BAD_SECTOR,          "[%Mmodule_type]    WriteSectors: Bad sector encountered! Sector: %u, Sectors: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_WRITESECTORS_DRIVER_FAIL,         "[%Mmodule_type]    WriteSectors: Driver write failed! Sector: %u, Sectors: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_WRITESECTORS_SYSTEM_CRASH,        "[%Mmodule_type]    WriteSectors: Bad sector found in FAT table region! Severe Damage! Sector: %u, Sectors: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_GETBUFFER_OUT_OF_BUFFERS,         "[%Mmodule_type]    GetBuffer: Out of buffer! Sector: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_LOCKDEVICE_DEVICE_BUSY,           "[%Mmodule_type]    LockDevice: Device is busy! Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_NONBLOCKLOCKDEVICE_DEVICE_BUSY,   "[%Mmodule_type]    NonBlockLockDevice: Device is busy! Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_NONBLOCKLOCKDEVICE_LOCK_DEV_FAIL, "[%Mmodule_type]    NonBlockLockDevice: Lock device failed! Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_NONBLOCKLOCKDEVICE_LOCK_RTF_FAIL, "[%Mmodule_type]    NonBlockLockDevice: Lock native FS failed! Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_PARSEFH_OUT_OF_RANGE,             "[%Mmodule_type]    ParseFileHandle: File Index: %d, FS_MAX_FILES: %u")
   TRC_MSG(FS_ERR_PARSEFH_UNLOCKED,                 "[%Mmodule_type]    ParseFileHandle: File (index: %d) is unlocked! It may be closed by others before!")
   TRC_MSG(FS_ERR_PARSEFH_UNIQUE_NOT_MATCHED,       "[%Mmodule_type]    ParseFileHandle: Unique is not matched. This file may be closed by others before! (File index: %d)")
   TRC_MSG(FS_ERR_PARSEFH_NULL_DEV,                 "[%Mmodule_type]    ParseFileHandle: NULL device! This file may be closed or freed before! (File index: %d)")
   TRC_MSG(FS_ERR_PARSEFH_INVALID_AFTER_DEV_LOCKED, "[%Mmodule_type]    ParseFileHandle: File (index: %d) is invalid after dev is locked! It may be closed by others just now!")
   TRC_MSG(FS_ERR_PARSEFH_EXPORTED,                 "[%Mmodule_type]    ParseFileHandle: Device is exported! This file will be closed automatically! (File index: %d)")
   TRC_MSG(FS_ERR_PARSEFH_MEDIA_CHANGED,            "[%Mmodule_type]    ParseFileHandle: Device is changed! This file will be closed automatically! (File index: %d)")
   TRC_MSG(FS_ERR_NBPARSEFH_OUT_OF_RANGE,               "[%Mmodule_type]    ParseFileHandle_NB: File Index: %d, FS_MAX_FILES: %u")
   TRC_MSG(FS_ERR_NBPARSEFH_UNLOCKED,                   "[%Mmodule_type]    ParseFileHandle_NB: File (index: %d) is unlocked! It may be closed by others before!")
   TRC_MSG(FS_ERR_NBPARSEFH_UNIQUE_NOT_MATCHED,         "[%Mmodule_type]    ParseFileHandle_NB: Unique is not matched. This file may be closed by others before! (File index: %d)")
   TRC_MSG(FS_ERR_NBPARSEFH_NULL_DEV,                   "[%Mmodule_type]    ParseFileHandle_NB: NULL device! This file may be closed or freed before! (File index: %d)")
   TRC_MSG(FS_ERR_NBPARSEFH_INVALID_AFTER_DEV_LOCKED,   "[%Mmodule_type]    ParseFileHandle_NB: File (index: %d) is invalid after dev is locked! It may be closed by others just now!")
   TRC_MSG(FS_ERR_NBPARSEFH_EXPORTED,                   "[%Mmodule_type]    ParseFileHandle_NB: Device is exported! This file will be closed automatically! (File index: %d)")
   TRC_MSG(FS_ERR_NBPARSEFH_MEDIA_CHANGED,              "[%Mmodule_type]    ParseFileHandle_NB: Device is changed! This file will be closed automatically! (File index: %d)")
   TRC_MSG(FS_ERR_MOUNTDRIVE_DEV_MOUNT_FAIL,        "[%Mmodule_type]    MountLogicalDrive: Device mount failed! Dev: %MFS_DEVICE_TYPE_ENUM, MountState(Dev): %MMountStates")
   TRC_MSG(FS_ERR_MOUNTDRIVE_DRV_MOUNT_FAIL,        "[%Mmodule_type]    MountLogicalDrive: Mount partition failed! Dev: %MFS_DEVICE_TYPE_ENUM, MountState(Drive): %MMountStates")
   TRC_MSG(FS_ERR_MOUNTDRIVE_INVALID_FS_SIG,        "[%Mmodule_type]    MountLogicalDrive: Invalid signature in PBR! Signature: 0x%X, NearJmp: 0x%X, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_MOUNTDRIVE_INVALID_FS_SEC,        "[%Mmodule_type]    MountLogicalDrive: Invalid PBR's BytesPerSector! BytesPerSector: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_MOUNTDRIVE_INVALID_FS_SPC,        "[%Mmodule_type]    MountLogicalDrive: Invalid PBR's SectorsPerCluster! SectorsPerCluster: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_MOUNTDRIVE_INVALID_FS_FAT_TYPE,   "[%Mmodule_type]    MountLogicalDrive: We can't choose a suitable FAT type for this drive! Cluster: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_MOUNTDRIVE_INVALID_FS_FAT32_VER,  "[%Mmodule_type]    MountLogicalDrive: FAT32's version should be 0! Ver: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_MOUNTDRIVE_INVALID_FS_RESERVED_SEC,   "[%Mmodule_type]    MountLogicalDrive: ReservedSectors should NOT be 0! Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_MOUNTDRIVE_INVALID_FS_FAT_CNT,    "[%Mmodule_type]    MountLogicalDrive: Invalid number of FAT tables! Count %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_MOUNTDRIVE_INVALID_FS_FAT_SIZE,   "[%Mmodule_type]    MountLogicalDrive: FAT size should NOT be 0! Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_MOUNTDRIVE_INVALID_FS_ZERO_SPC,   "[%Mmodule_type]    MountLogicalDrive: SectorsPerCluster should NOT be 0! Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_MOUNTDRIVE_TOO_MANY_LOGI_SEC,     "[%Mmodule_type]    MountLogicalDrive: Too many logical sectors! Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_MOUNTDRIVE_MEDIA_CHANGED,         "[%Mmodule_type]    MountLogicalDrive: Device may be changed! Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_SCANPTABLE_MBR_SIG,           "[%Mmodule_type]    ScanPartitionTable: Invalid signature in MBR! Signature: 0x%X, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_SCANPTABLE_BOOT_INDICATOR,    "[%Mmodule_type]    ScanPartitionTable: Invalid boot indicator in MBR! BootIndicator: 0x%X, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_SCANPTABLE_EXT_MBR_SIG,       "[%Mmodule_type]    ScanPartitionTable: Invalid signature in extended MBR! Signature: 0x%X, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_SCANPTABLE_RELATIVE_SECTOR,   "[%Mmodule_type]    ScanPartitionTable: Invalid relative sector MBR! RelativeSector: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_LOCATEDRIVE_DRVIDX_OUT_OF_RANGE,  "[%Mmodule_type]    LocateDrive: Drive index out of range! DriveIndex: %u")
   TRC_MSG(FS_ERR_LOCATEDRIVE_EXPORTED,             "[%Mmodule_type]    LocateDrive: Device is exported! Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_LOCATEDRIVE_MEDIA_CHANGED,        "[%Mmodule_type]    LocateDrive: Device may be changed! Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_GETCLUSTERVALUE_INVALID_IN_CLUSTER,   "[%Mmodule_type]    GetClusterValue: Invalid input cluster index! !Index: %u")
   TRC_MSG(FS_ERR_GETCLUSTERVALUE_INVALID_OUT_CLUSTER,  "[%Mmodule_type]    GetClusterValue: Invalid output cluster value! Index: %u, !Value: %u (0x%x), FATSector: %u")
   TRC_MSG(FS_ERR_SETCLUSTERVALUE_INVALID_IN_CLUSTER,   "[%Mmodule_type]    SetClusterValue: Invalid cluster index! !Index: %u")
   TRC_MSG(FS_ERR_SETCLUSTERVALUE_INVALID_OUT_CLUSTER,  "[%Mmodule_type]    SetClusterValue: Invalid cluster value! Index: %u, !Value: %u")
   TRC_MSG(FS_ERR_ALLOCFATSEGPERMIT_DISK_FULL,  "[%Mmodule_type]    AllocateFATSegmentPermit: Disk full! Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_ALLOCFATSEGPERMIT_APP_QERR,   "[%Mmodule_type]    AllocateFATSegmentPermit: APP quota full! Qidx: %u")
   TRC_MSG(FS_ERR_ALLOCFATSEG_DISK_FULL,        "[%Mmodule_type]    AllocateFATSegment: Disk full after traverse all FAT! Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_MOVEFILEPTR_WRAP_AROUND,          "[%Mmodule_type]    MoveFilePointer: File pointer wraps around! FilePointer: %u, Offset: %u")
   TRC_MSG(FS_ERR_MOVEFILEPTR_BEYOND_LAST_CLUSTER,  "[%Mmodule_type]    MoveFilePointer: Move beyond the last cluster! f<-Cluster: %u")
   TRC_MSG(FS_ERR_STARTDIRSEARCH_BEYOND_LAST_CLUSTER,   "[%Mmodule_type]    StartDirSearch: Invalid dir entry! Cluster: %u, Index: %u, Dev: %MFS_DEVICE_TYPE_ENUM")
   TRC_MSG(FS_ERR_RTFRENAME_DRIVE_NOT_THE_SAME,     "[%Mmodule_type]    RTFRename: 2 files should be on the same drive!")
   TRC_MSG(FS_ERR_RTFREAD_FPTR_OUT_OF_RANGE,        "[%Mmodule_type]    RTFRead: File pointer is out of range! FilePointer: %u, FileSize: %u")
   TRC_MSG(FS_ERR_RTFREAD_FPTR_WRAP_AROUND,         "[%Mmodule_type]    RTFRead: File pointer will be wrapped around! FilePointer: %u, Read Length: %u")
   TRC_MSG(FS_ERR_RTFREAD_MUST_READ_SECTOR_ALIGNED, "[%Mmodule_type]    RTFRead: Physical or Volume file should be read sector-aligned length! Length: %u")
   TRC_MSG(FS_ERR_RTFREAD_INVALID_FMAPED_HANDLE,    "[%Mmodule_type]    RTFRead: Invalid mapped file handle (Virtual file)! Handle: 0x%X")
   TRC_MSG(FS_ERR_RTFWRITE_FPTR_OUT_OF_RANGE,       "[%Mmodule_type]    RTFWrite: File pointer is out of range! FilePointer: %u, FileSize: %u")
   TRC_MSG(FS_ERR_RTFWRITE_FPTR_WRAP_AROUND,        "[%Mmodule_type]    RTFWrite: File pointer will be wrapped around! FilePointer: %u, Write Length: %u")
   TRC_MSG(FS_ERR_RTFWRITE_MUST_READ_SECTOR_ALIGNED,"[%Mmodule_type]    RTFWrite: Physical or Volume file should be written sector-aligned length! Length: %u")
   TRC_MSG(FS_ERR_RTFWRITE_INVALID_FMAPED_HANDLE,   "[%Mmodule_type]    RTFWrite: Invalid mapped file handle (Virtual file)! Handle: 0x%X")
   TRC_MSG(FS_ERR_RTFTRUNCATE_NORMAL_FILE_ONLY,     "[%Mmodule_type]    RTFTruncate: Only normal file could be truncated!")
   TRC_MSG(FS_ERR_RTFTRUNCATE_FPTR_OUT_OF_RANGE,    "[%Mmodule_type]    RTFTruncate: File pointer is out of range! FilePointer: %u, FileSize: %u")
   TRC_MSG(FS_ERR_RTFSEEK_FPTR_OUT_OF_RANGE,        "[%Mmodule_type]    RTFSeek: File pointer is out of range! FilePointer: %u, FileSize: %u")
   TRC_MSG(FS_ERR_RTFSEEK_INVALID_WHENCE,           "[%Mmodule_type]    RTFSeek: Invalid Whence! Whence: %u")
   TRC_MSG(FS_ERR_RTFSEEK_FPTR_WRAP_AROUND,         "[%Mmodule_type]    RTFSeek: New position is wrapped around! StartPos: %u, Offset: %d, NewPos: %u")
   TRC_MSG(FS_ERR_RTFSEEK_MUST_READ_SECTOR_ALIGNED, "[%Mmodule_type]    RTFSeek: Physical or Volume file should be seeked to sector-aligned position! StartPos: %u, Offset: %d, NewPos: %u")
   TRC_MSG(FS_ERR_RTFSEEK_INVALID_FMAPED_HANDLE,    "[%Mmodule_type]    RTFSeek: Invalid mapped file handle (Virtual file)! Handle: 0x%X")
   TRC_MSG(FS_ERR_RTFSEEK_CANT_EXTEND_READ_ONLY_FILE,   "[%Mmodule_type]    RTFSeek: Can't extend Read Only file! NewPos: %u, FileSize: %u")
   TRC_MSG(FS_ERR_RTFSEEK_CANT_EXTEND_ROOT_DIR,     "[%Mmodule_type]    RTFSeek: Can't extend Root Dir! NewPos: %u, FileSize: %u")
   TRC_MSG(FS_ERR_RTFSEEK_INVALID_CLUSTER,          "[%Mmodule_type]    RTFSeek: Invalid cluster number found! Cluster: %u")
   TRC_MSG(FS_ERR_RTFEXTEND_FPTR_OUT_OF_RANGE,      "[%Mmodule_type]    RTFExtend: File pointer is out of range! FilePointer: %u, FileSize: %u")
   TRC_MSG(FS_ERR_RTFEXTEND_FSIZE_WRAP_AROUND,      "[%Mmodule_type]    RTFExtend: File size is wrapped around! FilePointer: %u, Length: %u")
   TRC_MSG(FS_ERR_RTFRESETDISK_FILE_NOT_CLOSED,     "[%Mmodule_type]    RTFResetDisk: All file should be closed! FileCount: %u")
   TRC_MSG(FS_ERR_COPYSECTORS_DEV_ERROR,            "[%Mmodule_type]    CopySectors: Device error! From: %u, To: %u, Sectors: %u")
   TRC_MSG(FS_ERR_COPYSECTORS_DEV_NOT_MOUNTED,      "[%Mmodule_type]    CopySectors: Device is not mounted! From: %u, To: %u, Sectors: %u")
   TRC_MSG(FS_ERR_COPYSECTORS_DRIVER_FAILED,        "[%Mmodule_type]    CopySectors: Driver failed! From: %u, To: %u, Sectors: %u")
   TRC_MSG(FS_ERR_FILENAME_INVALID_CHAR,            "[%Mmodule_type]    Invalid character in file name: 0x%X")
   TRC_MSG(FS_ERR_FILENAME_INVALID_LEADING_BLANK,   "[%Mmodule_type]    Leading blank in file name is not allowed!")
   TRC_MSG(FS_ERR_FILENAME_INVALID_TAILING_DOT,     "[%Mmodule_type]    Tailing dot in file name is not allowed!")
   TRC_MSG(FS_ERR_VOLUMELABEL_TOO_LONG,             "[%Mmodule_type]    Volume label is too long! The maximum length is 11!")
   TRC_MSG(FS_ERR_DIRENTRY_INVALID_START_CLUSTER,   "[%Mmodule_type]    CheckDirEntry: The start cluster value %u (0x%x) is invalid, MaxCluster %d (0x%x)")

   /* FS Information */
   TRC_MSG(FS_INFO_FT_TITLE,    "[FS INFO] ====== File Table ======")
   TRC_MSG(FS_INFO_FT_SLOT,     "[FS INFO] FileTable[%d] = FileHandle: 0x%X, Task: %c%c%c, OwnerLR: 0x%x, Lock: %d, Valid: %Mfs_fh_status, ShortName(SFN):%c%c%c%c%c%c%c%c.%c%c%c")
   TRC_MSG(FS_INFO_FT_LFN,      "[FS INFO] ___________ FileName (Mouse Right Click -> Display Unicode String) ")
   TRC_MSG(FS_INFO_FT_TAIL,     "[FS INFO] === End of File Table ===")
   TRC_MSG(FS_INFO_DIR_ENTRY_WALKED,            "[%Mmodule_type]       %d directory entries were walked!")
   TRC_MSG(FS_INFO_COPY_FILE_BUFFER_SIZE,       "[%Mmodule_type]       Copy file buffer size: %d bytes")
   TRC_MSG(FS_INFO_QUOTA_DELETE,                "[%Mmodule_type]       QM: Delete - %d, Free: %d (FATDelete)")
   TRC_MSG(FS_INFO_QUOTA_STATUS_NOW_FATDELETE,  "[%Mmodule_type]       QM: Status - Qidx: %u, Qnow: %u (FATDelete)")
   TRC_MSG(FS_INFO_QUOTA_STATUS_NOW_ALLOCFATSEG,"[%Mmodule_type]       QM: Status - Qidx: %u, Qnow: %u (AllocateFATSegment)")
   TRC_MSG(FS_INFO_QUOTA_STATUS_NOW_RTFEXTEND,  "[%Mmodule_type]       QM: Status - Qidx: %u, Qnow: %u (RTFExtend)")
   TRC_MSG(FS_INFO_QUOTA_BEFORE_ALLOC,          "[%Mmodule_type]       QM: Before allocate %u, Free: %u")

   TRC_MSG(FS_INFO_LFN,          "[FS] FileName (Mouse Right Click -> Display Unicode String) ")
   TRC_MSG(FS_INFO_LFN_ERR,      "[FS ERR] FileName (Mouse Right Click -> Display Unicode String) ")

   TRC_MSG(FS_INFO_FAT_SECTOR,   "[FS INFO] FAT Sector Buffer")
   TRC_MSG(FS_INFO_DIR_ENTRY,    "[FS INFO] Directory Entry")
   TRC_MSG(FS_INFO_DISK_ERROR,   "[%Mmodule_type] The disk has errors, please run check disk (chkdsk.exe /f) from PC")
   TRC_MSG(FS_INFO_DISK_ERROR2,  "[%Mmodule_type] Thd disk %c: has errors, please run check disk (chkdsk.exe /f) from PC")

   TRC_MSG(FS_INFO_TOP_FH_USER_TITLE, "[FS INFO] ========= Top File Handle Consumers =========")
   TRC_MSG(FS_INFO_TOP_FH_USER,       "[FS INFO] %u. Task: %c%c%c, LR: 0x%x, number of opened file handles: %u")
   TRC_MSG(FS_INFO_TOP_FH_USER_TAIL,  "[FS INFO] ===== End of Top File Handle Consumers ======")

   TRC_MSG(FS_INFO_IO_STAT_START, "[FS INFO] ============= Start of File System IO Statistics ============")
   TRC_MSG(FS_INFO_IO_STAT_TITLE, "[FS INFO] ================= File System IO Statistics =================")
   TRC_MSG(FS_INFO_IO_STAT_ENTRY, "[FS INFO] %u.<%c%c%c> IO.Count: %u, IO.Data: %u KB, IO.Time: %u ms (%u)")
   TRC_MSG(FS_INFO_IO_STAT_LINE,  "[FS INFO] -------------------------------------------------------------")
   TRC_MSG(FS_INFO_IO_STAT_TOTAL, "[FS INFO] Total.IO.Count: %u, Total.IO.Data: %u KB, Total.IO.Time: %u ms (100)")
   TRC_MSG(FS_INFO_IO_STAT_TAIL,  "[FS INFO] ============= End of File System IO Statistics ==============")
   TRC_MSG(FS_INFO_IO_STAT_DISABLE, "[FS INFO] IO Statistics is disabled, add CUSTOM_OPTION += __FS_IO_STATISTICS__ to makefile and rebuild fs.lib")

   /* FS Info Group 1 - R/W sector breakdown */
   TRC_MSG(FS_INFO_GR1_READSECTORS,   "[%Mmodule_type]       ReadSectors -> Dev: %MFS_DEVICE_TYPE_ENUM, Length: %u, Duration: %u us, Throughput: %u KB/s, Sector: %u")
   TRC_MSG(FS_INFO_GR1_WRITESECTORS,  "[%Mmodule_type]       WriteSectors -> Dev: %MFS_DEVICE_TYPE_ENUM, Length: %u, Duration: %u us, Throughput: %u KB/s, Sector: %u")

   TRC_MSG(FS_INFO_GR2_READSECTORS,   "[%Mmodule_type]       %MFS_DEVICE_TYPE_ENUM, R, %u, %u, %u")
   TRC_MSG(FS_INFO_GR2_WRITESECTORS,  "[%Mmodule_type]       %MFS_DEVICE_TYPE_ENUM, W, %u, %u, %u")

   /* FS Info Group 2 - R/W sector breakdown */
   TRC_MSG(FS_INFO_READSECTORS_S,   "[%Mmodule_type] ReadSectors <- Sector: %u,")
   TRC_MSG(FS_INFO_WRITESECTORS_S,  "[%Mmodule_type] WriteSectors <- Sector: %u,")

    /* FSAL */
    TRC_MSG(FSAL_TRACE_OPEN_ERROR,                  "[FSAL] DRM_open_file Error:%d, fsal.c/line=%d")
    TRC_MSG(FSAL_TRACE_CLOSE_ERROR,                 "[FSAL] DRM_close_file Error:%d, fsal.c/line=%d")
    TRC_MSG(FSAL_TRACE_READ_ERROR,                  "[FSAL] DRM_read_file Error:%d, fsal.c/line=%d")
    TRC_MSG(FSAL_TRACE_READ_ERROR_OUT_OF_RANGE,     "[FSAL] FSAL_Direct_Read Error: Offset out of range, fsal.c/line=%d")
    TRC_MSG(FSAL_TRACE_WRITE_ERROR,                 "[FSAL] FS_Write Error:%d, Written:%d, fsal.c/line=%d")
    TRC_MSG(FSAL_TRACE_SEEK_ERROR,                  "[FSAL] DRM_seek_large_file Error:%d, fsal.c/line=%d")
    TRC_MSG(FSAL_TRACE_SEEK_ERROR_OUT_OF_RANGE,     "[FSAL] FSAL_Direct_Seek Error:RAM offset out of range, fsal.c/line=%d")
    TRC_MSG(FSAL_TRACE_GET_FILE_POSITION_ERROR,     "[FSAL] DRM_file_pos Error:%d, fsal.c/line=%d")
    TRC_MSG(FSAL_TRACE_GET_FILE_SIZE_ERROR,         "[FSAL] DRM_file_size Error:%d, fsal.c/line=%d")
    TRC_MSG(FSAL_TRACE_BUF_READ_BLK_ERROR,          "[FSAL] fsal_read_block %d + %d > %d, fsal_buffer.c/line=%d")
    TRC_MSG(FSAL_TRACE_BUF_READ_ERROR,              "[FSAL] fsal_read_block Error:%d, fsal_buffer.c/line=%d")
    TRC_MSG(FSAL_TRACE_ERROR_FSAL_C,                "[FSAL] Error:%MFSAL_Status, fsal.c/line=%d")
    TRC_MSG(FSAL_TRACE_ERROR_FSAL_BUF_C,            "[FSAL] Error:%MFSAL_Status, fsal_buffer.c/line=%d")

/*
 * FS Iteration Profiling
 */

    TRC_MSG(FS_TEST_ITERATION_START,   "====== File System Iteration Performance Test (START) ======")
    TRC_MSG(FS_TEST_ITERATION_END,     "====== File System Iteration Performance Test (END) ======")

/*
 * FS SST
 */

    // FS Assert
    TRC_MSG(FS_SST_ASSERT_INFO1,        "File System ASSERT! File: %Mfs_src_file_enum, Line: %u.")
    TRC_MSG(FS_SST_ASSERT_INFO2,        "Information: %u, %u, %u")
    TRC_MSG(FS_SST_ASSERT_GUIDELINE,    "Guideline: Please contact File System owner!")

    TRC_MSG(FS_SST_USER_ERROR_TITLE,    "====== File System User Error Analyzer ======")
    TRC_MSG(FS_SST_INTERNAL_ERROR_TITLE,"====== File System Internal Error Analyzer ======")

    TRC_MSG(FS_SST_API_CLOSE_ALL,       "FS_CloseAll() is NOT allowed to be used under normal state!")
    TRC_MSG(FS_SST_BUFFER_02,           "AllocBuffers(): Cache buffer is not properly aligned!")
    TRC_MSG(FS_SST_HANDLE_01,           "ReserveFTSlot(): File handle is insufficient! Please see File Table below to find out the murder!")
    TRC_MSG(FS_SST_CLUSTER_01,          "GetClusterValue(): Invalid FAT type: %d!")
    TRC_MSG(FS_SST_CLUSTER_03,          "SetClusterValue(): Invalid FAT type: %d!")
    TRC_MSG(FS_SST_CLUSTER_05,          "BatchCoutnFreeClusters(): Invalid FAT type: %d!")
    TRC_MSG(FS_SST_CLUSTER_06,          "FATSearchZeroInBuffer(): Invalid FAT type: %d!")
    TRC_MSG(FS_SST_CLUSTER_08,          "ScanDrive(): Invalid FAT type: %d!")
    TRC_MSG(FS_SST_DIRENTRY_01,         "UpdateDirEntry(): An invalid file pointer is found! Please open memory dump for details.")
    TRC_MSG(FS_SST_EXCEPTION_04,        "_XRaiseException(): Unhandled exception is detected! It may because an exception is raised in XFINALLY section!")
    TRC_MSG(FS_SST_TLS_02,              "RTFSYSSetTLS/RTFSYSGetTaskIndex(): FS_MAX_THREAD (%d) is insufficient! Please enlarge it in fs_config.c!")
    TRC_MSG(FS_SST_MUTEX_01,            "RTFSYSAllocMutex(): The number of FS mutexes exceeds the limit (%d)!")
    TRC_MSG(FS_SST_TOO_MANY_OPENED_FILES, "There were too many opened files, please check the file handles are properly closed after use")


END_TRACE_MAP(MOD_FS)
#endif /* __FS_CARD_DOWNLOAD__ */
#endif // _FS_TRC_H
