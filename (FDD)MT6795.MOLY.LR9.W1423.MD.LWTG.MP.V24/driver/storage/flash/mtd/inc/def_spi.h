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
 *   def_spi.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 * definition for spi flash
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * Add SPI Driver to storage/flash/mtd folder.
 * 
 ****************************************************************************/

#ifndef _SPIFLASH_DEF_H_
#define _SPIFLASH_DEF_H_

#define BIT(b)	(1<<b)

/* Return values */
enum{
	SPI_FLASH_ERR = -1,
	SPI_FLASH_OK
};

enum{
	SPI_FLASH_FIFO0,
	SPI_FLASH_FIFO1
};

// there has new DRV_Reg32 in new UT envionment	
// #define REG32(addr)     (*((volatile unsigned int*)(addr)))

/*-------------------------------------------------------
 *        Serial Flash Interface Access Macros in MTD Driver
 *-------------------------------------------------------*/

#define SFI_ReadReg8(addr)          *((volatile unsigned char *)(addr))
#define SFI_ReadReg32(addr)         *((volatile unsigned int *)(addr))
#define SFI_WriteReg32(addr, data)  *((volatile unsigned int *)(addr)) = (unsigned int)(data)
	
	
	
/* Ping-pong parameters */
#define SPI_FLASH_FIFO_DEPTH		256
#define SPI_FLASH_FIFO_TRUE_DEPTH	256

/* Polling time maximum */
/* 10 times of theory length and round up */
#define SPI_FLASH_POLL_WAITWIP_MAX	30000	//64x32
#define SPI_FLASH_POLL_CMD_MAX		20000
/* assume 200MHz */
#define SPI_FLASH_POLL_PP_MAX		3200		//max 5ms, 5m*200M/(1024*32)
#define SPI_FLASH_POLL_E4K_MAX		20000	//max 300ms, 300m*200M/(1024*32)
#define SPI_FLASH_POLL_E64K_MAX		150000	//max 2s
#define SPI_FLASH_POLL_CE_MAX		2500000	//max 250s for 128Mb

/* SPI flash memory space */
#define SPI_FLASH_START_ADDRESS	0xA0000000

/* System clocks */
#define SPI_FLASH_NORMAL_CLK	33
#define SPI_FLASH_READ_CLK		33
#define SPI_FLASH_FASTREAD_CLK	75

/* Common commands */
#define SPI_FLASH_CMD_WRSR		0x01
#define SPI_FLASH_CMD_PP		0x02
#define SPI_FLASH_CMD_READ		0x03
#define SPI_FLASH_CMD_WRDI		0x04
#define SPI_FLASH_CMD_RDSR		0x05
#define SPI_FLASH_CMD_WREN		0x06
#define SPI_FLASH_CMD_FASTREAD	0x0B

#define SPI_FLASH_CMD_E4K		0x20
#define SPI_FLASH_CMD_SE		0xD8
#define SPI_FLASH_CMD_CE		0xC7
#define SPI_FLASH_CMD_RDID		0x9F
#define SPI_FLASH_CMD_PWDN		0xB9
#define SPI_FLASH_CMD_WKUP		0xAB
#define SPI_FLASH_CMD_REMS		0x90

/* Manufacturer-specific commands */
#define SPI_FLASH_MXIC_2READ		0xBB
#define SPI_FLASH_WNBD_DUALREAD		0x3B
#define SPI_FALSH_WNBD_CONPROGRAM	0xAD

#define SPI_FLASH_MXIC_REMS2		0xEF
#define SPI_FLASH_MXIC_REMS4		0xDF
#define SPI_FLASH_MXIC_REMS4D		0xCF

/* SPI Flash Status Register */
#define SPI_FLASH_SR_WIP			0x01
#define SPI_FLASH_SR_WEL			0x02
#define SPI_FLASH_SR_BP0			0x04
#define SPI_FLASH_SR_BP1			0x08
#define SPI_FLASH_SR_BP2			0x10
#define SPI_FLASH_SR_SRWD			0x80

/* SPIC Registers */
/*
#define SPI_FLASH_CTRL_BASE			0xAB000000
#define SPI_FLASH_CTRL_REG			(SPI_FLASH_CTRL_BASE+0x0000)
#define SPI_FLASH_INPUT_LEN_REG		(SPI_FLASH_CTRL_BASE+0x0004)
#define SPI_FLASH_OUTPUT_LEN_REG	(SPI_FLASH_CTRL_BASE+0x0008)
#define SPI_FLASH_MAC_CTRL_REG		(SPI_FLASH_CTRL_BASE+0x000C)
#define SPI_FLASH_ASYNC_REG			(SPI_FLASH_CTRL_BASE+0x0010)
#define SPI_FLASH_FIFO_CTRL_REG		(SPI_FLASH_CTRL_BASE+0x0080)
#define SPI_FLASH_PROTEC_CTRL_REG	(SPI_FLASH_CTRL_BASE+0x0090)
#define SPI_FLASH_OFFSET_ADDR_REG	(SPI_FLASH_CTRL_BASE+0x0094)
#define SPI_FLASH_PROTEC_TOP1_REG	(SPI_FLASH_CTRL_BASE+0x0098)
#define SPI_FLASH_PROTEC_BOT1_REG	(SPI_FLASH_CTRL_BASE+0x009C)
#define SPI_FLASH_PROTEC_TOP2_REG	(SPI_FLASH_CTRL_BASE+0x00A0)
#define SPI_FLASH_PROTEC_BOT2_REG	(SPI_FLASH_CTRL_BASE+0x00A4)
#define SPI_FLASH_MPU_ERR_ADDR_REG	(SPI_FLASH_CTRL_BASE+0x00A8)
#define SPI_FLASH_FIFO_REG			0xAC000000
*/
#define SPI_FLASH_CTRL_BASE			0xBE940000
#define SPI_FLASH_CTRL_REG			(SPI_FLASH_CTRL_BASE+0x0004)
#define SPI_FLASH_INPUT_LEN_REG		(SPI_FLASH_CTRL_BASE+0x000C)
#define SPI_FLASH_OUTPUT_LEN_REG	(SPI_FLASH_CTRL_BASE+0x0010)
#define SPI_FLASH_MAC_CTRL_REG		(SPI_FLASH_CTRL_BASE+0x0014)
#define SPI_FLASH_ASYNC_REG			(SPI_FLASH_CTRL_BASE+0x0018)
#define SPI_FLASH_FIFO_CTRL_REG		(SPI_FLASH_CTRL_BASE+0x0080)
#define SPI_FLASH_PROTEC_CTRL_REG	(SPI_FLASH_CTRL_BASE+0x0090)
#define SPI_FLASH_OFFSET_ADDR_REG	(SPI_FLASH_CTRL_BASE+0x0094)
#define SPI_FLASH_PROTEC_TOP1_REG	(SPI_FLASH_CTRL_BASE+0x0098)
#define SPI_FLASH_PROTEC_BOT1_REG	(SPI_FLASH_CTRL_BASE+0x009C)
#define SPI_FLASH_PROTEC_TOP2_REG	(SPI_FLASH_CTRL_BASE+0x00A0)
#define SPI_FLASH_PROTEC_BOT2_REG	(SPI_FLASH_CTRL_BASE+0x00A4)
#define SPI_FLASH_MPU_ERR_ADDR_REG	(SPI_FLASH_CTRL_BASE+0x00A8)
#define SPI_FLASH_FIFO_REG			0xBE990000



#define SPI_FLASH_FIFO0_OWN			BIT(0)
#define SPI_FLASH_FIFO1_OWN			BIT(1)
#define SPI_FLASH_FIFO0_ERR			BIT(2)
#define SPI_FLASH_FIFO1_ERR			BIT(3)
#define SPI_FLASH_TRIGGER			BIT(1)
#define SPI_FLASH_MAC_EN			BIT(2)
#define SPI_FLASH_CTRL_WIP			BIT(0)
#define SPI_FLASH_CTRL_WIP_RD_RDY	BIT(1)
#define SPI_FLASH_MPU_ENABLE1		BIT(0)
#define SPI_FLASH_MPU_ENABLE2		BIT(1)
#define SPI_FLASH_MPU_INT			BIT(2)

#define SPI_FLASH_SLOWREAD		0
#define SPI_FLASH_FASTREAD		1
#define SPI_FLASH_FASTREAD_DUALOUT	2	/* WNBD */
#define SPI_FLASH_2READ			3		/* MXIC */


#define SPICLK_135M		0x0
#define SPICLK_108M		0x1
#define SPICLK_90M		0x2
#define SPICLK_77M		0x3
#define SPICLK_67M		0x4
#define SPICLK_60M		0x5
#define SPICLK_54M		0x6
#define SPICLK_49M		0x7
#define SPICLK_45M		0x8
#define SPICLK_38M		0x9
#define SPICLK_33M		0xA
#define SPICLK_30M		0xB
#define SPICLK_27M		0xC 
#define SPICLK_20M		0xD
#define SPICLK_10M		0xE
#define SPICLK_5M		0xF


#endif /* _SPIFLASH_DEF_H */
