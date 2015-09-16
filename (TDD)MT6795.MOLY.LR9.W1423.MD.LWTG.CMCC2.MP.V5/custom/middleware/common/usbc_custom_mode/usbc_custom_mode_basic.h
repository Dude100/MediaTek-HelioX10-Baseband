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
 *   usbc_custom_mode_basic.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _USBC_CUSTOM_MODE_BASIC_H_
#define _USBC_CUSTOM_MODE_BASIC_H_

/*
#define _USB_MODE_TEMPLATE \
        {   PID, \
            DEVICE_ID, SUBCLASS, PROTOCOL_CODE, \
            CONFIG_NUMBER, \
            { \
                { \
                    CLASS_DEVICE_NUMBER, \
                    {CLASS_TYPE}, \
                    {(void*)CONTEXT}, \
                    {DATA_IN_DOUBLE_FIFO_ON|DATA_OUT_DOUBLE_FIFO_ON} \
                } \
            } \
        }
*/

// Applicaton COM only is one of the simplest mode
#define _USBMODE_APP_COM_ONLY \
        {   0x7101, \
            0xEF, 0x02, 0x01, \
            1, \
            { \
                { 1, {USB_CLASS_ACM2}, \
                     {(void*)uart_port_usb}, \
                     {DATA_IN_DOUBLE_FIFO_ON|DATA_OUT_DOUBLE_FIFO_ON} } \
            } \
        }


// Debug COM only is one of the simplest mode
#define _USBMODE_DBG_COM_ONLY \
        {   0x7101, \
            0xEF, 0x02, 0x01, \
            1, \
            { \
                { 1, {USB_CLASS_ACM2}, \
                     {(void*)uart_port_usb2}, \
                     {DATA_IN_DOUBLE_FIFO_ON|DATA_OUT_DOUBLE_FIFO_ON} } \
            } \
        }

// BOOTROM COM for META reused
#define _USBMODE_BOOTROM_COM \
        {   0x0003, \
            0x02, 0x00, 0x00, \
            1, \
            { \
                { 1, {USB_CLASS_ACM2}, \
                     {(void*)uart_port_usb2}, \
                     {DATA_IN_DOUBLE_FIFO_ON|DATA_OUT_DOUBLE_FIFO_ON} } \
            } \
        }

// 1R2C is used for legacy
#if ( (defined(__MODEM_CCCI_EXIST__) && !defined(__MODEM_CARD__)) || (defined(MT6595)) || (defined(MT6752) && defined(__MD1__)) || !defined(__USB_RNDIS_SUPPORT__) )
    #define _USBMODE_LEGACY_1R2C _USBMODE_DBG_COM_ONLY
#else
    #define _USBMODE_LEGACY_1R2C \
        {   0x7102, \
            0xEF, 0x02, 0x01, \
            1, \
            { \
                { 3, {USB_CLASS_RNDIS, USB_CLASS_ACM2, USB_CLASS_ACM2}, \
                     {(void*)0x100, (void*)uart_port_usb, (void*)uart_port_usb2}, \
                     {(DATA_IN_DOUBLE_FIFO_ON|DATA_OUT_DOUBLE_FIFO_ON), (DATA_IN_DOUBLE_FIFO_ON|DATA_OUT_DOUBLE_FIFO_ON), (DATA_IN_DOUBLE_FIFO_ON|DATA_OUT_DOUBLE_FIFO_ON)} } \
            } \
        }
#endif

#endif 
