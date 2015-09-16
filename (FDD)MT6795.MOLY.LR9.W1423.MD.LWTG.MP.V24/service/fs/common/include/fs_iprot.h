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
 *   fs_iprot.h
 *
 * Project:
 * --------
 *   Maui Software
 *
 * Description:
 * ------------
 *   This file provides the header of MTK file system internal prototypes.
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
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 ****************************************************************************/
#ifndef _FS_IPROT_H
#define _FS_IPROT_H

#include "fs_gprot.h"

//-----------------------------------------------------------------------------
// Internal Macros
//-----------------------------------------------------------------------------
// FS_DeviceInfo (RTFDeviceInfo) related definition (internal)
#define FS_DEVICE_FLAG_VISIBLE   (0x00000001)
#define FS_DEVICE_FLAG_PRESENT   (0x00000010)

//-- TLS (internal)
#ifndef MAX_TLS_INDEX
#define MAX_TLS_INDEX           2
#endif

//-- Trace (internal)
#define FS_TRACE_INDEX          2  // (should obsolete)

//-- Flag of FS_Buffer.recoverable_flag (internal)
#define FS_RECOVERABLE_WRITE    1
#define FS_NORMAL_WRITE         0

//-- Recursive Engine maximum level
#define FS_MAX_FOLDER_LEVEL     (128) // The maximum folder level for FAT FS

//-- Short filename
#define FS_PRIVATE_FLAG_IGNORE_SFN_GENERATION    (0x0001)


//-----------------------------------------------------------------------------
// Internal Enumerations
//-----------------------------------------------------------------------------
//-- For Driver only
typedef enum
{
    FS_DEVICE_UNKNOWN,
    FS_DEVICE_FLOPPY,
    FS_DEVICE_FDISK
} FS_DRIVER_DEVICE_ENUM;

//-- For Driver->MessageAck
typedef enum
{
    FS_DEV_IN_ACK_ENUM = 1,
    FS_DEV_SLOT_ACK_ENUM,
    FS_DEV_OUT_ACK_ENUM
} FS_ACK_TYPE_ENUM;

//-- For exception memory
typedef enum
{
    FS_MEM_TYPE_DEFAULT = 0x00,     // (invalid type)
    FS_MEM_TYPE_XDATA   = 0x01,     // for _XData
    FS_MEM_TYPE_INVALID = 0xFF      // (invalid type)
} fs_mem_type_enum;

//-- Open Hint Cache
typedef enum {
    FS_HINT_FREE = 0,
    FS_HINT_ALLOCATED,
    FS_HINT_CREATING,
    FS_HINT_STABLE,
    FS_HINT_STABLE_LOCKED,
    FS_HINT_DELETED_LOCKED
} FS_OpenHintStatusEnum;

//-- Device CFI information query
typedef enum
{
    FS_DEV_NO_BOOT = 0,
    FS_DEV_DUAL_BOOT,
    FS_DEV_TOP_BOOT,
    FS_DEV_BOTTOM_BOOT
} FS_DEVICE_BOOT_LOCATION_ENUM;

//-- FS trace file enumeration
typedef enum {
    rtfiles_c               = 0,
    rtfcore_c,
    rtfbuf_c,
    rtfex_c,
    fs_func_c,
    fs_func_adv_c,
    fs_func_async_c,
    fs_internal_c,
    fs_internal_api_c,
    fs_kal_c,
    fs_task_c,
    fs_utility_c,
    fs_usbms_c,
    fs_unknown_src_file
} fs_src_file_enum;


//-----------------------------------------------------------------------------
// Internal Structure
//-----------------------------------------------------------------------------
//-- Exception Handler: TLS
typedef struct
{
    fs_job_id   current_job;
    kal_bool    aborted;
} fs_tls_struct;


// Open Hint Location
typedef struct {
    kal_uint32     Cluster;                  // zero if none
    kal_uint32     Index;                    // undefined if none
    kal_uint32     DirCluster;
} FS_OpenHintLocation;

// FS Internal open hint
typedef struct {
    FS_OpenHintStatusEnum   Status;
    kal_uint8               FirstLevel;
    kal_uint8               HintNum;
    kal_uint8               FirstHint;
    kal_uint8               HitStamp;
    kal_uint8               Flag;
    kal_uint16              PathLength;
    FS_Drive                * Drive;
    kal_uint32              SerialNumber;
    FS_OpenHintLocation     * Location;
    WCHAR                   Path[FS_MAX_PATH / 2];
} FS_OpenHintPath;

// FS external open hint
typedef struct {
    // Dir Location
    kal_uint32  Cluster;
    kal_uint32  Index;
    // Extension
    kal_uint8   Level;
    kal_uint8   PathIndex;
    kal_uint8   MatchType;
    kal_uint8   Flag;
    kal_uint32  DirCluster;
} FS_OpenHintInt;

// SD Format
typedef enum
{
    FS_SD_FMT_OK             = 0,
    FS_SD_FMT_SIGNATURE_FAIL = 1,
    FS_SD_FMT_MBR_FAIL       = 2,
    FS_SD_FMT_BS_FAIL        = 3
} FS_SD_FMT_ENUM;

//-----------------------------------------------------------------------------
// Internal API Prototype
//-----------------------------------------------------------------------------
#if !(defined(__CCCIFS_SUPPORT__) && defined(__MTK_TARGET__))

/* DOM-NOT_FOR_SDK-BEGIN */

// Feature Phone

/*****************************************************************************
 * <GROUP  FileContent>
 *
 * FUNCTION
 *  FS_Close
 * DESCRIPTION
 *  To Close all currently open files.
 *  <WARNING>
 * PARAMETERS
 *  N/A
 * RETURNS
 *  If the function succeeds, the return value is the number of open files found
 *  and closed. If the function fails, the return value is a negative error code.
 *  In case of failure, some files may have been closed successfully, while others
 *  could not be closed.This function also invalidates all of FS's file handles,
 *  which may be in use by the application. Subsequent use of such handles will
 *  fail.
 *****************************************************************************/
extern int FS_CloseAll(void);

/*****************************************************************************
 * <GROUP  FileOperation>
 *
 * FUNCTION
 *  FS_ReleaseFH
 * DESCRIPTION
 *  This function can release all the file handles used by the specified task.
 * PARAMETERS
 *  TaskId : [IN]<P>Specified the file handled owned by the task. If this value
 *                  is NULL, FS will release all the file handles occupied by
 *                  the current task.
 * RETURNS
 *   Always returns FS_NO_ERROR.
 *****************************************************************************/
extern int FS_ReleaseFH(void * TaskId);

/*****************************************************************************
 * <GROUP  Obsolete >
 *
 * FUNCTION
 *  FS_GetFirstCluster
 * DESCRIPTION
 *  This function provides facility to get the first cluster (unique file/folder
 *  information in a drive).
 * PARAMETERS
 *  FileHandle : [IN] <P>User provides specified file handle
 *  Cluster    : [OUT]<P>The first cluster number to return
 * RETURNS
 *  Successful  : FS_NO_ERROR
 *  Failed      : Please refer to fs_error_enum.
 *****************************************************************************/
extern int FS_GetFirstCluster(FS_HANDLE FileHandle, UINT * Cluster);

/*****************************************************************************
 * <GROUP  VolumeManagement>
 *
 * FUNCTION
 *  FS_CreateBootSector
 * DESCRIPTION
 *  Create a valid boot sector for a logical drive.
 * PARAMETERS
 *  BootSector           : [OUT] <P>Must point to a buffer of at least 512 bytes. It will receive the boot sector data.
 *  Partition            : [IN]  <P>Must point to a partition record describing the partition for which the boot sector is intended. If the boot record is to be written to a hard disk, this data must be identical to the respective partition record in the partition table.
 *  MediaDescriptor      : [IN]  <P>It's the value to be written into the BIOS parameter block. FS never uses this value, but other operating systems may require it to mount a volume. MediaDescriptors usually supplied by the device driver.
 *  MinSectorsPerCluster : [IN]  <P>Specifies the minimum number of sectors per cluster.
 *  Flags                : [IN]  <P>Controls additional properties of the file system to set up. Please refer to the documentation of function FS_Format for details about parameters MinSectorsPerCluster and Flags.
 * RETURNS
 *  If the function succeeds, it returns the first data sector number (if flag has FS_FMT_GET_DATA_SECTOR) or the FAT type. If it fails, the return value is a negative error code.
 * NOTE
 * (1)  Path name should be exactly the same as one in QuotaSet.
 * (2)  To save more resource, we use ：BYTE； (unsigned char) instead of FS traditional WCHAR here.
 *****************************************************************************/
extern int FS_CreateBootSector(void * BootSector, const FS_PartitionRecord * Partition, BYTE MediaDescriptor, UINT MinSectorsPerCluster, UINT Flags);

/*****************************************************************************
 * <GROUP  VolumeManagement>
 *
 * FUNCTION
 *  FS_GetPartitionInfo
 * DESCRIPTION
 *  Return information about a partition or physical disk.
 * PARAMETERS
 *  DriveName       : [IN]  <P>Must be a valid file name (for example, a root directory named "C:\"), a logical drive name ("\\.\C:"), or a physical disk name ("\\.\PHYSICALDRIVE0"). If the name refers to a physical disk file, the returned partition information applies to the whole disk, not just a single logical drive.
 *  PartitionInfo   : [OUT] <P>Please refer to FS_PartitionRecord.
 * RETURNS
 *  If the function succeeds, the return value is FS_NO_ERROR and the structure is filled as described below. If the function fails, the return value is a negative error code.
 *  <xtable>
 *       Value         	            Meaning
 *  -----------------	-------------------------------------------------------
 *  Partition        	This field contains a physical copy of the partition record read from the partition table to mount this partition. For floppy disks and physical disks, FS will create a fake partition record describing the whole disk.
 *  PartitionSector  	The physical sector number of the hosting device containing the partition table containing the above partition record. This value will be 0 for all primary partitions.
 *  PhysicalDiskIndex	The index of the physical disk device hosting this partition, or -1 for a floppy disk. The first hard disk in the system has index 0.
 *  BytesPerSector   	The sector size of the disk.
 *  MediaDescriptor  	The media byte of the hosting device. This value will be F8h for hard disks and some other value read from the boot sector for floppies. If this value is 0, FS was unable to determine the media descriptor. This situation can occur when the boot sector of a floppy disk is unreadable.
 *  DeviceListIndex  	The zero-based index of the device hosting the partition in FS's device list.
 *  </xtable>
 * NOTE
 *  Please note that actual values must be calculated as follows:
 *  ActualStartSector      = StartSector & 63;
 *  ActualStartTrack       = StartTrack | ((StartSector & 0xC0) << 2);
 *  ActualEndSector        = EndSector & 63;
 *  ActualEndTrack         = EndTrack | ((EndSector & 0xC0) << 2);
 *  For large hard disks, the EndTrack value may be incorrect, because it is limited to 1024 cylinders. If you need to calculate the size of a disk or partition, rely on field Sectors.
 *****************************************************************************/
extern int FS_GetPartitionInfo(const WCHAR * DriveName, FS_PartitionRecord * PartitionInfo);

/*****************************************************************************
 * <GROUP  VolumeManagement>
 *
 * FUNCTION
 *  FS_MappingDrive
 * DESCRIPTION
 *  This function can map one drive to another drive name. The first user, FS_SanityCheck
 *  in system booting up, will call FS_GetDrive to get the system drive name and map it
 *  to another fixed drive in all project. <color red>Here we decided to map it to ．Z・ drive in
 *  all projects.<color>
 * PARAMETERS
 *  UpperOldDrv : [IN] <P>Capital system drive name you get
 *  UpperNewDrv : [IN] <P>Capital fixed drive name you want
 * RETURN VALUES
 *  FS_PARAM_ERROR (-2):
 *          Drive number over range.
 *          For an example: if this project has 6 drive,
 *          UpperOldDrv should be 67~70, UpperNewDrv should be 71~90 (not include 88)
 *  FS_ACCESS_DENIED (-16):
 *          Call this function without initialize file system
 *          One should call function, FS_GetDrive, to get system drive number (UpperOldDrv) first.
 *          The function will help you to initialize file system if it has not been initiated yet.
 * NOTE
 *  (1) This function now only supports one mapping. If you map it to another drive again, the former configuration will be reset.
 *  (2) Drive ．X・ is reserved in file system. You should not map system drive to ．X・.
 *  (3) If you map system drive, say ．D・ drive, to ．Z・ drive. Then you can access system drive either via ．D・ or ．Z・ later.
 *****************************************************************************/
extern int FS_MappingDrive(UINT UpperOldDrv, UINT UpperNewDrv);

/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  FS_SetDiskFlag
 * DESCRIPTION
 *  Create a flag file in system drive for sanity check indication. If the system shutdown normally, FS_ClearDiskFlag should be called to delete the file. If the file exists when system boot up, sanity check will be triggered.
 * PARAMETERS
 *  N/A
 * RETURNS
 *  Refer to fs_error_enum. If the function succeeds, the return value is FS_NO_ERROR. If the function fails, the return value is a negative error code.
 *****************************************************************************/
extern int FS_SetDiskFlag(void);

/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  FS_ClearDiskFlag
 * DESCRIPTION
 *  Delete the flag file in system drive.
 * PARAMETERS
 *  N/A
 * RETURNS
 *  If the function succeeds, the return value is FS_NO_ERROR. If the function fails, the return value is a negative error code.
 *****************************************************************************/
extern int FS_ClearDiskFlag(void);

/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  FS_CreateMasterBootRecord
 * DESCRIPTION
 *  Create a valid master boot record with a partition table for a hard disk.
 * PARAMETERS
 *  SectorBuffer: [OUT] <P>Must point to a buffer of at least 512 bytes size. It will receive the new master boot record.
 *  DiskGeometry: [OUT] <P>It's a pointer to a partition record describing the complete hard disk. This information will usually supplied by a device driver.
 * RETURNS
 * If the function succeeds, the return value is FS_NO_ERROR.
 * If the function fails, the return value is a negative error code.
 *  FS_CreateMasterBootRecord fills the supplied buffer with a master boot loader and a partition table containing exactly one primary active partition spanning the complete disk.
 *  Please refer to FS_GetPartitionInfo for more information about structure FS_PartitionRecord.
 *****************************************************************************/
extern int FS_CreateMasterBootRecord(void * SectorBuffer, const FS_PartitionRecord * DiskGeometry);

/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  FS_SplitPartition
 * DESCRIPTION
 *  Split the last partition in a partition table into two partitions.
 * PARAMETERS
 *  MasterBootRecord : [OUT] <P>Must point to a buffer of at least 512 bytes size containing a valid master boot record with a partition table.
 *  Sectors          : [IN]  <P>Specifies how many sectors to allocate to the currently last partition. It must be less than the number of sectors it currently has. All remaining sectors are then allocated to a new partition.
 * RETURNS
 *  If the function succeeds, the return value is a zero-based index of the created partition (a value between 1 and 3). If the function fails, the return value is a negative  error code.
 *  Parameter Sectors is rounded down to a multiple of a cylinder, so the actual number of sectors can be less than the specified value.
 *****************************************************************************/
extern int FS_SplitPartition(void * MasterBootRecord, UINT Sectors);

/*****************************************************************************
 * <GROUP  LifeCycle>
 *
 * FUNCTION
 *  FS_ShutDown
 * DESCRIPTION
 *  This function will un-mount all devices and calls disk drivers to shutdown all the disks. This API is limited used by system process.
 * RETURNS
 *  N/A
 *****************************************************************************/
extern void FS_ShutDown(void);

/*****************************************************************************
 * <GROUP  LifeCycle>
 *
 * FUNCTION
 *  FS_UnlockAll
 * DESCRIPTION
 *  Unlock all devices and files. This API is limited to be used in system error handling processing.
 * RETURNS
 *  Return the number of devices that have been unlocked.
 *  Refer to fs_error_enum.
 * Note
 *  This function should only be called by the system.
 *****************************************************************************/
extern int FS_UnlockAll(void);

/*****************************************************************************
 * <GROUP  LifeCycle>
 *
 * FUNCTION
 *  FS_LockFAT
 * DESCRIPTION
 *  This function provides interface to switch global state in whole file system
 *  to work well under specific system mode. USB Boot Mode, Low Cost Single Bank
 *  Mode and Mass Storage Mode require File System to lock or limit application
 *  access.
 * PARAMETERS
 *  Type : [IN] <P>New File System State. Refer to FS_LOCK_TYPE_ENUM.
 * RETURNS
 *  Refer to fs_error_enum.
 *****************************************************************************/
extern int FS_LockFAT(UINT Type);

/*************************************************************************
 * <GROUP  DirectIOCtrl>
 *
 * FUNCTION
 *  FS_OTPWrite
 * DESCRIPTION
 *  Some flash devices provide OTP (One-Time Program) zone. This API is a
 *  driver wrapper function for application to support multiple device
 *  drivers and prevent re-entrance problem on the same device driver.
 *  Applications can read the specific content segment from OTP zone by
 *  this API.
 *  First it enters secured silicon sector, and write data from "Offset",
 *  totally write "Length" bytes, then exit secured silicon sector mode.
 *  <color red>Be careful</color>, do not set bit to one if it is zero
 * PARAMETERS
 *  devtype     : [IN] <P>FS_DEVICE_TYPE_NOR or FS_DEVICE_TYPE_NAND can be assigned.
 *  Offset      : [IN] <P>The start position to read from (unit: bytes).
 *  BufferPtr   : [IN] <P>The buffer address to keep copied data
 *  Length      : [IN] <P>Specific total length of this read operation (unit: bytes)
 * RETURN VALUES
 *  FS_NO_ERROR : success
 *  FS_UNSUPPORTED_DEVICE (-11): no such OTP device configured
 *  FS_UNSUPPORTED_DRIVER_FUNCTION (-12): no OTP function supported on configured device
 *  FS_FLASH_OTP_OVERSCOPE (-124): writing range is out of OTP range
 *  FS_FLASH_OTP_LOCK_ALREADY (-127): the OTP zone already locked.
 *************************************************************************/
extern int FS_OTPWrite(int devtype, UINT Offset, void * BufferPtr, kal_uint32 Length);

/*************************************************************************
 * <GROUP  DirectIOCtrl>
 *
 * FUNCTION
 *  FS_OTPRead
 * DESCRIPTION
 *  Some flash devices provide OTP (One-Time Program) zone. This API is a
 *  driver wrapper function for application to support multiple device
 *  drivers and prevent re-entrance problem on the same device driver.
 *  Applications can read the specific content segment from OTP zone by
 *  this API.
 *  first it enters secured silicon sector, and read data from "Offset",
 *  totally read "Length" bytes, then exit secured silicon sector mode
 * PARAMETERS
 *  devtype     : [IN] <P>FS_DEVICE_TYPE_NOR or FS_DEVICE_TYPE_NAND can be assigned.
 *  Offset      : [IN] <P>The start position to read from (unit: bytes).
 *  BufferPtr   : [IN] <P>The buffer address to keep copied data
 *  Length      : [IN] <P>Specific total length of this read operation (unit: bytes)
 * RETURN VALUES
 *  FS_NO_ERROR : success
 *  FS_UNSUPPORTED_DEVICE (-11): no such OTP device configured
 *  FS_UNSUPPORTED_DRIVER_FUNCTION (-12): no OTP function supported on configured device
 *  FS_FLASH_OTP_OVERSCOPE (-124): reading range is out of OTP range
 *************************************************************************/
extern int FS_OTPRead(int devtype, UINT Offset, void * BufferPtr, kal_uint32 Length);

/*************************************************************************
 * <GROUP  DirectIOCtrl>
 *
 * FUNCTION
 *  FS_OTPQueryLength
 * DESCRIPTION
 *  This function implements the OTP length query function.
 * PARAMETERS
 *  devtype     : [IN] <P>FS_DEVICE_TYPE_NOR or FS_DEVICE_TYPE_NAND can be assigned.
 *  Offset      : [IN] <P>The start position to read from (unit: bytes).
 * RETURN VALUES
 *  FS_NO_ERROR: no error
 *  FS_UNSUPPORTED_DEVICE: no OTP device configured
 *  FS_UNSUPPORTED_DRIVER_FUNCTION: no OTP function support on configured device
 *************************************************************************/
extern int FS_OTPQueryLength(int devtype, UINT *Length);

/*************************************************************************
 * <GROUP  DirectIOCtrl>
 *
 * FUNCTION
 *  FS_OTPLock
 * DESCRIPTION
 *  Some flash devices provide OTP (One-Time Program) zone. This API is a
 *  driver wrapper function for application to permanently lock OTP zone.
 *  <color red><b>WARNING!!</b></color> If this API is executed, OTP zone can't be written again.
 * PARAMETERS
 *  devtype     : [IN] <P>FS_DEVICE_TYPE_NOR or FS_DEVICE_TYPE_NAND can be assigned.
 * RETURN VALUES
 *  FS_NO_ERROR : success
 *  FS_UNSUPPORTED_DEVICE (-11): no such OTP device configured
 *  FS_UNSUPPORTED_DRIVER_FUNCTION (-12): no OTP function supported on configured device
 *  FS_FLASH_OTP_LOCK_ALREADY (-127): the OTP zone already locked.
 *************************************************************************/
extern int FS_OTPLock(int devtype);

/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  FS_SweepDevice
 * DESCRIPTION
 *  File system provides this API to sweep out all unused data sectors.
 *  This API is designed to be called by background and low priority task.
 *  So API cannot hold the device lock too long to degrade system throughput.
 *  Note that it will return FS_CHECKDISK_RETRY(-41) to indicate caller to try
 *  again until FS_NO_ERROR return.
 * PARAMETERS
 *  devtype     : [IN] <P>FS_DEVICE_TYPE_NOR or FS_DEVICE_TYPE_NAND can be assigned.
 * RETURN VALUES
 *  FS_NO_ERROR : success and finished
 *  FS_PARAM_ERROR (-2): No such device configured
 *  FS_CHECKDISK_RETRY (-41): please retry again until FS_NO_ERROR return.
 *****************************************************************************/
extern int FS_SweepDevice(const int devtype);

extern int FS_OpenLR(const WCHAR * FileName, kal_uint32 Flag, kal_uint32 caller_address);
extern int FS_OpenHintLR(const WCHAR * FileName, kal_uint32 Flag, FS_FileOpenHint * DSR_Hint, kal_uint32 caller_address);
extern int FS_MoveLR(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, kal_uint32 Flag, FS_ProgressCallback Progress,
            kal_uint8 *RecursiveStack, const kal_uint32 StackSize, kal_uint32 caller_address);

extern FS_TaskIOStatistics *gFS_TaskIOStatistics;

/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  SDCreateMasterBootRecord
 * DESCRIPTION
 *  Create SDHC Master Boot Record, follow SDHC file system spec. V3
 * PARAMETERS
 *  MasterBootRecord :[OUT] <P> Master Boot Record sector buffer
 *  Sectors          :[IN]  <P> Number of sectors on the device
 * RETURN VALUES
 *   0: Error
 *  >0: Success, the offset to the partition starting sector (Boot Sector).
 *****************************************************************************/
extern int SDCreateMasterBootRecord(void * MasterBootRecord, kal_uint32 Sectors);

/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  SDCreateBootSector
 * DESCRIPTION
 *  Create SDHC Boot Sector, follow SDHC file system spec. V3
 * PARAMETERS
 *  BootSector :[OUT] <P> Boot sector buffer
 *  Sectors    :[IN]  <P> Number of sectors on the device
 *  Partition  :[IN]  <P> First partition record created from SDCreateMasterBootRecord()
 * RETURN VALUES
 *   0: Error
 *  12: Created File System Type is FAT12
 *  16: Created File System Type is FAT16
 *  32: Created File System Type is FAT32
 *****************************************************************************/
extern int SDCreateBootSector(void * BootSector, kal_uint32 Sectors, FS_PartitionRecord *Partition);

/*****************************************************************************
 * <GROUP  DiskManagement>
 *
 * FUNCTION
 *  SDCheckFormatParameter
 * DESCRIPTION
 *  Compare SDHC format parameters, including BootSector(BS) and MasterBootRecord(MBR)
 * PARAMETERS
 *  MBR1 :[IN] <P> Master Boot Record 1 (Read from Device)
 *  MBR2 :[IN] <P> Master Boot Record 2 (Created from SDCreateMasterBootRecord)
 *  BS1  :[IN] <P> Boot Sector 1 (Read from Device)
 *  BS2  :[IN] <P> Boot Sector 2 (Created from SDCreateBootSector)
 * RETURN VALUES
 *  FS_SD_FMT_OK : (0): Format parameters are match.
 *  FS_SD_FMT_SIGNATURE_FAIL (1): BS or MBR Signature are mismatch.
 *  FS_SD_FMT_MBR_FAIL       (2): MBR1/MBR2 parameters are mismatch.
 *  FS_SD_FMT_BS_FAIL        (3): BS1/BS2 parameters are mismatch.
 *****************************************************************************/
extern int SDCheckFormatParameter(void *MBR1, void *BS1, void *MBR2, void *BS2);

#else

// Smart Phone Modem Wrapper
//------------------------------------------------------------
/* DOM-NOT_FOR_SDK-BEGIN */

/* DOM-NOT_FOR_SDK-END */

#endif

#endif // _FS_IPROT_H

