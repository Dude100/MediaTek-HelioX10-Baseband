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
*  A. Patent Notice:
*  The software delivered hereunder, including any and all updates and upgrades, 
*  might be subject to patent rights of standard-setting organizations, patent pools 
*  or their respective patent owners, that will be necessarily infringed by the use 
*  and distribution of the products incorporating all or part of this software.  
*  According to the licensing terms of these patent holders, it is your sole 
*  obligation to obtain the necessary patent licenses from these patent holders 
*  before you can use or distribute the products incorporating all or part of this 
*  software. MediaTek shall not be liable for your failure to obtain or maintain such 
*  licenses.
*  
*    As a courtesy to our customers, the following are some of the software that might 
*    contain such patent licenses, but MediaTek does not warrant the accuracy or
*    completeness of the information below.  
*    (1) MPEG4/AAC/AACPLUS/AACVPLUSV2: essential patents license must be obtained
*        from Via Licensing: <www.vialicensing.com>
*    (2) WAP/MMS security RC5 algorithm belongs to RSA Data Security: 
*        <www.rsasecurity.com> 
*    Notice: Please contact RSA to get this license before shipping the products to 
*    USA which include RC5 security algorithm.
*  
*  B. In addition, customers must contact the respective licensors to obtain 
*  necessary software licenses before it can use or distribute the licensed 
*  products. 
*  
*    As a courtesy to our customers, the following are some of the software licensers 
*    and the notice or disclaimer required by their licenses, but MediaTek does not 
*    warrant the accuracy or completeness of the information below.  
*    (1) Microsoft Windows Media (WMA software): 
*        Microsoft: <www.microsoft.com> 
*        Approved OEM Manufacturers: <wmlicense.smdisp.net/oem_approved/>
*        Sample Windows Media Licensing Agreements: 
*        <www.microsoft.com/windows/windowsmedia/licensing/agreements.aspx>
*    Notice in header or documentation: "This product is protected by certain 
*    intellectual property rights of Microsoft and cannot be used or further 
*    distributed without a license from Microsoft."
*    
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   usb_debug_tool.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file intends for usb common driver debug buffer definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __IC_USB_ENABLE__

#ifndef USB_DEBUG_TOOL_H
#define USB_DEBUG_TOOL_H

/***********************************************
	implement definition
************************************************/

#define ICUSB_DBG_DATA_SIZE   512

typedef enum
{
	IC_USB_DBG_SET_TXPKTREADY,
	IC_USB_SET_EVENT,
	IC_USB_RETRIEVE_EVENT,
	IC_USB_SUSSPEND_DEVICE,
	IC_USB_REMOTE_WAKEUP,
	IC_USB_REMOTE_WAKEUP_DONE,
	IC_USB_RESET,
	IC_USB_CONN,
	IC_USB_DISCONN,
	IC_USB_BABBLE,
	IC_USB_SESSREQ,	
	IC_USB_MASK_HISR,
	IC_USB_DBG_HISR,
	IC_USB_DMA_CALLBACK,
	IC_USB_CONN_AND_DISCONN,
	IC_USB_UNEXPECTED_EP0_INTR,
	IC_USB_UNEXPECTED_TX_INTR,
	IC_USB_EPN_RX_INTR,
	IC_USB_UNEXPECTED_RX_INTR,
	IC_USB_UNMASK_HISR,
	IC_USB_DMA_TIMEOUT_ERROR,
	IC_USB_EP0_INTR,
	IC_USB_EPN_TX_INTR,
	IC_USB_PN_RX_INTR,
	IC_USB_SEND_DATA_DONE,
	IC_USB_EP0_Setup,
	IC_USB_EP0_Data,	
	IC_USB_DMA_LISR,
	
#ifdef __IC_USB_EEM_SUPPORT__
	IC_USB_EEM_START,
	IC_USB_EEM_END,	
	IC_USB_EEM_RECEIVE,
	IC_USB_EEM_SEND,
	IC_USB_EEM_ClearRX,
	IC_USB_EEM_ClearTX,
	IC_USB_EEM_Resume,
	IC_USB_EEM_Suspend,
#endif	

#ifdef __IC_USB_ICCD_SUPPORT__
	IC_USB_ICCD_CTRL_EP_HDLR,
	IC_USB_ICCD_HDLR,
	IC_USB_ICCD_START,
	IC_USB_ICCD_END,	
	IC_USB_ICCD_POWER_ON,
	IC_USB_ICCD_POWER_OFF,	
	IC_USB_ICCD_DATA_TRANSFER,		
	IC_USB_ICCD_Already_POWER_ON,	
	IC_USB_ICCD_ERROR,
	IC_USB_ICCD_BUSY_WAIT,
	IC_USB_ICC_DATA_CMD,
	IC_USB_ICC_XFR_CMD,
	IC_USB_ICC_Power_ON_CMD,
	IC_USB_ICC_Power_OFF_CMD,
	IC_USB_ICC_SLOT_CMD,
	IC_USB_ICC_ENUMERATION_FAIL,
	IC_USB_ICC_RESET_DEVICE,
	IC_USB_ICC_SUSPEND,
	IC_USB_ICC_RESUME,
	IC_USB_ICC_STALL,
#endif		
	USB_DBG_MAX
}ICUSB_DBG_INFO;


/***********************************************
	Implement enum and structure
************************************************/

typedef struct
{
	ICUSB_DBG_INFO	tag;
	kal_uint32      time;
	kal_uint32      data1;
	kal_uint32      data2;
}ICUsb_Dbg_Data;


typedef struct
{
	ICUsb_Dbg_Data	dbg_data[ICUSB_DBG_DATA_SIZE];
	kal_uint16 	dbg_data_idx;
}ICUsb_Dbg_Struct;


/***********************************************
	function and global variable
************************************************/
extern void ICUSB_Dbg_Trace(ICUSB_DBG_INFO tag, kal_uint32 time, kal_uint32 data1, kal_uint32 data2);


#endif 
/* USB_DEBUG_TOOL_H */

#endif 

