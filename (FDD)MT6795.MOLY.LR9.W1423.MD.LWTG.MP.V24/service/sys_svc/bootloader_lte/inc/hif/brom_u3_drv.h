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
 *   brom_u3_drv.h
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *	This is the MT7208 USB3.0 driver header file
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 ****************************************************************************/
#ifndef __BROM_U3_DRV_H__
#define __BROM_U3_DRV_H__

#include "brom_u3mac_reg.h"
#include "brom_acm_drv.h"
#include "brom_bm.h"
//#include "brom_errno.h"
//#include "brom_uart_drv.h"


//#define USB_FPGA

#define USB_EP0_BUF_SZ	1024


#define HIFUSB_SS_EP0_MPS	(512)
#define HIFUSB_HS_EP0_MPS	(64)
#define HIFUSB_FS_EP0_MPS	(64)

/*
 * 	@brief 	U3/U2 selection flow definition 
 *			reference the U3 spec 10.16.2
*/
#define U3_INIT_RXDET_CNT		8
#define U3_RETRY_RXDET_CNT		1
#define U3_U2_SEL_DISABLE_CNT	3


typedef struct _u3_u2_sel_flow{
	kal_uint8 disable_cnt;
	kal_uint8 u2_reset_cnt;
}u3_u2_sel_flow_t;


typedef struct _u3_drv_priv {
	u3_u2_sel_flow_t u3_u2_sel_flow;
}u3_drv_priv_t;


/*!
 *  @brief hifusb_priv_t used to define the usb driver private information.
 */
typedef struct _hifusb_ep0_priv {
    /*!
     *  @brief ep0_request the buffer to receive the setup reqeust
     *			put infront of all to makt the buffer start pointer 4 byte align
     */
	hifusb_setup_packet_t	ep0_request;
	
    /*!
     *  @brief usb_state the usb status when operation
     */
	hifusb_ep0_state_e	usb_ep0_st;

    /*!
     *  @brief ep0_in_buf, the buffer pointer of the buffer for EP0 DATAIN stage
     */
	kal_uint8			*ep0_datain_buf;

    /*!
     *  @brief ep0_out_buf, the buffer pointer of the buffer EP0 DATAOUT stage
     */
	kal_uint8			*ep0_dataout_buf;

    /*!
     *  @brief ep0_datain_len, the expect length of the buffer for EP0 DATAIN stage
     */
	kal_uint32			ep0_datain_len;

    /*!
     *  @brief ep0_dataout_len, the expect length of the buffer for EP0 DATAOUT stage
     */
	kal_uint32			ep0_dataout_len;

    /*!
     *  @brief ep0_data_len_idx, used to handle DATAIN / DATAOUT transfer buffer pointer 
     *			in several interrupt handles
     */
	kal_uint32			ep0_data_len_idx;

    /*!
     *  @brief ack_pend, recorded CRS0 pending ack behavior
     */
	kal_uint16			csr0_ack_pend;
	
    /*!
     *  @brief update_dev_addr, hifusb_set_usb_address() would update new addres to libdrv_hif
     *			libdrv_hif should update the address to register and clear after update addr register
     */
	kal_uint8			update_dev_addr;

    /*!
     *  @brief testmode, hifusb_set_usb_testmode() would update test mode
     *			libdrv_hif should execute the test mode after the SET_FEATURE end
     */
	hifusb_test_mode_e	testmode;

} hifusb_ep0_priv_t;

/*!
 *  @brief hifusb_statistic is used to record the current usb information
 			configured from upper layer driver or host side.
 */
typedef struct _hifusb_statistic {
    /*!
     *  @brief usb_val_addr is used to record currently host set address value
     */
	kal_uint32	usb_val_addr;

    /*!
     *  @brief usb_val_config is used to record currently host set configure value
     */
	kal_uint32	usb_val_config;

    /*!
     *  @brief usb_cur_speed is used to record current usb operation speed
     */
	hifusb_usb_speed_e	usb_cur_speed;

} hifusb_statistic_t;

/*!
 *  @brief EndpointResource is the information each EP needs
 */
typedef struct
{
    kal_uint8               	nEnd;
    hifusb_usb_xfer_type_e		type;
	kal_uint8					MutiFifoU3Burst;		/*U2 Mutli Fifo or U3 Burst Count*/
	kal_uint8					reserve;
    kal_uint32                	MaxPacketSize;			/* Bytes */
} EndpointResource;


/*!
 *  @brief hifusb_priv_t used to define the usb driver private information.
 */
typedef struct _hifusb_priv {
    /*!
     *  @brief ep0_priv , the variable to maintain EP0 related state machine 
     *				and to record ep0 information
     */
	hifusb_ep0_priv_t	ep0_pirv;

    /*!
     *  @brief usb_state the usb status when operation
     */
	hifusb_state_e		usb_state;

	/*!
	 *	@brief usb_statistic is used to record currently usb operate information
	 */
	 hifusb_statistic_t	usb_statistic;

	/*!
	 *	@brief USB3.0 control information 
	 */
	u3_drv_priv_t		u3_drv_priv;

    /*!
     *  @ep0_config , the EP0 dynamic configuration, MPS
     */
	EndpointResource	ep0_config;

    /*!
     *  @brief tx_ep_config, the actual tx ep configure values
     */
	EndpointResource	tx_ep_config[USB_ACM_IN_EP_NUM];

    /*!
     *  @brief rx_ep_config, the actual rx ep configure values
     */
	EndpointResource	rx_ep_config[USB_ACM_OUT_EP_NUM];
	
} hifusb_priv_t;

/*!
*  @brief  translate the endpoint number to queue number
*  @param  nEnd        endpoint number
*/
#define HIFUSB_EPNO_2_QNO(nEnd)	(nEnd - 1)



kal_uint32 u3_phy_init(void);
void u3_mac_hw_init(void);
void u3_set_connect(void);
void u3_set_disconnect(void);
void u3_isr_handler(void);
kal_bool hifusb_get_rx_data(kal_uint8 *recv_buf, kal_uint32 *p_len);
kal_bool hifusb_send_tx_data(kal_uint8 *send_buf, kal_uint32 len);
hifusb_state_e usb_get_protocol_st(void);
void hifusb_stop_all_acm_queue(void);
void u3_pwr_deinit(void);

#endif
