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
 *   info.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides APIs to get device information 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "string.h"
#include "custom_MemoryDevice.h"
#include "flash_opt.h"
#include "fs_gprot.h"
#include "emi_sw.h"
#include "info.h"
#include "flash_cfi.h"

#if defined(__MTK_TARGET__) && !defined(__SMART_PHONE_MODEM__) && !defined(__RAMDISK__)
static WCHAR GetFirstDriveNamebyDeviceType(int Type)
{
   WCHAR driveName = L'C';

   for (; driveName <= L'Z'; driveName++)
   {
      if (Type == FS_GetDevType(&driveName))
         return driveName;
   }

   return 0xFFFF;
}
#endif

void INT_GetMemDevInfo(MEM_DEV_INFO_T* Info)
{
#if defined(__MTK_TARGET__) && !defined(__SMART_PHONE_MODEM__) && !defined(__RAMDISK__)	
   WCHAR driveName;
#endif   

   memset(Info, 0, sizeof(MEM_DEV_INFO_T));

#if defined(__MTK_TARGET__) && !defined(__SMART_PHONE_MODEM__) && !defined(__RAMDISK__)

   if (FS_GetDevStatus(FS_DEVICE_TYPE_NOR, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
      Info->NORPresent = KAL_TRUE;
   else
   	  Info->NORPresent = KAL_FALSE;

   if (FS_GetDevStatus(FS_DEVICE_TYPE_NAND, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
      Info->NANDPresent = KAL_TRUE;
   else
   	  Info->NANDPresent = KAL_FALSE;

   EMI_QueryCurSetting(&(Info->EMIInfo));

   if (Info->NANDPresent == KAL_TRUE)
   {
      driveName = GetFirstDriveNamebyDeviceType(FS_DEVICE_TYPE_NAND);

      if (driveName != 0xFFFF)
      {
         FS_IOCtrl(&driveName, FS_IOCTRL_QUERY_NAND_INFO, &(Info->NANDDevInfo));
      }

      #if defined(__EMMC_BOOTING__)
      Info->NANDConfInfo.FSBaseAddress    = EMMC_BOOTING_CODE_PARTITION_SIZE;
      Info->NANDConfInfo.FSTotalSize      = 0;
      Info->NANDConfInfo.FSFirstDriveSize = 0;
      #elif defined(_NAND_FLASH_BOOTING_) || defined(__FS_SYSDRV_ON_NAND__) || (defined(__FOTA_DM__) && defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))
      Info->NANDConfInfo.FSBaseAddress    = NAND_FLASH_BASE_ADDRESS;
      Info->NANDConfInfo.FSTotalSize      = NAND_ALLOCATED_FAT_SPACE;
      Info->NANDConfInfo.FSFirstDriveSize = NAND_PARTITION_SECTORS;
      #elif defined(NAND_SUPPORT)  // NOR booting without (__FOTA_DM__ && __UP_PKG_ON_NAND__) but NAND_SUPPORT is enabled, the whole NAND flash is treated as a public drive.
      Info->NANDConfInfo.FSBaseAddress    = 0;
      Info->NANDConfInfo.FSTotalSize      = Info->NANDDevInfo.DeviceInfo.NAND.DeviceSize * 1024 * 1024; // translate to MB
      Info->NANDConfInfo.FSFirstDriveSize = 0;
      #endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ || __FS_SYSDRV_ON_NAND__ && (__FOTA_DM__ && __UP_PKG_ON_NAND__ && NAND_SUPPORT) */

      #if defined(__NAND_FDM_50__)
      Info->NANDFDMVer = 5;
      #else
      Info->NANDFDMVer = 4;
      #endif /* __NOR_FDM5__ */

   }

   if (Info->NORPresent == KAL_TRUE)
   {
      driveName = GetFirstDriveNamebyDeviceType(FS_DEVICE_TYPE_NOR);

      if (driveName != 0xFFFF)
      {
         FS_IOCtrl(&driveName, FS_IOCTRL_QUERY_NOR_INFO, &(Info->NORDevInfo));
      }

      #if !defined(_NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__) && !defined(__FS_SYSDRV_ON_NAND__)
      Info->NORConfInfo.FSBaseAddress     = NOR_FLASH_BASE_ADDRESS;
      Info->NORConfInfo.FSTotalSize       = NOR_ALLOCATED_FAT_SPACE;
      Info->NORConfInfo.FSFirstDriveSize  = NOR_PARTITION_SECTORS;
      #endif /* !_NAND_FLASH_BOOTING_ && !__EMMC_BOOTING__ && !__FS_SYSDRV_ON_NAND__ */

      #if defined(__NOR_FDM5__)
      Info->NORFDMVer = 5;
      #else
      Info->NORFDMVer = 4;
      #endif /* __NOR_FDM5__ */

   }

#endif /* __MTK_TARGET__ && !__SMART_PHONE_MODEM__ */

}

