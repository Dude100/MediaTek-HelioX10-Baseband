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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   l1_option.h
 *
 * Project:
 * --------
 *   MT6280
 *
 * Description:
 * ------------
 *   The global compile option definition of L1
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *******************************************************************************/

#ifndef __L1_OPTION_H__
#define __L1_OPTION_H__

/***************************************************************************************************************************
 * Chip ID & compile option definition for other modules                                                                   *
 ***************************************************************************************************************************/

/* Chip ID */
#if defined(ESIM_BUILD_CONFIG) || defined(__UE_SIMULATOR__)/* ESIM-MOLY and UESIM-MOLY */
#define MD_DRV_IS_CHIP_MT6280                            (defined MT6290)
#else
#define MD_DRV_IS_CHIP_MT6276                            (defined MT6276)
#define MD_DRV_IS_CHIP_MT6573                            (defined MT6573)
#define MD_DRV_IS_CHIP_MT6575                           ((defined MT6575) || (defined MT6577))
#define MD_DRV_IS_CHIP_MT6250                            (defined MT6250)
#define MD_DRV_IS_CHIP_MT6280                            (defined MT6280)
#define MD_DRV_IS_CHIP_MT6583_MD1                       ((((defined MT6583)||(defined MT6589)) && (defined __MD1__)))
#define MD_DRV_IS_CHIP_MT6583_MD2                       ((((defined MT6583)||(defined MT6589)) && (defined __MD2__)))
#define MD_DRV_IS_CHIP_MT6572                           ((defined MT6572) || (defined MT6582))
#define MD_DRV_IS_CHIP_MT6582                            (defined MT6582)
#define MD_DRV_IS_CHIP_MT6290                            (defined MT6290)
#define MD_DRV_IS_CHIP_MT6595                            ((defined MT6595))
#define MD_DRV_IS_CHIP_MT6752_MD1                       ((defined MT6752) && (defined __MD1__))
#define MD_DRV_IS_CHIP_MT6752_MD2                       ((defined MT6752) && (defined __MD2__))
#endif

/* Chip ID consistency check */
#if MD_DRV_IS_CHIP_MT6276 || MD_DRV_IS_CHIP_MT6573 || MD_DRV_IS_CHIP_MT6575 || MD_DRV_IS_CHIP_MT6250 || MD_DRV_IS_CHIP_MT6280 || MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572 || MD_DRV_IS_CHIP_MT6290 || MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1 || MD_DRV_IS_CHIP_MT6752_MD2
#else
#error "Please check the chip ID defined in l1d_cid.h"
#endif

/* RF ID */
#define MD_DRV_IS_RF_MT6280RF                            (defined MT6280RF_2G_RF)
#define MD_DRV_IS_RF_MT6169                              (defined MT6169_2G_RF)
#define MD_DRV_IS_RF_MT6166                              (defined MT6166_2G_RF)
#define MD_DRV_IS_RF_MT6165                              (defined MT6165_2G_RF)

/* ======================================================================================================================= */

// Definition of GSM/GPRS/EGPRS support
#if (defined MODE_EGPRS) || (defined MTK_EGPRS_ENABLE) || (defined __EGPRS_MODE__)
#define MD_DRV_IS_GSM                                     0
#define MD_DRV_IS_GPRS                                    1
#define MD_DRV_IS_EGPRS                                   1
#elif ((defined MODE_GPRS) || (defined __PS_SERVICE__) || (defined MTK_GPRS_ENABLE) || (GPRS==1))
#define MD_DRV_IS_GSM                                     0
#define MD_DRV_IS_GPRS                                    1
#define MD_DRV_IS_EGPRS                                   0
#else
#define MD_DRV_IS_GSM                                     1
#define MD_DRV_IS_GPRS                                    0
#define MD_DRV_IS_EGPRS                                   0
#endif

// EPSK TX Support
#if (defined __EPSK_TX__)
#define MD_DRV_IS_EPSK_TX_SUPPORT                         1
#else
#define MD_DRV_IS_EPSK_TX_SUPPORT                         0
#endif

// Centralized sleep mode
#if (defined __CENTRALIZED_SLEEP_MANAGER__)
#define MD_DRV_IS_CENTRALIZED_SMM_CHIP                    1
#else
#define MD_DRV_IS_CENTRALIZED_SMM_CHIP                    0
#endif

// TDD Dual Mode Feature Option
#if ((defined __UMTS_TDD128_MODE__) && MD_DRV_IS_CHIP_MT6250)
#define MD_DRV_IS_AST_B2S_SUPPORT                         1
#else
#define MD_DRV_IS_AST_B2S_SUPPORT                         0
#endif

// For feature of split binary: MAUI/FACTORY bin
#if (defined __FACTORY_BIN__) || !(defined __SPLIT_BINARY__)
#define MD_DRV_IS_FOR_FACTORY_MODE_ONLY                   1
#else
#define MD_DRV_IS_FOR_FACTORY_MODE_ONLY                   0
#endif

// Factory mode compile option: FHC & NSFT
#if MD_DRV_IS_FOR_FACTORY_MODE_ONLY
#define MD_DRV_IS_FHC_SUPPORT                             1
#define MD_DRV_IS_NSFT_SUPPORT                            1
#define MD_DRV_IS_SINGLE_END_BER_SUPPORT                  1
#define MD_DRV_IS_NSFT_SACCH_TEST_ITEM_SUPPORT            1
#else
#define MD_DRV_IS_FHC_SUPPORT                             0
#define MD_DRV_IS_NSFT_SUPPORT                            0
#define MD_DRV_IS_SINGLE_END_BER_SUPPORT                  0
#define MD_DRV_IS_NSFT_SACCH_TEST_ITEM_SUPPORT            0
#endif

// Multi-slot TX Support in GSM only
#if MD_DRV_IS_FHC_SUPPORT && MD_DRV_IS_GSM
#define MD_DRV_IS_MULTISLOT_TX_SUPPORT                    0
#else
#define MD_DRV_IS_MULTISLOT_TX_SUPPORT                    0
#endif

// AFC 33-section Calibration
#if (defined MT6253T) || (defined MT6253) || (defined MT6253E) || (defined MT6253L) || (defined MT6252) || (defined MT6252H)
#define MD_DRV_IS_VCXO_LC_SUPPORT                         1
#else
#define MD_DRV_IS_VCXO_LC_SUPPORT                         0
#endif

// TX Power Compensation
#if defined (__2G_TX_POWER_CONTROL_SUPPORT__)
#define MD_DRV_IS_TX_POWER_CONTROL_SUPPORT                1
   #if MD_DRV_IS_CHIP_MT6276 || MD_DRV_IS_CHIP_MT6573
#define MD_DRV_IS_TXPC_CL_AUXADC_SUPPORT                  1  // Closed-loop TX Power Compensation (Vdet from AUXADC)
   #else
#define MD_DRV_IS_TXPC_CL_AUXADC_SUPPORT                  0
   #endif
#else
#define MD_DRV_IS_TX_POWER_CONTROL_SUPPORT                0
#define MD_DRV_IS_TXPC_CL_AUXADC_SUPPORT                  0
#endif

// W cancellation
#if (defined L1D_TEST) || (defined L1_SIM)
#define MD_DRV_IS_W_CANCELLATION_SUPPORT                  0
#elif MD_DRV_IS_CHIP_MT6250 || MD_DRV_IS_CHIP_MT6280 || MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6572 || MD_DRV_IS_CHIP_MT6290 || MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1 || MD_DRV_IS_CHIP_MT6752_MD2
#define MD_DRV_IS_W_CANCELLATION_SUPPORT                  1
#else
#define MD_DRV_IS_W_CANCELLATION_SUPPORT                  0
#endif

// 2G RF Custom Tool
#if defined(__2G_RF_CUSTOM_TOOL_SUPPORT__)
#define MD_DRV_IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2        1
#else
#define MD_DRV_IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2        0
#endif

// UDVT Frequency Hopping
#if ((defined __UDVT__) && (MD_DRV_IS_CHIP_MT6250 || MD_DRV_IS_CHIP_MT6280))
#define MD_DRV_IS_UDVT_FH_SUPPORT                         1
#else
#define MD_DRV_IS_UDVT_FH_SUPPORT                         0
#endif

// Feature of 32k crystal removal
#if defined(__F32_XOSC_REMOVAL_SUPPORT__)
#define MD_DRV_IS_32K_CRYSTAL_REMOVAL_SUPPORT             1
#else
#define MD_DRV_IS_32K_CRYSTAL_REMOVAL_SUPPORT             0
#endif

// Feature of TX gain RF calibration
#if defined(__2G_TX_GAIN_RF_CALIBRATION__)
#define MD_DRV_IS_TX_GAIN_RF_CALIBRATION_SUPPORT          1
#else
#define MD_DRV_IS_TX_GAIN_RF_CALIBRATION_SUPPORT          0
#endif

// For chip with 32-bit of BPI_DATA
#if MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572 || MD_DRV_IS_CHIP_MT6290 || MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1 || MD_DRV_IS_CHIP_MT6752_MD2
#define MD_DRV_IS_BPI_DATA_32_BIT_CHIP                    1
#else
#define MD_DRV_IS_BPI_DATA_32_BIT_CHIP                    0
#endif

// For MD2G SW mode
#if MD_DRV_IS_CHIP_MT6276 || MD_DRV_IS_CHIP_MT6573 || MD_DRV_IS_CHIP_MT6575 || MD_DRV_IS_CHIP_MT6280 || MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572 || MD_DRV_IS_CHIP_MT6290 || MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1 || MD_DRV_IS_CHIP_MT6752_MD2
#define MD_DRV_IS_MD2G_PWD_DEFAULT_SW_MODE                0
#else
#define MD_DRV_IS_MD2G_PWD_DEFAULT_SW_MODE                1
#endif

// Feature of Fix AFC
#if defined(__L1_GPS_CO_CLOCK_SUPPORT__)
#define MD_DRV_IS_DUAL_LOOP_AFC_CONTROL_SUPPORT           1
#else
#define MD_DRV_IS_DUAL_LOOP_AFC_CONTROL_SUPPORT           0
#endif

// Feature of MIPI Control
#if defined(__2G_MIPI_SUPPORT__)
#define MD_DRV_IS_2G_MIPI_SUPPORT           1
#else
#define MD_DRV_IS_2G_MIPI_SUPPORT           0
#endif

#if MD_DRV_IS_2G_MIPI_SUPPORT && defined(__2G_MIPI_INTERSLOT_RAMPING_OPTIMIZE_SUPPORT__)
#define MD_DRV_IS_MIPI_INTERSLOT_RAMPING_OPTIMIZE_SUPPORT  1
#else
#define MD_DRV_IS_MIPI_INTERSLOT_RAMPING_OPTIMIZE_SUPPORT  0
#endif

#endif
