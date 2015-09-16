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
 *   m12192.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Setup Gain
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.49  $
 * $Modtime:   Jul 29 2005 13:45:34  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1/l1d/m12192.c-arc  $
 *
 * removed!
 * removed!
 * 	.
 *
 * 10 02 2013 ola.lee
 * removed!
 * 	.
 *
 * removed!
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
 * 07 02 2012 ola.lee
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
 * 12 02 2011 th.yeh
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
 * Modify the SKY74137 driver that we do not use short mode on the interslot
 *
 * removed!
 * removed!
 * < Triple850>  
 * RF chip gets GSM900 signal from GSm850 input pins  to avoid getting GSM900 signal
 *
 * removed!
 * removed!
 * Add code to support GSM850 signal received through GSM900 path
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
 * 
 *
 * removed!
 * removed!
 * Modify the SKY74137 gain table
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
 *    Rev 1.49   Jul 29 2005 14:01:38   mtk00773
 * [L1D][Enhence] Support RF SKY74117
 * Resolution for 12111: [L1D][Enhence] Support RF SKY74117
 * 
 *    Rev 1.48   Jul 08 2005 16:53:04   mtk00939
 * [L1D][Modify]L1D add code for MT6139C and META related code
 * 
 *    Rev 1.47   May 17 2005 00:34:38   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 * 
 *    Rev 1.46   May 16 2005 11:46:24   mtk00240
 * Support 22 BPI setting & current sense PA
 * Resolution for 11091: [L1D][New Feature] Support 22 BPI setting & current sense PA
 * 
 *    Rev 1.45   Jan 18 2005 00:38:08   BM
 * append new line in W05.04
 * 
 *    Rev 1.44   Jan 10 2005 12:18:52   mtk00939
 * Do some modify for MT6129D driver to support GSM850
 * Resolution for 9426: [L1D][modify] modified for MT6129D driver to support GSM850
 * 
 *    Rev 1.43   Jan 10 2005 10:38:16   mtk00939
 * Do some modify for MT6129D driver to support GSM850
 * Resolution for 9426: [L1D][modify] modified for MT6129D driver to support GSM850
 * 
 *    Rev 1.42   Oct 01 2004 21:25:36   mtk00703
 * use const declaration on AGC_TABLE to lower cost of GSM project.
 * Resolution for 7997: [L1D][Modify]Reduce RAM Size for LOW cost GSM project
 * 
 *    Rev 1.41   Sep 16 2004 15:56:30   mtk00773
 * To clear warning message
 * Resolution for 7712: [L1D][Modify] Modify POLARIS1 setting
 * 
 *    Rev 1.40   Aug 19 2004 15:31:04   mtk00240
 * Update Aero1Plus latest setting
 * Resolution for 6925: [L1D][Enhance] L1D add code to support AERO1Plus RF chip
 * 
 *    Rev 1.39   Jul 30 2004 17:37:06   mtk00240
 * L1D add code to support AERO1Plus RF chip
 * Resolution for 6925: [L1D][Enhance] L1D add code to support AERO1Plus RF chip
 *
 *    Rev 1.38   Jul 05 2004 15:50:40   mtk00773
 * Add RF POLARIS1 setting
 *
 *    Rev 1.37   May 21 2004 19:01:58   mtk00240
 * Add code to support MT6129D
 * Resolution for 5565: [L1D][Add Feature] Add code to support MT6129D
 *
 *    Rev 1.36   Jan 27 2004 15:33:12   mtk00585
 * [L1D][Add] L1D Add code for MT6129C RF Driver.
 *
 *    Rev 1.35   Jan 12 2004 14:26:20   mtk00489
 * [L1D][Enhanced]L1D modify code to sync with FT load. 1.Delay 400QB of CTIRQ1/2 and DSP_GPRS_DFB_ON for mt6218A/B 2.separate CSD and GPRS's DSP_TCH_BFI_THRESHOLD 3.adjust set-point and gain table for Mt6119C
 * Resolution for 3714: [L1D][Enhanced]L1D modify code to sync with FT load. 1.Delay 400QB of CTIRQ1/2 and DSP_GPRS_DFB_ON for mt6218A/B 2.separate CSD and GPRS's DSP_TCH_BFI_THRESHOLD 3.adjust set-point and gain table for Mt6119C
 *
 *    Rev 1.34   Oct 23 2003 14:22:18   mtk00585
 * [L1D][Add] L1D Add code for MT6129B RF Driver.
 * Resolution for 3177: [L1D][Add] L1D Add code for MT6129B RF Driver.
 *
 *    Rev 1.33   Jul 11 2003 17:41:30   mtk00489
 * [L1D][Enhanced]L1D supports MT6129A
 * Resolution for 2241: [L1D][Enhanced]L1D supports MT6129A
 *
 *    Rev 1.32   May 16 2003 13:09:24   mtk00489
 * [L1D][New Feature]L1D supports MT6119C
 * Resolution for 1794: [L1D][New Feature]L1D supports MT6119C
 *
 *    Rev 1.31   May 12 2003 21:36:54   mtk00489
 * [L1D][Enhanced]L1D modify L1D_RecordHwRegisters() / m12192.c(aero) / l1d_reg.h to make compiler happy.
 * Resolution for 1770: [L1D][Enhanced]L1D modify L1D_RecordHwRegisters() / m12192.c(aero) / l1d_reg.h to make compiler happy.
 *
 *    Rev 1.30   Apr 11 2003 16:44:16   mtk00489
 * [L1D][FixBug] L1D adjust SR2(from 40 to 100) for MT6119 by SA's request. In order to lower the ring of I/Q when channel filter switching
 * Resolution for 1522: [L1D][FixBug] L1D adjust SR2(from 40 to 100) for MT6119 by SA's request. In order to lower the ring of I/Q when channel filter switching
 *
 *    Rev 1.29   Apr 11 2003 16:43:30   mtk00489
 * [L1D][FixBug] L1D fix bug about gain setting small than ¡V11dBm(Aero), DSP will measure very high power even there is no input.
 * Resolution for 1521: [L1D][FixBug] L1D fix bug about gain setting small than ¡V11dBm(Aero), DSP will measure very high power even there is no input.
 *
 *    Rev 1.28   06 Jan 2003 16:43:40   mtk00240
 * type of agcptr shall be declared to const.
 * Resolution for 617: L1D fix the compile error in MAUI project when using AERO option
 *
 *    Rev 1.27   Jan 03 2003 16:26:22   mtk00474
 * MT6119 modifies PGA setting time and LNA gain boundary
 * Resolution for 615: MT6119 gain setting modify
 *
 *    Rev 1.25   16 Nov 2002 08:54:02   mtk00240
 * L1D add code to support AERO gain setting in GPRS mode
 * Resolution for 562: L1D add code to support AERO gain setting in GPRS mode
 *
 *    Rev 1.24   11 Sep 2002 12:05:48   mtk00240
 * (1) modified some MT6119 constant suggestted by SA
 * (2) modified some AERO constant suggestted by SA
 * Resolution for 439: L1D add code to support MT6119 RF Module
 * Resolution for 464:  L1D add code to support AERO RF Module
 *
 *    Rev 1.23   27 Aug 2002 12:04:22   admin
 * change file header
 *
 *    Rev 1.22   26 Aug 2002 14:34:14   admin
 * remove modification notice
 * add copyright statement.
 *
 *    Rev 1.21   24 Aug 2002 14:10:46   mtk00240
 *  L1D add code to support AERO RF Module
 * Resolution for 464:  L1D add code to support AERO RF Module
 *
 *    Rev 1.20   22 Aug 2002 10:37:00   mtk00240
 * Using macro to define the constants for evaluating gain setting.
 * Resolution for 455: L1D modified m12192.c to eavluate gain setting more easily
 *
 *    Rev 1.19   15 Aug 2002 08:28:00   mtk00240
 * L1D fix the minimum Gain of BRIGHT4
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.18   23 Jul 2002 15:49:12   mtk00240
 * L1D add code to support MT6119 RF Module
 * Resolution for 439: L1D add code to support MT6119 RF Module
 *
 *    Rev 1.17   03 Jul 2002 21:43:48   mtk00240
 * L1D extrract RF setting code to let customer setup new RF module more easily
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.16   08 May 2002 22:19:30   mtk00240
 * L1D add functions to support RF Test Tool
 * Resolution for 387: L1D add functions to support RF Test Tool
 *
 *    Rev 1.15   01 May 2002 22:45:58   mtk00240
 * Extract GSM code from L1D
 * Resolution for 384: Extract GSM code from L1D
 *
 *    Rev 1.14   23 Apr 2002 14:40:34   mtk00240
 * L1D integrate all RF calibration data into m12193.c
 *
 *    Rev 1.13   12 Apr 2002 21:27:10   mtk00240
 * L1D add new initialized value for RF
 * Resolution for 359: L1D add new initialized value for RF
 *
 *    Rev 1.12   03 Apr 2002 19:30:32   mtk00240
 * Fix some code to support Bright4 properly
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 *
 *    Rev 1.11   01 Apr 2002 12:24:14   mtk00240
 * L1D modified register's definition for DSP main v10
 * Resolution for 347: L1D modified register's definition for DSP F/W main v10
 *
 *    Rev 1.10   30 Mar 2002 13:04:16   mtk00240
 * 1) Modify L1D code to support both Bright2 & Bright4 RF board
 * 2) L1D add Audio interface to support Voice Memo & Melody
 * 3) Add L1D code to support RAM-based chip
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 * Resolution for 342: L1D add Audio interface to support Voice Memo & Melody
 * Resolution for 343: Add L1D code to support RAM-based chip
 *
 *    Rev 1.9   11 Mar 2002 19:46:58   mtk00240
 * Remove unused variables
 * Resolution for 310: L1D changed the gain setting methode
 *
 *    Rev 1.7   11 Mar 2002 13:36:24   mtk00240
 * instead TAB characters of Space characters in L1D code .
 * Resolution for 318: Shine change TAB character to Space charter
 *
 *    Rev 1.6   06 Mar 2002 19:28:18   mtk00240
 * L1D reset TSC value while CC reset
 * Resolution for 310: L1D changed the gain setting methode
 *
 *    Rev 1.5   17 Feb 2002 20:15:42   mtk00240
 * Update L1D code for solving HandOver test item
 * Resolution for 275: Update L1D code for solving HandOver test item
 *
 *    Rev 1.4   30 Jan 2002 13:12:48   mtk00240
 * support changing resolution by defined constance
 * Resolution for 253: RSSI resolution
 *
 *    Rev 1.3   03 Jan 2002 12:19:50   mtk00240
 * Merge B.L1.20011225 to Main V1.XX
 *
 *    Rev 1.2.1.0   Dec 25 2001 14:32:58   mtk00210
 * Update for High resolution RSSI, multiband AFC,
 * update L1C/L1D interface for CSD
 *
 *    Rev 1.1   Dec 10 2001 16:43:56   mtk00240
 * Add copyright header of MediaTek
 *
 *******************************************************************************/


/*===============================================================================*/
/*                                                                               */
/* int L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain,          */
/*                            long *gain_setting )                               */
/*                                                                               */
/*===============================================================================*/
/*                                                                               */
/* rf_band      : RF Band. the value is 0 (GSM) or 1 (DCS)                       */
/* arfcn        : ARFCN number                                                   */
/* request_gain : Request Gain. the unit is 0.125 dBm                            */
/* *gain_setting: the Setting Value for tranceiver gain.                         */
/* return       : returned Actually Setting Gain. the unit is 0.125 dBm.         */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/* This program evaluates the AGC setting value by the request gain for Bright2. */
/* If the AGC component is changed, this file shall be modified by vendor        */
/*                                                                               */
/* ----------------------------------------------------------------------------- */

#include "l1d_cid.h"
#include "m12190.h"

/*================================================================================================*/

#define  ROUNDINT( n )                    ((int)(((n)>=0)?((n)+0.5):((n)-0.5)))
#define  GC_B                             ((GAIN_STEP)*(PWRRES))
#define  GC_A( bitno, gain  )             (short)ROUNDINT(((1+2*(bitno))*GC_B/2-(gain)*(PWRRES)))
#define  GBOUND( gain1, gain2 )           (short)ROUNDINT((((gain1)+(gain2))/2.0*(PWRRES)))
#define  BIT_NO( reqgain, A, B )          (((reqgain)+(A))/(B))
#define  REAL_GAIN( bitno, A, B )         ((bitno)*(B)-(A)+(B)/2)

/*================================================================================================*/

#if IS_RF_BRIGHT2
/*BRIGHT2*/
/*BRIGHT2*/ #define  GAIN_STEP               2
/*BRIGHT2*/
/*BRIGHT2*/ #define  RF_GSM_MAXGAIN         ((114.0-37.6)*(PWRRES))
/*BRIGHT2*/ #define  RF_GSM_MINGAIN         (( 14.0-37.6)*(PWRRES))
/*BRIGHT2*/ #define  RF_DCS_MAXGAIN         ((114.0-36.6)*(PWRRES))
/*BRIGHT2*/ #define  RF_DCS_MINGAIN         (( 14.0-36.6)*(PWRRES))
/*BRIGHT2*/ #define  RF_PCS_MAXGAIN         ((114.0-36.6)*(PWRRES))
/*BRIGHT2*/ #define  RF_PCS_MINGAIN         (( 14.0-36.6)*(PWRRES))
/*BRIGHT2*/
/*BRIGHT2*/ /* GSM900....................................................................*/
/*BRIGHT2*/
/*BRIGHT2*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[3] =
/*BRIGHT2*/ {  {  GBOUND( 20.4, 18.4 ), GC_A( 20, 20.4 ), 0x00 },
/*BRIGHT2*/    {  GBOUND(  8.4,  6.4 ), GC_A( 20,  8.4 ), 0x80 },
/*BRIGHT2*/    {  GBOUND(-23.6,-23.6 ), GC_A( 12,-23.6 ), 0xC0 },
/*BRIGHT2*/ };
/*BRIGHT2*/
/*BRIGHT2*/ /* DCS1800...................................................................*/
/*BRIGHT2*/
/*BRIGHT2*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[3] =
/*BRIGHT2*/ {  {  GBOUND( 21.4, 19.4 ), GC_A( 21, 21.4 ), 0x00 },
/*BRIGHT2*/    {  GBOUND(  9.4,  7.4 ), GC_A( 21,  9.4 ), 0x80 },
/*BRIGHT2*/    {  GBOUND(-22.6,-22.6 ), GC_A( 13,-22.6 ), 0xC0 },
/*BRIGHT2*/ };
/*BRIGHT2*/
/*BRIGHT2*/ /* PCS1900...................................................................*/
/*BRIGHT2*/
/*BRIGHT2*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[3] =
/*BRIGHT2*/ {  {  GBOUND( 21.4, 19.4 ), GC_A( 21, 21.4 ), 0x00 },
/*BRIGHT2*/    {  GBOUND(  9.4,  7.4 ), GC_A( 21,  9.4 ), 0x80 },
/*BRIGHT2*/    {  GBOUND(-22.6,-22.6 ), GC_A( 13,-22.6 ), 0xC0 },
/*BRIGHT2*/ };
/*BRIGHT2*/
/*BRIGHT2*/ /*...........................................................................*/
/*BRIGHT2*/
/*BRIGHT2*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*BRIGHT2*/ {  {                   0,                   0 },   /*#FrequencyBand400  */
/*BRIGHT2*/    {                   0,                   0 },   /*#FrequencyBand850  */
/*BRIGHT2*/    { (int)RF_GSM_MAXGAIN, (int)RF_GSM_MINGAIN },   /* FrequencyBand900  */
/*BRIGHT2*/    { (int)RF_DCS_MAXGAIN, (int)RF_DCS_MINGAIN },   /* FrequencyBand1800 */
/*BRIGHT2*/    { (int)RF_PCS_MAXGAIN, (int)RF_PCS_MINGAIN },   /* FrequencyBand1900 */
/*BRIGHT2*/ };
/*BRIGHT2*/
/*BRIGHT2*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*BRIGHT2*/ {  0,                                              /*#FrequencyBand400  */
/*BRIGHT2*/    0,                                              /*#FrequencyBand850  */
/*BRIGHT2*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*BRIGHT2*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*BRIGHT2*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*BRIGHT2*/ };
/*BRIGHT2*/
/*BRIGHT2*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*BRIGHT2*/
/*BRIGHT2*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*BRIGHT2*/ {  int   max_gain, min_gain, real_gain;
/*BRIGHT2*/    const int*    d32ptr;
/*BRIGHT2*/    const sL1DAGCDATA*  agcptr;
/*BRIGHT2*/    long  setting;
/*BRIGHT2*/    int   bit_no;
/*BRIGHT2*/
/*BRIGHT2*/    /* evaluate the range of available gain */
/*BRIGHT2*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*BRIGHT2*/    max_gain = *d32ptr++;
/*BRIGHT2*/    min_gain = *d32ptr;
/*BRIGHT2*/
/*BRIGHT2*/    /* clipping the request gain to the avialable gain */
/*BRIGHT2*/    if( request_gain>=max_gain )
/*BRIGHT2*/    {  request_gain = max_gain;  }
/*BRIGHT2*/    else  if( request_gain<=min_gain )
/*BRIGHT2*/    {  request_gain = min_gain;  }
/*BRIGHT2*/
/*BRIGHT2*/    /* evaluate the real gain setting */
/*BRIGHT2*/    agcptr = AGC_TABLE[rf_band];
/*BRIGHT2*/    if( request_gain <= agcptr->pos_gain )
/*BRIGHT2*/    {  agcptr++;
/*BRIGHT2*/       if( request_gain <= agcptr->pos_gain )
/*BRIGHT2*/       {  agcptr++;  }
/*BRIGHT2*/    }
/*BRIGHT2*/    {  bit_no    = BIT_NO( request_gain, (agcptr->A-1), GC_B );
/*BRIGHT2*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*BRIGHT2*/       setting   = agcptr->setting + bit_no;
/*BRIGHT2*/    }
/*BRIGHT2*/
/*BRIGHT2*/    *gain_setting = setting;
/*BRIGHT2*/    return( real_gain );
/*BRIGHT2*/ }
/*BRIGHT2*/
#endif

#if IS_RF_BRIGHT4
/*BRIGHT4*/
/*BRIGHT4*/ #define  GAIN_STEP               2
/*BRIGHT4*/
/*BRIGHT4*/ #define  RF_GSM_MAXGAIN         (( 58.5)*(PWRRES))
/*BRIGHT4*/ #define  RF_GSM_MINGAIN         ((-39.0)*(PWRRES))
/*BRIGHT4*/ #define  RF_DCS_MAXGAIN         (( 53.5)*(PWRRES))
/*BRIGHT4*/ #define  RF_DCS_MINGAIN         ((-43.0)*(PWRRES))
/*BRIGHT4*/ #define  RF_PCS_MAXGAIN         (( 53.5)*(PWRRES))
/*BRIGHT4*/ #define  RF_PCS_MINGAIN         ((-43.0)*(PWRRES))
/*BRIGHT4*/
/*BRIGHT4*/ /* GSM900....................................................................*/
/*BRIGHT4*/
/*BRIGHT4*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*BRIGHT4*/ {  {  GBOUND(-11.5,-13.0 ), GC_A( 10,-11.5 ), 0x2002 },
/*BRIGHT4*/    {  GBOUND(-39.0,-39.0 ), GC_A( 13,-39.0 ), 0x2202 },
/*BRIGHT4*/ };
/*BRIGHT4*/
/*BRIGHT4*/ /* DCS1800...................................................................*/
/*BRIGHT4*/
/*BRIGHT4*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*BRIGHT4*/ {  {  GBOUND(-16.5,-17.0 ), GC_A( 10,-16.5 ), 0x2002 },
/*BRIGHT4*/    {  GBOUND(-43.0,-43.0 ), GC_A(  9,-43.0 ), 0x2202 },
/*BRIGHT4*/ };
/*BRIGHT4*/
/*BRIGHT4*/ /* PCS1900...................................................................*/
/*BRIGHT4*/
/*BRIGHT4*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*BRIGHT4*/ {  {  GBOUND(-16.5,-17.0 ), GC_A( 10,-16.5 ), 0x2002 },
/*BRIGHT4*/    {  GBOUND(-43.0,-43.0 ), GC_A(  9,-43.0 ), 0x2202 },
/*BRIGHT4*/ };
/*BRIGHT4*/
/*BRIGHT4*/ /*...........................................................................*/
/*BRIGHT4*/
/*BRIGHT4*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*BRIGHT4*/ {  {                   0,                   0 },   /*#FrequencyBand400  */
/*BRIGHT4*/    {                   0,                   0 },   /*#FrequencyBand850  */
/*BRIGHT4*/    { (int)RF_GSM_MAXGAIN, (int)RF_GSM_MINGAIN },   /* FrequencyBand900  */
/*BRIGHT4*/    { (int)RF_DCS_MAXGAIN, (int)RF_DCS_MINGAIN },   /* FrequencyBand1800 */
/*BRIGHT4*/    { (int)RF_PCS_MAXGAIN, (int)RF_PCS_MINGAIN },   /* FrequencyBand1900 */
/*BRIGHT4*/ };
/*BRIGHT4*/
/*BRIGHT4*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*BRIGHT4*/ {  0,                                              /*#FrequencyBand400  */
/*BRIGHT4*/    0,                                              /*#FrequencyBand850  */
/*BRIGHT4*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*BRIGHT4*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*BRIGHT4*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*BRIGHT4*/ };
/*BRIGHT4*/
/*BRIGHT4*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*BRIGHT4*/
/*BRIGHT4*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*BRIGHT4*/ {  int   max_gain, min_gain, real_gain;
/*BRIGHT4*/    const int*    d32ptr;
/*BRIGHT4*/    const sL1DAGCDATA*  agcptr;
/*BRIGHT4*/    long  setting;
/*BRIGHT4*/    int   bit_no;
/*BRIGHT4*/
/*BRIGHT4*/    /* evaluate the range of available gain */
/*BRIGHT4*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*BRIGHT4*/    max_gain = *d32ptr++;
/*BRIGHT4*/    min_gain = *d32ptr;
/*BRIGHT4*/
/*BRIGHT4*/    /* clipping the request gain to the avialable gain */
/*BRIGHT4*/    if( request_gain>=max_gain )
/*BRIGHT4*/    {  request_gain = max_gain;  }
/*BRIGHT4*/    else  if( request_gain<=min_gain )
/*BRIGHT4*/    {  request_gain = min_gain;  }
/*BRIGHT4*/
/*BRIGHT4*/    /* evaluate the real gain setting */
/*BRIGHT4*/    agcptr = AGC_TABLE[rf_band];
/*BRIGHT4*/    if( request_gain < agcptr->pos_gain )
/*BRIGHT4*/    {  agcptr++;
/*BRIGHT4*/    }
/*BRIGHT4*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*BRIGHT4*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*BRIGHT4*/       setting   = agcptr->setting + (bit_no<<3);
/*BRIGHT4*/    }
/*BRIGHT4*/
/*BRIGHT4*/    *gain_setting = setting;
/*BRIGHT4*/    return( real_gain );
/*BRIGHT4*/ }
/*BRIGHT4*/
#endif

#if IS_RF_BRIGHT5P
/*BRIGHT5P*/
/*BRIGHT5P*/ #define  GAIN_STEP               2
/*BRIGHT5P*/
/*BRIGHT5P*/ #define  RF_GSM850_MAXGAIN         (( 64.5)*(PWRRES))
/*BRIGHT5P*/ #define  RF_GSM850_MINGAIN         ((-11.5)*(PWRRES))
/*BRIGHT5P*/ #define  RF_GSM_MAXGAIN            (( 64.5)*(PWRRES))
/*BRIGHT5P*/ #define  RF_GSM_MINGAIN            ((-11.5)*(PWRRES))
/*BRIGHT5P*/ #define  RF_DCS_MAXGAIN            (( 63.5)*(PWRRES))
/*BRIGHT5P*/ #define  RF_DCS_MINGAIN            ((-12.5)*(PWRRES))
/*BRIGHT5P*/ #define  RF_PCS_MAXGAIN            (( 63.5)*(PWRRES))
/*BRIGHT5P*/ #define  RF_PCS_MINGAIN            ((-12.5)*(PWRRES))
/*BRIGHT5P*/
/*BRIGHT5P*/ /* GSM850....................................................................*/
/*BRIGHT5P*/
/*BRIGHT5P*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[1] =
/*BRIGHT5P*/ {  {  GBOUND(-11.5,-11.5 ), GC_A( 7,-11.5 ), 0x0002 },
/*BRIGHT5P*/ };
/*BRIGHT5P*/
/*BRIGHT5P*/ /* GSM900....................................................................*/
/*BRIGHT5P*/
/*BRIGHT5P*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[1] =
/*BRIGHT5P*/ {  {  GBOUND(-11.5,-11.5 ), GC_A( 7,-11.5 ), 0x0002 },
/*BRIGHT5P*/ };
/*BRIGHT5P*/
/*BRIGHT5P*/ /* DCS1800...................................................................*/
/*BRIGHT5P*/
/*BRIGHT5P*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[1] =
/*BRIGHT5P*/ {  {  GBOUND(-12.5,-12.5 ), GC_A( 7,-12.5 ), 0x0002 },
/*BRIGHT5P*/ };
/*BRIGHT5P*/
/*BRIGHT5P*/ /* PCS1900...................................................................*/
/*BRIGHT5P*/
/*BRIGHT5P*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*BRIGHT5P*/ {  {  GBOUND(-12.5,-12.5 ), GC_A( 7,-12.5 ), 0x0002 },
/*BRIGHT5P*/ };
/*BRIGHT5P*/
/*BRIGHT5P*/ /*...........................................................................*/
/*BRIGHT5P*/
/*BRIGHT5P*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*BRIGHT5P*/ {  {                      0,                   0    },   /*#FrequencyBand400  */
/*BRIGHT5P*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN },   /* FrequencyBand850  */
/*BRIGHT5P*/    { (int)RF_GSM_MAXGAIN   , (int)RF_GSM_MINGAIN    },   /* FrequencyBand900  */
/*BRIGHT5P*/    { (int)RF_DCS_MAXGAIN   , (int)RF_DCS_MINGAIN    },   /* FrequencyBand1800 */
/*BRIGHT5P*/    { (int)RF_PCS_MAXGAIN   , (int)RF_PCS_MINGAIN    },   /* FrequencyBand1900 */
/*BRIGHT5P*/ };
/*BRIGHT5P*/
/*BRIGHT5P*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*BRIGHT5P*/ {  0,                                              /*#FrequencyBand400  */
/*BRIGHT5P*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*BRIGHT5P*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*BRIGHT5P*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*BRIGHT5P*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*BRIGHT5P*/ };
/*BRIGHT5P*/
/*BRIGHT5P*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*BRIGHT5P*/
/*BRIGHT5P*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*BRIGHT5P*/ {  int   max_gain, min_gain, real_gain;
/*BRIGHT5P*/    const int*    d32ptr;
/*BRIGHT5P*/    const sL1DAGCDATA*  agcptr;
/*BRIGHT5P*/    long  setting;
/*BRIGHT5P*/    int   bit_no;
/*BRIGHT5P*/
/*BRIGHT5P*/    /* evaluate the range of available gain */
/*BRIGHT5P*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*BRIGHT5P*/    max_gain = *d32ptr++;
/*BRIGHT5P*/    min_gain = *d32ptr;
/*BRIGHT5P*/
/*BRIGHT5P*/    /* clipping the request gain to the avialable gain */
/*BRIGHT5P*/    if( request_gain>=max_gain )
/*BRIGHT5P*/    {  request_gain = max_gain;  }
/*BRIGHT5P*/    else  if( request_gain<=min_gain )
/*BRIGHT5P*/    {  request_gain = min_gain;  }
/*BRIGHT5P*/
/*BRIGHT5P*/    /* evaluate the real gain setting */
/*BRIGHT5P*/    agcptr = AGC_TABLE[rf_band];
/*BRIGHT5P*/
/*BRIGHT5P*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*BRIGHT5P*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*BRIGHT5P*/       setting   = agcptr->setting + (bit_no<<3);
/*BRIGHT5P*/    }
/*BRIGHT5P*/
/*BRIGHT5P*/    *gain_setting = setting;
/*BRIGHT5P*/    return( real_gain );
/*BRIGHT5P*/ }
/*BRIGHT5P*/
#endif

#if IS_RF_AERO
/*AERO*/
/*AERO*/ #define  GAIN_STEP               1
/*AERO*/
/*AERO*/ #if IS_GPRS
/*AERO*/ #define  RF_GSM_MAXGAIN         (( 56+13)*(PWRRES))
/*AERO*/ #define  RF_GSM_MINGAIN         ((-23+13)*(PWRRES))
/*AERO*/ #define  RF_DCS_MAXGAIN         (( 56+13)*(PWRRES))
/*AERO*/ #define  RF_DCS_MINGAIN         ((-23+13)*(PWRRES))
/*AERO*/ #define  RF_PCS_MAXGAIN         (( 56+13)*(PWRRES))
/*AERO*/ #define  RF_PCS_MINGAIN         ((-23+13)*(PWRRES))
/*AERO*/ #else
/*AERO*/ #define  RF_GSM_MAXGAIN         (( 56+13)*(PWRRES))
/*AERO*/ #define  RF_GSM_MINGAIN         ((-38+13)*(PWRRES))
/*AERO*/ #define  RF_DCS_MAXGAIN         (( 56+13)*(PWRRES))
/*AERO*/ #define  RF_DCS_MINGAIN         ((-38+13)*(PWRRES))
/*AERO*/ #define  RF_PCS_MAXGAIN         (( 56+13)*(PWRRES))
/*AERO*/ #define  RF_PCS_MINGAIN         ((-38+13)*(PWRRES))
/*AERO*/ #endif
/*AERO*/
/*AERO*/ #if IS_GPRS
/*AERO*/ /* GSM900....................................................................*/
/*AERO*/
/*AERO*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[6] =
/*AERO*/ {
/*AERO*/    {  GBOUND( 56.0+13.0,  -7.0+13.0)-(2*PWRRES), GC_A(43,  36+13.0), 0x758021 },
/*AERO*/    {  GBOUND( 52.0+13.0, -11.0+13.0)-(2*PWRRES), GC_A(43,  32+13.0), 0x756021 },
/*AERO*/    {  GBOUND( 48.0+13.0, -15.0+13.0)-(2*PWRRES), GC_A(43,  28+13.0), 0x754021 },
/*AERO*/    {  GBOUND( 44.0+13.0, -19.0+13.0)-(2*PWRRES), GC_A(43,  24+13.0), 0x752021 },
/*AERO*/    {  GBOUND( 40.0+13.0, -23.0+13.0)-(2*PWRRES), GC_A( 0, -23+13.0), 0x750021 },
/*AERO*/ };
/*AERO*/
/*AERO*/ /* DCS1800...................................................................*/
/*AERO*/
/*AERO*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[6] =
/*AERO*/ {
/*AERO*/    {  GBOUND( 56.0+8.0,  -7.0+13.0)-(2*PWRRES), GC_A(43,  36+13.0), 0x358021 },
/*AERO*/    {  GBOUND( 52.0+8.0, -11.0+13.0)-(2*PWRRES), GC_A(43,  32+13.0), 0x356021 },
/*AERO*/    {  GBOUND( 48.0+8.0, -15.0+13.0)-(2*PWRRES), GC_A(43,  28+13.0), 0x354021 },
/*AERO*/    {  GBOUND( 44.0+8.0, -19.0+13.0)-(2*PWRRES), GC_A(43,  24+13.0), 0x352021 },
/*AERO*/    {  GBOUND( 40.0+8.0, -23.0+13.0)-(2*PWRRES), GC_A( 0, -23+13.0), 0x350021 },
/*AERO*/ };
/*AERO*/
/*AERO*/ /* PCS1900...................................................................*/
/*AERO*/
/*AERO*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[6] =
/*AERO*/ {
/*AERO*/    {  GBOUND( 56.0,  -7.0)-(2*PWRRES), GC_A(43,  36), 0x358021 },
/*AERO*/    {  GBOUND( 52.0, -11.0)-(2*PWRRES), GC_A(43,  32), 0x356021 },
/*AERO*/    {  GBOUND( 48.0, -15.0)-(2*PWRRES), GC_A(43,  28), 0x354021 },
/*AERO*/    {  GBOUND( 44.0, -19.0)-(2*PWRRES), GC_A(43,  24), 0x352021 },
/*AERO*/    {  GBOUND( 40.0, -23.0)-(2*PWRRES), GC_A( 0, -23), 0x350021 },
/*AERO*/ };
/*AERO*/
/*AERO*/ #else
/*AERO*/ /* GSM900....................................................................*/
/*AERO*/
/*AERO*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[6] =
/*AERO*/ {
/*AERO*/    {  GBOUND( 36.0+13.0,  35.0+13.0), GC_A(43,  36+13.0), 0x758021 },
/*AERO*/    {  GBOUND( 32.0+13.0,  31.0+13.0), GC_A(43,  32+13.0), 0x756021 },
/*AERO*/    {  GBOUND( 28.0+13.0,  27.0+13.0), GC_A(43,  28+13.0), 0x754021 },
/*AERO*/    {  GBOUND( 24.0+13.0,  23.0+13.0), GC_A(43,  24+13.0), 0x752021 },
/*AERO*/    {  GBOUND(-23.0+13.0, -24.0+13.0), GC_A( 0, -23+13.0), 0x750021 },
/*AERO*/    {  GBOUND(-38.0+13.0, -38.0+13.0), GC_A( 0, -38+13.0), 0x700021 },
/*AERO*/ };
/*AERO*/
/*AERO*/ /* DCS1800...................................................................*/
/*AERO*/
/*AERO*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[6] =
/*AERO*/ {
/*AERO*/    {  GBOUND( 36.0+13.0,  35.0+13.0), GC_A(43,  36+13.0), 0x358021 },
/*AERO*/    {  GBOUND( 32.0+13.0,  31.0+13.0), GC_A(43,  32+13.0), 0x356021 },
/*AERO*/    {  GBOUND( 28.0+13.0,  27.0+13.0), GC_A(43,  28+13.0), 0x354021 },
/*AERO*/    {  GBOUND( 24.0+13.0,  23.0+13.0), GC_A(43,  24+13.0), 0x352021 },
/*AERO*/    {  GBOUND(-23.0+13.0, -24.0+13.0), GC_A( 0, -23+13.0), 0x350021 },
/*AERO*/    {  GBOUND(-38.0+13.0, -38.0+13.0), GC_A( 0, -38+13.0), 0x300021 },
/*AERO*/ };
/*AERO*/
/*AERO*/ /* PCS1900...................................................................*/
/*AERO*/
/*AERO*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[6] =
/*AERO*/ {
/*AERO*/    {  GBOUND( 36.0+13.0,  35.0+13.0), GC_A(43,  36+13.0), 0x358021 },
/*AERO*/    {  GBOUND( 32.0+13.0,  31.0+13.0), GC_A(43,  32+13.0), 0x356021 },
/*AERO*/    {  GBOUND( 28.0+13.0,  27.0+13.0), GC_A(43,  28+13.0), 0x354021 },
/*AERO*/    {  GBOUND( 24.0+13.0,  23.0+13.0), GC_A(43,  24+13.0), 0x352021 },
/*AERO*/    {  GBOUND(-23.0+13.0, -24.0+13.0), GC_A( 0, -23+13.0), 0x350021 },
/*AERO*/    {  GBOUND(-38.0+13.0, -38.0+13.0), GC_A( 0, -38+13.0), 0x300021 },
/*AERO*/ };
/*AERO*/
/*AERO*/ #endif
/*AERO*/ //*...........................................................................*/
/*AERO*/
/*AERO*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*AERO*/ {  {                   0,                   0 },   /*#FrequencyBand400  */
/*AERO*/    {                   0,                   0 },   /*#FrequencyBand850  */
/*AERO*/    { (int)RF_GSM_MAXGAIN, (int)RF_GSM_MINGAIN },   /* FrequencyBand900  */
/*AERO*/    { (int)RF_DCS_MAXGAIN, (int)RF_DCS_MINGAIN },   /* FrequencyBand1800 */
/*AERO*/    { (int)RF_PCS_MAXGAIN, (int)RF_PCS_MINGAIN },   /* FrequencyBand1900 */
/*AERO*/ };
/*AERO*/
/*AERO*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*AERO*/ {  0,                                              /*#FrequencyBand400  */
/*AERO*/    0,                                              /*#FrequencyBand850  */
/*AERO*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*AERO*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*AERO*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*AERO*/ };
/*AERO*/
/*AERO*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*AERO*/
/*AERO*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*AERO*/ {  int   max_gain, min_gain, real_gain;
/*AERO*/    const int*    d32ptr;
/*AERO*/    const sL1DAGCDATA*  agcptr;
/*AERO*/    long  setting;
/*AERO*/    int   bit_no;
/*AERO*/
/*AERO*/ #if IS_GPRS
/*AERO*/    const static sL1DAGCDATA*  last_agcptr;
/*AERO*/ #endif
/*AERO*/
/*AERO*/    /* evaluate the range of available gain */
/*AERO*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*AERO*/    max_gain = *d32ptr++;
/*AERO*/    min_gain = *d32ptr;
/*AERO*/
/*AERO*/    /* clipping the request gain to the avialable gain */
/*AERO*/    if( request_gain>=max_gain )
/*AERO*/    {  request_gain = max_gain;  }
/*AERO*/    else  if( request_gain<=min_gain )
/*AERO*/    {  request_gain = min_gain;  }
/*AERO*/ #if IS_GPRS
/*AERO*/    if(!IS_CONTINUOUS_RX_SLOT()) /*false: evaluate the real gain setting */
/*AERO*/    {
/*AERO*/ #endif
/*AERO*/       agcptr = AGC_TABLE[rf_band];
/*AERO*/       agcptr += 2;
/*AERO*/       if( request_gain >= agcptr->pos_gain )
/*AERO*/       {  agcptr -= 2;
/*AERO*/          if( request_gain < agcptr->pos_gain )
/*AERO*/          {  agcptr += 1;
/*AERO*/             if(request_gain < agcptr->pos_gain )
/*AERO*/             {  agcptr += 1;
/*AERO*/             }
/*AERO*/          }
/*AERO*/       }
/*AERO*/       else
/*AERO*/       {  agcptr += 1;
/*AERO*/          if( request_gain < agcptr->pos_gain )
/*AERO*/          {  agcptr += 1;
/*AERO*/ #if IS_GSM
/*AERO*/             if(request_gain < agcptr->pos_gain )
/*AERO*/             {  agcptr += 1;
/*AERO*/             }
/*AERO*/ #endif
/*AERO*/          }
/*AERO*/       }
/*AERO*/       {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*AERO*/          real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*AERO*/          setting   = agcptr->setting + (bit_no<<6);
/*AERO*/       }
/*AERO*/ #if IS_GPRS
/*AERO*/       last_agcptr = agcptr;
/*AERO*/    }
/*AERO*/    else /* is_continuous_slot */
/*AERO*/    {  bit_no    = BIT_NO( request_gain, last_agcptr->A, GC_B );
/*AERO*/       real_gain = REAL_GAIN( bit_no, last_agcptr->A, GC_B );
/*AERO*/       setting   = (bit_no<<6)|0x22;
/*AERO*/    }
/*AERO*/ #endif
/*AERO*/    *gain_setting = setting;
/*AERO*/    return( real_gain );
/*AERO*/ }
/*AERO*/
#endif

#if IS_RF_AERO1PLUS
/*AERO1+*/
/*AERO1+*/ #define  GAIN_STEP               1
/*AERO1+*/ #define  PVOFS                   (-25.0)
/*AERO1+*/
/*AERO1+*/ #if IS_GPRS
/*AERO1+*/ #define  RF_GSM_MAXGAIN         (( 85)*(PWRRES))
/*AERO1+*/ #define  RF_GSM_MINGAIN         (( -2)*(PWRRES))
/*AERO1+*/ #define  RF_DCS_MAXGAIN         (( 83)*(PWRRES))
/*AERO1+*/ #define  RF_DCS_MINGAIN         ((  5)*(PWRRES))
/*AERO1+*/ #define  RF_PCS_MAXGAIN         (( 83)*(PWRRES))
/*AERO1+*/ #define  RF_PCS_MINGAIN         ((  5)*(PWRRES))
/*AERO1+*/ #else
/*AERO1+*/ #define  RF_GSM_MAXGAIN         (( 85)*(PWRRES))
/*AERO1+*/ #define  RF_GSM_MINGAIN         (( -2)*(PWRRES))
/*AERO1+*/ #define  RF_DCS_MAXGAIN         (( 83)*(PWRRES))
/*AERO1+*/ #define  RF_DCS_MINGAIN         ((  5)*(PWRRES))
/*AERO1+*/ #define  RF_PCS_MAXGAIN         (( 83)*(PWRRES))
/*AERO1+*/ #define  RF_PCS_MINGAIN         ((  5)*(PWRRES))
/*AERO1+*/ #endif
/*AERO1+*/
/*AERO1+*/ #if IS_GPRS
/*AERO1+*/ /* GSM900....................................................................*/
/*AERO1+*/
/*AERO1+*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[6] =
/*AERO1+*/ {
/*AERO1+*/    {  GBOUND( 93.0+PVOFS, 30.0+PVOFS)-(2*PWRRES), GC_A(37,  67.0+PVOFS), 0x758021 },
/*AERO1+*/    {  GBOUND( 89.0+PVOFS, 26.0+PVOFS)-(2*PWRRES), GC_A(37,  63.0+PVOFS), 0x756021 },
/*AERO1+*/    {  GBOUND( 85.0+PVOFS, 22.0+PVOFS)-(2*PWRRES), GC_A(37,  59.0+PVOFS), 0x754021 },
/*AERO1+*/    {  GBOUND( 81.0+PVOFS, 18.0+PVOFS)-(2*PWRRES), GC_A(37,  55.0+PVOFS), 0x752021 },
/*AERO1+*/    {  GBOUND( 77.0+PVOFS, 14.0+PVOFS)-(2*PWRRES), GC_A( 0,  14.0+PVOFS), 0x750021 },
/*AERO1+*/ };
/*AERO1+*/
/*AERO1+*/ /* DCS1800...................................................................*/
/*AERO1+*/
/*AERO1+*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[6] =
/*AERO1+*/ {
/*AERO1+*/    {  GBOUND( 91.0+PVOFS, 28.0+PVOFS)-(2*PWRRES), GC_A(37,  65.0+PVOFS), 0x358021 },
/*AERO1+*/    {  GBOUND( 87.0+PVOFS, 24.0+PVOFS)-(2*PWRRES), GC_A(37,  61.0+PVOFS), 0x356021 },
/*AERO1+*/    {  GBOUND( 83.0+PVOFS, 20.0+PVOFS)-(2*PWRRES), GC_A(37,  57.0+PVOFS), 0x354021 },
/*AERO1+*/    {  GBOUND( 79.0+PVOFS, 16.0+PVOFS)-(2*PWRRES), GC_A(37,  53.0+PVOFS), 0x352021 },
/*AERO1+*/    {  GBOUND( 75.0+PVOFS, 12.0+PVOFS)-(2*PWRRES), GC_A( 0,  12.0+PVOFS), 0x350021 },
/*AERO1+*/ };
/*AERO1+*/
/*AERO1+*/ /* PCS1900...................................................................*/
/*AERO1+*/
/*AERO1+*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[6] =
/*AERO1+*/ {
/*AERO1+*/    {  GBOUND( 91.0+PVOFS, 28.0+PVOFS)-(2*PWRRES), GC_A(37,  65.0+PVOFS), 0x358021 },
/*AERO1+*/    {  GBOUND( 87.0+PVOFS, 24.0+PVOFS)-(2*PWRRES), GC_A(37,  61.0+PVOFS), 0x356021 },
/*AERO1+*/    {  GBOUND( 83.0+PVOFS, 20.0+PVOFS)-(2*PWRRES), GC_A(37,  57.0+PVOFS), 0x354021 },
/*AERO1+*/    {  GBOUND( 79.0+PVOFS, 16.0+PVOFS)-(2*PWRRES), GC_A(37,  53.0+PVOFS), 0x352021 },
/*AERO1+*/    {  GBOUND( 75.0+PVOFS, 12.0+PVOFS)-(2*PWRRES), GC_A( 0,  12.0+PVOFS), 0x350021 },
/*AERO1+*/ };
/*AERO1+*/
/*AERO1+*/ #else
/*AERO1+*/ /* GSM900....................................................................*/
/*AERO1+*/
/*AERO1+*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[6] =
/*AERO1+*/ {
/*AERO1+*/    {  GBOUND( 67.0+PVOFS,  66.0+PVOFS), GC_A(37,  67.0+PVOFS), 0x758021 },
/*AERO1+*/    {  GBOUND( 63.0+PVOFS,  62.0+PVOFS), GC_A(37,  63.0+PVOFS), 0x756021 },
/*AERO1+*/    {  GBOUND( 59.0+PVOFS,  58.0+PVOFS), GC_A(37,  59.0+PVOFS), 0x754021 },
/*AERO1+*/    {  GBOUND( 55.0+PVOFS,  54.0+PVOFS), GC_A(37,  55.0+PVOFS), 0x752021 },
/*AERO1+*/    {  GBOUND( 14.0+PVOFS,  13.0+PVOFS), GC_A( 0,  14.0+PVOFS), 0x750021 },
/*AERO1+*/    {  GBOUND( -2.0+PVOFS,  -2.0+PVOFS), GC_A( 0,  -2.0+PVOFS), 0x700021 },
/*AERO1+*/ };
/*AERO1+*/
/*AERO1+*/ /* DCS1800...................................................................*/
/*AERO1+*/
/*AERO1+*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[6] =
/*AERO1+*/ {
/*AERO1+*/    {  GBOUND( 65.0+PVOFS,  64.0+PVOFS), GC_A(37,  65.0+PVOFS), 0x358021 },
/*AERO1+*/    {  GBOUND( 61.0+PVOFS,  60.0+PVOFS), GC_A(37,  61.0+PVOFS), 0x356021 },
/*AERO1+*/    {  GBOUND( 57.0+PVOFS,  56.0+PVOFS), GC_A(37,  57.0+PVOFS), 0x354021 },
/*AERO1+*/    {  GBOUND( 53.0+PVOFS,  52.0+PVOFS), GC_A(37,  53.0+PVOFS), 0x352021 },
/*AERO1+*/    {  GBOUND( 12.0+PVOFS,  11.0+PVOFS), GC_A( 0,  12.0+PVOFS), 0x350021 },
/*AERO1+*/    {  GBOUND(  5.0+PVOFS,   5.0+PVOFS), GC_A( 0,   5.0+PVOFS), 0x300021 },
/*AERO1+*/ };
/*AERO1+*/
/*AERO1+*/ /* PCS1900...................................................................*/
/*AERO1+*/
/*AERO1+*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[6] =
/*AERO1+*/ {
/*AERO1+*/    {  GBOUND( 65.0+PVOFS,  64.0+PVOFS), GC_A(37,  65.0+PVOFS), 0x358021 },
/*AERO1+*/    {  GBOUND( 61.0+PVOFS,  60.0+PVOFS), GC_A(37,  61.0+PVOFS), 0x356021 },
/*AERO1+*/    {  GBOUND( 57.0+PVOFS,  56.0+PVOFS), GC_A(37,  57.0+PVOFS), 0x354021 },
/*AERO1+*/    {  GBOUND( 53.0+PVOFS,  52.0+PVOFS), GC_A(37,  53.0+PVOFS), 0x352021 },
/*AERO1+*/    {  GBOUND( 12.0+PVOFS,  11.0+PVOFS), GC_A( 0,  12.0+PVOFS), 0x350021 },
/*AERO1+*/    {  GBOUND(  5.0+PVOFS,   5.0+PVOFS), GC_A( 0,   5.0+PVOFS), 0x300021 },
/*AERO1+*/ };
/*AERO1+*/
/*AERO1+*/ #endif
/*AERO1+*/ //*...........................................................................*/
/*AERO1+*/
/*AERO1+*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*AERO1+*/ {  {                   0,                   0 },   /*#FrequencyBand400  */
/*AERO1+*/    {                   0,                   0 },   /*#FrequencyBand850  */
/*AERO1+*/    { (int)RF_GSM_MAXGAIN, (int)RF_GSM_MINGAIN },   /* FrequencyBand900  */
/*AERO1+*/    { (int)RF_DCS_MAXGAIN, (int)RF_DCS_MINGAIN },   /* FrequencyBand1800 */
/*AERO1+*/    { (int)RF_PCS_MAXGAIN, (int)RF_PCS_MINGAIN },   /* FrequencyBand1900 */
/*AERO1+*/ };
/*AERO1+*/
/*AERO1+*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*AERO1+*/ {  0,                                              /*#FrequencyBand400  */
/*AERO1+*/    0,                                              /*#FrequencyBand850  */
/*AERO1+*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*AERO1+*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*AERO1+*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*AERO1+*/ };
/*AERO1+*/
/*AERO1+*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*AERO1+*/
/*AERO1+*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*AERO1+*/ {  int   max_gain, min_gain, real_gain;
/*AERO1+*/    const int*    d32ptr;
/*AERO1+*/    const sL1DAGCDATA*  agcptr;
/*AERO1+*/    long  setting;
/*AERO1+*/    int   bit_no;
/*AERO1+*/
/*AERO1+*/ #if IS_GPRS
/*AERO1+*/    const static sL1DAGCDATA*  last_agcptr;
/*AERO1+*/ #endif
/*AERO1+*/
/*AERO1+*/    /* evaluate the range of available gain */
/*AERO1+*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*AERO1+*/    max_gain = *d32ptr++;
/*AERO1+*/    min_gain = *d32ptr;
/*AERO1+*/
/*AERO1+*/    /* clipping the request gain to the avialable gain */
/*AERO1+*/    if( request_gain>=max_gain )
/*AERO1+*/    {  request_gain = max_gain;  }
/*AERO1+*/    else  if( request_gain<=min_gain )
/*AERO1+*/    {  request_gain = min_gain;  }
/*AERO1+*/ #if IS_GPRS
/*AERO1+*/    if(!IS_CONTINUOUS_RX_SLOT()) /*false: evaluate the real gain setting */
/*AERO1+*/    {
/*AERO1+*/ #endif
/*AERO1+*/       agcptr = AGC_TABLE[rf_band];
/*AERO1+*/       agcptr += 2;
/*AERO1+*/       if( request_gain >= agcptr->pos_gain )
/*AERO1+*/       {  agcptr -= 2;
/*AERO1+*/          if( request_gain < agcptr->pos_gain )
/*AERO1+*/          {  agcptr += 1;
/*AERO1+*/             if(request_gain < agcptr->pos_gain )
/*AERO1+*/             {  agcptr += 1;
/*AERO1+*/             }
/*AERO1+*/          }
/*AERO1+*/       }
/*AERO1+*/       else
/*AERO1+*/       {  agcptr += 1;
/*AERO1+*/          if( request_gain < agcptr->pos_gain )
/*AERO1+*/          {  agcptr += 1;
/*AERO1+*/ #if IS_GSM
/*AERO1+*/             if(request_gain < agcptr->pos_gain )
/*AERO1+*/             {  agcptr += 1;
/*AERO1+*/             }
/*AERO1+*/ #endif
/*AERO1+*/          }
/*AERO1+*/       }
/*AERO1+*/       {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*AERO1+*/          real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*AERO1+*/          setting   = agcptr->setting + (bit_no<<6);
/*AERO1+*/       }
/*AERO1+*/ #if IS_GPRS
/*AERO1+*/       last_agcptr = agcptr;
/*AERO1+*/    }
/*AERO1+*/    else /* is_continuous_slot */
/*AERO1+*/    {  bit_no    = BIT_NO( request_gain, last_agcptr->A, GC_B );
/*AERO1+*/       real_gain = REAL_GAIN( bit_no, last_agcptr->A, GC_B );
/*AERO1+*/       setting   = (bit_no<<6)|0x22;
/*AERO1+*/    }
/*AERO1+*/ #endif
/*AERO1+*/    *gain_setting = setting;
/*AERO1+*/    return( real_gain );
/*AERO1+*/ }
/*AERO1+*/
#endif

#if IS_RF_POLARIS1
/*RFMD*/
/*RFMD*/ typedef  struct
/*RFMD*/ {
/*RFMD*/    short pos_gain;
/*RFMD*/    short setting;
/*RFMD*/    short A;
/*RFMD*/    short base;
/*RFMD*/ } sL1DAGCDATA_RFMD;
/*RFMD*/
/*RFMD*/ #define  GAIN_STEP              1 // no used
/*RFMD*/
/*RFMD*/ #define  RF_GSM_MAXGAIN         ( 110.4*(PWRRES))
/*RFMD*/ #define  RF_GSM_MINGAIN         (    -3*(PWRRES))
/*RFMD*/ #define  RF_DCS_MAXGAIN         RF_GSM_MAXGAIN
/*RFMD*/ #define  RF_DCS_MINGAIN         RF_GSM_MINGAIN
/*RFMD*/ #define  RF_PCS_MAXGAIN         RF_GSM_MAXGAIN
/*RFMD*/ #define  RF_PCS_MINGAIN         RF_GSM_MINGAIN
/*RFMD*/
/*RFMD*/
/*RFMD*/ /* GSM900....................................................................*/
/*RFMD*/ const  sL1DAGCDATA_RFMD  AGC_TABLE_GSM900[25] =
/*RFMD*/ {
/*RFMD*/    {  GBOUND( 107.375, 106.375 ), (short)0x17AB, -107.375*8, 107.375*8 },
/*RFMD*/    {  GBOUND( 101.375, 100.375 ), (short)0x17AA, -101.375*8, 101.375*8 },
/*RFMD*/    {  GBOUND(  94.375,  93.375 ), (short)0x07A9,  -94.375*8,  94.375*8 },
/*RFMD*/    {  GBOUND(  88.375,  87.375 ), (short)0x07A8,  -88.375*8,  88.375*8 },
/*RFMD*/    {  GBOUND(  82.375,  81.375 ), (short)0x07A7,  -82.375*8,  82.375*8 },
/*RFMD*/    {  GBOUND(  76.375,  75.375 ), (short)0x07A6,  -76.375*8,  76.375*8 },
/*RFMD*/    {  589                       , (short)0x47A5,  -74.400*8,  74.400*8 },
/*RFMD*/    {  587                       , (short)0x25e5,  -73.500*8,  72.875*8 },
/*RFMD*/    {  GBOUND(  70.875,  69.875 ), (short)0x05e5,  -70.875*8,  70.875*8 },
/*RFMD*/    {  GBOUND(  64.875,  63.875 ), (short)0x05e4,  -64.875*8,  64.875*8 },
/*RFMD*/    {  475                       , (short)0x15e3,  -59.875*8,  59.875*8 },
/*RFMD*/    {  GBOUND(  57.000,  56.000 ), (short)0x0564,  -57.000*8,  57.000*8 },
/*RFMD*/    {  403                       , (short)0x0563,  -51.000*8,  51.000*8 },
/*RFMD*/    {  GBOUND(  48.875,  47.875 ), (short)0xe563,  -48.875*8,  48.875*8 },
/*RFMD*/    {  338                       , (short)0x0463,  -42.875*8,  42.875*8 },
/*RFMD*/    {  292                       , (short)0xa463,  -36.750*8,  36.750*8 },
/*RFMD*/    {  278                       , (short)0x0063,  -35.375*8,  35.375*8 },
/*RFMD*/    {  231                       , (short)0xa063,  -29.250*8,  29.250*8 },
/*RFMD*/    {  208                       , (short)0x0473,  -26.625*8,  26.625*8 },
/*RFMD*/    {  GBOUND(  20.500,  19.500 ), (short)0xa473,  -20.500*8,  20.500*8 },
/*RFMD*/    {  110                       , (short)0xa472,  -14.500*8,  14.500*8 },
/*RFMD*/    {  100                       , (short)0x0072, -107.000*8,  13.125*8 },
/*RFMD*/    {  GBOUND(   7.000,   6.000 ), (short)0xa072,   -7.000*8,   7.000*8 },
/*RFMD*/    {  GBOUND(   1.000,   0.000 ), (short)0xa071,   -1.000*8,   1.000*8 },
/*RFMD*/    {  -25                       , (short)0xc070,    3.000*8,  -3.000*8 },
/*RFMD*/ };
/*RFMD*/
/*RFMD*/ /*...........................................................................*/
/*RFMD*/
/*RFMD*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*RFMD*/ {  {                   0,                   0          },   /*#FrequencyBand400  */
/*RFMD*/    {                   0,                   0         },   /*#FrequencyBand850  */
/*RFMD*/    { (int)RF_GSM_MAXGAIN, (int)RF_GSM_MINGAIN         },   /* FrequencyBand900  */
/*RFMD*/    { (int)RF_GSM_MAXGAIN, (int)RF_GSM_MINGAIN         },   /* FrequencyBand1800 */
/*RFMD*/    { (int)RF_GSM_MAXGAIN, (int)RF_GSM_MINGAIN         },   /* FrequencyBand1900 */
/*RFMD*/ };
/*RFMD*/
/*RFMD*/ /*...........................................................................*/
/*RFMD*/
/*RFMD*/ const  sL1DAGCDATA_RFMD *const  AGC_TABLE[] =
/*RFMD*/ {  0,                                          /*#FrequencyBand400  */
/*RFMD*/    0,                                          /*#FrequencyBand850  */
/*RFMD*/    AGC_TABLE_GSM900,                           /* FrequencyBand900  */
/*RFMD*/    AGC_TABLE_GSM900,                           /* FrequencyBand1800 */
/*RFMD*/    AGC_TABLE_GSM900,                           /* FrequencyBand1900 */
/*RFMD*/ };
/*RFMD*/ /*...........................................................................*/
/*RFMD*/
/*RFMD*/ int L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*RFMD*/ {  int   max_gain, min_gain, real_gain;
/*RFMD*/    const int*    d32ptr;
/*RFMD*/    const sL1DAGCDATA_RFMD*  agcptr;
/*RFMD*/    short  setting;
/*RFMD*/    int   bit_no;
/*RFMD*/    int left, right, middle;
/*RFMD*/
/*RFMD*/   /*transfer power gain to voltage gain*/
/*RFMD*/   request_gain = request_gain + 37*8;
/*RFMD*/
/*RFMD*/    /* evaluate the range of available gain */
/*RFMD*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*RFMD*/    max_gain = *d32ptr++;
/*RFMD*/    min_gain = *d32ptr;
/*RFMD*/
/*RFMD*/    /* clipping the request gain to the avialable gain */
/*RFMD*/    if( request_gain>=max_gain )
/*RFMD*/    {  request_gain = max_gain;  }
/*RFMD*/    else  if( request_gain<=min_gain )
/*RFMD*/    {  request_gain = min_gain;  }
/*RFMD*/
/*RFMD*/    /* evaluate the real gain setting */
/*RFMD*/    agcptr = AGC_TABLE[rf_band];
/*RFMD*/
/*RFMD*/    /*binary search*/
/*RFMD*/    left = 0; right = 24;
/*RFMD*/    while (left <= right)
/*RFMD*/    {
/*RFMD*/       middle = (left + right)/2;
/*RFMD*/       if ( request_gain > (agcptr+middle)->pos_gain )
/*RFMD*/          right = middle - 1;
/*RFMD*/       else if ( request_gain <= (agcptr+middle)->pos_gain )
/*RFMD*/          left = middle + 1;
/*RFMD*/    }
/*RFMD*/    agcptr = (agcptr+left);
/*RFMD*/
/*RFMD*/    {
/*RFMD*/       bit_no = (request_gain + 3 + agcptr->A)/8;
/*RFMD*/       real_gain = agcptr->base + (bit_no*8);
/*RFMD*/       /*transfer voltage gain to power gain*/
/*RFMD*/       real_gain = real_gain - 37*8;
/*RFMD*/
/*RFMD*/       bit_no = 0x0f & ( ((agcptr->setting)>>12) + bit_no);
/*RFMD*/       setting = ((agcptr->setting) & 0x07ff) + (bit_no<<11);
/*RFMD*/    }
/*RFMD*/
/*RFMD*/    *gain_setting = setting;
/*RFMD*/    return( real_gain );
/*RFMD*/ }
/*RFMD*/
#endif

#if  0 /* AMR use */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74117*/ #if IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74117*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if IS_RF_SKY74117 /* GPRS use */
/*SKY74117*/
/*SKY74117*/ #define  LOFS    (4.000)
/*SKY74117*/ #define  HOFS    (4.000)
/*SKY74117*/
/*SKY74117*/ #define  GAIN_STEP               2
/*SKY74117*/
/*SKY74117*/ #define  RF_GSM850_MAXGAIN      (( 57+LOFS)*(PWRRES))
/*SKY74117*/ #define  RF_GSM850_MINGAIN      ((-33+LOFS)*(PWRRES))
/*SKY74117*/ #define  RF_GSM_MAXGAIN         (( 57+LOFS)*(PWRRES))
/*SKY74117*/ #define  RF_GSM_MINGAIN         ((-33+LOFS)*(PWRRES))
/*SKY74117*/ #define  RF_DCS_MAXGAIN         (( 51+HOFS)*(PWRRES))
/*SKY74117*/ #define  RF_DCS_MINGAIN         ((-33+HOFS)*(PWRRES))
/*SKY74117*/ #define  RF_PCS_MAXGAIN         (( 53+HOFS)*(PWRRES))
/*SKY74117*/ #define  RF_PCS_MINGAIN         ((-33+HOFS)*(PWRRES))
/*SKY74117*/ /* GSM850....................................................................*/
/*SKY74117*/
/*SKY74117*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[13] =
/*SKY74117*/ {
/*SKY74117*/    {  GBOUND( 45.0+LOFS,  43.0+LOFS), GC_A( 0,  45.0+LOFS), 0x043C24 },
/*SKY74117*/    {  GBOUND( 33.0+LOFS,  31.0+LOFS), GC_A( 0,  33.0+LOFS), 0x043824 },
/*SKY74117*/    {  GBOUND( 27.0+LOFS,  25.0+LOFS), GC_A( 0,  27.0+LOFS), 0x043424 },
/*SKY74117*/    {  GBOUND( 25.0+LOFS,  23.0+LOFS), GC_A( 5,  25.0+LOFS), 0x043024 },
/*SKY74117*/    {  GBOUND( 21.0+LOFS,  19.0+LOFS), GC_A( 3,  21.0+LOFS), 0x042824 },
/*SKY74117*/    {  GBOUND( 17.0+LOFS,  15.0+LOFS), GC_A( 4,  17.0+LOFS), 0x042424 },
/*SKY74117*/    {  GBOUND( 15.0+LOFS,  13.0+LOFS), GC_A( 0,  15.0+LOFS), 0x042824 },
/*SKY74117*/    {  GBOUND(  9.0+LOFS,   7.0+LOFS), GC_A( 0,   9.0+LOFS), 0x042424 },
/*SKY74117*/    {  GBOUND(  5.0+LOFS,   3.0+LOFS), GC_A( 4,   5.0+LOFS), 0x042024 },
/*SKY74117*/    {  GBOUND( -9.0+LOFS, -11.0+LOFS), GC_A( 0,  -9.0+LOFS), 0x040814 },
/*SKY74117*/    {  GBOUND(-15.0+LOFS, -17.0+LOFS), GC_A( 0, -15.0+LOFS), 0x040414 },
/*SKY74117*/    {  GBOUND(-27.0+LOFS, -29.0+LOFS), GC_A( 0, -27.0+LOFS), 0x040014 },
/*SKY74117*/    {  GBOUND(-33.0+LOFS, -33.0+LOFS), GC_A( 0, -33.0+LOFS), 0x040004 },
/*SKY74117*/ };
/*SKY74117*/
/*SKY74117*/ /* GSM900....................................................................*/
/*SKY74117*/
/*SKY74117*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[13] =
/*SKY74117*/ {
/*SKY74117*/    {  GBOUND( 45.0+LOFS,  43.0+LOFS), GC_A( 0,  45.0+LOFS), 0x053C24 },
/*SKY74117*/    {  GBOUND( 33.0+LOFS,  31.0+LOFS), GC_A( 0,  33.0+LOFS), 0x053824 },
/*SKY74117*/    {  GBOUND( 27.0+LOFS,  25.0+LOFS), GC_A( 0,  27.0+LOFS), 0x053424 },
/*SKY74117*/    {  GBOUND( 25.0+LOFS,  23.0+LOFS), GC_A( 5,  25.0+LOFS), 0x053024 },
/*SKY74117*/    {  GBOUND( 21.0+LOFS,  19.0+LOFS), GC_A( 3,  21.0+LOFS), 0x052824 },
/*SKY74117*/    {  GBOUND( 17.0+LOFS,  15.0+LOFS), GC_A( 4,  17.0+LOFS), 0x052424 },
/*SKY74117*/    {  GBOUND( 15.0+LOFS,  13.0+LOFS), GC_A( 0,  15.0+LOFS), 0x052824 },
/*SKY74117*/    {  GBOUND(  9.0+LOFS,   7.0+LOFS), GC_A( 0,   9.0+LOFS), 0x052424 },
/*SKY74117*/    {  GBOUND(  5.0+LOFS,   3.0+LOFS), GC_A( 4,   5.0+LOFS), 0x052024 },
/*SKY74117*/    {  GBOUND( -9.0+LOFS, -11.0+LOFS), GC_A( 0,  -9.0+LOFS), 0x050814 },
/*SKY74117*/    {  GBOUND(-15.0+LOFS, -17.0+LOFS), GC_A( 0, -15.0+LOFS), 0x050414 },
/*SKY74117*/    {  GBOUND(-27.0+LOFS, -29.0+LOFS), GC_A( 0, -27.0+LOFS), 0x050014 },
/*SKY74117*/    {  GBOUND(-33.0+LOFS, -33.0+LOFS), GC_A( 0, -33.0+LOFS), 0x050004 },
/*SKY74117*/ };
/*SKY74117*/
/*SKY74117*/ /* DCS1800...................................................................*/
/*SKY74117*/
/*SKY74117*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[13] =
/*SKY74117*/ {
/*SKY74117*/    {  GBOUND( 33.0+HOFS,  31.0+HOFS), GC_A( 0,  33.0+HOFS), 0x063824 },
/*SKY74117*/    {  GBOUND( 27.0+HOFS,  25.0+HOFS), GC_A( 0,  27.0+HOFS), 0x063424 },
/*SKY74117*/    {  GBOUND( 25.0+HOFS,  23.0+HOFS), GC_A( 5,  25.0+HOFS), 0x063024 },
/*SKY74117*/    {  GBOUND(  9.0+HOFS,   7.0+HOFS), GC_A( 0,   9.0+HOFS), 0x062424 },
/*SKY74117*/    {  GBOUND(  7.0+HOFS,   5.0+HOFS), GC_A( 5,   7.0+HOFS), 0x062024 },
/*SKY74117*/    {  GBOUND( -3.0+HOFS,  -5.0+HOFS), GC_A( 0,  -3.0+HOFS), 0x060824 },
/*SKY74117*/    {  GBOUND( -7.0+HOFS,  -9.0+HOFS), GC_A( 1,  -7.0+HOFS), 0x060424 },
/*SKY74117*/    {  GBOUND( -9.0+HOFS, -11.0+HOFS), GC_A( 0,  -9.0+HOFS), 0x060814 },
/*SKY74117*/    {  GBOUND(-27.0+HOFS, -29.0+HOFS), GC_A( 0, -27.0+HOFS), 0x060014 },
/*SKY74117*/    {  GBOUND(-33.0+HOFS, -33.0+HOFS), GC_A( 0, -33.0+HOFS), 0x060004 },
/*SKY74117*/    {  GBOUND(-33.0+HOFS, -33.0+HOFS), GC_A( 0, -33.0+HOFS), 0x060004 },
/*SKY74117*/    {  GBOUND(-33.0+HOFS, -33.0+HOFS), GC_A( 0, -33.0+HOFS), 0x060004 },
/*SKY74117*/    {  GBOUND(-33.0+HOFS, -33.0+HOFS), GC_A( 0, -33.0+HOFS), 0x060004 },
/*SKY74117*/ };
/*SKY74117*/
/*SKY74117*/ /* PCS1900...................................................................*/
/*SKY74117*/
/*SKY74117*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[13] =
/*SKY74117*/ {
/*SKY74117*/    {  GBOUND( 33.0+HOFS,  31.0+HOFS), GC_A( 0,  33.0+HOFS), 0x073824 },
/*SKY74117*/    {  GBOUND( 27.0+HOFS,  25.0+HOFS), GC_A( 0,  27.0+HOFS), 0x073424 },
/*SKY74117*/    {  GBOUND( 25.0+HOFS,  23.0+HOFS), GC_A( 5,  25.0+HOFS), 0x073024 },
/*SKY74117*/    {  GBOUND( 17.0+HOFS,  15.0+HOFS), GC_A( 1,  17.0+HOFS), 0x072824 },
/*SKY74117*/    {  GBOUND(  9.0+HOFS,   7.0+HOFS), GC_A( 0,   9.0+HOFS), 0x072424 },
/*SKY74117*/    {  GBOUND(  7.0+HOFS,   5.0+HOFS), GC_A( 5,   7.0+HOFS), 0x072024 },
/*SKY74117*/    {  GBOUND( -3.0+HOFS,  -5.0+HOFS), GC_A( 0,  -3.0+HOFS), 0x070824 },
/*SKY74117*/    {  GBOUND( -5.0+HOFS,  -7.0+HOFS), GC_A( 2,  -5.0+HOFS), 0x070424 },
/*SKY74117*/    {  GBOUND( -9.0+HOFS, -11.0+HOFS), GC_A( 0,  -9.0+HOFS), 0x070814 },
/*SKY74117*/    {  GBOUND(-27.0+HOFS, -29.0+HOFS), GC_A( 0, -27.0+HOFS), 0x070014 },
/*SKY74117*/    {  GBOUND(-33.0+HOFS, -33.0+HOFS), GC_A( 0, -33.0+HOFS), 0x070004 },
/*SKY74117*/    {  GBOUND(-33.0+HOFS, -33.0+HOFS), GC_A( 0, -33.0+HOFS), 0x070004 },
/*SKY74117*/    {  GBOUND(-33.0+HOFS, -33.0+HOFS), GC_A( 0, -33.0+HOFS), 0x070004 },
/*SKY74117*/ };
/*SKY74117*/
/*SKY74117*/ //*...........................................................................*/
/*SKY74117*/
/*SKY74117*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*SKY74117*/ {  { 0                     , 0                         },   /*#FrequencyBand400  */
/*SKY74117*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN    },   /* FrequencyBand850  */
/*SKY74117*/    { (int)RF_GSM_MAXGAIN   , (int)RF_GSM_MINGAIN       },   /* FrequencyBand900  */
/*SKY74117*/    { (int)RF_DCS_MAXGAIN   , (int)RF_DCS_MINGAIN       },   /* FrequencyBand1800 */
/*SKY74117*/    { (int)RF_PCS_MAXGAIN   , (int)RF_PCS_MINGAIN       },   /* FrequencyBand1900 */
/*SKY74117*/ };
/*SKY74117*/
/*SKY74117*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*SKY74117*/ {  0,                                              /*#FrequencyBand400  */
/*SKY74117*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*SKY74117*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*SKY74117*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*SKY74117*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*SKY74117*/ };
/*SKY74117*/
/*SKY74117*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*SKY74117*/
/*SKY74117*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*SKY74117*/ {  int   max_gain, min_gain, real_gain;
/*SKY74117*/    const int*    d32ptr;
/*SKY74117*/    const sL1DAGCDATA*  agcptr;
/*SKY74117*/    long  setting;
/*SKY74117*/    int   bit_no;
/*SKY74117*/    int left, right, middle;
/*SKY74117*/
/*SKY74117*/    /* evaluate the range of available gain */
/*SKY74117*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*SKY74117*/    max_gain = *d32ptr++;
/*SKY74117*/    min_gain = *d32ptr;
/*SKY74117*/
/*SKY74117*/    /* clipping the request gain to the avialable gain */
/*SKY74117*/    if( request_gain>=max_gain )
/*SKY74117*/    {  request_gain = max_gain;  }
/*SKY74117*/    else  if( request_gain<=min_gain )
/*SKY74117*/    {  request_gain = min_gain;  }
/*SKY74117*/
/*SKY74117*/    /*binary search*/
/*SKY74117*/    agcptr = AGC_TABLE[rf_band];
/*SKY74117*/    left = 0; right = 12;
/*SKY74117*/    while (left <= right)
/*SKY74117*/    {  middle = (left + right)/2;
/*SKY74117*/       if ( request_gain >= (agcptr+middle)->pos_gain )
/*SKY74117*/          right = middle - 1;
/*SKY74117*/       else if ( request_gain < (agcptr+middle)->pos_gain )
/*SKY74117*/          left = middle + 1;
/*SKY74117*/    }
/*SKY74117*/    agcptr = (agcptr+left);
/*SKY74117*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*SKY74117*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*SKY74117*/       setting   = agcptr->setting + (bit_no<<6);
/*SKY74117*/    }
/*SKY74117*/
/*SKY74117*/ #if IS_GPRS
/*SKY74117*/    if(IS_CONTINUOUS_RX_SLOT())
/*SKY74117*/    {  setting |= 0x000008L;
/*SKY74117*/    }
/*SKY74117*/ #endif
/*SKY74117*/    *gain_setting = setting;
/*SKY74117*/    return( real_gain );
/*SKY74117*/ }
#endif

#if IS_RF_SKY74400
/*SKY74400*/
/*SKY74400*/ #define  LOFS                   (-10.000)
/*SKY74400*/ #define  HOFS                   (-10.000)
/*SKY74400*/
/*SKY74400*/ #define  GAIN_STEP              2
/*SKY74400*/
/*SKY74400*/ #define  RF_GSM850_MAXGAIN      (( 66+LOFS)*(PWRRES))
/*SKY74400*/ #define  RF_GSM850_MINGAIN      ((-24+LOFS)*(PWRRES))
/*SKY74400*/ #define  RF_GSM_MAXGAIN         (( 66+LOFS)*(PWRRES))
/*SKY74400*/ #define  RF_GSM_MINGAIN         ((-24+LOFS)*(PWRRES))
/*SKY74400*/ #define  RF_DCS_MAXGAIN         (( 64+HOFS)*(PWRRES))
/*SKY74400*/ #define  RF_DCS_MINGAIN         ((-26+HOFS)*(PWRRES))
/*SKY74400*/ #define  RF_PCS_MAXGAIN         (( 64+HOFS)*(PWRRES))
/*SKY74400*/ #define  RF_PCS_MINGAIN         ((-26+HOFS)*(PWRRES))
/*SKY74400*/ /* GSM850....................................................................*/
/*SKY74400*/
/*SKY74400*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[13] =
/*SKY74400*/ {
/*SKY74400*/    {  GBOUND( 54.0+LOFS,  52.0+LOFS), GC_A( 0,  54.0+LOFS), 0x043C24 },
/*SKY74400*/    {  GBOUND( 42.0+LOFS,  40.0+LOFS), GC_A( 0,  42.0+LOFS), 0x043824 },
/*SKY74400*/    {  GBOUND( 36.0+LOFS,  34.0+LOFS), GC_A( 0,  36.0+LOFS), 0x043424 },
/*SKY74400*/    {  GBOUND( 34.0+LOFS,  32.0+LOFS), GC_A( 5,  34.0+LOFS), 0x043024 },
/*SKY74400*/    {  GBOUND( 30.0+LOFS,  28.0+LOFS), GC_A( 3,  30.0+LOFS), 0x042824 },
/*SKY74400*/    {  GBOUND( 26.0+LOFS,  24.0+LOFS), GC_A( 4,  26.0+LOFS), 0x042424 },
/*SKY74400*/    {  GBOUND( 24.0+LOFS,  22.0+LOFS), GC_A( 0,  24.0+LOFS), 0x042824 },
/*SKY74400*/    {  GBOUND( 18.0+LOFS,  16.0+LOFS), GC_A( 0,  18.0+LOFS), 0x042424 },
/*SKY74400*/    {  GBOUND( 14.0+LOFS,  12.0+LOFS), GC_A( 4,  14.0+LOFS), 0x042024 },
/*SKY74400*/    {  GBOUND(  0.0+LOFS,  -2.0+LOFS), GC_A( 0,   0.0+LOFS), 0x040814 },
/*SKY74400*/    {  GBOUND( -6.0+LOFS,  -8.0+LOFS), GC_A( 0,  -6.0+LOFS), 0x040414 },
/*SKY74400*/    {  GBOUND(-18.0+LOFS, -20.0+LOFS), GC_A( 0, -18.0+LOFS), 0x040014 },
/*SKY74400*/    {  GBOUND(-24.0+LOFS, -24.0+LOFS), GC_A( 0, -24.0+LOFS), 0x040004 },
/*SKY74400*/ };
/*SKY74400*/
/*SKY74400*/ /* GSM900....................................................................*/
/*SKY74400*/
/*SKY74400*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[13] =
/*SKY74400*/ {
/*SKY74400*/    {  GBOUND( 54.0+LOFS,  52.0+LOFS), GC_A( 0,  54.0+LOFS), 0x053C24 },
/*SKY74400*/    {  GBOUND( 42.0+LOFS,  40.0+LOFS), GC_A( 0,  42.0+LOFS), 0x053824 },
/*SKY74400*/    {  GBOUND( 36.0+LOFS,  34.0+LOFS), GC_A( 0,  36.0+LOFS), 0x053424 },
/*SKY74400*/    {  GBOUND( 34.0+LOFS,  32.0+LOFS), GC_A( 5,  34.0+LOFS), 0x053024 },
/*SKY74400*/    {  GBOUND( 30.0+LOFS,  28.0+LOFS), GC_A( 3,  30.0+LOFS), 0x052824 },
/*SKY74400*/    {  GBOUND( 26.0+LOFS,  24.0+LOFS), GC_A( 4,  26.0+LOFS), 0x052424 },
/*SKY74400*/    {  GBOUND( 24.0+LOFS,  22.0+LOFS), GC_A( 0,  24.0+LOFS), 0x052824 },
/*SKY74400*/    {  GBOUND( 18.0+LOFS,  16.0+LOFS), GC_A( 0,  18.0+LOFS), 0x052424 },
/*SKY74400*/    {  GBOUND( 14.0+LOFS,  12.0+LOFS), GC_A( 4,  14.0+LOFS), 0x052024 },
/*SKY74400*/    {  GBOUND(  0.0+LOFS,  -2.0+LOFS), GC_A( 0,   0.0+LOFS), 0x050814 },
/*SKY74400*/    {  GBOUND( -6.0+LOFS,  -8.0+LOFS), GC_A( 0,  -6.0+LOFS), 0x050414 },
/*SKY74400*/    {  GBOUND(-18.0+LOFS, -20.0+LOFS), GC_A( 0, -18.0+LOFS), 0x050014 },
/*SKY74400*/    {  GBOUND(-24.0+LOFS, -24.0+LOFS), GC_A( 0, -24.0+LOFS), 0x050004 },
/*SKY74400*/ };
/*SKY74400*/
/*SKY74400*/ /* DCS1800...................................................................*/
/*SKY74400*/
/*SKY74400*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[13] =
/*SKY74400*/ {
/*SKY74400*/    {  GBOUND( 42.0+HOFS,  40.0+HOFS), GC_A( 0,  42.0+HOFS), 0x063824 },
/*SKY74400*/    {  GBOUND( 36.0+HOFS,  34.0+HOFS), GC_A( 0,  36.0+HOFS), 0x063424 },
/*SKY74400*/    {  GBOUND( 34.0+HOFS,  32.0+HOFS), GC_A( 5,  34.0+HOFS), 0x063024 },
/*SKY74400*/    {  GBOUND( 18.0+HOFS,  16.0+HOFS), GC_A( 0,  18.0+HOFS), 0x062424 },
/*SKY74400*/    {  GBOUND( 16.0+HOFS,  14.0+HOFS), GC_A( 5,  16.0+HOFS), 0x062024 },
/*SKY74400*/    {  GBOUND(  6.0+HOFS,   4.0+HOFS), GC_A( 0,   6.0+HOFS), 0x060824 },
/*SKY74400*/    {  GBOUND(  2.0+HOFS,   0.0+HOFS), GC_A( 1,   2.0+HOFS), 0x060424 },
/*SKY74400*/    {  GBOUND(  0.0+HOFS,  -2.0+HOFS), GC_A( 0,   0.0+HOFS), 0x060814 },
/*SKY74400*/    {  GBOUND(-18.0+HOFS, -20.0+HOFS), GC_A( 0, -18.0+HOFS), 0x060014 },
/*SKY74400*/    {  GBOUND(-24.0+HOFS, -24.0+HOFS), GC_A( 0, -24.0+HOFS), 0x060004 },
/*SKY74400*/    {  GBOUND(-24.0+HOFS, -24.0+HOFS), GC_A( 0, -24.0+HOFS), 0x060004 },
/*SKY74400*/    {  GBOUND(-24.0+HOFS, -24.0+HOFS), GC_A( 0, -24.0+HOFS), 0x060004 },
/*SKY74400*/    {  GBOUND(-24.0+HOFS, -24.0+HOFS), GC_A( 0, -24.0+HOFS), 0x060004 },
/*SKY74400*/ };
/*SKY74400*/
/*SKY74400*/ /* PCS1900...................................................................*/
/*SKY74400*/
/*SKY74400*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[13] =
/*SKY74400*/ {
/*SKY74400*/    {  GBOUND( 42.0+HOFS,  40.0+HOFS), GC_A( 0,  42.0+HOFS), 0x073824 },
/*SKY74400*/    {  GBOUND( 36.0+HOFS,  34.0+HOFS), GC_A( 0,  36.0+HOFS), 0x073424 },
/*SKY74400*/    {  GBOUND( 34.0+HOFS,  32.0+HOFS), GC_A( 5,  34.0+HOFS), 0x073024 },
/*SKY74400*/    {  GBOUND( 18.0+HOFS,  16.0+HOFS), GC_A( 1,  18.0+HOFS), 0x072424 },
/*SKY74400*/    {  GBOUND( 16.0+HOFS,  14.0+HOFS), GC_A( 0,  16.0+HOFS), 0x072024 },
/*SKY74400*/    {  GBOUND(  6.0+HOFS,   4.0+HOFS), GC_A( 5,   6.0+HOFS), 0x070824 },
/*SKY74400*/    {  GBOUND(  2.0+HOFS,   0.0+HOFS), GC_A( 0,   2.0+HOFS), 0x070424 },
/*SKY74400*/    {  GBOUND(  0.0+HOFS,  -2.0+HOFS), GC_A( 2,   0.0+HOFS), 0x070814 },
/*SKY74400*/    {  GBOUND(-18.0+HOFS, -20.0+HOFS), GC_A( 0, -18.0+HOFS), 0x070014 },
/*SKY74400*/    {  GBOUND(-24.0+HOFS, -24.0+HOFS), GC_A( 0, -24.0+HOFS), 0x070004 },
/*SKY74400*/    {  GBOUND(-24.0+HOFS, -24.0+HOFS), GC_A( 0, -24.0+HOFS), 0x070004 },
/*SKY74400*/    {  GBOUND(-24.0+HOFS, -24.0+HOFS), GC_A( 0, -24.0+HOFS), 0x070004 },
/*SKY74400*/    {  GBOUND(-24.0+HOFS, -24.0+HOFS), GC_A( 0, -24.0+HOFS), 0x070004 },
/*SKY74400*/ };
/*SKY74400*/
/*SKY74400*/ //*...........................................................................*/
/*SKY74400*/
/*SKY74400*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*SKY74400*/ {  { 0                     , 0                         },   /*#FrequencyBand400  */
/*SKY74400*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN    },   /* FrequencyBand850  */
/*SKY74400*/    { (int)RF_GSM_MAXGAIN   , (int)RF_GSM_MINGAIN       },   /* FrequencyBand900  */
/*SKY74400*/    { (int)RF_DCS_MAXGAIN   , (int)RF_DCS_MINGAIN       },   /* FrequencyBand1800 */
/*SKY74400*/    { (int)RF_PCS_MAXGAIN   , (int)RF_PCS_MINGAIN       },   /* FrequencyBand1900 */
/*SKY74400*/ };
/*SKY74400*/
/*SKY74400*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*SKY74400*/ {  0,                                              /*#FrequencyBand400  */
/*SKY74400*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*SKY74400*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*SKY74400*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*SKY74400*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*SKY74400*/ };
/*SKY74400*/
/*SKY74400*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*SKY74400*/
/*SKY74400*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*SKY74400*/ {  int   max_gain, min_gain, real_gain;
/*SKY74400*/    const int*    d32ptr;
/*SKY74400*/    const sL1DAGCDATA*  agcptr;
/*SKY74400*/    long  setting;
/*SKY74400*/    int   bit_no;
/*SKY74400*/    int left, right, middle;
/*SKY74400*/
/*SKY74400*/    /* evaluate the range of available gain */
/*SKY74400*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*SKY74400*/    max_gain = *d32ptr++;
/*SKY74400*/    min_gain = *d32ptr;
/*SKY74400*/
/*SKY74400*/    /* clipping the request gain to the avialable gain */
/*SKY74400*/    if( request_gain>=max_gain )
/*SKY74400*/    {  request_gain = max_gain;  }
/*SKY74400*/    else  if( request_gain<=min_gain )
/*SKY74400*/    {  request_gain = min_gain;  }
/*SKY74400*/
/*SKY74400*/    /*binary search*/
/*SKY74400*/    agcptr = AGC_TABLE[rf_band];
/*SKY74400*/    left = 0; right = 12;
/*SKY74400*/    while (left <= right)
/*SKY74400*/    {  middle = (left + right)/2;
/*SKY74400*/       if ( request_gain >= (agcptr+middle)->pos_gain )
/*SKY74400*/          right = middle - 1;
/*SKY74400*/       else if ( request_gain < (agcptr+middle)->pos_gain )
/*SKY74400*/          left = middle + 1;
/*SKY74400*/    }
/*SKY74400*/    agcptr = (agcptr+left);
/*SKY74400*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*SKY74400*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*SKY74400*/       setting   = agcptr->setting + (bit_no<<6);
/*SKY74400*/    }
/*SKY74400*/
/*SKY74400*/ #if IS_GPRS
/*SKY74400*/    if(IS_CONTINUOUS_RX_SLOT())
/*SKY74400*/    {  setting |= 0x000008L;
/*SKY74400*/    }
/*SKY74400*/ #endif
/*SKY74400*/    *gain_setting = setting;
/*SKY74400*/    return( real_gain );
/*SKY74400*/ }
#endif

#if IS_RF_MT6119
/*MT6119*/
/*MT6119*/ #define  GAIN_STEP               2
/*MT6119*/
/*MT6119*/ #define  RF_GSM_MAXGAIN         (  68.0*(PWRRES))
/*MT6119*/ #define  RF_GSM_MINGAIN         ( -30.0*(PWRRES))
/*MT6119*/ #define  RF_DCS_MAXGAIN         (  68.0*(PWRRES))
/*MT6119*/ #define  RF_DCS_MINGAIN         ( -30.0*(PWRRES))
/*MT6119*/ #define  RF_PCS_MAXGAIN         (  68.0*(PWRRES))
/*MT6119*/ #define  RF_PCS_MINGAIN         ( -30.0*(PWRRES))
/*MT6119*/
/*MT6119*/ /* GSM900....................................................................*/
/*MT6119*/
/*MT6119*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6119*/ {  {  GBOUND(-10.0,-12.0 ), GC_A(  0,-10.0 ), 0x0681A },
/*MT6119*/    {  GBOUND(-30.0,-30.0 ), GC_A(  9,-30.0 ), 0x06812 },
/*MT6119*/ };
/*MT6119*/
/*MT6119*/ /* DCS1800...................................................................*/
/*MT6119*/
/*MT6119*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6119*/ {  {  GBOUND(-10.0,-12.0 ), GC_A(  0,-10.0 ), 0x0701A },
/*MT6119*/    {  GBOUND(-30.0,-30.0 ), GC_A(  9,-30.0 ), 0x07012 },
/*MT6119*/ };
/*MT6119*/
/*MT6119*/ /* PCS1900...................................................................*/
/*MT6119*/
/*MT6119*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6119*/ {  {  GBOUND(-10.0,-12.0 ), GC_A(  0,-10.0 ), 0x0781A },
/*MT6119*/    {  GBOUND(-30.0,-30.0 ), GC_A(  9,-30.0 ), 0x07812 },
/*MT6119*/ };
/*MT6119*/
/*MT6119*/ /*...........................................................................*/
/*MT6119*/
/*MT6119*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6119*/ {  {                   0,                   0 },   /*#FrequencyBand400  */
/*MT6119*/    {                   0,                   0 },   /*#FrequencyBand850  */
/*MT6119*/    { (int)RF_GSM_MAXGAIN, (int)RF_GSM_MINGAIN },   /* FrequencyBand900  */
/*MT6119*/    { (int)RF_DCS_MAXGAIN, (int)RF_DCS_MINGAIN },   /* FrequencyBand1800 */
/*MT6119*/    { (int)RF_PCS_MAXGAIN, (int)RF_PCS_MINGAIN },   /* FrequencyBand1900 */
/*MT6119*/ };
/*MT6119*/
/*MT6119*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6119*/ {  0,                                              /*#FrequencyBand400  */
/*MT6119*/    0,                                              /*#FrequencyBand850  */
/*MT6119*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6119*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6119*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6119*/ };
/*MT6119*/
/*MT6119*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6119*/
/*MT6119*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6119*/ {  int   max_gain, min_gain, real_gain;
/*MT6119*/    const int*    d32ptr;
/*MT6119*/    const sL1DAGCDATA*  agcptr;
/*MT6119*/    long  setting;
/*MT6119*/    int   bit_no;
/*MT6119*/
/*MT6119*/    /* evaluate the range of available gain */
/*MT6119*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6119*/    max_gain = *d32ptr++;
/*MT6119*/    min_gain = *d32ptr;
/*MT6119*/
/*MT6119*/    /* clipping the request gain to the avialable gain */
/*MT6119*/    if( request_gain>=max_gain )
/*MT6119*/    {  request_gain = max_gain;  }
/*MT6119*/    else  if( request_gain<=min_gain )
/*MT6119*/    {  request_gain = min_gain;  }
/*MT6119*/
/*MT6119*/    /* evaluate the real gain setting */
/*MT6119*/    agcptr = AGC_TABLE[rf_band];
/*MT6119*/    if( request_gain < agcptr->pos_gain )
/*MT6119*/    {  agcptr++;
/*MT6119*/    }
/*MT6119*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6119*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6119*/       setting   = agcptr->setting + (bit_no<<5);
/*MT6119*/    }
/*MT6119*/
/*MT6119*/    *gain_setting = setting;
/*MT6119*/    return( real_gain );
/*MT6119*/ }
/*MT6119*/
#endif

#if IS_RF_MT6119C
/*MT6119C*/
/*MT6119C*/ #define  GAIN_STEP               2
/*MT6119C*/
/*MT6119C*/ #define  RF_GSM_MAXGAIN         (  72.0*(PWRRES))
/*MT6119C*/ #define  RF_GSM_MINGAIN         ( -26.0*(PWRRES))
/*MT6119C*/ #define  RF_DCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6119C*/ #define  RF_DCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6119C*/ #define  RF_PCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6119C*/ #define  RF_PCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6119C*/
/*MT6119C*/ /* GSM900....................................................................*/
/*MT6119C*/
/*MT6119C*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[3] =
/*MT6119C*/ {  {  GBOUND( 34.0, 32.0 ), GC_A( 11, 34.0 ), 0x12681A },
/*MT6119C*/    {  GBOUND( -6.0, -8.0 ), GC_A( 32, -6.0 ), 0x00681A },
/*MT6119C*/    {  GBOUND(-26.0,-26.0 ), GC_A(  0,-26.0 ), 0x006812 },
/*MT6119C*/ };
/*MT6119C*/
/*MT6119C*/ /* DCS1800...................................................................*/
/*MT6119C*/
/*MT6119C*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[3] =
/*MT6119C*/ {  {  GBOUND( 32.0, 30.0 ), GC_A( 11, 32.0 ), 0x12701A },
/*MT6119C*/    {  GBOUND( -8.0,-10.0 ), GC_A( 32, -8.0 ), 0x00701A },
/*MT6119C*/    {  GBOUND(-28.0,-28.0 ), GC_A(  0,-28.0 ), 0x007012 },
/*MT6119C*/ };
/*MT6119C*/
/*MT6119C*/ /* PCS1900...................................................................*/
/*MT6119C*/
/*MT6119C*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[3] =
/*MT6119C*/ {  {  GBOUND( 32.0, 30.0 ), GC_A( 11, 32.0 ), 0x12781A },
/*MT6119C*/    {  GBOUND( -8.0,-10.0 ), GC_A( 32, -8.0 ), 0x00781A },
/*MT6119C*/    {  GBOUND(-28.0,-28.0 ), GC_A(  0,-28.0 ), 0x007812 },
/*MT6119C*/ };
/*MT6119C*/
/*MT6119C*/ /*...........................................................................*/
/*MT6119C*/
/*MT6119C*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6119C*/ {  {                   0,                   0 },   /*#FrequencyBand400  */
/*MT6119C*/    {                   0,                   0 },   /*#FrequencyBand850  */
/*MT6119C*/    { (int)RF_GSM_MAXGAIN, (int)RF_GSM_MINGAIN },   /* FrequencyBand900  */
/*MT6119C*/    { (int)RF_DCS_MAXGAIN, (int)RF_DCS_MINGAIN },   /* FrequencyBand1800 */
/*MT6119C*/    { (int)RF_PCS_MAXGAIN, (int)RF_PCS_MINGAIN },   /* FrequencyBand1900 */
/*MT6119C*/ };
/*MT6119C*/
/*MT6119C*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6119C*/ {  0,                                              /*#FrequencyBand400  */
/*MT6119C*/    0,                                              /*#FrequencyBand850  */
/*MT6119C*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6119C*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6119C*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6119C*/ };
/*MT6119C*/
/*MT6119C*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6119C*/
/*MT6119C*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6119C*/ {  int   max_gain, min_gain, real_gain;
/*MT6119C*/    const int*    d32ptr;
/*MT6119C*/    const sL1DAGCDATA*  agcptr;
/*MT6119C*/    long  setting;
/*MT6119C*/    int   bit_no;
/*MT6119C*/
/*MT6119C*/    /* evaluate the range of available gain */
/*MT6119C*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6119C*/    max_gain = *d32ptr++;
/*MT6119C*/    min_gain = *d32ptr;
/*MT6119C*/
/*MT6119C*/    /* clipping the request gain to the avialable gain */
/*MT6119C*/    if( request_gain>=max_gain )
/*MT6119C*/    {  request_gain = max_gain;  }
/*MT6119C*/    else  if( request_gain<=min_gain )
/*MT6119C*/    {  request_gain = min_gain;  }
/*MT6119C*/
/*MT6119C*/    /* evaluate the real gain setting */
/*MT6119C*/    agcptr = AGC_TABLE[rf_band];
/*MT6119C*/    if( request_gain < agcptr->pos_gain )
/*MT6119C*/    {  agcptr++;
/*MT6119C*/       if( request_gain < agcptr->pos_gain )
/*MT6119C*/       {  agcptr++;  }
/*MT6119C*/    }
/*MT6119C*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6119C*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6119C*/       setting   = agcptr->setting + (bit_no<<5);
/*MT6119C*/    }
/*MT6119C*/
/*MT6119C*/    *gain_setting = setting;
/*MT6119C*/    return( real_gain );
/*MT6119C*/ }
/*MT6119C*/
#endif

#if IS_RF_MT6129A
/*MT6129A*/
/*MT6129A*/ #define  GAIN_STEP               2
/*MT6129A*/
/*MT6129A*/ #define  RF_GSM_MAXGAIN         (  72.0*(PWRRES))
/*MT6129A*/ #define  RF_GSM_MINGAIN         ( -26.0*(PWRRES))
/*MT6129A*/ #define  RF_DCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6129A*/ #define  RF_DCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6129A*/ #define  RF_PCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6129A*/ #define  RF_PCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6129A*/
/*MT6129A*/ /* GSM900....................................................................*/
/*MT6129A*/
/*MT6129A*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[3] =
/*MT6129A*/ {  {  GBOUND( 18.0, 16.0 ), GC_A(  3, 18.0 ), 0x126812 },
/*MT6129A*/    {  GBOUND( -6.0, -8.0 ), GC_A(  32,-6.0 ), 0x006812 },
/*MT6129A*/    {  GBOUND(-26.0,-26.0 ), GC_A(  0,-26.0 ), 0x006802 },
/*MT6129A*/ };
/*MT6129A*/
/*MT6129A*/ /* DCS1800...................................................................*/
/*MT6129A*/
/*MT6129A*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[3] =
/*MT6129A*/ {  {  GBOUND( 16.0, 14.0 ), GC_A(  3, 16.0 ), 0x127012 },
/*MT6129A*/    {  GBOUND( -8.0,-10.0 ), GC_A(  32,-8.0 ), 0x007012 },
/*MT6129A*/    {  GBOUND(-28.0,-28.0 ), GC_A(  0,-28.0 ), 0x007002 },
/*MT6129A*/ };
/*MT6129A*/
/*MT6129A*/ /* PCS1900...................................................................*/
/*MT6129A*/
/*MT6129A*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[3] =
/*MT6129A*/ {  {  GBOUND( 16.0, 14.0 ), GC_A(  3, 16.0 ), 0x127812 },
/*MT6129A*/    {  GBOUND( -8.0,-10.0 ), GC_A(  32,-8.0 ), 0x007812 },
/*MT6129A*/    {  GBOUND(-28.0,-28.0 ), GC_A(  0,-28.0 ), 0x007802 },
/*MT6129A*/ };
/*MT6129A*/
/*MT6129A*/ /*...........................................................................*/
/*MT6129A*/
/*MT6129A*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6129A*/ {  {                   0,                   0 },   /*#FrequencyBand400  */
/*MT6129A*/    {                   0,                   0 },   /*#FrequencyBand850  */
/*MT6129A*/    { (int)RF_GSM_MAXGAIN, (int)RF_GSM_MINGAIN },   /* FrequencyBand900  */
/*MT6129A*/    { (int)RF_DCS_MAXGAIN, (int)RF_DCS_MINGAIN },   /* FrequencyBand1800 */
/*MT6129A*/    { (int)RF_PCS_MAXGAIN, (int)RF_PCS_MINGAIN },   /* FrequencyBand1900 */
/*MT6129A*/ };
/*MT6129A*/
/*MT6129A*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6129A*/ {  0,                                              /*#FrequencyBand400  */
/*MT6129A*/    0,                                              /*#FrequencyBand850  */
/*MT6129A*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6129A*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6129A*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6129A*/ };
/*MT6129A*/
/*MT6129A*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6129A*/
/*MT6129A*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6129A*/ {  int   max_gain, min_gain, real_gain;
/*MT6129A*/    const int*    d32ptr;
/*MT6129A*/    const sL1DAGCDATA*  agcptr;
/*MT6129A*/    long  setting;
/*MT6129A*/    int   bit_no;
/*MT6129A*/
/*MT6129A*/    /* evaluate the range of available gain */
/*MT6129A*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6129A*/    max_gain = *d32ptr++;
/*MT6129A*/    min_gain = *d32ptr;
/*MT6129A*/
/*MT6129A*/    /* clipping the request gain to the avialable gain */
/*MT6129A*/    if( request_gain>=max_gain )
/*MT6129A*/    {  request_gain = max_gain;  }
/*MT6129A*/    else  if( request_gain<=min_gain )
/*MT6129A*/    {  request_gain = min_gain;  }
/*MT6129A*/
/*MT6129A*/    /* evaluate the real gain setting */
/*MT6129A*/    agcptr = AGC_TABLE[rf_band];
/*MT6129A*/    if( request_gain < agcptr->pos_gain )
/*MT6129A*/    {  agcptr++;
/*MT6129A*/       if( request_gain < agcptr->pos_gain )
/*MT6129A*/       {  agcptr++;  }
/*MT6129A*/    }
/*MT6129A*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6129A*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6129A*/       setting   = agcptr->setting + (bit_no<<5);
/*MT6129A*/    }
/*MT6129A*/
/*MT6129A*/    *gain_setting = setting;
/*MT6129A*/    return( real_gain );
/*MT6129A*/ }
/*MT6129A*/
#endif

#if IS_RF_MT6129B
/*MT6129B*/
/*MT6129B*/ #define  GAIN_STEP               2
/*MT6129B*/
/*MT6129B*/ #define  RF_GSM850_MAXGAIN      (  72.0*(PWRRES))
/*MT6129B*/ #define  RF_GSM850_MINGAIN      ( -26.0*(PWRRES))
/*MT6129B*/ #define  RF_GSM_MAXGAIN         (  72.0*(PWRRES))
/*MT6129B*/ #define  RF_GSM_MINGAIN         ( -26.0*(PWRRES))
/*MT6129B*/ #define  RF_DCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6129B*/ #define  RF_DCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6129B*/ #define  RF_PCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6129B*/ #define  RF_PCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6129B*/
/*MT6129B*/ /* GSM850....................................................................*/
/*MT6129B*/
/*MT6129B*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[3] =
/*MT6129B*/ {  {  GBOUND( 48.0, 46.0 ), GC_A( 18, 48.0 ), 0x126012 },
/*MT6129B*/    {  GBOUND( -6.0, -8.0 ), GC_A( 32, -6.0 ), 0x006012 },
/*MT6129B*/    {  GBOUND(-26.0,-26.0 ), GC_A(  0,-26.0 ), 0x006002 },
/*MT6129B*/ };
/*MT6129B*/
/*MT6129B*/ /* GSM900....................................................................*/
/*MT6129B*/
/*MT6129B*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[3] =
/*MT6129B*/ {  {  GBOUND( 48.0, 46.0 ), GC_A( 18, 48.0 ), 0x126812 },
/*MT6129B*/    {  GBOUND( -6.0, -8.0 ), GC_A( 32, -6.0 ), 0x006812 },
/*MT6129B*/    {  GBOUND(-26.0,-26.0 ), GC_A(  0,-26.0 ), 0x006802 },
/*MT6129B*/ };
/*MT6129B*/
/*MT6129B*/ /* DCS1800...................................................................*/
/*MT6129B*/
/*MT6129B*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[3] =
/*MT6129B*/ {  {  GBOUND( 46.0, 44.0 ), GC_A( 18, 46.0 ), 0x127012 },
/*MT6129B*/    {  GBOUND( -8.0,-10.0 ), GC_A( 32, -8.0 ), 0x007012 },
/*MT6129B*/    {  GBOUND(-28.0,-28.0 ), GC_A(  0,-28.0 ), 0x007002 },
/*MT6129B*/ };
/*MT6129B*/
/*MT6129B*/ /* PCS1900...................................................................*/
/*MT6129B*/
/*MT6129B*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[3] =
/*MT6129B*/ {  {  GBOUND( 46.0, 44.0 ), GC_A( 18, 46.0 ), 0x127812 },
/*MT6129B*/    {  GBOUND( -8.0,-10.0 ), GC_A( 32, -8.0 ), 0x007812 },
/*MT6129B*/    {  GBOUND(-28.0,-28.0 ), GC_A(  0,-28.0 ), 0x007802 },
/*MT6129B*/ };
/*MT6129B*/
/*MT6129B*/ /*...........................................................................*/
/*MT6129B*/
/*MT6129B*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6129B*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6129B*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6129B*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6129B*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6129B*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6129B*/ };
/*MT6129B*/
/*MT6129B*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6129B*/ {  0,                                              /*#FrequencyBand400  */
/*MT6129B*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6129B*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6129B*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6129B*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6129B*/ };
/*MT6129B*/
/*MT6129B*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6129B*/
/*MT6129B*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6129B*/ {  int   max_gain, min_gain, real_gain;
/*MT6129B*/    const int*    d32ptr;
/*MT6129B*/    const sL1DAGCDATA*  agcptr;
/*MT6129B*/    long  setting;
/*MT6129B*/    int   bit_no;
/*MT6129B*/
/*MT6129B*/    /* evaluate the range of available gain */
/*MT6129B*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6129B*/    max_gain = *d32ptr++;
/*MT6129B*/    min_gain = *d32ptr;
/*MT6129B*/
/*MT6129B*/    /* clipping the request gain to the avialable gain */
/*MT6129B*/    if( request_gain>=max_gain )
/*MT6129B*/    {  request_gain = max_gain;  }
/*MT6129B*/    else  if( request_gain<=min_gain )
/*MT6129B*/    {  request_gain = min_gain;  }
/*MT6129B*/
/*MT6129B*/    /* evaluate the real gain setting */
/*MT6129B*/    agcptr = AGC_TABLE[rf_band];
/*MT6129B*/    if( request_gain < agcptr->pos_gain )
/*MT6129B*/    {  agcptr++;
/*MT6129B*/       if( request_gain < agcptr->pos_gain )
/*MT6129B*/       {  agcptr++;  }
/*MT6129B*/    }
/*MT6129B*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6129B*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6129B*/       setting   = agcptr->setting + (bit_no<<5);
/*MT6129B*/    }
/*MT6129B*/
/*MT6129B*/    *gain_setting = setting;
/*MT6129B*/    return( real_gain );
/*MT6129B*/ }
/*MT6129B*/
#endif

#if  (IS_RF_MT6129C)||(IS_RF_MT6129D)
/*MT6129C,D*/
/*MT6129C,D*/ #define  GAIN_STEP               2
/*MT6129C,D*/
/*MT6129C,D*/ #define  RF_GSM850_MAXGAIN      (  72.0*(PWRRES))
/*MT6129C,D*/ #define  RF_GSM850_MINGAIN      ( -26.0*(PWRRES))
/*MT6129C,D*/ #define  RF_GSM_MAXGAIN         (  72.0*(PWRRES))
/*MT6129C,D*/ #define  RF_GSM_MINGAIN         ( -26.0*(PWRRES))
/*MT6129C,D*/ #define  RF_DCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6129C,D*/ #define  RF_DCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6129C,D*/ #define  RF_PCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6129C,D*/ #define  RF_PCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6129C,D*/
/*MT6129C,D*/ /* GSM850....................................................................*/

/*MT6129C,D*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[3] =
/*MT6129C,D*/ {  {  GBOUND( 34.0, 32.0 ), GC_A( 11, 34.0 ), 0x126012 },
/*MT6129C,D*/    {  GBOUND( -6.0, -8.0 ), GC_A( 32, -6.0 ), 0x006012 },
/*MT6129C,D*/    {  GBOUND(-26.0,-26.0 ), GC_A(  0,-26.0 ), 0x006002 },
/*MT6129C,D*/ };

/*MT6129C,D*/ /* GSM900....................................................................*/
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[3] =
/*MT6129C,D*/ {  {  GBOUND( 34.0, 32.0 ), GC_A( 11, 34.0 ), 0x126812 },
/*MT6129C,D*/    {  GBOUND( -6.0, -8.0 ), GC_A( 32, -6.0 ), 0x006812 },
/*MT6129C,D*/    {  GBOUND(-26.0,-26.0 ), GC_A(  0,-26.0 ), 0x006802 },
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ /* DCS1800...................................................................*/
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[3] =
/*MT6129C,D*/ {  {  GBOUND( 32.0, 30.0 ), GC_A( 11, 32.0 ), 0x127012 },
/*MT6129C,D*/    {  GBOUND( -8.0,-10.0 ), GC_A( 32, -8.0 ), 0x007012 },
/*MT6129C,D*/    {  GBOUND(-28.0,-28.0 ), GC_A(  0,-28.0 ), 0x007002 },
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ /* PCS1900...................................................................*/
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[3] =
/*MT6129C,D*/ {  {  GBOUND( 32.0, 30.0 ), GC_A( 11, 32.0 ), 0x127812 },
/*MT6129C,D*/    {  GBOUND( -8.0,-10.0 ), GC_A( 32, -8.0 ), 0x007812 },
/*MT6129C,D*/    {  GBOUND(-28.0,-28.0 ), GC_A(  0,-28.0 ), 0x007802 },
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ /*...........................................................................*/
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6129C,D*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6129C,D*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6129C,D*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6129C,D*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6129C,D*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6129C,D*/ {  0,                                              /*#FrequencyBand400  */
/*MT6129C,D*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6129C,D*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6129C,D*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6129C,D*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DAGCDATA *const  AGC_TABLE_GSM800in900PATH[] =
/*MT6129C,D*/ {  0,                                              /*#FrequencyBand400 (not support)  */
/*MT6129C,D*/    AGC_TABLE_GSM900,                               /* FrequencyBand900 (Get GSM850 signal from GSM900 input pins) */
/*MT6129C,D*/    AGC_TABLE_GSM850,                               /* FrequencyBand850 (Get GSM900 signal from GSM850 input pins, just avoid to camp on GSM900 network, not swap*/
/*MT6129C,D*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800               */
/*MT6129C,D*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900               */
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6129C,D*/
/*MT6129C,D*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6129C,D*/ {  int   max_gain, min_gain, real_gain;
/*MT6129C,D*/    const int*    d32ptr;
/*MT6129C,D*/    const sL1DAGCDATA*  agcptr;
/*MT6129C,D*/    long  setting;
/*MT6129C,D*/    int   bit_no;
/*MT6129C,D*/
/*MT6129C,D*/    /* evaluate the range of available gain */
/*MT6129C,D*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6129C,D*/    max_gain = *d32ptr++;
/*MT6129C,D*/    min_gain = *d32ptr;
/*MT6129C,D*/
/*MT6129C,D*/    /* clipping the request gain to the avialable gain */
/*MT6129C,D*/    if( request_gain>=max_gain )
/*MT6129C,D*/    {  request_gain = max_gain;  }
/*MT6129C,D*/    else  if( request_gain<=min_gain )
/*MT6129C,D*/    {  request_gain = min_gain;  }
/*MT6129C,D*/
/*MT6129C,D*/    /* evaluate the real gain setting */
/*MT6129C,D*/    if(  BBTXParameters.bbrx_gsm850_gsm900_swap )
/*MT6129C,D*/    {   agcptr = AGC_TABLE_GSM800in900PATH[rf_band];  }
/*MT6129C,D*/    else
/*MT6129C,D*/    {   agcptr = AGC_TABLE[rf_band];           }
/*MT6129C,D*/
/*MT6129C,D*/    if( request_gain < agcptr->pos_gain )
/*MT6129C,D*/    {  agcptr++;
/*MT6129C,D*/       if( request_gain < agcptr->pos_gain )
/*MT6129C,D*/       {  agcptr++;  }
/*MT6129C,D*/    }
/*MT6129C,D*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6129C,D*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6129C,D*/       setting   = agcptr->setting + (bit_no<<5);
/*MT6129C,D*/    }
/*MT6129C,D*/
/*MT6129C,D*/    *gain_setting = setting;
/*MT6129C,D*/    return( real_gain );
/*MT6129C,D*/ }
/*MT6129C,D*/
#endif

#if IS_RF_MT6139B
/*MT6139B*/
/*MT6139B*/ #define  GAIN_STEP               2
/*MT6139B*/
/*MT6139B*/ #define  RF_GSM850_MAXGAIN      (  56.0*(PWRRES))
/*MT6139B*/ #define  RF_GSM850_MINGAIN      ( -32.0*(PWRRES))
/*MT6139B*/ #define  RF_GSM_MAXGAIN         (  56.0*(PWRRES))
/*MT6139B*/ #define  RF_GSM_MINGAIN         ( -32.0*(PWRRES))
/*MT6139B*/ #define  RF_DCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6139B*/ #define  RF_DCS_MINGAIN         ( -32.0*(PWRRES))
/*MT6139B*/ #define  RF_PCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6139B*/ #define  RF_PCS_MINGAIN         ( -32.0*(PWRRES))
/*MT6139B*/
/*MT6139B*/ /* GSM850....................................................................*/
/*MT6139B*/
/*MT6139B*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6139B*/ {  {  GBOUND( -4.0, -6.0 ), GC_A( 32, -4.0 ), 0x000C02 },
/*MT6139B*/    {  GBOUND(-44.0,-44.0 ), GC_A(  0,-44.0 ), 0x000C02 },
/*MT6139B*/ };
/*MT6139B*/
/*MT6139B*/ /* GSM900....................................................................*/
/*MT6139B*/
/*MT6139B*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6139B*/ {  {  GBOUND( -4.0, -6.0 ), GC_A( 32, -4.0 ), 0x000C02 },
/*MT6139B*/    {  GBOUND(-44.0,-44.0 ), GC_A(  0,-44.0 ), 0x000C02 },
/*MT6139B*/ };
/*MT6139B*/
/*MT6139B*/ /* DCS1800...................................................................*/
/*MT6139B*/
/*MT6139B*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6139B*/ {  {  GBOUND( -4.0, -6.0 ), GC_A( 32, -4.0 ), 0x000C02 },
/*MT6139B*/    {  GBOUND(-44.0,-44.0 ), GC_A(  0,-44.0 ), 0x000C02 },
/*MT6139B*/ };
/*MT6139B*/
/*MT6139B*/ /* PCS1900...................................................................*/
/*MT6139B*/
/*MT6139B*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6139B*/ {  {  GBOUND( -4.0, -6.0 ), GC_A( 32, -4.0 ), 0x000C02 },
/*MT6139B*/    {  GBOUND(-44.0,-44.0 ), GC_A(  0,-44.0 ), 0x000C02 },
/*MT6139B*/ };
/*MT6139B*/
/*MT6139B*/ /*...........................................................................*/
/*MT6139B*/
/*MT6139B*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6139B*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6139B*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6139B*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6139B*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6139B*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6139B*/ };
/*MT6139B*/
/*MT6139B*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6139B*/ {  0,                                              /*#FrequencyBand400  */
/*MT6139B*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6139B*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6139B*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6139B*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6139B*/ };
/*MT6139B*/
/*MT6139B*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6139B*/
/*MT6139B*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6139B*/ {  int   max_gain, min_gain, real_gain;
/*MT6139B*/    const int*    d32ptr;
/*MT6139B*/    const sL1DAGCDATA*  agcptr;
/*MT6139B*/    long  setting;
/*MT6139B*/    int   bit_no;
/*MT6139B*/
/*MT6139B*/    /* evaluate the range of available gain */
/*MT6139B*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6139B*/    max_gain = *d32ptr++;
/*MT6139B*/    min_gain = *d32ptr;
/*MT6139B*/
/*MT6139B*/    /* clipping the request gain to the avialable gain */
/*MT6139B*/    if( request_gain>=max_gain )
/*MT6139B*/    {  request_gain = max_gain;  }
/*MT6139B*/    else  if( request_gain<=min_gain )
/*MT6139B*/    {  request_gain = min_gain;  }
/*MT6139B*/
/*MT6139B*/    /* evaluate the real gain setting */
/*MT6139B*/    agcptr = AGC_TABLE[rf_band];
/*MT6139B*/    if( request_gain < agcptr->pos_gain )
/*MT6139B*/    {  agcptr++;
/*MT6139B*/    }
/*MT6139B*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6139B*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6139B*/       setting   = agcptr->setting + (bit_no<<4);
/*MT6139B*/    }
/*MT6139B*/
/*MT6139B*/    *gain_setting = setting;
/*MT6139B*/    return( real_gain );
/*MT6139B*/ }
/*MT6139B*/
#endif

#if IS_RF_MT6139C
/*MT6139C*/
/*MT6139C*/ #define  GAIN_STEP               2
/*MT6139C*/
/*MT6139C*/ #define  RF_GSM850_MAXGAIN      (  56.0*(PWRRES))
/*MT6139C*/ #define  RF_GSM850_MINGAIN      ( -32.0*(PWRRES))
/*MT6139C*/ #define  RF_GSM_MAXGAIN         (  56.0*(PWRRES))
/*MT6139C*/ #define  RF_GSM_MINGAIN         ( -32.0*(PWRRES))
/*MT6139C*/ #define  RF_DCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6139C*/ #define  RF_DCS_MINGAIN         ( -32.0*(PWRRES))
/*MT6139C*/ #define  RF_PCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6139C*/ #define  RF_PCS_MINGAIN         ( -32.0*(PWRRES))
/*MT6139C*/
/*MT6139C*/ /* GSM850....................................................................*/
/*MT6139C*/
/*MT6139C*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6139C*/ {  {  GBOUND( -4.0, -6.0 ), GC_A( 32, -4.0 ), 0x000C02 },
/*MT6139C*/    {  GBOUND(-44.0,-44.0 ), GC_A(  0,-44.0 ), 0x000C02 },
/*MT6139C*/ };
/*MT6139C*/
/*MT6139C*/ /* GSM900....................................................................*/
/*MT6139C*/
/*MT6139C*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6139C*/ {  {  GBOUND( -4.0, -6.0 ), GC_A( 32, -4.0 ), 0x000C02 },
/*MT6139C*/    {  GBOUND(-44.0,-44.0 ), GC_A(  0,-44.0 ), 0x000C02 },
/*MT6139C*/ };
/*MT6139C*/
/*MT6139C*/ /* DCS1800...................................................................*/
/*MT6139C*/
/*MT6139C*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6139C*/ {  {  GBOUND( -4.0, -6.0 ), GC_A( 32, -4.0 ), 0x000C02 },
/*MT6139C*/    {  GBOUND(-44.0,-44.0 ), GC_A(  0,-44.0 ), 0x000C02 },
/*MT6139C*/ };
/*MT6139C*/
/*MT6139C*/ /* PCS1900...................................................................*/
/*MT6139C*/
/*MT6139C*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6139C*/ {  {  GBOUND( -4.0, -6.0 ), GC_A( 32, -4.0 ), 0x000C02 },
/*MT6139C*/    {  GBOUND(-44.0,-44.0 ), GC_A(  0,-44.0 ), 0x000C02 },
/*MT6139C*/ };
/*MT6139C*/
/*MT6139C*/ /*...........................................................................*/
/*MT6139C*/
/*MT6139C*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6139C*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6139C*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6139C*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6139C*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6139C*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6139C*/ };
/*MT6139C*/
/*MT6139C*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6139C*/ {  0,                                              /*#FrequencyBand400  */
/*MT6139C*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6139C*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6139C*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6139C*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6139C*/ };
/*MT6139C*/
/*MT6139C*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6139C*/
/*MT6139C*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6139C*/ {  int   max_gain, min_gain, real_gain;
/*MT6139C*/    const int*    d32ptr;
/*MT6139C*/    const sL1DAGCDATA*  agcptr;
/*MT6139C*/    long  setting;
/*MT6139C*/    int   bit_no;
/*MT6139C*/
/*MT6139C*/    /* evaluate the range of available gain */
/*MT6139C*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6139C*/    max_gain = *d32ptr++;
/*MT6139C*/    min_gain = *d32ptr;
/*MT6139C*/
/*MT6139C*/    /* clipping the request gain to the avialable gain */
/*MT6139C*/    if( request_gain>=max_gain )
/*MT6139C*/    {  request_gain = max_gain;  }
/*MT6139C*/    else  if( request_gain<=min_gain )
/*MT6139C*/    {  request_gain = min_gain;  }
/*MT6139C*/
/*MT6139C*/    /* evaluate the real gain setting */
/*MT6139C*/    agcptr = AGC_TABLE[rf_band];
/*MT6139C*/    if( request_gain < agcptr->pos_gain )
/*MT6139C*/    {  agcptr++;
/*MT6139C*/    }
/*MT6139C*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6139C*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6139C*/       setting   = agcptr->setting + (bit_no<<4);
/*MT6139C*/    }
/*MT6139C*/
/*MT6139C*/    *gain_setting = setting;
/*MT6139C*/    return( real_gain );
/*MT6139C*/ }
/*MT6139C*/
#endif

#if IS_RF_MT6139E
/*MT6139E*/
/*MT6139E*/ #define  GAIN_STEP               2
/*MT6139E*/
/*MT6139E*/ #define  RF_GSM850_MAXGAIN      (  56.0*(PWRRES))
/*MT6139E*/ #define  RF_GSM850_MINGAIN      ( -28.0*(PWRRES))
/*MT6139E*/ #define  RF_GSM_MAXGAIN         (  56.0*(PWRRES))
/*MT6139E*/ #define  RF_GSM_MINGAIN         ( -28.0*(PWRRES))
/*MT6139E*/ #define  RF_DCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6139E*/ #define  RF_DCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6139E*/ #define  RF_PCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6139E*/ #define  RF_PCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6139E*/
/*MT6139E*/ /* GSM850....................................................................*/
/*MT6139E*/
/*MT6139E*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6139E*/ {  {  GBOUND( -4.0, -6.0 ), GC_A(  0, -4.0 ), 0x000E02 },
/*MT6139E*/    {  GBOUND(-32.0,-32.0 ), GC_A(  4,-32.0 ), 0x000C02 },
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ /* GSM900....................................................................*/
/*MT6139E*/
/*MT6139E*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6139E*/ {  {  GBOUND( -4.0, -6.0 ), GC_A(  0, -4.0 ), 0x000E02 },
/*MT6139E*/    {  GBOUND(-32.0,-32.0 ), GC_A(  4,-32.0 ), 0x000C02 },
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ /* DCS1800...................................................................*/
/*MT6139E*/
/*MT6139E*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6139E*/ {  {  GBOUND( -4.0, -6.0 ), GC_A(  0, -4.0 ), 0x000E02 },
/*MT6139E*/    {  GBOUND(-32.0,-32.0 ), GC_A(  4,-32.0 ), 0x000C02 },
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ /* PCS1900...................................................................*/
/*MT6139E*/
/*MT6139E*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6139E*/ {  {  GBOUND( -4.0, -6.0 ), GC_A(  0, -4.0 ), 0x000E02 },
/*MT6139E*/    {  GBOUND(-32.0,-32.0 ), GC_A(  4,-32.0 ), 0x000C02 },
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ /*...........................................................................*/
/*MT6139E*/
/*MT6139E*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6139E*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6139E*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6139E*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6139E*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6139E*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6139E*/ {  0,                                              /*#FrequencyBand400  */
/*MT6139E*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6139E*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6139E*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6139E*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6139E*/
/*MT6139E*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6139E*/ {  int   max_gain, min_gain, real_gain;
/*MT6139E*/    const int*    d32ptr;
/*MT6139E*/    const sL1DAGCDATA*  agcptr;
/*MT6139E*/    long  setting;
/*MT6139E*/    int   bit_no;
/*MT6139E*/
/*MT6139E*/    /* evaluate the range of available gain */
/*MT6139E*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6139E*/    max_gain = *d32ptr++;
/*MT6139E*/    min_gain = *d32ptr;
/*MT6139E*/
/*MT6139E*/    /* clipping the request gain to the avialable gain */
/*MT6139E*/    if( request_gain>=max_gain )
/*MT6139E*/    {  request_gain = max_gain;  }
/*MT6139E*/    else  if( request_gain<=min_gain )
/*MT6139E*/    {  request_gain = min_gain;  }
/*MT6139E*/
/*MT6139E*/    /* evaluate the real gain setting */
/*MT6139E*/    agcptr = AGC_TABLE[rf_band];
/*MT6139E*/    if( request_gain < agcptr->pos_gain )
/*MT6139E*/    {  agcptr++;
/*MT6139E*/    }
/*MT6139E*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6139E*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6139E*/       setting   = agcptr->setting + (bit_no<<4);
/*MT6139E*/    }
/*MT6139E*/
/*MT6139E*/    *gain_setting = setting;
/*MT6139E*/    return( real_gain );
/*MT6139E*/ }
/*MT6139E*/
#endif

#if IS_RF_MT6140A
/*MT6140A*/
/*MT6140A*/ #define  GAIN_STEP               2
/*MT6140A*/
/*MT6140A*/ #define  RF_GSM850_MAXGAIN      (  56.0*(PWRRES))
/*MT6140A*/ #define  RF_GSM850_MINGAIN      ( -32.0*(PWRRES))
/*MT6140A*/ #define  RF_GSM_MAXGAIN         (  56.0*(PWRRES))
/*MT6140A*/ #define  RF_GSM_MINGAIN         ( -32.0*(PWRRES))
/*MT6140A*/ #define  RF_DCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6140A*/ #define  RF_DCS_MINGAIN         ( -32.0*(PWRRES))
/*MT6140A*/ #define  RF_PCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6140A*/ #define  RF_PCS_MINGAIN         ( -32.0*(PWRRES))
/*MT6140A*/
/*MT6140A*/ /* GSM850....................................................................*/
/*MT6140A*/
/*MT6140A*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6140A*/ {  {  GBOUND( -4.0, -6.0 ), GC_A( 32, -4.0 ), 0x000C02 },
/*MT6140A*/    {  GBOUND(-44.0,-44.0 ), GC_A(  0,-44.0 ), 0x000C02 },
/*MT6140A*/ };
/*MT6140A*/
/*MT6140A*/ /* GSM900....................................................................*/
/*MT6140A*/
/*MT6140A*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6140A*/ {  {  GBOUND( -4.0, -6.0 ), GC_A( 32, -4.0 ), 0x000C02 },
/*MT6140A*/    {  GBOUND(-44.0,-44.0 ), GC_A(  0,-44.0 ), 0x000C02 },
/*MT6140A*/ };
/*MT6140A*/
/*MT6140A*/ /* DCS1800...................................................................*/
/*MT6140A*/
/*MT6140A*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6140A*/ {  {  GBOUND( -4.0, -6.0 ), GC_A( 32, -4.0 ), 0x000C02 },
/*MT6140A*/    {  GBOUND(-44.0,-44.0 ), GC_A(  0,-44.0 ), 0x000C02 },
/*MT6140A*/ };
/*MT6140A*/
/*MT6140A*/ /* PCS1900...................................................................*/
/*MT6140A*/
/*MT6140A*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6140A*/ {  {  GBOUND( -4.0, -6.0 ), GC_A( 32, -4.0 ), 0x000C02 },
/*MT6140A*/    {  GBOUND(-44.0,-44.0 ), GC_A(  0,-44.0 ), 0x000C02 },
/*MT6140A*/ };
/*MT6140A*/
/*MT6140A*/ /*...........................................................................*/
/*MT6140A*/
/*MT6140A*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6140A*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6140A*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6140A*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6140A*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6140A*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6140A*/ };
/*MT6140A*/
/*MT6140A*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6140A*/ {  0,                                              /*#FrequencyBand400  */
/*MT6140A*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6140A*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6140A*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6140A*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6140A*/ };
/*MT6140A*/
/*MT6140A*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6140A*/
/*MT6140A*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6140A*/ {  int   max_gain, min_gain, real_gain;
/*MT6140A*/    const int*    d32ptr;
/*MT6140A*/    const sL1DAGCDATA*  agcptr;
/*MT6140A*/    long  setting;
/*MT6140A*/    int   bit_no;
/*MT6140A*/
/*MT6140A*/    /* evaluate the range of available gain */
/*MT6140A*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6140A*/    max_gain = *d32ptr++;
/*MT6140A*/    min_gain = *d32ptr;
/*MT6140A*/
/*MT6140A*/    /* clipping the request gain to the avialable gain */
/*MT6140A*/    if( request_gain>=max_gain )
/*MT6140A*/    {  request_gain = max_gain;  }
/*MT6140A*/    else  if( request_gain<=min_gain )
/*MT6140A*/    {  request_gain = min_gain;  }
/*MT6140A*/
/*MT6140A*/    /* evaluate the real gain setting */
/*MT6140A*/    agcptr = AGC_TABLE[rf_band];
/*MT6140A*/    if( request_gain < agcptr->pos_gain )
/*MT6140A*/    {  agcptr++;
/*MT6140A*/    }
/*MT6140A*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6140A*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6140A*/       setting   = agcptr->setting + (bit_no<<4);
/*MT6140A*/    }
/*MT6140A*/
/*MT6140A*/    *gain_setting = setting;
/*MT6140A*/    return( real_gain );
/*MT6140A*/ }
/*MT6140A*/
#endif

#if IS_RF_MT6140B
/*MT6140B*/
/*MT6140B*/ #define  GAIN_STEP               2
/*MT6140B*/
/*MT6140B*/ #define  RF_GSM850_MAXGAIN      (  56.0*(PWRRES))
/*MT6140B*/ #define  RF_GSM850_MINGAIN      ( -30.0*(PWRRES))
/*MT6140B*/ #define  RF_GSM_MAXGAIN         (  56.0*(PWRRES))
/*MT6140B*/ #define  RF_GSM_MINGAIN         ( -30.0*(PWRRES))
/*MT6140B*/ #define  RF_DCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6140B*/ #define  RF_DCS_MINGAIN         ( -30.0*(PWRRES))
/*MT6140B*/ #define  RF_PCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6140B*/ #define  RF_PCS_MINGAIN         ( -30.0*(PWRRES))
/*MT6140B*/
/*MT6140B*/ /* GSM850....................................................................*/
/*MT6140B*/
/*MT6140B*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6140B*/ {  {  GBOUND( -4.0, -6.0 ), GC_A(  0, -4.0 ), 0x000202 },
/*MT6140B*/    {  GBOUND(-30.0,-30.0 ), GC_A(  6,-30.0 ), 0x000002 },
/*MT6140B*/ };
/*MT6140B*/
/*MT6140B*/ /* GSM900....................................................................*/
/*MT6140B*/
/*MT6140B*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6140B*/ {  {  GBOUND( -4.0, -6.0 ), GC_A(  0, -4.0 ), 0x000202 },
/*MT6140B*/    {  GBOUND(-30.0,-30.0 ), GC_A(  6,-30.0 ), 0x000002 },
/*MT6140B*/ };
/*MT6140B*/
/*MT6140B*/ /* DCS1800...................................................................*/
/*MT6140B*/
/*MT6140B*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6140B*/ {  {  GBOUND( -4.0, -6.0 ), GC_A(  0, -4.0 ), 0x000202 },
/*MT6140B*/    {  GBOUND(-30.0,-30.0 ), GC_A(  6,-30.0 ), 0x000002 },
/*MT6140B*/ };
/*MT6140B*/
/*MT6140B*/ /* PCS1900...................................................................*/
/*MT6140B*/
/*MT6140B*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6140B*/ {  {  GBOUND( -4.0, -6.0 ), GC_A(  0, -4.0 ), 0x000202 },
/*MT6140B*/    {  GBOUND(-30.0,-30.0 ), GC_A(  6,-30.0 ), 0x000002 },
/*MT6140B*/ };
/*MT6140B*/
/*MT6140B*/ /*...........................................................................*/
/*MT6140B*/
/*MT6140B*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6140B*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6140B*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6140B*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6140B*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6140B*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6140B*/ };
/*MT6140B*/
/*MT6140B*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6140B*/ {  0,                                              /*#FrequencyBand400  */
/*MT6140B*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6140B*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6140B*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6140B*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6140B*/ };
/*MT6140B*/
/*MT6140B*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6140B*/
/*MT6140B*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6140B*/ {  int   max_gain, min_gain, real_gain;
/*MT6140B*/    const int*    d32ptr;
/*MT6140B*/    const sL1DAGCDATA*  agcptr;
/*MT6140B*/    long  setting;
/*MT6140B*/    int   bit_no;
/*MT6140B*/
/*MT6140B*/    /* evaluate the range of available gain */
/*MT6140B*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6140B*/    max_gain = *d32ptr++;
/*MT6140B*/    min_gain = *d32ptr;
/*MT6140B*/
/*MT6140B*/    /* clipping the request gain to the avialable gain */
/*MT6140B*/    if( request_gain>=max_gain )
/*MT6140B*/    {  request_gain = max_gain;  }
/*MT6140B*/    else  if( request_gain<=min_gain )
/*MT6140B*/    {  request_gain = min_gain;  }
/*MT6140B*/
/*MT6140B*/    /* evaluate the real gain setting */
/*MT6140B*/    agcptr = AGC_TABLE[rf_band];
/*MT6140B*/    if( request_gain < agcptr->pos_gain )
/*MT6140B*/    {  agcptr++;
/*MT6140B*/    }
/*MT6140B*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6140B*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6140B*/       setting   = agcptr->setting + (bit_no<<4);
/*MT6140B*/    }
/*MT6140B*/
/*MT6140B*/    *gain_setting = setting;
/*MT6140B*/    return( real_gain );
/*MT6140B*/ }
/*MT6140B*/
#endif

#if IS_RF_MT6140C
/*MT6140C*/
/*MT6140C*/ #define  GAIN_STEP               2
/*MT6140C*/
/*MT6140C*/ #define  RF_GSM850_MAXGAIN      (  54.0*(PWRRES))
/*MT6140C*/ #define  RF_GSM850_MINGAIN      ( -30.0*(PWRRES))
/*MT6140C*/ #define  RF_GSM_MAXGAIN         (  54.0*(PWRRES))
/*MT6140C*/ #define  RF_GSM_MINGAIN         ( -30.0*(PWRRES))
/*MT6140C*/ #define  RF_DCS_MAXGAIN         (  54.0*(PWRRES))
/*MT6140C*/ #define  RF_DCS_MINGAIN         ( -32.0*(PWRRES))
/*MT6140C*/ #define  RF_PCS_MAXGAIN         (  54.0*(PWRRES))
/*MT6140C*/ #define  RF_PCS_MINGAIN         ( -32.0*(PWRRES))
/*MT6140C*/
/*MT6140C*/ /* GSM850....................................................................*/
/*MT6140C*/
/*MT6140C*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6140C*/ {  {  GBOUND( -6.0, -8.0 ), GC_A(  0, -6.0 ), 0x000202 },
/*MT6140C*/    {  GBOUND(-30.0,-30.0 ), GC_A(  6,-30.0 ), 0x000002 },
/*MT6140C*/ };
/*MT6140C*/
/*MT6140C*/ /* GSM900....................................................................*/
/*MT6140C*/
/*MT6140C*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6140C*/ {  {  GBOUND( -6.0, -8.0 ), GC_A(  0, -6.0 ), 0x000202 },
/*MT6140C*/    {  GBOUND(-30.0,-30.0 ), GC_A(  6,-30.0 ), 0x000002 },
/*MT6140C*/ };
/*MT6140C*/
/*MT6140C*/ /* DCS1800...................................................................*/
/*MT6140C*/
/*MT6140C*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6140C*/ {  {  GBOUND( -6.0, -8.0 ), GC_A(  0, -6.0 ), 0x000202 },
/*MT6140C*/    {  GBOUND(-30.0,-30.0 ), GC_A(  6,-30.0 ), 0x000002 },
/*MT6140C*/ };
/*MT6140C*/
/*MT6140C*/ /* PCS1900...................................................................*/
/*MT6140C*/
/*MT6140C*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6140C*/ {  {  GBOUND( -6.0, -8.0 ), GC_A(  0, -6.0 ), 0x000202 },
/*MT6140C*/    {  GBOUND(-30.0,-30.0 ), GC_A(  6,-30.0 ), 0x000002 },
/*MT6140C*/ };
/*MT6140C*/
/*MT6140C*/ /*...........................................................................*/
/*MT6140C*/
/*MT6140C*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6140C*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6140C*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6140C*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6140C*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6140C*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6140C*/ };
/*MT6140C*/
/*MT6140C*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6140C*/ {  0,                                              /*#FrequencyBand400  */
/*MT6140C*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6140C*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6140C*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6140C*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6140C*/ };
/*MT6140C*/
/*MT6140C*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6140C*/
/*MT6140C*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6140C*/ {  int   max_gain, min_gain, real_gain;
/*MT6140C*/    const int*    d32ptr;
/*MT6140C*/    const sL1DAGCDATA*  agcptr;
/*MT6140C*/    long  setting;
/*MT6140C*/    int   bit_no;
/*MT6140C*/
/*MT6140C*/    /* evaluate the range of available gain */
/*MT6140C*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6140C*/    max_gain = *d32ptr++;
/*MT6140C*/    min_gain = *d32ptr;
/*MT6140C*/
/*MT6140C*/    /* clipping the request gain to the avialable gain */
/*MT6140C*/    if( request_gain>=max_gain )
/*MT6140C*/    {  request_gain = max_gain;  }
/*MT6140C*/    else  if( request_gain<=min_gain )
/*MT6140C*/    {  request_gain = min_gain;  }
/*MT6140C*/
/*MT6140C*/    /* evaluate the real gain setting */
/*MT6140C*/    agcptr = AGC_TABLE[rf_band];
/*MT6140C*/    if( request_gain < agcptr->pos_gain )
/*MT6140C*/    {  agcptr++;
/*MT6140C*/    }
/*MT6140C*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6140C*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6140C*/       setting   = agcptr->setting + (bit_no<<4);
/*MT6140C*/    }
/*MT6140C*/
/*MT6140C*/    *gain_setting = setting;
/*MT6140C*/    return( real_gain );
/*MT6140C*/ }
/*MT6140C*/
#endif

#if IS_RF_MT6140D
/*MT6140D*/
/*MT6140D*/ #define  GAIN_STEP               2
/*MT6140D*/ #define  PVOFSL                 34
/*MT6140D*/ #define  PVOFSH                 34
/*MT6140D*/ #define  RF_GSM850_MAXGAIN      (( 90-PVOFSL )*(PWRRES))
/*MT6140D*/ #define  RF_GSM850_MINGAIN      ((  6-PVOFSL )*(PWRRES))
/*MT6140D*/ #define  RF_GSM_MAXGAIN         (( 90-PVOFSL )*(PWRRES))
/*MT6140D*/ #define  RF_GSM_MINGAIN         ((  6-PVOFSL )*(PWRRES))
/*MT6140D*/ #define  RF_DCS_MAXGAIN         (( 88-PVOFSH )*(PWRRES))
/*MT6140D*/ #define  RF_DCS_MINGAIN         ((  2-PVOFSH )*(PWRRES))
/*MT6140D*/ #define  RF_PCS_MAXGAIN         (( 88-PVOFSH )*(PWRRES))
/*MT6140D*/ #define  RF_PCS_MINGAIN         ((  2-PVOFSH )*(PWRRES))
/*MT6140D*/
/*MT6140D*/ /* GSM850....................................................................*/
/*MT6140D*/
/*MT6140D*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6140D*/ {  {  GBOUND(( 30-PVOFSL ),( 28-PVOFSL ) ), GC_A( 0,( 30-PVOFSL ) ), 0x000202 },
/*MT6140D*/    {  GBOUND((  4-PVOFSL ),(  4-PVOFSL ) ), GC_A( 5,(  4-PVOFSL ) ), 0x000002 },
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ /* GSM900....................................................................*/
/*MT6140D*/
/*MT6140D*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6140D*/ {  {  GBOUND(( 30-PVOFSL ),( 28-PVOFSL ) ), GC_A( 0,( 30-PVOFSL ) ), 0x000202 },
/*MT6140D*/    {  GBOUND((  4-PVOFSL ),(  4-PVOFSL ) ), GC_A( 5,(  4-PVOFSL ) ), 0x000002 },
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ /* DCS1800...................................................................*/
/*MT6140D*/
/*MT6140D*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6140D*/ {  {  GBOUND(( 28-PVOFSH ),( 26-PVOFSH ) ), GC_A( 0,( 28-PVOFSH ) ), 0x000202 },
/*MT6140D*/    {  GBOUND((  2-PVOFSH ),(  2-PVOFSH ) ), GC_A( 6,(  2-PVOFSH ) ), 0x000002 },
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ /* PCS1900...................................................................*/
/*MT6140D*/
/*MT6140D*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6140D*/ {  {  GBOUND(( 28-PVOFSH ),( 26-PVOFSH ) ), GC_A( 0,( 28-PVOFSH ) ), 0x000202 },
/*MT6140D*/    {  GBOUND((  2-PVOFSH ),(  2-PVOFSH ) ), GC_A( 6,(  2-PVOFSH ) ), 0x000002 },
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ /*...........................................................................*/
/*MT6140D*/
/*MT6140D*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6140D*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6140D*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6140D*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6140D*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6140D*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6140D*/ {  0,                                              /*#FrequencyBand400  */
/*MT6140D*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6140D*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6140D*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6140D*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6140D*/
/*MT6140D*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6140D*/ {  int   max_gain, min_gain, real_gain;
/*MT6140D*/    const int*    d32ptr;
/*MT6140D*/    const sL1DAGCDATA*  agcptr;
/*MT6140D*/    long  setting;
/*MT6140D*/    int   bit_no;
/*MT6140D*/
/*MT6140D*/    /* evaluate the range of available gain */
/*MT6140D*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6140D*/    max_gain = *d32ptr++;
/*MT6140D*/    min_gain = *d32ptr;
/*MT6140D*/
/*MT6140D*/    /* clipping the request gain to the avialable gain */
/*MT6140D*/    if( request_gain>=max_gain )
/*MT6140D*/    {  request_gain = max_gain;  }
/*MT6140D*/    else  if( request_gain<=min_gain )
/*MT6140D*/    {  request_gain = min_gain;  }
/*MT6140D*/
/*MT6140D*/    /* evaluate the real gain setting */
/*MT6140D*/    agcptr = AGC_TABLE[rf_band];
/*MT6140D*/    if( request_gain < agcptr->pos_gain )
/*MT6140D*/    {  agcptr++;
/*MT6140D*/    }
/*MT6140D*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6140D*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6140D*/       setting   = agcptr->setting + (bit_no<<4);
/*MT6140D*/    }
/*MT6140D*/
/*MT6140D*/    *gain_setting = setting;
/*MT6140D*/    return( real_gain );
/*MT6140D*/ }
/*MT6140D*/
#endif

#if IS_RF_CMOSEDGE
/*CMOSEDGE*/
/*CMOSEDGE*/ #define  GAIN_STEP               2
/*CMOSEDGE*/ #define  PVOFSL                 38
/*CMOSEDGE*/ #define  PVOFSH                 38
/*CMOSEDGE*/ #define  RF_GSM850_MAXGAIN      (( 96-PVOFSL )*(PWRRES))
/*CMOSEDGE*/ #define  RF_GSM850_MINGAIN      (( 10-PVOFSL )*(PWRRES))
/*CMOSEDGE*/ #define  RF_GSM_MAXGAIN         (( 96-PVOFSL )*(PWRRES))
/*CMOSEDGE*/ #define  RF_GSM_MINGAIN         (( 10-PVOFSL )*(PWRRES))
/*CMOSEDGE*/ #define  RF_DCS_MAXGAIN         (( 96-PVOFSH )*(PWRRES))
/*CMOSEDGE*/ #define  RF_DCS_MINGAIN         (( 10-PVOFSH )*(PWRRES))
/*CMOSEDGE*/ #define  RF_PCS_MAXGAIN         (( 96-PVOFSH )*(PWRRES))
/*CMOSEDGE*/ #define  RF_PCS_MINGAIN         (( 10-PVOFSH )*(PWRRES))
/*CMOSEDGE*/
/*CMOSEDGE*/ /* GSM850....................................................................*/
/*CMOSEDGE*/
/*CMOSEDGE*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*CMOSEDGE*/ {  {  GBOUND(( 36-PVOFSL ),( 34-PVOFSL ) ), GC_A( 0,( 36-PVOFSL ) ), 0x0400020 },
/*CMOSEDGE*/    {  GBOUND(( 10-PVOFSL ),( 10-PVOFSL ) ), GC_A( 0,( 10-PVOFSL ) ), 0x0400000 },
/*CMOSEDGE*/ };
/*CMOSEDGE*/
/*CMOSEDGE*/ /* GSM900....................................................................*/
/*CMOSEDGE*/
/*CMOSEDGE*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*CMOSEDGE*/ {  {  GBOUND(( 36-PVOFSL ),( 34-PVOFSL ) ), GC_A( 0,( 36-PVOFSL ) ), 0x0400020 },
/*CMOSEDGE*/    {  GBOUND(( 10-PVOFSL ),( 10-PVOFSL ) ), GC_A( 0,( 10-PVOFSL ) ), 0x0400000 },
/*CMOSEDGE*/ };
/*CMOSEDGE*/
/*CMOSEDGE*/ /* DCS1800...................................................................*/
/*CMOSEDGE*/
/*CMOSEDGE*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*CMOSEDGE*/ {  {  GBOUND(( 36-PVOFSL ),( 34-PVOFSL ) ), GC_A( 0,( 36-PVOFSL ) ), 0x0400020 },
/*CMOSEDGE*/    {  GBOUND(( 10-PVOFSL ),( 10-PVOFSL ) ), GC_A( 0,( 10-PVOFSL ) ), 0x0400000 },
/*CMOSEDGE*/ };
/*CMOSEDGE*/
/*CMOSEDGE*/ /* PCS1900...................................................................*/
/*CMOSEDGE*/
/*CMOSEDGE*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*CMOSEDGE*/ {  {  GBOUND(( 36-PVOFSL ),( 34-PVOFSL ) ), GC_A( 0,( 36-PVOFSL ) ), 0x0400020 },
/*CMOSEDGE*/    {  GBOUND(( 10-PVOFSL ),( 10-PVOFSL ) ), GC_A( 0,( 10-PVOFSL ) ), 0x0400000 },
/*CMOSEDGE*/ };
/*CMOSEDGE*/
/*CMOSEDGE*/ /*...........................................................................*/
/*CMOSEDGE*/
/*CMOSEDGE*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*CMOSEDGE*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*CMOSEDGE*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*CMOSEDGE*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*CMOSEDGE*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*CMOSEDGE*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*CMOSEDGE*/ };
/*CMOSEDGE*/
/*CMOSEDGE*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*CMOSEDGE*/ {  0,                                              /*#FrequencyBand400  */
/*CMOSEDGE*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*CMOSEDGE*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*CMOSEDGE*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*CMOSEDGE*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*CMOSEDGE*/ };
/*CMOSEDGE*/
/*CMOSEDGE*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*CMOSEDGE*/
/*CMOSEDGE*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*CMOSEDGE*/ {  int   max_gain, min_gain, real_gain;
/*CMOSEDGE*/    const int*    d32ptr;
/*CMOSEDGE*/    const sL1DAGCDATA*  agcptr;
/*CMOSEDGE*/    long  setting;
/*CMOSEDGE*/    int   bit_no;
/*CMOSEDGE*/
/*CMOSEDGE*/    /* evaluate the range of available gain */
/*CMOSEDGE*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*CMOSEDGE*/    max_gain = *d32ptr++;
/*CMOSEDGE*/    min_gain = *d32ptr;
/*CMOSEDGE*/
/*CMOSEDGE*/    /* clipping the request gain to the avialable gain */
/*CMOSEDGE*/    if( request_gain>=max_gain )
/*CMOSEDGE*/    {  request_gain = max_gain;  }
/*CMOSEDGE*/    else  if( request_gain<=min_gain )
/*CMOSEDGE*/    {  request_gain = min_gain;  }
/*CMOSEDGE*/
/*CMOSEDGE*/    /* evaluate the real gain setting */
/*CMOSEDGE*/    agcptr = AGC_TABLE[rf_band];
/*CMOSEDGE*/    if( request_gain < agcptr->pos_gain )
/*CMOSEDGE*/    {  agcptr++;
/*CMOSEDGE*/    }
/*CMOSEDGE*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*CMOSEDGE*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*CMOSEDGE*/       setting   = agcptr->setting + bit_no;
/*CMOSEDGE*/    }
/*CMOSEDGE*/
/*CMOSEDGE*/    *gain_setting = setting;
/*CMOSEDGE*/    return( real_gain );
/*CMOSEDGE*/ }
/*CMOSEDGE*/
#endif

#if IS_RF_MTKSOC1T
/*MTKSOC1T*/
/*MTKSOC1T*/ #define  GAIN_STEP               2
/*MTKSOC1T*/ #define  PVOFSL                  39
/*MTKSOC1T*/ #define  PVOFSH                  39
/*MTKSOC1T*/ #define  RF_GSM850_MAXGAIN      (( 98-PVOFSL )*(PWRRES))
/*MTKSOC1T*/ #define  RF_GSM850_MINGAIN      (( 12-PVOFSL )*(PWRRES))
/*MTKSOC1T*/ #define  RF_GSM_MAXGAIN         (( 98-PVOFSL )*(PWRRES))
/*MTKSOC1T*/ #define  RF_GSM_MINGAIN         (( 12-PVOFSL )*(PWRRES))
/*MTKSOC1T*/ #define  RF_DCS_MAXGAIN         (( 98-PVOFSH )*(PWRRES))
/*MTKSOC1T*/ #define  RF_DCS_MINGAIN         (( 12-PVOFSH )*(PWRRES))
/*MTKSOC1T*/ #define  RF_PCS_MAXGAIN         (( 98-PVOFSH )*(PWRRES))
/*MTKSOC1T*/ #define  RF_PCS_MINGAIN         (( 12-PVOFSH )*(PWRRES))
/*MTKSOC1T*/
/*MTKSOC1T*/ /* GSM850....................................................................*/
/*MTKSOC1T*/
/*MTKSOC1T*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MTKSOC1T*/ {  {  GBOUND(( 38-PVOFSL ),( 36-PVOFSL ) ), GC_A( 0,( 38-PVOFSL ) ), 0x0400020 },
/*MTKSOC1T*/    {  GBOUND(( 12-PVOFSL ),( 12-PVOFSL ) ), GC_A( 0,( 12-PVOFSL ) ), 0x0400000 },
/*MTKSOC1T*/ };
/*MTKSOC1T*/
/*MTKSOC1T*/ /* GSM900....................................................................*/
/*MTKSOC1T*/
/*MTKSOC1T*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MTKSOC1T*/ {  {  GBOUND(( 38-PVOFSL ),( 36-PVOFSL ) ), GC_A( 0,( 38-PVOFSL ) ), 0x0400020 },
/*MTKSOC1T*/    {  GBOUND(( 12-PVOFSL ),( 12-PVOFSL ) ), GC_A( 0,( 12-PVOFSL ) ), 0x0400000 },
/*MTKSOC1T*/ };
/*MTKSOC1T*/
/*MTKSOC1T*/ /* DCS1800...................................................................*/
/*MTKSOC1T*/
/*MTKSOC1T*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MTKSOC1T*/ {  {  GBOUND(( 38-PVOFSL ),( 36-PVOFSL ) ), GC_A( 0,( 38-PVOFSL ) ), 0x0400020 },
/*MTKSOC1T*/    {  GBOUND(( 12-PVOFSL ),( 12-PVOFSL ) ), GC_A( 0,( 12-PVOFSL ) ), 0x0400000 },
/*MTKSOC1T*/ };
/*MTKSOC1T*/
/*MTKSOC1T*/ /* PCS1900...................................................................*/
/*MTKSOC1T*/
/*MTKSOC1T*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MTKSOC1T*/ {  {  GBOUND(( 38-PVOFSL ),( 36-PVOFSL ) ), GC_A( 0,( 38-PVOFSL ) ), 0x0400020 },
/*MTKSOC1T*/    {  GBOUND(( 12-PVOFSL ),( 12-PVOFSL ) ), GC_A( 0,( 12-PVOFSL ) ), 0x0400000 },
/*MTKSOC1T*/ };
/*MTKSOC1T*/
/*MTKSOC1T*/ /*...........................................................................*/
/*MTKSOC1T*/
/*MTKSOC1T*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MTKSOC1T*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MTKSOC1T*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MTKSOC1T*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MTKSOC1T*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MTKSOC1T*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MTKSOC1T*/ };
/*MTKSOC1T*/
/*MTKSOC1T*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MTKSOC1T*/ {  0,                                              /*#FrequencyBand400  */
/*MTKSOC1T*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MTKSOC1T*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MTKSOC1T*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MTKSOC1T*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MTKSOC1T*/ };
/*MTKSOC1T*/
/*MTKSOC1T*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MTKSOC1T*/
/*MTKSOC1T*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MTKSOC1T*/ {  int   max_gain, min_gain, real_gain;
/*MTKSOC1T*/    const int*    d32ptr;
/*MTKSOC1T*/    const sL1DAGCDATA*  agcptr;
/*MTKSOC1T*/    long  setting;
/*MTKSOC1T*/    int   bit_no;
/*MTKSOC1T*/
/*MTKSOC1T*/    /* evaluate the range of available gain */
/*MTKSOC1T*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MTKSOC1T*/    max_gain = *d32ptr++;
/*MTKSOC1T*/    min_gain = *d32ptr;
/*MTKSOC1T*/
/*MTKSOC1T*/    /* clipping the request gain to the avialable gain */
/*MTKSOC1T*/    if( request_gain>=max_gain )
/*MTKSOC1T*/    {  request_gain = max_gain;  }
/*MTKSOC1T*/    else  if( request_gain<=min_gain )
/*MTKSOC1T*/    {  request_gain = min_gain;  }
/*MTKSOC1T*/
/*MTKSOC1T*/    /* evaluate the real gain setting */
/*MTKSOC1T*/    agcptr = AGC_TABLE[rf_band];
/*MTKSOC1T*/    if( request_gain < agcptr->pos_gain )
/*MTKSOC1T*/    {  agcptr++;
/*MTKSOC1T*/    }
/*MTKSOC1T*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MTKSOC1T*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MTKSOC1T*/       setting   = agcptr->setting + bit_no;
/*MTKSOC1T*/    }
/*MTKSOC1T*/
/*MTKSOC1T*/    *gain_setting = setting;
/*MTKSOC1T*/    return( real_gain );
/*MTKSOC1T*/ }
/*MTKSOC1T*/
#endif

#if IS_RF_MTKSOC1
/*MTKSOC1*/
/*MTKSOC1*/ #define  GAIN_STEP               2
/*MTKSOC1*/ #define  PVOFSL                  39
/*MTKSOC1*/ #define  PVOFSH                  39
/*MTKSOC1*/ #define  RF_GSM850_MAXGAIN      (( 94-PVOFSL )*(PWRRES))
/*MTKSOC1*/ #define  RF_GSM850_MINGAIN      (( 14-PVOFSL )*(PWRRES))
/*MTKSOC1*/ #define  RF_GSM_MAXGAIN         (( 94-PVOFSL )*(PWRRES))
/*MTKSOC1*/ #define  RF_GSM_MINGAIN         (( 14-PVOFSL )*(PWRRES))
/*MTKSOC1*/ #define  RF_DCS_MAXGAIN         (( 94-PVOFSH )*(PWRRES))
/*MTKSOC1*/ #define  RF_DCS_MINGAIN         (( 14-PVOFSH )*(PWRRES))
/*MTKSOC1*/ #define  RF_PCS_MAXGAIN         (( 94-PVOFSH )*(PWRRES))
/*MTKSOC1*/ #define  RF_PCS_MINGAIN         (( 14-PVOFSH )*(PWRRES))
/*MTKSOC1*/
/*MTKSOC1*/ /* GSM850....................................................................*/
/*MTKSOC1*/
/*MTKSOC1*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MTKSOC1*/ {  {  GBOUND(( 40-PVOFSL ),( 38-PVOFSL ) ), GC_A(  0,( 40-PVOFSL ) ), 0x0400020 },
/*MTKSOC1*/    {  GBOUND(( 14-PVOFSL ),( 14-PVOFSL ) ), GC_A(  0,( 14-PVOFSL ) ), 0x0400000 },
/*MTKSOC1*/ };
/*MTKSOC1*/
/*MTKSOC1*/ /* GSM900....................................................................*/
/*MTKSOC1*/
/*MTKSOC1*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MTKSOC1*/ {  {  GBOUND(( 40-PVOFSL ),( 38-PVOFSL ) ), GC_A(  0,( 40-PVOFSL ) ), 0x0400020 },
/*MTKSOC1*/    {  GBOUND(( 14-PVOFSL ),( 14-PVOFSL ) ), GC_A(  0,( 14-PVOFSL ) ), 0x0400000 },
/*MTKSOC1*/ };
/*MTKSOC1*/
/*MTKSOC1*/ /* DCS1800...................................................................*/
/*MTKSOC1*/
/*MTKSOC1*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MTKSOC1*/ {  {  GBOUND(( 40-PVOFSL ),( 38-PVOFSL ) ), GC_A(  0,( 40-PVOFSL ) ), 0x0400020 },
/*MTKSOC1*/    {  GBOUND(( 14-PVOFSL ),( 14-PVOFSL ) ), GC_A(  0,( 14-PVOFSL ) ), 0x0400000 },
/*MTKSOC1*/ };
/*MTKSOC1*/
/*MTKSOC1*/ /* PCS1900...................................................................*/
/*MTKSOC1*/
/*MTKSOC1*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MTKSOC1*/ {  {  GBOUND(( 40-PVOFSL ),( 38-PVOFSL ) ), GC_A(  0,( 40-PVOFSL ) ), 0x0400020 },
/*MTKSOC1*/    {  GBOUND(( 14-PVOFSL ),( 14-PVOFSL ) ), GC_A(  0,( 14-PVOFSL ) ), 0x0400000 },
/*MTKSOC1*/ };
/*MTKSOC1*/
/*MTKSOC1*/ /*...........................................................................*/
/*MTKSOC1*/
/*MTKSOC1*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MTKSOC1*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MTKSOC1*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MTKSOC1*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MTKSOC1*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MTKSOC1*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MTKSOC1*/ };
/*MTKSOC1*/
/*MTKSOC1*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MTKSOC1*/ {  0,                                              /*#FrequencyBand400  */
/*MTKSOC1*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MTKSOC1*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MTKSOC1*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MTKSOC1*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MTKSOC1*/ };
/*MTKSOC1*/
/*MTKSOC1*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MTKSOC1*/
/*MTKSOC1*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MTKSOC1*/ {  int   max_gain, min_gain, real_gain;
/*MTKSOC1*/    const int*    d32ptr;
/*MTKSOC1*/    const sL1DAGCDATA*  agcptr;
/*MTKSOC1*/    long  setting;
/*MTKSOC1*/    int   bit_no;
/*MTKSOC1*/
/*MTKSOC1*/    /* evaluate the range of available gain */
/*MTKSOC1*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MTKSOC1*/    max_gain = *d32ptr++;
/*MTKSOC1*/    min_gain = *d32ptr;
/*MTKSOC1*/
/*MTKSOC1*/    /* clipping the request gain to the avialable gain */
/*MTKSOC1*/    if( request_gain>=max_gain )
/*MTKSOC1*/    {  request_gain = max_gain;  }
/*MTKSOC1*/    else  if( request_gain<=min_gain )
/*MTKSOC1*/    {  request_gain = min_gain;  }
/*MTKSOC1*/
/*MTKSOC1*/    /* evaluate the real gain setting */
/*MTKSOC1*/    agcptr = AGC_TABLE[rf_band];
/*MTKSOC1*/    if( request_gain < agcptr->pos_gain )
/*MTKSOC1*/    {  agcptr++;
/*MTKSOC1*/    }
/*MTKSOC1*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MTKSOC1*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MTKSOC1*/       setting   = agcptr->setting + bit_no;
/*MTKSOC1*/    }
/*MTKSOC1*/
/*MTKSOC1*/    *gain_setting = setting;
/*MTKSOC1*/    return( real_gain );
/*MTKSOC1*/ }
/*MTKSOC1*/
#endif

#if IS_RF_MT6252RF
/*MT6252RF*/
/*MT6252RF*/ #define  GAIN_STEP               2
/*MT6252RF*/ #define  PVOFSL                  39
/*MT6252RF*/ #define  PVOFSH                  39
/*MT6252RF*/ #define  RF_GSM850_MAXGAIN      (( 96-PVOFSL )*(PWRRES))
/*MT6252RF*/ #define  RF_GSM850_MINGAIN      (( 16-PVOFSL )*(PWRRES))
/*MT6252RF*/ #define  RF_GSM_MAXGAIN         (( 96-PVOFSL )*(PWRRES))
/*MT6252RF*/ #define  RF_GSM_MINGAIN         (( 16-PVOFSL )*(PWRRES))
/*MT6252RF*/ #define  RF_DCS_MAXGAIN         (( 96-PVOFSH )*(PWRRES))
/*MT6252RF*/ #define  RF_DCS_MINGAIN         (( 16-PVOFSH )*(PWRRES))
/*MT6252RF*/ #define  RF_PCS_MAXGAIN         (( 96-PVOFSH )*(PWRRES))
/*MT6252RF*/ #define  RF_PCS_MINGAIN         (( 16-PVOFSH )*(PWRRES))
/*MT6252RF*/
/*MT6252RF*/ /* GSM850....................................................................*/
/*MT6252RF*/
/*MT6252RF*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6252RF*/ {  {  GBOUND(( 42-PVOFSL ),( 40-PVOFSL ) ), GC_A( 0, ( 42-PVOFSL ) ), 0x6000020 },
/*MT6252RF*/    {  GBOUND(( 16-PVOFSL ),( 16-PVOFSL ) ), GC_A( 0, ( 16-PVOFSL ) ), 0x6000000 },
/*MT6252RF*/ };
/*MT6252RF*/
/*MT6252RF*/ /* GSM900....................................................................*/
/*MT6252RF*/
/*MT6252RF*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6252RF*/ {  {  GBOUND(( 42-PVOFSL ),( 40-PVOFSL ) ), GC_A( 0, ( 42-PVOFSL ) ), 0x6000020 },
/*MT6252RF*/    {  GBOUND(( 16-PVOFSL ),( 16-PVOFSL ) ), GC_A( 0, ( 16-PVOFSL ) ), 0x6000000 },
/*MT6252RF*/ };
/*MT6252RF*/
/*MT6252RF*/ /* DCS1800...................................................................*/
/*MT6252RF*/
/*MT6252RF*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6252RF*/ {  {  GBOUND(( 42-PVOFSL ),( 40-PVOFSL ) ), GC_A( 0, ( 42-PVOFSL ) ), 0x6000020 },
/*MT6252RF*/    {  GBOUND(( 16-PVOFSL ),( 16-PVOFSL ) ), GC_A( 0, ( 16-PVOFSL ) ), 0x6000000 },
/*MT6252RF*/ };
/*MT6252RF*/
/*MT6252RF*/ /* PCS1900...................................................................*/
/*MT6252RF*/
/*MT6252RF*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6252RF*/ {  {  GBOUND(( 42-PVOFSL ),( 40-PVOFSL ) ), GC_A( 0, ( 42-PVOFSL ) ), 0x6000020 },
/*MT6252RF*/    {  GBOUND(( 16-PVOFSL ),( 16-PVOFSL ) ), GC_A( 0, ( 16-PVOFSL ) ), 0x6000000 },
/*MT6252RF*/ };
/*MT6252RF*/
/*MT6252RF*/ /*...........................................................................*/
/*MT6252RF*/
/*MT6252RF*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6252RF*/ {  {                   0,                      0    }, /* FrequencyBand400  */
/*MT6252RF*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6252RF*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6252RF*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6252RF*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6252RF*/ };
/*MT6252RF*/
/*MT6252RF*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6252RF*/ {  0,                                                  /* FrequencyBand400  */
/*MT6252RF*/    AGC_TABLE_GSM850,                                   /* FrequencyBand850  */
/*MT6252RF*/    AGC_TABLE_GSM900,                                   /* FrequencyBand900  */
/*MT6252RF*/    AGC_TABLE_DCS1800,                                  /* FrequencyBand1800 */
/*MT6252RF*/    AGC_TABLE_PCS1900,                                  /* FrequencyBand1900 */
/*MT6252RF*/ };
/*MT6252RF*/
/*MT6252RF*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6252RF*/
/*MT6252RF*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6252RF*/ {  int   max_gain, min_gain, real_gain;
/*MT6252RF*/    const int*    d32ptr;
/*MT6252RF*/    const sL1DAGCDATA*  agcptr;
/*MT6252RF*/    long  setting;
/*MT6252RF*/    int   bit_no;
/*MT6252RF*/
/*MT6252RF*/    /* evaluate the range of available gain */
/*MT6252RF*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6252RF*/    max_gain = *d32ptr++;
/*MT6252RF*/    min_gain = *d32ptr;
/*MT6252RF*/
/*MT6252RF*/    /* clipping the request gain to the avialable gain */
/*MT6252RF*/    if( request_gain>=max_gain )
/*MT6252RF*/    {  request_gain = max_gain;  }
/*MT6252RF*/    else  if( request_gain<=min_gain )
/*MT6252RF*/    {  request_gain = min_gain;  }
/*MT6252RF*/
/*MT6252RF*/    /* evaluate the real gain setting */
/*MT6252RF*/    agcptr = AGC_TABLE[rf_band];
/*MT6252RF*/    if( request_gain < agcptr->pos_gain )
/*MT6252RF*/    {  agcptr++;
/*MT6252RF*/    }
/*MT6252RF*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6252RF*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6252RF*/       setting   = agcptr->setting + bit_no;
/*MT6252RF*/    }
/*MT6252RF*/
/*MT6252RF*/    *gain_setting = setting;
/*MT6252RF*/    return( real_gain );
/*MT6252RF*/ }
/*MT6252RF*/
#endif

#if IS_RF_MT6256RF
/*MT6256RF*/
/*MT6256RF*/ #define  GAIN_STEP               6
/*MT6256RF*/ #define  PVOFSL                  34
/*MT6256RF*/ #define  PVOFSH                  34
/*MT6256RF*/ #define  INSERTION_LOSS         (3*(PWRRES))  //Insertion loss is 3dB
/*MT6256RF*/ #define  RF_GSM850_MAXGAIN      (( 62-PVOFSL )*(PWRRES))
/*MT6256RF*/ #define  RF_GSM850_MINGAIN      ((  2-PVOFSL )*(PWRRES))
/*MT6256RF*/ #define  RF_GSM_MAXGAIN         (( 62-PVOFSL )*(PWRRES))
/*MT6256RF*/ #define  RF_GSM_MINGAIN         ((  2-PVOFSL )*(PWRRES))
/*MT6256RF*/ #define  RF_DCS_MAXGAIN         (( 62-PVOFSH )*(PWRRES))
/*MT6256RF*/ #define  RF_DCS_MINGAIN         ((  0-PVOFSH )*(PWRRES))
/*MT6256RF*/ #define  RF_PCS_MAXGAIN         (( 62-PVOFSH )*(PWRRES))
/*MT6256RF*/ #define  RF_PCS_MINGAIN         ((  0-PVOFSH )*(PWRRES))
/*MT6256RF*/
/*MT6256RF*/ /* GSM850....................................................................*/
/*MT6256RF*/
/*MT6256RF*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6256RF*/ {  {  GBOUND(( 32-PVOFSL ),( 26-PVOFSL ) ), GC_A( 0,( 32-PVOFSL ) ), BSI_CW(0x60, 0x40) },
/*MT6256RF*/    {  GBOUND((  0-PVOFSL ),(  0-PVOFSL ) ), GC_A( 0,(  2-PVOFSL ) ), BSI_CW(0x60, 0x00) },
/*MT6256RF*/ };
/*MT6256RF*/
/*MT6256RF*/ /* GSM900....................................................................*/
/*MT6256RF*/
/*MT6256RF*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6256RF*/ {  {  GBOUND(( 32-PVOFSL ),( 26-PVOFSL ) ), GC_A( 0,( 32-PVOFSL ) ), BSI_CW(0x60, 0x40) },
/*MT6256RF*/    {  GBOUND((  0-PVOFSL ),(  0-PVOFSL ) ), GC_A( 0,(  2-PVOFSL ) ), BSI_CW(0x60, 0x00) },
/*MT6256RF*/ };
/*MT6256RF*/
/*MT6256RF*/ /* DCS1800...................................................................*/
/*MT6256RF*/
/*MT6256RF*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6256RF*/ {  {  GBOUND(( 32-PVOFSL ),( 22-PVOFSL ) ), GC_A( 0,( 32-PVOFSL ) ), BSI_CW(0x60, 0x40) },
/*MT6256RF*/    {  GBOUND((  0-PVOFSL ),(  0-PVOFSL ) ), GC_A( 0,(  0-PVOFSL ) ), BSI_CW(0x60, 0x00) },
/*MT6256RF*/ };
/*MT6256RF*/
/*MT6256RF*/ /* PCS1900...................................................................*/
/*MT6256RF*/
/*MT6256RF*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6256RF*/ {  {  GBOUND(( 32-PVOFSL ),( 22-PVOFSL ) ), GC_A( 0,( 32-PVOFSL ) ), BSI_CW(0x60, 0x40) },
/*MT6256RF*/    {  GBOUND((  0-PVOFSL ),(  0-PVOFSL ) ), GC_A( 0,(  0-PVOFSL ) ), BSI_CW(0x60, 0x00) },
/*MT6256RF*/ };
/*MT6256RF*/
/*MT6256RF*/ /*...........................................................................*/
/*MT6256RF*/
/*MT6256RF*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6256RF*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6256RF*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6256RF*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6256RF*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6256RF*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6256RF*/ };
/*MT6256RF*/
/*MT6256RF*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6256RF*/ {  0,                                              /*#FrequencyBand400  */
/*MT6256RF*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6256RF*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6256RF*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6256RF*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6256RF*/ };
/*MT6256RF*/
/*MT6256RF*/ const  int  GAIN_STEP_TABLE[] =
/*MT6256RF*/ { 10, 18, 26, 34, 42, 45, 53 };   /* gain step for high/low LNA gain                */
/*MT6256RF*/                                   /* Low LNA gain  : { 10, 18, 26, 34, 42         } */
/*MT6256RF*/                                   /* High LNA gain : {     18, 26, 34, 42, 45, 53 } */
/*MT6256RF*/
/*MT6256RF*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6256RF*/
/*MT6256RF*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6256RF*/ {  int   max_gain, min_gain, real_gain;
/*MT6256RF*/    const int*    d32ptr;
/*MT6256RF*/    const sL1DAGCDATA*  agcptr;
/*MT6256RF*/    long  setting;
/*MT6256RF*/    int   bit_no, gain_step, idx_shift_value;
/*MT6256RF*/
/*MT6256RF*/    /* evaluate the range of available gain */
/*MT6256RF*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6256RF*/    max_gain = *d32ptr++;
/*MT6256RF*/    min_gain = *d32ptr;
/*MT6256RF*/
/*MT6256RF*/    /* clipping the request gain to the avialable gain */
/*MT6256RF*/    if( request_gain>=max_gain )
/*MT6256RF*/    {  request_gain = max_gain;  }
/*MT6256RF*/    else  if( request_gain<=min_gain )
/*MT6256RF*/    {  request_gain = min_gain;  }
/*MT6256RF*/
/*MT6256RF*/    /* evaluate the real gain setting */
/*MT6256RF*/    agcptr = AGC_TABLE[rf_band];
/*MT6256RF*/    idx_shift_value = 1;  //Since the lowest gain step of high LNA gain case is 18
/*MT6256RF*/    if( request_gain < agcptr->pos_gain )
/*MT6256RF*/    {  agcptr++;
/*MT6256RF*/       idx_shift_value = 0;
/*MT6256RF*/    }
/*MT6256RF*/    {
/*MT6256RF*/       bit_no = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6256RF*/       gain_step = GAIN_STEP_TABLE[bit_no+idx_shift_value];  //Use bit_no to choose gain step
/*MT6256RF*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B ) - INSERTION_LOSS;
/*MT6256RF*/       setting   = agcptr->setting + gain_step;
/*MT6256RF*/    }
/*MT6256RF*/
/*MT6256RF*/    *gain_setting = setting;
/*MT6256RF*/    return( real_gain );
/*MT6256RF*/ }
/*MT6256RF*/
   #if IS_W_CANCELLATION_SUPPORT
/*MT6256RF*/ unsigned short   L1D_RF_FindGainStep( unsigned long gain_setting, FrequencyBand rf_band )
/*MT6256RF*/ {
/*MT6256RF*/    int bit_value, shift_value;
/*MT6256RF*/    unsigned short left_idx, right_idx, mid_idx, idx;
/*MT6256RF*/
/*MT6256RF*/    shift_value = (gain_setting>>6) & 0x1;
/*MT6256RF*/    bit_value = gain_setting & 0x3F;
/*MT6256RF*/    left_idx = 0;
/*MT6256RF*/    right_idx = sizeof(GAIN_STEP_TABLE)/sizeof(int)-1;
/*MT6256RF*/
/*MT6256RF*/    while( left_idx < right_idx )
/*MT6256RF*/    {
/*MT6256RF*/       mid_idx = (left_idx + right_idx) >> 1;
/*MT6256RF*/
/*MT6256RF*/       if( bit_value <= GAIN_STEP_TABLE[mid_idx])
/*MT6256RF*/          right_idx = mid_idx;
/*MT6256RF*/       else
/*MT6256RF*/          left_idx = mid_idx + 1;
/*MT6256RF*/    }
/*MT6256RF*/
/*MT6256RF*/    idx = right_idx;
/*MT6256RF*/
/*MT6256RF*/    if( shift_value == 1 )
/*MT6256RF*/       return (idx + 4);
/*MT6256RF*/    else
/*MT6256RF*/       return (idx);
/*MT6256RF*/ }
/*MT6256RF*/
   #endif
#endif

#if IS_RF_MT6251RF || IS_RF_MT6255RF
/*MT6251RF*/
/*MT6251RF*/ #define  GAIN_STEP               6
/*MT6251RF*/ #define  PVOFSL                  34
/*MT6251RF*/ #define  PVOFSH                  34
   #if IS_RF_MT6255RF
/*MT6251RF*/ #define  INSERTION_LOSS         (2*(PWRRES))  //Insertion loss is 2dB
   #else
/*MT6251RF*/ #define  INSERTION_LOSS         (0*(PWRRES))  //Insertion loss is 0dB
   #endif
/*MT6251RF*/ #define  RF_GSM850_MAXGAIN      (( 62-PVOFSL )*(PWRRES))
/*MT6251RF*/ #define  RF_GSM850_MINGAIN      ((  0-PVOFSL )*(PWRRES))
/*MT6251RF*/ #define  RF_GSM_MAXGAIN         (( 62-PVOFSL )*(PWRRES))
/*MT6251RF*/ #define  RF_GSM_MINGAIN         ((  0-PVOFSL )*(PWRRES))
/*MT6251RF*/ #define  RF_DCS_MAXGAIN         (( 62-PVOFSH )*(PWRRES))
/*MT6251RF*/ #define  RF_DCS_MINGAIN         ((  0-PVOFSH )*(PWRRES))
/*MT6251RF*/ #define  RF_PCS_MAXGAIN         (( 62-PVOFSH )*(PWRRES))
/*MT6251RF*/ #define  RF_PCS_MINGAIN         ((  0-PVOFSH )*(PWRRES))
/*MT6251RF*/
/*MT6251RF*/ /* GSM850....................................................................*/
/*MT6251RF*/
/*MT6251RF*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6251RF*/ {  {  GBOUND(( 32-PVOFSL ),( 22-PVOFSL ) ), GC_A( 0,( 32-PVOFSL ) ), 0x6000040 },
/*MT6251RF*/    {  GBOUND((  0-PVOFSL ),(  0-PVOFSL ) ), GC_A( 0,(  0-PVOFSL ) ), 0x6000000 },
/*MT6251RF*/ };
/*MT6251RF*/
/*MT6251RF*/ /* GSM900....................................................................*/
/*MT6251RF*/
/*MT6251RF*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6251RF*/ {  {  GBOUND(( 32-PVOFSL ),( 22-PVOFSL ) ), GC_A( 0,( 32-PVOFSL ) ), 0x6000040 },
/*MT6251RF*/    {  GBOUND((  0-PVOFSL ),(  0-PVOFSL ) ), GC_A( 0,(  0-PVOFSL ) ), 0x6000000 },
/*MT6251RF*/ };
/*MT6251RF*/
/*MT6251RF*/ /* DCS1800...................................................................*/
/*MT6251RF*/
/*MT6251RF*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6251RF*/ {  {  GBOUND(( 32-PVOFSL ),( 22-PVOFSL ) ), GC_A( 0,( 32-PVOFSL ) ), 0x6000040 },
/*MT6251RF*/    {  GBOUND((  0-PVOFSL ),(  0-PVOFSL ) ), GC_A( 0,(  0-PVOFSL ) ), 0x6000000 },
/*MT6251RF*/ };
/*MT6251RF*/
/*MT6251RF*/ /* PCS1900...................................................................*/
/*MT6251RF*/
/*MT6251RF*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6251RF*/ {  {  GBOUND(( 32-PVOFSL ),( 22-PVOFSL ) ), GC_A( 0,( 32-PVOFSL ) ), 0x6000040 },
/*MT6251RF*/    {  GBOUND((  0-PVOFSL ),(  0-PVOFSL ) ), GC_A( 0,(  0-PVOFSL ) ), 0x6000000 },
/*MT6251RF*/ };
/*MT6251RF*/
/*MT6251RF*/ /*...........................................................................*/
/*MT6251RF*/
/*MT6251RF*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6251RF*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6251RF*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6251RF*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6251RF*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6251RF*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6251RF*/ };
/*MT6251RF*/
/*MT6251RF*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6251RF*/ {  0,                                              /*#FrequencyBand400  */
/*MT6251RF*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6251RF*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6251RF*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6251RF*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6251RF*/ };
/*MT6251RF*/
/*MT6251RF*/ const  int  GAIN_STEP_TABLE[] =
/*MT6251RF*/ { 10, 18, 26, 34, 42, 45, 53 };   //gain step for high/low LNA gain
/*MT6251RF*/                                   //Low LNA gain  : { 10, 18, 26, 34, 42         }
/*MT6251RF*/                                   //High LNA gain : {     18, 26, 34, 42, 45, 53 }
/*MT6251RF*/
/*MT6251RF*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6251RF*/
/*MT6251RF*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6251RF*/ {  int   max_gain, min_gain, real_gain;
/*MT6251RF*/    const int*    d32ptr;
/*MT6251RF*/    const sL1DAGCDATA*  agcptr;
/*MT6251RF*/    long  setting;
/*MT6251RF*/    int   bit_no, gain_step, idx_shift_value;
/*MT6251RF*/
/*MT6251RF*/    /* evaluate the range of available gain */
/*MT6251RF*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6251RF*/    max_gain = *d32ptr++;
/*MT6251RF*/    min_gain = *d32ptr;
/*MT6251RF*/
/*MT6251RF*/    /* clipping the request gain to the avialable gain */
/*MT6251RF*/    if( request_gain>=max_gain )
/*MT6251RF*/    {  request_gain = max_gain;  }
/*MT6251RF*/    else  if( request_gain<=min_gain )
/*MT6251RF*/    {  request_gain = min_gain;  }
/*MT6251RF*/
/*MT6251RF*/    /* evaluate the real gain setting */
/*MT6251RF*/    agcptr = AGC_TABLE[rf_band];
/*MT6251RF*/    idx_shift_value = 1;  //the lowest gain step of high LNA gain case is 18
/*MT6251RF*/    if( request_gain < agcptr->pos_gain )
/*MT6251RF*/    {  agcptr++;
/*MT6251RF*/       idx_shift_value = 0;
/*MT6251RF*/    }
/*MT6251RF*/    {
/*MT6251RF*/       bit_no = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6251RF*/       gain_step = GAIN_STEP_TABLE[bit_no+idx_shift_value];  //Use bit_no to choose gain step
/*MT6251RF*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B ) - INSERTION_LOSS;
/*MT6251RF*/       setting   = agcptr->setting + gain_step;
/*MT6251RF*/       if( gain_step == 10 )
/*MT6251RF*/       {
/*MT6251RF*/          setting += 128;              // The LNA setting of the lowest gain is 10, not 00
/*MT6251RF*/          real_gain = -259;            // The real gain of lowest gain has 1.6dB offset, (-34+1.6)*8=-259
/*MT6251RF*/       }
/*MT6251RF*/    }
/*MT6251RF*/
/*MT6251RF*/    *gain_setting = setting;
/*MT6251RF*/    return( real_gain );
/*MT6251RF*/ }
/*MT6251RF*/
   #if IS_W_CANCELLATION_SUPPORT
/*MT6251RF*/ unsigned short   L1D_RF_FindGainStep( unsigned long gain_setting, FrequencyBand rf_band )
/*MT6251RF*/ {
/*MT6251RF*/    int bit_value, shift_value;
/*MT6251RF*/    unsigned short left_idx, right_idx, mid_idx, idx;
/*MT6251RF*/
/*MT6251RF*/    shift_value = (gain_setting>>6) & 0x1;
/*MT6251RF*/    bit_value = gain_setting & 0x3F;
/*MT6251RF*/    left_idx = 0;
/*MT6251RF*/    right_idx = sizeof(GAIN_STEP_TABLE)/sizeof(int)-1;
/*MT6251RF*/
/*MT6251RF*/    while( left_idx < right_idx )
/*MT6251RF*/    {
/*MT6251RF*/       mid_idx = (left_idx + right_idx) >> 1;
/*MT6251RF*/
/*MT6251RF*/       if( bit_value <= GAIN_STEP_TABLE[mid_idx])
/*MT6251RF*/          right_idx = mid_idx;
/*MT6251RF*/       else
/*MT6251RF*/          left_idx = mid_idx + 1;
/*MT6251RF*/    }
/*MT6251RF*/
/*MT6251RF*/    idx = right_idx;
/*MT6251RF*/
/*MT6251RF*/    if( shift_value == 1 )
/*MT6251RF*/       return (idx + 4);
/*MT6251RF*/    else
/*MT6251RF*/       return (idx);
/*MT6251RF*/ }
/*MT6251RF*/
   #endif
#endif

#if IS_RF_SKY74045
/*SKY74045*/
/*SKY74045*/ #define  GAIN_STEP              2 // no used
/*SKY74045*/
/*SKY74045*/ #define  RF_GSM850_MAXGAIN      ( (100.8)*(PWRRES))
/*SKY74045*/ #define  RF_GSM850_MINGAIN      ( ( 10.8)*(PWRRES))
/*SKY74045*/ #define  RF_GSM_MAXGAIN         ( (100.8)*(PWRRES))
/*SKY74045*/ #define  RF_GSM_MINGAIN         ( ( 10.8)*(PWRRES))
/*SKY74045*/ #define  RF_DCS_MAXGAIN         ( (101.8)*(PWRRES))
/*SKY74045*/ #define  RF_DCS_MINGAIN         ( (  7.8)*(PWRRES))
/*SKY74045*/ #define  RF_PCS_MAXGAIN         ( (100.6)*(PWRRES))
/*SKY74045*/ #define  RF_PCS_MINGAIN         ( (  8.6)*(PWRRES))
/*SKY74045*/
/*SKY74045*/
/*SKY74045*/ /* GSM850....................................................................*/
/*SKY74045*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[7] =
/*SKY74045*/ {  {  GBOUND( 78.8, 76.8 ), GC_A( 0, 78.8 )-1, 0x00405F },
/*SKY74045*/    {  GBOUND( 66.8, 64.8 ), GC_A( 0, 66.8 )-1, 0x00404F },
/*SKY74045*/    {  GBOUND( 60.8, 58.8 ), GC_A( 0, 60.8 )-1, 0x004057 },
/*SKY74045*/    {  GBOUND( 48.8, 46.8 ), GC_A( 0, 48.8 )-1, 0x004047 },
/*SKY74045*/    {  GBOUND( 40.8, 38.8 ), GC_A( 0, 40.8 )-1, 0x004053 },
/*SKY74045*/    {  GBOUND( 28.8, 26.8 ), GC_A( 0, 28.8 )-1, 0x004043 },
/*SKY74045*/    {  GBOUND( 10.8, 10.8 ), GC_A( 0, 10.8 )-1, 0x004003 },
/*SKY74045*/ };
/*SKY74045*/
/*SKY74045*/ /* GSM900....................................................................*/
/*SKY74045*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[7] =
/*SKY74045*/ {  {  GBOUND( 78.8, 76.8 ), GC_A( 0, 78.8 )-1, 0x00405F },
/*SKY74045*/    {  GBOUND( 66.8, 64.8 ), GC_A( 0, 66.8 )-1, 0x00404F },
/*SKY74045*/    {  GBOUND( 60.8, 58.8 ), GC_A( 0, 60.8 )-1, 0x004057 },
/*SKY74045*/    {  GBOUND( 48.8, 46.8 ), GC_A( 0, 48.8 )-1, 0x004047 },
/*SKY74045*/    {  GBOUND( 40.8, 38.8 ), GC_A( 0, 40.8 )-1, 0x004053 },
/*SKY74045*/    {  GBOUND( 28.8, 26.8 ), GC_A( 0, 28.8 )-1, 0x004043 },
/*SKY74045*/    {  GBOUND( 10.8, 10.8 ), GC_A( 0, 10.8 )-1, 0x004003 },
/*SKY74045*/ };
/*SKY74045*/
/*SKY74045*/ /*DCS1800...................................................................*/
/*SKY74045*/
/*SKY74045*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[7] =
/*SKY74045*/ {  {  GBOUND( 77.8, 75.8 ), GC_A( 0, 77.8 )-1, 0x00805F },
/*SKY74045*/    {  GBOUND( 65.8, 63.8 ), GC_A( 0, 65.8 )-1, 0x00804F },
/*SKY74045*/    {  GBOUND( 59.8, 57.8 ), GC_A( 0, 59.8 )-1, 0x008057 },
/*SKY74045*/    {  GBOUND( 47.8, 45.8 ), GC_A( 0, 47.8 )-1, 0x008047 },
/*SKY74045*/    {  GBOUND( 37.8, 35.8 ), GC_A( 0, 37.8 )-1, 0x008053 },
/*SKY74045*/    {  GBOUND( 25.8, 23.8 ), GC_A( 0, 25.8 )-1, 0x008043 },
/*SKY74045*/    {  GBOUND(  7.8,  7.8 ), GC_A( 0,  7.8 )-1, 0x008003 },
/*SKY74045*/ };
/*SKY74045*/
/*SKY74045*/ /* PCS1900...................................................................*/
/*SKY74045*/
/*SKY74045*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[7] =
/*SKY74045*/ {  {  GBOUND( 76.6, 74.6 ), GC_A( 0, 76.6 ),   0x00C05F },
/*SKY74045*/    {  GBOUND( 64.6, 62.6 ), GC_A( 0, 64.6 ),   0x00C04F },
/*SKY74045*/    {  GBOUND( 58.6, 56.6 ), GC_A( 0, 58.6 ),   0x00C057 },
/*SKY74045*/    {  GBOUND( 46.6, 44.6 ), GC_A( 0, 46.6 ),   0x00C047 },
/*SKY74045*/    {  GBOUND( 38.6, 36.6 ), GC_A( 0, 38.6 ),   0x00C053 },
/*SKY74045*/    {  GBOUND( 26.6, 24.6 ), GC_A( 0, 26.6 ),   0x00C043 },
/*SKY74045*/    {  GBOUND(  8.6,  8.6 ), GC_A( 0,  8.6 ),   0x00C003 },
/*SKY74045*/ };
/*SKY74045*/
/*SKY74045*/ /*...........................................................................*/
/*SKY74045*/
/*SKY74045*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*SKY74045*/ {  {                   0,                      0      },   /*#FrequencyBand400  */
/*SKY74045*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN   },   /*#FrequencyBand850  */
/*SKY74045*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN      },   /* FrequencyBand900  */
/*SKY74045*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN      },   /* FrequencyBand1800 */
/*SKY74045*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN      },   /* FrequencyBand1900 */
/*SKY74045*/ };
/*SKY74045*/
/*SKY74045*/ /*...........................................................................*/
/*SKY74045*/
/*SKY74045*/ const  sL1DAGCDATA*  AGC_TABLE[] =
/*SKY74045*/ {  0,                                          /*#FrequencyBand400  */
/*SKY74045*/    AGC_TABLE_GSM850,                           /*#FrequencyBand850  */
/*SKY74045*/    AGC_TABLE_GSM900,                           /* FrequencyBand900  */
/*SKY74045*/    AGC_TABLE_DCS1800,                          /* FrequencyBand1800 */
/*SKY74045*/    AGC_TABLE_PCS1900,                          /* FrequencyBand1900 */
/*SKY74045*/ };
/*SKY74045*/ /*...........................................................................*/
/*SKY74045*/
/*SKY74045*/ int L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*SKY74045*/ {  int   max_gain, min_gain, real_gain;
/*SKY74045*/    const int*    d32ptr;
/*SKY74045*/    const sL1DAGCDATA*  agcptr;
/*SKY74045*/    long  setting;
/*SKY74045*/    int   bit_no;
/*SKY74045*/    int   left, right, middle;
/*SKY74045*/
/*SKY74045*/    /* transfer power gain to voltage gain */
/*SKY74045*/    request_gain = request_gain + 34*8;
/*SKY74045*/
/*SKY74045*/    /* evaluate the range of available gain */
/*SKY74045*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*SKY74045*/    max_gain = *d32ptr++;
/*SKY74045*/    min_gain = *d32ptr;
/*SKY74045*/
/*SKY74045*/    /* clipping the request gain to the avialable gain */
/*SKY74045*/    if( request_gain>=max_gain )
/*SKY74045*/    {  request_gain = max_gain;  }
/*SKY74045*/    else  if( request_gain<=min_gain )
/*SKY74045*/    {  request_gain = min_gain;  }
/*SKY74045*/
/*SKY74045*/    /* evaluate the real gain setting */
/*SKY74045*/    agcptr = AGC_TABLE[rf_band];
/*SKY74045*/
/*SKY74045*/    /* binary search */
/*SKY74045*/    left = 0; right = 6;
/*SKY74045*/    while (left <= right)
/*SKY74045*/    {
/*SKY74045*/       middle = (left + right)/2;
/*SKY74045*/       if ( request_gain > (agcptr+middle)->pos_gain )
/*SKY74045*/          right = middle - 1;
/*SKY74045*/       else if ( request_gain < (agcptr+middle)->pos_gain )
/*SKY74045*/          left = middle + 1;
/*SKY74045*/       else
/*SKY74045*/       {
/*SKY74045*/          left = middle;
/*SKY74045*/          break;
/*SKY74045*/       }
/*SKY74045*/    }
/*SKY74045*/    if (left > 6)
/*SKY74045*/       left--;
/*SKY74045*/
/*SKY74045*/    agcptr = (agcptr+left);
/*SKY74045*/
/*SKY74045*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*SKY74045*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*SKY74045*/       /* transfer voltage gain to power gain */
/*SKY74045*/       real_gain = real_gain - 34*8;
/*SKY74045*/
/*SKY74045*/       if (left != 6)  //if not last region
/*SKY74045*/       {  bit_no = bit_no + (int)(bit_no/3);
/*SKY74045*/          setting   = agcptr->setting | ((bit_no&0x1)<<13) | ((bit_no&0x2)<<11) | ((bit_no&0x4)<<9) | ((bit_no&0x8)<<7) | ((bit_no&0x10)<<5);
/*SKY74045*/       }
/*SKY74045*/       else if (left == 6)  //else if last region
/*SKY74045*/       {  bit_no = bit_no + (int)(bit_no/3) + 8;
/*SKY74045*/          setting   = agcptr->setting | ((bit_no&0x1)<<13) | ((bit_no&0x2)<<11) | (((~bit_no)&0x1c)<<3);
/*SKY74045*/       }
/*SKY74045*/    }
/*SKY74045*/
/*SKY74045*/    *gain_setting = setting;
/*SKY74045*/    return( real_gain );
/*SKY74045*/ }
/*SKY74045*/
#endif

#if IS_RF_AERO2
/*AERO2*/
/*AERO2*/ #define  GAIN_STEP               1
/*AERO2*/ #define  PVOFSL                  (-25.0)
/*AERO2*/ #define  PVOFSH                  (-25.0)
/*AERO2*/ #define  RF_GSM850_MAXGAIN      (( 94.0 + PVOFSL )*(PWRRES))
/*AERO2*/ #define  RF_GSM850_MINGAIN      ((  8.0 + PVOFSL )*(PWRRES))
/*AERO2*/ #define  RF_GSM_MAXGAIN         (( 94.0 + PVOFSL )*(PWRRES))
/*AERO2*/ #define  RF_GSM_MINGAIN         ((  8.0 + PVOFSL )*(PWRRES))
/*AERO2*/ #define  RF_DCS_MAXGAIN         (( 94.0 + PVOFSH )*(PWRRES))
/*AERO2*/ #define  RF_DCS_MINGAIN         ((  8.0 + PVOFSH )*(PWRRES))
/*AERO2*/ #define  RF_PCS_MAXGAIN         (( 94.0 + PVOFSH )*(PWRRES))
/*AERO2*/ #define  RF_PCS_MINGAIN         ((  8.0 + PVOFSH )*(PWRRES))
/*AERO2*/
/*AERO2*/ /* GSM850....................................................................*/
/*AERO2*/
/*AERO2*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[6] =
/*AERO2*/ {  {  GBOUND( ( 76.0 + PVOFSL ),( 77.0 + PVOFSL ) ), GC_A( 46, ( 77.0 + PVOFSL ) ), 0x00C020 },
/*AERO2*/    {  GBOUND( ( 72.0 + PVOFSL ),( 73.0 + PVOFSL ) ), GC_A( 46, ( 73.0 + PVOFSL ) ), 0x00B020 },
/*AERO2*/    {  GBOUND( ( 68.0 + PVOFSL ),( 69.0 + PVOFSL ) ), GC_A( 46, ( 69.0 + PVOFSL ) ), 0x00A020 },
/*AERO2*/    {  GBOUND( ( 64.0 + PVOFSL ),( 65.0 + PVOFSL ) ), GC_A( 46, ( 65.0 + PVOFSL ) ), 0x009020 },
/*AERO2*/    {  GBOUND( ( 14.0 + PVOFSL ),( 15.0 + PVOFSL ) ), GC_A(  0, ( 15.0 + PVOFSL ) ), 0x008020 },
/*AERO2*/    {  GBOUND( (  8.0 + PVOFSL ),(  8.0 + PVOFSL ) ), GC_A(  8, (  8.0 + PVOFSL ) ), 0x000020 },
/*AERO2*/ };
/*AERO2*/
/*AERO2*/ /* GSM900....................................................................*/
/*AERO2*/
/*AERO2*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[6] =
/*AERO2*/ {  {  GBOUND( ( 76.0 + PVOFSL ),( 77.0 + PVOFSL ) ), GC_A( 46, ( 77.0 + PVOFSL ) ), 0x00C020 },
/*AERO2*/    {  GBOUND( ( 72.0 + PVOFSL ),( 73.0 + PVOFSL ) ), GC_A( 46, ( 73.0 + PVOFSL ) ), 0x00B020 },
/*AERO2*/    {  GBOUND( ( 68.0 + PVOFSL ),( 69.0 + PVOFSL ) ), GC_A( 46, ( 69.0 + PVOFSL ) ), 0x00A020 },
/*AERO2*/    {  GBOUND( ( 64.0 + PVOFSL ),( 65.0 + PVOFSL ) ), GC_A( 46, ( 65.0 + PVOFSL ) ), 0x009020 },
/*AERO2*/    {  GBOUND( ( 14.0 + PVOFSL ),( 15.0 + PVOFSL ) ), GC_A(  0, ( 15.0 + PVOFSL ) ), 0x008020 },
/*AERO2*/    {  GBOUND( (  8.0 + PVOFSL ),(  8.0 + PVOFSL ) ), GC_A(  8, (  8.0 + PVOFSL ) ), 0x000020 },
/*AERO2*/ };
/*AERO2*/
/*AERO2*/ /* DCS1800...................................................................*/
/*AERO2*/
/*AERO2*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[6] =
/*AERO2*/ {  {  GBOUND( ( 76.0 + PVOFSH ),( 77.0 + PVOFSH ) ), GC_A( 46, ( 77.0 + PVOFSH ) ), 0x00C020 },
/*AERO2*/    {  GBOUND( ( 72.0 + PVOFSH ),( 73.0 + PVOFSH ) ), GC_A( 46, ( 73.0 + PVOFSH ) ), 0x00B020 },
/*AERO2*/    {  GBOUND( ( 68.0 + PVOFSH ),( 69.0 + PVOFSH ) ), GC_A( 46, ( 69.0 + PVOFSH ) ), 0x00A020 },
/*AERO2*/    {  GBOUND( ( 64.0 + PVOFSH ),( 65.0 + PVOFSH ) ), GC_A( 46, ( 65.0 + PVOFSH ) ), 0x009020 },
/*AERO2*/    {  GBOUND( ( 14.0 + PVOFSH ),( 15.0 + PVOFSH ) ), GC_A(  0, ( 15.0 + PVOFSH ) ), 0x008020 },
/*AERO2*/    {  GBOUND( (  8.0 + PVOFSH ),(  8.0 + PVOFSH ) ), GC_A(  0, (  8.0 + PVOFSH ) ), 0x000020 },
/*AERO2*/ };
/*AERO2*/
/*AERO2*/ /* PCS1900...................................................................*/
/*AERO2*/
/*AERO2*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[6] =
/*AERO2*/ {  {  GBOUND( ( 76.0 + PVOFSH ),( 77.0 + PVOFSH ) ), GC_A( 46, ( 77.0 + PVOFSH ) ), 0x00C020 },
/*AERO2*/    {  GBOUND( ( 72.0 + PVOFSH ),( 73.0 + PVOFSH ) ), GC_A( 46, ( 73.0 + PVOFSH ) ), 0x00B020 },
/*AERO2*/    {  GBOUND( ( 68.0 + PVOFSH ),( 69.0 + PVOFSH ) ), GC_A( 46, ( 69.0 + PVOFSH ) ), 0x00A020 },
/*AERO2*/    {  GBOUND( ( 64.0 + PVOFSH ),( 65.0 + PVOFSH ) ), GC_A( 46, ( 65.0 + PVOFSH ) ), 0x009020 },
/*AERO2*/    {  GBOUND( ( 14.0 + PVOFSH ),( 15.0 + PVOFSH ) ), GC_A(  0, ( 15.0 + PVOFSH ) ), 0x008020 },
/*AERO2*/    {  GBOUND( (  8.0 + PVOFSH ),(  8.0 + PVOFSH ) ), GC_A(  0, (  8.0 + PVOFSH ) ), 0x000020 },
/*AERO2*/ };
/*AERO2*/
/*AERO2*/ /*...........................................................................*/
/*AERO2*/
/*AERO2*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*AERO2*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*AERO2*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*AERO2*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*AERO2*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*AERO2*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*AERO2*/ };
/*AERO2*/
/*AERO2*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*AERO2*/ {  0,                                              /*#FrequencyBand400  */
/*AERO2*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*AERO2*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*AERO2*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*AERO2*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*AERO2*/ };
/*AERO2*/
/*AERO2*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*AERO2*/
/*AERO2*/ int  L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*AERO2*/ {  int   max_gain, min_gain, real_gain;
/*AERO2*/    const int*    d32ptr;
/*AERO2*/    const sL1DAGCDATA*  agcptr;
/*AERO2*/    long  setting;
/*AERO2*/    int   bit_no;
/*AERO2*/
/*AERO2*/    /* evaluate the range of available gain */
/*AERO2*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*AERO2*/    max_gain = *d32ptr++;
/*AERO2*/    min_gain = *d32ptr;
/*AERO2*/
/*AERO2*/    /* clipping the request gain to the avialable gain */
/*AERO2*/    if( request_gain>=max_gain )
/*AERO2*/    {  request_gain = max_gain;  }
/*AERO2*/    else  if( request_gain<=min_gain )
/*AERO2*/    {  request_gain = min_gain;  }
/*AERO2*/
/*AERO2*/    /* evaluate the real gain setting */
/*AERO2*/    agcptr = AGC_TABLE[rf_band];
/*AERO2*/    agcptr += 2;
/*AERO2*/    if( request_gain >= agcptr->pos_gain )
/*AERO2*/    {  agcptr -= 2;                            //#1
/*AERO2*/       if( request_gain < agcptr->pos_gain )
/*AERO2*/       {  agcptr += 1;                         //#2
/*AERO2*/          if(request_gain < agcptr->pos_gain )
/*AERO2*/          {  agcptr += 1;                      //#3
/*AERO2*/          }
/*AERO2*/       }
/*AERO2*/    }
/*AERO2*/    else
/*AERO2*/    {  agcptr += 1;                            //#4
/*AERO2*/       if( request_gain < agcptr->pos_gain )
/*AERO2*/       {  agcptr += 1;                         //#5
/*AERO2*/          if(request_gain < agcptr->pos_gain )
/*AERO2*/          {  agcptr += 1;                      //#6
/*AERO2*/          }
/*AERO2*/       }
/*AERO2*/    }
/*AERO2*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*AERO2*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*AERO2*/       setting   = agcptr->setting + (bit_no<<6);
/*AERO2*/    }
/*AERO2*/
/*AERO2*/    *gain_setting = setting;
/*AERO2*/    return( real_gain );
/*AERO2*/ }
/*AERO2*/
#endif

#if IS_RF_SKY74137
/*SKY74137*/
/*SKY74137*/ #define  GAIN_STEP              2 // no used
/*SKY74137*/
/*SKY74137*/ #define  RF_GSM850_MAXGAIN      ( (95+2)*(PWRRES))
/*SKY74137*/ #define  RF_GSM850_MINGAIN      ( ( 3+2)*(PWRRES))
/*SKY74137*/ #define  RF_GSM_MAXGAIN         RF_GSM850_MAXGAIN
/*SKY74137*/ #define  RF_GSM_MINGAIN         RF_GSM850_MINGAIN
/*SKY74137*/ #define  RF_DCS_MAXGAIN         RF_GSM850_MAXGAIN
/*SKY74137*/ #define  RF_DCS_MINGAIN         RF_GSM850_MINGAIN
/*SKY74137*/ #define  RF_PCS_MAXGAIN         RF_GSM850_MAXGAIN
/*SKY74137*/ #define  RF_PCS_MINGAIN         RF_GSM850_MINGAIN
/*SKY74137*/
/*SKY74137*/
/*SKY74137*/ /* GSM850....................................................................*/
/*SKY74137*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[12] =
/*SKY74137*/ {  {  GBOUND( 83+2, 81+2 ), GC_A( 0, 83+2 ),   0xA23C24 },
/*SKY74137*/    {  GBOUND( 71+2, 69+2 ), GC_A( 0, 71+2 ),   0xA23824 },
/*SKY74137*/    {  GBOUND( 65+2, 63+2 ), GC_A( 0, 65+2 ),   0xA23424 },
/*SKY74137*/    {  GBOUND( 59+2, 57+2 ), GC_A( 0, 59+2 ),   0xA22824 },
/*SKY74137*/    {  GBOUND( 55+2, 53+2 ), GC_A( 0, 55+2 ),   0xA22464 },
/*SKY74137*/    {  GBOUND( 47+2, 45+2 ), GC_A( 0, 47+2 ),   0xA02824 },
/*SKY74137*/    {  GBOUND( 39+2, 37+2 ), GC_A( 0, 39+2 ),   0xA20824 },
/*SKY74137*/    {  GBOUND( 33+2, 31+2 ), GC_A( 0, 33+2 ),   0xA20424 },
/*SKY74137*/    {  GBOUND( 27+2, 25+2 ), GC_A( 0, 27+2 ),   0xA00824 },
/*SKY74137*/    {  GBOUND( 21+2, 19+2 ), GC_A( 0, 21+2 ),   0xA00424 },
/*SKY74137*/    {  GBOUND( 15+2, 13+2 ), GC_A( 0, 15+2 ),   0xA00414 },
/*SKY74137*/    {  GBOUND(  3+2,  3+2 ), GC_A( 0,  3+2 ),   0xA00014 },
/*SKY74137*/ };
/*SKY74137*/
/*SKY74137*/ /* GSM900....................................................................*/
/*SKY74137*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[7] =
/*SKY74137*/ {  {  GBOUND( 78.8, 76.8 ), GC_A( 0, 78.8 )-1, 0x00405F },
/*SKY74137*/    {  GBOUND( 66.8, 64.8 ), GC_A( 0, 66.8 )-1, 0x00404F },
/*SKY74137*/    {  GBOUND( 60.8, 58.8 ), GC_A( 0, 60.8 )-1, 0x004057 },
/*SKY74137*/    {  GBOUND( 48.8, 46.8 ), GC_A( 0, 48.8 )-1, 0x004047 },
/*SKY74137*/    {  GBOUND( 40.8, 38.8 ), GC_A( 0, 40.8 )-1, 0x004053 },
/*SKY74137*/    {  GBOUND( 28.8, 26.8 ), GC_A( 0, 28.8 )-1, 0x004043 },
/*SKY74137*/    {  GBOUND( 10.8, 10.8 ), GC_A( 0, 10.8 )-1, 0x004003 },
/*SKY74137*/ };
/*SKY74137*/
/*SKY74137*/ /*DCS1800...................................................................*/
/*SKY74137*/
/*SKY74137*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[7] =
/*SKY74137*/ {  {  GBOUND( 77.8, 75.8 ), GC_A( 0, 77.8 )-1, 0x00805F },
/*SKY74137*/    {  GBOUND( 65.8, 63.8 ), GC_A( 0, 65.8 )-1, 0x00804F },
/*SKY74137*/    {  GBOUND( 59.8, 57.8 ), GC_A( 0, 59.8 )-1, 0x008057 },
/*SKY74137*/    {  GBOUND( 47.8, 45.8 ), GC_A( 0, 47.8 )-1, 0x008047 },
/*SKY74137*/    {  GBOUND( 37.8, 35.8 ), GC_A( 0, 37.8 )-1, 0x008053 },
/*SKY74137*/    {  GBOUND( 25.8, 23.8 ), GC_A( 0, 25.8 )-1, 0x008043 },
/*SKY74137*/    {  GBOUND(  7.8,  7.8 ), GC_A( 0,  7.8 )-1, 0x008003 },
/*SKY74137*/ };
/*SKY74137*/
/*SKY74137*/ /* PCS1900...................................................................*/
/*SKY74137*/
/*SKY74137*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[7] =
/*SKY74137*/ {  {  GBOUND( 76.6, 74.6 ), GC_A( 0, 76.6 ),   0x00C05F },
/*SKY74137*/    {  GBOUND( 64.6, 62.6 ), GC_A( 0, 64.6 ),   0x00C04F },
/*SKY74137*/    {  GBOUND( 58.6, 56.6 ), GC_A( 0, 58.6 ),   0x00C057 },
/*SKY74137*/    {  GBOUND( 46.6, 44.6 ), GC_A( 0, 46.6 ),   0x00C047 },
/*SKY74137*/    {  GBOUND( 38.6, 36.6 ), GC_A( 0, 38.6 ),   0x00C053 },
/*SKY74137*/    {  GBOUND( 26.6, 24.6 ), GC_A( 0, 26.6 ),   0x00C043 },
/*SKY74137*/    {  GBOUND(  8.6,  8.6 ), GC_A( 0,  8.6 ),   0x00C003 },
/*SKY74137*/ };
/*SKY74137*/
/*SKY74137*/ /*...........................................................................*/
/*SKY74137*/
/*SKY74137*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*SKY74137*/ {  {                   0,                   0         },   /*#FrequencyBand400  */
/*SKY74137*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN   },   /* FrequencyBand850  */
/*SKY74137*/    { (int)RF_GSM_MAXGAIN, (int)RF_GSM_MINGAIN         },   /* FrequencyBand900  */
/*SKY74137*/    { (int)RF_DCS_MAXGAIN, (int)RF_DCS_MINGAIN         },   /* FrequencyBand1800 */
/*SKY74137*/    { (int)RF_PCS_MAXGAIN, (int)RF_PCS_MINGAIN         },   /* FrequencyBand1900 */
/*SKY74137*/ };
/*SKY74137*/
/*SKY74137*/ /*...........................................................................*/
/*SKY74137*/
/*SKY74137*/ const  sL1DAGCDATA*  AGC_TABLE[] =
/*SKY74137*/ {  0,                                          /*#FrequencyBand400  */
/*SKY74137*/    AGC_TABLE_GSM850,                           /* FrequencyBand850  */
/*SKY74137*/    AGC_TABLE_GSM850,                           /* FrequencyBand900  */
/*SKY74137*/    AGC_TABLE_GSM850,                           /* FrequencyBand1800 */
/*SKY74137*/    AGC_TABLE_GSM850,                           /* FrequencyBand1900 */
/*SKY74137*/ };
/*SKY74137*/ /*...........................................................................*/
/*SKY74137*/
/*SKY74117*/ const  short AGC_TABLE_SIZE[] =
/*SKY74117*/ {  0,                                              /*#FrequencyBand400  */
/*SKY74117*/    sizeof(AGC_TABLE_GSM850)/sizeof(sL1DAGCDATA),   /* FrequencyBand850  */
/*SKY74117*/    sizeof(AGC_TABLE_GSM850)/sizeof(sL1DAGCDATA),   /* FrequencyBand900  */
/*SKY74117*/    sizeof(AGC_TABLE_GSM850)/sizeof(sL1DAGCDATA),   /* FrequencyBand1800 */
/*SKY74117*/    sizeof(AGC_TABLE_GSM850)/sizeof(sL1DAGCDATA),   /* FrequencyBand1900 */
/*SKY74117*/ };
/*SKY74137*/ /*...........................................................................*/
/*SKY74137*/
/*SKY74137*/ int L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*SKY74137*/ {  int   max_gain, min_gain, real_gain;
/*SKY74137*/    const int*    d32ptr;
/*SKY74137*/    const sL1DAGCDATA*  agcptr;
/*SKY74137*/    long  setting;
/*SKY74137*/    int   bit_no;
/*SKY74137*/    int   left, right, middle;
/*SKY74137*/
/*SKY74137*/    /* transfer power gain to voltage gain */
/*SKY74137*/    request_gain = request_gain + 34*8;
/*SKY74137*/
/*SKY74137*/    /* evaluate the range of available gain */
/*SKY74137*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*SKY74137*/    max_gain = *d32ptr++;
/*SKY74137*/    min_gain = *d32ptr;
/*SKY74137*/
/*SKY74137*/    /* clipping the request gain to the avialable gain */
/*SKY74137*/    if( request_gain>=max_gain )
/*SKY74137*/    {  request_gain = max_gain;  }
/*SKY74137*/    else  if( request_gain<=min_gain )
/*SKY74137*/    {  request_gain = min_gain;  }
/*SKY74137*/
/*SKY74137*/    /* evaluate the real gain setting */
/*SKY74137*/    agcptr = AGC_TABLE[rf_band];
/*SKY74137*/
/*SKY74137*/    /* binary search */
/*SKY74137*/    left = 0; right = AGC_TABLE_SIZE[rf_band]-1;
/*SKY74137*/    while (left <= right)
/*SKY74137*/    {
/*SKY74137*/       middle = (left + right)/2;
/*SKY74137*/       if ( request_gain > (agcptr+middle)->pos_gain )
/*SKY74137*/          right = middle - 1;
/*SKY74137*/       else if ( request_gain < (agcptr+middle)->pos_gain )
/*SKY74137*/          left = middle + 1;
/*SKY74137*/       else
/*SKY74137*/       {
/*SKY74137*/          left = middle;
/*SKY74137*/          break;
/*SKY74137*/       }
/*SKY74137*/    }
/*SKY74137*/
/*SKY74137*/    agcptr = (agcptr+left);
/*SKY74137*/
/*SKY74137*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*SKY74137*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*SKY74137*/       /* transfer voltage gain to power gain */
/*SKY74137*/       real_gain = real_gain - 34*8;
/*SKY74137*/       setting   = agcptr->setting + (bit_no<<6);
/*SKY74137*/    }
/*SKY74137*/
/*SKY74137*/    *gain_setting = setting;
/*SKY74137*/    return( real_gain );
/*SKY74137*/ }
/*SKY74137*/
#endif

#if IS_RF_GRF6201
/*GRF6201*/
/*GRF6201*/ typedef  struct
/*GRF6201*/ {
/*GRF6201*/    short pos_gain;
/*GRF6201*/    long  setting;
/*GRF6201*/    short A;
/*GRF6201*/    short pos_bitno;
/*GRF6201*/ } sL1DAGCDATA_GCT;
/*GRF6201*/
/*GRF6201*/ #define  GAIN_STEP               2
/*GRF6201*/
/*GRF6201*/ #define  RF_GSM850_MAXGAIN      ( ( 68.0)*(PWRRES))
/*GRF6201*/ #define  RF_GSM850_MINGAIN      ( (-44.0)*(PWRRES))
/*GRF6201*/ #define  RF_GSM_MAXGAIN         ( ( 68.0)*(PWRRES))
/*GRF6201*/ #define  RF_GSM_MINGAIN         ( (-44.0)*(PWRRES))
/*GRF6201*/ #define  RF_DCS_MAXGAIN         ( ( 70.0)*(PWRRES))
/*GRF6201*/ #define  RF_DCS_MINGAIN         ( (-38.0)*(PWRRES))
/*GRF6201*/ #define  RF_PCS_MAXGAIN         ( ( 70.0)*(PWRRES))
/*GRF6201*/ #define  RF_PCS_MINGAIN         ( (-36.0)*(PWRRES))
/*GRF6201*/
/*GRF6201*/ /* GSM850....................................................................*/
/*GRF6201*/
/*GRF6201*/ const  sL1DAGCDATA_GCT  AGC_TABLE_GSM850[8] =   //Table060714
/*GRF6201*/ {  {  GBOUND( 44.0, 42.0 ),  (1L<<23)|(8L<<19)|(16L<<14)|(9L<<6)|2L,  GC_A(  0, 44.0 ),  10 },
/*GRF6201*/    {  GBOUND( 22.0, 20.0 ),  (1L<<23)|(7L<<19)|( 1L<<10)|(9L<<6)|2L,  GC_A(  5, 22.0 ),  14 },
/*GRF6201*/    {  GBOUND(  6.0,  4.0 ),  (1L<<23)|(4L<<14)|( 3L<<10)|(5L<<6)|2L,  GC_A(  2,  6.0 ),  19 },
/*GRF6201*/    {  GBOUND(  0.0, -4.0 ),  (1L<<23)|(1L<<19)|( 4L<<14)|(5L<<6)|2L,  GC_A(  1,  0.0 ),  10 },
/*GRF6201*/    {  GBOUND(-10.0,-16.0 ),  (1L<<23)|(1L<<19)|( 1L<<10)|(4L<<6)|2L,  GC_A(  0,-10.0 ),  14 },
/*GRF6201*/    {  GBOUND(-22.0,-24.0 ),  (0L<<23)|(4L<<14)|( 7L<<10)|(3L<<6)|2L,  GC_A(  0,-22.0 ),  19 },
/*GRF6201*/    {  GBOUND(-30.0,-32.0 ),  (0L<<23)|(0L<<19)|( 7L<<10)|(3L<<6)|2L,  GC_A(  0,-30.0 ),  14 },
/*GRF6201*/    {  GBOUND(-44.0,-44.0 ),  (0L<<23)|(0L<<19)|( 0L<<14)|(3L<<6)|2L,  GC_A(  0,-44.0 ),  10 },
/*GRF6201*/ };
/*GRF6201*/
/*GRF6201*/ const  sL1DAGCDATA_GCT  AGC_TABLE_GSM900[8] =   //Table060714
/*GRF6201*/ {  {  GBOUND( 44.0, 42.0 ),  (1L<<23)|(8L<<19)|(16L<<14)|(9L<<6)|2L,  GC_A(  0, 44.0 ),  10 },
/*GRF6201*/    {  GBOUND( 22.0, 20.0 ),  (1L<<23)|(7L<<19)|( 1L<<10)|(9L<<6)|2L,  GC_A(  5, 22.0 ),  14 },
/*GRF6201*/    {  GBOUND(  6.0,  4.0 ),  (1L<<23)|(4L<<14)|( 3L<<10)|(5L<<6)|2L,  GC_A(  2,  6.0 ),  19 },
/*GRF6201*/    {  GBOUND(  0.0, -4.0 ),  (1L<<23)|(1L<<19)|( 4L<<14)|(5L<<6)|2L,  GC_A(  1,  0.0 ),  10 },
/*GRF6201*/    {  GBOUND(-10.0,-16.0 ),  (1L<<23)|(1L<<19)|( 1L<<10)|(4L<<6)|2L,  GC_A(  0,-10.0 ),  14 },
/*GRF6201*/    {  GBOUND(-22.0,-24.0 ),  (0L<<23)|(4L<<14)|( 7L<<10)|(3L<<6)|2L,  GC_A(  0,-22.0 ),  19 },
/*GRF6201*/    {  GBOUND(-30.0,-32.0 ),  (0L<<23)|(0L<<19)|( 7L<<10)|(3L<<6)|2L,  GC_A(  0,-30.0 ),  14 },
/*GRF6201*/    {  GBOUND(-44.0,-44.0 ),  (0L<<23)|(0L<<19)|( 0L<<14)|(3L<<6)|2L,  GC_A(  0,-44.0 ),  10 },
/*GRF6201*/ };
/*GRF6201*/
/*GRF6201*/ const  sL1DAGCDATA_GCT  AGC_TABLE_DCS1800[8] =  //Table060714
/*GRF6201*/ {  {  GBOUND( 46.0, 44.0 ),  (1L<<23)|(8L<<19)|(16L<<14)|(8L<<6)|2L,  GC_A(  0, 46.0 ),  10 },
/*GRF6201*/    {  GBOUND( 24.0, 22.0 ),  (1L<<23)|(7L<<19)|( 1L<<10)|(8L<<6)|2L,  GC_A(  5, 24.0 ),  14 },
/*GRF6201*/    {  GBOUND(  8.0,  6.0 ),  (1L<<23)|(4L<<14)|( 3L<<10)|(4L<<6)|2L,  GC_A(  2,  8.0 ),  19 },
/*GRF6201*/    {  GBOUND(  4.0,  0.0 ),  (1L<<23)|(1L<<19)|( 4L<<14)|(4L<<6)|2L,  GC_A(  2,  4.0 ),  10 },
/*GRF6201*/    {  GBOUND( -8.0,-10.0 ),  (1L<<23)|(1L<<19)|( 1L<<10)|(3L<<6)|2L,  GC_A(  0, -8.0 ),  14 },
/*GRF6201*/    {  GBOUND(-16.0,-18.0 ),  (0L<<23)|(4L<<14)|( 7L<<10)|(3L<<6)|2L,  GC_A(  0,-16.0 ),  19 },
/*GRF6201*/    {  GBOUND(-24.0,-26.0 ),  (0L<<23)|(0L<<19)|( 7L<<10)|(3L<<6)|2L,  GC_A(  0,-24.0 ),  14 },
/*GRF6201*/    {  GBOUND(-38.0,-38.0 ),  (0L<<23)|(0L<<19)|( 0L<<14)|(3L<<6)|2L,  GC_A(  0,-38.0 ),  10 },
/*GRF6201*/ };
/*GRF6201*/
/*GRF6201*/ const  sL1DAGCDATA_GCT  AGC_TABLE_PCS1900[10] = //Table060714
/*GRF6201*/ {  {  GBOUND( 46.0, 44.0 ),  (1L<<23)|(8L<<19)|(16L<<14)|(7L<<6)|2L,  GC_A(  0, 46.0 ),  10 },
/*GRF6201*/    {  GBOUND( 40.0, 36.0 ),  (1L<<23)|(7L<<19)|( 1L<<10)|(7L<<6)|2L,  GC_A( 13, 40.0 ),  14 },
/*GRF6201*/    {  GBOUND( 22.0, 20.0 ),  (1L<<23)|(7L<<19)|( 1L<<10)|(6L<<6)|2L,  GC_A(  5, 22.0 ),  14 },
/*GRF6201*/    {  GBOUND( 20.0, 18.0 ),  (1L<<23)|(8L<<19)|( 4L<<14)|(5L<<6)|2L,  GC_A(  1, 20.0 ),  10 },
/*GRF6201*/    {  GBOUND(  4.0,  2.0 ),  (1L<<23)|(4L<<14)|( 2L<<10)|(3L<<6)|2L,  GC_A(  1,  4.0 ),  19 },
/*GRF6201*/    {  GBOUND(  0.0, -2.0 ),  (1L<<23)|(1L<<19)|( 4L<<14)|(3L<<6)|2L,  GC_A(  0,  0.0 ),  10 },
/*GRF6201*/    {  GBOUND( -8.0,-10.0 ),  (1L<<23)|(1L<<19)|( 0L<<10)|(3L<<6)|2L,  GC_A(  0, -8.0 ),  14 },
/*GRF6201*/    {  GBOUND(-16.0,-18.0 ),  (0L<<23)|(4L<<14)|( 6L<<10)|(3L<<6)|2L,  GC_A(  0,-16.0 ),  19 },
/*GRF6201*/    {  GBOUND(-24.0,-26.0 ),  (0L<<23)|(0L<<19)|( 6L<<10)|(3L<<6)|2L,  GC_A(  0,-24.0 ),  14 },
/*GRF6201*/    {  GBOUND(-36.0,-36.0 ),  (0L<<23)|(0L<<19)|( 0L<<14)|(3L<<6)|2L,  GC_A(  0,-36.0 ),  10 },
/*GRF6201*/ };
/*GRF6201*/
/*GRF6201*/ /*...........................................................................*/
/*GRF6201*/
/*GRF6201*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*GRF6201*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*GRF6201*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*GRF6201*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*GRF6201*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*GRF6201*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*GRF6201*/ };
/*GRF6201*/
/*GRF6201*/ const  sL1DAGCDATA_GCT *const  AGC_TABLE[] =
/*GRF6201*/ {  0,                                                  /*#FrequencyBand400  */
/*GRF6201*/    AGC_TABLE_GSM850,                                   /* FrequencyBand850  */
/*GRF6201*/    AGC_TABLE_GSM900,                                   /* FrequencyBand900  */
/*GRF6201*/    AGC_TABLE_DCS1800,                                  /* FrequencyBand1800 */
/*GRF6201*/    AGC_TABLE_PCS1900,                                  /* FrequencyBand1900 */
/*GRF6201*/ };
/*GRF6201*/
/*GRF6201*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*GRF6201*/
/*GRF6201*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*GRF6201*/ {  int   max_gain, min_gain, real_gain;
/*GRF6201*/    const int*    d32ptr;
/*GRF6201*/    const sL1DAGCDATA_GCT*  agcptr;
/*GRF6201*/    long  setting;
/*GRF6201*/    int   bit_no;
/*GRF6201*/    int   left, right, middle;
/*GRF6201*/
/*GRF6201*/    /* evaluate the range of available gain */
/*GRF6201*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*GRF6201*/    max_gain = *d32ptr++;
/*GRF6201*/    min_gain = *d32ptr;
/*GRF6201*/
/*GRF6201*/    /* clipping the request gain to the avialable gain */
/*GRF6201*/    if( request_gain>=max_gain )
/*GRF6201*/    {  request_gain = max_gain;  }
/*GRF6201*/    else  if( request_gain<=min_gain )
/*GRF6201*/    {  request_gain = min_gain;  }
/*GRF6201*/
/*GRF6201*/    /*binary search*/
/*GRF6201*/    agcptr = AGC_TABLE[rf_band];
/*GRF6201*/    left = 0;
/*GRF6201*/    if ( rf_band == FrequencyBand1900 )
/*GRF6201*/       right = 9;
/*GRF6201*/    else
/*GRF6201*/       right = 7;
/*GRF6201*/
/*GRF6201*/    while (left <= right)
/*GRF6201*/    {  middle = (left + right)/2;
/*GRF6201*/       if ( request_gain >= (agcptr+middle)->pos_gain )
/*GRF6201*/          right = middle - 1;
/*GRF6201*/       else if ( request_gain < (agcptr+middle)->pos_gain )
/*GRF6201*/          left = middle + 1;
/*GRF6201*/    }
/*GRF6201*/    agcptr = (agcptr+left);
/*GRF6201*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*GRF6201*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*GRF6201*/       setting   = (agcptr->setting) | ( bit_no<<(agcptr->pos_bitno) );
/*GRF6201*/    }
/*GRF6201*/
/*GRF6201*/    *gain_setting = setting;
/*GRF6201*/    return( real_gain );
/*GRF6201*/ }
/*GRF6201*/
#endif

#if IS_RF_IRFS3001
/*IRFS3001*/ #define  GAIN_STEP               1
/*IRFS3001*/
/*IRFS3001*/ #define  RF_GSM850_MAXGAIN      (  72.0*(PWRRES) )
/*IRFS3001*/ #define  RF_GSM850_MINGAIN      ( -22.0*(PWRRES) )
/*IRFS3001*/ #define  RF_GSM_MAXGAIN         RF_GSM850_MAXGAIN
/*IRFS3001*/ #define  RF_GSM_MINGAIN         RF_GSM850_MINGAIN
/*IRFS3001*/ #define  RF_DCS_MAXGAIN         (  69.0*(PWRRES) )
/*IRFS3001*/ #define  RF_DCS_MINGAIN         ( -14.0*(PWRRES) )
/*IRFS3001*/ #define  RF_PCS_MAXGAIN         RF_DCS_MAXGAIN
/*IRFS3001*/ #define  RF_PCS_MINGAIN         RF_DCS_MINGAIN
/*IRFS3001*/
/*IRFS3001*/ /* GSM850 & GSM900 ..........................................................*/
/*IRFS3001*/
/*IRFS3001*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[17] =
/*IRFS3001*/ {  {  GBOUND( 66.0, 67.0 ), GC_A(  0, 67.0 ), (0x30474<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 60.0, 61.0 ), GC_A(  0, 61.0 ), (0x303F4<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 54.0, 55.0 ), GC_A(  0, 55.0 ), (0x303E4<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 48.0, 49.0 ), GC_A(  0, 49.0 ), (0x30364<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 42.0, 43.0 ), GC_A(  0, 43.0 ), (0x30354<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 36.0, 37.0 ), GC_A(  0, 37.0 ), (0x302D4<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 30.0, 31.0 ), GC_A(  0, 31.0 ), (0x302C4<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 24.0, 25.0 ), GC_A(  0, 25.0 ), (0x30244<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 22.0, 23.0 ), GC_A(  4, 23.0 ), (0x30234<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 17.0, 18.0 ), GC_A(  0, 18.0 ), (0x30355<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 11.0, 12.0 ), GC_A(  0, 12.0 ), (0x302D5<<6)|0x6 },
/*IRFS3001*/    {  GBOUND(  5.0,  6.0 ), GC_A(  0,  6.0 ), (0x302C5<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( -1.0,  0.0 ), GC_A(  0,  0.0 ), (0x30245<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( -7.0, -6.0 ), GC_A(  0, -6.0 ), (0x30235<<6)|0x6 },
/*IRFS3001*/    {  GBOUND(-13.0,-12.0 ), GC_A(  0,-12.0 ), (0x301B5<<6)|0x6 },
/*IRFS3001*/    {  GBOUND(-19.0,-18.0 ), GC_A(  0,-18.0 ), (0x301A5<<6)|0x6 },
/*IRFS3001*/    {  GBOUND(-22.0,-22.0 ), GC_A(  2,-22.0 ), (0x30125<<6)|0x6 },
/*IRFS3001*/ };
/*IRFS3001*/
/*IRFS3001*/ /* DCS1800 & PCS1900 .....................................................*/
/*IRFS3001*/
/*IRFS3001*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[15] =
/*IRFS3001*/ {  {  GBOUND( 63.0, 64.0 ), GC_A(  0, 64.0 ), (0x30474<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 57.0, 58.0 ), GC_A(  0, 58.0 ), (0x303F4<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 51.0, 52.0 ), GC_A(  0, 52.0 ), (0x303E4<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 45.0, 46.0 ), GC_A(  0, 46.0 ), (0x30364<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 39.0, 40.0 ), GC_A(  0, 40.0 ), (0x30354<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 33.0, 34.0 ), GC_A(  0, 34.0 ), (0x302D4<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 27.0, 28.0 ), GC_A(  0, 28.0 ), (0x302C4<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 22.0, 23.0 ), GC_A(  1, 23.0 ), (0x30244<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 19.0, 20.0 ), GC_A(  0, 20.0 ), (0x302D5<<6)|0x6 },
/*IRFS3001*/    {  GBOUND( 13.0, 14.0 ), GC_A(  0, 14.0 ), (0x302C5<<6)|0x6 },
/*IRFS3001*/    {  GBOUND(  7.0,  8.0 ), GC_A(  0,  8.0 ), (0x30245<<6)|0x6 },
/*IRFS3001*/    {  GBOUND(  1.0,  2.0 ), GC_A(  0,  2.0 ), (0x30235<<6)|0x6 },
/*IRFS3001*/    {  GBOUND(- 5.0, -4.0 ), GC_A(  0, -4.0 ), (0x301B5<<6)|0x6 },
/*IRFS3001*/    {  GBOUND(-11.0,-10.0 ), GC_A(  0,-10.0 ), (0x301A5<<6)|0x6 },
/*IRFS3001*/    {  GBOUND(-14.0,-14.0 ), GC_A(  2,-14.0 ), (0x30125<<6)|0x6 },
/*IRFS3001*/ };
/*IRFS3001*/
/*IRFS3001*/ /*...........................................................................*/
/*IRFS3001*/
/*IRFS3001*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*IRFS3001*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*IRFS3001*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*IRFS3001*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*IRFS3001*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*IRFS3001*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*IRFS3001*/ };
/*IRFS3001*/
/*IRFS3001*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*IRFS3001*/ {  0,                                              /*#FrequencyBand400  */
/*IRFS3001*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*IRFS3001*/    AGC_TABLE_GSM850,                               /* FrequencyBand900  */
/*IRFS3001*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*IRFS3001*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1900 */
/*IRFS3001*/ };
/*IRFS3001*/
/*IRFS3001*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*IRFS3001*/
/*IRFS3001*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*IRFS3001*/ {  int   max_gain, min_gain, real_gain;
/*IRFS3001*/    const int*    d32ptr;
/*IRFS3001*/    const sL1DAGCDATA*  agcptr;
/*IRFS3001*/    long  setting;
/*IRFS3001*/    int   bit_no;
/*IRFS3001*/    int   left, right, middle;
/*IRFS3001*/
/*IRFS3001*/    /* evaluate the range of available gain */
/*IRFS3001*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*IRFS3001*/    max_gain = *d32ptr++;
/*IRFS3001*/    min_gain = *d32ptr;
/*IRFS3001*/
/*IRFS3001*/    /* clipping the request gain to the avialable gain */
/*IRFS3001*/    if( request_gain>=max_gain )
/*IRFS3001*/    {  request_gain = max_gain;  }
/*IRFS3001*/    else  if( request_gain<=min_gain )
/*IRFS3001*/    {  request_gain = min_gain;  }
/*IRFS3001*/
/*IRFS3001*/    /* evaluate the real gain setting */
/*IRFS3001*/    agcptr = AGC_TABLE[rf_band];
/*IRFS3001*/    /*binary search*/
/*IRFS3001*/    left = 0;
/*IRFS3001*/    if (rf_band == FrequencyBand850 || rf_band == FrequencyBand900)
/*IRFS3001*/    {    right = 16;
/*IRFS3001*/    }
/*IRFS3001*/    else
/*IRFS3001*/    {    right = 14;
/*IRFS3001*/    }
/*IRFS3001*/    while (left <= right)
/*IRFS3001*/    {
/*IRFS3001*/       middle = (left + right)/2;
/*IRFS3001*/       if ( request_gain >= (agcptr+middle)->pos_gain )
/*IRFS3001*/          right = middle - 1;
/*IRFS3001*/       else
/*IRFS3001*/          left  = middle + 1;
/*IRFS3001*/    }
/*IRFS3001*/    agcptr = (agcptr+left);
/*IRFS3001*/    bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*IRFS3001*/    real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*IRFS3001*/    setting   = agcptr->setting | ((( 1<<(5-bit_no) )-1)<<17);
/*IRFS3001*/
/*IRFS3001*/    *gain_setting = setting;
/*IRFS3001*/    return( real_gain );
/*IRFS3001*/ }
/*IRFS3001*/
#endif

#if IS_RF_AD6548
/*AD6548*/ #define  GAIN_STEP              3
/*AD6548*/
/*AD6548*/ #define  PVOFSL                 (-33)
/*AD6548*/ #define  PVOFSH                 (-34)
/*AD6548*/
/*AD6548*/ #define  RF_GSM850_MAXGAIN      ((80+PVOFSL)*(PWRRES))
/*AD6548*/ #define  RF_GSM850_MINGAIN      (( 3+PVOFSL)*(PWRRES))
/*AD6548*/ #define  RF_GSM_MAXGAIN         RF_GSM850_MAXGAIN
/*AD6548*/ #define  RF_GSM_MINGAIN         RF_GSM850_MINGAIN
/*AD6548*/ #define  RF_DCS_MAXGAIN         ((80+PVOFSH)*(PWRRES))
/*AD6548*/ #define  RF_DCS_MINGAIN         (( 3+PVOFSH)*(PWRRES))
/*AD6548*/ #define  RF_PCS_MAXGAIN         RF_DCS_MAXGAIN
/*AD6548*/ #define  RF_PCS_MINGAIN         RF_DCS_MINGAIN
/*AD6548*/
/*AD6548*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*AD6548*/ { {GBOUND( (23+PVOFSL),(21+PVOFSL) ), GC_A(2,23+PVOFSL), 0x000005 },
/*AD6548*/   {GBOUND( ( 3+PVOFSL),( 3+PVOFSL) ), GC_A(2, 3+PVOFSL), 0x001005 },
/*AD6548*/ };
/*AD6548*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*AD6548*/ { {GBOUND( (23+PVOFSL),(21+PVOFSL) ), GC_A(2,23+PVOFSL), 0x000005 },
/*AD6548*/   {GBOUND( ( 3+PVOFSL),( 3+PVOFSL) ), GC_A(2, 3+PVOFSL), 0x001005 },
/*AD6548*/ };
/*AD6548*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2]=
/*AD6548*/ { {GBOUND( (23+PVOFSH),(21+PVOFSH) ), GC_A(2,23+PVOFSH), 0x000005 },
/*AD6548*/   {GBOUND( ( 3+PVOFSH),( 3+PVOFSH) ), GC_A(2, 3+PVOFSH), 0x001005 },
/*AD6548*/ };
/*AD6548*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2]=
/*AD6548*/ { {GBOUND( (23+PVOFSH),(21+PVOFSH) ), GC_A(2,23+PVOFSH), 0x000005 },
/*AD6548*/   {GBOUND( ( 3+PVOFSH),( 3+PVOFSH) ), GC_A(2, 3+PVOFSH), 0x001005 },
/*AD6548*/ };
/*AD6548*/
/*AD6548*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*AD6548*/ { {                   0,                      0    }, /*#FrequencyBand400  */
/*AD6548*/   { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*AD6548*/   { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*AD6548*/   { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*AD6548*/   { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*AD6548*/ };
/*AD6548*/
/*AD6548*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*AD6548*/ {  0,                                              /*#FrequencyBand400  */
/*AD6548*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*AD6548*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*AD6548*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*AD6548*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*AD6548*/ };
/*AD6548*/
/*AD6548*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*AD6548*/ {  int   max_gain, min_gain, real_gain;
/*AD6548*/    const int*    d32ptr;
/*AD6548*/    const sL1DAGCDATA*  agcptr;
/*AD6548*/    long  setting;
/*AD6548*/    int   bit_no;
/*AD6548*/
/*AD6548*/    /* evaluate the range of available gain */
/*AD6548*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*AD6548*/    max_gain = *d32ptr++;
/*AD6548*/    min_gain = *d32ptr;
/*AD6548*/
/*AD6548*/    /* clipping the request gain to the avialable gain */
/*AD6548*/    if( request_gain>=max_gain )
/*AD6548*/    {  request_gain = max_gain;  }
/*AD6548*/    else  if( request_gain<=min_gain )
/*AD6548*/    {  request_gain = min_gain;  }
/*AD6548*/
/*AD6548*/    /* evaluate the real gain setting */
/*AD6548*/    agcptr = AGC_TABLE[rf_band];
/*AD6548*/    if( request_gain < agcptr->pos_gain )
/*AD6548*/    {  agcptr++;
/*AD6548*/    }
/*AD6548*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*AD6548*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*AD6548*/       setting   = agcptr->setting | (bit_no<<7);
/*AD6548*/    }
/*AD6548*/
/*AD6548*/    *gain_setting = setting;
/*AD6548*/    return( real_gain );
/*AD6548*/ }
/*AD6548*/
#endif

#if IS_RF_AD6546
/*AD6546*/ #define  GAIN_STEP              3
/*AD6546*/
/*AD6546*/ #define  PVOFSL                 (-33)
/*AD6546*/ #define  PVOFSH                 (-33)
/*AD6546*/
/*AD6546*/ #define  RF_GSM850_MAXGAIN      ((74+PVOFSL)*(PWRRES))
/*AD6546*/ #define  RF_GSM850_MINGAIN      (( 3+PVOFSL)*(PWRRES))
/*AD6546*/ #define  RF_GSM_MAXGAIN         RF_GSM850_MAXGAIN
/*AD6546*/ #define  RF_GSM_MINGAIN         RF_GSM850_MINGAIN
/*AD6546*/ #define  RF_DCS_MAXGAIN         ((74+PVOFSH)*(PWRRES))
/*AD6546*/ #define  RF_DCS_MINGAIN         (( 3+PVOFSH)*(PWRRES))
/*AD6546*/ #define  RF_PCS_MAXGAIN         RF_DCS_MAXGAIN
/*AD6546*/ #define  RF_PCS_MINGAIN         RF_DCS_MINGAIN
/*AD6546*/
/*AD6546*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*AD6546*/ { {GBOUND( (23+PVOFSL),(21+PVOFSL) ), GC_A(2,23+PVOFSL), 0x000005 },
/*AD6546*/   {GBOUND( ( 3+PVOFSL),( 3+PVOFSL) ), GC_A(2, 3+PVOFSL), 0x001005 },
/*AD6546*/ };
/*AD6546*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*AD6546*/ { {GBOUND( (23+PVOFSL),(21+PVOFSL) ), GC_A(2,23+PVOFSL), 0x000005 },
/*AD6546*/   {GBOUND( ( 3+PVOFSL),( 3+PVOFSL) ), GC_A(2, 3+PVOFSL), 0x001005 },
/*AD6546*/ };
/*AD6546*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2]=
/*AD6546*/ { {GBOUND( (23+PVOFSH),(21+PVOFSH) ), GC_A(2,23+PVOFSH), 0x000005 },
/*AD6546*/   {GBOUND( ( 3+PVOFSH),( 3+PVOFSH) ), GC_A(2, 3+PVOFSH), 0x001005 },
/*AD6546*/ };
/*AD6546*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2]=
/*AD6546*/ { {GBOUND( (23+PVOFSH),(21+PVOFSH) ), GC_A(2,23+PVOFSH), 0x000005 },
/*AD6546*/   {GBOUND( ( 3+PVOFSH),( 3+PVOFSH) ), GC_A(2, 3+PVOFSH), 0x001005 },
/*AD6546*/ };
/*AD6546*/
/*AD6546*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*AD6546*/ { {                   0,                      0    }, /*#FrequencyBand400  */
/*AD6546*/   { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*AD6546*/   { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*AD6546*/   { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*AD6546*/   { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*AD6546*/ };
/*AD6546*/
/*AD6546*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*AD6546*/ {  0,                                              /*#FrequencyBand400  */
/*AD6546*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*AD6546*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*AD6546*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*AD6546*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*AD6546*/ };
/*AD6546*/
/*AD6546*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*AD6546*/ {
/*AD6546*/    int   max_gain, min_gain, real_gain;
/*AD6546*/    const int*    d32ptr;
/*AD6546*/    const sL1DAGCDATA*  agcptr;
/*AD6546*/    long  setting;
/*AD6546*/    int   bit_no;
/*AD6546*/
/*AD6546*/    /* evaluate the range of available gain */
/*AD6546*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*AD6546*/    max_gain = *d32ptr++;
/*AD6546*/    min_gain = *d32ptr;
/*AD6546*/
/*AD6546*/    /* clipping the request gain to the avialable gain */
/*AD6546*/    if( request_gain>=max_gain )
/*AD6546*/    {  request_gain = max_gain;  }
/*AD6546*/    else  if( request_gain<=min_gain )
/*AD6546*/    {  request_gain = min_gain;  }
/*AD6546*/
/*AD6546*/    /* evaluate the real gain setting */
/*AD6546*/    agcptr = AGC_TABLE[rf_band];
/*AD6546*/    if( request_gain < agcptr->pos_gain )
/*AD6546*/    {  agcptr++;
/*AD6546*/    }
/*AD6546*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*AD6546*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*AD6546*/       setting   = agcptr->setting | (bit_no<<7);
/*AD6546*/    }
/*AD6546*/
/*AD6546*/    *gain_setting = setting;
/*AD6546*/    return( real_gain );
/*AD6546*/ }
/*AD6546*/
#endif

#if IS_RF_MT6162 || IS_RF_MT6163
/*MT6162*/ #define  GAIN_STEP              3
/*MT6162*/
/*MT6162*/ #define  PVOFSL                 (34)
/*MT6162*/ #define  PVOFSH                 (34)
/*MT6162*/
/*MT6162*/ #define  RF_GSM850_MAXGAIN      ((66-PVOFSL)*(PWRRES))
/*MT6162*/ #define  RF_GSM850_MINGAIN      (( 9-PVOFSL)*(PWRRES))
/*MT6162*/ #define  RF_GSM_MAXGAIN         RF_GSM850_MAXGAIN
/*MT6162*/ #define  RF_GSM_MINGAIN         RF_GSM850_MINGAIN
/*MT6162*/ #define  RF_DCS_MAXGAIN         ((66-PVOFSH)*(PWRRES))
/*MT6162*/ #define  RF_DCS_MINGAIN         (( 9-PVOFSH)*(PWRRES))
/*MT6162*/ #define  RF_PCS_MAXGAIN         RF_DCS_MAXGAIN
/*MT6162*/ #define  RF_PCS_MINGAIN         RF_DCS_MINGAIN
/*MT6162*/
/*MT6162*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[3] =
/*MT6162*/ { {GBOUND( (54-PVOFSL),(51-PVOFSL) ), GC_A(8,54-PVOFSL), 0x00300 },
/*MT6162*/   {GBOUND( (36-PVOFSL),(33-PVOFSL) ), GC_A(5,36-PVOFSL), 0x00200 },
/*MT6162*/   {GBOUND( ( 9-PVOFSL),( 9-PVOFSL) ), GC_A(0, 9-PVOFSL), 0x00100 },
/*MT6162*/ };
/*MT6162*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[3] =
/*MT6162*/ { {GBOUND( (54-PVOFSL),(51-PVOFSL) ), GC_A(8,54-PVOFSL), 0x00300 },
/*MT6162*/   {GBOUND( (36-PVOFSL),(33-PVOFSL) ), GC_A(5,36-PVOFSL), 0x00200 },
/*MT6162*/   {GBOUND( ( 9-PVOFSL),( 9-PVOFSL) ), GC_A(0, 9-PVOFSL), 0x00100 },
/*MT6162*/ };
/*MT6162*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[3]=
/*MT6162*/ { {GBOUND( (54-PVOFSH),(51-PVOFSH) ), GC_A(8,54-PVOFSH), 0x00300 },
/*MT6162*/   {GBOUND( (36-PVOFSH),(33-PVOFSH) ), GC_A(5,36-PVOFSH), 0x00200 },
/*MT6162*/   {GBOUND( ( 9-PVOFSH),( 9-PVOFSH) ), GC_A(0, 9-PVOFSH), 0x00100 },
/*MT6162*/ };
/*MT6162*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[3]=
/*MT6162*/ { {GBOUND( (54-PVOFSH),(51-PVOFSH) ), GC_A(8,54-PVOFSH), 0x00300 },
/*MT6162*/   {GBOUND( (36-PVOFSH),(33-PVOFSH) ), GC_A(5,36-PVOFSH), 0x00200 },
/*MT6162*/   {GBOUND( ( 9-PVOFSH),( 9-PVOFSH) ), GC_A(0, 9-PVOFSH), 0x00100 },
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6162*/ { {                   0,                      0    }, /* FrequencyBand400  */
/*MT6162*/   { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6162*/   { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6162*/   { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6162*/   { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6162*/ {  0,                                                 /* FrequencyBand400  */
/*MT6162*/    AGC_TABLE_GSM850,                                  /* FrequencyBand850  */
/*MT6162*/    AGC_TABLE_GSM900,                                  /* FrequencyBand900  */
/*MT6162*/    AGC_TABLE_DCS1800,                                 /* FrequencyBand1800 */
/*MT6162*/    AGC_TABLE_PCS1900,                                 /* FrequencyBand1900 */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6162*/ {
/*MT6162*/    int   max_gain, min_gain, real_gain;
/*MT6162*/    const int*    d32ptr;
/*MT6162*/    const sL1DAGCDATA*  agcptr;
/*MT6162*/    sLNAGAINOFFSET* lnaptr;
/*MT6162*/    sAGCGAINOFFSET* ofsptr;
/*MT6162*/    long  setting;
/*MT6162*/    int   bit_no, idx, lna_path_loss;
/*MT6162*/ #if IS_RF_RX_DCOC_SUPPORT
/*MT6162*/    int   biquad_gain;
/*MT6162*/    signed short  dc_offset_i, dc_offset_q;
/*MT6162*/ #endif
/*MT6162*/
/*MT6162*/    /* evaluate the range of available gain */
/*MT6162*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6162*/    max_gain = *d32ptr++;
/*MT6162*/    min_gain = *d32ptr;
/*MT6162*/
/*MT6162*/
/*MT6162*/    /* choose the LNA path loss */
/*MT6162*/    lnaptr = LNA_PATHLOSS_TABLE[rf_band];
/*MT6162*/    /* get the arfcn section */
/*MT6162*/    ofsptr = AGC_PATHLOSS_TABLE[rf_band];
/*MT6162*/    while( ofsptr->max_arfcn>=0 )
/*MT6162*/    {  if( arfcn <= ofsptr->max_arfcn )
/*MT6162*/       {  break;  }
/*MT6162*/       ofsptr++;
/*MT6162*/       lnaptr++;
/*MT6162*/    }
/*MT6162*/
/*MT6162*/    /* evaluate the real gain setting */
/*MT6162*/    agcptr = AGC_TABLE[rf_band];
/*MT6162*/    while( request_gain < agcptr->pos_gain )
/*MT6162*/    {  agcptr++;
/*MT6162*/       if(agcptr->pos_gain == GBOUND( ( 9-PVOFSL),( 9-PVOFSL) ))
/*MT6162*/       {
/*MT6162*/          break;
/*MT6162*/       }
/*MT6162*/    }
/*MT6162*/    {  idx       = (int)(((agcptr->setting)>>8)&0x3);
/*MT6162*/       if( idx==3 )      /* LNA_High */
/*MT6162*/       {  lna_path_loss = 0;  }
/*MT6162*/       else if( idx==2 ) /* LNA_Middle */
/*MT6162*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_middle-ofsptr->gain_offset));  }
/*MT6162*/       else              /* LNA_Low */
/*MT6162*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_low-ofsptr->gain_offset));     }
/*MT6162*/
/*MT6162*/       request_gain+=lna_path_loss;
/*MT6162*/
/*MT6162*/       /* clipping the request gain to the avialable gain */
/*MT6162*/       if( request_gain>=max_gain )
/*MT6162*/       {  request_gain = max_gain;  }
/*MT6162*/       else  if( request_gain<=min_gain )
/*MT6162*/       {  request_gain = min_gain;  }
/*MT6162*/
/*MT6162*/       bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6162*/       real_gain = -lna_path_loss+REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6162*/       setting   = agcptr->setting | (bit_no&0xF);
/*MT6162*/    }
/*MT6162*/
/*MT6162*/    *gain_setting = setting;
/*MT6162*/
/*MT6162*/    l1d_rf2.rx_dc_offset = 0;
/*MT6162*/ #if IS_RF_RX_DCOC_SUPPORT
/*MT6162*/    biquad_gain = BBGAIN_DECODE_TABLE[(setting&0xF)][0];
/*MT6162*/    dc_offset_i = l1d_rf2.rx_dc_offset_i[rf_band-1][biquad_gain/6];
/*MT6162*/    dc_offset_q = l1d_rf2.rx_dc_offset_q[rf_band-1][biquad_gain/6];
/*MT6162*/    #if IS_RF_RX_DCOC_WITH_PRECISION_IMPROVEMENT
/*MT6162*/    if( dc_offset_i>0 )
/*MT6162*/       dc_offset_i = (  ( dc_offset_i+(1<<(ALPHA_FILTER_SCALE-1)))>>ALPHA_FILTER_SCALE  );
/*MT6162*/    else
/*MT6162*/       dc_offset_i = (-((-dc_offset_i+(1<<(ALPHA_FILTER_SCALE-1)))>>ALPHA_FILTER_SCALE));
/*MT6162*/    if( dc_offset_q>0 )
/*MT6162*/       dc_offset_q = (  ( dc_offset_q+(1<<(ALPHA_FILTER_SCALE-1)))>>ALPHA_FILTER_SCALE  );
/*MT6162*/    else
/*MT6162*/       dc_offset_q = (-((-dc_offset_q+(1<<(ALPHA_FILTER_SCALE-1)))>>ALPHA_FILTER_SCALE));
/*MT6162*/    #endif /* IS_RF_RX_DCOC_WITH_PRECISION_IMPROVEMENT */
/*MT6162*/    l1d_rf2.rx_dc_offset = (unsigned long)(((dc_offset_q&0xFF)<<8)|(dc_offset_i&0xFF) );
/*MT6162*/ #endif
/*MT6162*/
/*MT6162*/    return( real_gain );
/*MT6162*/ }
/*MT6162*/
#endif

#if IS_RF_MT6280RF
/*MT6280RF*/
/*MT6280RF*/ #define  GAIN_STEP               3
/*MT6280RF*/ #define  PVOFSL                  34
/*MT6280RF*/ #define  PVOFSH                  34
/*MT6280RF*/ #define  MIXER_GAIN             (9*(PWRRES))
/*MT6280RF*/ #define  RF_GSM850_MAXGAIN      (( 51-PVOFSL )*(PWRRES))
/*MT6280RF*/ #define  RF_GSM850_MINGAIN      (( -3-PVOFSL )*(PWRRES))
/*MT6280RF*/ #define  RF_GSM_MAXGAIN         (( 51-PVOFSL )*(PWRRES))
/*MT6280RF*/ #define  RF_GSM_MINGAIN         (( -3-PVOFSL )*(PWRRES))
/*MT6280RF*/ #define  RF_DCS_MAXGAIN         (( 51-PVOFSH )*(PWRRES))
/*MT6280RF*/ #define  RF_DCS_MINGAIN         (( -3-PVOFSH )*(PWRRES))
/*MT6280RF*/ #define  RF_PCS_MAXGAIN         (( 51-PVOFSH )*(PWRRES))
/*MT6280RF*/ #define  RF_PCS_MINGAIN         (( -3-PVOFSH )*(PWRRES))
/*MT6280RF*/
/*MT6280RF*/ /* if no rx cal. DCOC_DACI/DCOC_DACQ in CW12 use the default value */
/*MT6280RF*/ #define  RXIF_DCOC_DACI_M       0x90000
/*MT6280RF*/ #define  RXIF_DCOC_DACQ_M       0x00000
/*MT6280RF*/
/*MT6280RF*/ /* GSM850....................................................................*/
/*MT6280RF*/
/*MT6280RF*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[3] =
/*MT6280RF*/ {  {  GBOUND(( 39-PVOFSL ),( 36-PVOFSL ) ), GC_A( 4,( 39-PVOFSL ) ), BSI_CW(0x0C, 0x00080) },
/*MT6280RF*/    {  GBOUND(( 21-PVOFSL ),( 18-PVOFSL ) ), GC_A( 2,( 21-PVOFSL ) ), BSI_CW(0x0C, 0x00020) },
/*MT6280RF*/    {  GBOUND(( -3-PVOFSL ),( -3-PVOFSL ) ), GC_A( 0,( -3-PVOFSL ) ), BSI_CW(0x0C, 0x00000) },
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ /* GSM900....................................................................*/
/*MT6280RF*/
/*MT6280RF*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[3] =
/*MT6280RF*/ {  {  GBOUND(( 39-PVOFSL ),( 36-PVOFSL ) ), GC_A( 4,( 39-PVOFSL ) ), BSI_CW(0x0C, 0x00080) },
/*MT6280RF*/    {  GBOUND(( 21-PVOFSL ),( 18-PVOFSL ) ), GC_A( 2,( 21-PVOFSL ) ), BSI_CW(0x0C, 0x00020) },
/*MT6280RF*/    {  GBOUND(( -3-PVOFSL ),( -3-PVOFSL ) ), GC_A( 0,( -3-PVOFSL ) ), BSI_CW(0x0C, 0x00000) },
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ /* DCS1800...................................................................*/
/*MT6280RF*/
/*MT6280RF*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[3] =
/*MT6280RF*/ {  {  GBOUND(( 39-PVOFSH ),( 36-PVOFSH ) ), GC_A( 4,( 39-PVOFSH ) ), BSI_CW(0x0C, 0x00080) },
/*MT6280RF*/    {  GBOUND(( 21-PVOFSH ),( 18-PVOFSH ) ), GC_A( 2,( 21-PVOFSH ) ), BSI_CW(0x0C, 0x00020) },
/*MT6280RF*/    {  GBOUND(( -3-PVOFSH ),( -3-PVOFSH ) ), GC_A( 0,( -3-PVOFSH ) ), BSI_CW(0x0C, 0x00000) },
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ /* PCS1900...................................................................*/
/*MT6280RF*/
/*MT6280RF*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[3] =
/*MT6280RF*/ {  {  GBOUND(( 39-PVOFSH ),( 36-PVOFSH ) ), GC_A( 4,( 39-PVOFSH ) ), BSI_CW(0x0C, 0x00080) },
/*MT6280RF*/    {  GBOUND(( 21-PVOFSH ),( 18-PVOFSH ) ), GC_A( 2,( 21-PVOFSH ) ), BSI_CW(0x0C, 0x00020) },
/*MT6280RF*/    {  GBOUND(( -3-PVOFSH ),( -3-PVOFSH ) ), GC_A( 0,( -3-PVOFSH ) ), BSI_CW(0x0C, 0x00000) },
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ /*...........................................................................*/
/*MT6280RF*/
/*MT6280RF*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6280RF*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6280RF*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6280RF*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6280RF*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6280RF*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6280RF*/ {  0,                                              /*#FrequencyBand400  */
/*MT6280RF*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6280RF*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6280RF*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6280RF*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/
/*MT6280RF*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6280RF*/
/*MT6280RF*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6280RF*/ {  int   max_gain, min_gain, real_gain;
/*MT6280RF*/    const int*    d32ptr;
/*MT6280RF*/    const sL1DAGCDATA*  agcptr;
/*MT6280RF*/    sLNAGAINOFFSET*     lnaptr;
/*MT6280RF*/    sAGCGAINOFFSET*     ofsptr;
/*MT6280RF*/    long  setting;
/*MT6280RF*/    int   bit_no, idx, lna_path_loss;
/*MT6280RF*/
/*MT6280RF*/    /* evaluate the range of available gain */
/*MT6280RF*/    d32ptr   = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6280RF*/    max_gain = *d32ptr++;
/*MT6280RF*/    min_gain = *d32ptr;
/*MT6280RF*/
/*MT6280RF*/    /* clipping the request gain to the avialable gain */
/*MT6280RF*/    if( request_gain>=max_gain )
/*MT6280RF*/    {  request_gain = max_gain;  
/*MT6280RF*/    }
/*MT6280RF*/    else if( request_gain<=min_gain )
/*MT6280RF*/    {  request_gain = min_gain;  
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    /* choose the LNA path loss */
/*MT6280RF*/    lnaptr = LNA_PATHLOSS_TABLE[rf_band];
/*MT6280RF*/    /* get the arfcn section */
/*MT6280RF*/    ofsptr = AGC_PATHLOSS_TABLE[rf_band];
/*MT6280RF*/    while( ofsptr->max_arfcn>=0 )
/*MT6280RF*/    {  if( arfcn <= ofsptr->max_arfcn )
/*MT6280RF*/       {  break;  }
/*MT6280RF*/       ofsptr++;
/*MT6280RF*/       lnaptr++;
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    /* evaluate the real gain setting */
/*MT6280RF*/    agcptr = AGC_TABLE[rf_band];
/*MT6280RF*/    while( request_gain < agcptr->pos_gain )
/*MT6280RF*/    {  agcptr++;
/*MT6280RF*/    }
/*MT6280RF*/    {
/*MT6280RF*/       idx = (int)(((agcptr->setting)>>5)&0x7);
/*MT6280RF*/       if( idx==4 )      /* LNA_High */
/*MT6280RF*/       {  lna_path_loss = 0;  }
/*MT6280RF*/       else if( idx==1 ) /* LNA_Middle */
/*MT6280RF*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_middle-ofsptr->gain_offset));  }
/*MT6280RF*/       else              /* LNA_Low */
/*MT6280RF*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_low-ofsptr->gain_offset));     }
/*MT6280RF*/
/*MT6280RF*/       bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6280RF*/       real_gain = -lna_path_loss+REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6280RF*/    #if IS_HEADROOM_DETECTION_SUPPORT || IS_INBAND_BLOCKER_DETECTION_SUPPORT
/*MT6280RF*/       if( ( ((l1d_rf.blk_flag)&(HRD_FOUND)) && (request_gain >= -4*PWRRES) ) || ( ((l1d_rf.blk_flag)&(IBB_FOUND)) && (request_gain >= 8*PWRRES) ) )
/*MT6280RF*/       {        /* CW12: LNA GAIN     |MIXER GAIN| IF GAIN */
/*MT6280RF*/          setting   = agcptr->setting | (0x1<<4) | (bit_no&0xF); 
/*MT6280RF*/          real_gain -= MIXER_GAIN;
/*MT6280RF*/       }
/*MT6280RF*/       else
/*MT6280RF*/    #endif
/*MT6280RF*/       {  setting   = agcptr->setting | (bit_no&0xF);  
/*MT6280RF*/       }
/*MT6280RF*/    }
/*MT6280RF*/    
/*MT6280RF*/    /* if cal. DCOC_DACI/DCOC_DACQ in CW12 use the calibrated data */
/*MT6280RF*/    if( (l1d_rf2.is_power_on_cal)&(RXRC_DCOC_CAL_DONE) )
/*MT6280RF*/    {  setting |= ((l1d_rf2.rxif_dcoc_daci_m[rf_band-FrequencyBand850][bit_no]&0x3F)<<14) | ((l1d_rf2.rxif_dcoc_dacq_m[rf_band-FrequencyBand850][bit_no]&0x3F)<<8);  
/*MT6280RF*/    }
/*MT6280RF*/    else
/*MT6280RF*/    {  setting |= RXIF_DCOC_DACI_M | RXIF_DCOC_DACQ_M;  
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    *gain_setting = setting;
/*MT6280RF*/    return( real_gain );
/*MT6280RF*/ }
/*MT6280RF*/
   #if IS_W_CANCELLATION_SUPPORT
/*MT6280RF*/ unsigned short   L1D_RF_FindGainStep( unsigned long gain_setting, FrequencyBand rf_band  )
/*MT6280RF*/ {
/*MT6280RF*/    int lna_gain_setting;
/*MT6280RF*/    int tz_gain_setting;
/*MT6280RF*/    int if_gain_setting;
/*MT6280RF*/
/*MT6280RF*/    lna_gain_setting = (gain_setting>>5) & 0x7;
/*MT6280RF*/    tz_gain_setting  = (gain_setting>>4) & 0x1;
/*MT6280RF*/    if_gain_setting  = (gain_setting>>0) & 0xF; /* bit_no */
/*MT6280RF*/
/*MT6280RF*/    #if IS_HEADROOM_DETECTION_SUPPORT || IS_INBAND_BLOCKER_DETECTION_SUPPORT
/*MT6280RF*/    if( tz_gain_setting == 0x1 )               /*        ACI2   Gain Table      */
/*MT6280RF*/    {                                          /* ----------------------------- */
/*MT6280RF*/       if( lna_gain_setting == 0x4 )           /* gain| bit | tz_gain |lna_gain */
/*MT6280RF*/       {                                       /*  idx|  no | setting | setting */
/*MT6280RF*/          return ( if_gain_setting+8 );        /* ----+-----+---------+-------- */
/*MT6280RF*/       }                                       /*  16 |  8  |  (tz=1) |         */
/*MT6280RF*/       else if( lna_gain_setting == 0x1 )      /*  15 |  7  |         |  LNA    */
/*MT6280RF*/       {                                       /*  14 |  6  |  ACI2   |  High   */
/*MT6280RF*/          if( if_gain_setting>=5 )             /*  13 |  5  |         |  Gain   */
/*MT6280RF*/             return ( if_gain_setting-4+8);    /*  12 |  4  |  Gain   |         */
/*MT6280RF*/          else                                 /* ----+-----|         |-------- */
/*MT6280RF*/             return 0;                         /*  11 |  7  |  Table  |  LNA    */
/*MT6280RF*/       }                                       /*  10 |  6  |         |  Mid    */
/*MT6280RF*/       else                                    /*   9 |  5  |         |  Gain   */
/*MT6280RF*/       {                                       /* ----+-----+---------+-------- */
/*MT6280RF*/          return 0;                            /*   0 | 0~4 |       other       */
/*MT6280RF*/       }                                       /* ----------------------------- */
/*MT6280RF*/    }
/*MT6280RF*/    else
/*MT6280RF*/    #endif
/*MT6280RF*/    {                                          /*        Normal Gain Table      */
/*MT6280RF*/       if( lna_gain_setting == 0x4 )           /* ----------------------------- */
/*MT6280RF*/       {                                       /* gain| bit | tz_gain |lna_gain */
/*MT6280RF*/          return ( if_gain_setting   );        /*  idx|  no | setting | setting */
/*MT6280RF*/       }                                       /* ----+-----+---------+-------- */
/*MT6280RF*/       else if( lna_gain_setting == 0x1 )      /*   8 |  8  |  (tz=0) |         */
/*MT6280RF*/       {                                       /*   7 |  7  |         |  LNA    */
/*MT6280RF*/          if( if_gain_setting>=5 )             /*   6 |  6  |  Normal |  High   */
/*MT6280RF*/             return ( if_gain_setting-4 );     /*   5 |  5  |         |  Gain   */
/*MT6280RF*/          else                                 /*   4 |  4  |  Gain   |         */
/*MT6280RF*/             return 0;                         /* ----+-----|         |-------- */
/*MT6280RF*/       }                                       /*   3 |  7  |  Table  |  LNA    */
/*MT6280RF*/       else                                    /*   2 |  6  |         |  Mid    */
/*MT6280RF*/       {                                       /*   1 |  5  |         |  Gain   */
/*MT6280RF*/          return 0;                            /* ----+-----+------------------ */
/*MT6280RF*/       }                                       /*   0 | 0~4 |       other       */
/*MT6280RF*/    }                                          /* ----------------------------- */
/*MT6280RF*/ }
/*MT6280RF*/
   #endif
#endif

#if IS_RF_MT6169
/*MT6169*/
/*MT6169*/ #define  GAIN_STEP              3
/*MT6169*/ #define  PVOFSL                 34
/*MT6169*/ #define  PVOFSH                 34
/*MT6169*/ #define  LPF2_DROP_GAIN         ROUNDINT(6*(PWRRES))
/*MT6169*/ #define  HRD_LB_THRESHOLD       ROUNDINT((39.4-PVOFSL)*(PWRRES))
/*MT6169*/ #define  HRD_HB_THRESHOLD       ROUNDINT((39.4-PVOFSH)*(PWRRES))
/*MT6169*/ #define  IBBD_LB_THRESHOLD      ROUNDINT((42.4-PVOFSL)*(PWRRES))
/*MT6169*/ #define  IBBD_HB_THRESHOLD      ROUNDINT((42.4-PVOFSH)*(PWRRES))
/*MT6169*/ #define  IBBD_REAL_GAIN1_L      ROUNDINT((45.4-PVOFSL)*(PWRRES))
/*MT6169*/ #define  IBBD_REAL_GAIN1_H      ROUNDINT((45.4-PVOFSH)*(PWRRES))
/*MT6169*/ #define  IBBD_REAL_GAIN2_L      ROUNDINT((39.4-PVOFSL)*(PWRRES))
/*MT6169*/ #define  IBBD_REAL_GAIN2_H      ROUNDINT((39.4-PVOFSH)*(PWRRES))
/*MT6169*/ #define  IBBD_GAIN1_SETTING     BSI_CW(0x36, 0x8209E)
/*MT6169*/ #define  IBBD_GAIN2_SETTING     BSI_CW(0x36, 0x82096)
/*MT6169*/ #define  RF_GSM850_MAXGAIN      (( 51.4-PVOFSL )*(PWRRES))
/*MT6169*/ #define  RF_GSM850_MINGAIN      (( -2.6-PVOFSL )*(PWRRES))
/*MT6169*/ #define  RF_GSM_MAXGAIN         (( 51.4-PVOFSL )*(PWRRES))
/*MT6169*/ #define  RF_GSM_MINGAIN         (( -2.6-PVOFSL )*(PWRRES))
/*MT6169*/ #define  RF_DCS_MAXGAIN         (( 51.4-PVOFSH )*(PWRRES))
/*MT6169*/ #define  RF_DCS_MINGAIN         (( -2.6-PVOFSH )*(PWRRES))
/*MT6169*/ #define  RF_PCS_MAXGAIN         (( 51.4-PVOFSH )*(PWRRES))
/*MT6169*/ #define  RF_PCS_MINGAIN         (( -2.6-PVOFSH )*(PWRRES))
/*MT6169*/
/*MT6169*/ /* GSM850....................................................................*/
/*MT6169*/
/*MT6169*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[7] =
/*MT6169*/ {  {  GBOUND(( 51.4-PVOFSL ),( 42.4-PVOFSL ) ), GC_A( 6,( 51.4-PVOFSL ) ), BSI_CW(0x36, 0x820B8) },
/*MT6169*/    {  GBOUND(( 39.4-PVOFSL ),( 36.4-PVOFSL ) ), GC_A( 4,( 39.4-PVOFSL ) ), BSI_CW(0x36, 0x820B0) },
/*MT6169*/    {  GBOUND(( 27.4-PVOFSL ),( 24.4-PVOFSL ) ), GC_A( 2,( 27.4-PVOFSL ) ), BSI_CW(0x36, 0x82090) },
/*MT6169*/    {  GBOUND(( 21.4-PVOFSL ),( 18.4-PVOFSL ) ), GC_A( 2,( 21.4-PVOFSL ) ), BSI_CW(0x36, 0x82088) },
/*MT6169*/    {  GBOUND((  9.4-PVOFSL ),(  6.4-PVOFSL ) ), GC_A( 2,(  9.4-PVOFSL ) ), BSI_CW(0x36, 0x82018) },
/*MT6169*/    {  GBOUND((  3.4-PVOFSL ),(  0.4-PVOFSL ) ), GC_A( 2,(  3.4-PVOFSL ) ), BSI_CW(0x36, 0x82010) },
/*MT6169*/    {  GBOUND(( -2.6-PVOFSL ),( -2.6-PVOFSL ) ), GC_A( 2,( -2.6-PVOFSL ) ), BSI_CW(0x36, 0x82008) },
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ /* GSM900....................................................................*/
/*MT6169*/
/*MT6169*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[7] =
/*MT6169*/ {  {  GBOUND(( 51.4-PVOFSL ),( 42.4-PVOFSL ) ), GC_A( 6,( 51.4-PVOFSL ) ), BSI_CW(0x36, 0x820B8) },
/*MT6169*/    {  GBOUND(( 39.4-PVOFSL ),( 36.4-PVOFSL ) ), GC_A( 4,( 39.4-PVOFSL ) ), BSI_CW(0x36, 0x820B0) },
/*MT6169*/    {  GBOUND(( 27.4-PVOFSL ),( 24.4-PVOFSL ) ), GC_A( 2,( 27.4-PVOFSL ) ), BSI_CW(0x36, 0x82090) },
/*MT6169*/    {  GBOUND(( 21.4-PVOFSL ),( 18.4-PVOFSL ) ), GC_A( 2,( 21.4-PVOFSL ) ), BSI_CW(0x36, 0x82088) },
/*MT6169*/    {  GBOUND((  9.4-PVOFSL ),(  6.4-PVOFSL ) ), GC_A( 2,(  9.4-PVOFSL ) ), BSI_CW(0x36, 0x82018) },
/*MT6169*/    {  GBOUND((  3.4-PVOFSL ),(  0.4-PVOFSL ) ), GC_A( 2,(  3.4-PVOFSL ) ), BSI_CW(0x36, 0x82010) },
/*MT6169*/    {  GBOUND(( -2.6-PVOFSL ),( -2.6-PVOFSL ) ), GC_A( 2,( -2.6-PVOFSL ) ), BSI_CW(0x36, 0x82008) },
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ /* DCS1800...................................................................*/
/*MT6169*/
/*MT6169*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[7] =
/*MT6169*/ {  {  GBOUND(( 51.4-PVOFSH ),( 42.4-PVOFSH ) ), GC_A( 6,( 51.4-PVOFSH ) ), BSI_CW(0x36, 0x820B8) },
/*MT6169*/    {  GBOUND(( 39.4-PVOFSH ),( 36.4-PVOFSH ) ), GC_A( 4,( 39.4-PVOFSH ) ), BSI_CW(0x36, 0x820B0) },
/*MT6169*/    {  GBOUND(( 27.4-PVOFSH ),( 24.4-PVOFSH ) ), GC_A( 2,( 27.4-PVOFSH ) ), BSI_CW(0x36, 0x82090) },
/*MT6169*/    {  GBOUND(( 21.4-PVOFSH ),( 18.4-PVOFSH ) ), GC_A( 2,( 21.4-PVOFSH ) ), BSI_CW(0x36, 0x82088) },
/*MT6169*/    {  GBOUND((  9.4-PVOFSH ),(  6.4-PVOFSH ) ), GC_A( 2,(  9.4-PVOFSH ) ), BSI_CW(0x36, 0x82018) },
/*MT6169*/    {  GBOUND((  3.4-PVOFSH ),(  0.4-PVOFSH ) ), GC_A( 2,(  3.4-PVOFSH ) ), BSI_CW(0x36, 0x82010) },
/*MT6169*/    {  GBOUND(( -2.6-PVOFSH ),( -2.6-PVOFSH ) ), GC_A( 2,( -2.6-PVOFSH ) ), BSI_CW(0x36, 0x82008) },
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ /* PCS1900...................................................................*/
/*MT6169*/
/*MT6169*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[7] =
/*MT6169*/ {  {  GBOUND(( 51.4-PVOFSH ),( 42.4-PVOFSH ) ), GC_A( 6,( 51.4-PVOFSH ) ), BSI_CW(0x36, 0x820B8) },
/*MT6169*/    {  GBOUND(( 39.4-PVOFSH ),( 36.4-PVOFSH ) ), GC_A( 4,( 39.4-PVOFSH ) ), BSI_CW(0x36, 0x820B0) },
/*MT6169*/    {  GBOUND(( 27.4-PVOFSH ),( 24.4-PVOFSH ) ), GC_A( 2,( 27.4-PVOFSH ) ), BSI_CW(0x36, 0x82090) },
/*MT6169*/    {  GBOUND(( 21.4-PVOFSH ),( 18.4-PVOFSH ) ), GC_A( 2,( 21.4-PVOFSH ) ), BSI_CW(0x36, 0x82088) },
/*MT6169*/    {  GBOUND((  9.4-PVOFSH ),(  6.4-PVOFSH ) ), GC_A( 2,(  9.4-PVOFSH ) ), BSI_CW(0x36, 0x82018) },
/*MT6169*/    {  GBOUND((  3.4-PVOFSH ),(  0.4-PVOFSH ) ), GC_A( 2,(  3.4-PVOFSH ) ), BSI_CW(0x36, 0x82010) },
/*MT6169*/    {  GBOUND(( -2.6-PVOFSH ),( -2.6-PVOFSH ) ), GC_A( 2,( -2.6-PVOFSH ) ), BSI_CW(0x36, 0x82008) },
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ /*...........................................................................*/
/*MT6169*/
/*MT6169*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6169*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6169*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6169*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6169*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6169*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6169*/ {  0,                                              /*#FrequencyBand400  */
/*MT6169*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6169*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6169*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6169*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6169*/ };
/*MT6169*/
/*MT6169*/
/*MT6169*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6169*/
/*MT6169*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6169*/ {  int   max_gain, min_gain, real_gain;
/*MT6169*/    const int*    d32ptr;
/*MT6169*/    const sL1DAGCDATA*  agcptr;
/*MT6169*/    sLNAGAINOFFSET*     lnaptr;
/*MT6169*/    sAGCGAINOFFSET*     ofsptr;
/*MT6169*/    long  setting;
/*MT6169*/    int   bit_no, idx, lna_path_loss;
/*MT6169*/    #if IS_INBAND_BLOCKER_DETECTION_SUPPORT
/*MT6169*/    int   ibbd_threshold = (rf_band<FrequencyBand1800) ? IBBD_LB_THRESHOLD : IBBD_HB_THRESHOLD;
/*MT6169*/    #endif
/*MT6169*/    #if IS_HEADROOM_DETECTION_SUPPORT
/*MT6169*/    int   hrd_threshold  = (rf_band<FrequencyBand1800) ? HRD_LB_THRESHOLD  : HRD_HB_THRESHOLD;
/*MT6169*/    #endif
/*MT6169*/
/*MT6169*/    /* evaluate the range of available gain */
/*MT6169*/    d32ptr   = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6169*/    max_gain = *d32ptr++;
/*MT6169*/    min_gain = *d32ptr;
/*MT6169*/
/*MT6169*/    /* clipping the request gain to the avialable gain */
/*MT6169*/    if( request_gain>=max_gain )
/*MT6169*/    {  request_gain = max_gain;  
/*MT6169*/    }
/*MT6169*/    else if( request_gain<=min_gain )
/*MT6169*/    {  request_gain = min_gain;  
/*MT6169*/    }
/*MT6169*/
/*MT6169*/    /* choose the LNA path loss */
/*MT6169*/    lnaptr = LNA_PATHLOSS_TABLE[rf_band];
/*MT6169*/    /* get the arfcn section */
/*MT6169*/    ofsptr = AGC_PATHLOSS_TABLE[rf_band];
/*MT6169*/    while( ofsptr->max_arfcn>=0 )
/*MT6169*/    {  if( arfcn <= ofsptr->max_arfcn )
/*MT6169*/       {  break;  }
/*MT6169*/       ofsptr++;
/*MT6169*/       lnaptr++;
/*MT6169*/    }
/*MT6169*/
/*MT6169*/    /* evaluate the real gain setting */
/*MT6169*/    agcptr = AGC_TABLE[rf_band];
/*MT6169*/    while( request_gain < agcptr->pos_gain )
/*MT6169*/    {  agcptr++;
/*MT6169*/    }
/*MT6169*/    {
/*MT6169*/       idx = (int)(((agcptr->setting)>>5)&0x7);
/*MT6169*/       if( idx==5 )      /* LNA_High */
/*MT6169*/       {  lna_path_loss = 0;  }
/*MT6169*/       else if( idx==4 ) /* LNA_Middle */
/*MT6169*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_middle-ofsptr->gain_offset));  }
/*MT6169*/       else              /* LNA_Low */
/*MT6169*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_low-ofsptr->gain_offset));     }
/*MT6169*/
/*MT6169*/       bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6169*/       real_gain = -lna_path_loss+REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6169*/
/*MT6169*/       if( 0 )
/*MT6169*/       { /* do nothing */ }
/*MT6169*/    #if IS_INBAND_BLOCKER_DETECTION_SUPPORT
/*MT6169*/       else if( ((l1d_rf.blk_flag)&(IBB_FOUND)) && (request_gain >= ibbd_threshold) )
/*MT6169*/       {
/*MT6169*/          if( bit_no < 6)
/*MT6169*/          {  
/*MT6169*/             setting   = IBBD_GAIN2_SETTING; 
/*MT6169*/             real_gain = (rf_band<FrequencyBand1800) ? IBBD_REAL_GAIN2_L : IBBD_REAL_GAIN2_H;
/*MT6169*/          }
/*MT6169*/          else
/*MT6169*/          {
/*MT6169*/             setting   = IBBD_GAIN1_SETTING; 
/*MT6169*/             real_gain = (rf_band<FrequencyBand1800) ? IBBD_REAL_GAIN1_L : IBBD_REAL_GAIN1_H;
/*MT6169*/          }
/*MT6169*/       }
/*MT6169*/    #endif
/*MT6169*/    #if IS_HEADROOM_DETECTION_SUPPORT
/*MT6169*/       else if( ((l1d_rf.blk_flag)&(HRD_FOUND)) && (request_gain >= (hrd_threshold)) )
/*MT6169*/       {
/*MT6169*/          setting   = agcptr->setting | ((bit_no-2)&0xF); 
/*MT6169*/          real_gain -= LPF2_DROP_GAIN;
/*MT6169*/       }
/*MT6169*/    #endif
/*MT6169*/       else
/*MT6169*/       {  setting   = agcptr->setting | (bit_no&0xF);  
/*MT6169*/       }
/*MT6169*/    }
/*MT6169*/    
/*MT6169*/    *gain_setting = setting;
/*MT6169*/    return( real_gain );
/*MT6169*/ }
/*MT6169*/
   #if IS_W_CANCELLATION_SUPPORT
/*MT6169*/ unsigned short   L1D_RF_FindGainStep( unsigned long gain_setting, FrequencyBand rf_band  )
/*MT6169*/ {
/*MT6169*/    unsigned short lna_gain_setting;
/*MT6169*/    unsigned short cb_gain_setting;
/*MT6169*/    unsigned short if_gain_setting;
/*MT6169*/    unsigned short band_offset = (rf_band<FrequencyBand1800) ? 0 : 10;
/*MT6169*/    unsigned short gain_step;
/*MT6169*/
/*MT6169*/    lna_gain_setting = (unsigned short)( (gain_setting>>5) & 0x7 );
/*MT6169*/    cb_gain_setting  = (unsigned short)( (gain_setting>>3) & 0x3 );
/*MT6169*/    if_gain_setting  = (unsigned short)( (gain_setting>>0) & 0x7 ); /* bit_no */
/*MT6169*/
/*MT6169*/    if( lna_gain_setting == 0x5 )
/*MT6169*/    {
/*MT6169*/       if( if_gain_setting == 0x4 )
/*MT6169*/       {
/*MT6169*/          gain_step = (cb_gain_setting==3) ? if_gain_setting+5+band_offset : if_gain_setting+band_offset ;
/*MT6169*/       }
/*MT6169*/       else
/*MT6169*/       {
/*MT6169*/          gain_step = (if_gain_setting<4)  ? if_gain_setting+5+band_offset : if_gain_setting+band_offset ;
/*MT6169*/       }
/*MT6169*/    }
/*MT6169*/    else if( lna_gain_setting == 0x4 )
/*MT6169*/    {
/*MT6169*/       if( if_gain_setting ==0x6 )
/*MT6169*/       {
/*MT6169*/          gain_step = (cb_gain_setting==3) ? if_gain_setting+band_offset : if_gain_setting-1+band_offset ;
/*MT6169*/       }
/*MT6169*/       else
/*MT6169*/       {
/*MT6169*/          gain_step = (cb_gain_setting==2) ? if_gain_setting-2+band_offset : 0+band_offset ;
/*MT6169*/       }
/*MT6169*/    }
/*MT6169*/    else
/*MT6169*/    {
/*MT6169*/       gain_step = 0+band_offset;
/*MT6169*/    }
/*MT6169*/    return gain_step;
/*MT6169*/ }
/*MT6169*/
   #endif
#endif

#if IS_RF_MT6166
/*MT6166*/
/*MT6166*/ #define  GAIN_STEP               3
/*MT6166*/ #define  PVOFSL                  34
/*MT6166*/ #define  PVOFSH                  34
/*MT6166*/ #define  NORMAL_GAIN_TABLE_FLAG  0
/*MT6166*/ #define  OBB_GAIN_TABLE_FLAG     1
/*MT6166*/ #define  IBB_GAIN_TABLE_FLAG     2
/*MT6166*/ #define  ACI_GAIN_TABLE_FLAG     3
/*MT6166*/ #define  MIXER_GAIN             (9*(PWRRES))
/*MT6166*/ #define  LNA_GAIN_LB            (5*(PWRRES))
/*MT6166*/ #define  LNA_GAIN_HB            (6*(PWRRES))
/*MT6166*/ #define  LNA_GAIN_LB_M          (3.5*(PWRRES))
/*MT6166*/ #define  LNA_GAIN_HB_M          (2.5*(PWRRES))
/*MT6166*/ #define  IF_GAIN                (6*(PWRRES))
/*MT6166*/ #define  IF_GAIN_OBB            (9*(PWRRES))
/*MT6166*/ #if IS_DUAL_TALK_RX_GAIN_TABLE_CO_BAND_SUPPORT
/*MT6166*/ #define  RF_GSM850_MAXGAIN_H    (( 56.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM850_MINGAIN_H    ((    1-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM850_MAXGAIN_L    (( 56.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM850_MINGAIN_L    ((  2.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM_MAXGAIN_H       (( 56.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM_MINGAIN_H       ((    1-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM_MAXGAIN_L       (( 56.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM_MINGAIN_L       ((  2.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_DCS_MAXGAIN_H       (( 55.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_DCS_MINGAIN_H       ((  0.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_DCS_MAXGAIN_L       (( 55.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_DCS_MINGAIN_L       ((  1.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_PCS_MAXGAIN_H       (( 55.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_PCS_MINGAIN_H       ((  0.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_PCS_MAXGAIN_L       (( 55.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_PCS_MINGAIN_L       ((  1.5-PVOFSH )*(PWRRES))
/*MT6166*/
/*MT6166*/ /* GSM850....................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_GSM850_H[4] =
/*MT6166*/ {  {  GBOUND(( 38.5-PVOFSL ),( 28  -PVOFSL ) ), GC_A( 2,( 38.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 28  -PVOFSL ),( 22  -PVOFSL ) ), GC_A( 2,( 28  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 10  -PVOFSL ),(  1  -PVOFSL ) ), GC_A( 2,( 10  -PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  1  -PVOFSL ),(  1  -PVOFSL ) ), GC_A( 2,(  1  -PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_GSM850_L[4] =
/*MT6166*/ {  {  GBOUND(( 38.5-PVOFSL ),( 30  -PVOFSL ) ), GC_A( 2,( 38.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 30  -PVOFSL ),( 23.5-PVOFSL ) ), GC_A( 2,( 30  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 11.5-PVOFSL ),(  2.5-PVOFSL ) ), GC_A( 2,( 11.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  2.5-PVOFSL ),(  2.5-PVOFSL ) ), GC_A( 2,(  2.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /* GSM900....................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_GSM900_H[4] =
/*MT6166*/ {  {  GBOUND(( 38.5-PVOFSL ),( 28  -PVOFSL ) ), GC_A( 2,( 38.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 28  -PVOFSL ),( 22  -PVOFSL ) ), GC_A( 2,( 28  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 10  -PVOFSL ),(  1  -PVOFSL ) ), GC_A( 2,( 10  -PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  1  -PVOFSL ),(  1  -PVOFSL ) ), GC_A( 2,(  1  -PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_GSM900_L[4] =
/*MT6166*/ {  {  GBOUND(( 38.5-PVOFSL ),( 30  -PVOFSL ) ), GC_A( 2,( 38.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 30  -PVOFSL ),( 23.5-PVOFSL ) ), GC_A( 2,( 30  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 11.5-PVOFSL ),(  2.5-PVOFSL ) ), GC_A( 2,( 11.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  2.5-PVOFSL ),(  2.5-PVOFSL ) ), GC_A( 2,(  2.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /* DCS1800...................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800_H[4] =
/*MT6166*/ {  {  GBOUND(( 37.5-PVOFSL ),( 27.5-PVOFSL ) ), GC_A( 2,( 37.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 27.5-PVOFSL ),( 21.5-PVOFSL ) ), GC_A( 2,( 27.5-PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND((  9.5-PVOFSL ),(  0.5-PVOFSL ) ), GC_A( 2,(  9.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  0.5-PVOFSL ),(  0.5-PVOFSL ) ), GC_A( 2,(  0.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800_L[4] =
/*MT6166*/ {  {  GBOUND(( 37.5-PVOFSL ),( 29  -PVOFSL ) ), GC_A( 2,( 37.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 29  -PVOFSL ),( 22.5-PVOFSL ) ), GC_A( 2,( 29  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 10.5-PVOFSL ),(  1.5-PVOFSL ) ), GC_A( 2,( 10.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  1.5-PVOFSL ),(  1.5-PVOFSL ) ), GC_A( 2,(  1.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /* PCS1900...................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900_H[4] =
/*MT6166*/ {  {  GBOUND(( 37.5-PVOFSL ),( 27.5-PVOFSL ) ), GC_A( 2,( 37.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 27.5-PVOFSL ),( 21.5-PVOFSL ) ), GC_A( 2,( 27.5-PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND((  9.5-PVOFSL ),(  0.5-PVOFSL ) ), GC_A( 2,(  9.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  0.5-PVOFSL ),(  0.5-PVOFSL ) ), GC_A( 2,(  0.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900_L[4] =
/*MT6166*/ {  {  GBOUND(( 37.5-PVOFSL ),( 29  -PVOFSL ) ), GC_A( 2,( 37.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 29  -PVOFSL ),( 22.5-PVOFSL ) ), GC_A( 2,( 29  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 10.5-PVOFSL ),(  1.5-PVOFSL ) ), GC_A( 2,( 10.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  1.5-PVOFSL ),(  1.5-PVOFSL ) ), GC_A( 2,(  1.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /*...........................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE_H[] =
/*MT6166*/ {  {                     0,                    0        }, /*#FrequencyBand400  */
/*MT6166*/    { (int)RF_GSM850_MAXGAIN_H, (int)RF_GSM850_MINGAIN_H }, /* FrequencyBand850  */
/*MT6166*/    { (int)RF_GSM_MAXGAIN_H,    (int)RF_GSM_MINGAIN_H    }, /* FrequencyBand900  */
/*MT6166*/    { (int)RF_DCS_MAXGAIN_H,    (int)RF_DCS_MINGAIN_H    }, /* FrequencyBand1800 */
/*MT6166*/    { (int)RF_PCS_MAXGAIN_H,    (int)RF_PCS_MINGAIN_H    }, /* FrequencyBand1900 */
/*MT6166*/ };
/*MT6166*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE_L[] =
/*MT6166*/ {  {                     0,                    0        }, /*#FrequencyBand400  */
/*MT6166*/    { (int)RF_GSM850_MAXGAIN_L, (int)RF_GSM850_MINGAIN_L }, /* FrequencyBand850  */
/*MT6166*/    { (int)RF_GSM_MAXGAIN_L,    (int)RF_GSM_MINGAIN_L    }, /* FrequencyBand900  */
/*MT6166*/    { (int)RF_DCS_MAXGAIN_L,    (int)RF_DCS_MINGAIN_L    }, /* FrequencyBand1800 */
/*MT6166*/    { (int)RF_PCS_MAXGAIN_L,    (int)RF_PCS_MINGAIN_L    }, /* FrequencyBand1900 */
/*MT6166*/ };
/*MT6166*/ const  sL1DGAINRANGE * GAIN_RANGE_TABLE[] =
/*MT6166*/ {  GAIN_RANGE_TABLE_L,
/*MT6166*/    GAIN_RANGE_TABLE_H,
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA* AGC_TABLE_H[] =
/*MT6166*/ {  0,                                              /*#FrequencyBand400  */
/*MT6166*/	  AGC_TABLE_GSM850_H,                             /* FrequencyBand850  */
/*MT6166*/	  AGC_TABLE_GSM900_H,                             /* FrequencyBand900  */
/*MT6166*/	  AGC_TABLE_DCS1800_H,                            /* FrequencyBand1800 */
/*MT6166*/	  AGC_TABLE_PCS1900_H,                            /* FrequencyBand1900 */
/*MT6166*/ };
/*MT6166*/ const  sL1DAGCDATA* AGC_TABLE_L[] =
/*MT6166*/ {  0,                                              /*#FrequencyBand400  */
/*MT6166*/	  AGC_TABLE_GSM850_L,                             /* FrequencyBand850  */
/*MT6166*/	  AGC_TABLE_GSM900_L,                             /* FrequencyBand900  */
/*MT6166*/	  AGC_TABLE_DCS1800_L,                            /* FrequencyBand1800 */
/*MT6166*/	  AGC_TABLE_PCS1900_L,                            /* FrequencyBand1900 */
/*MT6166*/ };
/*MT6166*/ const  sL1DAGCDATA **const  AGC_TABLE[] =
/*MT6166*/ {  AGC_TABLE_L,
/*MT6166*/    AGC_TABLE_H,
/*MT6166*/ };
/*MT6166*/ #else
/*MT6166*/ #define  RF_GSM850_MAXGAIN      (( 56.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM850_MINGAIN      ((  2.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM_MAXGAIN         (( 56.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_GSM_MINGAIN         ((  2.5-PVOFSL )*(PWRRES))
/*MT6166*/ #define  RF_DCS_MAXGAIN         (( 55.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_DCS_MINGAIN         ((  1.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_PCS_MAXGAIN         (( 55.5-PVOFSH )*(PWRRES))
/*MT6166*/ #define  RF_PCS_MINGAIN         ((  1.5-PVOFSH )*(PWRRES))
/*MT6166*/
/*MT6166*/ /* GSM850....................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[4] =
/*MT6166*/ {  {  GBOUND(( 38.5-PVOFSL ),( 30  -PVOFSL ) ), GC_A( 2,( 38.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 30  -PVOFSL ),( 23.5-PVOFSL ) ), GC_A( 2,( 30  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 11.5-PVOFSL ),(  2.5-PVOFSL ) ), GC_A( 2,( 11.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  2.5-PVOFSL ),(  2.5-PVOFSL ) ), GC_A( 2,(  2.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /* GSM900....................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[4] =
/*MT6166*/ {  {  GBOUND(( 38.5-PVOFSL ),( 30  -PVOFSL ) ), GC_A( 2,( 38.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 30  -PVOFSL ),( 23.5-PVOFSL ) ), GC_A( 2,( 30  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 11.5-PVOFSL ),(  2.5-PVOFSL ) ), GC_A( 2,( 11.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  2.5-PVOFSL ),(  2.5-PVOFSL ) ), GC_A( 2,(  2.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /* DCS1800...................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[4] =
/*MT6166*/ {  {  GBOUND(( 37.5-PVOFSL ),( 29  -PVOFSL ) ), GC_A( 2,( 37.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 29  -PVOFSL ),( 22.5-PVOFSL ) ), GC_A( 2,( 29  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 10.5-PVOFSL ),(  1.5-PVOFSL ) ), GC_A( 2,( 10.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  1.5-PVOFSL ),(  1.5-PVOFSL ) ), GC_A( 2,(  1.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /* PCS1900...................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[4] =
/*MT6166*/ {  {  GBOUND(( 37.5-PVOFSL ),( 29  -PVOFSL ) ), GC_A( 2,( 37.5-PVOFSL ) ), BSI_CW(0x83, 0x50188) },
/*MT6166*/    {  GBOUND(( 29  -PVOFSL ),( 22.5-PVOFSL ) ), GC_A( 2,( 29  -PVOFSL ) ), BSI_CW(0x83, 0x50088) },
/*MT6166*/    {  GBOUND(( 10.5-PVOFSL ),(  1.5-PVOFSL ) ), GC_A( 2,( 10.5-PVOFSL ) ), BSI_CW(0x83, 0x50008) },
/*MT6166*/    {  GBOUND((  1.5-PVOFSL ),(  1.5-PVOFSL ) ), GC_A( 2,(  1.5-PVOFSL ) ), BSI_CW(0x83, 0x50028) },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /*...........................................................................*/
/*MT6166*/
/*MT6166*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6166*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6166*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6166*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6166*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6166*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6166*/ {  0,                                              /*#FrequencyBand400  */
/*MT6166*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6166*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6166*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6166*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6166*/ };
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6166*/
/*MT6166*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6166*/ {  int   max_gain, min_gain, real_gain, band_mode, gain_table;
/*MT6166*/    const int*    d32ptr;
/*MT6166*/    const sL1DAGCDATA*  agcptr;
/*MT6166*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6166*/    sLNAGAINOFFSET*     lnaptr;
/*MT6166*/ #endif
/*MT6166*/    sAGCGAINOFFSET*     ofsptr;
/*MT6166*/    long  setting;
/*MT6166*/    int   bit_no, lna_path_loss;
/*MT6166*/    int   thres_IBB, thres_HRD, thres_OBB, dividing_OBB1, dividing_OBB2, LNA_GAIN, LNA_GAIN_M;
/*MT6166*/ #if IS_DUAL_TALK_RX_GAIN_TABLE_CO_BAND_SUPPORT
/*MT6166*/    unsigned char  coband_gaintable_en;
/*MT6166*/    unsigned short coband_en_bitmap;
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/    band_mode      = (rf_band < FrequencyBand1800) ? 0 /* LowBand */ : 1 /* HighBand */;
/*MT6166*/
/*MT6166*/    thres_IBB      = band_mode ?            28 :              36;   //( 37.5-PVOFSL )*PWRRES : ( 38.5-PVOFSL )*PWRRES
/*MT6166*/    thres_HRD      = band_mode ?            76 :              84;   //( 43.5-PVOFSL )*PWRRES : ( 44.5-PVOFSL )*PWRRES
/*MT6166*/    thres_OBB      = band_mode ?           -40 :             -32;   //(   29-PVOFSL )*PWRRES : (   30-PVOFSL )*PWRRES
/*MT6166*/    dividing_OBB1  = band_mode ?           172 :             180;   //( 55.5-PVOFSL )*PWRRES : ( 56.5-PVOFSL )*PWRRES
/*MT6166*/    dividing_OBB2  = band_mode ?            28 :              36;   //( 37.5-PVOFSL )*PWRRES : ( 38.5-PVOFSL )*PWRRES
/*MT6166*/    LNA_GAIN       = band_mode ?   LNA_GAIN_HB :     LNA_GAIN_LB;
/*MT6166*/    LNA_GAIN_M     = band_mode ? LNA_GAIN_HB_M :   LNA_GAIN_LB_M;
/*MT6166*/
/*MT6166*/    /* evaluate the range of available gain */
/*MT6166*/ #if IS_DUAL_TALK_RX_GAIN_TABLE_CO_BAND_SUPPORT
/*MT6166*/    coband_en_bitmap    = L1D_Rx_Gain_Table_CoBand_Enable();
/*MT6166*/    coband_gaintable_en = (coband_en_bitmap & (0x1<<(rf_band-1))) ? 1 : 0;
/*MT6166*/    d32ptr   = (int*)(GAIN_RANGE_TABLE[coband_gaintable_en]+rf_band);
/*MT6166*/ #else
/*MT6166*/    d32ptr   = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6166*/ #endif
/*MT6166*/    max_gain = *d32ptr++;
/*MT6166*/    min_gain = *d32ptr;
/*MT6166*/
/*MT6166*/    /* clipping the request gain to the avialable gain */
/*MT6166*/    if( request_gain>=max_gain )
/*MT6166*/    {  request_gain = max_gain;
/*MT6166*/    }
/*MT6166*/    else if( request_gain<=min_gain )
/*MT6166*/    {  request_gain = min_gain;
/*MT6166*/    }
/*MT6166*/
/*MT6166*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6166*/    /* choose the LNA path loss */
/*MT6166*/    lnaptr = LNA_PATHLOSS_TABLE[rf_band];
/*MT6166*/ #endif
/*MT6166*/    /* get the arfcn section */
/*MT6166*/    ofsptr = AGC_PATHLOSS_TABLE[rf_band];
/*MT6166*/    while( ofsptr->max_arfcn>=0 )
/*MT6166*/    {  if( arfcn <= ofsptr->max_arfcn )
/*MT6166*/       {  break;  }
/*MT6166*/       ofsptr++;
/*MT6166*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6166*/       lnaptr++;
/*MT6166*/ #endif
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    /* evaluate the real gain setting */
/*MT6166*/ #if IS_DUAL_TALK_RX_GAIN_TABLE_CO_BAND_SUPPORT
/*MT6166*/    agcptr = *(AGC_TABLE[coband_gaintable_en]+rf_band);
/*MT6166*/ #else
/*MT6166*/    agcptr = AGC_TABLE[rf_band];
/*MT6166*/ #endif
/*MT6166*/    while( request_gain < agcptr->pos_gain )
/*MT6166*/    {  agcptr++;
/*MT6166*/    }
/*MT6166*/    {
/*MT6166*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6166*/       int idx;
/*MT6166*/       idx = (int)(((agcptr->setting)>>7)&0x7);
/*MT6166*/       if( idx==3 )      /* LNA_High */
/*MT6166*/       {
/*MT6166*/    #if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
/*MT6166*/          if( ( (l1d_rf.blk_flag & LB_OBB_FOUND) && (band_mode == 0) && request_gain>= thres_OBB ) ||
/*MT6166*/              ( (l1d_rf.blk_flag & HB_OBB_FOUND) && (band_mode == 1) && request_gain>= thres_OBB )  )
/*MT6166*/          {   lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_middle-ofsptr->gain_offset));   }
/*MT6166*/          else
/*MT6166*/    #endif
/*MT6166*/          {   lna_path_loss = 0;   }
/*MT6166*/       }
/*MT6166*/       else if( idx==1 ) /* LNA_Middle */
/*MT6166*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_middle-ofsptr->gain_offset));  }
/*MT6166*/       else              /* LNA_Low */
/*MT6166*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_low-ofsptr->gain_offset));     }
/*MT6166*/ #else
/*MT6166*/       lna_path_loss = 0;
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/       bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6166*/       real_gain = -lna_path_loss+REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6166*/
/*MT6166*/       /* Evaluate the real gain setting. */
/*MT6166*/       if( 0 )
/*MT6166*/       { /* do nothing */ }
/*MT6166*/ #if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
/*MT6166*/       else if( ( (l1d_rf.blk_flag & LB_OBB_FOUND) && (band_mode == 0) && request_gain>= thres_OBB ) ||
/*MT6166*/                ( (l1d_rf.blk_flag & HB_OBB_FOUND) && (band_mode == 1) && request_gain>= thres_OBB )  )
/*MT6166*/       {
/*MT6166*/          gain_table = OBB_GAIN_TABLE_FLAG;
/*MT6166*/          if( request_gain >= dividing_OBB1 )
/*MT6166*/          {
/*MT6166*/             agcptr++; // decrease LNA gain
/*MT6166*/                        /* CW131: IF GAIN  | LNA GAIN        |MIXER GAIN */
/*MT6166*/             setting    = (bit_no&0xF)<<10 | agcptr->setting | (0x0<<5);
/*MT6166*/             real_gain -= LNA_GAIN;
/*MT6166*/          }
/*MT6166*/          else if( request_gain >= dividing_OBB2 )
/*MT6166*/          {
/*MT6166*/             agcptr++; // decrease LNA gain
/*MT6166*/                        /* CW131: IF GAIN       | LNA GAIN        |MIXER GAIN */
/*MT6166*/             setting    = ( (bit_no+3)&0xF)<<10 | agcptr->setting | (0x0<<5);
/*MT6166*/             real_gain -= (LNA_GAIN - IF_GAIN_OBB);
/*MT6166*/          }
/*MT6166*/          else
/*MT6166*/          {             /* CW131: IF GAIN  | LNA GAIN        |MIXER GAIN */
/*MT6166*/             setting    = (bit_no&0xF)<<10 | agcptr->setting | (0x0<<5);
/*MT6166*/             real_gain += LNA_GAIN_M;
/*MT6166*/          }
/*MT6166*/       }
/*MT6166*/ #endif
/*MT6166*/ #if IS_INBAND_BLOCKER_DETECTION_SUPPORT
/*MT6166*/       else if( (l1d_rf.blk_flag & IBB_FOUND) && (request_gain>= thres_IBB ) )
/*MT6166*/       {
/*MT6166*/          gain_table = IBB_GAIN_TABLE_FLAG;
/*MT6166*/                     /* CW131: IF GAIN     | LNA GAIN             |MIXER GAIN */
/*MT6166*/          setting    = (bit_no&0xF)<<10 | agcptr->setting | (0x1<<5);
/*MT6166*/          real_gain -= MIXER_GAIN;
/*MT6166*/       }
/*MT6166*/ #endif
/*MT6166*/ #if IS_HEADROOM_DETECTION_SUPPORT
/*MT6166*/       else if( ( l1d_rf.blk_flag & HRD_FOUND ) && (request_gain >= thres_HRD ) )
/*MT6166*/       {
/*MT6166*/          gain_table = ACI_GAIN_TABLE_FLAG;
/*MT6166*/                     /* CW131: IF GAIN       | LNA GAIN        |MIXER GAIN */
/*MT6166*/          setting    = ( (bit_no-2)&0xF)<<10 | agcptr->setting | (0x0<<5);
/*MT6166*/          real_gain -= IF_GAIN;
/*MT6166*/       }
/*MT6166*/ #endif
/*MT6166*/       else
/*MT6166*/       {
/*MT6166*/          gain_table = NORMAL_GAIN_TABLE_FLAG;
/*MT6166*/          setting    = (bit_no&0xF)<<10 | agcptr->setting;
/*MT6166*/       }
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    *gain_setting = ((gain_table&0xFF)<<28) | setting;
/*MT6166*/    return( real_gain );
/*MT6166*/ }
/*MT6166*/
   #if IS_W_CANCELLATION_SUPPORT
/*MT6166*/ unsigned short   L1D_RF_FindGainStep( unsigned long gain_setting, FrequencyBand rf_band  )
/*MT6166*/ {
/*MT6166*/    int lna_gain_setting;
/*MT6166*/    int if_gain_setting;
/*MT6166*/    int band_mode, gain_step, gain_table;
/*MT6166*/    band_mode    = (rf_band < FrequencyBand1800) ? 0 /* LowBand */ : 1 /* HighBand */;
/*MT6166*/
/*MT6166*/    gain_table       = (unsigned int)(gain_setting&0xFF0000000L)>>28;
/*MT6166*/    lna_gain_setting = (gain_setting>>7 ) & 0x7;
/*MT6166*/    if_gain_setting  = (gain_setting>>10) & 0xF; /* bit_no */
/*MT6166*/
/*MT6166*/    if( ( gain_table == IBB_GAIN_TABLE_FLAG ) || ( gain_table == OBB_GAIN_TABLE_FLAG ) )
/*MT6166*/    {
/*MT6166*/       gain_step = 0;
/*MT6166*/    }
/*MT6166*/    else
/*MT6166*/    {
/*MT6166*/       if( lna_gain_setting == 0x3 )
/*MT6166*/       {
/*MT6166*/          if( if_gain_setting== 0x3)
/*MT6166*/             gain_step = 5;
/*MT6166*/          else if( if_gain_setting== 0x6)
/*MT6166*/             gain_step = 6;
/*MT6166*/          else
/*MT6166*/             gain_step = ROUNDINT(if_gain_setting/2.0);
/*MT6166*/       }
/*MT6166*/       else
/*MT6166*/       {
/*MT6166*/          gain_step = 0;
/*MT6166*/       }
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    /* LB step: 0,2,4,6,8 */
/*MT6166*/    /* HB step: 1,3,5,7,9 */
/*MT6166*/    gain_step = gain_step * 2 + band_mode;
/*MT6166*/
/*MT6166*/    return gain_step;
/*MT6166*/ }
/*MT6166*/
   #endif
#endif

#if IS_RF_MT6165
/*MT6165*/
/*MT6165*/ #define  MAX_GAIN_STEP           7
/*MT6165*/ #define  PVOFSL                  34
/*MT6165*/ #define  PVOFSH                  34
/*MT6165*/ #define  NORMAL_GAIN_TABLE_FLAG  0
/*MT6165*/ #define  OBB_GAIN_TABLE_FLAG     1
/*MT6165*/ #define  IBB_GAIN_TABLE_FLAG     2
/*MT6165*/ #define  ACI_GAIN_TABLE_FLAG     3
/*MT6165*/ #define  RF_GSM850_MAXGAIN      ( 176)
/*MT6165*/ #define  RF_GSM850_MINGAIN      (-168)
/*MT6165*/ #define  RF_GSM_MAXGAIN         ( 176)
/*MT6165*/ #define  RF_GSM_MINGAIN         (-168)
/*MT6165*/ #define  RF_DCS_MAXGAIN         ( 176)
/*MT6165*/ #define  RF_DCS_MINGAIN         (-168)
/*MT6165*/ #define  RF_PCS_MAXGAIN         ( 176)
/*MT6165*/ #define  RF_PCS_MINGAIN         (-168)
/*MT6165*/
/*MT6165*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6165*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6165*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6165*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6165*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6165*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6165*/ };
/*MT6165*/ /* { RFLNA gain step, RFIF gain step } */
/*MT6165*/ const  unsigned char  NORMAL_GAIN_TABLE[][2] =
/*MT6165*/ {  { 3, 5 }, /* gain_step = 0 */
/*MT6165*/    { 2, 4 }, /* gain_step = 1 */
/*MT6165*/    { 2, 2 }, /* gain_step = 2 */
/*MT6165*/    { 2, 0 }, /* gain_step = 3 */
/*MT6165*/    { 0, 4 }, /* gain_step = 4 */
/*MT6165*/    { 0, 2 }, /* gain_step = 5 */
/*MT6165*/    { 0, 0 }, /* gain_step = 6 */
/*MT6165*/ };
/*MT6165*/ const  unsigned char  RXLNA_GAIN[2][4] =
/*MT6165*/ {  /*  0    1    2    3    :RFLNA gain_step */
/*MT6165*/    { 0x4, 0x5, 0x6, 0x7 }, /* LowBand    */ /*3bits*/
/*MT6165*/    { 0x2, 0x5, 0x6, 0x7 }, /* HighBand   */ /*3bits*/
/*MT6165*/ };
/*MT6165*/
/*MT6165*/ const  unsigned char  RXIF_GAIN[2][6] =
/*MT6165*/ {  /*  0    1    2    3    4,   5    :RFIF gain_step */
/*MT6165*/    { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6 }, /* LowBand    */ /*3bits*/
/*MT6165*/    { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6 }, /* HighBand   */ /*3bits*/
/*MT6165*/ };
/*MT6165*/
/*MT6165*/ /* GAIN_TABLE: voltage gain (total gain) */
/*MT6165*/ const  signed short  GAIN_TABLE_NORMAL[2][MAX_GAIN_STEP] =
/*MT6165*/ {  /*  0    1   2   3   4   5   6  :gain_step    */
/*MT6165*/    { 176, 128, 80, 32, -72, -120, -168 }, /* LowBand  */
/*MT6165*/    { 176, 132, 84, 36, -72, -120, -168 }, /* HighBand */
/*MT6165*/ };
/*MT6165*/ const  signed short  GAIN_TABLE_OBB[2][MAX_GAIN_STEP] =
/*MT6165*/ {  /*  0    1   2   3   4   5   6  :gain_step    */
/*MT6165*/    { 144, 96, 48,  -0, -72, -120, -168  }, /* LowBand  */
/*MT6165*/    { 124, 72, 24, -24, -72, -120, -168 }, /* HighBand */
/*MT6165*/ };
/*MT6165*/ const  signed short  GAIN_TABLE_IBB[2][MAX_GAIN_STEP] =
/*MT6165*/ {  /*  0    1   2   3   4   5   6  :gain_step    */
/*MT6165*/    { 152, 88, 40,  -8, -72, -120, -168 }, /* LowBand  */
/*MT6165*/    { 156, 92, 44,  -4, -72, -120, -168 }, /* HighBand */
/*MT6165*/ };
/*MT6165*/ const  signed short  GAIN_TABLE_HEADROOM[2][MAX_GAIN_STEP] =
/*MT6165*/ {  /*  0   1   2   3   4   5   6  :gain_step    */
/*MT6165*/    { 128, 80, 32, 32, -72, -120, -168 }, /* LowBand  */
/*MT6165*/    { 128, 84, 36, 36, -72, -120, -168 }, /* HighBand */
/*MT6165*/ };
/*MT6165*/ const  unsigned short  RXIF_BP_EN_NORMAL[2][MAX_GAIN_STEP] =
/*MT6165*/ {  /* 0  1  2  3  4  5  6    :gain_step    */
/*MT6165*/    {  0, 0, 1, 1, 1, 1, 1 }, /* LowBand  */
/*MT6165*/    {  0, 0, 1, 1, 1, 1, 1 }, /* HighBand */
/*MT6165*/ };
/*MT6165*/ const  signed short  RXIF_BP_EN_HEADROOM[2][MAX_GAIN_STEP] =
/*MT6165*/ {  /* 0  1  2  3  4  5  6    :gain_step    */
/*MT6165*/    {  1, 1, 1, 1, 1, 1, 1 }, /* LowBand  */
/*MT6165*/    {  1, 1, 1, 1, 1, 1, 1 }, /* HighBand */
/*MT6165*/ };
/*MT6165*/
/*MT6165*/
/*MT6165*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6165*/
/*MT6165*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6165*/ {  int   max_gain, min_gain, real_gain, band_mode, gain_table;
/*MT6165*/    const int*    d32ptr;
/*MT6165*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6165*/    sLNAGAINOFFSET*     lnaptr;
/*MT6165*/ #endif
/*MT6165*/    sAGCGAINOFFSET*     ofsptr;
/*MT6165*/    long  setting;
/*MT6165*/    int   rx_gain_step, rx_lna_setting, rx_if_setting, lna_path_loss;
/*MT6165*/    int   thres_OBB, thres_IBB, thres_HRD;
/*MT6165*/
/*MT6165*/    band_mode      = (rf_band < FrequencyBand1800) ? 0 /* LowBand */ : 1 /* HighBand */;
/*MT6165*/
/*MT6165*/    thres_OBB      = band_mode ?            32 :              36;   //( 38-PVOFSL )*PWRRES : ( 38.5-PVOFSH )*PWRRES
/*MT6165*/    thres_IBB      = band_mode ?            32 :              36;   //( 38-PVOFSL )*PWRRES : ( 38.5-PVOFSH )*PWRRES
/*MT6165*/    thres_HRD      = band_mode ?            80 :              84;   //( 44-PVOFSL )*PWRRES : ( 44.5-PVOFSH )*PWRRES
/*MT6165*/
/*MT6165*/    /* evaluate the range of available gain */
/*MT6165*/    d32ptr   = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6165*/    max_gain = *d32ptr++;
/*MT6165*/    min_gain = *d32ptr;
/*MT6165*/
/*MT6165*/    /* clipping the request gain to the avialable gain */
/*MT6165*/    if( request_gain>=max_gain )
/*MT6165*/    {  request_gain = max_gain;
/*MT6165*/    }
/*MT6165*/    else if( request_gain<=min_gain )
/*MT6165*/    {  request_gain = min_gain;
/*MT6165*/    }
/*MT6165*/
/*MT6165*/    for ( rx_gain_step = 0; rx_gain_step < MAX_GAIN_STEP; rx_gain_step++ )
/*MT6165*/    {
/*MT6165*/       if( request_gain >= GAIN_TABLE_NORMAL[band_mode][rx_gain_step] )
/*MT6165*/       {  break;  }
/*MT6165*/    }
/*MT6165*/    if( rx_gain_step >= MAX_GAIN_STEP )
/*MT6165*/    {  rx_gain_step = (MAX_GAIN_STEP-1);
/*MT6165*/    }
/*MT6165*/
/*MT6165*/    rx_lna_setting = RXLNA_GAIN[band_mode][(NORMAL_GAIN_TABLE[rx_gain_step][0])];
/*MT6165*/    rx_if_setting  = RXIF_GAIN[band_mode][(NORMAL_GAIN_TABLE[rx_gain_step][1])];
/*MT6165*/
/*MT6165*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6165*/       /* choose the LNA path loss */
/*MT6165*/       lnaptr = LNA_PATHLOSS_TABLE[rf_band];
/*MT6165*/ #endif
/*MT6165*/       /* get the arfcn section */
/*MT6165*/       ofsptr = AGC_PATHLOSS_TABLE[rf_band];
/*MT6165*/       while( ofsptr->max_arfcn>=0 )
/*MT6165*/       {  if( arfcn <= ofsptr->max_arfcn )
/*MT6165*/          {  break;  }
/*MT6165*/          ofsptr++;
/*MT6165*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6165*/          lnaptr++;
/*MT6165*/ #endif
/*MT6165*/       }
/*MT6165*/
/*MT6165*/       /* Evaluate the real gain setting. */
/*MT6165*/    {
/*MT6165*/ #if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
/*MT6165*/       if( rx_lna_setting==0x7 )      /* LNA_High */
/*MT6165*/       {
/*MT6165*/    #if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
/*MT6165*/          if( ( (l1d_rf.blk_flag & LB_OBB_FOUND) && (band_mode == 0) && request_gain>= thres_OBB ) ||
/*MT6165*/              ( (l1d_rf.blk_flag & HB_OBB_FOUND) && (band_mode == 1) && request_gain>= thres_OBB )  )
/*MT6165*/          {   lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_low-ofsptr->gain_offset));   }
/*MT6165*/          else
/*MT6165*/    #endif
/*MT6165*/          {   lna_path_loss = 0;   }
/*MT6165*/       }
/*MT6165*/       else if( rx_lna_setting==0x6 ) /* LNA_Middle */
/*MT6165*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_middle-ofsptr->gain_offset));  }
/*MT6165*/       else              /* LNA_Low */
/*MT6165*/       {  lna_path_loss = (l1d_rf2.is_fhc) ? (0) : ((int)(lnaptr->gain_offset_low-ofsptr->gain_offset));     }
/*MT6165*/ #else
/*MT6165*/       lna_path_loss = 0;
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/       real_gain = -lna_path_loss;
/*MT6165*/       if( 0 )
/*MT6165*/       { /* do nothing */ }
/*MT6165*/ #if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
/*MT6165*/       else if( ( (l1d_rf.blk_flag & LB_OBB_FOUND) && (band_mode == 0) && request_gain>= thres_OBB ) ||
/*MT6165*/                ( (l1d_rf.blk_flag & HB_OBB_FOUND) && (band_mode == 1) && request_gain>= thres_OBB )  )
/*MT6165*/       {  /* CW66: LNA Gain | IF GAIN | RXIF_BP_EN */
/*MT6165*/          setting = ((rx_lna_setting-1)<<17) | (rx_if_setting<<13) | (RXIF_BP_EN_NORMAL[band_mode][rx_gain_step]<<10);  // OBB: decrease RX_LNA_Gain by 1 step
/*MT6165*/          gain_table = OBB_GAIN_TABLE_FLAG;
/*MT6165*/          real_gain += GAIN_TABLE_OBB[band_mode][rx_gain_step];
/*MT6165*/       }
/*MT6165*/ #endif
/*MT6165*/ #if IS_INBAND_BLOCKER_DETECTION_SUPPORT
/*MT6165*/       else if( (l1d_rf.blk_flag & IBB_FOUND) && (request_gain>= thres_IBB ) )
/*MT6165*/       {  /* CW66: LNA Gain | IF GAIN | RXIF_BP_EN */
/*MT6165*/          setting    = ((rx_lna_setting-1)<<17) | (rx_if_setting<<13) | (RXIF_BP_EN_NORMAL[band_mode][rx_gain_step]<<10);  // IBB: decrease RX_LNA_Gain by 1 step
/*MT6165*/          gain_table = IBB_GAIN_TABLE_FLAG;
/*MT6165*/          real_gain += GAIN_TABLE_IBB[band_mode][rx_gain_step];
/*MT6165*/       }
/*MT6165*/ #endif
/*MT6165*/ #if IS_HEADROOM_DETECTION_SUPPORT
/*MT6165*/       else if( ( l1d_rf.blk_flag & HRD_FOUND ) && (request_gain >= thres_HRD ) )
/*MT6165*/       {  /* CW66: LNA Gain | IF GAIN | RXIF_BP_EN */
/*MT6165*/          setting    = (rx_lna_setting<<17) | ((rx_if_setting-2)<<13) | (RXIF_BP_EN_HEADROOM[band_mode][rx_gain_step]<<10);  // HRD: decrease RX_IF_Gain by 2 step
/*MT6165*/          gain_table = ACI_GAIN_TABLE_FLAG;
/*MT6165*/          real_gain += GAIN_TABLE_HEADROOM[band_mode][rx_gain_step];
/*MT6165*/       }
/*MT6165*/ #endif
/*MT6165*/       else
/*MT6165*/       {  /* CW66: LNA Gain | IF GAIN | RXIF_BP_EN */
/*MT6165*/          setting    = (rx_lna_setting<<17) | (rx_if_setting<<13) | (RXIF_BP_EN_NORMAL[band_mode][rx_gain_step]<<10);
/*MT6165*/          gain_table = NORMAL_GAIN_TABLE_FLAG;
/*MT6165*/          real_gain += GAIN_TABLE_NORMAL[band_mode][rx_gain_step];
/*MT6165*/       }
/*MT6165*/    }
/*MT6165*/
/*MT6165*/    (void) thres_OBB;
/*MT6165*/
/*MT6165*/    *gain_setting = ((gain_table&0xFF)<<28) | BSI_CW(0x42, setting);  //CW66: RX Gain
/*MT6165*/    return( real_gain );
/*MT6165*/ }
/*MT6165*/
   #if IS_W_CANCELLATION_SUPPORT
/*MT6165*/ unsigned short   L1D_RF_FindGainStep( unsigned long gain_setting, FrequencyBand rf_band )
/*MT6165*/ {
/*MT6165*/    int band_mode, gain_step, gain_table, rx_lna_setting, rx_if_setting;
/*MT6165*/    
/*MT6165*/    gain_table     = (unsigned int)(gain_setting&0xFF0000000L)>>28;
/*MT6165*/    rx_lna_setting = (gain_setting&0xE0000)>>17;
/*MT6165*/    rx_if_setting  = (gain_setting&0x0E000)>>13;
/*MT6165*/    band_mode      = (rf_band < FrequencyBand1800) ? 0 /* LowBand */ : 1 /* HighBand */;
/*MT6165*/ 
/*MT6165*/    if( gain_table == NORMAL_GAIN_TABLE_FLAG )
/*MT6165*/    {  
/*MT6165*/       /* Normal condition: gain_step: 0,1,2,3,4 */
/*MT6165*/       for(gain_step = 0; gain_step <= 3; gain_step++ )
/*MT6165*/       {  if( ( rx_lna_setting == RXLNA_GAIN[band_mode][ NORMAL_GAIN_TABLE[gain_step][0] ] ) &&
/*MT6165*/              ( rx_if_setting  == RXIF_GAIN [band_mode][ NORMAL_GAIN_TABLE[gain_step][1] ] ) )
/*MT6165*/          {  break;  }
/*MT6165*/       }
/*MT6165*/       
/*MT6165*/       if( gain_step > 3 )  gain_step = 4;
/*MT6165*/    }
/*MT6165*/    #if IS_HEADROOM_DETECTION_SUPPORT
/*MT6165*/    else if( gain_table == ACI_GAIN_TABLE_FLAG )
/*MT6165*/    {  
/*MT6165*/       /* Headroom condition: gain_step: 2,3,4,5 */
/*MT6165*/       if( ( rx_lna_setting == RXLNA_GAIN[band_mode][ NORMAL_GAIN_TABLE[0][0] ] ) &&
/*MT6165*/           ( rx_if_setting  == RXIF_GAIN [band_mode][ NORMAL_GAIN_TABLE[0][1] ]-2 ) )
/*MT6165*/       {  gain_step=5;  }
/*MT6165*/       else
/*MT6165*/       {
/*MT6165*/          for(gain_step = 2; gain_step <= 3; gain_step++ )
/*MT6165*/          {  if( ( rx_lna_setting == RXLNA_GAIN[band_mode][ NORMAL_GAIN_TABLE[gain_step][0] ] ) &&
/*MT6165*/                 ( rx_if_setting  == RXIF_GAIN [band_mode][ NORMAL_GAIN_TABLE[gain_step][1] ] ) )
/*MT6165*/             {  break;  }
/*MT6165*/          }
/*MT6165*/          if( gain_step > 3 )  gain_step = 4;           
/*MT6165*/       }
/*MT6165*/    }
/*MT6165*/    #endif
/*MT6165*/    else /* Others: gain_step: 4 */
/*MT6165*/    {  gain_step = 4;  }
/*MT6165*/    
/*MT6165*/    /* LB step: 0,2,4,6,8,10 */
/*MT6165*/    /* HB step: 1,3,5,7,9,11 */
/*MT6165*/    gain_step = gain_step * 2 + band_mode;
/*MT6165*/    
/*MT6165*/    return gain_step;
/*MT6165*/ }
/*MT6165*/
   #endif
#endif
