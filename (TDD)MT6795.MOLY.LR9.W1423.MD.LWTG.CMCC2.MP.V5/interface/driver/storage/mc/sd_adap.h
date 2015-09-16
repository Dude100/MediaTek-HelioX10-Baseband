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
 *   msdc_adap_BL.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef _SD_ADAP_H_
#define _SD_ADAP_H_


#if defined(__EMMC_BOOTING__)

#include "fat_fs.h"

#include "msdc_def.h"
#include "sd_def.h"

typedef enum 
{
	DRV_SUCCESS = 0,
	DRV_ERROR,
	DRV_INIT_FAILURE,
	DRV_MOUNT_DEV_FAILURE,
	DRV_READ_FAILURE,
	DRV_WRITE_FAILURE,
	DRV_BAD_BLOCK,
	DRV_OPERATION_RETRY,
	DRV_INVALID_PARAMETER,
	DRV_ERASE_FAILURE,
	DRV_NON_EMPTY,
	DRV_NON_EMPTY_CHECK,
	DRV_ECC_FAILURE,
	DRV_ECC_CORRECTED
} DRV_STATUS_CODE;

typedef struct _emmc_addr {
	eMMC_partitions partition;
	unsigned int offset; // unit size: 512-byte
} emmc_addr;

extern DRV_STATUS_CODE DRV_SD_Init(void);
extern DRV_STATUS_CODE DRV_SD_DeInit(void);
extern DRV_STATUS_CODE DRV_SD_MountDevice(
	mcdev_enum id,
	unsigned int flags	// reserved
	);
extern DRV_STATUS_CODE DRV_SD_ReadSectors(
	mcdev_enum id,
	unsigned int sector,
	unsigned int sectors,
	void * buffer,
	unsigned int flags	// reserved
	);
extern DRV_STATUS_CODE DRV_SD_WriteSectors(
	mcdev_enum id,
	unsigned int sector,
	unsigned int sectors,
	void * buffer,
	unsigned int flags	// reserved
	);

#endif //__EMMC_BOOTING__


#if defined(__CARD_DOWNLOAD__)

#include "fat_fs.h"

extern int BL_MSDC_Init(void);
extern int BL_MSDC_DeInit(void);
extern int BL_MSDC_MountDevice(void * DriveData, int DeviceNumber, int DeviceType, unsigned int Flags);
extern int BL_MSDC_ReadSectors(void * DriveData, unsigned int Sector, unsigned int Sectors, void * Buffer);
extern int BL_MSDC_GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor);

#endif //__CARD_DOWNLOAD__


#endif //_SD_ADAP_H_
