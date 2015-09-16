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
 *   drv_coresight.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   Coresight public API header file
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
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * Patch back MT6595 modification
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
 * [MOLY] Coresight Driver Update for ADC Capture
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
 * Merge Coresight related driver from TATAKA to MOLY trunk
 ****************************************************************************/

#include "pll.h"
//===========================================================================//
//  ATID Setting                                                             //
//===========================================================================//
//*********************************************************************************
//  ATID settings
//*********************************************************************************
#ifdef MT6290
  #define ATID_ADCC_DATA                (0x01)
  #define ATID_ADCC_FM                  (0x02)
  #define ATID_LMU_MDARM                (0x10)
  #define ATID_LMU_FCore4               (0x11)
  #define ATID_LMU_APARM                (0x12)
  #define ATID_LogAcc0                  (0x18)
  #define ATID_LogAcc1                  (0x19)
  #define ATID_Flush_Master             (0x1F)
  #define ATID_2G_Modem_RXBUF           (0x20)
  #define ATID_2G_Modem_EQRAM1          (0x21)
  #define ATID_2G_Modem_EQRAM2          (0x22)
  #define ATID_3G_Modem_MODEM0          (0x30)
  #define ATID_3G_Modem_MODEM1          (0x31)
  #define ATID_3G_Modem_EXTRT           (0x32)
  #define ATID_3G_Modem_SCALER          (0x33)
  #define ATID_L2Copro_DPA_MAC          (0x40)
  #define ATID_L2Copro_DPA_RLC_IM       (0x41)
  #define ATID_L2Copro_DPA_RLC_RO       (0x42)
  #define ATID_L2Copro_DPA_RLC_CTRL     (0x43)
  #define ATID_L2Copro_DPA_RLC_SDU      (0x44)
  #define ATID_L2Copro_UPA_MAC          (0x45)
  #define ATID_L2Copro_UPA_RLC          (0x46)
  //For L2Copro E2
  #define ATID_L2Copro_DPA_RLC_DROP     (0x47)
  #define ATID_L2Copro_DPA_MAC_HS       ATID_L2Copro_DPA_MAC
  #define ATID_L2Copro_DPA_MAC_HS_DROP  (0x48)
  #define ATID_L2Copro_DPA_MAC_D        (0x49)
  #define ATID_L2Copro_DPA_MAC_D_DROP   (0x4A)
  #define ATID_L2Copro_DPA_TS           (0x4B)
  #define ATID_L2Copro_UPA_RLC_AMD      ATID_L2Copro_UPA_RLC
  #define ATID_L2Copro_UPA_RLC_UMD      (0x4C)
  #define ATID_L2Copro_UPA_MAC_SAD      (0x4D)
  #define ATID_L2Copro_UPA_TS           (0x4E)
  #define ATID_ETM_MDARM                (0x50)
  #define ATID_FCore4_HSL_PC            (0x51)
  #define ATID_ETM_APARM                (0x52)
  #define ATID_FCore4_HSL_DATA          (0x53)
  #define ATID_MMSYS                    (0x60)
  //For 4G DSP LOG
  #define LTE_DSPLOG_MSC_CH0            (0x62) //98
  #define LTE_DSPLOG_MSC_CH1            (0x63) //99
  #define LTE_DSPLOG_MD32_CH0           (0x64) //100
  #define LTE_DSPLOG_MD32_CH1           (0x65) //101
  #define LTE_DSPLOG_FMC_CH0            (0x66) //102
  #define LTE_DSPLOG_FMC_CH1            (0x67) //103
  #define LTE_DSPLOG_FNC_CH0            (0x68) //104
  #define LTE_DSPLOG_FNC_CH1            (0x69) //105
  #define LTE_DSPLOG_MC_CH0             (0x6A) //106
  #define LTE_DSPLOG_MC_CH1             (0x6B) //107
  #define LTE_DSPLOG_BC_CH0             (0x6C) //108
  #define LTE_DSPLOG_BC_CH1             (0x6D) //109
  #define LTE_DSPLOG_MMC_CH0            (0x6E) //110
  #define LTE_DSPLOG_MMC_CH1            (0x6F) //111


//===========================================================================//
//  DRV Enum Protype                                                         //
//===========================================================================//

typedef enum {
  Trace_SATA_120MHZ,
  Trace_SATA_122MHZ,
  Trace_SATA_124MHZ,
  Trace_SATA_126MHZ,
  Trace_SATA_128MHZ,
  Trace_SATA_130MHZ
} eTrace_SATA_Frequency;
  
typedef enum {
  DNT_MODE_MD_LOG,
  DNT_MODE_ADCC,
  DNT_MODE_ADCP,
  DNT_MODE_L2Copro_TestMode
} eSIB_Configure_mode;
  
typedef enum {
  Trace_ADCC_Mode,
  Trace_ADCP_Mode,
  Trace_SW_LOG_Mode,
  Trace_L2CoproHWLogMode,
  Trace_L2CoproHWLogMode_FlushEnable, //for test only
  Trace_3G_Logger0, // 3G L2 Co-Pro logger
  Trace_3G_Logger1, // 3G Logger
  Trace_Flush_Master,
} eTrace_mode;

typedef enum {
  ADCC_Query_FIFO_Status,
    // ADCC_Query_FIFO_Status return value definition
    // bit 0 : Channel 1 FIFO overflow
    // bit 1 : Channel 2 FIFO overflow
  ADCC_Query_CH1_Data_Drop_Counter,
  ADCC_Query_CH2_Data_Drop_Counter
} eADCC_Query_Type;

typedef enum {
  ADCC_52MHZ,
  ADCC_30720KHZ,
  ADCC_15360KHZ,
  ADCC_7680KHZ,
  ADCC_3840KHZ,
  ADCC_1920KHZ,
  ADCC_SINTONE_TEST_PATTERN,
  ADCC_RealADC_CAPTURE_FROM_DFE_INPUT,
  ADCC_RealADC_CAPTURE_FROM_DFE_OUTPUT
} eADCC_Capture_Mode;

typedef enum {
  ADCP_Query_Playback_Status,
    // ADCP_Query_Playback_Status return value definition
    // bit 0:1 : 00 => IDLE
    //           01 => WAITING (to start playback)
    //           02 => PLAYING
    //           03 => STOP (normarl or abnormal)
    // bit 4   : Channel 1's PHY FIFO underrun
    // bit 5   : Channel 1's AP FIFO overflow
    // bit 6   : Channel 1's AP FIFO underrun
    // bit 7   : Channel 1   APdetect CRC error
    // bit 8   : Channel 2's PHY FIFO overflow
    // bit 9   : Channel 2's AP FIFO overflow
    // bit 10  : Channel 2's AP FIFO underrun    
    // bit 11  : Channel 2   AP detect CRC error
    // bit 12  : RXDFE detect asyc playback status
  ADCP_Query_CH1_Data_Counter,
  ADCP_Query_CH2_Data_Counter,
  ADCP_Query_CH1_CRC_CheckSum,
  ADCP_Query_CH2_CRC_CheckSum
} eADCP_Query_Type;

#define ADCP_PB_STATUS_MASK        0x03
#define ADCP_PB_STATUS_IDLE        0x00
#define ADCP_PB_STATUS_WAITING     0x01
#define ADCP_PB_STATUS_PLAYING     0x02
#define ADCP_PB_STATUS_STOP        0x03

#define ADCP_PB_PHY_STATUS_MASK    0x0110
#define ADCP_PB_CH1_PHY_UNDERRUN   0x0010
#define ADCP_PB_CH2_PHY_UNDERRUN   0x0100

#define ADCP_PB_AP_STATUS_MASK     0x0EE0
#define ADCP_PB_AP_CH1_OVERFLOW    0x0020
#define ADCP_PB_AP_CH1_UNDERRUN    0x0040
#define ADCP_PB_AP_CH1_PHY_CRC_ERR 0x0080
#define ADCP_PB_AP_CH2_OVERFLOW    0x0200
#define ADCP_PB_AP_CH2_UNDERRUN    0x0400
#define ADCP_PB_AP_CH2_PHY_CRC_ERR 0x0800

#define ADCP_PB_RXDFE_STATUS_MASK  0x1000
#define ADCP_PB_RXDFE_ASYNC_STATUS 0x1000


#define ADCP_PB_NORMAL_STOP_STATUS (ADCP_PB_CH1_PHY_UNDERRUN | ADCP_PB_AP_CH1_UNDERRUN | ADCP_PB_CH2_PHY_UNDERRUN | ADCP_PB_AP_CH2_UNDERRUN | ADCP_PB_STATUS_STOP)

#define ADCP_PB_ERROR_MASK         (ADCP_PB_AP_CH1_PHY_CRC_ERR | ADCP_PB_AP_CH2_PHY_CRC_ERR | ADCP_PB_AP_CH1_OVERFLOW | ADCP_PB_AP_CH2_OVERFLOW)








//===========================================================================//
//  Public Driver API for coresight IP                                       //
//===========================================================================//
kal_uint32 drv_dnt_init(eSIB_Configure_mode);
void drv_cnp_serdes_test_init(eTrace_mode Trace_Mode, kal_uint32 Pattern);
kal_uint32 drv_query_playback_serdes_test_status(kal_uint32 *Ch0_ReceiveCount, kal_uint32 *Ch1_ReceiveCount);
void drv_dnt_set_sata_frequency(eTrace_SATA_Frequency);
void drv_dnt_set_bus1x_frequency(trace_bus1x_clk);
kal_uint32 drv_dnt_funnel_open(eTrace_mode Trace_Mode);
kal_uint32 drv_dnt_funnel_close(eTrace_mode Trace_Mode);
void TF_enable_flush_master_only(void);

//===========================================================================//
//  Public Driver API for ADC Capture                                        //
//===========================================================================//
void drv_adcc_start(eADCC_Capture_Mode);
void drv_adcc_stop(void);
kal_uint32 drv_adcc_status(eADCC_Query_Type ADCC_Query_Type);

//===========================================================================//
//  Public Driver API for ADC Playback                                       //
//===========================================================================//
void drv_adcp_start(void);
void drv_adcp_stop(void);
kal_int32 drv_adcp_status(eADCP_Query_Type);

#endif

