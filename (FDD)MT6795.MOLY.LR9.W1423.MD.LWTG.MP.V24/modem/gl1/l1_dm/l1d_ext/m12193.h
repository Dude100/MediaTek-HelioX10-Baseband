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
 *   m12193.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   AFC DAC and RX ADC configuration
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.26  $
 * $Modtime:   Jul 29 2005 13:45:52  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1/l1d/m12193.h-arc  $
 *
 * 10 02 2013 ola.lee
 * removed!
 * 	.
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
 * 10 21 2011 th.yeh
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
 * 
 *
 * removed!
 * removed!
 * Merge MT6251 DVT branch back to MAUI
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
 * [L1D][Modify] Check in AD6546 RF Driver #if IS_RF_AD6546
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
 * Change default AFC slpoe from 3.2 to 7.0
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Change DSP setpoint from 42dBd to 47dBd in MT6223+MT6139E platform
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
 * Add RF driver of IRFS3001
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Modify the EDGE_SETPOINT_GAIN_OFFSET of SKY74137
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
 * deliver MAUI_00174200 on 2006/2/27 ¤U¤È 05:12:46.
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
 *    Rev 1.26   Jul 29 2005 14:01:52   mtk00773
 * [L1D][Enhence] Support RF SKY74117
 * Resolution for 12111: [L1D][Enhence] Support RF SKY74117
 *
 *    Rev 1.25   Jul 08 2005 16:53:06   mtk00939
 * [L1D][Modify]L1D add code for MT6139C and META related code
 *
 *    Rev 1.24   May 17 2005 00:34:38   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.23   Jan 18 2005 00:38:10   BM
 * append new line in W05.04
 *
 *    Rev 1.22   Jul 30 2004 17:37:06   mtk00240
 * L1D add code to support AERO1Plus RF chip
 * Resolution for 6925: [L1D][Enhance] L1D add code to support AERO1Plus RF chip
 *
 *    Rev 1.21   Jul 05 2004 15:51:32   mtk00773
 * Add RF POLARIS1 setting
 *
 *    Rev 1.20   May 21 2004 19:01:58   mtk00240
 * Add code to support MT6129D
 * Resolution for 5565: [L1D][Add Feature] Add code to support MT6129D
 *
 *    Rev 1.19   Feb 13 2004 23:53:10   mtk00489
 * [L1D][Enhanced]1.adjust L1D DL DTX threshold to improve DTX detection rate 2.enhanced Dummy burst detection rate 3.change RX ADC to 2.24V for MT61xx 4.modify LP2 code to pass MT6218BECO3 validation 5.modify new interface for dll(CHIP_VER)
 * Resolution for 3912: [L1D][Enhanced]1.adjust L1D DL DTX threshold to improve DTX detection rate 2.enhanced Dummy burst detection rate 3.change RX ADC to 2.24V for MT61xx 4.modify LP2 code to pass MT6218BECO3 validation 5.modify new interface for dll(CHIP_VER)
 *
 *    Rev 1.18   Jan 27 2004 15:33:12   mtk00585
 * [L1D][Add] L1D Add code for MT6129C RF Driver.
 *
 *    Rev 1.17   Jan 12 2004 14:26:20   mtk00489
 * [L1D][Enhanced]L1D modify code to sync with FT load. 1.Delay 400QB of CTIRQ1/2 and DSP_GPRS_DFB_ON for mt6218A/B 2.separate CSD and GPRS's DSP_TCH_BFI_THRESHOLD 3.adjust set-point and gain table for Mt6119C
 * Resolution for 3714: [L1D][Enhanced]L1D modify code to sync with FT load. 1.Delay 400QB of CTIRQ1/2 and DSP_GPRS_DFB_ON for mt6218A/B 2.separate CSD and GPRS's DSP_TCH_BFI_THRESHOLD 3.adjust set-point and gain table for Mt6119C
 *
 *    Rev 1.16   Oct 23 2003 14:22:20   mtk00585
 * [L1D][Add] L1D Add code for MT6129B RF Driver.
 * Resolution for 3177: [L1D][Add] L1D Add code for MT6129B RF Driver.
 *
 *    Rev 1.15   Oct 22 2003 12:43:48   mtk00240
 * Remove redefine SETPOINT_GAIN_OFFSET of Bright4
 * Resolution for 3171: [L1D][Fix Compile Error] Redefine SETPOINT_GAIN_OFFSET of Bright4 in m12193.h
 *
 *    Rev 1.14   Oct 20 2003 10:20:54   mtk00240
 * L1D add setpoints for all RF on mt6218B and change F3's set-pount on mt6218
 * Resolution for 3147: [L1D][Enhance] L1D add setpoints for all RF on mt6218B and change F3's set-pount on mt6218
 *
 *    Rev 1.13   Jul 11 2003 17:41:32   mtk00489
 * [L1D][Enhanced]L1D supports MT6129A
 * Resolution for 2241: [L1D][Enhanced]L1D supports MT6129A
 *
 *    Rev 1.12   Jun 26 2003 15:22:18   mtk00240
 * L1D modify some code to support MT6218
 * Resolution for 2116: [L1D][Enhance] L1D modify some code to support MT6218
 *
 *    Rev 1.11   May 16 2003 13:09:24   mtk00489
 * [L1D][New Feature]L1D supports MT6119C
 * Resolution for 1794: [L1D][New Feature]L1D supports MT6119C
 *
 *    Rev 1.10   Jan 17 2003 16:34:00   mtk00474
 * Update AFC slope value
 * Resolution for 631: Update AFC slope value
 *
 *    Rev 1.9   13 Jan 2003 15:13:20   mtk00361
 * Modify DSP_SETPOINT for MT6119 from 40 to 43
 *
 *    Rev 1.8   Nov 11 2002 18:04:58   mtk00474
 * Update MT6119 and AERO RF parameters
 * Resolution for 557: Update MT6119 and AERO RF parameters
 *
 *    Rev 1.7   Sep 06 2002 17:21:42   mtk00210
 * add new define for dynamic setpoint and remove definition for MT6116
 *
 *    Rev 1.6   24 Aug 2002 16:22:00   mtk00361
 * Define dedicated AFC parameter and DSP set point for each RF module
 *
 *    Rev 1.5   22 Jul 2002 08:43:30   mtk00361
 * Modify complie option for MT6205
 *
 *    Rev 1.4   Jul 05 2002 21:34:50   mtk00210
 * Re-construct the header for customer release
 *
 *
 *******************************************************************************/

#ifndef  _M12193_H_
#define  _M12193_H_

#include "l1d_cid.h"
/* Parameter read from Flash or EEPROM */

/*  Bit width of AFC DAC:                           */
/*                     Default     Option           */
/*  1)MT6208,FPGA      10-bit      13-bit           */
/*  2)MT6205           13-bit        X              */

//#define AFC_13bit     /* used to turn on 13-bit AFC DAC for MT6208 or FPGA */
//#define RX_ADC_14bit
#ifdef __MTK_TARGET__
   #if  (!defined(FPGA))&&(!defined(MT6208))
/*MT6205~*/ #ifndef  AFC_13bit
/*MT6205~*/ #define  AFC_13bit
/*MT6205~*/ #endif
   #endif
#endif

#ifdef AFC_13bit
/* Due to 13bits DAC */
   #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G) /* VCXO   */
      #if IS_RF_MT6251RF || IS_RF_MT6255RF || IS_RF_MT6163 || IS_RF_MT6162 || IS_RF_MT6280RF || IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165
#define  PSI_EE               (4500)            /* DAC initial value */
      #else
#define  PSI_EE               (4100)            /* DAC initial value */
      #endif
   #else                 /* VCTCXO */
      #if IS_RF_MT6162 || IS_RF_MT6163
#define  PSI_EE               (4000)            /* DAC initial value (Setting 4000 is for 3G ) */
      #else
#define  PSI_EE               (4500)            /* DAC initial value */
      #endif
   #endif
#define  AFC_DP_MIN           (0)
#define  AFC_DP_MAX           (8191)
#else
/* Due to 10bits DAC */
#define  PSI_EE               (517)             /* DAC initial value */
#define  AFC_DP_MIN           (0)
#define  AFC_DP_MAX           (1023)
#endif

#if IS_RF_BRIGHT2
/*BRIGHT2*/ #ifdef AFC_13bit
/*BRIGHT2*/ #define  C_PSI_STA     (1940)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=2.111  */
/*BRIGHT2*/ #else
/*BRIGHT2*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*BRIGHT2*/ #endif
/*BRIGHT2*/
/*BRIGHT2*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*BRIGHT2*//*MT6218B~*/ #define  DSP_SETPOINT  (49)
/*BRIGHT2*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*BRIGHT2*//*MT6218A*/  #define  DSP_SETPOINT  (49)
/*BRIGHT2*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*BRIGHT2*//*OTHERS*/   #define  DSP_SETPOINT  (45)
/*BRIGHT2*/ #endif
/*BRIGHT2*/ /* Note that setpoint and edge_setpoint cannot be nonzero simulataneously */
/*BRIGHT2*/ #define  SETPOINT_GAIN_OFFSET 0
/*BRIGHT2*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_BRIGHT4
/*BRIGHT4*/ #ifdef AFC_13bit
/*BRIGHT4*/ #define  C_PSI_STA     (1462)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=2.8  */
/*BRIGHT4*/ #else
/*BRIGHT4*/ #define  C_PSI_STA     (110)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=37  */
/*BRIGHT4*/ #endif
/*BRIGHT4*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*BRIGHT4*//*MT6218B~*/ #define  DSP_SETPOINT  (46)
/*BRIGHT4*//*MT6218B~*/ #define  SETPOINT_GAIN_OFFSET 0
/*BRIGHT4*//*MT6218B~*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
/*BRIGHT4*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*BRIGHT4*//*MT6218A*/  #define  DSP_SETPOINT  (49)
/*BRIGHT4*//*MT6218A*/  #define  SETPOINT_GAIN_OFFSET 0
/*BRIGHT4*//*MT6218A*/  #define  EDGE_SETPOINT_GAIN_OFFSET 0
/*BRIGHT4*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*BRIGHT4*//*OTHERS*//* Note that setpoint and edge_setpoint cannot be nonzero simulataneously */
/*BRIGHT4*//*OTHERS*/   #define  DSP_SETPOINT  (34)
/*BRIGHT4*//*OTHERS*/   #define  SETPOINT_GAIN_OFFSET -6
/*BRIGHT4*//*OTHERS*/   #define  EDGE_SETPOINT_GAIN_OFFSET 0
/*BRIGHT4*/ #endif
#endif

#if IS_RF_BRIGHT5P
/*BRIGHT5P*/ #ifdef AFC_13bit
/*BRIGHT5P*/ #define  C_PSI_STA     (1462)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=2.8  */
/*BRIGHT5P*/ #else
/*BRIGHT5P*/ #define  C_PSI_STA     (110)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=37  */
/*BRIGHT5P*/ #endif
/*BRIGHT5P*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*BRIGHT5P*//*MT6218B~*//* Note that setpoint and edge_setpoint cannot be nonzero simulataneously */
/*BRIGHT5P*//*MT6218B~*/ #define  DSP_SETPOINT  (46)
/*BRIGHT5P*//*MT6218B~*/ #define  SETPOINT_GAIN_OFFSET 0
/*BRIGHT5P*//*MT6218B~*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
/*BRIGHT5P*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*BRIGHT5P*//*MT6218A*/  #define  DSP_SETPOINT  (49)
/*BRIGHT5P*//*MT6218A*/  #define  SETPOINT_GAIN_OFFSET 0
/*BRIGHT5P*//*MT6218A*/  #define  EDGE_SETPOINT_GAIN_OFFSET 0
/*BRIGHT5P*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*BRIGHT5P*//*OTHERS*/   #define  DSP_SETPOINT  (34)
/*BRIGHT5P*//*OTHERS*/   #define  SETPOINT_GAIN_OFFSET -6
/*BRIGHT5P*//*OTHERS*/   #define  EDGE_SETPOINT_GAIN_OFFSET 0
/*BRIGHT5P*/ #endif
#endif

#if IS_RF_AERO
/*AERO*/ #ifdef AFC_13bit
/*AERO*/ #define  C_PSI_STA     (1940)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=2.111  */
/*AERO*/ #else
/*AERO*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*AERO*/ #endif
/*AERO*/
/*AERO*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*AERO*//*MT6218B~*/ #define  DSP_SETPOINT  (49)
/*AERO*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*AERO*//*MT6218A*/  #define  DSP_SETPOINT  (49)
/*AERO*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*AERO*//*OTHERS*/   #define  DSP_SETPOINT  (45)
/*AERO*/ #endif
/*AERO*//* Note that setpoint and edge_setpoint cannot be nonzero simulataneously */
/*AERO*/ #define  SETPOINT_GAIN_OFFSET 0
/*AERO*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_AERO1PLUS
/*AERO1+*/ #ifdef AFC_13bit
/*AERO1+*/ #define  C_PSI_STA     (1940)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=2.111  */
/*AERO1+*/ #else
/*AERO1+*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*AERO1+*/ #endif
/*AERO1+*/
/*AERO1+*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*AERO1+*//*MT6218B~*/ #define  DSP_SETPOINT  (49)
/*AERO1+*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*AERO1+*//*MT6218A*/  #define  DSP_SETPOINT  (49)
/*AERO1+*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*AERO1+*//*OTHERS*/   #define  DSP_SETPOINT  (45)
/*AERO1+*/ #endif
/*AERO1+*//* Note that setpoint and edge_setpoint cannot be nonzero simulataneously */
/*AERO1+*/ #define  SETPOINT_GAIN_OFFSET 0
/*AERO1+*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_POLARIS1    /*The value is temporary used*/
/*RFMD*/ #ifdef AFC_13bit
/*RFMD*/ #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*RFMD*/ #else
/*RFMD*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*RFMD*/ #endif
/*RFMD*/
/*RFMD*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*RFMD*//*MT6218B~*/ #define  DSP_SETPOINT  (50)
/*RFMD*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*RFMD*//*MT6218A*/  #define  DSP_SETPOINT  (60)
/*RFMD*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*RFMD*//*OTHERS*/   #define  DSP_SETPOINT  (43)
/*RFMD*/ #endif
/*RFMD*//* Note that setpoint and edge_setpoint cannot be nonzero simulataneously */
/*RFMD*/ #define  SETPOINT_GAIN_OFFSET 0
/*RFMD*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_SKY74117
/*SKY74117*/ #ifdef AFC_13bit
/*SKY74117*/ #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*SKY74117*/ #else
/*SKY74117*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*SKY74117*/ #endif
/*SKY74117*/
/*SKY74117*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*SKY74117*//*MT6218B~*/ #define  DSP_SETPOINT  (53)
/*SKY74117*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*SKY74117*//*MT6218A*/  #define  DSP_SETPOINT  (45)
/*SKY74117*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*SKY74117*//*OTHERS*/   #define  DSP_SETPOINT  (30)
/*SKY74117*/ #endif
/*SKY74117*/ #define  SETPOINT_GAIN_OFFSET 0
/*SKY74117*/ #define  GPRS_SETPOINT_GAIN_OFFSET 5
/*SKY74117*/ #define  EDGE_SETPOINT_GAIN_OFFSET 5
#endif

#if IS_RF_SKY74400
/*SKY74400*/ #ifdef AFC_13bit
/*SKY74400*/ #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*SKY74400*/ #else
/*SKY74400*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*SKY74400*/ #endif
/*SKY74400*/
/*SKY74400*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*SKY74400*//*MT6218B~*/ #define  DSP_SETPOINT  (58)
/*SKY74400*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*SKY74400*//*MT6218A*/  #define  DSP_SETPOINT  (45)
/*SKY74400*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*SKY74400*//*OTHERS*/   #define  DSP_SETPOINT  (30)
/*SKY74400*/ #endif
/*SKY74400*/ #define  SETPOINT_GAIN_OFFSET 0
/*SKY74400*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if (IS_RF_MT6119)||(IS_RF_MT6119C)||(IS_RF_MT6129A)||(IS_RF_MT6129B)||(IS_RF_MT6129C)||(IS_RF_MT6129D)
/*MT6119/C,MT6129A/B/C/D*/ #ifdef AFC_13bit
/*MT6119/C,MT6129A/B/C/D*/ #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*MT6119/C,MT6129A/B/C/D*/ #else
/*MT6119/C,MT6129A/B/C/D*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6119/C,MT6129A/B/C/D*/ #endif
/*MT6119/C,MT6129A/B/C/D*/
/*MT6119/C,MT6129A/B/C/D*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION   /* single-end peak2peak:  1.12V <-> 5184 */
/*MT6119/C,MT6129A/B/C/D*//*MT6218B~*/ #define  DSP_SETPOINT  (56)
/*MT6119/C,MT6129A/B/C/D*/ #elif  IS_CHIP_MT6218A || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION           /* single-end peak2peak:  1.12V <-> 6912 */
/*MT6119/C,MT6129A/B/C/D*//*MT6218A*/  #define  DSP_SETPOINT  (58)
/*MT6119/C,MT6129A/B/C/D*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*MT6119/C,MT6129A/B/C/D*//*OTHERS*/   #define  DSP_SETPOINT  (42)
/*MT6119/C,MT6129A/B/C/D*/ #endif
/*MT6119/C,MT6129A/B/C/D*//* Note that setpoint and edge_setpoint cannot be nonzero simulataneously */
/*MT6119/C,MT6129A/B/C/D*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6119/C,MT6129A/B/C/D*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6139B /*The value is temporary used*/
/*MT6139B*/ #ifdef AFC_13bit
/*MT6139B*/ #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*MT6139B*/ #else
/*MT6139B*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6139B*/ #endif
/*MT6139B*/
/*MT6139B*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*MT6139B*//*MT6218B~*/ #define  DSP_SETPOINT  (42)
/*MT6139B*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*MT6139B*//*MT6218A*/  #define  DSP_SETPOINT  (58)
/*MT6139B*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*MT6139B*//*OTHERS*/   #define  DSP_SETPOINT  (42)
/*MT6139B*/ #endif
/*MT6139B*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6139B*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6139C || IS_RF_MT6140A /*The value is temporary used*/
/*MT6139C*/ #ifdef AFC_13bit
/*MT6139C*/ #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*MT6139C*/ #else
/*MT6139C*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6139C*/ #endif
/*MT6139C*/
/*MT6139C*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*MT6139C*//*MT6218B~*/ #define  DSP_SETPOINT  (42)
/*MT6139C*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*MT6139C*//*MT6218A*/  #define  DSP_SETPOINT  (58)
/*MT6139C*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*MT6139C*//*OTHERS*/   #define  DSP_SETPOINT  (42)
/*MT6139C*/ #endif
/*MT6139C*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6139C*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6139E
/*MT6139E*/ #ifdef AFC_13bit
/*MT6139E*/ #define  C_PSI_STA      (585)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=7    */
/*MT6139E*/ #else
/*MT6139E*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6139E*/ #endif
/*MT6139E*/
/*MT6139E*/ #if    IS_CHIP_MT6225_AND_LATTER_VERSION||IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6139E*//*MT6225~*/  #define  DSP_SETPOINT  (51)
/*MT6139E*/ #elif  IS_CHIP_MT6218B_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*MT6139E*//*MT6218B~*/ #define  DSP_SETPOINT  (49)
/*MT6139E*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*MT6139E*//*MT6218A*/  #define  DSP_SETPOINT  (51)
/*MT6139E*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*MT6139E*//*OTHERS*/   #define  DSP_SETPOINT  (40)
/*MT6139E*/ #endif
/*MT6139E*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6139E*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6140A /*The value is temporary used*/
/*MT6140A*/ #ifdef AFC_13bit
/*MT6140A*/ #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*MT6140A*/ #else
/*MT6140A*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6140A*/ #endif
/*MT6140A*/
/*MT6140A*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION /* single-end peak2peak:  1.12V <-> 5184 */
/*MT6140A*//*MT6218B~*/ #define  DSP_SETPOINT  (42)
/*MT6140A*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*MT6140A*//*MT6218A*/  #define  DSP_SETPOINT  (58)
/*MT6140A*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*MT6140A*//*OTHERS*/   #define  DSP_SETPOINT  (42)
/*MT6140A*/ #endif
/*MT6140A*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6140A*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6140B /*The value is temporary used*/
/*MT6140B*/ #ifdef AFC_13bit
/*MT6140B*/ #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*MT6140B*/ #else
/*MT6140B*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6140B*/ #endif
/*MT6140B*/
/*MT6140B*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION /* single-end peak2peak:  1.12V <-> 5184 */
/*MT6140B*//*MT6218B~*/ #define  DSP_SETPOINT  (42)
/*MT6140B*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*MT6140B*//*MT6218A*/  #define  DSP_SETPOINT  (58)
/*MT6140B*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*MT6140B*//*OTHERS*/   #define  DSP_SETPOINT  (42)
/*MT6140B*/ #endif
/*MT6140B*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6140B*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6140C /*The value is temporary used*/
/*MT6140C*/ #ifdef AFC_13bit
/*MT6140C*/ #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*MT6140C*/ #else
/*MT6140C*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6140C*/ #endif
/*MT6140C*/
/*MT6140C*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*MT6140C*//*MT6218B~*/ #define  DSP_SETPOINT  (42)
/*MT6140C*/ #elif  IS_CHIP_MT6218A || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION                     /* single-end peak2peak:  1.12V <-> 6912 */
/*MT6140C*//*MT6218A*/  #define  DSP_SETPOINT  (45)
/*MT6140C*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*MT6140C*//*OTHERS*/   #define  DSP_SETPOINT  (42)
/*MT6140C*/ #endif
/*MT6140C*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6140C*/ #define  EDGE_SETPOINT_GAIN_OFFSET 5
#endif

#if IS_RF_MT6140D /*The value is temporary used*/
/*MT6140D*/ #ifdef AFC_13bit
/*MT6140D*/    #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G) /*VCXO*/
/*MT6140D*/ #define  C_PSI_STA     (585)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=7    */
/*MT6140D*/    #else                 /*VCTCXO*/
/*MT6140D*/ #define  C_PSI_STA     (1365)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3    */
/*MT6140D*/    #endif
/*MT6140D*/ #else
/*MT6140D*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6140D*/ #endif
/*MT6140D*/
/*MT6140D*/ #if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION
/*MT6140D*/ /*MT6276~*/ #define  DSP_SETPOINT  (51)
/*MT6140D*/ #elif  IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
/*MT6140D*//*MT6238~*/  #define  DSP_SETPOINT  (48)
/*MT6140D*/ #elif  IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140D*//*MT6225~*/  #define  DSP_SETPOINT  (51)
/*MT6140D*/ #elif  IS_CHIP_MT6218B_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*MT6140D*//*MT6218B~*/ #define  DSP_SETPOINT  (49)
/*MT6140D*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*MT6140D*//*MT6218A*/  #define  DSP_SETPOINT  (51)
/*MT6140D*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*MT6140D*//*OTHERS*/   #define  DSP_SETPOINT  (40)
/*MT6140D*/ #endif
/*MT6140D*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6140D*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_CMOSEDGE
/*CMOSEDGE*/ #ifdef AFC_13bit
/*CMOSEDGE*/ #define  C_PSI_STA    (1309)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.1291    */
/*CMOSEDGE*/ #else
/*CMOSEDGE*/ #define  C_PSI_STA    (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*CMOSEDGE*/ #endif
/*CMOSEDGE*/
/*CMOSEDGE*/ #if    IS_CHIP_MT6238
/*CMOSEDGE*//*MT6238~*/  #define  DSP_SETPOINT  (48)
/*CMOSEDGE*/ #elif  IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*CMOSEDGE*//*MT6225~*/  #define  DSP_SETPOINT  (50)
/*CMOSEDGE*/ #elif    IS_CHIP_MT6218B_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*CMOSEDGE*//*MT6218B~*/ #define  DSP_SETPOINT  (49)
/*CMOSEDGE*/ #elif  IS_CHIP_MT6218A                      /* single-end peak2peak:  1.12V <-> 6912 */
/*CMOSEDGE*//*MT6218A*/  #define  DSP_SETPOINT  (51)
/*CMOSEDGE*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*CMOSEDGE*//*OTHERS*/   #define  DSP_SETPOINT  (40)
/*CMOSEDGE*/ #endif
/*CMOSEDGE*/ #define  SETPOINT_GAIN_OFFSET 0
/*CMOSEDGE*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MTKSOC1/*The value is temporary used*/
/*MTKSOC1*/ #ifdef AFC_13bit
/*MTKSOC1*/ #define  C_PSI_STA     (1170)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=4.511  */
/*MTKSOC1*/ #else
/*MTKSOC1*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MTKSOC1*/ #endif
/*MTKSOC1*/ #define  DSP_SETPOINT  (46)  //MT6253 use
/*MTKSOC1*/ #define  SETPOINT_GAIN_OFFSET 0
/*MTKSOC1*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MTKSOC1T/*The value is temporary used*/
/*MTKSOC1T*/ #ifdef AFC_13bit
/*MTKSOC1T*/ #define  C_PSI_STA     (1170)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=4.511  */ 
/*MTKSOC1T*/ #else
/*MTKSOC1T*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MTKSOC1T*/ #endif
/*MTKSOC1T*/ #define  DSP_SETPOINT  (50)  //MT6253T use
/*MTKSOC1T*/ #define  SETPOINT_GAIN_OFFSET 0
/*MTKSOC1T*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6252RF  /*The value is temporary used*/
/*MT6252RF*/ #ifdef AFC_13bit
/*MT6252RF*/ #define  C_PSI_STA     (1170)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=4.511    */ //ZZZZZ
/*MT6252RF*/ #else
/*MT6252RF*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6252RF*/ #endif
/*MT6252RF*/ #define  DSP_SETPOINT  (46)  //MT6253 use
/*MT6252RF*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6252RF*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6256RF
/*MT6256RF*/ #ifdef AFC_13bit
/*MT6256RF*/ #define  C_PSI_STA     (585)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=7.002  */
/*MT6256RF*/ #else
/*MT6256RF*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6256RF*/ #endif
/*MT6256RF*/ #define  DSP_SETPOINT  (64)    // Default setpoint for dynamic setpoint
/*MT6256RF*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6256RF*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6255RF
/*MT6255RF*/ #ifdef AFC_13bit
/*MT6255RF*/ #define  C_PSI_STA     (585)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=7.002  */
/*MT6255RF*/ #else
/*MT6255RF*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6255RF*/ #endif
/*MT6255RF*/ #define  DSP_SETPOINT  (64)    // The same setting as MT6256RF
/*MT6255RF*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6255RF*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6251RF
/*MT6251RF*/ #ifdef AFC_13bit
/*MT6251RF*/ #define  C_PSI_STA     (546)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=7.502  */
/*MT6251RF*/ #else
/*MT6251RF*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6251RF*/ #endif
/*MT6251RF*/ #define  DSP_SETPOINT  (64)    // Same setting as MT6256RF
/*MT6251RF*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6251RF*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_SKY74045    /*The value is temporary used*/
/*SKY74045*/ #ifdef AFC_13bit
/*SKY74045*/ #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*SKY74045*/ #else
/*SKY74045*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*SKY74045*/ #endif
/*SKY74045*/
/*SKY74045*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION/* single-end peak2peak:  1.12V <-> 5184 */
/*SKY74045*//*MT6218B~*/ #define  DSP_SETPOINT  (48)
/*SKY74045*/ #elif  IS_CHIP_MT6218A || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 6912 */
/*SKY74045*//*MT6218A*/  #define  DSP_SETPOINT  (50)
/*SKY74045*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*SKY74045*//*OTHERS*/   #define  DSP_SETPOINT  (45)
/*SKY74045*/ #endif
/*SKY74045*//* Note that setpoint and edge_setpoint cannot be nonzero simulataneously */
/*SKY74045*/ #define  SETPOINT_GAIN_OFFSET 0
/*SKY74045*/ #define  EDGE_SETPOINT_GAIN_OFFSET 8
#endif

#if IS_RF_AERO2
/*AERO2*/ #ifdef AFC_13bit
/*AERO2*/ #define  C_PSI_STA     (745)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=5.5  */
/*AERO2*/ #else
/*AERO2*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*AERO2*/ #endif
/*AERO2*/
/*AERO2*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*AERO2*//*MT6218B~*/ #define  DSP_SETPOINT  (49) //MJ temporary setting
/*AERO2*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*AERO2*//*MT6218A*/  #define  DSP_SETPOINT  (49)
/*AERO2*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*AERO2*//*OTHERS*/   #define  DSP_SETPOINT  (49)
/*AERO2*/ #endif
/*AERO2*/ #define  SETPOINT_GAIN_OFFSET 0
/*AERO2*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_SKY74137
/*SKY74137*/ #ifdef AFC_13bit
/*SKY74137*/ #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*SKY74137*/ #else
/*SKY74137*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*SKY74137*/ #endif
/*SKY74137*/
/*SKY74137*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION/* single-end peak2peak:  1.12V <-> 5184 */
/*SKY74137*//*MT6218B~*/ #define  DSP_SETPOINT  (48)
/*SKY74137*/ #elif  IS_CHIP_MT6218A || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 6912 */
/*SKY74137*//*MT6218A*/  #define  DSP_SETPOINT  (50)
/*SKY74137*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*SKY74137*//*OTHERS*/   #define  DSP_SETPOINT  (45)
/*SKY74137*/ #endif
/*SKY74137*//* Note that setpoint and edge_setpoint cannot be nonzero simulataneously */
/*SKY74137*/ #define  SETPOINT_GAIN_OFFSET 0
/*SKY74137*/ #define  EDGE_SETPOINT_GAIN_OFFSET 5
#endif

#if IS_RF_GRF6201
/*GRF6201*/ #ifdef AFC_13bit
/*GRF6201*/ #define  C_PSI_STA      (1447)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=2.83    */
/*GRF6201*/ #else
/*GRF6201*/ #define  C_PSI_STA      (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*GRF6201*/ #endif
/*GRF6201*/
/*GRF6201*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*GRF6201*//*MT6218B~*/ #define  DSP_SETPOINT  (42)//(42)
/*GRF6201*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*GRF6201*//*MT6218A*/  #define  DSP_SETPOINT  (58)
/*GRF6201*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*GRF6201*//*OTHERS*/   #define  DSP_SETPOINT  (42)
/*GRF6201*/ #endif
/*GRF6201*/ #define  SETPOINT_GAIN_OFFSET       0
/*GRF6201*/ #define  EDGE_SETPOINT_GAIN_OFFSET  0
#endif

#if IS_RF_IRFS3001
/*IRFS3001*/ #ifdef AFC_13bit
/*IRFS3001*/ #define  C_PSI_STA     (422)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=9.7  */
/*IRFS3001*/ #else
/*IRFS3001*///#define  C_PSI_STA     (422)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*IRFS3001*/ #endif
/*IRFS3001*/
/*IRFS3001*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*IRFS3001*//*MT6218B~*/ #define  DSP_SETPOINT  (54)
/*IRFS3001*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*IRFS3001*//*MT6218A*/  #define  DSP_SETPOINT  (54)
/*IRFS3001*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*IRFS3001*//*OTHERS*/   #define  DSP_SETPOINT  (54)
/*IRFS3001*/ #endif
/*IRFS3001*/ #define  SETPOINT_GAIN_OFFSET      0
/*IRFS3001*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_AD6548
/*AD6548*/ #ifdef AFC_13bit
/*AD6548*/    #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G) /*VCXO*/
/*AD6548*/ #define  C_PSI_STA     (585)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=7    */
/*AD6548*/    #else                 /*VCTCXO*/
/*AD6548*/ #define  C_PSI_STA     (1365)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3    */
/*AD6548*/    #endif
/*AD6548*/ #else
/*AD6548*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*AD6548*/ #endif
/*AD6548*/
/*AD6548*/ #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION /* single-end peak2peak:  2.24V <-> 6912 */
/*AD6548*//*MT6229~*/  #define  DSP_SETPOINT  (39)//40
/*AD6548*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*AD6548*//*OTHERS*/   #define  DSP_SETPOINT  (39)//40
/*AD6548*/ #endif
/*AD6548*/ #define  SETPOINT_GAIN_OFFSET 0
/*AD6548*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_AD6546
/*AD6546*/ #ifdef AFC_13bit
/*AD6546*/    #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G) /*VCXO*/
/*AD6546*/ #define  C_PSI_STA     (417)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=7    */ 
/*AD6546*/    #else                 /*VCTCXO*/
/*AD6546*/ #define  C_PSI_STA     (1365) /* C_PSI_STA= sta^(-1)  * (2^12), sta=3    */
/*AD6546*/    #endif
/*AD6546*/ #else
/*AD6546*/ #define  C_PSI_STA     (146)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*AD6546*/ #endif
/*AD6546*/
/*AD6546*/ #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION /* single-end peak2peak:  2.24V <-> 6912 */
/*AD6546*//*MT6229~*/  #define  DSP_SETPOINT  (45)
/*AD6546*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*AD6546*//*OTHERS*/   #define  DSP_SETPOINT  (39)
/*AD6546*/ #endif
/*AD6546*/ #define  SETPOINT_GAIN_OFFSET 0
/*AD6546*/ #define  EDGE_SETPOINT_GAIN_OFFSET 5
#endif

#if IS_RF_MT6162
/*MT6162*/ #ifdef AFC_13bit
/*MT6162*/    #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G) /*VCXO*/
/*MT6162*/ #define  C_PSI_STA     (585)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=7      */
/*MT6162*/    #else                 /*VCTCXO*/
/*MT6162*/ #define  C_PSI_STA     (1339)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.059  */
/*MT6162*/    #endif
/*MT6162*/ #else
/*MT6162*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6162*/ #endif
/*MT6162*/ #define  DSP_SETPOINT             32
/*MT6162*/ #define  SETPOINT_GAIN_OFFSET      0
/*MT6162*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6163
/*MT6163*/ #ifdef AFC_13bit
/*MT6163*/ #define  C_PSI_STA     (594)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=6.9    */
/*MT6163*/ #else
/*MT6163*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6163*/ #endif
/*MT6163*/ #if IS_BBTXRX_CHIP_DESIGN_VER_3
/*MT6163*/ #define  DSP_SETPOINT             53
/*MT6163*/ #else
/*MT6163*/ #define  DSP_SETPOINT             32
/*MT6163*/ #endif
/*MT6163*/
/*MT6163*/ #define  SETPOINT_GAIN_OFFSET      0
/*MT6163*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6280RF
/*MT6280RF*/ #ifdef AFC_13bit
/*MT6280RF*/    #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G) /*VCXO*/
/*MT6280RF*/ #define  C_PSI_STA     (501)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=8.18  */
/*MT6280RF*/    #else
/*MT6280RF*/ #define  C_PSI_STA     (1325)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.091  */
/*MT6280RF*/    #endif
/*MT6280RF*/ #else
/*MT6280RF*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6280RF*/ #endif
/*MT6280RF*/ #define  DSP_SETPOINT  (62)    // Default setpoint for dynamic setpoint
/*MT6280RF*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6280RF*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6169
/*MT6169*/ #ifdef AFC_13bit
/*MT6169*/ #define  C_PSI_STA     (474)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=8.64   */
/*MT6169*/ #else
/*MT6169*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6169*/ #endif
/*MT6169*/ #define  DSP_SETPOINT  (62)    // Default setpoint for dynamic setpoint
/*MT6169*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6169*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6166
/*MT6166*/ #ifdef AFC_13bit
/*MT6166*/ #define  C_PSI_STA     (474)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=8.64   */
/*MT6166*/ #else
/*MT6166*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6166*/ #endif
/*MT6166*/ #define  DSP_SETPOINT  (62)    // Default setpoint for dynamic setpoint
/*MT6166*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6166*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6165
/*MT6165*/ #ifdef AFC_13bit
/*MT6165*/ #define  C_PSI_STA     (474)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=8.64   */
/*MT6165*/ #else
/*MT6165*/ #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6165*/ #endif
/*MT6165*/ #define  DSP_SETPOINT  (62)    // Default setpoint for dynamic setpoint
/*MT6165*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6165*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#ifndef GPRS_SETPOINT_GAIN_OFFSET
#define GPRS_SETPOINT_GAIN_OFFSET 0
#endif

#ifndef EDGE_SETPOINT_GAIN_OFFSET
#define EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#endif

