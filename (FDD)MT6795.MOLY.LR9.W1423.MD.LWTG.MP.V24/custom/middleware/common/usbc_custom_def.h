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
 *   usbc_custom_def.h
 *
 * Project:
 * --------
 *   MOLY 
 *
 * Description:
 * ------------
 *   This file declares usb customization definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _USBC_CUSTOM_DEF_H_
#define _USBC_CUSTOM_DEF_H_

#define USB_UNIQUE_SERIAL_NUM_ENABLE    (1)     /* 1: Set IMEI as the serial number. 0: do not report serial number in device descriptor */
#define U3_CONF_BMAXPOWER               (896)   /* the iMaxPower of USB 3.0 configuration descriptor */
#define U3_CONF_BMAXPOWER_META          (400)   /* the iMaxPower of USB 3.0 configuration descriptor in META mode */

typedef enum {
    USB_MODE_BTT_STANDALONE = 0,    /* BTT standlone */
    USB_MODE_ACM_ONLY,              /* Normal Operations */
    USB_MODE_META,
    USB_MODE_1R2C,
    USB_MODE_MSD_ONLY,
    USB_MODE_MT6290_DATACARD,
    USB_MODE_MORPHING,
    USB_MODE_MT6290_ECM,
    USB_MODE_ESL,
    USB_MODE_NUM
} usb_mode_e;

#if defined(__USB_MSD_SUPPORT__)
typedef enum
{
	USBMS_DISK_MSDC1,
	USBMS_DISK_MSDC2,
	USBMS_DISK_NOR,
	USBMS_DISK_NAND,
#if defined(__MTK_TARGET__)
	USBMS_DISK_CDROM
#else
	USBMS_DISK_CDROM,
	USBMS_DISK_RAMDISK
#endif
} MS_DISK_CONFIG_TYPE;//config type for ms adapter

/*from spec SCSI-4 (6.4.2)*/
#define MS_INQURIY_VENDOR_MAX_SIZE 8
#define MS_INQURIY_PRODUCT_MAX_SIZE 16
#define MS_INQURIY_REVISION_MAX_SIZE 4
#endif

#endif /* _USBC_CUSTOM_DEF_H_ */
