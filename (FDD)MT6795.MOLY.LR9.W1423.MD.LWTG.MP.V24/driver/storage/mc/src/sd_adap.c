/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   sd_adap.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   MSDC/SD driver adaption layer
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __EMMC_BOOTING__

#include "sd_adap.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "dcl.h"

#if defined(__UBL__) || defined(__FUE__)
#include <bl_MTK_BB_REG.H>
#else
#include "drv_comm.h"
#include "msdc_reg_adap.h"
#endif


/*** external data & function ***/


/*** internal data & function ***/

static SDC_CMD_STATUS DRV_SD_AddrLookupTbl(unsigned int sector, emmc_addr *addr);

/*** external function body ***/

DRV_STATUS_CODE DRV_SD_Init(void)
{
#if (defined(__UBL__) || defined(__FUE__)) && defined(MT6256_S00)
    // enable GPIO for MSDC
    //DRV_WriteReg16(0x701D0610, 0x1110);
    //DRV_WriteReg16(0x701D0620, 0x0111);
    DRV_WriteReg16(GPIO_base+0x0610, 0x1110);
    DRV_WriteReg16(GPIO_base+0x0620, 0x0111);
    // enable GPT3
    //DRV_WriteReg32(0x7007001C, 1);
    DRV_WriteReg32(GPT_base+0x001C, 1);
    
#endif

#if !defined(DCL_MSDC_INTERFACE)
	MSDC_Initialize();
#else
	DclSD_Initialize();
#endif//!defined(DCL_MSDC_INTERFACE)

    return DRV_SUCCESS;
}

DRV_STATUS_CODE DRV_SD_DeInit(void)
{
    MSDC_DeInit();

    // reset GPIO to disable MSDC

    return DRV_SUCCESS;
}

DRV_STATUS_CODE DRV_SD_MountDevice(
	mcdev_enum id,
	unsigned int flags
	)
{
	SDC_CMD_STATUS status = NO_ERROR;
	status = MountDevice(GetMsdcHandle(id), 0, 0, flags);
	if (512 != status)
		return DRV_MOUNT_DEV_FAILURE;

	return DRV_SUCCESS;
}

DRV_STATUS_CODE DRV_SD_ReadSectors(
	mcdev_enum id,
	unsigned int sector,
	unsigned int sectors,
	void * buffer,
	unsigned int flags
	)
{
	SDC_CMD_STATUS status = NO_ERROR;
	emmc_addr addr;

	get_MSDC_lock(&gSD->mSDdrv_lock);

	status = DRV_SD_AddrLookupTbl(sector, &addr);
	if (NO_ERROR != status)
	{
		free_MSDC_lock(&gSD->mSDdrv_lock);
		return DRV_READ_FAILURE;
	}

	if (KAL_TRUE != SD_eMMC_ECSD_setCurrentPart(addr.partition))
	{
		free_MSDC_lock(&gSD->mSDdrv_lock);
		return DRV_READ_FAILURE;
	}

#if defined(DRV_MSDC_BLOCKING_TRANSFER_SUPPORT)
	status = ReadSectors(GetMsdcHandle(id), addr.offset, sectors, buffer, SD_FLAG_BLOCKING_TRANSFER);
#else
	status = ReadSectors(GetMsdcHandle(id), addr.offset, sectors, buffer);
#endif
	if (NO_ERROR != status)
	{
		free_MSDC_lock(&gSD->mSDdrv_lock);
		return DRV_READ_FAILURE;
	}

	if (KAL_TRUE != SD_eMMC_ECSD_setCurrentPart(eMMC_user_Area))
	{
		free_MSDC_lock(&gSD->mSDdrv_lock);
		return DRV_READ_FAILURE;
	}

	free_MSDC_lock(&gSD->mSDdrv_lock);
	return DRV_SUCCESS;
}

//! under construction [Samuel, 2010/10/01]
DRV_STATUS_CODE DRV_SD_WriteSectors(
	mcdev_enum id,
	unsigned int sector,
	unsigned int sectors,
	void * buffer,
	unsigned int flags
	)
{
	SDC_CMD_STATUS status = NO_ERROR;
	emmc_addr addr;

//#if !defined(__UBL__) && !defined(__FUE__)
//	ASSERT(0); // so far this function can only be used in bootloader
//#endif

	get_MSDC_lock(&gSD->mSDdrv_lock);

	status = DRV_SD_AddrLookupTbl(sector, &addr);
	if (NO_ERROR != status)
	{
		free_MSDC_lock(&gSD->mSDdrv_lock);
		return DRV_WRITE_FAILURE;
	}

	if (KAL_TRUE != SD_eMMC_ECSD_setCurrentPart(addr.partition))
	{
		free_MSDC_lock(&gSD->mSDdrv_lock);
		return DRV_WRITE_FAILURE;
	}

	status = WriteSectors(GetMsdcHandle(id), addr.offset, sectors, buffer);
	if (NO_ERROR != status)
	{
		free_MSDC_lock(&gSD->mSDdrv_lock);
		return DRV_WRITE_FAILURE;
	}

	//! TODO: check why it fails
	if (KAL_TRUE != SD_eMMC_ECSD_setCurrentPart(eMMC_user_Area))
	{
		free_MSDC_lock(&gSD->mSDdrv_lock);
		return DRV_WRITE_FAILURE;
	}

	free_MSDC_lock(&gSD->mSDdrv_lock);
	return DRV_SUCCESS;
}

/*** internal function body ***/

//! 1st designed for eMMC
static SDC_CMD_STATUS DRV_SD_AddrLookupTbl(unsigned int sector, emmc_addr *addr)
{
	if (gSD->emmc_info.isEmmcV44 == KAL_FALSE)
		return ERR_INVALID_CARD;

	if (sector >= (gSD->emmc_info.bootPartitionSize + gSD->emmc_info.gp1PartitionSize))
		return ERR_INVALID_BLOCK; // out-of-range

	if (sector < gSD->emmc_info.bootPartitionSize)
	{
		addr->partition = eMMC_boot_partition1;
		addr->offset = sector;
	}
	else
	{
		addr->partition = eMMC_GP_partition1;
		addr->offset = sector - gSD->emmc_info.bootPartitionSize;
	}

	return DRV_SUCCESS;
}

#endif//__EMMC_BOOTING__



#ifdef __CARD_DOWNLOAD__

#include "msdc_adap_bl.h"
#include "drv_comm.h"
#include "msdc_def.h"

/*** external data & function ***/

extern FS_Driver FS_SdDrv;

/*** function body ***/

int BL_MSDC_Init(void)
{
    // enable GPIO for MSDC
    DRV_SetBits(0x80021800, 0x5540);
    DRV_SetBits(0x80021900, 0x55);

    MSDC_Initialize();

    return 0;
}

int BL_MSDC_DeInit(void)
{
    MSDC_DeInit();

    // reset GPIO to disable MSDC
    DRV_ClearBits(0x80021800, 0x5540);
    DRV_ClearBits(0x80021900, 0x55);

    return 0;
}

int BL_MSDC_MountDevice(int DeviceNumber, int DeviceType, unsigned int Flags)
{
    return FS_SdDrv.MountDevice((void*)&MSDC_Blk[0], DeviceNumber, DeviceType, Flags);
}

int BL_MSDC_ReadSectors(unsigned int Sector, unsigned int Sectors, void * Buffer)
{
    return FS_SdDrv.ReadSectors((void*)&MSDC_Blk[0], Sector, Sectors, Buffer);
}

int BL_MSDC_GetDiskGeometry(FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor)
{
    return FS_SdDrv.GetDiskGeometry((void*)&MSDC_Blk[0], DiskGeometry, MediaDescriptor);
}

int BL_MSDC_GetCardPSN(unsigned int *psn)
{
    FS_DeviceInfo info;
    FS_SdDrv.IOCtrl((void*)&MSDC_Blk[0], FS_IOCTRL_QUERY_CARD_INFO, &info);

    *psn = info.DeviceInfo.Card.PSN;

    return 0;
}

#endif//__CARD_DOWNLOAD__

