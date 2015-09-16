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
 * nvram_interface.h
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NVRAM_INTERFACE_H
#define NVRAM_INTERFACE_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "nvram_enums.h"
#include "nvram_defs.h"

typedef struct
{
    kal_bool (*callback)(void *user_data);
    void *user_data;
    module_type module;
    nvram_lid_enum file_id;
    kal_bool processed;
}nvram_read_callback_struct;

#if defined(__MTK_TARGET__)
#define nvram_read_callback_entry nvram_read_callback_struct __attribute__((section("_nvram_callback_tbl")))
#else
#ifdef _MSC_VER
#define nvram_read_callback_entry __pragma(section("_nvram_callback_tbl_content")) \
                            nvram_read_callback_struct __declspec(allocate("_nvram_callback_tbl_content"))
#else
#define nvram_read_callback_entry nvram_read_callback_struct __attribute__((section("_nvram_callback_tbl_content")))
#endif
#endif

/*****************************************************************************
 * FUNCTION
 *  nvram_get_info
 * DESCRIPTION
 *  This is nvram_get_info() function of NVRAM module.
 * PARAMETERS
 *  LID:         [IN]   NVRAM LID
 *  total:       [OUT]  The record number of the LID
 *  size:        [OUT]  The record size of the LID
 * RETURNS
 *  NVRAM_ERRNO_SUCCESS if succeed, NVRAM_ERRNO_INVALID otherwise (ie, invalid LID).
 *****************************************************************************/
extern nvram_errno_enum nvram_get_info(nvram_lid_enum LID, kal_uint16 *total, kal_uint16 *size);

/*****************************************************************************
 * FUNCTION
 *  nvram_write_exception
 * DESCRIPTION
 *
 * PARAMETERS
 *  length:      [IN]   buffer length
 *  ex_data:     [IN]   ex_data
 * RETURNS
 *  void
 *****************************************************************************/
extern void nvram_write_exception(kal_uint16 length, long *ex_data);

/*****************************************************************************
 * FUNCTION
 *  nvram_get_lid_num
 * DESCRIPTION
 *  To get the total number of LID
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_ptr->ltable.total_LID
  *****************************************************************************/
extern nvram_lid_enum nvram_get_lid_num(void);

/*****************************************************************************
 * FUNCTION
 *  nvram_check_backup
 * DESCRIPTION
 *  To tell given LID needs to backup or not
 * PARAMETERS
 *  LID:        [IN]    LID of the file
 *  prefix:     [IN]    file prefix
 * RETURNS
 *  NVRAM_IO_ERRNO_OK: need to backup
 *  NVRAM_IO_ERRNO_INVALID_LID: LID out of range or don't need to backup
  *****************************************************************************/
extern kal_uint8 nvram_check_backup(nvram_lid_enum LID, kal_char **prefix, kal_char **verno);

/*****************************************************************************
 * FUNCTION
 *  nvram_validate_file
 * DESCRIPTION
 *  To validate integrity of  the given file
 * PARAMETERS
 *  LID:        [IN]    LID of the file
 *  path:       [IN]    path to validate
 * RETURNS
 *  NVRAM_IO_ERRNO_OK: valid
 *  NVRAM_IO_ERRNO_INVALID_LID: LID out of range
 *  others: invalid
  *****************************************************************************/
extern nvram_errno_enum nvram_validate_file(nvram_lid_enum LID, kal_wchar *path);

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
void nvram_shutdown_handler(void);

/*****************************************************************************
 * FUNCTION
 *  nvram_test_lock
 * DESCRIPTION
 *  get lock state from nvram context.
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_TRUE if locked, else KAL_FALSE
 *****************************************************************************/
extern kal_bool nvram_test_lock(void);

/*****************************************************************************
 * FUNCTION
 *  nvram_space_reserve
 * DESCRIPTION
 *  get lock state from nvram context.
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_TRUE if locked, else KAL_FALSE
 *****************************************************************************/
extern void nvram_space_reserve(kal_uint32 *size_from_code);

/*****************************************************************************
 * FUNCTION
 *  nvram_usb_read_data
 * DESCRIPTION
 *  This function is used to get bmt calibration data ONLY when USB power on.
 * PARAMETERS
 *  LID:            [IN]
 *  buffer:         [OUT]
 *  buffer_size:    [IN]
 * RETURNS
 *  NVRAM_ERRNO_SUCCESS if succeed, NVRAM_ERRNO_INVALID otherwise (ie, invalid LID).
 *****************************************************************************/
extern kal_bool nvram_usb_read_data(nvram_lid_enum LID, kal_uint8 *buffer, kal_uint32 buffer_size);

/*****************************************************************************
 * FUNCTION
 *  nvram_sec_port_is_enable
 * DESCRIPTION
 *  To get TST port status
 * PARAMETERS
 *  void
 * RETURNS
 *  TST port Enable or Disable
 *****************************************************************************/
extern kal_bool nvram_sec_port_is_enable(void);

/*****************************************************************************
 * FUNCTION
 *  nvram_get_default_value
 * DESCRIPTION
 *  This function is used to get default value for external modules.
 * PARAMETERS
 *  LID:             [IN]
 *  rec_index:       [IN]
 *  p_buffer:        [IN/OUT]
 *
 * RETURNS
 *  NVRAM_DEFAULT_VALUE_FAIL : get default value fail
 *  NVRAM_DEFAULT_VALUE_FF   : p_buffer is invalid, default value is FF
 *  NVRAM_DEFAULT_VALUE_ZERO : p_buffer is invalid, default value is zero
 *  NVRAM_DEFAULT_VALUE_POINT: p_buffer is valid, use p_buffer to get default value
 *****************************************************************************/
extern nvram_default_value_enum nvram_get_default_value(nvram_lid_enum LID,
                                                        kal_uint16 rec_index,
                                                        kal_uint8 **p_buffer);

/*****************************************************************************
 * FUNCTION
 *  nvram_get_file_fullname
 * DESCRIPTION
 *  To get the full name of nvram file.
 * PARAMETERS
 *  folder_idx : [In]   folder index
 *  nvramname  : [In]   nvram name
 *  filename   : [Out]  full file path
 * RETURNS
 *  index of folder.
 *****************************************************************************/
extern kal_wchar * nvram_get_file_fullname(kal_uint8 folder_idx,
                                           kal_char *nvramname,
                                           kal_wchar *filename);

/*****************************************************************************
 * FUNCTION
 *  nvram_get_folder_idx
 * DESCRIPTION
 *  To get the index of nvram folder.
 * PARAMETERS
 *  LID:    [IN]    NVRAM LID
 * RETURNS
 *  index of folder.
 *****************************************************************************/
extern kal_uint8 nvram_get_folder_idx(nvram_lid_enum LID);

/*****************************************************************************
 * FUNCTION
 *  nvram_get_work_path
 * DESCRIPTION
 *  To get NVRAM working directory.
 * PARAMETERS
 *  folder_idx  :   [IN]    Which folder
 * RETURNS
 *  NVRAM working directory.
 *****************************************************************************/
extern kal_char *nvram_get_work_path(kal_uint8 folder_idx);

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
extern kal_uint8 nvram_get_folder_total_amount(void);

/*****************************************************************************
 * FUNCTION
 *  nvram_external_read_data
 * DESCRIPTION
 *  This function is used to read data items for external modules.
 *  Please must check with NVRAM owner before you use this API.
 * PARAMETERS
 *  LID:            [IN]    NVRAM LID
 *  rec_index:      [IN]    record index
 *  buffer:         [OUT]    buffer pointer
 *  buffer_size:    [IN]    buffer size
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  KAL_FALSE:  fail
 *  KAL_TRUE:   success
 *****************************************************************************/
extern kal_bool nvram_external_read_data(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint8 *buffer, kal_uint32 buffer_size);

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
extern kal_bool nvram_external_read_chksum(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint16 rec_amount, kal_uint8 *buffer, kal_uint32 buffer_size);

/*****************************************************************************
 * FUNCTION
 *  nvram_external_write_data
 * DESCRIPTION
 *  This function is used to write data items for external modules.
 *  Please must check with NVRAM owner before you use this API.
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
extern kal_bool nvram_external_write_data(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint8 *buffer, kal_uint32 buffer_size);

/*****************************************************************************
 * FUNCTION
 *  nvram_external_reset_data
 * DESCRIPTION
 *  This function is used to reset data items for external modules.
 *  Please must check with NVRAM owner before you use this API.
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
kal_bool nvram_external_reset_data(nvram_lid_enum LID, kal_uint16 rec_index, kal_uint16 rec_amount);

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
 *  filename:    [IN]    the filename
 *  backup:      [IN]    During backup/restore the hidden file is different from normal
 *                       Please set this as true during backup/restore
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  KAL_TRUE:   hidden
 *  KAL_FALSE:  not hidden
 *****************************************************************************/
    extern kal_bool nvram_check_hidden_file(const kal_wchar* filename, kal_bool backup);


/*****************************************************************************
 * FUNCTION
 *  nvram_get_imei_type
 * DESCRIPTION
 *  To get storage type of IMEI
 * PARAMETERS
 *  void
 * RETURNS
 *  NVRAM_STORAGE_TYPE_FAT: store in FAT
 *  NVRAM_STORAGE_TYPE_OTP: store in OTP
 *  NVRAM_STORAGE_TYPE_SECRO: store in secure RO
 *****************************************************************************/
extern kal_uint8 nvram_get_imei_type(void);

/*****************************************************************************
 * FUNCTION
 *  nvram_get_imei_value
 * DESCRIPTION
 *  To get the IMEI value via blocking function
 * PARAMETERS
 *  length:      [IN]        Length of imei_buf, in byte, at least 8 bytes.
 *  imei_buf:    [OUT]       buffer to fill in IMEI
 *  rec_index:   [IN]        Can be 1 or 2 to access both IMEI on dual sim project.
 *                          It should be 1 on single sim project.
 * RETURNS
 *  KAL_TRUE: SUCCESS
 *  KAL_FALSE: FAIL
 *****************************************************************************/
extern kal_bool nvram_get_imei_value(kal_uint8 length, kal_uint8 *imei_buf, kal_uint16 rec_index);

/*****************************************************************************
 * FUNCTION
 *  nvram_get_imei_record_num
 * DESCRIPTION
 *  To get the record number of imei
 * PARAMETERS
 *  void
 * RETURNS
 *  number of imei record number
 *****************************************************************************/
extern kal_uint16 nvram_get_imei_record_num(void);

/*****************************************************************************
 * FUNCTION
 *  nvram_is_imei_unset
 * DESCRIPTION
 *  To tell if the IMEI equals to its default value.
 * PARAMETERS
 *  rec_index:   [IN]    the index of record
 * RETURNS
 *  KAL_TRUE: unset
 *  KAL_FALSE: set
 *****************************************************************************/
extern kal_bool nvram_is_imei_unset(kal_uint16 rec_index);




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
extern kal_int32 nvram_compare_to_default_value(nvram_lid_enum LID, kal_uint16 rec_index);



extern kal_uint8 *nvram_get_custpack_version(void);
/*****************************************************************************
 * FUNCTION
 *  nvram_set_restore_factory_flag
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern kal_bool nvram_set_restore_factory_flag(nvram_restore_flag_enum restore_flag);

/*****************************************************************************
 * FUNCTION
 *  nvram_check_restore_factory_flag
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern kal_bool nvram_check_restore_factory_flag(void);

/*****************************************************************************
 * FUNCTION
 *  nvram_ltable_register
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern void nvram_ltable_register(nvram_ltable_entry_struct *table);


/*****************************************************************************
 * FUNCTION
 *  nvram_register_read_req
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern kal_bool nvram_register_read_req(nvram_read_callback_struct *entry);


/*****************************************************************************
 * for FT task to get all nvram data items
*****************************************************************************/
extern kal_bool nvram_util_next_data_item(nvram_ltable_entry_struct **entry);
extern kal_bool nvram_util_get_data_item(nvram_ltable_entry_struct **ldi, nvram_lid_enum LID);


#ifdef __cplusplus
}
#endif

#endif /* NVRAM_INTERFACE_H */

