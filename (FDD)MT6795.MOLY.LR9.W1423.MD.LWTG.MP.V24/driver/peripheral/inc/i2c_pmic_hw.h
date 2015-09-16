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
 *    i2c_pmic_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for I2C DUAL driver.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _I2C_PMIC_HW_H
#define _I2C_PMIC_HW_H
#include "drv_features.h"

#include "drv_comm.h"
#include "reg_base.h"

#if defined(DRV_I2C_PMIC)

#ifndef __DRV_DEBUG_I2C_PMIC_REG_READ_WRITE__
#define I2C_PMIC_DRV_ClearBits16(addr, data)       DRV_ClearBits(addr,data)
#define I2C_PMIC_DRV_SetBits16(addr, data)         DRV_SetBits(addr,data)
#define I2C_PMIC_DRV_WriteReg16(addr, data)        DRV_WriteReg(addr, data)
#define I2C_PMIC_DRV_ReadReg16(addr)               DRV_Reg(addr)
#define I2C_PMIC_DRV_ClearBits32(addr, data)       DRV_ClearBits32(addr, data)
#define I2C_PMIC_DRV_SetData(addr, bitmask, value)       DRV_SetData(addr, bitmask, value)
#else // #ifndef __DRV_DEBUG_I2C_PMIC_REG_READ_WRITE__
#define I2C_PMIC_DRV_ClearBits16(addr,data)        DRV_DBG_ClearBits(addr,data)
#define I2C_PMIC_DRV_SetBits16(addr)               DRV_DBG_SetBits(addr)
#define I2C_PMIC_DRV_WriteReg16(addr, data)        DRV_DBG_WriteReg(addr, data)
#define I2C_PMIC_DRV_ReadReg16(addr)               DRV_DBG_Reg(addr)
#define I2C_PMIC_DRV_ClearBits32(addr, data)       DRV_DBG_ClearBits32(addr, data)
#define I2C_PMIC_DRV_SetData(addr, bitmask, value)       DRV_SetData(addr, bitmask, value)
#endif // #ifndef __DRV_DEBUG_I2C_PMIC_REG_READ_WRITE__


//#define I2CP_base I2C_DUAL_base
#define I2CP_base I2C_base
#define PMIC6327_I2C_ID		    0xC0


// I2CP means I2C for PMIC
#define I2CP_DATA_PORT						(I2CP_base + 0x00)
#define I2CP_SLAVE_ADDR					(I2CP_base + 0x04)
#define I2CP_INTR_MASK						(I2CP_base + 0x08)
#define I2CP_INTR_STAT						(I2CP_base + 0x0C)
#define I2CP_CTRL							(I2CP_base + 0x10)
#define I2CP_TRANSFER_LEN					(I2CP_base + 0x14)
#define I2CP_TRANSFER_LEN_AUX				(I2CP_base + 0x6c)
#define I2CP_TRANSAC_LEN					(I2CP_base + 0x18)
#define I2CP_DELAY_LEN						(I2CP_base + 0x1C)
#define I2CP_TIMING							(I2CP_base + 0x20)
#define I2CP_START							(I2CP_base + 0x24)
#define I2CP_FIFO_STAT						(I2CP_base + 0x30)
#define I2CP_FIFO_THRESH					(I2CP_base + 0x34)
#define I2CP_FIFO_ADDR_CLR					(I2CP_base + 0x38)
#define I2CP_IO_CONFIG						(I2CP_base + 0x40)
#define I2CP_HS								(I2CP_base + 0x48)
#define I2CP_SOFTRESET						(I2CP_base + 0x50)
#define I2CP_DEBUGSTAT						(I2CP_base + 0x64)
#define I2CP_DEBUGCTRL						(I2CP_base + 0x68)
#define I2CP_TIMEOUT						(I2CP_base + 0x74)
#define I2CP_VERSION						(I2CP_base + 0x78)


// 0x00
#define I2CP_DATA_PORT_MASK							0x00FF									
#define I2CP_DATA_PORT_SHIFT						0									
                                                											
// 0x04                                         											
#define I2CP_SLAVE_ADDR_MASK						0x00FF									
#define I2CP_SLAVE_ADDR_SHIFT						0									
                                                											
// 0x08                                         											
#define I2CP_INTR_MASK_TRANS_COMP_MASK				0x0001									
#define I2CP_INTR_MASK_TRANS_COMP_SHIFT				0									
#define I2CP_INTR_MASK_ACK_ERR_MASK					0x0002									
#define I2CP_INTR_MASK_ACK_ERR_SHIFT					1									
#define I2CP_INTR_MASK_HSNAK_ERR_MASK				0x0004									
#define I2CP_INTR_MASK_HSNAK_ERR_SHIFT				2									
#define I2CP_INTR_MASK_TIMEOUT_MASK					0x0010									
#define I2CP_INTR_MASK_TIMEOUT_SHIFT					4									

// 0x0C
#define I2CP_INTR_STAT_TRANS_COMP_MASK				0x0001
#define I2CP_INTR_STAT_TRANS_COMP_SHIFT				0
#define I2CP_INTR_STAT_ACK_ERR_MASK					0x0002
#define I2CP_INTR_STAT_ACK_ERR_SHIFT					1
#define I2CP_INTR_STAT_HSNAK_ERR_MASK				0x0004
#define I2CP_INTR_STAT_HSNAK_ERR_SHIFT				2
#define I2CP_INTR_STAT_TIMEOUT_MASK					0x0010
#define I2CP_INTR_STAT_TIMEOUT_SHIFT					4


// 0x10
#define I2CP_CTRL_RESTART_MASK					0x0002
#define I2CP_CTRL_RESTART_SHIFT					1
#define I2CP_CTRL_DMA_EN_MASK						0x0004
#define I2CP_CTRL_DMA_EN_SHIFT					2
#define I2CP_CTRL_CLK_EXT_EN_MASK					0x0008
#define I2CP_CTRL_CLK_EXT_EN_SHIFT				3
#define I2CP_CTRL_DIR_CHANGE_MASK					0x0010
#define I2CP_CTRL_DIR_CHANGE_SHIFT				4
#define I2CP_CTRL_ACKERR_DET_EN_MASK				0x0020
#define I2CP_CTRL_ACKERR_DET_EN_SHIFT				5
#define I2CP_CTRL_TRANSFER_LEN_CHANGE_MASK		0x0040
#define I2CP_CTRL_TRANSFER_LEN_CHANGE_SHIFT		6
#define I2CP_CTRL_RESET_BUS_BUSY_EN_MASK			0x0080
#define I2CP_CTRL_RESET_BUS_BUSY_EN_SHIFT		7
#define I2CP_CTRL_TIMEOUT_EN_MASK					0x0100
#define I2CP_CTRL_TIMEOUT_EN_SHIFT				8

// 0x14
#define I2CP_TRANSFER_LEN_TRANSFER_LEN_MASK			0x00FF
#define I2CP_TRANSFER_LEN_TRANSFER_LEN_SHIFT		0

// 0x6c
#define I2CP_TRANSFER_LEN_AUX_TRANSFER_LEN_AUX_MASK			0x00FF
#define I2CP_TRANSFER_LEN_AUX_TRANSFER_LEN_AUX_SHIFT		0

// 0x18
#define I2CP_TRANSAC_LEN_TRANSAC_LEN_MASK			0x00FF
#define I2CP_TRANSAC_LEN_TRANSAC_LEN_SHIFT			0

// 0x1C
#define I2CP_DELAY_LEN_DELAY_LEN_MASK				0x00FF
#define I2CP_DELAY_LEN_DELAY_LEN_SHIFT				0

// 0x20
#define I2CP_TIMING_STEP_CNT_DIV_MASK				0x003F
#define I2CP_TIMING_STEP_CNT_DIV_SHIFT				0
#define I2CP_TIMING_SAMPLE_CNT_DIV_MASK				0x0700
#define I2CP_TIMING_SAMPLE_CNT_DIV_SHIFT				8
#define I2CP_TIMING_DATA_READ_MASK					0x7000
#define I2CP_TIMING_DATA_READ_SHIFT					12
#define I2CP_TIMING_DATA_READ_ADJ_MASK				0x8000
#define I2CP_TIMING_DATA_READ_ADJ_SHIFT				15
                                                    	
// 0x24
#define I2CP_START_START_MASK						0x0001
#define I2CP_START_START_SHIFT						0

// 0x30
#define I2CP_FIFO_STAT_RD_EMPTY_MASK					0x0001
#define I2CP_FIFO_STAT_RD_EMPTY_SHIFT				0
#define I2CP_FIFO_STAT_WR_FULL_MASK					0x0002
#define I2CP_FIFO_STAT_WR_FULL_SHIFT					1
#define I2CP_FIFO_STAT_OFFSET_MASK					0x00F0
#define I2CP_FIFO_STAT_OFFSET_SHIFT					4
#define I2CP_FIFO_STAT_WR_ADDR_MASK					0x0F00
#define I2CP_FIFO_STAT_WR_ADDR_SHIFT					8
#define I2CP_FIFO_STAT_RD_ADDR_MASK					0xF000
#define I2CP_FIFO_STAT_RD_ADDR_SHIFT					12

// 0x34
#define I2CP_FIFO_THRESH_RX_TRIG_MASK				0x0007
#define I2CP_FIFO_THRESH_RX_TRIG_SHIFT				0
#define I2CP_FIFO_THRESH_TX_TRIG_MASK				0x0700
#define I2CP_FIFO_THRESH_TX_TRIG_SHIFT				8

// 0x38
#define I2CP_FIFO_ADDR_CLR_CR_MASK					0x0001
#define I2CP_FIFO_ADDR_CLR_CR_SHIFT					0

// 0x40
#define I2CP_IO_CONFIG_SCL_IO_MASK						0x0001
#define I2CP_IO_CONFIG_SCL_IO_SHIFT						0
#define I2CP_IO_CONFIG_SDA_IO_MASK						0x0002
#define I2CP_IO_CONFIG_SDA_IO_SHIFT						1
#define I2CP_IO_CONFIG_SYNC_EN_MASK						0x0004
#define I2CP_IO_CONFIG_SYNC_EN_SHIFT						2
#define I2CP_IO_CONFIG_IDLE_OE_EN_MASK                  			0x0008  
#define I2CP_IO_CONFIG_IDLE_OE_SIFT                     			3       

// 0x48
#define I2CP_HS_HS_EN_MASK							0x0001
#define I2CP_HS_HS_EN_SHIFT							0
#define I2CP_HS_HS_NAK_ERR_DET_EN_MASK				0x0002
#define I2CP_HS_HS_NAK_ERR_DET_EN_SHIFT				1
#define I2CP_HS_MASTER_CODE_MASK						0x0070
#define I2CP_HS_MASTER_CODE_SHIFT						4
#define I2CP_HS_HS_STEP_CNT_DIV_MASK					0x0700
#define I2CP_HS_HS_STEP_CNT_DIV_SHIFT					8
#define I2CP_HS_HS_SAMPLE_CNT_DIV_MASK				0x7000
#define I2CP_HS_HS_SAMPLE_CNT_DIV_SHIFT				12

// 0x50
#define I2CP_SOFTRESET_SOFTRESET_MASK				0x0001
#define I2CP_SOFTRESET_SOFTRESET_SHIFT				0

//0x64
#define I2CP_DEBUG_STAT_MASTER_STAT_MASK			0x001f
#define I2CP_DEBUG_STAT_MASTER_STAT_SHIFT			0
#define I2CP_DEBUG_STAT_MASTER_READ_MASK			0x0020
#define I2CP_DEBUG_STAT_MASTER_READ_SHIFT			5
#define I2CP_DEBUG_STAT_MASTER_WRITE_MASK			0x0040
#define I2CP_DEBUG_STAT_MASTER_WRITE_SHIFT			6
#define I2CP_DEBUG_STAT_BUS_BUSY_MASK				0x0080
#define I2CP_DEBUG_STAT_BUS_BUSY_SHIFT				7



///////////////////////////////////////////////////////////////////////////////
// Ch1 macros
#define I2C_PMIC_CLEAR_FIFO(val)				I2C_PMIC_DRV_WriteReg16(I2CP_FIFO_ADDR_CLR, (kal_uint16)1)
#define I2C_PMIC_CLEAR_INTR_STAT(val)			{\
	kal_uint16 tmp;\
	tmp = I2C_PMIC_DRV_ReadReg16(I2CP_INTR_STAT);\
	tmp &= (I2CP_INTR_STAT_TRANS_COMP_MASK | I2CP_INTR_STAT_ACK_ERR_MASK|I2CP_INTR_STAT_HSNAK_ERR_MASK|I2CP_INTR_STAT_TIMEOUT_MASK);\
	tmp |= (val);\
	I2C_PMIC_DRV_WriteReg16(I2CP_INTR_STAT, tmp);\
}
#define I2C_PMIC_SET_SLAVE_ADDR(val)			I2C_PMIC_DRV_WriteReg16(I2CP_SLAVE_ADDR, (kal_uint16)val)
#define I2C_PMIC_SET_TRANSFER_LEN(len1, len2)	{\
	kal_uint16 tmp;\
	tmp = I2C_PMIC_DRV_ReadReg16(I2CP_TRANSFER_LEN);\
	tmp &= ~(I2CP_TRANSFER_LEN_TRANSFER_LEN_MASK);\
	tmp |= ((kal_uint16)len1 << I2CP_TRANSFER_LEN_TRANSFER_LEN_SHIFT);\
	I2C_PMIC_DRV_WriteReg16(I2CP_TRANSFER_LEN, tmp);\
	tmp = I2C_PMIC_DRV_ReadReg16(I2CP_TRANSFER_LEN_AUX);\
	tmp &= ~(I2CP_TRANSFER_LEN_AUX_TRANSFER_LEN_AUX_MASK);\
	tmp |= ((kal_uint16)len1 << I2CP_TRANSFER_LEN_AUX_TRANSFER_LEN_AUX_SHIFT);\
	I2C_PMIC_DRV_WriteReg16(I2CP_TRANSFER_LEN_AUX, tmp);\
}

#define I2C_PMIC_SET_TIMING(sample_cnt, step_cnt)	{\
	kal_uint16 tmp;\
	tmp = I2C_PMIC_DRV_ReadReg16(I2CP_TIMING);\
	tmp &= ~(I2CP_TIMING_STEP_CNT_DIV_MASK | I2CP_TIMING_SAMPLE_CNT_DIV_MASK);\
	tmp |= ((kal_uint16)sample_cnt << I2CP_TIMING_SAMPLE_CNT_DIV_SHIFT);\
	tmp |= ((kal_uint16)step_cnt << I2CP_TIMING_STEP_CNT_DIV_SHIFT);\
	I2C_PMIC_DRV_WriteReg16(I2CP_TIMING, tmp);\
}

#define I2C_PMIC_SET_TRANSAC_LEN(len)		I2C_PMIC_DRV_WriteReg16(I2CP_TRANSAC_LEN, (kal_uint16)len);
#define I2C_PMIC_SET_DIR_CHANGE(val)		{\
	kal_uint16 tmp;\
	tmp = I2C_PMIC_DRV_ReadReg16(I2CP_CTRL);\
	tmp &= ~I2CP_CTRL_DIR_CHANGE_MASK;\
	tmp |= ((kal_uint16)val << I2CP_CTRL_DIR_CHANGE_SHIFT);\
	I2C_PMIC_DRV_WriteReg16(I2CP_CTRL, tmp);\
}


#define I2C_PMIC_SET_ACKERR_DET_EN(val)		{\
	kal_uint16 tmp;\
	tmp = I2C_PMIC_DRV_ReadReg16(I2CP_CTRL);\
	tmp &= ~I2CP_CTRL_ACKERR_DET_EN_MASK;\
	tmp |= ((kal_uint16)val << I2CP_CTRL_ACKERR_DET_EN_SHIFT);\
	I2C_PMIC_DRV_WriteReg16(I2CP_CTRL, tmp);\
}

#define I2C_PMIC_SET_CLK_EXT_EN(val)		{\
	kal_uint16 tmp;\
	tmp = I2C_PMIC_DRV_ReadReg16(I2CP_CTRL);\
	tmp &= ~I2CP_CTRL_CLK_EXT_EN_MASK;\
	tmp |= ((kal_uint16)val << I2CP_CTRL_CLK_EXT_EN_SHIFT);\
	I2C_PMIC_DRV_WriteReg16(I2CP_CTRL, tmp);\
}


#define I2C_PMIC_SET_RESTART(val)		{\
	kal_uint16 tmp;\
	tmp = I2C_PMIC_DRV_ReadReg16(I2CP_CTRL);\
	tmp &= ~I2CP_CTRL_RESTART_MASK;\
	tmp |= ((kal_uint16)val << I2CP_CTRL_RESTART_SHIFT);\
	I2C_PMIC_DRV_WriteReg16(I2CP_CTRL, tmp);\
}


#define I2C_PMIC_SET_INTR(val)		{\
	kal_uint16 tmp;\
	tmp = I2C_PMIC_DRV_ReadReg16(I2CP_INTR_MASK);\
	tmp |= (val & (I2CP_INTR_MASK_TRANS_COMP_MASK | I2CP_INTR_MASK_ACK_ERR_MASK | I2CP_INTR_MASK_HSNAK_ERR_MASK));\
	I2C_PMIC_DRV_WriteReg16(I2CP_INTR_MASK, (kal_uint16)tmp);\
}

#define I2C_PMIC_CLR_INTR(val)		{\
	kal_uint16 tmp;\
	tmp = I2C_PMIC_DRV_ReadReg16(I2CP_INTR_MASK);\
	tmp &= ~(val & (I2CP_INTR_MASK_TRANS_COMP_MASK | I2CP_INTR_MASK_ACK_ERR_MASK | I2CP_INTR_MASK_HSNAK_ERR_MASK) );\
	I2C_PMIC_DRV_WriteReg16(I2CP_INTR_MASK, (kal_uint16)tmp);\
}


#define I2C_PMIC_SET_DATA_PORT(val)			I2C_PMIC_DRV_WriteReg16(I2CP_DATA_PORT, (kal_uint16)val)
#define I2C_PMIC_GET_START()				((I2C_PMIC_DRV_ReadReg16(I2CP_START)&I2CP_START_START_MASK)>>I2CP_START_START_SHIFT)
#define I2C_PMIC_SET_START(val)						I2C_PMIC_DRV_WriteReg16(I2CP_START, I2CP_START_START_MASK);



#endif // #if defined(DRV_I2C_PMIC)

#endif // #ifndef _I2C_PMIC_HW_H

