/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 * Filename:
 * ---------
 *   brom_usb_drv.c
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *	This is the common USB driver 
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 ****************************************************************************/
#include "brom_usb_drv.h"
#include "brom_u3_drv.h"


void brom_usb_init(void)
{
	/*initial USB PHY*/
	u3_phy_init();

	/*initial USB MAC Hardware*/
	u3_mac_hw_init();

	/*initial ACM related descriptor and ACM function configuration*/
	usb_acm_init();

	/*attach USB*/
	/*
	*	only skip disconnect when POR, 
	* 	otherwise, set disconnect to make sure disconnect and delay make host disconnect normally
	*/
	//if (RST_POR != rstctl_get_rst_type()) {
		//u3_set_disconnect();
	//}
	u3_set_connect();
}

void brom_usb_isr_handle(void)
{
	u3_isr_handler();
}

brom_usb_link_st_e brom_usb_get_link_st(void)
{
	brom_usb_link_st_e link_st = BROM_USB_LINK_OFF;

	/*handle usb isr when bootrom call this function*/
	u3_isr_handler();
	if (HIFUSB_STATE_CONFIG <= usb_get_protocol_st()) {
		link_st = BROM_USB_LINK_ON;
	}

	return link_st;	
}

kal_bool brom_usb_get_rx_data(kal_uint8 *recv_buf, kal_uint32 *p_len)
{
	/*handle usb isr when bootrom call this function*/
	u3_isr_handler();

	return hifusb_get_rx_data(recv_buf, p_len);
}
kal_bool brom_usb_send_tx_data(kal_uint8 *send_buf, kal_uint32 len)
{
	/*handle usb isr when bootrom call this function*/
	u3_isr_handler();

	return hifusb_send_tx_data(send_buf, len);
}

void brom_usb_deinit(void)
{
	hifusb_stop_all_acm_queue();
	u3_set_disconnect();
	u3_pwr_deinit();
}

void brom_usb_patch_pid_vid(kal_uint16 patch_pid, kal_uint16 patch_vid)
{
	usb_acm_patch_pid_vid(patch_pid, patch_vid);
}

