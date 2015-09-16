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
 *    usbdl_pmic6326.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines functions that PMIC 6326 can support
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features.h"
#include "dcl.h"
#include 	"drv_comm.h"
#include 	"reg_base.h"
#include "i2c_dual_hw.h"
#include "i2c_dual_sw.h"
#include "dcl_pmic_features.h"
#include "dcl_pmu_common_sw.h"
#include "drvpdn.h"

#define CHRDET_MASK						0x1
#define CHRDET_SHIFT						0x5

#if defined(PMIC_6326_REG_API)

#if defined(DRV_I2C_DUAL)

#if defined(MT6268)
#define I2C_BASE		(0x85100000)
#endif // #if defined(MT6268)

#define I2C_DUAL_POWER_ON()		DRV_WriteReg(CG_CLR2, CG_CON2_I2C_DUAL);
#define I2C_DUAL_POWER_OFF()		DRV_WriteReg(CG_SET2, CG_CON2_I2C_DUAL);

volatile kal_uint8 gI2CSampleCount = 0;
volatile kal_uint8 gI2CStepCnt = 1;

kal_bool i2c_init = KAL_FALSE;

#define I2C_POLLING_TIMEOUT		100000
#define PMIC6326_I2C_ID		0xC0
kal_uint32 gI2CPollingTimeout = I2C_POLLING_TIMEOUT;

kal_bool pmic6326_reg_write(kal_uint8 reg, kal_uint8 val){
	register kal_uint32 tmp;
	register kal_uint32 i;
	
	
	if (i2c_init == KAL_FALSE)
	{
		// Set to I2C DUAL mode
		GPIO_ModeSetup(40, 0x01);
		GPIO_ModeSetup(41, 0x01);
		i2c_init = KAL_TRUE;
	}
	
	I2C_DUAL_POWER_ON();

	//  Clear FIFO
	I2C_DUAL_CH1_CLEAR_FIFO(1);
	
	// Clear intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));	

	// Set slave address
	I2C_DUAL_CH1_SET_SLAVE_ADDR(PMIC6326_I2C_ID);

	// Set transfter length
	I2C_DUAL_CH1_SET_TRANSFER_LEN(2, 0);

	//I2C_DUAL_CH1_SET_TIMING(1, 3);
	I2C_DUAL_CH1_SET_TIMING(gI2CSampleCount, gI2CStepCnt);

	// Set transaction length
	I2C_DUAL_CH1_SET_TRANSAC_LEN(1);

	// Set disable direction change
	I2C_DUAL_CH1_SET_DIR_CHANGE(0);
	I2C_DUAL_CH1_SET_RESTART(0);

	// Set disable intr
	I2C_DUAL_CH1_CLR_INTR((I2CD_INTR_MASK_CH1_TRANS_COMP_MASK | I2CD_INTR_MASK_CH1_ACK_ERR_MASK | I2CD_INTR_MASK_CH1_HSNAK_ERR_MASK));

	// Fill data port
	I2C_DUAL_CH1_SET_DATA_PORT(reg);

	// Fill data port
	I2C_DUAL_CH1_SET_DATA_PORT(val);

	// Start transaction
	I2C_DUAL_CH1_SET_START(1);


	i = 0;
	while(1){
		i++;
		tmp = DRV_Reg(I2CD_INTR_STAT);
		if (tmp & I2CD_INTR_STAT_CH1_ACK_ERR_MASK){	// ack err
			ASSERT(0);
		}else if (tmp & I2CD_INTR_STAT_CH1_TRANS_COMP_MASK){	// transaction complete
			break;
		}
		if (i>gI2CPollingTimeout){
			ASSERT(0);
		}
	}

	// Clear all intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));

	I2C_DUAL_POWER_OFF();

	return KAL_TRUE;
}


kal_bool pmic6326_reg_read(kal_uint8 reg, kal_uint8 *pval){
	kal_uint32 tmp;
	kal_uint32 i;
	
	
	if (i2c_init == KAL_FALSE)
	{
		// Set to I2C DUAL mode
		GPIO_ModeSetup(40, 0x01);
		GPIO_ModeSetup(41, 0x01);
		i2c_init = KAL_TRUE;
	}

	I2C_DUAL_POWER_ON();


	// Clear FIFO
	I2C_DUAL_CH1_CLEAR_FIFO(1);

	// Clear intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));

	// Set slave address
	I2C_DUAL_CH1_SET_SLAVE_ADDR(PMIC6326_I2C_ID);

	// Set transfter length
	I2C_DUAL_CH1_SET_TRANSFER_LEN(1, 1);

	//I2C_DUAL_CH1_SET_TIMING(1, 3);
	I2C_DUAL_CH1_SET_TIMING(gI2CSampleCount, gI2CStepCnt);

	// Set transaction length
	I2C_DUAL_CH1_SET_TRANSAC_LEN(2);

	// Set enable direction change, use STOP condition between transfers
	I2C_DUAL_CH1_SET_DIR_CHANGE(1);
	I2C_DUAL_CH1_SET_RESTART(0);

	// Set disable intr
	I2C_DUAL_CH1_CLR_INTR((I2CD_INTR_MASK_CH1_TRANS_COMP_MASK | I2CD_INTR_MASK_CH1_ACK_ERR_MASK | I2CD_INTR_MASK_CH1_HSNAK_ERR_MASK));
	
	// Fill data port
	I2C_DUAL_CH1_SET_DATA_PORT(reg);

	// Start transaction
	I2C_DUAL_CH1_SET_START(1);

	i = 0;
	while(1){
		i++;
		tmp = DRV_Reg(I2CD_INTR_STAT);
		if (tmp & I2CD_INTR_STAT_CH1_ACK_ERR_MASK){	// ack err
			ASSERT(0);
		}else if (tmp & I2CD_INTR_STAT_CH1_TRANS_COMP_MASK){	// transaction complete
			*pval = (kal_uint8)(DRV_Reg(I2CD_CH1_DATA_PORT));
			break;
		}
		if (i>gI2CPollingTimeout){
			ASSERT(0);
		}
	}
	// Clear all intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));

	I2C_DUAL_POWER_OFF();

	return KAL_TRUE;
}

#endif // #if defined(DRV_I2C_DUAL)

kal_bool pmic_chrdet_status(void){
#ifdef  __USB_DOWNLOAD__
	kal_uint8 reg_val;
    pmic6326_reg_read(0x09, &reg_val);
    if (reg_val & (CHRDET_MASK << CHRDET_SHIFT)){
        return KAL_TRUE;
    }else{
        return KAL_FALSE;
    }
#endif // #ifdef  __USB_DOWNLOAD__
	return KAL_FALSE;
}

PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[1];
DCL_UINT16 pmu_parameter_size=0;



DCL_STATUS PMIC6326_control_handler(DCL_HANDLE handle, DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
{
	DCL_UINT16	regVal;
	DCL_UINT32	val;

	switch(cmd)
	{			
		case CHR_GET_CHR_DET_STATUS:
		{
			PMU_CTRL_CHR_GET_CHR_DET_STATUS *pChrCtrl=&(data->rPMUChrGetChrDetStatus);
			pChrCtrl->enable=(DCL_BOOL)pmic_chrdet_status();
		}	
		break;
		default:				
		return STATUS_UNSUPPORTED;
		break;
	}

	return STATUS_OK;

}

extern PMU_CONTROL_HANDLER pmu_control_handler;

void dcl_pmic6326_init(void)
{
	pmu_control_handler=PMIC6326_control_handler;
}


#endif // #if defined(PMIC_6326_REG_API)

