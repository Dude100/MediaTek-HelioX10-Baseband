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
 *   m12190.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Setup RF
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.36  $
 * $Modtime:   Jul 08 2005 16:45:06  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1/l1d/m12190.h-arc  $
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
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * Rollback //MOLY/BRANCHES_LR9/LR9.W1423.MD.LWTG.MP/mcu/interface/modem/l1/gsm/external/l1cal.h to revision 1
 *
 * 06 05 2014 ola.lee
 * removed!
 * 	.
 *
 * 06 04 2014 ola.lee
 * removed!
 * .
 *
 * 06 03 2014 ola.lee
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 * 05 16 2014 ola.lee
 * removed!
 * 	.
 *
 * 05 16 2014 ola.lee
 * removed!
 * 	.
 *
 * 05 16 2014 ola.lee
 * removed!
 * 	.
 *
 * 05 16 2014 ola.lee
 * removed!
 * 	.
 *
 * 04 10 2014 ola.lee
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
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
 * 	.
 *
 * removed!
 * removed!
 * 	.
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
 * 	.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
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
 * 05 03 2013 th.yeh
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
 * 08 14 2012 th.yeh
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
 * 07 13 2012 ola.lee
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Add SR3 check for FSIWinOff
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
 * 12 23 2011 cs.wu
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
 * 11 04 2011 th.yeh
 * removed!
 * .
 *
 * 11 03 2011 cs.wu
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
 * 09 20 2011 th.yeh
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
 * 08 10 2011 cs.wu
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * 07 20 2011 th.yeh
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * 07 07 2011 cs.wu
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
 * 04 20 2011 cs.wu
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
 * 01 09 2011 cs.wu
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
 * 12 27 2010 cs.wu
 * removed!
 * .
 *
 * 12 26 2010 cs.wu
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
 * 10 31 2010 cs.wu
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
 * MT6270A FPGA 2G phone call ACIF_base issue
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
 * Revise code
 *
 * removed!
 * removed!
 * Revise RFSpecialCoef usage
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
 * Fix compile warning related to m12150.c
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
 * [L1D][Modify] And unsigned long Uncalibrated_LID_Flag in l1d_rf to record the uncalibrated LID checked by NVRAM
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
 * Remove the L1D_RF_SetPM_Length() for applying the DC offset length 148 for all RF solutions
 *
 * removed!
 * removed!
 * Add compile option to remove dummy code
 *
 * removed!
 * removed!
 * Add the interfaces to switch the fixed gain mechanism
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
 * Modify for lowest APC DAC during the interslot
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
 * Modify RX filter bandwidth while doing TX auto calibration
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
 *    Rev 1.36   Jul 08 2005 16:53:04   mtk00939
 * [L1D][Modify]L1D add code for MT6139C and META related code
 *
 *    Rev 1.35   May 17 2005 00:34:36   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.34   May 16 2005 11:46:24   mtk00240
 * Support 22 BPI setting & current sense PA
 * Resolution for 11091: [L1D][New Feature] Support 22 BPI setting & current sense PA
 *
 *    Rev 1.33   Jan 18 2005 00:38:08   BM
 * append new line in W05.04
 *
 *    Rev 1.32   Oct 29 2004 12:44:56   mtk00240
 * Open interface to get battery voltage & temperature in m12190
 * Resolution for 7034: [L1D][Add feature] Open PCL & PathLoss compensation function for customer.
 *
 *    Rev 1.31   Oct 18 2004 15:42:46   mtk00703
 * Modify the structure of sBBTXParameters for Calibration of TXOffsetI/Q, TrimI/Q, Tx_Gain on META mode.
 * Resolution for 8290: [L1][NewFeature]Calibration of TXOffsetI/Q, TrimI/Q and TXgain on META mdoe
 *
 *    Rev 1.30   Aug 05 2004 20:42:18   mtk00240
 * Open PCL & PathLoss compensation function for customer.
 * Resolution for 7034: [L1D][Add feature] Open PCL & PathLoss compensation function for customer.
 *
 *    Rev 1.29   Mar 12 2004 11:55:22   mtk00489
 * [L1D][Enhanced]L1D add APC voltage/temperature compensation and add BBTXParameter for META
 * Resolution for 4233: [L1D][Enhanced]L1D add APC voltage/temperature compensation and add BBTXParameter for META
 *
 *    Rev 1.28   Aug 08 2003 12:26:22   mtk00489
 * [L1D][Modify]ONLY apply bb_tx_autocal when we get enough samples to evalute it, so L1D apply bb_tx_autocal for 1. All RF except AERO 2.MT6205B_AND_LATTER_VERSION
 * Resolution for 2472: [L1D][Modify]ONLY apply bb_tx_autocal when we get enough samples to evalute it, so L1D apply bb_tx_autocal for 1. All RF except AERO 2.MT6205B_AND_LATTER_VERSION
 *
 *    Rev 1.27   Jul 31 2003 21:35:10   mtk00240
 * Add GPRS inter-slot ramp profile and crystal data support in Meta mode
 * Resolution for 2391: [GPRS][Enhance] Add GPRS inter-slot ramp profile and crystal data support in Meta mode
 *
 *    Rev 1.26   Jun 26 2003 15:22:18   mtk00240
 * L1D modify some code to support MT6218
 * Resolution for 2116: [L1D][Enhance] L1D modify some code to support MT6218
 *
 *    Rev 1.25   Jun 06 2003 18:42:46   mtk00489
 * [L1D][Enhanced]L1D modify for custom folder/files. from now on, L1D only knows the RF chip name(not board name) 1.add l1d_custom_rf.h(from l1d_rf.h) 2.add 12196.c(from 12190.c) 3.move m12193.c to custom directory 4.modify l1s.lis 5.files include l1d_rf.h should also include l1d_custom_rf.h 6.change l1d_cid.h
 * Resolution for 1961: [L1D][Enhanced]L1D modify for custom folder/files. from now on, L1D only knows the RF chip name(not board name) 1.add l1d_custom_rf.h(from l1d_rf.h) 2.add 12196.c(from 12190.c) 3.move m12193.c to custom directory 4.modify l1s.lis 5.files
 *
 *    Rev 1.24   11 Feb 2003 08:26:12   mtk00240
 * L1D turn off AFC DAC in turbo sleep mode
 * Resolution for 644: L1D turn off AFC DAC in turbo sleep mode
 *
 *    Rev 1.23   Jan 29 2003 18:07:46   mtk00474
 * m12150.c : MCU calulate offset I/Q
 * m12190.c/h : remove L1D_RF_NeedToCalibrate()
 * m12100.c   : resolve the collision between BB TX auto-calibration and META calibration
 * Resolution for 636: for BB TX autocalibration and META calibrtaion
 *
 *    Rev 1.22   08 Jan 2003 12:34:18   mtk00240
 * L1D initial the Ramp profile file when L1D initialize
 * Resolution for 619: L1D initial the Ramp profile file when L1D initialize
 *
 *    Rev 1.21   06 Jan 2003 09:27:06   mtk00240
 * To support META2, modify some code.
 * Resolution for 632: To support META2, modify some code.
 *
 *    Rev 1.20   Jan 03 2003 10:13:10   mtk00474
 * calibration depends on the RF module, add L1D_RF_NeedToCalibrate()
 * Resolution for 614: calibration depends on the RF module
 *
 *    Rev 1.19   06 Dec 2002 20:06:58   mtk00240
 * L1D set MT6119 to TX Mode when TX calibration
 * Resolution for 584: L1D set MT6119 to TX Mode when TX calibration
 *
 *    Rev 1.18   22 Nov 2002 17:36:20   mtk00240
 * Add code to support power saving mode of MT6119
 * Resolution for 568: Add code to support power saving mode of MT6119
 *
 *    Rev 1.17   16 Nov 2002 08:52:16   mtk00240
 * L1D add code to support AERO gain setting in GPRS mode
 * Resolution for 562: L1D add code to support AERO gain setting in GPRS mode
 *
 *    Rev 1.16   Sep 03 2002 20:01:50   admin
 * change file header
 *
 *    Rev 1.15   22 Aug 2002 10:37:48   mtk00240
 * change the sL1DAGCDATA fields
 * Resolution for 455: L1D modified m12192.c to eavluate gain setting more easily
 *
 *    Rev 1.14   15 Aug 2002 08:27:28   mtk00240
 * L1D add functions to support AERO initialization
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.13   07 Aug 2002 10:46:44   mtk00240
 * L1D fix the bug that the negative value of pathloss gain is always compiled to 0
 * Resolution for 448: L1D fix the bug that the negative value of pathloss gain is always compiled to 0
 *
 *    Rev 1.12   18 Jul 2002 08:49:48   mtk00240
 * L1D modify ramp structure to align DWORD address
 * Resolution for 435: L1D modify ramp structure to align DWORD address
 *
 *    Rev 1.11   03 Jul 2002 22:17:26   mtk00240
 * L1D extrract RF setting code to let customer setup new RF module more easily
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.10   03 Jul 2002 21:43:48   mtk00240
 * L1D extrract RF setting code to let customer setup new RF module more easily
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.9   08 May 2002 22:19:28   mtk00240
 * L1D add functions to support RF Test Tool
 * Resolution for 387: L1D add functions to support RF Test Tool
 *
 *    Rev 1.8   23 Apr 2002 14:40:34   mtk00240
 * L1D integrate all RF calibration data into m12193.c
 *
 *    Rev 1.7   13 Apr 2002 22:07:22   mtk00240
 * L1D add code to wake up RF from sleep mode
 * Resolution for 366: L1D add code to wake up RF from sleep mode
 *
 *    Rev 1.6   30 Mar 2002 13:04:16   mtk00240
 * 1) Modify L1D code to support both Bright2 & Bright4 RF board
 * 2) L1D add Audio interface to support Voice Memo & Melody
 * 3) Add L1D code to support RAM-based chip
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 * Resolution for 342: L1D add Audio interface to support Voice Memo & Melody
 * Resolution for 343: Add L1D code to support RAM-based chip
 *
 *    Rev 1.5   06 Mar 2002 19:41:16   mtk00240
 * L1D change the methode of setup APC ramp
 * Resolution for 311: L1D change the methode of setup APC ramp
 *
 *    Rev 1.4   17 Feb 2002 20:15:40   mtk00240
 * Update L1D code for solving HandOver test item
 * Resolution for 275: Update L1D code for solving HandOver test item
 *
 *    Rev 1.3   03 Jan 2002 12:19:48   mtk00240
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


#ifndef  _M12190_H_
#define  _M12190_H_
/*---------------------------------------------------------------------------*/

/*...................................*/
// for the following IS_CHIP_* compile option
#include "l1d_cid.h"
#include "l1cal.h"
#include "l1_interface.h"
#if IS_RF_CENTRAL_CONTROL_SUPPORT
#include "mml1_rf_global.h"
#endif
/*...................................*/

#ifndef _L1D_DATA_H_
#define  PWRRES_BIT              3
#define  PWRRES                  (1<<PWRRES_BIT)
#endif

#define  GAINLOSS( n )           ((signed char)((n)*PWRRES))
#define  TABLE_END               -1

/*...................................*/

#define  IS_CONTINUOUS_RX_SLOT() ((l1d_rf.rx_slots&CONTISLOTMASK[l1d_rf.cur_slot])==CONTISLOTMASK[l1d_rf.cur_slot])
#define  IS_CONTINUOUS_TX_SLOT() ((l1d_rf.tx_slots&CONTISLOTMASK[l1d_rf.cur_slot])==CONTISLOTMASK[l1d_rf.cur_slot])
#define  IS_1ST_RX_SLOT()        ((l1d_rf.rx_slots&FIRSTSLOTMASK[l1d_rf.cur_slot])==(1<<l1d_rf.cur_slot))
#define  IS_1ST_TX_SLOT()        ((l1d_rf.tx_slots&FIRSTSLOTMASK[l1d_rf.cur_slot])==(1<<l1d_rf.cur_slot))
#if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF
#define  IS_2_TX_CWIN()          ((l1d_rf.tx_slots==5)||(l1d_rf.tx_slots==9)||(l1d_rf.tx_slots==10)||(l1d_rf.tx_slots==11)||(l1d_rf.tx_slots==13))
                                 /*       T_T_                  T__T                  _T_T                  TT_T                   T_TT        */
   #if IS_RF_MT6162 && IS_RF_VCO_PARTIAL_DOO_ON
#define  IS_2ND_RX_SLOT_EXIST()  ((l1d_rf.rx_slots==5)||(l1d_rf.rx_slots==9)||(l1d_rf.rx_slots==10)||(l1d_rf.rx_slots==11)||(l1d_rf.rx_slots==13))
                                 /*       R_R_                  R__R                  _R_R                  RR_R                   R_RR        */
   #endif
#endif

/*...................................*/

#if IS_DCXO_SUPPORT_CHIP && IS_AFC_EVENT_SUPPORT_CHIP
#define IS_USE_AFC()             (l1d_rf.is_afc_event_enable)
#define IS_AFC_TRIGGER_BSI()     (l1d_rf.is_afc_trigger_bsi)
#elif IS_DCXO_SUPPORT_CHIP
#define IS_USE_AFC()             (0)
#define IS_AFC_TRIGGER_BSI()     (0)
#else
#define IS_USE_AFC()             (1)
#define IS_AFC_TRIGGER_BSI()     (0)
#endif

#if IS_BBTXRX_CHIP_DESIGN_VER_2 || IS_BBTXRX_CHIP_DESIGN_VER_3
#define IS_AUTO_CAL_IN_PROCESS() (L1D_RF_RXDCOC_Check() || L1D_RF_TXIQMM_Check())
#else
#define IS_AUTO_CAL_IN_PROCESS() (0)
#endif

/*...................................*/

#if IS_BSI_TRIG_OFFCHIP_BSI_SWITCH_SUPPORT
   #if IS_BSI_TRIG_OFFCHIP_VRF18_SUPPORT
#define SDATA_BSI_OWNER_2G    0x0F0C0000  /* bit[19]: Vrf18 on,  [18]: BSI owner 2G */
#define SDATA_BSI_OWNER_TD    0x0F080000  /* bit[19]: Vrf18 on,  [18]: BSI owner TD */
   #else
#define SDATA_BSI_OWNER_2G    0x0F040000  /* bit[19]: Vrf18 xx,  [18]: BSI owner 2G */
#define SDATA_BSI_OWNER_TD    0x0F000000  /* bit[19]: Vrf18 xx,  [18]: BSI owner TD */
   #endif
#endif

#if IS_BSI_TRIG_OFFCHIP_VRF18_SUPPORT
   #if IS_BSI_TRIG_OFFCHIP_BSI_SWITCH_SUPPORT
#define SDATA_VRF18_ON        0x0F0C0000  /* bit[19]: Vrf18 on,  [18]: BSI owner 2G */
#define SDATA_VRF18_ON_ONLY   0x0F080000  /* bit[19]: Vrf18 on,  [18]: BSI owner TD */
#define SDATA_VRF18_OFF       0x0F000000  /* bit[19]: Vrf18 off, [18]: BSI owner TD */
   #else
#define SDATA_VRF18_ON        0x0F080000  /* bit[19]: Vrf18 on,  [18]: BSI owner xx */
#define SDATA_VRF18_ON_ONLY   0x0F080000  /* bit[19]: Vrf18 on,  [18]: BSI owner xx */
#define SDATA_VRF18_OFF       0x0F000000  /* bit[19]: Vrf18 off, [18]: BSI owner xx */
   #endif
#endif

typedef enum
{                          /* IS_BSI_TRIG_OFFCHIP_BSI_SWITCH_SUPPORT */
   BSI_SWITCH_2G_THEN_TD,  /* Switch to 2G first, and then back to TD after send/recv */
   BSI_SWITCH_2G,          /* Switch to 2G */
   BSI_SWITCH_NO_ACT,      /* Don't switch. Remain ON or OFF */
   BSI_SWITCH_NO_ACT_ONCE, /* Don't switch. Remain ON or OFF once for send/recv */
   BSI_SWITCH_TD           /* Switch to TD */
} BSI_SWITCH;

/*...................................*/

#if IS_TX_POWER_CONTROL_SUPPORT
#define TXPC_SLOT_MAX            4
#define TXPC_MAX_OFFSET_PWR      4     /* Max compensation: 4 dBm */
#define TXPC_DB_NUM              8     /* Must be 2^n             */
#define TXPC_DB_RES              12
#define TXPC_DB_ROUNDING         (1<<(TXPC_DB_RES-1))
#define TXPC_DB_MAX_OFFSET       ((TXPC_MAX_OFFSET_PWR<<TXPC_DB_RES)/2) /* DB offset: (1<<TXPC_DB_RES) == 2dB */
#define TXPC_RD_ADC_RES          6
#define TXPC_RD_ADC_ROUNDING     (1<<(TXPC_RD_ADC_RES-1))
#define AUXADC_DAT_RES           12
#define AUXADC_DAT_MASK          ((1<<AUXADC_DAT_RES) - 1)
#define AUXADC_VALUE_MAX         ((1<<AUXADC_DAT_RES) - 1)
#define TXPC_WEIGHT_CAL          2     /* For calibration   */
#define TXPC_WEIGHT_UPDATE       4     /* For normal update */
#define TEMP_IDX_DEFAULT         2     /* Default index of TXTEMP_DATA for 20 oC */
#define TEMP_VALUE_DEFAULT       20    /* Default temperature: 20 oC */


   #if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
#define TXPC_CL_DET_RES          12    /* the detetor resolution */
   #endif

   #if IS_TXPC_OL_BSI_SUPPORT || IS_TXPC_OL_AUXADC_SUPPORT
#define TXPC_OL_UPDATE_PERIOD    2//200   /* 200 L1 frames     */
   #endif

   #if IS_CHIP_MT6256 || IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6583_MD2
      #if IS_CHIP_MT6256
#define TXPC_RF_TEMP_CW          138
#define TXPC_BB_PGA_GAIN_MAX     7
      #endif
#define TXPC_AUXADC_VDET_PORT    6
#define TXPC_ADC_THRES_G         2
#define TXPC_ADC_THRES_E         4
#define TXPC_RF_TEMP_RES         12
   #elif IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1
#define TXPC_RF_TEMP_CW          16
#define TXPC_AUXADC_VDET_PORT    6
#define TXPC_ADC_THRES_G         2
#define TXPC_ADC_THRES_E         4
#define TXPC_RF_TEMP_RES         10
#define TXPC_TEMP_THRESHOLD      20    /* open loop slope change point - temperature: 20 oC */
   #elif IS_CHIP_MT6572
#define TXPC_RF_TEMP_CW          21    /* TEMP_MEAS_LATCH D[19:10], RXOBB_DETOUT D[7:0] */
#define TXPC_AUXADC_VDET_PORT    6
#define TXPC_ADC_THRES_G         2
#define TXPC_ADC_THRES_E         4
#define TXPC_RF_TEMP_RES         10
#define TXPC_TEMP_THRESHOLD      20    /* open loop slope change point - temperature: 20 oC */
   #elif IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
      #if IS_RF_MT6166
#define TXPC_RF_TEMP_CW          21    /* TEMP_MEAS_LATCH D[19:10], RXOBB_DETOUT D[7:0] */
#define TXPC_RF_TEMP_LSB         10
#define TXPC_RF_TEMP_RES         10
      #elif IS_RF_MT6165
#define TXPC_RF_TEMP_CW          8     /* RXOBB_DETOUT D[19:12], THADC_OUT[11:5] */
#define TXPC_RF_TEMP_LSB         5
#define TXPC_RF_TEMP_RES         7
      #elif IS_RF_MT6169
#define TXPC_RF_TEMP_CW          210   /* TEMP_MEAS_LATCH D[19:10], RXOBB_DETOUT D[7:0] */
#define TXPC_RF_TEMP_RES         10
      #endif
#define TXPC_AUXADC_VDET_PORT    6
#define TXPC_ADC_THRES_G         2
#define TXPC_ADC_THRES_E         4
#define TXPC_TEMP_THRESHOLD      20    /* open loop slope change point - temperature: 20 oC */
   #endif

   #if IS_RF_MT6162 || IS_RF_MT6163
#define TXPC_RF_ADC_SLOPE        32    /* 1 dB power change = 32 steps of ADC change        */
#define TXPC_RF_PA_GAIN_SLOPE    32    /* 1 dB power change = 32 steps of OH PA gain change */
   #endif

typedef enum
{                                /* Sampling       */
   TXPC_NO_CONTROL_TYPE,         /* (Do nothing)   */
   TXPC_AUXADC_CLOSED_TYPE,      /* AUXADC (Vdet)  */
   TXPC_BSI_CLOSED_TYPE,         /* BSI_RD (Pdet)  */
   TXPC_AUXADC_OPEN_TYPE,        /* AUXADC (Temp.) */
   TXPC_BSI_OPEN_TYPE            /* RF Temperature */
} TXPC_TYPE;

typedef enum
{                                /* Calibration    DB Update & Compensation        */
   TXPC_SAMPLE_MODE,             /* N              N, Only output sampling results */
   TXPC_NORMAL_MODE,             /* N              Y                               */
   TXPC_META_MODE,               /* Y              N                               */
   TXPC_TRANS_TO_META_MODE,      /* N              N                               */
   TXPC_TRANS_TO_NORMAL_MODE     /* N              N                               */
} TXPC_MODE;

typedef struct
{
            short    adc;        /* info_idx=0, record the themister read-back value */
            short    idx;        /* info_idx=1, record the region index (0~7) of current temperature */
            short    value;      /* info_idx=2, record the temperature (degree) calculated from the themister read-back value */
} sTXPC_TEMP_INFO;

typedef struct
{
            short    power_idx_right;              /* Setup stage only */
            short    power_dac_right;              /* Setup stage only */
            short    power_dac_left;               /* Setup stage only */
            short    power_dac_target;             /* Setup stage only */

   #if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
   unsigned char     is_dtx_detected;              /* Passed to COMPUTE in runQ1 */
            short    adc_interval[TXPC_SLOT_MAX];  /* Passed to COMPUTE in runQ1 */
            short    target_adc[TXPC_SLOT_MAX];    /* Passed to COMPUTE in runQ1. Target Vdet or Pdet ADC value */
            short    power_idx[TXPC_SLOT_MAX];     /* For calibration only */
   #endif
} sTXPC_SETUP;

   #if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
typedef struct
{                                                  /* Update in Run Q 1 */
   unsigned char     tx_slots;                     /* win.last_tx_slots. [7:0]:TX slots mask    */
      #if IS_EPSK_TX_SUPPORT
   unsigned char     tx_mod_type;                  /* win.last_tx_mod_type */ // 29 latter
      #endif
   unsigned char     tx_setting_change;            /* [3:0] 1: TX slot 0-3 power chang, 0: no change. If power changes, final computed ratio is divided by 2 to avoid the problem that contiguous slot power diff is not 2 dBm */
            char     rf_band;                      /* Computed from win.last_rtx_arfcn */
            short    arfcn;                        /* win.last_rtx_arfcn   */
            short    adc_interval[TXPC_SLOT_MAX];
            short    target_adc[TXPC_SLOT_MAX];    /* Target power. TXPC_AUXADC_CLOSED_MODE: Vdet, TXPC_BSI_CLOSED_MODE: Pdet */
            short    power_idx[TXPC_SLOT_MAX];     /* For traditional calibration only */
            long     rdbk_adc[TXPC_SLOT_MAX];      /* Readback power from AUXADC or RF(BSI). Resolution enhanced before storing. Fed into alpha filter */
} sTXPC_CL_COMPUTE;

typedef struct
{
   unsigned short    outdate;                            /* The larger this number is, the more likely this DB entry is to be cleared. */
            short    arfcn;                              /* Applied ARFCN */
            short    dac_offset_ratio_G[TXPC_SLOT_MAX];  /* APC DAC offset ratio, if target power is changed, apply half of the DB value due to incorrect ratio exchange between different PCL */
      #if IS_EPSK_TX_SUPPORT
            short    dac_offset_ratio_E[TXPC_SLOT_MAX];  /* APC DAC offset ratio, valide value range: min:(-1)<<14, max: 1<<14 */
      #endif
} sTXPC_CL_DB_DATA;

typedef struct
{
   sTXPC_CL_DB_DATA  data[TXPC_DB_NUM];
} sTXPC_CL_DB;
   #endif /* IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT */

   #if IS_TXPC_OL_BSI_SUPPORT || IS_TXPC_OL_AUXADC_SUPPORT
typedef struct
{
   short             temperature;
   short             update_coutdown;              /* Update event is triggered when this value is zero */
} sTXPC_OL_DB;
   #endif /* IS_TXPC_OL_BSI_SUPPORT || IS_TXPC_OL_AUXADC_SUPPORT */

typedef struct
{
   sTXPC_TEMP_INFO   temp_info;                    /* Temperature info for both closed & open loop */
   sTXPC_SETUP       setup;                        /* For TX setup recorded in  L1D_SetupTxAPC & L1D_SetupTxAPC2 */

   #if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
   sTXPC_CL_COMPUTE  cl_compute;                   /* For TXPC computation in L1D_TXPC_Update1 & L1D_TXPC_Update2 before updating DB */
   sTXPC_CL_DB       cl_db;                        /* Database of TX power compensation */
   #endif
   #if IS_TXPC_OL_BSI_SUPPORT || IS_TXPC_OL_AUXADC_SUPPORT
   sTXPC_OL_DB       ol_db;
   #endif
} sTXPC;

typedef struct
{
   #if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
   short             subband_compensation;
   short             temperature_compensation;
   #endif
   #if IS_TXPC_OL_BSI_SUPPORT || IS_TXPC_OL_AUXADC_SUPPORT
   short             ratio;                        /* record the compensation ratio */
   #endif
} sTXPC_TRACE;

extern       char       closed_loop_txpc_type;
extern const char       open_loop_txpc_type;
extern       char       is_txpc_calibrated;

   #if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
extern sTXPC_ADCDATA*   TXADC_Data[FrequencyBandCount];
extern sTXPC_TEMPDATA*  TXTEMP_Data[FrequencyBandCount];
      #if IS_EPSK_TX_SUPPORT
extern sTXPC_ADCDATA*   TXADC_Data_EPSK[FrequencyBandCount];
extern sTXPC_TEMPDATA*  TXTEMP_Data_EPSK[FrequencyBandCount];
      #endif
   #endif   /* IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT */

   #if IS_TXPC_OL_BSI_SUPPORT || IS_TXPC_OL_AUXADC_SUPPORT
extern short            ref_temperature;
   #endif
#endif      /* IS_TX_POWER_CONTROL_SUPPORT */

typedef enum
{
   VOLTCOM_NORMAL_MODE,
   VOLTCOM_NSFT_MODE,
   VOLTCOM_META_MODE,
   VOLTCOM_TRANS_TO_META_MODE,
   VOLTCOM_TRANS_TO_NSFT_MODE
} VOLTCOM_MODE;

/*...................................*/

#define  RF_RX                   0
#define  RF_TX                   1
#define  RF_TX_8G                2

/*...................................*/

#if IS_MIPI_SUPPORT
/* MIPI WIN Type */
#define MIPI_RX_START              0x01
#define MIPI_RX_MIDDLE             0x02
#define MIPI_RX_END                0x03
#define MIPI_TX_START              0x04
#define MIPI_TX_MIDDLE             0x05
#define MIPI_TX_END                0x06

/* MIPI SETDATA Type */
#define MIPI_SETDATA_SR            0x01
#define MIPI_SETDATA_ST            0x02
#define MIPI_SETDATA_STM           0x03
#endif

/* BB -> RF structure, can not use RF complie option */

typedef  struct
{
   unsigned char  cwin_idx;
   unsigned char  band;
   signed char    rtxwin_idx;
   char           is_init;
   char           is_nvram_data_ready;
   unsigned char  cur_slot;
   unsigned char  cur_slot_n;
   char           rx_slots;
   char           tx_slots;
   char           tx_mod_type;
   unsigned short tx_mod_type2;
   char           modidx;
   char           change;
   char           bb_tx_autocal;
   unsigned char  bat_volt;
   unsigned char  bat_temp;
   char           old_band;
   unsigned short apc_dc_offset;
   unsigned short AFC_data;
   unsigned long  RFN_data;
   unsigned long  IFN_data;
   unsigned long  AGC_data;
   char           inj;
   char           next_inj;
   char           d2c_txiqswap;
   char           d2c_txiqconfig;
   char           egsm_disable;
   unsigned long  Uncalibrated_LID_Flag;
   unsigned short gpio_modeswitch;
   unsigned char  handle_tx_dcm;
#if IS_DCXO_SUPPORT_CHIP && IS_AFC_EVENT_SUPPORT_CHIP
   unsigned char  is_afc_event_enable;
   unsigned char  is_afc_trigger_bsi;
#endif
#if IS_OBB_DETECTION_SUPPORT
   signed short   if_change;
   signed int     obb_arfcn;
#endif
#if IS_FHC_SUPPORT
   unsigned long  fhc_proc;
   signed short   fhc_high_apc_dcoffset;
   unsigned char  fhc_vbias[4];
   unsigned char  fhc_is_low_pcl[4];
#endif
#if IS_BBTXRX_CHIP_DESIGN_VER_2 || IS_BBTXRX_CHIP_DESIGN_VER_3
   signed short   rx_dc_i;
   signed short   rx_dc_q;
   signed short   cal_band;
   char           is_rf_rxdcoc_support;
   char           is_rf_txiqmm_support;
#endif
#if IS_TX_POWER_CONTROL_SUPPORT
   TXPC_MODE      txpc_mode;
   TXPC_TYPE      txpc_type;
   sTXPC          txpc;
   sTXPC_TRACE    txpc_trc;
   char           is_txpc_in_meta;
#endif
   VOLTCOM_MODE   voltcom_mode;
   char           is_voltcom_in_meta;
#if IS_W_CANCELLATION_SUPPORT
   char           if_state;
   #if IS_RF_MT6166 || IS_RF_MT6165
   char           if_sel_Nif_wc;   // use +IF channel for the +/-IF offset in W coefficient cal
   #endif
#endif
#if IS_BSI_TRIG_OFFCHIP_BSI_SWITCH_SUPPORT
   BSI_SWITCH     imm_bsi_switch_cfg;
#endif
#if IS_TDD_DM_RF_INIT_HANDSHAKE_SUPPORT
   char           is_init_done;
   int            SPI_sta;
#endif
#if IS_32K_CRYSTAL_REMOVAL_SUPPORT
   char           dcxo_lpm;
#endif
#if IS_32K_CRYSTAL_REMOVAL_SUPPORT || IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
   signed char    is_lock_dcxo;
#endif
#if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
   unsigned long  dcxo_frac_fpm;
   signed long    tx_nfracoffset;
#endif
#if IS_DECREASE_RF_TX_MAX_POWER_SUPPORT
   char           is_tx_decrease_power_needed;
#endif
#if IS_HEADROOM_DETECTION_SUPPORT ||       \
    IS_INBAND_BLOCKER_DETECTION_SUPPORT || \
    IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
   char           blk_flag;
#endif
#if IS_WIFI_ADAPTIVE_POWER_CONTROL_SUPPORT
   char           wifi_low_pwr_flag;
   char           rx_power_flag;
#endif
   unsigned long FBX;
#if IS_DCS_NB_WB_SWITCH_SUPPORT
   int            arfcn;
#endif
   unsigned long  is_init_abnormal;
#if IS_2G_TAS_SUPPORT
   uint8          tas_ant_sel;
#endif
}  sRFSETTING;

extern sRFSETTING l1d_rf;

/* RF only structure */

typedef  struct
{
   int            arfcn;
#if IS_EPSK_TX_SUPPORT || IS_RF_MT6162 || IS_RF_MT6163 || IS_RF_MT6280RF || IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165
   unsigned char  tx_power[4];
#endif
#if IS_DYNAMIC_MACRO_SUPPORT
   char           is_wakeup;     //for reset dynamic digital block
#endif
#if IS_RF_MT6256RF
   unsigned char  r_cal;         //for BT R calibration
   #if IS_EPSK_TX_SUPPORT
   unsigned char  is_alt_bb_gain;//for indication of using BB PGA gain 4~7
   unsigned short tx_power_sel;  //for TX power selection
   #endif
#endif
#if IS_FHC_SUPPORT
   #if IS_EPSK_TX_GAIN_CONTROL_SUPPORT
   unsigned short fhc_PGA_gain;  /* for MT6256 and OH EPSK APC DAC */
   #endif
#endif
#if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF || IS_WIFI_ADAPTIVE_POWER_CONTROL_SUPPORT || IS_REPORT_RF_TEMPERATURE_SUPPORT || IS_REPORT_RF_TEMPERATURE_BYATCMD_SUPPORT
   char           dedicated_flag;
#endif
#if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF
   char           rx_pm_flag;
   char           tx_1st_cwin_idx;
#endif
#if IS_RF_MT6162 || IS_RF_MT6163
   char           is_2g_on;             /* for 3G to check if 2G is on and decide if doing RF_Power_On or RF_Power_Off */
   char           lpfcap;
   char           is_rx_cal;
   char           is_tx_cal;
   char           is_isotpol;           /* On the near-integer channel, we should set it to 1 */
   char           is_integer;           /* On the      integer channel, we should set it to 1 */
   char           is_fhc;               /* for the RX LNA path loss calibration use */
   unsigned char  mt6162_rfid;
   unsigned char  is_fix_rf1828;        /* indicate if Vrf18 and Vrf28 should be always turned on */
   unsigned long  rx_dc_offset;
   #if IS_RF_RX_DCOC_SUPPORT
   signed short   rx_dac_to_voltage_i;  /* stored in S(4,4) */
   signed short   rx_dac_to_voltage_q;  /* stored in S(4,4) */
   signed short   rx_dc_offset_i[4][4]; /* [Band][G_Biquad] */
   signed short   rx_dc_offset_q[4][4]; /* [Band][G_Biquad] */
   #endif
   #if IS_RF_TX_CALIBRATION_SUPPORT
   signed short   tx_gain_error[4][4];  /* the   gain error is related to band and gain_RF (3,4,5,6) */
   signed short   tx_phase_error[4][4]; /* the  phase error is related to band and gain_RF (3,4,5,6) */
   signed short   tx_dc_bb_i[4];        /* the bb dc offset is related to band only                  */
   signed short   tx_dc_bb_q[4];        /* the bb dc offset is related to band only                  */
   signed short   tx_dc_rf_i[4][4];     /* the rf dc offset is related to band and gain_RF (3,4,5,6) */
   signed short   tx_dc_rf_q[4][4];     /* the rf dc offset is related to band and gain_RF (3,4,5,6) */
      #if IS_BBTXRX_CHIP_DESIGN_VER_3
   signed short   tx_dc_comp_i[4][16];  /* the dc compensation for [Band][PCL]                       */
   signed short   tx_dc_comp_q[4][16];  /* the dc compensation for [Band][PCL]                       */
   signed short   tx_dc_meas_i[4][3];
   signed short   tx_dc_meas_q[4][3];
   unsigned char  tx_cal_power_index;
      #endif
   #endif
#endif
#if IS_DCXO_ENABLE
   char           is_bsi_afc_active;    /* In TDDM, determine whether to update 2G AFC DAC to RF */
#endif
#if IS_TX_POWER_CONTROL_SUPPORT
   #if IS_RF_MT6162 || IS_RF_MT6163
   unsigned short real_read_back[TXPC_SLOT_MAX];
   unsigned short compensated_read_back[TXPC_SLOT_MAX];
   unsigned short tx_gain_setting[TXPC_SLOT_MAX];
   #elif IS_RF_MT6256RF || IS_RF_MT6280RF || IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165
      #if IS_EPSK_TX_SUPPORT
   unsigned short tx_gain_setting[TXPC_SLOT_MAX];
      #endif
   #endif
#endif
#if IS_RF_MT6280RF || IS_RF_MT6166
   char           is_2g_on;                 /* for 3G to check if 2G is on and decide if doing RF_Power_On or RF_Power_Off */
   char           is_power_on_cal;          /* 1.for wake up check 2.for rx dc offset check */
   char           is_fhc;                   /* for the RX LNA path loss calibration use */
   signed char    rxif_rck_m;               /* RXRC Cal. */
   #if IS_RF_MT6280RF
   signed char    calr_const;               /* RCAL Cal. */
   signed char    rxif_dcoc_daci_m[4][10];  /* Rx DC offset I [Band][G_LPF] */
   signed char    rxif_dcoc_dacq_m[4][10];  /* Rx DC offset Q [Band][G_LPF] */
   signed char    r8dl_stage1_adj;          /* ADC Loop Filter Coef. */
   signed char    r8dl_stage2_adj;          /* ADC Loop Filter Coef. */
   signed char    r8dl_stage3_adj;          /* ADC Loop Filter Coef. */
   signed char    r8dl_quantizer_adj;       /* ADC Loop Filter Coef. */
   #endif
   signed short   Gvga_rf[4][14];           /* EPSK Tx power gain [Band][Gvga_rf] */
   unsigned short power_on_cal_flag;        
   unsigned short tx_gain_step_k_flag;      /* Record gain step cal abnornal appear times */
#elif IS_RF_MT6165
   char           is_2g_on;                 /* for 3G to check if 2G is on and decide if doing RF_Power_On or RF_Power_Off */
   char           is_fhc;                   /* for the RX LNA path loss calibration use */
   signed short   Gvga_rf[4][14];           /* EPSK Tx power gain [Band][Gvga_rf] */
#endif
#if IS_RF_MT6169
   char           is_2g_on;                 /* for 3G to check if 2G is on and decide if doing RF_Power_On or RF_Power_Off */
   char           is_power_on_cal;          /* 1.for wake up check 2.for rx dc offset check */
   char           is_fhc;                   /* for the RX LNA path loss calibration use */
   signed char    calr_const;               /* RCAL Cal. */
   signed char    calr_tcl_r_m;             /* RCAL Cal. */
   signed char    txrcf_csel[2];            /* TXRCF Cal.tx_rcf_csel[0]: C_SEL for C value = b11, tx_rcf_csel[0]: C_SEL for C value = b00 */
   signed short   Gvga_rf[4][28];           /* EPSK Tx power gain [Band][Gvga_rf] */
   unsigned short power_on_cal_flag;
#endif
#if L1D_CUSTOM_DYNAMIC_SUPPORT
   #if IS_L1_RF_DRDI_CUSTOM_SETTING_FROM_MML1
   #else
   /* for GPIO debug */
   unsigned long  combined_result;
   signed   long  gpio_status[2];
   unsigned char  gpio_result[L1D_CUSTOM_GPIO_NUM_OF_DETECT_PINS_IN_USE];
   unsigned char  gpio_pin[L1D_CUSTOM_GPIO_NUM_OF_DETECT_PINS_IN_USE];

   /* for ADC debug */
   unsigned long  adc_get_ch_num;
   unsigned long  adc_read_result;
   signed   long  adc_rpc_status;
   signed   long  adc_dcl_status;
   signed   long  adc_cal_status;
   signed   long  adc_volt_result;
   unsigned char  adc_volt_level;

   /* for Barcode debug */
   unsigned long  barcode_result;
   unsigned char  barcode_error_no;
   unsigned char  barcode_digit_no;
   unsigned char  barcode_read;

   unsigned short custom_1st_idx;
   unsigned short custom_2nd_idx;
   unsigned short custom_3rd_idx;
   #endif
#endif
#if IS_DCS_NB_WB_SWITCH_SUPPORT
   unsigned char  is_dcs_nb_wb_switch_on;
#endif
#if IS_DSDA_DCS_TX_NOTCH_SWITCH_SUPPORT
   unsigned char  is_tx_notch_switch_on;
#endif

}  sRFSETTING2;

extern sRFSETTING2 l1d_rf2;

/*...................................*/

typedef  struct
{
   char           is_init;
   unsigned char  band;
   unsigned char  cur_slot;
   signed short   arfcn;
   signed short   tx_arfcn;
   unsigned char  tx_mid_idx;
   short          pm_delta[5];
   unsigned short tx_cwin;
} sMIPISETTING;

extern sMIPISETTING l1d_mipi;
typedef  struct
{
   unsigned short  ctrl;
   unsigned long   data;

} sSDATAINITDATA;

/*...................................*/

typedef  struct
{
   int  max_gain;
   int  min_gain;

} sL1DGAINRANGE;

/*...................................*/

typedef  struct
{
   short pos_gain;
   short A;
   long  setting;

} sL1DAGCDATA;

/*...................................*/

extern sLNAGAINOFFSET* LNA_PATHLOSS_TABLE[FrequencyBandCount];

/*...................................*/

#define WEIGHT(n)                ((unsigned short)((n)*(1<<14)))

typedef  struct
{
   signed   long  lowest_power;
   unsigned short power[16];
   sRAMPAREADATA  ramp;
} sRAMPDATA_DEFAULT;

extern const sRAMPDATA_DEFAULT RampData_Default;
#if IS_EPSK_TX_SUPPORT
extern const sRAMPDATA_DEFAULT RampData_Default_EPSK;
#endif
/*...................................*/

#if IS_EPSK_TX_SUPPORT
extern sMIDRAMPDATA*  GSM850_EPSK_InterRampData[4];
extern sMIDRAMPDATA*  GSM_EPSK_InterRampData[4];
extern sMIDRAMPDATA*  DCS_EPSK_InterRampData[4];
extern sMIDRAMPDATA*  PCS_EPSK_InterRampData[4];
#endif

/*...................................*/

extern XO_SLOPE_AREA_DATA  XO_SlopeAreaData[XO_SlopeArea_Num];
#if IS_VCXO_LC_SUPPORT
extern XO_SLOPE_AREA_DATA  XO_SlopeAreaData_ori[XO_SlopeArea_Num];
#endif
/*...................................*/

#define XO_SET_FLAG(flag,mask)   ((flag)|=(mask))
#define XO_CHECK_FLAG(flag,mask) ((flag)&(mask))

#define XO_LC_DISABLED           0x00
#define XO_LC_ENABLED            0x01
#define XO_LC_INIT_FAIL          0x02

extern unsigned char XO_LC_Flags;

typedef struct
{
   unsigned int         curr_idx;
   XO_SLOPE_AREA_DATA  *first_element;
   XO_SLOPE_AREA_DATA  *last_element;
}  XO_LC_PARAMS;

/*...................................*/

#if IS_BPI_DATA_32_BIT_CHIP
extern signed long  pdata_gmsk;
extern signed long  pdata_8psk;
#else
extern signed short pdata_gmsk;
extern signed short pdata_8psk;
#endif

/*...................................*/

typedef union  //  Vito For Register8
{  struct
   {
      unsigned int Address           : 7;
      unsigned int POLAR_APC_CAP     : 5;
      unsigned int VGA_SLOPE         : 4;
      unsigned int REFDET_SLOPE_SKEW : 4;
      unsigned int AM_FB_DAC         : 4;
      unsigned int reserved          : 8;
   } AM_LOOP;
   unsigned int RegData;
} ad6546tx_reg8;

typedef struct
{
   unsigned short stage;
   unsigned short flag;
   unsigned short ADD;
   unsigned short delay_ADD;
   unsigned short event_timing;
   unsigned short ADD_pair;
   unsigned long  DATA_pair;
} sBSIread;

typedef struct
{    signed short gain_bb_dac;
   unsigned short gain_bb_inverse;
} sTX_GAIN_BB_MAPPING;

/*...................................*/

typedef enum
{
   FMC_CAP_ID,
   FMC_TRX_OFFSET,
   FMC_TX_IQ,
   FMC_OE_ITEM,
   FMC_W_COEF,
   FMC_TX_PC,
   FMC_TX_PC_TEMP,
   FMC_BAT_TEMP_COMP,
   FMC_DTS_GAIN_CMB,
   FMC_UTS_BAND_CMB
} FAC_CAL_ITEM;

#define FMC_NULL_SETTING      0x0
#define FMC_CAPABLE           0x1
#define FMC_MANDATORY         0x2

/*...................................*/

extern const unsigned char   CONTISLOTMASK[5];
extern const unsigned char   FIRSTSLOTMASK[5];

/*.............................................*/
#ifdef  __UMTS_RAT__
/* temperature dac from 3G */
extern unsigned short U_TEMP_DAC[8];
#endif

/*.............................................*/

#if IS_RF_MT6162 || IS_RF_MT6163
extern unsigned char  TX_GAINRF_MAPPING[4][16];
extern signed   short BBGAIN_DECODE_TABLE[14][2];
extern unsigned long  read_back;
extern unsigned long  TX_GAIN_READ_ADDRESS[5];
#endif

/*.............................................*/

#if IS_RF_MT6169
extern const unsigned long  SDATA_CW117[5];
#endif

/*.............................................*/

#ifdef __MTK_TARGET__
   #ifdef NVRAM_NOT_PRESENT
#define IS_NVRAM_DATA_READY() (1)
   #else
#define IS_NVRAM_DATA_READY() (l1d_rf.is_nvram_data_ready==1)
   #endif
#else
#define IS_NVRAM_DATA_READY() (1)
#endif
/*.............................................*/

/* inteface to set BFE setting from calibration data rather than GCM */
void  L1D_GCMachine_Stop( void );
short L1D_GCMachine_Done( void );
int   L1D_CheckIfMetaMode( void );

void  L1D_RF_Init( void );
void  L1D_RF_Init_FIR( void );
void  L1D_RF_Init_BPI( void );
void  L1D_RF_Init_ABB( void );

#if IS_65NM_CHIP_BSI_BPI_PWN
void  L1D_RF_Init_BSI_BPI( void );
#endif

void  L1D_DM_Wait_BSI_Switch_Init_Done( void );
void  L1D_DM_Wait_UMTS_RF_Init_Done( void );

void  L1D_RF_WindowOn( void );
void  L1D_RF_WindowOff( void );
void  L1D_RF_SetWakeUpFlag( void );
void  L1D_RF_ClearWakeUpFlag( void );

#if IS_RF_AD6548 || IS_RF_AD6546
void  L1D_RF_CAP_Set( void );
void  L1D_RF_CAP_Clear( void );
#endif

#if IS_RF_MT6256RF || IS_RF_MT6251RF || IS_RF_MT6255RF || IS_RF_MT6280RF || IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165
unsigned short L1D_RF_ARFCN_CH_to_TxFreq( int rf_band, int arfcn );
unsigned short L1D_RF_ARFCN_CH_to_RxFreq( int rf_band, int arfcn );
#endif

#if IS_RF_MT6280RF || IS_RF_MT6169 || IS_RF_MT6166
void  L1D_RF_GetTxKDCOCAL2ndSetting( int rf_band, int arfcn, long *rfN, long *ifN );
unsigned short L1D_RF_GetTxDCOSCACodeTypeSetting( unsigned short Nint, unsigned long  Nfrac );
unsigned short L1D_RF_GetTxDEMChunkSetting( int rf_band, unsigned short Nint );
unsigned short L1D_RF_GetTxDAoffsetSetting( unsigned short Nint );
#endif
#if IS_RF_MT6166
void L1D_RF_SplitRxPLLSetting(unsigned long rfN, unsigned long ifN, unsigned short *Nint, unsigned long *Nfrac);
void L1D_RF_AdjustRxPLLSetting(unsigned short Nint, unsigned long Nfrac, signed long NfracOffset, unsigned long * rfN, unsigned long * ifN);
void L1D_RF_SplitTxPLLSetting(unsigned long rfN, unsigned long ifN, unsigned short *Nint, unsigned long *Nfrac);
void L1D_RF_AdjustTxPLLSetting(unsigned short Nint, unsigned long Nfrac, signed long NfracOffset, unsigned long * rfN, unsigned long * ifN);
void L1D_RF_CompensateSXSetting( unsigned short *Nint, unsigned long *Nfrac, signed long NfracOffset, unsigned char is_TX);
   #if IS_DUAL_TALK_RX_GAIN_TABLE_CO_BAND_SUPPORT
unsigned short L1D_Rx_Gain_Table_CoBand_Enable(void);
   #endif
#endif

#if IS_RF_MT6165
unsigned short L1D_RF_GetTxDEMChunkSetting( int rf_band, unsigned short Nint );
unsigned short L1D_RF_GetSxDCOSCACodeTypeSetting( unsigned short Nint, unsigned long  Nfrac );
unsigned short L1D_RF_GetSxDAoffsetSetting( unsigned long rfn );
unsigned short L1D_RF_GetSCAKNoffsetSetting(unsigned short Nint);
void L1D_RF_GetTxKDCOCAL2ndSetting( int rf_band, int arfcn, long *rfN, long *ifN );
void L1D_RF_SplitRxPLLSetting(unsigned long rfN, unsigned long ifN, unsigned short *Nint, unsigned long *Nfrac);
void L1D_RF_AdjustRxPLLSetting(unsigned short Nint, unsigned long Nfrac, signed long NfracOffset, unsigned long * rfN, unsigned long * ifN);
void L1D_RF_SplitTxPLLSetting(unsigned long rfN, unsigned long ifN, unsigned short *Nint, unsigned long *Nfrac);
void L1D_RF_AdjustTxPLLSetting(unsigned short Nint, unsigned long Nfrac, signed long NfracOffset, unsigned long * rfN, unsigned long * ifN);
void L1D_RF_CompensateSXSetting( unsigned short *Nint, unsigned long *Nfrac, signed long NfracOffset, unsigned char is_TX);
#endif

#if IS_RF_MT6256RF
   #if IS_EPSK_TX_SUPPORT
void L1D_Setup_BB_TxPower( unsigned short reversed_PGA_gain, unsigned char alt_bb_gain );
   #endif
unsigned long  L1D_RF_GetSData_ST2( void );
unsigned char  L1D_RF_Get_BT_Rcal( void );
#endif

#if IS_AST_B2S_SUPPORT
signed short L1D_RF_GetPData_PR2( int rf_band, char set_2g_own_bsi );
#endif

void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN );
void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN );
int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting );

#if IS_RF_MTKSOC1 || IS_RF_MTKSOC1T
void  L1D_RF_GetRxPLL_HB_FractionPart( int *Nfrac, int arfcn, int arfcn_base );
void  L1D_RF_Band1800_FrequecyFractionPartCompensation( int arfcn, int *Nfrac, short arfcn1, short arfcn2, short arfcn3, short arfcn4, short arfcn5, short arfcn6 );
void  L1D_RF_GetRX_SX_CAL_FBX_Setting( int arfcn, int rf_band, long *cw27, short sx_cal_dmd_t );
void  L1D_RF_GetTX_SX_CAL_FBX_Setting( int arfcn, int rf_band, long *cw27, short sx_cal_dmd_t, short OPLL_DIV4O5_DIV4 );
void  L1D_SetTxIQSwap_NO_PCS1900( void );
#endif

#if IS_RF_MTKSOC1T
/*Chip version*/
#define IS_RF_MTKSOC1_A1         0
#define IS_RF_MTKSOC1_A2         1
#define IS_RF_MTKSOC1_A3         0
#define IS_RF_MTKSOC1_A4         0
#define IS_RF_MTKSOC1_A5         0
#define IS_RF_MTKSOC1_MP         0

/*Parameter setting*/
   #if IS_RF_MTKSOC1_A2 || IS_RF_MTKSOC1_A3 || IS_RF_MTKSOC1_A4
//RFVCO subband calibration methold, MMD(=0) or DMD(=1), it should the same with cw27
#define MTKSOC1_SX_CALSBA        1
   #else
#define MTKSOC1_SX_CALSBA        0
   #endif

//RFVCO subband calibration time, 80us (=0) or 100us(=1), it should the same with cw27
#define MTKSOC1_SX_CAL_DMD_T     0

#endif

#if IS_RF_MT6256RF || IS_RF_MT6251RF || IS_RF_MT6255RF
#define SYNTH_SCALE              5
#define DCXO_FREQ                (26*SYNTH_SCALE)
#define DLIF                     (65*SYNTH_SCALE)   //65=13*5
#define DLIF_SCALE               384                //384=96*4
#endif

#if IS_RF_MT6280RF
/* For Synthesizer */
#define SYNTH_SCALE              5
#define TX_DCXO_FREQ             (26*SYNTH_SCALE)
#define RX_DCXO_FREQ             (52*SYNTH_SCALE)
#define DLIF                     (65*SYNTH_SCALE)   //65=13*5
#define DLIF_SCALE               384                //384=96*4

/* For Gain Setting */
#define GAIN_PA                  1120 /*     35(dB)  * 32, S10.5 */

/* For Turn On Power On Cal. Flag */
#define RXRC_DCOC_CAL_ON         0x01
#define TX_GAINSTEP_CAL_ON       0x02
#define ADC_LF_COEF_CAL_ON       0x04
#define RCAL_CAL_ON              0x08

/* For Check Power On Cal. Done Flag */
#define RXRC_DCOC_CAL_DONE       0x01
#define TXGAIN_STEP_CAL_DONE     0x02
#define ADC_LF_COEF_CAL_DONE     0x04
#define RCAL_CAL_DONE            0x08

/* For Tx Gain Step Cal. */
#define POR_CW80                 0x05000002L
//#define POR_CW79                 0x04F00003L
//#define POR_CW75                 0x04B00260L
#define POR_CW36                 0x02400180L
#define POR_CW41                 0x02900000L
#define POR_CW42                 0x02A40030L
   #if IS_CHIP_MT6280_S00
#define POR_CW34                 0x0229E000L
#define POR_CW75                 0x04B00260L
#define CW245_CURRENT_ON         0x0F580003L
#define CW245_CURRENT_OFF        0x0F580000L
#define POR_CW35                 0x02300400L /* E1 : CW change to Improve ORFS at LT */
#define POR_CW33                 0x02100000L /* E1 : CW change to Improve ORFS at LT */
   #else
#define POR_CW34                 0x02298000L
#define POR_CW9                  0x0094C025L
#define POR_CW75                 0x04B00060L
#define POR_CW117                0x07504840L //0x07502840L
#define POR_CW35                 0x02310400L
   #endif
#define TX_2GHB_EN               (0x1<<0)
#define TX_2GLB_EN               (0x1<<4)
#define POR_CW37                 0x02520030L
#define POR_CW38                 0x02602915L
#endif

#if IS_RF_MT6169
/* For Synthesizer */
#define SYNTH_SCALE              5
#define TX_DCXO_FREQ             (26*SYNTH_SCALE)
#define DLIF                     (65*SYNTH_SCALE)   //65=13*5
#define DLIF_SCALE               384                //384=96*4
#define POR_CW176                0x0B000000L

/* For Turn On Power On Cal. Flag */
#define RCAL_CAL_ON              0x01
#define TX_GAINSTEP_CAL_ON       0x02
#define TX_DET_DCOC_CAL_ON       0x04
#define TX_RCF_CAL_ON            0x08

/* For Check Power On Cal. Done Flag */
#define RCAL_CAL_DONE            0x01
#define TX_GAINSTEP_CAL_DONE     0x02
#define TX_DET_DCOC_CAL_DONE     0x04
#define TX_RCF_CAL_DONE          0x08

/* For RX/TX Setting */
#define POR_CW77                 0x04D3222AL //Move from m12196.c POR
#define POR_CW78                 0x04E01C64L //Move from m12196.c POR
#define POR_CW118                0x076EE311L //Move from m12196.c POR
#define POR_CW162                0x0A200052L

#define POR_CW74                 0x04A00311L
#define POR_CW75                 0x04B00004L

/* For Co-Clock Setting */
#define POR_CW247                0x0F78CCBCL
#define POR_CW252                0x0FC01EFFL
#define POR_CW253                0x0FD00040L
#define CO_CLOCK_MASK            (0x7)

/* For Gain Setting */
#define GAIN_PA                  800 /*     25(dB)  * 32, S10.5 */
#endif

#if IS_RF_MT6166
/* CW129 */
/* RXIF mode select */
#define RXIF_MODE                (0x0<<14)  //00: 2G/TDD-SC; 01: TDD-DC; 10(POR): FDD-SC; 11: FDD-DC
/* Dual talk mode select */
   #if IS_DUAL_TALK_RX_GAIN_TABLE_CO_BAND_SUPPORT
      #if ( GSM850_PATH_SEL > LNA_2 ) || ( GSM_PATH_SEL > LNA_2 ) || ( DCS_PATH_SEL > LNA_2 ) || ( PCS_PATH_SEL > LNA_2 )
#define RXDTK_EN                 (0x1<< 7)  //0(POR): single talk; 1 dual talk
      #else
#define RXDTK_EN                 (0x0<< 7)  //0(POR): single talk; 1 dual talk
      #endif
   #else
#define RXDTK_EN                 (0x0<< 7)  //0(POR): single talk; 1 dual talk
   #endif
//#define POR_CW129                ((0x0810A450L)|OBBDET_INBURST_EN) // CW129 D[19]:RXLNA_DET_INBURST_EN
#define OBBDET_INBURST_EN        (0x0<<19)                         // OBB detection in burst is disable on default

/* For Synthesizer */
#define SYNTH_SCALE              5
#define TX_DCXO_FREQ             (26*SYNTH_SCALE)
#define RX_DCXO_FREQ             (26*SYNTH_SCALE)   //(52*SYNTH_SCALE)
#define DLIF                     (65*SYNTH_SCALE)   //65=13*5
#define DLIF_SCALE               384                //384=96*4
#define STX_MAX_NFRAC            (0x1<<23)
#define SRX_MAX_NFRAC            (0x1<<23)

/* For Gain Setting */
#define GAIN_PA                  1120 /*     35(dB)  * 32, S10.5 */

/* For Turn On Power On Cal. Flag */
#define RXRC_CAL_ON              0x01
#define TX_GAINSTEP_CAL_ON       0x02

/* For Check Power On Cal. Done Flag */
#define RXRC_CAL_DONE            0x01
#define TX_GAINSTEP_CAL_DONE     0x02

/* RX RC Value */
#define POR_CW144                0x09080020L
#define RXIF_RCK_MASK            0x0000003FL  //  6 bits length

/* For Tx Gain Step Cal. */
#define POR_CW87                 0x05700000L
#define POR_CW36                 0x02400180L
#define POR_CW41                 0x02900000L
#define POR_CW42                 0x02A40020L//0x02A40030L
#define POR_CW34                 0x02288000L
#define POR_CW43                 0x02B2D040L
#define POR_CW45                 0x02D11000L
#define POR_CW47                 0x02F00000L
#define TX_2GHB_EN               (0x1<<0)
#define TX_2GLB_EN               (0x1<<4)

/* For SRX Setting */
#define POR_CW224                0x0E03B19AL
#define SRX_REF_DOUBLER_EN       (0x0<<7)
#define SRX_VCO_CFG              (0x2<<3)

/* For STX Setting */
#define POR_CW99                 0x06300000L
#define POR_CW117                0x07502840L

/* For Co-Clock Setting */
#define POR_CW247                0x0F78CCBCL
#define POR_CW252                0x0FC01EFFL
#define POR_CW253                0x0FD00040L
#define CO_CLOCK_MASK            (0x7)

/* For DCXO Setting */
#define POR_CW250                0x0FAFF750L
#endif
#if IS_RF_MT6165
/* For OBB Related Setting */
   #if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
#define RXLNA_NODET_EN           (0x0<<15)          // Single Talk Setting (SAWless)
   #else
#define RXLNA_NODET_EN           (0x1<<15)          // Dual Talk Setting (with SAW)
   #endif

#define OBBDET_INBURST_EN        (0x0<<17)                         // OBB detection in burst is disable on default


/* For Synthesizer */
#define SYNTH_SCALE              5
#define TX_DCXO_FREQ             (26*SYNTH_SCALE)
#define RX_DCXO_FREQ             (26*SYNTH_SCALE)   //(52*SYNTH_SCALE)
#define DLIF                     (65*SYNTH_SCALE)   //65=13*5
#define DLIF_SCALE               384                //384=96*4
#define STX_MAX_NFRAC            (0x1<<23)
#define SRX_MAX_NFRAC            (0x1<<23)

/* For Gain Setting */
#define GAIN_PA                  1120 /*     35(dB)  * 32, S10.5 */
//#define TX_GAIN_STEP_NUM         13
#define POR_CW130                0x08200000L
#define POR_CW131                0x08300000L
#define TX_2GHB_EN               (0x1<<6)
#define TX_2GLB_EN               (0x1<<7)

/* For SX Setting */
#define POR_CW173                0x0AD001FBL
#define POR_CW174                0x0AE00053L
#define POR_CW182                0x0B600101L
#define POR_CW184                0x0B800000L
#define POR_CW188                0x0BC01800L
#define POR_CW169                0x0A980060L
#define POR_CW160                0x0A01254AL
#define POR_CW175                0x0AF03EC4L
#define POR_CW176                0x0B025054L
#define POR_CW179                0x0B3FF34FL

/* For Co-Clock Setting */
#define POR_CW247                0x0F78CCBCL
#define POR_CW252                0x0FC01EFFL
#define POR_CW253                0x0FD00040L
#define CO_CLOCK_MASK            (0x7)

/* For DCXO Setting */
#define POR_CW250                0x0FAFF750L

/* For TX Gain setting */
#define POWER_BB0                  2363 /*   9.23(dBm) * 256, S7.8 */
#define GAIN_BACKOFF_LB               0 /*      0(dB)  * 32 ,S10.5 */
#define GAIN_BACKOFF_HB               0 /*      0(dB)  * 32 ,S10.5 */
#define GAINBB0_CODE_LENGTH           9
#endif

void  L1D_RF_SetFixGainEnable( unsigned char enable );
void  L1D_RF_CheckFHC( char is_fhc );

// Update AFC DAC by BSI 3-wire
void  L1D_RF_UpdateAFCDac( unsigned short afc_data );

void  L1D_RF_GetPGAGain( unsigned short tx_power );

void  L1D_RF_InitRampTable( int rf_band );

#if IS_EPSK_TX_SUPPORT
void  L1D_RF_InitRampTableEPSK( int rf_band );
short L1D_RF_SetInterslotPowerLevel( int rf_band, int arfcn, short mod_type );
#endif

#if IS_RF_CMOSEDGE
short L1D_RF_SetPGASubBandWeight( void );
#endif

void  L1D_RF_SetCrystalCap_Value( int cap_no );
void  L1D_RF_SetCrystalDac_Value( short dacValue );
int   L1D_RF_GetCrystalCapRange( void );
int   L1D_RF_GetWCalMode( void );
unsigned short L1D_RF_GetCalSets( FAC_CAL_ITEM item );
unsigned long  L1D_GetBandSupport( void );
unsigned short L1D_Get_EPSK_TX_Support( void );
unsigned short L1D_GetPsEpskTxStatus( void );
unsigned short L1D_Get_TCVCXO_Support( void );
signed short L1D_RF_GetDSPSetPointLNAHighMode( void );
signed short L1D_RF_GetDSPSetPointLNAMidMode( void );
signed short L1D_RF_GetDSPSetPointLNALowMode( void );
#if IS_BSI_V2_SUPPORT
unsigned long L1D_RF_TX_BSI_ENA( unsigned short win );
#endif
#if IS_BPI_V2_SUPPORT
unsigned long L1D_RF_TX_BPI_ENA( unsigned short win );
#endif
void  L1D_RF_TXIQ_Dynamic_Swap( void );
void  L1D_BFE_SetTxIQSwap( void );
void  L1D_BFE_SET_TxIQSwapRegister( int is_swap );
void  L1D_BFE_GET_RxRegisters( void *set );
void  L1D_BFE_SET_RxRegisters( void *set );
void  L1D_BFE_GET_TxRegisters( void *set );
void  L1D_BFE_SET_TxRegisters( void *set );

#define HW_READ_BFERXSET(  _set )   L1D_BFE_GET_RxRegisters( &_set )
#define HW_WRITE_BFERXSET( _set )   L1D_BFE_SET_RxRegisters( &_set )
#define HW_READ_BFETXSET(  _set )   L1D_BFE_GET_TxRegisters( &_set )
#define HW_WRITE_BFETXSET( _set )   L1D_BFE_SET_TxRegisters( &_set )

#if IS_TDMA_BSI_READBACK_SUPPORT
/*BSI read flag*/
#define BSI_GET_READBACK_DATA       0x1
#define BSI_READBACK_DATA_ERROR     0x2
#define BSI_READBACK_ENABLE         0x4
#define BSI_READ_INDICATE_ADDR(add) { BSIread.ADD = add; }

typedef  enum
{
   BSI_READ_STOP,
   BSI_READ_START,
   BSI_READ_DELAY,
   BSI_READ_DELAY_THEN_START

}  BSI_READ_STATUS;

extern sBSIread BSIread;
void  L1D_RF_Readback_BSI_Set_Event( void* data );
void  L1D_RF_Readback_BSI_Set_Address( void* data );
void  L1D_RF_Readback_BSI_GetData( unsigned short ADD, unsigned long *DATA );
#endif

#if IS_RF_MT6251RF
void  L1D_RF_OBB_trace_setting( void );
#endif

unsigned long L1D_RF_SetTX_BSI_CW( short qb_st2, short timing_bound );

#define FOUR_POINT_FOUR_SUBBAND          0  // 4-point W cal.,  4 subbands
#define ZERO_POINT_SIXTEEN_SUBBAND       1  // 0-point W cal., 16 subbands
#define ONE_POINT_SIXTEEN_SUBBAND        2  // 1-point W cal., 16 subbands
#define FOUR_POINT_SIXTEEN_SUBBAND       3  // 4-point W cal., 16 subbands
#define EIGHT_POINT_SIXTEEN_SUBBAND      4  // 8-point W cal., 16 subbands
#define SIXTEEN_POINT_SIXTEEN_SUBBAND    5  //16-point W cal., 16 subbands
#if IS_W_CANCELLATION_SUPPORT
   #if IS_RF_MT6256RF || IS_RF_MT6251RF || IS_RF_MT6255RF || IS_RF_MT6280RF || IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165
unsigned short  L1D_RF_FindGainStep( unsigned long gain_setting, FrequencyBand rf_band );
   #endif
#endif

#define SC_DEDICATED            0x0001
#define SC_ACCESS               0x0002
#define SC_DEDICATED_2TX        0x0004
#define SC_NON_IDLE             ( SC_DEDICATED | SC_ACCESS | SC_DEDICATED_2TX )

void  L1D_RF_Access_Dedicated_Mode_Start( char mode_flag );
void  L1D_RF_Access_Dedicated_Mode_End( char mode_flag );
void  L1D_RF_Check_RTX_PM( unsigned char rx_slots, int pm_count, char tx_cwin_idx, unsigned short is_fsi_win );
void  L1D_RF_SetStandbyMode( void );

short L1D_RF_SetTxPowerLevel( int rf_band, int arfcn, short power_dbm, short mod_type );
short L1D_RF_GetRxPathLoss( int rf_band, int arfcn, short request_gain );
void  L1D_RF_SetTxPower( short *tx_power );
void  L1D_RF_NotifyBatteryVoltage( int micro_volt );
void  L1D_RF_NotifyBatteryTemperature( int mili_degree );
void  L1D_RF_NotifyRFTemperature( int temp_adc );
unsigned char L1D_RF_IS_GetRFTemperatureFromADC( void );
unsigned char L1D_RF_IS_GetBatteryInfoFromADC( void );

void  L1D_RF_ResetSData_StopFSIWinOff( int idx );
void  L1D_RF_SetSData_FSIWinOff( int idx );

#if IS_RF_MT6163
void  L1D_RF_SetSData_FSIWinOff_SR3( int idx );
#endif

void  L1D_RF_SetPData_PR( void );
void  L1D_RF_SetPData_PT( void );
void  L1D_RF_SetPData_PR2M( void );
void  L1D_RF_SetPData_PT2M( void );
void  L1D_RF_SetSData_SR1( void );
void  L1D_RF_SetSData_SR2( void );
void  L1D_RF_SetSData_SR3( void );
void  L1D_RF_SetSData_ST1( void );
void  L1D_RF_SetSData_ST2( void );
void  L1D_RF_SetSData_ST3( void );

#if IS_BSI_SX0_SUPPORT
void  L1D_RF_SetSData_SR0( void );
void  L1D_RF_SetSData_ST0( void );
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
void  L1D_RF_SetSData_ST2B( void );
void  L1D_RF_SetSData_ST2M( void );
void  L1D_RF_Set_FB_FIR( void );
/*
void  L1D_RF_init_FIR_SwitchNB( int wider );
 */
void  L1D_RF_TXIQ_Dynamic_Config( void );
void  L1D_BFE_SetTxIQ_Config( void );
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION || IS_CHIP_MT6225_AND_LATTER_VERSION
void  L1D_RF_init_FIR_SwitchNB( int wider );
#endif

#if IS_MIPI_SUPPORT

extern const char is_2g_mipi_enable;

void  L1D_MIPI_Init( void );
void  L1D_MIPI_Init_BSI( void );
void  L1D_MIPI_PowerOn( void );
void  L1D_MIPI_PowerOff( void );

void L1D_MIPI_Table_Update(void);

void  L1D_MIPI_TX_BSI_DISABLE( unsigned short );

void  L1D_MIPI_RTX_WIN( signed int win_idx,unsigned short WIN_TYPE );
void  L1D_MIPI_SetSData_SX(  unsigned short rt_type );
void  L1D_MIPI_CWIN_SELECT_CUR_SLOT( unsigned short  tx_slot_con, unsigned char  pre_slot );
void  L1D_MIPI_SetSData_FSIWinOff_SR( void );
unsigned short L1D_MIPI_Parity_Bit( unsigned short data );

void  L1D_MIPI_RX_SB( signed int cwin_idx, signed short pos_on, signed short pos_off, signed short tx_wrap );
void  L1D_MIPI_RX_PM( signed int cwin_idx, unsigned short is_pm_enhance, unsigned short is_pm_1r7pm , unsigned short is_pm_tddm );
void  L1D_MIPI_stopFSIwindow( void );
#endif

#if IS_TX_POWER_CONTROL_SUPPORT
void  L1D_RF_Init_TXPC_Data( void );
void  L1D_RF_TXPC_Get_Temp_ADC( sTEMPERATURE_ADC_L1CAL *buff );
void  L1D_RF_TXPC_Set_Temp_ADC( sTEMPERATURE_ADC_L1CAL *temp_adc );
void  L1D_RF_TXPC_RecordParam( unsigned char scenario, const sRAMPDATA* band, unsigned short weight, short temp_idx, char is_rollback, short target_dac );
short L1D_RF_TXPC_RecUpdateAPCDAC( const short dac_ori, unsigned char rf_band, short arfcn, short slot, char is_EPSK );
short L1D_RF_TXPC_ComputeVAPC_DAC( const short dac_ori, short ratio, short dac_diff );

   #if IS_EPSK_TX_SUPPORT
      #if IS_RF_MT6256RF
short L1D_RF_TXPC_ComputePGA_GAIN( const short gain_ori, short slot, short ratio, short gain_diff );
      #elif IS_RF_MT6162 || IS_RF_MT6163
short L1D_RF_TXPC_Compute_OH_PA_GAIN( const short dac_ori, short ratio );
	  #elif IS_RF_MT6280RF || IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165
short L1D_RF_TXPC_Compute_OrionH_Remaining_GAIN( const short dac_ori, short ratio );
      #endif
   #endif
#endif

#if IS_TXPC_CL_AUXADC_SUPPORT
void  L1D_RF_TXPC_CL_AUXADC_PowerOn( void );
void  L1D_RF_TXPC_CL_AUXADC_PowerOff( void );
#endif

#if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
void  L1D_TXPC_CL_RecordPowerIndex( short index, short slot );
void  L1D_RF_TXPC_CL_GetAllADC( sTXPC_L1CAL *buff, char is_EPSK );
void  L1D_RF_TXPC_CL_GetAllTEMP( sTXPC_L1CAL *buff, char is_EPSK );
void  L1D_RF_TXPC_CL_GetSubband( int rf_band, unsigned short *buff, char is_EPSK );
void  L1D_RF_TXPC_CL_SetAllCalADC( sTXPC_L1CAL *cal_adc, char is_EPSK );
void  L1D_RF_TXPC_CL_SetAllCalTEMP( sTXPC_L1CAL *cal_adc, char is_EPSK );
void  L1D_RF_TXPC_CL_BackUpSubband( int rf_band, char is_EPSK );
void  L1D_RF_TXPC_CL_RestoreSubband( void );
void  L1D_RF_TXPC_CL_BackupAllCalADC( void );
void  L1D_RF_TXPC_CL_RestoreAllCalADC( void );
void  L1D_RF_TXPC_CL_Read_RF_Power( long *sample_array, unsigned char tx_slot, unsigned char mod_type );
void  L1D_RF_TXPC_CL_Update_TXADC_Subband_Data( unsigned short read_back_data, short arfcn, char rf_band, unsigned char mod_type );
unsigned short L1D_RF_TXPC_CL_GetDetReadBack( unsigned char is_compensated, unsigned short slot_idx );
unsigned short L1D_RF_TXPC_CL_GetOneADC( int rf_band, int power_in_dBm, char is_EPSK );
unsigned char  L1D_RF_TXPC_CL_Check_OHGMSK( void );
short L1D_TXPC_CL_Detector_Subband_Compensation( unsigned char mod_type );
short L1D_TXPC_CL_Detector_Temperature_Compensation( unsigned char mod_type );
#endif

#if IS_TX_POWER_CONTROL_SUPPORT
short L1D_RF_TXPC_GetTxGainSetting( unsigned char is_gain_rf, unsigned char slot_idx );
short L1D_RF_TXPC_GetTemperatureInfo( unsigned char info_idx );
short L1D_RF_TXPC_CheckTransitionMode( void );
unsigned char  L1D_RF_TXPC_IS_CAL( void );
   #if IS_RF_MT6162 || IS_RF_MT6163 || IS_RF_MT6256RF || IS_RF_MT6280RF || IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165
void  L1D_RF_GetRFTemperatureIdxAndValue( short temp_dac );
   #endif
   #if IS_CHIP_MT6256 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
unsigned short L1D_RF_TXPC_GetTemperatureInfoFromBSI( void );
   #endif
#endif

#if IS_TXPC_CL_AUXADC_SUPPORT
#define L1D_RF_TXPC_CL_AUXADC_POWERON()   L1D_RF_TXPC_CL_AUXADC_PowerOn()
#define L1D_RF_TXPC_CL_AUXADC_POWEROFF()  L1D_RF_TXPC_CL_AUXADC_PowerOff()
#else
#define L1D_RF_TXPC_CL_AUXADC_POWERON()   {;}
#define L1D_RF_TXPC_CL_AUXADC_POWEROFF()  {;}
#endif /* IS_TXPC_CL_AUXADC_SUPPORT */

#if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT
#define L1D_RF_TXPC_CL_RECORD_PWR_IDX( index, slot )                                               \
{  L1D_TXPC_CL_RecordPowerIndex( index, slot );                                                    \
}

#define L1D_RF_TXPC_CL_GET_ALL_ADC( buff, is_EPSK )                                                \
{  L1D_RF_TXPC_CL_GetAllADC( buff, is_EPSK );                                                      \
}

#define L1D_RF_TXPC_CL_GET_ALL_TEMP( buff, is_EPSK )                                               \
{  L1D_RF_TXPC_CL_GetAllTEMP( buff, is_EPSK );                                                     \
}

#define L1D_RF_TXPC_CL_GET_SUBBAND( rf_band, buff, is_EPSK )                                                \
{  L1D_RF_TXPC_CL_GetSubband( rf_band, buff, is_EPSK );                                                     \
}

#define L1D_RF_TXPC_CL_SET_ALL_CAL_ADC( cal, is_EPSK )                                             \
{  L1D_RF_TXPC_CL_SetAllCalADC( cal, is_EPSK );                                                    \
}

#define L1D_RF_TXPC_CL_SET_ALL_CAL_TEMP( cal, is_EPSK )                                            \
{  L1D_RF_TXPC_CL_SetAllCalTEMP( cal, is_EPSK );                                                   \
}

#else
#define L1D_RF_TXPC_CL_RECORD_PWR_IDX( index, slot )                                               {;}
#define L1D_RF_TXPC_CL_GET_ALL_ADC( buff, is_EPSK )                                                {;}
#define L1D_RF_TXPC_CL_GET_ALL_TEMP( buff, is_EPSK )                                               {;}
#define L1D_RF_TXPC_CL_GET_SUBBAND( buff, is_EPSK )                                                {;}
#define L1D_RF_TXPC_CL_SET_ALL_CAL_ADC( cal, is_EPSK )                                             {;}
#define L1D_RF_TXPC_CL_SET_ALL_CAL_TEMP( cal, is_EPSK )                                            {;}
#endif /* IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT */

#if IS_TXPC_OL_BSI_SUPPORT || IS_TXPC_OL_AUXADC_SUPPORT
#define L1D_RF_TXPC_OL_GET_TEMPERATURE( buff )                                                     \
{  (buff)->temperature = ref_temperature;                                                          \
}

#define L1D_RF_TXPC_OL_SET_CAL_TEMPERATURE( cal )                                                  \
{  ref_temperature = (cal)->temperature;                                                           \
}
#else
#define L1D_RF_TXPC_OL_GET_TEMPERATURE( buff )                                                     {;}
#define L1D_RF_TXPC_OL_SET_CAL_TEMPERATURE( cal )                                                  {;}
#endif

#if IS_TX_POWER_CONTROL_SUPPORT
#define L1D_RF_INIT_TXPC_DATA()                                                                    \
{  L1D_RF_Init_TXPC_Data();                                                                        \
}

#define L1D_RF_TXPC_GET_FLAG( buff )                                                               \
{  (buff)->is_calibrated = is_txpc_calibrated;                                                     \
}

#define L1D_RF_TXPC_SET_CAL_FLAG( cal )                                                            \
{  is_txpc_calibrated |= (cal)->is_calibrated;                                                     \
}

#define L1D_RF_TXPC_SET_TEMP_ADC( temp_adc )                                                       \
{  L1D_RF_TXPC_Set_Temp_ADC( temp_adc );                                                           \
}

#define L1D_RF_TXPC_RECORD_PARAM( scenario, band, weight, temp_idx, is_rollback, target_dac )      \
{  L1D_RF_TXPC_RecordParam( scenario, band, weight, temp_idx, is_rollback, target_dac );           \
}

#define L1D_RF_TXPC_REC_UPDATE_APCDAC( dac_ori, rf_band, arfcn, slot, is_EPSK )                    \
(  L1D_RF_TXPC_RecUpdateAPCDAC( dac_ori, rf_band, arfcn, slot, is_EPSK )   )

   #if IS_RF_MT6162 || IS_RF_MT6163 || IS_ORION_RF_SERIES
#define L1D_RF_TXPC_UPDATE_TEMPERATUREINFO()                                                       \
{  L1D_RF_TXPC_Update_TemperatureInfo();                                                           \
}
   #endif

   #if IS_EPSK_TX_SUPPORT
      #if IS_RF_MT6256RF
#define L1D_RF_TXPC_COMPUTE_DAC_EPSK( dac_ori, slot, ratio, dac_diff )                             \
(  L1D_RF_TXPC_ComputePGA_GAIN( dac_ori, slot, ratio, dac_diff )  )
      #elif IS_RF_MT6162 || IS_RF_MT6163
#define L1D_RF_TXPC_COMPUTE_DAC_EPSK( dac_ori, slot, ratio, dac_diff )                             \
(  L1D_RF_TXPC_Compute_OH_PA_GAIN( dac_ori, ratio )  )
	  #elif IS_RF_MT6280RF || IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165
#define L1D_RF_TXPC_COMPUTE_DAC_EPSK( dac_ori, slot, ratio, dac_diff )                             \
(  L1D_RF_TXPC_Compute_OrionH_Remaining_GAIN( dac_ori, ratio )  )
      #else
#define L1D_RF_TXPC_COMPUTE_DAC_EPSK( dac_ori, slot, ratio, dac_diff )                             \
(  L1D_RF_TXPC_ComputeVAPC_DAC( dac_ori, ratio, dac_diff )  )
      #endif
   #endif /* IS_EPSK_TX_SUPPORT */
#else
#define L1D_RF_INIT_TXPC_DATA()                                                                    {;}
#define L1D_RF_TXPC_GET_FLAG( buff )                                                               {;}
#define L1D_RF_TXPC_SET_CAL_FLAG( cal )                                                            {;}
#define L1D_RF_TXPC_SET_TEMP_ADC( temp_adc )                                                       {;}
#define L1D_RF_TXPC_RECORD_PARAM( scenario, band, weight, temp_idx, is_rollback, target_dac )      {;}
#define L1D_RF_TXPC_REC_UPDATE_APCDAC( dac_ori, rf_band, arfcn, slot, is_EPSK )                    (dac_ori)
#define L1D_RF_TXPC_UPDATE_TEMPERATUREINFO()                                                       {;}
#endif /* IS_TX_POWER_CONTROL_SUPPORT */

#if IS_DECREASE_RF_TX_MAX_POWER_SUPPORT
void  L1D_RF_set_TxPowerDecrementTable( unsigned char op_code, unsigned char tx_reduction_table[4][2][4] );
void  L1D_RF_Check_TxPowerDecrementTable( char valid, unsigned char op_code, unsigned char tx_reduction_table[4][2][4] );
#endif

/*===============================================================================*/
/* for RF Tool Customization Support                                             */
/*===============================================================================*/
void  L1D_RF_Custom_Table_Update( void );
void  L1D_RF_Custom_Table_Update_V2_No_Check( void );

/*.............................................*/

void  L1D_PowerOn_BSI( void );
void  L1D_AFCDAC_On( void );
void  L1D_AFCDAC_Off( void );
void  L1D_BeforeSleep( void );
void  L1D_AfterSleep( void );
char  L1D_RF_Check_DCXO_Enable( void );
void  L1D_RF_Set_DCXO_2G_AFCDAC_Active( char set );
unsigned short L1D_RF_GetTxPAVBias_TxITC( unsigned short lb_cw_high_idx, unsigned short hb_cw_high_idx );
short L1D_RF_GetTxPAVBias(void);

/*.............................................*/

#define IMMMASK_AFC              0x01
#define IMMMASK_BSI              0x02
#define IMMMASK_BPI              0x04
#define IMMMASK_ALL              (IMMMASK_AFC|IMMMASK_BSI|IMMMASK_BPI)

#if IS_BPI_DATA_32_BIT_CHIP
typedef unsigned long            uintBPI;      /*32 bits */
#else
typedef unsigned short           uintBPI;      /*16 bits */
#endif

#if IS_BSI_CON_32_BIT_CHIP
typedef unsigned long            uintBSI;      /*32 bits*/
#else
typedef unsigned short           uintBSI;      /*16 bits*/
#endif

void  WAIT_TIME_QB( short time_qb );
void  IMM_MODE_BEGIN( unsigned short imm_mask );
void  IMM_MODE_END( void );
void  IMM_SEND_BPI( uintBPI data );
void  IMM_SEND_BSI( uintBSI ctrl, unsigned long data );
void  IMM_RECEIVE_BSI( uintBSI ADD_Ctrl, unsigned long ADD, uintBSI DATA_Ctrl, unsigned long *DATA );
void  IMM_UPDATE_BSI_BEGIN( void );
void  IMM_UPDATE_BSI_END( void );
void  IMM_OFFCHIP_BSI_CFG( BSI_SWITCH state );

#if IS_BSI_TRIG_OFFCHIP_BSI_SWITCH_SUPPORT
#define IMM_OFFCHIP_BSI_SWITCH_SET( state )  {l1d_rf.imm_bsi_switch_cfg = state;}
#define IMM_OFFCHIP_BSI_SWITCH_QUERY()       (l1d_rf.imm_bsi_switch_cfg)
#else
#define IMM_OFFCHIP_BSI_SWITCH_SET( state )  {;}
#define IMM_OFFCHIP_BSI_SWITCH_QUERY()       (BSI_SWITCH_2G_THEN_TD)
#endif

/*===============================================================================*/
/*    BSI codeword marco                                                         */
/*===============================================================================*/
#if IS_CHIP_MT6256 || IS_CHIP_MT6251 || IS_CHIP_MT6255 || IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define BSI_CW( addr, data )     ((unsigned long)((((addr)&0xFF)<<20)|((data)&0xFFFFF))) //CW length: 28bit, addr part: 8bit, data part: 20bit
#endif

#if IS_MIPI_SUPPORT
/* CW length: 22bit, slave addr part: 4bits, r/w cmd part: 3bits, addr part: 5 bits, parity bit part: 1bit, data part: 8bits, parity bit part: 1bit */
#define MIPI_BSI_RDADDR( s_addr, addr )             ((unsigned long)((((s_addr)&0xF)<<8)|(0x3<<5)|(((addr)&0x1F))))
#endif

/*===============================================================================*/
/*    BSI read back                                                              */
/*===============================================================================*/
#define SCTRL_IMOD_RX_MAIN       (0x0103+(2<<4)+(2<<6))    /* 13/4Mhz, long enable negative pulse */
#define SCTRL_IMOD_RX_SEND       (0x000B+(2<<4)+(2<<6))    /* 13/4Mhz,                            */

/*===============================================================================*/
/*    AFC linear compensation mechanism                                          */
/*===============================================================================*/
void             XO_LC_Initialize( void );
void             XO_LC_TuneAFCTable( signed int Ratio_ind );
signed short int XO_LC_CalculateNewDacNBSB( signed int Current_Freq, signed short int Servingstarted );
signed int       XO_LC_InitialPhiFactor( signed short int DacValue );
signed int       XO_LC_GetCurrentPhi_est( void );

/*===============================================================================*/
/* for TX power rollback                                                         */
/*===============================================================================*/

#if IS_GPRS
short L1D_RF_PowerRollback( short power_dbm, int rf_band, unsigned short weight, short mod_type);

#define F2I_Resolution           8     //float to interger resolution
#define GMSK_LB_MAX_POWER        33
#define GMSK_HB_MAX_POWER        30
#define EPSK_LB_MAX_POWER        27
#define EPSK_HB_MAX_POWER        26
#endif
// end :TX power rollback

/*===============================================================================*/
/* for 32K Crystal Removal                                                       */
/*===============================================================================*/
#if IS_32K_CRYSTAL_REMOVAL_SUPPORT
#define DCXO_NONE    0x0
#define DCXO_LPM     0x1
#define DCXO_FPM     0x2

char L1D_RF_Check_32K_XO_Status( void );
void L1D_RF_SetCLoadFreqOffset( int* freq_offset );
void L1D_RF_GetAfcDacFreqOffset( int* freq_offset );
void L1D_RF_GetDFCFreqOffset( int* freq_offset );
void L1D_RF_Set_DCXO_LPM_Divider( unsigned int dcxo_frac );
void L1D_RF_Set_DCXO_FPM_Divider( unsigned int dcxo_frac );
#endif

#if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
#define DLAFC_INV_SLOPE          (512)                                 //Fix AFC Slope for Dual Loop AFC
#define DLAFC_SCALE              (14)
#define DLAFC_DAC_2_PPB_CONST    (((0x1000*10)<<DLAFC_SCALE)/(DLAFC_INV_SLOPE*9))
#define DLAFC_PPB_2_DAC_CONST    (((DLAFC_INV_SLOPE*9)<<DLAFC_SCALE)/(0x1000*10))
#endif

unsigned short L1D_RF_Check_DCXO_LPM( void );
void L1D_RF_Set_DCXO_Power_Mode( char mode );
void L1D_RF_Set_FixAFC_Status( void );

/*===============================================================================*/
/* dynamic Tx freq. error compensation over temperature                          */
/*===============================================================================*/
#if IS_DYNAMIC_TC_GAIN_SUPPORT

#define TC_GAIN_LOW_TEMP            (-20)  /* unit: Celsius degree */
#define TC_GAIN_NORMAL_TEMP         (25)   /* any two value of LOW_TEMP, NORMAL_TEMP, and HIGH_TEMP can not be the same. */
#define TC_GAIN_HIGH_TEMP           (65)   /* it will make tcGainSlope be infinite and make error. */
#define TC_GAIN_SLOPE(x1,x2,y1,y2)  (( ((short)(y2) << 8) - ((short)(y1) << 8) )/((x2) - (x1)))  /* Get slope from (x1,y1) to (x2,y2) */

   #if IS_RF_MT6256RF || IS_RF_MT6255RF
#define TC_GAIN_RES                 5                      /* DFM_VCO_TC_GAIN[4:0] is composed by 5 bits */
#define TC_GAIN_CW_LSB              4                      /* DFM_VCO_TC_GAIN[4:0] is located at CW63[8:4] */
#define TC_GAIN_CW                  BSI_CW(0x3F, 0x8BC86)  /* CW63, from m12196.c RF POR */
   #endif
#define TC_GAIN_MASK                ((0x1<<TC_GAIN_RES)-1)
#define TC_GAIN_CW_MASK             (TC_GAIN_MASK<<TC_GAIN_CW_LSB)  /* DFM_VCO_TC_GAIN[4:0] */

typedef enum
{
   LOW_TEMP_IND,     /* low temperature index    */
   NORMAL_TEMP_IND,  /* normal temperature index */
   HIGH_TEMP_IND,    /* high temperature index   */

   TEMP_SECTION_NUM
} TC_GAIN_TEMP_SECTION;

unsigned long L1D_RF_Get_TC_Gain_CW( void );

#endif      /* IS_DYNAMIC_TC_GAIN_SUPPORT */

/*===============================================================================*/
/* HRD/IBB/OBB detection                                                         */
/*===============================================================================*/
/* Define flags for l1d_rf.blk_flag */
#define  HRD_FOUND                  0x01
#define  IBB_FOUND                  0x02
#define  LB_OBB_FOUND               0x04
#define  HB_OBB_FOUND               0x08

/*===============================================================================*/
/* for BT Co_clock Support                                                       */
/*===============================================================================*/
#if IS_CHIP_MT6223
unsigned short L1D_BT_Co_Clock_EINT_Setting( void );
#endif

#if IS_CHIP_MT6223 || IS_CHIP_MT6225 || IS_CHIP_MT6238
   #ifdef __CUST_NEW__   /*support driving tool*/
extern const char gpio_bt_co_clock_pin;
#define BT_Co_Clock_GPIO_PORT    gpio_bt_co_clock_pin
   #else
#define BT_Co_Clock_GPIO_PORT    0xff      /*user must define this value for BT co-clock solution*/
   #endif

#define SET_GPIO_MODE            0

   #if IS_CHIP_MT6225
#define SET_EINT_MODE            3 ///for MT6225
   #elif IS_CHIP_MT6238
#define SET_EINT_MODE            1 ///for MT6235/38/39
   #else
#define SET_EINT_MODE            L1D_BT_Co_Clock_EINT_Setting()
   #endif
#endif

/*===============================================================================*/
/* BFE registers transformation for META tool                                    */
/*===============================================================================*/
#if IS_BBTXRX_CHIP_DESIGN_VER_2 || IS_BBTXRX_CHIP_DESIGN_VER_3
signed char DC_OFFSET_TO_OFFSET( signed char off, signed char coarse );
signed char OFFSET_TO_DC_OFFSET( signed char off );
signed char OFFSET_TO_DC_COARSE( signed char off );
signed char TRIM_IQ_TO_GAIN_COMP( signed char trimi, signed char trimq );
signed char TRIM_IQ_TO_GAIN_SEL( signed char trimi, signed char trimq );
signed char GAIN_COMP_TO_TRIMI( signed char iqgain_sel, signed char gain_comp );
signed char GAIN_COMP_TO_TRIMQ( signed char iqgain_sel, signed char gain_comp );
signed char PHASE_COMP_TO_PHSEL_I( signed char phase_sel );
signed char PHASE_COMP_TO_PHSEL_Q( signed char phase_sel );
signed char PHSEL_IQ_TO_PHASE_COMP( signed char phseli, signed char phselq );

void L1D_BFE_SET_TX_CON( int idx, void *_set );
#endif
/*===============================================================================*/

/*===============================================================================*/
/* for PMU Control                                                               */
/*===============================================================================*/
void L1D_PMU_VRF18Setting( char vrf18on );
void L1D_PMU_VRF28Setting( char vrf28on );
void L1D_PMU_VRF18ModeSetting( char onSel );
void L1D_PMU_VRF28ModeSetting( char onSel );
void L1D_PMU_VRF18HWModeSelect( void );
void L1D_PMU_VRF28HWModeSelect( void );
void L1D_PMIC_ADPT2_PWM_ENABLE( char pwm_ena );
void L1D_PMU_LPModeSetting( char modeSel );
void L1D_PMU_LPSetting( char lpSel );
unsigned long L1D_PMU_AUXADCRead( void );
/*===============================================================================*/

void L1D_ABB_Set_ADCMUX_DLPad( void );
void L1D_ABB_Set_BBRX_CON( void );
unsigned char L1D_Check_BPI_Data( void );

/*===============================================================================*/
/* for Othello H & Othello T                                                     */
/*===============================================================================*/
#define RX_LNA_0              0
#define RX_TEST_DISABLE       1
#define PLL_TYPE2_SWITCH      2
#define PLL_TYPE1_SWITCH      3
#define TX_CAL_EN             4
#define TX_CAL_DIS            5

#define RF_TXIQMM_OH          1
#define RF_TXIQMM_OT          2

#if IS_RF_MT6162 || IS_RF_MT6163
#define RF_MT6162_ID_REV0_0A  0x01
#define RF_MT6162_ID_REV0_0B  0x02
#define RF_MT6162_ID_REV0_1A  0xFE
#define RF_MT6162_ID_REV0_1B  0xFD
#define RF_MT6162_ID_REV1_0   0x03
   #if IS_RF_RX_DCOC_WITH_PRECISION_IMPROVEMENT
#define ALPHA_FILTER_COEFF    3
#define ALPHA_FILTER_SCALE    3   /* ALPHA_FILTER_SCALE should not smaller than 1 */
   #else
#define ALPHA_FILTER_COEFF    1
#define ALPHA_FILTER_SCALE    0
   #endif /* IS_RF_RX_DCOC_WITH_PRECISION_IMPROVEMENT */
#endif

#if IS_BBTXRX_CHIP_DESIGN_VER_2 || IS_BBTXRX_CHIP_DESIGN_VER_3
void  L1D_RF_Calibration_Start( void );
void  L1D_RF_IMM_SEND_BSI( char type );
void  L1D_RF_GetData( unsigned long data, unsigned char idx );
void  L1D_RF_Get_RXDCOffset( FrequencyBand band, signed short idx );
void  L1D_RF_Update_DCoffset( unsigned char slot, FrequencyBand band, unsigned long gain_setting );
void  L1D_RF_RXDCOC_Start( void );
void  L1D_RF_RXDCOC_End( void );
char  L1D_RF_RXDCOC_Check( void );
int   L1D_RF_SetRXDelayInTXIQMM( int tq_cnt );
int   L1D_RF_SetTXDelayInTXIQMM( int tq_cnt );
void  L1D_RF_TXIQMM_Start( char tx_cal );
void  L1D_RF_TXIQMM_End( void );
char  L1D_RF_TXIQMM_Check( void );
void  L1D_RF_Get_TXIQMM_Results_DCBB( short dc_i_1, short dc_i_2, short dc_q_1, short dc_q_2 );
void  L1D_RF_Get_TXIQMM_Results( short g, short phi, short dc_i, short dc_q, unsigned char idx );
signed short L1D_RF_TXIQMM_Query_IQ_Setup( char query_idx, signed short band, signed short gain_rf );
void  L1D_RF_Set_BULON( void );
void  L1D_RF_Recover_BULON( void );
   #if IS_BBTXRX_CHIP_DESIGN_VER_3
void  L1D_RF_TXIQMM_PowerIndex( unsigned char pwr_idx );
   #endif
#endif

#if IS_DLIF_CHIP || IS_DCR_IN_DLIF_CHIP
unsigned short L1D_Set_TXCON0( unsigned short tx_con0 );
#endif

#if IS_RF_MT6162 || IS_RF_MT6163
char  L1D_RF_Get6162Version( void );
char  L1D_RF_CheckDMPower( void );
unsigned long L1D_RF_GetClockControl( void );
unsigned long L1D_RF_SetTxGainWrite( unsigned short mod_type, char slot_idx, signed short tx_power, FrequencyBand rf_band );
void  L1D_RF_BASEBAND_FILTER_CAL( void );
void  L1D_RF_TX_GAINSTEP_CAL( void );
   #if IS_RF_RX_DCOC_SUPPORT
void  L1D_RF_RXDCOffset_Init( void );
   #endif /* IS_RF_RX_DCOC_SUPPORT */
   #if IS_RF_TX_CALIBRATION_SUPPORT
void  L1D_RF_TXIQMM_Init( void );
void  L1D_RF_SetEPSKTxIQ( signed short slot_idx, unsigned long tx_gain_write );
   #endif /* IS_RF_TX_CALIBRATION_SUPPORT */
#endif /* IS_RF_MT6162 || IS_RF_MT6163 */

#if IS_RF_MT6280RF
char  L1D_RF_CheckDMPower( void );
void  L1D_RF_RxDCOC_Init( void );
void  L1D_RF_Gainrf_Init( void );
void  L1D_RF_RCAL_Cal( void );
void  L1D_RF_RXRC_DCO_Cal( void );
void  L1D_RF_TX_GainStep_Cal( void );
void  L1D_RF_ADC_LoopFilter_Coef_Cal( void );
void  L1D_RF_TxGainSetting( unsigned short mod_type, char slot_idx, signed short tx_power, FrequencyBand rf_band, unsigned long *cw41, unsigned long *cw42 );
unsigned long L1D_RF_GetGainBB0CW( signed long gainbb0 );
void  SPECIAL_IMM_RECEIVE_BSI( unsigned short ADD_Ctrl, unsigned long ADD, unsigned short DATA_Ctrl, unsigned long *DATA );
#endif /* IS_RF_MT6280RF */

#if IS_RF_MT6169
   #if IS_RF_CENTRAL_CONTROL_ENABLE
void  L1D_RF_RCAL_Cal( RFC_DATABASE_T* pRfcDataBase );
void  L1D_RF_TX_GainStep_Cal( RFC_DATABASE_T* pRfcDataBase );
void  L1D_RF_TX_DET_DCOC_Cal( RFC_DATABASE_T* pRfcDataBase );
void  L1D_RF_TX_RCF_Cal( RFC_DATABASE_T* pRfcDataBase );
void  L1D_MMRF_SetPowerOnCalibrationData( RFC_DATABASE_T* pRfcDataBase );
   #else
void  L1D_RF_RCAL_Cal( void );
void  L1D_RF_TX_GainStep_Cal( void );
void  L1D_RF_TX_DET_DCOC_Cal( void );
void  L1D_RF_TX_RCF_Cal( void );
   #endif
char  L1D_RF_CheckDMPower( void );
void  L1D_RF_SetClockControl(void);
void  L1D_RF_Gainrf_Init( void );
void  L1D_RF_TxGainSetting( unsigned short mod_type, char slot_idx, signed short tx_power, FrequencyBand rf_band, unsigned long *cw74, unsigned long *cw75 );
void  SPECIAL_IMM_RECEIVE_BSI( unsigned short ADD_Ctrl, unsigned long ADD, unsigned short DATA_Ctrl, unsigned long *DATA );
unsigned long L1D_RF_GetGainBB0CW( signed long gainbb0 );
#endif /* IS_RF_MT6169 */

#if IS_RF_MT6166
char  L1D_RF_CheckDMPower( void );
void  L1D_RF_Gainrf_Init( void );
void  L1D_RF_TX_GainStep_Cal( void );
void  L1D_RF_TxGainSetting( unsigned short mod_type, char slot_idx, signed short tx_power, FrequencyBand rf_band, unsigned long *cw41, unsigned long *cw42 );
unsigned long L1D_RF_GetGainBB0CW( signed long gainbb0 );
void L1D_RF_RXRC_Cal(void);
void L1D_RF_SetClockControl(void);
unsigned long L1D_RF_GetRXRCKResult( void );
void  SPECIAL_IMM_RECEIVE_BSI( uintBSI ADD_Ctrl, unsigned long ADD, uintBSI DATA_Ctrl, unsigned long *DATA );
void  L1D_RF_Power_On_Sequence( void );
void  L1D_MMRF_SetPowerOnCalibrationData( RFC_DATABASE_T* pRfcDataBase );
#endif /* IS_RF_MT6166*/

#if IS_RF_MT6165
char  L1D_RF_CheckDMPower( void );
   #if IS_TX_GAIN_RF_CALIBRATION_SUPPORT
void  L1D_RF_Gainrfcal_Info_init(void);
   #else
void  L1D_RF_Gainrf_Init( void );
   #endif
void  L1D_RF_TxGainSetting( unsigned short mod_type, char slot_idx, signed short tx_power, FrequencyBand rf_band, unsigned long *cw130, unsigned long *cw131 );
unsigned long L1D_RF_GetGainBB0CW( signed long gainbb0 );
void L1D_RF_SetClockControl(void);
void  L1D_RF_Power_On_Sequence( void );
void  SPECIAL_IMM_RECEIVE_BSI( uintBSI ADD_Ctrl, unsigned long ADD, uintBSI DATA_Ctrl, unsigned long *DATA );
   #if IS_RF_CENTRAL_CONTROL_SUPPORT
void  L1D_MMRF_SetPowerOnCalibrationData( RFC_DATABASE_T* pRfcDataBase );
   #endif
#endif

/*===============================================================================*/
/* Configure the version of TX PCL calibration                                   */
/*===============================================================================*/
#if IS_RF_MT6280RF || IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165
#define  TX_PCL_CAL_GMSK_VER     0
#define  TX_PCL_CAL_EPSK_VER     1
#else
#define  TX_PCL_CAL_GMSK_VER     0
#define  TX_PCL_CAL_EPSK_VER     0
#endif

#define  TX_PCL_CAL_VER          ((TX_PCL_CAL_EPSK_VER<<7)|(TX_PCL_CAL_GMSK_VER<<0))
int L1D_GetTxPclCalVer( void );

void L1D_RF_GetAFCData( void *data_buffer );

/*===============================================================================*/
/* For MT6573 & MT6575 AFC Switch GPIO Setting                                   */
/*===============================================================================*/
#if IS_TDD_DUAL_MODE_SUPPORT
    #if IS_CHIP_MT6575 || IS_CHIP_MT6280
void L1D_TD_AFC_Mode_GPIO_Set( void );
void L1D_TD_AFC_Mode_GPIO_Reset( void );
    #endif
#endif

/*===============================================================================*/
/* MPLL frequency hopping free run switch                                        */
/*===============================================================================*/
extern int L1D_FH_Is_MPLL_Free_Run_On( void );

#if IS_RESEND_AFC_DATA_REQUIRED
void  L1D_DCXO_WAKEUP_RESEND( void );
#endif
unsigned char L1D_RF_IS_MT6162_DCXO( void );
unsigned char L1D_PMU_IS_FIX_VRF1828SETTING( void );

/*===============================================================================*/
/* For MT6575 & AST3001 RF power-on/off check                                    */
/*===============================================================================*/
#if IS_TDD_DM_RF_POWER_CHECK_SUPPORT
#define TDD_DM_RF_POWER_CHECK_VER_1          1  /* Check via GPIO */
#define TDD_DM_RF_POWER_CHECK_VER_2          2  /* Check via BSI mailbox register on AST3001 */
#define TDD_DM_RF_POWER_CHECK_VER_3          3  /* Check via BSI mailbox register on AST3002 */

   #if defined(__AST3001__) && defined(__AST_E1__)
#define TDD_DM_RF_POWER_CHECK_VER            TDD_DM_RF_POWER_CHECK_VER_1
   #elif defined(__AST3001__) && defined(__AST_E2__)
#define TDD_DM_RF_POWER_CHECK_VER            TDD_DM_RF_POWER_CHECK_VER_2
   #elif IS_AST3002_SUPPORT
#define TDD_DM_RF_POWER_CHECK_VER            TDD_DM_RF_POWER_CHECK_VER_3
   #endif

#define IS_TDD_DM_RF_POWER_CHECK_V1_SUPPORT  (TDD_DM_RF_POWER_CHECK_VER == TDD_DM_RF_POWER_CHECK_VER_1)
#define IS_TDD_DM_RF_POWER_CHECK_V2_SUPPORT  (TDD_DM_RF_POWER_CHECK_VER == TDD_DM_RF_POWER_CHECK_VER_2)
#define IS_TDD_DM_RF_POWER_CHECK_V3_SUPPORT  (TDD_DM_RF_POWER_CHECK_VER == TDD_DM_RF_POWER_CHECK_VER_3)

   #if IS_TDD_DM_RF_POWER_CHECK_V1_SUPPORT
      #if IS_CHIP_MT6575
#define TDD_DM_RF_POWER_CHECK_WAIT           44 /* Wait 40us */
      #endif
   #elif IS_TDD_DM_RF_POWER_CHECK_V2_SUPPORT
      #if IS_CHIP_MT6575 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6280
#define TDD_DM_RF_POWER_CHECK_WAIT           44 /* To be verified */
      #endif
   #elif IS_TDD_DM_RF_POWER_CHECK_V3_SUPPORT
#define TDD_DM_RF_POWER_CHECK_WAIT           44 /* To be verified */
   #endif

   #if IS_TDD_DM_RF_POWER_CHECK_V2_SUPPORT
/* AST3001E2 BSI mailbox register for 2G/TD RF status indication.
   TD sets HW reg M_BPI_STATUS_CFG (HIF_BASE+0x98) to 0xF2F1 during HIF init, which means:
   (1) 2G stores 2G RF status to virtual CW 0xF1 bit[19]
   (2) 2G reads TD RF status from virtual CW 0xF2 bit[18] */
#define SDATA_MAILBOX_2GRF_STATUS_ON         0x0F180000  /* bit[19]: 2G RF status on */
#define SDATA_MAILBOX_2GRF_STATUS_OFF        0x0F100000  /* bit[19]: 2G RF status off */
#define CW_MAILBOX_TDRF_STATUS               0x0F2
#define MAILBOX_TDRF_STATUS_BIT              18
   #endif

void  L1D_RF_Init_TDD_Power_Check_GPIO( void );
void  L1D_RF_Set_2G_Power_Status( unsigned short set_2g_status );
char  L1D_RF_Check_TDD_Power( char is_at_power_on );
#endif

#if IS_TDD_DM_RF_POWER_CHECK_V3_SUPPORT
/*===============================================================================*/
/* For MT6572 & AST3002 RF power-on/off check                                    */
/*===============================================================================*/
extern unsigned short  rf_ctrl_2g_get_3g_status( void );                     /* TDD sleep: 0x0000, TDD awake: 0xaaaa */
extern void            rf_ctrl_2g_put_status_to_3g( unsigned short value );  /* 2G sleep : 0x0000, 2G awake : 0x5555 */
#endif

#if IS_TDD_DM_RF_POWER_CHECK_SUPPORT
#define L1D_RF_SET_2G_POWER_STATUS( status ) L1D_RF_Set_2G_Power_Status( status )
#define L1D_RF_CHECK_TDD_POWER( is_pwr_on )  L1D_RF_Check_TDD_Power( is_pwr_on )
#else
#define L1D_RF_SET_2G_POWER_STATUS( status ) {;}
#define L1D_RF_CHECK_TDD_POWER( is_pwr_on )  (0)
#endif

/*===============================================================================*/
/* For RF TX Max Power Decrement                                                 */
/*===============================================================================*/
#if IS_DECREASE_RF_TX_MAX_POWER_SUPPORT
#define IS_RF_TX_MAX_POWER_DECREASED()       (l1d_rf.is_tx_decrease_power_needed==1)
typedef struct
{
   unsigned char power_decrement[4][2][4];
} sTX_POWER_DECREMENT_TABLE;
extern sTX_POWER_DECREMENT_TABLE Tx_Power_Decrement_Table;
extern sTX_POWER_DECREMENT_TABLE Tx_Fine_Tune_Table;
#else
#define IS_RF_TX_MAX_POWER_DECREASED()       (0)
#endif

/*===============================================================================*/
/* For WiFi adaptive power control                                               */
/*===============================================================================*/
#if IS_WIFI_ADAPTIVE_POWER_CONTROL_SUPPORT
#define DEGRADE_PWR_THRES_ORI                -100
#define DEGRADE_PWR_THRES_HYS                -97
short L1D_GET_RX_PWR_THRES_ORI( void );
short L1D_GET_RX_PWR_THRES_HYS( void );
#endif

/*===============================================================================*/
/* For AP Query L1 Report RF Temperature                                         */
/*===============================================================================*/
void L1D_RF_Report_Temperature_HISR( kal_uint32 ap_param );
kal_int16 L1D_RF_Report_Temperature( void );

/*===============================================================================*/
/* For AP Send Voltage Information to L1                                         */
/*===============================================================================*/
void L1D_RF_Update_VoltageInfo_HISR( kal_uint32 ap_param );

/*===============================================================================*/
/* For AP Send Tx power offset Information to L1                                         */
/*===============================================================================*/
void L1D_RF_Update_TxPowerOffsetInfo_HISR( kal_uint32 ap_param );

signed long L1D_RF_UpdateVoltInfoPeriod( void );

#if IS_TX_VOLTAGE_COMPENSATION_SUPPORT
   #ifndef AP_UPDATE_VOLTINFO_PERIOD
#define MINUTES2FRAME(n)                     ((int)((n)*13000))
#define AP_UPDATE_VOLTINFO_PERIOD            MINUTES2FRAME(5)
   #endif
#endif

#ifdef L1_SIM
#define IS_BSI_IMM_SEND_COMPLETE             (0x1)
#else
   #if IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define IS_BSI_IMM_SEND_COMPLETE             (HW_READ(BSI_IMM_WD_RDY)&0x1)
   #else
#define IS_BSI_IMM_SEND_COMPLETE             (0x1)
   #endif
#endif

extern unsigned short L1D_Get_PSI_EE( void );
extern unsigned short L1D_Get_C_PSI_STA( void );

/*===============================================================================*/
#if IS_RF_MT6280RF
extern signed   short chip_ver;
#endif

#if IS_RF_MT6169
extern unsigned long MT6169_2G_CHIP_VER;
#define        MT6169_E1          0x1
#define        MT6169_ECO         0x2
#define        MT6169_E3          0x3
#endif
/*===============================================================================*/

unsigned char L1D_Check_SW_SecVersion( void );
void L1D_RF_SetBSISPI_Control();

/*===============================================================================*/
/* Switch IF Threshold Setting                                                   */
/*===============================================================================*/
#if IS_OBB_DETECTION_SUPPORT
#define  OBB_POWER_THR                  (-840)  //-105*PWRRES
#define  OBB_C_VALUE_THR1                 128   //16*8
   #if IS_CHIP_MT6251 || IS_CHIP_MT6255
#define  OBB_C_VALUE_THR2                 128   //16*8
   #else
#define  OBB_C_VALUE_THR2                 640   //80*8
   #endif
#define  OBB_C_RATIO_THR1                  16   //THR4
#define  OBB_W_THR                      16384   //2048*8
#define  OBB_C_RATIO_THR2                   2   //THR6
#endif
/*===============================================================================*/

/*===============================================================================*/
/* For RF One-bin Support Feature                                                */
/*===============================================================================*/
#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2
   #if L1D_CUSTOM_DYNAMIC_SUPPORT
      #if IS_L1_RF_DRDI_CUSTOM_SETTING_FROM_MML1
#define  L1D_CUSTOM_FIRST_INDEX_BASE                         1
      #else
#define  L1D_CUSTOM_GPIO_MAX_NUM_OF_DEFINED_DETECT_PIN_NAME  3
#define  L1D_CUSTOM_GPIO_PIN_NAME_STRING_LENGTH             34 /* the length of GPIO_FDD_Band_Support_Detection_x */
#define  L1D_CUSTOM_ADC_CH_NAME_STRING_LENGTH               33 /* the length of ADC_FDD_Rf_Params_Dynamic_Custom  */
#define  L1D_CUSTOM_NULL_ACTION                              0
#define  L1D_CUSTOM_GPIO_DETECTION_ID                        1
#define  L1D_CUSTOM_ADC_DETECTION_ID                         2
#define  L1D_CUSTOM_BARCODE_DETECTION_ID                     3
#define  L1D_CUSTOM_FIRST_INDEX_BASE                         1

/* ADC */
#define  EFUSE_SPARE_0                 ((APBADDR32)(EFUSE_base        + 0x0040))
#define  EFUSE_SPARE_1                 ((APBADDR32)(EFUSE_base        + 0x0044))
#define  EFUSE_SPARE_2                 ((APBADDR32)(EFUSE_base        + 0x0048))
#define  AP_MIXED_ABB_TST_CON1         ((APBADDR)  (AP_MIXED_ABB_base + 0x0804))
#define  AP_MIXED_ABB_TST_CON2         ((APBADDR)  (AP_MIXED_ABB_base + 0x0808))
/* the following definitions  should be the same as which defined in Wcustom.h with the prefix of EFUSE_xxx */
#define  GGE_EFUSE_SPARE0_O_VBG_SHIFT  8
#define  GGE_EFUSE_SPARE0_O_VBG_MASK   (0xFF << GGE_EFUSE_SPARE0_O_VBG_SHIFT)
#define  GGE_EFUSE_SPARE1_ADC_OE_MASK  0xFF
#define  GGE_EFUSE_SPARE2_ADC_GE_MASK  0xFF
#define  GGE_EFUSE_ADC_GE_DEFAULT      128
#define  GGE_EFUSE_ADC_OE_DEFAULT      128
#define  GGE_EFUSE_O_VBG_DEFAULT       167
#define  GGE_EFUSE_Y_VBG_DEFAULT       1967
#define  GGE_EFUSE_ADC_CALI_CH_NUM     5
#define  GGE_EFUSE_ADC_CALI_MEAS_CNT   100

typedef enum
{
   L1D_CUSTOM_NULL_ACTION_ID      = L1D_CUSTOM_NULL_ACTION,
   L1D_CUSTOM_BASE_PROC_ACTION_ID = L1D_CUSTOM_NULL_ACTION_ID,
   L1D_CUSTOM_GPIO_DETECTION      = L1D_CUSTOM_GPIO_DETECTION_ID,
   L1D_CUSTOM_ADC_DETECTION       = L1D_CUSTOM_ADC_DETECTION_ID,
   L1D_CUSTOM_BARCODE_DETECTION   = L1D_CUSTOM_BARCODE_DETECTION_ID,
   L1D_CUSTOM_MAX_PROC_ACTIONS
} sL1CustomActionId;

typedef struct
{
   /* Null-terminated string to record the GPIO
    * pin name for detection HW settings */
   char gpioPinNameString[L1D_CUSTOM_GPIO_PIN_NAME_STRING_LENGTH];

   /* Record the detected GPIO detection pin number */
   unsigned long  gpioPinNum;

   /* Record the GPIO detection pin value of the corresponding
    * GPIO pin number (mapped by GPIO pin name) */
   unsigned long  gpioReadPinValue;
} sL1CustomGpioGetPinValueInfo;

unsigned char L1D_CustomGpioGetConfigSettingIdx( void );
unsigned char L1D_CustomAdcGetConfigSettingIdx( void );
unsigned char L1D_CustomBarcodeGetConfigSettingIdx( void );
      #if IS_CHIP_MT6280
/* MT6280 Does not support selection by ADC */
      #else
signed   long L1D_CUSTOM_AdcDacToVoltage( unsigned long adcDigitalValue );
unsigned long L1D_CUSTOM_AuxAdcCalibrate( unsigned long adcDigitalValue );
void L1D_CUSTOM_ReplaceAuxAdcCalibrate( unsigned long adcDigitalValue, signed long *volt );
      #endif
void L1D_CustomDynamicInitByGPIO( void *data );
void L1D_CustomDynamicInitByADC( void *data );
void L1D_CustomDynamicInitByBarcode( void *data );
void L1D_CustomDynamicInitConfigIdxCalc( unsigned char result_idx, unsigned char index_base_no );
void L1D_CustomDynamicInitConfigIdxBaseCalc( void );
void L1D_CustomDynamicSetRfParams( unsigned short index );
void L1D_CustomDynamicSetRxData( unsigned short index );
void L1D_CustomDynamicSetPData( unsigned short index );

extern signed long IPC_RPC_GPIO_GetPin( unsigned char *GPIOName, unsigned long GPIONameLength, unsigned long *GPIOPin );
extern signed long IPC_RPC_ADC_GetChannelNumber( unsigned char *ChannelName, unsigned long ChannelNameLength, unsigned long *ChannelNumber );
      #if IS_CHIP_MT6572
extern signed long IPC_RPC_GPIO_GetValue( unsigned long GPIONumber, unsigned long *GPIOValue );
extern signed long IPC_RPC_ADC_GetValue( unsigned long ADCNumber, unsigned long *ADCValue );
      #endif
   #endif
   #endif
void L1D_CustomDynamicInit( void );
void L1D_CustomDynamicDebugStoreToNVRAM( void );
void L1D_CustomDynamicDebug( void );
void L1D_CustomDrdiStatusUpdatetoNVRAM(unsigned short index);

#endif

      /* For BPI/LNA                          */
unsigned char L1D_Get_BandCapability( void );

#define  L1D_CUSTOM_MAX_RF_BPI_EVENT_NUM  8

typedef struct
{
   /* RX LNA ports */
   unsigned long lnaPort;

   /* ASM logics */
   /* PR1, PR2, PR2B, PR2M1, PR2M2, PR2M3, PR3, PR3A */
#if IS_BPI_DATA_32_BIT_CHIP
   signed long  asmLogics[L1D_CUSTOM_MAX_RF_BPI_EVENT_NUM];
#else
   signed short asmLogics[L1D_CUSTOM_MAX_RF_BPI_EVENT_NUM];
#endif
} sL1CustomDynamicInitRxData;

#define  L1D_CUSTOM_MAX_RF_TX_BPI_EVENT_NUM  11

typedef struct
{
   /* TX ports */
   unsigned long txPort;

#if IS_BPI_DATA_32_BIT_CHIP
   /* ASM logics */
   /* PT1, PT2, PT2B, PT2M1_G8,PT2M2_G8,PT2M3_G8,PT2M1_8G,PT2M2_8G,PT2M3_8G, PT3, PT3A */
   signed long  asmpaLogics[L1D_CUSTOM_MAX_RF_TX_BPI_EVENT_NUM];
#else
   /* ASM logics */
   /* PT1, PT2, PT2B, PT2M1_G8,PT2M2_G8,PT2M3_G8,PT2M1_8G,PT2M2_8G,PT2M3_8G, PT3, PT3A */
   signed short asmpaLogics[L1D_CUSTOM_MAX_RF_TX_BPI_EVENT_NUM];

#endif
} sL1CustomDynamicInitTxData;

typedef struct
{
#if IS_BPI_DATA_32_BIT_CHIP
   signed long pdata_gmsk;
   signed long pdata_8psk;
   signed long pdata_init;
   signed long pdata_idle;
   sL1CustomDynamicInitTxData pdata_txdata[4];
#else
   signed short pdata_gmsk;
   signed short pdata_8psk;
   signed short pdata_init;
   signed short pdata_idle;
   sL1CustomDynamicInitTxData pdata_txdata[4];
#endif
} sL1CustomDynamicInitPData;


/*===============================================================================*/

/*===============================================================================*/
/* for the DCS-TD co-existence support                                           */
/*===============================================================================*/
#if IS_DCS_NB_WB_SWITCH_SUPPORT
/* the frequency range of DCS narrow band is 1805~1830MHz, and the ARFCN is from 512 to 636 */
#define  DCS_NB_ARFCN                     636
void L1D_RF_Init_DCS_NB_WB_Switch( void );
char L1D_RF_IS_DCS_NB_WB_Switch( void );
char L1D_RF_IS_DCS_Change_to_NB( void );
#endif

#if IS_DSDA_DCS_TX_NOTCH_SWITCH_SUPPORT
char L1D_RF_IS_TDD_GSM_TX_Overlap( void );
void L1D_RF_Init_TX_Notch_Switch( void );
char L1D_RF_Get_Flag( void );
char L1D_RF_IS_DCS_Change_to_TX_Notch( void );
extern kal_bool tl1_m_l_is_freq_b34_b39(void);
#endif

#if IS_DSDA_PROVIDE_RX_STATUS_TO_LTE_SUPPORT
char L1D_RF_Provide_Rx_Statue_To_LTE_Enable( void );
#endif
/*===============================================================================*/
/* TX Gain RF Calibration                                                        */
/*===============================================================================*/
#if IS_TX_GAIN_RF_CALIBRATION_SUPPORT
void L1D_RF_SetGainRF( l1cal_gainrf_T *gain );
void L1D_RF_GetGainRF( l1cal_gainrf_T *buff );

typedef struct
{
   unsigned short pa_Gain;
   unsigned short pa_Vbias;
   unsigned short gain_rf_index;
   char           gain_rf_cal_state;  /* 1: cal gain rf; 0: normal flow */
   signed   short baseband_power[TX_GAIN_STEP_NUM];   
} sTX_GAINRF_CAL;
#endif

/*===============================================================================*/
/* For tx power offset support                                                                                                         */
/*===============================================================================*/
#if IS_TX_POWER_OFFSET_SUPPORT
short L1D_RF_Tx_Power_Offset( int rf_band, int arfcn, short power_dbm, short mod_type );
#endif

/*===============================================================================*/
/* Output the RF version                                                         */
/*===============================================================================*/
#if IS_OUTPUT_RF_VERSION_SUPPORT
unsigned long L1D_RF_Get_Version( void );
#endif

/*===============================================================================*/
/* L1D Init Abnormal Status Check                                                */
/*===============================================================================*/
#define  INIT_BSISPI_ABNORMAL       0x00000001

/*===============================================================================*/
/* L1D TAS feature                                               */
/*===============================================================================*/
#if IS_2G_TAS_SUPPORT
//For the Transmint Antenna Selection feature
#define L1D_TAS_BPI_PIN_GEN(var1, var2, var3) ( (L1D_TAS_PIN1==L1D_TAS_PIN_NULL?0:(var1<<L1D_TAS_PIN1)) | \
                                                (L1D_TAS_PIN2==L1D_TAS_PIN_NULL?0:(var2<<L1D_TAS_PIN2)) | \
                                                (L1D_TAS_PIN3==L1D_TAS_PIN_NULL?0:(var3<<L1D_TAS_PIN3)) )


extern void L1D_UpdateTASParameters( sL1_TAS_CUSTOM_PARAMS* custom_param, sL1_TAS_LIB_PARAMS* lib_param );
uint16 L1D_RF_TAS_NVRAM_LID_QUERY(void);
#endif
#endif

