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
 * nvram_multi_folder.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   NVRAM feature: support multi folders
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"

#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "nvram_main.h"

/***********************************************************
 * Static Variable
 ***********************************************************/

/* marco to form absolute path and filename */
/* File System with wide character interface */

#define NVRAM_FS_MAKE_LID_PATH_FILENAME_1( buf, name )   \
   kal_wsprintf( buf, "%s\\%s", NVRAM_FS_DATAITEM_PATH, name)

#ifdef __NVRAM_MULTI_FOLDERS__
/* core folder */
#define NVRAM_FS_MAKE_CORE_PATH_FILENAME(buf, name)        \
    kal_wsprintf( buf, "%s\\%s", NVRAM_FS_COREITEM_PATH, name);

#define NVRAM_FS_MAKE_CRITICAL_CALIBRAT_PATH_FILENAME(buf, name)	\
    kal_wsprintf( buf, "%s\\%s", NVRAM_FS_CALIBRAT_DATAITEM_PATH, name);

#define NVRAM_FS_MAKE_CRITICAL_IMEI_PATH_FILENAME(buf, name)	\
    kal_wsprintf( buf, "%s\\%s", NVRAM_FS_IMEI_DATAITEM_PATH, name);

#define NVRAM_FS_MAKE_CUST_PATH_FILENAME(buf, name) \
    kal_wsprintf( buf, "%s\\%s", NVRAM_FS_CUST_DATAITEM_PATH, name);

#define NVRAM_FS_MAKE_IMPORTNT_PATH_FILENAME(buf, name) \
    kal_wsprintf( buf, "%s\\%s", NVRAM_FS_IMPORTNT_DATAITEM_PATH, name);

#define NVRAM_FS_MAKE_IMPORTNT_PATH_FILENAME2(buf, name) \
    kal_wsprintf( buf, "%s\\%s", NVRAM_FS_IMPORTNT_DATAITEM_PATH2, name);

#define NVRAM_FS_MAKE_IMPORTNT_PATH_FILENAME3(buf, name) \
    kal_wsprintf( buf, "%s\\%s", NVRAM_FS_IMPORTNT_DATAITEM_PATH3, name);
#endif

#ifdef __NVRAM_BACKUP_DISK_FAT__
#define NVRAM_FS_MAKE_BACKUP_PATH_FILENAME(buf, name)                       \
    kal_wsprintf( buf, "%s\\%s", NVRAM_FS_BACKUP_ROOT_PATH, name);
#endif


/***********************************************************
 * Global Variable
 **********************************************************/

/***********************************************************
 * Local Function
 **********************************************************/

/***********************************************************
 * Global Function
 **********************************************************/


#define FOLDER_PATH
/*****************************************************************************
 * FUNCTION
 *  nvram_query_folder_index
 * DESCRIPTION
 *  Get the index of folder
 * PARAMETERS
 *  category
 * RETURNS
 *  Success or Fail
 *****************************************************************************/

nvram_folder_enum nvram_query_folder_index_ex(nvram_category_enum category, kal_bool first_copy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_folder_enum folder_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __NVRAM_MULTI_FOLDERS__
    if (NVRAM_IS_CATEGORY_INTERNAL(category))
    {
        folder_index = NVRAM_NVD_CORE;
    }
    else if (NVRAM_IS_CATEGORY_CALIBRAT(category))
    {
        folder_index = NVRAM_NVD_CALI;
    }
    else if (NVRAM_IS_CATEGORY_IMPORTANT(category))
    {
        folder_index = NVRAM_NVD_IMEI;
    }
#if defined(__CCCIFS_SUPPORT__)
    else if (NVRAM_IS_CATEGORY_IMPORTANT_L4(category))
    {
    #if defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__)
        if (!first_copy)
            folder_index = NVRAM_NVD_IMPNT2;
        else
    #endif
        folder_index = NVRAM_NVD_IMPNT;
    }
#endif
    #ifdef __NVRAM_CUSTOM_SENSITIVE__
    else if (NVRAM_IS_CATEGORY_CUSTOM_SENSITIVE(category))
    {
        folder_index = NVRAM_NVD_CUST;
    }
    #endif
    else
#endif /* __NVRAM_MULTI_FOLDERS__ */
    {
        folder_index = NVRAM_NVD_DATA;
    }

    return folder_index;
}

nvram_folder_enum nvram_query_folder_index(nvram_category_enum category)
{
    return nvram_query_folder_index_ex(category, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  nvram_query_work_path
 * DESCRIPTION
 *  Get the path of nvram folder
 * PARAMETERS
 *  folder_idx
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
kal_char * nvram_query_work_path(nvram_folder_enum folder_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (folder_idx)
    {
        case NVRAM_NVD_DATA:
        {
            return (kal_char *)NVRAM_FS_DATAITEM_PATH;
        }
#ifdef __NVRAM_MULTI_FOLDERS__
        case NVRAM_NVD_CORE:
        {
            return (kal_char *)NVRAM_FS_COREITEM_PATH;
        }
        case NVRAM_NVD_CALI:
        {
            return (kal_char *)NVRAM_FS_CALIBRAT_DATAITEM_PATH;
        }
        case NVRAM_NVD_IMEI:
        {
            return (kal_char *)NVRAM_FS_IMEI_DATAITEM_PATH;
        }
        #if defined(__CCCIFS_SUPPORT__)
        case NVRAM_NVD_IMPNT:
        {
            return (kal_char *)NVRAM_FS_IMPORTNT_DATAITEM_PATH;
        }

        #if defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__)
        case NVRAM_NVD_IMPNT2:
        {
            return (kal_char *)NVRAM_FS_IMPORTNT_DATAITEM_PATH2;
        }
        case NVRAM_NVD_IMPNT3:
        {
            return (kal_char *)NVRAM_FS_IMPORTNT_DATAITEM_PATH3;
        }
        #endif

        #endif
        #ifdef __NVRAM_CUSTOM_SENSITIVE__
        case NVRAM_NVD_CUST:
        {
            return (kal_char *)NVRAM_FS_CUST_DATAITEM_PATH;
        }
        #endif
#endif /* __NVRAM_MULTI_FOLDERS__ */
        default:
        {
//            EXT_ASSERT(KAL_FALSE, 10, 10, 10);
            ASSERT(0);
            break;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_query_file_name
 * DESCRIPTION
 *  Get file full name
 * PARAMETERS
 *  folder_idx  :
 *  nvramname   : nvram file
 *  filename    : full name of nvram file
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
kal_wchar * nvram_query_file_name(nvram_folder_enum folder_idx, kal_char *nvramname, kal_wchar *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (folder_idx)
    {
        case NVRAM_NVD_DATA:
        {
            NVRAM_FS_MAKE_LID_PATH_FILENAME_1(filename, nvramname);
            break;
        }
    #ifdef __NVRAM_MULTI_FOLDERS__
        case NVRAM_NVD_CORE:
        {
            NVRAM_FS_MAKE_CORE_PATH_FILENAME(filename, nvramname);
            break;
        }
        case NVRAM_NVD_CALI:
        {
            NVRAM_FS_MAKE_CRITICAL_CALIBRAT_PATH_FILENAME(filename, nvramname);
            break;
        }
        case NVRAM_NVD_IMEI:
        {
            NVRAM_FS_MAKE_CRITICAL_IMEI_PATH_FILENAME(filename, nvramname);
            break;
        }
        #if defined(__CCCIFS_SUPPORT__)
        case NVRAM_NVD_IMPNT:
        {
            NVRAM_FS_MAKE_IMPORTNT_PATH_FILENAME(filename, nvramname);
            break;
        }

        #if defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__)
        case NVRAM_NVD_IMPNT2:
        {
            NVRAM_FS_MAKE_IMPORTNT_PATH_FILENAME2(filename, nvramname);
            break;
        }
        case NVRAM_NVD_IMPNT3:
        {
            NVRAM_FS_MAKE_IMPORTNT_PATH_FILENAME3(filename, nvramname);
            break;
        }
        #endif

        #endif
        #ifdef __NVRAM_CUSTOM_SENSITIVE__
        case NVRAM_NVD_CUST:
        {
            NVRAM_FS_MAKE_CUST_PATH_FILENAME(filename, nvramname);
            break;
        }
        #endif
    #endif /* __NVRAM_MULTI_FOLDERS__ */
    #ifdef __NVRAM_BACKUP_DISK_FAT__
        case NVRAM_NVD_BAK:
        {
            NVRAM_FS_MAKE_BACKUP_PATH_FILENAME(filename, nvramname);
            break;
        }
    #endif
        default:
        {
//            EXT_ASSERT(KAL_FALSE, 11, 11, 11);
            ASSERT(0);
            break;
        }
    }

    return filename;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_query_ex_file_name
 * DESCRIPTION
 *  Get file full name
 * PARAMETERS
 *  folder_idx  :
 *  nvramname   : nvram file
 *  filename    : full name of nvram file
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
kal_wchar * nvram_query_ex_file_name(nvram_folder_enum folder_idx, kal_wchar *nvramname, kal_wchar *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __NVRAM_MULTI_FOLDERS__
    if (folder_idx == NVRAM_NVD_CORE)
    {
        kal_wsprintf(filename, "%s\\%w", NVRAM_FS_COREITEM_PATH, nvramname);
    }
    else if (folder_idx == NVRAM_NVD_CALI)
    {
        kal_wsprintf(filename, "%s\\%w", NVRAM_FS_CALIBRAT_DATAITEM_PATH, nvramname);
    }
    else if (folder_idx == NVRAM_NVD_IMEI)
    {
        kal_wsprintf(filename, "%s\\%w", NVRAM_FS_IMEI_DATAITEM_PATH, nvramname);
    }
    #if defined(__CCCIFS_SUPPORT__)
    else if (folder_idx == NVRAM_NVD_IMPNT)
    {
        kal_wsprintf(filename, "%s\\%w", NVRAM_FS_IMPORTNT_DATAITEM_PATH, nvramname);
    }
    #endif
    #ifdef __NVRAM_CUSTOM_SENSITIVE__
    else if (folder_idx == NVRAM_NVD_CUST)
    {
        kal_wsprintf(filename, "%s\\%w", NVRAM_FS_CUST_DATAITEM_PATH, nvramname);
    }
    #endif
    else if (folder_idx == NVRAM_NVD_DATA)
#endif /* __NVRAM_MULTI_FOLDERS__ */
    {
        kal_wsprintf(filename, "%s\\%w", NVRAM_FS_DATAITEM_PATH, nvramname);
    }

    return filename;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_delete_certain_folder
 * DESCRIPTION
 *  Delete all files in certain folder
 * PARAMETERS
 *  folder_idx : [in]
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static nvram_errno_enum nvram_create_certain_folder(nvram_folder_enum folder_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[NVRAM_MAX_PATH_LEN];
    kal_int32 Ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(filename, "%s", nvram_query_work_path(folder_idx));

    Ret = FS_GetAttributes(filename);
    if (Ret < FS_NO_ERROR)
    {
        /* Return value should be FS_FILE_NOT_FOUND (-9) only, others treat as fatal error */
        Ret = FS_CreateDir((const kal_wchar*)filename);
//        EXT_ASSERT(Ret == FS_NO_ERROR, (kal_uint32) Ret, 0, 0);
        if (Ret == FS_NO_ERROR)
            return NVRAM_ERRNO_SUCCESS;
    }

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_CREATE_ALL_FOLDER, Ret, __LINE__);
    return NVRAM_ERRNO_FOLDER_EXIST;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_create_all_folder
 * DESCRIPTION
 *  create all the folders
 * PARAMETERS
 *  void
 * RETURNS
 *  status
 *****************************************************************************/
nvram_errno_enum nvram_create_all_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 loop_idx;
    nvram_errno_enum result = NVRAM_ERRNO_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (loop_idx = NVRAM_FOLDER_TOTAL - 1; loop_idx >= NVRAM_FOLDER_BEGIN; loop_idx--)    
    {
        if (nvram_create_certain_folder(loop_idx) == NVRAM_ERRNO_FOLDER_EXIST)
        {
            result = NVRAM_ERRNO_FOLDER_EXIST;
        }

        nvram_trace(TRACE_FUNC, FUNC_NVRAM_CREATE_ALL_FOLDER, loop_idx);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_delete_certain_folder
 * DESCRIPTION
 *  Delete all files in certain folder
 * PARAMETERS
 *  folder_idx : [in]
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static kal_bool nvram_delete_certain_folder(nvram_folder_enum folder_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    FS_DOSDirEntry fileinfo;
    WCHAR namepattern[32];

#if defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__) && defined(__CCCIFS_SUPPORT__)
    WCHAR filename[NVRAM_MAX_PATH_LEN];
#else
    WCHAR filename[NVRAM_FILE_LEN + 1];
#endif

    WCHAR fullfilename[NVRAM_MAX_PATH_LEN];
    kal_uint32 retval;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * FS_XDelete will cut the folder, here we can't call it.
     */

#if defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__) && defined(__CCCIFS_SUPPORT__)
    if ((folder_idx == NVRAM_NVD_IMPNT) || (folder_idx == NVRAM_NVD_IMPNT2))
    {   // SML should never be deleted
        return KAL_TRUE;
    }
#endif

    nvram_query_file_name(folder_idx, "*", namepattern);

 #ifndef __LOW_COST_SUPPORT_ULC__
    handle = FS_FindFirst(namepattern, 0, FS_ATTR_DIR, &fileinfo, filename, sizeof(filename));
    if (handle > 0)
    {
        do
        {
            nvram_query_ex_file_name(folder_idx, filename, fullfilename);


            retval = FS_Delete(fullfilename);
            if (retval != FS_NO_ERROR)
            {
                FS_FindClose(handle);
                return KAL_FALSE;
            }
        }
        while (FS_FindNext(handle, &fileinfo, filename, sizeof(filename)) == FS_NO_ERROR);
    }
    else
    {
        return KAL_FALSE;
    }

    FS_FindClose(handle);
#else /* __LOW_COST_SUPPORT_ULC__ */
    while(1)
    {
        handle = FS_FindFirst(namepattern, 0, FS_ATTR_DIR, &fileinfo, filename, sizeof(filename));
        if (handle > 0)
        {
            FS_FindClose(handle);

            nvram_query_ex_file_name(folder_idx, filename, fullfilename);

            retval = FS_Delete(fullfilename);
            if (retval != FS_NO_ERROR)
            {
                return KAL_FALSE;
            }
        }
        else
        {
            break;
        }
    }
#endif /* __LOW_COST_SUPPORT_ULC__ */

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_delete_all_nvram_files
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_bool nvram_delete_all_nvram_files(nvram_bootup_enum bootup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 loop_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_trace(TRACE_FUNC, FUNC_NVRAM_DELETE_ALL_NVRAM_FILES, bootup_type);
    switch (bootup_type)
    {
        case NVRAM_FIRST_BOOTUP:
        {
            for (loop_idx = NVRAM_FOLDER_TOTAL - 1; loop_idx >= NVRAM_FOLDER_BEGIN; loop_idx--)                
            {
                nvram_delete_certain_folder(loop_idx);
            }
            break;
        }

        case NVRAM_NORMAL_BOOTUP:
        {
            nvram_delete_certain_folder(NVRAM_NVD_DATA);
        #if !defined(__CCCIFS_SUPPORT__)
        #ifdef __NVRAM_MULTI_FOLDERS__
            nvram_delete_certain_folder(NVRAM_NVD_CALI);
        #endif /* __NVRAM_MULTI_FOLDERS__ */
        #endif
            break;
        }
        
        default:
            break;
    }

    return KAL_TRUE;
}


