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
 *   drv_coresight.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   Driver of coresight IP
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
 * Enable Flush master for ADCC
 *
 * removed!
 * removed!
 * Not Turn OFF ADCC after enable flush
 *
 * removed!
 * removed!
 * [MOLY] Capture Card Normal Mode issue fixed
 *
 * removed!
 * removed!
 * [MOLY] Lock sleep for capture card
 *
 * removed!
 * removed!
 * [DNT] Update for 6290 E2
 *
 * removed!
 * removed!
 * 	Update driver for E2
 *
 * removed!
 * removed!
 * [MOLY] DNT driver update for 6290 E2
 *
 * removed!
 * removed!
 * Update DNT driver for HK field trial
 *
 * removed!
 * removed!
 * Fix compile warning for SLT
 *
 * removed!
 * removed!
 * [MOLY] Coresight Driver Update for ADC Capture
 *
 * removed!
 * removed!
 * [MOLY] DNT Update
 *
 * removed!
 * removed!
 * [MOLY] DNT Driver Update
 *
 * removed!
 * removed!
 * 1. Update L2 HW logging test to use new coresight driver
 * 2. In order to reduce use size of trace fifo, only trigger flush master to output trace data
 *     when the data in trace fifo is not enough to do 15/16b decode
 *
 * removed!
 * removed!
 * [MOLY] DNT Driver Update
 *
 * removed!
 * removed!
 * [MOLY] DNT Modification
 *
 * removed!
 * removed!
 * [MOLY] DNT Modification for 6290E1, sync back to MOLY TRUNK from FIRSTCALL BRANCH
 *
 * removed!
 * removed!
 * [MOLY Trunk] DNT Modification for ASIC
 *
 * removed!
 * removed!
 * [Call for checkin] [MOLY maintrunk] Rename MT7208 projects to MT6290
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * Merge Coresight related driver from TATAKA to MOLY trunk
 ****************************************************************************/

/**
 * @file drv_dnt.c
 * @brief driver functions for DNT sys
 *
 * @author mtk00586
 * @date 04/02/12
 *
 **/

#ifdef MT6290

#include "reg_base.h"
#include "drv_features_gpt.h"
#include "drv_comm.h"
#include "drv_iomux.h"
#include "dcl.h"
#include "dcl_gpio.h"
#include "drv_coresight.h"
#include "drv_coresight_pri.h"
#include "drv_adccnp.h"
#include "drv_rstctl.h"

#include "intrCtrl.h"
#include "dcl.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "sync_data.h"

#if defined( MTK_SLEEP_ENABLE) && !defined(ATEST_ENABLE)
// sleep disable / enable API
extern kal_uint8 SleepDrv_GetHandle( void );
extern void SleepDrv_SleepDisable( kal_uint8 handleCount );
extern void SleepDrv_SleepEnable( kal_uint8 handleCount );
kal_uint8 dnt_sleep_lock_handler = 0;
#endif


void dnt_delay_us(kal_uint32 us)
{
  kal_uint32 counter_val_old;
  kal_uint32 counter_val;


  if ((DRV_Reg32(TOPSM_FRC_CON) & 0x01) != 0x01)
  {
    DRV_WriteReg32(TOPSM_FRC_CON, DRV_Reg32(TOPSM_FRC_CON) | 0x01);
  }
  
  counter_val_old = DRV_Reg32(TOPSM_FRC_VAL_R);

  while(1)
  {
    counter_val = DRV_Reg32(TOPSM_FRC_VAL_R);
    if (((counter_val - counter_val_old)) >= us)
    {
      break;
    }
  }


}

// ----------------------------------------------------------
/**
 *  brief TPIU initialization
  *  @param  DNT path selection : DNT 1 or DNT 2 or both
 */
void CoreSight_TPIU_SW_Configure(kal_uint32 uDNTSel, eSIB_Configure_mode SIB_Configure_mode)
{	
	MISC_CoreSight_Module_Unlock(TPIU_BASE_ADDRESS, uDNTSel);

   TRACE_WriteReg32(TPIU_CURRENT_PORT_SIZE_REG, uDNTSel, PORT_SIZE_16);

   TRACE_WriteReg32(DNT_MISC_CTRL, uDNTSel, SW_FLUSH_DISABLE);

   if (SIB_Configure_mode == DNT_MODE_ADCP)
   {
     TRACE_WriteReg32(TPIU_FFCR_REG, uDNTSel, 0);
   }
   else
   {
     TRACE_WriteReg32(TPIU_FFCR_REG, uDNTSel, TPIU_FOnFlIn | TPIU_EnFCont); // use FLUSHIN interface; Enable continuous formatting
   }

	MISC_CoreSight_Module_Lock(TPIU_BASE_ADDRESS, uDNTSel);

}


// ----------------------------------------------------------
/**
 * @brief STP initialization
 *  @param  DNT path selection : DNT 1 or DNT 2 or both
 */
void STP_Configuration(kal_uint32 uDNTSel, eSIB_Configure_mode SIB_Configure_mode)
{

  MISC_CoreSight_Module_Unlock( STP_BASE_ADDRESS, uDNTSel);

  TRACE_WriteReg32(STP_LINK_COUNT, uDNTSel, LNK_SCOUNT_1 | LNK_TCOUNT_8);
  TRACE_WriteReg32(STP_LINK_TINT, uDNTSel, LNK_TINTERVAL_4096);
  if (SIB_Configure_mode == DNT_MODE_L2Copro_TestMode)
  {
    TRACE_WriteReg32(STP_CONTROL_REG, uDNTSel, STP_ENA);
  }
  else
  {
    TRACE_WriteReg32(STP_CONTROL_REG, uDNTSel, STP_ENA | 0x04); // enable scramble
  }
  //  *(volatile int*) STP_CONTROL_REG = 0x105;

  TRACE_WriteReg32(STP_FLUSHTH, uDNTSel, FLUSHTH_4095);
 
  MISC_CoreSight_Module_Lock( STP_BASE_ADDRESS, uDNTSel);

}

// ----------------------------------------------------------
/**
 * @brief Set to ATBBWL to bypass mode
 *  @param  DNT path selection : DNT 1 or DNT 2 or both 
 */
void ATBBWL_Set_Bypass_Mode(kal_uint32 uDNTSel)
{
  TRACE_WriteReg32(ATBBWL_EN_REG_ADDR, uDNTSel, 0);
}

// ----------------------------------------------------------
/**
 * @brief Trace Funnel Initialization
 *  @param  DNT path selection : DNT 1 or DNT 2 or both  
 */
void TF_init(eSIB_Configure_mode SIB_Configure_mode)
{
  MISC_CoreSight_Module_Unlock(TRACE_FUNNEL, 0);
  MISC_CoreSight_Module_Unlock(TRACE_FUNNEL, 1);
      
  if (SIB_Configure_mode == DNT_MODE_MD_LOG)
  {
    TRACE_WriteReg32(CSTF_CONTROL, 0, 0);
    TRACE_WriteReg32(CSTF_CONTROL, 1, MINUMUM_HOLD_TIME_15 | ((~ENABLE_SLAVE_PORT0) & 0x000000FF));
  }
  else if (SIB_Configure_mode == DNT_MODE_ADCC)
  {
    // Will Turn Off all the other funnel setting
    TRACE_WriteReg32(CSTF_CONTROL, 0, MINUMUM_HOLD_TIME_15 | ENABLE_SLAVE_PORT0);
    TRACE_WriteReg32(CSTF_CONTROL, 1, MINUMUM_HOLD_TIME_15 | ENABLE_SLAVE_PORT0); 
  }
  else if (SIB_Configure_mode == DNT_MODE_ADCP)
  {
    TRACE_WriteReg32(CSTF_CONTROL, 0, 0);
    TRACE_WriteReg32(CSTF_CONTROL, 1, 0);
  }
  else // DNT_MODE_L2Copro_TestMode
  {
    //Enable Test Mode for L2 HW Log testing!
    TRACE_WriteReg32(DNT_MISC_CTRL, 1, SW_FLUSH_EN); // Disable STP flush function
    TRACE_WriteReg32(CSTF_CONTROL, 0, 0);
    TRACE_WriteReg32(CSTF_CONTROL, 1, ENABLE_SLAVE_PORT7 | ENABLE_SLAVE_PORT1);
  }
  
  MISC_CoreSight_Module_Lock(TRACE_FUNNEL, 0);  
  MISC_CoreSight_Module_Lock(TRACE_FUNNEL, 1);  

}

// ----------------------------------------------------------
/**
 * @brief Trace Funnel enable flush master only
 *  @param  None
 */
// ----------------------------------------------------------
void TF_enable_flush_master_only(void)
{
  MISC_CoreSight_Module_Unlock(TRACE_FUNNEL, 0);
  MISC_CoreSight_Module_Unlock(TRACE_FUNNEL, 1);
      
  TRACE_WriteReg32(CSTF_CONTROL, 0, TRACE_ReadReg32(CSTF_CONTROL, 0) | ENABLE_SLAVE_PORT7 );
  TRACE_WriteReg32(CSTF_CONTROL, 1, TRACE_ReadReg32(CSTF_CONTROL, 1) | ENABLE_SLAVE_PORT7 ); 
  
  
  MISC_CoreSight_Module_Lock(TRACE_FUNNEL, 0);  
  MISC_CoreSight_Module_Lock(TRACE_FUNNEL, 1);  

}
/**
 * @brief Lock CoreSight Module for register access
 *  @param  lock_access_addr : The lock access register address
 *  @param  lock_status_addr : The lock status register address
 */
kal_int32 MISC_CoreSight_Module_Lock_By_Addr(kal_uint32 lock_access_addr, kal_uint32 lock_status_addr, kal_uint32 uDNTSel)
{
  //volatile kal_int32 *reg_st;
  //volatile kal_int32 *reg_lock;
  kal_uint32 val;

  //reg_st   = (volatile kal_int32 *) lock_status_addr;
  //reg_lock = (volatile kal_int32 *) lock_access_addr;

  /* Read Lock Status Register */
  val = TRACE_ReadReg32(lock_status_addr, uDNTSel); //val = *reg_st;

  if ((val & CORESIGHT_MASK_LOCK) == CORESIGHT_CONST_LOCKED)
  {
    /* already locked */
    while(1);
  }

  /* Lock CoreSight CORESIGHT Module */
  TRACE_WriteReg32(lock_access_addr, uDNTSel, CORESIGHT_CONST_KEYLOCK); //*reg_lock = CORESIGHT_CONST_KEYLOCK;

  //Check is already locked
  do
  {
    val = TRACE_ReadReg32(lock_status_addr, uDNTSel); //val = *reg_st;
  }while( (val & CORESIGHT_MASK_LOCK) != CORESIGHT_CONST_LOCKED);

  return (1);
}

// ----------------------------------------------------------
/**
 * @brief Unlock CoreSight Module for register access
 *  @param  lock_access_addr : The lock access register address
 *  @param  lock_status_addr : The lock status register address
 */
kal_int32 MISC_CoreSight_Module_Unlock_By_Addr(kal_uint32 lock_access_addr, kal_uint32 lock_status_addr, kal_uint32 uDNTSel)
{
  //volatile kal_int32 *reg_st;
  //volatile kal_int32 *reg_lock;
  volatile kal_int32 val;

  //reg_st   = (volatile int *) lock_status_addr;
  //reg_lock = (volatile int *) lock_access_addr;
  
  /* Read Lock Status Register */
  val = TRACE_ReadReg32(lock_status_addr, uDNTSel); //  val = *reg_st;
    
  ASSERT( (val & 0x1) != 0);  /* Not implemented */

  /* Unlock CoreSight CORESIGHT Module */
  TRACE_WriteReg32(lock_access_addr, uDNTSel, CORESIGHT_CONST_KEYRELE); //*reg_lock = CORESIGHT_CONST_KEYRELE;

  /* polling Lock status */
  do
  {
    val = TRACE_ReadReg32(lock_status_addr, uDNTSel); //  val = *reg_st;
  }
  while( (val & CORESIGHT_MASK_LOCK) == CORESIGHT_CONST_LOCKED );

  return (1);
}

// ----------------------------------------------------------
/**
 * @brief Lock CoreSight Module for register access
 *  @param  addr :  The IP's base address
 */
kal_int32 MISC_CoreSight_Module_Lock(kal_uint32 addr, kal_uint32 uDNTSel)
{
  return MISC_CoreSight_Module_Lock_By_Addr(addr + CORESIGHT_LOCK_AC_REG, addr + CORESIGHT_LOCK_ST_REG, uDNTSel);    
}


// ----------------------------------------------------------
/**
 * @brief Unlock CoreSight Module for register access
 *  @param  addr :  The IP's base address
 */
kal_int32 MISC_CoreSight_Module_Unlock(kal_uint32 addr, kal_uint32 uDNTSel)
{  
  return MISC_CoreSight_Module_Unlock_By_Addr(addr + CORESIGHT_LOCK_AC_REG, addr + CORESIGHT_LOCK_ST_REG, uDNTSel);    
}

// ----------------------------------------------------------
/**
 * @brief Initialize SerDes Board
 *  @param uDNTSel : Select coresight path 0 or path 1 
 */
void Serdes_Init(kal_uint32 uDNTSel, eSIB_Configure_mode SIB_Configure_mode)
{
  // Set ATID of Trace port 7 (flush master
  TRACE_WriteReg32(TRACE_PORT7_ATID, uDNTSel, 0);         

#ifdef __FPGA__
  if (SIB_Configure_mode == DNT_MODE_ADCP)
  {
    // For PLAYBACK need set LCKREFN to 1 (i.e. TX/RX mode)
    TRACE_WriteReg32(SERDES_BOARD_CTRL, uDNTSel, (TRACE_ReadReg32(SERDES_BOARD_CTRL, uDNTSel) | (LCKREFN)));  
  }
  else
  {
    // For HW log, only TX path is enable for TLK3101, so need set LCKREFN to 0 (i.e. Transmitter Mode)
    TRACE_WriteReg32(SERDES_BOARD_CTRL, uDNTSel, (TRACE_ReadReg32(SERDES_BOARD_CTRL, uDNTSel) & (~LCKREFN)));
  }
#endif

}

// ----------------------------------------------------------
/**
 * @brief Initialize ATB bandwidth limiter
 *  @param uDNTSel : Select coresight path 0 or path 1
 */

void ATBBWL_init(kal_uint32 uDNTSel)
{
  // For 6290, ATBBWL is not used, set to bypass mode!
  ATBBWL_Set_Bypass_Mode(uDNTSel);
}

#ifndef __FPGA__

#ifndef ATEST_SLT

#define DRIVING_4MA    0x00
#define DRIVING_8MA    0x01
#define DRIVING_12MA   0x02
#define DRIVING_16MA   0x03

typedef struct
{
  config_sel_t CNP_Share_Pin_sel;
  kal_uint8    driving_current;
}CNP_Share_Pin_Driving_Setting;

CNP_Share_Pin_Driving_Setting CNP_Share_Pin_DualChannel_Setting[] =  {{cfg_gpio_0,   DRIVING_12MA},
                                                                      {cfg_spi_0,    DRIVING_12MA},
                                                                      {cfg_gpio_1,   DRIVING_12MA},
                                                                      {cfg_gpio_2,   DRIVING_12MA},
                                                                      {cfg_msdc0p_0, DRIVING_12MA},
                                                                      {cfg_msdc0p_1, DRIVING_12MA},
                                                                      {cfg_msdc0p_2, DRIVING_12MA},
                                                                      {cfg_gpio_3,   DRIVING_12MA},
                                                                      {cfg_gpio_4,   DRIVING_12MA}};

CNP_Share_Pin_Driving_Setting CNP_Share_Pin_SingleChannelSetting[] = {{cfg_gpio_0,   DRIVING_16MA},
                                                                      {cfg_msdc0p_0, DRIVING_12MA},
                                                                      {cfg_msdc0p_1, DRIVING_12MA},
                                                                      {cfg_msdc0p_2, DRIVING_12MA},
                                                                      {cfg_gpio_3,   DRIVING_12MA},
                                                                      {cfg_gpio_4,   DRIVING_12MA}};

typedef struct
{
  mod_sel_t mode_sel;
  kal_uint8 cnp_normal_function;
  kal_uint8 cnp_pin_parking_function;
  kal_uint8 cnp_pin_parking_gpio_no; // GPIO pin number
}CNP_Share_Pin_Type;

static CNP_Share_Pin_Type STP0_RX_CK_pin       =  {sel_gpio_0_0, 1, 4,  0};
static CNP_Share_Pin_Type STP0_TX_EN_RX_DV_pin =  {sel_spi_0,    1, 4, 18};
static CNP_Share_Pin_Type STP0_DATA_pin[16]    = {{sel_spi_0,    1, 4, 19},
                                                  {sel_spi_1,    1, 4, 24}, 
                                                  {sel_spi_0,    1, 4, 20},
                                                  {sel_spi_0,    1, 4, 21},
                                                  {sel_spi_0,    1, 4, 22},
                                                  {sel_spi_0,    1, 4, 23},
                                                  {sel_gpio_0_1, 1, 4,  3},
                                                  {sel_gpio_0_1, 1, 4,  4},
                                                  {sel_gpio_1,   1, 4,  5},
                                                  {sel_gpio_1,   1, 4,  6},
                                                  {sel_gpio_1,   1, 4,  7},                                                
                                                  {sel_gpio_2_0, 1, 4,  8},
                                                  {sel_gpio_2_0, 1, 4,  9},
                                                  {sel_gpio_2_0, 1, 4, 10},
                                                  {sel_gpio_2_1, 1, 4, 11},
                                                  {sel_gpio_2_1, 1, 4, 12}};
                                               
static CNP_Share_Pin_Type STP1_RX_CK_pin       =  {sel_gpio_0_0, 1, 4,  1};
static CNP_Share_Pin_Type STP1_TX_EN_RX_DV_pin =  {sel_msdc0p_0, 1, 4, 25};                                               
static CNP_Share_Pin_Type STP1_DATA_pin[16]    = {{sel_msdc0p_0, 1, 4, 26},
                                                  {sel_msdc0p_1, 1, 4, 27},
                                                  {sel_msdc0p_1, 1, 4, 28},
                                                  {sel_msdc0p_1, 1, 4, 29},
                                                  {sel_msdc0p_1, 1, 4, 30},
                                                  {sel_msdc0p_1, 1, 4, 31},
                                                  {sel_msdc0p_1, 1, 4, 32},
                                                  {sel_msdc0p_2, 1, 4, 33},
                                                  {sel_msdc0p_2, 1, 4, 34},
                                                  {sel_msdc0p_2, 1, 4, 35},
                                                  {sel_msdc0p_2, 1, 4, 36},                                                
                                                  {sel_gpio_3,   1, 4, 13},
                                                  {sel_gpio_3,   1, 4, 14},
                                                  {sel_gpio_3,   1, 4, 15},
                                                  {sel_gpio_4,   1, 4, 16},
                                                  {sel_gpio_4,   1, 4, 17}};
static CNP_Share_Pin_Type STP1_TX_CK_pin       =  {sel_gpio_0_0, 1, 4,  2};  
static CNP_Share_Pin_Type CNP_mode_control_pin =  {sel_usim2,    4, 4,  5};

//   Normal Function 1                | Normal Functino 4
//====== STP 0 function ============= |
//STP0_RX_CK           : SEL_GPIO_0_0 | GPIO[0]  
//STP0_TX_EN/RX_DV     : SEL_SPI_0    | GPIO[18]
//STP0_DATA[0,2:5]     : SEL_SPI_0    | GPIO[19, 20:23]
//STP0_DATA[1]         : SEL_SPI_1    | GPIO[24]
//STP0_DATA[6:7]       : SEL_GPIO_0_1 | GPIO[3:4]
//STP0_DATA[8:10]      : SEL_GPIO_1   | GPIO[5:7]
//STP0_DATA[11:13]     : SEL_GPIO_2_0 | GPIO[8:10]
//STP0_DATA[14:15]     : SEL_GPIO_2_1 | GPIO[11:12]
//                                    |
//====== STP 1 function ============= |
//STP1_RX_CK           : SEL_GPIO_0_0 | GPIO[1]
//STP1_TX_EN/RX_DV     : SEL_MSDC0P_0 | GPIO[25]
//STP1_DATA[0]         : SEL_MSDC0P_0 | GPIO[26]
//STP1_DATA[1:6]       : SEL_MSDC0P_1 | GPIO[27:32]
//STP1_DATA[7:10]      : SEL_MSDC0P_2 | GPIO[33:36]
//STP1_DATA[11:13]     : SEL_GPIO_3   | GPIO[13:15]
//STP1_DATA[14:15]     : SEL_GPIO_4   | GPIO[16:17]

//====== STP 0/1 common function ==== |
//STP1_TX_CK           : SEL_GPIO_0_0 | GPIO[2] 
// x                   : SEL_USIM2    | GPO[5]

#endif //ATEST_SLT

#ifdef CNP_PARKING_IOMUX_TO_GPIO_INPUT_MODE
void CNP_iomux_parking(void)
{
#ifdef ATEST_SLT
  return;
#else
  kal_uint32 index;
  DCL_HANDLE hgpio;
  
  //1. Configure Related GPIO to Input Mode first
  hgpio = DclGPIO_Open(DCL_GPIO, STP0_RX_CK_pin.cnp_pin_parking_gpio_no);
  DclGPIO_Control(hgpio, GPIO_CMD_SET_OWNERSHIP_TO_MD, 0);
  DclGPIO_Control(hgpio, GPIO_CMD_SET_DIR_IN, 0);

  hgpio = DclGPIO_Open(DCL_GPIO, STP0_TX_EN_RX_DV_pin.cnp_pin_parking_gpio_no);
  DclGPIO_Control(hgpio, GPIO_CMD_SET_OWNERSHIP_TO_MD, 0);
  DclGPIO_Control(hgpio, GPIO_CMD_SET_DIR_IN, 0);  

  hgpio = DclGPIO_Open(DCL_GPIO, STP1_RX_CK_pin.cnp_pin_parking_gpio_no);
  DclGPIO_Control(hgpio, GPIO_CMD_SET_OWNERSHIP_TO_MD, 0);
  DclGPIO_Control(hgpio, GPIO_CMD_SET_DIR_IN, 0);  

  hgpio = DclGPIO_Open(DCL_GPIO, STP1_TX_EN_RX_DV_pin.cnp_pin_parking_gpio_no);
  DclGPIO_Control(hgpio, GPIO_CMD_SET_OWNERSHIP_TO_MD, 0);
  DclGPIO_Control(hgpio, GPIO_CMD_SET_DIR_IN, 0);  
  
  hgpio = DclGPIO_Open(DCL_GPIO, STP1_TX_CK_pin.cnp_pin_parking_gpio_no);
  DclGPIO_Control(hgpio, GPIO_CMD_SET_OWNERSHIP_TO_MD, 0);
  DclGPIO_Control(hgpio, GPIO_CMD_SET_DIR_IN, 0);  
  
  for (index = 0; index < 16; index++)
  {
    hgpio = DclGPIO_Open(DCL_GPIO, STP0_DATA_pin[index].cnp_pin_parking_gpio_no);
    DclGPIO_Control(hgpio, GPIO_CMD_SET_OWNERSHIP_TO_MD, 0);
    DclGPIO_Control(hgpio, GPIO_CMD_SET_DIR_IN, 0);

    hgpio = DclGPIO_Open(DCL_GPIO, STP1_DATA_pin[index].cnp_pin_parking_gpio_no);
    DclGPIO_Control(hgpio, GPIO_CMD_SET_OWNERSHIP_TO_MD, 0);
    DclGPIO_Control(hgpio, GPIO_CMD_SET_DIR_IN, 0);
  }

  //2. Configure CNP related to GPIO function to prevent conflict  

  IOMUX_set_module_func(STP0_RX_CK_pin.cnp_pin_parking_function, STP0_RX_CK_pin.mode_sel);

  IOMUX_set_module_func(STP0_TX_EN_RX_DV_pin.cnp_pin_parking_function, STP0_TX_EN_RX_DV_pin.mode_sel);

  IOMUX_set_module_func(STP1_RX_CK_pin.cnp_pin_parking_function, STP1_RX_CK_pin.mode_sel);

  IOMUX_set_module_func(STP1_TX_EN_RX_DV_pin.cnp_pin_parking_function, STP1_TX_EN_RX_DV_pin.mode_sel);

  IOMUX_set_module_func(STP1_TX_CK_pin.cnp_pin_parking_function, STP1_TX_CK_pin.mode_sel);
  
  for (index = 0; index < 16; index++)
  {
    IOMUX_set_module_func(STP0_DATA_pin[index].cnp_pin_parking_function, STP0_DATA_pin[index].mode_sel);
    IOMUX_set_module_func(STP1_DATA_pin[index].cnp_pin_parking_function, STP1_DATA_pin[index].mode_sel);
  }
#endif
}
#endif

#if 1
#include "reg_base.h"
#include "intrCtrl.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"
#include "kal_public_api.h"
#include "drv_bsi.h"
#endif
// ----------------------------------------------------------
/**
 * @brief IOMUX selection
 *  @param Trace_Mode : configure the IOMUX for capture or 
 *                      playback mode
 */
void CNP_iomux_sel(eSIB_Configure_mode SIB_Configure_mode)
{
  kal_uint32 bypass_iomux_setting = 0;
#ifndef ATEST_SLT  
  DCL_HANDLE control_gpio_handler;
  kal_uint32 index;
#endif  
  
#if defined(__LTE_PHY_TEST__)  
  kal_uint16 pmic_val;
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
#endif
  // Enable VMC
  pmic_val = drv_bsi_pmic6339_reg_read(0x38);
  pmic_val |= 0x0001; // RG_VMCH_EN
  drv_bsi_pmic6339_reg_write(0x38, pmic_val);
  //0x60 => 3.0v
  //0x70 => 3.3v
  drv_bsi_pmic6339_reg_write(0x36, 0x70);
  //pmic_val = drv_bsi_pmic6339_reg_read(0x37);
  //pmic_val &= 0xFFF0;
  //pmic_val |= 0x000B; // +100mv  
  //pmic_val |= 0x000D; // +60mv
  //drv_bsi_pmic6339_reg_write(0x37, pmic_val);
#endif
  
#ifndef ATEST_SLT
  if (SIB_Configure_mode == DNT_MODE_L2Copro_TestMode)
#endif    
  {
    bypass_iomux_setting = 1;
  }

  if (bypass_iomux_setting)
  {
    if (SIB_Configure_mode == DNT_MODE_ADCP)
    {
      DRV_WriteReg32_NPW(BASE_ADDR_MDCFGAPB + 0x30, DRV_Reg32(BASE_ADDR_MDCFGAPB + 0x30) | 0x00100000);
      DRV_WriteReg32_NPW(APPERISYS_TRACE_CTRL, (DRV_Reg32(APPERISYS_TRACE_CTRL)&0xFFFFFFFE) | IO_PLAYBACK_MODE);
    }
    else // Trace_ADCC_Mode, Trace_SW_LOG_Mode, Trace_L2CoproHWLogMode
    {
      DRV_WriteReg32_NPW(BASE_ADDR_MDCFGAPB + 0x30, DRV_Reg32(BASE_ADDR_MDCFGAPB + 0x30) | 0x00100000);
      DRV_WriteReg32_NPW(APPERISYS_TRACE_CTRL, (DRV_Reg32(APPERISYS_TRACE_CTRL)&0xFFFFFFFE) | IO_CAPTURE_MODE);
    }  
  }
#ifndef ATEST_SLT  
  else
  {
  #ifdef CNP_PARKING_IOMUX_TO_GPIO_INPUT_MODE
    //1. Parking share pin to GPIO input mode
    CNP_iomux_parking();
  #endif  
  
    //2. Congure Control Pin
    IOMUX_set_module_func(4, sel_usim2); // Use pad_usim2rst as mode selection signal
    control_gpio_handler = DclGPIO_Open(DCL_GPIO, CNP_mode_control_pin.cnp_pin_parking_gpio_no);
    DclGPIO_Control(control_gpio_handler, GPIO_CMD_SET_OWNERSHIP_TO_MD, 0);
    DclGPIO_Control(control_gpio_handler, GPIO_CMD_SET_DIR_OUT, 0);
    
    if (SIB_Configure_mode == DNT_MODE_ADCP)
    {
      //3.b.1 Set control pin to LOW as playback mode (Will inverted to High as input for PI3CH281L)
      DclGPIO_Control(control_gpio_handler, CNP_CONTROL_PIN_PLAYBACK_MODE,0);
      //3.b.2 Configure Trace Channel as playback mode
      DRV_WriteReg32_NPW(BASE_ADDR_MDCFGAPB + 0x30, DRV_Reg32(BASE_ADDR_MDCFGAPB + 0x30) | 0x00100000);
      DRV_WriteReg32_NPW(APPERISYS_TRACE_CTRL, (DRV_Reg32(APPERISYS_TRACE_CTRL)&0xFFFFFFFE) | IO_PLAYBACK_MODE);
      //3.b.3 configure RXDFE as playback mode
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, PLAYBACK_FROM_ADCP);
    }
    else // Trace_ADCC_Mode, Trace_SW_LOG_Mode, Trace_L2CoproHWLogMode
    {
      //3.c.1 Set control pin to HIGH as capture mode (Will inverted to Low as input for PI3CH281L)
      DclGPIO_Control(control_gpio_handler, CNP_CONTROL_PIN_CAPTURE_MODE,0);
      //3.c.2 Configure Trace Channel as capture mode
      DRV_WriteReg32_NPW(BASE_ADDR_MDCFGAPB + 0x30, DRV_Reg32(BASE_ADDR_MDCFGAPB + 0x30) | 0x00100000);
      DRV_WriteReg32_NPW(APPERISYS_TRACE_CTRL, (DRV_Reg32(APPERISYS_TRACE_CTRL)&0xFFFFFFFE) | IO_CAPTURE_MODE);
    }
  
    //4. Switch share pin to trace
    IOMUX_set_module_func(STP0_RX_CK_pin.cnp_normal_function, STP0_RX_CK_pin.mode_sel);
  
    IOMUX_set_module_func(STP0_TX_EN_RX_DV_pin.cnp_normal_function, STP0_TX_EN_RX_DV_pin.mode_sel);
  
    IOMUX_set_module_func(STP1_RX_CK_pin.cnp_normal_function, STP1_RX_CK_pin.mode_sel);
  
    IOMUX_set_module_func(STP1_TX_EN_RX_DV_pin.cnp_normal_function, STP1_TX_EN_RX_DV_pin.mode_sel);
    
    IOMUX_set_module_func(STP1_TX_CK_pin.cnp_normal_function, STP1_TX_CK_pin.mode_sel);
    
    for (index = 0; index < 16; index++)
    {
      IOMUX_set_module_func(STP0_DATA_pin[index].cnp_normal_function, STP0_DATA_pin[index].mode_sel);
      IOMUX_set_module_func(STP1_DATA_pin[index].cnp_normal_function, STP1_DATA_pin[index].mode_sel);
    }
  
    DRV_WriteReg32(IOMUX_TOPMISC_DUMMY, (DRV_Reg32(IOMUX_TOPMISC_DUMMY) & 0xFFFFFFC0) | 0x09);
  
    //5. Configure Driving Current
    if (SIB_Configure_mode == DNT_MODE_ADCP)
    {
      DRV_WriteReg32_NPW(0xBF8A0124, 0x000C);
      DRV_WriteReg32_NPW(0xBF8A0128, 0x000C);
      DRV_WriteReg32_NPW(0xBF8A0154, 0x000C);
      DRV_WriteReg32_NPW(0xBF8A0158, 0x000C);
      DRV_WriteReg32_NPW(0xBF8A015C, 0x000C);
      DRV_WriteReg32_NPW(0xBF8A01AC, 0x000C0C0C);
      DRV_WriteReg32_NPW(0xBF8A01B0, 0x000C);
      DRV_WriteReg32_NPW(0xBF8A01B4, 0x000C000C);
      DRV_WriteReg32_NPW(0xBF8A01B8, 0x000C);
      DRV_WriteReg32_NPW(0xBF8A01BC, 0x000C);
    }
    else if (SIB_Configure_mode == DNT_MODE_ADCC)
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
  #else
     
    #if 0 //Old Capture Board
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
    #if 1 //new Capture Board #1
      DRV_WriteReg32_NPW(0xBF8A0124, 0x0000);
      DRV_WriteReg32_NPW(0xBF8A0128, 0x0000);
      DRV_WriteReg32_NPW(0xBF8A0154, 0x0000);
      DRV_WriteReg32_NPW(0xBF8A0158, 0x0000);
      DRV_WriteReg32_NPW(0xBF8A015C, 0x0000);
      DRV_WriteReg32_NPW(0xBF8A01AC, 0x00000400);    
      DRV_WriteReg32_NPW(0xBF8A01B0, 0x0000);
      DRV_WriteReg32_NPW(0xBF8A01B4, 0x00000000);
      DRV_WriteReg32_NPW(0xBF8A01B8, 0x0000);
      DRV_WriteReg32_NPW(0xBF8A01BC, 0x0000);
    #endif
    
  #endif
    }
    else // for single channel
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
  #endif
  #if 1 //EVB 8
      DRV_WriteReg32_NPW(0xBF8A0124, 0x0000);
      DRV_WriteReg32_NPW(0xBF8A0128, 0x0000);
      DRV_WriteReg32_NPW(0xBF8A0154, 0x0C00);
      DRV_WriteReg32_NPW(0xBF8A0158, 0x0800);//0x1400
      DRV_WriteReg32_NPW(0xBF8A015C, 0x0800);//0x1400
      DRV_WriteReg32_NPW(0xBF8A01AC, 0x00000C00);//0x0C000800
      DRV_WriteReg32_NPW(0xBF8A01B0, 0x0000); //0xC00
      DRV_WriteReg32_NPW(0xBF8A01B4, 0x00000000);//0x0C000C00
      DRV_WriteReg32_NPW(0xBF8A01B8, 0x0C00); //0xC00
      DRV_WriteReg32_NPW(0xBF8A01BC, 0x0800);//0xC00
  #endif    
    }
  }
#endif
}


void trace_enable_dsp_c2crf(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
  DRV_WriteReg32(BASE_ADDR_CORE_DMAIF_FCORE1, 0x02); // C2CRF access enable

}
#endif

//===========================================================================//
//====================== Public Driver API ==================================//
//===========================================================================//

// ----------------------------------------------------------
/**
 *  @brief Initialize CoreSight IP
 * @param  Trace_Mode :  Trace_ADCC_Mode for capture mode, 
 *                       Trace_ADCP_Mode for playback mode
 * @retval 0 The DNT IP is eable
 * @retval 1 The DNT IP is disabled by E-fuse
 */
kal_uint32 drv_dnt_init(eSIB_Configure_mode SIB_Configure_mode)
{
  kal_uint32 dnt_path;
  kal_uint32 result = 0;

#if defined( MTK_SLEEP_ENABLE) && !defined(ATEST_ENABLE)
  // Always lock OSTD sleep while using DNT
  if (dnt_sleep_lock_handler == 0)
  {
    dnt_sleep_lock_handler = SleepDrv_GetHandle();
    SleepDrv_SleepDisable(dnt_sleep_lock_handler);
  }
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
#endif
#endif

  // TODO : Check efuse setting to check if the IP is enable or not
  //        Example: result = ((bCheckEfuse(DNT_IP) == IP_ENABLE)? 0 : 1);
#if defined(MT6290_S01)
  //The debug and trace ECO for MT6290 need to update the TOPMISC CSR as follows :
  //
  //0xbf8a01d4 <R_TOPMISC_DUMMY>
  //[24] STP_TX_OE : STP TX clock output enable control
  //[23] STP_SMT_EN : STP RX IO pad SMT control enable
  //[22:20] STP_SMT: STP RX IO pad SMT control 
  //   [20] : MSDC0P_WP and MSDC0P_INS SMT control when STP RX IO pad SMT control enable=1
  //   [21] : SPI SMT control when STP RX IO pad SMT control enable=1
  //   [22] : GPIO SMT control when STP RX IO pad SMT control enable=1
  DRV_WriteReg32(0xBF8A01D4, DRV_Reg32(0xBF8A01D4) | (1 << 24));
#endif
  
#ifndef __FPGA__
  trace_enable_dsp_c2crf();
#endif

  for (dnt_path = 0; dnt_path < 2; dnt_path++)
  {
    
    //Serdes
    Serdes_Init(dnt_path, SIB_Configure_mode);
  
    //STP
    STP_Configuration(dnt_path, SIB_Configure_mode);
  
    //TPIU
    CoreSight_TPIU_SW_Configure(dnt_path, SIB_Configure_mode);
  
    //ATB BWL
    ATBBWL_init(dnt_path);
  }
  
  //Trace funnel
  TF_init(SIB_Configure_mode);
   
  //IO Mux setting, include driving current adjustment
#ifndef __FPGA__  
  CNP_iomux_sel(SIB_Configure_mode);
#endif

  return result;
}

// ----------------------------------------------------------
/**
 *  @brief Trace Funnel On for specific function
 * @param  Trace_Mode :  Trace_ADCC_Mode for capture mode, 
 *                       Trace_ADCP_Mode for playback mode
 * @retval 0 Successful
 * @retval 1 Fail
 */
kal_uint32 drv_dnt_funnel_open(eTrace_mode Trace_Mode)
{
  //CH0
  //0 : ADCC
  //1 : x
  //2 : x
  //3 : patgen0
  //4 : patgen1
  //5 : x
  //6 : x 
  //7 : flush master

  //CH1
  //0 : ADCC
  //1 : L2C
  //2 : DSP
  //3 : patgen0
  //4 : patgen1
  //5 : 3g_0
  //6 : 3g_1 
  //7 : flush master
  

  MISC_CoreSight_Module_Unlock(TRACE_FUNNEL, 0);
  MISC_CoreSight_Module_Unlock(TRACE_FUNNEL, 1);

  // Only ADCC use trace 0, so turn it off initially
  TRACE_WriteReg32(CSTF_CONTROL, 0, 0);

  switch (Trace_Mode)
  {
    case Trace_ADCC_Mode:
      // Will Turn Off all the other funnel setting
      TRACE_WriteReg32(CSTF_CONTROL, 0, MINUMUM_HOLD_TIME_15 | ENABLE_SLAVE_PORT7 | ENABLE_SLAVE_PORT0);
      TRACE_WriteReg32(CSTF_CONTROL, 1, MINUMUM_HOLD_TIME_15 | ENABLE_SLAVE_PORT7 | ENABLE_SLAVE_PORT0);
      break;
    case Trace_ADCP_Mode:
      // Playback mode, turn off all the funnel
      TRACE_WriteReg32(CSTF_CONTROL, 0, 0);
      TRACE_WriteReg32(CSTF_CONTROL, 1, 0);
      break;
    case Trace_L2CoproHWLogMode:
      if (TRACE_ReadReg32(CSTF_CONTROL, 1) & ENABLE_SLAVE_PORT0)
      // Will Turn off all the other funnel setting
      TRACE_WriteReg32(CSTF_CONTROL, 1, ENABLE_SLAVE_PORT1);
      break;
    case Trace_L2CoproHWLogMode_FlushEnable: //test only
      //Enable Test Mode for L2 HW Log testing!
      TRACE_WriteReg32(DNT_MISC_CTRL, 1, SW_FLUSH_EN); // Disable STP flush function
      TRACE_WriteReg32(CSTF_CONTROL, 1, ENABLE_SLAVE_PORT7 | ENABLE_SLAVE_PORT1);
      break;
    case Trace_3G_Logger0: // 3G L2 Copro Log
      TRACE_WriteReg32(CSTF_CONTROL, 1, TRACE_ReadReg32(CSTF_CONTROL, 1) | ENABLE_SLAVE_PORT5 | ENABLE_SLAVE_PORT7);
      break;
    case Trace_3G_Logger1: // 3G Log
      TRACE_WriteReg32(CSTF_CONTROL, 1, TRACE_ReadReg32(CSTF_CONTROL, 1) | ENABLE_SLAVE_PORT6 | ENABLE_SLAVE_PORT7);
      break;
	case Trace_Flush_Master: 
      TRACE_WriteReg32(CSTF_CONTROL, 1, TRACE_ReadReg32(CSTF_CONTROL, 1) | ENABLE_SLAVE_PORT7);
      break; 
     default:
      break;
  }


  
  MISC_CoreSight_Module_Lock(TRACE_FUNNEL, 0);
  MISC_CoreSight_Module_Lock(TRACE_FUNNEL, 1);

  return 0;
}


// ----------------------------------------------------------
/**
 *  @brief Trace Funnel Off for specific function
 * @param  Trace_Mode :  Trace_ADCC_Mode for capture mode, 
 *                       Trace_ADCP_Mode for playback mode
 * @retval 0 Successful
 * @retval 1 Fail
 */
kal_uint32 drv_dnt_funnel_close(eTrace_mode Trace_Mode)
{
  //CH0
  //0 : ADCC
  //1 : x
  //2 : x
  //3 : patgen0
  //4 : patgen1
  //5 : x
  //6 : x 
  //7 : flush master

  //CH1
  //0 : ADCC
  //1 : L2C
  //2 : DSP
  //3 : patgen0
  //4 : patgen1
  //5 : 3g_0
  //6 : 3g_1 
  //7 : flush master
  

  MISC_CoreSight_Module_Unlock(TRACE_FUNNEL, 0);
  MISC_CoreSight_Module_Unlock(TRACE_FUNNEL, 1);

  switch (Trace_Mode)
  {
    case Trace_ADCC_Mode:
      // Will Turn Off all the other funnel setting
      TRACE_WriteReg32(CSTF_CONTROL, 0, 0);
      TRACE_WriteReg32(CSTF_CONTROL, 1, 0);
      break;
    case Trace_ADCP_Mode:
      // do nothing
      break;
    case Trace_L2CoproHWLogMode:
      TRACE_WriteReg32(CSTF_CONTROL, 1, 0);
      break;
    case Trace_L2CoproHWLogMode_FlushEnable: //test only
      TRACE_WriteReg32(DNT_MISC_CTRL, 1, 0);
      TRACE_WriteReg32(CSTF_CONTROL, 1, 0);
      break;
    case Trace_3G_Logger0:
      TRACE_WriteReg32(CSTF_CONTROL, 1, TRACE_ReadReg32(CSTF_CONTROL, 1) & (~(ENABLE_SLAVE_PORT5 | ENABLE_SLAVE_PORT7)));
      break;
    case Trace_3G_Logger1:
      TRACE_WriteReg32(CSTF_CONTROL, 1, TRACE_ReadReg32(CSTF_CONTROL, 1) & (~(ENABLE_SLAVE_PORT6 | ENABLE_SLAVE_PORT7)));
      break;
    case Trace_Flush_Master: 
      TRACE_WriteReg32(CSTF_CONTROL, 1, TRACE_ReadReg32(CSTF_CONTROL, 1) & ~ENABLE_SLAVE_PORT7);      
      break;
    default:
      break;
  }


  
  MISC_CoreSight_Module_Lock(TRACE_FUNNEL, 0);
  MISC_CoreSight_Module_Lock(TRACE_FUNNEL, 1);
  
  return 0;
}


// ----------------------------------------------------------
/**
 * @brief Used to start ADC Capturing
 * @param  ADCC_Capture_Mode :  ADCC_52MHZ for 52MHz sampling rate, 
 *                              ADCC_30720KHZ for 30.72MHz sampling rate, 
 *                              ADCC_15360KHZ for 15.36MHz sampling rate, 
 *                              ADCC_7680KHZ for 7.68MHz sampling rate, 
 *                              ADCC_3840KHZ for for 3.84MHz sampling rate, 
 */
void drv_adcc_start(eADCC_Capture_Mode ADCC_Capture_Mode)
{
//#define ATID_ADCC_DATA 1 //16
//#define ATID_ADCC_FM   2 //17


#if ADCC_SOURCE == ADCC_SOURCE_ADCC

  kal_uint32 dnt_path;
  for (dnt_path = 0; dnt_path < 2; dnt_path++)
  {
    //=== 1 Setup ADCC ATID ===
    ADCC_WriteReg32(ADCC_CTRL, dnt_path, ((ATID_ADCC_DATA << ADCC_ATID_SHIFT) & ADCC_ATID_MASK));
    
    //=== 2 Setup FRAME MARKER ATID ===
    ADCC_WriteReg32(FRAME_GEN_ATID, dnt_path, (ATID_ADCC_FM& ATID_FRAME_GEN_MASK));
  
    //=== 3 Frame Marker generator enable, and set interval ===
    ADCC_WriteReg32(FRAME_GEN_CTRL, dnt_path, FRAME_GEN_EN | (52000 & FRAME_GEN_INTERVAL_MASK)); // 52MHZ , 1ms
    
    //=== 4 ADCC burst type, enable ADCC ===
    ADCC_WriteReg32(ADCC_CTRL, dnt_path, ADCC_ReadReg32(ADCC_CTRL, dnt_path) | ADCC_OVERFLOW_STOP_EN | ADCC_EN);
  
    //=== 5. Trigger ADCC Source ===
    ADCC_WriteReg32(DUMMY_TRACE_INIT_VALUE, dnt_path, 0x00000000);
    ADCC_WriteReg32(DUMMY_TRACE_INC_VALUE, dnt_path, 0x00000001);
    ADCC_WriteReg32(DUMMY_TRACE_CTRL, dnt_path, DUMMY_TRACE_INC_PAT | DUMMY_TRACE_INIT);
    ADCC_WriteReg32(DUMMY_TRACE_CTRL, dnt_path, DUMMY_TRACE_INC_PAT | DUMMY_TRACE_EN);
  }
  
#elif ADCC_SOURCE == ADCC_SOURCE_RXDFE_STUB  

  //=== 0 Block The ADC Data in  ===
  // Switch to test mode to block the adc data!!
  // cause the RXDFE_ADCC_ENABLE only take effect for test mode (rxdfe test pattern)
  // otherwise, the adc data will keep on coming into ADCC if we just write "0" to this register
  RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_52000);

  //=== 1 Setup ADCC ATID ===
  ADCC_WriteReg32(ADCC_CTRL, 0, ((ATID_ADCC_DATA << ADCC_ATID_SHIFT) & ADCC_ATID_MASK));
  ADCC_WriteReg32(ADCC_CTRL, 1, ((ATID_ADCC_DATA << ADCC_ATID_SHIFT) & ADCC_ATID_MASK));
  
  //=== 2 Setup FRAME MARKER ATID ===
  ADCC_WriteReg32(FRAME_GEN_ATID, 0, (ATID_ADCC_FM & ATID_FRAME_GEN_MASK));
  ADCC_WriteReg32(FRAME_GEN_ATID, 1, (ATID_ADCC_FM & ATID_FRAME_GEN_MASK));
  
  //=== 3 ADCC burst type, enable ADCC ===
  ADCC_WriteReg32(ADCC_CTRL, 0, ADCC_ReadReg32(ADCC_CTRL, 0) | ADCC_OVERFLOW_STOP_EN | ADCC_EN);
  ADCC_WriteReg32(ADCC_CTRL, 1, ADCC_ReadReg32(ADCC_CTRL, 1) | ADCC_OVERFLOW_STOP_EN | ADCC_EN);  

  //=== 4 Frame Marker generator enable, and set interval ===
  //ADCC_WriteReg32(FRAME_GEN_CTRL, 0, FRAME_GEN_EN | (52000 & FRAME_GEN_INTERVAL_MASK)); // 52MHZ , 1ms
  //ADCC_WriteReg32(FRAME_GEN_CTRL, 1, FRAME_GEN_EN | (52000 & FRAME_GEN_INTERVAL_MASK)); // 52MHZ , 1ms
  //ADCC_WriteReg32(FRAME_GEN_CTRL, 0, FRAME_GEN_EN | (32 & FRAME_GEN_INTERVAL_MASK)); // 52MHZ , 1ms
  //ADCC_WriteReg32(FRAME_GEN_CTRL, 1, FRAME_GEN_EN | (32 & FRAME_GEN_INTERVAL_MASK)); // 52MHZ , 1ms
  switch (ADCC_Capture_Mode)
  {
    case ADCC_52MHZ:
      #if 1
      ADCC_WriteReg32(FRAME_GEN_CTRL, 0, FRAME_GEN_EN | (52000 & FRAME_GEN_INTERVAL_MASK)); // 52MHZ , 1ms
      ADCC_WriteReg32(FRAME_GEN_CTRL, 1, FRAME_GEN_EN | (52000 & FRAME_GEN_INTERVAL_MASK)); // 52MHZ , 1ms
      #else
/* under construction !*/
/* under construction !*/
      #endif
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, RXDFE_ADCCP_SW_RST);
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_52000 | RXDFE_DATA_FORMAT_IQ | RXDFE_ADCCP_FM_4096);
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_52000 | RXDFE_ADCC_ENABLE | RXDFE_DATA_FORMAT_IQ | RXDFE_ADCCP_FM_4096);
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_52000 | RXDFE_DATA_FORMAT_IQ);
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_52000 | RXDFE_ADCC_ENABLE | RXDFE_DATA_FORMAT_IQ);
      break;

    case ADCC_30720KHZ:
      ADCC_WriteReg32(FRAME_GEN_CTRL, 0, FRAME_GEN_EN | (30720 & FRAME_GEN_INTERVAL_MASK)); // 1ms
      ADCC_WriteReg32(FRAME_GEN_CTRL, 1, FRAME_GEN_EN | (30720 & FRAME_GEN_INTERVAL_MASK)); // 1ms
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, RXDFE_ADCCP_SW_RST);
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_30720 | RXDFE_DATA_FORMAT_IQ | RXDFE_ADCCP_FM_4096);
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_30720 | RXDFE_ADCC_ENABLE | RXDFE_DATA_FORMAT_IQ | RXDFE_ADCCP_FM_4096);
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_30720 | RXDFE_DATA_FORMAT_IQ);
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_30720 | RXDFE_ADCC_ENABLE | RXDFE_DATA_FORMAT_IQ);
      break;

    case ADCC_15360KHZ:
      ADCC_WriteReg32(FRAME_GEN_CTRL, 0, FRAME_GEN_EN | (15360 & FRAME_GEN_INTERVAL_MASK)); // 1ms
      ADCC_WriteReg32(FRAME_GEN_CTRL, 1, FRAME_GEN_EN | (15360 & FRAME_GEN_INTERVAL_MASK)); // 1ms    
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, RXDFE_ADCCP_SW_RST);
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_15360 | RXDFE_DATA_FORMAT_IQ | RXDFE_ADCCP_FM_4096);
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_15360 | RXDFE_ADCC_ENABLE | RXDFE_DATA_FORMAT_IQ | RXDFE_ADCCP_FM_4096);
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_15360 | RXDFE_DATA_FORMAT_IQ);
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_15360 | RXDFE_ADCC_ENABLE | RXDFE_DATA_FORMAT_IQ);
      break;

    case ADCC_7680KHZ:
      ADCC_WriteReg32(FRAME_GEN_CTRL, 0, FRAME_GEN_EN | (7680 & FRAME_GEN_INTERVAL_MASK)); // 1ms
      ADCC_WriteReg32(FRAME_GEN_CTRL, 1, FRAME_GEN_EN | (7680 & FRAME_GEN_INTERVAL_MASK)); // 1ms    
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, RXDFE_ADCCP_SW_RST);
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_7680 | RXDFE_DATA_FORMAT_IQ | RXDFE_ADCCP_FM_4096);
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_7680 | RXDFE_ADCC_ENABLE | RXDFE_DATA_FORMAT_IQ | RXDFE_ADCCP_FM_4096);
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_7680 | RXDFE_DATA_FORMAT_IQ);
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_7680 | RXDFE_ADCC_ENABLE | RXDFE_DATA_FORMAT_IQ);
      break;

    case ADCC_3840KHZ:
      ADCC_WriteReg32(FRAME_GEN_CTRL, 0, FRAME_GEN_EN | (3840 & FRAME_GEN_INTERVAL_MASK)); // 1ms
      ADCC_WriteReg32(FRAME_GEN_CTRL, 1, FRAME_GEN_EN | (3840 & FRAME_GEN_INTERVAL_MASK)); // 1ms      
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, RXDFE_ADCCP_SW_RST);
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_3840 | RXDFE_DATA_FORMAT_IQ | RXDFE_ADCCP_FM_4096);
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_3840 | RXDFE_ADCC_ENABLE | RXDFE_DATA_FORMAT_IQ | RXDFE_ADCCP_FM_4096);
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_3840 | RXDFE_DATA_FORMAT_IQ);
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_3840 | RXDFE_ADCC_ENABLE | RXDFE_DATA_FORMAT_IQ);      
      break;

    case ADCC_1920KHZ:
      ADCC_WriteReg32(FRAME_GEN_CTRL, 0, FRAME_GEN_EN | (1920 & FRAME_GEN_INTERVAL_MASK)); // 1ms
      ADCC_WriteReg32(FRAME_GEN_CTRL, 1, FRAME_GEN_EN | (1920 & FRAME_GEN_INTERVAL_MASK)); // 1ms    
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, RXDFE_ADCCP_SW_RST);
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_1920 | RXDFE_DATA_FORMAT_IQ | RXDFE_ADCCP_FM_4096);
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_1920 | RXDFE_ADCC_ENABLE | RXDFE_DATA_FORMAT_IQ | RXDFE_ADCCP_FM_4096);    
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_1920 | RXDFE_DATA_FORMAT_IQ);
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_1920 | RXDFE_ADCC_ENABLE | RXDFE_DATA_FORMAT_IQ);          
      break;

#ifndef __FPGA__
    case ADCC_SINTONE_TEST_PATTERN: // 30.72MHz
         
      ADCC_WriteReg32(FRAME_GEN_CTRL, 0, FRAME_GEN_EN | (30720 & FRAME_GEN_INTERVAL_MASK)); // 30.72MHZ , 1ms
      ADCC_WriteReg32(FRAME_GEN_CTRL, 1, FRAME_GEN_EN | (30720 & FRAME_GEN_INTERVAL_MASK)); // 30.72MHZ , 1ms

      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, RXDFE_ADCCP_FM_4096 | CAPTURE_TEST_MODE_52000);
    
      RXDFE_WriteReg32(FMC_MML1_PHYTIMER_BWSW_2, 0x0025);
      RXDFE_WriteReg32(FMC_MML1_PHYTIMER_START,  0x0001);
    
      RXDFE_WriteReg32(FMC_MML1_PHYCK_26MCFG, 0x0000);
    
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_CS_DAGC_RX1, 0x8040);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_CS_DAGC_RX2, 0x8040);
    
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_CE_DAGC_RX1, 0x8168);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_CE_DAGC_RX2, 0x8168);
    
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_IQ1_GAIN, 0x0400);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_IQ2_GAIN, 0x0400);
    
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_TEST_CTRL, 0x1111);
    
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_CTRL, 0x00008530);//test_mode[15], en_win_mode[10], sym_num_pre[8], rx2_en[5], rx1_en[4]
    
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_CONFIG, 0x00006100);//clk_mode[14], vld_mode[13], dc_mode[8]
      
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, RXDFE_ADCCP_SW_RST);
      
    
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_BIT_MAP,   0x3FFF);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_SYM_LEN1,  4416);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_SYM_LEN2,  4384);
    
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_FIR24_T0,  0x3F02);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_FIR24_T1,  0x3E3E);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_FIR24_T2,  0x0200);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_FIR24_T3,  0x3D01);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_FIR24_T4,  0x013B);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_FIR24_T5,  0x170D);
    
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_DCO1_I,    0x1F);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_DCO1_Q,    0x1F);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_DCO2_I,    0x1F);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_DCO2_Q,    0x1F);
    
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_FOE_LSB,   0x8000);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_FOE_MSB,   0x0000); //[5:0]
    
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_RAMP_UP,   160);
      
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_ON_LSB,    960);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_ON_MSB,    0x8000);

      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_SFRM1,     19200);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_SFRM2,     19200);
      
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_DCO_SFRM1, 480);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_NCO_SFRM1, 480);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_DCO_SFRM2, 320);
      RXDFE_WriteReg32(FMC_LTEL1_RXDFE_NCO_SFRM2, 320);  
      //RXDFE_WriteReg32(FMC_LTEL1_RXDFE_SFRM1,     1920);
      //RXDFE_WriteReg32(FMC_LTEL1_RXDFE_SFRM2,     1920);

      
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, RXDFE_ADCCP_FM_4096 | RXDFE_ADCC_ENABLE | CAPTURE_FROM_DFE_OUTPUT);
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, RXDFE_ADCC_ENABLE | CAPTURE_FROM_DFE_OUTPUT);
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, RXDFE_ADCC_ENABLE | CAPTURE_FROM_DFE_OUTPUT);
      break;
#endif

    case ADCC_RealADC_CAPTURE_FROM_DFE_INPUT: // 52MHz
    
      ADCC_WriteReg32(FRAME_GEN_CTRL, 0, FRAME_GEN_EN | (52000 & FRAME_GEN_INTERVAL_MASK)); // 52MHZ , 1ms
      ADCC_WriteReg32(FRAME_GEN_CTRL, 1, FRAME_GEN_EN | (52000 & FRAME_GEN_INTERVAL_MASK)); // 52MHZ , 1ms
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, RXDFE_ADCCP_SW_RST);
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_FROM_DFE_INPUT | RXDFE_DATA_FORMAT_IQ | RXDFE_ADCCP_FM_4096);
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_FROM_DFE_INPUT | RXDFE_ADCC_ENABLE | RXDFE_DATA_FORMAT_IQ | RXDFE_ADCCP_FM_4096);
      dnt_delay_us(1);
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_FROM_DFE_INPUT | RXDFE_ADCC_ENABLE | RXDFE_DATA_FORMAT_IQ);
      break;

    case ADCC_RealADC_CAPTURE_FROM_DFE_OUTPUT: // sampling rate depends on the DSP's setting
     
      ADCC_WriteReg32(FRAME_GEN_CTRL, 0, FRAME_GEN_EN | (30720 & FRAME_GEN_INTERVAL_MASK)); // 52MHZ , 1ms
      ADCC_WriteReg32(FRAME_GEN_CTRL, 1, FRAME_GEN_EN | (30720 & FRAME_GEN_INTERVAL_MASK)); // 52MHZ , 1ms
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, RXDFE_ADCCP_SW_RST);
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_FROM_DFE_OUTPUT | RXDFE_DATA_FORMAT_IQ | RXDFE_ADCCP_FM_4096);
      //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_FROM_DFE_OUTPUT | RXDFE_ADCC_ENABLE | RXDFE_DATA_FORMAT_IQ | RXDFE_ADCCP_FM_4096);
      dnt_delay_us(1);
      RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, ADCC_OPT_SEL_AFTER_AGC | CAPTURE_FROM_DFE_OUTPUT | RXDFE_ADCC_ENABLE | RXDFE_DATA_FORMAT_IQ);
      break;

    default:
      ASSERT(KAL_FALSE);
      break;
  }

  
#elif ADCC_SOURCE == ADCC_SOURCE_RXDFE

  switch (ADCC_Capture_Mode)
  {
    case ADCC_52MHZ:
      break;

    case ADCC_30720KHZ:
      break;

    case ADCC_15360KHZ:
      break;

    case ADCC_7680KHZ:
      break;

    case ADCC_3840KHZ:
      break;

    default:
      ASSERT(KAL_FALSE);
      break;
  }

#else
  ASSERT(KAL_FALSE);
#endif

}

// ----------------------------------------------------------
/**
 * @brief Used to stop ADC Capturing
 */
void drv_adcc_stop(void)
{

  drv_rstctl_sw_reset(RST_TRACE);

#if ADCC_SOURCE == ADCC_SOURCE_ADCC
  ADCC_WriteReg32(DUMMY_TRACE_CTRL, 0, 0);
  ADCC_WriteReg32(DUMMY_TRACE_CTRL, 1, 0);
#elif ADCC_SOURCE == ADCC_SOURCE_RXDFE_STUB
  RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, 0);
  RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, RXDFE_ADCCP_SW_RST);
  // Switch to test mode to block the adc data!!
  // cause the RXDFE_ADCC_ENABLE only take effect for test mode (rxdfe test pattern)
  // otherwise, the adc data will keep on coming into ADCC if we just write "0" to this register
  RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, CAPTURE_TEST_MODE_52000); 
  //RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, 0);
#elif ADCC_SOURCE == ADCC_SOURCE_RXDFE
#endif

  drv_rstctl_sw_reset(RST_TRACE);

  DRV_WriteReg32(ADCP_PHY_SW_RESET, ADCP_PHY_RESET);
  dnt_delay_us(10);
  DRV_WriteReg32(ADCP_PHY_SW_RESET, 0x00);
  dnt_delay_us(10);

#ifdef CNP_PARKING_IOMUX_TO_GPIO_INPUT_MODE
  //Parking share pin to GPIO input mode
  CNP_iomux_parking();
#endif  

}

// ----------------------------------------------------------
/**
 * @brief Used to query ADCC status
 * @param  ADCC_Query_Type :  ADCC_Query_FIFO_Status for query FIFO status, 
 *                            ADCC_Query_CH1_Data_Drop_Counter for query CH1 's data drop count
 *                            ADCC_Query_CH2_Data_Drop_Counter for query CH2 's data drop count
 */
kal_uint32 drv_adcc_status(eADCC_Query_Type ADCC_Query_Type)
{
  kal_uint32 ret_val = 0;

  switch (ADCC_Query_Type)
  {
    case ADCC_Query_FIFO_Status:
      ret_val =  ((ADCC_ReadReg32(ADCC_CTRL, 0) & ADCC_OVERFLOW) ? 0x01 : 0);
      ret_val |= ((ADCC_ReadReg32(ADCC_CTRL, 1) & ADCC_OVERFLOW) ? 0x02 : 0);
      break;
      
    case ADCC_Query_CH1_Data_Drop_Counter:
      ret_val = ADCC_ReadReg32(ADCC_OVL_CNT, 0);
      break;

    case ADCC_Query_CH2_Data_Drop_Counter:
      ret_val = ADCC_ReadReg32(ADCC_OVL_CNT, 1);
      break;

    default:
      ASSERT(KAL_FALSE);
      break;
  }

  return ret_val;
}

// ----------------------------------------------------------
/**
 * @brief Used to start ADC Playback
 */
void drv_adcp_start(void)
{
  kal_uint32 dnt_path;
  
  for (dnt_path = 0; dnt_path < 2; dnt_path++)
  {
    ADCP_AP_WriteReg32(ADCP_AP_CTRL, dnt_path, RX_CK_POLARITY_INVERSION);
  
    ADCP_PHY_WriteReg32(ADCP_PHY_MONITOR_FIFO_CTRL, dnt_path, PB_MONITOR_EN);
#ifdef __FPGA__  
    ADCP_AP_WriteReg32(ADCP_AP_CTRL, dnt_path, RX_CK_POLARITY_INVERSION | PLAYBACK_AP_EN);
#else
    //ADCP_AP_WriteReg32(ADCP_AP_CTRL, dnt_path, dnt_path?(RX_CK_POLARITY_INVERSION | PLAYBACK_AP_EN):(PLAYBACK_AP_EN));
    ADCP_AP_WriteReg32(ADCP_AP_CTRL, dnt_path, PLAYBACK_AP_EN);
#endif
  
    ADCP_PHY_WriteReg32(ADCP_PHY_START_THRESHOLD, dnt_path, START_THRESHOLD_2);
  
    ADCP_PHY_WriteReg32(ADCP_PHY_CTRL, dnt_path, PLAYBACK_PHY_EN);
  }
}

// ----------------------------------------------------------
/**
 * @brief Used to Stop ADC Playback
 */
void drv_adcp_stop(void)
{
  
  ADCP_PHY_WriteReg32(ADCP_PHY_SMD_STATUS, 0, 0); // disable compare circuit for SIB counter data
  ADCP_PHY_WriteReg32(ADCP_PHY_SMD_STATUS, 1, 0); // disable compare circuit for SIB counter data

  ADCP_PHY_WriteReg32(ADCP_PHY_CTRL, 0, 0);
  ADCP_PHY_WriteReg32(ADCP_PHY_CTRL, 1, 0);

  ADCP_AP_WriteReg32(ADCP_AP_CTRL, 0, 0);
  ADCP_AP_WriteReg32(ADCP_AP_CTRL, 1, 0);

  ADCP_AP_WriteReg32(ADCP_AP_SIBPATGEN_CTRL, 0, 0);
  ADCP_AP_WriteReg32(ADCP_AP_SIBPATGEN_CTRL, 1, 0);


  drv_rstctl_sw_reset(RST_TRACE);

  DRV_WriteReg32(ADCP_PHY_SW_RESET, ADCP_PHY_RESET);
  dnt_delay_us(10);
  DRV_WriteReg32(ADCP_PHY_SW_RESET, 0x00);
  dnt_delay_us(10);

  RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, RXDFE_ADCCP_SW_RST);
  RXDFE_WriteReg32(RXDFE_ADCP_PB_MODE, 0);

#ifdef CNP_PARKING_IOMUX_TO_GPIO_INPUT_MODE
  //Parking share pin to GPIO input mode
  CNP_iomux_parking();
#endif  
}

// ----------------------------------------------------------
/**
 * @brief Used to query ADCP status
 * @param  eADCP_Query_Type : ADCP_Query_Playback_Status,
                                  bit 0:1 : 00 => IDLE
                                            01 => WAITING (to start playback)
                                            02 => PLAYING
                                            03 => STOP (normarl or abnormal)
                                  bit 4   : Channel 1's PHY FIFO underrun
                                  bit 5   : Channel 1's AP FIFO overflow
                                  bit 6   : Channel 1's AP FIFO underrun
                                  bit 7   : Channel 1   AP detect CRC error
                                  bit 8   : Channel 2's PHY FIFO overflow
                                  bit 9   : Channel 2's AP FIFO overflow
                                  bit 10  : Channel 2's AP FIFO underrun    
                                  bit 11  : Channel 2   AP detect CRC error
                                  bit 12  : RXDFE detect asyc playback status
                              ADCP_Query_CH1_Data_Counter,
                              ADCP_Query_CH2_Data_Counter,
                              ADCP_Query_CH1_CRC_CheckSum,
                              ADCP_Query_CH2_CRC_CheckSum
 */

kal_int32 drv_adcp_status(eADCP_Query_Type ADCP_Query_Type)
{
  kal_uint32 ret_val = 0;
  switch (ADCP_Query_Type)
  {
    case ADCP_Query_Playback_Status:
      //bit 01  : Playback Status
      if ((ADCP_PHY_ReadReg32(ADCP_PHY_CTRL, 0) & PLAYBACK_STATUS) && (ADCP_PHY_ReadReg32(ADCP_PHY_CTRL, 1) & PLAYBACK_STATUS))
      {
        ret_val |= ADCP_PB_STATUS_PLAYING;
      }
      else if ((ADCP_PHY_ReadReg32(ADCP_PHY_CTRL, 0) & PLAYBACK_STATUS) || (ADCP_PHY_ReadReg32(ADCP_PHY_CTRL, 1) & PLAYBACK_STATUS))
      {
        // Abnormal!
        ret_val |= ADCP_PB_STATUS_PLAYING;
      }
      else if ((ADCP_PHY_ReadReg32(ADCP_PHY_CTRL, 0) & PLAYBACK_PHY_EN) && (ADCP_PHY_ReadReg32(ADCP_PHY_CTRL, 1) & PLAYBACK_PHY_EN))
      {
        if ((ADCP_PHY_ReadReg32(ADCP_PHY_CTRL, 0) & PLAYBACK_PHY_UNDERFLOW) ||
            (ADCP_PHY_ReadReg32(ADCP_PHY_CTRL, 1) & PLAYBACK_PHY_UNDERFLOW) ||
            (ADCP_AP_ReadReg32(ADCP_AP_CTRL, 0) & (PLAYBACK_CRC_ERROR | PLAYBACK_AP_UNDERFLOW | PLAYBACK_AP_OVERFLOW)) ||
            (ADCP_AP_ReadReg32(ADCP_AP_CTRL, 1) & (PLAYBACK_CRC_ERROR | PLAYBACK_AP_UNDERFLOW | PLAYBACK_AP_OVERFLOW)) )
        {
          ret_val |= ADCP_PB_STATUS_STOP;
        }
        else
        {
          ret_val |= ADCP_PB_STATUS_WAITING;
        }
      }
      else
      {
        ret_val |= ADCP_PB_STATUS_IDLE;
      }
      
      //bit 4   : Channel 1's PHY FIFO underrun
      if (ADCP_PHY_ReadReg32(ADCP_PHY_CTRL, 0) & PLAYBACK_PHY_UNDERFLOW)
      {
       ret_val |= ADCP_PB_CH1_PHY_UNDERRUN;
      }
      //bit 5   : Channel 1's AP FIFO overflow
      if (ADCP_AP_ReadReg32(ADCP_AP_CTRL, 0) & PLAYBACK_AP_OVERFLOW)
      {
       ret_val |= ADCP_PB_AP_CH1_OVERFLOW;
      }      
      //bit 6   : Channel 1's AP FIFO underrun
      if (ADCP_AP_ReadReg32(ADCP_AP_CTRL, 0) & PLAYBACK_AP_UNDERFLOW)
      {
       ret_val |= ADCP_PB_AP_CH1_UNDERRUN;
      }    
      //bit 7   : Channel 1   AP detect CRC error
      if (ADCP_AP_ReadReg32(ADCP_AP_CTRL, 0) & PLAYBACK_CRC_ERROR)
      {
       ret_val |= ADCP_PB_AP_CH1_PHY_CRC_ERR;
      }   

      //bit 8   : Channel 2's PHY FIFO overflow
      if (ADCP_PHY_ReadReg32(ADCP_PHY_CTRL, 1) & PLAYBACK_PHY_UNDERFLOW)
      {
       ret_val |= ADCP_PB_CH2_PHY_UNDERRUN;
      }
      //bit 9   : Channel 2's AP FIFO overflow
      if (ADCP_AP_ReadReg32(ADCP_AP_CTRL, 1) & PLAYBACK_AP_OVERFLOW)
      {
       ret_val |= ADCP_PB_AP_CH2_OVERFLOW;
      }     
      //bit 10   : Channel 2's AP FIFO underrun
      if (ADCP_AP_ReadReg32(ADCP_AP_CTRL, 1) & PLAYBACK_AP_UNDERFLOW)
      {
       ret_val |= ADCP_PB_AP_CH2_UNDERRUN;
      }    
      //bit 11   : Channel 2   AP detect CRC error
      if (ADCP_AP_ReadReg32(ADCP_AP_CTRL, 1) & PLAYBACK_CRC_ERROR)
      {
       ret_val |= ADCP_PB_AP_CH2_PHY_CRC_ERR;
      }   
      //bit 12   : RXDFE detect asyc playback status
      if ((RXDFE_ReadReg32(RXDFE_ADCP_SYNC_IDR) & PATH1_PATH2_SYNC_STAUTS) == PATH1_PATH2_UNSYNC)
      {
       ret_val |= ADCP_PB_RXDFE_ASYNC_STATUS;
      }   

      
      break;
      
    case ADCP_Query_CH1_Data_Counter:
      ret_val = RXDFE_ReadReg32(RXDFE_DATA1_CNT_LSB) + (RXDFE_ReadReg32(RXDFE_DATA1_CNT_MSB) << 16);
      break;
      
    case ADCP_Query_CH2_Data_Counter:
      ret_val = RXDFE_ReadReg32(RXDFE_DATA2_CNT_LSB) + (RXDFE_ReadReg32(RXDFE_DATA2_CNT_MSB) << 16);
      break;
      
    case ADCP_Query_CH1_CRC_CheckSum:
      ret_val = RXDFE_ReadReg32(RXDFE_CHECK_SUM1_LSB) + (RXDFE_ReadReg32(RXDFE_CHECK_SUM1_MSB) << 16);
      break;
      
    case ADCP_Query_CH2_CRC_CheckSum:
      ret_val = RXDFE_ReadReg32(RXDFE_CHECK_SUM2_LSB) + (RXDFE_ReadReg32(RXDFE_CHECK_SUM2_MSB) << 16);
      break;
      
    default:
      ASSERT(KAL_FALSE);
      break;
      
  }

  return ret_val;
}

// ----------------------------------------------------------
/**
 * @brief Used to query ADCP status
 * @param  Trace_Mode :  Trace_ADCC_Mode for capture mode, 
 *                       Trace_ADCP_Mode for playback mode
 * @param  Pattern    :  Test Pattern selection 
 */

void drv_cnp_serdes_test_init(eTrace_mode Trace_Mode, kal_uint32 Pattern)
{
  kal_uint32 dnt_path;
  kal_uint32 pattern_config[10][5] = {
      {0x0000, 0xFFFF,      0,      0,      0},
      {0x0002,      0, 0xFFFF,      0,      0},
      {0x0004,      0,      0, 0xFFFF,      0},
      {0x0008,      0,      0,      0, 0xFFFF},
      {0x0005, 0xFFFF,      0, 0x0000,      0},
      {0x000A,      0, 0xAAAA,      0, 0x5555},
      {0x0007, 0xFFFF, 0x5555, 0xAAAA,      0},
      {0x000E,      0, 0x5555, 0xAAAA, 0xFFFF},
      {0x000B, 0xFFFF, 0x5555,      0, 0xFFFF},
      {0x000F, 0xFFFF, 0x5555, 0xAAAA, 0x8888},
  };
  
  kal_uint32 playback_pattern_config[4][4] = {
      {0x15AF0, 0x1A50F, 0x10F5A, 0x1F0A5},
      {0x15AF0, 0x1A50F, 0x10F5A, 0x00000},
      {0x1FFFF, 0x10000, 0x1AAAA, 0x00000},
      {0x15AF0, 0x1A50F, 0x15AF0, 0x1A50F},
  };  
  
  drv_adcc_stop();
  drv_adcp_stop();

  if (Trace_Mode != Trace_ADCP_Mode)
  {
    //CNP_iomux_sel(Trace_ADCC_Mode);
    
    TRACE_WriteReg32(SERDES_BOARD_CTRL, 0, (TRACE_ReadReg32(SERDES_BOARD_CTRL, 0) & (~LCKREFN))); // path 0/1 are both connected to path0's LCKREFN


    for (dnt_path = 0; dnt_path < 2; dnt_path++)
    {
      MISC_CoreSight_Module_Unlock(STP_BASE_ADDRESS, dnt_path);

      TRACE_WriteReg32(STP_CONTROL_REG, dnt_path, 0);
      TRACE_WriteReg32(STP_PG_TEST_0, dnt_path, (pattern_config[Pattern][0] & 0x01)? (0x0010000 | pattern_config[Pattern][1]) : 0);
      TRACE_WriteReg32(STP_PG_TEST_1, dnt_path, (pattern_config[Pattern][0] & 0x02)? (0x0010000 | pattern_config[Pattern][2]) : 0);
      TRACE_WriteReg32(STP_PG_TEST_2, dnt_path, (pattern_config[Pattern][0] & 0x04)? (0x0010000 | pattern_config[Pattern][3]) : 0);
      TRACE_WriteReg32(STP_PG_TEST_3, dnt_path, (pattern_config[Pattern][0] & 0x08)? (0x0010000 | pattern_config[Pattern][4]) : 0);
      TRACE_WriteReg32(DNT_MONITOR_MEM_CTRL, dnt_path, MONITOR_FULL_STOP_EN | MONITOR_WPTR_CLR);
      TRACE_WriteReg32(STP_CONTROL_REG, dnt_path, STP_ENA | PG_ENA);

      MISC_CoreSight_Module_Lock(STP_BASE_ADDRESS, dnt_path);
    }

  
  }
  else
  {
    drv_dnt_init(DNT_MODE_ADCP);

    //CNP_iomux_sel(Trace_ADCP_Mode);

    for (dnt_path = 0; dnt_path < 2; dnt_path++)
    {
      // 1. Unlock STP
      MISC_CoreSight_Module_Unlock(STP_BASE_ADDRESS, dnt_path);

      MISC_CoreSight_Module_Unlock(TPIU_BASE_ADDRESS, dnt_path);

      ADCP_AP_WriteReg32(ADCP_AP_CTRL, dnt_path, RX_CK_POLARITY_INVERSION);

      ADCP_AP_WriteReg32(ADCP_AP_PATGEN0, dnt_path, playback_pattern_config[Pattern][0]);
      ADCP_AP_WriteReg32(ADCP_AP_PATGEN1, dnt_path, playback_pattern_config[Pattern][1]);
      ADCP_AP_WriteReg32(ADCP_AP_PATGEN2, dnt_path, playback_pattern_config[Pattern][2]);
      ADCP_AP_WriteReg32(ADCP_AP_PATGEN3, dnt_path, playback_pattern_config[Pattern][3]);
      ADCP_AP_WriteReg32(ADCP_AP_PATGEN_CTRL, dnt_path, PB_PATGEN_EN);
    }
  }
  
  return;
}

// ----------------------------------------------------------
/**
 * @brief Used to query playback serdes status
 * @param  Ch0_ReceiveCount :  CH0 successfully received data count 
 * @param  Ch1_ReceiveCount :  CH0 successfully received data count 
 * @retval bit 0 : CH 0 had received data or not
 *         bit 1 : CH 0 compared failed
 *         bit 4 : CH 1 had received data or not
 *         bit 5 : CH 1 compared failed 
 */
kal_uint32 drv_query_playback_serdes_test_status(kal_uint32 *Ch0_ReceiveCount, kal_uint32 *Ch1_ReceiveCount)
{
  kal_uint32 ret_val = 0;

  if((ADCP_AP_ReadReg32(ADCP_AP_PATGEN_CTRL, 0) & PB_PATGEN_EN) && (ADCP_AP_ReadReg32(ADCP_AP_PATGEN_CTRL, 0) & PB_PATGEN_RCVCNT_MASK))
  {
    ret_val |= 0x01;
  }
  if((ADCP_AP_ReadReg32(ADCP_AP_PATGEN_CTRL, 1) & PB_PATGEN_EN) && (ADCP_AP_ReadReg32(ADCP_AP_PATGEN_CTRL, 1) & PB_PATGEN_RCVCNT_MASK))
  {
    ret_val |= 0x10;
  }
  
  if ((ADCP_AP_ReadReg32(ADCP_AP_PATGEN_CTRL, 0) & PB_PATGEN_EN) && (ADCP_AP_ReadReg32(ADCP_AP_PATGEN_CTRL, 0) & PB_PATGEN_RCVCNT_FAIL))
  {
    ret_val |= 0x02;
  }
  if ((ADCP_AP_ReadReg32(ADCP_AP_PATGEN_CTRL, 1) & PB_PATGEN_EN) && (ADCP_AP_ReadReg32(ADCP_AP_PATGEN_CTRL, 1) & PB_PATGEN_RCVCNT_FAIL))
  {
    ret_val |= 0x20;
  }
  
  *Ch0_ReceiveCount = (ADCP_AP_ReadReg32(ADCP_AP_PATGEN_CTRL, 0) & PB_PATGEN_RCVCNT_MASK) >> PB_PATGEN_RCVCNT_SHIFT;
  *Ch1_ReceiveCount = (ADCP_AP_ReadReg32(ADCP_AP_PATGEN_CTRL, 1) & PB_PATGEN_RCVCNT_MASK) >> PB_PATGEN_RCVCNT_SHIFT;
  
  return ret_val;
}

// ----------------------------------------------------------
/**
 * @brief Used to configure SATA PHY Frequency
 * @param  eSATA_Frequency : frequency to be configured
 * @retval None
 */
void drv_dnt_set_sata_frequency(eTrace_SATA_Frequency eFrequency)
{
  switch (eFrequency)
  {
    case Trace_SATA_120MHZ:
      break;
      
    case Trace_SATA_122MHZ:
      break;
      
    case Trace_SATA_124MHZ:
      break;
      
    case Trace_SATA_126MHZ:
      break;
      
    case Trace_SATA_128MHZ:
      break;
      
    case Trace_SATA_130MHZ:
    default:
      break;
  }
}


// ----------------------------------------------------------
/**
 * @brief Used to configure BUS1X Clock
 * @param  eSATA_Frequency : frequency to be configured
 * @retval None
 */
void drv_dnt_set_bus1x_frequency(trace_bus1x_clk eBUS1XFrequency)
{
  ASSERT(eBUS1XFrequency <= TRACE_BUS1X_65MHZ); 
  
  
  if (eBUS1XFrequency == TRACE_BUS1X_65MHZ)// configure BUX2X to UNIPLL/5
  {
    DRV_WriteReg32(0xBF810008, (DRV_Reg32(0xBF810008) & 0xFF00FFFF) | 0x00460000);
    dnt_delay_us(50000);
  }
  else
  {
  set_trace_bus1x_clock(eBUS1XFrequency);
    dnt_delay_us(100000);
  }
  
}

#endif // MT6290
