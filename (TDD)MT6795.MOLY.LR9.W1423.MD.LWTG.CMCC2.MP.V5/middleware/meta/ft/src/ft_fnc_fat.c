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
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   ft_fnc_fat.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   FT FAT operations
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/*************************************************************************
 * FT header
 *************************************************************************/
#include "ft_msg.h"
#include "ft_private.h"
#include "ft_fnc_fat.h"
#include "svc_sap.h"
#include "ft_msgid.h"
/*************************************************************************
 * NVRAM header
 *************************************************************************/
#include "nvram_interface.h"
/*******************************************************************************
 *
 *  Dynamic allocated stack
 *
 *******************************************************************************/
#define FT_STACK_MAGIC  12345

typedef void (*FT_STACK_RELEASE_CALLBACK)(void *data, void *usr_arg);

typedef struct {
    kal_uint8   *stack;  // used to remember the FindNext calling times,not FS_HANDLE

    kal_uint16  max_node_size;
    kal_uint16  max_depth;
    kal_uint16  depth; // 1 ~ N , 0 -> empty

    kal_uint16  magic;  // used to mark if the stack is created or not.

}ft_stack_handle;

kal_uint8 ft_stack_destroy(ft_stack_handle  *p_ft_stack_hdl)
{

    if( NULL==p_ft_stack_hdl)
    {
        return 1;
    }

    // free buffer
    free_ctrl_buffer(p_ft_stack_hdl->stack);
    // reset
    kal_mem_set(p_ft_stack_hdl, 0, sizeof(ft_stack_handle));

    return 0;
}

kal_uint8 ft_stack_create(ft_stack_handle *p_ft_stack_hdl, kal_uint16  max_node_size, kal_uint16  max_depth) {

    if( NULL==p_ft_stack_hdl || 0==max_node_size || 0==max_depth ) {
        return 1;
    }

    // if un-release handle, destroy first
    if( FT_STACK_MAGIC == p_ft_stack_hdl->magic ) {
        if(ft_stack_destroy(p_ft_stack_hdl))
        {
            return 2;
        }
    }

    // allocate memory
    if( NULL == (p_ft_stack_hdl->stack=(kal_uint8 *)get_ctrl_buffer(max_node_size*max_depth)) ) {
        return 2;
    }

    // initialize
    p_ft_stack_hdl->max_node_size = max_node_size;
    p_ft_stack_hdl->max_depth = max_depth;
    p_ft_stack_hdl->depth = 0;
    p_ft_stack_hdl->magic = FT_STACK_MAGIC;

    return 0;
}

kal_uint8 ft_stack_push(ft_stack_handle *p_ft_stack_hdl, kal_uint16 cur_width) {

    if( NULL==p_ft_stack_hdl || FT_STACK_MAGIC!=p_ft_stack_hdl->magic)
    {
        return 1;
    }

    /*
       if( data_size > p_ft_stack_hdl->max_node_size ) {
       return 2;
       }
       */
    if( (p_ft_stack_hdl->depth+1) > p_ft_stack_hdl->max_depth ) {
        return 3;
    }

    p_ft_stack_hdl->depth++;

    //kal_mem_cpy(p_ft_stack_hdl->stack+p_ft_stack_hdl->max_node_size*(p_ft_stack_hdl->depth-1), data, data_size);

    (*(p_ft_stack_hdl->stack+p_ft_stack_hdl->max_node_size*(p_ft_stack_hdl->depth-1))) = cur_width;
    return 0;
}

kal_uint8 ft_stack_pop(ft_stack_handle *p_ft_stack_hdl, kal_uint16 *pWidth) {

    if( NULL==p_ft_stack_hdl || FT_STACK_MAGIC!=p_ft_stack_hdl->magic || NULL == pWidth)
    {
        return 1;
    }
    /*
       if( data_size > p_ft_stack_hdl->max_node_size ) {
       return 2;
       }
       */
    if( 1 > p_ft_stack_hdl->depth ) {
        return 3;
    }

    //kal_mem_cpy(data, p_ft_stack_hdl->stack+p_ft_stack_hdl->max_node_size*(p_ft_stack_hdl->depth-1), data_size);
    (*pWidth) = (*(p_ft_stack_hdl->stack+p_ft_stack_hdl->max_node_size*(p_ft_stack_hdl->depth-1)));

    p_ft_stack_hdl->depth--;

    return 0;
}

kal_uint16 ft_stack_get_cur_depth(ft_stack_handle *p_ft_stack_hdl) {
    if( NULL==p_ft_stack_hdl || FT_STACK_MAGIC!=p_ft_stack_hdl->magic ) {
        return 0;
    }

    return p_ft_stack_hdl->depth;
}
/*******************************************************************************
 *
 *  FAT functionality
 *
 *******************************************************************************/
#define FT_FAT_MAX_PEER_SIZE        2048
#define FT_FAT_MAX_FRAME_SIZE       FT_FAT_MAX_PEER_SIZE/64*56

/**
 * Get Disk free space
 */
kal_int32 FT_GetDiskFreeSpace(const WCHAR* pathname)
{
    FS_DiskInfo fs_diskinfo;
    kal_int32 status;
    kal_int32 cluster_size = FS_GetClusterSize(pathname[0]);
    if(FS_DRIVE_NOT_FOUND == cluster_size)
    {
        return cluster_size;
    }
    if( (status=FS_GetDiskInfo(pathname, &fs_diskinfo, FS_DI_BASIC_INFO|FS_DI_FREE_SPACE)) < 0 )
    {
        return status;
    }
    return cluster_size * fs_diskinfo.FreeClusters;
}
kal_uint8  FT_FAT_SendCnf(FT_FAT_OPERATION *ft_fat_ret, peer_buff_struct *peer_buff) {

    ilm_struct          ilm_ptr;
    FT_FAT_OPERATION    *ptrMsg;

    FT_ALLOC_MSG(&ilm_ptr,sizeof(FT_FAT_OPERATION));

    /* if ptrMsg != NULL*/
    ptrMsg = (FT_FAT_OPERATION *)ilm_ptr.local_para_ptr;

    // assign primitive id
    ptrMsg->header.ft_msg_id = FT_FAT_OPERATION_ID;

    // assign return structure
    ptrMsg->fs_handle = ft_fat_ret->fs_handle;
    ptrMsg->fat_op = ft_fat_ret->fat_op;
    ptrMsg->offset = ft_fat_ret->offset;
    ptrMsg->last_frame = ft_fat_ret->last_frame;
    ptrMsg->status = ft_fat_ret->status;

    // assign peer buffer
    if( NULL != peer_buff ) {
        ilm_ptr.peer_buff_ptr = peer_buff;
    }

    FT_SEND_MSG_TO_PC(&ilm_ptr);
    return 0;
}

WCHAR * ft_wstrnpbrk(const WCHAR *s, const WCHAR *char_set) {
    const WCHAR *p;
    kal_int32 char_set_len;
    kal_int32 i;

    if( NULL == s || NULL == char_set ) {
        return NULL;
    }

    char_set_len = kal_wstrlen(char_set);
    p = s;

    while( 0 != *p ) {
        for(i=0; i<char_set_len; i++) {
            if( *p == char_set[i] ) {
                break;
            }
        }
        // if no char match in char_set
        if( i == char_set_len ) {
            return (WCHAR *)p;
        }
        p++;
    }

    return NULL;
}

WCHAR *ft_wstrichr(const WCHAR *s, int c)
{
    WCHAR   tmp;

    // to upper case
    if( 0x61<=c && 0x7a>=c ) {
        // a(0x61)~z(0x7a) --> A(0x41)~Z(0x5a)
        c -= 0x20;
    }

    do
    {
        tmp = *s;

        // to upper case
        if( 0x61<=tmp && 0x7a>=tmp ) {
            // a(0x61)~z(0x7a) --> A(0x41)~Z(0x5a)
            tmp -= 0x20;
        }

        if (tmp == c)
            return (WCHAR*)s;

    } while (*s++);

    return (0);
}

/*-----------------------------------*/
/* Return : 0 s1 = s2                */
/*         <0 s1 is less than s2     */
/*         >0 s1 is greater than s2  */
/*-----------------------------------*/
int ft_wstrnicmp(const WCHAR *s1, const WCHAR *s2, int n)
{
    WCHAR   c1, c2;

    for(; 0!=*s1 && 0!=*s2 && n>0; s1++, s2++, n--) {

        c1 = *s1;
        c2 = *s2;

        // to upper case
        if( 0x61<=c1 && 0x7a>=c1 ) {
            // a(0x61)~z(0x7a) --> A(0x41)~Z(0x5a)
            c1 -= 0x20;
        }

        // to upper case
        if( 0x61<=c2 && 0x7a>=c2 ) {
            // a(0x61)~z(0x7a) --> A(0x41)~Z(0x5a)
            c2 -= 0x20;
        }

        if( c1 != c2 ) {
            // not match
            break;
        }
    }

    return (0>=n ? 0 : (*s1 - *s2));
}

const WCHAR * ft_wstristr(const WCHAR *s, const WCHAR *ptn) {

    if( NULL == s || NULL == ptn ) {
        return NULL;
    }

    while( NULL != (s=ft_wstrichr(s, ptn[0])) ) {
        if(!ft_wstrnicmp(s, ptn, kal_wstrlen(ptn))) {
            return s;
        }
        s++;
    }

    return NULL;
}

kal_bool  ft_IsDirectoryExist(const WCHAR *dir) {

    kal_int32   ret;

    if( NULL == dir ) {
        return KAL_FALSE;
    }

#if defined(__LOW_COST_SUPPORT_ULC__)
    if( 0 > (ret = FS_Open(dir, FS_OPEN_DIR|FS_READ_ONLY))){
        return KAL_FALSE;
    }else{
        if( FS_NO_ERROR != FS_Close(ret)){
            ASSERT(0);
        }
    }
#else
    if( 0 >= (ret=FS_GetAttributes(dir)) ) {
        return KAL_FALSE;
    }

    if(!(FS_ATTR_DIR&((kal_uint32)ret))) {
        return KAL_FALSE;
    }
#endif

    return KAL_TRUE;
}

kal_int32 ft_CreateFullDirectory(const WCHAR *pathname) {

    kal_int32   ret;
    WCHAR   *buf, *p, ch;

    if( NULL == pathname ) {
        return 1;
    }

    if( NULL == (buf=(WCHAR *)get_ctrl_buffer(sizeof(WCHAR)*(kal_wstrlen(pathname)+1))) ) {
        return 2;
    }
    kal_wstrcpy(buf, pathname);
    p = buf;

    if( KAL_TRUE != ft_IsDirectoryExist(p) ) {

        // skip drive letter
        if(!kal_wstrncmp(p+1, L":\\", 2)) {
            p += 3; // skip "C:\"
        }

        // skip '\' and '.' to find the first directory name
        while( NULL != (p=ft_wstrnpbrk(p, L"\\.")) ) {

            // find the first '\' after directory name
            if( NULL == (p=kal_wstrchr(p, L'\\')) ) {
                // no more '\' all sub directories are created.
                break;
            }

            // temporarily replace with 0
            ch = *p;
            *p = 0;

            // create directory
            if(!ft_IsDirectoryExist(buf)) {
                if( FS_NO_ERROR != (ret=FS_CreateDir(buf)) ) {
                    free_ctrl_buffer(buf);
                    return ret;
                }
            }

            // restore char
            *p = ch;
        }
    }

    free_ctrl_buffer(buf);

    return 0;
}

kal_uint8  ft_fat_fullpath_concatenate(WCHAR *fullpath, kal_uint32 fullpath_len_of_bytes, const WCHAR *subname) {

    kal_uint32  total_length;
    kal_bool    end_with_backslash;

    // get base_path length first
    total_length = kal_wstrlen(fullpath);

    // check if end with backslash
    if( L'\\' == fullpath[total_length-1] ) {
        end_with_backslash = KAL_TRUE;
    }
    else {
        end_with_backslash = KAL_FALSE;
        total_length += 1; // add '\' length
    }

    // calculate total length
    total_length += kal_wstrlen(subname) + 1; // including 0 terminator char

    if( (fullpath_len_of_bytes/sizeof(WCHAR)) < total_length ) {
        return 1;
    }

    if(!end_with_backslash) {
        kal_wstrcat(fullpath, L"\\");
    }
    kal_wstrcat(fullpath, subname);

    return 0;
}

kal_uint8  ft_fat_fullpath_extract(WCHAR *fullpath, WCHAR **pp_subname) {

    WCHAR *p;

    if( NULL == (p=kal_wstrrchr(fullpath, L'\\')) ) {
        return 1;
    }

    *p = 0;

    if( NULL != pp_subname ) {
        *pp_subname = p+1;
    }

    return 0;
}
/*  for build warning
    static void ft_fat_find_close_handle(ft_fat_dir_info  *dir_info, void *arg) {
    FS_FindClose(dir_info->fs_handle);
    }
    */
void ft_fat_free_buffer(ft_stack_handle *p_stack,WCHAR  *fullpath, WCHAR    *found)
{
    if(NULL != p_stack)
        ft_stack_destroy(p_stack);//, (FT_STACK_RELEASE_CALLBACK)ft_fat_find_close_handle, NULL);
    p_stack = NULL;

    // free fullpath
    if( NULL != fullpath ) {
        free_ctrl_buffer(fullpath);
        fullpath = NULL;
    }

    // free found
    if( NULL != found ) {
        free_ctrl_buffer(found);
        found = NULL;
    }
}

kal_uint8 ft_fat_find_file_only(ft_stack_handle *p_stack,
        const WCHAR *find_pattern,
        WCHAR   *fullpath,
        WCHAR   *found,
        FT_FAT_FIND_CALLBACK  cb, void *usr_arg)
{
    FS_HANDLE               fs_handle;
    FS_DOSDirEntry      fileinfo;
    kal_uint8           ret = FT_FAT_FIND_NOT_FOUND;


    // concatenate fullpath with file search pattern
    if(ft_fat_fullpath_concatenate(fullpath, FT_FAT_MAX_FULLPATH, find_pattern)) {
        ret = 10;
        ft_fat_free_buffer(p_stack,fullpath,found);
        return ret;
    }

    // find first file
    fs_handle = FS_FindFirst(fullpath, 0, FS_ATTR_DIR, &fileinfo, found, FT_FAT_MAX_FILENAME);

    // remove find_pattern from fullpath
    if(ft_fat_fullpath_extract(fullpath, NULL)) {
        ret = 11;
        ft_fat_free_buffer(p_stack,fullpath,found);
        return ret;
    }

    // keep finding file
    if( 0 <= fs_handle ) {

        do {
            // file found!
            ret = 0;

            // concatenate fullpath with found filename
            if(ft_fat_fullpath_concatenate(fullpath, FT_FAT_MAX_FULLPATH, found)) {
                ret = 12;
                ft_fat_free_buffer(p_stack,fullpath,found);
                return ret;
            }

            // callback
            if( 0 != cb(fullpath, &fileinfo, usr_arg) ) {
                ret = 13;
                ft_fat_free_buffer(p_stack,fullpath,found);
                return ret;
            }

            // extract path
            if(ft_fat_fullpath_extract(fullpath, NULL)) {
                ret = 14;
                ft_fat_free_buffer(p_stack,fullpath,found);
                return ret;
            }
        }while( FS_NO_ERROR == FS_FindNext(fs_handle, &fileinfo, found, FT_FAT_MAX_FILENAME) );

        // close find handle
        FS_FindClose(fs_handle);
    }

    return ret;

}
kal_uint8 ft_fat_find_first_dir(ft_stack_handle *p_stack,
        ft_fat_dir_info *p_dir_info,
        WCHAR   *fullpath,
        WCHAR   *found,
        FS_DOSDirEntry  *p_fileinfo,
        kal_bool *p_IsDirSearchGoOn)
{
    kal_uint8           ret = FT_FAT_FIND_NOT_FOUND;  // default value

    (*p_IsDirSearchGoOn) = KAL_FALSE;

    // concatenate fullpath with dir search pattern "*"
    if(ft_fat_fullpath_concatenate(fullpath, FT_FAT_MAX_FULLPATH, L"*")) {
        ret = 5;
        ft_fat_free_buffer(p_stack,fullpath,found);
        return ret;
    }
    // find first dir
    p_dir_info->fs_handle  = FS_FindFirst(fullpath, FS_ATTR_DIR, FS_ATTR_HIDDEN, p_fileinfo, found, FT_FAT_MAX_FILENAME);//update by wayne

    //  p_dir_info->fs_handle = FS_FindFirst(fullpath, FS_ATTR_DIR, 0, p_fileinfo, found, FT_FAT_MAX_FILENAME);


    //cur_width=0;


    // remove dir search pattern "*" from fullpath
    if(ft_fat_fullpath_extract(fullpath, NULL)) {
        ret = 6;
        ft_fat_free_buffer(p_stack,fullpath,found);
        return ret;
    }

    return ret;
}

kal_uint8 ft_fat_find(const WCHAR *base_path, const WCHAR *find_pattern, FT_FAT_FIND_MODE  mode, FT_FAT_FIND_CALLBACK  cb, void *usr_arg) {

    ft_stack_handle     stack;
    ft_fat_dir_info     dir_info;
    //  FS_HANDLE           fs_handle;  // for build warning
    FS_DOSDirEntry      fileinfo;

    kal_uint16    cur_width;
    kal_uint16    get_width;
    kal_uint16    i;

    kal_uint8           ret = FT_FAT_FIND_NOT_FOUND;
    kal_bool            IsDirSearchGoOn;
    kal_bool            IsSearchSubDirGoOn;
    WCHAR               *fullpath = NULL;
    WCHAR               *found = NULL;

    kal_uint8    test_ret = 0;


    if( NULL==base_path || 0==base_path[0] || NULL==find_pattern || 0==find_pattern[0] || NULL==cb ) {
        return 1;
    }

    // create fullpath buffer
    if( NULL == (fullpath=(WCHAR *)get_ctrl_buffer(FT_FAT_MAX_FULLPATH)) ) {
        ret = 2;
        goto free_buffer;
    }

    // create found buffer
    if( NULL == (found=(WCHAR *)get_ctrl_buffer(FT_FAT_MAX_FILENAME)) ) {
        ret = 3;
        goto free_buffer;
    }

    // create stack for depth first dir search
    //if(ft_stack_create(&stack, sizeof(ft_fat_dir_info), FT_FAT_MAX_DIR_DEPTH)) { //FT_FAT_MAX_DIR_DEPTH
    if(ft_stack_create(&stack,sizeof(kal_uint16), FT_FAT_MAX_DIR_DEPTH)) { //FT_FAT_MAX_DIR_DEPTH
        ret = 4;
        goto free_buffer;
    }

    // copy base_path to fullpath
    kal_wstrcpy(fullpath, base_path);

    // check find mode
    if( FT_FAT_FIND_FILE == mode ) {
        //goto file_search;
        ret = ft_fat_find_file_only(&stack,find_pattern,fullpath,found,cb,usr_arg);
    }
    else // FT_FAT_FIND_FILE_RECURSIVE  or FT_FAT_FIND_DIR_RECURSIVE
    {
        // search the first directory in the base_path == lable: dir_search
        ret = ft_fat_find_first_dir(&stack, &dir_info, fullpath, found, &fileinfo, &IsDirSearchGoOn);
        cur_width=0;
        if(ret != FT_FAT_FIND_NOT_FOUND)  goto free_buffer;

        IsSearchSubDirGoOn = KAL_FALSE;
        for(; ;)
        {

            if( 0 <= dir_info.fs_handle )
            {
                do{
                    cur_width++;

                    // if dir search go on, FindNext() again first
                    if(IsDirSearchGoOn) {
                        IsDirSearchGoOn = KAL_FALSE;
                        continue;
                    }
                    // if found is "." or ".." , skip it
                    if( !kal_wstrcmp(found, L".") || !kal_wstrcmp(found, L"..") ) {
                        continue;
                    }
                    if( FT_FAT_FIND_DIR_RECURSIVE == mode ) {
                        // dir found!
                        ret = 0;
                    }
                    //close the file handler before we push it!
                    FS_FindClose(dir_info.fs_handle);

                    // push current dir
                    cur_width--;
                    //test_ret = ft_stack_push(&stack, &dir_info, sizeof(dir_info), cur_width);
                    test_ret = ft_stack_push(&stack, cur_width);
                    if(test_ret>0)
                    {
                        if(test_ret == 1)      ret = 60;
                        else if(test_ret ==2)  ret = 61;
                        else if(test_ret ==3)  ret = 62;

                        goto free_buffer;
                    }

                    // concatenate with the found sub dir
                    if(ft_fat_fullpath_concatenate(fullpath, FT_FAT_MAX_FULLPATH, found)) {
                        ret = 8;
                        goto free_buffer;
                    }

                    // callback
                    if( 0 != cb(fullpath, &fileinfo, usr_arg) ) {
                        ret = 9;
                        goto free_buffer;
                    }

                    // find from sub dir
                    //goto dir_search;
                    if(ret != 0)
                        ret = ft_fat_find_first_dir(&stack, &dir_info, fullpath, found, &fileinfo, &IsDirSearchGoOn);
                    else
                        ft_fat_find_first_dir(&stack, &dir_info, fullpath, found, &fileinfo, &IsDirSearchGoOn);

                    cur_width=0;
                    if(ret != 0 && ret != FT_FAT_FIND_NOT_FOUND)  goto free_buffer;

                    IsSearchSubDirGoOn = KAL_TRUE;
                    break; // break the while loop
                    //goto dir_search_go_on;

                }while( FS_NO_ERROR == FS_FindNext(dir_info.fs_handle, &fileinfo, found, FT_FAT_MAX_FILENAME) );

                if(IsSearchSubDirGoOn == KAL_TRUE)
                {
                    IsSearchSubDirGoOn = KAL_FALSE;
                    continue;  // start from the for loop again

                }
                // close find handle
                FS_FindClose(dir_info.fs_handle);



            }// end of if( 0 <= dir_info.fs_handle )


            // file_search: find file
            if(FT_FAT_FIND_FILE_RECURSIVE == mode)
            {
                if(ret!= 0)
                    ret = ft_fat_find_file_only(&stack,find_pattern,fullpath,found,cb,usr_arg);
                else
                    ft_fat_find_file_only(&stack,find_pattern,fullpath,found,cb,usr_arg);

                if(ret != 0 && ret != FT_FAT_FIND_NOT_FOUND)  goto free_buffer; // error
            }


            // pop to parent dir
            if(!ft_stack_pop(&stack, &get_width)) {
                // extract fullpath to parent dir
                if(ft_fat_fullpath_extract(fullpath, NULL)) {
                    ret = 15;
                    goto free_buffer;
                }


                // open the directory after we pop it  =========================
                // concatenate fullpath with dir search pattern "*"
                if(ft_fat_fullpath_concatenate(fullpath, FT_FAT_MAX_FULLPATH, L"*")) {
                    ret = 70;
                    goto free_buffer;
                }

                //dir_info.fs_handle = FS_FindFirst(fullpath, FS_ATTR_DIR, 0, &fileinfo, found, FT_FAT_MAX_FILENAME);
                dir_info.fs_handle = FS_FindFirst(fullpath, FS_ATTR_DIR, FS_ATTR_HIDDEN , &fileinfo, found, FT_FAT_MAX_FILENAME);
                for(i=0;i<get_width;i++)
                {
                    if(FS_FindNext(dir_info.fs_handle, &fileinfo, found, FT_FAT_MAX_FILENAME) !=FS_NO_ERROR)
                    {
                        ret = 73;
                        goto free_buffer;
                    }
                }

                cur_width = get_width;

                // remove dir search pattern "*" from fullpath
                if(ft_fat_fullpath_extract(fullpath, NULL)) {
                    ret = 71;
                    goto free_buffer;
                }
                //===========================================================

                // dir search go on
                IsDirSearchGoOn = KAL_TRUE;
                //goto dir_search_go_on;
            }// end of pop up the parent dir
            else
            {
                break;  // exit the for(; ;) loop
            }
        } // end of for(; ;)


    } // end of else
free_buffer:

    ft_fat_free_buffer(&stack,fullpath,found);
    return ret;
}

static kal_bool ft_fat_check_if_path_restricted(const WCHAR *path)
{
    return nvram_check_hidden_file(path, (ft_gl_path_check_flag) ? KAL_FALSE : KAL_TRUE );
}

typedef struct {
    FT_FAT_OPERATION    *p_fat_ret;
    peer_buff_struct    **pp_peer_buff_ret;
    FT_FAT_FIND_MODE    find_mode;
}ft_fat_find_cb_arg;

static kal_int8 ft_fat_update_peer_buf(const WCHAR *fullpath, const FS_DOSDirEntry  *dos_info, ft_fat_find_cb_arg *arg) {

    kal_uint32  filesize;
    kal_uint16  pdu_length;
    kal_char    *pdu_ptr;

    // check find mode
    if( FT_FAT_FIND_DIR_RECURSIVE == arg->find_mode ) {
        // find dir mode, skip all non-dir found items
        if(!(FS_ATTR_DIR&(dos_info->Attributes))) {
            return 0;
        }
    }
    else {
        // find file mode, skip all non-file found items
        if((FS_ATTR_DIR&(dos_info->Attributes))) {
            return 0;
        }
    }

    // check path restriction
    if(ft_fat_check_if_path_restricted(fullpath)) {
        return 0;
    }

allocate_peer_buf:
    // if peer buffer is not allocated, allocate it now.
    if( NULL == *(arg->pp_peer_buff_ret) ) {
        if( NULL == (*(arg->pp_peer_buff_ret)=construct_peer_buff(FT_FAT_MAX_FRAME_SIZE, 0, 0, TD_CTRL)) ) {
            return 1;
        }
        (*(arg->pp_peer_buff_ret))->pdu_len = 0;
    }

    // data format: filesize(4bytes) + filepath(string) + '\0'

    // if data exceed limit, flush out.
    if( FT_FAT_MAX_FRAME_SIZE < ((*(arg->pp_peer_buff_ret))->pdu_len+4+((kal_wstrlen(fullpath)+1)*2)) ) {
        // set last_frame = 0
        arg->p_fat_ret->last_frame = 0;
        arg->p_fat_ret->status = FT_CNF_OK;
        // send confirm
        FT_FAT_SendCnf(arg->p_fat_ret, *(arg->pp_peer_buff_ret));

        // sleep to wait for tst flush out data
        kal_sleep_task(50);

        // allocate peer buffer again
        *(arg->pp_peer_buff_ret) = NULL;
        goto allocate_peer_buf;
    }

    pdu_ptr = get_peer_buff_pdu( *(arg->pp_peer_buff_ret), &pdu_length );

    // store filesize
    filesize = dos_info->FileSize;
    kal_mem_cpy(pdu_ptr+pdu_length, &filesize, sizeof(filesize));
    // copy filepath
    kal_mem_cpy(pdu_ptr+pdu_length+sizeof(filesize), (void *)fullpath, (kal_wstrlen(fullpath)+1)*2);
    // update pdu_len
    (*(arg->pp_peer_buff_ret))->pdu_len += ( sizeof(filesize) + (kal_wstrlen(fullpath)+1)*2 );

    return 0;
}

#define MAX_OPENED_HANDLE       32
static FS_HANDLE    g_FAT_HandleArrary[MAX_OPENED_HANDLE];

kal_int8  FT_FAT_Handle_Clear(void) {
    kal_uint16  i;
    for(i=0; i<MAX_OPENED_HANDLE; i++) {
        g_FAT_HandleArrary[i] = -1;
    }
    return 0;
}

kal_int8  FT_FAT_Handle_Add(FS_HANDLE  handle) {
    kal_uint16  i;
    for(i=0; i<MAX_OPENED_HANDLE; i++) {
        if( -1 == g_FAT_HandleArrary[i] ) {
            g_FAT_HandleArrary[i] = handle;
            return 0;
        }
    }
    return 1;
}


kal_int8  FT_FAT_Handle_Del(FS_HANDLE  handle) {
    kal_uint16  i;
    for(i=0; i<MAX_OPENED_HANDLE; i++) {
        if( handle == g_FAT_HandleArrary[i] ) {
            g_FAT_HandleArrary[i] = -1;
            return 0;
        }
    }
    return 1;
}

kal_bool  FT_FAT_Handle_IsAvailable(void) {
    kal_uint16  i;
    for(i=0; i<MAX_OPENED_HANDLE; i++) {
        if( -1 == g_FAT_HandleArrary[i] ) {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}

#if !defined(__LOW_COST_SUPPORT_ULC__)
kal_bool  FT_FAT_IsFileAlreadyOpened(const WCHAR  *filename, FS_HANDLE  *handle) {
    kal_uint16  i;
    FS_FileInfo     file_info;
    for(i=0; i<MAX_OPENED_HANDLE; i++) {
        if( -1 != g_FAT_HandleArrary[i] ) {
            // get file handel info
            if( 0 <= FS_GetFileInfo(g_FAT_HandleArrary[i], &file_info) ) {

                // compare full filename
                if(!ft_wstrnicmp(filename, (WCHAR *)file_info.FullName, kal_wstrlen(filename))) {
                    // filename is the same, this file is already opened!
                    if( NULL != handle ) {
                        *handle = g_FAT_HandleArrary[i];
                    }
                    return KAL_TRUE;
                }

            }
        }
    }
    return KAL_FALSE;
}

kal_int8  FT_FAT_CloseFileIfAlreadyOpened(const WCHAR  *filename) {
    FS_HANDLE   handle;
    // check if handle is already opened
    if( KAL_TRUE == FT_FAT_IsFileAlreadyOpened(filename, &handle) ) {
        if( FS_NO_ERROR != FS_Close(handle) ) {
            return 1;
        }
        // delete this handle from opened handle arrary
        if( 0 != FT_FAT_Handle_Del(handle) ) {
            return 2;
        }
    }
    return 0;
}
#endif

void FT_FAT_Operation(FT_FAT_OPERATION *ft_fat_op, peer_buff_struct *peer_buff_in) {

    kal_uint32  mode;
    kal_uint16  pdu_length;
    kal_char    *pdu_ptr;
    peer_buff_struct *peer_buff_ret;
    kal_uint32  finish_bytes;
    FT_FAT_OPERATION    ft_fat_ret;
    ft_fat_find_cb_arg      ft_fat_update_peer_buf_arg;
    kal_uint32  filesize;
    WCHAR *w_filepath_1;
    WCHAR *w_filepath_2;
    FT_FAT_DiskInfo_T   DiskInfo;
    FS_DiskInfo         fs_diskinfo;
    //kal_uint8 folder_total_amount;
    //kal_uint8 folder_idx;

    // initialize
    pdu_length = 0;
    pdu_ptr = NULL;
    peer_buff_ret = NULL;
    kal_mem_set(&ft_fat_ret, '\0', sizeof(FT_FAT_OPERATION));

    if( NULL != peer_buff_in ) {
        pdu_ptr = get_peer_buff_pdu( peer_buff_in, &pdu_length );
    }

    ft_fat_ret.fat_op = ft_fat_op->fat_op;
    ft_fat_ret.status = FT_CNF_FAIL;
    switch((int)ft_fat_op->fat_op) {
        case FT_FAT_OP_OPEN|FT_FAT_OP_READ:
        case FT_FAT_OP_OPEN|FT_FAT_OP_WRITE:
            if( NULL != peer_buff_in && 0 < pdu_length ) {

                // check if filepath too long
                if( FT_FAT_MAX_FULLPATH < pdu_length ) {
                    ft_fat_ret.status = FT_FAT_ERR_PATH_TOO_LONG;
                    break;
                }

                // cast to WCHAR
                w_filepath_1 = (WCHAR *)pdu_ptr;

                // check path restriction
                if(ft_fat_check_if_path_restricted(w_filepath_1)) {
                    ft_fat_ret.status = FT_FAT_ERR_PATH_RESTRICTION;
                    break;
                }

                // create dir
                if( 0 != (ft_fat_ret.status=ft_CreateFullDirectory(w_filepath_1)) ) {
                    break;
                }

                if( (FT_FAT_OP_OPEN+FT_FAT_OP_WRITE) == ft_fat_ret.fat_op ) {
                    mode = FS_CREATE_ALWAYS;
                }
                else {
                    mode = FS_READ_ONLY;
                }

#if !defined(__LOW_COST_SUPPORT_ULC__)
                // close file if it is already opened
                FT_FAT_CloseFileIfAlreadyOpened(w_filepath_1);
#endif

                // check if file handle available
                if( KAL_TRUE != FT_FAT_Handle_IsAvailable() ) {
                    ft_fat_ret.status = FS_TOO_MANY_FILES;
                    break;
                }

                if( 0 <= (ft_fat_ret.status=FS_Open(w_filepath_1, mode)) ) {
                    // assign file handle
                    ft_fat_ret.fs_handle = ft_fat_ret.status;
                    // ok
                    ft_fat_ret.status = FT_CNF_OK;
                    // add this handle into opened handle arrary
                    FT_FAT_Handle_Add(ft_fat_ret.fs_handle);
                    // send confirm
                    break;
                }
            }
            break;
        case FT_FAT_OP_READ:
            ft_fat_ret.fs_handle = ft_fat_op->fs_handle;
            ft_fat_ret.offset = ft_fat_op->offset;
            ft_fat_ret.last_frame = 0;
            if( 0 <= (ft_fat_ret.status=FS_Seek(ft_fat_ret.fs_handle, ft_fat_ret.offset, FS_FILE_BEGIN))) {
                finish_bytes = 0;
                if( NULL != (peer_buff_ret=construct_peer_buff(FT_FAT_MAX_FRAME_SIZE, 0, 0, TD_CTRL)) ) {

                    pdu_ptr = get_peer_buff_pdu( peer_buff_ret, &pdu_length );

                    if( FS_NO_ERROR == (ft_fat_ret.status=FS_GetFileSize(ft_fat_ret.fs_handle, &filesize)) ) {

                        if( FS_NO_ERROR == (ft_fat_ret.status=FS_Read(ft_fat_ret.fs_handle, pdu_ptr, FT_FAT_MAX_FRAME_SIZE, &finish_bytes)) ) {
                            if( (finish_bytes+ft_fat_ret.offset) >= filesize ) {
                                ft_fat_ret.last_frame = 1;
                            }
                            ft_fat_ret.status = FT_CNF_OK;
                            peer_buff_ret->pdu_len = finish_bytes;
                            // send confirm
                            break;
                        }

                    }

                    // error, free buffer
                    free_peer_buff(peer_buff_ret);
                    peer_buff_ret = NULL;
                }
            }
            break;
        case FT_FAT_OP_WRITE:
            ft_fat_ret.fs_handle = ft_fat_op->fs_handle;
            ft_fat_ret.offset = ft_fat_op->offset;
            if( NULL != peer_buff_in && 0 < pdu_length ) {
                if( 0 <= (ft_fat_ret.status=FS_Seek(ft_fat_ret.fs_handle, ft_fat_ret.offset, FS_FILE_BEGIN))) {
                    finish_bytes = 0;
                    if( FS_NO_ERROR==(ft_fat_ret.status=FS_Write(ft_fat_ret.fs_handle, pdu_ptr, pdu_length, &finish_bytes)) && pdu_length==finish_bytes ) {
                        ft_fat_ret.status = FT_CNF_OK;
                        // send confirm
                        break;
                    }
                }
            }
            break;
        case FT_FAT_OP_CLOSE:
            ft_fat_ret.fs_handle = ft_fat_op->fs_handle;
            if( FS_NO_ERROR == (ft_fat_ret.status=FS_Close(ft_fat_ret.fs_handle)) ) {
                // ok
                ft_fat_ret.status = FT_CNF_OK;
                // delete this handle from opened handle arrary
                FT_FAT_Handle_Del(ft_fat_ret.fs_handle);
                // send confirm
                break;
            }
            break;
        case FT_FAT_OP_FILESIZE:
            ft_fat_ret.fs_handle = ft_fat_op->fs_handle;
            if( FS_NO_ERROR == (ft_fat_ret.status=FS_GetFileSize(ft_fat_ret.fs_handle, (kal_uint32 *)&(ft_fat_ret.offset))) ) {
                // ok
                ft_fat_ret.status = FT_CNF_OK;
                // send confirm
                break;
            }
            break;
        case FT_FAT_OP_DELETE:
            if( NULL != peer_buff_in && 0 < pdu_length ) {

                // check if filepath too long
                if( FT_FAT_MAX_FULLPATH < pdu_length ) {
                    ft_fat_ret.status = FT_FAT_ERR_PATH_TOO_LONG;
                    break;
                }

                // cast to WCHAR
                w_filepath_1 = (WCHAR *)pdu_ptr;

                // check path restriction
                if(ft_fat_check_if_path_restricted(w_filepath_1)) {
                    ft_fat_ret.status = FT_FAT_ERR_PATH_RESTRICTION;
                    break;
                }

#if !defined(__LOW_COST_SUPPORT_ULC__)
                // close file if it is already opened
                FT_FAT_CloseFileIfAlreadyOpened(w_filepath_1);
#endif
                if( FS_NO_ERROR == (ft_fat_ret.status=FS_Delete(w_filepath_1)) ) {
                    // ok
                    ft_fat_ret.status = FT_CNF_OK;
                    // send confirm
                    break;
                }
            }
            break;
        case FT_FAT_OP_MOVE:
#if defined(__LOW_COST_SUPPORT_ULC__)
            ft_fat_ret.status = FT_FAT_ERR_ACTION_NOT_SUPPORT;
#else  // non __LOW_COST_SUPPORT_LC__
            if( NULL != peer_buff_in && 0 < pdu_length ) {

                w_filepath_1 = (WCHAR *)pdu_ptr;
                w_filepath_2 = w_filepath_1+kal_wstrlen(w_filepath_1)+1;

                // check if src path too long
                if( FT_FAT_MAX_FULLPATH < (kal_wstrlen(w_filepath_1)+1)*2 ) {
                    ft_fat_ret.status = FT_FAT_ERR_PATH_TOO_LONG;
                    break;
                }

                // check if dest path too long
                if( FT_FAT_MAX_FULLPATH < (kal_wstrlen(w_filepath_2)+1)*2 ) {
                    ft_fat_ret.status = FT_FAT_ERR_PATH_TOO_LONG;
                    break;
                }

                // check path restriction
                if(ft_fat_check_if_path_restricted(w_filepath_1)) {
                    ft_fat_ret.status = FT_FAT_ERR_PATH_RESTRICTION;
                    break;
                }

                // check path restriction
                if(ft_fat_check_if_path_restricted(w_filepath_2)) {
                    ft_fat_ret.status = FT_FAT_ERR_PATH_RESTRICTION;
                    break;
                }

                // close file if it is already opened
                FT_FAT_CloseFileIfAlreadyOpened(w_filepath_1);
                FT_FAT_CloseFileIfAlreadyOpened(w_filepath_2);

                if( FS_NO_ERROR == (ft_fat_ret.status=FS_Rename(w_filepath_1, w_filepath_2)) ) {
                    // ok
                    ft_fat_ret.status = FT_CNF_OK;
                    // send confirm
                    break;
                }
            }
#endif // non __LOW_COST_SUPPORT_LC__
            break;
        case FT_FAT_OP_FIND_FILE:
        case FT_FAT_OP_FIND_FILE_RECURSIVE:
        case FT_FAT_OP_FIND_DIR_RECURSIVE:
            if( NULL != peer_buff_in && 0 < pdu_length ) {

                w_filepath_1 = (WCHAR *)pdu_ptr;
                w_filepath_2 = w_filepath_1+kal_wstrlen(w_filepath_1)+1;

                // check if base_dir too long
                if( FT_FAT_MAX_FULLPATH < (kal_wstrlen(w_filepath_1)+1)*2 ) {
                    ft_fat_ret.status = FT_FAT_ERR_PATH_TOO_LONG;
                    break;
                }

                // check if find_pattern path too long
                if( FT_FAT_MAX_FULLPATH < (kal_wstrlen(w_filepath_2)+1)*2 ) {
                    ft_fat_ret.status = FT_FAT_ERR_PATH_TOO_LONG;
                    break;
                }

                // check path restriction in file search case
                if( (FT_FAT_OP_FIND_DIR_RECURSIVE != ft_fat_op->fat_op) &&
                        ft_fat_check_if_path_restricted(w_filepath_1) ) {
                    ft_fat_ret.status = FT_FAT_ERR_PATH_RESTRICTION;
                    break;
                }

                // find
                peer_buff_ret = NULL;
                ft_fat_update_peer_buf_arg.p_fat_ret = &ft_fat_ret;
                ft_fat_update_peer_buf_arg.pp_peer_buff_ret = &peer_buff_ret;
                switch(ft_fat_op->fat_op) {
                    case FT_FAT_OP_FIND_FILE:
                        ft_fat_update_peer_buf_arg.find_mode = FT_FAT_FIND_FILE;
                        break;
                    case FT_FAT_OP_FIND_DIR_RECURSIVE:
                        ft_fat_update_peer_buf_arg.find_mode = FT_FAT_FIND_DIR_RECURSIVE;
                        break;
                    case FT_FAT_OP_FIND_FILE_RECURSIVE:
                    default:
                        ft_fat_update_peer_buf_arg.find_mode = FT_FAT_FIND_FILE_RECURSIVE;
                        break;
                }
                if( 0 == (ft_fat_ret.status=ft_fat_find(
                                w_filepath_1,
                                w_filepath_2,
                                ft_fat_update_peer_buf_arg.find_mode,
                                (FT_FAT_FIND_CALLBACK)ft_fat_update_peer_buf,
                                &ft_fat_update_peer_buf_arg)) )
                {
                    // found
                    ft_fat_ret.last_frame = 1;
                    ft_fat_ret.status = FT_CNF_OK;
                }
            }
            break;
        case FT_FAT_OP_GET_DISK_INFO:
            if( NULL != peer_buff_in && 0 < pdu_length ) {

                // cast to WCHAR
                w_filepath_1 = (WCHAR *)pdu_ptr;

                /*              // check path restriction
                                if(ft_fat_check_if_path_restricted(w_filepath_1)) {
                                ft_fat_ret.status = FT_FAT_ERR_PATH_RESTRICTION;
                                break;
                                }*/

                if( NULL != (peer_buff_ret=construct_peer_buff(sizeof(FT_FAT_DiskInfo_T), 0, 0, TD_CTRL)) ) {

                    pdu_ptr = get_peer_buff_pdu( peer_buff_ret, &pdu_length );

                    kal_mem_set(&fs_diskinfo, 0, sizeof(fs_diskinfo));
                    if( 0 <= (ft_fat_ret.status=FS_GetDiskInfo(w_filepath_1, &fs_diskinfo, FS_DI_BASIC_INFO|FS_DI_FREE_SPACE)) ) {
                        // ok
                        ft_fat_ret.status = FT_CNF_OK;
                        // fill FT_FAT_DiskInfo_T
                        DiskInfo.Type = fs_diskinfo.FATType;
                        DiskInfo.SectorsPerCluster = fs_diskinfo.SectorsPerCluster;
                        DiskInfo.TotalClusters = fs_diskinfo.TotalClusters;
                        DiskInfo.FreeClusters = fs_diskinfo.FreeClusters;
                        kal_mem_cpy(pdu_ptr, &DiskInfo, sizeof(FT_FAT_DiskInfo_T));
                        // send confirm
                        break;
                    }

                    // error, free buffer
                    free_peer_buff(peer_buff_ret);
                    peer_buff_ret = NULL;
                }
            }
            break;
        case FT_FAT_OP_RMDIR:
#if defined(__LOW_COST_SUPPORT_ULC__)
            ft_fat_ret.status = FT_FAT_ERR_ACTION_NOT_SUPPORT;
#else   // non __LOW_COST_SUPPORT_ULC__
            if( NULL != peer_buff_in && 0 < pdu_length ) {

                // check if filepath too long
                if( FT_FAT_MAX_FULLPATH < pdu_length ) {
                    ft_fat_ret.status = FT_FAT_ERR_PATH_TOO_LONG;
                    break;
                }

                // cast to WCHAR
                w_filepath_1 = (WCHAR *)pdu_ptr;

                // check path restriction
                if(ft_fat_check_if_path_restricted(w_filepath_1)) {
                    ft_fat_ret.status = FT_FAT_ERR_PATH_RESTRICTION;
                    break;
                }

                // check if directory
                if(!ft_IsDirectoryExist(w_filepath_1)) {
                    ft_fat_ret.status = FT_FAT_ERR_DIR_NOT_EXIST;
                    break;
                }

                // call FS_XDelete
                if( 0 <= (ft_fat_ret.status=FS_XDelete(w_filepath_1, FS_FILE_TYPE|FS_DIR_TYPE|FS_RECURSIVE_TYPE, NULL, 0)) ) {
                    ft_fat_ret.status = FT_CNF_OK;
                }
            }
#endif // end non __LOW_COST_SUPPORT_ULC__
            break;
        case FT_FAT_OP_GET_DRIVE_TYPE:
            {
#if defined(__LOW_COST_SUPPORT_ULC__)
                ft_fat_ret.status = FT_FAT_ERR_ACTION_NOT_SUPPORT;
#else   // non __LOW_COST_SUPPORT_ULC__
                kal_int32 DrvType; // for test
                //kal_char buf[128];  // for test
                if( NULL != peer_buff_in && 0 < pdu_length ) {

                    // cast to WCHAR
                    w_filepath_1 = (WCHAR *)pdu_ptr;
                    if( NULL != (peer_buff_ret=construct_peer_buff(sizeof(kal_int32), 0, 0, TD_CTRL)) ) {

                        pdu_ptr = get_peer_buff_pdu( peer_buff_ret, &pdu_length );
                        if( 0 < ( DrvType= FS_GetDevType(w_filepath_1))) {
                            // ok
                            kal_mem_cpy(pdu_ptr, &(DrvType), sizeof(kal_int32));
                            ft_fat_ret.status = FT_CNF_OK;

                            // send confirm
                            break;
                        }
                        else
                        {
                            ft_fat_ret.status = FT_CNF_FAIL;
                            break;
                        }

                    }
                }

                break;
#endif // end non __LOW_COST_SUPPORT_ULC__
            }
        default:
            break;
    }

    // send confirm
    ft_gl_path_check_flag = true; // re-enable the path restriction!
    FT_FAT_SendCnf(&ft_fat_ret, peer_buff_ret);
}
