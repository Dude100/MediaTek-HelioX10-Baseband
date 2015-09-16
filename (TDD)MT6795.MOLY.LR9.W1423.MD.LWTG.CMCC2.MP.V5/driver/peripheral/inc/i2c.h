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
 *   sccb_v2.h
 *
 *
 * Description:
 * ------------
 *   SCCB/I2C V2 Driver
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
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __I2C_H__
#define __I2C_H__

#include "drv_features_i2c.h"
#include "dcl_i2c_owner.h"

#if (defined(DRV_I2C_25_SERIES))

#include "drv_comm.h"

#include "kal_general_types.h"
#include "reg_base.h"

#ifdef I2C_V2_DVT
  #if !defined(DRV_I2C_DMA_ENABLED)
    #define DRV_I2C_DMA_ENABLED 	
  #endif // #if !defined(DRV_I2C_DMA_ENABLED)
#endif // #ifdef I2C_V2_DVT


#ifndef __DRV_DEBUG_I2C_REG_READ_WRITE__
#define DRV_I2C_ClearBits16(addr, data)             DRV_ClearBits(addr,data)
#define DRV_I2C_SetBits16(addr, data)               DRV_SetBits(addr,data)
#define DRV_I2C_WriteReg16(addr, data)              DRV_WriteReg(addr, data)
#define DRV_I2C_ReadReg16(addr)                     DRV_Reg(addr)
#define DRV_I2C_SetData16(addr, bitmask, value)     DRV_SetData(addr, bitmask, value)
#else // #ifndef __DRV_DEBUG_PMU_REG_READ_WRITE__
#define DRV_I2C_ClearBits16(addr,data)              DRV_DBG_ClearBits(addr,data)
#define DRV_I2C_SetBits16(addr)                     DRV_DBG_SetBits(addr)
#define DRV_I2C_WriteReg16(addr, data)              DRV_DBG_WriteReg(addr, data)
#define DRV_I2C_ReadReg16(addr)                     DRV_DBG_Reg(addr)
#define DRV_I2C_SetData16(addr, bitmask, value)     DRV_DBG_SetData(addr, bitmask, value)
#endif // #ifndef __DRV_DEBUG_PMU_REG_READ_WRITE__

#define SCCB_MAXIMUM_TRANSACTION_LENGTH 8  // SCCB backward compatible


#if defined(DRV_I2C_CLOCK_RATE_15_360_MHZ)
#define I2C_CLOCK_RATE	15360 //15.36MHz
#elif defined(DRV_I2C_CLOCK_RATE_3_000_MHZ)
#define I2C_CLOCK_RATE	3000 //3.0MHz
#else // #if defined(DRV_I2C_CLOCK_RATE_15_360_MHZ)
#define I2C_CLOCK_RATE	13000 //13MHz
#endif // #if defined(DRV_I2C_CLOCK_RATE_15_360_MHZ)


#if (defined(DRV_I2C_DMA_ENABLED))
#include "dma_hw.h"
  #include "dma_sw.h"
  #if (defined(__DMA_API_V2__))
    #define DRV_I2C_USE_DMA_V2_API	// 76 and later chips are all applied V2 DMA API
  #else 
    #define DRV_I2C_USE_DMA_V1_API	// 35, 38, 39, 53, 68, 36 chips are all applied V1 DMA API
  #endif
#endif // #if (defined(DRV_I2C_DMA_ENABLED))

// Some common structures are defined in sccb.h

typedef enum
{
	I2C_TRANSACTION_COMPLETE,
	I2C_TRANSACTION_FAIL,
	I2C_TRANSACTION_IS_BUSY,
	I2C_TRANSACTION_ACKERR,
	I2C_TRANSACTION_HS_NACKERR,
	I2C_TRANSACTION_SUCCESS,
	I2C_TRANSACTION_TIMEOUT
}I2C_TRANSACTION_RESULT;


typedef enum
{
    I2C_IDLE_STATE = 0,
	I2C_READY_STATE,
	I2C_BUSY_STATE
}I2C_STATE;

/* Transaction mode for new SCCB APIs */
typedef enum
{
	I2C_TRANSACTION_FAST_MODE,
	I2C_TRANSACTION_HIGH_SPEED_MODE
}I2C_TRANSACTION_MODE;

/* Transaction type for batch transaction */
typedef enum
{
	I2C_TRANSACTION_WRITE,
	I2C_TRANSACTION_READ,
	I2C_TRANSACTION_CONT_WRITE,
	I2C_TRANSACTION_CONT_READ,
	I2C_TRANSACTION_WRITE_AND_READ
}I2C_TRANSACTION_TYPE;

typedef struct
{
   kal_uint8 *data;
   kal_uint32 data_len;
}i2c_single_write_struct, i2c_single_read_struct;
/* For I2C_CMD_CONT_WRITE, I2C_CMD_CONT_READ command. */
typedef struct
{
   kal_uint8 *data;
   kal_uint32 data_len;
   kal_uint32 transfer_num;
}i2c_cont_write_struct, i2c_cont_read_struct;
/* For I2C_CMD_WRITE_AND_READ command. */
typedef struct
{
   kal_uint8 *indata;
   kal_uint32 indata_len;
   kal_uint8 *outdata;
   kal_uint32 outdata_len;
}i2c_write_and_read_struct;
/* */
typedef union
{
	i2c_single_write_struct single_write;
  i2c_single_read_struct single_read;
  i2c_cont_write_struct cont_write;
  i2c_cont_write_struct cont_read;
  i2c_write_and_read_struct write_and_read;
}i2c_transaction_data_struct;
/* For I2C_CMD_SINGLE_BATCH command. */
typedef struct
{
   I2C_TRANSACTION_TYPE transaction_type;
   i2c_transaction_data_struct transaction_data;
}i2c_batch_data_struct;

typedef enum
{
#if defined(DRV_I2C_CLOCK_RATE_15_360_MHZ)
	// Module source clock is 15.36Mhz
	I2C_100KB,       //99.74KB
	I2C_200KB,       //196.9KB
	I2C_300KB,       //295.4KB
	I2C_400KB,	      //384.0KB
	/* HS Mode */
	I2C_960KB,       //960.0KB
	I2C_1280KB,      //1280.0KB
	I2C_1536KB,      //1536.0KB
	I2C_1920KB,      //1920.0KB
	I2C_2560KB,      //2560.0KB
	I2C_3840KB       //3840.0KB
#elif defined(DRV_I2C_CLOCK_RATE_3_000_MHZ)
    // Module source clock is 3.0Mhz
    I2C_100KB,       //100.0KB
	I2C_200KB,       //196.9KB
	I2C_400KB,       //384.0KB
	/* HS Mode */
	I2C_750KB,       //750.0KB
	I2C_1500KB       //1500.0KB
#else // #if defined(DRV_I2C_CLOCK_RATE_15_360_MHZ)
	// Module source clock is 13Mhz
	I2C_100KB,       //101.5KB
	I2C_200KB,       //203.1KB
	I2C_300KB,       //295.5KB
	I2C_400KB,       //382.4KB
	/* HS Mode */
	I2C_460KB,       //464.3KB
	I2C_540KB,       //541.7KB
	I2C_650KB,       //650.0KB
	I2C_720KB,       //722.0KB

	I2C_810KB,       //812.5KB
	I2C_930KB,       //928.6KB
	I2C_1100KB,      //1083.3KB
	I2C_1300KB,      //1300.0KB
	I2C_1625KB,      //1625.0KB
	I2C_2150KB,      //2166.6KB
	I2C_3250KB	      //3250.6KB
#endif // #if defined(DRV_I2C_CLOCK_RATE_15_360_MHZ)
}I2C_SPEED_ENUM;

typedef struct
{
	//kal_uint8 sccb_mode; // Transaction mode for existing SCCB APIs

	kal_bool get_handle_wait; //When get handle wait until the I2C is avaliable

	kal_uint8 slave_address;	//the address of the slave device

	kal_uint8 delay_len;	//number of half pulse between transfers in a trasaction

	I2C_TRANSACTION_MODE transaction_mode;	//I2C_TRANSACTION_FAST_MODE or I2C_TRANSACTION_HIGH_SPEED_MODE

	kal_uint16 Fast_Mode_Speed;	//The speed of I2C fast mode(Kb)

	kal_uint16 HS_Mode_Speed;	//The speed of I2C high speed mode(Kb)

	#if (defined(DRV_I2C_DMA_ENABLED))
	kal_bool	is_DMA_enabled;	//Transaction via DMA instead of 8-byte FIFO
	#endif // #if (defined(DRV_I2C_DMA_ENABLED))

}i2c_config_struct;

typedef struct
{
	i2c_config_struct  i2c_config;

	kal_uint8 fs_sample_cnt_div;     //these two parameters are used to specify I2C clock rate
	kal_uint8 fs_step_cnt_div;       //half pulse width=step_cnt_div*sample_cnt_div*(1/13Mhz)

	kal_uint8 hs_sample_cnt_div;     //these two parameters are used to specify I2C clock rate
	kal_uint8 hs_step_cnt_div;       //half pulse width=step_cnt_div*sample_cnt_div*(1/13Mhz)

	I2C_TRANSACTION_RESULT transaction_result; /* The result of the end of transaction
	                                               (I2C_TRANSACTION_COMPLETE|I2C_TRANSACTION_FAIL) */

}i2c_handle_struct;

typedef struct
{
	volatile I2C_STATE  state;
	DCL_I2C_OWNER	    owner;

	kal_uint8	number_of_read;
	kal_uint8*	read_buffer;

	#if (defined(DRV_I2C_DMA_ENABLED))
	kal_bool	is_DMA_enabled;
	#endif // #if (defined(DRV_I2C_DMA_ENABLED))

}i2c_status_struct;



#ifndef DRV_I2C_OFF
/* Register Definitions */
#define REG_I2C_DATA_PORT             (I2C_base + 0x00)
#define REG_I2C_SLAVE_ADDR            (I2C_base + 0x04)
#define REG_I2C_INT_MASK              (I2C_base + 0x08)
#define REG_I2C_INT_STA               (I2C_base + 0x0c)
#define REG_I2C_CONTROL               (I2C_base + 0x10)
#define REG_I2C_TRANSFER_LEN          (I2C_base + 0x14)
#define REG_I2C_TRANSAC_LEN           (I2C_base + 0x18)
#define REG_I2C_DELAY_LEN             (I2C_base + 0x1c)
#define REG_I2C_TIMING                (I2C_base + 0x20)
#define REG_I2C_START                 (I2C_base + 0x24)
#define REG_I2C_FIFO_STAT             (I2C_base + 0x30)
#define REG_I2C_FIFO_THRESH           (I2C_base + 0x34)
#define REG_I2C_FIFO_ADDR_CLR         (I2C_base + 0x38)
#define REG_I2C_IO_CONFIG             (I2C_base + 0x40)
#define REG_I2C_MULTI_MASTER          (I2C_base + 0x44)
#define REG_I2C_HS_MODE               (I2C_base + 0x48)
#define REG_I2C_SOFTRESET             (I2C_base + 0x50)
#define REG_I2C_TRANSFER_LEN_AUX      (I2C_base + 0x6C)     ///new from MT6256E2
#define REG_I2C_HW_Version            (I2C_base + 0x78)
#define REG_I2C_DBG_STA               (I2C_base + 0x64)     //only for debug
#define REG_I2C_TIMEOUT_TIMING        (I2C_base + 0x74)     //timeout timing reg
#endif //  DRV_I2C_OFF

/* Register masks */
#define I2C_1_BIT_MASK                0x01
#define I2C_3_BIT_MASK                0x07
#define I2C_4_BIT_MASK                0x0f
#define I2C_6_BIT_MASK                0x3f
#define I2C_8_BIT_MASK                0xff
#define I2C_16_BIT_MASK               0xffff

#define I2C_RX_FIFO_THRESH_MASK       0x0007
#define I2C_RX_FIFO_THRESH_SHIFT      0
#define I2C_TX_FIFO_THRESH_MASK       0x0700
#define I2C_TX_FIFO_THRESH_SHIFT      8

#define I2C_AUX_LEN_MASK              0x1f00
#define I2C_AUX_LEN_SHIFT             8

#define I2C_SAMPLE_CNT_DIV_MASK       0x0700
#define I2C_SAMPLE_CNT_DIV_SHIFT      8
#define I2C_DATA_READ_TIME_MASK       0x7000
#define I2C_DATA_READ_TIME_SHIFT      12

#define I2C_MASTER_READ               0x01
#define I2C_MASTER_WRITE              0x00

//#define I2C_CTL_MODE_BIT            0x01
#define I2C_CTL_RS_STOP_BIT           0x02
#define I2C_CTL_DMA_EN_BIT            0x04
#define I2C_CTL_CLK_EXT_EN_BIT        0x08
#define I2C_CTL_DIR_CHANGE_BIT        0x10
#define I2C_CTL_ACK_ERR_DET_BIT       0x20
#define I2C_CTL_TRANSFER_LEN_CHG_BIT  0x40

#define I2C_DATA_READ_ADJ_BIT         0x8000

#define I2C_SCL_MODE_BIT              0x01
#define I2C_SDA_MODE_BIT              0x02
#define I2C_BUS_DETECT_EN_BIT         0x04

#define I2C_ARBITRATION_BIT           0x01
#define I2C_CLOCK_SYNC_BIT            0x02
#define I2C_BUS_BUSY_DET_BIT          0x04

#define I2C_HS_EN_BIT                 0x01
#define I2C_HS_NACK_ERR_DET_EN_BIT    0x02
#define I2C_HS_MASTER_CODE_MASK       0x0070
#define I2C_HS_MASTER_CODE_SHIFT      4
#define I2C_HS_STEP_CNT_DIV_MASK      0x0700
#define I2C_HS_STEP_CNT_DIV_SHIFT     8
#define I2C_HS_SAMPLE_CNT_DIV_MASK    0x7000
#define I2C_HS_SAMPLE_CNT_DIV_SHIFT   12

/* I2C Status */
#define I2C_FIFO_FULL_STATUS          0x01
#define I2C_FIFO_EMPTY_STATUS         0x02

/* Register Settings */
#define SET_I2C_SLAVE_ADDRESS(n,rw)       do{DRV_I2C_SetData16(REG_I2C_SLAVE_ADDR, I2C_8_BIT_MASK, (((n>>1)<<1) + rw));} while(0);

#define DISABLE_I2C_INT                   do{DRV_I2C_WriteReg16(REG_I2C_INT_MASK, 0);} while(0);
#define ENABLE_I2C_INT                    do{DRV_I2C_WriteReg16(REG_I2C_INT_MASK,I2C_1_BIT_MASK);} while(0);

#define CLEAR_I2C_STA                     do{DRV_I2C_WriteReg16(REG_I2C_INT_STA, I2C_4_BIT_MASK);} while(0);

//#define SET_I2C_FAST_SPEED_MODE	REG_I2C_CONTROL &= ~I2C_CTL_MODE_BIT;
//#define SET_I2C_HIGH_SPEED_MODE	REG_I2C_CONTROL |= I2C_CTL_MODE_BIT;

#define SET_I2C_ST_BETWEEN_TRANSFER       do{DRV_I2C_ClearBits16(REG_I2C_CONTROL, I2C_CTL_RS_STOP_BIT);} while(0);
#define SET_I2C_RS_BETWEEN_TRANSFER       do{DRV_I2C_SetBits16(REG_I2C_CONTROL, I2C_CTL_RS_STOP_BIT);} while(0);
#define ENABLE_I2C_DMA_TRANSFER           do{DRV_I2C_SetBits16(REG_I2C_CONTROL, I2C_CTL_DMA_EN_BIT);} while(0);
#define ENABLE_I2C_CLOCK_EXTENSION        do{DRV_I2C_SetBits16(REG_I2C_CONTROL, I2C_CTL_CLK_EXT_EN_BIT);} while(0);
#define ENABLE_I2C_DIR_CHANGE             do{DRV_I2C_SetBits16(REG_I2C_CONTROL, I2C_CTL_DIR_CHANGE_BIT);} while(0);
#define ENABLE_I2C_ACK_ERR_DET            do{DRV_I2C_SetBits16(REG_I2C_CONTROL, I2C_CTL_ACK_ERR_DET_BIT);} while(0);
#define ENABLE_I2C_TRANSFER_LEN_CHG       do{DRV_I2C_SetBits16(REG_I2C_CONTROL, I2C_CTL_TRANSFER_LEN_CHG_BIT);} while(0);
#define ENABLE_I2C_BUS_BUSY_RESET         do{DRV_I2C_SetBits16(REG_I2C_CONTROL, 0x80);} while(0);
#define ENABLE_I2C_TIMEOUT                do{DRV_I2C_SetBits16(REG_I2C_CONTROL, I2C_TIMEOUT);} while(0); 

#define DISABLE_I2C_DMA_TRANSFER          do{DRV_I2C_ClearBits16(REG_I2C_CONTROL, I2C_CTL_DMA_EN_BIT);} while(0);
#define DISABLE_I2C_CLOCK_EXTENSION       do{DRV_I2C_ClearBits16(REG_I2C_CONTROL, I2C_CTL_CLK_EXT_EN_BIT);} while(0);
#define DISABLE_I2C_DIR_CHANGE            do{DRV_I2C_ClearBits16(REG_I2C_CONTROL, I2C_CTL_DIR_CHANGE_BIT);} while(0);
#define DISABLE_I2C_ACK_ERR_DET           do{DRV_I2C_ClearBits16(REG_I2C_CONTROL, I2C_CTL_ACK_ERR_DET_BIT);} while(0);
#define DISABLE_I2C_TRANSFER_LEN_CHG      do{DRV_I2C_ClearBits16(REG_I2C_CONTROL, I2C_CTL_TRANSFER_LEN_CHG_BIT);} while(0);
#define DISABLE_I2C_BUS_BUSY_RESET        do{DRV_I2C_ClearBits16(REG_I2C_CONTROL, 0x80);} while(0);
#define DISABLE_I2C_TIMEOUT               do{DRV_I2C_ClearBits16(REG_I2C_CONTROL, I2C_TIMEOUT);} while(0); 

#ifdef DRV_I2C_MAX_65535_TRANSFER_LENGTH
#define SET_I2C_TRANSFER_LENGTH(n)        do{DRV_I2C_SetData16(REG_I2C_TRANSFER_LEN, I2C_16_BIT_MASK, (n));} while(0);
#define SET_I2C_AUX_TRANSFER_LENGTH(n)    do{DRV_I2C_SetData16(REG_I2C_TRANSFER_LEN_AUX, I2C_16_BIT_MASK, (n));} while(0);
#else
#define SET_I2C_TRANSFER_LENGTH(n)        do{DRV_I2C_SetData16(REG_I2C_TRANSFER_LEN, I2C_8_BIT_MASK, (n));} while(0);
#define SET_I2C_AUX_TRANSFER_LENGTH(n)    do{DRV_I2C_SetData16(REG_I2C_TRANSFER_LEN, I2C_AUX_LEN_MASK, ((n)<<I2C_AUX_LEN_SHIFT));} while(0);
#endif

#define SET_I2C_TRANSACTION_LENGTH(n)     do{DRV_I2C_SetData16(REG_I2C_TRANSAC_LEN, I2C_8_BIT_MASK, (n));} while(0);
#define SET_I2C_DELAY_LENGTH(n)           do{DRV_I2C_SetData16(REG_I2C_DELAY_LEN, I2C_8_BIT_MASK, (n));} while(0);

#define SET_I2C_STEP_CNT_DIV(n)           do{DRV_I2C_SetData16(REG_I2C_TIMING, I2C_6_BIT_MASK, (n));} while(0);
#define SET_I2C_SAMPLE_CNT_DIV(n)         do{DRV_I2C_SetData16(REG_I2C_TIMING, I2C_SAMPLE_CNT_DIV_MASK, ((n)<<I2C_SAMPLE_CNT_DIV_SHIFT));} while(0);
#define SET_I2C_DATA_READ_TIME(n)         do{DRV_I2C_SetData16(REG_I2C_TIMING, I2C_DATA_READ_TIME_MASK, ((n)<<I2C_DATA_READ_TIME_SHIFT));} while(0);
#define ENABLE_I2C_DATA_READ_ADJ          do{DRV_I2C_SetBits16(REG_I2C_TIMING, I2C_DATA_READ_ADJ_BIT);} while(0);
#define DISABLE_I2C_DATA_READ_ADJ         do{DRV_I2C_ClearBits16(REG_I2C_TIMING, I2C_DATA_READ_ADJ_BIT);} while(0);

#define START_I2C_TRANSACTION             do{DRV_I2C_WriteReg16(REG_I2C_START, 0x01);} while(0);

// #define I2C_FIFO_FULL                     ((REG_I2C_FIFO_STAT>>1)&0x01)
// #define I2C_FIFO_EMPTY                    (REG_I2C_FIFO_STAT & 0x01)

#define SET_I2C_RX_FIFO_THRESH(n)         do{DRV_I2C_SetData16(REG_I2C_FIFO_THRESH, I2C_RX_FIFO_THRESH_MASK, ((n)<< I2C_RX_FIFO_THRESH_SHIFT));} while(0);
#define SET_I2C_TX_FIFO_THRESH(n)         do{DRV_I2C_SetData16(REG_I2C_FIFO_THRESH, I2C_TX_FIFO_THRESH_MASK, ((n)<< I2C_TX_FIFO_THRESH_SHIFT));} while(0);

#define CLEAR_I2C_FIFO                    do{DRV_I2C_WriteReg16(REG_I2C_FIFO_ADDR_CLR, 0x01);} while(0);

#define SET_I2C_SCL_NORMAL_MODE           do{DRV_I2C_ClearBits16(REG_I2C_IO_CONFIG, I2C_SCL_MODE_BIT);} while(0);
#define SET_I2C_SCL_WIRED_AND_MODE        do{DRV_I2C_SetBits16(REG_I2C_IO_CONFIG, I2C_SCL_MODE_BIT);} while(0);
#define SET_I2C_SDA_NORMAL_MODE           do{DRV_I2C_ClearBits16(REG_I2C_IO_CONFIG, I2C_SDA_MODE_BIT);} while(0);
#define SET_I2C_SDA_WIRED_AND_MODE        do{DRV_I2C_SetBits16(REG_I2C_IO_CONFIG, I2C_SDA_MODE_BIT);} while(0);
#define ENABLE_I2C_BUS_DETECT             do{DRV_I2C_SetBits16(REG_I2C_IO_CONFIG, I2C_BUS_DETECT_EN_BIT);} while(0);
#define DISABLE_I2C_BUS_DETECT            do{DRV_I2C_ClearBits16(REG_I2C_IO_CONFIG, I2C_BUS_DETECT_EN_BIT);} while(0);

#define ENABLE_I2C_CLOCK_SYNC             do{DRV_I2C_SetBits16(REG_I2C_MULTI_MASTER, I2C_ARBITRATION_BIT);} while(0);
#define ENABLE_DATA_ARBITION              do{DRV_I2C_SetBits16(REG_I2C_MULTI_MASTER, I2C_CLOCK_SYNC_BIT);} while(0);
#define ENABLE_I2C_BUS_BUSY_DET           do{DRV_I2C_SetBits16(REG_I2C_MULTI_MASTER, I2C_BUS_BUSY_DET_BIT);} while(0);
#define DISABLE_I2C_CLOCK_SYNC            do{DRV_I2C_ClearBits16(REG_I2C_MULTI_MASTER, I2C_ARBITRATION_BIT);} while(0);
#define DISABLE_DATA_ARBITION             do{DRV_I2C_ClearBits16(REG_I2C_MULTI_MASTER, I2C_CLOCK_SYNC_BIT);} while(0);
#define DISABLE_I2C_BUS_BUSY_DET          do{DRV_I2C_ClearBits16(REG_I2C_MULTI_MASTER, I2C_BUS_BUSY_DET_BIT);} while(0);

#define SET_I2C_HIGH_SPEED_MODE_800KB     do{DRV_I2C_WriteReg16(REG_I2C_HS_MODE, 0x0703);} while(0);
#define SET_I2C_HIGH_SPEED_MODE_1000KB    do{DRV_I2C_WriteReg16(REG_I2C_HS_MODE, 0x0503);} while(0);

#define SET_I2C_FAST_MODE                 do{DRV_I2C_ClearBits16(REG_I2C_HS_MODE, I2C_HS_EN_BIT);} while(0);
#define SET_I2C_HS_MODE                   do{DRV_I2C_SetBits16(REG_I2C_HS_MODE, I2C_HS_EN_BIT);} while(0);
#define ENABLE_I2C_NAKERR_DET             do{DRV_I2C_SetBits16(REG_I2C_HS_MODE, I2C_HS_NACK_ERR_DET_EN_BIT);} while(0);
#define DISABLE_I2C_NAKERR_DET            do{DRV_I2C_ClearBits16(REG_I2C_HS_MODE, I2C_HS_NACK_ERR_DET_EN_BIT);} while(0);
#define SET_I2C_HS_MASTER_CODE(n)         do{DRV_I2C_SetData16(REG_I2C_HS_MODE, I2C_HS_MASTER_CODE_MASK, ((n)<<I2C_HS_MASTER_CODE_SHIFT));} while(0);

#define SET_I2C_HS_STEP_CNT_DIV(n)        do{DRV_I2C_SetData16(REG_I2C_HS_MODE, I2C_HS_STEP_CNT_DIV_MASK, ((n)<<I2C_HS_STEP_CNT_DIV_SHIFT));} while(0);
#define SET_I2C_HS_SAMPLE_CNT_DIV(n)      do{DRV_I2C_SetData16(REG_I2C_HS_MODE, I2C_HS_SAMPLE_CNT_DIV_MASK, ((n)<<I2C_HS_SAMPLE_CNT_DIV_SHIFT));} while(0);

#define RESET_I2C                         do{DRV_I2C_WriteReg16(REG_I2C_SOFTRESET, 0x01);} while(0);

//---------------- DMA ----------------
#if defined(DRV_I2C_DIRECT_CONFIG_DMA_REGISTER)

//#define DMA_base		0x80030000 -->defined in /inc/reg_base.h

/* Regidter Definitions */
#define REG_DMA_CHANNEL_CONTROL(c)        *((volatile unsigned int *) (DMA_base + 0x14+ (c<<8)))
#define REG_DMA_CHANNEL_START(c)          *((volatile unsigned int *) (DMA_base + 0x18+ (c<<8)))
#define REG_DMA_PROG_ADDR(c)              *((volatile unsigned int *) (DMA_base + 0x2c+ (c<<8)))
#define REG_DMA_TRANSFER_COUNT(c)         *((volatile unsigned int *) (DMA_base + 0x10+ (c<<8)))

/* Master Definitions*/
#define DMA_MASTER_I2C_TX                 DMA_CON_MASTER_I2CTX
#define DMA_MASTER_I2C_RX                 DMA_CON_MASTER_I2CRX
#define DMA_MASTER_IRDA_TX                0x02
#define DMA_MASTER_IRDA_RX                0x03

#define DMA_I2C_TX_CHANNEL                4
#define DMA_I2C_RX_CHANNEL                5

/* Register masks */
#define DMA_CON_DIR_MASK                  0x40000
#define DMA_CON_MAS_MASK                  0x01f00000

#define I2C_SET_TX_DMA_CONTROL(c,m)       REG_DMA_CHANNEL_CONTROL(c) = 0x00000014;\
                                          REG_DMA_CHANNEL_CONTROL(c) |= (((m)<<20) & DMA_CON_MAS_MASK);

#define I2C_SET_RX_DMA_CONTROL(c,m)       REG_DMA_CHANNEL_CONTROL(c) = 0x00040018;\
                                          REG_DMA_CHANNEL_CONTROL(c) |= (((m)<<20) & DMA_CON_MAS_MASK);

#define I2C_SET_DMA_PROGRAMMABLE_ADDR(c,addr)    REG_DMA_PROG_ADDR(c) = (addr);
#define I2C_SET_DMA_TRANSFER_COUNT(c,size)       REG_DMA_TRANSFER_COUNT(c)= size ;
#define I2C_START_DMA_TRANSFER(c)                REG_DMA_CHANNEL_START(c) =	0x8000;
#define I2C_STOP_DMA_TRANSFER(c)                 REG_DMA_CHANNEL_START(c) =	0;

#endif // #if defined(DRV_I2C_DIRECT_CONFIG_DMA_REGISTER)

/****** SW definitions******/
#define I2C_READ_BIT            0x01
#define I2C_WRITE_BIT           0x00

#define I2C_TRANSAC_COMPLETE    0x01
#define I2C_TRANSAC_ACK_ERR     0x02
#define I2C_HS_NACK_ERR         0x04
#define I2C_TIMEOUT         	0x10

//extern kal_bool dcl_i2c_init_done_flag;
//extern i2c_handle_struct i2c_handle[DCL_I2C_NUM_OF_OWNER];

void dcl_i2c_init(void);
extern void dcl_i2c_hw_cfg (DCL_I2C_OWNER owner, I2C_TRANSACTION_TYPE type, kal_uint8* write_buffer, kal_uint32 write_len, kal_uint8* read_buffer, kal_uint32 read_len, kal_uint32 transfer_num);
void dcl_i2c_set_transaction_speed(DCL_I2C_OWNER owner,I2C_TRANSACTION_MODE mode,kal_uint16* Fast_Mode_Speed,kal_uint16* HS_Mode_Speed);
extern kal_uint32 dcl_i2c_wait_transaction_complete_and_lock(DCL_I2C_OWNER owner);
void dcl_i2c_wait_transaction_complete(kal_uint32 savedMask);
#if defined(DRV_I2C_BATCH_TRANSACTION_SUPPORT)
I2C_TRANSACTION_RESULT dcl_i2c_get_batch_transaction_result(DCL_I2C_OWNER owner,kal_uint32* batch_num);
I2C_TRANSACTION_RESULT dcl_i2c_batch_transaction(DCL_I2C_OWNER owner, i2c_batch_data_struct *batch_data, kal_uint32 batch_num);
#endif // #if (defined(DRV_I2C_DMA_ENABLED))

#endif // #if (defined(DRV_I2C_25_SERIES))

void CameraSccbPadEnable(kal_bool On);
#endif // #ifndef __I2C_H__

