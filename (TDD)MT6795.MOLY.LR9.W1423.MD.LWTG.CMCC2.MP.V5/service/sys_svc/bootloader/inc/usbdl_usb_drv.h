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
 *    usb_drv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file intends for usb hardware related function definitions
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
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef USB_DRV_H
#define USB_DRV_H

//#include "kal_non_specific_general_types.h"
#include "dcl.h"


#if 0
/* under construction !*/
/* under construction !*/
#if defined (DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef USB_SUPPORT_MUTIPLE_APP
/* under construction !*/
#else
/* under construction !*/
#endif
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
#ifndef __USB_HS_ENABLE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#else  //USB_IP_V2 /V1
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef USB_SUPPORT_MUTIPLE_APP
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
/* under construction !*/
#elif  defined(DRV_USB_IP_V2) 
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_USB_IP_V1)
/* under construction !*/
#elif  defined(DRV_USB_IP_V2) 
/* under construction !*/
#elif  defined(DRV_USB_IP_V1_PLUS)
/* under construction !*/
#endif
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
#endif

/* USB PDN owner id */
typedef enum
{
	USB_PDN_OWNER_USB = 0,
	USB_PDN_OWNER_IRDA,
	USB_PDN_OWNER_UPLL
}USB_PDN_OWNER;


/* add for debug*/
typedef enum
{
	USB_CTRL_STALL_ENTRY_1 = 0,
	USB_CTRL_STALL_ENTRY_2,
	USB_CTRL_STALL_ENTRY_3,
	USB_CTRL_STALL_ENTRY_4,
	USB_CTRL_STALL_ENTRY_5		/* for image class */
}USB_CTRL_STALL_ENTRY;


// MoDIS parser skip start
/* driver info functions */
extern void USB_Init_Drv_Info(kal_bool is_ft_mode);
extern void USB_ResetDrv_Info(void);
extern void USB_Register_Drv_Info(USB_DRV_HDLR_TYPE type, kal_uint32 ep_num, usb_drv_intr_handler_ptr hdlr);
extern kal_uint32 USB_Get_HW_Error_Count(void);
extern void USB_Set_UnMask_Irq(kal_bool set);
extern kal_bool USB_Get_UnMask_Irq(void);
extern kal_bool USB_Get_EP_Stall_Status(kal_uint8 ep_num, USB_EP_DIRECTION direction);
extern void USB_Drv_Activate_ISR(void);
extern void USB_Drv_Create_ISR(void);



/* system ctrl functions */
extern void USB_PDNEnable(USB_PDN_OWNER owner);
extern void USB_PDNDisable(USB_PDN_OWNER owner);
extern void USB_PDNmode(kal_bool pdn_en);
extern void USB_Pull_Up_DP_Line(void);
extern void USB_Set_DMA_Stop_Flag(void);
extern void USB_Reset_Drv(void);
extern void USB_Release_Drv(void);
extern void USB_EnSysIntr(void);
extern void USB_SetAddress(kal_uint8 addr, USB_SET_ADDR_STATE state);
extern kal_uint16 USB_GetFrameCount(void);

/* EP ctrl functinos */
extern void USB_TxEPInit(kal_uint8 ep_num, kal_uint16 data_size, USB_ENDPT_TXFER_TYPE type);
extern void USB_RxEPInit(kal_uint8 ep_num, kal_uint16 data_size, USB_ENDPT_TXFER_TYPE type);
extern void USB_EP0En(void);
extern void USB_TxEPEn(kal_uint8 ep_num, USB_ENDPT_TXFER_TYPE ep_type, USB_ENDPT_DMA_USAGE dma_usage_type, kal_bool is_flush, kal_bool is_ft_mode);
extern void USB_RxEPEn(kal_uint8 ep_num, USB_ENDPT_TXFER_TYPE ep_type, USB_ENDPT_DMA_USAGE dma_usage_type, kal_bool is_flush, kal_bool is_ft_mode);
extern void USB_TxEPDis(kal_uint8 ep_num, USB_ENDPT_DMA_USAGE dma_usage_type);
extern void USB_RxEPDis(kal_uint8 ep_num, USB_ENDPT_DMA_USAGE dma_usage_type);
extern void USB_Config_TxEP_Type(kal_uint8 ep_num, USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_is_use_dma);
extern void USB_Config_RxEP_Type(kal_uint8 ep_num, USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_is_use_dma);
extern USB_EP_STATE USB_RxEP_Usage(kal_uint8 ep_num);
extern void USB_TxEPClearDataTog(kal_uint8 ep_num);
//extern void USB_RxEPClearDataTog(kal_uint8 ep_num);
extern void USB_EPFIFORead(kal_uint8 ep_num, kal_uint16 nBytes, void *pDst);
extern void USB_EPFIFORead_Shift(kal_uint8 ep_num, kal_uint16 nBytes, void *pDst, kal_uint32 shift);
extern void USB_EPFIFOWrite (kal_uint8 ep_num, kal_uint16 nBytes, void *pSrc);
extern void USB_CtrlEPStall(kal_uint8 ep_num, USB_EP_DIRECTION direction, kal_bool en, USB_CTRL_STALL_ENTRY entry);
extern void USB_Get_EP0_Status(kal_bool *p_transaction_end, kal_bool *p_sent_stall);
extern void USB_Update_EP0_State(USB_EP0_DRV_STATE state, kal_bool stall, kal_bool end);
extern kal_uint32 USB_EP0_Pkt_Len(void);
extern void USB_EP_Bulk_Tx_Ready(kal_uint8 ep_num);
extern kal_uint32 USB_EP_Rx_Pkt_Len(kal_uint8 ep_num);
extern void USB_EP_Bulk_Rx_Ready(kal_uint8 ep_num);
extern kal_bool USB_Is_EP_Bulk_Tx_Empty(kal_uint8 ep_num);
extern void USB_Clear_Tx_EP_FIFO(kal_uint8 ep_num, USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_reset_toggle);
extern void USB_Clear_Rx_EP_FIFO(kal_uint8 ep_num, USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_reset_toggle);


#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
extern kal_bool USB_Is_High_Speed(void);
extern kal_bool USB_Speed_Read_Is_HS(void);
extern void USB_High_Speed_Enable(kal_bool b_enable);
extern void USB_Reset_FIFO(void);
extern kal_bool USB_FIFO_Full(void);

#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
extern void USB_Charger_Detect_Init(void);
extern kal_bool USB_Detect_Is_Charger_In(void);
extern void USB_Check_Standard_Charger(void);
extern kal_bool USB_Detect_Is_Standard_Charger_In(void);
extern void USB_Charger_Detect_Release(void);
#endif

#endif  //USB_IP_V3

/* polling functions (used for exception log) */
extern void USB_Polling_Transmit_Done(kal_uint8 ep_num);
extern void USB_Polling_Transmit_Data(kal_uint8 ep_num, USB_EP_DIRECTION direction, USB_ENDPT_TXFER_TYPE ep_type, kal_uint32 addr, kal_uint32 length,
				usb_dma_callback callback, kal_bool callback_upd_run, kal_bool known_size, USB_DMA_TYPE dma_type);
extern void USB_Polling_Recv_Data(kal_uint8 ep_num);

extern void USB_HISR(void);
																
extern void USB_Phy_Enable(USB_PHY_OWNER owner);
extern void USB_Phy_Disable(USB_PHY_OWNER owner);

#if (defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__))
extern void USB_UART_Share(kal_bool USB_Mode);
#endif

extern kal_bool USBDL_Update_USB_Download_Mode(void);
extern kal_bool USBDL_Is_USB_Download_Mode(void);


#endif //USB_DRV_H
 


