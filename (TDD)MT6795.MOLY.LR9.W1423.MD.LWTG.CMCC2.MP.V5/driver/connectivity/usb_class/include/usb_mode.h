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
 *    usb_mode.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    This file intends for usb mode selection definitions
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef USB_MODE_H
#define USB_MODE_H


#include "usb_comm.h"
#include "usb.h"
#ifdef __OTG_ENABLE__
#include "otg.h"
#endif
#include "kal_general_types.h"

#define USB_MAX_COMPOSITE_DEVICES	10

typedef enum
{
	USB_MODE_NONE = 0,
	USB_MODE_NVRAM_READ_DONE,
	USB_MODE_BMT_READ_DONE,
	USB_MODE_FT_START_DONE
}USB_MODE_PRARM;

typedef enum
{
	USBDL_MODE_NONE = 0,
	USBDL_MODE_USB_DOWNLOAD,
	USBDL_MODE_FAST_META
}USBDL_MODE_PRARM;


typedef enum
{
	USB_MODE_CABLE_PLUGOUT,
	USB_MODE_CABLE_A_PLUGIN,
	USB_MODE_CABLE_B_PLUGIN,
	USB_MODE_CABLE_ERROR,
	USB_MODE_CABLE_UNSUPPORT
}USB_MODE_CABLE_TYPE;


typedef struct
{
	USB_Comport_Boot_Status  	usb_comport_boot;		/* a flag to check if usb boot as com port */
	USB_Comport_OS_Driver_Status  	usb_comport_driver;		/* a flag to check OS version for usb comport usage */
	kal_uint8 				mode_param;
	kal_uint8				com_port_num;
	USB_MODE_CABLE_TYPE 	cable_type;
	USB_MODE_CABLE_TYPE 	previous_cable_type;
#if defined(__USB_MASS_STORAGE_ENABLE__)||defined(__MTP_ENABLE__)
	kal_bool 					b_ms_first_plugin;  /*whether it is first plug in or not in ms mode */
	kal_bool					b_usb_boot_with_ms;
#endif
#ifdef __OTG_ENABLE__
	kal_bool					b_start_srp;		/* set in OTG_Start_SRP */
	kal_bool					b_start_hnp;	/* Check if start HNP */
	kal_bool 					b_usb_pdnmode;	/* Check if phy power down or not */
#endif
#ifdef __IC_USB_ENABLE__
	kal_bool 					b_int_usb_detect; // ICUSB enter Host mode
#endif
#if defined(__DM_LAWMO_SUPPORT__)
	kal_bool					b_lock_usb_boot;
#endif
	kal_bool 			usb_config_result; 	/* configure may be fail */
	kal_bool 			usb_boot; 	/* is in usb boot mode */
	kal_bool			usb_menu_en; // pop up menu or not
	kal_bool			usb_cdrom_en;//config as cd rom	or not
#ifdef __USB_TETHERING__
	kal_bool			rndis_cnf_response;
#endif
}Usb_Mode_Struct;


extern Usb_Mode_Struct g_UsbMode;

extern void USB_Init_Mode(void);
#ifdef __OTG_ENABLE__
extern void OTG_Mode_Selection(void);
#else
extern void USB_Mode_Selection(void);
#endif

extern void USB_Config_Type(USB_DEVICE_TYPE type, kal_bool b_enable, kal_uint32 *parameter);
extern void USB_Release_Type(kal_bool b_enable, kal_bool b_plugout);
extern void USB_Init_Normal_Mode_Ms(void);
extern kal_bool USB_Check_Composite_With_COM(USB_DEVICE_TYPE type);

//extern void USB_Init_Normal_Mode_Ms(kal_uint32* mem_addr);
extern void USB_End_Normal_Mode_Ms(void);

#ifdef __OTG_ENABLE__
extern void OTG_Hdlr_Select(OTG_HDLR_TASK_TYPE type, kal_uint32 *parameter);
#endif

extern void USB_Init_Ms(kal_bool bFirst);
extern void USB_Init_ACM_In_Meta(void);
extern void USB_Init_ACM_In_AT_Mode(void);

extern USBDL_MODE_PRARM USBDL_Mode_Type(void);
extern kal_bool USB_Exception_Check(void);


extern kal_bool USB_Boot_With_MS(void);
#ifdef __MTP_ENABLE__
extern void USB_Init_MTP(kal_bool bFirst);
#endif

extern void USB_Mode_Switch(USB_DEVICE_TYPE type);
extern void USB_Composite_Device_Table_Reset(void);
extern void USB_Composite_Device_Table_Register(USB_COMPOSITE_DEVICE_TYPE type);

#endif //USB_MODE_H

