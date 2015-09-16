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
 * Filename:
 * ---------
 * nvram_io.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is startup_handler() of NVRAM module.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef NVRAM_IO_H
#define NVRAM_IO_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "kal_general_types.h"
#include "nvram_defs.h"

#include "nvram_config.h"
#include "nvram_internal.h"


/******************************************************
 *  FAT
 ******************************************************/
extern nvram_errno_enum nvram_read_data_item(
                            nvram_ltable_entry_struct *ldi,
                            kal_uint16 rec_index,
                            kal_uint16 rec_amount,
                            kal_uint8 *buffer,
                            kal_uint32 buffer_size);

extern nvram_errno_enum nvram_read_data_item_chksum(
                            nvram_ltable_entry_struct *ldi,
                            kal_uint16 rec_index,
                            kal_uint16 rec_amount,
                            kal_uint16 *chksum,
                            kal_uint32 chksum_size);

extern nvram_errno_enum nvram_write_data_item(
                            nvram_ltable_entry_struct *ldi,
                            kal_uint16 index,
                            kal_uint8 *data,
                            kal_bool is_init);

extern kal_uint8 const * nvram_get_default_value_to_write(
                    nvram_ltable_entry_struct *ldi,
                    kal_uint16 rec_index,
                    kal_uint8 *buffer,
                    kal_uint32 buffer_size);

extern kal_bool nvram_reset_data_items(
                    nvram_reset_category_enum reset_category,
                    nvram_app_id_enum  app_id,
                    nvram_ltable_entry_struct *ldi,
                    kal_uint16 rec_index,
                    kal_uint16 rec_amount);

extern kal_bool nvram_check_restore_factory_flag(void);

/******************************************************
 *  OTP
 ******************************************************/

#ifdef __NVRAM_OTP__
extern nvram_errno_enum nvram_read_otp_data_item(nvram_ltable_entry_struct *ldi, kal_uint16 rec_index, kal_uint16 rec_amount, kal_uint8 *buffer, kal_uint32 buffer_size);
extern nvram_errno_enum nvram_write_otp_data_item(nvram_ltable_entry_struct *ldi, kal_uint16 index, kal_uint8 *data, kal_uint32 buffer_size);
#endif /* __NVRAM_OTP__ */

/******************************************************
 *  Custom Disk
 ******************************************************/

#ifdef __NVRAM_CUSTOM_DISK__
extern nvram_errno_enum nvram_read_custom_disk(nvram_ltable_entry_struct *ldi, kal_uint16 rec_index, kal_uint16 rec_amount, kal_uint8 *buffer, kal_uint32 buffer_size);
extern nvram_errno_enum nvram_write_custom_disk(nvram_ltable_entry_struct *ldi, kal_uint16 index, kal_uint8 *data, kal_uint32 buffer_size, kal_bool is_init);
#endif

/******************************************************
 *  Secure Data Storage
 ******************************************************/

#ifdef __NVRAM_SECURE_DATA_STORAGE__
extern nvram_errno_enum nvram_sds_status(void);
extern nvram_errno_enum nvram_sds_init_start(void);
extern nvram_errno_enum nvram_sds_init_end(void);
extern nvram_errno_enum nvram_sds_read_data_item(nvram_ltable_entry_struct *ldi, kal_uint16 rec_index, kal_uint16 rec_amount, kal_uint8 *buffer, kal_uint32 buffer_size);
extern nvram_errno_enum nvram_sds_write_data_item(nvram_ltable_entry_struct *ldi, kal_uint16 index, kal_uint8 *data, kal_uint32 buffer_size, kal_bool is_init);
extern nvram_errno_enum nvram_sds_backup(void);
extern nvram_errno_enum nvram_sds_restore(void);
extern kal_int32 nvram_sds_get_last_err(void);
#endif

/******************************************************
 *  Backup Partition
 ******************************************************/

#ifdef __SYSDRV_BACKUP_DISK_FAT__
extern nvram_errno_enum nvram_init_backup_disk(void);
extern nvram_errno_enum nvram_recover_image_by_lid(nvram_ltable_entry_struct *ldi);
#elif defined(__SYSDRV_BACKUP_DISK_RAW__)
extern nvram_errno_enum nvram_init_backup_disk(void);
extern nvram_errno_enum nvram_create_image(nvram_image_type_enum image_type);
extern nvram_errno_enum nvram_recover_image(nvram_image_type_enum image_type);
extern nvram_errno_enum nvram_verify_image(nvram_image_type_enum image_type, kal_bool fast_verify);
extern nvram_errno_enum nvram_recover_image_by_lid(nvram_ltable_entry_struct *ldi);
#endif

/******************************************************
 *  AP BIN Region
 ******************************************************/
extern nvram_errno_enum nvram_ap_bin_region_backup(void);

#if defined(__SMART_PHONE_MODEM__) && defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__)
kal_int32 nvram_recover_protect(nvram_ltable_entry_struct *ldi);
#endif


#ifdef __cplusplus
}
#endif

#endif /* NVRAM_IO_H */ 

