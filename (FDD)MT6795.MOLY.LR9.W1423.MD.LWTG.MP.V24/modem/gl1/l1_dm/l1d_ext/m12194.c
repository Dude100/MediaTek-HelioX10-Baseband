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
 * Filename:
 * ---------
 *   m12194.c
 *
 * Project:
 * --------
 *   MTK6208
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.37  $
 * $Modtime:   Jul 29 2005 13:47:12  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1/l1d/m12194.c-arc  $
 *
 * 10 02 2013 ola.lee
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * .
 *
 * 05 14 2013 ola.lee
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
 * 03 19 2013 ola.lee
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
 * Add IS_EGPRS compile option to maintain EGPRS code
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
 * Add RF driver of IRFS3001
 *
 * removed!
 * removed!
 * Modify the noise flow of SKY74137
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
 * Modify the L1 Compile option position
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
 *    Rev 1.37   Jul 29 2005 14:02:04   mtk00773
 * [L1D][Enhence] Support RF SKY74117
 * Resolution for 12111: [L1D][Enhence] Support RF SKY74117
 *
 *    Rev 1.36   Jul 08 2005 16:53:06   mtk00939
 * [L1D][Modify]L1D add code for MT6139C and META related code
 *
 *    Rev 1.35   May 17 2005 00:34:38   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.34   Feb 14 2005 20:52:42   mtk00939
 * [L1][update] fix RVCT compile warning
 * Resolution for 9821: [L1][update] fix RVCT compile warning
 *
 *    Rev 1.33   Jul 30 2004 17:37:08   mtk00240
 * L1D add code to support AERO1Plus RF chip
 * Resolution for 6925: [L1D][Enhance] L1D add code to support AERO1Plus RF chip
 *
 *    Rev 1.32   Jul 05 2004 15:52:12   mtk00773
 * Add RF POLARIS1 setting
 *
 *    Rev 1.31   May 21 2004 19:01:58   mtk00240
 * Add code to support MT6129D
 * Resolution for 5565: [L1D][Add Feature] Add code to support MT6129D
 *
 *    Rev 1.30   May 02 2004 21:22:52   mtk00240
 * Copy type definition in m12194.c to avoid including L1 private header files
 * Resolution for 5221: [L1D] Copy type definition in m12194.c to avoid including L1 private header files
 *
 *    Rev 1.29   Mar 15 2004 08:31:34   mtk00489
 * [L1D][Modified]L1D modify code to make compiler happy (include l1d_custom_rf.h)
 * Resolution for 4289: [L1D][Modified]L1D modify code to make compiler happy (include l1d_custom_rf.h)
 *
 *    Rev 1.28   Feb 13 2004 23:53:10   mtk00489
 * [L1D][Enhanced]1.adjust L1D DL DTX threshold to improve DTX detection rate 2.enhanced Dummy burst detection rate 3.change RX ADC to 2.24V for MT61xx 4.modify LP2 code to pass MT6218BECO3 validation 5.modify new interface for dll(CHIP_VER)
 * Resolution for 3912: [L1D][Enhanced]1.adjust L1D DL DTX threshold to improve DTX detection rate 2.enhanced Dummy burst detection rate 3.change RX ADC to 2.24V for MT61xx 4.modify LP2 code to pass MT6218BECO3 validation 5.modify new interface for dll(CHIP_VER)
 *
 *    Rev 1.27   Jan 27 2004 15:33:12   mtk00585
 * [L1D][Add] L1D Add code for MT6129C RF Driver.
 *
 *    Rev 1.26   Jan 12 2004 14:26:20   mtk00489
 * [L1D][Enhanced]L1D modify code to sync with FT load. 1.Delay 400QB of CTIRQ1/2 and DSP_GPRS_DFB_ON for mt6218A/B 2.separate CSD and GPRS's DSP_TCH_BFI_THRESHOLD 3.adjust set-point and gain table for Mt6119C
 * Resolution for 3714: [L1D][Enhanced]L1D modify code to sync with FT load. 1.Delay 400QB of CTIRQ1/2 and DSP_GPRS_DFB_ON for mt6218A/B 2.separate CSD and GPRS's DSP_TCH_BFI_THRESHOLD 3.adjust set-point and gain table for Mt6119C
 *
 *    Rev 1.25   Oct 25 2003 16:00:26   mtk00240
 * Add AGC definition for mt6218B
 * Resolution for 3196: [L1D][Enhance] Add code to support mt6218B
 *
 *    Rev 1.24   Oct 23 2003 19:58:58   mtk00585
 * [L1D][Add] L1D Add code for MT6129B RF Driver.
 * Resolution for 3177: [L1D][Add] L1D Add code for MT6129B RF Driver.
 *
 *    Rev 1.23   Oct 20 2003 10:20:54   mtk00240
 * L1D add setpoints for all RF on mt6218B and change F3's set-pount on mt6218
 * Resolution for 3147: [L1D][Enhance] L1D add setpoints for all RF on mt6218B and change F3's set-pount on mt6218
 *
 *    Rev 1.22   Oct 01 2003 15:58:44   mtk00585
 * [L1D][Modify]L1D modify code for MT6219
 * Resolution for 3037: [L1D][Modify]L1D modify code for MT6219
 *
 *    Rev 1.21   Jun 26 2003 15:22:18   mtk00240
 * L1D modify some code to support MT6218
 * Resolution for 2116: [L1D][Enhance] L1D modify some code to support MT6218
 *
 *    Rev 1.20   May 30 2003 10:17:40   mtk00248
 * Use ARM "pragma" directive to put global variables in internal ram.
 * Resolution for 1891: [L1C][Update] Put L1_MAC (m11305) and AGC (m11303) in internal RAM.
 *
 *    Rev 1.19   May 12 2003 14:56:22   mtk00489
 * [L1D][Enhanced]Avoid m12168.c to use customization file(m12193.h) a.move some code from m12193.h b.add one variable(onek_hz_dac)
 * Resolution for 1754: [L1D][Enhanced]Avoid m12168.c to use customization file(m12193.h) a.move some code from m12193.h b.add one variable(onek_hz_dac)
 *
 *    Rev 1.18   Apr 30 2003 20:41:08   mtk00489
 * [L1D][Enhanced]L1D fills chip specific registers to support MT6205B - a.RX_CON / AFC_CALIBIAS b.RXADC_NoiseFlow c.BBTX_GAIN
 * Resolution for 1693: [L1D][Enhanced]L1D fills chip specific registers to support MT6205B.
 *
 *    Rev 1.17   Feb 10 2003 17:23:34   mtk00489
 * L1D supports AMR and L1D_LP2 supports MT6218 cosim
 * Resolution for 639: L1D supports AMR and L1D_LP2 supports MT6218 cosim
 *
 *    Rev 1.16   Sep 06 2002 17:20:32   mtk00210
 * add new global variable for dynamic setpoint
 *
 *    Rev 1.15   27 Aug 2002 12:04:22   admin
 * change file header
 *
 *    Rev 1.14   26 Aug 2002 14:34:14   admin
 * remove modification notice
 * add copyright statement.
 *
 *    Rev 1.13   15 Aug 2002 17:49:22   mtk00361
 * Modify AGC parameter table to be suitable for different chips - FPGA, MT6208 or MT6205
 *
 *    Rev 1.12   Jul 05 2002 21:35:22   mtk00210
 * Revise the AFC dac and RX adc configuration
 *
 *    Rev 1.11   Jul 04 2002 00:22:40   mtk00210
 * Rearrange AGC definition table for different radio
 *
 *    Rev 1.10   29 Jun 2002 15:25:12   mtk00245
 * update files for label MT6208.W02.22.FTA.ALL.EXCEPT.14.1.1.1
 * Resolution for SCR 444
 *
 *    Rev 1.9   Apr 18 2002 20:05:34   mtk00210
 * reduce DSP setpoint for bright 4 plus radio
 *
 *    Rev 1.8   Apr 18 2002 11:55:12   mtk00210
 * Adjust AGC setpoint for bright 4 Plus
 *
 *    Rev 1.7   Apr 03 2002 19:42:04   mtk00210
 * (1) add DSP_MAGIC_VALUE used for L1C AGC and L1D power calculation
 * (2) revise AGC paramter table
 *
 *    Rev 1.6   Mar 06 2002 23:51:02   mtk00210
 * RSSI Compensation at low received condition
 *
 *    Rev 1.5   Jan 30 2002 14:40:04   mtk00210
 * make agcParams more flexible for different RSSI resolution bit
 *
 *    Rev 1.4   Jan 03 2002 15:10:00   mtk00210
 * modified the AGC paramter
 *
 *    Rev 1.3   Jan 03 2002 11:57:36   mtk00210
 * merge the branch B.L1.20011225
 *
 *    Rev 1.2.1.1   Dec 30 2001 01:06:42   mtk00210
 * revise the beta for AGC
 *
 *    Rev 1.2.1.0   Dec 25 2001 14:37:04   mtk00210
 * Update Layer 1 for high resolution RSSI, multiband AFC, new L1C/L1D interface for CSD
 *
 *    Rev 1.2   Dec 21 2001 12:40:08   admin
 * add copyright
 *
 *******************************************************************************/


#include "l1d_cid.h"
#include "m12190.h"
#include "m12193.h"
#include "l1d_custom_rf.h"
#include "l1d_rf.h"

/*...........................................................................*/
#if   (INTERNDATA_M12194==INTERN_FULL)
#define IS_INTERNDATA_LEVEL1     1
#else
#define IS_INTERNDATA_LEVEL1     0
#endif
/*...........................................................................*/

/*---------------------------------------------------------------------*/
/* remind: this is the type definition copy from another header file.  */
/*         If the type definition is changed in the original file,     */
/*         these copy shall be updated !!!                             */
/*---------------------------------------------------------------------*/
#ifndef  l1_generic_l1_const_h
#define RSSI_RESOLUTION_BITS     3 /* 0.125 dB resolution */
#define RSSI_FACTOR              (1<<RSSI_RESOLUTION_BITS)
#endif

#ifndef _MPH_TYPES_H
typedef  short  Power;
#endif

#ifndef l1_generic_l1_types_h
typedef  signed short int  int16;
typedef  signed int   intx;
typedef  short  Gain;
typedef struct
{
   Power defaultPower;
   Power bestPower;
   Power underflowPower;
   Power overflowPower;
   Gain  underflowReportPower;
   Gain  overflowReportPower;
} AGCParams;
#endif
/*---------------------------------------------------------------------*/

#if IS_FPGA_TARGET || IS_CHIP_MT6208
#define RXADC_NoiseFlow          8
#define RXADC_Saturation         3
#define RXADC_MAX_DBd            60
#endif

#if IS_CHIP_MT6205A
#define RXADC_NoiseFlow          8
#define RXADC_Saturation         0
#define RXADC_MAX_DBd            60
#endif

#if IS_CHIP_MT6205B
   #if IS_RF_BRIGHT2 || IS_RF_BRIGHT4 || IS_RF_AERO || IS_RF_AERO1PLUS || IS_RF_AERO2
#define RXADC_NoiseFlow          5
#define RXADC_Saturation         0
#define RXADC_MAX_DBd            60
   #endif
   #if IS_RF_MT6116 || IS_RF_MT6119 || IS_RF_MT6119C || IS_RF_MT6129A || IS_RF_MT6129B || IS_RF_MT6129C || IS_RF_MT6129D
#define RXADC_NoiseFlow          15
#define RXADC_Saturation         3
#define RXADC_MAX_DBd            60
   #endif

   #if IS_RF_POLARIS1      /* RFMD: temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation         3
#define RXADC_MAX_DBd            60
   #endif
   #if IS_RF_SKY74117      /* SKY74117: temporary parameter */
#define RXADC_NoiseFlow          5
#define RXADC_Saturation         0
#define RXADC_MAX_DBd            60
   #endif
   #if IS_RF_SKY74400      /* SKY74400: temporary parameter */
#define RXADC_NoiseFlow          5
#define RXADC_Saturation         0
#define RXADC_MAX_DBd            60
   #endif
   #if IS_RF_MT6139B       /* temporary parameter */
#define RXADC_NoiseFlow          0
#define RXADC_Saturation         0
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_MT6139C       /* temporary parameter */
#define RXADC_NoiseFlow          0
#define RXADC_Saturation         0
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_MT6139E       /* temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation         0
#define RXADC_MAX_DBd            60
   #endif
   #if IS_RF_SKY74045      /* SKY74045: temporary parameter */
#define RXADC_NoiseFlow          23
#define RXADC_Saturation         0
#define RXADC_MAX_DBd            60
   #endif
   #if IS_RF_SKY74137      /* SKY74137: temporary parameter */
#define RXADC_NoiseFlow          20
#define RXADC_Saturation         0
#define RXADC_MAX_DBd            60
   #endif
   #if IS_RF_GRF6201       /* temporary parameter */
#define RXADC_NoiseFlow          0
#define RXADC_Saturation         0
#define RXADC_MAX_DBd            60
   #endif
   #if IS_RF_MT6140C       /* temporary parameter */
#define RXADC_NoiseFlow          0
#define RXADC_Saturation         0
#define RXADC_MAX_DBd            60
   #endif
   #if IS_RF_MT6140D       /* temporary parameter, not verify*/
#define RXADC_NoiseFlow          15
#define RXADC_Saturation         0
#define RXADC_MAX_DBd            60
   #endif
   #if IS_RF_CMOSEDGE      /* temporary parameter, not verify*/
#define RXADC_NoiseFlow          15
#define RXADC_Saturation         0
#define RXADC_MAX_DBd            60
  #endif
#endif

#if IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
   #if IS_RF_MT6140D
      #if IS_BBTXRX_CHIP_DESIGN_VER_2
#define RXADC_NoiseFlow          16
#define RXADC_Saturation          3
#define RXADC_MAX_DBd            79
      #else
#define RXADC_NoiseFlow          13
#define RXADC_Saturation          3
#define RXADC_MAX_DBd            76
      #endif
   #endif
   #if IS_RF_CMOSEDGE      /* temporary parameter */
#define RXADC_NoiseFlow          13
#define RXADC_Saturation          3
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6139E
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          0  /* measured with MT6223*/
#define RXADC_MAX_DBd            76  /* measured with MT6223*/
   #endif
   #if IS_RF_AERO2
#define RXADC_NoiseFlow          12
#define RXADC_Saturation          2
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_SKY74137
#define RXADC_NoiseFlow          20
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MTKSOC1T
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          5
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_MTKSOC1
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          5
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_MT6252RF
#define RXADC_NoiseFlow          15  
#define RXADC_Saturation          5  
#define RXADC_MAX_DBd            74  
   #endif                            
   #if IS_RF_MT6256RF
      #if IS_CHIP_MT6256_S00
#define RXADC_NoiseFlow          24
#define RXADC_Saturation          9
#define RXADC_MAX_DBd           100  //MAX COUNT=108864
      #else
#define RXADC_NoiseFlow          22
#define RXADC_Saturation          9
#define RXADC_MAX_DBd           100  //MAX COUNT=108864
      #endif
   #endif
   #if IS_RF_MT6255RF
#define RXADC_NoiseFlow          22
#define RXADC_Saturation          9
#define RXADC_MAX_DBd           100  //MAX COUNT=108864
   #endif
   #if IS_RF_MT6251RF
#define RXADC_NoiseFlow          25
#define RXADC_Saturation          9
#define RXADC_MAX_DBd           100  //MAX COUNT=108864
   #endif
   #if IS_RF_AD6548        /* temporary parameter */
#define RXADC_NoiseFlow           4
#define RXADC_Saturation          2
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_AD6546        /* temporary parameter */
#define RXADC_NoiseFlow          10
#define RXADC_Saturation          3
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_SKY74045
#define RXADC_NoiseFlow          23
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6162              /* temporary setting */
#define RXADC_NoiseFlow           0
#define RXADC_Saturation          1
#define RXADC_MAX_DBd            79
   #endif
   #if IS_RF_MT6163
      #if IS_BBTXRX_CHIP_DESIGN_VER_3
#define RXADC_NoiseFlow          22
#define RXADC_Saturation         10
#define RXADC_MAX_DBd           101
      #else
#define RXADC_NoiseFlow           0
#define RXADC_Saturation          1
#define RXADC_MAX_DBd            79
      #endif
   #endif
   #if IS_RF_MT6280RF
#define RXADC_NoiseFlow          16
#define RXADC_Saturation          8
#define RXADC_MAX_DBd            99
   #endif
   #if IS_RF_MT6169
#define RXADC_NoiseFlow          14
#define RXADC_Saturation          8
#define RXADC_MAX_DBd            99
   #endif
   #if IS_RF_MT6166
#define RXADC_NoiseFlow          16
#define RXADC_Saturation          9
#define RXADC_MAX_DBd            99
   #endif
   #if IS_RF_MT6165
#define RXADC_NoiseFlow          16
#define RXADC_Saturation          9
#define RXADC_MAX_DBd            99
   #endif   
#elif IS_CHIP_MT6218A || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_RF_BRIGHT2 || IS_RF_BRIGHT4 || IS_RF_AERO || IS_RF_AERO1PLUS
#define RXADC_NoiseFlow          5
#define RXADC_Saturation         6
#define RXADC_MAX_DBd            78
   #endif
   #if IS_RF_MT6116 || IS_RF_MT6119 || IS_RF_MT6119C || IS_RF_MT6129A || IS_RF_MT6129B || IS_RF_MT6129C || IS_RF_MT6129D
#define RXADC_NoiseFlow          31
#define RXADC_Saturation         3
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_POLARIS1      /* RFMD: temporary parameter */
#define RXADC_NoiseFlow          31
#define RXADC_Saturation         3
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_SKY74117      /* SKY74117: temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          2
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_SKY74400      /* SKY74400: temporary parameter */
#define RXADC_NoiseFlow          12
#define RXADC_Saturation          2
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6139B       /* temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6140A       /* temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6140B       /* temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6140C       /* temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6140D
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_CMOSEDGE
#define RXADC_NoiseFlow          10
#define RXADC_Saturation          2
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MTKSOC1T      /* temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          5
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_MT6139C
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6139E
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          0  /* measured with MT6223*/
#define RXADC_MAX_DBd            76  /* measured with MT6223*/
   #endif
   #if IS_RF_SKY74045
#define RXADC_NoiseFlow          23
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_AERO2
#define RXADC_NoiseFlow          12
#define RXADC_Saturation          2
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_SKY74137
#define RXADC_NoiseFlow          20
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_GRF6201
#define RXADC_NoiseFlow           5
#define RXADC_Saturation          4
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_AD6548
#define RXADC_NoiseFlow           4
#define RXADC_Saturation          2
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_AD6546
#define RXADC_NoiseFlow          10
#define RXADC_Saturation          3
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6162              /* temporary setting */
#define RXADC_NoiseFlow           0
#define RXADC_Saturation          1
#define RXADC_MAX_DBd            79
   #endif
   #if IS_RF_MT6163              /* temporary setting */
#define RXADC_NoiseFlow           0
#define RXADC_Saturation          1
#define RXADC_MAX_DBd            79
   #endif
#endif

#if IS_CHIP_MT6225_AND_LATTER_VERSION
   #if IS_RF_BRIGHT2 || IS_RF_BRIGHT4 || IS_RF_AERO || IS_RF_AERO1PLUS
#define RXADC_NoiseFlow           8
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6116 || IS_RF_MT6119 || IS_RF_MT6119C || IS_RF_MT6129A || IS_RF_MT6129B || IS_RF_MT6129C || IS_RF_MT6129D
#define RXADC_NoiseFlow          29
#define RXADC_Saturation          3
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_POLARIS1      /* RFMD: temporary parameter */
#define RXADC_NoiseFlow           0
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_SKY74117      /* SKY74117: temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_SKY74400      /* SKY74400: temporary parameter */
#define RXADC_NoiseFlow          12
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6139B       /* temporary parameter */
#define RXADC_NoiseFlow           0
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6139C       /* temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          5
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6139E
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6140A       /* temporary parameter */
#define RXADC_NoiseFlow           0
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6140B       /* temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          5
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6140C       /* temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          5
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MT6140D
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          5
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_CMOSEDGE      /* temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          5
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_MTKSOC1T      /* temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          5
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_SKY74045      /* SKY74045: temporary parameter */
#define RXADC_NoiseFlow          23//20
#define RXADC_Saturation          1
#define RXADC_MAX_DBd            76//75
   #endif
    #if IS_RF_BRIGHT5P
#define RXADC_NoiseFlow           0
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            78
   #endif
   #if IS_RF_AERO2
#define RXADC_NoiseFlow          12
#define RXADC_Saturation          2
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_SKY74137
#define RXADC_NoiseFlow          20
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_GRF6201
#define RXADC_NoiseFlow           5
#define RXADC_Saturation          4
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_AD6548        /* temporary parameter */
#define RXADC_NoiseFlow           4
#define RXADC_Saturation          2
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_AD6546        /* temporary parameter */
#define RXADC_NoiseFlow          10
#define RXADC_Saturation          3
#define RXADC_MAX_DBd            76
   #endif
#elif IS_CHIP_MT6218B_AND_LATTER_VERSION
   #if IS_RF_BRIGHT2 || IS_RF_BRIGHT4 || IS_RF_AERO || IS_RF_AERO1PLUS
#define RXADC_NoiseFlow           8
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_MT6116 || IS_RF_MT6119 || IS_RF_MT6119C || IS_RF_MT6129A || IS_RF_MT6129B || IS_RF_MT6129C || IS_RF_MT6129D
#define RXADC_NoiseFlow          29
#define RXADC_Saturation          3
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_POLARIS1      /* RFMD: temporary parameter */
#define RXADC_NoiseFlow           0
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_SKY74117      /* SKY74117: temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_SKY74400      /* SKY74400: temporary parameter */
#define RXADC_NoiseFlow          12
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_MT6139B       /* temporary parameter */
#define RXADC_NoiseFlow           0
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_MT6139C       /* temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          5
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_MT6139E
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_MT6140A       /* temporary parameter */
#define RXADC_NoiseFlow           0
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_MT6140B       /* temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          5
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_MT6140C       /* */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          5
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_MT6140D       /* temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          5
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_CMOSEDGE      /* temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          5
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_MTKSOC1T      /* temporary parameter */
#define RXADC_NoiseFlow          15
#define RXADC_Saturation          5
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_SKY74045      /* SKY74045: temporary parameter */
#define RXADC_NoiseFlow          23 //20
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            74 //75
   #endif
   #if IS_RF_BRIGHT5P
#define RXADC_NoiseFlow           0
#define RXADC_Saturation          0
#define RXADC_MAX_DBd            78
   #endif
   #if IS_RF_AERO2
#define RXADC_NoiseFlow          12
#define RXADC_Saturation          2
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_SKY74137
#define RXADC_NoiseFlow           0
#define RXADC_Saturation          0
#define RXADC_MAX_DBd           100
   #endif
   #if IS_RF_GRF6201
#define RXADC_NoiseFlow           5
#define RXADC_Saturation          4
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_IRFS3001
#define RXADC_NoiseFlow          27
#define RXADC_Saturation          6
#define RXADC_MAX_DBd            74
   #endif
   #if IS_RF_AD6548
#define RXADC_NoiseFlow           4
#define RXADC_Saturation          2
#define RXADC_MAX_DBd            76
   #endif
   #if IS_RF_AD6546        /* AD6546: temporary parameter */
#define RXADC_NoiseFlow          10
#define RXADC_Saturation          3
#define RXADC_MAX_DBd            74
   #endif
#endif

#define PM_MAGIC_VALUE           ( (short)(DSP_MAGIC_VALUE*RSSI_FACTOR) )
#define PM_SETPOINT              ( PM_MAGIC_VALUE + DSP_SETPOINT * RSSI_FACTOR )
#define PM_UnderFlow             ( PM_MAGIC_VALUE + RXADC_NoiseFlow * RSSI_FACTOR )
#define PM_OverFlow              ( PM_MAGIC_VALUE + (RXADC_MAX_DBd-RXADC_Saturation) * RSSI_FACTOR )
#define PM_UnderFlowReport       ( PM_UnderFlow - PM_OverFlow + PM_SETPOINT )
#define PM_OverFlowReport        ( PM_OverFlow + PM_SETPOINT - PM_UnderFlow )

/*...........................................................................*/
#if defined(__MTK_TARGET__) && defined(__ARMCC_VERSION)
#if IS_INTERNDATA_LEVEL1
#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#else
#pragma arm section rwdata , rodata , zidata
#endif
#endif /* __MTK_TARGET__ */
/*...........................................................................*/

const AGCParams agcParams[ FrequencyBandCount ] =
{/*          default,        best,        under,        over,        underReport,        overReport */
   { -76*RSSI_FACTOR, PM_SETPOINT, PM_UnderFlow, PM_OverFlow, PM_UnderFlowReport, PM_OverFlowReport }, /* FrequencyBand400  */
   { -76*RSSI_FACTOR, PM_SETPOINT, PM_UnderFlow, PM_OverFlow, PM_UnderFlowReport, PM_OverFlowReport }, /* FrequencyBand850  */
   { -76*RSSI_FACTOR, PM_SETPOINT, PM_UnderFlow, PM_OverFlow, PM_UnderFlowReport, PM_OverFlowReport }, /* FrequencyBand900  */
   { -76*RSSI_FACTOR, PM_SETPOINT, PM_UnderFlow, PM_OverFlow, PM_UnderFlowReport, PM_OverFlowReport }, /* FrequencyBand1800 */
   { -76*RSSI_FACTOR, PM_SETPOINT, PM_UnderFlow, PM_OverFlow, PM_UnderFlowReport, PM_OverFlowReport }, /* FrequencyBand1900 */
};

#if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
const unsigned short RXADC_NoiseFlow_mul_64 = RXADC_NoiseFlow * 64;  /* Noise floor(dBd)*64 */
#endif

intx  afc_inv_slope   = C_PSI_STA;
int16 afc_dac_default = PSI_EE;
int16 onek_hz_dac     = (int16)((1200*C_PSI_STA)/0x1000);

#ifdef IS_TDD_DUAL_MODE_SUPPORT
int16 GSM_afc_inv_slope   = C_PSI_STA; 
intx  GSM_afc_dac_default = PSI_EE;
#endif

#if IS_32K_CRYSTAL_REMOVAL_SUPPORT || IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
intx  afc_Phi_est         = C_PSI_STA;
int16 locked_DacValue     = PSI_EE;
int16 current_DacValue    = PSI_EE;
int16 afc_dac_default_ori = PSI_EE;
#endif

Power agc_gainoffset_h2l  = SETPOINT_GAIN_OFFSET * RSSI_FACTOR;
Power agc_gprs_gainoffset = GPRS_SETPOINT_GAIN_OFFSET * RSSI_FACTOR;
#if IS_EGPRS
Power agc_edge_gainoffset = EDGE_SETPOINT_GAIN_OFFSET * RSSI_FACTOR;
#endif

/*...........................................................................*/
#if defined(__MTK_TARGET__) && defined(__ARMCC_VERSION)
#pragma arm section rwdata , rodata , zidata
#endif /* __MTK_TARGET__ */
/*...........................................................................*/

#if IS_VCXO_LC_SUPPORT
XO_SLOPE_AREA_DATA  XO_SlopeAreaData_ori[ XO_SlopeArea_Num ];
#endif

const XO_SLOPE_AREA_DATA  XO_SlopeAreaData_RO[ XO_SlopeArea_Num ] =
//For MT6253T 33 sections calibration
#if IS_VCXO_LC_SUPPORT
{  // 2 sections with 1 Slopes
   {  20635,    0      },/*Lower Bound*/
   {  18440, 1296      },
   {  17211, 1944      },
   {  15827, 2591      },
   {  15377, 2791      },
   {  14891, 2991      },
   {  14387, 3191      },
   {  13859, 3391      },
   {  13316, 3591      },
   {  12740, 3791      },
   {  12138, 3991      },
   {  11511, 4191      },
   {  10845, 4391      },
   {  10165, 4591      },
   {   9430, 4791      },
   {   8663, 4991      },
   {   7841, 5191      },
   {   6971, 5391      },
   {   6040, 5591      },
   {   5022, 5791      },
   {   3907, 5991      },
   {   2642, 6191      },
   {   1211, 6391      },
   { -  413, 6591      },
   { - 2211, 6791      },
   { - 4165, 6991      },
   { - 6274, 7191      },
   { - 8539, 7391      },
   { -10958, 7591      },
   { -13536, 7791      },
   { -16291, 7991      },
   { -19209, 8191      }, /*Upper Bound*/
   {      0, TABLE_END },
};
#else
{  // 2 sections with 1 Slopes
   {  (PSI_EE*0x1000)/C_PSI_STA,    0      }, /*Low Bound*/
   { (-PSI_EE*0x1000)/C_PSI_STA, 8191      }, /*Upper Bound*/
   {                          0, TABLE_END },
};
#endif

XO_SLOPE_AREA_DATA  XO_SlopeAreaData[ XO_SlopeArea_Num ];

void L1I_SetAFcData( int16 calibrated_dac_default, intx calibrated_int_slope )
{
#if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
   //Since we don't have fixafc_en status when 1st update AFC Data,
   //use calibrated_int_slope == 0 as a index of fixafc_en is already get from NVRAM
   if( calibrated_int_slope == 0 )
   {
      if( RFSpecialCoef.rx.fixafc.fixafc_en && !L1D_CheckIfMetaMode() )
      {  
         l1d_rf.AFC_data        = afc_dac_default;
         calibrated_dac_default = afc_dac_default;
         calibrated_int_slope   = DLAFC_INV_SLOPE;
   #if IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2
        l1d_rf_custom_input_data.RF_Others_Variable.xafc_inv_slope = calibrated_int_slope;
   #endif      
      }
      else
      {  
         return; 
      }
   }
#endif

#if IS_VCXO_LC_SUPPORT
   if( L1D_CheckIfMetaMode() )
   {
      afc_inv_slope   = calibrated_int_slope;
      afc_dac_default = calibrated_dac_default;
      onek_hz_dac     = (int16)((1200*calibrated_int_slope)/0x1000);
   }
#else
   afc_inv_slope   = calibrated_int_slope;
   afc_dac_default = calibrated_dac_default;
   onek_hz_dac     = (int16)((1200*calibrated_int_slope)/0x1000);

   #ifdef  __UMTS_RAT__
   {  unsigned char i;
      extern void L1T_AFCInit( unsigned char simIndex );

      for( i=0; i<NUM_OF_SIM; i++ )
      {  L1T_AFCInit( i ); }
   }
   #endif
#endif

#ifdef IS_TDD_DUAL_MODE_SUPPORT
   GSM_afc_inv_slope   = afc_inv_slope;
   GSM_afc_dac_default = afc_dac_default;
#endif

#if IS_32K_CRYSTAL_REMOVAL_SUPPORT || IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
   afc_Phi_est         = calibrated_int_slope;
   locked_DacValue     = calibrated_dac_default;
   current_DacValue    = calibrated_dac_default;
   afc_dac_default_ori = calibrated_dac_default;
#endif
}
/*---------------------------------------------------------------------------*/

