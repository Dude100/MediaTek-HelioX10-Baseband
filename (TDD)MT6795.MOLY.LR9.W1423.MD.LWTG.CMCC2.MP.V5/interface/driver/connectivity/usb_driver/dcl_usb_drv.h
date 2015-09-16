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
 *   dcl_usb_drv.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  This file defines the DCL common definitions for USB driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_USB_DRV_H_STRUCT__
#define __DCL_USB_DRV_H_STRUCT__


#include "dcl.h"


#define DMA_MODE_INC16 		3
#define DMA_MODE_INC8 		2
#define DMA_MODE_INC4 		1
#define DMA_MODE_BURST 		0



#define USB_EP_BULK_MAXP_HS	512  	/* maximum packet size for high-speed bulk endpoints */
#define USB_EP_BULK_MAXP_FS	64  		/* maximum packet size for full-speed bulk endpoints */

#define USB_EP_ISO_MAXP_HB      (1024|(0x02<<11))
#define USB_EP_ISO_MAXP_HB_HS	3072 	/* maximum packet size for high-speed, high bandwidth isochronous endpoints */
#define USB_EP_ISO_MAXP_HS	1024 	/* maximum packet size for high-speed isochronous endpoints */
#define USB_EP_ISO_MAXP_FS	 	  512  	/* maximum packet size for full-speed isochronous endpoints */

#define USB_EP_INTR_MAXP_HB	(1024|(0x02<<11))

#define USB_EP_INTR_MAXP_HB_HS	3072   	/* maximum packet size for high-speed, high bandwidth interrupt endpoints */
#define USB_EP_INTR_MAXP_HS	 64//1024  	/* maximum packet size for high-speed interrupt endpoints */
#define USB_EP_INTR_MAXP_FS	64   		/* maximum packet size for full-speed interrupt endpoints */



#if defined (DRV_USB_IP_V3)||defined (DRV_USB_IP_V4)

#define USB_EP0_MAXP			64		/* control pipe, the same when HS or FS */

#define USB_EP_RX_MAX_COUNT	8192	/* because endpoint rx count only minus 4, so maybe we see here and ot is a minus number */


#ifndef __USB_HS_ENABLE__
#define USB_EP_BULK_MAXP	64
#define USB_EP_INTR_MAXP  64
#define USBDL_EP_BULK_MAXP		64
#else
#define USB_EP_INTR_MAXP  64
#define USBDL_EP_BULK_MAXP		512
#endif

#else  //USB_IP_V2 /V1 /V1_plus


#define USB_EP0_MAXP		8
#define USB_EP_BULK_MAXP	64  /* maximum packet size for bulk endpoints */
#define USB_EP_ISO_MAXP	64  /* maximum packet size for bulk endpoints */

 /* maximum packet size for interrupt endpoints */
#if defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)
#define USB_EP_INTR_MAXP	16
#elif  defined(DRV_USB_IP_V2)
#define USB_EP_INTR_MAXP	8
#endif


/* maximum packet size for USB Download */
#if defined(DRV_USB_IP_V1)
#define USBDL_EP_BULK_MAXP		32
#elif  defined(DRV_USB_IP_V2)
#define USBDL_EP_BULK_MAXP		64
#elif defined(DRV_USB_IP_V1_PLUS)
#define USBDL_EP_BULK_MAXP		64
#endif

#endif


#ifdef  __USB_HW_DBG__
#define USB_DRV_WriteReg(addr, data)  DRV_DBG_WriteReg(addr, data)
#define USB_DRV_Reg(addr)  DRV_DBG_Reg(addr)
#define USB_DRV_WriteReg32(addr, data)  DRV_DBG_WriteReg32(addr, data)
#define USB_DRV_Reg32(addr)  DRV_DBG_Reg32(addr)
#define USB_DRV_WriteReg8(addr, data)  DRV_DBG_WriteReg8(addr, data)
#define USB_DRV_Reg8(addr)  DRV_DBG_Reg8(addr)
#define USB_DRV_ClearBits(addr, data)  DRV_DBG_ClearBits(addr, data)
#define USB_DRV_SetBits(addr, data)  DRV_DBG_SetBits(addr, data)
#define USB_DRV_ClearBits32(addr, data)  DRV_DBG_ClearBits32(addr, data)
#define USB_DRV_SetBits32(addr, data)  DRV_DBG_SetBits32(addr, data)
#define USB_DRV_ClearBits8(addr, data)  DRV_DBG_ClearBits8(addr, data)
#define USB_DRV_SetBits8(addr, data)  DRV_DBG_SetBits8(addr, data)
#define USB_Log_DRV_WriteReg(addr, data)  DRV_DBG_WriteReg(addr, data)
#define USB_Log_DRV_Reg(addr)  DRV_DBG_Reg(addr)


#else
#define USB_DRV_WriteReg(addr, data)  DRV_WriteReg(addr, data)
#define USB_DRV_Reg(addr)  DRV_Reg(addr)
#define USB_DRV_WriteReg32(addr, data)  DRV_WriteReg32(addr, data)
#define USB_DRV_Reg32(addr)  DRV_Reg32(addr)
#define USB_DRV_WriteReg8(addr, data)  DRV_WriteReg8(addr, data)
#define USB_DRV_Reg8(addr)  DRV_Reg8(addr)
#define USB_DRV_ClearBits(addr, data)  DRV_ClearBits(addr, data)
#define USB_DRV_SetBits(addr, data)  DRV_SetBits(addr, data)
#define USB_DRV_ClearBits32(addr, data)  DRV_ClearBits32(addr, data)
#define USB_DRV_SetBits32(addr, data)  DRV_SetBits32(addr, data)
#define USB_DRV_ClearBits8(addr, data)  DRV_ClearBits8(addr, data)
#define USB_DRV_SetBits8(addr, data)  DRV_SetBits8(addr, data)
#define USB_Log_DRV_WriteReg(addr, data)  DRV_WriteReg(addr, data)
#define USB_Log_DRV_Reg(addr)  DRV_Reg(addr)
#endif




/* USB phy owner id */
typedef enum
{
	USB_PHY_OWNER_USB = 0,
	USB_PHY_OWNER_BMT,
	USB_PHY_OWNER_MAX = 31
}USB_PHY_OWNER;


typedef enum
{
	USB_DMA0_TYPE = 0,
	USB_DMA1_TYPE,
	USB_DMA2_TYPE
} USB_DMA_TYPE;


typedef enum
{
	USB_TEST_MODE_TYPE_NONE = 0,
	USB_TEST_MODE_TYPE_J,
	USB_TEST_MODE_TYPE_K,
	USB_TEST_MODE_TYPE_SE0_NAK,
	USB_TEST_MODE_TYPE_PACKET
}USB_TEST_MODE_TYPE;


/* IN, OUT pipe index for ep_number */
typedef enum
{
	USB_EP_TX_DIR = 0,
	USB_EP_RX_DIR
}USB_EP_DIRECTION;


/* CTRL, BULK, INTR, ISO endpoint */
typedef enum
{
	USB_ENDPT_CTRL = 0,
	USB_ENDPT_BULK,
	USB_ENDPT_INTR,
	USB_ENDPT_ISO
}USB_ENDPT_TXFER_TYPE;


/* USB DMA usage */
typedef enum
{
	USB_EP_USE_NO_DMA = 0,
	USB_EP_USE_ONLY_DMA,
	USB_EP_USE_DMA_ON_DEMAND
}USB_ENDPT_DMA_USAGE;


/* Endpoint state*/
typedef enum
{
	USB_EP_STATE_DISABLE = 0,
	USB_EP_STATE_FIFO,
	USB_EP_STATE_DMA
}USB_EP_STATE;



/* endpoint 0 hardware control state*/
typedef enum
{
	USB_EP0_DRV_STATE_READ_END,
	USB_EP0_DRV_STATE_WRITE_RDY,
	USB_EP0_DRV_STATE_TRANSACTION_END,
	USB_EP0_DRV_STATE_CLEAR_SENT_STALL
}USB_EP0_DRV_STATE;


/* interrupt handler type*/
typedef enum
{
	USB_DRV_HDLR_RESET,
	USB_DRV_HDLR_SUSPEND,
	USB_DRV_HDLR_RESUME,
	USB_DRV_HDLR_EP0,
	USB_DRV_HDLR_EP_TX,
	USB_DRV_HDLR_EP_RX
}USB_DRV_HDLR_TYPE;


/* The set address action may be different for different hardware,
    This is the current state for the set address function */
typedef enum
{
	USB_SET_ADDR_DATA,
	USB_SET_ADDR_STATUS
}USB_SET_ADDR_STATE;


/* interrupt handler function type */
typedef void (*usb_drv_intr_handler_ptr)(void);
/* application dma callback function type */
typedef void (*usb_dma_callback)(void);
typedef void (*usb_dmaq_callback)(DCL_UINT32 u4_port);


/////// DCL part ////////////////////


/* USB phy owner id */
typedef enum
{
	DCL_USB_PHY_OWNER_USB = 0,
	DCL_USB_PHY_OWNER_BMT,
	DCL_USB_PHY_OWNER_MAX = 31
}DCL_USB_PHY_OWNER;


typedef enum 
{
	DCL_USB_DMA0_TYPE = 0,
	DCL_USB_DMA1_TYPE,
	DCL_USB_DMA2_TYPE
}DCL_USB_DMA_TYPE;


typedef enum 
{
	DCL_USB_TEST_MODE_TYPE_NONE = 0,
	DCL_USB_TEST_MODE_TYPE_J,
	DCL_USB_TEST_MODE_TYPE_K,
	DCL_USB_TEST_MODE_TYPE_SE0_NAK,
	DCL_USB_TEST_MODE_TYPE_PACKET
}DCL_USB_TEST_MODE_TYPE;


/* USB PDN owner id */
typedef enum
{
	DCL_USB_PDN_OWNER_USB = 0,
	DCL_USB_PDN_OWNER_IRDA,
//	DCL_USB_PDN_OWNER_UPLL
}DCL_USB_PDN_OWNER;


typedef enum 
{
	DCL_USB_EP_TX_DIR = 0,
	DCL_USB_EP_RX_DIR
}DCL_USB_EP_DIRECTION;


/* CTRL, BULK, INTR, ISO endpoint */
typedef enum
{
	DCL_USB_ENDPT_CTRL = 0,
	DCL_USB_ENDPT_BULK,
	DCL_USB_ENDPT_INTR,
	DCL_USB_ENDPT_ISO
}DCL_USB_ENDPT_TXFER_TYPE;



/* USB DMA usage */
typedef enum
{
	DCL_USB_EP_USE_NO_DMA = 0,
	DCL_USB_EP_USE_ONLY_DMA,
	DCL_USB_EP_USE_DMA_ON_DEMAND
}DCL_USB_ENDPT_DMA_USAGE;


/* Endpoint state*/
typedef enum
{
	DCL_USB_EP_STATE_DISABLE = 0,
	DCL_USB_EP_STATE_FIFO,
	DCL_USB_EP_STATE_DMA
}DCL_USB_EP_STATE;


/* endpoint 0 hardware control state*/
typedef enum
{
	DCL_USB_EP0_DRV_STATE_READ_END,
	DCL_USB_EP0_DRV_STATE_WRITE_RDY,
	DCL_USB_EP0_DRV_STATE_TRANSACTION_END,
	DCL_USB_EP0_DRV_STATE_CLEAR_SENT_STALL
}DCL_USB_EP0_DRV_STATE;


/* interrupt handler type*/
typedef enum
{
	DCL_USB_DRV_HDLR_RESET,
	DCL_USB_DRV_HDLR_SUSPEND,
	DCL_USB_DRV_HDLR_RESUME,
	DCL_USB_DRV_HDLR_EP0,
	DCL_USB_DRV_HDLR_EP_TX,
	DCL_USB_DRV_HDLR_EP_RX
}DCL_USB_DRV_HDLR_TYPE;


/* The set address action may be different for different hardware, 
    This is the current state for the set address function */
typedef enum
{
	DCL_USB_SET_ADDR_DATA,
	DCL_USB_SET_ADDR_STATUS
}DCL_USB_SET_ADDR_STATE;


typedef enum
{
	DCL_USB_TOTAL_FIFO_SIZE_4096 = 0,
	DCL_USB_TOTAL_FIFO_SIZE_2304,
	DCL_USB_TOTAL_FIFO_SIZE_NONE
}DCL_USB_TOTAL_FIFO_SIZE;


typedef enum
{
	DCL_USB_IP_V3 = 0,
	DCL_USB_IP_V1,
	DCL_USB_IP_V1_PLUS
}DCL_USB_IP_VERSION;


typedef void (*DCL_USB_FUNC_TYPE_0)(void);



/*******************************************************************************
 * DCL_OPTIONS for USB_DRV
 *******************************************************************************/
#define USB_DRV_OPTIONS


 /*******************************************************************************
 * DCL_CONFIGURE_T for USB_DRV
 *******************************************************************************/
#define USB_DRV_CONFIGS


/*******************************************************************************
 * DCL_EVENT for USB_DRV
 *******************************************************************************/
#define USB_DRV_EVENTS


/*******************************************************************************
 * DCL_CTRL_CMD for USB_DRV
 *******************************************************************************/

//#ifdef __BUILD_DOM__
 /* The USB DRV command values in DCL_CTRL_CMD_T Enum of dcl.h */
//typedef enum{
//	USB_DRV_CMD_INIT_DRV_INFO, \   /* Initialize usb driver SW information, called at USB_Reset() */
//	USB_DRV_CMD_RESET_DRV_INFO, \     /* Reset usb driver SW information, called at USB_Reset() */
//}DCL_CTRL_CMD_T;


//#else /*__BUILD_DOM__*/

#define USB_DRV_CMDS \
	USB_DRV_CMD_INIT_DRV_INFO = 0, \
	USB_DRV_CMD_RESET_DRV_INFO, \
	USB_DRV_CMD_REGISTER_DRV_INFO, \
	USB_DRV_CMD_SET_UNMASK_IRQ, \
	USB_DRV_CMD_GET_UNMASK_IRQ, \
	USB_DRV_CMD_GET_EP_STALL_STATUS, \
	USB_DRV_CMD_DRV_CREATE_ISR, \
	USB_DRV_CMD_DRV_ACTIVATE_ISR, \
	USB_DRV_CMD_DMA_DRV_CREATE_ISR, \
	USB_DRV_CMD_DMA_DRV_ACTIVATE_ISR, \
	USB_DRV_CMD_PDN_ENABLE, \
	USB_DRV_CMD_DP_PULL_UP, \
	USB_DRV_CMD_SET_DISCON_STATUS, \
	USB_DRV_CMD_RESET_DRV, \
	USB_DRV_CMD_INITIALIZE_DRV_PHASE_1, \
	USB_DRV_CMD_INITIALIZE_DRV_PHASE_2, \
	USB_DRV_CMD_RELEASE_DRV, \
	USB_DRV_CMD_SET_ADDRESS, \
	USB_DRV_CMD_GET_FRAME_COUNT, \
	USB_DRV_CMD_TXEP_INIT, \
	USB_DRV_CMD_RXEP_INIT, \
	USB_DRV_CMD_TXEP_EN, \
	USB_DRV_CMD_TXEP_DIS, \
	USB_DRV_CMD_RXEP_EN, \
	USB_DRV_CMD_RXEP_DIS, \
	USB_DRV_CMD_CONFIG_TXEP_TYPE, \
	USB_DRV_CMD_CONFIG_RXEP_TYPE, \
	USB_DRV_CMD_TXEP_CLEAR_DATATOG, \
	USB_DRV_CMD_RxEP_CLEAR_DATATOG, \
	USB_DRV_CMD_TXEP_USAGE, \
	USB_DRV_CMD_RXEP_USAGE, \
	USB_DRV_CMD_TXEP_PK_SIZE, \
	USB_DRV_CMD_RXEP_PK_SIZE, \
	USB_DRV_CMD_EPFIFO_READ, \
	USB_DRV_CMD_EPFIFO_WRITE, \
	USB_DRV_CMD_CTRLEPSTALL, \
	USB_DRV_CMD_GET_EP0_STATUS, \
	USB_DRV_CMD_UPDATE_EP0_STATE, \
	USB_DRV_CMD_GET_EP0_PKT_LEN, \
	USB_DRV_CMD_TXEP_READY, \
	USB_DRV_CMD_GET_RXEP_PKT_LEN, \
	USB_DRV_CMD_RXEP_READY, \
	USB_DRV_CMD_IS_TXEP_EMPTY, \
	USB_DRV_CMD_IS_RXEP_EMPTY, \
	USB_DRV_CMD_CLEAR_TXEP_FIFO, \
	USB_DRV_CMD_CLEAR_RXEP_FIFO, \
	USB_DRV_CMD_GET_DMA_CHANNEL, \
	USB_DRV_CMD_STOP_DMA_CHANNEL, \
	USB_DRV_CMD_FREE_DMA_CHANNEL, \
	USB_DRV_CMD_DMA_SETUP, \
	USB_DRV_CMD_GET_DMA_RUN_STATUS, \
	USB_DRV_CMD_SET_DMA_RUN_STATUS, \
	USB_DRV_CMD_ENABLE_DMA_TIMER, \
	USB_DRV_CMD_CHECK_DMA_TIME_OUT, \
	USB_DRV_CMD_GET_DMA_REAL_COUNT, \
	USB_DRV_CMD_SET_DMA_LIMITER, \
	USB_DRV_CMD_SWITCH_DMA_BURST_MODE, \
	USB_DRV_CMD_REGISTER_DMA_CHANNEL, \
	USB_DRV_CMD_SET_DMA_BURST_MODE, \
	USB_DRV_CMD_USB_IS_HIGH_SPEED, \
	USB_DRV_CMD_ENTER_TESTMODE, \
	USB_DRV_CMD_RESET_FIFO, \
	USB_DRV_CMD_IS_FIFO_Not_Empty, \
	USB_DRV_CMD_IS_SUSPEND_POWER_STATUS, \
	USB_DRV_CMD_POLLING_TX_DONE, \
	USB_DRV_CMD_POLLING_RX_DATA, \
	USB_DRV_CMD_CLR_RXEP_ISR, \
	USB_DRV_CMD_GET_RXEP_ISR_STATUS, \
	USB_DRV_CMD_GET_TX_ISR_STATUS, \
	USB_DRV_CMD_PHY_ENABLE, \
	USB_DRV_CMD_PHY_DISABLE, \
	USB_DRV_CMD_USB_UART_SHARE, \
	USB_DRV_CMD_USBDL_UPDATE_USB_DL_MODE, \
	USB_DRV_CMD_USBDL_IS_USB_DL_MODE, \
	USB_DRV_CMD_DEBUG_INFO, \
	USB_DRV_CMD_DUMP,  \
	USB_DRV_CMD_GET_TOTAL_FIFO_SIZE,  \
	USB_DRV_CMD_GET_IP_VERSION,  \
	USB_DRV_CMD_CHECK_IC_DMA_LIMIT_CAPABILITY,  \
	USB_DRV_CMD_CHECK_IC_UART_SHARE_PAD_CAPABILITY,  \
	USB_DRV_CMD_USBDL_IS_USB_FAST_META_MODE,  \
	USB_DRV_CMD_SET_MENU_CONFIG,  \
	USB_DRV_CMD_GET_MENU_CONFIG,  \
	USB_CLASS_CMD_START = 0x1000,  \
	USB_VIDEO_CLASS_START = 0x1001,  \
	USB_Video_CMD_Set_Default_JPEG_Max_Size,  \
	USB_Video_CMD_Complete_Still_Buffer,  \
	USB_Video_CMD_Complete_Video_Buffer,  \
	USB_Video_CMD_Get_Still_Buffer,  \
	USB_Video_CMD_Get_Video_Buffer,  \
	USB_VIDEO_CLASS_END = 0x10FF,  \
	USB_IMAGE_CLASS_START = 0x1100,  \
	USB_IMAGE_MTP_CMD_GET_DESCRIPTION_STRING_1_PTR,  \
	USB_IMAGE_MTP_CMD_GET_DESCRIPTION_STRING_2_PTR,  \
	USB_IMAGE_CLASS_END = 0x11FF,  \


//#endif /*__BUILD_DOM__*/


#define USB_VIDEO_CLASS_CODE  0
#define USB_IMAGE_CLASS_CODE  1


/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/

typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32			u4ep_num;
	DCL_USB_ENDPT_TXFER_TYPE type;
	DCL_USB_EP_DIRECTION		direction;
}USB_DRV_CTRL_EP_COMMON_FUNC_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32 	u4ep_num;
	DCL_USB_DRV_HDLR_TYPE type;
	DCL_USB_FUNC_TYPE_0 hdlr;
}USB_DRV_CTRL_REGISTER_DRV_INFO_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32			u4ep_num;
	DCL_USB_EP_DIRECTION		direction;
	DCL_BOOL 			fg_result;
}USB_DRV_CTRL_EP_CTRL_FUNC_1_T;



typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT8 	u1addr;
	DCL_USB_SET_ADDR_STATE state;
}USB_DRV_CTRL_USB_SET_ADDR_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32  u4ep_num;
	DCL_UINT16 u2data_size;
	DCL_USB_ENDPT_TXFER_TYPE type;
	DCL_BOOL fgdouble_fifo;
}USB_DRV_CTRL_USB_EP_INIT_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32  u4ep_num;
	DCL_USB_ENDPT_TXFER_TYPE ep_type;
	DCL_USB_ENDPT_DMA_USAGE dma_usage_type;
	DCL_BOOL fgis_flush;
	DCL_BOOL fgis_ft_mode;
}USB_DRV_CTRL_EP_ENABLE_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32 u4ep_num;
	DCL_USB_ENDPT_DMA_USAGE dma_usage_type;
}USB_DRV_CTRL_EP_DISABLE_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32			u4ep_num;
	DCL_USB_ENDPT_TXFER_TYPE ep_type;
	DCL_BOOL			fg_is_switch_to_dma;
}USB_DRV_CTRL_EP_CONFIG_TYPE_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32			u4ep_num;
	DCL_USB_EP_STATE 	result;
}USB_DRV_CTRL_EP_STATE_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_USB_TOTAL_FIFO_SIZE fifo_size;
}USB_DRV_CTRL_GET_FIFO_SIZE_T;


typedef struct
{
	DCL_UINT32	u4ip_port;
	DCL_USB_IP_VERSION  ip_version;
}USB_DRV_CTRL_GET_IP_VERSION_T;


typedef struct
{
	DCL_UINT32	u4ip_port;
	DCL_UINT32			u4ep_num;
	DCL_USB_ENDPT_TXFER_TYPE ep_type;
	DCL_BOOL			fg_reset_toggle;
}USB_DRV_CTRL_EP_CTRL_FUNC_2_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32			u4ep_num;
	DCL_UINT32			u4result;
}USB_DRV_CTRL_EP_CTRL_FUNC_3_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32			u4ep_num;
	DCL_USB_ENDPT_TXFER_TYPE ep_type;
	DCL_BOOL			fgresult;
}USB_DRV_CTRL_EP_CTRL_FUNC_4_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32			u4ep_num;
	DCL_USB_EP_DIRECTION 	direction;
	DCL_UINT32			u4count;
}USB_DRV_CTRL_EP_CTRL_FUNC_6_T;


typedef struct
{
	DCL_UINT8			u1_ip_port;
	DCL_BOOL			fg_is_ft_mode;
}USB_DRV_CTRL_EP_CTRL_FUNC_7_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32 			u4ep_num;
	DCL_UINT16 			u2nBytes;
	void 				*paddr;
	DCL_BOOL			fg_force_one_byte_access;
}USB_DRV_CTRL_EP_FIFO_RW_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32  u4ep_num;
	DCL_USB_EP_DIRECTION direction;
	DCL_BOOL fgen;
}USB_DRV_CTRL_EP_STALL_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_BOOL fg_transaction_end;
	DCL_BOOL fg_sent_stall;
}USB_DRV_CTRL_GET_EP_STATUS_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_USB_EP0_DRV_STATE state;
	DCL_BOOL fgstall;
	DCL_BOOL fgend;
}USB_DRV_CTRL_UPDATE_EPSTATE_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32 	u4ep_tx_num;
	DCL_UINT32 	u4ep_rx_num;
	DCL_USB_EP_DIRECTION direction;
	DCL_BOOL 	fgsame_chan;
}USB_DRV_CTRL_DMA_FUNC_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT8 u1dma_chan;
	DCL_BOOL fgenable;
	DCL_UINT8 u1timer_ticks;
}USB_DRV_CTRL_DMA_TIMER_FUNC_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT8 u1dma_chan;
	DCL_BOOL  fgresult;
}USB_DRV_CTRL_DMA_CTRL_FUNC_1_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32  u4ep_num;
	DCL_USB_EP_DIRECTION direction;
	DCL_UINT8 u1chan_num; 
	DCL_BOOL fgsame_chan;
}USB_DRV_CTRL_DMA_CTRL_FUNC_2_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32  u4ep_num;
	DCL_USB_EP_DIRECTION direction;
	DCL_USB_ENDPT_TXFER_TYPE ep_type;
	DCL_UINT32 u4addr;
	DCL_UINT32 u4length;
	DCL_USB_FUNC_TYPE_0 callback;
	DCL_BOOL fgcallback_upd_run;
	DCL_BOOL fgknown_size;
	DCL_USB_DMA_TYPE dma_type;
}USB_DRV_CTRL_DMA_SETUP_FUNC_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_UINT32  u4ep_num;
	DCL_USB_EP_DIRECTION direction;
	DCL_BOOL fgstatus;
}USB_DRV_CTRL_DMA_STATUS_FUNC_T;


typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_USB_TEST_MODE_TYPE test_selector;
}USB_DRV_CTRL_USB_TEST_MODE_FUNC_T;



typedef struct
{
	DCL_UINT32			u4ip_port;
	DCL_USB_PHY_OWNER owner;
}USB_DRV_CTRL_PHY_FUNC_T;

typedef struct
{
  DCL_BOOL is_cdcacm; //Check CDCACM or 1T1R port
} USB_DRV_CTRL_COM_TYPE_QUERY_T;


typedef struct
{
  DCL_BOOL 		enable;
  DCL_UINT32 	u4OwenrId;
  DCL_BOOL		u2Retresult;
  DCL_UINT8		ptransfer_type;	//USB_Transfer_type
} USB_DRV_CTRL_COM_HIGH_SPEED_IF, USB_DRV_CTRL_COM_DIRECT_PATH_IF; //Check CDC ACM use high speed interface


typedef struct
{
	DCL_UINT16 	u2Length;
	DCL_UINT32 	u4OwenrId;
	DCL_UINT16	u2RetSize;
	DCL_UINT8* 	puBuffaddr;
	DCL_UINT8	ptransfer_type;	//USB_Transfer_type
} USB_DRV_CTRL_COM_SEND_DATA;



typedef struct
{
	DCL_UINT16	u2Length;
	DCL_UINT32	u4OwenrId;
	DCL_UINT16	u2RetSize;
	DCL_UINT8*	puBuffaddr;
	DCL_UINT8	umode;
	DCL_UINT8	uescape_char;
	DCL_UINT8	ptransfer_type; //USB_Transfer_type
} USB_DRV_CTRL_COM_SEND_ISR_DATA;


typedef struct
{
	DCL_UINT16 		u2Length;
	DCL_UINT32 		u4OwenrId;
	DCL_UINT16		u2RetSize;
	DCL_UINT8** 	puBuffaddr;
	DCL_UINT8*  	pustatus;
	DCL_UINT8 		ptype; // USB_Requ_type
	DCL_UINT8		ptransfer_type;  //USB_Transfer_type
} USB_DRV_CTRL_COM_GET_DATA;

typedef struct
{
	DCL_UINT32 		u4OwenrId;
} USB_DRV_CTRL_COM_PUSH_DATA;



typedef struct
{
	DCL_BOOL	  u2Retresult;
} USB_DRV_CTRL_COM_RESPONSE;

typedef struct
{    
	DCL_BOOL	  u2set;
	DCL_BOOL	  u2Retresult;
} USB_DRV_CTRL_SET;

typedef struct
{    
	DCL_BOOL fgbset;		
	DCL_UINT32 		u4OwenrId;
} USB_DRV_CTRL_COM_RB_THRESHOLD_EN;

typedef struct
{
  DCL_UINT8 u1ftPort; //Check CDCACM or 1T1R port
} USB_DRV_CTRL_COM_FT_PORT;

typedef struct
{
  DCL_UINT32 u4info; 
} USB_DRV_CTRL_COM_INFO;

typedef struct
{
	DCL_UINT8	  uindex;
	DCL_UINT32	  u4max_size;
} USB_VIDEO_CTRL_FUNC1_T;

typedef struct
{
	DCL_UINT8*	  uaddr;
	DCL_UINT32	  u4size;
	DCL_UINT32	  u4time;
	DCL_UINT32	  u4size_type;			
} USB_VIDEO_CTRL_FUNC2_T;

typedef struct
{
	DCL_UINT8*	  u2Retresult;
} USB_VIDEO_CTRL_FUNC3_T;

typedef struct
{
	DCL_UINT16*	  u2String;
} USB_IMAGE_CTRL_FUNC1_T;



#define USB_DRV_CTRLS \
  USB_DRV_CTRL_EP_COMMON_FUNC_T		rUSB_Common_Struct;  \
  USB_DRV_CTRL_REGISTER_DRV_INFO_T		rDrv_Info; \
  USB_DRV_CTRL_EP_CTRL_FUNC_1_T		rEP_Ctrl_Func_1; \
  USB_DRV_CTRL_USB_SET_ADDR_T			rUSB_Set_Addr; \
  USB_DRV_CTRL_USB_EP_INIT_T			rUSB_Ep_Init; \
  USB_DRV_CTRL_EP_ENABLE_T				rEP_Enable; \
  USB_DRV_CTRL_EP_DISABLE_T				rEP_Disable; \
  USB_DRV_CTRL_EP_CONFIG_TYPE_T		rEP_Config_Type; \
  USB_DRV_CTRL_EP_STATE_T				rEP_Get_State; \
  USB_DRV_CTRL_EP_CTRL_FUNC_2_T		rEP_Ctrl_Func_2; \
  USB_DRV_CTRL_EP_CTRL_FUNC_3_T		rEP_Ctrl_Func_3; \
  USB_DRV_CTRL_EP_CTRL_FUNC_4_T		rEP_Ctrl_Func_4; \
  USB_DRV_CTRL_EP_CTRL_FUNC_6_T		rEP_Ctrl_Func_6; \
  USB_DRV_CTRL_EP_FIFO_RW_T				rEP_Fifo_Rw; \
  USB_DRV_CTRL_EP_STALL_T				rEP_Stall; \
  USB_DRV_CTRL_GET_EP_STATUS_T			rEP_Status; \
  USB_DRV_CTRL_UPDATE_EPSTATE_T		rEP_State; \
  USB_DRV_CTRL_DMA_FUNC_T				rDMA_Func; \
  USB_DRV_CTRL_DMA_TIMER_FUNC_T		rDMA_Timer_Func; \
  USB_DRV_CTRL_DMA_CTRL_FUNC_1_T		rDMA_Ctrl_Func_1; \
  USB_DRV_CTRL_DMA_CTRL_FUNC_2_T		rDMA_Ctrl_Func_2; \
  USB_DRV_CTRL_DMA_SETUP_FUNC_T		rDMA_Setup_Func; \
  USB_DRV_CTRL_DMA_STATUS_FUNC_T		rDMA_Status_Func; \
  USB_DRV_CTRL_USB_TEST_MODE_FUNC_T	rTest_Mode_Func; \
  USB_DRV_CTRL_PHY_FUNC_T				rPhy_Ctrl_Func; \
  USB_DRV_CTRL_COM_TYPE_QUERY_T			rComport_Ctrl_Func; \
  USB_DRV_CTRL_COM_HIGH_SPEED_IF		rComport_Ctrl_Fun2; \
  USB_DRV_CTRL_COM_SEND_DATA			rComport_Ctrl_Fun3; \
  USB_DRV_CTRL_COM_GET_DATA				rComport_Ctrl_Fun4; \
  USB_DRV_CTRL_COM_RESPONSE				rComport_Ctrl_Fun5; \
  USB_DRV_CTRL_COM_SEND_ISR_DATA		rComport_Ctrl_Fun6; \
  USB_DRV_CTRL_COM_RB_THRESHOLD_EN		rComport_Ctrl_Fun7; \
  USB_DRV_CTRL_COM_FT_PORT	  rComport_Ctrl_Fun8; \
  USB_DRV_CTRL_COM_INFO		rComport_Ctrl_Fun10; \
  USB_VIDEO_CTRL_FUNC1_T				rVideo_Ctrl_Fun1; \
  USB_VIDEO_CTRL_FUNC2_T				rVideo_Ctrl_Fun2; \
  USB_VIDEO_CTRL_FUNC3_T				rVideo_Ctrl_Fun3; \
  USB_IMAGE_CTRL_FUNC1_T				rImage_Ctrl_Fun1; \
  USB_DRV_CTRL_SET				  	rComport_Ctrl_Fun9; \
  USB_DRV_CTRL_COM_PUSH_DATA		rComport_Ctrl_Fun11; \

#endif // #ifndef __DCL_USB_DRV_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT



#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_USB_DRV_H_PROTOTYPE__
#define __DCL_USB_DRV_H_PROTOTYPE__


typedef DCL_STATUS (*DCL_USB_CTRL_API)(DCL_CTRL_DATA_T *data);
typedef void(*DCL_USB_CLASS_API)(DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);


/*************************************************************************
* FUNCTION
*  DclUSB_DRV_Initialize
*
* DESCRIPTION
*  This function is to initialize USB_DRV module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclUSB_DRV_Initialize(void);
/*************************************************************************
* FUNCTION
*  DclUSB_DRV_Open
*
* DESCRIPTION
*  This function is to open the USB_DRV module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_USB
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed
*  Other value: A valid handle
*
*************************************************************************/
extern DCL_HANDLE DclUSB_DRV_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION
*  DclUSB_DRV_ReadData
*
* DESCRIPTION
*  This function is not supported for the USB_DRV module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclUSB_DRV_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclUSB_DRV_WriteData
*
* DESCRIPTION
*  This function is not supported for the USB_DRV module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclUSB_DRV_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclUSB_DRV_Configure
*
* DESCRIPTION
*  This function is not supported for the USB_DRV module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclUSB_DRV_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION
*  DclUSB_DRV_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the USB_DRV module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclUSB_DRV_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, DCL_UINT8 index,void *class_handler);
/*************************************************************************
* FUNCTION
*  DclUSB_DRV_Control
*
* DESCRIPTION
*  This function is to send command to control the USB_DRV module.
*
* PARAMETERS
*  handle: A valid handle return by DclSADC_Open()
*  cmd: A control command for ADC module
*          1. ADC_CMD_CREATE_OBJECT: to create measurement object
*          2. ADC_CMD_MODIFY_PARAM: to change measurement parameters
*          3. ADC_CMD_START_MEASURE: to start measurement item
*          4. ADC_CMD_STOP_MEASURE: to stop measurement item
*  data: The data of the control command
*          1. ADC_CMD_CREATE_OBJECT: pointer to a ADC_CTRL_CREATE_OBJECT_T structure
*          2. ADC_CMD_MODIFY_PARAM: pointer to a ADC_CTRL_MODIFY_PARAM_T structure
*          3. ADC_CMD_START_MEASURE: a null pointer
*          4. ADC_CMD_STOP_MEASURE: a null pointer
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
extern DCL_STATUS DclUSB_DRV_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION
*  DclUSB_DRV_Close
*
* DESCRIPTION
*  This function is to close the SW USB_DRV module.
*
* PARAMETERS
*  handle: the returned handle value of DclUSB_Drv_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclUSB_DRV_Close(DCL_HANDLE handle);


#endif // #ifndef __DCL_USB_DRV_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE

