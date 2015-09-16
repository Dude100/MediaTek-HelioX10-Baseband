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
 * nvram_ex_io.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_public_api.h" //MSBB change #include "kal_release.h"        /* Basic data type */

#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
//MSBB remove #include "app_buff_alloc.h"     /* Declaration of buffer management API */

#include "nvram_main.h"
#include "nvram_io.h"

/* For FAT */
#include "fs_gprot.h"
#include "fs_iprot.h"

#ifdef __NVRAM_OTP__
#ifndef __MTK_TARGET__

nvram_ltable_entry_struct ldi_otp =
{
    NVRAM_EF_RESERVED_LID - 1,
    256,
    1,
    NVRAM_EF_ZERO_DEFAULT,
    NVRAM_CATEGORY_USER,
    NVRAM_ATTR_AVERAGE,    
    "CT05",
    "000",
    "Fake OTP\0"
};


/*****************************************************************************
 * FUNCTION
 *  OTP_Read_FAKE
 * DESCRIPTION
 * PARAMETERS
 *  Offset          [IN]
 *  BufferPtr       [?]
 *  Length          [IN]
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
int OTP_Read_FAKE(kal_uint32 Offset, void *BufferPtr, kal_uint32 Length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE hFile = 0;
    kal_uint32 len = 0;
    kal_int32 Ret = FS_FLASH_OTP_UNKNOWERR;
    kal_uint16 chksum1 = 0, chksum2 = 0;
    kal_uint32 i;
    NVRAM_FILE_NAME nvramname;
    nvram_ltable_entry_struct *ldi = &ldi_otp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(BufferPtr);

    nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);

    /* translate record id to filename */
    nvram_query_file_name(NVRAM_NVD_DATA, nvramname, filename);

    /* open NV_RCD.(RCD#) file */
    hFile = FS_Open((const WCHAR*)filename, FS_READ_WRITE | FS_CREATE);
    if (hFile == FS_FILE_NOT_FOUND)
    {
        FS_Close(hFile);
        return FS_FLASH_OTP_UNKNOWERR;
    }
    else if (hFile <= FS_NO_ERROR)
    {
        FS_Close(hFile);
        return FS_FLASH_OTP_UNKNOWERR;
    }

    len = 256;
    if ((Offset + Length) > len)
    {
        FS_Close(hFile);
        return FS_FLASH_OTP_OVERSCOPE;
    }

    /* check if a empty record */
    Ret = FS_GetFileSize(hFile, &len);
    if ((Ret == FS_NO_ERROR) && (len == 0))
    {
        FS_Close(hFile);
        return FS_FLASH_OTP_UNKNOWERR;
    }

    /* seek to the record start */
    Ret = FS_Seek(hFile, Offset, FS_FILE_BEGIN);
    if (Ret >= FS_NO_ERROR)
    {
        Ret = FS_Read(hFile, BufferPtr, Length, &len);
    }

    if (Ret != FS_NO_ERROR)
    {
        FS_Close(hFile);
        return FS_FLASH_OTP_UNKNOWERR;
    }

    FS_Close(hFile);
    return FS_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  OTP_Write_FAKE
 * DESCRIPTION
 * PARAMETERS
 *  Offset          [IN]
 *  BufferPtr       [?]
 *  Length          [IN]
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
int OTP_Write_FAKE(kal_uint32 Offset, void *BufferPtr, kal_uint32 Length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE hFile = 0;
    kal_uint32 len = 0;
    kal_int32 Ret = FS_FLASH_OTP_UNKNOWERR;
    kal_int32 openOption = FS_READ_WRITE | FS_OPEN_NO_DIR;
    kal_uint16 chksum = 0;
    kal_uint8 *buffer_with_chksum;
    NVRAM_FILE_NAME nvramname;
    nvram_ltable_entry_struct *ldi = &ldi_otp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);

    /* translate record id to filename */
    nvram_query_file_name(NVRAM_NVD_DATA, nvramname, filename);

    openOption |= FS_CREATE;
#if !defined(_NAND_FLASH_BOOTING_) && !defined(__FS_SYSDRV_ON_NAND__)
    openOption |= FS_PROTECTION_MODE;
#endif
    openOption |= FS_READ_WRITE;

    nvram_trace(TRACE_FUNC, OTP_FAKE_WRITE, Offset, Offset + Length - 1);

    hFile = FS_Open((const WCHAR*)filename, openOption);

    if (hFile == FS_FILE_NOT_FOUND)
    {
        if (nvram_ptr->state != NVRAM_STATE_READY)
        {
            nvram_trace(TRACE_FUNC, OTP_INIT);
            /* Reinitialize, Create always, No committed */
            openOption |= FS_CREATE_ALWAYS;
            hFile = FS_Open((const WCHAR*)filename, openOption);
            if (hFile >= FS_NO_ERROR)
            {
                buffer_with_chksum = (kal_uint8*) get_ctrl_buffer(Length);
                ASSERT(buffer_with_chksum);
                memset(buffer_with_chksum, 0x00, Length);
                /* init fake OTP file */
                Ret = FS_Write(hFile, buffer_with_chksum, ldi->size, &len);
                ASSERT(Ret >= FS_NO_ERROR);
                free_ctrl_buffer(buffer_with_chksum);
                FS_Close(hFile);
                return FS_NO_ERROR;
            }
        }
        else
            return FS_FLASH_OTP_WRITEFAIL;
    }
    ASSERT(hFile >= FS_NO_ERROR);

    /* start write */

    /* Update one of the sections if linear-fixed */
    Ret = FS_GetFileSize(hFile, &len);
    if ((Ret == FS_NO_ERROR) && (len == 0))
    {
        if (nvram_ptr->state != NVRAM_STATE_READY)
        {
            FS_Close(hFile);

            nvram_trace(TRACE_FUNC, OTP_INIT);
            /* Reinitialize, Create always, No committed */
            openOption |= FS_CREATE_ALWAYS;
            hFile = FS_Open((const WCHAR*)filename, openOption);
            if (hFile >= FS_NO_ERROR)
            {
                buffer_with_chksum = (kal_uint8*) get_ctrl_buffer(Length);
                ASSERT(buffer_with_chksum);
                memset(buffer_with_chksum, 0x00, Length);
                /* init fake OTP file */
                Ret = FS_Write(hFile, buffer_with_chksum, ldi->size, &len);
                ASSERT(Ret >= FS_NO_ERROR);
                free_ctrl_buffer(buffer_with_chksum);
                FS_Close(hFile);
                return FS_NO_ERROR;
            }
        }
        else
            return FS_FLASH_OTP_WRITEFAIL;

    }

    /* seek to the section start in this record */
    Ret = FS_Seek(hFile, Offset, FS_FILE_BEGIN);
    if (Ret >= FS_NO_ERROR)
    {
        kal_uint8 i = 0;

        nvram_trace(TRACE_FUNC, OTP_AREA_ALLOW, Ret, Ret + Length - 1);
        buffer_with_chksum = (kal_uint8*) get_ctrl_buffer(Length);
        ASSERT(buffer_with_chksum);
        Ret = FS_Read(hFile, buffer_with_chksum, Length, &len);
        for (i = 0; i < Length; ++i)
        {
            if (buffer_with_chksum[i])
            {
                nvram_trace(TRACE_FUNC, OTP_PROGRAM_TWICE, Offset, Offset + Length - 1);
                free_ctrl_buffer(buffer_with_chksum);
                FS_Close(hFile);
                return FS_FLASH_OTP_WRITEFAIL;
            }
        }

        kal_mem_cpy(buffer_with_chksum, BufferPtr, Length);
        Ret = FS_Seek(hFile, Offset, FS_FILE_BEGIN);

        Ret = FS_Write(hFile, buffer_with_chksum, Length, &len);
        ASSERT(Ret == FS_NO_ERROR);
        if (Ret != FS_NO_ERROR)
        {
            free_ctrl_buffer(buffer_with_chksum);
            FS_Close(hFile);
            return Ret;
        }
        free_ctrl_buffer(buffer_with_chksum);
    }
    else
    {
        FS_Close(hFile);
        nvram_trace(TRACE_FUNC, OTP_OVERSCOPE, Offset, Offset + Length - 1);
        return FS_FLASH_OTP_OVERSCOPE;
    }

    FS_Close(hFile);
    return FS_NO_ERROR;
}
#endif /* __MTK_TARGET__ */


/*****************************************************************************
 * FUNCTION
 *  nvram_read_otp_data_item
 * DESCRIPTION
 * PARAMETERS
 *  ldi             [?]
 *  rec_index       [IN]
 *  rec_amount      [IN]
 *  buffer          [?]
 *  buffer_size     [IN]
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
nvram_errno_enum nvram_read_otp_data_item(
                    nvram_ltable_entry_struct *ldi,
                    kal_uint16 rec_index,
                    kal_uint16 rec_amount,
                    kal_uint8 *buffer,
                    kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 offset = 0;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!NVRAM_IS_CATEGORY_OTP(ldi->category))
    {
        return NVRAM_IO_ERRNO_INVALID_LID;
    }

    if (ldi->size * rec_amount > buffer_size)
    {
        return NVRAM_IO_ERRNO_INVALID_SIZE;
    }

    offset = nvram_get_otp_offset(ldi->LID);

    offset += (rec_index - 1) * ldi->size;

#ifndef __MTK_TARGET__
    result = OTP_Read_FAKE(offset, buffer, ldi->size * rec_amount);
#else
    result = FS_OTPRead(FS_DEVICE_TYPE_UNKNOWN, offset, buffer, ldi->size * rec_amount);
#endif

    nvram_trace(TRACE_FUNC, OTP_READ_RESULT, result, offset, offset + ldi->size - 1);

    if (result < FS_NO_ERROR)
    {
        return NVRAM_ERRNO_FAIL;
    }
    else
    {
        return NVRAM_ERRNO_SUCCESS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  nvram_write_otp_data_item
 * DESCRIPTION
 * PARAMETERS
 *  ldi             [?]
 *  index           [IN]
 *  data            [?]
 *  buffer_size     [IN]
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/

static kal_int32 nvram_translate_otp_error_code(kal_int32 fs_err_code)
{
    // NVRAM_LOG1(TRACE_FUNC, OTP_WRITE_RESULT, fs_err_code);

    switch (fs_err_code)
    {
        case FS_FLASH_OTP_UNKNOWERR:    /* -123 */
            return NVRAM_ERRNO_OTP_UNKNOW;
        case FS_FLASH_OTP_OVERSCOPE:    /* -124 */
            return NVRAM_ERRNO_OTP_OVERSCOPE;
        case FS_FLASH_OTP_WRITEFAIL:    /* -125 */
            return NVRAM_ERRNO_OTP_WRITEFAIL;
        default:
            if (fs_err_code < FS_NO_ERROR)
                return NVRAM_ERRNO_FAIL;
            else
                return NVRAM_ERRNO_SUCCESS;

    }
    return NVRAM_IO_ERRNO_OK;
}

nvram_errno_enum nvram_write_otp_data_item(
                    nvram_ltable_entry_struct *ldi,
                    kal_uint16 index,
                    kal_uint8 *data,
                    kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 offset;
    nvram_errno_enum result=NVRAM_IO_ERRNO_OK;
    kal_uint32 fs_otp_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!NVRAM_IS_CATEGORY_OTP(ldi->category))
    {
        return NVRAM_IO_ERRNO_INVALID_LID;
    }

    offset = nvram_get_otp_offset(ldi->LID);
    offset += (index - 1) * ldi->size;

#ifdef __MTK_TARGET__
    FS_OTPQueryLength(FS_DEVICE_TYPE_UNKNOWN, &fs_otp_size);
#else
    fs_otp_size = 256;
#endif

    if ((offset + ldi->size) > fs_otp_size)
    {
        return NVRAM_ERRNO_OTP_INVALID_RANGE;
    }

#ifndef __MTK_TARGET__
    result = OTP_Write_FAKE(offset, data, ldi->size);
#else /* __MTK_TARGET__ */
    {
        kal_uint8 *buffer = (kal_uint8*) get_ctrl_buffer(ldi->size);
        ASSERT(buffer);

        do {
            kal_uint32 i = 0;
            kal_uint8 is_empty = 1;
            kal_int32 fs_result = FS_NO_ERROR;

            FS_OTPRead(FS_DEVICE_TYPE_UNKNOWN, offset, buffer, ldi->size);

            for (; i < ldi->size; i++)
            {
                if ((buffer[i] != 0xFF && buffer[i] != 0x00) || (buffer[i] != buffer[0]))
                {
                    //NVRAM_LOG2(TRACE_FUNC, OTP_PROGRAM_TWICE, offset, offset + ldi->size - 1);
                    result = NVRAM_ERRNO_OTP_WRITETWICE;
                    goto error_return;
                }

                if ((data[i] != 0xFF && data[i] != 0x00) || data[i] != data[0])
                {
                    is_empty = 0;
                }
            }

            if (is_empty)
            {
                result = NVRAM_ERRNO_OTP_INVALID_INPUT;
                break;
            }

            fs_result = FS_OTPWrite(FS_DEVICE_TYPE_UNKNOWN, offset, data, ldi->size);

            if (fs_result < 0)
            {
                result = nvram_translate_otp_error_code(fs_result);
                break;
            }

            FS_OTPRead(FS_DEVICE_TYPE_UNKNOWN, offset, buffer, ldi->size);

            if (kal_mem_cmp(data, buffer, ldi->size) != 0)
            {
                result=NVRAM_ERRNO_OTP_WRITEFAIL;
                break;
            }

        } while(0);

error_return:
        free_ctrl_buffer(buffer);
    }
#endif /* __MTK_TARGET__ */

    return result;
}

#endif /* __NVRAM_OTP__ */

#if defined(__CUSTOMER_TC01_DISK__) && defined (__MTK_TARGET__)

#include "..\..\lgesrc\lgeSecurity\lge_fw_factory_data.h"

/*****************************************************************************
 * FUNCTION
 *  nvram_read_raw_disk
 * DESCRIPTION
 * PARAMETERS
 *  ldi             [?]
 *  rec_index       [IN]
 *  rec_amount      [IN]
 *  buffer          [?]
 *  buffer_size     [IN]
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
nvram_errno_enum nvram_read_custom_disk(
                    nvram_ltable_entry_struct *ldi,
                    kal_uint16 rec_index,
                    kal_uint16 rec_amount,
                    kal_uint8 *buffer,
                    kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 imei[NVRAM_EF_IMEI_IMEI_SIZE << 1];
    kal_int32 i, j;
    kal_bool result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(ldi->LID)
    {
    case NVRAM_EF_IMEI_IMEISV_LID:

        if (buffer && buffer_size < NVRAM_EF_IMEI_IMEI_SIZE * rec_amount)
        {
            ASSERT(0);
            return NVRAM_IO_ERRNO_INVALID_SIZE;
        }

        if (buffer)
        {
            memset(buffer, 0, NVRAM_EF_IMEI_IMEI_SIZE * rec_amount);
        }

        for (i = 0 ; i < rec_amount ; i++)
        {
            memset(imei, 0, NVRAM_EF_IMEI_IMEI_SIZE << 1);

            if ((rec_index  + i) == 1)
            {
                result = LGE_FacReadImei(1, imei);
            }
            else if ((rec_index  + i) == 2)
            {
                result = LGE_FacReadImei(0, imei);
            }
            else
            {
                result = LGE_FacReadImei(2, imei);
            }

            if (result == KAL_FALSE)
            {
                kal_wap_trace(MOD_NVRAM, TRACE_FUNC, "[ws_nvram] read imei fail, result = %d, rec_index = %d", result, rec_index);
                return NVRAM_ERRNO_FAIL;
            }

            kal_wap_trace(MOD_NVRAM, TRACE_FUNC, "[ws_nvram] imei(wise format): %02x %02x %02x %02x %02x %02x %02x %02x",
                                   imei[0], imei[1], imei[2], imei[3], imei[4], imei[5], imei[6], imei[7]);

            if (buffer)
            {
                kal_uint8 *tmp = buffer + NVRAM_EF_IMEI_IMEI_SIZE * i;

                for (j = 0 ; j < NVRAM_EF_IMEI_IMEI_SIZE ; j++)
                {
                    tmp[j] = (imei[j << 1] & 0x0F) | ((imei[(j << 1) + 1] & 0x0F) << 4);
                }
                kal_wap_trace(MOD_NVRAM, TRACE_FUNC, "[ws_nvram] imei(mtk format): %02x %02x %02x %02x %02x %02x %02x %02x",
                                       tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5], tmp[6], tmp[7]);
            }
        }

        break;
    default:
        ASSERT(0);
        return NVRAM_IO_ERRNO_INVALID_LID;
    }

    return NVRAM_IO_ERRNO_OK;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_write_raw_disk
 * DESCRIPTION
 * PARAMETERS
 *  ldi             [?]
 *  index           [IN]
 *  data            [?]
 *  buffer_size     [IN]
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
nvram_errno_enum nvram_write_custom_disk(
                    nvram_ltable_entry_struct *ldi,
                    kal_uint16 rec_index,
                    kal_uint8 *data,
                    kal_uint32 buffer_size,
                    kal_bool is_init)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 imei[NVRAM_EF_IMEI_IMEI_SIZE << 1];
    kal_int32 i;
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(ldi->LID)
    {
    case NVRAM_EF_IMEI_IMEISV_LID:

        kal_wap_trace(MOD_NVRAM, TRACE_FUNC, "[ws_nvram] imei(mtk format): %02x %02x %02x %02x %02x %02x %02x %02x",
                               data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);

        for (i = 0 ;i < NVRAM_EF_IMEI_IMEI_SIZE ;i++)
        {
            imei[i << 1] = data[i] & 0x0F;
            imei[(i << 1) + 1] = (data[i] & 0xF0) >> 4;
        }

        kal_wap_trace(MOD_NVRAM, TRACE_FUNC, "[ws_nvram] imei(wise format): %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
                               imei[0], imei[1], imei[2], imei[3], imei[4], imei[5], imei[6], imei[7],
                               imei[8], imei[9], imei[10], imei[11], imei[12], imei[13], imei[14], imei[15]);

        if (is_init)
        {
            return NVRAM_IO_ERRNO_OK;
        }
        else
        {
            if (rec_index == 1)
            {
                result = LGE_FacWriteImei(1, imei, KAL_TRUE);
            }
            else if (ldi->total_records > 1 && rec_index == 2)
            {
                result = LGE_FacWriteImei(0, imei, KAL_TRUE);
            }
            else if (ldi->total_records > 1 && rec_index == 3)
            {
                result = LGE_FacWriteImei(2, imei, KAL_TRUE);
            }
            else
            {
                ASSERT(0);
                return NVRAM_IO_ERRNO_INVALID_RECORD;
            }
        }

        if (result == KAL_FALSE)
        {
            //use kal_trace
            nvram_trace(TRACE_FUNC, EX_IO_RECOVER_IMAGE_BY_LID, ldi->LID, rec_index, __LINE__);
            return NVRAM_ERRNO_FAIL;
        }

        break;
    default:
//        EXT_ASSERT(0,0,0,0);
        ASSERT(0);
        return NVRAM_IO_ERRNO_INVALID_LID;

    }
    return NVRAM_IO_ERRNO_OK;
}
#endif /* __CUSTOMER_TC01_DISK__ */

#ifdef __NVRAM_BACKUP_DISK_FAT__
/*****************************************************************************
 * FUNCTION
 *  nvram_backup_disk_init
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
nvram_errno_enum nvram_init_backup_disk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[NVRAM_MAX_PATH_LEN];
    FS_HANDLE hFile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check nvram root folder, if not exist, create it! */
    NVRAM_FS_MAKE_BACKUP_ROOT_PATH(filename);
    hFile = FS_Open((const kal_wchar*)filename, FS_READ_ONLY | FS_OPEN_DIR);

    if (hFile >= FS_NO_ERROR)
    {
        FS_Close(hFile);
    }
    else if (hFile == FS_FILE_NOT_FOUND || hFile == FS_PATH_NOT_FOUND)
    {
        FS_CreateDir((const kal_wchar*)filename);
        return NVRAM_ERRNO_IMAGE_EMPTY;
    }
    else
    {
        //ASSERT(0);
		EXT_ASSERT(0, hFile, NVRAM_LOC_OPEN_BACKUP_DISK_FAIL, 0);
        return NVRAM_ERRNO_IMAGE_BROKEN;
    }
    return NVRAM_ERRNO_SUCCESS;
}




/*****************************************************************************
 * FUNCTION
 *  nvram_recover_image_by_lid
 * DESCRIPTION
 *  to recover the image from backup partition
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_errno_enum
 * RETURN VALUES
 *  return NVRAM_ERRNO_SUCCESS if no error
 *****************************************************************************/
nvram_errno_enum nvram_recover_image_by_lid(nvram_ltable_entry_struct *ldi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 error = 0;
    FS_FileOpenHint Hint = {0};
    NVRAM_FILE_NAME nvramname;
    kal_int32 file_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!NVRAM_IS_LID_VALID(ldi->LID))
    {
        return NVRAM_ERRNO_INVALID;
    }

    nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);

    file_size = nvram_drv_fat_get_record_size(nvramname, &Hint, NVRAM_NVD_BAK);

    if (file_size < FS_NO_ERROR)
    {
        nvram_trace(TRACE_FUNC, EX_IO_RECOVER_IMAGE_BY_LID, ldi->LID, file_size, __LINE__);
        return NVRAM_ERRNO_IMAGE_DATA_NOT_EXIST;
    }
    else if (file_size != (kal_int32)(ldi->size + NVRAM_CHKSUM_SIZE) * ldi->total_records )
    {
        nvram_trace(TRACE_FUNC, EX_IO_RECOVER_IMAGE_BY_LID, ldi->LID, file_size, __LINE__);
        return NVRAM_ERRNO_IMAGE_BROKEN;
    }

    error = nvram_drv_fat_backup(ldi, KAL_FALSE);

    nvram_trace(TRACE_FUNC, EX_IO_RECOVER_IMAGE_BY_LID, ldi->LID, error, __LINE__);

    if (error == FS_NO_ERROR)
    {
        return NVRAM_ERRNO_SUCCESS;
    }
    else
    {
        return NVRAM_ERRNO_IMAGE_BROKEN;
    }
}


#elif defined(__NVRAM_BACKUP_DISK_RAW__)

#if !defined(__NVRAM_SIMULATE_BACKUP_DISK__)    // Target
#include "flash_disk.h"
#else                                           // MoDIS simulate
#define BACKUP_DISK_STATUS_INIT 0
#define BACKUP_DISK_STATUS_EMPTY 1
#define BACKUP_DISK_STATUS_LOCK 2

#define RAW_DISK_ERR_NONE 0
#define RAW_DISK_ERR_WRONG_ADDRESS 1
#define RAW_DISK_ERR_NO_SPACE  2
#define RAW_DISK_ERR_LOCKED 3  //only for backup partition
#define RAW_DISK_ERR_NO_INIT 4  //only for backup partition
#define RAW_DISK_ERR_PROG_FAIL 5
#define RAW_DISK_ERR_ERASE_FAIL 6
#define RAW_DISK_ERR_UNKNOWN 7

#define DATA_MAX_NUMBER 64
static kal_uint16 ID_ARRAY[DATA_MAX_NUMBER];
static kal_uint16 DATA_BUFFER[DATA_MAX_NUMBER][1024];
static kal_uint16 DATA_NUMBER = 0;
static kal_int32 DATA_STATUS = BACKUP_DISK_STATUS_EMPTY;

void initBackupPartition(void)
{
    DATA_NUMBER = 0;
    DATA_STATUS = BACKUP_DISK_STATUS_INIT;
    memset(DATA_BUFFER, 0, sizeof(DATA_BUFFER));
}

kal_int32 readBackupPartition(kal_uint16 ID, kal_uint8* data_ptr, kal_uint32 len)
{
    kal_int32 i;

    if (DATA_STATUS != BACKUP_DISK_STATUS_LOCK)
    {
        ASSERT(0);
        return RAW_DISK_ERR_UNKNOWN;
    }

    for (i = 0 ; i < DATA_MAX_NUMBER ;i++)
    {
        if (ID_ARRAY[i] == ID)
        {
            memcpy(data_ptr, DATA_BUFFER[i], len);
            return len;
        }
    }
    return RAW_DISK_ERR_UNKNOWN;
}

kal_int32 writeBackupPartition(kal_uint16 ID, kal_uint8* data_ptr, kal_uint32 len)
{

    if (DATA_STATUS != BACKUP_DISK_STATUS_INIT)
    {
        ASSERT(0);
        return RAW_DISK_ERR_UNKNOWN;
    }

    if (DATA_NUMBER >= DATA_MAX_NUMBER)
    {
        return RAW_DISK_ERR_NO_SPACE;
    }

    ID_ARRAY[DATA_NUMBER] = ID;
    memcpy(DATA_BUFFER[DATA_NUMBER], data_ptr, len);
    DATA_NUMBER++;
    return RAW_DISK_ERR_NONE;
}

void lockBackupPartition(void)
{
    DATA_STATUS = BACKUP_DISK_STATUS_LOCK;
}

kal_int32 getBackupPartitionStatus(void)
{
    return DATA_STATUS;
}

#endif  /* #if defined(__NVRAM_UNIT_TEST__) && !defined(__MTK_TARGET__) */

/*****************************************************************************
 * FUNCTION
 *  nvram_backup_disk_init
 * DESCRIPTION
 *  to init the backup disk and check the error
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_errno_enum
 * RETURN VALUES
 *  return NVRAM_ERRNO_SUCCESS if no error
 *****************************************************************************/
nvram_errno_enum nvram_init_backup_disk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 status = getBackupPartitionStatus();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* under normal mode, we would check the back disk status,
       if the status is BACKUP_DISK_STATUS_INIT, that means power lost during backup procedure */

    kal_wap_trace(MOD_NVRAM, TRACE_FUNC, "nvram_init_backup_disk %d", status);

    if (status == BACKUP_DISK_STATUS_EMPTY)
    {
        return NVRAM_ERRNO_IMAGE_EMPTY;
    }
    else if (status == BACKUP_DISK_STATUS_LOCK)
    {
        return NVRAM_ERRNO_SUCCESS;
    }
    else
    {
        if (NORMAL_BOOT == stack_query_boot_mode())
        {
//            ASSERT(0); // design change: backup to backup partition can be execute in normal mode
        }
        return NVRAM_ERRNO_IMAGE_BROKEN;
    }
}

/*****************************************************************************
 * FUNCTION
 *  nvram_create_image
 * DESCRIPTION
 *  to create the image into backup partition
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_errno_enum
 * RETURN VALUES
 *  return NVRAM_ERRNO_SUCCESS if no error
 *****************************************************************************/
nvram_errno_enum nvram_create_image(nvram_image_type_enum image_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_lid_enum file_idx;
    nvram_ltable_entry_struct *ldi;
    kal_uint8 *buffer;
    kal_int32 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    initBackupPartition();

    /* just clear the data in backup partition */
    if (image_type == NVRAM_IMAGE_TYPE_EMPTY)
    {
        lockBackupPartition();
        return NVRAM_ERRNO_SUCCESS;
    }

    buffer = (kal_uint8*) get_ctrl_buffer(MAX_NVRAM_RECORD_SIZE);

    ldi = &logical_data_item_table[0];
    do
    {
        kal_bool match = KAL_FALSE;


        if ((image_type & NVRAM_IMAGE_TYPE_CALIBRAT) && NVRAM_IS_CATEGORY_CALIBRAT(ldi->category))
        {
            match = KAL_TRUE;
        }

        if ((image_type & NVRAM_IMAGE_TYPE_IMEI) && ldi->LID == NVRAM_EF_IMEI_IMEISV_LID)
        {
            match = KAL_TRUE;
        }

        if (match)
        {
            kal_uint16 chksum = 0;

            if (ldi->size > MAX_NVRAM_RECORD_SIZE - NVRAM_CHKSUM_SIZE - NVRAM_FILE_LEN)
            {
                ASSERT(0);
                continue;
            }

            nvram_read_data_item(ldi, 1, ldi->total_records, buffer, MAX_NVRAM_RECORD_SIZE);

            chksum = nvram_util_caculate_checksum(buffer, ldi->total_records * ldi->size);

            buffer[ldi->total_records * ldi->size] = (kal_uint8)(chksum & 0xFF);
            buffer[ldi->total_records * ldi->size + 1] = (kal_uint8)((chksum & 0xFF00) >> 8);
            sprintf((char*)(buffer + (ldi->total_records * ldi->size + NVRAM_CHKSUM_SIZE)), "%s%s", ldi->fileprefix, ldi->fileverno);

            error = writeBackupPartition(ldi->LID, buffer, ldi->total_records * ldi->size + NVRAM_CHKSUM_SIZE + NVRAM_FILE_LEN);

            kal_wap_trace(MOD_NVRAM, TRACE_FUNC, "nvram_create_image %d %d", image_type, error);

            if (error != RAW_DISK_ERR_NONE)
            {
                ASSERT(0);
                return NVRAM_ERRNO_IMAGE_BROKEN;
            }
        }
    }while(nvram_util_next_data_item(&ldi));

    free_ctrl_buffer(buffer);

    lockBackupPartition();
    return NVRAM_ERRNO_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_recover_image
 * DESCRIPTION
 *  to recover the image from backup partition
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_errno_enum
 * RETURN VALUES
 *  return NVRAM_ERRNO_SUCCESS if no error
 *****************************************************************************/
nvram_errno_enum nvram_recover_image(nvram_image_type_enum image_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    nvram_lid_enum file_idx;
    nvram_ltable_entry_struct *ldi;
    kal_uint8 *buffer;
    kal_int32 error = 0;
    kal_int32 status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* just clear the data in backup partition */
    if (image_type == NVRAM_IMAGE_TYPE_EMPTY)
    {
        return NVRAM_ERRNO_INVALID;
    }

    status = getBackupPartitionStatus();

    if (status != BACKUP_DISK_STATUS_LOCK)
    {
        if (status == BACKUP_DISK_STATUS_EMPTY)
        {
            return NVRAM_ERRNO_IMAGE_EMPTY;
        }
        else if (status == BACKUP_DISK_STATUS_INIT)
        {
            return NVRAM_ERRNO_IMAGE_BROKEN;
        }

        return NVRAM_ERRNO_INVALID;
    }

    buffer = (kal_uint8*) get_ctrl_buffer(MAX_NVRAM_RECORD_SIZE);

    ldi = &logical_data_item_table[0];
    do
    {
        kal_bool match = KAL_FALSE;


        if ((image_type & NVRAM_IMAGE_TYPE_CALIBRAT) && NVRAM_IS_CATEGORY_CALIBRAT(ldi->category))
        {
            match = KAL_TRUE;
        }

        if ((image_type & NVRAM_IMAGE_TYPE_IMEI) && ldi->LID == NVRAM_EF_IMEI_IMEISV_LID)
        {
            match = KAL_TRUE;
        }

        if (match)
        {
            kal_uint16 chksum1, chksum2 = 0;
            kal_char filename[NVRAM_FILE_LEN];

            if (ldi->size > MAX_NVRAM_RECORD_SIZE - NVRAM_CHKSUM_SIZE - NVRAM_FILE_LEN)
            {
                ASSERT(0);
                continue;
            }

            error = readBackupPartition(ldi->LID, buffer, ldi->total_records * ldi->size + NVRAM_CHKSUM_SIZE + NVRAM_FILE_LEN);

            kal_wap_trace(MOD_NVRAM, TRACE_FUNC, "nvram_recover_image %d %d %d", ldi->LID, image_type, error);

            if (error != (ldi->total_records * ldi->size + NVRAM_CHKSUM_SIZE + NVRAM_FILE_LEN))
            {
                /* cannot found the data in back partition, just skip it */
                continue;
            }

            chksum1 = nvram_util_caculate_checksum(buffer, ldi->total_records * ldi->size);

            chksum2 = (kal_int32)buffer[ldi->total_records * ldi->size] | ((kal_int32)buffer[ldi->total_records * ldi->size + 1] << 8);

            if (chksum1 != chksum2)
            {
                ASSERT(0);
                /* the data in back partition is corruptted, just skip it */
                continue;
            }

            sprintf(filename, "%s%s", ldi->fileprefix, ldi->fileverno);

            if (strcmp(filename, (char*)(buffer + (ldi->total_records * ldi->size + NVRAM_CHKSUM_SIZE)))!= 0)
            {
                /* the verno number is changed */
                continue;
            }

            for (i = 0; i < ldi->total_records; i++)
            {
                nvram_write_data_item(ldi, (kal_uint16)(i + 1), buffer + i * (ldi->size), KAL_FALSE);
            }
        }
    }while(nvram_util_next_data_item(&ldi));

    free_ctrl_buffer(buffer);

    return NVRAM_ERRNO_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_verify_image
 * DESCRIPTION
 *  to verfiy the image from backup partition
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_errno_enum
 * RETURN VALUES
 *  return NVRAM_ERRNO_SUCCESS if no error
 *****************************************************************************/
nvram_errno_enum nvram_verify_image(nvram_image_type_enum image_type, kal_bool fast_verify)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_lid_enum file_idx;
    nvram_ltable_entry_struct *ldi;
    kal_uint8 *buffer1, *buffer2;
    kal_int32 error = NVRAM_ERRNO_SUCCESS;
    kal_int32 status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    status = getBackupPartitionStatus();

    if (status != BACKUP_DISK_STATUS_LOCK)
    {
        if (status == BACKUP_DISK_STATUS_EMPTY)
        {
            return NVRAM_ERRNO_IMAGE_EMPTY;
        }
        else if (status == BACKUP_DISK_STATUS_INIT)
        {
            return NVRAM_ERRNO_IMAGE_BROKEN;
        }
        return NVRAM_ERRNO_INVALID;
    }

    if (fast_verify)
    {
        return NVRAM_ERRNO_SUCCESS;
    }

    buffer1 = (kal_uint8*) get_ctrl_buffer(MAX_NVRAM_RECORD_SIZE);
    buffer2 = (kal_uint8*) get_ctrl_buffer(MAX_NVRAM_RECORD_SIZE);

    ldi = &logical_data_item_table[0];
    do
    {
        kal_bool match = KAL_FALSE;


        if ((image_type & NVRAM_IMAGE_TYPE_CALIBRAT) && NVRAM_IS_CATEGORY_CALIBRAT(ldi->category))
        {
            match = KAL_TRUE;
        }

        if ((image_type & NVRAM_IMAGE_TYPE_IMEI) && ldi->LID == NVRAM_EF_IMEI_IMEISV_LID)
        {
            match = KAL_TRUE;
        }

        if (match)
        {
            kal_uint16 chksum1, chksum2 = 0;
            kal_char filename[NVRAM_FILE_LEN];

            if (ldi->size > MAX_NVRAM_RECORD_SIZE - NVRAM_CHKSUM_SIZE - NVRAM_FILE_LEN)
            {
                ASSERT(0);
                continue;
            }

            error = readBackupPartition(ldi->LID, buffer1, ldi->total_records * ldi->size + NVRAM_CHKSUM_SIZE + NVRAM_FILE_LEN);

            kal_wap_trace(MOD_NVRAM, TRACE_FUNC, "nvram_verify_image %d %d %d %d", ldi->LID, image_type, fast_verify, error);

            if (error != (ldi->total_records * ldi->size + NVRAM_CHKSUM_SIZE + NVRAM_FILE_LEN))
            {
                error = NVRAM_ERRNO_IMAGE_DATA_NOT_EXIST;
                break;
            }

            chksum1 = nvram_util_caculate_checksum(buffer1, ldi->total_records * ldi->size);

            chksum2 = (kal_int32)buffer1[ldi->total_records * ldi->size] | ((kal_int32)buffer1[ldi->total_records * ldi->size + 1] << 8);

            if (chksum1 != chksum2)
            {
                error = NVRAM_ERRNO_IMAGE_BROKEN;
                break;
            }

            sprintf(filename, "%s%s", ldi->fileprefix, ldi->fileverno);

            if (strcmp(filename, (char*)(buffer1 + (ldi->total_records * ldi->size + NVRAM_CHKSUM_SIZE)))!= 0)
            {
                /* the verno number is changed */
                error = NVRAM_ERRNO_IMAGE_DATA_NOT_SYNC;
                break;
            }

            nvram_read_data_item(ldi, 1, ldi->total_records, buffer2, MAX_NVRAM_RECORD_SIZE);

            if (memcmp(buffer1, buffer2, ldi->total_records * ldi->size) != 0)
            {
                error = NVRAM_ERRNO_IMAGE_DATA_NOT_SYNC;
                break;
            }

            error = NVRAM_ERRNO_SUCCESS;
        }
    }while(nvram_util_next_data_item(&ldi));

    free_ctrl_buffer(buffer1);
    free_ctrl_buffer(buffer2);

    return error;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_recover_image
 * DESCRIPTION
 *  to recover the image from backup partition
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_errno_enum
 * RETURN VALUES
 *  return NVRAM_ERRNO_SUCCESS if no error
 *****************************************************************************/
nvram_errno_enum nvram_recover_image_by_lid(nvram_ltable_entry_struct *ldi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_uint8 *buffer;
    kal_int32 error = 0;
    kal_int32 status;
    kal_uint16 chksum1, chksum2 = 0;
    kal_char filename[NVRAM_FILE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!NVRAM_IS_LID_VALID(ldi->LID))
    {
        return NVRAM_ERRNO_INVALID;
    }

    status = getBackupPartitionStatus();

    if (status != BACKUP_DISK_STATUS_LOCK)
    {
        nvram_trace(TRACE_FUNC, EX_IO_RECOVER_IMAGE_BY_LID, ldi->LID, status, __LINE__);

        if (status == BACKUP_DISK_STATUS_EMPTY)
        {
            return NVRAM_ERRNO_IMAGE_EMPTY;
        }
        else if (status == BACKUP_DISK_STATUS_INIT)
        {
            return NVRAM_ERRNO_IMAGE_BROKEN;
        }

        return NVRAM_ERRNO_INVALID;
    }

    buffer = (kal_uint8*) get_ctrl_buffer(MAX_NVRAM_RECORD_SIZE);

    error = readBackupPartition(ldi->LID, buffer, ldi->total_records * ldi->size + NVRAM_CHKSUM_SIZE + NVRAM_FILE_LEN);

    nvram_trace(TRACE_FUNC, EX_IO_RECOVER_IMAGE_BY_LID, ldi->LID, error, __LINE__);

    if (error != (ldi->total_records * ldi->size + NVRAM_CHKSUM_SIZE + NVRAM_FILE_LEN))
    {
        free_ctrl_buffer(buffer);
        return NVRAM_ERRNO_INVALID;
    }

    chksum1 = nvram_util_caculate_checksum(buffer, ldi->total_records * ldi->size);

    chksum2 = (kal_int32)buffer[ldi->total_records * ldi->size] | ((kal_int32)buffer[ldi->total_records * ldi->size + 1] << 8);

    if (chksum1 != chksum2)
    {
        ASSERT(0);
    }

    sprintf(filename, "%s%s", ldi->fileprefix, ldi->fileverno);

    if (strcmp(filename, (char*)(buffer + (ldi->total_records * ldi->size + NVRAM_CHKSUM_SIZE)))!= 0)
    {
        free_ctrl_buffer(buffer);
        /* the verno number is changed */
        return NVRAM_ERRNO_INVALID;
    }

    for (i = 0; i < ldi->total_records; i++)
    {
        nvram_write_data_item(ldi, (kal_uint16)(i + 1), buffer + i * (ldi->size), KAL_FALSE);
    }

    free_ctrl_buffer(buffer);

    return NVRAM_ERRNO_SUCCESS;
}

#endif /* __SYSDRV_BACKUP_DISK_FAT__ */


#ifdef __NVRAM_SECURE_DATA_STORAGE__
#include "sds_type.h"
#include "SST_secure.h"
#include "nvram_lid_statistics.h"

extern kal_int32 SDS_PackNvramFilesToRecord(kal_uint32 index, const kal_uint16 **pFolderList, const kal_uint16 **pFileList, kal_int32 fileCount);
extern kal_int32 SDS_RestoreNvramFilesFromRecord(kal_uint32 index);
extern kal_int32 SDS_ReadNvramFileInRecord(kal_uint32 index, const kal_uint16 *pFilename, kal_uint8* pBuf, kal_uint32 bufLen);

static kal_int32 nvram_sds_last_err;
static kal_uint32 nvram_sds_last_line;

/*****************************************************************************
 * FUNCTION
 *  nvram_drv_sds_throw_exception
 * DESCRIPTION
 *  record the error code and prompt message
 * PARAMETERS
 *  checksum        [?]
 *  buf             [?]
 *  size            [IN]
 * RETURNS
 *  checksum(?)
 *****************************************************************************/
void nvram_sds_throw_exception(kal_int32 err, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_sds_last_err = err;
    nvram_sds_last_line = line;

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_SDS_THROW_EXCEPTION, err, line);
}

/*****************************************************************************
 * FUNCTION
 *  nvram_sds_get_last_err
 * DESCRIPTION
 *  record the error code and prompt message
 * PARAMETERS
 *  checksum        [?]
 *  buf             [?]
 *  size            [IN]
 * RETURNS
 *  checksum(?)
 *****************************************************************************/
kal_int32 nvram_sds_get_last_err(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return nvram_sds_last_err;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_make_lid_filename
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
kal_uint32 nvram_sds_fileprefix_2_int32(kal_char *fileprefix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result |= (kal_uint32) fileprefix[0] << 24;
    result |= (kal_uint32) fileprefix[1] << 16;
    result |= (kal_uint32) fileprefix[2] <<  8;
    result |= (kal_uint32) fileprefix[3];

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_make_lid_filename
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void nvram_sds_int32_2_fileprefix(kal_int32 index, kal_char *fileprefix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    fileprefix[0] = (index >> 24) & 0xFF;
    fileprefix[1] = (index >> 16) & 0xFF;
    fileprefix[2] = (index >> 8) & 0xFF;
    fileprefix[3] = index & 0xFF;
    fileprefix[4] = 0;

    return ;
}


#ifdef __NVRAM_SIMULATE_SECURE_DATA_STORAGE__

#define SECURE_STORGE_PATH "Z:\\SECURE"

kal_int32 SDS_AddRecord(SDS_PARTITION_TYPE partition, kal_uint32 index, const kal_uint8 *pData, kal_uint32 length, SDS_DP_TYPE dpType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hFile;
    kal_wchar filename[32];
    kal_char fileprefix[5];
    kal_int32 result = SDS_SUCCESS;
    kal_int32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

//    kal_wsprintf(filename, "%s\\%08X", SECURE_STORGE_PATH, index);

    nvram_sds_int32_2_fileprefix(index, fileprefix);
    kal_wsprintf(filename, "%s\\%s", SECURE_STORGE_PATH, fileprefix);


    if (FS_GetAttributes(filename) >= FS_NO_ERROR)
    {
        return SDS_RECORD_EXISTING;
    }

    if (FS_NO_ERROR > (hFile = FS_Open(filename, FS_READ_WRITE | FS_OPEN_NO_DIR | FS_CREATE_ALWAYS)))
    {
        return SDS_FAIL;
    }

    if (FS_NO_ERROR > FS_Write(hFile, (void *)pData, length, &len))
    {
        result = SDS_FAIL;
    }

    FS_Close(hFile);

    return result;

}

kal_int32 SDS_UpdateRecord(SDS_PARTITION_TYPE partition, kal_uint32 index, const kal_uint8 *pData, kal_uint32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hFile;
    kal_wchar filename[32];
    kal_int32 result = SDS_SUCCESS;
    kal_int32 len;
    kal_char fileprefix[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

//    kal_wsprintf(filename, "%s\\%08X", SECURE_STORGE_PATH, index);
    nvram_sds_int32_2_fileprefix(index, fileprefix);
    kal_wsprintf(filename, "%s\\%s", SECURE_STORGE_PATH, fileprefix);

    if (FS_GetAttributes(filename) < FS_NO_ERROR)
    {
        return SDS_NO_SPECIFIED_RECORD;
    }

    if (FS_NO_ERROR > (hFile = FS_Open(filename, FS_READ_WRITE | FS_OPEN_NO_DIR | FS_CREATE_ALWAYS)))
    {
        return SDS_FAIL;
    }

    if (FS_NO_ERROR > FS_Write(hFile, (void *)pData, length, &len))
    {
        result = SDS_FAIL;
    }

    FS_Close(hFile);

    return result;

}

kal_int32 SDS_ReadRecord(SDS_PARTITION_TYPE partition, kal_uint32 index, kal_uint8 *pData, kal_uint32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hFile;
    kal_wchar filename[32];
    kal_int32 result = SDS_SUCCESS;
    kal_int32 len;
    kal_char fileprefix[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //kal_wsprintf(filename, "%s\\%08X", SECURE_STORGE_PATH, index);
    nvram_sds_int32_2_fileprefix(index, fileprefix);
    kal_wsprintf(filename, "%s\\%s", SECURE_STORGE_PATH, fileprefix);

    if (FS_GetAttributes(filename) < FS_NO_ERROR)
    {
        return SDS_NO_SPECIFIED_RECORD;
    }

    if (FS_NO_ERROR > (hFile = FS_Open(filename, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED)))
    {
        return SDS_FAIL;
    }

    if (FS_NO_ERROR > FS_Read(hFile, pData, length, &len) || len != length)
    {
        result = SDS_FAIL;
    }
    else
    {
        result = len;
    }

    FS_Close(hFile);

    return result;
}

kal_int32 SDS_DelRecord(SDS_PARTITION_TYPE partition, kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[32];
    kal_int32 result = SDS_SUCCESS;
    kal_char fileprefix[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //kal_wsprintf(filename, "%s\\%08X", SECURE_STORGE_PATH, index);
    nvram_sds_int32_2_fileprefix(index, fileprefix);
    kal_wsprintf(filename, "%s\\%s", SECURE_STORGE_PATH, fileprefix);

    if (FS_GetAttributes(filename) < FS_NO_ERROR)
    {
        return SDS_NO_SPECIFIED_RECORD;
    }

    FS_Delete(filename);

    return result;
}

kal_int32 SDS_FormatPartition(SDS_PARTITION_TYPE partition)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar namepattern[32];
    kal_int32 result = SDS_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wsprintf(namepattern, "%s", SECURE_STORGE_PATH);

    FS_RemoveDir(namepattern);

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    return result;

}

kal_int32 SDS_GetRecordCount(SDS_PARTITION_TYPE partition)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar namepattern[32];
    kal_int32 count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wsprintf(namepattern, "%s", SECURE_STORGE_PATH);

    count = FS_Count((WCHAR *)namepattern, FS_DIR_TYPE |FS_FILE_TYPE|FS_RECURSIVE_TYPE,NULL,0);

    return count;

}

kal_int32 SDS_GetRecordList(SDS_PARTITION_TYPE partition, kal_uint32 *pIndexList, kal_uint32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hFile;
    kal_wchar namepattern[32];
    kal_wchar filename[32];
    kal_int32 result = SDS_SUCCESS;
    FS_DOSDirEntry fileinfo;
    kal_uint32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(namepattern, "%s\\*", SECURE_STORGE_PATH);

    hFile = FS_FindFirst(namepattern, 0, FS_ATTR_DIR, &fileinfo, filename, sizeof(filename));

    if (hFile > 0)
    {
        do
        {
            if (count >=num)
            {
                result = SDS_FULL;
                break;
            }

            pIndexList[count] = 0;
            pIndexList[count] |= (kal_uint32) filename[0] << 24;
            pIndexList[count] |= (kal_uint32) filename[1] << 16;
            pIndexList[count] |= (kal_uint32) filename[2] <<  8;
            pIndexList[count] |= (kal_uint32) filename[3];

            //sscanf(filename, "%x", pIndexList[count]);
            //pIndexList[count] = nvram_sds_fileprefix_2_int32(filename);
        }
        while (FS_FindNext(hFile, &fileinfo, filename, sizeof(filename)) == FS_NO_ERROR);
        FS_FindClose(hFile);
    }
    else
    {
        result = SDS_FAIL;
    }

    return result;
}

kal_int32 SDS_GetRecordLen(SDS_PARTITION_TYPE partition, kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hFile;
    kal_wchar filename[32];
    kal_int32 result = SDS_SUCCESS;
    kal_int32 len;
    kal_char fileprefix[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

//    kal_wsprintf(filename, "%s\\%08X", SECURE_STORGE_PATH, index);
    nvram_sds_int32_2_fileprefix(index, fileprefix);
    kal_wsprintf(filename, "%s\\%s", SECURE_STORGE_PATH, fileprefix);

    if (FS_GetAttributes(filename) < FS_NO_ERROR)
    {
        return SDS_NO_SPECIFIED_RECORD;
    }

    if (FS_NO_ERROR > (hFile = FS_Open(filename, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED)))
    {
        return SDS_FAIL;
    }

    if (FS_NO_ERROR > FS_GetFileSize(hFile, &len))
    {
        return SDS_FAIL;
    }

    FS_Close(hFile);

    return len;

}

/* 1. Copy all files specified by 'pFileList' into one record  in SDS nvram partition
   2. All files should be with full path
   3. Target record in SDS will always be overwritten
*/
kal_int32 SDS_PackNvramFilesToRecord(kal_uint32 index, const kal_uint16 **pFolderList, const kal_uint16 **pFileList, kal_int32 fileCount)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hFile;
    kal_wchar log_file[32];
    kal_wchar src_file[32], dest_file[32];
    kal_int32 result = SDS_SUCCESS;

    kal_int32 i;
    kal_uint32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wsprintf(log_file, "%s\\path.txt", SECURE_STORGE_PATH);

    if ( (hFile = FS_Open(log_file, FS_CREATE_ALWAYS | FS_READ_WRITE)) < FS_NO_ERROR)
    {
        EXT_ASSERT(0, 0, 0, 0);
        return SDS_FAIL;
    }

    for (i = 0 ; i < fileCount ; i++)
    {
        kal_wsprintf(src_file, "%w\\%w", pFolderList[i], pFileList[i]);
        kal_wsprintf(dest_file, "%s\\%w", SECURE_STORGE_PATH, pFileList[i]);

//        FS_SetAttributes(dest_file, 0);
        FS_Delete(dest_file);

        result = FS_Move(src_file, dest_file, FS_MOVE_COPY, NULL, NULL, 0);

        if (result != FS_NO_ERROR)
        {
            result = SDS_FAIL;
            break;
        }
        else
        {

            FS_Write(hFile, (void*) dest_file, 64, &len);
            FS_Write(hFile, (void*) src_file, 64, &len);

            result = SDS_SUCCESS;
        }
    }

    FS_Close(hFile);

    return result;
}

/* 1. Restore all files packed in SDS record to their original position in the FAT
   2. All files will be overwritten
*/
kal_int32 SDS_RestoreNvramFilesFromRecord(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hFile;
    kal_wchar src_file[32], dest_file[32];
    kal_wchar log_file[32];
    kal_int32 result = SDS_SUCCESS;

    kal_uint32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wsprintf(log_file, "%s\\path.txt", SECURE_STORGE_PATH);

    if ((hFile = FS_Open(log_file, FS_READ_ONLY)) < FS_NO_ERROR)
    {
        return SDS_FAIL;
    }

    do
    {
        if ( FS_Read(hFile, src_file, 64, &len) >= FS_NO_ERROR &&
             FS_Read(hFile, dest_file, 64, &len) >= FS_NO_ERROR && len == 64)
        {
//            FS_SetAttributes(dest_file, 0);
            FS_Delete(dest_file);
            FS_Move(src_file, dest_file, FS_MOVE_COPY, NULL, NULL, 0);
        }
        else
        {
            break;
        }
    } while (1);

    FS_Close(hFile);

    return SDS_SUCCESS;
}

/* 1. Read a specific nvram file from packed data in SDS record
   2. Return failure if no such file exists
   3. The filename is with full path and should be exactly the same as that was provided in invoking SDS_PackNvramFilesToRecord (case sensitive)
*/
kal_int32 SDS_ReadNvramFileInRecord(kal_uint32 index, const kal_uint16 *pFilename, kal_uint8* pBuf, kal_uint32 bufLen)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hFile;
    kal_wchar filename[32];
    kal_int32 result = SDS_SUCCESS;

    kal_wchar *tmp;
    kal_uint32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    tmp = kal_wstrrchr(pFilename, '\\');

    kal_wsprintf(filename, "%s\\%w", SECURE_STORGE_PATH, tmp);

    if ( (hFile = FS_Open(filename, FS_READ_ONLY)) >= FS_NO_ERROR)
    {
        if (FS_Read(hFile, pBuf, bufLen, &len) < FS_NO_ERROR || len != bufLen )
        {
            result = SDS_FAIL;
        }
        else
        {
            result = SDS_SUCCESS;
        }
    }
    else
    {
        return SDS_FAIL;
    }

    FS_Close(hFile);

    if (result == SDS_SUCCESS)
    {
        return len;
    }
    else
    {
        return result;
    }
}

kal_int32 SDS_GetNvramFileLengthInRecord(kal_uint32 index, const kal_uint16 *pFilename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hFile;
    kal_wchar filename[32];
    kal_int32 result = SDS_SUCCESS;

    kal_wchar *tmp;
    kal_uint32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    tmp = kal_wstrrchr(pFilename, '\\');

    kal_wsprintf(filename, "%s\\%w", SECURE_STORGE_PATH, tmp);

    if ( (hFile = FS_Open(filename, FS_READ_ONLY)) >= FS_NO_ERROR)
    {
        if (FS_GetFileSize(hFile, &size) < FS_NO_ERROR)
        {
            result = SDS_FAIL;
        }
        else
        {
            result = SDS_SUCCESS;
        }
    }
    else
    {
        return SDS_FAIL;
    }

    FS_Close(hFile);

    if (result == SDS_SUCCESS)
    {
        return size;
    }
    else
    {
        return result;
    }
}


#endif

/* -----------------------------------------------------------------------------------
 * |  prefix  | verno  | Flag    | Data Len | Record number | Data 1 + chksum |  Data2 + chksum
 * -----------------------------------------------------------------------------------
 *   4 Bytes   3 Bytes   3 Bytes    4 Bytes     2 bytes
 */

#define SDS_DATA_HEADER_LEN 16

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
nvram_errno_enum nvram_sds_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (nvram_check_first_bootup_log("SDS") || SDS_GetRecordCount(SDS_PT_NVRAM_PARTITION) <= 0)
    {
        return NVRAM_ERRNO_SDS_EMPTY;
    }

    return NVRAM_ERRNO_SDS_READY;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_sds_init_start
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
nvram_errno_enum nvram_sds_init_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __NVRAM_SIMULATE_SECURE_DATA_STORAGE__
    kal_wchar filename[NVRAM_MAX_PATH_LEN];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_create_first_bootup_log("SDS");
    SDS_FormatPartition(SDS_PT_NVRAM_PARTITION);

#ifdef __NVRAM_SIMULATE_SECURE_DATA_STORAGE__
    kal_wsprintf(filename, "%s\\", SECURE_STORGE_PATH);
    FS_CreateDir(filename);
#endif

    return NVRAM_ERRNO_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_sds_init_end
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
nvram_errno_enum nvram_sds_init_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_delete_first_bootup_log("SDS");

    return NVRAM_ERRNO_SUCCESS;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
        #ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
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
    #ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  nvram_sds_read_data_item
 * DESCRIPTION
 * PARAMETERS
 *  ldi             [IN]
 *  rec_index       [IN]
 *  rec_amount      [IN]
 *  buffer          [IN]
 *  buffer_size     [IN]
 * RETURNS
 *  NVRAM_IO_ERRNO_OK    if read successfully.
 *  NVRAM_IO_ERRNO_CHK   if checksum error, and cannot be reset to default value.
 *  NVRAM_IO_ERRNO_INIT  if checksum error, but successfully reset to default value.
 *****************************************************************************/
nvram_errno_enum nvram_sds_read_data_item
    (nvram_ltable_entry_struct *ldi, kal_uint16 rec_index, kal_uint16 rec_amount, kal_uint8 *buffer, kal_uint32 buffer_size)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    FS_HANDLE hFile = 0;
    kal_wchar *filename = (kal_wchar *)get_ctrl_buffer(NVRAM_MAX_PATH_LEN * sizeof(kal_wchar));
    nvram_folder_enum folder_index;
    NVRAM_FILE_NAME nvramname;
    kal_uint16 chksum1 = 0, chksum2 = 0;
//    kal_uint16 chksum3 = 0;
    kal_uint32 remainLen = 0;
//    kal_uint32 len = 0;
    kal_int32 section_size;
    kal_int32 working_buffer_size = 0;
    kal_uint8 *working_buffer = NULL;
    kal_int32 result = NVRAM_IO_ERRNO_OK;
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    folder_index = nvram_query_folder_index(ldi->category);
    nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);
    nvram_query_file_name(folder_index, nvramname, filename);

#ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
    if (ldi->attr & NVRAM_ATTR_MSP)
    {
        /* 16 byte alignment */
        remainLen = NVRAM_MSP_ALIGNMENT_REMAINDER(ldi->size + NVRAM_CHKSUM_SIZE);
    }
#endif

    section_size = ldi->size + NVRAM_CHKSUM_SIZE + remainLen;
    //working_buffer_size = MAX_NVRAM_RECORD_SIZE;
    working_buffer_size = section_size * ldi->total_records;
    if (working_buffer_size > MAX_NVRAM_RECORD_SIZE)
    {
        working_buffer_size = MAX_NVRAM_RECORD_SIZE;
    }

    working_buffer = (kal_uint8*) get_ctrl_buffer(working_buffer_size);
    
    //read the whole file
    if (SDS_SUCCESS > (result = SDS_ReadNvramFileInRecord(0, filename, working_buffer, working_buffer_size)))
    {
        nvram_sds_throw_exception(result, __LINE__);
        result = NVRAM_IO_ERRNO_SDS_FAIL;
        goto final;
    }
    else if (result != working_buffer_size)
    {
        result = NVRAM_IO_ERRNO_SDS_FAIL;
    }
    else
    {
        result = NVRAM_IO_ERRNO_OK;
    }

#ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
    if (ldi->attr & NVRAM_ATTR_MSP)
    {
        for (i = 0; i < ldi->total_records; i++)
        {
            SST_Secure_Algo(NVRAM_MSP_DECRYPT, (kal_uint32) (working_buffer + section_size * i), section_size, nvram_ptr->secret_key, working_buffer + section_size * i);
        }
    }
#endif

    /* Handle multi-record reading */
    for (i = 0; i < rec_amount; i++)
    {
        chksum1 = chksum2 = 0;

        chksum2  = *(kal_uint8*) (working_buffer + section_size * (i + rec_index - 1) + ldi->size);
        chksum2 |= *(kal_uint8*) (working_buffer + section_size * (i + rec_index - 1) + ldi->size + 1) << 8;

        /* checksum from content */
        chksum1 = nvram_util_caculate_checksum(working_buffer + (section_size * (i + rec_index - 1)), ldi->size);

        if (chksum1 != chksum2)
        {
            result = NVRAM_IO_ERRNO_CONTENT_BROKEN;
            break;
        }
    
        if (ldi->attr & NVRAM_ATTR_CONFIDENTIAL)
        {
            custom_nvram_decrypt(nvram_ptr->secret_key, working_buffer + section_size * (i + rec_index - 1), ldi->size, ldi->size);
        }
        kal_mem_cpy(buffer + ldi->size * i, working_buffer + section_size * (i + rec_index - 1), ldi->size);
    }

final:

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_SDS_READ_DATA_ITEM, ldi->LID, result);

    if (working_buffer)
    {
        free_ctrl_buffer(working_buffer);
    }

    if (filename)
    {
        free_ctrl_buffer(filename);
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_sds_err_handle
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
kal_bool nvram_sds_err_handle(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 folder_index = 0;
    kal_int32 file_size = 0;
    nvram_ltable_entry_struct *ldi = &logical_data_item_table[0];
    kal_bool result = KAL_TRUE;
    FS_FileOpenHint Hint;
    NVRAM_FILE_NAME nvramname;
    kal_uint32 section_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Must clear up Hint beforehand */
    memset(&Hint, 0, sizeof(Hint));

    do
    {
        if (!NVRAM_IS_CATEGORY_BACKUP_SDS(ldi->category))
        {
            continue;
        }

        folder_index = nvram_query_folder_index(ldi->category);

        //NVRAM_ATTR_MULTIPLE would be turned-off if NVRAM_CATEGORY_BACKUP_SDS
        nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);

        file_size = nvram_drv_fat_get_record_size(nvramname, &Hint, folder_index);

        if (ldi->attr & NVRAM_ATTR_MSP)
        {
            section_size = NVRAM_MSP_ALIGNMENT_CEILING(ldi->size + NVRAM_CHKSUM_SIZE);
        }
        else
        {
            section_size = ldi->size + NVRAM_CHKSUM_SIZE;
        }

        if ((file_size <= 0) || (file_size != (kal_int32)(section_size * ldi->total_records)))
        {
            result = nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records);
        }

        if (result != KAL_TRUE)
        {
            return result;
        }
    }while(nvram_util_next_data_item(&ldi));    
    
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  nvram_sds_backup
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
nvram_errno_enum nvram_sds_backup(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *file_list_working_buffer;
    kal_wchar *folder_list_working_buffer;
    kal_int32 result = NVRAM_IO_ERRNO_OK;
    kal_wchar **file_list, **folder_list;
    nvram_ltable_entry_struct *ldi;
    kal_int32 file_idx = 0, i;
    nvram_folder_enum folder_index;
    NVRAM_FILE_NAME nvramname;
    kal_uint32 retry_cnt = 0;
    kal_bool result2 = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
TRY_AGAIN:

    file_list = (kal_wchar **) get_ctrl_buffer(sizeof(kal_wchar *) * NVRAM_SDS_TOTAL);
    folder_list = (kal_wchar **) get_ctrl_buffer(sizeof(kal_wchar *) * NVRAM_SDS_TOTAL);
    file_list_working_buffer = (kal_wchar *) get_ctrl_buffer(sizeof(NVRAM_FILE_NAME) * NVRAM_SDS_TOTAL * 2);
    folder_list_working_buffer = (kal_wchar *) get_ctrl_buffer(NVRAM_MAX_PATH_LEN * NVRAM_FOLDER_TOTAL * 2);

    for (i = 0 ; i < NVRAM_FOLDER_TOTAL ; i++)
    {
        kal_wsprintf(folder_list_working_buffer + NVRAM_MAX_PATH_LEN * i , "%s", nvram_query_work_path(i));
    }

    ldi = &logical_data_item_table[0];
    do
    {

        if (!NVRAM_IS_CATEGORY_BACKUP_SDS(ldi->category))
        {
            continue;
        }

        if (file_idx >= NVRAM_SDS_TOTAL)
        {
            EXT_ASSERT(0, ldi->LID, file_idx , NVRAM_SDS_TOTAL);
            result = NVRAM_IO_ERRNO_SDS_FAIL;
            goto final;
        }

        nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);
        kal_wsprintf(file_list_working_buffer + sizeof(NVRAM_FILE_NAME) * file_idx ,
            "%s", nvramname);
        file_list[file_idx] = file_list_working_buffer + sizeof(NVRAM_FILE_NAME) * file_idx ;

        folder_index = nvram_query_folder_index(ldi->category);
        folder_list[file_idx] = folder_list_working_buffer + NVRAM_MAX_PATH_LEN * folder_index;

        file_idx ++;
    }while(nvram_util_next_data_item(&ldi));

    if ((result = SDS_PackNvramFilesToRecord(0, (const kal_uint16**)folder_list, (const kal_uint16**)file_list, file_idx)) != SDS_SUCCESS)
    {
        if (!retry_cnt)
        {
            free_ctrl_buffer(file_list);
            free_ctrl_buffer(folder_list);
            free_ctrl_buffer(file_list_working_buffer);
            free_ctrl_buffer(folder_list_working_buffer);
            if ((result2 = nvram_sds_err_handle()) == KAL_TRUE)
            {
                result = NVRAM_IO_ERRNO_OK;
                retry_cnt++;
                file_idx = 0;
                goto TRY_AGAIN;
            }
        }
        
        EXT_ASSERT(0, result, result2, retry_cnt);
        result = NVRAM_IO_ERRNO_SDS_FAIL;
        goto final;
    }
    else
    {
        result = NVRAM_IO_ERRNO_OK;
    }

final:

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_SDS_FLUSH_IN, result);

    free_ctrl_buffer(file_list);
    free_ctrl_buffer(folder_list);
    free_ctrl_buffer(file_list_working_buffer);
    free_ctrl_buffer(folder_list_working_buffer);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_sds_restore
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
nvram_errno_enum nvram_sds_restore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_SDS_FLUSH_OUT);

    if ((result = SDS_RestoreNvramFilesFromRecord(0)) != SDS_SUCCESS)
    {
        EXT_ASSERT(0, result, 0, 0);
        return NVRAM_IO_ERRNO_SDS_FAIL;
    }
    else
    {
        return NVRAM_IO_ERRNO_OK;
    }
}

#endif

/*****************************************************************************
 * FUNCTION
 *  nvram_ap_bin_region_backup
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
nvram_errno_enum nvram_ap_bin_region_backup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_trace(TRACE_FUNC, FUNC_NVRAM_AP_BIN_REGION_BACKUP);

    // Open specific device, to notify AP side
    result = FS_Open(L"\\BACKUP", FS_READ_WRITE);

    if (result==FS_NO_ERROR)
    {
        return NVRAM_IO_ERRNO_OK;
    }
    else
    {
        return NVRAM_ERRNO_FAIL;
    }
}
