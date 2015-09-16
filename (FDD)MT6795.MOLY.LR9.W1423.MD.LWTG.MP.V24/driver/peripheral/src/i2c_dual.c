/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *    i2c_dual.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the I2D DUAL driver.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
#include "drv_features.h"
#include "kal_public_api.h"
#include "dcl.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "kal_public_defs.h" //MSBB change #include	"stack_config.h"        /*MOD_UART1_HISR,MOD_UART2_HISR*/
#include "eint.h"
#include "bmt.h"
#include "i2c_dual_hw.h"
#include "i2c_dual_sw.h"

#include "drvpdn.h"

#if defined(DRV_I2C_DUAL)

#if defined(MT6575) || defined(MT6577)
#define I2C_DUAL_POWER_ON()         {}
#define I2C_DUAL_POWER_OFF()        {}

#elif defined(MT6268)

#define I2C_DUAL_POWER_ON()         I2C_DUAL_DRV_WriteReg16(CG_CLR2, CG_CON2_I2C_DUAL);
#define I2C_DUAL_POWER_OFF()        I2C_DUAL_DRV_WriteReg16(CG_SET2, CG_CON2_I2C_DUAL);
#endif // End of #if defined(MT6575) || defined(MT6577)

kal_bool I2c_Dual_Start_Already = KAL_FALSE;

///////////////////////////////////////////////////////////////////////////////
// Define to enable debug information of I2C DUAL functions execution info
// 1. The execution sequence(ordering)
// 2. The execution count
// #define I2C_DUAL_INTR_DEBUG

// Define to calculate the I2C transmission period
// The max and min transmission period will be logged
// Only has function in polliong mode
// #define MEASURE_I2C_PERIOD

// Define to force I2C R/W polling mode
#define DEBUG_FORCE_POLLING_MODE

// Define to record I2C R/W Action
#define DEBUG_RECORD_I2C_ACTION

///////////////////////////////////////////////////////////////////////////////
#define I2C_POLLING_TIMEOUT		100000

#if defined(MT6326)
#define PMIC6326_I2C_ID		    0xC0
#elif defined(MT6329)
#define PMIC6329_BANK0_I2C_ID   0xC0
#define PMIC6329_BANK1_I2C_ID   0xC2
#endif // End of #if defined(MT6326)

kal_uint32 gI2CPollingTimeout = I2C_POLLING_TIMEOUT;

///////////////////////////////////////////////////////////////////////////////
#if defined(I2C_DUAL_INTR_DEBUG)
#define I2C_DUAL_FUNC_CH1_LISR						1
#define I2C_DUAL_FUNC_CH1_WRITE_INTR				2
#define I2C_DUAL_FUNC_CH1_WRITE_POLLING			3
#define I2C_DUAL_FUNC_CH1_LISR_WRITE_POLLING		4
#define I2C_DUAL_FUNC_CH1_READ_INTR					5
#define I2C_DUAL_FUNC_CH1_READ_POLLING				6
#define I2C_DUAL_FUNC_CH1_LISR_READ_POLLING		7
#define I2C_DUAL_FUNC_CH2_LISR						8
#define I2C_DUAL_FUNC_CH2_WRITE_INTR				9
#define I2C_DUAL_FUNC_CH2_WRITE_POLLING			10
#define I2C_DUAL_FUNC_CH2_LISR_WRITE_POLLING		11
#define I2C_DUAL_FUNC_CH2_READ_INTR					12
#define I2C_DUAL_FUNC_CH2_READ_POLLING				13
#define I2C_DUAL_FUNC_CH2_LISR_READ_POLLING		14

#define MAX_DEBUG_ENTRY_NUM	500
typedef struct{
	kal_uint8 func_type;		// Indicate which function is running
	kal_uint32 count;			// The count of execution
	kal_uint32 time;			// Indicate the time
	kal_uint8 reg;				// Operating register
}i2cd_intr_debug;
i2cd_intr_debug gI2CDUALDeabugArray[MAX_DEBUG_ENTRY_NUM];
kal_uint32 gI2CDUALDebugIdx;

volatile kal_uint32 gI2CDUALDebugCh1LISRCount;
volatile kal_uint32 gI2CDUALDebugCh1WriteIntrCount;
volatile kal_uint32 gI2CDUALDebugCh1WritePollingCount;
volatile kal_uint32 gI2CDUALDebugCh1LISRWritePollingCount;
volatile kal_uint32 gI2CDUALDebugCh1ReadIntrCount;
volatile kal_uint32 gI2CDUALDebugCh1ReadPollingCount;
volatile kal_uint32 gI2CDUALDebugCh1LISRReadPollingCount;

volatile kal_uint32 gI2CDUALDebugCh2LISRCount;
volatile kal_uint32 gI2CDUALDebugCh2WriteIntrCount;
volatile kal_uint32 gI2CDUALDebugCh2WritePollingCount;
volatile kal_uint32 gI2CDUALDebugCh2LISRWritePollingCount;
volatile kal_uint32 gI2CDUALDebugCh2ReadIntrCount;
volatile kal_uint32 gI2CDUALDebugCh2ReadPollingCount;
volatile kal_uint32 gI2CDUALDebugCh2LISRReadPollingCount;
volatile kal_bool gI2CDUALCheckPrevious = KAL_TRUE;
#endif // #if defined(I2C_DUAL_INTR_DEBUG)

///////////////////////////////////////////////////////////////////////////////
#if defined (MEASURE_I2C_PERIOD)
#define MAX_I2C_PERIOD_STATISTIC_NUM		128
volatile kal_bool gI2CPeriodPerformMeasure = KAL_TRUE;
kal_uint16 I2CPeriodArray[MAX_I2C_PERIOD_STATISTIC_NUM];
kal_uint32 gI2CPeriodIndex = 0;
kal_uint16 I2CPeriodTime1, I2CPeriodTime2;
kal_uint16 I2CPeriodMax = 0x0;
kal_uint16 I2CPeriodMin = 0xFFFF;
#endif // #if defined (MEASURE_I2C_PERIOD)

#if defined(MEASURE_I2C_DUAL_PERIOD)
#include "us_timer.h"               /* For ust_get_current_time() API*/
kal_uint32 i2c_dual_time1 = 0;
kal_uint32 i2c_dual_time2 = 0;
kal_uint32 i2c_dual_time3 = 0;
#endif // End of #if defined(MEASURE_I2C_DUAL_PERIOD)


#if defined(DEBUG_RECORD_I2C_ACTION)
#define MAX_I2C_DUAL_DBG_INFO_SIZE	64
typedef struct{
	kal_uint32		index;
   	kal_uint32      reg;
   	kal_uint32      val;
   	kal_uint32      action;
}DRV_I2C_DUAL_DBG_DATA;

typedef struct{
   DRV_I2C_DUAL_DBG_DATA   dbg_data[MAX_I2C_DUAL_DBG_INFO_SIZE];
   kal_uint16     		   dbg_data_idx;
}DRV_I2C_DUAL_DBG_STRUCT;

DRV_I2C_DUAL_DBG_STRUCT	I2C_DUAL_DBG_INFO_DATA;

typedef enum{
	I2C_DUAL_CLEAR_FIFO = 0,
	I2C_DUAL_CLEAR_INTR_STAT,
	I2C_DUAL_SET_SLAVE_ADDRESS,
	I2C_DUAL_SET_TRANSFER_LENGTH,
	I2C_DUAL_SET_TRANSACTION_LENGTH,
	I2C_DUAL_SET_DIR_CHANGE,
	I2C_DUAL_SET_RESTART,
	I2C_DUAL_DISABLE_INTR,
	I2C_DUAL_FILL_DATA_PORT,
	I2C_DUAL_START_TRANSACTION
}I2C_DUAL_ACTION;
#endif // End of #if defined(DEBUG_RECORD_I2C_ACTION)

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
volatile kal_uint8 *i2c_dual_ch1_buff_ptr;		// I2C DUAL Ch1 read buffer ptr
volatile kal_uint8 i2c_dual_ch1_buff_len;			// I2C DUAL Ch1 read buffer length
volatile kal_bool *i2c_daul_ch1_result_ptr;		// I2C DUAL Ch1 result ptr, I2C DUAL driver will write result to the pointer
volatile kal_uint32 i2c_dual_ch1_in_process;		// Indicate whether Ch1 is busy or NOT
volatile kal_uint32 i2c_dual_ch1_op_count = 0;	// Indicate the current operation has satus update (Complete or Error)

volatile kal_uint8 *i2c_dual_ch2_buff_ptr;		// I2C DUAL Ch2 read buffer ptr
volatile kal_uint8 i2c_dual_ch2_buff_len;			// I2C DUAL Ch2 read buffer length
volatile kal_bool *i2c_daul_ch2_result_ptr;		// I2C DUAL Ch2 result ptr, I2C DUAL driver will write result to the pointer
volatile kal_uint32 i2c_dual_ch2_in_process;		// Indicate whether Ch2 is busy or NOT
volatile kal_uint32 i2c_dual_ch2_op_count = 0;	// Indicate the current operation has satus update (Complete or Error)

// Set speed 100K ==> 15.36MHz/100K = 3 * 25.6 * 2
// Set speed 400K ==> 15.36MHz/400K = 38.4 = 2 * 9.6 * 2
// Set speed 800K ==> 15.36MHz/800K = 19.2 = 2 * 4.8 * 2
// Set speed 1000K ==> 15.36MHz/1000K = 15.36 = 2 * 3.84 * 2
// Set speed 1000K ==> 15.36MHz/2000K = 7.68 = 2 * 1.92 * 2
// Set speed 3840K ==> 15.36MHz/3840K = 4 = 1 * 2 * 2
volatile kal_uint8 gI2CSampleCount = 0;
volatile kal_uint8 gI2CStepCnt = 1;

kal_uint8 I2C_DUAL_POLLING_INTR_STAT(kal_uint32 channel, kal_bool RW)
{
	register kal_uint32 tmp;
	register kal_uint32 i;
    kal_uint8 ret = 0xFF;    
    
	i = 0;
	while(1){
		i++;

#if defined(MT6575_S00)
        if (channel == I2C_DUAL_CHANNEL1)
        {
            tmp = I2C_DUAL_DRV_ReadReg16(I2CD_CH1_START);
            if(tmp == 0)
            {
			    if(RW == I2C_DUAL_READ)
		        {
			        ret = (kal_uint8)(I2C_DUAL_DRV_ReadReg16(I2CD_CH1_DATA_PORT));
		        }
                break;
            }
        }
        else if (channel == I2C_DUAL_CHANNEL2)
        {
            tmp = I2C_DUAL_DRV_ReadReg16(I2CD_CH2_START);
            if(tmp == 0)
            {
			    if(RW == I2C_DUAL_READ)
		        {
			        ret = (kal_uint8)(I2C_DUAL_DRV_ReadReg16(I2CD_CH2_DATA_PORT));
		        }
                break;
            }            
        }
#else
		tmp = I2C_DUAL_DRV_ReadReg16(I2CD_INTR_STAT);

        if (channel == I2C_DUAL_CHANNEL1)
        {
		    if (tmp & I2CD_INTR_STAT_CH1_ACK_ERR_MASK){	// ack err
			    ASSERT(0);
		    }else if (tmp & I2CD_INTR_STAT_CH1_TRANS_COMP_MASK){	// transaction complete
		        if(RW == I2C_DUAL_READ)
		        {
			        ret = (kal_uint8)(I2C_DUAL_DRV_ReadReg16(I2CD_CH1_DATA_PORT));
		        }
			    break;
		    }
        }
        else if (channel == I2C_DUAL_CHANNEL2)
        {
		    if (tmp & I2CD_INTR_STAT_CH2_ACK_ERR_MASK){	// ack err
			    ASSERT(0);
		    }else if (tmp & I2CD_INTR_STAT_CH2_TRANS_COMP_MASK){	// transaction complete
			    if(RW == I2C_DUAL_READ)
		        {
			        ret = (kal_uint8)(I2C_DUAL_DRV_ReadReg16(I2CD_CH2_DATA_PORT));
		        }
			    break;
		    }            
        }
#endif // End of #if defined(MT6575_S00)

		if (i > gI2CPollingTimeout){
			ASSERT(0);
		}
	}
    
    return ret;
}
#if defined(MT6329)
void I2C_DUAL_SET_BANK_SLAVE_ADDR(kal_uint32 bank, kal_uint32 channel)
{   
   switch (bank)
    {
        case PMIC_BANK0:
            {
                if(channel == I2C_DUAL_CHANNEL1)
                {
                    I2C_DUAL_CH1_SET_SLAVE_ADDR(PMIC6329_BANK0_I2C_ID);
                }
                else
                {
                    I2C_DUAL_CH2_SET_SLAVE_ADDR(PMIC6329_BANK0_I2C_ID);                    
#if defined(DEBUG_RECORD_I2C_ACTION)   
                    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].val = PMIC6329_BANK0_I2C_ID;	                 
#endif // End of #if defined(DEBUG_RECORD_I2C_ACTION)
                }
                break;
            }
        case PMIC_BANK1:
            {
                if(channel == I2C_DUAL_CHANNEL1)
                {
                    I2C_DUAL_CH1_SET_SLAVE_ADDR(PMIC6329_BANK1_I2C_ID);
                }
                else
                {
                    I2C_DUAL_CH2_SET_SLAVE_ADDR(PMIC6329_BANK1_I2C_ID);                    
#if defined(DEBUG_RECORD_I2C_ACTION)
					I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].val = PMIC6329_BANK1_I2C_ID;	
#endif // End of #if defined(DEBUG_RECORD_I2C_ACTION)
                }                
                break;
            }
        default:
            {
                ASSERT(0); // No such bank number
                break;
            }
    }
}
#endif // End of #if defined(MT6329)

kal_uint32 I2C_DUAL_GET_FIFO_STAT(kal_uint32 channel)
{
    if(channel == I2C_DUAL_CHANNEL1)
    {
        return I2C_DUAL_DRV_ReadReg16(I2CD_CH1_FIFO_STAT);
    }
    else
    {
        return I2C_DUAL_DRV_ReadReg16(I2CD_CH2_FIFO_STAT);                  
    }
}

#if defined(MT6326)
kal_bool pmic6326_reg_write(kal_uint8 reg, kal_uint8 val)
#elif defined(MT6329)
kal_bool pmic6329_reg_write(kal_uint8 reg, kal_uint8 val, kal_uint32 bank)
#endif // End of #if defined(MT6326)
{
	// kal_query_systemInit() return KAL_TRUE: System is at init phase
	// kal_query_systemInit() return KAL_FALSE: System is NOT at init phase, O.S is running

#if defined(IC_BURNIN_TEST)
	return KAL_TRUE;
#endif // #if defined(IC_BURNIN_TEST)

#if defined(DEBUG_FORCE_POLLING_MODE)
#if defined(MT6326)
	return pmic6326_reg_write_fast(reg, val);
#elif defined(MT6329)
    return pmic6329_reg_write_fast(reg, val, bank);
#endif // End of #if defined(MT6326)

#else

	if (!kal_query_systemInit()){
		if (kal_if_lisr()){
#if defined(I2C_DUAL_INTR_DEBUG)
	        {
        		kal_uint32 savedMask = 0;
        		savedMask = SaveAndSetIRQMask();
        		gI2CDUALDebugCh1LISRWritePollingCount++;

        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].func_type = I2C_DUAL_FUNC_CH1_LISR_WRITE_POLLING;
        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].time = drv_get_current_time();
        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].reg = reg;
        		gI2CDUALDebugIdx ++;
        		gI2CDUALDebugIdx = gI2CDUALDebugIdx % MAX_DEBUG_ENTRY_NUM;
        		RestoreIRQMask(savedMask);
	        }
#endif // #if defined(I2C_DUAL_INTR_DEBUG)
#if defined(MT6326)
		    return pmic6326_reg_write_polling(reg, val);
#elif defined(MT6329)
		    return pmic6329_reg_write_polling(reg, val, bank);
#endif // End of #if defined(MT6329)
		}else{
#if defined(I2C_DUAL_INTR_DEBUG)
	        {
		        kal_uint32 savedMask = 0;
		        savedMask = SaveAndSetIRQMask();
		        gI2CDUALDebugCh1WriteIntrCount++;

		        gI2CDUALDeabugArray[gI2CDUALDebugIdx].func_type = I2C_DUAL_FUNC_CH1_WRITE_INTR;
		        gI2CDUALDeabugArray[gI2CDUALDebugIdx].time = drv_get_current_time();
		        gI2CDUALDeabugArray[gI2CDUALDebugIdx].reg = reg;
		        if (gI2CDUALCheckPrevious){
			        if (gI2CDUALDeabugArray[gI2CDUALDebugIdx-1].func_type == I2C_DUAL_FUNC_CH1_WRITE_INTR){
				        ASSERT(0);
			        }
		        }
		        gI2CDUALDebugIdx ++;
		        gI2CDUALDebugIdx = gI2CDUALDebugIdx % MAX_DEBUG_ENTRY_NUM;
		        RestoreIRQMask(savedMask);
	        }
#endif // #if defined(I2C_DUAL_INTR_DEBUG)
#if defined(MT6326)
			return pmic6326_reg_write_intr(reg, val);
#elif defined(MT6329)
			return pmic6329_reg_write_intr(reg, val, bank);
#endif // End of #if defined(MT6326)
		}
	}else{
#if defined(I2C_DUAL_INTR_DEBUG)
    	{
    		kal_uint32 savedMask = 0;
    		savedMask = SaveAndSetIRQMask();
    		gI2CDUALDebugCh1WritePollingCount++;

    		gI2CDUALDeabugArray[gI2CDUALDebugIdx].func_type = I2C_DUAL_FUNC_CH1_WRITE_POLLING;
    		gI2CDUALDeabugArray[gI2CDUALDebugIdx].time = drv_get_current_time();
    		gI2CDUALDeabugArray[gI2CDUALDebugIdx].reg = reg;
    		gI2CDUALDebugIdx ++;
    		gI2CDUALDebugIdx = gI2CDUALDebugIdx % MAX_DEBUG_ENTRY_NUM;
    		RestoreIRQMask(savedMask);
    	}
#endif // #if defined(I2C_DUAL_INTR_DEBUG)
#if defined(MT6326)
        return pmic6326_reg_write_polling(reg, val);
#elif defined(MT6329)
		return pmic6329_reg_write_polling(reg, val, bank);
#endif // End of #if defined(MT6326)
		
	}
#endif // #if defined(DEBUG_FORCE_POLLING_MODE)    
}

#if defined(MT6326)
kal_bool pmic6326_reg_read(kal_uint8 reg, kal_uint8 *pval)
#elif defined(MT6329)
kal_bool pmic6329_reg_read(kal_uint8 reg, kal_uint8 *pval, kal_uint32 bank)
#endif // End of #if defined(MT6326)
{
	// kal_query_systemInit() return KAL_TRUE: System is at init phase
	// kal_query_systemInit() return KAL_FALSE: System is NOT at init phase, O.S is running

#if defined(IC_BURNIN_TEST)
	return KAL_TRUE;
#endif // #if defined(IC_BURNIN_TEST)

#if defined(DEBUG_FORCE_POLLING_MODE)
#if defined(MT6326)
    return pmic6326_reg_read_fast(reg, pval);
#elif defined(MT6329)
    return pmic6329_reg_read_fast(reg, pval, bank);
#endif // End of #if defined(MT6326)
#else

	if (!kal_query_systemInit()){
		if (kal_if_lisr()){
#if defined(I2C_DUAL_INTR_DEBUG)
        	{
        		kal_uint32 savedMask = 0;
        		savedMask = SaveAndSetIRQMask();
        		gI2CDUALDebugCh1LISRReadPollingCount++;

        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].func_type = I2C_DUAL_FUNC_CH1_LISR_READ_POLLING;
        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].time = drv_get_current_time();
        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].reg = reg;
        		gI2CDUALDebugIdx ++;
        		gI2CDUALDebugIdx = gI2CDUALDebugIdx % MAX_DEBUG_ENTRY_NUM;
        		RestoreIRQMask(savedMask);
        	}
#endif // #if defined(I2C_DUAL_INTR_DEBUG)
#if defined(MT6326)
			return pmic6326_reg_read_polling(reg, pval);
#elif defined(MT6329)
			return pmic6329_reg_read_polling(reg, pval, bank);
#endif // End of #if defined(MT6326)
		}else{
#if defined(I2C_DUAL_INTR_DEBUG)
        	{
        		kal_uint32 savedMask = 0;
        		savedMask = SaveAndSetIRQMask();
        		gI2CDUALDebugCh1ReadIntrCount++;

        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].func_type = I2C_DUAL_FUNC_CH1_READ_INTR;
        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].time = drv_get_current_time();
        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].reg = reg;
        		gI2CDUALDebugIdx ++;
        		gI2CDUALDebugIdx = gI2CDUALDebugIdx % MAX_DEBUG_ENTRY_NUM;
        		RestoreIRQMask(savedMask);
        	}
#endif // #if defined(I2C_DUAL_INTR_DEBUG)
#if defined(MT6326)
			return pmic6326_reg_read_intr(reg, pval);
#elif defined(MT6329)
			return pmic6329_reg_read_intr(reg, pval, bank);
#endif // End of #if defined(MT6326)			
		}
	}else{
#if defined(I2C_DUAL_INTR_DEBUG)
    	{
    		kal_uint32 savedMask = 0;
    		savedMask = SaveAndSetIRQMask();
    		gI2CDUALDebugCh1ReadPollingCount++;

    		gI2CDUALDeabugArray[gI2CDUALDebugIdx].func_type = I2C_DUAL_FUNC_CH1_READ_POLLING;
    		gI2CDUALDeabugArray[gI2CDUALDebugIdx].time = drv_get_current_time();
    		gI2CDUALDeabugArray[gI2CDUALDebugIdx].reg = reg;
    		gI2CDUALDebugIdx ++;
    		gI2CDUALDebugIdx = gI2CDUALDebugIdx % MAX_DEBUG_ENTRY_NUM;
    		RestoreIRQMask(savedMask);
    	}
#endif // #if defined(I2C_DUAL_INTR_DEBUG)
#if defined(MT6326)
		return pmic6326_reg_read_polling(reg, pval);
#elif defined(MT6329)
		return pmic6329_reg_read_polling(reg, pval, bank);
#endif // End of #if defined(MT6326)

	}
#endif // #if defined(DEBUG_FORCE_POLLING_MODE)
}

#if defined(MT6326)
kal_bool pmic6326_ch2_reg_write(kal_uint8 reg, kal_uint8 val)
#elif defined(MT6329)
kal_bool pmic6329_ch2_reg_write(kal_uint8 reg, kal_uint8 val, kal_uint32 bank)
#endif // End of #if defined(MT6326)
{
	// kal_query_systemInit() return KAL_TRUE: System is at init phase
	// kal_query_systemInit() return KAL_FALSE: System is NOT at init phase, O.S is running

#if defined(IC_BURNIN_TEST)
	return KAL_TRUE;
#endif // #if defined(IC_BURNIN_TEST)

#if defined(DEBUG_FORCE_POLLING_MODE)
#if defined(MT6326)
	return pmic6326_ch2_reg_write_fast(reg, val);
#elif defined(MT6329)
	return pmic6329_ch2_reg_write_fast(reg, val, bank);
#endif // End of #if defined(MT6326)

#else

	if (!kal_query_systemInit()){
		if (kal_if_lisr()){
#if defined(I2C_DUAL_INTR_DEBUG)
        	{
        		kal_uint32 savedMask = 0;
        		savedMask = SaveAndSetIRQMask();
        		gI2CDUALDebugCh2LISRWritePollingCount++;

        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].func_type = I2C_DUAL_FUNC_CH2_LISR_WRITE_POLLING;
        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].time = drv_get_current_time();
        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].reg = reg;
        		gI2CDUALDebugIdx ++;
        		gI2CDUALDebugIdx = gI2CDUALDebugIdx % MAX_DEBUG_ENTRY_NUM;
        		RestoreIRQMask(savedMask);
        	}

#endif // #if defined(I2C_DUAL_INTR_DEBUG)
#if defined(MT6326)
			return pmic6326_ch2_reg_write_polling(reg, val);
#elif defined(MT6329)
			return pmic6329_ch2_reg_write_polling(reg, val, bank);
#endif // End of #if defined(MT6326)
		}else{
#if defined(I2C_DUAL_INTR_DEBUG)
        	{
        		kal_uint32 savedMask = 0;
        		savedMask = SaveAndSetIRQMask();
        		gI2CDUALDebugCh2WriteIntrCount++;

        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].func_type = I2C_DUAL_FUNC_CH2_WRITE_INTR;
        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].time = drv_get_current_time();
        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].reg = reg;
        		gI2CDUALDebugIdx ++;
        		gI2CDUALDebugIdx = gI2CDUALDebugIdx % MAX_DEBUG_ENTRY_NUM;
        		RestoreIRQMask(savedMask);
        	}
#endif // #if defined(I2C_DUAL_INTR_DEBUG)
#if defined(MT6326)
			return pmic6326_ch2_reg_write_intr(reg, val);
#elif defined(MT6329)
			return pmic6329_ch2_reg_write_intr(reg, val, bank);
#endif // End of #if defined(MT6326)
		}
	}else{
#if defined(I2C_DUAL_INTR_DEBUG)
    	{
    		kal_uint32 savedMask = 0;
    		savedMask = SaveAndSetIRQMask();
    		gI2CDUALDebugCh2WritePollingCount++;

    		gI2CDUALDeabugArray[gI2CDUALDebugIdx].func_type = I2C_DUAL_FUNC_CH2_WRITE_POLLING;
    		gI2CDUALDeabugArray[gI2CDUALDebugIdx].time = drv_get_current_time();
    		gI2CDUALDeabugArray[gI2CDUALDebugIdx].reg = reg;
    		gI2CDUALDebugIdx ++;
    		gI2CDUALDebugIdx = gI2CDUALDebugIdx % MAX_DEBUG_ENTRY_NUM;
    		RestoreIRQMask(savedMask);
    	}
#endif // #if defined(I2C_DUAL_INTR_DEBUG)
#if defined(MT6326)
		return pmic6326_ch2_reg_write_polling(reg, val);
#elif defined(MT6329)
		return pmic6329_ch2_reg_write_polling(reg, val, bank);
#endif // End of #if defined(MT6326)
	}
#endif // #if defined(DEBUG_FORCE_POLLING_MODE)    
}

#if defined(MT6326)
kal_bool pmic6326_ch2_reg_read(kal_uint8 reg, kal_uint8 *pval)
#elif defined(MT6329)
kal_bool pmic6329_ch2_reg_read(kal_uint8 reg, kal_uint8 *pval, kal_uint32 bank)
#endif // End of #if defined(MT6326)
{
	// kal_query_systemInit() return KAL_TRUE: System is at init phase
	// kal_query_systemInit() return KAL_FALSE: System is NOT at init phase, O.S is running

#if defined(IC_BURNIN_TEST)
	return KAL_TRUE;
#endif // #if defined(IC_BURNIN_TEST)

#if defined(DEBUG_FORCE_POLLING_MODE)
#if defined(MT6326)
	return pmic6326_ch2_reg_read_fast(reg, pval);
#elif defined(MT6329)
	return pmic6329_ch2_reg_read_fast(reg, pval, bank);
#endif // End of #if defined(MT6326)

#else

	if (!kal_query_systemInit()){
		if (kal_if_lisr()){
#if defined(I2C_DUAL_INTR_DEBUG)
        	{
        		kal_uint32 savedMask = 0;
        		savedMask = SaveAndSetIRQMask();
        		gI2CDUALDebugCh2LISRReadPollingCount++;

        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].func_type = I2C_DUAL_FUNC_CH2_LISR_READ_POLLING;
        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].time = drv_get_current_time();
        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].reg = reg;
        		gI2CDUALDebugIdx ++;
        		gI2CDUALDebugIdx = gI2CDUALDebugIdx % MAX_DEBUG_ENTRY_NUM;
        		RestoreIRQMask(savedMask);
        	}
#endif // #if defined(I2C_DUAL_INTR_DEBUG)
#if defined(MT6326)
			return pmic6326_ch2_reg_read_polling(reg, pval);
#elif defined(MT6329)
			return pmic6329_ch2_reg_read_polling(reg, pval, bank);
#endif // End of #if defined(MT6326)
		}else{
#if defined(I2C_DUAL_INTR_DEBUG)
        	{
        		kal_uint32 savedMask = 0;
        		savedMask = SaveAndSetIRQMask();
        		gI2CDUALDebugCh2ReadIntrCount++;

        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].func_type = I2C_DUAL_FUNC_CH2_READ_INTR;
        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].time = drv_get_current_time();
        		gI2CDUALDeabugArray[gI2CDUALDebugIdx].reg = reg;
        		gI2CDUALDebugIdx ++;
        		gI2CDUALDebugIdx = gI2CDUALDebugIdx % MAX_DEBUG_ENTRY_NUM;
        		RestoreIRQMask(savedMask);
        	}
#endif // #if defined(I2C_DUAL_INTR_DEBUG)
#if defined(MT6326)
			return pmic6326_ch2_reg_read_intr(reg, pval);
#elif defined(MT6329)
			return pmic6329_ch2_reg_read_intr(reg, pval, bank);
#endif // End of #if defined(MT6326)
		}
	}else{
#if defined(I2C_DUAL_INTR_DEBUG)
    	{
    		kal_uint32 savedMask = 0;
    		savedMask = SaveAndSetIRQMask();
    		gI2CDUALDebugCh2ReadPollingCount++;

    		gI2CDUALDeabugArray[gI2CDUALDebugIdx].func_type = I2C_DUAL_FUNC_CH2_READ_POLLING;
    		gI2CDUALDeabugArray[gI2CDUALDebugIdx].time = drv_get_current_time();
    		gI2CDUALDeabugArray[gI2CDUALDebugIdx].reg = reg;
    		gI2CDUALDebugIdx ++;
    		gI2CDUALDebugIdx = gI2CDUALDebugIdx % MAX_DEBUG_ENTRY_NUM;
    		RestoreIRQMask(savedMask);
    	}
#endif // #if defined(I2C_DUAL_INTR_DEBUG)
#if defined(MT6326)
		return pmic6326_ch2_reg_read_polling(reg, pval);
#elif defined(MT6329)
		return pmic6329_ch2_reg_read_polling(reg, pval, bank);
#endif // End of #if defined(MT6326)

	}
#endif // #if defined(DEBUG_FORCE_POLLING_MODE)    
}

void i2c_dual_lisr(){
	kal_uint16 intr_stat;
	kal_uint32 savedMask = 0;

	savedMask = SaveAndSetIRQMask();

	// Check ch1
	//intr_stat = *(volatile kal_uint16 *)(I2C_BASE + 0x0C);
	intr_stat = I2C_DUAL_DRV_ReadReg16(I2CD_INTR_STAT);
	if ( intr_stat & (I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_MASK_CH1_HSNAK_ERR_MASK) ){
#if defined(I2C_DUAL_INTR_DEBUG)
    	gI2CDUALDebugCh1LISRCount++;
    	gI2CDUALDeabugArray[gI2CDUALDebugIdx].func_type = I2C_DUAL_FUNC_CH1_LISR;
    	gI2CDUALDeabugArray[gI2CDUALDebugIdx].time = drv_get_current_time();
    	if (gI2CDUALCheckPrevious){
    		if (gI2CDUALDeabugArray[gI2CDUALDebugIdx-1].func_type == I2C_DUAL_FUNC_CH1_LISR){
    			ASSERT(0);
    		}
	    }
	    gI2CDUALDebugIdx ++;
	    gI2CDUALDebugIdx = gI2CDUALDebugIdx % MAX_DEBUG_ENTRY_NUM;
#endif // #if defined(I2C_DUAL_INTR_DEBUG)
		if (i2c_dual_ch1_in_process){
			if (intr_stat & I2CD_INTR_STAT_CH1_ACK_ERR_MASK){	// ack err
				if (i2c_daul_ch1_result_ptr != NULL){
					*i2c_daul_ch1_result_ptr = KAL_FALSE;
				}
				ASSERT(0);
			}else if (intr_stat & I2CD_INTR_STAT_CH1_TRANS_COMP_MASK){	// transaction complete
				if (i2c_dual_ch1_buff_ptr != NULL){
					// Read operation, read data into buffer
					//i2c_dual_ch1_buff_ptr = (kal_uint8)(*(volatile kal_uint16 *)(I2C_BASE + 0x00));
					*i2c_dual_ch1_buff_ptr = (kal_uint8)(I2C_DUAL_DRV_ReadReg16(I2CD_CH1_DATA_PORT));
				}
				if (i2c_daul_ch1_result_ptr != NULL){
					*i2c_daul_ch1_result_ptr = KAL_TRUE;
				}
			}else if (intr_stat & I2CD_INTR_MASK_CH1_HSNAK_ERR_MASK){	// HS NAK error
				// TODO
				if (i2c_daul_ch1_result_ptr != NULL){
					*i2c_daul_ch1_result_ptr = KAL_FALSE;
				}
			}
		}else{
			ASSERT(0);

		}
		i2c_dual_ch1_in_process = 0;
		// Every time when we enter LISR, we increase op count to indicate the last operation is done
		i2c_dual_ch1_op_count ++;
		i2c_daul_ch1_result_ptr = NULL;
		i2c_dual_ch1_buff_ptr = NULL;
		I2C_DUAL_DRV_WriteReg16(I2CD_INTR_STAT, 0x7);	// Clear all intr stat
	}

	// Check ch2
	if ( intr_stat & (I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK) ){
#if defined(I2C_DUAL_INTR_DEBUG)
    	gI2CDUALDebugCh2LISRCount++;
    	gI2CDUALDeabugArray[gI2CDUALDebugIdx].func_type = I2C_DUAL_FUNC_CH2_LISR;
    	gI2CDUALDeabugArray[gI2CDUALDebugIdx].time = drv_get_current_time();
    	gI2CDUALDebugIdx ++;
    	gI2CDUALDebugIdx = gI2CDUALDebugIdx % MAX_DEBUG_ENTRY_NUM;
#endif // #if defined(I2C_DUAL_INTR_DEBUG)
		if (i2c_dual_ch2_in_process){
			if (intr_stat & I2CD_INTR_STAT_CH2_ACK_ERR_MASK){	// ack err
				if (i2c_daul_ch2_result_ptr != NULL){
					*i2c_daul_ch2_result_ptr = KAL_FALSE;
				}
				ASSERT(0);
			}else if (intr_stat & I2CD_INTR_STAT_CH2_TRANS_COMP_MASK){	// transaction complete
				if (i2c_dual_ch2_buff_ptr != NULL){
					// Read operation, read data into buffer
					*i2c_dual_ch2_buff_ptr = (kal_uint8)(I2C_DUAL_DRV_ReadReg16(I2CD_CH2_DATA_PORT));
				}
				if (i2c_daul_ch2_result_ptr != NULL){
					*i2c_daul_ch2_result_ptr = KAL_TRUE;
				}
			}
			I2C_DUAL_DRV_WriteReg16(I2CD_INTR_STAT, (I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK));	// Clear all intr stat
		}else{
			ASSERT(0);
			// I2C_DUAL_DRV_WriteReg16(I2CD_INTR_STAT, (I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK));	// Clear all intr stat
		}
		i2c_dual_ch2_in_process = 0;
		// Every time when we enter LISR, we increase op count to indicate the last operation is done
		i2c_dual_ch2_op_count ++;
		i2c_daul_ch2_result_ptr = NULL;
		i2c_dual_ch2_buff_ptr = NULL;
		I2C_DUAL_DRV_WriteReg16(I2CD_INTR_STAT, 0x30);	// Clear all intr stat
	}

	RestoreIRQMask(savedMask);
#if !defined(DEBUG_FORCE_POLLING_MODE)    
	IRQClearInt(IRQ_I2C_DUAL_CODE);
#endif
}

volatile kal_uint32 gI2CDualCheckCount = 208000;
// I2C DUAL Ch1 ownership check and lock
kal_uint32 i2c_dual_ch1_check_and_lock(){
	kal_uint32 i = 0;
	kal_uint32 savedMask;

	while (i<gI2CDualCheckCount){
		i++;
		savedMask = SaveAndSetIRQMask();
		if (i2c_dual_ch1_in_process == 0){
			return savedMask;
		}
		RestoreIRQMask(savedMask);
	}
	ASSERT(0);
	return 0;
}

kal_uint32 i2c_dual_ch2_check_and_lock(){
	kal_uint32 i = 0;
	kal_uint32 savedMask;

	while (i<gI2CDualCheckCount){
		i++;
		savedMask = SaveAndSetIRQMask();
		if (i2c_dual_ch2_in_process == 0){
			return savedMask;
		}
		RestoreIRQMask(savedMask);
	}
	ASSERT(0);
	return 0;
}

#if defined(MT6575) || defined(MT6577)
#define MAINPLL_CON0    ((volatile kal_uint32 *)(AP_MIX_ABB_base + 0x120))
#define MAINPLL_CON1    ((volatile kal_uint32 *)(AP_MIX_ABB_base + 0x124))

/* Top Clock Generator Register Definition */
#define TOP_CKMUXSEL    ((volatile kal_uint32 *)AP_INFRACFG_base)
#define TOP_CKDIV0      ((volatile kal_uint32 *)(AP_INFRACFG_base + 0x004))

#define WPLL197_FREQ 197000 // 3G PLL frequency is 197Mhz
#define CLKSQ_FREQ   26000  // Default frequency is 26Mhz

kal_uint32 mt6575_get_bus_freq(void)
{
    kal_uint32 fout = 0, fbdiv = 0, fbsel = 0, prediv = 0, postdiv = 0, ckdiv = 0;
    
    if ((*TOP_CKMUXSEL & 0x3) == 0x2) // Using WPLL
        return WPLL197_FREQ;
    
    if ((*TOP_CKMUXSEL & 0x3) == 0x0) // Using CLKSQ
        return CLKSQ_FREQ;
    
    fbdiv = ((*MAINPLL_CON0) & 0x7F00) >> 8;
    
    fbsel = ((*MAINPLL_CON0) & 0x0030) >> 4;
    if (fbsel == 0)
        fbsel = 1;
    else if (fbsel == 1)
        fbsel = 2;
    else
        fbsel = 4;
    
    prediv = ((*MAINPLL_CON0) & 0x00C0) >> 6;
    if (prediv == 0)
        prediv = 1;
    else if (prediv == 1)
        prediv = 2;
    else
        prediv = 4;
    
    postdiv = ((*MAINPLL_CON1) & 0x0030) >> 4;
    if (postdiv == 0)
        postdiv = 1;
    else if (postdiv == 1)
        postdiv = 2;
    else
        postdiv = 4;
    
    fout = CLKSQ_FREQ * (fbdiv + 1) * fbsel / prediv / postdiv; // KHz
    
    ckdiv = ((*TOP_CKDIV0) & 0x00000018) >> 3;
    
    switch (ckdiv)
    {
        case 0:
            fout = fout;     // bus clock will not be divided
            break;
        case 1:
            fout = fout / 4; // bus clock will be divided by 4
            break;
        case 2:
            fout = fout / 5; // bus clock will be divided by 5
            break;
        case 3:
            fout = fout / 6; // bus clock will be divided by 6
            break;
        default:
            break; 
    }
    
    return fout;
}
#endif // End of #if defined(MT6575) || defined(MT6577)

void i2c_dual_set_timing(kal_uint32 channel, kal_uint32 sample_count, kal_uint32 step_count)
{
    if(channel == 1)
    {
        I2C_DUAL_CH1_SET_TIMING(sample_count, step_count);
    }
    else
    {
        I2C_DUAL_CH2_SET_TIMING(sample_count, step_count);
    }
}

void i2c_dual_init(void){
#if defined(MT6268A)
	kal_uint16 tmp;
#endif // #if defined(MT6268A)

#if defined(MT6268A)
	// 1. PDN bit
	// I2C_DUAL bit
	//*(volatile kal_uint16 *)(0x84010000 + 0x328) = 0x2000;
	I2C_DUAL_DRV_WriteReg16((CONFIG_base + 0x328), 0x2000);
	// 2. GPIO mode
	//    SCL: GPIO_29, mode 01, SDA: GPIO_30, mode 01
	//tmp = *(volatile kal_uint16 *)(0x84020000 + 0x1300);
	tmp = I2C_DUAL_DRV_ReadReg16((GPIO_base + 0x1300));
	tmp &= ~(0xF << 10);
	tmp |= (0x5 << 10);
	//*(volatile kal_uint16 *)(0x84020000 + 0x1300) = tmp;
	I2C_DUAL_DRV_WriteReg16((GPIO_base + 0x1300), tmp);
	// 3. I2C BUS pull high
	//tmp = *(volatile kal_uint16 *)(0x84020000 + 0x0240);
	tmp = I2C_DUAL_DRV_ReadReg16((GPIO_base + 0x0240));
	tmp |= 0x6000;		// Enable PULL HIGH?DOWN
	//*(volatile kal_uint16 *)(0x84020000 + 0x0240) = tmp;
	I2C_DUAL_DRV_WriteReg16((GPIO_base + 0x0240), tmp);

	//tmp = *(volatile kal_uint16 *)(0x84020000 + 0x0440);
	tmp = I2C_DUAL_DRV_ReadReg16((GPIO_base + 0x0440));
	tmp |= 0x6000;		// Select PULL HIGH
	//*(volatile kal_uint16 *)(0x84020000 + 0x0440) = tmp;
	I2C_DUAL_DRV_WriteReg16((GPIO_base + 0x0440), tmp);
#else // #if defined(MT6268A)
	// 3. I2C BUS pull high
	// TODO
#endif // #if defined(MT6268A)

#if !defined(DEBUG_FORCE_POLLING_MODE)
	IRQ_Register_LISR(IRQ_I2C_DUAL_CODE, i2c_dual_lisr,"I2C DUAL ISR");
	IRQSensitivity(IRQ_I2C_DUAL_CODE,LEVEL_SENSITIVE);
	IRQUnmask(IRQ_I2C_DUAL_CODE);
#endif    

#if defined(MT6268)
	// Set to I2C DUAL mode
	GPIO_ModeSetup(40, 0x01);
	GPIO_ModeSetup(41, 0x01);
#endif

#if defined(MT6575) || defined(MT6577)
	I2C_DUAL_DRV_ClearBits32(PERISYS_CONFG_base + 0x018, 0x40000000);
    //i2c_v1_set_speed(I2C_CLK_RATE, FS_MODE, MAX_FS_MODE_SPEED);
   //I2C_DUAL_DRV_WriteReg16(I2CD_CH2_TIMING, 0x1103);
#endif

}

#if defined(MT6326)
kal_bool pmic6326_reg_write_intr(kal_uint8 reg, kal_uint8 val){
#endif
#if defined(MT6329)
kal_bool pmic6329_reg_write_intr(kal_uint8 reg, kal_uint8 val, kal_uint32 bank){
#endif // End of #if defined(MT6326)
	register kal_uint32 tmp;
	register kal_uint32 savedMask;
	kal_bool result;

	//savedMask = SaveAndSetIRQMask();
	savedMask = i2c_dual_ch1_check_and_lock();

	// Clear FIFO
	//*(volatile kal_uint16 *)(I2C_BASE + 0x38) = 1;
	//I2C_DUAL_DRV_WriteReg16(I2CD_CH1_FIFO_ADDR_CLR, 0x1);
	I2C_DUAL_CH1_CLEAR_FIFO(1);

	// Clear intr state
	//I2C_DUAL_DRV_WriteReg16(I2CD_INTR_STAT, 0x0037);	// Clear intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));

	// Set slave address
#if defined(MT6326)	
	I2C_DUAL_CH1_SET_SLAVE_ADDR(PMIC6326_I2C_ID);
#elif defined(MT6329)
    I2C_DUAL_SET_BANK_SLAVE_ADDR(bank, I2C_DUAL_CHANNEL1);
#endif // End of #if defined(MT6326)

	// Set transfter length
	//*(volatile kal_uint16 *)(I2C_BASE + 0x14) = 2;
	//I2C_DUAL_DRV_WriteReg16(I2CD_CH1_TRANSFER_LEN, 2);
	I2C_DUAL_CH1_SET_TRANSFER_LEN(2, 0);

	//I2C_DUAL_CH1_SET_TIMING(1, 3);
	I2C_DUAL_CH1_SET_TIMING(gI2CSampleCount, gI2CStepCnt);

	// Set transaction length
	//*(volatile kal_uint16 *)(I2C_BASE + 0x18) = 1;
	//I2C_DUAL_DRV_WriteReg16(I2CD_CH1_TRANSAC_LEN, 1);
	I2C_DUAL_CH1_SET_TRANSAC_LEN(1);

	// Set disable direction change
	//*(volatile kal_uint16 *)(I2C_BASE + 0x10) = 0;
	//tmp = I2C_DUAL_DRV_ReadReg16(I2CD_CH1_CTRL);
	//tmp &= ~I2CD_CH1_CTRL_DIR_CHANGE_MASK;
	//tmp |= I2CD_CH1_CTRL_DIR_CHANGE_MASK;
	//I2C_DUAL_DRV_WriteReg16(I2CD_CH1_CTRL, (kal_uint16)tmp);
	I2C_DUAL_CH1_SET_DIR_CHANGE(0);
	I2C_DUAL_CH1_SET_RESTART(0);

	// Set intr
	//*(volatile kal_uint16 *)(I2C_BASE + 0x08) = 0;
	//tmp = I2C_DUAL_DRV_ReadReg16(I2CD_INTR_MASK);
	//tmp |= I2CD_INTR_MASK_CH1_TRANS_COMP_MASK | I2CD_INTR_MASK_CH1_ACK_ERR_MASK;
	//I2C_DUAL_DRV_WriteReg16(I2CD_INTR_MASK, (kal_uint16)tmp);
	I2C_DUAL_CH1_SET_INTR((I2CD_INTR_MASK_CH1_TRANS_COMP_MASK | I2CD_INTR_MASK_CH1_ACK_ERR_MASK));

	// Fill data port
	//*(volatile kal_uint16 *)(I2C_BASE + 0x00) = reg;
	//I2C_DUAL_DRV_WriteReg16(I2CD_CH1_DATA_PORT, (kal_uint16)reg);
	I2C_DUAL_CH1_SET_DATA_PORT(reg);

	// Fill data port
	//*(volatile kal_uint16 *)(I2C_BASE + 0x00) = val;
	//I2C_DUAL_DRV_WriteReg16(I2CD_CH1_DATA_PORT, (kal_uint16)val);
	I2C_DUAL_CH1_SET_DATA_PORT(val);

	// Start transaction
	//*(volatile kal_uint16 *)(I2C_BASE + 0x24) = 1;
	//I2C_DUAL_DRV_WriteReg16(I2CD_CH1_START, I2CD_CH1_START_START_MASK);
	I2C_DUAL_CH1_SET_START(1);

	i2c_daul_ch1_result_ptr = &result;
	i2c_dual_ch1_in_process = 1;

	tmp = i2c_dual_ch1_op_count;

	RestoreIRQMask(savedMask);

	// Wait until op count is updated ==> Means either operation is completed or there is error
	while (tmp == i2c_dual_ch1_op_count);

	return KAL_TRUE;
}

#if defined(MT6326)
kal_bool pmic6326_reg_read_intr(kal_uint8 reg, kal_uint8 *pval){
#elif defined(MT6329)
kal_bool pmic6329_reg_read_intr(kal_uint8 reg, kal_uint8 *pval, kal_uint32 bank){
#endif // End of #if defined(MT6326)
	kal_uint32 tmp;
	kal_uint32 savedMask;
	kal_bool result;

	//savedMask = SaveAndSetIRQMask();
	savedMask = i2c_dual_ch1_check_and_lock();

	// Clear FIFO
	//*(volatile kal_uint16 *)(I2C_BASE + 0x38) = 1;
	//I2C_DUAL_DRV_WriteReg16(I2CD_CH1_FIFO_ADDR_CLR, 0x1);
	I2C_DUAL_CH1_CLEAR_FIFO(1);

	// Clear intr state
	//I2C_DUAL_DRV_WriteReg16(I2CD_INTR_STAT, 0x0037);	// Clear intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));

	// Set slave address
#if defined(MT6326)	
	I2C_DUAL_CH1_SET_SLAVE_ADDR(PMIC6326_I2C_ID);
#elif defined(MT6329)
    I2C_DUAL_SET_BANK_SLAVE_ADDR(bank, I2C_DUAL_CHANNEL1);
#endif // End of #if defined(MT6326)    

	// Set transfter length
	//*(volatile kal_uint16 *)(I2C_BASE + 0x14) = 1;
	//tmp = I2C_DUAL_DRV_ReadReg16(I2CD_CH1_TRANSFER_LEN);
	//tmp &= ~(I2CD_CH1_TRANSFER_LEN_TRANSFER_LEN_MASK | I2CD_CH1_TRANSFER_LEN_TRANSFER_LEN_AUX_MASK);
	//// Write 1 byte to slave (reg)
	//tmp |= (1 << I2CD_CH1_TRANSFER_LEN_TRANSFER_LEN_SHIFT);
	//// Read 1 byte from slave (val)
	//tmp |= (1 << I2CD_CH1_TRANSFER_LEN_TRANSFER_LEN_AUX_SHIFT);
	//I2C_DUAL_DRV_WriteReg16(I2CD_CH1_TRANSFER_LEN, tmp);
	I2C_DUAL_CH1_SET_TRANSFER_LEN(1, 1);

	//I2C_DUAL_CH1_SET_TIMING(1, 3);
	I2C_DUAL_CH1_SET_TIMING(gI2CSampleCount, gI2CStepCnt);

	// Set transaction length
	//*(volatile kal_uint16 *)(I2C_BASE + 0x18) = 2;
	//I2C_DUAL_DRV_WriteReg16(I2CD_CH1_TRANSAC_LEN, 2);
	I2C_DUAL_CH1_SET_TRANSAC_LEN(2);

	// 6. Set enable direction change, use STOP condition between transfers
	//tmp = I2C_DUAL_DRV_ReadReg16(I2CD_CH1_CTRL);
	//tmp |= I2CD_CH1_CTRL_DIR_CHANGE_MASK;	// Enable direction change
	//tmp &= ~I2CD_CH1_CTRL_RESTART_MASK;		// Use SOPT condition between each transfers
	//tmp |= I2CD_CH1_CTRL_DIR_CHANGE_MASK;
	//I2C_DUAL_DRV_WriteReg16(I2CD_CH1_CTRL, (kal_uint16)tmp);
	I2C_DUAL_CH1_SET_DIR_CHANGE(1);
	I2C_DUAL_CH1_SET_RESTART(0);

	// Set intr
	//*(volatile kal_uint16 *)(I2C_BASE + 0x08) = 0;
	//tmp = I2C_DUAL_DRV_ReadReg16(I2CD_INTR_MASK);
	//tmp |= I2CD_INTR_MASK_CH1_TRANS_COMP_MASK | I2CD_INTR_MASK_CH1_ACK_ERR_MASK;
	//I2C_DUAL_DRV_WriteReg16(I2CD_INTR_MASK, (kal_uint16)tmp);
	I2C_DUAL_CH1_SET_INTR((I2CD_INTR_MASK_CH1_TRANS_COMP_MASK | I2CD_INTR_MASK_CH1_ACK_ERR_MASK));

	// Fill data port
	//*(volatile kal_uint16 *)(I2C_BASE + 0x00) = reg;
	//I2C_DUAL_DRV_WriteReg16(I2CD_CH1_DATA_PORT, (kal_uint16)reg);
	I2C_DUAL_CH1_SET_DATA_PORT(reg);

	// Set read data buffer ptr
	i2c_dual_ch1_buff_ptr = pval;
	i2c_dual_ch1_buff_len = 1;

	//  Start transaction
	//*(volatile kal_uint16 *)(I2C_BASE + 0x24) = 1;
	//I2C_DUAL_DRV_WriteReg16(I2CD_CH1_START, I2CD_CH1_START_START_MASK);
	I2C_DUAL_CH1_SET_START(1);

	i2c_daul_ch1_result_ptr = &result;
	i2c_dual_ch1_in_process = 1;

	tmp = i2c_dual_ch1_op_count;

	RestoreIRQMask(savedMask);

	// Wait until op count is updated ==> Means either operation is completed or there is error
	while (tmp == i2c_dual_ch1_op_count);

	return result;
}


// Polling mode of pmic6326 write
#if defined(MT6326)
kal_bool pmic6326_reg_write_polling(kal_uint8 reg, kal_uint8 val)
#elif defined(MT6329)
kal_bool pmic6329_reg_write_polling(kal_uint8 reg, kal_uint8 val, kal_uint32 bank)
#endif // End of #if defined(MT6326)
{
	register kal_uint32 savedMask;
#if defined(DEBUG_FORCE_POLLING_MODE)
	kal_bool maskIRQ = KAL_FALSE;
#endif // #if defined(DEBUG_FORCE_POLLING_MODE)

	I2C_DUAL_POWER_ON();

	// Get ch1 cs to avoid preemption
	savedMask = i2c_dual_ch1_check_and_lock();
	RestoreIRQMask(savedMask);

#if defined (MEASURE_I2C_PERIOD)
	//I2CPeriodTime1 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
	I2CPeriodTime1 = I2C_DUAL_DRV_ReadReg16((TDMA_base + 0x00));
#endif // #if defined (MEASURE_I2C_PERIOD)

#if defined(DEBUG_FORCE_POLLING_MODE)
	if (!CheckIRQLock()){
		savedMask = SaveAndSetIRQMask();
		maskIRQ = KAL_TRUE;
	}
#endif // #if defined(DEBUG_FORCE_POLLING_MODE)

	//  Clear FIFO
	I2C_DUAL_CH1_CLEAR_FIFO(1);

	// Clear intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));

	// Set slave address
#if defined(MT6326)	
	I2C_DUAL_CH1_SET_SLAVE_ADDR(PMIC6326_I2C_ID);
#elif defined(MT6329)
    I2C_DUAL_SET_BANK_SLAVE_ADDR(bank, I2C_DUAL_CHANNEL1);
#endif // End of #if defined(MT6326) 	

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

    // Polling INTR_STAT
    I2C_DUAL_POLLING_INTR_STAT(I2C_DUAL_CHANNEL1, (kal_bool)I2C_DUAL_WRITE);

	// Clear all intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));

	i2c_dual_ch1_in_process = 0;

#if defined (MEASURE_I2C_PERIOD)
	//I2CPeriodTime2 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
	I2CPeriodTime2 = I2C_DUAL_DRV_ReadReg16((TDMA_base + 0x00));
	if (I2CPeriodTime2>= I2CPeriodTime1){
		I2CPeriodArray[gI2CPeriodIndex] = (I2CPeriodTime2 - I2CPeriodTime1);
	}else{
		I2CPeriodArray[gI2CPeriodIndex] = (0x3FFFF - I2CPeriodTime1 + I2CPeriodTime2);
	}
	if (I2CPeriodArray[gI2CPeriodIndex] > I2CPeriodMax){
		// We only log the values which is smaller than 200
		if (I2CPeriodArray[gI2CPeriodIndex] < 200){
			I2CPeriodMax = I2CPeriodArray[gI2CPeriodIndex];
		}
	}
	if (I2CPeriodArray[gI2CPeriodIndex] < I2CPeriodMin){
		I2CPeriodMin = I2CPeriodArray[gI2CPeriodIndex];
	}
	gI2CPeriodIndex ++;
	gI2CPeriodIndex &= (MAX_I2C_PERIOD_STATISTIC_NUM-1);
#endif // #if defined (MEASURE_I2C_PERIOD)

#if defined(DEBUG_FORCE_POLLING_MODE)
	if (maskIRQ){
		 RestoreIRQMask(savedMask);
	}
#endif // #if defined(DEBUG_FORCE_POLLING_MODE)

	I2C_DUAL_POWER_OFF();

	return KAL_TRUE;
}

// Polling mode of pmic6326 write
#if defined(MT6326)
kal_bool pmic6326_reg_read_polling(kal_uint8 reg, kal_uint8 *pval)
#elif defined(MT6329)
kal_bool pmic6329_reg_read_polling(kal_uint8 reg, kal_uint8 *pval, kal_uint32 bank)
#endif // End of #if defined(MT6326)
{
	kal_uint32 savedMask;
#if defined(DEBUG_FORCE_POLLING_MODE)
	kal_bool maskIRQ = KAL_FALSE;
#endif // #if defined(DEBUG_FORCE_POLLING_MODE)

	I2C_DUAL_POWER_ON();

	// Get ch1 cs to avoid preemption
	savedMask = i2c_dual_ch1_check_and_lock();
	RestoreIRQMask(savedMask);

#if defined (MEASURE_I2C_PERIOD)
	//I2CPeriodTime1 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
	I2CPeriodTime1 = I2C_DUAL_DRV_ReadReg16((TDMA_base + 0x00));
#endif // #if defined (MEASURE_I2C_PERIOD)

#if defined(DEBUG_FORCE_POLLING_MODE)
	if (!CheckIRQLock()){
		savedMask = SaveAndSetIRQMask();
		maskIRQ = KAL_TRUE;
	}
#endif // #if defined(DEBUG_FORCE_POLLING_MODE)

	// Clear FIFO
	I2C_DUAL_CH1_CLEAR_FIFO(1);

	// Clear intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));

	// Set slave address
#if defined(MT6326)	
	I2C_DUAL_CH1_SET_SLAVE_ADDR(PMIC6326_I2C_ID);
#elif defined(MT6329)
    I2C_DUAL_SET_BANK_SLAVE_ADDR(bank, I2C_DUAL_CHANNEL1);
#endif // End of #if defined(MT6326) 		

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

    // Polling INTR_STAT
    *pval = I2C_DUAL_POLLING_INTR_STAT(I2C_DUAL_CHANNEL1, (kal_bool)I2C_DUAL_READ);
    
	// Clear all intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));

	i2c_dual_ch1_in_process = 0;

#if defined (MEASURE_I2C_PERIOD)
	//I2CPeriodTime2 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
	I2CPeriodTime2 = I2C_DUAL_DRV_ReadReg16((TDMA_base + 0x00));
	if (I2CPeriodTime2>= I2CPeriodTime1){
		I2CPeriodArray[gI2CPeriodIndex] = (I2CPeriodTime2 - I2CPeriodTime1);
	}else{
		I2CPeriodArray[gI2CPeriodIndex] = (0x3FFFF - I2CPeriodTime1 + I2CPeriodTime2);
	}
	if (I2CPeriodArray[gI2CPeriodIndex] > I2CPeriodMax){
		// We only log the values which is smaller than 200
		if (I2CPeriodArray[gI2CPeriodIndex] < 200){
			I2CPeriodMax = I2CPeriodArray[gI2CPeriodIndex];
		}
	}
	if (I2CPeriodArray[gI2CPeriodIndex] < I2CPeriodMin){
		I2CPeriodMin = I2CPeriodArray[gI2CPeriodIndex];
	}
	gI2CPeriodIndex ++;
	gI2CPeriodIndex &= (MAX_I2C_PERIOD_STATISTIC_NUM-1);
#endif // #if defined (MEASURE_I2C_PERIOD)

#if defined(DEBUG_FORCE_POLLING_MODE)
	if (maskIRQ){
		 RestoreIRQMask(savedMask);
	}
#endif // #if defined(DEBUG_FORCE_POLLING_MODE)

	I2C_DUAL_POWER_OFF();

	return KAL_TRUE;
}

#if defined(MT6326)
kal_bool pmic6326_ch2_reg_write_intr(kal_uint8 reg, kal_uint8 val)
#elif defined(MT6329)
kal_bool pmic6329_ch2_reg_write_intr(kal_uint8 reg, kal_uint8 val, kal_uint32 bank)
#endif // End of #if defined(MT6326)
{
	register kal_uint32 tmp;
	kal_uint32 savedMask;
	kal_bool result;

	savedMask = i2c_dual_ch2_check_and_lock();

	// Clear FIFO
	I2C_DUAL_CH2_CLEAR_FIFO(1);

	// Clear intr state
	I2C_DUAL_CH2_CLEAR_INTR_STAT(I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK);

	// Set slave address
#if defined(MT6326)	
	I2C_DUAL_CH2_SET_SLAVE_ADDR(PMIC6326_I2C_ID);
#elif defined(MT6329)
    I2C_DUAL_SET_BANK_SLAVE_ADDR(bank, I2C_DUAL_CHANNEL2);
#endif // End of #if defined(MT6326) 		

	// Set transfter length
	I2C_DUAL_CH2_SET_TRANSFER_LEN(2, 0);

	//I2C_DUAL_CH2_SET_TIMING(1, 3);
	I2C_DUAL_CH2_SET_TIMING(gI2CSampleCount, gI2CStepCnt);

	// Set transaction length
	I2C_DUAL_CH2_SET_TRANSAC_LEN(1);

	// Set disable direction change
	I2C_DUAL_CH2_SET_DIR_CHANGE(0);
	I2C_DUAL_CH2_SET_RESTART(0);

	// Set intr
	I2C_DUAL_CH2_SET_INTR((I2CD_INTR_MASK_CH2_TRANS_COMP_MASK | I2CD_INTR_MASK_CH2_ACK_ERR_MASK));

	// Fill data port
	I2C_DUAL_CH2_SET_DATA_PORT(reg);

	// Fill data port
	I2C_DUAL_CH2_SET_DATA_PORT(val);

	// Start transaction
	I2C_DUAL_CH2_SET_START(1);

	i2c_daul_ch2_result_ptr = &result;
	i2c_dual_ch2_in_process = 1;

	tmp = i2c_dual_ch2_op_count;

	RestoreIRQMask(savedMask);

	// Wait until op count is updated ==> Means either operation is completed or there is error
	while (tmp == i2c_dual_ch2_op_count);

	return KAL_TRUE;
}

#if defined(MT6326)
kal_bool pmic6326_ch2_reg_read_intr(kal_uint8 reg, kal_uint8 *pval)
#elif defined(MT6329)
kal_bool pmic6329_ch2_reg_read_intr(kal_uint8 reg, kal_uint8 *pval, kal_uint32 bank)
#endif // End of #if defined(MT6326)
{
	kal_uint32 tmp;
	kal_uint32 savedMask;
	kal_bool result;

	savedMask = i2c_dual_ch2_check_and_lock();

	// Clear FIFO
	I2C_DUAL_CH2_CLEAR_FIFO(1);

	// Clear intr state
	I2C_DUAL_CH2_CLEAR_INTR_STAT(I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK);

	// Set slave address
#if defined(MT6326)	
	I2C_DUAL_CH2_SET_SLAVE_ADDR(PMIC6326_I2C_ID);
#elif defined(MT6329)
    I2C_DUAL_SET_BANK_SLAVE_ADDR(bank, I2C_DUAL_CHANNEL2);
#endif // End of #if defined(MT6326)	

	// Set transfter length
	I2C_DUAL_CH2_SET_TRANSFER_LEN(1, 1);

	//I2C_DUAL_CH2_SET_TIMING(1, 3);
	I2C_DUAL_CH2_SET_TIMING(gI2CSampleCount, gI2CStepCnt);

	// Set transaction length
	I2C_DUAL_CH2_SET_TRANSAC_LEN(2);

	// 6. Set enable direction change, use STOP condition between transfers
	I2C_DUAL_CH2_SET_DIR_CHANGE(1);
	I2C_DUAL_CH2_SET_RESTART(0);

	// Set intr
	I2C_DUAL_CH2_SET_INTR((I2CD_INTR_MASK_CH2_TRANS_COMP_MASK | I2CD_INTR_MASK_CH2_ACK_ERR_MASK));

	// Fill data port
	I2C_DUAL_CH2_SET_DATA_PORT(reg);

	// Set read data buffer ptr
	i2c_dual_ch2_buff_ptr = pval;
	i2c_dual_ch2_buff_len = 1;

	//  Start transaction
	I2C_DUAL_CH2_SET_START(1);

	i2c_daul_ch2_result_ptr = &result;
	i2c_dual_ch2_in_process = 1;

	tmp = i2c_dual_ch2_op_count;

	RestoreIRQMask(savedMask);

	// Wait until op count is updated ==> Means either operation is completed or there is error
	while (tmp == i2c_dual_ch2_op_count);

	return result;
}


// Polling mode of pmic6326 write
#if defined(MT6326)
kal_bool pmic6326_ch2_reg_write_polling(kal_uint8 reg, kal_uint8 val)
#elif defined(MT6329)
kal_bool pmic6329_ch2_reg_write_polling(kal_uint8 reg, kal_uint8 val, kal_uint32 bank)
#endif // End of #if defined(MT6326)
{
	kal_uint32 savedMask;
#if defined(DEBUG_FORCE_POLLING_MODE)
	kal_bool maskIRQ = KAL_FALSE;
#endif // #if defined(DEBUG_FORCE_POLLING_MODE)

	I2C_DUAL_POWER_ON();

	// Get ch2 cs to avoid preemption
	savedMask = i2c_dual_ch2_check_and_lock();
	RestoreIRQMask(savedMask);

#if defined (MEASURE_I2C_PERIOD)
	//I2CPeriodTime1 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
	I2CPeriodTime1 = I2C_DUAL_DRV_ReadReg16((TDMA_base + 0x00));
#endif // #if defined (MEASURE_I2C_PERIOD)

#if defined(DEBUG_FORCE_POLLING_MODE)
	if (!CheckIRQLock()){
		savedMask = SaveAndSetIRQMask();
		maskIRQ = KAL_TRUE;
	}
#endif // #if defined(DEBUG_FORCE_POLLING_MODE)

	//  Clear FIFO
	I2C_DUAL_CH2_CLEAR_FIFO(1);

	// Clear intr stat
	I2C_DUAL_CH2_CLEAR_INTR_STAT(I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK);

	// Set slave address
#if defined(MT6326)	
	I2C_DUAL_CH2_SET_SLAVE_ADDR(PMIC6326_I2C_ID);
#elif defined(MT6329)
    I2C_DUAL_SET_BANK_SLAVE_ADDR(bank, I2C_DUAL_CHANNEL2);
#endif // End of #if defined(MT6326) 		

	// Set transfter length
	I2C_DUAL_CH2_SET_TRANSFER_LEN(2, 0);

	//I2C_DUAL_CH2_SET_TIMING(1, 3);
	I2C_DUAL_CH2_SET_TIMING(gI2CSampleCount, gI2CStepCnt);

	// Set transaction length
	I2C_DUAL_CH2_SET_TRANSAC_LEN(1);

	// Set disable direction change
	I2C_DUAL_CH2_SET_DIR_CHANGE(0);
	I2C_DUAL_CH2_SET_RESTART(0);

	// Set disable intr
	I2C_DUAL_CH2_CLR_INTR((I2CD_INTR_MASK_CH2_TRANS_COMP_MASK | I2CD_INTR_MASK_CH2_ACK_ERR_MASK));

	// Fill data port
	I2C_DUAL_CH2_SET_DATA_PORT(reg);

	// Fill data port
	I2C_DUAL_CH2_SET_DATA_PORT(val);

	// Start transaction
	I2C_DUAL_CH2_SET_START(1);

    // Polling INTR_STAT
    I2C_DUAL_POLLING_INTR_STAT(I2C_DUAL_CHANNEL2, (kal_bool)I2C_DUAL_WRITE);

	// Clear all intr stat
	I2C_DUAL_CH2_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK));

	i2c_dual_ch2_in_process = 0;

#if defined (MEASURE_I2C_PERIOD)
	//I2CPeriodTime2 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
	I2CPeriodTime2 = I2C_DUAL_DRV_ReadReg16((TDMA_base + 0x00));
	if (I2CPeriodTime2>= I2CPeriodTime1){
		I2CPeriodArray[gI2CPeriodIndex] = (I2CPeriodTime2 - I2CPeriodTime1);
	}else{
		I2CPeriodArray[gI2CPeriodIndex] = (0x3FFFF - I2CPeriodTime1 + I2CPeriodTime2);
	}
	if (I2CPeriodArray[gI2CPeriodIndex] > I2CPeriodMax){
		// We only log the values which is smaller than 200
		if (I2CPeriodArray[gI2CPeriodIndex] < 200){
			I2CPeriodMax = I2CPeriodArray[gI2CPeriodIndex];
		}
	}
	if (I2CPeriodArray[gI2CPeriodIndex] < I2CPeriodMin){
		I2CPeriodMin = I2CPeriodArray[gI2CPeriodIndex];
	}
	gI2CPeriodIndex ++;
	gI2CPeriodIndex &= (MAX_I2C_PERIOD_STATISTIC_NUM-1);
#endif // #if defined (MEASURE_I2C_PERIOD)

#if defined(DEBUG_FORCE_POLLING_MODE)
	if (maskIRQ){
		 RestoreIRQMask(savedMask);
	}
#endif // #if defined(DEBUG_FORCE_POLLING_MODE)

	I2C_DUAL_POWER_OFF();

	return KAL_TRUE;
}

// Polling mode of pmic6326 write
#if defined(MT6326)
kal_bool pmic6326_ch2_reg_read_polling(kal_uint8 reg, kal_uint8 *pval)
#elif defined(MT6329)
kal_bool pmic6329_ch2_reg_read_polling(kal_uint8 reg, kal_uint8 *pval, kal_uint32 bank)
#endif // End of #if defined(MT6326)
{
	kal_uint32 savedMask;
#if defined(DEBUG_FORCE_POLLING_MODE)
	kal_bool maskIRQ = KAL_FALSE;
#endif // #if defined(DEBUG_FORCE_POLLING_MODE)

	I2C_DUAL_POWER_ON();

	// Get ch2 cs to avoid preemption
	savedMask = i2c_dual_ch2_check_and_lock();
	RestoreIRQMask(savedMask);

#if defined (MEASURE_I2C_PERIOD)
	//I2CPeriodTime1 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
	I2CPeriodTime1 = I2C_DUAL_DRV_ReadReg16((TDMA_base + 0x00));
#endif // #if defined (MEASURE_I2C_PERIOD)

#if defined(DEBUG_FORCE_POLLING_MODE)
	if (!CheckIRQLock()){
		savedMask = SaveAndSetIRQMask();
		maskIRQ = KAL_TRUE;
	}
#endif // #if defined(DEBUG_FORCE_POLLING_MODE)

	// Clear FIFO
	I2C_DUAL_CH2_CLEAR_FIFO(1);

	// Clear intr stat
	I2C_DUAL_CH2_CLEAR_INTR_STAT(I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK);

	// Set slave address
#if defined(MT6326)	
	I2C_DUAL_CH2_SET_SLAVE_ADDR(PMIC6326_I2C_ID);
#elif defined(MT6329)
    I2C_DUAL_SET_BANK_SLAVE_ADDR(bank, I2C_DUAL_CHANNEL2);
#endif // End of #if defined(MT6326)	

	// Set transfter length
	I2C_DUAL_CH2_SET_TRANSFER_LEN(1, 1);

	//I2C_DUAL_CH2_SET_TIMING(1, 3);
	I2C_DUAL_CH2_SET_TIMING(gI2CSampleCount, gI2CStepCnt);

	// Set transaction length
	I2C_DUAL_CH2_SET_TRANSAC_LEN(2);

	// Set enable direction change, use STOP condition between transfers
	I2C_DUAL_CH2_SET_DIR_CHANGE(1);
	I2C_DUAL_CH2_SET_RESTART(0);

	// Set disable intr
	I2C_DUAL_CH2_CLR_INTR((I2CD_INTR_MASK_CH2_TRANS_COMP_MASK | I2CD_INTR_MASK_CH2_ACK_ERR_MASK));

	// Fill data port
	I2C_DUAL_CH2_SET_DATA_PORT(reg);

	// Start transaction
	I2C_DUAL_CH2_SET_START(1);

    // Polling INTR_STAT
    *pval = I2C_DUAL_POLLING_INTR_STAT(I2C_DUAL_CHANNEL2, (kal_bool)I2C_DUAL_READ);

	// Clear all intr stat
	I2C_DUAL_CH2_CLEAR_INTR_STAT(I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK);

	i2c_dual_ch2_in_process = 0;

#if defined (MEASURE_I2C_PERIOD)
	//I2CPeriodTime2 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
	I2CPeriodTime2 = I2C_DUAL_DRV_ReadReg16((TDMA_base + 0x00));
	if (I2CPeriodTime2>= I2CPeriodTime1){
		I2CPeriodArray[gI2CPeriodIndex] = (I2CPeriodTime2 - I2CPeriodTime1);
	}else{
		I2CPeriodArray[gI2CPeriodIndex] = (0x3FFFF - I2CPeriodTime1 + I2CPeriodTime2);
	}
	if (I2CPeriodArray[gI2CPeriodIndex] > I2CPeriodMax){
		// We only log the values which is smaller than 200
		if (I2CPeriodArray[gI2CPeriodIndex] < 200){
			I2CPeriodMax = I2CPeriodArray[gI2CPeriodIndex];
		}
	}
	if (I2CPeriodArray[gI2CPeriodIndex] < I2CPeriodMin){
		I2CPeriodMin = I2CPeriodArray[gI2CPeriodIndex];
	}
	gI2CPeriodIndex ++;
	gI2CPeriodIndex &= (MAX_I2C_PERIOD_STATISTIC_NUM-1);
#endif // #if defined (MEASURE_I2C_PERIOD)

#if defined(DEBUG_FORCE_POLLING_MODE)
	if (maskIRQ){
		 RestoreIRQMask(savedMask);
	}
#endif // #if defined(DEBUG_FORCE_POLLING_MODE)

	I2C_DUAL_POWER_OFF();

	return KAL_TRUE;
}

// fast mode of pmic6326 write
// Assume IRQ is masked outside the routine
#if defined(MT6326)
kal_bool pmic6326_reg_write_fast(kal_uint8 reg, kal_uint8 val)
#elif defined(MT6329)
kal_bool pmic6329_reg_write_fast(kal_uint8 reg, kal_uint8 val, kal_uint32 bank)
#endif // End of #if defined(MT6326)
{
#if defined (MEASURE_I2C_PERIOD)
	//I2CPeriodTime1 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
	I2CPeriodTime1 = I2C_DUAL_DRV_ReadReg16((TDMA_base + 0x00));
#endif // #if defined (MEASURE_I2C_PERIOD)

	I2C_DUAL_POWER_ON();

	//  Clear FIFO
	I2C_DUAL_CH1_CLEAR_FIFO(1);

	// Clear intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));

	// Set slave address
#if defined(MT6326)	
	I2C_DUAL_CH2_SET_SLAVE_ADDR(PMIC6326_I2C_ID);
#elif defined(MT6329)
    I2C_DUAL_SET_BANK_SLAVE_ADDR(bank, I2C_DUAL_CHANNEL1);
#endif // End of #if defined(MT6326)		

	// Set transfter length
	I2C_DUAL_CH1_SET_TRANSFER_LEN(2, 0);

#if defined(MT6268)
	//I2C_DUAL_CH1_SET_TIMING(1, 3);
	I2C_DUAL_CH1_SET_TIMING(gI2CSampleCount, gI2CStepCnt);
#endif	

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

#if 1//defined(MT6326)
    // Polling INTR_STAT
    I2C_DUAL_POLLING_INTR_STAT(I2C_DUAL_CHANNEL1, (kal_bool)I2C_DUAL_WRITE);
#endif
    
	// Clear all intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));

	i2c_dual_ch1_in_process = 0;

#if defined (MEASURE_I2C_PERIOD)
	if (gI2CPeriodPerformMeasure){
		//I2CPeriodTime2 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
		I2CPeriodTime2 = I2C_DUAL_DRV_ReadReg16((TDMA_base + 0x00));
		if (I2CPeriodTime2>= I2CPeriodTime1){
			I2CPeriodArray[gI2CPeriodIndex] = (I2CPeriodTime2 - I2CPeriodTime1);
		}else{
			I2CPeriodArray[gI2CPeriodIndex] = (0x3FFFF - I2CPeriodTime1 + I2CPeriodTime2);
		}
		if (I2CPeriodArray[gI2CPeriodIndex] > I2CPeriodMax){
			// We only log the values which is smaller than 200
			if (I2CPeriodArray[gI2CPeriodIndex] < 200){
				I2CPeriodMax = I2CPeriodArray[gI2CPeriodIndex];
			}
		}
		if (I2CPeriodArray[gI2CPeriodIndex] < I2CPeriodMin){
			I2CPeriodMin = I2CPeriodArray[gI2CPeriodIndex];
		}
		gI2CPeriodIndex ++;
		gI2CPeriodIndex &= (MAX_I2C_PERIOD_STATISTIC_NUM-1);
	}
#endif // #if defined (MEASURE_I2C_PERIOD)

	I2C_DUAL_POWER_OFF();

	return KAL_TRUE;
}


#if defined(MT6326)
kal_bool pmic6326_reg_read_fast(kal_uint8 reg, kal_uint8 *pval)
#elif defined(MT6329)
kal_bool pmic6329_reg_read_fast(kal_uint8 reg, kal_uint8 *pval, kal_uint32 bank)
#endif // End of #if defined(MT6326)
{
#if defined (MEASURE_I2C_PERIOD)
	//I2CPeriodTime1 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
	I2CPeriodTime1 = I2C_DUAL_DRV_ReadReg16((TDMA_base + 0x00));
#endif // #if defined (MEASURE_I2C_PERIOD)

	I2C_DUAL_POWER_ON();

	// Clear FIFO
	I2C_DUAL_CH1_CLEAR_FIFO(1);

	// Clear intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));

	// Set slave address
#if defined(MT6326)	
	I2C_DUAL_CH1_SET_SLAVE_ADDR(PMIC6326_I2C_ID);
#elif defined(MT6329)
    I2C_DUAL_SET_BANK_SLAVE_ADDR(bank, I2C_DUAL_CHANNEL1);
#endif // End of #if defined(MT6326)		

	// Set transfter length
	I2C_DUAL_CH1_SET_TRANSFER_LEN(1, 1);

#if defined(MT6268)
	//I2C_DUAL_CH1_SET_TIMING(1, 3);
	I2C_DUAL_CH1_SET_TIMING(gI2CSampleCount, gI2CStepCnt);
#endif

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

#if 1//defined(MT6326)
    // Polling INTR_STAT
    *pval = I2C_DUAL_POLLING_INTR_STAT(I2C_DUAL_CHANNEL1, (kal_bool)I2C_DUAL_READ);
#endif    

	// Clear all intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));

	i2c_dual_ch1_in_process = 0;

#if defined (MEASURE_I2C_PERIOD)
	if (gI2CPeriodPerformMeasure){
		//I2CPeriodTime2 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
		I2CPeriodTime2 = I2C_DUAL_DRV_ReadReg16((TDMA_base + 0x00));
		if (I2CPeriodTime2>= I2CPeriodTime1){
			I2CPeriodArray[gI2CPeriodIndex] = (I2CPeriodTime2 - I2CPeriodTime1);
		}else{
			I2CPeriodArray[gI2CPeriodIndex] = (0x3FFFF - I2CPeriodTime1 + I2CPeriodTime2);
		}
		if (I2CPeriodArray[gI2CPeriodIndex] > I2CPeriodMax){
			// We only log the values which is smaller than 200
			if (I2CPeriodArray[gI2CPeriodIndex] < 200){
				I2CPeriodMax = I2CPeriodArray[gI2CPeriodIndex];
			}
		}
		if (I2CPeriodArray[gI2CPeriodIndex] < I2CPeriodMin){
			I2CPeriodMin = I2CPeriodArray[gI2CPeriodIndex];
		}
		gI2CPeriodIndex ++;
		gI2CPeriodIndex &= (MAX_I2C_PERIOD_STATISTIC_NUM-1);
	}
#endif // #if defined (MEASURE_I2C_PERIOD)

	I2C_DUAL_POWER_OFF();

	return KAL_TRUE;
}

// fast mode of pmic6326 write
#if defined(MT6326)
kal_bool pmic6326_ch2_reg_write_fast(kal_uint8 reg, kal_uint8 val)
#elif defined(MT6329)
kal_bool pmic6329_ch2_reg_write_fast(kal_uint8 reg, kal_uint8 val, kal_uint32 bank)
#endif // End of #if defined(MT6326)
{
    //i2c_dual_time2 = ust_get_current_time();    
#if defined (MEASURE_I2C_PERIOD)
	//I2CPeriodTime1 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
	I2CPeriodTime1 = I2C_DUAL_DRV_ReadReg16((TDMA_base + 0x00));
#endif // #if defined (MEASURE_I2C_PERIOD)

	I2C_DUAL_POWER_ON();

#if defined(DEBUG_RECORD_I2C_ACTION)
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].index = I2C_DUAL_DBG_INFO_DATA.dbg_data_idx;	
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].action = I2C_DUAL_CLEAR_FIFO;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].reg = I2CD_CH2_FIFO_ADDR_CLR;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].val = 1;	
	I2C_DUAL_DBG_INFO_DATA.dbg_data_idx++;
#endif // End of #if defined(DEBUG_RECORD_I2C_ACTION)
   	
	//  Clear FIFO
	I2C_DUAL_CH2_CLEAR_FIFO(1);

#if defined(DEBUG_RECORD_I2C_ACTION)
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].index = I2C_DUAL_DBG_INFO_DATA.dbg_data_idx;	
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].action = I2C_DUAL_CLEAR_INTR_STAT;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].reg = I2CD_INTR_STAT;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].val = I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK;	
	I2C_DUAL_DBG_INFO_DATA.dbg_data_idx++;
#endif // End of #if defined(DEBUG_RECORD_I2C_ACTION)
		
#if !defined(MT6575_S00)	
	// Clear intr stat
	I2C_DUAL_CH2_CLEAR_INTR_STAT(I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK);
#endif	

#if defined(DEBUG_RECORD_I2C_ACTION)
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].index = I2C_DUAL_DBG_INFO_DATA.dbg_data_idx;	
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].action = I2C_DUAL_SET_SLAVE_ADDRESS;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].reg = I2CD_CH2_SLAVE_ADDR;
#endif // End of #if defined(DEBUG_RECORD_I2C_ACTION)

	// Set slave address
#if defined(MT6326)	
	I2C_DUAL_CH2_SET_SLAVE_ADDR(PMIC6326_I2C_ID);
#elif defined(MT6329)
    I2C_DUAL_SET_BANK_SLAVE_ADDR(bank, I2C_DUAL_CHANNEL2);
#endif // End of #if defined(MT6326)	

#if defined(DEBUG_RECORD_I2C_ACTION)	
	I2C_DUAL_DBG_INFO_DATA.dbg_data_idx++;    
#endif // End of #if defined(DEBUG_RECORD_I2C_ACTION)

	// Set transfter length
	I2C_DUAL_CH2_SET_TRANSFER_LEN(2, 0);

#if defined(MT6268)
	//I2C_DUAL_CH2_SET_TIMING(1, 3);
	I2C_DUAL_CH2_SET_TIMING(gI2CSampleCount, gI2CStepCnt);
#endif

#if defined(DEBUG_RECORD_I2C_ACTION)	
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].index = I2C_DUAL_DBG_INFO_DATA.dbg_data_idx;	
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].action = I2C_DUAL_SET_TRANSACTION_LENGTH;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].reg = I2CD_CH2_TRANSAC_LEN;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].val = 1;	
	I2C_DUAL_DBG_INFO_DATA.dbg_data_idx++;
#endif // End of #if defined(DEBUG_RECORD_I2C_ACTION)	
		
	// Set transaction length
	I2C_DUAL_CH2_SET_TRANSAC_LEN(1);

#if defined(DEBUG_RECORD_I2C_ACTION)	
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].index = I2C_DUAL_DBG_INFO_DATA.dbg_data_idx;	
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].action = I2C_DUAL_SET_DIR_CHANGE;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].reg = I2CD_CH2_CTRL;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].val = 0;	
	I2C_DUAL_DBG_INFO_DATA.dbg_data_idx++;
#endif // End of #if defined(DEBUG_RECORD_I2C_ACTION)	
	
	// Set disable direction change
	I2C_DUAL_CH2_SET_DIR_CHANGE(0);
	
#if defined(DEBUG_RECORD_I2C_ACTION)
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].index = I2C_DUAL_DBG_INFO_DATA.dbg_data_idx;	
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].action = I2C_DUAL_SET_RESTART;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].reg = I2CD_CH2_CTRL;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].val = 0;	
	I2C_DUAL_DBG_INFO_DATA.dbg_data_idx++;
#endif // End of #if defined(DEBUG_RECORD_I2C_ACTION)
		
	I2C_DUAL_CH2_SET_RESTART(0);

#if defined(DEBUG_RECORD_I2C_ACTION)	
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].index = I2C_DUAL_DBG_INFO_DATA.dbg_data_idx;	
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].action = I2C_DUAL_DISABLE_INTR;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].reg = I2CD_INTR_MASK;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].val = (I2CD_INTR_MASK_CH2_TRANS_COMP_MASK | I2CD_INTR_MASK_CH2_ACK_ERR_MASK);	
	I2C_DUAL_DBG_INFO_DATA.dbg_data_idx++;
#endif // End of #if defined(DEBUG_RECORD_I2C_ACTION)
	
#if !defined(MT6575) && !defined(MT6577)	
	// Set disable intr (MT6575 cannot enable this part due to AP/MD race condition)
	I2C_DUAL_CH2_CLR_INTR((I2CD_INTR_MASK_CH2_TRANS_COMP_MASK | I2CD_INTR_MASK_CH2_ACK_ERR_MASK));
#endif

#if defined(DEBUG_RECORD_I2C_ACTION)	
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].index = I2C_DUAL_DBG_INFO_DATA.dbg_data_idx;	
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].action = I2C_DUAL_FILL_DATA_PORT;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].reg = I2CD_CH2_DATA_PORT;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].val = reg;	
	I2C_DUAL_DBG_INFO_DATA.dbg_data_idx++;
#endif // End of #if defined(DEBUG_RECORD_I2C_ACTION)

	// Fill data port
	I2C_DUAL_CH2_SET_DATA_PORT(reg);

#if defined(DEBUG_RECORD_I2C_ACTION)
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].index = I2C_DUAL_DBG_INFO_DATA.dbg_data_idx;	
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].action = I2C_DUAL_FILL_DATA_PORT;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].reg = I2CD_CH2_DATA_PORT;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].val = val;	
	I2C_DUAL_DBG_INFO_DATA.dbg_data_idx++;
#endif // End of #if defined(DEBUG_RECORD_I2C_ACTION)
	
	// Fill data port
	I2C_DUAL_CH2_SET_DATA_PORT(val);

#if defined(DEBUG_RECORD_I2C_ACTION)
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].index = I2C_DUAL_DBG_INFO_DATA.dbg_data_idx;	
	I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].action = I2C_DUAL_START_TRANSACTION;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].reg = I2CD_CH2_START;
    I2C_DUAL_DBG_INFO_DATA.dbg_data[I2C_DUAL_DBG_INFO_DATA.dbg_data_idx&(MAX_I2C_DUAL_DBG_INFO_SIZE - 1)].val = 1;	
	I2C_DUAL_DBG_INFO_DATA.dbg_data_idx++;    
#endif // End of #if defined(DEBUG_RECORD_I2C_ACTION)
    
	// Start transaction
	I2C_DUAL_CH2_SET_START(1);
    I2c_Dual_Start_Already = KAL_TRUE;    

#if defined(MT6326)
    // Polling INTR_STAT
    I2C_DUAL_POLLING_INTR_STAT(I2C_DUAL_CHANNEL2, (kal_bool)I2C_DUAL_WRITE);

	// Clear all intr stat
	I2C_DUAL_CH2_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK));
#endif

    //i2c_dual_time3 = ust_get_current_time();
	i2c_dual_ch2_in_process = 0;

#if defined (MEASURE_I2C_PERIOD)
	if (gI2CPeriodPerformMeasure){
		//I2CPeriodTime2 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
		I2CPeriodTime2 = I2C_DUAL_DRV_ReadReg16((TDMA_base + 0x00));
		if (I2CPeriodTime2>= I2CPeriodTime1){
			I2CPeriodArray[gI2CPeriodIndex] = (I2CPeriodTime2 - I2CPeriodTime1);
		}else{
			I2CPeriodArray[gI2CPeriodIndex] = (0x3FFFF - I2CPeriodTime1 + I2CPeriodTime2);
		}
		if (I2CPeriodArray[gI2CPeriodIndex] > I2CPeriodMax){
			// We only log the values which is smaller than 200
			if (I2CPeriodArray[gI2CPeriodIndex] < 200){
				I2CPeriodMax = I2CPeriodArray[gI2CPeriodIndex];
			}
		}
		if (I2CPeriodArray[gI2CPeriodIndex] < I2CPeriodMin){
			I2CPeriodMin = I2CPeriodArray[gI2CPeriodIndex];
		}
		gI2CPeriodIndex ++;
		gI2CPeriodIndex &= (MAX_I2C_PERIOD_STATISTIC_NUM-1);
	}
#endif // #if defined (MEASURE_I2C_PERIOD)

	I2C_DUAL_POWER_OFF();

	return KAL_TRUE;
}


#if defined(MT6326)
kal_bool pmic6326_ch2_reg_read_fast(kal_uint8 reg, kal_uint8 *pval)
#elif defined(MT6329)
kal_bool pmic6329_ch2_reg_read_fast(kal_uint8 reg, kal_uint8 *pval, kal_uint32 bank)
#endif // End of #if defined(MT6326)
{
#if defined (MEASURE_I2C_PERIOD)
	//I2CPeriodTime1 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
	I2CPeriodTime1 = I2C_DUAL_DRV_ReadReg16((TDMA_base + 0x00));
#endif // #if defined (MEASURE_I2C_PERIOD)

	I2C_DUAL_POWER_ON();

	// Clear FIFO
	I2C_DUAL_CH2_CLEAR_FIFO(1);

#if !defined(MT6575_S00)
	// Clear intr stat
	I2C_DUAL_CH2_CLEAR_INTR_STAT(I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK);
#endif

	// Set slave address
#if defined(MT6326)	
	I2C_DUAL_CH2_SET_SLAVE_ADDR(PMIC6326_I2C_ID);
#elif defined(MT6329)
    I2C_DUAL_SET_BANK_SLAVE_ADDR(bank, I2C_DUAL_CHANNEL2);
#endif // End of #if defined(MT6326)	

	// Set transfter length
	I2C_DUAL_CH2_SET_TRANSFER_LEN(1, 1);

#if defined(MT6268)
	//I2C_DUAL_CH2_SET_TIMING(1, 3);
	I2C_DUAL_CH2_SET_TIMING(gI2CSampleCount, gI2CStepCnt);
#endif

	// Set transaction length
	I2C_DUAL_CH2_SET_TRANSAC_LEN(2);

	// Set enable direction change, use STOP condition between transfers
	I2C_DUAL_CH2_SET_DIR_CHANGE(1);
	I2C_DUAL_CH2_SET_RESTART(0);

#if !defined(MT6575) && !defined(MT6577)
	// Set disable intr (MT6575 cannot enable this part due to AP/MD race condition)
	I2C_DUAL_CH2_CLR_INTR((I2CD_INTR_MASK_CH2_TRANS_COMP_MASK | I2CD_INTR_MASK_CH2_ACK_ERR_MASK));
#endif	

	// Fill data port
	I2C_DUAL_CH2_SET_DATA_PORT(reg);

	// Start transaction
	I2C_DUAL_CH2_SET_START(1);

    I2c_Dual_Start_Already = KAL_FALSE;    
#if 1//defined(MT6326)
    // Polling INTR_STAT
    *pval = I2C_DUAL_POLLING_INTR_STAT(I2C_DUAL_CHANNEL2, (kal_bool)I2C_DUAL_READ);
#endif

#if !defined(MT6575_S00)
	// Clear all intr stat
	I2C_DUAL_CH2_CLEAR_INTR_STAT(I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK);
#endif

	i2c_dual_ch2_in_process = 0;

#if defined (MEASURE_I2C_PERIOD)
	if (gI2CPeriodPerformMeasure){
		//I2CPeriodTime2 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
		I2CPeriodTime2 = I2C_DUAL_DRV_ReadReg16((TDMA_base + 0x00));
		if (I2CPeriodTime2>= I2CPeriodTime1){
			I2CPeriodArray[gI2CPeriodIndex] = (I2CPeriodTime2 - I2CPeriodTime1);
		}else{
			I2CPeriodArray[gI2CPeriodIndex] = (0x3FFFF - I2CPeriodTime1 + I2CPeriodTime2);
		}
		if (I2CPeriodArray[gI2CPeriodIndex] > I2CPeriodMax){
			// We only log the values which is smaller than 200
			if (I2CPeriodArray[gI2CPeriodIndex] < 200){
				I2CPeriodMax = I2CPeriodArray[gI2CPeriodIndex];
			}
		}
		if (I2CPeriodArray[gI2CPeriodIndex] < I2CPeriodMin){
			I2CPeriodMin = I2CPeriodArray[gI2CPeriodIndex];
		}
		gI2CPeriodIndex ++;
		gI2CPeriodIndex &= (MAX_I2C_PERIOD_STATISTIC_NUM-1);
	}
#endif // #if defined (MEASURE_I2C_PERIOD)

	I2C_DUAL_POWER_OFF();

	return KAL_TRUE;
}

/*-----------------------------------------------------------------------
 * Set I2C Speend interface:    Set internal I2C speed, 
 *                              Goal is that get sample_cnt_div and step_cnt_div
 *   clock: Depends on the current MCU/AHB/APB clock frequency   
 *   mode:  FS_MODE. (fixed setting for stable I2C transaction)
 *   khz:   MAX_FS_MODE_SPEED. (fixed setting for stable I2C transaction) 
 *
 *   Returns: ERROR_CODE
 */
void i2c_v1_set_speed (unsigned long clock, I2C_SPD_MODE mode, unsigned long khz)
{
    unsigned short sample_cnt_div, step_cnt_div;
    unsigned short max_step_cnt_div = (mode == HS_MODE) ? MAX_HS_STEP_CNT_DIV : MAX_STEP_CNT_DIV;
    unsigned long tmp, sclk;
    
    {
        unsigned long diff, min_diff = I2C_CLK_RATE;
        unsigned short sample_div = MAX_SAMPLE_CNT_DIV;
        unsigned short step_div = max_step_cnt_div;
        for (sample_cnt_div = 1; sample_cnt_div <= MAX_SAMPLE_CNT_DIV; sample_cnt_div++) {
        
            for (step_cnt_div = 1; step_cnt_div <= max_step_cnt_div; step_cnt_div++) {
                sclk = (clock >> 1) / (sample_cnt_div * step_cnt_div);
                if (sclk > khz) 
                    continue;
                diff = khz - sclk;
                
                if (diff < min_diff) {
                    min_diff = diff;
                    sample_div = sample_cnt_div;
                    step_div   = step_cnt_div;
                }
            }
        }
        sample_cnt_div = sample_div;
        step_cnt_div   = step_div;
    }

    sclk = clock / (2 * sample_cnt_div * step_cnt_div);

    step_cnt_div--;
    sample_cnt_div--;
    
    tmp  = I2C_DUAL_DRV_ReadReg16(I2CD_CH2_TIMING) & ~((0x7 << 8) | (0x3f << 0));
    tmp  = (sample_cnt_div & 0x7) << 8 | (step_cnt_div & 0x3f) << 0 | tmp;
    I2C_DUAL_DRV_WriteReg16(I2CD_CH2_TIMING, tmp);
}

#if defined(IC_BURNIN_TEST)
// Only used for BTMT load

kal_bool i2c_dual_ch1_write_nocheck(kal_uint8 slave_id, kal_uint8 reg, kal_uint8 val)
{
	register kal_uint32 tmp;
	register kal_uint32 i;
	kal_bool ret = KAL_FALSE;

	I2C_DUAL_POWER_ON();

	//  Clear FIFO
	I2C_DUAL_CH1_CLEAR_FIFO(1);

	// Clear intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));

	// Set slave address
	I2C_DUAL_CH1_SET_SLAVE_ADDR(slave_id);

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
		tmp = I2C_DUAL_DRV_ReadReg16(I2CD_INTR_STAT);
		if (tmp & I2CD_INTR_STAT_CH1_ACK_ERR_MASK){	// ack err
			break;
		}else if (tmp & I2CD_INTR_STAT_CH1_TRANS_COMP_MASK){	// transaction complete
			ret = KAL_TRUE;
			break;
		}
		if (i>200){
			break;
		}
	}

	// Clear all intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));

	i2c_dual_ch1_in_process = 0;

	I2C_DUAL_POWER_OFF();

	return ret;
}

kal_bool i2c_dual_ch2_write_nocheck(kal_uint8 slave_id, kal_uint8 reg, kal_uint8 val)
{
	register kal_uint32 tmp;
	register kal_uint32 i;
	kal_bool ret = KAL_FALSE;

	I2C_DUAL_POWER_ON();

	//  Clear FIFO
	I2C_DUAL_CH2_CLEAR_FIFO(1);

	// Clear intr stat
	I2C_DUAL_CH2_CLEAR_INTR_STAT(I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK);

	// Set slave address
	I2C_DUAL_CH2_SET_SLAVE_ADDR(slave_id);

	// Set transfter length
	I2C_DUAL_CH2_SET_TRANSFER_LEN(2, 0);

	//I2C_DUAL_CH2_SET_TIMING(1, 3);
	I2C_DUAL_CH2_SET_TIMING(gI2CSampleCount, gI2CStepCnt);

	// Set transaction length
	I2C_DUAL_CH2_SET_TRANSAC_LEN(1);

	// Set disable direction change
	I2C_DUAL_CH2_SET_DIR_CHANGE(0);
	I2C_DUAL_CH2_SET_RESTART(0);

	// Set disable intr
	I2C_DUAL_CH2_CLR_INTR((I2CD_INTR_MASK_CH2_TRANS_COMP_MASK | I2CD_INTR_MASK_CH2_ACK_ERR_MASK));

	// Fill data port
	I2C_DUAL_CH2_SET_DATA_PORT(reg);

	// Fill data port
	I2C_DUAL_CH2_SET_DATA_PORT(val);

	// Start transaction
	I2C_DUAL_CH2_SET_START(1);

	i = 0;
	while(1){
		i++;
		tmp = I2C_DUAL_DRV_ReadReg16(I2CD_INTR_STAT);
		if (tmp & I2CD_INTR_STAT_CH2_ACK_ERR_MASK){	// ack err
			break;
		}else if (tmp & I2CD_INTR_STAT_CH2_TRANS_COMP_MASK){	// transaction complete
			ret = KAL_TRUE;
			break;
		}
		if (i>200){
			break;
		}
	}

	// Clear all intr stat
	I2C_DUAL_CH2_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK));

	i2c_dual_ch2_in_process = 0;

	I2C_DUAL_POWER_OFF();

	return KAL_TRUE;
}

#endif // #if defined(IC_BURNIN_TEST)
kal_bool i2c_dual_polling_trans_comp(kal_uint32 channel)
{
    kal_uint8 tmp;
    
    if(I2c_Dual_Start_Already)
    {
        tmp = I2C_DUAL_DRV_ReadReg16(I2CD_INTR_STAT);

        if(channel == I2C_DUAL_CHANNEL1)
        {
            if (tmp & I2CD_INTR_STAT_CH1_ACK_ERR_MASK){	// ack err
                ASSERT(0);
            }else if (tmp & I2CD_INTR_STAT_CH1_TRANS_COMP_MASK){	// transaction complete
                I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK));
                return KAL_TRUE;
            }                
        }
        else
        {
            if (tmp & I2CD_INTR_STAT_CH2_ACK_ERR_MASK){	// ack err
                ASSERT(0);
            }else if (tmp & I2CD_INTR_STAT_CH2_TRANS_COMP_MASK){	// transaction complete
                I2C_DUAL_CH2_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK));
                return KAL_TRUE;
            }                          
        }
    }
    else
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}

#if defined(I2C_DUAL_AP_MD_TEST)
static volatile kal_bool gPMIC6329IRQMasked = KAL_FALSE;
static volatile kal_uint32 gsavedMask;
kal_uint8 pmic6329_test[2];

#define LOCK_PMIC6329_CHECK  {\
    if (CheckIRQLock() == 0xC0){\
        ;\
    }else{\
        if (1){\
            gsavedMask = SaveAndSetIRQMask();\
            gPMIC6329IRQMasked = KAL_TRUE;\
        }\
    }\
}

#define RELEASE_PMIC6329_CHECK {\
    if (gPMIC6329IRQMasked == KAL_TRUE){\
        gPMIC6329IRQMasked = KAL_FALSE;\
        RestoreIRQMask(gsavedMask);\
    }\
}

void i2c_dual_ap_md_test()
{
	// AP Configure
	// pmic6329_ch_reg_read(0x00, &pmic6329_test[0], 0);
	I2C_DUAL_POWER_ON();

	// Clear FIFO
	I2C_DUAL_CH1_CLEAR_FIFO(1);

	// Clear intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));

	// Set slave address
#if defined(MT6326)	
	I2C_DUAL_CH1_SET_SLAVE_ADDR(PMIC6326_I2C_ID);
#elif defined(MT6329)
    I2C_DUAL_SET_BANK_SLAVE_ADDR(0, I2C_DUAL_CHANNEL1);
#endif // End of #if defined(MT6326)		

	// Set transfter length
	I2C_DUAL_CH1_SET_TRANSFER_LEN(1, 1);

#if defined(MT6268)
	//I2C_DUAL_CH1_SET_TIMING(1, 3);
	I2C_DUAL_CH1_SET_TIMING(gI2CSampleCount, gI2CStepCnt);
#endif

	// Set transaction length
	I2C_DUAL_CH1_SET_TRANSAC_LEN(2);

	// Set enable direction change, use STOP condition between transfers
	I2C_DUAL_CH1_SET_DIR_CHANGE(1);
	I2C_DUAL_CH1_SET_RESTART(0);

	// Set disable intr
	I2C_DUAL_CH1_CLR_INTR((I2CD_INTR_MASK_CH1_TRANS_COMP_MASK | I2CD_INTR_MASK_CH1_ACK_ERR_MASK | I2CD_INTR_MASK_CH1_HSNAK_ERR_MASK));

	// Fill data port
	I2C_DUAL_CH1_SET_DATA_PORT(0x00);

	// Start transaction
	// I2C_DUAL_CH1_SET_START(1);
			
	// MD Configure
	// pmic6329_ch2_reg_read(0x01, &pmic6329_test[1], 0);
    LOCK_PMIC6329_CHECK;
    i2c_dual_time1 = ust_get_current_time();
   
	I2C_DUAL_POWER_ON();

	// Clear FIFO
	I2C_DUAL_CH2_CLEAR_FIFO(1);

	// Clear intr stat
	I2C_DUAL_CH2_CLEAR_INTR_STAT(I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK);

	// Set slave address
#if defined(MT6326)	
	I2C_DUAL_CH2_SET_SLAVE_ADDR(PMIC6326_I2C_ID);
#elif defined(MT6329)
    I2C_DUAL_SET_BANK_SLAVE_ADDR(0, I2C_DUAL_CHANNEL2);
#endif // End of #if defined(MT6326)	

	// Set transfter length
	I2C_DUAL_CH2_SET_TRANSFER_LEN(1, 1);

#if defined(MT6268)
	//I2C_DUAL_CH2_SET_TIMING(1, 3);
	I2C_DUAL_CH2_SET_TIMING(gI2CSampleCount, gI2CStepCnt);
#endif

	// Set transaction length
	I2C_DUAL_CH2_SET_TRANSAC_LEN(2);

	// Set enable direction change, use STOP condition between transfers
	I2C_DUAL_CH2_SET_DIR_CHANGE(1);
	I2C_DUAL_CH2_SET_RESTART(0);

	// Set disable intr
	I2C_DUAL_CH2_CLR_INTR((I2CD_INTR_MASK_CH2_TRANS_COMP_MASK | I2CD_INTR_MASK_CH2_ACK_ERR_MASK));

	// Fill data port
	I2C_DUAL_CH2_SET_DATA_PORT(0x01);

	// Start transaction
	I2C_DUAL_CH1_SET_START(1);
	I2C_DUAL_CH2_SET_START(1);
	
	i2c_dual_time2 = ust_get_current_time();
	
    I2c_Dual_Start_Already = KAL_FALSE;    
#if 1//defined(MT6326)
    // Polling INTR_STAT
    pmic6329_test[1] = I2C_DUAL_POLLING_INTR_STAT(I2C_DUAL_CHANNEL2, (kal_bool)I2C_DUAL_READ);
#endif
	i2c_dual_time3 = ust_get_current_time();
	// Clear all intr stat
	I2C_DUAL_CH2_CLEAR_INTR_STAT(I2CD_INTR_STAT_CH2_TRANS_COMP_MASK | I2CD_INTR_STAT_CH2_ACK_ERR_MASK);    
    
    RELEASE_PMIC6329_CHECK;
    
#if 1//defined(MT6326)
    // Polling INTR_STAT
    pmic6329_test[0] = I2C_DUAL_POLLING_INTR_STAT(I2C_DUAL_CHANNEL1, (kal_bool)I2C_DUAL_READ);
#endif    

	// Clear all intr stat
	I2C_DUAL_CH1_CLEAR_INTR_STAT((I2CD_INTR_STAT_CH1_TRANS_COMP_MASK | I2CD_INTR_STAT_CH1_ACK_ERR_MASK | I2CD_INTR_STAT_CH1_HSNAK_ERR_MASK));    
        
}

#endif // End of #if defined(I2C_DUAL_AP_MD_TEST)
// ======= Polling mode I2C Read/Write functions ==============================

//void pmic6326_reg_write(kal_uint8 reg, kal_uint8 val){
//	kal_uint32 i;
//	kal_uint16 tmp;
//
//// TTTTT, i2c_dual_init should be called in pmic_init()
////	i2c_dual_init();
//
//#if defined (MEASURE_I2C_PERIOD)
//	I2CPeriodTime1 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
//#endif // #if defined (MEASURE_I2C_PERIOD)
//
//	// 1. Clear FIFO
//	*(volatile kal_uint16 *)(I2C_BASE + 0x38) = 1;
//	// 2. Set slave address
//	*(volatile kal_uint16 *)(I2C_BASE + 0x04) = PMIC6326_I2C_ID;
//	// 3. Set transfter length
//	*(volatile kal_uint16 *)(I2C_BASE + 0x14) = 2;
//	// 4. Set speed 100K ==> 15.36MHz/100K = 3 * 25.6 * 2
//	*(volatile kal_uint16 *)(I2C_BASE + 0x20) = 0x0219;
//	// 4. Set speed 400K ==> 15.36MHz/400K = 38.4 = 2 * 9.6 * 2
//	//*(volatile kal_uint16 *)(I2C_BASE + 0x20) = 0x0108;
//	// 4. Set speed 800K ==> 15.36MHz/800K = 19.2 = 2 * 4.8 * 2
//	//*(volatile kal_uint16 *)(I2C_BASE + 0x20) = 0x0104;
//	// 5. Set transaction length
//	*(volatile kal_uint16 *)(I2C_BASE + 0x18) = 1;
//	// 6. Set disable direction change
//	*(volatile kal_uint16 *)(I2C_BASE + 0x10) = 0;
//	// 7. Disable intr
//	*(volatile kal_uint16 *)(I2C_BASE + 0x08) = 0;
//	// 8. Fill data port
//	*(volatile kal_uint16 *)(I2C_BASE + 0x00) = reg;
//	// 9. Fill data port
//	*(volatile kal_uint16 *)(I2C_BASE + 0x00) = val;
//	// 10. Start transaction
//	*(volatile kal_uint16 *)(I2C_BASE + 0x24) = 1;
//
//	for (i=0;i<gI2CPollingTimeout;i++){
//		tmp = *(volatile kal_uint16 *)(I2C_BASE + 0x0C);
//		if (tmp & 0x01){
//			// Complete
//			//*(volatile kal_uint16 *)(I2C_BASE + 0x0C) = 0x1;
//			break;
//		}
//		if (tmp & 0x02){
//			// ACK error
//			//*(volatile kal_uint16 *)(I2C_BASE + 0x0C) = 0x2;
//			break;
//		}
//	}
//	if (i == gI2CPollingTimeout){
//		ASSERT(0);
//	}
//	// Write 1 to all bits to clear status no matter complete or error occur
//	*(volatile kal_uint16 *)(I2C_BASE + 0x0C) = 0x7;
//
//
//
//
//#if defined (MEASURE_I2C_PERIOD)
//	I2CPeriodTime2 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
//
//	if (I2CPeriodTime2>= I2CPeriodTime1){
//		I2CPeriodArray[gI2CPeriodIndex] = (I2CPeriodTime2 - I2CPeriodTime1);
//	}else{
//		I2CPeriodArray[gI2CPeriodIndex] = (0x3FFFF - I2CPeriodTime1 + I2CPeriodTime2);
//	}
//	if (I2CPeriodArray[gI2CPeriodIndex] > I2CPeriodMax){
//		// We only log the values which is smaller than 200
//		if (I2CPeriodArray[gI2CPeriodIndex] < 200){
//			I2CPeriodMax = I2CPeriodArray[gI2CPeriodIndex];
//		}
//	}
//	if (I2CPeriodArray[gI2CPeriodIndex] < I2CPeriodMin){
//		I2CPeriodMin = I2CPeriodArray[gI2CPeriodIndex];
//	}
//	gI2CPeriodIndex ++;
// gI2CPeriodIndex &= (MAX_I2C_PERIOD_STATISTIC_NUM-1);
//#endif // #if defined (MEASURE_I2C_PERIOD)
//
//}
//
//kal_uint8 pmic6326_reg_read(kal_uint8 reg){
//	kal_uint32 i;
//	kal_uint16 tmp;
//
//
//// TTTTT, i2c_dual_init should be called in pmic_init()
////	i2c_dual_init();
//
//
//
//#if defined (MEASURE_I2C_PERIOD)
//	I2CPeriodTime1 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
//#endif // #if defined (MEASURE_I2C_PERIOD)
//
//	// 1. Clear FIFO
//	*(volatile kal_uint16 *)(I2C_BASE + 0x38) = 1;
//	// 2. Set slave address
//	*(volatile kal_uint16 *)(I2C_BASE + 0x04) = PMIC6326_I2C_ID;
//	// 3. Set transfter length
//	*(volatile kal_uint16 *)(I2C_BASE + 0x14) = 1;
//	// 4. Set speed 100K ==> 15.36MHz/100K = 3 * 25.6 * 2
//	*(volatile kal_uint16 *)(I2C_BASE + 0x20) = 0x0219;
//	// 4. Set speed 400K ==> 15.36MHz/400K = 38.4 = 2 * 9.6 * 2
//	//*(volatile kal_uint16 *)(I2C_BASE + 0x20) = 0x0108;
//	// 4. Set speed 800K ==> 15.36MHz/800K = 19.2 = 2 * 4.8 * 2
//	//*(volatile kal_uint16 *)(I2C_BASE + 0x20) = 0x0104;
//	// 5. Set transaction length
//	*(volatile kal_uint16 *)(I2C_BASE + 0x18) = 1;
//	// 6. Set disable direction change
//	*(volatile kal_uint16 *)(I2C_BASE + 0x10) = 0;
//	// 7. Disable intr
//	*(volatile kal_uint16 *)(I2C_BASE + 0x08) = 0;
//	// 8. Fill data port
//	*(volatile kal_uint16 *)(I2C_BASE + 0x00) = reg;
//	// 9. Start transaction
//	*(volatile kal_uint16 *)(I2C_BASE + 0x24) = 1;
//
//	for (i=0;i<gI2CPollingTimeout;i++){
//		tmp = *(volatile kal_uint16 *)(I2C_BASE + 0x0C);
//		if (tmp & 0x01){
//			// Complete
//			*(volatile kal_uint16 *)(I2C_BASE + 0x0C) = 0x1;
//			break;
//		}
//		if (tmp & 0x02){
//			// ACK error
//			*(volatile kal_uint16 *)(I2C_BASE + 0x0C) = 0x2;
//			break;
//		}
//	}
//	if (i == gI2CPollingTimeout){
//		ASSERT(0);
//	}
//	// Write 1 to all bits to clear status no matter complete or error occur
//	*(volatile kal_uint16 *)(I2C_BASE + 0x0C) = 0x7;
//
//	// 1. Clear FIFO
//	*(volatile kal_uint16 *)(I2C_BASE + 0x38) = 1;
//	// 2. Set slave address
//	*(volatile kal_uint16 *)(I2C_BASE + 0x04) = (PMIC6326_I2C_ID | 1);
//	// 3. Set transfter length
//	*(volatile kal_uint16 *)(I2C_BASE + 0x14) = 1;
//	// 4. Set speed 100K ==> 15.36MHz/100K = 3 * 25.6 * 2
//	*(volatile kal_uint16 *)(I2C_BASE + 0x20) = 0x0219;
//	// 4. Set speed 400K ==> 15.36MHz/400K = 38.4 = 2 * 9.6 * 2
//	//*(volatile kal_uint16 *)(I2C_BASE + 0x20) = 0x0108;
//	// 4. Set speed 800K ==> 15.36MHz/800K = 19.2 = 2 * 4.8 * 2
//	//*(volatile kal_uint16 *)(I2C_BASE + 0x20) = 0x0104;
//	// 5. Set transaction length
//	*(volatile kal_uint16 *)(I2C_BASE + 0x18) = 1;
//	// 6. Set disable direction change
//	*(volatile kal_uint16 *)(I2C_BASE + 0x10) = 0;
//	// 7. Disable intr
//	*(volatile kal_uint16 *)(I2C_BASE + 0x08) = 0;
//	// 9. Start transaction
//	*(volatile kal_uint16 *)(I2C_BASE + 0x24) = 1;
//
//
//	for (i=0;i<gI2CPollingTimeout;i++){
//		tmp = *(volatile kal_uint16 *)(I2C_BASE + 0x0C);
//		if (tmp & 0x01){
//			// Complete
//			//*(volatile kal_uint16 *)(I2C_BASE + 0x0C) = 0x1;
//			break;
//		}
//		if (tmp & 0x02){
//			// ACK error
//			//*(volatile kal_uint16 *)(I2C_BASE + 0x0C) = 0x2;
//			break;
//		}
//	}
//	if (i == gI2CPollingTimeout){
//		ASSERT(0);
//	}
//	// Write 1 to all bits to clear status no matter complete or error occur
//	*(volatile kal_uint16 *)(I2C_BASE + 0x0C) = 0x7;
//
//#if defined (MEASURE_I2C_PERIOD)
//	I2CPeriodTime2 = *(volatile kal_uint16 *)(TDMA_base + 0x00);
//
//	if (I2CPeriodTime2>= I2CPeriodTime1){
//		I2CPeriodArray[gI2CPeriodIndex] = (I2CPeriodTime2 - I2CPeriodTime1);
//	}else{
//		I2CPeriodArray[gI2CPeriodIndex] = (0x3FFFF - I2CPeriodTime1 + I2CPeriodTime2);
//	}
//	if (I2CPeriodArray[gI2CPeriodIndex] > I2CPeriodMax){
//		// We only log the values which is smaller than 200
//		if (I2CPeriodArray[gI2CPeriodIndex] < 200){
//			I2CPeriodMax = I2CPeriodArray[gI2CPeriodIndex];
//		}
//	}
//	if (I2CPeriodArray[gI2CPeriodIndex] < I2CPeriodMin){
//		I2CPeriodMin = I2CPeriodArray[gI2CPeriodIndex];
//	}
//	gI2CPeriodIndex ++;
//	gI2CPeriodIndex &= (MAX_I2C_PERIOD_STATISTIC_NUM-1);
//#endif // #if defined (MEASURE_I2C_PERIOD)
//
//
//	return *(volatile kal_uint16 *)(I2C_BASE + 0x00);
//
//}

// ======= Polling mode I2C Read/Write functions ==============================

#endif // #if defined(DRV_I2C_DUAL)

