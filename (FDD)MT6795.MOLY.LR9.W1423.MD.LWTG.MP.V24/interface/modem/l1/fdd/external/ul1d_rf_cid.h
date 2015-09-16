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
 *   ul1d_rf_cid.h
 *
 * Project:
 * --------
 *   3G Project Common File
 *
 * Description:
 * ------------
 *   Compile option definition
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime: $
 * $Log: $
 *
 * removed!
 * removed!
 * [MIPI NVRAM][MP6.MP][MT6795] Enable 3G MIPI NVRAM item
 *
 * removed!
 * removed!
 * [TAS][MP6.MP][MT6795] 3G TAS RF driver porting, SKU1:BPI-6, SKU3: BPI-6, HIAU:BPI-24, EVB: BPI-0
 *
 * removed!
 * removed!
 * 	[MT6290][3G FDD RF driver] Rx Path selection feature, request by ANT team test in K2.
 *
 * removed!
 * removed!
 * 	[MIPI NVRAM] Disable 3G MIPI NVRAM for UL1 INIT assert issue
 *
 * removed!
 * removed!
 * 	[3G MIPI NVRAM] Create 3G MIPI NVRAM items for all cumtom MIPI table
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * [MT6290] 3G ET driver porting
 *
 * removed!
 * removed!
 * 	[MT6290][3G MIPI driver] remove 2G MIPI support flag.
 *
 * removed!
 * removed!
 * 	[MT6290][3G MIPI driver] Add custom_mipi.c and .h to all the 6290 project.
 *
 * removed!
 * removed!
 * 	[MT6290][3G RF MIPI driver]1. add global variable for enable/disable MIPI, sync from CBr. 2. fix warning,
 *
 * removed!
 * removed!
 * 	[MT6290][3G RF driver] 1. change the RSSI abnormal assert lower/upper bond to easier trigger the RSSI abnormal issue; 2. Add dump BSI record and 256 RF CWs. when RSSI abnormal.
 *
 * removed!
 * removed!
 * 	[MT6290][3G RF driver] rename 3G MIPI data struture, avoiding conflict with LTE.
 *
 * removed!
 * removed!
 * 	[MT6290][3G RF driver] revert 3G MIPI enable in A1US, A1EU.
 *
 * removed!
 * removed!
 * 	[MT6290][3G MIPI code] Temperarily make 3G MIPI option enable with 2G make option, change it to 3G make option later.
 *
 * removed!
 * removed!
 * 	[MT6290][3G FDD RF driver] 1. Enable CW21/22/27/41 power saving. 2. change CW53 setting for power saving.
 *
 * removed!
 * removed!
 * 	[MT6290][3G FDD RF driver] Also 1. CW115 setting change, RG_SRX_KVCO_SEL set to 2. Add CW118
 *
 * 08 28 2013 tony.wu
 * removed!
 * 	MOLY Thermal change - UL1D temp
 *
 * removed!
 * removed!
 * 	[MT6290][3G FDD RF driver] Add CW27 and CW41 in RX control sequence, since CW21 and CW22 had set the manual mode for power saving. This is only for E1 version, no needing in E2.
 *
 * removed!
 * removed!
 * [MT6290][3G FDD RFFE MIPI driver]
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * [MT6290][3G FDD RF driver] enable RxD support flag.
 *
 * removed!
 * removed!
 * roll back to revision 8 due to build error
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * [MT6290][3G FDD RF driver] disable RxD
 *
 * removed!
 * removed!
 * [MT6290][3G FDD RF driver] 1. enable RX DCOC K, 2. enable RxD.
 *
 * removed!
 * removed!
 * [MT6290][3G FDD RF driver] 1. fix a RF DC DAC format defect. 2. enable RF DC tracking. 3. add RXD code, 4. modify the IQ cal and RX DCOC cal. But now disable the RxD and Rx DCOC K first.
 *
 * removed!
 * removed!
 * 1. Turn on RF temperature measurement
 * 2. fix typo in error_check.c for MT6280
 * 3. Turn off Tx runtime calibration which makes EVM worse
 *
 * removed!
 * removed!
 * [MT6290 & MT6169][3G FDD RF driver] Sync driver patch from first call branch to Moly.
 *
 * removed!
 * removed!
 * [MT6169 and MT6290 3G RF driver ] Merge from Yuyang's 6572+6169 CBr, CL#118715, and make it build okay.
 *
 * removed!
 * removed!
 * [UL1D][Modify] Code merge of RF related from WR8 for MT6290
 *
 * removed!
 * removed!
 * In order to that xGen in UESIM align to Target, RF module in UESIM must be align to latest RF driver.
 *
 * removed!
 * removed!
 * sync MT6280_DVT_DEV to MT6280_GCC_DEV
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Merge RF MSBB architecture modification
 *
 * 11 08 2011 ivan.hu
 * removed!
 * .
 *
 * 10 14 2011 ivan.hu
 * removed!
 * .
 *
 *******************************************************************************/

#ifndef  _UL1D_RF_CID_H_
#define  _UL1D_RF_CID_H_

/*******************************************************************************
** Define RF chip in use
*******************************************************************************/

/*------------------------------------------*/
/* Use in UL1D :                            */
/*   ( 1) UL1D_RF_ID_SONY_CXA3359           */
/*   ( 2) UL1D_RF_ID_MT6159B                */
/*   ( 3) UL1D_RF_ID_SMARTI3G               */
/*   ( 4) UL1D_RF_ID_MT6159D                */
/*   ( 5) UL1D_RF_ID_MT6160                 */
/*   ( 6) UL1D_RF_ID_MT6162                 */
/*------------------------------------------*/

#define UL1D_RF_ID_SONY_CXA3359              0x00000001
#define UL1D_RF_ID_MT6159B                   0x00000002
#define UL1D_RF_ID_SMARTI3G                  0x00000003
#define UL1D_RF_ID_MT6159D                   0x00000005 
#define UL1D_RF_ID_MT6160                    0x00000007
#define UL1D_RF_ID_MT6162                    0x00000008
#define UL1D_RF_ID_MT6162_DUAL               0x00000009
#define UL1D_RF_ID_ORION_FDD                 0x0000000A
#define UL1D_RF_ID_ORION_HPLUS               0x0000000B
#define UL1D_RF_ID_MT6167                    0x0000000C
#define UL1D_RF_ID_MT6166                    0x0000000D
#define UL1D_RF_ID_MT6169                    0x0000000E


/*.......................................................*/
#ifdef __UE_SIMULATOR__
#define IS_URF_ORION_HPLUS                   ( 1 )
#elif defined (ESIM_BUILD_CONFIG) &&  (ESIM_BUILD_CONFIG == ESIM_MULTI_MODE_ON_FIBERS)
#define IS_URF_ORION_HPLUS                   ( 1 )
#else
#define IS_RF_SONY_CXA3359                   ( UL1D_RF_ID==UL1D_RF_ID_SONY_CXA3359 )
#define IS_RF_MT6159B                        ( UL1D_RF_ID==UL1D_RF_ID_MT6159B )
#define IS_RF_SMARTI3G                       ( UL1D_RF_ID==UL1D_RF_ID_SMARTI3G )
#define IS_RF_MT6159D                        ( UL1D_RF_ID==UL1D_RF_ID_MT6159D )
#define IS_RF_MT6160                         ( UL1D_RF_ID==UL1D_RF_ID_MT6160 )
//Both 2G and 3G should use same IS_RF_MT6162 defintion to fix compile warning 
#define IS_RF_MT6162                         ( ((defined RF_ID) && RF_ID==RF_ID_MT6162) || ((defined UL1D_RF_ID) && UL1D_RF_ID==UL1D_RF_ID_MT6162) )

#define IS_URF_MT6162_DUAL                   ( UL1D_RF_ID==UL1D_RF_ID_MT6162_DUAL  )
#define IS_URF_ORION_FDD                     ( UL1D_RF_ID==UL1D_RF_ID_ORION_FDD    )
#define IS_URF_ORION_HPLUS                   ( UL1D_RF_ID==UL1D_RF_ID_ORION_HPLUS  )
#define IS_URF_MT6167                        ( UL1D_RF_ID==UL1D_RF_ID_MT6167       )
#define IS_URF_MT6166                        ( UL1D_RF_ID==UL1D_RF_ID_MT6166       )
#define IS_URF_MT6169                        ( UL1D_RF_ID==UL1D_RF_ID_MT6169       )
#endif
/*.......................................................*/

#ifndef  UL1D_RF_ID
   #if   defined(SONY_CXA3359_RF)
#define UL1D_RF_ID                           UL1D_RF_ID_SONY_CXA3359
   #elif defined(MT6159B_RF)
#define UL1D_RF_ID                           UL1D_RF_ID_MT6159B
   #elif defined(SMARTI3G_RF)
#define UL1D_RF_ID                           UL1D_RF_ID_SMARTI3G
   #elif defined(MT6159D_RF)
#define UL1D_RF_ID                           UL1D_RF_ID_MT6159D
   #elif defined(MT6160_RF)
#define UL1D_RF_ID                           UL1D_RF_ID_MT6160
   #elif defined(MT6162_RF)
#define UL1D_RF_ID                           UL1D_RF_ID_MT6162
   #elif defined(MT6162_DUAL_RF)
#define UL1D_RF_ID                           UL1D_RF_ID_MT6162_DUAL
   #elif defined(B60155A_RF)
#define UL1D_RF_ID                           UL1D_RF_ID_ORION_FDD
   #elif defined(MT6280RF_UMTS_FDD_RF)
#define UL1D_RF_ID                           UL1D_RF_ID_ORION_HPLUS
   #elif defined(MT6167_RF)
#define UL1D_RF_ID                           UL1D_RF_ID_MT6167
   #elif defined(MT6166_RF)
#define UL1D_RF_ID                           UL1D_RF_ID_MT6166
   #elif defined(MT6169_RF)
#define UL1D_RF_ID                           UL1D_RF_ID_MT6169
   #else
      #error "No Valid RF Chip was defined"
   #endif
#else
   #error "Unexpected RF Chip was defined"
#endif

/*.......................................................*/

/*******************************************************************************
** META HWTPC test item usage
*******************************************************************************/
#define IS_HSPA_HWTPC                        0

/*******************************************************************************
** RXD & DUAL CELL usage
*******************************************************************************/
#if IS_URF_MT6162_DUAL
#define IS_RF_DUAL_CELL_SUPPORT              1
#define IS_RF_RXD_SUPPORT                    1
#define TEAMPERATURE_MEAS_EN                 0 //Can be enabled for OrionRF related only

#elif IS_URF_ORION_HPLUS
#define IS_RF_DUAL_CELL_SUPPORT              1
#define IS_RF_RXD_SUPPORT                    1
#define TEAMPERATURE_MEAS_EN                 1

#elif IS_URF_MT6167
#define IS_RF_DUAL_CELL_SUPPORT              1
#define IS_RF_RXD_SUPPORT                    1
#define TEAMPERATURE_MEAS_EN                 1

#elif IS_URF_MT6166
#define IS_RF_DUAL_CELL_SUPPORT              1
#define IS_RF_RXD_SUPPORT                    0   // MT6166 doesn't support RxD
#define TEAMPERATURE_MEAS_EN                 1   // temp disable for phone call and not port yet

#elif IS_URF_MT6169
#define IS_RF_DUAL_CELL_SUPPORT              1
#define IS_RF_RXD_SUPPORT                    1
#define TEAMPERATURE_MEAS_EN                 1   /* temp disable for phone call and not port yet */


/*MIPI RFFE flag*/
#define IS_3G_MIPI_SUPPORT                   defined(__3G_MIPI_SUPPORT__) /* temp enable 3G MIPI by 2G make option */
#if (IS_3G_MIPI_SUPPORT)
#define IS_3G_MIPI_NVRAM_FULL_SUPPORT        defined(__3G_MIPI_NVRAM_FULL_SUPPORT__)
#endif
#define ENABLE_3G_TPC_SUB_BAND               0 /* subband support for MIPI 8 stage PA bias*/
#define IS_3G_ET_SUPPORT                     0
#define IS_3G_ET_NVRAM_SUPPORT               IS_3G_ET_SUPPORT
#define ENABLE_ET_DEBUG_TRACE                0
#define ENABLE_3G_ET_SUB_BAND                0 /* subband support for MIPI ET*/
#define IS_3G_MIPI_EXTENDED_READ_ENABLE      0
#define IS_3G_VPA_SEL_BY_BAND_SUPPORT        IS_3G_ET_SUPPORT
#define IS_3G_FDD_RX_PATH_SELECTION_SUPPORT  defined(__3G_RX_PATH_SELECTION_SUPPORT__)
#define IS_3G_TAS_SUPPORT                    defined(__TAS_SUPPORT__)
#define IS_3G_TAS_UL1_CUSTOM_SET             IS_3G_TAS_SUPPORT
#define IS_3G_TAS_RX_GAIN_SWAP_SUPPORT       0
#define ENABLE_TAS_DEBUG_TRACE               0
#define IS_3G_TAS_NVRAM_SUPPORT              IS_3G_TAS_SUPPORT
#define IS_3G_FORCE_TX_ANT_SUPPORT           IS_3G_TAS_SUPPORT


#define IS_RX_LPF_CURR_IN_MANUAL_MODE        1   /*For power saving purpose, MT7206 programing guide_0705.doc, 9.4.2.3 excel file*/

//Temporary for development and bring up test. shall remove this all when stabel, paul.
#define MT6169_TO_DO                         1

#define MT6169_DISABLE_RF_DC_TRACKING        0 /*for beginning bring up*/
#define MT6169_ENABLE_RX_DCOC_K              1
#define IS_3G_RSSI_ABNORMAL_DEBUG            1


#else
#define IS_RF_DUAL_CELL_SUPPORT              0
#define IS_RF_RXD_SUPPORT                    0
#define TEAMPERATURE_MEAS_EN                 0
#endif

#if defined (__TX_POWER_OFFSET_SUPPORT__)
#define IS_3G_TX_POWER_OFFSET_SUPPORT                 1  /* Enable Tx power offset */
#else
#define IS_3G_TX_POWER_OFFSET_SUPPORT                 0  /* Disable Tx power offset */
#endif /*__TX_POWER_OFFSET_SUPPORT__*/   

#endif /* #ifndef  _UL1D_RF_CID_H_ */

