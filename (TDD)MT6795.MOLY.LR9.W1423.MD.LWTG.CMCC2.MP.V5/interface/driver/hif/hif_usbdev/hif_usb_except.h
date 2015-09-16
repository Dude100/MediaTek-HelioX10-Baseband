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
 *   hif_usb.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *	This is the USB exception handler driver API head file for both USB2.0/USB3.0.
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 ****************************************************************************/

#ifndef __HIF_USB_EXCEPT__
#define __HIF_USB_EXCEPT__

#include "hif_usb.h"

#define HIFUSB_EXCEPT_EP_BUF_SZ	2048

typedef struct _hifusb_except_cb {
    /*!
     *  @brief 	callback function while usb state changed (Exception Handler Only)
     *	@param	evt, the USB related event including USB bus event
     *	@param	*p_data, the information to inform upper driver,
     *			Currenlty, only the USB Speed mode(hifusb_usb_speed_e) when HIFUSB_NOTIFY_EVT_RESET
     */
    void    (*notify_usb_except_evt)(hifusb_notify_evt_e evt , void* p_data);
    /*!
     *  @brief 	callback function while control data in transfer SETUP packet
     *         	is received (Exception Handler Only)
     *	@param	p_setup, the SETUP request 8 byte data buffer
     *	@param	p_buf, the buffer which callback function shall fill data in
     *	@param	p_len, the expect IN data stage data length callback function shall fill
     *	@return	return STALL or not
     */
    hifusb_control_request_type_e (*notify_usb_except_control_in)(hifusb_setup_packet_t* p_setup, void *p_buf, kal_uint32 *p_len);
    /*!
     *  @brief callback function while control data out or no data transfer 
     *			data stage complete(Exception Handler Only)
     *	@param	p_setup, the SETUP request 8 byte data buffer
     *	@param	p_buf, the buffer which USB driver fill the recieved data in and callback function could parse
     *	@param	len, the recieved data length USB driver filled
	 *	@return	return STALL or not
     */
    hifusb_control_request_type_e (*notify_usb_except_control_out)(hifusb_setup_packet_t* p_setup, void *p_buf, kal_uint32 len);

}hifusb_except_cb_t;


/*!
 *	@brief	Change the channel configuration when exception happen
 *			Currently, system would only enumerate the ACM as logging and debug channel
 *			USB driver dettach and attach to re-enumerate
 *	@param	p_except_cb, all the callback function upper driver should register
*/
kal_bool hifusb_except_change_ch(hifusb_except_cb_t *p_except_cb);

/*!
 *	@brief	upper driver should use this function to set the USB deivce and each endpoint
 *			property and the parameters commented with Exception Mandatory are required.
 *	@param	p_property, the property of USB device and each endpoint
*/
kal_bool hifusb_except_set_property(hifusb_property_t *p_property);

/*!
 *	@brief	upper layer driver call this API to trigger USB related ISR handler
 *			The USB enumeration flow should use this function.
*/
void hifusb_except_poll_isr(void);

/*!
 *  @brief  ask usb hif driver to set control transfer type and status
 *			This is the USB exception handler internal used API, upper driver could ignore this API.
 *  @param  length          length of buffer to send, or to receive
 *  @param  type            send or receive or stall
 */
void hifusb_except_set_control_request(kal_uint32 length, hifusb_control_request_type_e type);
/*!
 *	@brief	upper layer driver set the address when received SET_ADDRESS command
 *	@param	address : the address host assigned
*/
void hifusb_except_set_usb_address(kal_uint8 address);
/*!
 *	@brief	upper layer driver set the configuration value when received SET_CONFIGURE command
 *	@param	configuration : the configure value host assigned
*/
void hifusb_except_set_usb_configuration(kal_uint8 configuration);

#endif
