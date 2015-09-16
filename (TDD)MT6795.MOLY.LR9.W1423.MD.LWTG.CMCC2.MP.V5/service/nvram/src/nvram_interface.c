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
 * nvram_interface.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   These are interface functions of NVRAM module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * Include
 */
#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_trace.h"


#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "ex_item.h"
#include "ex_public.h"
#include "sysconf_statistics.h"

#include "fs_type.h"
#include "fs_errcode.h"
#include "fs_func.h"
//MSBB remove #include "fctycomp_config.h"

#include "nvram_data_items.h"
#include "nvram_main.h"
#include "nvram_interface.h"

#include "ul1_nvram_def.h"
#include "audio_nvram_def.h"
#include "ex_nvram_def.h"
/*
 * Macro
 */
#define NVRAM_SPACE_MARGIN 10

/*
 * Local Variable
 */
static kal_uint8 nvram_exception_buffer[NVRAM_EF_SYS_EXCEPTION_SIZE];
extern kal_uint32 BytesPerCluster;  /* will be set to exact value in nvram_get_disk_file_info */
extern kal_bool stack_update_sys_statistics(stack_statistics_struct *prev_stats);

extern nvram_shutdown_cb_struct nvram_shutdown_cb_table[];

/*****************************************************************************
 * FUNCTION
 *  nvram_get_info
 * DESCRIPTION
 *  This is nvram_get_info() function of NVRAM module.
 * PARAMETERS
 *  LID         [IN]
 *  total       [?]
 *  size        [?]
 * RETURNS
 *  NVRAM_ERRNO_SUCCESS if succeed, NVRAM_ERRNO_INVALID otherwise (ie, invalid LID).
 *****************************************************************************/
nvram_errno_enum nvram_get_info(nvram_lid_enum LID, kal_uint16 *total, kal_uint16 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((nvram_ptr->state != NVRAM_STATE_READY) && !nvram_util_is_usbboot())
    {
        return NVRAM_ERRNO_FAIL;
    }

    nvram_pre_init();

    if (!NVRAM_IS_LID_VALID(LID))
    {
        return NVRAM_ERRNO_INVALID;
    }

    nvram_util_get_data_item(&ldi, LID);

    *total = ldi->total_records;
    *size = ldi->size;

    return NVRAM_ERRNO_SUCCESS;
}   /* end of nvram_get_info function */


/*****************************************************************************
 * FUNCTION
 *  nvram_write_exception
 * DESCRIPTION
 *
 * PARAMETERS
 *  length      [IN]
 *  ex_data     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_write_exception(kal_uint16 length, long *ex_data)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;
    kal_uint16 prev_num = 0;

    nvram_drv_status_enum result;
    nvram_ltable_entry_struct *ldi;

    EX_LOG_T *exception_ptr = (EX_LOG_T*) nvram_exception_buffer;
    EX_HEADER_T exception_header;

    NVRAM_FILE_NAME nvramname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ex_data == NULL)
    {
        /* kal_print("nvram_write_exception(): ex_data == NULL\n"); */
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_EXCEPTION1);
        return;
    }

    /* Length must be equal to NVRAM_EF_SYS_EXCEPTION_SIZE */
    if (length != NVRAM_EF_SYS_EXCEPTION_SIZE)
    {
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_EXCEPTION2, length, NVRAM_EF_SYS_EXCEPTION_SIZE);
        return;
    }

    /* Exception could happen even when no task is initialized */
    if (nvram_ptr->state == NVRAM_STATE_NULL)
    {
        //nvram_init(INDX_NIL);
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_EXCEPTION2, NVRAM_STATE_NULL, 1);
        return;
    }

   /**
    * Now linear searching for a free record such that ex_data could be
    * written.
    *
    * Note that if value of ex_nvram field of a exception record
    * is NOT 0xFF, then it is a valid record; otherwise it is a free
    * record.
    * Furthermore, update of exception records cannot exceeds
    * the capacity, ie, number of exception records defined in NVRAM.
    * Once the storage is full, no more exception record can be dumped.
    * Hence, as long as a free record is found, then that record and
    * other records after it could be all assumed to be free.
    */

    nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_EXCEPTION_LID);
    nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);

    for (i = 1; i <= NVRAM_EF_SYS_EXCEPTION_TOTAL; ++i)
    {
        result = nvram_drv_fat_read_exception_item(
                    (kal_uint8*) & exception_header,
                    nvramname,
                    i,
                    ldi->size,
                    sizeof(exception_header));
        /* Ok, now determine whether it is a free record */

        nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_EXCEPTION2, i, result);

        if ((result == NVRAM_DRV_OK) || (result == NVRAM_DRV_EMPTY_RECORD))
        {
            if ((exception_header.ex_nvram == (kal_uint8) NVRAM_INVALID_VALUE) || (exception_header.ex_serial_num < prev_num))  /* Found! */
            {
                break;
            }
            else
            {
                prev_num = exception_header.ex_serial_num;
            }
        }
        else    /* Error, read fail!? How come?.....Dunno what to do.. */
        {
            nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_EXCEPTION2, i, result);
            return;
        }
    }

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_EXCEPTION2, 0, 255);
    
    if (i >= NVRAM_EF_SYS_EXCEPTION_TOTAL + 1)
    {
        i = 1;
    }

    prev_num += 1;
    if (prev_num == 0xFFFF)
    {
        prev_num = 1;   /* wrap around to 1 if it reaches 65535 */
    }

   /**
    *
    * Hence the first record is the free record. Increment the serial number
    * of the last record and take it as the new serial number for free record.
    */
    exception_ptr = (EX_LOG_T*) ex_data;
    exception_ptr->header.ex_nvram = KAL_TRUE;
    exception_ptr->header.ex_serial_num = prev_num;

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_EXCEPTION2, 1, 255);

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_EXCEPTION2, ldi->LID, i);

    nvram_write_data_item(ldi, i, (kal_uint8*) ex_data, KAL_FALSE);

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_EXCEPTION2, 1, 255);

    /* Save the current statistics */
    {
        stack_statistics_struct *statistic;

        ASSERT(sizeof(stack_statistics_struct) < MAX_NVRAM_RECORD_SIZE);
		statistic = (stack_statistics_struct*) get_ctrl_buffer(NVRAM_EF_SYS_STATISTICS_SIZE);
				
        kal_mem_set(statistic, 0, NVRAM_EF_SYS_STATISTICS_SIZE);

        nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_EXCEPTION2, 2, 255);

        nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_EXCEPTION2, NVRAM_EF_SYS_STATISTICS_LID, 1);

        nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_STATISTICS_LID);
        nvram_read_data_item(ldi, 1, 1, (kal_uint8*) statistic, sizeof(statistic));

        nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_EXCEPTION2, 2, 255);
        
        if (stack_update_sys_statistics(statistic))
        {
            nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_EXCEPTION2, 3, 255);

            nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_EXCEPTION2, NVRAM_EF_SYS_STATISTICS_LID, 1);

            nvram_write_data_item(ldi, 1, (kal_uint8*) statistic, KAL_FALSE);

            nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_EXCEPTION2, 3, 255);
        }

		free_ctrl_buffer(statistic);
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_EXCEPTION2, 4, 255);
    }
}   /* end of nvram_write_exception function */


/*****************************************************************************
 * FUNCTION
 *  nvram_get_lid_num
 * DESCRIPTION
 *  To get the maxium LID
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_ptr->ltable.total_LID
  *****************************************************************************/
nvram_lid_enum nvram_get_lid_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return nvram_ptr->ltable.total_LID;

}


/*****************************************************************************
 * FUNCTION
 *  nvram_check_backup
 * DESCRIPTION
 *  To tell given LID needs to backup or not
 * PARAMETERS
 *  LID         [IN]    LID of the file
 *  prefix      [IN]    file prefix
 * RETURNS
 *  NVRAM_IO_ERRNO_OK: need to backup
 *  NVRAM_IO_ERRNO_INVALID_LID: LID out of range or don't need to backup
  *****************************************************************************/
kal_uint8 nvram_check_backup(nvram_lid_enum LID, kal_char **prefix, kal_char **verno)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!NVRAM_IS_LID_VALID(LID) || prefix == NULL)
    {
        return NVRAM_IO_ERRNO_INVALID_LID;
    }

    nvram_util_get_data_item(&ldi, LID);

    if ((NVRAM_IS_CATEGORY_CALIBRAT(ldi->category) ||
         NVRAM_IS_CATEGORY_IMPORTANT(ldi->category)||
         NVRAM_IS_CATEGORY_IMPORTANT_L4(ldi->category)) &&
        !NVRAM_IS_CATEGORY_OTP(ldi->category))
    {
    #ifdef __NVRAM_PSEUDO_MERGE__
        if (NVRAM_IS_ATTR_PACKAGE(ldi->attr))
        {
            *prefix = "PACK";
            *verno  = "LID";
        }
        else
    #endif
        {
            *prefix = ldi->fileprefix;
            *verno = ldi->fileverno;
        }
        return NVRAM_IO_ERRNO_OK;
    }
    else
    {
        *prefix = NULL;
        *verno = NULL;
        return NVRAM_IO_ERRNO_INVALID_LID;
    }


}


/*****************************************************************************
 * FUNCTION
 *  nvram_validate_file
 * DESCRIPTION
 *  To validate integrity of  the given file
 * PARAMETERS
 *  LID         [IN]    LID of the file
 *  path        [IN]    path to validate
 * RETURNS
 *  NVRAM_IO_ERRNO_OK: valid
 *  NVRAM_IO_ERRNO_INVALID_LID: LID out of range
 *  others: invalid
  *****************************************************************************/
nvram_errno_enum nvram_validate_file(nvram_lid_enum LID, kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi = NULL;
    kal_uint8 *buffer = NULL;
    kal_int32 result;
    FS_HANDLE hFile = 0;
#ifdef __NVRAM_PSEUDO_MERGE__
    kal_uint32 file_offset;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!NVRAM_IS_LID_VALID(LID))
    {
        return NVRAM_IO_ERRNO_INVALID_LID;
    }

    nvram_util_get_data_item(&ldi, LID);


#ifdef __NVRAM_PSEUDO_MERGE__
    if (NVRAM_IS_ATTR_PACKAGE(ldi->attr))
    {
        file_offset = (kal_uint32) (ldi->description);
    }
    else
    {
        file_offset = (kal_uint32) 0;
    }
#endif

    /* open NV_RCD.(RCD#) file */
    if (FS_NO_ERROR > (hFile = FS_Open((const kal_wchar*)path, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED)))
    {
        return NVRAM_IO_ERRNO_INVALID_LID;
    }

#ifdef __NVRAM_PSEUDO_MERGE__
    if (file_offset && FS_NO_ERROR > (result = FS_Seek(hFile, file_offset, FS_FILE_BEGIN)))
    {
        FS_Close(hFile);
        return NVRAM_IO_ERRNO_INVALID_LID;
    }
#endif

    buffer = (kal_uint8 *)get_ctrl_buffer(NVRAM_CHKSUM_SIZE * ldi->total_records);

    result = nvram_drv_fat_read_section(hFile, 1, ldi->total_records, ldi->size, buffer, NVRAM_DRV_READ_TYPE_CHKSUM, ldi->attr);

    free_ctrl_buffer(buffer);

    FS_Close(hFile);

    if (result != NVRAM_DRV_OK)
    {
        return NVRAM_IO_ERRNO_INVALID_LID;
    }

    return NVRAM_IO_ERRNO_OK;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_external_read_data
 * DESCRIPTION
 *  This function is used to get data items for external modules.
 * PARAMETERS
 *  LID             [IN]
 *  rec_index       [IN]
 *  buffer          [?]
 *  buffer_size     [IN]
 *  .(?)
 * RETURNS
 *  NVRAM_ERRNO_SUCCESS if succeed, NVRAM_ERRNO_INVALID otherwise (ie, invalid LID).
 *****************************************************************************/
kal_bool nvram_external_read_data(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint8 *buffer, kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi = NULL;
    nvram_errno_enum result = NVRAM_IO_ERRNO_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (nvram_ptr->state != NVRAM_STATE_READY)
    {
        return KAL_FALSE;
    }

//    nvram_pre_init();

    /**
    * Invalid input paramters.
    */
    if (!NVRAM_IS_LID_VALID(LID))
    {
        return KAL_FALSE;
    }

    nvram_util_get_data_item(&ldi, LID);

#if defined(__NVRAM_CUSTOM_SENSITIVE__) || defined(__NVRAM_CUSTOM_DISK__)
    /* In Meta mode, we cannot access the data belongs to custom sensitve area */
    if (NVRAM_IS_CATEGORY_CUSTOM_SENSITIVE(ldi->category) || NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category))
    {
        if (FACTORY_BOOT == stack_query_boot_mode() && stack_get_active_module_id() == MOD_FT)
        {
            return KAL_FALSE;
        }
    }
#endif

    if ((rec_index < 1) ||(rec_index > ldi->total_records))
    {
        return KAL_FALSE;
    }


    /* handle by nvram_io layer */
    result = nvram_read_data_item(ldi, rec_index, 1, buffer, buffer_size);

    if (result != NVRAM_IO_ERRNO_OK)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }

}

/*****************************************************************************
 * FUNCTION
 *  nvram_external_read_chksum
 * DESCRIPTION
 *  This function is used to read the checksum of data item for external module.
 *  Please must check with NVRAM owner before you use this API.
 * PARAMETERS
 *  LID:            [IN]    NVRAM LID
 *  rec_index:      [IN]    record index
 *  rec_amount:     [IN]    read how many record
 *  buffer:         [OUT]   buffer pointer
 *  buffer_size:    [IN]    buffer size
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  KAL_FALSE:  fail
 *  KAL_TRUE:   success
 *****************************************************************************/
kal_bool nvram_external_read_chksum(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint16 rec_amount, kal_uint8 *buffer, kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi = NULL;
    nvram_errno_enum result = NVRAM_IO_ERRNO_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (nvram_ptr->state != NVRAM_STATE_READY)
    {
        return KAL_FALSE;
    }

//    nvram_pre_init();

    /**
    * Invalid input paramters.
    */
    if (buffer_size < NVRAM_CHKSUM_SIZE * rec_amount)
    {
        return KAL_FALSE;
    }

    if (!NVRAM_IS_LID_VALID(LID))
    {
        return KAL_FALSE;
    }

    nvram_util_get_data_item(&ldi, LID);

#if defined(__NVRAM_CUSTOM_SENSITIVE__) || defined(__NVRAM_CUSTOM_DISK__)
    /* In Meta mode, we cannot access the data belongs to custom sensitve area */
    if (NVRAM_IS_CATEGORY_CUSTOM_SENSITIVE(ldi->category) || NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category))
    {
        if (FACTORY_BOOT == stack_query_boot_mode() && stack_get_active_module_id() == MOD_FT)
        {
            return KAL_FALSE;
        }
    }
#endif

    if ((rec_index < 1) ||(rec_index > ldi->total_records))
    {
        return KAL_FALSE;
    }


    /* handle by nvram_io layer */
    result = nvram_read_data_item_chksum(ldi, rec_index, rec_amount, (kal_uint16*)buffer, buffer_size);

    if (result != NVRAM_IO_ERRNO_OK)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }

}

/*****************************************************************************
 * FUNCTION
 *  nvram_external_write_data
 * DESCRIPTION
 *  This function is used to write data items for external modules.
 * PARAMETERS
 *  LID:            [IN]    NVRAM LID
 *  rec_index:      [IN]    record index
 *  buffer:         [IN]    buffer pointer
 *  buffer_size:    [IN]    buffer size
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  KAL_FALSE:  fail
 *  KAL_TRUE:   success
 *****************************************************************************/
kal_bool nvram_external_write_data(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint8 *buffer, kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi = NULL;
    nvram_errno_enum result = NVRAM_IO_ERRNO_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (nvram_ptr->state != NVRAM_STATE_READY)
    {
        return KAL_FALSE;
    }

//    nvram_pre_init();

    if (!NVRAM_IS_LID_VALID(LID))
    {
        return KAL_FALSE;
    }

    nvram_util_get_data_item(&ldi, LID);

#if defined(__NVRAM_CUSTOM_SENSITIVE__) || defined(__NVRAM_CUSTOM_DISK__)
    /* In Meta mode, we cannot access the data belongs to custom sensitve area */
    if (NVRAM_IS_CATEGORY_CUSTOM_SENSITIVE(ldi->category) || NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category))
    {
        if (FACTORY_BOOT == stack_query_boot_mode() && stack_get_active_module_id() == MOD_FT)
        {
            return KAL_FALSE;
        }
    }
#endif

    if ((rec_index < 1) ||
        (rec_index > ldi->total_records))
    {
        return KAL_FALSE;
    }

    if (buffer_size < ldi->size)
    {
        return KAL_FALSE;
    }

    result = nvram_write_data_item(ldi, rec_index, buffer, KAL_FALSE);

    if (result != NVRAM_IO_ERRNO_OK)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  nvram_external_reset_data
 * DESCRIPTION
 *  This function is used to reset data items for external modules.
 * PARAMETERS
 *  LID:            [IN]    NVRAM LID
 *  rec_index:      [IN]    record index
 *  buffer:         [IN]    buffer pointer
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  KAL_FALSE:  fail
 *  KAL_TRUE:   success
 *****************************************************************************/
kal_bool nvram_external_reset_data(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint16 rec_amount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi = NULL;
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (nvram_ptr->state != NVRAM_STATE_READY)
    {
        return KAL_FALSE;
    }

//    nvram_pre_init();

    if (!NVRAM_IS_LID_VALID(LID))
    {
        return KAL_FALSE;
    }

    nvram_util_get_data_item(&ldi, LID);

    /* In Meta mode, we cannot access the data belongs to custom sensitve area
       we also cannot reset the important data to prevent security problem */
    if (NVRAM_IS_CATEGORY_IMPORTANT(ldi->category)
        || NVRAM_IS_CATEGORY_IMPORTANT_L4(ldi->category)
        #if defined(__NVRAM_CUSTOM_SENSITIVE__) || defined(__NVRAM_CUSTOM_DISK__)
        || NVRAM_IS_CATEGORY_CUSTOM_SENSITIVE(ldi->category)
        || NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category)
        #endif
       )
    {
        if (FACTORY_BOOT == kal_query_boot_mode() && kal_get_active_module_id() == MOD_FT)
        {
            return KAL_FALSE;
        }
    }


    result = nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, rec_index, rec_amount);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_get_default_value
 * DESCRIPTION
 *  This function is used to get default value for external modules.
 * PARAMETERS
 *  LID             [IN]
 *  rec_index       [IN]
 *  p_buffer        [IN/OUT]
 *
 * RETURNS
 *  NVRAM_DEFAULT_VALUE_FAIL : get default value fail
 *  NVRAM_DEFAULT_VALUE_FF   : p_buffer is invalid, default value is FF
 *  NVRAM_DEFAULT_VALUE_ZERO : p_buffer is invalid, default value is zero
 *  NVRAM_DEFAULT_VALUE_POINT: p_buffer is valid, use p_buffer to get default value
 *****************************************************************************/
nvram_default_value_enum nvram_get_default_value(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint8 **p_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi = NULL;
    nvram_default_value_enum result = NVRAM_DEFAULT_VALUE_SUCCESS;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!NVRAM_IS_LID_VALID(LID))
    {
        return NVRAM_DEFAULT_VALUE_FAIL;
    }

    nvram_util_get_data_item(&ldi, LID);

    if ((rec_index < 1) || (rec_index > ldi->total_records))
    {
        return NVRAM_DEFAULT_VALUE_FAIL;
    }


    /* Multi default value */
    if ((ldi->attr & NVRAM_ATTR_MULTI_DEFAULT))
    {
        rec_index--;
    }
    else
    {
        rec_index = 0;
    }

    if ((ldi->LID >= NVRAM_EF_L1_START && ldi->LID <= NVRAM_EF_L1_END)
        || (ldi->LID >= NVRAM_EF_UL1_START && ldi->LID <= NVRAM_EF_UL1_END)
    #if defined(__WIFI_SUPPORT__)&&(__CUSTOM_WIFI_FEATURES_SWITCH__)
        || (ldi->LID >= NVRAM_EF_WNDRV_START && ldi->LID <= NVRAM_EF_WNDRV_END)
    #endif
#if !defined(MED_NOT_PRESENT)
#ifdef __AMRWB_LINK_SUPPORT__
        || (ldi->LID == NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID) || (ldi->LID == NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID) || (ldi->LID == NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID)
#endif
#ifdef __AUDIO_COMPENSATION_SW_VERSION__
        || (ldi->LID == NVRAM_EF_AUDIO_SWFIR_LID)
#endif
#ifdef __BES_LOUDNESS_SUPPORT__
        || (ldi->LID == NVRAM_EF_AUDIO_BESLOUDNESS_LID)
#endif
        || (ldi->LID == NVRAM_EF_AUDIO_DC_CALIBRATION_LID)

        || (ldi->LID == NVRAM_EF_AUDIO_PARAM_LID)
#endif
        )
    {
        result = NVRAM_DEFAULT_VALUE_APPLICATION;
    }
#ifdef __NVRAM_COMPRESS_SUPPORT__
    else if (NVRAM_IS_ATTR_ZIP_DEFAULT(ldi->attr))
    {
        result = NVRAM_DEFAULT_VALUE_FF;
    }
#endif
    else
    {
        /* No default value supplied. Fill the buffer with 0xFF. */
        if (ldi->default_value == NULL || ldi->default_value == (kal_uint8 const*)NVRAM_EF_FF_DEFAULT)
        {
            result = NVRAM_DEFAULT_VALUE_FF;
        }     /* Default value is all the same value (0x00) Fill it as well. */
        else if (ldi->default_value == (kal_uint8 const*)NVRAM_EF_ZERO_DEFAULT)
        {
            result = NVRAM_DEFAULT_VALUE_ZERO;
        }
        else
        {
            *p_buffer = (void*)(ldi->default_value + ldi->size * rec_index);
            result = NVRAM_DEFAULT_VALUE_POINT;
        }
    }
#ifdef __NVRAM_PSEUDO_MERGE__
    nvram_trace(TRACE_FUNC, FUNC_NVRAM_GET_DEFAULT_VALUE, ldi->LID, result, ldi->size, (kal_int32)ldi->fileprefix);
#else
    nvram_trace(TRACE_FUNC, FUNC_NVRAM_GET_DEFAULT_VALUE, ldi->LID, result, ldi->size);
#endif

    return result;
}




/*****************************************************************************
 * FUNCTION
 *  nvram_shutdown_handler
 * DESCRIPTION
 *  Disable all interrupts, change NVRAM state, change FS command mode, and flush
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_shutdown_handler(void)
{

#ifdef __MMI_FMI__    
#if !defined(__L1_STANDALONE__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to handle shutdown callback */
    for (i = 0; ;i++)
    {
        if (nvram_shutdown_cb_table[i].LID == 0 && nvram_shutdown_cb_table[i].get_data == NULL)
        {
            break;
        }

        if (NVRAM_IS_LID_VALID(nvram_shutdown_cb_table[i].LID) && nvram_shutdown_cb_table[i].get_data)
        {
            kal_uint8 *data;
            nvram_ltable_entry_struct *ldi;

            nvram_util_get_data_item(&ldi, nvram_shutdown_cb_table[i].LID);
            data = (kal_uint8 *)get_ctrl_buffer(ldi->size);
            if (nvram_shutdown_cb_table[i].get_data(data, ldi->size))
            {
                /* doesn't support linear-fix */
                nvram_write_data_item(ldi, 1, data, KAL_FALSE);
            }
            free_ctrl_buffer(data);
        }
    }
#endif /* !__L1_STANDALONE__ */
#endif /* __MMI_FMI__ */
}


/*****************************************************************************
 * FUNCTION
 *  nvram_space_reserve
 * DESCRIPTION
 *  To perform software upgrade.
 * PARAMETERS
 *  SpecialName         [?]
 *  StillNeed           [?]
 *  sysrecord(?)        [IN]        Sysrecord
 * RETURNS
 *  Success or Fail(?)
 *****************************************************************************/
void nvram_space_reserve(kal_uint32 *size_from_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 CodeFileSize;
    kal_uint32 clusterSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clusterSize = FS_GetClusterSize('Z');

    nvram_pre_init();

    nvram_get_code_file_size(&CodeFileSize);

    *size_from_code = (CodeFileSize / clusterSize) + ((CodeFileSize / clusterSize)? 1 : 0) + NVRAM_SPACE_MARGIN;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_folder_name
 * DESCRIPTION
 *  To get NVRAM folder name.
 * PARAMETERS
 *  void
 * RETURNS
 *  NVRAM folder name.
 *****************************************************************************/
void nvram_get_folder_name(WCHAR *nvram_folder_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wstrcpy(nvram_folder_name, NVRAM_FS_FOLDER_NAME);
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_work_path
 * DESCRIPTION
 *  To get NVRAM working directory.
 * PARAMETERS
 *  folder_idx  : Which folder
 * RETURNS
 *  NVRAM working directory.
 *****************************************************************************/
kal_char *nvram_get_work_path(kal_uint8 folder_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return nvram_query_work_path((nvram_folder_enum)folder_idx);
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_folder_idx
 * DESCRIPTION
 *  To get the index of nvram folder.
 * PARAMETERS
 *  LID  :
 * RETURNS
 *  index of folder.
 *****************************************************************************/
kal_uint8 nvram_get_folder_idx(nvram_lid_enum LID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!NVRAM_IS_LID_VALID(LID))
    {
        return NVRAM_ERRNO_INVALID;
    }

    nvram_util_get_data_item(&ldi, LID);

    return nvram_query_folder_index(ldi->category);
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_file_fullname
 * DESCRIPTION
 *  To get the full name of nvram file.
 * PARAMETERS
 *  folder_idx : [In]
 *  nvramname  : [In]
 *  filename   : [Out]
 * RETURNS
 *  index of folder.
 *****************************************************************************/
kal_wchar * nvram_get_file_fullname(kal_uint8 folder_idx, kal_char *nvramname, kal_wchar *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return nvram_query_file_name((nvram_folder_enum)folder_idx, nvramname, filename);
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_folder_total_amount
 * DESCRIPTION
 *  To get the full name of nvram file.
 * PARAMETERS
 *  void
 * RETURNS
 *  number of folders
 *****************************************************************************/
kal_uint8 nvram_get_folder_total_amount(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return NVRAM_FOLDER_TOTAL;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_check_hidden_files
 * DESCRIPTION
 *  Check if the files or folder is hidden or not in Meta FAT Editor.
 *  1. Any LID with NVRAM_CATEGORY_IMPORTANT will not appear in meta FAT Editor. ex: IMEI and SML
 *  2. Important Folder will not appear in meta FAT Editor.
 *  3. Customer sensitive data.
 *  Exception 1: During backup/restore, we can see IMEI and SML
 *  Exception 2: When NVRAM is locked. All the files and folder are hidden.
 *
 * PARAMETERS
 *  filename    [IN]    the filename
 *  backup      [IN]    During backup/restore the hidden file is different from normal
 *                      Please set this as true during backup/restore
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  KAL_TRUE:   hidden
 *  KAL_FALSE:  not hidden
 *****************************************************************************/
kal_bool nvram_check_hidden_file(const kal_wchar* filename, kal_bool backup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar buf[NVRAM_MAX_PATH_LEN];
    nvram_ltable_entry_struct *ldi;
    nvram_folder_enum i;
    kal_wchar *starter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    starter = kal_wstrchr(filename, '\\');

    if (starter == NULL)
    {
        return KAL_FALSE;
    }

    if (kal_wstrncmp(starter + 1, NVRAM_FS_FOLDER_NAME, kal_wstrlen(NVRAM_FS_FOLDER_NAME)) !=0 )
    {
        /* Not belongs to NVRAM folder */
        return KAL_FALSE;
    }

    if (nvram_test_lock() && backup == KAL_FALSE)
    {
        return KAL_TRUE;
    }
    
    starter = kal_wstrrchr(filename, '\\') + 1;

#ifdef __NVRAM_MULTI_FOLDERS__
    for (i = NVRAM_FOLDER_BEGIN; i < NVRAM_FOLDER_TOTAL ; i++)
    {
        kal_wsprintf(buf, "%s", strrchr(nvram_query_work_path(i), '\\')+1);
        if (kal_wstrcmp(buf, starter) == 0)
        {
            if ((i == NVRAM_NVD_IMEI && backup == KAL_FALSE)
                #ifdef __NVRAM_CUSTOM_SENSITIVE__
                || i == NVRAM_NVD_CUST
                #endif
                )
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
        }
    }
#endif

    ldi = &logical_data_item_table[0];
    do
    {

        if (( NVRAM_IS_CATEGORY_IMPORTANT(ldi->category) && backup == KAL_FALSE)
            || (NVRAM_IS_CATEGORY_IMPORTANT_L4(ldi->category) && backup == KAL_FALSE)
        #ifdef __NVRAM_CUSTOM_SENSITIVE__
            || NVRAM_IS_CATEGORY_CUSTOM_SENSITIVE(ldi->category)
        #endif
        #ifdef __NVRAM_CUSTOM_DISK__
            || NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category)
        #endif
            )
        {

            kal_wsprintf(buf, "%s", ldi->fileprefix);

            if (kal_wstrncmp(buf, starter, FILE_PREFIX_LEN)== 0)
            {
                return KAL_TRUE;
            }
        }
    }while(nvram_util_next_data_item(&ldi));

    return KAL_FALSE;
}




/*****************************************************************************
 * FUNCTION
 *  nvram_compare_to_default_value
 * DESCRIPTION
 *  This function is used to compare the value in nvram file to default value
 * PARAMETERS
 *  LID:            [IN]    NVRAM LID
 *  rec_index:      [IN]    record index, start from 1, but if the value is 0,
 *                          this function will compare all record to default value
 * RETURNS
 *  nvram_errno_enum
 * RETURN VALUES
 *  NVRAM_ERRNO_SUCCESS:            no error
 *  NVRAM_ERRNO_FAIL:   at least one record is different to default value
 *****************************************************************************/
kal_int32 nvram_compare_to_default_value(nvram_lid_enum LID, kal_uint16 rec_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi;
    int i;
    kal_uint8 *default_value;
    kal_uint8 *buffer;
    kal_int32 compare_result = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_util_get_data_item(&ldi, LID);

    if (!NVRAM_IS_LID_VALID(LID))
    {
        return NVRAM_IO_ERRNO_INVALID_LID;
    }

    if (rec_index > ldi->total_records)
    {
        return NVRAM_IO_ERRNO_INVALID_RECORD;
    }

    if (ldi->size <= MAX_NVRAM_RECORD_SIZE)
    {
        /* this function doesn't support the size over 2K now */
        buffer = (kal_uint8*) get_ctrl_buffer(ldi->size);


        for (i = (rec_index == 0?0:rec_index-1); i < ldi->total_records ; i++)
        {
            nvram_read_data_item(ldi, i + 1, 1, buffer, ldi->size);

            default_value = (kal_uint8 *)nvram_get_default_value_to_write(ldi, i + 1, NULL, 0);

            if (default_value == NULL || default_value == NVRAM_EF_FF_DEFAULT || default_value == NVRAM_EF_ZERO_DEFAULT)
            {
                default_value = (kal_uint8*)get_ctrl_buffer(ldi->size);
                nvram_get_default_value_to_write(ldi, i + 1, default_value, ldi->size);
                compare_result = memcmp(default_value, buffer, ldi->size);
                free_ctrl_buffer(default_value);
            }
            else
            {
                compare_result = memcmp(default_value, buffer, ldi->size);
            }

            if (rec_index != 0)
            {
                break;
            }
        }

        free_ctrl_buffer(buffer);
    }
    else
    {
        kal_uint16 chksum1, chksum2;

        buffer = (kal_uint8*) get_ctrl_buffer(ldi->total_records * NVRAM_CHKSUM_SIZE);

        /* this is temp solution, should implement full solution in drv layer in the future */
        nvram_read_data_item_chksum(ldi, 1, ldi->total_records, (kal_uint16*) buffer, ldi->total_records * NVRAM_CHKSUM_SIZE);

        for (i = (rec_index == 0?0:rec_index-1); i < ldi->total_records ; i++)
        {
            default_value = (kal_uint8 *)nvram_get_default_value_to_write(ldi, i + 1, NULL, 0);

            /* not support special default_value now */
            ASSERT(default_value);

            chksum1 = nvram_util_caculate_checksum(default_value, ldi->size);
            chksum2 = *(kal_uint16*)(buffer + NVRAM_CHKSUM_SIZE * i);

            if (chksum1 == chksum2)
            {
                compare_result = 0;
            }
            else
            {
                compare_result = 1;
            }

            if (rec_index != 0)
            {
                break;
            }
        }

        free_ctrl_buffer(buffer);
    }

    if (compare_result == 0)
    {
        return NVRAM_ERRNO_SUCCESS;
    }
    else
    {
        return NVRAM_ERRNO_FAIL;
    }
}

kal_uint8 *nvram_get_custpack_version(void)
{
    return nvram_ptr->custpack_version;
}
void nvram_dummy(void)
{
}
/*****************************************************************************
 * FUNCTION
 *  nvram_set_restore_factory_flag
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
kal_bool nvram_set_restore_factory_flag(nvram_restore_flag_enum restore_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi;
    kal_uint8 sys_cache[NVRAM_EF_SYS_CACHE_OCTET_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_CACHE_OCTET_LID);

    /*
     * if current record just record NVRAM_SYS_FACTORY_FLAG
     *  1. please use memory set
     *  2. else read out first.
     */
    memset(sys_cache, 0, NVRAM_EF_SYS_CACHE_OCTET_SIZE);

    sys_cache[0] = (kal_uint8) restore_flag;

    nvram_write_data_item(ldi, NVRAM_SYS_FACTORY_FLAG, sys_cache, KAL_FALSE);

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_check_restore_factory_flag
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
kal_bool nvram_check_restore_factory_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi;
    kal_uint8 sys_cache[NVRAM_EF_SYS_CACHE_OCTET_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_CACHE_OCTET_LID);

    nvram_read_data_item(ldi, NVRAM_SYS_FACTORY_FLAG, 1, sys_cache, NVRAM_EF_SYS_CACHE_OCTET_SIZE);

    if (NVRAM_RESTORE_TRUE == sys_cache[0])
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


extern void nvram_set_ltable(nvram_ltable_entry_struct *table);
extern nvram_ltable_entry_struct *nvram_get_ltable(void);

/*****************************************************************************
 * FUNCTION
 *  nvram_ltable_register
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void nvram_ltable_register(nvram_ltable_entry_struct *table)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
    nvram_set_ltable(table);
}

// The return value not used now, always return KAL_TRUE
kal_bool nvram_register_read_req(nvram_read_callback_struct *entry)
{
    entry->processed = KAL_FALSE;
    return KAL_TRUE;
}

