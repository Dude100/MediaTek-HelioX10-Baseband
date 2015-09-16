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
 * nvram_drval_fat.h
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _NVRAM_DRVAL_FAT_H
#define _NVRAM_DRVAL_FAT_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include "kal_general_types.h"
#include "fs_type.h"
#include "nvram_defs.h"

#include "nvram_internal.h"
/*****************************************************************************
* Define
*****************************************************************************/

#define NVRAM_MAX_PATH_LEN                   32
#define NVRAM_FS_DATATIEM_FILENAME_TPLT      "MT01_000.TMP"
#define NVRAM_FS_FOLDER_NAME                 L"NVRAM"
#define NVRAM_FS_ROOT_PATH                   "Z:\\NVRAM"
#define NVRAM_FS_DATAITEM_PATH               "Z:\\NVRAM\\NVD_DATA"
#define NVRAM_SWCHANGE_REPORT_FILE           "Z:\\NVRAM\\SWCHANGE"
#define NVRAM_SWCHANGE_REPORT_FILE_TXT       "Z:\\NVRAM\\SWCHANGE.TXT"
#ifdef __NVRAM_MULTI_FOLDERS__
#define NVRAM_FS_COREITEM_PATH               "Z:\\NVRAM\\NVD_CORE"
#define NVRAM_FS_CALIBRAT_DATAITEM_PATH	     "Z:\\NVRAM\\CALIBRAT"
#define NVRAM_FS_IMEI_DATAITEM_PATH    	     "Z:\\NVRAM\\NVD_IMEI"
#define NVRAM_FS_CUST_DATAITEM_PATH          "Z:\\NVRAM\\NVD_CUST"
    #if defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__) && defined(__CCCIFS_SUPPORT__)
    #define NVRAM_FS_IMPORTNT_DATAITEM_PATH           "X:\\"
    #define NVRAM_FS_IMPORTNT_DATAITEM_PATH2          "Y:\\"
    #define NVRAM_FS_IMPORTNT_DATAITEM_PATH3          "Z:\\NVRAM\\IMPORTNT"
    #else
#define NVRAM_FS_IMPORTNT_DATAITEM_PATH      "Z:\\NVRAM\\IMPORTNT"
#endif
#endif

#ifdef __NVRAM_BACKUP_DISK_FAT__
#if defined(__TC01__) && defined(__MTK_TARGET__)
#define NVRAM_FS_BACKUP_ROOT_PATH            "G:\\NVRAM"
#else
#define NVRAM_FS_BACKUP_ROOT_PATH            "Z:\\NVRAM_BAK"
#endif
#endif

typedef kal_int32 nvram_drv_status_enum;
#define  NVRAM_DRV_OK                  0x00
#define  NVRAM_DRV_UNFORMATTED         0x01
#define  NVRAM_DRV_CHECKSUM_ERROR      0x02
#define  NVRAM_DRV_INVALID_RECORD_ID   0x03
#define  NVRAM_DRV_NOT_ENOUGH_SPACE    0x04
#define  NVRAM_DRV_EMPTY_RECORD        0x05
#define  NVRAM_DRV_FATAL_ERROR         0x06
#define  NVRAM_DRV_ERASE_BUSY          0x07
#define  NVRAM_DRV_DRIVE_BROKEN        0x08
#define  NVRAM_DRV_DRIVE_VNOERR        0x10
#define  NVRAM_DRV_FOLDER_NOT_READY    0x11

typedef enum
{
    NVRAM_DRV_READ_TYPE_DATA,
    NVRAM_DRV_READ_TYPE_CHKSUM,
    NVRAM_DRV_READ_TYPE_MAX
}nvram_drv_read_type_enum;

#define NVRAM_FS_MAKE_ROOT_PATH(buf)  \
   kal_wsprintf( buf, "%s", NVRAM_FS_ROOT_PATH )

#define NVRAM_FS_MAKE_BACKUP_ROOT_PATH(buf) \
    kal_wsprintf( buf, "%s", NVRAM_FS_BACKUP_ROOT_PATH )

#define NVRAM_FS_GET_FULL_PATH_LEN \
   (strlen(NVRAM_FS_DATAITEM_PATH) + strlen(NVRAM_FS_DATATIEM_FILENAME_TPLT) + 1)

/*****************************************************************************
* Extern Global Function
*****************************************************************************/
extern nvram_drv_status_enum nvram_drv_fat_status(void);
extern nvram_drv_status_enum nvram_drv_fat_init_start(void);
extern nvram_drv_status_enum nvram_drv_fat_init_end(void);

extern void nvram_drv_fat_format(void);

extern nvram_drv_status_enum nvram_drv_fat_read(
                                kal_char *nvramname,
                                nvram_folder_enum nvram_folder,      /* folder index */
                                kal_uint32 file_offset,      /* offset in package file */
                                kal_uint16 rec_index,
                                kal_uint16 rec_amount,
                                kal_uint32 rec_size,
                                kal_uint8 *buffer,
                                nvram_drv_read_type_enum type,
                                nvram_attr_enum attr);

extern kal_int32 nvram_drv_fat_read_section(
            FS_HANDLE hFile,
            kal_uint16 rec_index,
            kal_uint16 rec_amount,
            kal_uint32 rec_size,
            kal_uint8 *buffer,
            nvram_drv_read_type_enum type,
            nvram_attr_enum attr
			);

#if defined(__NVRAM_FS_OPERATION_COMPACT__)	&& defined(__CCCIFS_SUPPORT__) && defined(__MTK_TARGET__) 		
extern kal_int32 nvram_drv_fat_read_section_cmp(
			FS_HANDLE hFile,
			kal_uint16 rec_index,
			kal_uint16 rec_amount,
			kal_uint32 rec_size,
			kal_uint8 *buffer,
			nvram_drv_read_type_enum type,
			nvram_attr_enum attr,
			kal_wchar *filename,
			NVRAM_FS_PARAM_CMPT_T *nvram_param
			);
#endif


extern nvram_drv_status_enum nvram_drv_fat_write(
                                kal_char   *nvramname,
                                nvram_folder_enum  nvram_folder,
                                kal_uint32 file_offset,
                                kal_uint16 rec_index,
                                kal_uint16 rec_amount,
                                kal_uint32 rec_size,
                                const kal_uint8 *buffer,
                                nvram_attr_enum attr,
                                kal_bool   initialize);

extern kal_int32 nvram_drv_fat_write_section(
    FS_HANDLE hFile,
    const kal_uint8 *buffer,
    kal_uint16 rec_index,
    kal_uint16 rec_amount,
    kal_uint32 rec_size,
    nvram_attr_enum attr);

extern kal_int32 nvram_drv_fat_backup(nvram_ltable_entry_struct *ldi, kal_bool a_to_b);

extern kal_int32 nvram_drv_fat_get_record_size(kal_char *nvramname, void *hint, nvram_folder_enum nvram_folder);

extern nvram_drv_status_enum nvram_drv_fat_read_exception_item(
                                kal_uint8 *buffer,
                                kal_char *nvramname,
                                kal_uint16 section_number,
                                kal_uint32 size,
                                kal_uint32 readsize);

extern kal_int32 nvram_drv_fat_get_last_err(void);
extern kal_uint32 nvram_drv_fat_get_last_line(void);

extern kal_int32 nvram_drv_fat_set_read_only(kal_char *nvramname, nvram_folder_enum nvram_folder, kal_bool read_only);
extern void nvram_drv_fat_take_mutex(kal_mutexid ext_mutex_id_ptr);
extern void nvram_drv_fat_give_mutex(kal_mutexid ext_mutex_id_ptr);

extern kal_int32 nvram_drv_fat_auto_recover(
            kal_char *nvramname,
            nvram_folder_enum nvram_folder
            );

#ifdef __cplusplus
}
#endif

#endif /* _NVRAM_DRVAL_FAT_H */

