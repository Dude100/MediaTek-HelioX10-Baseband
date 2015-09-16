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
 *    usb_msdisk.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for usb mass storage disk related information.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef USB_MSDISK_H
#define USB_MSDISK_H

//#include "kal_non_specific_general_types.h"
#include "qmu_bm.h"



#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
#define LOGIC_DRIVE_COUNT             2
#else
#define LOGIC_DRIVE_COUNT             1
#endif
#define LOGIC_DRIVE_MS              	0
#define LOGIC_DRIVE_CDROM             1

typedef enum 
{
	USB_STORAGE_DEV_STATUS_OK = 0,
	USB_STORAGE_DEV_STATUS_MEDIA_CHANGE,
	USB_STORAGE_DEV_STATUS_NOMEDIA,
	USB_STORAGE_DEV_STATUS_WP,
	USB_STORAGE_DEV_STATUS_MAX
} USB_STORAGE_DEV_STATUS;


typedef enum
{
	USB_STORAGE_DEV_NOR,
	USB_STORAGE_DEV_NAND,
	USB_STORAGE_DEV_CARD,
	USB_STORAGE_DEV_CDROM,
	USB_STORAGE_DEV_NONE
}USB_STORAGE_DEV_TYPE;


typedef struct
{
	kal_bool (* usbms_read)(void *data, kal_uint32 LBA, kal_uint16 sec_len);
	kal_bool (* usbms_write)(void *data, kal_uint32 LBA, kal_uint16 sec_len);
	kal_bool (* usbms_format)(void);
	USB_STORAGE_DEV_STATUS (* usbms_checkmedia_exist)(void);
	kal_bool (* usbms_prevmedia_removal)(kal_bool enable);
	kal_bool (* usbms_read_capacity)(kal_uint32 *max_lba, kal_uint32 *sec_len);
//	kal_bool (* usbms_read_formatcapacity)(kal_uint32 *no_of_blks, kal_uint32 *blk_len);
	USB_STORAGE_DEV_TYPE	(* usbms_dev_type)(void);
    kal_bool (* usbms_read_gpd)(qbm_gpd *head,qbm_gpd *tail,kal_uint32 LBA,kal_uint16 sec_len);
    kal_bool (* usbms_write_gpd)(qbm_gpd *head,qbm_gpd *tail,kal_uint32 LBA,kal_uint16 sec_len);
    kal_bool (* usbms_query_max_db_num)(kal_uint16 *max_bd_num);

}USB_DiskDriver_STRUCT;


#if ( (defined(__MSDC_MS__)) || (defined(__MSDC_SD_MMC__)) || (defined(__MSDC_MSPRO__)) )
extern USB_DiskDriver_STRUCT USB_MSDC_drv;
#endif

//kal_uint8 usbms_register_diskdriver(USB_DiskDriver_STRUCT *disk_api);
extern kal_uint8 USB_Ms_Register_DiskDriver(USB_DiskDriver_STRUCT *disk_api);
extern kal_uint8 USB_Ms_Set_Current_Driver(kal_uint32 drv);
extern kal_uint32 USB_Ms_Get_Current_Driver(void);

#endif /* USB_MSDISK_H */                    

