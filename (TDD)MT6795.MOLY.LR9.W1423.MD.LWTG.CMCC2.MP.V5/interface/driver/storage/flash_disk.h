/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   flash_disk.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This is the header of NOR Flash raw disk code
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 ****************************************************************************/

#ifndef __FLASH_DISK_H__
#define __FLASH_DISK_H__

#if defined __MTK_TARGET__
#if !defined(_NAND_FLASH_BOOTING_)  && !defined(__NOR_FDM5__)

/*******************************************
*   Include File      
********************************************/

#include "custom_MemoryDevice.h"
#include "flash_opt.h"
#include "flash_mtd.h"
#include "reg_base.h"
#include <stdio.h>
#include <stdlib.h>
#include "DrvFlash.h"

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#include "intrCtrl.h"
#include "drv_comm.h"
#endif /*__SINGLE_BANK_NOR_FLASH_SUPPORT__*/

#ifdef __INTEL_SIBLEY__
//MSBB remove #include "app_buff_alloc.h" //get control buffer
#endif //__INTEL_SIBLEY__

/*******************************************
*   Error Code Definition
********************************************/

#define RAW_DISK_ERR_NONE 0
#define RAW_DISK_ERR_WRONG_ADDRESS 2
#define RAW_DISK_ERR_NO_SPACE  3

#ifdef __SYSDRV_BACKUP_DISK_RAW__
#define RAW_DISK_ERR_LOCKED 1  //only for backup partition
#define RAW_DISK_ERR_NO_INIT 4  //only for backup partition
#endif //__SYSDRV_BACKUP_DISK_RAW__

#define RAW_DISK_ERR_PROG_FAIL 5
#define RAW_DISK_ERR_ERASE_FAIL 6

#define ERROR_NOR_SUCCESS             	(0)   //(ERROR_FOTA_SUCCESS)
#define ERROR_NOR_READ                	(-13) //(ERROR_FOTA_READ)
#define ERROR_NOR_PROGRAM             	(-14) //(ERROR_FOTA_PROGRAM)
#define ERROR_NOR_ERASE               	(-15) //(ERROR_FOTA_ERASE)
#define ERROR_NOR_OVERRANGE             (-1)  //(ERROR_FOTA_OVERRANGE)

/*******************************************
*   Structure and Macro Definition      
********************************************/

#define FLASH_DISK_DONE FS_NO_ERROR

#ifdef __SERIAL_FLASH_EN__
#define NOR_FLASH_PAGE_SIZE 0x200 //default 512B page
#define NOR_FLASH_PAGE_SHIFT 9
#else
#define NOR_FLASH_PAGE_SIZE 0x800 //default 2KB page
#define NOR_FLASH_PAGE_SHIFT 11
#endif

#ifdef __SYSDRV_BACKUP_DISK_RAW__

#define BACKUP_DISK_STATUS_INIT 0
#define BACKUP_DISK_STATUS_EMPTY 1
#define BACKUP_DISK_STATUS_LOCK 2

#endif //__SYSDRV_BACKUP_DISK_RAW__

/*******************************************
*   Function and Variable Definition      
********************************************/

/* TC01 security partition API */
#ifdef __CUSTOMER_TC01_DISK__
#define TC01_DISK RAW_DISK1
#define TC01_DISK_BLOCK_SIZE 0x4000
#define TC01_DISK_PAGE_SIZE 0x800 //default 2KB page
#define TC01_DISK_PAGE_SHIFT 11
kal_int32 EraseRawDataItem(kal_uint32 block_idx);
kal_int32 ReadRawDataItem(kal_uint32 block_idx, kal_uint32 page_idx, kal_uint32 length, kal_uint8* data_ptr);
kal_int32 WriteRawDataItem(kal_uint32 block_idx, kal_uint32 page_idx, kal_uint32 length, kal_uint8* data_ptr);
#endif //__CUSTOMER_TC01_DISK__

/* Backup partition API*/
#ifdef __SYSDRV_BACKUP_DISK_RAW__
void initBackupPartition(void);
kal_int32 readBackupPartition(kal_uint16 ID, kal_uint8* data_ptr, kal_uint32 len );
kal_int32 writeBackupPartition(kal_uint16 ID, kal_uint8* data_ptr, kal_uint32 len);
void lockBackupPartition(void);
kal_int32 getBackupPartitionStatus(void);
#endif //__SYSDRV_BACKUP_DISK_RAW__

/* NOR driver API for Secure Storage(in MAUI) */

kal_int32 NOR_init (void);
//kal_int32 NOR_QueryInfo (Logical_Flash_info info);
kal_int32 NOR_ReadPhysicalPage (kal_uint32 block_idx, kal_uint32 page_idx, kal_uint8 * data_ptr);
#ifdef __NOR_FULL_DRIVER__
kal_int32 NOR_ProgramPhysicalPage (kal_uint32 block_idx, kal_uint32 page_idx, kal_uint8 * data_ptr);
kal_int32 NOR_ErasePhysicalBlock (kal_uint32 block_idx);
#endif //__NOR_FULL_DRIVER__
kal_uint32 NOR_BlockSize(kal_uint32 block_idx);
kal_uint32 NOR_BlockIndex(kal_uint32 block_addr);
kal_int32 NOR_Addr2BlockIndexOffset(kal_uint32 block_addr, kal_uint32 *block_index, kal_uint32 *offset);
kal_int32 NOR_BlockIndexOffset2Addr(kal_uint32 block_index, kal_uint32 offset, kal_uint32 *addr);

#endif // !_NAND_FLASH_BOOTING__ && !__NOR_FDM5__
#endif //__MTK_TARGET__
#endif //__FLASH_DISK_H__
