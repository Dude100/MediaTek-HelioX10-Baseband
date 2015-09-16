/********************************************************************************************
 *     LEGAL DISCLAIMER 
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES 
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED 
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS 
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED, 
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR 
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY 
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, 
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK 
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION 
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *     
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH 
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, 
 *     
 *     TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE 
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
 *     
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS 
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.  
 ************************************************************************************************/


/*******************************************************************************
 *
 * Filename:
 * ---------
 * l1v_db.c
 *
 * Project:
 * --------
 * MOLY
 *
 * Description:
 * ------------
 * This file used for pre-processing to build L1V DB
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *  How to add a new gv script
 * 1. Put the l1v script into the proper folder e.g: \dhl\database\l1validation_db
 *                                                 
 * 2. #include "xxx.l1v". 
 *
 *******************************************************************************/

#ifdef STDC_HEADERS
#undef STDC_HEADERS //it will include stdio.h
#endif

#ifdef __UMTS_RAT__
//For 3G Project, please include your header here, e.g: #include "dps_D1_MT_call.l1v"
//Please put your gv files to \dhl\database\l1validation_db\

#include "0_3G_Single_Channel/1_Idle/udps_I1_Initial_Cell_Search.l1v"
#include "0_3G_Single_Channel/1_Idle/udps_I2_SFN_Read_SIB_Listen.l1v"
#include "0_3G_Single_Channel/1_Idle/udps_I3_Paging_Response.l1v"
#include "0_3G_Single_Channel/1_Idle/udps_I4_Target_Cell_Search.l1v"
#include "0_3G_Single_Channel/1_Idle/udps_I10_UL1D_CS_Test.l1v"
#include "0_3G_Single_Channel/1_Idle/udps_I12_pch_measurement_8960.l1v"
#include "0_3G_Single_Channel/2_Access/udps_A1_UL_Open_Loop_Pwr_Ctrl.l1v"
#include "0_3G_Single_Channel/2_Access/udps_A2_Tx_On_Off_Time_Mask.l1v"
#include "0_3G_Single_Channel/2_Access/udps_A3_Rx_ACK_on_AICH.l1v"
#include "0_3G_Single_Channel/2_Access/udps_A4_Rx_No_ACK_on_AICH.l1v"
#include "0_3G_Single_Channel/2_Access/udps_A5_Rx_NACK_on_AICH.l1v"
#include "0_3G_Single_Channel/3_Dedicated/CD05/udps_CD05_Pef_in_Static_CH_RMC12.l1v"
#include "0_3G_Single_Channel/3_Dedicated/CD05/udps_CD05_Pef_in_Static_CH_RMC144.l1v"
#include "0_3G_Single_Channel/3_Dedicated/CD05/udps_CD05_Pef_in_Static_CH_RMC384.l1v"
#include "0_3G_Single_Channel/3_Dedicated/CD05/udps_CD05_Pef_in_Static_CH_RMC64.l1v"
#include "0_3G_Single_Channel/3_Dedicated/CD10/udps_CD10_DL_Pwr_Ctrl_Const_BLER_RMC12.l1v"
#include "0_3G_Single_Channel/3_Dedicated/CD10/udps_CD10_DL_Pwr_Ctrl_Const_BLER_RMC64.l1v"
#include "0_3G_Single_Channel/3_Dedicated/CD13/udps_CD13_Pef_in_SHO_RMC12.l1v"
#include "0_3G_Single_Channel/3_Dedicated/CD13/udps_CD13_Pef_in_SHO_RMC64.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD01_UL_Inner_Loop_Pwr_Ctrl.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD02_Out_of_Sync_Handling.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD03_Change_of_TFC.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD04_UL_Compressed_Mode.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD09_Pef_in_TX_Div_Mode.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD11_Pef_in_DL_Compressed_Mode.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD12_Pef_of_BTFD.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD14_Pef_of_TPC_Combining.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD15_Pef_in_SSDT_Pwr_Ctrl.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD16_Active_Set_Update_Delay.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD17_TX_Timing_in_SHO.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD18_Intra_Freq_TRHHO_Delay.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD19_Inter_Freq_TRHHO_Delay.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD20_RRC_Re_estab_Delay.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD21_Inter_Freq_TMHHO.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD22_Inter_Freq_TRHHO_Revert.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD23_Inter_Freq_TMHHO_Revert.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD24_abort_enter_DCH.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD39_BER_test_in_DCH_mode.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD40_SADCH_TTI_eighty.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD41_SADCH_TTI_eighty_with_CM.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD50.l1v"
#include "0_3G_Single_Channel/3_Dedicated/udps_CD51_DCH_FACH_transition.l1v"
#include "0_3G_Single_Channel/udps_Test_Stop.l1v"
#include "1_3G_Single_Meas/udps_CRS1_Inter_Freq_Crs_in_Idle.l1v"
#include "1_3G_Single_Meas/udps_CRS2_Intra_Freq_Crs_in_Fach.l1v"
#include "1_3G_Single_Meas/udps_CRS3_Inter_Freq_Crs_in_Fach.l1v"
#include "1_3G_Single_Meas/udps_M01_Intra_Freq_Reporting_Delay.l1v"
#include "1_3G_Single_Meas/udps_M03_Inter_Freq_Reporting_Delay.l1v"
#include "1_3G_Single_Meas/udps_M04_Abs_Intra_Freq_Cpich_Rscp.l1v"
#include "1_3G_Single_Meas/udps_M05_Rel_Intra_Freq_Cpich_Rscp.l1v"
#include "1_3G_Single_Meas/udps_M06_Rel_Inter_Freq_Cpich_Rscp.l1v"
#include "1_3G_Single_Meas/udps_M07_Abs_Intra_Freq_Cpich_Ecio.l1v"
#include "1_3G_Single_Meas/udps_M08_Rel_Intra_Freq_Cpich_Ecio.l1v"
#include "1_3G_Single_Meas/udps_M09_Rel_Inter_Freq_Cpich_Ecio.l1v"
#include "1_3G_Single_Meas/udps_M10_Abs_Utra_Carrier_Rssi.l1v"
#include "1_3G_Single_Meas/udps_M11_Rel_Utra_Carrier_Rssi.l1v"
#include "1_3G_Single_Meas/udps_M12_Intra_Freq_Sfn_Cfn_Diff.l1v"
#include "1_3G_Single_Meas/udps_M13_Inter_Freq_Sfn_Cfn_Diff.l1v"
#include "1_3G_Single_Meas/udps_M14_Sfn_Sfn_Diff_Type1.l1v"
#include "1_3G_Single_Meas/udps_M15_UE_Tx_Power.l1v"
#include "2_3G_Dual_Mode/udps_GM1_Gsm_Meas_in_Null.l1v"
#include "2_3G_Dual_Mode/udps_GM2_Gsm_Meas_in_Idle.l1v"
#include "2_3G_Dual_Mode/udps_GM3_Gsm_Meas_in_Fach.l1v"
#include "2_3G_Dual_Mode/udps_GM4_Gsm_Reporting_Delay.l1v"
#include "2_3G_Dual_Mode/udps_GM5_Gsm_Reporting_Delay_No_Bsic.l1v"
#include "2_3G_Dual_Mode/udps_GM6_Abs_Gsm_Carrier_Rssi.l1v"
#include "2_3G_Dual_Mode/udps_UM1_Wcdma_Meas_in_Scan.l1v"
#include "2_3G_Dual_Mode/udps_UM2_Wcdma_Meas_in_Idle.l1v"
#include "2_3G_Dual_Mode/udps_UM3_Wcdma_Meas_in_Dedi.l1v"
#include "2_3G_Dual_Mode/udps_UM4_Wcdma_Meas_in_Pidle.l1v"
#include "2_3G_Dual_Mode/udps_UM5_Wcdma_Meas_in_Ptx.l1v"
#include "2_3G_Dual_Mode/udps_IRT1_Gsm_Crs_to_Umts.l1v"
#include "2_3G_Dual_Mode/udps_IRT2_Umts_Crs_to_Gsm.l1v"
#include "2_3G_Dual_Mode/udps_IRT3_Gsm_Hho_to_Umts.l1v"
#include "3_3G_CSD_Request/udps_I5_PCH_reading_on_STTD_Cell.l1v"
#include "3_3G_CSD_Request/udps_I6_Pch_Receive.l1v"
#include "3_3G_CSD_Request/udps_I8_Recursive_TCS_in_PCH.l1v"
#include "3_3G_CSD_Request/udps_I9_Recursive_ICS_in_NULL.l1v"
#include "3_3G_CSD_Request/udps_I11_Recursive_IPS_in_NULL.l1v"
#include "3_3G_CSD_Request/udps_A6_Best_Effort_for_PRACH.l1v"
#include "3_3G_CSD_Request/udps_A7_Recursive_TCS_in_FACH.l1v"
#include "3_3G_CSD_Request/udps_CD25_Recursive_TCS_in_DCH.l1v"
#include "3_3G_CSD_Request/udps_CD26_Unknown_SFN_Decoding_in_DCH.l1v"
#include "3_3G_CSD_Request/udps_CD28_TPC_Combining_Reliable_Test.l1v"
#include "3_3G_CSD_Request/udps_CD31_SIR_Meas_In_DCH_with_TXTD_CM.l1v"
#include "3_3G_CSD_Request/udps_CD32_DLPC_Test_Wind_Up_Down.l1v"
#include "3_3G_CSD_Request/udps_CD33_Pef_of_TrCH_Reconfig.l1v"
#include "3_3G_CSD_Request/udps_CD34_DLPC_for_Diff_TF.l1v"
#include "3_3G_CSD_Request/udps_CD35_DLPC_for_BTFD_Dual_TF.l1v"
#include "3_3G_CSD_Request/udps_CD36_DLPC_for_TFCI_Dual_TF.l1v"
#include "3_3G_CSD_Request/udps_CD37_DLPC_Test_Initial_Convergence.l1v"
#include "3_3G_CSD_Request/udps_CD38_ULPC_for_TX_AGC_test.l1v"
#include "3_3G_CSD_Request/udps_M16_all_meas_statistic.l1v"
#include "3_3G_CSD_Request/udps_UM6_Recursive_TCS_in_2G_Idle.l1v"
#include "3_3G_CSD_Request/udps_UM7_Recursive_TCS_in_2G_Dedi.l1v"
#include "11_HSDPA/udps_DPAS_SL1.l1v"
#include "11_HSDPA/udps_DPAS_SL2.l1v"
#include "11_HSDPA/udps_DPAS_SL3.l1v"
#include "11_HSDPA/udps_DPAS_SL4.l1v"
#include "11_HSDPA/udps_DPAS_SL5.l1v"
#include "11_HSDPA/udps_DPAS_SL6.l1v"
#include "11_HSDPA/udps_DPAS_SL7.l1v"
#include "11_HSDPA/udps_DPAS_SL8.l1v"
#include "11_HSDPA/udps_DPAS_SL9.l1v"
#include "11_HSDPA/udps_DPAS_SL10.l1v"
#include "11_HSDPA/udps_DPAS_SL11.l1v"
#include "11_HSDPA/udps_DPAS_SL12.l1v"
#include "11_HSDPA/udps_DPAS_SL13.l1v"
#include "11_HSDPA/udps_DPAS_CC1.l1v"
#include "11_HSDPA/udps_DPAS_CC2.l1v"
#include "11_HSDPA/udps_DPAS_CC3.l1v"
#include "11_HSDPA/udps_DPAS_CC4.l1v"
#include "11_HSDPA/udps_DPAS_CC5.l1v"
#include "11_HSDPA/udps_DPAS_CC6.l1v"
#include "11_HSDPA/udps_DPAS_TGPS1.l1v"
#include "11_HSDPA/udps_DPAS_TGPS2.l1v"
#include "11_HSDPA/udps_DPAS_MEAS1.l1v"
#include "11_HSDPA/udps_DPAS_MEAS2.l1v"
#include "11_HSDPA/udps_DPAS_MEAS3.l1v"
#include "11_HSDPA/udps_DPAS_OCIC1.l1v"
#include "11_HSDPA/udps_DPAS_OCIC2.l1v"
#include "11_HSDPA/udps_DPAS02_OCIC.l1v"
#include "11_HSDPA/udps_DPAS08_1.l1v"
#include "11_HSDPA/udps_DPAF01.l1v"
#include "11_HSDPA/udps_DPAF02.l1v"
#include "11_HSDPA/udps_DPAF03.l1v"
#include "11_HSDPA/udps_DPAF04.l1v"
#include "11_HSDPA/udps_DPAF07.l1v"
#include "11_HSDPA/udps_DPAF08.l1v"
#include "11_HSDPA/udps_DPAF09.l1v"
#include "11_HSDPA/udps_DPAF10.l1v"
#include "11_HSDPA/udps_DPAF11.l1v"
#include "11_HSDPA/udps_DPAF11_1.l1v"
#include "11_HSDPA/udps_DPAF12.l1v"
#include "11_HSDPA/udps_DPAF13.l1v"
#include "11_HSDPA/udps_DPAF14.l1v"
#include "11_HSDPA/udps_DPAF15.l1v"
#include "11_HSDPA/1_FDDTest_8960/udps_DPAS_FDD_Test1.l1v"
#include "11_HSDPA/1_FDDTest_8960/udps_DPAS_FDD_Test2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN01_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN01_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN02_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN02_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN03_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN03_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN04_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN04_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN05_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN05_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN06_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN06_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN07_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN07_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN08_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN08_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN09_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN09_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN10_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN10_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN11_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN11_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN12_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN12_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN13_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN13_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN14_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN14_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN15_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN15_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN16.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN17_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN17_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN18_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN18_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN19_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN19_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN20.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN21.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN22.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN90_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN90_2.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN91_1.l1v"
#include "12_HSUPA_R6/1_E_DCH_CONN/udps_R6_CN91_2.l1v"
#include "12_HSUPA_R6/2_POWER/udps_R6_PW01_1.l1v"
#include "12_HSUPA_R6/2_POWER/udps_R6_PW01_2.l1v"
#include "12_HSUPA_R6/2_POWER/udps_R6_PW02.l1v"
#include "12_HSUPA_R6/2_POWER/udps_R6_PW03.l1v"
#include "12_HSUPA_R6/2_POWER/udps_R6_PW04.l1v"
#include "12_HSUPA_R6/2_POWER/udps_R6_PW05.l1v"
#include "12_HSUPA_R6/2_POWER/udps_R6_PW06_1.l1v"
#include "12_HSUPA_R6/2_POWER/udps_R6_PW06_2.l1v"
#include "12_HSUPA_R6/2_POWER/udps_R6_PW06_3.l1v"
#include "12_HSUPA_R6/2_POWER/udps_R6_PW07_1.l1v"
#include "12_HSUPA_R6/2_POWER/udps_R6_PW07_2.l1v"
#include "12_HSUPA_R6/2_POWER/udps_R6_PW07_3.l1v"
#include "12_HSUPA_R6/2_POWER/udps_R6_PW08_1.l1v"
#include "12_HSUPA_R6/2_POWER/udps_R6_PW08_2.l1v"
#include "12_HSUPA_R6/2_POWER/udps_R6_PW08_3.l1v"
#include "12_HSUPA_R6/3_CM/udps_R6_CM01_1.l1v"
#include "12_HSUPA_R6/3_CM/udps_R6_CM01_2.l1v"
#include "12_HSUPA_R6/3_CM/udps_R6_CM02_1.l1v"
#include "12_HSUPA_R6/3_CM/udps_R6_CM02_2.l1v"
#include "12_HSUPA_R6/3_CM/udps_R6_CM03_1.l1v"
#include "12_HSUPA_R6/3_CM/udps_R6_CM03_2.l1v"
#include "12_HSUPA_R6/3_CM/udps_R6_CM04.l1v"
#include "12_HSUPA_R6/3_CM/udps_R6_CM05_1.l1v"
#include "12_HSUPA_R6/3_CM/udps_R6_CM05_2.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_HI01_1.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_HI01_2.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_HI02_1.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_HI02_2.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_HI03_1.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_HI03_2.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_HI04_1.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_HI04_2.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_RG01_1.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_RG01_2.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_RG02.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_RG03_1.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_RG03_2.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_RG04_1.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_RG04_2.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_AG01_1.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_AG01_2.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_AG02_1.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_AG02_2.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_AG03_1.l1v"
#include "12_HSUPA_R6/4_E_AG_HI_RG/udps_R6_AG03_2.l1v"
#include "12_HSUPA_R6/5_E_TFC/udps_R6_TF01_1.l1v"
#include "12_HSUPA_R6/5_E_TFC/udps_R6_TF01_2.l1v"
#include "12_HSUPA_R6/5_E_TFC/udps_R6_TF02_1.l1v"
#include "12_HSUPA_R6/5_E_TFC/udps_R6_TF02_2.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CD01_1.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_HI01_1.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_HI01_2.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_HI02_1.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_HI02_2.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_HI03_1.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_HI03_2.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_HI04_1.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_HI04_2.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_RG01_1.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_RG01_2.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_RG02.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_RG03_1.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_RG03_2.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_RG04_1.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_RG04_2.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_AG01_1.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_AG01_2.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_AG02_1.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_AG02_2.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_PW02.l1v"
#include "12_HSUPA_R6/6_CSD_REQ/udps_R6_CSD_PW03.l1v"
#include "12_HSUPA_R6/7_AGL8960/udps_R6_AGL01_1.l1v"
#include "12_HSUPA_R6/7_AGL8960/udps_R6_AGL01_2.l1v"
#include "12_HSUPA_R6/7_AGL8960/udps_R6_AGL02_1.l1v"
#include "12_HSUPA_R6/7_AGL8960/udps_R6_AGL02_2.l1v"
#include "12_HSUPA_R6/7_AGL8960/udps_R6_AGL_HI01_1_ACK.l1v"
#include "12_HSUPA_R6/7_AGL8960/udps_R6_AGL_HI01_1_FALSE_ACK.l1v"
#include "12_HSUPA_R6/7_AGL8960/udps_R6_AGL_HI01_2_ACK.l1v"
#include "12_HSUPA_R6/7_AGL8960/udps_R6_AGL_HI01_2_FALSE_ACK.l1v"
#include "12_HSUPA_R6/7_AGL8960/udps_R6_AGL_AG01_1.l1v"
#include "12_HSUPA_R6/7_AGL8960/udps_R6_AGL_AG01_2.l1v"
#include "12_HSUPA_R6/8_MEAS/udps_R6_ME01_1.l1v"
#include "12_HSUPA_R6/8_MEAS/udps_R6_ME01_2.l1v"
#include "12_HSUPA_R6/8_MEAS/udps_R6_ME02_1.l1v"
#include "12_HSUPA_R6/8_MEAS/udps_R6_ME02_2.l1v"
#include "12_HSUPA_R6/8_MEAS/udps_R6_ME02_3.l1v"
#include "12_HSUPA_R6/8_MEAS/udps_R6_ME03_1.l1v"
#include "12_HSUPA_R6/8_MEAS/udps_R6_ME03_2.l1v"
#include "12_HSUPA_R6/8_MEAS/udps_R6_ME03_3.l1v"
#include "13_R7R8/DpsTest_R7_HSDPA_01.l1v"
#include "13_R7R8/DpsTest_R7_HSDPA_02.l1v"
#include "13_R7R8/DpsTest_R7_HSDPA_03.l1v"
#include "13_R7R8/DpsTest_R7_HSDPA_04.l1v"
#include "13_R7R8/DpsTest_R7_HSDPA_05.l1v"
#include "13_R7R8/DpsTest_R7_HSDPA_06.l1v"
#include "13_R7R8/DpsTest_R7_HSDPA_07.l1v"
#include "13_R7R8/DpsTest_R7_HSDPA_08.l1v"
#include "13_R7R8/udps_R7_TF01_1.l1v"
#include "13_R7R8/udps_R7_TF01_2.l1v"
#include "13_R7R8/DpsTest_R7_CPC_01.l1v"
#include "13_R7R8/DpsTest_R7_CPC_02.l1v"
#include "13_R7R8/DpsTest_R7_CPC_03.l1v"
#include "13_R7R8/DpsTest_R7_CPC_04.l1v"
#include "13_R7R8/DpsTest_R7_CPC_05.l1v"
#include "13_R7R8/DpsTest_R7_CPC_06.l1v"
#include "13_R7R8/DpsTest_R7_CPC_07.l1v"
#include "13_R7R8/DpsTest_R7_CPC_08.l1v"
#include "13_R7R8/DpsTest_R7_CPC_09.l1v"
#include "13_R7R8/DpsTest_R7_CPC_10.l1v"
#include "13_R7R8/DpsTest_R7_CPC_11.l1v"
#include "13_R7R8/DpsTest_R7_CPC_12.l1v"
#include "13_R7R8/DpsTest_R7_CPC_13.l1v"
#include "13_R7R8/DpsTest_R7_CPC_14.l1v"
#include "13_R7R8/DpsTest_R7_CPC_15.l1v"
#include "13_R7R8/DpsTest_R7_CPC_16.l1v"
#include "13_R7R8/DpsTest_R7_FDPCH_01.l1v"
#include "13_R7R8/DpsTest_R7_FDPCH_02.l1v"
#include "13_R7R8/DpsTest_R7_FDPCH_03.l1v"
#include "13_R7R8/DpsTest_R7_FDPCH_04.l1v"
#include "13_R7R8/DpsTest_R7_FDPCH_05.l1v"
#include "13_R7R8/DpsTest_R7_EFACH_01.l1v"
#include "13_R7R8/DpsTest_R7_EFACH_02.l1v"
#include "13_R7R8/DpsTest_R7_EFACH_03.l1v"
#include "13_R7R8/DpsTest_R7_EFACH_04.l1v"
#include "13_R7R8/DpsTest_R7_EFACH_05.l1v"
#include "13_R7R8/DpsTest_R7_EFACH_06.l1v"
#include "13_R7R8/DpsTest_R7_EFACH_07.l1v"
#include "13_R7R8/DpsTest_R8_CEDCH_01.l1v"
#include "13_R7R8/DpsTest_R8_CEDCH_02.l1v"
#include "13_R7R8/DpsTest_R8_CEDCH_03.l1v"
#include "13_R7R8/DpsTest_R8_CEDCH_04.l1v"
#include "13_R7R8/DpsTest_R8_CEDCH_05.l1v"
#include "13_R7R8/DpsTest_R8_CEDCH_06.l1v"
#include "13_R7R8/DpsTest_R8_CEDCH_07.l1v"
#include "13_R7R8/DpsTest_R8_DCHSDPA_01.l1v"
#include "13_R7R8/DpsTest_R8_DCHSDPA_02.l1v"
#include "13_R7R8/DpsTest_R8_DCHSDPA_03.l1v"
#include "13_R7R8/DpsTest_R8_DCHSDPA_04.l1v"
#include "13_R7R8/DpsTest_R8_DCHSDPA_05.l1v"
#include "13_R7R8/DpsTest_R8_DCHSDPA_06.l1v"
#include "13_R7R8/DpsTest_R8_DCHSDPA_07.l1v"
#include "13_R7R8/DpsTest_R8_DCHSDPA_08.l1v"
#include "13_R7R8/DpsTest_R8_DCHSDPA_09.l1v"
#include "13_R7R8/DpsTest_R8_DCHSDPA_10.l1v"
#include "13_R7R8/DpsTest_R8_DCHSDPA_11.l1v"
#include "13_R7R8/DpsTest_R8_DCHSDPA_12.l1v"
#include "13_R7R8/DpsTest_R8_DCHSDPA_13.l1v"
#include "13_R7R8/DpsTest_R8_DCHSDPA_14.l1v"
#include "13_R7R8/DpsTest_R8_DCHSDPA_15.l1v"
#include "13_R7R8/DpsTest_R8_FACHDRX_01.l1v"
#include "13_R7R8/DpsTest_R8_FACHDRX_02.l1v"
#include "13_R7R8/DpsTest_R8_FACHDRX_03.l1v"
#include "13_R7R8/DpsTest_R8_LessMode_01.l1v"
#include "13_R7R8/DpsTest_R8_LessMode_02.l1v"
#include "13_R7R8/DpsTest_R8_LessMode_03.l1v"
#include "13_R7R8/DpsTest_R8_LessMode_04.l1v"
#include "13_R7R8/DpsTest_R8_LessMode_05.l1v"
#include "13_R7R8/DpsTest_R8_M1.l1v"
#include "13_R7R8/DpsTest_R8_M2.l1v"
#include "13_R7R8/DpsTest_R8_M3.l1v"
#include "13_R7R8/DpsTest_R8_M4.l1v"
#include "13_R7R8/DpsTest_R8_M5.l1v"
#include "13_R7R8/DpsTest_R8_M6.l1v"
#include "13_R7R8/DpsTest_R8_M7.l1v"
#include "13_R7R8/DpsTest_R8_M8.l1v"
#include "13_R7R8/DpsTest_R8_M9.l1v"
#include "13_R7R8/DpsTest_R8_M10.l1v"
#include "13_R7R8/DpsTest_R8_MCPC1_01.l1v"
#include "13_R7R8/DpsTest_R8_MCPC1_02.l1v"
#include "13_R7R8/DpsTest_R8_MCPC2_01.l1v"
#include "13_R7R8/DpsTest_R8_MCPC2_02.l1v"
#include "13_R7R8/DpsTest_R8_CRS1.l1v"
#include "13_R7R8/DpsTest_R8_CRS2.l1v"
#endif  //__UMTS_RAT__

 



//For GSM/GPRS Project, please include your header here, e.g: #include "dps_D1_MT_call.l1v"
//Please put your gv files to \dhl\database\l1validation_db

#ifdef __GSM_RAT__

#include "4_2G_FT/dps_FT1_PowerScanWithStoredList.l1v"
#ifdef __PS_SERVICE__   // Jeff Lee 20100331
#include "4_2G_FT/dps_FT2_CCCh_nonSig_FT.l1v"
#endif /* __PS_SERVICE__ */
#include "4_2G_FT/dps_FT3_CCCh_Comb_Page_Reorg.l1v"
#include "5_2G_Scan/dps_S1_PowerScan.l1v"
#include "5_2G_Scan/dps_S2_FBSBsearch.l1v"
#include "5_2G_Scan/dps_S3_repeated_FBSB.l1v"
#include "5_2G_Scan/dps_S4_BCCH_SI_receive.l1v"
#include "6_2G_Idle/dps_I1_RepeatCampOn.l1v"
#include "6_2G_Idle/dps_I2_EnterIdleState.l1v"
#include "6_2G_Idle/dps_I3_SC_Test.l1v"
#include "6_2G_Idle/dps_I4_CBCH_receive.l1v"
#include "6_2G_Idle/dps_I5_LocUpdate.l1v"
#include "7_2G_Dedicated/dps_D1_MT_call.l1v"
#include "7_2G_Dedicated/dps_D2_MO_call.l1v"
#ifdef __PS_SERVICE__   // Jeff Lee 20100331
#include "8_2G_Pkt_Idle/dps_PI1_CCCh_Pkt_Idle1.l1v"
#include "8_2G_Pkt_Idle/dps_PI2_CCCh_Pkt_Idle2.l1v"
#include "8_2G_Pkt_Idle/dps_PI3_CCCh_Idle_Read_Pbcch.l1v"
#include "8_2G_Pkt_Idle/dps_PI4_PCCCh_Pkt_Idle.l1v"
#include "8_2G_Pkt_Idle/dps_PI5_PCCCh_Pkt_Idle_Pbcch_Update.l1v"
#include "8_2G_Pkt_Idle/dps_PI6_PCCCh_Pkt_Idle_SC_Test.l1v"
#include "8_2G_Pkt_Idle/dps_PI7_PCCCh_Pkt_Idle_SC_Test_Pbcch_Update.l1v"
#include "8_2G_Pkt_Idle/dps_PI8_PCCCh_NCMeas.l1v"
#include "8_2G_Pkt_Idle/dps_PI9_PCCCh_ExtMeas.l1v"
#include "8_2G_Pkt_Idle/dps_PI10_CCCh_Pkt_Idle_SC_Test.l1v"
#include "8_2G_Pkt_Idle/dps_PI11_CCChNCMeas.l1v"
#include "8_2G_Pkt_Idle/dps_PI12_CCChExtMeas.l1v"
#include "8_2G_Pkt_Idle/dps_PI13_CCCh_Gprs_Attach_One_Phase.l1v"
#include "8_2G_Pkt_Idle/dps_PI14_CCCh_Gprs_Attach_Two_Phase.l1v"
#include "8_2G_Pkt_Idle/dps_PI15_PCCCh_Gprs_Attach_One_Phase.l1v"
#include "8_2G_Pkt_Idle/dps_PI16_PCCCh_Gprs_Attach_Two_Phase.l1v"
#ifdef __EGPRS_MODE__  // Jeff Lee 20100331
#include "8_2G_Pkt_Idle/dps_PI17_CCCh_Egprs_Attach_One_Phase.l1v"
#include "8_2G_Pkt_Idle/dps_PI19_CCCh_Egprs_Attach_Two_Phase.l1v"
#include "8_2G_Pkt_Idle/dps_PI20_PCCCh_Egprs_Attach_One_Phase.l1v"
#include "8_2G_Pkt_Idle/dps_PI22_PCCCh_Egprs_Attach_Two_Phase.l1v"
#endif /* __EGPRS_MODE__ */
#include "9_2G_Pkt_Transfer/dps_PT8_Serving_PBCCh_Update_During_TBF.l1v"
#include "9_2G_Pkt_Transfer/dps_PT9_CCCh_TBF_SC_Test.l1v"
#include "9_2G_Pkt_Transfer/dps_PT10-1_CCCh_Nbr_PBCCh_Update_During_TBF.l1v"
#include "9_2G_Pkt_Transfer/dps_PT10-2_PCCCh_Nbr_PBCCh_Update_During_TBF.l1v"
#include "9_2G_Pkt_Transfer/dps_PT11_CCCh_ICMP.l1v"
#include "9_2G_Pkt_Transfer/dps_PT12_CCCh_nonSignaling.l1v"
#ifdef __EGPRS_MODE__  // Jeff Lee 20100331
#include "9_2G_Pkt_Transfer/dps_PT16_CCCH_Egprs_TBF_NBCCH_Req.l1v"
#include "9_2G_Pkt_Transfer/dps_PT17_CCCH_Egprs_TBF_NPBCCH_Req.l1v"
#include "9_2G_Pkt_Transfer/dps_PT18_PCCCh_Egprs_TBF_NPBCCH_Req.l1v"
#endif /* __EGPRS_MODE__ */
#endif /* __PS_SERVICE__ */
#include "10_2G_L1D/dps_l1d_lp1.l1v"
#include "10_2G_L1D/dps_l1d_lp2.l1v"
#include "10_2G_L1D/dps_l1d_lp3.l1v"
#include "10_2G_L1D/dps_l1d_lp5_23.l1v"
#include "10_2G_L1D/dps_l1d_lp5.l1v"
#include "10_2G_L1D/dps_l1d_lp6.l1v"
#include "10_2G_L1D/dps_l1d_lp7.l1v"
#include "10_2G_L1D/dps_l1d_lp8.l1v"

#include "dps_Test_Stop.l1v"
#endif //__GSM_RAT__

#include "dummy.l1v"



