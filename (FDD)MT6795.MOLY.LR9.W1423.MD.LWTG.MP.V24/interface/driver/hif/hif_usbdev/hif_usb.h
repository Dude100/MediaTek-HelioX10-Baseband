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
 *   hif_usb.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *	This is the USB driver API head file for both USB2.0/USB3.0.
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * . add ip layer power save handle for upper layer driver use when gate all tx/rx
 *
 * removed!
 * removed!
 * . add call back handle for reset from suspend case without u3 ip link interrupt
 *
 * removed!
 * removed!
 * .add dev request U1/U2 and function remote wakeup notfiy for usb driver
 *
 * removed!
 * removed!
 * .modify project name as MT6290 and change all comment or log for new model name
 *
 * removed!
 * removed!
 * .Merge MSBB latest code of USB2.0/USB3.0 to Moly trunk
 ****************************************************************************/

#ifndef __HIF_USB_H__
#define __HIF_USB_H__

#include "kal_public_api.h"

/*!
 *	@brief	define the USB EP0 standard field
*/
/* EP0 data stage direction */
#define HIFUSB_DIR_MASK		(0x80)
#define HIFUSB_DIR_OUT		(0)
#define HIFUSB_DIR_IN		(0x80)



#define HIFUSB_SS_EP0_MPS	(512)
#define HIFUSB_HS_EP0_MPS	(64)
#define HIFUSB_FS_EP0_MPS	(64)

/*!
 *  @brief hifusb_notify_evt_e enumerate possible states of usb device
 *  @param HIFUSB_NOTIFY_EVT_MIN           	pseudo state
 *  @param HIFUSB_NOTIFY_EVT_ATTACHED      	attach to usb bus
 *  @param HIFUSB_NOTIFY_EVT_DETACHING     	start detaching from usb bus
 *  @param HIFUSB_NOTIFY_EVT_DETACHED      	detach from usb bus already
 *  @param HIFUSB_NOTIFY_EVT_SUSPENDING    	start suspending
 *  @param HIFUSB_NOTIFY_EVT_SUSPENDED     	suspend already
 *  @param HIFUSB_NOTIFY_EVT_RESUME        	recevie usb resume signal
 *  @param HIFUSB_NOTIFY_EVT_RESET         	recevie usb bus reset
 *  @param HIFUSB_NOTIFY_EVT_MAX           	pseudo state
 */
typedef enum _hifusb_notify_evt {
    HIFUSB_NOTIFY_EVT_MIN			= 0,
    HIFUSB_NOTIFY_EVT_ATTACH		= 1,
    HIFUSB_NOTIFY_EVT_DETACH		= 2,
    HIFUSB_NOTIFY_EVT_SUSPEND		= 3,
    HIFUSB_NOTIFY_EVT_RESUME		= 4,
    HIFUSB_NOTIFY_EVT_RESET			= 5,
    HIFUSB_NOTIFY_EVT_MAX			= 6,
} hifusb_notify_evt_e;


/*!
 *  @brief hifusb_state_e enumerate possible states of usb device
 *  @param HIFUSB_STATE_MIN				pseudo state
 *  @param HIFUSB_STATE_PWROFF			USB initial state , before VBUS valid
 *  @param HIFUSB_STATE_PWRON			after VBUS valid , before attach
 *  @param HIFUSB_STATE_ATTACHED     	after attach, before USB reset
 *  @param HIFUSB_STATE_DEFAULT      	after USB reset , this is the default normal state
 *  @param HIFUSB_STATE_ADDR      		after USB reset and set address 
 *  @param HIFUSB_STATE_CONFIG      	after set address and set configure
 *  @param HIFUSB_STATE_SUSPENDED     	after default state and stay in suspend
 *  @param HIFUSB_STATE_RESUME      	when receive resume, return to default immediately
 *  @param HIFUSB_STATE_MAX    			psuduo state
 */
typedef enum _hifusb_state {
    HIFUSB_STATE_MIN		 = 0,
    HIFUSB_STATE_PWROFF,
    HIFUSB_STATE_PWRON,
    HIFUSB_STATE_ATTACHED,
    HIFUSB_STATE_NEW_RST,
    HIFUSB_STATE_DEFAULT,
    HIFUSB_STATE_ADDR,
    HIFUSB_STATE_CONFIG,
    HIFUSB_STATE_SUSPENDED,
    HIFUSB_STATE_RESUME,
    HIFUSB_STATE_LPM_SUSPEND,
    HIFUSB_STATE_MAX,
} hifusb_state_e;

/*!
 *  @brief hifusb_usb_speed_e enumerate possible speed of usb device
 *  @param HIFUSB_USB_SPEED_MIN           pseudo speed
 *  @param HIFUSB_USB_SPEED_USB11         usb 1.1 full speed
 *  @param HIFUSB_USB_SPEED_USB20         usb 2.0 high speed
 *  @param HIFUSB_USB_SPEED_USB30         usb 3.0 super speed
 *  @param HIFUSB_USB_SPEED_MAX           pseudo speed
 */
typedef enum hifusb_usb_speed {
    HIFUSB_USB_SPEED_MIN                  = 0,
    HIFUSB_USB_SPEED_USB11                = 1,
    HIFUSB_USB_SPEED_USB20                = 2,
    HIFUSB_USB_SPEED_USB30                = 3,
    HIFUSB_USB_SPEED_MAX                  = 4,
} hifusb_usb_speed_e;


/*!
 *  @brief hifusb_request_owner_e enumerate all possible types of usb control
 *         request type
 *  @param HIFUSB_CONTROL_REQUEST_TYPE_MIN        	pseudo type
	@param HIFUSB_CONTROL_REQUEST_TYPE_NODATA		request no data
 *  @param HIFUSB_CONTROL_REQUEST_TYPE_SEND       	request to send, Device->Host
 *  @param HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE    	request to receive, Host->Device
 *  @param HIFUSB_CONTROL_REQUEST_TYPE_STALL      	request to stall
 *  @param HIFUSB_CONTROL_REQUEST_TYPE_MAX        	pseudo type
 */
typedef enum _hifusb_control_request_type {
    HIFUSB_CONTROL_REQUEST_TYPE_MIN       	= 0,
    HIFUSB_CONTROL_REQUEST_TYPE_SEND      	= 1,
    HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE   	= 2,
    HIFUSB_CONTROL_REQUEST_TYPE_STALL     	= 3,
    HIFUSB_CONTROL_REQUEST_TYPE_MAX       	= 4,
} hifusb_control_request_type_e;


/*!
 *  @brief hifusb_hw_info_t is used to record the USB IP information
 */
typedef struct _hifusb_hw_info{
    /*!
     *  @brief usb_hw_ver is the hardware USB IP version
     */
	kal_uint8 	usb_hw_ver;
    /*!
     *  @brief usb_hw_subver is the hardware USB IP subversion
     */
	kal_uint8	usb_hw_subver;
    /*!
     *  @brief usb20_drc_ip_valid ,presents that USB2.0 Dual-Role IP valid
     */
	kal_bool	usb20_drc_ip_valid;
    /*!
     *  @brief usb30_dev_ip_valid ,presents that USB3.0 device IP valid
     */
	kal_bool	usb30_dev_ip_valid;
    /*!
     *  @brief usb_max_speed , presents that current max usb speed supported
     */
	hifusb_usb_speed_e	usb_max_speed;
    /*!
     *  @brief hub_hw_support presents that if the HUB supported in host mode
     */
	kal_bool	hub_hw_support;
    /*!
     *  @brief qmu_hw_support presents that if the QMU supported
     */
	kal_bool	qmu_hw_support;
    /*!
     *  @brief usb_hw_outepnum presents the hardware OUT EP numbers
     */
	kal_uint8	usb_hw_outepnum;
    /*!
     *  @brief usb_hw_inepnum presents the hardware IN EP numbers
     */
	kal_uint8	usb_hw_inepnum;
    /*!
     *  @brief usb_hw_dmachnum presents the hardware DMA channel numbers
     */
	kal_uint8	usb_hw_dmachnum;
    /*!
     *  @brief usb_hw_fifo_sz presents the hardware dynamic fifo size in bytes
     */
	kal_uint32	usb_hw_fifo_sz;
    /*!
     *  @brief usb_hw_fifo_sz presents the hardware dynamic fifo size in bytes
     */
	kal_uint32	usb_hw_ep0_fifo_sz;
    /*!
     *  @brief usb_hw_fifo_sz presents the hardware dynamic fifo size in bytes
     */
	kal_uint32	usb_hw_in_fifo_sz;
    /*!
     *  @brief usb_hw_fifo_sz presents the hardware dynamic fifo size in bytes
     */
	kal_uint32	usb_hw_out_fifo_sz;
    /*!
     *  @brief usb_reg_config_data presents the hardware register of CONFIGDATA.
     */
	kal_uint16	usb_reg_config_data;
} hifusb_hw_info_t;

/*!
 *  @brief hifusb_setup_packet_t describe the detail field definition of
 *         control setup packet
 */
typedef struct _hifusb_setup_packet {
    /*!
     *  @brief request type of setup packet
     *         Bit 7: Request direction
     *                (0=Host to device - Out, 1=Device to host - In)
     *         Bits 5-6: Request type
     *                (0=standard, 1=class, 2=vendor, 3=reserved)
     *         Bits 0-4: Recipient
     *                (0=device, 1=interface, 2=endpoint,3=other)
     */
    kal_uint8           bmRequestType;
    /*!
     *  @brief the actual request, see the Standard Device Request Codes table
     */
    kal_uint8           bRequest;
    /*!
     *  @brief a word-size value that varies according to the request
     */
    kal_uint16          wValue;
    /*!
     *  @brief a word-size value that varies according to the request,
     *         the index is generally used to specify an endpoint or
     *         an interface.
     */
    kal_uint16          wIndex;
    /*!
     *  @brief a word-size value that indicates the number of bytes to be
     *         transferred if there is a data stage
     */
    kal_uint16          wLength;
} hifusb_setup_packet_t;


/*!
 *  @brief used to record the bootup information for power saving power down or watchdog reset
 */
typedef enum _hifusb_boot_type {
	HIFUSB_BOOT_PWRON_RST = 0,
	HIFUSB_BOOT_SUSPEND,
	HIFUSB_BOOT_UNKNOWN = 255,
} hifusb_boot_type_e;

/*!
 *  @brief used to record the bootup information for power saving power down or watchdog reset
 */
typedef struct _hifusb_boot_info {
	hifusb_boot_type_e	boot_type;
	hifusb_usb_speed_e	usb_speed; 
	kal_uint8			usb_addr;
	kal_uint8			usb_config_val;
} hifusb_boot_info_t;


/*the max ep number of USB spec*/
#define HIFUSB_USB_MAX_EP_NUM	15

/*!
 *  @brief hifusb_usb_xfer_type enumerate all possible types of  USB
 *         transfer type
 *  @param HIFUSB_EP_XFER_TYPE_MIN          pseudo type
 *  @param HIFUSB_EP_XFER_TYPE_CONTROL      Control Transfer
 *  @param HIFUSB_EP_XFER_TYPE_ISOC      	Isochronous Transfer
 *  @param HIFUSB_EP_XFER_TYPE_BULK     	Bulk Transfer
 *  @param HIFUSB_EP_XFER_TYPE_INT     		Interrupt Out Transfer
 *  @param HIFUSB_EP_XFER_TYPE_MAX          pseudo type
 */
typedef enum _hifusb_usb_xfer_type {
	HIFUSB_EP_XFER_TYPE_MIN = 0,
	HIFUSB_EP_XFER_TYPE_CONTROL,
	HIFUSB_EP_XFER_TYPE_ISOC,
	HIFUSB_EP_XFER_TYPE_BULK,
	HIFUSB_EP_XFER_TYPE_INT,
	HIFUSB_EP_XFER_TYPE_MAX
}hifusb_usb_xfer_type_e;

/*!
 *  @brief hifusb_test_mode , the test mode which host expect, 
 *			the number sync the USB2.0 Test Mode Selector
 *			The test mode only used in USB2.0 transfer
 */
typedef enum _hifusb_test_mode {
	HIFUSB_HSET_NONE = 0,
	HIFUSB_HSET_TEST_J,
	HIFUSB_HSET_TEST_K,
	HIFUSB_HSET_TEST_SE0_NAK,
	HIFUSB_HSET_TEST_PACKET,
}hifusb_test_mode_e;

#define HIFUSB_MAX_QUE_NUM		15

/*
 *	bit-map of hifusb_property.qmu_config (32bits) for global qmu configuration
*/
#define HIFUSB_QMU_CS16		(0x1 << 0)

/*
 *	bit-map of hifusb_qmu_queue.config (32bits) for per-queue configuration
*/
#define HIFUSB_QMU_EN			(0x1 << 0) // set 1 for qmu enable , set 0 for dma mode
#define HIFUSB_QMU_CS_EN		(0x1 << 1)
#define HIFUSB_QMU_RXQ_ZLP		(0x1 << 2)
#define HIFUSB_QMU_TXQ_ZLP		(0x1 << 3)
#define HIFUSB_QMU_TXQ_EMPTY_ENQ	(0x1 << 4)


/*!
 *  @brief hifusb_qmu_queue_t describe per QMU-queue property that usbcore
 *         will set into usb hif driver
 */
typedef struct _hifusb_qmu_queue {
    /*!
     *  @brief endpoint number of this queue
     */
    kal_uint8               ep_no;
    /*!
     *  @brief queue number , shall always be ep_no-1
     */
    kal_uint8               que_no;
    /*!
     *  @brief endpoint type of this queue
     */
    hifusb_usb_xfer_type_e   type;
    /*!
     *  @brief request fifo type of this queue is DOUBLE FIFO or not
     */
    kal_bool                double_fifo;
    /*!
     *  @brief queue configuration
     */
    kal_uint32               config;
    /*!
     *  @brief maximun packet size of this queue
     */
    kal_uint16              max_packet_size;
    /*!
     *  @brief allocate the FIFO count for this queue and also imply the U3 burst number
     *			if upper module set 0, the FIFO count is depended on the double_fifo setting
     */
    kal_uint8                u2_fifo_u3_burst;
    /*!
     *  @brief reserve for 4 byte align
     */
	kal_uint8				reserve[1];
} hifusb_qmu_queue_t;



/*!
 *  @brief hifusb_property_t describe the property parameters that
 *         usbcore will set into usb hif driver
 *	Note : The the components commented with exception are mandatory for exception configuration
 */
typedef struct _hifusb_property {
    /*!
     *  @brief desired usb speed
     */
    hifusb_usb_speed_e    speed;
    /*!
     *  @brief total RX QMU queues requested to configure
     *	Note : Exception Mandatory
     */
    kal_uint8           rxq_num;
    /*!
     *  @brief total TX QMU queues requested to configure
     *	Note : Exception Mandatory
     */
    kal_uint8           txq_num;
    /*!
     *  @brief reserve for 4 bytes alignment
     */
    kal_uint8           reserve[1];    
    /*!
     *  @brief QMU global configuration
     */
    kal_uint32           qmu_config;
    /*!
     *  @brief QMU per queue property
     *	Note : Exception Mandatory
     */
    hifusb_qmu_queue_t    rx_que[HIFUSB_USB_MAX_EP_NUM];
    /*!
     *  @brief QMU per queue property
     *	Note : Exception Mandatory
     */
    hifusb_qmu_queue_t    tx_que[HIFUSB_USB_MAX_EP_NUM];
    /*!
     *  @brief callback function while usb state changed
     */
    void    (*notify_usb_evt)(hifusb_notify_evt_e evt , void* p_data);
    /*!
     *  @brief callback function while control tranfer happens for this device
     *         is received
     *	@return KAL_TRUE if the control transfer has been handled in this callback function;
     *          KAL_FALSE if the control transfer will be handled in task context later.
     */
    kal_bool (*notify_control_setup_packet)(hifusb_setup_packet_t* p_setup);
    /*!
     *  @brief callback function while control tranfer is complete
     */
    void    (*notify_control_complete)();
} hifusb_property_t;


/*!
 *  @brief  initialize usb hif driver, must call hifusb_init() and hifusb_set_property()
 *			to finish the initialization before hifusb_set_connect()
 *	@param	usb_max_speed , the max speed upper driver wanted
 *	@return KAL_TRUE if initial success , 
 			KAL_FALSE if initial failure, or the speed don't match currently hardware
 */
kal_bool hifusb_init(hifusb_usb_speed_e usb_max_speed);

/*!
 *  @brief  ask usb hif driver to set this property
 *  @param  property    the property usbcore will set
 *  @return KAL_TRUE if the property can be satisfied, otherwise KAL_FALSE
 */
kal_bool hifusb_set_property(hifusb_property_t* p_property);

/*!
 *  @brief  ask usb hif driver to connect to Host
 *	@return KAL_TRUE if all settting correct , KAL_FALSE if setting not incorrect
 */
kal_bool hifusb_set_connect(void);

/*!
 *  @brief  ask usb hif driver to disconnect from Host
 *	@return KAL_TRUE if success , KAL_FALSE if fail
 */
kal_bool hifusb_set_disconnect(void);

/*!
 *  @brief  ask usb hif driver to set control transfer type and status in HISR context
 *  @param  buffer          pointer to byte array to send or receive data
 *  @param  length          length of buffer to send, or to receive
 *  @param  type            send or receive or stall
 */
void hifusb_set_control_request_in_hisr(kal_uint8* buffer, kal_uint32 length, hifusb_control_request_type_e type);

/*!
 *  @brief  ask usb hif driver to set control transfer type and status in task context
 *  @param  buffer          pointer to byte array to send or receive data
 *  @param  length          length of buffer to send, or to receive
 *  @param  type            send or receive or stall
 */
void hifusb_set_control_request_in_task(kal_uint8* buffer, kal_uint32 length, hifusb_control_request_type_e type);

/*!
 *  @brief  ask usb hif driver to set usb address into USB IP
 *  @param  address         address to be set
 */
void hifusb_set_usb_address(kal_uint8 address);


/*!
 *  @brief  inform usb hif driver that set configuration standard request has
 *          been received
 *  @param  configuration   configuration to be set
 */
void hifusb_set_usb_configuration(kal_uint8 configuration);

/*!
 *  @brief  configure the test mode when upper layer driver receive the 
 *			SetFeature with the Test Mode selector
 *  @param  testmode   the test parsed from the ep0 request command
 *	@return	KAL_TRUE when the ep0 stage and USB2.0 transfer , KAL_FALSE fail
 */
kal_bool hifusb_set_usb_testmode(hifusb_test_mode_e testmode);


/*!
 *  @brief  shutdown usb hif driver, detach LISR/HISR , detach USB ,shut USB PHY
 *			need to re-initial usb driver after shut down
 */
void hifusb_shutdown(void);

/*!
 *  @brief  record and log the usb ip hardware information.
 *  @param  p_hw_inof , used to record the hw info 
 */
void hifusb_get_hw_info(hifusb_hw_info_t* p_hw_info);

/*!
*  @brief  ask usb hif driver to set endpoint STALL for specified endpoint and queue
*			stop queue, set ep stall, flush fifo , record current GPD pointer
*  @param  is_tx	KAL_TRUE for tx (IN)ep , KAL_FALSE for rx (OUT)ep
*  @param  nEnd		endpoint number descript in ep0 request command
*/
void hifusb_set_stall(kal_bool is_tx, kal_uint8 nEnd);


/*!
*  @brief  ask usb hif driver to clear endpoint STALL for specified endpoint and queue
*			restore queue, start queue , clear stall
*  @param  is_tx	KAL_TRUE for tx (IN)ep , KAL_FALSE for rx (OUT)ep
*  @param  nEnd        endpoint number descript in ep0 request command
*/
void hifusb_clear_stall(kal_bool is_tx ,kal_uint8 nEnd);


/*!
*  @brief  flush the USB FIFO of specific queue endpoint
*  @param  is_tx	KAL_TRUE for tx (IN)ep , KAL_FALSE for rx (OUT)ep
*  @param  nEnd        endpoint number descript in ep0 request command
*/
void hifusb_flush_fifo(kal_bool is_tx, kal_uint8 q_num);


/*!
 * 	@brief  use this API to trigger USB device send remote wakeup signal to host
 *			upper driver should wait resume event callback to confirm the resume flow completed
 *	@return	KAL_TRUE: success, KAL_FALSE: failure
*/
kal_bool hifusb_remote_wakeup(void);

/*!
 * 	@brief  use this API to trigger USB device send LPM remote wakeup signal to host
 *			upper driver should wait resume event callback to confirm the resume flow completed
 *	@return	KAL_TRUE: success, KAL_FALSE: failure
*/
kal_bool hifusb_lpm_remote_wakeup(void);

/********************************************************
	USB SUSPEND power down reboot related flow and API Note
*********************************************************
		When USB SUSPEND power down issued on MT6290, whole system
	will reboot with USB IP non-reset state.
		USB low layer driver and high layer driver should emulate some 
	USB enumeration flow to make the software state sync current
	hardware state.
		Upper layer driver should follow following flow to emulate.
 	1. hifusb_init()
	2. hifusb_get_boot_info() 
	==> if the boot_type == HIFUSB_BOOT_SUSPEND plz issue follow steps
	==> upper driver should not hifusb_set_connect(), hifusb_set_disconnect()
 	3. hifusb_reset_isr_emulate() 
 	4. hifusb_set_property_emulate()
 	5. hifusb_set_usb_address_emulate()
 	6. hifusb_set_usb_configuration_emulate()	
*********************************************************/
/*!
 * 	@brief 	use this function to get boot information to check if system boot from
 *			SUSPEND power down
 *	@param	p_boot_info, the variable to return the boot information
*/
void hifusb_get_boot_info(hifusb_boot_info_t *p_boot_info);

/*!
 * 	@brief  this function is used to emulate reset interrupt function for boot from suspend case
 *			usb driver will set private software state for link up state
*/
void hifusb_reset_isr_emulate(void);

/*!
 * 	@brief  upper driver should configure the correct property with to speed mode
 *			info in the boot info get by hifusb_get_boot_info().
 *	@param	p_property, the property to configure by speed mode
 *	@return KAL_TRUE: success, KAL_FALSE : failure
*/
kal_bool hifusb_set_property_emulate(hifusb_property_t* p_property);

/*!
 * 	@brief  upper driver set emulate set address flow with the address in the boot info
 *			got by hifusb_get_boot_info()
 *	@param	address, the current address
*/
void hifusb_set_usb_address_emulate(kal_uint8 address);

/*!
 * 	@brief  upper driver set emulate set configure flow with the configuration value in the boot info
 *			got by hifusb_get_boot_info()
 *	@param	configuration, the current configuration value
*/
void hifusb_set_usb_configuration_emulate(kal_uint8 configuration);

/*!
 *  @brief  used to enable/disable device auto request enter U1 state
 *  @param  is_en, KAL_TRUE : enable , KAL_FALSE : disable
 */
void hifusb_ss_dev_init_u1_en(kal_bool is_en);

/*!
 *  @brief  used to enable/disable device auto request enter U2 state
 *  @param  is_en, KAL_TRUE : enable , KAL_FALSE : disable
 */
void hifusb_ss_dev_init_u2_en(kal_bool is_en);

/*!
 *	@brief	send device function wakeup notify after remote wakeup issued
 *	@param	if_num, the interface number which trigger remote wakeup in supre-speed
 *	@return	KAL_TRUE is success, KAL_FALSE is failure
*/
kal_bool hifusb_ss_func_wk_notify(kal_uint8 if_num);

/*!
 *  @brief  suspend IP layer power save flow
 *			this function will make access IP register hang because IP clock off
 *			usbcore create a very low prioriy task to issue this function after gate all set/poll gpd instants
 */
void hifusb_suspend_done_handle(void);


/*MACRO for USB EP/QUE operation*/

/*!
*  @brief  translate the endpoint number to queue number
*  @param  nEnd        endpoint number
*/
#define HIFUSB_EPNO_2_QNO(nEnd)	(nEnd - 1)

#endif
