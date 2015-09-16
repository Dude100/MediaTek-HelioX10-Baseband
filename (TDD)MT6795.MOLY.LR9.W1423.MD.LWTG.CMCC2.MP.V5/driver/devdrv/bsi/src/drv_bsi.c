/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 *   drv_bsi.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   BSI-PMIC (Baseband Serial Interface - Power Management Integrated Circuit) Driver
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
 * assert in error handling function
 *
 * removed!
 * removed!
 * add error handling function
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Integration change.
 *
 * removed!
 * removed!
 * [TRUNK] bsi driver update and  bsispi init cmm add
 *
 * removed!
 * removed!
 * [TRUNK] add failWrite BSI-PMIC API for reset test
 *
 * removed!
 * removed!
 * [TRUNK] BSI-PMIC driver update after testing on MT6339 ES1
 *
 * removed!
 * removed!
 * [TRUNK] add BSI-PMIC driver design and .mak
 ****************************************************************************/
#include "drv_features_bsi.h"
#include "drv_comm.h"

#include "drv_bsi.h"
#include "intrCtrl.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
 
kal_char bsi_dbg_str[128];
kal_uint32 bsi_enter_leave[16];
kal_uint32 bsi_enter_leave_ptr = 0;
kal_uint32 bsi_mutex = 0;

#if defined(__UBL__)
#define BSI_IN
#define BSI_OUT
#else
#define BSI_IN									\
do{										\
while(bsi_mutex);								\
bsi_mutex++;									\
bsi_enter_leave[bsi_enter_leave_ptr] = kal_get_active_module_id();		\
bsi_enter_leave_ptr++;								\
bsi_enter_leave_ptr %= 16;							\
} while(0)

#define BSI_OUT									\
do{										\
bsi_enter_leave[bsi_enter_leave_ptr] = kal_get_active_module_id() | 0xF000;	\
bsi_enter_leave_ptr++;								\
bsi_enter_leave_ptr %= 16;							\
bsi_mutex--;									\
} while(0)
#endif

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_bsi_pmic_init
*
* DESCRIPTION
*  This function is to initialize BSI SPI controller for PMIC.
*
* PARAMETERS
*  None.
*
* RETURNS
*  None.
*
*------------------------------------------------------------------------*/
void drv_bsi_pmic_init(void)
{
    kal_uint32 setting;

	BSI_IN;

    DRV_WriteReg32(0xBF300114, DRV_Reg32(0xBF300114) | 0x6); // LPHYCTL_HREADY_ENABLE
    DRV_WriteReg32(0xBF200114, DRV_Reg32(0xBF200114) | 0x4); // LPHYCTL_INTERRUPT_ENABLE

    setting = (DRV_BSI_MIPI_EN << BSISPI_MIPI_EN_OFFSET);
    setting |= (DRV_BSI_MODE << BSISPI_BSI_MODE_OFFSET);
    setting |= (DRV_BSI_SINGLE_DIR << BSISPI_SINGLE_DIR_OFFSET);
    setting |= (DRV_BSI_CLSNINT_EN << BSISPI_CLSNINT_EN_OFFSET);
    setting |= (DRV_BSI_DBG_EN << BSISPI_DBG_EN_OFFSET);
    setting |= (DRV_BSI_READ_PHASE << BSISPI_READ_PHASE_OFFSET);
    setting |= (DRV_BSI_RESET_MODE << BSISPI_RESET_MODE_OFFSET);
    setting |= (DRV_BSI_IO_MODE << BSISPI_IO_MODE_OFFSET);
    setting |= (DRV_BSI_SW_CS_SEL << BSISPI_SW_CS_SEL_OFFSET);
    DRV_WriteReg32(BSISPI_PORT_PARAM_REG, setting);

#if DRV_BSI_CS0_SUPPORT
    setting = (DRV_BSI_CLK_POL0 << BSISPI_CLK_POL_OFFSET);
    setting |= (DRV_BSI_CLK_SPD0 << BSISPI_CLK_SPD_OFFSET);
    setting |= (DRV_BSI_CS0_LEN << BSISPI_CS_LEN_OFFSET);
    setting |= (DRV_BSI_CS0_POL << BSISPI_CS_POL_OFFSET);
    setting |= (DRV_BSI_RD_CLK_SPD0 << BSISPI_RD_CLK_SPD_OFFSET);
    setting |= (DRV_BSI_RD_TRANS_CLKON0 << BSISPI_RD_TRANS_CLKON_OFFSET);
    setting |= (DRV_BSI_RD_TRANS_LEN0 << BSISPI_RD_TRANS_LEN_OFFSET);
    setting |= (DRV_BSI_IDLE_CNT0 << BSISPI_IDLE_CNT_OFFSET);
    setting |= (DRV_BSI_WLEN0 << BSISPI_WLEN_OFFSET);
    DRV_WriteReg32(BSISPI_IC0_PARAM1_REG, setting);
    
    setting = (DRV_BSI_RD_TRANS_CS0_WAVEFORM << BSISPI_RD_TRANS_CS_WAVEFORM_OFFSET);
    setting |= (DRV_BSI_RD_RDATA_CS0_POL << BSISPI_RD_RDATA_CS_POL_OFFSET);
    setting |= (DRV_BSI_RD_WLEN0 << BSISPI_RD_WLEN_OFFSET);
    setting |= (DRV_BSI_RD_RLEN0 << BSISPI_RD_RLEN_OFFSET);
    DRV_WriteReg32(BSISPI_IC0_PARAM2_REG, setting);
#endif

/*#if DRV_BSI_CS1_SUPPORT
    setting = (DRV_BSI_CLK_POL1 << BSISPI_CLK_POL_OFFSET);
    setting |= (DRV_BSI_CLK_SPD1 << BSISPI_CLK_SPD_OFFSET);
    setting |= (DRV_BSI_CS1_LEN << BSISPI_CS_LEN_OFFSET);
    setting |= (DRV_BSI_CS1_POL << BSISPI_CS_POL_OFFSET);
    setting |= (DRV_BSI_RD_CLK_SPD1 << BSISPI_RD_CLK_SPD_OFFSET);
    setting |= (DRV_BSI_RD_TRANS_CLKON1 << BSISPI_RD_TRANS_CLKON_OFFSET);
    setting |= (DRV_BSI_RD_TRANS_LEN1 << BSISPI_RD_TRANS_LEN_OFFSET);
    setting |= (DRV_BSI_IDLE_CNT1 << BSISPI_IDLE_CNT_OFFSET);
    setting |= (DRV_BSI_WLEN1 << BSISPI_WLEN_OFFSET);
    DRV_WriteReg32(BSISPI_IC1_PARAM1_REG, setting);
    
    setting = (DRV_BSI_RD_TRANS_CS1_WAVEFORM << BSISPI_RD_TRANS_CS_WAVEFORM_OFFSET);
    setting |= (DRV_BSI_RD_RDATA_CS1_POL << BSISPI_RD_RDATA_CS_POL_OFFSET);
    setting |= (DRV_BSI_RD_WLEN1 << BSISPI_RD_WLEN_OFFSET);
    setting |= (DRV_BSI_RD_RLEN1 << BSISPI_RD_RLEN_OFFSET);
    DRV_WriteReg32(BSISPI_IC1_PARAM2_REG, setting);
#endif*/

#if A60386_TARGET
    // for A60386 only: set A60386 before a read event
    drv_bsi_a60386_reg_write(0x010, 0x2);
#endif
	BSI_OUT;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_bsi_pmic6339_reg_write
*
* DESCRIPTION
*  This function is to write MT6339 PMIC register through BSI.
*
* PARAMETERS
*  reg  - MT6339 PMIC register address. (8 bits)
*  val  - data to be written into MT6339 PMIC address. (16 bits)
*
* RETURNS
*  None
*
*------------------------------------------------------------------------*/
void drv_bsi_pmic6339_reg_write(kal_uint8 reg, kal_uint16 val)
{
	BSI_IN;
    kal_uint32 counter = 0;

    while (GET_BSI_IMM_STATUS()) {
        counter++;
        if (counter > 100000) {
		drv_bsi_dump_reg();
            ASSERT(0);
        }
    }
    SET_BSI_IMM_CTRL(DRV_BSI_PORT_SEL, DRV_BSI_CS_SEL, BSI_WRITE_EVENT);
    SET_BSI_IMM_WRITE_DATA(((reg << (DRV_BSI_RD_RLEN0+1)) | (val)));
	BSI_OUT;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_bsi_pmic6339_reg_failWrite
*  (Only for BSI reset testing, not for normal use)
*
* DESCRIPTION
*  This function is to write MT6339 PMIC register through BSI
*  with incorrect number of transfer bits.
*
* PARAMETERS
*  reg  - MT6339 PMIC register address. (8 bits)
*  val  - data to be written into MT6339 PMIC address. (16 bits)
*
* RETURNS
*  None
*
*------------------------------------------------------------------------*/
void drv_bsi_pmic6339_reg_failWrite(kal_uint8 reg, kal_uint16 val)
{
    kal_uint32 counter = 0, setting;

    // Incorrect config
    while (GET_BSI_IMM_STATUS()) {
        counter++;
        if (counter > 100000) {
            ASSERT(0);
        }
    }
    setting = (DRV_BSI_CLK_POL0 << BSISPI_CLK_POL_OFFSET);
    setting |= (DRV_BSI_CLK_SPD0 << BSISPI_CLK_SPD_OFFSET);
    setting |= (DRV_BSI_CS0_LEN << BSISPI_CS_LEN_OFFSET);
    setting |= (DRV_BSI_CS0_POL << BSISPI_CS_POL_OFFSET);
    setting |= (DRV_BSI_RD_CLK_SPD0 << BSISPI_RD_CLK_SPD_OFFSET);
    setting |= (DRV_BSI_RD_TRANS_CLKON0 << BSISPI_RD_TRANS_CLKON_OFFSET);
    setting |= (DRV_BSI_RD_TRANS_LEN0 << BSISPI_RD_TRANS_LEN_OFFSET);
    setting |= (DRV_BSI_IDLE_CNT0 << BSISPI_IDLE_CNT_OFFSET);
    setting |= ((DRV_BSI_WLEN0 - 8) << BSISPI_WLEN_OFFSET); // missing 8 bits
    DRV_WriteReg32(BSISPI_IC0_PARAM1_REG, setting);

    // Fail write
    while (GET_BSI_IMM_STATUS()) {
        counter++;
        if (counter > 100000) {
            ASSERT(0);
        }
    }
    SET_BSI_IMM_CTRL(DRV_BSI_PORT_SEL, DRV_BSI_CS_SEL, BSI_WRITE_EVENT);
    SET_BSI_IMM_WRITE_DATA(((reg << (DRV_BSI_RD_RLEN0+1)) | (val)));

    // Return to original correct config
    while (GET_BSI_IMM_STATUS()) {
        counter++;
        if (counter > 100000) {
            ASSERT(0);
        }
    }
    setting = (DRV_BSI_CLK_POL0 << BSISPI_CLK_POL_OFFSET);
    setting |= (DRV_BSI_CLK_SPD0 << BSISPI_CLK_SPD_OFFSET);
    setting |= (DRV_BSI_CS0_LEN << BSISPI_CS_LEN_OFFSET);
    setting |= (DRV_BSI_CS0_POL << BSISPI_CS_POL_OFFSET);
    setting |= (DRV_BSI_RD_CLK_SPD0 << BSISPI_RD_CLK_SPD_OFFSET);
    setting |= (DRV_BSI_RD_TRANS_CLKON0 << BSISPI_RD_TRANS_CLKON_OFFSET);
    setting |= (DRV_BSI_RD_TRANS_LEN0 << BSISPI_RD_TRANS_LEN_OFFSET);
    setting |= (DRV_BSI_IDLE_CNT0 << BSISPI_IDLE_CNT_OFFSET);
    setting |= (DRV_BSI_WLEN0 << BSISPI_WLEN_OFFSET);
    DRV_WriteReg32(BSISPI_IC0_PARAM1_REG, setting);
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_bsi_pmic6339_reg_read
*
* DESCRIPTION
*  This function is to read MT6339 PMIC register through BSI.
*
* PARAMETERS
*  reg  - MT6339 PMIC register address. (8 bits)
*
* RETURNS
*  value which from MT6339 PMIC address. (16 bits)
*
*------------------------------------------------------------------------*/
kal_uint16 drv_bsi_pmic6339_reg_read(kal_uint8 reg)
{
	BSI_IN;

	kal_uint32 counter = 0, i = 0, tmp = 0, tmp_0 = 0, tmp_1 = 0;

	for(i = 0; i < 3; i++)
	{
		if(i == 2)
		{
			// MDCLKCTL_PLL_FORCE_ON (0xBF81_0400) bit 0-12, bit 16-17 set 1
			tmp_0 = DRV_Reg32(0xBF810400);
			DRV_WriteReg32(0xBF810400, tmp_0 | 0x31FFF);

			// MDCLKCTL_CLKONCTL (0xBF81_0004) bit 0-31 set 1
			tmp_1 = DRV_Reg32(0xBF810004);
			DRV_WriteReg32(0xBF810004, 0xFFFFFFFF);

			// stop event
			tmp = DRV_Reg32(BSI_APB2CRF_IMM_CTRL_REG);
			DRV_WriteReg32(BSI_APB2CRF_IMM_CTRL_REG, tmp | BSI_IMM_STOP);

#if !defined(__UBL__)
			kal_sprintf(bsi_dbg_str, "[BSI] error handling mode start (2)\n\r");
			tst_sys_trace(bsi_dbg_str);							
#endif
		} else if(i == 1)
		{
			// stop event
			tmp = DRV_Reg32(BSI_APB2CRF_IMM_CTRL_REG);
			DRV_WriteReg32(BSI_APB2CRF_IMM_CTRL_REG, tmp | BSI_IMM_STOP);

#if !defined(__UBL__)
			kal_sprintf(bsi_dbg_str, "[BSI] error handling mode start (1)\n\r");
			tst_sys_trace(bsi_dbg_str);							
#endif
		}

		counter = 0;
		while(GET_BSI_IMM_STATUS())
		{
			counter++;
			if(counter > 100000)
			{
				drv_bsi_dump_reg();
				ASSERT(0);
			}
		}
		SET_BSI_IMM_CTRL(DRV_BSI_PORT_SEL, DRV_BSI_CS_SEL, BSI_READ_EVENT);
		SET_BSI_IMM_WRITE_DATA((BSI_READ_EVENT << DRV_BSI_RD_WLEN0) | reg);

		counter = 0;
		while(!GET_BSI_IMM_RD_INT_STATUS())
		{
			counter++;
			if(counter > 100000)
			{
				drv_bsi_dump_reg();
			}
		}
		CLEAR_IMM_RDINT_STS;

		if(i == 2)
		{
			DRV_WriteReg32(0xBF810400, tmp_0);
			DRV_WriteReg32(0xBF810004, tmp_1);
		}

		if(counter < 100000) break;
	}

	if(i == 3) ASSERT(0);

	if(i == 2) ASSERT(0);

	if(i == 1) ASSERT(0);

	BSI_OUT;

	return (kal_uint16)GET_BSI_IMM_READ_DATA_3100();
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_bsi_a60386_reg_write
*
* DESCRIPTION
*  This function is to write A60386 register through BSI.
*
* PARAMETERS
*  reg  - A60386 register address. (12 bits)
*  val  - data to be written into A60386 address. (16 bits)
*
* RETURNS
*  None
*
*------------------------------------------------------------------------*/
void drv_bsi_a60386_reg_write(kal_uint16 reg, kal_uint16 val)
{
    kal_uint32 counter = 0;

    // check address is 12 bits only
    if (reg > 0x1FFF)
        ASSERT(0);

    while (GET_BSI_IMM_STATUS()) {
        counter++;
        if (counter > 100000) {
            ASSERT(0);
        }
    }
    SET_BSI_IMM_CTRL(DRV_BSI_PORT_SEL, DRV_BSI_CS_SEL, BSI_WRITE_EVENT);
    SET_BSI_IMM_WRITE_DATA(((reg << (DRV_BSI_RD_RLEN0+1)) | (val)));
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_bsi_a60386_reg_read
*
* DESCRIPTION
*  This function is to read A60386 register through BSI.
*
* PARAMETERS
*  reg  - A60386 register address. (12 bits)
*
* RETURNS
*  value which from A60386 address. (16 bits)
*
*------------------------------------------------------------------------*/
kal_uint16 drv_bsi_a60386_reg_read(kal_uint16 reg)
{
    kal_uint32 counter = 0;

    // check address is 12 bits only
    if (reg > 0x1FFF)
        ASSERT(0);

    while (GET_BSI_IMM_STATUS()) {
        counter++;
        if (counter > 100000) {
            ASSERT(0);
        }
    }
    SET_BSI_IMM_CTRL(DRV_BSI_PORT_SEL, DRV_BSI_CS_SEL, BSI_READ_EVENT);
    SET_BSI_IMM_WRITE_DATA((BSI_READ_EVENT << DRV_BSI_RD_WLEN0) | reg);
    counter = 0;
    while (!GET_BSI_IMM_RD_INT_STATUS()) {
        counter++;
        if (counter > 100000) {
            ASSERT(0);
        }
    }
    CLEAR_IMM_RDINT_STS;

    return (kal_uint16)GET_BSI_IMM_READ_DATA_3100();
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_bsi_dump_reg
*
* DESCRIPTION
*  This function is to dump BSI related registers
*
* PARAMETERS
*  None 
*
* RETURNS
*  None
*
*------------------------------------------------------------------------*/
void drv_bsi_dump_reg()
{
#if !defined(__UBL__)
	kal_uint32 i = 0;


	kal_sprintf(bsi_dbg_str,"[BSI]%x %x\n\r", DRV_Reg32(0xBF300114), DRV_Reg32(0xBF200114)); // &== 0x6, &== 0x4 (FPGA)
	tst_sys_trace(bsi_dbg_str);							

	kal_sprintf(bsi_dbg_str, "[BSI]%x %x %x %x\n\r", DRV_Reg32(0xF1010880), DRV_Reg32(0xF1010840), DRV_Reg32(0xF10108E0), DRV_Reg32(0xF1010A20)); // even, even, odd, odd
	tst_sys_trace(bsi_dbg_str);

	// bsi clock request of clock control
	kal_sprintf(bsi_dbg_str, "[BSI]%x\n\r", DRV_Reg32(0xBF810818)); // &== 0x800
	tst_sys_trace(bsi_dbg_str);							

	// &== 0x00200020 (SW TURN_ON_BSI_CLK), 0x0 (SW TURN_OFF_BSI_CLK)
	kal_sprintf(bsi_dbg_str, "[BSI]%x\n\r", DRV_Reg32(0xBF81040C));
	tst_sys_trace(bsi_dbg_str);

	// BSISPI
	kal_sprintf(bsi_dbg_str, "[BSI]%x %x %x\n\r", DRV_Reg32(BSISPI_PORT_PARAM_REG), DRV_Reg32(BSISPI_IC0_PARAM1_REG), DRV_Reg32(BSISPI_IC0_PARAM2_REG));
	tst_sys_trace(bsi_dbg_str);

	// BSI
	kal_sprintf(bsi_dbg_str, "[BSI]%x %x %x %x\n\r", DRV_Reg32(BSI_APB2CRF_IMM_CTRL_REG), DRV_Reg32(BSI_APB2CRF_IMM_WDATA_REG), DRV_Reg32(BSI_APB2CRF_IMM_RDINT_REG), DRV_Reg32(BSI_APB2CRF_IMM_RDATA_3100_REG));
	tst_sys_trace(bsi_dbg_str);							

	// BSI
	kal_sprintf(bsi_dbg_str, "[BSI]%x %x %x %x %x\n\r", bsi_enter_leave[(bsi_enter_leave_ptr-5+16)%16], bsi_enter_leave[(bsi_enter_leave_ptr-4+16)%16], bsi_enter_leave[(bsi_enter_leave_ptr-3+16)%16], bsi_enter_leave[(bsi_enter_leave_ptr-2+16)%16], bsi_enter_leave[(bsi_enter_leave_ptr-1+16)%16]);
	tst_sys_trace(bsi_dbg_str);							

	// force on PLL
	kal_sprintf(bsi_dbg_str, "[BSI]%x %x\n\r", DRV_Reg32(0xBF810400), DRV_Reg32(0xBF810004));
	tst_sys_trace(bsi_dbg_str);

	// W/R 0xB6F2D800
	for(i = 0; i < 5; i++)
	{
		DRV_WriteReg32(0xB6F2D800, i);

		kal_sprintf(bsi_dbg_str, "[BSI]%x %x\n\r", i, DRV_Reg32(0xB6F2D800));
		tst_sys_trace(bsi_dbg_str);
	}
#endif
	return;
}
