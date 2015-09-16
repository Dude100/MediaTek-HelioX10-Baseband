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
 *   m12191.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Setup Synthesizer
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.30  $
 * $Modtime:   Jul 29 2005 13:44:06  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1/l1d/m12191.c-arc  $
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
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
 * [L1D][Modify]Check in AD6546 RF Driver #if IS_RF_AD6546
 *
 * removed!
 * removed!
 * Remove compile warning of may be used before being set
 *
 * removed!
 * removed!
 * local variable f_vco is not used
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
 *    Rev 1.30   Jul 29 2005 14:01:24   mtk00773
 * [L1D][Enhence] Support RF SKY74117
 * Resolution for 12111: [L1D][Enhence] Support RF SKY74117
 * 
 *    Rev 1.29   Jul 08 2005 16:53:04   mtk00939
 * [L1D][Modify]L1D add code for MT6139C and META related code
 * 
 *    Rev 1.28   May 17 2005 00:34:36   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 * 
 *    Rev 1.27   Jan 18 2005 00:38:08   BM
 * append new line in W05.04
 * 
 *    Rev 1.26   Jul 30 2004 17:37:06   mtk00240
 * L1D add code to support AERO1Plus RF chip
 * Resolution for 6925: [L1D][Enhance] L1D add code to support AERO1Plus RF chip
 *
 *    Rev 1.25   Jul 05 2004 15:49:42   mtk00773
 * Add RF POLARIS1 setting
 *
 *    Rev 1.24   May 21 2004 19:01:58   mtk00240
 * Add code to support MT6129D
 * Resolution for 5565: [L1D][Add Feature] Add code to support MT6129D
 *
 *    Rev 1.23   Jan 27 2004 15:33:12   mtk00585
 * [L1D][Add] L1D Add code for MT6129C RF Driver.
 *
 *    Rev 1.22   Oct 23 2003 14:22:18   mtk00585
 * [L1D][Add] L1D Add code for MT6129B RF Driver.
 * Resolution for 3177: [L1D][Add] L1D Add code for MT6129B RF Driver.
 *
 *    Rev 1.21   Jul 11 2003 17:41:30   mtk00489
 * [L1D][Enhanced]L1D supports MT6129A
 * Resolution for 2241: [L1D][Enhanced]L1D supports MT6129A
 *
 *    Rev 1.20   May 16 2003 13:09:24   mtk00489
 * [L1D][New Feature]L1D supports MT6119C
 * Resolution for 1794: [L1D][New Feature]L1D supports MT6119C
 *
 *    Rev 1.19   Mar 07 2003 18:47:32   mtk00474
 * modify the coding error for decision tx arfcn value of MT6119
 * Resolution for 1182: modify the coding error for decision tx arfcn value of MT6119
 *
 *    Rev 1.18   14 Feb 2003 11:42:54   mtk00240
 * L1D modify the synthesizer setting of Bright4 to support PCS band
 * Resolution for 652: L1D modify the synthesizer setting of Bright4 to support PCS band
 *
 *    Rev 1.17   Nov 11 2002 18:04:58   mtk00474
 * Update MT6119 and AERO RF parameters
 * Resolution for 557: Update MT6119 and AERO RF parameters
 *
 *    Rev 1.16   01 Nov 2002 11:11:24   mtk00240
 * L1D modify TX PLL evaulation for new MT6119 chip
 * Resolution for 547: L1D modify TX PLL evaulation for new MT6119 chip
 *
 *    Rev 1.15   22 Oct 2002 08:18:00   mtk00240
 * L1D modified some control data of mt6119
 * Resolution for 439: L1D add code to support MT6119 RF Module
 *
 *    Rev 1.14   01 Oct 2002 09:41:12   mtk00240
 * L1D modified GSM RX frequency evaluation of MT6119
 * Resolution for 515: L1D modified GSM RX frequency evaluation of MT6119
 *
 *    Rev 1.13   01 Sep 2002 15:35:30   mtk00240
 * L1D fix the bug that  max ARFCN of GSM is 1023 not 1024
 * Resolution for 473: L1D fix the bug that  max ARFCN of GSM is 1023 not 1024
 *
 *    Rev 1.12   27 Aug 2002 12:04:22   admin
 * change file header
 *
 *    Rev 1.11   26 Aug 2002 14:34:14   admin
 * remove modification notice
 * add copyright statement.
 *
 *    Rev 1.10   24 Aug 2002 14:10:46   mtk00240
 *  L1D add code to support AERO RF Module
 * Resolution for 464:  L1D add code to support AERO RF Module
 *
 *    Rev 1.9   23 Jul 2002 15:49:12   mtk00240
 * L1D add code to support MT6119 RF Module
 * Resolution for 439: L1D add code to support MT6119 RF Module
 *
 *    Rev 1.8   03 Jul 2002 21:43:48   mtk00240
 * L1D extrract RF setting code to let customer setup new RF module more easily
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.7   01 May 2002 22:45:58   mtk00240
 * Extract GSM code from L1D
 * Resolution for 384: Extract GSM code from L1D
 *
 *    Rev 1.6   30 Mar 2002 13:04:16   mtk00240
 * 1) Modify L1D code to support both Bright2 & Bright4 RF board
 * 2) L1D add Audio interface to support Voice Memo & Melody
 * 3) Add L1D code to support RAM-based chip
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 * Resolution for 342: L1D add Audio interface to support Voice Memo & Melody
 * Resolution for 343: Add L1D code to support RAM-based chip
 *
 *    Rev 1.5   03 Mar 2002 23:07:10   mtk00240
 * L1D modified Tx synthesizer setting of DCS band
 * Resolution for 306: L1D modified Tx synthesizer setting of DCS band
 *
 *    Rev 1.4   17 Feb 2002 20:15:42   mtk00240
 * Update L1D code for solving HandOver test item
 * Resolution for 275: Update L1D code for solving HandOver test item
 *
 *    Rev 1.3   03 Jan 2002 12:19:50   mtk00240
 * Merge B.L1.20011225 to Main V1.XX
 *
 *    Rev 1.2.1.0   Dec 25 2001 14:32:56   mtk00210
 * Update for High resolution RSSI, multiband AFC,
 * update L1C/L1D interface for CSD
 *
 *    Rev 1.1   Dec 10 2001 16:43:56   mtk00240
 * Add copyright header of MediaTek
 *
 *******************************************************************************/


/*===============================================================================*/
/*                                                                               */
/* void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )  */
/* void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )  */
/*                                                                               */
/*===============================================================================*/
/*                                                                               */
/* arfcn  : the request ARFCN number.                                            */
/* *rfN   : returned RF N counter setting                                        */
/* *ifN   : returned IF N counter setting                                        */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/* This program evaluates the PLL setting value by the request arfcn for Si4133. */
/* If the PLL component is changed, this file shall be modified by vendor        */
/*                                                                               */
/* ----------------------------------------------------------------------------- */

#include "l1d_cid.h"
#include "m12190.h"

/*================================================================================================*/

#if IS_RF_BRIGHT2
/*BRIGHT2*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*BRIGHT2*/ {  long setting = 0;
/*BRIGHT2*/
/*BRIGHT2*/    switch(rf_band)
/*BRIGHT2*/    {
/*BRIGHT2*/       case  FrequencyBand900 :
/*BRIGHT2*/       {
/*BRIGHT2*/          if( arfcn<=124 )                    /* GSM( 0~  124), */
/*BRIGHT2*/             setting = (5800L<<4)|4;
/*BRIGHT2*/          else                                /* GSM(975~1023), */
/*BRIGHT2*/             setting = (4776L<<4)|4;
/*BRIGHT2*/          break;
/*BRIGHT2*/       }
/*BRIGHT2*/       case  FrequencyBand1800 :
/*BRIGHT2*/       {
/*BRIGHT2*/          setting = (7389L<<4)|3;             /* DCS(512~ 885), */
/*BRIGHT2*/          break;
/*BRIGHT2*/       }
/*BRIGHT2*/       default :
/*BRIGHT2*/       {
/*BRIGHT2*/          break;
/*BRIGHT2*/       }
/*BRIGHT2*/    }
/*BRIGHT2*/    *rfN = setting + (arfcn<<4);
/*BRIGHT2*/    *ifN = (2700L<<4) | 5;
/*BRIGHT2*/ }
/*BRIGHT2*/ /* =========================================================================== */
/*BRIGHT2*/
/*BRIGHT2*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*BRIGHT2*/ {  long setting = 0;
/*BRIGHT2*/
/*BRIGHT2*/    switch(rf_band)
/*BRIGHT2*/    {
/*BRIGHT2*/       case  FrequencyBand900 :
/*BRIGHT2*/       {
/*BRIGHT2*/          if( arfcn<=124 )                    /* GSM( 0~  124), */
/*BRIGHT2*/          {  setting = (5800L<<4)|4;  }
/*BRIGHT2*/          else                                /* GSM(975~1023), */
/*BRIGHT2*/          {  setting = (4776L<<4)|4;  }
/*BRIGHT2*/          *ifN = (2700L<<4)|5;                /* 54M/200K */
/*BRIGHT2*/          break;
/*BRIGHT2*/       }
/*BRIGHT2*/       case  FrequencyBand1800 :
/*BRIGHT2*/       {
/*BRIGHT2*/          setting = (7389L<<4)|3;             /* DCS(512~ 885), */
/*BRIGHT2*/          *ifN    = (2600L<<4)|5;             /* 52M/200K */
/*BRIGHT2*/          break;
/*BRIGHT2*/       }
/*BRIGHT2*/       default :
/*BRIGHT2*/       {  break;
/*BRIGHT2*/       }
/*BRIGHT2*/    }
/*BRIGHT2*/    *rfN = setting + (arfcn<<4);
/*BRIGHT2*/ }
/*BRIGHT2*/ /* =========================================================================== */
#endif

#if IS_RF_BRIGHT4
/*BRIGHT4*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*BRIGHT4*/ {
/*BRIGHT4*/    switch(rf_band)
/*BRIGHT4*/    {
/*BRIGHT4*/       case  FrequencyBand900 :
/*BRIGHT4*/       {
/*BRIGHT4*/          if(arfcn<=50)
/*BRIGHT4*/          {  *rfN = 0x0490C9 + (arfcn<<6);  }  /*  ARFCN :   1~  50 */
/*BRIGHT4*/          else if(arfcn<=124)
/*BRIGHT4*/          {  *rfN = 0x4490C9 + (arfcn<<6);  }  /*  ARFCN :  51~ 124 */
/*BRIGHT4*/          else
/*BRIGHT4*/          {  *rfN = 0x0390C9 + (arfcn<<6);  }  /*  ARFCN : 975~1023 */
/*BRIGHT4*/          break;
/*BRIGHT4*/       }
/*BRIGHT4*/       case  FrequencyBand1800 :
/*BRIGHT4*/       {
/*BRIGHT4*/          *rfN = 0x042851 + (arfcn<<5);        /*  ARFCN : 512~ 885 */
/*BRIGHT4*/          break;
/*BRIGHT4*/       }
/*BRIGHT4*/       case  FrequencyBand1900 :
/*BRIGHT4*/       {
/*BRIGHT4*/          *rfN = 0x447679 + (arfcn<<5);        /*  ARFCN : 512~ 810 */
/*BRIGHT4*/          break;
/*BRIGHT4*/       }
/*BRIGHT4*/       default :
/*BRIGHT4*/       {
/*BRIGHT4*/          break;
/*BRIGHT4*/       }
/*BRIGHT4*/    }
/*BRIGHT4*/    *ifN = 0;
/*BRIGHT4*/ }
/*BRIGHT4*/ /* =========================================================================== */
/*BRIGHT4*/
/*BRIGHT4*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*BRIGHT4*/ {
/*BRIGHT4*/    switch(rf_band)
/*BRIGHT4*/    {
/*BRIGHT4*/       case  FrequencyBand900 :
/*BRIGHT4*/       {
/*BRIGHT4*/          if(arfcn<=10)
/*BRIGHT4*/          {  *rfN = 0xD4BF09 + (arfcn<<6);  }  /*  ARFCN :   1~  10 */
/*BRIGHT4*/          else if(arfcn<=124)
/*BRIGHT4*/          {  *rfN = 0xC4BC89 + (arfcn<<6);  }  /*  ARFCN :  11~ 124 */
/*BRIGHT4*/          else
/*BRIGHT4*/          {  *rfN = 0xD3BF09 + (arfcn<<6);  }  /*  ARFCN : 975~1023 */
/*BRIGHT4*/          break;
/*BRIGHT4*/       }
/*BRIGHT4*/       case  FrequencyBand1800 :
/*BRIGHT4*/       {
/*BRIGHT4*/          if(arfcn<=672)
/*BRIGHT4*/          {  *rfN = 0x841EF1 + (arfcn<<5);  }  /*  ARFCN : 512~ 672 */
/*BRIGHT4*/          else
/*BRIGHT4*/          {  *rfN = 0x942031 + (arfcn<<5);  }  /*  ARFCN : 673~ 885 */
/*BRIGHT4*/          break;
/*BRIGHT4*/       }
/*BRIGHT4*/       case  FrequencyBand1900 :
/*BRIGHT4*/       {
/*BRIGHT4*/          *rfN = 0xC47679 + (arfcn<<5);        /*  ARFCN : 512~ 810 */
/*BRIGHT4*/          break;
/*BRIGHT4*/       }
/*BRIGHT4*/       default :
/*BRIGHT4*/       {  break;
/*BRIGHT4*/       }
/*BRIGHT4*/    }
/*BRIGHT4*/    *ifN = 0;
/*BRIGHT4*/ }
/*BRIGHT4*/ /* =========================================================================== */
#endif

#if IS_RF_BRIGHT5P
/*BRIGHT5P*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*BRIGHT5P*/ {
/*BRIGHT5P*/    switch(rf_band)
/*BRIGHT5P*/    {
/*BRIGHT5P*/       case  FrequencyBand850 :
/*BRIGHT5P*/       {
/*BRIGHT5P*/          if(arfcn<=133)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-128) + 52)<<5) | (135<<11) | (0x080001) ); }  /*  ARFCN :   128~  133 */
/*BRIGHT5P*/          else if(arfcn<=165)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-134))<<5) | (136<<11) | (0x080001) ); }  /*  ARFCN :  134~ 165 */
/*BRIGHT5P*/          else if(arfcn<=197)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-166))<<5) | (137<<11) | (0x080001) ); }  /*  ARFCN :  166~ 197 */
/*BRIGHT5P*/          else if(arfcn<=229)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-198))<<5) | (138<<11) | (0x080001) ); }  /*  ARFCN :  198~ 229 */
/*BRIGHT5P*/          else
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-230))<<5) | (139<<11) | (0x080001) ); }  /*  ARFCN :  230~ 251 */
/*BRIGHT5P*/          break;
/*BRIGHT5P*/       }
/*BRIGHT5P*/       case  FrequencyBand900 :
/*BRIGHT5P*/       {
/*BRIGHT5P*/          if(arfcn<=28)
/*BRIGHT5P*/          {  *rfN = ( ((2*arfcn + 6)<<5) | (146<<11) | (0x080009) ); }  /*  ARFCN :   0~  28 */
/*BRIGHT5P*/          else if(arfcn<=60)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-29))<<5) | (147<<11) | (0x080009) ); }  /*  ARFCN :  29~ 60 */
/*BRIGHT5P*/          else if(arfcn<=92)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-61))<<5) | (148<<11) | (0x080009) ); }  /*  ARFCN :  61~ 92 */
/*BRIGHT5P*/          else if(arfcn<=124)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-93))<<5) | (149<<11) | (0x080009) ); }  /*  ARFCN :  93~ 124 */
/*BRIGHT5P*/          else if(arfcn<=988)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-975)+36)<<5) | (144<<11) | (0x080009) );  }  /*  ARFCN :  975~ 988 */
/*BRIGHT5P*/          else if(arfcn<=1020)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-989))<<5) | (145<<11) | (0x080009) ); }  /*  ARFCN :  989~ 1020 */
/*BRIGHT5P*/          else
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-1021))<<5) | (146<<11) | (0x080009) ); }  /*  ARFCN :  1021~ 1023 */
/*BRIGHT5P*/          break;
/*BRIGHT5P*/       }
/*BRIGHT5P*/       case  FrequencyBand1800 :
/*BRIGHT5P*/       {
/*BRIGHT5P*/          if(arfcn<=573)
/*BRIGHT5P*/          {  *rfN = ( (((arfcn-512) + 2)<<5) | (141<<11) | (0x080011) ); }  /*  ARFCN :   512~  573 */
/*BRIGHT5P*/          else if(arfcn<=637)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-574)<<5) | (142<<11) | (0x080011) ); }  /*  ARFCN :  574~ 637 */
/*BRIGHT5P*/          else if(arfcn<=701)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-638)<<5) | (143<<11) | (0x080011) ); }  /*  ARFCN :  638~ 701 */
/*BRIGHT5P*/          else if(arfcn<=765)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-702)<<5) | (144<<11) | (0x080011) ); }  /*  ARFCN :  702~ 765 */
/*BRIGHT5P*/          else if(arfcn<=829)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-766)<<5) | (145<<11) | (0x080011) ); }  /*  ARFCN :  766~ 829 */
/*BRIGHT5P*/          else
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-830)<<5) | (146<<11) | (0x080011) ); }  /*  ARFCN :  830~ 885 */
/*BRIGHT5P*/          break;
/*BRIGHT5P*/       }
/*BRIGHT5P*/       case  FrequencyBand1900 :
/*BRIGHT5P*/       {
/*BRIGHT5P*/          if(arfcn<=524)
/*BRIGHT5P*/          {  *rfN = ( (((arfcn-512) + 51)<<5) | (150<<11) | (0x080019) ); }  /*  ARFCN :   512~  524 */
/*BRIGHT5P*/          else if(arfcn<=588)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-525)<<5) | (151<<11) | (0x080019) ); }  /*  ARFCN :  525~ 588 */
/*BRIGHT5P*/          else if(arfcn<=652)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-589)<<5) | (152<<11) | (0x080019) ); }  /*  ARFCN :  589~ 652 */
/*BRIGHT5P*/          else if(arfcn<=716)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-653)<<5) | (153<<11) | (0x080019) ); }  /*  ARFCN :  653~ 716 */
/*BRIGHT5P*/          else if(arfcn<=780)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-717)<<5) | (154<<11) | (0x080019) ); }  /*  ARFCN :  717~ 780 */
/*BRIGHT5P*/          else
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-781)<<5) | (155<<11) | (0x080019) ); }  /*  ARFCN :  781~ 810 */
/*BRIGHT5P*/          break;
/*BRIGHT5P*/       }
/*BRIGHT5P*/       default :
/*BRIGHT5P*/       {
/*BRIGHT5P*/          break;
/*BRIGHT5P*/       }
/*BRIGHT5P*/    }
/*BRIGHT5P*/    *ifN = 0;
/*BRIGHT5P*/ }
/*BRIGHT5P*/ /* =========================================================================== */
/*BRIGHT5P*/
/*BRIGHT5P*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*BRIGHT5P*/ {
/*BRIGHT5P*/    switch(rf_band)
/*BRIGHT5P*/    {
/*BRIGHT5P*/       case  FrequencyBand850 :
/*BRIGHT5P*/       {
/*BRIGHT5P*/          if(arfcn<=150)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-128) + 18)<<5) | (141<<11) | (0x000001) ); }  /*  ARFCN :   128~  150 */
/*BRIGHT5P*/          else if(arfcn<=182)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-151))<<5) | (142<<11) | (0x000001) ); }  /*  ARFCN :  151~ 182 */
/*BRIGHT5P*/          else if(arfcn<=214)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-183))<<5) | (143<<11) | (0x000001) ); }  /*  ARFCN :  183~ 214 */
/*BRIGHT5P*/          else if(arfcn<=246)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-215))<<5) | (144<<11) | (0x000001) ); }  /*  ARFCN :  215~ 246 */
/*BRIGHT5P*/          else
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-247))<<5) | (145<<11) | (0x000001) ); }  /*  ARFCN :  247~ 251 */
/*BRIGHT5P*/          break;
/*BRIGHT5P*/       }
/*BRIGHT5P*/       case  FrequencyBand900 :
/*BRIGHT5P*/       {
/*BRIGHT5P*/          if(arfcn<=3)
/*BRIGHT5P*/          {  *rfN = ( ((2*arfcn+56)<<5) | (151<<11) | (0x200009) ); }  /*  ARFCN :   0~  3 */
/*BRIGHT5P*/          else if(arfcn<=9)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-4))<<5) | (152<<11) | (0x200009) ); }  /*  ARFCN :  4~ 9 */
/*BRIGHT5P*/          else if(arfcn<=13)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-10)+56)<<5) | (151<<11) | (0x000009) ); }  /*  ARFCN :  10~ 13 */
/*BRIGHT5P*/          else if(arfcn<=45)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-14))<<5) | (152<<11) | (0x000009) ); }  /*  ARFCN :  14~ 45 */
/*BRIGHT5P*/          else if(arfcn<=77)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-46))<<5) | (153<<11) | (0x000009) ); }  /*  ARFCN :  46~ 77 */
/*BRIGHT5P*/          else if(arfcn<=109)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-78))<<5) | (154<<11) | (0x000009) ); }  /*  ARFCN :  78~ 109 */
/*BRIGHT5P*/          else if(arfcn<=124)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-110))<<5) | (155<<11) | (0x000009) ); }  /*  ARFCN :  110~ 124 */
/*BRIGHT5P*/          else if(arfcn<=995)
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-975)+22)<<5) | (150<<11) | (0x200009) ); }  /*  ARFCN : 975~ 995 */
/*BRIGHT5P*/          else
/*BRIGHT5P*/          {  *rfN = ( ((2*(arfcn-996))<<5) | (151<<11) | (0x200009) ); }  /*  ARFCN : 996~1023 */
/*BRIGHT5P*/          break;
/*BRIGHT5P*/       }
/*BRIGHT5P*/       case  FrequencyBand1800 :
/*BRIGHT5P*/       {
/*BRIGHT5P*/          if(arfcn<=520)
/*BRIGHT5P*/          {  *rfN = ( (((arfcn-512) + 55)<<5) | (139<<11) | (0x000011) ); }  /*  ARFCN :   512~  520 */
/*BRIGHT5P*/          else if(arfcn<=584)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-521)<<5) | (140<<11) | (0x000011) ); }  /*  ARFCN :  521~ 584 */
/*BRIGHT5P*/          else if(arfcn<=648)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-585)<<5) | (141<<11) | (0x000011) ); }  /*  ARFCN :  585~ 648 */
/*BRIGHT5P*/          else if(arfcn<=670)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-649)<<5) | (142<<11) | (0x000011) ); }  /*  ARFCN :  649~ 670 */
/*BRIGHT5P*/          else if(arfcn<=702)
/*BRIGHT5P*/          {  *rfN = ( (((arfcn-671)+32)<<5) | (142<<11) | (0x200011) ); }  /*  ARFCN :  671~ 702 */
/*BRIGHT5P*/          else if(arfcn<=766)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-703)<<5) | (143<<11) | (0x200011) ); }  /*  ARFCN :  703~ 766 */
/*BRIGHT5P*/          else if(arfcn<=830)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-767)<<5) | (144<<11) | (0x200011) ); }  /*  ARFCN :  767~ 830 */
/*BRIGHT5P*/          else
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-831)<<5) | (145<<11) | (0x200011) ); }  /*  ARFCN : 831~ 885 */
/*BRIGHT5P*/          break;
/*BRIGHT5P*/       }
/*BRIGHT5P*/       case  FrequencyBand1900 :
/*BRIGHT5P*/       {
/*BRIGHT5P*/          if(arfcn<=524)
/*BRIGHT5P*/          {  *rfN = ( (((arfcn-512) + 51)<<5) | (150<<11) | (0x000019) ); }  /*  ARFCN :   512~  524 */
/*BRIGHT5P*/          else if(arfcn<=588)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-525)<<5) | (151<<11) | (0x000019) ); }  /*  ARFCN :  525~ 588 */
/*BRIGHT5P*/          else if(arfcn<=652)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-589)<<5) | (152<<11) | (0x000019) ); }  /*  ARFCN :  589~ 652 */
/*BRIGHT5P*/          else if(arfcn<=716)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-653)<<5) | (153<<11) | (0x000019) ); }  /*  ARFCN :  653~ 716 */
/*BRIGHT5P*/          else if(arfcn<=780)
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-717)<<5) | (154<<11) | (0x000019) ); }  /*  ARFCN :  717~ 780 */
/*BRIGHT5P*/          else
/*BRIGHT5P*/          {  *rfN = ( ((arfcn-781)<<5) | (155<<11) | (0x000019) ); }  /*  ARFCN :  781~ 810 */
/*BRIGHT5P*/          break;
/*BRIGHT5P*/       }
/*BRIGHT5P*/       default :
/*BRIGHT5P*/       {  break;
/*BRIGHT5P*/       }
/*BRIGHT5P*/    }
/*BRIGHT5P*/    *ifN = 0;
/*BRIGHT5P*/ }
/*BRIGHT5P*/ /* =========================================================================== */
#endif

#if IS_RF_AERO
/*AERO*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*AERO*/ {
/*AERO*/    switch(rf_band)
/*AERO*/    {
/*AERO*/       case  FrequencyBand900 :
/*AERO*/       {
/*AERO*/          if(arfcn<=124)
/*AERO*/          {  *rfN = 0x092160 + (arfcn<<7);  }  /*  ARFCN :   1~  124 */
/*AERO*/          else
/*AERO*/          {  *rfN = 0x072160 + (arfcn<<7);  }  /*  ARFCN : 975~1023 */
/*AERO*/          break;
/*AERO*/       }
/*AERO*/       case  FrequencyBand1800 :
/*AERO*/       {
/*AERO*/          *rfN = 0x50A0E0 + (arfcn<<7);        /*  ARFCN : 512~ 885 */
/*AERO*/          break;
/*AERO*/       }
/*AERO*/       case  FrequencyBand1900 :
/*AERO*/       {
/*AERO*/          *rfN = 0x91D960 + (arfcn<<7);        /*  ARFCN : 512~ 810 */
/*AERO*/          break;
/*AERO*/       }
/*AERO*/       default :
/*AERO*/       {
/*AERO*/          break;
/*AERO*/       }
/*AERO*/    }
/*AERO*/    *ifN = 0;
/*AERO*/ }
/*AERO*/ /* =========================================================================== */
/*AERO*/
/*AERO*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*AERO*/ {
/*AERO*/    switch(rf_band)
/*AERO*/    {
/*AERO*/       case  FrequencyBand900 :
/*AERO*/       {
/*AERO*/         if(arfcn<=49)
/*AERO*/         {
/*AERO*/            if(arfcn<=24)                    /* ARFCN :   0~  24 */
/*AERO*/            {  *rfN = 0x064B63 + (arfcn<<6);
/*AERO*/               *ifN = 0X73E5A4;
/*AERO*/            }
/*AERO*/            else                             /* ARFCN :  25~  49 */
/*AERO*/            {  *rfN = 0x064663 + (arfcn<<6);
/*AERO*/               *ifN = 0X73DBA4;
/*AERO*/            }
/*AERO*/         }
/*AERO*/         else
/*AERO*/         {
/*AERO*/            if(arfcn<=124)                   /* ARFCN :  50~ 124 */
/*AERO*/            {  *rfN = 0x064B63 + (arfcn<<6);
/*AERO*/               *ifN = 0X73E5A4;
/*AERO*/            }
/*AERO*/            else                             /* ARFCN : 975~1023 */
/*AERO*/            {  *rfN = 0x054B63 + (arfcn<<6);
/*AERO*/               *ifN = 0X73E5A4;
/*AERO*/            }
/*AERO*/         }
/*AERO*/         break;
/*AERO*/       }
/*AERO*/       case  FrequencyBand1800 :
/*AERO*/       {
/*AERO*/          *rfN = 0x45FB23 + (arfcn<<6);  /*  ARFCN : 512~ 885 */
/*AERO*/          *ifN = 0X63BDA4;
/*AERO*/          break;
/*AERO*/       }
/*AERO*/       case  FrequencyBand1900 :
/*AERO*/       {
/*AERO*/          *rfN = 0x867323 + (arfcn<<6);   /*  ARFCN : 512~ 810 */
/*AERO*/          *ifN = 0X742BA4;
/*AERO*/          break;
/*AERO*/       }
/*AERO*/       default :
/*AERO*/       {  break;
/*AERO*/       }
/*AERO*/    }
/*AERO*/ }
/*AERO*/ /* =========================================================================== */
#endif

#if IS_RF_AERO1PLUS
/*AERO1+*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*AERO1+*/ {
/*AERO1+*/    switch(rf_band)
/*AERO1+*/    {
/*AERO1+*/       case  FrequencyBand900 :
/*AERO1+*/       {
/*AERO1+*/          if(arfcn<=124)
/*AERO1+*/          {  *rfN = 0x092160 + (arfcn<<7);  }  /*  ARFCN :   1~  124 */
/*AERO1+*/          else
/*AERO1+*/          {  *rfN = 0x072160 + (arfcn<<7);  }  /*  ARFCN : 975~1023 */
/*AERO1+*/          break;
/*AERO1+*/       }
/*AERO1+*/       case  FrequencyBand1800 :
/*AERO1+*/       {
/*AERO1+*/          *rfN = 0x50A0E0 + (arfcn<<7);        /*  ARFCN : 512~ 885 */
/*AERO1+*/          break;
/*AERO1+*/       }
/*AERO1+*/       case  FrequencyBand1900 :
/*AERO1+*/       {
/*AERO1+*/          *rfN = 0x91D960 + (arfcn<<7);        /*  ARFCN : 512~ 810 */
/*AERO1+*/          break;
/*AERO1+*/       }
/*AERO1+*/       default :
/*AERO1+*/       {
/*AERO1+*/          break;
/*AERO1+*/       }
/*AERO1+*/    }
/*AERO1+*/    *ifN = 0;
/*AERO1+*/ }
/*AERO1+*/ /* =========================================================================== */
/*AERO1+*/
/*AERO1+*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*AERO1+*/ {
/*AERO1+*/    switch(rf_band)
/*AERO1+*/    {
/*AERO1+*/       case  FrequencyBand900 :
/*AERO1+*/       {
/*AERO1+*/         if(arfcn<=49)
/*AERO1+*/         {
/*AERO1+*/            if(arfcn<=24)                    /* ARFCN :   0~  24 */
/*AERO1+*/            {  *rfN = 0x064B63 + (arfcn<<6);
/*AERO1+*/               *ifN = 0X73E5A4;
/*AERO1+*/            }
/*AERO1+*/            else                             /* ARFCN :  25~  49 */
/*AERO1+*/            {  *rfN = 0x064663 + (arfcn<<6);
/*AERO1+*/               *ifN = 0X73DBA4;
/*AERO1+*/            }
/*AERO1+*/         }
/*AERO1+*/         else
/*AERO1+*/         {
/*AERO1+*/            if(arfcn<=124)                   /* ARFCN :  50~ 124 */
/*AERO1+*/            {  *rfN = 0x064B63 + (arfcn<<6);
/*AERO1+*/               *ifN = 0X73E5A4;
/*AERO1+*/            }
/*AERO1+*/            else                             /* ARFCN : 975~1023 */
/*AERO1+*/            {  *rfN = 0x054B63 + (arfcn<<6);
/*AERO1+*/               *ifN = 0X73E5A4;
/*AERO1+*/            }
/*AERO1+*/         }
/*AERO1+*/         break;
/*AERO1+*/       }
/*AERO1+*/       case  FrequencyBand1800 :
/*AERO1+*/       {
/*AERO1+*/          *rfN = 0x45FB23 + (arfcn<<6);  /*  ARFCN : 512~ 885 */
/*AERO1+*/          *ifN = 0X63BDA4;
/*AERO1+*/          break;
/*AERO1+*/       }
/*AERO1+*/       case  FrequencyBand1900 :
/*AERO1+*/       {
/*AERO1+*/          *rfN = 0x867323 + (arfcn<<6);   /*  ARFCN : 512~ 810 */
/*AERO1+*/          *ifN = 0X742BA4;
/*AERO1+*/          break;
/*AERO1+*/       }
/*AERO1+*/       default :
/*AERO1+*/       {  break;
/*AERO1+*/       }
/*AERO1+*/    }
/*AERO1+*/ }
/*AERO1+*/ /* =========================================================================== */
#endif

#if IS_RF_POLARIS1
/*RFMD*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*RFMD*/ {
/*RFMD*/    int OFFS;
/*RFMD*/    switch(rf_band)
/*RFMD*/    {
/*RFMD*/       case  FrequencyBand900 :
/*RFMD*/       {
/*RFMD*/          if(arfcn<=124)                      /*  ARFCN :   0~ 124 */
/*RFMD*/          {
/*RFMD*/             OFFS = 80*arfcn + 41160;
/*RFMD*/             *rfN = 0x0C0000L | (OFFS);
/*RFMD*/          }
/*RFMD*/          else                                /*  ARFCN : 975~1023 */
/*RFMD*/          {
/*RFMD*/             OFFS = 80*arfcn - 40760;
/*RFMD*/             *rfN = 0x0C0000L + (OFFS);
/*RFMD*/          }
/*RFMD*/          break;
/*RFMD*/       }
/*RFMD*/       case  FrequencyBand1800 :              /*  ARFCN : 512~ 885 */
/*RFMD*/       {
/*RFMD*/          OFFS = 40*arfcn + 7740;
/*RFMD*/          *rfN = 0x0C0000L + (OFFS);
/*RFMD*/          break;
/*RFMD*/       }
/*RFMD*/       case  FrequencyBand1900 :              /*  ARFCN : 512~ 810 */
/*RFMD*/       {
/*RFMD*/          OFFS = 40*arfcn + 32740;
/*RFMD*/          *rfN = 0x0C0000L + (OFFS);
/*RFMD*/          break;
/*RFMD*/       }
/*RFMD*/       default :
/*RFMD*/       {
/*RFMD*/          break;
/*RFMD*/       }
/*RFMD*/    }
/*RFMD*/    *ifN = 0;
/*RFMD*/ }
/*RFMD*/ /* =========================================================================== */
/*RFMD*/
/*RFMD*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*RFMD*/ {
/*RFMD*/    int OFFS;
/*RFMD*/    switch(rf_band)
/*RFMD*/    {
/*RFMD*/       case  FrequencyBand900 :
/*RFMD*/       {
/*RFMD*/          if(arfcn<=124)                    /*  ARFCN :   0~ 124 */
/*RFMD*/          {
/*RFMD*/             OFFS = 40*arfcn + 178000;
/*RFMD*/             *rfN = 0x0C0000L | (OFFS);
/*RFMD*/          }
/*RFMD*/          else                              /*  ARFCN : 975~1023 */
/*RFMD*/          {  OFFS = 40*arfcn + 137040;
/*RFMD*/             *rfN = 0x0C0000L + (OFFS);
/*RFMD*/          }
/*RFMD*/          break;
/*RFMD*/       }
/*RFMD*/       case  FrequencyBand1800 :            /*  ARFCN : 512~ 885 */
/*RFMD*/       {
/*RFMD*/          OFFS = 40*arfcn - 11240;
/*RFMD*/          *rfN = 0x0C0000L + (OFFS);
/*RFMD*/          break;
/*RFMD*/
/*RFMD*/       }
/*RFMD*/       case  FrequencyBand1900 :            /*  ARFCN : 512~ 810 */
/*RFMD*/       {
/*RFMD*/          OFFS = 40*arfcn + 16760;
/*RFMD*/          *rfN = 0x0C0000L + (OFFS);
/*RFMD*/          break;
/*RFMD*/       }
/*RFMD*/       default :
/*RFMD*/       {  break;
/*RFMD*/       }
/*RFMD*/    }
/*RFMD*/      *ifN = 0;
/*RFMD*/ }
/*RFMD*/ /* =========================================================================== */
#endif

#if IS_RF_SKY74117
/*SKY74117*/ typedef struct
/*SKY74117*/ {  short  arfcn;
/*SKY74117*/    short  Nint;
/*SKY74117*/    int    Fbase;
/*SKY74117*/    int    Fstep;
/*SKY74117*/    short  Inj_Div;
/*SKY74117*/ }  SKY74117_PLL_ELM;
/*SKY74117*/
/*SKY74117*/ const SKY74117_PLL_ELM  SKY74117_RX_850[] =
/*SKY74117*/ {
/*SKY74117*/    { 128 , 96 , 3323179, 3097332 },
/*SKY74117*/    { 137 , 97 ,       0, 3097332 },
/*SKY74117*/    { 181 , 98 ,   64527, 3097332 },
/*SKY74117*/    { 224 , 99 ,   32263, 3097332 },
/*SKY74117*/ };
/*SKY74117*/ const SKY74117_PLL_ELM  SKY74117_RX_900[] =
/*SKY74117*/ {
/*SKY74117*/    { 0   , 104, 1613193, 3097332 },
/*SKY74117*/    { 27  , 105, 32263  , 3097332 },
/*SKY74117*/    { 70  , 106, 0      , 3097332 },
/*SKY74117*/    { 114 , 107, 64527  , 3097332 },
/*SKY74117*/    { 975 , 103, 1064707, 3097332 },
/*SKY74117*/    { 1008, 104, 64527  , 3097332 },
/*SKY74117*/ };
/*SKY74117*/ const SKY74117_PLL_ELM  SKY74117_RX_1800[] =
/*SKY74117*/ {
/*SKY74117*/    { 512 , 100, 2710165, 1548666 },
/*SKY74117*/    { 543 , 101, 16131  , 1548666 },
/*SKY74117*/    { 630 , 102, 32263  , 1548666 },
/*SKY74117*/    { 716 , 103, 0      , 1548666 },
/*SKY74117*/    { 803 , 104, 16131  , 1548666 },
/*SKY74117*/ };
/*SKY74117*/ const SKY74117_PLL_ELM  SKY74117_RX_1900[] =
/*SKY74117*/ {
/*SKY74117*/    { 512 , 107, 3597422, 1548666 },
/*SKY74117*/    { 525 , 108, 32263  , 1548666 },
/*SKY74117*/    { 611 , 109, 0      , 1548666 },
/*SKY74117*/    { 698 , 110, 16131  , 1548666 },
/*SKY74117*/    { 785 , 111, 32263  , 1548666 },
/*SKY74117*/ };
/*SKY74117*/ const SKY74117_PLL_ELM *const  SKY74117_RXPLL_TBL[] =
/*SKY74117*/ {
/*SKY74117*/    0,                                 /* FrequencyBand400 (not support)  */
/*SKY74117*/    SKY74117_RX_850,                  /* FrequencyBand850                */
/*SKY74117*/    SKY74117_RX_900,                  /* FrequencyBand900                */
/*SKY74117*/    SKY74117_RX_1800,                 /* FrequencyBand1800               */
/*SKY74117*/    SKY74117_RX_1900,                 /* FrequencyBand1900               */
/*SKY74117*/ };
/*SKY74117*/
/*SKY74117*/ short SKY74117_RXPLL_TBL_SIZE[5] =
/*SKY74117*/ {
/*SKY74117*/    0,                                                     /* FrequencyBand400 (not support)  */
/*SKY74117*/    sizeof(SKY74117_RX_850)/sizeof(SKY74117_PLL_ELM)-1,    /* FrequencyBand850                */
/*SKY74117*/    sizeof(SKY74117_RX_900)/sizeof(SKY74117_PLL_ELM)-1,    /* FrequencyBand900                */
/*SKY74117*/    sizeof(SKY74117_RX_1800)/sizeof(SKY74117_PLL_ELM)-1,   /* FrequencyBand1800               */
/*SKY74117*/    sizeof(SKY74117_RX_1900)/sizeof(SKY74117_PLL_ELM)-1,   /* FrequencyBand1900               */
/*SKY74117*/ };
/*SKY74117*/
/*SKY74117*/ const SKY74117_PLL_ELM  SKY74117_TX_850[] =
/*SKY74117*/ {
/*SKY74117*/    { 128 , 83 , 1881444,  2831846, 1  },
/*SKY74117*/    { 145 , 101, 3652493,  3417745, 3  },
/*SKY74117*/    { 149 , 83 , 3739844,  2831846, 1  },
/*SKY74117*/    { 152 , 102, 205821 ,  3417745, 3  },
/*SKY74117*/    { 157 , 84 , 253501 ,  2831846, 1  },
/*SKY74117*/    { 177 , 102, 2875935,  3417745, 3  },
/*SKY74117*/    { 190 , 103, 70090  ,  3417745, 3  },
/*SKY74117*/    { 198 , 84 , 3881805,  2831846, 1  },
/*SKY74117*/    { 200 , 103, 1138136,  3417745, 3  },
/*SKY74117*/    { 209 , 85 , 660948 ,  2831846, 1  },
/*SKY74117*/    { 211 , 103, 2312986,  3417745, 3  },
/*SKY74117*/    { 218 , 85 , 1457405,  2831846, 1  },
/*SKY74117*/    { 221 , 103, 3381031,  3417745, 3  },
/*SKY74117*/    { 227 , 85 , 2253862,  2831846, 1  },
/*SKY74117*/    { 249 , 104, 2177255,  0      , 3  },
/*SKY74117*/    { 250 , 86 , 94947  ,  2831846, 1  },
/*SKY74117*/ };
/*SKY74117*/ const SKY74117_PLL_ELM  SKY74117_TX_900[] =
/*SKY74117*/ {
/*SKY74117*/    { 0   , 109, 3421083, 3417745 , 3  },
/*SKY74117*/    { 6   , 90 , 2167210, 2831846 , 1  },
/*SKY74117*/    { 19  , 110, 1256066, 3417745 , 3  },
/*SKY74117*/    { 25  , 90 , 3848619, 2831846 , 1  },
/*SKY74117*/    { 29  , 110, 2324111, 3417745 , 3  },
/*SKY74117*/    { 46  , 91 , 1512714, 2831846 , 1  },
/*SKY74117*/    { 48  , 111, 159094 , 3417745 , 3  },
/*SKY74117*/    { 64  , 91 , 3105628, 2831846 , 1  },
/*SKY74117*/    { 75  , 111, 3042817, 3417745 , 3  },
/*SKY74117*/    { 78  , 92 , 150257 , 2831846 , 1  },
/*SKY74117*/    { 87  , 112, 130168 , 3417745 , 3  },
/*SKY74117*/    { 104 , 92 , 2451132, 0       , 1  },
/*SKY74117*/    { 105 , 112, 2052650, 3417745 , 3  },
/*SKY74117*/    { 107 , 92 , 2716618, 2831846 , 1  },
/*SKY74117*/    { 124 , 93 , 26732  , 75367399, 1  },
/*SKY74117*/    { 975 , 108, 2381964, 3417745 , 3  },
/*SKY74117*/    { 991 , 89 , 2910201, 2831846 , 1  },
/*SKY74117*/    { 993 , 109, 110142 , 3417745 , 3  },
/*SKY74117*/    { 1010, 90 , 397306 , 52330164, 1  },
/*SKY74117*/    { 1011, 109, 2032624, 3417745 , 3  },
/*SKY74117*/    { 1013, 90 , 662792 , 2831846 , 1  },
/*SKY74117*/    { 1015, 109, 2459842, 3417745 , 3  },
/*SKY74117*/    { 1019, 90 , 1193763, 57603258, 1  },
/*SKY74117*/    { 1020, 109, 2993865, 3417745 , 3  },
/*SKY74117*/ };
/*SKY74117*/ const SKY74117_PLL_ELM  SKY74117_TX_1800[] =
/*SKY74117*/ {
/*SKY74117*/    { 512, 90 , 3135374, 1479322  , 1  },
/*SKY74117*/    { 516, 100, 277680 , 1624829  , 3  },
/*SKY74117*/    { 546, 91 , 512851 , 1479322  , 1  },
/*SKY74117*/    { 559, 100, 2461046, 1624829  , 3  },
/*SKY74117*/    { 567, 91 , 1483656, 1479322  , 1  },
/*SKY74117*/    { 576, 100, 3324237, 1624829  , 3  },
/*SKY74117*/    { 591, 91 , 2593148, 1479322  , 1  },
/*SKY74117*/    { 597, 101, 196227 , 1624829  , 3  },
/*SKY74117*/    { 630, 92 , 201769 , 1479322  , 1  },
/*SKY74117*/    { 641, 101, 2430369, 1624829  , 3  },
/*SKY74117*/    { 674, 88 , 1750545, 1415923  , 0  },
/*SKY74117*/    { 677, 102, 63998  , 1624829  , 3  },
/*SKY74117*/    { 681, 92 , 2559440, 1479322  , 1  },
/*SKY74117*/    { 691, 102, 774861 , 1624829  , 3  },
/*SKY74117*/    { 696, 88 , 2723993, 1415923  , 0  },
/*SKY74117*/    { 706, 102, 1536501, 1624829  , 3  },
/*SKY74117*/    { 712, 92 , 3992534, 1479322  , 1  },
/*SKY74117*/    { 714, 88 , 3520449, 1415923  , 0  },
/*SKY74117*/    { 719, 93 , 121832 , 1479322  , 1  },
/*SKY74117*/    { 723, 102, 2399691, 1624829  , 3  },
/*SKY74117*/    { 756, 89 , 1184545, 1415923  , 0  },
/*SKY74117*/    { 762, 103, 185649 , 1624829  , 3  },
/*SKY74117*/    { 788, 93 , 3311622, 1479322  , 1  },
/*SKY74117*/    { 806, 89 , 3396925, 1415923  , 0  },
/*SKY74117*/    { 812, 94 , 226810 , 1479322  , 1  },
/*SKY74117*/    { 821, 103, 3181429, 1624829  , 3  },
/*SKY74117*/    { 824, 94 , 781556 , 1479322  , 1  },
/*SKY74117*/    { 826, 103, 3435309, 1624829  , 3  },
/*SKY74117*/    { 839, 94 , 1474988, 1479322  , 1  },
/*SKY74117*/    { 844, 104, 154972 , 1624829  , 3  },
/*SKY74117*/    { 876, 94 , 3185455, 1479322  , 1  },
/*SKY74117*/ };
/*SKY74117*/ const SKY74117_PLL_ELM  SKY74117_TX_1900[] =
/*SKY74117*/ {
/*SKY74117*/    { 512 , 94 , 389931 , 0       , 0  },
/*SKY74117*/    { 513 , 94 , 434179 , 1415923 , 0  },
/*SKY74117*/    { 518 , 108, 2367956, 1624829 , 3  },
/*SKY74117*/    { 522 , 98 , 2403418, 1479322 , 1  },
/*SKY74117*/    { 558 , 109, 204690 , 1624829 , 3  },
/*SKY74117*/    { 581 , 99 , 936615 , 1479322 , 1  },
/*SKY74117*/    { 601 , 109, 2388055, 1624829 , 3  },
/*SKY74117*/    { 614 , 99 , 2462167, 1479322 , 1  },
/*SKY74117*/    { 645 , 110, 427893 , 1624829 , 3  },
/*SKY74117*/    { 652 , 95 , 2390292, 1415923 , 0  },
/*SKY74117*/    { 671 , 100, 902907 , 1479322 , 1  },
/*SKY74117*/    { 683 , 110, 2357378, 1624829 , 3  },
/*SKY74117*/    { 701 , 100, 2289772, 1479322 , 1  },
/*SKY74117*/    { 719 , 96 , 1160577, 1415923 , 0  },
/*SKY74117*/    { 728 , 100, 3537950, 1479322 , 1  },
/*SKY74117*/    { 740 , 111, 1057303, 1624829 , 3  },
/*SKY74117*/    { 746 , 101, 175765 , 1479322 , 1  },
/*SKY74117*/    { 781 , 111, 3139116, 1624829 , 3  },
/*SKY74117*/    { 796 , 101, 2487207, 1479322 , 1  },
/*SKY74117*/ };
/*SKY74117*/
/*SKY74117*/ const SKY74117_PLL_ELM *const  SKY74117_TXPLL_TBL[] =
/*SKY74117*/ {
/*SKY74117*/    0,                                /* FrequencyBand400 (not support)  */
/*SKY74117*/    SKY74117_TX_850,                  /* FrequencyBand850                */
/*SKY74117*/    SKY74117_TX_900,                  /* FrequencyBand900                */
/*SKY74117*/    SKY74117_TX_1800,                 /* FrequencyBand1800               */
/*SKY74117*/    SKY74117_TX_1900,                 /* FrequencyBand1900               */
/*SKY74117*/ };
/*SKY74117*/
/*SKY74117*/ short  SKY74117_TXPLL_TBL_SIZE[5] =
/*SKY74117*/ {
/*SKY74117*/    0,                                                     /* FrequencyBand400 (not support)  */
/*SKY74117*/    sizeof(SKY74117_TX_850)/sizeof(SKY74117_PLL_ELM)-1,    /* FrequencyBand850                */
/*SKY74117*/    sizeof(SKY74117_TX_900)/sizeof(SKY74117_PLL_ELM)-1,    /* FrequencyBand900                */
/*SKY74117*/    sizeof(SKY74117_TX_1800)/sizeof(SKY74117_PLL_ELM)-1,   /* FrequencyBand1800               */
/*SKY74117*/    sizeof(SKY74117_TX_1900)/sizeof(SKY74117_PLL_ELM)-1,   /* FrequencyBand1900               */
/*SKY74117*/ };
/*SKY74117*/
/*SKY74117*/ short  SKY74117_TXPLL_INJECTIN_TBL[5] =
/*SKY74117*/ {
/*SKY74117*/    0,       /* FrequencyBand400 (not support)  */
/*SKY74117*/    90,      /* FrequencyBand850 (not support)  */
/*SKY74117*/    95,      /* FrequencyBand900 (not support)  */
/*SKY74117*/    98,      /* FrequencyBand1800 (not support)  */
/*SKY74117*/    105,     /* FrequencyBand1900 (not support)  */
/*SKY74117*/ };
/*SKY74117*/
/*SKY74117*/ const unsigned long SDATA_TX_TABLE[5] =
/*SKY74117*/ {
/*SKY74117*/           0L ,  /* FrequencyBand400 (not support)  */
/*SKY74117*/    0x040004L ,  /* FrequencyBand850                */
/*SKY74117*/    0x050004L ,  /* FrequencyBand900                */
/*SKY74117*/    0x060004L ,  /* FrequencyBand1800               */
/*SKY74117*/    0x070004L ,  /* FrequencyBand1900               */
/*SKY74117*/ };
/*SKY74117*/ const unsigned long SDATA_TX_Div_TABLE[2] = { 0x100000, 0x200000 };  // 0: /8  1: /16
/*SKY74117*/ const unsigned long SDATA_TX_Inj_TABLE[2] = { 0x000000, 0x080000 };  // 0: Low 1: High
/*SKY74117*/ unsigned long  SKY74117_TxCtrl = 0;
/*SKY74117*/ unsigned long  SKY74117_TxCtrl_Mask = 0;
/*SKY74117*/
/*SKY74117*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*SKY74117*/ {  int   Nfrac;
/*SKY74117*/    const SKY74117_PLL_ELM*  elmptr;
/*SKY74117*/    int left, right, middle;
/*SKY74117*/
/*SKY74117*/   /*binary search*/
/*SKY74117*/   elmptr = SKY74117_RXPLL_TBL[rf_band];
/*SKY74117*/   left = 0; right = SKY74117_RXPLL_TBL_SIZE[rf_band];
/*SKY74117*/   while (left <= right)
/*SKY74117*/   {  middle = (left + right)/2;
/*SKY74117*/      if ( arfcn<(elmptr+middle)->arfcn )
/*SKY74117*/         right = middle - 1;
/*SKY74117*/      else
/*SKY74117*/         left = middle + 1;
/*SKY74117*/   }
/*SKY74117*/   elmptr = (elmptr+left-1);
/*SKY74117*/
/*SKY74117*/   Nfrac = elmptr->Fbase + (((arfcn-elmptr->arfcn)*elmptr->Fstep)>>5);
/*SKY74117*/   *rfN = (elmptr->Nint<<6) | 0xC40000;
/*SKY74117*/   *ifN = (Nfrac<<2) | 3;
/*SKY74117*/ //  *rfN = elmptr->Nint;
/*SKY74117*/ //  *ifN = Nfrac;
/*SKY74117*/ }
/*SKY74117*/ /* =========================================================================== */
/*SKY74117*/
/*SKY74117*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*SKY74117*/ {  int   Nfrac;
/*SKY74117*/    const SKY74117_PLL_ELM*  elmptr;
/*SKY74117*/    int left, right, middle;
/*SKY74117*/    int div;
/*SKY74117*/
/*SKY74117*/   /*binary search*/
/*SKY74117*/   elmptr = SKY74117_TXPLL_TBL[rf_band];
/*SKY74117*/   left = 0; right = SKY74117_TXPLL_TBL_SIZE[rf_band];
/*SKY74117*/   while (left <= right)
/*SKY74117*/   {  middle = (left + right)/2;
/*SKY74117*/      if ( arfcn<(elmptr+middle)->arfcn )
/*SKY74117*/         right = middle - 1;
/*SKY74117*/      else
/*SKY74117*/         left = middle + 1;
/*SKY74117*/   }
/*SKY74117*/   elmptr = (elmptr+left-1);
/*SKY74117*/   Nfrac = elmptr->Fbase + (((arfcn-elmptr->arfcn)*elmptr->Fstep)>>5);
/*SKY74117*/   *rfN = (elmptr->Nint<<6) | 0xC40000;
/*SKY74117*/   *ifN = (Nfrac<<2) | 3;
/*SKY74117*/ //  *rfN = elmptr->Nint;
/*SKY74117*/ //  *ifN = Nfrac;
/*SKY74117*/
/*SKY74117*/   l1d_rf.next_inj = (elmptr->Inj_Div>>1)&0x01;
/*SKY74117*/   div = (elmptr->Inj_Div>>0)&0x01;
/*SKY74117*/   SKY74117_TxCtrl_Mask = SDATA_TX_Div_TABLE[div] | SDATA_TX_Inj_TABLE[l1d_rf.next_inj];
/*SKY74117*/   SKY74117_TxCtrl = SDATA_TX_TABLE[rf_band] | SDATA_TX_Div_TABLE[div] | SDATA_TX_Inj_TABLE[l1d_rf.next_inj];
/*SKY74117*/ }
/*SKY74117*/ /* =========================================================================== */
#endif

#if IS_RF_SKY74400
/*SKY74400*/ typedef struct
/*SKY74400*/ {  short  arfcn;
/*SKY74400*/    short  Nint;
/*SKY74400*/    int    Fbase;
/*SKY74400*/    int    Fstep;
/*SKY74400*/    short  Inj_Div;
/*SKY74400*/ }  SKY74400_PLL_ELM;
/*SKY74400*/
/*SKY74400*/ const SKY74400_PLL_ELM  SKY74400_RX_850[] =
/*SKY74400*/ {
/*SKY74400*/    { 128 , 96 , 3323179, 3097332 },
/*SKY74400*/    { 137 , 97 ,       0, 3097332 },
/*SKY74400*/    { 181 , 98 ,   64527, 3097332 },
/*SKY74400*/    { 224 , 99 ,   32263, 3097332 },
/*SKY74400*/ };
/*SKY74400*/ const SKY74400_PLL_ELM  SKY74400_RX_900[] =
/*SKY74400*/ {
/*SKY74400*/    { 0   , 104, 1613193, 3097332 },
/*SKY74400*/    { 27  , 105, 32263  , 3097332 },
/*SKY74400*/    { 70  , 106, 0      , 3097332 },
/*SKY74400*/    { 114 , 107, 64527  , 3097332 },
/*SKY74400*/    { 975 , 103, 1064707, 3097332 },
/*SKY74400*/    { 1008, 104, 64527  , 3097332 },
/*SKY74400*/ };
/*SKY74400*/ const SKY74400_PLL_ELM  SKY74400_RX_1800[] =
/*SKY74400*/ {
/*SKY74400*/    { 512 , 100, 2710165, 1548666 },
/*SKY74400*/    { 543 , 101, 16131  , 1548666 },
/*SKY74400*/    { 630 , 102, 32263  , 1548666 },
/*SKY74400*/    { 716 , 103, 0      , 1548666 },
/*SKY74400*/    { 803 , 104, 16131  , 1548666 },
/*SKY74400*/ };
/*SKY74400*/ const SKY74400_PLL_ELM  SKY74400_RX_1900[] =
/*SKY74400*/ {
/*SKY74400*/    { 512 , 107, 3597422, 1548666 },
/*SKY74400*/    { 525 , 108, 32263  , 1548666 },
/*SKY74400*/    { 611 , 109, 0      , 1548666 },
/*SKY74400*/    { 698 , 110, 16131  , 1548666 },
/*SKY74400*/    { 785 , 111, 32263  , 1548666 },
/*SKY74400*/ };
/*SKY74400*/ const SKY74400_PLL_ELM *const  SKY74400_RXPLL_TBL[] =
/*SKY74400*/ {
/*SKY74400*/    0,                                 /* FrequencyBand400 (not support)  */
/*SKY74400*/    SKY74400_RX_850,                  /* FrequencyBand850                */
/*SKY74400*/    SKY74400_RX_900,                  /* FrequencyBand900                */
/*SKY74400*/    SKY74400_RX_1800,                 /* FrequencyBand1800               */
/*SKY74400*/    SKY74400_RX_1900,                 /* FrequencyBand1900               */
/*SKY74400*/ };
/*SKY74400*/
/*SKY74400*/ short SKY74400_RXPLL_TBL_SIZE[5] =
/*SKY74400*/ {
/*SKY74400*/    0,                                                     /* FrequencyBand400 (not support)  */
/*SKY74400*/    sizeof(SKY74400_RX_850)/sizeof(SKY74400_PLL_ELM)-1,    /* FrequencyBand850                */
/*SKY74400*/    sizeof(SKY74400_RX_900)/sizeof(SKY74400_PLL_ELM)-1,    /* FrequencyBand900                */
/*SKY74400*/    sizeof(SKY74400_RX_1800)/sizeof(SKY74400_PLL_ELM)-1,   /* FrequencyBand1800               */
/*SKY74400*/    sizeof(SKY74400_RX_1900)/sizeof(SKY74400_PLL_ELM)-1,   /* FrequencyBand1900               */
/*SKY74400*/ };
/*SKY74400*/
/*SKY74400*/ const SKY74400_PLL_ELM  SKY74400_TX_850[] =
/*SKY74400*/ {
/*SKY74400*/    { 128 , 83 , 1881444,  2831846, 1  },
/*SKY74400*/    { 145 , 101, 3652493,  3417745, 3  },
/*SKY74400*/    { 149 , 83 , 3739844,  2831846, 1  },
/*SKY74400*/    { 152 , 102, 205821 ,  3417745, 3  },
/*SKY74400*/    { 157 , 84 , 253501 ,  2831846, 1  },
/*SKY74400*/    { 177 , 102, 2875935,  3417745, 3  },
/*SKY74400*/    { 190 , 103, 70090  ,  3417745, 3  },
/*SKY74400*/    { 198 , 84 , 3881805,  2831846, 1  },
/*SKY74400*/    { 200 , 103, 1138136,  3417745, 3  },
/*SKY74400*/    { 209 , 85 , 660948 ,  2831846, 1  },
/*SKY74400*/    { 211 , 103, 2312986,  3417745, 3  },
/*SKY74400*/    { 218 , 85 , 1457405,  2831846, 1  },
/*SKY74400*/    { 221 , 103, 3381031,  3417745, 3  },
/*SKY74400*/    { 227 , 85 , 2253862,  2831846, 1  },
/*SKY74400*/    { 249 , 104, 2177255,  0      , 3  },
/*SKY74400*/    { 250 , 86 , 94947  ,  2831846, 1  },
/*SKY74400*/ };
/*SKY74400*/ const SKY74400_PLL_ELM  SKY74400_TX_900[] =
/*SKY74400*/ {
/*SKY74400*/    { 0   , 109, 3421083, 3417745 , 3  },
/*SKY74400*/    { 6   , 90 , 2167210, 2831846 , 1  },
/*SKY74400*/    { 19  , 110, 1256066, 3417745 , 3  },
/*SKY74400*/    { 25  , 90 , 3848619, 2831846 , 1  },
/*SKY74400*/    { 29  , 110, 2324111, 3417745 , 3  },
/*SKY74400*/    { 46  , 91 , 1512714, 2831846 , 1  },
/*SKY74400*/    { 48  , 111, 159094 , 3417745 , 3  },
/*SKY74400*/    { 64  , 91 , 3105628, 2831846 , 1  },
/*SKY74400*/    { 75  , 111, 3042817, 3417745 , 3  },
/*SKY74400*/    { 78  , 92 , 150257 , 2831846 , 1  },
/*SKY74400*/    { 87  , 112, 130168 , 3417745 , 3  },
/*SKY74400*/    { 104 , 92 , 2451132, 0       , 1  },
/*SKY74400*/    { 105 , 112, 2052650, 3417745 , 3  },
/*SKY74400*/    { 107 , 92 , 2716618, 2831846 , 1  },
/*SKY74400*/    { 124 , 93 , 26732  , 75367399, 1  },
/*SKY74400*/    { 975 , 108, 2381964, 3417745 , 3  },
/*SKY74400*/    { 991 , 89 , 2910201, 2831846 , 1  },
/*SKY74400*/    { 993 , 109, 110142 , 3417745 , 3  },
/*SKY74400*/    { 1010, 90 , 397306 , 52330164, 1  },
/*SKY74400*/    { 1011, 109, 2032624, 3417745 , 3  },
/*SKY74400*/    { 1013, 90 , 662792 , 2831846 , 1  },
/*SKY74400*/    { 1015, 109, 2459842, 3417745 , 3  },
/*SKY74400*/    { 1019, 90 , 1193763, 57603258, 1  },
/*SKY74400*/    { 1020, 109, 2993865, 3417745 , 3  },
/*SKY74400*/ };
/*SKY74400*/ const SKY74400_PLL_ELM  SKY74400_TX_1800[] =
/*SKY74400*/ {
/*SKY74400*/    { 512, 90 , 3135374, 1479322  , 1  },
/*SKY74400*/    { 516, 100, 277680 , 1624829  , 3  },
/*SKY74400*/    { 546, 91 , 512851 , 1479322  , 1  },
/*SKY74400*/    { 559, 100, 2461046, 1624829  , 3  },
/*SKY74400*/    { 567, 91 , 1483656, 1479322  , 1  },
/*SKY74400*/    { 576, 100, 3324237, 1624829  , 3  },
/*SKY74400*/    { 591, 91 , 2593148, 1479322  , 1  },
/*SKY74400*/    { 597, 101, 196227 , 1624829  , 3  },
/*SKY74400*/    { 630, 92 , 201769 , 1479322  , 1  },
/*SKY74400*/    { 641, 101, 2430369, 1624829  , 3  },
/*SKY74400*/    { 674, 88 , 1750545, 1415923  , 0  },
/*SKY74400*/    { 677, 102, 63998  , 1624829  , 3  },
/*SKY74400*/    { 681, 92 , 2559440, 1479322  , 1  },
/*SKY74400*/    { 691, 102, 774861 , 1624829  , 3  },
/*SKY74400*/    { 696, 88 , 2723993, 1415923  , 0  },
/*SKY74400*/    { 706, 102, 1536501, 1624829  , 3  },
/*SKY74400*/    { 712, 92 , 3992534, 1479322  , 1  },
/*SKY74400*/    { 714, 88 , 3520449, 1415923  , 0  },
/*SKY74400*/    { 719, 93 , 121832 , 1479322  , 1  },
/*SKY74400*/    { 723, 102, 2399691, 1624829  , 3  },
/*SKY74400*/    { 756, 89 , 1184545, 1415923  , 0  },
/*SKY74400*/    { 762, 103, 185649 , 1624829  , 3  },
/*SKY74400*/    { 788, 93 , 3311622, 1479322  , 1  },
/*SKY74400*/    { 806, 89 , 3396925, 1415923  , 0  },
/*SKY74400*/    { 812, 94 , 226810 , 1479322  , 1  },
/*SKY74400*/    { 821, 103, 3181429, 1624829  , 3  },
/*SKY74400*/    { 824, 94 , 781556 , 1479322  , 1  },
/*SKY74400*/    { 826, 103, 3435309, 1624829  , 3  },
/*SKY74400*/    { 839, 94 , 1474988, 1479322  , 1  },
/*SKY74400*/    { 844, 104, 154972 , 1624829  , 3  },
/*SKY74400*/    { 876, 94 , 3185455, 1479322  , 1  },
/*SKY74400*/ };
/*SKY74400*/ const SKY74400_PLL_ELM  SKY74400_TX_1900[] =
/*SKY74400*/ {
/*SKY74400*/    { 512 , 94 , 389931 , 0       , 0  },
/*SKY74400*/    { 513 , 94 , 434179 , 1415923 , 0  },
/*SKY74400*/    { 518 , 108, 2367956, 1624829 , 3  },
/*SKY74400*/    { 522 , 98 , 2403418, 1479322 , 1  },
/*SKY74400*/    { 558 , 109, 204690 , 1624829 , 3  },
/*SKY74400*/    { 581 , 99 , 936615 , 1479322 , 1  },
/*SKY74400*/    { 601 , 109, 2388055, 1624829 , 3  },
/*SKY74400*/    { 614 , 99 , 2462167, 1479322 , 1  },
/*SKY74400*/    { 645 , 110, 427893 , 1624829 , 3  },
/*SKY74400*/    { 652 , 95 , 2390292, 1415923 , 0  },
/*SKY74400*/    { 671 , 100, 902907 , 1479322 , 1  },
/*SKY74400*/    { 683 , 110, 2357378, 1624829 , 3  },
/*SKY74400*/    { 701 , 100, 2289772, 1479322 , 1  },
/*SKY74400*/    { 719 , 96 , 1160577, 1415923 , 0  },
/*SKY74400*/    { 728 , 100, 3537950, 1479322 , 1  },
/*SKY74400*/    { 740 , 111, 1057303, 1624829 , 3  },
/*SKY74400*/    { 746 , 101, 175765 , 1479322 , 1  },
/*SKY74400*/    { 781 , 111, 3139116, 1624829 , 3  },
/*SKY74400*/    { 796 , 101, 2487207, 1479322 , 1  },
/*SKY74400*/ };
/*SKY74400*/
/*SKY74400*/ const SKY74400_PLL_ELM *const  SKY74400_TXPLL_TBL[] =
/*SKY74400*/ {
/*SKY74400*/    0,                                /* FrequencyBand400 (not support)  */
/*SKY74400*/    SKY74400_TX_850,                  /* FrequencyBand850                */
/*SKY74400*/    SKY74400_TX_900,                  /* FrequencyBand900                */
/*SKY74400*/    SKY74400_TX_1800,                 /* FrequencyBand1800               */
/*SKY74400*/    SKY74400_TX_1900,                 /* FrequencyBand1900               */
/*SKY74400*/ };
/*SKY74400*/
/*SKY74400*/ short  SKY74400_TXPLL_TBL_SIZE[5] =
/*SKY74400*/ {
/*SKY74400*/    0,                                                     /* FrequencyBand400 (not support)  */
/*SKY74400*/    sizeof(SKY74400_TX_850)/sizeof(SKY74400_PLL_ELM)-1,    /* FrequencyBand850                */
/*SKY74400*/    sizeof(SKY74400_TX_900)/sizeof(SKY74400_PLL_ELM)-1,    /* FrequencyBand900                */
/*SKY74400*/    sizeof(SKY74400_TX_1800)/sizeof(SKY74400_PLL_ELM)-1,   /* FrequencyBand1800               */
/*SKY74400*/    sizeof(SKY74400_TX_1900)/sizeof(SKY74400_PLL_ELM)-1,   /* FrequencyBand1900               */
/*SKY74400*/ };
/*SKY74400*/
/*SKY74400*/ short  SKY74400_TXPLL_INJECTIN_TBL[5] =
/*SKY74400*/ {
/*SKY74400*/    0,       /* FrequencyBand400 (not support)  */
/*SKY74400*/    90,      /* FrequencyBand850 (not support)  */
/*SKY74400*/    95,      /* FrequencyBand900 (not support)  */
/*SKY74400*/    98,      /* FrequencyBand1800 (not support)  */
/*SKY74400*/    105,     /* FrequencyBand1900 (not support)  */
/*SKY74400*/ };
/*SKY74400*/
/*SKY74400*/ const unsigned long SDATA_TX_TABLE[5] =
/*SKY74400*/ {
/*SKY74400*/           0L ,  /* FrequencyBand400 (not support)  */
/*SKY74400*/    0x040004L ,  /* FrequencyBand850                */
/*SKY74400*/    0x050004L ,  /* FrequencyBand900                */
/*SKY74400*/    0x060004L ,  /* FrequencyBand1800               */
/*SKY74400*/    0x070004L ,  /* FrequencyBand1900               */
/*SKY74400*/ };
/*SKY74400*/ const unsigned long SDATA_TX_Div_TABLE[2] = { 0x100000, 0x200000 };  // 0: /8  1: /16
/*SKY74400*/ const unsigned long SDATA_TX_Inj_TABLE[2] = { 0x000000, 0x080000 };  // 0: Low 1: High
/*SKY74400*/ unsigned long  SKY74400_TxCtrl = 0;
/*SKY74400*/ unsigned long  SKY74400_TxCtrl_Mask = 0;
/*SKY74400*/
/*SKY74400*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*SKY74400*/ {  int   Nfrac;
/*SKY74400*/    const SKY74400_PLL_ELM*  elmptr;
/*SKY74400*/    int left, right, middle;
/*SKY74400*/
/*SKY74400*/   /*binary search*/
/*SKY74400*/   elmptr = SKY74400_RXPLL_TBL[rf_band];
/*SKY74400*/   left = 0; right = SKY74400_RXPLL_TBL_SIZE[rf_band];
/*SKY74400*/   while (left <= right)
/*SKY74400*/   {  middle = (left + right)/2;
/*SKY74400*/      if ( arfcn<(elmptr+middle)->arfcn )
/*SKY74400*/         right = middle - 1;
/*SKY74400*/      else
/*SKY74400*/         left = middle + 1;
/*SKY74400*/   }
/*SKY74400*/   elmptr = (elmptr+left-1);
/*SKY74400*/
/*SKY74400*/   Nfrac = elmptr->Fbase + (((arfcn-elmptr->arfcn)*elmptr->Fstep)>>5);
/*SKY74400*/   *rfN = (elmptr->Nint<<6) | 0xC40000;
/*SKY74400*/   *ifN = (Nfrac<<2) | 3;
/*SKY74400*/ //  *rfN = elmptr->Nint;
/*SKY74400*/ //  *ifN = Nfrac;
/*SKY74400*/ }
/*SKY74400*/ /* =========================================================================== */
/*SKY74400*/
/*SKY74400*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*SKY74400*/ {  int   Nfrac;
/*SKY74400*/    const SKY74400_PLL_ELM*  elmptr;
/*SKY74400*/    int left, right, middle;
/*SKY74400*/    int div;
/*SKY74400*/
/*SKY74400*/   /*binary search*/
/*SKY74400*/   elmptr = SKY74400_TXPLL_TBL[rf_band];
/*SKY74400*/   left = 0; right = SKY74400_TXPLL_TBL_SIZE[rf_band];
/*SKY74400*/   while (left <= right)
/*SKY74400*/   {  middle = (left + right)/2;
/*SKY74400*/      if ( arfcn<(elmptr+middle)->arfcn )
/*SKY74400*/         right = middle - 1;
/*SKY74400*/      else
/*SKY74400*/         left = middle + 1;
/*SKY74400*/   }
/*SKY74400*/   elmptr = (elmptr+left-1);
/*SKY74400*/   Nfrac = elmptr->Fbase + (((arfcn-elmptr->arfcn)*elmptr->Fstep)>>5);
/*SKY74400*/   *rfN = (elmptr->Nint<<6) | 0xC40000;
/*SKY74400*/   *ifN = (Nfrac<<2) | 3;
/*SKY74400*/ //  *rfN = elmptr->Nint;
/*SKY74400*/ //  *ifN = Nfrac;
/*SKY74400*/
/*SKY74400*/   l1d_rf.next_inj = (elmptr->Inj_Div>>1)&0x01;
/*SKY74400*/   div = (elmptr->Inj_Div>>0)&0x01;
/*SKY74400*/   SKY74400_TxCtrl_Mask = SDATA_TX_Div_TABLE[div] | SDATA_TX_Inj_TABLE[l1d_rf.next_inj];
/*SKY74400*/   SKY74400_TxCtrl = SDATA_TX_TABLE[rf_band] | SDATA_TX_Div_TABLE[div] | SDATA_TX_Inj_TABLE[l1d_rf.next_inj];
/*SKY74400*/ }
/*SKY74400*/ /* =========================================================================== */
#endif

#if IS_RF_MT6119
/*MT6119*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6119*/ {  int   Nfrac;
/*MT6119*/
/*MT6119*/    switch(rf_band)
/*MT6119*/    {
/*MT6119*/       case  FrequencyBand900 :
/*MT6119*/       {
/*MT6119*/          if(arfcn<=70)
/*MT6119*/          {  if(arfcn<=5)                                /*  ARFCN :   0~5    */
/*MT6119*/             {  Nfrac = 80*(arfcn-0)+4760;
/*MT6119*/                *rfN = (7L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/             else                                        /*  ARFCN :  6~70    */
/*MT6119*/             {  Nfrac = 80*(arfcn-6)+40;
/*MT6119*/                *rfN = (8L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          else
/*MT6119*/          {  if(arfcn<=124)                              /*  ARFCN : 71~124   */
/*MT6119*/             {  Nfrac = 80*(arfcn-71)+40;
/*MT6119*/                *rfN = (9L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/             else
/*MT6119*/             {  Nfrac = 80*(arfcn-975)+840;              /*  ARFCN : 975~1023 */
/*MT6119*/                *rfN = (7L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          break;
/*MT6119*/       }
/*MT6119*/       case  FrequencyBand1800 :
/*MT6119*/       {
/*MT6119*/          if(arfcn<=716)
/*MT6119*/          {  if(arfcn<=586)                              /*  ARFCN : 512~586  */
/*MT6119*/             {  Nfrac = 40*(arfcn-512)+2220;
/*MT6119*/                *rfN = (5L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/             else                                        /*  ARFCN : 587~716  */
/*MT6119*/             {  Nfrac = 40*(arfcn-587)+20;
/*MT6119*/                *rfN = (6L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          else
/*MT6119*/          {  if(arfcn<=846)                              /*  ARFCN : 717~846  */
/*MT6119*/             {  Nfrac = 40*(arfcn-717)+20;
/*MT6119*/                *rfN = (7L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/             else                                        /*  ARFCN : 847~885  */
/*MT6119*/             {  Nfrac = 40*(arfcn-847)+20;
/*MT6119*/                *rfN = (8L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          break;
/*MT6119*/       }
/*MT6119*/       case  FrequencyBand1900 :
/*MT6119*/       {
/*MT6119*/          if(arfcn<=741)
/*MT6119*/          {  if(arfcn<=611)                              /*  ARFCN : 512~611  */
/*MT6119*/             {  Nfrac = 40*(arfcn-512)+1220;
/*MT6119*/                *rfN = (10L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/             else                                        /*  ARFCN : 612~741  */
/*MT6119*/             {  Nfrac = 40*(arfcn-612)+20;
/*MT6119*/                *rfN = (11L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          else
/*MT6119*/          {  Nfrac = 40*(arfcn-742)+20;                  /*  ARFCN : 742~810  */
/*MT6119*/             *rfN = (12L<<16) | (Nfrac<<3) | 1;
/*MT6119*/          }
/*MT6119*/          break;
/*MT6119*/       }
/*MT6119*/       default :
/*MT6119*/       {
/*MT6119*/          break;
/*MT6119*/       }
/*MT6119*/    }
/*MT6119*/    *ifN = 0;
/*MT6119*/ }
/*MT6119*/ /* =========================================================================== */
/*MT6119*/
/*MT6119*/ char mt6119_d_flag = 0;
/*MT6119*/
/*MT6119*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6119*/ {  int   Nfrac;
/*MT6119*/
/*MT6119*/    switch(rf_band)
/*MT6119*/    {
/*MT6119*/       case  FrequencyBand900 :
/*MT6119*/       {
/*MT6119*/          if(arfcn<=110)
/*MT6119*/          {  if(arfcn<=52)
/*MT6119*/             {  if(arfcn<=3)                     /* ARFCN : 0~3       */
/*MT6119*/                {  Nfrac = 88*(arfcn-0)+1600;
/*MT6119*/                   *rfN = (11L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                }
/*MT6119*/                else                             /* ARFCN : 4~52     */
/*MT6119*/                {  Nfrac = 90*(arfcn-4)+460;
/*MT6119*/                   *rfN = (13L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/             else
/*MT6119*/             {  if(arfcn<=61)                    /* ARFCN : 53~61     */
/*MT6119*/                {  Nfrac = 88*(arfcn-53)+1064;
/*MT6119*/                   *rfN = (12L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                }
/*MT6119*/                else                             /* ARFCN : 62~110    */
/*MT6119*/                {  Nfrac = 90*(arfcn-62)+480;
/*MT6119*/                   *rfN = (14L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          else
/*MT6119*/          {  if(arfcn<=124)
/*MT6119*/             {  if(arfcn<=118)                   /* ARFCN : 111~118   */
/*MT6119*/                {  Nfrac = 88*(arfcn-111)+968;
/*MT6119*/                   *rfN = (13L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                }
/*MT6119*/                else                             /* ARFCN : 119~124  */
/*MT6119*/                {  Nfrac = 90*(arfcn-119)+410;
/*MT6119*/                   *rfN = (15L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/             else
/*MT6119*/             {  if(arfcn<=1018)                  /* ARFCN : 975~1018 */
/*MT6119*/                {  Nfrac = 90*(arfcn-975)+890;
/*MT6119*/                   *rfN = (12L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/                else                             /* ARFCN : 1019~1023 */
/*MT6119*/                {  Nfrac = 88*(arfcn-1019)+1160;
/*MT6119*/                   *rfN = (11L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          break;
/*MT6119*/       }
/*MT6119*/       case  FrequencyBand1800 :
/*MT6119*/       {
/*MT6119*/          if(arfcn<=734)
/*MT6119*/          {  if(arfcn<=618)
/*MT6119*/             {  if(arfcn<=520)                   /* ARFCN : 512~520   */
/*MT6119*/                {  Nfrac = 44*(arfcn-512)+1844;
/*MT6119*/                   *rfN = (8L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                }
/*MT6119*/                else                             /* ARFCN : 521~618   */
/*MT6119*/                {  Nfrac = 45*(arfcn-521)+400;
/*MT6119*/                   *rfN = (10L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/             else
/*MT6119*/             {  if(arfcn<=636)                   /* ARFCN : 619~636   */
/*MT6119*/                {  Nfrac = 44*(arfcn-619)+1352;
/*MT6119*/                   *rfN = (9L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                }
/*MT6119*/                else                             /* ARFCN : 637~734   */
/*MT6119*/                {  Nfrac = 45*(arfcn-637)+420;
/*MT6119*/                   *rfN = (11L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          else
/*MT6119*/          {  if(arfcn<=849)
/*MT6119*/             {  if(arfcn<=752)                   /* ARFCN : 735~752   */
/*MT6119*/                {  Nfrac = 44*(arfcn-735)+1256;
/*MT6119*/                   *rfN = (10L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                }
/*MT6119*/                else                             /* ARFCN : 753~849   */
/*MT6119*/                {  Nfrac = 45*(arfcn-753)+440;
/*MT6119*/                   *rfN = (12L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/             else                                /* ARFCN : 850~867   */
/*MT6119*/             {  if(arfcn<=867)
/*MT6119*/                 {  Nfrac = 44*(arfcn-850)+1116;
/*MT6119*/                   *rfN = (11L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                }
/*MT6119*/                else                            /* ARFCN : 868~885   */
/*MT6119*/                {  Nfrac = 45*(arfcn-868)+415;
/*MT6119*/                   *rfN = (13L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          break;
/*MT6119*/       }
/*MT6119*/       case  FrequencyBand1900 :
/*MT6119*/       {
/*MT6119*/          if(arfcn<=727)
/*MT6119*/          {  if(arfcn<=612)
/*MT6119*/             {  if(arfcn<=514)                /* ARFCN : 512~514   */
/*MT6119*/                {  Nfrac = 44*(arfcn-512)+1444;
/*MT6119*/                   *rfN = (14L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                 }
/*MT6119*/                 else
/*MT6119*/                 {  Nfrac = 45*(arfcn-515)+430;  /* ARFCN : 515~612   */
/*MT6119*/                   *rfN = (16L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/             else
/*MT6119*/             {  if(arfcn<=629)                /* ARFCN : 613~629   */
/*MT6119*/                {  Nfrac = 44*(arfcn-613)+688;
/*MT6119*/                   *rfN = (15L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                 }
/*MT6119*/                 else
/*MT6119*/                 {  Nfrac = 45*(arfcn-630)+405;  /* ARFCN : 630~727   */
/*MT6119*/                   *rfN = (17L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          else
/*MT6119*/          {  if(arfcn<=745)                      /* ARFCN : 728~745   */
/*MT6119*/               {  Nfrac = 44*(arfcn-728)+548;
/*MT6119*/                *rfN = (16L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                mt6119_d_flag = 1;
/*MT6119*/             }
/*MT6119*/             else                                /* ARFCN : 746~810   */
/*MT6119*/             {  Nfrac = 45*(arfcn-746)+425;
/*MT6119*/                *rfN = (18L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                mt6119_d_flag = 0;
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          break;
/*MT6119*/       }
/*MT6119*/       default :
/*MT6119*/       {
/*MT6119*/          break;
/*MT6119*/       }
/*MT6119*/    }
/*MT6119*/    *ifN = 0;
/*MT6119*/ }
/*MT6119*/ /* =========================================================================== */
#endif

#if IS_RF_MT6119C
/*MT6119C*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6119C*/{  int   Nfrac;
/*MT6119C*/
/*MT6119C*/   switch(rf_band)
/*MT6119C*/   {
/*MT6119C*/      case  FrequencyBand900 :
/*MT6119C*/      {
/*MT6119C*/         if(arfcn<=70)
/*MT6119C*/         {  if(arfcn<=5)                                /*  ARFCN :   0~5    */
/*MT6119C*/            {  Nfrac = 80*(arfcn-0)+4760;
/*MT6119C*/               *rfN = (7L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/            else                                        /*  ARFCN :  6~70    */
/*MT6119C*/            {  Nfrac = 80*(arfcn-6)+40;
/*MT6119C*/               *rfN = (8L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         else
/*MT6119C*/         {  if(arfcn<=124)                              /*  ARFCN : 71~124   */
/*MT6119C*/            {  Nfrac = 80*(arfcn-71)+40;
/*MT6119C*/               *rfN = (9L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/            else
/*MT6119C*/            {  Nfrac = 80*(arfcn-975)+840;              /*  ARFCN : 975~1023 */
/*MT6119C*/               *rfN = (7L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         break;
/*MT6119C*/      }
/*MT6119C*/      case  FrequencyBand1800 :
/*MT6119C*/      {
/*MT6119C*/         if(arfcn<=716)
/*MT6119C*/         {  if(arfcn<=586)                              /*  ARFCN : 512~586  */
/*MT6119C*/            {  Nfrac = 40*(arfcn-512)+2220;
/*MT6119C*/               *rfN = (5L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/            else                                        /*  ARFCN : 587~716  */
/*MT6119C*/            {  Nfrac = 40*(arfcn-587)+20;
/*MT6119C*/               *rfN = (6L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         else
/*MT6119C*/         {  if(arfcn<=846)                              /*  ARFCN : 717~846  */
/*MT6119C*/            {  Nfrac = 40*(arfcn-717)+20;
/*MT6119C*/               *rfN = (7L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/            else                                        /*  ARFCN : 847~885  */
/*MT6119C*/            {  Nfrac = 40*(arfcn-847)+20;
/*MT6119C*/               *rfN = (8L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         break;
/*MT6119C*/      }
/*MT6119C*/      case  FrequencyBand1900 :
/*MT6119C*/      {
/*MT6119C*/         if(arfcn<=741)
/*MT6119C*/         {  if(arfcn<=611)                              /*  ARFCN : 512~611  */
/*MT6119C*/            {  Nfrac = 40*(arfcn-512)+1220;
/*MT6119C*/               *rfN = (10L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/            else                                        /*  ARFCN : 612~741  */
/*MT6119C*/            {  Nfrac = 40*(arfcn-612)+20;
/*MT6119C*/               *rfN = (11L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         else
/*MT6119C*/         {  Nfrac = 40*(arfcn-742)+20;                  /*  ARFCN : 742~810  */
/*MT6119C*/            *rfN = (12L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/         }
/*MT6119C*/         break;
/*MT6119C*/      }
/*MT6119C*/      default :
/*MT6119C*/      {
/*MT6119C*/         break;
/*MT6119C*/      }
/*MT6119C*/   }
/*MT6119C*/   *ifN = 0;
/*MT6119C*/}
/*MT6119C*//* =========================================================================== */
/*MT6119C*/
/*MT6119C*/char mt6119_d_flag = 0;
/*MT6119C*/
/*MT6119C*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6119C*/{  int   Nfrac;
/*MT6119C*/
/*MT6119C*/   switch(rf_band)
/*MT6119C*/   {
/*MT6119C*/      case  FrequencyBand900 :
/*MT6119C*/      {
/*MT6119C*/         if(arfcn<=104)
/*MT6119C*/         {  if(arfcn<=45)
/*MT6119C*/            {  if(arfcn<=36)                     /* ARFCN : 0~36       */
/*MT6119C*/               {  Nfrac = 88*(arfcn-0)+1600;
/*MT6119C*/                  *rfN = (11L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/               }
/*MT6119C*/               else                             /* ARFCN : 37~45     */
/*MT6119C*/               {  Nfrac = 90*(arfcn-37)+3430;
/*MT6119C*/                  *rfN = (13L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 0;
/*MT6119C*/               }
/*MT6119C*/            }
/*MT6119C*/            else
/*MT6119C*/            {  if(arfcn<=95)                    /* ARFCN : 46~95     */
/*MT6119C*/               {  Nfrac = 88*(arfcn-46)+448;
/*MT6119C*/                  *rfN = (12L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/               }
/*MT6119C*/               else                             /* ARFCN : 96~104    */
/*MT6119C*/               {  Nfrac = 90*(arfcn-96)+3540;
/*MT6119C*/                  *rfN = (14L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 0;
/*MT6119C*/               }
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         else
/*MT6119C*/         {  if(arfcn<=1001)
/*MT6119C*/            {  if(arfcn<=124)                   /* ARFCN : 105~124   */
/*MT6119C*/               {  Nfrac = 88*(arfcn-105)+440;
/*MT6119C*/                  *rfN = (13L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/               }
/*MT6119C*/               else                             /* ARFCN : 975~1001  */
/*MT6119C*/               {  Nfrac = 88*(arfcn-975)+2488;
/*MT6119C*/                  *rfN = (10L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/               }
/*MT6119C*/            }
/*MT6119C*/            else
/*MT6119C*/            {  if(arfcn<=1010)                  /* ARFCN : 1002~1010 */
/*MT6119C*/               {  Nfrac = 90*(arfcn-1002)+3320;
/*MT6119C*/                  *rfN = (12L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 0;
/*MT6119C*/               }
/*MT6119C*/               else                             /* ARFCN : 1011~1023 */
/*MT6119C*/               {  Nfrac = 88*(arfcn-1011)+456;
/*MT6119C*/                  *rfN = (11L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/               }
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         break;
/*MT6119C*/      }
/*MT6119C*/      case  FrequencyBand1800 :
/*MT6119C*/      {
/*MT6119C*/         if(arfcn<=715)
/*MT6119C*/         {  if(arfcn<=597)
/*MT6119C*/            {  if(arfcn<=579)                   /* ARFCN : 512~579   */
/*MT6119C*/               {  Nfrac = 44*(arfcn-512)+1844;
/*MT6119C*/                  *rfN = (8L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/               }
/*MT6119C*/               else                             /* ARFCN : 580~597   */
/*MT6119C*/               {  Nfrac = 45*(arfcn-580)+3055;
/*MT6119C*/                  *rfN = (10L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 0;
/*MT6119C*/               }
/*MT6119C*/            }
/*MT6119C*/            else
/*MT6119C*/            {  if(arfcn<=697)                   /* ARFCN : 598~697   */
/*MT6119C*/               {  Nfrac = 44*(arfcn-598)+428;
/*MT6119C*/                  *rfN = (9L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/               }
/*MT6119C*/               else                             /* ARFCN : 698~715   */
/*MT6119C*/               {  Nfrac = 45*(arfcn-698)+3165;
/*MT6119C*/                  *rfN = (11L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 0;
/*MT6119C*/               }
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         else
/*MT6119C*/         {  if(arfcn<=833)
/*MT6119C*/            {  if(arfcn<=815)                   /* ARFCN : 716~815   */
/*MT6119C*/               {  Nfrac = 44*(arfcn-716)+420;
/*MT6119C*/                  *rfN = (10L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/               }
/*MT6119C*/               else                             /* ARFCN : 816~833   */
/*MT6119C*/               {  Nfrac = 45*(arfcn-816)+3275;
/*MT6119C*/                  *rfN = (12L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 0;
/*MT6119C*/               }
/*MT6119C*/            }
/*MT6119C*/            else                                /* ARFCN : 834~885   */
/*MT6119C*/            {  Nfrac = 44*(arfcn-834)+412;
/*MT6119C*/               *rfN = (11L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/               mt6119_d_flag = 1;
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         break;
/*MT6119C*/      }
/*MT6119C*/      case  FrequencyBand1900 :
/*MT6119C*/      {
/*MT6119C*/         if(arfcn<=706)
/*MT6119C*/         {  if(arfcn<=606)
/*MT6119C*/            {  if(arfcn<=588)                /* ARFCN : 512~588   */
/*MT6119C*/               {  Nfrac = 44*(arfcn-512)+1444;
/*MT6119C*/                  *rfN = (14L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/              }
/*MT6119C*/              else
/*MT6119C*/              {  Nfrac = 45*(arfcn-589)+3760;  /* ARFCN : 589~606   */
/*MT6119C*/                  *rfN = (16L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 0;
/*MT6119C*/               }
/*MT6119C*/            }
/*MT6119C*/            else                                /* ARFCN : 607~706   */
/*MT6119C*/            {  Nfrac = 44*(arfcn-607)+424;
/*MT6119C*/               *rfN = (15L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/               mt6119_d_flag = 1;
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         else
/*MT6119C*/         {  if(arfcn<=724)                      /* ARFCN : 707~724   */
/*MT6119C*/              {  Nfrac = 45*(arfcn-707)+3870;
/*MT6119C*/               *rfN = (17L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/               mt6119_d_flag = 0;
/*MT6119C*/            }
/*MT6119C*/            else                                /* ARFCN : 725~810   */
/*MT6119C*/            {  Nfrac = 44*(arfcn-725)+416;
/*MT6119C*/               *rfN = (16L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/               mt6119_d_flag = 1;
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         break;
/*MT6119C*/      }
/*MT6119C*/      default :
/*MT6119C*/      {
/*MT6119C*/         break;
/*MT6119C*/      }
/*MT6119C*/   }
/*MT6119C*/   *ifN = 0;
/*MT6119C*/}
/*MT6119C*//* =========================================================================== */
#endif

#if IS_RF_MT6129A
/*MT6129A*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6129A*/{  int   Nfrac;
/*MT6129A*/
/*MT6129A*/   switch(rf_band)
/*MT6129A*/   {
/*MT6129A*/      case  FrequencyBand900 :
/*MT6129A*/      {
/*MT6129A*/         if(arfcn<=70)
/*MT6129A*/         {  if(arfcn<=5)                                /*  ARFCN :   0~5    */
/*MT6129A*/            {  Nfrac = 80*(arfcn-0)+4760;
/*MT6129A*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/            else                                        /*  ARFCN :  6~70    */
/*MT6129A*/            {  Nfrac = 80*(arfcn-6)+40;
/*MT6129A*/               *rfN = (8L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         else
/*MT6129A*/         {  if(arfcn<=124)                              /*  ARFCN : 71~124   */
/*MT6129A*/            {  Nfrac = 80*(arfcn-71)+40;
/*MT6129A*/               *rfN = (9L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/            else
/*MT6129A*/            {  Nfrac = 80*(arfcn-975)+840;              /*  ARFCN : 975~1023 */
/*MT6129A*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         break;
/*MT6129A*/      }
/*MT6129A*/      case  FrequencyBand1800 :
/*MT6129A*/      {
/*MT6129A*/         if(arfcn<=716)
/*MT6129A*/         {  if(arfcn<=586)                              /*  ARFCN : 512~586  */
/*MT6129A*/            {  Nfrac = 40*(arfcn-512)+2220;
/*MT6129A*/               *rfN = (5L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/            else                                        /*  ARFCN : 587~716  */
/*MT6129A*/            {  Nfrac = 40*(arfcn-587)+20;
/*MT6129A*/               *rfN = (6L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         else
/*MT6129A*/         {  if(arfcn<=846)                              /*  ARFCN : 717~846  */
/*MT6129A*/            {  Nfrac = 40*(arfcn-717)+20;
/*MT6129A*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/            else                                        /*  ARFCN : 847~885  */
/*MT6129A*/            {  Nfrac = 40*(arfcn-847)+20;
/*MT6129A*/               *rfN = (8L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         break;
/*MT6129A*/      }
/*MT6129A*/      case  FrequencyBand1900 :
/*MT6129A*/      {
/*MT6129A*/         if(arfcn<=741)
/*MT6129A*/         {  if(arfcn<=611)                              /*  ARFCN : 512~611  */
/*MT6129A*/            {  Nfrac = 40*(arfcn-512)+1220;
/*MT6129A*/               *rfN = (10L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/            else                                        /*  ARFCN : 612~741  */
/*MT6129A*/            {  Nfrac = 40*(arfcn-612)+20;
/*MT6129A*/               *rfN = (11L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         else
/*MT6129A*/         {  Nfrac = 40*(arfcn-742)+20;                  /*  ARFCN : 742~810  */
/*MT6129A*/            *rfN = (12L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/         }
/*MT6129A*/         break;
/*MT6129A*/      }
/*MT6129A*/      default :
/*MT6129A*/      {
/*MT6129A*/         break;
/*MT6129A*/      }
/*MT6129A*/   }
/*MT6129A*/   *ifN = 0;
/*MT6129A*/}
/*MT6129A*//* =========================================================================== */
/*MT6129A*/
/*MT6129A*/char mt6119_d_flag = 0;
/*MT6129A*/
/*MT6129A*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6129A*/{  int   Nfrac;
/*MT6129A*/
/*MT6129A*/   switch(rf_band)
/*MT6129A*/   {
/*MT6129A*/      case  FrequencyBand900 :
/*MT6129A*/      {
/*MT6129A*/         if(arfcn<=104)
/*MT6129A*/         {  if(arfcn<=45)
/*MT6129A*/            {  if(arfcn<=36)                     /* ARFCN : 0~36       */
/*MT6129A*/               {  Nfrac = 88*(arfcn-0)+1600;
/*MT6129A*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/               }
/*MT6129A*/               else                             /* ARFCN : 37~45     */
/*MT6129A*/               {  Nfrac = 90*(arfcn-37)+3430;
/*MT6129A*/                  *rfN = (13L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 0;
/*MT6129A*/               }
/*MT6129A*/            }
/*MT6129A*/            else
/*MT6129A*/            {  if(arfcn<=95)                    /* ARFCN : 46~95     */
/*MT6129A*/               {  Nfrac = 88*(arfcn-46)+448;
/*MT6129A*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/               }
/*MT6129A*/               else                             /* ARFCN : 96~104    */
/*MT6129A*/               {  Nfrac = 90*(arfcn-96)+3540;
/*MT6129A*/                  *rfN = (14L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 0;
/*MT6129A*/               }
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         else
/*MT6129A*/         {  if(arfcn<=1001)
/*MT6129A*/            {  if(arfcn<=124)                   /* ARFCN : 105~124   */
/*MT6129A*/               {  Nfrac = 88*(arfcn-105)+440;
/*MT6129A*/                  *rfN = (13L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/               }
/*MT6129A*/               else                             /* ARFCN : 975~1001  */
/*MT6129A*/               {  Nfrac = 88*(arfcn-975)+2488;
/*MT6129A*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/               }
/*MT6129A*/            }
/*MT6129A*/            else
/*MT6129A*/            {  if(arfcn<=1010)                  /* ARFCN : 1002~1010 */
/*MT6129A*/               {  Nfrac = 90*(arfcn-1002)+3320;
/*MT6129A*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 0;
/*MT6129A*/               }
/*MT6129A*/               else                             /* ARFCN : 1011~1023 */
/*MT6129A*/               {  Nfrac = 88*(arfcn-1011)+456;
/*MT6129A*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/               }
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         break;
/*MT6129A*/      }
/*MT6129A*/      case  FrequencyBand1800 :
/*MT6129A*/      {
/*MT6129A*/         if(arfcn<=715)
/*MT6129A*/         {  if(arfcn<=597)
/*MT6129A*/            {  if(arfcn<=579)                   /* ARFCN : 512~579   */
/*MT6129A*/               {  Nfrac = 44*(arfcn-512)+1844;
/*MT6129A*/                  *rfN = (8L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/               }
/*MT6129A*/               else                             /* ARFCN : 580~597   */
/*MT6129A*/               {  Nfrac = 45*(arfcn-580)+3055;
/*MT6129A*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 0;
/*MT6129A*/               }
/*MT6129A*/            }
/*MT6129A*/            else
/*MT6129A*/            {  if(arfcn<=697)                   /* ARFCN : 598~697   */
/*MT6129A*/               {  Nfrac = 44*(arfcn-598)+428;
/*MT6129A*/                  *rfN = (9L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/               }
/*MT6129A*/               else                             /* ARFCN : 698~715   */
/*MT6129A*/               {  Nfrac = 45*(arfcn-698)+3165;
/*MT6129A*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 0;
/*MT6129A*/               }
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         else
/*MT6129A*/         {  if(arfcn<=833)
/*MT6129A*/            {  if(arfcn<=815)                   /* ARFCN : 716~815   */
/*MT6129A*/               {  Nfrac = 44*(arfcn-716)+420;
/*MT6129A*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/               }
/*MT6129A*/               else                             /* ARFCN : 816~833   */
/*MT6129A*/               {  Nfrac = 45*(arfcn-816)+3275;
/*MT6129A*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 0;
/*MT6129A*/               }
/*MT6129A*/            }
/*MT6129A*/            else                                /* ARFCN : 834~885   */
/*MT6129A*/            {  Nfrac = 44*(arfcn-834)+412;
/*MT6129A*/               *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/               mt6119_d_flag = 1;
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         break;
/*MT6129A*/      }
/*MT6129A*/      case  FrequencyBand1900 :
/*MT6129A*/      {
/*MT6129A*/         if(arfcn<=706)
/*MT6129A*/         {  if(arfcn<=606)
/*MT6129A*/            {  if(arfcn<=588)                /* ARFCN : 512~588   */
/*MT6129A*/               {  Nfrac = 44*(arfcn-512)+1444;
/*MT6129A*/                  *rfN = (14L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/              }
/*MT6129A*/              else
/*MT6129A*/              {  Nfrac = 45*(arfcn-589)+3760;  /* ARFCN : 589~606   */
/*MT6129A*/                  *rfN = (16L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 0;
/*MT6129A*/               }
/*MT6129A*/            }
/*MT6129A*/            else                                /* ARFCN : 607~706   */
/*MT6129A*/            {  Nfrac = 44*(arfcn-607)+424;
/*MT6129A*/               *rfN = (15L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/               mt6119_d_flag = 1;
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         else
/*MT6129A*/         {  if(arfcn<=724)                      /* ARFCN : 707~724   */
/*MT6129A*/              {  Nfrac = 45*(arfcn-707)+3870;
/*MT6129A*/               *rfN = (17L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/               mt6119_d_flag = 0;
/*MT6129A*/            }
/*MT6129A*/            else                                /* ARFCN : 725~810   */
/*MT6129A*/            {  Nfrac = 44*(arfcn-725)+416;
/*MT6129A*/               *rfN = (16L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/               mt6119_d_flag = 1;
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         break;
/*MT6129A*/      }
/*MT6129A*/      default :
/*MT6129A*/      {
/*MT6129A*/         break;
/*MT6129A*/      }
/*MT6129A*/   }
/*MT6129A*/   *ifN = 0;
/*MT6129A*/}
/*MT6129A*//* =========================================================================== */
#endif

#if IS_RF_MT6129B
/*MT6129B*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6129B*/{  int   Nfrac;
/*MT6129B*/
/*MT6129B*/   switch(rf_band)
/*MT6129B*/   {
/*MT6129B*/      case  FrequencyBand850 :
/*MT6129B*/      {
/*MT6129B*/         if(arfcn<=202)
/*MT6129B*/         {  if(arfcn<=137)                              /*  ARFCN :  128~137    */
/*MT6129B*/            {  Nfrac = 80*(arfcn-128)+4440;
/*MT6129B*/               *rfN = (2L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/            else                                        /*  ARFCN :  138~202    */
/*MT6129B*/            {  Nfrac = 80*(arfcn-138)+40;
/*MT6129B*/               *rfN = (3L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         else
/*MT6129B*/         {                                             /*  ARFCN :  203~251   */
/*MT6129B*/               Nfrac = 80*(arfcn-203)+40;
/*MT6129B*/               *rfN = (4L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/         }
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/      case  FrequencyBand900 :
/*MT6129B*/      {
/*MT6129B*/         if(arfcn<=70)
/*MT6129B*/         {  if(arfcn<=5)                                /*  ARFCN :   0~5    */
/*MT6129B*/            {  Nfrac = 80*(arfcn-0)+4760;
/*MT6129B*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/            else                                        /*  ARFCN :  6~70    */
/*MT6129B*/            {  Nfrac = 80*(arfcn-6)+40;
/*MT6129B*/               *rfN = (8L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         else
/*MT6129B*/         {  if(arfcn<=124)                              /*  ARFCN : 71~124   */
/*MT6129B*/            {  Nfrac = 80*(arfcn-71)+40;
/*MT6129B*/               *rfN = (9L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/            else
/*MT6129B*/            {  Nfrac = 80*(arfcn-975)+840;              /*  ARFCN : 975~1023 */
/*MT6129B*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/      case  FrequencyBand1800 :
/*MT6129B*/      {
/*MT6129B*/         if(arfcn<=716)
/*MT6129B*/         {  if(arfcn<=586)                              /*  ARFCN : 512~586  */
/*MT6129B*/            {  Nfrac = 40*(arfcn-512)+2220;
/*MT6129B*/               *rfN = (5L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/            else                                        /*  ARFCN : 587~716  */
/*MT6129B*/            {  Nfrac = 40*(arfcn-587)+20;
/*MT6129B*/               *rfN = (6L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         else
/*MT6129B*/         {  if(arfcn<=846)                              /*  ARFCN : 717~846  */
/*MT6129B*/            {  Nfrac = 40*(arfcn-717)+20;
/*MT6129B*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/            else                                        /*  ARFCN : 847~885  */
/*MT6129B*/            {  Nfrac = 40*(arfcn-847)+20;
/*MT6129B*/               *rfN = (8L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/      case  FrequencyBand1900 :
/*MT6129B*/      {
/*MT6129B*/         if(arfcn<=741)
/*MT6129B*/         {  if(arfcn<=611)                              /*  ARFCN : 512~611  */
/*MT6129B*/            {  Nfrac = 40*(arfcn-512)+1220;
/*MT6129B*/               *rfN = (10L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/            else                                        /*  ARFCN : 612~741  */
/*MT6129B*/            {  Nfrac = 40*(arfcn-612)+20;
/*MT6129B*/               *rfN = (11L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         else
/*MT6129B*/         {  Nfrac = 40*(arfcn-742)+20;                  /*  ARFCN : 742~810  */
/*MT6129B*/            *rfN = (12L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/         }
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/      default :
/*MT6129B*/      {
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/   }
/*MT6129B*/   *ifN = 0;
/*MT6129B*/}
/*MT6129B*//* =========================================================================== */
/*MT6129B*/
/*MT6129B*/char mt6119_d_flag = 0;
/*MT6129B*/
/*MT6129B*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6129B*/{  int   Nfrac;
/*MT6129B*/
/*MT6129B*/   switch(rf_band)
/*MT6129B*/   {
/*MT6129B*/      case  FrequencyBand850 :
/*MT6129B*/      {
/*MT6129B*/         if(arfcn<=197)
/*MT6129B*/         {  if(arfcn<=147)
/*MT6129B*/            {  if(arfcn<=138)
/*MT6129B*/               {                                /* ARFCN : 128~138     */
/*MT6129B*/                  Nfrac = 88*(arfcn-128)+3848;
/*MT6129B*/                  *rfN = (5L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/               else
/*MT6129B*/               {                                /* ARFCN : 139~147     */
/*MT6129B*/                  Nfrac = 90*(arfcn-139)+2680;
/*MT6129B*/                  *rfN = (7L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/            else
/*MT6129B*/            {                                   /* ARFCN : 148~197     */
/*MT6129B*/                  Nfrac = 88*(arfcn-148)+408;
/*MT6129B*/                  *rfN = (6L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         else
/*MT6129B*/         {  if(arfcn<=206)
/*MT6129B*/            {                                   /* ARFCN : 198~206   */
/*MT6129B*/                  Nfrac = 90*(arfcn-198)+2790;
/*MT6129B*/                  *rfN = (8L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/            }
/*MT6129B*/            else
/*MT6129B*/            {                                   /* ARFCN : 207~251 */
/*MT6129B*/                  Nfrac = 88*(arfcn-207)+400;
/*MT6129B*/                  *rfN = (7L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/      case  FrequencyBand900 :
/*MT6129B*/      {
/*MT6129B*/         if(arfcn<=104)
/*MT6129B*/         {  if(arfcn<=45)
/*MT6129B*/            {  if(arfcn<=36)                     /* ARFCN : 0~36       */
/*MT6129B*/               {  Nfrac = 88*(arfcn-0)+1600;
/*MT6129B*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/               else                             /* ARFCN : 37~45     */
/*MT6129B*/               {  Nfrac = 90*(arfcn-37)+3430;
/*MT6129B*/                  *rfN = (13L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/            else
/*MT6129B*/            {  if(arfcn<=95)                    /* ARFCN : 46~95     */
/*MT6129B*/               {  Nfrac = 88*(arfcn-46)+448;
/*MT6129B*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/               else                             /* ARFCN : 96~104    */
/*MT6129B*/               {  Nfrac = 90*(arfcn-96)+3540;
/*MT6129B*/                  *rfN = (14L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         else
/*MT6129B*/         {  if(arfcn<=1001)
/*MT6129B*/            {  if(arfcn<=124)                   /* ARFCN : 105~124   */
/*MT6129B*/               {  Nfrac = 88*(arfcn-105)+440;
/*MT6129B*/                  *rfN = (13L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/               else                             /* ARFCN : 975~1001  */
/*MT6129B*/               {  Nfrac = 88*(arfcn-975)+2488;
/*MT6129B*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/            else
/*MT6129B*/            {  if(arfcn<=1010)                  /* ARFCN : 1002~1010 */
/*MT6129B*/               {  Nfrac = 90*(arfcn-1002)+3320;
/*MT6129B*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/               }
/*MT6129B*/               else                             /* ARFCN : 1011~1023 */
/*MT6129B*/               {  Nfrac = 88*(arfcn-1011)+456;
/*MT6129B*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/      case  FrequencyBand1800 :
/*MT6129B*/      {
/*MT6129B*/         if(arfcn<=715)
/*MT6129B*/         {  if(arfcn<=597)
/*MT6129B*/            {  if(arfcn<=579)                   /* ARFCN : 512~579   */
/*MT6129B*/               {  Nfrac = 44*(arfcn-512)+1844;
/*MT6129B*/                  *rfN = (8L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/               else                             /* ARFCN : 580~597   */
/*MT6129B*/               {  Nfrac = 45*(arfcn-580)+3055;
/*MT6129B*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/            else
/*MT6129B*/            {  if(arfcn<=697)                   /* ARFCN : 598~697   */
/*MT6129B*/               {  Nfrac = 44*(arfcn-598)+428;
/*MT6129B*/                  *rfN = (9L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/               else                             /* ARFCN : 698~715   */
/*MT6129B*/               {  Nfrac = 45*(arfcn-698)+3165;
/*MT6129B*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         else
/*MT6129B*/         {  if(arfcn<=833)
/*MT6129B*/            {  if(arfcn<=815)                   /* ARFCN : 716~815   */
/*MT6129B*/               {  Nfrac = 44*(arfcn-716)+420;
/*MT6129B*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/               else                             /* ARFCN : 816~833   */
/*MT6129B*/               {  Nfrac = 45*(arfcn-816)+3275;
/*MT6129B*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/            else                                /* ARFCN : 834~885   */
/*MT6129B*/            {  Nfrac = 44*(arfcn-834)+412;
/*MT6129B*/               *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/               mt6119_d_flag = 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/      case  FrequencyBand1900 :
/*MT6129B*/      {
/*MT6129B*/         if(arfcn<=706)
/*MT6129B*/         {  if(arfcn<=606)
/*MT6129B*/            {  if(arfcn<=588)                /* ARFCN : 512~588   */
/*MT6129B*/               {  Nfrac = 44*(arfcn-512)+1444;
/*MT6129B*/                  *rfN = (14L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/              }
/*MT6129B*/              else
/*MT6129B*/              {  Nfrac = 45*(arfcn-589)+3760;  /* ARFCN : 589~606   */
/*MT6129B*/                  *rfN = (16L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/            else                                /* ARFCN : 607~706   */
/*MT6129B*/            {  Nfrac = 44*(arfcn-607)+424;
/*MT6129B*/               *rfN = (15L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/               mt6119_d_flag = 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         else
/*MT6129B*/         {  if(arfcn<=724)                      /* ARFCN : 707~724   */
/*MT6129B*/              {  Nfrac = 45*(arfcn-707)+3870;
/*MT6129B*/               *rfN = (17L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/               mt6119_d_flag = 0;
/*MT6129B*/            }
/*MT6129B*/            else                                /* ARFCN : 725~810   */
/*MT6129B*/            {  Nfrac = 44*(arfcn-725)+416;
/*MT6129B*/               *rfN = (16L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/               mt6119_d_flag = 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/      default :
/*MT6129B*/      {
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/   }
/*MT6129B*/   *ifN = 0;
/*MT6129B*/}
/*MT6129B*//* =========================================================================== */
#endif

#if  (IS_RF_MT6129C)||(IS_RF_MT6129D)
/*MT6129C,D*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6129C,D*/{  int   Nfrac;
/*MT6129C,D*/
/*MT6129C,D*/   switch(rf_band)
/*MT6129C,D*/   {
/*MT6129C,D*/      case  FrequencyBand850 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=202)
/*MT6129C,D*/         {  if(arfcn<=137)                              /*  ARFCN :  128~137    */
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-128)+4440;
/*MT6129C,D*/               *rfN = (2L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                        /*  ARFCN :  138~202    */
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-138)+40;
/*MT6129C,D*/               *rfN = (3L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {                                             /*  ARFCN :  203~251   */
/*MT6129C,D*/               Nfrac = 80*(arfcn-203)+40;
/*MT6129C,D*/               *rfN = (4L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand900 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=70)
/*MT6129C,D*/         {  if(arfcn<=5)                                /*  ARFCN :   0~5    */
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-0)+4760;
/*MT6129C,D*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                        /*  ARFCN :  6~70    */
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-6)+40;
/*MT6129C,D*/               *rfN = (8L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=124)                              /*  ARFCN : 71~124   */
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-71)+40;
/*MT6129C,D*/               *rfN = (9L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-975)+840;              /*  ARFCN : 975~1023 */
/*MT6129C,D*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand1800 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=716)
/*MT6129C,D*/         {  if(arfcn<=586)                              /*  ARFCN : 512~586  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-512)+2220;
/*MT6129C,D*/               *rfN = (5L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                        /*  ARFCN : 587~716  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-587)+20;
/*MT6129C,D*/               *rfN = (6L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=846)                              /*  ARFCN : 717~846  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-717)+20;
/*MT6129C,D*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                        /*  ARFCN : 847~885  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-847)+20;
/*MT6129C,D*/               *rfN = (8L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand1900 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=741)
/*MT6129C,D*/         {  if(arfcn<=611)                              /*  ARFCN : 512~611  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-512)+1220;
/*MT6129C,D*/               *rfN = (10L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                        /*  ARFCN : 612~741  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-612)+20;
/*MT6129C,D*/               *rfN = (11L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  Nfrac = 40*(arfcn-742)+20;                  /*  ARFCN : 742~810  */
/*MT6129C,D*/            *rfN = (12L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      default :
/*MT6129C,D*/      {
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/   }
/*MT6129C,D*/   *ifN = 0;
/*MT6129C,D*/}
/*MT6129C,D*//* =========================================================================== */
/*MT6129C,D*/
/*MT6129C,D*/char mt6119_d_flag = 0;
/*MT6129C,D*/
/*MT6129C,D*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6129C,D*/{  int   Nfrac;
/*MT6129C,D*/
/*MT6129C,D*/   switch(rf_band)
/*MT6129C,D*/   {
/*MT6129C,D*/      case  FrequencyBand850 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=197)
/*MT6129C,D*/         {  if(arfcn<=147)
/*MT6129C,D*/            {  if(arfcn<=138)
/*MT6129C,D*/               {                                /* ARFCN : 128~138     */
/*MT6129C,D*/                  Nfrac = 88*(arfcn-128)+3848;
/*MT6129C,D*/                  *rfN = (5L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else
/*MT6129C,D*/               {                                /* ARFCN : 139~147     */
/*MT6129C,D*/                  Nfrac = 90*(arfcn-139)+2680;
/*MT6129C,D*/                  *rfN = (7L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {                                   /* ARFCN : 148~197     */
/*MT6129C,D*/                  Nfrac = 88*(arfcn-148)+408;
/*MT6129C,D*/                  *rfN = (6L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=206)
/*MT6129C,D*/            {                                   /* ARFCN : 198~206   */
/*MT6129C,D*/                  Nfrac = 90*(arfcn-198)+2790;
/*MT6129C,D*/                  *rfN = (8L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {                                   /* ARFCN : 207~251 */
/*MT6129C,D*/                  Nfrac = 88*(arfcn-207)+400;
/*MT6129C,D*/                  *rfN = (7L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand900 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=104)
/*MT6129C,D*/         {  if(arfcn<=45)
/*MT6129C,D*/            {  if(arfcn<=36)                     /* ARFCN : 0~36       */
/*MT6129C,D*/               {  Nfrac = 88*(arfcn-0)+1600;
/*MT6129C,D*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 37~45     */
/*MT6129C,D*/               {  Nfrac = 90*(arfcn-37)+3430;
/*MT6129C,D*/                  *rfN = (13L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {  if(arfcn<=95)                    /* ARFCN : 46~95     */
/*MT6129C,D*/               {  Nfrac = 88*(arfcn-46)+448;
/*MT6129C,D*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 96~104    */
/*MT6129C,D*/               {  Nfrac = 90*(arfcn-96)+3540;
/*MT6129C,D*/                  *rfN = (14L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=1001)
/*MT6129C,D*/            {  if(arfcn<=124)                   /* ARFCN : 105~124   */
/*MT6129C,D*/               {  Nfrac = 88*(arfcn-105)+440;
/*MT6129C,D*/                  *rfN = (13L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 975~1001  */
/*MT6129C,D*/               {  Nfrac = 88*(arfcn-975)+2488;
/*MT6129C,D*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {  if(arfcn<=1010)                  /* ARFCN : 1002~1010 */
/*MT6129C,D*/               {  Nfrac = 90*(arfcn-1002)+3320;
/*MT6129C,D*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 1011~1023 */
/*MT6129C,D*/               {  Nfrac = 88*(arfcn-1011)+456;
/*MT6129C,D*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand1800 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=715)
/*MT6129C,D*/         {  if(arfcn<=597)
/*MT6129C,D*/            {  if(arfcn<=579)                   /* ARFCN : 512~579   */
/*MT6129C,D*/               {  Nfrac = 44*(arfcn-512)+1844;
/*MT6129C,D*/                  *rfN = (8L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 580~597   */
/*MT6129C,D*/               {  Nfrac = 45*(arfcn-580)+3055;
/*MT6129C,D*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {  if(arfcn<=697)                   /* ARFCN : 598~697   */
/*MT6129C,D*/               {  Nfrac = 44*(arfcn-598)+428;
/*MT6129C,D*/                  *rfN = (9L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 698~715   */
/*MT6129C,D*/               {  Nfrac = 45*(arfcn-698)+3165;
/*MT6129C,D*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=833)
/*MT6129C,D*/            {  if(arfcn<=815)                   /* ARFCN : 716~815   */
/*MT6129C,D*/               {  Nfrac = 44*(arfcn-716)+420;
/*MT6129C,D*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 816~833   */
/*MT6129C,D*/               {  Nfrac = 45*(arfcn-816)+3275;
/*MT6129C,D*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                /* ARFCN : 834~885   */
/*MT6129C,D*/            {  Nfrac = 44*(arfcn-834)+412;
/*MT6129C,D*/               *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/               mt6119_d_flag = 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand1900 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=706)
/*MT6129C,D*/         {  if(arfcn<=606)
/*MT6129C,D*/            {  if(arfcn<=588)                /* ARFCN : 512~588   */
/*MT6129C,D*/               {  Nfrac = 44*(arfcn-512)+1444;
/*MT6129C,D*/                  *rfN = (14L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/              }
/*MT6129C,D*/              else
/*MT6129C,D*/              {  Nfrac = 45*(arfcn-589)+3760;  /* ARFCN : 589~606   */
/*MT6129C,D*/                  *rfN = (16L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                /* ARFCN : 607~706   */
/*MT6129C,D*/            {  Nfrac = 44*(arfcn-607)+424;
/*MT6129C,D*/               *rfN = (15L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/               mt6119_d_flag = 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=724)                      /* ARFCN : 707~724   */
/*MT6129C,D*/              {  Nfrac = 45*(arfcn-707)+3870;
/*MT6129C,D*/               *rfN = (17L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/               mt6119_d_flag = 0;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                /* ARFCN : 725~810   */
/*MT6129C,D*/            {  Nfrac = 44*(arfcn-725)+416;
/*MT6129C,D*/               *rfN = (16L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/               mt6119_d_flag = 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      default :
/*MT6129C,D*/      {
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/   }
/*MT6129C,D*/   *ifN = 0;
/*MT6129C,D*/}
/*MT6129C,D*//* =========================================================================== */
#endif

#if  (IS_RF_MT6139B)
/*MT6139B*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6139B*/{
/*MT6139B*/   switch(rf_band)
/*MT6139B*/   {
/*MT6139B*/      case  FrequencyBand850 :
/*MT6139B*/      {
/*MT6139B*/         if(arfcn<=201)
/*MT6139B*/         {  if(arfcn<=136)
/*MT6139B*/            {                                /* ARFCN : 128~136     */
/*MT6139B*/             //   Nfrac = (arfcn-128)<<1+112;
/*MT6139B*/             //   *rfN = (66L<<12) | (Nfrac<<4) | 0x00001L;
/*MT6139B*/                *rfN = (66L<<12) | ((arfcn-72)<<5) | 0x000001L;
/*MT6139B*/            }
/*MT6139B*/            else
/*MT6139B*/            {                              /* ARFCN : 137~201     */
/*MT6139B*/                *rfN = (67L<<12) | ((arfcn-137)<<5) | 0x000001L;
/*MT6139B*/            }
/*MT6139B*/         }
/*MT6139B*/         else
/*MT6139B*/         {                                 /* ARFCN : 202~251     */
/*MT6139B*/                *rfN = (68L<<12) | ((arfcn-202)<<5) | 0x000001L;
/*MT6139B*/         }
/*MT6139B*/
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/      case  FrequencyBand900 :
/*MT6139B*/      {
/*MT6139B*/         if(arfcn<=69)
/*MT6139B*/         {  if(arfcn<=4)
/*MT6139B*/            {                                /* ARFCN : 0~4     */
/*MT6139B*/                *rfN = (71L<<12) | ((arfcn+60)<<5) | 0x100001L;
/*MT6139B*/            }
/*MT6139B*/            else
/*MT6139B*/            {                              /* ARFCN : 5~69     */
/*MT6139B*/                *rfN = (72L<<12) | ((arfcn-5)<<5) | 0x100001L;
/*MT6139B*/            }
/*MT6139B*/         }
/*MT6139B*/         else
/*MT6139B*/         {  if(arfcn<=124)
/*MT6139B*/            {                                /* ARFCN : 70~124     */
/*MT6139B*/                *rfN = (73L<<12) | ((arfcn-70)<<5) | 0x100001L;
/*MT6139B*/            }
/*MT6139B*/            else
/*MT6139B*/            {                              /* ARFCN : 975~1023     */
/*MT6139B*/                *rfN = (71L<<12) | ((arfcn-964)<<5) | 0x100001L;
/*MT6139B*/            }
/*MT6139B*/         }
/*MT6139B*/
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/      case  FrequencyBand1800 :
/*MT6139B*/      {
/*MT6139B*/         if(arfcn<=715)
/*MT6139B*/         {  if(arfcn<=585)
/*MT6139B*/            {                                /* ARFCN : 512~585     */
/*MT6139B*/                *rfN = (69L<<12) | ((arfcn-456)<<4) | 0x200001L;
/*MT6139B*/            }
/*MT6139B*/            else
/*MT6139B*/            {                              /* ARFCN : 586~715     */
/*MT6139B*/                *rfN = (70L<<12) | ((arfcn-586)<<4) | 0x200001L;
/*MT6139B*/            }
/*MT6139B*/         }
/*MT6139B*/         else
/*MT6139B*/         {  if(arfcn<=845)
/*MT6139B*/            {                                /* ARFCN : 716~845     */
/*MT6139B*/                *rfN = (71L<<12) | ((arfcn-716)<<4) | 0x200001L;
/*MT6139B*/            }
/*MT6139B*/            else
/*MT6139B*/            {                              /* ARFCN : 846~885     */
/*MT6139B*/                *rfN = (72L<<12) | ((arfcn-846)<<4) | 0x200001L;
/*MT6139B*/            }
/*MT6139B*/         }
/*MT6139B*/
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/      case  FrequencyBand1900 :
/*MT6139B*/      {
/*MT6139B*/         if(arfcn<=740)
/*MT6139B*/         {  if(arfcn<=610)
/*MT6139B*/            {                                /* ARFCN : 512~610     */
/*MT6139B*/                *rfN = (74L<<12) | ((arfcn-481)<<4) | 0x300001L;
/*MT6139B*/            }
/*MT6139B*/            else
/*MT6139B*/            {                               /* ARFCN : 611~740     */
/*MT6139B*/                *rfN = (75L<<12) | ((arfcn-611)<<4) | 0x300001L;
/*MT6139B*/            }
/*MT6139B*/         }
/*MT6139B*/         else
/*MT6139B*/         {
/*MT6139B*/                                            /* ARFCN : 741~810     */
/*MT6139B*/            *rfN = (76L<<12) | ((arfcn-741)<<4) | 0x300001L;
/*MT6139B*/
/*MT6139B*/         }
/*MT6139B*/
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/      default :
/*MT6139B*/      {
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/   }
/*MT6139B*/   *ifN = 0;
/*MT6139B*/}
/*MT6139B*//* =========================================================================== */
/*MT6139B*/
/*MT6139B*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6139B*/{
/*MT6139B*/   switch(rf_band)
/*MT6139B*/   {
/*MT6139B*/      case  FrequencyBand850 :
/*MT6139B*/      {
/*MT6139B*/         if(arfcn<=231)
/*MT6139B*/         {  if(arfcn<=166)
/*MT6139B*/            {                                /* ARFCN : 128~166     */
/*MT6139B*/             //   Nfrac = (arfcn-128)<<1+52;
/*MT6139B*/             //   *rfN = (63L<<12) | (Nfrac<<4) | 0x80001L;
/*MT6139B*/                *rfN = (63L<<12) | ((arfcn-102)<<5) | 0x080001L; /* 0x080001L; */
/*MT6139B*/            }
/*MT6139B*/            else
/*MT6139B*/            {                              /* ARFCN : 167~231     */
/*MT6139B*/                *rfN = (64L<<12) | ((arfcn-167)<<5) | 0x080001L; /* 0x080001L; */
/*MT6139B*/            }
/*MT6139B*/         }
/*MT6139B*/         else
/*MT6139B*/         {                                 /* ARFCN : 232~251     */
/*MT6139B*/                *rfN = (65L<<12) | ((arfcn-232)<<5) | 0x080001L; /* 0x080001L; */
/*MT6139B*/         }
/*MT6139B*/
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/      case  FrequencyBand900 :
/*MT6139B*/      {
/*MT6139B*/         if(arfcn<=124)
/*MT6139B*/         {  if(arfcn<=99)
/*MT6139B*/            {  if(arfcn<=34)
/*MT6139B*/               {                                /* ARFCN : 0~34     */
/*MT6139B*/                   *rfN = (68L<<12) | ((arfcn+30)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139B*/               }
/*MT6139B*/               else
/*MT6139B*/               {                                /* ARFCN : 35~99     */
/*MT6139B*/                   *rfN = (69L<<12) | ((arfcn-35)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139B*/               }
/*MT6139B*/            }
/*MT6139B*/            else
/*MT6139B*/            {                              /* ARFCN : 100~124     */
/*MT6139B*/                *rfN = (70L<<12) | ((arfcn-100)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139B*/            }
/*MT6139B*/         }
/*MT6139B*/         else
/*MT6139B*/         {  if(arfcn<=993)
/*MT6139B*/            {                                /* ARFCN : 975~993     */
/*MT6139B*/                *rfN = (67L<<12) | ((arfcn-929)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139B*/            }
/*MT6139B*/            else
/*MT6139B*/            {                              /* ARFCN : 994~1023     */
/*MT6139B*/                *rfN = (68L<<12) | ((arfcn-994)<<5) | 0x180001L; /* 0x080001L; */
/*MT6139B*/            }
/*MT6139B*/         }
/*MT6139B*/
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/      case  FrequencyBand1800 :
/*MT6139B*/      {
/*MT6139B*/         if(arfcn<=670)
/*MT6139B*/         {  if(arfcn<=540)
/*MT6139B*/            {                                /* ARFCN : 512~540     */
/*MT6139B*/                *rfN = (65L<<12) | ((arfcn-411)<<4) | 0x200001L; /* 0x280001L; */
/*MT6139B*/            }
/*MT6139B*/            else
/*MT6139B*/            {                              /* ARFCN : 541~670     */
/*MT6139B*/                *rfN = (66L<<12) | ((arfcn-541)<<4) | 0x200001L; /* 0x280001L; */
/*MT6139B*/            }
/*MT6139B*/         }
/*MT6139B*/         else
/*MT6139B*/         {  if(arfcn<=800)
/*MT6139B*/            {                                /* ARFCN : 671~800     */
/*MT6139B*/                *rfN = (67L<<12) | ((arfcn-671)<<4) | 0x200001L; /* 0x280001L; */
/*MT6139B*/            }
/*MT6139B*/            else
/*MT6139B*/            {                              /* ARFCN : 801~885     */
/*MT6139B*/                *rfN = (68L<<12) | ((arfcn-801)<<4) | 0x200001L; /* 0x280001L; */
/*MT6139B*/            }
/*MT6139B*/         }
/*MT6139B*/
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/      case  FrequencyBand1900 :
/*MT6139B*/      {
/*MT6139B*/         if(arfcn<=750)
/*MT6139B*/         {  if(arfcn<=620)
/*MT6139B*/            {                                /* ARFCN : 512~620     */
/*MT6139B*/                *rfN = (71L<<12) | ((arfcn-491)<<4) | 0x300001L; /* 0x380001L; */
/*MT6139B*/            }
/*MT6139B*/            else
/*MT6139B*/            {                               /* ARFCN : 621~750     */
/*MT6139B*/                *rfN = (72L<<12) | ((arfcn-621)<<4) | 0x300001L; /* 0x380001L; */
/*MT6139B*/            }
/*MT6139B*/         }
/*MT6139B*/         else
/*MT6139B*/         {
/*MT6139B*/                                            /* ARFCN : 751~810     */
/*MT6139B*/            *rfN = (73L<<12) | ((arfcn-751)<<4) | 0x300001L; /* 0x380001L; */
/*MT6139B*/
/*MT6139B*/         }
/*MT6139B*/
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/      default :
/*MT6139B*/      {
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/   }
/*MT6139B*/   *ifN = 0;
/*MT6139B*/}
/*MT6139B*//* =========================================================================== */
#endif

#if IS_RF_MT6139C
/*MT6139C*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6139C*/{
/*MT6139C*/   switch(rf_band)
/*MT6139C*/   {
/*MT6139C*/      case  FrequencyBand850 :
/*MT6139C*/      {
/*MT6139C*/         if(arfcn<=201)
/*MT6139C*/         {  if(arfcn<=136)
/*MT6139C*/            {                                /* ARFCN : 128~136     */
/*MT6139C*/                *rfN = (66L<<12) | ((arfcn-72)<<5) | 0x000001L;
/*MT6139C*/            }
/*MT6139C*/            else
/*MT6139C*/            {                              /* ARFCN : 137~201     */
/*MT6139C*/                *rfN = (67L<<12) | ((arfcn-137)<<5) | 0x000001L;
/*MT6139C*/            }
/*MT6139C*/         }
/*MT6139C*/         else
/*MT6139C*/         {                                 /* ARFCN : 202~251     */
/*MT6139C*/                *rfN = (68L<<12) | ((arfcn-202)<<5) | 0x000001L;
/*MT6139C*/         }
/*MT6139C*/
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/      case  FrequencyBand900 :
/*MT6139C*/      {
/*MT6139C*/         if(arfcn<=69)
/*MT6139C*/         {  if(arfcn<=4)
/*MT6139C*/            {                                /* ARFCN : 0~4     */
/*MT6139C*/                *rfN = (71L<<12) | ((arfcn+60)<<5) | 0x100001L;
/*MT6139C*/            }
/*MT6139C*/            else
/*MT6139C*/            {                              /* ARFCN : 5~69     */
/*MT6139C*/                *rfN = (72L<<12) | ((arfcn-5)<<5) | 0x100001L;
/*MT6139C*/            }
/*MT6139C*/         }
/*MT6139C*/         else
/*MT6139C*/         {  if(arfcn<=124)
/*MT6139C*/            {                                /* ARFCN : 70~124     */
/*MT6139C*/                *rfN = (73L<<12) | ((arfcn-70)<<5) | 0x100001L;
/*MT6139C*/            }
/*MT6139C*/            else
/*MT6139C*/            {                              /* ARFCN : 975~1023     */
/*MT6139C*/                *rfN = (71L<<12) | ((arfcn-964)<<5) | 0x100001L;
/*MT6139C*/            }
/*MT6139C*/         }
/*MT6139C*/
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/      case  FrequencyBand1800 :
/*MT6139C*/      {
/*MT6139C*/         if(arfcn<=715)
/*MT6139C*/         {  if(arfcn<=585)
/*MT6139C*/            {                                /* ARFCN : 512~585     */
/*MT6139C*/                *rfN = (69L<<12) | ((arfcn-456)<<4) | 0x200001L;
/*MT6139C*/            }
/*MT6139C*/            else
/*MT6139C*/            {                              /* ARFCN : 586~715     */
/*MT6139C*/                *rfN = (70L<<12) | ((arfcn-586)<<4) | 0x200001L;
/*MT6139C*/            }
/*MT6139C*/         }
/*MT6139C*/         else
/*MT6139C*/         {  if(arfcn<=845)
/*MT6139C*/            {                                /* ARFCN : 716~845     */
/*MT6139C*/                *rfN = (71L<<12) | ((arfcn-716)<<4) | 0x200001L;
/*MT6139C*/            }
/*MT6139C*/            else
/*MT6139C*/            {                              /* ARFCN : 846~885     */
/*MT6139C*/                *rfN = (72L<<12) | ((arfcn-846)<<4) | 0x200001L;
/*MT6139C*/            }
/*MT6139C*/         }
/*MT6139C*/
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/      case  FrequencyBand1900 :
/*MT6139C*/      {
/*MT6139C*/         if(arfcn<=740)
/*MT6139C*/         {  if(arfcn<=610)
/*MT6139C*/            {                                /* ARFCN : 512~610     */
/*MT6139C*/                *rfN = (74L<<12) | ((arfcn-481)<<4) | 0x300001L;
/*MT6139C*/            }
/*MT6139C*/            else
/*MT6139C*/            {                               /* ARFCN : 611~740     */
/*MT6139C*/                *rfN = (75L<<12) | ((arfcn-611)<<4) | 0x300001L;
/*MT6139C*/            }
/*MT6139C*/         }
/*MT6139C*/         else
/*MT6139C*/         {
/*MT6139C*/                                            /* ARFCN : 741~810     */
/*MT6139C*/            *rfN = (76L<<12) | ((arfcn-741)<<4) | 0x300001L;
/*MT6139C*/
/*MT6139C*/         }
/*MT6139C*/
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/      default :
/*MT6139C*/      {
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/   }
/*MT6139C*/   *ifN = 0;
/*MT6139C*/}
/*MT6139C*//* =========================================================================== */
/*MT6139C*/
/*MT6139C*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6139C*/{
/*MT6139C*/   switch(rf_band)
/*MT6139C*/   {
/*MT6139C*/      case  FrequencyBand850 :
/*MT6139C*/      {
/*MT6139C*/         if(arfcn<=231)
/*MT6139C*/         {  if(arfcn<=166)
/*MT6139C*/            {                                /* ARFCN : 128~166     */
/*MT6139C*/                *rfN = (63L<<12) | ((arfcn-102)<<5) | 0x480001L; /* 0x080001L; */
/*MT6139C*/            }
/*MT6139C*/            else
/*MT6139C*/            {                              /* ARFCN : 167~231     */
/*MT6139C*/                *rfN = (64L<<12) | ((arfcn-167)<<5) | 0x480001L; /* 0x080001L; */
/*MT6139C*/            }
/*MT6139C*/         }
/*MT6139C*/         else
/*MT6139C*/         {                                 /* ARFCN : 232~251     */
/*MT6139C*/                *rfN = (65L<<12) | ((arfcn-232)<<5) | 0x480001L; /* 0x080001L; */
/*MT6139C*/         }
/*MT6139C*/
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/      case  FrequencyBand900 :
/*MT6139C*/      {
/*MT6139C*/         if(arfcn<=124)
/*MT6139C*/         {  if(arfcn<=99)
/*MT6139C*/            {  if(arfcn<=34)
/*MT6139C*/               {                                /* ARFCN : 0~34     */
/*MT6139C*/                   *rfN = (68L<<12) | ((arfcn+30)<<5) | 0x580001L; /* 0x180001L; */
/*MT6139C*/               }
/*MT6139C*/               else
/*MT6139C*/               {                                /* ARFCN : 35~99     */
/*MT6139C*/                   *rfN = (69L<<12) | ((arfcn-35)<<5) | 0x580001L; /* 0x180001L; */
/*MT6139C*/               }
/*MT6139C*/            }
/*MT6139C*/            else
/*MT6139C*/            {                              /* ARFCN : 100~124     */
/*MT6139C*/                *rfN = (70L<<12) | ((arfcn-100)<<5) | 0x580001L; /* 0x180001L; */
/*MT6139C*/            }
/*MT6139C*/         }
/*MT6139C*/         else
/*MT6139C*/         {  if(arfcn<=993)
/*MT6139C*/            {                                /* ARFCN : 975~993     */
/*MT6139C*/                *rfN = (67L<<12) | ((arfcn-929)<<5) | 0x580001L; /* 0x180001L; */
/*MT6139C*/            }
/*MT6139C*/            else
/*MT6139C*/            {                              /* ARFCN : 994~1023     */
/*MT6139C*/                *rfN = (68L<<12) | ((arfcn-994)<<5) | 0x580001L; /* 0x080001L; */
/*MT6139C*/            }
/*MT6139C*/         }
/*MT6139C*/
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/      case  FrequencyBand1800 :
/*MT6139C*/      {
/*MT6139C*/         if(arfcn<=670)
/*MT6139C*/         {  if(arfcn<=540)
/*MT6139C*/            {                                /* ARFCN : 512~540     */
/*MT6139C*/                *rfN = (65L<<12) | ((arfcn-411)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139C*/            }
/*MT6139C*/            else
/*MT6139C*/            {                              /* ARFCN : 541~670     */
/*MT6139C*/                *rfN = (66L<<12) | ((arfcn-541)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139C*/            }
/*MT6139C*/         }
/*MT6139C*/         else
/*MT6139C*/         {  if(arfcn<=800)
/*MT6139C*/            {                                /* ARFCN : 671~800     */
/*MT6139C*/                *rfN = (67L<<12) | ((arfcn-671)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139C*/            }
/*MT6139C*/            else
/*MT6139C*/            {                              /* ARFCN : 801~885     */
/*MT6139C*/                *rfN = (68L<<12) | ((arfcn-801)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139C*/            }
/*MT6139C*/         }
/*MT6139C*/
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/      case  FrequencyBand1900 :
/*MT6139C*/      {
/*MT6139C*/         if(arfcn<=750)
/*MT6139C*/         {  if(arfcn<=620)
/*MT6139C*/            {                                /* ARFCN : 512~620     */
/*MT6139C*/                *rfN = (71L<<12) | ((arfcn-491)<<4) | 0x780001L; /* 0x380001L; */
/*MT6139C*/            }
/*MT6139C*/            else
/*MT6139C*/            {                               /* ARFCN : 621~750     */
/*MT6139C*/                *rfN = (72L<<12) | ((arfcn-621)<<4) | 0x780001L; /* 0x380001L; */
/*MT6139C*/            }
/*MT6139C*/         }
/*MT6139C*/         else
/*MT6139C*/         {
/*MT6139C*/                                            /* ARFCN : 751~810     */
/*MT6139C*/            *rfN = (73L<<12) | ((arfcn-751)<<4) | 0x780001L; /* 0x380001L; */
/*MT6139C*/
/*MT6139C*/         }
/*MT6139C*/
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/      default :
/*MT6139C*/      {
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/   }
/*MT6139C*/   *ifN = 0;
/*MT6139C*/}
/*MT6139C*//* =========================================================================== */
#endif

#if IS_RF_MT6139E
/*MT6139E*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6139E*/{
/*MT6139E*/   switch(rf_band)
/*MT6139E*/   {
/*MT6139E*/      case  FrequencyBand850 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=201)
/*MT6139E*/         {  if(arfcn<=136)
/*MT6139E*/            {                                /* ARFCN : 128~136     */
/*MT6139E*/                *rfN = (66L<<12) | ((arfcn-72)<<5) | 0x400001L;
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 137~201     */
/*MT6139E*/                *rfN = (67L<<12) | ((arfcn-137)<<5) | 0x400001L;
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/         else
/*MT6139E*/         {                                 /* ARFCN : 202~251     */
/*MT6139E*/                *rfN = (68L<<12) | ((arfcn-202)<<5) | 0x400001L;
/*MT6139E*/         }
/*MT6139E*/
/*MT6139E*/         // Get GSM850 signal from GSM900 input pins if flag=1
/*MT6139E*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap ) *rfN |= 0x100000L;
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand900 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=69)
/*MT6139E*/         {  if(arfcn<=4)
/*MT6139E*/            {                                /* ARFCN : 0~4     */
/*MT6139E*/                *rfN = (71L<<12) | ((arfcn+60)<<5) | 0x100001L;
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 5~69     */
/*MT6139E*/                *rfN = (72L<<12) | ((arfcn-5)<<5) | 0x100001L;
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/         else
/*MT6139E*/         {  if(arfcn<=124)
/*MT6139E*/            {                                /* ARFCN : 70~124     */
/*MT6139E*/                *rfN = (73L<<12) | ((arfcn-70)<<5) | 0x100001L;
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 975~1023     */
/*MT6139E*/                *rfN = (71L<<12) | ((arfcn-964)<<5) | 0x100001L;
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/
/*MT6139E*/         // Get GSM900 signal from GSM850 input pins if flag=1
/*MT6139E*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap )  *rfN &= (~(0x100000L));
/*MT6139E*/
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand1800 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=715)
/*MT6139E*/         {  if(arfcn<=585)
/*MT6139E*/            {                                /* ARFCN : 512~585     */
/*MT6139E*/                *rfN = (69L<<12) | ((arfcn-456)<<4) | 0x200001L;
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 586~715     */
/*MT6139E*/                *rfN = (70L<<12) | ((arfcn-586)<<4) | 0x200001L;
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/         else
/*MT6139E*/         {  if(arfcn<=845)
/*MT6139E*/            {                                /* ARFCN : 716~845     */
/*MT6139E*/                *rfN = (71L<<12) | ((arfcn-716)<<4) | 0x200001L;
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 846~885     */
/*MT6139E*/                *rfN = (72L<<12) | ((arfcn-846)<<4) | 0x200001L;
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/
/*MT6139E*/         // Get PCS1900 signal from DCS1800 input pins if flag=1
/*MT6139E*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap ) *rfN |= 0x100000L;
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand1900 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=740)
/*MT6139E*/         {  if(arfcn<=610)
/*MT6139E*/            {                                /* ARFCN : 512~610     */
/*MT6139E*/                *rfN = (74L<<12) | ((arfcn-481)<<4) | 0x300001L;
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                               /* ARFCN : 611~740     */
/*MT6139E*/                *rfN = (75L<<12) | ((arfcn-611)<<4) | 0x300001L;
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/         else
/*MT6139E*/         {
/*MT6139E*/                                            /* ARFCN : 741~810     */
/*MT6139E*/            *rfN = (76L<<12) | ((arfcn-741)<<4) | 0x300001L;
/*MT6139E*/
/*MT6139E*/         }
/*MT6139E*/
/*MT6139E*/         // Get DCS1800 signal from PCS1900 input pins if flag=1
/*MT6139E*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap)  *rfN &= (~(0x100000L));
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      default :
/*MT6139E*/      {
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/   }
/*MT6139E*/   *ifN = 0;
/*MT6139E*/}
/*MT6139E*//* =========================================================================== */
/*MT6139E*/
/*MT6139E*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6139E*/{
/*MT6139E*/   switch(rf_band)
/*MT6139E*/   {
/*MT6139E*/      case  FrequencyBand850 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=231)
/*MT6139E*/         {  if(arfcn<=166)
/*MT6139E*/            {                                /* ARFCN : 128~166     */
/*MT6139E*/                *rfN = (63L<<12) | ((arfcn-102)<<5) | 0x080001L; /* 0x080001L; */
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 167~231     */
/*MT6139E*/                *rfN = (64L<<12) | ((arfcn-167)<<5) | 0x080001L; /* 0x080001L; */
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/         else
/*MT6139E*/         {                                 /* ARFCN : 232~251     */
/*MT6139E*/                *rfN = (65L<<12) | ((arfcn-232)<<5) | 0x080001L; /* 0x080001L; */
/*MT6139E*/         }
/*MT6139E*/
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand900 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=124)
/*MT6139E*/         {  if(arfcn<=99)
/*MT6139E*/            {  if(arfcn<=34)
/*MT6139E*/               {                                /* ARFCN : 0~34     */
/*MT6139E*/                   *rfN = (68L<<12) | ((arfcn+30)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139E*/               }
/*MT6139E*/               else
/*MT6139E*/               {                                /* ARFCN : 35~99     */
/*MT6139E*/                   *rfN = (69L<<12) | ((arfcn-35)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139E*/               }
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 100~124     */
/*MT6139E*/                *rfN = (70L<<12) | ((arfcn-100)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/         else
/*MT6139E*/         {  if(arfcn<=993)
/*MT6139E*/            {                                /* ARFCN : 975~993     */
/*MT6139E*/                *rfN = (67L<<12) | ((arfcn-929)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 994~1023     */
/*MT6139E*/                *rfN = (68L<<12) | ((arfcn-994)<<5) | 0x180001L; /* 0x080001L; */
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand1800 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=670)
/*MT6139E*/         {  if(arfcn<=540)
/*MT6139E*/            {                                /* ARFCN : 512~540     */
/*MT6139E*/                *rfN = (65L<<12) | ((arfcn-411)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 541~670     */
/*MT6139E*/                *rfN = (66L<<12) | ((arfcn-541)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/         else
/*MT6139E*/         {  if(arfcn<=800)
/*MT6139E*/            {                                /* ARFCN : 671~800     */
/*MT6139E*/                *rfN = (67L<<12) | ((arfcn-671)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                              /* ARFCN : 801~885     */
/*MT6139E*/                *rfN = (68L<<12) | ((arfcn-801)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand1900 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=750)
/*MT6139E*/         {  if(arfcn<=620)
/*MT6139E*/            {                                /* ARFCN : 512~620     */
/*MT6139E*/                *rfN = (71L<<12) | ((arfcn-491)<<4) | 0x780001L; /* 0x380001L; */
/*MT6139E*/            }
/*MT6139E*/            else
/*MT6139E*/            {                               /* ARFCN : 621~750     */
/*MT6139E*/                *rfN = (72L<<12) | ((arfcn-621)<<4) | 0x780001L; /* 0x380001L; */
/*MT6139E*/            }
/*MT6139E*/         }
/*MT6139E*/         else
/*MT6139E*/         {
/*MT6139E*/                                            /* ARFCN : 751~810     */
/*MT6139E*/            *rfN = (73L<<12) | ((arfcn-751)<<4) | 0x780001L; /* 0x380001L; */
/*MT6139E*/
/*MT6139E*/         }
/*MT6139E*/
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      default :
/*MT6139E*/      {
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/   }
/*MT6139E*/   *ifN = 0;
/*MT6139E*/}
/*MT6139E*//* =========================================================================== */
#endif

#if IS_RF_MT6140A
/*MT6140A*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140A*/{
/*MT6140A*/   switch(rf_band)
/*MT6140A*/   {
/*MT6140A*/      case  FrequencyBand850 :
/*MT6140A*/      {
/*MT6140A*/         if(arfcn<=201)
/*MT6140A*/         {  if(arfcn<=136)
/*MT6140A*/            {                                /* ARFCN : 128~136     */
/*MT6140A*/                *rfN = (66L<<12) | ((arfcn-72)<<5) | 0x000001L;
/*MT6140A*/            }
/*MT6140A*/            else
/*MT6140A*/            {                              /* ARFCN : 137~201     */
/*MT6140A*/                *rfN = (67L<<12) | ((arfcn-137)<<5) | 0x000001L;
/*MT6140A*/            }
/*MT6140A*/         }
/*MT6140A*/         else
/*MT6140A*/         {                                 /* ARFCN : 202~251     */
/*MT6140A*/                *rfN = (68L<<12) | ((arfcn-202)<<5) | 0x000001L;
/*MT6140A*/         }
/*MT6140A*/
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/      case  FrequencyBand900 :
/*MT6140A*/      {
/*MT6140A*/         if(arfcn<=69)
/*MT6140A*/         {  if(arfcn<=4)
/*MT6140A*/            {                                /* ARFCN : 0~4     */
/*MT6140A*/                *rfN = (71L<<12) | ((arfcn+60)<<5) | 0x100001L;
/*MT6140A*/            }
/*MT6140A*/            else
/*MT6140A*/            {                              /* ARFCN : 5~69     */
/*MT6140A*/                *rfN = (72L<<12) | ((arfcn-5)<<5) | 0x100001L;
/*MT6140A*/            }
/*MT6140A*/         }
/*MT6140A*/         else
/*MT6140A*/         {  if(arfcn<=124)
/*MT6140A*/            {                                /* ARFCN : 70~124     */
/*MT6140A*/                *rfN = (73L<<12) | ((arfcn-70)<<5) | 0x100001L;
/*MT6140A*/            }
/*MT6140A*/            else
/*MT6140A*/            {                              /* ARFCN : 975~1023     */
/*MT6140A*/                *rfN = (71L<<12) | ((arfcn-964)<<5) | 0x100001L;
/*MT6140A*/            }
/*MT6140A*/         }
/*MT6140A*/
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/      case  FrequencyBand1800 :
/*MT6140A*/      {
/*MT6140A*/         if(arfcn<=715)
/*MT6140A*/         {  if(arfcn<=585)
/*MT6140A*/            {                                /* ARFCN : 512~585     */
/*MT6140A*/                *rfN = (69L<<12) | ((arfcn-456)<<4) | 0x200001L;
/*MT6140A*/            }
/*MT6140A*/            else
/*MT6140A*/            {                              /* ARFCN : 586~715     */
/*MT6140A*/                *rfN = (70L<<12) | ((arfcn-586)<<4) | 0x200001L;
/*MT6140A*/            }
/*MT6140A*/         }
/*MT6140A*/         else
/*MT6140A*/         {  if(arfcn<=845)
/*MT6140A*/            {                                /* ARFCN : 716~845     */
/*MT6140A*/                *rfN = (71L<<12) | ((arfcn-716)<<4) | 0x200001L;
/*MT6140A*/            }
/*MT6140A*/            else
/*MT6140A*/            {                              /* ARFCN : 846~885     */
/*MT6140A*/                *rfN = (72L<<12) | ((arfcn-846)<<4) | 0x200001L;
/*MT6140A*/            }
/*MT6140A*/         }
/*MT6140A*/
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/      case  FrequencyBand1900 :
/*MT6140A*/      {
/*MT6140A*/         if(arfcn<=740)
/*MT6140A*/         {  if(arfcn<=610)
/*MT6140A*/            {                                /* ARFCN : 512~610     */
/*MT6140A*/                *rfN = (74L<<12) | ((arfcn-481)<<4) | 0x300001L;
/*MT6140A*/            }
/*MT6140A*/            else
/*MT6140A*/            {                               /* ARFCN : 611~740     */
/*MT6140A*/                *rfN = (75L<<12) | ((arfcn-611)<<4) | 0x300001L;
/*MT6140A*/            }
/*MT6140A*/         }
/*MT6140A*/         else
/*MT6140A*/         {
/*MT6140A*/                                            /* ARFCN : 741~810     */
/*MT6140A*/            *rfN = (76L<<12) | ((arfcn-741)<<4) | 0x300001L;
/*MT6140A*/
/*MT6140A*/         }
/*MT6140A*/
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/      default :
/*MT6140A*/      {
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/   }
/*MT6140A*/   *ifN = 0;
/*MT6140A*/}
/*MT6140A*//* =========================================================================== */
/*MT6140A*/
/*MT6140A*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140A*/{
/*MT6140A*/   switch(rf_band)
/*MT6140A*/   {
/*MT6140A*/      case  FrequencyBand850 :
/*MT6140A*/      {
/*MT6140A*/         if(arfcn<=231)
/*MT6140A*/         {  if(arfcn<=166)
/*MT6140A*/            {                                /* ARFCN : 128~166     */
/*MT6140A*/                *rfN = (63L<<12) | ((arfcn-102)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140A*/            }
/*MT6140A*/            else
/*MT6140A*/            {                              /* ARFCN : 167~231     */
/*MT6140A*/                *rfN = (64L<<12) | ((arfcn-167)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140A*/            }
/*MT6140A*/         }
/*MT6140A*/         else
/*MT6140A*/         {                                 /* ARFCN : 232~251     */
/*MT6140A*/                *rfN = (65L<<12) | ((arfcn-232)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140A*/         }
/*MT6140A*/
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/      case  FrequencyBand900 :
/*MT6140A*/      {
/*MT6140A*/         if(arfcn<=124)
/*MT6140A*/         {  if(arfcn<=99)
/*MT6140A*/            {  if(arfcn<=34)
/*MT6140A*/               {                                /* ARFCN : 0~34     */
/*MT6140A*/                   *rfN = (68L<<12) | ((arfcn+30)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140A*/               }
/*MT6140A*/               else
/*MT6140A*/               {                                /* ARFCN : 35~99     */
/*MT6140A*/                   *rfN = (69L<<12) | ((arfcn-35)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140A*/               }
/*MT6140A*/            }
/*MT6140A*/            else
/*MT6140A*/            {                              /* ARFCN : 100~124     */
/*MT6140A*/                *rfN = (70L<<12) | ((arfcn-100)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140A*/            }
/*MT6140A*/         }
/*MT6140A*/         else
/*MT6140A*/         {  if(arfcn<=993)
/*MT6140A*/            {                                /* ARFCN : 975~993     */
/*MT6140A*/                *rfN = (67L<<12) | ((arfcn-929)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140A*/            }
/*MT6140A*/            else
/*MT6140A*/            {                              /* ARFCN : 994~1023     */
/*MT6140A*/                *rfN = (68L<<12) | ((arfcn-994)<<5) | 0x580001L; /* 0x080001L; */
/*MT6140A*/            }
/*MT6140A*/         }
/*MT6140A*/
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/      case  FrequencyBand1800 :
/*MT6140A*/      {
/*MT6140A*/         if(arfcn<=670)
/*MT6140A*/         {  if(arfcn<=540)
/*MT6140A*/            {                                /* ARFCN : 512~540     */
/*MT6140A*/                *rfN = (65L<<12) | ((arfcn-411)<<4) | 0x600001L; /* 0x280001L; */
/*MT6140A*/            }
/*MT6140A*/            else
/*MT6140A*/            {                              /* ARFCN : 541~670     */
/*MT6140A*/                *rfN = (66L<<12) | ((arfcn-541)<<4) | 0x600001L; /* 0x280001L; */
/*MT6140A*/            }
/*MT6140A*/         }
/*MT6140A*/         else
/*MT6140A*/         {  if(arfcn<=800)
/*MT6140A*/            {                                /* ARFCN : 671~800     */
/*MT6140A*/                *rfN = (67L<<12) | ((arfcn-671)<<4) | 0x600001L; /* 0x280001L; */
/*MT6140A*/            }
/*MT6140A*/            else
/*MT6140A*/            {                              /* ARFCN : 801~885     */
/*MT6140A*/                *rfN = (68L<<12) | ((arfcn-801)<<4) | 0x600001L; /* 0x280001L; */
/*MT6140A*/            }
/*MT6140A*/         }
/*MT6140A*/
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/      case  FrequencyBand1900 :
/*MT6140A*/      {
/*MT6140A*/         if(arfcn<=750)
/*MT6140A*/         {  if(arfcn<=620)
/*MT6140A*/            {                                /* ARFCN : 512~620     */
/*MT6140A*/                *rfN = (71L<<12) | ((arfcn-491)<<4) | 0x700001L; /* 0x380001L; */
/*MT6140A*/            }
/*MT6140A*/            else
/*MT6140A*/            {                               /* ARFCN : 621~750     */
/*MT6140A*/                *rfN = (72L<<12) | ((arfcn-621)<<4) | 0x700001L; /* 0x380001L; */
/*MT6140A*/            }
/*MT6140A*/         }
/*MT6140A*/         else
/*MT6140A*/         {
/*MT6140A*/                                            /* ARFCN : 751~810     */
/*MT6140A*/            *rfN = (73L<<12) | ((arfcn-751)<<4) | 0x700001L; /* 0x380001L; */
/*MT6140A*/
/*MT6140A*/         }
/*MT6140A*/
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/      default :
/*MT6140A*/      {
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/   }
/*MT6140A*/   *ifN = 0;
/*MT6140A*/}
/*MT6140A*//* =========================================================================== */
#endif

#if IS_RF_MT6140B
/*MT6140B*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140B*/{
/*MT6140B*/   switch(rf_band)
/*MT6140B*/   {
/*MT6140B*/      case  FrequencyBand850 :
/*MT6140B*/      {
/*MT6140B*/         if(arfcn<=201)
/*MT6140B*/         {  if(arfcn<=136)
/*MT6140B*/            {                                /* ARFCN : 128~136     */
/*MT6140B*/                *rfN = (66L<<12) | ((arfcn-72)<<5) | 0x000001L;
/*MT6140B*/            }
/*MT6140B*/            else
/*MT6140B*/            {                              /* ARFCN : 137~201     */
/*MT6140B*/                *rfN = (67L<<12) | ((arfcn-137)<<5) | 0x000001L;
/*MT6140B*/            }
/*MT6140B*/         }
/*MT6140B*/         else
/*MT6140B*/         {                                 /* ARFCN : 202~251     */
/*MT6140B*/                *rfN = (68L<<12) | ((arfcn-202)<<5) | 0x000001L;
/*MT6140B*/         }
/*MT6140B*/
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/      case  FrequencyBand900 :
/*MT6140B*/      {
/*MT6140B*/         if(arfcn<=69)
/*MT6140B*/         {  if(arfcn<=4)
/*MT6140B*/            {                                /* ARFCN : 0~4     */
/*MT6140B*/                *rfN = (71L<<12) | ((arfcn+60)<<5) | 0x100001L;
/*MT6140B*/            }
/*MT6140B*/            else
/*MT6140B*/            {                              /* ARFCN : 5~69     */
/*MT6140B*/                *rfN = (72L<<12) | ((arfcn-5)<<5) | 0x100001L;
/*MT6140B*/            }
/*MT6140B*/         }
/*MT6140B*/         else
/*MT6140B*/         {  if(arfcn<=124)
/*MT6140B*/            {                                /* ARFCN : 70~124     */
/*MT6140B*/                *rfN = (73L<<12) | ((arfcn-70)<<5) | 0x100001L;
/*MT6140B*/            }
/*MT6140B*/            else
/*MT6140B*/            {                              /* ARFCN : 975~1023     */
/*MT6140B*/                *rfN = (71L<<12) | ((arfcn-964)<<5) | 0x100001L;
/*MT6140B*/            }
/*MT6140B*/         }
/*MT6140B*/
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/      case  FrequencyBand1800 :
/*MT6140B*/      {
/*MT6140B*/         if(arfcn<=715)
/*MT6140B*/         {  if(arfcn<=585)
/*MT6140B*/            {                                /* ARFCN : 512~585     */
/*MT6140B*/                *rfN = (69L<<12) | ((arfcn-456)<<4) | 0x200001L;
/*MT6140B*/            }
/*MT6140B*/            else
/*MT6140B*/            {                              /* ARFCN : 586~715     */
/*MT6140B*/                *rfN = (70L<<12) | ((arfcn-586)<<4) | 0x200001L;
/*MT6140B*/            }
/*MT6140B*/         }
/*MT6140B*/         else
/*MT6140B*/         {  if(arfcn<=845)
/*MT6140B*/            {                                /* ARFCN : 716~845     */
/*MT6140B*/                *rfN = (71L<<12) | ((arfcn-716)<<4) | 0x200001L;
/*MT6140B*/            }
/*MT6140B*/            else
/*MT6140B*/            {                              /* ARFCN : 846~885     */
/*MT6140B*/                *rfN = (72L<<12) | ((arfcn-846)<<4) | 0x200001L;
/*MT6140B*/            }
/*MT6140B*/         }
/*MT6140B*/
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/      case  FrequencyBand1900 :
/*MT6140B*/      {
/*MT6140B*/         if(arfcn<=740)
/*MT6140B*/         {  if(arfcn<=610)
/*MT6140B*/            {                                /* ARFCN : 512~610     */
/*MT6140B*/                *rfN = (74L<<12) | ((arfcn-481)<<4) | 0x300001L;
/*MT6140B*/            }
/*MT6140B*/            else
/*MT6140B*/            {                               /* ARFCN : 611~740     */
/*MT6140B*/                *rfN = (75L<<12) | ((arfcn-611)<<4) | 0x300001L;
/*MT6140B*/            }
/*MT6140B*/         }
/*MT6140B*/         else
/*MT6140B*/         {
/*MT6140B*/                                            /* ARFCN : 741~810     */
/*MT6140B*/            *rfN = (76L<<12) | ((arfcn-741)<<4) | 0x300001L;
/*MT6140B*/
/*MT6140B*/         }
/*MT6140B*/
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/      default :
/*MT6140B*/      {
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/   }
/*MT6140B*/   *ifN = 0;
/*MT6140B*/}
/*MT6140B*//* =========================================================================== */
/*MT6140B*/
/*MT6140B*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140B*/{
/*MT6140B*/   switch(rf_band)
/*MT6140B*/   {
/*MT6140B*/      case  FrequencyBand850 :
/*MT6140B*/      {
/*MT6140B*/         if(arfcn<=231)
/*MT6140B*/         {  if(arfcn<=166)
/*MT6140B*/            {                                /* ARFCN : 128~166     */
/*MT6140B*/                *rfN = (63L<<12) | ((arfcn-102)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140B*/            }
/*MT6140B*/            else
/*MT6140B*/            {                              /* ARFCN : 167~231     */
/*MT6140B*/                *rfN = (64L<<12) | ((arfcn-167)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140B*/            }
/*MT6140B*/         }
/*MT6140B*/         else
/*MT6140B*/         {                                 /* ARFCN : 232~251     */
/*MT6140B*/                *rfN = (65L<<12) | ((arfcn-232)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140B*/         }
/*MT6140B*/
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/      case  FrequencyBand900 :
/*MT6140B*/      {
/*MT6140B*/         if(arfcn<=124)
/*MT6140B*/         {  if(arfcn<=99)
/*MT6140B*/            {  if(arfcn<=34)
/*MT6140B*/               {                                /* ARFCN : 0~34     */
/*MT6140B*/                   *rfN = (68L<<12) | ((arfcn+30)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140B*/               }
/*MT6140B*/               else
/*MT6140B*/               {                                /* ARFCN : 35~99     */
/*MT6140B*/                   *rfN = (69L<<12) | ((arfcn-35)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140B*/               }
/*MT6140B*/            }
/*MT6140B*/            else
/*MT6140B*/            {                              /* ARFCN : 100~124     */
/*MT6140B*/                *rfN = (70L<<12) | ((arfcn-100)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140B*/            }
/*MT6140B*/         }
/*MT6140B*/         else
/*MT6140B*/         {  if(arfcn<=993)
/*MT6140B*/            {                                /* ARFCN : 975~993     */
/*MT6140B*/                *rfN = (67L<<12) | ((arfcn-929)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140B*/            }
/*MT6140B*/            else
/*MT6140B*/            {                              /* ARFCN : 994~1023     */
/*MT6140B*/                *rfN = (68L<<12) | ((arfcn-994)<<5) | 0x580001L; /* 0x080001L; */
/*MT6140B*/            }
/*MT6140B*/         }
/*MT6140B*/
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/      case  FrequencyBand1800 :
/*MT6140B*/      {
/*MT6140B*/         if(arfcn<=670)
/*MT6140B*/         {  if(arfcn<=540)
/*MT6140B*/            {                                /* ARFCN : 512~540     */
/*MT6140B*/                *rfN = (65L<<12) | ((arfcn-411)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140B*/            }
/*MT6140B*/            else
/*MT6140B*/            {                              /* ARFCN : 541~670     */
/*MT6140B*/                *rfN = (66L<<12) | ((arfcn-541)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140B*/            }
/*MT6140B*/         }
/*MT6140B*/         else
/*MT6140B*/         {  if(arfcn<=800)
/*MT6140B*/            {                                /* ARFCN : 671~800     */
/*MT6140B*/                *rfN = (67L<<12) | ((arfcn-671)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140B*/            }
/*MT6140B*/            else
/*MT6140B*/            {                              /* ARFCN : 801~885     */
/*MT6140B*/                *rfN = (68L<<12) | ((arfcn-801)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140B*/            }
/*MT6140B*/         }
/*MT6140B*/
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/      case  FrequencyBand1900 :
/*MT6140B*/      {
/*MT6140B*/         if(arfcn<=750)
/*MT6140B*/         {  if(arfcn<=620)
/*MT6140B*/            {                                /* ARFCN : 512~620     */
/*MT6140B*/                *rfN = (71L<<12) | ((arfcn-491)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140B*/            }
/*MT6140B*/            else
/*MT6140B*/            {                               /* ARFCN : 621~750     */
/*MT6140B*/                *rfN = (72L<<12) | ((arfcn-621)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140B*/            }
/*MT6140B*/         }
/*MT6140B*/         else
/*MT6140B*/         {
/*MT6140B*/                                            /* ARFCN : 751~810     */
/*MT6140B*/            *rfN = (73L<<12) | ((arfcn-751)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140B*/
/*MT6140B*/         }
/*MT6140B*/
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/      default :
/*MT6140B*/      {
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/   }
/*MT6140B*/   *ifN = 0;
/*MT6140B*/}
/*MT6140B*//* =========================================================================== */
#endif

#if IS_RF_MT6140C
/*MT6140C*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140C*/{
/*MT6140C*/   switch(rf_band)
/*MT6140C*/   {
/*MT6140C*/      case  FrequencyBand850 :
/*MT6140C*/      {
/*MT6140C*/         if(arfcn<=201)
/*MT6140C*/         {  if(arfcn<=136)
/*MT6140C*/            {                                /* ARFCN : 128~136     */
/*MT6140C*/                *rfN = (66L<<12) | ((arfcn-72)<<5) | 0x000001L;
/*MT6140C*/            }
/*MT6140C*/            else
/*MT6140C*/            {                              /* ARFCN : 137~201     */
/*MT6140C*/                *rfN = (67L<<12) | ((arfcn-137)<<5) | 0x000001L;
/*MT6140C*/            }
/*MT6140C*/         }
/*MT6140C*/         else
/*MT6140C*/         {                                 /* ARFCN : 202~251     */
/*MT6140C*/                *rfN = (68L<<12) | ((arfcn-202)<<5) | 0x000001L;
/*MT6140C*/         }
/*MT6140C*/
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/      case  FrequencyBand900 :
/*MT6140C*/      {
/*MT6140C*/         if(arfcn<=69)
/*MT6140C*/         {  if(arfcn<=4)
/*MT6140C*/            {                                /* ARFCN : 0~4     */
/*MT6140C*/                *rfN = (71L<<12) | ((arfcn+60)<<5) | 0x100001L;
/*MT6140C*/            }
/*MT6140C*/            else
/*MT6140C*/            {                              /* ARFCN : 5~69     */
/*MT6140C*/                *rfN = (72L<<12) | ((arfcn-5)<<5) | 0x100001L;
/*MT6140C*/            }
/*MT6140C*/         }
/*MT6140C*/         else
/*MT6140C*/         {  if(arfcn<=124)
/*MT6140C*/            {                                /* ARFCN : 70~124     */
/*MT6140C*/                *rfN = (73L<<12) | ((arfcn-70)<<5) | 0x100001L;
/*MT6140C*/            }
/*MT6140C*/            else
/*MT6140C*/            {                              /* ARFCN : 975~1023     */
/*MT6140C*/                *rfN = (71L<<12) | ((arfcn-964)<<5) | 0x100001L;
/*MT6140C*/            }
/*MT6140C*/         }
/*MT6140C*/
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/      case  FrequencyBand1800 :
/*MT6140C*/      {
/*MT6140C*/         if(arfcn<=715)
/*MT6140C*/         {  if(arfcn<=585)
/*MT6140C*/            {                                /* ARFCN : 512~585     */
/*MT6140C*/                *rfN = (69L<<12) | ((arfcn-456)<<4) | 0x200001L;
/*MT6140C*/            }
/*MT6140C*/            else
/*MT6140C*/            {                              /* ARFCN : 586~715     */
/*MT6140C*/                *rfN = (70L<<12) | ((arfcn-586)<<4) | 0x200001L;
/*MT6140C*/            }
/*MT6140C*/         }
/*MT6140C*/         else
/*MT6140C*/         {  if(arfcn<=845)
/*MT6140C*/            {                                /* ARFCN : 716~845     */
/*MT6140C*/                *rfN = (71L<<12) | ((arfcn-716)<<4) | 0x200001L;
/*MT6140C*/            }
/*MT6140C*/            else
/*MT6140C*/            {                              /* ARFCN : 846~885     */
/*MT6140C*/                *rfN = (72L<<12) | ((arfcn-846)<<4) | 0x200001L;
/*MT6140C*/            }
/*MT6140C*/         }
/*MT6140C*/
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/      case  FrequencyBand1900 :
/*MT6140C*/      {
/*MT6140C*/         if(arfcn<=740)
/*MT6140C*/         {  if(arfcn<=610)
/*MT6140C*/            {                                /* ARFCN : 512~610     */
/*MT6140C*/                *rfN = (74L<<12) | ((arfcn-481)<<4) | 0x300001L;
/*MT6140C*/            }
/*MT6140C*/            else
/*MT6140C*/            {                               /* ARFCN : 611~740     */
/*MT6140C*/                *rfN = (75L<<12) | ((arfcn-611)<<4) | 0x300001L;
/*MT6140C*/            }
/*MT6140C*/         }
/*MT6140C*/         else
/*MT6140C*/         {
/*MT6140C*/                                            /* ARFCN : 741~810     */
/*MT6140C*/            *rfN = (76L<<12) | ((arfcn-741)<<4) | 0x300001L;
/*MT6140C*/
/*MT6140C*/         }
/*MT6140C*/
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/      default :
/*MT6140C*/      {
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/   }
/*MT6140C*/   *ifN = 0;
/*MT6140C*/}
/*MT6140C*//* =========================================================================== */
/*MT6140C*/
/*MT6140C*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140C*/{
/*MT6140C*/   switch(rf_band)
/*MT6140C*/   {
/*MT6140C*/      case  FrequencyBand850 :
/*MT6140C*/      {
/*MT6140C*/         if(arfcn<=231)
/*MT6140C*/         {  if(arfcn<=166)
/*MT6140C*/            {                                /* ARFCN : 128~166     */
/*MT6140C*/                *rfN = (63L<<12) | ((arfcn-102)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140C*/            }
/*MT6140C*/            else
/*MT6140C*/            {                              /* ARFCN : 167~231     */
/*MT6140C*/                *rfN = (64L<<12) | ((arfcn-167)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140C*/            }
/*MT6140C*/         }
/*MT6140C*/         else
/*MT6140C*/         {                                 /* ARFCN : 232~251     */
/*MT6140C*/                *rfN = (65L<<12) | ((arfcn-232)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140C*/         }
/*MT6140C*/
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/      case  FrequencyBand900 :
/*MT6140C*/      {
/*MT6140C*/         if(arfcn<=124)
/*MT6140C*/         {  if(arfcn<=99)
/*MT6140C*/            {  if(arfcn<=34)
/*MT6140C*/               {                                /* ARFCN : 0~34     */
/*MT6140C*/                   *rfN = (68L<<12) | ((arfcn+30)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140C*/               }
/*MT6140C*/               else
/*MT6140C*/               {                                /* ARFCN : 35~99     */
/*MT6140C*/                   *rfN = (69L<<12) | ((arfcn-35)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140C*/               }
/*MT6140C*/            }
/*MT6140C*/            else
/*MT6140C*/            {                              /* ARFCN : 100~124     */
/*MT6140C*/                *rfN = (70L<<12) | ((arfcn-100)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140C*/            }
/*MT6140C*/         }
/*MT6140C*/         else
/*MT6140C*/         {  if(arfcn<=993)
/*MT6140C*/            {                                /* ARFCN : 975~993     */
/*MT6140C*/                *rfN = (67L<<12) | ((arfcn-929)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140C*/            }
/*MT6140C*/            else
/*MT6140C*/            {                              /* ARFCN : 994~1023     */
/*MT6140C*/                *rfN = (68L<<12) | ((arfcn-994)<<5) | 0x580001L; /* 0x080001L; */
/*MT6140C*/            }
/*MT6140C*/         }
/*MT6140C*/
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/      case  FrequencyBand1800 :
/*MT6140C*/      {
/*MT6140C*/         if(arfcn<=670)
/*MT6140C*/         {  if(arfcn<=540)
/*MT6140C*/            {                                /* ARFCN : 512~540     */
/*MT6140C*/                *rfN = (65L<<12) | ((arfcn-411)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140C*/            }
/*MT6140C*/            else
/*MT6140C*/            {                              /* ARFCN : 541~670     */
/*MT6140C*/                *rfN = (66L<<12) | ((arfcn-541)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140C*/            }
/*MT6140C*/         }
/*MT6140C*/         else
/*MT6140C*/         {  if(arfcn<=800)
/*MT6140C*/            {                                /* ARFCN : 671~800     */
/*MT6140C*/                *rfN = (67L<<12) | ((arfcn-671)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140C*/            }
/*MT6140C*/            else
/*MT6140C*/            {                              /* ARFCN : 801~885     */
/*MT6140C*/                *rfN = (68L<<12) | ((arfcn-801)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140C*/            }
/*MT6140C*/         }
/*MT6140C*/
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/      case  FrequencyBand1900 :
/*MT6140C*/      {
/*MT6140C*/         if(arfcn<=750)
/*MT6140C*/         {  if(arfcn<=620)
/*MT6140C*/            {                                /* ARFCN : 512~620     */
/*MT6140C*/                *rfN = (71L<<12) | ((arfcn-491)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140C*/            }
/*MT6140C*/            else
/*MT6140C*/            {                               /* ARFCN : 621~750     */
/*MT6140C*/                *rfN = (72L<<12) | ((arfcn-621)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140C*/            }
/*MT6140C*/         }
/*MT6140C*/         else
/*MT6140C*/         {
/*MT6140C*/                                            /* ARFCN : 751~810     */
/*MT6140C*/            *rfN = (73L<<12) | ((arfcn-751)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140C*/
/*MT6140C*/         }
/*MT6140C*/
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/      default :
/*MT6140C*/      {
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/   }
/*MT6140C*/   *ifN = 0;
/*MT6140C*/}
/*MT6140C*//* =========================================================================== */
#endif

#if IS_RF_MT6140D
/*MT6140D*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140D*/{
/*MT6140D*/   switch(rf_band)
/*MT6140D*/   {
/*MT6140D*/      case  FrequencyBand850 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=201)
/*MT6140D*/         {  if(arfcn<=136)
/*MT6140D*/            {                                /* ARFCN : 128~136     */
/*MT6140D*/                *rfN = (66L<<12) | ((arfcn-72)<<5) | 0x000001L;
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 137~201     */
/*MT6140D*/                *rfN = (67L<<12) | ((arfcn-137)<<5) | 0x000001L;
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/         else
/*MT6140D*/         {                                 /* ARFCN : 202~251     */
/*MT6140D*/                *rfN = (68L<<12) | ((arfcn-202)<<5) | 0x000001L;
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         // Get GSM850 signal from GSM900 input pins if flag=1
/*MT6140D*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap ) *rfN |= 0x100000L;
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand900 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=69)
/*MT6140D*/         {  if(arfcn<=4)
/*MT6140D*/            {                                /* ARFCN : 0~4     */
/*MT6140D*/                *rfN = (71L<<12) | ((arfcn+60)<<5) | 0x100001L;
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 5~69     */
/*MT6140D*/                *rfN = (72L<<12) | ((arfcn-5)<<5) | 0x100001L;
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/         else
/*MT6140D*/         {  if(arfcn<=124)
/*MT6140D*/            {                                /* ARFCN : 70~124     */
/*MT6140D*/                *rfN = (73L<<12) | ((arfcn-70)<<5) | 0x100001L;
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 975~1023     */
/*MT6140D*/                *rfN = (71L<<12) | ((arfcn-964)<<5) | 0x100001L;
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         // Get GSM900 signal from GSM850 input pins if flag=1
/*MT6140D*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap )  *rfN &= (~(0x100000L));
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand1800 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=715)
/*MT6140D*/         {  if(arfcn<=585)
/*MT6140D*/            {                                /* ARFCN : 512~585     */
/*MT6140D*/                *rfN = (69L<<12) | ((arfcn-456)<<4) | 0x200001L;
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 586~715     */
/*MT6140D*/                *rfN = (70L<<12) | ((arfcn-586)<<4) | 0x200001L;
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/         else
/*MT6140D*/         {  if(arfcn<=845)
/*MT6140D*/            {                                /* ARFCN : 716~845     */
/*MT6140D*/                *rfN = (71L<<12) | ((arfcn-716)<<4) | 0x200001L;
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 846~885     */
/*MT6140D*/                *rfN = (72L<<12) | ((arfcn-846)<<4) | 0x200001L;
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         // Get PCS1900 signal from DCS1800 input pins if flag=1
/*MT6140D*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap ) *rfN |= 0x100000L;
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand1900 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=740)
/*MT6140D*/         {  if(arfcn<=610)
/*MT6140D*/            {                                /* ARFCN : 512~610     */
/*MT6140D*/                *rfN = (74L<<12) | ((arfcn-481)<<4) | 0x300001L;
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                               /* ARFCN : 611~740     */
/*MT6140D*/                *rfN = (75L<<12) | ((arfcn-611)<<4) | 0x300001L;
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/         else
/*MT6140D*/         {
/*MT6140D*/                                            /* ARFCN : 741~810     */
/*MT6140D*/            *rfN = (76L<<12) | ((arfcn-741)<<4) | 0x300001L;
/*MT6140D*/
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         // Get DCS1800 signal from PCS1900 input pins if flag=1
/*MT6140D*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap)  *rfN &= (~(0x100000L));
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      default :
/*MT6140D*/      {
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/   }
/*MT6140D*/   *ifN = 0;
/*MT6140D*/}
/*MT6140D*//* =========================================================================== */
/*MT6140D*/
/*MT6140D*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140D*/{
/*MT6140D*/   switch(rf_band)
/*MT6140D*/   {
/*MT6140D*/      case  FrequencyBand850 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=231)
/*MT6140D*/         {  if(arfcn<=166)
/*MT6140D*/            {                                /* ARFCN : 128~166     */
/*MT6140D*/                *rfN = (63L<<12) | ((arfcn-102)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 167~231     */
/*MT6140D*/                *rfN = (64L<<12) | ((arfcn-167)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/         else
/*MT6140D*/         {                                 /* ARFCN : 232~251     */
/*MT6140D*/                *rfN = (65L<<12) | ((arfcn-232)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand900 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=124)
/*MT6140D*/         {  if(arfcn<=99)
/*MT6140D*/            {  if(arfcn<=34)
/*MT6140D*/               {                                /* ARFCN : 0~34     */
/*MT6140D*/                   *rfN = (68L<<12) | ((arfcn+30)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140D*/               }
/*MT6140D*/               else
/*MT6140D*/               {                                /* ARFCN : 35~99     */
/*MT6140D*/                   *rfN = (69L<<12) | ((arfcn-35)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140D*/               }
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 100~124     */
/*MT6140D*/                *rfN = (70L<<12) | ((arfcn-100)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/         else
/*MT6140D*/         {  if(arfcn<=993)
/*MT6140D*/            {                                /* ARFCN : 975~993     */
/*MT6140D*/                *rfN = (67L<<12) | ((arfcn-929)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 994~1023     */
/*MT6140D*/                *rfN = (68L<<12) | ((arfcn-994)<<5) | 0x580001L; /* 0x080001L; */
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand1800 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=670)
/*MT6140D*/         {  if(arfcn<=540)
/*MT6140D*/            {                                /* ARFCN : 512~540     */
/*MT6140D*/                *rfN = (65L<<12) | ((arfcn-411)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 541~670     */
/*MT6140D*/                *rfN = (66L<<12) | ((arfcn-541)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/         else
/*MT6140D*/         {  if(arfcn<=800)
/*MT6140D*/            {                                /* ARFCN : 671~800     */
/*MT6140D*/                *rfN = (67L<<12) | ((arfcn-671)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                              /* ARFCN : 801~885     */
/*MT6140D*/                *rfN = (68L<<12) | ((arfcn-801)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand1900 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=750)
/*MT6140D*/         {  if(arfcn<=620)
/*MT6140D*/            {                                /* ARFCN : 512~620     */
/*MT6140D*/                *rfN = (71L<<12) | ((arfcn-491)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140D*/            }
/*MT6140D*/            else
/*MT6140D*/            {                               /* ARFCN : 621~750     */
/*MT6140D*/                *rfN = (72L<<12) | ((arfcn-621)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140D*/            }
/*MT6140D*/         }
/*MT6140D*/         else
/*MT6140D*/         {
/*MT6140D*/                                            /* ARFCN : 751~810     */
/*MT6140D*/            *rfN = (73L<<12) | ((arfcn-751)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140D*/
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      default :
/*MT6140D*/      {
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/   }
/*MT6140D*/   *ifN = 0;
/*MT6140D*/}
/*MT6140D*//* =========================================================================== */
#endif

#if IS_RF_CMOSEDGE
/*CMOSEDGE*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*CMOSEDGE*/{ int Nfrac;
/*CMOSEDGE*/   switch(rf_band)
/*CMOSEDGE*/   {
/*CMOSEDGE*/      case  FrequencyBand850 :
/*CMOSEDGE*/      {
/*CMOSEDGE*/         if(arfcn<=201)
/*CMOSEDGE*/         {  if(arfcn<=169)
/*CMOSEDGE*/            {  if(arfcn<=136)
/*CMOSEDGE*/               {                                /* ARFCN : 128~136     */
/*CMOSEDGE*/                   Nfrac = (arfcn-128)*258111+6065609;
/*CMOSEDGE*/                   *rfN = (133L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/               else
/*CMOSEDGE*/               {                                /* ARFCN : 137~169     */
/*CMOSEDGE*/                   Nfrac = (arfcn-137)*258111;
/*CMOSEDGE*/                   //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (134L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/            }
/*CMOSEDGE*/            else
/*CMOSEDGE*/            {                              /* ARFCN : 170~201     */
/*CMOSEDGE*/                Nfrac = (arfcn-170)*258111+129056;
/*CMOSEDGE*/                *rfN = (135L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/         }
/*CMOSEDGE*/         else
/*CMOSEDGE*/         {  if(arfcn<=234)
/*CMOSEDGE*/            {                                /* ARFCN : 202~234     */
/*CMOSEDGE*/                Nfrac = (arfcn-202)*258111;
/*CMOSEDGE*/                //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                *rfN = (136L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/            else
/*CMOSEDGE*/            {                                /* ARFCN : 235~251     */
/*CMOSEDGE*/                 Nfrac = (arfcn-235)*258111+129056;
/*CMOSEDGE*/                *rfN = (137L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/         }
/*CMOSEDGE*/         *ifN = (Nfrac>>10);
/*CMOSEDGE*/
/*CMOSEDGE*/         // Get GSM850 signal from GSM900 input pins if flag=1
/*CMOSEDGE*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap ) *ifN |=0x0010000L ;
/*CMOSEDGE*/         break;
/*CMOSEDGE*/      }
/*CMOSEDGE*/      case  FrequencyBand900 :
/*CMOSEDGE*/      {
/*CMOSEDGE*/         if(arfcn<=124)
/*CMOSEDGE*/         {  if(arfcn<=69)
/*CMOSEDGE*/            {  if(arfcn<=37)
/*CMOSEDGE*/               {  if(arfcn<=4)
/*CMOSEDGE*/                  {                                /* ARFCN : 0~4     */
/*CMOSEDGE*/                      Nfrac = arfcn*258111+7098053;
/*CMOSEDGE*/                      *rfN = (143L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/                  }
/*CMOSEDGE*/                  else
/*CMOSEDGE*/                  {                                /* ARFCN : 5~37     */
/*CMOSEDGE*/                      Nfrac = (arfcn-5)*258111;
/*CMOSEDGE*/                      //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                      *rfN = (144L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/                  }
/*CMOSEDGE*/               }
/*CMOSEDGE*/               else
/*CMOSEDGE*/               {                                /* ARFCN : 38~69     */
/*CMOSEDGE*/                    Nfrac = (arfcn-38)*258111+129056;
/*CMOSEDGE*/                   *rfN = (145L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/            }
/*CMOSEDGE*/            else
/*CMOSEDGE*/            {  if(arfcn<=102)
/*CMOSEDGE*/               {                                /* ARFCN : 70~102     */
/*CMOSEDGE*/                    Nfrac = (arfcn-70)*258111;
/*CMOSEDGE*/                    //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (146L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/               else
/*CMOSEDGE*/               {                                /* ARFCN : 103~124     */
/*CMOSEDGE*/                    Nfrac = (arfcn-103)*258111+129056;
/*CMOSEDGE*/                   *rfN = (147L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/            }
/*CMOSEDGE*/         }
/*CMOSEDGE*/         else
/*CMOSEDGE*/         {  if(arfcn<=996)
/*CMOSEDGE*/            {                                /* ARFCN : 975~996     */
/*CMOSEDGE*/                Nfrac = (arfcn-975)*258111+2839221;
/*CMOSEDGE*/                *rfN = (142L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/            else
/*CMOSEDGE*/            {                              /* ARFCN : 997~1023     */
/*CMOSEDGE*/                Nfrac = (arfcn-997)*258111+129056;
/*CMOSEDGE*/                *rfN = (143L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/         }
/*CMOSEDGE*/         *ifN = (Nfrac>>10) | 0x0010000L;
/*CMOSEDGE*/
/*CMOSEDGE*/         // Get GSM900 signal from GSM850 input pins if flag=1
/*CMOSEDGE*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap )  *ifN &= (~(0x0010000L));
/*CMOSEDGE*/         break;
/*CMOSEDGE*/      }
/*CMOSEDGE*/      case  FrequencyBand1800 :
/*CMOSEDGE*/      {
/*CMOSEDGE*/         if(arfcn<=715)
/*CMOSEDGE*/         {  if(arfcn<=585)
/*CMOSEDGE*/            {  if(arfcn<=520)
/*CMOSEDGE*/               {                                /* ARFCN : 512~520     */
/*CMOSEDGE*/                   Nfrac=((arfcn-512)&0x1) ? ((arfcn-513)>>1)*258111+7356164:((arfcn-512)>>1)*258111+7227108;
/*CMOSEDGE*/                   *rfN = (138L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/               else
/*CMOSEDGE*/               {                               /* ARFCN : 521~585     */
/*CMOSEDGE*/                   Nfrac=((arfcn-521)&0x1) ? ((arfcn-522)>>1)*258111+129056:((arfcn-521)>>1)*258111;
/*CMOSEDGE*/                   //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (139L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/            }
/*CMOSEDGE*/            else
/*CMOSEDGE*/            {  if(arfcn<=650)
/*CMOSEDGE*/               {                                /* ARFCN : 586~650     */
/*CMOSEDGE*/                    Nfrac=((arfcn-586)&0x1) ? ((arfcn-587)>>1)*258111+129056:((arfcn-586)>>1)*258111;
/*CMOSEDGE*/                   //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (140L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/               else
/*CMOSEDGE*/               {                                /* ARFCN : 651~715     */
/*CMOSEDGE*/                   Nfrac=((arfcn-651)&0x1) ? ((arfcn-652)>>1)*258111+129056:((arfcn-651)>>1)*258111;
/*CMOSEDGE*/                   //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (141L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/            }
/*CMOSEDGE*/         }
/*CMOSEDGE*/         else
/*CMOSEDGE*/         {  if(arfcn<=845)
/*CMOSEDGE*/            {  if(arfcn<=780)
/*CMOSEDGE*/               {                                /* ARFCN : 716~780     */
/*CMOSEDGE*/                   Nfrac=((arfcn-716)&0x1) ? ((arfcn-717)>>1)*258111+129056:((arfcn-716)>>1)*258111;
/*CMOSEDGE*/                   //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (142L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/                }
/*CMOSEDGE*/                else
/*CMOSEDGE*/                {                              /* ARFCN : 781~845     */
/*CMOSEDGE*/                   Nfrac=((arfcn-781)&0x1) ? ((arfcn-782)>>1)*258111+129056:((arfcn-781)>>1)*258111;
/*CMOSEDGE*/                   //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (143L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/                }
/*CMOSEDGE*/            }
/*CMOSEDGE*/            else
/*CMOSEDGE*/            {                              /* ARFCN : 846~885     */
/*CMOSEDGE*/                 Nfrac=((arfcn-846)&0x1) ? ((arfcn-847)>>1)*258111+129056:((arfcn-846)>>1)*258111;
/*CMOSEDGE*/                 //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                *rfN = (144L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/         }
/*CMOSEDGE*/         *ifN = (Nfrac>>10) | 0x0020000L;
/*CMOSEDGE*/
/*CMOSEDGE*/         // Get PCS1900 signal from DCS1800 input pins if flag=1
/*CMOSEDGE*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap ) *ifN |=0x0010000L ;
/*CMOSEDGE*/         break;
/*CMOSEDGE*/      }
/*CMOSEDGE*/      case  FrequencyBand1900 :
/*CMOSEDGE*/      {
/*CMOSEDGE*/         if(arfcn<=675)
/*CMOSEDGE*/         {  if(arfcn<=610)
/*CMOSEDGE*/            {  if(arfcn<=545)
/*CMOSEDGE*/               {                                /* ARFCN : 512~545     */
/*CMOSEDGE*/                   Nfrac=((arfcn-512)&0x1) ? ((arfcn-513)>>1)*258111+4129776:((arfcn-512)>>1)*258111+4000721;
/*CMOSEDGE*/                   *rfN = (148L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/               else
/*CMOSEDGE*/               {                                /* ARFCN : 546~610     */
/*CMOSEDGE*/                   Nfrac=((arfcn-546)&0x1) ? ((arfcn-547)>>1)*258111+129056:((arfcn-546)>>1)*258111;;
/*CMOSEDGE*/                   //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (149L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/            }
/*CMOSEDGE*/            else
/*CMOSEDGE*/            {                              /* ARFCN : 611~675     */
/*CMOSEDGE*/                 Nfrac=((arfcn-611)&0x1) ? ((arfcn-612)>>1)*258111+129056:((arfcn-611)>>1)*258111;
/*CMOSEDGE*/                 //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                *rfN = (150L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/         }
/*CMOSEDGE*/         else
/*CMOSEDGE*/         {  if(arfcn<=805)
/*CMOSEDGE*/            {  if(arfcn<=740)
/*CMOSEDGE*/               {                                /* ARFCN : 676~740     */
/*CMOSEDGE*/                   Nfrac=((arfcn-676)&0x1) ? ((arfcn-677)>>1)*258111+129056:((arfcn-676)>>1)*258111;
/*CMOSEDGE*/                   //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (151L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/               else
/*CMOSEDGE*/               {                                /* ARFCN : 741~805     */
/*CMOSEDGE*/                   Nfrac=((arfcn-741)&0x1) ? ((arfcn-742)>>1)*258111+129056:((arfcn-741)>>1)*258111;
/*CMOSEDGE*/                   //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (152L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/            }
/*CMOSEDGE*/            else
/*CMOSEDGE*/            {                                /* ARFCN : 806~810     */
/*CMOSEDGE*/                Nfrac=((arfcn-806)&0x1) ? ((arfcn-807)>>1)*258111+129056:((arfcn-806)>>1)*258111;
/*CMOSEDGE*/                //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                *rfN = (153L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/         }
/*CMOSEDGE*/         *ifN = (Nfrac>>10) | 0x0030000L;
/*CMOSEDGE*/
/*CMOSEDGE*/         // Get DCS1800 signal from PCS1900 input pins if flag=1
/*CMOSEDGE*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap)  *ifN &= (~(0x0010000L));
/*CMOSEDGE*/         break;
/*CMOSEDGE*/      }
/*CMOSEDGE*/      default :
/*CMOSEDGE*/      {
/*CMOSEDGE*/         break;
/*CMOSEDGE*/      }
/*CMOSEDGE*/   }
/*CMOSEDGE*/}
/*CMOSEDGE*//* =========================================================================== */
/*CMOSEDGE*/
/*CMOSEDGE*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*CMOSEDGE*/{  int Nfrac;
/*CMOSEDGE*/   switch(rf_band)
/*CMOSEDGE*/   {
/*CMOSEDGE*/      case  FrequencyBand850 :
/*CMOSEDGE*/      {
/*CMOSEDGE*/         if(arfcn<=199)
/*CMOSEDGE*/         {  if(arfcn<=166)
/*CMOSEDGE*/            {  if(arfcn<=134)
/*CMOSEDGE*/               {                                /* ARFCN : 128~134     */
/*CMOSEDGE*/                   Nfrac = (arfcn-128)*258111+6710886;
/*CMOSEDGE*/                   *rfN = (126L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/               else
/*CMOSEDGE*/               {                                /* ARFCN : 135~166     */
/*CMOSEDGE*/                   Nfrac = (arfcn-135)*258111+129056;
/*CMOSEDGE*/                   *rfN = (127L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/            }
/*CMOSEDGE*/            else
/*CMOSEDGE*/            {                              /* ARFCN : 167~199     */
/*CMOSEDGE*/                 Nfrac = (arfcn-167)*258111;
/*CMOSEDGE*/                 //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                *rfN = (128L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/         }
/*CMOSEDGE*/         else
/*CMOSEDGE*/         {  if(arfcn<=231)
/*CMOSEDGE*/            {                                /* ARFCN : 200~231     */
/*CMOSEDGE*/                 Nfrac = (arfcn-200)*258111+129056;
/*CMOSEDGE*/                *rfN = (129L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/            else
/*CMOSEDGE*/            {                                /* ARFCN : 232~251     */
/*CMOSEDGE*/                 Nfrac = (arfcn-232)*258111;
/*CMOSEDGE*/                 //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                *rfN = (130L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/         }
/*CMOSEDGE*/         *ifN = (Nfrac>>10) | 0x0040000L |(arfcn<<20);
/*CMOSEDGE*/
/*CMOSEDGE*/         break;
/*CMOSEDGE*/      }
/*CMOSEDGE*/      case  FrequencyBand900 :
/*CMOSEDGE*/      {
/*CMOSEDGE*/         if(arfcn<=124)
/*CMOSEDGE*/         {  if(arfcn<=67)
/*CMOSEDGE*/            {  if(arfcn<=34)
/*CMOSEDGE*/               {  if(arfcn<=2)
/*CMOSEDGE*/                  {                                /* ARFCN : 0~2     */
/*CMOSEDGE*/                      Nfrac =arfcn*258111+7743330;
/*CMOSEDGE*/                      *rfN = (136L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/                  }
/*CMOSEDGE*/                  else
/*CMOSEDGE*/                  {                                /* ARFCN : 3~34     */
/*CMOSEDGE*/                      Nfrac =(arfcn-3)*258111+129056;
/*CMOSEDGE*/                      *rfN = (137L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/                  }
/*CMOSEDGE*/               }
/*CMOSEDGE*/               else
/*CMOSEDGE*/               {                                /* ARFCN : 35~67     */
/*CMOSEDGE*/                      Nfrac =(arfcn-35)*258111;
/*CMOSEDGE*/                     // if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                      *rfN = (138L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/            }
/*CMOSEDGE*/            else
/*CMOSEDGE*/            {  if(arfcn<=99)
/*CMOSEDGE*/               {                                /* ARFCN : 68~99     */
/*CMOSEDGE*/                    Nfrac =(arfcn-68)*258111+129056;
/*CMOSEDGE*/                   *rfN = (139L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/               else
/*CMOSEDGE*/               {                                /* ARFCN : 100~124     */
/*CMOSEDGE*/                    Nfrac =(arfcn-100)*258111;
/*CMOSEDGE*/                    //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (140L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/            }
/*CMOSEDGE*/         }
/*CMOSEDGE*/         else
/*CMOSEDGE*/         {  if(arfcn<=993)
/*CMOSEDGE*/            {                                /* ARFCN : 975~993     */
/*CMOSEDGE*/                Nfrac = (arfcn-975)*258111+3484499;
/*CMOSEDGE*/                *rfN = (135L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/            else
/*CMOSEDGE*/            {                              /* ARFCN : 994~1023     */
/*CMOSEDGE*/                Nfrac = (arfcn-994)*258111;
/*CMOSEDGE*/               // if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                *rfN = (136L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/         }
/*CMOSEDGE*/         *ifN = (Nfrac>>10) | 0x0050000L |(arfcn<<20);
/*CMOSEDGE*/
/*CMOSEDGE*/         break;
/*CMOSEDGE*/      }
/*CMOSEDGE*/      case  FrequencyBand1800 :
/*CMOSEDGE*/      {
/*CMOSEDGE*/         if(arfcn<=735)
/*CMOSEDGE*/         {  if(arfcn<=605)
/*CMOSEDGE*/            {  if(arfcn<=540)
/*CMOSEDGE*/               {                                /* ARFCN : 512~540     */
/*CMOSEDGE*/                   Nfrac=((arfcn-512)&0x1) ? ((arfcn-513)>>1)*258111+4775054:((arfcn-512)>>1)*258111+4645998;
/*CMOSEDGE*/                   *rfN = (131L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/               else
/*CMOSEDGE*/               {                               /* ARFCN : 541~605     */
/*CMOSEDGE*/                   Nfrac=((arfcn-541)&0x1) ? ((arfcn-542)>>1)*258111+129056:((arfcn-541)>>1)*258111;
/*CMOSEDGE*/                   //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (132L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/            }
/*CMOSEDGE*/            else
/*CMOSEDGE*/            {  if(arfcn<=670)
/*CMOSEDGE*/               {                                /* ARFCN : 606~670     */
/*CMOSEDGE*/                   Nfrac=((arfcn-606)&0x1) ? ((arfcn-607)>>1)*258111+129056:((arfcn-606)>>1)*258111;
/*CMOSEDGE*/                   //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (133L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/               else
/*CMOSEDGE*/               {                                /* ARFCN : 671~735     */
/*CMOSEDGE*/                   Nfrac=((arfcn-671)&0x1) ? ((arfcn-672)>>1)*258111+129056:((arfcn-671)>>1)*258111;
/*CMOSEDGE*/                   //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (134L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/            }
/*CMOSEDGE*/         }
/*CMOSEDGE*/         else
/*CMOSEDGE*/         {  if(arfcn<=865)
/*CMOSEDGE*/            {  if(arfcn<=800)
/*CMOSEDGE*/               {                                /* ARFCN : 736~800     */
/*CMOSEDGE*/                   Nfrac=((arfcn-736)&0x1) ? ((arfcn-737)>>1)*258111+129056:((arfcn-736)>>1)*258111;
/*CMOSEDGE*/                   //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (135L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/                }
/*CMOSEDGE*/                else
/*CMOSEDGE*/                {                              /* ARFCN : 801~865     */
/*CMOSEDGE*/                   Nfrac=((arfcn-801)&0x1) ? ((arfcn-802)>>1)*258111+129056:((arfcn-801)>>1)*258111;
/*CMOSEDGE*/                   //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (136L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/                }
/*CMOSEDGE*/            }
/*CMOSEDGE*/            else
/*CMOSEDGE*/            {                              /* ARFCN : 866~885     */
/*CMOSEDGE*/                 Nfrac=((arfcn-866)&0x1) ? ((arfcn-867)>>1)*258111+129056:((arfcn-866)>>1)*258111;
/*CMOSEDGE*/                 //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                *rfN = (137L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/         }
/*CMOSEDGE*/         *ifN = (Nfrac>>10) | 0x0060000L |(arfcn<<20);
/*CMOSEDGE*/
/*CMOSEDGE*/         break;
/*CMOSEDGE*/      }
/*CMOSEDGE*/      case  FrequencyBand1900 :
/*CMOSEDGE*/      {
/*CMOSEDGE*/         if(arfcn<=685)
/*CMOSEDGE*/         {  if(arfcn<=620)
/*CMOSEDGE*/            {  if(arfcn<=555)
/*CMOSEDGE*/               {                                /* ARFCN : 512~555     */
/*CMOSEDGE*/                   Nfrac=((arfcn-512)&0x1) ? ((arfcn-513)>>1)*258111+2839221:((arfcn-512)>>1)*258111+2710166;
/*CMOSEDGE*/                   *rfN = (142L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/               else
/*CMOSEDGE*/               {                                /* ARFCN : 556~620     */
/*CMOSEDGE*/                   Nfrac=((arfcn-556)&0x1) ? ((arfcn-557)>>1)*258111+129056:((arfcn-556)>>1)*258111;
/*CMOSEDGE*/                   //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (143L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/               }
/*CMOSEDGE*/            }
/*CMOSEDGE*/            else
/*CMOSEDGE*/            {                              /* ARFCN : 621~685     */
/*CMOSEDGE*/                   Nfrac=((arfcn-621)&0x1) ? ((arfcn-622)>>1)*258111+129056:((arfcn-621)>>1)*258111;
/*CMOSEDGE*/                   //if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                   *rfN = (144L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/         }
/*CMOSEDGE*/         else
/*CMOSEDGE*/         {  if(arfcn<=750)
/*CMOSEDGE*/            {                                /* ARFCN : 686~750     */
/*CMOSEDGE*/                 Nfrac=((arfcn-686)&0x1) ? ((arfcn-687)>>1)*258111+129056:((arfcn-686)>>1)*258111;
/*CMOSEDGE*/                // if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                *rfN = (145L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/            else
/*CMOSEDGE*/            {                                /* ARFCN : 751~810     */
/*CMOSEDGE*/                 Nfrac=((arfcn-751)&0x1) ? ((arfcn-752)>>1)*258111+129056:((arfcn-751)>>1)*258111;
/*CMOSEDGE*/                // if (Nfrac==0) Nfrac=1;
/*CMOSEDGE*/                *rfN = (146L<<10) | (Nfrac&0x3FF) | 0x0100000L;
/*CMOSEDGE*/            }
/*CMOSEDGE*/         }
/*CMOSEDGE*/         *ifN = (Nfrac>>10) | 0x0070000L |(arfcn<<20);
/*CMOSEDGE*/
/*CMOSEDGE*/         break;
/*CMOSEDGE*/      }
/*CMOSEDGE*/      default :
/*CMOSEDGE*/      {
/*CMOSEDGE*/         break;
/*CMOSEDGE*/      }
/*CMOSEDGE*/   }
/*CMOSEDGE*/}
/*CMOSEDGE*//* =========================================================================== */
#endif

#if IS_RF_MTKSOC1T
/*MTKSOC1T*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MTKSOC1T*/{
/*MTKSOC1T*/ int Nfrac, SDM_IFM = 1, OPLL_DIV4O5_DIV4 = 0;
/*MTKSOC1T*/ long cw27 =0;
/*MTKSOC1T*/ switch(rf_band)
/*MTKSOC1T*/ {
/*MTKSOC1T*/ case  FrequencyBand850 :
/*MTKSOC1T*/    {
/*MTKSOC1T*/       if(arfcn<=189)
/*MTKSOC1T*/       {
/*MTKSOC1T*/          if(arfcn<=160)
/*MTKSOC1T*/          {
/*MTKSOC1T*/             if(arfcn<=131)
/*MTKSOC1T*/             {                                /* ARFCN : 128~131     */
/*MTKSOC1T*/                Nfrac = (arfcn-128)*286790 + 7456540;
/*MTKSOC1T*/                *rfN = (140L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/             }
/*MTKSOC1T*/             else
/*MTKSOC1T*/             {                                /* ARFCN : 132~160     */
/*MTKSOC1T*/                Nfrac = (arfcn-132)*286790 + 215093;
/*MTKSOC1T*/                *rfN = (141L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/             }
/*MTKSOC1T*/          }
/*MTKSOC1T*/          else
/*MTKSOC1T*/          {                              /* ARFCN : 161~189     */
/*MTKSOC1T*/             Nfrac = (arfcn-161)*286790 + 143395;
/*MTKSOC1T*/             *rfN = (142L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/          }
/*MTKSOC1T*/       }
/*MTKSOC1T*/       else
/*MTKSOC1T*/       {
/*MTKSOC1T*/          if(arfcn<=218)
/*MTKSOC1T*/          {                              /* ARFCN : 190~218     */
/*MTKSOC1T*/             Nfrac = (arfcn-190)*286790 + 71698;
/*MTKSOC1T*/             *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/          }
/*MTKSOC1T*/          else
/*MTKSOC1T*/          {
/*MTKSOC1T*/             if(arfcn<=248)
/*MTKSOC1T*/             {                                /* ARFCN : 219~248     */
/*MTKSOC1T*/                Nfrac = (arfcn-219)*286790;
/*MTKSOC1T*/                *rfN = (144L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/
/*MTKSOC1T*/                if(arfcn == 219)
/*MTKSOC1T*/                   SDM_IFM = 0;
/*MTKSOC1T*/             }
/*MTKSOC1T*/             else
/*MTKSOC1T*/             {                                /* ARFCN : 249~251     */
/*MTKSOC1T*/                Nfrac = (arfcn-249)*286790 + 215093;
/*MTKSOC1T*/                *rfN = (145L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/             }
/*MTKSOC1T*/          }
/*MTKSOC1T*/       }
/*MTKSOC1T*/
/*MTKSOC1T*/       *ifN = (Nfrac>>10) | 0x0242000L;                       /* N_FRAC[22:10] | (CW2|OPLL_DIV4O5_DIV4|TRX|BAND|MODE(warm_up mode))*/
/*MTKSOC1T*/       *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1T*/
/*MTKSOC1T*/       break;
/*MTKSOC1T*/    }
/*MTKSOC1T*/ case  FrequencyBand900 :
/*MTKSOC1T*/    {
/*MTKSOC1T*/       if(arfcn<=112)
/*MTKSOC1T*/       {
/*MTKSOC1T*/          if(arfcn<=54)
/*MTKSOC1T*/          {
/*MTKSOC1T*/             if(arfcn<=25)
/*MTKSOC1T*/             {                                /* ARFCN : 0~25     */
/*MTKSOC1T*/                Nfrac = (arfcn)*286790 + 1147160;
/*MTKSOC1T*/                *rfN = (152L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/             }
/*MTKSOC1T*/             else
/*MTKSOC1T*/             {                                /* ARFCN : 26~54     */
/*MTKSOC1T*/                Nfrac = (arfcn-26)*286790 + 215093;
/*MTKSOC1T*/                *rfN = (153L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/             }
/*MTKSOC1T*/          }
/*MTKSOC1T*/          else
/*MTKSOC1T*/          {
/*MTKSOC1T*/             if(arfcn<=83)
/*MTKSOC1T*/             {                                /* ARFCN : 55~83     */
/*MTKSOC1T*/                Nfrac = (arfcn-55)*286790 + 143395;
/*MTKSOC1T*/                *rfN = (154L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/             }
/*MTKSOC1T*/             else
/*MTKSOC1T*/             {                                /* ARFCN : 84~112     */
/*MTKSOC1T*/                Nfrac = (arfcn-84)*286790 + 71698;
/*MTKSOC1T*/                *rfN = (155L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/             }
/*MTKSOC1T*/          }
/*MTKSOC1T*/       }
/*MTKSOC1T*/       else
/*MTKSOC1T*/       {
/*MTKSOC1T*/          if(arfcn<=990)
/*MTKSOC1T*/          {
/*MTKSOC1T*/             if(arfcn<=124)
/*MTKSOC1T*/             {                                /* ARFCN : 113~124     */
/*MTKSOC1T*/                Nfrac = (arfcn-113)*286790;
/*MTKSOC1T*/                *rfN = (156L<<10);
/*MTKSOC1T*/
/*MTKSOC1T*/                if(arfcn == 113)
/*MTKSOC1T*/                   SDM_IFM = 0;
/*MTKSOC1T*/
/*MTKSOC1T*/             }
/*MTKSOC1T*/             else
/*MTKSOC1T*/             {                              /* ARFCN : 975~990     */
/*MTKSOC1T*/                Nfrac = (arfcn-975)*286790 + 3871665;
/*MTKSOC1T*/                *rfN = (150L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/             }
/*MTKSOC1T*/          }
/*MTKSOC1T*/          else
/*MTKSOC1T*/          {
/*MTKSOC1T*/             if(arfcn<=1019)
/*MTKSOC1T*/             {                                /* ARFCN : 991~1019     */
/*MTKSOC1T*/                Nfrac = (arfcn-991)*286790 + 71698;
/*MTKSOC1T*/                *rfN = (151L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/             }
/*MTKSOC1T*/             else
/*MTKSOC1T*/             {                                /* ARFCN : 1020~1023     */
/*MTKSOC1T*/                Nfrac = (arfcn-1020)*286790;
/*MTKSOC1T*/                *rfN = (152L<<10);
/*MTKSOC1T*/
/*MTKSOC1T*/                if(arfcn == 1020)
/*MTKSOC1T*/                   SDM_IFM = 0;
/*MTKSOC1T*/             }
/*MTKSOC1T*/          }
/*MTKSOC1T*/       }
/*MTKSOC1T*/       *ifN = (Nfrac>>10) | 0x0252000L;                       /* N_FRAC[22:10] | (CW2|OPLL_DIV4O5_DIV4|TRX|BAND|MODE(warm_up mode))*/
/*MTKSOC1T*/       *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1T*/
/*MTKSOC1T*/       break;
/*MTKSOC1T*/    }
/*MTKSOC1T*/ case  FrequencyBand1800 :
/*MTKSOC1T*/    {
/*MTKSOC1T*/       if(arfcn<=670)
/*MTKSOC1T*/       {
/*MTKSOC1T*/          if(arfcn<=603)
/*MTKSOC1T*/          {
/*MTKSOC1T*/             if(arfcn<=547)
/*MTKSOC1T*/             {
/*MTKSOC1T*/                if(arfcn<=541)
/*MTKSOC1T*/                { /* ARFCN : 512~541 */
/*MTKSOC1T*/                   Nfrac = (arfcn-529)*135848 + 6316927;
/*MTKSOC1T*/                   *rfN = (138L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/
/*MTKSOC1T*/                   /*error compensation*/
/*MTKSOC1T*/                    L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 0, 0, 519, 529, 540, 542);
/*MTKSOC1T*/                   /*End: error compensation*/
/*MTKSOC1T*/
/*MTKSOC1T*/                }
/*MTKSOC1T*/                else
/*MTKSOC1T*/                { /* ARFCN : 542~547 */
/*MTKSOC1T*/                   Nfrac = (arfcn-542)*137659 + 6848546;
/*MTKSOC1T*/                   *rfN = (140L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/                   OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1T*/
/*MTKSOC1T*/                   /*error compensation*/
/*MTKSOC1T*/                   if(arfcn>=547)
/*MTKSOC1T*/                      Nfrac++;
/*MTKSOC1T*/                   /*End: error compensation*/
/*MTKSOC1T*/
/*MTKSOC1T*/                }
/*MTKSOC1T*/
/*MTKSOC1T*/             }
/*MTKSOC1T*/             else
/*MTKSOC1T*/             { /* ARFCN : 548~603 */
/*MTKSOC1T*/                Nfrac = (arfcn-581)*135848 + 4992410;
/*MTKSOC1T*/                *rfN = (139L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/
/*MTKSOC1T*/                /*error compensation*/
/*MTKSOC1T*/                L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 550, 560, 570, 581, 591, 601);
/*MTKSOC1T*/                /*End: error compensation*/
/*MTKSOC1T*/
/*MTKSOC1T*/             }
/*MTKSOC1T*/          }
/*MTKSOC1T*/          else
/*MTKSOC1T*/          {
/*MTKSOC1T*/             if(arfcn<=665)
/*MTKSOC1T*/             {
/*MTKSOC1T*/                if(arfcn<=608)
/*MTKSOC1T*/                { /* ARFCN : 604~608 */
/*MTKSOC1T*/                   Nfrac = (arfcn-604)*137659 + 6994809;
/*MTKSOC1T*/                   *rfN = (141L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/                   OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1T*/
/*MTKSOC1T*/                   /*error compensation*/
/*MTKSOC1T*/                   /*End: error compensation*/
/*MTKSOC1T*/                }
/*MTKSOC1T*/                else
/*MTKSOC1T*/                { /* ARFCN : 609~665 */
/*MTKSOC1T*/                   Nfrac = (arfcn-643)*135848 + 5026372;
/*MTKSOC1T*/                   *rfN = (140L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/
/*MTKSOC1T*/                   /*error compensation*/
/*MTKSOC1T*/                   L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 612, 622, 632, 643, 653, 663);
/*MTKSOC1T*/                   /*End: error compensation*/
/*MTKSOC1T*/                }
/*MTKSOC1T*/             }
/*MTKSOC1T*/             else
/*MTKSOC1T*/             { /* ARFCN : 666~670 */
/*MTKSOC1T*/                Nfrac = (arfcn-666)*137659 + 7141071;
/*MTKSOC1T*/                *rfN = (142L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/                OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1T*/
/*MTKSOC1T*/                /*error compensation*/
/*MTKSOC1T*/                if(arfcn>=667)
/*MTKSOC1T*/                   Nfrac++;
/*MTKSOC1T*/                /*End: error compensation*/
/*MTKSOC1T*/             }
/*MTKSOC1T*/          }
/*MTKSOC1T*/       }
/*MTKSOC1T*/       else
/*MTKSOC1T*/       {
/*MTKSOC1T*/          if(arfcn<=788)
/*MTKSOC1T*/          {
/*MTKSOC1T*/             if(arfcn<=732)
/*MTKSOC1T*/             {
/*MTKSOC1T*/                if(arfcn<=726)
/*MTKSOC1T*/                {/* ARFCN : 671~726 */
/*MTKSOC1T*/                   Nfrac = (arfcn-704)*135848 + 4924486;
/*MTKSOC1T*/                   *rfN = (141L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/
/*MTKSOC1T*/                   /*error compensation*/
/*MTKSOC1T*/                   L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 673, 684, 694, 704, 715, 725);
/*MTKSOC1T*/                   /*End: error compensation*/
/*MTKSOC1T*/                }
/*MTKSOC1T*/                else
/*MTKSOC1T*/                {/*ARFCN:727~732*/
/*MTKSOC1T*/                   Nfrac = (arfcn-727)*137659 + 7149675;
/*MTKSOC1T*/                   *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/                   OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1T*/
/*MTKSOC1T*/                   /*error compensation*/
/*MTKSOC1T*/                   if(arfcn>=729)
/*MTKSOC1T*/                      Nfrac++;
/*MTKSOC1T*/                   /*End: error compensation*/
/*MTKSOC1T*/
/*MTKSOC1T*/                }
/*MTKSOC1T*/             }
/*MTKSOC1T*/             else
/*MTKSOC1T*/             {/*ARFCN:733~788*/
/*MTKSOC1T*/                Nfrac = (arfcn-766)*135848 + 4958448;
/*MTKSOC1T*/                *rfN = (142L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/
/*MTKSOC1T*/                /*error compensation*/
/*MTKSOC1T*/                L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 735, 745, 756, 766, 776, 786);
/*MTKSOC1T*/                /*End: error compensation*/
/*MTKSOC1T*/             }
/*MTKSOC1T*/          }
/*MTKSOC1T*/          else
/*MTKSOC1T*/          {
/*MTKSOC1T*/             if(arfcn<=850)
/*MTKSOC1T*/             {
/*MTKSOC1T*/                if(arfcn<=794)
/*MTKSOC1T*/                {/*ARFCN:789~794*/
/*MTKSOC1T*/                   Nfrac = (arfcn-789)*137659 + 7295938;
/*MTKSOC1T*/                   *rfN = (144L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/                   OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1T*/
/*MTKSOC1T*/                   /*error compensation*/
/*MTKSOC1T*/                   if(arfcn>=792)
/*MTKSOC1T*/                      Nfrac++;
/*MTKSOC1T*/                   /*End: error compensation*/
/*MTKSOC1T*/                }
/*MTKSOC1T*/                else
/*MTKSOC1T*/                {/*ARFCN:795~850*/
/*MTKSOC1T*/                   Nfrac = (arfcn-828)*135848 + 4992410;
/*MTKSOC1T*/                   *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/                   /*error compensation*/
/*MTKSOC1T*/                   L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 797, 806, 817, 828, 838, 848);
/*MTKSOC1T*/                   /*End:*error compensation*/
/*MTKSOC1T*/                }
/*MTKSOC1T*/             }
/*MTKSOC1T*/             else
/*MTKSOC1T*/             {
/*MTKSOC1T*/                if(arfcn<=855)
/*MTKSOC1T*/                {/*ARFCN:851~855*/
/*MTKSOC1T*/                   Nfrac = (arfcn-851)*137659 + 7442201;
/*MTKSOC1T*/                   *rfN = (145L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/                   OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1T*/
/*MTKSOC1T*/                   /*error compensation*/
/*MTKSOC1T*/                   if(arfcn>=854)
/*MTKSOC1T*/                      Nfrac++;
/*MTKSOC1T*/                   /*End: error compensation*/
/*MTKSOC1T*/                }
/*MTKSOC1T*/                else
/*MTKSOC1T*/                {/*ARFCN:856~885*/
/*MTKSOC1T*/                   Nfrac = (arfcn-869)*135848 + 2173566;
/*MTKSOC1T*/                   *rfN = (144L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/
/*MTKSOC1T*/                   /*error compensation*/
/*MTKSOC1T*/                   L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 0, 0, 859, 869, 879, 885);
/*MTKSOC1T*/                   /*End: error compensation*/
/*MTKSOC1T*/                }
/*MTKSOC1T*/             }
/*MTKSOC1T*/          }
/*MTKSOC1T*/       }
/*MTKSOC1T*/       *ifN = (Nfrac>>10) | 0x0262000L | (OPLL_DIV4O5_DIV4<<19);                       /* N_FRAC[22:10] | (CW2|OPLL_DIV4O5_DIV4|TRX|BAND|MODE(warm_up mode))*/
/*MTKSOC1T*/       *rfN |= ((Nfrac&0x3FF) | 0x01C0000L); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1T*/       break;
/*MTKSOC1T*/      }
/*MTKSOC1T*/      case  FrequencyBand1900 :
/*MTKSOC1T*/      {
/*MTKSOC1T*/         if(arfcn<=676)
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(arfcn<=546)
/*MTKSOC1T*/            {
/*MTKSOC1T*/               if(arfcn<=540)
/*MTKSOC1T*/               { /*ARFCN:512~540*/
/*MTKSOC1T*/                  Nfrac = (arfcn-512)*122910 + 4578398;
/*MTKSOC1T*/                  *rfN = (135L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/               else
/*MTKSOC1T*/               { /*ARFCN:541~546*/
/*MTKSOC1T*/                  Nfrac = (arfcn-541)*121464 + 3112515;
/*MTKSOC1T*/                  *rfN = (134L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/                  OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1T*/               }
/*MTKSOC1T*/            }
/*MTKSOC1T*/            else
/*MTKSOC1T*/            {
/*MTKSOC1T*/               if(arfcn<=614)
/*MTKSOC1T*/               {
/*MTKSOC1T*/                  if(arfcn<=608)
/*MTKSOC1T*/                  { /*ARFCN:547~608*/
/*MTKSOC1T*/                     Nfrac = (arfcn-547)*122910 + 491640;
/*MTKSOC1T*/                     *rfN = (136L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/                  }
/*MTKSOC1T*/                  else
/*MTKSOC1T*/                  { /*ARFCN:609~614*/
/*MTKSOC1T*/                     Nfrac = (arfcn-609)*121464 + 2983460;
/*MTKSOC1T*/                     *rfN = (135L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/                     OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1T*/                  }
/*MTKSOC1T*/               }
/*MTKSOC1T*/               else
/*MTKSOC1T*/               { /*ARFCN:615~676*/
/*MTKSOC1T*/                  Nfrac = (arfcn-615)*122910 + 460913;
/*MTKSOC1T*/                  *rfN = (137L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/            }
/*MTKSOC1T*/         }
/*MTKSOC1T*/         else
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(arfcn<=744)
/*MTKSOC1T*/            {
/*MTKSOC1T*/               if(arfcn<=682)
/*MTKSOC1T*/               {/*ARFCN:677~682*/
/*MTKSOC1T*/                  Nfrac = (arfcn-677)*121464 + 2854404;
/*MTKSOC1T*/                  *rfN = (136L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/                  OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1T*/               }
/*MTKSOC1T*/               else
/*MTKSOC1T*/               { /*ARFCN:683~744*/
/*MTKSOC1T*/                  Nfrac = (arfcn-683)*122910 + 430185;
/*MTKSOC1T*/                  *rfN = (138L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/            }
/*MTKSOC1T*/            else
/*MTKSOC1T*/            {
/*MTKSOC1T*/               if(arfcn<=750)
/*MTKSOC1T*/               {/*ARFCN:745~750*/
/*MTKSOC1T*/                  Nfrac = (arfcn-745)*121464 + 2725349;
/*MTKSOC1T*/                  *rfN = (137L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/                  OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1T*/               }
/*MTKSOC1T*/               else
/*MTKSOC1T*/               { /*ARFCN:751~810*/
/*MTKSOC1T*/                  Nfrac = (arfcn-751)*122910 + 399458;
/*MTKSOC1T*/                  *rfN = (139L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/            }
/*MTKSOC1T*/         }
/*MTKSOC1T*/
/*MTKSOC1T*/         *ifN = (Nfrac>>10) | 0x0272000L | (OPLL_DIV4O5_DIV4<<19);                       /* N_FRAC[22:10] | (CW2|OPLL_DIV4O5_DIV4|TRX|BAND|MODE(warm_up mode))*/
/*MTKSOC1T*/         *rfN |= ((Nfrac&0x3FF) | 0x0140000L); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1T*/         break;
/*MTKSOC1T*/      }
/*MTKSOC1T*/      default :
/*MTKSOC1T*/      {
/*MTKSOC1T*/         break;
/*MTKSOC1T*/      }
/*MTKSOC1T*/   }
/*MTKSOC1T*/   /*For CW27*/
/*MTKSOC1T*/   L1D_RF_GetTX_SX_CAL_FBX_Setting(arfcn, rf_band, &cw27, MTKSOC1_SX_CAL_DMD_T, ((*ifN>>19) & 0x1) );
/*MTKSOC1T*/   *ifN |= ( ( cw27     & 0x7F) << 25);
/*MTKSOC1T*/   *rfN |= ( ((cw27>>7) & 0x3F) << 25);
/*MTKSOC1T*/}
/*MTKSOC1T*//* =============================================================== */
/*MTKSOC1T*/
/*MTKSOC1T*/void L1D_RF_Band1800_FrequecyFractionPartCompensation(int arfcn, int *Nfrac, short arfcn1, short arfcn2, short arfcn3, short arfcn4, short arfcn5, short arfcn6)
/*MTKSOC1T*/{
/*MTKSOC1T*/ if(arfcn<arfcn4)
/*MTKSOC1T*/ {
/*MTKSOC1T*/    if(arfcn<arfcn2)
/*MTKSOC1T*/    {
/*MTKSOC1T*/       if(arfcn<arfcn1)
/*MTKSOC1T*/          *Nfrac+=4;
/*MTKSOC1T*/       else
/*MTKSOC1T*/          *Nfrac+=3;
/*MTKSOC1T*/    }
/*MTKSOC1T*/    else
/*MTKSOC1T*/    {
/*MTKSOC1T*/       if(arfcn<arfcn3)
/*MTKSOC1T*/          *Nfrac+=2;
/*MTKSOC1T*/       else
/*MTKSOC1T*/          *Nfrac+=1;
/*MTKSOC1T*/    }
/*MTKSOC1T*/ }
/*MTKSOC1T*/ else if (arfcn>=arfcn5)
/*MTKSOC1T*/ {
/*MTKSOC1T*/    if(arfcn<arfcn6)
/*MTKSOC1T*/    {
/*MTKSOC1T*/       *Nfrac-=1;
/*MTKSOC1T*/    }
/*MTKSOC1T*/    else
/*MTKSOC1T*/    {
/*MTKSOC1T*/       *Nfrac-=2;
/*MTKSOC1T*/    }
/*MTKSOC1T*/ }
/*MTKSOC1T*/}
/*MTKSOC1T*/
/*MTKSOC1T*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MTKSOC1T*/{
/*MTKSOC1T*/   int Nfrac, SDM_IFM = 1;
/*MTKSOC1T*/ long cw27 = 0;
/*MTKSOC1T*/   switch(rf_band)
/*MTKSOC1T*/   {
/*MTKSOC1T*/   case  FrequencyBand850 :
/*MTKSOC1T*/      {
/*MTKSOC1T*/         if(arfcn<=201)
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(arfcn<=169)
/*MTKSOC1T*/            {
/*MTKSOC1T*/               if(arfcn<=136)
/*MTKSOC1T*/               {/*arfcn:128~136*/
/*MTKSOC1T*/                  Nfrac = (arfcn-128)*258111 + 6065609;
/*MTKSOC1T*/                  *rfN = (133L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/               else
/*MTKSOC1T*/               {/*arfcn:137~169*/
/*MTKSOC1T*/                  Nfrac = (arfcn-137)*258111;
/*MTKSOC1T*/                  *rfN = (134L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/            }
/*MTKSOC1T*/            else
/*MTKSOC1T*/            {/*arfcn:170~201*/
/*MTKSOC1T*/               Nfrac = (arfcn-170)*258111+129056;
/*MTKSOC1T*/               *rfN = (135L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/            }
/*MTKSOC1T*/         }
/*MTKSOC1T*/         else
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(arfcn<=234)
/*MTKSOC1T*/            {/*arfcn:202~234*/
/*MTKSOC1T*/               Nfrac = (arfcn-202)*258111;
/*MTKSOC1T*/               *rfN = (136L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/            }
/*MTKSOC1T*/            else
/*MTKSOC1T*/            {/*arfcn:235~251*/
/*MTKSOC1T*/               Nfrac = (arfcn-235)*258111+129056;
/*MTKSOC1T*/               *rfN = (137L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/            }
/*MTKSOC1T*/         }
/*MTKSOC1T*/         *ifN = (Nfrac>>10)|0x0202000;  /* CW2, TRX:0, BAND:0, MODE:1, N_RFC[22:10]*/
/*MTKSOC1T*/         if(Nfrac==0) SDM_IFM = 0;
/*MTKSOC1T*/         *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1T*/
/*MTKSOC1T*/         // Get GSM850 signal from GSM900 input pins if flag=1
/*MTKSOC1T*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap ) *ifN |=0x0010000L ;
/*MTKSOC1T*/         break;
/*MTKSOC1T*/      }
/*MTKSOC1T*/   case  FrequencyBand900 :
/*MTKSOC1T*/      {
/*MTKSOC1T*/         if(arfcn<=102)
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(arfcn<=37)
/*MTKSOC1T*/            {
/*MTKSOC1T*/               if(arfcn<=4)
/*MTKSOC1T*/               {/*arfcn:0~4*/
/*MTKSOC1T*/                  Nfrac = (arfcn)*258111+7098053;
/*MTKSOC1T*/                  *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/               else
/*MTKSOC1T*/               {/*arfcn:5~37*/
/*MTKSOC1T*/                  Nfrac = (arfcn-5)*258111;
/*MTKSOC1T*/                  *rfN = (144L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/            }
/*MTKSOC1T*/            else
/*MTKSOC1T*/            {
/*MTKSOC1T*/               if(arfcn<=69)
/*MTKSOC1T*/               {/*arfcn:38~69*/
/*MTKSOC1T*/                  Nfrac = (arfcn-38)*258111+129056;
/*MTKSOC1T*/                  *rfN = (145L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/               else
/*MTKSOC1T*/               {/*arfcn:70~102*/
/*MTKSOC1T*/                  Nfrac = (arfcn-70)*258111;
/*MTKSOC1T*/                  *rfN = (146L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/            }
/*MTKSOC1T*/         }
/*MTKSOC1T*/         else
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(arfcn<=996)
/*MTKSOC1T*/            {
/*MTKSOC1T*/               if(arfcn<=124)
/*MTKSOC1T*/               {/*arfcn:103~124*/
/*MTKSOC1T*/                  Nfrac = (arfcn-103)*258111+129056;
/*MTKSOC1T*/                  *rfN = (147L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/               else
/*MTKSOC1T*/               {/*arfcn:975~996*/
/*MTKSOC1T*/                  Nfrac = (arfcn-975)*258111+2839221;
/*MTKSOC1T*/                  *rfN = (142L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/            }
/*MTKSOC1T*/            else
/*MTKSOC1T*/            {/*arfcn:997~1023*/
/*MTKSOC1T*/               Nfrac = (arfcn-997)*258111+129056;
/*MTKSOC1T*/               *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/            }
/*MTKSOC1T*/         }
/*MTKSOC1T*/
/*MTKSOC1T*/         *ifN = (Nfrac>>10)|0x0212000;  /* CW2, TRX:0, BAND:1, MODE:1, N_RFC[22:10]*/
/*MTKSOC1T*/
/*MTKSOC1T*/         if(Nfrac==0) SDM_IFM = 0;
/*MTKSOC1T*/         *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1T*/
/*MTKSOC1T*/         // Get GSM900 signal from GSM850 input pins if flag=1
/*MTKSOC1T*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap )  *ifN &= (~(0x0010000L));
/*MTKSOC1T*/         break;
/*MTKSOC1T*/      }
/*MTKSOC1T*/   case  FrequencyBand1800 :
/*MTKSOC1T*/      {
/*MTKSOC1T*/         if(arfcn<=715)
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(arfcn<=585)
/*MTKSOC1T*/            {
/*MTKSOC1T*/               if(arfcn<=520)
/*MTKSOC1T*/               {/*arfcn:512~520*/
/*MTKSOC1T*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 456);
/*MTKSOC1T*/                  *rfN = (138L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/               else
/*MTKSOC1T*/               {/*arfcn:521~585*/
/*MTKSOC1T*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 521);
/*MTKSOC1T*/                  *rfN = (139L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/            }
/*MTKSOC1T*/            else
/*MTKSOC1T*/            {
/*MTKSOC1T*/               if(arfcn<=650)
/*MTKSOC1T*/               {/*arfcn:586~650*/
/*MTKSOC1T*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 586);
/*MTKSOC1T*/                  *rfN = (140L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/               else
/*MTKSOC1T*/               {/*arfcn:651~715*/
/*MTKSOC1T*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 651);
/*MTKSOC1T*/                  *rfN = (141L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/            }
/*MTKSOC1T*/         }
/*MTKSOC1T*/         else
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(arfcn<=845)
/*MTKSOC1T*/            {
/*MTKSOC1T*/               if(arfcn<=780)
/*MTKSOC1T*/               {/*arfcn:716~780*/
/*MTKSOC1T*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 716);
/*MTKSOC1T*/                  *rfN = (142L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/               else
/*MTKSOC1T*/               {/*arfcn:781~845*/
/*MTKSOC1T*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 781);
/*MTKSOC1T*/                  *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/            }
/*MTKSOC1T*/            else
/*MTKSOC1T*/            {/*arfcn:846~885*/
/*MTKSOC1T*/               L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 846);
/*MTKSOC1T*/               *rfN = (144L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/            }
/*MTKSOC1T*/         }
/*MTKSOC1T*/
/*MTKSOC1T*/
/*MTKSOC1T*/         *ifN = (Nfrac>>10)|0x0222000;  /* CW2, TRX:0, BAND:2, MODE:1, N_RFC[22:10]*/
/*MTKSOC1T*/
/*MTKSOC1T*/         if(Nfrac==0) SDM_IFM = 0;
/*MTKSOC1T*/         *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1T*/
/*MTKSOC1T*/         // Get PCS1900 signal from DCS1800 input pins if flag=1
/*MTKSOC1T*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap ) *ifN |=0x0010000L ;
/*MTKSOC1T*/         break;
/*MTKSOC1T*/      }
/*MTKSOC1T*/   case  FrequencyBand1900 :
/*MTKSOC1T*/      {
/*MTKSOC1T*/         if(arfcn<=675)
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(arfcn<=610)
/*MTKSOC1T*/            {
/*MTKSOC1T*/               if(arfcn<=545)
/*MTKSOC1T*/               {/*arfcn:512~545*/
/*MTKSOC1T*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 481);
/*MTKSOC1T*/                  *rfN = (148L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/               else
/*MTKSOC1T*/               {/*arfcn:546~610*/
/*MTKSOC1T*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 546);
/*MTKSOC1T*/                  *rfN = (149L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/            }
/*MTKSOC1T*/            else
/*MTKSOC1T*/            {/*arfcn:611~675*/
/*MTKSOC1T*/               L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 611);
/*MTKSOC1T*/               *rfN = (150L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/            }
/*MTKSOC1T*/         }
/*MTKSOC1T*/         else
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(arfcn<=805)
/*MTKSOC1T*/            {
/*MTKSOC1T*/               if(arfcn<=740)
/*MTKSOC1T*/               {/*arfcn:676~740*/
/*MTKSOC1T*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 676);
/*MTKSOC1T*/                  *rfN = (151L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/               else
/*MTKSOC1T*/               {/*arfcn:741~805*/
/*MTKSOC1T*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 741);
/*MTKSOC1T*/                  *rfN = (152L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/               }
/*MTKSOC1T*/            }
/*MTKSOC1T*/            else
/*MTKSOC1T*/            {/*arfcn:806~810*/
/*MTKSOC1T*/               L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 806);
/*MTKSOC1T*/               *rfN = (153L<<10); /* N_INT[7:0]*/
/*MTKSOC1T*/            }
/*MTKSOC1T*/         }
/*MTKSOC1T*/
/*MTKSOC1T*/         *ifN = (Nfrac>>10)|0x0232000;  /* CW2, TRX:0, BAND:2, MODE:1, N_RFC[22:10]*/
/*MTKSOC1T*/
/*MTKSOC1T*/         if(Nfrac==0) SDM_IFM = 0;
/*MTKSOC1T*/         *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1T*/         // Get DCS1800 signal from PCS1900 input pins if flag=1
/*MTKSOC1T*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap)  *ifN &= (~(0x0010000L));
/*MTKSOC1T*/         break;
/*MTKSOC1T*/      }
/*MTKSOC1T*/   default :
/*MTKSOC1T*/      {
/*MTKSOC1T*/         break;
/*MTKSOC1T*/      }
/*MTKSOC1T*/   }
/*MTKSOC1T*/   L1D_RF_GetRX_SX_CAL_FBX_Setting(arfcn, rf_band, &cw27, MTKSOC1_SX_CAL_DMD_T);
/*MTKSOC1T*/   *ifN |= ( ( cw27     & 0x7F) << 25);
/*MTKSOC1T*/   *rfN |= ( ((cw27>>7) & 0x3F) << 25);
/*MTKSOC1T*/}
/*MTKSOC1T*//* =============================================================== */
/*MTKSOC1T*/
/*MTKSOC1T*/void L1D_RF_GetRxPLL_HB_FractionPart(int *Nfrac, int arfcn, int arfcn_base)
/*MTKSOC1T*/{
/*MTKSOC1T*/   int Diff_arfcn;
/*MTKSOC1T*/
/*MTKSOC1T*/   Diff_arfcn = arfcn - arfcn_base;
/*MTKSOC1T*/   *Nfrac = (Diff_arfcn >>1) * 258111;
/*MTKSOC1T*/   if(Diff_arfcn & 0x1) *Nfrac += 129056;
/*MTKSOC1T*/}
/*MTKSOC1T*/
/*MTKSOC1T*//*output: CW27 */
/*MTKSOC1T*/void L1D_RF_GetRX_SX_CAL_FBX_Setting(int arfcn, int rf_band, long *cw27, short sx_cal_dmd_t)
/*MTKSOC1T*/{
/*MTKSOC1T*/ int N_sx_cal_fbx = 0;
/*MTKSOC1T*/ if( !MTKSOC1_SX_CALSBA )
/*MTKSOC1T*/ {
/*MTKSOC1T*/     *cw27 = 0;
/*MTKSOC1T*/      return;
/*MTKSOC1T*/ }
/*MTKSOC1T*/   if(sx_cal_dmd_t)
/*MTKSOC1T*/   {
/*MTKSOC1T*/      switch(rf_band)
/*MTKSOC1T*/      {
/*MTKSOC1T*/      case  FrequencyBand850 :
/*MTKSOC1T*/         {
/*MTKSOC1T*/            N_sx_cal_fbx = 468 + arfcn;
/*MTKSOC1T*/            break;
/*MTKSOC1T*/         }
/*MTKSOC1T*/      case  FrequencyBand900 :
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(arfcn<=124)
/*MTKSOC1T*/               N_sx_cal_fbx = 925 + arfcn;
/*MTKSOC1T*/            else
/*MTKSOC1T*/               N_sx_cal_fbx = -99 + arfcn;
/*MTKSOC1T*/
/*MTKSOC1T*/            break;
/*MTKSOC1T*/         }
/*MTKSOC1T*/      case  FrequencyBand1800 :
/*MTKSOC1T*/         {
/*MTKSOC1T*/            N_sx_cal_fbx = 251- ( (arfcn-512)>>1 )+ arfcn;
/*MTKSOC1T*/            break;
/*MTKSOC1T*/         }
/*MTKSOC1T*/      case  FrequencyBand1900 :
/*MTKSOC1T*/         {
/*MTKSOC1T*/            N_sx_cal_fbx = 564- ( (arfcn-511)>>1 )+ arfcn;
/*MTKSOC1T*/            break;
/*MTKSOC1T*/         }
/*MTKSOC1T*/      default:
/*MTKSOC1T*/         break;
/*MTKSOC1T*/      }
/*MTKSOC1T*/
/*MTKSOC1T*/   }
/*MTKSOC1T*/   else
/*MTKSOC1T*/   {
/*MTKSOC1T*/      switch(rf_band)
/*MTKSOC1T*/      {
/*MTKSOC1T*/      case  FrequencyBand850 :
/*MTKSOC1T*/         {
/*MTKSOC1T*/            N_sx_cal_fbx = (int)( 348+ 1+ arfcn - (arfcn-130 +5)/5 ); /* 1- 5/5 =0 */
/*MTKSOC1T*/            break;
/*MTKSOC1T*/         }
/*MTKSOC1T*/      case  FrequencyBand900 :
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(arfcn<=124)
/*MTKSOC1T*/            {
/*MTKSOC1T*/               N_sx_cal_fbx = (int)( 739+ 1+ arfcn -(arfcn-3+5)/5 ); /* 1- 5/5 =0 */
/*MTKSOC1T*/            }
/*MTKSOC1T*/            else
/*MTKSOC1T*/            {
/*MTKSOC1T*/               N_sx_cal_fbx = (int)( -275+ 1+ arfcn -(arfcn-977+5)/5 ); /* 1- 5/5 =0 */
/*MTKSOC1T*/            }
/*MTKSOC1T*/            break;
/*MTKSOC1T*/         }
/*MTKSOC1T*/      case  FrequencyBand1800 :
/*MTKSOC1T*/         {
/*MTKSOC1T*/            N_sx_cal_fbx = (int)( 98+ arfcn- ( (arfcn-512)/5 )*3 - ( ( (arfcn-512)%5 )>>1 ) );
/*MTKSOC1T*/            break;
/*MTKSOC1T*/         }
/*MTKSOC1T*/      case  FrequencyBand1900 :
/*MTKSOC1T*/         {
/*MTKSOC1T*/            N_sx_cal_fbx = (int)( 348+ arfcn- ( (arfcn-512)/5 )*3 - ( ( (arfcn-512)%5 )>>1 ) );
/*MTKSOC1T*/            break;
/*MTKSOC1T*/         }
/*MTKSOC1T*/      default:
/*MTKSOC1T*/         break;
/*MTKSOC1T*/      }
/*MTKSOC1T*/
/*MTKSOC1T*/   }
/*MTKSOC1T*/ *cw27 = 0x1b00001L | (N_sx_cal_fbx<<2) | (sx_cal_dmd_t<<1); /*CW27 | sx_cal_fbx | sx_cal_dmd_t | sx_calsba*/
/*MTKSOC1T*/}
/*MTKSOC1T*/
/*MTKSOC1T*//*output: CW27 */
/*MTKSOC1T*/void L1D_RF_GetTX_SX_CAL_FBX_Setting(int arfcn, int rf_band, long *cw27, short sx_cal_dmd_t, short OPLL_DIV4O5_DIV4)
/*MTKSOC1T*/{
/*MTKSOC1T*/   int N_sx_cal_fbx = 0;
/*MTKSOC1T*/   if(!MTKSOC1_SX_CALSBA)
/*MTKSOC1T*/   {
/*MTKSOC1T*/      *cw27 = 0;
/*MTKSOC1T*/      return;
/*MTKSOC1T*/   }
/*MTKSOC1T*/   if(sx_cal_dmd_t)
/*MTKSOC1T*/   {
/*MTKSOC1T*/      switch(rf_band)
/*MTKSOC1T*/      {
/*MTKSOC1T*/      case  FrequencyBand850 :
/*MTKSOC1T*/         {
/*MTKSOC1T*/            N_sx_cal_fbx = (int)( 702 -1 +arfcn +(arfcn-134 +9)/9 ); /* 1- 9/9 =0 */
/*MTKSOC1T*/            break;
/*MTKSOC1T*/         }
/*MTKSOC1T*/      case  FrequencyBand900 :
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(arfcn<=124)
/*MTKSOC1T*/            {
/*MTKSOC1T*/               N_sx_cal_fbx = (int)( 1195 -1 +arfcn +(arfcn-1+9)/9 ); /* 1- 9/9 =0 */
/*MTKSOC1T*/            }
/*MTKSOC1T*/            else
/*MTKSOC1T*/            {
/*MTKSOC1T*/               N_sx_cal_fbx = (int)( 166 -1 +arfcn +(arfcn-980+9)/9 ); /* 1- 9/9 =0 */
/*MTKSOC1T*/            }
/*MTKSOC1T*/
/*MTKSOC1T*/            break;
/*MTKSOC1T*/         }
/*MTKSOC1T*/      case  FrequencyBand1800 :
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(OPLL_DIV4O5_DIV4)
/*MTKSOC1T*/               N_sx_cal_fbx = (int) ((arfcn-512+8551)*2*16-3000*15*5+30)/(15*4); //DIV16
/*MTKSOC1T*/            else
/*MTKSOC1T*/               N_sx_cal_fbx = (int) ((arfcn-512+8551)*2*20-3000*19*5+38)/(19*4); //DIV20
/*MTKSOC1T*/            break;
/*MTKSOC1T*/         }
/*MTKSOC1T*/      case  FrequencyBand1900 :
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(OPLL_DIV4O5_DIV4)
/*MTKSOC1T*/               N_sx_cal_fbx = (int)( ( (arfcn-512+9251)*2*16 -3000*5*17 +34) /(4*17)); /* DIV16 (((Arfcn-512+1850.2*5)*2*16-3000*5*17+34)/(5*17*0.8)).*/
/*MTKSOC1T*/            else
/*MTKSOC1T*/               N_sx_cal_fbx = (int)( ( (arfcn-512+9251)*2*20 -3000*5*21 +42) /(4*21)); //DIV20 =INT(((A5-512+1850.2*5)*2*20-3000*5*21+42)/(5*21*0.8))
/*MTKSOC1T*/            break;
/*MTKSOC1T*/         }
/*MTKSOC1T*/      default:
/*MTKSOC1T*/         break;
/*MTKSOC1T*/      }
/*MTKSOC1T*/
/*MTKSOC1T*/   }
/*MTKSOC1T*/   else
/*MTKSOC1T*/   {
/*MTKSOC1T*/      switch(rf_band)
/*MTKSOC1T*/      {
/*MTKSOC1T*/      case  FrequencyBand850 :
/*MTKSOC1T*/         {
/*MTKSOC1T*/            N_sx_cal_fbx = (int)( 534+ 1+ arfcn - (arfcn-134 +9)/9 ); /* 1- 9/9 =0 */
/*MTKSOC1T*/            break;
/*MTKSOC1T*/         }
/*MTKSOC1T*/      case  FrequencyBand900 :
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(arfcn<=124)
/*MTKSOC1T*/            {
/*MTKSOC1T*/               N_sx_cal_fbx = (int)( 955+ 1+ arfcn -(arfcn-1+9)/9 ); /* 1- 9/9 =0 */
/*MTKSOC1T*/            }
/*MTKSOC1T*/            else
/*MTKSOC1T*/            {
/*MTKSOC1T*/               N_sx_cal_fbx = (int)( -64+ 1+ arfcn -(arfcn-980+9)/9 ); /* 1- 9/9 =0 */
/*MTKSOC1T*/            }
/*MTKSOC1T*/            break;
/*MTKSOC1T*/         }
/*MTKSOC1T*/      case  FrequencyBand1800 :
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(OPLL_DIV4O5_DIV4)
/*MTKSOC1T*/               N_sx_cal_fbx = (int)( ((arfcn-512+8551)*2*16-3000*15*5+37) / (15*5) ); /* DIV16 ( (arfcn-512+1710.2*5)*2*16-3000*15*5+37) / (15*5) ) (arfcn-512+1710.2*5)*2 is RFVCO freq. 37 is for round. 16/15 is div16.*/
/*MTKSOC1T*/            else
/*MTKSOC1T*/               N_sx_cal_fbx = (int)( ((arfcn-512+8551)*2*20-3000*19*5+47) / (19*5)); //DIV20
/*MTKSOC1T*/            break;
/*MTKSOC1T*/         }
/*MTKSOC1T*/      case  FrequencyBand1900 :
/*MTKSOC1T*/         {
/*MTKSOC1T*/            if(OPLL_DIV4O5_DIV4)
/*MTKSOC1T*/               N_sx_cal_fbx = (int)( ( (arfcn-512+9251)*2*16 -3000*5*17 + 42)/ (5*17)); /* DIV16 INT(((A5-512+1850.2*5)*2*16+42)/(5*17)-3000).*/
/*MTKSOC1T*/            else
/*MTKSOC1T*/               N_sx_cal_fbx = (int)( ( (arfcn-512+9251)*2*20 -3000*5*21 + 52)/ (5*21) ); //DIV20
/*MTKSOC1T*/            break;
/*MTKSOC1T*/         }
/*MTKSOC1T*/      default:
/*MTKSOC1T*/         break;
/*MTKSOC1T*/      }
/*MTKSOC1T*/
/*MTKSOC1T*/   }
/*MTKSOC1T*/ *cw27 = 0x1b00001L | (N_sx_cal_fbx<<2) | (sx_cal_dmd_t<<1); /*CW27 | sx_cal_fbx | sx_cal_dmd_t | sx_calsba*/
/*MTKSOC1T*/}
#endif

#if IS_RF_MTKSOC1
/*MTKSOC1*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MTKSOC1*/{
/*MTKSOC1*/ int Nfrac, SDM_IFM = 1, OPLL_DIV4O5_DIV4 = 0;
/*MTKSOC1*/ switch(rf_band)
/*MTKSOC1*/ {
/*MTKSOC1*/ case  FrequencyBand850 :
/*MTKSOC1*/    {
/*MTKSOC1*/       if(arfcn<=189)
/*MTKSOC1*/       {
/*MTKSOC1*/          if(arfcn<=160)
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=131)
/*MTKSOC1*/             {                                /* ARFCN : 128~131     */
/*MTKSOC1*/                Nfrac = (arfcn-128)*286790 + 7456540;
/*MTKSOC1*/                *rfN = (140L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             {                                /* ARFCN : 132~160     */
/*MTKSOC1*/                Nfrac = (arfcn-132)*286790 + 215093;
/*MTKSOC1*/                *rfN = (141L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/          else
/*MTKSOC1*/          {                              /* ARFCN : 161~189     */
/*MTKSOC1*/             Nfrac = (arfcn-161)*286790 + 143395;
/*MTKSOC1*/             *rfN = (142L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/          }
/*MTKSOC1*/       }
/*MTKSOC1*/       else
/*MTKSOC1*/       {
/*MTKSOC1*/          if(arfcn<=218)
/*MTKSOC1*/          {                              /* ARFCN : 190~218     */
/*MTKSOC1*/             Nfrac = (arfcn-190)*286790 + 71698;
/*MTKSOC1*/             *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/          }
/*MTKSOC1*/          else
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=248)
/*MTKSOC1*/             {                                /* ARFCN : 219~248     */
/*MTKSOC1*/                Nfrac = (arfcn-219)*286790;
/*MTKSOC1*/                *rfN = (144L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/
/*MTKSOC1*/                if(arfcn == 219)
/*MTKSOC1*/                   SDM_IFM = 0;
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             {                                /* ARFCN : 249~251     */
/*MTKSOC1*/                Nfrac = (arfcn-249)*286790 + 215093;
/*MTKSOC1*/                *rfN = (145L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/       }
/*MTKSOC1*/
/*MTKSOC1*/       *ifN = (Nfrac>>10) | 0x0242000L;                       /* N_FRAC[22:10] | (CW2|OPLL_DIV4O5_DIV4|TRX|BAND|MODE(warm_up mode))*/
/*MTKSOC1*/       *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1*/
/*MTKSOC1*/       break;
/*MTKSOC1*/    }
/*MTKSOC1*/ case  FrequencyBand900 :
/*MTKSOC1*/    {
/*MTKSOC1*/       if(arfcn<=112)
/*MTKSOC1*/       {
/*MTKSOC1*/          if(arfcn<=54)
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=25)
/*MTKSOC1*/             {                                /* ARFCN : 0~25     */
/*MTKSOC1*/                Nfrac = (arfcn)*286790 + 1147160;
/*MTKSOC1*/                *rfN = (152L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             {                                /* ARFCN : 26~54     */
/*MTKSOC1*/                Nfrac = (arfcn-26)*286790 + 215093;
/*MTKSOC1*/                *rfN = (153L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/          else
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=83)
/*MTKSOC1*/             {                                /* ARFCN : 55~83     */
/*MTKSOC1*/                Nfrac = (arfcn-55)*286790 + 143395;
/*MTKSOC1*/                *rfN = (154L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             {                                /* ARFCN : 84~112     */
/*MTKSOC1*/                Nfrac = (arfcn-84)*286790 + 71698;
/*MTKSOC1*/                *rfN = (155L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/       }
/*MTKSOC1*/       else
/*MTKSOC1*/       {
/*MTKSOC1*/          if(arfcn<=990)
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=124)
/*MTKSOC1*/             {                                /* ARFCN : 113~124     */
/*MTKSOC1*/                Nfrac = (arfcn-113)*286790;
/*MTKSOC1*/                *rfN = (156L<<10);
/*MTKSOC1*/
/*MTKSOC1*/                if(arfcn == 113)
/*MTKSOC1*/                   SDM_IFM = 0;
/*MTKSOC1*/
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             {                              /* ARFCN : 975~990     */
/*MTKSOC1*/                Nfrac = (arfcn-975)*286790 + 3871665;
/*MTKSOC1*/                *rfN = (150L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/          else
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=1019)
/*MTKSOC1*/             {                                /* ARFCN : 991~1019     */
/*MTKSOC1*/                Nfrac = (arfcn-991)*286790 + 71698;
/*MTKSOC1*/                *rfN = (151L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             {                                /* ARFCN : 1020~1023     */
/*MTKSOC1*/                Nfrac = (arfcn-1020)*286790;
/*MTKSOC1*/                *rfN = (152L<<10);
/*MTKSOC1*/
/*MTKSOC1*/                if(arfcn == 1020)
/*MTKSOC1*/                   SDM_IFM = 0;
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/       }
/*MTKSOC1*/       *ifN = (Nfrac>>10) | 0x0252000L;                       /* N_FRAC[22:10] | (CW2|OPLL_DIV4O5_DIV4|TRX|BAND|MODE(warm_up mode))*/
/*MTKSOC1*/       *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1*/
/*MTKSOC1*/       break;
/*MTKSOC1*/    }
/*MTKSOC1*/ case  FrequencyBand1800 :
/*MTKSOC1*/    {
/*MTKSOC1*/       if(arfcn<=670)
/*MTKSOC1*/       {
/*MTKSOC1*/          if(arfcn<=603)
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=547)
/*MTKSOC1*/             {
/*MTKSOC1*/                if(arfcn<=541)
/*MTKSOC1*/                { /* ARFCN : 512~541 */
/*MTKSOC1*/                   Nfrac = (arfcn-529)*135848 + 6316927;
/*MTKSOC1*/                   *rfN = (138L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                    L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 0, 0, 519, 529, 540, 542);
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/
/*MTKSOC1*/                }
/*MTKSOC1*/                else
/*MTKSOC1*/                { /* ARFCN : 542~547 */
/*MTKSOC1*/                   Nfrac = (arfcn-542)*137659 + 6848546;
/*MTKSOC1*/                   *rfN = (140L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                   OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   if(arfcn>=547)
/*MTKSOC1*/                      Nfrac++;
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/
/*MTKSOC1*/                }
/*MTKSOC1*/
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             { /* ARFCN : 548~603 */
/*MTKSOC1*/                Nfrac = (arfcn-581)*135848 + 4992410;
/*MTKSOC1*/                *rfN = (139L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/
/*MTKSOC1*/                /*error compensation*/
/*MTKSOC1*/                L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 550, 560, 570, 581, 591, 601);
/*MTKSOC1*/                /*End: error compensation*/
/*MTKSOC1*/
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/          else
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=665)
/*MTKSOC1*/             {
/*MTKSOC1*/                if(arfcn<=608)
/*MTKSOC1*/                { /* ARFCN : 604~608 */
/*MTKSOC1*/                   Nfrac = (arfcn-604)*137659 + 6994809;
/*MTKSOC1*/                   *rfN = (141L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                   OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/                }
/*MTKSOC1*/                else
/*MTKSOC1*/                { /* ARFCN : 609~665 */
/*MTKSOC1*/                   Nfrac = (arfcn-643)*135848 + 5026372;
/*MTKSOC1*/                   *rfN = (140L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 612, 622, 632, 643, 653, 663);
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/                }
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             { /* ARFCN : 666~670 */
/*MTKSOC1*/                Nfrac = (arfcn-666)*137659 + 7141071;
/*MTKSOC1*/                *rfN = (142L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/
/*MTKSOC1*/                /*error compensation*/
/*MTKSOC1*/                if(arfcn>=667)
/*MTKSOC1*/                   Nfrac++;
/*MTKSOC1*/                /*End: error compensation*/
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/       }
/*MTKSOC1*/       else
/*MTKSOC1*/       {
/*MTKSOC1*/          if(arfcn<=788)
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=732)
/*MTKSOC1*/             {
/*MTKSOC1*/                if(arfcn<=726)
/*MTKSOC1*/                {/* ARFCN : 671~726 */
/*MTKSOC1*/                   Nfrac = (arfcn-704)*135848 + 4924486;
/*MTKSOC1*/                   *rfN = (141L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 673, 684, 694, 704, 715, 725);
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/                }
/*MTKSOC1*/                else
/*MTKSOC1*/                {/*ARFCN:727~732*/
/*MTKSOC1*/                   Nfrac = (arfcn-727)*137659 + 7149675;
/*MTKSOC1*/                   *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                   OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   if(arfcn>=729)
/*MTKSOC1*/                      Nfrac++;
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/
/*MTKSOC1*/                }
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             {/*ARFCN:733~788*/
/*MTKSOC1*/                Nfrac = (arfcn-766)*135848 + 4958448;
/*MTKSOC1*/                *rfN = (142L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/
/*MTKSOC1*/                /*error compensation*/
/*MTKSOC1*/                L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 735, 745, 756, 766, 776, 786);
/*MTKSOC1*/                /*End: error compensation*/
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/          else
/*MTKSOC1*/          {
/*MTKSOC1*/             if(arfcn<=850)
/*MTKSOC1*/             {
/*MTKSOC1*/                if(arfcn<=794)
/*MTKSOC1*/                {/*ARFCN:789~794*/
/*MTKSOC1*/                   Nfrac = (arfcn-789)*137659 + 7295938;
/*MTKSOC1*/                   *rfN = (144L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                   OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   if(arfcn>=792)
/*MTKSOC1*/                      Nfrac++;
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/                }
/*MTKSOC1*/                else
/*MTKSOC1*/                {/*ARFCN:795~850*/
/*MTKSOC1*/                   Nfrac = (arfcn-828)*135848 + 4992410;
/*MTKSOC1*/                   *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 797, 806, 817, 828, 838, 848);
/*MTKSOC1*/                   /*End:*error compensation*/
/*MTKSOC1*/                }
/*MTKSOC1*/             }
/*MTKSOC1*/             else
/*MTKSOC1*/             {
/*MTKSOC1*/                if(arfcn<=855)
/*MTKSOC1*/                {/*ARFCN:851~855*/
/*MTKSOC1*/                   Nfrac = (arfcn-851)*137659 + 7442201;
/*MTKSOC1*/                   *rfN = (145L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                   OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   if(arfcn>=854)
/*MTKSOC1*/                      Nfrac++;
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/                }
/*MTKSOC1*/                else
/*MTKSOC1*/                {/*ARFCN:856~885*/
/*MTKSOC1*/                   Nfrac = (arfcn-869)*135848 + 2173566;
/*MTKSOC1*/                   *rfN = (144L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/
/*MTKSOC1*/                   /*error compensation*/
/*MTKSOC1*/                   L1D_RF_Band1800_FrequecyFractionPartCompensation(arfcn, &Nfrac, 0, 0, 859, 869, 879, 885);
/*MTKSOC1*/                   /*End: error compensation*/
/*MTKSOC1*/                }
/*MTKSOC1*/             }
/*MTKSOC1*/          }
/*MTKSOC1*/       }
/*MTKSOC1*/       *ifN = (Nfrac>>10) | 0x0262000L | (OPLL_DIV4O5_DIV4<<19);                       /* N_FRAC[22:10] | (CW2|OPLL_DIV4O5_DIV4|TRX|BAND|MODE(warm_up mode))*/
/*MTKSOC1*/       *rfN |= ((Nfrac&0x3FF) | 0x01C0000L); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1*/       break;
/*MTKSOC1*/      }
/*MTKSOC1*/      case  FrequencyBand1900 :
/*MTKSOC1*/      {
/*MTKSOC1*/         if(arfcn<=676)
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=546)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=540)
/*MTKSOC1*/               { /*ARFCN:512~540*/
/*MTKSOC1*/                  Nfrac = (arfcn-512)*122910 + 4578398;
/*MTKSOC1*/                  *rfN = (135L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               { /*ARFCN:541~546*/
/*MTKSOC1*/                  Nfrac = (arfcn-541)*121464 + 3112515;
/*MTKSOC1*/                  *rfN = (134L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                  OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=614)
/*MTKSOC1*/               {
/*MTKSOC1*/                  if(arfcn<=608)
/*MTKSOC1*/                  { /*ARFCN:547~608*/
/*MTKSOC1*/                     Nfrac = (arfcn-547)*122910 + 491640;
/*MTKSOC1*/                     *rfN = (136L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                  }
/*MTKSOC1*/                  else
/*MTKSOC1*/                  { /*ARFCN:609~614*/
/*MTKSOC1*/                     Nfrac = (arfcn-609)*121464 + 2983460;
/*MTKSOC1*/                     *rfN = (135L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                     OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/                  }
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               { /*ARFCN:615~676*/
/*MTKSOC1*/                  Nfrac = (arfcn-615)*122910 + 460913;
/*MTKSOC1*/                  *rfN = (137L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/         else
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=744)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=682)
/*MTKSOC1*/               {/*ARFCN:677~682*/
/*MTKSOC1*/                  Nfrac = (arfcn-677)*121464 + 2854404;
/*MTKSOC1*/                  *rfN = (136L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                  OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               { /*ARFCN:683~744*/
/*MTKSOC1*/                  Nfrac = (arfcn-683)*122910 + 430185;
/*MTKSOC1*/                  *rfN = (138L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=750)
/*MTKSOC1*/               {/*ARFCN:745~750*/
/*MTKSOC1*/                  Nfrac = (arfcn-745)*121464 + 2725349;
/*MTKSOC1*/                  *rfN = (137L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/                  OPLL_DIV4O5_DIV4 = 1;
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               { /*ARFCN:751~810*/
/*MTKSOC1*/                  Nfrac = (arfcn-751)*122910 + 399458;
/*MTKSOC1*/                  *rfN = (139L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/
/*MTKSOC1*/         *ifN = (Nfrac>>10) | 0x0272000L | (OPLL_DIV4O5_DIV4<<19);                       /* N_FRAC[22:10] | (CW2|OPLL_DIV4O5_DIV4|TRX|BAND|MODE(warm_up mode))*/
/*MTKSOC1*/         *rfN |= ((Nfrac&0x3FF) | 0x0140000L); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1*/         break;
/*MTKSOC1*/      }
/*MTKSOC1*/      default :
/*MTKSOC1*/      {
/*MTKSOC1*/         break;
/*MTKSOC1*/      }
/*MTKSOC1*/   }
/*MTKSOC1*/}
/*MTKSOC1*//* =============================================================== */
/*MTKSOC1*/
/*MTKSOC1*/void L1D_RF_Band1800_FrequecyFractionPartCompensation(int arfcn, int *Nfrac, short arfcn1, short arfcn2, short arfcn3, short arfcn4, short arfcn5, short arfcn6)
/*MTKSOC1*/{
/*MTKSOC1*/ if(arfcn<arfcn4)
/*MTKSOC1*/ {
/*MTKSOC1*/    if(arfcn<arfcn2)
/*MTKSOC1*/    {
/*MTKSOC1*/       if(arfcn<arfcn1)
/*MTKSOC1*/          *Nfrac+=4;
/*MTKSOC1*/       else
/*MTKSOC1*/          *Nfrac+=3;
/*MTKSOC1*/    }
/*MTKSOC1*/    else
/*MTKSOC1*/    {
/*MTKSOC1*/       if(arfcn<arfcn3)
/*MTKSOC1*/          *Nfrac+=2;
/*MTKSOC1*/       else
/*MTKSOC1*/          *Nfrac+=1;
/*MTKSOC1*/    }
/*MTKSOC1*/ }
/*MTKSOC1*/ else if (arfcn>=arfcn5)
/*MTKSOC1*/ {
/*MTKSOC1*/    if(arfcn<arfcn6)
/*MTKSOC1*/    {
/*MTKSOC1*/       *Nfrac-=1;
/*MTKSOC1*/    }
/*MTKSOC1*/    else
/*MTKSOC1*/    {
/*MTKSOC1*/       *Nfrac-=2;
/*MTKSOC1*/    }
/*MTKSOC1*/ }
/*MTKSOC1*/}
/*MTKSOC1*/
/*MTKSOC1*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MTKSOC1*/{
/*MTKSOC1*/   int Nfrac, SDM_IFM = 1;
/*MTKSOC1*/   switch(rf_band)
/*MTKSOC1*/   {
/*MTKSOC1*/   case  FrequencyBand850 :
/*MTKSOC1*/      {
/*MTKSOC1*/         if(arfcn<=201)
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=169)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=136)
/*MTKSOC1*/               {/*arfcn:128~136*/
/*MTKSOC1*/                  Nfrac = (arfcn-128)*258111 + 6065609;
/*MTKSOC1*/                  *rfN = (133L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:137~169*/
/*MTKSOC1*/                  Nfrac = (arfcn-137)*258111;
/*MTKSOC1*/                  *rfN = (134L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {/*arfcn:170~201*/
/*MTKSOC1*/               Nfrac = (arfcn-170)*258111+129056;
/*MTKSOC1*/               *rfN = (135L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/         else
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=234)
/*MTKSOC1*/            {/*arfcn:202~234*/
/*MTKSOC1*/               Nfrac = (arfcn-202)*258111;
/*MTKSOC1*/               *rfN = (136L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {/*arfcn:235~251*/
/*MTKSOC1*/               Nfrac = (arfcn-235)*258111+129056;
/*MTKSOC1*/               *rfN = (137L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/         *ifN = (Nfrac>>10)|0x0202000;  /* CW2, TRX:0, BAND:0, MODE:1, N_RFC[22:10]*/
/*MTKSOC1*/         if(Nfrac==0) SDM_IFM = 0;
/*MTKSOC1*/         *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1*/
/*MTKSOC1*/         // Get GSM850 signal from GSM900 input pins if flag=1
/*MTKSOC1*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap ) *ifN |=0x0010000L ;
/*MTKSOC1*/         break;
/*MTKSOC1*/      }
/*MTKSOC1*/   case  FrequencyBand900 :
/*MTKSOC1*/      {
/*MTKSOC1*/         if(arfcn<=102)
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=37)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=4)
/*MTKSOC1*/               {/*arfcn:0~4*/
/*MTKSOC1*/                  Nfrac = (arfcn)*258111+7098053;
/*MTKSOC1*/                  *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:5~37*/
/*MTKSOC1*/                  Nfrac = (arfcn-5)*258111;
/*MTKSOC1*/                  *rfN = (144L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=69)
/*MTKSOC1*/               {/*arfcn:38~69*/
/*MTKSOC1*/                  Nfrac = (arfcn-38)*258111+129056;
/*MTKSOC1*/                  *rfN = (145L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:70~102*/
/*MTKSOC1*/                  Nfrac = (arfcn-70)*258111;
/*MTKSOC1*/                  *rfN = (146L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/         else
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=996)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=124)
/*MTKSOC1*/               {/*arfcn:103~124*/
/*MTKSOC1*/                  Nfrac = (arfcn-103)*258111+129056;
/*MTKSOC1*/                  *rfN = (147L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:975~996*/
/*MTKSOC1*/                  Nfrac = (arfcn-975)*258111+2839221;
/*MTKSOC1*/                  *rfN = (142L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {/*arfcn:997~1023*/
/*MTKSOC1*/               Nfrac = (arfcn-997)*258111+129056;
/*MTKSOC1*/               *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/
/*MTKSOC1*/         *ifN = (Nfrac>>10)|0x0212000;  /* CW2, TRX:0, BAND:1, MODE:1, N_RFC[22:10]*/
/*MTKSOC1*/
/*MTKSOC1*/         if(Nfrac==0) SDM_IFM = 0;
/*MTKSOC1*/         *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1*/
/*MTKSOC1*/         // Get GSM900 signal from GSM850 input pins if flag=1
/*MTKSOC1*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap )  *ifN &= (~(0x0010000L));
/*MTKSOC1*/         break;
/*MTKSOC1*/      }
/*MTKSOC1*/   case  FrequencyBand1800 :
/*MTKSOC1*/      {
/*MTKSOC1*/         if(arfcn<=715)
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=585)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=520)
/*MTKSOC1*/               {/*arfcn:512~520*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 456);
/*MTKSOC1*/                  *rfN = (138L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:521~585*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 521);
/*MTKSOC1*/                  *rfN = (139L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=650)
/*MTKSOC1*/               {/*arfcn:586~650*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 586);
/*MTKSOC1*/                  *rfN = (140L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:651~715*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 651);
/*MTKSOC1*/                  *rfN = (141L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/         else
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=845)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=780)
/*MTKSOC1*/               {/*arfcn:716~780*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 716);
/*MTKSOC1*/                  *rfN = (142L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:781~845*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 781);
/*MTKSOC1*/                  *rfN = (143L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {/*arfcn:846~885*/
/*MTKSOC1*/               L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 846);
/*MTKSOC1*/               *rfN = (144L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/
/*MTKSOC1*/
/*MTKSOC1*/         *ifN = (Nfrac>>10)|0x0222000;  /* CW2, TRX:0, BAND:2, MODE:1, N_RFC[22:10]*/
/*MTKSOC1*/
/*MTKSOC1*/         if(Nfrac==0) SDM_IFM = 0;
/*MTKSOC1*/         *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1*/
/*MTKSOC1*/         // Get PCS1900 signal from DCS1800 input pins if flag=1
/*MTKSOC1*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap ) *ifN |=0x0010000L ;
/*MTKSOC1*/         break;
/*MTKSOC1*/      }
/*MTKSOC1*/   case  FrequencyBand1900 :
/*MTKSOC1*/      {
/*MTKSOC1*/         if(arfcn<=675)
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=610)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=545)
/*MTKSOC1*/               {/*arfcn:512~545*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 481);
/*MTKSOC1*/                  *rfN = (148L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:546~610*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 546);
/*MTKSOC1*/                  *rfN = (149L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {/*arfcn:611~675*/
/*MTKSOC1*/               L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 611);
/*MTKSOC1*/               *rfN = (150L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/         else
/*MTKSOC1*/         {
/*MTKSOC1*/            if(arfcn<=805)
/*MTKSOC1*/            {
/*MTKSOC1*/               if(arfcn<=740)
/*MTKSOC1*/               {/*arfcn:676~740*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 676);
/*MTKSOC1*/                  *rfN = (151L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/               else
/*MTKSOC1*/               {/*arfcn:741~805*/
/*MTKSOC1*/                  L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 741);
/*MTKSOC1*/                  *rfN = (152L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/               }
/*MTKSOC1*/            }
/*MTKSOC1*/            else
/*MTKSOC1*/            {/*arfcn:806~810*/
/*MTKSOC1*/               L1D_RF_GetRxPLL_HB_FractionPart(&Nfrac, arfcn, 806);
/*MTKSOC1*/               *rfN = (153L<<10); /* N_INT[7:0]*/
/*MTKSOC1*/            }
/*MTKSOC1*/         }
/*MTKSOC1*/
/*MTKSOC1*/         *ifN = (Nfrac>>10)|0x0232000;  /* CW2, TRX:0, BAND:2, MODE:1, N_RFC[22:10]*/
/*MTKSOC1*/
/*MTKSOC1*/         if(Nfrac==0) SDM_IFM = 0;
/*MTKSOC1*/         *rfN |= ((Nfrac&0x3FF) | 0x0180000L | (SDM_IFM<<18) ); /* N_INT[7:0] | N_FRAC[9:0] | (CW1|OPLL_HLSIDE)| SDM_IFM)*/
/*MTKSOC1*/         // Get DCS1800 signal from PCS1900 input pins if flag=1
/*MTKSOC1*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap)  *ifN &= (~(0x0010000L));
/*MTKSOC1*/         break;
/*MTKSOC1*/      }
/*MTKSOC1*/   default :
/*MTKSOC1*/      {
/*MTKSOC1*/         break;
/*MTKSOC1*/      }
/*MTKSOC1*/   }
/*MTKSOC1*/}
/*MTKSOC1*//* =============================================================== */
/*MTKSOC1*/
/*MTKSOC1*/void L1D_RF_GetRxPLL_HB_FractionPart(int *Nfrac, int arfcn, int arfcn_base)
/*MTKSOC1*/{
/*MTKSOC1*/   int Diff_arfcn;
/*MTKSOC1*/
/*MTKSOC1*/   Diff_arfcn = arfcn - arfcn_base;
/*MTKSOC1*/   *Nfrac = (Diff_arfcn >>1) * 258111;
/*MTKSOC1*/   if(Diff_arfcn & 0x1) *Nfrac += 129056;
/*MTKSOC1*/}
/*MTKSOC1*//* =============================================================== */
#endif

#if IS_RF_MT6252RF
/*MT6252RF*/
/*MT6252RF*/ static void  L1D_RF_GetRxPLLifNrfN( int rf_band, short K, long *ifN, long *rfN )
/*MT6252RF*/ {
/*MT6252RF*/    int Nfrac = 64527*K + ( ( 3*K + 2 ) >> 2 );
/*MT6252RF*/
/*MT6252RF*/    /* CW2, TRX:0, BAND:0, MODE:010, N_RFC[22:10]*/
/*MT6252RF*/    *ifN = ( Nfrac >> 10) | 0x0204000L | ( ( rf_band - 1 ) << 16 );
/*MT6252RF*/
/*MT6252RF*/    *rfN |= ( ( Nfrac&0x3FF ) | 0x0100000L );
/*MT6252RF*/ }
/*MT6252RF*/ /* ============================================================================= */
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6252RF*/ {
/*MT6252RF*/    short D = 0, K = 0;
/*MT6252RF*/    int Nfrac, DFM_LGCP_IOSTPOL;
/*MT6252RF*/    switch(rf_band)
/*MT6252RF*/    {
/*MT6252RF*/       case  FrequencyBand850 :
/*MT6252RF*/       {
/*MT6252RF*/          D = arfcn - 128;
/*MT6252RF*/          K = 104 + 4*D - 130*( ( 1653 + 63*D ) >> 11 );
/*MT6252RF*/
/*MT6252RF*/          // Nint = 126 + ( ( 1653 + 63*D ) >> 11 ); *rfN = Nint << 10;
/*MT6252RF*/          *rfN = ( 126 << 10 ) + (long)( ( ( 1653 + 63*D ) >> 1 ) & 0xFC00 );
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/       case  FrequencyBand900 :
/*MT6252RF*/       {
/*MT6252RF*/	         D = ( arfcn > 974 ) ? ( arfcn - 1024 ) : arfcn;
/*MT6252RF*/	         K = 250 + 4*D - 130*( ( 3953 + 63*D ) >> 11 );
/*MT6252RF*/
/*MT6252RF*/	         // Nint = 135 + ( ( 3953 + 63 D ) >> 11 ); *rfN = Nint << 10;
/*MT6252RF*/          *rfN = ( 135 << 10 ) + (long)( ( ( 3953 + 63*D ) >> 1 ) & 0xFC00 );
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/       case  FrequencyBand1800 :
/*MT6252RF*/       {
/*MT6252RF*/          D = arfcn - 512;
/*MT6252RF*/          K = 72 + 2*D - 130*( ( 2300 + 63*D ) >> 12 );
/*MT6252RF*/
/*MT6252RF*/          // Nint = 131 + ( ( 2300 + 63*D ) >> 12 ); *rfN = Nint << 10;
/*MT6252RF*/          *rfN = ( 131 << 10 ) + (long)( ( ( 2300 + 63*D ) >> 2 ) & 0xFC00 );
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/       case  FrequencyBand1900 :
/*MT6252RF*/       {
/*MT6252RF*/          D = arfcn - 512;
/*MT6252RF*/          K = 42 + 2*D - 130*( ( 1355 + 63*D ) >> 12 );
/*MT6252RF*/
/*MT6252RF*/          // Nint = 142 + ( ( 1355 + 63*D ) >> 12 ); *rfN = Nint << 10;
/*MT6252RF*/          *rfN = ( 142 << 10 ) + (long)( ( ( 1355 + 63*D ) >> 2 ) & 0xFC00 );
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/       default :
/*MT6252RF*/       {
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/    }
/*MT6252RF*/    DFM_LGCP_IOSTPOL = (27 < K && K < 37) || (49 < K && K < 59) || (113 < K && K < 129) ? 1 : 0;
/*MT6252RF*/    Nfrac = 64527*K + ( ( 3*K + 2 ) >> 2 );
/*MT6252RF*/
/*MT6252RF*/    /* CW2:      [27:20] |  [19:18] |   [17:16] |   [15:13]               |        [12:0] */
/*MT6252RF*/    /*      Address[7:0] | TRX[1:0] | BAND[1:0] | MODE[2:0](warm_up mode) | N_FRAC[22:10] */
/*MT6252RF*/    *ifN = ( Nfrac >> 10 ) | 0x0244000L | ( ( rf_band - 1 ) << 16 );
/*MT6252RF*/
/*MT6252RF*/    /* CW1:      [27:20] |          [19] |             [18] |    [17:10] |       [9:0]    */
/*MT6252RF*/    /*      Address[7:0] | DFM_SDM_DI_EN | DFM_LGCP_IOSTPOL | N_INT[7:0] | N_FRAC[9:0]    */
/*MT6252RF*/    *rfN |= ( ( Nfrac & 0x3FF ) | 0x0180000L | DFM_LGCP_IOSTPOL << 18 );
/*MT6252RF*/ }
/*MT6252RF*/ /* ============================================================================= */
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6252RF*/ {
/*MT6252RF*/    short D = 0, K = 0;
/*MT6252RF*/    switch(rf_band)
/*MT6252RF*/    {
/*MT6252RF*/       case  FrequencyBand850 :
/*MT6252RF*/       {
/*MT6252RF*/          D = arfcn - 128;
/*MT6252RF*/          K = 94 + 4*D - 130*( ( 1496 + 63*D ) >> 11 );
/*MT6252RF*/
/*MT6252RF*/          // Nint = 133 + ( ( 1496 + 63*D ) >> 11); *rfN = Nint << 10;
/*MT6252RF*/          *rfN = ( 133 << 10 ) + (long)( ( ( 1496 + 63*D ) >> 1 ) & 0xFC00 );
/*MT6252RF*/          L1D_RF_GetRxPLLifNrfN( rf_band, K, ifN, rfN );
/*MT6252RF*/
/*MT6252RF*/          // Get GSM850 signal from GSM900 input pins if flag = 1
/*MT6252RF*/          if( BBTXParameters.bbrx_gsm850_gsm900_swap ) *ifN |=0x0010000L ;
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/       case  FrequencyBand900 :
/*MT6252RF*/       {
/*MT6252RF*/          D = ( arfcn > 974 ) ? ( arfcn - 1024 ) : arfcn;
/*MT6252RF*/          K = 240 + 4*D - 130*( ( 3796 + 63*D ) >> 11 );
/*MT6252RF*/
/*MT6252RF*/          // Nint = 142 + ( ( 3796 + 63 D ) >> 11); *rfN = Nint << 10;
/*MT6252RF*/          *rfN = ( 142 << 10 ) + (long)( ( ( 3796 + 63*D ) >> 1 ) & 0xFC00 );
/*MT6252RF*/          L1D_RF_GetRxPLLifNrfN( rf_band, K, ifN, rfN );
/*MT6252RF*/
/*MT6252RF*/          // Get GSM900 signal from GSM850 input pins if flag = 1
/*MT6252RF*/          if( BBTXParameters.bbrx_gsm850_gsm900_swap )  *ifN &= (~(0x0010000L));
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/       case  FrequencyBand1800 :
/*MT6252RF*/       {
/*MT6252RF*/          D = arfcn - 512;
/*MT6252RF*/          K = 112 + 2*D - 130*( ( 3560 + 63*D ) >> 12 );
/*MT6252RF*/
/*MT6252RF*/          // Nint = 138 + ( (3560 + 63 D) >> 12); *rfN = Nint << 10;
/*MT6252RF*/          *rfN = ( 138 << 10 ) + (long)( ( ( 3560 + 63*D ) >> 2 ) & 0xFC00 );
/*MT6252RF*/          L1D_RF_GetRxPLLifNrfN( rf_band, K, ifN, rfN );
/*MT6252RF*/
/*MT6252RF*/          // Get PCS1900 signal from DCS1800 input pins if flag = 1
/*MT6252RF*/          if( BBTXParameters.bbrx_dcs1800_pcs1900_swap ) *ifN |=0x0010000L ;
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/       case  FrequencyBand1900 :
/*MT6252RF*/       {
/*MT6252RF*/          D = arfcn - 512;
/*MT6252RF*/          K = 62 + 2*D - 130*( ( 1985 + 63*D ) >> 12 );
/*MT6252RF*/
/*MT6252RF*/          // Nint = 148 + ( ( 1985 + 63*D ) >> 12); *rfN = Nint << 10;
/*MT6252RF*/          *rfN = ( 148 << 10 ) + (long)( ( ( 1985 + 63*D ) >> 2 ) & 0xFC00 );
/*MT6252RF*/          L1D_RF_GetRxPLLifNrfN( rf_band, K, ifN, rfN );
/*MT6252RF*/
/*MT6252RF*/          // Get DCS1800 signal from PCS1900 input pins if flag = 1
/*MT6252RF*/          if( BBTXParameters.bbrx_dcs1800_pcs1900_swap)  *ifN &= (~(0x0010000L));
/*MT6252RF*/          break;
/*MT6252RF*/       }
/*MT6252RF*/    }
/*MT6252RF*/ }
/*MT6252RF*/ /* ============================================================================= */
#endif

#if IS_RF_MT6256RF || IS_RF_MT6251RF || IS_RF_MT6255RF
   #if IS_MT6256_DCR_MODE || IS_MT6251_DCR_MODE
/*MT6256RF*/ //For DCR backup mode
/*MT6256RF*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6256RF*/ {  long *if_sel = ifN+1;
/*MT6256RF*/    unsigned short Nint =0, CH_freq =0;
/*MT6256RF*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6256RF*/
/*MT6256RF*/    *if_sel = 2;
/*MT6256RF*/    CH_freq = L1D_RF_ARFCN_CH_to_RxFreq( rf_band, arfcn );
/*MT6256RF*/
/*MT6256RF*/    if( rf_band < FrequencyBand1800 )
/*MT6256RF*/    {  VCO_freq = 4*CH_freq;  }
/*MT6256RF*/    else
/*MT6256RF*/    {  VCO_freq = 2*CH_freq;  }
/*MT6256RF*/
/*MT6256RF*/    Nint  = VCO_freq/DCXO_FREQ;
/*MT6256RF*/    Nfrac = ( ( (VCO_freq - Nint*DCXO_FREQ)<<23 ) + DCXO_FREQ/2 )/DCXO_FREQ;
/*MT6256RF*/
/*MT6256RF*/    // CW2, TRX:0, BAND, MODE: standby, N_RFC[22:10]
/*MT6256RF*/    *ifN = BSI_CW( 0x02, 0x04000|(Nfrac>>10)|((rf_band-1)<<16) );
/*MT6256RF*/    // CW1, DFM_LG_COE, N_INT[7:0], N_FRAC[9:0]
/*MT6256RF*/    *rfN = BSI_CW( 0x01, 0xC0000|(Nfrac&0x3FF)|(Nint<<10) );
/*MT6256RF*/
/*MT6256RF*/    if( BBTXParameters.bbrx_gsm850_gsm900_swap || BBTXParameters.bbrx_dcs1800_pcs1900_swap )
/*MT6256RF*/    {
/*MT6256RF*/       switch( rf_band )
/*MT6256RF*/       {
/*MT6256RF*/          case FrequencyBand850 :
/*MT6256RF*/          case FrequencyBand1800 :
/*MT6256RF*/          {  *ifN |= 0x0010000L;
/*MT6256RF*/             break;
/*MT6256RF*/          }
/*MT6256RF*/          case FrequencyBand900 :
/*MT6256RF*/          case FrequencyBand1900 :
/*MT6256RF*/          {  *ifN &= (~(0x0010000L));
/*MT6256RF*/             break;
/*MT6256RF*/          }
/*MT6256RF*/          default:
/*MT6256RF*/          {  break;
/*MT6256RF*/          }
/*MT6256RF*/       }
/*MT6256RF*/    }
/*MT6256RF*/ }
/*MT6256RF*/ /* =========================================================================== */
   #else
/*MT6256RF*/ //For DLIF mode
/*MT6256RF*/ void  L1D_RF_Cal_Synthesizer_Params( unsigned short* Nint, unsigned long* Nfrac, unsigned long  VCO_freq )
/*MT6256RF*/ {
/*MT6256RF*/    *Nint  = VCO_freq/(DCXO_FREQ*DLIF_SCALE);
/*MT6256RF*/    //+195/2 is for rounding, 195=13*3*5, 5 is SYNTH_SCALE, 13 and 3 are related to DLIF
/*MT6256RF*/    *Nfrac = ( ( (VCO_freq - *Nint*DCXO_FREQ*DLIF_SCALE)<<15 ) + 195/2 )/195;
/*MT6256RF*/ }
/*MT6256RF*/ /* =========================================================================== */
/*MT6256RF*/
/*MT6256RF*/ char  L1D_RF_Cal_IF_Synth_State( void )
/*MT6256RF*/ {
      #if IS_W_CANCELLATION_SUPPORT
/*MT6256RF*/    if( L1D_CheckIfMetaMode() )
/*MT6256RF*/    {  return l1d_rf.if_state;  }
/*MT6256RF*/    else
/*MT6256RF*/    {  return 0;  }
      #else
/*MT6256RF*/    return 0;
      #endif                    
/*MT6256RF*/ }
/*MT6256RF*/ /* =========================================================================== */
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6256RF*/ {  long *if_sel = ifN+1;
/*MT6256RF*/    unsigned short Nint =0, CH_freq =0;
/*MT6256RF*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6256RF*/    unsigned long  frac_spurs_thd0=0, frac_spurs_thd1=0;
/*MT6256RF*/    unsigned char  IF_state=0;   //IF_state=0:default, IF_state=1:+IF, IF_state=2:-IF
/*MT6256RF*/
/*MT6256RF*/    IF_state = L1D_RF_Cal_IF_Synth_State();
/*MT6256RF*/
/*MT6256RF*/    CH_freq = L1D_RF_ARFCN_CH_to_RxFreq( rf_band, arfcn );
/*MT6256RF*/
/*MT6256RF*/    if( IF_state != 2 ) 
/*MT6256RF*/    {
/*MT6256RF*/       *if_sel = 0;
/*MT6256RF*/       if( rf_band < FrequencyBand1800 )
/*MT6256RF*/       {
/*MT6256RF*/          VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);  //High-side mixing
/*MT6256RF*/          frac_spurs_thd0 = 193584;
/*MT6256RF*/          frac_spurs_thd1 = 8195024;
/*MT6256RF*/       }
/*MT6256RF*/       else
/*MT6256RF*/       {
/*MT6256RF*/          VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);  //High-side mixing
/*MT6256RF*/          frac_spurs_thd0 = 96792;
/*MT6256RF*/          frac_spurs_thd1 = 8291816;
/*MT6256RF*/       }
/*MT6256RF*/       L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6256RF*/    }
/*MT6256RF*/  
/*MT6256RF*/    if( IF_state != 1 )
/*MT6256RF*/    {       
/*MT6256RF*/       // check fractional spurs criterion (for run-time) or IRR state (for IRR calibration) 
/*MT6256RF*/       if( ( Nfrac < frac_spurs_thd0 ) || ( Nfrac > frac_spurs_thd1) || ( Nfrac < 4258832 && Nfrac > 4129776 ) || ( IF_state == 2 ) )
/*MT6256RF*/       {
/*MT6256RF*/          *if_sel = 1;  //-170k
/*MT6256RF*/          if( rf_band < FrequencyBand1800 )
/*MT6256RF*/          {  VCO_freq = 4*(CH_freq*DLIF_SCALE + DLIF);  }  //Low-side mixing
/*MT6256RF*/          else
/*MT6256RF*/          {  VCO_freq = 2*(CH_freq*DLIF_SCALE + DLIF);  }  //Low-side mixing
/*MT6256RF*/
/*MT6256RF*/          L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6256RF*/       }
/*MT6256RF*/    }  
/*MT6256RF*/
      #if IS_OBB_DETECTION_SUPPORT
/*MT6256RF*/    if( !L1D_CheckIfMetaMode() )
/*MT6256RF*/    {
/*MT6256RF*/       if( l1d_rf.if_change == -1 && arfcn == l1d_rf.obb_arfcn )
/*MT6256RF*/       {
/*MT6256RF*/          signed short if_sign = l1d_rf.if_change*(*if_sel*2-1);
/*MT6256RF*/
/*MT6256RF*/          *if_sel = if_sign > 0 ? 1 : 0;
/*MT6256RF*/          if( rf_band < FrequencyBand1800 )
/*MT6256RF*/          {  VCO_freq = 4*(CH_freq*DLIF_SCALE + if_sign*DLIF);  }
/*MT6256RF*/          else
/*MT6256RF*/          {  VCO_freq = 2*(CH_freq*DLIF_SCALE + if_sign*DLIF);  }
/*MT6256RF*/
/*MT6256RF*/          L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6256RF*/       }
/*MT6256RF*/    }
      #endif
/*MT6256RF*/    // CW2, TRX:0, BAND, MODE: standby, N_RFC[22:10]
/*MT6256RF*/    *ifN = BSI_CW( 0x02, 0x04000|(Nfrac>>10)|((rf_band-1)<<16) );
/*MT6256RF*/    // CW1, DFM_LG_COE, N_INT[7:0], N_FRAC[9:0]
/*MT6256RF*/    *rfN = BSI_CW( 0x01, 0xC0000|(Nfrac&0x3FF)|(Nint<<10) );
/*MT6256RF*/    
/*MT6256RF*/    if( BBTXParameters.bbrx_gsm850_gsm900_swap || BBTXParameters.bbrx_dcs1800_pcs1900_swap ) 
/*MT6256RF*/    {
/*MT6256RF*/       switch( rf_band )
/*MT6256RF*/       {
/*MT6256RF*/          case FrequencyBand850 :
/*MT6256RF*/          case FrequencyBand1800 :
/*MT6256RF*/          {  *ifN |= 0x0010000L;
/*MT6256RF*/             break;
/*MT6256RF*/          }
/*MT6256RF*/          case FrequencyBand900 :
/*MT6256RF*/          case FrequencyBand1900 :
/*MT6256RF*/          {  *ifN &= (~(0x0010000L));
/*MT6256RF*/             break;
/*MT6256RF*/          }
/*MT6256RF*/          default:
/*MT6256RF*/          {  break;
/*MT6256RF*/          }
/*MT6256RF*/       }
/*MT6256RF*/    }
/*MT6256RF*/ }
/*MT6256RF*/ /* =========================================================================== */
   #endif
/*MT6256RF*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6256RF*/ {
/*MT6256RF*/    unsigned short Nint =0, CH_freq =0;
/*MT6256RF*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6256RF*/
/*MT6256RF*/    l1d_rf2.arfcn = arfcn;  //for L1D_RF_GetSData_ST2()
/*MT6256RF*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6256RF*/
/*MT6256RF*/    if( rf_band < FrequencyBand1800 )
/*MT6256RF*/    {  VCO_freq = 4*CH_freq;  }
/*MT6256RF*/    else
/*MT6256RF*/    {  VCO_freq = 2*CH_freq;  }
/*MT6256RF*/
/*MT6256RF*/    Nint  = VCO_freq/DCXO_FREQ;
/*MT6256RF*/    Nfrac = ( ((VCO_freq-Nint*DCXO_FREQ)<<23) + DCXO_FREQ/2 )/DCXO_FREQ;  //+DCXO_freq/2 is for rounding
/*MT6256RF*/
/*MT6256RF*/    // CW2, TRX:1, BAND, MODE: standby, N_RFC[22:10]
/*MT6256RF*/    *ifN = BSI_CW( 0x02, 0x44000|(Nfrac>>10)|((rf_band-1)<<16) );
/*MT6256RF*/    // CW1, DFM_LG_COE, N_INT[7:0], N_FRAC[9:0]
/*MT6256RF*/    *rfN = BSI_CW( 0x01, 0xC0000|(Nfrac&0x3FF)|(Nint<<10) );
   #if IS_CHIP_MT6256_S00 || IS_CHIP_MT6251_S00
   /* Do nothing */
   #elif IS_CHIP_MT6256 || IS_CHIP_MT6255
/*MT6256RF*/    if( ( Nfrac>=225847  && Nfrac<=419430  ) || ( Nfrac>=1000180 && Nfrac<=1193763 ) ||
/*MT6256RF*/        ( Nfrac>=1903568 && Nfrac<=2097152 ) || ( Nfrac>=3452234 && Nfrac<=3645818 ) ||
/*MT6256RF*/        ( Nfrac>=4484678 && Nfrac<=4678262 ) || ( Nfrac>=5000900 && Nfrac<=5065428 ) ||
/*MT6256RF*/        ( Nfrac>=5517122 && Nfrac<=5581650 ) || ( Nfrac>=7452955 && Nfrac<=7904649 )
/*MT6256RF*/      )
/*MT6256RF*/    {  /*CW1, DFM_LG_COE = 0*/
/*MT6256RF*/       *rfN &= ~(1<<19);
/*MT6256RF*/    }
   #elif IS_CHIP_MT6251
/*MT6251RF*/    if( ( Nfrac>=1774513 && Nfrac<=2355264 ) || ( Nfrac>=2936012 && Nfrac<=3129597 ) ||
/*MT6251RF*/        ( Nfrac>=3452235 && Nfrac<=3516763 ) || ( Nfrac>=3968457 && Nfrac<=4162041 ) ||
/*MT6251RF*/        ( Nfrac>=6162401 && Nfrac<=6355983 ) || ( Nfrac>=6807678 && Nfrac<=7130316 ) ||
/*MT6251RF*/        ( Nfrac>=7711067 && Nfrac<=8033705 ) )
/*MT6251RF*/    {  /*CW1, DFM_LG_COE = 0*/
/*MT6251RF*/       *rfN &= ~(1<<19);
/*MT6251RF*/    }
   #endif
/*MT6256RF*/ }
/*MT6256RF*/ /* =========================================================================== */
/*MT6256RF*/
/*MT6256RF*/ unsigned short L1D_RF_ARFCN_CH_to_RxFreq( int rf_band, int arfcn )
/*MT6256RF*/ {
/*MT6256RF*/    unsigned short freq=4450+225;
/*MT6256RF*/    switch( rf_band )
/*MT6256RF*/    {
/*MT6256RF*/       case  FrequencyBand850 :
/*MT6256RF*/       {
/*MT6256RF*/          freq=4121+(arfcn-128)+225;     //freq = f_ch*SYNTH_SCALE
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/       case  FrequencyBand900 :
/*MT6256RF*/       {
/*MT6256RF*/          if( arfcn<=124 )
/*MT6256RF*/          {  freq=4450+arfcn+225;  }
/*MT6256RF*/          else
/*MT6256RF*/          {  freq=4450+(arfcn-1024)+225;  }
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/       case  FrequencyBand1800 :
/*MT6256RF*/       {
/*MT6256RF*/          freq=8551+(arfcn-512)+475;
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/       case  FrequencyBand1900 :
/*MT6256RF*/       {
/*MT6256RF*/          freq=9251+(arfcn-512)+400;
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/       default :
/*MT6256RF*/       {
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/    }
/*MT6256RF*/
/*MT6256RF*/    return freq;
/*MT6256RF*/ }
/*MT6256RF*/ /* =========================================================================== */
/*MT6256RF*/
/*MT6256RF*/ unsigned short L1D_RF_ARFCN_CH_to_TxFreq( int rf_band, int arfcn )
/*MT6256RF*/ {
/*MT6256RF*/    unsigned short freq=4450;
/*MT6256RF*/    switch( rf_band )
/*MT6256RF*/    {
/*MT6256RF*/       case  FrequencyBand850 :
/*MT6256RF*/       {
/*MT6256RF*/          freq=4121+(arfcn-128);     //freq = f_ch*SYNTH_SCALE
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/       case  FrequencyBand900 :
/*MT6256RF*/       {
/*MT6256RF*/          if( arfcn<=124 )
/*MT6256RF*/          {  freq=4450+arfcn;  }
/*MT6256RF*/          else
/*MT6256RF*/          {  freq=4450+(arfcn-1024);  }
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/       case  FrequencyBand1800 :
/*MT6256RF*/       {
/*MT6256RF*/          freq=8551+(arfcn-512);
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/       case  FrequencyBand1900 :
/*MT6256RF*/       {
/*MT6256RF*/          freq=9251+(arfcn-512);
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/       default :
/*MT6256RF*/       {
/*MT6256RF*/          break;
/*MT6256RF*/       }
/*MT6256RF*/    }
/*MT6256RF*/
/*MT6256RF*/    return freq;
/*MT6256RF*/ }
/*MT6256RF*/ /* =========================================================================== */
#endif

#if IS_RF_SKY74045
/*SKY74045*/
/*SKY74045*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*SKY74045*/ {  int Nfrac=0;
/*SKY74045*/
/*SKY74045*/    switch(rf_band)
/*SKY74045*/    {
/*SKY74045*/       case  FrequencyBand850 :
/*SKY74045*/       {
/*SKY74045*/          if (arfcn <= 180)
/*SKY74045*/          {  if (arfcn <= 136)                             /*  ARFCN :   128~136    */
/*SKY74045*/             {   Nfrac = 3323179 + 96792*(arfcn-128) - ((arfcn-128)>>2) ;
/*SKY74045*/                 *rfN = 0x008538 | (96L<<16);
/*SKY74045*/             }
/*SKY74045*/             else                                          /*  ARFCN :   137~180    */
/*SKY74045*/             {   Nfrac = 96791*(arfcn-137) + ((arfcn-137)>>2) +3 ;
/*SKY74045*/                 *rfN = 0x008538 | (97L<<16);
/*SKY74045*/             }
/*SKY74045*/          }
/*SKY74045*/          else
/*SKY74045*/          {  if (arfcn <= 223)                             /*  ARFCN :   181~223    */
/*SKY74045*/             {  Nfrac = 64528 + 96792*(arfcn-181) - ((arfcn-181)>>2) -3 ;
/*SKY74045*/                *rfN = 0x008538 | (98L<<16);
/*SKY74045*/             }
/*SKY74045*/             else                                          /*  ARFCN :   224~251    */
/*SKY74045*/             {  Nfrac = 32264 + 96792*(arfcn-224) - ((arfcn-224)>>2) -2 ;
/*SKY74045*/                *rfN = 0x008538 | (99L<<16);
/*SKY74045*/             }
/*SKY74045*/          }
/*SKY74045*/          break;
/*SKY74045*/       }
/*SKY74045*/       case  FrequencyBand900 :
/*SKY74045*/       {
/*SKY74045*/          if (arfcn <=113)
/*SKY74045*/          {  if (arfcn<=26)                                /*  ARFCN :   0~26    */
/*SKY74045*/             {  Nfrac = 1613194 + 96792*arfcn - (arfcn>>2) - 2 ;
/*SKY74045*/                *rfN = 0x008538 | (104L<<16);
/*SKY74045*/             }
/*SKY74045*/             else if (arfcn<=69)                           /*  ARFCN :   27~69   */
/*SKY74045*/             {  Nfrac = 32264 + (96792*(arfcn-27)) - ((arfcn-27)>>2) - 3 ;
/*SKY74045*/                *rfN = 0x008538 | (105L<<16);
/*SKY74045*/             }
/*SKY74045*/             else                                          /*  ARFCN :   70~113  */
/*SKY74045*/             {  Nfrac = (96791*(arfcn-70)) + ((arfcn-70)>>1) + 3 ;
/*SKY74045*/                *rfN = 0x008538 | (106L<<16);
/*SKY74045*/             }
/*SKY74045*/          }
/*SKY74045*/          else
/*SKY74045*/          {  if (arfcn<=1007)
/*SKY74045*/             { if (arfcn<=124)                             /*  ARFCN :   114~124 */
/*SKY74045*/               {  Nfrac = 64528 + (96792*(arfcn-114)) - ((arfcn-114)>>2) ;
/*SKY74045*/                  *rfN = 0x008538 | (107L<<16);
/*SKY74045*/               }
/*SKY74045*/               else                                        /*  ARFCN :   975~1007   */
/*SKY74045*/               {  Nfrac = 1064708 + (96792*(arfcn-975)) - ((arfcn-975)>>2) - 2 ;
/*SKY74045*/                  *rfN = 0x008538 | (103L<<16);
/*SKY74045*/               }
/*SKY74045*/             }
/*SKY74045*/             else                                          /*  ARFCN :   1008~1023 */
/*SKY74045*/             {  Nfrac = 64528 + (96792*(arfcn-1008)) - ((arfcn-1008)>>2) - 2 ;
/*SKY74045*/                *rfN = 0x008538 | (104L<<16);
/*SKY74045*/             }
/*SKY74045*/          }
/*SKY74045*/          break;
/*SKY74045*/       }
/*SKY74045*/       case  FrequencyBand1800 :
/*SKY74045*/       {
/*SKY74045*/          if (arfcn<=715)
/*SKY74045*/          {  if(arfcn<=542)                                /*  ARFCN : 512~542  */
/*SKY74045*/             {  Nfrac = 2710166 + (48396*(arfcn-512)) - ((arfcn-512)>>2);
/*SKY74045*/                *rfN = 0x008568 | (100L<<16);
/*SKY74045*/             }
/*SKY74045*/             else if (arfcn<=629)                          /*  ARFCN : 543~629  */
/*SKY74045*/             {  Nfrac = 16132 + (48396*(arfcn-543)) - ((arfcn-543)>>2) +2 ;
/*SKY74045*/                *rfN = 0x008568 | (101L<<16);
/*SKY74045*/             }
/*SKY74045*/             else                                          /*  ARFCN : 630~715  */
/*SKY74045*/             {  Nfrac = 32264 + (48396*(arfcn-630)) - ((arfcn-630)>>2) +2 ;
/*SKY74045*/                *rfN = 0x008568 | (102L<<16);
/*SKY74045*/             }
/*SKY74045*/          }
/*SKY74045*/          else
/*SKY74045*/          {  if (arfcn<=802)                               /*  ARFCN : 716~802  */
/*SKY74045*/             {  Nfrac = (48396*(arfcn-716)) - ((arfcn-716)>>2) +2 ;
/*SKY74045*/                *rfN = 0x008568 | (103L<<16);
/*SKY74045*/             }
/*SKY74045*/             else                                          /*  ARFCN : 803~885  */
/*SKY74045*/             {  Nfrac = 16132 + (48396*(arfcn-803)) - ((arfcn-803)>>2) +2 ;
/*SKY74045*/                *rfN = 0x008568 | (104L<<16);
/*SKY74045*/             }
/*SKY74045*/          }
/*SKY74045*/          break;
/*SKY74045*/       }
/*SKY74045*/       case  FrequencyBand1900 :
/*SKY74045*/       {
/*SKY74045*/          if (arfcn<=697)
/*SKY74045*/          {  if(arfcn<=524)                                /*  ARFCN : 512~524  */
/*SKY74045*/             {  Nfrac = 3597422 + (48396*(arfcn-512)) - ((arfcn-512)>>2) ;
/*SKY74045*/                *rfN = 0x008568 | (107L<<16);
/*SKY74045*/             }
/*SKY74045*/             else if (arfcn<=610)                          /*  ARFCN : 525~610  */
/*SKY74045*/             {  Nfrac = 32264 + (48396*(arfcn-525)) - ((arfcn-525)>>2) +2 ;
/*SKY74045*/                *rfN = 0x008568 | (108L<<16);
/*SKY74045*/             }
/*SKY74045*/             else                                          /*  ARFCN : 611~697  */
/*SKY74045*/             {  Nfrac = (48396*(arfcn-611)) - ((arfcn-611)>>2) +2 ;
/*SKY74045*/                *rfN = 0x008568 | (109L<<16);
/*SKY74045*/             }
/*SKY74045*/          }
/*SKY74045*/          else
/*SKY74045*/          {  if (arfcn<=784)                               /*  ARFCN : 698~784  */
/*SKY74045*/             {  Nfrac = 16132 + (48396*(arfcn-698)) - ((arfcn-698)>>2) +2 ;
/*SKY74045*/                *rfN = 0x008568 | (110L<<16);
/*SKY74045*/             }
/*SKY74045*/             else                                          /*  ARFCN : 785~810  */
/*SKY74045*/             {  Nfrac = 32264 + (48396*(arfcn-785)) - ((arfcn-785)>>2) ;
/*SKY74045*/                *rfN = 0x008568 | (111L<<16);
/*SKY74045*/             }
/*SKY74045*/          }
/*SKY74045*/          break;
/*SKY74045*/       }
/*SKY74045*/       default :
/*SKY74045*/       {
/*SKY74045*/          break;
/*SKY74045*/       }
/*SKY74045*/    }
/*SKY74045*/    *ifN = 0x2 | (Nfrac<<2);
/*SKY74045*/ }
/*SKY74045*/ /* =========================================================================== */
/*SKY74045*/
/*SKY74045*/ char SKY_d_flag = 0;
/*SKY74045*/ char SKY_TXCP = 0;      //tx charge pump current choice
/*SKY74045*/
/*SKY74045*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*SKY74045*/ {  int   Nfrac=0;
/*SKY74045*/
/*SKY74045*/    switch(rf_band)
/*SKY74045*/    {
/*SKY74045*/       case  FrequencyBand850 :
/*SKY74045*/       {
/*SKY74045*/          if (arfcn <= 186)
/*SKY74045*/          {  if (arfcn <= 147)                             /*  ARFCN :   128~147    */
/*SKY74045*/             {   SKY_d_flag = 0x0; //D = 9
/*SKY74045*/                 Nfrac = 2044723 + 108891*(arfcn-128) - ((arfcn-128)>>2) -2 ;
/*SKY74045*/                 *rfN = 0x008538 | (103L<<16);
/*SKY74045*/             }
/*SKY74045*/             else                                          /*  ARFCN :   148~186    */
/*SKY74045*/             {  if ( (arfcn ==166) || (arfcn ==168) )
/*SKY74045*/                {  SKY_d_flag = 0x2; //D = 10
/*SKY74045*/                   Nfrac = 591504 + (arfcn - 166)*107546 ;
/*SKY74045*/                   *rfN = 0x008538 | (103L<<16);
/*SKY74045*/                }
/*SKY74045*/                else
/*SKY74045*/                {  SKY_d_flag = 0x0; //D = 9
/*SKY74045*/                   Nfrac = 28231 + 108891*(arfcn-148) - ((arfcn-148)>>2) -4 ;
/*SKY74045*/                   *rfN = 0x008538 | (104L<<16);
/*SKY74045*/                }
/*SKY74045*/             }
/*SKY74045*/          }
/*SKY74045*/          else
/*SKY74045*/          {
/*SKY74045*/             if (arfcn <= 224)                             /*  ARFCN :   187~224    */
/*SKY74045*/             {  SKY_d_flag = 0x0; //D = 9
/*SKY74045*/                Nfrac = 80660 + 108891*(arfcn-187) - ((arfcn-187)>>2) -4 ;
/*SKY74045*/                *rfN = 0x008538 | (105L<<16);
/*SKY74045*/             }
/*SKY74045*/             else                                          /*  ARFCN :   225~251    */
/*SKY74045*/             {  if ( (arfcn == 243) || (arfcn == 244) )
/*SKY74045*/                {  SKY_d_flag = 0x2; //D = 10
/*SKY74045*/                   Nfrac = 483958 + (arfcn - 243)*107546 ;
/*SKY74045*/                   *rfN = 0x008538 | (105L<<16);
/*SKY74045*/                }
/*SKY74045*/                else
/*SKY74045*/                {  SKY_d_flag = 0x0; //D = 9
/*SKY74045*/                   Nfrac = 24198 + 108891*(arfcn-225) - ((arfcn-225)>>2) -3 ;
/*SKY74045*/                   *rfN = 0x008538 | (106L<<16);
/*SKY74045*/                }
/*SKY74045*/             }
/*SKY74045*/          }
/*SKY74045*/          break;
/*SKY74045*/       }
/*SKY74045*/       case  FrequencyBand900 :
/*SKY74045*/       {
/*SKY74045*/          if(arfcn<=99)
/*SKY74045*/          {  if(arfcn<=54)
/*SKY74045*/             {  if(arfcn<=34)                              /*  ARFCN : 0~34  */
/*SKY74045*/                {  if (arfcn == 18)
/*SKY74045*/                   {  SKY_d_flag = 0x2; //D = 10
/*SKY74045*/                      Nfrac = 268866;
/*SKY74045*/                      *rfN = 0x008538 | (111L<<16);
/*SKY74045*/                   }
/*SKY74045*/                   else
/*SKY74045*/                   {  SKY_d_flag = 0x0; //D = 9
/*SKY74045*/                      Nfrac = 120990 + (108891*arfcn) - (arfcn>>2) -4 ;
/*SKY74045*/                      *rfN = 0x008538 | (112L<<16);
/*SKY74045*/                   }
/*SKY74045*/                }
/*SKY74045*/                else                                       /*  ARFCN : 35~54  */
/*SKY74045*/                {  SKY_d_flag = 0x2; //D = 10
/*SKY74045*/                   Nfrac = 2097152 + (107546*(arfcn-35)) - ((arfcn-35)>>2) ;
/*SKY74045*/                   *rfN = 0x008538 | (111L<<16);
/*SKY74045*/                }
/*SKY74045*/             }
/*SKY74045*/             else
/*SKY74045*/             {  if(arfcn<=90)                              /*  ARFCN : 55~90  */
/*SKY74045*/                {  SKY_d_flag = 0x2; //D = 10
/*SKY74045*/                   Nfrac = 53773 + (107546*(arfcn-55)) - ((arfcn-55)>>2) ;
/*SKY74045*/                   *rfN = 0x008538 | (112L<<16);
/*SKY74045*/                }
/*SKY74045*/                else                                       /*  ARFCN : 91~99  */
/*SKY74045*/                {  SKY_d_flag = 0x1; //D = 11
/*SKY74045*/                   Nfrac = 3236067 + (106471*(arfcn-91)) - ((arfcn-91)>>2) ;
/*SKY74045*/                   *rfN = 0x008538 | (111L<<16);
/*SKY74045*/                }
/*SKY74045*/             }
/*SKY74045*/          }
/*SKY74045*/          else
/*SKY74045*/          {  if(arfcn<=984)
/*SKY74045*/             {  if(arfcn<=124)                             /*  ARFCN : 100~124  */
/*SKY74045*/                {  SKY_d_flag = 0x1; //D = 11
/*SKY74045*/                   Nfrac = (106471*(arfcn-100)) - ((arfcn-100)>>2) ;
/*SKY74045*/                   *rfN = 0x008538 | (112L<<16);
/*SKY74045*/                }
/*SKY74045*/                else                                       /*  ARFCN : 975~984  */
/*SKY74045*/                {  SKY_d_flag = 0x0; //D = 9
/*SKY74045*/                   Nfrac = 3173959 + (108891*(arfcn-975)) - ((arfcn-975)>>2) -1 ;
/*SKY74045*/                   *rfN = 0x008538 | (110L<<16);
/*SKY74045*/                }
/*SKY74045*/             }
/*SKY74045*/             else
/*SKY74045*/             {  if (arfcn == 1023)                         /*  ARFCN : 1023  */
/*SKY74045*/                {  SKY_d_flag = 0x0; //D = 9
/*SKY74045*/                   Nfrac = 12099;
/*SKY74045*/                   *rfN = 0x008538 | (112L<<16);
/*SKY74045*/                }
/*SKY74045*/                else                                       /*  ARFCN : 985~1022  */
/*SKY74045*/                {  SKY_d_flag = 0x0; //D = 9
/*SKY74045*/                   Nfrac = 68561 + (108891*(arfcn-985)) - ((arfcn-985)>>2) -4 ;
/*SKY74045*/                   *rfN = 0x008538 | (111L<<16);
/*SKY74045*/                }
/*SKY74045*/             }
/*SKY74045*/          }
/*SKY74045*/
/*SKY74045*/          /* choose tx cp current */
/*SKY74045*/          if (arfcn<100)
/*SKY74045*/             SKY_TXCP = 0;
/*SKY74045*/          else
/*SKY74045*/             SKY_TXCP = 1;
/*SKY74045*/
/*SKY74045*/          break;
/*SKY74045*/       }
/*SKY74045*/       case  FrequencyBand1800 :
/*SKY74045*/       {
/*SKY74045*/          if (arfcn <= 740)
/*SKY74045*/          {
/*SKY74045*/             if(arfcn<=576)                                  /*  ARFCN : 512~576  */
/*SKY74045*/             {
/*SKY74045*/                if ( (arfcn == 534) || (arfcn == 538) )
/*SKY74045*/                {
/*SKY74045*/                   SKY_d_flag = 0x2; //D = 14
/*SKY74045*/                   Nfrac = 77312 + (arfcn-534)*51135 ;
/*SKY74045*/                   *rfN = 0x008568 | (101L<<16);
/*SKY74045*/                }
/*SKY74045*/                else
/*SKY74045*/                {
/*SKY74045*/                   SKY_d_flag = 0x0; //D = 13
/*SKY74045*/                   Nfrac = 864540 + (51359*(arfcn-512)) - ((arfcn-512)>>2) +2 ;
/*SKY74045*/                   *rfN = 0x008568 | (101L<<16);
/*SKY74045*/                }
/*SKY74045*/             }
/*SKY74045*/             else if (arfcn <= 658)                          /*  ARFCN : 577~658  */
/*SKY74045*/             {
/*SKY74045*/                if ( (arfcn == 618) || (arfcn == 620) )
/*SKY74045*/                {
/*SKY74045*/                   SKY_d_flag = 0x2; //D = 14
/*SKY74045*/                   Nfrac = 178364 + (arfcn-618)*51135 ;
/*SKY74045*/                   *rfN = 0x008568 | (102L<<16);
/*SKY74045*/                }
/*SKY74045*/                else
/*SKY74045*/                {
/*SKY74045*/                   SKY_d_flag = 0x0; //D = 13
/*SKY74045*/                   Nfrac = 8560 + (51359*(arfcn-577)) - ((arfcn-577)>>2) +3 ;
/*SKY74045*/                   *rfN = 0x008568 | (102L<<16);
/*SKY74045*/                }
/*SKY74045*/             }
/*SKY74045*/             else                           /*  ARFCN : 659~740  */
/*SKY74045*/             {
/*SKY74045*/                if ( (arfcn == 697) || (arfcn == 699) || (arfcn == 702) )
/*SKY74045*/                {
/*SKY74045*/                   SKY_d_flag = 0x2; //D = 14
/*SKY74045*/                   Nfrac = 23741 + (arfcn-697)*51135 ;
/*SKY74045*/                   *rfN = 0x008568 | (103L<<16);
/*SKY74045*/                }
/*SKY74045*/                else
/*SKY74045*/                {
/*SKY74045*/                   SKY_d_flag = 0x0; //D = 13
/*SKY74045*/                   Nfrac = 25679 + (51359*(arfcn-659)) - ((arfcn-659)>>2) +3 ;
/*SKY74045*/                   *rfN = 0x008568 | (103L<<16);
/*SKY74045*/                }
/*SKY74045*/             }
/*SKY74045*/          }
/*SKY74045*/          else
/*SKY74045*/          {
/*SKY74045*/             if (arfcn <= 821)                          /*  ARFCN : 741~821  */
/*SKY74045*/             {
/*SKY74045*/                if ( (arfcn == 779) || (arfcn == 783) || (arfcn == 791) )
/*SKY74045*/                {
/*SKY74045*/                   SKY_d_flag = 0x2; //D = 14
/*SKY74045*/                   Nfrac = 22524 + (arfcn-779)*51135 ;
/*SKY74045*/                   *rfN = 0x008568 | (104L<<16);
/*SKY74045*/                }
/*SKY74045*/                else
/*SKY74045*/                {
/*SKY74045*/                   SKY_d_flag = 0x0; //D = 13
/*SKY74045*/                   Nfrac = 42799 + (51359*(arfcn-741)) - ((arfcn-741)>>2) +3 ;
/*SKY74045*/                   *rfN = 0x008568 | (104L<<16);
/*SKY74045*/                }
/*SKY74045*/             }
/*SKY74045*/             else                           /*  ARFCN : 822~885  */
/*SKY74045*/             {
/*SKY74045*/                if (arfcn == 860)
/*SKY74045*/                {
/*SKY74045*/                   SKY_d_flag = 0x2; //D = 14
/*SKY74045*/                   Nfrac = 4164475;
/*SKY74045*/                   *rfN = 0x008568 | (104L<<16);
/*SKY74045*/                }
/*SKY74045*/                else if ( (arfcn == 863) || (arfcn == 865) )
/*SKY74045*/                {
/*SKY74045*/                   SKY_d_flag = 0x2; //D = 14
/*SKY74045*/                   Nfrac = 123577 + (arfcn-863)*51135 ;
/*SKY74045*/                   *rfN = 0x008568 | (105L<<16);
/*SKY74045*/                }
/*SKY74045*/                else
/*SKY74045*/                {
/*SKY74045*/                   SKY_d_flag = 0x0; //D = 13
/*SKY74045*/                   Nfrac = 8560 + (51359*(arfcn-822)) - ((arfcn-822)>>2) +1 ;
/*SKY74045*/                   *rfN = 0x008568 | (105L<<16);
/*SKY74045*/                }
/*SKY74045*/             }
/*SKY74045*/          }
/*SKY74045*/          /* choose tx cp current */
/*SKY74045*/          if (arfcn<661)
/*SKY74045*/             SKY_TXCP = 0;
/*SKY74045*/          else
/*SKY74045*/             SKY_TXCP = 1;
/*SKY74045*/
/*SKY74045*/          break;
/*SKY74045*/       }
/*SKY74045*/       case  FrequencyBand1900 :
/*SKY74045*/       {
/*SKY74045*/          if(arfcn<=652)
/*SKY74045*/          {
/*SKY74045*/             if(arfcn<=570)                                  /*  ARFCN : 512~570  */
/*SKY74045*/             {
/*SKY74045*/                if ( (arfcn == 530) || (arfcn == 532) )
/*SKY74045*/                {  SKY_d_flag = 0x3; //D = 16
/*SKY74045*/                   Nfrac = 2977268 + (arfcn-530)*50776 ;
/*SKY74045*/                   *rfN = 0x008568 | (108L<<16);
/*SKY74045*/                }
/*SKY74045*/                else
/*SKY74045*/                {  SKY_d_flag = 0x2; //D = 14
/*SKY74045*/                   Nfrac = 1192546 + (51135*(arfcn-512)) - ((arfcn-512)>>2) -1 ;
/*SKY74045*/                   *rfN = 0x008568 | (109L<<16);
/*SKY74045*/                }
/*SKY74045*/             }
/*SKY74045*/             else                              /*  ARFCN : 571~652  */
/*SKY74045*/             {
/*SKY74045*/                if ( (arfcn == 609) || (arfcn == 610) || (arfcn == 612) || (arfcn == 614) | (arfcn == 628))
/*SKY74045*/                {  SKY_d_flag = 0x3; //D = 16
/*SKY74045*/                   Nfrac = 2794263 + (arfcn-609)*50776 ;
/*SKY74045*/                   *rfN = 0x008568 | (109L<<16);
/*SKY74045*/                }
/*SKY74045*/                else
/*SKY74045*/                {  SKY_d_flag = 0x2; //D = 14
/*SKY74045*/                   Nfrac = 15219 + (51135*(arfcn-571)) - ((arfcn-571)>>2) -2 ;
/*SKY74045*/                   *rfN = 0x008568 | (110L<<16);
/*SKY74045*/                }
/*SKY74045*/             }
/*SKY74045*/          }
/*SKY74045*/          else
/*SKY74045*/          {
/*SKY74045*/             if(arfcn<=734)                             /*  ARFCN : 653~734  */
/*SKY74045*/             {
/*SKY74045*/                if ( (arfcn == 694) || (arfcn == 696) )
/*SKY74045*/                {  SKY_d_flag = 0x3; //D = 16
/*SKY74045*/                   Nfrac = 2915914 + (arfcn-694)*50776 ;
/*SKY74045*/                   *rfN = 0x008568 | (110L<<16);
/*SKY74045*/                }
/*SKY74045*/                else
/*SKY74045*/                {  SKY_d_flag = 0x2; //D = 14
/*SKY74045*/                   Nfrac = 14001 + (51135*(arfcn-653)) - ((arfcn-653)>>2) -1 ;
/*SKY74045*/                   *rfN = 0x008568 | (111L<<16);
/*SKY74045*/                }
/*SKY74045*/             }
/*SKY74045*/             else                            /*  ARFCN : 735~810  */
/*SKY74045*/             {
/*SKY74045*/                if ( (arfcn == 773) || (arfcn == 774) || (arfcn == 776) || (arfcn == 778) )
/*SKY74045*/                {  SKY_d_flag = 0x3; //D = 16
/*SKY74045*/                   Nfrac = 2732909 + (arfcn-773)*50776 ;
/*SKY74045*/                   *rfN = 0x008568 | (111L<<16);
/*SKY74045*/                }
/*SKY74045*/                else
/*SKY74045*/                {  SKY_d_flag = 0x2; //D = 14
/*SKY74045*/                   Nfrac = 12784 + (51135*(arfcn-735)) - ((arfcn-735)>>2) -2 ;
/*SKY74045*/                   *rfN = 0x008568 | (112L<<16);
/*SKY74045*/                }
/*SKY74045*/             }
/*SKY74045*/          }
/*SKY74045*/
/*SKY74045*/          /* choose tx cp current */
/*SKY74045*/          if (arfcn<611)
/*SKY74045*/             SKY_TXCP = 0;
/*SKY74045*/          else
/*SKY74045*/             SKY_TXCP = 1;
/*SKY74045*/
/*SKY74045*/          break;
/*SKY74045*/       }
/*SKY74045*/       default :
/*SKY74045*/       {
/*SKY74045*/          break;
/*SKY74045*/       }
/*SKY74045*/    }
/*SKY74045*/    *ifN = 0x2 | (Nfrac<<2);
/*SKY74045*/ }
/*SKY74045*/ /* =========================================================================== */
#endif

#if IS_RF_AERO2
/*AERO2*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*AERO2*/ {
/*AERO2*/    int BandInd = (~rf_band )& 0x01; /* 1:GSM/PCS, 0:GSM850/DCS */
/*AERO2*/    *rfN = (BandInd<<16) | (arfcn<<6) | 0x00021L;
/*AERO2*/    *ifN = 0;
/*AERO2*/ }
/*AERO2*/ /* =========================================================================== */
/*AERO2*/
/*AERO2*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*AERO2*/ {
/*AERO2*/    int BandInd = (~rf_band )& 0x01; /* 1:GSM/PCS, 0:GSM850/DCS */
/*AERO2*/    *rfN = (BandInd<<16) | (arfcn<<6) | 0x00021L;
/*AERO2*/    *ifN = 0;
/*AERO2*/ }
/*AERO2*/ /* =========================================================================== */
#endif

#if IS_RF_SKY74137
/*SKY74137*/
/*SKY74137*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*SKY74137*/ {  int Nfrac=0;
/*SKY74137*/
/*SKY74137*/    switch(rf_band)
/*SKY74137*/    {
/*SKY74137*/       case  FrequencyBand850 :
/*SKY74137*/       {
/*SKY74137*/          if (arfcn <= 201)
/*SKY74137*/          {  if (arfcn <= 158)                             /*  ARFCN :   128~158    */
/*SKY74137*/             {   Nfrac = 1226027 + 96792*(arfcn-128) - ((arfcn-128)>>2) -2 ;
/*SKY74137*/                 *rfN = 0xE20000 | (97L<<6);
/*SKY74137*/             }
/*SKY74137*/             else                                          /*  ARFCN :   159~201    */
/*SKY74137*/             {   Nfrac = 32264 + 96791*(arfcn-159) + ((arfcn-159)>>1) +3 ;
/*SKY74137*/                 *rfN = 0xE20000 | (98L<<6);
/*SKY74137*/             }
/*SKY74137*/          }
/*SKY74137*/          else
/*SKY74137*/          {  if (arfcn <= 245)                             /*  ARFCN :   202~245    */
/*SKY74137*/             {  Nfrac = 96792*(arfcn-202) - ((arfcn-202)>>1) +2 ;
/*SKY74137*/                *rfN = 0xE20000 | (99L<<6);
/*SKY74137*/             }
/*SKY74137*/             else                                          /*  ARFCN :   246~251    */
/*SKY74137*/             {  Nfrac = 64528 + 96792*(arfcn-246) - ((arfcn-246)>>2) ;
/*SKY74137*/                *rfN = 0xE20000 | (100L<<6);
/*SKY74137*/             }
/*SKY74137*/          }
/*SKY74137*/          break;
/*SKY74137*/       }
/*SKY74137*/       case  FrequencyBand900 :
/*SKY74137*/       {
/*SKY74137*/          if (arfcn<=91)
/*SKY74137*/          {  if (arfcn<=4)                                /*  ARFCN :   0~4   */
/*SKY74137*/             {  Nfrac = 3710346 + 96792*arfcn - (arfcn>>2) ;
/*SKY74137*/                *rfN = 0xE20000 | (104L<<6);
/*SKY74137*/             }
/*SKY74137*/             else if (arfcn<=48)                          /*  ARFCN :   5~48  */
/*SKY74137*/             {  Nfrac = 0 + (96792*(arfcn-5)) - ((arfcn-5)>>1) +2 ;
/*SKY74137*/                *rfN = 0xE20000 | (105L<<6);
/*SKY74137*/             }
/*SKY74137*/             else                                         /*  ARFCN :  49~91  */
/*SKY74137*/             {  Nfrac = 64528 + (96792*(arfcn-49)) - ((arfcn-49)>>2) -3 ;
/*SKY74137*/                *rfN = 0xE20000 | (106L<<6);
/*SKY74137*/             }
/*SKY74137*/          }
/*SKY74137*/          else
/*SKY74137*/          {  if (arfcn<=985)
/*SKY74137*/             { if (arfcn<=124)                             /*  ARFCN :   92~124 */
/*SKY74137*/               {  Nfrac = 32264 + (96791*(arfcn-92)) + ((arfcn-92)>>1) +2 ;
/*SKY74137*/                  *rfN = 0xE20000 | (107L<<6);
/*SKY74137*/               }
/*SKY74137*/               else                                        /*  ARFCN :   975~985   */
/*SKY74137*/               {  Nfrac = 3161860 + (96792*(arfcn-975)) - ((arfcn-975)>>2) - 1 ;
/*SKY74137*/                  *rfN = 0xE20000 | (103L<<6);
/*SKY74137*/               }
/*SKY74137*/             }
/*SKY74137*/             else                                          /*  ARFCN :   986~1023 */
/*SKY74137*/             {  Nfrac = 32264 + (96792*(arfcn-986)) - ((arfcn-986)>>2) - 2 ;
/*SKY74137*/                *rfN = 0xE20000 | (104L<<6);
/*SKY74137*/             }
/*SKY74137*/          }
/*SKY74137*/          break;
/*SKY74137*/       }
/*SKY74137*/       case  FrequencyBand1800 :
/*SKY74137*/       {
/*SKY74137*/          if (arfcn<=759)
/*SKY74137*/          {  if(arfcn<=585)                                /*  ARFCN : 512~585  */
/*SKY74137*/             {  Nfrac = 613014 + (48396*(arfcn-512)) - ((arfcn-512)>>2) +2 ;
/*SKY74137*/                *rfN = 0xE20000 | (101L<<6);
/*SKY74137*/             }
/*SKY74137*/             else if (arfcn<=672)                          /*  ARFCN : 586~672  */
/*SKY74137*/             {  Nfrac = (48396*(arfcn-586)) - ((arfcn-586)>>2) +2 ;
/*SKY74137*/                *rfN = 0xE20000 | (102L<<6);
/*SKY74137*/             }
/*SKY74137*/             else                                          /*  ARFCN : 673~759  */
/*SKY74137*/             {  Nfrac = 16132 + (48396*(arfcn-673)) - ((arfcn-673)>>2) +2 ;
/*SKY74137*/                *rfN = 0xE20000 | (103L<<6);
/*SKY74137*/             }
/*SKY74137*/          }
/*SKY74137*/          else
/*SKY74137*/          {  if (arfcn<=845)                               /*  ARFCN : 760~845  */
/*SKY74137*/             {  Nfrac = 32264 + (48396*(arfcn-760)) - ((arfcn-760)>>2) +2 ;
/*SKY74137*/                *rfN = 0xE20000 | (104L<<6);
/*SKY74137*/             }
/*SKY74137*/             else                                          /*  ARFCN : 846~885  */
/*SKY74137*/             {  Nfrac = (48396*(arfcn-846)) - ((arfcn-846)>>2) +1 ;
/*SKY74137*/                *rfN = 0xE20000 | (105L<<6);
/*SKY74137*/             }
/*SKY74137*/          }
/*SKY74137*/          break;
/*SKY74137*/       }
/*SKY74137*/       case  FrequencyBand1900 :
/*SKY74137*/       {
/*SKY74137*/          if (arfcn<=654)
/*SKY74137*/          {  if(arfcn<=567)                                /*  ARFCN : 512~567  */
/*SKY74137*/             {  Nfrac = 1500270 + (48396*(arfcn-512)) - ((arfcn-512)>>2) +2 ;
/*SKY74137*/                *rfN = 0xE20000 | (108L<<6);
/*SKY74137*/             }
/*SKY74137*/             else                                          /*  ARFCN : 568~654  */
/*SKY74137*/             {  Nfrac = 16132 + (48396*(arfcn-568)) - ((arfcn-568)>>2) +2 ;
/*SKY74137*/                *rfN = 0xE20000 | (109L<<6);
/*SKY74137*/             }
/*SKY74137*/          }
/*SKY74137*/          else
/*SKY74137*/          {  if (arfcn<=740)                               /*  ARFCN : 655~740  */
/*SKY74137*/             {  Nfrac = 32264 + (48396*(arfcn-655)) - ((arfcn-655)>>2) +2 ;
/*SKY74137*/                *rfN = 0xE20000 | (110L<<6);
/*SKY74137*/             }
/*SKY74137*/             else                                          /*  ARFCN : 741~810  */
/*SKY74137*/             {  Nfrac = (48396*(arfcn-741)) - ((arfcn-741)>>2) +2 ;
/*SKY74137*/                *rfN = 0xE20000 | (111L<<6);
/*SKY74137*/             }
/*SKY74137*/          }
/*SKY74137*/          break;
/*SKY74137*/       }
/*SKY74137*/       default :
/*SKY74137*/       {
/*SKY74137*/          break;
/*SKY74137*/       }
/*SKY74137*/    }
/*SKY74137*/    *ifN = 0x3 | (Nfrac<<2);
/*SKY74137*/ }
/*SKY74137*/ /* =========================================================================== */
/*SKY74137*/
/*SKY74137*/ char SKY_TXCP = 0;      //tx charge pump current choice
/*SKY74137*/
/*SKY74137*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*SKY74137*/ {  int   Nfrac=0;
/*SKY74137*/
/*SKY74137*/    switch(rf_band)
/*SKY74137*/    {
/*SKY74137*/       case  FrequencyBand850 :
/*SKY74137*/       {
/*SKY74137*/          if (arfcn <= 185)
/*SKY74137*/          {  if (arfcn <= 146)                             /*  ARFCN :   128~146    */
/*SKY74137*/             {
/*SKY74137*/                Nfrac = 2147484 + 108407*(arfcn-128) - ((arfcn-128)>>2) -2 ;
/*SKY74137*/                *rfN = 0xE20000 | (103L<<6);
/*SKY74137*/             }
/*SKY74137*/             else                                          /*  ARFCN :   147~185    */
/*SKY74137*/             {
/*SKY74137*/                Nfrac = 12906 + 108407*(arfcn-147) - ((arfcn-147)>>2) -3 ;
/*SKY74137*/                *rfN = 0xE20000 | (104L<<6);
/*SKY74137*/             }
/*SKY74137*/          }
/*SKY74137*/          else
/*SKY74137*/          {
/*SKY74137*/             if (arfcn <= 224)                             /*  ARFCN :   186~224    */
/*SKY74137*/             {
/*SKY74137*/                Nfrac = 46460 + 108407*(arfcn-186) - ((arfcn-186)>>2) -3 ;
/*SKY74137*/                *rfN = 0xE20000 | (105L<<6);
/*SKY74137*/             }
/*SKY74137*/             else                                          /*  ARFCN :   225~251    */
/*SKY74137*/             {
/*SKY74137*/                Nfrac = 80014 + 108407*(arfcn-225) - ((arfcn-225)>>2) -2 ;
/*SKY74137*/                *rfN = 0xE20000 | (106L<<6);
/*SKY74137*/             }
/*SKY74137*/          }
/*SKY74137*/
/*SKY74137*/          SKY_TXCP = 1;
/*SKY74137*/
/*SKY74137*/          break;
/*SKY74137*/       }
/*SKY74137*/       case  FrequencyBand900 :
/*SKY74137*/       {
/*SKY74137*/          if(arfcn<=115)
/*SKY74137*/          {  if(arfcn<=76)
/*SKY74137*/             {  if(arfcn<=38)                              /*  ARFCN : 0~38  */
/*SKY74137*/                {
/*SKY74137*/                   Nfrac = 64528 + (108407*arfcn) - (arfcn>>2) -3 ;
/*SKY74137*/                   *rfN = 0xE20000 | (112L<<6);
/*SKY74137*/                }
/*SKY74137*/                else                                       /*  ARFCN : 39~76  */
/*SKY74137*/                {
/*SKY74137*/                   Nfrac = 98082 + (108407*(arfcn-39)) - ((arfcn-39)>>2) -2 ;
/*SKY74137*/                   *rfN = 0xE20000 | (113L<<6);
/*SKY74137*/                }
/*SKY74137*/             }
/*SKY74137*/             else                                          /*  ARFCN : 77~115  */
/*SKY74137*/             {
/*SKY74137*/                Nfrac = 23230 + (108407*(arfcn-77)) - ((arfcn-77)>>2) -2 ;
/*SKY74137*/                *rfN = 0xE20000 | (114L<<6);
/*SKY74137*/             }
/*SKY74137*/          }
/*SKY74137*/          else
/*SKY74137*/          {  if(arfcn<=984)
/*SKY74137*/             {  if(arfcn<=124)                             /*  ARFCN : 116~124  */
/*SKY74137*/                {
/*SKY74137*/                   Nfrac = 56784 + (108407*(arfcn-116)) - ((arfcn-116)>>2) ;
/*SKY74137*/                   *rfN = 0xE20000 | (115L<<6);
/*SKY74137*/                }
/*SKY74137*/                else                                       /*  ARFCN : 975~984  */
/*SKY74137*/                {
/*SKY74137*/                   Nfrac = 3141211 + (108407*(arfcn-975)) - ((arfcn-975)>>2) -1 ;
/*SKY74137*/                   *rfN = 0xE20000 | (110L<<6);
/*SKY74137*/                }
/*SKY74137*/             }
/*SKY74137*/             else                                          /*  ARFCN : 985~1023 */
/*SKY74137*/             {
/*SKY74137*/                Nfrac = 30973 + (108407*(arfcn-985)) - ((arfcn-985)>>2) -2 ;
/*SKY74137*/                *rfN = 0xE20000 | (111L<<6);
/*SKY74137*/             }
/*SKY74137*/          }
/*SKY74137*/
/*SKY74137*/          SKY_TXCP = 1;
/*SKY74137*/
/*SKY74137*/          break;
/*SKY74137*/       }
/*SKY74137*/       case  FrequencyBand1800 :
/*SKY74137*/       {
/*SKY74137*/          if (arfcn <= 737)
/*SKY74137*/          {
/*SKY74137*/             if(arfcn<=655)
/*SKY74137*/             {  if(arfcn <= 573)                             /*  ARFCN : 512~573  */
/*SKY74137*/                {
/*SKY74137*/                   Nfrac = 1049489 + (51135*(arfcn-512)) + ((arfcn-512)>>2) -2 ;
/*SKY74137*/                   *rfN = 0xE20000 | (101L<<6);
/*SKY74137*/                }
/*SKY74137*/                else                                         /*  ARFCN : 574~655  */
/*SKY74137*/                {
/*SKY74137*/                   Nfrac = 25568 + (51135*(arfcn-574)) + ((arfcn-574)>>2) -2 ;
/*SKY74137*/                   *rfN = 0xE20000 | (102L<<6);
/*SKY74137*/                }
/*SKY74137*/             }
/*SKY74137*/             else                                            /*  ARFCN : 656~737  */
/*SKY74137*/             {
/*SKY74137*/                Nfrac = 24350 + (51135*(arfcn-656)) + ((arfcn-656)>>2) -2 ;
/*SKY74137*/                *rfN = 0xE20000 | (103L<<6);
/*SKY74137*/             }
/*SKY74137*/          }
/*SKY74137*/          else
/*SKY74137*/          {
/*SKY74137*/             if(arfcn <= 819)                               /*  ARFCN : 738~819  */
/*SKY74137*/             {
/*SKY74137*/                Nfrac = 23133 + (51135*(arfcn-738)) + ((arfcn-738)>>2) -2 ;
/*SKY74137*/                *rfN = 0xE20000 | (104L<<6);
/*SKY74137*/             }
/*SKY74137*/             else                                            /*  ARFCN : 820~885  */
/*SKY74137*/             {
/*SKY74137*/                Nfrac = 21915 + (51135*(arfcn-820)) + ((arfcn-820)>>2) -2 ;
/*SKY74137*/                *rfN = 0xE20000 | (105L<<6);
/*SKY74137*/             }
/*SKY74137*/          }
/*SKY74137*/
/*SKY74137*/          SKY_TXCP = 3;
/*SKY74137*/
/*SKY74137*/          break;
/*SKY74137*/       }
/*SKY74137*/       case  FrequencyBand1900 :
/*SKY74137*/       {
/*SKY74137*/          if (arfcn <= 693)
/*SKY74137*/          {
/*SKY74137*/             if(arfcn<=611)
/*SKY74137*/             {  if(arfcn <= 529)                             /*  ARFCN : 512~529  */
/*SKY74137*/                {
/*SKY74137*/                   Nfrac = 3289698 + (51135*(arfcn-512)) + ((arfcn-512)>>2) ;
/*SKY74137*/                   *rfN = 0xE20000 | (109L<<6);
/*SKY74137*/                }
/*SKY74137*/                else                                         /*  ARFCN : 530~611  */
/*SKY74137*/                {
/*SKY74137*/                   Nfrac = 15828 + (51135*(arfcn-530)) + ((arfcn-530)>>2) -2 ;
/*SKY74137*/                   *rfN = 0xE20000 | (110L<<6);
/*SKY74137*/                }
/*SKY74137*/             }
/*SKY74137*/             else                                            /*  ARFCN : 612~693  */
/*SKY74137*/             {
/*SKY74137*/                Nfrac = 14610 + (51135*(arfcn-612)) + ((arfcn-612)>>2) -2 ;
/*SKY74137*/                *rfN = 0xE20000 | (111L<<6);
/*SKY74137*/             }
/*SKY74137*/          }
/*SKY74137*/          else
/*SKY74137*/          {
/*SKY74137*/             if(arfcn <= 775)                               /*  ARFCN : 694~775  */
/*SKY74137*/             {
/*SKY74137*/                Nfrac = 13393 + (51135*(arfcn-694)) + ((arfcn-694)>>2) -2 ;
/*SKY74137*/                *rfN = 0xE20000 | (112L<<6);
/*SKY74137*/             }
/*SKY74137*/             else                                            /*  ARFCN : 820~885  */
/*SKY74137*/             {
/*SKY74137*/                Nfrac = 12175 + (51135*(arfcn-776)) + ((arfcn-776)>>2) ;
/*SKY74137*/                *rfN = 0xE20000 | (113L<<6);
/*SKY74137*/             }
/*SKY74137*/          }
/*SKY74137*/
/*SKY74137*/          SKY_TXCP = 3;
/*SKY74137*/
/*SKY74137*/          break;
/*SKY74137*/       }
/*SKY74137*/       default :
/*SKY74137*/       {
/*SKY74137*/          break;
/*SKY74137*/       }
/*SKY74137*/    }
/*SKY74137*/    *ifN = 0x3 | (Nfrac<<2);
/*SKY74137*/ }
/*SKY74137*/ /* =========================================================================== */
#endif

#if IS_RF_GRF6201
/*GRF6201*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*GRF6201*/{
/*GRF6201*/   unsigned long PC;
/*GRF6201*/   unsigned long SC;
/*GRF6201*/   unsigned long MC;
/*GRF6201*/
/*GRF6201*/   switch(rf_band)
/*GRF6201*/   {
/*GRF6201*/      case FrequencyBand850:
/*GRF6201*/      {
/*GRF6201*/         if (arfcn<=201)
/*GRF6201*/         {
/*GRF6201*/            if (arfcn<=169)
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=136)   /* ARFCN : 128~136 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 16;
/*GRF6201*/                  SC = 5;
/*GRF6201*/                  MC = (unsigned long)( 4065248 - (136-arfcn)*129055 - ((136-arfcn)>>1) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 137~169 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 16;
/*GRF6201*/                  SC = 6;
/*GRF6201*/                  MC = (unsigned long)( 4129776 - (169-arfcn)*129055 - ((169-arfcn)>>1) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/            else            /* ARFCN : 170~201 */
/*GRF6201*/            {
/*GRF6201*/               PC = 16;
/*GRF6201*/               SC = 7;
/*GRF6201*/               MC = (unsigned long)( 4065248 - (201-arfcn)*129055 - ((201-arfcn)>>1) );
/*GRF6201*/            }
/*GRF6201*/         }
/*GRF6201*/         else
/*GRF6201*/         {
/*GRF6201*/            if (arfcn<=234)      /* ARFCN : 202~234 */
/*GRF6201*/            {
/*GRF6201*/               PC = 17;
/*GRF6201*/               SC = 0;
/*GRF6201*/               MC = (unsigned long)( 4129776 - (234-arfcn)*129055 - ((234-arfcn)>>1) );
/*GRF6201*/            }
/*GRF6201*/            else            /* ARFCN : 235~251 */
/*GRF6201*/            {
/*GRF6201*/               PC = 17;
/*GRF6201*/               SC = 1;
/*GRF6201*/               MC = (unsigned long)( 2129416 - (251-arfcn)*129056 + ((251-arfcn)>>1) );
/*GRF6201*/            }
/*GRF6201*/         }
/*GRF6201*/         *rfN = ((MC&0x3E0000L)<<1) | (PC<<13) | (SC<<10) | (0x00L<<8) | (0x02L<<6);   /* MC/PC/SC/Band/Mode */
/*GRF6201*/         *ifN = ((MC&0x1FFFFL)<<7 ) | 0x01L;                                 /* MC/Addr */
/*GRF6201*/
/*GRF6201*/         break;
/*GRF6201*/      }
/*GRF6201*/      case FrequencyBand900:
/*GRF6201*/      {
/*GRF6201*/         if (arfcn<=102)
/*GRF6201*/         {
/*GRF6201*/            if (arfcn<=37)
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=4)   /* ARFCN : 0~4 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 7;
/*GRF6201*/                  MC = (unsigned long)( 4065248 - (4-arfcn)*129055 - ((4-arfcn)>>1) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 5~37 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 18;
/*GRF6201*/                  SC = 0;
/*GRF6201*/                  MC = (unsigned long)( 4129776 - (37-arfcn)*129055 - ((37-arfcn)>>1) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/            else
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=69)   /* ARFCN : 38~69 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 18;
/*GRF6201*/                  SC = 1;
/*GRF6201*/                  MC = (unsigned long)( 4065248 - (69-arfcn)*129055 - ((69-arfcn)>>1) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 70~102 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 18;
/*GRF6201*/                  SC = 2;
/*GRF6201*/                  MC = (unsigned long)( 4129776 - (102-arfcn)*129055 - ((102-arfcn)>>1) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/         }
/*GRF6201*/         else
/*GRF6201*/         {
/*GRF6201*/            if (arfcn<=124)      /* ARFCN : 103~124 */
/*GRF6201*/            {
/*GRF6201*/               PC = 18;
/*GRF6201*/               SC = 3;
/*GRF6201*/               MC = (unsigned long)( 2774693 - (124-arfcn)*129055 - ((124-arfcn)>>1) );
/*GRF6201*/            }
/*GRF6201*/            else
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=996)   /* ARFCN : 975~996 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 6;
/*GRF6201*/                  MC = (unsigned long)( 4129776 - (996-arfcn)*129055 - ((996-arfcn)>>1) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 997~1023 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 7;
/*GRF6201*/                  MC = (unsigned long)( 3419971 - (1023-arfcn)*129056 + ((1023-arfcn)>>1) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/         }
/*GRF6201*/         *rfN = ((MC&0x3E0000L)<<1) | (PC<<13) | (SC<<10) | (0x01L<<8) | (0x02L<<6);   /* MC/PC/SC/Band/Mode */
/*GRF6201*/         *ifN = ((MC&0x1FFFFL)<<7 ) | 0x01L;                                 /* MC/Addr */
/*GRF6201*/
/*GRF6201*/         break;
/*GRF6201*/      }
/*GRF6201*/      case FrequencyBand1800:
/*GRF6201*/      {
/*GRF6201*/         if (arfcn<=715)
/*GRF6201*/         {
/*GRF6201*/            if (arfcn<=585)
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=520)   /* ARFCN : 512~520 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 2;
/*GRF6201*/                  MC = (unsigned long)( 3807137 + (arfcn-515)*64528 - ((arfcn-515)>>2) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 521~585 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 3;
/*GRF6201*/                  MC = (unsigned long)( 2000360 + (arfcn-552)*64528 - ((arfcn-552)>>2) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/            else
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=650)   /* ARFCN : 586~650 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 4;
/*GRF6201*/                  MC = (unsigned long)( 2000360 + (arfcn-617)*64528 - ((arfcn-617)>>2) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 651~715 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 5;
/*GRF6201*/                  MC = (unsigned long)( 2000360 + (arfcn-682)*64528 - ((arfcn-682)>>2) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/         }
/*GRF6201*/         else
/*GRF6201*/         {
/*GRF6201*/            if (arfcn<=845)
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=780)   /* ARFCN : 716~780 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 6;
/*GRF6201*/                  MC = (unsigned long)( 2000360 + (arfcn-747)*64528 - ((arfcn-747)>>2) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 781~845 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 7;
/*GRF6201*/                  MC = (unsigned long)( 2000360 + (arfcn-812)*64528 - ((arfcn-812)>>2) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/            else            /* ARFCN : 846~885 */
/*GRF6201*/            {
/*GRF6201*/               PC = 18;
/*GRF6201*/               SC = 0;
/*GRF6201*/               MC = (unsigned long)( 1226027 + (arfcn-865)*64528 - ((arfcn-865)>>2) );
/*GRF6201*/            }
/*GRF6201*/         }
/*GRF6201*/         *rfN = ((MC&0x3E0000L)<<1) | (PC<<13) | (SC<<10) | (0x02L<<8) | (0x02L<<6);   /* MC/PC/SC/Band/Mode */
/*GRF6201*/         *ifN = ((MC&0x1FFFFL)<<7 ) | 0x01L;                                 /* MC/Addr */
/*GRF6201*/
/*GRF6201*/         break;
/*GRF6201*/      }
/*GRF6201*/      case FrequencyBand1900:
/*GRF6201*/      {
/*GRF6201*/         if (arfcn<=675)
/*GRF6201*/         {
/*GRF6201*/            if (arfcn<=610)
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=545)   /* ARFCN : 512~545 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 18;
/*GRF6201*/                  SC = 4;
/*GRF6201*/                  MC = (unsigned long)( 3032804 + (arfcn-528)*64528 - ((arfcn-528)>>2) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 546~610 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 18;
/*GRF6201*/                  SC = 5;
/*GRF6201*/                  MC = (unsigned long)( 2000360 + (arfcn-577)*64528 - ((arfcn-577)>>2) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/            else            /* ARFCN : 611~675 */
/*GRF6201*/            {
/*GRF6201*/               PC = 18;
/*GRF6201*/               SC = 6;
/*GRF6201*/               MC = (unsigned long)( 2000360 + (arfcn-642)*64528 - ((arfcn-642)>>2) );
/*GRF6201*/            }
/*GRF6201*/         }
/*GRF6201*/         else
/*GRF6201*/         {
/*GRF6201*/            if (arfcn<=805)
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=740)   /* ARFCN : 676~740 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 18;
/*GRF6201*/                  SC = 7;
/*GRF6201*/                  MC = (unsigned long)( 2000360 + (arfcn-707)*64528 - ((arfcn-707)>>2) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 741~805 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 19;
/*GRF6201*/                  SC = 0;
/*GRF6201*/                  MC = (unsigned long)( 2000360 + (arfcn-772)*64528 - ((arfcn-772)>>2) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/            else            /* ARFCN : 806~810 */
/*GRF6201*/            {
/*GRF6201*/               PC = 19;
/*GRF6201*/               SC = 1;
/*GRF6201*/               MC = (unsigned long)( 129055 + (arfcn-808)*64528 - ((arfcn-808)>>2) );
/*GRF6201*/            }
/*GRF6201*/         }
/*GRF6201*/         *rfN = ((MC&0x3E0000L)<<1) | (PC<<13) | (SC<<10) | (0x03L<<8) | (0x02L<<6);   /* MC/PC/SC/Band/Mode */
/*GRF6201*/         *ifN = ((MC&0x1FFFFL)<<7 ) | 0x01L;                                 /* MC/Addr */
/*GRF6201*/
/*GRF6201*/         break;
/*GRF6201*/      }
/*GRF6201*/   }
/*GRF6201*/}
/*GRF6201*//* =========================================================================== */
/*GRF6201*/
/*GRF6201*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*GRF6201*/{
/*GRF6201*/   unsigned long PC;
/*GRF6201*/   unsigned long SC;
/*GRF6201*/   unsigned long MC;
/*GRF6201*/   unsigned long special_ch;
/*GRF6201*/
/*GRF6201*/   special_ch = 0;
/*GRF6201*/   switch(rf_band)
/*GRF6201*/   {
/*GRF6201*/      case FrequencyBand850:
/*GRF6201*/      {
/*GRF6201*/         if (arfcn<=199)
/*GRF6201*/         {
/*GRF6201*/            if (arfcn<=166)
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=134)   /* ARFCN : 128~134 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 15;
/*GRF6201*/                  SC = 6;
/*GRF6201*/                  MC = (unsigned long)( 4129776 - (134-arfcn)*129055 - ((134-arfcn)>>1) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 135~166 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 15;
/*GRF6201*/                  SC = 7;
/*GRF6201*/                  MC = (unsigned long)( 4065248 - (166-arfcn)*129055 - ((166-arfcn)>>1) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/            else            /* ARFCN : 167~199 */
/*GRF6201*/            {
/*GRF6201*/               PC = 16;
/*GRF6201*/               SC = 0;
/*GRF6201*/               MC = (unsigned long)( 4129776 - (199-arfcn)*129055 - ((199-arfcn)>>1) );
/*GRF6201*/            }
/*GRF6201*/         }
/*GRF6201*/         else
/*GRF6201*/         {
/*GRF6201*/            if (arfcn<=231)      /* ARFCN : 200~231 */
/*GRF6201*/            {
/*GRF6201*/               PC = 16;
/*GRF6201*/               SC = 1;
/*GRF6201*/               MC = (unsigned long)( 4065248 - (231-arfcn)*129055 - ((231-arfcn)>>1) );
/*GRF6201*/            }
/*GRF6201*/            else            /* ARFCN : 232~251 */
/*GRF6201*/            {
/*GRF6201*/               PC = 16;
/*GRF6201*/               SC = 2;
/*GRF6201*/               MC = (unsigned long)( 2452055 - (251-arfcn)*129056 + ((251-arfcn)>>1) );
/*GRF6201*/            }
/*GRF6201*/         }
/*GRF6201*/         *rfN = ((MC&0x3E0000L)<<1) | (PC<<13) | (SC<<10) | (0x00L<<8) | (0x03L<<6);   /* MC/PC/SC/Band/Mode */
/*GRF6201*/         *ifN = ((MC&0x1FFFFL)<<7 ) | 0x01L | (0x00L<<24);                     /* MC/Addr/TxCurMag */
/*GRF6201*/
/*GRF6201*/         break;
/*GRF6201*/      }
/*GRF6201*/      case FrequencyBand900:
/*GRF6201*/      {
/*GRF6201*/         if (arfcn<=99)
/*GRF6201*/         {
/*GRF6201*/            if (arfcn<=34)
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=2)   /* ARFCN : 0~2 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 0;
/*GRF6201*/                  MC = (unsigned long)( 4129776 - (2-arfcn)*129055 - ((2-arfcn)>>1) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 3~34 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 1;
/*GRF6201*/                  MC = (unsigned long)( 4065248 - (34-arfcn)*129055 - ((34-arfcn)>>1) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/            else
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=67)   /* ARFCN : 35~67 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 2;
/*GRF6201*/                  MC = (unsigned long)( 4129776 - (67-arfcn)*129055 - ((67-arfcn)>>1) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 68~99 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 3;
/*GRF6201*/                  MC = (unsigned long)( 4065248 - (99-arfcn)*129055 - ((99-arfcn)>>1) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/         }
/*GRF6201*/         else
/*GRF6201*/         {
/*GRF6201*/            if (arfcn<=124)      /* ARFCN : 100~124 */
/*GRF6201*/            {
/*GRF6201*/               PC = 17;
/*GRF6201*/               SC = 4;
/*GRF6201*/               MC = (unsigned long)( 3097332 - (124-arfcn)*129055 - ((124-arfcn)>>1) );
/*GRF6201*/            }
/*GRF6201*/            else
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=993)   /* ARFCN : 975~993 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 16;
/*GRF6201*/                  SC = 7;
/*GRF6201*/                  MC = (unsigned long)( 4065248 - (993-arfcn)*129055 - ((993-arfcn)>>1) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 994~1023 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 0;
/*GRF6201*/                  MC = (unsigned long)( 3742610 - (1023-arfcn)*129056 + ((1023-arfcn)>>1) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/         }
/*GRF6201*/         *rfN = ((MC&0x3E0000L)<<1) | (PC<<13) | (SC<<10) | (0x01L<<8) | (0x03L<<6);   /* MC/PC/SC/Band/Mode */
/*GRF6201*/         *ifN = ((MC&0x1FFFFL)<<7 ) | 0x01L | (0x00L<<24);                     /* MC/Addr/TxCurMag */
/*GRF6201*/
/*GRF6201*/         break;
/*GRF6201*/      }
/*GRF6201*/      case FrequencyBand1800:
/*GRF6201*/      {
/*GRF6201*/         if (arfcn<=735)
/*GRF6201*/         {
/*GRF6201*/            if (arfcn<=605)
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=540)   /* ARFCN : 512~540 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 16;
/*GRF6201*/                  SC = 3;
/*GRF6201*/                  MC = (unsigned long)( 3290915 + (arfcn-527)*64528 - ((arfcn-527)>>2) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 541~605 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 16;
/*GRF6201*/                  SC = 4;
/*GRF6201*/                  MC = (unsigned long)( 2000360 + (arfcn-572)*64528 - ((arfcn-572)>>2) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/            else
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=670)   /* ARFCN : 606~670 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 16;
/*GRF6201*/                  SC = 5;
/*GRF6201*/                  MC = (unsigned long)( 2000360 + (arfcn-637)*64528 - ((arfcn-637)>>2) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 671~735 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 16;
/*GRF6201*/                  SC = 6;
/*GRF6201*/                  MC = (unsigned long)( 2000360 + (arfcn-702)*64528 - ((arfcn-702)>>2) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/         }
/*GRF6201*/         else
/*GRF6201*/         {
/*GRF6201*/            if (arfcn<=865)
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=800)   /* ARFCN : 736~800 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 16;
/*GRF6201*/                  SC = 7;
/*GRF6201*/                  MC = (unsigned long)( 2000360 + (arfcn-767)*64528 - ((arfcn-767)>>2) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 801~865 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 0;
/*GRF6201*/                  MC = (unsigned long)( 2000360 + (arfcn-832)*64528 - ((arfcn-832)>>2) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/            else            /* ARFCN : 866~885 */
/*GRF6201*/            {
/*GRF6201*/               PC = 17;
/*GRF6201*/               SC = 1;
/*GRF6201*/               MC = (unsigned long)( 451694 + (arfcn-873)*64528 - ((arfcn-873)>>2) );
/*GRF6201*/            }
/*GRF6201*/         }
/*GRF6201*/
/*GRF6201*/         /* Special channel */
/*GRF6201*/         if ( ((arfcn>=553) && (arfcn<=562)) ||
/*GRF6201*/             ((arfcn>=615) && (arfcn<=624)) ||
/*GRF6201*/             ((arfcn>=677) && (arfcn<=686)) ||
/*GRF6201*/             ((arfcn>=740) && (arfcn<=748)) ||
/*GRF6201*/             ((arfcn>=802) && (arfcn<=811)) ||
/*GRF6201*/             ((arfcn>=864) && (arfcn<=885)) )
/*GRF6201*/         {
/*GRF6201*/            special_ch = 0x01L;
/*GRF6201*/         }
/*GRF6201*/         *rfN = ((MC&0x3E0000L)<<1) | (PC<<13) | (SC<<10) | (0x02L<<8) | (0x03L<<6);            /* MC/PC/SC/Band/Mode */
/*GRF6201*/         *ifN = ((MC&0x1FFFFL)<<7 ) | (special_ch<<6) | 0x01L | (0x01L<<24) | (special_ch<<26);   /* MC/REV0/Addr/TxCurMag/REV1 */
/*GRF6201*/
/*GRF6201*/         break;
/*GRF6201*/      }
/*GRF6201*/      case FrequencyBand1900:
/*GRF6201*/      {
/*GRF6201*/         if (arfcn<=685)
/*GRF6201*/         {
/*GRF6201*/            if (arfcn<=620)
/*GRF6201*/            {
/*GRF6201*/               if (arfcn<=555)   /* ARFCN : 512~555 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 6;
/*GRF6201*/                  MC = (unsigned long)( 2774693 + (arfcn-534)*64528 - ((arfcn-534)>>2) );
/*GRF6201*/               }
/*GRF6201*/               else         /* ARFCN : 556~620 */
/*GRF6201*/               {
/*GRF6201*/                  PC = 17;
/*GRF6201*/                  SC = 7;
/*GRF6201*/                  MC = (unsigned long)( 2000360 + (arfcn-587)*64528 - ((arfcn-587)>>2) );
/*GRF6201*/               }
/*GRF6201*/            }
/*GRF6201*/            else            /* ARFCN : 621~685 */
/*GRF6201*/            {
/*GRF6201*/               PC = 18;
/*GRF6201*/               SC = 0;
/*GRF6201*/               MC = (unsigned long)( 2000360 + (arfcn-652)*64528 - ((arfcn-652)>>2) );
/*GRF6201*/            }
/*GRF6201*/         }
/*GRF6201*/         else
/*GRF6201*/         {
/*GRF6201*/            if (arfcn<=750)      /* ARFCN : 686~750 */
/*GRF6201*/            {
/*GRF6201*/               PC = 18;
/*GRF6201*/               SC = 1;
/*GRF6201*/               MC = (unsigned long)( 2000360 + (arfcn-717)*64528 - ((arfcn-717)>>2) );
/*GRF6201*/            }
/*GRF6201*/            else            /* ARFCN : 751~810 */
/*GRF6201*/            {
/*GRF6201*/               PC = 18;
/*GRF6201*/               SC = 2;
/*GRF6201*/               MC = (unsigned long)( 2000360 + (arfcn-782)*64528 - ((arfcn-782)>>2) );
/*GRF6201*/            }
/*GRF6201*/         }
/*GRF6201*/
/*GRF6201*/         /* Special channel */
/*GRF6201*/         if ( ((arfcn>=538) && (arfcn<=547)) ||
/*GRF6201*/             ((arfcn>=600) && (arfcn<=609)) ||
/*GRF6201*/             ((arfcn>=663) && (arfcn<=671)) ||
/*GRF6201*/             ((arfcn>=725) && (arfcn<=737)) ||
/*GRF6201*/             ((arfcn>=787) && (arfcn<=796)) )
/*GRF6201*/         {
/*GRF6201*/            special_ch = 0x01L;
/*GRF6201*/         }
/*GRF6201*/         *rfN = ((MC&0x3E0000L)<<1) | (PC<<13) | (SC<<10) | (0x03L<<8) | (0x03L<<6);            /* MC/PC/SC/Band/Mode */
/*GRF6201*/         *ifN = ((MC&0x1FFFFL)<<7 ) | (special_ch<<6) | 0x01L | (0x01L<<24) | (special_ch<<26);   /* MC/REV0/Addr/TxCurMag/REV1 */
/*GRF6201*/
/*GRF6201*/         break;
/*GRF6201*/      }
/*GRF6201*/   }
/*GRF6201*/}
/*GRF6201*//* =========================================================================== */
#endif

#if IS_RF_IRFS3001
/*IRFS3001*/#define IRFS3001_MOD10( _in )  (( (_in*51)+76 ) >> 9);
/*IRFS3001*/
/*IRFS3001*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*IRFS3001*/{
/*IRFS3001*/   unsigned short x1, x2;
/*IRFS3001*/
/*IRFS3001*/   switch(rf_band)
/*IRFS3001*/   {
/*IRFS3001*/      case  FrequencyBand850 :
/*IRFS3001*/      {
/*IRFS3001*/         x1 = (arfcn - 127) << 1;   // x1 = (ARFCN-127)*2
/*IRFS3001*/         x2 = IRFS3001_MOD10( x1 );          // x2 = x1 mod 10
/*IRFS3001*/         *rfN = ( (x2+869) << 10 ) | ( (x1-x2*10) << 6 ) | 0x04;
/*IRFS3001*/         break;
/*IRFS3001*/      }
/*IRFS3001*/      case  FrequencyBand900 :
/*IRFS3001*/      {
/*IRFS3001*/         if( arfcn<125 )// ARFCN = 0~124
/*IRFS3001*/         {
/*IRFS3001*/            x1 = arfcn << 1;           // x1 = ARFCN * 2
/*IRFS3001*/            x2 = IRFS3001_MOD10( x1 );          // x2 = x1 mod 10
/*IRFS3001*/            *rfN = ( (x2+935) << 10 ) | ( (x1-x2*10) << 6 ) | 0x04;
/*IRFS3001*/         }
/*IRFS3001*/         else           // ARFCN = 975~1023
/*IRFS3001*/         {
/*IRFS3001*/            x1 = (arfcn-974) << 1;           // x1 = (ARFCN-974) * 2
/*IRFS3001*/            x2 = IRFS3001_MOD10( x1 );                // x2 = x1 mod 10
/*IRFS3001*/            *rfN = ( (x2+925) << 10 ) | ( (x1-x2*10) << 6 ) | 0x04;
/*IRFS3001*/         }
/*IRFS3001*/         break;
/*IRFS3001*/      }
/*IRFS3001*/      case  FrequencyBand1800 :
/*IRFS3001*/      {
/*IRFS3001*/         if( arfcn<701 )// ARFCN = 512~700
/*IRFS3001*/         {
/*IRFS3001*/            x1 = (arfcn-511) << 1;           // x1 = (ARFCN-511) * 2
/*IRFS3001*/            x2 = IRFS3001_MOD10( x1 );                // x2 = x1 mod 10
/*IRFS3001*/            *rfN = ( (x2+1805) << 10 ) | ( (x1-x2*10) << 6 ) | 0x04;
/*IRFS3001*/         }
/*IRFS3001*/         else           // ARFCN = 701~885
/*IRFS3001*/         {
/*IRFS3001*/            x1 = (arfcn-701) << 1;           // x1 = (ARFCN-701) * 2
/*IRFS3001*/            x2 = IRFS3001_MOD10( x1 );                // x2 = x1 mod 10
/*IRFS3001*/            *rfN = ( (x2+1843) << 10 ) | ( (x1-x2*10) << 6 ) | 0x04;
/*IRFS3001*/         }
/*IRFS3001*/         break;
/*IRFS3001*/      }
/*IRFS3001*/      case  FrequencyBand1900 :
/*IRFS3001*/      {
/*IRFS3001*/         if( arfcn<661 )// ARFCN = 512~660
/*IRFS3001*/         {
/*IRFS3001*/            x1 = (arfcn-511) << 1;           // x1 = (ARFCN-511) * 2
/*IRFS3001*/            x2 = IRFS3001_MOD10( x1 );          // x2 = x1 mod 10
/*IRFS3001*/            *rfN = ( (x2+1930) << 10 ) | ( (x1-x2*10) << 6 ) | 0x04;
/*IRFS3001*/         }
/*IRFS3001*/         else           // ARFCN = 661~810
/*IRFS3001*/         {
/*IRFS3001*/            x1 = (arfcn-661) << 1;           // x1 = (ARFCN-701) * 2
/*IRFS3001*/            x2 = IRFS3001_MOD10( x1 );                // x2 = x1 mod 10
/*IRFS3001*/            *rfN = ( (x2+1960) << 10 ) | ( (x1-x2*10) << 6 ) | 0x04;
/*IRFS3001*/         }
/*IRFS3001*/         break;
/*IRFS3001*/      }
/*IRFS3001*/      default :
/*IRFS3001*/      {
/*IRFS3001*/         break;
/*IRFS3001*/      }
/*IRFS3001*/   }
/*IRFS3001*/
/*IRFS3001*/   *ifN = 0;
/*IRFS3001*/}
/*IRFS3001*//* =========================================================================== */
/*IRFS3001*/
/*IRFS3001*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*IRFS3001*/{
/*IRFS3001*/   unsigned short x1, x2;
/*IRFS3001*/
/*IRFS3001*/   switch(rf_band)
/*IRFS3001*/   {
/*IRFS3001*/      case  FrequencyBand850 :
/*IRFS3001*/      {
/*IRFS3001*/         x1 = (arfcn - 127) << 1;   // x1 = (ARFCN-127)*2
/*IRFS3001*/         x2 = IRFS3001_MOD10( x1 );          // x2 = x1 mod 10
/*IRFS3001*/         *rfN = ( (x2+824) << 10 ) | ( (x1-x2*10) << 6 ) | 0x05;
/*IRFS3001*/         break;
/*IRFS3001*/      }
/*IRFS3001*/      case  FrequencyBand900 :
/*IRFS3001*/      {
/*IRFS3001*/         if( arfcn<125 )// ARFCN = 0~124
/*IRFS3001*/         {
/*IRFS3001*/            x1 = arfcn << 1;           // x1 = ARFCN * 2
/*IRFS3001*/            x2 = IRFS3001_MOD10( x1 );          // x2 = x1 mod 10
/*IRFS3001*/            *rfN = ( (x2+890) << 10 ) | ( (x1-x2*10) << 6 ) | 0x05;
/*IRFS3001*/         }
/*IRFS3001*/         else           // ARFCN = 975~1023
/*IRFS3001*/         {
/*IRFS3001*/            x1 = (arfcn-974) << 1;           // x1 = (ARFCN-974) * 2
/*IRFS3001*/            x2 = IRFS3001_MOD10( x1 );                // x2 = x1 mod 10
/*IRFS3001*/            *rfN = ( (x2+880) << 10 ) | ( (x1-x2*10) << 6 ) | 0x05;
/*IRFS3001*/         }
/*IRFS3001*/         break;
/*IRFS3001*/      }
/*IRFS3001*/      case  FrequencyBand1800 :
/*IRFS3001*/      {
/*IRFS3001*/         if( arfcn<701 )// ARFCN = 512~700
/*IRFS3001*/         {
/*IRFS3001*/            x1 = (arfcn-511) << 1;           // x1 = (ARFCN-511) * 2
/*IRFS3001*/            x2 = IRFS3001_MOD10( x1 );                // x2 = x1 mod 10
/*IRFS3001*/            *rfN = ( (x2+1710) << 10 ) | ( (x1-x2*10) << 6 ) | 0x05;
/*IRFS3001*/         }
/*IRFS3001*/         else           // ARFCN = 701~885
/*IRFS3001*/         {
/*IRFS3001*/            x1 = (arfcn-701) << 1;           // x1 = (ARFCN-701) * 2
/*IRFS3001*/            x2 = IRFS3001_MOD10( x1 );                // x2 = x1 mod 10
/*IRFS3001*/            *rfN = ( (x2+1748) << 10 ) | ( (x1-x2*10) << 6 ) | 0x05;
/*IRFS3001*/         }
/*IRFS3001*/         break;
/*IRFS3001*/      }
/*IRFS3001*/      case  FrequencyBand1900 :
/*IRFS3001*/      {
/*IRFS3001*/         if( arfcn<661 )// ARFCN = 512~660
/*IRFS3001*/         {
/*IRFS3001*/            x1 = (arfcn-511) << 1;           // x1 = (ARFCN-511) * 2
/*IRFS3001*/            x2 = IRFS3001_MOD10( x1 );          // x2 = x1 mod 10
/*IRFS3001*/            *rfN = ( (x2+1850) << 10 ) | ( (x1-x2*10) << 6 ) | 0x05;
/*IRFS3001*/         }
/*IRFS3001*/         else           // ARFCN = 661~810
/*IRFS3001*/         {
/*IRFS3001*/            x1 = (arfcn-661) << 1;           // x1 = (ARFCN-701) * 2
/*IRFS3001*/            x2 = IRFS3001_MOD10( x1 );                // x2 = x1 mod 10
/*IRFS3001*/            *rfN = ( (x2+1880) << 10 ) | ( (x1-x2*10) << 6 ) | 0x05;
/*IRFS3001*/         }
/*IRFS3001*/         break;
/*IRFS3001*/      }
/*IRFS3001*/      default :
/*IRFS3001*/      {
/*IRFS3001*/         break;
/*IRFS3001*/      }
/*IRFS3001*/   }
/*IRFS3001*/
/*IRFS3001*/   *ifN = 0;
/*IRFS3001*/}
/*IRFS3001*//* =========================================================================== */
#endif

#if IS_RF_AD6548
/*AD6548*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*AD6548*/{
/*AD6548*/   switch(rf_band)
/*AD6548*/   {
/*AD6548*/      case  FrequencyBand850 :
/*AD6548*/      {
/*AD6548*/         if(arfcn<=201)
/*AD6548*/         {  if(arfcn<=158)
/*AD6548*/            {                                /* ARFCN : 128~158     */
/*AD6548*/                *rfN = (((arfcn-128)*24 + 304)<<13) | 0x1206L /*(36L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                              /* ARFCN : 159~201     */
/*AD6548*/                *rfN = (((arfcn-159)*24 + 8)<<13) | 0x1286L /*(37L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         else
/*AD6548*/         {  if(arfcn<=245)
/*AD6548*/            {                                /* ARFCN : 202~245     */
/*AD6548*/                *rfN = (((arfcn-202)*24 )<<13) | 0x1306L /*(38L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                              /* ARFCN : 246~251     */
/*AD6548*/                *rfN = (((arfcn-246)*24+16)<<13) | 0x1386L /*(39L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/      case  FrequencyBand900 :
/*AD6548*/      {
/*AD6548*/         if(arfcn<=48)
/*AD6548*/         {  if(arfcn<=4)
/*AD6548*/            {                                /* ARFCN : 0~4     */
/*AD6548*/                *rfN = (((arfcn)*24+920 )<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                              /* ARFCN : 5~48     */
/*AD6548*/                *rfN = (((arfcn-5)*24 )<<13) | 0x1606L /*(44L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         else
/*AD6548*/         {  if(arfcn<=124)
/*AD6548*/            {   if(arfcn<=91)
/*AD6548*/                {                                /* ARFCN : 49~91     */
/*AD6548*/                   *rfN = (((arfcn-49)*24+16)<<13) | 0x1686L /*(45L<<7|0x06L)*/;
/*AD6548*/                }
/*AD6548*/                else
/*AD6548*/                {                                /* ARFCN : 92~124     */
/*AD6548*/                   *rfN = (((arfcn-92)*24+8 )<<13) | 0x1706L /*(46L<<7|0x06L)*/;
/*AD6548*/                }
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {  if(arfcn<=985)
/*AD6548*/                {                                /* ARFCN : 975~985     */
/*AD6548*/                   *rfN = (((arfcn-975)*24+784)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6548*/                }
/*AD6548*/                else
/*AD6548*/                {                                /* ARFCN : 986~1023     */
/*AD6548*/                   *rfN = (((arfcn-986)*24+8 )<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6548*/                }
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/      case  FrequencyBand1800 :
/*AD6548*/      {
/*AD6548*/         if(arfcn<=672)
/*AD6548*/         {  if(arfcn<=585)
/*AD6548*/            {                                /* ARFCN : 512~585     */
/*AD6548*/                *rfN = (((arfcn-512)*12+152)<<13) | 0x1406L /*(40L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                                /* ARFCN : 586~672     */
/*AD6548*/                *rfN = (((arfcn-586)*12)<<13) | 0x1486L /*(41L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         else
/*AD6548*/         {  if(arfcn<=759)
/*AD6548*/            {                                 /* ARFCN : 673~759     */
/*AD6548*/               *rfN = (((arfcn-673)*12+4)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            { if(arfcn<=845)
/*AD6548*/              {                               /* ARFCN : 760~845     */
/*AD6548*/                *rfN = (((arfcn-760)*12+8)<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6548*/              }
/*AD6548*/              else
/*AD6548*/              {                                /* ARFCN : 846~885     */
/*AD6548*/                *rfN = (((arfcn-846)*12)<<13) | 0x1606L /*(44L<<7|0x06L)*/;
/*AD6548*/              }
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/      case  FrequencyBand1900 :
/*AD6548*/      {
/*AD6548*/         if(arfcn<=654)
/*AD6548*/         {  if(arfcn<=567)
/*AD6548*/            {                                /* ARFCN : 512~567     */
/*AD6548*/                *rfN = (((arfcn-512)*12+372)<<13) | 0x1786L /*(47L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                                /* ARFCN : 568~654     */
/*AD6548*/                *rfN = (((arfcn-568)*12+4)<<13) | 0x1806L /*(48L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         else
/*AD6548*/         {  if(arfcn<=740)
/*AD6548*/            {                                /* ARFCN : 655~740     */
/*AD6548*/                *rfN = (((arfcn-655)*12+8)<<13) | 0x1886L /*(49L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                                /* ARFCN : 741~810     */
/*AD6548*/                *rfN = (((arfcn-741)*12)<<13) | 0x1906L /*(50L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/      default :
/*AD6548*/      {
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/   }
/*AD6548*/   *ifN = 0;
/*AD6548*/}
/*AD6548*//* ========================================================================== */
/*AD6548*/
/*AD6548*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*AD6548*/{
/*AD6548*/   switch(rf_band)
/*AD6548*/   {
/*AD6548*/      case  FrequencyBand850 :
/*AD6548*/      {
/*AD6548*/         if(arfcn<=185)
/*AD6548*/         {  if(arfcn<=143)
/*AD6548*/            {                                /* ARFCN : 128~143     */
/*AD6548*/                *rfN = (((arfcn-128)*28+728)<<13) | 0x1106L /*(34L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                                /* ARFCN : 144~185     */
/*AD6548*/                *rfN = (((arfcn-144)*28+6)<<13) | 0x1186L /*(35L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         else
/*AD6548*/         {  if(arfcn<=227)
/*AD6548*/            {                                /* ARFCN : 186~227     */
/*AD6548*/                *rfN = (((arfcn-186)*28+12)<<13) | 0x1206L /*(36L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                              /* ARFCN : 228~251     */
/*AD6548*/                *rfN = (((arfcn-228)*28+18)<<13) | 0x1286L /*(37L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/      case  FrequencyBand900 :
/*AD6548*/      {
/*AD6548*/         if(arfcn<=62)
/*AD6548*/         {  if(arfcn<=21)
/*AD6548*/            {                                /* ARFCN : 0~21     */
/*AD6548*/                *rfN = (((arfcn)*28+580)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                              /* ARFCN : 22~62     */
/*AD6548*/                *rfN = (((arfcn-22)*28+26)<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         else
/*AD6548*/         {  if(arfcn<=124)
/*AD6548*/            {   if(arfcn<=104)
/*AD6548*/                {                                /* ARFCN : 63~104     */
/*AD6548*/                   *rfN = (((arfcn-63)*28+4)<<13) | 0x1606L /*(44L<<7|0x06L)*/;
/*AD6548*/                }
/*AD6548*/                else
/*AD6548*/                {                                /* ARFCN : 105~124     */
/*AD6548*/                   *rfN = (((arfcn-105)*28+10)<<13) | 0x1686L /*(45L<<7|0x06L)*/;
/*AD6548*/                }
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {  if(arfcn<=1003)
/*AD6548*/                {                                /* ARFCN : 975~1003     */
/*AD6548*/                   *rfN = (((arfcn-975)*28+378)<<13) | 0x1486L /*(41L<<7|0x06L)*/;
/*AD6548*/                }
/*AD6548*/                else
/*AD6548*/                {                                /* ARFCN : 1004~1023     */
/*AD6548*/                   *rfN = (((arfcn-1004)*28+20)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6548*/                }
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/      case  FrequencyBand1800 :
/*AD6548*/      {
/*AD6548*/         if(arfcn<=694)
/*AD6548*/         {  if(arfcn<=605)
/*AD6548*/            { if(arfcn<=517)
/*AD6548*/              {                                /* ARFCN : 512~517     */
/*AD6548*/                *rfN = (((arfcn-512)*14+1154)<<13) | 0x1006L /*(32L<<7|0x06L)*/;
/*AD6548*/              }
/*AD6548*/              else
/*AD6548*/              {                                /* ARFCN : 518~605     */
/*AD6548*/                *rfN = (((arfcn-518)*14+3)<<13) | 0x1086L /*(33L<<7|0x06L)*/;
/*AD6548*/              }
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                                  /* ARFCN : 606~694     */
/*AD6548*/                *rfN = (((arfcn-606)*14)<<13) | 0x1106L /*(34L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         else
/*AD6548*/         {  if(arfcn<=782)
/*AD6548*/            {                                  /* ARFCN : 695~782     */
/*AD6548*/               *rfN = (((arfcn-695)*14+11)<<13) | 0x1186L /*(35L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            { if(arfcn<=870)
/*AD6548*/              {                               /* ARFCN : 783~870     */
/*AD6548*/                *rfN = (((arfcn-783)*14+8)<<13) | 0x1206L /*(36L<<7|0x06L)*/;
/*AD6548*/              }
/*AD6548*/              else
/*AD6548*/              {                                /* ARFCN : 871~885     */
/*AD6548*/                *rfN = (((arfcn-871)*14+5)<<13) | 0x1286L /*(37L<<7|0x06L)*/;
/*AD6548*/              }
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/      case  FrequencyBand1900 :
/*AD6548*/      {
/*AD6548*/         if(arfcn<=699)
/*AD6548*/         {  if(arfcn<=611)
/*AD6548*/            { if(arfcn<=523)
/*AD6548*/              {                                /* ARFCN : 512~523     */
/*AD6548*/                *rfN = (((arfcn-512)*14+1074)<<13) | 0x1406L /*(40L<<7|0x06L)*/;
/*AD6548*/              }
/*AD6548*/              else
/*AD6548*/              {                                /* ARFCN : 524~611     */
/*AD6548*/                *rfN = (((arfcn-524)*14+7)<<13) | 0x1486L /*(41L<<7|0x06L)*/;
/*AD6548*/              }
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                                  /* ARFCN : 612~699     */
/*AD6548*/                *rfN = (((arfcn-612)*14+4)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         else
/*AD6548*/         {  if(arfcn<=788)
/*AD6548*/            {                                  /* ARFCN : 700~788     */
/*AD6548*/                *rfN = (((arfcn-700)*14+1)<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/            else
/*AD6548*/            {                                  /* ARFCN : 789~810     */
/*AD6548*/                *rfN = (((arfcn-789)*14+12)<<13) | 0x1606L /*(44L<<7|0x06L)*/;
/*AD6548*/            }
/*AD6548*/         }
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/      default :
/*AD6548*/      {
/*AD6548*/         break;
/*AD6548*/      }
/*AD6548*/   }
/*AD6548*/   *ifN = 0;
/*AD6548*/}
/*AD6548*//* ========================================================================== */
#endif

#if IS_RF_AD6546
/*AD6546*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*AD6546*/{
/*AD6546*/   switch(rf_band)
/*AD6546*/   {
/*AD6546*/      case  FrequencyBand850 :
/*AD6546*/      {
/*AD6546*/         if(arfcn<=201)
/*AD6546*/         {  if(arfcn<=158)
/*AD6546*/            {                                /* ARFCN : 128~158     */
/*AD6546*/                *rfN = (((arfcn-128)*24 + 304)<<13) | 0x1206L /*(36L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                              /* ARFCN : 159~201     */
/*AD6546*/                *rfN = (((arfcn-159)*24 + 8)<<13) | 0x1286L /*(37L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         else
/*AD6546*/         {  if(arfcn<=245)
/*AD6546*/            {                                /* ARFCN : 202~245     */
/*AD6546*/                *rfN = (((arfcn-202)*24 )<<13) | 0x1306L /*(38L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                              /* ARFCN : 246~251     */
/*AD6546*/                *rfN = (((arfcn-246)*24+16)<<13) | 0x1386L /*(39L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/      case  FrequencyBand900 :
/*AD6546*/      {
/*AD6546*/         if(arfcn<=48)
/*AD6546*/         {  if(arfcn<=4)
/*AD6546*/            {                                /* ARFCN : 0~4     */
/*AD6546*/                *rfN = (((arfcn)*24+920 )<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                              /* ARFCN : 5~48     */
/*AD6546*/                *rfN = (((arfcn-5)*24 )<<13) | 0x1606L /*(44L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         else
/*AD6546*/         {  if(arfcn<=124)
/*AD6546*/            {   if(arfcn<=91)
/*AD6546*/                {                                /* ARFCN : 49~91     */
/*AD6546*/                   *rfN = (((arfcn-49)*24+16)<<13) | 0x1686L /*(45L<<7|0x06L)*/;
/*AD6546*/                }
/*AD6546*/                else
/*AD6546*/                {                                /* ARFCN : 92~124     */
/*AD6546*/                   *rfN = (((arfcn-92)*24+8 )<<13) | 0x1706L /*(46L<<7|0x06L)*/;
/*AD6546*/                }
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {  if(arfcn<=985)
/*AD6546*/                {                                /* ARFCN : 975~985     */
/*AD6546*/                   *rfN = (((arfcn-975)*24+784)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6546*/                }
/*AD6546*/                else
/*AD6546*/                {                                /* ARFCN : 986~1023     */
/*AD6546*/                   *rfN = (((arfcn-986)*24+8 )<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6546*/                }
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/      case  FrequencyBand1800 :
/*AD6546*/      {
/*AD6546*/         if(arfcn<=672)
/*AD6546*/         {  if(arfcn<=585)
/*AD6546*/            {                                /* ARFCN : 512~585     */
/*AD6546*/                *rfN = (((arfcn-512)*12+152)<<13) | 0x1406L /*(40L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                                /* ARFCN : 586~672     */
/*AD6546*/                *rfN = (((arfcn-586)*12)<<13) | 0x1486L /*(41L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         else
/*AD6546*/         {  if(arfcn<=759)
/*AD6546*/            {                                 /* ARFCN : 673~759     */
/*AD6546*/               *rfN = (((arfcn-673)*12+4)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            { if(arfcn<=845)
/*AD6546*/              {                               /* ARFCN : 760~845     */
/*AD6546*/                *rfN = (((arfcn-760)*12+8)<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6546*/              }
/*AD6546*/              else
/*AD6546*/              {                                /* ARFCN : 846~885     */
/*AD6546*/                *rfN = (((arfcn-846)*12)<<13) | 0x1606L /*(44L<<7|0x06L)*/;
/*AD6546*/              }
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/      case  FrequencyBand1900 :
/*AD6546*/      {
/*AD6546*/         if(arfcn<=654)
/*AD6546*/         {  if(arfcn<=567)
/*AD6546*/            {                                /* ARFCN : 512~567     */
/*AD6546*/                *rfN = (((arfcn-512)*12+372)<<13) | 0x1786L /*(47L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                                /* ARFCN : 568~654     */
/*AD6546*/                *rfN = (((arfcn-568)*12+4)<<13) | 0x1806L /*(48L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         else
/*AD6546*/         {  if(arfcn<=740)
/*AD6546*/            {                                /* ARFCN : 655~740     */
/*AD6546*/                *rfN = (((arfcn-655)*12+8)<<13) | 0x1886L /*(49L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                                /* ARFCN : 741~810     */
/*AD6546*/                *rfN = (((arfcn-741)*12)<<13) | 0x1906L /*(50L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/      default :
/*AD6546*/      {
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/   }
/*AD6546*/   *ifN = 0;
/*AD6546*/}
/*AD6546*//* ========================================================================== */
/*AD6546*/
/*AD6546*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*AD6546*/{
/*AD6546*/   switch(rf_band)
/*AD6546*/   {
/*AD6546*/      case  FrequencyBand850 :
/*AD6546*/      {
/*AD6546*/         if(arfcn<=185)
/*AD6546*/         {  if(arfcn<=143)
/*AD6546*/            {                                /* ARFCN : 128~143     */
/*AD6546*/                *rfN = (((arfcn-128)*28+728)<<13) | 0x1106L /*(34L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                                /* ARFCN : 144~185     */
/*AD6546*/                *rfN = (((arfcn-144)*28+6)<<13) | 0x1186L /*(35L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         else
/*AD6546*/         {  if(arfcn<=227)
/*AD6546*/            {                                /* ARFCN : 186~227     */
/*AD6546*/                *rfN = (((arfcn-186)*28+12)<<13) | 0x1206L /*(36L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                              /* ARFCN : 228~251     */
/*AD6546*/                *rfN = (((arfcn-228)*28+18)<<13) | 0x1286L /*(37L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/      case  FrequencyBand900 :
/*AD6546*/      {
/*AD6546*/         if(arfcn<=62)
/*AD6546*/         {  if(arfcn<=21)
/*AD6546*/            {                                /* ARFCN : 0~21     */
/*AD6546*/                *rfN = (((arfcn)*28+580)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                              /* ARFCN : 22~62     */
/*AD6546*/                *rfN = (((arfcn-22)*28+26)<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         else
/*AD6546*/         {  if(arfcn<=124)
/*AD6546*/            {   if(arfcn<=104)
/*AD6546*/                {                                /* ARFCN : 63~104     */
/*AD6546*/                   *rfN = (((arfcn-63)*28+4)<<13) | 0x1606L /*(44L<<7|0x06L)*/;
/*AD6546*/                }
/*AD6546*/                else
/*AD6546*/                {                                /* ARFCN : 105~124     */
/*AD6546*/                   *rfN = (((arfcn-105)*28+10)<<13) | 0x1686L /*(45L<<7|0x06L)*/;
/*AD6546*/                }
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {  if(arfcn<=1003)
/*AD6546*/                {                                /* ARFCN : 975~1003     */
/*AD6546*/                   *rfN = (((arfcn-975)*28+378)<<13) | 0x1486L /*(41L<<7|0x06L)*/;
/*AD6546*/                }
/*AD6546*/                else
/*AD6546*/                {                                /* ARFCN : 1004~1023     */
/*AD6546*/                   *rfN = (((arfcn-1004)*28+20)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6546*/                }
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/      case  FrequencyBand1800 :
/*AD6546*/      {
/*AD6546*/         if(arfcn<=694)
/*AD6546*/         {  if(arfcn<=605)
/*AD6546*/            { if(arfcn<=517)
/*AD6546*/              {                                /* ARFCN : 512~517     */
/*AD6546*/                *rfN = (((arfcn-512)*14+1154)<<13) | 0x1006L /*(32L<<7|0x06L)*/;
/*AD6546*/              }
/*AD6546*/              else
/*AD6546*/              {                                /* ARFCN : 518~605     */
/*AD6546*/                *rfN = (((arfcn-518)*14+3)<<13) | 0x1086L /*(33L<<7|0x06L)*/;
/*AD6546*/              }
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                                  /* ARFCN : 606~694     */
/*AD6546*/                *rfN = (((arfcn-606)*14)<<13) | 0x1106L /*(34L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         else
/*AD6546*/         {  if(arfcn<=782)
/*AD6546*/            {                                  /* ARFCN : 695~782     */
/*AD6546*/               *rfN = (((arfcn-695)*14+11)<<13) | 0x1186L /*(35L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            { if(arfcn<=870)
/*AD6546*/              {                               /* ARFCN : 783~870     */
/*AD6546*/                *rfN = (((arfcn-783)*14+8)<<13) | 0x1206L /*(36L<<7|0x06L)*/;
/*AD6546*/              }
/*AD6546*/              else
/*AD6546*/              {                                /* ARFCN : 871~885     */
/*AD6546*/                *rfN = (((arfcn-871)*14+5)<<13) | 0x1286L /*(37L<<7|0x06L)*/;
/*AD6546*/              }
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/      case  FrequencyBand1900 :
/*AD6546*/      {
/*AD6546*/         if(arfcn<=699)
/*AD6546*/         {  if(arfcn<=611)
/*AD6546*/            { if(arfcn<=523)
/*AD6546*/              {                                /* ARFCN : 512~523     */
/*AD6546*/                *rfN = (((arfcn-512)*14+1074)<<13) | 0x1406L /*(40L<<7|0x06L)*/;
/*AD6546*/              }
/*AD6546*/              else
/*AD6546*/              {                                /* ARFCN : 524~611     */
/*AD6546*/                *rfN = (((arfcn-524)*14+7)<<13) | 0x1486L /*(41L<<7|0x06L)*/;
/*AD6546*/              }
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                                  /* ARFCN : 612~699     */
/*AD6546*/                *rfN = (((arfcn-612)*14+4)<<13) | 0x1506L /*(42L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         else
/*AD6546*/         {  if(arfcn<=788)
/*AD6546*/            {                                  /* ARFCN : 700~788     */
/*AD6546*/                *rfN = (((arfcn-700)*14+1)<<13) | 0x1586L /*(43L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/            else
/*AD6546*/            {                                  /* ARFCN : 789~810     */
/*AD6546*/                *rfN = (((arfcn-789)*14+12)<<13) | 0x1606L /*(44L<<7|0x06L)*/;
/*AD6546*/            }
/*AD6546*/         }
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/      default :
/*AD6546*/      {
/*AD6546*/         break;
/*AD6546*/      }
/*AD6546*/   }
/*AD6546*/   *ifN = 0;
/*AD6546*/}
/*AD6546*//* ========================================================================== */
#endif

#if IS_RF_MT6162
/*MT6162*/unsigned long  TX_N_FRAC_THRESHOLD_LB = 7356163; /* 7356163/2^23 = 0.876922965 */
/*MT6162*/unsigned long  TX_N_FRAC_THRESHOLD_HB = 7485219; /* 7485219/2^23 = 0.892307639 */
/*MT6162*/         short AFC_TRx_Offset_Threshold_LB = 30; /* the offset range in LB is -30Hz ~ +30Hz*/
/*MT6162*/         short AFC_TRx_Offset_Threshold_HB = 60; /* the offset range in HB is -60Hz ~ +60Hz*/
/*MT6162*/extern   short AFC_TRx_Offset[5];
/*MT6162*/
/*MT6162*//* rfN : 0x61, SRX_FREQ=>SRX_B[5:0],SRX_A[0] and SRX_FRAC[11:0] */
/*MT6162*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6162*/{
/*MT6162*/   int channelFrequency = 0;
/*MT6162*/   int synthesizerFrequency = 0;
/*MT6162*/   int N_INT;
/*MT6162*/   int N_FRAC;
/*MT6162*/
/*MT6162*/   switch(rf_band)
/*MT6162*/   {
/*MT6162*/      case  FrequencyBand850 :
/*MT6162*/      {  channelFrequency = 8242+2*(arfcn-128)+450; /* 824.2+0.2*(arfcn-128)+45 */
/*MT6162*/         synthesizerFrequency = 4*channelFrequency;
/*MT6162*/
/*MT6162*/         if(arfcn<=201)
/*MT6162*/         {  if(arfcn<=136)
/*MT6162*/            {  /* ARFCN : 128~136 */
/*MT6162*/               *rfN = ((arfcn-128)*32+1792) | (66<<12);
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 137~201 */
/*MT6162*/               *rfN = ((arfcn-137)*32) | (67<<12);
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  /* ARFCN : 202~251 */
/*MT6162*/            *rfN = ((arfcn-202)*32) | (68<<12);
/*MT6162*/         }
/*MT6162*/         break;
/*MT6162*/      }
/*MT6162*/      case  FrequencyBand900 :
/*MT6162*/      {
/*MT6162*/		   if(arfcn<=124)
/*MT6162*/		   {  channelFrequency = 8900+2*(arfcn)+450; /* 890+0.2*(arfcn)+45 */
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  channelFrequency = 8900+2*(arfcn-1024)+450; /* 890+0.2*(arfcn-1024)+45 */
/*MT6162*/         }
/*MT6162*/         synthesizerFrequency = 4*channelFrequency;
/*MT6162*/
/*MT6162*/         if(arfcn<=124)
/*MT6162*/         {  if(arfcn<=69)
/*MT6162*/            {  if(arfcn<=4)
/*MT6162*/               {  /* ARFCN : 0~4 */
/*MT6162*/                  *rfN = ((arfcn)*32+1920) | (71<<12);
/*MT6162*/               }
/*MT6162*/               else
/*MT6162*/               {  /* ARFCN : 5~69 */
/*MT6162*/                  *rfN = ((arfcn-5)*32) | (72<<12);
/*MT6162*/               }
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 70~124 */
/*MT6162*/               *rfN = ((arfcn-70)*32) | (73<<12);
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  /* ARFCN : 975~1023 */
/*MT6162*/            *rfN = ((arfcn-975)*32+352) | (71<<12);
/*MT6162*/         }
/*MT6162*/         break;
/*MT6162*/      }
/*MT6162*/      case  FrequencyBand1800 :
/*MT6162*/      {
/*MT6162*/         channelFrequency = 17102+2*(arfcn-512)+950; /* 1710.2+0.2*(arfcn-512)+95 */
/*MT6162*/         synthesizerFrequency = 2*channelFrequency;
/*MT6162*/
/*MT6162*/         if(arfcn<=715)
/*MT6162*/         {  if(arfcn<=585)
/*MT6162*/            {  /* ARFCN : 512~585 */
/*MT6162*/               *rfN = ((arfcn-512)*16+896) | (69<<12);
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 586~715 */
/*MT6162*/               *rfN = ((arfcn-586)*16) | (70<<12);
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  if(arfcn<=845)
/*MT6162*/            {  /* ARFCN : 716~845 */
/*MT6162*/               *rfN = ((arfcn-716)*16) | (71<<12);
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 846~885 */
/*MT6162*/               *rfN = ((arfcn-846)*16) | (72<<12);
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         break;
/*MT6162*/      }
/*MT6162*/      case  FrequencyBand1900 :
/*MT6162*/      {
/*MT6162*/         channelFrequency = 18502+2*(arfcn-512)+800; /* 1850.2+0.2*(arfcn-512)+80 */
/*MT6162*/         synthesizerFrequency = 2*channelFrequency;
/*MT6162*/
/*MT6162*/         if(arfcn<=740)
/*MT6162*/         {  if(arfcn<=610)
/*MT6162*/            {  /* ARFCN : 512~610 */
/*MT6162*/               *rfN = ((arfcn-512)*16+496) | (74<<12);
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 611~740 */
/*MT6162*/               *rfN = ((arfcn-611)*16) | (75<<12);
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  /* ARFCN : 741~810 */
/*MT6162*/            *rfN = ((arfcn-741)*16) | (76<<12);
/*MT6162*/         }
/*MT6162*/         break;
/*MT6162*/      }
/*MT6162*/   }
/*MT6162*/   N_INT = synthesizerFrequency/520;
/*MT6162*/   N_FRAC = ((synthesizerFrequency-520*N_INT)*2080) / 520;
/*MT6162*/   *rfN = (N_FRAC&0xFFF) | ((N_INT&0x7F)<<12);
/*MT6162*/}
/*MT6162*//* ========================================================================== */
/*MT6162*/
/*MT6162*//* rfN : 0x01, CW1=>N_INT[7:0] and N_FRAC[ 9: 0] */
/*MT6162*//* irN : 0x02, CW2=>               N_FRAC[22:10] */
/*MT6162*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6162*/{
/*MT6162*/   int channelFrequency = 0;
/*MT6162*/   int synthesizerFrequency = 0;
/*MT6162*/   int N_INT;
/*MT6162*/   int N_FRAC;
/*MT6162*/   int TRx_Offset_value;
/*MT6162*/
/*MT6162*/   l1d_rf2.arfcn = arfcn;  //for L1D_RF_SetTxGainWrite()
/*MT6162*/
/*MT6162*/   switch(rf_band)
/*MT6162*/   {
/*MT6162*/      case  FrequencyBand850 :
/*MT6162*/      {
/*MT6162*/         channelFrequency = 8242+2*(arfcn-128); /* 824.2+0.2*(arfcn-128) */
/*MT6162*/         synthesizerFrequency = 4*channelFrequency;
/*MT6162*/
/*MT6162*/         if(arfcn<=199)
/*MT6162*/         {  if(arfcn<=166)
/*MT6162*/            {  if(arfcn<=134)
/*MT6162*/               {  /* ARFCN : 128~134 */
/*MT6162*/                  *rfN = (((arfcn-128)*258111+6710886)&0x3FF) | (126<<10);
/*MT6162*/                  *ifN = (((arfcn-128)*258111+6710886)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/               else
/*MT6162*/               {  /* ARFCN : 135~166 */
/*MT6162*/                  *rfN = (((arfcn-135)*258111+129055)&0x3FF) | (127<<10);
/*MT6162*/                  *ifN = (((arfcn-135)*258111+129055)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 167~199 */
/*MT6162*/               *rfN = (((arfcn-167)*258111)&0x3FF) | (128<<10);
/*MT6162*/               *ifN = (((arfcn-167)*258111)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  if(arfcn<=231)
/*MT6162*/            {  /* ARFCN : 200~231 */
/*MT6162*/               *rfN = (((arfcn-200)*258111+129055)&0x3FF) | (129<<10);
/*MT6162*/               *ifN = (((arfcn-200)*258111+129055)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 232~251 */
/*MT6162*/               *rfN = (((arfcn-232)*258111)&0x3FF) | (130<<10);
/*MT6162*/               *ifN = (((arfcn-232)*258111)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         break;
/*MT6162*/      }
/*MT6162*/      case  FrequencyBand900 :
/*MT6162*/      {  if(arfcn<=124)
/*MT6162*/		   {  channelFrequency = 8900+2*(arfcn); /* 890+0.2*(arfcn) */
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  channelFrequency = 8900+2*(arfcn-1024); /* 890+0.2*(arfcn-1024) */
/*MT6162*/         }
/*MT6162*/         synthesizerFrequency = 4*channelFrequency;
/*MT6162*/
/*MT6162*/         if(arfcn<=124)
/*MT6162*/         {  if(arfcn<=67)
/*MT6162*/            {  if(arfcn<=34)
/*MT6162*/               {  if(arfcn<=2)
/*MT6162*/                  {  /* ARFCN : 0~2 */
/*MT6162*/                     *rfN = (((arfcn-0)*258111+7743330)&0x3FF) | (136<<10);
/*MT6162*/                     *ifN = (((arfcn-0)*258111+7743330)>>10)&0x1FFF;
/*MT6162*/                  }
/*MT6162*/                  else
/*MT6162*/                  {  /* ARFCN : 3~34 */
/*MT6162*/                     *rfN = (((arfcn-3)*258111+129055)&0x3FF) | (137<<10);
/*MT6162*/                     *ifN = (((arfcn-3)*258111+129055)>>10)&0x1FFF;
/*MT6162*/                  }
/*MT6162*/               }
/*MT6162*/               else
/*MT6162*/               {  /* ARFCN : 35~67 */
/*MT6162*/                  *rfN = (((arfcn-35)*258111)&0x3FF) | (138<<10);
/*MT6162*/                  *ifN = (((arfcn-35)*258111)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {	 if(arfcn<=99)
/*MT6162*/               {  /* ARFCN : 68~99 */
/*MT6162*/                  *rfN = (((arfcn-68)*258111+129055)&0x3FF) | (139<<10);
/*MT6162*/                  *ifN = (((arfcn-68)*258111+129055)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/               else
/*MT6162*/               {  /* ARFCN : 100~124 */
/*MT6162*/                  *rfN = (((arfcn-100)*258111)&0x3FF) | (140<<10);
/*MT6162*/                  *ifN = (((arfcn-100)*258111)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  if(arfcn<=993)
/*MT6162*/            {   /* ARFCN : 975~993 */
/*MT6162*/                *rfN = (((arfcn-975)*258111+3484498)&0x3FF) | (135<<10);
/*MT6162*/                *ifN = (((arfcn-975)*258111+3484498)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {   /* ARFCN : 994~1023 */
/*MT6162*/                *rfN = (((arfcn-994)*258111)&0x3FF) | (136<<10);
/*MT6162*/                *ifN = (((arfcn-994)*258111)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         break;
/*MT6162*/      }
/*MT6162*/      case  FrequencyBand1800 :
/*MT6162*/      {
/*MT6162*/         channelFrequency = 17102+2*(arfcn-512); /* 1710.2+0.2*(arfcn-512) */
/*MT6162*/         synthesizerFrequency = 2*channelFrequency;
/*MT6162*/
/*MT6162*/         if(arfcn<=735)
/*MT6162*/         {  if(arfcn<=670)
/*MT6162*/            {  if(arfcn<=605)
/*MT6162*/               {  if(arfcn<=540)
/*MT6162*/                  {  /* ARFCN : 512~540 */
/*MT6162*/                     *rfN = (((arfcn-512)*129055+4645998+(arfcn-512)/2)&0x3FF) | (131<<10);
/*MT6162*/                     *ifN = (((arfcn-512)*129055+4645998+(arfcn-512)/2)>>10)&0x1FFF;
/*MT6162*/                  }
/*MT6162*/                  else
/*MT6162*/                  {  /* ARFCN : 541~605 */
/*MT6162*/                     *rfN = (((arfcn-541)*129055+(arfcn-541)/2)&0x3FF) | (132<<10);
/*MT6162*/                     *ifN = (((arfcn-541)*129055+(arfcn-541)/2)>>10)&0x1FFF;
/*MT6162*/                  }
/*MT6162*/               }
/*MT6162*/               else
/*MT6162*/               {  /* ARFCN : 606~670 */
/*MT6162*/                  *rfN = (((arfcn-606)*129055+(arfcn-606)/2)&0x3FF) | (133<<10);
/*MT6162*/                  *ifN = (((arfcn-606)*129055+(arfcn-606)/2)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {   /* ARFCN : 671~735 */
/*MT6162*/                *rfN = (((arfcn-671)*129055+(arfcn-671)/2)&0x3FF) | (134<<10);
/*MT6162*/                *ifN = (((arfcn-671)*129055+(arfcn-671)/2)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  if(arfcn<=865)
/*MT6162*/            {  if(arfcn<=800)
/*MT6162*/               {  /* ARFCN : 736~800 */
/*MT6162*/                  *rfN = (((arfcn-736)*129055+(arfcn-736)/2)&0x3FF) | (135<<10);
/*MT6162*/                  *ifN = (((arfcn-736)*129055+(arfcn-736)/2)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/               else
/*MT6162*/               {  /* ARFCN : 801~865 */
/*MT6162*/                  *rfN = (((arfcn-801)*129055+(arfcn-801)/2)&0x3FF) | (136<<10);
/*MT6162*/                  *ifN = (((arfcn-801)*129055+(arfcn-801)/2)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 866~885 */
/*MT6162*/               *rfN = (((arfcn-866)*129055+(arfcn-866)/2)&0x3FF) | (137<<10);
/*MT6162*/               *ifN = (((arfcn-866)*129055+(arfcn-866)/2)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         break;
/*MT6162*/      }
/*MT6162*/      case  FrequencyBand1900 :
/*MT6162*/      {
/*MT6162*/         channelFrequency = 18502+2*(arfcn-512); /* 1850.2+0.2*(arfcn-512) */
/*MT6162*/         synthesizerFrequency = 2*channelFrequency;
/*MT6162*/
/*MT6162*/         if(arfcn<=685)
/*MT6162*/         {  if(arfcn<=620)
/*MT6162*/            {  if(arfcn<=555)
/*MT6162*/               {  /* ARFCN : 512~555 */
/*MT6162*/                  *rfN = (((arfcn-512)*129056+2710165-(arfcn-512)/2)&0x3FF) | (142<<10);
/*MT6162*/                  *ifN = (((arfcn-512)*129056+2710165-(arfcn-512)/2)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/               else
/*MT6162*/               {  /* ARFCN : 556~620 */
/*MT6162*/                  *rfN = (((arfcn-556)*129055+(arfcn-556)/2)&0x3FF) | (143<<10);
/*MT6162*/                  *ifN = (((arfcn-556)*129055+(arfcn-556)/2)>>10)&0x1FFF;
/*MT6162*/               }
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {   /* ARFCN : 621~685 */
/*MT6162*/                *rfN = (((arfcn-621)*129055+(arfcn-621)/2)&0x3FF) | (144<<10);
/*MT6162*/                *ifN = (((arfcn-621)*129055+(arfcn-621)/2)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         else
/*MT6162*/         {  if(arfcn<=750)
/*MT6162*/            {  /* ARFCN : 686~750 */
/*MT6162*/               *rfN = (((arfcn-686)*129055+(arfcn-686)/2)&0x3FF) | (145<<10);
/*MT6162*/               *ifN = (((arfcn-686)*129055+(arfcn-686)/2)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/            else
/*MT6162*/            {  /* ARFCN : 751~810 */
/*MT6162*/               *rfN = (((arfcn-751)*129055+(arfcn-751)/2)&0x3FF) | (146<<10);
/*MT6162*/               *ifN = (((arfcn-751)*129055+(arfcn-751)/2)>>10)&0x1FFF;
/*MT6162*/            }
/*MT6162*/         }
/*MT6162*/         break;
/*MT6162*/      }
/*MT6162*/   }
/*MT6162*/   N_INT = synthesizerFrequency/260;
/*MT6162*/   N_FRAC = ((synthesizerFrequency-260*N_INT)<<21) / 65; /* ((synthesizerFrequency-260*N_INT)<<23) / 260 */
/*MT6162*/
/*MT6162*/   if( L1D_RF_Get6162Version() == 1 )
/*MT6162*/   {  /* for OH E1, do nothing */  }
/*MT6162*/   else
/*MT6162*/   {  /* for OH E2 */
/*MT6162*/      l1d_rf2.is_integer = (N_FRAC == 0) ? 1 : 0;
/*MT6162*/      if( rf_band <= FrequencyBand900 )
/*MT6162*/      {  l1d_rf2.is_isotpol = (N_FRAC > TX_N_FRAC_THRESHOLD_LB) ? 1 : 0;  }
/*MT6162*/      else
/*MT6162*/      {  l1d_rf2.is_isotpol = (N_FRAC > TX_N_FRAC_THRESHOLD_HB) ? 1 : 0;  }
/*MT6162*/   }
/*MT6162*/   
/*MT6162*/   if( rf_band <= FrequencyBand900 )
/*MT6162*/   {
/*MT6162*/      if( AFC_TRx_Offset[rf_band] > AFC_TRx_Offset_Threshold_LB )
/*MT6162*/      {  TRx_Offset_value = (int)((AFC_TRx_Offset_Threshold_LB*258111)/200000);  }
/*MT6162*/      else if( AFC_TRx_Offset[rf_band] < (-AFC_TRx_Offset_Threshold_LB) )
/*MT6162*/      {  TRx_Offset_value = (int)(((-AFC_TRx_Offset_Threshold_LB)*258111)/200000);  }
/*MT6162*/      else
/*MT6162*/      {  TRx_Offset_value = (int)((AFC_TRx_Offset[rf_band]*258111)/200000);  }
/*MT6162*/   }
/*MT6162*/   else
/*MT6162*/   {
/*MT6162*/      if( AFC_TRx_Offset[rf_band] > AFC_TRx_Offset_Threshold_HB )
/*MT6162*/      {  TRx_Offset_value = (int)((AFC_TRx_Offset_Threshold_HB*129055)/200000);  }
/*MT6162*/      else if( AFC_TRx_Offset[rf_band] < (-AFC_TRx_Offset_Threshold_HB) )
/*MT6162*/      {  TRx_Offset_value = (int)(((-AFC_TRx_Offset_Threshold_HB)*129055)/200000);  }
/*MT6162*/      else
/*MT6162*/      {  TRx_Offset_value = (int)((AFC_TRx_Offset[rf_band]*129055)/200000);  }
/*MT6162*/   }
/*MT6162*/
/*MT6162*/   if( N_FRAC == 0 )
/*MT6162*/   {
/*MT6162*/      if( TRx_Offset_value >= 0 )
/*MT6162*/      {  N_FRAC += TRx_Offset_value;  }
/*MT6162*/      else
/*MT6162*/      {
/*MT6162*/         N_INT  -= 1;
/*MT6162*/         N_FRAC  = 8388608+TRx_Offset_value; /* 2^23 = 8388608 */
/*MT6162*/      }
/*MT6162*/   }
/*MT6162*/   else
/*MT6162*/   {  N_FRAC += TRx_Offset_value;  }
/*MT6162*/
/*MT6162*/   *rfN = (N_FRAC&0x3FF) | ((N_INT&0xFF)<<10);
/*MT6162*/   *ifN = (N_FRAC>>10)&0x1FFF;
/*MT6162*/}
/*MT6162*//* ========================================================================== */
#endif

#if IS_RF_MT6163
/*MT6163*/  /* rfN : 0x01, CW1=>N_INT[7:0] and N_FRAC[ 9: 0] */
/*MT6163*/  /* irN : 0x02, CW2=>               N_FRAC[22:10] */
/*MT6163*/
/*MT6163*/  #define TX_NEAR_INT_N_FRAC_MIN  167772
/*MT6163*/  #define TX_NEAR_INT_N_FRAC_MAX  754974
/*MT6163*/  #define N_FRAC_DIFF_200KHZ_LB   258111    /* LB N_FRAC difference of neighboring ARFCN (200KHz) */
/*MT6163*/  #define N_FRAC_DIFF_200KHZ_HB   129055    /* HB N_FRAC difference of neighboring ARFCN (200KHz) */
/*MT6163*/  #define N_FRAC_MIN              0
/*MT6163*/  #define N_FRAC_MAX              8388608   /* 2^23 */
/*MT6163*/  #define AFC_TRX_OFFSET_BOUND_LB 30        /* offset range in LB is -30Hz ~ +30Hz */
/*MT6163*/  #define AFC_TRX_OFFSET_BOUND_HB 60        /* offset range in HB is -60Hz ~ +60Hz */
/*MT6163*/  #define CW2_DFM_SDM_IFM_ON_SET  (0x1<<13)
/*MT6163*/
/*MT6163*/  extern short AFC_TRx_Offset[FrequencyBandCount];
/*MT6163*/
/*MT6163*/  static void L1D_RF_ComputeTxPLLFreq( char is_Rx, int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6163*/  {
/*MT6163*/     int   channelFrequency     = 0;
/*MT6163*/     int   synthesizerFrequency = 0;
/*MT6163*/     int   N_INT, N_FRAC, frac_diff;
/*MT6163*/     short trx_offset_bound;
/*MT6163*/     char  int_mask             = 0x1<<is_Rx;   /* bit1: RX, bit0: TX */
/*MT6163*/     unsigned long sdm          = 0;
/*MT6163*/
/*MT6163*/     if( is_Rx )
/*MT6163*/     {  /* Add freq offset of RX/TX at the same ARFCN */
/*MT6163*/        switch( rf_band )
/*MT6163*/        {
/*MT6163*/           case FrequencyBand850:
/*MT6163*/           case FrequencyBand900:
/*MT6163*/           {
/*MT6163*/              channelFrequency = 450;  /* 45 MHz */
/*MT6163*/              break;
/*MT6163*/           }
/*MT6163*/           case FrequencyBand1800:
/*MT6163*/           {
/*MT6163*/              channelFrequency = 950;  /* 95 MHz */
/*MT6163*/              break;
/*MT6163*/           }
/*MT6163*/           case FrequencyBand1900:
/*MT6163*/           {
/*MT6163*/              channelFrequency = 800;  /* 80 MHz */
/*MT6163*/              break;
/*MT6163*/           }
/*MT6163*/        }
/*MT6163*/     }
/*MT6163*/
/*MT6163*/     switch( rf_band )
/*MT6163*/     {
/*MT6163*/        case FrequencyBand850:
/*MT6163*/        {
/*MT6163*/           channelFrequency += (8242 + 2*(arfcn-128));        /*  824.2 + 0.2*(arfcn-128)   */
/*MT6163*/           synthesizerFrequency = 4*channelFrequency;
/*MT6163*/           break;
/*MT6163*/        }
/*MT6163*/        case FrequencyBand900:
/*MT6163*/        {
/*MT6163*/           if(arfcn<=124)
/*MT6163*/           {  channelFrequency += (8900 + 2*(arfcn));      }  /*  890.0 + 0.2*(arfcn)       */
/*MT6163*/           else
/*MT6163*/           {  channelFrequency += (8900 + 2*(arfcn-1024)); }  /*  890.0 + 0.2*(arfcn-1024)  */
/*MT6163*/           synthesizerFrequency = 4*channelFrequency;
/*MT6163*/           break;
/*MT6163*/        }
/*MT6163*/        case FrequencyBand1800:
/*MT6163*/        {
/*MT6163*/           channelFrequency += (17102 + 2*(arfcn-512));       /* 1710.2 + 0.2*(arfcn-512)   */
/*MT6163*/           synthesizerFrequency = 2*channelFrequency;
/*MT6163*/           break;
/*MT6163*/        }
/*MT6163*/        case FrequencyBand1900:
/*MT6163*/        {
/*MT6163*/           channelFrequency += (18502 + 2*(arfcn-512));       /* 1850.2 + 0.2*(arfcn-512)   */
/*MT6163*/           synthesizerFrequency = 2*channelFrequency;
/*MT6163*/           break;
/*MT6163*/        }
/*MT6163*/     }
/*MT6163*/
/*MT6163*/     N_INT = synthesizerFrequency/260;
/*MT6163*/     N_FRAC = ((synthesizerFrequency - 260*N_INT)<<21) / 65;  /* ((synthesizerFrequency-260*N_INT)<<23) / 260 */
/*MT6163*/
/*MT6163*/     /* add TRX offset */
/*MT6163*/     if( is_Rx )
/*MT6163*/     {  /* do nothing for RX */ }
/*MT6163*/     else
/*MT6163*/     {
/*MT6163*/        if( rf_band <= FrequencyBand900 )
/*MT6163*/        {
/*MT6163*/           trx_offset_bound = AFC_TRX_OFFSET_BOUND_LB;
/*MT6163*/           frac_diff        = N_FRAC_DIFF_200KHZ_LB;
/*MT6163*/        }
/*MT6163*/        else
/*MT6163*/        {
/*MT6163*/           trx_offset_bound = AFC_TRX_OFFSET_BOUND_HB;
/*MT6163*/           frac_diff        = N_FRAC_DIFF_200KHZ_HB;
/*MT6163*/        }
/*MT6163*/
/*MT6163*/        if( AFC_TRx_Offset[rf_band] > trx_offset_bound )
/*MT6163*/        {  AFC_TRx_Offset[rf_band] = trx_offset_bound;  }
/*MT6163*/        else if( AFC_TRx_Offset[rf_band] < (-1)*trx_offset_bound )
/*MT6163*/        {  AFC_TRx_Offset[rf_band] = (-1)*trx_offset_bound;  }
/*MT6163*/
/*MT6163*/        N_FRAC += (int)(AFC_TRx_Offset[rf_band]*frac_diff/200000);
/*MT6163*/
/*MT6163*/        if( N_FRAC >= N_FRAC_MAX )
/*MT6163*/        {
/*MT6163*/           N_FRAC -= N_FRAC_MAX;
/*MT6163*/           N_INT++;
/*MT6163*/        }
/*MT6163*/        else if( N_FRAC < N_FRAC_MIN )
/*MT6163*/        {
/*MT6163*/           N_FRAC += N_FRAC_MAX;
/*MT6163*/           N_INT--;
/*MT6163*/        }
/*MT6163*/     }
/*MT6163*/
/*MT6163*/     /* integer channel check */
/*MT6163*/     if( N_FRAC == 0 )
/*MT6163*/     {  l1d_rf2.is_integer |=  int_mask;  }  /* integer */
/*MT6163*/     else
/*MT6163*/     {  l1d_rf2.is_integer &= ~int_mask;  }  /* not integer */
/*MT6163*/
/*MT6163*/     /* near-integer channel check */
/*MT6163*/     if( is_Rx )
/*MT6163*/     {  sdm = (l1d_rf2.is_integer&0x2) ? 0 : CW2_DFM_SDM_IFM_ON_SET;                                    }  /* turn off for integer channels */
/*MT6163*/     else
/*MT6163*/     {  l1d_rf2.is_isotpol = (N_FRAC>TX_NEAR_INT_N_FRAC_MIN && N_FRAC<TX_NEAR_INT_N_FRAC_MAX) ? 1 : 0;  }
/*MT6163*/
/*MT6163*/     *rfN = (N_FRAC&0x3FF) | ((N_INT&0xFF)<<10);
/*MT6163*/     *ifN = (sdm)|((N_FRAC>>10)&0x1FFF);
/*MT6163*/  }
/*MT6163*/  /* ========================================================================== */
/*MT6163*/
/*MT6163*/  void L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6163*/  {
/*MT6163*/     L1D_RF_ComputeTxPLLFreq( 1/*RX*/, rf_band, arfcn, rfN, ifN );
/*MT6163*/  }
/*MT6163*/  /* ========================================================================== */
/*MT6163*/
/*MT6163*/  void L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6163*/  {
/*MT6163*/     l1d_rf2.arfcn = arfcn;  //for L1D_RF_SetTxGainWrite()
/*MT6163*/     L1D_RF_ComputeTxPLLFreq( 0/*TX*/, rf_band, arfcn, rfN, ifN );
/*MT6163*/  }
/*MT6163*/  /* ========================================================================== */
#endif

#if IS_RF_MT6280RF
/*MT6280RF*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6280RF*/ {  long *if_sel = ifN+1;
/*MT6280RF*/    unsigned short Nint =0, CH_freq =0;
/*MT6280RF*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6280RF*/
/*MT6280RF*/    CH_freq = L1D_RF_ARFCN_CH_to_RxFreq( rf_band, arfcn );
/*MT6280RF*/
/*MT6280RF*/    *if_sel = 0;
/*MT6280RF*/    if( rf_band < FrequencyBand1800 )
/*MT6280RF*/       VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);  
/*MT6280RF*/    else
/*MT6280RF*/       VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);  
/*MT6280RF*/
/*MT6280RF*/    Nint  = VCO_freq/(RX_DCXO_FREQ*DLIF_SCALE);
/*MT6280RF*/    //+195/2 is for rounding, 195=13*3*5, 5 is SYNTH_SCALE, 13 and 3 are related to DLIF
/*MT6280RF*/    Nfrac = ( (((VCO_freq-Nint*RX_DCXO_FREQ*DLIF_SCALE)*2080)<<3) + (195)/2 )/195;
/*MT6280RF*/
/*MT6280RF*/    /* CW99,  N_INT[6:0], N_RFC[23:11] */
/*MT6280RF*/    *rfN = BSI_CW( 0x63, ((Nint &0x7F)<<13) | (Nfrac>>11) );
/*MT6280RF*/    /* CW100, N_FRAC[10:0], DITHER_MASK[4:0] */
/*MT6280RF*/    *ifN = BSI_CW( 0x64, ((Nfrac&0x7FF)<<9) | 0x10 );
/*MT6280RF*/    
/*MT6280RF*/ }
/*MT6280RF*/ /* =========================================================================== */
/*MT6280RF*/
/*MT6280RF*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6280RF*/ {
/*MT6280RF*/    unsigned short Nint =0, CH_freq =0;
/*MT6280RF*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6280RF*/    unsigned short DAoffset=0;
/*MT6280RF*/    
/*MT6280RF*/
/*MT6280RF*/    l1d_rf2.arfcn = arfcn;  //for L1D_RF_TxGainSetting
/*MT6280RF*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6280RF*/
/*MT6280RF*/    if( rf_band < FrequencyBand1800 )
/*MT6280RF*/       VCO_freq = 4*CH_freq;  
/*MT6280RF*/    else
/*MT6280RF*/       VCO_freq = 2*CH_freq;  
/*MT6280RF*/
/*MT6280RF*/    Nint  = VCO_freq/TX_DCXO_FREQ;
/*MT6280RF*/    Nfrac = ( ((VCO_freq-Nint*TX_DCXO_FREQ)<<23) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6280RF*/
/*MT6280RF*/    DAoffset = L1D_RF_GetTxDAoffsetSetting( Nint );
/*MT6280RF*/
/*MT6280RF*/    /* CW95, N_INT[7:0], N_RFC[22:11] */
/*MT6280RF*/    *rfN = BSI_CW( 0x5F, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6280RF*/    /* CW96, N_FRAC[10:0], DA_OFFSET[7:0], DI_EN */
/*MT6280RF*/    *ifN = BSI_CW( 0x60, ((Nfrac&0x7FF)<<9) | ((DAoffset&0xFF)<<1) | 0x1);
/*MT6280RF*/
/*MT6280RF*/ }
/*MT6280RF*/ /* =========================================================================== */
/*MT6280RF*/
/*MT6280RF*/ unsigned short L1D_RF_ARFCN_CH_to_RxFreq( int rf_band, int arfcn )
/*MT6280RF*/ {
/*MT6280RF*/    unsigned short freq=4450+225;
/*MT6280RF*/    switch( rf_band )
/*MT6280RF*/    {
/*MT6280RF*/       case  FrequencyBand850 :
/*MT6280RF*/       {
/*MT6280RF*/          freq=4121+(arfcn-128)+225;     //freq = f_ch*SYNTH_SCALE
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/       case  FrequencyBand900 :
/*MT6280RF*/       {
/*MT6280RF*/          if( arfcn<=124 )
/*MT6280RF*/          {  freq=4450+arfcn+225;  }
/*MT6280RF*/          else
/*MT6280RF*/          {  freq=4450+(arfcn-1024)+225;  }
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/       case  FrequencyBand1800 :
/*MT6280RF*/       {
/*MT6280RF*/          freq=8551+(arfcn-512)+475;
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/       case  FrequencyBand1900 :
/*MT6280RF*/       {
/*MT6280RF*/          freq=9251+(arfcn-512)+400;
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/       default :
/*MT6280RF*/       {
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    return freq;
/*MT6280RF*/ }
/*MT6280RF*/ /* =========================================================================== */
/*MT6280RF*/
/*MT6280RF*/ unsigned short L1D_RF_ARFCN_CH_to_TxFreq( int rf_band, int arfcn )
/*MT6280RF*/ {
/*MT6280RF*/    unsigned short freq=4450;
/*MT6280RF*/    switch( rf_band )
/*MT6280RF*/    {
/*MT6280RF*/       case  FrequencyBand850 :
/*MT6280RF*/       {
/*MT6280RF*/          freq=4121+(arfcn-128);     //freq = f_ch*SYNTH_SCALE
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/       case  FrequencyBand900 :
/*MT6280RF*/       {
/*MT6280RF*/          if( arfcn<=124 )
/*MT6280RF*/          {  freq=4450+arfcn;  }
/*MT6280RF*/          else
/*MT6280RF*/          {  freq=4450+(arfcn-1024);  }
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/       case  FrequencyBand1800 :
/*MT6280RF*/       {
/*MT6280RF*/          freq=8551+(arfcn-512);
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/       case  FrequencyBand1900 :
/*MT6280RF*/       {
/*MT6280RF*/          freq=9251+(arfcn-512);
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/       default :
/*MT6280RF*/       {
/*MT6280RF*/          break;
/*MT6280RF*/       }
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    return freq;
/*MT6280RF*/ }
/*MT6280RF*/ /* =========================================================================== */
/*MT6280RF*/
/*MT6280RF*/ unsigned short L1D_RF_GetTxDCOSCACodeTypeSetting(unsigned short Nint, unsigned long  Nfrac)
/*MT6280RF*/ {
/*MT6280RF*/    char segment_tx=3, LUT_num_tx=8, offset_tx=13; // LUT method related parameters
/*MT6280RF*/    unsigned short TXDCO_LUT[8]={1865, 1424, 1067, 774, 534, 331, 160, 13};  // TXDCO LUT
/*MT6280RF*/    short idx, x_axis, code_type;  // code_type value for SCA calibration (code_type > 0)
/*MT6280RF*/
/*MT6280RF*/    /* STX DCO SCA Typical Code LUT */
/*MT6280RF*/	idx = (Nint>>segment_tx)-((short)offset_tx);                                                                                      
/*MT6280RF*/    if(idx<0)                                                                                                                          
/*MT6280RF*/       idx = 0;                                                                                                                          
/*MT6280RF*/    else if(idx>(LUT_num_tx-2))                                                                                                        
/*MT6280RF*/       idx = LUT_num_tx-2;
/*MT6280RF*/
/*MT6280RF*/    x_axis      = ((Nint-((Nint>>segment_tx)<<segment_tx))<<3)+((short)(Nfrac>>20));                                                   
/*MT6280RF*/    code_type   = TXDCO_LUT[idx]+ ((x_axis*(TXDCO_LUT[idx+1]-TXDCO_LUT[idx]))>>(segment_tx+3));
/*MT6280RF*/    code_type <<= 1;
/*MT6280RF*/
/*MT6280RF*/    return code_type;
/*MT6280RF*/ }
/*MT6280RF*/ /* =========================================================================== */
/*MT6280RF*/
/*MT6280RF*/ unsigned short L1D_RF_GetTxDEMChunkSetting(int rf_band, unsigned short Nint)
/*MT6280RF*/ {
/*MT6280RF*/    unsigned short DEM_Chunk_L1;
/*MT6280RF*/    unsigned short OUT_G, OUT_E;
/*MT6280RF*/    char segment_dem=4, LUT_num_dem=4, offset_dem=7;     // LUT method related parameters
/*MT6280RF*/    unsigned short DEM_chunk_G_LUT[4]={15, 10,  7,  5};  // DEM chunk GMSK LUT
/*MT6280RF*/    unsigned short DEM_chunk_E_LUT[4]={69, 46, 33, 24};  // DEM chunk EPSK LUT
/*MT6280RF*/    short idx;
/*MT6280RF*/
/*MT6280RF*/    /* STX DEM CHUNK LUT */
/*MT6280RF*/	idx = (Nint>>segment_dem)-((short)offset_dem);                                                                                      
/*MT6280RF*/    if(idx<0)                                                                                                                          
/*MT6280RF*/       idx = 0;                                                                                                                          
/*MT6280RF*/    else if(idx>(LUT_num_dem-2))                                                                                                        
/*MT6280RF*/       idx = LUT_num_dem-2;                                                                                                                                                               
/*MT6280RF*/
/*MT6280RF*/    OUT_G = DEM_chunk_G_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_G_LUT[idx+1]-DEM_chunk_G_LUT[idx]))>>(segment_dem));
/*MT6280RF*/    OUT_E = DEM_chunk_E_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_E_LUT[idx+1]-DEM_chunk_E_LUT[idx]))>>(segment_dem));
/*MT6280RF*/    
/*MT6280RF*/    if( ( (l1d_rf.tx_mod_type2)^(l1d_rf.tx_mod_type2<<1) ) & 0xE )   // IS_MIXED_MULTISLOT
/*MT6280RF*/    {
/*MT6280RF*/       if( rf_band < FrequencyBand1800 )
/*MT6280RF*/          DEM_Chunk_L1 = ((OUT_E+OUT_G+5)>40) ? (OUT_E+OUT_G+5) : 40; 
/*MT6280RF*/       else
/*MT6280RF*/          DEM_Chunk_L1 = 40;   
/*MT6280RF*/    }
/*MT6280RF*/    else
/*MT6280RF*/    {
/*MT6280RF*/       if( (l1d_rf.tx_mod_type2 != 0) && (rf_band < FrequencyBand1800) )
/*MT6280RF*/          DEM_Chunk_L1 = ((2*OUT_E+6)>40) ? (2*OUT_E+6) : 40; 
/*MT6280RF*/       else
/*MT6280RF*/          DEM_Chunk_L1 = 40;   
/*MT6280RF*/    }
/*MT6280RF*/    return DEM_Chunk_L1;
/*MT6280RF*/ }
/*MT6280RF*/ /* =========================================================================== */
/*MT6280RF*/
/*MT6280RF*/ void L1D_RF_GetTxKDCOCAL2ndSetting(int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6280RF*/ {
/*MT6280RF*/    unsigned short Nint =0, CH_freq =0;
/*MT6280RF*/    unsigned long  Nfrac=0, DCO4G_freq=0;
/*MT6280RF*/    
/*MT6280RF*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6280RF*/
/*MT6280RF*/    if( rf_band < FrequencyBand1800 )
/*MT6280RF*/       DCO4G_freq = 4*CH_freq;  
/*MT6280RF*/    else
/*MT6280RF*/       DCO4G_freq = 2*CH_freq;  
/*MT6280RF*/
/*MT6280RF*/    Nint  = ( (DCO4G_freq<<15) - 64*DCO4G_freq + 64*TX_DCXO_FREQ*92 ) / (TX_DCXO_FREQ<<15);
/*MT6280RF*/    Nfrac = ( ( ( (DCO4G_freq<<15) - 64*DCO4G_freq + 64*TX_DCXO_FREQ*92 - ((Nint*TX_DCXO_FREQ)<<15) )<<8 ) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6280RF*/
/*MT6280RF*/    /* CW97, N_INT1[7:0], N_RFC1[22:11] */
/*MT6280RF*/    *rfN = BSI_CW( 0x61, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6280RF*/    /* CW98, N_FRAC1[10:0], NOFFSET_REV[3:0], STX_DCO_SCAK_NOFFSET[2:0], STX_MMD_SDM_DI_LS[1:0] */
/*MT6280RF*/    *ifN = BSI_CW( 0x62, ((Nfrac&0x7FF)<<9) | 0x00);
/*MT6280RF*/
/*MT6280RF*/ }
/*MT6280RF*/ /* =========================================================================== */
/*MT6280RF*/
/*MT6280RF*/ unsigned short L1D_RF_GetTxDAoffsetSetting(unsigned short Nint)
/*MT6280RF*/ {
/*MT6280RF*/    return (Nint - 10);
/*MT6280RF*/ }
#endif

#if IS_RF_MT6169
/*MT6169*/ //For DLIF mode
/*MT6169*/ char  L1D_RF_Cal_IF_Synth_State( void )
/*MT6169*/ {
   #if IS_W_CANCELLATION_SUPPORT
/*MT6169*/    if( L1D_CheckIfMetaMode() )
/*MT6169*/    {  return l1d_rf.if_state;  }
/*MT6169*/    else
/*MT6169*/    {  return 0;  }
   #else
/*MT6169*/    return 0;
   #endif
/*MT6169*/ }
/*MT6169*/ /* =========================================================================== */
/*MT6169*/
/*MT6169*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6169*/ {  long *if_sel = ifN+1;
/*MT6169*/    unsigned short Nint =0, CH_freq =0;
/*MT6169*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6169*/    unsigned short Nint_spur =0;
/*MT6169*/    unsigned long  Nfrac_spur=0;
/*MT6169*/    unsigned long  frac_spurs_thd0=0, frac_spurs_thd1=0;
/*MT6169*/
/*MT6169*/    unsigned short RG_RXREP_EN        = 1;
/*MT6169*/    unsigned short RG_SRX_REF_SEL     = (SDATA_CW117[rf_band]&0x3);
/*MT6169*/    unsigned short RG_SRX_KVCO_SEL[5] = { 0,  2,  2,  2,  2};
/*MT6169*/    unsigned short RG_SRX_LF_R2[5]    = { 0, 24, 20, 21, 18};
/*MT6169*/    unsigned short FREF_SRX[3]        = {26, 13, 52};
/*MT6169*/    unsigned short multiplier[3]      = {15, 16, 14};
/*MT6169*/    unsigned char  IF_state=0;   //IF_state=0:default, IF_state=1:+IF, IF_state=2:-IF
/*MT6169*/
/*MT6169*/    IF_state = L1D_RF_Cal_IF_Synth_State();
/*MT6169*/
/*MT6169*/    CH_freq = L1D_RF_ARFCN_CH_to_RxFreq( rf_band, arfcn );
/*MT6169*/
/*MT6169*/    if( IF_state != 2 )
/*MT6169*/    {
/*MT6169*/       *if_sel = 0;
/*MT6169*/       if( rf_band < FrequencyBand1800 )
/*MT6169*/       {
/*MT6169*/          VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);  //High-side mixing
/*MT6169*/          frac_spurs_thd0 = 193584;
/*MT6169*/          frac_spurs_thd1 = 8195024;
/*MT6169*/       }
/*MT6169*/       else
/*MT6169*/       {
/*MT6169*/          VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);  //High-side mixing
/*MT6169*/          frac_spurs_thd0 = 96792;
/*MT6169*/          frac_spurs_thd1 = 8291816;
/*MT6169*/       }
/*MT6169*/    }
/*MT6169*/
/*MT6169*/    Nint  = VCO_freq/(FREF_SRX[RG_SRX_REF_SEL]*SYNTH_SCALE*DLIF_SCALE);
/*MT6169*/    //+195/2 is for rounding, 195=13*3*5, 5 is SYNTH_SCALE, 13 and 3 are related to DLIF
/*MT6169*/    Nfrac = ( ((VCO_freq-Nint*FREF_SRX[RG_SRX_REF_SEL]*SYNTH_SCALE*DLIF_SCALE)<<multiplier[RG_SRX_REF_SEL]) + (195)/2 )/195;
/*MT6169*/
/*MT6169*/    Nint_spur  = VCO_freq/(FREF_SRX[0]*SYNTH_SCALE*DLIF_SCALE);
/*MT6169*/    //+195/2 is for rounding, 195=13*3*5, 5 is SYNTH_SCALE, 13 and 3 are related to DLIF
/*MT6169*/    Nfrac_spur = ( ((VCO_freq-Nint_spur*FREF_SRX[0]*SYNTH_SCALE*DLIF_SCALE)<<multiplier[0]) + (195)/2 )/195;
/*MT6169*/
/*MT6169*/    if( IF_state != 1 )
/*MT6169*/    {
/*MT6169*/       // check fractional spurs criterion (for run-time) or IRR state (for IRR calibration)
/*MT6169*/       if( ( Nfrac_spur < frac_spurs_thd0 ) || ( Nfrac_spur > frac_spurs_thd1 ) || ( Nfrac_spur < 4258832 && Nfrac_spur > 4129776 ) || ( IF_state == 2 ) )
/*MT6169*/       {
/*MT6169*/          *if_sel = 1;  //-170k
/*MT6169*/          if( rf_band < FrequencyBand1800 )
/*MT6169*/          {  VCO_freq = 4*(CH_freq*DLIF_SCALE + DLIF);  }  //Low-side mixing
/*MT6169*/          else
/*MT6169*/          {  VCO_freq = 2*(CH_freq*DLIF_SCALE + DLIF);  }  //Low-side mixing
/*MT6169*/
/*MT6169*/          Nint  = VCO_freq/(FREF_SRX[RG_SRX_REF_SEL]*SYNTH_SCALE*DLIF_SCALE);
/*MT6169*/          //+195/2 is for rounding, 195=13*3*5, 5 is SYNTH_SCALE, 13 and 3 are related to DLIF
/*MT6169*/          Nfrac = ( ((VCO_freq-Nint*FREF_SRX[RG_SRX_REF_SEL]*SYNTH_SCALE*DLIF_SCALE)<<multiplier[RG_SRX_REF_SEL]) + (195)/2 )/195;
/*MT6169*/       }
/*MT6169*/    }
/*MT6169*/
/*MT6169*/    /* CW115, N_INT[8:0], N_RFC[22:20], RG_RXREP_EN, RG_SRX_KVCO_SEL[1:0], RG_SRX_LF_R2[4:0] */
/*MT6169*/    *rfN = BSI_CW( 0x73, ((Nint &0x1FF)<<11) | (((Nfrac>>20)&0x7)<<8) | ((RG_RXREP_EN&0x1)<<7) | ((RG_SRX_KVCO_SEL[rf_band]&0x3)<<5) | (RG_SRX_LF_R2[rf_band]&0x1F) );
/*MT6169*/    /* CW116, N_FRAC[19:0] */
/*MT6169*/    *ifN = BSI_CW( 0x74, (Nfrac&0xFFFFF) );
/*MT6169*/ }
/*MT6169*/ /* =========================================================================== */
/*MT6169*/
/*MT6169*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6169*/ {
/*MT6169*/    unsigned short Nint =0, CH_freq =0;
/*MT6169*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6169*/
/*MT6169*/    unsigned short DA_OFFSET_26M  = 10;
/*MT6169*/    unsigned short MMD_SDM_DI_EN  = 0;  //keep POR = 0
/*MT6169*/
/*MT6169*/    l1d_rf2.arfcn = arfcn;  //for L1D_RF_TxGainSetting
/*MT6169*/ #if IS_MIPI_SUPPORT 
/*MT6169*/    if(is_2g_mipi_enable)
/*MT6169*/    {
/*MT6169*/       l1d_mipi.tx_arfcn = arfcn;  //for L1D_RF_TxGainSetting
/*MT6169*/    }
/*MT6169*/ #endif
/*MT6169*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6169*/
/*MT6169*/    if( rf_band < FrequencyBand1800 )
/*MT6169*/       VCO_freq = 4*CH_freq;  
/*MT6169*/    else
/*MT6169*/       VCO_freq = 2*CH_freq;  
/*MT6169*/
/*MT6169*/    Nint    = VCO_freq/TX_DCXO_FREQ;
/*MT6169*/    Nfrac   = ( ((VCO_freq-Nint*TX_DCXO_FREQ)<<23) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6169*/
/*MT6169*/    /* Apply SW dithering no matter it is integer channel or not */
/*MT6169*/    Nfrac   = ( (Nfrac&0x1) == 0 ) ? Nfrac+1 : Nfrac; //always let LSB[0]=1
/*MT6169*/
/*MT6169*/    /* CW169, N_INT[7:0], N_RFC[22:11] */
/*MT6169*/    *rfN = BSI_CW( 0xA9, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6169*/    /* CW170, N_FRAC[10:0], DA_OFFSET[7:0], DI_EN */
/*MT6169*/    *ifN = BSI_CW( 0xAA, ((Nfrac&0x7FF)<<9) | ((DA_OFFSET_26M&0xFF)<<1) | (MMD_SDM_DI_EN&0x1) );
/*MT6169*/
/*MT6169*/ }
/*MT6169*/ /* =========================================================================== */
/*MT6169*/
/*MT6169*/ unsigned short L1D_RF_ARFCN_CH_to_RxFreq( int rf_band, int arfcn )
/*MT6169*/ {
/*MT6169*/    unsigned short freq=4450+225;
/*MT6169*/    switch( rf_band )
/*MT6169*/    {
/*MT6169*/       case  FrequencyBand850 :
/*MT6169*/       {
/*MT6169*/          freq=4121+(arfcn-128)+225;     //freq = f_ch*SYNTH_SCALE
/*MT6169*/          break;
/*MT6169*/       }
/*MT6169*/       case  FrequencyBand900 :
/*MT6169*/       {
/*MT6169*/          if( arfcn<=124 )
/*MT6169*/          {  freq=4450+arfcn+225;  }
/*MT6169*/          else
/*MT6169*/          {  freq=4450+(arfcn-1024)+225;  }
/*MT6169*/          break;
/*MT6169*/       }
/*MT6169*/       case  FrequencyBand1800 :
/*MT6169*/       {
/*MT6169*/          freq=8551+(arfcn-512)+475;
/*MT6169*/          break;
/*MT6169*/       }
/*MT6169*/       case  FrequencyBand1900 :
/*MT6169*/       {
/*MT6169*/          freq=9251+(arfcn-512)+400;
/*MT6169*/          break;
/*MT6169*/       }
/*MT6169*/       default :
/*MT6169*/       {
/*MT6169*/          break;
/*MT6169*/       }
/*MT6169*/    }
/*MT6169*/
/*MT6169*/    return freq;
/*MT6169*/ }
/*MT6169*/ /* =========================================================================== */
/*MT6169*/
/*MT6169*/ unsigned short L1D_RF_ARFCN_CH_to_TxFreq( int rf_band, int arfcn )
/*MT6169*/ {
/*MT6169*/    unsigned short freq=4450;
/*MT6169*/    switch( rf_band )
/*MT6169*/    {
/*MT6169*/       case  FrequencyBand850 :
/*MT6169*/       {
/*MT6169*/          freq=4121+(arfcn-128);     //freq = f_ch*SYNTH_SCALE
/*MT6169*/          break;
/*MT6169*/       }
/*MT6169*/       case  FrequencyBand900 :
/*MT6169*/       {
/*MT6169*/          if( arfcn<=124 )
/*MT6169*/          {  freq=4450+arfcn;  }
/*MT6169*/          else
/*MT6169*/          {  freq=4450+(arfcn-1024);  }
/*MT6169*/          break;
/*MT6169*/       }
/*MT6169*/       case  FrequencyBand1800 :
/*MT6169*/       {
/*MT6169*/          freq=8551+(arfcn-512);
/*MT6169*/          break;
/*MT6169*/       }
/*MT6169*/       case  FrequencyBand1900 :
/*MT6169*/       {
/*MT6169*/          freq=9251+(arfcn-512);
/*MT6169*/          break;
/*MT6169*/       }
/*MT6169*/       default :
/*MT6169*/       {
/*MT6169*/          break;
/*MT6169*/       }
/*MT6169*/    }
/*MT6169*/
/*MT6169*/    return freq;
/*MT6169*/ }
/*MT6169*/ /* =========================================================================== */
/*MT6169*/
/*MT6169*/ unsigned short L1D_RF_GetTxDCOSCACodeTypeSetting(unsigned short Nint, unsigned long  Nfrac)
/*MT6169*/ {
/*MT6169*/    char segment_tx=3, LUT_num_tx=6, offset_tx=15; // LUT method related parameters
/*MT6169*/    signed short TXDCO_LUT[6]={2786, 1986, 1337, 792, 316, -68};  // TXDCO LUT
/*MT6169*/    short idx, x_axis, code_type;  // code_type value for SCA calibration (code_type > 0)
/*MT6169*/
/*MT6169*/    /* STX DCO SCA Typical Code LUT */
/*MT6169*/    idx = (Nint>>segment_tx)-((short)offset_tx);
/*MT6169*/    if(idx<0)
/*MT6169*/       idx = 0;
/*MT6169*/    else if(idx>(LUT_num_tx-2))
/*MT6169*/       idx = LUT_num_tx-2;
/*MT6169*/
/*MT6169*/    x_axis      = ((Nint-((Nint>>segment_tx)<<segment_tx))<<3)+((short)(Nfrac>>20));
/*MT6169*/    code_type   = TXDCO_LUT[idx]+ ((x_axis*(TXDCO_LUT[idx+1]-TXDCO_LUT[idx]))>>(segment_tx+3));
/*MT6169*/
/*MT6169*/    return code_type;
/*MT6169*/ }
/*MT6169*/ /* =========================================================================== */
/*MT6169*/
/*MT6169*/ unsigned short L1D_RF_GetTxDEMChunkSetting(int rf_band, unsigned short Nint)
/*MT6169*/ {
/*MT6169*/    unsigned short DEM_Chunk_L1;
/*MT6169*/    unsigned short OUT_G, OUT_E;
/*MT6169*/    char segment_dem=4, LUT_num_dem=4, offset_dem=7;     // LUT method related parameters
/*MT6169*/    unsigned short DEM_chunk_G_LUT[4]={15, 10,  7,  5};  // DEM chunk GMSK LUT
/*MT6169*/    unsigned short DEM_chunk_E_LUT[4]={69, 46, 33, 24};  // DEM chunk EPSK LUT
/*MT6169*/    short idx;
/*MT6169*/
/*MT6169*/    /* STX DEM CHUNK LUT */
/*MT6169*/	  idx = (Nint>>segment_dem)-((short)offset_dem);                                                                                      
/*MT6169*/    if(idx<0)                                                                                                                          
/*MT6169*/       idx = 0;                                                                                                                          
/*MT6169*/    else if(idx>(LUT_num_dem-2))                                                                                                        
/*MT6169*/       idx = LUT_num_dem-2;                                                                                                                                                               
/*MT6169*/
/*MT6169*/    OUT_G = DEM_chunk_G_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_G_LUT[idx+1]-DEM_chunk_G_LUT[idx]))>>(segment_dem));
/*MT6169*/    OUT_E = DEM_chunk_E_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_E_LUT[idx+1]-DEM_chunk_E_LUT[idx]))>>(segment_dem));
/*MT6169*/    
/*MT6169*/    if( ( (l1d_rf.tx_mod_type2)^(l1d_rf.tx_mod_type2<<1) ) & 0xE )   // IS_MIXED_MULTISLOT
/*MT6169*/    {
/*MT6169*/       if( rf_band < FrequencyBand1800 )
/*MT6169*/          DEM_Chunk_L1 = ((OUT_E+OUT_G+5)>40) ? (OUT_E+OUT_G+5) : 40; 
/*MT6169*/       else
/*MT6169*/          DEM_Chunk_L1 = 40;   
/*MT6169*/    }
/*MT6169*/    else
/*MT6169*/    {
/*MT6169*/       if( (l1d_rf.tx_mod_type2 != 0) && (rf_band < FrequencyBand1800) )
/*MT6169*/          DEM_Chunk_L1 = ((2*OUT_E+6)>40) ? (2*OUT_E+6) : 40; 
/*MT6169*/       else
/*MT6169*/          DEM_Chunk_L1 = 40;   
/*MT6169*/    }
/*MT6169*/    return DEM_Chunk_L1;
/*MT6169*/ }
/*MT6169*/ /* =========================================================================== */
/*MT6169*/
/*MT6169*/ void L1D_RF_GetTxKDCOCAL2ndSetting(int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6169*/ {
/*MT6169*/    unsigned short Nint =0, CH_freq =0;
/*MT6169*/    unsigned long  Nfrac=0, DCO4G_freq=0;
/*MT6169*/    unsigned short KDCO_NCAL = (POR_CW176&(0x3<<6))>>6;
/*MT6169*/    unsigned short NCAL[4] = {64, 96, 16, 32};
/*MT6169*/
/*MT6169*/    unsigned short DCO_SCAK_NOFFSET  = 0; //keep POR = 0
/*MT6169*/    unsigned short MMD_SDM_DI_LS     = 0; //keep POR = 0
/*MT6169*/
/*MT6169*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6169*/
/*MT6169*/    if( rf_band < FrequencyBand1800 )
/*MT6169*/       DCO4G_freq = 4*CH_freq;  
/*MT6169*/    else
/*MT6169*/       DCO4G_freq = 2*CH_freq;  
/*MT6169*/
/*MT6169*/    Nint  = ( (DCO4G_freq<<15) - NCAL[KDCO_NCAL]*DCO4G_freq + NCAL[KDCO_NCAL]*TX_DCXO_FREQ*92 ) / (TX_DCXO_FREQ<<15);
/*MT6169*/    Nfrac = ( ( ( (DCO4G_freq<<15) - NCAL[KDCO_NCAL]*DCO4G_freq + NCAL[KDCO_NCAL]*TX_DCXO_FREQ*92 - ((Nint*TX_DCXO_FREQ)<<15) )<<8 ) )/TX_DCXO_FREQ;  //floor
/*MT6169*/
/*MT6169*/    /* CW171, N_INT1[7:0], N_RFC1[22:11] */
/*MT6169*/    *rfN = BSI_CW( 0x61, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6169*/    /* CW172, N_FRAC1[10:0], NOFFSET_REV[3:0], STX_DCO_SCAK_NOFFSET[2:0], STX_MMD_SDM_DI_LS[1:0] */
/*MT6169*/    *ifN = BSI_CW( 0x62, ((Nfrac&0x7FF)<<9) | ((DCO_SCAK_NOFFSET&0xF)<<2) |(MMD_SDM_DI_LS&0x3) );
/*MT6169*/
/*MT6169*/ }
/*MT6169*/ /* =========================================================================== */
#endif

#if IS_RF_MT6166
/*MT6166*/ //For DLIF mode
/*MT6166*/ void  L1D_RF_Cal_Synthesizer_Params( unsigned short* Nint, unsigned long* Nfrac, unsigned long  VCO_freq )
/*MT6166*/ {
/*MT6166*/    *Nint  = VCO_freq/(RX_DCXO_FREQ*DLIF_SCALE);
/*MT6166*/    //+195/2 is for rounding, 195=13*3*5, 5 is SYNTH_SCALE, 13 and 3 are related to DLIF
/*MT6166*/    *Nfrac = ( ((VCO_freq-*Nint*RX_DCXO_FREQ*DLIF_SCALE)<<15) + (195)/2 )/195;
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ char  L1D_RF_Cal_IF_Synth_State( void )
/*MT6166*/ {
/*MT6166*/ #if IS_W_CANCELLATION_SUPPORT
/*MT6166*/    if( L1D_CheckIfMetaMode() )
/*MT6166*/    {  return l1d_rf.if_state;  }
/*MT6166*/    else
/*MT6166*/    {  return 0;  }
/*MT6166*/ #else
/*MT6166*/    return 0;
/*MT6166*/ #endif                    
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6166*/ {  long *if_sel = ifN+1;
/*MT6166*/    unsigned short Nint =0, CH_freq =0;
/*MT6166*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6166*/    unsigned long  frac_spurs_thd0=0, frac_spurs_thd1=0;
/*MT6166*/    unsigned char  IF_state=0;   //IF_state=0:default, IF_state=1:+IF, IF_state=2:-IF
/*MT6166*/
/*MT6166*/    IF_state = L1D_RF_Cal_IF_Synth_State();
/*MT6166*/
/*MT6166*/    CH_freq = L1D_RF_ARFCN_CH_to_RxFreq( rf_band, arfcn );
/*MT6166*/
/*MT6166*/    if( IF_state != 2 )
/*MT6166*/    {
/*MT6166*/       *if_sel = 0;
/*MT6166*/       l1d_rf.if_sel_Nif_wc = 0;
/*MT6166*/       if( rf_band < FrequencyBand1800 )
/*MT6166*/       {
/*MT6166*/          VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);  //High-side mixing
/*MT6166*/          frac_spurs_thd0 = 193584;
/*MT6166*/          frac_spurs_thd1 = 8195024;
/*MT6166*/       }
/*MT6166*/       else
/*MT6166*/       {
/*MT6166*/          VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);  //High-side mixing
/*MT6166*/          frac_spurs_thd0 = 96792;
/*MT6166*/          frac_spurs_thd1 = 8291816;
/*MT6166*/       }
/*MT6166*/       L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    if( IF_state != 1 )
/*MT6166*/    {
/*MT6166*/       // use +IF channel instead of -IF for IRR calibration 
/*MT6166*/       if( ( Nfrac < frac_spurs_thd0 ) || ( Nfrac > frac_spurs_thd1) || ( Nfrac < 4258832 && Nfrac > 4129776 ) || ( IF_state == 2 ) )
/*MT6166*/       {
/*MT6166*/          *if_sel = 0;
/*MT6166*/          l1d_rf.if_sel_Nif_wc = 1;
/*MT6166*/          if( rf_band < FrequencyBand1800 )
/*MT6166*/          {  VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);  }  //Low-side mixing
/*MT6166*/          else
/*MT6166*/          {  VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);  }  //Low-side mixing
/*MT6166*/
/*MT6166*/          L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6166*/       }
/*MT6166*/
/*MT6166*/    }  
/*MT6166*/
/*MT6166*/ #if IS_OBB_DETECTION_SUPPORT
/*MT6166*/    if( !L1D_CheckIfMetaMode() )
/*MT6166*/    {
/*MT6166*/       if( l1d_rf.if_change == -1 && arfcn == l1d_rf.obb_arfcn )
/*MT6166*/       {
/*MT6166*/          signed short if_sign = l1d_rf.if_change*(*if_sel*2-1);
/*MT6166*/
/*MT6166*/          *if_sel = if_sign > 0 ? 1 : 0;
/*MT6166*/          if( rf_band < FrequencyBand1800 )
/*MT6166*/          {  VCO_freq = 4*(CH_freq*DLIF_SCALE + if_sign*DLIF);  }
/*MT6166*/          else
/*MT6166*/          {  VCO_freq = 2*(CH_freq*DLIF_SCALE + if_sign*DLIF);  }
/*MT6166*/
/*MT6166*/          L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6166*/       }
/*MT6166*/    }
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/    /* CW223, SRX_NINT[8:0], SRX_NRFC[22:12] */
/*MT6166*/    *rfN = BSI_CW( 0xDF, ((Nint &0x1FF)<<11) | ((Nfrac>>12)&0x7FF) );
/*MT6166*/    /* CW224, SRX_NFRAC[11:0],SRX_REF_DOUBLER_EN,SRX_CAL_DISABLE,SRX_VCO_CFG[2:0],TALL_TRG_M,SRX_SDM_FRAC_MODE,SRX_RELOCK */
/*MT6166*/    *ifN = BSI_CW( 0xE0, ((Nfrac&0xFFF)<<8) | SRX_REF_DOUBLER_EN | SRX_VCO_CFG | (POR_CW224&0x47) );
/*MT6166*/
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ void L1D_RF_SplitRxPLLSetting(unsigned long rfN, unsigned long ifN, unsigned short *Nint, unsigned long *Nfrac)
/*MT6166*/ {
/*MT6166*/    *Nint  = (rfN&(0x1FF<<11))>>11;
/*MT6166*/    *Nfrac = ( (rfN&0x7FF)<<12 ) | ( (ifN&(0xFFF<<8))>>8 );
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ void L1D_RF_AdjustRxPLLSetting(unsigned short Nint, unsigned long Nfrac, signed long NfracOffset, unsigned long *rfN, unsigned long *ifN )
/*MT6166*/ {
/*MT6166*/    L1D_RF_CompensateSXSetting( &Nint, &Nfrac, NfracOffset, 0 );
/*MT6166*/
/*MT6166*/    /* CW223, SRX_NINT[8:0], SRX_NRFC[22:12] */
/*MT6166*/    *rfN = BSI_CW( 0xDF, ((Nint &0x1FF)<<11) | ((Nfrac>>12)&0x7FF) );
/*MT6166*/    /* CW224, SRX_NFRAC[11:0],SRX_REF_DOUBLER_EN,SRX_CAL_DISABLE,SRX_VCO_CFG[2:0],TALL_TRG_M,SRX_SDM_FRAC_MODE,SRX_RELOCK */
/*MT6166*/    *ifN = BSI_CW( 0xE0, ((Nfrac&0xFFF)<<8)  | ((*ifN)&0xFF));
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6166*/ {
/*MT6166*/    unsigned short Nint =0, CH_freq =0;
/*MT6166*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6166*/    unsigned short DAoffset=0;
/*MT6166*/    
/*MT6166*/
/*MT6166*/    l1d_rf2.arfcn = arfcn;  //for L1D_RF_TxGainSetting
/*MT6166*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6166*/
/*MT6166*/    if( rf_band < FrequencyBand1800 )
/*MT6166*/       VCO_freq = 4*CH_freq;  
/*MT6166*/    else
/*MT6166*/       VCO_freq = 2*CH_freq;  
/*MT6166*/
/*MT6166*/    Nint  = VCO_freq/TX_DCXO_FREQ;
/*MT6166*/    Nfrac = ( ((VCO_freq-Nint*TX_DCXO_FREQ)<<23) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6166*/
/*MT6166*/    DAoffset = 10;//L1D_RF_GetTxDAoffsetSetting( Nint );
/*MT6166*/
/*MT6166*/    /* CW96, N_INT[7:0], N_RFC[22:11] */
/*MT6166*/    *rfN = BSI_CW( 0x60, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6166*/    /* CW97, N_FRAC[10:0], DA_OFFSET[4:0], DI_EN */
/*MT6166*/    *ifN = BSI_CW( 0x61, ((Nfrac&0x7FF)<<9) | ((DAoffset&0x1F)<<4) | 0x1);
/*MT6166*/
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ void L1D_RF_SplitTxPLLSetting(unsigned long rfN, unsigned long ifN, unsigned short *Nint, unsigned long *Nfrac)
/*MT6166*/ {
/*MT6166*/    *Nint  = (rfN&(0xFF<<12))>>12;
/*MT6166*/    *Nfrac = ( (rfN&0xFFF)<<11 ) | ( (ifN&(0x7FF<<9))>>9 );
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ void L1D_RF_AdjustTxPLLSetting(unsigned short Nint, unsigned long Nfrac, signed long NfracOffset, unsigned long *rfN, unsigned long *ifN )
/*MT6166*/ {
/*MT6166*/    L1D_RF_CompensateSXSetting( &Nint, &Nfrac, NfracOffset, 1 );
/*MT6166*/
/*MT6166*/    /* CW96, N_INT[7:0], N_RFC[22:11] */
/*MT6166*/    *rfN = BSI_CW( 0x60, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6166*/    /* CW97, N_FRAC[10:0], DA_OFFSET[4:0], DI_EN */
/*MT6166*/    *ifN = BSI_CW( 0x61, ((Nfrac&0x7FF)<<9) |((*ifN)&0x1FF));
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ void L1D_RF_CompensateSXSetting( unsigned short *Nint, unsigned long *Nfrac, signed long NfracOffset, unsigned char is_TX)
/*MT6166*/ {
/*MT6166*/    signed long Max_Nfrac=0;
/*MT6166*/    if( is_TX )
/*MT6166*/    {  Max_Nfrac = STX_MAX_NFRAC;  }
/*MT6166*/    else
/*MT6166*/    {  Max_Nfrac = SRX_MAX_NFRAC;  }
/*MT6166*/    
/*MT6166*/    //Calculate new Nfrac and Nint
/*MT6166*/    *Nfrac  += (NfracOffset + Max_Nfrac);
/*MT6166*/    if( *Nfrac < Max_Nfrac )
/*MT6166*/    {  (*Nint)--;  
/*MT6166*/    }
/*MT6166*/    else if( *Nfrac >= (Max_Nfrac<<1) )
/*MT6166*/    {  (*Nint)++;  
/*MT6166*/       *Nfrac = *Nfrac - (Max_Nfrac<<1);
/*MT6166*/    }
/*MT6166*/    else
/*MT6166*/    {  *Nfrac-= Max_Nfrac;
/*MT6166*/    }
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ unsigned short L1D_RF_ARFCN_CH_to_RxFreq( int rf_band, int arfcn )
/*MT6166*/ {
/*MT6166*/    unsigned short freq=4450+225;
/*MT6166*/    switch( rf_band )
/*MT6166*/    {
/*MT6166*/       case  FrequencyBand850 :
/*MT6166*/       {
/*MT6166*/          freq=4121+(arfcn-128)+225;     //freq = f_ch*SYNTH_SCALE
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/       case  FrequencyBand900 :
/*MT6166*/       {
/*MT6166*/          if( arfcn<=124 )
/*MT6166*/          {  freq=4450+arfcn+225;  }
/*MT6166*/          else
/*MT6166*/          {  freq=4450+(arfcn-1024)+225;  }
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/       case  FrequencyBand1800 :
/*MT6166*/       {
/*MT6166*/          freq=8551+(arfcn-512)+475;
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/       case  FrequencyBand1900 :
/*MT6166*/       {
/*MT6166*/          freq=9251+(arfcn-512)+400;
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/       default :
/*MT6166*/       {
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    return freq;
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ unsigned short L1D_RF_ARFCN_CH_to_TxFreq( int rf_band, int arfcn )
/*MT6166*/ {
/*MT6166*/    unsigned short freq=4450;
/*MT6166*/    switch( rf_band )
/*MT6166*/    {
/*MT6166*/       case  FrequencyBand850 :
/*MT6166*/       {
/*MT6166*/          freq=4121+(arfcn-128);     //freq = f_ch*SYNTH_SCALE
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/       case  FrequencyBand900 :
/*MT6166*/       {
/*MT6166*/          if( arfcn<=124 )
/*MT6166*/          {  freq=4450+arfcn;  }
/*MT6166*/          else
/*MT6166*/          {  freq=4450+(arfcn-1024);  }
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/       case  FrequencyBand1800 :
/*MT6166*/       {
/*MT6166*/          freq=8551+(arfcn-512);
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/       case  FrequencyBand1900 :
/*MT6166*/       {
/*MT6166*/          freq=9251+(arfcn-512);
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/       default :
/*MT6166*/       {
/*MT6166*/          break;
/*MT6166*/       }
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    return freq;
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ unsigned short L1D_RF_GetTxDCOSCACodeTypeSetting(unsigned short Nint, unsigned long  Nfrac)
/*MT6166*/ {
/*MT6166*/    char segment_tx=3, LUT_num_tx=6, offset_tx=15; // LUT method related parameters
/*MT6166*/    signed short TXDCO_LUT[6]={1566, 1169, 840, 565, 331, -40};  // TXDCO LUT
/*MT6166*/    short idx, x_axis, code_type;  // code_type value for SCA calibration (code_type > 0)
/*MT6166*/
/*MT6166*/ #if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
/*MT6166*/    if( l1d_rf.is_lock_dcxo )
/*MT6166*/    {  L1D_RF_CompensateSXSetting( &Nint, &Nfrac, -l1d_rf.tx_nfracoffset, 1 );  }
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/    /* STX DCO SCA Typical Code LUT */
/*MT6166*/    idx = (Nint>>segment_tx)-((short)offset_tx);                                                                                      
/*MT6166*/    if(idx<0)                                                                                                                          
/*MT6166*/       idx = 0;                                                                                                                          
/*MT6166*/    else if(idx>(LUT_num_tx-2))                                                                                                        
/*MT6166*/       idx = LUT_num_tx-2;
/*MT6166*/
/*MT6166*/    x_axis      = ((Nint-((Nint>>segment_tx)<<segment_tx))<<3)+((short)(Nfrac>>20));                                                   
/*MT6166*/    code_type   = TXDCO_LUT[idx]+ ((x_axis*(TXDCO_LUT[idx+1]-TXDCO_LUT[idx]))>>(segment_tx+3));
/*MT6166*/    code_type <<= 1;
/*MT6166*/
/*MT6166*/    return code_type;
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ unsigned short L1D_RF_GetTxDEMChunkSetting(int rf_band, unsigned short Nint)
/*MT6166*/ {
/*MT6166*/    unsigned short DEM_Chunk_L1;
/*MT6166*/    unsigned short OUT_G, OUT_E;
/*MT6166*/    char segment_dem=4, LUT_num_dem=4, offset_dem=7;     // LUT method related parameters
/*MT6166*/    signed short DEM_chunk_G_LUT[4]={15, 10,  7,  5};  // DEM chunk GMSK LUT
/*MT6166*/    signed short DEM_chunk_E_LUT[4]={69, 46, 33, 24};  // DEM chunk EPSK LUT
/*MT6166*/    short idx;
/*MT6166*/
/*MT6166*/    /* STX DEM CHUNK LUT */
/*MT6166*/	  idx = (Nint>>segment_dem)-((short)offset_dem);                                                                                      
/*MT6166*/    if(idx<0)                                                                                                                          
/*MT6166*/       idx = 0;                                                                                                                          
/*MT6166*/    else if(idx>(LUT_num_dem-2))                                                                                                        
/*MT6166*/       idx = LUT_num_dem-2;                                                                                                                                                               
/*MT6166*/
/*MT6166*/    OUT_G = DEM_chunk_G_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_G_LUT[idx+1]-DEM_chunk_G_LUT[idx]))>>(segment_dem));
/*MT6166*/    OUT_E = DEM_chunk_E_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_E_LUT[idx+1]-DEM_chunk_E_LUT[idx]))>>(segment_dem));
/*MT6166*/    
/*MT6166*/    if( ( (l1d_rf.tx_mod_type2)^(l1d_rf.tx_mod_type2<<1) ) & 0xE )   // IS_MIXED_MULTISLOT
/*MT6166*/    {
/*MT6166*/       if( rf_band < FrequencyBand1800 )
/*MT6166*/          DEM_Chunk_L1 = ((OUT_E+OUT_G+5)>40) ? (OUT_E+OUT_G+5) : 40; 
/*MT6166*/       else
/*MT6166*/          DEM_Chunk_L1 = 40;   
/*MT6166*/    }
/*MT6166*/    else
/*MT6166*/    {
/*MT6166*/       if( (l1d_rf.tx_mod_type2 != 0) && (rf_band < FrequencyBand1800) )
/*MT6166*/          DEM_Chunk_L1 = ((2*OUT_E+6)>40) ? (2*OUT_E+6) : 40; 
/*MT6166*/       else
/*MT6166*/          DEM_Chunk_L1 = 40;   
/*MT6166*/    }
/*MT6166*/    return DEM_Chunk_L1;
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
/*MT6166*/ void L1D_RF_GetTxKDCOCAL2ndSetting(int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6166*/ {
/*MT6166*/    unsigned short Nint =0, CH_freq =0;
/*MT6166*/    unsigned long  Nfrac=0, DCO4G_freq=0;
/*MT6166*/    
/*MT6166*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6166*/
/*MT6166*/    if( rf_band < FrequencyBand1800 )
/*MT6166*/       DCO4G_freq = 4*CH_freq;  
/*MT6166*/    else
/*MT6166*/       DCO4G_freq = 2*CH_freq;  
/*MT6166*/
/*MT6166*/    Nint  = ( (DCO4G_freq<<15) - 64*DCO4G_freq + 64*TX_DCXO_FREQ*92 ) / (TX_DCXO_FREQ<<15);
/*MT6166*/    Nfrac = ( ( ( (DCO4G_freq<<15) - 64*DCO4G_freq + 64*TX_DCXO_FREQ*92 - ((Nint*TX_DCXO_FREQ)<<15) )<<8 ) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6166*/
/*MT6166*/ #if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
/*MT6166*/    if( l1d_rf.is_lock_dcxo )
/*MT6166*/    {  L1D_RF_CompensateSXSetting( &Nint, &Nfrac, l1d_rf.tx_nfracoffset, 1 );  }
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/    /* CW98, N_INT1[7:0], N_RFC1[22:11] */
/*MT6166*/    *rfN = BSI_CW( 0x62, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6166*/    /* CW99, N_FRAC1[10:0], NOFFSET_REV[3:0], STX_DCO_SCAK_NOFFSET[2:0], STX_MMD_SDM_DI_LS[1:0] */
/*MT6166*/    *ifN = BSI_CW( 0x63, ((Nfrac&0x7FF)<<9) | (POR_CW99&0x1FF) );
/*MT6166*/
/*MT6166*/ }
/*MT6166*/ /* =========================================================================== */
/*MT6166*/
#endif

#if IS_RF_MT6165
/*MT6165*/ //For DLIF mode
/*MT6165*/ void  L1D_RF_Cal_Synthesizer_Params( unsigned short* Nint, unsigned long* Nfrac, unsigned long  VCO_freq )
/*MT6165*/ {
/*MT6165*/    *Nint  = VCO_freq/(RX_DCXO_FREQ*DLIF_SCALE);
/*MT6165*/    //+195/2 is for rounding, 195=13*3*5, 5 is SYNTH_SCALE, 13 and 3 are related to DLIF
/*MT6165*/    *Nfrac = ( ((VCO_freq-*Nint*RX_DCXO_FREQ*DLIF_SCALE)<<15) + (195)/2 )/195;
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ char  L1D_RF_Cal_IF_Synth_State( void )
/*MT6165*/ {
/*MT6165*/ #if IS_W_CANCELLATION_SUPPORT
/*MT6165*/    if( L1D_CheckIfMetaMode() )
/*MT6165*/    {  return l1d_rf.if_state;  }
/*MT6165*/    else
/*MT6165*/    {  return 0;  }
/*MT6165*/ #else
/*MT6165*/    return 0;
/*MT6165*/ #endif
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6165*/ {  long *if_sel = ifN+1;
/*MT6165*/    unsigned short Nint =0, CH_freq =0;
/*MT6165*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6165*/    unsigned long  frac_spurs_thd0=0, frac_spurs_thd1=0;
/*MT6165*/    unsigned char  IF_state=0;   //IF_state=0:default, IF_state=1:+IF, IF_state=2:-IF
/*MT6165*/
/*MT6165*/    IF_state = L1D_RF_Cal_IF_Synth_State();
/*MT6165*/
/*MT6165*/    CH_freq = L1D_RF_ARFCN_CH_to_RxFreq( rf_band, arfcn );
/*MT6165*/
/*MT6165*/    if( IF_state != 2 )
/*MT6165*/    {
/*MT6165*/       *if_sel = 0;
/*MT6165*/ #if IS_W_CANCELLATION_SUPPORT
/*MT6165*/       l1d_rf.if_sel_Nif_wc = 0;
/*MT6165*/ #endif
/*MT6165*/       if( rf_band < FrequencyBand1800 )
/*MT6165*/       {
/*MT6165*/          VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);  //High-side mixing
/*MT6165*/          frac_spurs_thd0 = 193584;
/*MT6165*/          frac_spurs_thd1 = 8195024;
/*MT6165*/       }
/*MT6165*/       else
/*MT6165*/       {
/*MT6165*/          VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);  //High-side mixing
/*MT6165*/          frac_spurs_thd0 = 96792;
/*MT6165*/          frac_spurs_thd1 = 8291816;
/*MT6165*/       }
/*MT6165*/       L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6165*/    }
/*MT6165*/
/*MT6165*/    if( IF_state != 1 )
/*MT6165*/    {
/*MT6165*/       // use +IF channel instead of -IF for IRR calibration
/*MT6165*/       if( ( Nfrac < frac_spurs_thd0 ) || ( Nfrac > frac_spurs_thd1) || ( Nfrac < 4258832 && Nfrac > 4129776 ) || ( IF_state == 2 ) )
/*MT6165*/       {
/*MT6165*/          *if_sel = 0;
/*MT6165*/ #if IS_W_CANCELLATION_SUPPORT
/*MT6165*/          l1d_rf.if_sel_Nif_wc = 1;
/*MT6165*/ #endif
/*MT6165*/          if( rf_band < FrequencyBand1800 )
/*MT6165*/          {  VCO_freq = 4*(CH_freq*DLIF_SCALE - DLIF);  }  //use High-side mixing instead of Low-side for MT6165
/*MT6165*/          else
/*MT6165*/          {  VCO_freq = 2*(CH_freq*DLIF_SCALE - DLIF);  }  //use High-side mixing instead of Low-side for MT6165
/*MT6165*/
/*MT6165*/          L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6165*/       }
/*MT6165*/
/*MT6165*/    }
/*MT6165*/
/*MT6165*/ #if IS_OBB_DETECTION_SUPPORT
/*MT6165*/    if( !L1D_CheckIfMetaMode() )
/*MT6165*/    {
/*MT6165*/       if( l1d_rf.if_change == -1 && arfcn == l1d_rf.obb_arfcn )
/*MT6165*/       {
/*MT6165*/          signed short if_sign = l1d_rf.if_change*(*if_sel*2-1);
/*MT6165*/
/*MT6165*/          *if_sel = if_sign > 0 ? 1 : 0;
/*MT6165*/          if( rf_band < FrequencyBand1800 )
/*MT6165*/          {  VCO_freq = 4*(CH_freq*DLIF_SCALE + if_sign*DLIF);  }
/*MT6165*/          else
/*MT6165*/          {  VCO_freq = 2*(CH_freq*DLIF_SCALE + if_sign*DLIF);  }
/*MT6165*/
/*MT6165*/          L1D_RF_Cal_Synthesizer_Params( &Nint, &Nfrac, VCO_freq );
/*MT6165*/       }
/*MT6165*/    }
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/    /* CW181, SRX_NINT[7:0], SRX_NRFC[22:11] */
/*MT6165*/    *rfN = BSI_CW( 0xB5, ((Nint &0xFF)<<12) | ((Nfrac>>11)&0xFFF) );
/*MT6165*/    /* CW182, SRX_NFRAC[10:0], DA_OFFSET[7:0], DI_EN */
/*MT6165*/    *ifN = BSI_CW( 0xB6, ((Nfrac&0x7FF)<<9) | (POR_CW182&0x1) ); // Keep DA_OFFSET=0x0 and setup at L1D_RF_SetSData_SR1()
/*MT6165*/
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ void L1D_RF_SplitRxPLLSetting(unsigned long rfN, unsigned long ifN, unsigned short *Nint, unsigned long *Nfrac)
/*MT6165*/ {
/*MT6165*/    *Nint  = (rfN&(0xFF<<12))>>12;
/*MT6165*/    *Nfrac = ( (rfN&0xFFF)<<11 ) | ( (ifN&(0x7FF<<9))>>9 );
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ void L1D_RF_AdjustRxPLLSetting(unsigned short Nint, unsigned long Nfrac, signed long NfracOffset, unsigned long *rfN, unsigned long *ifN )
/*MT6165*/ {
/*MT6165*/    L1D_RF_CompensateSXSetting( &Nint, &Nfrac, NfracOffset, 0 );
/*MT6165*/
/*MT6165*/    /* CW181, SRX_NINT[7:0], SRX_NRFC[22:11] */
/*MT6165*/    *rfN = BSI_CW( 0xB5, ((Nint &0xFF)<<12) | ((Nfrac>>11)&0xFFF) );
/*MT6165*/    /* CW182, SRX_NFRAC[10:0], DA_OFFSET[7:0], DI_EN */
/*MT6165*/    *ifN = BSI_CW( 0xB6, ((Nfrac&0x7FF)<<9) | ((*ifN)&0x1FF) );
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6165*/ {
/*MT6165*/    unsigned short Nint =0, CH_freq =0;
/*MT6165*/    unsigned long  Nfrac=0, VCO_freq=0;
/*MT6165*/
/*MT6165*/
/*MT6165*/    l1d_rf2.arfcn = arfcn;  //for L1D_RF_TxGainSetting
/*MT6165*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6165*/
/*MT6165*/    if( rf_band < FrequencyBand1800 )
/*MT6165*/       VCO_freq = 4*CH_freq;
/*MT6165*/    else
/*MT6165*/       VCO_freq = 2*CH_freq;
/*MT6165*/
/*MT6165*/    Nint  = VCO_freq/TX_DCXO_FREQ;
/*MT6165*/    Nfrac = ( ((VCO_freq-Nint*TX_DCXO_FREQ)<<23) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6165*/
/*MT6165*/    /* CW181, SRX_NINT[7:0], SRX_NRFC[22:11] */
/*MT6165*/    *rfN = BSI_CW( 0xB5, ((Nint &0xFF)<<12) | ((Nfrac>>11)&0xFFF) );
/*MT6165*/    /* CW182, SRX_NFRAC[10:0], DA_OFFSET[7:0], DI_EN */
/*MT6165*/    *ifN = BSI_CW( 0xB6, ((Nfrac&0x7FF)<<9) | (POR_CW182&0x1) ); // Keep DA_OFFSET=0x0 and setup at L1D_RF_SetSData_ST1()
/*MT6165*/
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ void L1D_RF_SplitTxPLLSetting(unsigned long rfN, unsigned long ifN, unsigned short *Nint, unsigned long *Nfrac)
/*MT6165*/ {
/*MT6165*/    *Nint  = (rfN&(0xFF<<12))>>12;
/*MT6165*/    *Nfrac = ( (rfN&0xFFF)<<11 ) | ( (ifN&(0x7FF<<9))>>9 );
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ void L1D_RF_AdjustTxPLLSetting(unsigned short Nint, unsigned long Nfrac, signed long NfracOffset, unsigned long *rfN, unsigned long *ifN )
/*MT6165*/ {
/*MT6165*/    L1D_RF_CompensateSXSetting( &Nint, &Nfrac, NfracOffset, 1 );
/*MT6165*/
/*MT6165*/    /* CW181, SRX_NINT[7:0], SRX_NRFC[22:11] */
/*MT6165*/    *rfN = BSI_CW( 0xB5, ((Nint &0xFF)<<12) | ((Nfrac>>11)&0xFFF) );
/*MT6165*/    /* CW182, SRX_NFRAC[10:0], DA_OFFSET[7:0], DI_EN */
/*MT6165*/    *ifN = BSI_CW( 0xB6, ((Nfrac&0x7FF)<<9) | ((*ifN)&0x1FF) );
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ void L1D_RF_CompensateSXSetting( unsigned short *Nint, unsigned long *Nfrac, signed long NfracOffset, unsigned char is_TX)
/*MT6165*/ {
/*MT6165*/    signed long Max_Nfrac=0;
/*MT6165*/    if( is_TX )
/*MT6165*/    {  Max_Nfrac = STX_MAX_NFRAC;  }
/*MT6165*/    else
/*MT6165*/    {  Max_Nfrac = SRX_MAX_NFRAC;  }
/*MT6165*/
/*MT6165*/    //Calculate new Nfrac and Nint
/*MT6165*/    *Nfrac  += (NfracOffset + Max_Nfrac);
/*MT6165*/    if( *Nfrac < Max_Nfrac )
/*MT6165*/    {  (*Nint)--;
/*MT6165*/    }
/*MT6165*/    else if( *Nfrac >= (Max_Nfrac<<1) )
/*MT6165*/    {  (*Nint)++;
/*MT6165*/       *Nfrac = *Nfrac - (Max_Nfrac<<1);
/*MT6165*/    }
/*MT6165*/    else
/*MT6165*/    {  *Nfrac-= Max_Nfrac;
/*MT6165*/    }
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ unsigned short L1D_RF_ARFCN_CH_to_RxFreq( int rf_band, int arfcn )
/*MT6165*/ {
/*MT6165*/    unsigned short freq=4450+225;
/*MT6165*/    switch( rf_band )
/*MT6165*/    {
/*MT6165*/       case  FrequencyBand850 :
/*MT6165*/       {
/*MT6165*/          freq=4121+(arfcn-128)+225;     //freq = f_ch*SYNTH_SCALE
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/       case  FrequencyBand900 :
/*MT6165*/       {
/*MT6165*/          if( arfcn<=124 )
/*MT6165*/          {  freq=4450+arfcn+225;  }
/*MT6165*/          else
/*MT6165*/          {  freq=4450+(arfcn-1024)+225;  }
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/       case  FrequencyBand1800 :
/*MT6165*/       {
/*MT6165*/          freq=8551+(arfcn-512)+475;
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/       case  FrequencyBand1900 :
/*MT6165*/       {
/*MT6165*/          freq=9251+(arfcn-512)+400;
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/       default :
/*MT6165*/       {
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/    }
/*MT6165*/
/*MT6165*/    return freq;
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ unsigned short L1D_RF_ARFCN_CH_to_TxFreq( int rf_band, int arfcn )
/*MT6165*/ {
/*MT6165*/    unsigned short freq=4450;
/*MT6165*/    switch( rf_band )
/*MT6165*/    {
/*MT6165*/       case  FrequencyBand850 :
/*MT6165*/       {
/*MT6165*/          freq=4121+(arfcn-128);     //freq = f_ch*SYNTH_SCALE
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/       case  FrequencyBand900 :
/*MT6165*/       {
/*MT6165*/          if( arfcn<=124 )
/*MT6165*/          {  freq=4450+arfcn;  }
/*MT6165*/          else
/*MT6165*/          {  freq=4450+(arfcn-1024);  }
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/       case  FrequencyBand1800 :
/*MT6165*/       {
/*MT6165*/          freq=8551+(arfcn-512);
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/       case  FrequencyBand1900 :
/*MT6165*/       {
/*MT6165*/          freq=9251+(arfcn-512);
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/       default :
/*MT6165*/       {
/*MT6165*/          break;
/*MT6165*/       }
/*MT6165*/    }
/*MT6165*/
/*MT6165*/    return freq;
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ unsigned short L1D_RF_GetSxDCOSCACodeTypeSetting(unsigned short Nint, unsigned long  Nfrac)
/*MT6165*/ {
/*MT6165*/    char segment=3, LUT_num=11, offset=15; // LUT method related parameters
/*MT6165*/    signed short TXDCO_LUT[11]={1625, 1307, 1040, 818, 628, 467, 328, 208, 102, 11, -30};  // SXDCO LUT
/*MT6165*/    short idx, x_axis, code_type;  // code_type value for SCA calibration (code_type > 0)
/*MT6165*/
/*MT6165*/ #if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
/*MT6165*/    if( l1d_rf.is_lock_dcxo )
/*MT6165*/    {  L1D_RF_CompensateSXSetting( &Nint, &Nfrac, -l1d_rf.tx_nfracoffset, 1 );  }
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/    /* STX DCO SCA Typical Code LUT */
/*MT6165*/    idx = (Nint>>segment)-((short)offset);
/*MT6165*/    if(idx<0)
/*MT6165*/       idx = 0;
/*MT6165*/    else if(idx>(LUT_num-2))
/*MT6165*/       idx = LUT_num-2;
/*MT6165*/
/*MT6165*/    x_axis      = ((Nint-((Nint>>segment)<<segment))<<3)+((short)(Nfrac>>20));
/*MT6165*/    code_type   = TXDCO_LUT[idx]+ ((x_axis*(TXDCO_LUT[idx+1]-TXDCO_LUT[idx]))>>(segment+3));
/*MT6165*/    code_type <<= 1;
/*MT6165*/
/*MT6165*/    return code_type;
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ unsigned short L1D_RF_GetTxDEMChunkSetting(int rf_band, unsigned short Nint)
/*MT6165*/ {
/*MT6165*/    unsigned short DEM_Chunk_L1;
/*MT6165*/    unsigned short OUT_G, OUT_E;
/*MT6165*/    char segment_dem=4, LUT_num_dem=4, offset_dem=7;     // LUT method related parameters
/*MT6165*/    signed short DEM_chunk_G_LUT[4]={15, 10,  7,  5};  // DEM chunk GMSK LUT
/*MT6165*/    signed short DEM_chunk_E_LUT[4]={69, 46, 33, 24};  // DEM chunk EPSK LUT
/*MT6165*/    short idx;
/*MT6165*/
/*MT6165*/    /* STX DEM CHUNK LUT */
/*MT6165*/    idx = (Nint>>segment_dem)-((short)offset_dem);
/*MT6165*/    if(idx<0)
/*MT6165*/       idx = 0;
/*MT6165*/    else if(idx>(LUT_num_dem-2))
/*MT6165*/       idx = LUT_num_dem-2;
/*MT6165*/
/*MT6165*/    OUT_G = DEM_chunk_G_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_G_LUT[idx+1]-DEM_chunk_G_LUT[idx]))>>(segment_dem));
/*MT6165*/    OUT_E = DEM_chunk_E_LUT[idx]+(((Nint-((Nint>>segment_dem)<<segment_dem))*(DEM_chunk_E_LUT[idx+1]-DEM_chunk_E_LUT[idx]))>>(segment_dem));
/*MT6165*/
/*MT6165*/    if( ( (l1d_rf.tx_mod_type2)^(l1d_rf.tx_mod_type2<<1) ) & 0xE )   // IS_MIXED_MULTISLOT
/*MT6165*/    {
/*MT6165*/       if( rf_band < FrequencyBand1800 )
/*MT6165*/          DEM_Chunk_L1 = ((OUT_E+OUT_G+5)>40) ? (OUT_E+OUT_G+5) : 40;
/*MT6165*/       else
/*MT6165*/          DEM_Chunk_L1 = 40;
/*MT6165*/    }
/*MT6165*/    else
/*MT6165*/    {
/*MT6165*/       if( (l1d_rf.tx_mod_type2 != 0) && (rf_band < FrequencyBand1800) )
/*MT6165*/          DEM_Chunk_L1 = ((2*OUT_E+6)>40) ? (2*OUT_E+6) : 40;
/*MT6165*/       else
/*MT6165*/          DEM_Chunk_L1 = 40;
/*MT6165*/    }
/*MT6165*/    return DEM_Chunk_L1;
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ void L1D_RF_GetTxKDCOCAL2ndSetting(int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6165*/ {
/*MT6165*/    unsigned short Nint =0, CH_freq =0;
/*MT6165*/    unsigned long  Nfrac=0, DCO4G_freq=0, NCal=64;
/*MT6165*/    signed   long  Nfrac1Offset=0;
/*MT6165*/    unsigned short KDCO_NCAL_LUT[4]={64, 96, 16, 32};
/*MT6165*/
/*MT6165*/    CH_freq = L1D_RF_ARFCN_CH_to_TxFreq( rf_band, arfcn );
/*MT6165*/    NCal    = KDCO_NCAL_LUT[((POR_CW188>>6)&0x3)];
/*MT6165*/
/*MT6165*/    if( rf_band < FrequencyBand1800 )
/*MT6165*/       DCO4G_freq = 4*CH_freq;
/*MT6165*/    else
/*MT6165*/       DCO4G_freq = 2*CH_freq;
/*MT6165*/
/*MT6165*/    Nint  = ( (DCO4G_freq<<15) - NCal*DCO4G_freq + NCal*TX_DCXO_FREQ*92 ) / (TX_DCXO_FREQ<<15);
/*MT6165*/    Nfrac = ( ( ( (DCO4G_freq<<15) - NCal*DCO4G_freq + NCal*TX_DCXO_FREQ*92 - ((Nint*TX_DCXO_FREQ)<<15) )<<8 ) + TX_DCXO_FREQ/2 )/TX_DCXO_FREQ;  //+TX_DCXO_FREQ/2 is for rounding
/*MT6165*/
/*MT6165*/ #if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
/*MT6165*/    if( l1d_rf.is_lock_dcxo )
/*MT6165*/    {  Nfrac1Offset = l1d_rf.tx_nfracoffset - ((((signed long)NCal)*l1d_rf.tx_nfracoffset)>>15);
/*MT6165*/       L1D_RF_CompensateSXSetting( &Nint, &Nfrac, Nfrac1Offset, 1 );
/*MT6165*/    }
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/    /* CW183, N_INT1[7:0], N_FRFC1[22:11] */
/*MT6165*/    *rfN = BSI_CW( 0xB7, ((Nint &0xFF)<<12) | (Nfrac>>11) );
/*MT6165*/    /* CW184, N_FRAC1[10:0], NOFFSET_REV[2:0], STX_DCO_SCAK_NOFFSET[3:0], STX_MMD_SDM_DI_LS[1:0] */
/*MT6165*/    *ifN = BSI_CW( 0xB8, ((Nfrac&0x7FF)<<9) | (POR_CW184&0x1FF) );
/*MT6165*/    (void) Nfrac1Offset;
/*MT6165*/
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ unsigned short L1D_RF_GetSxDAoffsetSetting(unsigned long rfn)
/*MT6165*/ {
/*MT6165*/    unsigned short Nint        = ((rfn>>12)&0xFF);
/*MT6165*/    unsigned long  Nfrac_round = ((rfn>>11)&0x1);  // Check if (Nfrac*2^23)>0.5 by Nfrac[22]
/*MT6165*/    return (Nint+Nfrac_round-10);
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
/*MT6165*/ unsigned short L1D_RF_GetSCAKNoffsetSetting(unsigned short Nint)
/*MT6165*/ {
/*MT6165*/    unsigned short SCAK_NOFFSET;
/*MT6165*/    if( Nint<100 )
/*MT6165*/    {  SCAK_NOFFSET = 0;   }
/*MT6165*/    else if( Nint>227)
/*MT6165*/    {  SCAK_NOFFSET = 127; }
/*MT6165*/    else
/*MT6165*/    {  SCAK_NOFFSET = Nint-100;  }
/*MT6165*/
/*MT6165*/    return (SCAK_NOFFSET>>3);
/*MT6165*/ }
/*MT6165*/ /* =========================================================================== */
/*MT6165*/
#endif

