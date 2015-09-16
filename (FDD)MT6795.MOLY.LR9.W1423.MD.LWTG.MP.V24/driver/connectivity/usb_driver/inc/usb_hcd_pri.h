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
 *    usb_hcd_pri.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file intends for usb host hardware related function definitions. Only use for hardware driver.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef USB_HCD_PRI_H
#define USB_HCD_PRI_H

#include "usb_drv.h"
//#include "usb_drv_pri.h"
#include "usb_custom.h"
#include "usb_hw.h"
#include "dcl.h"
//#include "kal_non_specific_general_types.h"
//#include "usb_hcd.h"

#define  USB_HCD_DEBOUNCE_DELAY			(10)	 /* 10ms unit */
#define  USB_HCD_RESET_RECOVERY_DELAY	(1)
#define  USB_HCD_RESET_DELAY			(6)
#define  USB_HCD_RESUME_DELAY			(2)  //20ms
#define  USB_HCD_DMA_TIMER					(500)

#if defined (DRV_USB_IP_V3)

#define USBHCD_DMA_CheckRunStat(_baseaddr,_n)		(USB_DRV_Reg(USB_DMACNTL_HCD(_baseaddr,_n))&USB_DMACNTL_DMAEN)
#define USBHCD_DMA_CheckPPRunStat(_baseaddr,_n)			(USB_DRV_Reg(USB_DMAPPCNTL_HCD(_baseaddr,_n))&USB_DMACNTL_DMAEN)
#define USBHCD_DMA_Stop(_baseaddr,_n)					USB_DRV_ClearBits(USB_DMACNTL_HCD(_baseaddr,_n), USB_DMACNTL_DMAEN)

#define  USB_HCD_DMA_TX_CSR		(USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE)
#define  USB_HCD_DMA_TX_CSR_ISO	(USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE|USB_TXCSR_ISO)

#define  USB_HCD_DMA_RX_CSR		(USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB|USB_RXCSR_AUTOREQ)
#define  USB_HCD_DMA_RX_CSR_ISO	(USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB|USB_RXCSR_AUTOREQ|USB_RXCSR_ISO)


#elif defined (DRV_USB_IP_V4)

#define USBHCD_DMA_CheckRunStat(_baseaddr,_n)		(USB_DRV_Reg(USB_DMACNTL_HCD(_baseaddr,_n))&USB_DMACNTL_DMAEN)
#define USBHCD_DMA_CheckPPRunStat(_baseaddr,_n)			(USB_DRV_Reg(USB_DMAPPCNTL_HCD(_baseaddr,_n))&USB_DMACNTL_DMAEN)
#define USBHCD_DMA_Stop(_baseaddr,_n)					USB_DRV_ClearBits(USB_DMACNTL_HCD(_baseaddr,_n), USB_DMACNTL_DMAEN)


#define  USB_HCD_DMA_TX_CSR		(USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE)
#define  USB_HCD_DMA_TX_CSR_ISO	(USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE|USB_TXCSR_ISO)
#define  USB_HCD_DMAQ_TX_CSR		(USB_TXCSR_DMAREQENAB)


#define  USB_HCD_DMA_RX_CSR		(USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB|USB_RXCSR_AUTOREQ)
#define  USB_HCD_DMA_RX_CSR_ISO	(USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB|USB_RXCSR_AUTOREQ|USB_RXCSR_ISO)
#define  USB_HCD_DMAQ_RX_CSR		(USB_RXCSR_DMAREQENAB)


//RX DMAQ
#define USBHCD_DMAQ_RQ_CheckRunStat(_n)(_n)		(DRV_Reg32(USB_DMAQ_RQCSR(_n))&USB_DMACNTL_DMAEN_ACTIVE)
#define USBHCD_DMAQ_RQ_Stop(_n)				DRV_WriteReg32(USB_DMAQ_RQCSR(_n), DRV_Reg32(USB_DMAQ_RQCSR(_n))|USB_DMACNTL_DMAEN_STOP)
#define USBHCD_DMAQ_RQ_Start(_n)				DRV_WriteReg32(USB_DMAQ_RQCSR(_n), DRV_Reg32(USB_DMAQ_RQCSR(_n))|USB_DMACNTL_DMAEN_START)
#define USBHCD_DMAQ_RQ_Resume(_n)				DRV_WriteReg32(USB_DMAQ_RQCSR(_n), DRV_Reg32(USB_DMAQ_RQCSR(_n))|USB_DMACNTL_DMAEN_RESUME)


//TX DMAQ
#define USBHCD_DMAQ_TQ_CheckRunStat(_n)		(DRV_Reg32(USB_DMAQ_TQCSR(_n))&USB_DMACNTL_DMAEN_ACTIVE)
#define USBHCD_DMAQ_TQ_Stop(_n)				DRV_WriteReg32(USB_DMAQ_TQCSR(_n), DRV_Reg32(USB_DMAQ_TQCSR(_n))|USB_DMACNTL_DMAEN_STOP)
#define USBHCD_DMAQ_TQ_Start(_n)				DRV_WriteReg32(USB_DMAQ_TQCSR(_n), DRV_Reg32(USB_DMAQ_TQCSR(_n))|USB_DMACNTL_DMAEN_START)
#define USBHCD_DMAQ_TQ_Resume(_n)				DRV_WriteReg32(USB_DMAQ_TQCSR(_n), DRV_Reg32(USB_DMAQ_TQCSR(_n))|USB_DMACNTL_DMAEN_RESUME)


#define RGPD_FLAGS_HWO           0x01
#define RGPD_FLAGS_BDP       		 0x02
#define RGPD_ENDPOINT          	0x0F
#define RGPD_TGL          			0x10
#define RGPD_ZLP          			0x20
#define RGPD_FLAGS_IOC           0x80


#define TGPD_FLAGS_HWO              0x01
#define TGPD_FORMAT_BDP             0x02
#define TGPD_FORMAT_TGL             0x10
#define TGPD_FORMAT_ZLP             0x20
#define TGPD_FLAG_IOC				0x40


/*
#define TGPD_IS_FLAGS_HWO(_pd)      (((TGPD *)_pd)->flag & TGPD_FLAGS_HWO)
#define TGPD_SET_FLAGS_HWO(_pd)     (((TGPD *)_pd)->flag |= TGPD_FLAGS_HWO)
#define TGPD_CLR_FLAGS_HWO(_pd)     (((TGPD *)_pd)->flag &= (~TGPD_FLAGS_HWO))
#define TGPD_IS_FORMAT_BDP(_pd)     (((TGPD *)_pd)->flag & TGPD_FORMAT_BDP)
#define TGPD_SET_FORMAT_BDP(_pd)    (((TGPD *)_pd)->flag |= TGPD_FORMAT_BDP)
#define TGPD_CLR_FORMAT_BDP(_pd)    (((TGPD *)_pd)->flag &= (~TGPD_FORMAT_BDP))

#define TGPD_SET_FLAG(_pd, _flag)   ((TGPD *)_pd)->flag = (((TGPD *)_pd)->flag&(~TGPD_FLAGS_HWO))|(_flag)
#define TGPD_GET_FLAG(_pd)             (((TGPD *)_pd)->flag & TGPD_FLAGS_HWO)
#define TGPD_SET_CHKSUM(_pd, _n)    ((TGPD *)_pd)->chksum = PDU_calcCksum((kal_uint8 *)_pd, _n)
#define TGPD_SET_CHKSUM_HWO(_pd, _n)    ((TGPD *)_pd)->chksum = PDU_calcCksum((kal_uint8 *)_pd, _n)-1
#define TGPD_GET_CHKSUM(_pd)        ((TGPD *)_pd)->chksum
#define TGPD_SET_FORMAT(_pd, _fmt)  ((TGPD *)_pd)->flag = (((TGPD *)_pd)->flag&(~TGPD_FORMAT_BDP))|(_fmt)
#define TGPD_GET_FORMAT(_pd)        ((((TGPD *)_pd)->flag & TGPD_FORMAT_BDP)>>1)
#define TGPD_SET_DataBUF_LEN(_pd, _len) ((TGPD *)_pd)->DataBufferLen = _len
#define TGPD_ADD_DataBUF_LEN(_pd, _len) ((TGPD *)_pd)->DataBufferLen += _len
#define TGPD_GET_DataBUF_LEN(_pd)       ((TGPD *)_pd)->DataBufferLen
#define TGPD_SET_NEXT(_pd, _next)   ((TGPD *)_pd)->pNext = ((TGPD *)_next)
#define TGPD_GET_NEXT(_pd)          (TGPD *)phys_to_virt((kal_uint32)_pd->pNext)
#define TGPD_SET_TBD(_pd, _tbd)     ((TGPD *)_pd)->pBuf = (kal_uint8 *)_tbd;\
                                    TGPD_SET_FORMAT_BDP(_pd)
#define TGPD_GET_TBD(_pd)           (TBD *)((TGPD *)_pd)->pBuf

#define TGPD_SET_DATA(_pd, _data)   ((TGPD *)_pd)->pBuf = (kal_uint8 *)_data
#define TGPD_GET_DATA(_pd)          (kal_uint8*)((TGPD *)_pd)->pBuf
#define TGPD_SET_BUF_LEN(_pd, _len) ((TGPD *)_pd)->bufLen = _len
#define TGPD_ADD_BUF_LEN(_pd, _len) ((TGPD *)_pd)->bufLen += _len
#define TGPD_GET_BUF_LEN(_pd)       ((TGPD *)_pd)->bufLen
#define TGPD_SET_EXT_LEN(_pd, _len) ((TGPD *)_pd)->ExtLength = _len
#define TGPD_GET_EXT_LEN(_pd)        ((TGPD *)_pd)->ExtLength
#define TGPD_SET_EPaddr(_pd, _EP)  ((TGPD *)_pd)->ZTepFlag =(((TGPD *)_pd)->ZTepFlag&0xF0)|(_EP)
#define TGPD_GET_EPaddr(_pd)        ((TGPD *)_pd)->ZTepFlag & 0x0F 

#define TGPD_IS_FORMAT_TGL(_pd)     (((TGPD *)_pd)->ZTepFlag & TGPD_FORMAT_TGL)
#define TGPD_SET_FORMAT_TGL(_pd)    (((TGPD *)_pd)->ZTepFlag |=TGPD_FORMAT_TGL)
#define TGPD_CLR_FORMAT_TGL(_pd)    (((TGPD *)_pd)->ZTepFlag &= (~TGPD_FORMAT_TGL))
#define TGPD_IS_FORMAT_ZLP(_pd)     (((TGPD *)_pd)->ZTepFlag & TGPD_FORMAT_ZLP)
#define TGPD_SET_FORMAT_ZLP(_pd)    (((TGPD *)_pd)->ZTepFlag |=TGPD_FORMAT_ZLP)
#define TGPD_CLR_FORMAT_ZLP(_pd)    (((TGPD *)_pd)->ZTepFlag &= (~TGPD_FORMAT_ZLP))

#define TGPD_SET_TGL(_pd, _TGL)  ((TGPD *)_pd)->ZTepFlag |=(( _TGL) ? 0x10: 0x00)
#define TGPD_GET_TGL(_pd)        ((TGPD *)_pd)->ZTepFlag & 0x10 ? 1:0
#define TGPD_SET_ZLP(_pd, _ZLP)  ((TGPD *)_pd)->ZTepFlag |= ((_ZLP) ? 0x20: 0x00)
#define TGPD_GET_ZLP(_pd)        ((TGPD *)_pd)->ZTepFlag & 0x20 ? 1:0

#define TGPD_SET_IOC(_pd)			(((TGPD *)_pd)->ZTepFlag |= TGPD_FLAG_IOC)

#define TGPD_GET_EXT(_pd)           ((kal_uint8 *)_pd + sizeof(TGPD))
#define TGPD_SET_KEY_IDX(_pd, _data) \
{\
	kal_uint8 *_tmp = ((kal_uint8 *)_pd + sizeof(TGPD));\
	*_tmp = (unsigned char)_data;\
}
#define TGPD_GET_KEY_IDX(_pd)        *((kal_uint8 *)_pd + sizeof(TGPD))
*/

/**
 * TGPD
 */
typedef struct _TGPD
{
    kal_uint8 flag;
    kal_uint8  chksum;
    kal_uint16  DataBufferLen; /*Rx Allow Length*/
    struct _TGPD* pNext;
    kal_uint8* pBuf;
    kal_uint16 bufLen;
    kal_uint8 ExtLength;
    kal_uint8 ZTepFlag;
}TGPD, *PGPD;


#endif 


/* endpoint information*/
typedef struct
{
	/* keep send/recv buffer addr, wait for scheduler*/
	kal_uint8					*p_data;
	kal_uint16					data_length;
	/* If normal mode and data length > max pkt size */
	kal_uint16					max_packet_size;
	kal_uint16					sofar;

	USB_ENDPT_TXFER_TYPE		ep_type;			/* Control, interrupt, bulk or ISO */
	USB_EP_DIRECTION			direction;			/* For control endpoint, this indicates data direction*/
	kal_bool					b_enable;

	kal_bool					b_dma_enable;
	kal_bool					b_dmaQ_enable;
}USB_HCD_EP_INFO;

typedef enum
{
	 USBH_STATE_START,
	 USBH_STATE_IDLE,
	 USBH_STATE_WAIT_VRISE,
	 USBH_STATE_WAIT_BCON,
	 USBH_STATE_HOST,
	 USBH_STATE_SUSPEND
}USB_HCD_STATE;


typedef struct 
{
	const USB_HOST_COMMON_PARAM		*host_common_param;	

	USB_HCD_STATE				host_state;		
	USB_HCD_STATUS				reset_reason;

	/* interrupt handler */
	usb_hcd_intr_handler_ptr	attach_hdlr;
	usb_hcd_intr_handler_ptr	detach_hdlr;
	usb_hcd_intr_handler_ptr	resume_hdlr;		/* Host receive remote wakeup handler */

	/* endpoint related information*/
	usb_hcd_intr_handler_ptr			ep0_hdlr;
	usb_hcd_intr_handler_ptr			ep_tx_hdlr[MAX_TX_EP_NUM];
	usb_hcd_intr_handler_ptr			ep_rx_hdlr[MAX_RX_EP_NUM];
	USB_HCD_EP_INFO				ep0_info;
	USB_HCD_EP_INFO				ep_tx_info[MAX_TX_EP_NUM];
	USB_HCD_EP_INFO				ep_rx_info[MAX_RX_EP_NUM];

	kal_bool					ep0_setup;
	kal_bool					ep0_status;

 	USB_EP_STATE		ep_tx_enb_state[MAX_TX_EP_NUM];
 	USB_EP_STATE		ep_rx_enb_state[MAX_RX_EP_NUM];
	/* FIFO flush interrupt */
	kal_bool					ep_tx_flush_intr[MAX_TX_EP_NUM];
	kal_bool					ep_rx_flush_intr[MAX_RX_EP_NUM];
	/* TX FIFOWrite interrupt */
	kal_bool					ep0_fifo_intr;
	kal_bool					ep_tx_fifo_intr[MAX_TX_EP_NUM];
	kal_bool					ep_rx_fifo_intr[MAX_RX_EP_NUM];
	kal_bool					b_hcd_is_high_speed;

	kal_uint8				ep_rx_real_num;			
	kal_uint8				ep_tx_real_num;
	
	/* Attach/detach debounce timer */
	kal_uint32					gpt_handle;    /*GPT handle*/

	/* may be omit */
//	kal_uint32					resume_timer; 	

	kal_bool					b_unmask_irq;

	/* DMA parameters */
	/* DMA RX timer */
	kal_uint32					dma_gpt_handle[MAX_RX_EP_NUM];    /*GPT handle*/
	kal_uint8					dma_port[2][MAX_EP_NUM]; 	/* record TX/RX ep's DMA port number */
	USB_EP_DIRECTION		dma_dir[MAX_DMA_NUM]; 			/* record  DMA port's direction */
  kal_bool					dma_pktrdy[MAX_DMA_NUM];
  kal_bool					dma_running[MAX_DMA_NUM];
	kal_bool					dma_callback_upd_run[MAX_DMA_NUM]; /* take PP buffer */
	usb_dma_callback			dma_callback[MAX_DMA_NUM];			/* take PP buffer */
	kal_uint32 				dma_length[MAX_DMA_NUM];
#if defined(DRV_USB_IP_V4)
	kal_uint32 				dmaQ_tx_length[DMAQ_MAX_NUMBERS];
	kal_uint32 				dmaQ_rx_length[DMAQ_MAX_NUMBERS];
#endif
	kal_uint32 				dma_addr[MAX_DMA_NUM];
	kal_bool 					is_bidirection_dma[MAX_DMA_NUM];
	kal_uint8					dma_channel;
	kal_uint8					dma_tx_ep_num[MAX_DMA_NUM];  		/* record  DMA port's TX ep number */
	kal_uint8					dma_rx_ep_num[MAX_DMA_NUM];  		/* record  DMA port's RX ep number */
	kal_bool					b_enable_dma_burst_auto_chge;		/* For DVT use only, enable DMA auto changed burst mode */
 	kal_bool					b_disable_attach;
 	kal_uint8				usb_ip_port;
}USB_HCD_Struct;



extern USB_HCD_Struct g_UsbHcdInfo[USB_IP_NUM];


#endif /* USB_HCD_PRI_H */

