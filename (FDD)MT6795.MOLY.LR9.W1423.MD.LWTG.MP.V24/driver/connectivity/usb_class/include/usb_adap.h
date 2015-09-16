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
 *    usb_adap.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    This file intends for usb adaption layer between HW driver and class drivers
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef USB_ADAP_H
#define USB_ADAP_H


//#include "kal_non_specific_general_types.h"
#include "usb_comm.h"
#include "dcl.h"
//#include "usb_drv.h"
#include "usb.h"
#include "usb_mode.h"

//#if defined(__MTK_TARGET__)
//#if defined (__ARMCC_VERSION)
//#define INLINE static __inline
//#elif defined (__GNUC__)
//#define INLINE inline
//#endif /* ARMCC , GNUC */
//#else  /* __MTK_TARGET__ */
//#define INLINE __inline
//#endif /* __MTK_TARGET__ */


static INLINE USB_DEVICE_STATE USB_Get_Device_State(void)
{
	return gUsbDevice.nDevState;
}

static INLINE void USB_Set_Device_State(USB_DEVICE_STATE usb_device_state)
{
	gUsbDevice.nDevState = usb_device_state;
}

static INLINE USB_DEVICE_TYPE USB_Get_Device_Type(void)
{
	return gUsbDevice.device_type;
}

static INLINE void USB_Set_Device_Type(USB_DEVICE_TYPE usb_device_type)
{
	gUsbDevice.device_type = usb_device_type;
}

static INLINE USB_EP0_STATE USB_Get_Endpoint0_State(void)
{
	return gUsbDevice.ep0_state;
}

static INLINE void USB_Set_Endpoint0_State(USB_EP0_STATE ep0_state)
{
	gUsbDevice.ep0_state = ep0_state;
}

static INLINE USB_Comport_Boot_Status USB_Get_Comport_Boot_Status(void)
{
	return g_UsbMode.usb_comport_boot;
}

static INLINE void USB_Release(void)
{

}

static INLINE void USB_Register_EP0_RxHdlr(usb_ep0_rx_ptr handler)
{
	gUsbDevice.ep0_rx_handler = handler;
}



extern void USB_Register_CreateFunc(kal_char* if_name, usb_create_if_func_ptr if_create_func, usb_void_func if_init_func,
				usb_void_func if_enable_func, usb_speed_if_func_ptr if_speed_func, usb_void_func if_resume_func);
extern void USB_Register_Device_Code(kal_uint8 device_code, kal_uint8 subclass_code, kal_uint8 protocol_code, kal_uint16 product_code);
extern void USB_DeRegister_CreateFunc(void);
//extern void USB_DeRegister_Device_Code(void);
extern Usb_Ep_Info* USB_Get_Intr_Ep(kal_uint8 *p_num);
#ifdef  __USB_SUPPORT_ISO_PIPE__
extern Usb_Ep_Info* USB_Get_Iso_Tx_Ep(kal_uint8 *p_num);
#endif
#if  defined(__USB_SUPPORT_ISO_PIPE__)||defined(__MBIM_SUPPORT__)
extern Usb_Alternate_Interface_Info* USB_Get_Interface_Alternate_Setting(kal_uint8 p_num);
#endif

extern Usb_Ep_Info* USB_Get_Bulk_Tx_Ep(kal_uint8 *p_num);
extern Usb_Ep_Info* USB_Get_Bulk_Rx_Ep(kal_uint8 *p_num);
extern Usb_Interface_Info* USB_Get_Interface_Number(kal_uint8 *p_num);
extern kal_uint8 USB_Get_String_Number(void *usb_string);
extern Usb_IAD_Dscr* USB_Get_IAD_Number(void);

extern void USB_Release_Device_Status(void);
extern void USB_Register_EP0_Class_CmdHdlr(kal_uint8 cmd, usb_ep0_cmd_ptr handler);
extern void USB_Init(USB_DEVICE_TYPE type, kal_bool b_enable, kal_bool is_ft_mode);
//extern void USB_Release(void);
//extern void USB_Register_EP0_RxHdlr(usb_ep0_rx_ptr handler);
void USB_Mask_USB_CORE(USB_MASK_OWNER owner);
void USB_UnMask_USB_CORE(USB_MASK_OWNER owner);
extern void USB_UnMask_Irq(USB_MASK_OWNER owner);
extern void USB_Mask_Irq(USB_MASK_OWNER owner);
extern void USB_Generate_EP0Data(Usb_Ep0_Status*pep0state, Usb_Command*pcmd, void *data, kal_int32 len);


extern void USB_Register_Drv_Info(USB_DRV_HDLR_TYPE type, kal_uint32 ep_num, usb_drv_intr_handler_ptr hdlr);
extern void USB_Set_UnMask_Irq(kal_bool set);
extern kal_bool USB_Get_UnMask_Irq(void);
extern kal_uint16 USB_GetFrameCount(void);
extern void USB_PDNmode(kal_bool pdn_en);


extern void USB_TxEPEn(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type, USB_ENDPT_DMA_USAGE dma_usage_type, kal_bool is_flush, kal_bool is_ft_mode);
extern void USB_TxEPDis(kal_uint32 ep_num, USB_ENDPT_DMA_USAGE dma_usage_type);
extern void USB_RxEPEn(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type, USB_ENDPT_DMA_USAGE dma_usage_type, kal_bool is_flush, kal_bool is_ft_mode);
extern void USB_RxEPDis(kal_uint32 ep_num, USB_ENDPT_DMA_USAGE dma_usage_type);
extern void USB_Config_TxEP_Type(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_is_use_dma);
extern void USB_Config_RxEP_Type(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_is_use_dma);
extern void USB_TxEPClearDataTog(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type);
extern void USB_RxEPClearDataTog(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type);
extern USB_EP_STATE USB_TxEP_Usage(kal_uint32 ep_num);
extern USB_EP_STATE USB_RxEP_Usage(kal_uint32 ep_num);
extern void USB_EPFIFORead(kal_uint32 ep_num, kal_uint16 nBytes, void *pDst, kal_bool force_one_byte_access);
extern void USB_EPFIFOWrite (kal_uint32 ep_num, kal_uint16 nBytes, void *pSrc);
extern void USB_CtrlEPStall(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_bool stall_enable);
//extern void USB_Get_EP0_Status(kal_bool *p_transaction_end, kal_bool *p_sent_stall);
extern void USB_Update_EP0_State(USB_EP0_DRV_STATE state, kal_bool stall, kal_bool end);
extern kal_uint32 USB_EP0_Pkt_Len(void);
extern void USB_EP_Tx_Ready(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type);
extern kal_uint32 USB_EP_Rx_Pkt_Len(kal_uint32 ep_num);
extern void USB_EP_Rx_Ready(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type);
extern kal_bool USB_Is_EP_Tx_Empty(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type);
extern kal_bool USB_Is_EP_Rx_Empty(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type);
extern void USB_Clear_Tx_EP_FIFO(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_reset_toggle);
extern void USB_Clear_Rx_EP_FIFO(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_reset_toggle);

/* DMA control functions */
extern void USB_Get_DMA_Channel(kal_uint32 ep_tx_num, kal_uint32 ep_rx_num, USB_EP_DIRECTION direction, kal_bool same_chan);
extern void USB_Stop_DMA_Channel(kal_uint32 ep_num, USB_EP_DIRECTION direction);
extern void USB_Free_DMA_Channel(kal_uint32 ep_tx_num, kal_uint32 ep_rx_num, USB_EP_DIRECTION direction, kal_bool same_chan);
extern void USB_DMA_Setup(kal_uint32 ep_num, USB_EP_DIRECTION direction, USB_ENDPT_TXFER_TYPE ep_type, kal_uint32 addr, kal_uint32 length,
					usb_dma_callback callback, kal_bool callback_upd_run, kal_bool known_size, USB_DMA_TYPE dma_type);

extern kal_bool USB_DMA_Get_Run_Status(kal_uint32 ep_num, USB_EP_DIRECTION direction);
extern void USB_DMA_Set_Run_Status(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_bool status);
extern void USB_Set_DMA_Limiter(kal_uint32 dma_limit_num);


extern void USB_Switch_DMA_Burst_mode(kal_bool b_enable);
extern void USB_Register_DMA_Channel(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_uint8 chan_num, kal_bool same_chan);
extern void USB_Set_DMA_Burst_Mode(kal_uint8 dma_burst_mode);

extern kal_bool USB_Is_High_Speed(void);

extern void USB_Enter_Test_Mode(USB_TEST_MODE_TYPE test_selector);
//extern void USB_Reset_FIFO(void);
extern kal_bool USB_Is_FIFO_Not_Empty(void);
extern kal_bool USB_Is_Suspend_Power_Status(void);

extern void USB_Polling_Transmit_Done(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type);
extern void USB_Polling_Transmit_Data(kal_uint32 ep_num, USB_EP_DIRECTION direction, USB_ENDPT_TXFER_TYPE ep_type, kal_uint32 addr, kal_uint32 length,
				usb_dma_callback callback, kal_bool callback_upd_run, kal_bool known_size, USB_DMA_TYPE dma_type);
extern void USB_Polling_Recv_Data(void);


extern void USB_Clr_RX_EP_ISR(kal_uint32 ep_num);
extern kal_bool USB_Get_RX_EP_ISR_Status(kal_uint32 ep_num);

//extern kal_bool USBDL_Is_USB_Download_Mode(void);
//extern kal_bool USBDL_Is_USB_Fast_Meta_Mode(void);


extern void USB_Debug_Information(kal_uint32 ep_num, USB_EP_DIRECTION direction,kal_bool check_error);
extern void USB_DUMP(void);

extern DCL_USB_IP_VERSION USB_IP_Version(void);


extern kal_uint32 USB_Intr_Max_Packet_Size(void);
extern kal_uint32 USB_Bulk_Max_Packet_Size(void);
#ifdef  __USB_SUPPORT_ISO_PIPE__
extern kal_uint32 USB_Iso_Max_Packet_Size(void);
#endif

#ifdef __USB_HS_ENABLE__	
extern kal_uint32 USB_Speed_Reset_Packet_Size(kal_bool b_other_speed);
#endif

extern DCL_HANDLE g_USB_Dcl_Handle;

typedef void (*usb_hisr)(void);


//===========================  DCL interface to other module =====================================//

extern void USB_GPTI_StartItem(kal_uint32 handle,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter);
extern void USB_GPTI_StopItem(kal_uint32 handle);
extern void USB_GPTI_GetHandle(kal_uint32* handle);
extern void USB_GPTI_ReleaseHandle(kal_uint32* handle);
//extern kal_uint32 USB_GPTI_GetHandle(void);
//extern kal_uint32 USB_GPTI_ReleaseHandle(kal_uint32 handle);


#ifdef WEBCAM_SUPPORT
extern void USB_GPT3_Start(void);
extern void USB_GPT3_Stop(void);
extern kal_uint32 USB_GPT3_return_current_count(void);
#endif


extern void USB_CHR_USB_EINT_UnMask(void);

//extern kal_bool USB_INT_USBBoot(void);

//extern void USB_BMT_NO_CHARGING_OUT(kal_bool cable_in);

static INLINE kal_bool USB_INT_USBBoot(void)
{
	DCL_HANDLE g_PW_Dcl_Handle;
	PW_CTRL_IS_USB_BOOT CtrlVal;

	g_PW_Dcl_Handle = DclPMU_Open(DCL_PW, FLAGS_NONE);
	DclPW_Control(g_PW_Dcl_Handle, PW_CMD_IS_USB_BOOT,(DCL_CTRL_DATA_T *)&CtrlVal);
	return (kal_bool)CtrlVal.val;
}

static INLINE void USB_Get_Current_Table(void)
{
	DCL_HANDLE pmu_handle; // add for usb charging 

	pmu_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(pmu_handle, CHR_GET_CHR_CURRENT_LIST, (DCL_CTRL_DATA_T *)&gUsbDevice.get_chr_current_list);
	DclPMU_Close(pmu_handle);
}

static INLINE void USB_Register_USB_HISR(usb_hisr func_ptr)
{
	DCL_HANDLE pmu_handle; // add for usb charging 
	CHR_DET_CTRL_REGISTER_USB_HISR ChrDetVal;
	
	pmu_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
	ChrDetVal.usb_det_hisr = func_ptr;
	Dcl_Chr_Det_Control(pmu_handle, CHR_DET_CMD_REGISTER_USB_HISR, (DCL_CTRL_DATA_T *)&ChrDetVal);
	DclPMU_Close(pmu_handle);
}


static INLINE void USB_BMT_NO_CHARGING_OUT(void)
{
	DCL_HANDLE bmt_handler;
	BMT_CTRL_SENDMES2UEM_T bmt_cmd_data1;

	bmt_handler = DclBMT_Open(DCL_BMT,FLAGS_NONE);
	bmt_cmd_data1.ChargerMsg = DCL_BMT_USB_NO_CHARGING_OUT;
	DclBMT_Control(bmt_handler, BMT_CMD_SENDMES2UEM, (DCL_CTRL_DATA_T *)&bmt_cmd_data1); // New API with CMD & DATA
}

static INLINE void USB_BMT_NO_CHARGING_IN(void)
{
	DCL_HANDLE bmt_handler;
	BMT_CTRL_SENDMES2UEM_T bmt_cmd_data1;

	bmt_handler = DclBMT_Open(DCL_BMT,FLAGS_NONE);
	bmt_cmd_data1.ChargerMsg = DCL_BMT_USB_NO_CHARGING_IN;
	DclBMT_Control(bmt_handler, BMT_CMD_SENDMES2UEM, (DCL_CTRL_DATA_T *)&bmt_cmd_data1); // New API with CMD & DATA
}


#endif /* USB_ADAP_H */

