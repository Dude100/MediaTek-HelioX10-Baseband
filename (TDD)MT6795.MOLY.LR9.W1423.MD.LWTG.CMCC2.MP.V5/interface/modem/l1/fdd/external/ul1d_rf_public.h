/*******************************************************************************
*  Modification Notice :
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/


/*****************************************************************************
 *
 * Filename:
 * ---------
 * ul1d_rf_public.h
 *
 * Project:
 * --------
 *   3G Project Common File
 *
 * Description:
 * ------------
 *   Definition of some of customization setting not defined in ul1d_custom_rf.h
 *   And the stuff needs to be recognized by UL1D external module (wdata.c)
 *   Also some of data structure, global data, global function prototypes to be used
 *   by inter-category module (e.g. NVRAM)
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/
#ifndef UL1D_RF_PUBLIC_H
#define UL1D_RF_PUBLIC_H


/*******************************************************************************
** Includes
*******************************************************************************/
#include "ul1d_rf_cid.h"
#if (IS_3G_MIPI_SUPPORT)
#include "ul1d_custom_mipi.h"
#endif

/*******************************************************************************
** Setting for specific RF
*******************************************************************************/

#if IS_RF_SMARTI3G

/*SMARTI3G*/
/*SMARTI3G*/ #define  VBIAS_MODE     1
/*SMARTI3G*/ #define  VM_H           0
/*SMARTI3G*/ #define  VM_M           1
/*SMARTI3G*/ #define  VM_L           1
/*SMARTI3G*/ #define  DC2DC_H        1
/*SMARTI3G*/ #define  DC2DC_M        0
/*SMARTI3G*/ #define  DC2DC_L        0
/*SMARTI3G*/
////////////////////////////////////////////////////////////////////////////////

#elif IS_RF_MT6159D

/*MT6159D*/
/*MT6159D*/ #define  VBIAS_MODE     1 
/*MT6159D*/ #define  VM_H           0
/*MT6159D*/ #define  VM_M           0
/*MT6159D*/ #define  VM_L           0 
/*MT6159D*/ #define  DC2DC_H        1
/*MT6159D*/ #define  DC2DC_M        0
/*MT6159D*/ #define  DC2DC_L        0
/*MT6159D*/
////////////////////////////////////////////////////////////////////////////////

#elif IS_RF_MT6160
/*MT6160*/ 
/*MT6160*/ #define  NUMBER_OF_VGA_DAC         10
/*MT6160*/ 
/*MT6160*/ /*****************************************/
/*MT6160*/ /* Define band mode mapped receiver type */
/*MT6160*/ /* DO NOT MODIFY the definitions here    */
/*MT6160*/ /*****************************************/
/*MT6160*/ #define  HIGH_BAND1                0x1
/*MT6160*/ #define  HIGH_BAND2                0x2
/*MT6160*/ #define  LOW_BAND                  0xF
/*MT6160*/ #define  NON_USED_BAND             0x0
/*MT6160*/ 
/*MT6160*/ /* Bit shift of data field of Reg.0 8-bit sub-registers */
/*MT6160*/ #define  READ_REG0_DATA_FIELD_BIT_SHIFT  18
/*MT6160*/ 
/*MT6160*/ /* Path Select for Transmitter sections */
/*MT6160*/ #define TX_HIGH_BAND3    6
/*MT6160*/ #define TX_HIGH_BAND2    5
/*MT6160*/ #define TX_LOW_BAND1     0
/*MT6160*/ #define TX_NULL_BAND     8
/*MT6160*/
/*MT6160*/ #define  VBIAS_MODE     1
/*MT6160*/ #define  VM_H           0
/*MT6160*/ #define  VM_M           1
/*MT6160*/ #define  VM_L           3
/*MT6160*/ #define  DC2DC_H        1
/*MT6160*/ #define  DC2DC_M        0
/*MT6160*/ #define  DC2DC_L        0
/*MT6160*/ #define  NUMBER_OF_CALI_DATA_ELEMENT 3
/*MT6160*/
/*MT6160*/ #define  TC_SR1               MICROSECOND_TO_CHIP(342)                                         
/*MT6160*/ #define  TC_SR2               MICROSECOND_TO_CHIP(267)                                         
/*MT6160*/ #define  TC_SR2B              MICROSECOND_TO_CHIP( 37)                                         
/*MT6160*/ #define  TC_SR3               MICROSECOND_TO_CHIP( 22)
/*MT6160*/ #define  TC_ST1               MICROSECOND_TO_CHIP(357)                                    
/*MT6160*/ #define  TC_ST2               MICROSECOND_TO_CHIP(287)
/*MT6160*/ #define  TC_ST2C              MICROSECOND_TO_CHIP( 57)                                        
/*MT6160*/ #define  TC_ST2B              MICROSECOND_TO_CHIP( 57)                                         
/*MT6160*/ #define  TC_ST3               MICROSECOND_TO_CHIP(  2)
/*MT6160*/
////////////////////////////////////////////////////////////////////////////////

#elif IS_RF_MT6162
/*MT6162*/ 
/*MT6162*/ #if defined(AFC_VCXO)
/*MT6162*/ #define IS_R6_DCXO_SUPPORT           1
/*MT6162*/ #endif
/*MT6162*/ 
/*MT6162*/ #define  NUMBER_OF_VGA_DAC           10
/*MT6162*/ 
/*MT6162*/ #define  UMTS_RF_TYPE  1
/*MT6162*/ 
/*MT6162*/ /* Receiver Front End Mapping */
/*MT6162*/ /* Each of the 8 independent LNA/mixer/divider are either dedicated to either high (VCO divide-by-2) or low (VCO divide-by-4) band. */
/*MT6162*/ /* Furthermore even though the LNAs are identical some recommended configurations are required since performance may be limited by board/package isolation. */
/*MT6162*/ #define  LNA1_HIGH_BAND   0
/*MT6162*/ #define  LNA2_LOW_BAND    1
/*MT6162*/ #define  LNA3_HIGH_BAND   2
/*MT6162*/ #define  LNA4_LOW_BAND    3
/*MT6162*/ #define  LNA5_HIGH_BAND   4
/*MT6162*/ #define  LNA6_HIGH_BAND   5
/*MT6162*/ #define  LNA7_LOW_BAND    6
/*MT6162*/ #define  LNA8_LOW_BAND    7
/*MT6162*/ #define  NON_USED_BAND    8
/*MT6162*/          
/*MT6162*/ /* Path  Select for Transmitter sections */
/*MT6162*/ #define  TX_HIGH_BAND3    6
/*MT6162*/ #define  TX_HIGH_BAND2    5
/*MT6162*/ #define  TX_LOW_BAND1     0
/*MT6162*/ #define  TX_NULL_BAND     8
/*MT6162*/
/*MT6162*/ #define  VM_H             0
/*MT6162*/ #define  VM_M             1
/*MT6162*/ #define  VM_L             3
/*MT6162*/ #define  DC2DC_H          1
/*MT6162*/ #define  DC2DC_M          1
/*MT6162*/ #define  DC2DC_L          0
/*MT6162*/ #define  NUMBER_OF_CALI_DATA_ELEMENT 4
/*MT6162*/
/*MT6162*/ #define  TC_SR1               MICROSECOND_TO_CHIP(235)
/*MT6162*/ #define  TC_SR2               MICROSECOND_TO_CHIP(180)
/*MT6162*/ #define  TC_SR2B              MICROSECOND_TO_CHIP( 25)
/*MT6162*/ #define  TC_SR2C              MICROSECOND_TO_CHIP( 25)
/*MT6162*/ #define  TC_SR3               MICROSECOND_TO_CHIP( 20)
/*MT6162*/ #define  TC_ST1               MICROSECOND_TO_CHIP(285)//for 2G change CW43//(290)//(270)
/*MT6162*/ #define  TC_ST2               MICROSECOND_TO_CHIP(230)//for 2G change CW43//(235)//(215)
/*MT6162*/ #define  TC_ST2B              MICROSECOND_TO_CHIP(200)//(220)//(200)
/*MT6162*/ #define  TC_ST2C              MICROSECOND_TO_CHIP( 25)//( 45)//( 25)
/*MT6162*/ #define  TC_ST3               MICROSECOND_TO_CHIP(  0)
/*MT6162*/
/*MT6162*/ /*--------------------------------------------------------*/
/*MT6162*/ /* Crystal solution parameter definition                  */
/*MT6162*/ /*--------------------------------------------------------*/
/*MT6162*/ #define  CRYSTAL_CAPID_MAX    255
////////////////////////////////////////////////////////////////////////////////

#elif IS_URF_MT6162_DUAL
/*MT6162_DUAL*/
/*MT6162_DUAL*/ /* Receiver Front End Mapping */
/*MT6162_DUAL*/ /* Each of the 8 independent LNA/mixer/divider are either dedicated to either high (VCO divide-by-2) or low (VCO divide-by-4) band. */
/*MT6162_DUAL*/ /* Furthermore even though the LNAs are identical some recommended configurations are required since performance may be limited by board/package isolation. */
/*MT6162_DUAL*/ #define  LNA1_HIGH_BAND              0
/*MT6162_DUAL*/ #define  LNA2_LOW_BAND               1
/*MT6162_DUAL*/ #define  LNA3_HIGH_BAND              2
/*MT6162_DUAL*/ #define  LNA4_LOW_BAND               3
/*MT6162_DUAL*/ #define  LNA5_HIGH_BAND              4
/*MT6162_DUAL*/ #define  LNA6_HIGH_BAND              5
/*MT6162_DUAL*/ #define  LNA7_LOW_BAND               6
/*MT6162_DUAL*/ #define  LNA8_LOW_BAND               7
/*MT6162_DUAL*/ #define  NON_USED_BAND               8
/*MT6162_DUAL*/          
/*MT6162_DUAL*/ /* Path  Select for Transmitter sections */
/*MT6162_DUAL*/ #define  TX_HIGH_BAND3               6
/*MT6162_DUAL*/ #define  TX_HIGH_BAND2               5
/*MT6162_DUAL*/ #define  TX_LOW_BAND1                0
/*MT6162_DUAL*/ #define  TX_NULL_BAND                8
/*MT6162_DUAL*/
/*MT6162_DUAL*/ /*For RXD LNA path mapping*/                 
/*MT6162_DUAL*/ #define  LNA1D_HIGH_BAND             LNA1_HIGH_BAND
/*MT6162_DUAL*/ #define  LNA2D_LOW_BAND              LNA2_LOW_BAND
/*MT6162_DUAL*/ #define  LNA3D_HIGH_BAND             LNA3_HIGH_BAND
/*MT6162_DUAL*/ #define  LNAD_NON_USED_BAND          NON_USED_BAND
/*MT6162_DUAL*/                                      
/*MT6162_DUAL*/ /* PA mode Setting */ 
/*MT6162_DUAL*/ #define  NUMBER_OF_VGA_DAC           10
/*MT6162_DUAL*/ #define  VM_H                        0
/*MT6162_DUAL*/ #define  VM_M                        1
/*MT6162_DUAL*/ #define  VM_L                        3
/*MT6162_DUAL*/ #define  DC2DC_H                     1
/*MT6162_DUAL*/ #define  DC2DC_M                     1
/*MT6162_DUAL*/ #define  DC2DC_L                     0
/*MT6162_DUAL*/ #define  NUMBER_OF_CALI_DATA_ELEMENT 4
/*MT6162_DUAL*/
/*MT6162_DUAL*/ #define  TC_SR1               MICROSECOND_TO_CHIP(235)
/*MT6162_DUAL*/ #define  TC_SR2               MICROSECOND_TO_CHIP(180)
/*MT6162_DUAL*/ #define  TC_SR2B              MICROSECOND_TO_CHIP( 25)
/*MT6162_DUAL*/ #define  TC_SR2C              MICROSECOND_TO_CHIP( 25)
/*MT6162_DUAL*/ #define  TC_SR3               MICROSECOND_TO_CHIP( 20)
/*MT6162_DUAL*/ #define  TC_ST1               MICROSECOND_TO_CHIP(285)//for 2G change CW43//(290)//(270)
/*MT6162_DUAL*/ #define  TC_ST2               MICROSECOND_TO_CHIP(230)//for 2G change CW43//(235)//(215)
/*MT6162_DUAL*/ #define  TC_ST2B              MICROSECOND_TO_CHIP(200)//(220)//(200)
/*MT6162_DUAL*/ #define  TC_ST2C              MICROSECOND_TO_CHIP( 25)//( 45)//( 25)
/*MT6162_DUAL*/ #define  TC_ST3               MICROSECOND_TO_CHIP(  0)
/*MT6162_DUAL*/
/*MT6162_DUAL*/ #define  TC_ST_CAL            ((TC_ST1-TC_ST2C)+(TC_SR2-TC_SR2B)+MAX_MODE_START_OFFSET)
/*MT6162_DUAL*/
/*MT6162_DUAL*/ /* BSI Event timing for Dual cell & RXD reconfig */
/*MT6162_DUAL*/ #define  TC_DC_SR1            MICROSECOND_TO_CHIP(180)
/*MT6162_DUAL*/ #define  TC_DC_SR2            MICROSECOND_TO_CHIP( 25)
/*MT6162_DUAL*/
/*MT6162_DUAL*/ #define  TC_RXD_SR1           MICROSECOND_TO_CHIP(25)
/*MT6162_DUAL*/ #define  TC_RXD_SR3           MICROSECOND_TO_CHIP(20)
/*MT6162_DUAL*/ /*--------------------------------------------------------*/
/*MT6162_DUAL*/ /* Crystal solution parameter definition                  */
/*MT6162_DUAL*/ /*--------------------------------------------------------*/
/*MT6162_DUAL*/ #define  CRYSTAL_CAPID_MAX    255
////////////////////////////////////////////////////////////////////////////////

#elif IS_URF_ORION_FDD
/*ORION_FDD*/
/*ORION_FDD*/ #define  TC_SR1               MICROSECOND_TO_CHIP(170)//170//for "SRX locking time" + "reserved BSI event send time(about for 10 events)" =150us + 250us
/*ORION_FDD*/ #define  TC_SR2               MICROSECOND_TO_CHIP(  0)
/*ORION_FDD*/ #define  TC_SR2B              MICROSECOND_TO_CHIP(  0)
/*ORION_FDD*/ #define  TC_SR2C              MICROSECOND_TO_CHIP(  0)
/*ORION_FDD*/ #define  TC_SR3               MICROSECOND_TO_CHIP( 20)
/*ORION_FDD*/ #define  TC_ST1               MICROSECOND_TO_CHIP(170)//for "STX locking time" + "reserved BSI event send time(about for 10 events)" =150us + 20us
/*ORION_FDD*/ #define  TC_ST2               MICROSECOND_TO_CHIP(  0)
/*ORION_FDD*/ #define  TC_ST2B              MICROSECOND_TO_CHIP(  0)
/*ORION_FDD*/ #define  TC_ST2C              MICROSECOND_TO_CHIP(  0)
/*ORION_FDD*/ #define  TC_ST3               MICROSECOND_TO_CHIP(  0)
/*ORION_FDD*/
/*ORION_FDD*/ /* BSI Event timing RXCAL & TXCAL*/  
/*ORION_FDD*/ #define  TC_SR1_CAL           MICROSECOND_TO_CHIP(610) // "RX cal timing"+"BSI send time length"+"reserved timing margin" =550us + 10us +10us + 40us (for RXDFE active wait + IQ settling time)
/*ORION_FDD*/ #define  TC_SR2_CAL           MICROSECOND_TO_CHIP(10)  //"reserved BSI event send time(about for 10 events)" 
/*ORION_FDD*/ #define  TC_ST_CAL            MICROSECOND_TO_CHIP(10)  //"reserved BSI event send time(about for 10 events)"
/*ORION_FDD*/ 
/*ORION_FDD*/ /* BSI Event timing for Dual cell & RXD reconfig */
/*ORION_FDD*/ #define  TC_DC_SR1            MICROSECOND_TO_CHIP(180)
/*ORION_FDD*/ #define  TC_DC_SR2            MICROSECOND_TO_CHIP( 25)
/*ORION_FDD*/
/*ORION_FDD*/ #define  TC_RXD_SR1           MICROSECOND_TO_CHIP(25)
/*ORION_FDD*/ #define  TC_RXD_SR3           MICROSECOND_TO_CHIP(20)
/*ORION_FDD*/ 
/*ORION_FDD*/ /* Receiver Front End Mapping */
/*ORION_FDD*/ /* Each of the 8 independent LNA/mixer/divider are either dedicated to either high (VCO divide-by-2) or low (VCO divide-by-4) band. */
/*ORION_FDD*/ /* Furthermore even though the LNAs are identical some recommended configurations are required since performance may be limited by board/package isolation. */
/*ORION_FDD*/ #define  LNA1_HIGH_BAND              0
/*ORION_FDD*/ #define  LNA2_LOW_BAND               1
/*ORION_FDD*/ #define  LNA3_HIGH_BAND              2
/*ORION_FDD*/ #define  LNA4_LOW_BAND               3
/*ORION_FDD*/ #define  LNA5_HIGH_BAND              4
/*ORION_FDD*/ #define  LNA6_HIGH_BAND              5
/*ORION_FDD*/ #define  LNA7_LOW_BAND               6
/*ORION_FDD*/ #define  LNA8_LOW_BAND               7
/*ORION_FDD*/ #define  NON_USED_BAND               8
/*ORION_FDD*/ 
/*ORION_FDD*/ /* Path Select for Transmitter sections */
/*ORION_FDD*/ #define  TX_HIGH_BAND3               6
/*ORION_FDD*/ #define  TX_HIGH_BAND2               5
/*ORION_FDD*/ #define  TX_LOW_BAND1                0
/*ORION_FDD*/ #define  TX_NULL_BAND                8
/*ORION_FDD*/
/*ORION_FDD*/ /* PA mode Setting */
/*ORION_FDD*/ #define  NUMBER_OF_VGA_DAC           10
/*ORION_FDD*/ #define  VM_H                        0
/*ORION_FDD*/ #define  VM_M                        1
/*ORION_FDD*/ #define  VM_L                        3
/*ORION_FDD*/ #define  DC2DC_H                     1
/*ORION_FDD*/ #define  DC2DC_M                     1
/*ORION_FDD*/ #define  DC2DC_L                     0
/*ORION_FDD*/ #define  NUMBER_OF_CALI_DATA_ELEMENT 4
/*ORION_FDD*/
/*ORION_FDD*/ /*--------------------------------------------------------*/
/*ORION_FDD*/ /* Crystal solution parameter definition                  */
/*ORION_FDD*/ /*--------------------------------------------------------*/
/*ORION_FDD*/ #define  CRYSTAL_CAPID_MAX           255
/*ORION_FDD*/
////////////////////////////////////////////////////////////////////////////////

#elif IS_URF_ORION_HPLUS// should be reviewed with Jay
/*ORION_HPLUS*/ 
/*ORION_HPLUS*/ #define  TC_SR1               MICROSECOND_TO_CHIP(120)//for "SRX locking time" + "reserved BSI event send time(about for 10 events)" =110us + 10us
/*ORION_HPLUS*/ #define  TC_SR3               MICROSECOND_TO_CHIP( 20)
/*ORION_HPLUS*/ #define  TC_ST1               MICROSECOND_TO_CHIP(140)//for "STX locking time" + "reserved BSI event send time(about for 10 events)" =150us + 20us
/*ORION_HPLUS*/ #define  TC_ST2               MICROSECOND_TO_CHIP( 25)//for "STX locking time" + "reserved BSI event send time(about for 10 events)" =150us + 20us
/*ORION_HPLUS*/ #define  TC_ST3               MICROSECOND_TO_CHIP( 1)
/*ORION_HPLUS*/
/*ORION_HPLUS*/ /* BSI Event timing RXCAL & TXCAL*/  
/*ORION_HPLUS*/ #define  TC_SR1_CAL           MICROSECOND_TO_CHIP(610) // "RX cal timing"+"BSI send time length"+"reserved timing margin" =550us + 10us +10us + 40us (for RXDFE active wait + IQ settling time)
/*ORION_HPLUS*/ #define  TC_SR2_CAL           MICROSECOND_TO_CHIP(10)  //"reserved BSI event send time(about for 10 events)" 
/*ORION_HPLUS*/ #define  TC_ST_CAL            MICROSECOND_TO_CHIP(10)  //"reserved BSI event send time(about for 10 events)"
/*ORION_HPLUS*/ 
/*ORION_HPLUS*/ /* BSI Event timing for Dual cell & RXD reconfig */               
/*ORION_HPLUS*/ #define  TC_DC_SR1            MICROSECOND_TO_CHIP(125)              
/*ORION_HPLUS*/ #define  TC_DC_SR2            MICROSECOND_TO_CHIP(120)              
/*ORION_HPLUS*/               
/*ORION_HPLUS*/ #define  TC_RXD_SR1           MICROSECOND_TO_CHIP(25)               
/*ORION_HPLUS*/ #define  TC_RXD_SR3           MICROSECOND_TO_CHIP(20)
/*ORION_HPLUS*/
/*ORION_HPLUS*/ /*For RXD LNA path mapping*/ 
/*ORION_HPLUS*/ #define  LNA1_HIGH_BAND              1
/*ORION_HPLUS*/ #define  LNA2_LOW_BAND               2
/*ORION_HPLUS*/ #define  LNA3_HIGH_BAND              3
/*ORION_HPLUS*/ #define  LNA4_LOW_BAND               4
/*ORION_HPLUS*/ #define  LNA5_HIGH_BAND              5
/*ORION_HPLUS*/ #define  NON_USED_BAND               6
/*ORION_HPLUS*/                                      
/*ORION_HPLUS*/ /*For RXD LNA path mapping*/                 
/*ORION_HPLUS*/ #define  LNA1D_HIGH_BAND             1
/*ORION_HPLUS*/ #define  LNA2D_LOW_BAND              2
/*ORION_HPLUS*/ #define  LNA3D_HIGH_BAND             3
/*ORION_HPLUS*/ #define  LNAD_NON_USED_BAND          0
/*ORION_HPLUS*/
/*ORION_HPLUS*/ /* Path mapping for Transmitter sections */
/*ORION_HPLUS*/ #define TX_HIGH_BAND3                4
/*ORION_HPLUS*/ #define TX_HIGH_BAND2                2
/*ORION_HPLUS*/ #define TX_LOW_BAND1                 8
/*ORION_HPLUS*/ #define TX_NULL_BAND                 0
/*ORION_HPLUS*/
/*ORION_HPLUS*/ /* PA mode Setting */
/*ORION_HPLUS*/ #define  NUMBER_OF_VGA_DAC           10
/*ORION_HPLUS*/ #define  VM_H                        0
/*ORION_HPLUS*/ #define  VM_M                        1
/*ORION_HPLUS*/ #define  VM_L                        3
/*ORION_HPLUS*/ #define  DC2DC_H                     1
/*ORION_HPLUS*/ #define  DC2DC_M                     1
/*ORION_HPLUS*/ #define  DC2DC_L                     0
/*ORION_HPLUS*/ #define  NUMBER_OF_CALI_DATA_ELEMENT 4
/*ORION_HPLUS*/
/*ORION_HPLUS*/ /*--------------------------------------------------------*/
/*ORION_HPLUS*/ /* Crystal solution parameter definition                  */
/*ORION_HPLUS*/ /*--------------------------------------------------------*/
/*ORION_HPLUS*/ #define  CRYSTAL_CAPID_MAX           255
/*ORION_HPLUS*/
////////////////////////////////////////////////////////////////////////////////

#elif IS_URF_MT6167// should be reviewed with Jay
/*MT6167*/ 
/*MT6167*/ #define  TC_SR1               MICROSECOND_TO_CHIP(155)//for "SRX locking time" + "reserved BSI event send time(about for 10 events)" =140us + 10us
/*MT6167*/ #define  TC_SR2               (TC_SR1-MICROSECOND_TO_CHIP(20))
/*MT6167*/ #define  TC_SR3               MICROSECOND_TO_CHIP( 20)
/*MT6167*/ #define  TC_ST1               MICROSECOND_TO_CHIP(145)//for "STX locking time" + "reserved BSI event send time(about for 10 events)" =130us + 10us
/*MT6167*/ #define  TC_ST2               MICROSECOND_TO_CHIP( 25)//for "STX locking time" + "reserved BSI event send time(about for 10 events)" =150us + 20us
/*MT6167*/ #define  TC_ST3               MICROSECOND_TO_CHIP( 1) //for not collision with the TXUPC set gain BSI
/*MT6167*/
/*MT6167*/ /* BSI Event timing RXCAL & TXCAL*/  
/*MT6167*/ #define  TC_SR1_CAL           MICROSECOND_TO_CHIP(610) // "RX cal timing"+"BSI send time length"+"reserved timing margin" =550us + 10us +10us + 40us (for RXDFE active wait + IQ settling time)
/*MT6167*/ #define  TC_SR2_CAL           MICROSECOND_TO_CHIP(10)  //"reserved BSI event send time(about for 10 events)" 
/*MT6167*/ #define  TC_ST_CAL            MICROSECOND_TO_CHIP(0)  //"reserved BSI event send time(about for 10 events)"
/*MT6167*/ 
/*MT6167*/ /* BSI Event timing for Dual cell & RXD reconfig */               
/*MT6167*/ #define  TC_DC_SR1            MICROSECOND_TO_CHIP(155) //refer to TC_DC_SR2 setting timing             
/*MT6167*/ #define  TC_DC_SR2            MICROSECOND_TO_CHIP(150) //refer to TC_SR1 setting timing                
/*MT6167*/ #define  TC_DC_SR2B           (TC_DC_SR2-MICROSECOND_TO_CHIP(20))              
/*MT6167*/               
/*MT6167*/ #define  TC_RXD_SR1           MICROSECOND_TO_CHIP(25)  //doesn't matter, no RXD reconfiguration event @ MT6583             
/*MT6167*/ #define  TC_RXD_SR3           MICROSECOND_TO_CHIP(20)  //doesn't matter, No RXD reconfiguration event @ MT6583    
/*MT6167*/
/*MT6167*/ /*For RXD LNA path mapping*/ 
/*MT6167*/ #define  LNA1_HIGH_BAND              1
/*MT6167*/ #define  LNA2_LOW_BAND               2
/*MT6167*/ #define  LNA3_HIGH_BAND              3
/*MT6167*/ #define  LNA4_LOW_BAND               4
/*MT6167*/ #define  LNA5_HIGH_BAND              5
/*MT6167*/ #define  NON_USED_BAND               6
/*MT6167*/                                      
/*MT6167*/ /*For RXD LNA path mapping*/                 
/*MT6167*/ #define  LNA1D_HIGH_BAND             1
/*MT6167*/ #define  LNA2D_LOW_BAND              2
/*MT6167*/ #define  LNA3D_HIGH_BAND             3
/*MT6167*/ #define  LNAD_NON_USED_BAND          0
/*MT6167*/
/*MT6167*/ /* Path mapping for Transmitter sections */
/*MT6167*/ #define TX_HIGH_BAND3                4
/*MT6167*/ #define TX_HIGH_BAND2                2
/*MT6167*/ #define TX_LOW_BAND1                 8
/*MT6167*/ #define TX_NULL_BAND                 0
/*MT6167*/
/*MT6167*/ /* PA mode Setting */ /*MT6167 PORTING NOT READY*///(start) 
/*MT6167*/ #define  NUMBER_OF_VGA_DAC           10
/*MT6167*/ #define  VM_H                        0
/*MT6167*/ #define  VM_M                        1
/*MT6167*/ #define  VM_L                        3
/*MT6167*/ #define  DC2DC_H                     1
/*MT6167*/ #define  DC2DC_M                     1
/*MT6167*/ #define  DC2DC_L                     0
/*MT6167*/ #define  NUMBER_OF_CALI_DATA_ELEMENT 4
/*MT6167*/  /*MT6167 PORTING NOT READY*///(End) 
/*MT6167*/ /*--------------------------------------------------------*/
/*MT6167*/ /* Crystal solution parameter definition                  */
/*MT6167*/ /*--------------------------------------------------------*/
/*MT6167*/ #define  CRYSTAL_CAPID_MAX           255
/*MT6167*/
////////////////////////////////////////////////////////////////////////////////

#elif IS_URF_MT6166// should be reviewed with Jay
/*MT6166*/ 
/*MT6166*/ #define  TC_SR1               MICROSECOND_TO_CHIP(150+10)//for "SRX locking time" + "reserved BSI event send time(about for 10 events)" =140us + 10us
/*MT6166*/ #define  TC_SR2               MICROSECOND_TO_CHIP( 25+ 0)//15+2us=17us (TRX 3us constraint)
/*MT6166*/ #define  TC_SR3               MICROSECOND_TO_CHIP( 20)
/*MT6166*/ #define  TC_ST1               MICROSECOND_TO_CHIP(170+10)//for "STX locking time" + "reserved BSI event send time(about for 10 events)" =50+2+28+46+9(margin)=135us, 135 + 25us=160us, 160+10us=170 (TRX 3us constraint)
/*MT6166*/ #define  TC_ST2               MICROSECOND_TO_CHIP( 25)//for "STX locking time" + "reserved BSI event send time(about for 10 events)" =150us + 20us
/*MT6166*/ #define  TC_ST3               MICROSECOND_TO_CHIP( 1) //for not collision with the TXUPC set gain BSI
/*MT6166*/
/*MT6166*/ /* BSI Event timing RXCAL & TXCAL*/  
/*MT6166*/ #define  TC_SR1_CAL           MICROSECOND_TO_CHIP(610) // "RX cal timing"+"BSI send time length"+"reserved timing margin" =550us + 10us +10us + 40us (for RXDFE active wait + IQ settling time)
/*MT6166*/ #define  TC_SR2_CAL           MICROSECOND_TO_CHIP(10)  //"reserved BSI event send time(about for 10 events)" 
/*MT6166*/ #define  TC_ST_CAL            MICROSECOND_TO_CHIP(4)   //"reserved BSI event send time(about for 10 events)"
/*MT6166*/ 
/*MT6166*/ /* BSI Event timing for Dual cell & RXD reconfig */               
/*MT6166*/ #define  TC_DC_SR1            MICROSECOND_TO_CHIP(155) //refer to TC_DC_SR2 setting timing             
/*MT6166*/ #define  TC_DC_SR2            MICROSECOND_TO_CHIP(150) //refer to TC_SR1 setting timing                
/*MT6166*/ #define  TC_DC_SR2B           (TC_DC_SR2-MICROSECOND_TO_CHIP(20))              
/*MT6166*/               
/*MT6166*/ #define  TC_RXD_SR1           MICROSECOND_TO_CHIP(25)  //doesn't matter, no RXD reconfiguration event @ MT6583             
/*MT6166*/ #define  TC_RXD_SR3           MICROSECOND_TO_CHIP(20)  //doesn't matter, No RXD reconfiguration event @ MT6583    
/*MT6166*/
/*MT6166*/ /*For RX LNA path mapping*/ 
/*MT6166*/ #define  LNA1_HIGH_BAND              6		//B2: 110
/*MT6166*/ #define  LNA2_LOW_BAND               5		//B5: 101
/*MT6166*/ #define  LNA3_HIGH_BAND              4		//B1: 100
/*MT6166*/ #define  LNA4_LOW_BAND               7		//B8: 111
/*MT6166*/ #define  LNA5_HIGH_BAND              0
/*MT6166*/ #define  NON_USED_BAND               0
/*MT6166*/                                      
/*MT6166*/ /*For RXD LNA path mapping*/ //MT6166 didn't support RxD                 
/*MT6166*/ #define  LNA1D_HIGH_BAND             0
/*MT6166*/ #define  LNA2D_LOW_BAND              0
/*MT6166*/ #define  LNA3D_HIGH_BAND             0
/*MT6166*/ #define  LNAD_NON_USED_BAND          0
/*MT6166*/
/*MT6166*/ /* Path mapping for Transmitter sections */
/*MT6166*/ #define TX_HIGH_BAND3                4
/*MT6166*/ #define TX_HIGH_BAND2                2
/*MT6166*/ #define TX_LOW_BAND1                 8
/*MT6166*/ #define TX_NULL_BAND                 0
/*MT6166*/
/*MT6166*/ /* PA mode Setting */ /*MT6166 PORTING NOT READY*///(start) 
/*MT6166*/ #define  NUMBER_OF_VGA_DAC           10
/*MT6166*/ #define  VM_H                        0
/*MT6166*/ #define  VM_M                        1
/*MT6166*/ #define  VM_L                        3
/*MT6166*/ #define  DC2DC_H                     1
/*MT6166*/ #define  DC2DC_M                     1
/*MT6166*/ #define  DC2DC_L                     0
/*MT6166*/ #define  NUMBER_OF_CALI_DATA_ELEMENT 4
/*MT6166*/  /*MT6167 PORTING NOT READY*///(End) 
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ /* Crystal solution parameter definition                  */
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ #define  CRYSTAL_CAPID_MAX           255
/*MT6166*/
////////////////////////////////////////////////////////////////////////////////

#elif (IS_URF_MT6169)
/*MT6169*/ 
/*MT6169*/ #define  TC_T120_TO_T140      (90) /*including SRX setting time*/
/*MT6169*/ #define  TC_T140_TO_T141      (15) /*including RX LDO setting time*/
/*MT6169*/ #define  TC_SR1               MICROSECOND_TO_CHIP( TC_T120_TO_T140+TC_T140_TO_T141+10)//for "SRX locking time 90us + 15us(SR2)" + "reserved BSI event send time(about for 10 events)" =105us + 10us
/*MT6169*/ #define  TC_SR2               MICROSECOND_TO_CHIP( TC_T140_TO_T141+ 2)//15+2us=17us
/*MT6169*/ #define  TC_SR3               MICROSECOND_TO_CHIP( 20)
/*MT6169*/ #define  TC_ST1               MICROSECOND_TO_CHIP(170+10)//for "STX locking time" + "reserved BSI event send time(about for 10 events)" =50+2+28+46+9(margin)=135us, 135 + 25us=160us, 160+10us=170 (TRX 3us constraint)
/*MT6169*/ #define  TC_ST2               MICROSECOND_TO_CHIP( 25)//for "STX locking time" + "reserved BSI event send time(about for 10 events)" =150us + 20us
/*MT6169*/ #define  TC_ST3               MICROSECOND_TO_CHIP( 1) //for not collision with the TXUPC set gain BSI
/*MT6169*/
/*MT6169*/ /* BSI Event timing RXCAL & TXCAL, [Paul] only use it in ORION_FDD*/  
/*MT6169*/ #define  TC_SR1_CAL           MICROSECOND_TO_CHIP(610) // "RX cal timing"+"BSI send time length"+"reserved timing margin" =550us + 10us +10us + 40us (for RXDFE active wait + IQ settling time)
/*MT6169*/ #define  TC_SR2_CAL           MICROSECOND_TO_CHIP(10)  //"reserved BSI event send time(about for 10 events)" 
/*MT6169*/ #define  TC_ST_CAL            MICROSECOND_TO_CHIP(0)  //"reserved BSI event send time(about for 10 events)"
/*MT6169*/ 
/*MT6169*/ #if MT6169_TO_DO /*to do, check DC, RXD timing*/
/*MT6169*/ /* BSI Event timing for Dual cell & RXD reconfig */               
/*MT6169*/ #define  TC_DC_SR1            (TC_SR1+MICROSECOND_TO_CHIP(15)) //SC RX off timing, including off(5us for BSI delay), DC rx window on time.             
/*MT6169*/ #define  TC_DC_SR2            (TC_SR1) //DC RX SRX on timing(SR1).
/*MT6169*/ #define  TC_DC_SR2B           (TC_SR2) //DC RX on timing(SR2).             
/*MT6169*/               
/*MT6169*/ #define  TC_RXD_SR1           MICROSECOND_TO_CHIP(25)  //doesn't matter, no RXD reconfiguration event @ MT6583             
/*MT6169*/ #define  TC_RXD_SR3           MICROSECOND_TO_CHIP(20)  //doesn't matter, No RXD reconfiguration event @ MT6583    
/*MT6169*/
           #endif
/*MT6169*/ /*For RX LNA path mapping*/ 
/*MT6169*/ #define LNA_HB_1 (0)
/*MT6169*/ #define LNA_HB_2 (1)
/*MT6169*/ #define LNA_HB_3 (2)
/*MT6169*/ #define LNA_MB_1 (3)
/*MT6169*/ #define LNA_MB_2 (4)
/*MT6169*/ #define LNA_LB_1 (5)
/*MT6169*/ #define LNA_LB_2 (6)
/*MT6169*/ #define LNA_LB_3 (7)
/*MT6169*/ /*Start from MT6169, use 0xFF(max) to make all projects in the future aligned with the same value, for customer's comprehension*/
/*MT6169*/ #define NON_USED_BAND (0xFF)
/*MT6169*/ #define NON_USED_BAND_ORIGIN (0x8) // Coexistence with NON_USED_BAND since DVT we use 0x8. CAN removed for future projects
/*MT6169*/                                      
/*MT6169*/ /*For RXD LNA path mapping*/                 
/*MT6169*/ #define LNA_RXD_HB_1 (0)
/*MT6169*/ #define LNA_RXD_HB_2 (1)
/*MT6169*/ #define LNA_RXD_HB_3 (2)
/*MT6169*/ #define LNA_RXD_MB_1 (3)
/*MT6169*/ #define LNA_RXD_MB_2 (4)
/*MT6169*/ #define LNA_RXD_LB_1 (5)
/*MT6169*/ #define LNA_RXD_LB_2 (6)
/*MT6169*/ #define LNA_RXD_LB_3 (7)
/*MT6169*/ #define LNA_RXD_NON_USED_BAND (NON_USED_BAND)
/*MT6169*/
/*MT6169*/ /*CW68: IOTX Table 11-5*/
/*MT6169*/ #define TX_HB_1 (0)
/*MT6169*/ #define TX_HB_2 (1)
/*MT6169*/ #define TX_MB_1 (2)
/*MT6169*/ #define TX_MB_2 (3)
/*MT6169*/ #define TX_LB_1 (4)
/*MT6169*/ #define TX_LB_2 (5)
/*MT6169*/ #define TX_LB_3 (6)
/*MT6169*/ #define TX_LB_4 (7)
/*MT6169*/ #define TX_NON_USED_BAND (8)
/*MT6169*/ 
/*MT6169*/ /* Path mapping for Transmitter sections */
/*MT6169*/ #define TX_HIGH_BAND2                TX_HB_2
/*MT6169*/ #define TX_HIGH_BAND3                TX_MB_1
/*MT6169*/ #define TX_LOW_BAND1                 TX_LB_1
/*MT6169*/ #define TX_NULL_BAND                 TX_NON_USED_BAND
/*MT6169*/
/*MT6169*/ /* PA mode Setting */ /*MT6166 PORTING NOT READY*///(start) 
/*MT6169*/ #define  NUMBER_OF_VGA_DAC           10
/*MT6169*/ #define  VM_H                        0
/*MT6169*/ #define  VM_M                        1
/*MT6169*/ #define  VM_L                        3
/*MT6169*/ #define  DC2DC_H                     1
/*MT6169*/ #define  DC2DC_M                     1
/*MT6169*/ #define  DC2DC_L                     0
/*MT6169*/ #define  NUMBER_OF_CALI_DATA_ELEMENT 4
/*MT6169*/  /*MT6167 PORTING NOT READY*///(End) 
/*MT6169*/ /*--------------------------------------------------------*/
/*MT6169*/ /* Crystal solution parameter definition                  */
/*MT6169*/ /*--------------------------------------------------------*/
/*MT6169*/ #define  CRYSTAL_CAPID_MAX           255
/*MT6169*/
////////////////////////////////////////////////////////////////////////////////

#else
   #error "Should define at least a kind of RF being used."
#endif

/*===============================================================================================*/


/*******************************************************************************
** New BPI data type 
*******************************************************************************/

#if IS_URF_MT6167 || IS_URF_MT6166 || IS_URF_MT6169
typedef kal_uint32     BPI_data_type; 
#else
typedef kal_uint16     BPI_data_type; 
#endif




/*******************************************************************************
** META Factory Calibration and 3G RF tool usage
*******************************************************************************/
#if !defined(IS_R6_DCXO_SUPPORT)
#define IS_R6_DCXO_SUPPORT          0
#endif


/*******************************************************************************
** Constants
*******************************************************************************/
#define  CAL_TEMP_SECTION            8
#define  CAL_UARFCN_SECTION         15
#define  CAL_PWR_DETECTOR_SECTION   32

#if !defined(NUMBER_OF_VGA_DAC)
#define  NUMBER_OF_VGA_DAC          96
#endif

#if IS_3G_TX_POWER_OFFSET_SUPPORT
#define  TPO_3G_TABLE_NUM             2
#define  TPO_3G_BIT_NUM_FOR_TABLE_0   2
#define  TPO_3G_BIT_NUM_FOR_TABLE_1   3
#endif /* IS_3G_TX_POWER_OFFSET_SUPPORT */

/*******************************************************************************
** Typedefs
*******************************************************************************/
typedef enum
{
   UMTSBandNone = 0,
   UMTSBand1    = 1,
   UMTSBand2    = 2,
   UMTSBand3    = 3,
   UMTSBand4    = 4,
   UMTSBand5    = 5,
   UMTSBand6    = 6,
   UMTSBand7    = 7,
   UMTSBand8    = 8,
   UMTSBand9    = 9,
   UMTSBand10   = 10,
   UMTSBand11   = 11,
   UMTSBand12   = 12,
   UMTSBand13   = 13,
   UMTSBand14   = 14,
   UMTSBand15   = 15,
   UMTSBand16   = 16,
   UMTSBand17   = 17,
   UMTSBand18   = 18,
   UMTSBand19   = 19,
   UMTSBand20   = 20,
   UMTSBand21   = 21,
   UMTSBand22   = 22,
   UMTSBandcount
}  UMTSBand;

typedef struct {
   kal_uint32      capability;
   kal_uint32      band_support;
   kal_uint32      rxd_band_support;
   kal_uint32      padrift_band_support;
} UMTS_MsCapabilityEx;

typedef  struct
{
   kal_uint16 max_uarfcn;
   kal_int8   path_loss_H;
   kal_int8   path_loss_M;
   kal_int8   path_loss_L;
}  U_sAGCGAINOFFSET;

typedef  struct
{
   U_sAGCGAINOFFSET  gain_of_uarfcn[CAL_UARFCN_SECTION];
}  U_sTEMPAGCOFFSET;

typedef  struct
{
   kal_uint16 level_0;
   kal_uint16 level_1;
} U_sDC2DC;

typedef  struct
{
   kal_uint16 start;
   kal_uint16 end;
} U_sHYSTERESISDATA;

typedef  struct
{
   kal_uint16 max_uarfcn;
   kal_int16  pwr_offset_dB; /* unit: 1/32 dB, range: -8 ~ +7 dB */ 
   kal_int16  pwr_offset_txdac;
}  U_sARFCN_SECTION;

typedef  struct
{
   kal_uint8  pwr_dt_thr;
   kal_uint8  pwr_dt_section;
   kal_uint16 pwr_dt_dac[ CAL_PWR_DETECTOR_SECTION ];
   kal_int16  pwr_dt_value[ CAL_PWR_DETECTOR_SECTION ]; //bit0~4 is used for fractions
   U_sARFCN_SECTION  pwr_dt_comp_by_subband[ CAL_UARFCN_SECTION ];
   kal_int16  pwr_dt_comp_by_temperature[8][2];  //[0]:slope, [1]:offset
}  U_sPWTDTDATA;

typedef  struct
{
   kal_uint16 dc2dc_level;
   kal_uint16 vbias_dac;
   kal_uint8  vm1;
   kal_uint8  vm2;
}  U_sPADATA;

typedef  struct
{
   U_sPADATA   pa_data; 
   kal_uint16  vga_dac[NUMBER_OF_VGA_DAC];
   U_sARFCN_SECTION  vga_comp_by_subband[ CAL_UARFCN_SECTION ];
   kal_int16  vga_comp_by_temperature[8][2];  //[0]:slope, [1]:offset
} U_sTXPOWERDATA;

typedef struct 
{
   kal_int16  vga_comp_by_temperature[8][2];  //[0]:slope, [1]:offset
} U_sRACHCOMP;


typedef struct 
{
   U_sRACHCOMP  power_dac[3];
} U_sPARACHTMCOMPDATA;

#if IS_3G_TX_POWER_OFFSET_SUPPORT
typedef  struct
{
   kal_uint16 max_uarfcn;
   kal_int16  pwr_offset_dB[3];    /* index 0/1/2 : R99/HSDPA/HSUPA ; unit: 1/32 dB, range: -8 ~ +7 dB */ 
}  U_sSUBBAND_SECTION;

typedef struct 
{
   U_sSUBBAND_SECTION  subband_power_offset[CAL_UARFCN_SECTION];
} U_sTXPOWEROFFSETTABLE;

typedef struct 
{
   U_sTXPOWEROFFSETTABLE  table[TPO_3G_TABLE_NUM];
} U_sTXPOWEROFFSETDATA;

typedef struct
{
   kal_bool    TPO_enable;          /* Enable Tx power offset */
   kal_bool    TPO_meta_enable;     /* Enable Tx power offset table  in Meta mode */
   kal_uint32  TPO_table_on_mask;   /* Turn on offset table. ex:bit0=1 --> apply offset in table 0  */
   kal_uint32  TPO_bit_number_for_3G_table[TPO_3G_TABLE_NUM];
}U_sUl1dMetaTxPowerOffsetSetting;
#endif /* IS_3G_TX_POWER_OFFSET_SUPPORT */

#if IS_3G_FDD_RX_PATH_SELECTION_SUPPORT
typedef enum
{
   ANT_RX_MAIN_ONLY   = 0,
   ANT_RX_RXD_ONLY    = 1,
   ANT_RX_BOTH        = 2,
   ANT_RESUME_DEFAULT = 3
}ANT_SEL_TYPE;

typedef struct
{
   kal_bool       rx_path_selection_enable;
   ANT_SEL_TYPE   rx_path_type;
} U_sRxPathSelection;
#endif

typedef struct 
{
   kal_uint16 initDac;
   kal_int32 slope;
} U_sAFCDACDATA;

typedef struct 
{
   kal_int32 cap_id; 
} U_sAFCCAPDATA;


typedef  struct
{
   U_sDC2DC pa_dc2dc;
   U_sTXPOWERDATA  power_dac[3];  //0:PA high mode, 1:PA mid mode, 2:PA low mode (use 0&1 if only 2 mode)
   U_sHYSTERESISDATA tx_hysteresis[2];
   U_sPWTDTDATA    pwr_dt_data;
} U_sRAMPDATA;

typedef  struct
{
   kal_uint8  pa_mode;   //  2 bits
   kal_int8   prf;       //  8 bits
   kal_uint8  dc2dc_lvl; //  5 bits // MT6589, MT6582: 6 bits
   kal_uint8  vm1;       //  1 bit
   kal_uint8  vm2;       //  1 bit
   kal_uint16 vbias_dac; // 10 bits
   kal_uint16 pa_gain;   //  9 bits
} U_sPMULEVHANDLE;

typedef  struct
{
   /* octlev_num_section accounts for recording the number of sections that defined by user
    * To keep the design simple, we only allow user to use consecutive regions
    *
    * The two control parameters pa_phase_compensation[] and pmu_level_handle[] belong to BB TX HW
    * funtionality and all relates to PA, though PA phase compensation only has three modes
    * PD coupler loss by PA modes stored in power_dac[]->vga_dac[9]
    */
   kal_uint8         octlev_num_section;
   kal_uint8         reserved_byte; // Use ARM compiler padding byte to store power backoff value configured by META user in Factory Mode calibration
   kal_uint32        pa_phase_compensation[3]; // 0: PA high mode, 1: PA mid mode
   U_sPMULEVHANDLE   pmu_level_handle[8];
} U_sPAOCTLVLSETTING;

// Start for ADAPT IOT AMR workaround
typedef struct
{
   kal_bool ADAPT_Customized;
   kal_bool reserved1;
   kal_bool reserved2;
   kal_bool reserved3;
} U_sUl1IotCustomSupportStruct;
// End for ADAPT IOT AMR workaround

#if IS_HSPA_HWTPC
   #ifdef __HSDPA_SUPPORT__
typedef struct 
{
   kal_uint8  pseudo_hscch[5];
   kal_uint8  pseudo_hdsch[5];
   kal_uint16 beta_hs_p[15];
   kal_uint16 beta_hs_q[15];
} META_HWTPC_HSDPA_FRAME_INFO;
   #endif

   #ifdef __HSUPA_SUPPORT__
typedef struct 
{
   kal_uint8  edch_enable[5];
   kal_uint8  is_new_tx[5];
   kal_uint8  etfci[5];
   kal_uint8  beta_ed_num[5];
   kal_uint16 beta_ed0_sf[5];
   kal_uint16 beta_ed1_sf[5];
   kal_uint16 beta_ed2_sf[5];
   kal_uint16 beta_ed3_sf[5];
   kal_uint16 beta_ec[5];
   kal_uint16 beta_ed_x_beta_c_0[5];
   kal_uint16 beta_ed_x_beta_c_1[5];
   kal_uint16 beta_ed_x_beta_c_2[5];
   kal_uint16 beta_ed_x_beta_c_3[5];
   kal_uint8  delta_harq[5];
} META_HWTPC_HSUPA_FRAME_INFO;
   #endif
#endif // #if IS_HSPA_HWTPC

typedef struct 
{
   /*input*/
   kal_uint8 tpc_step;
   kal_uint8 itp;
   kal_uint8 rpp;
   kal_uint8 fmt_idx;
   kal_uint8 dl_frame_type;
   kal_uint16 slot_mask;
   kal_int8   tpc_cmd[15];
   kal_uint8  beta_c;
   kal_uint8  beta_d;
#if IS_HSPA_HWTPC
   // Above is R99 original used
   kal_uint32 normcon;
   kal_int16  net_maxpow;
   kal_int16  net_minpow;
   
   #ifdef __HSDPA_SUPPORT__
   META_HWTPC_HSDPA_FRAME_INFO hsdpa;
   #endif
   #ifdef __HSUPA_SUPPORT__
   META_HWTPC_HSUPA_FRAME_INFO hsupa;
   #endif
#endif // #if IS_HSPA_HWTPC
}  META_HWTPC_FRAME_INFO;

#if defined(__UMTS_R8__)
typedef  struct
{ 
   kal_int8          temper_offset[CAL_TEMP_SECTION];
   U_sAGCGAINOFFSET  gain_of_uarfcn[CAL_UARFCN_SECTION];   
}  U_sAGCOFFSETRXD;

typedef  struct
{
   kal_int16 pa_drift_comp_w_table[6][2];
   kal_int16 pa_drift_comp_h_table[6][4];
} U_sPADRIFTSETTING;
#endif

typedef enum
{
   MPRSetting0 = 0,
   MPRSetting1 = 1,
   MPRSetting2 = 2,
   MPRSetting3 = 3,
   MPRSetting4 = 4,
   MPRSettingCount
}  MPR_Setting;

#if (IS_3G_MIPI_SUPPORT)
typedef enum
{
   MIPI_DEFAULT = 0,
   MIPI_DISABLE = 1,
   MIPI_ENABLE  = 2
   #if (IS_3G_ET_SUPPORT)
  ,MIPI_ET_ENABLE  = 3
   #endif
}MIPI_Setting;
#endif
/*******************************************************************************
** RF Customization usage
*******************************************************************************/

/*******************************************************************************
** Macros and constants
*******************************************************************************/
#if defined(__UMTS_R8__)
   //For R8 project use internal definition.
#else
#define CAL_RX_ACT_DLY                5 //CAL_RX_ACT_DLY*64 samples = CAL_RX_ACT_DLY*38 chips
#define CAL_RX_DC_LEN                 4 //0~7, 1<<(4+CAL_RX_DC_LEN) samples = (1<<(4+CAL_RX_DC_LEN))*0.6 chips
#define CAL_RX_DC_STL_TIME            30 //CAL_RX_DC_STL_TIME asmples = CAL_RX_DC_STL_TIME/2 chips
#define CAL_RX_IQ_LEN                 7 //0~8, 1<<(4+CAL_RX_IQ_LEN) samples = 1<<(3+CAL_RX_IQ_LEN) chips

//Sample to Chip = Samples * (3.84MHz/6.5MHz=0.59077)
#define CAL_RX_IDLE_IN_CHIP           1      //chips
#define CAL_RX_ACT_DLY_IN_CHIP        190    //CAL_RX_ACT_DLY*(64)*0.59077 chips
#define CAL_RX_DC_LEN_IN_CHIP         152    //(1<<(4+CAL_RX_DC_LEN))*0.59077 chips
#define CAL_RX_DC_STL_TIME_IN_CHIP    18     //CAL_RX_DC_STL_TIME*0.59077 chips
#define CAL_RX_IQ_LEN_IN_CHIP         1210   //(1<<(4+CAL_RX_IQ_LEN))*0.59077 chips

#define RXCAL_TTG_DIS_GUARD_TIME      30 //Chips ~=7.8us
#define RXCAL_MODE_CHANGE_GUARD_TIME  20 //Chips ~=5.2us
#define RXCAL_TOTAL_TIME              (CAL_RX_IDLE_IN_CHIP + CAL_RX_ACT_DLY_IN_CHIP + CAL_RX_DC_LEN_IN_CHIP + CAL_RX_DC_STL_TIME_IN_CHIP + CAL_RX_IQ_LEN_IN_CHIP + RXCAL_TTG_DIS_GUARD_TIME)
#define RXCAL_EVENT_SHIFT_TIME0       (RXCAL_TOTAL_TIME+RXCAL_MODE_CHANGE_GUARD_TIME+RXCAL_TOTAL_TIME+TC_SR2B)
#define RXCAL_EVENT_SHIFT_TIME1       (RXCAL_TOTAL_TIME+TC_SR2B)

#define RXCAL_EVENT_SHIFT_TIME       (RXCAL_TOTAL_TIME+RXCAL_MODE_CHANGE_GUARD_TIME+RXCAL_TOTAL_TIME+TC_SR2B)
#endif //__UMTS_R8__

#define  U_PWRRES                   4 // resolution 0.25dB
#define  U_GAINLOSS( n )           ((kal_int8)((n)*U_PWRRES))
#define  UMTS_TABLE_END             0 // Use this value ater the end of UARFCN weight
#define  MICROSECOND_TO_CHIP(x)    ((kal_int32)((x)*3.84))

#if !defined(UMTS_RF_TYPE)
#define  UMTS_RF_TYPE  2
#endif

#if defined(__UMTS_R8__)
#define UMTS_RF_MAX_PA_SECTIONS                (3)
#define UMTS_RF_RX_START_TIMING_ARRAY_LENGTH   (9)
#define UMTS_RF_RX_END_TIMING_ARRAY_LENGTH     (5)
#define UMTS_RF_TX_START_TIMING_ARRAY_LENGTH   (7)
#define UMTS_RF_TX_END_TIMING_ARRAY_LENGTH     (3)
#define UMTS_RF_BPI_DATA_TABLE_NUM_OF_BANDS   (11)
#define UMTS_RF_BPI_DATA_TABLE_NUM_OF_WINDOWS  (2)
#define UMTS_RF_BPI_DATA_TABLE_NUM_OF_EVENTS   (5)
#define UMTS_RF_BPI_DATA2_TABLE_NUM_OF_EVENTS  (5)
#else
#define UMTS_RF_MAX_PA_SECTIONS                (3)
#define UMTS_RF_RX_START_TIMING_ARRAY_LENGTH   (6)
#define UMTS_RF_RX_END_TIMING_ARRAY_LENGTH     (3)
#define UMTS_RF_TX_START_TIMING_ARRAY_LENGTH   (8)
#define UMTS_RF_TX_END_TIMING_ARRAY_LENGTH     (5)
#define UMTS_RF_BPI_DATA_TABLE_NUM_OF_BANDS   (11)
#define UMTS_RF_BPI_DATA_TABLE_NUM_OF_WINDOWS  (2)
#define UMTS_RF_BPI_DATA_TABLE_NUM_OF_EVENTS   (5)
#endif

/*******************************************************************************
** Typedefs
*******************************************************************************/
typedef struct
{
   kal_uint16 maxOffset;
   kal_uint16 vmOffset;
   kal_uint16 vbiasOffset;
   kal_uint16 dc2dcOffset;
   kal_uint16 vgaOffset;
}U_sUl1dRfPaControlTiming;

typedef struct
{
   /* RX window start timing */
   kal_int16 xTC_PR1;
   kal_int16 xTC_PR2;
   kal_int16 xTC_PR2B;

   /* RX window end timing */
   kal_int16 xTC_PR3;
   kal_int16 xTC_PR3A;

   /* TX window start timing */
   kal_int16 xTC_PT1;
   kal_int16 xTC_PT2;
   kal_int16 xTC_PT2B;

   /* TX window end timing */
   kal_int16 xTC_PT3;
   kal_int16 xTC_PT3A;
}U_sUl1dRfBsiBpiTiming;

typedef struct
{
   /* Band 1 BPI data */
   BPI_data_type xPDATA_BAND1_PR1;
   BPI_data_type xPDATA_BAND1_PR2;
   BPI_data_type xPDATA_BAND1_PR2B;
   BPI_data_type xPDATA_BAND1_PR3;
   BPI_data_type xPDATA_BAND1_PR3A;
   BPI_data_type xPDATA_BAND1_PT1;
   BPI_data_type xPDATA_BAND1_PT2;
   BPI_data_type xPDATA_BAND1_PT2B;
   BPI_data_type xPDATA_BAND1_PT3;
   BPI_data_type xPDATA_BAND1_PT3A;
#if defined (__UL1_HS_PLUS_PLATFORM__)
   BPI_data_type xPDATA_BAND1_RXD_PR1;
   BPI_data_type xPDATA_BAND1_RXD_PR2;
   BPI_data_type xPDATA_BAND1_RXD_PR2B;
   BPI_data_type xPDATA_BAND1_RXD_PR3;
   BPI_data_type xPDATA_BAND1_RXD_PR3A;
#endif
   
   /* Band 2 BPI data */
   BPI_data_type xPDATA_BAND2_PR1;
   BPI_data_type xPDATA_BAND2_PR2;
   BPI_data_type xPDATA_BAND2_PR2B;
   BPI_data_type xPDATA_BAND2_PR3;
   BPI_data_type xPDATA_BAND2_PR3A;
   BPI_data_type xPDATA_BAND2_PT1;
   BPI_data_type xPDATA_BAND2_PT2;
   BPI_data_type xPDATA_BAND2_PT2B;
   BPI_data_type xPDATA_BAND2_PT3;
   BPI_data_type xPDATA_BAND2_PT3A;
#if defined (__UL1_HS_PLUS_PLATFORM__)
   BPI_data_type xPDATA_BAND2_RXD_PR1;
   BPI_data_type xPDATA_BAND2_RXD_PR2;
   BPI_data_type xPDATA_BAND2_RXD_PR2B;
   BPI_data_type xPDATA_BAND2_RXD_PR3;
   BPI_data_type xPDATA_BAND2_RXD_PR3A;
#endif
   
   /* Band 3 BPI data */
   BPI_data_type xPDATA_BAND3_PR1;
   BPI_data_type xPDATA_BAND3_PR2;
   BPI_data_type xPDATA_BAND3_PR2B;
   BPI_data_type xPDATA_BAND3_PR3;
   BPI_data_type xPDATA_BAND3_PR3A;
   BPI_data_type xPDATA_BAND3_PT1;
   BPI_data_type xPDATA_BAND3_PT2;
   BPI_data_type xPDATA_BAND3_PT2B;
   BPI_data_type xPDATA_BAND3_PT3;
   BPI_data_type xPDATA_BAND3_PT3A;
#if defined (__UL1_HS_PLUS_PLATFORM__)
   BPI_data_type xPDATA_BAND3_RXD_PR1;
   BPI_data_type xPDATA_BAND3_RXD_PR2;
   BPI_data_type xPDATA_BAND3_RXD_PR2B;
   BPI_data_type xPDATA_BAND3_RXD_PR3;
   BPI_data_type xPDATA_BAND3_RXD_PR3A;
#endif
   
   /* Band 4 BPI data */
   BPI_data_type xPDATA_BAND4_PR1;
   BPI_data_type xPDATA_BAND4_PR2;
   BPI_data_type xPDATA_BAND4_PR2B;
   BPI_data_type xPDATA_BAND4_PR3;
   BPI_data_type xPDATA_BAND4_PR3A;
   BPI_data_type xPDATA_BAND4_PT1;
   BPI_data_type xPDATA_BAND4_PT2;
   BPI_data_type xPDATA_BAND4_PT2B;
   BPI_data_type xPDATA_BAND4_PT3;
   BPI_data_type xPDATA_BAND4_PT3A;
#if defined (__UL1_HS_PLUS_PLATFORM__)
   BPI_data_type xPDATA_BAND4_RXD_PR1;
   BPI_data_type xPDATA_BAND4_RXD_PR2;
   BPI_data_type xPDATA_BAND4_RXD_PR2B;
   BPI_data_type xPDATA_BAND4_RXD_PR3;
   BPI_data_type xPDATA_BAND4_RXD_PR3A;
#endif
   
   /* Band 5 BPI data */
   BPI_data_type xPDATA_BAND5_PR1;
   BPI_data_type xPDATA_BAND5_PR2;
   BPI_data_type xPDATA_BAND5_PR2B;
   BPI_data_type xPDATA_BAND5_PR3;
   BPI_data_type xPDATA_BAND5_PR3A;
   BPI_data_type xPDATA_BAND5_PT1;
   BPI_data_type xPDATA_BAND5_PT2;
   BPI_data_type xPDATA_BAND5_PT2B;
   BPI_data_type xPDATA_BAND5_PT3;
   BPI_data_type xPDATA_BAND5_PT3A;
#if defined (__UL1_HS_PLUS_PLATFORM__)
   BPI_data_type xPDATA_BAND5_RXD_PR1;
   BPI_data_type xPDATA_BAND5_RXD_PR2;
   BPI_data_type xPDATA_BAND5_RXD_PR2B;
   BPI_data_type xPDATA_BAND5_RXD_PR3;
   BPI_data_type xPDATA_BAND5_RXD_PR3A;
#endif
   
   /* Band 6 BPI data */
   BPI_data_type xPDATA_BAND6_PR1;
   BPI_data_type xPDATA_BAND6_PR2;
   BPI_data_type xPDATA_BAND6_PR2B;
   BPI_data_type xPDATA_BAND6_PR3;
   BPI_data_type xPDATA_BAND6_PR3A;
   BPI_data_type xPDATA_BAND6_PT1;
   BPI_data_type xPDATA_BAND6_PT2;
   BPI_data_type xPDATA_BAND6_PT2B;
   BPI_data_type xPDATA_BAND6_PT3;
   BPI_data_type xPDATA_BAND6_PT3A;
#if defined (__UL1_HS_PLUS_PLATFORM__)
   BPI_data_type xPDATA_BAND6_RXD_PR1;
   BPI_data_type xPDATA_BAND6_RXD_PR2;
   BPI_data_type xPDATA_BAND6_RXD_PR2B;
   BPI_data_type xPDATA_BAND6_RXD_PR3;
   BPI_data_type xPDATA_BAND6_RXD_PR3A;
#endif
   
   /* Band 7 BPI data */
   BPI_data_type xPDATA_BAND7_PR1;
   BPI_data_type xPDATA_BAND7_PR2;
   BPI_data_type xPDATA_BAND7_PR2B;
   BPI_data_type xPDATA_BAND7_PR3;
   BPI_data_type xPDATA_BAND7_PR3A;
   BPI_data_type xPDATA_BAND7_PT1;
   BPI_data_type xPDATA_BAND7_PT2;
   BPI_data_type xPDATA_BAND7_PT2B;
   BPI_data_type xPDATA_BAND7_PT3;
   BPI_data_type xPDATA_BAND7_PT3A;
#if defined (__UL1_HS_PLUS_PLATFORM__)
   BPI_data_type xPDATA_BAND7_RXD_PR1;
   BPI_data_type xPDATA_BAND7_RXD_PR2;
   BPI_data_type xPDATA_BAND7_RXD_PR2B;
   BPI_data_type xPDATA_BAND7_RXD_PR3;
   BPI_data_type xPDATA_BAND7_RXD_PR3A;
#endif
   
   /* Band 8 BPI data */
   BPI_data_type xPDATA_BAND8_PR1;
   BPI_data_type xPDATA_BAND8_PR2;
   BPI_data_type xPDATA_BAND8_PR2B;
   BPI_data_type xPDATA_BAND8_PR3;
   BPI_data_type xPDATA_BAND8_PR3A;
   BPI_data_type xPDATA_BAND8_PT1;
   BPI_data_type xPDATA_BAND8_PT2;
   BPI_data_type xPDATA_BAND8_PT2B;
   BPI_data_type xPDATA_BAND8_PT3;
   BPI_data_type xPDATA_BAND8_PT3A;
#if defined (__UL1_HS_PLUS_PLATFORM__)
   BPI_data_type xPDATA_BAND8_RXD_PR1;
   BPI_data_type xPDATA_BAND8_RXD_PR2;
   BPI_data_type xPDATA_BAND8_RXD_PR2B;
   BPI_data_type xPDATA_BAND8_RXD_PR3;
   BPI_data_type xPDATA_BAND8_RXD_PR3A;
#endif
   
   /* Band 9 BPI data */
   BPI_data_type xPDATA_BAND9_PR1;
   BPI_data_type xPDATA_BAND9_PR2;
   BPI_data_type xPDATA_BAND9_PR2B;
   BPI_data_type xPDATA_BAND9_PR3;
   BPI_data_type xPDATA_BAND9_PR3A;
   BPI_data_type xPDATA_BAND9_PT1;
   BPI_data_type xPDATA_BAND9_PT2;
   BPI_data_type xPDATA_BAND9_PT2B;
   BPI_data_type xPDATA_BAND9_PT3;
   BPI_data_type xPDATA_BAND9_PT3A;
#if defined (__UL1_HS_PLUS_PLATFORM__)
   BPI_data_type xPDATA_BAND9_RXD_PR1;
   BPI_data_type xPDATA_BAND9_RXD_PR2;
   BPI_data_type xPDATA_BAND9_RXD_PR2B;
   BPI_data_type xPDATA_BAND9_RXD_PR3;
   BPI_data_type xPDATA_BAND9_RXD_PR3A;
#endif
   
   /* Band 10 BPI data */
   BPI_data_type xPDATA_BAND10_PR1;
   BPI_data_type xPDATA_BAND10_PR2;
   BPI_data_type xPDATA_BAND10_PR2B;
   BPI_data_type xPDATA_BAND10_PR3;
   BPI_data_type xPDATA_BAND10_PR3A;
   BPI_data_type xPDATA_BAND10_PT1;
   BPI_data_type xPDATA_BAND10_PT2;
   BPI_data_type xPDATA_BAND10_PT2B;
   BPI_data_type xPDATA_BAND10_PT3;
   BPI_data_type xPDATA_BAND10_PT3A;
#if defined (__UL1_HS_PLUS_PLATFORM__)
   BPI_data_type xPDATA_BAND10_RXD_PR1;
   BPI_data_type xPDATA_BAND10_RXD_PR2;
   BPI_data_type xPDATA_BAND10_RXD_PR2B;
   BPI_data_type xPDATA_BAND10_RXD_PR3;
   BPI_data_type xPDATA_BAND10_RXD_PR3A;
   
   /* Band 11 BPI data */
   BPI_data_type xPDATA_BAND11_PR1;
   BPI_data_type xPDATA_BAND11_PR2;
   BPI_data_type xPDATA_BAND11_PR2B;
   BPI_data_type xPDATA_BAND11_PR3;
   BPI_data_type xPDATA_BAND11_PR3A;
   BPI_data_type xPDATA_BAND11_PT1;
   BPI_data_type xPDATA_BAND11_PT2;
   BPI_data_type xPDATA_BAND11_PT2B;
   BPI_data_type xPDATA_BAND11_PT3;
   BPI_data_type xPDATA_BAND11_PT3A;
   BPI_data_type xPDATA_BAND11_RXD_PR1;
   BPI_data_type xPDATA_BAND11_RXD_PR2;
   BPI_data_type xPDATA_BAND11_RXD_PR2B;
   BPI_data_type xPDATA_BAND11_RXD_PR3;
   BPI_data_type xPDATA_BAND11_RXD_PR3A;
   
   /* Band 19 BPI data */
   BPI_data_type xPDATA_BAND19_PR1;
   BPI_data_type xPDATA_BAND19_PR2;
   BPI_data_type xPDATA_BAND19_PR2B;
   BPI_data_type xPDATA_BAND19_PR3;
   BPI_data_type xPDATA_BAND19_PR3A;
   BPI_data_type xPDATA_BAND19_PT1;
   BPI_data_type xPDATA_BAND19_PT2;
   BPI_data_type xPDATA_BAND19_PT2B;
   BPI_data_type xPDATA_BAND19_PT3;
   BPI_data_type xPDATA_BAND19_PT3A;
   BPI_data_type xPDATA_BAND19_RXD_PR1;
   BPI_data_type xPDATA_BAND19_RXD_PR2;
   BPI_data_type xPDATA_BAND19_RXD_PR2B;
   BPI_data_type xPDATA_BAND19_RXD_PR3;
   BPI_data_type xPDATA_BAND19_RXD_PR3A;
#endif
}U_sUl1dRfBpiData;

#if IS_3G_TAS_SUPPORT
typedef struct
{
   /* Band 1 TAS BPI data */
   BPI_data_type xPDATA_BAND1_TAS1;
   BPI_data_type xPDATA_BAND1_TAS2;
   BPI_data_type xPDATA_BAND1_TAS3;

   /* Band 2 TAS BPI data */
   BPI_data_type xPDATA_BAND2_TAS1;
   BPI_data_type xPDATA_BAND2_TAS2;
   BPI_data_type xPDATA_BAND2_TAS3;

   /* Band 3 TAS BPI data */
   BPI_data_type xPDATA_BAND3_TAS1;
   BPI_data_type xPDATA_BAND3_TAS2;
   BPI_data_type xPDATA_BAND3_TAS3;

   /* Band 4 TAS BPI data */
   BPI_data_type xPDATA_BAND4_TAS1;
   BPI_data_type xPDATA_BAND4_TAS2;
   BPI_data_type xPDATA_BAND4_TAS3;

   /* Band 5 TAS BPI data */
   BPI_data_type xPDATA_BAND5_TAS1;
   BPI_data_type xPDATA_BAND5_TAS2;
   BPI_data_type xPDATA_BAND5_TAS3;

   /* Band 6 TAS BPI data */
   BPI_data_type xPDATA_BAND6_TAS1;
   BPI_data_type xPDATA_BAND6_TAS2;
   BPI_data_type xPDATA_BAND6_TAS3;

   /* Band 7 TAS BPI data */
   BPI_data_type xPDATA_BAND7_TAS1;
   BPI_data_type xPDATA_BAND7_TAS2;
   BPI_data_type xPDATA_BAND7_TAS3;

   /* Band 8 TAS BPI data */
   BPI_data_type xPDATA_BAND8_TAS1;
   BPI_data_type xPDATA_BAND8_TAS2;
   BPI_data_type xPDATA_BAND8_TAS3;

   /* Band 9 TAS BPI data */
   BPI_data_type xPDATA_BAND9_TAS1;
   BPI_data_type xPDATA_BAND9_TAS2;
   BPI_data_type xPDATA_BAND9_TAS3;

   /* Band 10 TAS BPI data */
   BPI_data_type xPDATA_BAND10_TAS1;
   BPI_data_type xPDATA_BAND10_TAS2;
   BPI_data_type xPDATA_BAND10_TAS3;

   /* Band 11 TAS BPI data */
   BPI_data_type xPDATA_BAND11_TAS1;
   BPI_data_type xPDATA_BAND11_TAS2;
   BPI_data_type xPDATA_BAND11_TAS3;

   /* Band 19 TAS BPI data */
   BPI_data_type xPDATA_BAND19_TAS1;
   BPI_data_type xPDATA_BAND19_TAS2;
   BPI_data_type xPDATA_BAND19_TAS3;
}U_sUl1dRfTasBpiData;

typedef struct
{
   BPI_data_type       umtsTasMask;
   U_sUl1dRfTasBpiData umtsTasPdata;
}U_sUl1dRfTasData;


#if (IS_3G_TAS_UL1_CUSTOM_SET)

typedef enum
{
   TAS_TYPE_0,    /* TAS Disable */
   TAS_TYPE_1,    /* TAS with Rx Diversity support */
   TAS_TYPE_2,    /* TAS WITHOUT Rx Diversity support */
} ul1_tas_type_E;

typedef enum
{
   BY_BAND_TAS_TYPE_0 = TAS_TYPE_0,/* TAS Disable */
   BY_BAND_TAS_TYPE_1 = TAS_TYPE_1,/* TAS with Rx Diversity support */
   BY_BAND_TAS_TYPE_2 = TAS_TYPE_2,/* TAS WITHOUT Rx Diversity support */
   BY_BAND_TAS_TYPE_Default        /* Set TAS type as tas_default_type for each band */
} ul1_tas_type_by_band_E;

typedef enum
{
   UL1_ANTENNA_0,     /* Main antenna */
   UL1_ANTENNA_1,     /* Diversity antenna */
   UL1_ANTENNA_2,     /* Auxiliary antenna */
   UL1_ANTENNA_NUM
}
ul1_antenna_idx_E;

typedef struct
{
   kal_int16           rscp_diff_thd_po;           /* RSCP difference threshold */
   kal_int16           rscp_cb_thd;                /* RSCP drop threshold */
   kal_int8            txp_cb_thd;                 /* Transmit power increase threshold during check-back */
   kal_uint8           n_ms_cb;                    /* Check-back period for RSCP, TXP (in measurement slots, MS) */
   kal_int8            u_htp;                      /* High transmit power offset */
   kal_uint8           htp_thd;                    /* High transmit power ratio threshold (in percentage, %) */
   kal_int8            tpc_inc_thd1;               /* Transmit power increase threshold */
   kal_uint8           n_ms_sb;                    /* Monitoring duration for switch-back check (in measurement slots, MS) */
} UMTS_TAS_Type1_Params_T;

typedef struct
{
   //kal_uint16          t_thd1_j;                   /* Periodic check timer threshold (in frames) */
   kal_int16           rscp_thd_po;                /* RSCP threshold */
   kal_int16           rscp_cb_thd;                /* RSCP drop threshold */
   kal_int8            txp_cb_thd;                 /* Transmit power increase threshold during check-back */
   kal_uint8           n_ms_cb;                    /* Check-back period for RSCP, TXP (in measurement slots, MS) */
   kal_int8            u_htp;                      /* High transmit power offset */
   kal_uint8           htp_thd;                    /* High transmit power ratio threshold (in percentage, %) */
   kal_int16           rscp_drop_thd_po;           /* RSCP drop threshold */
   kal_int8            tpc_inc_thd;                /* Transmit power increase threshold */
   kal_uint8           n_ms_sb;                    /* Monitoring duration for switch-back check (in measurement slots, MS) */
   kal_int16           rscp_thd_idle;              /* RSCP threshold for IDLE mode */
   kal_int16           rscp_drop_thd_idle;         /* RSCP drop threshold for IDLE mode */
   kal_uint8           n_ms_sb_idle;               /* Monitoring duration for switch-back check in IDLE mode (in DRX cycles) */
} UMTS_TAS_Type2_Params_T;

typedef struct {
   ul1_tas_type_by_band_E      xBand1_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand2_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand3_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand4_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand5_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand6_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand8_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand9_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand10_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand11_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand19_TAS_TYPE;
} UMTS_TAS_Type_By_Band_T;

typedef struct
{
   kal_bool                   umts_tas_enable;
   kal_bool                   umts_tas_support_on_test_sim;
   ul1_antenna_idx_E          umts_tas_default_main_antenna;
   ul1_tas_type_E             umts_tas_default_type;
   UMTS_TAS_Type_By_Band_T    umts_tas_type_by_band;
#if 0/* Remove from NVRAM */   
/* under construction !*/
/* under construction !*/
#endif
#if IS_3G_FORCE_TX_ANT_SUPPORT
   kal_bool                   umts_tas_force_tx_ant_enable;
   ul1_antenna_idx_E          umts_tas_force_tx_ant_index;
#endif/* IS_3G_FORCE_TX_ANT_SUPPORT */
} UMTS_TAS_Configuration_T;

#endif/*IS_3G_TAS_UL1_CUSTOM_SET*/

#endif/*IS_3G_TAS_SUPPORT*/

typedef struct
{
   UMTSBand HB1;
   UMTSBand HB2;
#if defined (__UL1_HS_PLUS_PLATFORM__)
#if IS_URF_ORION_HPLUS || IS_URF_MT6167 || IS_URF_MT6166 || IS_URF_MT6169
   UMTSBand HB3;
#endif
#endif
   UMTSBand LB1;
#if IS_RF_MT6162||IS_URF_ORION_HPLUS || IS_URF_MT6167 || IS_URF_MT6166 || IS_URF_MT6169
   UMTSBand LB2;
#endif
}U_sUl1dRfBandIndicator;

typedef struct
{
   kal_uint8 xBAND1_CHANNEL_SEL;
   kal_uint8 xBAND2_CHANNEL_SEL;
   kal_uint8 xBAND3_CHANNEL_SEL;
   kal_uint8 xBAND4_CHANNEL_SEL;
   kal_uint8 xBAND5_CHANNEL_SEL;
   kal_uint8 xBAND6_CHANNEL_SEL;
   kal_uint8 xBAND8_CHANNEL_SEL;
   kal_uint8 xBAND9_CHANNEL_SEL;
   kal_uint8 xBAND10_CHANNEL_SEL;
#if defined (__UL1_HS_PLUS_PLATFORM__)
   kal_uint8 xBAND11_CHANNEL_SEL;
   kal_uint8 xBAND19_CHANNEL_SEL;
//#if IS_RF_RXD_SUPPORT
   kal_uint8 xBAND1_CHANNEL2_SEL;
   kal_uint8 xBAND2_CHANNEL2_SEL;
   kal_uint8 xBAND3_CHANNEL2_SEL;
   kal_uint8 xBAND4_CHANNEL2_SEL;
   kal_uint8 xBAND5_CHANNEL2_SEL;
   kal_uint8 xBAND6_CHANNEL2_SEL;
   kal_uint8 xBAND8_CHANNEL2_SEL;
   kal_uint8 xBAND9_CHANNEL2_SEL;
   kal_uint8 xBAND10_CHANNEL2_SEL;
   kal_uint8 xBAND11_CHANNEL2_SEL;
   kal_uint8 xBAND19_CHANNEL2_SEL;
//#endif
#endif
}U_sUl1dRfRxLnaPortSel;

typedef struct
{
   kal_uint8 xBAND1_OUTPUT_SEL;
   kal_uint8 xBAND2_OUTPUT_SEL;
   kal_uint8 xBAND3_OUTPUT_SEL;
   kal_uint8 xBAND4_OUTPUT_SEL;
   kal_uint8 xBAND5_OUTPUT_SEL;
   kal_uint8 xBAND6_OUTPUT_SEL;
   kal_uint8 xBAND8_OUTPUT_SEL;
   kal_uint8 xBAND9_OUTPUT_SEL;
   kal_uint8 xBAND10_OUTPUT_SEL;
#if defined (__UL1_HS_PLUS_PLATFORM__)
   kal_uint8 xBAND11_OUTPUT_SEL;
   kal_uint8 xBAND19_OUTPUT_SEL;
#endif
}U_sUl1dRfTxPathSel;

typedef struct
{
   kal_uint32 Rx_Main_Path_Onoff;
   kal_uint32 Rx_Diversity_Path_Onoff;
}U_sUl1dRxdPathSetting;

#if defined (__UL1_HS_PLUS_PLATFORM__)
typedef struct
{
   MPR_Setting HSDPA_MprBackOff[20];
   MPR_Setting HSUPA_MprBackOff[20];
}U_sUl1dMprBackOff;
#endif

typedef struct
{
   /* Start pattern to be recognized by Modem Bin Update Tool */
   kal_uint32 startPattern;

   /* RF and parameter structure version */
   kal_uint8 structVersion; // record structure version for tool once we add more parameters to be customized in the future
   kal_uint8 rfType; // needed? To distinguish O3, OH and furhter 3G RF chips
   kal_uint8 isDataUpdate; // default FALSE, will be update to be TRUE after tool update parameters
   #if defined (__UL1_HS_PLUS_PLATFORM__)
   kal_bool  umtsRfSettingByNVRAM; // default True. if the value is False, than Single SW for Multiple HW scheme will be applied.
   #endif

   /* Timing of PA control */
   U_sUl1dRfPaControlTiming umtsRfPaControlTimingOffset;

   /* RF T/RX timing offset */
   U_sUl1dRfBsiBpiTiming umtsBsiBpiTiming;

   /* BPI data allocation */
   U_sUl1dRfBpiData umtsPdata;

   /* RF Hign-band and Low-band indicator */
   U_sUl1dRfBandIndicator umtsBandIndicator;

   /* RX LNA port selection */
   U_sUl1dRfRxLnaPortSel umtsRxLnaPortSel;

   /* TX output path selection */
   U_sUl1dRfTxPathSel umtsTxPathSel;

   /* PMU VPA control disable/enable */
   kal_bool xPMU_PA_CONTROL;

#if defined (__UL1_HS_PLUS_PLATFORM__)
   /* PMU VPA control disable/enable */
   U_sUl1dMprBackOff umtsMprBackOff;
#endif
   
   /* RxD support bit map*/
   kal_bool umtsRxDAlwaysOn;
   
   /* Tx PA dirft compensation bit map*/
   kal_uint32 umtsPADriftCompensation;

   /*MT6320, Vrf18 Bulk=>LOD solution*/
   kal_bool ultra_low_cost_solution;

   /*MT6167, temperature measurement enable*/
   kal_bool customer_TM_enable;

   /*for DRDI, to prevent the DRDI NVRAM write after the first boot*/
   kal_bool isDrdiNvramSaved;

   kal_uint16 drdiCombinedIndex;

   /* Baseband Idle Mode RXD Feature enable */
   kal_bool umtsIdleModeRxDOn;

#if IS_3G_TX_POWER_OFFSET_SUPPORT
   /*Tx power offset enable*/
   U_sUl1dMetaTxPowerOffsetSetting umtsTxPowerOffsetSetting;
#endif /* IS_3G_TX_POWER_OFFSET_SUPPORT */

#if IS_3G_FDD_RX_PATH_SELECTION_SUPPORT
   U_sRxPathSelection umtsRxPathSelection;

#endif /*IS_3G_FDD_RX_PATH_SELECTION_SUPPORT*/

   /* End pattern to be recognized by Modem Bin Update Tool */
   kal_uint32 endPattern;
   
}U_sUl1dRfCustomInputData;

/*******************************************************************************
** Global data for RF customization and META Factory Calibration
*******************************************************************************/
#if defined (__UL1_HS_PLUS_PLATFORM__)
extern kal_uint8 ul1d_BandInfo[5];
#else
extern kal_uint8 rxHighBand1Indicator;
extern kal_uint8 rxHighBand2Indicator;
extern kal_uint8 rxHighBand3Indicator;
extern kal_uint8 rxLowBand1Indicator;
extern kal_uint8 rxLowBand2Indicator;
#endif

extern U_sUl1dRfCustomInputData UMTS_RF_CUSTOM_INPUT_DATA;
extern U_sTEMPAGCOFFSET*  U_AGC_PATHLOSS_TABLE[];
extern kal_uint16 U_TEMP_DAC[CAL_TEMP_SECTION];
extern U_sRAMPDATA*  UMTS_RampData[];
extern U_sPAOCTLVLSETTING*  U_PA_OCTLEV_TABLE[];
extern U_sPARACHTMCOMPDATA* U_PA_RACH_COMP_TABLE[];
extern U_sAFCDACDATA U_AFC_DAC;
extern U_sAFCCAPDATA U_AFC_CAP;

extern kal_uint8  DC2DC[UMTS_RF_MAX_PA_SECTIONS];
extern kal_uint8  VM_data[UMTS_RF_MAX_PA_SECTIONS];
extern kal_int16  UMTS_RX_START_TQ_TABLE[UMTS_RF_RX_START_TIMING_ARRAY_LENGTH];
extern kal_int16  UMTS_RX_END_TQ_TABLE[UMTS_RF_RX_END_TIMING_ARRAY_LENGTH];
#if IS_RF_MT6162
extern kal_int16  UMTS_TX_START_TQ_TABLE[7];
extern kal_int16  UMTS_TX_END_TQ_TABLE[3];
#else
extern kal_int16  UMTS_TX_START_TQ_TABLE[UMTS_RF_TX_START_TIMING_ARRAY_LENGTH];
extern kal_int16  UMTS_TX_END_TQ_TABLE[UMTS_RF_TX_END_TIMING_ARRAY_LENGTH];
#endif


extern BPI_data_type  UMTS_PDATA_TABLE[][UMTS_RF_BPI_DATA_TABLE_NUM_OF_WINDOWS][UMTS_RF_BPI_DATA_TABLE_NUM_OF_EVENTS];

#if defined(__UMTS_R8__)
extern BPI_data_type  UMTS_PDATA2_RX_TABLE[][UMTS_RF_BPI_DATA2_TABLE_NUM_OF_EVENTS];
#endif

extern kal_int16 max_rx_start_offset;
extern kal_int16 max_tx_start_offset;
extern kal_int16 min_rx_end_offset;
extern kal_int16 min_tx_end_offset;
extern kal_uint16 max_offset;
extern kal_uint16 vm_offset;
extern kal_uint16 vbias_offset;
extern kal_uint16 dc2dc_offset;
extern kal_uint16 vga_offset;
extern kal_uint8  pa_section;
extern kal_uint16 vbias_mode;
// Start for ADAPT IOT AMR workaround
//extern kal_bool UL1_IS_ADAPT_IOT_CUSTOMIZATION; //remove for gcc build error
// End for ADAPT IOT AMR workaround
extern kal_uint32 UL1D_DCXO_CAPID;
extern kal_bool   UL1D_Set_CAPID;

#if defined (__UMTS_R8__)
extern U_sAGCOFFSETRXD*     U_AGC_PATHLOSS_RXD_TABLE[]; //RXD path loss
extern U_sPADRIFTSETTING*   U_PA_DRIFT_TABLE[];
#endif

#if IS_3G_TX_POWER_OFFSET_SUPPORT
extern U_sTXPOWEROFFSETDATA*  U_TX_POWER_OFFSET_TABLE[];
#endif /* IS_3G_TX_POWER_OFFSET_SUPPORT */

#if IS_3G_TAS_SUPPORT
extern U_sUl1dRfTasData UMTS_TAS_RF_TABLE;
extern BPI_data_type  UMTS_TAS_PDATA_TABLE[][UL1_ANTENNA_NUM+1];

extern UMTS_TAS_Configuration_T UMTS_TAS_Configuration_Table;
#endif/*IS_3G_TAS_SUPPORT*/

/*******************************************************************************
** Global Function Prototypes for RF customization and META Factory Calibration
*******************************************************************************/
// for RAC and L4 to recognize this FDD HW band support query API
extern void UL1D_UeBandCapability(kal_uint16 *ue_cap);
extern void UL1D_UeBandCapabilityEx(kal_uint32 *ue_cap);
extern void UL1TST_MsCapability(UMTS_MsCapabilityEx *ms_cap);
extern void UL1D_RF_SetTempDac(void* table);
extern void UL1D_RF_SetPathLossTable(UMTSBand rf_band, void* table);
extern void UL1D_RF_SetTxDacData(UMTSBand rf_band, void* table );
extern void UL1D_RF_SetPaApcDac(UMTSBand rf_band, kal_uint16 idx, kal_uint8 pa_mode, kal_uint8 vm1, kal_uint8 vm2, kal_uint16 dc2dc_level, kal_uint16 vbias_dac, kal_uint16 apc_dac);
extern void UL1D_RF_SetImmediateBSI(kal_uint32 bsidata);
extern void UL1D_RF_GetImmediateBSI(kal_uint32 bsi_addr, kal_uint32 *bsi_data);
extern void UL1D_RF_SetTxPaOctLevData(UMTSBand rf_band, void* table);
extern void UL1D_RF_GetPwrDetMeas(kal_uint16 txpwr_set_idx, kal_uint16 *txpwr_meas);
extern void UL1D_RF_SetTxPrachTmCompData(UMTSBand rf_band, void* table);
extern void UL1D_RF_SetAfcDac(void* table);
extern void UL1D_RF_SetAfcCap(void* table);


#if defined(__UMTS_R8__)

extern void UL1D_RF_SetPathLossRxdTable( UMTSBand rf_band, void* table );
extern kal_uint8 UL1D_RF_GetCurrRxDLnaStatus(void);
extern void UL1D_RF_SetTxPaDriftData(UMTSBand rf_band, void* table);
extern void UL1D_RF_SetRxBandwidth(kal_bool is_5mhz);

//just for META link, UL1 define this function as dummy macro
#define UL1D_RF_SetPwrCtrlMode(x)
#else
extern void UL1D_RF_SetPwrCtrlMode(kal_uint8 mode);
#endif

#if !IS_HSPA_HWTPC
extern void UL1D_Meta_HWTPC_Config(kal_uint8 pc_algo, kal_uint8 tpc_used_frame, kal_int16 pini, META_HWTPC_FRAME_INFO* info);
#else
extern void UL1D_Meta_HWTPC_Config(META_HWTPC_INFO *info, META_HWTPC_FRAME_INFO* f_info);
#endif
extern kal_bool UL1TST_GET_BIT_COUNT(kal_uint32* total_bits, kal_uint32* error_bits);
extern kal_int8 UL1D_RF_Replace_Gain_Table_for_Cal(kal_uint32 action);
extern kal_uint8 UL1D_RF_GetCurrRxLnaStatus(void);
extern kal_uint32 UL1D_RF_GetID(void);
extern kal_uint32 UL1TST_CAPID_MAX(void);
extern void UL1D_RF_SetCrystalCap(kal_uint32 cap_no);

//For NVRAM
extern void UL1D_RF_SetDefaultCalDataDetection(kal_uint8 index);
extern void nvram_init_uL1_RF_customInputData(void);

#if (IS_3G_MIPI_SUPPORT)
void nvram_init_uL1_mipiData(void);

#if (IS_3G_MIPI_NVRAM_FULL_SUPPORT)
void nvram_init_uL1_mipiTxData(void);
void nvram_init_uL1_mipiTxEvent(void);
void nvram_init_uL1_mipiRxData(void);
void nvram_init_uL1_mipiRxEvent(void);
void nvram_init_uL1_mipiInitCw(void);
void nvram_init_uL1_mipiSleepCw(void);
#if (IS_3G_ET_NVRAM_SUPPORT)
void nvram_init_uL1_mipiEtOnCw(void);
void nvram_init_uL1_mipiEtOffCw(void);
#endif/*IS_3G_ET_NVRAM_SUPPORT*/

#if (IS_3G_VPA_SEL_BY_BAND_SUPPORT)
void nvram_init_uL1_vpaSrcSel(void);
#endif/*IS_3G_VPA_SEL_BY_BAND_SUPPORT*/

#endif/*IS_3G_MIPI_NVRAM_FULL_SUPPORT*/

#define M_UMTS_MIPI_RX_EVENT(x) UMTS_MIPI_RX_EVENT_##x
#define M_UMTS_RX_EVENT(x)      M_UMTS_MIPI_RX_EVENT(x)

#define M_UMTS_MIPI_RX_DATA(x)  UMTS_MIPI_RX_DATA_##x
#define M_UMTS_RX_DATA(x)       M_UMTS_MIPI_RX_DATA(x)

#define M_UMTS_MIPI_TX_EVENT(x) UMTS_MIPI_TX_EVENT_##x
#define M_UMTS_TX_EVENT(x)      M_UMTS_MIPI_TX_EVENT(x)

#define M_UMTS_MIPI_TX_DATA(x)  UMTS_MIPI_TX_DATA_##x
#define M_UMTS_TX_DATA(x)       M_UMTS_MIPI_TX_DATA(x)

#define M_UMTS_MIPI_TPC(x)      &UMTS_MIPI_TPC_##x
#define M_UMTS_TPC(x)           M_UMTS_MIPI_TPC(x)

#define M_UMTS_MIPI_TPC_EVENT(x) UMTS_MIPI_TPC_##x.umts_mipi_tpc_event
#define M_UMTS_TPC_EVENT(x)      M_UMTS_MIPI_TPC_EVENT(x)

#define M_UMTS_MIPI_TPC_DATA(x)  UMTS_MIPI_TPC_##x.umts_mipi_tpc_data
#define M_UMTS_TPC_DATA(x)       M_UMTS_MIPI_TPC_DATA(x)

#define M_UMTS_MIPI_ASM_ISO(x)   UMTS_MIPI_ASM_ISOLATION_DATA_##x
#define M_UMTS_ASM_ISO(x)        M_UMTS_MIPI_ASM_ISO(x)

#if (IS_3G_ET_SUPPORT)
void nvram_init_uL1_etData(void);

#define M_UMTS_MIPI_ET(x)       &UMTS_MIPI_ET_##x
#define M_UMTS_ET(x)            M_UMTS_MIPI_ET(x)

#define M_UMTS_MIPI_ET_EVENT(x) UMTS_MIPI_ET_##x.umts_mipi_et_event
#define M_UMTS_ET_EVENT(x)      M_UMTS_MIPI_ET_EVENT(x)

#define M_UMTS_MIPI_ET_DATA(x)  UMTS_MIPI_ET_##x.umts_mipi_et_data
#define M_UMTS_ET_DATA(x)       M_UMTS_MIPI_ET_DATA(x)

#if (IS_3G_VPA_SEL_BY_BAND_SUPPORT)
#define M_UMTS_VPA_SRC_SEL(x)   UMTS_VPA_SOURCE_##x
#define M_UMTS_VPA_SRC(x)       M_UMTS_VPA_SRC_SEL(x)
#endif/*IS_3G_VPA_SEL_BY_BAND_SUPPORT*/

#define ET_MAX_ON_IMM_BSI_CW_NUM   30

#define ET_MAX_OFF_IMM_BSI_CW_NUM  20

#endif/*IS_3G_ET_SUPPORT*/

#if (IS_3G_TAS_SUPPORT)
#define M_UMTS_TAS_BPI(value, mask, bpiData) (((value)&(mask))|(bpiData))

#define UL1D_TAS_BPI_PIN_GEN(var1, var2, var3)   ( ((UMTS_TAS_BPI_PIN_1==UMTS_TAS_BPI_PIN_NULL)?0:((var1)<< UMTS_TAS_BPI_PIN_1))|\
                                                   ((UMTS_TAS_BPI_PIN_2==UMTS_TAS_BPI_PIN_NULL)?0:((var2)<< UMTS_TAS_BPI_PIN_2))|\
                                                   ((UMTS_TAS_BPI_PIN_3==UMTS_TAS_BPI_PIN_NULL)?0:((var3)<< UMTS_TAS_BPI_PIN_3)) )

#endif/*IS_3G_TAS_SUPPORT*/


#define MIPI_MAX_INITIAL_IMM_BSI_CW_NUM   30

#define MIPI_MAX_SLEEP_IMM_BSI_CW_NUM     20

#define MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM     1

#endif

#if IS_URF_MT6167 || IS_URF_MT6166 || (IS_URF_MT6169 && MT6169_TO_DO)
extern unsigned long UL1D_RF_GetRxDCOC_CW151(void);
#endif

#endif /* End of #ifndef UL1D_RF_PUBLIC_H */

