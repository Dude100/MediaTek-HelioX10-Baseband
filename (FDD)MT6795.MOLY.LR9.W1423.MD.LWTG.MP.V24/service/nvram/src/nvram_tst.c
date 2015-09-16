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
 * nvram_msg_handler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   To handle the messages sent to NVRAM
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "nvram_main.h"
#include "nvram_interface.h"
#include "nvram_io.h"

#ifdef __LTE_RAT__
#define nvram_lid_info_structure nvram_ltable_entry_struct
#include "kal_debug.h"
#else
#include "custom_nvram_editor_data_item.h"
#endif

#ifdef __NVRAM_UNIT_TEST__
#define __NVRAM_PERFORMANCE_TEST__
#endif

#ifdef __NVRAM_PERFORMANCE_TEST__
    #ifdef __MTK_TARGET__
    static kal_uint32 starttime, endtime;
    #define PERFORMANCE_START() kal_get_time(&starttime)
    #define PERFORMANCE_STOP() kal_get_time(&endtime)
    #define PERFORMANCE_TIME_PASS   (endtime-starttime)
       #ifndef __LTE_RAT__
    #define PERFORMANCE_SHOW_TIME_PASS(x, y1) do{PERFORMANCE_STOP();kal_wap_trace(MOD_NVRAM, TRACE_FUNC, x, y1);}while(0)
       #else //__LTE_RAT__
          #define PERFORMANCE_SHOW_TIME_PASS kal_printf
       #endif //__LTE_RAT__
    #else
    #include "time.h"
    static clock_t startclock, endclock;
    #define PERFORMANCE_START()   startclock = clock()
    #define PERFORMANCE_STOP() endclock = clock()
    #define PERFORMANCE_TIME_PASS (endclock-startclock)
    #define PERFORMANCE_SHOW_TIME_PASS(x, y1) do{PERFORMANCE_STOP();printf(x, y1);}while(0)
    #endif
#else
    #define PERFORMANCE_PRINT1(x, y1)
    #define PERFORMANCE_START()
    #define PERFORMANCE_END()
    #define PERFORMANCE_SHOW_TIME_PASS(x, y1)
#endif

#ifdef __NVRAM_UNIT_TEST__
#define A(x) L##x
#define WIDE_STR(x) A(x)

#ifndef __MTK_TARGET__
#define UNIT_TEST_THROW_EXCEPTION(number)   \
    printf("test case#%d fail\n", number);
#else
#define UNIT_TEST_THROW_EXCEPTION(number)   \
    kal_wap_trace(MOD_NVRAM, TRACE_FUNC, "test case#%d fail\n", number);
#endif

#define NVUT(__test_block__)         \
{                                               \
    if (!(__test_block__))                      \
    {                                           \
        UNIT_TEST_THROW_EXCEPTION(__LINE__);    \
        unit_test_result = KAL_FALSE;           \
    }                                           \
}

kal_uint8 buffer1[4096 * 5];
kal_uint8 buffer2[4096 * 5];
nvram_errno_enum ut_io_status = NVRAM_IO_ERRNO_OK;
nvram_drv_status_enum ut_drv_status = NVRAM_DRV_OK;


/*****************************************************************************
 * FUNCTION
 *  nvram_read_default_value
 * DESCRIPTION
 *  This function is used to read the default value of data item for external module.
 *  Please must check with NVRAM owner before you use this API.
 * PARAMETERS
 *  LID:            [IN]    NVRAM LID
 *  rec_index:      [IN]    record index, start from 1, but if the value is 0,
 *                          this function will return all default value of each record
 *  buffer:         [OUT]   buffer pointer, cannot be NULL
 *  buffer_size:    [IN]    buffer size
 * RETURNS
 *  nvram_errno_enum
 * RETURN VALUES
 *  NVRAM_ERRNO_SUCCESS:            no error
 *  NVRAM_IO_ERRNO_INVALID_LID:     invalid LID
 *  NVRAM_IO_ERRNO_INVALID_SIZE:    buffer size is too small
 *****************************************************************************/
kal_int32 nvram_read_default_value(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint8 *buffer, kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    nvram_ltable_entry_struct *ldi;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!NVRAM_IS_LID_VALID(LID))
    {
        return NVRAM_IO_ERRNO_INVALID_LID;
    }

    nvram_util_get_data_item(&ldi, LID);

    if (rec_index > ldi->total_records)
    {
        return NVRAM_IO_ERRNO_INVALID_RECORD;
    }

    if (rec_index == 0)
    {
        if (buffer_size < ldi->size * ldi->total_records)
        {
            return NVRAM_IO_ERRNO_INVALID_SIZE;
        }
    }
    else
    {
        if (buffer_size < ldi->size)
        {
            return NVRAM_IO_ERRNO_INVALID_SIZE;
        }
    }

    if (rec_index == 0)
    {
        for(i = 0; i < ldi->total_records; i++)
        {
            nvram_get_default_value_to_write(ldi, i + 1, buffer + i * ldi->size, ldi->size);
        }
    }
    else
    {
        nvram_get_default_value_to_write(ldi, rec_index, buffer, ldi->size);
    }


    return NVRAM_ERRNO_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_compare_to_default_value
 * DESCRIPTION
 *  This function is used to compare the value in nvram file to default value
 * PARAMETERS
 *  LID:       [IN]    NVRAM LID
 *  info:      [OUT]   output the information of an nvram item
 * RETURNS
 *  nvram_errno_enum
 * RETURN VALUES
 *  NVRAM_ERRNO_SUCCESS:            no error
 *  NVRAM_IO_ERRNO_INVALID_LID:     lid is invalid
 *****************************************************************************/
kal_int32 nvram_get_lid_info(nvram_lid_enum LID, nvram_lid_info_structure *info)
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
        return NVRAM_IO_ERRNO_INVALID_LID;
    }

    nvram_util_get_data_item(&ldi, LID);

    memset(info, 0, sizeof(nvram_lid_info_structure));

    info->LID = LID;
    info->size = ldi->size;
    info->total_records = ldi->total_records;
    info->attr = ldi->attr;
    info->category = ldi->category;
    strncpy(info->fileprefix, ldi->fileprefix, FILE_PREFIX_LEN);
    strncpy(info->fileverno, ldi->fileverno, FILE_VERNO_LEN);
    strncpy(info->description, ldi->description, NVRAM_MAX_DESC_LEN);

    return NVRAM_ERRNO_SUCCESS;
}

kal_int32 nvram_unit_test_get_drv_status(kal_int32 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ut_drv_status == NVRAM_DRV_OK)
    {
        return status;
    }
    else if (ut_drv_status == NVRAM_DRV_CHECKSUM_ERROR)
    {
        ut_drv_status = NVRAM_DRV_OK;
        return NVRAM_DRV_CHECKSUM_ERROR;
    }

    return ut_drv_status;
}

kal_int32 nvram_unit_test_get_io_status(kal_int32 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ut_io_status == NVRAM_IO_ERRNO_OK)
    {
        return status;
    }
    return ut_io_status;
}

static kal_bool nvram_unit_test_hidden_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unit_test_result  = KAL_TRUE;
    nvram_ltable_entry_struct *ldi = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_util_get_data_item(&ldi, NVRAM_EF_NVRAM_UNIT_TEST_LID);

    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_DATAITEM_PATH),          KAL_FALSE) == KAL_FALSE);
#ifdef __NVRAM_MULTI_FOLDERS__
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_CALIBRAT_DATAITEM_PATH), KAL_FALSE) == KAL_FALSE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_COREITEM_PATH),          KAL_FALSE) == KAL_FALSE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_IMEI_DATAITEM_PATH),     KAL_FALSE) == KAL_TRUE);
#endif

    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_DATAITEM_PATH),          KAL_TRUE) == KAL_FALSE);
#ifdef __NVRAM_MULTI_FOLDERS__
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_CALIBRAT_DATAITEM_PATH), KAL_TRUE) == KAL_FALSE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_COREITEM_PATH),          KAL_TRUE) == KAL_FALSE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_IMEI_DATAITEM_PATH),     KAL_TRUE) == KAL_FALSE);
#endif

#ifdef __NVRAM_MULTI_FOLDERS__
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_COREITEM_PATH)L"\\MT00_000", KAL_FALSE) == KAL_FALSE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_COREITEM_PATH)L"\\MT00_000", KAL_TRUE)  == KAL_FALSE);

    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_IMEI_DATAITEM_PATH)L"\\MP0B_004", KAL_FALSE) == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_IMEI_DATAITEM_PATH)L"\\MP0B_004", KAL_TRUE)  == KAL_FALSE)

    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_IMEI_DATAITEM_PATH)L"\\ST33A002", KAL_FALSE) == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_IMEI_DATAITEM_PATH)L"\\ST33B002", KAL_FALSE) == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_IMEI_DATAITEM_PATH)L"\\ST33A002", KAL_TRUE) == KAL_FALSE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_IMEI_DATAITEM_PATH)L"\\ST33B002", KAL_TRUE) == KAL_FALSE);
#else
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_DATAITEM_PATH)L"\\MT00_000", KAL_FALSE) == KAL_FALSE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_DATAITEM_PATH)L"\\MT00_000", KAL_TRUE)  == KAL_FALSE);

    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_DATAITEM_PATH)L"\\MP0B_004", KAL_FALSE) == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_DATAITEM_PATH)L"\\MP0B_004", KAL_TRUE)  == KAL_FALSE)

    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_DATAITEM_PATH)L"\\ST33A002", KAL_FALSE) == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_DATAITEM_PATH)L"\\ST33B002", KAL_FALSE) == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_DATAITEM_PATH)L"\\ST33A002", KAL_TRUE) == KAL_FALSE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_DATAITEM_PATH)L"\\ST33B002", KAL_TRUE) == KAL_FALSE);
#endif

#ifdef __NVRAM_CUSTOM_SENSITIVE__
    ldi->category = NVRAM_CATEGORY_CUSTOM_SENSITIVE;
    #ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
    ldi->attr |= NVRAM_ATTR_MSP;
    #endif
    ldi->attr |= NVRAM_ATTR_CONFIDENTIAL;
    ldi->attr |= NVRAM_ATTR_MULTIPLE;

    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_CUST_DATAITEM_PATH),             KAL_FALSE) == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_CUST_DATAITEM_PATH),             KAL_TRUE)  == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_CUST_DATAITEM_PATH)L"\\NV00A000", KAL_FALSE) == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_CUST_DATAITEM_PATH)L"\\NV00B000", KAL_FALSE) == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_CUST_DATAITEM_PATH)L"\\NV00A000", KAL_TRUE)  == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_CUST_DATAITEM_PATH)L"\\NV00B000", KAL_TRUE)  == KAL_TRUE);

    ldi->category = NVRAM_CATEGORY_USER;
    ldi->attr = NVRAM_ATTR_AVERAGE;

#endif

    nvram_ptr->lock = KAL_TRUE;

    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_DATAITEM_PATH),          KAL_FALSE) == KAL_TRUE);
#ifdef __NVRAM_MULTI_FOLDERS__
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_CALIBRAT_DATAITEM_PATH), KAL_FALSE) == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_COREITEM_PATH),          KAL_FALSE) == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_IMEI_DATAITEM_PATH),     KAL_FALSE) == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_COREITEM_PATH)L"\\MT00_000", KAL_FALSE) == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_IMEI_DATAITEM_PATH)L"\\MP0A_001", KAL_FALSE) == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_IMEI_DATAITEM_PATH)L"\\ST1DA002", KAL_FALSE) == KAL_TRUE);
#else
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_DATAITEM_PATH)L"\\MT00_000", KAL_FALSE) == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_DATAITEM_PATH)L"\\MP0A_001", KAL_FALSE) == KAL_TRUE);
    NVUT(nvram_check_hidden_file(WIDE_STR(NVRAM_FS_DATAITEM_PATH)L"\\ST1DA002", KAL_FALSE) == KAL_TRUE);
#endif

    nvram_ptr->lock = KAL_FALSE;

    return unit_test_result;
}

static kal_bool nvram_unit_test_basic_1(kal_uint32 size, kal_uint16 total_records)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unit_test_result  = KAL_TRUE;
    nvram_ltable_entry_struct *ldi = NULL;
    kal_int32 i, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_util_get_data_item(&ldi, NVRAM_EF_NVRAM_UNIT_TEST_LID);

    ldi->size = size;
    ldi->total_records = total_records;
    ldi->category = NVRAM_CATEGORY_USER;

    memset(buffer1, 0, ldi->total_records * ldi->size);
    ldi->default_value = NVRAM_EF_ZERO_DEFAULT;
    /* Reset: basic */
    ldi->attr = NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }

    memset(buffer1, 0xFF, ldi->total_records * ldi->size);
    ldi->default_value = NVRAM_EF_FF_DEFAULT;
    /* Reset: basic */
    ldi->attr = NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }


    for(i = 0 ;i < ldi->total_records; i++)
    {
        for (j = 0 ;j < ldi->size; j+=2)
        {
            buffer1[ldi->size * i + j] = (ldi->size * i + j) & 0xFF;
            buffer1[ldi->size * i + j + 1] = ((ldi->size * i + j) >> 8) & 0xFF;
        }
    }
    ldi->default_value = buffer1;

    /* Reset: basic */
    ldi->attr = NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }

    /* Reset: multi_default */
    ldi->attr = NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1 + i * ldi->size, buffer2 + i * ldi->size, ldi->size)==0);
    }

    /* Reset: mutiple backup */
    ldi->attr = NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTIPLE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }

    /* Reset: multi default + mutiple backup */
    ldi->attr = NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTIPLE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1 + i * ldi->size, buffer2 + i * ldi->size, ldi->size)==0);
    }

    /* Reset: confidential */
    ldi->attr = NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }

    /* Reset: confidential + multi_default*/
    ldi->attr = NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1 + i * ldi->size, buffer2 + i * ldi->size, ldi->size)==0);
    }

#ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
    ldi->attr = NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL | NVRAM_ATTR_MSP;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }

    ldi->attr = NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL | NVRAM_ATTR_MSP;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1 + i * ldi->size, buffer2 + i * ldi->size, ldi->size)==0);
    }
#endif

    /* Reset: multi_default */
    ldi->attr = NVRAM_ATTR_MULTI_DEFAULT;
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
        NVUT(nvram_read_data_item(ldi,  i + 1, 1, buffer2 + i * ldi->size, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
        NVUT(kal_mem_cmp(buffer1 + i * ldi->size, buffer2 + i * ldi->size, ldi->size)==0);
    }

    /* Reset: multi_default */
    ldi->attr = NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_MULTIPLE;
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
        NVUT(nvram_read_data_item(ldi,  i + 1, 1, buffer2 + i * ldi->size, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
        NVUT(kal_mem_cmp(buffer1 + i * ldi->size, buffer2 + i * ldi->size, ldi->size)==0);
    }

    ldi->size = NVRAM_EF_NVRAM_UNIT_TEST_SIZE;
    ldi->total_records = NVRAM_EF_NVRAM_UNIT_TEST_TOTAL;
    ldi->default_value = NVRAM_EF_ZERO_DEFAULT;
    ldi->attr = NVRAM_ATTR_AVERAGE;
    ldi->category = NVRAM_CATEGORY_USER;

    return unit_test_result;
}

static kal_bool nvram_unit_test_basic_2(kal_uint32 size, kal_uint16 total_records)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unit_test_result  = KAL_TRUE;
    nvram_ltable_entry_struct *ldi = NULL;
    kal_int32 i, j = 0;
    kal_uint16 chksum1, chksum2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_util_get_data_item(&ldi, NVRAM_EF_NVRAM_UNIT_TEST_LID);

    ldi->size = size;
    ldi->total_records = total_records;
    ldi->category = NVRAM_CATEGORY_USER;

    memset(buffer1, 0, ldi->total_records * ldi->size);
    ldi->default_value = NVRAM_EF_ZERO_DEFAULT;
    /* Reset: basic */
    ldi->attr = NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item_chksum(ldi,  1, ldi->total_records, (kal_uint16*)buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    chksum1 = nvram_util_caculate_checksum(buffer1, ldi->size);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }

    memset(buffer1, 0xFF, ldi->total_records * ldi->size);
    ldi->default_value = NVRAM_EF_FF_DEFAULT;
    /* Reset: basic */
    ldi->attr = NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item_chksum(ldi,  1, ldi->total_records, (kal_uint16*)buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    chksum1 = nvram_util_caculate_checksum(buffer1, ldi->size);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }


    for(i = 0 ;i < ldi->total_records; i++)
    {
        for (j = 0 ;j < ldi->size; j+=2)
        {
            buffer1[ldi->size * i + j] = (ldi->size * i + j) & 0xFF;
            buffer1[ldi->size * i + j + 1] = ((ldi->size * i + j) >> 8) & 0xFF;
        }
    }
    ldi->default_value = buffer1;

    /* Reset: basic */
    ldi->attr = NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item_chksum(ldi,  1, ldi->total_records, (kal_uint16*)buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    chksum1 = nvram_util_caculate_checksum(buffer1, ldi->size);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }

    /* Reset: multi_default */
    ldi->attr = NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item_chksum(ldi,  1, ldi->total_records, (kal_uint16*)buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        chksum1 = nvram_util_caculate_checksum(buffer1 + ldi->size * i, ldi->size);
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }

    /* Reset: mutiple backup */
    ldi->attr = NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTIPLE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item_chksum(ldi,  1, ldi->total_records, (kal_uint16*)buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    chksum1 = nvram_util_caculate_checksum(buffer1, ldi->size);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }

    /* Reset: multi default + mutiple backup */
    ldi->attr = NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTIPLE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item_chksum(ldi,  1, ldi->total_records, (kal_uint16*)buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        chksum1 = nvram_util_caculate_checksum(buffer1 + ldi->size * i, ldi->size);
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }

    /* Reset: confidential */
    /* we cannot test confidential here, because checksum value is calculated via ciphertext */
    ldi->attr = NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL;

    /* Reset: confidential + multi_default*/
    /* we cannot test confidential here, because checksum value is calculated via ciphertext */
    ldi->attr = NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL;

#ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
    ldi->attr = NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MSP;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item_chksum(ldi,  1, ldi->total_records, (kal_uint16*)buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    chksum1 = nvram_util_caculate_checksum(buffer1, ldi->size);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }

    ldi->attr = NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MSP;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item_chksum(ldi,  1, ldi->total_records, (kal_uint16*)buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        chksum1 = nvram_util_caculate_checksum(buffer1 + ldi->size * i, ldi->size);
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }
#endif

    ldi->attr = NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item_chksum(ldi,  1, ldi->total_records, (kal_uint16*)buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    chksum1 = nvram_util_caculate_checksum(buffer1, ldi->size);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }

    /* Reset: multi_default */
    ldi->attr = NVRAM_ATTR_MULTI_DEFAULT;
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
        NVUT(nvram_read_data_item_chksum(ldi,  i + 1, 1, (kal_uint16*)(buffer2 + i * NVRAM_CHKSUM_SIZE), sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
        chksum1 = nvram_util_caculate_checksum(buffer1 + ldi->size * i, ldi->size);
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }

    /* Reset: multi_default */
    ldi->attr = NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_MULTIPLE;
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
        NVUT(nvram_read_data_item_chksum(ldi,  i + 1, 1, (kal_uint16*)(buffer2 + i * NVRAM_CHKSUM_SIZE), sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
        chksum1 = nvram_util_caculate_checksum(buffer1 + ldi->size * i, ldi->size);
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }

    ldi->size = NVRAM_EF_NVRAM_UNIT_TEST_SIZE;
    ldi->total_records = NVRAM_EF_NVRAM_UNIT_TEST_TOTAL;
    ldi->default_value = NVRAM_EF_ZERO_DEFAULT;
    ldi->attr = NVRAM_ATTR_AVERAGE;
    ldi->category = NVRAM_CATEGORY_USER;

    return unit_test_result;
}


static kal_bool nvram_unit_test_basic_3(kal_uint32 size, kal_uint16 total_records)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unit_test_result  = KAL_TRUE;
    nvram_ltable_entry_struct *ldi = NULL;
    kal_int32 i, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_util_get_data_item(&ldi, NVRAM_EF_NVRAM_UNIT_TEST_LID);

    ldi->size = size;
    ldi->total_records = total_records;
    ldi->category = NVRAM_CATEGORY_USER;

    memset(buffer1, 0xFF, ldi->total_records * ldi->size);
    ldi->default_value = NVRAM_EF_FF_DEFAULT;
    /* Reset: basic */
    ldi->attr = NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }


    for(i = 0 ;i < ldi->total_records; i++)
    {
        for (j = 0 ;j < ldi->size; j+=2)
        {
            buffer1[ldi->size * i + j] = (ldi->size * i + j) & 0xFF;
            buffer1[ldi->size * i + j + 1] = ((ldi->size * i + j) >> 8) & 0xFF;
        }
    }

    /* write / read */
    ldi->attr = NVRAM_ATTR_MULTIREC_READ;
    for(i = 0 ;i < ldi->total_records; i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
        NVUT(nvram_read_data_item(ldi, i + 1, 1, buffer2 + i * ldi->size, ldi->size) == NVRAM_IO_ERRNO_OK);
        NVUT(kal_mem_cmp(buffer1 + i * ldi->size, buffer2 + i * ldi->size, ldi->size) == 0);
    }

    /* write / read */
    ldi->attr = NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL;
    for(i = 0 ;i < ldi->total_records; i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
        NVUT(nvram_read_data_item(ldi, i + 1, 1, buffer2 + i * ldi->size, ldi->size) == NVRAM_IO_ERRNO_OK);
        NVUT(kal_mem_cmp(buffer1 + i * ldi->size, buffer2 + i * ldi->size, ldi->size) == 0);
    }


#ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
    /* write / read */
    ldi->attr = NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL;
    for(i = 0 ;i < ldi->total_records; i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
        NVUT(nvram_read_data_item(ldi, i + 1, 1, buffer2 + i * ldi->size, ldi->size) == NVRAM_IO_ERRNO_OK);
        NVUT(kal_mem_cmp(buffer1 + i * ldi->size, buffer2 + i * ldi->size, ldi->size) == 0);
    }
#endif

    /* read fail -> read backup*/
    ldi->attr = NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTIREC_READ;
    ldi->default_value = NVRAM_EF_FF_DEFAULT;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);

    for(i = 0 ;i < ldi->total_records; i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
    }

    for(i = 0 ;i < ldi->total_records; i++)
    {
        ut_drv_status = NVRAM_DRV_CHECKSUM_ERROR;
        NVUT(nvram_read_data_item(ldi,  i + 1, 1, buffer2 + i * ldi->size, ldi->size) == NVRAM_IO_ERRNO_OK);
        NVUT(kal_mem_cmp(buffer1 + i * ldi->size, buffer2 + i * ldi->size, ldi->size) == 0);
    }

    ldi->size = NVRAM_EF_NVRAM_UNIT_TEST_SIZE;
    ldi->total_records = NVRAM_EF_NVRAM_UNIT_TEST_TOTAL;
    ldi->default_value = NVRAM_EF_ZERO_DEFAULT;
    ldi->attr = NVRAM_ATTR_AVERAGE;
    ldi->category = NVRAM_CATEGORY_USER;

    return unit_test_result;
}

static kal_bool nvram_unit_test_basic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unit_test_result  = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

start_test:
    NVUT(nvram_unit_test_basic_1(10, 5) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- basic(10,5): %d\n", PERFORMANCE_TIME_PASS);

    NVUT(nvram_unit_test_basic_1(128, 5) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- basic(128,5): %d\n", PERFORMANCE_TIME_PASS);

    NVUT(nvram_unit_test_basic_1(256, 10) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- basic(256,10): %d\n", PERFORMANCE_TIME_PASS);

    NVUT(nvram_unit_test_basic_1(MAX_NVRAM_RECORD_SIZE - NVRAM_CHKSUM_SIZE, 1) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- basic(max,10): %d\n", PERFORMANCE_TIME_PASS);

#ifdef __NVRAM_LARGE_RECORD_SIZE__
    NVUT(nvram_unit_test_basic_1(4096, 5) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- basic(4096,5): %d\n", PERFORMANCE_TIME_PASS);
#endif

    NVUT(nvram_unit_test_basic_2(10, 5) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- read_chksum(10,5): %d\n", PERFORMANCE_TIME_PASS);

    NVUT(nvram_unit_test_basic_2(128, 5) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- read_chksum(128,5): %d\n", PERFORMANCE_TIME_PASS);

    NVUT(nvram_unit_test_basic_2(256, 10) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- read_chksum(256,10): %d\n", PERFORMANCE_TIME_PASS);

    NVUT(nvram_unit_test_basic_2(MAX_NVRAM_RECORD_SIZE - NVRAM_CHKSUM_SIZE, 1) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- read_chksum(max,10): %d\n", PERFORMANCE_TIME_PASS);

#ifdef __NVRAM_LARGE_RECORD_SIZE__
    NVUT(nvram_unit_test_basic_2(4096, 5) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- read_chksum(4096,5): %d\n", PERFORMANCE_TIME_PASS);
#endif

    if (ut_io_status == NVRAM_IO_ERRNO_OK)
    {
        ut_io_status = NVRAM_IO_ERRNO_CHK;
        goto start_test;
    }

    ut_io_status = NVRAM_IO_ERRNO_OK;
    ut_drv_status = NVRAM_DRV_OK;

    NVUT(nvram_unit_test_basic_3(10, 5) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- basic3(10,5): %d\n", PERFORMANCE_TIME_PASS);

    NVUT(nvram_unit_test_basic_3(128, 5) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- basic3(128,5): %d\n", PERFORMANCE_TIME_PASS);

    NVUT(nvram_unit_test_basic_3(256, 10) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- basic3(256,10): %d\n", PERFORMANCE_TIME_PASS);

    NVUT(nvram_unit_test_basic_3(MAX_NVRAM_RECORD_SIZE - NVRAM_CHKSUM_SIZE, 1) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- basic3(max,10): %d\n", PERFORMANCE_TIME_PASS);

    return unit_test_result;
}

#ifdef __NVRAM_BACKUP_DISK_FAT__
static kal_bool nvram_unit_test_backup_disk_fat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unit_test_result  = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return unit_test_result;
}
#endif

#ifdef __NVRAM_BACKUP_DISK_RAW__
static kal_bool nvram_unit_test_backup_disk_raw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unit_test_result  = KAL_TRUE;
    nvram_lid_enum file_idx;
    nvram_ltable_entry_struct *ldi;
    kal_wchar *filename;
    NVRAM_FILE_NAME nvramname;
    kal_uint8* buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    NVUT(nvram_create_image(NVRAM_IMAGE_TYPE_DEFAULT) == NVRAM_ERRNO_SUCCESS);
    NVUT(nvram_verify_image(NVRAM_IMAGE_TYPE_DEFAULT, KAL_TRUE) == NVRAM_ERRNO_SUCCESS);
    NVUT(nvram_verify_image(NVRAM_IMAGE_TYPE_DEFAULT, KAL_FALSE) == NVRAM_ERRNO_SUCCESS);
    NVUT(nvram_recover_image(NVRAM_IMAGE_TYPE_DEFAULT) == NVRAM_ERRNO_SUCCESS);
    NVUT(nvram_verify_image(NVRAM_IMAGE_TYPE_DEFAULT, KAL_TRUE) == NVRAM_ERRNO_SUCCESS);
    NVUT(nvram_verify_image(NVRAM_IMAGE_TYPE_DEFAULT, KAL_FALSE) == NVRAM_ERRNO_SUCCESS);

    ldi = &logical_data_item_table[0];
    do
    {

        if (NVRAM_IS_CATEGORY_CALIBRAT(ldi->category))
        {
            NVUT(nvram_recover_image_by_lid(ldi) == NVRAM_ERRNO_SUCCESS);
        }
    }while(nvram_util_next_data_item(&ldi));

    filename = (kal_wchar *)get_ctrl_buffer(NVRAM_MAX_PATH_LEN * sizeof(kal_wchar));
    buffer = (kal_uint8*) get_ctrl_buffer(MAX_NVRAM_RECORD_SIZE);

    ldi = &logical_data_item_table[0];
    do
    {


        if (NVRAM_IS_CATEGORY_CALIBRAT(ldi->category))
        {
            nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);

            nvram_query_file_name(NVRAM_NVD_CALI, nvramname , filename);

            FS_Delete(filename);

            NVUT(nvram_read_data_item(ldi, 1, ldi->total_records, buffer, MAX_NVRAM_RECORD_SIZE) == NVRAM_IO_ERRNO_OK);
        }
    }while(nvram_util_next_data_item(&ldi));

    NVUT(nvram_verify_image(NVRAM_IMAGE_TYPE_DEFAULT, KAL_FALSE) == NVRAM_ERRNO_SUCCESS);

    ldi = &logical_data_item_table[0];
    do
    {

        if (NVRAM_IS_CATEGORY_CALIBRAT(ldi->category))
        {
            nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);

            nvram_query_file_name(NVRAM_NVD_CALI, nvramname , filename);

            NVUT(nvram_read_data_item(ldi, 1, ldi->total_records, buffer, MAX_NVRAM_RECORD_SIZE) == NVRAM_IO_ERRNO_OK);

            buffer[0] = ~buffer[0];

            nvram_write_data_item(ldi, 1, buffer, KAL_FALSE);

        }
    }while(nvram_util_next_data_item(&ldi));

    NVUT(nvram_verify_image(NVRAM_IMAGE_TYPE_DEFAULT, KAL_FALSE) == NVRAM_ERRNO_IMAGE_DATA_NOT_SYNC);
    ldi = &logical_data_item_table[0];
    do
    {


        if (NVRAM_IS_CATEGORY_CALIBRAT(ldi->category))
        {
            nvram_util_make_lid_filename(ldi, nvramname, KAL_TRUE);

            nvram_query_file_name(NVRAM_NVD_CALI, nvramname , filename);

            NVUT(nvram_read_data_item(ldi, 1, ldi->total_records, buffer, MAX_NVRAM_RECORD_SIZE) == NVRAM_IO_ERRNO_OK);

            buffer[0] = ~buffer[0];

            nvram_write_data_item(ldi, 1, buffer, KAL_FALSE);

        }
    }while(nvram_util_next_data_item(&ldi));

    NVUT(nvram_verify_image(NVRAM_IMAGE_TYPE_DEFAULT, KAL_FALSE) == NVRAM_ERRNO_SUCCESS);

    free_ctrl_buffer(buffer);
    free_ctrl_buffer(filename);

    return unit_test_result;

}
#endif

#ifdef __NVRAM_BACKUP_DISK__
static kal_bool nvram_unit_test_backup_disk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unit_test_result  = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __NVRAM_BACKUP_DISK_FAT__
    NVUT(nvram_unit_test_backup_disk_fat() == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- backup disk(FAT) %d\n", PERFORMANCE_TIME_PASS);
#endif

#ifdef __NVRAM_BACKUP_DISK_RAW__
    NVUT(nvram_unit_test_backup_disk_raw() == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- backup disk(RAW) %d\n", PERFORMANCE_TIME_PASS);
#endif

    return unit_test_result;
}
#endif

static kal_bool nvram_unit_test_compare_to_default_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unit_test_result  = KAL_TRUE;
    nvram_lid_enum file_idx;
    nvram_ltable_entry_struct *ldi;
    int i;
    kal_int8 *buffer1, *buffer2;
    nvram_lid_info_structure info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (! (nvram_ptr->sw_status & NVRAM_SW_EMPTY_FAT) )
    {
        return KAL_TRUE;
    }

    ldi = &logical_data_item_table[0];
    do
    {

        buffer1 = (kal_int8*) get_ctrl_buffer(ldi->size);
        buffer2 = (kal_int8*) get_ctrl_buffer(ldi->size);

        for (i = 0 ;i < ldi->total_records; i++)
        {
            NVUT(nvram_compare_to_default_value(ldi->LID, i + 1) == NVRAM_ERRNO_SUCCESS);

            nvram_read_default_value(ldi->LID, i + 1, buffer1, ldi->size);
            nvram_read_data_item(ldi, i + 1, 1, buffer2, ldi->size);

            NVUT(memcmp(buffer1, buffer2, ldi->size) == 0);

        }

        free_ctrl_buffer(buffer1);
        free_ctrl_buffer(buffer2);


        nvram_get_lid_info(ldi->LID, &info);

        NVUT(info.attr == ldi->attr);
        NVUT(info.category == ldi->category);
        NVUT(strncmp(info.description, ldi->description, NVRAM_MAX_DESC_LEN)==0);

    }while(nvram_util_next_data_item(&ldi));
    return unit_test_result;

}

#ifdef __NVRAM_PSEUDO_MERGE__
static kal_bool nvram_unit_test_pseudo_merge_1(kal_uint32 size, kal_uint16 total_records)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unit_test_result  = KAL_TRUE;
    nvram_ltable_entry_struct *ldi = NULL;
    kal_int32 i, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_util_get_data_item(&ldi, NVRAM_EF_NVRAM_UNIT_TEST_LID);

    ldi->size = size;
    ldi->total_records = total_records;
    ldi->category = NVRAM_CATEGORY_USER;

    memset(buffer1, 0, ldi->total_records * ldi->size);
    ldi->default_value = NVRAM_EF_ZERO_DEFAULT;
    /* Reset: basic */
    ldi->attr = NVRAM_ATTR_PACKAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }

    memset(buffer1, 0xFF, ldi->total_records * ldi->size);
    ldi->default_value = NVRAM_EF_FF_DEFAULT;
    /* Reset: basic */
    ldi->attr = NVRAM_ATTR_PACKAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }

    for(i = 0 ;i < ldi->total_records; i++)
    {
        for (j = 0 ;j < ldi->size; j+=2)
        {
            buffer1[ldi->size * i + j] = (ldi->size * i + j) & 0xFF;
            buffer1[ldi->size * i + j + 1] = ((ldi->size * i + j) >> 8) & 0xFF;
        }
    }
    ldi->default_value = buffer1;

    /* Reset: basic */
    ldi->attr = NVRAM_ATTR_PACKAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }

    /* Reset: multi_default */
    ldi->attr = NVRAM_ATTR_PACKAGE | NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1 + i * ldi->size, buffer2 + i * ldi->size, ldi->size)==0);
    }

    /* Reset: confidential */
    ldi->attr = NVRAM_ATTR_PACKAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }

    /* Reset: confidential + multi_default*/
    ldi->attr = NVRAM_ATTR_PACKAGE | NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1 + i * ldi->size, buffer2 + i * ldi->size, ldi->size)==0);
    }


    ldi->size = NVRAM_EF_NVRAM_UNIT_TEST_SIZE;
    ldi->total_records = NVRAM_EF_NVRAM_UNIT_TEST_TOTAL;
    ldi->default_value = NVRAM_EF_ZERO_DEFAULT;
    ldi->attr = NVRAM_ATTR_AVERAGE;
    ldi->category = NVRAM_CATEGORY_USER;

    return unit_test_result;
}

static kal_bool nvram_unit_test_pseudo_merge_2(kal_uint32 size, kal_uint16 total_records)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unit_test_result  = KAL_TRUE;
    nvram_ltable_entry_struct *ldi = NULL;
    kal_int32 i, j = 0;
    kal_uint16 chksum1, chksum2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_util_get_data_item(&ldi, NVRAM_EF_NVRAM_UNIT_TEST_LID);

    ldi->size = size;
    ldi->total_records = total_records;
    ldi->category = NVRAM_CATEGORY_USER;

    memset(buffer1, 0, ldi->total_records * ldi->size);
    ldi->default_value = NVRAM_EF_ZERO_DEFAULT;
    /* Reset: basic */
    ldi->attr = NVRAM_ATTR_PACKAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item_chksum(ldi,  1, ldi->total_records, (kal_uint16 *)buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    chksum1 = nvram_util_caculate_checksum(buffer1, ldi->size);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }

    memset(buffer1, 0xFF, ldi->total_records * ldi->size);
    ldi->default_value = NVRAM_EF_FF_DEFAULT;
    /* Reset: basic */
    ldi->attr = NVRAM_ATTR_PACKAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item_chksum(ldi,  1, ldi->total_records, (kal_uint16 *)buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    chksum1 = nvram_util_caculate_checksum(buffer1, ldi->size);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }

    for(i = 0 ;i < ldi->total_records; i++)
    {
        for (j = 0 ;j < ldi->size; j+=2)
        {
            buffer1[ldi->size * i + j] = (ldi->size * i + j) & 0xFF;
            buffer1[ldi->size * i + j + 1] = ((ldi->size * i + j) >> 8) & 0xFF;
        }
    }
    ldi->default_value = buffer1;

    /* Reset: basic */
    ldi->attr = NVRAM_ATTR_PACKAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item_chksum(ldi,  1, ldi->total_records, (kal_uint16 *)buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    chksum1 = nvram_util_caculate_checksum(buffer1, ldi->size);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }

    /* Reset: multi_default */
    ldi->attr = NVRAM_ATTR_PACKAGE | NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item_chksum(ldi,  1, ldi->total_records, (kal_uint16 *)buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        chksum1 = nvram_util_caculate_checksum(buffer1 + ldi->size * i, ldi->size);
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }

    /* Reset: confidential */
    ldi->attr = NVRAM_ATTR_PACKAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item_chksum(ldi,  1, ldi->total_records, (kal_uint16 *)buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    chksum1 = nvram_util_caculate_checksum(buffer1, ldi->size);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }

    /* Reset: confidential + multi_default*/
    ldi->attr = NVRAM_ATTR_PACKAGE | NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL;
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    NVUT(nvram_read_data_item_chksum(ldi,  1, ldi->total_records, (kal_uint16 *)buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        chksum1 = nvram_util_caculate_checksum(buffer1 + ldi->size * i, ldi->size);
        chksum2 = *(kal_uint16*) (buffer2 + NVRAM_CHKSUM_SIZE * i);
        NVUT(chksum1 == chksum2);
    }

    ldi->size = NVRAM_EF_NVRAM_UNIT_TEST_SIZE;
    ldi->total_records = NVRAM_EF_NVRAM_UNIT_TEST_TOTAL;
    ldi->default_value = NVRAM_EF_ZERO_DEFAULT;
    ldi->attr = NVRAM_ATTR_AVERAGE;
    ldi->category = NVRAM_CATEGORY_USER;

    return unit_test_result;
}

static kal_bool nvram_unit_test_pseudo_merge(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unit_test_result  = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

start_test:
    NVUT(nvram_unit_test_pseudo_merge_1(10, 5) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- Pseudo merge(10,5): %d\n", PERFORMANCE_TIME_PASS);

    NVUT(nvram_unit_test_pseudo_merge_1(128, 5) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- Pseudo merge(128,5): %d\n", PERFORMANCE_TIME_PASS);

    NVUT(nvram_unit_test_pseudo_merge_2(10, 5) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- Pseudo merge read_chksum(10,5): %d\n", PERFORMANCE_TIME_PASS);

    NVUT(nvram_unit_test_pseudo_merge_2(128, 5) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- Pseudo merge read_chksum(128,5): %d\n", PERFORMANCE_TIME_PASS);

    if (ut_io_status == NVRAM_IO_ERRNO_OK)
    {
        ut_io_status = NVRAM_IO_ERRNO_CHK;
        goto start_test;
    }

    ut_io_status = NVRAM_IO_ERRNO_OK;

    return unit_test_result;
}

#endif


#ifdef __NVRAM_SECURE_DATA_STORAGE__
static kal_bool nvram_unit_test_sds_1(kal_uint32 size, kal_uint16 total_records)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unit_test_result  = KAL_TRUE;
    nvram_ltable_entry_struct *ldi = NULL;
    kal_int32 i, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_util_get_data_item(&ldi, NVRAM_EF_NVRAM_UNIT_TEST_LID);

    ldi->size = size;
    ldi->total_records = total_records;
    ldi->category = NVRAM_CATEGORY_BACKUP_SDS;

/*********************************************
 *   1. Backup & Reset function
 ********************************************/
        
    /**************************************************
     *   1-1. Defaul value is NVRAM_EF_ZERO_DEFAULT
     **************************************************/
    ldi->attr = NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    ldi->default_value = NVRAM_EF_ZERO_DEFAULT;
    //Write 0x00 to the LID and the SDS
    memset(buffer1, 0x00, ldi->total_records * ldi->size);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
    }    

    nvram_access_sds(NVRAM_SDS_ACCESS_BACKUP);

    //Write 0xFF to the LID
    memset(buffer2, 0xFF, ldi->total_records * ldi->size);
    NVUT(nvram_write_data_item(ldi, 1, buffer2, KAL_FALSE) == NVRAM_IO_ERRNO_OK);

    //Reset the LID
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);
    
    //Read the LID
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);

    //Compare the buffer, it should be 0x00
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }
    
    /**************************************************
     *   1-2. Defaul value is NVRAM_EF_FF_DEFAULT
     **************************************************/
    ldi->attr = NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    ldi->default_value = NVRAM_EF_FF_DEFAULT;
    //Write 0xFF to the LID and the SDS
    memset(buffer1, 0xFF, ldi->total_records * ldi->size);
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
    }
    
    nvram_access_sds(NVRAM_SDS_ACCESS_BACKUP);

    //Write 0x00 to the LID
    memset(buffer2, 0x00, ldi->total_records * ldi->size);
    NVUT(nvram_write_data_item(ldi, 1, buffer2, KAL_FALSE) == NVRAM_IO_ERRNO_OK);

    //Reset the LID
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);

    //Read the LID
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);

    //Compare the buffer, it should be 0x00
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }

    /**************************************************
     *   1-2-2. Generate new default value for next case
     **************************************************/   
    for(i = 0 ;i < ldi->total_records; i++)
    {
        for (j = 0 ;j < ldi->size; j+=2)
        {
            buffer1[ldi->size * i + j] = (ldi->size * i + j) & 0xFF;
            buffer1[ldi->size * i + j + 1] = ((ldi->size * i + j) >> 8) & 0xFF;
        }
    }
    ldi->default_value = buffer1;

    /**************************************************
     *   1-3. Single default
     **************************************************/
    ldi->attr = NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    //Write to the LID and the SDS
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
    }    

    nvram_access_sds(NVRAM_SDS_ACCESS_BACKUP);

    //Write 0x00 to the LID
    memset(buffer2, 0x00, ldi->total_records * ldi->size);
    NVUT(nvram_write_data_item(ldi, ldi->total_records, buffer2, KAL_FALSE) == NVRAM_IO_ERRNO_OK);

    //Reset the LID
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);

    //Read the LID
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);

    //Compare the buffer, it should be 0x00
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }

    /**************************************************
     *   1-4. Multiple default
     **************************************************/
    ldi->attr = NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    ldi->attr |= NVRAM_ATTR_MULTI_DEFAULT;
    //Write to the LID and the SDS
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
    }    

    nvram_access_sds(NVRAM_SDS_ACCESS_BACKUP);

    //Write 0x00 to the LID
    memset(buffer2, 0x00, ldi->total_records * ldi->size);
    NVUT(nvram_write_data_item(ldi, ldi->total_records, buffer2, KAL_FALSE) == NVRAM_IO_ERRNO_OK);

    //Reser the LID
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);

    //Read the LID
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);

    //Compare the buffer, it should be 0x00
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }


    /**************************************************
     *   1-5. Confidential single default
     **************************************************/
    ldi->attr = NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    ldi->attr |= NVRAM_ATTR_CONFIDENTIAL;
    //Write to the LID and the SDS
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
    }    

    nvram_access_sds(NVRAM_SDS_ACCESS_BACKUP);

    //Write 0x00 to the LID
    memset(buffer2, 0x00, ldi->total_records * ldi->size);
    NVUT(nvram_write_data_item(ldi, ldi->total_records, buffer2, KAL_FALSE) == NVRAM_IO_ERRNO_OK);

    //Reser the LID
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);

    //Read the LID
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);

    //Compare the buffer, it should be 0x00
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }

    /**************************************************
     *   1-6. Confidential multiple default
     **************************************************/
    ldi->attr = NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    ldi->attr |= (NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_CONFIDENTIAL);
    //Write to the LID and the SDS
    for(i = 0; i < ldi->total_records; i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
    }    

    nvram_access_sds(NVRAM_SDS_ACCESS_BACKUP);

    //Write 0x00 to the LID
    memset(buffer2, 0x00, ldi->total_records * ldi->size);
    NVUT(nvram_write_data_item(ldi, ldi->total_records, buffer2, KAL_FALSE) == NVRAM_IO_ERRNO_OK);

    //Reser the LID
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);

    //Read the LID
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);

    //Compare the buffer, it should be 0x00
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }
    
#ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
    /********************************************************************************
     * 1-7: Default value is single & (MSP + Confidentail)
     *********************************************************************************/
    ldi->attr = NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    ldi->attr |= (NVRAM_ATTR_CONFIDENTIAL | NVRAM_ATTR_MSP);
    //Write to the LID and the SDS
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
    }    

    nvram_access_sds(NVRAM_SDS_ACCESS_BACKUP);

    //Write 0x00 to the LID
    memset(buffer2, 0x00, ldi->total_records * ldi->size);
    NVUT(nvram_write_data_item(ldi, ldi->total_records, buffer2, KAL_FALSE) == NVRAM_IO_ERRNO_OK);

    //Reser the LID
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);

    //Read the LID
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);

    //Compare the buffer, it should be 0x00
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }
    /********************************************************************************
     * 1-8: Default value is multiple & (MSP + Confidentail)
     *********************************************************************************/
    ldi->attr = NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_AVERAGE;
    ldi->attr |= NVRAM_ATTR_MULTI_DEFAULT;
    //Write to the LID and the SDS
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
    }    

    nvram_access_sds(NVRAM_SDS_ACCESS_BACKUP);

    //Write 0x00 to the LID
    memset(buffer2, 0x00, ldi->total_records * ldi->size);
    NVUT(nvram_write_data_item(ldi, ldi->total_records, buffer2, KAL_FALSE) == NVRAM_IO_ERRNO_OK);

    //Reser the LID
    NVUT(nvram_reset_data_items(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, ldi, 1, ldi->total_records) == KAL_TRUE);

    //Read the LID
    NVUT(nvram_read_data_item(ldi,  1, ldi->total_records, buffer2, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);

    //Compare the buffer, it should be 0x00
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(kal_mem_cmp(buffer1, buffer2 + i * ldi->size, ldi->size)==0);
    }
#endif    

/*********************************************
 *   2. Restore function
 ********************************************/
    ldi->attr = NVRAM_ATTR_MULTI_DEFAULT;
    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(nvram_write_data_item(ldi, i + 1, buffer1 + i * ldi->size, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
    }

    nvram_access_sds(NVRAM_SDS_ACCESS_RESTORE);

    //Write 0x00 to the LID
    memset(buffer2, 0x00, ldi->total_records * ldi->size);
    NVUT(nvram_write_data_item(ldi, ldi->total_records, buffer2, KAL_FALSE) == NVRAM_IO_ERRNO_OK);
    
    nvram_access_sds(NVRAM_SDS_ACCESS_RESTORE);

    for(i = 0 ;i < ldi->total_records;i++)
    {
        NVUT(nvram_read_data_item(ldi,  i + 1, 1, buffer2 + i * ldi->size, sizeof(buffer2)) == NVRAM_IO_ERRNO_OK);
        NVUT(kal_mem_cmp(buffer1 + i * ldi->size, buffer2 + i * ldi->size, ldi->size)==0);
    }

    ldi->size = NVRAM_EF_NVRAM_UNIT_TEST_SIZE;
    ldi->total_records = NVRAM_EF_NVRAM_UNIT_TEST_TOTAL;
    ldi->default_value = NVRAM_EF_ZERO_DEFAULT;
    ldi->attr = NVRAM_ATTR_AVERAGE;
    ldi->category = NVRAM_CATEGORY_USER;
    

    return unit_test_result;
}


static kal_bool nvram_unit_test_sds(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unit_test_result  = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    NVUT(nvram_unit_test_sds_1(10, 5) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- secure data storage(10,5): %d\n", PERFORMANCE_TIME_PASS);

    NVUT(nvram_unit_test_sds_1(128, 5) == KAL_TRUE);
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- secure data storage(128,5): %d\n", PERFORMANCE_TIME_PASS);

    return unit_test_result;
}

#endif

static kal_bool nvram_unit_test_reset_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unit_test_result  = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __NVRAM_SUPPORT_CUSTPACK__
    NVUT(nvram_reset_data_items(NVRAM_RESET_CUSTPACK, NVRAM_APP_RESERVED, NULL, 0, 0) == KAL_TRUE);
#endif
    NVUT(nvram_reset_data_items(NVRAM_RESET_SECUPACK, NVRAM_APP_RESERVED, NULL, 0, 0) == KAL_TRUE);
    NVUT(nvram_reset_data_items(NVRAM_RESET_BRANCH, NVRAM_APP_RESERVED, NULL, 0, 0) == KAL_TRUE);
#ifdef __NVRAM_PSEUDO_MERGE__
    NVUT(nvram_reset_data_items(NVRAM_RESET_PACKAGE, NVRAM_APP_RESERVED, NULL, 0, 0) == KAL_TRUE);
#endif
    NVUT(nvram_reset_data_items(NVRAM_RESET_FAT, NVRAM_APP_RESERVED, NULL, 0, 0) == KAL_TRUE);

    nvram_ptr->state = NVRAM_STATE_NOT_READY;
    NVUT(nvram_reset_data_items(NVRAM_RESET_FACTORY, NVRAM_APP_RESERVED, NULL, 0, 0) == KAL_TRUE);
    nvram_ptr->state = NVRAM_STATE_READY;


    NVUT(nvram_reset_data_items(NVRAM_RESET_ALL, NVRAM_APP_RESERVED, NULL, 0, 0) == KAL_TRUE);

    return unit_test_result;
}

kal_bool nvram_unit_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unit_test_result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PERFORMANCE_START();

    unit_test_result &= nvram_unit_test_hidden_file();
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- hidden file: %d\n", PERFORMANCE_TIME_PASS);

    unit_test_result &= nvram_unit_test_basic();
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- basic: %d\n", PERFORMANCE_TIME_PASS);

#ifdef __NVRAM_BACKUP_DISK__
    unit_test_result &= nvram_unit_test_backup_disk();
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- backup_disk: %d\n", PERFORMANCE_TIME_PASS);
#endif

    unit_test_result &= nvram_unit_test_compare_to_default_value();
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- compare to default value: %d\n", PERFORMANCE_TIME_PASS);

#ifdef __NVRAM_PSEUDO_MERGE__
    unit_test_result &= nvram_unit_test_pseudo_merge();
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- pseudo merge: %d\n", PERFORMANCE_TIME_PASS);
#endif

#ifdef __NVRAM_SECURE_DATA_STORAGE__
    unit_test_result &= nvram_unit_test_sds();
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- secure data storage: %d\n", PERFORMANCE_TIME_PASS);
#endif

    unit_test_result &= nvram_unit_test_reset_function();
    PERFORMANCE_SHOW_TIME_PASS("nvram unit test -- reset function %d\n", PERFORMANCE_TIME_PASS);

    return unit_test_result;
}
#endif

