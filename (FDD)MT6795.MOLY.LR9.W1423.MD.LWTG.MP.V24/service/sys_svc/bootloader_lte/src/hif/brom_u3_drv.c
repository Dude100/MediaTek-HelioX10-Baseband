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
 *   brom_u3_drv.c
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *	This is the MT7208 USB3.0 driver
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 ****************************************************************************/

#include "string.h"
//#include "brom_cr4perf_drv.h"
#include "bl_GPT.h"
#include "brom_u3mac_reg.h"
#include "brom_u3phy_reg.h"
#include "brom_u3_drv.h"
#include "brom_usb_dbg.h"
#include "brom_i2c.h"
#include "brom_usb_drv.h"
#include "brom_u3q_reg.h"
#include "brom_u3q_op.h"


hifusb_priv_t usb_priv;
kal_uint8 usb_ep0_buf[USB_EP0_BUF_SZ];


#define BOOTROM_MS_CPU_LOOP_CNT 1000
void usb_delay_ms(kal_uint32 msec)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	kal_uint32 delay_cnt = 0;

	for (delay_cnt = 0 ; delay_cnt < msec ; delay_cnt ++) {
		//perf_delay_us(1000);
		//gpt_delay_us(1000);
		BL_GPT_UDELAY(1000);
	}
}

/*!
 *  @brief  close all u3 ip layer power and clock resource
 */
void u3_pwr_deinit(void)
{
	/*reset of IP and  power down of IP*/
	USBReg_Read32(U3_IP_PW_CTRL0) |= U3_IP_SW_RST; 
	USBReg_Read32(U3_IP_PW_CTRL2) |= U3_IP_DEV_PDN;

	/*disable U3 port 0, enable U3 port 0 power down*/
	USBReg_Read32(U3_IP_U3_CTRL_0P) |= (U3_IP_U3_PORT0_DIS | U3_IP_U3_PORT0_PDN );

	/*disable U2 port 0, enable U2 port 0 power down*/
	USBReg_Read32(U3_IP_U2_CTRL_0P) |= (U3_IP_U2_PORT0_DIS | U3_IP_U2_PORT0_PDN);	

}

/*!
 *  @brief  enable U3 clock and power to start using the MAC and PHY
 *			should prevent accessing the U3 MAC before enable clock and power
 *			or the accessing might make the system bus hang
 */
void u3_pwr_init(void)
{
	kal_uint32 reg_mask = 0, timeout = 0;

#ifdef U3_DUAL_MODE_IP
	/*release the reset of IP and disable power down of IP*/
	USBReg_Read32(U3_IP_PW_CTRL0) &= (~U3_IP_SW_RST);
	USBReg_Read32(U3_IP_PW_CTRL2) &= (~U3_IP_DEV_PDN);

	/*enable U3 port 0, disable U3 port 0 power down*/
	USBReg_Read32(U3_IP_U3_CTRL_0P) &= (~(U3_IP_U3_PORT0_DIS | U3_IP_U3_PORT0_PDN | U3_IP_U3_PORT0_HOST_SEL));

	/*enable U2 port 0, disable U2 port 0 power down*/
	USBReg_Read32(U3_IP_U2_CTRL_0P) &= (~(U3_IP_U2_PORT0_DIS | U3_IP_U2_PORT0_PDN | U3_IP_U2_PORT0_HOST_SEL));

#else /*U3_DUAL_MODE_IP*/
	/*release the reset of IP and disable power down of IP*/
	USBReg_Read32(U3_IP_PW_CTRL) &= (~(U3_IP_SW_RST | U3_IP_PDN));

	/*enable U3 port 0, disable U3 port 0 power down*/
	USBReg_Read32(U3_IP_U3_CTRL_0P) &= (~(U3_IP_U3_PORT0_DIS | U3_IP_U3_PORT0_PDN));

	/*enable U2 port 0, disable U2 port 0 power down*/
	USBReg_Read32(U3_IP_U2_CTRL_0P) &= (~(U3_IP_U2_PORT0_DIS | U3_IP_U2_PORT0_PDN));

#endif /*U3_DUAL_MODE_IP*/

	/*wait all clock active and PLL stable*/
#ifdef U3_VER_20120720_LATER	
	reg_mask = U3_IP_SYS125_CK_RST_B |U3_IP_U3_MAC_CK_0P_RST_B;
	timeout = 0;
	while ((USBReg_Read32(U3_IP_PW_STS) & reg_mask) != reg_mask) {
		//gpt_delay_us(1);
		BL_GPT_UDELAY(1);
		timeout ++;
		if (timeout > 5000000) { //count 5sec to output debug information
			timeout = 0;
			//serial_put_errno(ERR_USB_PREFIX | E_USB_PHY_PWR_BLOCKED);
		}		
	}
	reg_mask = U3_IP_U2_MAC_SYS_0P_RST_B;
	timeout = 0;
	while ((USBReg_Read32(U3_IP_PW_STS2) & reg_mask) != reg_mask) {
		//gpt_delay_us(1);
		BL_GPT_UDELAY(1);
		timeout ++;
		if (timeout > 5000000) { //count 5sec to output debug information
			timeout = 0;
			//serial_put_errno(ERR_USB_PREFIX | E_USB_PHY_PWR_BLOCKED);
		}		
	}
#else
	reg_mask = U3_IP_SYS125_CK_RST_B |U3_IP_U3_MAC_CK_0P_RST_B ;
	while ((USBReg_Read32(U3_IP_PW_STS) & reg_mask) != reg_mask);
#endif
}

void u3_rst_dev(void)
{
	kal_uint32 reg_mask = 0;

	/*this reset function would both reset U3 MAC and PHY*/
#ifdef U3_DUAL_MODE_IP
	USBReg_Read32(U3_IP_DEV_RST_CTRL) |= U3_DEV_RST;
	usb_delay_ms(1);			
	USBReg_Read32(U3_IP_DEV_RST_CTRL) &= (~U3_DEV_RST);
#else
	USBReg_Read32(U3_DEV_RST_CTRL) |= U3_DEV_RST;
	usb_delay_ms(1);			
	USBReg_Read32(U3_DEV_RST_CTRL) &= (~U3_DEV_RST);
#endif

	/*wait all clock active and PLL stable*/
#ifdef U3_VER_20120720_LATER	
	reg_mask = U3_IP_SYS125_CK_RST_B |U3_IP_U3_MAC_CK_0P_RST_B;
	while ((USBReg_Read32(U3_IP_PW_STS) & reg_mask) != reg_mask);
	reg_mask = U3_IP_U2_MAC_SYS_0P_RST_B;
	while ((USBReg_Read32(U3_IP_PW_STS2) & reg_mask) != reg_mask);
#else
	reg_mask = U3_IP_SYS125_CK_RST_B |U3_IP_U3_MAC_CK_0P_RST_B ;
	while ((USBReg_Read32(U3_IP_PW_STS) & reg_mask) != reg_mask);
#endif

}


//#define USB30_PHY_CAL
#ifdef HAL_PLATFORM_FPGA
#define U3_PHY_PG_A60802A 			0x30
#define A60802B_PIPE_PHASE_BANK 	0x30
#define A60802B_PIPE_PHASE_REG		0x23
#define C60802A_PIPE_PHASE_BANK 	0x50
#define C60802A_PIPE_PHASE_REG		0x0B
#define C60802A_VER_CODE			0x111128E0
#define U3_PHY_BANK_SEL				0xFF
#define U3_PHY_I2C_DEV_ID			0x60
#define ENTER_U0_TH		 			10
#define MAX_PHASE_RANGE 			31
#define MAX_TIMEOUT_COUNT 			20
	
/*!
 *  @brief  initial U3 PHY configuration
 */
kal_uint32 u3_phy_init(void) 
{
	kal_uint32 phase_val = 0;
	kal_bool rx_latch_pos = KAL_TRUE;
	kal_uint32 temp = 0, phy_ver = 0;
	kal_uint8 i2c_reg = 0, reg_addr = 0, bank = 0;
#ifdef USB30_PHY_CAL
	kal_bool fset_phase_val = KAL_TRUE;
	kal_uint32 U0_count = 0, link_error_count = 0, recov_cnt = 0, count = 0;
#endif


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef GPIO_FPGA_20120814_LATER
	/*mt7208 GPIO need to change the AP/MD MUX for md use*/
	*(volatile unsigned int*)(BASE_MADDR_MDGPIOMUX + 0x10) = 0x0;
	*(volatile unsigned int*)(BASE_MADDR_MDGPIOMUX + 0x20) = 0x0;
#else
#endif

	u3_pwr_init();


	/*
	 * @ brief 	MT7208 LTE FPGA U3 PHY test chip I2C GPIO arrange
	 *			U2_SCL : GPIO2 , U2_SDA : GPIO3
	 *			U3_SCL : GPIO4 , U3_SDA : GPIO5
	*/

	/*use I2C to control PHY test chip*/
	SerialCommInit();

	/*read PHY Version*/
	bank = 0x20;
	I2cWriteReg(U3_PHY_I2C_DEV_ID, U3_PHY_BANK_SEL, bank);
	reg_addr = 0xE0;
	I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
	phy_ver = i2c_reg;
	reg_addr = 0xE1;
	I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
	phy_ver |= (i2c_reg << 8);
	reg_addr = 0xE2;
	I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
	phy_ver |= (i2c_reg << 16);
	reg_addr = 0xE3;
	I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
	phy_ver |= (i2c_reg << 24);
	usbdev_printf(USBDEV_UARTDBG_WARN ,"U3 PHY Version = 0x%x \n\r", phy_ver);


	if (phy_ver == C60802A_VER_CODE) {
		usbdev_printf(USBDEV_UARTDBG_WARN ,"Start initial C60802A U3 PHY\n\r");
		bank = 0x00;
		I2cWriteReg(U3_PHY_I2C_DEV_ID, U3_PHY_BANK_SEL, bank);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x18, 0x04);
		reg_addr = U3_PHY_BANK_SEL;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x18;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);

		bank = 0x10;
		I2cWriteReg(U3_PHY_I2C_DEV_ID, U3_PHY_BANK_SEL, bank);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x08, 0x19);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x09, 0x82);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x60, 0x80);
		reg_addr = U3_PHY_BANK_SEL;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x08;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x09;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x60;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);

		bank = 0x20;
		I2cWriteReg(U3_PHY_I2C_DEV_ID, U3_PHY_BANK_SEL, bank);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x02, 0x01);
		reg_addr = U3_PHY_BANK_SEL;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x02;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);

		bank = 0x30;
		I2cWriteReg(U3_PHY_I2C_DEV_ID, U3_PHY_BANK_SEL, bank);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x1d, 0xa4);
		reg_addr = U3_PHY_BANK_SEL;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x1d;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);

		bank = 0x40;
		I2cWriteReg(U3_PHY_I2C_DEV_ID, U3_PHY_BANK_SEL, bank);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x42, 0x47);
		reg_addr = U3_PHY_BANK_SEL;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x42;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		
		bank = 0x50;
		I2cWriteReg(U3_PHY_I2C_DEV_ID, U3_PHY_BANK_SEL, bank);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x07, 0x01);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x0a, 0x10);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x0b, 0x19);
		reg_addr = U3_PHY_BANK_SEL;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x42;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x0a;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x0b;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);		
	} else {
		usbdev_printf(USBDEV_UARTDBG_WARN ,"Start initial A60802B U3 PHY\n\r");
		/*initial chip register*/
		bank = U3_PHY_PG_A60802A;
		I2cWriteReg(U3_PHY_I2C_DEV_ID, U3_PHY_BANK_SEL, bank);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x0d, 0x02);
		/*A60802B U2 PHY intial flow, enable U2 UTMI interface I/O*/
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x20, 0x80);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x21, 0x08);
		/*set u3 pipe data driving*/
		reg_addr = 0x22;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		i2c_reg &= 0xE7;
		i2c_reg |= 0x18; //set drv level 3
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x22, i2c_reg); 


		reg_addr = U3_PHY_BANK_SEL;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x0d;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x20;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r", bank, reg_addr, i2c_reg);
		reg_addr = 0x21;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r", bank, reg_addr, i2c_reg);

		/*initial U3 PHYD*/
		bank = 0x10;
		I2cWriteReg(U3_PHY_I2C_DEV_ID, U3_PHY_BANK_SEL, 0x10);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x22, 0x07);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x06, 0x37);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x08, 0x19);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x32, 0x5a);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x00, 0x80);
		reg_addr = U3_PHY_BANK_SEL;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x22;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x06;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x08;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x32;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x00;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);

		/*initial U3 PHYA*/
		bank = 0x20;
		I2cWriteReg(U3_PHY_I2C_DEV_ID, U3_PHY_BANK_SEL, 0x20);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x06, 0xd9);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x05, 0x14);
		I2cWriteReg(U3_PHY_I2C_DEV_ID, 0x16, 0x42);
		reg_addr = U3_PHY_BANK_SEL;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x06;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x05;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);
		reg_addr = 0x16;
		I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
		usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);		
	}

	/*calibration for U3 PHY test chip and MAC PIPE interface timing*/
	/*select U3 PHY regster bank*/
	if (phy_ver == C60802A_VER_CODE) {
		bank = C60802A_PIPE_PHASE_BANK;
		reg_addr = C60802A_PIPE_PHASE_REG;
	} else {
		bank = A60802B_PIPE_PHASE_BANK;
		reg_addr = A60802B_PIPE_PHASE_REG;
	}
	I2cWriteReg(U3_PHY_I2C_DEV_ID, U3_PHY_BANK_SEL, bank);	
	I2cReadReg(U3_PHY_I2C_DEV_ID, reg_addr, &i2c_reg);
	usbdev_printf(USBDEV_UARTDBG_WARN ,"I2C read bank=0x%x, addr=0x%x, data=0x%x after write\n\r",bank , reg_addr, i2c_reg);


#ifdef USB30_PHY_CAL

	usbdev_printf(USBDEV_UARTDBG_WARN ,"Start U3 PHY PIPE calibration flow\n\r");

 	phase_val = 0x0;
	count = 0;
	fset_phase_val = KAL_TRUE;
	rx_latch_pos = KAL_TRUE;

	if (phy_ver == C60802A_VER_CODE) {
		bank = C60802A_PIPE_PHASE_BANK;
		reg_addr = C60802A_PIPE_PHASE_REG;
	} else {
		bank = A60802B_PIPE_PHASE_BANK;
		reg_addr = A60802B_PIPE_PHASE_REG;
	}	
	I2cWriteReg(U3_PHY_I2C_DEV_ID, U3_PHY_BANK_SEL, bank);

	while(1){
		if(phase_val > MAX_PHASE_RANGE){
			usb_delay_ms(10);
			/*TODO: reset USB IP*/
			break;
		}
		if(fset_phase_val) {
			temp = phase_val << 3;
			/*set U3 MAC to SS.Disable*/
			USBReg_Write32(U3_USB3_CONFIG, 0);
			usb_delay_ms(10);
			temp |= 0x6; //fill max u3ck_drv
			I2cWriteReg(U3_PHY_I2C_DEV_ID, reg_addr, temp);//i2c write phy(0x23) phase range:bit7~bit3
			/*reset USB IP*/
			u3_rst_dev();
			USBReg_Write32(U3_USB3_CONFIG, 0);

			usb_delay_ms(10);
			
			/*set rx latch edge*/
			if (rx_latch_pos == KAL_TRUE) {
				USBReg_Write32(U3_MAC_PIPE_LATCH_SEL, U3_PIPE_RX_LATCH_POS);
			} else {
				USBReg_Write32(U3_MAC_PIPE_LATCH_SEL, U3_PIPE_RX_LATCH_NEG);				
			}
			/*Start U3 MAC LTSSM*/
			USBReg_Write32(U3_USB3_CONFIG, USB3_EN);
			fset_phase_val = KAL_FALSE;
			U0_count=0;
			link_error_count=0;
			recov_cnt=0;
			count=0;
		}
		usb_delay_ms(100);
		count++;
		recov_cnt = USBReg_Read32(U3_RECOVERY_COUNT);//read U0 recovery count
		link_error_count=USBReg_Read32(U3_LINK_ERR_COUNT);//read link error count
		if((USBReg_Read32(U3_LINK_STATE_MACHINE) & LTSSM_MASK) == LTSSM_ST_U0){//enter U0 state
			U0_count++;
		}
		if(U0_count > ENTER_U0_TH) {//link up
			usbdev_printf(USBDEV_UARTDBG_WARN ,"Link Error Count=%d, Recovery Count=%d], rx_latch_pos=%d\n\r", link_error_count, recov_cnt, rx_latch_pos);
			usb_delay_ms(500);
			recov_cnt = USBReg_Read32(U3_RECOVERY_COUNT);
			link_error_count = USBReg_Read32(U3_LINK_ERR_COUNT);
			USBReg_Write32(U3_RECOVERY_COUNT, CLR_RECOV_CNT);//clear recovery count
			USBReg_Write32(U3_LINK_ERR_COUNT, CLR_LINK_ERR_CNT);//clear link error count
			usbdev_printf(USBDEV_UARTDBG_WARN ,"[PASS] Link Error Count=%d, Recovery Count=%d, PhaseDelay[0x%x], rx_latch_pos=%d\n\r", 
																					link_error_count, recov_cnt, phase_val, rx_latch_pos);
			fset_phase_val = KAL_TRUE;
		} else if ((USBReg_Read32(U3_LINK_STATE_MACHINE) & LTSSM_MASK) == LTSSM_ST_DISABLE) {//link fail
			usbdev_printf(USBDEV_UARTDBG_WARN, "[FAIL] STATE_DISABLE, PhaseDelay[0x%x], rx_latch_pos=%d\n\r", phase_val, rx_latch_pos);
			fset_phase_val = KAL_TRUE;
			
		} else if (count > MAX_TIMEOUT_COUNT) {//link timeout
			usbdev_printf(USBDEV_UARTDBG_WARN,"[FAIL] TIMEOUT, PhaseDelay[0x%x] rx_latch_pos=%d \n\r", phase_val, rx_latch_pos);
			fset_phase_val = KAL_TRUE;
		}

		if (fset_phase_val == KAL_TRUE) {
			if (rx_latch_pos == KAL_TRUE) {
				rx_latch_pos = KAL_FALSE;
			} else {
				rx_latch_pos = KAL_TRUE;
				phase_val ++; // try positive and negative latch for rx and then to next phase
				if (phase_val == 4) {
					//phase_val ++; //skip phase 4 because would dead lock
				}
			}
		}
	}
#else /*USB30_PHY_CAL*/

	if (phy_ver == C60802A_VER_CODE) {
		bank = C60802A_PIPE_PHASE_BANK;
		reg_addr = C60802A_PIPE_PHASE_REG;
	} else {
		bank = A60802B_PIPE_PHASE_BANK;
		reg_addr = A60802B_PIPE_PHASE_REG;
	}	

	/*initail PHY PIPE phase with the calibration result*/
	I2cWriteReg(U3_PHY_I2C_DEV_ID, U3_PHY_BANK_SEL, bank);

	if (phy_ver == C60802A_VER_CODE) {
		/*FPGA 20120506_MD_a4_b12_C3 phase = , positive = 1 is good phase*/
		/*FPGA 20120521_USB3_a4_b12_cx phase = 0x5~0xd, 0x13~0x16, positive = 1 is good phase*/
		/*FPGA 20120617_USB3_a4_b12_C3 phase = 0x1~0x8,0x11~0x17 , positive = 1 is good phase*/
		/*FPGA 20120621_USB3_a4_b12_C3 phase = 0x1~0x8,positive = 1, phase=0xd~0x17, positive=0 is good phase*/
		/*FPGA 20120706_USB3_a4_b12_C3 phase = 0x1~0x8,positive = 1, phase=0xd~0x14, positive=1 is good phase*/
		/*FPGA 20120814_USB3_a4_b12_C3 phase = 0x0~0x12,positive = 1, phase=0x1b~0x1f, positive=0 is good phase*/
		/*FPGA 20120827_USB3_a4_b12_C3 phase = 0x0~0x17,positive = 1, phase=0x1c~0x1f, positive=0 is good phase*/
		/*FPGA 201201003_USB3_a4_b12_C3 phase = 0x0~0x6,positive = 0, phase=0x13~0x1f, positive=0 is good phase*/
		/*FPGA 20121129_MD_a4_b12_C3 phase = 0x0~0x8,positive = 0, phase = 0x9~0x16,positive = 1 is good phase*/
		phase_val = 0x10;
		rx_latch_pos = KAL_TRUE;
	} else {
		/*FPGA 20111118_USB3, phase = 0x18~0x1d, positive = 0 or 1 is good phase*/
		//phase_val = 0x1a;
		/*FPGA 20120302_MD_a4_b12_C3 phase = 0x1b~0x1e, positive = 0 or 1 is good phase*/
		//phase_val = 0x1c;
		/*FPGA 20120506_MD_a4_b12_C3 phase = 0x16~0x1c, positive = 1 is good phase*/
		//phase_val = 0x18;
		/*FPGA 20120521_BOOTROM_a4_b12_cx phase = 0x18~0x1c, positive = 1 is good phase*/
		//phase_val = 0x1a;
		/*FPGA 20120706_USB3_a4_b12_C3 phase = 0x5~0xa,positive = 0 is good phase*/
		/*FPGA 20120827_BOOTROM_a4_b12_C3 phase = 0x3~0x11,positive = 1, phase=0x13~0x1d, positive=0 is good phase*/
		/*FPGA 20121112_MD_a4_b12_C3 phase = 0x18~0x1f,positive = 0 is good phase*/
		/*FPGA 20121129_MD_a4_b12_C3 phase = 0xd~0x16 positive = 1 is good phase*/
		phase_val = 0x11;
		rx_latch_pos = KAL_TRUE;
	}
	usbdev_printf(USBDEV_UARTDBG_WARN ,"Set A60802B U3 PHY PIPE phase=0x%x, rx_latch_pos=%d\n\r",
																			phase_val, rx_latch_pos);
	
	temp = phase_val << 3;
	/*set U3 MAC to SS.Disable*/
	USBReg_Write32(U3_USB3_CONFIG, 0);
	usb_delay_ms(10);
	temp |= 0x6; //fill max u3ck_drv
	I2cWriteReg(U3_PHY_I2C_DEV_ID, reg_addr, temp);//i2c write phy(0x23) phase range:bit7~bit3
	/*reset USB IP*/
	u3_rst_dev();
	USBReg_Write32(U3_USB3_CONFIG, 0);
	usb_delay_ms(10);

	/*set rx latch edge*/
	if (rx_latch_pos == KAL_TRUE) {
		USBReg_Write32(U3_MAC_PIPE_LATCH_SEL, U3_PIPE_RX_LATCH_POS);
	} else {
		USBReg_Write32(U3_MAC_PIPE_LATCH_SEL, U3_PIPE_RX_LATCH_NEG);				
	}
	
#endif /*USB30_PHY_CAL*/

	SerialCommRelease();


	return 0;
} 
#else /*HAL_PLATFORM_FPGA*/
/*!
 *  @brief  initial U3 PHY configuration
 */
kal_uint32 u3_phy_init(void) 
{
	u3_pwr_init();

	return 0;
}
#endif /*HAL_PLATFORM_FPGA*/

/*!
 *  @brief  set the expect usb isr mask and record the mask value
 *  @param  p_priv,	the endpoint information to configure to hardware registers
 */
void u3_init_intr(void)
{
	kal_uint32 intr_mask = 0;

	/*clear disable all interrupt*/
	USBReg_Write32(U3_DEV_LV1IECR, 0xFFFFFFFF);

	/*set buffer management interrtup, EP interrupt*/
	intr_mask = U3_DEV_EP0ISR | U3_DEV_SETUPENDISR;
	/*clear disable all interrupt*/
	USBReg_Write32(U3_DEV_EPIECR, 0xFFFFFFFF);
	/*set interrupt enable mask*/
	USBReg_Write32(U3_DEV_EPIESR, intr_mask);

	/*set USB2.0 MAC related interrupt*/
	intr_mask = U3_USB2_INTR_SUSPEND | U3_USB2_INTR_RESUME | U3_USB2_INTR_RESET;
	/*set interrupt enable mask*/
	USBReg_Write32(U3_USB2_COMMON_INTR_EN , intr_mask);	

	/*set QMU TX/RX GPD done interrupt*/
	intr_mask = 0x0;
	/*clear disable all interrupt*/
	USBReg_Write32(USB3_QMU_QIECR0, 0xFFFFFFFF);	
	/*set interrupt enable mask*/
	USBReg_Write32(USB3_QMU_QIESR0, intr_mask);
	
	/*set QMU error and queue empty interrupt*/
	intr_mask = U3_TXQ_CSERR_INTR_FLAG | U3_TXQ_LENERR_INTR_FLAG 
										| U3_RXQ_CSERR_INTR_FLAG | U3_RXQ_LENERR_INTR_FLAG;
	/*clear disable all interrupt*/
	USBReg_Write32(USB3_QMU_QIECR1, 0xFFFFFFFF);	
	/*set interrupt enable mask*/
	USBReg_Write32(USB3_QMU_QIESR1, intr_mask);

	/*enable all txq length error and checksum error interrupt*/
	USBReg_Write32(USB3_QMU_TQERRIESR0, 0xFFFFFFFF);
	/*enable all rxq length error and checksum error interrupt*/
	USBReg_Write32(USB3_QMU_RQERRIESR0, 0xFFFFFFFF);

	/*clear USB3.0 MAC bootup dummy interrupt*/
	USBReg_Write32(U3_LTSSM_INTR , (~(U3_LTSSM_VBUS_RISE_INTR | U3_LTSSM_VBUS_FALL_INTR)));
	/*set USB3.0 MAC related interrupt*/
	intr_mask = U3_LTSSM_SS_INACTIVE_INTR | U3_LTSSM_SS_DISABLE_INTR | U3_LTSSM_COMPLIANCE_INTR |
		U3_LTSSM_LOOPBACK_INTR | U3_LTSSM_HOT_RST_INTR | U3_LTSSM_WARM_RST_INTR | U3_LTSSM_RECOVERY_INTR | U3_LTSSM_ENTER_U0_INTR |
		U3_LTSSM_ENTER_U1_INTR | U3_LTSSM_ENTER_U2_INTR | U3_LTSSM_ENTER_U3_INTR | U3_LTSSM_EXIT_U1_INTR | U3_LTSSM_EXIT_U2_INTR |
		U3_LTSSM_EXIT_U3_INTR | U3_LTSSM_RXDET_SUCCESS_INTR | U3_LTSSM_VBUS_RISE_INTR | U3_LTSSM_VBUS_FALL_INTR |
		U3_LTSSM_U3_LFPS_TO_INTR | U3_LTSSM_U3_RESUME_INTR;
	USBReg_Write32(U3_LTSSM_INTR_EN , intr_mask);

	/*set USB speed change interrupt*/
	USBReg_Write32(U3_EPCTL_DEV_LINK_INTR_EN, U3_EPCTL_DEV_SPEED_CHG_INTR);

}

void u3_pwr_p1_p2_setting(void)
{
	//kal_uint32 reg_32 = 0;

	/*set U3 MAC power control*/
	USBReg_Read32(U3_LINK_POWER_CTRL) |= (U3_PWR_AUTO_U1_REQ_EN | U3_PWR_AUTO_U2_REQ_EN | 
											U3_PWR_AUTO_U1_ACCEPT_EN | U3_PWR_AUTO_U2_ACCEPT_EN);
	USBReg_Write32(U3_DEV_MAC_P1_EN, REQ_UX_EP0_INACT_CHK | REQ_UX_TXQ_INACT_CHK | REQ_UX_BMU_RX_EMP_CHK |REQ_UX_BMU_TX_EMP_CHK 
							| ACCEPT_EP0_INACT_CHK | ACCEPT_TXQ_INACT_CHK | ACCEPT_BMU_RX_EMP_CHK | ACCEPT_BMU_TX_EMP_CHK);
	USBReg_Write32(U3_DEV_MAC_P2_EN, REQ_UX_EP0_INACT_CHK | REQ_UX_TXQ_INACT_CHK | REQ_UX_BMU_RX_EMP_CHK |REQ_UX_BMU_TX_EMP_CHK 
							| ACCEPT_EP0_INACT_CHK | ACCEPT_TXQ_INACT_CHK | ACCEPT_BMU_RX_EMP_CHK | ACCEPT_BMU_TX_EMP_CHK);

	//reg_32 = (((DEV_REQ_U1_TIMEOUT & U3_DEV_U1_INACT_TO_MSK) << U3_DEV_U1_INACT_TO_OFFSET) + 
	//			((DEV_REQ_U2_TIMEOUT & U3_DEV_U2_INACT_TO_MSK) << U3_DEV_U2_INACT_TO_OFFSET));
	//USBReg_Write32(U3_LINK_UX_INACT_TIMER, reg_32);
	
}




/*!
 *  @brief  initial U3 mac default setting
 */
void u3_mac_hw_init(void)
{
	kal_uint64 tmp = 0;
	kal_uint32 reg_32 = 0;

	/*initial usb variable*/
	memset(&usb_priv, 0 , sizeof(hifusb_priv_t));
	usb_priv.usb_state = HIFUSB_STATE_PWROFF;
	usb_priv.ep0_pirv.ep0_datain_buf = usb_ep0_buf;
	usb_priv.ep0_pirv.ep0_dataout_buf = usb_ep0_buf;


	/*EP0 MPS set default HS/FS mode and should re-setting after U3/U2 detection flow done*/
	USBReg_Write16(U3_DEV_EP0CSR_REG16_MPS, U3MAC_HS_FS_EP0_MPS);
	

	/*enable MAC reference clock setting*/
	tmp = U3_MAC_REF_CLK_MHZ; //calculate 1us, refernece clock cycle count
	USBReg_Write32(U3_REF_CK_PARAM, tmp & U3_REF_CK_1US_MSK);

	/*set P3 Exit LFPS 300ns detect with ref_clk count*/
	reg_32 = USBReg_Read32(U3_P3_EXIT_LFPS_PARAM);
	reg_32 &= (~(U3_P3_EXIT_LFPS_REF_MSK << U3_P3_EXIT_LFPS_REF_OFFSET));
	reg_32 |= ((U3_P3_LFPS_REF_CLK_CNT & U3_P3_EXIT_LFPS_REF_MSK) << (U3_P3_EXIT_LFPS_REF_OFFSET));
	USBReg_Write32(U3_P3_EXIT_LFPS_PARAM, reg_32);

	/*set USB3.0 System clock 1us ref count*/
	reg_32 = USBReg_Read32(U3_TIMING_PULSE_CTRL);
	reg_32 &= (~U3_SYSCLK_1US_CNT_MSK);
	reg_32 |= U3_MAC_SYS_CLK_1US_CNT;
	USBReg_Write32(U3_TIMING_PULSE_CTRL, reg_32);

	/*set USB2.0 System clock 1us ref count*/
	reg_32 = USBReg_Read32(U3_USB2_TIMING_PARAM);
	reg_32 &= (~U2_SYSCLK_1US_CNT_MSK);
	reg_32 |= U3_MAC_SYS_CLK_1US_CNT;
	USBReg_Write32(U3_USB2_TIMING_PARAM, reg_32);
	
#ifdef USB_IF_TST
	/*enable USB3.0 P1/P2*/
	u3_pwr_p1_p2_setting();
#else
	/*disable all USB power saving in bootrom*/
#endif
	/*disable SUSPEND_M to prevent PHY power down issue*/
	USBReg_Read32(U3_USB2_PWR_MANAGE) &= (~U3_USB2_PM_SUSPENDM_EN);

	/*set most save U2 LPM, have accept configure and longest resume time*/
	/*set beseck=14 because CV3.0 LPM test only try BESL=0~14*/
	reg_32 = ((U3_USB2_LMP_BESLCK_MSK - 1) << U3_USB2_LMP_BESLCK_OFFSET) 
				+ (U3_USB2_LMP_BESLDCK_MSK << U3_USB2_LMP_BESLDCK_OFFSET)
				+ (U3_USB2_LMP_BESLCK_U3_MSK << U3_USB2_LMP_BESLCK_U3_OFFSET);
	USBReg_Write32(U3_USB2_LPM_PARAM, reg_32);

	/*disable software handle exit U3 flow*/
	USBReg_Read32(U3_MAC_LTSSM_CTRL) &= (~U3_MAC_SW_U3_EXIT_EN);

	/*initial interrupt mask for both layer 1 and layer 2*/
	u3_init_intr();
	
#ifdef SIMULATION
	/*set register to make simulation faster*/
	USBReg_Read32(U3_MAC_LTSSM_PARAM) &= (~(U3_MAC_RXDET_CNT_MSK|U3_MAC_RXEQ_CNT_MSK));
	USBReg_Read32(U3_MAC_LTSSM_PARAM) |= ((0x100 << U3_MAC_RXEQ_CNT_OFFSET)|(0x1 << U3_MAC_RXDET_CNT_OFFSET));
	USBReg_Read32(U3_USB2_TIMING_TM) |= U3_USB2_TM1;
	
	SIMULATION_CHECK_POINT_UPDATE(CHECK_USB_MAC_INIT_REG);
#endif
}

void u3_unload_fifo(kal_uint8 nEnd, kal_uint32 ByteCnt, kal_uint8 *pDest)
{
	kal_uint32 Index = 0, Index32 = 0;
	kal_uint32 Count32 = ((kal_uint32)pDest & 3) ? 0 : (ByteCnt >> 2);
	kal_uint32 u3_fifo_32 = 0, fifo_idx = 0, fifo_offset = 0;

	usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s:%s:%d] nEnd=%d, pDest=0x%p, ByteCnt=%d\n\r", 
									__FILE__, __FUNCTION__,__LINE__, nEnd, pDest, ByteCnt);

	/* doublewords when possible */
	for (Index = Index32 = 0; Index32 < Count32; Index32++, Index += 4) {
		*((kal_uint32*)&(pDest[Index])) = U3_FIFO_REG32(nEnd);
	}

	/* Or, only can ready in byte */
	fifo_idx = 0;
	while (Index < ByteCnt) {
		if (fifo_idx == 0) {
			u3_fifo_32 = U3_FIFO_REG32(nEnd);
		}
		fifo_offset = fifo_idx * 8;
		pDest[Index] = (kal_uint8)((u3_fifo_32 & (0xFF << fifo_offset)) >> fifo_offset);
		fifo_idx ++;
		Index ++;
		if (fifo_idx >= 4) {
			fifo_idx = 0;
		}
	}
}

void u3_load_fifo(kal_uint8 nEnd, kal_uint32 ByteCnt, kal_uint8 *pSrc)
{
	kal_uint32 Index = 0, Index32 = 0;
	kal_uint32 Data32 = 0;
	kal_uint32 Count32 = ((kal_uint32)pSrc & 3) ? 0 : (ByteCnt >> 2);
	kal_uint32 u3_fifo_32 = 0, fifo_idx = 0, fifo_offset = 0, remain_len = 0;

	usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s:%s:%d] nEnd=%d\n\r", 
									__FILE__, __FUNCTION__,__LINE__, nEnd);

	usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s:%s:%d] pSrc=0x%p, ByteCnt=%d\n\r", 
									__FILE__, __FUNCTION__,__LINE__, pSrc, ByteCnt);

	if (ByteCnt == 1) {
		usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s:%s:%d] pSrc=0x%p, ByteCnt=%d\n\r", 
									__FILE__, __FUNCTION__,__LINE__, pSrc, ByteCnt);
		
	}
									
	/* doublewords when possible */
	for (Index = Index32 = 0; Index32 < Count32; Index32++, Index += 4) {
		Data32 = *((kal_uint32*)&(pSrc[Index]));
		U3_FIFO_REG32(nEnd) = Data32;
	}

	/* Or, only can write in byte */
	fifo_idx = 0;
	u3_fifo_32 = 0;
	remain_len = ByteCnt - Index;
	while (Index < ByteCnt) {
		fifo_offset = fifo_idx * 8;
		u3_fifo_32 |= (pSrc[Index] << fifo_offset);
		fifo_idx ++;
		Index ++;
		if (fifo_idx >= 4) {
			U3_FIFO_REG32(nEnd) = u3_fifo_32;
			u3_fifo_32 = 0;
			fifo_idx = 0;
			remain_len = ByteCnt - Index;
		} else if (Index == ByteCnt) { //write remain data
			if (remain_len == 3) {
				U3_FIFO_REG16(nEnd) = (kal_uint16)(u3_fifo_32 & 0xFFFF);
				U3_FIFO_REG8(nEnd) = (kal_uint8)(u3_fifo_32 >> 16);
			}
			if (remain_len == 2) {
				U3_FIFO_REG16(nEnd) = (kal_uint16)(u3_fifo_32 & 0xFFFF);
			}
			if (remain_len == 1) {
				U3_FIFO_REG8(nEnd) = (kal_uint8)(u3_fifo_32 & 0xFF);
			}				
		}
	}
}

/*!
 *  @brief  translate the fifo addr form bytes unit to register value, 8 x reg bytes
 *  @param  fifo_addr , the fifo address in bytes
 *  @param  p_reg_val , the register value stand for the fifo address
 *	@return KAL_FALSE when the fifo address is not valid, KAL_TRUE when success
 */
kal_bool u3_calc_fifoaddr_reg_val(kal_uint32 fifo_addr , kal_uint32 *p_reg_val)
{
	kal_bool ret = KAL_TRUE;
	kal_uint32 reg_val = 0;
	
	if (fifo_addr & 0x10) {
		ret = KAL_FALSE;
	} else {
		reg_val = fifo_addr >> 0x4;
		*p_reg_val = reg_val;
	}
	
	return ret;
}

/*!
 *  @brief  translate the fifo size form bytes unit to register value, 8 x 2^reg bytes
 *  @param  fifo_sz , the fifo size in bytes
 *  @param  p_reg_val , the register value stand for the fifo size
 *	@return KAL_FALSE when the fifo size is not valid, KAL_TRUE when success
 */
kal_bool u3_calc_fifosz_reg_val(kal_uint32 fifo_sz , kal_uint32 *p_reg_val)
{
	kal_bool ret = KAL_TRUE;
	kal_uint32 reg_val = 0;

	if ((fifo_sz < 0x10) || (fifo_sz & 0x1)) {
		ret = KAL_FALSE;
	} else {
		while(1) {
			if (fifo_sz == 0x1) {
				/*fifo size translate done*/
				break;
			} else if (fifo_sz & 0x1){
				/*means the fifo size illegal*/
				ret = KAL_FALSE;
				break;
			} else {
				reg_val ++;
				fifo_sz >>= 1;
			}
		}
	}

	if (ret == KAL_TRUE) {
		*p_reg_val = reg_val;
	}
	
	return ret;
}

/*!
 *  @brief  configure USB QMU EN/CS/ZLP/COZ ...etc.
 *	@return KAL_TRUE if success , KAL_FALSE when error
 */
kal_bool u3_config_ep_que_hw(void)
{
	kal_bool ret = KAL_TRUE;
	kal_uint32 que_cnt = 0;
	kal_uint8 ep_num = 0, ep_idx = 0;
	EndpointResource *p_ep_cfg = NULL;
	kal_uint32 fifo_addr = 0, fifo_size = 0;
	kal_uint32 fifo_sz_regval = 0 , fifo_addr_regval = 0, csr1_reg32 = 0;


	/*clear before configure*/
	*USB3_QMU_QCR0 = 0;
	*USB3_QMU_QCR1 = 0;
	*USB3_QMU_QCR2 = 0;
	*USB3_QMU_QCR3= 0;
	*USB3_QMU_QGCSR = 0;

	/*configure USB QMU CS12*/
	*USB3_QMU_QCR0 &= (~U3_DQMU_CS16_EN);


	/*
	 *	Configure QMU DMA setting, TX/RX DMA AXI burst size <= 64byte on MT7208 for platform limitation
	*/
	/*configure TX DMA burst size*/
	USBReg_Write32(U3_DEV_TXDMARLCOUNT, (U3_DMA_BURST_64 << U3_TX_DMA_BURST_OFFSET));
	/*configure RX DMA burst size*/
	USBReg_Write32(U3_DEV_RXDMARLCOUNT, (U3_DMA_BURST_64 << U3_RX_DMA_BURST_OFFSET));
	/*configure EP0 DMA burst size*/
	USBReg_Write32(U3_DEV_EP0DMARLCOUNT, (U3_DMA_BURST_64 << U3_EP0_DMA_BURST_OFFSET));

	/*
	 *	EP0 HW configuration
	 *	EP0 FIFO is independent with max 512 BYTES in U3 IP and don't have to set the FIFO address
	 *	only set max pkt size
	*/
	p_ep_cfg = &usb_priv.ep0_config;
	USBReg_Write16(U3_DEV_EP0CSR_REG16_MPS, (p_ep_cfg->MaxPacketSize & U3_EP0_MPS_MSK));


	/*TXQ (dev to host)*/
	fifo_addr = 0; //TX fifo address start from 0	
	for(ep_idx = 0; ep_idx < USB_ACM_IN_EP_NUM ; ep_idx ++) {
		p_ep_cfg = &usb_priv.tx_ep_config[ep_idx];
		ep_num = p_ep_cfg->nEnd;
		que_cnt = HIFUSB_EPNO_2_QNO(ep_num);
		/*set qmu enable*/
		*USB3_QMU_QGCSR |= USB3_QMU_TX_EN(que_cnt);

		/*configure per que cs enable*/
		*USB3_QMU_QCR0 |= U3_DQMU_TQCS_EN(que_cnt);
		
		/*configure USBQ ZLP condition*/
		*USB3_QMU_QCR2 |= U3_DQMU_TX_ZLP(que_cnt);

		/*configure ep fifo address and fifo size*/
		fifo_size = p_ep_cfg->MaxPacketSize * p_ep_cfg->MutiFifoU3Burst;

		/*set the FIFO size , the u3 IP FIFO size is the MPS*/
		if (KAL_FALSE == u3_calc_fifosz_reg_val(p_ep_cfg->MaxPacketSize , &fifo_sz_regval)) {
			return KAL_FALSE;
		}		
		USBReg_Read32(U3_TXCSR2_ADDR(ep_num)) &= (~(U3_TXEP_REG32_FIFOSZ_MSK << U3_TXEP_REG32_FIFOSZ_OFFSET));
		USBReg_Read32(U3_TXCSR2_ADDR(ep_num)) |= ((fifo_sz_regval & U3_TXEP_REG32_FIFOSZ_MSK) << U3_TXEP_REG32_FIFOSZ_OFFSET);

		/*set the FIFO address*/		
		if (KAL_FALSE == u3_calc_fifoaddr_reg_val(fifo_addr, &fifo_addr_regval)) {
			return KAL_FALSE;
		}
		USBReg_Read32(U3_TXCSR2_ADDR(ep_num)) &= (~(U3_TXEP_REG32_FIFOADDR_MSK << U3_TXEP_REG32_FIFOADDR_OFFSET));
		USBReg_Read32(U3_TXCSR2_ADDR(ep_num)) |= ((fifo_addr_regval & U3_TXEP_REG32_FIFOADDR_MSK) << U3_TXEP_REG32_FIFOADDR_OFFSET);		

		/*set max packet size*/
		USBReg_Read16(U3_TXCSR0_REG16_MPS_ADDR(ep_num)) = p_ep_cfg->MaxPacketSize & U3_TXEP_MPS_MSK;

		/*configure TXEP CSR*/
		csr1_reg32 = 0;
		/*set DMAReqEn = 1 and AutoSet = 0 for QMU DMA operation*/
		USBReg_Read16(U3_TXCSR0_REG16_CTL_ADDR(ep_num)) = U3_TXEP_REG16_DMAREQEN;
		
		/*set endpoint transfer type*/
		switch (p_ep_cfg->type) {
			case HIFUSB_EP_XFER_TYPE_INT:
				csr1_reg32 |= (U3_TXEP_REG32_TXTYPE_INT << U3_TXEP_REG32_TXTYPE_OFFSET);
				break;
			case HIFUSB_EP_XFER_TYPE_ISOC:
				csr1_reg32 |= (U3_TXEP_REG32_TXTYPE_ISO << U3_TXEP_REG32_TXTYPE_OFFSET);
				break;
			case HIFUSB_EP_XFER_TYPE_BULK:
			default :
				csr1_reg32 |= (U3_TXEP_REG32_TXTYPE_BULK << U3_TXEP_REG32_TXTYPE_OFFSET);
				break;
		}
		
		if (usb_priv.usb_statistic.usb_cur_speed == HIFUSB_USB_SPEED_USB30) { //USB3.0
			/*
			 *	USB3.0 BURST=N, TX_MULT=0,TX_MAX_PKT=0, SLOT means multiple of Nth FIFO and the value should be N-1
			*/				
			csr1_reg32 |= (((p_ep_cfg->MutiFifoU3Burst - 1) & U3_TXEP_REG32_TXSLOT_MSK) << U3_TXEP_REG32_TXSLOT_OFFSET);
			csr1_reg32 |= (((p_ep_cfg->MutiFifoU3Burst - 1) & U3_TXEP_REG32_SSBURST_MSK) << U3_TXEP_REG32_SSBURST_OFFSET);
		} else { //USB2.0
			/*
			 *	USB2.0 BURST, TX_MULT, TX_MAX_PKT = 0, SLOT means multiple of Nth FIFO and the value should be N-1
			*/				
			csr1_reg32 |= (((p_ep_cfg->MutiFifoU3Burst - 1) & U3_TXEP_REG32_TXSLOT_MSK) << U3_TXEP_REG32_TXSLOT_OFFSET);
		}
		USBReg_Write32(U3_TXCSR1_ADDR(ep_num), csr1_reg32);
		fifo_addr += fifo_size;
	}

	/*RXQ (host to dev)*/
	fifo_addr = 0; //RX fifo address start from 0	
	for(ep_idx = 0; ep_idx < USB_ACM_OUT_EP_NUM ; ep_idx ++) {
		p_ep_cfg = &usb_priv.rx_ep_config[ep_idx];
		ep_num = p_ep_cfg->nEnd;
		que_cnt = HIFUSB_EPNO_2_QNO(ep_num);

		/*set qmu enable*/
		*USB3_QMU_QGCSR |= USB3_QMU_RX_EN(que_cnt);

		/*configure per que cs enable*/
		*USB3_QMU_QCR0 |= U3_DQMU_RQCS_EN(que_cnt);

		/*RX_ZLP would make ACM like transfer LEN ERR*/		

		/*configure ep fifo address and fifo size*/
		fifo_size = p_ep_cfg->MaxPacketSize * p_ep_cfg->MutiFifoU3Burst;

		/*set the FIFO size , the u3 IP FIFO size is the MPS*/
		if (KAL_FALSE == u3_calc_fifosz_reg_val( p_ep_cfg->MaxPacketSize, &fifo_sz_regval)) {
			return KAL_FALSE;
		}		
		USBReg_Read32(U3_RXCSR2_ADDR(ep_num)) &= (~(U3_RXEP_REG32_FIFOSZ_MSK << U3_RXEP_REG32_FIFOSZ_OFFSET));
		USBReg_Read32(U3_RXCSR2_ADDR(ep_num)) |= ((fifo_sz_regval & U3_RXEP_REG32_FIFOSZ_MSK) << U3_RXEP_REG32_FIFOSZ_OFFSET);

		/*set the FIFO address*/		
		if (KAL_FALSE == u3_calc_fifoaddr_reg_val(fifo_addr, &fifo_addr_regval)) {
			return KAL_FALSE;
		}
		USBReg_Read32(U3_RXCSR2_ADDR(ep_num)) &= (~(U3_RXEP_REG32_FIFOADDR_MSK << U3_RXEP_REG32_FIFOADDR_OFFSET));
		USBReg_Read32(U3_RXCSR2_ADDR(ep_num)) |= ((fifo_addr_regval & U3_RXEP_REG32_FIFOADDR_MSK) << U3_RXEP_REG32_FIFOADDR_OFFSET);		

		/*set max packet size*/
		USBReg_Read16(U3_RXCSR0_REG16_MPS_ADDR(ep_num)) = p_ep_cfg->MaxPacketSize & U3_RXEP_MPS_MSK;

		/*configure RXEP CSR*/
		csr1_reg32 = 0;
		/*set DMAReqEn = 1 and AutoClr = 0 for QMU DMA operation*/
		USBReg_Read16(U3_RXCSR0_REG16_CTL_ADDR(ep_num)) = U3_RXEP_REG16_DMAREQEN;
		
		/*set endpoint transfer type, U2 RX INT EP would auto disable NYET by the RXTYPE setting*/
		switch (p_ep_cfg->type) {
			case HIFUSB_EP_XFER_TYPE_INT:
				csr1_reg32 |= (U3_RXEP_REG32_RXTYPE_INT << U3_RXEP_REG32_RXTYPE_OFFSET);
				break;
			case HIFUSB_EP_XFER_TYPE_ISOC:
				csr1_reg32 |= (U3_RXEP_REG32_RXTYPE_ISO << U3_RXEP_REG32_RXTYPE_OFFSET);
				break;
			case HIFUSB_EP_XFER_TYPE_BULK:
			default :
				csr1_reg32 |= (U3_RXEP_REG32_RXTYPE_BULK << U3_RXEP_REG32_RXTYPE_OFFSET);
				break;
		}
		if (usb_priv.usb_statistic.usb_cur_speed == HIFUSB_USB_SPEED_USB30) { //USB3.0
			/*
			 *	USB3.0 BURST=N, TX_MULT=0,TX_MAX_PKT=0, SLOT means multiple of Nth FIFO and the value should be N-1
			*/				
			csr1_reg32 |= (((p_ep_cfg->MutiFifoU3Burst - 1) & U3_RXEP_REG32_RXSLOT_MSK) << U3_RXEP_REG32_RXSLOT_OFFSET);
			csr1_reg32 |= (((p_ep_cfg->MutiFifoU3Burst - 1) & U3_RXEP_REG32_SSBURST_MSK) << U3_RXEP_REG32_SSBURST_OFFSET);
		} else { //USB2.0
			/*
			 *	USB2.0 BURST, RX_MULT, RX_MAX_PKT = 0, SLOT means multiple of Nth FIFO and the value should be N-1
			*/				
			csr1_reg32 |= (((p_ep_cfg->MutiFifoU3Burst - 1) & U3_RXEP_REG32_RXSLOT_MSK) << U3_RXEP_REG32_RXSLOT_OFFSET);
		}
		USBReg_Write32(U3_RXCSR1_ADDR(ep_num), csr1_reg32);

		fifo_addr += fifo_size;
	}

	return ret;
}


void u3_set_acm_desc_by_speed(hifusb_usb_speed_e speed)
{

    switch (speed)
    {
        case HIFUSB_USB_SPEED_USB11:
        {
            usbc_mode_speed_change_cdc_acm_usb11();
            break;
        }
        case HIFUSB_USB_SPEED_USB30:
        {
            usbc_mode_speed_change_cdc_acm_usb30();
            break;
        }
        case HIFUSB_USB_SPEED_USB20:
        default:
        {
            usbc_mode_speed_change_cdc_acm_usb20();
            break;
        }
    }

}

void u3_config_ep_setting_by_acm_desc(void)
{
	EndpointResource *p_ep_cfg = NULL;
	kal_uint8 ep_num = 0, ep_idx = 0;

	/*configure ep0 setting*/
	p_ep_cfg = &usb_priv.ep0_config;
	if (usb_priv.usb_statistic.usb_cur_speed == HIFUSB_USB_SPEED_USB30) {
		p_ep_cfg->MaxPacketSize = HIFUSB_SS_EP0_MPS;
	} else {
		p_ep_cfg->MaxPacketSize = HIFUSB_HS_EP0_MPS;
	}
	p_ep_cfg->nEnd = 0;
	p_ep_cfg->MutiFifoU3Burst = 1;
	p_ep_cfg->type = HIFUSB_EP_XFER_TYPE_CONTROL;
	
	/*configure ACM data out*/
	ep_num = (~USBC_EP_ADDR_DIR_IN) & usbc_configuration_descriptor_cdc_acm.dataout_endpoint_descriptor.bEndpointAddress;
	ep_idx = ep_num - 1;
	p_ep_cfg = &usb_priv.rx_ep_config[ep_idx];
	p_ep_cfg->nEnd = ep_num;
	p_ep_cfg->MaxPacketSize = usbc_configuration_descriptor_cdc_acm.dataout_endpoint_descriptor.wMaxPacketSize;
	p_ep_cfg->MutiFifoU3Burst = U3_USB30_MULTI_FIFO_CNT;
	p_ep_cfg->type = HIFUSB_EP_XFER_TYPE_BULK;

	/*configure ACM data in*/
	ep_num = (~USBC_EP_ADDR_DIR_IN) & usbc_configuration_descriptor_cdc_acm.datain_endpoint_descriptor.bEndpointAddress;
	ep_idx = ep_num - 1;
	p_ep_cfg = &usb_priv.tx_ep_config[ep_idx];
	p_ep_cfg->nEnd = ep_num;
	p_ep_cfg->MaxPacketSize = usbc_configuration_descriptor_cdc_acm.datain_endpoint_descriptor.wMaxPacketSize;
	p_ep_cfg->MutiFifoU3Burst = U3_USB30_MULTI_FIFO_CNT;
	p_ep_cfg->type = HIFUSB_EP_XFER_TYPE_BULK;

	/*configure ACM communication in*/
	ep_num = (~USBC_EP_ADDR_DIR_IN) & usbc_configuration_descriptor_cdc_acm.commin_endpoint_descriptor.bEndpointAddress;
	ep_idx = ep_num - 1;
	p_ep_cfg = &usb_priv.tx_ep_config[ep_idx];
	p_ep_cfg->nEnd = ep_num;
	p_ep_cfg->MaxPacketSize = usbc_configuration_descriptor_cdc_acm.commin_endpoint_descriptor.wMaxPacketSize;
	p_ep_cfg->MutiFifoU3Burst = U3_USB30_MULTI_FIFO_CNT;
	p_ep_cfg->type = HIFUSB_EP_XFER_TYPE_INT;

}

void u3_set_connect(void) 
{
	kal_uint32 reg_32 = 0;

	/*set usb state for interrupt handle and state machine maintain*/
	usb_priv.usb_state = HIFUSB_STATE_ATTACHED;

	reg_32 = USBReg_Read32(U3_EPCTL_DEV_CONFIG);
	/*set select U2/U3 by hardware*/
	reg_32 &= (~U3_EPCTL_SW_SEL_U2_U3_EN);
	USBReg_Write32(U3_EPCTL_DEV_CONFIG , reg_32);
	/*set RX detect count 8 for initial*/
	USBReg_Read32(U3_MAC_LTSSM_PARAM) &= (~U3_MAC_RXDET_CNT_MSK);
	USBReg_Read32(U3_MAC_LTSSM_PARAM) |= (U3_INIT_RXDET_CNT << U3_MAC_RXDET_CNT_OFFSET);
	/*set the U3/U2 selection flow disable count*/
	USBReg_Read32(U3_MAC_LTSSM_PARAM) &= (~U3_MAC_DISABLE_CNT_MSK);
	USBReg_Read32(U3_MAC_LTSSM_PARAM) |= (U3_U2_SEL_DISABLE_CNT << U3_MAC_DISABLE_CNT_OFFSET);
	/*set U3 attach to start the U3/U2 selection flow*/
	USBReg_Read32(U3_USB3_CONFIG) |= USB3_EN;
}

void u3_set_disconnect(void) 
{
 
	/*should make sure both U2 andU3 disconnected*/
	USBReg_Read32(U3_USB3_CONFIG) &= (~USB3_EN);
	USBReg_Read32(U3_USB2_PWR_MANAGE) &= (~U3_USB2_PM_SOFT_CONN);

	/*delay 500ms for connect/disconnect compatibility*/
	usb_delay_ms(500);
 }

void u3_set_u2_connect(void)
{
	USBReg_Read32(U3_USB2_PWR_MANAGE) |= U3_USB2_PM_SOFT_CONN;
}

void u3_set_u2_disconnect(void)
{
	USBReg_Read32(U3_USB2_PWR_MANAGE) &= (~U3_USB2_PM_SOFT_CONN);
}

kal_bool u3_reset_isr_handle(hifusb_priv_t *p_priv)
{
	kal_bool ret = KAL_TRUE;

	/*configure the endpoint by current speed mode*/
	u3_set_acm_desc_by_speed(p_priv->usb_statistic.usb_cur_speed);

	/*configure the new endpoint software setting*/
	u3_config_ep_setting_by_acm_desc();

	/*configure the endpoint hardware setting by speed*/
	u3_config_ep_que_hw();

	return ret;
}

void hifusb_stop_all_acm_queue(void)
{
	kal_uint8 q_num = 0;
	kal_bool is_tx = KAL_TRUE;

	q_num = HIFUSB_EPNO_2_QNO(USBC_ACM_COMM_IN_EP);
	is_tx = KAL_TRUE;
	HIF_QMU_STOP(is_tx, q_num);
	HIF_QMU_CHK_STOP_COMPLETE(is_tx, q_num);

	q_num = HIFUSB_EPNO_2_QNO(USBC_ACM_DATA_IN_EP);
	is_tx = KAL_TRUE;
	HIF_QMU_STOP(is_tx, q_num);
	HIF_QMU_CHK_STOP_COMPLETE(is_tx, q_num);
	
	q_num = HIFUSB_EPNO_2_QNO(USBC_ACM_DATA_OUT_EP);
	is_tx = KAL_FALSE;
	HIF_QMU_STOP(is_tx, q_num);
	HIF_QMU_CHK_STOP_COMPLETE(is_tx, q_num);

}

void hifusb_set_usb_address(kal_uint8 address)
{
	hifusb_ep0_priv_t *p_ep0_priv;
	p_ep0_priv = &usb_priv.ep0_pirv;

	if (usb_priv.usb_state < HIFUSB_STATE_ADDR) {
		/*initial acm related variable for new connection*/
		memset((void*)acm_if_setting, 0, sizeof(acm_if_setting));
		memset((void*)&dev_status, 0, sizeof(dev_status));
		memset((void*)interface_status, 0, sizeof(interface_status));
	}
	
	p_ep0_priv->update_dev_addr = address;

	
	if (address == 0) {
		usb_priv.usb_state = HIFUSB_STATE_DEFAULT;
	} else {
		usb_priv.usb_state = HIFUSB_STATE_ADDR;
	}
}

void hifusb_set_usb_configuration(kal_uint8 configuration)
{
	usb_priv.usb_statistic.usb_val_config = configuration;
	if (configuration == USBC_DEV_CONFIG_DEF_VAL) { //set configure value = 0 to return address state
		usb_priv.usb_state = HIFUSB_STATE_ADDR;
	} else {
		usb_priv.usb_state = HIFUSB_STATE_CONFIG;
	}
	/*
	 *	should reset all EP except EP0 sequence number(USB3.0) ,toggle(USB2.0) and FIFO
	 *	
	*/

	//stop all queue
	hifusb_stop_all_acm_queue();
	//reset ep fifo, sequence number and data toggle
	USBReg_Write32(U3_EPCTL_EP_RST, (U3_EPCTL_EPN_IN_RST_MSK|U3_EPCTL_EPN_OUT_RST_MSK)); //don't reset EP0
	USBReg_Write32(U3_EPCTL_EP_RST, ~(U3_EPCTL_EPN_IN_RST_MSK|U3_EPCTL_EPN_OUT_RST_MSK|U3_EPCTL_EP0_RST)); //don't reset EP0
}
/*only used when USB2.0 mode*/
kal_bool hifusb_set_usb_testmode(hifusb_test_mode_e testmode)
{
	kal_bool ret = KAL_TRUE;

	hifusb_ep0_priv_t *p_ep0_priv;

	p_ep0_priv = &usb_priv.ep0_pirv;

	p_ep0_priv->testmode = testmode;
	
	return ret;
}

hifusb_state_e usb_get_protocol_st(void)
{
	return usb_priv.usb_state;
}

hifusb_control_request_type_e usb_ep0_set_address(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len)
{
	hifusb_control_request_type_e ret = 0;
	kal_uint8 addr = 0;

	*p_len = 0;
	ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;

	addr = p_setup->wValue & USBC_DEV_ADDR_MASK;
	hifusb_set_usb_address(addr);
	
	return ret;
}

hifusb_control_request_type_e usb_ep0_set_interface(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len)
{
	hifusb_control_request_type_e ret = 0;
	kal_uint16 if_num = 0, alt_set = 0;
	
	*p_len = 0;
	ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;

	if_num = p_setup->wIndex;
	alt_set = p_setup->wValue;
	if (p_setup->wIndex == USBC_INTERFACE_MTK_COM_0) {
		acm_if_setting[USBC_INTERFACE_MTK_COM_0] = alt_set;
	} else if (p_setup->wIndex == USBC_INTERFACE_MTK_COM_1) {
		acm_if_setting[USBC_INTERFACE_MTK_COM_1] = alt_set;
	} else {
		ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
	}
		
	return ret;
}

hifusb_control_request_type_e usb_ep0_get_interface(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len)
{
	hifusb_control_request_type_e ret = 0;
	kal_uint16 if_num = 0, alt_set = 0;
	
	ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
	*p_len = 1/*alt setting length*/;

	if_num = p_setup->wIndex;
	if (p_setup->wIndex == USBC_INTERFACE_MTK_COM_0) {
		alt_set =acm_if_setting[USBC_INTERFACE_MTK_COM_0];
	} else if (p_setup->wIndex == USBC_INTERFACE_MTK_COM_1) {
		alt_set = acm_if_setting[USBC_INTERFACE_MTK_COM_1];
	} else {
		ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
		*p_len = 0;
	}
	memcpy(p_buf, (void*)&alt_set, *p_len);
	ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;
		
	return ret;
}


hifusb_control_request_type_e usb_ep0_set_config(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len)
{
	hifusb_control_request_type_e ret = 0;
	kal_uint8 config = 0;

	*p_len = 0;
	ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;

	config = p_setup->wValue & 0xFF;
	/*only support valid configure value and default configure value*/
	if ((config == USBC_DEV_CONFIG_ACM_VAL) || (config == USBC_DEV_CONFIG_DEF_VAL)) {
		hifusb_set_usb_configuration(config);

		/*USB speed is confirmed and configure the data path*/
		brom_bm_init(usb_priv.rx_ep_config[HIFUSB_EPNO_2_QNO(USBC_ACM_DATA_OUT_EP)].MaxPacketSize, KAL_FALSE);
	} else {
		ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
	}
	
	return ret;
}

hifusb_control_request_type_e usb_ep0_get_config(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len)
{
	hifusb_control_request_type_e ret = 0;
	kal_uint8 *buffer = NULL;

	*p_len = 1;
	ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;

	buffer = (kal_uint8 *)p_buf;
	buffer[0] = 0xff & usb_priv.usb_statistic.usb_val_config;
	
	return ret;
}


hifusb_control_request_type_e usb_ep0_get_desc(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len)
{
	hifusb_control_request_type_e ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;
	kal_uint8 desc_type = 0, str_idx = 0;
	kal_uint16 wValue = 0, wLength = 0;
	

	wValue = p_setup->wValue;
	wLength = p_setup->wLength;
	desc_type = wValue >> 8;
	if ((p_setup->bmRequestType & USBC_REQUEST_RECIP_MASK) == USBC_REQUEST_RECIP_DEVICE) {
		switch (desc_type) {
			case USBC_DT_DEVICE:
				*p_len = HIFUSB_MIN(usbc_device_descriptor_cdc_acm.bLength, wLength);
				memcpy(p_buf, (void*)(&usbc_device_descriptor_cdc_acm), *p_len);
				ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;
				break;
			case USBC_DT_CONFIG:
				*p_len = usbc_cpy_config_desc_by_speed(usb_priv.usb_statistic.usb_cur_speed, (kal_uint8 *)p_buf, wLength, KAL_FALSE);
 				ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;			
				break;
			case USBC_DT_OTHER_SPEED: /*only HS/FS support spec.9.4.3*/
				if (usb_priv.usb_statistic.usb_cur_speed == HIFUSB_USB_SPEED_USB20) {
					*p_len = usbc_cpy_config_desc_by_speed(HIFUSB_USB_SPEED_USB11, (kal_uint8 *)p_buf, wLength, KAL_TRUE);
	 				ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;			
				} else if (usb_priv.usb_statistic.usb_cur_speed == HIFUSB_USB_SPEED_USB11) {
					*p_len = usbc_cpy_config_desc_by_speed(HIFUSB_USB_SPEED_USB20, (kal_uint8 *)p_buf, wLength, KAL_TRUE);
	 				ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;			
				} else {
					*p_len = 0;
					ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
				}
				break;
			case USBC_DT_DEVICE_QUALIFIER: /*only HS/FS support spec.9.4.3*/
				/*same qualifier desc for both HS and FS*/
				if ((usb_priv.usb_statistic.usb_cur_speed == HIFUSB_USB_SPEED_USB20) ||
									(usb_priv.usb_statistic.usb_cur_speed == HIFUSB_USB_SPEED_USB11)) {
					*p_len = HIFUSB_MIN(usbc_device_qualifier_descriptor_cdc_acm.bLength, wLength);
					memcpy(p_buf, (void*)(&usbc_device_qualifier_descriptor_cdc_acm), *p_len);
					ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;			
				} else {
					*p_len = 0;
					ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
				}
				break;
			case USBC_DT_STRING:
				str_idx = wValue & 0xFF;
				switch (str_idx) {
					case USBC_DEF_STR_IDX_LANGUAGE:
						*p_len = HIFUSB_MIN(p_language_str_desc->bLength, wLength);
						memcpy(p_buf, (void*)p_language_str_desc, *p_len);
						ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;
						break;
					case USBC_DEF_STR_IDX_MANUFACTURER:
						*p_len = HIFUSB_MIN(p_manuf_str_desc->bLength, wLength);
						memcpy(p_buf, (void*)p_manuf_str_desc, *p_len);
						ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;
						break;
					case USBC_DEF_STR_IDX_PRODUCT:
						*p_len = HIFUSB_MIN(p_product_str_desc->bLength, wLength);
						memcpy(p_buf, (void*)p_product_str_desc, *p_len);
						ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;
						break;
					case USBC_DEF_STR_IDX_SERIALNUM:
						*p_len = HIFUSB_MIN(p_sn_str_desc->bLength, wLength);
						memcpy(p_buf, (void*)p_sn_str_desc, *p_len);
						ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;
						break;
					default:
						*p_len = 0;
						ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
						break;
				}
				break;
			case USBC_DT_BOS:
				*p_len = HIFUSB_MIN(usbc_bos_descriptor_cdc_acm.bos_descriptor.wTotalLength, wLength);
				memcpy(p_buf, (void*)(&usbc_bos_descriptor_cdc_acm), *p_len);
				ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;			
				break;
			default:
				*p_len = 0;
				ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
				break;
		}
	} else {
		*p_len = 0;
		ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
	}
	
	return ret;
}

hifusb_control_request_type_e usb_ep0_get_status(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len)
{
	hifusb_control_request_type_e ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;
	kal_uint8 ep_num = 0;
	kal_uint16 wValue = 0, wLength = 0, wIndex = 0;
	kal_uint8 status[2] = {0x0, 0x0};

	wValue = p_setup->wValue;
	wLength = p_setup->wLength;
	wIndex = p_setup->wIndex;
	switch (p_setup->bmRequestType & USBC_REQUEST_RECIP_MASK) {
		case USBC_REQUEST_RECIP_DEVICE:
			/*
			 *	bootrom don't support remote wakeup
			 *	bootrom default bus power
			*/
			*p_len = HIFUSB_MIN(wLength, 2/*status length*/);
			memcpy(p_buf, (void*)&dev_status, *p_len);
			ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;
			break;
		case USBC_REQUEST_RECIP_INTERFACE:
			/*default no interface status assert for both USB2.0 and USB3.0*/
			*p_len = HIFUSB_MIN(wLength, 2/*status length*/);
			memcpy(p_buf, (void*)status, *p_len);
			ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;
			break;
		case USBC_REQUEST_RECIP_ENDPOINT:
			ep_num = (kal_uint8)(wIndex & (~USBC_EP_ADDR_DIR_IN));
			if ((wIndex & USBC_EP_ADDR_DIR_IN) == USBC_EP_ADDR_DIR_IN) {
				/*Device to Host endpoint and check if EP STALL state set*/
				status[0] = ((USBReg_Read16(U3_TXCSR0_REG16_CTL_ADDR(ep_num)) & U3_TXEP_REG16_SENDSTALL) ? 1 : 0);
			} else {
				/*Host to Device endpoint and check if EP STALL state set*/
				status[0] = ((USBReg_Read16(U3_RXCSR0_REG16_CTL_ADDR(ep_num)) & U3_RXEP_REG16_SENDSTALL) ? 1 : 0);
			}
			*p_len = HIFUSB_MIN(wLength, 2/*status length*/);
			memcpy(p_buf, (void*)status, *p_len);
			ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;
			break;
		default:
			ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
			*p_len = 0;
			break;
	}
	
	return ret;
}

void u3_set_ep_stall(kal_bool is_tx, kal_uint8 nEnd)
{
	kal_uint8 q_num = 0;
	kal_uint16 reg_16 = 0;

	q_num = HIFUSB_EPNO_2_QNO(nEnd);

	/*must stop queue before set SEND_STALL, this is the hardware limitation*/
	HIF_QMU_STOP(is_tx, q_num);
	HIF_QMU_CHK_STOP_COMPLETE(is_tx, q_num);

	/*set ep stall*/
	if (is_tx) {
		reg_16 = USBReg_Read16(U3_TXCSR0_REG16_CTL_ADDR(nEnd));
		reg_16 &= (~U3_TXEP_REG16_TXPKTRDY);
		reg_16 |= U3_TXEP_REG16_SENDSTALL;
		USBReg_Write16(U3_TXCSR0_REG16_CTL_ADDR(nEnd), reg_16);
	} else {
		reg_16 = USBReg_Read16(U3_RXCSR0_REG16_CTL_ADDR(nEnd));
		reg_16 &= (~U3_RXEP_REG16_RXPKTRDY);
		reg_16 |= U3_RXEP_REG16_SENDSTALL;
		USBReg_Write16(U3_RXCSR0_REG16_CTL_ADDR(nEnd), reg_16);
	}
	
}

void u3_clr_ep_stall(kal_bool is_tx, kal_uint8 nEnd)
{
	kal_uint8 q_num = 0;
	kal_uint16 reg_16 = 0;

	q_num = HIFUSB_EPNO_2_QNO(nEnd);

	/*
	 *	stop queue again to prevent had started
	 *	must confirm stop queue before reset EP fifo
	*/
	HIF_QMU_STOP(is_tx, q_num);
	HIF_QMU_CHK_STOP_COMPLETE(is_tx, q_num);

	//reset ep fifo, sequence number and data toggle before restart this endpoint and queue
	if (is_tx) {
		USBReg_Write32(U3_EPCTL_EP_RST, U3_EPCTL_EPN_IN_RST(nEnd)); 
		USBReg_Write32(U3_EPCTL_EP_RST, 0); 
	} else {
		USBReg_Write32(U3_EPCTL_EP_RST, U3_EPCTL_EPN_OUT_RST(nEnd)); 
		USBReg_Write32(U3_EPCTL_EP_RST, 0); 
	}
	
	/*clear stall*/
	if (is_tx) {
		/*reset buffer to restart queue to restart at next hifusb_send_tx_data*/
		brom_tgpd.in_use = KAL_FALSE;
		/*set TGPD HWO=0 to leave current waiting*/
		QBM_DES_CLR_HWO(&brom_tgpd.data_gpd);

		reg_16 = USBReg_Read16(U3_TXCSR0_REG16_CTL_ADDR(nEnd));
		reg_16 &= (~(U3_TXEP_REG16_TXPKTRDY | U3_TXEP_REG16_SENDSTALL));
		reg_16 |= U3_TXEP_REG16_SENTSTALL;
		USBReg_Write16(U3_TXCSR0_REG16_CTL_ADDR(nEnd), reg_16);
	} else {
		/*reset buffer to restart queue to restart at next hifusb_get_rx_data*/
		brom_rgpd.in_use = KAL_FALSE;
		
		reg_16 = USBReg_Read16(U3_RXCSR0_REG16_CTL_ADDR(nEnd));
		reg_16 &= (~(U3_RXEP_REG16_RXPKTRDY | U3_RXEP_REG16_SENDSTALL));
		reg_16 |= U3_RXEP_REG16_SENTSTALL;
		USBReg_Write16(U3_RXCSR0_REG16_CTL_ADDR(nEnd), reg_16);
	}

}

hifusb_control_request_type_e usb_ep0_set_feature(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len)
{
	hifusb_control_request_type_e ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
	kal_uint8 ep_num = 0;
	kal_uint16 wValue = 0, wLength = 0, wIndex = 0;

	wValue = p_setup->wValue;
	wLength = p_setup->wLength;
	wIndex = p_setup->wIndex;
	switch (p_setup->bmRequestType & USBC_REQUEST_RECIP_MASK) {
		case USBC_REQUEST_RECIP_DEVICE:
			ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
			*p_len = 0;
			if (usb_priv.usb_state >= HIFUSB_STATE_ADDR) {
				if (wValue == USBC_FEATURE_DEVICE_REMOTE_WAKEUP) { //remote wakeup
					/*Device remote wakeup, no support*/
				} else if (wValue == USBC_FEATURE_TEST_MODE) { //U2 test mode
					/*don't handle in USB bootrom*/
				} else if (usb_priv.usb_state >= HIFUSB_STATE_CONFIG) {
					if (wValue == USBC_FEATURE_DEV_U1_EN) {
						dev_status |= USBC_DEV_STATUS_U1_EN;
					} else if (wValue == USBC_FEATURE_DEV_U2_EN) {
						dev_status |= USBC_DEV_STATUS_U2_EN;
					} else if (wValue == USBC_FEATURE_DEV_LTM_EN) {
						dev_status |= USBC_DEV_STATUS_LTM_EN;
					} else {
						ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
					}
				} else {
					ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
				}
			} else {
				ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
				*p_len = 0;
			}
			break;
		case USBC_REQUEST_RECIP_INTERFACE:
			ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
			*p_len = 0;
			if (usb_priv.usb_state >= HIFUSB_STATE_CONFIG) {
				if (wValue == USBC_FEATURE_IF_FUNC_SUS) { 
				} else {
					ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
				}
			} else {
				ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
			}

			break;
		case USBC_REQUEST_RECIP_ENDPOINT:
			*p_len = 0;
			ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
			if (usb_priv.usb_state >= HIFUSB_STATE_CONFIG) {
				if (wValue == USBC_FEATURE_ENDPOINT_HALT) { 
					ep_num = (kal_uint8)(wIndex & (~USBC_EP_ADDR_DIR_IN));
					if ((wIndex & USBC_EP_ADDR_DIR_IN) == USBC_EP_ADDR_DIR_IN) {
						/*Device to Host endpoint and check if EP STALL state set*/
						u3_set_ep_stall(KAL_TRUE, ep_num);
					} else {
						/*Host to Device endpoint and check if EP STALL state set*/
						u3_set_ep_stall(KAL_FALSE, ep_num);
					}
				} else {
					ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
				}
			} else {
				ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
			}			
			break;
		default:
			ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
			*p_len = 0;
			break;
	}
	
	return ret;
}

hifusb_control_request_type_e usb_ep0_clear_feature(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len)
{
	hifusb_control_request_type_e ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
	kal_uint8 ep_num = 0;
	kal_uint16 wValue = 0, wLength = 0, wIndex = 0;

	wValue = p_setup->wValue;
	wLength = p_setup->wLength;
	wIndex = p_setup->wIndex;
	switch (p_setup->bmRequestType & USBC_REQUEST_RECIP_MASK) {
		case USBC_REQUEST_RECIP_DEVICE:
			ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
			*p_len = 0;
			if (usb_priv.usb_state >= HIFUSB_STATE_ADDR) {
				if (wValue == USBC_FEATURE_DEVICE_REMOTE_WAKEUP) { //remote wakeup
					/*Device remote wakeup, no support*/
				} else if (wValue == USBC_FEATURE_TEST_MODE) { //U2 test mode
					/*don't handle in USB bootrom*/
				} else if (usb_priv.usb_state >= HIFUSB_STATE_CONFIG){
					if (wValue == USBC_FEATURE_DEV_U1_EN) {
						dev_status &= (~USBC_DEV_STATUS_U1_EN);
					} else if (wValue == USBC_FEATURE_DEV_U2_EN) {
						dev_status &= (~USBC_DEV_STATUS_U2_EN);
					} else if (wValue == USBC_FEATURE_DEV_LTM_EN) {
						dev_status &= (~USBC_DEV_STATUS_LTM_EN);
					} else {
						ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
					}
				} else {
					ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
				}
			} else {
				ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
			}
			break;
		case USBC_REQUEST_RECIP_INTERFACE:
			ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
			*p_len = 0;
			if (usb_priv.usb_state >= HIFUSB_STATE_CONFIG){			
				if (wValue == USBC_FEATURE_IF_FUNC_SUS) {
				} else {
					ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
				}
			} else {
				ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
			}
			break;
		case USBC_REQUEST_RECIP_ENDPOINT:
			*p_len = 0;
			ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
			if (usb_priv.usb_state >= HIFUSB_STATE_CONFIG){			
				if (wValue == USBC_FEATURE_ENDPOINT_HALT) {
					ep_num = (kal_uint8)(wIndex & (~USBC_EP_ADDR_DIR_IN));
					if ((wIndex & USBC_EP_ADDR_DIR_IN) == USBC_EP_ADDR_DIR_IN) {
						/*Device to Host endpoint and check if EP STALL state set*/
						u3_clr_ep_stall(KAL_TRUE, ep_num);
					} else {
						/*Host to Device endpoint and check if EP STALL state set*/
						u3_clr_ep_stall(KAL_FALSE, ep_num);
					}
				} else {
					ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
				}
			} else {
				ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
			}
			break;
		default:
			ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
			*p_len = 0;
			break;
	}
	
	return ret;
}

hifusb_control_request_type_e usb_ep0_set_iso_delay(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len)
{
	hifusb_control_request_type_e ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;

	*p_len = 0;
	ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
	
	return ret;
}

hifusb_control_request_type_e usb_ep0_std_req_handle(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len)
{
	hifusb_control_request_type_e ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;

	switch (p_setup->bRequest) {
		case USBC_REQ_SET_ADDRESS:
			ret = usb_ep0_set_address(p_setup, p_buf, p_len);
			break;
		case USBC_REQ_GET_STATUS:
			ret = usb_ep0_get_status(p_setup, p_buf, p_len);
			break;
		case USBC_REQ_SET_FEATURE:
			ret = usb_ep0_set_feature(p_setup, p_buf, p_len);
			break;
		case USBC_REQ_CLEAR_FEATURE:
			ret = usb_ep0_clear_feature(p_setup, p_buf, p_len);
			break;
		case USBC_REQ_GET_DESCRIPTOR:
			ret = usb_ep0_get_desc(p_setup, p_buf, p_len);
			break;
		case USBC_REQ_SET_CONFIGURATION:
			ret = usb_ep0_set_config(p_setup, p_buf, p_len);
			break;
		case USBC_REQ_GET_CONFIGURATION:
			ret = usb_ep0_get_config(p_setup, p_buf, p_len);
			break;
		case USBC_REQ_SET_INTERFACE: //no alternate interface for ACM
			ret = usb_ep0_set_interface(p_setup, p_buf, p_len);
			break;
		case USBC_REQ_GET_INTERFACE: //no alternate interface for ACM
			ret = usb_ep0_get_interface(p_setup, p_buf, p_len);
			break;
		case USBC_REQ_SET_SEL: /*ep0 data out , handle host set data*/
			ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
			break;
		case USBC_REQ_SET_ISOCH_DELAY:
			ret = usb_ep0_set_iso_delay(p_setup, p_buf, p_len);
			break;
		default:
			ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
			*p_len = 0;
			break;
	}

	return ret;
}

hifusb_control_request_type_e usb_ep0_req_parse_handle(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len)
{
	hifusb_control_request_type_e ret = 0;

	if ((p_setup->bmRequestType & USBC_REQUEST_TYPE_MASK) == USBC_REQUEST_TYPE_STANDARD) {
		ret = usb_ep0_std_req_handle(p_setup, p_buf, p_len);
	} else if ((p_setup->bmRequestType & USBC_REQUEST_TYPE_MASK) == USBC_REQUEST_TYPE_CLASS) { //class type request for ACM
		ret = usb_ep0_class_req_handle(p_setup, p_buf, p_len);
	} else if ((p_setup->bmRequestType & USBC_REQUEST_TYPE_MASK) == USBC_REQUEST_TYPE_VENDOR){ //VENDOR request
		ret = usb_ep0_vendor_req_handle(p_setup, p_buf, p_len);
	} else { //no match case return STALL
		ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
		*p_len = 0;
	}

	if (ret == HIFUSB_CONTROL_REQUEST_TYPE_STALL) {
		//serial_put_errno(ERR_USB_PREFIX | E_USB_EP0_STALL);
	}

	return ret;
}


void hifusb_set_control_request(kal_uint32 length, hifusb_control_request_type_e type)
{
	hifusb_ep0_priv_t *p_ep0_priv;

	p_ep0_priv = &usb_priv.ep0_pirv;

	usbdev_printf(USBDEV_UARTDBG_TRACE,"[%s:%d] type = %d, buf_len = %d\r\n",
											__FUNCTION__,__LINE__,type,length);

	/*use the local buffer for exception*/
	p_ep0_priv->ep0_datain_buf = usb_ep0_buf;
	p_ep0_priv->ep0_dataout_buf = usb_ep0_buf;
	switch (type) {
		case HIFUSB_CONTROL_REQUEST_TYPE_SEND: //IN data
			p_ep0_priv->ep0_datain_len = length;
			p_ep0_priv->ep0_dataout_len = 0;
			if (length > 0) {
				p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_DATAIN;
			} else {
				p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_ACKWAIT;
			}
			break;
		case HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE://OUT data
			p_ep0_priv->ep0_datain_len = 0;
			p_ep0_priv->ep0_dataout_len = length;
			if (length > 0) {
				p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_DATAOUT;
			} else {
				p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_ACKWAIT;
			}
			break;
		case HIFUSB_CONTROL_REQUEST_TYPE_STALL:
			p_ep0_priv->ep0_datain_len = 0;
			p_ep0_priv->ep0_dataout_len = 0;
			p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_STALL;
			break;
		default :
			break;
	}

}


/*!
 *  @brief  parse USB SETUP packet for request and EP0 stage transition
 *  @param  p_req , the request SETUP packet buffer
 *	@param p_ep0_st , the current ep0 stage and this function might update the new stage
 *	@return KAL_TRUE if ep0 stage updated , KAL_FALSE ep0 stage not updated or current stage error
 */
kal_bool u3_ep0_parse_setup(hifusb_ep0_priv_t *p_ep0_priv)
{
	kal_bool ret = KAL_TRUE;
	hifusb_setup_packet_t *p_request = NULL;
	kal_uint32 data_len = 0;
	hifusb_control_request_type_e req_type = 0;


	p_request = &p_ep0_priv->ep0_request;

	if (p_ep0_priv->usb_ep0_st != HIFUSB_EP0_ST_SETUP) {
		return KAL_FALSE;
	}

	if (p_request->bmRequestType & USBC_REQUEST_DIR_IN) {
		/*use the data in callback to fill the data in data to usb driver local buffer*/
		req_type = usb_ep0_req_parse_handle(p_request, p_ep0_priv->ep0_datain_buf, &data_len);
	} else{ //data stage is OUT
		/*use the usb driver local buffer to receive the data out data*/
		/*recv all host data event don't support this command*/
		req_type = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
		data_len = p_request->wLength;
		if (data_len == 0) { //means no data stage set command, directly callback
			req_type = usb_ep0_req_parse_handle(p_request, p_ep0_priv->ep0_datain_buf, &data_len);
		}
	}
	/*configure next ep0 stage*/
	hifusb_set_control_request(data_len, req_type);
	
	return ret;
}

/*!
 *  @brief  handle the data in stage load FIFO and ack CSR0
 *  @param  p_priv, the usb driver global handle
 */
void u3_ep0_datain_stage(hifusb_priv_t *p_priv)
{
	hifusb_ep0_priv_t *p_ep0_priv;
	kal_uint8 *src_buf = NULL;
	kal_uint32 load_len = 0;
	kal_uint16 csr0_ack = U3_EP0_REG16_TXPKTRDY, reg_16 = 0;


	p_ep0_priv = &p_priv->ep0_pirv;
	if (p_ep0_priv->usb_ep0_st != HIFUSB_EP0_ST_DATAIN) {
		usbdev_printf(USBDEV_UARTDBG_ERR, "[%s : %d] ep0_stage err\n\r", __FUNCTION__,__LINE__);
		return;
	}
	if ((NULL == p_ep0_priv->ep0_datain_buf) || (0 == p_ep0_priv->ep0_datain_len)) {
		usbdev_printf(USBDEV_UARTDBG_ERR, "[%s : %d] data in buf and len ERR\n\r", __FUNCTION__,__LINE__);
		return;
	}
	
	if (p_ep0_priv->ep0_data_len_idx < p_ep0_priv->ep0_datain_len) {
		src_buf = (kal_uint8*)p_ep0_priv->ep0_datain_buf + p_ep0_priv->ep0_data_len_idx;
		load_len = HIFUSB_MIN((p_ep0_priv->ep0_datain_len - p_ep0_priv->ep0_data_len_idx)
													, p_priv->ep0_config.MaxPacketSize);
		p_ep0_priv->ep0_data_len_idx += load_len;

		u3_load_fifo(0, load_len , src_buf);
		/*
		 * 	case 1 : last packet with length smaller than MPS
		 *	case 2 : last packet with MPS length and host request buffer same as xfer length
		*/
		if ((load_len < p_priv->ep0_config.MaxPacketSize) ||
				((p_ep0_priv->ep0_data_len_idx == p_ep0_priv->ep0_datain_len) && (p_ep0_priv->ep0_request.wLength == p_ep0_priv->ep0_datain_len))) {

			/*DATA_IN stage end*/
			/*set the DATAEND in latest TX PKT send complete interrupt, DATAEND here would err*/
			p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_STATUSOUT;

			/*notify complete to upper driver*/
			
		} else { //continue transfer next ep0 IN packet
		}
		reg_16 = USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL);
		reg_16 &= (~(U3_EP0_REG16_RXPKTRDY | U3_EP0_REG16_SETUPRDY | U3_EP0_REG16_TXPKTRDY));
		reg_16 |= csr0_ack;
		USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL) = reg_16;;
	} else if (p_ep0_priv->ep0_data_len_idx == p_ep0_priv->ep0_datain_len) { //DATA IN END for N x MPS to send ZLP

		/*DATA_IN stage end*/
		/*set the DATAEND in latest TX PKT send complete interrupt, DATAEND here would err*/
		p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_STATUSOUT;

		/*notify complete to upper driver*/
		reg_16 = USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL);
		reg_16 &= (~(U3_EP0_REG16_RXPKTRDY | U3_EP0_REG16_SETUPRDY | U3_EP0_REG16_TXPKTRDY));
		reg_16 |= csr0_ack;
		USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL) = reg_16;;
	} else {
		usbdev_printf(USBDEV_UARTDBG_ERR, "[%s : %d] ep0 data_in handle err\n\r", __FUNCTION__,__LINE__);
		return;
	}
	
}

void u3_ep0_dataout_stage(hifusb_priv_t *p_priv)
{
	hifusb_ep0_priv_t *p_ep0_priv;
	kal_uint8 *dest_buf = NULL;
	kal_uint32 remain_len = 0 , rxcount = 0;
	kal_uint16 csr0_ack = U3_EP0_REG16_RXPKTRDY, reg_16 = 0;

	p_ep0_priv = &p_priv->ep0_pirv;

	if (p_ep0_priv->ep0_data_len_idx < p_ep0_priv->ep0_dataout_len) {
		dest_buf =(kal_uint8*)p_ep0_priv->ep0_dataout_buf + p_ep0_priv->ep0_data_len_idx;	
		remain_len = p_ep0_priv->ep0_dataout_len - p_ep0_priv->ep0_data_len_idx;
		rxcount = USBReg_Read32(U3_DEV_EP0RXCOUNT);
		if (rxcount > remain_len) {
			usbdev_printf(USBDEV_UARTDBG_ERR, "[%s : %d] host driver transfer too many bytes\n\r", 
																	__FUNCTION__,__LINE__);		
			/*only store the correct length data*/
			rxcount = remain_len;	
		}
		u3_unload_fifo(0, rxcount, dest_buf);
		p_ep0_priv->ep0_data_len_idx += rxcount;

		/*means DATA_OUT transfer complete*/
		if ((rxcount < p_priv->ep0_config.MaxPacketSize) || 
				(p_ep0_priv->ep0_data_len_idx == p_ep0_priv->ep0_dataout_len)) {

			csr0_ack |= U3_EP0_REG16_DATAEND;
			p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_STATUSIN;
			
			/*
			 *	out data stage complete, notify upper driver to handle
			 *	recv all data without STALL event don't support this reqeust command
			*/
			usb_ep0_req_parse_handle(&p_ep0_priv->ep0_request, p_ep0_priv->ep0_dataout_buf, &p_ep0_priv->ep0_dataout_len);
			
		} else { //continue transfer next ep0 OUT packet
		}
	} else {
		usbdev_printf(USBDEV_UARTDBG_ERR, "[%s : %d] host driver transfer too many bytes\n\r", 
																__FUNCTION__,__LINE__);		
		/*no data request, so replay stall*/
		csr0_ack |= U3_EP0_REG16_SENDSTALL;
	}
	reg_16 = USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL);
	reg_16 &= (~(U3_EP0_REG16_RXPKTRDY | U3_EP0_REG16_SETUPRDY | U3_EP0_REG16_TXPKTRDY));
	reg_16 |= csr0_ack;
	USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL) |= reg_16;

}

kal_uint32 u3_setupend_isr_handle(hifusb_priv_t *p_usb_priv)
{
	hifusb_ep0_priv_t *p_ep0_priv = NULL;

	/* 
	 * 	just ack the setupend interrupt,
	 *	hardware lock all the EP0 fifo and CSR operation before setupend interrupt acked
	*/
	usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] EP0 SetupEnd occur to ignore previous setup\n\r" ,__FUNCTION__, __LINE__);

	//serial_put_errno(ERR_USB_PREFIX | E_USB_EP0_SETUPEND);

	/*set EP0 handle state to initial state to handle new request*/
	p_ep0_priv = &p_usb_priv->ep0_pirv;
	p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_IDLE;
	p_ep0_priv->ep0_datain_len = 0;
	p_ep0_priv->ep0_dataout_len = 0;
	
	return 0;
}


kal_uint32 u3_ep0_isr_handle(hifusb_priv_t *p_usb_priv)
{
	kal_uint16 csr = 0, len = 0, ack_csr = 0;
	hifusb_ep0_priv_t *p_ep0_priv;
	
	p_ep0_priv = &p_usb_priv->ep0_pirv;
	
	csr = USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL);
	len = USBReg_Read32(U3_DEV_EP0RXCOUNT);

	usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] CSR0 = 0x%x , RXCOUNT0 = %d ep0_stage = %s\n\r"
						,__FUNCTION__, __LINE__, csr , len , u3_decode_ep0_stage(p_ep0_priv->usb_ep0_st));
		
	/*Stall had sent, need ack the status*/
	if (csr & U3_EP0_REG16_SENTSTALL) {
		/*don't ack all set 1 clear bit or the rapid setup packet will be cleared*/
		ack_csr = USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL);
		ack_csr &= (~(U3_EP0_REG16_RXPKTRDY | U3_EP0_REG16_SETUPRDY | U3_EP0_REG16_TXPKTRDY));
		ack_csr |= U3_EP0_REG16_SENTSTALL;
		USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL) = ack_csr; //SENTSTALL W1C
		p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_IDLE;

		/*re-flash the csr value for following handle*/
		csr = USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL);
	}
	
	/*
	 *	handle each usb ep0 stage,
	 * 	the order of the stage handle is matter
	*/
	switch (p_ep0_priv->usb_ep0_st) {
		case HIFUSB_EP0_ST_DATAIN:
			/*irq when clear txpktrdy*/
			if (0 == (csr & U3_EP0_REG16_TXPKTRDY)) {
				u3_ep0_datain_stage(p_usb_priv);
			}
			break;
		case HIFUSB_EP0_ST_DATAOUT:
			/*irq when rxpktrdy*/
			if (csr & U3_EP0_REG16_RXPKTRDY) {
				u3_ep0_dataout_stage(p_usb_priv);
			}
			break;
		case HIFUSB_EP0_ST_STATUSIN:
			/*end of DATA_OUT or NO_DATA*/
			/*
			 *	U3 IP HW support to fill address when recv SET_ADDRESS request
			 *	We can't fill here because there is no status stage end interrupt.
			 *	Test mode handle should be considered.
			*/
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
#endif
			p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_IDLE;			
			goto idle;

			//don't break out, might has new setup
									
		case HIFUSB_EP0_ST_STATUSOUT:
			/*
			 *	the new setup packet might have been received
			*/
			if (csr & U3_EP0_REG16_SETUPRDY) {
				p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_SETUP;
				goto setup;
			}			

			/*
			 *	data in stage end and the latest packet trigger this interrupt
			 *	should set DATAEND here for U3 IP , not the same as mentor IP
			*/
			ack_csr = USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL);
			ack_csr &= (~(U3_EP0_REG16_RXPKTRDY | U3_EP0_REG16_SETUPRDY | U3_EP0_REG16_TXPKTRDY));
			ack_csr |= U3_EP0_REG16_DATAEND;			
			USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL) = ack_csr;

			p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_IDLE;			
			break;
		case HIFUSB_EP0_ST_IDLE:
idle:
			len = USBReg_Read32(U3_DEV_EP0RXCOUNT);
			if ((csr & U3_EP0_REG16_SETUPRDY) && (len == 8)) {
				p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_SETUP;
			} else {
				//usbdev_printf(USBDEV_UARTDBG_ERR, "[%s : %d] ERR EP0 IDLE stage csr0 = 0x%x , rxcount0 = %d\n\r"
					//											,__FUNCTION__,__LINE__, csr , len);
			}
		case HIFUSB_EP0_ST_SETUP:
setup:		
			if (csr & U3_EP0_REG16_SETUPRDY) {
				len = USBReg_Read32(U3_DEV_EP0RXCOUNT);
				if (len != 8) {
					usbdev_printf(USBDEV_UARTDBG_ERR, "[%s : %d] SETUP packet len %d != 8\n\r",__FUNCTION__,__LINE__, len);
					break;
				} else {
					usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] ep0_stage = %s\n\r"
						,__FUNCTION__, __LINE__, u3_decode_ep0_stage(p_ep0_priv->usb_ep0_st));
				}
				/*zero the ep0 handle variable*/
				p_ep0_priv->ep0_data_len_idx = 0;
				/*unload SETUP packet from FIFO*/
				u3_unload_fifo(0, len, (kal_uint8*)&p_ep0_priv->ep0_request);

				/*check if the SETUPEND ISR asserted to skip following handle*/
				if(USBReg_Read32(U3_DEV_EPISR) & U3_DEV_SETUPENDISR) {
					return 0;	
				}

				/*
				 *	usb_ep0_st should be update and request would be handled after this callback, 
				 *	this callback must call hifusb_set_control_request()
				 *	hifusb_set_control_request() would update the usb_ep0_st and the 
				 *	data stage buffer information.
				*/
				u3_ep0_parse_setup(p_ep0_priv);
				if (HIFUSB_EP0_ST_SETUP == p_ep0_priv->usb_ep0_st) {
					usbdev_printf(USBDEV_UARTDBG_ERR, "[%s : %d] Call Back don't update correct ep0 stage\n\r"
																			,__FUNCTION__,__LINE__);
					break;
				}

				/* 	no data requests delay the STATUS stage to
				 * 	avoid SETUPEND errors.  
				 *	read data (OUT) reqeust, delay accepting
				 * 	packets until has a buffer to store.
				 */
				p_ep0_priv->csr0_ack_pend = U3_EP0_REG16_SETUPRDY;
				
				/*
				 *	handle the usb_ep0_st after updated by callback
				 *	only handle NO_DATA, DATA_IN and STALL case
				*/				
				switch(p_ep0_priv->usb_ep0_st) {
					/*
					*	no data request
					*/
					case HIFUSB_EP0_ST_ACKWAIT: 
						usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] ep0_stage = %s \n\r"
								,__FUNCTION__, __LINE__, u3_decode_ep0_stage(p_ep0_priv->usb_ep0_st));
						if (p_ep0_priv->ep0_request.bmRequestType & USBC_REQUEST_DIR_IN) {
							p_ep0_priv->csr0_ack_pend |= U3_EP0_REG16_TXPKTRDY;;
						}

						/*
						 *	U3 IP HW support to fill address when recv SET_ADDRESS request
						 *	the Address would take effect after the status stage end to meet the spec
						*/						
						if (p_ep0_priv->update_dev_addr) {
							p_usb_priv->usb_statistic.usb_val_addr = p_ep0_priv->update_dev_addr;
							USBReg_Write8(U3_EPCTL_REG8_DEV_ADDR, p_ep0_priv->update_dev_addr);
							p_usb_priv->usb_state = HIFUSB_STATE_ADDR;
							p_ep0_priv->update_dev_addr = 0;
						} 
						
						/*control call back had handled the request and enter setup complete process*/
						p_ep0_priv->csr0_ack_pend |= U3_EP0_REG16_DATAEND;
						/*status stage might be immediately*/
						p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_STATUSIN;
						break;
					/*
					*	data in reqeust handle
					*/
					case HIFUSB_EP0_ST_DATAIN: 
						usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] ep0_stage = %s , len = %d\n\r"
								,__FUNCTION__, __LINE__,u3_decode_ep0_stage(p_ep0_priv->usb_ep0_st),p_ep0_priv->ep0_datain_len);
						/*flush the pending ack*/
						p_ep0_priv->csr0_ack_pend = 0;
						/*upper layer driver should have set the buffer and buffer length*/
						if ((NULL == p_ep0_priv->ep0_datain_buf) || (0 == p_ep0_priv->ep0_datain_len)) {
							/*data in stage just ack the RxPktRdy*/
							ack_csr = USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL);
							ack_csr &= (~(U3_EP0_REG16_RXPKTRDY | U3_EP0_REG16_SETUPRDY | U3_EP0_REG16_TXPKTRDY));
							ack_csr |= U3_EP0_REG16_SETUPRDY;			
							USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL) = ack_csr; //W1C
							goto stall;
						} else {
							/*data in stage just ack the RxPktRdy and set the FIFO direction to TX*/
							ack_csr = USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL);
							ack_csr &= (~(U3_EP0_REG16_RXPKTRDY | U3_EP0_REG16_SETUPRDY | U3_EP0_REG16_TXPKTRDY));
							ack_csr |= (U3_EP0_REG16_SETUPRDY | U3_EP0_REG16_DPHTX);										
							USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL) = ack_csr; 
							u3_ep0_datain_stage(p_usb_priv);
							/*don't have to handle the csr0_ack_pend after u2_ep_datain_stage()*/
							return 0;
						}						
						//break;
					/*
					*	ep0 callback would set to stall stage when the request handle fail
					*/
					case HIFUSB_EP0_ST_STALL: 
stall:
						usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] ep0_stage = %s\n\r"
							,__FUNCTION__, __LINE__, u3_decode_ep0_stage(p_ep0_priv->usb_ep0_st));

						p_ep0_priv->csr0_ack_pend |= U3_EP0_REG16_SENDSTALL;
						p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_IDLE;
						break;
					default : 
						break;
				}

				/* handle the pending csr0 ack to finish the request*/
				ack_csr = USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL);
				ack_csr &= (~(U3_EP0_REG16_RXPKTRDY | U3_EP0_REG16_SETUPRDY | U3_EP0_REG16_TXPKTRDY));
				ack_csr |= p_ep0_priv->csr0_ack_pend;										
				USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL) = ack_csr;
			}
			break;
		case HIFUSB_EP0_ST_ACKWAIT:
			break;
		default:
			ack_csr = USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL);
			ack_csr &= (~(U3_EP0_REG16_RXPKTRDY | U3_EP0_REG16_SETUPRDY | U3_EP0_REG16_TXPKTRDY));
			ack_csr |= U3_EP0_REG16_SENDSTALL;										
			USBReg_Read16(U3_DEV_EP0CSR_REG16_CTL) = ack_csr;
			p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_IDLE;
			break;
	}

	
	return 0;
}


kal_uint32 u3_epctl_link_isr_handle(kal_uint32 intr_dev_link)
{
	hifusb_priv_t *p_usb_priv = NULL;
	hifusb_statistic_t *p_usb_statistic;
	hifusb_ep0_priv_t *p_ep0_priv;
	kal_uint8 speed_md = 0;
	
	p_usb_priv = &usb_priv;
	p_usb_statistic = &p_usb_priv->usb_statistic;
	p_ep0_priv = &p_usb_priv->ep0_pirv;

	usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] [SPEED CHANGE] U3_EPCTL_DEV_LINK_INTR \n\r", __FUNCTION__,__LINE__);

	/*skip all USB interrupt when has not set_connect*/
	if (p_usb_priv->usb_state < HIFUSB_STATE_ATTACHED) {
		speed_md = USBReg_Read32(U3_EPCTL_DEV_CONFIG) & U3_EPCTL_DEV_SPEED_MSK;
		usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] U3_EPCTL_DEV_LINK_INTR when no attach, speed = 0x%x\n\r", __FUNCTION__,__LINE__,speed_md);
		return 0;
	}

	/*speed change interrupt occur when speed detection end*/
	if (intr_dev_link & U3_EPCTL_DEV_SPEED_CHG_INTR) {
		/*record and notify the USB speed after USB2.0 CHIRP*/
		p_usb_priv->usb_state = HIFUSB_STATE_DEFAULT;
		p_ep0_priv->usb_ep0_st = HIFUSB_EP0_ST_IDLE;

		/*read final speed mode*/
		speed_md = USBReg_Read32(U3_EPCTL_DEV_CONFIG) & U3_EPCTL_DEV_SPEED_MSK;
		if (speed_md == U3_EPCTL_DEV_SPEED_SS) {
			p_usb_statistic->usb_cur_speed = HIFUSB_USB_SPEED_USB30;
#ifdef USB_IF_TST
			u3_pwr_p1_p2_setting();
#endif			
			usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] [SPEED CHANGE] Super Speed Mode\n\r", __FUNCTION__,__LINE__);
		} else if (speed_md == U3_EPCTL_DEV_SPEED_HS) {
			p_usb_statistic->usb_cur_speed = HIFUSB_USB_SPEED_USB20;
			usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] [SPEED CHANGE] High Speed Mode\n\r", __FUNCTION__,__LINE__);
		} else if (speed_md == U3_EPCTL_DEV_SPEED_FS) {
			p_usb_statistic->usb_cur_speed = HIFUSB_USB_SPEED_USB11;
			usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] [SPEED CHANGE] FS Speed Mode\n\r", __FUNCTION__,__LINE__);
		} else { //error
			usbdev_printf(USBDEV_UARTDBG_ERR, "[%s : %d] [SPEED CHANGE] invalid speed mode\n\r", __FUNCTION__,__LINE__);
			return 0;
		}					
		/*issue reset interrupt handler to configure the endpoint setting for current speed*/
		u3_reset_isr_handle(p_usb_priv);
#ifdef SIMULATION
		SIMULATION_CHECK_POINT_UPDATE(CHECK_USB_LINK_INTR);
		MDM_ENDSIM();
#endif
		
	}

	return 0;
}

kal_uint32 u3_mac3_isr_handle(kal_uint32 intr_u3_ltssm)
{
	hifusb_priv_t *p_usb_priv = NULL;
	hifusb_ep0_priv_t *p_ep0_priv;
	hifusb_statistic_t *p_usb_statistic;

	p_usb_priv = &usb_priv;
	p_ep0_priv = &(p_usb_priv->ep0_pirv);
	p_usb_statistic = &(p_usb_priv->usb_statistic);


	if (intr_u3_ltssm & U3_LTSSM_VBUS_RISE_INTR) {
		usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] U3_LTSSM_VBUS_RISE_INTR\n\r", __FUNCTION__,__LINE__);
		/*host power just supplying*/
		//p_usb_priv->usb_state = HIFUSB_STATE_PWRON;
	}

	if (intr_u3_ltssm & U3_LTSSM_VBUS_FALL_INTR) {
		usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] U3_LTSSM_VBUS_FALL_INTR\n\r", __FUNCTION__,__LINE__);
		/*host power off*/
		//p_usb_priv->usb_state = HIFUSB_STATE_PWROFF;
	}

	/*skip all U3 MAC interrupt except the VBUS event when has not set_connect*/
	if (p_usb_priv->usb_state < HIFUSB_STATE_ATTACHED) {
		return 0;
	}

	if (intr_u3_ltssm & U3_LTSSM_RXDET_SUCCESS_INTR){
		usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] U3_LTSSM_RXDET_SUCCESS_INTR\n\r", __FUNCTION__,__LINE__);
		/*RX detection success means just start the connection and the state should be just starting*/
		p_usb_priv->usb_state = HIFUSB_STATE_ATTACHED;
	}
	
	if (intr_u3_ltssm & U3_LTSSM_SS_INACTIVE_INTR) {
		usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] U3_LTSSM_SS_INACTIVE_INTR\n\r", __FUNCTION__,__LINE__);
		//p_usb_priv->usb_state = HIFUSB_STATE_PWRON;
	}

	if (intr_u3_ltssm & U3_LTSSM_SS_DISABLE_INTR) {
		usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] U3_LTSSM_SS_DISABLE_INTR\n\r", __FUNCTION__,__LINE__);
		/*U3 spec 10.16.2, when enter RX.Detect from Disable, the RX.Detect retry count is one*/
		//hardware automatically handle this requirement
		//USBReg_Read32(U3_MAC_LTSSM_PARAM) &= (~U3_MAC_RXDET_CNT_MSK);
		//USBReg_Read32(U3_MAC_LTSSM_PARAM) |= (U3_RETRY_RXDET_CNT << U3_MAC_RXDET_CNT_OFFSET);
		/*always use the SS_HS_SUPPORT in exception mode*/
		/*follow the 10.16.2 U3/U2 detection flow*/
		u3_set_u2_connect();
	} else {
		/*U3 spec 10.16.2, when enter RX.Detect from non-Disable, the RX.Detect retry count is eight*/
		//hardware will handle this case
		//USBReg_Read32(U3_MAC_LTSSM_PARAM) &= (~U3_MAC_RXDET_CNT_MSK);
		//USBReg_Read32(U3_MAC_LTSSM_PARAM) |= (U3_INIT_RXDET_CNT << U3_MAC_RXDET_CNT_OFFSET);
	}

	if (intr_u3_ltssm & U3_LTSSM_COMPLIANCE_INTR) {
		usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] U3_LTSSM_COMPLIANCE_INTR\n\r", __FUNCTION__,__LINE__);
	}

	if (intr_u3_ltssm & U3_LTSSM_LOOPBACK_INTR) {
		usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] U3_LTSSM_LOOPBACK_INTR\n\r", __FUNCTION__,__LINE__);
	}

	if (intr_u3_ltssm & U3_LTSSM_HOT_RST_INTR) {
		usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] U3_LTSSM_HOT_RST_INTR\n\r", __FUNCTION__,__LINE__);
		/*hot reset trigger to enter protocol layer DEFAULT state*/
		p_usb_priv->usb_state = HIFUSB_STATE_ATTACHED;
	}

	if (intr_u3_ltssm & U3_LTSSM_WARM_RST_INTR) {
		usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] U3_LTSSM_WARM_RST_INTR\n\r", __FUNCTION__,__LINE__);
		p_usb_priv->usb_state = HIFUSB_STATE_ATTACHED;
	}

	if (intr_u3_ltssm & U3_LTSSM_RECOVERY_INTR) {
		usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] U3_LTSSM_RECOVERY_INTR\n\r", __FUNCTION__,__LINE__);
	}

	if (intr_u3_ltssm & U3_LTSSM_ENTER_U0_INTR) {
		usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] U3_LTSSM_ENTER_U0_INTR\n\r", __FUNCTION__,__LINE__);
		/*transition from lower state means that sw should reset the sw state machine*/
#if 0 // speed confirmed by U3_EPCTL_DEV_LINK_INTR interrupt
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif		
		/*transition from suspend state means resume*/
		if ((p_usb_priv->usb_state == HIFUSB_STATE_SUSPENDED) || (p_usb_priv->usb_state == HIFUSB_STATE_RESUME)) {
			usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] RESUME from SUSPEND state\n\r", __FUNCTION__,__LINE__);
			/*return to original state before suspend immediately after all resume handle*/
			if ((p_usb_statistic->usb_val_addr > 0) && (p_usb_statistic->usb_val_config > 0)) {
				p_usb_priv->usb_state = HIFUSB_STATE_CONFIG;
			} else if (p_usb_statistic->usb_val_addr > 0) {
				p_usb_priv->usb_state = HIFUSB_STATE_ADDR;
			} else {
				p_usb_priv->usb_state = HIFUSB_STATE_DEFAULT;
			}
		}
	}

	if (intr_u3_ltssm & U3_LTSSM_ENTER_U1_INTR) {
		usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] U3_LTSSM_ENTER_U1_INTR\n\r", __FUNCTION__,__LINE__);
	}

	if (intr_u3_ltssm & U3_LTSSM_ENTER_U2_INTR) {
		usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] U3_LTSSM_ENTER_U2_INTR\n\r", __FUNCTION__,__LINE__);
	}

	if (intr_u3_ltssm & U3_LTSSM_ENTER_U3_INTR) {
		usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] U3_LTSSM_ENTER_U3_INTR\n\r", __FUNCTION__,__LINE__);
		p_usb_priv->usb_state = HIFUSB_STATE_SUSPENDED;
		/*SUSPEND handle, don't issue power saving for bootrom*/
	}

	if (intr_u3_ltssm & U3_LTSSM_EXIT_U1_INTR) {
		usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] U3_LTSSM_EXIT_U1_INTR\n\r", __FUNCTION__,__LINE__);
	}

	if (intr_u3_ltssm & U3_LTSSM_EXIT_U2_INTR) {
		usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] U3_LTSSM_EXIT_U2_INTR\n\r", __FUNCTION__,__LINE__);
	}

	if (intr_u3_ltssm & U3_LTSSM_EXIT_U3_INTR) {
		usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] U3_LTSSM_EXIT_U3_INTR\n\r", __FUNCTION__,__LINE__);
		p_usb_priv->usb_state = HIFUSB_STATE_RESUME;
	}
	if (intr_u3_ltssm & U3_LTSSM_U3_LFPS_TO_INTR) {
		usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] U3_LTSSM_U3_LFPS_TO_INTR\n\r", __FUNCTION__,__LINE__);
	}
	if (intr_u3_ltssm & U3_LTSSM_U3_RESUME_INTR) {
		usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] U3_LTSSM_U3_RESUME_INTR\n\r", __FUNCTION__,__LINE__);
	}

	return 0;
}


kal_uint32 u3_mac2_isr_handle(kal_uint8 intr_u2_mac)
{
	hifusb_priv_t *p_usb_priv = NULL;
	hifusb_statistic_t *p_usb_statistic;
	hifusb_ep0_priv_t *p_ep0_priv;
	u3_drv_priv_t *p_u3_priv = NULL;

	p_usb_priv = &usb_priv;
	p_usb_statistic = &(p_usb_priv->usb_statistic);
	p_ep0_priv = &(p_usb_priv->ep0_pirv);
	p_u3_priv = &(p_usb_priv->u3_drv_priv);

	/*skip all U2 MAC interrupt when has not set_connect*/
	if (p_usb_priv->usb_state < HIFUSB_STATE_ATTACHED) {
		return 0;
	}
	/*the order to handle USB bus interrupt should take care*/
	if(intr_u2_mac & U3_USB2_INTR_RESET) {
#if 0 // speed confirmed by U3_EPCTL_DEV_LINK_INTR interrupt	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
		if (USBReg_Read32(U3_USB2_PWR_MANAGE) & U3_USB2_PM_HS_MD) {
			usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] [U2 RESET] High Speed Mode\n\r", __FUNCTION__,__LINE__);
		} else {
			usbdev_printf(USBDEV_UARTDBG_WARN, "[%s : %d] [U2 RESET] Full Speed Mode\n\r", __FUNCTION__,__LINE__);
		}		
#endif
	}

	if (intr_u2_mac & U3_USB2_INTR_SUSPEND) {
		usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] [SUSPEND]\n\r", __FUNCTION__,__LINE__);
		p_usb_priv->usb_state = HIFUSB_STATE_SUSPENDED;

		/*don't issue power saving for bootrom*/

		/*handle SUSPEND*/
	}
	
	if (intr_u2_mac & U3_USB2_INTR_RESUME) {
		usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] [RESUME]\n\r", __FUNCTION__,__LINE__);
		p_usb_priv->usb_state = HIFUSB_STATE_RESUME;
		
		/*return to original state before suspend immediately after all resume handle*/
		if ((p_usb_statistic->usb_val_addr > 0) && (p_usb_statistic->usb_val_config > 0)) {
			p_usb_priv->usb_state = HIFUSB_STATE_CONFIG;
		} else if (p_usb_statistic->usb_val_addr > 0) {
			p_usb_priv->usb_state = HIFUSB_STATE_ADDR;
		} else {
			p_usb_priv->usb_state = HIFUSB_STATE_DEFAULT;
		}
	}

	if (intr_u2_mac & U3_USB2_INTR_SOF) {
		usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] [SOF]\n\r", __FUNCTION__,__LINE__);
	}

	return 0;
}

void u3_isr_handler(void)
{
	kal_uint32 intr_l1 = 0, intr_ep = 0, intr_u2_mac = 0, intr_u3_ltssm = 0, 
							intr_qmu_done = 0,intr_qmu_empty_err = 0, intr_dev_link = 0;

	intr_l1 = USBReg_Read32(U3_DEV_LV1ISR);

	/*must only read the layer 1 interrupt indicated layer 2 or would lost interrupt*/
	if (intr_l1 & U3_DEV_BMU_INTR) {
		/*the EP normal interrupt is include in the BMU L1 interrupt*/
		intr_ep = USBReg_Read32(U3_DEV_EPISR);
		USBReg_Write32(U3_DEV_EPISR, intr_ep); //write 1 clear
	}
	if (intr_l1 & U3_DEV_QMU_INTR) {
		intr_qmu_done = *USB3_QMU_QISAR0;
		intr_qmu_empty_err = *USB3_QMU_QISAR1;
		*USB3_QMU_QISAR0 = intr_qmu_done; //write 1 clear
		*USB3_QMU_QISAR1, intr_qmu_empty_err; //write 1 clear
	}
	if (intr_l1 & U3_DEV_MAC3_INTR) {
		intr_u3_ltssm = USBReg_Read32(U3_LTSSM_INTR);
		USBReg_Write32(U3_LTSSM_INTR, intr_u3_ltssm);
 	}
	if (intr_l1 & U3_DEV_DMA_INTR) {
	}
	if (intr_l1 & U3_DEV_MAC2_INTR) {
		intr_u2_mac = USBReg_Read32(U3_USB2_COMMON_INTR_ST);
		USBReg_Write32(U3_USB2_COMMON_INTR_ST, intr_u2_mac); //write 1 clear
	}
	if (intr_l1 & U3_DEV_EP_CTRL_INTR) {
		/*speed detection end interrupt*/
		intr_dev_link = USBReg_Read32(U3_EPCTL_DEV_LINK_INTR);
		USBReg_Write32(U3_EPCTL_DEV_LINK_INTR, intr_dev_link); //write 1 clear
	}

	/*handle MAC3 ISR , only handle unmask isr*/
	if (intr_l1 & U3_DEV_MAC3_INTR) {
		u3_mac3_isr_handle(intr_u3_ltssm);
	}
	/*handle MAC2 ISR , only handle unmask isr*/
	if (intr_l1 & U3_DEV_MAC2_INTR) {
		u3_mac2_isr_handle(intr_u2_mac);
	}
	/*handle device link ISR , only handle unmask isr*/
	if (intr_l1 & U3_DEV_EP_CTRL_INTR) {
		u3_epctl_link_isr_handle(intr_dev_link);
	}
	/*handle BMU ISR , only handle unmask isr*/
	if (intr_l1 & U3_DEV_BMU_INTR) {
		if (intr_ep & U3_DEV_SETUPENDISR) {
			u3_setupend_isr_handle(&usb_priv);
		}
		if (intr_ep & (U3_DEV_EP0ISR | U3_DEV_SETUPENDISR)) { //no ep0 isr when setup end interrupt asserted
			u3_ep0_isr_handle(&usb_priv);
		}
	}
	/*handle DMA ISR , only handle unmask isr*/
	if (intr_l1 & U3_DEV_DMA_INTR) {
	}
	/*handle QMU ISR , only handle unmask isr*/
	if ((intr_l1 & U3_DEV_QMU_INTR) && 
		((intr_qmu_done & (*USB3_QMU_QIER0)) || (intr_qmu_empty_err & (*USB3_QMU_QIER1)))) {
		usbdev_printf(USBDEV_UARTDBG_TRACE, "[%s : %d] QMU INTR QISAR0 = %x, QISAR1=%x\n\r"
												,__FUNCTION__, __LINE__, intr_qmu_done, intr_qmu_empty_err);
	}
}


/*!
 *	@brief	Get USB RX data by this API
 *	@param	recv_buf : buffer to store received data
 *	@param	p_len: return received data length 
 *	@return	KAL_TRUE: received data, KAL_FLASE: no received data
*/
kal_bool hifusb_get_rx_data(kal_uint8 *recv_buf, kal_uint32 *p_len)
{
	kal_bool ret = KAL_FALSE;
	qbm_gpd *p_gpd = NULL;
	kal_uint8 q_num = 0;
	kal_uint32 checksum = 0;

	q_num = HIFUSB_EPNO_2_QNO(USBC_ACM_DATA_OUT_EP);
	p_gpd = (qbm_gpd *)&brom_rgpd.data_gpd;
	*p_len = 0;

	if (brom_rgpd.in_use == KAL_FALSE) {
		brom_rgpd.in_use = KAL_TRUE;

		/*stop queue*/
		HIF_QMU_STOP(KAL_FALSE, q_num);
		HIF_QMU_CHK_STOP_COMPLETE(KAL_FALSE, q_num);

		/*fill GPD format*/
		QBM_DES_SET_HWO(p_gpd);
		QBM_DES_SET_DATAPTR(p_gpd, recv_buf);
		checksum = cal_checksum_by_len((kal_uint8*)p_gpd, DEFAULT_QMU_CS_12);
		QBM_DES_SET_CHKSUM(p_gpd, checksum);

		/*start queue*/
		HIF_QMU_SET_START_ADDR(KAL_FALSE, q_num, p_gpd);
		HIF_QMU_START(KAL_FALSE, q_num);
	} else {
		if (QBM_DES_GET_HWO(p_gpd) == 0) {
			/*return receive data and data length*/
			*p_len = QBM_DES_GET_DATALEN(p_gpd);
			/*restart RXQ*/
			if (brom_rgpd.sig != BROM_GPD_SIGNATURE) {
				//ERROR				
				//serial_put_errno(ERR_USB_PREFIX | E_USB_GPD_SIG_ERR_UL);
				brom_reset_rgpd(usb_priv.rx_ep_config[HIFUSB_EPNO_2_QNO(USBC_ACM_DATA_OUT_EP)].MaxPacketSize, KAL_FALSE);
			}
			/*bootrom service recycle the buffer and HIF set buffer not in-use to wait new buffer submitted*/
			brom_rgpd.in_use = KAL_FALSE;

			ret = KAL_TRUE;
		}
	}
	
	return ret;
}

/*!
 *	@brief	Send USB Tx data by this API, will blocked until sent, no timeout
 *	@param	send_buf : buffer to send
 *	@param	len : the data length to send
 *	@return	KAL_TRUE: data send success, KAL_FALSE: data send fail
*/
kal_bool hifusb_send_tx_data(kal_uint8 *send_buf, kal_uint32 len)
{
	kal_bool ret = KAL_FALSE;
	qbm_gpd *p_gpd = NULL;
	kal_uint8 q_num = 0;
	kal_uint32 checksum = 0, timeout = 0;

	q_num = HIFUSB_EPNO_2_QNO(USBC_ACM_DATA_IN_EP);
	p_gpd = (qbm_gpd *)&brom_tgpd.data_gpd;

	if (brom_tgpd.in_use == KAL_FALSE) {
		brom_tgpd.in_use = KAL_TRUE;
		
		/*stop queue*/
		HIF_QMU_STOP(KAL_TRUE, q_num);
		HIF_QMU_CHK_STOP_COMPLETE(KAL_TRUE, q_num);
		/*fill GPD format*/
		QBM_DES_SET_HWO(p_gpd);
		QBM_DES_SET_DATAPTR(p_gpd, send_buf);
		QBM_DES_SET_DATALEN(p_gpd, len);
		checksum = cal_checksum_by_len((kal_uint8*)p_gpd, DEFAULT_QMU_CS_12);
		QBM_DES_SET_CHKSUM(p_gpd, checksum);
		/*start queue*/
		HIF_QMU_SET_START_ADDR(KAL_TRUE, q_num, p_gpd);
		HIF_QMU_START(KAL_TRUE, q_num);
	}
	/*block here until tx packet sent*/
	while(1) {
		if (QBM_DES_GET_HWO(p_gpd) == 0) {
			if (brom_tgpd.sig != BROM_GPD_SIGNATURE) {
				//ERROR
				//serial_put_errno(ERR_USB_PREFIX | E_USB_GPD_SIG_ERR_DL);
				brom_reset_tgpd();
				brom_tgpd.in_use = KAL_TRUE;
			}
			brom_tgpd.in_use = KAL_FALSE;
			ret = KAL_TRUE;
			break;
		}
		/*must polling USB ISR or might blocked host request command*/
		u3_isr_handler();

		//gpt_delay_us(1);
		BL_GPT_UDELAY(1);
		timeout ++;
		if (timeout > 5000000) { //count 5sec to output debug information
			timeout = 0;
			//serial_put_errno(ERR_USB_PREFIX | E_USB_TX_BLOCKED);
		}

	}
	return ret;
}

