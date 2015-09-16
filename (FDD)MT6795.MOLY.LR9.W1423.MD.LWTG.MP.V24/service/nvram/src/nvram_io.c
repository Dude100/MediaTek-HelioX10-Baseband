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
 * nvram_io.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is main() function of NVRAM module.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
* Include
*****************************************************************************/
#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"


/* For FAT */
#include "fs_type.h"
#include "fs_gprot.h"
#include "fs_iprot.h"

#include "nvram_data_items.h"
#include "nvram_main.h"
#include "custom_nvram_restore.h"


#if defined(__MMI_FMI__)
#include "nvram_common_defs.h"

#endif
/*
 * External Function
 */
extern void WDT_Restart2(void);
extern void MMICheckDiskDisplay(void);
extern void DRV_ABN_RESET(void);
extern kal_bool nvram_set_restore_factory_flag(nvram_restore_flag_enum restore_flag);

extern const nvram_clean_folder_entry nvram_clean_folder_list[];

#ifdef __NVRAM_WRITE_WITH_FILE_SIZE__
extern kal_bool bResetNvramData;
#endif

/*
 * Local Function
 */
static nvram_errno_enum nvram_read_data_item_multiple(
                            nvram_ltable_entry_struct *ldi,
                            kal_uint16 rec_index,
                            kal_uint16 rec_amount,
                            kal_uint8 *buffer,
                            kal_uint32 buffer_size);
static nvram_errno_enum nvram_write_fs_data_item(
                            nvram_ltable_entry_struct *ldi,
                            kal_uint16 index,
                            kal_uint8 *buffer,
                            kal_uint32 buffer_size,
                            kal_bool is_init);
 
static nvram_errno_enum nvram_reset_one_data_item(nvram_ltable_entry_struct *ldi,
                                        kal_uint16 rec_index,
                                        kal_uint16 rec_amount);
static kal_bool nvram_factory_restore_sys_cache(
                    nvram_reset_category_enum category,
                    nvram_app_id_enum app_id);

static kal_bool nvram_factory_rmdir_user(nvram_reset_category_enum category);

kal_int32 nvram_recover_data_item(nvram_ltable_entry_struct *ldi);


/*****************************************************************************
 * FUNCTION
 *  nvram_read_data_item_chk
 * DESCRIPTION
 *  This is nvram_read_data_item() function of NVRAM module.
 * PARAMETERS
 *  ldi             [IN]        MUST be 1 ~ (total_LID - 1)
 *  rec_index       [IN]
 *  rec_amount      [IN]
 *  buffer          [IN]        MUST be even-bytes aligned.
 *  rec_size        [IN]        MUST be even-bytes aligned: ie, ((ldi->size + 1) / 2) * 2
 *  index(?)        [IN]        MUST be 1 ~ total_records
 * RETURNS
 *  NVRAM_IO_ERRNO_OK    if read successfully.
 *  NVRAM_IO_ERRNO_CHK   if checksum error, and cannot be reset to default value.
 *  NVRAM_IO_ERRNO_INIT  if checksum error, but successfully reset to default value.
 *****************************************************************************/
nvram_errno_enum nvram_read_data_item_chksum
    (nvram_ltable_entry_struct *ldi, kal_uint16 rec_index, kal_uint16 rec_amount, kal_uint16 *chksum, kal_uint32 chksum_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 status;
    kal_uint8 *default_value = NULL, *default_value_buffer = NULL;
    NVRAM_FILE_NAME nvramname;

    kal_uint32 file_offset = 0;
    nvram_folder_enum folder_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/




/******************************************************
 *  Device Broken
 ******************************************************/

    /* Read Default Value */
    if (nvram_ptr->dev_broken)
    {
        kal_uint32 i;
        
        default_value_buffer = (kal_uint8*) get_ctrl_buffer(MAX_NVRAM_RECORD_SIZE);

        for (i = 0; i < rec_amount; i++)
        {
            /* when ldi size too big, we cannot operator it on buffer,
               use original default value pointer directly */

            default_value = (kal_uint8*) nvram_get_default_value_to_write(ldi, (kal_uint16)(i + 1), NULL, 0);

            /* the default_value is not assigned in table , ex: L1 LID */
            if (default_value == NULL)
            {
                nvram_get_default_value_to_write(ldi, (kal_uint16)(i + 1), default_value_buffer, MAX_NVRAM_RECORD_SIZE);
                default_value = default_value_buffer;
            }

            chksum[i]  = nvram_util_caculate_checksum(default_value, ldi->size);
        }


        free_ctrl_buffer(default_value_buffer);
        
        status = NVRAM_IO_ERRNO_OK;

        return (nvram_errno_enum)status;
    }

/******************************************************
 *  OTP
 ******************************************************/
#ifdef __NVRAM_OTP__
    /* Handle request to OTP */
    if (NVRAM_IS_CATEGORY_OTP(ldi->category))
    {
        if (nvram_ptr->state != NVRAM_STATE_READY)
        {
            status = NVRAM_IO_ERRNO_ACCESS_DENIED;
        }
        else
        {
            kal_uint32 i;
           
            default_value_buffer = (kal_uint8*) get_ctrl_buffer(MAX_NVRAM_RECORD_SIZE);

            status = nvram_read_otp_data_item(ldi, rec_index, rec_amount, default_value_buffer, MAX_NVRAM_RECORD_SIZE);

            for (i = 0; i < rec_amount; i++)
            {
                chksum[i]  = nvram_util_caculate_checksum(default_value_buffer + i * ldi->size, ldi->size);
            }
            free_ctrl_buffer(default_value_buffer);
        }

        return (nvram_errno_enum)status;
    }
#endif

/******************************************************
 *  Custom Disk
 ******************************************************/

#ifdef __NVRAM_CUSTOM_DISK__
    if (NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category))
    {
        kal_uint32 i;
        default_value_buffer = (kal_uint8*) get_ctrl_buffer(MAX_NVRAM_RECORD_SIZE);

        status = nvram_read_custom_disk(ldi, rec_index, rec_amount, default_value_buffer, MAX_NVRAM_RECORD_SIZE);

        for (i = 0; i < rec_amount; i++)
        {
            chksum[i]  = nvram_util_caculate_checksum(default_value_buffer + i * ldi->size, ldi->size);
        }

        free_ctrl_buffer(default_value_buffer);
        return (nvram_errno_enum)status;
    }
#endif


/******************************************************
 *  FAT
 ******************************************************/

    folder_index = nvram_query_folder_index(ldi->category);

#ifdef __NVRAM_PSEUDO_MERGE__
    if (NVRAM_IS_ATTR_PACKAGE(ldi->attr))
    {
        file_offset = (kal_uint32) (ldi->description);
    }
    else
#endif
    {
        file_offset = 0;
    }

    nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);

    status = nvram_drv_fat_read(nvramname, folder_index, file_offset, rec_index, rec_amount, ldi->size, (kal_uint8*) chksum, NVRAM_DRV_READ_TYPE_CHKSUM, ldi->attr);

    if (status != NVRAM_DRV_OK && (ldi->attr & NVRAM_ATTR_MULTIPLE))
    {
        nvram_util_make_lid_filename(ldi, nvramname, KAL_FALSE);

        status = nvram_drv_fat_read(nvramname, folder_index, file_offset, rec_index, rec_amount, ldi->size, (kal_uint8*) chksum, NVRAM_DRV_READ_TYPE_CHKSUM, ldi->attr);

        if (status == NVRAM_DRV_OK)
        {
            nvram_drv_fat_backup(ldi, KAL_FALSE);
        }
    }

    return (nvram_errno_enum)status;
}   /* end of nvram_read_data_item */


/*****************************************************************************
 * FUNCTION
 *  nvram_read_data_item
 * DESCRIPTION
 *  This is nvram_read_data_item() function of NVRAM module.
 * PARAMETERS
 *  ldi             [IN]        MUST be 1 ~ (total_LID - 1)
 *  rec_index       [IN]
 *  rec_amount      [IN]
 *  buffer          [IN]        MUST be even-bytes aligned.
 *  rec_size        [IN]        MUST be even-bytes aligned: ie, ((ldi->size + 1) / 2) * 2
 *  index(?)        [IN]        MUST be 1 ~ total_records
 * RETURNS
 *  NVRAM_IO_ERRNO_OK    if read successfully.
 *  NVRAM_IO_ERRNO_CHK   if checksum error, and cannot be reset to default value.
 *  NVRAM_IO_ERRNO_INIT  if checksum error, but successfully reset to default value.
 *****************************************************************************/
nvram_errno_enum nvram_read_data_item
    (nvram_ltable_entry_struct *ldi, kal_uint16 rec_index, kal_uint16 rec_amount, kal_uint8 *buffer, kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_errno_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_trace(TRACE_FUNC, IO_READ_DATA_ITEM_START, ldi->LID, rec_index, rec_amount, buffer_size);
    nvram_trace(TRACE_INFO, INFO_NVRAM_DATA_ITEM, ldi->LID, ldi->size);

    if (buffer_size < ldi->size * rec_amount)
    {
        nvram_trace(TRACE_FUNC, IO_READ_DATA_ITEM_RESULT, ldi->LID, NVRAM_IO_ERRNO_INVALID_SIZE, __LINE__);
        return NVRAM_IO_ERRNO_INVALID_SIZE;
    }

/******************************************************
 *  Device Broken
 ******************************************************/
    if (nvram_ptr->dev_broken)
    {
        kal_uint32 i;

        nvram_trace(TRACE_FUNC, IO_READ_DATA_ITEM_RESULT, ldi->LID, NVRAM_IO_ERRNO_DRV_BROKEN, __LINE__);

        for (i = 0; i < rec_amount; i++)
        {
            nvram_get_default_value_to_write(ldi, (kal_uint16)(i + 1), buffer + (i * ldi->size), ldi->size);
        }

        return NVRAM_IO_ERRNO_OK;
    }

/******************************************************
 *  OTP
 ******************************************************/
#ifdef __NVRAM_OTP__
    /* Handle request to OTP */
    if ((nvram_ptr->state != NVRAM_STATE_READY) && NVRAM_IS_CATEGORY_OTP(ldi->category))
    {
        nvram_trace(TRACE_FUNC, IO_READ_DATA_ITEM_RESULT, ldi->LID, NVRAM_IO_ERRNO_OK, __LINE__);
        return NVRAM_IO_ERRNO_OK;
    }
    else  if ((nvram_ptr->state == NVRAM_STATE_READY) && NVRAM_IS_CATEGORY_OTP(ldi->category))
    {
        status = nvram_read_otp_data_item(ldi, rec_index, rec_amount, buffer, buffer_size);
    }
    else
#endif


/******************************************************
 *  Custom Disk
 ******************************************************/
#ifdef __NVRAM_CUSTOM_DISK__
    if (NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category))
    {
        status = nvram_read_custom_disk(ldi, rec_index, rec_amount, buffer, buffer_size);
    }
    else
#endif


/******************************************************
 *  FAT
 ******************************************************/
    if (NVRAM_IS_ATTR_MULTIPLE(ldi->attr) || NVRAM_IS_ATTR_BACKUP_FAT(ldi->attr))
    {
        status = nvram_read_data_item_multiple(ldi, rec_index, rec_amount, buffer, buffer_size);
    }
    else
    {
        status = nvram_read_data_item_multiple(ldi, rec_index, rec_amount, buffer, buffer_size);
    }
#if defined(__CCCIFS_SUPPORT__) && defined(__MTK_TARGET__)
    if (NVRAM_IS_ATTR_AUTORECOVER(ldi->attr) &&
        (status != NVRAM_IO_ERRNO_OK))
    {

#if defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__)
        // Try to upgrade from obsolete path when upgrade.
        if (NVRAM_IS_CATEGORY_IMPORTANT_L4(ldi->category))
        {
            nvram_recover_protect(ldi);

			status = nvram_read_data_item_multiple(ldi, rec_index, rec_amount, buffer, buffer_size);

	        if (status != NVRAM_IO_ERRNO_OK)
	        {
	            EXT_ASSERT(KAL_FALSE, DISPLAY_ERROR(status), NVRAM_LOC_RESTORE_SUCCESS_READ_FAIL, ldi->LID);
	        }
        }	
#endif

        if (NVRAM_IS_CATEGORY_IMPORTANT_L4(ldi->category) == 0)   // Important partitions doesn't need auto recover
        {
	        nvram_trace(TRACE_FUNC, IO_READ_DATA_ITEM_MULTIPLE, ldi->LID, status, nvram_drv_fat_get_last_err(), __LINE__);

	        //if AP restore fail, nvram_recover_data_item() will assert
	        nvram_recover_data_item(ldi);

	        status = nvram_read_data_item_multiple(ldi, rec_index, rec_amount, buffer, buffer_size);

	        if (status != NVRAM_IO_ERRNO_OK)
	        {
	            EXT_ASSERT(KAL_FALSE, DISPLAY_ERROR(status), NVRAM_LOC_RESTORE_SUCCESS_READ_FAIL, ldi->LID);
	        }
        }
    }
#endif


#ifdef __NVRAM_UNIT_TEST__
    status = nvram_unit_test_get_io_status(status);
#endif

    /*
     *  Error Handling
     *  1. try to restore data from backup partition
     *  2. reset data if data is not in important category
     *
     */

#ifdef __NVRAM_BACKUP_DISK_RAW__
    if (status != NVRAM_IO_ERRNO_OK && NVRAM_IS_ATTR_BACKUP_RAW(ldi->attr))
    {
        nvram_trace(TRACE_FUNC, IO_READ_DATA_ITEM_RESULT, ldi->LID, status, __LINE__);

        if (nvram_recover_image_by_lid(ldi) == NVRAM_ERRNO_SUCCESS)
        {
            status = nvram_read_data_item_multiple(ldi, rec_index, rec_amount, buffer, buffer_size, KAL_FALSE);
        }
    }
#endif

    /* it is impossible to read data from sds fail
       if it fails, we have no error handling here , so assert */


    /* If we read internal item fail, we do not reset it , just return fail
       We will reset it after error handling */

    //internal data locates in the SDS also, need to consider this
    if (status != NVRAM_IO_ERRNO_OK && !NVRAM_IS_CATEGORY_INTERNAL(ldi->category))
    {

        nvram_trace(TRACE_FUNC, IO_READ_DATA_ITEM_RESULT, ldi->LID, status, __LINE__);
    
    #if !defined(__NVRAM_SECURE_DATA_STORAGE__) && !defined(__NVRAM_SIMULATE_SST__)
        if ( (NVRAM_IS_CATEGORY_IMPORTANT(ldi->category)
    #ifdef __CCCIFS_SUPPORT__
        #if defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__)
            || (NVRAM_IS_CATEGORY_IMPORTANT_L4(ldi->category))) && (ldi->LID != NVRAM_EF_IMPT_COUNTER_LID)
        #else
            ) && (ldi->LID != NVRAM_EF_IMPT_COUNTER_LID)
        #endif
    #else
        )
    #endif
        )
        {
            EXT_ASSERT(KAL_FALSE, DISPLAY_ERROR(status), NVRAM_LOC_READ_IMPORTANT_DATA_FAIL, ldi->LID);
        }
    #endif

        if((status = nvram_reset_one_data_item(ldi, rec_index, rec_amount)) == NVRAM_IO_ERRNO_OK)
        {
            kal_uint32 i;

            nvram_trace(TRACE_FUNC, IO_READ_DATA_ITEM_RESULT, ldi->LID, status, __LINE__);

            for (i = 0; i < rec_amount; i++)
            {
                nvram_get_default_value_to_write(ldi, (kal_uint16)(rec_index + i), buffer + (i * ldi->size), ldi->size);
            }

        }
        else
        {
            nvram_trace(TRACE_FUNC, IO_READ_DATA_ITEM_RESULT, ldi->LID, status, __LINE__);
            //ASSERT(0);
			EXT_ASSERT(0, DISPLAY_ERROR(status), NVRAM_LOC_READ_AND_RESET_FAIL, ldi->LID);
        }
    }

    return status;
}   /* end of nvram_read_data_item */


/*****************************************************************************
 * FUNCTION
 *  nvram_read_data_item_multiple
 * DESCRIPTION
 *  This is nvram_read_data_item_multiple() function of NVRAM module.
 *  Note that multiple copied attribute DOES NOT support for
 *  linear fixed logical data items.
 * PARAMETERS
 *  ldi             [IN]
 *  rec_index       [IN]
 *  rec_amount      [IN]
 *  buffer          [IN/OUT]
 *  rec_size        [IN]
 * RETURNS
 *  NVRAM_IO_ERRNO_INIT if all copies are corrupted and any of them is reset successfully.
 *  NVRAM_IO_ERRNO_CHK if all copies are corrupted and reset failed.
 *  NVRAM_IO_ERRNO_OK at least one valid copy is read.
 *****************************************************************************/
static nvram_errno_enum nvram_read_data_item_multiple
    (nvram_ltable_entry_struct *ldi, kal_uint16 rec_index, kal_uint16 rec_amount, kal_uint8 *buffer, kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_drv_status_enum drv_status[2] = {NVRAM_DRV_OK, NVRAM_DRV_OK};

    NVRAM_FILE_NAME nvramname;
    kal_uint32 file_offset = 0;
    nvram_folder_enum folder_index;
    kal_bool multiple = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NVRAM_IS_ATTR_MULTIPLE(ldi->attr) || NVRAM_IS_ATTR_BACKUP_FAT(ldi->attr))
    {
        multiple = KAL_TRUE;
    }
    folder_index = nvram_query_folder_index(ldi->category);

    file_offset = 0;
    nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);

#ifdef __NVRAM_PSEUDO_MERGE__
    if (NVRAM_IS_ATTR_PACKAGE(ldi->attr))
    {
        file_offset = (kal_uint32) (ldi->description);
        if (!multiple)
        {
            nvram_make_package_filename(nvramname, 'A');
        }
    }
#endif

    /*************************************************************************
     *  Step 1:  try to find one valid copy
     *  Step 2:  If found,  try to recover another one if need
     *  Step 3:  If not found or recover fail, reset the data
     *
     *  If fail in step 2 and step 3, return error
     ***************************************************************************/

    /* First, try to find one valid / healthy copy */
    
    do
    {
        drv_status[0] = nvram_drv_fat_read(
                                nvramname,
                                folder_index,
                                file_offset,
                                rec_index,
                                rec_amount,
                                ldi->size,
                                buffer,
                                NVRAM_DRV_READ_TYPE_DATA,
                                ldi->attr);

    #ifdef __NVRAM_UNIT_TEST__
        drv_status[0] = nvram_unit_test_get_drv_status(drv_status[0]);
    #endif   

        if (!multiple)
        {
            break;
        }
//Read 2nd copy
    #ifdef __NVRAM_BACKUP_DISK_FAT__
        if (NVRAM_IS_ATTR_BACKUP_FAT(ldi->attr))
        {
            folder_index = NVRAM_NVD_BAK;
        }
    #endif

    
    #if defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__) && defined(__CCCIFS_SUPPORT__)
        {
            folder_index = nvram_query_folder_index_ex(ldi->category, KAL_FALSE);
        }
    #endif

        nvram_util_make_lid_filename(ldi, nvramname, KAL_FALSE);

        if (drv_status[0] == NVRAM_DRV_OK)
        {
            //Read checksum only
            kal_uint8* extra_buffer;

        #if defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__) && defined(__CCCIFS_SUPPORT__)
            folder_index = nvram_query_folder_index_ex(ldi->category, KAL_FALSE);
        #endif

            extra_buffer = (kal_uint8*) get_ctrl_buffer(NVRAM_CHKSUM_SIZE * rec_amount);


            drv_status[1] = nvram_drv_fat_read(
                                    nvramname,
                                    folder_index,
                                    file_offset,
                                    rec_index,
                                    rec_amount,
                                    ldi->size,
                                    extra_buffer,
                                    NVRAM_DRV_READ_TYPE_CHKSUM,
                                    ldi->attr);
            free_ctrl_buffer(extra_buffer);
        }
        else
        {
            //read data
            drv_status[1] = nvram_drv_fat_read(
                                    nvramname,
                                    folder_index,
                                    file_offset,
                                    rec_index,
                                    rec_amount,
                                    ldi->size,
                                    buffer,
                                    NVRAM_DRV_READ_TYPE_DATA,
                                    ldi->attr);
        }

        nvram_trace(TRACE_FUNC, IO_READ_DATA_ITEM_MULTIPLE, ldi->LID, drv_status[0], drv_status[1], nvram_drv_fat_get_last_err(), __LINE__);

        if ((drv_status[0] == NVRAM_DRV_OK) && (drv_status[1] == NVRAM_DRV_OK))
        {
            //Need to check if checksum[0] != checksum[1] in the future
            return NVRAM_IO_ERRNO_OK;
        }
        else if ((drv_status[0] != NVRAM_DRV_OK) && (drv_status[1] != NVRAM_DRV_OK))
        {
            //if SDS, backup from SDS

            return NVRAM_IO_ERRNO_CHK;        
        }
        else if ((drv_status[0] != NVRAM_DRV_OK))
        {
//            nvram_trace(TRACE_FUNC, IO_READ_DATA_ITEM_MULTIPLE, ldi->LID, drv_status[0], nvram_drv_fat_get_last_err(), __LINE__);
            drv_status[0] = nvram_drv_fat_backup(ldi, KAL_FALSE);
        }
        else
        {
//            nvram_trace(TRACE_FUNC, IO_READ_DATA_ITEM_MULTIPLE, ldi->LID, drv_status[1], nvram_drv_fat_get_last_err(), __LINE__);
            drv_status[1] = nvram_drv_fat_backup(ldi, KAL_TRUE);        
        }
    
    }while(0);


    /* read two copy fail or recover fail */
    if ((drv_status[0] != NVRAM_DRV_OK) || (drv_status[1] != NVRAM_DRV_OK))
    {
        nvram_trace(TRACE_FUNC, IO_READ_DATA_ITEM_MULTIPLE, ldi->LID, drv_status[0], drv_status[1], nvram_drv_fat_get_last_err(), __LINE__);
        return NVRAM_IO_ERRNO_CHK;
    }

    return NVRAM_IO_ERRNO_OK;
}   /* end of nvram_read_data_item_multiple */

#ifdef __NVRAM_WRITE_WITH_FILE_SIZE__
/*****************************************************************************
 * FUNCTION
 *  nvram_get_lid_default_value_to_write
 * DESCRIPTION
 *  This is nvram_get_default_value_to_write() function of NVRAM module.
 *  Get default value of certain logical data item.
 *  The default value is copied into buffer.
 *  The returned content of buffer may be encrypted if needed.
 * PARAMETERS
 *  ldi             [?]
 *  rec_index       [IN]
 *  buffer          [?]
 *  buffer_size     [IN]
 * RETURNS
 *  KAL_FALSE if no default value defined, KAL_TRUE otherwise.(?)
 *****************************************************************************/
kal_uint8 const * nvram_get_lid_default_value_to_write(
								nvram_ltable_entry_struct *ldi, 
							    kal_uint16 rec_index,
							    kal_uint8 *buffer, 
							    kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 const *default_value = ldi->default_value;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (ldi->category & NVRAM_CATEGORY_FUNC_DEFAULT)
    {
        if (buffer && ldi->default_value)
        {
            nvram_query_deault_func query_func = (nvram_query_deault_func)ldi->default_value;

            if(ldi->LID != NVRAM_EF_SYS_LID)
            {
                query_func(ldi->LID, buffer, ldi->size);
            }
        }
        return NULL;
    }
    else
    {    	
		rec_index++;		
        /* Multi default value */
        if (ldi->attr & NVRAM_ATTR_MULTI_DEFAULT)
        {
            rec_index--;
        }
        else
        {
            rec_index = 0;
        }

        if (buffer)
        {            
            EXT_ASSERT(buffer_size >= ldi->size, NVRAM_INTERNAL_ERR(ldi->LID), NVRAM_LOC_GET_DEFAULT_WITH_WRONG_PARAM, buffer_size);
            kal_mem_cpy(buffer, (void*)(default_value + (ldi->size * rec_index)), ldi->size);
        }

        return default_value + (ldi->size * rec_index);
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  nvram_get_default_value_to_write
 * DESCRIPTION
 *  This is nvram_get_default_value_to_write() function of NVRAM module.
 *  Get default value of certain logical data item.
 *  The default value is copied into buffer.
 *  The returned content of buffer may be encrypted if needed.
 * PARAMETERS
 *  ldi             [?]
 *  rec_index       [IN]
 *  buffer          [?]
 *  buffer_size     [IN]
 * RETURNS
 *  KAL_FALSE if no default value defined, KAL_TRUE otherwise.(?)
 *****************************************************************************/
kal_uint8 const * nvram_get_default_value_to_write
    (nvram_ltable_entry_struct *ldi, kal_uint16 rec_index, kal_uint8 *buffer, kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 const *default_value = ldi->default_value;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __NVRAM_SECURE_DATA_STORAGE__
    if (NVRAM_IS_CATEGORY_BACKUP_SDS(ldi->category) && !(nvram_ptr->sw_status & NVRAM_SW_EMPTY_SDS))
    {
        if (buffer)
        {
            kal_uint32 status;
            kal_uint32 rec_amount = buffer_size / ldi->size;
            if ((status = nvram_sds_read_data_item(ldi, rec_index, rec_amount, buffer, buffer_size)) == NVRAM_ERRNO_SUCCESS)
            {
                //use the default value from the sds
                if ((ldi->total_records > 1) && !(ldi->attr & NVRAM_ATTR_MULTI_DEFAULT))
                {
                    ldi->attr |= NVRAM_ATTR_MULTI_DEFAULT;
                }
                return NULL;
            }
            else
            {
                //error handle for the important data
                if (NVRAM_IS_CATEGORY_IMPORTANT(ldi->category))
                {
                    extern void nvram_sds_throw_exception(kal_int32 err, kal_uint32 line);
                    nvram_sds_throw_exception(status, __LINE__);
                    EXT_ASSERT(KAL_FALSE, DISPLAY_ERROR(status), NVRAM_LOC_GET_DEFAULT_FROM_SDS_FAIL ,ldi->LID);
                }
                //read sds fail, goto original flow
                goto GET_DEFAULT_VALUE;
            }    
        }
        
        return NULL;
    }
GET_DEFAULT_VALUE:
#endif

    if (ldi->category & NVRAM_CATEGORY_FUNC_DEFAULT)
    {
        if (buffer && ldi->default_value)
        {
            nvram_query_deault_func query_func = (nvram_query_deault_func)ldi->default_value;

            if(ldi->LID == NVRAM_EF_SYS_LID)
            {
                if(rec_index == 2)
                    query_func(NVRAM_EF_BRANCH_VERNO_LID, buffer, ldi->size);
                else if(rec_index == 3)
                    query_func(NVRAM_EF_FLAVOR_VERNO_LID, buffer, ldi->size);
                else
                    query_func(NVRAM_EF_SYS_LID, buffer, ldi->size);
              
            }else
            {
                query_func(ldi->LID, buffer, ldi->size);
            }
        }
        return NULL;
    }
    else
    {
        if (default_value == NULL || default_value == NVRAM_EF_FF_DEFAULT)
            /* No default value supplied. Fill the buffer with 0xFF. */
        {
            if (buffer)
            {
                kal_mem_set(buffer, (kal_uint8) NVRAM_INVALID_VALUE, buffer_size);
            }
            return NVRAM_EF_FF_DEFAULT;
        }
        else if (default_value == NVRAM_EF_ZERO_DEFAULT)
            /* Default value is all the same value (0x00) Fill it as well. */
        {
            if (buffer)
            {
                kal_mem_set(buffer, (kal_uint8) NVRAM_EF_ZERO_DEFAULT_VALUE, buffer_size);
            }
            return NVRAM_EF_ZERO_DEFAULT;
        }
        else
        {
            /* Multi default value */
            if ((ldi->attr & NVRAM_ATTR_MULTI_DEFAULT))
            {
                rec_index--;
            }
            else
            {
                rec_index = 0;
            }


            if (buffer)
            {
                //EXT_ASSERT(buffer_size >= ldi->size, ldi->LID, buffer_size, ldi->size);
                EXT_ASSERT(buffer_size >= ldi->size, NVRAM_INTERNAL_ERR(ldi->LID), NVRAM_LOC_GET_DEFAULT_WITH_WRONG_PARAM, buffer_size);

                kal_mem_cpy(buffer, (void*)(default_value + (ldi->size * rec_index)), ldi->size);
            }

            return default_value + (ldi->size * rec_index);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  nvram_write_data_item
 * DESCRIPTION
 *  This is nvram_write_data_item() function of NVRAM module.
 * PARAMETERS
 *  ldi                 [IN]        MUST be 1 ~ (total_LID - 1)
 *  index               [IN]        MUST be 1 ~ total_records
 *  data                [?]
 *  is_init             [IN]
 *  buffer_size(?)      [IN]        MUST be even-bytes aligned: ie, ((ldi->size + 1) / 2) * 2 Note that content of `data' could be changed due to encyrption!!
 *  buffer(?)           [IN]        MUST be even-bytes aligned.
 * RETURNS
 *  NVRAM_IO_ERRNO_INVALID_LID
 *  NVRAM_IO_ERRNO_INVALID_RECORD
 *  NVRAM_IO_ERRNO_INVALID_SIZE
 *  NVRAM_IO_ERRNO_CHK if all copies are failed to write
 *  NVRAM_IO_ERRNO_OK at least one valid copy is written.
 *****************************************************************************/
nvram_errno_enum nvram_write_data_item(nvram_ltable_entry_struct *ldi, kal_uint16 index, kal_uint8 *data, kal_bool is_init)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_errno_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    nvram_trace(TRACE_FUNC, IO_WRITE_DATA_ITEM_START, ldi->LID, index, is_init);
    nvram_trace(TRACE_INFO, INFO_NVRAM_DATA_ITEM, ldi->LID, ldi->size);
    /* Construct a even bytes aligned buffer, and assign it to returned data pointer */
    if (data == NULL)
    {
        nvram_trace(TRACE_FUNC, IO_WRITE_DATA_ITEM_RESULT, ldi->LID, NVRAM_IO_ERRNO_INVALID_SIZE, __LINE__, is_init);
        return NVRAM_IO_ERRNO_INVALID_SIZE;
    }

    /* Global software lock status is locked and this logical data item's attribute is write-protected. */
    if ((nvram_ptr->lock == KAL_TRUE) && NVRAM_IS_ATTR_WRITEPROTECT(ldi->attr))
    {
        nvram_trace(TRACE_FUNC, IO_WRITE_DATA_ITEM_RESULT, ldi->LID, NVRAM_IO_ERRNO_LOCKED, __LINE__, is_init);
        return NVRAM_IO_ERRNO_LOCKED;
    }

/******************************************************
 *  Device Broken
 ******************************************************/
    if (nvram_ptr->dev_broken)
    {
        nvram_trace(TRACE_FUNC, IO_WRITE_DATA_ITEM_RESULT, ldi->LID, NVRAM_IO_ERRNO_DRV_BROKEN, __LINE__, is_init);
        return NVRAM_IO_ERRNO_OK;
    }


/******************************************************
 *  OTP
 ******************************************************/

#ifdef __NVRAM_OTP__
    /* Handle request to OTP */
    if ((ldi->category & NVRAM_CATEGORY_OTP &&  nvram_ptr->state == NVRAM_STATE_READY))
    {
        status = nvram_write_otp_data_item(ldi, index, data, ldi->size);
        return status;
    }
    else if ((nvram_ptr->state != NVRAM_STATE_READY) && (ldi->category & NVRAM_CATEGORY_OTP))
    {
        nvram_trace(TRACE_FUNC, IO_WRITE_DATA_ITEM_RESULT, ldi->LID, NVRAM_IO_ERRNO_OK, __LINE__, is_init);
        status = nvram_write_fs_data_item(ldi, index, data, ldi->size, is_init);
    }
    else
#endif

/******************************************************
 *  Custom Disk
 ******************************************************/
#ifdef __NVRAM_CUSTOM_DISK__
    if (NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category))
    {
        status = nvram_write_custom_disk(ldi, index, data, ldi->size, is_init);
    }
    else
#endif


/******************************************************
 *  FAT
 ******************************************************/

    status = nvram_write_fs_data_item(ldi, index, data, ldi->size, is_init);

#ifdef __NVRAM_UNIT_TEST__
    if (!is_init)
    {
        status = nvram_unit_test_get_io_status(status);
    }
#endif

    if (status != NVRAM_IO_ERRNO_OK)
    {

        /* IMEI and SML */
        if ((NVRAM_IS_CATEGORY_IMPORTANT(ldi->category)
    #if defined(__CCCIFS_SUPPORT__)
        #if defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__)
            || NVRAM_IS_CATEGORY_IMPORTANT_L4(ldi->category)) && (ldi->LID != NVRAM_EF_IMPT_COUNTER_LID)
        #else
            ) && (ldi->LID != NVRAM_EF_IMPT_COUNTER_LID)
        #endif
    #else
        )
	#endif	
            )
        {
            //EXT_ASSERT (KAL_FALSE, ldi->LID, status, nvram_drv_fat_get_last_err());
            EXT_ASSERT (KAL_FALSE, DISPLAY_ERROR(status),NVRAM_LOC_WRITE_IMPORTANT_DATA_FAIL , ldi->LID);
            return status;
        }


        nvram_trace(TRACE_FUNC, IO_WRITE_DATA_ITEM_RESULT, ldi->LID, status, __LINE__, is_init);

        if (is_init == KAL_FALSE
        #ifdef __NVRAM_CUSTOM_DISK__
            && !NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category)
        #endif
        #ifdef __NVRAM_OTP__
            && !NVRAM_IS_CATEGORY_OTP(ldi->category)
        #endif
            )
        {
            /* Try to reset data if it is not a initial case */
            if ((status = nvram_reset_one_data_item(ldi, 1, ldi->total_records)) == NVRAM_IO_ERRNO_OK)
            {
                nvram_trace(TRACE_FUNC, IO_WRITE_DATA_ITEM_RESULT, ldi->LID, status, __LINE__, is_init);

                status = nvram_write_fs_data_item(ldi, index, data, ldi->size, is_init);
            }
        }
    }

    if (status != NVRAM_IO_ERRNO_OK)
    {
        nvram_trace(TRACE_FUNC, IO_WRITE_DATA_ITEM_RESULT, ldi->LID, status, __LINE__, is_init);
        //ASSERT(0);
        EXT_ASSERT(0, DISPLAY_ERROR(status), NVRAM_LOC_WRITE_AND_RESET_FAIL, ldi->LID);
    }

    return status;
}

#ifdef __NVRAM_WRITE_WITH_FILE_SIZE__
/*****************************************************************************
 * FUNCTION
 *  nvram_write_fs_data_item_multiple
 * DESCRIPTION
 *  This is nvram_write_data_item_multiple() function of NVRAM module.
 * PARAMETERS
 *  ldi             [?]
 *  index           [IN]
 *  buffer          [?]
 *  buffer_size     [IN]
 *  is_init         [IN]
 * RETURNS
 *  NVRAM_IO_ERRNO_CHK if all copies are failed to write
 *  NVRAM_IO_ERRNO_OK at least one valid copy is written.
 *****************************************************************************/
static nvram_errno_enum nvram_write_fs_data_item_multiple
    (nvram_ltable_entry_struct *ldi, 
    kal_uint16 index, 
    kal_uint16 rec_mount, 
    const kal_uint8 *buffer,
    kal_bool is_init)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_errno_enum status = NVRAM_IO_ERRNO_OK;
    nvram_drv_status_enum drv_status;
    kal_uint32 record_ID;
    NVRAM_FILE_NAME nvramname;
    kal_uint32 file_offset;
    nvram_folder_enum folder_index;
    kal_bool multiple = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NVRAM_IS_ATTR_MULTIPLE(ldi->attr) || NVRAM_IS_ATTR_BACKUP_FAT(ldi->attr))
    {
        multiple = KAL_TRUE;
    }

    folder_index = nvram_query_folder_index(ldi->category);

    file_offset = 0;
    nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);


    for (record_ID = 0; record_ID < 2; record_ID++)
    {

    #ifdef __NVRAM_BACKUP_DISK_FAT__
        if (record_ID == 1 && NVRAM_IS_ATTR_BACKUP_FAT(ldi->attr))
        {
            folder_index = NVRAM_NVD_BAK;
        }
    #endif

    #if defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__) && defined(__SMART_PHONE_MODEM__)
        if (record_ID == 1)
        {
            folder_index = nvram_query_folder_index_ex(ldi->category, KAL_FALSE);
        }
    #endif
       
		nvram_drv_fat_write_multRec(
							nvramname,
			                folder_index,
			                file_offset,
			                index,
			                rec_mount,
			                ldi->size,
			                buffer,
			                ldi->attr,
			                is_init);

        /* Try to reset data if it is not a initial case */
        if (drv_status != NVRAM_DRV_OK)
        {
            nvram_trace(TRACE_FUNC, IO_WRITE_DATA_ITEM_MULTIPLE, ldi->LID, drv_status, nvram_drv_fat_get_last_err(), __LINE__);
            status = NVRAM_IO_ERRNO_CHK;
            break;
        }

        if (!multiple)
        {
            break;
        }        

        nvram_util_make_lid_filename(ldi, nvramname, KAL_FALSE);

    }

    return status;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  nvram_write_fs_data_item
 * DESCRIPTION
 *  This is nvram_write_data_item_multiple() function of NVRAM module.
 * PARAMETERS
 *  ldi             [?]
 *  index           [IN]
 *  buffer          [?]
 *  buffer_size     [IN]
 *  is_init         [IN]
 * RETURNS
 *  NVRAM_IO_ERRNO_CHK if all copies are failed to write
 *  NVRAM_IO_ERRNO_OK at least one valid copy is written.
 *****************************************************************************/
static nvram_errno_enum nvram_write_fs_data_item
    (nvram_ltable_entry_struct *ldi, kal_uint16 index, kal_uint8 *buffer, kal_uint32 buffer_size, kal_bool is_init)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_errno_enum status = NVRAM_IO_ERRNO_OK;
    nvram_drv_status_enum drv_status;

    kal_uint32 record_ID;
    NVRAM_FILE_NAME nvramname;

    kal_uint32 file_offset;
    nvram_folder_enum folder_index;
    kal_bool multiple = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NVRAM_IS_ATTR_MULTIPLE(ldi->attr) || NVRAM_IS_ATTR_BACKUP_FAT(ldi->attr))
    {
        multiple = KAL_TRUE;
    }

    folder_index = nvram_query_folder_index(ldi->category);

    file_offset = 0;
    nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);

#ifdef __NVRAM_PSEUDO_MERGE__
    if (NVRAM_IS_ATTR_PACKAGE(ldi->attr))
    {
        file_offset = (kal_uint32) (ldi->description);
        if (!multiple)
        {
            nvram_make_package_filename(nvramname, 'A');
        }
    }
#endif

    for (record_ID = 0; record_ID < 2; record_ID++)
    {

    #ifdef __NVRAM_BACKUP_DISK_FAT__
        if (record_ID == 1 && NVRAM_IS_ATTR_BACKUP_FAT(ldi->attr))
        {
            folder_index = NVRAM_NVD_BAK;
        }
    #endif

    #if defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__) && defined(__CCCIFS_SUPPORT__)
        if (record_ID == 1)
        {
            folder_index = nvram_query_folder_index_ex(ldi->category, KAL_FALSE);
        }
    #endif

        // if LID == SYS_LID, file can be empty & index is the index of record needs to write (amount is 1)
        // if is_init == TRUE, file can be empty & index is the # of record needs to write (index always 1)
        // if is_init == FALSE, file should not be empty & index is the index of record needs to write (amount always 1)

        if(is_init && NVRAM_EF_SYS_LID != ldi->LID)
        {

            drv_status = nvram_drv_fat_write(
                            nvramname,
                            folder_index,
                            file_offset,
                            1,
                            index,
                            buffer_size,
                            buffer,
                            ldi->attr,
                            is_init);

        }
		else
        {
            drv_status = nvram_drv_fat_write(
                            nvramname,
                            folder_index,
                            file_offset,
                            index,
                            1,
                            buffer_size,
                            buffer,
                            ldi->attr,
                            is_init);
        }


        /* Try to reset data if it is not a initial case */
        if (drv_status != NVRAM_DRV_OK)
        {
            nvram_trace(TRACE_FUNC, IO_WRITE_DATA_ITEM_MULTIPLE, ldi->LID, drv_status, nvram_drv_fat_get_last_err(), __LINE__);
            status = NVRAM_IO_ERRNO_CHK;
            break;
        }

        if (!multiple)
        {
            break;
        }        

        nvram_util_make_lid_filename(ldi, nvramname, KAL_FALSE);

    }

    return status;
}

#ifdef __NVRAM_WRITE_WITH_FILE_SIZE__
/*****************************************************************************
 * FUNCTION
 *  nvram_write_mutilpe_data_item
 * DESCRIPTION
 *  write data with lid size but not a record.Support write 1..amount records
 *  one time if (lid->size+checksum) * amount < MAX_NVRAM_RECORD_SIZE
 * PARAMETERS
 *  ldi         [IN]    the data item to be write
 *  rec_idnex   [IN]    the start record index will be write
 *  rec_amount  [IN]    the amount of the records will be write 
 * RETURNS
 *  void
 *****************************************************************************/
static nvram_errno_enum nvram_write_data_item_mutilpe(nvram_ltable_entry_struct *ldi,
                                        kal_uint16 rec_index,
                                        kal_uint16 rec_amount)
{
	
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	nvram_errno_enum status = NVRAM_IO_ERRNO_OK;
		
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	nvram_trace(TRACE_FUNC, IO_WRITE_DATA_ITEM_START, ldi->LID, rec_index, rec_amount);
	nvram_trace(TRACE_INFO, INFO_NVRAM_DATA_ITEM, ldi->LID, ldi->size);

	/******************************************************
	 *	Device Broken
	 ******************************************************/
	if (nvram_ptr->dev_broken)
	{
		nvram_trace(TRACE_FUNC, IO_WRITE_DATA_ITEM_RESULT, ldi->LID, NVRAM_IO_ERRNO_DRV_BROKEN, __LINE__, ldi->LID);
		return status;
	}
	
	/* prepare data */
	if( ldi->default_value == NVRAM_EF_FF_DEFAULT || 
		ldi->default_value == NVRAM_EF_ZERO_DEFAULT)
	{
		kal_uint8 const *default_value = ldi->default_value;
		status = nvram_write_fs_data_item_multiple(ldi,rec_index,rec_amount,default_value,KAL_TRUE);
	}
	else if(ldi->default_value == NULL)
	{
		kal_uint8 const *default_value = NVRAM_EF_FF_DEFAULT;
		status = nvram_write_fs_data_item_multiple(ldi,rec_index,rec_amount,default_value,KAL_TRUE);
	}
	else
	{
		kal_uint8 *default_value_buffer;
		kal_uint32 i;
		kal_uint8 *default_value_p;
		kal_uint8 *def_buff;

		default_value_buffer = (kal_uint8*) get_ctrl_buffer(ldi->size * rec_amount);
		def_buff = (kal_uint8*) get_ctrl_buffer(ldi->size);
		
		for (i = 0; i < rec_amount; i++)
		{
			default_value_p = (kal_uint8*) nvram_get_lid_default_value_to_write(ldi, i, NULL, 0);        
			if (default_value_p == NULL)
			{
	            nvram_get_lid_default_value_to_write(ldi, i, def_buff, ldi->size);
	            default_value_p = def_buff;
	        }			
			kal_mem_cpy(default_value_buffer + i*(ldi->size), default_value_p, ldi->size);
			default_value_p = NULL;
		}
		
		free_ctrl_buffer(def_buff);		
		status = nvram_write_fs_data_item_multiple(ldi,rec_index,rec_amount,default_value_buffer,KAL_TRUE);
		free_ctrl_buffer(default_value_buffer);
	}
	
	if (status != NVRAM_IO_ERRNO_OK)
	{
		/* IMEI and SML */	
		if ((NVRAM_IS_CATEGORY_IMPORTANT(ldi->category)
	#ifdef __SMART_PHONE_MODEM__
	    #if defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__)
				|| NVRAM_IS_CATEGORY_IMPORTANT_L4(ldi->category)) && (ldi->LID != NVRAM_EF_IMPT_COUNTER_LID)
	    #else
			) && (ldi->LID != NVRAM_EF_IMPT_COUNTER_LID)
	    #endif
	#else
	        )
	#endif	
			)
		{
			EXT_ASSERT (KAL_FALSE, DISPLAY_ERROR(status),NVRAM_LOC_WRITE_IMPORTANT_DATA_FAIL , ldi->LID);
			return status;
		}

		nvram_trace(TRACE_FUNC, IO_WRITE_DATA_ITEM_RESULT, ldi->LID, status, __LINE__, KAL_TRUE);
	}

	if (status != NVRAM_IO_ERRNO_OK)
	{
		nvram_trace(TRACE_FUNC, IO_WRITE_DATA_ITEM_RESULT, ldi->LID, status, __LINE__, KAL_TRUE);
		EXT_ASSERT(0, DISPLAY_ERROR(status), NVRAM_LOC_WRITE_AND_RESET_FAIL, ldi->LID);
	}

	return status;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  nvram_reset_one_data_item
 * DESCRIPTION
 *  Reset only one data item
 * PARAMETERS
 *  ldi         [IN]    the data item to reset
 *  buffer      [IN]    buffer which has enough space
 *  buffer_size [IN]    the max buffer size
 * RETURNS
 *  void
 *****************************************************************************/
static nvram_errno_enum nvram_reset_one_data_item(nvram_ltable_entry_struct *ldi,
                                        kal_uint16 rec_index,
                                        kal_uint16 rec_amount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *default_value;
    kal_uint32 i , start, end;
    kal_uint8 *default_value_buffer;
    kal_uint32 working_buffer_size = 0;
    nvram_errno_enum result = NVRAM_IO_ERRNO_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (rec_index < 1 ||
        rec_index > ldi->total_records ||
        rec_amount < 1 ||
        rec_amount > ldi->total_records - rec_index + 1)
    {
        /* arguments invalid */
        start = 1;
        end = ldi->total_records;
    }
    else
    {
        start = rec_index,
        end = rec_index + rec_amount - 1;
    }

#if defined(__MTK_TARGET__) && defined(__NVRAM_WRITE_WITH_FILE_SIZE__)
	do
	{	
		if (KAL_FALSE == bResetNvramData 
			|| KAL_FALSE == kal_query_systemInit()   //initiation
			|| (ldi->size + NVRAM_CHKSUM_SIZE) > MAX_NVRAM_RECORD_SIZE   //large record
			|| ldi->LID == NVRAM_EF_SYS_LID
		#ifdef __NVRAM_OTP__		
			|| NVRAM_IS_CATEGORY_OTP(ldi->category)
		#endif
		#ifdef __NVRAM_CUSTOM_DISK__
			|| NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category)
		#endif		
		#ifdef __NVRAM_PSEUDO_MERGE__
	    	|| NVRAM_IS_ATTR_PACKAGE(ldi->attr)
	    #endif
			)
		{			
			break;
		}
			
		// only support reset 1..total_records
		if (start == 1 && end == ldi->total_records)
		{
			kal_uint32 remainLen = 0;
			default_value = NULL;
			default_value_buffer = NULL;
		
			#ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
		    if (ldi->attr & NVRAM_ATTR_MSP)
		    {
		        /* 4 byte alignment */
		        remainLen = NVRAM_MSP_ALIGNMENT_REMAINDER(ldi->size + NVRAM_CHKSUM_SIZE);
		    }
			#endif
			
			working_buffer_size = (ldi->size + NVRAM_CHKSUM_SIZE + remainLen) * ldi->total_records;
						
		    if (working_buffer_size <= MAX_NVRAM_RECORD_SIZE)
		    {
				result = nvram_write_data_item_mutilpe(ldi,1,ldi->total_records);
				return result;
		    }			
		}
		break;
		
	}while(0);
#endif

    //default_value_buffer = (kal_uint8*) get_ctrl_buffer(MAX_NVRAM_RECORD_SIZE);
    working_buffer_size = ldi->size * rec_amount;
    if ((start == 1) && (end == ldi->total_records))
    {
        working_buffer_size = ldi->size * ldi->total_records;
    }

    if (working_buffer_size > MAX_NVRAM_RECORD_SIZE)
    {
        working_buffer_size = MAX_NVRAM_RECORD_SIZE;
    }

    default_value_buffer = (kal_uint8*) get_ctrl_buffer(working_buffer_size);

    for (i = start; i <= end; i++)
    {
        /* when ldi size too big, we cannot operator it on buffer,
           use original default value pointer directly */

        default_value = (kal_uint8*) nvram_get_default_value_to_write(ldi, i, NULL, 0);

        /* the default_value is not assigned in table , ex: L1 LID */
        if (default_value == NULL)
        {
            nvram_get_default_value_to_write(ldi, i, default_value_buffer, working_buffer_size);
            default_value = default_value_buffer;
        }

        /* initial case, we reset it directly to enhance performance*/
        if (start == 1 && end == ldi->total_records)
        {
            if(NVRAM_EF_SYS_LID == ldi->LID)
            {
                result = nvram_write_data_item(ldi, i, default_value, KAL_TRUE);
                if (result != NVRAM_IO_ERRNO_OK)
                {
                    break;
                }                
            }
            else
            {
                result = nvram_write_data_item(ldi, ldi->total_records, default_value, KAL_TRUE);
                break;
            }
        }
        else
        {
            result = nvram_write_data_item(ldi, i, default_value, KAL_FALSE);

            if (result != NVRAM_IO_ERRNO_OK)
            {
                break;
            }
        }
    }

    free_ctrl_buffer(default_value_buffer);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_reset_one_data_item
 * DESCRIPTION
 *  Reset only one data item
 * PARAMETERS
 *  ldi         [IN]    the data item to reset
 *  buffer      [IN]    buffer which has enough space
 *  buffer_size [IN]    the max buffer size
 * RETURNS
 *  void
 *****************************************************************************/
static nvram_errno_enum nvram_reset_category(nvram_category_enum included, nvram_category_enum excluded)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi = &logical_data_item_table[0];
    nvram_errno_enum result = NVRAM_IO_ERRNO_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do
    {
        if (ldi->category & excluded)
        {
            continue;
        }

        /*
         *  special handle for reset all
         */
        if (included == NVRAM_CATEGORY_ALL)
        {
        #ifdef __NVRAM_BACKUP_DISK__
            /* recover the data from backup partition */
            if (NVRAM_IS_ATTR_BACKUP_FAT(ldi->attr) || NVRAM_IS_ATTR_BACKUP_RAW(ldi->attr))
            {
                if (nvram_recover_image_by_lid(ldi) == NVRAM_ERRNO_SUCCESS)
                {
                    continue;
                }
            }
        #endif
        #ifdef __NVRAM_CUSTOM_DISK__
            if (NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category))
            {
                if (nvram_read_custom_disk(ldi, 1, ldi->total_records, NULL, 0) == NVRAM_IO_ERRNO_OK)
                {
                    /* do not reset the data in custom disk */
                    continue;
                }
            }
        #endif
        }

        if (included == NVRAM_CATEGORY_ALL || ldi->category & included)
        {
            result = nvram_reset_one_data_item(ldi, 1, ldi->total_records);
        }

        if (result != NVRAM_IO_ERRNO_OK)
        {
            break;
        }
    }while(nvram_util_next_data_item(&ldi));

    return result;

}

/*****************************************************************************
 * FUNCTION
 *  nvram_reset_one_data_item
 * DESCRIPTION
 *  Reset only one data item
 * PARAMETERS
 *  ldi         [IN]    the data item to reset
 *  buffer      [IN]    buffer which has enough space
 *  buffer_size [IN]    the max buffer size
 * RETURNS
 *  void
 *****************************************************************************/
static nvram_errno_enum nvram_reset_attr(nvram_attr_enum included, nvram_attr_enum excluded)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi = &logical_data_item_table[0];
    nvram_errno_enum result = NVRAM_IO_ERRNO_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do
    {

        if (ldi->attr & excluded)
        {
            continue;
        }

        if (included == NVRAM_ATTR_ALL || ldi->attr & included)
        {
            result = nvram_reset_one_data_item(ldi, 1, ldi->total_records);
        }

        if (result != NVRAM_IO_ERRNO_OK)
        {
            break;
        }
    }while(nvram_util_next_data_item(&ldi));

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_reset_data_items
 * DESCRIPTION
 *  This is nvram_reset_data_item() function of NVRAM module.
 *
 *  When invoking nvram_write_data_item(), `is_init' flag is ALWAYS TRUE;
 *  such that for each data item to be written:
 *
 *  1. Driver Layer could delete records of the data item, if it
 *  already exists.
 *  (In current flash driver, namely fd, this function is fd_rcd_delete())
 *
 *  2. Then Driver Layer write default value to each record of the data item.
 *  (In current flash driver, namely fd, this function is fd_rcd_initialize())
 *
 *  This function may be invoked due to incompatible version.
 *  For data items located in the `reset_category',
 *  they may be (1) newly added, (2)newly removed, or (3)just default value modified.
 *  Consider invoking nvram_write_data_item() with `is_init' flag set to true for
 *  each case:
 *  (1) Newly added:
 *  Invoke fd_rcd_delete() to delete records of the data item is no effect.
 *  fd_rcd_initialize() will allocate spaces for that data item.
 *
 *  (2) Newly deleted:
 *  This results in a effect of "shift" due to some data item LID's are deleted.
 *  It should be ok since fd_rcd_delete()/fd_rcd_initialize() will be called
 *  for each valid LID. Of course, some out-of-dated LID's are possibly
 *  left and occupies FLASH space.
 *
 *  (3) Default value modified:
 *  This is ok.
 * PARAMETERS
 *  reset_category      [IN]        Coubld be NVRAM_RESET_ALL NVRAM_RESET_SYSTEM NVRAM_RESET_USER
 *  ldi                 [?]
 * RETURNS
 *
 *****************************************************************************/
kal_bool nvram_reset_data_items(
            nvram_reset_category_enum reset_category,
            nvram_app_id_enum   app_id,
            nvram_ltable_entry_struct *ldi,
            kal_uint16 rec_index,
            kal_uint16 rec_amount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool lock_state = nvram_ptr->lock;
    kal_bool status = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ldi)
    {
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_RESET_DATA_ITEMS, reset_category, nvram_ptr->state, ldi->LID, rec_index);
    }
    else
    {
        nvram_trace(TRACE_FUNC, FUNC_NVRAM_RESET_DATA_ITEMS, reset_category, nvram_ptr->state);
    }

    /* Since reset is highest priority, the software lock must be unlocked temporarily. */
    nvram_ptr->lock = KAL_FALSE;

    /* Since entire logical data item is to be reset, nvram_write_data_item() is invoked. */
    switch (reset_category)
    {
        case NVRAM_RESET_CERTAIN:
        {
            #ifdef __NVRAM_OTP__
                if(ldi && (ldi->category & NVRAM_CATEGORY_OTP))
                {
                    /*
                     * if from nvram init, return true.
                     */
                    if (nvram_ptr->state != NVRAM_STATE_READY)
                    {
                        return KAL_TRUE;
                    }
                    else
                    {
                        return KAL_FALSE;
                    }
                }
            #endif /* __NVRAM_OTP__ */

                nvram_reset_one_data_item(ldi, rec_index, rec_amount);
            break;
        }

        case NVRAM_RESET_ALL:
        {
            {

            #ifdef __NVRAM_PSEUDO_MERGE__
                nvram_calculate_write_data_offset(NULL, KAL_TRUE);
            #endif

                if (nvram_ptr->sw_status & NVRAM_SW_EMPTY_FAT)
                {
                    nvram_reset_category(NVRAM_CATEGORY_ALL, 0);
                }
                else
                {
                #if defined(__CCCIFS_SUPPORT__)
                    nvram_reset_category(NVRAM_CATEGORY_ALL, NVRAM_CATEGORY_IMPORTANT | NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_IMPORTANT_L4);
                #else
                    nvram_reset_category(NVRAM_CATEGORY_ALL, NVRAM_CATEGORY_IMPORTANT);
                #endif
                }
            }

            nvram_factory_rmdir_user(NVRAM_RESET_ALL);

            break;
        }
    #ifdef __NVRAM_PSEUDO_MERGE__
        case NVRAM_RESET_PACKAGE:
        {
            /* write information of package LID into info_file */
            nvram_calculate_write_data_offset(NULL, KAL_TRUE);
            nvram_reset_attr(NVRAM_ATTR_PACKAGE, 0);
            break;
        }
    #endif /* __NVRAM_PSEUDO_MERGE__ */
        case NVRAM_RESET_FACTORY:
        {
            if (nvram_ptr->state != NVRAM_STATE_READY)/* init stage */
            {
                nvram_reset_attr(NVRAM_ATTR_FACTORY_RESET, 0);
                //nvram_factory_restore_mmi_cache(NVRAM_RESET_FACTORY, app_id);
                nvram_factory_restore_sys_cache(NVRAM_RESET_FACTORY, app_id);
                nvram_factory_rmdir_user(NVRAM_RESET_FACTORY);
                nvram_set_restore_factory_flag(NVRAM_RESTORE_TRUE);
            }
            else
            {
                nvram_set_restore_factory_flag(NVRAM_RESTORE_TRUE);
            }
            break;
        }
        case NVRAM_RESET_BRANCH:
        {
            nvram_reset_category(NVRAM_CATEGORY_ALL, NVRAM_CATEGORY_IMPORTANT | NVRAM_CATEGORY_IMPORTANT_L4 | NVRAM_CATEGORY_CALIBRAT);
            nvram_factory_rmdir_user(NVRAM_RESET_BRANCH);
            break;
        }
    #ifdef __NVRAM_SUPPORT_CUSTPACK__
        case NVRAM_RESET_CUSTPACK:
        {
            nvram_reset_category(NVRAM_CATEGORY_CUSTPACK, 0);

            nvram_util_get_data_item(&ldi, NVRAM_EF_CUSTPACK_VERNO_LID);
            nvram_reset_one_data_item(ldi, 1, ldi->total_records);

            break;
        }
    #endif
    #ifdef __SECURE_RO_ENABLE__    
        case NVRAM_RESET_SECUPACK:
        {
            nvram_reset_category(NVRAM_CATEGORY_SECUPACK, 0);

            nvram_util_get_data_item(&ldi, NVRAM_EF_SECUPACK_VERNO_LID);
            nvram_reset_one_data_item(ldi, 1, ldi->total_records);

            break;
        }
    #endif    
       
        default:
        {
            ASSERT(KAL_FALSE);
            status = KAL_FALSE;
        }
    }

    /* Restore lock state */
    nvram_ptr->lock = lock_state;

    return status;
}   /* end of nvram_reset_data_item */


/*****************************************************************************
 * FUNCTION
 *  nvram_factory_restore_sys_cache
 * DESCRIPTION
 *  Reset system cache
 * PARAMETERS
 *  void
 * RETURNS
 *  Success or not
 *****************************************************************************/
static kal_bool nvram_factory_restore_sys_cache(nvram_reset_category_enum category, nvram_app_id_enum app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 record_idx;
    nvram_ltable_entry_struct *ldi;
    kal_uint8 *buffer;
    kal_uint8 *tmp_buffer;
	nvram_drv_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_CACHE_OCTET_LID);
    buffer = (kal_uint8*)get_ctrl_buffer(ldi->total_records * ldi->size);

    if (NVRAM_IO_ERRNO_OK == (status = nvram_read_data_item(ldi, 1, ldi->total_records, buffer, ldi->total_records * ldi->size)))
    {
//        nvram_restore_system_cache(category, app_id, buffer);
        nvram_restore_system_cache(category, 0, buffer);

        for (record_idx = 1; record_idx < ldi->total_records; record_idx++)
        {
            tmp_buffer = buffer + ldi->size * (record_idx - 1);
            nvram_write_data_item(ldi, (kal_uint16)record_idx, tmp_buffer, KAL_FALSE);
        }

    }
    else
    {
//        ASSERT(0);
        EXT_ASSERT(0, DISPLAY_ERROR(status), NVRAM_LOC_READ_SYS_CACHE_FAIL, status);
    }

    free_ctrl_buffer(buffer);

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_factory_rmdir_user
 * DESCRIPTION
 *  Remove customizable folder list
 * PARAMETERS
 *  void
 * RETURNS
 *  Success or not
 *****************************************************************************/
static kal_bool nvram_factory_rmdir_user(nvram_reset_category_enum category)
{

#ifdef __MMI_FMI__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 dir_idx;
    nvram_clean_folder_enum clean_folder_category;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (category)
    {
        case NVRAM_RESET_ALL:
            clean_folder_category = NVRAM_CLEAN_FOLDER_ALL;
            break;
        case NVRAM_RESET_BRANCH:
            clean_folder_category = NVRAM_CLEAN_FOLDER_BRANCH;
            break;
        case NVRAM_RESET_FACTORY:
            clean_folder_category = NVRAM_CLEAN_FOLDER_FACTORY;
            break;
        default:
            clean_folder_category = NVRAM_CLEAN_FOLDER_NONE;
        break;
    }

    if (clean_folder_category != NVRAM_CLEAN_FOLDER_NONE)
    {
        for (dir_idx = nvram_custom_max_clean_folder_size() - 1; dir_idx >= 0 ; dir_idx--)
        {
            if ((clean_folder_category & nvram_clean_folder_list[dir_idx].category) &&
                nvram_clean_folder_list[dir_idx].folder_path != NULL)
            {
                FS_XDelete(nvram_clean_folder_list[dir_idx].folder_path, (FS_FILE_TYPE | FS_RECURSIVE_TYPE), NULL, 0);
            }
        }
    }
#endif /* __MMI_FMI__ */
    return KAL_TRUE;
}


#if defined(__CCCIFS_SUPPORT__) && defined(__MTK_TARGET__)

/*****************************************************************************
 * FUNCTION
 *  nvram_recover_data_item
 * DESCRIPTION
 *  Data item auto-receovery for smart phone
 * PARAMETERS
 *  ldi             [?]
  * RETURNS
 *  kal_int32   error code from AP FS
 *****************************************************************************/
kal_int32 nvram_recover_data_item(nvram_ltable_entry_struct *ldi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    kal_int32 drv_status[2] = {0, 0};
    NVRAM_FILE_NAME nvramname;
    nvram_folder_enum folder_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    folder_index = nvram_query_folder_index(ldi->category);
    
    nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);
    drv_status[0] = nvram_drv_fat_auto_recover(nvramname, folder_index);

    nvram_trace(TRACE_FUNC, IO_READ_DATA_ITEM_MULTIPLE, ldi->LID, drv_status[0], nvram_drv_fat_get_last_err(), __LINE__);

    if (NVRAM_IS_ATTR_MULTIPLE(ldi->attr))
    {
        nvram_util_make_lid_filename(ldi, nvramname, KAL_FALSE);
        drv_status[1] = nvram_drv_fat_auto_recover(nvramname, folder_index);
        nvram_trace(TRACE_FUNC, IO_READ_DATA_ITEM_MULTIPLE, ldi->LID, drv_status[1], nvram_drv_fat_get_last_err(), __LINE__);
    }
    
    if ((drv_status[0] != 0) || (drv_status[1] != 0))
    {
//        EXT_ASSERT(KAL_FALSE, drv_status[0], drv_status[1], __LINE__);
        EXT_ASSERT(KAL_FALSE, drv_status[0]?drv_status[0]:drv_status[1], NVRAM_LOC_BIN_REGION_RESTORE_FAIL, ldi->LID);
    }

    return NVRAM_IO_ERRNO_OK;
}

#if defined(__NVRAM_IMPORTANT_PARTITIONS__)
    
/*****************************************************************************
 * FUNCTION
 *  nvram_recover_protect
 * DESCRIPTION
 *  Recover important data from obsolete folder to protect partition
 * PARAMETERS
 *  ldi             [?]
  * RETURNS
 *  kal_int32   error code from AP FS
 *****************************************************************************/
kal_int32 nvram_recover_protect(nvram_ltable_entry_struct *ldi)
{
    kal_wchar *filename_new, *filename_old;
    NVRAM_FILE_NAME nvram_name;
    nvram_folder_enum folder_index;
    
    if (!NVRAM_IS_CATEGORY_IMPORTANT_L4(ldi->category))
    return NVRAM_IO_ERRNO_OK;

    filename_new = (kal_wchar *)get_ctrl_buffer(NVRAM_MAX_PATH_LEN * sizeof(kal_wchar));
    filename_old = (kal_wchar *)get_ctrl_buffer(NVRAM_MAX_PATH_LEN * sizeof(kal_wchar));

    // move first copy
    folder_index = nvram_query_folder_index_ex(ldi->category, KAL_TRUE);
    nvram_util_make_lid_filename(ldi, nvram_name, KAL_TRUE);
    nvram_query_file_name(folder_index, nvram_name, filename_new);
    nvram_query_file_name(NVRAM_NVD_IMPNT3, nvram_name, filename_old);
    FS_Move(filename_old, filename_new, FS_MOVE_COPY, NULL, NULL, 0);

    // move second copy
    folder_index = nvram_query_folder_index_ex(ldi->category, KAL_FALSE);
    nvram_util_make_lid_filename(ldi, nvram_name, KAL_FALSE);
    nvram_query_file_name(folder_index, nvram_name, filename_new);
    nvram_query_file_name(NVRAM_NVD_IMPNT3, nvram_name, filename_old);
    FS_Move(filename_old, filename_new, FS_MOVE_COPY, NULL, NULL, 0);

    free_ctrl_buffer(filename_new);
    free_ctrl_buffer(filename_old);

    return NVRAM_IO_ERRNO_OK;
}
#endif

#endif

