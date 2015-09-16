/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	ul1d_custom_rf.h
 *
 * Project:
 * --------
 *   MT6169
 *
 * Description:
 * ------------
 *   MT6169 UMTS FDD RF
 *
 * Author:
 * -------
 * -------
 *

 *******************************************************************************/
#ifndef  _UL1D_CUSTOM_RF_H_
#define  _UL1D_CUSTOM_RF_H_
/* ------------------------------------------------------------------------- */
#if !defined(MT6169_RF)
   #error "rf files mismatch with compile option!"
#endif

#include "ul1d_custom_mipi.h"

/*MT6169*/
/*MT6169*/ #define  PA_SECTION   3
/*MT6169*/
/*MT6169*/ /*--------------------------------------------------------*/
/*MT6169*/ /*   Event Timing Define                                  */
/*MT6169*/ /*--------------------------------------------------------*/
/*MT6169*/ #define  TC_PR1               MICROSECOND_TO_CHIP(200)
/*MT6169*/ #define  TC_PR2               MICROSECOND_TO_CHIP(100)
/*MT6169*/ #define  TC_PR2B              MICROSECOND_TO_CHIP( 50)
/*MT6169*/ #define  TC_PR3               MICROSECOND_TO_CHIP( 20)
/*MT6169*/
/*MT6169*/ #define  TC_PT1               MICROSECOND_TO_CHIP(200)
/*MT6169*/ #define  TC_PT2               MICROSECOND_TO_CHIP(100)
/*MT6169*/ #define  TC_PT2B              MICROSECOND_TO_CHIP( 50)
/*MT6169*/ #define  TC_PT3               MICROSECOND_TO_CHIP( 10)
/*MT6169*/
/*MT6169*/
/*MT6169*/ /* the following parameter is chip resolution */
/*MT6169*/ #define MAX_OFFSET        (24*4) //this value must be equal to max of the following 4 offset value
/*MT6169*/ /* Set VM timing same as PGABSI_OFFSET1 */
/*MT6169*/ // Rich modification for the vm_offset as 37
/*MT6169*/ #define VM_OFFSET         (42)//(33)   //54 //63 chips
/*MT6169*/ #define VBIAS_OFFSET      (59)   //59 chips
/*MT6169*/ #define DC2DC_OFFSET      (24*4)
/*MT6169*/ #define VGA_OFFSET        (24*4)
/*MT6169*/
/*MT6169*/
/*---------------------------------------------------------------------*/
/*   define  BPI data for MT6169  (7206_VERSION A_BPI Table_0225.xlsx) */
/*---------------------------------------------------------------------*/
/*    PRCB : bit  BPI   pin function                                   */
/*            0    0    LTE_BPI_OUT0                                   */
/*            1    1    LTE_BPI_OUT1                                   */
/*            2    2    AT_SEL_MAIN2_1                                 */
/*            3    3    AT_SEL_MAIN2_2                                 */
/*            4    4    RX_CB_B1_B3                                    */
/*            5    5    4G DSDA Tx Bypass Mode                         */
/*            6    6    2G DSDA Mode Co-existence                      */
/*            7    7    2G MEM dump and MD log                         */
/*            8    8    2G USB wake up host                            */
/*            9    9    2G MD wake up host                             */
/*            10   10   Host wake up 2G MD                             */
/*            11   11   RX_CB_B7_B1                                    */
/*            12   12   RX_CB_B17_B8                                   */
/*            13   13   RX_CB_B40_B41_DRX                              */
/*            14   14   ANT_DRX_V1                                     */
/*            15   15   ANT_DRX_V2                                     */
/*            16   16   ANT_DRX_V3                                     */
/*            17   17   ANT_DRX_V4                                     */
/*            18   18   RX_CB_B40_B41_PRX                              */
/*            19   19   ANT_Main1_SP5T_V3                              */
/*            20   20   ANT_Main1_SP5T_V2                              */
/*            21   21   ANT_Main1_SP5T_V1                              */
/*            22   22   3P4T_V1                                        */
/*            23   23   3P4T_V2                                        */
/*            24   24   3P4T_V3                                        */
/*            25   25   3P4T_V4                                        */
/*            26   26   Reserved                                       */
/*            27   27   Reserved                                       */
/*            28   28   Reserved                                       */
/*            29   29   Reserved                                       */
/*            30   30   Reserved                                       */
/*            31   31   Reserved                                       */
/*---------------------------------------------------------------------*/

 //* --------------------- PDATA_BAND1 Start ---------------------------*/
#define    PDATA_BAND1_PR1      0x00120810
#define    PDATA_BAND1_PR2      0x00120810
#define    PDATA_BAND1_PR2B     0x00120810
#define    PDATA_BAND1_PR3      0x00000000
#define    PDATA_BAND1_PT1      0x00120810
#define    PDATA_BAND1_PT2      0x00120810
#define    PDATA_BAND1_PT2B     0x00120810
#define    PDATA_BAND1_PT3      0x00000000
 /* --------------------- PDATA_BAND1 End ------------------------------*/
 /* --------------------- PDATA_BAND1 RXD Start ------------------------*/
#define    PDATA2_BAND1_PR1     0x00120810
#define    PDATA2_BAND1_PR2     0x00120810
#define    PDATA2_BAND1_PR2B    0x00120810
#define    PDATA2_BAND1_PR3     0x00000000
 /* --------------------- PDATA_BAND1 RXD End --------------------------*/
 /* --------------------- PDATA_BAND2 Start ----------------------------*/
#define    PDATA_BAND2_PR1      0x0011C010
#define    PDATA_BAND2_PR2      0x0011C010
#define    PDATA_BAND2_PR2B     0x0011C010
#define    PDATA_BAND2_PR3      0x00000000
#define    PDATA_BAND2_PT1      0x0011C010
#define    PDATA_BAND2_PT2      0x0011C010
#define    PDATA_BAND2_PT2B     0x0011C010
#define    PDATA_BAND2_PT3      0x00000000
 /* --------------------- PDATA_BAND2 End ------------------------------*/
 /* --------------------- PDATA_BAND2 RXD Start ------------------------*/
#define    PDATA2_BAND2_PR1     0x0011C010
#define    PDATA2_BAND2_PR2     0x0011C010
#define    PDATA2_BAND2_PR2B    0x0011C010
#define    PDATA2_BAND2_PR3     0x00000000
 /* --------------------- PDATA_BAND2 RXD End --------------------------*/
/* --------------------- PDATA_BAND3 Start ---------------------------*/
#define    PDATA_BAND3_PR1      0x00118000
#define    PDATA_BAND3_PR2      0x00118000
#define    PDATA_BAND3_PR2B     0x00118000
#define    PDATA_BAND3_PR3      0x00000000
#define    PDATA_BAND3_PT1      0x00118000
#define    PDATA_BAND3_PT2      0x00118000
#define    PDATA_BAND3_PT2B     0x00118000
#define    PDATA_BAND3_PT3      0x00000000
/* --------------------- PDATA_BAND3 End ------------------------------*/
/* --------------------- PDATA_BAND3 RXD Start ------------------------*/
#define    PDATA2_BAND3_PR1     0x00118000
#define    PDATA2_BAND3_PR2     0x00118000
#define    PDATA2_BAND3_PR2B    0x00118000
#define    PDATA2_BAND3_PR3     0x00000000
/* --------------------- PDATA_BAND3 RXD End --------------------------*/
 /* --------------------- PDATA_BAND5 Start ----------------------------*/
#define    PDATA_BAND5_PR1      0x00134008
#define    PDATA_BAND5_PR2      0x00134008
#define    PDATA_BAND5_PR2B     0x00134008
#define    PDATA_BAND5_PR3      0x00000000
#define    PDATA_BAND5_PT1      0x00134008
#define    PDATA_BAND5_PT2      0x00134008
#define    PDATA_BAND5_PT2B     0x00134008
#define    PDATA_BAND5_PT3      0x00000000
 /* --------------------- PDATA_BAND5 End ------------------------------*/
 /* --------------------- PDATA_BAND5 RXD Start ------------------------*/
#define    PDATA2_BAND5_PR1     0x00134008
#define    PDATA2_BAND5_PR2     0x00134008
#define    PDATA2_BAND5_PR2B    0x00134008
#define    PDATA2_BAND5_PR3     0x00000000
 /* --------------------- PDATA_BAND5 RXD End --------------------------*/
/* --------------------- PDATA_BAND6 Start ----------------------------*/
#define    PDATA_BAND6_PR1      PDATA_BAND5_PR1
#define    PDATA_BAND6_PR2      PDATA_BAND5_PR2
#define    PDATA_BAND6_PR2B     PDATA_BAND5_PR2B
#define    PDATA_BAND6_PR3      PDATA_BAND5_PR3
#define    PDATA_BAND6_PT1      PDATA_BAND5_PT1
#define    PDATA_BAND6_PT2      PDATA_BAND5_PT2
#define    PDATA_BAND6_PT2B     PDATA_BAND5_PT2B
#define    PDATA_BAND6_PT3      PDATA_BAND5_PT3
/* --------------------- PDATA_BAND6 End ------------------------------*/
/* --------------------- PDATA_BAND6 RXD Start ------------------------*/
#define    PDATA2_BAND6_PR1     PDATA2_BAND5_PR1
#define    PDATA2_BAND6_PR2     PDATA2_BAND5_PR2
#define    PDATA2_BAND6_PR2B    PDATA2_BAND5_PR2B
#define    PDATA2_BAND6_PR3     PDATA2_BAND5_PR3
/* --------------------- PDATA_BAND6 RXD End --------------------------*/
 /* --------------------- PDATA_BAND8 Start ----------------------------*/
#define    PDATA_BAND8_PR1      0x00111000
#define    PDATA_BAND8_PR2      0x00111000
#define    PDATA_BAND8_PR2B     0x00111000
#define    PDATA_BAND8_PR3      0x00000000
#define    PDATA_BAND8_PT1      0x00111000
#define    PDATA_BAND8_PT2      0x00111000
#define    PDATA_BAND8_PT2B     0x00111000
#define    PDATA_BAND8_PT3      0x00000000
 /* --------------------- PDATA_BAND8 End ------------------------------*/
 /* --------------------- PDATA_BAND8 RXD Start ------------------------*/
#define    PDATA2_BAND8_PR1     0x00111000
#define    PDATA2_BAND8_PR2     0x00111000
#define    PDATA2_BAND8_PR2B    0x00111000
#define    PDATA2_BAND8_PR3     0x00000000
 /* --------------------- PDATA_BAND8 RXD End --------------------------*/ 
/*MT6169*/ /****************************************************************************/
/*MT6169*/ /* Define your band mode selection on one of five main path LNA ports.      */
/*MT6169*/ /* Each of the 5 independent LNA/mixer/divider are either dedicated to      */
/*MT6169*/ /* either high (VCO divide-by-2) or low (VCO divide-by-4) band.             */
/*MT6169*/ /* TBD: Complete the description later.                                     */
/*MT6169*/ /****************************************************************************/
/*MT6169*/ #define    BAND1_CHANNEL_SEL    LNA_HB_1
/*MT6169*/ #define    BAND2_CHANNEL_SEL    LNA_MB_1
/*MT6169*/ #define    BAND3_CHANNEL_SEL    LNA_HB_1
/*MT6169*/ #define    BAND4_CHANNEL_SEL    NON_USED_BAND
/*MT6169*/ #define    BAND5_CHANNEL_SEL    LNA_LB_3
/*MT6169*/ #define    BAND6_CHANNEL_SEL    NON_USED_BAND
/*MT6169*/ #define    BAND8_CHANNEL_SEL    LNA_LB_2
/*MT6169*/ #define    BAND9_CHANNEL_SEL    NON_USED_BAND
/*MT6169*/ #define    BAND10_CHANNEL_SEL   NON_USED_BAND
/*MT6169*/ #define    BAND11_CHANNEL_SEL   NON_USED_BAND
/*MT6169*/ #define    BAND19_CHANNEL_SEL   NON_USED_BAND
/*MT6169*/
/*MT6169*/  /****************************************************************************/
/*MT6169*/  /* RXD. Descript it later.                                                   */
/*MT6169*/  /****************************************************************************/
/*MT6169*/ #define    BAND1_CHANNEL2_SEL    LNA_RXD_HB_2 
/*MT6169*/ #define    BAND2_CHANNEL2_SEL    LNA_RXD_HB_1 
/*MT6169*/ #define    BAND3_CHANNEL2_SEL    LNA_RXD_MB_1
/*MT6169*/ #define    BAND4_CHANNEL2_SEL    NON_USED_BAND
/*MT6169*/ #define    BAND5_CHANNEL2_SEL    LNA_RXD_LB_2 
/*MT6169*/ #define    BAND6_CHANNEL2_SEL    NON_USED_BAND
/*MT6169*/ #define    BAND8_CHANNEL2_SEL    LNA_RXD_LB_1
/*MT6169*/ #define    BAND9_CHANNEL2_SEL    NON_USED_BAND
/*MT6169*/ #define    BAND10_CHANNEL2_SEL   NON_USED_BAND
/*MT6169*/ #define    BAND11_CHANNEL2_SEL   NON_USED_BAND
/*MT6169*/ #define    BAND19_CHANNEL2_SEL   NON_USED_BAND
/*MT6169*/ /************************************************************/
/*MT6169*/ /* Define your tx output selection                          */
/*MT6169*/ /* There are two high band and one low band to choose.      */
/*MT6169*/ /* All options are listed below:                            */
/*MT6169*/ /* TX_HIGH_BAND3/TX_HIGH_BAND2/TX_LOW_BAND1/TX_NULL_BAND    */
/*MT6169*/ /************************************************************/
/*MT6169*/ #define    BAND1_OUTPUT_SEL     TX_MB_2
/*MT6169*/ #define    BAND2_OUTPUT_SEL     TX_MB_2
/*MT6169*/ #define    BAND3_OUTPUT_SEL     TX_MB_2
/*MT6169*/ #define    BAND4_OUTPUT_SEL     TX_NULL_BAND
/*MT6169*/ #define    BAND5_OUTPUT_SEL     TX_LB_2
/*MT6169*/ #define    BAND6_OUTPUT_SEL     TX_NULL_BAND
/*MT6169*/ #define    BAND8_OUTPUT_SEL     TX_LB_2
/*MT6169*/ #define    BAND9_OUTPUT_SEL     TX_NULL_BAND
/*MT6169*/ #define    BAND10_OUTPUT_SEL    TX_NULL_BAND
/*MT6169*/ #define    BAND11_OUTPUT_SEL    TX_NULL_BAND
/*MT6169*/ #define    BAND19_OUTPUT_SEL    TX_NULL_BAND
/*MT6169*/
/*MT6169*/ /************************************************************/
/*MT6169*/ /* For Single SW vs. multiple HW feature                    */
/*MT6169*/ /* Let the NVRAN BPI setting overwrite the GPIO BPI setting,*/
/*MT6169*/ /* If they are not the same (wrong config. by customer)     */
/*MT6169*/ /************************************************************/
/*MT6169*/ #define    RF_SETTING_BY_NVRAM   KAL_FALSE
/*MT6169*/ /************************************************************/
/*MT6169*/ /* For using the V-battery as instead setting               */
/*MT6169*/ /************************************************************/
/*MT6169*/ #define    PMU_PASETTING         KAL_TRUE
/*MT6169*/ /************************************************************/
/*MT6169*/ /* For RXD single test, customer may use the RXD only,      */
/*MT6169*/ /* need to write RX_MAIN_PATH_ON & RX_DIVERSITY_PATH_ON to  */
/*MT6169*/ /* 0xFFFFFFFF after test                               */
/*MT6169*/ /************************************************************/
/*MT6169*/ #define    RX_DIVERSITY_ALWAYS_ON KAL_FALSE
/*MT6169*/ /************************************************************/
/*MT6169*/ /* For PA drift compensation by different band's PA         */
/*MT6169*/ /************************************************************/
/*MT6169*/ #define    PA_DIRFT_COMPENSATION 0x00000000
/*MT6169*/
/*MT6169*/ /************************************************************/
/*MT6169*/ /* For MPR back off for SAR& lowering PA temerature& UPA/DPA*/
/*MT6169*/ /* PAPR concern                                             */
/*MT6169*/ /************************************************************/
/*MT6169*/ #define    MPR_BACK_OFF_HSDPA_BAND1  MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSDPA_BAND2  MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSDPA_BAND3  MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSDPA_BAND4  MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSDPA_BAND5  MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSDPA_BAND6  MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSDPA_BAND8  MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSDPA_BAND9  MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSDPA_BAND10 MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSDPA_BAND11 MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSDPA_BAND19 MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSUPA_BAND1  MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSUPA_BAND2  MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSUPA_BAND3  MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSUPA_BAND4  MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSUPA_BAND5  MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSUPA_BAND6  MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSUPA_BAND8  MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSUPA_BAND9  MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSUPA_BAND10 MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSUPA_BAND11 MPRSetting2
/*MT6169*/ #define    MPR_BACK_OFF_HSUPA_BAND19 MPRSetting2
/*MT6169*/
/*MT6169*/ /************************************************************/
/*MT6169*/ /* At MT6589+MT6320PMIC, Vrf18_1(MD1) can use bulk/LDO mode */
/*MT6169*/ /* take bulk mode as default value*/
/*MT6169*/ /************************************************************/
/*MT6169*/ #define    ULTRA_LOW_COST_EN 0
/*MT6169*/
/*MT6169*/ #define    RX_HIGHBAND1_INDICATOR UMTSBand1
/*MT6169*/ #define    RX_HIGHBAND2_INDICATOR UMTSBand2
/*MT6169*/ #define    RX_HIGHBAND3_INDICATOR UMTSBandNone
/*MT6169*/ #define    RX_LOWBAND1_INDICATOR UMTSBand5
/*MT6169*/ #define    RX_LOWBAND2_INDICATOR UMTSBand8


/*============================================================================== */

#endif
