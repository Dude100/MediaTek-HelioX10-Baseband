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
 *    usbms_cdrom.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements usb adaption layer of CD-ROM for mass storage
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
 
#if defined(__USB_MASS_STORAGE_CDROM_ENABLE__)
 #include "drv_comm.h"
#include "gpt_sw.h"
#include "usb_comm.h"
#include "usb_drv.h"
#include "usb.h"
#include "usbms_drv.h"
#include "usbms_adap.h"
#include "usb_custom.h"

#include "fs_gprot.h" 


static kal_bool usbms_read_sysdrv( void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	kal_uint32  received_file_size;
	kal_int32	   result;


	result = FS_Seek(g_UsbMS.cdrom_drive_handle, (int)(LBA*512), (int)FS_FILE_BEGIN);

	if(result < 0)
	{
		//EXT_ASSERT(0, result, 0, 0);
		return KAL_FALSE;
	}

	result = FS_Read(g_UsbMS.cdrom_drive_handle, data, (sec_len*512), &received_file_size);

	if(result != FS_NO_ERROR)
		EXT_ASSERT(0, result, 0, 0);

	return KAL_TRUE;
}


static kal_bool usbms_write_sysdrv(void *data, kal_uint32 LBA, kal_uint16 sec_len)
{
	ASSERT(0);
	return KAL_FALSE;
}


static kal_bool usbms_read_capacity_sysdrv(kal_uint32 *max_lba, kal_uint32 *sec_len)
{
	kal_uint32  lba = 512;
	kal_int32	   result;
	
	*sec_len = 512;
	result = FS_GetFileSize(g_UsbMS.cdrom_drive_handle, &lba);

	if(result != FS_NO_ERROR)
		EXT_ASSERT(0, result, 0, 0);

	*max_lba = (lba/512) - 1;

	return KAL_TRUE;
}


static USB_STORAGE_DEV_STATUS usbms_checkmedia_exit_sysdrv(void)
{
	if(g_UsbMS.cdrom_drive_handle < 0)
		return USB_STORAGE_DEV_STATUS_NOMEDIA;
	else
		return USB_STORAGE_DEV_STATUS_OK;
}


static kal_bool usbms_format_sysdrv()
{
	return KAL_TRUE;
}


static kal_bool usbms_prevmedia_removal_sysdrv(kal_bool enable)
{
	return KAL_TRUE;
}


/*
static kal_bool usbms_read_formatcapacity_sysdrv(kal_uint32 *no_of_blks, kal_uint32 *blk_len)
{
	return KAL_TRUE;
}
*/

static USB_STORAGE_DEV_TYPE usbms_dev_type_sysdrv(void)
{
	return USB_STORAGE_DEV_CDROM;
}


/* If we want to export the drive which system drive in the same disk, then we need to build this fake MS APIs to replace NOR or NAND flash APIs */
USB_DiskDriver_STRUCT USB_CDROM_drv =
{
	usbms_read_sysdrv,
	usbms_write_sysdrv,
	usbms_format_sysdrv,
	usbms_checkmedia_exit_sysdrv,
	usbms_prevmedia_removal_sysdrv,
	usbms_read_capacity_sysdrv,
//	usbms_read_formatcapacity_sysdrv,
	usbms_dev_type_sysdrv
};
#endif
