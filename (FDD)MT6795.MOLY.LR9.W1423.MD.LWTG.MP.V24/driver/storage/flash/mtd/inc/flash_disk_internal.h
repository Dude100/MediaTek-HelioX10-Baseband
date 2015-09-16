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

#ifndef __FLASH_DISK_INTERNAL_H__
#define __FLASH_DISK_INTERNAL_H__

#if defined __MTK_TARGET__
#if !defined(_NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__)

/*******************************************
*   Include File      
********************************************/

#include "flash_disk.h"
#include "custom_MemoryDevice.h"
#include "flash_opt.h"
#include "flash_mtd.h"
#include "reg_base.h"
#include <stdio.h>
#include <stdlib.h>
#include "DrvFlash.h"
#include "fs_gprot.h"

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#include "intrCtrl.h"
#include "drv_comm.h"
#endif /*__SINGLE_BANK_NOR_FLASH_SUPPORT__*/

#ifdef __INTEL_SIBLEY__
//MSBB remove #include "app_buff_alloc.h" //get control buffer
#endif //__INTEL_SIBLEY__


/*******************************************
*   Structure and Macro Definition      
********************************************/
#define RAW_DISK0 0
#define RAW_DISK1 1


#ifdef __SYSDRV_BACKUP_DISK_RAW__

#define BACKUP_HEADER 6
#define INIT_MARK  0x1234
#define LOCK_MARK  0x4321

#ifdef __INTEL_SIBLEY__
#define SIBLEY_REGION_SIZE 1024
#endif //__INTEL_SIBLEY__

#endif //__SYSDRV_BACKUP_DISK_RAW__


// Flash raw disk driver's data
typedef __fs_packed_prefix struct {
   kal_uint32   DiskSize;        
   NOR_MTD_Driver *MTDDriver;       ///< MTD driver
   void    *MTDData;                ///< MTD data
   NOR_MTD_FlashInfo FlashInfo;     ///< Flash information
#if defined (__INTEL_SIBLEY__) && defined(__SYSDRV_BACKUP_DISK_RAW__)
   kal_uint32    bufIdx;   
   BYTE    *Buffer;                 ///< SIBLEY Backup Partition Buffer(1024 bytes): used as write buffer and write data in control mode
#endif
   kal_bool is_mount;
}__fs_packed_postfix NOR_FLASH_DISK_Data;

/*******************************************
*   Function and Variable Definition      
********************************************/
#ifdef __NOR_SUPPORT_RAW_DISK__
extern NOR_FLASH_DISK_Data FlashDiskDriveData[NOR_BOOTING_NOR_DISK_NUM];
#endif 

extern kal_bool         INT_QueryExceptionStatus(void);
extern kal_uint32       BlockIndex(void* DriverData, kal_uint32 blk_addr);
extern kal_mutexid      fdm_reclaim_mutex;

/* Raw disk API */
kal_int32 readRawDiskData(NOR_FLASH_DISK_Data *D, kal_uint32 addr, kal_uint8* data_ptr, kal_uint32 len);
#if defined(__NOR_SUPPORT_RAW_DISK__) || defined(__NOR_FULL_DRIVER__)
kal_int32 writeRawDiskData(NOR_FLASH_DISK_Data *D, kal_uint32 addr, kal_uint8* data_ptr, kal_uint32 len);
kal_int32 eraseRawDiskBlock(NOR_FLASH_DISK_Data *D, kal_uint32 block_baseaddr);
#endif //__NOR_SUPPORT_RAW_DISK__ || __NOR_FULL_DRIVER__


#endif // !_NAND_FLASH_BOOTING__ && !__EMMC_BOOTING__
#endif //__MTK_TARGET__
#endif //__FLASH_DISK_H__
