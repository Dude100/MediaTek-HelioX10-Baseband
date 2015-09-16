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
 *    usb_drv_pri.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file intends for usb hardware related function definitions. Only use for hardware driver.
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef USB_DRV_PRI_H
#define USB_DRV_PRI_H


#include "usb_hw.h"
#include "usb_drv.h"
#include "kal_general_types.h"


/* power state */
typedef enum 
{
	USB_STATE_NORMAL = 0,
	USB_STATE_SUSPEND
} USB_POWER_STATE;



#if defined(DRV_USB_IP_V4)

#define USBDMA_CheckRunStat(_n)			(DRV_Reg32(USB_DMACNTL(_n))&USB_DMACNTL_DMAEN)
#define USBDMA_Stop(_n)						DRV_WriteReg32(USB_DMACNTL(_n), DRV_Reg32(USB_DMACNTL(_n))&(~USB_DMACNTL_DMAEN))
#define USB_DMA_TIMER_TIMEOUT_TICK 		0x7f
#define USB_DIS_DMA_LIMITER				0xff
#define USB_DMA_TIMEOUT_STATUS			0x100

#define  USB_DMA_TX_CSR		(USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE)
#define  USB_DMA_TX_CSR_ISO	(USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE|USB_TXCSR_ISO)
#define  USB_DMAQ_TX_CSR		(USB_TXCSR_DMAREQENAB)


#define  USB_DMA_RX_CSR		(USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB)
#define  USB_DMA_RX_CSR_ISO	(USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB|USB_RXCSR_ISO)
#define  USB_DMAQ_RX_CSR		(USB_RXCSR_DMAREQENAB)

//=============================
//DMAQ
#define USBDMAQ_RQ_CheckRunStat(_n)(_n)		(DRV_Reg32(USB_DMAQ_RQCSR(_n))&USB_DMACNTL_DMAEN_ACTIVE)
#define USBDMAQ_RQ_Stop(_n)				DRV_WriteReg32(USB_DMAQ_RQCSR(_n), DRV_Reg32(USB_DMAQ_RQCSR(_n))|USB_DMACNTL_DMAEN_STOP)
#define USBDMAQ_RQ_Start(_n)				DRV_WriteReg32(USB_DMAQ_RQCSR(_n), DRV_Reg32(USB_DMAQ_RQCSR(_n))|USB_DMACNTL_DMAEN_START)
#define USBDMAQ_RQ_Resume(_n)				DRV_WriteReg32(USB_DMAQ_RQCSR(_n), DRV_Reg32(USB_DMAQ_RQCSR(_n))|USB_DMACNTL_DMAEN_RESUME)
//#define USBDMAQ_Start_Addr(_n, addr)			DRV_WriteReg32(USB_DMAQ_RQSAR(_n), addr)
//TX DMAQ
#define USBDMAQ_TQ_CheckRunStat(_n)		(DRV_Reg32(USB_DMAQ_TQCSR(_n))&USB_DMACNTL_DMAEN_ACTIVE)
#define USBDMAQ_TQ_Stop(_n)				DRV_WriteReg32(USB_DMAQ_TQCSR(_n), DRV_Reg32(USB_DMAQ_TQCSR(_n))|USB_DMACNTL_DMAEN_STOP)
#define USBDMAQ_TQ_Start(_n)				DRV_WriteReg32(USB_DMAQ_TQCSR(_n), DRV_Reg32(USB_DMAQ_TQCSR(_n))|USB_DMACNTL_DMAEN_START)
#define USBDMAQ_TQ_Resume(_n)				DRV_WriteReg32(USB_DMAQ_TQCSR(_n), DRV_Reg32(USB_DMAQ_TQCSR(_n))|USB_DMACNTL_DMAEN_RESUME)
//#define USBDMAQ_Start_Addr(_n, addr)			DRV_WriteReg32(USB_DMAQ_RQSAR(_n), addr)
//============================
#define	TGPD_MAX_NUMBERS	8


#define RGPD_FLAGS_IOC              0x80
#define RGPD_FLAGS_HWO            0x01
#define RGPD_FLAGS_BDP       		0x02
#define RGPD_ENDPOINT          	0x0F
#define RGPD_TGL          			0x10
#define RGPD_ZLP          			0x20



#define TGPD_FLAGS_HWO              0x01
#define TGPD_IS_FLAGS_HWO(_pd)      (((TGPD *)_pd)->flag & TGPD_FLAGS_HWO)
#define TGPD_SET_FLAGS_HWO(_pd)     (((TGPD *)_pd)->flag |= TGPD_FLAGS_HWO)
#define TGPD_CLR_FLAGS_HWO(_pd)     (((TGPD *)_pd)->flag &= (~TGPD_FLAGS_HWO))
#define TGPD_FORMAT_BDP             0x02
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

#define TGPD_FORMAT_TGL             0x10
#define TGPD_IS_FORMAT_TGL(_pd)     (((TGPD *)_pd)->ZTepFlag & TGPD_FORMAT_TGL)
#define TGPD_SET_FORMAT_TGL(_pd)    (((TGPD *)_pd)->ZTepFlag |=TGPD_FORMAT_TGL)
#define TGPD_CLR_FORMAT_TGL(_pd)    (((TGPD *)_pd)->ZTepFlag &= (~TGPD_FORMAT_TGL))
#define TGPD_FORMAT_ZLP             0x20
#define TGPD_IS_FORMAT_ZLP(_pd)     (((TGPD *)_pd)->ZTepFlag & TGPD_FORMAT_ZLP)
#define TGPD_SET_FORMAT_ZLP(_pd)    (((TGPD *)_pd)->ZTepFlag |=TGPD_FORMAT_ZLP)
#define TGPD_CLR_FORMAT_ZLP(_pd)    (((TGPD *)_pd)->ZTepFlag &= (~TGPD_FORMAT_ZLP))

#define TGPD_SET_TGL(_pd, _TGL)  ((TGPD *)_pd)->ZTepFlag |=(( _TGL) ? 0x10: 0x00)
#define TGPD_GET_TGL(_pd)        ((TGPD *)_pd)->ZTepFlag & 0x10 ? 1:0
#define TGPD_SET_ZLP(_pd, _ZLP)  ((TGPD *)_pd)->ZTepFlag |= ((_ZLP) ? 0x20: 0x00)
#define TGPD_GET_ZLP(_pd)        ((TGPD *)_pd)->ZTepFlag & 0x20 ? 1:0

#define TGPD_FLAG_IOC				0x40
#define TGPD_SET_IOC(_pd)			(((TGPD *)_pd)->ZTepFlag |= TGPD_FLAG_IOC)



#define TGPD_GET_EXT(_pd)           ((kal_uint8 *)_pd + sizeof(TGPD))
#define TGPD_SET_KEY_IDX(_pd, _data) \
{\
	kal_uint8 *_tmp = ((kal_uint8 *)_pd + sizeof(TGPD));\
	*_tmp = (unsigned char)_data;\
}
#define TGPD_GET_KEY_IDX(_pd)        *((kal_uint8 *)_pd + sizeof(TGPD))

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



#elif defined(DRV_USB_IP_V3)


#define USBDMA_CheckRunStat(_n)			(USB_DRV_Reg(USB_DMACNTL(_n))&USB_DMACNTL_DMAEN)
#define USBDMA_CheckPPRunStat(_n)			(USB_DRV_Reg(USB_DMAPPCNTL(_n))&USB_DMACNTL_DMAEN)
#define USBDMA_Stop(_n)						USB_DRV_ClearBits(USB_DMACNTL(_n), USB_DMACNTL_DMAEN)
#ifdef __DMA_PP_ENABLE__
#define USBDMA_PPStop(_n)					USB_DRV_ClearBits(USB_DMAPPCNTL(_n), USB_DMACNTL_DMAEN)
#endif
#define USB_DMA_TIMER_TIMEOUT_TICK 		0x7f
#define USB_DIS_DMA_LIMITER				0xff


#define  USB_DMA_TX_CSR		(USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE)
#define  USB_DMA_TX_CSR_ISO	(USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE|USB_TXCSR_ISO)


#define  USB_DMA_RX_CSR		(USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB)
#define  USB_DMA_RX_CSR_ISO	(USB_RXCSR_AUTOCLEAR|USB_RXCSR_DMAREQENAB|USB_RXCSR_ISO)


#elif defined (DRV_USB_IP_V2)

#define USB_BDT_NUMBER				10

/* BDT structure */
typedef struct
{
	kal_uint32	PID_OWN_DATA01_BC;
	kal_uint32	ADDRESS;
} USB_BDT, *USB_BDT_PTR;


/* EP0 state machine, used to handle abnormal cases*/
typedef enum
{
	USB_EP0_TRANS_NONE,
	USB_EP0_TRANS_TX_DATA,
	USB_EP0_TRANS_TX_DATA_END,
	USB_EP0_TRANS_TX_STATUS,
	USB_EP0_TRANS_RX_DATA,
	USB_EP0_TRANS_RX_STATUS,
	USB_EP0_TRANS_END,
	USB_EP0_TRANS_STALL
}USB_EP0_TRANS_TYPE;

/* BDT macro*/
#define USB_BDT_RX		0
#define USB_BDT_TX		1
#define USB_BDT_EVEN	0
#define USB_BDT_ODD	1
#define WRITE_EP0_BDT(direction, even_odd, value)  (g_UsbDrvInfo.bdt_ptr[direction][even_odd] = value)
#define WRITE_EPN_BDT(ep, direction, value)  		(g_UsbDrvInfo.bdt_ptr[ep+1][direction] = value)

#define WRITE_EP0_BDT_PID(direction, even_odd, value)	(g_UsbDrvInfo.bdt_ptr[direction][even_odd]->PID_OWN_DATA01_BC = value)
#define WRITE_EPN_BDT_PID(ep, direction, value)	(g_UsbDrvInfo.bdt_ptr[ep+1][direction]->PID_OWN_DATA01_BC = value)
#define READ_EP0_BDT_PID(direction, even_odd)	(g_UsbDrvInfo.bdt_ptr[direction][even_odd]->PID_OWN_DATA01_BC)
#define READ_EPN_BDT_PID(ep, direction)		(g_UsbDrvInfo.bdt_ptr[ep+1][direction]->PID_OWN_DATA01_BC)

#define WRITE_EP0_BDT_ADDR(direction, even_odd, value)	(g_UsbDrvInfo.bdt_ptr[direction][even_odd]->ADDRESS = value)
#define WRITE_EPN_BDT_ADDR(ep, direction, value)		(g_UsbDrvInfo.bdt_ptr[ep+1][direction]->ADDRESS = value)
#define READ_EP0_BDT_ADDR(direction, even_odd)		(g_UsbDrvInfo.bdt_ptr[direction][even_odd]->ADDRESS)
#define READ_EPN_BDT_ADDR(ep, direction)	(g_UsbDrvInfo.bdt_ptr[ep+1][direction]->ADDRESS)

#endif /* DRV_USB_IP_V2 */

typedef struct
{
	USB_POWER_STATE				power_state;
	kal_bool					is_unMaskUSB;	 /*Tricky, used to control interrupt */
	kal_bool					is_ProUSBHISR;

	/* interrupt handler */
	usb_drv_intr_handler_ptr	reset_hdlr;
	usb_drv_intr_handler_ptr	suspend_hdlr;
	usb_drv_intr_handler_ptr	resume_hdlr;
	usb_drv_intr_handler_ptr	ep0_hdlr;
	usb_drv_intr_handler_ptr	ep_tx_hdlr[MAX_TX_EP_NUM];
	usb_drv_intr_handler_ptr	ep_rx_hdlr[MAX_RX_EP_NUM];

	/* Stall status */
	kal_bool					ep_tx_stall_status[MAX_TX_EP_NUM];
	kal_bool					ep_rx_stall_status[MAX_RX_EP_NUM];

	/* cable plug out : disconnect */
	kal_bool          usb_disconnect;

	/* Endpoint current status */
 	USB_EP_STATE		ep_tx_enb_state[MAX_TX_EP_NUM];
 	USB_EP_STATE		ep_rx_enb_state[MAX_RX_EP_NUM];

#if defined (DRV_USB_IP_V3)||defined (DRV_USB_IP_V4)
	/* FIFO flush interrupt */
	kal_bool					ep_tx_flush_intr[MAX_TX_EP_NUM];
	kal_bool					ep_rx_flush_intr[MAX_RX_EP_NUM];
	kal_uint8                            dma_burst_mode;
        /*HS FS flag*/
        kal_bool					Is_HS_mode;

        /*USB FIFO full and receive Suspend signal */
        kal_bool					suspend_with_FIFO_not_empty; 
        kal_uint8    suspend_count;

	/* DMA parameters */
	kal_uint8					dma_port[2][MAX_EP_NUM]; 	/* record TX/RX ep's DMA port number */
	USB_EP_DIRECTION		dma_dir[MAX_DMA_NUM]; 			/* record  DMA port's direction */
	usb_dmaq_callback			dmaq_callback[2][MAX_DMA_NUM];			/* take PP buffer */	
	usb_dmaq_callback			dmaq_empty_callback[2][MAX_DMA_NUM];			/* take PP buffer */
#else
	kal_uint8					dma_port[MAX_DMA_NUM];  
	USB_EP_DIRECTION		dma_dir[MAX_EP_NUM]; 			/* record  DMA port's direction */
#endif
   	kal_bool					dma_pktrdy[MAX_DMA_NUM];
   	kal_bool					dma_running[MAX_DMA_NUM];
	kal_bool					dma_callback_upd_run[MAX_DMA_NUM]; /* take PP buffer */
	usb_dma_callback			dma_callback[MAX_DMA_NUM];			/* take PP buffer */
	kal_uint32                  dma_tx_length[MAX_DMA_NUM];	
#ifdef __WRITE_THROUGH_CACHEABLE__
	kal_uint32 				dma_length[MAX_DMA_NUM];
	kal_uint32 				dma_addr[MAX_DMA_NUM];
#endif

#if defined (DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_bool 					is_bidirection_dma[MAX_DMA_NUM];
	kal_uint8					dma_channel;
	kal_uint8					dma_tx_ep_num[MAX_DMA_NUM];  		/* record  DMA port's TX ep number */
	kal_uint8					dma_rx_ep_num[MAX_DMA_NUM];  		/* record  DMA port's RX ep number */
	kal_bool					b_enable_dma_burst_auto_chge;		/* For DVT use only, enable DMA auto changed burst mode */

#ifdef __DMA_PP_ENABLE__
	/* Only PP need this!! */
	kal_uint32 				dma_pp_addr[MAX_RX_EP_NUM];
	kal_uint32 				dma_pp_length[MAX_RX_EP_NUM];

	kal_uint32 				real_count;
	kal_uint32 				real_pp_count;
	kal_bool 					dma_is_pp[MAX_DMA_NUM]; 	/* is PP A or PP B */
	kal_bool 					dma_is_running[2][MAX_DMA_NUM]; 	/* is PP A or PP B running */
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


#elif defined (DRV_USB_IP_V2)
 	/* DMA parameters */
	kal_uint8					dma_pktlength[MAX_DMA_NUM];

	/* dma and fast mode sequnce control parameters*/
	kal_bool					b_dma_rx_config;		/* a flag to record USB config RX DMA, to cancel token done intr */
	kal_uint8					dma_tx_ep;
 	kal_uint8					dma_res_tx_ep;
 	kal_uint8					fast_mode_tx_ep;
 
	/* BDT addr*/
 	USB_BDT_PTR			bdt_ptr[USB_BDT_NUMBER/2][2];

 	/* EP0 status*/
 	kal_uint8					ep0_rx_even_odd;
 	kal_uint8					ep0_tx_even_odd;
 	kal_uint8 				ep0_current_dir;
 	kal_uint8					ep0_tx_data01;
 	USB_EP0_TRANS_TYPE		ep0_transaction_type;

	/* EPn (others to EP0) status*/
//	USB_EP_ENB_STATE		ep_tx_enb_state[MAX_TX_EP_NUM];
//	USB_EP_ENB_STATE		ep_rx_enb_state[MAX_RX_EP_NUM];
 	kal_uint8					ep_tx_max_data_size[MAX_TX_EP_NUM];
 	kal_uint8					ep_rx_max_data_size[MAX_RX_EP_NUM];
 	kal_uint8					ep_tx_data01[MAX_TX_EP_NUM];
 	kal_uint8					ep_rx_data01[MAX_RX_EP_NUM];
	kal_uint32				error_count;
	kal_uint8					error_reason;
	kal_uint8					fm_error_reason;

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	kal_uint8    IntrTx;
	kal_uint8    IntrRx;
#endif
}USB_Drv_Info;



extern USB_Drv_Info g_UsbDrvInfo;


#endif /* USB_DRV_PRI_H */

