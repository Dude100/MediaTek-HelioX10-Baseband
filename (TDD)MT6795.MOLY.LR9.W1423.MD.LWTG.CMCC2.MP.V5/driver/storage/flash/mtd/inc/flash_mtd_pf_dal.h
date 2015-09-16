/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *
 * Filename:
 * ---------
 *	flash_mtd_pf_dal.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is a flash MTD driver header file (for Combo Memory)
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/
 
 #ifndef __FLASH_MTD_PF_DAL_H__
#define __FLASH_MTD_PF_DAL_H__

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "DrvFlash.h"
#include "fs_type.h"
#include "flash_mtd.h"

// [Combo Memory] ESB status (Flash_ReturnReady, waitReady)

#if defined(__COMBO_MEMORY_SUPPORT__)

typedef kal_uint16 FLASH_CELL; //sync with flash_mtd.h

typedef enum {
    PF_SR_READY  = 0
    ,PF_SR_COUNT
} PF_Status_Enum;


typedef enum {
    PF_AMD_SR_READY  = 0x40 //DQ6, toggle busy
} PF_AMD_Status_Indication_Enum;

//WVSR use the INTEL status indication
typedef enum {
    PF_INTEL_SR_READY  = 0x80 
} PF_INTEL_Status_Indication_Enum;

typedef unsigned char   PF_Status;


//-------------------------------------------------------
//Data or Functional pointer which is device dependent and do not explore to outside user (MTD use internal only)
typedef struct
{
	void (*CMD_EraseBlock)(volatile FLASH_CELL* fp);
	void (*CMD_UnlockBlock)(volatile FLASH_CELL* fp);
	FLASH_CELL (*CMD_ReadStatus)(volatile FLASH_CELL* fp);
    kal_uint8 Suspend;
    kal_uint8 Resume;
	kal_bool DYB_Lock; //set DYB_Lock to KAL_TRUE if need to unlock/lock block before/afer progra or erase

}PF_MTD_CMD;


//SuspendLatency: Duration during Suspend command and Polling status
//ResumeInterval: Duration during Suspend command and next Resume command
typedef struct {
//========== First Part ===========
   kal_uint32  Signature;
   BYTE * BaseAddr;
   kal_semid          DeviceLock;       // The device lock that keeps driver resource consistent
   kal_taskid         DeviceLockOwner;  // The owner of the deivce lock
   kal_int8           DeviceLockDepth;  // The depth of the deivce lock

//========== First Part ===========
   FlashRegionInfo * RegionInfo;
   BYTE * CurrAddr;
   FlashBankInfo *BankInfo;
   BYTE * CurrBankAddr;
   kal_uint32 CurrBankSize;
   BYTE * CurrPollAddr;
#ifndef __MTK_TARGET__
   const char        *FileName;
   void              *flash_device;
   BYTE              *rootMTDcache;
   BYTE              *MTDcache;
   kal_uint32             first;
   kal_uint32             last_WinAddr;
   kal_uint32             last_region;
#endif
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_AddrLookup  lookup_tbl[LOOKUP_TABLE_SIZE][2];
#endif

//========== Parallel NOR Flash ===========
   kal_uint8              SuspendLatency;
   kal_uint8              ResumeInterval;
   PF_MTD_CMD            *CMD;
   PF_Status            *StatusMap;
} PF_MTD_Data;



//-----------------------------------------------------------------------------
// [DAL] Init functions
//-----------------------------------------------------------------------------
kal_int32 ADMUX_DAL_Init_Driver(NOR_MTD_Driver *driver, PF_MTD_Data *data, kal_uint32 baseaddr, kal_uint32 type);


//located in flash_mtd.intel.c
kal_int32 ADMUX_DAL_Init_INTEL(NOR_MTD_Driver *driver, PF_MTD_Data *data);
kal_int32 ADMUX_DAL_Init_INTEL_SIBLEY(NOR_MTD_Driver *driver, PF_MTD_Data *data);

//located in flash_mtd.amd.c
kal_int32 ADMUX_DAL_Init_AMD(NOR_MTD_Driver *driver, PF_MTD_Data *data);
kal_int32 ADMUX_DAL_Init_WVSR(NOR_MTD_Driver *driver, PF_MTD_Data *data);
kal_int32 ADMUX_DAL_Init_TOSHIBA(NOR_MTD_Driver *driver, PF_MTD_Data *data);


//-----------------------------------------------------------------------------
// [DAL] MTD Interfaces
//-----------------------------------------------------------------------------

int PF_DAL_MountDevice(void * DriveData, void *Info);
int PF_DAL_ShutDown(void * DriveData);

int PF_DAL_SuspendErase(void * DriveData, kal_uint32 BlockIndex);
int PF_DAL_ResumeErase(void * DriveData, kal_uint32 BlockIndex);


//-------------------------------------------------------
// System Context Switch Service Routines
//-------------------------------------------------------
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
void Flash_ReturnReady(void);
#endif


//-----------------------------------------------------------------------------
// [DAL] MTD Internal Functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [DAL] Lock functions
//-----------------------------------------------------------------------------
void PF_DAL_Dev_UnlockBlock_Spansion_NS_J(volatile FLASH_CELL * fp);
void PF_DAL_Dev_UnlockBlock_Samsung_Spansion_NS_J_Like(volatile FLASH_CELL * fp);
void PF_DAL_Dev_UnlockBlock_INTEL(volatile FLASH_CELL * fp);
void PF_DAL_Dev_Dummy(volatile FLASH_CELL * fp);

//-----------------------------------------------------------------------------
// [DAL] ReadStatus functions
//-----------------------------------------------------------------------------
FLASH_CELL PF_DAL_Dev_ReadStatus_INTEL(volatile FLASH_CELL *fp);
FLASH_CELL PF_DAL_Dev_ReadStatus_WVSR(volatile FLASH_CELL *fp);
FLASH_CELL PF_DAL_Dev_ReadStatus_AMD(volatile FLASH_CELL *fp);



#endif //__COMBO_MEMORY_SUPPORT__
#endif  // #ifndef __FLASH_MTD_PF_H__

