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
 *    ramdisk_gprot.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This is header file for RAM Disk drivers.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#ifndef __RAMDISK_DRV_H__
#define __RAMDISK_DRV_H__

#include "custom_MemoryDevice.h"
#include "kal_general_types.h"
#include "fs_gprot.h"

/*--------------------------------------------------------
 * RAM Disk Size Configurations
 *--------------------------------------------------------*/


#ifdef RAMDISK_FS_SIZE
    #define RAM_FS_SIZE                 (RAMDISK_FS_SIZE)                   // read FS size setting in custom_MemoryDevice.h
#else
    #define RAM_FS_SIZE                 (0x00300000)                        // default total RAM disk size: 3 MB
#endif

#ifdef RAMDISK_FS_FIRST_DRIVE_SECTORS
    #define RAM_FS_FIRST_DRIVE_SECTORS  (RAMDISK_FS_FIRST_DRIVE_SECTORS)    // read FS first partition size setting in custom_MemoryDevice.h
#else
    #define RAM_FS_FIRST_DRIVE_SECTORS  (0)                                 // default public drive size: 0 (unit: number of 512-byte-sectors)
#endif

/*--------------------------------------------------------
 * RAM Disk Internal Definitions
 *--------------------------------------------------------*/

#define RAM_SECTOR_SIZE                 (512)

/*--------------------------------------------------------
 * RAM Disk Error Codes
 *--------------------------------------------------------*/

typedef enum
{
    RAMDISK_NO_ERROR                = 0,
    RAMDISK_INVALID_DISK_OFFSET     = -1,
    RAMDISK_INVALID_DISK_SIZE       = -2,
    RAMDISK_NOT_EXISTED             = -3,
    RAMDISK_ERROR_CODE_END          = -65536
} ramdisk_error_code;

/*--------------------------------------------------------
 * RAM Disk Query and Read Tool (for META Tool only now)
 *--------------------------------------------------------*/

/*
 *  Check if RAM Disk is supported in this project. Please use this API to detect RAM Disk before using any other RAM Disk APIs.
 *
 *  Return Value:
 *      1: RAM Disk is existed.
 *      0: RAM Disk is not existed.
 */
kal_uint32 ramdisk_is_existed(void);

/*
 *  Get start address of RAM Disk.
 *
 *  Return Value:
 *      Valid address must be a non-zero value. 0 means an invalid address.
 */
kal_uint32 ramdisk_get_raw_start_address(void);

/*
 *  Get length of RAM Disk.
 *
 *  Return Value:
 *      Valid length must be a non-zero value. 0 means an invalid length.
 */
kal_uint32 ramdisk_get_raw_length(void);

/*
 *  Get raw data from RAM Disk.
 *
 *  Parameters:
 *      [in/out] buf: Buffer address to read RAM Disk data (Buffer address could be byte-aligned)
 *      [in] offset: Start offset. The valid range is 0 to disk size.
 *      [in] length: Total read length
 *
 *  Return Value:
 *      Positive integer: Number of bytes read to buffer successfully.
 *      Negative integer: It is an error code. Please refer to ramdisk_error_code enum defined in ramdisk_gprot.h for the meaning of error codes.
 */
kal_int32 ramdisk_get_raw_data(void * buf, kal_uint32 offset, kal_uint32 length);

/*--------------------------------------------------------
 * RAM Disk Management Layer
 *--------------------------------------------------------*/
int     ramdisk_fdm_mount_device(void * DriveData, int DeviceNumber, int DeviceType, kal_uint32 Flags);
int     ramdisk_fdm_shutdown(void * DriveData);
int     ramdisk_fdm_read_sectors(void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Data);
int     ramdisk_fdm_write_sectors(void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Data);
int     ramdisk_fdm_media_changed(void * DriveData);
int     ramdisk_fdm_get_disk_geometry(void * DriveData, FS_PartitionRecord * DiskGeometry, kal_uint8 * MediaDescriptor);
int     ramdisk_fdm_recoverable_write_sectors(void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Buffer);
int     ramdisk_fdm_resume_sector_states(void * DriveData);
void    ramdisk_util_memcpy(void * dst, void * src, kal_uint32 len);

#endif // __RAMDISK_DRV_H__

