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
 * Filename:
 * ---------
 * nvram_drval_fat.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is Driver adaption level functions.
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

/***************************************************************************** 
* Include
*****************************************************************************/

#include "stdio.h"
#include "string.h"
#include "stdarg.h"

#include "kal_general_types.h"
#include "kal_public_api.h"

#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "nvram_main.h"


#if defined(__MTK_TARGET__)
#include "SST_secure.h"
#endif
/*****************************************************************************
* Define
*****************************************************************************/

/*****************************************************************************
* Global Variable
*****************************************************************************/
extern kal_mutexid g_nvram_fs_mutex;

#ifdef __NVRAM_WRITE_WITH_FILE_SIZE__
extern kal_bool bResetNvramData;
#endif
/*****************************************************************************
* Local Variable
*****************************************************************************/

static kal_int32 nvram_fat_last_err;
static kal_uint32 nvram_fat_last_line;


#ifndef __MTK_TARGET__  /* Simulate by nvram on MODIS */
void SST_Secure_Algo (kal_uint8 Direction, kal_uint32 ContentAddr,
                             kal_uint32 ContentLen, kal_uint8 *CustomSeed,
                             kal_uint8 *ResText)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *source = (kal_uint8 *) ContentAddr;
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((ContentAddr & 0x03) != 0)
    {
        ASSERT(0);
    }

    if (NVRAM_MSP_ALIGNMENT_REMAINDER(ContentLen) != 0)
    {
        ASSERT(0);
    }

    for (i = 0 ;i < ContentLen; i ++)
    {
        *(ResText+i) = *(source+i) ^ i;
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  nvram_fat_last_err
 * DESCRIPTION
 *  get the last error in nvram drv fat
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
kal_int32 nvram_drv_fat_get_last_err(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return nvram_fat_last_err;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_fat_last_line
 * DESCRIPTION
 *  get the last error in nvram drv fat
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
kal_uint32 nvram_drv_fat_get_last_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return nvram_fat_last_line;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_init
 * DESCRIPTION
 *  This is nvram_drv_fat_init() function of NVRAM module.
 * PARAMETERS
 *  void
 * RETURNS
 *  if NVRAM folder does not exist, it means the FAT is empty.
 *****************************************************************************/
nvram_drv_status_enum nvram_drv_fat_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE hFile;
    nvram_folder_enum i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (nvram_check_first_bootup_log("FAT"))
    {
        return NVRAM_DRV_UNFORMATTED;
    }

    NVRAM_FS_MAKE_ROOT_PATH(filename);

    hFile = FS_Open((const kal_wchar*)filename, FS_READ_ONLY | FS_OPEN_DIR);

    if (hFile == FS_FILE_NOT_FOUND || hFile == FS_PATH_NOT_FOUND)
    {
        return NVRAM_DRV_UNFORMATTED;
    }
    else if (hFile == FS_FDM_USER_DRIVE_BROKEN ||
             hFile == FS_FDM_SYS_DRIVE_BROKEN ||
             hFile == FS_FDM_MULTIPLE_BROKEN)
    {
        return NVRAM_DRV_DRIVE_BROKEN;
    }
    else if (hFile == FS_FDM_VERSION_MISMATCH)
    {
        return NVRAM_DRV_DRIVE_VNOERR;
    }
    else if (hFile >= FS_NO_ERROR)   /* Success */
    {
        FS_Close(hFile);
    }
    else
    {
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_DRV_FAT_THROW_EXCEPTION, hFile, __LINE__);
		EXT_ASSERT(KAL_FALSE, (kal_uint32) hFile, NVRAM_LOC_OPEN_NV_FOLDER_FAIL, 0);
        return NVRAM_DRV_FATAL_ERROR;
    }


    for (i = NVRAM_FOLDER_BEGIN; i < NVRAM_FOLDER_TOTAL; i++)
    {
        kal_wsprintf(filename, "%s", nvram_query_work_path(i));

        if (FS_NO_ERROR > FS_GetAttributes(filename))
        {
            return NVRAM_DRV_FOLDER_NOT_READY;
        }
    }
 
    g_nvram_fs_mutex = kal_create_mutex("NVFS");

    return NVRAM_DRV_OK;

}


/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_init
 * DESCRIPTION
 *  This is nvram_drv_fat_init() function of NVRAM module.
 * PARAMETERS
 *  void
 * RETURNS
 *  if NVRAM folder does not exist, it means the FAT is empty.
 *****************************************************************************/
nvram_drv_status_enum nvram_drv_fat_init_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[NVRAM_MAX_PATH_LEN];
    kal_int32 Ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    Ret = NVRAM_FS_GET_FULL_PATH_LEN;

    nvram_create_first_bootup_log("FAT");

    /* check nvram root folder, if not exist, create it! */
    NVRAM_FS_MAKE_ROOT_PATH(filename);

    if (FS_NO_ERROR > FS_GetAttributes(filename))
    {
        Ret = FS_CreateDir((const kal_wchar*)filename);
       nvram_trace(TRACE_FUNC, FUNC_NVRAM_DRV_FAT_THROW_EXCEPTION, Ret, __LINE__);
    }

    nvram_create_all_folder();

    return NVRAM_DRV_OK;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_init
 * DESCRIPTION
 *  This is nvram_drv_fat_init() function of NVRAM module.
 * PARAMETERS
 *  void
 * RETURNS
 *  if NVRAM folder does not exist, it means the FAT is empty.
 *****************************************************************************/
nvram_drv_status_enum nvram_drv_fat_init_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_delete_first_bootup_log("FAT");

    return NVRAM_DRV_OK;
}



/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_format
 * DESCRIPTION
 *  Dummy format function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_drv_fat_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Folder is ready as init, nothing to do in format */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_nvram_drv_fat_backup
 * DESCRIPTION
 *  To make a backup.
 * PARAMETERS
 *  prefix           [IN]         file prefix
 *  verno            [IN]         file verno
 *  a_to_b           [IN]         direction
 * RETURNS
 *  error code
 *****************************************************************************/
kal_int32 nvram_drv_fat_backup(nvram_ltable_entry_struct *ldi, kal_bool a_to_b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar src_path[NVRAM_MAX_PATH_LEN], dest_path[NVRAM_MAX_PATH_LEN];
    NVRAM_FILE_NAME nvramname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (a_to_b)
    {
        nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);  // A
        nvram_query_file_name(nvram_query_folder_index_ex(ldi->category, KAL_TRUE), nvramname, src_path);

    #ifdef __NVRAM_BACKUP_DISK_FAT__
        if (NVRAM_IS_ATTR_BACKUP_FAT(ldi->attr))
        {
            nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);
            nvram_query_file_name(NVRAM_NVD_BAK, nvramname, dest_path);
        }
        else
    #endif
        {
            nvram_util_make_lid_filename(ldi, nvramname, KAL_FALSE); // B
            nvram_query_file_name(nvram_query_folder_index_ex(ldi->category, KAL_FALSE), nvramname, dest_path);
        }
    }
    else
    {
    #ifdef __NVRAM_BACKUP_DISK_FAT__
        if (NVRAM_IS_ATTR_BACKUP_FAT(ldi->attr))
        {
            nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);
            nvram_query_file_name(NVRAM_NVD_BAK, nvramname, src_path);
        }
        else
    #endif
        {
            nvram_util_make_lid_filename(ldi, nvramname, KAL_FALSE);  // B
            nvram_query_file_name(nvram_query_folder_index_ex(ldi->category, KAL_FALSE), nvramname, src_path);

        }

        nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);  // A
        nvram_query_file_name(nvram_query_folder_index_ex(ldi->category, KAL_TRUE), nvramname, dest_path);
    }

#ifndef __LOW_COST_SUPPORT_ULC__

//    FS_SetAttributes(dest_path, 0);
    FS_Delete(dest_path);

    return FS_Move(src_path, dest_path, FS_MOVE_COPY, NULL, NULL, 0);
#else
    {
        FS_HANDLE src, dest;

        src = FS_Open(src_path, FS_READ_ONLY);
        dest = FS_Open(dest_path, FS_READ_WRITE | FS_CREATE_ALWAYS);

        if (src >= FS_NO_ERROR && dest >= FS_NO_ERROR)
        {
            kal_int32 ret = 0;
            kal_uint32 len;
            kal_uint8 *buf = (kal_uint8 *)get_ctrl_buffer(MAX_NVRAM_RECORD_SIZE);

            while ((ret == FS_NO_ERROR) &&
                   (ret = FS_Read(src, buf, MAX_NVRAM_RECORD_SIZE, &len)) >= FS_NO_ERROR &&
                   (len > 0))
            {
                ret = FS_Write(dest, buf, len, &len);
            }
            nvram_fat_last_err = ret;
            nvram_fat_last_line = __LINE__;
            FS_Close(src);
            FS_Close(dest);
            free_ctrl_buffer(buf);
            return ret;
        }
        else
        {
            if (src < FS_NO_ERROR)
                return src;
            else
                return dest;
        }
    }
#endif
}

#if defined(__NVRAM_FS_OPERATION_COMPACT__)&& defined(__CCCIFS_SUPPORT__) && defined(__MTK_TARGET__)
/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_read_section_cmpt
 * DESCRIPTION
 *  read record(s) from FAT.
 * PARAMETERS
 *  hFile               [IN]         file handle
 *  rec_index           [IN]         which record to read (start)
 *  rec_amount          [IN]         how many record to read at once
 *  rec_size            [IN]         size of record
 *  buffer              [IN/OUT]     buffer of check sum
 *  type                [IN]         read content or checksum
 *  ismsp               [IN]         to indicate that the records protected by hw
 * RETURNS
 *  = 0: success
 *  > 0: NVRAM error code
 *  < 0: FS error code
 *****************************************************************************/
kal_int32 nvram_drv_fat_read_section_cmpt(
            FS_HANDLE hFile,
            kal_uint16 rec_index,
            kal_uint16 rec_amount,
            kal_uint32 rec_size,
            kal_uint8 *buffer,
            nvram_drv_read_type_enum type,
            nvram_attr_enum attr,
			kal_wchar *filename,
            NVRAM_FS_PARAM_CMPT_T *nvram_param
			)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 chksum1 = 0, chksum2 = 0, chksum3 = 0;
    kal_uint32 len = 0, remainLen = 0;
    kal_uint32 section_size;
    kal_uint32 working_buffer_size;
    kal_uint8 *working_buffer = NULL;
    kal_int32 result = NVRAM_DRV_OK;
    kal_uint32 i,j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
    if (attr & NVRAM_ATTR_MSP)
    {
        /* 16 byte alignment */
        remainLen = NVRAM_MSP_ALIGNMENT_REMAINDER(rec_size + NVRAM_CHKSUM_SIZE);
    }
#endif

    section_size = rec_size + NVRAM_CHKSUM_SIZE + remainLen;

    nvram_param->opid_map |= NVRAM_FS_CMPT_SEEK;
    nvram_param->Offset = (rec_index - 1) * section_size;
    nvram_param->Whence = FS_FILE_CURRENT;

	/*
    //working_buffer_size = MAX_NVRAM_RECORD_SIZE;        
    //MAX_NVRAM_RECORD_SIZE = (NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM * NVRAM_RECORD_SECTOR_SIZE)
    //                      = (128 0r 16 or 4) * 512
	*/

    working_buffer_size = section_size * rec_amount;
    if (working_buffer_size > MAX_NVRAM_RECORD_SIZE)
    {
        working_buffer_size = MAX_NVRAM_RECORD_SIZE;
    }
    
    working_buffer = (kal_uint8*) get_ctrl_buffer(working_buffer_size);


	{
    kal_int32 rec_in_block = working_buffer_size / section_size;

    for (i = 0 ; i < rec_amount; )
    {
 	    kal_uint32 total_read = section_size * rec_in_block;
 	    kal_uint32 working_buffer_sub_index = 0;

        /* last read */
        if (rec_in_block > rec_amount - i)
        {
            rec_in_block = rec_amount - i;
        }
		
 	    #define NVRAM_MAX_READ_LEN (3*1024)
		
 	    do 
 	    {
 	        kal_uint32 this_read = total_read;
			
 	        if (total_read >= NVRAM_MAX_READ_LEN)
 	        {
 	            this_read = NVRAM_MAX_READ_LEN;
 	        }

			nvram_param->opid_map |= NVRAM_FS_CMPT_READ;
			/*
			1, will be a full process: fs_open() ==> fs_seek(, offsert) ==> fs_read() ==> fs_close()
			2, offset should be right
			*/
			nvram_param->Offset += (len + i*(section_size * rec_in_block));
			nvram_param->DataPtr = (working_buffer + working_buffer_sub_index);
			nvram_param->Length = this_read;
			nvram_param->Read = &len;								
			nvram_param->opid_map |= NVRAM_FS_CMPT_CLOSE;
			
			result = FS_CMPT_Read(filename, nvram_param);
            
			if (nvram_param->opid_map != nvram_param->ret[0])
			{
				nvram_fat_last_err = nvram_param->ret[1];
				nvram_fat_last_line =  __LINE__;
				goto final;
			}	
	
            if (len==0)
            {
                result = FS_INVALID_FILE_POS;  // End of File
                nvram_fat_last_line = __LINE__;
                goto final;
            }

 	        total_read -= len;
 	        working_buffer_sub_index += len;
            
 	    }while(total_read > 0);

    #ifdef __NVRAM_BIND_TO_CHIP_CIPHER__

        if (attr & NVRAM_ATTR_MSP)
        {
            for (j = 0; j < rec_in_block; j++)
            {
                /* work arround solution for hw.. sej is not stable */
            #ifdef __CCCIFS_SUPPORT__
                kal_uint8 *working_buffer2 = (kal_uint8*) get_ctrl_buffer(section_size);
                kal_uint8 *working_buffer3 = (kal_uint8*) get_ctrl_buffer(section_size);
                //copy the encrypted data from working_buffer to working_buffer2
                memcpy(working_buffer2, working_buffer + section_size * j, section_size);

                do
                {
                    nvram_trace_to_file(__LINE__, 999, 1, 0, 0 ,0);
                    nvram_trace_to_file(nvram_ptr->secret_key[0], nvram_ptr->secret_key[1], nvram_ptr->secret_key[2], nvram_ptr->secret_key[3], 0, 0);
                    nvram_trace_to_file(working_buffer[j*section_size], working_buffer[j*section_size + 1], working_buffer[j*section_size + 2], working_buffer[j*section_size + 3], 0, 0);
                    //decrypt the working_buffer
                    SST_Secure_Algo(NVRAM_MSP_DECRYPT, (kal_uint32) (working_buffer + section_size * j), section_size, nvram_ptr->secret_key, working_buffer + section_size * j);
                    nvram_trace_to_file(working_buffer[j*section_size], working_buffer[j*section_size + 1], working_buffer[j*section_size + 2], working_buffer[j*section_size + 3], 0, 0);

                    //copy decrypted data from working_buffer to working_buffer3
                    memcpy(working_buffer3, working_buffer + section_size * j, section_size);
                    //encrypt the working_buffer3
                    SST_Secure_Algo(NVRAM_MSP_ENCRYPT, (kal_uint32)working_buffer3, section_size, nvram_ptr->secret_key, working_buffer3);

                    //compare the working_buffer2 & working_buffer3
                    if (memcmp(working_buffer2, working_buffer3, section_size) == 0)
                    {
                        //decrypt PASS
                        break;
                    }
                    else
                    {
                        //decrypt FAIL, try again
                        memcpy(working_buffer + section_size * j, working_buffer2, section_size);
                    }
                }while(1);

                free_ctrl_buffer(working_buffer2);
                free_ctrl_buffer(working_buffer3);
            #else
                SST_Secure_Algo(NVRAM_MSP_DECRYPT, (kal_uint32) (working_buffer + section_size * j), section_size, nvram_ptr->secret_key, working_buffer + section_size * j);
            #endif
            }
        }
    #endif


        /* Handle multi-record reading */
        for (j = 0; j < rec_in_block; j++)
        {
            //verify checksum one at once
            chksum1 = chksum2 = 0;

            //get checksum from the working buffer
            chksum2  = *(kal_uint8*) (working_buffer + section_size * j + rec_size);
            chksum2 |= *(kal_uint8*) (working_buffer + section_size * j + rec_size + 1) << 8;

            //calculate the checksum from the content
            /* checksum from content */
            chksum1 = nvram_util_caculate_checksum(working_buffer + (section_size * j), rec_size);

            if (chksum1 != chksum2)
            {
                nvram_ptr->sw_status &= NVRAM_SW_SOME_CORRUPT;
                nvram_fat_last_line = __LINE__;
                result = NVRAM_DRV_CHECKSUM_ERROR;
                goto final;
            }
        
            if (attr & NVRAM_ATTR_CONFIDENTIAL)
            {
                custom_nvram_decrypt(nvram_ptr->secret_key, working_buffer + section_size * j, rec_size, rec_size);
            }
            //seems no need to calculate checksum3, and buffer for NVRAM_DRV_READ_TYPE_CHKSUM is useless if we do not verify the checksum?
            //if we want to compare the checksum between A & B, we need another buffer to use memcmp
            /* checksum after decrypt */
            chksum3 = nvram_util_caculate_checksum(working_buffer + (section_size * j), rec_size);

            if (type == NVRAM_DRV_READ_TYPE_DATA)
            {
                kal_mem_cpy(buffer + (rec_size * (i + j)), working_buffer + (section_size * j), rec_size);
            }
            else if  (type == NVRAM_DRV_READ_TYPE_CHKSUM)
            {
                kal_mem_cpy(buffer + (NVRAM_CHKSUM_SIZE * (i + j)), &chksum3, NVRAM_CHKSUM_SIZE);
            }
        }
        i += rec_in_block;
    }
	}

final:
    
    free_ctrl_buffer(working_buffer);

ERROR:
    if (FS_NO_ERROR > result)
    {
        nvram_fat_last_err = result;
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_DRV_FAT_THROW_EXCEPTION, nvram_fat_last_err, nvram_fat_last_line);
    }

    return result;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_read_aux
 * DESCRIPTION
 *  read record(s) from FAT.
 * PARAMETERS
 *  hFile               [IN]         file handle
 *  rec_index           [IN]         which record to read (start)
 *  rec_amount          [IN]         how many record to read at once
 *  rec_size            [IN]         size of record
 *  buffer              [IN/OUT]     buffer of check sum
 *  type                [IN]         read content or checksum
 *  ismsp               [IN]         to indicate that the records protected by hw
 * RETURNS
 *  = 0: success
 *  > 0: NVRAM error code
 *  < 0: FS error code
 *****************************************************************************/
kal_int32 nvram_drv_fat_read_section(
            FS_HANDLE hFile,
            kal_uint16 rec_index,
            kal_uint16 rec_amount,
            kal_uint32 rec_size,
            kal_uint8 *buffer,
            nvram_drv_read_type_enum type,
            nvram_attr_enum attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 chksum1 = 0, chksum2 = 0, chksum3 = 0;
    kal_uint32 len = 0, remainLen = 0;
    kal_uint32 section_size;
    kal_uint32 working_buffer_size;
    kal_uint8 *working_buffer = NULL;
    kal_int32 result = NVRAM_DRV_OK;
    kal_uint32 i,j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
    if (attr & NVRAM_ATTR_MSP)
    {
        /* 16 byte alignment */
        remainLen = NVRAM_MSP_ALIGNMENT_REMAINDER(rec_size + NVRAM_CHKSUM_SIZE);
    }
#endif

    section_size = rec_size + NVRAM_CHKSUM_SIZE + remainLen;


    /* seek to the record start */
    if (FS_NO_ERROR > (result = FS_Seek(hFile, (rec_index - 1) * section_size, FS_FILE_CURRENT)))
    {
        nvram_fat_last_line = __LINE__;
        goto ERROR;
    }

    //working_buffer_size = MAX_NVRAM_RECORD_SIZE;        
    //MAX_NVRAM_RECORD_SIZE = (NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM * NVRAM_RECORD_SECTOR_SIZE)
    //                                                    = (16 or 4) * 512
    working_buffer_size = section_size * rec_amount;
    if (working_buffer_size > MAX_NVRAM_RECORD_SIZE)
    {
        working_buffer_size = MAX_NVRAM_RECORD_SIZE;
    }
    
    working_buffer = (kal_uint8*) get_ctrl_buffer(working_buffer_size);


    {
        kal_int32 rec_in_block = working_buffer_size / section_size;

        for (i = 0 ; i < rec_amount; )
        {
     	    kal_uint32 total_read = section_size * rec_in_block;
     	    kal_uint32 working_buffer_sub_index = 0;

            /* last read */
            if (rec_in_block > rec_amount - i)
            {
                rec_in_block = rec_amount - i;
            }
			
     	    #define NVRAM_MAX_READ_LEN (3*1024)
			
     	    do 
     	    {
     	        kal_uint32 this_read = total_read;
				
     	        if (total_read >= NVRAM_MAX_READ_LEN)
     	        {
     	            this_read = NVRAM_MAX_READ_LEN;
     	        }
			    
     	        if (FS_NO_ERROR > (result = FS_Read(hFile, working_buffer + working_buffer_sub_index, this_read, &len)))
     	        {
	            nvram_fat_last_line = __LINE__;
	            goto final;
     	        }
	            
                if (len==0)
                {
                    result = FS_INVALID_FILE_POS;  // End of File
	                nvram_fat_last_line = __LINE__;
	                goto final;
                }

     	        total_read -= len;
     	        working_buffer_sub_index += len;
	            
     	    }while(total_read > 0);

        #ifdef __NVRAM_BIND_TO_CHIP_CIPHER__

            if (attr & NVRAM_ATTR_MSP)
            {
                for (j = 0; j < rec_in_block; j++)
                {
                    /* work arround solution for hw.. sej is not stable */
                #ifdef __CCCIFS_SUPPORT__
                    kal_uint8 *working_buffer2 = (kal_uint8*) get_ctrl_buffer(section_size);
                    kal_uint8 *working_buffer3 = (kal_uint8*) get_ctrl_buffer(section_size);
                    //copy the encrypted data from working_buffer to working_buffer2
                    memcpy(working_buffer2, working_buffer + section_size * j, section_size);

                    do
                    {
                        nvram_trace_to_file(__LINE__, 999, 1, 0, 0 ,0);
                        nvram_trace_to_file(nvram_ptr->secret_key[0], nvram_ptr->secret_key[1], nvram_ptr->secret_key[2], nvram_ptr->secret_key[3], 0, 0);
                        nvram_trace_to_file(working_buffer[j*section_size], working_buffer[j*section_size + 1], working_buffer[j*section_size + 2], working_buffer[j*section_size + 3], 0, 0);
                        //decrypt the working_buffer
                        SST_Secure_Algo(NVRAM_MSP_DECRYPT, (kal_uint32) (working_buffer + section_size * j), section_size, nvram_ptr->secret_key, working_buffer + section_size * j);
                        nvram_trace_to_file(working_buffer[j*section_size], working_buffer[j*section_size + 1], working_buffer[j*section_size + 2], working_buffer[j*section_size + 3], 0, 0);

                        //copy decrypted data from working_buffer to working_buffer3
                        memcpy(working_buffer3, working_buffer + section_size * j, section_size);
                        //encrypt the working_buffer3
                        SST_Secure_Algo(NVRAM_MSP_ENCRYPT, (kal_uint32)working_buffer3, section_size, nvram_ptr->secret_key, working_buffer3);

                        //compare the working_buffer2 & working_buffer3
                        if (memcmp(working_buffer2, working_buffer3, section_size) == 0)
                        {
                            //decrypt PASS
                            break;
                        }
                        else
                        {
                            //decrypt FAIL, try again
                            memcpy(working_buffer + section_size * j, working_buffer2, section_size);
                        }
                    }while(1);

                    free_ctrl_buffer(working_buffer2);
                    free_ctrl_buffer(working_buffer3);
                #else
                    SST_Secure_Algo(NVRAM_MSP_DECRYPT, (kal_uint32) (working_buffer + section_size * j), section_size, nvram_ptr->secret_key, working_buffer + section_size * j);
                #endif
                }
            }
        #endif


            /* Handle multi-record reading */
            for (j = 0; j < rec_in_block; j++)
            {
                //verify checksum one at once
                chksum1 = chksum2 = 0;

                //get checksum from the working buffer
                chksum2  = *(kal_uint8*) (working_buffer + section_size * j + rec_size);
                chksum2 |= *(kal_uint8*) (working_buffer + section_size * j + rec_size + 1) << 8;

                //calculate the checksum from the content
                /* checksum from content */
                chksum1 = nvram_util_caculate_checksum(working_buffer + (section_size * j), rec_size);

                if (chksum1 != chksum2)
                {
                    nvram_ptr->sw_status &= NVRAM_SW_SOME_CORRUPT;
                    nvram_fat_last_line = __LINE__;
                    result = NVRAM_DRV_CHECKSUM_ERROR;
                    goto final;
                }
            
                if (attr & NVRAM_ATTR_CONFIDENTIAL)
                {
                    custom_nvram_decrypt(nvram_ptr->secret_key, working_buffer + section_size * j, rec_size, rec_size);
                }
                //seems no need to calculate checksum3, and buffer for NVRAM_DRV_READ_TYPE_CHKSUM is useless if we do not verify the checksum?
                //if we want to compare the checksum between A & B, we need another buffer to use memcmp
                /* checksum after decrypt */
                chksum3 = nvram_util_caculate_checksum(working_buffer + (section_size * j), rec_size);

                if (type == NVRAM_DRV_READ_TYPE_DATA)
                {
                    kal_mem_cpy(buffer + (rec_size * (i + j)), working_buffer + (section_size * j), rec_size);
                }
                else if  (type == NVRAM_DRV_READ_TYPE_CHKSUM)
                {
                    kal_mem_cpy(buffer + (NVRAM_CHKSUM_SIZE * (i + j)), &chksum3, NVRAM_CHKSUM_SIZE);
                }
            }
            i += rec_in_block;
        }
    }



final:
    
    free_ctrl_buffer(working_buffer);

ERROR:
    if (FS_NO_ERROR > result)
    {
        nvram_fat_last_err = result;
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_DRV_FAT_THROW_EXCEPTION, nvram_fat_last_err, nvram_fat_last_line);
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_read_aux
 * DESCRIPTION
 *  read record(s) from FAT.
 * PARAMETERS
 *  filename            [IN]         full path of the data item
 *  rec_index           [IN]         which record to read (start)
 *  rec_amount          [IN]         how many record to read at once
 *  rec_size            [IN]         size of record
 *  buffer              [IN/OUT]     buffer of check sum
 *  type                [IN]         read content or checksum
 *  ismsp               [IN]         to indicate that the records protected by hw
 * RETURNS
 *  = 0: success
 *  > 0: NVRAM error code
 *  < 0: FS error code
 *****************************************************************************/
kal_int32 nvram_drv_fat_read(
            kal_char *nvramname,
            nvram_folder_enum nvram_folder,      /* folder index */
            kal_uint32 file_offset,
            kal_uint16 rec_index,
            kal_uint16 rec_amount,
            kal_uint32 rec_size,
            kal_uint8 *buffer,
            nvram_drv_read_type_enum type,
            nvram_attr_enum attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hFile = 0;
    kal_uint32 len = 0;
    kal_int32 result = 0;
    kal_wchar filename[NVRAM_MAX_PATH_LEN];

#if defined(__NVRAM_FS_OPERATION_COMPACT__) && defined(__CCCIFS_SUPPORT__) && defined(__MTK_TARGET__)
    NVRAM_FS_PARAM_CMPT_T nvram_param;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
    nvram_util_take_mutex(g_nvram_fs_mutex);
    
    do
    {
        if (rec_index < 1)
        {
            nvram_fat_last_line = __LINE__;
            result = NVRAM_DRV_INVALID_RECORD_ID;
            break;
        }

        nvram_query_file_name(nvram_folder, nvramname, filename);

#if !defined(__NVRAM_FS_OPERATION_COMPACT__) || defined(__NVRAM_PSEUDO_MERGE__) || !(defined(__CCCIFS_SUPPORT__) && defined(__MTK_TARGET__))   
        hFile = FS_Open((const kal_wchar*)filename, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED);

        if (hFile == FS_FILE_NOT_FOUND)
        {
            nvram_fat_last_line = __LINE__;
            result = NVRAM_DRV_EMPTY_RECORD;
            break;
        }
        else if (hFile <= FS_NO_ERROR)
        {
            nvram_fat_last_line = __LINE__;
            result = NVRAM_DRV_FATAL_ERROR;
            break;
        }

        /* check if a empty record */
        result = FS_GetFileSize(hFile, &len);
        if ((result == FS_NO_ERROR) && (len == 0))
        {
            nvram_fat_last_line = __LINE__;
            result = NVRAM_DRV_EMPTY_RECORD;
            break;
        }

    #ifdef __NVRAM_PSEUDO_MERGE__
        if (FS_NO_ERROR > (result = FS_Seek(hFile, file_offset, FS_FILE_BEGIN)))
        {
            nvram_fat_last_line = __LINE__;
            break;
        }
    #endif
		result = nvram_drv_fat_read_section(hFile, rec_index, rec_amount, rec_size, buffer, type, attr);
		if (hFile > FS_NO_ERROR)
	    {
	        FS_Close(hFile);
	    }
#else
		nvram_param.opid_map = 0;
		nvram_param.ret[0] = 0;
		nvram_param.ret[1] = 0;
		
        nvram_param.Flag = (FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED);
        nvram_param.opid_map |= NVRAM_FS_CMPT_OPEN;
		nvram_param.opid_map |= NVRAM_FS_CMPT_GETFILESIZE;	
		nvram_param.FileSize = &len;
		result = nvram_drv_fat_read_section_cmpt(hFile, rec_index, rec_amount, rec_size, buffer, type, attr,(const kal_wchar*)filename, &nvram_param);
#endif
    }while(0);


    nvram_util_give_mutex(g_nvram_fs_mutex);

#if !defined(__NVRAM_FS_OPERATION_COMPACT__) || defined(__NVRAM_PSEUDO_MERGE__) || !(defined(__CCCIFS_SUPPORT__) && defined(__MTK_TARGET__))
    if (result < FS_NO_ERROR)
    {
        nvram_fat_last_err = result;
        nvram_fat_last_line =  __LINE__;
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_DRV_FAT_THROW_EXCEPTION, nvram_fat_last_err, nvram_fat_last_line);
    }
#else	
	if (nvram_param.opid_map != nvram_param.ret[0])
	{
		nvram_fat_last_err = nvram_param.ret[1];
		nvram_fat_last_line =  __LINE__;
		nvram_trace(TRACE_FUNC, FUNC_NVRAM_DRV_FAT_THROW_EXCEPTION, nvram_fat_last_err, nvram_fat_last_line);

	}
#endif
	
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_read_exception_item
 * DESCRIPTION
 *  read exception record from FAT.
 * PARAMETERS
 *  buffer              [?]
 *  nvramname           [?]
 *  section_number      [IN]
 *  size                [IN]
 *  readsize            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
nvram_drv_status_enum nvram_drv_fat_read_exception_item(kal_uint8 *buffer,
                                                        kal_char *nvramname,
                                                        kal_uint16 section_number,
                                                        kal_uint32 size,
                                                        kal_uint32 readsize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE hFile = 0;
    kal_uint32 len = 0;
    kal_int32 Ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (section_number < 1)
    {
        /* kal_print("Nvram write: section_number < 1 !"); */
        return NVRAM_DRV_INVALID_RECORD_ID;
    }

    /* translate record id to filename */
    nvram_query_file_name(NVRAM_NVD_DATA, nvramname, filename);

    /* open NV_RCD.(RCD#) file */
    hFile = FS_Open((const kal_wchar*)filename, FS_READ_ONLY | FS_OPEN_NO_DIR);

    if (hFile == FS_FILE_NOT_FOUND)
    {
        return NVRAM_DRV_EMPTY_RECORD;
    }
    else if (hFile <= FS_NO_ERROR)
    {
        /* kal_print("Nvram read: FS_Open return error!"); */
        return NVRAM_DRV_FATAL_ERROR;
    }

    /* check if a empty record */
    Ret = FS_GetFileSize(hFile, &len);
    if ((Ret == FS_NO_ERROR) && (len == 0))
    {
        FS_Close(hFile);
        return NVRAM_DRV_EMPTY_RECORD;
    }

    /* seek to the record start */
    Ret = FS_Seek(hFile, (section_number - 1) * (size + sizeof(kal_uint16)), FS_FILE_BEGIN);
    if (Ret >= FS_NO_ERROR)
    {
        Ret = FS_Read(hFile, buffer, (kal_uint32) readsize, &len);
    }

    if (Ret != FS_NO_ERROR)
    {
        /* kal_print("Nvram read: Read error!"); */
        FS_Close(hFile);
        return NVRAM_DRV_CHECKSUM_ERROR;
    }

    FS_Close(hFile);
    return NVRAM_DRV_OK;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_prepare_data
 * DESCRIPTION
 *  copy data into buffer
 * PARAMETERS
 *  source:             [IN]    source data
 *  offset:             [IN]    offset in data
 *  buffer:             [OUT]   buffer
 *  buffer_size:        [IN]    size of buffer
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_drv_fat_prepare_data(kal_uint8 *buffer, const kal_uint8 *source, kal_uint32 offset, kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (source == NVRAM_EF_ZERO_DEFAULT)
    {
        kal_mem_set(buffer, 0x00, buffer_size);
    }
    else if (source == NVRAM_EF_FF_DEFAULT)
    {
        kal_mem_set(buffer, 0xFF, buffer_size);
    }
    else
    {
        kal_mem_cpy(buffer, source+offset, buffer_size);
    }
}

#ifdef __NVRAM_WRITE_WITH_FILE_SIZE__
/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_write_multiple
 * DESCRIPTION
 *  write record(s) to FAT.
 * PARAMETERS
 *  hFile               [?]
 *  buffer              [?]
 *  rec_amount          [IN]
 *  rec_size            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 nvram_drv_fat_write_multiple(
    FS_HANDLE hFile,
    const kal_uint8 *buffer,
    kal_uint16 rec_index,
    kal_uint16 rec_amount,
    kal_uint32 rec_size,
    nvram_attr_enum attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len = 0, remainLen = 0;
    kal_uint16 chksum = 0;
    kal_uint32 max_rec_amount;
    kal_uint32 section_size;
    kal_uint32 working_buffer_size;
    kal_uint8 *working_buffer = NULL;
    kal_int32 result = NVRAM_DRV_OK;
    kal_uint32 i;
	kal_uint32 rec_in_block;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
    if (attr & NVRAM_ATTR_MSP)
    {
        /* 4 byte alignment */
        remainLen = NVRAM_MSP_ALIGNMENT_REMAINDER(rec_size + NVRAM_CHKSUM_SIZE);
    }
#endif

    //16bytes alignment, limitation: msp data will be oversize 
    section_size = rec_size + NVRAM_CHKSUM_SIZE + remainLen;
	working_buffer_size = section_size * rec_amount;

	if (rec_index > 1)
    {
        if (FS_NO_ERROR > (result = FS_Seek(hFile, (rec_index - 1) * section_size, FS_FILE_CURRENT)))
        {    
            nvram_fat_last_line = __LINE__;
            goto final;
        }
    }

	if (working_buffer_size > MAX_NVRAM_RECORD_SIZE)
    {
        working_buffer_size = MAX_NVRAM_RECORD_SIZE;
    }

	working_buffer = (kal_uint8*) get_ctrl_buffer(working_buffer_size);
	max_rec_amount = working_buffer_size/section_size;
	
    if (!(attr & NVRAM_ATTR_MSP) && !(attr & NVRAM_ATTR_CONFIDENTIAL) &&
        buffer != NVRAM_EF_ZERO_DEFAULT && buffer != NVRAM_EF_FF_DEFAULT)
    {
		for(i = 0; i < rec_amount; i++)
        {
        	if (attr & NVRAM_ATTR_MULTI_DEFAULT)
        	{
        		//rec_index start from 1
        		chksum = nvram_util_caculate_checksum(buffer + (i+rec_index-1)*rec_size, rec_size);
	        	kal_mem_cpy(working_buffer + i*(rec_size + NVRAM_CHKSUM_SIZE), buffer + (i+rec_index-1)*rec_size, rec_size);				
				kal_mem_cpy(working_buffer + i*(rec_size+NVRAM_CHKSUM_SIZE)+rec_size, &chksum, NVRAM_CHKSUM_SIZE);
        	}
			else
			{
				if (i==0)
				{
					chksum = nvram_util_caculate_checksum(buffer, rec_size);
				}
				kal_mem_cpy(working_buffer + i*(rec_size+NVRAM_CHKSUM_SIZE), buffer, rec_size);				
				kal_mem_cpy(working_buffer + i*(rec_size+NVRAM_CHKSUM_SIZE)+rec_size, &chksum, NVRAM_CHKSUM_SIZE);
        	}

	        if (i == (rec_amount - 1))
            {
                if (FS_NO_ERROR > (result = FS_Write(hFile, working_buffer, section_size * rec_amount, &len)))
                {
                    nvram_fat_last_line = __LINE__;
                    goto final;
                }
            }			
		}
		goto final;
    }

    rec_in_block = 0;
    max_rec_amount = working_buffer_size / section_size;
	
    for (i = 0; i < rec_amount; i ++)
    {
        nvram_drv_fat_prepare_data(working_buffer + rec_in_block * section_size, buffer, (i+rec_index-1) * rec_size, rec_size);
		
        if (attr & NVRAM_ATTR_CONFIDENTIAL)
        {
            custom_nvram_encrypt(nvram_ptr->secret_key, working_buffer + rec_in_block * section_size, rec_size, rec_size);
        }

        chksum = nvram_util_caculate_checksum(working_buffer + rec_in_block * section_size, rec_size);

        kal_mem_cpy(working_buffer + rec_in_block * section_size + rec_size, &chksum, NVRAM_CHKSUM_SIZE);

        if (remainLen)
        {
            kal_mem_set(working_buffer + rec_in_block * section_size + rec_size + NVRAM_CHKSUM_SIZE , 0x00, remainLen);
        }

    #ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
        if (attr & NVRAM_ATTR_MSP)
        {
        /* this solution is only for work arround */
        #ifdef __SMART_PHONE_MODEM__
            kal_uint8 *working_buffer2 = (kal_uint8*) get_ctrl_buffer(section_size);
            kal_uint8 *working_buffer3 = (kal_uint8*) get_ctrl_buffer(section_size);
            //copy the original data from working_buffer to working_buffer2
            memcpy(working_buffer2, working_buffer + rec_in_block * section_size, section_size);

            do
            {
                nvram_trace_to_file(__LINE__, 999, 0, 0, 0, 0);
                nvram_trace_to_file(nvram_ptr->secret_key[0], nvram_ptr->secret_key[1], nvram_ptr->secret_key[2], nvram_ptr->secret_key[3], 0, 0);
                nvram_trace_to_file(working_buffer[rec_in_block*section_size], working_buffer[rec_in_block*section_size + 1], working_buffer[rec_in_block*section_size + 2], working_buffer[rec_in_block*section_size + 3], 0, 0);

                //encrypt working_buffer
                SST_Secure_Algo(NVRAM_MSP_ENCRYPT, (kal_uint32)working_buffer + rec_in_block * section_size, section_size, nvram_ptr->secret_key, working_buffer + rec_in_block * section_size);
                nvram_trace_to_file(working_buffer[rec_in_block*section_size], working_buffer[rec_in_block*section_size + 1], working_buffer[rec_in_block*section_size + 2], working_buffer[rec_in_block*section_size + 3], 0, 0);

                //copy the encrypted data from working_buffer to working_buffer3
                memcpy(working_buffer3, working_buffer + rec_in_block * section_size, section_size);
                //decrypt the working_buffer3
                SST_Secure_Algo(NVRAM_MSP_DECRYPT, (kal_uint32)working_buffer3, section_size, nvram_ptr->secret_key, working_buffer3);

                //compare the data between the working_buffer2 & working_buffer3
                if (memcmp(working_buffer2, working_buffer3, section_size) == 0)
                {
                    //encrypt PASS
                    break;
                }
                else
                {
                    //encrypt FAIL, try again, WTF
                    memcpy(working_buffer + rec_in_block * section_size, working_buffer2, section_size);
                }
            }while(1);

            free_ctrl_buffer(working_buffer2);
            free_ctrl_buffer(working_buffer3);
        #else
            SST_Secure_Algo(NVRAM_MSP_ENCRYPT, (kal_uint32)working_buffer + rec_in_block * section_size, section_size, nvram_ptr->secret_key, working_buffer + rec_in_block * section_size);

        #endif
        }
    #endif

        /* if this is not multi default, no need to prepare data anymore */
        if (!(attr & NVRAM_ATTR_MULTI_DEFAULT))
        {
            break;
        }

        rec_in_block ++;

        if (rec_in_block == max_rec_amount || i == rec_amount - 1)
        {
            if (FS_NO_ERROR > (result = FS_Write(hFile, working_buffer, section_size * rec_in_block, &len)))
            {
                nvram_fat_last_line = __LINE__;
                goto final;
            }
            rec_in_block = 0;
        }
    }

    /* special handling for not multi default */
    if (!(attr & NVRAM_ATTR_MULTI_DEFAULT))
    {
        if (rec_amount > 1)
        {
            for (i = 1; i < max_rec_amount && i < rec_amount; i++)
            {
                kal_mem_cpy(working_buffer + section_size * (i+rec_index-1), working_buffer, section_size);
            }
        }

		if (FS_NO_ERROR > (result = FS_Write(hFile, working_buffer, section_size * rec_amount, &len)))
        {
            nvram_fat_last_line = __LINE__;
            goto final;
        }
    }

final:

    if (working_buffer)
    {
        free_ctrl_buffer(working_buffer);
    }

    if (FS_NO_ERROR > result)
    {
        nvram_fat_last_err = result;
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_DRV_FAT_THROW_EXCEPTION, nvram_fat_last_err, nvram_fat_last_line);
        return result;
    }
    
    return NVRAM_DRV_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_write_section
 * DESCRIPTION
 *  write record(s) to FAT.
 * PARAMETERS
 *  buffer              [?]
 *  nvramname           [?]
 *  section_number      [IN]
 *  size                [IN]
 *  initialize          [IN]        true for reset, false for normal write.
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 nvram_drv_fat_write_section(
    FS_HANDLE hFile,
    const kal_uint8 *buffer,
    kal_uint16 rec_index,
    kal_uint16 rec_amount,
    kal_uint32 rec_size,
    nvram_attr_enum attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len = 0, remainLen = 0;
    kal_uint16 chksum = 0;
    kal_uint32 max_rec_amount;
    kal_uint32 section_size;
    kal_uint32 working_buffer_size;
    kal_uint8 *working_buffer = NULL;
    kal_int32 result = NVRAM_DRV_OK;
    kal_uint32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
    if (attr & NVRAM_ATTR_MSP)
    {
        /* 4 byte alignment */
        remainLen = NVRAM_MSP_ALIGNMENT_REMAINDER(rec_size + NVRAM_CHKSUM_SIZE);
    }
#endif

    section_size = rec_size + NVRAM_CHKSUM_SIZE + remainLen;
    
    if (rec_index > 1 && rec_amount == 1)
    {
        if (FS_NO_ERROR > (result = FS_Seek(hFile, (rec_index - 1) * section_size, FS_FILE_CURRENT)))
        {
    
            nvram_fat_last_line = __LINE__;
            goto final;
        }
    }

    /* we can write data into FS directly, we don't need another buffer*/
    if (!(attr & NVRAM_ATTR_MSP) && !(attr & NVRAM_ATTR_CONFIDENTIAL) &&
    	#if defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__)
    	  !(attr & NVRAM_ATTR_COMMITTED) && !(attr & NVRAM_ATTR_AUTO_RECOVER) &&   /* exclude NVRAM_EF_IMPT_COUNTER_LID */
      #endif  
        buffer != NVRAM_EF_ZERO_DEFAULT && buffer != NVRAM_EF_FF_DEFAULT)
    {

        for(i = 0;i < rec_amount;i++)
        {
            if (i == 0 || (attr & NVRAM_ATTR_MULTI_DEFAULT))
            {
                chksum = nvram_util_caculate_checksum(buffer + i * rec_size, rec_size);
            }

            if (attr & NVRAM_ATTR_MULTI_DEFAULT)
            {
                if (FS_NO_ERROR > (result = FS_Write(hFile, (void *)(buffer + i * rec_size), rec_size, &len)))
                {
                    nvram_fat_last_line = __LINE__;
                    goto final;
                }
            }
            else
            {
                if (FS_NO_ERROR > (result = FS_Write(hFile, (void *)buffer, rec_size, &len)))
                {
                    nvram_fat_last_line = __LINE__;
                    goto final;
                }
            }

            if (FS_NO_ERROR > (result = FS_Write(hFile, &chksum, NVRAM_CHKSUM_SIZE, &len)))
            {
                    nvram_fat_last_line = __LINE__;
                goto final;
            }
        }
        goto final;
    }

    //working_buffer_size = MAX_NVRAM_RECORD_SIZE;
    //MAX_NVRAM_RECORD_SIZE = (NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM * NVRAM_RECORD_SECTOR_SIZE)
    //                                                    = (16 or 4) * 512
    working_buffer_size = section_size * rec_amount;
    if (working_buffer_size > MAX_NVRAM_RECORD_SIZE)
    {
        working_buffer_size = MAX_NVRAM_RECORD_SIZE;
    }

    working_buffer = (kal_uint8*) get_ctrl_buffer(working_buffer_size);

#ifdef __NVRAM_LARGE_RECORD_SIZE__
    /* size too large , we need to operate block by block */
    if (section_size > working_buffer_size)
    {
        /* we need to prepare extra working buffer;
           and due to msp need 16-bytes alignment, therefore
           we set the working buffer to 16-bytes alignment also */
        kal_uint16 tmpchksum = 0;
        kal_int32 reserve_buffer_size = 0;
        kal_int32 j;

        working_buffer_size = NVRAM_MSP_ALIGNMENT_FLOOR(working_buffer_size) - NVRAM_MSP_ALIGNMENT;
        reserve_buffer_size = NVRAM_MSP_ALIGNMENT;

        for (i = 0 ; i < rec_amount; i++)
        {
            for (j = 0; j < rec_size; j += working_buffer_size)
            {
                kal_int32 byte_in_block = rec_size - j;
                kal_bool last_block = KAL_FALSE;

                if (byte_in_block > working_buffer_size)
                {
                    byte_in_block = working_buffer_size;
                    if (!(attr & NVRAM_ATTR_MULTI_DEFAULT))
                    {
                        nvram_drv_fat_prepare_data(working_buffer, buffer, j, byte_in_block);
                    }
                    else
                    {
                        nvram_drv_fat_prepare_data(working_buffer, buffer, i * rec_size + j, byte_in_block);
                    }
                }
                else    /* last block */
                {
                    if (!(attr & NVRAM_ATTR_MULTI_DEFAULT))
                    {
                        nvram_drv_fat_prepare_data(working_buffer, buffer, j, byte_in_block);
                    }
                    else
                    {
                        nvram_drv_fat_prepare_data(working_buffer, buffer, i * rec_size + j, byte_in_block);
                    }
                    last_block = KAL_TRUE;
                }

                if (attr & NVRAM_ATTR_CONFIDENTIAL)
                {
                    custom_nvram_encrypt(nvram_ptr->secret_key, working_buffer, byte_in_block, rec_size);
                }

                if (i == 0 || attr & NVRAM_ATTR_MULTI_DEFAULT)
                {
                    if (j == 0)
                    {
                        chksum = 0;
                    }
                    tmpchksum = nvram_util_caculate_checksum(working_buffer, byte_in_block);
                    chksum = ((chksum & 0xFF00) + (tmpchksum & 0xFF00)) | ((chksum + tmpchksum) & 0xFF);
                }

                /* last block */
                if (last_block)
                {
                    kal_mem_cpy(working_buffer + byte_in_block, &chksum, NVRAM_CHKSUM_SIZE);
                    kal_mem_set(working_buffer + byte_in_block + NVRAM_CHKSUM_SIZE, 0, remainLen);
                    byte_in_block += (NVRAM_CHKSUM_SIZE + remainLen);
                }

            #ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
                if (attr & NVRAM_ATTR_MSP)
                {

                    SST_Secure_Algo(NVRAM_MSP_ENCRYPT, (kal_uint32)working_buffer, byte_in_block, nvram_ptr->secret_key, working_buffer);
                }
            #endif

                if (FS_NO_ERROR > (result = FS_Write(hFile, working_buffer, byte_in_block, &len)))
                {
                    nvram_fat_last_line = __LINE__;
                    goto final;
                }
            }
        }
    }
    else
#endif
    {
        kal_uint32 rec_in_block = 0;

        max_rec_amount = working_buffer_size / section_size;

        for (i = 0; i < rec_amount ; i ++)
        {
            /*
             * Write several record at once to reduce io Write
             *   case a: all remain record
             *               section_number - i
             *   case b: max record we can write in one time
             *               max_rec_amount
             *   check which case is smaller
             */

            nvram_drv_fat_prepare_data(working_buffer + rec_in_block * section_size, buffer, i * rec_size, rec_size);

            if (attr & NVRAM_ATTR_CONFIDENTIAL)
            {
                custom_nvram_encrypt(nvram_ptr->secret_key, working_buffer + rec_in_block * section_size, rec_size, rec_size);
            }

            chksum = nvram_util_caculate_checksum(working_buffer + rec_in_block * section_size, rec_size);

            kal_mem_cpy(working_buffer + rec_in_block * section_size + rec_size, &chksum, NVRAM_CHKSUM_SIZE);

            if (remainLen)
            {
                kal_mem_set(working_buffer + rec_in_block * section_size + rec_size + NVRAM_CHKSUM_SIZE , 0x00, remainLen);
            }

        #ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
            if (attr & NVRAM_ATTR_MSP)
            {

            /* this solution is only for work arround */
            #ifdef __CCCIFS_SUPPORT__
                kal_uint8 *working_buffer2 = (kal_uint8*) get_ctrl_buffer(section_size);
                kal_uint8 *working_buffer3 = (kal_uint8*) get_ctrl_buffer(section_size);
                //copy the original data from working_buffer to working_buffer2
                memcpy(working_buffer2, working_buffer + rec_in_block * section_size, section_size);

                do
                {
                    nvram_trace_to_file(__LINE__, 999, 0, 0, 0, 0);
                    nvram_trace_to_file(nvram_ptr->secret_key[0], nvram_ptr->secret_key[1], nvram_ptr->secret_key[2], nvram_ptr->secret_key[3], 0, 0);
                    nvram_trace_to_file(working_buffer[rec_in_block*section_size], working_buffer[rec_in_block*section_size + 1], working_buffer[rec_in_block*section_size + 2], working_buffer[rec_in_block*section_size + 3], 0, 0);

                    //encrypt working_buffer
                    SST_Secure_Algo(NVRAM_MSP_ENCRYPT, (kal_uint32)working_buffer + rec_in_block * section_size, section_size, nvram_ptr->secret_key, working_buffer + rec_in_block * section_size);
                    nvram_trace_to_file(working_buffer[rec_in_block*section_size], working_buffer[rec_in_block*section_size + 1], working_buffer[rec_in_block*section_size + 2], working_buffer[rec_in_block*section_size + 3], 0, 0);

                    //copy the encrypted data from working_buffer to working_buffer3
                    memcpy(working_buffer3, working_buffer + rec_in_block * section_size, section_size);
                    //decrypt the working_buffer3
                    SST_Secure_Algo(NVRAM_MSP_DECRYPT, (kal_uint32)working_buffer3, section_size, nvram_ptr->secret_key, working_buffer3);

                    //compare the data between the working_buffer2 & working_buffer3
                    if (memcmp(working_buffer2, working_buffer3, section_size) == 0)
                    {
                        //encrypt PASS
                        break;
                    }
                    else
                    {
                        //encrypt FAIL, try again, WTF
                        memcpy(working_buffer + rec_in_block * section_size, working_buffer2, section_size);
                    }
                }while(1);

                free_ctrl_buffer(working_buffer2);
                free_ctrl_buffer(working_buffer3);
            #else
                SST_Secure_Algo(NVRAM_MSP_ENCRYPT, (kal_uint32)working_buffer + rec_in_block * section_size, section_size, nvram_ptr->secret_key, working_buffer + rec_in_block * section_size);

            #endif
            }
        #endif


            /* if this is not multi default, no need to prepare data anymore */
            if (!(attr & NVRAM_ATTR_MULTI_DEFAULT))
            {
                break;
            }

            rec_in_block ++;

            if (rec_in_block == max_rec_amount || i == rec_amount - 1)
            {
                if (FS_NO_ERROR > (result = FS_Write(hFile, working_buffer, section_size * rec_in_block, &len)))
                {
                    nvram_fat_last_line = __LINE__;
                    goto final;
                }
                rec_in_block = 0;
            }
        }


        /* special handling for not multi default */
        if (!(attr & NVRAM_ATTR_MULTI_DEFAULT))
        {
            if (rec_amount > 1)
            {
                for (i = 1; i < max_rec_amount && i < rec_amount; i++)
                {
                    kal_mem_cpy(working_buffer + section_size * i, working_buffer, section_size);
                }
            }

            for (i = 0 ; i < rec_amount ; i += max_rec_amount)
            {
                rec_in_block = (rec_amount - i) > max_rec_amount ? max_rec_amount: (rec_amount - i);

                if (FS_NO_ERROR > (result = FS_Write(hFile, working_buffer, section_size * rec_in_block, &len)))
                {
                    nvram_fat_last_line = __LINE__;
                    goto final;
                }
            }
        }

    }




final:

    if (working_buffer)
    {
        free_ctrl_buffer(working_buffer);
    }

    if (FS_NO_ERROR > result)
    {
        nvram_fat_last_err = result;
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_DRV_FAT_THROW_EXCEPTION, nvram_fat_last_err, nvram_fat_last_line);
        return result;
    }
    
    return NVRAM_DRV_OK;
}

#ifdef __NVRAM_WRITE_WITH_FILE_SIZE__
/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_write_multRec
 * DESCRIPTION
 *  write record(s) to FAT,now it only used at initiation stage
 * PARAMETERS
 *  buffer              [?]
 *  nvramname           [?]
 *  section_number      [IN]
 *  size                [IN]
 *  initialize          [IN]        true for reset, false for normal write.
 * RETURNS
 *  void
 *****************************************************************************/
nvram_drv_status_enum nvram_drv_fat_write_multRec(kal_char   *nvramname,
                                          nvram_folder_enum  nvram_folder,
                                          kal_uint32 file_offset,
                                          kal_uint16 rec_index,
                                          kal_uint16 rec_amount,
                                          kal_uint32 rec_size,
                                          const kal_uint8 *buffer,
                                          nvram_attr_enum attr,
                                          kal_bool initialize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE hFile = 0;
    kal_int32 result = FS_NO_ERROR;
    kal_uint32 openOption = FS_READ_WRITE | FS_OPEN_NO_DIR;
    kal_uint32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_util_take_mutex(g_nvram_fs_mutex);
    
    do
    {
        if (rec_index < 1 || rec_amount < 1)
        {
            nvram_fat_last_line = __LINE__;
            result = NVRAM_DRV_INVALID_RECORD_ID;
            break;
        }

        /* translate record id to filename */
        nvram_query_file_name(nvram_folder, nvramname, filename);

        /* set the attribute to empty before write data
           sometime the files may be read only if the nvram lock is turn on
           ex: software update when nvram lock is turned on
           But it is not a good solution here, we should unlock it in io layer */


        openOption |= FS_CREATE;
#if (defined(__SMART_PHONE_MODEM__) || defined(__MODEM_CCCI_EXIST__)) && defined(__MTK_TARGET__)
        if (attr & NVRAM_ATTR_COMMITTED)
        {
            openOption |= FS_COMMITTED;
        }
#endif

        hFile = FS_Open((const kal_wchar*)filename, openOption);

        if (hFile == FS_FILE_NOT_FOUND)
        {
            nvram_fat_last_line = __LINE__;
            result = NVRAM_DRV_EMPTY_RECORD;
            break;
        }
        else if (hFile <= FS_NO_ERROR)
        {
            nvram_fat_last_line = __LINE__;
            result = hFile;
            break;
        }

    #ifdef __NVRAM_PSEUDO_MERGE__
        if (file_offset && FS_NO_ERROR > (result = FS_Seek(hFile, file_offset, FS_FILE_BEGIN)))
        {
            nvram_fat_last_line = __LINE__;
            break;
        }
    #endif

		result = nvram_drv_fat_write_multiple(hFile, buffer, rec_index, rec_amount, rec_size, attr);
    }while(0);


    if (hFile > FS_NO_ERROR)
    {
        FS_Close(hFile);
    }

    nvram_util_give_mutex(g_nvram_fs_mutex);
    
    /* Set the attribute back to original attribute */
    if (result < FS_NO_ERROR)
    {
        nvram_fat_last_err = result;
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_DRV_FAT_THROW_EXCEPTION, nvram_fat_last_err, nvram_fat_last_line);
    }    

    return result;
}	
#endif

/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_write
 * DESCRIPTION
 *  write record(s) to FAT.
 * PARAMETERS
 *  buffer              [?]
 *  nvramname           [?]
 *  section_number      [IN]
 *  size                [IN]
 *  initialize          [IN]        true for reset, false for normal write.
 * RETURNS
 *  void
 *****************************************************************************/
nvram_drv_status_enum nvram_drv_fat_write(kal_char   *nvramname,
                                          nvram_folder_enum  nvram_folder,
                                          kal_uint32 file_offset,
                                          kal_uint16 rec_index,
                                          kal_uint16 rec_amount,
                                          kal_uint32 rec_size,
                                          const kal_uint8 *buffer,
                                          nvram_attr_enum attr,
                                          kal_bool initialize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE hFile = 0;
    kal_int32 result = FS_NO_ERROR;
    kal_uint32 openOption = FS_READ_WRITE | FS_OPEN_NO_DIR;
    kal_uint32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_util_take_mutex(g_nvram_fs_mutex);
    
    do
    {
        if (rec_index < 1 || rec_amount < 1)
        {
            nvram_fat_last_line = __LINE__;
            result = NVRAM_DRV_INVALID_RECORD_ID;
            break;
        }

        /* translate record id to filename */
        nvram_query_file_name(nvram_folder, nvramname, filename);

        /* set the attribute to empty before write data
           sometime the files may be read only if the nvram lock is turn on
           ex: software update when nvram lock is turned on
           But it is not a good solution here, we should unlock it in io layer */


        openOption |= FS_CREATE;
        if (initialize != KAL_TRUE)
        {  
        #if !defined(_NAND_FLASH_BOOTING_) && !defined(__FS_SYSDRV_ON_NAND__)  && !defined(__EMMC_BOOTING__)                                  
            openOption |= FS_PROTECTION_MODE;   /* boot from NAND and single bank NOR don't support this */        
        #endif                                                                                                 
        }

#if defined(__CCCIFS_SUPPORT__) && defined(__MTK_TARGET__)
        if (attr & NVRAM_ATTR_COMMITTED)
        {
            openOption |= FS_COMMITTED;
        }
#endif

        hFile = FS_Open((const kal_wchar*)filename, openOption);

        if (hFile == FS_FILE_NOT_FOUND)
        {
            nvram_fat_last_line = __LINE__;
            result = NVRAM_DRV_EMPTY_RECORD;
            break;
        }
        else if (hFile <= FS_NO_ERROR)
        {
            nvram_fat_last_line = __LINE__;
            result = hFile;
            break;
        }

    #ifdef __NVRAM_PSEUDO_MERGE__
        if (file_offset && FS_NO_ERROR > (result = FS_Seek(hFile, file_offset, FS_FILE_BEGIN)))
        {
            nvram_fat_last_line = __LINE__;
            break;
        }
    #endif

        /* try to write one record in file, but found the file size is zero. strange ! */
        if (!(attr & NVRAM_ATTR_BACKUP_RAW) && 
            !initialize && 
            (result = FS_GetFileSize(hFile, &len)) == FS_NO_ERROR && 
            (len == 0))
        {
            nvram_fat_last_line = __LINE__;
            result = NVRAM_DRV_EMPTY_RECORD;
            break;
        }

        result = nvram_drv_fat_write_section(hFile, buffer, rec_index, rec_amount, rec_size, attr);
    }while(0);


    if (hFile > FS_NO_ERROR)
    {
        FS_Close(hFile);
    }

    nvram_util_give_mutex(g_nvram_fs_mutex);
    
/* Set the attribute back to original attribute */


    if (result < FS_NO_ERROR)
    {
        nvram_fat_last_err = result;
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_DRV_FAT_THROW_EXCEPTION, nvram_fat_last_err, nvram_fat_last_line);
    }    

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_get_record_size
 * DESCRIPTION
 *  get the record size.
 * PARAMETERS
 *  nvramname       [?]
 *  Hint            [?]
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 nvram_drv_fat_get_record_size(kal_char *nvramname, void *Hint, nvram_folder_enum nvram_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hFile;
    kal_wchar filename[NVRAM_MAX_PATH_LEN];
    kal_uint32 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_query_file_name(nvram_folder, nvramname, filename);
#if !defined(__NVRAM_FS_OPERATION_COMPACT__) || !(defined(__CCCIFS_SUPPORT__) && defined(__MTK_TARGET__))
    if ((hFile = FS_OpenHint(filename, FS_READ_ONLY, (FS_FileOpenHint*) Hint)) > 0)
    {
        if (FS_GetFileSize(hFile, &size) != FS_NO_ERROR)
        {
            size = 0;
        }

        FS_Close(hFile);
        return size;
    }
    else
    {
        return hFile;
    }
#else
	{
		NVRAM_FS_PARAM_CMPT_T nvram_param;
		
		nvram_util_take_mutex(g_nvram_fs_mutex);

		nvram_param.opid_map = 0;
		nvram_param.ret[0] = 0;
		nvram_param.ret[1] = 0;
		
		//FS_Open			
        nvram_param.opid_map |= NVRAM_FS_CMPT_OPEN;
		nvram_param.Flag = FS_READ_ONLY;		
		//FS_GetFileSize
		nvram_param.opid_map |= NVRAM_FS_CMPT_GETFILESIZE;
		nvram_param.FileSize = &size;
		nvram_param.DataPtr = NULL;
		nvram_param.Read = NULL;
		//FS_Close
		nvram_param.opid_map |= NVRAM_FS_CMPT_CLOSE;
		nvram_util_give_mutex(g_nvram_fs_mutex);

		FS_CMPT_Read(filename, &nvram_param);

		if (nvram_param.opid_map == nvram_param.ret[0])
		{
			return size;
		}
		else
		{
			return nvram_param.ret[1];
		}		
	}
#endif
}


#if defined(__CCCIFS_SUPPORT__) && defined(__MTK_TARGET__)

/*****************************************************************************
 * FUNCTION
 *  nvram_drv_fat_auto_recover
 * DESCRIPTION
 *  file auto-recover, only for smart phone.
 * PARAMETERS
 *  filename            [IN]         full path of the data item
 *  rec_index           [IN]         which record to read (start)
 *  rec_amount          [IN]         how many record to read at once
 *  rec_size            [IN]         size of record
 *  buffer              [IN/OUT]     buffer of check sum
 *  type                [IN]         read content or checksum
 *  ismsp               [IN]         to indicate that the records protected by hw
 * RETURNS
 *  = 0: success
 *  > 0: NVRAM error code
 *  < 0: FS error code
 *****************************************************************************/
kal_int32 nvram_drv_fat_auto_recover(
            kal_char *nvramname,
            nvram_folder_enum nvram_folder      /* folder index */
            )
            
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = 0;
    kal_wchar *filename = (kal_wchar *)get_ctrl_buffer(NVRAM_MAX_PATH_LEN * sizeof(kal_wchar));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_query_file_name(nvram_folder, nvramname, filename);
    result = MD_FS_Restore((const kal_wchar*)filename, NULL, 4);
    free_ctrl_buffer(filename);

    return result;
}
#endif




