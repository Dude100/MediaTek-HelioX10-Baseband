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
 *   brom_u3phy_reg.h
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


#ifndef __BROM_U3PHY_REG_H__
#define __BROM_U3PHY_REG_H__

#include "reg_base.h"
#include "brom_u3mac_reg.h"

#ifdef U3_VER_20120720_LATER
#define U3PHY_BASE			BASE_ADDR_U3PHY
#define U3PHY_IPPC_OFFSET	0x700
#define U3PHY_IPPC_BASE		U3PHY_BASE + U3PHY_IPPC_OFFSET
#else /*U3_VER_20120720_LATER*/
#ifdef U3_DUAL_MODE_IP
#define U3PHY_BASE	(BASE_ADDR_U3MAC + 0x2000)
#else /*U3_DUAL_MODE_IP*/
#define U3PHY_BASE	BASE_ADDR_U3PHY
#endif /*U3_DUAL_MODE_IP*/
#endif /*U3_VER_20120720_LATER*/

#ifdef U3_DUAL_MODE_IP
#ifdef U3_VER_20120720_LATER
/*SIFSLV group (USB PHY)*/
#define U3_IP_PW_CTRL0			(U3PHY_IPPC_BASE + 0x0000)
#define U3_IP_PW_CTRL1			(U3PHY_IPPC_BASE + 0x0004)
#define U3_IP_PW_CTRL2			(U3PHY_IPPC_BASE + 0x0008)
#define U3_IP_PW_CTRL3			(U3PHY_IPPC_BASE + 0x000C)
#define U3_IP_PW_STS			(U3PHY_IPPC_BASE + 0x0010)
#define U3_IP_PW_STS1			(U3PHY_IPPC_BASE + 0x0010)
#define U3_IP_PW_STS2			(U3PHY_IPPC_BASE + 0x0014)
#define U3_IP_MAC_CAP			(U3PHY_IPPC_BASE + 0x0020)
#define U3_IP_XHCI_CAP			(U3PHY_IPPC_BASE + 0x0024)
#define U3_IP_DEV_CAP			(U3PHY_IPPC_BASE + 0x0028)
#define U3_IP_U3_CTRL_0P		(U3PHY_IPPC_BASE + 0x0030)
#define U3_IP_U3_CTRL_1P		(U3PHY_IPPC_BASE + 0x0038)
#define U3_IP_U3_CTRL_2P		(U3PHY_IPPC_BASE + 0x0040)
#define U3_IP_U3_CTRL_3P		(U3PHY_IPPC_BASE + 0x0048)
#define U3_IP_U2_CTRL_0P		(U3PHY_IPPC_BASE + 0x0050)
#define U3_IP_U2_CTRL_1P		(U3PHY_IPPC_BASE + 0x0058)
#define U3_IP_U2_CTRL_2P		(U3PHY_IPPC_BASE + 0x0060)
#define U3_IP_U2_CTRL_3P		(U3PHY_IPPC_BASE + 0x0068)
#define U3_IP_U2_CTRL_4P		(U3PHY_IPPC_BASE + 0x0070)
#define U3_IP_U2_CTRL_5P		(U3PHY_IPPC_BASE + 0x0078)
#define U3_IP_DMA_CTRL			(U3PHY_IPPC_BASE + 0x0080)
#define U3_IP_MAC_CK_CTRL		(U3PHY_IPPC_BASE + 0x0084)
#define U3_IP_CSR_CK_CTRL		(U3PHY_IPPC_BASE + 0x0088)
#define U3_IP_REF_CK_CTRL		(U3PHY_IPPC_BASE + 0x008C)
#define U3_IP_XHCI_CK_CTRL		(U3PHY_IPPC_BASE + 0x0090)
#define U3_IP_XHCI_RST_CTRL		(U3PHY_IPPC_BASE + 0x0094)
#define U3_IP_DEV_RST_CTRL		(U3PHY_IPPC_BASE + 0x0098)
#define U3_IP_SYS_CK_CTRL		(U3PHY_IPPC_BASE + 0x009C)
#define U3_IP_FPGA_ID			(U3PHY_IPPC_BASE + 0x00A0)
#define U3_IP_PRB_CTRL0			(U3PHY_IPPC_BASE + 0x00B0)
#define U3_IP_PRB_CTRL1			(U3PHY_IPPC_BASE + 0x00B4)
#define U3_IP_PRB_CTRL2			(U3PHY_IPPC_BASE + 0x00B8)
#define U3_IP_PRB_CTRL3			(U3PHY_IPPC_BASE + 0x00BC)
#define U3_IP_PRB_CTRL4			(U3PHY_IPPC_BASE + 0x00C0)
#define U3_IP_PRB_CTRL5			(U3PHY_IPPC_BASE + 0x00C4)
#define U3_IP_SPARE0			(U3PHY_IPPC_BASE + 0x00C8)
#define U3_IP_SPARE1			(U3PHY_IPPC_BASE + 0x00CC)


/*U3_IP_PW_CTRL0*/
#define U3_IP_SW_RST					(0x1 << 0)
#define U3_IP_U2_ENT_SLEEP_CNT_MSK		(0xFF)
#define U3_IP_U2_ENT_SLEEP_CNT_OFFSET	(0x8)

/*U3_IP_PW_CTRL2*/
#define U3_IP_DEV_PDN					(0x1 << 0)

/*U3_IP_PW_STS*/
#define U3_IP_SYSPLL_STABLE			(0x1 << 0)
#define U3_IP_DEV_QMU_RST_B			(0x1 << 1)
#define U3_IP_DEV_BMU_RST_B			(0x1 << 2)
#define U3_IP_DEV_RST_B				(0x1 << 3)
#define U3_IP_REF_CK_RST_B			(0x1 << 8)
#define U3_IP_SYS60_CK_RST_B		(0x1 << 9)
#define U3_IP_SYS125_CK_RST_B		(0x1 << 10)
#define U3_IP_XHCI_CK_RST_B			(0x1 << 11)
#define U3_IP_XHCI_DRAM_CK_RST_B	(0x1 << 12)
#define U3_IP_DEV_DRAM_CK_RST_B		(0x1 << 13)
#define U3_IP_U3_MAC_CK_0P_RST_B	(0x1 << 16)
#define U3_IP_U3_MAC_CK_1P_RST_B	(0x1 << 17)
#define U3_IP_U3_MAC_CK_2P_RST_B	(0x1 << 18)
#define U3_IP_U3_MAC_CK_3P_RST_B	(0x1 << 19)
#define U3_IP_U2_MAC_CK_0P_RST_B	(0x1 << 24)
#define U3_IP_U2_MAC_CK_1P_RST_B	(0x1 << 25)
#define U3_IP_U2_MAC_CK_2P_RST_B	(0x1 << 26)
#define U3_IP_U2_MAC_CK_3P_RST_B	(0x1 << 27)
#define U3_IP_U2_MAC_CK_4P_RST_B	(0x1 << 28)
#define U3_IP_U2_MAC_CK_5P_RST_B	(0x1 << 29)

/*U3_IP_PW_STS2*/
#define U3_IP_U2_MAC_SYS_0P_RST_B	(0x1 << 0)
#define U3_IP_U2_MAC_SYS_1P_RST_B	(0x1 << 1)
#define U3_IP_U2_MAC_SYS_2P_RST_B	(0x1 << 2)
#define U3_IP_U2_MAC_SYS_3P_RST_B	(0x1 << 3)
#define U3_IP_U2_MAC_SYS_4P_RST_B	(0x1 << 4)
#define U3_IP_U2_MAC_SYS_5P_RST_B	(0x1 << 5)


/*U3_IP_U3_CTRL_0P*/
#define U3_IP_U3_PORT0_DIS			(0x1 << 0)
#define U3_IP_U3_PORT0_PDN			(0x1 << 1)
#define U3_IP_U3_PORT0_HOST_SEL		(0x1 << 2)
#define U3_IP_U3_PORT0_U2_CG_EN		(0x1 << 3)
#define U3_IP_U3_PORT0_MAC_RST		(0x1 << 4)
#define U3_IP_U3_PORT0_PHYD_RST		(0x1 << 5)

/*U3_IP_U2_CTRL_0P*/
#define U3_IP_U2_PORT0_DIS			(0x1 << 0)
#define U3_IP_U2_PORT0_PDN			(0x1 << 1)
#define U3_IP_U2_PORT0_HOST_SEL		(0x1 << 2)
#define U3_IP_U2_PORT0_U2_CG_EN		(0x1 << 3)
#define U3_IP_U2_PORT0_MAC_RST		(0x1 << 4)
#define U3_IP_U2_PORT0_PHYD_RST		(0x1 << 5)


/*!
 *	@breif	U3_IP_DEV_RST_CTRL filed description
*/
#define U3_DEV_RST				(0x1 << 0)
#define U3_DEV_BMU_RST			(0x1 << 1)
#define U3_DEV_QMU_RST			(0x1 << 2)
#define U3_DEV_DRAM_RST			(0x1 << 3)


#else /*U3_VER_20120720_LATER*/
/*SIFSLV group (USB PHY)*/
#define U3_IP_PW_CTRL0			(U3PHY_BASE + 0x0000)
#define U3_IP_PW_CTRL1			(U3PHY_BASE + 0x0004)
#define U3_IP_PW_CTRL2			(U3PHY_BASE + 0x0008)
#define U3_IP_PW_CTRL3			(U3PHY_BASE + 0x000C)
#define U3_IP_PW_STS			(U3PHY_BASE + 0x0010)
#define U3_IP_MAC_CAP			(U3PHY_BASE + 0x0014)
#define U3_IP_XHCI_CAP			(U3PHY_BASE + 0x0018)
#define U3_IP_DEV_CAP			(U3PHY_BASE + 0x001C)
#define U3_IP_U3_CTRL_0P		(U3PHY_BASE + 0x0100)
#define U3_IP_U3_CTRL_1P		(U3PHY_BASE + 0x0110)
#define U3_IP_U3_CTRL_2P		(U3PHY_BASE + 0x0120)
#define U3_IP_U3_CTRL_3P		(U3PHY_BASE + 0x0130)
#define U3_IP_U2_CTRL_0P		(U3PHY_BASE + 0x0180)
#define U3_IP_U2_CTRL_1P		(U3PHY_BASE + 0x0190)
#define U3_IP_U2_CTRL_2P		(U3PHY_BASE + 0x01A0)
#define U3_IP_U2_CTRL_3P		(U3PHY_BASE + 0x01B0)
#define U3_IP_U2_CTRL_4P		(U3PHY_BASE + 0x01C0)
#define U3_IP_U2_CTRL_5P		(U3PHY_BASE + 0x01D0)
#define U3_IP_DMA_CTRL			(U3PHY_BASE + 0x0200)
#define U3_IP_MAC_CK_CTRL		(U3PHY_BASE + 0x0204)
#define U3_IP_XHCI_CK_CTRL		(U3PHY_BASE + 0x0210)
#define U3_IP_XHCI_RST_CTRL		(U3PHY_BASE + 0x0214)
#define U3_IP_DEV_RST_CTRL		(U3PHY_BASE + 0x0220)
#define U3_IP_FPGA_ID			(U3PHY_BASE + 0x02F0)
#define U3_IP_PRB_CTRL0			(U3PHY_BASE + 0x0300)
#define U3_IP_PRB_CTRL1			(U3PHY_BASE + 0x0304)
#define U3_IP_PRB_CTRL2			(U3PHY_BASE + 0x0308)
#define U3_IP_PRB_CTRL3			(U3PHY_BASE + 0x030C)
#define U3_IP_PRB_CTRL4			(U3PHY_BASE + 0x0310)
#define U3_IP_PRB_CTRL5			(U3PHY_BASE + 0x0314)
#define U3_IP_SPARE0			(U3PHY_BASE + 0x03F8)
#define U3_IP_SPARE1			(U3PHY_BASE + 0x03FC)


/*U3_IP_PW_CTRL0*/
#define U3_IP_SW_RST					(0x1 << 0)
#define U3_IP_U2_ENT_SLEEP_CNT_MSK		(0xFF)
#define U3_IP_U2_ENT_SLEEP_CNT_OFFSET	(0x8)

/*U3_IP_PW_CTRL2*/
#define U3_IP_DEV_PDN					(0x1 << 0)

/*U3_IP_PW_STS*/
#define U3_IP_SYSPLL_STABLE			(0x1 << 0)
#define U3_IP_REF_CK_RST_B			(0x1 << 8)
#define U3_IP_SYS60_CK_RST_B		(0x1 << 9)
#define U3_IP_SYS125_CK_RST_B		(0x1 << 10)
#define U3_IP_XHCI_CK_RST_B			(0x1 << 11)
#define U3_IP_DRAM_CK_RST_B			(0x1 << 12)
#define U3_IP_U3_MAC_CK_0P_RST_B	(0x1 << 16)
#define U3_IP_U3_MAC_CK_1P_RST_B	(0x1 << 17)
#define U3_IP_U3_MAC_CK_2P_RST_B	(0x1 << 18)
#define U3_IP_U3_MAC_CK_3P_RST_B	(0x1 << 19)
#define U3_IP_U2_MAC_CK_0P_RST_B	(0x1 << 24)
#define U3_IP_U2_MAC_CK_1P_RST_B	(0x1 << 25)
#define U3_IP_U2_MAC_CK_2P_RST_B	(0x1 << 26)
#define U3_IP_U2_MAC_CK_3P_RST_B	(0x1 << 27)
#define U3_IP_U2_MAC_CK_4P_RST_B	(0x1 << 28)
#define U3_IP_U2_MAC_CK_5P_RST_B	(0x1 << 29)



/*U3_IP_U3_CTRL_0P*/
#define U3_IP_U3_PORT0_DIS			(0x1 << 0)
#define U3_IP_U3_PORT0_PDN			(0x1 << 1)
#define U3_IP_U3_PORT0_HOST_SEL		(0x1 << 2)
#define U3_IP_U3_PORT0_CKDG_EN		(0x1 << 3)
#define U3_IP_U3_PORT0_MAC_RST		(0x1 << 4)
#define U3_IP_U3_PORT0_PHYD_RST		(0x1 << 5)
#define U3_IP_U3_PORT0_U2_CG_EN		(0x1 << 6)

/*U3_IP_U2_CTRL_0P*/
#define U3_IP_U2_PORT0_DIS			(0x1 << 0)
#define U3_IP_U2_PORT0_PDN			(0x1 << 1)
#define U3_IP_U2_PORT0_HOST_SEL		(0x1 << 2)
#define U3_IP_U2_PORT0_CKDG_EN		(0x1 << 3)
#define U3_IP_U2_PORT0_MAC_RST		(0x1 << 4)
#define U3_IP_U2_PORT0_PHYD_RST		(0x1 << 5)
#define U3_IP_U2_PORT0_U2_CG_EN		(0x1 << 6)


/*!
 *	@breif	U3_IP_DEV_RST_CTRL filed description
*/
#define U3_DEV_RST				(0x1 << 0)
#define U3_DEV_BMU_RST			(0x1 << 1)
#define U3_DEV_QMU_RST			(0x1 << 2)
#define U3_DEV_DRAM_RST			(0x1 << 3)
#endif /*U3_VER_20120720_LATER*/

#else /*U3_DUAL_MODE_IP*/
/*SIFSLV group (USB PHY)*/
#define SSUSB_SIFSLV_BASE		(BASE_ADDR_U3PHY + 0x700)
#define U3_IP_PW_CTRL			(SSUSB_SIFSLV_BASE + 0x0000)
#define U3_IP_PW_STS			(SSUSB_SIFSLV_BASE + 0x0004)
#define U3_IP_U3_CTRL_0P		(SSUSB_SIFSLV_BASE + 0x0010)
#define U3_IP_U3_CTRL_1P		(SSUSB_SIFSLV_BASE + 0x0020)
#define U3_IP_U2_CTRL_0P		(SSUSB_SIFSLV_BASE + 0x0080)
#define U3_IP_U2_CTRL_1P		(SSUSB_SIFSLV_BASE + 0x0090)
#define U3_IP_U2_CTRL_2P		(SSUSB_SIFSLV_BASE + 0x00A0)
#define U3_IP_U2_CTRL_3P		(SSUSB_SIFSLV_BASE + 0x00B0)
#define U3_IP_U2_CTRL_4P		(SSUSB_SIFSLV_BASE + 0x00C0)


/*U3_IP_PW_CTRL*/
#define U3_IP_SW_RST				(0x1 << 0)
#define U3_IP_PDN					(0x1 << 1)

/*U3_IP_PW_STS*/
#define U3_IP_SYSPLL_STABLE			(0x1 << 0)
#define U3_IP_REF_CK_RST_B			(0x1 << 8)
#define U3_IP_SYS60_CK_RST_B		(0x1 << 9)
#define U3_IP_SYS125_CK_RST_B		(0x1 << 10)
#define U3_IP_XHCI_CK_RST_B			(0x1 << 11)
#define U3_IP_DRAM_CK_RST_B			(0x1 << 12)
#define U3_IP_U3_MAC_CK_0P_RST_B	(0x1 << 16)
#define U3_IP_U3_MAC_CK_1P_RST_B	(0x1 << 17)
#define U3_IP_U2_MAC_CK_0P_RST_B	(0x1 << 24)
#define U3_IP_U2_MAC_CK_1P_RST_B	(0x1 << 25)
#define U3_IP_U2_MAC_CK_2P_RST_B	(0x1 << 26)
#define U3_IP_U2_MAC_CK_3P_RST_B	(0x1 << 27)
#define U3_IP_U2_MAC_CK_4P_RST_B	(0x1 << 28)



/*U3_IP_U3_CTRL_0P*/
#define U3_IP_U3_PORT0_DIS			(0x1 << 0)
#define U3_IP_U3_PORT0_PDN			(0x1 << 1)
#define U3_IP_U3_PORT0_HOST_SEL		(0x1 << 2)
#define U3_IP_U3_PORT0_CKDG_EN		(0x1 << 3)
#define U3_IP_U3_PORT0_MAC_RST		(0x1 << 4)
#define U3_IP_U3_PORT0_PHYD_RST		(0x1 << 5)
#define U3_IP_U3_PORT0_U2_CG_EN		(0x1 << 6)

/*U3_IP_U2_CTRL_0P*/
#define U3_IP_U2_PORT0_DIS			(0x1 << 0)
#define U3_IP_U2_PORT0_PDN			(0x1 << 1)
#define U3_IP_U2_PORT0_HOST_SEL		(0x1 << 2)
#define U3_IP_U2_PORT0_CKDG_EN		(0x1 << 3)
#define U3_IP_U2_PORT0_MAC_RST		(0x1 << 4)
#define U3_IP_U2_PORT0_PHYD_RST		(0x1 << 5)
#define U3_IP_U2_PORT0_U2_CG_EN		(0x1 << 6)
#endif /*U3_DUAL_MODE_IP*/

#endif
