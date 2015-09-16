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
 *    usbms_msdc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements usb adaption layer of msdc card for mass storage
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
#if defined(__USB_MSD_SUPPORT__) || defined(ATEST_DRV_MSDC)

//RHR ADD
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "qmu_bm.h"
//RHR REMOVE
/*
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
//MSBB remove #include "kal_non_specific_general_types.h"
#include "drv_comm.h"
#include "gpt_sw.h"
#include "usb_comm.h"
#include "usb_drv.h"
#include "usb.h"
#include "usbms_drv.h"
#include "usbms_adap.h"
#include "usb_custom.h"
#include "Rtfiles.h"
#include "fat_fs.h"
#include "custom_fs.h"
*/
//RHR
#include "msdc_def.h"
#include "fs_type.h"
/***********************************************
	MS and SD Disk Related functions
************************************************/

//#if !defined(DCL_MSDC_INTERFACE)
#include "msdc_def.h"
//#endif

#ifdef __MSDC_MS__
	#include "ms_def.h"
	extern FS_Driver FS_MsDrv;
	FS_Driver *CardDrv = &FS_MsDrv;
#elif defined(__MSDC_MSPRO__)	
	#include "mspro_def.h"	
	FS_Driver *CardDrv = &FS_MspDrvAll;		
#elif defined(__MSDC_SD_MMC__)
	#if defined(DCL_MSDC_INTERFACE)
	#include "dcl.h"
	#else
	#include "sd_def.h"
	#endif
	extern FS_Driver FS_SdDrv;
	FS_Driver *CardDrv = &FS_SdDrv;
#endif

#include "qmu_bm.h"
#include "usbms_msdc.h"

extern int Gpd_ReadSectors_NEW(void * DriveData, kal_uint32 Sector, kal_uint32 Sectors,qbm_gpd *head,qbm_gpd *tail);
extern int Gpd_WriteSectors_NEW(void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, qbm_gpd *head,qbm_gpd *tail);
extern kal_uint32 Get_BDStructNum(void);
kal_bool usbms_query_max_bd_num(kal_uint16 * max_bd_num)
{
    *max_bd_num = (kal_uint16)Get_BDStructNum();
    return KAL_TRUE;
}
#if ( (defined(__MSDC_MS__)) || (defined(__MSDC_SD_MMC__)) || (defined(__MSDC_MSPRO__)) )
kal_bool usbms_read_all(void *data, kal_uint32 LBA, kal_uint16 sec_len, MSDC_EXT_MEM_TYPE type)
{
	kal_int32 status;
	void *ID = NULL;
	ASSERT(CardDrv != NULL);
	switch(type)
	{
		case MSDC_MEM_TYPE_EXT:
			ID = EXT_MEM_ID;
			break;
#if defined(__SIM_PLUS__)
		case MSDC_MEM_TYPE_SIMPLUS:
			ID = SIMPLUS_MEM_ID;
			break;
#endif

#if defined(__MSDC_DUAL_CARD_SWITCH__)
		case MSDC_MEM_TYPE_TCARD2:
			ID = TCARD_2_MEM_ID;
			break;
#endif
		default:
			ID = NULL;
			return KAL_FALSE;			
	}	
	
	status = CardDrv->ReadSectors((void*)ID, LBA, sec_len, data);

	if(status)
		return KAL_FALSE;

	return KAL_TRUE;
}
kal_bool usbms_gpd_read_all(qbm_gpd *head,qbm_gpd *tail,kal_uint32 LBA,kal_uint16 sec_len,MSDC_EXT_MEM_TYPE type)
{
    kal_int32 status;
	void *ID = NULL;
	ASSERT(CardDrv != NULL);
	switch(type)
	{
		case MSDC_MEM_TYPE_EXT:
			ID = EXT_MEM_ID;
			break;
#if defined(__SIM_PLUS__)
		case MSDC_MEM_TYPE_SIMPLUS:
			ID = SIMPLUS_MEM_ID;
			break;
#endif

#if defined(__MSDC_DUAL_CARD_SWITCH__)
		case MSDC_MEM_TYPE_TCARD2:
			ID = TCARD_2_MEM_ID;
			break;
#endif
		default:
			ID = NULL;
			return KAL_FALSE;			
	}	
	status = Gpd_ReadSectors_NEW((void*)ID, LBA, sec_len, head,tail);

	if(status)
		return KAL_FALSE;

	return KAL_TRUE;
}
kal_bool usbms_write_all(void *data, kal_uint32 LBA, kal_uint16 sec_len, MSDC_EXT_MEM_TYPE type)
{
	kal_int32 status;
	void *ID = NULL;
	ASSERT(CardDrv != NULL);
	switch(type)
	{
		case MSDC_MEM_TYPE_EXT:
			ID = EXT_MEM_ID;
			break;
#if defined(__SIM_PLUS__)
		case MSDC_MEM_TYPE_SIMPLUS:
			ID = SIMPLUS_MEM_ID;
			break;
#endif

#if defined(__MSDC_DUAL_CARD_SWITCH__)
		case MSDC_MEM_TYPE_TCARD2:
			ID = TCARD_2_MEM_ID;
			break;
#endif
		default:
			ID = NULL;
			return KAL_FALSE;		
	}
	
	status = CardDrv->WriteSectors((void*)ID, LBA, sec_len, data);	
	
	if(status)
		return KAL_FALSE;

	return KAL_TRUE;
}
kal_bool usbms_gpd_write_all(qbm_gpd *head,qbm_gpd *tail,kal_uint32 LBA,kal_uint16 sec_len,MSDC_EXT_MEM_TYPE type)
{
    kal_int32 status;
	void *ID = NULL;
	ASSERT(CardDrv != NULL);

	switch(type)
	{
		case MSDC_MEM_TYPE_EXT:
			ID = EXT_MEM_ID;
			break;
#if defined(__SIM_PLUS__)
		case MSDC_MEM_TYPE_SIMPLUS:
			ID = SIMPLUS_MEM_ID;
			break;
#endif

#if defined(__MSDC_DUAL_CARD_SWITCH__)
		case MSDC_MEM_TYPE_TCARD2:
			ID = TCARD_2_MEM_ID;
			break;
#endif
		default:
			ID = NULL;
			return KAL_FALSE;			
	}	
	status = Gpd_WriteSectors_NEW((void*)ID, LBA, sec_len, head,tail);

	if(status)
		return KAL_FALSE;

	return KAL_TRUE;
}

/*
typedef  enum{
 	USB_MS_EXIST,
 	USB_MS_CHANGED,
 	USB_MS_NOT_EXIST,
 	USB_MS_LOCKED
}USB_MS_EXIST_ENUM;
*/
/*status =0(ok),1(MediaChanged),2(NoMedia)*/

#if defined(DCL_MSDC_INTERFACE)

kal_int16 usbms_checkmedia_exist_all(MSDC_EXT_MEM_TYPE type)
{
	DCL_BOOL changed = DCL_FALSE;
	DCL_HANDLE dclHandle = DCL_HANDLE_NONE;	
	DCL_BOOL isCardExist = DCL_FALSE;
	DCL_BOOL isWP = DCL_FALSE;
#if defined(__MSDC_SD_MMC__)&&(defined (LIPTON_BB) ||defined(ROSEMARY_BB))
	SD_CTRL_GET_CAPACITY_T capacity;
#endif
//jinxing add for dual T-card.
#if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	sd_select_enum sel;
	SD_CTRL_ANALOG_SWITCH_T prSwitch;
	void *ID = NULL;


	switch(type)
	{
		case MSDC_MEM_TYPE_EXT:
			ID = EXT_MEM_ID;
			break;
	#if defined(__SIM_PLUS__)
		case MSDC_MEM_TYPE_SIMPLUS:
			ID = SIMPLUS_MEM_ID;
			break;
	#endif

	#if defined(__MSDC_DUAL_CARD_SWITCH__)
		case MSDC_MEM_TYPE_TCARD2:
			ID = TCARD_2_MEM_ID;
			break;
	#endif
			default:
				ID = NULL;
				return DEV_STATUS_NOMEDIA;			
	}	
#endif

#if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	if((MSDC_HANDLE *)ID == &MSDC_Blk[0])
   {
		sel = SD_EXT;
	}
	else
   {
#if defined(__SIM_PLUS__)
		sel = SD_SIM;
#elif defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
		sel = SD_T_CARD_2;
#endif
	}

   if(sel==SD_EXT)
	{
    dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
	if (dclHandle == DCL_HANDLE_INVALID)
		return DEV_STATUS_NOMEDIA;
   }
   else
   {
      #if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
      dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_SIMPLUS|DCL_SD_FLAGS_USAGE_CMD);
      if (dclHandle == DCL_HANDLE_INVALID)
         return DEV_STATUS_NOMEDIA;
      #else
         ASSERT(0);
      #endif
   }
   prSwitch.u4TargetInterface=sel;
   //DclSD_Control(dclHandle, SD_CTRL_CMD_ANALOG_SWITCH, (DCL_CTRL_DATA_T*)&prSwitch);
#else
   dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
	if (dclHandle == DCL_HANDLE_INVALID)
		return DEV_STATUS_NOMEDIA;
#endif
//jinxing add done
	DclSD_Control(dclHandle, SD_CTRL_CMD_GET_AND_CLEAR_MEDIA_CHANGED, (DCL_CTRL_DATA_T*)&changed);
	if(changed)
	{
		DclSD_Close(dclHandle);
		return DEV_STATUS_MEDIA_CHANGE;
	}

	DclSD_Control(dclHandle, SD_CTRL_CMD_IS_EXISTENCE, (DCL_CTRL_DATA_T*)&isCardExist);
	if (isCardExist)
	{
		#if defined(__MSDC_SD_MMC__)
		DclSD_Control(dclHandle, SD_CTRL_CMD_WRITE_PROTECTION, (DCL_CTRL_DATA_T*)&isWP);
		if(isWP)
		{		
			DclSD_Close(dclHandle);
			return DEV_STATUS_WP;
		}
		#endif
		#if defined(__MSDC_MS__)
		if(gMS.is_wp)
		{
			return DEV_STATUS_WP;
		}
		#endif	
		#if defined(__MSDC_MSPRO__)		
		if(gMSP.is_wp)		
		{			
			//return USB_MS_LOCKED;		
			return DEV_STATUS_WP;
		}					
		#endif
		//return USB_MS_EXIST;

		#if defined(__MSDC_SD_MMC__)
		#if (defined (LIPTON_BB) ||defined(ROSEMARY_BB))
		// TFlash larger than 8GB is not support
		
		DclSD_Control(dclHandle, SD_CTRL_CMD_GET_CAPACITY, (DCL_CTRL_DATA_T*)&capacity);
		if (*(capacity.pu8Capacity) > ((unsigned long long)FS_MAX_DISK_SIZE*1024*1024))
		{
			DclSD_Close(dclHandle);
			return DEV_STATUS_NOMEDIA;
		}
		#endif //(LIPTON_BB) ||defined(ROSEMARY_BB))
		#endif

		DclSD_Close(dclHandle);
		return DEV_STATUS_OK;
	}

	DclSD_Close(dclHandle);
	
	return DEV_STATUS_NOMEDIA;
}

#else

kal_int16 usbms_checkmedia_exist_all(MSDC_EXT_MEM_TYPE type)
{
	kal_bool changed;
	void *ID = NULL;

	switch(type)
	{
		case MSDC_MEM_TYPE_EXT:
			ID = EXT_MEM_ID;
			break;
#if defined(__SIM_PLUS__)
		case MSDC_MEM_TYPE_SIMPLUS:
			ID = SIMPLUS_MEM_ID;
			break;
#endif

#if defined(__MSDC_DUAL_CARD_SWITCH__)
		case MSDC_MEM_TYPE_TCARD2:
			ID = TCARD_2_MEM_ID;
			break;
#endif

		default:
			ID = NULL;
			return DEV_STATUS_NOMEDIA;			
	}	

	changed = MSDC_GetMediaChanged((void*)ID);
	if(changed)
	{
		//return USB_MS_CHANGED;
		return DEV_STATUS_MEDIA_CHANGE;
	}
		
	if(gMSDC_Handle->mIsPresent)
	{
		#if defined(__MSDC_SD_MMC__)
		if(gSD->mWPEnabled)
		{		
			//return USB_MS_LOCKED;
			return DEV_STATUS_WP;
		}
		#endif
		#if defined(__MSDC_MS__)
		if(gMS.is_wp)
		{
			//return USB_MS_LOCKED;
			return DEV_STATUS_WP;
		}
		#endif	
		#if defined(__MSDC_MSPRO__)		
		if(gMSP.is_wp)		
		{			
			//return USB_MS_LOCKED;		
			return DEV_STATUS_WP;
		}					
		#endif
		//return USB_MS_EXIST;

		#if defined(__MSDC_SD_MMC__)
		#if (defined (LIPTON_BB) ||defined(ROSEMARY_BB))
		// TFlash larger than 8GB is not support
		if (gSD->mCSD.capacity > ((unsigned long long)FS_MAX_DISK_SIZE*1024*1024))
			return DEV_STATUS_NOMEDIA;
		#endif //(LIPTON_BB) ||defined(ROSEMARY_BB))
		#endif

		return DEV_STATUS_OK;
	}
	
	//return USB_MS_NOT_EXIST;   
	return DEV_STATUS_NOMEDIA;
}

#endif//defined(DCL_MSDC_INTERFACE)

kal_bool usbms_format_all(MSDC_EXT_MEM_TYPE type)
{
	kal_uint32 status;
	void *ID = NULL;

	switch(type)
	{
		case MSDC_MEM_TYPE_EXT:
			ID = EXT_MEM_ID;
			break;
#if defined(__SIM_PLUS__)
		case MSDC_MEM_TYPE_SIMPLUS:
			ID = SIMPLUS_MEM_ID;
			break;
#endif

#if defined(__MSDC_DUAL_CARD_SWITCH__)
		case MSDC_MEM_TYPE_TCARD2:
			ID = TCARD_2_MEM_ID;
			break;
#endif

		default:
			return KAL_FALSE;			
	}	
	
	ASSERT(CardDrv != NULL);
	status = CardDrv->MountDevice((void*)ID,0,0,0);
	if(status != 512)
		return KAL_FALSE;

	return KAL_TRUE;  
}

kal_bool usbms_prevmedia_removal_all(kal_bool enable)
{
	return KAL_TRUE;
}

#if defined(DCL_MSDC_INTERFACE)

kal_bool usbms_read_capacity_all(kal_uint32 *max_lba, kal_uint32 *sec_len, MSDC_EXT_MEM_TYPE type)
{
	kal_int32 status;
	DCL_HANDLE dclHandle = DCL_HANDLE_NONE;
	SD_CTRL_GET_CAPACITY_T capacity;
	void *ID = NULL;
//jinxing add for dual T-card.
#if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	sd_select_enum sel;
	SD_CTRL_ANALOG_SWITCH_T prSwitch;
#endif

	ASSERT(CardDrv != NULL);
	switch(type)
	{
		case MSDC_MEM_TYPE_EXT:
			ID = EXT_MEM_ID;
			break;
#if defined(__SIM_PLUS__)
		case MSDC_MEM_TYPE_SIMPLUS:
			ID = SIMPLUS_MEM_ID;
			break;
#endif

#if defined(__MSDC_DUAL_CARD_SWITCH__)
		case MSDC_MEM_TYPE_TCARD2:
			ID = TCARD_2_MEM_ID;
			break;
#endif

		default:
			return KAL_FALSE;			
	}	

	status = CardDrv->MountDevice((void*)ID, 0, 0, 0);
	if(status != 512)
		return KAL_FALSE;

	#if defined(__MSDC_MS__)   	
		*max_lba = gMS.TotalSectors-1;   
	#elif defined(__MSDC_MSPRO__)   	
		*max_lba = gMSP.user_block*gMSP.block_size-1;   
	#elif defined(__MSDC_SD_MMC__)
	#if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	if((MSDC_HANDLE *)ID == &MSDC_Blk[0])
   {
		sel = SD_EXT;
	}
	else
   {
#if defined(__SIM_PLUS__)
		sel = SD_SIM;
#elif defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
		sel = SD_T_CARD_2;
#endif
	}

   if(sel==SD_EXT)
	{
    	dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
		if (dclHandle == DCL_HANDLE_INVALID)
			return KAL_FALSE;
   }
   else
   {
      #if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
      dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_SIMPLUS|DCL_SD_FLAGS_USAGE_CMD);
      if (dclHandle == DCL_HANDLE_INVALID)
         return KAL_FALSE;
      #else
         ASSERT(0);
      #endif
   }
	prSwitch.u4TargetInterface=sel; 
   DclSD_Control(dclHandle, SD_CTRL_CMD_ANALOG_SWITCH, (DCL_CTRL_DATA_T*)&prSwitch);
   #else
   dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
	if (dclHandle == DCL_HANDLE_INVALID)
		return KAL_FALSE;
#endif
//jinxing add done
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	
		DclSD_Control(dclHandle, SD_CTRL_CMD_GET_CAPACITY, (DCL_CTRL_DATA_T*)&capacity);
		DclSD_Close(dclHandle);
		*max_lba =(capacity.pu8Capacity)/512 -1;
	#endif
	*sec_len =512;
	return KAL_TRUE;
}

#else

kal_bool usbms_read_capacity_all(kal_uint32 *max_lba, kal_uint32 *sec_len, MSDC_EXT_MEM_TYPE type)
{
	kal_int32 status;
	void *ID = NULL;

	ASSERT(CardDrv != NULL);
	switch(type)
	{
		case MSDC_MEM_TYPE_EXT:
			ID = EXT_MEM_ID;
			break;
#if defined(__SIM_PLUS__)
		case MSDC_MEM_TYPE_SIMPLUS:
			ID = SIMPLUS_MEM_ID;
			break;
#endif

#if defined(__MSDC_DUAL_CARD_SWITCH__)
		case MSDC_MEM_TYPE_TCARD2:
			ID = TCARD_2_MEM_ID;
			break;
#endif

		default:
			return KAL_FALSE;			
	}	
	status = CardDrv->MountDevice((void*)ID, 0, 0, 0);
	if(status != 512)
		return KAL_FALSE;

	#if defined(__MSDC_MS__)   	
		*max_lba = gMS.TotalSectors-1;   
	#elif defined(__MSDC_MSPRO__)   	
		*max_lba = gMSP.user_block*gMSP.block_size-1;   
	#elif defined(__MSDC_SD_MMC__)
		*max_lba = gSD->mCSD.capacity/512 -1;
	#endif
	*sec_len =512;
	return KAL_TRUE;
}

#endif//defined(DCL_MSDC_INTERFACE)

#endif   /*__MSDC_MS__,__MSDC_SD_MMC__*/

#endif /*__USB_MSD_SUPPORT__*/

