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

//#include "usb_phy_drv.h"
#include "uart_sw.h"
#include "drv_comm.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_general_types.h"
#include "dcl.h"

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined (DRV_USB_IP_V3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__USB_STRESS_TEST__)
/* under construction !*/
#elif defined(__USB_SUPPORT_MULTIPLE_DMA_CHANNEL__)
	#ifdef __USB_MODEM_CARD_SUPPORT__
/* under construction !*/
	#else
/* under construction !*/
	#endif
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
#else  //USB_IP_V2 /V1 /V1_plus
/* under construction !*/
#if defined (DRV_USB_IP_V1_PLUS)
/* under construction !*/
/* under construction !*/
#else	//V2 and V1
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __USB_SUPPORT_MULTIPLE_DMA_CHANNEL__
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
#if defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)
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
#elif defined(DRV_USB_IP_V1_PLUS)
/* under construction !*/
#endif
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifdef  __USB_HW_DBG__
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
#else
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
/* under construction !*/
/* under construction !*/
#endif

// MoDIS parser skip start
/* driver info functions */
//extern void USB_Init_Drv_Info(kal_bool is_ft_mode);
//extern void USB_ResetDrv_Info(void);
//extern void USB_Register_Drv_Info(USB_DRV_HDLR_TYPE type, kal_uint32 ep_num, usb_drv_intr_handler_ptr hdlr);
//extern void USB_Set_UnMask_Irq(kal_bool set);
extern kal_bool USB_HW_Get_UnMask_Irq(void);   // no DCL
//extern kal_bool USB_Get_EP_Stall_Status(kal_uint8 ep_num, USB_EP_DIRECTION direction);
//extern void USB_Drv_Activate_ISR(void);
//extern void USB_Drv_Create_ISR(void);
//extern void USBDMA_Drv_Create_ISR(void);
//extern void USBDMA_Drv_Activate_ISR(void);


/* system ctrl functions */
//extern void USB_PDNmode(kal_bool pdn_en);
//extern void USB_Pull_Up_DP_Line(void);
//extern void USB_Set_DMA_Stop_Flag(void);
//extern void USB_Reset_Drv(void);
//extern void USB_Initialize_Drv_Phase1(void);
//extern void USB_Initialize_Drv_Phase2(kal_bool b_is_reset);
//extern void USB_Release_Drv(void);
extern void USB_EnSysIntr(void);  // no DCL
//extern void USB_SetAddress(kal_uint8 addr, USB_SET_ADDR_STATE state);
//extern kal_uint16 USB_GetFrameCount(void);

/* EP ctrl functinos */
//extern void USB_TxEPInit(kal_uint8 ep_num, kal_uint16 data_size, USB_ENDPT_TXFER_TYPE type,kal_bool double_fifo);
//extern void USB_RxEPInit(kal_uint8 ep_num, kal_uint16 data_size, USB_ENDPT_TXFER_TYPE type,kal_bool double_fifo);

//extern kal_uint16 USB_TXEP_PK_SIZE(kal_uint32 ep_num);
//extern kal_uint16 USB_RXEP_PK_SIZE(kal_uint32 ep_num);
//extern void USB_TxEPEn(kal_uint8 ep_num, USB_ENDPT_TXFER_TYPE ep_type, USB_ENDPT_DMA_USAGE dma_usage_type, kal_bool is_flush, kal_bool is_ft_mode);
//extern void USB_TxEPDis(kal_uint8 ep_num, USB_ENDPT_DMA_USAGE dma_usage_type);
//extern void USB_RxEPEn(kal_uint8 ep_num, USB_ENDPT_TXFER_TYPE ep_type, USB_ENDPT_DMA_USAGE dma_usage_type, kal_bool is_flush, kal_bool is_ft_mode);
//extern void USB_RxEPDis(kal_uint8 ep_num, USB_ENDPT_DMA_USAGE dma_usage_type);
//extern void USB_Config_TxEP_Type(kal_uint8 ep_num, USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_is_use_dma);
//extern void USB_Config_RxEP_Type(kal_uint8 ep_num, USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_is_use_dma);
//extern void USB_TxEPClearDataTog(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type);
//extern void USB_RxEPClearDataTog(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type);
//extern USB_EP_STATE USB_TxEP_Usage(kal_uint32 ep_num);
//extern USB_EP_STATE USB_RxEP_Usage(kal_uint32 ep_num);
//extern void USB_EPFIFORead(kal_uint32 ep_num, kal_uint16 nBytes, void *pDst, kal_bool force_one_byte_access);
//extern void USB_HW_EPFIFOWrite (kal_uint32 ep_num, kal_uint16 nBytes, void *pSrc);
//extern void USB_CtrlEPStall(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_bool stall_enable);



//extern void USB_Get_EP0_Status(kal_bool *p_transaction_end, kal_bool *p_sent_stall);
//extern void USB_Update_EP0_State(USB_EP0_DRV_STATE state, kal_bool stall, kal_bool end);
//extern kal_uint32 USB_EP0_Pkt_Len(void);
extern void USB_HW_EP_Tx_Ready(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type);
//extern kal_uint32 USB_EP_Rx_Pkt_Len(kal_uint32 ep_num);
extern void USB_HW_EP_Rx_Ready(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type);
extern kal_bool USB_HW_Is_EP_Tx_Empty(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type);
//extern kal_bool USB_Is_EP_Bulk_Tx_Empty(kal_uint32 ep_num);
//extern kal_bool USB_Is_EP_Bulk_Rx_Empty(kal_uint32 ep_num);
//extern void USB_Clear_Tx_EP_FIFO(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_reset_toggle);
//extern void USB_Clear_Rx_EP_FIFO(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_reset_toggle);

/* DMA control functions */
//extern void USB_Get_DMA_Channel(kal_uint32 ep_tx_num, kal_uint32 ep_rx_num, USB_EP_DIRECTION direction, kal_bool same_chan);
//extern void USB_HW_Stop_DMA_Channel(kal_uint32 ep_num, USB_EP_DIRECTION direction);
//extern void USB_Free_DMA_Channel(kal_uint32 ep_tx_num, kal_uint32 ep_rx_num, USB_EP_DIRECTION direction, kal_bool same_chan);
//extern void USB_DMA_Setup(kal_uint32 ep_num, USB_EP_DIRECTION direction, USB_ENDPT_TXFER_TYPE ep_type, kal_uint32 addr, kal_uint32 length,
//					usb_dma_callback callback, kal_bool callback_upd_run, kal_bool known_size, USB_DMA_TYPE dma_type);

//extern kal_bool USB_DMA_Get_Run_Status(kal_uint32 ep_num, USB_EP_DIRECTION direction);
//extern void USB_DMA_Set_Run_Status(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_bool status);



extern void USB_DMA_Callback(kal_uint8 dma_chan);  // no DCL
extern void USB_DMAQ_Callback(kal_uint8 dma_chan,USB_EP_DIRECTION direction);


extern void USB_Enable_DMA_Timer_Count(kal_uint8 dma_chan, kal_bool enable, kal_uint8 timer_ticks);
extern kal_bool USB_Check_DMA_Time_Out(kal_uint8 dma_chan);
//extern kal_uint32 USB_Get_DMA_Real_Count(kal_uint32 ep_num, USB_EP_DIRECTION direction);

//extern void USB_DMA_Limiter(kal_uint32 dma_limit_num);

//extern void USB_Switch_DMA_Burst_mode(kal_bool b_enable);
//extern void USB_Register_DMA_Channel(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_uint8 chan_num, kal_bool same_chan);
//extern void USB_Set_DMA_Burst_Mode(kal_uint8 dma_burst_mode);


//extern kal_uint8 USB_Get_DMA_Channel_Num(kal_uint8 ep_num, USB_EP_DIRECTION direction);  // no DCL


#if defined(DRV_USB_IP_V3)
//extern kal_bool USB_Is_High_Speed(void);
//extern void USB_High_Speed_Enable(kal_bool b_enable);
//extern void USB_Enter_Test_Mode(USB_TEST_MODE_TYPE test_selector);
//extern void USB_Reset_FIFO(void);
//extern kal_bool USB_Is_FIFO_Full(void);
//extern kal_bool USB_Is_Suspend_Power_Status(void);

#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
extern kal_bool USB_Check_DM_Value_Is_High(void);  // no DCL
extern kal_bool USB_Check_DP_Value_Is_High(void);   // no DCL
extern void USB_Charger_Detect_Init(void);   // no DCL
extern kal_bool USB_Detect_Is_Charger_In(void);   // no DCL
extern void USB_Check_Standard_Charger(void);   // no DCL
extern kal_bool USB_Detect_Is_Standard_Charger_In(void);   // no DCL
extern void USB_Charger_Detect_Release(void);   // no DCL
#endif




#endif

/* polling functions (used for exception log) */
//extern void USB_Polling_Transmit_Done(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type);
//extern void USB_Polling_Transmit_Data(kal_uint32 ep_num, USB_EP_DIRECTION direction, USB_ENDPT_TXFER_TYPE ep_type, kal_uint32 addr, kal_uint32 length,
//				usb_dma_callback callback, kal_bool callback_upd_run, kal_bool known_size, USB_DMA_TYPE dma_type);

//extern void USB_Polling_Recv_Data();
//extern void USB_Clr_RX_EP_ISR(kal_uint32 ep_num);
//extern kal_bool USB_Get_RX_EP_ISR_Status(kal_uint32 ep_num);
//extern void USB_Read_TX_ISR_Status(void);
extern void USB_HISR(void);  // no DCL

								
//extern void USB_Phy_Enable(USB_PHY_OWNER owner);
//extern void USB_Phy_Disable(USB_PHY_OWNER owner);

//extern void USBDL_Update_USB_Download_Mode(void);
//extern kal_bool USBDL_Is_USB_Download_Mode(void);

//extern void USB_EP_Reset_Data_Toggle(kal_uint32 ep_num, USB_EP_DIRECTION direction);

//extern void USB_Debug_Information(kal_uint32 ep_num, USB_EP_DIRECTION direction,kal_bool check_error);
//extern void USB_DUMP(void);

//extern void USB_PDNEnable(void);
//extern void USB_PDNDisable(void);


//extern void USB_EP_DMA_Running_Check(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_uint32 line);
//extern void USB_EP_Check(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_uint32 line);



// MoDIS parser skip end

#ifndef __USB_ENABLE__
// MoDIS parser skip start
/* driver info functions */
extern void USB_Acm_Ring_Buffer_Threshold_Enable(UART_PORT port, kal_bool bset, module_type ownerid);
extern kal_uint8 USB_Acm_FT_Port(void);
extern kal_uint16 USB2UART_FT_Get_Max_Len(void);
extern void USB2UART_FT_Tx_Byte(kal_uint8* addr, kal_uint16 len);
extern void USB2UART_FT_Tx_Word(kal_uint32* addr, kal_uint16 len);
extern void USB2UART_FT_Tx_Stop(void);
extern kal_uint16 USB2UART_FT_Rx_Byte(kal_uint8* addr, kal_uint16 len);
// MoDIS parser skip end
#endif


#endif //USB_DRV_H



