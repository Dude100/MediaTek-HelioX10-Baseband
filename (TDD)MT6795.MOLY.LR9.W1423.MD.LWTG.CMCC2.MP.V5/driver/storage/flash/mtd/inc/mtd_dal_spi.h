/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *    mtd_dal_spi.h
 *
 * Project:
 * --------
 *   TAKAKA
 *
 * Description:
 * ------------
 *   The MTD driver for spi flash controller
 *   This code is modified from MAUI flash_mtd_sf_dal.h
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
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/
//#include "flash_opt.h"

#ifndef __FLASH_MTD_SF_DAL_H__
#define __FLASH_MTD_SF_DAL_H__

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "devdrv_ls.h"
#include "DrvFlash.h"
#include "fs_type.h"
#include "flash_sf.h"
#include "drv_spi.h"

//-------------------------------------------------------
// IoCtrl enumeration
//-------------------------------------------------------
typedef enum
{
    SF_IOCTRL_UNLOCK_BLOCK,
    SF_IOCTRL_GET_PROGRAM_FAIL_HANDLE_TYPE
} SF_MTD_IOCtrl_Action_Enum;

typedef enum
{
    SFDRV_READY=0,
    SFDRV_PROGRAMMING,
    SFDRV_ERASING
} SF_Driver_Status;

//-------------------------------------------------------
// Driver Data - Device Command
//-------------------------------------------------------
typedef struct
{
    kal_uint8 PageProg;
    kal_uint8 WriteEnable;

    kal_uint8 Suspend;
    kal_uint8 Resume;
    kal_uint8 Read;

    kal_uint8 Erase;
    kal_uint8 Erase4K;
    kal_uint8 Erase32K;
    kal_uint8 Erase64K;

    kal_uint8 ReadID_SPI;
    kal_uint8 ReadID_QPI;

    kal_uint8 ReadBPReg;
    kal_uint8 WriteBPReg;
    kal_uint8 ReadSecurityReg;
    kal_uint8 WriteSecurityReg;
    kal_uint8 ReadSuspendReg;
    kal_uint8 ReadReadyReg;
    kal_uint8 ReadFailReg;

#ifdef __SECURITY_OTP__
    kal_uint8 OTPProg;
    kal_uint8 OTPEnter;
    kal_uint8 OTPExit;
    kal_uint8 OTPLock;
#endif
}SF_MTD_CMD;

//-----------------------------------------------------------------------
// Driver Data
// Note: The first part must be identical to
//       NOR_Flash_MTD_Data(FDM4.0), NOR_MTD_DATA(FDM5.0)
//       The second part must be identical to
//       NOR_Flash_MTD_Data(FDM4.0)
//-----------------------------------------------------------------------
typedef struct {
//========== First Part ===========
       kal_uint32         Signature;
       kal_uint8         *BaseAddr;
       kal_semid          DeviceLock;       // The device lock that keeps driver resource consistent
       kal_taskid         DeviceLockOwner;  // The owner of the deivce lock
       kal_int8           DeviceLockDepth;  // The depth of the deivce lock

//========== Second Part ===========
       FlashRegionInfo   *RegionInfo;
       kal_uint8         *CurrAddr;
       FlashBankInfo     *BankInfo;
       kal_uint8         *CurrBankAddr;
       kal_uint32         CurrBankSize;
       kal_uint8         *CurrPollAddr;

#ifndef __MTK_TARGET__
       const char        *FileName;
       void              *flash_device;
       kal_uint8         *rootMTDcache;
       kal_uint8         *MTDcache;
       kal_uint32         first;
       kal_uint32         last_WinAddr;
       kal_uint32         last_region;
#endif
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
       NOR_AddrLookup    lookup_tbl[LOOKUP_TABLE_SIZE][2];
#endif

//========== Serial Flash =========
       SF_Status             *StatusMap;
       SF_MTD_CMD            *CMD;
       kal_uint32             Flag;
       kal_uint16             BPRBitCount;

#ifdef __SECURITY_OTP__
       kal_uint16             OTPLength;
       kal_uint16             OTPBase;
#endif // __SECURITY_OTP__

       kal_uint8              SuspendLatency;
       kal_uint8              ResumeLatency;
       kal_uint8              FlashID[SF_FLASH_ID_LENGTH];
       kal_uint8              DriverStatus;

       int (*UnlockBlock)(void *MTDData);

#ifdef __SECURITY_OTP__
       int (*OTPLock)(void *MTDData);
       int (*OTPRead)(void *MTDData, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
       int (*OTPWrite)(void *MTDData, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
#endif // __SECURITY_OTP__
}SF_MTD_Data;

//-------------------------------------------------------
// Driver Abstract Layer Initialization Function
//-------------------------------------------------------
kal_int32 SF_DAL_Init_Driver(
    NOR_MTD_Driver *driver,    // Pointer to allocated driver interface
    SF_MTD_Data *data,         // Pointer to allocated driver data
    kal_uint32 baseaddr,       // Base address of FAT region
    kal_uint32 type            // Reserved
);

//-------------------------------------------------------
// Type Enumeration
//-------------------------------------------------------
// Note: This must match with JECDEC vendor id
typedef enum {
    SF_DAL_TYPE_NONE    = 0,
    SF_DAL_TYPE_SST     = 0xBF,
    SF_DAL_TYPE_MXIC    = 0xC2,
    SF_DAL_TYPE_EON     = 0x1C,
    SF_DAL_TYPE_WINBOND = 0xEF,
    SF_DAL_TYPE_FIDELIX = 0xF8,
    SF_DAL_TYPE_COUNT
} SF_DAL_Type;

//-------------------------------------------------------
// Sleep Mode Service Routines
//-------------------------------------------------------
void Flash_ProgramData(void *Target, void *Data, kal_uint32 Size);
kal_bool Flash_CheckReady(void);

//-------------------------------------------------------
// System Context Switch Service Routines
//-------------------------------------------------------
void Flash_ReturnReady(void);

#endif  // #ifndef __FLASH_MTD_SF_H__
