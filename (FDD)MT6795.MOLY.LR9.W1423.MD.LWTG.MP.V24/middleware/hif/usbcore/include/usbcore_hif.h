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

/*******************************************************************************
 * Filename:
 * ---------
 *   usbcore_hif.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   USB Core HIF interface shared between normal and exception modes.
 *   One can tell the type of HIF interface from function name prefix:
 *      (1) usbc_normal_hif_xxx(): implementation for normal mode HIF.
 *      (2) usbc_core_xxx(): shared between normal mode and exception mode HIF.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                 HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _USBCORE_HIF_H
#define _USBCORE_HIF_H

#include "hif_usb.h"
#include "usbcore_main.h"

typedef kal_bool (*USBC_INDICATE_CONTROL_SETUP_PACKET)(kal_uint8 intf_idx, usbc_setup_packet_t *packet);
typedef void (*USBC_INDICATE_CONTROL_COMPLETE)(kal_uint8 intf_idx);
typedef void (*USBC_INDICATE_ALTERNATE_SETTING)(kal_uint8 intf_idx, kal_uint8 alternate_setting);
typedef void (*USBC_INDICATE_STALL)(kal_bool is_tx, kal_uint8 queue_idx, kal_bool stall);
typedef void (*USBC_SET_CONTROL_REQUEST)(kal_uint8* buffer, kal_uint32 length, usbc_control_request_type_e type);
typedef kal_bool (*USBC_SET_PROPERTY)(hifusb_property_t *p_property);
typedef kal_bool (*USBC_SET_USB_ADDRESS)(kal_uint8 address);
typedef kal_bool (*USBC_SET_USB_CONFIGURATION)(kal_uint8 configuration);
typedef void (*USBC_SET_STALL)(kal_bool is_tx, kal_uint8 nEnd);
typedef void (*USBC_CLEAR_STALL)(kal_bool is_tx, kal_uint8 nEnd);
typedef kal_bool (*USBC_SET_USB_TESTMODE)(hifusb_test_mode_e testmode);
typedef void (*USBC_SET_SS_DEV_INIT_U1_EN)(kal_bool);
typedef void (*USBC_SET_SS_DEV_INIT_U2_EN)(kal_bool);
typedef void (*USBC_SET_USBHIF_ADDRESS)(kal_uint8);
typedef void (*USBC_SET_UFBHIF_CONFIGURATION)(kal_uint8);
typedef kal_bool (*USBC_SET_USBHIF_CONNECT)(void);
typedef kal_bool (*USBC_SET_USBHIF_DISCONNECT)(void);
typedef kal_bool (*USBC_SET_USBHIFQ_GPD)(hif_queue_type_e, kal_uint8, qbm_gpd*, qbm_gpd*);

/*------------------------------------------------------------------------------
 * USB Core HIF interface shared between normal mode and exception mode.
 *----------------------------------------------------------------------------*/
/*!
 *  @brief indicate the setup packet up to specified USB CLASS interface.
 */
extern USBC_INDICATE_CONTROL_SETUP_PACKET usbc_core_indicate_control_setup_packet;

/*!
 *  @brief indicate the complete complete to specified USB CLASS interface.
 */
extern USBC_INDICATE_CONTROL_COMPLETE usbc_core_indicate_control_complete;

/*!
 *  @brief indicate the alternate setting set by host to specified interface.
 */
extern USBC_INDICATE_ALTERNATE_SETTING usbc_core_indicate_alternate_setting;

/*!
 *  @brief indicate the alternate setting set by host to specified interface.
 */
extern USBC_INDICATE_STALL usbc_core_indicate_stall;

/*!
 *  @brief write or read control transfer data buffer and status to hif driver
 */
extern USBC_SET_CONTROL_REQUEST usbc_core_set_control_request;

/*!
 *  @brief set USB device and endpoint related settings to hif driver
 */
extern USBC_SET_PROPERTY usbc_core_set_property;

/*!
 *  @brief update USB address to hif driver
 */
extern USBC_SET_USB_ADDRESS usbc_core_set_usb_address;

/*!
 *  @brief set usb configuration to hif driver
 */
extern USBC_SET_USB_CONFIGURATION usbc_core_set_usb_configuration;

/*!
 *  @brief set endpoint stall to hif driver
 */
extern USBC_SET_STALL usbc_core_set_stall;

/*!
 *  @brief clear endpoint stall to hif driver
 */
extern USBC_CLEAR_STALL usbc_core_clear_stall;

/*!
 *  @brief set test mode to hif driver
 */
extern USBC_SET_USB_TESTMODE usbc_core_set_usb_testmode;

/*!
 *  @brief enable U1 to hif driver
 */
extern USBC_SET_SS_DEV_INIT_U1_EN usbc_core_set_ss_dev_init_u1_en;

/*!
 *  @brief enable U2 to hif driver
 */
extern USBC_SET_SS_DEV_INIT_U2_EN usbc_core_set_ss_dev_init_u2_en;

/*!
 * @brief HIF API for setting address
 */
extern USBC_SET_USBHIF_ADDRESS usbc_core_set_usbhif_address; 

/*!
 * @brief HIF API for setting configuration
 */
extern USBC_SET_UFBHIF_CONFIGURATION usbc_core_set_usbhif_configuration; 

/*!
 * @brief HIF API for attaching to USB IP driver
 */
extern USBC_SET_USBHIF_CONNECT usbc_core_set_usbhif_connect;

/*!
 * @brief HIF API for deattaching to USB IP driver
 */
extern USBC_SET_USBHIF_DISCONNECT usbc_core_set_usbhif_disconnect;
 

/*!
 * @brief HIF QBM API for submit GPDs to USB QMU
 */
extern USBC_SET_USBHIFQ_GPD usbc_core_set_usbhifq_gpd;

#ifdef __USBCORE_DEBUG__
/*!
 *  @brief dump gpd content for debug purpose
 */
void usbc_core_dump_gpd_list(void* first_gpd, void* last_gpd);
#endif

/*!
 *  @brief fill up HIF IP dependent settings to hif driver
 */
kal_bool usbc_core_set_hif_configuration(void);

/*!
 *  @brief USB Core internal implementation to dispatch setup packet
 *  @param  pUsbCore USB Core context
 *  @param  p_setup setup packet to parse
 *  @return KAL_TRUE if it has been handled in this function;
 *          KAL_FALSE if it will be handled in task context later.
 */
kal_bool usbc_core_dispatch_control_setup_packet(usbc_core_t *pUsbCore, hifusb_setup_packet_t *p_setup);

/*!
 *  @brief USB Core internal implementation for control transfer complete post-processing 
 *  @param  pUsbCore USB Core context
 */
void usbc_core_notify_control_complete(usbc_core_t *pUsbCore);

/*!
 *  @brief Change USB speed and related descriptors.
 *  @param  pUsbCore USB Core context
 */
void usbc_core_speed_change(usbc_core_t *pUsbCore, usbc_usb_speed_e speed);


/*------------------------------------------------------------------------------
 * USB Core internal implementation for HIF normal mode.
 *----------------------------------------------------------------------------*/
/*!
 *  @brief ask hif driver to initiate
 */
kal_bool usbc_normal_hif_init(void);

/*!
 *  @brief ask hif driver to shutdown
 */
kal_bool usbc_normal_hif_shutdown(void);

/*!
 *  @brief ask hif driver to connect
 */
kal_bool usbc_normal_hif_connect(void);

/*!
 *  @brief ask hif driver to disconnect
 */
kal_bool usbc_normal_hif_disconnect(void);

/*!
 *  @brief ask hif driver to remote wakeup
 */
kal_bool usbc_normal_hif_remote_wakeup(void);
/*!
 *  @brief ask hif driver to send function wakeup notification
  */
kal_bool usbc_normal_hif_ss_wk_notify(kal_uint8 nInterface);

/*!
 *  @brief poll hif each queue to see if any data available
 */
void usbc_normal_hif_poll_queue(void);

/*!
 *  @brief Process indications queued in USBCORE task context
 */
void usbc_normal_hif_process_indications(void);

/*!
 *  @brief Fill up HIF function pointers with nomral mode HIF implementation
 */
void usbc_normal_hif_factory(void);

/*!
 *  @brief Fill up HIF function pointers with meta mode HIF implementation
 */
void usbc_meta_hif_factory(void);

/*!
 *  @breif Fill up HIF function pointers with USB suspended HIF implementation
 */
void usbc_suspended_hif_factory(void);

#ifdef ATEST_SYS_USBCORE
/*!
 *  @brief Fill up HIF function pointers with dummy HIF implementation
 */
void usbc_fake_hif_factory(void);
#endif

/*!
 *  @brief Emulate HIFUSB_NOTIFY_EVT_RESET, SetAddress, and SetConfiguration in META mode
 */
void usbc_normal_hif_meta_attach(void);

/*!
 *  @brief Check for reusing META COM
 */
kal_bool usbc_normal_hif_is_meta_reused(void);

/*!
 *  @brief Restore Buffered GPDs to hardware
 */
kal_bool usbc_normal_hif_restore_gpd_pwrsave(void);
#endif  // _USBCORE_HIF_H
