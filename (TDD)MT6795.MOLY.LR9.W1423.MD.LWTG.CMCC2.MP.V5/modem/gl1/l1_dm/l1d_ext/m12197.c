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
 *   m12197.c
 *
 * Project:
 * --------
 *   MT6573
 *
 * Description:
 * ------------
 *   ModemBinUpdate feature
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime:  $
 * $Log:      $
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 *******************************************************************************/

#include "l1d_loc_def.h"
#include "m12193.h"
#include "m12197.h"
#include "l1d_rf.h"

#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2

#ifndef  GSM_ERR_DET_ID
#define  GSM_ERR_DET_ID        9  //<--temp use, each rf should define this in l1d_custom_rf.h
#endif

#ifndef  Custom_RF_XO_CapID
#define  Custom_RF_XO_CapID    31
#endif

/*----------------------------------------*/
/* data for BBTX setting                  */
/*----------------------------------------*/
#ifdef GSM850_IN_GSM900_PATH
#define  GSM850_GSM900_SWAP    GSM850_IN_GSM900_PATH
#endif
#ifndef  GSM850_GSM900_SWAP
#define  GSM850_GSM900_SWAP    0
#endif
#ifndef  DCS1800_PCS1900_SWAP
#define  DCS1800_PCS1900_SWAP  0
#endif

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void TX_Default_Setting(int16 *dst, int16 defaultvalue)
{
   if(*dst==(int16)RFDEF)
      *dst=defaultvalue;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Default_Setting_int8(int8 *dst, int8 defaultvalue)
{
   if(*dst==(int8)RFDEF_short)
      *dst=defaultvalue;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Default_Setting_int16(int16 *dst, int16 defaultvalue)
{
   if(*dst==(int16)RFDEF)
      *dst=defaultvalue;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

   #if IS_RF_MT6140D
#define RF_TYPE      1
   #elif IS_RF_AD6548
#define RF_TYPE      2
   #elif IS_RF_AD6546
#define RF_TYPE      3
   #elif IS_RF_MT6162
#define RF_TYPE      4
   #else
#define RF_TYPE      1
   #endif

   #if !IS_BSI_TRIG_OFFCHIP_BPI_SUPPORT
#define PDATA_GSM850_SR0 0
#define PDATA_GSM850_SR3 0
#define PDATA_GSM850_ST0 0
#define PDATA_GSM850_ST3 0
#define PDATA_GSM_SR0    0
#define PDATA_GSM_SR3    0
#define PDATA_GSM_ST0    0
#define PDATA_GSM_ST3    0
#define PDATA_DCS_SR0    0
#define PDATA_DCS_SR3    0
#define PDATA_DCS_ST0    0
#define PDATA_DCS_ST3    0
#define PDATA_PCS_SR0    0
#define PDATA_PCS_SR3    0
#define PDATA_PCS_ST0    0
#define PDATA_PCS_ST3    0
   #endif

sL1D_RF_CUSTOM_INPUT_DATA l1d_rf_custom_input_data=
{
   0x12345678,                                                            // the special pattern of start position
   1,                                                                     // Struct Version ID
   RF_TYPE,                                                               // default set MT6140D_RF
   1,                                                                     // default is false, and will be changed  as true after tool update
   //sRF_BPI_VARIABLE
   {
      PDATA_GSM850_PR1,
      PDATA_GSM850_PR2,
      PDATA_GSM850_PR2B,
      PDATA_GSM850_PR3,
      PDATA_GSM850_PR3A,
      PDATA_GSM850_PT1,
      PDATA_GSM850_PT2,
      PDATA_GSM850_PT2B,
      PDATA_GSM850_PT3,
      PDATA_GSM850_PT3A,
      PDATA_GSM_PR1,
      PDATA_GSM_PR2,
      PDATA_GSM_PR2B,
      PDATA_GSM_PR3,
      PDATA_GSM_PR3A,
      PDATA_GSM_PT1,
      PDATA_GSM_PT2,
      PDATA_GSM_PT2B,
      PDATA_GSM_PT3,
      PDATA_GSM_PT3A,
      PDATA_DCS_PR1,
      PDATA_DCS_PR2,
      PDATA_DCS_PR2B,
      PDATA_DCS_PR3,
      PDATA_DCS_PR3A,
      PDATA_DCS_PT1,
      PDATA_DCS_PT2,
      PDATA_DCS_PT2B,
      PDATA_DCS_PT3,
      PDATA_DCS_PT3A,
      PDATA_PCS_PR1,
      PDATA_PCS_PR2,
      PDATA_PCS_PR2B,
      PDATA_PCS_PR3,
      PDATA_PCS_PR3A,
      PDATA_PCS_PT1,
      PDATA_PCS_PT2,
      PDATA_PCS_PT2B,
      PDATA_PCS_PT3,
      PDATA_PCS_PT3A,
      PDATA_GSM850_PR2M1,
      PDATA_GSM850_PR2M2,
      PDATA_GSM850_PR2M3,
      PDATA_GSM850_PT2M1_G8,
      PDATA_GSM850_PT2M2_G8,
      PDATA_GSM850_PT2M3_G8,
      PDATA_GSM850_PT2M1_8G,
      PDATA_GSM850_PT2M2_8G,
      PDATA_GSM850_PT2M3_8G,
      PDATA_GSM_PR2M1,
      PDATA_GSM_PR2M2,
      PDATA_GSM_PR2M3,
      PDATA_GSM_PT2M1_G8,
      PDATA_GSM_PT2M2_G8,
      PDATA_GSM_PT2M3_G8,
      PDATA_GSM_PT2M1_8G,
      PDATA_GSM_PT2M2_8G,
      PDATA_GSM_PT2M3_8G,
      PDATA_DCS_PR2M1,
      PDATA_DCS_PR2M2,
      PDATA_DCS_PR2M3,
      PDATA_DCS_PT2M1_G8,
      PDATA_DCS_PT2M2_G8,
      PDATA_DCS_PT2M3_G8,
      PDATA_DCS_PT2M1_8G,
      PDATA_DCS_PT2M2_8G,
      PDATA_DCS_PT2M3_8G,
      PDATA_PCS_PR2M1,
      PDATA_PCS_PR2M2,
      PDATA_PCS_PR2M3,
      PDATA_PCS_PT2M1_G8,
      PDATA_PCS_PT2M2_G8,
      PDATA_PCS_PT2M3_G8,
      PDATA_PCS_PT2M1_8G,
      PDATA_PCS_PT2M2_8G,
      PDATA_PCS_PT2M3_8G,
      PDATA_INIT,
      PDATA_IDLE,
      PDATA_GMSK,
      PDATA_8PSK,
      {  // sRF_PDATA_OFFCHIP
         { PDATA_GSM850_SR0, PDATA_GSM850_SR3, PDATA_GSM850_ST0, PDATA_GSM850_ST3, }, /* GSM850 */
         { PDATA_GSM_SR0,    PDATA_GSM_SR3,    PDATA_GSM_ST0,    PDATA_GSM_ST3,    }, /* GSM    */
         { PDATA_DCS_SR0,    PDATA_DCS_SR3,    PDATA_DCS_ST0,    PDATA_DCS_ST3,    }, /* DCS    */
         { PDATA_PCS_SR0,    PDATA_PCS_SR3,    PDATA_PCS_ST0,    PDATA_PCS_ST3,    }, /* PCS    */
      },
   },
   //sRF_TIMING_VARIABLE
   {
      QB_RX_FENA_2_FSYNC,
      QB_RX_FSYNC_2_FENA,
      QB_TX_FENA_2_FSYNC,
      QB_TX_FSYNC_2_FENA,
      QB_SR0,
      QB_SR1,
      QB_SR2,
      QB_SR3,
      QB_SR2M,
      QB_PR1,
      QB_PR2,
      QB_PR2B,
      QB_PR3,
      QB_PR3A,
      QB_PR2M1,
      QB_PR2M2,
      QB_ST0,
      QB_ST1,
      QB_ST2,
      QB_ST2B,
      QB_ST3,
      QB_ST2M_G8,
      QB_ST2M_8G,
      QB_PT1,
      QB_PT2,
      QB_PT2B,
      QB_PT3,
      QB_PT3A,
      QB_PT2M1_G8,
      QB_PT2M2_G8,
      QB_PT2M3_G8,
      QB_PT2M1_8G,
      QB_PT2M2_8G,
      QB_PT2M3_8G,
      QB_APCON,
      QB_APCMID,
      QB_APCOFF,
      QB_APCDACON,
   },
   //sRF_APC_COMPENSATE_VARIABLE
   {
      BAT_VOLTAGE_SAMPLE_PERIOD_SECOND,     //BAT_VOLTAGE_SAMPLE_PERIOD,
      BAT_VOLTAGE_AVERAGE_COUNT,            //BAT_VOLTAGE_AVERAGE_COUNT,
      BAT_TEMPERATURE_SAMPLE_PERIOD_SECOND, //BAT_TEMPERATURE_SAMPLE_PERIOD,
      BAT_TEMPERATURE_AVERAGE_COUNT,        //BAT_TEMPERATURE_AVERAGE_COUNT,
      (BAT_LOW_VOLTAGE_TRHESHOLD*10),       //BAT_LOW_VOLTAGE,
      (BAT_HIGH_VOLTAGE_TRHESHOLD*10),      //BAT_HIGH_VOLTAGE,
      BAT_LOW_TEMPERATURE_TRHESHOLD,        //BAT_LOW_TEMPERATURE,
      BAT_HIGH_TEMPERATURE_TRHESHOLD,       //BAT_HIGH_TEMPERATURE,
      RF_TEMPERATURE_SAMPLE_PERIOD_SECOND,  //RF_TEMPERATURE_SAMPLE_PERIOD,     // OH
      RF_TEMPERATURE_AVERAGE_COUNT,         //RF_TEMPERATURE_AVERAGE_COUNT,     // OH
   },
   //sRF_PCL_VARIABLE
   {
      RFDEF,                            // txios_highpcl_850_GMSK;
      RFDEF,                            // txios_highpcl_900_GMSK;
      RFDEF,                            // txios_highpcl_DCS_GMSK;
      RFDEF,                            // txios_highpcl_PCS_GMSK;
      RFDEF,                            // txios_highpcl_850_EPSK;
      RFDEF,                            // txios_highpcl_900_EPSK;
      RFDEF,                            // txios_highpcl_DCS_EPSK;
      RFDEF,                            // txios_highpcl_PCS_EPSK;
      RFDEF,                            // txios_lowpcl_850_GMSK;
      RFDEF,                            // txios_lowpcl_900_GMSK;
      RFDEF,                            // txios_lowpcl_DCS_GMSK;
      RFDEF,                            // txios_lowpcl_PCS_GMSK;
      RFDEF,                            // txios_lowpcl_850_EPSK;
      RFDEF,                            // txios_lowpcl_900_EPSK;
      RFDEF,                            // txios_lowpcl_DCS_EPSK;
      RFDEF,                            // txios_lowpcl_PCS_EPSK;
   },
   //sRF_LBMOD_GC_VARIABLE
   {
      RFDEF,                            // lbmod_gc_highpcl_850_GMSK;
      RFDEF,                            // lbmod_gc_highpcl_900_GMSK;
      RFDEF,                            // lbmod_gc_highpcl_DCS_GMSK;
      RFDEF,                            // lbmod_gc_highpcl_PCS_GMSK;
      RFDEF,                            // lbmod_gc_highpcl_850_EPSK;
      RFDEF,                            // lbmod_gc_highpcl_900_EPSK;
      RFDEF,                            // lbmod_gc_highpcl_DCS_EPSK;
      RFDEF,                            // lbmod_gc_highpcl_PCS_EPSK;
      RFDEF,                            // lbmod_gc_lowpcl_850_GMSK;
      RFDEF,                            // lbmod_gc_lowpcl_900_GMSK;
      RFDEF,                            // lbmod_gc_lowpcl_DCS_GMSK;
      RFDEF,                            // lbmod_gc_lowpcl_PCS_GMSK;
      RFDEF,                            // lbmod_gc_lowpcl_850_EPSK;
      RFDEF,                            // lbmod_gc_lowpcl_900_EPSK;
      RFDEF,                            // lbmod_gc_lowpcl_DCS_EPSK;
      RFDEF,                            // lbmod_gc_lowpcl_PCS_EPSK;
   },
   //sRF_HBMOD_GC_VARIABLE
   {
      RFDEF,                             // hbmod_gc_highpcl_850_GMSK;
      RFDEF,                             // hbmod_gc_highpcl_900_GMSK;
      RFDEF,                             // hbmod_gc_highpcl_DCS_GMSK;
      RFDEF,                             // hbmod_gc_highpcl_PCS_GMSK;
      RFDEF,                             // hbmod_gc_highpcl_850_EPSK;
      RFDEF,                             // hbmod_gc_highpcl_900_EPSK;
      RFDEF,                             // hbmod_gc_highpcl_DCS_EPSK;
      RFDEF,                             // hbmod_gc_highpcl_PCS_EPSK;
      RFDEF,                             // hbmod_gc_lowpcl_850_GMSK;
      RFDEF,                             // hbmod_gc_lowpcl_900_GMSK;
      RFDEF,                             // hbmod_gc_lowpcl_DCS_GMSK;
      RFDEF,                             // hbmod_gc_lowpcl_PCS_GMSK;
      RFDEF,                             // hbmod_gc_lowpcl_850_EPSK;
      RFDEF,                             // hbmod_gc_lowpcl_900_EPSK;
      RFDEF,                             // hbmod_gc_lowpcl_DCS_EPSK;
      RFDEF,                             // hbmod_gc_lowpcl_PCS_EPSK;
   },
   //sRF_ITC_PCL_VARIABLE
   {
      RFDEF,                             // txitc_highpcl_850_GMSK;
      RFDEF,                             // txitc_highpcl_900_GMSK;
      RFDEF,                             // txitc_highpcl_DCS_GMSK;
      RFDEF,                             // txitc_highpcl_PCS_GMSK;
      RFDEF,                             // txitc_highpcl_850_EPSK;
      RFDEF,                             // txitc_highpcl_900_EPSK;
      RFDEF,                             // txitc_highpcl_DCS_EPSK;
      RFDEF,                             // txitc_highpcl_PCS_EPSK;
      RFDEF,                             // txitc_lowpcl_850_GMSK;
      RFDEF,                             // txitc_lowpcl_900_GMSK;
      RFDEF,                             // txitc_lowpcl_DCS_GMSK;
      RFDEF,                             // txitc_lowpcl_PCS_GMSK;
      RFDEF,                             // txitc_lowpcl_850_EPSK;
      RFDEF,                             // txitc_lowpcl_900_EPSK;
      RFDEF,                             // txitc_lowpcl_DCS_EPSK;
      RFDEF,                             // txitc_lowpcl_PCS_EPSK;
   },
   //sRF_TX_POWERFEEDBACK_VARIABLE
   {
      RFDEF_short,
      QB_TX_SAMPLE_OFFSET_GMSK,
      QB_TX_SAMPLE_OFFSET_EPSK,
      TXPC_EPSK_TP_SLOPE_LB,
      TXPC_EPSK_TP_SLOPE_HB,
   },
   //sRF_TX_POWER_ROLLBACK_VARIABLE
   {
      {GSM850_TX_ROLLBACK_2T_GMSK, GSM850_TX_ROLLBACK_3T_GMSK, GSM850_TX_ROLLBACK_4T_GMSK, GSM850_TX_ROLLBACK_5T_GMSK},//GMSK
      {GSM_TX_ROLLBACK_2T_GMSK,    GSM_TX_ROLLBACK_3T_GMSK,    GSM_TX_ROLLBACK_4T_GMSK,    GSM_TX_ROLLBACK_5T_GMSK   },
      {DCS_TX_ROLLBACK_2T_GMSK,    DCS_TX_ROLLBACK_3T_GMSK,    DCS_TX_ROLLBACK_4T_GMSK,    DCS_TX_ROLLBACK_5T_GMSK   },
      {PCS_TX_ROLLBACK_2T_GMSK,    PCS_TX_ROLLBACK_3T_GMSK,    PCS_TX_ROLLBACK_4T_GMSK,    PCS_TX_ROLLBACK_5T_GMSK   },
      {GSM850_TX_ROLLBACK_2T_EPSK, GSM850_TX_ROLLBACK_3T_EPSK, GSM850_TX_ROLLBACK_4T_EPSK, GSM850_TX_ROLLBACK_5T_EPSK},//8PSK
      {GSM_TX_ROLLBACK_2T_EPSK,    GSM_TX_ROLLBACK_3T_EPSK,    GSM_TX_ROLLBACK_4T_EPSK,    GSM_TX_ROLLBACK_5T_EPSK   },
      {DCS_TX_ROLLBACK_2T_EPSK,    DCS_TX_ROLLBACK_3T_EPSK,    DCS_TX_ROLLBACK_4T_EPSK,    DCS_TX_ROLLBACK_5T_EPSK   },
      {PCS_TX_ROLLBACK_2T_EPSK,    PCS_TX_ROLLBACK_3T_EPSK,    PCS_TX_ROLLBACK_4T_EPSK,    PCS_TX_ROLLBACK_5T_EPSK   },
   },
   //sRF_RX_BAND_VARIABLE;
   {
      GSM850_PATH_SEL,
      GSM_PATH_SEL,
      DCS_PATH_SEL,
      PCS_PATH_SEL,
   },
   //sRF_OTHERS_VARIABLE
   {
      Custom_RF_XO_CapID,
      PSI_EE,
      C_PSI_STA,
      IS_EGSM900_DISABLE,	
      GSM850_GSM900_SWAP,
      DCS1800_PCS1900_SWAP,
      GSM_ERR_DET_ID, //OH
      TX_PROPAGATION_DELAY,
      TQ_EPSK_TX_DELAY,
   },
   //sRF_AFC_TRACKING_VARIABLE
   {
      0,
      416,
      16,
   },
   //sRF_CLK_BUFFER_VARIABLE
   {
      CLK1_EN,
      CLK2_EN,
      CLK3_EN,
      CLK4_EN,
   },
   //sRF_TX_PORT_VARIABLE
   {
      GSM850_PORT_SEL,
      GSM_PORT_SEL   ,
      DCS_PORT_SEL   ,
      PCS_PORT_SEL   ,
   },
   0x87654321,                         //the special pattern of end2 position

};
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_TX_POWER_OFFSET_SUPPORT
s2G_RF_PARAMETER_EXT l1d_rf_custom_input_data_ext =
{
   {
      TPO_2G_ENABLE,                /* tx_power_offset_enable           : Enable Tx power offset */
      TPO_2G_META_ENABLE,           /* meta_tx_power_offset_enable   : The main purpose of "meta_tx_power_offset_enable" is to disable power offset during calibration */
      TPO_2G_TABLE_ON_MASK,         /* offset_table_on_mask              : Turn on offset table. ex:bit0=1 --> apply offset in table 0  */
      {
         TPO_2G_BIT_NUM_FOR_TABLE_0,
         TPO_2G_BIT_NUM_FOR_TABLE_1
      }
   }
};
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_BPI_DefaultValue_Handler(void)
{

}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_APC_Compensate_DefaultValue_Handler(void)
{

}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_Timing_DefaultValue_Handler(void)
{

}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_TX_PCL_DefaultValue_Handler(void)
{
   sRF_PCL_VARIABLE      *p =&l1d_rf_custom_input_data.RF_PCL_Varaible;
   sRF_ITC_PCL_VARIABLE  *p1=&l1d_rf_custom_input_data.RF_ITC_PCL_Variable;
   sRF_LBMOD_GC_VARIABLE *p2=&l1d_rf_custom_input_data.RF_Lbmod_GC_Variable;
   sRF_HBMOD_GC_VARIABLE *p3=&l1d_rf_custom_input_data.RF_Hbmod_GC_Variable;
	
   //BPI_default_setting(&l1_rf_data.rfBPI.xPDATA_GSM_PT2M2_8G,l1_rf_data.rfBPI.xP
   TX_Default_Setting(&p->txios_highpcl_850_GMSK,2);
   TX_Default_Setting(&p->txios_highpcl_900_GMSK,6);
   TX_Default_Setting(&p->txios_highpcl_DCS_GMSK,0);
   TX_Default_Setting(&p->txios_highpcl_PCS_GMSK,0);

   TX_Default_Setting(&p->txios_highpcl_850_EPSK,0);
   TX_Default_Setting(&p->txios_highpcl_900_EPSK,2);
   TX_Default_Setting(&p->txios_highpcl_DCS_EPSK,0);
   TX_Default_Setting(&p->txios_highpcl_PCS_EPSK,0);

   TX_Default_Setting(&p->txios_lowpcl_850_GMSK,2);
   TX_Default_Setting(&p->txios_lowpcl_900_GMSK,6);
   TX_Default_Setting(&p->txios_lowpcl_DCS_GMSK,0);
   TX_Default_Setting(&p->txios_lowpcl_PCS_GMSK,0);

   TX_Default_Setting(&p->txios_lowpcl_850_EPSK,5);
   TX_Default_Setting(&p->txios_lowpcl_900_EPSK,7);
   TX_Default_Setting(&p->txios_lowpcl_DCS_EPSK,0);
   TX_Default_Setting(&p->txios_lowpcl_PCS_EPSK,0);

   //BPI_default_setting(&l1_rf_data.rfBPI.xPDATA_GSM_PT2M2_8G,l1_rf_data.rfBPI.xP
   TX_Default_Setting(&p1->txitc_highpcl_850_GMSK,0x0);
   TX_Default_Setting(&p1->txitc_highpcl_900_GMSK,0x0);
   TX_Default_Setting(&p1->txitc_highpcl_DCS_GMSK,0x0);
   TX_Default_Setting(&p1->txitc_highpcl_PCS_GMSK,0x0);

   TX_Default_Setting(&p1->txitc_highpcl_850_EPSK,0x9);
   TX_Default_Setting(&p1->txitc_highpcl_900_EPSK,0x9);
   TX_Default_Setting(&p1->txitc_highpcl_DCS_EPSK,0x7);
   TX_Default_Setting(&p1->txitc_highpcl_PCS_EPSK,0x7);

   TX_Default_Setting(&p1->txitc_lowpcl_850_GMSK,0x0);
   TX_Default_Setting(&p1->txitc_lowpcl_900_GMSK,0x0);
   TX_Default_Setting(&p1->txitc_lowpcl_DCS_GMSK,0x0);
   TX_Default_Setting(&p1->txitc_lowpcl_PCS_GMSK,0x0);

   TX_Default_Setting(&p1->txitc_lowpcl_850_EPSK,0x9);
   TX_Default_Setting(&p1->txitc_lowpcl_900_EPSK,0x9);
   TX_Default_Setting(&p1->txitc_lowpcl_DCS_EPSK,0x7);
   TX_Default_Setting(&p1->txitc_lowpcl_PCS_EPSK,0x7);

   TX_Default_Setting(&p2->lbmod_gc_highpcl_850_GMSK,0x1);
   TX_Default_Setting(&p2->lbmod_gc_highpcl_900_GMSK,0x1);
   TX_Default_Setting(&p2->lbmod_gc_highpcl_DCS_GMSK,0x1);
   TX_Default_Setting(&p2->lbmod_gc_highpcl_PCS_GMSK,0x1);

   TX_Default_Setting(&p2->lbmod_gc_highpcl_850_EPSK,0x1);
   TX_Default_Setting(&p2->lbmod_gc_highpcl_900_EPSK,0x1);
   TX_Default_Setting(&p2->lbmod_gc_highpcl_DCS_EPSK,0x1);
   TX_Default_Setting(&p2->lbmod_gc_highpcl_PCS_EPSK,0x1);

   TX_Default_Setting(&p2->lbmod_gc_lowpcl_850_GMSK,0x1);
   TX_Default_Setting(&p2->lbmod_gc_lowpcl_900_GMSK,0x1);
   TX_Default_Setting(&p2->lbmod_gc_lowpcl_DCS_GMSK,0x1);
   TX_Default_Setting(&p2->lbmod_gc_lowpcl_PCS_GMSK,0x1);

   TX_Default_Setting(&p2->lbmod_gc_lowpcl_850_EPSK,0x1);
   TX_Default_Setting(&p2->lbmod_gc_lowpcl_900_EPSK,0x1);
   TX_Default_Setting(&p2->lbmod_gc_lowpcl_DCS_EPSK,0x1);
   TX_Default_Setting(&p2->lbmod_gc_lowpcl_PCS_EPSK,0x1);

   TX_Default_Setting(&p3->hbmod_gc_highpcl_850_GMSK,0x0);
   TX_Default_Setting(&p3->hbmod_gc_highpcl_900_GMSK,0x0);
   TX_Default_Setting(&p3->hbmod_gc_highpcl_DCS_GMSK,0x0);
   TX_Default_Setting(&p3->hbmod_gc_highpcl_PCS_GMSK,0x0);

   TX_Default_Setting(&p3->hbmod_gc_highpcl_850_EPSK,0x1);
   TX_Default_Setting(&p3->hbmod_gc_highpcl_900_EPSK,0x1);
   TX_Default_Setting(&p3->hbmod_gc_highpcl_DCS_EPSK,0x1);
   TX_Default_Setting(&p3->hbmod_gc_highpcl_PCS_EPSK,0x1);

   TX_Default_Setting(&p3->hbmod_gc_lowpcl_850_GMSK,0x0);
   TX_Default_Setting(&p3->hbmod_gc_lowpcl_900_GMSK,0x0);
   TX_Default_Setting(&p3->hbmod_gc_lowpcl_DCS_GMSK,0x0);
   TX_Default_Setting(&p3->hbmod_gc_lowpcl_PCS_GMSK,0x0);

   TX_Default_Setting(&p3->hbmod_gc_lowpcl_850_EPSK,0x1);
   TX_Default_Setting(&p3->hbmod_gc_lowpcl_900_EPSK,0x1);
   TX_Default_Setting(&p3->hbmod_gc_lowpcl_DCS_EPSK,0x3);
   TX_Default_Setting(&p3->hbmod_gc_lowpcl_PCS_EPSK,0x3);
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_TX_Power_Control_DefaultValue_Handler(void)
{
   #if IS_TX_POWER_CONTROL_SUPPORT
   sRF_TX_POWERFEEDBACK_VARIABLE *p=&l1d_rf_custom_input_data.RF_TX_PowerFeedback_Variable;

      #if IS_TXPC_CL_BSI_SUPPORT && IS_BSI_CLOSED_LOOP_TXPC_ON
   Default_Setting_int8(&p->xCLOSED_LOOP_TXPC_TYPE,2);
      #elif IS_TXPC_CL_AUXADC_SUPPORT && IS_AUXADC_CLOSED_LOOP_TXPC_ON
   Default_Setting_int8(&p->xCLOSED_LOOP_TXPC_TYPE,1);
      #else
   Default_Setting_int8(&p->xCLOSED_LOOP_TXPC_TYPE,0);
      #endif

   Default_Setting_int16(&p->xQB_TX_SAMPLE_OFFSET_GMSK,0);
   Default_Setting_int16(&p->xQB_TX_SAMPLE_OFFSET_EPSK,0);
   Default_Setting_int16(&p->xTXPC_EPSK_TP_SLOPE_LB,1);
   Default_Setting_int16(&p->xTXPC_EPSK_TP_SLOPE_HB,1);
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_TX_Power_Rollback_DefaultValue_Handler(void)
{

}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_RF_RX_Band_DefaultValue_Handler(void)
{

}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_Others_DefaultValue_Handler(void)
{

}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_AFC_Tracking_DefaultValue_Handler(void)
{

}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_RF_CLK_Buffer_Variable_DefaultValue_Handler(void)
{

}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_RF_Custom_RF_TX_Port_DefaultValue_Handler(void)
{

}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


#endif //#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2

