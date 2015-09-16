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
 *   sd_drv2.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Adaption driver of file system for SD card for MSDC_2
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
#ifndef DRV_MSDC_OFF
//RHR ADD
#include "kal_public_defs.h"
//#include "btif_sw.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
//RHR REMOVE
/*
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
//MSBB remove #include "kal_non_specific_general_types.h"
//MSBB remove #include "app_buff_alloc.h"
#include "fat_fs.h"
#if defined(__MSDC_MS__)
#include "ms_def.h"
#endif
#include "init.h"
*/
//RHR
#include "drv_comm.h"
#include "msdc_reg_adap.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "intrCtrl.h"
#include "cache_sw.h"    //doublelo add
#if defined(__MSDC2_SD_MMC__)

#define SECTOR_SIZE 512	
#define MSDC_MEDIA_DESCRIPTOR		0xF8
#define SD_MAX_RETRY	2
extern MSDC_HANDLE *msdc2_handle;
extern T_SDC_HANDLE	*gSD2;

static int  ReadSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
static int  WriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer);
static kal_uint32 sd_r,sd_w;

static int  DiscardSectors(void * DriveData, DWORD Sector, UINT Sectors)
{
   return FS_NO_ERROR;
}

static int  ReadSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer)
{
	
	SDC_CMD_STATUS status;
	kal_uint8 retry = 0;
	kal_uint32 adrs;
	MSDC_HANDLE *msdc = (MSDC_HANDLE *)DriveData ;
	
#ifdef MSDC_CACHED_SUPPORT
	/*tell buffer type each time this function called*/
	if (INT_QueryIsCachedRAM(Buffer, Sectors * SECTOR_SIZE)){
		msdc2_handle->isCachedBuf = KAL_TRUE;
	}
	else
		msdc2_handle->isCachedBuf = KAL_FALSE;
#endif
	
#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)	
	if(gSD2->flags & SD_FLAG_HCS_SUPPORT)
		adrs = Sector;
	else
#endif		
	adrs = Sector * SECTOR_SIZE;
	msdc2_handle->timeout_count = 0;
start:
	if(!msdc2_handle->mIsInitialized)
	{
		//dbg_print("Read but not Initialized \r\n");
		MSDC_PDNControl2(KAL_TRUE);
		return FS_MSDC_READ_SECTOR_ERROR;
	}
	retry ++;
	MSDC_PDNControl2(KAL_FALSE);
	if(Sectors > 1)
		status = SD_ReadMultiBlock_2((kal_uint32)adrs,(kal_uint32*)Buffer,(kal_uint32)Sectors);
	else
		status = SD_ReadSingleBlock_2((kal_uint32)adrs,(kal_uint32*)Buffer);
	if(status != NO_ERROR )
	{		
		sd_r++;
		if(kal_query_systemInit()== KAL_TRUE)
		{
			MSDC_PDNControl2(KAL_TRUE);
			return FS_MSDC_READ_SECTOR_ERROR;
		}		
		//dbg_print("read retry:%d,status:%d,total %d\r\n",retry,status,sd_r);
		if(status == ERR_CMD_TIMEOUT || status == MSDC_GPT_TIMEOUT_ERR)
			msdc2_handle->timeout_count++;
		if(msdc2_handle->timeout_count++ == 3 && msdc2_handle->mIsPresent == KAL_TRUE)
		{
			tst_sys_trace("[MSDC]:re-mount(read fail)");
			msdc2_handle->mIsInitialized = KAL_FALSE;
			retry = 0;
			if(SD_Initialize_2() != NO_ERROR)
			{
				MSDC_PDNControl2(KAL_TRUE);
				return FS_MSDC_READ_SECTOR_ERROR;
			}
		}
		if(retry >= SD_MAX_RETRY)
		{
			MSDC_PDNControl2(KAL_TRUE);
			return FS_MSDC_READ_SECTOR_ERROR;
		}
		else
		{
			// kal_prompt_trace(MOD_AUD,"CRC etry:%d,status:%d",retry,status);
			goto start;			
		}
	}
	MSDC_PDNControl2(KAL_TRUE);
   return FS_NO_ERROR;
}

static int  WriteSectors(void * DriveData, DWORD Sector, UINT Sectors, void * Buffer)
{
	SDC_CMD_STATUS status;
	kal_uint8 retry = 0;
	kal_uint32 adrs;
		
#ifdef MSDC_CACHED_SUPPORT
	/*tell buffer type each time this function called*/
	if (INT_QueryIsCachedRAM(Buffer, Sectors * SECTOR_SIZE)){
		msdc2_handle->isCachedBuf = KAL_TRUE;

	}
	else
		msdc2_handle->isCachedBuf = KAL_FALSE;
#endif
		
#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)	
		if(gSD2->flags & SD_FLAG_HCS_SUPPORT)
			adrs = Sector;
		else
#endif		
		adrs = Sector * SECTOR_SIZE;	
	msdc2_handle->timeout_count = 0;	
start:
	if(!msdc2_handle->mIsInitialized)
	{
		//dbg_print("Write but not Initialized \r\n");
		MSDC_PDNControl2(KAL_TRUE);
		return FS_MSDC_WRITE_SECTOR_ERROR;
	}
	retry++;
	MSDC_PDNControl2(KAL_FALSE);
	if(Sectors > 1)
	{
		if(msdc2_handle->mMSDC_type == SD_CARD)
			SD_SetPreEraseBlk_2(Sectors);		
		status = SD_WriteMultiBlock_2((kal_uint32)adrs,(kal_uint32*)Buffer,(kal_uint32)Sectors);
	}
	else
		status = SD_WriteSingleBlock_2((kal_uint32)adrs,(kal_uint32*)Buffer);	
	if(status != NO_ERROR)
	{
		sd_w++;		
		if(kal_query_systemInit()== KAL_TRUE)
		{
			MSDC_PDNControl2(KAL_TRUE);
			return FS_MSDC_WRITE_SECTOR_ERROR;
		}
		if(status == ERR_CMD_TIMEOUT || status == MSDC_GPT_TIMEOUT_ERR)
			msdc2_handle->timeout_count++;
		if(msdc2_handle->timeout_count++ == 3 && msdc2_handle->mIsPresent == KAL_TRUE)
		{
			tst_sys_trace("[MSDC]:SD re-mount (write fail)");
			msdc2_handle->mIsInitialized = KAL_FALSE;
			retry = 0;
			if(SD_Initialize_2() != NO_ERROR)
			{
				MSDC_PDNControl2(KAL_TRUE);
				return FS_MSDC_WRITE_SECTOR_ERROR;
			}
		}		
		if(retry >= SD_MAX_RETRY)
		{
			MSDC_PDNControl2(KAL_TRUE);
			return FS_MSDC_WRITE_SECTOR_ERROR;
		}
		else
		{
			// kal_prompt_trace(MOD_AUD,"CRC write Error retry %d",retry);
			goto start;			
		}
	}
	MSDC_PDNControl2(KAL_TRUE);
   return FS_NO_ERROR;
}

static int  MountDevice(void * DriveData, int DeviceNumber, int DeviceType, DWORD Flags)
{	
	kal_uint8 retry = 0;
	
	if(msdc2_handle->mIsInitialized)
		return SECTOR_SIZE;
	msdc2_handle->is_init_timeout = KAL_FALSE;		
start:		
	if(!msdc2_handle->mIsPresent)
	{		
		//dbg_print("not present \r\n");
		
		#if defined(_NAND_FLASH_BOOTING_)
		// add the following code for solving plug in or out the SD card during 
		// NFB loading process. The card detection interruptwill disapperared 		 
		// while interrupt controller is masked.
		IRQMask(IRQ_MSDC2_CODE);
		if(MSDC_Reg(MSDC_PS) & MSDC_PS_PIN0)
		{
			if(msdc2_handle->ins_level == MSDC_IOCTRL_PULL_UP)
				msdc2_handle->mIsPresent = KAL_FALSE;	
			else
				msdc2_handle->mIsPresent = KAL_TRUE;	
		}
		else
		{
			if(msdc2_handle->ins_level == MSDC_IOCTRL_PULL_UP)
				msdc2_handle->mIsPresent = KAL_TRUE;
			else
				msdc2_handle->mIsPresent = KAL_FALSE;	
		}
		IRQUnmask(IRQ_MSDC2_CODE);
		#endif // _NAND_FLASH_BOOTING_
		
		if(!msdc2_handle->mIsPresent)	
		{
			MSDC_PDNControl2(KAL_TRUE);			
			return FS_MSDC_MOUNT_ERROR;
		}
	}
	MSDC_PDNControl2(KAL_FALSE);
	if(SD_Initialize_2() != NO_ERROR)
	{		
		goto err_exit;
	}	
	//if(SD_MountDevice(DeviceType) != FS_NO_ERROR)
		//return FS_MSDC_MOUNT_ERROR;

	//dbg_print("Mount success! \r\n");
	MSDC_PDNControl2(KAL_TRUE);
   return SECTOR_SIZE;
   
err_exit:
	if(retry++ <= SD_MAX_RETRY && msdc2_handle->is_init_timeout == KAL_FALSE)
	{
		//dbg_print("SD MountDevice failed! retry: %d \r\n",retry);
		goto start;
	}
	#if defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
	msdc2_handle->mIsPresent = KAL_FALSE;
	#endif		
	MSDC_PDNControl2(KAL_TRUE);
	return FS_MSDC_MOUNT_ERROR;
	
}
static int  MediaChanged(void * DriveData)
{		
	if(msdc2_handle->mIsPresent)
	{
		if(msdc2_handle->mIsInitialized)
		{
   		return FS_NO_ERROR;
		}
		else
		{
			return FS_MSDC_PRESNET_NOT_READY;
		}
	}
	return FS_MSDC_NOT_PRESENT;
}

/*-----------------------------------*/
static int  GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor)
{	
   kal_mem_set((void*)DiskGeometry, 0, sizeof * DiskGeometry);
   DiskGeometry->Sectors = gSD2->mCSD.capacity/512;
	*MediaDescriptor = MSDC_MEDIA_DESCRIPTOR;
	if(gSD2->mWPEnabled)
		return FS_WRITE_PROTECTION;		
   return FS_NO_ERROR;
}

/*-----------------------------------*/
static int  ShutDown(void * DriveData)
{
#ifdef  __TST_WRITE_TO_FILE_ONLY__
	/*error recording: write error log to memory card here*/
	MSDC_ErrorRecordingReset();
#endif
   return FS_NO_ERROR;
}

FS_Driver FS_SdDrv2 = {
   MountDevice,
   ShutDown,
   ReadSectors,
   WriteSectors,
   MediaChanged,
   DiscardSectors,
   GetDiskGeometry,
   NULL,
   NULL,
   NULL,
   NULL,
   NULL,
   NULL,
   MSDC_GetCardStatus2
};
#endif // (__MSDC_SD_MMC__)

#endif //DRV_MSDC_OFF
