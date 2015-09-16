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
 *   dcl_usb_drv.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#include "drv_comm.h"
#include "reg_base.h"
#include "init.h"
#include "cache_sw.h"
#include "drvpdn.h"
#include "intrCtrl.h"
#include "drv_hisr.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "upll_ctrl.h"

#include "usb_hw.h"
#include "usb_drv.h"
#include "usb_phy_drv.h"
#include "usb_drv_pri.h"
#include "usb_custom.h"

#ifdef __OTG_ENABLE__
#include "otg_drv.h"
#include "otg_if.h"
//#include "usb_hcd.h"
//#include "usb_hcd_pri.h"
#endif

#include "usb_debug_tool.h"
#include "usb_trc.h"
#include "dcl.h"

#if !defined(__MEUT__) && !defined(__L1_STANDALONE__)
#include "nvram_data_items.h"
#include "nvram_interface.h"
#endif

//#include "kal_release.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "sync_data.h"

#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)
#include "eint.h"
#if defined(__TRADITIONAL_MODEM_CARD__)
#include "RM_public.h"
#else
#include "ccci.h"
#endif
#endif
#include "usb_adap.h"
#include "l1sm_public.h"

/* usb pdn register setting to check  re-entry */
static kal_bool PDN_USB_flag = KAL_FALSE;
/* USBDL flag in meta mode */
static kal_bool USBDL_mode = KAL_FALSE;
static kal_bool USB_Fast_Meta_mode = KAL_FALSE;


#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)
#if defined(__TRADITIONAL_MODEM_CARD__)
extern void RM_Usb_Lock_Clock( kal_bool lock );	//lock 26MHz
#else
extern kal_bool ccci_send_message(kal_uint32 message, kal_uint32 reserved);
#define	AP_26M_LOCK	1
#define	AP_26M_UNLOCK	0
#endif
extern kal_uint8 L1SM_GetHandle(void);
extern void L1SM_SleepEnable(kal_uint8 handle);
extern void L1SM_SleepDisable(kal_uint8 handle);
#define EINT_USB_PWRDWN		0x07	//it should be replaced by tool_gen
#endif

#if defined(MTK_SLEEP_ENABLE)
static kal_uint8 usb_pdn_handle;
#endif



#if !defined(DRV_USB_SUPPORT_DCM) && defined(DCM_ENABLE)
/*DCM control*/
extern kal_uint8 DCM_GetHandle(void);
extern void DCM_Disable(kal_uint8 handle);
extern void DCM_Enable(kal_uint8 handle);
/* DCM default handle */
static kal_uint8 g_usb_dcm_handle = 255;
#endif


static DCL_STATUS DCL_USB_CTRL_API_USB_PDNmode(DCL_CTRL_DATA_T *data);
static DCL_STATUS DCL_USB_CTRL_API_USBDL_Update_USB_Download_Mode(DCL_CTRL_DATA_T *data);
static DCL_STATUS DCL_USB_CTRL_API_USBDL_Is_USB_Download_Mode(DCL_CTRL_DATA_T *data);
static DCL_STATUS DCL_USB_CTRL_API_USBDL_Is_USB_Fast_Meta_Mode(DCL_CTRL_DATA_T *data);
//static void USB_PDNEnable(void);
//static void USB_PDNDisable(void);
static void USB_SleepEnable(kal_bool);

/* Exception flag*/
extern kal_uint8 INT_Exception_Enter;
#if defined(__USB_BOOTUP_TRACE__)
extern kal_bool is_init_log_enable;
extern kal_bool is_init_stage;
#endif
extern kal_bool INT_QueryIsROMSpace(kal_uint32 addr);

#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)||defined(DRV_USB_IP_V2)||defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4))
/************************************************************
	USB PDN
*************************************************************/

/* USB PDN enable */
#if defined(__USB_ENABLE__) && !defined(DRV_USB_OFF)
static void USB_PDNEnable(void)
{
#if !defined(DRV_USB_OFF)
#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)
	PDN_SET(PDN_USB);
#else
	#if defined(__OLD_PDN_ARCH__)
	
	#if defined(__OLD_PDN_DEFINE__)
		DRVPDN_Enable(DRVPDN_CON0, DRVPDN_CON0_USB, PDN_USB);
	#elif defined(__CLKG_DEFINE__)
		DRVPDN_Enable(CG_CON0, CG_CON0_USB, PDN_USB);
	#endif
	
	#else
		//	DRVPDN_Enable(PDN_USB);	
		PDN_SET(PDN_USB); //power down dev
		USB_SleepEnable(KAL_TRUE); //unlock sleep mode
	#endif
#endif

#ifdef __USB_ENABLE__
	USB_Dbg_Trace(USB_SET_PDN_FLAG_FALSE, 2, 0);
#endif

	PDN_USB_flag = KAL_FALSE;
#endif /*!defined(DRV_USB_OFF)*/
}
#else
#if defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)
static void USB_PDNEnable(void)
{
}
#endif
#endif


/* USB PDN disable */
static void USB_PDNDisable(void)
{
#if !defined(DRV_USB_OFF)

#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)
	PDN_CLR(PDN_USB);
#else
	#if defined(__OLD_PDN_ARCH__)
	#if defined(__OLD_PDN_DEFINE__)
		DRVPDN_Disable(DRVPDN_CON0, DRVPDN_CON0_USB, PDN_USB);
	#elif defined(__CLKG_DEFINE__)
		DRVPDN_Disable(CG_CON0, CG_CON0_USB, PDN_USB);
	#endif
	
	#else
	//		DRVPDN_Disable(PDN_USB);	
		PDN_CLR(PDN_USB); //power up dev	
		USB_SleepEnable(KAL_FALSE);
	#endif
#endif

#ifdef __USB_ENABLE__
	USB_Dbg_Trace(USB_SET_PDN_FLAG_TRUE, 2, 0);
#endif

	if(PDN_USB_flag == KAL_TRUE)
		ASSERT(0);
	PDN_USB_flag = KAL_TRUE;
#endif /*!defined(DRV_USB_OFF)*/
}

#endif


#if defined(__USB_ENABLE__) && !defined(DRV_USB_OFF)

/* usb phy pdn owner */
static kal_uint32 g_usb_phy_power_owner = 0;
static kal_uint32 g_usb_resume_gpt_handler = 0;


USB_Drv_Info g_UsbDrvInfo;
static kal_uint32 g_usb_reset_times = 0; /*  for debug information */
DCL_USB_CLASS_API USB_Class_Driver[USB_MAX_FEATURE_NUM];


#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
/* EP0's FIFO address is fixed from 0~63 */
static kal_uint32 g_FIFOadd = USB_FIFO_START_ADDRESS;

/* Static functions */
static kal_uint8 USB_Get_DMA_Channel_Num(kal_uint8 ep_num, USB_EP_DIRECTION direction);

#else

static void USB_DMA1_Callback(void);
#if defined(__USB_SUPPORT_MULTIPLE_DMA_CHANNEL__)
static void USB_DMA2_Callback(void);
#endif

#endif  /* defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4) */


#ifndef __OTG_ENABLE__
#if defined(DRV_USB_IP_V3)
static void USBDMA_HISR(void);
static void USBDMA_LISR(void);
#endif
static void USB_LISR(void);
#endif

static void USB_HW_Stop_DMA_Channel(kal_uint32 ep_num, USB_EP_DIRECTION direction);
static void USB_EP_Check(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_uint32 line);
static void USB_EP_DMA_Running_Check(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_uint32 line);
static void USB_EP0En(void);
static void USB_HW_EPFIFOWrite (kal_uint32 ep_num, kal_uint16 nBytes, void *pSrc);
static void USB_Phy_Enable(USB_PHY_OWNER owner);
static void USB_Phy_Disable(USB_PHY_OWNER owner);
static DCL_STATUS DCL_USB_CTRL_API_USB_DUMP(DCL_CTRL_DATA_T *data);



/************************************************************
	DMA utilities
*************************************************************/

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)

static kal_uint8 USB_Get_DMA_Channel_Num(kal_uint8 ep_num, USB_EP_DIRECTION direction)
{
	kal_uint8  dma_chan;


	dma_chan = g_UsbDrvInfo.dma_port[direction][ep_num-1];

	if((dma_chan == 0)||(dma_chan > MAX_DMA_NUM)||(ep_num == 0))
		EXT_ASSERT(0, ep_num, MAX_DMA_NUM, 0);

	return dma_chan;
}

#endif


/* Stop DMA channel */
static void USB_HW_Stop_DMA_Channel(kal_uint32 ep_num, USB_EP_DIRECTION direction)
{
#if defined(DRV_USB_IP_V4)
	kal_uint32 	savedMask;
	kal_uint8 	dma_chan;


	dma_chan = USB_Get_DMA_Channel_Num(ep_num, direction);

	savedMask = SaveAndSetIRQMask();
	/* Stop DMA channel */
	USBDMA_Stop(dma_chan);

	/* Clear pending DMA interrupts */
	//USB_DRV_WriteReg32(USB_DMAINTR, ~((1<<(dma_chan-1))|(0xC000<<(dma_chan*2))));
	DRV_WriteReg8(USB_DMA_INTR_STATUS, (1<<(dma_chan-1)));
	//DRV_WriteReg8(USB_DMA_INTR_UNMASK_SET, (1<<(dma_chan-1)));

	g_UsbDrvInfo.dma_pktrdy[dma_chan - 1] = KAL_FALSE;
	g_UsbDrvInfo.dma_running[dma_chan - 1] = KAL_FALSE;
	RestoreIRQMask(savedMask);

#elif defined(DRV_USB_IP_V3)
	kal_uint32 	savedMask;
	kal_uint8 	dma_chan;


	dma_chan = USB_Get_DMA_Channel_Num(ep_num, direction);

	savedMask = SaveAndSetIRQMask();
	/* Stop DMA channel */
	USBDMA_Stop(dma_chan);
//	USBDMA_PPStop(dma_chan);

	/* Clear pending DMA interrupts */
	// write 0 clear
	USB_DRV_WriteReg32(USB_DMAINTR, ~((1<<(dma_chan-1))|(0xC000<<(dma_chan*2))));

	g_UsbDrvInfo.dma_pktrdy[dma_chan - 1] = KAL_FALSE;
	g_UsbDrvInfo.dma_running[dma_chan - 1] = KAL_FALSE;
	RestoreIRQMask(savedMask);

#else  /* defined(DRV_USB_IP_V3) */
	kal_uint32 savedMask;

	USB_EP_Check(ep_num, direction, 0);

	if(g_UsbDrvInfo.dma_port[ep_num - 1] != 0)
	{
		if (DMA_CheckRunStat(g_UsbDrvInfo.dma_port[ep_num - 1]))
		{
			DMA_Stop(g_UsbDrvInfo.dma_port[ep_num - 1]);
		}

		savedMask = SaveAndSetIRQMask();
		if (DMA_CheckITStat(g_UsbDrvInfo.dma_port[ep_num - 1]))
		{
			DMA_ACKI(g_UsbDrvInfo.dma_port[ep_num - 1]);
			IRQClearInt(IRQ_DMA_CODE);
		}
		RestoreIRQMask(savedMask);
	}

	g_UsbDrvInfo.dma_pktrdy[ep_num - 1] = KAL_FALSE;
	g_UsbDrvInfo.dma_running[ep_num - 1] = KAL_FALSE;
#endif  /* defined(DRV_USB_IP_V3) */
}


/************************************************************
	driver debug utility
*************************************************************/

static void USB_EP_Check(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_uint32 line)
{
	if((ep_num == 0)||((direction == USB_EP_TX_DIR)&&(ep_num > MAX_TX_EP_NUM))||
		((direction == USB_EP_RX_DIR)&&(ep_num > MAX_RX_EP_NUM)))
	{
		EXT_ASSERT(0, ep_num, (kal_uint32)direction, line);
	}
}


static void USB_EP_DMA_Running_Check(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_uint32 line)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint8	dma_chan;


	dma_chan = g_UsbDrvInfo.dma_port[direction][ep_num-1];

	if((dma_chan != 0)&&(USBDMA_CheckRunStat(dma_chan) != 0)&&(g_UsbDrvInfo.dma_dir[dma_chan-1] == direction))
	{
		/* Fix for USB compliance test program */
		//EXT_ASSERT(0, ep_num, (kal_uint32)direction, line);
		USB_HW_Stop_DMA_Channel(ep_num, direction);
	}
#endif
}


static void USB_EP0En(void)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	/* Default address is from 0 to 63  */
	USB_DRV_SetBits(USB_INTRTXE, USB_INTRE_EPEN);
#elif defined(DRV_USB_IP_V2)
	USB_DRV_WriteReg8(USB_ENDPT_CTL(0), VUSB_ENDPT_CONTROL);
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	USB_DRV_SetBits8(USB_INTRIN1E, USB_INTRIN1E_EPEN);
#endif
}


/*  Write data to FIFO EP */
static void USB_HW_EPFIFOWrite(kal_uint32 ep_num, kal_uint16 nBytes, void *pSrc)
{
#if defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)||defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint16 nCount = nBytes;
	kal_uint8 *pby;
	kal_uint32 nAddr;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint32  temp_1, temp_2;
	kal_uint32 *pby1;
#endif
#endif

	if((nBytes != 0)&&(pSrc == NULL))
		EXT_ASSERT(0, (kal_uint32)nBytes, 0, 0);

	if (pSrc == NULL)
		return;

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)

	/* not index register */
//	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	nAddr = USB_EP0 + ep_num*4;

	if(((kal_uint32)pSrc%4) == 0)
	{
		/* Source address is 4 byte alignment */

		temp_1 = nCount/4;
		temp_2 = nCount%4;

		pby1 = (kal_uint32 *)pSrc;

		while(temp_1)
		{
			USB_DRV_WriteReg32(nAddr, *pby1++);	//lint !e613
			temp_1--;
		}

		pby = (kal_uint8 *)pby1;

		while(temp_2)
		{
			USB_DRV_WriteReg8(nAddr, *pby++);	//lint !e613
			temp_2--;
		}
	}
	else
	{
		pby = (kal_uint8 *)pSrc;

		/* Read byte by byte */
		while(nCount)
		{
			USB_DRV_WriteReg8(nAddr, *pby++);	//lint !e613
			nCount--;
		}
	}
#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	nAddr = USB_EP0 + ep_num*4;
	pby = (kal_uint8 *)pSrc;

	/* write by byte */
	while (nCount)
	{
		USB_DRV_WriteReg8(nAddr,*pby++);
		nCount--;
	}
#endif
}

#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))

/************************************************************
	DMA handler
*************************************************************/


/* DMA callback for endpoint 1*/
static void USB_DMA1_Callback(void)
{
	usb_dma_callback callback = g_UsbDrvInfo.dma_callback[0];



	USB_Dbg_Trace(USB_DBG_DMA_CALLBACK, 0, 0);

	g_UsbDrvInfo.dma_callback[0] = NULL;

#ifdef __WRITE_THROUGH_CACHEABLE__
	if(g_UsbDrvInfo.dma_dir[0] == USB_EP_RX_DIR)
	{
		/* Only RX need to invalidate cache */
		invalidate_wt_cache(g_UsbDrvInfo.dma_addr[0], g_UsbDrvInfo.dma_length[0]);
	}
#endif

	/* The last one pkt length not multiple of MAX_PKT_LEN, clear corresponding bits*/
	if(g_UsbDrvInfo.dma_pktrdy[0] == KAL_TRUE)
	{
		if(g_UsbDrvInfo.dma_dir[0] == USB_EP_TX_DIR)
		{
			USB_HW_EP_Tx_Ready(1, USB_ENDPT_BULK);
		}
		else
		{
			USB_HW_EP_Rx_Ready(1, USB_ENDPT_BULK);
		}
	}

	g_UsbDrvInfo.dma_pktrdy[0] = KAL_FALSE;

	/* If application callback function does not request to clear drv_running set by itself, clear running state here */
	if(g_UsbDrvInfo.dma_callback_upd_run[0] == KAL_FALSE)
		g_UsbDrvInfo.dma_running[0] = KAL_FALSE;

	if(callback != NULL)
		callback();
}


#if defined(__USB_SUPPORT_MULTIPLE_DMA_CHANNEL__)
/* DMA callback for endpoint 2*/
static void USB_DMA2_Callback(void)
{
	usb_dma_callback callback = g_UsbDrvInfo.dma_callback[1];


	g_UsbDrvInfo.dma_callback[1] = NULL;

#ifdef __WRITE_THROUGH_CACHEABLE__
	if(g_UsbDrvInfo.dma_dir[1] == USB_EP_RX_DIR)
	{
		/* Only RX need to invalidate cache */
		invalidate_wt_cache(g_UsbDrvInfo.dma_addr[1], g_UsbDrvInfo.dma_length[1]);
	}
#endif

	/* The last one pkt length not multiple of MAX_PKT_LEN, clear corresponding bits*/
	if (g_UsbDrvInfo.dma_pktrdy[1] == KAL_TRUE)
	{
		if(g_UsbDrvInfo.dma_dir[1] == USB_EP_TX_DIR)
			USB_HW_EP_Tx_Ready(2, USB_ENDPT_BULK);
		else
			USB_HW_EP_Rx_Ready(2, USB_ENDPT_BULK);
	}

	g_UsbDrvInfo.dma_pktrdy[1] = KAL_FALSE;

	/* if application callback function dose not request to clear drv_runnung set by itself, clear running state here*/
	if(g_UsbDrvInfo.dma_callback_upd_run[1] == KAL_FALSE)
		g_UsbDrvInfo.dma_running[1] = KAL_FALSE;

	if(callback != NULL)
		callback();
}

#endif /* __USB_SUPPORT_MULTIPLE_DMA_CHANNEL__ */

#endif

/************************************************************
	HISR/LISR   interrupt handler
*************************************************************/
#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)
void USB_PWNDWN_HISR(void)
{
	#if defined(DRV_USB_SLEEP_SUPPORT)
	#if defined(__TRADITIONAL_MODEM_CARD__)
	RM_Usb_Lock_Clock(KAL_TRUE); //hosted dongle no need to lock AP's clock in modem side
	#else
	ccci_send_message(CCMSG_ID_SYSMSGSVC_LOCK_AP_26M, AP_26M_LOCK);
	#endif
	#else
//	L1SM_SleepDisable(usb_pdn_handle);
	USB_SleepEnable(KAL_FALSE);
	#endif
	EINT_Mask(EINT_USB_PWRDWN);	
	drv_trace0(TRACE_FUNC, (kal_uint32)USB_PWNDWN);
}
#endif

PRAGMA_BEGIN_COMPILER_OPTIMIZE_TIME
void USB_HISR(void)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint8    IntrUSB;
	kal_uint16  IntrTx;
	kal_uint16  TXCSR;
	kal_uint16  RXCSR;
	kal_uint16  IntrRx;
	kal_uint16  IntrRxE;	
	kal_uint32  ep_num;
	kal_uint8    USBMode;
//	kal_uint8   delay;
//	kal_bool    Rx_FIFO_not_empty = KAL_FALSE;
	kal_uint32 savedMask;
	#if defined(DRV_USB_IP_V4)
	kal_uint32  	DMAIntr;
	kal_uint32  	DMAQIntr;
	static kal_uint32  	index;
//	kal_uint32  	dma_ctrl;
	#endif


	// read and clear
#ifdef __OTG_ENABLE__
	IntrUSB = OTG_Get_Intr_Status();
#else
	IntrUSB = USB_DRV_Reg8(USB_INTRUSB);
	#if defined(DRV_USB_IP_V4)
	USB_DRV_WriteReg8(USB_INTRUSB, IntrUSB);
	#endif
#endif
	// Write 1 clear
	IntrTx = USB_DRV_Reg(USB_INTRTX);
	USB_DRV_WriteReg(USB_INTRTX, IntrTx);

	// Write 0 clear
	IntrRx = USB_DRV_Reg(USB_INTRRX);
	IntrRxE = USB_DRV_Reg(USB_INTRRXE);
	IntrRx = IntrRx & IntrRxE;
	#if defined(DRV_USB_IP_V4)
	USB_DRV_WriteReg(USB_INTRRX, IntrRx);
	#else
	USB_DRV_WriteReg(USB_INTRRX, ~IntrRx);
	#endif
	
	USBMode = USB_DRV_Reg8(USB_POWER);

	if(INT_Exception_Enter == 0)
	{
		//USB_Dbg_Trace(USB_DBG_HISR, (kal_uint32)IntrUSB, (kal_uint32)USBMode);
		//USB_Dbg_Trace(USB_DBG_HISR, USB_DRV_Reg8(USB_LINE_STATE), USB_DRV_Reg8(USB_OPSTATE));
	}

	drv_trace4(TRACE_GROUP_5, (kal_uint32)USB_HISR_State, IntrUSB, USBMode, USB_DRV_Reg8(USB_LINE_STATE), USB_DRV_Reg8(USB_OPSTATE));

#ifdef __OTG_ENABLE__
	if(IntrUSB&(USB_INTRUSB_SESSREQ|USB_INTRUSB_VBUSERROR))
	{
		USB_Dbg_Trace(USB_HISR_ERROR, 0, 0);
		ASSERT(0);
	}

	if(IntrUSB&(USB_INTRUSB_CONN))
	{
		if(IntrUSB&USB_INTRUSB_SUSPEND)
		{
			/* IN HNP, suspend and conn intr come together */
			/* happen easily in full speed */
			USB_Dbg_Trace(USB_HISR_SUSPEND_AND_CONN_ISR, USB_DRV_Reg8(USB_LINE_STATE), USB_DRV_Reg8(USB_OPSTATE));
			OTG_Set_Conn_Intr_With_Suspend();
		}
		else
		{
			ASSERT(0);
		}
	}
#endif

	// Reset must be the highest priority ISR
	/* Check for reset interrupt */
#ifdef __OTG_ENABLE__
	if((IntrUSB&USB_INTRUSB_RESET)&&((USB_DRV_Reg8(USB_POWER)&USB_POWER_SOFTCONN) != 0))
#else
	if(IntrUSB&USB_INTRUSB_RESET)
#endif
	{
		USB_DRV_SetBits8(USB_INTRUSBE, USB_INTRUSBE_SUSPEND);
#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)
		#if defined(DRV_USB_SLEEP_SUPPORT)
		#if defined(__TRADITIONAL_MODEM_CARD__)
		RM_Usb_Lock_Clock(KAL_TRUE); //hosted dongle no need to lock AP's clock in modem side
		#else
		ccci_send_message(CCMSG_ID_SYSMSGSVC_LOCK_AP_26M, AP_26M_LOCK);
		#endif
		#else
	//	L1SM_SleepDisable(usb_pdn_handle);
		USB_SleepEnable(KAL_FALSE);
		#endif
		EINT_Mask(EINT_USB_PWRDWN);	
#endif
		g_usb_reset_times++;
		g_UsbDrvInfo.suspend_count = 0;
		drv_trace1(TRACE_FUNC, (kal_uint32)USB_RESET_TIMES, g_usb_reset_times);
		USB_Dbg_Trace(USB_RESET, USB_DRV_Reg8(USB_LINE_STATE), USB_DRV_Reg8(USB_OPSTATE));
		g_UsbDrvInfo.suspend_with_FIFO_not_empty= KAL_FALSE;

		if(g_UsbDrvInfo.reset_hdlr == NULL)
			ASSERT(0);
		/* Set SW_RST bit here, so we do not care about any following ep interrupts */
		g_UsbDrvInfo.reset_hdlr();
		IntrTx = 0;
		IntrRx = 0;
	#ifdef __OTG_ENABLE__
		/* Add for OTG function */
		if(OTG_Get_Plug_Type() == OTG_PLUG_A)
			OTG_Set_Status(OTG_STATUS_A_DETECT_B_SUSPEND, KAL_FALSE);
		else
			OTG_Set_Status(OTG_STATUS_B_DETECT_A_SUSPEND, KAL_FALSE);
	#endif
	}

	/* Check for resume from suspend mode */
	if (IntrUSB & USB_INTRUSB_RESUME)
	{
		USB_DRV_SetBits8(USB_INTRUSBE, USB_INTRUSBE_SUSPEND);
#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)
		#if defined(DRV_USB_SLEEP_SUPPORT)
		#if defined(__TRADITIONAL_MODEM_CARD__)
		RM_Usb_Lock_Clock(KAL_TRUE); //hosted dongle no need to lock AP's clock in modem side
		#else
		ccci_send_message(CCMSG_ID_SYSMSGSVC_LOCK_AP_26M, AP_26M_LOCK);
		#endif
		#else
	//	L1SM_SleepDisable(usb_pdn_handle);
		USB_SleepEnable(KAL_FALSE);
		#endif
		EINT_Mask(EINT_USB_PWRDWN);	
#endif
		USB_Dbg_Trace(USB_RESUME, USB_DRV_Reg8(USB_LINE_STATE), USB_DRV_Reg8(USB_OPSTATE));
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_IS_RESUME);
		g_UsbDrvInfo.suspend_with_FIFO_not_empty = KAL_FALSE;

		g_UsbDrvInfo.power_state = USB_STATE_NORMAL;
		g_UsbDrvInfo.suspend_count = 0;

		if((USB_DRV_Reg8(USB_POWER)&USB_POWER_HSMODE) != 0)
			g_UsbDrvInfo.Is_HS_mode = KAL_TRUE;
		else
			g_UsbDrvInfo.Is_HS_mode = KAL_FALSE;

		g_UsbDrvInfo.resume_hdlr();
		/* When from PERIPHERAL to SUSPEND, the device_up is still TRUE */
	#ifdef __OTG_ENABLE__
		/* Add for OTG function*/
		if(OTG_Get_Plug_Type() == OTG_PLUG_A)
			OTG_Set_Status(OTG_STATUS_A_DETECT_B_SUSPEND, KAL_FALSE);
		else
			OTG_Set_Status(OTG_STATUS_B_DETECT_A_SUSPEND, KAL_FALSE);
	#endif
   	}

#ifdef __OTG_ENABLE__
	if((OTG_Get_State() == OTG_STATE_A_PERIPHERAL)||(OTG_Get_State() == OTG_STATE_B_PERIPHERAL))
	{
#endif
		/* Check for endpoint 0 interrupt */
		if(IntrTx&USB_INTRTX_EP0)
		{
			if(g_UsbDrvInfo.ep0_hdlr == NULL)
				ASSERT(0);

			g_UsbDrvInfo.ep0_hdlr();
		}

		/* Check for Bulk TX interrupt */
		/* TX interrupt : 1.TxPktRdy is clear, 2. SENTSTALL is set */
		for(ep_num = 1; ep_num <= MAX_TX_EP_NUM; ep_num++)
		{
			if (IntrTx&(0x01 <<ep_num))
			{
				savedMask = SaveAndSetIRQMask();			
				USB_DRV_WriteReg8(USB_INDEX, ep_num);
				TXCSR = USB_DRV_Reg(USB_TXCSR);
				RestoreIRQMask(savedMask);
				#ifdef __MEUT__ //In usb suspend, this case will be happened when flush or put data with double fifo.
				if (g_UsbDrvInfo.power_state != USB_STATE_NORMAL)
					EXT_ASSERT(0, (kal_uint32)TXCSR, 0, 0);
				#endif
				if((TXCSR&USB_TXCSR_SENTSTALL) != 0)
				{
					/* Only clear SENTSTALL bit */
					TXCSR &= ~USB_TXCSR_SENTSTALL;
	    			savedMask = SaveAndSetIRQMask();			
    				USB_DRV_WriteReg8(USB_INDEX, ep_num);					
					USB_DRV_WriteReg(USB_TXCSR, TXCSR);
    				RestoreIRQMask(savedMask);					
				}
				else
				{
					if(g_UsbDrvInfo.ep_tx_hdlr[ep_num-1] != NULL)
					{
						g_UsbDrvInfo.ep_tx_hdlr[ep_num -1]();
					}
					else
					{
						if(g_UsbDrvInfo.ep_tx_flush_intr[ep_num -1] == KAL_TRUE)
						{
							g_UsbDrvInfo.ep_tx_flush_intr[ep_num -1] = KAL_FALSE;
						}
						else
						{
							/* Save debug info */
							USB_Dbg_Trace(USB_EPN_UNEXPECTED_TX_HISR, (kal_uint32)TXCSR, USB_DRV_Reg8(USB_INTRTXE));
							drv_trace2(TRACE_FUNC, (kal_uint32)USB_EP_UNEXPECTED_TX_HISR, ep_num, TXCSR);
						}
					}
				}
			}
		}

		/* Check for Bulk RX interrupt */
		/* RX interrupt : 1.RxPktRdy is set, 2. SENTSTALL is set */
		for(ep_num = 1; ep_num <= MAX_RX_EP_NUM; ep_num++)
		{
			if(IntrRx&(0x01<<ep_num))
			{
				savedMask = SaveAndSetIRQMask();  /*prevent race condition with putisrbyte */
				USB_DRV_WriteReg8(USB_INDEX, ep_num);
				RXCSR = USB_DRV_Reg(USB_RXCSR);
				RestoreIRQMask(savedMask);

//				if ((g_UsbDrvInfo.power_state != USB_STATE_NORMAL) && (g_UsbDrvInfo.suspend_with_FIFO_not_empty == KAL_FALSE))
//					EXT_ASSERT(0, (kal_uint32)RXCSR, 0, 0);


				if (g_UsbDrvInfo.power_state != USB_STATE_NORMAL)
					RXCSR = 0x00;

				if((RXCSR&USB_RXCSR_SENTSTALL) != 0)
				{
					RXCSR &= ~USB_RXCSR_SENTSTALL;
    				savedMask = SaveAndSetIRQMask();  /*prevent race condition with putisrbyte */					
    				USB_DRV_WriteReg8(USB_INDEX, ep_num);					
					USB_DRV_WriteReg(USB_RXCSR, RXCSR);
    				RestoreIRQMask(savedMask);					
				}
				else if((RXCSR&USB_RXCSR_RXPKTRDY) != 0)
				{
					if(g_UsbDrvInfo.ep_rx_hdlr[ep_num-1] != NULL)
					{
						g_UsbDrvInfo.ep_rx_hdlr[ep_num -1]();

//						RXCSR = USB_DRV_Reg(USB_RXCSR);

//						if (RXCSR & USB_RXCSR_RXPKTRDY)
//							Rx_FIFO_not_empty = KAL_TRUE;
										
					}
					else
					{
						/* No handler to receive this packet */
						USB_Dbg_Trace(USB_UNEXPECTED_RX_HISR, ep_num, RXCSR);
						drv_trace2(TRACE_FUNC, (kal_uint32)USB_DRV_RX_ERROR, ep_num, RXCSR);
						USB_DRV_ClearBits(USB_RXCSR, USB_RXCSR_RXPKTRDY);
#ifdef __MEUT__			
						ASSERT(0);
#endif
					}
				}
				else
				{
					//USB_Dbg_Trace(USB_EPN_UNEXPECTED_RX_HISR, (kal_uint32)RXCSR, USB_DRV_Reg8(USB_INTRRXE));
					//drv_trace2(TRACE_FUNC, (kal_uint32)USB_EP_UNEXPECTED_RX_HISR, ep_num, RXCSR);
					//if (g_UsbDrvInfo.ep_rx_stall_status[ep_num-1] == KAL_FALSE)
					//	ASSERT(0);

					if(g_UsbDrvInfo.ep_rx_flush_intr[ep_num -1] == KAL_TRUE)
					{
						g_UsbDrvInfo.ep_rx_flush_intr[ep_num -1] = KAL_FALSE;
					}
					else if (g_UsbDrvInfo.ep_rx_stall_status[ep_num-1] == KAL_FALSE)
					{
						// Save debug info
						USB_Dbg_Trace(USB_EPN_UNEXPECTED_RX_HISR, (kal_uint32)RXCSR, USB_DRV_Reg8(USB_INTRRXE));
						drv_trace2(TRACE_FUNC, (kal_uint32)USB_EP_UNEXPECTED_RX_HISR, ep_num, RXCSR);
#ifdef __MEUT__					
						ASSERT(0);
#endif

					}
				}
			}
		}
#ifdef __OTG_ENABLE__
	}
#endif

	/* When cable plugged out, it will trigger disconn interrupt */
	if(IntrUSB&USB_INTRUSB_DISCON)
	{
		USB_Dbg_Trace(USB_DISCONN, USB_DRV_Reg8(USB_LINE_STATE), USB_DRV_Reg8(USB_OPSTATE));
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_IS_DISCONN);
	}

	/* Check for suspend mode */
	if (IntrUSB&USB_INTRUSB_SUSPEND)
	{
#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)
		#if defined(DRV_USB_SLEEP_SUPPORT)
		#if defined(__TRADITIONAL_MODEM_CARD__)
		RM_Usb_Lock_Clock(KAL_FALSE); //hosted dongle no need to lock AP's clock in modem side
		#else
		ccci_send_message(CCMSG_ID_SYSMSGSVC_LOCK_AP_26M, AP_26M_UNLOCK);
		#endif
		#else
		//L1SM_SleepEnable(usb_pdn_handle);
		USB_SleepEnable(KAL_TRUE);
		#endif
		EINT_UnMask(EINT_USB_PWRDWN);
#endif
		
	#ifdef __OTG_ENABLE__
		/* HW issue */
		if((OTG_Get_Plug_Type() == OTG_PLUG_A)&&(USB_DRV_Reg8(USB_OPSTATE) == 0x06))
		{
			g_usb_reset_times++;
			drv_trace1(TRACE_FUNC, (kal_uint32)USB_RESET_TIMES, g_usb_reset_times);
			USB_Dbg_Trace(USB_RESET, USB_DRV_Reg8(USB_LINE_STATE), USB_DRV_Reg8(USB_OPSTATE));

			if(g_UsbDrvInfo.reset_hdlr == NULL)
				ASSERT(0);

			g_UsbDrvInfo.reset_hdlr();

			if(OTG_Get_Plug_Type() == OTG_PLUG_A)
				OTG_Set_Status(OTG_STATUS_A_DETECT_B_SUSPEND, KAL_FALSE);
			else
				OTG_Set_Status(OTG_STATUS_B_DETECT_A_SUSPEND, KAL_FALSE);

			return;
		}

	#endif

//		if(Rx_FIFO_not_empty == KAL_TRUE)
//			g_UsbDrvInfo.suspend_with_FIFO_not_empty = KAL_TRUE;

		USB_Dbg_Trace(USB_SUSPEND, USB_DRV_Reg8(USB_LINE_STATE), USB_DRV_Reg8(USB_OPSTATE));
		USB_Dbg_Trace(USB_SUSPEND, USB_DRV_Reg(USB_RXCSR), USB_DRV_Reg(USB_TXCSR));
		USB_Dbg_Trace(USB_SUSPEND, USB_DRV_Reg(USB_DEVCTL), 0);
		
		if((USB_DRV_Reg(USB_RXCSR)& USB_RXCSR_RXPKTRDY) == 0x0001)
			g_UsbDrvInfo.suspend_with_FIFO_not_empty = KAL_TRUE;
				
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_IS_SUSPEND);


		if(g_UsbDrvInfo.power_state == USB_STATE_SUSPEND)
		{
			g_UsbDrvInfo.suspend_count++;
			if(g_UsbDrvInfo.suspend_count == 5)
			{
				USB_DRV_ClearBits8(USB_INTRUSBE, USB_INTRUSBE_SUSPEND);
#ifdef __MTK_INTERNAL__
				////USB_DUMP();
				//DCL_USB_CTRL_API_USB_DUMP(NULL);
				//for(delay = 0; delay < 100; delay++)
				//{
				//	USB_Dbg_Trace(USB_SUSPEND, USB_DRV_Reg8(USB_LINE_STATE), USB_DRV_Reg8(USB_OPSTATE));
				//}
				////USB_DUMP();
				//DCL_USB_CTRL_API_USB_DUMP(NULL);
				//ASSERT(0);
#endif
			}
		}


		g_UsbDrvInfo.power_state = USB_STATE_SUSPEND;
		g_UsbDrvInfo.Is_HS_mode = KAL_FALSE;
		g_UsbDrvInfo.suspend_hdlr();

		/* When from PERIPHERAL to SUSPEND, the device_up is still TRUE */
	#ifdef __OTG_ENABLE__
		/* Add for OTG function*/
		if(OTG_Get_Plug_Type() == OTG_PLUG_A)
			OTG_Set_Status(OTG_STATUS_A_DETECT_B_SUSPEND, KAL_TRUE);
		else
			OTG_Set_Status(OTG_STATUS_B_DETECT_A_SUSPEND, KAL_TRUE);
	#endif
	}


#if defined(DRV_USB_IP_V4)
	/*******************/
	/*DMA_HISR        */
	/*******************/
	
	DMAIntr = USB_DRV_Reg8(USB_DMA_INTR_STATUS);
	if(DMAIntr != 0)
	{
		//USB_Debug_Trace(USB_ENTER_DMA_HISR, 0, 0);
	}
	
	while(DMAIntr != 0)
	{
		for (index = 0; index < MAX_DMA_NUM; index++)
		{
			if((DMAIntr&(1<<index)) != 0)
			{
				// write 1 clear first, then do call back function, order is very important !!!
				USB_DRV_WriteReg8(USB_DMA_INTR_STATUS, (0x01<<index));
    
				// DMA interrupt still occur if stop DMA channel and DMA do a transfer done at the same time.
				// Must skip it.
				if (g_UsbDrvInfo.dma_running[index] == KAL_TRUE)
				{
					/* DMA channel index+1 have interrupt */
					//if(USB_DRV_Reg32(USB_DMA_REALCNT(index+1)) != 0)
					if(1)
					{
						USB_DMA_Callback(index+1);
					}
					else
					{
						if(USB_Check_DMA_Time_Out(index+1) == KAL_TRUE)
						{
							USB_DMA_Callback(index+1);
						}
						else
						{
							ASSERT(0);
						}
					}
				}
			}
		}
    
		/* Read register again to see if any interrupt is generated again */
		/* if pong pong buffer serve done, then we do call back function here */
		DMAIntr = USB_DRV_Reg8(USB_DMA_INTR_STATUS);
		if(DMAIntr  == 0)
		{
			//USB_Debug_Trace(USB_OUT_DMA_HISR, 0, 0);
		}
	}
	
#ifdef DRV_USB_DMA_QUEUE_SUPPORT	
	/*******************/
	/*DMAQ_HISR        */
	/*******************/	
	DMAQIntr = USB_DRV_Reg32(USB_DMAQ_QISAR);	

	//while(DMAQIntr != 0)
	if (DMAQIntr != 0)
	{
		drv_trace2(TRACE_FUNC, (kal_uint32)USB_HW_State,DMAQIntr,DMAQIntr);	
		USB_DRV_WriteReg32(USB_DMAQ_QISAR, DMAQIntr); //write 1 clear
		
		for (index = 0; index < DMAQ_MAX_NUMBERS; index++)
		{
			if (DMAQIntr & USB_DMAQ_QISAR_TXQ_EMPYT_INT)
			{
				//USB_Debug_Trace(USB_OUT_DMA_HISR, 0xFF, DRV_Reg32(USB_DMAQ_TQEMIR));
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_DMA_HW_Intr, USB_DRV_Reg32(USB_DMAQ_TQEMIR));						
				USB_DRV_WriteReg32(USB_DMAQ_TQEMIR, USB_DRV_Reg32(USB_DMAQ_TQEMIR));
				
//				if (g_UsbDrvInfo.dmaq_empty_callback[USB_EP_TX_DIR][index] != NULL)
//				{
//					usb_dmaq_CB callback;
//					callback = g_UsbDrvInfo.dmaq_empty_callback[USB_EP_TX_DIR][index];
//					callback(index);
					USB_DMAQEmpty_Callback(index,USB_EP_TX_DIR);
//				}
			}
			
			if (DMAQIntr & USB_DMAQ_QISAR_RXQ_EMPTY_INT)	
			{
				//USB_Debug_Trace(USB_OUT_DMA_HISR, 0xEE, DRV_Reg32(USB_DMAQ_RQEMIR));
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_DMA_HW_Intr, USB_DRV_Reg32(USB_DMAQ_RQEMIR));
				USB_DRV_WriteReg32(USB_DMAQ_RQEMIR, USB_DRV_Reg32(USB_DMAQ_RQEMIR));

//				if (g_UsbDrvInfo.dmaq_empty_callback[USB_EP_RX_DIR][index] != NULL)
//				{
//					usb_dmaq_CB callback;
//					callback = g_UsbDrvInfo.dmaq_empty_callback[USB_EP_RX_DIR][index];
//					callback(privdata);
					USB_DMAQEmpty_Callback(index,USB_EP_RX_DIR);
//				}
			}
					
			if (DMAQIntr & (USB_DMAQ_QISAR_RXQ_ERR_INT | USB_DMAQ_QISAR_TXQ_ERR_INT | USB_DMAQ_QISAR_RXEP_ERR_INT | USB_DMAQ_QISAR_TXEP_ERR_INT))
			{
				if (DMAQIntr & USB_DMAQ_QISAR_RXQ_ERR_INT)
				{
					if (USB_DRV_Reg32(USB_DMAQ_RQEIR) & (USB_DMAQ_QIMCR0 << index))
					{
						ASSERT(0);			// Error handler
						USB_DRV_WriteReg32(USB_DMAQ_RQEIR, USB_DRV_Reg32(USB_DMAQ_RQEIR)); //write 1 clear
					}
				}
				if (DMAQIntr & USB_DMAQ_QISAR_TXQ_ERR_INT)
				{
					if (USB_DRV_Reg32(USB_DMAQ_TQEIR)& (USB_DMAQ_QIMCR0 << index))
					{
						ASSERT(0);  // Error handler
						USB_DRV_WriteReg32(USB_DMAQ_TQEIR, USB_DRV_Reg32(USB_DMAQ_TQEIR)); //write 1 clear
					}		
				}
				if (DMAQIntr & USB_DMAQ_QISAR_RXEP_ERR_INT)	
				{
					if (USB_DRV_Reg32(USB_DMAQ_REPEIR) & (USB_DMAQ_QIMCR0 << index))
					{
						ASSERT(0);					// Error handler
						USB_DRV_WriteReg32(USB_DMAQ_REPEIR, USB_DRV_Reg32(USB_DMAQ_REPEIR)); //write 1 clear
					}								
				}
				if (DMAQIntr & USB_DMAQ_QISAR_TXEP_ERR_INT)	
				{
					if (USB_DRV_Reg32(USB_DMAQ_TEPEIR) & (USB_DMAQ_QIMCR0 << index))
					{
						ASSERT(0);		// Error handler
						USB_DRV_WriteReg32(USB_DMAQ_TEPEIR, USB_DRV_Reg32(USB_DMAQ_TEPEIR)); //write 1 clear
					}
				}
			}
			
			if (DMAQIntr & USB_DMAQ_QISAR_RX_DONE(index))
			{	
				USB_DMAQ_Callback(index,USB_EP_RX_DIR);
			}
			
			if (DMAQIntr & USB_DMAQ_QISAR_TX_DONE(index))
			{
				USB_DMAQ_Callback(index,USB_EP_TX_DIR);
			}
		}
	}
#endif //DRV_USB_DMA_QUEUE_SUPPORT	

#endif

#ifndef __OTG_ENABLE__
	/* Clear interrupt and unmask interrupt if application agree on it */
	IRQClearInt(IRQ_USB_CODE);
	g_UsbDrvInfo.is_ProUSBHISR = KAL_FALSE;

	if (g_UsbDrvInfo.is_unMaskUSB == KAL_TRUE)
		IRQUnmask(IRQ_USB_CODE);
#endif

#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	kal_uint8    IntrUSB;
	kal_uint8    IntrTx;
	kal_uint8    IntrRx;
	kal_uint32  ep_num;

	IntrUSB = USB_DRV_Reg8(USB_INTRUSB);
	IntrTx = USB_DRV_Reg8(USB_INTRIN1);
	IntrRx = USB_DRV_Reg8(USB_INTROUT1);

	g_UsbDrvInfo.IntrTx = 0;
	USB_Dbg_Trace(USB_DBG_HISR, IntrUSB, IntrRx);

   	/* Check for resume from suspend mode */
   	if (IntrUSB & USB_INTRUSB_RESUME)
   	{
		USB_Dbg_Trace(USB_RESUME, 0, 0);
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_IS_RESUME);

   		g_UsbDrvInfo.power_state = USB_STATE_NORMAL;
		g_UsbDrvInfo.resume_hdlr();
   	}

	/* Check for reset interrupts */
	if (IntrUSB & USB_INTRUSB_RESET)
	{
		g_usb_reset_times++;
		drv_trace1(TRACE_FUNC, (kal_uint32)USB_RESET_TIMES, g_usb_reset_times);
		USB_Dbg_Trace(USB_RESET, 0, 0);

		if(g_UsbDrvInfo.reset_hdlr == NULL)
			ASSERT(0);
		g_UsbDrvInfo.reset_hdlr();
	}

	/* Check for endpoint 0 interrupt */
	if (IntrTx&USB_INTRIN1_EP0)
	{
		if(g_UsbDrvInfo.ep0_hdlr == NULL)
			EXT_ASSERT(0, 0, 0, 0);
		g_UsbDrvInfo.ep0_hdlr();
	}

//in EP0 handler, read TX interrupt value
	if ( g_UsbDrvInfo.IntrTx & IntrTx)
 	{
		ASSERT(0);
	}
	else
	{
		IntrTx |= g_UsbDrvInfo.IntrTx;
	}
	
	// Task read fifo to flush data in USB_Clr_RX_EP_ISR()
	if ( g_UsbDrvInfo.IntrRx & IntrRx)
 	{ 
		ASSERT(0);
	}
	else
	{
		IntrRx |= g_UsbDrvInfo.IntrRx;
		g_UsbDrvInfo.IntrRx = 0;
	}

	/* Check for Bulk TX interrupt */
	for(ep_num = 1; ep_num <= MAX_TX_EP_NUM; ep_num++)
	{
		if (IntrTx & (0x01 <<ep_num))
   		{
   			if(g_UsbDrvInfo.ep_tx_hdlr[ep_num-1] != NULL)
   			{
   				g_UsbDrvInfo.ep_tx_hdlr[ep_num -1]();
   			}
   			else
   			{
				/* if EP does not support ep_hdr, its interrupt should not be triggered */
				/* Save debug info */
				USB_DRV_WriteReg8(USB_INDEX, ep_num);
				USB_Dbg_Trace(USB_EPN_UNEXPECTED_TX_HISR, USB_DRV_Reg8(USB_INCSR1), USB_DRV_Reg8(USB_INTRIN1E));
				drv_trace2(TRACE_FUNC, (kal_uint32)USB_EP_UNEXPECTED_TX_HISR, ep_num, USB_DRV_Reg8(USB_INCSR1));
#ifdef __MEUT__					
				ASSERT(0);
#endif
			}
		}
	}

	/* Check for Bulk RX interrupt */
	for(ep_num = 1; ep_num <= MAX_RX_EP_NUM; ep_num++)
	{
		if (IntrRx & (0x01 <<ep_num))
		{
			if(g_UsbDrvInfo.ep_rx_hdlr[ep_num-1]!=NULL)
			{
				g_UsbDrvInfo.ep_rx_hdlr[ep_num -1]();
			}
			else
			{
				/* if EP does not support ep_hdr, its interrupt should not be triggered */
				/* Save debug info */
				USB_DRV_WriteReg8(USB_INDEX, ep_num);
				USB_Dbg_Trace(USB_EPN_UNEXPECTED_RX_HISR, USB_DRV_Reg8(USB_OUTCSR1), USB_DRV_Reg8(USB_INTROUT1E));
				drv_trace2(TRACE_FUNC, (kal_uint32)USB_EP_UNEXPECTED_RX_HISR, ep_num, USB_DRV_Reg8(USB_OUTCSR1));
#ifdef __MEUT__					
				ASSERT(0);
#endif
			}
		}
	}

   	/* Check for suspend mode */
   	if (IntrUSB &  USB_INTRUSB_SUSPEND)
   	{
		USB_Dbg_Trace(USB_SUSPEND, 0, 0);
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_IS_SUSPEND);

		g_UsbDrvInfo.power_state = USB_STATE_SUSPEND;
		g_UsbDrvInfo.suspend_hdlr();
   	}

	/* Clear interrupt and unmask interrupt if application agree on it */
   	IRQClearInt(IRQ_USB_CODE);
	g_UsbDrvInfo.is_ProUSBHISR = KAL_FALSE;

   	if (g_UsbDrvInfo.is_unMaskUSB == KAL_TRUE)
   		IRQUnmask(IRQ_USB_CODE);
#endif
}
PRAGMA_END_COMPILER_OPTIMIZE_TIME

#ifndef __OTG_ENABLE__

static void USB_LISR(void)
{
	IRQMask(IRQ_USB_CODE);
	g_UsbDrvInfo.is_ProUSBHISR = KAL_TRUE;
	drv_active_hisr(DRV_USB_HISR_ID);
}


#if defined(DRV_USB_IP_V3)

static void USBDMA_HISR(void)
{
	kal_uint8  	DMAIntr;
	kal_uint32  	index;


	DMAIntr = USB_DRV_Reg8(USB_DMAINTR);

	while(DMAIntr != 0)
	{
		for (index = 0; index < MAX_DMA_NUM; index++)
		{
			if((DMAIntr&(1<<index)) != 0)
			{
				// write 0 clear first, then do call back function, order is very important !!!
				USB_DRV_WriteReg8(USB_DMAINTR, ~(0x01<<index));

				// DMA interrupt still occur if stop DMA channel and DMA do a transfer done at the same time.
				// Must skip it.
				if (g_UsbDrvInfo.dma_running[index] == KAL_TRUE)
				{

					/* DMA channel index+1 have interrupt */
#ifdef __DMA_PP_ENABLE__

					USB_DMA_Callback(index+1);

#else  /* __DMA_PP_ENABLE__ */

					if(USB_DRV_Reg32(USB_DMA_REALCNT(index+1)) != 0)
					{
						USB_DMA_Callback(index+1);
					}
					else
					{
						if(USB_Check_DMA_Time_Out(index+1) == KAL_TRUE)
						{
							USB_DMA_Callback(index+1);
						}
						else
						{
							ASSERT(0);
						}

						// DMA timer time out
/*
						if(index == 0)
						{
							// set address
							USB_DMA_Callback(index+1);
						}
						else
						{
							USB_DRV_SetBits(USB_DMACNTL(index+1), USB_DMACNTL_DMAEN);
						}
*/
					}
#endif  /* __DMA_PP_ENABLE__ */
				}
			}
		}

		/* Read register again to see if any interrupt is generated again */
		/* if pong pong buffer serve done, then we do call back function here */
		DMAIntr = USB_DRV_Reg8(USB_DMAINTR);
	}

	IRQClearInt(IRQ_USBDMA_CODE);
	IRQUnmask(IRQ_USBDMA_CODE);
}


static void USBDMA_LISR(void)
{
	kal_uint8  	DMAIntr;


	IRQMask(IRQ_USBDMA_CODE);
	drv_active_hisr(DRV_USBDMA_HISR_ID);
	DMAIntr = USB_DRV_Reg8(USB_DMAINTR);
	USB_Dbg_Trace(USB_DMA_LISR, DMAIntr, 0);
	ASSERT(DMAIntr != 0);
}

#endif


#endif  /* __OTG_ENABLE__ */


/* enable system global interrupt*/
void USB_EnSysIntr(void)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
//	USB_DRV_WriteReg(USB_INTRTXE, 0);
//	USB_DRV_WriteReg(USB_INTRRXE, 0);
//	USB_DRV_WriteReg8(USB_INTRUSBE, 0);
	USB_DRV_WriteReg8(USB_INTRUSBE, ~USB_INTRUSBE_SOF);
#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	USB_DRV_WriteReg8(USB_INTRIN1E, 0);
	USB_DRV_WriteReg8(USB_INTROUT1E, 0);
	USB_DRV_WriteReg8(USB_INTRUSBE, 0);
	USB_DRV_WriteReg8(USB_INTRUSBE, (USB_INTRUSBE_SUSPEND|USB_INTRUSBE_RESUME|USB_INTRUSBE_RESET));
#endif
}


/* Get the irq status */
kal_bool USB_HW_Get_UnMask_Irq(void)
{
	return g_UsbDrvInfo.is_unMaskUSB;
}


/* EP TX data prepared ready, set ready bit */
void USB_HW_EP_Tx_Ready(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type)
{
#if defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)||defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint32 savedMask;
#endif

	USB_Dbg_Trace(USB_DBG_SET_TXPKTREADY, ep_num, 0);
	USB_EP_Check(ep_num, USB_EP_TX_DIR, 0);
	USB_EP_DMA_Running_Check(ep_num, USB_EP_TX_DIR, 0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	savedMask = SaveAndSetIRQMask();  //DMA_Setup : clear UnderRun bit & Set TX_PkyReady at the same time
	USB_DRV_WriteReg8(USB_INDEX, ep_num);

	if(USB_DRV_Reg(USB_TXCSR)&USB_TXCSR_TXPKTRDY)  // check TX_PktReady bit
	{
		ASSERT(0);
	}

	USB_DRV_SetBits(USB_TXCSR, USB_TXCSR_TXPKTRDY);
	RestoreIRQMask(savedMask);
#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	USB_DRV_WriteReg8(USB_INCSR1, USB_INCSR1_INPKTRDY);
	RestoreIRQMask(savedMask);
#endif
}


/* EP RX data already read out, clear the data */
void USB_HW_EP_Rx_Ready(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type)
{
#if defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)||defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint32 savedMask;
#endif

	USB_EP_Check(ep_num, USB_EP_RX_DIR, 0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);

	if((USB_DRV_Reg(USB_RXCSR)&USB_RXCSR_RXPKTRDY) == 0)  // check RX_PktReady bit
	{
		ASSERT(0);
	}

	USB_DRV_ClearBits(USB_RXCSR, USB_RXCSR_RXPKTRDY);
	RestoreIRQMask(savedMask);
#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);

	if((USB_DRV_Reg8(USB_OUTCSR1)&USB_OUTCSR1_OUTPKTRDY) == 0)  // check RX_PktReady bit
	{
		ASSERT(0);
	}

	USB_DRV_ClearBits8(USB_OUTCSR1, USB_OUTCSR1_OUTPKTRDY);
	RestoreIRQMask(savedMask);
#endif
}


/* Get status. See if ep in fifo is empty.
   If false, it means some data in fifo still wait to send out */
kal_bool USB_HW_Is_EP_Tx_Empty(kal_uint32 ep_num, USB_ENDPT_TXFER_TYPE ep_type)
{
#if defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)||defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint32 savedMask;
#endif
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint16  	CSR;
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	kal_uint8 byCSR;
#endif

	USB_EP_Check(ep_num, USB_EP_TX_DIR, 0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	CSR = USB_DRV_Reg(USB_TXCSR);
	RestoreIRQMask(savedMask);

	if(CSR&USB_TXCSR_FIFONOTEMPTY)
		return  KAL_FALSE;
	else
		return  KAL_TRUE;
#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	byCSR = USB_DRV_Reg8(USB_INCSR1);
	RestoreIRQMask(savedMask);

	if(byCSR&USB_INCSR1_FIFONOTEMPTY)
		return  KAL_FALSE;
	else
		return  KAL_TRUE;
#endif
}

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)

/************************************************************
	DMA control functions
*************************************************************/
void USB_DMA_Callback(kal_uint8 dma_chan)
{
	usb_dma_callback callback = g_UsbDrvInfo.dma_callback[dma_chan-1];
	kal_uint8 ep_num;


	if(dma_chan == 0)
		ASSERT(0);

	/*lint -save -e676 */
	g_UsbDrvInfo.dma_callback[dma_chan-1] = NULL;

	USB_Dbg_Trace(USB_DBG_DMA_CALLBACK, dma_chan, (kal_uint32)g_UsbDrvInfo.dma_dir[dma_chan-1]);

	if(g_UsbDrvInfo.dma_dir[dma_chan-1] == USB_EP_TX_DIR)
	{
		ep_num = g_UsbDrvInfo.dma_tx_ep_num[dma_chan-1];

		USB_Dbg_Trace(USB_TXCSR_STAT, USB_DRV_Reg(USB_EPn_TXCSR(ep_num)), USB_DRV_Reg(USB_DMACNT(dma_chan)));
	}
	else
	{
		ep_num = g_UsbDrvInfo.dma_rx_ep_num[dma_chan-1];

	#ifdef __WRITE_THROUGH_CACHEABLE__
		/* Only RX need to invalidate cache */
		invalidate_wt_cache(g_UsbDrvInfo.dma_addr[dma_chan - 1], g_UsbDrvInfo.dma_length[dma_chan - 1]);
	#endif

		USB_Dbg_Trace(USB_RXCSR_STAT, USB_DRV_Reg(USB_EPn_RXCSR(ep_num)), USB_DRV_Reg(USB_DMACNT(dma_chan)));
	}


	if(USB_Check_DMA_Time_Out(dma_chan) == KAL_FALSE)
	{
		/* ep0 do not do this */
		if(g_UsbDrvInfo.dma_pktrdy[dma_chan-1] == KAL_TRUE)
		{
			if(g_UsbDrvInfo.dma_dir[dma_chan-1] == USB_EP_TX_DIR)
			{
				USB_HW_EP_Tx_Ready(ep_num, USB_ENDPT_BULK);

	#ifdef __USB_AUTO_SET__
				if(((ep_num == 1)&&(dma_chan == 2))||
					((ep_num == 2)&&(dma_chan == 3))||
						((ep_num == 3)&&(dma_chan == 4)))
				{
					ASSERT(0);
				}
	#endif
			}
			else if(g_UsbDrvInfo.dma_dir[dma_chan-1] == USB_EP_RX_DIR)
			{
				/* not assert in unknow size RX */
//				ASSERT(0);
				USB_HW_EP_Rx_Ready(ep_num, USB_ENDPT_BULK);
			}
		}
	}

	g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_FALSE;

	/* if application callback function does not request to clear drv_running set by itself, clear running state here*/
	if(g_UsbDrvInfo.dma_callback_upd_run[dma_chan-1] == KAL_FALSE)
	{
		g_UsbDrvInfo.dma_running[dma_chan-1] = KAL_FALSE;
	}

	if(callback != NULL)
		callback();
	/*lint -restore */
}

#ifdef DRV_USB_DMA_QUEUE_SUPPORT
void USB_DMAQEmpty_Callback(kal_uint8 dma_chan,USB_EP_DIRECTION direction)
{
	usb_dmaq_CB callback;
	void *privdata;
	
 	callback = g_UsbDrvInfo.dmaq_empty_callback[direction][dma_chan];
	//g_UsbDrvInfo.dmaq_callback[direction][dma_chan] = NULL;

	if(callback != NULL)
	{
		privdata = g_UsbDrvInfo.privdata[direction][dma_chan];	
		callback(privdata);
	}	
	/*lint -restore */
}

void USB_DMAQ_Callback(kal_uint8 dma_chan,USB_EP_DIRECTION direction)
{
	usb_dmaq_CB callback;
	void *privdata;
	

 	callback = g_UsbDrvInfo.dmaq_callback[direction][dma_chan];
	//g_UsbDrvInfo.dmaq_callback[direction][dma_chan] = NULL;

	if(callback != NULL)
	{
		privdata = g_UsbDrvInfo.privdata[direction][dma_chan];	
		callback(privdata);
	}
	/*lint -restore */
}
#endif //DRV_USB_DMA_QUEUE_SUPPORT	

void USB_Enable_DMA_Timer_Count(kal_uint8 dma_chan, kal_bool enable, kal_uint8 timer_ticks)
{
	if(enable == KAL_TRUE)
	{
		// Enable DMA timer
		USB_DRV_WriteReg(USB_DMA_TIMER(dma_chan), USB_DMA_TIMER_ENTIMER|(timer_ticks&USB_DMA_TIMER_TIMEOUT_MASK));
	}
	else
	{
		// Disable DMA timer
		USB_DRV_WriteReg(USB_DMA_TIMER(dma_chan), 0);
	}
}


kal_bool USB_Check_DMA_Time_Out(kal_uint8 dma_chan)
{
	if((USB_DRV_Reg(USB_DMA_TIMER(dma_chan))&USB_DMA_TIMER_TIMEOUT_STATUS) != 0)
	{
		return KAL_TRUE;
	}
	else
	{
		return KAL_FALSE;
	}
}

#endif /* #if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4) */


/************************************************************
	USB PHY
*************************************************************/
static void USB_Phy_Enable(USB_PHY_OWNER owner)
{
	kal_uint32 savedMask;


	if(owner >= USB_PHY_OWNER_MAX)
		EXT_ASSERT(0, (kal_uint32)owner, g_usb_phy_power_owner, 0);

	savedMask = SaveAndSetIRQMask();

	if(g_usb_phy_power_owner == 0)
	{
		USB_PowerControl(KAL_TRUE);
	}

	g_usb_phy_power_owner |= 1<<(kal_uint32)owner;
	RestoreIRQMask(savedMask);
}


static void USB_Phy_Disable(USB_PHY_OWNER owner)
{
	kal_uint32 savedMask;


	if(owner >= USB_PHY_OWNER_MAX)
		EXT_ASSERT(0, (kal_uint32)owner, g_usb_phy_power_owner, 0);

	savedMask = SaveAndSetIRQMask();
	g_usb_phy_power_owner &= ~(1<<(kal_uint32)owner);

	if(g_usb_phy_power_owner == 0)
	{
		USB_PowerControl(KAL_FALSE);
	}
	RestoreIRQMask(savedMask);
}

/************************************************************
	DCL part
*************************************************************/

/* Global variables */
#define DCL_USB_DRV_HANDLE  	0x01001000
#define DCL_USB_DRV_CHECK_HANDLE_IS_VALID(handle) ((handle)&DCL_USB_DRV_HANDLE)


/* Static variables */
static kal_bool g_USB_Drv_Init = KAL_FALSE;
static kal_bool g_USB_Drv_Open = KAL_FALSE;



/*************************************************************************
* FUNCTION
*  DclUSB_DRV_Initialize
*
* DESCRIPTION
*  This function is to initialize USB module
*  It should be called before user register USB EINT handler and only called once
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK : command is executed successfully.
*  STATUS_INVALID_OPERATION : already initialized.
*
*************************************************************************/
DCL_STATUS DclUSB_DRV_Initialize(void)
{
	if(g_USB_Drv_Init == KAL_TRUE)
	{
		/* Already initialized */
//		ASSERT(0);
		return STATUS_INVALID_OPERATION;
	}
	else
	{
		g_USB_Drv_Init = KAL_TRUE;
//		USB_Initialize_Drv_Phase1();
		return STATUS_OK;
	}
}


/*************************************************************************
* FUNCTION
*  DclUSB_DRV_Open
*
* DESCRIPTION
*  This function is to open the USB module and return a valid handle
*
* PARAMETERS
*  dev: only valid for DCL_USB
*  flags: no sepcial flags are needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed
*  DCL_HANDLE_OCCUPIED: Already opened
*  Other value: A valid handle
*
*************************************************************************/
DCL_HANDLE DclUSB_DRV_Open(DCL_DEV dev, DCL_FLAGS flags)
{
//	if((dev != DCL_USB)||(g_USB_Drv_Init == KAL_FALSE))
	if(dev != DCL_USB)
	{
		ASSERT(0);
		return (DCL_HANDLE)DCL_HANDLE_INVALID;
	}
	else
	{
		g_USB_Drv_Open = KAL_TRUE;
		return (DCL_HANDLE)DCL_USB_DRV_HANDLE;
	}
}

/*************************************************************************
* FUNCTION
*  DclUSB_DRV_Close
*
* DESCRIPTION
*  This function is to close the USB module.
*
* PARAMETERS
*  handle: the returned handle value of DclUSB_DRV_Open
*
* RETURNS
*  STATUS_INVALID_OPERATION: USB module does not open yet, but user want to close
*  STATUS_INVALID_DCL_HANDLE: Use invalid handle to close
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclUSB_DRV_Close(DCL_HANDLE handle)
{
	/* Check open or not and handle validity */
//	if((g_USB_Drv_Open == KAL_FALSE)||(DCL_USB_DRV_CHECK_HANDLE_IS_VALID(handle) == 0))
	if(DCL_USB_DRV_CHECK_HANDLE_IS_VALID(handle) == 0)
	{
		ASSERT(0);

//		if(g_USB_Drv_Open == KAL_FALSE)
//			return STATUS_INVALID_OPERATION;
//		else
//			return STATUS_INVALID_DCL_HANDLE;
	}

//	g_USB_Drv_Open = KAL_FALSE;

	return STATUS_OK;
}


/*************************************************************************
* FUNCTION
*  DclUSB_DRV_ReadData
*
* DESCRIPTION
*  This function is not supported for the USB module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclUSB_DRV_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	/* Check open or not and handle validity */
//	if((g_USB_Drv_Open == KAL_FALSE)||(DCL_USB_DRV_CHECK_HANDLE_IS_VALID(handle) == 0))
//	{
//		ASSERT(0);

//		if(g_USB_Drv_Open == KAL_FALSE)
//			return STATUS_INVALID_OPERATION;
//		else
//			return STATUS_INVALID_DCL_HANDLE;
//	}

	return STATUS_UNSUPPORTED;
}



/*************************************************************************
* FUNCTION
*  DclUSB_DRV_WriteData
*
* DESCRIPTION
*  This function is not supported for the USB module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclUSB_DRV_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	/* Check open or not and handle validity */
//	if((g_USB_Drv_Open == KAL_FALSE)||(DCL_USB_DRV_CHECK_HANDLE_IS_VALID(handle) == 0))
//	{
//		ASSERT(0);

//		if(g_USB_Drv_Open == KAL_FALSE)
//			return STATUS_INVALID_OPERATION;
//		else
//			return STATUS_INVALID_DCL_HANDLE;
//	}

	return STATUS_UNSUPPORTED;
}


/*************************************************************************
* FUNCTION
*  DclUSB_DRV_Configure
*
* DESCRIPTION
*  This function is not supported for the USB module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclUSB_DRV_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	/* Check open or not and handle validity */
//	if((g_USB_Drv_Open == KAL_FALSE)||(DCL_USB_DRV_CHECK_HANDLE_IS_VALID(handle) == 0))
//	{
//		ASSERT(0);

//		if(g_USB_Drv_Open == KAL_FALSE)
//			return STATUS_INVALID_OPERATION;
//		else
//			return STATUS_INVALID_DCL_HANDLE;
//	}

	return STATUS_UNSUPPORTED;
}



/*************************************************************************
* FUNCTION
*  DclUSB_DRV_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the USB module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclUSB_DRV_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, DCL_UINT8 index,void *class_handler)
{
	if (index > USB_MAX_FEATURE_NUM)
		ASSERT(0);
	
	USB_Class_Driver[index]= (DCL_USB_CLASS_API)class_handler;

	return STATUS_OK;
}


/*******************************************************************************
	Control functions for USB_DRV
 *******************************************************************************/

/* Initialize usb driver SW information, called at USB_Init() */
static DCL_STATUS DCL_USB_CTRL_API_USB_Init_Drv_Info(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	DCL_BOOL *dcl_data_ptr = (DCL_BOOL*)data;
	kal_bool is_ft_mode = (kal_bool)(*dcl_data_ptr);
#endif
	kal_int32 index;


	g_UsbDrvInfo.power_state = USB_STATE_NORMAL;
	g_UsbDrvInfo.is_unMaskUSB = KAL_TRUE;
	g_UsbDrvInfo.is_ProUSBHISR = KAL_FALSE;
	g_UsbDrvInfo.reset_hdlr = NULL;
	g_UsbDrvInfo.ep0_hdlr = NULL;

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	g_UsbDrvInfo.Is_HS_mode = KAL_FALSE;
	g_UsbDrvInfo.suspend_with_FIFO_not_empty = KAL_FALSE;

	if(is_ft_mode == KAL_TRUE)
	{
		if((USB_DRV_Reg8(USB_POWER)&USB_POWER_HSMODE) != 0)
			g_UsbDrvInfo.Is_HS_mode = KAL_TRUE;
		else
			g_UsbDrvInfo.Is_HS_mode = KAL_FALSE;
	}
#endif

	for(index = (MAX_TX_EP_NUM-1); index >= 0; index--)
	{
		g_UsbDrvInfo.ep_tx_enb_state[index] = USB_EP_STATE_DISABLE;
		g_UsbDrvInfo.ep_tx_hdlr[index] = NULL;
		g_UsbDrvInfo.ep_tx_stall_status[index] = KAL_FALSE;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
		g_UsbDrvInfo.ep_tx_flush_intr[index] = KAL_FALSE;
#endif
	}

	for(index = (MAX_RX_EP_NUM-1); index >= 0; index--)
	{
		g_UsbDrvInfo.ep_rx_enb_state[index] = USB_EP_STATE_DISABLE;
		g_UsbDrvInfo.ep_rx_hdlr[index] = NULL;
		g_UsbDrvInfo.ep_rx_stall_status[index] = KAL_FALSE;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
		g_UsbDrvInfo.ep_rx_flush_intr[index] = KAL_FALSE;
#endif
	}

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	for(index = (MAX_EP_NUM-1); index >= 0; index--)
	{
		g_UsbDrvInfo.dma_port[USB_EP_TX_DIR][index] = 0;
		g_UsbDrvInfo.dma_port[USB_EP_RX_DIR][index] = 0;
	}
#ifdef DRV_USB_DMA_QUEUE_SUPPORT
	g_UsbDrvInfo.dma_channel = 1;
#else
	g_UsbDrvInfo.dma_channel = 0;
#endif
#endif

	for(index = (MAX_DMA_NUM-1); index >= 0; index--)
	{
		g_UsbDrvInfo.dma_pktrdy[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_running[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_callback_upd_run[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_callback[index] = NULL;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
		g_UsbDrvInfo.dma_tx_ep_num[index] = 0;
		g_UsbDrvInfo.dma_rx_ep_num[index] = 0;
//		g_UsbDrvInfo.dma_is_pp[index] = KAL_FALSE;
//		g_UsbDrvInfo.dma_is_running[0][index] = KAL_FALSE;
//		g_UsbDrvInfo.dma_is_running[1][index] = KAL_FALSE;
#else
		g_UsbDrvInfo.dma_port[index] = 0;
#endif
	}

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_ResetDrv_Info(DCL_CTRL_DATA_T *data)
{
	kal_int32 index;
#if !(defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4))
	kal_uint32 savedMask;
#endif

	g_UsbDrvInfo.power_state = USB_STATE_NORMAL;
	g_UsbDrvInfo.is_unMaskUSB = KAL_TRUE;
	g_UsbDrvInfo.is_ProUSBHISR = KAL_FALSE;

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	if((USB_DRV_Reg8(USB_POWER)&USB_POWER_HSMODE) != 0)
		g_UsbDrvInfo.Is_HS_mode = KAL_TRUE;
	else
		g_UsbDrvInfo.Is_HS_mode = KAL_FALSE;
#endif

	for(index = (MAX_TX_EP_NUM-1); index >= 0; index--)
	{
		g_UsbDrvInfo.ep_tx_enb_state[index] = USB_EP_STATE_DISABLE;
		g_UsbDrvInfo.ep_tx_stall_status[index] = KAL_FALSE;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
		g_UsbDrvInfo.ep_tx_flush_intr[index] = KAL_FALSE;
#endif
	}

	for(index = (MAX_RX_EP_NUM-1); index >= 0; index--)
	{
		g_UsbDrvInfo.ep_rx_enb_state[index] = USB_EP_STATE_DISABLE;
		g_UsbDrvInfo.ep_rx_stall_status[index] = KAL_FALSE;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
		g_UsbDrvInfo.ep_rx_flush_intr[index] = KAL_FALSE;
#endif
	}

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	for(index = (MAX_DMA_NUM-1); index >= 0; index--)
	{
		USBDMA_Stop(index+1);
//		USBDMA_PPStop(index+1);
	}

	#if defined(DRV_USB_IP_V3)
	//clear interrupt. write 0 clear
	USB_DRV_WriteReg32(USB_DMAINTR, 0x00);
	#elif defined(DRV_USB_IP_V4)
	//clear interrupt. write 1 clear
	DRV_WriteReg8(USB_DMA_INTR_STATUS, 0xFF);
	#endif
#endif//defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)

	for(index = (MAX_DMA_NUM-1); index >= 0; index--)
	{
#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)||defined(DRV_USB_IP_V2))
		if(g_UsbDrvInfo.dma_port[index]!=0)
		{
			if (DMA_CheckRunStat(g_UsbDrvInfo.dma_port[index]))
			{
				DMA_Stop(g_UsbDrvInfo.dma_port[index]);
			}

			savedMask = SaveAndSetIRQMask();
			if (DMA_CheckITStat(g_UsbDrvInfo.dma_port[index]))  /* check if interrupt is pending and waiting for service */
			{
				DMA_ACKI(g_UsbDrvInfo.dma_port[index]);
				IRQClearInt(IRQ_DMA_CODE);
			}
			RestoreIRQMask(savedMask);
		}
#endif

		g_UsbDrvInfo.dma_pktrdy[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_running[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_callback_upd_run[index] = KAL_FALSE;
		g_UsbDrvInfo.dma_callback[index] = NULL;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
//		g_UsbDrvInfo.dma_is_pp[index] = KAL_FALSE;
//		g_UsbDrvInfo.dma_is_running[0][index] = KAL_FALSE;
//		g_UsbDrvInfo.dma_is_running[1][index] = KAL_FALSE;
#endif
#if defined(DRV_USB_IP_V4)
	g_UsbDrvInfo.dmaq_empty_callback[USB_EP_RX_DIR][index] = NULL;
	g_UsbDrvInfo.dmaq_empty_callback[USB_EP_TX_DIR][index] = NULL;
#endif
	}

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Register_Drv_Info(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_REGISTER_DRV_INFO_T *prregister_drv_info;
	USB_DRV_HDLR_TYPE type;
	kal_uint32 ep_num;
	usb_drv_intr_handler_ptr hdlr;


	prregister_drv_info = &data->rDrv_Info;
	ep_num = (kal_uint32)prregister_drv_info->u4ep_num;
	type = (USB_DRV_HDLR_TYPE)prregister_drv_info->type;
	hdlr = (usb_drv_intr_handler_ptr)prregister_drv_info->hdlr;


	switch(type)
	{
	case USB_DRV_HDLR_RESET:
		g_UsbDrvInfo.reset_hdlr = hdlr;
		break;
	case USB_DRV_HDLR_SUSPEND:
		g_UsbDrvInfo.suspend_hdlr = hdlr;
		break;
	case USB_DRV_HDLR_RESUME:
		g_UsbDrvInfo.resume_hdlr = hdlr;
		break;
	case USB_DRV_HDLR_EP0:
		g_UsbDrvInfo.ep0_hdlr = hdlr;
		break;
	case USB_DRV_HDLR_EP_TX:
		USB_EP_Check(ep_num, USB_EP_TX_DIR, 0);
		g_UsbDrvInfo.ep_tx_hdlr[ep_num-1] = hdlr;
		break;
	case USB_DRV_HDLR_EP_RX:
		USB_EP_Check(ep_num, USB_EP_RX_DIR, 0);
		g_UsbDrvInfo.ep_rx_hdlr[ep_num-1] = hdlr;
		break;
	default:
		EXT_ASSERT(0, (kal_uint32)type, ep_num, 0);
		break;
	}

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Set_UnMask_Irq(DCL_CTRL_DATA_T *data)
{
	DCL_BOOL *dcl_data_ptr = (DCL_BOOL*)data;
	kal_bool is_set = (kal_bool)(*dcl_data_ptr);


	g_UsbDrvInfo.is_unMaskUSB = is_set;
	return STATUS_OK;
}



static DCL_STATUS DCL_USB_CTRL_API_USB_Get_UnMask_Irq(DCL_CTRL_DATA_T *data)
{
	DCL_BOOL *usb_data;


	usb_data = (DCL_BOOL *)data;
	*usb_data = (DCL_BOOL)g_UsbDrvInfo.is_unMaskUSB;
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Get_EP_Stall_Status(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_1_T	 *prget_stall_status;
	kal_uint32  ep_num;
	USB_EP_DIRECTION direction;



	prget_stall_status = &data->rEP_Ctrl_Func_1;
	ep_num = (kal_uint32)prget_stall_status->u4ep_num;
	direction = (USB_EP_DIRECTION)prget_stall_status->direction;

	USB_EP_Check(ep_num, direction, 0);

	if(direction == USB_EP_TX_DIR)
	{
		prget_stall_status->fg_result = (DCL_BOOL)g_UsbDrvInfo.ep_tx_stall_status[ep_num-1];
	}
	else
	{
		prget_stall_status->fg_result = (DCL_BOOL)g_UsbDrvInfo.ep_rx_stall_status[ep_num-1];
	}

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Drv_Create_ISR(DCL_CTRL_DATA_T *data)
{
#ifndef __OTG_ENABLE__
	IRQ_Register_LISR(IRQ_USB_CODE, USB_LISR,"USB");
	DRV_Register_HISR(DRV_USB_HISR_ID, USB_HISR);
	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Drv_Activate_ISR(DCL_CTRL_DATA_T *data)
{
#ifndef __OTG_ENABLE__
	IRQSensitivity(IRQ_USB_CODE,LEVEL_SENSITIVE);
	IRQUnmask(IRQ_USB_CODE);
	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USBDMA_Drv_Create_ISR(DCL_CTRL_DATA_T *data)
{
#if (defined(DRV_USB_IP_V3)&&(!defined(__OTG_ENABLE__)))
	IRQ_Register_LISR(IRQ_USBDMA_CODE, USBDMA_LISR, "USBDMA");
	DRV_Register_HISR(DRV_USBDMA_HISR_ID, USBDMA_HISR);
	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USBDMA_Drv_Activate_ISR(DCL_CTRL_DATA_T *data)
{
#if (defined(DRV_USB_IP_V3)&&(!defined(__OTG_ENABLE__)))
	IRQSensitivity(IRQ_USBDMA_CODE, LEVEL_SENSITIVE);
	IRQUnmask(IRQ_USBDMA_CODE);
	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Pull_Up_DP_Line(DCL_CTRL_DATA_T *data)
{
	/* For: Clear all interrupt before DP pull high
 	 * Reason: Windows MTP class won't trigger new reset signal if cable plugout and re-plugin.
	 *         We need a reset interrupt to reset IP else force clear all interrupt before DP pull high.
	 */
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	// read and clear
	USB_DRV_Reg8(USB_INTRUSB);
	USB_DRV_Reg(USB_INTRTX);
	USB_DRV_Reg(USB_INTRTX);
	#if defined(DRV_USB_IP_V4)
	USB_DRV_WriteReg(USB_INTRRX, USB_DRV_Reg(USB_INTRRX));// Write 1 clear
	
#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)
	#if defined(DRV_USB_SLEEP_SUPPORT)
	#if defined(__TRADITIONAL_MODEM_CARD__)
	RM_Usb_Lock_Clock(KAL_TRUE);	//hosted dongle no need to lock AP's clock in modem side
	#else
	ccci_send_message(CCMSG_ID_SYSMSGSVC_LOCK_AP_26M, AP_26M_LOCK);
	#endif
	#else
	//L1SM_SleepDisable(usb_pdn_handle);
	USB_SleepEnable(KAL_FALSE);
	#endif
	EINT_Set_Sensitivity(EINT_USB_PWRDWN, LEVEL_SENSITIVE);
	EINT_Registration(EINT_USB_PWRDWN, KAL_FALSE, LEVEL_LOW, USB_PWNDWN_HISR, KAL_FALSE);
#endif
	
	
	#else
	USB_DRV_WriteReg(USB_INTRRX, ~USB_DRV_Reg(USB_INTRRX));// Write 0 clear
	#endif
#elif defined(DRV_USB_IP_V2)
#elif defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)
	USB_DRV_Reg8(USB_INTRUSB);
	USB_DRV_Reg8(USB_INTRIN1);
	USB_DRV_Reg8(USB_INTROUT1);
#endif

	/*Pull up DP here!!*/
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	/* For V3, it already enables phy's power in USB_Initialize_Drv_Phase1() */
	USB_DRV_SetBits8(USB_POWER, USB_POWER_SOFTCONN);
#elif defined(DRV_USB_IP_V2)

#elif defined(DRV_USB_IP_V1)
	USB_Phy_Enable(USB_PHY_OWNER_USB);
#elif defined(DRV_USB_IP_V1_PLUS)
	USB_Phy_Enable(USB_PHY_OWNER_USB);
	USB_DRV_SetBits8(USB_PHY_CONTROL, USB_PHY_CONTROL_TOF | USB_PHY_CONTROL_PUB);
#endif
	g_UsbDrvInfo.usb_disconnect = KAL_FALSE;
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Set_DMA_Stop_Flag(DCL_CTRL_DATA_T *data)
{
	g_UsbDrvInfo.usb_disconnect = KAL_TRUE;
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Reset_Drv(DCL_CTRL_DATA_T *data)
{
	/* Enable software reset, USB IP only can be reset by SW when detecting reset signal from bus */
#if defined(DRV_USB_IP_V3)
	USB_DRV_WriteReg(USB_SWRST, USB_SWRST_DISUSBRESET);
#elif defined(DRV_USB_IP_V4)
	USB_DRV_WriteReg(USB_BUSPERF3, USB_BUSPERF3_DISUSBRESET);
#endif
	
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
//	USB_DRV_WriteReg8(USB_RSTINFO, 0xA6);
	USB_DRV_WriteReg8(USB_RSTINFO, 0x0A0);
	/* Because softconn has be decided to set or not */
	/* Set USB_POWER_ISOUPDATE will make ISO pipe with DMA abnormally */
//	USB_DRV_SetBits8(USB_POWER, (USB_POWER_ISOUPDATE|USB_POWER_ENABLESUSPENDM));
	USB_DRV_SetBits8(USB_POWER, (USB_POWER_ENABLESUSPENDM));

#ifdef __USB_HS_ENABLE__
	USB_DRV_SetBits8(USB_POWER, USB_POWER_HSENAB);
#else
	USB_DRV_ClearBits8(USB_POWER, USB_POWER_HSENAB);
#endif

#elif defined(DRV_USB_IP_V2)


#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	/* enable software reset, USB IP only can be reset by SW when detecting reset signal from bus */
	USB_DRV_WriteReg8(USB_POWER, USB_POWER_SETSUSPEND|USB_POWER_SWRSTENAB);
#endif
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Initialize_Drv_Phase1(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	volatile kal_uint32 delay;

//#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)
//	usb_pdn_handle = L1SM_GetHandle();
//#endif

	/* Open AHB clock, then we can set USB IP's registers */
#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)
	PDN_CLR(PDN_USB);
#else
	#if defined(__OLD_PDN_ARCH__)
	#if defined(__OLD_PDN_DEFINE__)
		USB_DRV_WriteReg(DRVPDN_CON0_CLR, DRVPDN_CON0_USB);
	#elif defined(__CLKG_DEFINE__)
		USB_DRV_WriteReg(CG_CLR0, CG_CON0_USB);
	#endif
	#else
//		DRVPDN_Disable(PDN_USB);	
	PDN_CLR(PDN_USB); //power up dev
	USB_SleepEnable(KAL_FALSE);
	#endif
#endif

	/* Turn on 3.3V phy power */
	USB_Phy_Enable(USB_PHY_OWNER_USB);

#if !defined(IC_MODULE_TEST) || defined(__SLT_MD_CATCHER_LOG_VIA_USB__)
	/* wait power stable */
	for(delay = 0; delay < 10000; delay++)  ;
#endif //IC_MODULE_TEST

#if (defined(DRV_USB_PHY_COST_DOWN))

	USB_DRV_WriteReg8(USB_PHYCR1_0, (USB_PHYCR1_0_IADJ_MASK2|USB_PHYCR1_0_BGR_CHIP_EN));//BGI enable

#if defined(DRV_USB_PHY_65_INITIAL_VALUE) //6268 MP
	USB_DRV_WriteReg8(USB_PHYCR1_2, USB_PHYCR1_2_RG_PLL_DIV);

#elif defined(DRV_USB_PHY_M110_INITIAL_VALUE) //6253 & MT6253D

	#if defined(DRV_MT6253_VERSION_CONTROL) //6253 MP
	if (INT_ecoVersion() < ECO_E5) //PLL Divider
	{
		USB_DRV_WriteReg8(USB_PHYCR1_2, USB_PHYCR1_2_RG_PLL_DIV2);
	}
	else
	#endif
	{
		USB_DRV_WriteReg8(USB_PHYCR1_2, USB_PHYCR1_2_RG_PLL_DIV3);
	}
#endif

#ifndef	__USB_PHY_BC11_SUPPORT__
	USB_DRV_WriteReg8(USB_PHYCR4_3, (USB_PHYCR4_3_UART_MODE|USB_PHYCR4_3_OTG_RESET_EN));
#endif

#elif (defined(DRV_USB_PHY_U65_IP))

#elif (defined(DRV_USB_PHY_M60_IP))

#elif (defined(DRV_USB_PHY_U40_IP))

#elif (defined(DRV_USB_PHY_T28_IP))

#else //Old PHY version

#if defined(DRV_USB_PHY_SUPPORT_OTG)
	/* Only for 38 E2 and after chip */
	USB_DRV_ClearBits8(USB_PHYCR2_3, USB_PHYCR2_3_HS_TERMC_MASK);
	USB_DRV_ClearBits8(USB_PHYCR3_0, USB_PHYCR3_0_IADJ_MASK);

	USB_DRV_ClearBits8(USB_PHYCR1_1, USB_PHYCR1_1_PLL_CCP_MASK);
	USB_DRV_SetBits8(USB_PHYCR1_1, USB_PHYCR1_1_PLL_CCP_SET);

	USB_DRV_ClearBits8(USB_PHYCR3_2, USB_PHYCR3_2_TEST_CTRL_MASK);
	USB_DRV_SetBits8(USB_PHYCR3_2, USB_PHYCR3_2_TEST_CTRL2_SET);
#else
	/* MT6235 Reset VBUSCMP_EN, its reset value is 1 */
	USB_DRV_ClearBits8(USB_PHYCR5_0, USB_PHYCR5_0_VBUSCMP_EN);

#endif

#endif

#if defined (__USB_MODEM_CARD_SUPPORT__)
	//USB_DRV_WriteReg8(USB_PHYCR3_0, USB_PHYCR3_0_CLEAR_MASK);   // value=00 Max
	//USB_DRV_WriteReg8(USB_PHYCR2_3, USB_PHYCR2_3_HS_TERMC|USB_PHYCR2_3_FORCE_DRV_VBUS);
#endif

#if defined(DRV_USB_PHY_CURRENT_CONSUMPTION)
	USB_Save_Current_Consumption();
#endif

#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)
	PDN_SET(PDN_USB);
#else
	#if defined(__OLD_PDN_ARCH__)
	#if defined(__OLD_PDN_DEFINE__)
		USB_DRV_WriteReg(DRVPDN_CON0_SET, DRVPDN_CON0_USB);
	#elif defined(__CLKG_DEFINE__)
		USB_DRV_WriteReg(CG_SET0, CG_CON0_USB);
	#endif
	#else
	//	DRVPDN_Enable(PDN_USB);	
	PDN_SET(PDN_USB); //power down dev
	USB_SleepEnable(KAL_TRUE); //unlock sleep mode
	#endif
#endif

#endif  /* defined(DRV_USB_IP_V3) */

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Initialize_Drv_Phase2(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	DCL_BOOL *dcl_data_ptr = (DCL_BOOL*)data;
	kal_bool b_is_reset = (kal_bool)(*dcl_data_ptr);
#endif

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	/* Software reset */
	if(b_is_reset == KAL_TRUE)
	{
#if defined(DRV_USB_IP_V3)	
		USB_DRV_WriteReg(USB_SWRST, (USB_SWRST_DISUSBRESET|USB_SWRST_SWRST));
#elif defined(DRV_USB_IP_V4)
		USB_DRV_WriteReg(USB_BUSPERF3, USB_DRV_Reg(USB_BUSPERF3)|(USB_BUSPERF3_DISUSBRESET|USB_BUSPERF3_SWRST));
#endif
	}

	/* Enable system interrupts, but disable all ep interrupts */
	USB_EnSysIntr();
	USB_DRV_WriteReg8(USB_INDEX, 0);
	/* Flush ep0 FIFO */
	USB_DRV_WriteReg(USB_CSR0, USB_CSR0_FLUSHFIFO);
	/* enable EP0 interrupt */
	USB_EP0En();
#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	/* software reset */
	USB_DRV_WriteReg8(USB_RSTCTRL, USB_RSTCTRL_SWRST);
	USB_DRV_WriteReg8(USB_RSTCTRL, 0);
	/* When mcu set SWRST, the USB_POWER register will be clear as 0 */
	USB_DRV_WriteReg8(USB_POWER, (USB_POWER_SETSUSPEND|USB_POWER_SWRSTENAB));
	USB_EnSysIntr();
	USB_EP0En();	/* enable EP0 */
#endif

#if defined(DRV_USB_IP_V4)
	/* Unmask USB L1 interrupt */
	DRV_WriteReg(USB_L1INTM, (USB_L1INTM_DMA_INT_UNMASK|USB_L1INTM_TX_INT_UNMASK|USB_L1INTM_RX_INT_UNMASK|USB_L1INTM_USBCOM_INT_UNMASK|USB_L1INTM_PSR_INT_UNMASK)|USB_L1INTM_QINT_UNMASK|USB_L1INTM_QHIF_INT_UNMASK);
	//DRV_WriteReg(USB_L1INTM,  USB_L1INTM_DMA_INT_UNMASK|USB_L1INTM_USBCOM_INT_UNMASK|USB_L1INTM_TX_INT_UNMASK|USB_L1INTM_RX_INT_UNMASK);
	DRV_WriteReg8(USB_DMA_INTR_UNMASK_SET,  0xFF);
	#ifdef DRV_USB_DMA_QUEUE_SUPPORT
		USB_DRV_WriteReg(USB_DMACNTL(1), ((g_UsbDrvInfo.dma_burst_mode&0x03)<<9));	
	#endif	
#endif
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Release_Drv(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	
	USB_DRV_Reg8(USB_FADDR); // QQ : after read register, power off can be normal 
	
	USB_PDNEnable();
	UPLL_Disable(UPLL_OWNER_USB);
#endif
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_SetAddress(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_USB_SET_ADDR_T  *prusb_set_addr;
	kal_uint8 addr;
	USB_SET_ADDR_STATE state;


	prusb_set_addr = &data->rUSB_Set_Addr;
	addr = (kal_uint8)prusb_set_addr->u1addr;
	state = (USB_SET_ADDR_STATE)prusb_set_addr->state;


#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	if(state == USB_SET_ADDR_STATUS)
	{
		USB_DRV_WriteReg8(USB_FADDR, addr);
	}
#elif defined(DRV_USB_IP_V2)
	if(state == USB_SET_ADDR_STATUS)
	{
		USB_DRV_WriteReg8(USB_ADDR, addr);
	}
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	if(state == USB_SET_ADDR_DATA)
	{
		USB_DRV_WriteReg8(USB_FADDR, addr);
	}
#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_GetFrameCount(DCL_CTRL_DATA_T *data)
{
	DCL_UINT16 *dcl_data_ptr = (DCL_UINT16*)data;


	kal_uint16 sof;


#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	sof =  USB_DRV_Reg(USB_FRAME);
#elif defined(DRV_USB_IP_V2)
	sof = (USB_DRV_Reg8(USB_FRM_NUMH)<<8) + USB_DRV_Reg8(USB_FRM_NUML);
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	sof = (USB_DRV_Reg8(USB_FRAME2)<<8) + USB_DRV_Reg8(USB_FRAME1);
#endif

	*dcl_data_ptr = (DCL_UINT16)sof;
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_TxEPInit(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_USB_EP_INIT_T *prusb_ep_init;
	kal_uint32 ep_num;
	kal_uint16 data_size;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	USB_ENDPT_TXFER_TYPE type;
	kal_bool double_fifo;
#endif	
	kal_uint32 savedMask;


	prusb_ep_init = &data->rUSB_Ep_Init;
	ep_num = (kal_uint32)prusb_ep_init->u4ep_num;
	data_size = (kal_uint16)prusb_ep_init->u2data_size;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	type = (USB_ENDPT_TXFER_TYPE)prusb_ep_init->type;
	double_fifo = (kal_bool)prusb_ep_init->fgdouble_fifo;



	USB_EP_Check(ep_num, USB_EP_TX_DIR, 0);
	USB_EP_DMA_Running_Check(ep_num, USB_EP_TX_DIR, 0);

	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	/* Double buffers, so flush twice */
	USB_DRV_WriteReg(USB_TXCSR, 0x00);
	USB_DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
	USB_DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
	USB_DRV_WriteReg(USB_TXMAXP, data_size);

	/* Set FIFO address here */
	if(type == USB_ENDPT_BULK)
	{
		if(double_fifo == KAL_TRUE)
		{
			//double  buffer
			USB_DRV_WriteReg8(USB_TXFIFOSZ, (USB_FIFOSZ_SIZE_512|USB_FIFOSZ_DPB));
			USB_DRV_WriteReg(USB_TXFIFOADD, (g_FIFOadd/8));
			g_FIFOadd += USB_BULK_FIFO_UNIT_SIZE*2;
		}
		else
		{
			//single buffer
			USB_DRV_WriteReg8(USB_TXFIFOSZ, USB_FIFOSZ_SIZE_512);
			USB_DRV_WriteReg(USB_TXFIFOADD, (kal_uint16)(g_FIFOadd/8));
			g_FIFOadd += USB_BULK_FIFO_UNIT_SIZE;
		}
	}
	else if(type == USB_ENDPT_INTR)
	{
#ifdef __INTR_HB__
		USB_DRV_WriteReg8(USB_TXFIFOSZ, USB_FIFOSZ_SIZE_4096);
		USB_DRV_WriteReg(USB_TXFIFOADD, (kal_uint16)(g_FIFOadd/8));
		g_FIFOadd += USB_INTR_FIFO_UNIT_SIZE;  //4096
#else
		if(double_fifo == KAL_TRUE)
		{
			USB_DRV_WriteReg8(USB_TXFIFOSZ, (USB_FIFOSZ_SIZE_32|USB_FIFOSZ_DPB));
			USB_DRV_WriteReg(USB_TXFIFOADD, (kal_uint16)(g_FIFOadd/8));
			g_FIFOadd += USB_INTR_FIFO_UNIT_SIZE*2;
		}
		else
		{
			USB_DRV_WriteReg8(USB_TXFIFOSZ, USB_FIFOSZ_SIZE_32);
			USB_DRV_WriteReg(USB_TXFIFOADD, (kal_uint16)(g_FIFOadd/8));
			g_FIFOadd += USB_INTR_FIFO_UNIT_SIZE; //32
		}
#endif
	}
	else if(type == USB_ENDPT_ISO)
	{
#ifdef __ISO_HB__
		USB_DRV_WriteReg8(USB_TXFIFOSZ, USB_FIFOSZ_SIZE_4096);
		USB_DRV_WriteReg(USB_TXFIFOADD, (kal_uint16)(g_FIFOadd/8));
		g_FIFOadd += USB_ISO_FIFO_UNIT_SIZE;
#else
		if(double_fifo == KAL_TRUE)
		{
			USB_DRV_WriteReg8(USB_TXFIFOSZ, (USB_FIFOSZ_SIZE_1024|USB_FIFOSZ_DPB));
			USB_DRV_WriteReg(USB_TXFIFOADD, (kal_uint16)(g_FIFOadd/8));
			g_FIFOadd += USB_ISO_FIFO_UNIT_SIZE*2;
		}
		else
		{
			USB_DRV_WriteReg8(USB_TXFIFOSZ, USB_FIFOSZ_SIZE_1024);
			USB_DRV_WriteReg(USB_TXFIFOADD, (kal_uint16)(g_FIFOadd/8));
			g_FIFOadd += USB_ISO_FIFO_UNIT_SIZE;
		}
#endif
	}

	RestoreIRQMask(savedMask);

	if(g_FIFOadd > USB_MAX_FIFO_SIZE)
		ASSERT(0);

#elif defined(DRV_USB_IP_V2)

#elif defined(DRV_USB_IP_V1)
	USB_EP_Check(ep_num, USB_EP_TX_DIR, 0);

	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	USB_DRV_WriteReg8(USB_INCSR1, (USB_INCSR1_CLRDATATOG|USB_INCSR1_FLUSHFIFO));
	USB_DRV_WriteReg8(USB_INMAXP, (kal_uint8)(data_size/8));
	RestoreIRQMask(savedMask);
#elif defined(DRV_USB_IP_V1_PLUS)
	USB_EP_Check(ep_num, USB_EP_TX_DIR, 0);

	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	USB_DRV_WriteReg8(USB_INCSR1, (USB_INCSR1_CLRDATATOG|USB_INCSR1_FLUSHFIFO));
	USB_DRV_WriteReg8(USB_INMAXP, (kal_uint8)(data_size));
	RestoreIRQMask(savedMask);
#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_RxEPInit(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_USB_EP_INIT_T *prusb_ep_init;
	kal_uint32 ep_num;
	kal_uint16 data_size;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	USB_ENDPT_TXFER_TYPE type;
	kal_bool double_fifo;
#endif
	kal_uint32 savedMask;


	prusb_ep_init = &data->rUSB_Ep_Init;
	ep_num = (kal_uint32)prusb_ep_init->u4ep_num;
	data_size = (kal_uint16)prusb_ep_init->u2data_size;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	type = (USB_ENDPT_TXFER_TYPE)prusb_ep_init->type;
	double_fifo = (kal_bool)prusb_ep_init->fgdouble_fifo;


	USB_EP_Check(ep_num, USB_EP_RX_DIR, 0);
	USB_EP_DMA_Running_Check(ep_num, USB_EP_RX_DIR, 0);

	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	USB_DRV_WriteReg(USB_RXCSR, USB_RXCSR_RXPKTRDY);
	USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG|USB_RXCSR_RXPKTRDY));
	USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG|USB_RXCSR_RXPKTRDY));
	USB_DRV_WriteReg(USB_RXMAXP, data_size);

	/* Set FIFO address here */
	if(type == USB_ENDPT_BULK)
	{
		if(double_fifo == KAL_TRUE)
		{
			//double buffer
			USB_DRV_WriteReg8(USB_RXFIFOSZ, (USB_FIFOSZ_SIZE_512|USB_FIFOSZ_DPB));
			USB_DRV_WriteReg(USB_RXFIFOADD, (g_FIFOadd/8));
			g_FIFOadd += USB_BULK_FIFO_UNIT_SIZE*2;
		}
		else
		{
			//single buffer
			USB_DRV_WriteReg8(USB_RXFIFOSZ, USB_FIFOSZ_SIZE_512);
			USB_DRV_WriteReg(USB_RXFIFOADD, (kal_uint16)(g_FIFOadd/8));
			g_FIFOadd += USB_BULK_FIFO_UNIT_SIZE;
		}
	}
	else if(type == USB_ENDPT_ISO)
	{
#ifdef __ISO_HB__
		USB_DRV_WriteReg8(USB_RXFIFOSZ, USB_FIFOSZ_SIZE_4096);
		USB_DRV_WriteReg(USB_RXFIFOADD, (kal_uint16)(g_FIFOadd/8));
		g_FIFOadd += USB_ISO_FIFO_UNIT_SIZE;
#else
 		if(double_fifo == KAL_TRUE)
		{
			USB_DRV_WriteReg8(USB_RXFIFOSZ, (USB_FIFOSZ_SIZE_1024|USB_FIFOSZ_DPB));
			USB_DRV_WriteReg(USB_RXFIFOADD, (kal_uint16)(g_FIFOadd/8));
			g_FIFOadd += USB_ISO_FIFO_UNIT_SIZE*2;
		}
		else
		{
			USB_DRV_WriteReg8(USB_RXFIFOSZ, USB_FIFOSZ_SIZE_1024);
			USB_DRV_WriteReg(USB_RXFIFOADD, (kal_uint16)(g_FIFOadd/8));
			g_FIFOadd += USB_ISO_FIFO_UNIT_SIZE;
		}
#endif
	}
	else
	{
		ASSERT(0);
	}

	RestoreIRQMask(savedMask);

	if(g_FIFOadd > USB_MAX_FIFO_SIZE)
		ASSERT(0);

#elif defined(DRV_USB_IP_V2)

#elif defined(DRV_USB_IP_V1)
	USB_EP_Check(ep_num, USB_EP_RX_DIR, 0);

	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	USB_DRV_WriteReg8(USB_OUTCSR1, (USB_OUTCSR1_CLRDATATOG|USB_OUTCSR1_FLUSHFIFO));
	USB_DRV_WriteReg8(USB_OUTMAXP, (kal_uint8)(data_size/8));
	RestoreIRQMask(savedMask);
#elif defined(DRV_USB_IP_V1_PLUS)
	USB_EP_Check(ep_num, USB_EP_RX_DIR, 0);

	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	USB_DRV_WriteReg8(USB_OUTCSR1, (USB_OUTCSR1_CLRDATATOG|USB_OUTCSR1_FLUSHFIFO));
	USB_DRV_WriteReg8(USB_OUTMAXP, (kal_uint8)(data_size));
	RestoreIRQMask(savedMask);
#endif
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_TxEPEn(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_ENABLE_T *prep_enable;
	kal_uint32 savedMask;
	kal_uint32 ep_num;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	USB_ENDPT_TXFER_TYPE ep_type;
#endif
	USB_ENDPT_DMA_USAGE dma_usage_type;
	kal_bool is_flush;
//	kal_bool is_ft_mode;


	prep_enable = &data->rEP_Enable;
	ep_num = (kal_uint32)prep_enable->u4ep_num;
	dma_usage_type = (USB_ENDPT_DMA_USAGE)prep_enable->dma_usage_type;
	is_flush = (kal_bool)prep_enable->fgis_flush;
//	is_ft_mode = (kal_bool)prep_enable->fgis_ft_mode;


	USB_EP_Check(ep_num, USB_EP_TX_DIR, 0);
	USB_EP_DMA_Running_Check(ep_num, USB_EP_TX_DIR, 0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	ep_type = (USB_ENDPT_TXFER_TYPE)prep_enable->ep_type;
	savedMask = SaveAndSetIRQMask();

	USB_DRV_WriteReg8(USB_INDEX, ep_num);

	/* Double buffers, so we flush twice */
	if(is_flush == KAL_TRUE)
	{
		if((USB_DRV_Reg(USB_TXCSR)&USB_TXCSR_FIFONOTEMPTY) != 0)
			g_UsbDrvInfo.ep_tx_flush_intr[ep_num-1] = KAL_TRUE;

		USB_DRV_WriteReg(USB_TXCSR, 0x00);
		USB_DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
		USB_DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
	}


	if(dma_usage_type == USB_EP_USE_ONLY_DMA)
	{
		g_UsbDrvInfo.ep_tx_enb_state[ep_num-1] = USB_EP_STATE_DMA;
		USB_DRV_ClearBits(USB_INTRTXE, (USB_INTRE_EPEN<<ep_num));

		/* Only is configured as multiple packet DMA TX mode */
		if(ep_type == USB_ENDPT_ISO)
		{
			USB_DRV_WriteReg(USB_TXCSR, USB_DMA_TX_CSR_ISO);
		}
		else
		{
			USB_DRV_WriteReg(USB_TXCSR, USB_DMA_TX_CSR);
		}
	}
	else if((dma_usage_type == USB_EP_USE_NO_DMA)||(dma_usage_type == USB_EP_USE_DMA_ON_DEMAND))
	{
		/* EP default uses FIFO */
		g_UsbDrvInfo.ep_tx_enb_state[ep_num-1] = USB_EP_STATE_FIFO;
		if(ep_type == USB_ENDPT_ISO)
		{
			USB_DRV_WriteReg(USB_TXCSR, USB_TXCSR_ISO);
		}
		else
		{
			USB_DRV_WriteReg(USB_TXCSR, 0x00);
		}
		USB_DRV_SetBits(USB_INTRTXE, (USB_INTRE_EPEN<<ep_num));
	}

	RestoreIRQMask(savedMask);

#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))

	if(dma_usage_type == USB_EP_USE_ONLY_DMA)
	{
		g_UsbDrvInfo.ep_tx_enb_state[ep_num-1] = USB_EP_STATE_DMA;

		savedMask = SaveAndSetIRQMask();
		USB_DRV_ClearBits8(USB_INTRIN1E, (USB_INTRIN1E_EPEN<<ep_num));
		USB_DRV_WriteReg8(USB_INDEX, ep_num);

		if(is_flush == KAL_TRUE)
		{
			USB_DRV_WriteReg8(USB_INCSR1, (USB_INCSR1_CLRDATATOG|USB_INCSR1_FLUSHFIFO));
			USB_DRV_WriteReg8(USB_INCSR1, (USB_INCSR1_CLRDATATOG|USB_INCSR1_FLUSHFIFO));
		}

		// CR MAUI_00248052
		USB_DRV_WriteReg8(USB_INCSR2, 0);
		USB_DRV_WriteReg8(USB_INCSR2, (USB_INCSR2_AUTOSET|USB_INCSR2_DMAENAB));
		RestoreIRQMask(savedMask);
	}
	else if((dma_usage_type == USB_EP_USE_NO_DMA)||(dma_usage_type == USB_EP_USE_DMA_ON_DEMAND))
	{
		/* EP default uses FIFO */
		g_UsbDrvInfo.ep_tx_enb_state[ep_num-1] = USB_EP_STATE_FIFO;

		savedMask = SaveAndSetIRQMask();
		USB_DRV_WriteReg8(USB_INDEX, ep_num);

		if(is_flush == KAL_TRUE)
		{
			USB_DRV_WriteReg8(USB_INCSR1, (USB_INCSR1_CLRDATATOG | USB_INCSR1_FLUSHFIFO));
			USB_DRV_WriteReg8(USB_INCSR1, (USB_INCSR1_CLRDATATOG | USB_INCSR1_FLUSHFIFO));
		}

		USB_DRV_WriteReg8(USB_INCSR2, 0);
		USB_DRV_SetBits8(USB_INTRIN1E, USB_INTRIN1E_EPEN<<ep_num);
		RestoreIRQMask(savedMask);
	}

#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_TxEPDis(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_DISABLE_T *prep_disable;
	kal_uint32 savedMask;
	kal_uint32 ep_num;
//	USB_ENDPT_DMA_USAGE dma_usage_type;


	prep_disable = &data->rEP_Disable;
	ep_num = (kal_uint32)prep_disable->u4ep_num;
//	dma_usage_type = (USB_ENDPT_DMA_USAGE)prep_disable->dma_usage_type;


	USB_EP_Check(ep_num, USB_EP_TX_DIR, 0);
	USB_EP_DMA_Running_Check(ep_num, USB_EP_TX_DIR, 0);

	g_UsbDrvInfo.ep_tx_enb_state[ep_num-1] = USB_EP_STATE_DISABLE;

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	savedMask = SaveAndSetIRQMask();
	USB_DRV_ClearBits(USB_INTRTXE, (USB_INTRE_EPEN<<ep_num));
/*
	USB_DRV_WriteReg8(USB_INDEX, ep_num);

	if((USB_DRV_Reg(USB_TXCSR)&USB_TXCSR_FIFONOTEMPTY) != 0)
		g_UsbDrvInfo.ep_tx_flush_intr[ep_num-1] = KAL_TRUE;

	USB_DRV_WriteReg(USB_TXCSR, 0x00);
	USB_DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
	USB_DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
*/
	RestoreIRQMask(savedMask);

#elif defined(DRV_USB_IP_V2)

#elif defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)
	savedMask = SaveAndSetIRQMask();
	USB_DRV_ClearBits8(USB_INTRIN1E, (USB_INTRIN1E_EPEN<<ep_num));
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	USB_DRV_WriteReg8(USB_INCSR2, 0);
	RestoreIRQMask(savedMask);
#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_RxEPEn(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_ENABLE_T *prep_enable;
	kal_uint32 savedMask;
	kal_uint32 ep_num;
#if defined(DRV_USB_IP_V3) || defined(DRV_USB_IP_V2) || defined(DRV_USB_IP_V4)
	USB_ENDPT_TXFER_TYPE ep_type;
	kal_bool is_ft_mode;
#endif
	USB_ENDPT_DMA_USAGE dma_usage_type;
	kal_bool is_flush;



	prep_enable = &data->rEP_Enable;
	ep_num = (kal_uint32)prep_enable->u4ep_num;
	dma_usage_type = (USB_ENDPT_DMA_USAGE)prep_enable->dma_usage_type;
	is_flush = (kal_bool)prep_enable->fgis_flush;


	USB_EP_Check(ep_num, USB_EP_RX_DIR, 0);
	USB_EP_DMA_Running_Check(ep_num, USB_EP_RX_DIR, 0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	ep_type = (USB_ENDPT_TXFER_TYPE)prep_enable->ep_type;	
	is_ft_mode = (kal_bool)prep_enable->fgis_ft_mode;

	savedMask = SaveAndSetIRQMask();

	if(dma_usage_type == USB_EP_USE_ONLY_DMA)
	{
		g_UsbDrvInfo.ep_rx_enb_state[ep_num-1] = USB_EP_STATE_DMA;
		USB_DRV_ClearBits(USB_INTRRXE, (USB_INTRE_EPEN<<ep_num));

/*
		if(ep_type == USB_ENDPT_ISO)
		{
//			USB_DRV_WriteReg(USB_RXCSR, USB_DMA_RX_CSR_ISO|USB_RXCSR_AUTOCLREN_SPKT);
			USB_DRV_WriteReg(USB_RXCSR, USB_DMA_RX_CSR_ISO);
		}
		else
		{
//			USB_DRV_WriteReg(USB_RXCSR, USB_DMA_RX_CSR|USB_RXCSR_AUTOCLREN_SPKT);
			USB_DRV_WriteReg(USB_RXCSR, USB_DMA_RX_CSR);
		}
*/
	}
	else if((dma_usage_type == USB_EP_USE_NO_DMA)||(dma_usage_type == USB_EP_USE_DMA_ON_DEMAND))
	{
		/* EP default uses FIFO */
		g_UsbDrvInfo.ep_rx_enb_state[ep_num-1] = USB_EP_STATE_FIFO;
		USB_DRV_SetBits(USB_INTRRXE, (USB_INTRE_EPEN<<ep_num));
	}

	RestoreIRQMask(savedMask);

	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);

	/* Maybe double buffer, so flush twice */
	if(is_flush == KAL_TRUE)
	{
//		if((USB_DRV_Reg(USB_RXCSR)&USB_RXCSR_RXPKTRDY) != 0)
//			g_UsbDrvInfo.ep_rx_flush_intr[ep_num-1] = KAL_TRUE;

		USB_DRV_WriteReg(USB_RXCSR, USB_RXCSR_RXPKTRDY);
		USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG|USB_RXCSR_RXPKTRDY));
		USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG|USB_RXCSR_RXPKTRDY));
	}

	if(ep_type == USB_ENDPT_ISO)
	{
		USB_DRV_WriteReg(USB_RXCSR, USB_RXCSR_ISO);
	}
	else if (is_ft_mode != KAL_TRUE)
	{
		USB_DRV_WriteReg(USB_RXCSR, 0x00);
	}

	RestoreIRQMask(savedMask);

#elif defined(DRV_USB_IP_V2)
	is_ft_mode = (kal_bool)prep_enable->fgis_ft_mode;

	if(is_flush == KAL_TRUE)
	{
		/* The first expect received packet is data0 */
		g_UsbDrvInfo.ep_rx_data01[ep_num-1] = 0;
	}
	else
	{
		if(is_ft_mode == KAL_TRUE)
		{
			g_UsbDrvInfo.ep_rx_max_data_size[ep_num-1] = USBDL_EP_BULK_MAXP;
			g_UsbDrvInfo.ep_rx_data01[ep_num-1] = (READ_EPN_BDT_PID(ep_num, USB_BDT_RX)& 0x00000040)>>VUSB_BDT_DATA01_SHIFT;
			g_UsbDrvInfo.ep_rx_data01[ep_num-1] ^= 1;
			USB_Dbg_Trace(USB_EP_META_INIT, ep_num, 1);
			USB_Dbg_Trace(USB_EP_META_INIT, g_UsbDrvInfo.ep_rx_max_data_size[ep_num-1], g_UsbDrvInfo.ep_rx_data01[ep_num-1]);
		}
		else
		{
			/* Restore data token */
			g_UsbDrvInfo.ep_rx_data01[ep_num-1] ^= 1;
		}
	}

	if(dma_usage_type == USB_EP_USE_ONLY_DMA)
	{
		g_UsbDrvInfo.ep_rx_enb_state[ep_num-1] = USB_EP_STATE_DMA;
	}
	else if((dma_usage_type == USB_EP_USE_NO_DMA)||(dma_usage_type == USB_EP_USE_DMA_ON_DEMAND))
	{
		/* EP default uses FIFO */
		g_UsbDrvInfo.ep_rx_enb_state[ep_num-1] = USB_EP_STATE_FIFO;

		if(is_ft_mode == KAL_FALSE)
		{
			// configure BDT to receive data
			WRITE_EPN_BDT_PID(ep_num, USB_BDT_RX,
				((g_UsbDrvInfo.ep_rx_max_data_size[ep_num-1] << VUSB_BDT_BC_SHIFT)|
				(g_UsbDrvInfo.ep_rx_data01[ep_num-1]<<VUSB_BDT_DATA01_SHIFT)|
				VUSB_BDT_DTS_BIT|VUSB_BDT_OWNS_BIT));

			g_UsbDrvInfo.ep_rx_data01[ep_num-1] ^= 1;
		}
	}

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))

	if(dma_usage_type == USB_EP_USE_ONLY_DMA)
	{
		g_UsbDrvInfo.ep_rx_enb_state[ep_num-1] = USB_EP_STATE_DMA;

		savedMask = SaveAndSetIRQMask();
		USB_DRV_ClearBits8(USB_INTROUT1E, (USB_INTROUT1E_EPEN<<ep_num));
		USB_DRV_WriteReg8(USB_INDEX, ep_num);

		if(is_flush == KAL_TRUE)
		{
			USB_DRV_WriteReg8(USB_OUTCSR1, (USB_OUTCSR1_CLRDATATOG|USB_OUTCSR1_FLUSHFIFO));
			USB_DRV_WriteReg8(USB_OUTCSR1, (USB_OUTCSR1_CLRDATATOG|USB_OUTCSR1_FLUSHFIFO));
		}

		// CR MAUI_00248052
		USB_DRV_WriteReg8(USB_OUTCSR2, 0);
		USB_DRV_WriteReg8(USB_OUTCSR2, (USB_OUTCSR2_AUTOCLEAR|USB_OUTCSR2_DMAENAB));
		RestoreIRQMask(savedMask);
	}
	else if((dma_usage_type == USB_EP_USE_NO_DMA)||(dma_usage_type == USB_EP_USE_DMA_ON_DEMAND))
	{
		/* EP default uses FIFO */
		g_UsbDrvInfo.ep_rx_enb_state[ep_num-1] = USB_EP_STATE_FIFO;

		savedMask = SaveAndSetIRQMask();
		USB_DRV_WriteReg8(USB_INDEX, ep_num);

		if(is_flush == KAL_TRUE)
		{
			USB_DRV_WriteReg8(USB_OUTCSR1, (USB_OUTCSR1_CLRDATATOG|USB_OUTCSR1_FLUSHFIFO));
			USB_DRV_WriteReg8(USB_OUTCSR1, (USB_OUTCSR1_CLRDATATOG|USB_OUTCSR1_FLUSHFIFO));
		}

		USB_DRV_WriteReg8(USB_OUTCSR2, 0);
		USB_DRV_SetBits8(USB_INTROUT1E, (USB_INTROUT1E_EPEN<<ep_num));
		RestoreIRQMask(savedMask);
	}
#endif


	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_RxEPDis(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_DISABLE_T *prep_disable;
	kal_uint32 savedMask;
	kal_uint32 ep_num;
//	USB_ENDPT_DMA_USAGE dma_usage_type;


	prep_disable = &data->rEP_Disable;
	ep_num = (kal_uint32)prep_disable->u4ep_num;
//	dma_usage_type = (USB_ENDPT_DMA_USAGE)prep_disable->dma_usage_type;


	USB_EP_Check(ep_num, USB_EP_RX_DIR, 0);
	USB_EP_DMA_Running_Check(ep_num, USB_EP_RX_DIR, 0);

	g_UsbDrvInfo.ep_rx_enb_state[ep_num-1] = USB_EP_STATE_DISABLE;

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)

	savedMask = SaveAndSetIRQMask();
	USB_DRV_ClearBits(USB_INTRRXE, (USB_INTRE_EPEN<<ep_num));
/*
	USB_DRV_WriteReg8(USB_INDEX, ep_num);

	if((USB_DRV_Reg(USB_RXCSR)&USB_RXCSR_RXPKTRDY) != 0)
		g_UsbDrvInfo.ep_rx_flush_intr[ep_num-1] = KAL_TRUE;

	USB_DRV_WriteReg(USB_RXCSR, USB_RXCSR_RXPKTRDY);
	USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG|USB_RXCSR_RXPKTRDY));
	USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG|USB_RXCSR_RXPKTRDY));
*/
	RestoreIRQMask(savedMask);

#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	savedMask = SaveAndSetIRQMask();
	USB_DRV_ClearBits8(USB_INTROUT1E, (USB_INTROUT1E_EPEN << ep_num));
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	USB_DRV_WriteReg8(USB_OUTCSR2, 0);
	RestoreIRQMask(savedMask);
#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Config_TxEP_Type(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_CONFIG_TYPE_T *prep_config_type;
	kal_uint32 savedMask;
	kal_uint32 ep_num;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	USB_ENDPT_TXFER_TYPE ep_type;
#endif
	kal_bool b_is_switch_to_dma;



	prep_config_type = &data->rEP_Config_Type;
	ep_num = (kal_uint32)prep_config_type->u4ep_num;
	b_is_switch_to_dma = (kal_bool)prep_config_type->fg_is_switch_to_dma;


	USB_EP_Check(ep_num, USB_EP_TX_DIR, 0);
	USB_EP_DMA_Running_Check(ep_num, USB_EP_TX_DIR, 0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	ep_type = (USB_ENDPT_TXFER_TYPE)prep_config_type->ep_type;

	if(b_is_switch_to_dma == KAL_TRUE)
	{
		if(g_UsbDrvInfo.ep_tx_enb_state[ep_num-1] == USB_EP_STATE_DMA)
			ASSERT(0);
		g_UsbDrvInfo.ep_tx_enb_state[ep_num-1] = USB_EP_STATE_DMA;

		savedMask = SaveAndSetIRQMask();
		USB_DRV_ClearBits(USB_INTRTXE, (USB_INTRE_EPEN<<ep_num));
		USB_DRV_WriteReg8(USB_INDEX, ep_num);

		if(USB_DRV_Reg(USB_TXCSR)&USB_TXCSR_FIFONOTEMPTY)
			ASSERT(0);

		if(ep_type == USB_ENDPT_ISO)
		{
			USB_DRV_WriteReg(USB_TXCSR, USB_TXCSR_ISO);
		}
		else
		{
			USB_DRV_WriteReg(USB_TXCSR, 0x00);
		}

		/* Only is configured as multiple packet DMA TX mode */
/*
		if(ep_type == USB_ENDPT_ISO)
		{
			USB_DRV_WriteReg(USB_TXCSR, USB_DMA_TX_CSR_ISO);
		}
		else
		{
			USB_DRV_WriteReg(USB_TXCSR, USB_DMA_TX_CSR);
		}
*/
		RestoreIRQMask(savedMask);
	}
	else
	{
		if(g_UsbDrvInfo.ep_tx_enb_state[ep_num-1] == USB_EP_STATE_FIFO)
			ASSERT(0);

		g_UsbDrvInfo.ep_tx_enb_state[ep_num-1] = USB_EP_STATE_FIFO;

		savedMask = SaveAndSetIRQMask();
		USB_DRV_WriteReg8(USB_INDEX, ep_num);

		/* From DMA to FIFO, it may be not empty because this is DMA callback */
//		if(USB_DRV_Reg(USB_TXCSR)&USB_TXCSR_FIFONOTEMPTY)
//			ASSERT(0);

		/* When change ep state from DMA to FIFO, must make sure that FIFO is empty */
		if(USB_DRV_Reg(USB_TXCSR)&USB_TXCSR_TXPKTRDY)
			ASSERT(0);

		if(ep_type == USB_ENDPT_ISO)
		{
			USB_DRV_WriteReg(USB_TXCSR, USB_TXCSR_ISO);
		}
		else
		{
			USB_DRV_WriteReg(USB_TXCSR, 0x00);
		}

		USB_DRV_SetBits(USB_INTRTXE, (USB_INTRE_EPEN<<ep_num));
		RestoreIRQMask(savedMask);
	}

#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))

	if(b_is_switch_to_dma == KAL_TRUE)
	{
		if(g_UsbDrvInfo.ep_tx_enb_state[ep_num-1] == USB_EP_STATE_DMA)
			ASSERT(0);
		g_UsbDrvInfo.ep_tx_enb_state[ep_num-1] = USB_EP_STATE_DMA;

		savedMask = SaveAndSetIRQMask();
		USB_DRV_ClearBits8(USB_INTRIN1E, (USB_INTRIN1E_EPEN << ep_num));
		USB_DRV_WriteReg8(USB_INDEX, ep_num);
		// CR MAUI_00248052
		USB_DRV_WriteReg8(USB_INCSR2, 0);
		USB_DRV_WriteReg8(USB_INCSR2, (USB_INCSR2_AUTOSET|USB_INCSR2_DMAENAB));
		RestoreIRQMask(savedMask);
	}
	else
	{
		if(g_UsbDrvInfo.ep_tx_enb_state[ep_num-1] == USB_EP_STATE_FIFO)
			ASSERT(0);
		g_UsbDrvInfo.ep_tx_enb_state[ep_num-1] = USB_EP_STATE_FIFO;

		savedMask = SaveAndSetIRQMask();
		USB_DRV_WriteReg8(USB_INDEX, ep_num);

		/* When change ep state from DMA to FIFO, must make sure that FIFO is empty */
		if(USB_DRV_Reg8(USB_INCSR1)&USB_INCSR1_INPKTRDY)
			ASSERT(0);

		USB_DRV_WriteReg8(USB_INCSR2, 0);
		USB_DRV_SetBits8(USB_INTRIN1E, (USB_INTRIN1E_EPEN << ep_num));
		RestoreIRQMask(savedMask);
	}

#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Config_RxEP_Type(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_CONFIG_TYPE_T *prep_config_type;
	kal_uint32 savedMask;
	kal_uint32 ep_num;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	USB_ENDPT_TXFER_TYPE ep_type;
#endif
	kal_bool b_is_switch_to_dma;



	prep_config_type = &data->rEP_Config_Type;
	ep_num = (kal_uint32)prep_config_type->u4ep_num;
	b_is_switch_to_dma = (kal_bool)prep_config_type->fg_is_switch_to_dma;


	USB_EP_Check(ep_num, USB_EP_RX_DIR, 0);
	USB_EP_DMA_Running_Check(ep_num, USB_EP_RX_DIR, 0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	ep_type = (USB_ENDPT_TXFER_TYPE)prep_config_type->ep_type;

	if(b_is_switch_to_dma == KAL_TRUE)
	{
		if(g_UsbDrvInfo.ep_rx_enb_state[ep_num-1] == USB_EP_STATE_DMA)
			ASSERT(0);

		g_UsbDrvInfo.ep_rx_enb_state[ep_num-1] = USB_EP_STATE_DMA;

		savedMask = SaveAndSetIRQMask();
		USB_DRV_ClearBits(USB_INTRRXE, (USB_INTRE_EPEN<<ep_num));
		USB_DRV_WriteReg8(USB_INDEX, ep_num);

		/* Must set related DMA bits, otherwise, packets arrive will result in RX ep intr */
		if(ep_type == USB_ENDPT_ISO)
		{
			USB_DRV_WriteReg(USB_RXCSR, USB_DMA_RX_CSR_ISO|USB_RXCSR_RXPKTRDY);
		}
		else
		{
			USB_DRV_WriteReg(USB_RXCSR, USB_DMA_RX_CSR|USB_RXCSR_RXPKTRDY);
		}

		RestoreIRQMask(savedMask);
	}
	else
	{
		if(g_UsbDrvInfo.ep_rx_enb_state[ep_num-1] == USB_EP_STATE_FIFO)
			ASSERT(0);

		g_UsbDrvInfo.ep_rx_enb_state[ep_num-1] = USB_EP_STATE_FIFO;

		savedMask = SaveAndSetIRQMask();
		USB_DRV_WriteReg8(USB_INDEX, ep_num);

		/* When we change ep state from DMA to FIFO, must make sure that FIFO is empty */
		/* But there may be a null packet coming here in DMA callback */
		if(USB_DRV_Reg(USB_RXCSR)&USB_RXCSR_RXPKTRDY)
		{
			if(USB_DRV_Reg(USB_RXCOUNT) == 0)
			{
				USB_DRV_ClearBits(USB_RXCSR, USB_RXCSR_RXPKTRDY);
			}
			else
			{
				ASSERT(0);
			}
		}

		if(ep_type == USB_ENDPT_ISO)
		{
			//USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_ISO|USB_RXCSR_RXPKTRDY));
			/*It may clear STALL status, need to prevent it.*/
			USB_DRV_WriteReg(USB_RXCSR, USB_DRV_Reg(USB_RXCSR)&(USB_RXCSR_ISO|USB_RXCSR_RXPKTRDY|USB_RXCSR_SENDSTALL|USB_RXCSR_SENTSTALL));
		}
		else
		{
			//USB_DRV_WriteReg(USB_RXCSR, USB_RXCSR_RXPKTRDY);
			/*It may clear STALL status, need to prevent it.*/
			USB_DRV_WriteReg(USB_RXCSR, USB_DRV_Reg(USB_RXCSR)&(USB_RXCSR_RXPKTRDY|USB_RXCSR_SENDSTALL|USB_RXCSR_SENTSTALL));
		}

		USB_DRV_SetBits(USB_INTRRXE, (USB_INTRE_EPEN<<ep_num));
		RestoreIRQMask(savedMask);
	}

#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))

	if(b_is_switch_to_dma == KAL_TRUE)
	{
		if(g_UsbDrvInfo.ep_rx_enb_state[ep_num-1] == USB_EP_STATE_DMA)
			ASSERT(0);

		g_UsbDrvInfo.ep_rx_enb_state[ep_num-1] = USB_EP_STATE_DMA;

		savedMask = SaveAndSetIRQMask();
		USB_DRV_ClearBits8(USB_INTROUT1E, (USB_INTROUT1E_EPEN<<ep_num));
		USB_DRV_WriteReg8(USB_INDEX, ep_num);
		// CR MAUI_00248052
		USB_DRV_WriteReg8(USB_OUTCSR2, 0);
		USB_DRV_WriteReg8(USB_OUTCSR2, (USB_OUTCSR2_AUTOCLEAR|USB_OUTCSR2_DMAENAB));
		RestoreIRQMask(savedMask);
	}
	else
	{
		if(g_UsbDrvInfo.ep_rx_enb_state[ep_num-1] == USB_EP_STATE_FIFO)
			ASSERT(0);

		g_UsbDrvInfo.ep_rx_enb_state[ep_num-1] = USB_EP_STATE_FIFO;

		savedMask = SaveAndSetIRQMask();
		USB_DRV_WriteReg8(USB_INDEX, ep_num);

		/* When change ep state from DMA to FIFO, must make sure that FIFO is empty */
		if(USB_DRV_Reg8(USB_OUTCSR1)&USB_OUTCSR1_OUTPKTRDY)
		{
			if(USB_DRV_Reg8(USB_OUTCOUNT1) == 0)
			{
				USB_DRV_ClearBits8(USB_OUTCSR1, USB_OUTCSR1_OUTPKTRDY);
			}
			else
				ASSERT(0);
		}

		USB_DRV_WriteReg8(USB_OUTCSR2, 0x00);
		USB_DRV_SetBits8(USB_INTROUT1E, (USB_INTROUT1E_EPEN<<ep_num));
		RestoreIRQMask(savedMask);
	}

#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_TxEPClearDataTog(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_COMMON_FUNC_T *dcl_data_ptr;
	kal_uint32 savedMask;
	kal_uint32 ep_num;
//	USB_ENDPT_TXFER_TYPE ep_type;


	dcl_data_ptr = &data->rUSB_Common_Struct;
	ep_num = (kal_uint32)dcl_data_ptr->u4ep_num;
//	ep_type = (USB_ENDPT_TXFER_TYPE)dcl_data_ptr->type;


	USB_EP_Check(ep_num, USB_EP_TX_DIR, 0);
	USB_EP_DMA_Running_Check(ep_num, USB_EP_TX_DIR, 0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	USB_DRV_SetBits(USB_TXCSR, USB_TXCSR_CLRDATATOG);
	RestoreIRQMask(savedMask);
#elif defined(DRV_USB_IP_V2)
	g_UsbDrvInfo.ep_tx_data01[ep_num-1] = 0;
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	USB_DRV_SetBits8(USB_INCSR1, USB_INCSR1_CLRDATATOG);
	RestoreIRQMask(savedMask);
#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_RxEPClearDataTog(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_COMMON_FUNC_T *dcl_data_ptr;
	kal_uint32 savedMask;
	kal_uint32 ep_num;
//	USB_ENDPT_TXFER_TYPE ep_type;


	dcl_data_ptr = &data->rUSB_Common_Struct;
	ep_num = (kal_uint32)dcl_data_ptr->u4ep_num;
//	ep_type = (USB_ENDPT_TXFER_TYPE)dcl_data_ptr->type;

	USB_EP_Check(ep_num, USB_EP_RX_DIR, 0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	USB_DRV_SetBits(USB_RXCSR, USB_RXCSR_CLRDATATOG);
	RestoreIRQMask(savedMask);
#elif defined(DRV_USB_IP_V2)
	g_UsbDrvInfo.ep_rx_data01[ep_num-1] = 0;
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	USB_DRV_SetBits8(USB_OUTCSR1, USB_OUTCSR1_CLRDATATOG);
	RestoreIRQMask(savedMask);
#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_TxEP_Usage(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_STATE_T *prep_ep_state;
	kal_uint32 ep_num;


	prep_ep_state = &data->rEP_Get_State;
	ep_num = (kal_uint32)prep_ep_state->u4ep_num;

	USB_EP_Check(ep_num, USB_EP_TX_DIR, 0);
	prep_ep_state->result = (DCL_USB_EP_STATE)g_UsbDrvInfo.ep_tx_enb_state[ep_num-1];
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_RxEP_Usage(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_STATE_T *prep_ep_state;
	kal_uint32 ep_num;


	prep_ep_state = &data->rEP_Get_State;
	ep_num = (kal_uint32)prep_ep_state->u4ep_num;


	USB_EP_Check(ep_num, USB_EP_RX_DIR, 0);
	prep_ep_state->result = (DCL_USB_EP_STATE)g_UsbDrvInfo.ep_rx_enb_state[ep_num-1];
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_TXEP_PK_SIZE(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_3_T *prep_ctrl_func_3;
	kal_uint32 ep_num;
	kal_uint32 savedMask;
	kal_uint32 register_value;


	prep_ctrl_func_3 = &data->rEP_Ctrl_Func_3;
	ep_num = (kal_uint32)prep_ctrl_func_3->u4ep_num;

	savedMask = SaveAndSetIRQMask();

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	register_value = USB_DRV_Reg(USB_TXMAXP);
#elif defined(DRV_USB_IP_V2)
	register_value = USB_EP_BULK_MAXP; //fix Packet Size on ARC IP
#elif defined(DRV_USB_IP_V1)
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	register_value = USB_DRV_Reg8(USB_INMAXP)*8;
#elif defined(DRV_USB_IP_V1_PLUS)
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	register_value = USB_DRV_Reg8(USB_INMAXP);
#endif

	RestoreIRQMask(savedMask);
	prep_ctrl_func_3->u4result = (DCL_UINT32)register_value;
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_RXEP_PK_SIZE(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_3_T *prep_ctrl_func_3;
	kal_uint32 ep_num;
	kal_uint32 savedMask;
	kal_uint32 register_value;


	prep_ctrl_func_3 = &data->rEP_Ctrl_Func_3;
	ep_num = (kal_uint32)prep_ctrl_func_3->u4ep_num;

	savedMask = SaveAndSetIRQMask();

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	register_value = USB_DRV_Reg(USB_RXMAXP); //max 512 = 0x200
#elif defined(DRV_USB_IP_V2)
	register_value = USB_EP_BULK_MAXP; //fix Packet Size on ARC IP
#elif defined(DRV_USB_IP_V1)
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	register_value = USB_DRV_Reg8(USB_OUTMAXP)*8;	//max 64 = 0x40
#elif defined(DRV_USB_IP_V1_PLUS)
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	register_value = USB_DRV_Reg8(USB_OUTMAXP);		//max 64 = 0x40
#endif

	RestoreIRQMask(savedMask);
	prep_ctrl_func_3->u4result = (DCL_UINT32)register_value;
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_EPFIFORead(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_FIFO_RW_T	*prep_fifo_rw;
	kal_uint32 ep_num;
	kal_uint16 nBytes;
	void *pDst;
#if defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)||defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint16  nCount;
	kal_uint8   *pby;
	kal_uint32  nAddr;
	
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_bool force_one_byte_access;
	kal_uint32  temp_1, temp_2;
	kal_uint32 *pby1;
#endif
#endif

	prep_fifo_rw = &data->rEP_Fifo_Rw;

	ep_num = (kal_uint32)prep_fifo_rw->u4ep_num;
	nBytes = (kal_uint16)prep_fifo_rw->u2nBytes;
	pDst = (void *)prep_fifo_rw->paddr;

	nCount = nBytes;


	if((nBytes != 0)&&(pDst == NULL))
		EXT_ASSERT(0, (kal_uint32)nBytes, 0, 0);

	if (pDst == NULL)
		return STATUS_FAIL;

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	force_one_byte_access = (kal_bool)prep_fifo_rw->fg_force_one_byte_access;
	/* not indexed register */
//	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	nAddr = USB_EP0 + ep_num*4;

	if((((kal_uint32)pDst%4) == 0)&&(force_one_byte_access == KAL_FALSE))
	{
		/* Destination address is 4 byte alignment */

		temp_1 = nCount/4;
		temp_2 = nCount%4;

		pby1 = (kal_uint32 *)pDst;

		while(temp_1)
		{
			*pby1++ = USB_DRV_Reg32(nAddr);	//lint !e613
			temp_1--;
		}

		pby = (kal_uint8 *)pby1;

		while(temp_2)
		{
			*pby++ = USB_DRV_Reg8(nAddr);	//lint !e613
			temp_2--;
		}
	}
	else
	{
		pby = (kal_uint8 *)pDst;

		/* Read byte by byte */
		while(nCount)
		{
			*pby++ = USB_DRV_Reg8(nAddr);	//lint !e613
			nCount--;
		}
	}

#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	nAddr = USB_EP0 + ep_num*4;
	pby = (kal_uint8 *)pDst;

	/* read byte by byte */
	while (nCount)
	{
		*pby++ = USB_DRV_Reg8(nAddr);
		nCount--;
	}
#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_EPFIFOWrite(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_FIFO_RW_T	*prep_fifo_rw;
	kal_uint32 ep_num;
	kal_uint16 nBytes;
	void *pSrc;


	prep_fifo_rw = &data->rEP_Fifo_Rw;
	ep_num = (kal_uint32)prep_fifo_rw->u4ep_num;
	nBytes = (kal_uint16)prep_fifo_rw->u2nBytes;
	pSrc = (void *)prep_fifo_rw->paddr;


	USB_HW_EPFIFOWrite(ep_num, nBytes, pSrc);
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_CtrlEPStall(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_STALL_T *prctrl_ep_stall;
	kal_uint32 ep_num;
	USB_EP_DIRECTION direction;
	kal_bool stall_enable;
	kal_uint32 savedMask;
#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	kal_uint8 CSR1;
#endif


	prctrl_ep_stall = &data->rEP_Stall;

	ep_num = (kal_uint32)prctrl_ep_stall->u4ep_num;
	direction = (USB_EP_DIRECTION)prctrl_ep_stall->direction;
	stall_enable = (kal_bool)prctrl_ep_stall->fgen;


	USB_EP_Check(ep_num, direction, 0);
	USB_EP_DMA_Running_Check(ep_num, direction, 0);

	USB_Dbg_Trace(USB_EPN_CTRL_STALL, (kal_uint32)ep_num, (kal_uint32)direction);
	USB_Dbg_Trace(USB_EPN_CTRL_STALL, (kal_uint32)stall_enable, 0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)

	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);

	/* Stall endpoint */
	if(direction == USB_EP_RX_DIR)
	{
		/* For webcam case, when PC send clear featuere, we must reset toggle */
//		if((USB_DRV_Reg(USB_RXCSR)&USB_RXCSR_RXPKTRDY) != 0)
//			g_UsbDrvInfo.ep_rx_flush_intr[ep_num-1] = KAL_TRUE;

		USB_DRV_WriteReg(USB_RXCSR, USB_RXCSR_RXPKTRDY);
		USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG|USB_RXCSR_RXPKTRDY));
		USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG|USB_RXCSR_RXPKTRDY));
		g_UsbDrvInfo.ep_rx_stall_status[ep_num-1] = stall_enable;

		if(stall_enable == KAL_TRUE)
		{
			USB_DRV_WriteReg(USB_RXCSR, USB_RXCSR_SENDSTALL);
		}
	}
	else
	{
		/* For webcam case, when PC send clear featuere, we must reset toggle */
		if((USB_DRV_Reg(USB_TXCSR)&USB_TXCSR_FIFONOTEMPTY) != 0)
			g_UsbDrvInfo.ep_tx_flush_intr[ep_num-1] = KAL_TRUE;

		USB_DRV_WriteReg(USB_TXCSR, 0x00);
		USB_DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
		USB_DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
		g_UsbDrvInfo.ep_tx_stall_status[ep_num-1] = stall_enable;

		if(stall_enable == KAL_TRUE)
		{
			USB_DRV_WriteReg(USB_TXCSR, USB_TXCSR_SENDSTALL);
		}
	}

	RestoreIRQMask(savedMask);

#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))

	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);

	if(stall_enable == KAL_TRUE)
	{
		/* Stall endpoint */
		if (direction == USB_EP_RX_DIR)
		{
			USB_DRV_SetBits8(USB_OUTCSR1, (USB_OUTCSR1_SENDSTALL|USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG));
			USB_DRV_SetBits8(USB_OUTCSR1, (USB_OUTCSR1_SENDSTALL|USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG));
			g_UsbDrvInfo.ep_rx_stall_status[ep_num-1] = KAL_TRUE;
		}
		else
		{
			USB_DRV_SetBits8(USB_INCSR1, (USB_INCSR1_SENDSTALL|USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG));
			USB_DRV_SetBits8(USB_INCSR1, (USB_INCSR1_SENDSTALL|USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG));
			g_UsbDrvInfo.ep_tx_stall_status[ep_num-1] = KAL_TRUE;
		}
	}
	else
	{
		/* Clear stall */
		if (direction == USB_EP_RX_DIR)
		{
			CSR1 = USB_DRV_Reg8(USB_OUTCSR1);
			CSR1 &= ~USB_OUTCSR1_SENDSTALL;
			USB_DRV_WriteReg8(USB_OUTCSR1, (CSR1|USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG));
			USB_DRV_WriteReg8(USB_OUTCSR1, (CSR1|USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG));
			g_UsbDrvInfo.ep_rx_stall_status[ep_num-1] = KAL_FALSE;
		}
		else
		{
			CSR1 = USB_DRV_Reg8(USB_INCSR1);
			CSR1 &= ~USB_INCSR1_SENDSTALL;
			USB_DRV_WriteReg8(USB_INCSR1, (CSR1|USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG));
			USB_DRV_WriteReg8(USB_INCSR1, (CSR1|USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG));
			g_UsbDrvInfo.ep_tx_stall_status[ep_num-1] = KAL_FALSE;
		}
	}

	RestoreIRQMask(savedMask);

#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Get_EP0_Status(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_GET_EP_STATUS_T *prget_ep_status;
	kal_bool p_transaction_end;
	kal_bool p_sent_stall;
	kal_uint32 savedMask;
	kal_uint16  CSR0;

	prget_ep_status = &data->rEP_Status;

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, 0);
	CSR0 = USB_DRV_Reg(USB_CSR0);
	RestoreIRQMask(savedMask);

	if (CSR0 & USB_CSR0_SENTSTALL)
		p_sent_stall = KAL_TRUE;
	else
		p_sent_stall = KAL_FALSE;

	if (CSR0 & USB_CSR0_SETUPEND)
		p_transaction_end = KAL_TRUE;
	else
		p_transaction_end = KAL_FALSE;
#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, 0);
	CSR0 = USB_DRV_Reg8(USB_CSR0);
	RestoreIRQMask(savedMask);

	if(CSR0 & USB_CSR0_SENTSTALL)
		p_sent_stall = KAL_TRUE;
	else
		p_sent_stall = KAL_FALSE;

	if(CSR0 & USB_CSR0_SETUPEND)
		p_transaction_end = KAL_TRUE;
	else
		p_transaction_end = KAL_FALSE;
#endif


	prget_ep_status->fg_transaction_end = (DCL_BOOL)p_transaction_end;
	prget_ep_status->fg_sent_stall = (DCL_BOOL)p_sent_stall;
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Update_EP0_State(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_UPDATE_EPSTATE_T *prupdate_epstate;
	kal_uint32 savedMask;
	USB_EP0_DRV_STATE state;
	kal_bool stall;
	kal_bool end;
	kal_uint8   reg_state;


	prupdate_epstate = &data->rEP_State;
	state = (USB_EP0_DRV_STATE)prupdate_epstate->state;
	stall = (kal_bool)prupdate_epstate->fgstall;
	end = (kal_bool)prupdate_epstate->fgend;

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	/* Clear sent stall */
	if(state == USB_EP0_DRV_STATE_CLEAR_SENT_STALL)
	{
		savedMask = SaveAndSetIRQMask();
		USB_DRV_WriteReg8(USB_INDEX, 0);
		USB_DRV_ClearBits(USB_CSR0, USB_CSR0_SENTSTALL);
		RestoreIRQMask(savedMask);
		return STATUS_OK;
	}

	/* clear transaction end*/
	if(state == USB_EP0_DRV_STATE_TRANSACTION_END)
	{
		savedMask = SaveAndSetIRQMask();
		USB_DRV_WriteReg8(USB_INDEX, 0);
		USB_DRV_WriteReg(USB_CSR0, USB_CSR0_SERVICEDSETUPEND);
		RestoreIRQMask(savedMask);
		return STATUS_OK;
	}

	/* ep0 read end or write ready*/
	if(state == USB_EP0_DRV_STATE_READ_END)
	{
		reg_state = USB_CSR0_SERVICEDRXPKTRDY;
	}
	else
	{
		reg_state = USB_CSR0_TXPKTRDY;
	}

	/* error occured, sent stall*/
	if(stall == KAL_TRUE)
	{
		reg_state |= USB_CSR0_SENDSTALL;
	}

	/* last data for this transaction, set data end bit*/
	if(end == KAL_TRUE)
	{
		reg_state |= USB_CSR0_DATAEND;
	}

	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, 0);
	USB_DRV_WriteReg(USB_CSR0, reg_state);
	RestoreIRQMask(savedMask);

#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	/* Clear sent stall */
	if(state == USB_EP0_DRV_STATE_CLEAR_SENT_STALL)
	{
		savedMask = SaveAndSetIRQMask();
		USB_DRV_WriteReg8(USB_INDEX, 0);
		USB_DRV_ClearBits8(USB_CSR0, USB_CSR0_SENTSTALL);
		RestoreIRQMask(savedMask);
		return STATUS_OK;
	}

	/* Clear transaction end*/
	if(state == USB_EP0_DRV_STATE_TRANSACTION_END)
	{
		savedMask = SaveAndSetIRQMask();
		USB_DRV_WriteReg8(USB_INDEX, 0);
		USB_DRV_WriteReg8(USB_CSR0, USB_CSR0_SERVICESETUPEND);
		RestoreIRQMask(savedMask);
		return STATUS_OK;
	}

	/* Ep0 read end or write ready */
	if(state == USB_EP0_DRV_STATE_READ_END)
	{
		reg_state = USB_CSR0_SERVICEDOUTPKTRDY;
	}
	else
	{
		reg_state = USB_CSR0_INPKTRDY;
	}

	/* Error occured, sent stall*/
	if(stall == KAL_TRUE)
	{
		reg_state |= USB_CSR0_SENDSTALL;
	}
	/* last data for this transaction, set data end bit*/
	if(end == KAL_TRUE)
	{
		reg_state |= USB_CSR0_DATAEND;
	}

	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, 0);
	USB_DRV_WriteReg8(USB_CSR0, reg_state);
	RestoreIRQMask(savedMask);
#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_EP0_Pkt_Len(DCL_CTRL_DATA_T *data)
{
	DCL_UINT32 *dcl_data_ptr = (DCL_UINT32*)data;
	kal_uint32 savedMask;
	kal_uint32 nCount = 0;
	kal_uint16  CSR0;


#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, 0);
	CSR0 = USB_DRV_Reg(USB_CSR0);

	if(CSR0&USB_CSR0_RXPKTRDY)
	{
		nCount = (kal_uint32)USB_DRV_Reg8(USB_COUNT0);
	}
	RestoreIRQMask(savedMask);

#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, 0);
	CSR0 = USB_DRV_Reg8(USB_CSR0);

	if(CSR0 & USB_CSR0_OUTPKTRDY)
	{
		nCount = (kal_uint32)USB_DRV_Reg8(USB_COUNT0);
	}
	RestoreIRQMask(savedMask);
#endif

	*dcl_data_ptr = (DCL_UINT32) nCount;
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_EP_Bulk_Tx_Ready(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_COMMON_FUNC_T *dcl_data_ptr;
	kal_uint32 savedMask;
	kal_uint32 ep_num;
//	USB_ENDPT_TXFER_TYPE ep_type;

	dcl_data_ptr = &data->rUSB_Common_Struct;
	ep_num = (kal_uint32)dcl_data_ptr->u4ep_num;

	USB_Dbg_Trace(USB_DBG_SET_TXPKTREADY, ep_num, 0);
	USB_EP_Check(ep_num, USB_EP_TX_DIR, 0);
	USB_EP_DMA_Running_Check(ep_num, USB_EP_TX_DIR, 0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	savedMask = SaveAndSetIRQMask();  //DMA_Setup : clear UnderRun bit & Set TX_PkyReady at the same time
	USB_DRV_WriteReg8(USB_INDEX, ep_num);

	if(USB_DRV_Reg(USB_TXCSR)&USB_TXCSR_TXPKTRDY)  // check TX_PktReady bit
	{
		ASSERT(0);
	}

	USB_DRV_SetBits(USB_TXCSR, USB_TXCSR_TXPKTRDY);
	RestoreIRQMask(savedMask);
#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	USB_DRV_WriteReg8(USB_INCSR1, USB_INCSR1_INPKTRDY);
	RestoreIRQMask(savedMask);
#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_EP_Rx_Pkt_Len(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_3_T *prep_ctrl_func_3;
	kal_uint32 ep_num;
	kal_uint32 savedMask;
	kal_uint16 CSR;
	kal_uint32 nCount = 0;


	prep_ctrl_func_3 = &data->rEP_Ctrl_Func_3;
	ep_num = (kal_uint32)prep_ctrl_func_3->u4ep_num;

	USB_EP_Check(ep_num, USB_EP_RX_DIR, 0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	CSR = USB_DRV_Reg(USB_RXCSR);

	if(CSR&USB_RXCSR_RXPKTRDY)
	{
		nCount = (kal_uint32)USB_DRV_Reg(USB_RXCOUNT);
	}
	RestoreIRQMask(savedMask);
#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	CSR = USB_DRV_Reg8(USB_OUTCSR1);

	if(CSR & USB_OUTCSR1_OUTPKTRDY)
	{
		nCount = (kal_uint32)USB_DRV_Reg8(USB_OUTCOUNT1);
	}
	RestoreIRQMask(savedMask);
#endif

	prep_ctrl_func_3->u4result = (DCL_UINT32)nCount;
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_EP_Bulk_Rx_Ready(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_COMMON_FUNC_T *dcl_data_ptr;
	kal_uint32 savedMask;
	kal_uint32 ep_num;
//	USB_ENDPT_TXFER_TYPE ep_type;

	dcl_data_ptr = &data->rUSB_Common_Struct;
	ep_num = (kal_uint32)dcl_data_ptr->u4ep_num;


	USB_EP_Check(ep_num, USB_EP_RX_DIR, 0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);

	if((USB_DRV_Reg(USB_RXCSR)&USB_RXCSR_RXPKTRDY) == 0)  // check RX_PktReady bit
	{
		if(kal_if_hisr() == KAL_TRUE)
			ASSERT(0);
	}

	USB_DRV_ClearBits(USB_RXCSR, USB_RXCSR_RXPKTRDY);
	RestoreIRQMask(savedMask);
#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);

	if((USB_DRV_Reg8(USB_OUTCSR1)&USB_OUTCSR1_OUTPKTRDY) == 0)  // check RX_PktReady bit
	{
		ASSERT(0);
	}

	USB_DRV_ClearBits8(USB_OUTCSR1, USB_OUTCSR1_OUTPKTRDY);
	RestoreIRQMask(savedMask);
#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Is_EP_Bulk_Tx_Empty(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_4_T *prep_ctrl_func_4;
	kal_uint32 ep_num;
	USB_ENDPT_TXFER_TYPE ep_type;
//	kal_uint32 savedMask;
//	kal_uint16 CSR;
//	kal_bool result;

	prep_ctrl_func_4 = &data->rEP_Ctrl_Func_4;
	ep_num = (kal_uint32)prep_ctrl_func_4->u4ep_num;
	ep_type = (USB_ENDPT_TXFER_TYPE)prep_ctrl_func_4->ep_type;
	prep_ctrl_func_4->fgresult = (DCL_BOOL)USB_HW_Is_EP_Tx_Empty(ep_num, ep_type);
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Is_EP_Bulk_Rx_Empty(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_4_T *prep_ctrl_func_4;
	kal_uint32 ep_num;
	kal_uint32 savedMask;
	kal_uint16 CSR;
	kal_bool result;

	prep_ctrl_func_4 = &data->rEP_Ctrl_Func_4;
	ep_num = (kal_uint32)prep_ctrl_func_4->u4ep_num;


	USB_EP_Check(ep_num, USB_EP_RX_DIR, 0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	CSR = USB_DRV_Reg(USB_RXCSR);
	RestoreIRQMask(savedMask);

	if(CSR&USB_RXCSR_RXPKTRDY)
		result = KAL_FALSE;
	else
		result = KAL_TRUE;

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	savedMask = SaveAndSetIRQMask();
	DRV_WriteReg8(USB_INDEX, ep_num);
	CSR = DRV_Reg8(USB_OUTCSR1);
	RestoreIRQMask(savedMask);

	if(CSR&USB_OUTCSR1_OUTPKTRDY)
		result = KAL_FALSE;
	else
		result = KAL_TRUE;
#endif

	prep_ctrl_func_4->fgresult = (DCL_BOOL)result;
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Clear_Tx_EP_FIFO(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_2_T *prep_ctrl_func_2;
	kal_uint32 savedMask;
	kal_uint32 ep_num;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	USB_ENDPT_TXFER_TYPE ep_type;
#endif
	kal_bool b_reset_toggle;


	prep_ctrl_func_2 = &data->rEP_Ctrl_Func_2;
	ep_num = (kal_uint32)prep_ctrl_func_2->u4ep_num;
	b_reset_toggle = (kal_bool)prep_ctrl_func_2->fg_reset_toggle;


	USB_EP_Check(ep_num, USB_EP_TX_DIR, 0);
	USB_EP_DMA_Running_Check(ep_num, USB_EP_TX_DIR, 0);
	USB_Dbg_Trace(USB_CLEAR_TX_EP_FIFO, ep_num, 0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	ep_type = (USB_ENDPT_TXFER_TYPE)prep_ctrl_func_2->ep_type;
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);

	if((USB_DRV_Reg(USB_TXCSR)&USB_TXCSR_FIFONOTEMPTY) != 0)
		g_UsbDrvInfo.ep_tx_flush_intr[ep_num-1] = KAL_TRUE;

	/* FLUSHFIFO only works with TXPKTRDY is 0, so we cannot "or" */
	/* DMAReqEnab must be "0" before FLUSHFIFO, otherwise DMA will complete and issue DMA interrupt */
	if(ep_type == USB_ENDPT_ISO)
	{
		// To clear all DMA bits
		USB_DRV_WriteReg(USB_TXCSR, USB_TXCSR_ISO);

		if(b_reset_toggle == KAL_TRUE)
		{
			USB_DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG|USB_TXCSR_ISO));
			USB_DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG|USB_TXCSR_ISO));
		}
		else
		{
			USB_DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_ISO));
			USB_DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_ISO));
		}
	}
	else
	{
		// To clear all DMA bits
		USB_DRV_WriteReg(USB_TXCSR, 0x00);

		if(b_reset_toggle == KAL_TRUE)
		{
			USB_DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
			USB_DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
		}
		else
		{
			USB_DRV_WriteReg(USB_TXCSR, USB_TXCSR_FLUSHFIFO);
			USB_DRV_WriteReg(USB_TXCSR, USB_TXCSR_FLUSHFIFO);
		}
	}
	RestoreIRQMask(savedMask);

#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);

	if(b_reset_toggle == KAL_TRUE)
	{
		USB_DRV_SetBits8(USB_INCSR1, USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG);
		USB_DRV_SetBits8(USB_INCSR1, USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG);
	}
	else
	{
		USB_DRV_SetBits8(USB_INCSR1, USB_INCSR1_FLUSHFIFO);
		USB_DRV_SetBits8(USB_INCSR1, USB_INCSR1_FLUSHFIFO);
	}
	RestoreIRQMask(savedMask);
#endif


	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Clear_Rx_EP_FIFO(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_2_T *prep_ctrl_func_2;
	kal_uint32 savedMask;
	kal_uint32 ep_num;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	USB_ENDPT_TXFER_TYPE ep_type;
#endif
	kal_bool b_reset_toggle;


	prep_ctrl_func_2 = &data->rEP_Ctrl_Func_2;
	ep_num = (kal_uint32)prep_ctrl_func_2->u4ep_num;
	b_reset_toggle = (kal_bool)prep_ctrl_func_2->fg_reset_toggle;


	USB_EP_Check(ep_num, USB_EP_RX_DIR, 0);
	USB_EP_DMA_Running_Check(ep_num, USB_EP_RX_DIR, 0);
	USB_Dbg_Trace(USB_CLEAR_RX_EP_FIFO, ep_num, 0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	ep_type = (USB_ENDPT_TXFER_TYPE)prep_ctrl_func_2->ep_type;
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);

	if((USB_DRV_Reg(USB_RXCSR)&USB_RXCSR_RXPKTRDY) != 0)
		g_UsbDrvInfo.ep_rx_flush_intr[ep_num-1] = KAL_TRUE;

	if(ep_type == USB_ENDPT_ISO)
	{
		// To clear all DMA bits
		USB_DRV_WriteReg(USB_RXCSR, USB_RXCSR_ISO|USB_RXCSR_RXPKTRDY);

		if(b_reset_toggle == KAL_TRUE)
		{
			USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG|USB_RXCSR_ISO|USB_RXCSR_RXPKTRDY));
			USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG|USB_RXCSR_ISO|USB_RXCSR_RXPKTRDY));
		}
		else
		{
			USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_ISO|USB_RXCSR_RXPKTRDY));
			USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_ISO|USB_RXCSR_RXPKTRDY));
		}
	}
	else
	{
		// To clear all DMA bits
		USB_DRV_WriteReg(USB_RXCSR, USB_RXCSR_RXPKTRDY);

		if(b_reset_toggle == KAL_TRUE)
		{
			USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG|USB_RXCSR_RXPKTRDY));
			USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG|USB_RXCSR_RXPKTRDY));
		}
		else
		{
			USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_RXPKTRDY));
			USB_DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_RXPKTRDY));
		}
	}

	RestoreIRQMask(savedMask);
#elif defined(DRV_USB_IP_V2)

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);

	if(b_reset_toggle == KAL_TRUE)
	{
		USB_DRV_SetBits8(USB_OUTCSR1, USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG);
		USB_DRV_SetBits8(USB_OUTCSR1, USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG);
	}
	else
	{
		USB_DRV_SetBits8(USB_OUTCSR1, USB_OUTCSR1_FLUSHFIFO);
		USB_DRV_SetBits8(USB_OUTCSR1, USB_OUTCSR1_FLUSHFIFO);
	}
	RestoreIRQMask(savedMask);
#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Get_DMA_Channel(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_DMA_FUNC_T *prdma_func;
	kal_uint32 ep_tx_num;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint32 ep_rx_num;
	USB_EP_DIRECTION direction;
	kal_bool same_chan;
	/* Should not allow re-entry */
	static kal_bool race_check = KAL_FALSE;
#endif

	prdma_func = &data->rDMA_Func;

	ep_tx_num = (kal_uint32)prdma_func->u4ep_tx_num;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	ep_rx_num = (kal_uint32)prdma_func->u4ep_rx_num;
	direction = (USB_EP_DIRECTION)prdma_func->direction;
	same_chan = (kal_bool)prdma_func->fgsame_chan;



	if(race_check == KAL_TRUE)
		ASSERT(0);
	race_check = KAL_TRUE;

	g_UsbDrvInfo.dma_channel++;

	if(g_UsbDrvInfo.dma_channel > MAX_DMA_NUM)
		EXT_ASSERT(0, (kal_uint32)g_UsbDrvInfo.dma_channel, MAX_DMA_NUM, 0);

	if(same_chan == KAL_TRUE)
	{
		USB_EP_Check(ep_tx_num, USB_EP_TX_DIR, 0);
		USB_EP_Check(ep_rx_num, USB_EP_RX_DIR, 0);

		g_UsbDrvInfo.is_bidirection_dma[g_UsbDrvInfo.dma_channel-1] = KAL_TRUE;
		/* the same channel */
		g_UsbDrvInfo.dma_port[USB_EP_TX_DIR][ep_tx_num-1] = g_UsbDrvInfo.dma_channel;
		g_UsbDrvInfo.dma_port[USB_EP_RX_DIR][ep_rx_num-1] = g_UsbDrvInfo.dma_channel;
		g_UsbDrvInfo.dma_tx_ep_num[g_UsbDrvInfo.dma_channel-1] = ep_tx_num;
		g_UsbDrvInfo.dma_rx_ep_num[g_UsbDrvInfo.dma_channel-1] = ep_rx_num;
	}
	else
	{
		g_UsbDrvInfo.is_bidirection_dma[g_UsbDrvInfo.dma_channel-1] = KAL_FALSE;
		g_UsbDrvInfo.dma_dir[g_UsbDrvInfo.dma_channel-1] = direction;

		if(direction == USB_EP_TX_DIR)
		{
			USB_EP_Check(ep_tx_num, USB_EP_TX_DIR, 0);
			g_UsbDrvInfo.dma_port[USB_EP_TX_DIR][ep_tx_num-1] = g_UsbDrvInfo.dma_channel;
			g_UsbDrvInfo.dma_tx_ep_num[g_UsbDrvInfo.dma_channel-1] = ep_tx_num;
		}
		else
		{
			USB_EP_Check(ep_rx_num, USB_EP_RX_DIR, 0);
			g_UsbDrvInfo.dma_port[USB_EP_RX_DIR][ep_rx_num-1] = g_UsbDrvInfo.dma_channel;
			g_UsbDrvInfo.dma_rx_ep_num[g_UsbDrvInfo.dma_channel-1] = ep_rx_num;
		}
	}

	race_check = KAL_FALSE;

#else
	switch (ep_tx_num)
	{
	case 1:
		g_UsbDrvInfo.dma_port[ep_tx_num - 1] = DMA_GetChannel(DMA_USB1TX);
		break;
#if defined(__USB_SUPPORT_MULTIPLE_DMA_CHANNEL__)
	case 2:
		g_UsbDrvInfo.dma_port[ep_tx_num- 1] = DMA_GetChannel(DMA_USB2TX);
		break;
#endif /* __USB_SUPPORT_MULTIPLE_DMA_CHANNEL__ */
	default:
		EXT_ASSERT(0, (kal_uint32)ep_tx_num, 0 , 0);
		break;
	}
#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Stop_DMA_Channel(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_COMMON_FUNC_T *prep_ctrl_func_5;
	kal_uint32 ep_num;
	USB_EP_DIRECTION direction;
	kal_uint32 	savedMask;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint8 	dma_chan;
    volatile kal_uint32 delay;
    kal_uint32 left_count;
	kal_bool  dma_pktrdy;
#endif

	prep_ctrl_func_5 = &data->rUSB_Common_Struct;
	ep_num = (kal_uint32)prep_ctrl_func_5->u4ep_num;
	direction = (USB_EP_DIRECTION)prep_ctrl_func_5->direction;

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	dma_chan = USB_Get_DMA_Channel_Num(ep_num, direction);

	savedMask = SaveAndSetIRQMask();
	/* Stop DMA channel */
	USBDMA_Stop(dma_chan);
//	USBDMA_PPStop(dma_chan);

	/* Clear pending DMA interrupts */
#if defined(DRV_USB_IP_V3)
	// write 0 clear
	USB_DRV_WriteReg32(USB_DMAINTR, ~((1<<(dma_chan-1))|(0xC000<<(dma_chan*2))));
#elif defined(DRV_USB_IP_V4)
	DRV_WriteReg8(USB_DMA_INTR_STATUS, (1<<(dma_chan-1)));
	//DRV_WriteReg8(USB_DMA_INTR_UNMASK_SET, (1<<(dma_chan-1)));
#endif
	dma_pktrdy = g_UsbDrvInfo.dma_pktrdy[dma_chan - 1];
	g_UsbDrvInfo.dma_pktrdy[dma_chan - 1] = KAL_FALSE;
	g_UsbDrvInfo.dma_running[dma_chan - 1] = KAL_FALSE;
	RestoreIRQMask(savedMask);
	for(delay=0 ;delay<500 ;delay++);  /* wait for dma stop */
	
	left_count = USB_DMACNT(dma_chan); //get DMA Real CNT 	
    USB_Dbg_Trace(USB_ACM_DMA_SETUP, left_count, 0);
	if((left_count== 0)  || (left_count > g_UsbDrvInfo.dma_tx_length[dma_chan - 1]) )  /* check for short pkt */
	{
	  /* drop data in FIFO*/
	  if(dma_pktrdy == KAL_TRUE)
	  {
		if(g_UsbDrvInfo.dma_dir[dma_chan-1] == USB_EP_TX_DIR)
		{
           savedMask = SaveAndSetIRQMask();		
           USB_DRV_WriteReg8(USB_INDEX, ep_num);		
           USB_DRV_SetBits(USB_TXCSR,USB_TXCSR_FLUSHFIFO|USB_TXCSR_TXPKTRDY);
           RestoreIRQMask(savedMask);		   
		}
	  }
	}	

#else  /* defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4) */
	USB_EP_Check(ep_num, direction, 0);

	if(g_UsbDrvInfo.dma_port[ep_num - 1] != 0)
	{
		if (DMA_CheckRunStat(g_UsbDrvInfo.dma_port[ep_num - 1]))
		{
			DMA_Stop(g_UsbDrvInfo.dma_port[ep_num - 1]);
		}

		savedMask = SaveAndSetIRQMask();
		if (DMA_CheckITStat(g_UsbDrvInfo.dma_port[ep_num - 1]))
		{
			DMA_ACKI(g_UsbDrvInfo.dma_port[ep_num - 1]);
			IRQClearInt(IRQ_DMA_CODE);
		}
		RestoreIRQMask(savedMask);
	}

	g_UsbDrvInfo.dma_pktrdy[ep_num - 1] = KAL_FALSE;
	g_UsbDrvInfo.dma_running[ep_num - 1] = KAL_FALSE;
#endif  /* defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4) */

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Free_DMA_Channel(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_DMA_FUNC_T *prdma_func;
	kal_uint32 ep_tx_num;
	USB_EP_DIRECTION direction;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint32 ep_rx_num;
	kal_bool same_chan;
	kal_uint8 dma_chan;
#endif

	prdma_func = &data->rDMA_Func;
	ep_tx_num = (kal_uint32)prdma_func->u4ep_tx_num;
	direction = (USB_EP_DIRECTION)prdma_func->direction;


#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	ep_rx_num = (kal_uint32)prdma_func->u4ep_rx_num;
	same_chan = (kal_bool)prdma_func->fgsame_chan;
	if(same_chan == KAL_TRUE)
	{
		USB_EP_Check(ep_tx_num, USB_EP_TX_DIR, 0);
		USB_EP_Check(ep_rx_num, USB_EP_RX_DIR, 0);

		USB_HW_Stop_DMA_Channel(ep_tx_num, USB_EP_TX_DIR);
		dma_chan = USB_Get_DMA_Channel_Num(ep_tx_num, USB_EP_TX_DIR);

		if(g_UsbDrvInfo.is_bidirection_dma[dma_chan-1] == KAL_FALSE)
		{
			ASSERT(0);
		}

		g_UsbDrvInfo.dma_tx_ep_num[dma_chan-1] = 0;
		g_UsbDrvInfo.dma_rx_ep_num[dma_chan-1] = 0;
		g_UsbDrvInfo.dma_port[USB_EP_TX_DIR][ep_tx_num-1] = 0;
		g_UsbDrvInfo.dma_port[USB_EP_RX_DIR][ep_rx_num-1] = 0;
	}
	else
	{
		if(direction == USB_EP_TX_DIR)
		{
			USB_EP_Check(ep_tx_num, USB_EP_TX_DIR, 0);
			USB_HW_Stop_DMA_Channel(ep_tx_num, USB_EP_TX_DIR);
			dma_chan = USB_Get_DMA_Channel_Num(ep_tx_num, USB_EP_TX_DIR);

			if(g_UsbDrvInfo.is_bidirection_dma[dma_chan-1] == KAL_TRUE)
			{
				ASSERT(0);
			}

			g_UsbDrvInfo.dma_tx_ep_num[dma_chan-1] = 0;
			g_UsbDrvInfo.dma_port[USB_EP_TX_DIR][ep_tx_num-1] = 0;
		}
		else
		{
			USB_EP_Check(ep_rx_num, USB_EP_RX_DIR, 0);
			USB_HW_Stop_DMA_Channel(ep_rx_num, USB_EP_RX_DIR);
			dma_chan = USB_Get_DMA_Channel_Num(ep_rx_num, USB_EP_RX_DIR);

			if(g_UsbDrvInfo.is_bidirection_dma[dma_chan-1] == KAL_TRUE)
			{
				ASSERT(0);
			}

			g_UsbDrvInfo.dma_rx_ep_num[dma_chan-1] = 0;
			g_UsbDrvInfo.dma_port[USB_EP_RX_DIR][ep_rx_num-1] = 0;
		}
	}

#else

	USB_EP_Check(ep_tx_num, USB_EP_TX_DIR, 0);

	if(g_UsbDrvInfo.dma_port[ep_tx_num - 1] != 0)
	{
		USB_HW_Stop_DMA_Channel(ep_tx_num, direction);
		DMA_FreeChannel(g_UsbDrvInfo.dma_port[ep_tx_num - 1]);
	}

	g_UsbDrvInfo.dma_port[ep_tx_num - 1] = 0;
#endif

	return STATUS_OK;
}


#ifdef DRV_USB_DMA_QUEUE_SUPPORT

void USB_TxEP_DMAQ_En(kal_uint8 epno, kal_bool bQMU)
{
	kal_uint8 dma_chan = epno;
	kal_uint32 savedMask;
	
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, epno);	
	if (bQMU)
	{
		DRV_WriteReg(USB_TXCSR, USB_DMAQ_TX_CSR);
		USB_DRV_WriteReg32(USB_DMAQ_TQEIR, USB_DMAQ_QIMCR0 <<(dma_chan-1));
		USB_DRV_WriteReg32(USB_DMAQ_TQEMIMCR, USB_DMAQ_QIMCR0 <<(dma_chan-1));
		USB_DRV_WriteReg32(USB_DMAQ_TQEIR, USB_DMAQ_QIMCR0 <<(dma_chan-1));		
		USB_DRV_WriteReg32(USB_DMAQ_TQEIMCR, USB_DMAQ_QIMCR0 <<(dma_chan-1));
		USB_DRV_WriteReg32(USB_DMAQ_TEPEIR, USB_DMAQ_QIMCR0 <<(dma_chan-1));		
		USB_DRV_WriteReg32(USB_DMAQ_TEPEIMCR, USB_DMAQ_QIMCR0 <<(dma_chan-1));
		USB_DRV_WriteReg32(USB_DMAQ_QCR2, USB_DMAQ_QCR2_TX0_ZLP <<(dma_chan-1)); // Send ZLP
		USB_DRV_WriteReg32(USB_DMAQ_QIMCR, USB_DMAQ_QIMCR_TX_DONE(dma_chan-1)|USB_DMAQ_QIMCR_TXEP_ERR|USB_DMAQ_QIMCR_TXQ_ERR|USB_DMAQ_QIMCR_TXQ_EMPTY);	
		USB_DRV_WriteReg32(USB_DMAQ_USBGCSR,  DRV_Reg32(USB_DMAQ_USBGCSR)|(USB_DMAQ_USBGCSR_TQ_EN<<(dma_chan-1)));
	}
	else
	{
		DRV_WriteReg(USB_TXCSR, 0x0);
		USB_DRV_ClearBits32(USB_DMAQ_TQEIR, USB_DMAQ_QIMCR0 <<(dma_chan-1));
		USB_DRV_ClearBits32(USB_DMAQ_TQEMIMCR, USB_DMAQ_QIMCR0 <<(dma_chan-1));
		USB_DRV_ClearBits32(USB_DMAQ_TQEIR, USB_DMAQ_QIMCR0 <<(dma_chan-1));		
		USB_DRV_ClearBits32(USB_DMAQ_TQEIMCR, USB_DMAQ_QIMCR0 <<(dma_chan-1));
		USB_DRV_ClearBits32(USB_DMAQ_TEPEIR, USB_DMAQ_QIMCR0 <<(dma_chan-1));		
		USB_DRV_ClearBits32(USB_DMAQ_TEPEIMCR, USB_DMAQ_QIMCR0 <<(dma_chan-1));
		USB_DRV_ClearBits32(USB_DMAQ_QCR2, USB_DMAQ_QCR2_TX0_ZLP <<(dma_chan-1));
		USB_DRV_ClearBits32(USB_DMAQ_QIMCR, USB_DMAQ_QIMCR_TX_DONE(dma_chan-1));	
		USB_DRV_ClearBits32(USB_DMAQ_USBGCSR, (USB_DMAQ_USBGCSR_TQ_EN<<(dma_chan-1)));
	}
	RestoreIRQMask(savedMask);
}

void USB_RxEP_DMAQ_En(kal_uint8 epno, kal_bool bQMU)
{
	kal_uint8 dma_chan = epno;
	kal_uint32 savedMask;
	
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, epno);	
	if (bQMU)
	{
		USB_DRV_WriteReg(USB_RXCSR, USB_DMAQ_RX_CSR | USB_RXCSR_RXPKTRDY);
		USB_DRV_WriteReg32(USB_DMAQ_RQEIR, USB_DMAQ_QIMCR0 <<(dma_chan-1));	
		USB_DRV_WriteReg32(USB_DMAQ_RQEMIMCR, USB_DMAQ_QIMCR0 <<(dma_chan-1));
		USB_DRV_WriteReg32(USB_DMAQ_RQEIR, USB_DMAQ_QIMCR0 <<(dma_chan-1));		
		USB_DRV_WriteReg32(USB_DMAQ_RQEIMCR, USB_DMAQ_QIMCR0<<(dma_chan-1));
		USB_DRV_WriteReg32(USB_DMAQ_REPEIR, USB_DMAQ_QIMCR0 <<(dma_chan-1));		
		USB_DRV_WriteReg32(USB_DMAQ_REPEIMCR, USB_DMAQ_QIMCR0 <<(dma_chan-1));
		USB_DRV_WriteReg32(USB_DMAQ_QIMCR, USB_DMAQ_QIMCR_RX_DONE(dma_chan-1)|USB_DMAQ_QIMCR_RXEP_ERR|USB_DMAQ_QIMCR_RXQ_ERR|USB_DMAQ_QIMCR_RXQ_EMPTY);
		USB_DRV_WriteReg32(USB_DMAQ_USBGCSR, DRV_Reg32(USB_DMAQ_USBGCSR)|(USB_DMAQ_USBGCSR_RQ_EN<<(dma_chan-1)));
	}
	else
	{
		USB_DRV_WriteReg(USB_RXCSR, USB_RXCSR_RXPKTRDY);
		USB_DRV_ClearBits32(USB_DMAQ_RQEIR, USB_DMAQ_QIMCR0 <<(dma_chan-1));	
		USB_DRV_ClearBits32(USB_DMAQ_RQEMIMCR, USB_DMAQ_QIMCR0 <<(dma_chan-1));
		USB_DRV_ClearBits32(USB_DMAQ_RQEIR, USB_DMAQ_QIMCR0 <<(dma_chan-1));		
		USB_DRV_ClearBits32(USB_DMAQ_RQEIMCR, USB_DMAQ_QIMCR0<<(dma_chan-1));
		USB_DRV_ClearBits32(USB_DMAQ_REPEIR, USB_DMAQ_QIMCR0 <<(dma_chan-1));		
		USB_DRV_ClearBits32(USB_DMAQ_REPEIMCR, USB_DMAQ_QIMCR0 <<(dma_chan-1));
		USB_DRV_ClearBits32(USB_DMAQ_QIMCR, USB_DMAQ_QIMCR_RX_DONE(dma_chan-1));
		USB_DRV_ClearBits32(USB_DMAQ_USBGCSR, (USB_DMAQ_USBGCSR_RQ_EN<<(dma_chan-1)));
	}
	RestoreIRQMask(savedMask);	
}


void USB_DMAQ_Setup(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_bool first, kal_uint32 addr,
					usb_dmaq_CB callback, usb_dmaq_CB empty_callback ,void *privdata)
{
	kal_uint8 dma_chan = ep_num;

	ASSERT(addr);

	g_UsbDrvInfo.dmaq_callback[direction][dma_chan-1] = callback;
	g_UsbDrvInfo.dmaq_empty_callback[direction][dma_chan-1] = empty_callback;
	g_UsbDrvInfo.privdata[direction][dma_chan-1] = privdata;		
	Data_Sync_Barrier();			

 	/* DMAQ_CONFIG */
	if(direction == USB_EP_RX_DIR)
	{	
		//DRV_WriteReg32(USB_DMAQ_RQSAR(dma_chan), addr);
		if(first == KAL_TRUE)
		{
			DRV_WriteReg32(USB_DMAQ_RQSAR(dma_chan), addr);		
			DRV_WriteReg32(USB_DMAQ_RQCSR(dma_chan), USB_DMACNTL_DMAEN_START);
		}
		else
		{
			DRV_WriteReg32(USB_DMAQ_RQCSR(dma_chan), USB_DMACNTL_DMAEN_RESUME);			
		}
	}
	else if (direction == USB_EP_TX_DIR)
	{	
	//	DRV_WriteReg32(USB_DMAQ_TQSAR(dma_chan), addr);
		if(first == KAL_TRUE)
		{
			DRV_WriteReg32(USB_DMAQ_TQSAR(dma_chan), addr);		
			DRV_WriteReg32(USB_DMAQ_TQCSR(dma_chan), USB_DMACNTL_DMAEN_START);
		}
		else
		{
			DRV_WriteReg32(USB_DMAQ_TQCSR(dma_chan), USB_DMACNTL_DMAEN_RESUME);			
		}
	}			
	else
	{
		ASSERT(0);
	}
}

void USB_DMAQ_Stop(kal_uint32 ep_num, USB_EP_DIRECTION direction)
{
	kal_uint8	dma_chan = ep_num;
	volatile kal_uint32 temp_read;  

   	/* DMAQ_CONFIG */
	if(direction == USB_EP_RX_DIR)
	{		
		DRV_WriteReg32(USB_DMAQ_RQCSR(dma_chan), USB_DMACNTL_DMAEN_STOP);			
		if ((USB_DRV_Reg32(USB_DMAQ_RQCSR(dma_chan))&USB_DMACNTL_DMAEN_ACTIVE) > 0)
		{
			temp_read = USB_DRV_Reg32(USB_DMAQ_RQCSR(dma_chan));
			while (1)
			{
				temp_read = USB_DRV_Reg32(USB_DMAQ_RQCSR(dma_chan));
				if (temp_read == 0x00)
					break;
			}
		}
	}
	else if (direction == USB_EP_TX_DIR)
	{	
		DRV_WriteReg32(USB_DMAQ_TQCSR(dma_chan), USB_DMACNTL_DMAEN_STOP);			
		if ((USB_DRV_Reg32(USB_DMAQ_TQCSR(dma_chan))&USB_DMACNTL_DMAEN_ACTIVE) > 0)
		{
			temp_read = USB_DRV_Reg32(USB_DMAQ_TQCSR(dma_chan));
			while (1)
			{
				temp_read = USB_DRV_Reg32(USB_DMAQ_TQCSR(dma_chan));
				if (temp_read == 0x00)
					break;
			}
		}
	}			
	else
	{
		ASSERT(0);
	}
}

void USB_DMAQ_Insert(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_uint32 header, kal_uint32 addr)
{
	kal_uint8	dma_chan = ep_num;
	volatile TGPD *gpd_ptr = (TGPD*)header;
	
	ASSERT(addr);
	ASSERT(header);
	ASSERT(gpd_ptr->pNext);
	
  /* DMAQ_CONFIG */
	if(direction == USB_EP_RX_DIR)
	{	
		while(gpd_ptr->pNext->pNext != NULL)
		{
			gpd_ptr = gpd_ptr->pNext;
		}
		gpd_ptr->pNext = (TGPD*)addr;
		
		Data_Sync_Barrier();
		DRV_WriteReg32(USB_DMAQ_RQCSR(dma_chan), USB_DMACNTL_DMAEN_RESUME);
	}
	else if (direction == USB_EP_TX_DIR)
	{
		while(gpd_ptr->pNext->pNext != NULL)
		{
			gpd_ptr = gpd_ptr->pNext;
		}
		gpd_ptr->pNext = (TGPD*)addr;
	
		Data_Sync_Barrier();
		DRV_WriteReg32(USB_DMAQ_TQCSR(dma_chan), USB_DMACNTL_DMAEN_RESUME);
	}
	else
	{
		ASSERT(0);
	}
}


#endif //DRV_USB_DMA_QUEUE_SUPPORT	

static DCL_STATUS DCL_USB_CTRL_API_USB_DMA_Setup(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_DMA_SETUP_FUNC_T *prdma_setup_func;
	kal_uint32 ep_num;
	USB_EP_DIRECTION direction;
	kal_uint32 addr;
	kal_uint32 length;
	usb_dma_callback callback;
	kal_bool callback_upd_run;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	USB_ENDPT_TXFER_TYPE ep_type;
	kal_bool known_size;
	USB_DMA_TYPE dma_type;
	kal_uint16 dma_ctrl;
	kal_uint8 dma_chan;
	static kal_uint32 dma_burst_mode = 0;
	kal_uint32 savedMask;
#else  /* defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4) */
	DMA_INPUT dma_input;
   	DMA_HWMENU dma_menu;
#endif

	prdma_setup_func = &data->rDMA_Setup_Func;
	ep_num = (kal_uint32)prdma_setup_func->u4ep_num;
	direction = (USB_EP_DIRECTION)prdma_setup_func->direction;
  #if defined(MT6752) && defined(__MD1__) /* USB in AP side, and bank addr is 0x80000000*/
    addr = (kal_uint32)prdma_setup_func->u4addr | 0x80000000;;
  #elif defined(MT6752) && defined(__MD2__)  /*USB in AP side, bank addr is 0x80000000*/
    addr = (kal_uint32)prdma_setup_func->u4addr | 0x80000000;
  #elif defined(MT6572) || defined(MT6582)  /*USB in AP side, bank addr is 0x80000000*/
    addr = (kal_uint32)prdma_setup_func->u4addr | 0x80000000;    
  #else
    addr = (kal_uint32)prdma_setup_func->u4addr;
  #endif		
	length = (kal_uint32)prdma_setup_func->u4length;
	callback = (usb_dma_callback)prdma_setup_func->callback;
	callback_upd_run = (kal_bool)prdma_setup_func->fgcallback_upd_run;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	ep_type = (USB_ENDPT_TXFER_TYPE)prdma_setup_func->ep_type;	
	known_size = (kal_bool)prdma_setup_func->fgknown_size;
	dma_type = (USB_DMA_TYPE)prdma_setup_func->dma_type;


#ifdef  __DYNAMIC_SWITCH_CACHEABILITY__
	if((kal_bool)INT_QueryIsNonCachedRAM(addr, length) == KAL_FALSE)
		ASSERT(0);
#endif
	if (((kal_bool)INT_QueryIsROMSpace(addr)== KAL_TRUE) || 
		((kal_bool)INT_QueryIsROMSpace(addr+length) == KAL_TRUE)) {
				EXT_ASSERT(0, addr, length, 0);
	}

	if(length == 0)
		ASSERT(0);

	if(g_UsbDrvInfo.usb_disconnect == KAL_TRUE)
		return STATUS_OK;

	dma_chan = USB_Get_DMA_Channel_Num(ep_num, direction);

	ASSERT(g_UsbDrvInfo.dma_running[dma_chan-1] == KAL_FALSE);

	if(g_UsbDrvInfo.is_bidirection_dma[dma_chan-1] == KAL_TRUE)
	{
		g_UsbDrvInfo.dma_dir[dma_chan-1] = direction;
	}
	else if(g_UsbDrvInfo.dma_dir[dma_chan-1] != direction)
	{
		EXT_ASSERT(0, (kal_uint32)dma_chan, (kal_uint32)g_UsbDrvInfo.dma_dir[dma_chan-1], (kal_uint32)direction);
	}

	g_UsbDrvInfo.dma_running[dma_chan-1] = KAL_TRUE;
	g_UsbDrvInfo.dma_callback[dma_chan-1] = callback;
	g_UsbDrvInfo.dma_callback_upd_run[dma_chan-1] = callback_upd_run;
	g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_FALSE;

#ifdef __WRITE_THROUGH_CACHEABLE__
	if(direction == USB_EP_RX_DIR)
	{
		g_UsbDrvInfo.dma_length[dma_chan-1] = length;
		g_UsbDrvInfo.dma_addr[dma_chan-1] = addr;
	}
#endif


	if(direction == USB_EP_RX_DIR)
	{
		if(ep_type == USB_ENDPT_BULK)
		{
			if(g_UsbDrvInfo.Is_HS_mode == KAL_TRUE)
			{
				if(((length%USB_EP_BULK_MAXP_HS) != 0)
					&&((length%USB_EP_BULK_MAXP_HS) <= (USB_EP_BULK_MAXP_HS - 4)))
					g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
			}
			else
			{
				if(((length%USB_EP_BULK_MAXP_FS) != 0)
					&&((length%USB_EP_BULK_MAXP_FS) <= (USB_EP_BULK_MAXP_FS - 4)))
					g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
			}
		}
		else if(ep_type == USB_ENDPT_ISO)
		{
			if(g_UsbDrvInfo.Is_HS_mode == KAL_TRUE)
			{
	#ifdef __ISO_HB__
				if(((length%USB_EP_ISO_MAXP_HB_HS) != 0)
					&&((length%USB_EP_ISO_MAXP_HB_HS) <= (USB_EP_ISO_MAXP_HB_HS - 4)))
					g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
	#else
				if(((length%USB_EP_ISO_MAXP_HS) != 0)
					&&((length%USB_EP_ISO_MAXP_HS) <= (USB_EP_ISO_MAXP_HS - 4)))
					g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
	#endif
			}
			else
			{
				if(((length%USB_EP_ISO_MAXP_FS) != 0)
					&&((length%USB_EP_ISO_MAXP_FS) <= (USB_EP_ISO_MAXP_FS - 4)))
					g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
			}
		}
	}
	else
	{
#ifdef __USB_AUTO_SET__
		// Auto set only can use on "ep1 with channel 2", "ep2 with channel 3", and "ep3 with channel 4"
		/* Judge if it is multiple of max packet length */
		if(((ep_num != 1)||(dma_chan != 2))&&((ep_num != 2)||(dma_chan != 3))&&((ep_num != 3)||(dma_chan != 4)))
		{
#endif
			if(ep_type == USB_ENDPT_BULK)
			{
				if(g_UsbDrvInfo.Is_HS_mode == KAL_TRUE)
				{
					if(length%USB_EP_BULK_MAXP_HS)
						g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
				}
				else
				{
					if(length%USB_EP_BULK_MAXP_FS)
						g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
				}
			}
			else if(ep_type == USB_ENDPT_INTR)
			{
				if(g_UsbDrvInfo.Is_HS_mode == KAL_TRUE)
				{
		#ifdef __INTR_HB__
					if(length%USB_EP_INTR_MAXP_HB_HS)
						g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
		#else
					if(length%USB_EP_INTR_MAXP_HS)
						g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
		#endif
				}
				else
				{
					if(length%USB_EP_INTR_MAXP_FS)
						g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
				}
			}
			else if(ep_type == USB_ENDPT_ISO)
			{
				if(g_UsbDrvInfo.Is_HS_mode == KAL_TRUE)
				{
		#ifdef __ISO_HB__
					if(length%USB_EP_ISO_MAXP_HB_HS)
						g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
		#else
					if(length%USB_EP_ISO_MAXP_HS)
						g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
		#endif
				}
				else
				{
					if(length%USB_EP_ISO_MAXP_FS)
						g_UsbDrvInfo.dma_pktrdy[dma_chan-1] = KAL_TRUE;
				}
			}
#ifdef __USB_AUTO_SET__
		}
#endif
	}

	if(g_UsbDrvInfo.b_enable_dma_burst_auto_chge == KAL_TRUE)
		dma_burst_mode++;
	else
		dma_burst_mode = g_UsbDrvInfo.dma_burst_mode;

	/* DMA_CONFIG */
	if(dma_type == USB_DMA0_TYPE)
	{
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
#endif
	}
	else if(dma_type == USB_DMA1_TYPE)
	{
		if(direction == USB_EP_TX_DIR)
		{
			savedMask = SaveAndSetIRQMask();
			USB_DRV_WriteReg8(USB_INDEX, ep_num);

			/* Only is configured as multiple packet DMA TX mode */
			if(ep_type == USB_ENDPT_ISO)
			{
				USB_DRV_WriteReg(USB_TXCSR, USB_DMA_TX_CSR_ISO);
			}
			else
			{
				USB_DRV_WriteReg(USB_TXCSR, USB_DMA_TX_CSR);
			}

	#ifdef __USB_AUTO_SET__
			if(((ep_num == 1)&&(dma_chan == 2))||((ep_num == 2)&&(dma_chan == 3))||((ep_num == 3)&&(dma_chan == 4)))
			{
				USB_DRV_SetBits(USB_TXCSR, USB_TXCSR_AUTOSET_SPKT);
			}
	#endif

			RestoreIRQMask(savedMask);
         	g_UsbDrvInfo.dma_tx_length[dma_chan - 1] = length;

			USB_DRV_WriteReg32(USB_DMAADDR(dma_chan), addr);
			USB_DRV_WriteReg32(USB_DMACNT(dma_chan), length);

			dma_ctrl = USB_DMACNTL_DMADIR|USB_DMACNTL_DMAMODE|USB_DMACNTL_INTEN|(ep_num<<4);
			dma_ctrl |= ((dma_burst_mode&0x03)<<9)|USB_DMACNTL_DMAEN;
			Data_Sync_Barrier(); 
			USB_DRV_WriteReg(USB_DMACNTL(dma_chan), dma_ctrl);
		}
		else if(direction == USB_EP_RX_DIR)
		{
			/* Stop DMA channel */
			USBDMA_Stop(dma_chan);
//			USBDMA_PPStop(dma_chan);

			if(known_size == KAL_TRUE)
			{
				savedMask = SaveAndSetIRQMask();
				USB_DRV_WriteReg8(USB_INDEX, ep_num);

				if(ep_type == USB_ENDPT_ISO)
				{
					USB_DRV_WriteReg(USB_RXCSR, USB_DMA_RX_CSR_ISO|USB_RXCSR_RXPKTRDY);
				}
				else
				{
					USB_DRV_WriteReg(USB_RXCSR, USB_DMA_RX_CSR|USB_RXCSR_RXPKTRDY);
				}

				RestoreIRQMask(savedMask);
			}
			else
			{
		#ifdef  __DMA_UNKNOWN_RX__
				savedMask = SaveAndSetIRQMask();
				USB_DRV_WriteReg8(USB_INDEX, ep_num);

				if(ep_type == USB_ENDPT_ISO)
				{
					USB_DRV_WriteReg(USB_RXCSR, USB_DMA_RX_CSR_ISO|USB_RXCSR_RXPKTRDY|USB_RXCSR_DMAREQMODE);
				}
				else
				{
					USB_DRV_WriteReg(USB_RXCSR, USB_DMA_RX_CSR|USB_RXCSR_RXPKTRDY|USB_RXCSR_DMAREQMODE);
				}

				RestoreIRQMask(savedMask);

				USB_Enable_DMA_Timer_Count(dma_chan, KAL_TRUE, 0x7F);

		#else   /* __DMA_UNKNOWN_RX__ */
				ASSERT(0);
		#endif  /* __DMA_UNKNOWN_RX__ */
			}

			USB_DRV_WriteReg32(USB_DMAADDR(dma_chan), addr);
			USB_DRV_WriteReg32(USB_DMACNT(dma_chan), length);

			dma_ctrl = USB_DMACNTL_DMAMODE|USB_DMACNTL_INTEN|(ep_num<<4);
			dma_ctrl |= ((dma_burst_mode&0x03)<<9)|USB_DMACNTL_DMAEN;
			Data_Sync_Barrier(); 			
			USB_DRV_WriteReg(USB_DMACNTL(dma_chan), dma_ctrl);
		}
	}
	else if(dma_type == USB_DMA2_TYPE)
	{
#if defined(DRV_USB_IP_V4)
		EXT_ASSERT(0, 0, 0, 0);
#else
		if(direction == USB_EP_RX_DIR)
		{
			if(known_size == KAL_TRUE)
			{
				/* Stop DMA channel */
				USBDMA_Stop(dma_chan);
//				USBDMA_PPStop(dma_chan);

				savedMask = SaveAndSetIRQMask();
				USB_DRV_WriteReg8(USB_INDEX, ep_num);

				if(ep_type == USB_ENDPT_ISO)
				{
					USB_DRV_WriteReg(USB_RXCSR, USB_DMA_RX_CSR_ISO|USB_RXCSR_RXPKTRDY);
				}
				else
				{
					USB_DRV_WriteReg(USB_RXCSR, USB_DMA_RX_CSR|USB_RXCSR_RXPKTRDY);
				}

				RestoreIRQMask(savedMask);
			}
			else
			{
				ASSERT(0);
			}

			USB_DRV_WriteReg32(USB_DMAADDR(dma_chan), addr);
			USB_DRV_WriteReg32(USB_DMACNT(dma_chan), length);

			dma_ctrl = USB_DMACNTL_DMAMODE|USB_DMACNTL_INTEN|(ep_num<<4)|USB_DMACNTL_ENDMAMODE2;
			dma_ctrl |= ((dma_burst_mode&0x03)<<9)|USB_DMACNTL_DMAEN;

			USB_DRV_WriteReg(USB_DMACNTL(dma_chan), dma_ctrl);
		}
		else if(direction == USB_EP_TX_DIR)
		{
			ASSERT(0);
		}
#endif
	}
#else  /* defined(DRV_USB_IP_V3) */

	USB_EP_Check(ep_num, direction, 0);

#ifdef  __DYNAMIC_SWITCH_CACHEABILITY__
	if((kal_bool)INT_QueryIsNonCachedRAM(addr, length) == KAL_FALSE)
		ASSERT(0);
#endif
	if (((kal_bool)INT_QueryIsROMSpace(addr)== KAL_TRUE) || 
		((kal_bool)INT_QueryIsROMSpace(addr+length) == KAL_TRUE)) {
		EXT_ASSERT(0, addr, length, 0);
	}

	if(length == 0)
		ASSERT(0);

	ASSERT(g_UsbDrvInfo.dma_running[ep_num - 1]==KAL_FALSE);
	g_UsbDrvInfo.dma_running[ep_num - 1] = KAL_TRUE;

	ASSERT(g_UsbDrvInfo.dma_port[ep_num - 1] !=0);

	g_UsbDrvInfo.dma_callback[ep_num - 1] = callback;
	g_UsbDrvInfo.dma_callback_upd_run[ep_num - 1] = callback_upd_run;
	g_UsbDrvInfo.dma_dir[ep_num - 1] = direction;

#ifdef __WRITE_THROUGH_CACHEABLE__
	if(direction == USB_EP_RX_DIR)
	{
		g_UsbDrvInfo.dma_length[ep_num - 1] = length;
		g_UsbDrvInfo.dma_addr[ep_num - 1] = addr;
	}
#endif

	/* DMA_CONFIG */
	/* Single mode */
	dma_menu.TMOD.burst_mode = KAL_FALSE;

	if (ep_num == 1)
	{
		if(direction == USB_EP_TX_DIR)
		{
			dma_menu.master = DMA_USB1TX;
		}
		else
		{
			dma_menu.master = DMA_USB1RX;
		}

		dma_input.callback = USB_DMA1_Callback;
	}
#if defined(__USB_SUPPORT_MULTIPLE_DMA_CHANNEL__)
	else if (ep_num == 2)
	{
		if(direction == USB_EP_TX_DIR)
		{
			dma_menu.master = DMA_USB2TX;
		}
		else
		{
			dma_menu.master = DMA_USB2RX;
		}

		dma_input.callback = USB_DMA2_Callback;
	}
#endif /* __USB_SUPPORT_MULTIPLE_DMA_CHANNEL__ */
	else
	{
		EXT_ASSERT(0, (kal_uint32)ep_num, 0, 0);
	}

	dma_menu.addr = (kal_uint32)addr;

	/* half channel */
	if(direction == USB_EP_TX_DIR)
		dma_input.type = DMA_HWTX;
	else
		dma_input.type = DMA_HWRX;

	dma_input.menu = &dma_menu;

	// moduler 4
	if ((length&0x3) || (addr&0x3))
	{
		/* byte transfer */
		dma_input.size = DMA_BYTE;
		dma_input.count = length;
	}
	else
	{
		/* word transfer */
		dma_input.size = DMA_LONG;
		dma_input.count = length>>2;
	}

	/* judge if it is mutiple of max packet length*/
	if (length % USB_EP_BULK_MAXP)
		g_UsbDrvInfo.dma_pktrdy[ep_num - 1] = KAL_TRUE;
	else
		g_UsbDrvInfo.dma_pktrdy[ep_num - 1] = KAL_FALSE;

	/* Configure DMA */
	DMA_Config(g_UsbDrvInfo.dma_port[ep_num - 1], &dma_input, KAL_TRUE);
#endif  /* defined(DRV_USB_IP_V3) */

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_DMA_Get_Run_Status(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_CTRL_FUNC_1_T	 *prdma_get_run_status;
	kal_uint32 ep_num;
	USB_EP_DIRECTION direction;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint8   dma_chan;
#endif
	kal_bool result;


	prdma_get_run_status = &data->rEP_Ctrl_Func_1;
	ep_num = (kal_uint32)prdma_get_run_status->u4ep_num;
	direction = (USB_EP_DIRECTION)prdma_get_run_status->direction;


#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	dma_chan = USB_Get_DMA_Channel_Num(ep_num, direction);
	result = g_UsbDrvInfo.dma_running[dma_chan-1];
#else
	USB_EP_Check(ep_num, direction, 0);
	result = g_UsbDrvInfo.dma_running[ep_num-1];
#endif

	prdma_get_run_status->fg_result = (DCL_BOOL)result;
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_DMA_Set_Run_Status(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_DMA_STATUS_FUNC_T *prdma_status_func;
	kal_uint32 ep_num;
	USB_EP_DIRECTION direction;
	kal_bool status;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint8   dma_chan;
#endif

	prdma_status_func = &data->rDMA_Status_Func;
	ep_num = (kal_uint32)prdma_status_func->u4ep_num;
	direction = (USB_EP_DIRECTION)prdma_status_func->direction;
	status = (kal_bool)prdma_status_func->fgstatus;

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	dma_chan = USB_Get_DMA_Channel_Num(ep_num, direction);
	g_UsbDrvInfo.dma_running[dma_chan-1] = status;
#else
	USB_EP_Check(ep_num, direction, 0);
	g_UsbDrvInfo.dma_running[ep_num-1] = status;
#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Enable_DMA_Timer_Count(DCL_CTRL_DATA_T *data)
{
#if 0
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
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
#else
/* under construction !*/
#endif
#endif
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Check_DMA_Time_Out(DCL_CTRL_DATA_T *data)
{
#if 0
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
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
#else
/* under construction !*/
#endif
#endif
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Get_DMA_Real_Count(DCL_CTRL_DATA_T *data)
{
#if 0
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
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
#else
/* under construction !*/
#endif
#endif
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Set_DMA_Limiter(DCL_CTRL_DATA_T *data)
{
#if ((defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4))&&defined(__USB_LIMIT__))
	DCL_UINT32 *usb_data = (DCL_UINT32*)data;
	kal_uint32 dma_limit_num = (kal_uint32)(*usb_data);

	kal_uint8 dma_chan_num;


	if(dma_limit_num == 255)
		ASSERT(0);

	for (dma_chan_num = 1; dma_chan_num < (MAX_DMA_NUM+1); dma_chan_num++)
		USB_DRV_WriteReg(USB_DMALIMITER(dma_chan_num), dma_limit_num<<8);

	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Switch_DMA_Burst_mode(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	DCL_BOOL *usb_data = (DCL_BOOL*)data;
	kal_bool b_enable = (kal_bool)(*usb_data);


	if(b_enable == KAL_TRUE)
		g_UsbDrvInfo.b_enable_dma_burst_auto_chge = KAL_TRUE;
	else
		g_UsbDrvInfo.b_enable_dma_burst_auto_chge = KAL_FALSE;

	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Register_DMA_Channel(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	USB_DRV_CTRL_DMA_CTRL_FUNC_2_T *prdma_ctrl_func_2;
	kal_uint32 ep_num;
	USB_EP_DIRECTION direction;
	kal_uint8 chan_num;
	kal_bool same_chan;

	prdma_ctrl_func_2 = &data->rDMA_Ctrl_Func_2;
	ep_num = (kal_uint32 )prdma_ctrl_func_2->u4ep_num;
	direction = (USB_EP_DIRECTION)prdma_ctrl_func_2->direction;
	chan_num = (kal_uint8)prdma_ctrl_func_2->u1chan_num;
	same_chan = (kal_bool)prdma_ctrl_func_2->fgsame_chan;


	if((chan_num > MAX_DMA_NUM)||(chan_num == 0))
		EXT_ASSERT(0, chan_num, MAX_DMA_NUM, 0);

	if(same_chan == KAL_TRUE)
	{
		USB_EP_Check(ep_num, USB_EP_TX_DIR, 0);
		USB_EP_Check(ep_num, USB_EP_RX_DIR, 0);

		g_UsbDrvInfo.is_bidirection_dma[chan_num-1] = KAL_TRUE;
		/* the same channel */
		g_UsbDrvInfo.dma_port[USB_EP_TX_DIR][ep_num-1] = chan_num;
		g_UsbDrvInfo.dma_port[USB_EP_RX_DIR][ep_num-1] = chan_num;
		g_UsbDrvInfo.dma_tx_ep_num[chan_num-1] = ep_num;
		g_UsbDrvInfo.dma_rx_ep_num[chan_num-1] = ep_num;
	}
	else
	{
		g_UsbDrvInfo.is_bidirection_dma[chan_num-1] = KAL_FALSE;
		g_UsbDrvInfo.dma_dir[chan_num-1] = direction;
		g_UsbDrvInfo.dma_port[direction][ep_num-1] = chan_num;

		if(direction == USB_EP_TX_DIR)
		{
			USB_EP_Check(ep_num, USB_EP_TX_DIR, 0);
			g_UsbDrvInfo.dma_tx_ep_num[chan_num-1] = ep_num;
		}
		else
		{
			USB_EP_Check(ep_num, USB_EP_RX_DIR, 0);
			g_UsbDrvInfo.dma_rx_ep_num[chan_num-1] = ep_num;
		}
	}

	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Set_DMA_Burst_Mode(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	DCL_UINT8 *usb_data = (DCL_UINT8*)data;
	kal_uint8 dma_burst_mode = (kal_uint8)(*usb_data);


	g_UsbDrvInfo.dma_burst_mode = dma_burst_mode;
	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif


}


static DCL_STATUS DCL_USB_CTRL_API_USB_Is_High_Speed(DCL_CTRL_DATA_T *data)
{
	DCL_BOOL *usb_data;


	usb_data = (DCL_BOOL *)data;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	*usb_data = (DCL_BOOL)g_UsbDrvInfo.Is_HS_mode;
#else
	*usb_data = DCL_FALSE;
#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Enter_Test_Mode(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	USB_DRV_CTRL_USB_TEST_MODE_FUNC_T *prtest_mode_func;
	USB_TEST_MODE_TYPE test_selector;
	volatile kal_uint32 delay = 0;


	prtest_mode_func = &data->rTest_Mode_Func;
	test_selector = (USB_TEST_MODE_TYPE)prtest_mode_func->test_selector;


	if(test_selector == USB_TEST_MODE_TYPE_J)
	{
		USB_DRV_WriteReg8(USB_TESTMODE, USB_TESTMODE_TESTJ);
	}
	else if(test_selector == USB_TEST_MODE_TYPE_K)
	{
		USB_DRV_WriteReg8(USB_TESTMODE, USB_TESTMODE_TESTK);
	}
	else if(test_selector == USB_TEST_MODE_TYPE_SE0_NAK)
	{
//		USB_DRV_ClearBits8(USB_PHYCR2_0, USB_PHYCR2_0_HS_SQD_MASK);
//		USB_DRV_SetBits8(USB_PHYCR2_0, USB_PHYCR2_0_HS_SQD_SET);

		USB_DRV_WriteReg8(USB_TESTMODE, USB_TESTMODE_TESTSE0NAK);
	}
	else if(test_selector == USB_TEST_MODE_TYPE_PACKET)
	{
		kal_uint8 packet_test[] = {
					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA,
					0xAA, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE, 0xEE,
					0xEE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
					0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xBF, 0xDF,
					0xEF, 0xF7, 0xFB, 0xFD, 0xFC, 0x7E, 0xBF, 0xDF,
					0xEF, 0xF7, 0xFB, 0xFD, 0x7E};

		USB_HW_EPFIFOWrite(0, 53, packet_test);

		for(delay = 0; delay != 1000; delay++) ;

		USB_DRV_WriteReg8(USB_INDEX, 0);
		USB_DRV_WriteReg8(USB_TESTMODE, USB_TESTMODE_TESTPACKET);

		for(delay = 0; delay != 1000; delay++) ;

		USB_DRV_WriteReg(USB_CSR0, USB_CSR0_TXPKTRDY);
	}
	else
	{
		ASSERT(0);
	}

	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Reset_FIFO(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	g_FIFOadd = USB_FIFO_START_ADDRESS;
#endif
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_FIFO_Not_Empty(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	DCL_BOOL *usb_data;


	usb_data = (DCL_BOOL *)data;
	*usb_data = (DCL_BOOL)g_UsbDrvInfo.suspend_with_FIFO_not_empty;
	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Is_Suspend_Power_Status(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4) || defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)
	DCL_BOOL *usb_data;
	kal_bool result;


	usb_data = (DCL_BOOL *)data;

	if(g_UsbDrvInfo.power_state == USB_STATE_SUSPEND)
		result = KAL_TRUE;
	else
		result =  KAL_FALSE;

	*usb_data = (DCL_BOOL)result;
	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Polling_Transmit_Done(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_EP_COMMON_FUNC_T *prep_ctrl_func_2;
	kal_uint32 ep_num;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint8   dma_chan;
#endif

	prep_ctrl_func_2 = &data->rUSB_Common_Struct;
	ep_num = (kal_uint32)prep_ctrl_func_2->u4ep_num;


	/* This function can only be called after exception*/
	/* This ASSERT should be put in class driver layer */
//	if(INT_Exception_Enter == 0)
//		EXT_ASSERT(0, 0, 0, 0);

#if defined (DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	dma_chan = USB_Get_DMA_Channel_Num(ep_num, USB_EP_TX_DIR);

	/* error case, should it?? */
	if(g_UsbDrvInfo.dma_port[USB_EP_TX_DIR][ep_num - 1] == 0)
		return STATUS_FAIL;

	/* Polling until DMA done */
	while (USBDMA_CheckRunStat(dma_chan))
	{
		/* Check if other interrupt received */
		g_UsbDrvInfo.is_unMaskUSB = KAL_FALSE;
	#ifdef	__OTG_ENABLE__
		OTG_Set_Intr();
	#endif	
		USB_HISR();
	}
#if defined (DRV_USB_IP_V3)
	USB_DRV_WriteReg8(USB_DMAINTR, ~(0x01<<(dma_chan-1)));
#elif defined(DRV_USB_IP_V4)
	DRV_WriteReg8(USB_DMA_INTR_STATUS, (1<<(dma_chan-1)));
#endif

#else
	/* error case*/
	if(g_UsbDrvInfo.dma_port[ep_num - 1] == 0)
		return STATUS_FAIL;

	/* polling until DMA done */
	while (DMA_CheckRunStat(g_UsbDrvInfo.dma_port[ep_num - 1]))
	{
		/* check if other interrupt received*/
		g_UsbDrvInfo.is_unMaskUSB = KAL_FALSE;
		USB_HISR();
	}

	if (DMA_CheckITStat(g_UsbDrvInfo.dma_port[ep_num - 1]))
	{
		DMA_ACKI(g_UsbDrvInfo.dma_port[ep_num - 1]);
	}
#endif

	/* the last one pkt length not multiple of MAX_PKT_LEN, clear corresponding bits*/
#if defined (DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)	
	if (g_UsbDrvInfo.dma_pktrdy[dma_chan - 1])
#else
	if (g_UsbDrvInfo.dma_pktrdy[ep_num - 1])
#endif		
	{
#if defined (DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
		if(g_UsbDrvInfo.dma_dir[dma_chan-1] != USB_EP_TX_DIR)
		{
			EXT_ASSERT(0, (kal_uint32)g_UsbDrvInfo.dma_dir[dma_chan-1], 0, 0);
		}
#else
		if(g_UsbDrvInfo.dma_dir[ep_num-1] != USB_EP_TX_DIR)
		{
			EXT_ASSERT(0, (kal_uint32)g_UsbDrvInfo.dma_dir[ep_num-1], 0, 0);
		}
#endif

	#if defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)||defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
		USB_HW_EP_Tx_Ready(ep_num, USB_ENDPT_BULK);
	#endif
	#if defined (DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
		g_UsbDrvInfo.dma_pktrdy[dma_chan - 1] = KAL_FALSE;
	#else
		g_UsbDrvInfo.dma_pktrdy[ep_num - 1] = KAL_FALSE;
	#endif
	#if defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)||defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
		/* polling the last packet*/
		while(USB_HW_Is_EP_Tx_Empty(ep_num, USB_ENDPT_BULK) == KAL_FALSE)
	#endif
		{
			/* check if other interrupt received*/
			g_UsbDrvInfo.is_unMaskUSB = KAL_FALSE;
		#ifdef	__OTG_ENABLE__
			OTG_Set_Intr();
		#endif	
			USB_HISR();
		}
	}
	else
	{
	}
	#if defined (DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
		g_UsbDrvInfo.dma_running[dma_chan - 1] = KAL_FALSE;
	#else
		g_UsbDrvInfo.dma_pktrdy[ep_num - 1] = KAL_FALSE;
	#endif
	return STATUS_OK;
}



static DCL_STATUS DCL_USB_CTRL_API_USB_Polling_Recv_Data(DCL_CTRL_DATA_T *data)
{
	g_UsbDrvInfo.is_unMaskUSB = KAL_FALSE;
#ifdef	__OTG_ENABLE__
	OTG_Set_Intr();
#endif
	USB_HISR();

	return STATUS_OK;
}



static DCL_STATUS DCL_USB_CTRL_API_USB_Clr_RX_EP_ISR(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	USB_DRV_CTRL_EP_COMMON_FUNC_T *dcl_data_ptr;
	kal_uint32 ep_num;


	dcl_data_ptr = &data->rUSB_Common_Struct;
	ep_num = (kal_uint32)dcl_data_ptr->u4ep_num;

	#if defined(DRV_USB_IP_V4)
	USB_DRV_WriteReg(USB_INTRRX, (0x01<<ep_num));// Write 1 clear
	#else
	USB_DRV_WriteReg(USB_INTRRX, ~(0x01<<ep_num));// Write 0 clear
	#endif
	return STATUS_OK;
#elif defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)
	USB_DRV_CTRL_EP_COMMON_FUNC_T *dcl_data_ptr;
	kal_uint32 ep_num;
	dcl_data_ptr = &data->rUSB_Common_Struct;
	ep_num = (kal_uint32)dcl_data_ptr->u4ep_num;

	g_UsbDrvInfo.IntrRx = USB_DRV_Reg8(USB_INTROUT1); 
	g_UsbDrvInfo.IntrRx &= ~(0x01<<ep_num);
	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Get_RX_EP_ISR_Status(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	USB_DRV_CTRL_EP_CTRL_FUNC_1_T *dcl_data_ptr;
	kal_bool result;
	kal_uint32 ep_num;


	dcl_data_ptr = &data->rEP_Ctrl_Func_1;
	ep_num = (kal_uint32)dcl_data_ptr->u4ep_num;


	if(USB_DRV_Reg(USB_INTRRX)&(0x01<<ep_num))
		result = KAL_TRUE;
	else
		result = KAL_FALSE;

	dcl_data_ptr->fg_result = (DCL_BOOL)result;
	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Read_TX_ISR_Status(DCL_CTRL_DATA_T *data)
{
#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	//EP0 handler receive another Setup packet,need to clear EP0 interrupt
	g_UsbDrvInfo.IntrTx = USB_DRV_Reg8(USB_INTRIN1);
	g_UsbDrvInfo.IntrTx &= ~USB_INTRIN1_EP0;
#endif
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Phy_Enable(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_PHY_FUNC_T *prphy_ctrl_func;
	USB_PHY_OWNER owner;


	prphy_ctrl_func = &data->rPhy_Ctrl_Func;
	owner = (USB_PHY_OWNER)prphy_ctrl_func->owner;
	USB_Phy_Enable(owner);
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Phy_Disable(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_PHY_FUNC_T *prphy_ctrl_func;
	USB_PHY_OWNER owner;


	prphy_ctrl_func = &data->rPhy_Ctrl_Func;
	owner = (USB_PHY_OWNER)prphy_ctrl_func->owner;
	USB_Phy_Disable(owner);
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_UART_Share(DCL_CTRL_DATA_T *data)
{
#if (defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__))
	DCL_BOOL *usb_data = (DCL_BOOL*)data;
	kal_bool usb_mode = (kal_bool)(*usb_data);


	USB_UART_Share(usb_mode);
	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Debug_Information(DCL_CTRL_DATA_T *data)
{
#if defined(__MTK_INTERNAL__)&& (defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4))
	USB_DRV_CTRL_EP_STALL_T *prctrl_ep_stall;
	kal_uint32 ep_num;
	USB_EP_DIRECTION direction;
	kal_bool check_error;
	kal_uint16   dma_ctrl;
	kal_uint16   dma_chan;
	kal_uint16   TXCSR,RXCSR;
	kal_uint8    OP_STATE,LINE_STATE,DMA_INTR;
	kal_uint32   DMA_Count,Real_Count;
#if (defined(DRV_USB_PHY_COST_DOWN))
	kal_uint32   UTMI_1,UTMI_2,UTMI_3,UTMI_4;
#endif

	prctrl_ep_stall = &data->rEP_Stall;
	ep_num = (kal_uint32)prctrl_ep_stall->u4ep_num;
	direction = (USB_EP_DIRECTION)prctrl_ep_stall->direction;
	check_error = (kal_bool)prctrl_ep_stall->fgen;


	//dma_chan = USB_Get_DMA_Channel_Num(ep_num, direction);
	dma_chan = g_UsbDrvInfo.dma_port[direction][ep_num-1];
	if((dma_chan == 0)||(dma_chan > MAX_DMA_NUM)||(ep_num == 0))
		return STATUS_FAIL;

	dma_ctrl = USB_DRV_Reg(USB_DMACNTL(dma_chan));

	if(check_error == KAL_TRUE)
	{
		if(direction == USB_EP_TX_DIR)
		{
			TXCSR = USB_DRV_Reg(USB_EPn_TXCSR(ep_num));
			drv_trace2(TRACE_FUNC, (kal_uint32)USB_TX_DEBUG, TXCSR,dma_ctrl);
			DMA_Count = USB_DRV_Reg(USB_DMACNT(dma_chan));
			Real_Count = USB_DRV_Reg(USB_DMA_REALCNT(dma_chan));
			drv_trace2(TRACE_FUNC, (kal_uint32)USB_DMA_DEBUG,DMA_Count,Real_Count);
			OP_STATE = USB_DRV_Reg8(USB_OPSTATE);
			LINE_STATE = USB_DRV_Reg8(USB_LINE_STATE);
			drv_trace2(TRACE_FUNC, (kal_uint32)USB_HW_State,OP_STATE,LINE_STATE);
#if defined(DRV_USB_IP_V3)
			DMA_INTR = USB_DRV_Reg8(USB_DMAINTR);
#elif defined(DRV_USB_IP_V4)
			DMA_INTR = USB_DRV_Reg8(USB_DMA_INTR_STATUS);
#endif
			drv_trace1(TRACE_FUNC, (kal_uint32)USB_DMA_HW_Intr, DMA_INTR);
#if (defined(DRV_USB_PHY_COST_DOWN))
			UTMI_1 = USB_DRV_Reg8(USB_PHYIR2_2);
			UTMI_2 = USB_DRV_Reg8(USB_PHYIR2_3);
			UTMI_3 = USB_DRV_Reg8(USB_PHYIR3_0);
			UTMI_4 = USB_DRV_Reg8(USB_PHYIR3_1);
			drv_trace4(TRACE_FUNC, (kal_uint32)USB_UTMI_SIGNAL,UTMI_1,UTMI_2,UTMI_3,UTMI_4);
#endif
		}
		else
		{
			RXCSR = USB_DRV_Reg(USB_EPn_RXCSR(ep_num));
			drv_trace2(TRACE_FUNC, (kal_uint32)USB_RX_DEBUG,RXCSR,dma_ctrl);
			DMA_Count = USB_DRV_Reg(USB_DMACNT(dma_chan));
			Real_Count = USB_DRV_Reg(USB_DMA_REALCNT(dma_chan));
			drv_trace2(TRACE_FUNC, (kal_uint32)USB_DMA_DEBUG,DMA_Count,Real_Count);
			OP_STATE = USB_DRV_Reg8(USB_OPSTATE);
			LINE_STATE = USB_DRV_Reg8(USB_LINE_STATE);
			drv_trace2(TRACE_FUNC, (kal_uint32)USB_HW_State,OP_STATE,LINE_STATE);
		}
	}
	else
	{
		if(direction == USB_EP_TX_DIR)
		{
			TXCSR = USB_DRV_Reg(USB_EPn_TXCSR(ep_num));
			drv_trace2(TRACE_FUNC, (kal_uint32)USB_TX_DEBUG, TXCSR, dma_ctrl);
		}
	}

	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USB_DUMP(DCL_CTRL_DATA_T *data)
{
#if defined(__MTK_INTERNAL__)&&(defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4))
	volatile kal_uint32 index;
////dump MAC all
	for(index =0;index<0x200;index++)
		drv_trace2(TRACE_INFO, (kal_uint32)USB_Register,0x0+index,USB_DRV_Reg8(USB_FADDR+index));

////check IN token: EP1 , DMA 1
 	USB_DRV_ClearBits(USB_DMACNTL(1),USB_DMACNTL_DMAEN);
 	USB_DRV_WriteReg8(USB_INDEX,1);
 	USB_DRV_WriteReg8(USB_TXCSR,USB_TXCSR_FLUSHFIFO);
 	USB_DRV_WriteReg8(USB_TXCSR,USB_TXCSR_FLUSHFIFO);

  for(index =0;index<1000;index++);

	drv_trace2(TRACE_INFO, (kal_uint32)USB_Register,0x112,USB_DRV_Reg(USB_TXCSR));

////Check DMA :
 	USB_DRV_WriteReg8(USB_DMACNT(1),0xFF);
	USB_DRV_SetBits(USB_DMACNTL(1),USB_DMACNTL_DMAEN);

 	for(index =0;index<1000;index++);

	drv_trace2(TRACE_INFO, (kal_uint32)USB_Register,0x112,USB_DRV_Reg8(USB_TXCSR));
	drv_trace2(TRACE_INFO, (kal_uint32)USB_Register,0x20C,USB_DRV_Reg(USB_DMACNT(1)));

	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Get_Total_FIFO_Size(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_GET_FIFO_SIZE_T *dcl_data_ptr = (USB_DRV_CTRL_GET_FIFO_SIZE_T*)data;

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	#ifdef  DRV_USB_COST_DOWN_CHIP
	dcl_data_ptr->fifo_size = DCL_USB_TOTAL_FIFO_SIZE_2304;
	#else
	dcl_data_ptr->fifo_size = DCL_USB_TOTAL_FIFO_SIZE_4096;
	#endif

	return STATUS_OK;
#else
	dcl_data_ptr->fifo_size = DCL_USB_TOTAL_FIFO_SIZE_NONE;
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Get_IP_Version(DCL_CTRL_DATA_T *data)
{
	USB_DRV_CTRL_GET_IP_VERSION_T *dcl_data_ptr = (USB_DRV_CTRL_GET_IP_VERSION_T*)data;

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	dcl_data_ptr->ip_version = DCL_USB_IP_V3;
#elif defined(DRV_USB_IP_V2)
	ASSERT(0);
#elif defined(DRV_USB_IP_V1)
	dcl_data_ptr->ip_version = DCL_USB_IP_V1;
#elif defined(DRV_USB_IP_V1_PLUS)
	dcl_data_ptr->ip_version = DCL_USB_IP_V1_PLUS;
#else
	ASSERT(0);
#endif

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_USB_Check_IC_DMA_Limit(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_DMA_BW_LIMIT)
	return STATUS_OK;
#else
	return STATUS_UNSUPPORTED;
#endif
}



static DCL_STATUS DCL_USB_CTRL_API_USB_Check_IC_Uart_Share_Pad(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_SHARE_PAD_UART_DL)
	return STATUS_OK;
#else
	return STATUS_UNSUPPORTED;
#endif
}

static DCL_STATUS DCL_USB_CTRL_API_Set_Menu_Config(DCL_CTRL_DATA_T *data)
{
#if !defined(__MEUT__) && !defined(__L1_STANDALONE__)
	kal_uint8	 nvram_buffer[NVRAM_EF_SYS_CACHE_OCTET_SIZE];

	USB_DRV_CTRL_SET* ptr_CDCACM_fun9;
	ptr_CDCACM_fun9 =  &(data->rComport_Ctrl_Fun9);
//	ptr_CDCACM_fun9->u2Retresult= (DCL_BOOL)USB_Set_RNDIS_Mode((kal_bool)ptr_CDCACM_fun9->u2set);					
	
	nvram_buffer[0] =(kal_uint8)ptr_CDCACM_fun9->u2set;
	nvram_external_write_data(NVRAM_EF_SYS_CACHE_OCTET_LID, NVRAM_SYS_USB_TETHERING_MODE, nvram_buffer, NVRAM_EF_SYS_CACHE_OCTET_SIZE);
	
	ptr_CDCACM_fun9->u2Retresult = (DCL_BOOL) KAL_TRUE;
#endif
	return STATUS_OK;
}

static DCL_STATUS DCL_USB_CTRL_API_Get_Menu_Config(DCL_CTRL_DATA_T *data)
{
#if !defined(__MEUT__) && !defined(__L1_STANDALONE__)
	kal_uint8 	nvram_buffer[NVRAM_EF_SYS_CACHE_OCTET_SIZE];

	DCL_BOOL *usb_data;
	usb_data = (DCL_BOOL *)data;
//	*usb_data = (DCL_BOOL)USB_Get_RNDIS_Mode(); 		
	 
	nvram_external_read_data(NVRAM_EF_SYS_CACHE_OCTET_LID,NVRAM_SYS_USB_TETHERING_MODE, nvram_buffer, NVRAM_EF_SYS_CACHE_OCTET_SIZE);

	if(nvram_buffer[0] == 0)
		*usb_data = (DCL_BOOL) KAL_FALSE;
	else
      	*usb_data = (DCL_BOOL) KAL_TRUE;
#endif
	return STATUS_OK;
}


static void USB_Remote_Wakeup_Time_Expired(void *parameter)
{
	USB_DRV_ClearBits8(USB_POWER, USB_POWER_RESUME);
	USB_GPTI_StopItem(g_usb_resume_gpt_handler);
	USB_GPTI_ReleaseHandle(&g_usb_resume_gpt_handler);
	
	{
		USB_DRV_SetBits8(USB_INTRUSBE, USB_INTRUSBE_SUSPEND);
		USB_Dbg_Trace(USB_REMOTE_WAKE_UP, USB_DRV_Reg8(USB_LINE_STATE), USB_DRV_Reg8(USB_OPSTATE));
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_IS_REMOTE_WAKEUP);
		g_UsbDrvInfo.suspend_with_FIFO_not_empty = KAL_FALSE;
		
		g_UsbDrvInfo.power_state = USB_STATE_NORMAL;
		g_UsbDrvInfo.suspend_count = 0;
		
		if((USB_DRV_Reg8(USB_POWER)&USB_POWER_HSMODE) != 0)
			g_UsbDrvInfo.Is_HS_mode = KAL_TRUE;
		else
			g_UsbDrvInfo.Is_HS_mode = KAL_FALSE;
		
		g_UsbDrvInfo.resume_hdlr();
	}
}

static DCL_STATUS DCL_USB_CTRL_API_USB_Remote_Wakeup(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_REMOTE_WAKEUP_SUPPORT)
	USB_GPTI_GetHandle(&g_usb_resume_gpt_handler);
	USB_GPTI_StartItem(g_usb_resume_gpt_handler, 1, USB_Remote_Wakeup_Time_Expired, NULL);
	USB_DRV_SetBits8(USB_POWER, USB_POWER_RESUME);
	return STATUS_OK;
#else
	return STATUS_UNSUPPORTED;
#endif
}

#if 0
/* under construction !*/
/* under construction !*/
	#if defined(MTK_SLEEP_ENABLE)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#else
/* under construction !*/
	#endif 
/* under construction !*/
#endif

DCL_USB_CTRL_API DCL_USB_DRV_API_T[] =
{
	DCL_USB_CTRL_API_USB_Init_Drv_Info,
	DCL_USB_CTRL_API_USB_ResetDrv_Info,
	DCL_USB_CTRL_API_USB_Register_Drv_Info,
	DCL_USB_CTRL_API_USB_Set_UnMask_Irq,
	DCL_USB_CTRL_API_USB_Get_UnMask_Irq,
	DCL_USB_CTRL_API_USB_Get_EP_Stall_Status,
	DCL_USB_CTRL_API_USB_Drv_Create_ISR,
	DCL_USB_CTRL_API_USB_Drv_Activate_ISR,
	DCL_USB_CTRL_API_USBDMA_Drv_Create_ISR,
	DCL_USB_CTRL_API_USBDMA_Drv_Activate_ISR,
	DCL_USB_CTRL_API_USB_PDNmode,
	DCL_USB_CTRL_API_USB_Pull_Up_DP_Line,
	DCL_USB_CTRL_API_USB_Set_DMA_Stop_Flag,
	DCL_USB_CTRL_API_USB_Reset_Drv,
	DCL_USB_CTRL_API_USB_Initialize_Drv_Phase1,
	DCL_USB_CTRL_API_USB_Initialize_Drv_Phase2,
	DCL_USB_CTRL_API_USB_Release_Drv,
	DCL_USB_CTRL_API_USB_SetAddress,
	DCL_USB_CTRL_API_USB_GetFrameCount,
	DCL_USB_CTRL_API_USB_TxEPInit,
	DCL_USB_CTRL_API_USB_RxEPInit,
	DCL_USB_CTRL_API_USB_TxEPEn,
	DCL_USB_CTRL_API_USB_TxEPDis,
	DCL_USB_CTRL_API_USB_RxEPEn,
	DCL_USB_CTRL_API_USB_RxEPDis,
	DCL_USB_CTRL_API_USB_Config_TxEP_Type,
	DCL_USB_CTRL_API_USB_Config_RxEP_Type,
	DCL_USB_CTRL_API_USB_TxEPClearDataTog,
	DCL_USB_CTRL_API_USB_RxEPClearDataTog,
	DCL_USB_CTRL_API_USB_TxEP_Usage,
	DCL_USB_CTRL_API_USB_RxEP_Usage,
	DCL_USB_CTRL_API_USB_TXEP_PK_SIZE,
	DCL_USB_CTRL_API_USB_RXEP_PK_SIZE,
	DCL_USB_CTRL_API_USB_EPFIFORead,
	DCL_USB_CTRL_API_USB_EPFIFOWrite,
	DCL_USB_CTRL_API_USB_CtrlEPStall,
	DCL_USB_CTRL_API_USB_Get_EP0_Status,
	DCL_USB_CTRL_API_USB_Update_EP0_State,
	DCL_USB_CTRL_API_USB_EP0_Pkt_Len,
	DCL_USB_CTRL_API_USB_EP_Bulk_Tx_Ready,
	DCL_USB_CTRL_API_USB_EP_Rx_Pkt_Len,
	DCL_USB_CTRL_API_USB_EP_Bulk_Rx_Ready,
	DCL_USB_CTRL_API_USB_Is_EP_Bulk_Tx_Empty,
	DCL_USB_CTRL_API_USB_Is_EP_Bulk_Rx_Empty,
	DCL_USB_CTRL_API_USB_Clear_Tx_EP_FIFO,
	DCL_USB_CTRL_API_USB_Clear_Rx_EP_FIFO,
	DCL_USB_CTRL_API_USB_Get_DMA_Channel,
	DCL_USB_CTRL_API_USB_Stop_DMA_Channel,
	DCL_USB_CTRL_API_USB_Free_DMA_Channel,
	DCL_USB_CTRL_API_USB_DMA_Setup,
	DCL_USB_CTRL_API_USB_DMA_Get_Run_Status,
	DCL_USB_CTRL_API_USB_DMA_Set_Run_Status,
	DCL_USB_CTRL_API_USB_Enable_DMA_Timer_Count,
	DCL_USB_CTRL_API_USB_Check_DMA_Time_Out,
	DCL_USB_CTRL_API_USB_Get_DMA_Real_Count,
	DCL_USB_CTRL_API_USB_Set_DMA_Limiter,
	DCL_USB_CTRL_API_USB_Switch_DMA_Burst_mode,
	DCL_USB_CTRL_API_USB_Register_DMA_Channel,
	DCL_USB_CTRL_API_USB_Set_DMA_Burst_Mode,
	DCL_USB_CTRL_API_USB_Is_High_Speed,
	DCL_USB_CTRL_API_USB_Enter_Test_Mode,
	DCL_USB_CTRL_API_USB_Reset_FIFO,
	DCL_USB_CTRL_API_USB_FIFO_Not_Empty,
	DCL_USB_CTRL_API_USB_Is_Suspend_Power_Status,
	DCL_USB_CTRL_API_USB_Polling_Transmit_Done,
	DCL_USB_CTRL_API_USB_Polling_Recv_Data,
	DCL_USB_CTRL_API_USB_Clr_RX_EP_ISR,
	DCL_USB_CTRL_API_USB_Get_RX_EP_ISR_Status,
	DCL_USB_CTRL_API_USB_Read_TX_ISR_Status,
	DCL_USB_CTRL_API_USB_Phy_Enable,
	DCL_USB_CTRL_API_USB_Phy_Disable,
	DCL_USB_CTRL_API_USB_UART_Share,
	DCL_USB_CTRL_API_USBDL_Update_USB_Download_Mode,
	DCL_USB_CTRL_API_USBDL_Is_USB_Download_Mode,
	DCL_USB_CTRL_API_USB_Debug_Information,
	DCL_USB_CTRL_API_USB_DUMP,
	DCL_USB_CTRL_API_USB_Get_Total_FIFO_Size,
	DCL_USB_CTRL_API_USB_Get_IP_Version,
	DCL_USB_CTRL_API_USB_Check_IC_DMA_Limit,
	DCL_USB_CTRL_API_USB_Check_IC_Uart_Share_Pad,
	DCL_USB_CTRL_API_USBDL_Is_USB_Fast_Meta_Mode,
	DCL_USB_CTRL_API_Set_Menu_Config,
	DCL_USB_CTRL_API_Get_Menu_Config,	
	DCL_USB_CTRL_API_USB_Remote_Wakeup, 
};



/*************************************************************************
* FUNCTION
*  DclUSB_DRV_Control
*
* DESCRIPTION
*  This function is to send command to control the USB module.
*
* PARAMETERS
*  handle: A valid handle return by DclUSB_DRV_Open()
*  cmd: A control command for USB module
// Should be added
*
*  data: The data of the control command
// Should be added
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
DCL_STATUS DclUSB_DRV_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	/* Check open or not and handle validity */
	if((g_USB_Drv_Open == KAL_FALSE)||(DCL_USB_DRV_CHECK_HANDLE_IS_VALID(handle) == 0))
		ASSERT(0);

	if (cmd > USB_CLASS_CMD_START)
	{
		if ((cmd > USB_VIDEO_CLASS_START)&&(cmd < USB_VIDEO_CLASS_END))
			USB_Class_Driver[USB_VIDEO_CLASS_CODE](cmd,data);
			
		if ((cmd > USB_IMAGE_CLASS_START)&&(cmd < USB_IMAGE_CLASS_END))
			USB_Class_Driver[USB_IMAGE_CLASS_CODE](cmd,data);
	}		
	else
	{
		return DCL_USB_DRV_API_T[cmd](data);
	}
	
	return STATUS_OK;
}


/************************************************************
	Charger detection
*************************************************************/

kal_bool USB_Check_DM_Value_Is_High(void)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
#if (defined(DRV_USB_PHY_COST_DOWN))
	if((USB_DRV_Reg8(USB_LINE_STATE)&USB_PHYIR3_0_LINESTATE_DM) != 0)
#elif (defined(DRV_USB_PHY_U65_IP))
	#if defined(DRV_USB_IP_V3)
	USB_DRV_Reg8(USB_DUMMY);
	#endif
	if((USB_DRV_Reg8(USB_LINE_STATE)&USB_U2PHYDMON0_2_LINESTATE_DM) != 0)
#elif (defined(DRV_USB_PHY_M60_IP))
	#if defined(DRV_USB_IP_V3)
	USB_DRV_Reg8(USB_DUMMY);
	#endif
	if((USB_DRV_Reg32(USB_LINE_STATE)&USB_U2PHYDMON1_USB20_LINE_STATE_DM) != 0)
#elif (defined(DRV_USB_PHY_U40_IP))
	if (0)
#elif (defined(DRV_USB_PHY_T28_IP))
	if (0)
#else    //Old PHY version
	if((USB_DRV_Reg8(USB_LINE_STATE)&USB_PHYIR1_3_LINESTATE_DM) != 0)
#endif
		return KAL_TRUE;
	else
		return KAL_FALSE;
#elif defined(DRV_USB_IP_V1_PLUS)
  #if defined(DRV_USB_PHY_T55_IP)
    return KAL_FALSE;
  #else
	if((USB_DRV_Reg8(USB_U1PHYCR2_1)&USB_U1PHYCR2_1_AD_USB11_RXM) != 0)
		return KAL_TRUE;
	else
		return KAL_FALSE;
	#endif	
#endif //defined(DRV_USB_IP_V1_PLUS)
}

kal_bool USB_Check_DP_Value_Is_High(void)
{
#if	defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
#if (defined(DRV_USB_PHY_COST_DOWN))
	if((USB_DRV_Reg8(USB_LINE_STATE)&USB_PHYIR3_0_LINESTATE_DP) != 0)
#elif (defined(DRV_USB_PHY_U65_IP))
	#if defined(DRV_USB_IP_V3)
	USB_DRV_Reg8(USB_DUMMY);
	#endif
	if((USB_DRV_Reg8(USB_LINE_STATE)&USB_U2PHYDMON0_2_LINESTATE_DP) != 0)
#elif (defined(DRV_USB_PHY_M60_IP))
	#if defined(DRV_USB_IP_V3)
	USB_DRV_Reg8(USB_DUMMY);
	#endif
	if((USB_DRV_Reg32(USB_LINE_STATE)&USB_U2PHYDMON1_USB20_LINE_STATE_DP) != 0)
#elif (defined(DRV_USB_PHY_U40_IP))
	if (0)
#elif (defined(DRV_USB_PHY_T28_IP))
	if (0)		
#else    //Old PHY version
	if((USB_DRV_Reg8(USB_LINE_STATE)&USB_PHYIR1_3_LINESTATE_DP) != 0)
#endif
		return KAL_TRUE;
	else
		return KAL_FALSE;
#elif defined(DRV_USB_IP_V1_PLUS)
  #if defined(DRV_USB_PHY_T55_IP)
    return KAL_FALSE;
  #else
	if((USB_DRV_Reg8(USB_U1PHYCR2_1)&USB_U1PHYCR2_1_AD_USB11_RXP) != 0)
		return KAL_TRUE;
	else
		return KAL_FALSE;
	#endif	  
#endif //defined(DRV_USB_IP_V1_PLUS)
}


#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__

/* After Charger EINT, BMT call this function to pull high D- 100k, remove DP/DM 15K to ground */
void USB_Charger_Detect_Init(void)
{
#if (defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4))&&defined(__OTG_ENABLE__)
	/* During SRP then return directly */
	if(OTG_Is_B_Process_SRP() == KAL_TRUE)
		return;
#endif
	UPLL_Enable(UPLL_OWNER_USB);
	/* usb.lib is secondary MAUI, and drv.lib is the primary MAUI.
	So usb_drv.c cannot use usb folder's API */
//	USB_Dbg_Trace(USB_SET_PDN_FLAG_TRUE, 1, 0);
#if defined(__USB_BOOTUP_TRACE__)
	if (is_init_log_enable == KAL_FALSE)
#endif
	{

		if(PDN_USB_flag == KAL_TRUE)
			ASSERT(0);
		PDN_USB_flag = KAL_TRUE;
		/* Open AHB clock, then we can set USB IP's registers */
#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)
	PDN_CLR(PDN_USB);
#else
	#if defined(__OLD_PDN_ARCH__)
	#if defined(__OLD_PDN_DEFINE__)
			USB_DRV_WriteReg(DRVPDN_CON0_CLR, DRVPDN_CON0_USB);
	#elif defined(__CLKG_DEFINE__)
			USB_DRV_WriteReg(CG_CLR0, CG_CON0_USB);
	#endif
	#else
	//		DRVPDN_Disable(PDN_USB);	
		PDN_CLR(PDN_USB); //power up dev
		USB_SleepEnable(KAL_FALSE);
	#endif
#endif
		
	
#if (defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4))&&defined(DRV_USB_PHY_CURRENT_CONSUMPTION)
		USB_Recover_Current_Consumption();
#endif
		}
		
#if (defined(DRV_USB_IP_V3)&&(defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__)))
	USB_UART_Share(KAL_TRUE);
#endif
	USB_PHY_Charger_Detect_Init();
}


kal_bool USB_Detect_Is_Charger_In(void)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
#ifdef __OTG_ENABLE__
	if(OTG_Is_B_Process_SRP() == KAL_TRUE)
		return KAL_FALSE;
#endif
#endif //(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	return USB_Check_DM_Value_Is_High();
}


/* BMT already know charger in, need to differentiate standard or not-standard charger */
void USB_Check_Standard_Charger(void)
{
	USB_PHY_Check_Standard_Charger();
}


kal_bool USB_Detect_Is_Standard_Charger_In(void)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
#if (defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__))
	USB_UART_Share(KAL_FALSE);
#endif
#endif
	return USB_Check_DM_Value_Is_High();
}


void USB_Charger_Detect_Release(void)
{
#if (defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4))&&defined(__OTG_ENABLE__)
	if(OTG_Is_B_Process_SRP() == KAL_TRUE)
		return;
#endif //(defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4))&&defined(__OTG_ENABLE__)

	USB_PHY_Charger_Detect_Release();

#if (defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4))&&defined(DRV_USB_PHY_CURRENT_CONSUMPTION)
	USB_Save_Current_Consumption();
#endif //(defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4))&&defined(DRV_USB_PHY_CURRENT_CONSUMPTION)

#if defined(DRV_USB_POWER_DOWN_SUPPORT)&&defined(MTK_SLEEP_ENABLE)
	PDN_SET(PDN_USB);
#else
	#if defined(__OLD_PDN_ARCH__)
	#if defined(__OLD_PDN_DEFINE__)
		USB_DRV_WriteReg(DRVPDN_CON0_SET, DRVPDN_CON0_USB);
	#elif defined(__CLKG_DEFINE__)
		USB_DRV_WriteReg(CG_SET0, CG_CON0_USB);
	#endif
	#else
		//	DRVPDN_Enable(PDN_USB);	
		PDN_SET(PDN_USB); //power down dev
		USB_SleepEnable(KAL_TRUE); //unlock sleep mode
	#endif
#endif
	PDN_USB_flag = KAL_FALSE;
	/* usb.lib is secondary MAUI, and drv.lib is the primary MAUI.
	So usb_drv.c cannot use usb folder's API */
//	USB_Dbg_Trace(USB_SET_PDN_FLAG_FALSE, 1, 0);
	UPLL_Disable(UPLL_OWNER_USB);
}

#endif  /* __CHARGER_USB_DETECT_WIHT_ONE_EINT__ */


#else  /* #if defined(__USB_ENABLE__) && !defined(DRV_USB_OFF) */


DCL_STATUS DclUSB_DRV_Initialize(void)
{
	return STATUS_OK;
}


DCL_HANDLE DclUSB_DRV_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	return (DCL_HANDLE)DCL_HANDLE_NONE;
}


DCL_STATUS DclUSB_DRV_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}


DCL_STATUS DclUSB_DRV_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}


DCL_STATUS DclUSB_DRV_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}


DCL_STATUS DclUSB_DRV_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, DCL_UINT8 index,void *class_handler)
{
	return STATUS_UNSUPPORTED;
}


DCL_STATUS DclUSB_DRV_Close(DCL_HANDLE handle)
{
	return STATUS_OK;
}


DCL_STATUS DclUSB_DRV_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	switch(cmd)
	{
		case USB_DRV_CMD_PDN_ENABLE:
			DCL_USB_CTRL_API_USB_PDNmode(data);
			break;

		case USB_DRV_CMD_USBDL_UPDATE_USB_DL_MODE:
			DCL_USB_CTRL_API_USBDL_Update_USB_Download_Mode(data);
			break;

		case USB_DRV_CMD_USBDL_IS_USB_DL_MODE:
			DCL_USB_CTRL_API_USBDL_Is_USB_Download_Mode(data);
			break;

		case USB_DRV_CMD_USBDL_IS_USB_FAST_META_MODE:
			DCL_USB_CTRL_API_USBDL_Is_USB_Fast_Meta_Mode(data);
			break;

		default:
			ASSERT(0);
			break;
	}

	return STATUS_OK;
}


#endif /* #if defined(__USB_ENABLE__) && !defined(DRV_USB_OFF) */

static void USB_SleepEnable(kal_bool islock)
{
#if defined(MTK_SLEEP_ENABLE)
	if (usb_pdn_handle == 0)
	{
		usb_pdn_handle = L1SM_GetHandle();
	}	
	if(islock == KAL_FALSE)
 		L1SM_SleepDisable(usb_pdn_handle);
	else
		L1SM_SleepEnable(usb_pdn_handle);
#endif
}


/************************************************************
	Functions that is used whether USB_ENABLE is turned on or not
*************************************************************/

static DCL_STATUS DCL_USB_CTRL_API_USB_PDNmode(DCL_CTRL_DATA_T *data)
{
#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)||defined(DRV_USB_IP_V2)||defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4))
	DCL_BOOL *dcl_data_ptr = (DCL_BOOL*)data;
	kal_bool pdn_en = (kal_bool)(*dcl_data_ptr);
	volatile kal_uint32 delay;


	if(pdn_en == KAL_TRUE)
	{
		/* Power down */
		IRQMask(IRQ_USB_CODE);
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
		#if defined(DRV_USB_IP_V3)
		IRQMask(IRQ_USBDMA_CODE);
		#endif

		USB_DRV_ClearBits8(USB_POWER, USB_POWER_SOFTCONN);

//use UTMI to remove PHY 45 ohm resistor
#if (defined(DRV_USB_PHY_COST_DOWN))
 		//reg[60B] bit 3,1,0  = 1
		USB_DRV_SetBits8(USB_PHYCR3_3, (USB_PHYCR3_3_FORCE_XCVR_SELECT|USB_PHYCR3_3_FORCE_TERM_SELECT|USB_PHYCR3_3_FORCE_OP_MODE));
		//reg[613]  bit[2:0] = 101 , bit[5:4] = 01
		USB_DRV_ClearBits8(USB_PHYCR5_3,0x37);
#if defined(DRV_MT6236_VERSION_CONTROL)
		USB_DRV_SetBits8(USB_PHYCR5_3, (USB_PHYCR5_3_XCVR_SELECT_L|USB_PHYCR5_3_TERM_SELECT|USB_PHYCR5_3_OP_MODE));
#else
		USB_DRV_SetBits8(USB_PHYCR5_3, (USB_PHYCR5_3_XCVR_SELECT_L|USB_PHYCR5_3_TERM_SELECT|USB_PHYCR5_3_OP_MODE|USB_PHYCR5_3_SUSPENDM));
#endif

#elif (defined(DRV_USB_PHY_U65_IP))

//		USB_DRV_ClearBits8(USB_U2PHYDTM0_0,USB_U2PHYDTM0_0_RG_SUSPENDM);
//		USB_DRV_SetBits8(USB_U2PHYDTM0_2,USB_U2PHYDTM0_2_FORCE_SUSPENDM);

//		for(delay=0; delay <10; delay++) ; /* wait for stable*/

//		USB_DRV_ClearBits8(USB_U2PHYAC0_0,(USB_U2PHYAC0_0_RG_BGR_BGR_EN|USB_U2PHYAC0_0_RG_BGR_ISRC_EN|USB_U2PHYAC0_0_RG_BGR_CHP_EN));
#elif (defined(DRV_USB_PHY_M60_IP))

#elif (defined(DRV_USB_PHY_U40_IP))

#elif (defined(DRV_USB_PHY_T28_IP))

#else //Old PHY version
    //reg[612] bit 3,1,0  = 1
		USB_DRV_SetBits8(USB_PHYCR5_2, (USB_PHYCR5_2_FORCE_XCVR_SELECT|USB_PHYCR5_2_FORCE_TERM_SELECT|USB_PHYCR5_2_FORCE_OP_MODE));
		//reg[613]  bit[2:0] = 101 , bit[5:4] = 01
		USB_DRV_ClearBits8(USB_PHYCR5_3,0x37);
		USB_DRV_SetBits8(USB_PHYCR5_3, (USB_PHYCR5_3_XCVR_SELECT_L|USB_PHYCR5_3_TERM_SELECT|USB_PHYCR5_3_OP_MODE));
#endif   //use UTMI to remove PHY 45 ohm resistor
		USB_DRV_WriteReg(USB_INTRTXE, 0);
		USB_DRV_WriteReg(USB_INTRRXE, 0);
		USB_DRV_WriteReg8(USB_INTRUSBE, 0);

	#ifdef __OTG_ENABLE__
		if(((USB_DRV_Reg8(USB_DEVCTL)&USB_DEVCTL_SESSION) != 0)&&(USB_DRV_Reg8(USB_OPSTATE) == 0x21))
		{
			USB_DRV_WriteReg8(USB_DEVCTL, 0x00);

			delay = 0;

#if (defined(DRV_USB_PHY_COST_DOWN))
			while((USB_DRV_Reg8(USB_PHYIR3_1) != USB_PHYIR3_1_SESSEND)&&(delay <= 40))
#elif (defined(DRV_USB_PHY_U65_IP))
			#if defined(DRV_USB_IP_V3)
			USB_DRV_Reg8(USB_DUMMY);
			#endif
			while((USB_DRV_Reg8(USB_U2PHYDTM1_0) != USB_U2PHYDTM1_0_RG_SESSEND)&&(delay <= 40))
#elif (defined(DRV_USB_PHY_M60_IP))
#elif (defined(DRV_USB_PHY_U40_IP))
#elif (defined(DRV_USB_PHY_T28_IP))

#else //Old PHY version
			while((USB_DRV_Reg8(USB_PHYIR2_0) != USB_PHYIR2_0_SESSEND)&&(delay <= 40))
#endif
			{
				delay++;

				if(kal_if_hisr() == KAL_FALSE)
				{
					kal_sleep_task(1);
				}
			}

			if(delay == 41)
			{
				drv_trace0(TRACE_FUNC, (kal_uint32)USB_PDN_LOOP_FAIL);
			}
		}
	#endif

		USB_DRV_Reg8(USB_INTRUSB);
		USB_DRV_Reg(USB_INTRTX);
		
		#if defined(DRV_USB_IP_V4)
		USB_DRV_WriteReg(USB_INTRRX, 0xFFFF); // write 1 clear
		#else
		USB_DRV_WriteReg(USB_INTRRX, 0); // write 0 clear
		#endif

#if (defined(DRV_USB_PHY_CURRENT_CONSUMPTION) && (defined(__USB_ENABLE__) && !defined(DRV_USB_OFF)))
		USB_Save_Current_Consumption();
#endif

#if (defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__))
		USB_UART_Share(KAL_FALSE);
#endif

#else /* defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4) */

		/* disable sequence:1. GPIO(D+), 2. USB(USB register), 3. PDN_USB(USB power), 4. UPLL */
	#if defined(__USB_ENABLE__) && !defined(DRV_USB_OFF)
		USB_Phy_Disable(USB_PHY_OWNER_USB);
	#endif //(__USB_ENABLE__) && !defined(DRV_USB_OFF)

	#if defined(DRV_USB_IP_V2)
		USB_DRV_WriteReg8(USB_CTL, 0x00);
		USB_DRV_WriteReg8(USB_INT_ENB, 0x00);
		USB_DRV_WriteReg8(OTG_INT_EN, 0x00);
		USB_DRV_WriteReg8(USB_SOFT_RST, VUSB_SOFT_RST_EN);
		for(delay=0;delay<10;delay++) ; /* wait for stable*/

	#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))

		#if (defined(DRV_USB_PHY_U65_IP)) //MT6251 = MAC (IP_Plus) + PHY (unit PHY IP)
		USB_DRV_ClearBits8(USB_U1PHYCR0_1, USB_U1PHYCR0_1_RG_USB11_FSLS_ENBGRI);
		USB_DRV_ClearBits8(USB_PHY_CONTROL, USB_PHY_CONTROL_PUB);
		#elif (defined(DRV_USB_PHY_T55_IP))
		USB_DRV_ClearBits32(USB_U1PHYCR1, U1PHYCR1_RG_USB11_PHY_REV_7);		
		USB_DRV_ClearBits32(USB_U1PHYCR0, U1PHYCR0_RG_USB11_FSLS_ENBGRI);  		
		USB_DRV_ClearBits8(USB_PHY_CONTROL, USB_PHY_CONTROL_PUB);
		#else  //DRV_USB_IP_V1
		USB_DRV_WriteReg8(USB_ENABLE, USB_ENABLE_DIS);
		#endif

	#endif

		USB_PDNEnable();
		UPLL_Disable(UPLL_OWNER_USB);
#endif

#if !defined(DRV_USB_SUPPORT_DCM) && defined(DCM_ENABLE)
		/* Prevent from USB cable have been plugged out before configuring any USB type */
		if(g_usb_dcm_handle != 255)
		{
			DCM_Enable(g_usb_dcm_handle);
		}
#endif
	}
	else
	{
#if !defined(DRV_USB_SUPPORT_DCM) && defined(DCM_ENABLE)
		if(g_usb_dcm_handle == 255)
		{
			g_usb_dcm_handle = DCM_GetHandle();

			if(g_usb_dcm_handle == 255)
				EXT_ASSERT(0, (kal_uint32)g_usb_dcm_handle, 0, 0);
		}
		DCM_Disable(g_usb_dcm_handle);
#endif

		/* Enable sequence: 1. UPLL, 2.PDN_USB(USB power), 3.USB(USB register), 4.GPIO(D+) */
		UPLL_Enable(UPLL_OWNER_USB);
		for(delay = 0; delay < 3500; delay++) ; /* wait for power stable */
		USB_PDNDisable();

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)

#if (defined(DRV_USB_PHY_CURRENT_CONSUMPTION) && (defined(__USB_ENABLE__) && !defined(DRV_USB_OFF)))
		USB_Recover_Current_Consumption();
#endif

#if (defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__))
		USB_UART_Share(KAL_TRUE);
#endif

#if (defined(__USB_ENABLE__) && !defined(DRV_USB_OFF))
		USB_PHY_Initialize();
#endif //(defined(__USB_ENABLE__) && !defined(DRV_USB_OFF))

#if defined(DRV_USB_PHY_CALIBRATION) && defined(__USB_ENABLE__) && !defined(DRV_USB_OFF)
		USB_SR_Calibration();
#endif

		USB_DRV_WriteReg(USB_INTRTXE, 0);
		USB_DRV_WriteReg(USB_INTRRXE, 0);
		USB_DRV_WriteReg8(USB_INTRUSBE, 0);

		USB_DRV_Reg8(USB_INTRUSB);
		USB_DRV_Reg(USB_INTRTX);
		#if defined(DRV_USB_IP_V4)
		USB_DRV_WriteReg(USB_INTRRX, 0xFFFF); // write 1 clear
		#else
		USB_DRV_WriteReg(USB_INTRRX, 0); // write 0 clear
		#endif
		USB_DRV_WriteReg8(USB_DEVCTL, 0x00);
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
		// clear interrupt before previous power down PDN, the interrupts are read then clear
		USB_DRV_Reg8(USB_INTRUSB);
		USB_DRV_Reg8(USB_INTRIN1);
		USB_DRV_Reg8(USB_INTROUT1);

	#if (defined(DRV_USB_PHY_U65_IP)) //MT6251 = MAC (IP_Plus) + PHY (unit PHY IP)
		USB_DRV_SetBits8(USB_U1PHYCR1_1, USB_U1PHYCR1_1_RG_USB11_USBRESERVED); // USB PHY switch to USB1.1
		USB_DRV_ClearBits8(USB_U1PHYCR1_1, USB_U1PHYCR1_1_RG_USB11_USBRESERVED_PMU); // USB PHY switch : turn off PMU
		USB_DRV_SetBits8(USB_U1PHYCR0_1, USB_U1PHYCR0_1_RG_USB11_FSLS_ENBGRI); // USB PHY BIAS Current control
	#elif (defined(DRV_USB_PHY_T55_IP))	
		USB_DRV_ClearBits32(USB_U1PHYCR1, U1PHYCR1_RG_USB11_PHY_REV_7);
		USB_DRV_SetBits32(USB_U1PHYCR0, U1PHYCR0_RG_USB11_FSLS_ENBGRI);  
		for(delay = 0; delay < 1000; delay++);	  
	#else
		USB_DRV_WriteReg8(USB_ENABLE, USB_ENABLE_EN);
	#endif
#endif
	}

	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USBDL_Update_USB_Download_Mode(DCL_CTRL_DATA_T *data)
{
#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)||defined(DRV_USB_IP_V2)||defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4))
#if !defined(DRV_USB_OFF)
	#ifdef __MTK_TARGET__
  USB_Fast_Meta_mode = (kal_bool)INT_GetSysStaByCmd(CHK_FAST_META, NULL);
	#endif /* __MTK_TARGET__ */

#if defined(__USB_BOOTUP_TRACE__)
	if (is_init_log_enable == KAL_TRUE && is_init_stage == KAL_TRUE)
	{
		USBDL_mode = KAL_FALSE;
		return STATUS_OK;
	}
#endif
		
#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V2))
	/* Use a trick, if PC jump from bootloader to MAUI, and want to go into factory mode,
	 * then USB power down should be disable already
	 */
#if defined(__CLKG_DEFINE__)
	if((USB_DRV_Reg(CG_CON0)&CG_CON0_USB) == 0)
#else
	if((USB_DRV_Reg(DRVPDN_CON0)&DRVPDN_CON0_USB) == 0)
#endif
#elif defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	//if USB & UART share pad, we will open USB power in bootrom.
	// USB IP V3 use soft-connect to distinguish USB COM Port setup or not
	if (USB_DRV_Reg8(USB_POWER)&USB_POWER_SOFTCONN)
#elif defined(DRV_USB_IP_V1_PLUS)
  #if defined(DRV_USB_PHY_T55_IP)
    if ((USB_DRV_Reg8(USB_PHY_CONTROL)&USB_PHY_CONTROL_PUB)&&(USB_DRV_Reg32(USB_U1PHYCR0)&U1PHYCR0_RG_USB11_FSLS_ENBGRI))
  #else
	if ((USB_DRV_Reg8(USB_PHY_CONTROL)&USB_PHY_CONTROL_PUB)&&(USB_DRV_Reg8(USB_U1PHYCR0_1)&USB_U1PHYCR0_1_RG_USB11_FSLS_ENBGRI))
	#endif	
#else
	if(0)
#endif
		USBDL_mode = KAL_TRUE;
	else
		USBDL_mode = KAL_FALSE;
#endif /*!defined(DRV_USB_OFF) */

	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_USBDL_Is_USB_Download_Mode(DCL_CTRL_DATA_T *data)
{
	DCL_BOOL *usb_data;


	usb_data = (DCL_BOOL *)data;
#ifndef __USB_ENABLE__
	USBDL_mode = KAL_FALSE;
#endif
	*usb_data = (DCL_BOOL)USBDL_mode;
	return STATUS_OK;
}

static DCL_STATUS DCL_USB_CTRL_API_USBDL_Is_USB_Fast_Meta_Mode(DCL_CTRL_DATA_T *data)
{
	DCL_BOOL *usb_data;


	usb_data = (DCL_BOOL *)data;
#ifndef __USB_ENABLE__
	USB_Fast_Meta_mode = KAL_FALSE;
#endif
	*usb_data = (DCL_BOOL)USB_Fast_Meta_mode;
	return STATUS_OK;
}

void USB_EP_Bulk_HW_TxPktRdy_Enable(kal_uint32 ep_num, kal_bool enable)
{
#if defined(DRV_USB_IP_V4)
	kal_uint32 savedMask;
	
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	DRV_WriteReg(USB_TXCSR, USB_DMA_TX_CSR);		
	RestoreIRQMask(savedMask);		
	if(enable == KAL_TRUE)
	{
		USB_DRV_SetBits32((USB_HWTPR_EN), (1<<ep_num));
	}
	else
	{
		USB_DRV_ClearBits32((USB_HWTPR_EN), (1<<ep_num));
	}
	
#else
	ASSERT(0);
#endif
}

kal_uint32 USB_EP_Bulk_HW_FIFO_Addr(kal_uint32 ep_num)
{
#if defined(DRV_USB_IP_V4)
	return (USB_EP0 + ep_num*4);
#else
	ASSERT(0);
#endif
}

kal_uint32 USB_EP_Bulk_HW_TxPktRdy_Addr(void)
{
#if defined(DRV_USB_IP_V4)
	return (USB_HWTPR);
#else
	ASSERT(0);
#endif
}

void USB_EP_Bulk_HW_Set_TxPktRdy(kal_uint32 ep_num)
{
#if defined(DRV_USB_IP_V4)
	USB_DRV_SetBits32((USB_HWTPR), (1<<ep_num));
#else
	ASSERT(0);
#endif
}
