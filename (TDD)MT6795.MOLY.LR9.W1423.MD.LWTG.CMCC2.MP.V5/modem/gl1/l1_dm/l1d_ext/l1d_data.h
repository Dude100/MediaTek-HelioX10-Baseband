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
 *   l1d_data.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Definition of global data & tables used in L1D
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.52  $
 * $Modtime:   Aug 02 2005 13:54:30  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1/l1d/l1d_data.h-arc  $
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * Rollback //MOLY/BRANCHES_LR9/LR9.W1423.MD.LWTG.MP/mcu/interface/modem/l1/gsm/external/l1cal.h to revision 1
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
 * 04 09 2013 ola.lee
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
 * 08 23 2012 cs.wu
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
 * 06 13 2012 ola.lee
 * removed!
 * .
 *
 * 05 28 2012 cs.wu
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
 * 10 21 2011 th.yeh
 * removed!
 * .
 *
 * 09 22 2011 th.yeh
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * 08 05 2011 cs.wu
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
 * 05 05 2011 cs.wu
 * removed!
 * .
 *
 * 04 28 2011 cs.wu
 * removed!
 * .
 *
 * 04 21 2011 cs.wu
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
 * 11 21 2010 cs.wu
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
 * VAFC always  on
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
 * For MT6238~, WB/NB differences is never used. Fix the compile option.
 *
 * removed!
 * removed!
 * Remove the WB/NB differences for the MT6223
 *
 * removed!
 * removed!
 * Add two functions and one table
 * intx L1D_Cal_PM_Count_DM( intx ebit_duration );
 * intx L1D_Cal_FB_Slot_Length_DM(intx ebit_duration);
 * SHORT_PM_END_POINT_TABLE[]
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
 * Add Dual mode correlated codes
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
 * Modify the CTIRQ1/CTIRQ2 timing for the MT6223 GSM only platform
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
 * New 8PM mechanism
 *
 * removed!
 * removed!
 * Restore original AFC DAC setting of VCTCXO
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
 * For BT/WiFi to co-use 26MHz, keep AFC to always power on
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
 * Modify AFC length in idle and dedicated mode to 13 slots
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
 *    Rev 1.52   Aug 02 2005 13:56:02   mtk00361
 * 1.Change the type of USE_3_SUBSTAGES_FB_STAGE1 from bool to unsigned char
 * 2.Add prototype in l1d_data.h
 * Resolution for 12100: [L1D][Modify]Disable 3-substages FB stage 1 for X'tal from chip MT6229 and latter version
 *
 *    Rev 1.51   May 23 2005 18:10:54   mtk00240
 *  Let VCXO compile option independent with L1D internal code (Macro TQ_AFC_CHARGE_IN_IDLE --> global variable  TQ_Afc_ChargeInIdle
 * Resolution for 11194: [L1D][Enhance] Let VCXO compile option independent with L1D internal code
 *
 *    Rev 1.50   May 17 2005 00:34:18   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.49   May 16 2005 11:46:22   mtk00240
 * Support 22 BPI setting & current sense PA
 * Resolution for 11091: [L1D][New Feature] Support 22 BPI setting & current sense PA
 *
 *    Rev 1.48   Feb 14 2005 20:48:46   mtk00939
 * [L1][update] fix RVCT compile warning
 * Resolution for 9821: [L1][update] fix RVCT compile warning
 *
 *    Rev 1.47   Jan 18 2005 00:37:56   BM
 * append new line in W05.04
 *
 *    Rev 1.46   Dec 27 2004 11:42:00   mtk00939
 * Due to L1D extracted the tables and variables for L1D internal used from l1d_data.c and l1d_data.h into l1d_internal_data.c & l1d_internal_data.h
 * Resolution for 9276: [L1D][modify]Due to L1D extracted the tables and variables for L1D internal used from l1d_data.c and l1d_data.h into l1d_internal_data.c & l1d_internal_data.h
 *
 *    Rev 1.45   Jun 10 2004 14:48:02   mtk00240
 * Support phone used mt6129C/D with VCXO
 * Resolution for 6006: [L1D][Enhance] Support phone used mt6129C/D with VCXO
 *
 *    Rev 1.44   May 31 2004 11:52:12   mtk00585
 * [L1D][Modify] Add TX Swing Auto Calibration.
 * Resolution for 5743: [L1D][Modify] Add TX Swing Auto Calibration.
 *
 *    Rev 1.43   Mar 12 2004 11:55:20   mtk00489
 * [L1D][Enhanced]L1D add APC voltage/temperature compensation and add BBTXParameter for META
 * Resolution for 4233: [L1D][Enhanced]L1D add APC voltage/temperature compensation and add BBTXParameter for META
 *
 *    Rev 1.42   Feb 13 2004 23:53:10   mtk00489
 * [L1D][Enhanced]1.adjust L1D DL DTX threshold to improve DTX detection rate 2.enhanced Dummy burst detection rate 3.change RX ADC to 2.24V for MT61xx 4.modify LP2 code to pass MT6218BECO3 validation 5.modify new interface for dll(CHIP_VER)
 * Resolution for 3912: [L1D][Enhanced]1.adjust L1D DL DTX threshold to improve DTX detection rate 2.enhanced Dummy burst detection rate 3.change RX ADC to 2.24V for MT61xx 4.modify LP2 code to pass MT6218BECO3 validation 5.modify new interface for dll(CHIP_VER)
 *
 *    Rev 1.41   Jan 12 2004 14:26:14   mtk00489
 * [L1D][Enhanced]L1D modify code to sync with FT load. 1.Delay 400QB of CTIRQ1/2 and DSP_GPRS_DFB_ON for mt6218A/B 2.separate CSD and GPRS's DSP_TCH_BFI_THRESHOLD 3.adjust set-point and gain table for Mt6119C
 * Resolution for 3714: [L1D][Enhanced]L1D modify code to sync with FT load. 1.Delay 400QB of CTIRQ1/2 and DSP_GPRS_DFB_ON for mt6218A/B 2.separate CSD and GPRS's DSP_TCH_BFI_THRESHOLD 3.adjust set-point and gain table for Mt6119C
 *
 *    Rev 1.40   Oct 25 2003 15:45:54   mtk00240
 * Delay 400QB of CTIRQ1/2 for mt6218B
 * Resolution for 3196: [L1D][Enhance] Add code to support mt6218B
 *
 *    Rev 1.39   Aug 08 2003 12:26:22   mtk00489
 * [L1D][Modify]ONLY apply bb_tx_autocal when we get enough samples to evalute it, so L1D apply bb_tx_autocal for 1. All RF except AERO 2.MT6205B_AND_LATTER_VERSION
 * Resolution for 2472: [L1D][Modify]ONLY apply bb_tx_autocal when we get enough samples to evalute it, so L1D apply bb_tx_autocal for 1. All RF except AERO 2.MT6205B_AND_LATTER_VERSION
 *
 *    Rev 1.38   Jun 06 2003 18:42:44   mtk00489
 * [L1D][Enhanced]L1D modify for custom folder/files. from now on, L1D only knows the RF chip name(not board name) 1.add l1d_custom_rf.h(from l1d_rf.h) 2.add 12196.c(from 12190.c) 3.move m12193.c to custom directory 4.modify l1s.lis 5.files include l1d_rf.h should also include l1d_custom_rf.h 6.change l1d_cid.h
 * Resolution for 1961: [L1D][Enhanced]L1D modify for custom folder/files. from now on, L1D only knows the RF chip name(not board name) 1.add l1d_custom_rf.h(from l1d_rf.h) 2.add 12196.c(from 12190.c) 3.move m12193.c to custom directory 4.modify l1s.lis 5.files
 *
 *    Rev 1.37   Mar 24 2003 22:54:18   mtk00240
 * L1D disable BB TX TrimI/Q, OffsetI/Q Calibration by SA's request
 * Resolution for 1356: L1D disable BB TX TrimI/Q, OffsetI/Q Calibration by SA's request
 *
 *    Rev 1.36   Jan 29 2003 18:07:46   mtk00474
 * m12150.c : MCU calulate offset I/Q
 * m12190.c/h : remove L1D_RF_NeedToCalibrate()
 * m12100.c   : resolve the collision between BB TX auto-calibration and META calibration
 * Resolution for 636: for BB TX autocalibration and META calibrtaion
 *
 *    Rev 1.35   23 Jan 2003 16:01:12   mtk00240
 * L1D change setting PCL per TX block to per TX burst
 * Resolution for 633: L1D change setting PCL per TX block to per TX burst
 *
 *    Rev 1.34   23 Jan 2003 08:52:18   mtk00240
 * L1D turn off AFC DAC in sleep mode
 * Resolution for 625: L1D turn off AFC DAC in sleep mode
 *
 *    Rev 1.33   17 Jan 2003 14:47:30   mtk00240
 * L1D add global data FrequcyBias to compensate frequency bias.
 * Resolution for 628: L1D add global data FrequcyBias to compensate frequency bias.
 *
 *    Rev 1.32   08 Jan 2003 12:34:18   mtk00240
 * L1D initial the Ramp profile file when L1D initialize
 * Resolution for 619: L1D initial the Ramp profile file when L1D initialize
 *
 *    Rev 1.31   17 Dec 2002 09:19:28   mtk00240
 * (1) Change RX timing base to 156.25/156.25/156.25/156.25
 * (2) L1D switch APC event 3,4 and 5,6 when TX slot 3,4 are applied
 * Resolution for 592: Change RX timing base to 156.25/156.25/156.25/156.25
 * Resolution for 593: L1D switch APC event 3,4 and 5,6 when TX slot 3,4 are applied
 *
 *    Rev 1.30   10 Dec 2002 10:32:20   mtk00240
 * L1D change the time-base of TX from 157,156,156,156 to 156,157,156,156
 * Resolution for 586: L1D change the time-base of TX from 157,156,156,156 to 156,157,156,156
 *
 *    Rev 1.29   10 Dec 2002 08:12:24   mtk00240
 * modify some code to support MT6218 simulation
 * Resolution for 581: L1D add code to support MT6218
 *
 *    Rev 1.28   05 Dec 2002 10:50:26   mtk00240
 * L1D add code to support MT6218
 * Resolution for 581: L1D add code to support MT6218
 *
 *    Rev 1.27   06 Nov 2002 10:30:42   mtk00240
 * (1) Remove SM clk defintion from l1d_data.h to l1d_rf.h
 * (2) CLK_SETTLE_DEFAULT is 200 except Bright4+MT6206 is 100
 * Resolution for 599: CLK_Settle time setting
 *
 *    Rev 1.26   18 Oct 2002 10:44:32   mtk00240
 * L1D change AFC mode from event drivven to force power on to avoid mt6205 AFC bug when receive SChT
 * Resolution for 532: L1D change AFC mode from event drivven to force power on to avoid mt6205 AFC bug when receive SChT
 *
 *    Rev 1.25   25 Sep 2002 10:19:40   mtk00240
 * L1D Set the current drive capability of BPI bit 0/1/2/3 to 8mA for mt6205
 * Resolution for 497: L1D Set the current drive capability of BPI bit 0/1/2/3 to 8mA for mt6205
 *
 *    Rev 1.24   11 Sep 2002 12:08:00   mtk00240
 * (1) All NB RX window is 156 bit
 * (2) All NB TX window is 148 bit
 * (3) change all slot boundary to 157/156/156/156
 * Resolution for 457: L1D change slot length to 157bit,156bit,156bit,156bit
 *
 *    Rev 1.23   02 Sep 2002 17:10:14   mtk00240
 * Add BSI device CS polarity selection
 * Resolution for 464:  L1D add code to support AERO RF Module
 *
 *    Rev 1.22   29 Jul 2002 17:48:44   mtk00240
 * L1D remove code about initializing AFC data
 * Resolution for 442: L1D remove code about initializing AFC data
 *
 *    Rev 1.21   29 Jul 2002 15:43:16   mtk00240
 * L1D Add code to turn on/off RF power by checking window constellation
 * Resolution for 441: L1D Add code to turn on/off RF power by checking window constellation
 *
 *    Rev 1.20   23 Jul 2002 19:52:02   mtk00240
 * MT6205 active enable flags when writing corresponding events, so L1D disbale setting ENABLE register for MT6205
 * Resolution for 437: L1D modified code for MT6205
 *
 *    Rev 1.19   23 Jul 2002 11:48:40   mtk00240
 * L1D add 2 global variable for sleep mode
 * Resolution for 438: L1D add 2 global variable for sleep mode
 *
 *    Rev 1.18   18 Jul 2002 16:49:10   mtk00240
 * L1D modified code for MT6205
 * (1) change BPI setting (l1d_rf.h)
 * (2) Fix APC Scale factor (m12170.c)
 * (3) disable IDN_SEL and GPIO mode setting (m12190.c)
 * (4) change FIR coefficient type (l1d_data.c,l1d_data.h)
 * Resolution for 437: L1D modified code for MT6205
 *
 *    Rev 1.17   10 Jul 2002 15:48:28   mtk00240
 * CHange Variable Name RoundTripDelay to TXPropogation Delay
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.16   03 Jul 2002 21:43:46   mtk00240
 * L1D extrract RF setting code to let customer setup new RF module more easily
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.15   01 May 2002 22:45:54   mtk00240
 * Extract GSM code from L1D
 * Resolution for 384: Extract GSM code from L1D
 *
 *    Rev 1.14   23 Apr 2002 14:40:06   mtk00240
 * (1)  L1D removed RX_SWAP,TX_SWAP indicators in DSP R/TXWIN_PROC registers
 * (2)  L1D integrate all RF calibration data into m12193.c
 * Resolution for 376: L1D removed RX_SWAP,TX_SWAP indicators in DSP R/TXWIN_PROC registers
 * Resolution for 377: L1D integrate all RF calibration data into m12193.c
 *
 *    Rev 1.13   13 Apr 2002 22:07:20   mtk00240
 * L1D add code to wake up RF from sleep mode
 * Resolution for 366: L1D add code to wake up RF from sleep mode
 *
 *    Rev 1.12   03 Apr 2002 19:30:28   mtk00240
 * Fix some code to support Bright4 properly
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 *
 *    Rev 1.11   30 Mar 2002 13:04:10   mtk00240
 * 1) Modify L1D code to support both Bright2 & Bright4 RF board
 * 2) L1D add Audio interface to support Voice Memo & Melody
 * 3) Add L1D code to support RAM-based chip
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 * Resolution for 342: L1D add Audio interface to support Voice Memo & Melody
 * Resolution for 343: Add L1D code to support RAM-based chip
 *
 *    Rev 1.10   18 Mar 2002 21:25:58   mtk00240
 * Due to the issue of none duble-buffered AFC data when SB window is after CTIRQ1. L1D change the methode of setting negihbour cell AFC.
 * Resolution for 335: L1D avoid the issue of none duble-buffered AFC data
 *
 *    Rev 1.9   11 Mar 2002 13:35:34   mtk00240
 * instead TAB characters of Space characters in L1D code .
 * Resolution for 318: Shine change TAB character to Space charter
 *
 *    Rev 1.8   03 Mar 2002 23:06:30   mtk00240
 * L1D add code to setup APC DC offset
 * Resolution for 305: L1D add code to setup APC DC offset
 *
 *    Rev 1.7   19 Feb 2002 16:04:34   mtk00240
 * Change CTIRQ1/2 from solt6/5 to slot5/4
 * Resolution for 275: Update L1D code for solving HandOver test item
 *
 *    Rev 1.6   17 Feb 2002 20:15:30   mtk00240
 * Update L1D code for solving HandOver test item
 * Resolution for 275: Update L1D code for solving HandOver test item
 *
 *    Rev 1.5   30 Jan 2002 13:18:08   mtk00240
 * Add code to suppot power resolution change
 * Resolution for 253: RSSI resolution
 *
 *    Rev 1.4   21 Jan 2002 21:15:06   mtk00240
 * Add code to cancel the round trip delay of TX window in L1D
 * Resolution for 242: Add code to cancel the round trip delay of TX window
 *
 *    Rev 1.3   08 Jan 2002 17:10:54   mtk00240
 * Change TQ_BULON, TQ_BULOFF, TQ_BDLON.
 * Let IQ Swap can be change on running time.
 * Resolution for 203: Modify some RF parameters in L1D
 *
 *    Rev 1.2   03 Jan 2002 12:19:44   mtk00240
 * Merge B.L1.20011225 to Main V1.XX
 *
 *    Rev 1.1.1.0   Dec 25 2001 14:32:50   mtk00210
 * Update for High resolution RSSI, multiband AFC,
 * update L1C/L1D interface for CSD
 *
 *******************************************************************************/

#ifndef  _L1D_DATA_H_
#define  _L1D_DATA_H_
/*---------------------------------------------------------------------------*/

#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT || IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2
#define CONST
#else
#define CONST   const
#endif

#if IS_BPI_DATA_32_BIT_CHIP
typedef APBADDR32    APBADDR_P;
typedef signed long  sint_P;
#else
typedef APBADDR      APBADDR_P;
typedef signed short sint_P;
#endif

#if IS_BSI_CON_32_BIT_CHIP
typedef APBADDR32    APBADDR_S;
typedef signed long  sint_S;
#else
typedef APBADDR      APBADDR_S;
typedef signed short sint_S;
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6229~*/  #define  TQ_CTIRQ12_R23_DELAY   400
/*MT6229~*/  #if IS_CHIP_MT6251                    /*GSM only*/
/*MT6229~*/  #define  TQ_CTIRQ12_DELAY         0
/*MT6229~*/  #elif IS_CHIP_MT6253                  /*Not support EDGE*/
/*MT6229~*/  #define  TQ_CTIRQ12_DELAY       400   // 760
/*MT6229~*/  #elif IS_CHIP_MT6223                  /*Not support EDGE*/
/*MT6229~*/     #if IS_GPRS
/*MT6229~*/  #define  TQ_CTIRQ12_DELAY       400
/*MT6229~*/     #else                              /*GSM only */
/*MT6229~*/  #define  TQ_CTIRQ12_DELAY         0
/*MT6229~*/     #endif
/*MT6229~*/  #elif IS_CHIP_MT6236                  /*jason: for MPLL down hopping, need to gain 100 more for DSP*/
/*MT6229~*/  #define  TQ_CTIRQ12_DELAY       860
/*MT6229~*/  #else                                 /*Support EDGE*/
/*MT6229~*/  #define  TQ_CTIRQ12_DELAY       760
/*MT6229~*/  #endif
#elif IS_CHIP_MT6218_AND_LATTER_VERSION            /*&& !defined(L1D_TEST)*/   //For cosim and loopback, MCU will always run 104MHz
/*MT6218B~*/ #define  TQ_CTIRQ12_R23_DELAY   400
/*MT6218B~*/ #define  TQ_CTIRQ12_DELAY       400
#else
/*OTHERS*/   #define  TQ_CTIRQ12_R23_DELAY     0
/*OTHERS*/   #define  TQ_CTIRQ12_DELAY         0
#endif

#if defined(L1_SIM)
#undef  TQ_CTIRQ12_DELAY
   #if IS_FDD_DUAL_MODE_SUPPORT || IS_TDD_DUAL_MODE_SUPPORT
#define TQ_CTIRQ12_DELAY                     760
   #else
#define TQ_CTIRQ12_DELAY                     400
   #endif
#endif

#if IS_NEW_L1D_ARCH_SUPPORT
   #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#undef  TQ_CTIRQ12_DELAY
#define TQ_CTIRQ12_DELAY                     0
   #endif
#endif

#if IS_DSP_COSTDOWN_FB_CHIP
#define TQ_FSWIN_DTIRQ_DELATY_SLOT6   156    /*Set 100Qb before Slot0, for DSP has enough margin to deal FB data*/
#endif

/*--------------------------------------------------------*/
/* define TSU event time in QB                            */
/*--------------------------------------------------------*/
#if IS_TDMA_CLIPPING_SUPPORT
#define  TQ_MAXIMUM                          16383                         /*16383: 0x3FFF*/
#else
#define  TQ_MAXIMUM                          (2*TQ_WRAP_COUNT+TQ_SLOT_LEN) /*10624: 2 frames + 1 slot*/
#endif
#define  TQ_BURST_HEAD_GUARD                 16
#define  TQ_SLOT_LEN                         (156*4)
#define  TQ_SLOT0_BEGIN                      (TQ_AFC_READY)
#define  TQ_SLOT1_BEGIN                      (TQ_SLOT0_BEGIN+625)
#define  TQ_SLOT2_BEGIN                      (TQ_SLOT1_BEGIN+625)
#define  TQ_SLOT3_BEGIN                      (TQ_SLOT2_BEGIN+625)
#define  TQ_SLOT4_BEGIN                      (TQ_SLOT3_BEGIN+625)
#define  TQ_SLOT5_BEGIN                      (TQ_SLOT4_BEGIN+625)
#define  TQ_SLOT6_BEGIN                      (TQ_SLOT5_BEGIN+625)
#define  TQ_SLOT7_BEGIN                      (TQ_SLOT6_BEGIN+625)
#define  TQ_TX2RX_LEN                        (TQ_SLOT3_BEGIN-TQ_SLOT0_BEGIN)
#define  TQ_TX_SLOT0_BEGIN                   (TQ_SLOT0_BEGIN+TQ_TX2RX_LEN)
#define  TQ_WRAP_COUNT                       5000
#define  TQ_VALIDATE_OFFSET                  1
#define  TQ_VALIDATE_COUNT                   (TQ_WRAP_COUNT-60-TQ_VALIDATE_OFFSET)    /*4939*/
#define  TQ_VALIDATE                         (TQ_VALIDATE_COUNT+TQ_VALIDATE_OFFSET)   /*4940*/
#define  TQ_CTIRQ1                           (TQ_SLOT5_BEGIN+TQ_CTIRQ12_DELAY)
#if IS_NEW_L1D_ARCH_SUPPORT
   #if IS_MT6276_ADCMUX_CHECK_CHIP
#define  TQ_CTIRQ2                           (TQ_SLOT0_BEGIN-200)
   #else
#define  TQ_CTIRQ2                           (TQ_SLOT0_BEGIN)
   #endif
#else
#define  TQ_CTIRQ2                           (TQ_SLOT4_BEGIN+TQ_CTIRQ12_DELAY)
#endif
#define  TQ_DTIRQ                            2
#define  TQ_CTIRQ1_R23                       (TQ_SLOT5_BEGIN+TQ_CTIRQ12_R23_DELAY)
#define  TQ_CTIRQ2_R23                       (TQ_SLOT4_BEGIN+TQ_CTIRQ12_R23_DELAY)

#if L1D_PM_ENHANCE
#define  SHORT_PM_LEN                        64
#define  TQ_SHORT_PMWIN_LEN_IN_IDLE          (SHORT_PM_LEN*4)
   #if L1D_PM_1R7PM
#define  PM_LEN_1R7PM                        32
#define  TQ_1R7PM_PMWIN_LEN_IN_IDLE          (PM_LEN_1R7PM*4)
   #endif
#endif

#define  PM_LEN                              64
#define  TQ_SHORT_PMWIN_LEN                  (PM_LEN*4)

#if IS_AST_B2S_SUPPORT
#define  TQ_AFC_READY                        245
#define  TQ_AFC_READY_RX                     213
#else
#define  TQ_AFC_READY                        256
#define  TQ_AFC_READY_RX                     TQ_AFC_READY
#endif

#define  TQ_AFC_0_DEFAULT                    0
#define  TQ_AFC_1_DEFAULT                    TQ_SLOT4_BEGIN
#define  TQ_AFC_2_DEFAULT                    TQ_SLOT4_BEGIN
#define  TQ_AFC_CHARGE_IN_IDLE               (TQ_AFC_IDLE_LEN)
#define  TQ_AFC_CHARGE_IN_DEDI               (13*(TQ_WRAP_COUNT/8))
#define  TQ_AB_LEN                           (16+4*88+16)
#define  TQ_AB_END_ADVANCED                  (TQ_SLOT_LEN-TQ_AB_LEN)

#if IS_FDD_DUAL_MODE_SUPPORT
#define  TQ_FIRST_4PM_ADV                    368 // = 624-256 => make PM0 starting time align 256QB
#else
#define  TQ_FIRST_4PM_ADV                    0
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
  #if IS_DSP_SHORT_SB_ENABLED
#define  TQ_SBWIN_DSP_EXTEND1                28
#define  TQ_SBWIN_DSP_EXTEND2                28
#define  SB_TIMING_SHIFT_BASE                52
  #else
#define  TQ_SBWIN_DSP_EXTEND1                52
#define  TQ_SBWIN_DSP_EXTEND2                52
#define  SB_TIMING_SHIFT_BASE                52
  #endif
#else
#define  TQ_SBWIN_DSP_EXTEND1                28
#define  TQ_SBWIN_DSP_EXTEND2                28
#define  SB_TIMING_SHIFT_BASE                28
#endif

#define  TQ_SBWIN_LEN                        (TQ_SBWIN_DSP_EXTEND1+TQ_SLOT_LEN+TQ_SBWIN_DSP_EXTEND2)
#define  TQ_FSWIN_STOP_FSYNC                 (TQ_VALIDATE+10)

#define  TQ_BSI_READ_TIME                    (TQ_SLOT0_BEGIN+TQ_SLOT_LEN-100)

// for switching FB algorithm on MT6229
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION

   #ifdef L1D_TEST
#define  MT6229_FB_ON_MT6229                 1
#define  MT6229_FB_SCALING                   1 //loopback and cosim should 1
   #else
#define  MT6229_FB_ON_MT6229                 1
#define  MT6229_FB_SCALING                   1
   #endif

#define  MT6229_FB_VCXO                      1

#else
#define  MT6229_FB_ON_MT6229                 0
#define  MT6229_FB_SCALING                   0
#define  MT6229_FB_VCXO                      0
#endif /*IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION*/


/* The 3rd stage FB algorithm of MT6229 sometime finds a FB but with bad QI.               */
/* In the original design, DSP will try to decode SB automatically even if QI is bad.      */
/* In order improve it, L1 will reset DSP to search FB again if FB with bad QI is detected */
#if MT6229_FB_ON_MT6229
   #if IS_CHIP_MT6268T || (IS_EDGE_SAIC_CHIP_MT6268_AND_LATTER_VERSION && !IS_CHIP_MT6253T && !IS_CHIP_MT6516)
#define  RESET_FB_WITH_BAD_QI                1
   #else
#define  RESET_FB_WITH_BAD_QI                0
   #endif
#else
#define  RESET_FB_WITH_BAD_QI                0
#endif

/* ------------------------------------------------------------------------- */

/* todo : remeber to change the enable flag definition in l1d_reg.h */

#if IS_FPGA_TARGET || IS_CHIP_MT6208
/*FPGA,MT6208*/ #define  AFCEN(n)            ((n)<<3)
/*FPGA,MT6208*/ #define  AFCEN3              (0x8000)
#endif

#if IS_CHIP_MT6205_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6205~*/#define  AFCEN(n)                 ((n)<<12)
/*MT6205~*/#define  AFCEN3                   (0x8000)
#endif

#if IS_CHIP_MT6205
/*MT6205*/ #define  BSI_EVENT_COUNT          13
/*MT6205*/ #define  BSI_DATA_COUNT           22
#elif IS_CHIP_MT6208 || IS_CHIP_MT6218 || IS_CHIP_MT6219
/*MT6218*/ #define  BSI_EVENT_COUNT          16
/*MT6218*/ #define  BSI_DATA_COUNT           26
#elif IS_CHIP_MT6227_AND_LATTER_VERSION
/*MT6227*/ #define  BSI_EVENT_COUNT          16
/*MT6227*/ #define  BSI_DATA_COUNT           27
#elif IS_CHIP_MT6268T_DMAC
/*MT6270*/ #define  BSI_EVENT_COUNT          20   // DE JC Lin comment: align 68A
/*MT6270*/ #define  BSI_DATA_COUNT           65
#elif IS_CHIP_MT6268H
/*MT6270*/ #define  BSI_EVENT_COUNT          36
/*MT6270*/ #define  BSI_DATA_COUNT           104
#elif IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
/*MT6290*/ #define  BSI_EVENT_COUNT          103
/*MT6290*/ #define  BSI_DATA_COUNT           304
#elif IS_CHIP_MT6572
/*MT6572*/ #define  BSI_EVENT_COUNT          54
/*MT6572*/ #define  BSI_DATA_COUNT           196
#elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2
   #if IS_CHIP_MT6270A_E1 || IS_CHIP_MT6276_S00 || IS_CHIP_MT6573
/*MT6270*/ #define  BSI_EVENT_COUNT          36   // for MT6270A E1, MT6276E1, MT6573
/*MT6270*/ #define  BSI_DATA_COUNT           104  // for MT6270A E1, MT6276E1, MT6573
   #else
/*MT6270*/ #define  BSI_EVENT_COUNT          42   // for MT6270A E2, MT6276E2
/*MT6270*/ #define  BSI_DATA_COUNT           128  // for MT6270A E2, MT6276E2
   #endif
#elif IS_EDGE_SAIC_CHIP_MT6256_AND_LATTER_VERSION
   #if IS_CHIP_MT6256_S00 || IS_CHIP_MT6251
/*MT6256*/ #define  BSI_EVENT_COUNT          36
/*MT6256*/ #define  BSI_DATA_COUNT           64
   #else
/*MT6256*/ #define  BSI_EVENT_COUNT          21
/*MT6256*/ #define  BSI_DATA_COUNT           40
   #endif
#elif IS_CHIP_MT6252
/*MT6252*/ #define  BSI_EVENT_COUNT          21
/*MT6252*/ #define  BSI_DATA_COUNT           32
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6229*/ #define  BSI_EVENT_COUNT          20
/*MT6229*/ #define  BSI_DATA_COUNT           44
#endif

#if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268 || IS_EDGE_SAIC_CHIP_MT6256_AND_LATTER_VERSION || IS_CHIP_MT6252
/*MT6252*/ #define  BSI_DATA_COUNT_SW_LIMIT  BSI_DATA_COUNT
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6229*/ #define  BSI_DATA_COUNT_SW_LIMIT  40   // the maximum control words length of BSI data 40~43 is 78 bits, which is not support by L1D
#else
/*OTHERS*/ #define  BSI_DATA_COUNT_SW_LIMIT  BSI_DATA_COUNT
#endif

/* ------------------------------------------------------------------------- */

#if IS_GPRS || IS_MULTISLOT_TX_SUPPORT
   #if    IS_5_BANK_RAMP_PROFILES_SUPPORT
#define S2_S3_APC_IDX                        3
#define S3_S4_APC_IDX                        4
   #elif  IS_6_BANK_RAMP_PROFILES_SUPPORT
#define S2_S3_APC_IDX                        3
#define S3_S4_APC_IDX                        5
   #elif  IS_7_BANK_RAMP_PROFILES_SUPPORT
#define S2_S3_APC_IDX                        5
#define S3_S4_APC_IDX                        6
   #endif
#endif

/* ------------------------------------------------------------------------- */

#if !IS_RTX_5CWIN_SUPPORT // IS_GSM
   #if IS_BPI_V2_SUPPORT
/*GSM*/ #define  BPIRES1                     20
/*GSM*/ #define  BPIRES2                     20
/*GSM*/ #define  PT2M_EV(m,n)               (21+3*(m)+(n))
/*GSM*/ #define  PR3A_EV(n)                  BPIDX(n,3)
      #if IS_BPI_V2_PT3A_SUPPORT
/*GSM*/ /* PT1/2/2B/3: 0~3, 4~7, 8~11, 12~15, 16~19 */
/*GSM*/ /* FSI_STOP:   20                           */
/*GSM*/ /* PT2M1/2/3:  21~23, 24~26, 27~29          */
/*GSM*/ #define  PT3A_CWIN1                  30
/*GSM*/ #define  PT3A_CWIN2                  31
      #endif
   #elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*GSM*/ #define  BPIRES1                     40
/*GSM*/ #define  BPIRES2                     41
/*GSM*/ #define  PT2M_EV(m,n)               (26+3*(m)+(n))
/*GSM*/ #define  PR3A_EV(n)                 (35+(n))
   #else
/*GSM*/ #define  BPIRES                      12
   #endif
/*GSM*/
/*GSM*/ #define  FS_CWIN_IDX                 2
/*GSM*/ #define  FS_RXWIN_IDX                2
/*GSM*/ #define  FS_AFC_IDX                  3
/*GSM*/ #define  FS_AFC_EN                   AFCEN3
/*GSM*/
/*GSM*/ #define  PM7_RXWIN_IDX               3
/*GSM*/
/*GSM*/ #define  AGCEV0                      (CWIN_BSI_EVENT_COUNT*CWIN_COUNT)
#endif

#if IS_RTX_5CWIN_SUPPORT // IS_GPRS
   #if IS_BPI_V2_SUPPORT
/*GPRS*/ #define  BPIRES1                    20
/*GPRS*/ #define  BPIRES2                    20
/*GPRS*/ #define  PT2M_EV(m,n)              (21+3*(m)+(n))
/*GPRS*/ #define  PR3A_EV(n)                 BPIDX(n,3)
      #if IS_BPI_V2_PT3A_SUPPORT
/*GPRS*/ /* PT1/2/2B/3: 0~3, 4~7, 8~11, 12~15, 16~19 */
/*GPRS*/ /* FSI_STOP:   20                           */
/*GPRS*/ /* PT2M1/2/3:  21~23, 24~26, 27~29          */
/*GPRS*/ #define  PT3A_CWIN1                 30
/*GPRS*/ #define  PT3A_CWIN2                 31
      #endif
   #elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*GPRS*/ #define  BPIRES1                    40
/*GPRS*/ #define  BPIRES2                    41
/*GPRS*/ #define  PT2M_EV(m,n)              (26+3*(m)+(n))
/*GPRS*/ #define  PR3A_EV(n)                (35+(n))
   #else
/*GPRS*/ #define  BPIRES                     15
   #endif
/*GPRS*/
/*GPRS*/ #define  FS_CWIN_IDX                3
/*GPRS*/ #define  FS_RXWIN_IDX               4
/*GPRS*/ #define  FS_AFC_IDX                 3
/*GPRS*/ #define  FS_AFC_EN                  AFCEN3
/*GPRS*/
/*GPRS*/ #define  PM7_RXWIN_IDX              5
/*GPRS*/
/*GPRS*/ #define  AGCEV0                     (CWIN_BSI_EVENT_COUNT*CWIN_COUNT)
#endif

/* ------------------------------------------------------------------------- */

#define  AGCIDX(n)                           (AGCEV0+(n))
#if IS_BSI_SX0_SUPPORT
#define  BSI_GROUP_COUNT                     3
#define  BSIDX(m,n)                          ((m)*BSI_GROUP_COUNT+(n)+1)
#else
#define  BSI_GROUP_COUNT                     2
#define  BSIDX(m,n)                          ((m)*BSI_GROUP_COUNT+(n))
#endif
#define  BSIEN(m,n)                          (1<<BSIDX(m,n))
#define  BSIEN_X(n)                          (1<<AGCIDX(n))
#define  BSIENALL(m)                         ((1<<(BSI_GROUP_COUNT*(m)))-1)

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define  BPI_GROUP_COUNT                     4
#else
#define  BPI_GROUP_COUNT                     3
#endif
#define  BPIDX(m,n)                          ((m)*BPI_GROUP_COUNT+(n))
#define  BPIEN(m,n)                          (1<<BPIDX(m,n))
#define  BPIENALL(m)                         ((1<<(BPI_GROUP_COUNT*(m)))-1)

/* ------------------------------------------------------------------------- */

#if IS_FPGA_TARGET || IS_CHIP_MT6208
/*FPGA,MT6208*/ #define  PCTRL_INITIAL       0x0001         /* the initial bus status                         */
/*FPGA,MT6208*/ #define  PCTRL_MAIN          0x0000         /* BPI  main control value : ctrl. by TSU         */
/*FPGA,MT6208*/ /* ------------------------------------------------------------------------------------------ */
#endif

#if IS_CHIP_MT6205_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_CHIP_MT6572
/*MT6572 */ #define  DRV_0_6_4mA             0x0            /* Driving level 0 for bus0~ 6 =  4 mA (min)      */
/*MT6572 */ #define  DRV_0_6_8mA             0x1            /* Driving level 1 for bus0~ 6 =  8 mA (default)  */
/*MT6572 */ #define  DRV_0_6_12mA            0x2            /* Driving level 2 for bus0~ 6 = 12 mA            */
/*MT6572 */ #define  DRV_0_6_16mA            0x3            /* Driving level 3 for bus0~ 6 = 16 mA (max)      */
/*MT6572 */ #define  DRV_7_15_2mA            0x0            /* Driving level 0 for bus7~15 =  2 mA (min)      */
/*MT6572 */ #define  DRV_7_15_4mA            0x1            /* Driving level 1 for bus7~15 =  4 mA (default)  */
/*MT6572 */ #define  DRV_7_15_6mA            0x2            /* Driving level 2 for bus7~15 =  6 mA            */
/*MT6572 */ #define  DRV_7_15_8mA            0x3            /* Driving level 3 for bus7~15 =  8 mA (max)      */
/*MT6572 */ #define  CFG_DRV_MASK            0x000003FC     /* Driving capability setting mask (bit[ 9: 2])   */
/*MT6572 */ #define  CFG_DRV_CON             (DRV_7_15_4mA<<8)|(DRV_7_15_4mA<<6)|(DRV_0_6_8mA<<4)|(DRV_0_6_8mA<<2)
   #elif IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2
/*MT6583~*/ #define  DRV_4mA                 0x0            /* Driving level 0 =  4 mA (min)                  */
/*MT6583~*/ #define  DRV_8mA                 0x1            /* Driving level 1 =  8 mA                        */
/*MT6583~*/ #define  DRV_12mA                0x2            /* Driving level 2 = 12 mA (default)              */
/*MT6583~*/ #define  DRV_16mA                0x3            /* Driving level 3 = 16 mA (max)                  */
/*MT6583~*/ #define  CFG_DRV_MASK            0x00006000     /* Driving capability setting mask (bit[14:13])   */
/*MT6583~*/ #define  CFG_DRV_CON             (DRV_12mA<<13)
   #elif IS_CHIP_MT6280
/*MT6280~*/ #define  DRV_4mA                 0x0            /* Driving level 0 =  4 mA (min)                  */
/*MT6280~*/ #define  DRV_8mA                 0x1            /* Driving level 1 =  8 mA                        */
/*MT6280~*/ #define  DRV_12mA                0x2            /* Driving level 2 = 12 mA (default)              */
/*MT6280~*/ #define  DRV_16mA                0x3            /* Driving level 3 = 16 mA (max)                  */
/*MT6280~*/ #define  CFG_DRV13               (DRV_8mA << 8) /* Driving capability setting of BPI0~3           */
/*MT6280~*/ #define  CFG_DRV14               (DRV_8mA <<10) /* Driving capability setting of BPI4             */
/*MT6280~*/ #define  CFG_DRV15               (DRV_12mA<<12) /* Driving capability setting of BPI5             */
/*MT6280~*/ #define  CFG_DRV16               (DRV_12mA<<14) /* Driving capability setting of BPI6             */
/*MT6280~*/ #define  CFG_DRV17               (DRV_12mA<< 0) /* Driving capability setting of BPI7             */
/*MT6280~*/ #define  CFG_DRV18               (DRV_12mA<< 2) /* Driving capability setting of BPI8             */
/*MT6280~*/ #define  CFG_DRV19               (DRV_12mA<< 4) /* Driving capability setting of BPI9             */
/*MT6280~*/ #define  CFG_DRV20               (DRV_12mA<< 6) /* Driving capability setting of BPI10            */
/*MT6280~*/ #define  CFG_DRV21               (DRV_12mA<< 8) /* Driving capability setting of BPI11            */
/*MT6280~*/ #define  CFG_DRV22               (DRV_12mA<<10) /* Driving capability setting of BPI12            */
/*MT6280~*/ #define  CFG_DRV23               (DRV_12mA<<12) /* Driving capability setting of BPI13            */
/*MT6280~*/ #define  CFG_DRV_MASK            0xFF00         /* Driving capability setting mask (bit[15:8])    */
/*MT6280~*/ #define  CFG_DRV_MASK1           0x3FFF         /* Driving capability setting mask (bit[13:0])    */
/*MT6280~*/ #define  CFG_DRV_CON             (CFG_DRV16|CFG_DRV15|CFG_DRV14|CFG_DRV13)
/*MT6280~*/ #define  CFG_DRV_CON1            (CFG_DRV23|CFG_DRV22|CFG_DRV21|CFG_DRV20|CFG_DRV19|CFG_DRV18|CFG_DRV17)
/*MT6280~*/ /* ---------------------------------------------------------------------------------------------- */
   #elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H || IS_AST_B2S_SUPPORT
/*MT6270~*/ #define  PCTRL_INITIAL           0x03FE         /* The output driving capability of BPI0~4 is 8mA */
/*MT6270~*/ #define  PCTRL_MAIN              0x03FE         /* The output driving capability of BPI0~4 is 8mA */
/*MT6270~*/ /* ---------------------------------------------------------------------------------------------- */
   #elif IS_CHIP_MT6268
/*MT6268~*/ #define  PCTRL_INITIAL           0x003F         /* The output driving capability of BPI0~4 is 8mA */
/*MT6268~*/ #define  PCTRL_MAIN              0x003E         /* The output driving capability of BPI0~4 is 8mA */
/*MT6268~*/ /* ---------------------------------------------------------------------------------------------- */
   #else
/*MT6229~*/ #define  PCTRL_INITIAL           0x000F         /* The output driving capability of BPI0~2 is 8mA */
/*MT6229~*/ #define  PCTRL_MAIN              0x000E         /* The output driving capability of BPI0~2 is 8mA */
/*MT6229~*/ /* ---------------------------------------------------------------------------------------------- */
   #endif
#endif

#if IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define  L1D_SET_BPI_IMM_MODE_BEGIN()
#define  L1D_SET_BPI_IMM_MODE_END()
#elif IS_CHIP_MT6572
#define  L1D_SET_BPI_IMM_MODE_BEGIN()      { unsigned long  d32=HW_READ(GPIO_DRV_CFG0);  d32&=~(CFG_DRV_MASK);  d32|=CFG_DRV_CON ;  HW_WRITE(GPIO_DRV_CFG0, d32); }
#define  L1D_SET_BPI_IMM_MODE_END()        { unsigned long  d32=HW_READ(GPIO_DRV_CFG0);  d32&=~(CFG_DRV_MASK);  d32|=CFG_DRV_CON ;  HW_WRITE(GPIO_DRV_CFG0, d32); }
#elif IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2
#define  L1D_SET_BPI_IMM_MODE_BEGIN()      { unsigned long  d32=HW_READ(GPIO_DRV_CON5);  d32&=~(CFG_DRV_MASK);  d32|=CFG_DRV_CON ;  HW_WRITE(GPIO_DRV_CON5, d32); }
#define  L1D_SET_BPI_IMM_MODE_END()        { unsigned long  d32=HW_READ(GPIO_DRV_CON5);  d32&=~(CFG_DRV_MASK);  d32|=CFG_DRV_CON ;  HW_WRITE(GPIO_DRV_CON5, d32); }
#elif IS_CHIP_MT6280
#define  L1D_SET_BPI_IMM_MODE_BEGIN()      { unsigned short d16=HW_READ(GPIO_DRV2);  d16&=~(CFG_DRV_MASK );  d16|=CFG_DRV_CON ;  HW_WRITE(GPIO_DRV2, d16); \
                                                            d16=HW_READ(GPIO_DRV3);  d16&=~(CFG_DRV_MASK1);  d16|=CFG_DRV_CON1;  HW_WRITE(GPIO_DRV3, d16); }
#define  L1D_SET_BPI_IMM_MODE_END()        { unsigned short d16=HW_READ(GPIO_DRV2);  d16&=~(CFG_DRV_MASK );  d16|=CFG_DRV_CON ;  HW_WRITE(GPIO_DRV2, d16); \
                                                            d16=HW_READ(GPIO_DRV3);  d16&=~(CFG_DRV_MASK1);  d16|=CFG_DRV_CON1;  HW_WRITE(GPIO_DRV3, d16); }
#else
#define  L1D_SET_BPI_IMM_MODE_BEGIN()        HW_WRITE( BPI_CON, PCTRL_INITIAL )
#define  L1D_SET_BPI_IMM_MODE_END()          HW_WRITE( BPI_CON, PCTRL_MAIN )
#endif
/* ------------------------------------------------------------------------- */

#if IS_FPGA_TARGET || IS_CHIP_MT6208
/*FPGA,MT6208*/ #define  AFC_EVENT_TRIGGER   0x0000   /* AFC 10 bit *//* AFC power up by DAC_AFC_ENABLEn events   */
/*FPGA,MT6208*/ #define  AFC_FORCE_POWER_ON  0x0001   /* AFC 10 bit *//* AFC always power on                      */
#endif

#if IS_CHIP_MT6205_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_FDD_DUAL_MODE_SUPPORT || IS_TDD_DUAL_MODE_SUPPORT
      #if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H || IS_AST_B2S_SUPPORT || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
/*MT6205~*/ #define  AFC_EVENT_TRIGGER       0x0000   /* AFC power up by DAC_AFC_ENABLEn events   */
/*MT6205~*/ #define  AFC_FORCE_POWER_ON      0x0001   /* AFC immediate mode                       */
      #elif IS_CHIP_MT6268A || IS_CHIP_MT6268_S00 || IS_CHIP_MT6268T
/* chuwei: 0x0020 fixed MT6268A AFC Hold mode issue(Always on) */
/*MT6205~*/ #define  AFC_EVENT_TRIGGER       0x0024   /* AFC power up by DAC_AFC_ENABLEn events   */
/*MT6205~*/ #define  AFC_FORCE_POWER_ON      0x0025   /* AFC immediate mode + always power on     */
      #else
//* chuwei: 0x0020 fixed MT6268A AFC Hold mode issue(Always on), 0x0040 Auto_SRCLKEN_OFF*/
/*MT6205~*/ #define  AFC_EVENT_TRIGGER       0x0064   /* AFC power up by DAC_AFC_ENABLEn events   */
/*MT6205~*/ #define  AFC_FORCE_POWER_ON      0x0065   /* AFC immediate mode + always power on     */
      #endif
   #else
/*MT6205~*/ #define  AFC_EVENT_TRIGGER       0x0000   /* AFC power up by DAC_AFC_ENABLEn events   */
/*MT6205~*/ #define  AFC_FORCE_POWER_ON      0x0005   /* AFC immediate mooe + always power on     */
   #endif
#endif
/* ------------------------------------------------------------------------- */

#if IS_APC_HALF_QB_RESOLUTION_SUPPORT
/*MT6583~*/ #define  APC_CON_DAC_RATE_SEL    0x1      /* 1: The data rate of APC D/A converter is 2.1666MHz */
                                                      /* 0: The data rate of APC D/A converter is 1.0833MHz */
#else
/*others~*/ #define  APC_CON_DAC_RATE_SEL    0x0
#endif
/* ------------------------------------------------------------------------- */

#define  PWRRES_BIT                          RSSI_RESOLUTION_BITS
#define  PWRRES                              RSSI_FACTOR

/* ========================================================================= */

extern const int              dsp_power_constance;

extern const short            TQ_Afc_ChargeInIdle;
extern CONST short            TQ_FBWin_Start_Offset;
extern const short            TQ_FSWin_DTIRQ_Delay;
extern CONST short            TxPropagationDelay;
extern const short            FrequencyBias;
extern       short            AFC_Dac_TRx_Offset[5];
#if IS_VCXO_LC_TRXOFFSET_COMPENSATE_SUPPORT
extern       short            AFC_TRx_Offset[5];
extern       short            AFC_Default_TRx_Offset[5];
#else
   #if IS_RF_MT6162 || IS_RF_MT6163
extern       short            AFC_TRx_Offset[5];
extern       short            AFC_Default_TRx_Offset[5];
   #endif
#endif
#if IS_BBTXRX_CHIP_DESIGN_VER_2 || IS_BBTXRX_CHIP_DESIGN_VER_3
extern const unsigned char    bbrx_iq_swap;
extern const unsigned char    bbtx_iq_swap;
extern const unsigned char    bbtx_common_mode_voltage;
extern const unsigned char    bbtx_offset_i;
extern const unsigned char    bbtx_offset_q;
extern const unsigned char    bbtx_phseli;
extern const unsigned char    bbtx_phselq;
extern const unsigned char    bbtx_rpsel;
extern const unsigned char    bbtx_inten;
extern const unsigned char    bbtx_sw_qbcnt;
extern const unsigned char    bbtx_gain_comp;
extern const unsigned char    bbtx_iqgain_sel;
extern const unsigned char    bbtx_epsk_dtap_sym;
#else
extern const unsigned char    bbrx_iq_swap;
extern const unsigned char    bbrx_gain_double;
extern const unsigned char    bbtx_iq_swap;
extern const unsigned char    bbtx_calrcsel;
extern const unsigned char    bbtx_calbias;
extern const unsigned char    bbtx_common_mode_voltage;
extern const unsigned char    bbtx_gain;
extern const unsigned char    bbtx_trim_i;
extern const unsigned char    bbtx_trim_q;
   #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
extern const unsigned char    bbtx_dccoarse_i;
extern const unsigned char    bbtx_dccoarse_q;
   #endif
extern const unsigned char    bbtx_offset_i;
extern const unsigned char    bbtx_offset_q;
extern const unsigned char    bbtx_phsel;

   #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
extern const unsigned char    bbtx_calrcsel_h;
extern const unsigned char    bbtx_common_mode_voltage_h;
extern const unsigned char    bbtx_gain_h;
extern const unsigned char    bbtx_trim_i_h;
extern const unsigned char    bbtx_trim_q_h;
      #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
extern const unsigned char    bbtx_dccoarse_i_h;
extern const unsigned char    bbtx_dccoarse_q_h;
      #endif
extern const unsigned char    bbtx_offset_i_h;
extern const unsigned char    bbtx_offset_q_h;
extern const unsigned char    bbtx_phsel_h;
      #if !IS_CHIP_MT6223 && !IS_CHIP_MT6253  /*MT6223 and MT6253 don't support 8PSK*/
extern const unsigned char    bbtx_rpsel;
extern const unsigned char    bbtx_inten;
extern const unsigned char    bbtx_sw_qbcnt;
      #endif
   #endif
#endif

#if IS_CHIP_MT6227
extern const unsigned char    bbtx_iqswap_onfly;
#endif
extern const unsigned short   bdlcon_data;
extern const unsigned short   bulcon1_data;
extern const unsigned short   bulcon2_data;
#if IS_TDMA_AD_DA_WINDOW_SUPPORT
extern const unsigned short   bdlcon2_data;
extern const unsigned short   bulcon3_data;
#endif

extern CONST int              apc_bat_voltage_period;
extern CONST int              apc_bat_voltage_count;
extern CONST int              apc_bat_temperature_period;
extern CONST int              apc_bat_temperature_count;
extern CONST int              apc_rf_temperature_period;
extern CONST int              apc_rf_temperature_count;

/*---------------------------------------------------------------------------*/

extern const       APBADDR_P  PDATA_REG_TABLE[/*4:5*/];
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
extern const       APBADDR_P  PDATA_REG_TABLE2[/*4:5*/];
#endif
#if IS_BPI_V2_PT3A_SUPPORT
extern const       APBADDR_P  PDATA_REG_TABLE3[2];
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
extern CONST    signed short  RX_END_TQ_TABLE[5];
#else
extern CONST    signed short  RX_END_TQ_TABLE[4];
#endif
extern CONST    signed short  TX_START_TQ_TABLE[8];
extern CONST    signed short  TX_END_TQ_TABLE[6];
#if IS_BPI_V2_PT3A_SUPPORT
extern CONST    signed short  TX_END_TQ_TABLE2[1];
#endif
extern CONST    signed short  PM_START_TQ_TABLE[7];
extern const    signed short  FWIN_POS_TABLE[8];
extern CONST          sint_P  FSWIN_STOP_DATA_BPI_TABLE[2];
extern const       APBADDR_P  FSWIN_STOP_REG_BPI_TABLE[2];
extern const          sint_S  FSWIN_STOP_DATA_BSI_TABLE[2];
extern const       APBADDR_S  FSWIN_STOP_REG_BSI_TABLE[2];
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
extern CONST    signed short  FSWIN_STOP_DATA_TABLE[5];
extern const         APBADDR  FSWIN_STOP_REG_TABLE[2][5];
#else
extern CONST    signed short  FSWIN_STOP_DATA_TABLE[7];
extern const         APBADDR  FSWIN_STOP_REG_TABLE[2][6];
#endif
#if IS_RF_MT6162 || IS_RF_MT6163
extern const   unsigned long  FSWIN_STOP_BSI_DATA_TABLE[2];
extern const         APBADDR  FSWIN_STOP_BSI_REG_TABLE[4];
#else
extern const   unsigned long  FSWIN_STOP_BSI_DATA_TABLE[1];
extern const         APBADDR  FSWIN_STOP_BSI_REG_TABLE[2];
#endif
extern const           short  FIR_COEF[/*20:17*/];
extern CONST    signed short  RX_MIDDLE_TQ_TABLE[3];
extern CONST    signed short  TX_MIDDLE_TQ_TABLE[4];
extern const   unsigned char  LOWEST_TX_POWER[5];
extern const     signed long  bb_tx_opt_swing_dac_sqr;
extern const   unsigned char  CONTISLOTMASK[5];
extern const   unsigned char  FIRSTSLOTMASK[5];

/*---------------------------------------------------------------------------*/
#if IS_DSDA_DCS_TX_NOTCH_SWITCH_SUPPORT
#define  NOTCH_CPL      2; // 2nd path notch filter couple loss 2dB 
#endif
/*---------------------------------------------------------------------------*/

#if IS_DSDA_DCS_TX_NOTCH_SWITCH_SUPPORT
#define  PDATA_TABLE    PDATA_TABLE_P
#else
#define  PDATA_TABLE    PDATA_TABLE
#endif

#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_DSDA_DCS_TX_NOTCH_SWITCH_SUPPORT
/*MT6229~*/extern CONST          sint_P  (*PDATA_TABLE_P)[2][5];
/*MT6229~*/extern CONST          sint_P  PDATA_TABLE_DCS_TX_NOTCH[5][2][5];
/*MT6229~*/extern CONST          sint_P  PDATA_TABLE_DEFAULT[5][2][5];
   #else
/*MT6229~*/extern CONST          sint_P  PDATA_TABLE[5][2][5];
   #endif
/*MT6229~*/extern CONST          sint_P  PDATA_TABLE3[5][3][3];//for PR2M1, PR2M2, PT2M1, PT2M3
/*MT6229~*/extern const       APBADDR_P  PDATA_PT2M_REG_TABLE[4];
/*MT6229~*/extern const       APBADDR_P  PDATA_PR2M_REG_TABLE[4];
/*MT6229~*/
/*MT6229~*/extern CONST    signed short  RTX_START_TQ_TABLE[2];
   #ifdef L1D_TEST
/*MT6229~*/extern          signed short  RX_START_TQ_TABLE[8];
   #else
/*MT6229~*/extern CONST    signed short  RX_START_TQ_TABLE[8];
   #endif
/*MT6229~*/
/*MT6229~*/extern CONST    signed short  PM_TQ_TABLE[10];
/*MT6229~*/
   #if L1D_PM_ENHANCE
/*MT6229~*/extern CONST    signed short  PM_IN_IDLE_TQ_TABLE[10];
      #if L1D_PM_1R7PM
/*MT6229~*/extern CONST    signed short  PM_1R7PM_TQ_TABLE[10];
      #endif
   #endif
/*MT6229~*/
/*MT6229~*/extern const           short  NB_FIR_COEF[];
/*MT6229~*/extern const           short  NARROW_FB_FIR_COEF[];
/*MT6229~*/extern const           short  WIDE_FB_FIR_COEF[];
/*MT6229~*/extern const           short  NB_FIR_COEF_WIDER[];
/*MT6229~*/
   #ifdef  L1D_TEST
/*MT6229~*/extern const           short  VCXO_NARROW_FB_FIR_COEF[];
/*MT6229~*/extern const           short  VCXO_WIDE_FB_FIR_COEF[];
/*MT6229~*/extern const           short  TCVCXO_NARROW_FB_FIR_COEF[];
/*MT6229~*/extern const           short  TCVCXO_WIDE_FB_FIR_COEF[];
   #endif
/*MT6229~*/
/*MT6229~*/extern CONST    signed short  RX_MIDDLE_TQ_TABLE2[2];
/*MT6229~*/extern CONST    signed short  TX_START_TQ_TABLE2[1];
/*MT6229~*/extern CONST    signed short  TX_START_TQ_TABLE3[1];//for TQ_ST2B
/*MT6229~*/
/*MT6229~*/extern CONST    signed short  TX_MIDDLE_TQ_TABLE2[2][4];
/*MT6229~*/
#else /*!IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION*/
/*MT6218~*/extern const    signed short  PDATA_TABLE[/*5*/][2][3];
/*MT6218~*/
   #if IS_CHIP_MT6225_AND_LATTER_VERSION
      #ifdef L1D_TEST
/*MT6218~*/extern          signed short  RX_START_TQ_TABLE[7];
      #else
/*MT6218~*/extern const    signed short  RX_START_TQ_TABLE[7];
      #endif
   #else
/*MT6218~*/extern const    signed short  RX_START_TQ_TABLE[7];
   #endif /*End of "IS_CHIP_MT6225_AND_LATTER_VERSION"*/
/*MT6218~*/
/*MT6218~*/extern const    signed short  PM_TQ_TABLE[8];
/*MT6218~*/
   #if L1D_PM_ENHANCE
/*MT6218~*/extern const    signed short  PM_IN_IDLE_TQ_TABLE[8];
      #if L1D_PM_1R7PM
/*MT6218~*/extern const    signed short  PM_1R7PM_TQ_TABLE[8];
      #endif
   #endif
/*MT6218~*/
   #if IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6218~*//*MT6218~*/ extern const    signed short  PDATA_TABLE2[5][2][2];
/*MT6218~*//*MT6218~*/ extern const         APBADDR  PDATA_PT2B_REG_TABLE[2][3];
/*MT6218~*//*MT6218~*/ extern const         APBADDR  PDATA_PR2M_REG_TABLE[4];
/*MT6218~*//*MT6218~*/ extern const    signed short  RX_MIDDLE_TQ_TABLE2[2];
/*MT6218~*//*MT6218~*/ extern const    signed short  TX_START_TQ_TABLE2[1];
   #endif
/*MT6218~*/
   #if IS_CHIP_MT6225_AND_LATTER_VERSION
/*MT6218~*//*MT6225*/  extern const           short  NB_FIR_COEF[];
/*MT6218~*//*MT6225*/  extern const           short  NB_FIR_COEF_WIDER[];
   #endif
/*MT6218~*/
#endif /* End of "IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION" */

#if IS_BSI_TRIG_OFFCHIP_BPI_SUPPORT
extern CONST signed short PDATA_SX_TABLE[5][2][2];
#endif

/*---------------------------------------------------------------------------*/

#if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
extern unsigned char USE_3_SUBSTAGES_FB_STAGE1;
#elif !IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
extern const unsigned char USE_3_SUBSTAGES_FB_STAGE1;
#endif

/*---------------------------------------------------------------------------*/

#if  IS_RF_MT6140D
extern CONST unsigned long  TXCW[/*2*/][2][5];
#endif

/*---------------------------------------------------------------------------*/

#if IS_MPLL_FH_SUPPORT || IS_MT6276E1_TEMP_MPLL_FH_SUPPORT || IS_MT6276_FREERUN_SUPPORT
extern unsigned char MPLL_FLT;
#endif

#if IS_SPLL_FH_SUPPORT
extern unsigned char SPLL_FLT;
#endif

/*---------------------------------------------------------------------------*/

#if IS_32K_CRYSTAL_REMOVAL_SUPPORT
extern char l1d_ext_32k_exist;
#endif

/*---------------------------------------------------------------------------*/

#if IS_32K_CRYSTAL_REMOVAL_SUPPORT || IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
extern int   afc_Phi_est;
extern short locked_DacValue;
extern short current_DacValue;
extern short afc_dac_default_ori;
#endif

/*---------------------------------------------------------------------------*/


#define  TQ_PM0_BEGIN_HF         (TQ_AFC_READY+TQ_SLOT_LEN-TQ_SHORT_PMWIN_LEN_IN_IDLE)

#if L1D_PM_ENHANCE
#define  TQ_PM_WIN_OFF_MARGIN    8
#define  TQ_PM1_BEGIN_HF         (TQ_SLOT1_BEGIN+TQ_AFC_READY+TQ_PM_WIN_OFF_MARGIN)
#define  TQ_PM2_BEGIN_HF         (TQ_PM1_BEGIN_HF+TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_AFC_READY+TQ_PM_WIN_OFF_MARGIN)
#define  TQ_PM3_BEGIN_HF         (TQ_PM2_BEGIN_HF+TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_AFC_READY+TQ_PM_WIN_OFF_MARGIN)
#define  TQ_VALIDATE_COUNT_HF    (TQ_PM3_BEGIN_HF+TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN)
#define  TQ_CTIRQ2_HF            (TQ_PM1_BEGIN_HF+TQ_SHORT_PMWIN_LEN_IN_IDLE+100)
#define  TQ_PM_REGBIAS_OFF_HF    (((TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_AFC_READY+TQ_PM_WIN_OFF_MARGIN)*4)+TQ_PM_WIN_OFF_MARGIN)
   #if IS_FHC_SUPPORT
#define  TQ_PM_REGBIAS_OFF_FHC   TQ_SLOT4_BEGIN//(TQ_SLOT4_BEGIN + TQ_AFC_READY)
   #endif

#define  TQ_PM2_END_2ND_HF       (TQ_PM_REGBIAS_OFF_HF+TQ_PM2_BEGIN_HF+TQ_SHORT_PMWIN_LEN_IN_IDLE+20)
   #if IS_NEW_L1D_ARCH_8R_SUPPORT
#define  CTIRQ1_READ_SLOTS_IN_2ND_HF         (1)//Read PM2 of 2nd HF in CTIRQ1
#define  IS_CHECK_8PM_DSPPROC    0
   #elif (TQ_PM2_END_2ND_HF < TQ_CTIRQ1)
#define  CTIRQ1_READ_SLOTS_IN_2ND_HF         (3)//Read PM2 of 2nd HF in CTIRQ1
#define  IS_CHECK_8PM_DSPPROC    0
   #else
#define  CTIRQ1_READ_SLOTS_IN_2ND_HF         (2)//Read PM2 of 2nd HF in the following CTIRQ1/CTIRQ2H
#define  IS_CHECK_8PM_DSPPROC    1
   #endif

   #if IS_NEW_L1D_ARCH_8R_SUPPORT
#define  CTIRQ1_READ_SLOTS                   (3)
#define  CTIRQ2_READ_SLOTS_IN_1ST_HF         (0)
#define  CTIRQ1_READ_SLOTS_IN_2ND_HF_1R7PM   (1)
   #elif IS_NEW_L1D_ARCH_6R_SUPPORT
#define  CTIRQ1_READ_SLOTS                   (4)
#define  CTIRQ2_READ_SLOTS_IN_1ST_HF         (2)
#define  CTIRQ1_READ_SLOTS_IN_2ND_HF_1R7PM   (9)
   #else
#define  CTIRQ1_READ_SLOTS                   (6)
#define  CTIRQ2_READ_SLOTS_IN_1ST_HF         (2)
#define  CTIRQ1_READ_SLOTS_IN_2ND_HF_1R7PM   (9)
   #endif

extern const    signed short  SHORT_PM_START_TQ_TABLE_CT1[4];
extern const    signed short  SHORT_PM_START_TQ_TABLE_CT2H[4];
   #if IS_FDD_DUAL_MODE_SUPPORT || IS_TDD_DUAL_MODE_SUPPORT
extern const    signed short  SHORT_PM_END_POINT_TABLE[8];
   #endif

#define  TQ_CTIRQ1_HF_MIN        (TQ_SLOT5_BEGIN+400)                                              //3781
   #if IS_NEW_L1D_ARCH_8R_SUPPORT
#define  TQ_CTIRQ1_HF            (TQ_CTIRQ1)
   #elif ( TQ_CTIRQ1_HF_MIN < TQ_CTIRQ1 )
#define  TQ_CTIRQ1_HF            (TQ_CTIRQ1)
   #else
#define  TQ_CTIRQ1_HF            (TQ_CTIRQ1_HF_MIN)
   #endif

   #if L1D_PM_1R7PM
#define  TQ_PM0_BEGIN_1R7PM      (TQ_SLOT1_BEGIN-TQ_1R7PM_PMWIN_LEN_IN_IDLE)                                          // 753 (NULL)
#define  TQ_PM1_BEGIN_1R7PM      (TQ_SLOT1_BEGIN+TQ_AFC_READY+TQ_PM_WIN_OFF_MARGIN)                                   //1145
#define  TQ_PM2_BEGIN_1R7PM      (TQ_PM1_BEGIN_1R7PM+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_AFC_READY+TQ_PM_WIN_OFF_MARGIN)    //1537
#define  TQ_PM3_BEGIN_1R7PM      (TQ_PM2_BEGIN_1R7PM+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_AFC_READY+TQ_PM_WIN_OFF_MARGIN)    //1929
#define  TQ_PM4_BEGIN_1R7PM      (TQ_PM3_BEGIN_1R7PM+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_AFC_READY+TQ_PM_WIN_OFF_MARGIN)    //2321
/*
#define  TQ_PM5_BEGIN_1R7PM      ((TQ_PM4_BEGIN_1R7PM+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_AFC_READY+8)+8)//2721
#define  TQ_PM6_BEGIN_1R7PM      (TQ_PM5_BEGIN_1R7PM+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_AFC_READY+8)    //3113
#define  TQ_PM7_BEGIN_1R7PM      (TQ_CTIRQ1-100-TQ_1R7PM_PMWIN_LEN_IN_IDLE)                        //3553
 */
#define  TQ_VALIDATE_COUNT_1R7PM (TQ_PM4_BEGIN_1R7PM+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN)                          //2457
#define  TQ_CTIRQ2_1R7PM         (TQ_PM1_BEGIN_1R7PM+TQ_1R7PM_PMWIN_LEN_IN_IDLE+250)                                           //1523
#define  TQ_PM_REGBIAS_OFF_1R7PM (((TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_AFC_READY+TQ_PM_WIN_OFF_MARGIN)*5)+TQ_PM_WIN_OFF_MARGIN)     //1968

extern const    signed short  PM_1R7PM_START_TQ_TABLE[6];
   #endif

   #if IS_FDD_DUAL_MODE_SUPPORT || IS_TDD_DUAL_MODE_SUPPORT
/*DM*/ #define TQ_CTIRQ2_FOR_PM_BEFORE_FB         (TQ_SLOT0_BEGIN+TQ_SHORT_PMWIN_LEN+100)
/*DM*/ #define TQ_VALIDATE_COUNT_FOR_PM_BEFORE_FB (TQ_CTIRQ2_FOR_PM_BEFORE_FB+300)
/*DM*/ #define TQ_DTIRQ_FOR_PM_BEFORE_FB          (TQ_VALIDATE_COUNT_FOR_PM_BEFORE_FB+30)
   #endif

   #if IS_NEW_L1D_ARCH_8R_SUPPORT
#undef   TQ_CTIRQ2_HF
#undef   TQ_CTIRQ2_1R7PM
#define  TQ_CTIRQ2_HF            TQ_CTIRQ2
#define  TQ_CTIRQ2_1R7PM         TQ_CTIRQ2
   #endif
#endif

/*---------------------------------------------------------------------------*/

/* Power offset of WB/NB RX filter depens on WB/NB filter coefficients */
/* From MT6223~, the WB/NB power offset is not a constant, and the 64-symbol NB power is reported when WB is selected */
#if IS_CHIP_MT6223
#define WBNB_RX_FILTER_POWER_OFFSET     0   /* 0.75 *64  */
#elif IS_CHIP_MT6229 || IS_CHIP_MT6268T
#define WBNB_RX_FILTER_POWER_OFFSET    88   /* 1.375*64  */
#elif IS_CHIP_MT6225_AND_LATTER_VERSION
#define WBNB_RX_FILTER_POWER_OFFSET    80   /* 1.25 *64  */
#endif

/*---------------------------------------------------------------------------*/

#if IS_FHC_SUPPORT
#define FHC_PROC_NONE                  0x00
#define FHC_PROC_DTS_AFC_WB            0x01
#define FHC_PROC_DTS_AFC_NB_SYNC       0x02
#define FHC_PROC_DTS_START             0x04
#define FHC_PROC_DTS_PL                0x10
#define FHC_PROC_UTS_PCL               0x20
#define FHC_PROC_UTS_DAC               0x40
   #if IS_32K_CRYSTAL_REMOVAL_SUPPORT
#define FHC_PROC_DTS_DCXO_LPM          0x80
   #endif
   #if IS_TX_GAIN_RF_CALIBRATION_SUPPORT
#define FHC_PROC_UTS_GAIN_RF_IDX       0x100
   #endif
/*
   #if IS_GPRS
#define FHC_PM_SLOT_FOR_PL             6
   #endif
   #if IS_GSM
#define FHC_PM_SLOT_FOR_PL             4
   #endif
*/
#define FHC_PM_SLOT_FOR_PL             4

#define FHC_SB_FAIL_THRESHOLD          255
#define FHC_PM_SLOT_FOR_FCCH           4
   #if IS_DSP_ARCHITECTURE_V4_SUPPORT
#define FHC_SB_SNR_THRESHOLD           10
   #else
#define FHC_SB_SNR_THRESHOLD          (-1)
   #endif
#endif

/*---------------------------------------------------------------------------*/

#if IS_DLIF_CHIP || IS_DCR_IN_DLIF_CHIP
#define NB_FIR_4DC_NORMAL_IFSEL0       0x7F7F   //( -1, -1)
   #if (IS_CHIP_MT6256_S00 || IS_CHIP_MT6251_S00) && defined(L1D_TEST)
#define WB_FIR_4DC_NORMAL_IFSEL0       0x7C7C   //( -4, -4)
   #else
#define WB_FIR_4DC_NORMAL_IFSEL0       0x7F7F   //( -1, -1)
   #endif

/*
#define NB_FIR_4DC_NORMAL_IFSEL1       0x7F01   //( -1,  1), no-use, HW do complex-conjugate by itself
#define WB_FIR_4DC_NORMAL_IFSEL1       0x7C04   //( -4,  4), no-use, HW do complex-conjugate by itself
 */
   #if IS_CHIP_MT6256_S00 || IS_CHIP_MT6251
#define NB_FIR_4DC_FB_POWRON_IFSEL0    0x6A16   //(-22, 22)
#define WB_FIR_4DC_FB_POWRON_IFSEL0    0x2929   //( 41, 41)

#define NB_FIR_4DC_FB_POWRON_IFSEL1    0x1212   //( 18, 18)
#define WB_FIR_4DC_FB_POWRON_IFSEL1    0x2957   //( 41,-41)
   #endif

   #if IS_CHIP_MT6256_S00
   #elif IS_CHIP_MT6256 || IS_CHIP_MT6255 || IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
      #if defined(L1D_TEST)
#define DCOC_QB_RX_FENA_2_FSYNC        32
         #if IS_BFE_RX_TYPE_NB_EN_SUPPORT
#define CIC1_DLY_NB                    26  // filter CIC1 group delay
#define MAX_ALLOWED_OFFSET_NB           4  // max value for current data does NOT overlap the previous slot
#define FIR3_DLY                       20  // filter FIR3 group delay
#define CIC1_DLY                       30  // filter CIC1 group delay
#define MAX_ALLOWED_OFFSET              0  // max value for current data does NOT overlap the previous slot
         #else
#define CIC1_DLY                       26  // filter CIC1 group delay
#define MAX_ALLOWED_OFFSET              4  // max value for current data does NOT overlap the previous slot
#define FIR3_DLY                       20  // filter FIR3 group delay
         #endif
      #elif IS_BFE_RX_TYPE_NB_EN_SUPPORT
#define DCOC_QB_RX_FENA_2_FSYNC        48
#define CIC1_DLY_NB                    26  // filter CIC1 group delay
#define MAX_ALLOWED_OFFSET_NB          15  // max value for current data does NOT overlap the previous slot
#define FIR3_DLY                       20  // filter FIR3 group delay
#define CIC1_DLY                       38  // filter CIC1 group delay
#define MAX_ALLOWED_OFFSET             10  // max value for current data does NOT overlap the previous slot
      #elif IS_RX_DCOC_ADVANCED_SUPPORT
#define DCOC_QB_RX_FENA_2_FSYNC        48
#define CIC1_DLY                       38  // filter CIC1 group delay
#define MAX_ALLOWED_OFFSET             10  // max value for current data does NOT overlap the previous slot
#define FIR3_DLY                       20  // filter FIR3 group delay
      #else
#define DCOC_QB_RX_FENA_2_FSYNC        48
#define CIC1_DLY                       26  // filter CIC1 group delay
#define MAX_ALLOWED_OFFSET             15  // max value for current data does NOT overlap the previous slot
#define FIR3_DLY                       20  // filter FIR3 group delay
      #endif
      #if IS_BFE_RX_TYPE_NB_EN_SUPPORT
// for RX_TIME_CON0
#define RX_DCOC_STR_NB                 (DCOC_QB_RX_FENA_2_FSYNC-CIC1_DLY_NB)  // C1 for NB
#define RX_NULL_STR_NB                 (RX_DCOC_STR_NB-MAX_ALLOWED_OFFSET_NB) // C3 for NB
// for RX_TIME_CON1
#define RX_IRCMPN_SW                   (DCOC_QB_RX_FENA_2_FSYNC-FIR3_DLY)     // C2
// for RX_TIME_CON2
#define RX_DCOC_STR                    (DCOC_QB_RX_FENA_2_FSYNC-CIC1_DLY)     // C1 for non-NB
#define RX_NULL_STR                    (RX_DCOC_STR-MAX_ALLOWED_OFFSET)       // C3 for non-NB
      #else
// for RX_TIME_CON0
#define RX_DCOC_STR                    (DCOC_QB_RX_FENA_2_FSYNC-CIC1_DLY)     // C1
#define RX_NULL_STR                    (RX_DCOC_STR-MAX_ALLOWED_OFFSET)       // C3
// for RX_TIME_CON1
#define RX_IRCMPN_SW                   (DCOC_QB_RX_FENA_2_FSYNC-FIR3_DLY)     // C2
      #endif
   #endif

/*...........................................................................*/
   #if (IS_CHIP_MT6256_S00 || IS_CHIP_MT6251_S00) && defined(L1D_TEST)
#define THR_ITD_DEFAULT                0x96     //150
   #else
#define THR_ITD_DEFAULT                0xA0     //160
   #endif

   #if defined(L1D_TEST)
#define TX_CNT_TGT_DEFAULT             158
   #elif IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define TX_BB_GROUP_DELAY              10
#define TX_CNT_TGT_DEFAULT             (QB_TX_FENA_2_FSYNC-(QB_TON_2_FSYNC-TX_BB_GROUP_DELAY))
   #elif IS_CHIP_MT6583_MD2
#define TX_CNT_TGT_DEFAULT             QB_BFE_TXCOMP_HYS
   #else
#define TX_CNT_TGT_DEFAULT             36       //140
   #endif

#define PM_DLY_DEFAULT                 0
   #if IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define AM_DLY_DEFAULT                 1
   #elif IS_CHIP_MT6583_MD2
#define AM_DLY_DEFAULT                 0
   #endif
#define P2X_SCALE_DEFAULT              0x3A     //58

   #if IS_CHIP_MT6256_S00 || IS_CHIP_MT6251
#define TX_CNT_TGT_SW_DEFAULT          0
   #else
#define TX_CNT_TGT_SW_DEFAULT          TX_CNT_TGT_DEFAULT  //For normal mode, TX_CNT_TGT_SW_DEFAULT should be equal to TX_CNT_TGT_DEFAULT
   #endif                                                  //For loopback mode, we set TX_CNT_TGT_SW_DEFAULT=146 in L1DTest_Init2()

#define TX_CON0_DEFAULT                0
#define TX_CON1_DEFAULT                ( ((PM_DLY_DEFAULT&0xF)<<8)|TX_CNT_TGT_DEFAULT )

   #if IS_CHIP_MT6256_S00 || IS_CHIP_MT6251
#define RX_CON3_DEFAULT                (  THR_ITD_DEFAULT<<8  )
#define TX_PWR_DEFAULT                 ( (TX_CNT_TGT_SW_DEFAULT&0xFF)<<8 )
   #else
#define TX_CON2_DEFAULT                ( (TX_CNT_TGT_SW_DEFAULT&0xFF)<<8 )
   #endif
#endif

/*---------------------------------------------------------------------------*/

// MT6573E1, MD2G sleep ECO for pause abort on preclock_off rising edge
#if IS_CHIP_MT6573
#define EVTENA0_SLOW_EN_SEL     (0x1<<4)
#else
#define EVTENA0_SLOW_EN_SEL     (0)
#endif

/*---------------------------------------------------------------------------*/

#if IS_TX_POWER_CONTROL_SUPPORT
   #if IS_TXPC_CL_AUXADC_SUPPORT
extern       short   scan_qb;
extern CONST short   TQ_TxSampleOffsetGMSK;
      #if IS_EPSK_TX_SUPPORT
extern CONST short   TQ_TxSampleOffsetEPSK;
      #endif
   #endif
   #if IS_TXPC_OL_BSI_SUPPORT || IS_TXPC_OL_AUXADC_SUPPORT
extern CONST short   txpc_epsk_tp_slope_lb;
extern CONST short   txpc_epsk_tp_slope_hb;
   #endif
extern const char    temp_adc_cal_type;
#endif

/*---------------------------------------------------------------------------*/
/* RX LNA calbiration */
#if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
extern const char    is_lna_calibration;
#endif

/*---------------------------------------------------------------------------*/

#if IS_DYNAMIC_G_E_TXWIN_POSITION_SUPPORT || IS_DYNAMIC_G_E_TXWIN_POSITION_SUPPORT_V2
extern CONST signed short TQ_EPSK_TX_delay;
#endif

/*---------------------------------------------------------------------------*/

#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT
#define RFDEF  (signed short)0xABCD
#define URFDEF (unsigned short)0xABCD

typedef  struct
{
              int start;                         // the special pattern of start position
              int version;                       // Struct Version ID
              int RF_Type;                       // RF type
             char is_data_update;                // default is false, and will be changed  as true after tool update
     signed short xPDATA_TABLE[5][2][5];
     signed short xPDATA_TABLE3[5][3][3];
     signed short xRX_START_TQ_TABLE[8];
     signed short xRX_END_TQ_TABLE[5];
     signed short xRX_MIDDLE_TQ_TABLE[3];
     signed short xRX_MIDDLE_TQ_TABLE2[2];
     signed short xTX_START_TQ_TABLE[8];
     signed short xTX_START_TQ_TABLE2[1];
     signed short xTX_START_TQ_TABLE3[1];
     signed short xTX_END_TQ_TABLE[6];
     signed short xTX_MIDDLE_TQ_TABLE[4];
     signed short xTX_MIDDLE_TQ_TABLE2[2][4];
     signed short xPM_START_TQ_TABLE[7];
     signed short xPM_TQ_TABLE[10];
     signed short xPM_IN_IDLE_TQ_TABLE[10];
     signed short xPM_1R7PM_TQ_TABLE[10];
     signed short xFSWIN_STOP_DATA_TABLE[9];
   unsigned short xtxios_pcl_tab[2][2][5];
   unsigned short xtxitc_pcl_tab[2][2][5];
   unsigned short xtxmod_gc_tab[2][2][5];
             long XO_CapID;                      // L1 Rf data
              int end1;                          // the special pattern of end1 position
     signed short xPDATA_GMSK;
     signed short xPDATA_8PSK;
     signed short xGSM850_GSM900_SWAP;
     signed short xDCS1800_PCS1900_SWAP;
              int xBAT_VOLTAGE_SAMPLE_PERIOD;
              int xBAT_VOLTAGE_AVERAGE_COUNT;
              int xBAT_TEMPERATURE_SAMPLE_PERIOD;
              int xBAT_TEMPERATURE_AVERAGE_COUNT;
              int xBAT_LOW_VOLTAGE;
              int xBAT_HIGH_VOLTAGE;
              int xBAT_LOW_TEMPERATURE;
              int xBAT_HIGH_TEMPERATURE;
              int end2;                          // the special pattern of end2 position
} sRF_TABLE;

extern sRF_TABLE l1_rf_table;

#endif

/*-------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------- TDD Dual Mode Begin -----------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------*/
#if IS_TDD_DUAL_MODE_SUPPORT
/*TDD*/ #define  TQ_CTIRQ2_HF2_TD_DM           TQ_VALIDATE-100                                       // 4839
/* The tming margin left for DSP PM decoded is not enough. 5000us-675us*2 = 3954QB.
   If 2 PM (at max 2PM created in a TD slot gap) created 3954+2*(256+128+8)= 4738QB.
   4738QB+100QB = 4838QB ~= 4939-100 to read PM                                                   */
/*TDD*/ extern const signed short TD_DM_PM_BEGIN_POINT_TABLE[8];
/*TDD*/ extern const signed short TD_DM_PM_END_POINT_TABLE[8];
/*TDD*/ extern CONST signed short TD_DM_PM_TQ_TABLE[11];
   #if IS_DSP_ENHANCE_SHORT_FBSB_SUPPORT
/*TDD*/ #define FB_ENHANCE_TQ_LEN_TABLE_SIZE 4
/*TDD*/ extern CONST signed short FB_ENHANCE_TQ_LEN_TABLE[FB_ENHANCE_TQ_LEN_TABLE_SIZE];
/*TDD*/ extern CONST signed short FB_BURST_SCALOR_TABLE[FB_ENHANCE_TQ_LEN_TABLE_SIZE];
      #if IS_DSP_SHORT_FBSB_V2
/*TDD*/ extern CONST signed short FB_BURST_RESOLUTION_TABLE[FB_ENHANCE_TQ_LEN_TABLE_SIZE];
      #endif
/*TDD*/ #define SB_EXTEND_TQ_LEN_TABLE_SIZE 3
/*TDD*/ extern CONST signed short SB_EXTEND_TQ_LEN_TABLE[SB_EXTEND_TQ_LEN_TABLE_SIZE];
/*TDD*/ extern CONST signed short SB_BURST_SCALOR_TABLE[SB_EXTEND_TQ_LEN_TABLE_SIZE];
      #if IS_DSP_SHORT_FBSB_V2
/*TDD*/ extern CONST signed short SB_BURST_RESOLUTION_TABLE[SB_EXTEND_TQ_LEN_TABLE_SIZE];
      #endif
   #endif
/*TDD*/ extern unsigned long TD_AFC_switch_GPIO_pin;
/*TDD*/ extern signed   long TD_AFC_switch_GPIO_status;
#endif
/*-------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------- TDD Dual Mode End -------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------*/

#endif /*End of "#ifndef _L1D_DATA_H_" */

