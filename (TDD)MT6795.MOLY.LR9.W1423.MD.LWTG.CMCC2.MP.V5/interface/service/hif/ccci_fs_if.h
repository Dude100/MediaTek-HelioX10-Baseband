/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   ccci_fs_if.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Interface of CCCI_FS service.
 *
 * Author:
 * -------
 * -------
 *
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * 	CCCI_FS compact read and profile trace (sdio)
 *
 * removed!
 * removed!
 * 	CCCI_FS compact read and profile trace
 *
 * removed!
 * removed!
 * a. Check-in cccifs new features (support 16KB I/O)
 * b. add __CCCIFS_SUPPORT__ option to related files
 ****************************************************************************/
#ifndef __CCCI_FS_IF_H__
#define __CCCI_FS_IF_H__

#include "fs_type.h"
#include "nvram_defs.h"
/*******************************************************************************
 * File System op code
 *******************************************************************************/
typedef enum
{
    FS_CCCI_OP_OPEN = 0x1001,
    FS_CCCI_OP_SEEK,  //0x1002
    FS_CCCI_OP_READ,    //0x1003
    FS_CCCI_OP_WRITE, //0x1004
    FS_CCCI_OP_CLOSE, //0x1005
    FS_CCCI_OP_CLOSEALL, //0x1006
    FS_CCCI_OP_CREATEDIR, //0x1007
    FS_CCCI_OP_REMOVEDIR, //0x1008
    FS_CCCI_OP_GETFILESIZE, //0x1009
    FS_CCCI_OP_GETFOLDERSIZE, //0x100a
    FS_CCCI_OP_RENAME,  //0x100b
    FS_CCCI_OP_MOVE,    //0x100c
    FS_CCCI_OP_COUNT,   //0x100d
    FS_CCCI_OP_GETDISKINFO, //0x100e
    FS_CCCI_OP_DELETE, //0x100f
    FS_CCCI_OP_GETATTRIBUTES, //0x1010
    FS_CCCI_OP_OPENHINT, //0x1011
    FS_CCCI_OP_FINDFIRST, //0x1012
    FS_CCCI_OP_FINDNEXT, //0x1013
    FS_CCCI_OP_FINDCLOSE, //0x1014
    FS_CCCI_OP_LOCKFAT, //0x1015
    FS_CCCI_OP_UNLOCKALL, //0x1016
    FS_CCCI_OP_SHUTDOWN,//0x1017
    FS_CCCI_OP_XDELETE, //0x1018
    FS_CCCI_OP_CLEARDISKFLAG, //0x1019
    FS_CCCI_OP_GETDRIVE, //0x101a
    FS_CCCI_OP_GETCLUSTERSIZE, //0x101b
    FS_CCCI_OP_SETDISKFLAG, //0x101c
    FS_CCCI_OP_OTPWRITE, //0x101d
    FS_CCCI_OP_OTPREAD, //0x101e
    FS_CCCI_OP_OTPQUERYLENGTH, //0x101f
    FS_CCCI_OP_OTPLOCK,   //0x1020
    FS_CCCI_OP_RESTORE = 0x1021,
    FS_CCCI_OP_CMPTREAD = 0x1022
} FS_CCCI_OP_ID_T;

/*******************************************************************************
 * Declare function prototype.
 *******************************************************************************/

// General I/O
kal_int32 MD_FS_Open(const WCHAR * FileName, kal_uint32 Flag);
kal_int32 MD_FS_OpenHint(const WCHAR * FileName, kal_uint32 Flag, FS_FileOpenHint * DSR_Hint);
kal_int32 MD_FS_Close(FS_HANDLE FileHandle);
kal_int32 MD_FS_Read(FS_HANDLE FileHandle, void * DataPtr, kal_uint32 Length, kal_uint32 * Read);
kal_int32 MD_FS_Write(FS_HANDLE FileHandle, void * DataPtr, kal_uint32 Length, kal_uint32 * Written);
kal_int32 MD_FS_Seek(FS_HANDLE FileHandle, kal_int32 Offset, kal_int32 Whence);

//Information
kal_int32 MD_FS_GetFileSize(FS_HANDLE FileHandle, kal_uint32 * Size);

//File Only Operation
kal_int32 MD_FS_Delete(const WCHAR * FileName);

//Folder Only Operation
kal_int32 MD_FS_CreateDir(const WCHAR * DirName);

//File and Folder Operations
kal_int32 MD_FS_Move(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, kal_uint32 Flag, FS_ProgressCallback Progress, kal_uint8 *RecursiveStack, const kal_uint32 StackSize);

kal_int32 MD_FS_XDelete(const WCHAR * FullPath, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize);

//Find File
kal_int32 MD_FS_FindFirst(const WCHAR * NamePattern, kal_uint8 Attr, kal_uint8 AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength);
kal_int32 MD_FS_FindNext(FS_HANDLE FileHandle, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength);
kal_int32 MD_FS_FindClose(FS_HANDLE FileHandle);

//Drive Management
kal_int32 MD_FS_GetClusterSize(kal_uint32 DriveIdx);

//Power Lost Detection and Recovery
kal_int32 MD_FS_SetDiskFlag(void);

//kal_int32 MD_FS_CheckDiskFlag(void);
kal_int32 MD_FS_ClearDiskFlag(void);

//Disk Management
kal_int32 MD_FS_GetDiskInfo(const WCHAR * DriveName, FS_DiskInfo * DiskInfo, kal_int32 Flags);

//Card management

//File System Run-Time LifeCycle
void MD_FS_ShutDown(void);
kal_int32 MD_FS_UnlockAll(void);
kal_int32 MD_FS_LockFAT(kal_uint32 Type);

//File System Run-Time Debug

//DirCache

//Flash Device Direct IO
kal_int32 MD_FS_OTPWrite(kal_int32 devtype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
kal_int32 MD_FS_OTPRead(kal_int32 devtype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
kal_int32 MD_FS_OTPQueryLength(kal_int32 devtype, kal_uint32 *Length);
kal_int32 MD_FS_OTPLock(kal_int32 devtype);

kal_int32 MD_FS_Restore(const WCHAR * FileName, void* pBuffer, kal_uint32 Length);
kal_int32 MD_FS_GetAttributes(const WCHAR * FileName);

kal_int32 MD_FS_CMPT_Read(const WCHAR * FileName, NVRAM_FS_PARAM_CMPT_T *nvram_param);

#endif  /* !__CCCI_FS_IF_H__ */
