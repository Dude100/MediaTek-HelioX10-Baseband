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

/*******************************************************************************
 * Filename:
 * ---------
 *   ccci_fs_it.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements the CCCI FS Integration Test functions
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [CCCI FS] Support CCCI FS exception mode.
 *
 * removed!
 * removed!
 * [CCCI FS] Support CCCI FS exception mode.
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * Fix CCCIFS memory cpy offset issues
 *
 * removed!
 * removed!
 * a. Check-in cccifs new features (support 16KB I/O)
 * b. add __CCCIFS_SUPPORT__ option to related files
 *
 * removed!
 * removed!
 * MT6290 Rename CCCI Services
 *
 * removed!
 * removed!
 * sync latest version of new features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#if defined (__CCCI_FS_IT__)
/*  KAL service header  */
#include "kal_public_api.h" //for INLINE
#include "syscomp_config.h"
/*  FS service header  */
#include "fs_gprot.h"
/*  CCCI_FS header  */
#include "ccci_fs_debug.h"
#include "ccci_fs.h"

/*NVRAM*/
#include "nvram_defs.h"

static kal_uint32 cccifsit_trigger;
#define TEST_RUN 100
#define CCCI_FS_IT_FFFN_TEST   //FindFirst, FindNext test
//#define CCCI_FS_IT_SUPPORT_OTP // test OTP, only support [_otp] in ap project name

extern kal_int32 MD_FS_GetDiskInfo(const WCHAR *DriveName, FS_DiskInfo *DiskInfo, kal_int32 Flags);
extern kal_int32 MD_FS_CreateDir(const WCHAR * DirName);
extern kal_int32 MD_FS_RemoveDir(const WCHAR * DirName);
extern kal_int32 MD_FS_GetFolderSize(const WCHAR *DirName, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize);
extern void MD_FS_ShutDown(void);
extern kal_int32 MD_FS_CloseAll(void);
extern kal_int32 MD_FS_Open(const WCHAR * FileName, kal_uint32 Flag);
extern kal_int32 MD_FS_OpenHint(const WCHAR * FileName, kal_uint32 Flag, FS_FileOpenHint * DSR_Hint);
extern kal_int32 MD_FS_Close(FS_HANDLE FileHandle);
extern kal_int32 MD_FS_Write(FS_HANDLE FileHandle, void *DataPtr, kal_uint32 Length, kal_uint32 *Written);
extern kal_int32 MD_FS_Read(FS_HANDLE FileHandle, void *DataPtr, kal_uint32 Length, kal_uint32 *Read);
extern kal_int32 MD_FS_XDelete(const WCHAR * FullPath, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize);
extern kal_int32 MD_FS_Seek(FS_HANDLE FileHandle, kal_int32 Offset, kal_int32 Whence);
extern kal_int32 MD_FS_LockFAT(kal_uint32 Type);
extern kal_int32 MD_FS_UnlockAll(void);
extern kal_int32 MD_FS_SetDiskFlag(void);
extern kal_int32 MD_FS_ClearDiskFlag(void);
extern kal_int32 MD_FS_GetClusterSize(kal_uint32 DriveIdx);
extern kal_int32 MD_FS_GetDrive(kal_uint32 Type, kal_uint32 Serial, kal_uint32 AltMask);
extern kal_int32 MD_FS_OTPQueryLength(kal_int32 devtype, kal_uint32 *Length);
extern kal_int32 MD_FS_OTPLock(kal_int32 devtype);
extern kal_int32 MD_FS_OTPWrite(kal_int32 devtype, kal_uint32 Offset, void *BufferPtr, kal_uint32 Length);
extern kal_int32 MD_FS_OTPRead(kal_int32 devtype, kal_uint32 Offset, void *BufferPtr, kal_uint32 Length);
extern kal_int32 MD_FS_FindFirst(const WCHAR * NamePattern, kal_uint8 Attr, kal_uint8 AttrMask, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength);
extern kal_int32 MD_FS_FindNext(FS_HANDLE FileHandle, FS_DOSDirEntry * FileInfo, WCHAR * FileName, kal_uint32 MaxLength);
extern kal_int32 MD_FS_FindClose(FS_HANDLE FileHandle);
extern kal_int32 MD_FS_GetFileSize(FS_HANDLE FileHandle, kal_uint32 *Size);
extern kal_int32 MD_FS_GetFolderSize(const WCHAR *DirName, kal_uint32 Flag, kal_uint8 *RecursiveStack, const kal_uint32 StackSize);
extern kal_int32 MD_FS_GetAttributes(const WCHAR * FileName);
extern kal_int32 MD_FS_Count(const WCHAR * FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize);
extern kal_int32 MD_FS_Rename(const WCHAR * FileName, const WCHAR * NewName);
extern kal_int32 MD_FS_Move(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, kal_uint32 Flag, FS_ProgressCallback Progress, kal_uint8 *RecursiveStack, const kal_uint32 StackSize);
extern kal_int32 MD_FS_Delete(const WCHAR *FileName);
extern kal_int32 MD_FS_CMPT_Read(const WCHAR * FileName, NVRAM_FS_PARAM_CMPT_T* nvram_param);


//#define DSP_IMG_PATH_TEST
#if defined(DSP_IMG_PATH_TEST)
#define CCCI_FS_IT_DRIVE        "Y:\\"
#define CCCI_FS_IT_FOLDER_DMY   "Y:\\CCCI_FS_IT_dummy"
#define CCCI_FS_IT_FOLDER       "Y:\\CCCI_FS_IT"
#define CCCI_FS_IT_FILE_A       "Y:\\CCCI_FS_IT\\cccifsit_a"
#define CCCI_FS_IT_FILE_B       "Y:\\CCCI_FS_IT\\cccifsit_b"
#define CCCI_FS_IT_FILE_B_RE    "Y:\\CCCI_FS_IT\\cccifsit_b_rename"
#define CCCI_FS_IT_FILE_B_MV    "Y:\\CCCI_FS_IT\\LV2\\cccifsit_b"
#define CCCI_FS_IT_FILE_C       "Y:\\CCCI_FS_IT\\cccifsit_c"
#define CCCI_FS_IT_FOLDER_LV2   "Y:\\CCCI_FS_IT\\LV2"
#define CCCI_FS_IT_FILE_A_LV2   "Y:\\CCCI_FS_IT\\cccifsit_aa"
#define CCCI_FS_IT_FILE_16K     "Y:\\CCCI_FS_IT\\cccifsit_16k"
#else
#define CCCI_FS_IT_DRIVE        "Z:\\"
#define CCCI_FS_IT_FOLDER_DMY   "Z:\\CCCI_FS_IT_dummy"
#define CCCI_FS_IT_FOLDER       "Z:\\CCCI_FS_IT"
#define CCCI_FS_IT_FILE_A       "Z:\\CCCI_FS_IT\\cccifsit_a"
#define CCCI_FS_IT_FILE_B       "Z:\\CCCI_FS_IT\\cccifsit_b"
#define CCCI_FS_IT_FILE_B_RE    "Z:\\CCCI_FS_IT\\cccifsit_b_rename"
#define CCCI_FS_IT_FILE_B_MV    "Z:\\CCCI_FS_IT\\LV2\\cccifsit_b"
#define CCCI_FS_IT_FILE_C       "Z:\\CCCI_FS_IT\\cccifsit_c"
#define CCCI_FS_IT_FOLDER_LV2   "Z:\\CCCI_FS_IT\\LV2"
#define CCCI_FS_IT_FILE_A_LV2   "Z:\\CCCI_FS_IT\\cccifsit_aa"
#define CCCI_FS_IT_FILE_16K     "Z:\\CCCI_FS_IT\\cccifsit_16k"
#endif

#define CCCI_FS_IT_FILE_PREFIX "cccifsit_a"

#define CCCI_MAGIC_STR  "THIS IS WCP3_SE7_SD8::"
#define CCCI_FILE_A_CONTENT "test_a"
#define CCCI_FILE_B_CONTENT "test_b"
#define CCCI_FILE_C_CONTENT "test_c"
#define CCCI_FILE_MAX_TEST_LEN   50

#define CCCI_FS_MAX_IO_16K  (1024*16)
#define CCCI_FS_IT_MAGIC    0x55667788
#define STR_MATCH_RETURN    0
static kal_int32 ccci_fs_it_buff_16k[CCCI_FS_MAX_IO_16K+1];
static kal_int32 ccci_fs_it_buff_16k_ret[CCCI_FS_MAX_IO_16K+1];

static kal_uint32 ccci_fs_it_error_line = 0;

static kal_bool ccci_fs_it_close_all()
{
    kal_int32 fs_api_ret;

    //4 <1> MD_FS_ShutDown
    MD_FS_ShutDown();
    fs_api_ret = MD_FS_CloseAll();
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_SHUTDOWN_ERR, fs_api_ret);
        return KAL_FALSE;
    }
    return KAL_TRUE;
}


static kal_bool cccifs_it_create_dir()
{
    WCHAR FolderName[256];
    kal_int32 fs_api_ret;

    kal_wsprintf(FolderName, "%s\0", CCCI_FS_IT_FOLDER_DMY);
    //4 <1> create CCCI_FS_IT_FOLDER_DMY
    fs_api_ret = MD_FS_CreateDir(FolderName);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_CREATE_FOLDER_T1_ERR, fs_api_ret);
        return KAL_FALSE;
    }
    //4 <2> remove CCCI_FS_IT_FOLDER_DMY
    fs_api_ret = MD_FS_RemoveDir(FolderName);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_CREATE_FOLDER_T2_ERR, fs_api_ret);
        return KAL_FALSE;
    }    

    kal_wsprintf(FolderName, "%s\0", CCCI_FS_IT_FOLDER);
    //4 <3> create CCCI_FS_IT_FOLDER
    fs_api_ret = MD_FS_CreateDir(FolderName);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_CREATE_FOLDER_T3_ERR, fs_api_ret);
        return KAL_FALSE;
    }    
//    fs_api_ret = MD_FS_Close(fs_api_ret);
//    ASSERT( fs_api_ret < FS_NO_ERROR);


    kal_wsprintf(FolderName, "%s\0", CCCI_FS_IT_FOLDER_LV2);
    //4 <3> create CCCI_FS_IT_FOLDER
    fs_api_ret = MD_FS_CreateDir(FolderName);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_CREATE_FOLDER_T4_ERR, fs_api_ret);
        return KAL_FALSE;
    }    
//    fs_api_ret = MD_FS_Close(fs_api_ret);
//    ASSERT( fs_api_ret < FS_NO_ERROR);
    
    return KAL_TRUE;
    
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static kal_bool cccifs_it_read_op()
{
    WCHAR FileName[256];
    kal_bool ret;
    kal_int32 fs_api_ret;
    FS_FileOpenHint fileopenhint;
    kal_int32 ccci_file_handle_a, ccci_file_handle_b, ccci_file_handle_c;
    kal_uint32 read_byte_a, read_byte_b, read_byte_c;    
    kal_char testing_string[CCCI_FILE_MAX_TEST_LEN]; 
    kal_char returning_string[CCCI_FILE_MAX_TEST_LEN]; 
    kal_uint32 read_len;
    kal_uint32 string_match;
    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    kal_wsprintf(FileName, "%s\0", CCCI_FS_IT_FILE_A);
    //4 <1> create CCCI_FS_IT_FILE_A
    ccci_file_handle_a = MD_FS_Open(FileName, FS_READ_WRITE);
    if ( ccci_file_handle_a < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_READ_CREATE_FILE_T1_ERR, ccci_file_handle_a);
        return KAL_FALSE;
    }

    kal_wsprintf(FileName, "%s\0", CCCI_FS_IT_FILE_B);
    //4 <2> create CCCI_FS_IT_FILE_B
    ccci_file_handle_b = MD_FS_Open(FileName, FS_READ_WRITE);
    if ( ccci_file_handle_b < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_READ_CREATE_FILE_T2_ERR, ccci_file_handle_b);
        fs_api_ret = MD_FS_Close(ccci_file_handle_a);
        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);
        return KAL_FALSE;
    }

    kal_wsprintf(FileName, "%s\0", CCCI_FS_IT_FILE_C);
    fileopenhint.Cluster = 0;
    fileopenhint.Index = 0;
    fileopenhint.Stamp = 200;
    fileopenhint.Drive = 300;
    fileopenhint.SerialNumber = 400;
    //4 <3> create CCCI_FS_IT_FILE_C
    ccci_file_handle_c = MD_FS_OpenHint(FileName, FS_READ_WRITE, &fileopenhint);
    if ( ccci_file_handle_c < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_READ_CREATE_FILE_T3_ERR, ccci_file_handle_c);
        fs_api_ret = MD_FS_Close(ccci_file_handle_a);
        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);
        fs_api_ret = MD_FS_Close(ccci_file_handle_b);
        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);
        return KAL_FALSE;
    }

    
    //4 <4> read the content back and compare
    kal_sprintf(testing_string, "%s%s", CCCI_MAGIC_STR, CCCI_FILE_A_CONTENT);
    read_len = strlen(testing_string);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, read_len < CCCI_FILE_MAX_TEST_LEN, read_len, CCCI_FILE_MAX_TEST_LEN,0,0, __LINE__);
    fs_api_ret = MD_FS_Read(ccci_file_handle_a, returning_string, read_len , &read_byte_a);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_READ_FILE_T1_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }
    returning_string[read_byte_a] = '\0';

    string_match = strncmp(testing_string, returning_string, read_byte_a);
    if(STR_MATCH_RETURN != string_match){
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_READ_FILE_C_T1_ERR, string_match);
        ret=KAL_FALSE;
        goto error_exit;
    }


    kal_sprintf(testing_string, "%s", CCCI_MAGIC_STR);
    read_len = strlen(testing_string);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, read_len < CCCI_FILE_MAX_TEST_LEN, read_len, CCCI_FILE_MAX_TEST_LEN,0,0, __LINE__);
    fs_api_ret = MD_FS_Seek(ccci_file_handle_b, strlen(CCCI_MAGIC_STR), FS_FILE_BEGIN);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_SEEK_FILE_T1_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }
    fs_api_ret = MD_FS_Read(ccci_file_handle_b, returning_string, read_len , &read_byte_b);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_READ_FILE_T2_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }
    returning_string[read_byte_b] = '\0'; 

    kal_sprintf(testing_string, "%s", CCCI_FILE_B_CONTENT);
    string_match = strncmp(testing_string, returning_string, read_byte_b);
    if(STR_MATCH_RETURN != string_match){
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_READ_FILE_C_T2_ERR, string_match);
        ret=KAL_FALSE;
        goto error_exit;
    }



    kal_sprintf(testing_string, "%s%s", CCCI_MAGIC_STR, CCCI_FILE_C_CONTENT);
    read_len = strlen(testing_string);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, read_len < CCCI_FILE_MAX_TEST_LEN, read_len, CCCI_FILE_MAX_TEST_LEN,0,0, __LINE__); 
    fs_api_ret = MD_FS_Read(ccci_file_handle_c, returning_string, read_len , &read_byte_c);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_READ_FILE_T3_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }
    returning_string[read_byte_c] = '\0';

    string_match = strncmp(testing_string, returning_string, read_byte_c);
    if(STR_MATCH_RETURN != string_match){
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_READ_FILE_C_T3_ERR, string_match);
        ret=KAL_FALSE;
        goto error_exit;
    }  

    ret = KAL_TRUE;
error_exit:

    //4 <2> close CCCI_FS_IT_FILE_A, CCCI_FS_IT_FILE_B, CCCI_FS_IT_FILE_C
    /* close file should always returen NO_ERROR */
    fs_api_ret = MD_FS_Close(ccci_file_handle_c);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);
    fs_api_ret = MD_FS_Close(ccci_file_handle_b);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);
    fs_api_ret = MD_FS_Close(ccci_file_handle_a);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);

    return ret;
    
}

/* No use
static kal_bool cccifs_it_fake_16kbio_op(void* io_buff, kal_uint32 buff_len)
{
    kal_uint32 written_byte = 0;
    MD_FS_Write(0, io_buff, buff_len , &written_byte);
    return KAL_TRUE;
}
*/

static kal_bool cccifs_it_cmpt_read_op()
{
    WCHAR FileName[256];
    kal_bool ret;
    kal_int32 fs_api_ret;
    kal_uint32 read_byte_a;    
    kal_char testing_string[CCCI_FILE_MAX_TEST_LEN]; 
    kal_char returning_string[CCCI_FILE_MAX_TEST_LEN]; 
    kal_uint32 read_len;
    kal_uint32 string_match;
    NVRAM_FS_PARAM_CMPT_T fs_cmpt;
    kal_uint32 file_size;

    
    //4 <1> Only test read
    kal_sprintf(testing_string, "%s%s", CCCI_MAGIC_STR, CCCI_FILE_A_CONTENT);
    read_len = strlen(testing_string);
    fs_cmpt.opid_map = NVRAM_FS_CMPT_OPEN | NVRAM_FS_CMPT_GETFILESIZE | NVRAM_FS_CMPT_READ | NVRAM_FS_CMPT_CLOSE;
    fs_cmpt.Flag = FS_READ_WRITE;
    fs_cmpt.Length = read_len;
    fs_cmpt.Offset = 0;
    fs_cmpt.Whence = FS_FILE_BEGIN;
    fs_cmpt.DataPtr = returning_string;
    fs_cmpt.Read = &read_byte_a;
    fs_cmpt.FileSize = &file_size;
    kal_wsprintf(FileName, "%s\0", CCCI_FS_IT_FILE_A);
    fs_api_ret = MD_FS_CMPT_Read(FileName, &fs_cmpt);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_READ_FILE_T1_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }
    returning_string[read_byte_a] = '\0';
    
    string_match = strncmp(testing_string, returning_string, read_byte_a);
    if(STR_MATCH_RETURN != string_match){
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_READ_FILE_C_T1_ERR, string_match);
        ret=KAL_FALSE;
        goto error_exit;
    }

    //4 <2>  test seek
    kal_sprintf(testing_string, "%s%s", CCCI_MAGIC_STR, CCCI_FILE_A_CONTENT);
    read_len = strlen(testing_string);
    fs_cmpt.opid_map = NVRAM_FS_CMPT_OPEN | NVRAM_FS_CMPT_GETFILESIZE | NVRAM_FS_CMPT_READ | NVRAM_FS_CMPT_SEEK | NVRAM_FS_CMPT_CLOSE;
    fs_cmpt.Flag = FS_READ_WRITE;
    fs_cmpt.Length = read_len;
    fs_cmpt.Offset = strlen(CCCI_MAGIC_STR);
    fs_cmpt.Whence = FS_FILE_BEGIN;
    fs_cmpt.DataPtr = returning_string;
    fs_cmpt.Read = &read_byte_a;
    fs_cmpt.FileSize = &file_size;
    kal_wsprintf(FileName, "%s\0", CCCI_FS_IT_FILE_A);
    fs_api_ret = MD_FS_CMPT_Read(FileName, &fs_cmpt);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_READ_FILE_T1_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }
    returning_string[read_byte_a] = '\0';
    
    kal_sprintf(testing_string, "%s", CCCI_FILE_A_CONTENT);
    string_match = strncmp(testing_string, returning_string, read_byte_a);
    if(STR_MATCH_RETURN != string_match){
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_READ_FILE_C_T1_ERR, string_match);
        ret=KAL_FALSE;
        goto error_exit;
    }
    
    ret = KAL_TRUE;
error_exit:

    return ret;
}


static kal_bool cccifs_it_find_op()
{
    WCHAR FileName[256];
    WCHAR FindName[256];
    kal_int32 fs_api_ret, file_handle;
    FS_DOSDirEntry file_info;
    kal_uint32 max_len = 256;
    kal_bool   ret;
    kal_int32  ccci_file_handle_aa;

    kal_wsprintf(FileName, "%s\0", CCCI_FS_IT_FILE_A_LV2);
    ccci_file_handle_aa = MD_FS_Open(FileName, FS_CREATE|FS_READ_WRITE);
    if ( ccci_file_handle_aa < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_CREATE_FILE_FF_ERR, ccci_file_handle_aa);
        return KAL_FALSE;
    }
    /* close file should always returen NO_ERROR */
    fs_api_ret = MD_FS_Close(ccci_file_handle_aa);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);

    kal_wsprintf(FindName, "%s\0", CCCI_FS_IT_FILE_A);
    //4 <Note> testing MD_FS_FindFirst/MD_FS_FindNext/ MD_FS_FindClose
    fs_api_ret = MD_FS_FindFirst(FindName, 0, 0, &file_info, FileName, max_len);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FF_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }
    file_handle = fs_api_ret;

   
    fs_api_ret = MD_FS_FindNext(file_handle, &file_info, FileName, max_len);
    if ( fs_api_ret != FS_NO_MORE_FILES)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FN_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }

    fs_api_ret = MD_FS_FindClose(file_handle);    
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FC_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }

    ret=KAL_TRUE;

error_exit:    
    return ret;
}

#define cccifsit_quick_trace(...) dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_CCCIFS, ##__VA_ARGS__)

#define CCCI_FS_IT_FILE_PATH_a     "Z:\\CCCI_FS_IT\\"

#define CCCI_FS_IT_FILE_LEN        (NVRAM_FILE_LEN) //8
static kal_bool cccifs_it_find_op2()
{
    WCHAR FolderName[256];
    WCHAR FileName[256];
    //WCHAR FindName[CCCI_FS_IT_FILE_LEN+1];
    //WCHAR FindName2[CCCI_FS_IT_FILE_LEN+1];
    WCHAR FindName[CCCI_FS_IT_FILE_LEN+1];   //maximum shall not exceed 127 (126 + '\0') 
    WCHAR FindName2[CCCI_FS_IT_FILE_LEN+1];  //maximum shall not exceed 127 (126 + '\0') 
    char FileName_chr[CCCI_FS_IT_FILE_LEN+1];
    kal_int32 fs_api_ret, file_handle;
    FS_DOSDirEntry file_info;
    //kal_uint32 max_len = sizeof(FindName);
    kal_bool   ret;
    kal_int32  ccci_file_handle_aa;
    kal_uint32 i;

    kal_wsprintf(FolderName, "%s\0", CCCI_FS_IT_FOLDER);
    //4 <1> create CCCI_FS_IT_FOLDER_DMY
    fs_api_ret = MD_FS_CreateDir(FolderName);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_CREATE_FOLDER_T1_ERR, fs_api_ret);
        ccci_fs_it_error_line = __LINE__;
        return KAL_FALSE;
    }

    for(i = 0 ; i < CCCI_FS_IT_FILE_LEN; i++) //i < 126
    {
        FileName_chr[i] = 0x41+(i%26);
        FileName_chr[i+1] = 0;
        
        //set filename
        kal_wsprintf(FindName2, "%s\0", FileName_chr);
    
        kal_wsprintf(FileName, "%s%s\0", CCCI_FS_IT_FILE_PATH_a, FileName_chr);
        ccci_file_handle_aa = MD_FS_Open(FileName, FS_CREATE|FS_READ_WRITE);
        if ( ccci_file_handle_aa < FS_NO_ERROR)
        {
            ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_CREATE_FILE_FF_ERR, ccci_file_handle_aa);
            ccci_fs_it_error_line = __LINE__;
            return KAL_FALSE;
        }
        /* close file should always returen NO_ERROR */
        fs_api_ret = MD_FS_Close(ccci_file_handle_aa);
        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);
    
        //4 <Note> testing MD_FS_FindFirst/MD_FS_FindNext/ MD_FS_FindClose
        fs_api_ret = MD_FS_FindFirst(FileName, 0, 0, &file_info, FindName, (i+2)*2);
        if ( fs_api_ret < FS_NO_ERROR)
        {
            ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FF_ERR, fs_api_ret);
            ret=KAL_FALSE;
            ccci_fs_it_error_line = __LINE__;
            goto error_exit;
        }
        file_handle = fs_api_ret;

        if(kal_wstrcmp(FindName2,FindName)!= 0)
        {
            cccifsit_quick_trace("[CCCIFS_IT_ERROR] FindName2 len = %d, FindName len = %d", kal_dchar_strlen((const char *)FindName2), kal_dchar_strlen((const char *)FindName));
            ccci_fs_it_error_line = __LINE__;
            ret=KAL_FALSE;
            goto error_exit;
        }

        fs_api_ret = MD_FS_FindClose(file_handle);    
        if ( fs_api_ret < FS_NO_ERROR)
        {
            ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FC_ERR, fs_api_ret);
            ret=KAL_FALSE;
            ccci_fs_it_error_line = __LINE__;
            goto error_exit;
        }
    }
    ret = KAL_TRUE;

error_exit:
    return ret;
}


static kal_bool cccifs_it_file_op()
{
    WCHAR FileName[256];
    kal_bool ret;
    kal_int32 fs_api_ret;
    FS_FileOpenHint fileopenhint;
    kal_int32 ccci_file_handle_a, ccci_file_handle_b, ccci_file_handle_c;
    kal_uint32 written_byte_a, written_byte_b, written_byte_c;
    kal_char testing_string[CCCI_FILE_MAX_TEST_LEN]; 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    kal_wsprintf(FileName, "%s\0", CCCI_FS_IT_FILE_A);
    //4 <1> create CCCI_FS_IT_FILE_A
    ccci_file_handle_a = MD_FS_Open(FileName, FS_CREATE|FS_READ_WRITE);
    if ( ccci_file_handle_a < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_CREATE_FILE_T1_ERR, ccci_file_handle_a);
        return KAL_FALSE;
    }

    kal_wsprintf(FileName, "%s\0", CCCI_FS_IT_FILE_B);
    //4 <2> create CCCI_FS_IT_FILE_B
    ccci_file_handle_b = MD_FS_Open(FileName, FS_CREATE|FS_READ_WRITE);
    if ( ccci_file_handle_b < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_CREATE_FILE_T2_ERR, ccci_file_handle_b);
        fs_api_ret = MD_FS_Close(ccci_file_handle_a);
        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);
        return KAL_FALSE;
    }

    kal_wsprintf(FileName, "%s\0", CCCI_FS_IT_FILE_C);
    fileopenhint.Cluster = 0;
    fileopenhint.Index = 0;
    fileopenhint.Stamp = 200;
    fileopenhint.Drive = 300;
    fileopenhint.SerialNumber = 400;
    //4 <3> create CCCI_FS_IT_FILE_C
    ccci_file_handle_c = MD_FS_OpenHint(FileName, FS_CREATE|FS_READ_WRITE, &fileopenhint);
    if ( ccci_file_handle_c < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_CREATE_FILE_T3_ERR, ccci_file_handle_c);
        fs_api_ret = MD_FS_Close(ccci_file_handle_a);
        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);
        fs_api_ret = MD_FS_Close(ccci_file_handle_b);
        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);
        return KAL_FALSE;
    }

    //4 <4> writhe the initial contents
    kal_sprintf(testing_string, "%s%s", CCCI_MAGIC_STR, CCCI_FILE_A_CONTENT);
    fs_api_ret = MD_FS_Write(ccci_file_handle_a, testing_string, strlen(testing_string) , &written_byte_a);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_WRITE_FILE_T1_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }
    kal_sprintf(testing_string, "%s%s", CCCI_MAGIC_STR, CCCI_FILE_B_CONTENT);
    fs_api_ret = MD_FS_Write(ccci_file_handle_b, testing_string, strlen(testing_string) , &written_byte_b);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_WRITE_FILE_T2_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }
    kal_sprintf(testing_string, "%s%s", CCCI_MAGIC_STR, CCCI_FILE_C_CONTENT);    
    fs_api_ret = MD_FS_Write(ccci_file_handle_c, testing_string, strlen(testing_string) , &written_byte_c);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_WRITE_FILE_T3_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }

    ret = KAL_TRUE;
error_exit:

    //4 <2> close CCCI_FS_IT_FILE_A, CCCI_FS_IT_FILE_B, CCCI_FS_IT_FILE_C
    /* close file should always returen NO_ERROR */
    fs_api_ret = MD_FS_Close(ccci_file_handle_c);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);
    fs_api_ret = MD_FS_Close(ccci_file_handle_b);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);
    fs_api_ret = MD_FS_Close(ccci_file_handle_a);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);

    return ret;
    
}


static kal_bool cccifs_it_file_path_op()
{
    WCHAR FName[128];
    WCHAR New_FName[128];
    kal_char testing_string[CCCI_FILE_MAX_TEST_LEN]; 
    kal_char returning_string[CCCI_FILE_MAX_TEST_LEN];    
    kal_bool ret;
    kal_int32 fs_api_ret;
    kal_int32 ccci_file_handle_a;
    kal_uint32 fsz;
    kal_uint32 read_len, read_byte;
    kal_int32 string_match;
//    kal_char testing_string[CCCI_FILE_MAX_TEST_LEN]; 


    kal_wsprintf(FName, "%s\0", CCCI_FS_IT_FILE_A);
    //4 <1> create CCCI_FS_IT_FILE_A
    ccci_file_handle_a = MD_FS_Open(FName, FS_READ_WRITE);
    if ( ccci_file_handle_a < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FMISC_CREATE_FILE_ERR, ccci_file_handle_a);
        return KAL_FALSE;
    }

    fs_api_ret = MD_FS_GetFileSize(ccci_file_handle_a, &fsz);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FMISC_GSZ_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }

    fs_api_ret = MD_FS_GetAttributes(FName);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FMISC_GFA_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }

    kal_wsprintf(FName, "%s\0", CCCI_FS_IT_FOLDER);
    fs_api_ret = MD_FS_GetFolderSize(FName, FS_COUNT_IN_CLUSTER, NULL, 0);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FMISC_GSZ_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }

    fs_api_ret = MD_FS_Count(FName, FS_FILE_TYPE, NULL, 0);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FMISC_FSC_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }

    //4 <2> close CCCI_FS_IT_FILE_A /RENAME_FS_IT_FILE_A / OPEN / READ
    /* close file should always returen NO_ERROR */
    fs_api_ret = MD_FS_Close(ccci_file_handle_a);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);

    kal_wsprintf(FName, "%s\0", CCCI_FS_IT_FILE_B);
    kal_wsprintf(New_FName, "%s\0", CCCI_FS_IT_FILE_B_RE);
    fs_api_ret = MD_FS_Rename(FName, New_FName);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FMISC_RENAME_ERR, fs_api_ret);
        return KAL_FALSE;
    }

    ccci_file_handle_a = MD_FS_Open(New_FName, FS_READ_WRITE);
    if ( ccci_file_handle_a < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FMISC_RNCREATE_ERR, ccci_file_handle_a);
        return KAL_FALSE;
    }

    
    kal_sprintf(testing_string, "%s%s", CCCI_MAGIC_STR, CCCI_FILE_B_CONTENT);
    read_len = strlen(testing_string);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, read_len < CCCI_FILE_MAX_TEST_LEN, read_len, CCCI_FILE_MAX_TEST_LEN,0,0, __LINE__);
    fs_api_ret = MD_FS_Read(ccci_file_handle_a, returning_string, read_len , &read_byte);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FMISC_READ_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }
    returning_string[read_byte] = '\0';

    string_match = strncmp(testing_string, returning_string, read_byte);
    if(STR_MATCH_RETURN != string_match){
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FMISC_READRLT_ERR, string_match);
        ret=KAL_FALSE;
        goto error_exit;
    }



    //4 <3> close CCCI_FS_IT_FILE_B_RE /MD_FS_Move / OPEN / READ
    /* close file should always returen NO_ERROR */
    fs_api_ret = MD_FS_Close(ccci_file_handle_a);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);


    kal_wsprintf(FName, "%s\0", CCCI_FS_IT_FILE_B_RE);
    kal_wsprintf(New_FName, "%s\0", CCCI_FS_IT_FILE_B_MV);
    fs_api_ret = MD_FS_Move(FName, New_FName, FS_MOVE_COPY, NULL, NULL, 0);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FMISC_MV_ERR, fs_api_ret);
        return KAL_FALSE;
    }
    
    ccci_file_handle_a = MD_FS_Open(New_FName, FS_READ_WRITE);
    if ( ccci_file_handle_a < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FMISC_MVCREATE_ERR, ccci_file_handle_a);
        return KAL_FALSE;
    }

    kal_sprintf(testing_string, "%s%s", CCCI_MAGIC_STR, CCCI_FILE_B_CONTENT);
    read_len = strlen(testing_string);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, read_len < CCCI_FILE_MAX_TEST_LEN, read_len, CCCI_FILE_MAX_TEST_LEN,0,0, __LINE__);
    fs_api_ret = MD_FS_Read(ccci_file_handle_a, returning_string, read_len , &read_byte);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FMISC_READMV_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }
    returning_string[read_byte] = '\0';

    string_match = strncmp(testing_string, returning_string, read_byte);
    if(STR_MATCH_RETURN != string_match){
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FMISC_READRLTMV_ERR, string_match);
        ret=KAL_FALSE;
        goto error_exit;
    }


    kal_wsprintf(FName, "%s\0", CCCI_FS_IT_FILE_B_RE);
    fs_api_ret = MD_FS_Delete(FName);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FMISC_DELF_ERR, fs_api_ret);
        return KAL_FALSE;
    }

    ret=KAL_TRUE;
error_exit:

    //4 <2> close CCCI_FS_IT_FILE_A
    /* close file should always returen NO_ERROR */
    fs_api_ret = MD_FS_Close(ccci_file_handle_a);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);

    return ret;
}

static kal_bool cccifs_it_disk_op()
{
    WCHAR DriveName[256];
    FS_DiskInfo DI;
    kal_int32 fs_api_ret;
        
    //4 <1> MD_FS_GetDiskInfo test
    kal_wsprintf(DriveName, "%s\0", CCCI_FS_IT_DRIVE);
    fs_api_ret = MD_FS_GetDiskInfo((const WCHAR*)DriveName, &DI, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_IT, CCCIFS_TR_GETDKINFO_RET, DI.SectorsPerCluster, DI.TotalClusters, DI.TotalClusters, fs_api_ret);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_GETDKINFO_ERR, fs_api_ret);
        return KAL_FALSE;
    }
    //4 <2> MD_FS_LockFAT / MD_FS_UnlockAll
    fs_api_ret = MD_FS_LockFAT(0);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_LOCKFAT_ERR, fs_api_ret);
        return KAL_FALSE;
    }
    fs_api_ret = MD_FS_UnlockAll();
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_UNLOCKALL_ERR, fs_api_ret);
        return KAL_FALSE;
    }
    //4 <3> MD_FS_ClearDiskFlag / MD_FS_SetDiskFlag
    fs_api_ret = MD_FS_ClearDiskFlag();
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_CLRDFLAG_ERR, fs_api_ret);
        return KAL_FALSE;
    }
    fs_api_ret = MD_FS_SetDiskFlag();
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_SETDFLAG_ERR, fs_api_ret);
        return KAL_FALSE;
    }

    //4 <4> MD_FS_GetDrive / MD_FS_GetClusterSize 
    fs_api_ret = MD_FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_DRIVE_V_REMOVABLE | FS_DRIVE_I_SYSTEM);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_GET_DRV_ERR, fs_api_ret);
        return KAL_FALSE;
    }
    
    fs_api_ret = MD_FS_GetClusterSize(fs_api_ret);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_SETDFLAG_ERR, fs_api_ret);
        return KAL_FALSE;
    }
   

    return KAL_TRUE;
}

#ifdef CCCI_FS_IT_SUPPORT_OTP
static kal_bool cccifs_it_otp_op()
{
    kal_uint32 otplen;
    kal_int32 fs_api_ret;
    kal_char  fs_otp_buff[CCCI_FILE_MAX_TEST_LEN];

    //4 <NOTE> MT6575 doesn't have /dev/otp expect the api all faill
    //4 Testing MD_FS_OTPWrite/ MD_FS_OTPRead/ MD_FS_OTPLock/MD_FS_OTPQueryLength

    fs_api_ret = MD_FS_OTPQueryLength(0, &otplen);
    if ( fs_api_ret != FS_UNSUPPORTED_DRIVER_FUNCTION)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_OTP_LEN_ERR, fs_api_ret);
        return KAL_FALSE;
    }


    fs_api_ret = MD_FS_OTPLock(0);
    if ( fs_api_ret != FS_UNSUPPORTED_DRIVER_FUNCTION)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_OTP_LOCK_ERR, fs_api_ret);
        return KAL_FALSE;
    }

    fs_api_ret = MD_FS_OTPRead(0, 0, (void *)&fs_otp_buff, CCCI_FILE_MAX_TEST_LEN);
    if ( fs_api_ret != FS_UNSUPPORTED_DRIVER_FUNCTION)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_OTP_READ_ERR, fs_api_ret);
        return KAL_FALSE;
    }

    fs_api_ret = MD_FS_OTPWrite(0, 0, (void *)&fs_otp_buff, CCCI_FILE_MAX_TEST_LEN);
    if ( fs_api_ret != FS_ERROR_RESERVED)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_OTP_WRITE_ERR, fs_api_ret);
        return KAL_FALSE;
    }

    return KAL_TRUE;    
}
#endif
static kal_bool cccifs_it_process_clean_up()
{
    WCHAR FolderName[256];

    kal_wsprintf(FolderName, "%s\0", CCCI_FS_IT_FOLDER);
    MD_FS_XDelete(FolderName, FS_FILE_TYPE|FS_DIR_TYPE|FS_RECURSIVE_TYPE, NULL, 0);

    /*XDelete return error code if the file is not found*/
    //CCCI_FS_ASSERT( fs_api_ret >= FS_NO_ERROR);

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_IT, CCCIFS_TR_IT_CLN_PASS);
    return KAL_TRUE;
}

static kal_bool cccifs_it_process_find_op()
{
    kal_bool ret;
//    kal_int32 buf_seed = CCCI_FS_IT_MAGIC;
  
    //4 <6> testing the file search op
    ret = cccifs_it_find_op2();
    if (KAL_TRUE != ret){ goto it_err_cleanup; }

    //4 <n> remove the path of CCCI_FS_IT_FOLDER    
    ret = ccci_fs_it_close_all();
    if (KAL_TRUE != ret){ goto it_err_cleanup; }
    cccifs_it_process_clean_up();

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_IT, CCCIFS_TR_IT_PASS);
    return KAL_TRUE;


it_err_cleanup:
    //4 <n> remove the path of CCCI_FS_IT_FOLDER
    ret = ccci_fs_it_close_all();
    if (KAL_TRUE != ret){ goto it_error; }

    cccifs_it_process_clean_up();
    
it_error:
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FAIL);
    CCCI_FS_ASSERT(CCCI_FS_NORMAL_ASSERT, KAL_FALSE ,0,0,0,0, __LINE__);
    return KAL_FALSE;    
}
static kal_bool cccifs_it_process()
{
    kal_bool ret;
//    kal_int32 buf_seed = CCCI_FS_IT_MAGIC;

    //4 <0> test cmpt read
#ifdef CCCI_FS_IT_FFFN_TEST
    cccifs_it_process_find_op();
#endif
    //4 <1> Test OTP APIs CS: OTP only support _otp project
#ifdef CCCI_FS_IT_SUPPORT_OTP
    ret = cccifs_it_otp_op();
    if (KAL_TRUE != ret){ goto it_error; }
#endif    
    //4 <2> Test the get disk information APIs
    ret = cccifs_it_disk_op();
    if (KAL_TRUE != ret){ goto it_error; }
    
    ret = ccci_fs_it_close_all();
    if (KAL_TRUE != ret){ goto it_error; }

    //4 <3> create the CCCI_FS_IT_FOLDER and test the directory APIs
    ret = cccifs_it_create_dir();
    if (KAL_TRUE != ret){ goto it_error; }

    //4 <4> create the files and write the initial data
    ret = cccifs_it_file_op();
    if (KAL_TRUE != ret){ goto it_err_cleanup; }

    //4 <5> read the content and compare
    ret = cccifs_it_read_op();
    if (KAL_TRUE != ret){ goto it_err_cleanup; }

    //4 <6> testing the file search op
    ret = cccifs_it_find_op();
    if (KAL_TRUE != ret){ goto it_err_cleanup; }

    //4 <7> cccifs_it_file_path_op
    ret = cccifs_it_file_path_op();
    if (KAL_TRUE != ret){ goto it_err_cleanup; }

    //4 <8> cccifs_it_file_path_op
    ret = cccifs_it_cmpt_read_op();
    if (KAL_TRUE != ret){ goto it_err_cleanup; }

    //4 <n> remove the path of CCCI_FS_IT_FOLDER    
    ret = ccci_fs_it_close_all();
    if (KAL_TRUE != ret){ goto it_err_cleanup; }
    cccifs_it_process_clean_up();

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_IT, CCCIFS_TR_IT_PASS);
    return KAL_TRUE;


it_err_cleanup:
    //4 <n> remove the path of CCCI_FS_IT_FOLDER
    ret = ccci_fs_it_close_all();
    if (KAL_TRUE != ret){ goto it_err_cleanup; }

    cccifs_it_process_clean_up();
    
it_error:
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_IT, CCCIFS_TR_IT_FAIL);
    CCCI_FS_ASSERT(CCCI_FS_NORMAL_ASSERT, KAL_FALSE ,0,0,0,0, __LINE__);
    return KAL_FALSE;    
}


/* copied from driver test random function */
static kal_uint32 cccifs_rand_seed = 123456789;
static kal_uint32 y = 362436;
static kal_uint32 z = 521288629;
static kal_uint32 c = 7654321;

kal_uint32 drvtest_rand(void)
{
   kal_uint64 t, a= 698769069;

   cccifs_rand_seed = 69069 * cccifs_rand_seed + 12345;
   y ^= (y << 13); y ^= (y >> 17); y ^= (y << 5);
   t = a * z + c; c = (t >> 32); z = t;

   return cccifs_rand_seed + y + z;
}

static kal_bool cccifs_it_16kio_process(kal_bool rand_len_en)
{   
    WCHAR FileName[256];
    WCHAR FolderName[256];
    kal_int32  ccci_fh;
    kal_bool   ret;
    kal_int32  fs_api_ret;
    kal_int32  buf_seed = CCCI_FS_IT_MAGIC;
    kal_int32  i, *dptr;
    kal_uint32 written_byte=0;
    kal_uint32 read_byte=0;
    kal_uint32 read_len=0;
    kal_int32  string_match;
    kal_uint32 target_len = 0;

    kal_mem_set(ccci_fs_it_buff_16k, 0, sizeof(ccci_fs_it_buff_16k));
    kal_mem_set(ccci_fs_it_buff_16k_ret, 0, sizeof(ccci_fs_it_buff_16k_ret));

    dptr = (kal_int32*)ccci_fs_it_buff_16k;

    if(KAL_TRUE == rand_len_en){
        //mtk04122: length shall not be zero, otherwise ap will decode error
        target_len = (drvtest_rand() % CCCI_FS_MAX_IO_16K)+1;
    }else{
        target_len = CCCI_FS_MAX_IO_16K;
    }

    for(i = 0; i < CCCI_FS_MAX_IO_16K; i++){
        *(dptr+i) = buf_seed++;
    }

    /* create CCCI_FS_IT_FOLDER First*/
    kal_wsprintf(FolderName, "%s\0", CCCI_FS_IT_FOLDER);
    fs_api_ret = MD_FS_CreateDir(FolderName);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_CREATE_FOLDER_T3_ERR, fs_api_ret);
        return KAL_FALSE;
    }
    
    //4 <1> Create the IT file
    kal_wsprintf(FileName, "%s\0", CCCI_FS_IT_FILE_16K);
    ccci_fh = MD_FS_Open(FileName, FS_CREATE|FS_READ_WRITE);
    if ( ccci_fh < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_READ_CREATE_FILE_16K_ERR, ccci_fh);
        return KAL_FALSE;
    }

    //4 <2> Write the file content
    fs_api_ret = MD_FS_Write(ccci_fh, ccci_fs_it_buff_16k, target_len , &written_byte);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_WRITE_FILE_16K_ERR, fs_api_ret);
        ret = KAL_FALSE;
        goto error_exit;
    }

    //4 <3> Reset file pointer
    fs_api_ret = MD_FS_Seek(ccci_fh, 0, FS_FILE_BEGIN);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_SEEK_FILE_16K_ERR, fs_api_ret);
        ret=KAL_FALSE;
        goto error_exit;
    }

    //4 <4> Read the written_byte back and compare the content
    read_byte = written_byte;
    read_len  = written_byte;
    fs_api_ret = MD_FS_Read(ccci_fh, ccci_fs_it_buff_16k_ret, read_len , &read_byte);
    if ( fs_api_ret < FS_NO_ERROR)
    {
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_READ_FILE_16K_ERR, fs_api_ret);
        ret = KAL_FALSE;
        goto error_exit;
    }
    ccci_fs_it_buff_16k_ret[read_byte] = '\0';

    //string_match = strncmp(ccci_fs_it_buff_16k, ccci_fs_it_buff_16k_ret, read_byte);
    string_match = kal_mem_cmp(ccci_fs_it_buff_16k, ccci_fs_it_buff_16k_ret, read_byte);
    if(STR_MATCH_RETURN != string_match){
        ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_IT, CCCIFS_TR_IT_READ_RESULT_16K_ERR, string_match);
        ret=KAL_FALSE;
        goto error_exit;
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_IT, CCCIFS_TR_IT_16K_PASS);

    fs_api_ret = MD_FS_Close(ccci_fh);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);
    
    return KAL_TRUE;
error_exit:

    /* close file should always returen NO_ERROR */
    fs_api_ret = MD_FS_Close(ccci_fh);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, fs_api_ret >= FS_NO_ERROR, fs_api_ret, 0,0,0, __LINE__);

    return ret;

}

typedef enum
{
    CCCI_FS_IT_DISABLE  = 0,
    CCCI_FS_IT_SINGLE   = 1,
    CCCI_FS_IT_MULTI    = 2,
    CCCI_FS_IT_16KBIO   = 4,
    CCCI_FS_IT_CLEANUP  = 8
} CCCI_FS_IT_CASE;

void cccifs_it_case()
{
    kal_uint32 i;   
    kal_bool it_ret;

    cccifsit_trigger = CCCI_FS_IT_SINGLE |  CCCI_FS_IT_16KBIO | CCCI_FS_IT_CLEANUP;
    if(CCCI_FS_IT_SINGLE & cccifsit_trigger){
    
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_IT, CCCIFS_TR_IT_TRIGGER);
        cccifs_it_process_clean_up();

        cccifs_it_process();

        //cccifsit_trigger = 0;
    }
    if(CCCI_FS_IT_MULTI & cccifsit_trigger){
    
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_IT, CCCIFS_TR_IT_TRIGGER);
        cccifs_it_process_clean_up();
    
        for( i = 0; i<=TEST_RUN; i++){
            it_ret = cccifs_it_process();
            if(KAL_FALSE == it_ret)
            {
                CCCI_FS_ASSERT(CCCI_FS_NORMAL_ASSERT, KAL_FALSE ,0,0,0,0, __LINE__);
                break;
            }
        }
        
        //cccifsit_trigger = 0;
    }
    if(CCCI_FS_IT_16KBIO & cccifsit_trigger){
    
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_IT, CCCIFS_TR_IT_TRIGGER);
        cccifs_it_process_clean_up();
        
        cccifs_it_16kio_process(KAL_FALSE);
        //cccifs_it_16kio_process(KAL_TRUE);
    
        //cccifsit_trigger = 0;
    }
    if(CCCI_FS_IT_CLEANUP & cccifsit_trigger){
    
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_IT, CCCIFS_TR_IT_TRIGGER);
    
        cccifs_it_process_clean_up();
    
        //cccifsit_trigger = 0;
    }
    if(cccifsit_trigger == CCCI_FS_IT_DISABLE){
        ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_IT, CCCIFS_TR_IT_IDLE);
    }
}

static void cccifsit_task_main(task_entry_struct *task_entry_ptr)
{
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_IT, CCCIFS_TR_IT_START);    
    kal_sleep_task(10000);
    while(1){

        cccifs_it_case();
        kal_sleep_task(1000);
    }

    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_IT, CCCIFS_TR_IT_END);
}

kal_bool cccifsit_task_init(void)
{
    return KAL_TRUE;
}

kal_bool cccifsit_task_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct cccifsit_handler_info =
    {
        cccifsit_task_main,         /* task entry function */
        cccifsit_task_init,         /* task initialization function */
        NULL                        /* task reset handler */
    };

    *handle = (comptask_handler_struct *)&cccifsit_handler_info;
    return KAL_TRUE;
}

#endif //__CCCI_FS_IT__
