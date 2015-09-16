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
 *   brom_u3mac_reg.h
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *	This is the MT7208 USB3.0 hardware register definition head file.
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 ****************************************************************************/
 
#ifndef __BROM_U3MAC_REG_H__
#define __BROM_U3MAC_REG_H__

#include "reg_base.h"
#include "brom_irqid.h"
#include "kal_general_types.h" 


#define U3_VER_20121228_LATER
#define U3_DUAL_MODE_IP
#define U3_VER_20120720_LATER
#define FPGA_20120827_PATCH_ISSUE
#define FPGA_VER_20120927_LATER
//#define FPGA_20120814_PATCH_ISSUE
//#define U3_VER_TCM_ISSUE_FIXED
//#define U3_VER_20120618_LATER

#ifdef FPGA_VER_20120927_LATER
#define U3_MAC_REF_CLK		26*1000*1000 	// 26MB for MT7208
#define U3_MAC_REF_CLK_MHZ	26				// 26MB for MT7208
#define U3_P3_LFPS_REF_CLK_CNT	8 //the 300ns LFPS counter with ref_clk, about 230ns, set less for good compatibility
#else /*FPGA_VER_20120927_LATER*/
#define U3_MAC_REF_CLK		13*1000*1000 	// 13MB for MT7208
#define U3_MAC_REF_CLK_MHZ	13				// 13MB for MT7208
#define U3_P3_LFPS_REF_CLK_CNT	7 //the 300ns LFPS counter with ref_clk, about 269ns, set less for good compatibility
#endif
#ifdef FPGA_20120814_PATCH_ISSUE
/*FPGA 20120814 sys_clk = 125, should be 62.5 for following FPGA/ASIC mode*/
#define U3_MAC_SYS_CLK_1US_CNT		125//125MHz
#else /*FPGA_20120814_PATCH_ISSUE*/
#define U3_MAC_SYS_CLK_1US_CNT		63//62.5MHz
#endif


#define U3MAC_BASE	BASE_MADDR_U3MAC
#define U3MAC_IRQ	MD_IRQID_USB3

#define U3MAC_MAX_TXEP_NUM		6
#define U3MAC_MAX_RXEP_NUM		3
#define U3MAC_MAX_TXQ_NUM		6
#define U3MAC_MAX_RXQ_NUM		3
#define U3MAC_MAX_DMACH_NUM		8
#define U3MAC_MAX_FIFO_SIZE		(1024*8)
#define U3MAC_HS_FS_EP0_MPS		(64)
#define U3MAC_SS_EP0_MPS		(512)


/*
 *	normal register access
*/
#define USBReg_Write8(addr,data)	\
	(*((volatile kal_uint8 *)(addr))) = data

#define USBReg_Write16(addr,data)	\
	(*((volatile kal_uint16 *)(addr))) = data

#define USBReg_Write32(addr,data)	\
	(*((volatile kal_uint32 *)(addr))) = data

#define USBReg_Read8(addr)	\
	*(volatile kal_uint8 *)(addr)

#define USBReg_Read16(addr)	\
	*(volatile kal_uint16 *)(addr)

#define USBReg_Read32(addr)	\
	*(volatile kal_uint32 *)(addr)


#ifdef U3_DUAL_MODE_IP
#define SSUSB_DEV_OFFSET 		0x1000
#define SSUSB_EPCTL_OFFSET		0x1800
#define SSUSB_U2_MAC_OFFSET		0x3400
#define SSUSB_U3_SYS_OFFSET		0x2400
#define SSUSB_U3_MAC_OFFSET		0x2400
#else /*U3_DUAL_MODE_IP*/
#define SSUSB_DEV_OFFSET 		0x0000
#define SSUSB_EPCTL_OFFSET		0x1800
#define SSUSB_U2_MAC_OFFSET		0x1A00
#define SSUSB_U3_SYS_OFFSET		0x1C00
#define SSUSB_U3_MAC_OFFSET		0x1C00
#endif /*U3_DUAL_MODE_IP*/

#ifndef U3_DUAL_MODE_IP
/*SSUSB_DEVICE group*/
#define SSUSB_DEV_BASE   			(U3MAC_BASE + 0x0000)
#define U3_DEV_HW_VER				(SSUSB_DEV_BASE + 0x0000)
#define U3_DEV_EP0_FFSZ				(SSUSB_DEV_BASE + 0x0004)
#define U3_DEV_TXEP_FFSZ			(SSUSB_DEV_BASE + 0x0008)
#define U3_DEV_RXEP_FFSZ			(SSUSB_DEV_BASE + 0x000C)
#define U3_DEV_EP_Q_NUM				(SSUSB_DEV_BASE + 0x0010)
#define U3_DEV_RST_CTRL				(SSUSB_DEV_BASE + 0x0080)
#define U3_DEV_CK_CTRL				(SSUSB_DEV_BASE + 0x0084)
#define U3_DEV_DBG_SEL0				(SSUSB_DEV_BASE + 0x00C0)
#define U3_DEV_DBG_SEL1				(SSUSB_DEV_BASE + 0x00C4)
#define U3_DEV_DBG_SEL2				(SSUSB_DEV_BASE + 0x00C8)
#define U3_DEV_DBG_PRB				(SSUSB_DEV_BASE + 0x00D0)
#define U3_DEV_DBG_VALUE			(SSUSB_DEV_BASE + 0x0100)
#define U3_DEV_LV1ISR				(SSUSB_DEV_BASE + 0x1000)
#define U3_DEV_LV1IER				(SSUSB_DEV_BASE + 0x1004) //Read Only
#define U3_DEV_LV1IESR				(SSUSB_DEV_BASE + 0x1008)
#define U3_DEV_LV1IECR				(SSUSB_DEV_BASE + 0x100C)
#define U3_DEV_RISC_SIZE			(SSUSB_DEV_BASE + 0x1050)
#define U3_DEV_EPISR				(SSUSB_DEV_BASE + 0x1080)
#define U3_DEV_EPIER				(SSUSB_DEV_BASE + 0x1084) //Read Only
#define U3_DEV_EPIESR				(SSUSB_DEV_BASE + 0x1088)
#define U3_DEV_EPIECR				(SSUSB_DEV_BASE + 0x108C)
#define U3_DEV_DMAISR				(SSUSB_DEV_BASE + 0x1090)
#define U3_DEV_DMAIER				(SSUSB_DEV_BASE + 0x1094)
#define U3_DEV_DMAIESR				(SSUSB_DEV_BASE + 0x1098)
#define U3_DEV_DMAIECR				(SSUSB_DEV_BASE + 0x109C)
#define U3_DEV_EP0DMACTRL			(SSUSB_DEV_BASE + 0x10C0)
#define U3_DEV_EP0DMASTARTADDR		(SSUSB_DEV_BASE + 0x10C4)
#define U3_DEV_EP0DMATFRCOUNT		(SSUSB_DEV_BASE + 0x10C8)
#define U3_DEV_EP0DMARLCOUNT		(SSUSB_DEV_BASE + 0x10CC)
#define U3_DEV_TXDMACTRL			(SSUSB_DEV_BASE + 0x10D0)
#define U3_DEV_TXDMASTRADDR			(SSUSB_DEV_BASE + 0x10D4)
#define U3_DEV_TXDMATRDCNT			(SSUSB_DEV_BASE + 0x10D8)
#define U3_DEV_TXDMARLCOUNT			(SSUSB_DEV_BASE + 0x10DC)
#define U3_DEV_RXDMACTRL			(SSUSB_DEV_BASE + 0x10E0)
#define U3_DEV_RXDMASTRADDR			(SSUSB_DEV_BASE + 0x10E4)
#define U3_DEV_RXDMATRDCNT			(SSUSB_DEV_BASE + 0x10E8)
#define U3_DEV_RXDMARLCOUNT			(SSUSB_DEV_BASE + 0x10EC)
#define U3_DEV_EP0CSR				(SSUSB_DEV_BASE + 0x1100) //REG32
#define U3_DEV_EP0CSR_REG16_MPS		(SSUSB_DEV_BASE + 0x1100) //0x1100~0x1101 , REG16
#define U3_DEV_EP0CSR_REG16_CTL		(SSUSB_DEV_BASE + 0x1102) //0x1102~0x1104 , REG16
#define U3_DEV_EP0RXCOUNT			(SSUSB_DEV_BASE + 0x1108) 
#define U3_DEV_TX1CSR0				(SSUSB_DEV_BASE + 0x1110) 
#define U3_DEV_TX1CSR0_REG16_MPS	(SSUSB_DEV_BASE + 0x1110) 
#define U3_DEV_TX1CSR0_REG16_CTL	(SSUSB_DEV_BASE + 0x1112) 
#define U3_DEV_TX1CSR1				(SSUSB_DEV_BASE + 0x1114) 
#define U3_DEV_TX1CSR2				(SSUSB_DEV_BASE + 0x1118) 
#define U3_DEV_RX1CSR0				(SSUSB_DEV_BASE + 0x1210) 
#define U3_DEV_RX1CSR0_REG16_MPS	(SSUSB_DEV_BASE + 0x1210) 
#define U3_DEV_RX1CSR0_REG16_CTL	(SSUSB_DEV_BASE + 0x1212) 
#define U3_DEV_RX1CSR1				(SSUSB_DEV_BASE + 0x1214) 
#define U3_DEV_RX1CSR2				(SSUSB_DEV_BASE + 0x1218) 
#define U3_DEV_FIFO0				(SSUSB_DEV_BASE + 0x1300)
#define U3_DEV_FIFO1				(SSUSB_DEV_BASE + 0x1310)
#define U3_DEV_FIFO2				(SSUSB_DEV_BASE + 0x1320)
#define U3_DEV_FIFO3				(SSUSB_DEV_BASE + 0x1330)
#define U3_DEV_FIFO4				(SSUSB_DEV_BASE + 0x1340)
#define U3_DEV_FIFO5				(SSUSB_DEV_BASE + 0x1350)
#define U3_DEV_FIFO6				(SSUSB_DEV_BASE + 0x1360)
#define U3_DEV_FIFO7				(SSUSB_DEV_BASE + 0x1370)
#define U3_DEV_FIFO8				(SSUSB_DEV_BASE + 0x1380)
#define U3_DEV_FIFO9				(SSUSB_DEV_BASE + 0x1390)
#define U3_DEV_FIFO10				(SSUSB_DEV_BASE + 0x13A0)
#define U3_DEV_FIFO11				(SSUSB_DEV_BASE + 0x13B0)
#define U3_DEV_FIFO12				(SSUSB_DEV_BASE + 0x13C0)
#define U3_DEV_FIFO13				(SSUSB_DEV_BASE + 0x13D0)
#define U3_DEV_FIFO14				(SSUSB_DEV_BASE + 0x13E0)
#define U3_DEV_FIFO15				(SSUSB_DEV_BASE + 0x13F0)

/*SSUSB_EPCTL group*/
#define SSUSB_EPCTL_BASE		(U3MAC_BASE + 0x1800)
#define U3_EPCTL_DEV_CONFIG		(SSUSB_EPCTL_BASE + 0x0000)
#define U3_EPCTL_REG8_DEV_ADDR	(SSUSB_EPCTL_BASE + 0x0003)
#define U3_EPCTL_EP_RST			(SSUSB_EPCTL_BASE + 0x0004)
#define U3_EPCTL_CAP				(SSUSB_EPCTL_BASE + 0x000C)
#define U3_EPCTL_U2_RXERR_INTR		(SSUSB_EPCTL_BASE + 0x0020) //32bit access only
#define U3_EPCTL_EP_PKT_PEND		(SSUSB_EPCTL_BASE + 0x0048)
#define U3_EPCTL_DEV_LINK_INTR_EN	(SSUSB_EPCTL_BASE + 0x0050)
#define U3_EPCTL_DEV_LINK_INTR		(SSUSB_EPCTL_BASE + 0x0054)

/*SSUSB_USB2 group*/
#define SSUSB_U2_BASE			(U3MAC_BASE + 0x1A00)
#define U3_USB2_PWR_MANAGE		(SSUSB_U2_BASE + 0x0004)
#define U3_USB2_TIMING_TM		(SSUSB_U2_BASE + 0x0008)
#define U3_USB2_TEST_MODE		(SSUSB_U2_BASE + 0x0014)
#define U3_USB2_COMMON_INTR_EN	(SSUSB_U2_BASE + 0x0018) //RW
#define U3_USB2_COMMON_INTR_ST	(SSUSB_U2_BASE + 0x001C) //R, W1C
#define U3_USB2_TIMING_PARAM	(SSUSB_U2_BASE + 0x0040)

/*SSUSB_USB3_SYS group*/
#define SSUSB_U3_SYS_BASE		(U3MAC_BASE + 0x1C00)
#define U3_LINK_UX_INACT_TIMER	(SSUSB_U3_SYS_BASE + 0x020C)
#define U3_LINK_POWER_CTRL		(SSUSB_U3_SYS_BASE + 0x0210)
#define U3_LINK_ERR_COUNT		(SSUSB_U3_SYS_BASE + 0x0214)
#define U3_DEV_NOTIF_0			(SSUSB_U3_SYS_BASE + 0x0290)
#define U3_DEV_NOTIF_1			(SSUSB_U3_SYS_BASE + 0x0294)
#define U3_DEV_VDR_TST			(SSUSB_U3_SYS_BASE + 0x0298)
#define U3_DEV_VDR_TST_L		(SSUSB_U3_SYS_BASE + 0x029C)
#define U3_DEV_VDR_TST_H		(SSUSB_U3_SYS_BASE + 0x02A0)
#define U3_HOST_SET_PORT_CTRL	(SSUSB_U3_SYS_BASE + 0x02A4)
#define U3_TIMING_PULSE_CTRL	(SSUSB_U3_SYS_BASE + 0x02B4)
#define U3_RECV_PKT_INTR_EN		(SSUSB_U3_SYS_BASE + 0x02C0)
#define U3_RECV_PKT_INTR		(SSUSB_U3_SYS_BASE + 0x02C4)
#define U3_CRC_ERR_INTR_EN		(SSUSB_U3_SYS_BASE + 0x02C8)
#define U3_CRC_ERR_INTR			(SSUSB_U3_SYS_BASE + 0x02CC)
#define U3_PORT_ST_INTR_EN		(SSUSB_U3_SYS_BASE + 0x02D0)
#define U3_PORT_ST_INTR			(SSUSB_U3_SYS_BASE + 0x02D4)
#define U3_RECOVERY_COUNT		(SSUSB_U3_SYS_BASE + 0x02D8)

/*SSUSB_USB3_MAC group*/
#define SSUSB_U3_MAC_BASE		(U3MAC_BASE + 0x1C00)	
#define U3_MAC_LTSSM_PARAM		(SSUSB_U3_MAC_BASE + 0x000C)
#define U3_MAC_LTSSM_CTRL		(SSUSB_U3_MAC_BASE + 0x0010)
#define U3_USB3_CONFIG			(SSUSB_U3_MAC_BASE + 0x001C)
#define U3_P3_EXIT_LFPS_PARAM	(SSUSB_U3_MAC_BASE + 0x00A0)
#define U3_REF_CK_PARAM			(SSUSB_U3_MAC_BASE + 0x00B0)
#define U3_PIPE_RX_ERR_INTR_EN	(SSUSB_U3_MAC_BASE + 0x0128)
#define U3_PIPE_RX_ERR_INTR		(SSUSB_U3_MAC_BASE + 0x012C)
#define U3_MAC_PIPE_LATCH_SEL	(SSUSB_U3_MAC_BASE + 0x0130) //FPGA only
#define U3_LINK_STATE_MACHINE	(SSUSB_U3_MAC_BASE + 0x0134)
#define U3_MAC_FAST_SIM			(SSUSB_U3_MAC_BASE + 0x0138)
#define U3_LTSSM_INTR_EN		(SSUSB_U3_MAC_BASE + 0x013C)
#define U3_LTSSM_INTR			(SSUSB_U3_MAC_BASE + 0x0140)


/*!
 *	@breif	U3_DEV_RST_CTRL filed description
*/
#define U3_DEV_RST				(0x1 << 0)
#define U3_DEV_BMU_RST			(0x1 << 1)
#define U3_DEV_QMU_RST			(0x1 << 2)
#define U3_DEV_U2MAC_RST		(0x1 << 4)
#define U3_DEV_U3MAC_RST		(0x1 << 5)
#define U3_DEV_U2PHY_RST		(0x1 << 6)
#define U3_DEV_U3PHY_RST		(0x1 << 7)


#else /*U3_DUAL_MODE_IP*/
/*SSUSB_DEVICE group*/
#define SSUSB_DEV_BASE   			(U3MAC_BASE + SSUSB_DEV_OFFSET)
#define SSUSB_DEV_BMU_BASE			(SSUSB_DEV_BASE)
#define U3_DEV_LV1ISR				(SSUSB_DEV_BMU_BASE + 0x0000)
#define U3_DEV_LV1IER				(SSUSB_DEV_BMU_BASE + 0x0004) //Read Only
#define U3_DEV_LV1IESR				(SSUSB_DEV_BMU_BASE + 0x0008)
#define U3_DEV_LV1IECR				(SSUSB_DEV_BMU_BASE + 0x000C)
#define U3_DEV_MAC_P1_EN			(SSUSB_DEV_BMU_BASE + 0x0030)
#define U3_DEV_MAC_P2_EN			(SSUSB_DEV_BMU_BASE + 0x0034)
#define U3_DEV_RISC_SIZE			(SSUSB_DEV_BMU_BASE + 0x0050)
#define U3_DEV_EPISR				(SSUSB_DEV_BMU_BASE + 0x0080)
#define U3_DEV_EPIER				(SSUSB_DEV_BMU_BASE + 0x0084) //Read Only
#define U3_DEV_EPIESR				(SSUSB_DEV_BMU_BASE + 0x0088)
#define U3_DEV_EPIECR				(SSUSB_DEV_BMU_BASE + 0x008C)
#define U3_DEV_DMAISR				(SSUSB_DEV_BMU_BASE + 0x0090)
#define U3_DEV_DMAIER				(SSUSB_DEV_BMU_BASE + 0x0094)
#define U3_DEV_DMAIESR				(SSUSB_DEV_BMU_BASE + 0x0098)
#define U3_DEV_DMAIECR				(SSUSB_DEV_BMU_BASE + 0x009C)
#define U3_DEV_EP0DMACTRL			(SSUSB_DEV_BMU_BASE + 0x00C0)
#define U3_DEV_EP0DMASTARTADDR		(SSUSB_DEV_BMU_BASE + 0x00C4)
#define U3_DEV_EP0DMATFRCOUNT		(SSUSB_DEV_BMU_BASE + 0x00C8)
#define U3_DEV_EP0DMARLCOUNT		(SSUSB_DEV_BMU_BASE + 0x00CC)
#define U3_DEV_TXDMACTRL			(SSUSB_DEV_BMU_BASE + 0x00D0)
#define U3_DEV_TXDMASTRADDR			(SSUSB_DEV_BMU_BASE + 0x00D4)
#define U3_DEV_TXDMATRDCNT			(SSUSB_DEV_BMU_BASE + 0x00D8)
#define U3_DEV_TXDMARLCOUNT			(SSUSB_DEV_BMU_BASE + 0x00DC)
#define U3_DEV_RXDMACTRL			(SSUSB_DEV_BMU_BASE + 0x00E0)
#define U3_DEV_RXDMASTRADDR			(SSUSB_DEV_BMU_BASE + 0x00E4)
#define U3_DEV_RXDMATRDCNT			(SSUSB_DEV_BMU_BASE + 0x00E8)
#define U3_DEV_RXDMARLCOUNT			(SSUSB_DEV_BMU_BASE + 0x00EC)
#define U3_DEV_EP0CSR				(SSUSB_DEV_BMU_BASE + 0x0100) //REG32
#define U3_DEV_EP0CSR_REG16_MPS		(SSUSB_DEV_BMU_BASE + 0x0100) //0x1100~0x1101 , REG16
#define U3_DEV_EP0CSR_REG16_CTL		(SSUSB_DEV_BMU_BASE + 0x0102) //0x1102~0x1104 , REG16
#define U3_DEV_EP0RXCOUNT			(SSUSB_DEV_BMU_BASE + 0x0108) 
#define U3_DEV_TX1CSR0				(SSUSB_DEV_BMU_BASE + 0x0110) 
#define U3_DEV_TX1CSR0_REG16_MPS	(SSUSB_DEV_BMU_BASE + 0x0110) 
#define U3_DEV_TX1CSR0_REG16_CTL	(SSUSB_DEV_BMU_BASE + 0x0112) 
#define U3_DEV_TX1CSR1				(SSUSB_DEV_BMU_BASE + 0x0114) 
#define U3_DEV_TX1CSR2				(SSUSB_DEV_BMU_BASE + 0x0118) 
#define U3_DEV_RX1CSR0				(SSUSB_DEV_BMU_BASE + 0x0210) 
#define U3_DEV_RX1CSR0_REG16_MPS	(SSUSB_DEV_BMU_BASE + 0x0210) 
#define U3_DEV_RX1CSR0_REG16_CTL	(SSUSB_DEV_BMU_BASE + 0x0212) 
#define U3_DEV_RX1CSR1				(SSUSB_DEV_BMU_BASE + 0x0214) 
#define U3_DEV_RX1CSR2				(SSUSB_DEV_BMU_BASE + 0x0218) 
#define U3_DEV_FIFO0				(SSUSB_DEV_BMU_BASE + 0x0300)
#define U3_DEV_FIFO1				(SSUSB_DEV_BMU_BASE + 0x0310)
#define U3_DEV_FIFO2				(SSUSB_DEV_BMU_BASE + 0x0320)
#define U3_DEV_FIFO3				(SSUSB_DEV_BMU_BASE + 0x0330)
#define U3_DEV_FIFO4				(SSUSB_DEV_BMU_BASE + 0x0340)
#define U3_DEV_FIFO5				(SSUSB_DEV_BMU_BASE + 0x0350)
#define U3_DEV_FIFO6				(SSUSB_DEV_BMU_BASE + 0x0360)
#define U3_DEV_FIFO7				(SSUSB_DEV_BMU_BASE + 0x0370)
#define U3_DEV_FIFO8				(SSUSB_DEV_BMU_BASE + 0x0380)
#define U3_DEV_FIFO9				(SSUSB_DEV_BMU_BASE + 0x0390)
#define U3_DEV_FIFO10				(SSUSB_DEV_BMU_BASE + 0x03A0)
#define U3_DEV_FIFO11				(SSUSB_DEV_BMU_BASE + 0x03B0)
#define U3_DEV_FIFO12				(SSUSB_DEV_BMU_BASE + 0x03C0)
#define U3_DEV_FIFO13				(SSUSB_DEV_BMU_BASE + 0x03D0)
#define U3_DEV_FIFO14				(SSUSB_DEV_BMU_BASE + 0x03E0)
#define U3_DEV_FIFO15				(SSUSB_DEV_BMU_BASE + 0x03F0)
#define U3_DEV_MISC_CTRL			(SSUSB_DEV_BMU_BASE + 0x0C84)


#define SSUSB_DEV_COM_CSR_BASE		(SSUSB_DEV_BASE + 0x0C00)
//#define U3_DEV_HW_VER				(SSUSB_DEV_COM_CSR_BASE + 0x0000) //removed in dual mode
#define U3_DEV_EP0_FFSZ				(SSUSB_DEV_COM_CSR_BASE + 0x0004)
#define U3_DEV_TXEP_FFSZ			(SSUSB_DEV_COM_CSR_BASE + 0x0008)
#define U3_DEV_RXEP_FFSZ			(SSUSB_DEV_COM_CSR_BASE + 0x000C)
#define U3_DEV_EP_Q_NUM				(SSUSB_DEV_COM_CSR_BASE + 0x0010)
//#define U3_DEV_RST_CTRL				(SSUSB_DEV_COM_CSR_BASE + 0x0080) //removed in dual mode
//#define U3_DEV_CK_CTRL				(SSUSB_DEV_COM_CSR_BASE + 0x0084)
//#define U3_DEV_DBG_SEL0				(SSUSB_DEV_COM_CSR_BASE + 0x00C0) //removed in dual mode
//#define U3_DEV_DBG_SEL1				(SSUSB_DEV_COM_CSR_BASE + 0x00C4) //removed in dual mode
//#define U3_DEV_DBG_SEL2				(SSUSB_DEV_COM_CSR_BASE + 0x00C8) //removed in dual mode
//#define U3_DEV_DBG_PRB				(SSUSB_DEV_COM_CSR_BASE + 0x00D0) //removed in dual mode
//#define U3_DEV_DBG_VALUE			(SSUSB_DEV_COM_CSR_BASE + 0x0100)


/*SSUSB_EPCTL group*/
#define SSUSB_EPCTL_BASE			(U3MAC_BASE + SSUSB_EPCTL_OFFSET)
#define U3_EPCTL_DEV_CONFIG			(SSUSB_EPCTL_BASE + 0x0000)
#define U3_EPCTL_REG8_DEV_ADDR		(SSUSB_EPCTL_BASE + 0x0003)
#define U3_EPCTL_EP_RST				(SSUSB_EPCTL_BASE + 0x0004)
#define U3_EPCTL_CAP				(SSUSB_EPCTL_BASE + 0x000C)
#define U3_EPCTL_U2_RXERR_INTR		(SSUSB_EPCTL_BASE + 0x0020) //32bit access only
#define U3_EPCTL_EP_PKT_PEND		(SSUSB_EPCTL_BASE + 0x0048)
#define U3_EPCTL_DEV_LINK_INTR_EN	(SSUSB_EPCTL_BASE + 0x0050)
#define U3_EPCTL_DEV_LINK_INTR		(SSUSB_EPCTL_BASE + 0x0054)
#define U3_EPCTL_U2_LPM_FC_CHK		(SSUSB_EPCTL_BASE + 0x0060)

/*SSUSB_USB2 group*/
#define SSUSB_U2_BASE			(U3MAC_BASE + SSUSB_U2_MAC_OFFSET)
#define U3_USB2_PWR_MANAGE		(SSUSB_U2_BASE + 0x0004)
#define U3_USB2_TIMING_TM		(SSUSB_U2_BASE + 0x0008)
#define U3_USB2_TEST_MODE		(SSUSB_U2_BASE + 0x0014)
#define U3_USB2_COMMON_INTR_EN	(SSUSB_U2_BASE + 0x0018) //RW
#define U3_USB2_COMMON_INTR_ST	(SSUSB_U2_BASE + 0x001C) //R, W1C
#define U3_USB2_TIMING_PARAM	(SSUSB_U2_BASE + 0x0040)
#define U3_USB2_LPM_PARAM		(SSUSB_U2_BASE + 0x0044) 
#define U3_USB2_LPM_COUNT		(SSUSB_U2_BASE + 0x0048) 
#define U3_USB2_MISC_CTRL		(SSUSB_U2_BASE + 0x004C) 

/*SSUSB_USB3_SYS group*/
#define SSUSB_U3_SYS_BASE		(U3MAC_BASE + SSUSB_U3_SYS_OFFSET)
#define U3_LINK_UX_INACT_TIMER	(SSUSB_U3_SYS_BASE + 0x020C)
#define U3_LINK_POWER_CTRL		(SSUSB_U3_SYS_BASE + 0x0210)
#define U3_LINK_ERR_COUNT		(SSUSB_U3_SYS_BASE + 0x0214)
#define U3_DEV_NOTIF_0			(SSUSB_U3_SYS_BASE + 0x0290)
#define U3_DEV_NOTIF_1			(SSUSB_U3_SYS_BASE + 0x0294)
#define U3_DEV_VDR_TST			(SSUSB_U3_SYS_BASE + 0x0298)
#define U3_DEV_VDR_TST_L		(SSUSB_U3_SYS_BASE + 0x029C)
#define U3_DEV_VDR_TST_H		(SSUSB_U3_SYS_BASE + 0x02A0)
#define U3_HOST_SET_PORT_CTRL	(SSUSB_U3_SYS_BASE + 0x02A4)
#define U3_TIMING_PULSE_CTRL	(SSUSB_U3_SYS_BASE + 0x02B4)
#define U3_RECV_PKT_INTR_EN		(SSUSB_U3_SYS_BASE + 0x02C0)
#define U3_RECV_PKT_INTR		(SSUSB_U3_SYS_BASE + 0x02C4)
#define U3_CRC_ERR_INTR_EN		(SSUSB_U3_SYS_BASE + 0x02C8)
#define U3_CRC_ERR_INTR			(SSUSB_U3_SYS_BASE + 0x02CC)
#define U3_PORT_ST_INTR_EN		(SSUSB_U3_SYS_BASE + 0x02D0)
#define U3_PORT_ST_INTR			(SSUSB_U3_SYS_BASE + 0x02D4)
#define U3_RECOVERY_COUNT		(SSUSB_U3_SYS_BASE + 0x02D8)

/*SSUSB_USB3_MAC group*/
#define SSUSB_U3_MAC_BASE		(U3MAC_BASE + SSUSB_U3_MAC_OFFSET)	
#define U3_MAC_LTSSM_PARAM		(SSUSB_U3_MAC_BASE + 0x000C)
#define U3_MAC_LTSSM_CTRL		(SSUSB_U3_MAC_BASE + 0x0010)
#define U3_USB3_CONFIG			(SSUSB_U3_MAC_BASE + 0x001C)
#define U3_P3_EXIT_LFPS_PARAM	(SSUSB_U3_MAC_BASE + 0x00A0)
#define U3_REF_CK_PARAM			(SSUSB_U3_MAC_BASE + 0x00B0)
#define U3_PIPE_RX_ERR_INTR_EN	(SSUSB_U3_MAC_BASE + 0x0128)
#define U3_PIPE_RX_ERR_INTR		(SSUSB_U3_MAC_BASE + 0x012C)
#define U3_MAC_PIPE_LATCH_SEL	(SSUSB_U3_MAC_BASE + 0x0130) //FPGA only
#define U3_LINK_STATE_MACHINE	(SSUSB_U3_MAC_BASE + 0x0134)
#define U3_MAC_FAST_SIM			(SSUSB_U3_MAC_BASE + 0x0138)
#define U3_LTSSM_INTR_EN		(SSUSB_U3_MAC_BASE + 0x013C)
#define U3_LTSSM_INTR			(SSUSB_U3_MAC_BASE + 0x0140)
#endif /*U3_DUAL_MODE_IP*/

/*
 *	Endpoint TX/RX EP0~EPn FIFO access window register(Bi-Direction window, 32bits)
 *	The FIFO window offset for each ep is 4bytes
 *	read the FIFO window to access the RX FIFO
 *	write the FIFO window to access the TX FIFO
 *	use the U2_FIFO(ep) to count the FIFO window address for each ep
*/
#define U3_FIFO_REG8(ep_num)	\
	USBReg_Read8(U3_DEV_FIFO0 + ep_num * 0x10)
#define U3_FIFO_REG16(ep_num)	\
	USBReg_Read16(U3_DEV_FIFO0 + ep_num * 0x10)
#define U3_FIFO_REG32(ep_num)	\
	USBReg_Read32(U3_DEV_FIFO0 + ep_num * 0x10)


/*!
 *	@breif	U3_DEV_RISC_SIZE filed description
*/
#define U3_RISX_SZ_8_BIT	(0x0)
#define U3_RISX_SZ_16_BIT	(0x1)
#define U3_RISX_SZ_32_BIT	(0x2)

/*!
 *	@breif	U3_USB3_CONFIG filed description
*/
#define USB3_EN		(0x1 << 0)


/*!
 *	@breif	U3_REF_CK_PARAM filed description
*/
#define U3_REF_CK_1US_OFFSET	(0x0)
#define U3_REF_CK_1US_MSK		(0xFF)

/*!
 *	@breif	U3_PIPE_RX_ERR_INTR filed description
*/
#define U3_PIPE_EBUF_ERR_INTR		(0x1 << 0)
#define U3_PIPE_DISPARITY_ERR_INTR	(0x1 << 1)
#define U3_PIPE_DEC_8B10B_ERR_INTR	(0x1 << 2)

/*!
 *	@breif	U3_P3_EXIT_LFPS_PARAM filed description
*/
#define U3_P3_EXIT_LFPS_REF_OFFSET	(0x8)
#define U3_P3_EXIT_LFPS_REF_MSK		(0xFF)

/*!
 *	@breif	U3_LINK_STATE_MACHINE filed description
*/
#define VBUS_DBC_CYCLE_MASK		0xFFFF0000
#define VBUS_DBC_CYCLE_OFFSET	(16)
#define LTSSM_MASK				0x1F
typedef enum _u3_ltssm_st{
	LTSSM_ST_RESET = 0,
	LTSSM_ST_DISABLE = 1,
	LTSSM_ST_DISABLE_EXIT = 2,
	LTSSM_ST_SS_INACTIVE_QUIET = 3,
	LTSSM_ST_SS_INACTIVE_DISC_DETECT = 4,
	LTSSM_ST_RX_DETECT_RESET = 5,
	LTSSM_ST_RX_DETECT_ACTIVE = 6,
	LTSSM_ST_RX_DETECT_QUIET = 7,
	LTSSM_ST_POLLING_LFPS = 8,
	LTSSM_ST_POLLING_RXEQ = 9,
	LTSSM_ST_POLLING_ACTIVE = 10,
	LTSSM_ST_POLLING_CONFIGURATION = 11,
	LTSSM_ST_POLLING_IDLE = 12,
	LTSSM_ST_U0 = 13,
	LTSSM_ST_U1 = 14,
	LTSSM_ST_U1_TX_PING = 15,
	LTSSM_ST_U1_EXIT = 16,
	LTSSM_ST_U2 = 17,
	LTSSM_ST_U2_DETECT = 18,
	LTSSM_ST_U2_EXIT = 19,
	LTSSM_ST_U3 = 20,
	LTSSM_ST_U3_DETECT = 21,
	LTSSM_ST_U3_EXIT = 22,
	LTSSM_ST_COMPLIANCE = 23,
	LTSSM_ST_RECOVERY_ACTIVE = 24,
	LTSSM_ST_RECOVERY_CONFIGURATION = 25,
	LTSSM_ST_RECOVERY_IDLE = 26,
	LTSSM_ST_LOOPBACK_ACTIVE_MASTER = 27,
	LTSSM_ST_LOOPBACK_ACTIVE_SLAVE = 28,
	LTSSM_ST_LOOPBACK_EXIT = 29,
	LTSSM_ST_HOT_RESET_ACTIVE = 30,
	LTSSM_ST_HOT_RESET_EXIT = 31
}u3_ltssm_st_e;

/*!
 *	@breif	U3_LTSSM_INTR, U3_LTSSM_INTR_EN filed description
*/
#define U3_LTSSM_SS_INACTIVE_INTR		(0x1 << 0)
#define U3_LTSSM_SS_DISABLE_INTR		(0x1 << 1)
#define U3_LTSSM_COMPLIANCE_INTR		(0x1 << 2)
#define U3_LTSSM_LOOPBACK_INTR			(0x1 << 3)
#define U3_LTSSM_HOT_RST_INTR			(0x1 << 4)
#define U3_LTSSM_WARM_RST_INTR			(0x1 << 5)
#define U3_LTSSM_RECOVERY_INTR			(0x1 << 6)
#define U3_LTSSM_ENTER_U0_INTR			(0x1 << 7)
#define U3_LTSSM_ENTER_U1_INTR			(0x1 << 8)
#define U3_LTSSM_ENTER_U2_INTR			(0x1 << 9)
#define U3_LTSSM_ENTER_U3_INTR			(0x1 << 10)
#define U3_LTSSM_EXIT_U1_INTR			(0x1 << 11)
#define U3_LTSSM_EXIT_U2_INTR			(0x1 << 12)
#define U3_LTSSM_EXIT_U3_INTR			(0x1 << 13)
#define U3_LTSSM_RXDET_SUCCESS_INTR		(0x1 << 14)
#define U3_LTSSM_VBUS_RISE_INTR			(0x1 << 15)
#define U3_LTSSM_VBUS_FALL_INTR			(0x1 << 16)
#define U3_LTSSM_U3_LFPS_TO_INTR		(0x1 << 17)
#define U3_LTSSM_U3_RESUME_INTR			(0x1 << 18)
/*!
 *	@breif	U3_DEV_EP_Q_NUM filed description
*/
#define U3_DEV_TX_EP_NUM_MSK		0x000000FF
#define U3_DEV_RX_EP_NUM_MSK		0x0000FF00
#define U3_DEV_TX_Q_NUM_MSK			0x00FF0000
#define U3_DEV_RX_Q_NUM_MSK			0xFF000000
#define U3_DEV_TX_EP_NUM_OFFSET		(0)
#define U3_DEV_RX_EP_NUM_OFFSET		(8)
#define U3_DEV_TX_Q_NUM_OFFSET		(16)
#define U3_DEV_RX_Q_NUM_OFFSET		(24)


/*!
 *	@breif	U3_LINK_UX_INACT_TIMER filed description
*/
#define U3_DEV_U1_INACT_TO_MSK		(0xFF) //SW set for dev send LGO_U1 timeout U0->U1 (WO, UNIT:1us)
#define U3_DEV_U1_INACT_TO_OFFSET	(0)
#define U3_DEV_U1_INACT_TO_UNIT		(0x1) //us
#define U3_U2_INACT_TO_MSK			(0xFF) //HW set when recv u2_inact LMP U1->U2 (RU, UNIT:256us)
#define U3_U2_INACT_TO_OFFSET		(8)
#define U3_U2_INACT_TO_UNIT			(0x100) //us
#define U3_DEV_U2_INACT_TO_MSK		(0xFF) //SW set for dev send LGO_U2 timeout U0->U2 (RW, UNIT:256us)
#define U3_DEV_U2_INACT_TO_OFFSET	(16)
#define U3_DEV_U2_INACT_TO_UNIT		(0x100) //us

/*!
 *	@breif	U3_LINK_POWER_CTRL filed description
*/
#define U3_PWR_AUTO_U1_REQ_EN		(0x1 << 0)
#define U3_PWR_AUTO_U2_REQ_EN		(0x1 << 1)
#define U3_PWR_LGO_U1				(0x1 << 2) //WO
#define U3_PWR_LGO_U2				(0x1 << 3) //WO
#define U3_PWR_LGO_U3				(0x1 << 4) //host mode only (WO)
#define U3_PWR_UX_EXIT				(0x1 << 5) //WO
#define U3_PWR_AUTO_U1_ACCEPT_EN	(0x1 << 8)
#define U3_PWR_AUTO_U2_ACCEPT_EN	(0x1 << 9)

/*!
 *	@breif	U3_PORT_ST_INTR filed description
*/
#define U3_LINK_ADV_DONE_INTR	(0x1 << 0) //Header Seq and Rx Header Buffer Credit Adver
#define U3_LMP_ADV_DONE_INTR	(0x1 << 1) //LMP Port Configuration handshake
#define U3_LMP_ADV_ERR_INTR		(0x1 << 2)

/*!
 *	@breif	U3_HOST_SET_PORT_CTRL filed description
*/
#define U3_FORCE_PM_ACCEPT 		(0x1 << 1)

/*!
 *	@breif	U3_TIMING_PULSE_CTRL filed description
*/
#define U3_SYSCLK_1US_CNT_MSK		0xFF
#define U3_SYSCLK_1US_CNT_OFFSET	0x0

/*!
 *	@breif	U3_RECV_PKT_INTR filed description
*/
#define U3_RECV_ITP_INTR			(0x1 << 0)
#define U3_RECV_U2_INACT_INTR		(0x1 << 1)
#define U3_RECV_SET_LINK_FUNC_INTR	(0x1 << 2)

/*!
 *	@breif	U3_CRC_ERR_INTR filed description
*/
#define U3_CRC32_ERR_INTR			(0x1 << 0)
#define U3_CRC5_ERR_INTR			(0x1 << 1)
#define U3_CRC16_ERR_INTR			(0x1 << 2)

/*!
 *	@breif	U3_RECOVERY_COUNT filed description
*/
#define CLR_RECOV_CNT		(0x1 << 16)

/*!
 *	@breif	U3_LINK_ERR_COUNT filed description
*/
#define CLR_LINK_ERR_CNT	(0x1 << 16)


/*!
 *	@breif	U3_USB2_TIMING_TM filed description
*/
#define U3_USB2_TM1				(0x1 << 0)

/*!
 *	@breif	U3_DEV_NOTIF_0 filed description
*/
#define U3_DEV_NOTIF_SEND			(0x1)
#define U3_DEV_NOTIF_TYPE_MSK		(0xF)
#define U3_DEV_NOTIF_TYPE_OFFSET	(4)
#define U3_DEV_NOTIF_VAL_L_MSK		(0xFFFFFF)
#define U3_DEV_NOTIF_VAL_L_OFFSET	(8)
#define U3_DEV_NOTIF_VAL_L_WIDTH	(24)

/*!
 *	@breif	U3_DEV_VDR_TST filed description
*/
#define U3_SEND_VDR_TST_LMP			(0x1)
#define U3_VDR_TST_LMP_TYPE_MSK		(0x00FF0000)
#define U3_VDR_TST_LMP_TYPE_OFFSET	(16)

/*!
 *	@breif	U3_DEV_NOTIF_1 filed description
*/
#define U3_DEV_NOTIF_VAL_H_MSK		(0xFFFFFFFF)
#define U3_DEV_NOTIF_VAL_H_OFFSET	(0)



/*!
 *	@breif	U3_MAC_LTSSM_PARAM filed description
*/
#define U3_MAC_RXEQ_CNT_MSK		0x0000FFFF
#define U3_MAC_RXEQ_CNT_OFFSET	(0)
#define U3_MAC_RXDET_CNT_MSK		0x001F0000
#define U3_MAC_RXDET_CNT_OFFSET	(16)
#define U3_MAC_DISABLE_CNT_MSK		0x0F000000
#define U3_MAC_DISABLE_CNT_OFFSET	(24)


/*!
 *	@breif	U3_MAC_LTSSM_CTRL filed description
*/
#define U3_MAC_U1_GO_U2_EN		(0x1 << 0)
#define U3_MAC_COMPLIANCE_EN	(0x1 << 1)
/*!
 *	0: hardware auto reply U3 exit LFPS
 *	1: software should set the U3_PWR_UX_EXIT in U3_LINK_POWER_CTRL
 *	  when received the U3_LTSSM_U3_RESUME_INTR
*/
#define U3_MAC_SW_U3_EXIT_EN	(0x1 << 2) 

/*!
 *	@breif	U3_DEV_LV1ISR filed description
*/
#define U3_DEV_BMU_INTR			(0x1 << 0)
#define U3_DEV_QMU_INTR			(0x1 << 1)
#define U3_DEV_MAC3_INTR		(0x1 << 2)
#define U3_DEV_DMA_INTR			(0x1 << 3)
#define U3_DEV_MAC2_INTR		(0x1 << 4)
#define U3_DEV_EP_CTRL_INTR		(0x1 << 5)

/*!
 *	@breif	U3_DEV_MAC_P1_EN, U3_DEV_MAC_P2_EN filed description
*/
#define REQ_UX_EP0_INACT_CHK		(0x1 << 0)
#define REQ_UX_TXQ_INACT_CHK		(0x1 << 1)
#define REQ_UX_RXQ_INACT_CHK		(0x1 << 2)
#define REQ_UX_BMU_TX_EMP_CHK		(0x1 << 3)
#define REQ_UX_BMU_RX_EMP_CHK		(0x1 << 4)
#define ACCEPT_EP0_INACT_CHK		(0x1 << 16)
#define ACCEPT_TXQ_INACT_CHK		(0x1 << 17)
#define ACCEPT_RXQ_INACT_CHK		(0x1 << 18)
#define ACCEPT_BMU_TX_EMP_CHK		(0x1 << 19)
#define ACCEPT_BMU_RX_EMP_CHK		(0x1 << 20)
#define EXIT_BY_ERDY_DIS			(0x1 << 31)

/*!
 *	@breif	U3_USB2_COMMON_INTR_ST filed description
*/
#define U3_USB2_INTR_SUSPEND		(0x1 << 0)
#define U3_USB2_INTR_RESUME			(0x1 << 1)
#define U3_USB2_INTR_RESET			(0x1 << 2)
#define U3_USB2_INTR_SOF			(0x1 << 3)
#define U3_USB2_INTR_CONN			(0x1 << 4)
#define U3_USB2_INTR_DISCONN		(0x1 << 5)
#define U3_USB2_INTR_SESSION		(0x1 << 6)
#define U3_USB2_INTR_VBUS_ERR		(0x1 << 7)
#define U3_USB2_INTR_LPM_SUSPEND	(0x1 << 8)
#define U3_USB2_INTR_LPM_RESUME		(0x1 << 9)

/*!
 *	@breif	U3_USB2_TIMING_PARAM filed description
*/
#define U2_SYSCLK_1US_CNT_MSK		0xFF
#define U2_SYSCLK_1US_CNT_OFFSET	0


/*!
 *	@breif	U3_USB2_LPM_PARAM filed description
*/
#define U3_USB2_LMP_BESL_MSK			(0xF)
#define U3_USB2_LMP_BESL_OFFSET			(0)
#define U3_USB2_LMP_BESLDCK_MSK			(0xF)
#define U3_USB2_LMP_BESLDCK_OFFSET		(4)
#define U3_USB2_LMP_BESLCK_MSK			(0xF)
#define U3_USB2_LMP_BESLCK_OFFSET		(8)
#define U3_USB2_LMP_BESLCK_U3_MSK		(0xF)
#define U3_USB2_LMP_BESLCK_U3_OFFSET	(12)

/*!
 *	@breif	U3_USB2_LPM_COUNT filed description
*/
#define U3_USB2_LPM_ENTRY_CNT_MSK		(0xFF)
#define U3_USB2_LPM_ENTRY_CNT_OFFSET	(0)
#define U3_USB2_LPM_ENTRY_CNT_CLR		(0x1 << 8)
#define U3_USB2_LPM_EXIT_CNT_MSK		(0xFF)
#define U3_USB2_LPM_EXIT_CNT_OFFSET		(16)
#define U3_USB2_LPM_EXIT_CNT_CLR		(0x1 << 9)

/*!
 *	@breif	U3_USB2_MISC_CTRL filed description
*/
/*
 *	when lpm_hrwe=0, hw will clear this bit when LPM suspend
 *	sw should set this bit after LPM resume interrupt or issue remote wakeup
 *	when lpm_hrwe=1, hw won't clear this bit and sw don't have to handle this bit
*/
#define U3_USB2_LPM_ACK_EN				(0x1 << 0) 

/*!
 *	@breif	U3_MAC_PIPE_LATCH_SEL filed description (FPGA ONLY)
*/
#define U3_PIPE_RX_LATCH_MSK	(0x03 << 0)
#define U3_PIPE_RX_LATCH_POS	(0x00 << 0)
#define U3_PIPE_RX_LATCH_NEG	(0x01 << 0)
#define U3_PIPE_RX_LATCH_BPS	(0x10 << 0)
#define U3_PIPE_TX_LATCH_MSK	(0x03 << 2)
#define U3_PIPE_TX_LATCH_POS	(0x00 << 2)
#define U3_PIPE_TX_LATCH_NEG	(0x01 << 2)
#define U3_PIPE_TX_LATCH_BPS	(0x10 << 2)


/*!
 *	@breif	U3_DEV_DBG_SEL2 filed description (FPGA ONLY)
*/
#define U3_DBG_PRB_BYTE0_OFFSET	(0)
#define U3_DBG_PRB_BYTE1_OFFSET	(8)
#define U3_DBG_PRB_BYTE2_OFFSET	(16)
#define U3_DBG_PRB_BYTE3_OFFSET	(24)
typedef enum _u3_dbg_prb_sel{
	U3_DBG_PRB_MAC3 = 0x1,
	U3_DBG_PRB_MAC2,
	U3_DBG_PRB_BMU,
	U3_DBG_PRB_QMU,
	U3_DBG_PRB_AXI,
	U3_DBG_PRB_SSUSB_EPCTL,
	U3_DBG_PRB_IRQ,
	U3_DBG_PRB_DMA,
	U3_DBG_PRB_SSUSB_PHYD,
	U3_DBG_PRB_RISC_WRAP,
	U3_DBG_PRB_DMA_ARB,
	U3_DBG_PRB_SW_DBG,
}u3_dbg_prb_sel_e;

/*!
 *	@breif	U3_EPCTL_DEV_CONFIG filed description
*/
#define U3_EPCTL_VENDOR_ID_OFFSET		(0)
#define U3_EPCTL_VENDOR_ID_MSK			(0xff << U3_EPCTL_VENDOR_ID_OFFSET)
#define U3_EPCTL_REVISION_ID_OFFSET		(8)
#define U3_EPCTL_REVISION_ID_MSK		(0xff << U3_EPCTL_REVISION_ID_OFFSET)
#define U3_EPCTL_SW_SEL_U3				(0x1 << 16) //SW set 1 to select the device mode as U3 (only valid when DEV_CONFIG.17=1)
#define U3_EPCTL_DEV_SPEED_OFFSET		(0x0)
#define U3_EPCTL_DEV_SPEED_MSK			(0x7)
#define U3_EPCTL_DEV_SPEED_FS			(0x1)
#define U3_EPCTL_DEV_SPEED_HS			(0x3)
#define U3_EPCTL_DEV_SPEED_SS			(0x4)

/*!
 *	@breif	U3_EPCTL_EP_PKT_PEND filed description
*/


/*!
 *	@breif	U3_EPCTL_DEV_LINK_INTR filed description
*/
#define U3_EPCTL_DEV_SPEED_CHG_INTR		(0x1<<0)

/*!
 *	@breif	U3_EPCTL_U2_LPM_FC_CHK filed description
*/
#define LPM_HWRWE_FC_CHK_EP0			(0x1 << 0)
#define LPM_HWRWE_FC_CHK_IN_EPN_MSK		(0x000000FE)
#define LPM_HWRWE_FC_CHK_OUT_EPN_MSK	(0x00FE0000)

/*
 * set 1 and SW could select the U3/U2 mode by DEV_CONFIG.16
 * set 0 and the U2/U3 select flow would handled by HW and final mode status
 *	   would shown on the DEV_CONFIG.18
*/
#define U3_EPCTL_SW_SEL_U2_U3			(0x1 << 16)
#define U3_EPCTL_SW_SEL_U2_U3_EN		(0x1 << 17) 
#define U3_EPCTL_SEL_ST_U3				(0x1 << 18) //R only, 1 means the currently mode is U3 mode, else U2 mode
#define U3_EPCTL_DEV_ADDR_OFFSET		(24)
#define U3_EPCTL_DEV_ADDR_MSK			(0xff << U3_EPCTL_DEV_ADDR_OFFSET)

/*!
 *	@breif	U3_USB2_PWR_MANAGE filed description
*/
#define U3_USB2_PM_SUSPENDM_EN			(0x1 << 0)
#define U3_USB2_PM_ST_SUSPEND			(0x1 << 1)
#define U3_USB2_PM_RESUME				(0x1 << 2)
#define U3_USB2_PM_ST_RESET				(0x1 << 3)
#define U3_USB2_PM_HS_MD				(0x1 << 4)
#define U3_USB2_PM_HS_EN				(0x1 << 5)
#define U3_USB2_PM_SOFT_CONN			(0x1 << 6)
#define U3_USB2_PM_ISO_UPDATE			(0x1 << 7)
#define U3_USB2_PM_LPM_MODE_MSK			(0x3)				
#define U3_USB2_PM_LPM_MODE_OFFSET		(0x8)				
#define U3_USB2_LPM_AUTO				(0x0)
#define U3_USB2_LPM_REJECT				(0x1)
#define U3_USB2_LPM_ACCEPT				(0x2)
#define U3_USB2_PM_LPM_HRWE				(0x1 << 10)
#define U3_USB2_PM_LPM_REMOTE_WK		(0x1 << 11) //RO latch from host LPM

/*!
 *	@breif	U3_USB2_TEST_MODE filed description
*/
#define U3_USB2_TS_SE0_NAK				(0x1 << 0)
#define U3_USB2_TS_J					(0x1 << 1)
#define U3_USB2_TS_K					(0x1 << 2)
#define U3_USB2_TS_PKT					(0x1 << 3)
#define U3_USB2_TS_FORCE_HS				(0x1 << 4)
#define U3_USB2_TS_FORCE_FS				(0x1 << 5)
#define U3_USB2_TS_FIFO_ACCESS			(0x1 << 6)
#define U3_USB2_TS_FORCE_HOST			(0x1 << 7)
#define U3_USB2_TS_LPM_STALL			(0x1 << 8)

/*!
 *	@breif	U3_DEV_EPISR filed description
*/
#define U3_DEV_EP0ISR				(0x1 << 0)
#define U3_DEV_EPTISR_OFFSET		(0)
#define U3_DEV_EPTISR				(0xFFFE)
#define U3_DEV_EPRISR_OFFSET		(16)
#define U3_DEV_SETUPENDISR			(0x1 << 16)
#define U3_DEV_EPRISR				(0xFFFE << U3_DEV_EPRISR_OFFSET)


/*!
 *	@breif	U3_DEV_EP0CSR filed description
*/

/*U3_DEV_EP0CSR to access with 32 bit register*/
#define U3_EP0_MPS_MSK				(0x03FF)
#define U3_EP0_REG32_RXPKTRDY		(0x1 << 16)
#define U3_EP0_REG32_SETUP			(0x1 << 17)
#define U3_EP0_REG32_TXPKTRDY		(0x1 << 18)
#define U3_EP0_REG32_DATAEND		(0x1 << 19)
#define U3_EP0_REG32_DPHTX			(0x1 << 20) //set to change data phase TX
#define U3_EP0_REG32_SENTSTALL		(0x1 << 22)
#define U3_EP0_REG32_FIFOFULL		(0x1 << 23)
#define U3_EP0_REG32_FLUSHFIFO		(0x1 << 24)
#define U3_EP0_REG32_SENDSTALL		(0x1 << 25)
#define U3_EP0_REG32_DMAREQEN		(0x1 << 28)
#define U3_EP0_REG32_AUTOSET		(0x1 << 29)
#define U3_EP0_REG32_AUTOCLR		(0x1 << 30)
#define U3_EP0_REG32_EPRST			(0x1 << 31) //could use this bit to reset ep0 state machine

/*U3_DEV_EP0CSR_REG16_CTL to access EP0CSR control part with 16bit register*/
#define U3_EP0_REG16_RXPKTRDY		(0x1 << 0)
#define U3_EP0_REG16_SETUPRDY		(0x1 << 1)
#define U3_EP0_REG16_TXPKTRDY		(0x1 << 2)
#define U3_EP0_REG16_DATAEND		(0x1 << 3)
#define U3_EP0_REG16_DPHTX			(0x1 << 4) //set to change data phase TX
#define U3_EP0_REG16_SENTSTALL		(0x1 << 6)
#define U3_EP0_REG16_FLUSHFIFO		(0x1 << 8)
#define U3_EP0_REG16_SENDSTALL		(0x1 << 9)
#define U3_EP0_REG16_DMAREQEN		(0x1 << 12)
#define U3_EP0_REG16_AUTOSET		(0x1 << 13)
#define U3_EP0_REG16_AUTOCLR		(0x1 << 14)
#define U3_EP0_REG16_EPRST			(0x1 << 15) //could use this bit to reset ep0 state machine



/*!
 *	@breif	TX/RX CSR address definition
*/
#define U3_TXCSR0_ADDR(ep_num) 	(U3_DEV_TX1CSR0 + ((ep_num - 1) * 0x10))
#define U3_TXCSR1_ADDR(ep_num) 	(U3_DEV_TX1CSR1 + ((ep_num - 1) * 0x10))
#define U3_TXCSR2_ADDR(ep_num) 	(U3_DEV_TX1CSR2 + ((ep_num - 1) * 0x10))
#define U3_RXCSR0_ADDR(ep_num) 	(U3_DEV_RX1CSR0 + ((ep_num - 1) * 0x10))
#define U3_RXCSR1_ADDR(ep_num) 	(U3_DEV_RX1CSR1 + ((ep_num - 1) * 0x10))
#define U3_RXCSR2_ADDR(ep_num) 	(U3_DEV_RX1CSR2 + ((ep_num - 1) * 0x10))
#define U3_TXCSR0_REG16_MPS_ADDR(ep_num) 	(U3_DEV_TX1CSR0_REG16_MPS + ((ep_num - 1) * 0x10))
#define U3_TXCSR0_REG16_CTL_ADDR(ep_num) 	(U3_DEV_TX1CSR0_REG16_CTL + ((ep_num - 1) * 0x10))
#define U3_RXCSR0_REG16_MPS_ADDR(ep_num) 	(U3_DEV_RX1CSR0_REG16_MPS + ((ep_num - 1) * 0x10))
#define U3_RXCSR0_REG16_CTL_ADDR(ep_num) 	(U3_DEV_RX1CSR0_REG16_CTL + ((ep_num - 1) * 0x10))

/*!
 *	@breif	U3_DEV_TX1CSR0, U3_DEV_RX1CSR0_REG16_MPS filed description
*/
#define U3_TXEP_MPS_MSK				(0x07FF)
/*!
 *	@breif	U3_DEV_TX1CSR0_REG16_CTL filed description
*/
#define U3_TXEP_REG16_TXPKTRDY		(0x1 << 0)
#define U3_TXEP_REG16_FLUSHFIFO		(0x1 << 4)
#define U3_TXEP_REG16_SENDSTALL		(0x1 << 5)
#define U3_TXEP_REG16_SENTSTALL		(0x1 << 6)
#define U3_TXEP_REG16_FIFOEMPTY		(0x1 << 8)
#define U3_TXEP_REG16_FIFOFULL		(0x1 << 9)
#define U3_TXEP_REG16_DMAREQEN		(0x1 << 13)
#define U3_TXEP_REG16_AUTOSET		(0x1 << 14)
/* 	
 *	this reset would reset FSM, Flush FIFO, 
 *	reset U2 data toggle , reset U3 packet sequence
*/
#define U3_TXEP_REG16_EPRST			(0x1 << 15) 

/*!
 *	@breif	U3_DEV_TX1CSR1 filed description
*/
#define U3_TXEP_REG32_SSBURST_MSK		(0xF)
#define U3_TXEP_REG32_SSBURST_OFFSET	(0)
#define U3_TXEP_REG32_TXTYPE_BULK		(0x0)
#define U3_TXEP_REG32_TXTYPE_INT		(0x1)
#define U3_TXEP_REG32_TXTYPE_ISO		(0x2)
#define U3_TXEP_REG32_TXTYPE_MSK		(0x3)
#define U3_TXEP_REG32_TXTYPE_OFFSET		(4)
#ifdef U3_VER_20121228_LATER
#define U3_TXEP_REG32_TXSLOT_MSK		(0x3F)
#define U3_TXEP_REG32_TXSLOT_OFFSET		(8)
#define U3_TXEP_REG32_TXMAXPKT_MSK		(0x3F)
#define U3_TXEP_REG32_TXMAXPKT_OFFSET	(16)
#define U3_TXEP_REG32_TXMULT_MSK		(0x3)
#define U3_TXEP_REG32_TXMULT_OFFSET		(22)
#else /*U3_VER_20121228_LATER*/
#define U3_TXEP_REG32_TXMULT_MSK		(0x3)
#define U3_TXEP_REG32_TXMULT_OFFSET		(8)
#endif /*U3_VER_20121228_LATER*/
/*!
 *	@breif	U3_DEV_TX1CSR2 filed description
*/
#define U3_TXEP_REG32_FIFOADDR_MSK		(0x1FFF)
#define U3_TXEP_REG32_FIFOADDR_OFFSET	(0)
#define U3_TXEP_REG32_FIFOSZ_MSK		(0xF)
#define U3_TXEP_REG32_FIFOSZ_OFFSET		(16)
#define U3_TXEP_REG32_BINTERVAL_MSK		(0xFF)
#define U3_TXEP_REG32_BINTERVAL_OFFSET	(24)

/*!
 *	@breif	U3_DEV_RX1CSR0 filed description
*/
#define U3_RXEP_MPS_MSK				(0x07FF)
#define U3_RXEP_REG16_RXPKTRDY		(0x1 << 0)
#define U3_RXEP_REG16_FIFOEMPTY	(0x1 << 1)
#define U3_RXEP_REG16_FIFOFULL		(0x1 << 2)
#define U3_RXEP_REG16_FLUSHFIFO		(0x1 << 4)
#define U3_RXEP_REG16_SENDSTALL		(0x1 << 5)
#define U3_RXEP_REG16_SENTSTALL		(0x1 << 6)
#define U3_RXEP_REG16_DMAREQEN		(0x1 << 13)
#define U3_RXEP_REG16_AUTOCLR		(0x1 << 14)
/* 	
 *	this reset would reset FSM, Flush FIFO, 
 *	reset U2 data toggle , reset U3 packet sequence
*/
#define U3_RXEP_REG16_EPRST			(0x1 << 15) 

/*!
 *	@breif	U3_DEV_RX1CSR1 filed description
*/
#define U3_RXEP_REG32_SSBURST_MSK		(0xF)
#define U3_RXEP_REG32_SSBURST_OFFSET	(0)
#define U3_RXEP_REG32_RXTYPE_BULK		(0x0)
#define U3_RXEP_REG32_RXTYPE_INT		(0x1)
#define U3_RXEP_REG32_RXTYPE_ISO		(0x2)
#define U3_RXEP_REG32_RXTYPE_MSK		(0x3)
#define U3_RXEP_REG32_RXTYPE_OFFSET		(4)
#ifdef U3_VER_20121228_LATER
#define U3_RXEP_REG32_RXSLOT_MSK		(0x3F)
#define U3_RXEP_REG32_RXSLOT_OFFSET		(8)
#define U3_RXEP_REG32_RXMAXPKT_MSK		(0x3F)
#define U3_RXEP_REG32_RXMAXPKT_OFFSET	(16)
#define U3_RXEP_REG32_RXMULT_MSK		(0x3)
#define U3_RXEP_REG32_RXMULT_OFFSET		(22)
#else /*U3_VER_20121228_LATER*/
#define U3_RXEP_REG32_RXMULT_MSK		(0x3)
#define U3_RXEP_REG32_RXMULT_OFFSET		(8)
#endif /*U3_VER_20121228_LATER*/
/*!
 *	@breif	U3_DEV_RX1CSR2 filed description
*/
#define U3_RXEP_REG32_FIFOADDR_MSK		(0x1FFF)
#define U3_RXEP_REG32_FIFOADDR_OFFSET	(0)
#define U3_RXEP_REG32_FIFOSZ_MSK		(0xF)
#define U3_RXEP_REG32_FIFOSZ_OFFSET		(16)
#define U3_RXEP_REG32_BINTERVAL_MSK		(0xFF)
#define U3_RXEP_REG32_BINTERVAL_OFFSET	(24)

/*U3_DEV_EP0DMACTRL*/
#define U3_EP0_DMA_EN					(0x1 << 0)
#define U3_EP0_DMA_DIR_WR_DRAM			(0x1 << 1)
#define U3_EP0_DMA_INTR_EN				(0x1 << 2)
#define U3_EP0_DMA_EP_NUM_OFFSET		(4)
#define U3_EP0_DMA_EP_NUM_MSK			(0xF)
#define U3_EP0_DMA_FIFO_ADDR_OFFSET		(16)
#define U3_EP0_DMA_FIFO_ADDR_MSK		(0xFFFF)

/*U3_DEV_EP0DMASTARTADDR*/
#define U3_EP0_DMA_DRAM_ADDR_MSK		(0xFFFFFFFF)

/*U3_DEV_EP0DMATFRCOUNT*/
#define U3_EP0_DMA_XFER_CNT_MSK			(0x7FF) //max transfer lenght is 2047

/*U3_DEV_EP0DMARLCOUNT*/
#define U3_EP0_DMA_FAKE					(0x1 << 27)
#define U3_EP0_DMA_BURST_OFFSET			(24)
#define U3_EP0_DMA_BURST_MSK			(0x3)
#define U3_EP0_DMA_LIMITER_OFFSET		(28)
#define U3_EP0_DMA_LIMITER_MSK			(0x7)

/*U3_DEV_TXDMARLCOUNT*/
#define U3_TX_DMA_FAKE					(0x1 << 27)
#define U3_TX_DMA_BURST_OFFSET			(24)
#define U3_TX_DMA_BURST_MSK				(0x3)
#define U3_TX_DMA_LIMITER_OFFSET		(28)
#define U3_TX_DMA_LIMITER_MSK			(0x7)

/*U3_DEV_RXDMARLCOUNT*/
#define U3_RX_DMA_FAKE					(0x1 << 27)
#define U3_RX_DMA_BURST_OFFSET			(24)
#define U3_RX_DMA_BURST_MSK				(0x3)
#define U3_RX_DMA_LIMITER_OFFSET		(28)
#define U3_RX_DMA_LIMITER_MSK			(0x7)


typedef enum _u3_dma_burst_limiter {
	U3_DMA_LIMITER_1T = 0,
	U3_DMA_LIMITER_2T,
	U3_DMA_LIMITER_4T,
	U3_DMA_LIMITER_8T,
	U3_DMA_LIMITER_16T,
	U3_DMA_LIMITER_32T,
	U3_DMA_LIMITER_64T,
	U3_DMA_LIMITER_128T,
}u3_dma_burst_limiter_e;
typedef enum _u3_dma_axi_burst{
	U3_DMA_BURST_128 = 0,
	U3_DMA_BURST_64,
	U3_DMA_BURST_32,
	U3_DMA_BURST_16,
}u3_dma_axi_burst_e;

/*!
 *	@breif	U3_DEV_MISC_CTRL filed description
*/
#define U3_DEV_VBUS_FRC_EN				(0x1 << 0)
#define U3_DEV_VBUS_FRC_ON				(0x1 << 1)
#define U3_DEV_DMA_BUS_CK_GATE_DIS		(0x1 << 2)

/*U3_EPCTL_EP_RST*/
#define U3_EPCTL_EP0_RST				0x1
#define U3_EPCTL_EPN_OUT_RST_OFFSET		0
#define U3_EPCTL_EPN_OUT_RST_MSK		0x0000FFFE
#define U3_EPCTL_EPN_IN_RST_OFFSET		0x16
#define U3_EPCTL_EPN_IN_RST_MSK			0xFFFE0000
#define U3_EPCTL_EPN_OUT_RST(ep_num)			(0x1 << ep_num)
#define U3_EPCTL_EPN_IN_RST(ep_num)				(0x1 << (ep_num + 16))	

/*!
 *	@breif	U3_EPCTL_CAP filed description
*/
#define U3_EPCTL_TX_BURST_EN		(0x1 << 0)
#define U3_EPCTL_EOB_EN				(0x1 << 1)
#define U3_EPCTL_ISO_CRC_CHK_DIS	(0x1 << 2)


/*U3_EPCTL_U2_RXERR_INTR*/
#define U3_EPCTL_U2_RXERR_INTR_EN_MSK		0xFFFF
#define U3_EPCTL_U2_RXERR_INTR_EN_OFFSET	(16)
 #define U3_EPCTL_U2_RXERR_INTR_MSK			0xFFFF
 #define U3_EPCTL_U2_RXERR_INTR_OFFSET		(0)
 
#endif
