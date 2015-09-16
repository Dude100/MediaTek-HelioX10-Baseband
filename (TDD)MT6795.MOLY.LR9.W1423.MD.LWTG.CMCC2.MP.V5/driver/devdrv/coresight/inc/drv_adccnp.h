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
 *   drv_adccnp.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   ADC Capture and playback driver header file
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
 * [MOLY] Coresight Driver Update for ADC Capture
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
 ****************************************************************************/
#define ADCC_SOURCE_ADCC             1
#define ADCC_SOURCE_RXDFE_STUB       2
#define ADCC_SOURCE_RXDFE            3
#define ADCC_SOURCE                  ADCC_SOURCE_RXDFE_STUB

//###########################################################################//
//  IP : ADCC                                                                //
//###########################################################################//
#define ADCC_BASE_ADDRESS           (BASE_ADDR_MDDBGAPB + 0x00310000) // bit15 : 0

#define ADCC0_ADDR_OFFSET           (0x0000) // [14:13] => 00 for adcc0
#define ADCC1_ADDR_OFFSET           (0x2000) // [14:13] => 01 for adcc1
#define ADCC01_ADDR_DIFF            (ADCC1_ADDR_OFFSET - ADCC0_ADDR_OFFSET)



//###########################################################################//
//  IP : ADCP                                                                //
//###########################################################################//
#define ADCP_PHY_BASE_ADDRESS       (BASE_ADDR_MDDBGAPB + 0x00310000) // bit15 : 0
#ifdef __FPGA__ // FPGA
#define ADCP_AP_BASE_ADDRESS        (BASE_ADDR_MDDBGAPB + 0x0031B400) // [15]:1b, [14]:0b, [13:12]:11b,[11]:0b,[10]:1b
#else
#define ADCP_AP_BASE_ADDRESS        (BASE_ADDR_MDDBGAPB + 0x0041B400) // [15]:1b, [14]:0b, [13:12]:11b,[11]:0b,[10]:1b
#endif

#define ADCP_PHY0_BASE_ADDRESS      (ADCP_PHY_BASE_ADDRESS + 0x4000) // [14:13] => 10 for adcp0 (0xB9314000)
#define ADCP_PHY1_BASE_ADDRESS      (ADCP_PHY_BASE_ADDRESS + 0x6000) // [14:13] => 11 for adcp1 (0xB9316000)

#define ADCP_AP0_BASE_ADDRESS       (ADCP_AP_BASE_ADDRESS + 0x0000) // [9] => 0 for adcp0 (0xB931B400)
#define ADCP_AP1_BASE_ADDRESS       (ADCP_AP_BASE_ADDRESS + 0x0200) // [9] => 1 for adcp1 (0xB931B600)


#define ADCP_PHY_01_ADDR_DIFF       (ADCP_PHY1_BASE_ADDRESS - ADCP_PHY0_BASE_ADDRESS)
#define ADCP_AP_01_ADDR_DIFF        (ADCP_AP1_BASE_ADDRESS - ADCP_AP0_BASE_ADDRESS)



//###########################################################################//
//  IP : RXDFE ADC CAPTURE and PLAYBACK related                              //
//###########################################################################//
#ifdef __FPGA__ // FPGA
#define RXDFE_CNP_BASE_ADDRESS      (BASE_ADDR_MDDBGAPB + 0x00300000) // bit16 : 0, bit15 : 1
#else
#define BASE_ADDR_C2CRF_FCORE1      (0xB6300000)
#endif



//===========================================================================//
//  ADCC                                                                     //
//===========================================================================//
#define ADCC_CTRL                   (ADCC_BASE_ADDRESS + 0x00)
#define ADCC_MAX_USAGE_MASK         (0x003F0000)
#define ADCC_MAX_USAGE_SHIFT        (16)
#define ADCC_ATID_MASK              (0x00007F00)
#define ADCC_ATID_SHIFT             (8)
#define ADCC_ACT_THRESHOLD_MASK     (0x000000F0)
#define ADCC_ACT_THRESHOLD_SHIFT    (4)
#define ADCC_OVERFLOW_STOP_EN       (1 << 3)
#define ADCC_OVERFLOW               (1 << 2)
#define ADCC_EN                     (1 << 0)

#define FRAME_GEN_ATID              (ADCC_BASE_ADDRESS + 0x04)
#define ATID_FRAME_GEN_MASK         (0x0000007F)              

#define FRAME_GEN_CTRL              (ADCC_BASE_ADDRESS + 0x08)
#define FRAME_GEN_EN                (1 << 31)
#define FRAME_GEN_INTERVAL_MASK     (0x00FFFFFF)


#define ADCC_OVL_CNT                (ADCC_BASE_ADDRESS + 0x0C)
#define FRNUM_OVERFLOW_CNT_MASK     (0xFFFF0000)
#define FRNUM_OVERFLOW_CNT_SHIFT    (16)
#define ADCC_OVERFLOW_CNT_MASK      (0x0000FFFF)


#define DUMMY_TRACE_CTRL            (ADCC_BASE_ADDRESS + 0x14)
#define DUMMY_TRACE_INC_ONE         (0 << 2)
#define DUMMY_TRACE_DEC_ONE         (1 << 2)
#define DUMMY_TRACE_INC_PAT         (6 << 2)
#define DUMMY_TRACE_INIT            (1 << 1)
#define DUMMY_TRACE_EN              (1 << 0)


#define DUMMY_TRACE_INIT_VALUE      (ADCC_BASE_ADDRESS + 0x18)
#define DUMMY_TRACE_INC_VALUE       (ADCC_BASE_ADDRESS + 0x1C)

//===========================================================================//
//  ADCP                                                                     //
//===========================================================================//
// DFE <-- PLAYBACK PHY <-- PLAYBACK AP <-- SerDes <-- SIB

#define ADCP_PHY_CTRL               (ADCP_PHY0_BASE_ADDRESS + 0x00)//B9314000 / B9316000
#define PLAYBACK_STATUS             (1 << 31)
#define PHY_FIFO_USAGE_Q_CH_MASK    (0x0000F000)
#define PHY_FIFO_USAGE_Q_CH_SHIFT   (12)
#define PHY_FIFO_USAGE_I_CH_MASK    (0x00000F00)
#define PHY_FIFO_USAGE_I_CH_SHIFT   (8)
#define SINGLE_CH_EN                (1 << 7)
#define PLAYBACK_PHY_UNDERFLOW      (1 << 3)
#define PLAYBACK_PHY_IQ_SWAP        (1 << 1)
#define PLAYBACK_PHY_EN             (1 << 0) 


#define ADCP_PHY_START_THRESHOLD    (ADCP_PHY0_BASE_ADDRESS + 0x04)//B9314004 / B9316004
#define START_THRESHOLD_1           (0x0)
#define START_THRESHOLD_2           (0x1)
#define START_THRESHOLD_3           (0x2)
#define START_THRESHOLD_4           (0x3)

#define ADCP_PHY_DBG_CTRL           (ADCP_PHY0_BASE_ADDRESS + 0x10)//B9314010 / B9316010

#define ADCP_PHY_DBG_SWITCH         (ADCP_PHY0_BASE_ADDRESS + 0x20)//B9314020 / B9316020


#define ADCP_PHY_MONITOR_FIFO_CTRL  (ADCP_PHY0_BASE_ADDRESS + 0x40)//B9314040 / B9316040
#define PB_MONITOR_EN               (1 << 31)
#define PB_MONITOR_REN              (1 << 30)
#define PB_MONITOR_RADDR_MASK       (0x01FF0000)
#define PB_MONITOR_RADDR_SHIFT      (16)
#define PB_MONITOR_WADDR_MASK       (0x000001FF)



#define ADCP_PHY_MONITOR_FIFO_RDATA (ADCP_PHY0_BASE_ADDRESS + 0x44)//B9314044 / B9316044

#define ADCP_PHY_SMD_STATUS         (ADCP_PHY0_BASE_ADDRESS + 0x50)//B9314050 / B9316050
#define SIB_MODE_COMPARE_FAUL       (1 << 31)
#define SIB_MODE_COMPARE_EN         (1 << 0)

#define ADCP_PHY_SMD_SUCCESS_CNT    (ADCP_PHY0_BASE_ADDRESS + 0x54)//B9314054 / B9316054

#define ADCP_PHY_SMD_EXPECT_VALUE   (ADCP_PHY0_BASE_ADDRESS + 0x58)//B9314058 / B9316058

#define ADCP_PHY_SMD_ACTUAL_VALUE   (ADCP_PHY0_BASE_ADDRESS + 0x5C)//B931405C / B931605C

#define ADCP_PHY_SW_RESET           (0xB930C000)
#define ADCP_PHY_RESET              (1 << 0)

#define ADCP_AP_CTRL                (ADCP_AP0_BASE_ADDRESS + 0x00)//B931B400 / B931B600
#define SIB_MAX_BURST_LEN_MASK      (0x003F0000)
#define SIB_MAX_BURST_LEN_SHIFT     (16)
#define AP_FIFO_USAGE_Q_CH_MASK     (0x0000F000)
#define AP_FIFO_USAGE_Q_CH_SHIFT    (12)
#define AP_FIFO_USAGE_I_CH_MASK     (0x00000F00)
#define AP_FIFO_USAGE_I_CH_SHIFT    (8)
#define RX_CK_POLARITY_INVERSION    (1 << 5)
#define PLAYBACK_CRC_ERROR          (1 << 4)
#define PLAYBACK_AP_UNDERFLOW       (1 << 3)
#define PLAYBACK_AP_OVERFLOW        (1 << 2)
#define PLAYBACK_AP_IQ_SWAP         (1 << 1)
#define PLAYBACK_AP_EN              (1 << 0)


#define ADCP_AP_PATGEN_CTRL         (ADCP_AP0_BASE_ADDRESS + 0x04)//B931B404 / B931B604
#define PB_PATGEN_RCVCNT_MASK       (0xFFFF0000)
#define PB_PATGEN_RCVCNT_SHIFT      (16)
#define PB_PATGEN_RCVCNT_FAIL       (1 << 1)
#define PB_PATGEN_EN                (1 << 0)




#define ADCP_AP_PATGEN0             (ADCP_AP0_BASE_ADDRESS + 0x10)//B931B410 / B931B610

#define ADCP_AP_PATGEN1             (ADCP_AP0_BASE_ADDRESS + 0x14)//B931B414 / B931B614

#define ADCP_AP_PATGEN2             (ADCP_AP0_BASE_ADDRESS + 0x18)//B931B418 / B931B618

#define ADCP_AP_PATGEN3             (ADCP_AP0_BASE_ADDRESS + 0x1C)//B931B41C / B931B61C

#define ADCP_AP_SIBPATGEN_CTRL      (ADCP_AP0_BASE_ADDRESS + 0x20)//B931B420 / B931B620
#define PB_SIBPATGEN_LEN_MASK       (0xFFFF0000)
#define PB_SIBPATGEN_LEN_SHIFT      (16)
#define SIBPATGE_MASK               (0xE)
#define SIBPATGEN_X_U1              (0 << 1)  // data[15:8] no changed, data[7:0] increased by 1
#define SIBPATGEN_X_D1              (1 << 1)  // data[15:8] no changed, data[7:0] decreased 1
#define SIBPATGEN_U1_U1             (4 << 1)  // data[15:8] increased by 1, data[7:0] increased by 1
#define SIBPATGEN_D1_D1             (5 << 1)  // data[15:8] decreased by 1, data[7:0] decreased by 1
#define PB_SIBPATGEN_EN             (1 << 0)



//===========================================================================//
//  RXDFE ADCC & ADCP register                                               //
//===========================================================================//
#ifndef __FPGA__
#define FMC_MML1_PHYCK_26MCFG       (BASE_ADDR_C2CRF_FCORE1 + 0x028C)

#define FMC_MML1_PHYTIMER_START     (BASE_ADDR_C2CRF_FCORE1 + 0x0600)
#define FMC_MML1_PHYTIMER_BWSW_2    (BASE_ADDR_C2CRF_FCORE1 + 0x0668)

#define FMC_LTEL1_RXDFE_CTRL        (BASE_ADDR_C2CRF_FCORE1 + 0x1200)

#define FMC_LTEL1_RXDFE_CONFIG      (BASE_ADDR_C2CRF_FCORE1 + 0x1204)

#define FMC_LTEL1_RXDFE_TEST_CTRL   (BASE_ADDR_C2CRF_FCORE1 + 0x120C)

#define FMC_LTEL1_RXDFE_ON_LSB      (BASE_ADDR_C2CRF_FCORE1 + 0x1210)
#define FMC_LTEL1_RXDFE_ON_MSB      (BASE_ADDR_C2CRF_FCORE1 + 0x1214)

#define FMC_LTEL1_RXDFE_SFRM1       (BASE_ADDR_C2CRF_FCORE1 + 0x1220)
#define FMC_LTEL1_RXDFE_SFRM2       (BASE_ADDR_C2CRF_FCORE1 + 0x1224)

#define FMC_LTEL1_RXDFE_DCO_SFRM1   (BASE_ADDR_C2CRF_FCORE1 + 0x1228)
#define FMC_LTEL1_RXDFE_DCO_SFRM2   (BASE_ADDR_C2CRF_FCORE1 + 0x122C)
#define FMC_LTEL1_RXDFE_NCO_SFRM1   (BASE_ADDR_C2CRF_FCORE1 + 0x1230)
#define FMC_LTEL1_RXDFE_NCO_SFRM2   (BASE_ADDR_C2CRF_FCORE1 + 0x1234)


#define FMC_LTEL1_RXDFE_BIT_MAP     (BASE_ADDR_C2CRF_FCORE1 + 0x1238)

#define FMC_LTEL1_RXDFE_SYM_LEN1    (BASE_ADDR_C2CRF_FCORE1 + 0x123C)
#define FMC_LTEL1_RXDFE_SYM_LEN2    (BASE_ADDR_C2CRF_FCORE1 + 0x1240)

#define FMC_LTEL1_RXDFE_RAMP_UP     (BASE_ADDR_C2CRF_FCORE1 + 0x1244)

#define FMC_LTEL1_RXDFE_DCO1_I      (BASE_ADDR_C2CRF_FCORE1 + 0x1248)
#define FMC_LTEL1_RXDFE_DCO1_Q      (BASE_ADDR_C2CRF_FCORE1 + 0x124C)
#define FMC_LTEL1_RXDFE_DCO2_I      (BASE_ADDR_C2CRF_FCORE1 + 0x1250)
#define FMC_LTEL1_RXDFE_DCO2_Q      (BASE_ADDR_C2CRF_FCORE1 + 0x1254)

#define FMC_LTEL1_RXDFE_IQ1_GAIN    (BASE_ADDR_C2CRF_FCORE1 + 0x1258)
#define FMC_LTEL1_RXDFE_IQ2_GAIN    (BASE_ADDR_C2CRF_FCORE1 + 0x1260)

#define FMC_LTEL1_RXDFE_FOE_LSB     (BASE_ADDR_C2CRF_FCORE1 + 0x1268)
#define FMC_LTEL1_RXDFE_FOE_MSB     (BASE_ADDR_C2CRF_FCORE1 + 0x126C)

#define FMC_LTEL1_RXDFE_FIR24_T0    (BASE_ADDR_C2CRF_FCORE1 + 0x1288)
#define FMC_LTEL1_RXDFE_FIR24_T1    (BASE_ADDR_C2CRF_FCORE1 + 0x128C)
#define FMC_LTEL1_RXDFE_FIR24_T2    (BASE_ADDR_C2CRF_FCORE1 + 0x1290)
#define FMC_LTEL1_RXDFE_FIR24_T3    (BASE_ADDR_C2CRF_FCORE1 + 0x1294)
#define FMC_LTEL1_RXDFE_FIR24_T4    (BASE_ADDR_C2CRF_FCORE1 + 0x1298)
#define FMC_LTEL1_RXDFE_FIR24_T5    (BASE_ADDR_C2CRF_FCORE1 + 0x129C)

#define FMC_LTEL1_RXDFE_DCO_SFRM1B  (BASE_ADDR_C2CRF_FCORE1 + 0x1310)
#define FMC_LTEL1_RXDFE_DCO_SFRM2B  (BASE_ADDR_C2CRF_FCORE1 + 0x1314)
#define FMC_LTEL1_RXDFE_NCO_SFRM1B  (BASE_ADDR_C2CRF_FCORE1 + 0x1318)
#define FMC_LTEL1_RXDFE_NCO_SFRM2B  (BASE_ADDR_C2CRF_FCORE1 + 0x131C)


#define FMC_LTEL1_RXDFE_CS_DAGC_RX1 (BASE_ADDR_C2CRF_FCORE1 + 0x1370)
#define FMC_LTEL1_RXDFE_CE_DAGC_RX1 (BASE_ADDR_C2CRF_FCORE1 + 0x1374)
#define FMC_LTEL1_RXDFE_CS_DAGC_RX2 (BASE_ADDR_C2CRF_FCORE1 + 0x1378)
#define FMC_LTEL1_RXDFE_CE_DAGC_RX2 (BASE_ADDR_C2CRF_FCORE1 + 0x137C)


#endif

#ifdef __FPGA__ // FPGA
#define RXDFE_ADCP_SYNC_IDR         (RXDFE_CNP_BASE_ADDRESS + (0x4A << 2)) //B930_0128
#else
#define RXDFE_ADCP_SYNC_IDR         (BASE_ADDR_C2CRF_FCORE1 + 0x1328) //B630_1328
#endif

#define PATH1_PATH2_SYNC_STAUTS     (1 << 0)  
#define PATH1_PATH2_INSYNC          (0 << 0)
#define PATH1_PATH2_UNSYNC          (1 << 0)

#ifdef __FPGA__ // FPGA
#define RXDFE_ADCP_PB_MODE         (RXDFE_CNP_BASE_ADDRESS + (0x4B << 2)) //B930_012C
#else
#define RXDFE_ADCP_PB_MODE         (BASE_ADDR_C2CRF_FCORE1 + 0x132C) //B630_132C
#endif
#define PLAYBACK_INPUT_SOURCE      (1 << 0)
#define PLAYBACK_FROM_ADC          (0 << 0)
#define PLAYBACK_FROM_ADCP         (1 << 0)
#define CAPTURE_MODE_MASK          (7 << 1)
#define CAPTURE_FROM_DFE_INPUT     (0 << 1)
#define CAPTURE_FROM_DFE_OUTPUT    (1 << 1)
#define CAPTURE_TEST_MODE_52000    (2 << 1)
#define CAPTURE_TEST_MODE_30720    (3 << 1)
#define CAPTURE_TEST_MODE_15360    (4 << 1)
#define CAPTURE_TEST_MODE_7680     (5 << 1)
#define CAPTURE_TEST_MODE_3840     (6 << 1)
#define CAPTURE_TEST_MODE_1920     (7 << 1)
#define RXDFE_ADCC_ENABLE          (1 << 5)
#define RXDFE_DATA_FORMAT_QI       (0 << 6) // Q[15:0], I[15:0]
#define RXDFE_DATA_FORMAT_IQ       (1 << 6) // I[15:0], Q[15:0]
#define RXDFE_ADCCP_SW_RST         (1 << 7)
#define RXDFE_ADCCP_FM_4096        (1 << 8)
#define ADCC_OPT_SEL_AFTER_AGC     (1 << 9)
#define ADCC_OPT_SEL_BEFORE_AGC    (0 << 9) 

#ifdef __FPGA__ // FPGA
#define RXDFE_CHECK_SUM1_LSB       (RXDFE_CNP_BASE_ADDRESS + (0x4C << 2)) //B930_0130
#else
#define RXDFE_CHECK_SUM1_LSB       (BASE_ADDR_C2CRF_FCORE1 + 0x1330) //B630_1330
#endif

#ifdef __FPGA__ // FPGA
#define RXDFE_CHECK_SUM1_MSB       (RXDFE_CNP_BASE_ADDRESS + (0x4D << 2)) //B930_0134
#else
#define RXDFE_CHECK_SUM1_MSB       (BASE_ADDR_C2CRF_FCORE1 + 0x1334) //B630_1334
#endif


#ifdef __FPGA__ // FPGA
#define RXDFE_CHECK_SUM2_LSB       (RXDFE_CNP_BASE_ADDRESS + (0x4E << 2)) //B930_0138
#else
#define RXDFE_CHECK_SUM2_LSB       (BASE_ADDR_C2CRF_FCORE1 + 0x1338) //B630_1338
#endif

#ifdef __FPGA__ // FPGA
#define RXDFE_CHECK_SUM2_MSB       (RXDFE_CNP_BASE_ADDRESS + (0x4F << 2)) //B930_013C
#else
#define RXDFE_CHECK_SUM2_MSB       (BASE_ADDR_C2CRF_FCORE1 + 0x133C) //B630_133C
#endif

#ifdef __FPGA__ // FPGA
#define RXDFE_CRC_CNT_LSB          (RXDFE_CNP_BASE_ADDRESS + (0x50 << 2)) //B930_0140
#else
#define RXDFE_CRC_CNT_LSB          (BASE_ADDR_C2CRF_FCORE1 + 0x1340) //B630_1340
#endif

#ifdef __FPGA__ // FPGA
#define RXDFE_CRC_CNT_MSB          (RXDFE_CNP_BASE_ADDRESS + (0x51 << 2)) //B930_0144
#else
#define RXDFE_CRC_CNT_MSB          (BASE_ADDR_C2CRF_FCORE1 + 0x1344) //B630_1344
#endif

#ifdef __FPGA__ // FPGA
#define RXDFE_DATA1_CNT_LSB        (RXDFE_CNP_BASE_ADDRESS + (0x52 << 2)) //B930_0148
#else
#define RXDFE_DATA1_CNT_LSB        (BASE_ADDR_C2CRF_FCORE1 + 0x1348) //B630_1348
#endif

#ifdef __FPGA__ // FPGA
#define RXDFE_DATA1_CNT_MSB        (RXDFE_CNP_BASE_ADDRESS + (0x53 << 2)) //B930_014C
#else
#define RXDFE_DATA1_CNT_MSB        (BASE_ADDR_C2CRF_FCORE1 + 0x134C) //B630_134C
#endif

#ifdef __FPGA__ // FPGA
#define RXDFE_DATA2_CNT_LSB        (RXDFE_CNP_BASE_ADDRESS + (0x54 << 2)) //B930_0150
#else
#define RXDFE_DATA2_CNT_LSB        (BASE_ADDR_C2CRF_FCORE1 + 0x1350) //B630_1350
#endif

#ifdef __FPGA__ // FPGA
#define RXDFE_DATA2_CNT_MSB        (RXDFE_CNP_BASE_ADDRESS + (0x55 << 2)) //B930_0154
#else
#define RXDFE_DATA2_CNT_MSB        (BASE_ADDR_C2CRF_FCORE1 + 0x1354) //B630_1354
#endif



//===========================================================================//
//  DNT Register Read/Write Macro Redifine                                   //
//===========================================================================//
#define ADCC_WriteReg32(addr, path, data)  (path? DRV_WriteReg32((addr) | ADCC01_ADDR_DIFF, data) : DRV_WriteReg32(addr, data))
                                         
#define ADCC_ReadReg32(addr, path)         (path? DRV_Reg32((addr) | ADCC01_ADDR_DIFF) : DRV_Reg32(addr))

#define ADCP_PHY_WriteReg32(addr, path, data)  (path? DRV_WriteReg32((addr) + ADCP_PHY_01_ADDR_DIFF, data) : DRV_WriteReg32(addr, data))
                                         
#define ADCP_PHY_ReadReg32(addr, path)         (path? DRV_Reg32((addr) + ADCP_PHY_01_ADDR_DIFF) : DRV_Reg32(addr))

#define ADCP_AP_WriteReg32(addr, path, data)  (path? DRV_WriteReg32((addr) + ADCP_AP_01_ADDR_DIFF, data) : DRV_WriteReg32(addr, data))
                                         
#define ADCP_AP_ReadReg32(addr, path)         (path? DRV_Reg32((addr) + ADCP_AP_01_ADDR_DIFF) : DRV_Reg32(addr))



#define RXDFE_WriteReg32(addr, data)       DRV_WriteReg32(addr, data)
                                         
#define RXDFE_ReadReg32(addr)              DRV_Reg32(addr)

void trace_enable_dsp_c2crf(void);

#if 0 //move api to publif
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
#endif



