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
 *   l1d_data.c
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
 * $Revision:   1.63  $
 * $Modtime:   Aug 02 2005 13:42:22  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1/l1d/l1d_data.c-arc  $
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
 * 04 09 2013 ola.lee
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
 * 07 24 2012 cs.wu
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
 * 11 29 2011 th.yeh
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
 * 11 10 2011 cs.wu
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
 * 07 05 2011 cs.wu
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
 * removed!
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
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Check in PLL reset.
 *
 * 02 16 2011 cs.wu
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
 * [L1D][Modify] Check in MPLL_FLT as MPLL FH switch
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
 * Add two functions and one table
 * intx L1D_Cal_PM_Count_DM( intx ebit_duration );
 * intx L1D_Cal_FB_Slot_Length_DM(intx ebit_duration);
 * SHORT_PM_END_POINT_TABLE[]
 *
 * removed!
 * removed!
 * Remove TQ_SR1 in TQ_FBWIN_START_OFFSET definition due to the additional delay will cause FB process exceeds 3G gap
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Add const unsigned char  gsm_err_det_id = GSM_ERR_DET_ID;
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
 * Modify the Wide band RX filter parameter
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
 * Modify the NB FIR parameter of MT6229
 *
 * removed!
 * removed!
 *
 *
 *    Rev 1.63   Aug 02 2005 13:56:02   mtk00361
 * 1.Change the type of USE_3_SUBSTAGES_FB_STAGE1 from bool to unsigned char
 * 2.Add prototype in l1d_data.h
 * Resolution for 12100: [L1D][Modify]Disable 3-substages FB stage 1 for X'tal from chip MT6229 and latter version
 *
 *    Rev 1.62   Jul 28 2005 16:31:28   mtk00361
 * Disable 3-substages FB stage 1 for X'tal from chip MT6229 and latter version
 *
 *    Rev 1.61   Jun 21 2005 09:53:08   mtk00939
 *  [L1][Modify]Add compile option for MT6227
 *
 *    Rev 1.60   Jun 07 2005 21:06:24   mtk00939
 * [L1][Modify]Add compile option for MT6228
 *
 *    Rev 1.59   May 23 2005 18:10:54   mtk00240
 *  Let VCXO compile option independent with L1D internal code (Macro TQ_AFC_CHARGE_IN_IDLE --> global variable  TQ_Afc_ChargeInIdle
 * Resolution for 11194: [L1D][Enhance] Let VCXO compile option independent with L1D internal code
 *
 *    Rev 1.58   May 17 2005 00:34:18   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.57   May 16 2005 11:46:22   mtk00240
 * Support 22 BPI setting & current sense PA
 * Resolution for 11091: [L1D][New Feature] Support 22 BPI setting & current sense PA
 *
 *    Rev 1.56   Jan 18 2005 00:37:54   BM
 * append new line in W05.04
 *
 *    Rev 1.55   Dec 27 2004 11:43:42   mtk00939
 * Due to L1D extracted the tables and variables for L1D internal used from l1d_data.c and l1d_data.h into l1d_internal_data.c & l1d_internal_data.h
 * Resolution for 9276: [L1D][modify]Due to L1D extracted the tables and variables for L1D internal used from l1d_data.c and l1d_data.h into l1d_internal_data.c & l1d_internal_data.h
 *
 *    Rev 1.54   Oct 18 2004 15:36:14   mtk00703
 * Modify the initial value of BBTXParameters due to that the structure of BBTXParameters has been modified.
 * Resolution for 8290: [L1][NewFeature]Calibration of TXOffsetI/Q, TrimI/Q and TXgain on META mdoe
 *
 *    Rev 1.53   Sep 22 2004 10:27:30   mtk00240
 * Due to the FIR coeff. is different between MT6218B & mt6217, so add compile option IS_CHIP_M6217 and redefine the FIR coeff. for mt6217
 * Resolution for 7470: [L1D] Add mt6217 & mt6228 compile option support
 *
 *    Rev 1.52   Jun 10 2004 14:48:02   mtk00240
 * Support phone used mt6129C/D with VCXO
 * Resolution for 6006: [L1D][Enhance] Support phone used mt6129C/D with VCXO
 *
 *    Rev 1.51   May 31 2004 11:52:10   mtk00585
 * [L1D][Modify] Add TX Swing Auto Calibration.
 * Resolution for 5743: [L1D][Modify] Add TX Swing Auto Calibration.
 *
 *    Rev 1.50   May 21 2004 14:53:30   mtk00240
 * Support mt6218B_FN & mt6129_BV chip (Also remove BFE seting from customer config)
 * Resolution for 5550: [L1D][Enahnce] Support mt6218B_FN & mt6129_BV chip (Also remove BFE seting from customer config)
 *
 *    Rev 1.49   Mar 12 2004 11:55:16   mtk00489
 * [L1D][Enhanced]L1D add APC voltage/temperature compensation and add BBTXParameter for META
 * Resolution for 4233: [L1D][Enhanced]L1D add APC voltage/temperature compensation and add BBTXParameter for META
 *
 *    Rev 1.48   Feb 13 2004 23:53:10   mtk00489
 * [L1D][Enhanced]1.adjust L1D DL DTX threshold to improve DTX detection rate 2.enhanced Dummy burst detection rate 3.change RX ADC to 2.24V for MT61xx 4.modify LP2 code to pass MT6218BECO3 validation 5.modify new interface for dll(CHIP_VER)
 * Resolution for 3912: [L1D][Enhanced]1.adjust L1D DL DTX threshold to improve DTX detection rate 2.enhanced Dummy burst detection rate 3.change RX ADC to 2.24V for MT61xx 4.modify LP2 code to pass MT6218BECO3 validation 5.modify new interface for dll(CHIP_VER)
 *
 *    Rev 1.47   Jan 18 2004 14:17:34   mtk00585
 * [L1D][Modify] Add A9_SDCCH_New2 Case
 * Resolution for 3750: [L1D][Modify] Add A9_SDCCH_New2 Case
 *
 *    Rev 1.46   Oct 25 2003 15:44:14   mtk00240
 * Change some compile option
 * #if  (IS_CHIP_MT6218)||(IS_CHIP_MT6219)
 * to
 * #if  IS_CHIP_MT6218_AND_LATTER_VERSION
 * Resolution for 3196: [L1D][Enhance] Add code to support mt6218B
 *
 *    Rev 1.45   Oct 23 2003 14:20:54   mtk00585
 * [L1D][Add] L1D Add code for MT6129B RF Driver.
 * Resolution for 3177: [L1D][Add] L1D Add code for MT6129B RF Driver.
 *
 *    Rev 1.44   Oct 01 2003 15:17:30   mtk00585
 * [L1D][Modify]L1D modify code for MT6219
 * Resolution for 3037: [L1D][Modify]L1D modify code for MT6219
 *
 *    Rev 1.43   Sep 22 2003 10:50:38   mtk00585
 * [L1D][Modify]We should set TxPropagationDelay to 0 when we do L1 Simulation.
 * Resolution for 2937: [L1D][Modify]We should set TxPropagationDelay to 0 when we do L1 Simulation.
 *
 *    Rev 1.42   Sep 15 2003 09:30:42   mtk00240
 *  Compensate the shifted 1 bit by twice the RX FIR coefficients.
 * Resolution for 2830: [L1D][Fix Bug] Fix the bug that the input voltage and DSP set point dismatch on mt6218
 *
 *    Rev 1.41   Aug 08 2003 12:26:22   mtk00489
 * [L1D][Modify]ONLY apply bb_tx_autocal when we get enough samples to evalute it, so L1D apply bb_tx_autocal for 1. All RF except AERO 2.MT6205B_AND_LATTER_VERSION
 * Resolution for 2472: [L1D][Modify]ONLY apply bb_tx_autocal when we get enough samples to evalute it, so L1D apply bb_tx_autocal for 1. All RF except AERO 2.MT6205B_AND_LATTER_VERSION
 *
 *    Rev 1.40   Jun 06 2003 18:42:44   mtk00489
 * [L1D][Enhanced]L1D modify for custom folder/files. from now on, L1D only knows the RF chip name(not board name) 1.add l1d_custom_rf.h(from l1d_rf.h) 2.add 12196.c(from 12190.c) 3.move m12193.c to custom directory 4.modify l1s.lis 5.files include l1d_rf.h should also include l1d_custom_rf.h 6.change l1d_cid.h
 * Resolution for 1961: [L1D][Enhanced]L1D modify for custom folder/files. from now on, L1D only knows the RF chip name(not board name) 1.add l1d_custom_rf.h(from l1d_rf.h) 2.add 12196.c(from 12190.c) 3.move m12193.c to custom directory 4.modify l1s.lis 5.files
 *
 *    Rev 1.39   May 26 2003 15:26:20   mtk00240
 *  By OS request, All data and code in internal RAM shall be declaration.
 * Resolution for 1861: [L1D][Update] Add internal RAM using declaration
 *
 *    Rev 1.38   Apr 30 2003 20:41:08   mtk00489
 * [L1D][Enhanced]L1D fills chip specific registers to support MT6205B - a.RX_CON / AFC_CALIBIAS b.RXADC_NoiseFlow c.BBTX_GAIN
 * Resolution for 1693: [L1D][Enhanced]L1D fills chip specific registers to support MT6205B.
 *
 *    Rev 1.37   Jan 30 2003 16:23:22   mtk00489
 * modify BBTX_GAIN and RX_GAIN_SE definition
 * Resolution for 637: modify BBTX_GAIN and RX_GAIN_SE definition
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
 *    Rev 1.34   17 Jan 2003 14:47:30   mtk00240
 * L1D add global data FrequcyBias to compensate frequency bias.
 * Resolution for 628: L1D add global data FrequcyBias to compensate frequency bias.
 *
 *    Rev 1.33   08 Jan 2003 12:34:18   mtk00240
 * L1D initial the Ramp profile file when L1D initialize
 * Resolution for 619: L1D initial the Ramp profile file when L1D initialize
 *
 *    Rev 1.32   17 Dec 2002 09:19:28   mtk00240
 * (1) Change RX timing base to 156.25/156.25/156.25/156.25
 * (2) L1D switch APC event 3,4 and 5,6 when TX slot 3,4 are applied
 * Resolution for 592: Change RX timing base to 156.25/156.25/156.25/156.25
 * Resolution for 593: L1D switch APC event 3,4 and 5,6 when TX slot 3,4 are applied
 *
 *    Rev 1.31   07 Dec 2002 14:17:02   mtk00240
 * L1D perform 1 PM under GPRS RRRR_T__ constellation
 * Resolution for 583: L1D perform 1 PM under GPRS RRRR_T__ constellation
 *
 *    Rev 1.30   06 Dec 2002 20:06:28   mtk00240
 * L1D perform 1 PM under GPRS RRRR_T__ constellation
 * Resolution for 583: L1D perform 1 PM under GPRS RRRR_T__ constellation
 *
 *    Rev 1.29   05 Dec 2002 10:50:24   mtk00240
 * L1D add code to support MT6218
 * Resolution for 581: L1D add code to support MT6218
 *
 *    Rev 1.28   12 Nov 2002 12:28:36   mtk00240
 * L1D add APC enable register setting for MT6218
 * Resolution for 558: L1D add APC enable register setting for MT6218
 *
 *    Rev 1.27   11 Sep 2002 12:08:00   mtk00240
 * (1) All NB RX window is 156 bit
 * (2) All NB TX window is 148 bit
 * (3) change all slot boundary to 157/156/156/156
 * Resolution for 457: L1D change slot length to 157bit,156bit,156bit,156bit
 *
 *    Rev 1.26   22 Aug 2002 13:16:20   mtk00240
 * L1D modfied RX state machine to support GPRS AGC module
 * Resolution for 459: L1D modfied RX state machine to support GPRS AGC module
 *
 *    Rev 1.25   29 Jul 2002 17:48:42   mtk00240
 * L1D remove code about initializing AFC data
 * Resolution for 442: L1D remove code about initializing AFC data
 *
 *    Rev 1.24   23 Jul 2002 19:52:02   mtk00240
 * MT6205 active enable flags when writing corresponding events, so L1D disbale setting ENABLE register for MT6205
 * Resolution for 437: L1D modified code for MT6205
 *
 *    Rev 1.23   23 Jul 2002 11:48:40   mtk00240
 * L1D add 2 global variable for sleep mode
 * Resolution for 438: L1D add 2 global variable for sleep mode
 *
 *    Rev 1.22   18 Jul 2002 22:46:20   mtk00240
 * Prevent the compile warnings in simulation environment
 * Resolution for 437: L1D modified code for MT6205
 *
 *    Rev 1.21   18 Jul 2002 16:53:32   mtk00240
 * L1D modified code for MT6205
 * Resolution for 437: L1D modified code for MT6205
 *
 *    Rev 1.20   18 Jul 2002 16:49:10   mtk00240
 * L1D modified code for MT6205
 * (1) change BPI setting (l1d_rf.h)
 * (2) Fix APC Scale factor (m12170.c)
 * (3) disable IDN_SEL and GPIO mode setting (m12190.c)
 * (4) change FIR coefficient type (l1d_data.c,l1d_data.h)
 * Resolution for 437: L1D modified code for MT6205
 *
 *    Rev 1.19   10 Jul 2002 15:47:08   mtk00240
 * Change Variable Name RoundTripDelay to TXPropogationDelay
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.17   03 Jul 2002 21:43:46   mtk00240
 * L1D extrract RF setting code to let customer setup new RF module more easily
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.16   21 May 2002 13:26:16   mtk00240
 * Let Bright4 lock the frequency at the right time
 * Resolution for 356: L1D add some code to operate Bright4 RF propertly
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
 *    Rev 1.12   12 Apr 2002 21:27:10   mtk00240
 * L1D add new initialized value for RF
 * Resolution for 359: L1D add new initialized value for RF
 *
 *    Rev 1.11   03 Apr 2002 19:30:28   mtk00240
 * Fix some code to support Bright4 properly
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 *
 *    Rev 1.10   01 Apr 2002 12:24:10   mtk00240
 * L1D modified register's definition for DSP main v10
 * Resolution for 347: L1D modified register's definition for DSP F/W main v10
 *
 *    Rev 1.9   30 Mar 2002 13:04:10   mtk00240
 * 1) Modify L1D code to support both Bright2 & Bright4 RF board
 * 2) L1D add Audio interface to support Voice Memo & Melody
 * 3) Add L1D code to support RAM-based chip
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 * Resolution for 342: L1D add Audio interface to support Voice Memo & Melody
 * Resolution for 343: Add L1D code to support RAM-based chip
 *
 *    Rev 1.8   18 Mar 2002 21:25:58   mtk00240
 * Due to the issue of none duble-buffered AFC data when SB window is after CTIRQ1. L1D change the methode of setting negihbour cell AFC.
 * Resolution for 335: L1D avoid the issue of none duble-buffered AFC data
 *
 *    Rev 1.7   11 Mar 2002 13:35:34   mtk00240
 * instead TAB characters of Space characters in L1D code .
 * Resolution for 318: Shine change TAB character to Space charter
 *
 *    Rev 1.6   03 Mar 2002 23:06:30   mtk00240
 * L1D add code to setup APC DC offset
 * Resolution for 305: L1D add code to setup APC DC offset
 *
 *    Rev 1.5   26 Feb 2002 10:51:50   mtk00240
 * L1D Change PM position for CTIRQ1 at slot 5
 * Resolution for 302: L1D Change PM position for CTIRQ1 at slot 5
 *
 *    Rev 1.4   17 Feb 2002 20:15:30   mtk00240
 * Update L1D code for solving HandOver test item
 * Resolution for 275: Update L1D code for solving HandOver test item
 *
 *    Rev 1.3   21 Jan 2002 21:15:06   mtk00240
 * Add code to cancel the round trip delay of TX window in L1D
 * Resolution for 242: Add code to cancel the round trip delay of TX window
 *
 *    Rev 1.2   08 Jan 2002 17:10:54   mtk00240
 * Change TQ_BULON, TQ_BULOFF, TQ_BDLON.
 * Let IQ Swap can be change on running time.
 * Resolution for 203: Modify some RF parameters in L1D
 *
 *    Rev 1.1   03 Jan 2002 12:19:42   mtk00240
 * Merge B.L1.20011225 to Main V1.XX
 *
 *    Rev 1.0   Dec 25 2001 14:40:20   admin
 * Initial revision.
 *
 *******************************************************************************/

#include  "l1d_cid.h"
#include  "l1d_loc_def.h"
#include  "l1d_reg.h"
#include  "l1d_data.h"
#include  "l1d_custom_rf.h"
#include  "l1d_rf.h"
#include  "m12190.h"

/*...........................................................................*/
#if   (INTERNDATA_L1D_DATA==INTERN_FULL)
#define IS_INTERNDATA_LEVEL1     1
#else
#define IS_INTERNDATA_LEVEL1     0
#endif
/*...........................................................................*/

/* ========================================================================= */

/* General timing check for slot 0 RX window */
#if TQ_SR0>TQ_AFC_READY
#error "TQ_SR0 should not be larger than TQ_AFC_READY"
#endif

#if TQ_SR1>TQ_AFC_READY
#error "TQ_SR1 should not be larger than TQ_AFC_READY"
#endif

#if TQ_SR2>TQ_AFC_READY
#error "TQ_SR2 should not be larger than TQ_AFC_READY"
#endif

#if TQ_PR1>TQ_AFC_READY
#error "TQ_PR1 should not be larger than TQ_AFC_READY"
#endif

#if TQ_PR2>TQ_AFC_READY
#error "TQ_PR2 should not be larger than TQ_AFC_READY"
#endif

#if TQ_PR2B>TQ_AFC_READY
#error "TQ_PR2B should not be larger than TQ_AFC_READY"
#endif

/* ========================================================================= */

#if IS_BSI_SX0_SUPPORT && (QB_SR0!=(-10000))
#define  TQ_FBWIN_START_OFFSET   (TQ_SR0+TQ_SBWIN_DSP_EXTEND1+TQ_BURST_HEAD_GUARD)
#else
#define  TQ_FBWIN_START_OFFSET   (TQ_SR1+TQ_SBWIN_DSP_EXTEND1+TQ_BURST_HEAD_GUARD)
#endif
#define  TQ_FSWIN_DTIRQ_DELAY    ((TQ_SLOT_LEN-TQ_FBWIN_START_OFFSET-TQ_SBWIN_DSP_EXTEND2)/2)

#if IS_BSI_SX0_SUPPORT
   #if (QB_SR0!=(-10000)) && (QB_SR0 < QB_SR1)
#error "QB_SR0 should be larger than QB_SR1"
   #endif

   #if (QB_ST0!=(-10000)) && (QB_ST0 < QB_ST1)
#error "QB_ST0 should be larger than QB_ST1"
   #endif

   #if !defined(SX0_DATA_COUNT)
#error "SX0_DATA_COUNT should be defined in l1d_rf.h of specific RF driver, use 0 if no data"
#error "L1D_RF_SetSData_SR0(), L1D_RF_SetSData_ST0() should be defined in m12195.c of specific RF driver"
   #endif
#endif

/* ========================================================================= */

#if IS_DFM_RF_TIMING_CHECK_SUPPORT
/* RF-BFE timing constraints at RX on */
   #if IS_RF_MT6252RF || IS_RF_MT6162 || IS_RF_MT6163
      #if (QB_SR2<=QB_RX_FENA_2_FSYNC)
#error "QB_SR2 should be larger than QB_RX_FENA_2_FSYNC"
      #endif
   #elif IS_RF_MT6251RF || IS_RF_MT6256RF || IS_RF_MT6255RF || IS_RF_MT6250RF
      #if (QB_SR2<=QB_RX_FENA_2_FSYNC+11)
#error "QB_SR2 should be 11QB larger than QB_RX_FENA_2_FSYNC"
      #endif
   #elif IS_RF_MT6280RF || IS_RF_MT6169
      #if (QB_SR2<=QB_RX_FENA_2_FSYNC+7)
#error "QB_SR2 should be 7QB larger than QB_RX_FENA_2_FSYNC"
      #endif
   #elif IS_RF_MT6166 || IS_RF_MT6165
      #if (QB_SR2<=38+6) //38qb is for RX BFE group delay, and 6qb is for RX gain settling
#error "QB_SR2 should be larger than 44QB for RX BFE group delay"
      #endif
   #else
#error "please add the timing constraint of QB_SR2 in l1d_data.c"
   #endif

/* RF-BFE timing constraints at RX off */
   #if IS_RF_MT6252RF || IS_RF_MT6162 || IS_RF_MT6163
      #if (QB_SR3<QB_RX_FSYNC_2_FENA)
#error "QB_SR3 should be larger than or equal to QB_RX_FSYNC_2_FENA"
      #endif
   #elif IS_RF_MT6251RF || IS_RF_MT6256RF || IS_RF_MT6255RF || IS_RF_MT6250RF
      #if (QB_SR3<=QB_RX_FSYNC_2_FENA)
#error "QB_SR3 should be larger than QB_RX_FSYNC_2_FENA"
      #endif
   #elif IS_RF_MT6280RF || IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165
      #if (QB_SR3<=QB_RX_FSYNC_2_FENA+1)
#error "QB_SR3 should be 1QB larger than QB_RX_FSYNC_2_FENA"
      #endif
   #else
#error "please add the timing constraint of QB_SR3 in l1d_data.c"
   #endif

/* RF-BFE timing constraints at TX on */
   #if IS_RF_MT6252RF || IS_RF_MT6162 || IS_RF_MT6163
      #if (QB_ST2B<=QB_TX_FENA_2_FSYNC)
#error "QB_ST2B should be larger than QB_TX_FENA_2_FSYNC"
      #endif
   #elif IS_RF_MT6256RF || IS_RF_MT6255RF || IS_RF_MT6250RF
      #if (QB_ST2B<=QB_TX_FENA_2_FSYNC+11)
#error "QB_ST2B should be 11QB larger than QB_TX_FENA_2_FSYNC"
      #endif
   #elif IS_RF_MT6251RF
      #if (QB_ST2<=QB_TX_FENA_2_FSYNC+17)
#error "QB_ST2 should be 17QB larger than QB_TX_FENA_2_FSYNC"
      #endif
   #elif IS_RF_MT6280RF || IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165
      #if (QB_ST2B<=QB_TX_FENA_2_FSYNC+7)
#error "QB_ST2B should be 7QB larger than QB_TX_FENA_2_FSYNC"
      #endif
   #else
#error "please add the timing constraint of QB_ST2B/QB_ST2 in l1d_data.c"
   #endif

/* RF-BFE timing constraints at TX off */
   #if IS_RF_MT6252RF || IS_RF_MT6251RF || IS_RF_MT6256RF || IS_RF_MT6255RF
      #if (QB_ST3<=QB_TX_FSYNC_2_FENA)
#error "QB_ST3 should be larger than QB_TX_FSYNC_2_FENA"
      #endif
   #elif IS_RF_MT6250RF || IS_RF_MT6162 || IS_RF_MT6163
      #if (QB_ST3<=QB_TX_FSYNC_2_FENA+10)
#error "QB_ST3 should be 10QB larger than QB_TX_FSYNC_2_FENA"
      #endif
   #elif IS_RF_MT6280RF || IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165
      #if (QB_ST3<=QB_TX_FSYNC_2_FENA+6)
#error "QB_ST3 should be 6QB larger than QB_TX_FSYNC_2_FENA"
      #endif
   #else
#error "please add the timing constraint of QB_ST3 in l1d_data.c"
   #endif
#endif /* IS_DFM_RF_TIMING_CHECK_SUPPORT */

/* ========================================================================= */

/*IS_CONTINUOUS_TDMA_EVENT_TIMING_CHECK_SUPPORT: the timing difference of two continuous TDMA events should be larger than 1QB  */
#if IS_CONTINUOUS_TDMA_EVENT_TIMING_CHECK_SUPPORT
   #if ((QB_PT2M1_G8-QB_PT2M2_G8)<=1)
#error "QB_PT2M1_G8 should be larger than (QB_PT2M2_G8+1)"
   #endif
   #if ((QB_PT2M2_G8-QB_PT2M3_G8)<=1)
#error "QB_PT2M2_G8 should be larger than (QB_PT2M3_G8+1)"
   #endif
   #if ((QB_PT2M1_8G-QB_PT2M2_8G)<=1)
#error "QB_PT2M1_8G should be larger than (QB_PT2M2_8G+1)"
   #endif
   #if ((QB_PT2M2_8G-QB_PT2M3_8G)<=1)
#error "QB_PT2M2_8G should be larger than (QB_PT2M3_8G+1)"
   #endif
#endif

/* ========================================================================= */

/* IS_SPI_CONTROL_BY_BPI_SUPPORT: avoid the SPI switch to TDD before SR3/ST3 is sent*/
#if IS_SPI_CONTROL_SWITCH_BY_BPI_TIMING_CHECK_SUPPORT
   #if ((QB_PR3-QB_SR3)<=2)
#error "QB_PR3 should be larger than (QB_SR3+2)"
   #endif
   #if IS_BPI_V2_PT3A_SUPPORT
      #if ((QB_PT3A-QB_ST3)<=7)
#error "QB_PT3A should be larger than (QB_ST3+7)"
      #endif
   #else
      #if ((QB_PT3-QB_ST3)<=2)
#error "QB_PT3 should be larger than (QB_ST3+2)"
      #endif
   #endif
#endif
   
/* ========================================================================= */

/* avoid the timing of RP3 or ST3 are behind TQ_VALIDATE_COUNT_HF/TQ_VALIDATE_COUNT_1R7PM for 8PM and 1R7PM case */
#if L1D_PM_ENHANCE
   #if ((QB_PR3>=TQ_PM_WIN_OFF_MARGIN) || (QB_SR3>=TQ_PM_WIN_OFF_MARGIN) )
#error "QB_PR3 and QB_SR3 should be smaller than 8QB"
   #endif
#endif

/* ========================================================================= */

#include "l1_interface_reg.h"

/* Compile option consistency check */
#if (IS_GSM && !MD_DRV_IS_GSM) || (!IS_GSM && MD_DRV_IS_GSM)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_GPRS && !MD_DRV_IS_GPRS) || (!IS_GPRS && MD_DRV_IS_GPRS)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_EGPRS && !MD_DRV_IS_EGPRS) || (!IS_EGPRS && MD_DRV_IS_EGPRS)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_EPSK_TX_SUPPORT && !MD_DRV_IS_EPSK_TX_SUPPORT) || (!IS_EPSK_TX_SUPPORT && MD_DRV_IS_EPSK_TX_SUPPORT)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_CENTRALIZED_SMM_CHIP && !MD_DRV_IS_CENTRALIZED_SMM_CHIP) || (!IS_CENTRALIZED_SMM_CHIP && MD_DRV_IS_CENTRALIZED_SMM_CHIP)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_AST_B2S_SUPPORT && !MD_DRV_IS_AST_B2S_SUPPORT) || (!IS_AST_B2S_SUPPORT && MD_DRV_IS_AST_B2S_SUPPORT)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_FOR_FACTORY_MODE_ONLY && !MD_DRV_IS_FOR_FACTORY_MODE_ONLY) || (!IS_FOR_FACTORY_MODE_ONLY && MD_DRV_IS_FOR_FACTORY_MODE_ONLY)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_FHC_SUPPORT && !MD_DRV_IS_FHC_SUPPORT) || (!IS_FHC_SUPPORT && MD_DRV_IS_FHC_SUPPORT)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_NSFT_SUPPORT && !MD_DRV_IS_NSFT_SUPPORT) || (!IS_NSFT_SUPPORT && MD_DRV_IS_NSFT_SUPPORT)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_SINGLE_END_BER_SUPPORT && !MD_DRV_IS_SINGLE_END_BER_SUPPORT) || (!IS_SINGLE_END_BER_SUPPORT && MD_DRV_IS_SINGLE_END_BER_SUPPORT)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_NSFT_SACCH_TEST_ITEM_SUPPORT && !MD_DRV_IS_NSFT_SACCH_TEST_ITEM_SUPPORT) || (!IS_NSFT_SACCH_TEST_ITEM_SUPPORT && MD_DRV_IS_NSFT_SACCH_TEST_ITEM_SUPPORT)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_MULTISLOT_TX_SUPPORT && !MD_DRV_IS_MULTISLOT_TX_SUPPORT) || (!IS_MULTISLOT_TX_SUPPORT && MD_DRV_IS_MULTISLOT_TX_SUPPORT)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_VCXO_LC_SUPPORT && !MD_DRV_IS_VCXO_LC_SUPPORT) || (!IS_VCXO_LC_SUPPORT && MD_DRV_IS_VCXO_LC_SUPPORT)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_TX_POWER_CONTROL_SUPPORT && !MD_DRV_IS_TX_POWER_CONTROL_SUPPORT) || (!IS_TX_POWER_CONTROL_SUPPORT && MD_DRV_IS_TX_POWER_CONTROL_SUPPORT)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_TXPC_CL_AUXADC_SUPPORT && !MD_DRV_IS_TXPC_CL_AUXADC_SUPPORT) || (!IS_TXPC_CL_AUXADC_SUPPORT && MD_DRV_IS_TXPC_CL_AUXADC_SUPPORT)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_W_CANCELLATION_SUPPORT && !MD_DRV_IS_W_CANCELLATION_SUPPORT) || (!IS_W_CANCELLATION_SUPPORT && MD_DRV_IS_W_CANCELLATION_SUPPORT)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2 && !MD_DRV_IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2) || (!IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2 && MD_DRV_IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_UDVT_FH_SUPPORT && !MD_DRV_IS_UDVT_FH_SUPPORT) || (!IS_UDVT_FH_SUPPORT && MD_DRV_IS_UDVT_FH_SUPPORT)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_32K_CRYSTAL_REMOVAL_SUPPORT && !MD_DRV_IS_32K_CRYSTAL_REMOVAL_SUPPORT) || (!IS_32K_CRYSTAL_REMOVAL_SUPPORT && MD_DRV_IS_32K_CRYSTAL_REMOVAL_SUPPORT)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_TX_GAIN_RF_CALIBRATION_SUPPORT && !MD_DRV_IS_TX_GAIN_RF_CALIBRATION_SUPPORT) || (!IS_TX_GAIN_RF_CALIBRATION_SUPPORT && MD_DRV_IS_TX_GAIN_RF_CALIBRATION_SUPPORT)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_BPI_DATA_32_BIT_CHIP && !MD_DRV_IS_BPI_DATA_32_BIT_CHIP) || (!IS_BPI_DATA_32_BIT_CHIP && MD_DRV_IS_BPI_DATA_32_BIT_CHIP)
#error "Please check the compile option defined in l1_option.h"
#endif

#if (IS_MD2G_PWD_DEFAULT_SW_MODE && !MD_DRV_IS_MD2G_PWD_DEFAULT_SW_MODE) || (!IS_MD2G_PWD_DEFAULT_SW_MODE && MD_DRV_IS_MD2G_PWD_DEFAULT_SW_MODE)
#error "Please check the compile option defined in l1_option.h"
#endif

/* Constant consistency check */
#if MD_DRV_TQ_AFC_READY != TQ_AFC_READY
#error "Please check the definition of MD_DRV_TQ_AFC_READY in l1_interface_reg.h"
#endif

#if MD_DRV_TQ_MAXIMUM != TQ_MAXIMUM
#error "Please check the definition of MD_DRV_TQ_MAXIMUM in l1_interface_reg.h"
#endif

#if MD_DRV_TQ_CTIRQ1 != TQ_CTIRQ1
#error "Please check the definition of MD_DRV_TQ_CTIRQ1 in l1_interface_reg.h"
#endif

#if MD_DRV_TQ_WRAP_COUNT != TQ_WRAP_COUNT
#error "Please check the definition of MD_DRV_TQ_WRAP_COUNT in l1_interface_reg.h"
#endif

#if MD_DRV_TQ_VALIDATE_COUNT != TQ_VALIDATE_COUNT
#error "Please check the definition of MD_DRV_TQ_VALIDATE_COUNT in l1_interface_reg.h"
#endif

#if MD_DRV_EVTENA0_SLOW_EN_SEL != EVTENA0_SLOW_EN_SEL
#error "Please check the definition of MD_DRV_EVTENA0_SLOW_EN_SEL in l1_interface_reg.h"
#endif

#if (IS_MIPI_SUPPORT && !MD_DRV_IS_2G_MIPI_SUPPORT) || (!IS_MIPI_SUPPORT && MD_DRV_IS_2G_MIPI_SUPPORT)
#error "Please check the definition of IS_MIPI_SUPPORT in l1d_cid.h"
#error "Please check the definition of MD_DRV_IS_2G_MIPI_SUPPORT in l1_option.h"
#endif

/* ========================================================================= */

#if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
/* RP1/PR2 timing constraints at RX on */
   #if IS_RF_MT6166 || IS_RF_MT6165
      #if (QB_PR1<=QB_SR2-5) || (QB_PR2<=QB_SR2-5)
#error "QB_PR1 and QB_PR2 should be larger than (QB_SR2 - 5)"
      #endif
   #else
#error "please add the timing constraints for QB_PR1 and QB_PR2 in l1d_data.c"
   #endif
#endif

/* ========================================================================= */

/* #if  (IS_CHIP_MT6205)||(IS_CHIP_MT6208)||(IS_FPGA_TARGET) */
/*--------------------------------------------------------*/
/*   RX GAIN SETTING                                      */
/*--------------------------------------------------------*/
/* Value | Single-End_Voltage  |                          */
/*-------+---------------------|                          */
/*   0   |     AVDD*0.8        |                          */
/*   1   |     AVDD*0.4        |                          */
/*--------------------------------------------------------*/

#if   BBRX_GAIN_DOUBLE==0
#define RX_GAIN_SE  (float)0.8
#elif BBRX_GAIN_DOUBLE==1
#define RX_GAIN_SE  (float)0.4
#endif

#if IS_CHIP_MT6205_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*----------------------------------------------*/
/*                  BBTX_GAIN                   */
/*----------------------------------------------*/
/* Value | Output Swing || Value | Output Swing */
/*-------+--------------||-------+--------------*/
/*   3   |  AVDD*0.900  ||   7   |  AVDD*0.360  */
/*   2   |  AVDD*0.720  ||   6   |  AVDD*0.288  */
/*   1   |  AVDD*0.576  ||   5   |  AVDD*0.225  */
/*   0   |  AVDD*0.450  ||   4   |  AVDD*0.180  */
/*----------------------------------------------*/
   #if   BBTX_GAIN==3
#define TX_GAIN_DIFF  (float)0.900
   #elif BBTX_GAIN==2
#define TX_GAIN_DIFF  (float)0.720
   #elif BBTX_GAIN==1
#define TX_GAIN_DIFF  (float)0.576
   #elif BBTX_GAIN==0
#define TX_GAIN_DIFF  (float)0.450
   #elif (BBTX_GAIN==-1)||(BBTX_GAIN==7)
#define TX_GAIN_DIFF  (float)0.360
   #elif (BBTX_GAIN==-2)||(BBTX_GAIN==6)
#define TX_GAIN_DIFF  (float)0.288
   #elif (BBTX_GAIN==-3)||(BBTX_GAIN==5)
#define TX_GAIN_DIFF  (float)0.225
   #elif (BBTX_GAIN==-4)||(BBTX_GAIN==4)
#define TX_GAIN_DIFF  (float)0.180
   #endif

#endif

#if IS_CHIP_MT6205B
/*----------------------------------------------*/
/*                  BBTX_GAIN                   */
/*----------------------------------------------*/
/* Value | Output Swing || Value | Output Swing */
/*-------+--------------||-------+--------------*/
/*   3   |  AVDD*0.53   ||   7   |  AVDD*0.38   */
/*   2   |  AVDD*0.49   ||   6   |  AVDD*0.36   */
/*   1   |  AVDD*0.46   ||   5   |  AVDD*0.33   */
/*   0   |  AVDD*0.41   ||   4   |  AVDD*0.31   */
/*----------------------------------------------*/
   #if   BBTX_GAIN==3
#define TX_GAIN_DIFF  (float)0.53
   #elif BBTX_GAIN==2
#define TX_GAIN_DIFF  (float)0.49
   #elif BBTX_GAIN==1
#define TX_GAIN_DIFF  (float)0.46
   #elif BBTX_GAIN==0
#define TX_GAIN_DIFF  (float)0.41
   #elif (BBTX_GAIN==-1)||(BBTX_GAIN==7)
#define TX_GAIN_DIFF  (float)0.38
   #elif (BBTX_GAIN==-2)||(BBTX_GAIN==6)
#define TX_GAIN_DIFF  (float)0.36
   #elif (BBTX_GAIN==-3)||(BBTX_GAIN==5)
#define TX_GAIN_DIFF  (float)0.33
   #elif (BBTX_GAIN==-4)||(BBTX_GAIN==4)
#define TX_GAIN_DIFF  (float)0.31
   #endif

#endif

/*...........................................................................*/
#if defined(__MTK_TARGET__) && defined(__ARMCC_VERSION)
#if IS_INTERNDATA_LEVEL1
#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#else
#pragma arm section rwdata , rodata , zidata
#endif
#endif /* __MTK_TARGET__ */
/*...........................................................................*/

#if IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION /* 14-bit RXADC */
/*MT6218~*/ const  float bb_cali_scale=((2*RX_GAIN_SE/16383)/(TX_GAIN_DIFF/1023));
#else                                 /* 11-bit RXADC */
/*OTHER*/   const  float bb_cali_scale=((2*RX_GAIN_SE/2047)/(TX_GAIN_DIFF/1023));
#endif

#if IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
const signed long bb_tx_opt_swing_dac_sqr=((BBTX_GAIN_SWING*5420)/(2*1120))*((BBTX_GAIN_SWING*5420)/(2*1120));    //MT6238 Rx ADC short of 2dB
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION || IS_CHIP_MT6225_AND_LATTER_VERSION
const signed long bb_tx_opt_swing_dac_sqr=((BBTX_GAIN_SWING*6912)/(2*1120))*((BBTX_GAIN_SWING*6912)/(2*1120));
#elif IS_CHIP_MT6218B_AND_LATTER_VERSION
const signed long bb_tx_opt_swing_dac_sqr=((BBTX_GAIN_SWING*5184)/(2*1120))*((BBTX_GAIN_SWING*5184)/(2*1120));
#endif

/*----------------------------------------*/
/* Calibration data for round trip delay  */
/*----------------------------------------*/
CONST  short  TxPropagationDelay = TX_PROPAGATION_DELAY;

/*----------------------------------------*/
/* data for BFE setting                   */
/*----------------------------------------*/
#if IS_BBTXRX_CHIP_DESIGN_VER_2 || IS_BBTXRX_CHIP_DESIGN_VER_3
const unsigned char bbrx_iq_swap               = (0x01& BBRX_IQ_SWAP              );
const unsigned char bbtx_iq_swap               = (0x01& BBTX_IQ_SWAP              );
const unsigned char bbtx_common_mode_voltage   = (0x03& BBTX_COMMON_MODE_VOLTAGE  );
const unsigned char bbtx_offset_i              = (0xFF& BBTX_OFFSET_I             );
const unsigned char bbtx_offset_q              = (0xFF& BBTX_OFFSET_Q             );
const unsigned char bbtx_phseli                = (0x3F& BBTX_PHSEL_I              );
const unsigned char bbtx_phselq                = (0x3F& BBTX_PHSEL_Q              );
const unsigned char bbtx_rpsel                 = (0x03& BBTX_RPSEL                );
const unsigned char bbtx_inten                 = (0x01& BBTX_INTEN                );
const unsigned char bbtx_sw_qbcnt              = (0x1F& BBTX_SW_QBCNT             );
const unsigned char bbtx_gain_comp             = (0x3F& BBTX_GAIN_COMP            );
const unsigned char bbtx_iqgain_sel            = (0x3F& BBTX_IQGAIN_SEL           );
const unsigned char bbtx_epsk_dtap_sym         = (0x03& BBTX_EPSK_DTAP_SYM        );
#else
const unsigned char bbrx_iq_swap               = (0x01& BBRX_IQ_SWAP              );
const unsigned char bbrx_gain_double           = (0x01& BBRX_GAIN_DOUBLE          );
const unsigned char bbtx_iq_swap               = (0x01& BBTX_IQ_SWAP              );
const unsigned char bbtx_calrcsel              = (0x07& BBTX_CALRCSEL             );
   #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
const unsigned char bbtx_calbias               = (0x0F& BBTX_CALBIAS              );//for upper chip BBTX_CALBIAS is 4bits
   #else
const unsigned char bbtx_calbias               = (0x1F& BBTX_CALBIAS              );
   #endif
const unsigned char bbtx_common_mode_voltage   = (0x07& BBTX_COMMON_MODE_VOLTAGE  );
const unsigned char bbtx_gain                  = (0x07& BBTX_GAIN                 );
const unsigned char bbtx_trim_i                = (0x0F& BBTX_TRIM_I               );
const unsigned char bbtx_trim_q                = (0x0F& BBTX_TRIM_Q               );
   #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
const unsigned char bbtx_dccoarse_i            = (0x03& BBTX_DCCOARSE_I           );
const unsigned char bbtx_dccoarse_q            = (0x03& BBTX_DCCOARSE_Q           );
   #endif
const unsigned char bbtx_offset_i              = (0x3F& BBTX_OFFSET_I             );
const unsigned char bbtx_offset_q              = (0x3F& BBTX_OFFSET_Q             );
   #if IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
const unsigned char bbtx_phsel                 = (0x0F& BBTX_PHSEL                );
   #else
const unsigned char bbtx_phsel                 = (0x07& BBTX_PHSEL                );
   #endif

   #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
const unsigned char bbtx_calrcsel_h            = (0x07& BBTX_CALRCSEL_H           );
const unsigned char bbtx_common_mode_voltage_h = (0x07& BBTX_COMMON_MODE_VOLTAGE_H);
const unsigned char bbtx_gain_h                = (0x07& BBTX_GAIN_H               );
const unsigned char bbtx_trim_i_h              = (0x0F& BBTX_TRIM_I_H             );
const unsigned char bbtx_trim_q_h              = (0x0F& BBTX_TRIM_Q_H             );
      #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
const unsigned char bbtx_dccoarse_i_h          = (0x03& BBTX_DCCOARSE_I_H         );
const unsigned char bbtx_dccoarse_q_h          = (0x03& BBTX_DCCOARSE_Q_H         );
      #endif
const unsigned char bbtx_offset_i_h            = (0x3F& BBTX_OFFSET_I_H           );
const unsigned char bbtx_offset_q_h            = (0x3F& BBTX_OFFSET_Q_H           );
      #if IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
const unsigned char bbtx_phsel_h               = (0x0F& BBTX_PHSEL_H              );
      #else
const unsigned char bbtx_phsel_h               = (0x07& BBTX_PHSEL_H              );
      #endif
      #if !IS_CHIP_MT6223 && !IS_CHIP_MT6253 /*MT6223 and MT 6253T don't support 8PSK*/
const unsigned char bbtx_rpsel                 = (0x03& BBTX_RPSEL                );
const unsigned char bbtx_inten                 = (0x01& BBTX_INTEN                );
const unsigned char bbtx_sw_qbcnt              = (0x1F& BBTX_SW_QBCNT             );
      #endif
   #endif

   #if IS_CHIP_MT6227
const unsigned char bbtx_iqswap_onfly          = (0x01& BBTX_IQSWAP_ONFLY         );
   #endif
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

sBBTXParameters BBTXParameters =
{
   (0x07& BBTX_COMMON_MODE_VOLTAGE),
   (0x07& BBTX_GAIN),
   (0x07& BBTX_CALRCSEL),
   (0x0F& BBTX_TRIM_I),
   (0x0F& BBTX_TRIM_Q),
   (0x03& BBTX_DCCOARSE_I),
   (0x03& BBTX_DCCOARSE_Q),
   (0x3F& BBTX_OFFSET_I),
   (0x3F& BBTX_OFFSET_Q),
   0,   /* bbtx_isCalibrated */
   BAT_LOW_VOLTAGE,
   BAT_HIGH_VOLTAGE,
   BAT_LOW_TEMPERATURE,
   BAT_HIGH_TEMPERATURE,
   (0x07& BBTX_COMMON_MODE_VOLTAGE_H),
   (0x07& BBTX_GAIN_H),
   (0x07& BBTX_CALRCSEL_H),
   (0x0F& BBTX_TRIM_I_H),
   (0x0F& BBTX_TRIM_Q_H),
   (0x03& BBTX_DCCOARSE_I_H),
   (0x03& BBTX_DCCOARSE_Q_H),
   (0x3F& BBTX_OFFSET_I_H),
   (0x3F& BBTX_OFFSET_Q_H),
#if IS_BBTXRX_CHIP_DESIGN_VER_2 || IS_BBTXRX_CHIP_DESIGN_VER_3
   (0x3F& BBTX_PHSEL),
   (0x3F& BBTX_PHSEL_H),
#elif IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
   (0x0F& BBTX_PHSEL),
   (0x0F& BBTX_PHSEL_H),
#else
   (0x07& BBTX_PHSEL),
   (0x07& BBTX_PHSEL_H),
#endif
   (0x01& GSM850_GSM900_SWAP),
   (0x01& DCS1800_PCS1900_SWAP),
};

#ifndef  RF_TEMPERATURE_SAMPLE_PERIOD
#define  RF_TEMPERATURE_SAMPLE_PERIOD    BAT_TEMPERATURE_SAMPLE_PERIOD
#endif
#ifndef  RF_TEMPERATURE_AVERAGE_COUNT
#define  RF_TEMPERATURE_AVERAGE_COUNT    BAT_TEMPERATURE_AVERAGE_COUNT
#endif

CONST int apc_bat_voltage_period     = BAT_VOLTAGE_SAMPLE_PERIOD;
CONST int apc_bat_voltage_count      = BAT_VOLTAGE_AVERAGE_COUNT;
CONST int apc_bat_temperature_period = BAT_TEMPERATURE_SAMPLE_PERIOD;
CONST int apc_bat_temperature_count  = BAT_TEMPERATURE_AVERAGE_COUNT;
CONST int apc_rf_temperature_period  = RF_TEMPERATURE_SAMPLE_PERIOD;
CONST int apc_rf_temperature_count   = RF_TEMPERATURE_AVERAGE_COUNT;

/*--------------------------------------------------------*/
/* data for BDL/BUL data                                  */
/*--------------------------------------------------------*/
const unsigned short bdlcon_data  = BDLCON_DATA;
const unsigned short bulcon1_data = BULCON1_DATA;
const unsigned short bulcon2_data = BULCON2_DATA;
#if IS_TDMA_AD_DA_WINDOW_SUPPORT
const unsigned short bdlcon2_data = BDLCON2_DATA;
const unsigned short bulcon3_data = BULCON3_DATA;
#endif

/* ========================================================================= */

const short TQ_Afc_ChargeInIdle   = TQ_AFC_CHARGE_IN_IDLE;
CONST short TQ_FBWin_Start_Offset = TQ_FBWIN_START_OFFSET;  /* 216 QB  */
const short TQ_FSWin_DTIRQ_Delay  = TQ_FSWIN_DTIRQ_DELAY;   /* 190 QB  */
/* ========================================================================= */

#if IS_DYNAMIC_G_E_TXWIN_POSITION_SUPPORT || IS_DYNAMIC_G_E_TXWIN_POSITION_SUPPORT_V2
CONST signed short TQ_EPSK_TX_delay = TQ_EPSK_TX_DELAY; /* QB */
#endif

const short FrequencyBias = 0;
short AFC_Dac_TRx_Offset[5/*band*/] =
{  0, /* FrequencyBand400  */
   0, /* FrequencyBand850  */
   0, /* FrequencyBand900  */
   0, /* FrequencyBand1800 */
   0, /* FrequencyBand1900 */
};

#if IS_VCXO_LC_TRXOFFSET_COMPENSATE_SUPPORT
   #if IS_CHIP_MT6252
short AFC_Default_TRx_Offset[5/*band*/] =
{  10, /* FrequencyBand400  */
   10, /* FrequencyBand850  */
   10, /* FrequencyBand900  */
   10, /* FrequencyBand1800 */
   10, /* FrequencyBand1900 */
};

short AFC_TRx_Offset[5/*band*/] =
{  0, /* FrequencyBand400  */
   0, /* FrequencyBand850  */
   0, /* FrequencyBand900  */
   0, /* FrequencyBand1800 */
   0, /* FrequencyBand1900 */
};
   #else
short AFC_Default_TRx_Offset[5/*band*/] =
{  0, /* FrequencyBand400  */
   0, /* FrequencyBand850  */
   0, /* FrequencyBand900  */
   0, /* FrequencyBand1800 */
   0, /* FrequencyBand1900 */
};

short AFC_TRx_Offset[5/*band*/] =
{  0, /* FrequencyBand400  */
   0, /* FrequencyBand850  */
   0, /* FrequencyBand900  */
   0, /* FrequencyBand1800 */
   0, /* FrequencyBand1900 */
};
   #endif
#else
   #if IS_RF_MT6162
short AFC_TRx_Offset[5/*band*/] =
{  0, /* FrequencyBand400  */
   0, /* FrequencyBand850  */
   0, /* FrequencyBand900  */
   0, /* FrequencyBand1800 */
   0, /* FrequencyBand1900 */
};
      #if IS_RF_VCO_DOO_OFF
short AFC_Default_TRx_Offset[5/*band*/] =
{  0, /* Hz, FrequencyBand400  */
   0, /* Hz, FrequencyBand850  */
   0, /* Hz, FrequencyBand900  */
   0, /* Hz, FrequencyBand1800 */
   0, /* Hz, FrequencyBand1900 */
};
      #elif IS_RF_VCO_PARTIAL_DOO_ON
short AFC_Default_TRx_Offset[5/*band*/] =
{  0, /* Hz, FrequencyBand400  */
  15, /* Hz, FrequencyBand850  */
  14, /* Hz, FrequencyBand900  */
  23, /* Hz, FrequencyBand1800 */
  24, /* Hz, FrequencyBand1900 */
};
      #else
short AFC_Default_TRx_Offset[5/*band*/] =
{  0, /* Hz, FrequencyBand400  */
  24, /* Hz, FrequencyBand850  */
  19, /* Hz, FrequencyBand900  */
  36, /* Hz, FrequencyBand1800 */
  40, /* Hz, FrequencyBand1900 */
};
      #endif
   #elif IS_RF_MT6163
short AFC_TRx_Offset[5/*band*/] =
{  0, /* FrequencyBand400  */
   0, /* FrequencyBand850  */
   0, /* FrequencyBand900  */
   0, /* FrequencyBand1800 */
   0, /* FrequencyBand1900 */
};

short AFC_Default_TRx_Offset[5/*band*/] =
{  0, /* Hz, FrequencyBand400  */
  15, /* Hz, FrequencyBand850  */
  15, /* Hz, FrequencyBand900  */
  20, /* Hz, FrequencyBand1800 */
  20, /* Hz, FrequencyBand1900 */
};
   #endif
#endif

/* ========================================================================= */
const unsigned short FM_DURATION = FM_DURATION_DEFAULT;

#if IS_CHIP_MT6575 && !IS_CHIP_MT6575_S00
   #if IS_TDD_DUAL_MODE_SUPPORT
const unsigned short CLK_SETTLE  = CLK32K_MICRO_SECOND(4250);  // Set to fixed value due to AP clock settle time config
   #else
const unsigned short CLK_SETTLE  = CLK32K_MICRO_SECOND(5250);  // Set to fixed value due to AP clock settle time config
   #endif
#else
const unsigned short CLK_SETTLE  = CLK_SETTLE_DEFAULT;
#endif

const unsigned short PLL_RESET   = PLL_RESET_DEFAULT;
/* ========================================================================= */

#ifndef  PDATA_GSM850_PR1
#define  PDATA_GSM850_PR1    0x00
#endif

#ifndef  PDATA_GSM850_PR2
#define  PDATA_GSM850_PR2    0x00
#endif

#ifndef  PDATA_GSM850_PR3
#define  PDATA_GSM850_PR3    0x00
#endif

#ifndef  PDATA_GSM850_PT1
#define  PDATA_GSM850_PT1    0x00
#endif

#ifndef  PDATA_GSM850_PT2
#define  PDATA_GSM850_PT2    0x00
#endif

#ifndef  PDATA_GSM850_PT3
#define  PDATA_GSM850_PT3    0x00
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_DSDA_DCS_TX_NOTCH_SWITCH_SUPPORT
CONST sint_P PDATA_TABLE_DCS_TX_NOTCH[/*5*/][2][5] =
{
   #if IS_DCS_NB_WB_SWITCH_SUPPORT
      /* use this field to store the BPI data for the DCS narrow band  */
   {  {  PDATA_DCS_NB_PR1, PDATA_DCS_NB_PR2, PDATA_DCS_NB_PR2B, PDATA_DCS_NB_PR3, PDATA_DCS_NB_PR3A  } , /* RX */
      {  PDATA_DCS_PT1,    PDATA_DCS_PT2,    PDATA_DCS_PT2B,    PDATA_DCS_PT3,    PDATA_DCS_PT3A     } , /* TX */
   },
   #else
      /* FrequencyBand400 (not support)  */
   {  { 0, 0, 0, 0 },
      { 0, 0, 0, 0 },
   },
   #endif
      /* FrequencyBand850  */
   {  {  PDATA_GSM850_PR1, PDATA_GSM850_PR2, PDATA_GSM850_PR2B, PDATA_GSM850_PR3, PDATA_GSM850_PR3A  } , /* RX */
      {  PDATA_GSM850_PT1, PDATA_GSM850_PT2, PDATA_GSM850_PT2B, PDATA_GSM850_PT3, PDATA_GSM850_PT3A  } , /* TX */
   }, /* FrequencyBand900  */
   {  {  PDATA_GSM_PR1, PDATA_GSM_PR2, PDATA_GSM_PR2B, PDATA_GSM_PR3, PDATA_GSM_PR3A  } ,                /* RX */
      {  PDATA_GSM_PT1, PDATA_GSM_PT2, PDATA_GSM_PT2B, PDATA_GSM_PT3, PDATA_GSM_PT3A  } ,                /* TX */
   }, /* FrequencyBand1800 */
   {  {  PDATA_DCS_PR1,       PDATA_DCS_PR2,       PDATA_DCS_PR2B,       PDATA_DCS_PR3,       PDATA_DCS_PR3A        } ,   /* RX */
      {  PDATA_DCS_NOTCH_PT1, PDATA_DCS_NOTCH_PT2, PDATA_DCS_NOTCH_PT2B, PDATA_DCS_NOTCH_PT3, PDATA_DCS_NOTCH_PT3A  } ,   /* TX */
   }, /* FrequencyBand1900 */
   {  {  PDATA_PCS_PR1, PDATA_PCS_PR2, PDATA_PCS_PR2B, PDATA_PCS_PR3, PDATA_PCS_PR3A  } ,                /* RX */
      {  PDATA_PCS_PT1, PDATA_PCS_PT2, PDATA_PCS_PT2B, PDATA_PCS_PT3, PDATA_PCS_PT3A  } ,                /* TX */
   }
};

CONST sint_P PDATA_TABLE_DEFAULT[/*5*/][2][5] =
{
   #if IS_DCS_NB_WB_SWITCH_SUPPORT
      /* use this field to store the BPI data for the DCS narrow band  */
   {  {  PDATA_DCS_NB_PR1, PDATA_DCS_NB_PR2, PDATA_DCS_NB_PR2B, PDATA_DCS_NB_PR3, PDATA_DCS_NB_PR3A  } , /* RX */
      {  PDATA_DCS_PT1,    PDATA_DCS_PT2,    PDATA_DCS_PT2B,    PDATA_DCS_PT3,    PDATA_DCS_PT3A     } , /* TX */
   },
   #else
      /* FrequencyBand400 (not support)  */
   {  { 0, 0, 0, 0 },
      { 0, 0, 0, 0 },
   },
   #endif
      /* FrequencyBand850  */
   {  {  PDATA_GSM850_PR1, PDATA_GSM850_PR2, PDATA_GSM850_PR2B, PDATA_GSM850_PR3, PDATA_GSM850_PR3A  } , /* RX */
      {  PDATA_GSM850_PT1, PDATA_GSM850_PT2, PDATA_GSM850_PT2B, PDATA_GSM850_PT3, PDATA_GSM850_PT3A  } , /* TX */
   }, /* FrequencyBand900  */
   {  {  PDATA_GSM_PR1, PDATA_GSM_PR2, PDATA_GSM_PR2B, PDATA_GSM_PR3, PDATA_GSM_PR3A  } ,                /* RX */
      {  PDATA_GSM_PT1, PDATA_GSM_PT2, PDATA_GSM_PT2B, PDATA_GSM_PT3, PDATA_GSM_PT3A  } ,                /* TX */
   }, /* FrequencyBand1800 */
   {  {  PDATA_DCS_PR1, PDATA_DCS_PR2, PDATA_DCS_PR2B, PDATA_DCS_PR3, PDATA_DCS_PR3A  } ,                /* RX */
      {  PDATA_DCS_PT1, PDATA_DCS_PT2, PDATA_DCS_PT2B, PDATA_DCS_PT3, PDATA_DCS_PT3A  } ,                /* TX */
   }, /* FrequencyBand1900 */
   {  {  PDATA_PCS_PR1, PDATA_PCS_PR2, PDATA_PCS_PR2B, PDATA_PCS_PR3, PDATA_PCS_PR3A  } ,                /* RX */
      {  PDATA_PCS_PT1, PDATA_PCS_PT2, PDATA_PCS_PT2B, PDATA_PCS_PT3, PDATA_PCS_PT3A  } ,                /* TX */
   }
};
CONST sint_P (*PDATA_TABLE_P)[2][5] = PDATA_TABLE_DEFAULT;
   #else
CONST sint_P PDATA_TABLE[/*5*/][2][5] =
{
   #if IS_DCS_NB_WB_SWITCH_SUPPORT
      /* use this field to store the BPI data for the DCS narrow band  */
   {  {  PDATA_DCS_NB_PR1, PDATA_DCS_NB_PR2, PDATA_DCS_NB_PR2B, PDATA_DCS_NB_PR3, PDATA_DCS_NB_PR3A  } , /* RX */
      {  PDATA_DCS_PT1,    PDATA_DCS_PT2,    PDATA_DCS_PT2B,    PDATA_DCS_PT3,    PDATA_DCS_PT3A     } , /* TX */
   },
   #else
      /* FrequencyBand400 (not support)  */
   {  { 0, 0, 0, 0 },
      { 0, 0, 0, 0 },
   },
   #endif
      /* FrequencyBand850  */
   {  {  PDATA_GSM850_PR1, PDATA_GSM850_PR2, PDATA_GSM850_PR2B, PDATA_GSM850_PR3, PDATA_GSM850_PR3A  } , /* RX */
      {  PDATA_GSM850_PT1, PDATA_GSM850_PT2, PDATA_GSM850_PT2B, PDATA_GSM850_PT3, PDATA_GSM850_PT3A  } , /* TX */
   }, /* FrequencyBand900  */
   {  {  PDATA_GSM_PR1, PDATA_GSM_PR2, PDATA_GSM_PR2B, PDATA_GSM_PR3, PDATA_GSM_PR3A  } ,                /* RX */
      {  PDATA_GSM_PT1, PDATA_GSM_PT2, PDATA_GSM_PT2B, PDATA_GSM_PT3, PDATA_GSM_PT3A  } ,                /* TX */
   }, /* FrequencyBand1800 */
   {  {  PDATA_DCS_PR1, PDATA_DCS_PR2, PDATA_DCS_PR2B, PDATA_DCS_PR3, PDATA_DCS_PR3A  } ,                /* RX */
      {  PDATA_DCS_PT1, PDATA_DCS_PT2, PDATA_DCS_PT2B, PDATA_DCS_PT3, PDATA_DCS_PT3A  } ,                /* TX */
   }, /* FrequencyBand1900 */
   {  {  PDATA_PCS_PR1, PDATA_PCS_PR2, PDATA_PCS_PR2B, PDATA_PCS_PR3, PDATA_PCS_PR3A  } ,                /* RX */
      {  PDATA_PCS_PT1, PDATA_PCS_PT2, PDATA_PCS_PT2B, PDATA_PCS_PT3, PDATA_PCS_PT3A  } ,                /* TX */
   }
};
   #endif
#else
CONST signed short PDATA_TABLE[/*5*/][2][3] =
{     /* FrequencyBand400 (not support)  */
   {  { 0, 0, 0 },
      { 0, 0, 0 },
   }, /* FrequencyBand850  */
   {  {  PDATA_GSM850_PR1, PDATA_GSM850_PR2, PDATA_GSM850_PR3  } ,   /* RX */
      {  PDATA_GSM850_PT1, PDATA_GSM850_PT2, PDATA_GSM850_PT3  } ,   /* TX */
   }, /* FrequencyBand900  */
   {  {  PDATA_GSM_PR1, PDATA_GSM_PR2, PDATA_GSM_PR3  } ,            /* RX */
      {  PDATA_GSM_PT1, PDATA_GSM_PT2, PDATA_GSM_PT3  } ,            /* TX */
   }, /* FrequencyBand1800 */
   {  {  PDATA_DCS_PR1, PDATA_DCS_PR2, PDATA_DCS_PR3  } ,            /* RX */
      {  PDATA_DCS_PT1, PDATA_DCS_PT2, PDATA_DCS_PT3  } ,            /* TX */
   }, /* FrequencyBand1900 */
   {  {  PDATA_PCS_PR1, PDATA_PCS_PR2, PDATA_PCS_PR3  } ,            /* RX */
      {  PDATA_PCS_PT1, PDATA_PCS_PT2, PDATA_PCS_PT3  } ,            /* TX */
   }
};
#endif

#if IS_BSI_TRIG_OFFCHIP_BPI_SUPPORT
CONST signed short PDATA_SX_TABLE[/*5*/][2][2] =
{     /* FrequencyBand400 (not support)  */
   {  { 0, 0 },
      { 0, 0 },
   }, /* FrequencyBand850  */
   {  {  PDATA_GSM850_SR0, PDATA_GSM850_SR3  },    /* RX */
      {  PDATA_GSM850_ST0, PDATA_GSM850_ST3  },    /* TX */
   }, /* FrequencyBand900  */
   {  {  PDATA_GSM_SR0,    PDATA_GSM_SR3     },    /* RX */
      {  PDATA_GSM_ST0,    PDATA_GSM_ST3     },    /* TX */
   }, /* FrequencyBand1800 */
   {  {  PDATA_DCS_SR0,    PDATA_DCS_SR3     },    /* RX */
      {  PDATA_DCS_ST0,    PDATA_DCS_ST3     },    /* TX */
   }, /* FrequencyBand1900 */
   {  {  PDATA_PCS_SR0,    PDATA_PCS_SR3     },    /* RX */
      {  PDATA_PCS_ST0,    PDATA_PCS_ST3     },    /* TX */
   }
};
#endif

#if IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6218~*/ CONST signed short PDATA_TABLE2[5][2][2] =
/*MT6218~*/ {     /* FrequencyBand400 (not support)  */
/*MT6218~*/    {  { 0, 0 },
/*MT6218~*/       { 0    },
/*MT6218~*/    }, /* FrequencyBand850  */
/*MT6218~*/    {  {  PDATA_GSM850_PR2M1, PDATA_GSM850_PR2M2  } ,   /* RX */
/*MT6218~*/       {  PDATA_GSM850_PT2B                       } ,   /* TX */
/*MT6218~*/    }, /* FrequencyBand900  */
/*MT6218~*/    {  {  PDATA_GSM_PR2M1   , PDATA_GSM_PR2M2     } ,   /* RX */
/*MT6218~*/       {  PDATA_GSM_PT2B                          } ,   /* TX */
/*MT6218~*/    }, /* FrequencyBand1800 */
/*MT6218~*/    {  {  PDATA_DCS_PR2M1   , PDATA_DCS_PR2M2     } ,   /* RX */
/*MT6218~*/       {  PDATA_DCS_PT2B                          } ,   /* TX */
/*MT6218~*/    }, /* FrequencyBand1900 */
/*MT6218~*/    {  {  PDATA_PCS_PR2M1   , PDATA_PCS_PR2M2     } ,   /* RX */
/*MT6218~*/       {  PDATA_PCS_PT2B                          } ,   /* TX */
/*MT6218~*/    }
/*MT6218~*/ };
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
CONST sint_P PDATA_TABLE3[5][3][3] =
{     /* FrequencyBand400 (not support)  */
   {  { 0, 0 },
      { 0, 0 },
   }, /* FrequencyBand850  */
   {  {  PDATA_GSM850_PR2M1   , PDATA_GSM850_PR2M2   , PDATA_GSM850_PR2M3     }, /* RX    */
      {  PDATA_GSM850_PT2M1_G8, PDATA_GSM850_PT2M2_G8, PDATA_GSM850_PT2M3_G8  }, /* TX g8 */
      {  PDATA_GSM850_PT2M1_8G, PDATA_GSM850_PT2M2_8G, PDATA_GSM850_PT2M3_8G  }, /* TX 8g */
   }, /* FrequencyBand900  */
   {  {  PDATA_GSM_PR2M1      , PDATA_GSM_PR2M2      , PDATA_GSM_PR2M3        }, /* RX    */
      {  PDATA_GSM_PT2M1_G8   , PDATA_GSM_PT2M2_G8   , PDATA_GSM_PT2M3_G8     }, /* TX g8 */
      {  PDATA_GSM_PT2M1_8G   , PDATA_GSM_PT2M2_8G   , PDATA_GSM_PT2M3_8G     }, /* TX 8g */
   }, /* FrequencyBand1800 */
   {  {  PDATA_DCS_PR2M1      , PDATA_DCS_PR2M2      , PDATA_DCS_PR2M3        }, /* RX    */
      {  PDATA_DCS_PT2M1_G8   , PDATA_DCS_PT2M2_G8   , PDATA_DCS_PT2M3_G8     }, /* TX g8 */
      {  PDATA_DCS_PT2M1_8G   , PDATA_DCS_PT2M2_8G   , PDATA_DCS_PT2M3_8G     }, /* TX 8g */
   }, /* FrequencyBand1900 */
   {  {  PDATA_PCS_PR2M1      , PDATA_PCS_PR2M2      , PDATA_PCS_PR2M3        }, /* RX    */
      {  PDATA_PCS_PT2M1_G8   , PDATA_PCS_PT2M2_G8   , PDATA_PCS_PT2M3_G8     }, /* TX g8 */
      {  PDATA_PCS_PT2M1_8G   , PDATA_PCS_PT2M2_8G   , PDATA_PCS_PT2M3_8G     }, /* TX 8g */
   }
};
#endif
/*...........................................................................*/

const APBADDR_P PDATA_REG_TABLE[/*4:5*/] =
{
   BPI_V( BPIDX(0,0) ),
   BPI_V( BPIDX(1,0) ),
   BPI_V( BPIDX(2,0) ),
   BPI_V( BPIDX(3,0) ),
#if IS_RTX_5CWIN_SUPPORT
   BPI_V( BPIDX(4,0) ),
#endif
};

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
const APBADDR_P PDATA_REG_TABLE2[/*4:5*/] =
{
   BPI_V( PR3A_EV(0) ),
   BPI_V( PR3A_EV(1) ),
   BPI_V( PR3A_EV(2) ),
   BPI_V( PR3A_EV(3) ),
   #if IS_RTX_5CWIN_SUPPORT
   BPI_V( PR3A_EV(4) ),
   #endif
};
#endif

#if IS_BPI_V2_PT3A_SUPPORT
const APBADDR_P PDATA_REG_TABLE3[2] =
{
   BPI_V( PT3A_CWIN1 ),
   BPI_V( PT3A_CWIN2 ),
};
#endif

#if IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6218~*/ const APBADDR  PDATA_PT2B_REG_TABLE[2][3] =
/*MT6218~*/ {
/*MT6218~*/    { BPI_V( 20 ), BPI_V( 15 ), BPI_V( 21 ) },
/*MT6218~*/    { BPI_V( 16 ), BPI_V( 15 ), BPI_V( 17 ) },
/*MT6218~*/ };
/*MT6218~*/
/*MT6218~*/ const APBADDR  PDATA_PR2M_REG_TABLE[4] =
/*MT6218~*/ {
/*MT6218~*/    0,
/*MT6218~*/    BPI_V( 16 ),
/*MT6218~*/    BPI_V( 18 ),
/*MT6218~*/    BPI_V( 20 ),
/*MT6218~*/ };
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
const APBADDR_P  PDATA_PT2M_REG_TABLE[4] =
{
   0,
   BPI_V( PT2M_EV(0,0) ),
   BPI_V( PT2M_EV(1,0) ),
   BPI_V( PT2M_EV(2,0) ),
};

const APBADDR_P  PDATA_PR2M_REG_TABLE[4] =
{
   0,
   BPI_V( 20 ),
   BPI_V( 22 ),
   BPI_V( 24 ),
};
#endif

/*...........................................................................*/

#if IS_BSI_SX0_SUPPORT
CONST signed short RTX_START_TQ_TABLE[2] =
{
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR0,               /* RX_START_CWIN_REG_TABLE[c][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_ST0,               /* TX_START_CWIN_REG_TABLE[c][1]                   */
};
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #ifdef L1D_TEST
signed short RX_START_TQ_TABLE[8] =
{
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR1,               /* RX_START_CWIN_REG_TABLE[c][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR1,               /* RX_START_CWIN_REG_TABLE[c][1]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2,               /* RX_START_CWIN_REG_TABLE[c][2]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2B,              /* RX_START_CWIN_REG_TABLE[c][3]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR2,               /* RX_START_RIDX_REG_TABLE[i][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_BDLON,             /* RX_START_RIDX_REG_TABLE[i][1]                   */
   /* TQ_SLOT_BEGIN(i) + */  TQ_MAXIMUM,           /* RX_START_RIDX_REG_TABLE[i][2] (for FBWIN_HEAD)  */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_AFC_READY_RX,      /* RX_START_RIDX_REG_TABLE[i][3] (for FBWIN_HEAD)  */
};
   #else
CONST signed short RX_START_TQ_TABLE[8] =
{
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR1,               /* RX_START_CWIN_REG_TABLE[c][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR1,               /* RX_START_CWIN_REG_TABLE[c][1]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2,               /* RX_START_CWIN_REG_TABLE[c][2]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2B,              /* RX_START_CWIN_REG_TABLE[c][3]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR2,               /* RX_START_RIDX_REG_TABLE[i][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_BDLON,             /* RX_START_RIDX_REG_TABLE[i][1]                   */
   /* TQ_SLOT_BEGIN(i) + */  TQ_MAXIMUM,           /* RX_START_RIDX_REG_TABLE[i][2] (for FBWIN_HEAD)  */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_AFC_READY_RX,      /* RX_START_RIDX_REG_TABLE[i][3] (for FBWIN_HEAD)  */
};
   #endif

#elif IS_CHIP_MT6225_AND_LATTER_VERSION
   #ifdef L1D_TEST
signed short RX_START_TQ_TABLE[7] =
{
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR1,               /* RX_START_CWIN_REG_TABLE[c][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR1,               /* RX_START_CWIN_REG_TABLE[c][1]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2,               /* RX_START_CWIN_REG_TABLE[c][2]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR2,               /* RX_START_RIDX_REG_TABLE[i][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_BDLON,             /* RX_START_RIDX_REG_TABLE[i][1]                   */
   /* TQ_SLOT_BEGIN(i) + */  TQ_MAXIMUM,           /* RX_START_RIDX_REG_TABLE[i][2] (for FBWIN_HEAD)  */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_AFC_READY,         /* RX_START_RIDX_REG_TABLE[i][3] (for FBWIN_HEAD)  */
};
   #else
CONST signed short RX_START_TQ_TABLE[7] =
{
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR1,               /* RX_START_CWIN_REG_TABLE[c][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR1,               /* RX_START_CWIN_REG_TABLE[c][1]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2,               /* RX_START_CWIN_REG_TABLE[c][2]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR2,               /* RX_START_RIDX_REG_TABLE[i][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_BDLON,             /* RX_START_RIDX_REG_TABLE[i][1]                   */
   /* TQ_SLOT_BEGIN(i) + */  TQ_MAXIMUM,           /* RX_START_RIDX_REG_TABLE[i][2] (for FBWIN_HEAD)  */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_AFC_READY,         /* RX_START_RIDX_REG_TABLE[i][3] (for FBWIN_HEAD)  */
};
   #endif

#else
CONST signed short RX_START_TQ_TABLE[7] =
{
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR1,               /* RX_START_CWIN_REG_TABLE[c][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR1,               /* RX_START_CWIN_REG_TABLE[c][1]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2,               /* RX_START_CWIN_REG_TABLE[c][2]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR2,               /* RX_START_RIDX_REG_TABLE[i][0]                   */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_BDLON,             /* RX_START_RIDX_REG_TABLE[i][1]                   */
   /* TQ_SLOT_BEGIN(i) + */  TQ_MAXIMUM,           /* RX_START_RIDX_REG_TABLE[i][2] (for FBWIN_HEAD)  */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_AFC_READY,         /* RX_START_RIDX_REG_TABLE[i][3] (for FBWIN_HEAD)  */
};
#endif

/*...........................................................................*/

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
CONST signed short RX_END_TQ_TABLE[5] =
{
   /* TQ_SLOT_BEGIN(n) + */  TQ_SR3,               /* RX_END_CWIN_REG_TABLE[c][0]     */
   /* TQ_SLOT_BEGIN(n) + */  TQ_PR3,               /* RX_END_CWIN_REG_TABLE[c][1]     */
   /* TQ_SLOT_BEGIN(n) + */  TQ_PR3A,              /* RX_END_CWIN_REG_TABLE[c][2]     */
   /* TQ_SLOT_BEGIN(n) + */  TQ_BDLOFF,            /* RX/FSI_END_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(n) + */  TQ_MAXIMUM,           /* FSI_END_RIDX_REG_TABLE[i][1]    */
};
#else
CONST signed short RX_END_TQ_TABLE[4] =
{
   /* TQ_SLOT_BEGIN(n) + */  TQ_SR3,               /* RX_END_CWIN_REG_TABLE[c][0]     */
   /* TQ_SLOT_BEGIN(n) + */  TQ_PR3,               /* RX_END_CWIN_REG_TABLE[c][1]     */
   /* TQ_SLOT_BEGIN(n) + */  TQ_BDLOFF,            /* RX/FSI_END_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(n) + */  TQ_MAXIMUM,           /* FSI_END_RIDX_REG_TABLE[i][1]    */
};
#endif

/*...........................................................................*/

#if IS_GPRS
CONST signed short RX_MIDDLE_TQ_TABLE[3] =
{
   /* TQ_SLOT_BEGIN(i) + */ +TQ_BDLOFF,            /* RX_MIDDLE_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_BDLON,             /* RX_MIDDLE_RIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_SR2M,              /* RX_MIDDLE_RIDX_REG_TABLE[i][2] */
};

   #if IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6218~*/ CONST signed short RX_MIDDLE_TQ_TABLE2[2] =
/*MT6218~*/ {
/*MT6218~*/    /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2M1,             /* RX_MIDDLE_RIDX_REG_TABLE2[i][0] */
/*MT6218~*/    /* TQ_SLOT_BEGIN(i) + */ -TQ_PR2M2,             /* RX_MIDDLE_RIDX_REG_TABLE2[i][1] */
/*MT6218~*/ };
   #endif
#endif

/*...........................................................................*/

CONST signed short TX_START_TQ_TABLE[8] =
{
   /* TQ_SLOT_BEGIN(i) + */ -TQ_AFC_READY,          /* TX_START_CWIN_REG_TABLE[c][0] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_ST1,                /* TX_START_CWIN_REG_TABLE[c][1] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PT1,                /* TX_START_CWIN_REG_TABLE[c][2] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_PT2,                /* TX_START_CWIN_REG_TABLE[c][3] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_APCON,              /* TX_START_TIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_APCON,              /* TX_START_TIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_BULON,              /* TX_START_TIDX_REG_TABLE[i][2] */
   /* TQ_SLOT_BEGIN(i) + */ -TQ_ST2,                /* Bright4 : For TDMA_BSI( txwin_sr2 ), not used in Bright2 */
};

#if IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6218~*/ CONST signed short TX_START_TQ_TABLE2[1] =
/*MT6218~*/ {
/*MT6218~*/    /* TQ_SLOT_BEGIN(i) + */ -TQ_PT2B,               /* TX_START_CWIN_REG_TABLE2[c][0] */
/*MT6218~*/ };
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6229~*/ CONST signed short TX_START_TQ_TABLE3[1] =
/*MT6229~*/ {
/*MT6229~*/    /* TQ_SLOT_BEGIN(i) + */ -TQ_ST2B,               /* TX_START_CWIN_REG_TABLE2[c][0] */
/*MT6229~*/ };
#endif

/*...........................................................................*/

CONST signed short TX_END_TQ_TABLE[6] =
{  /* TQ_SLOT_BEGIN(n) + */  TQ_AFC2_2_BOFF,       /* TX_END_CWIN_REG_TABLE[c][0] */
   /* TQ_SLOT_BEGIN(n) + */  TQ_ST3,               /* TX_END_CWIN_REG_TABLE[c][1] */
   /* TQ_SLOT_BEGIN(n) + */  TQ_PT3,               /* TX_END_CWIN_REG_TABLE[c][2] */
   /* TQ_SLOT_BEGIN(n) + */  TQ_BULOFF,            /* TX_END_TIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(n) + */  TQ_APCOFF,            /* TX_END_TIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(n) + */  TQ_APCOFF,            /* TX_END_TIDX_REG_TABLE[i][2] */
};

#if IS_BPI_V2_PT3A_SUPPORT
CONST signed short TX_END_TQ_TABLE2[1] =
{   TQ_PT3A,
};
#endif

/*...........................................................................*/

#if IS_GPRS || IS_MULTISLOT_TX_SUPPORT
CONST signed short TX_MIDDLE_TQ_TABLE[4] =
{
   /* TQ_SLOT_BEGIN(i) */ +TQ_BULOFF,              /* TX_MIDDLE_TIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) */ -TQ_BULON,               /* TX_MIDDLE_TIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) */ -TQ_APCMID,              /* TX_MIDDLE_TIDX_REG_TABLE[i][2] */
   /* TQ_SLOT_BEGIN(i) */ -TQ_APCMID,              /* TX_MIDDLE_TIDX_REG_TABLE[i][3] */
};

   #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*EGPRS*/CONST signed short TX_MIDDLE_TQ_TABLE2[2][4] =
/*EGPRS*/{
/*EGPRS*/   /* TQ_SLOT_BEGIN(i) */{ -TQ_ST2M_G8,
/*EGPRS*/   /* TQ_SLOT_BEGIN(i) */  -TQ_PT2M1_G8,
/*EGPRS*/   /* TQ_SLOT_BEGIN(i) */  -TQ_PT2M2_G8,
/*EGPRS*/   /* TQ_SLOT_BEGIN(i) */  -TQ_PT2M3_G8 },
/*EGPRS*/
/*EGPRS*/   /* TQ_SLOT_BEGIN(i) */{ -TQ_ST2M_8G,
/*EGPRS*/   /* TQ_SLOT_BEGIN(i) */  -TQ_PT2M1_8G,
/*EGPRS*/   /* TQ_SLOT_BEGIN(i) */  -TQ_PT2M2_8G,
/*EGPRS*/   /* TQ_SLOT_BEGIN(i) */  -TQ_PT2M3_8G },
/*EGPRS*/};
   #endif

#endif /*End of "IS_GPRS"*/

/*...........................................................................*/

CONST signed short PM_START_TQ_TABLE[7] =
{
   TQ_SLOT0_BEGIN,
   TQ_SLOT1_BEGIN + TQ_AFC_READY,
   TQ_SLOT2_BEGIN + TQ_AFC_READY,
   TQ_SLOT3_BEGIN + TQ_AFC_READY,
   TQ_SLOT4_BEGIN + TQ_AFC_READY,
   TQ_SLOT5_BEGIN + TQ_AFC_READY,
   TQ_VALIDATE-1-TQ_SHORT_PMWIN_LEN-QR_BOFF_2_IDLE,
};

/*...........................................................................*/

#if L1D_PM_ENHANCE
/* advance PM position of 1st half frame in order to meet FDD dual mode criteria */
const signed short SHORT_PM_START_TQ_TABLE_CT1[4] =
{
   TQ_PM0_BEGIN_HF-TQ_FIRST_4PM_ADV,
   TQ_PM1_BEGIN_HF-TQ_FIRST_4PM_ADV,
   TQ_PM2_BEGIN_HF-TQ_FIRST_4PM_ADV,
   TQ_PM3_BEGIN_HF-TQ_FIRST_4PM_ADV,
};

const signed short SHORT_PM_START_TQ_TABLE_CT2H[4] =
{
   TQ_PM0_BEGIN_HF,
   TQ_PM1_BEGIN_HF,
   TQ_PM2_BEGIN_HF,
   TQ_PM3_BEGIN_HF,
};

   #if IS_FDD_DUAL_MODE_SUPPORT || IS_TDD_DUAL_MODE_SUPPORT
const signed short SHORT_PM_END_POINT_TABLE[8] =
{
   TQ_PM0_BEGIN_HF-TQ_FIRST_4PM_ADV+TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN,
   TQ_PM1_BEGIN_HF-TQ_FIRST_4PM_ADV+TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN,
   TQ_PM2_BEGIN_HF-TQ_FIRST_4PM_ADV+TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN,
   TQ_PM3_BEGIN_HF-TQ_FIRST_4PM_ADV+TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN,
   TQ_PM0_BEGIN_HF+TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN+TQ_PM_REGBIAS_OFF_HF,
   TQ_PM1_BEGIN_HF+TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN+TQ_PM_REGBIAS_OFF_HF,
   TQ_PM2_BEGIN_HF+TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN+TQ_PM_REGBIAS_OFF_HF,
   TQ_VALIDATE-1,
};
   #endif

   #if IS_DSP_ENHANCE_SHORT_FBSB_SUPPORT
      #if IS_DSP_SHORT_FBSB_V2
/*TDD*/ CONST signed short FB_ENHANCE_TQ_LEN_TABLE[FB_ENHANCE_TQ_LEN_TABLE_SIZE] =
/*TDD*/ {
/*TDD*/     0*4,   //   156*N  symbol
/*TDD*/    36*4,   // 156*N+36 symbol
/*TDD*/    76*4,   // 156*N+76 symbol
/*TDD*/   116*4,   //156*N+116 symbol
/*TDD*/ };
/*TDD*/
/*TDD*/ CONST signed short FB_BURST_SCALOR_TABLE[FB_ENHANCE_TQ_LEN_TABLE_SIZE] =
/*TDD*/ {
/*TDD*/    26887,// 420,   //   156*N  symbol
/*TDD*/    29127,//1820,   // 156*N+36 symbol
/*TDD*/    27594,// 862,   // 156*N+76 symbol
/*TDD*/    18079,// 565,   //156*N+116 symbol
/*TDD*/ };
/*TDD*/
/*TDD*/ CONST signed short FB_BURST_RESOLUTION_TABLE[FB_ENHANCE_TQ_LEN_TABLE_SIZE] =
/*TDD*/ {
/*TDD*/    22,   // 156*N      symbol
/*TDD*/    20,   // 156*N+36   symbol
/*TDD*/    21,   // 156*N+76   symbol
/*TDD*/    21,   // 156*N+116  symbol
/*TDD*/ };
/*TDD*/
/*TDD*/ CONST signed short SB_EXTEND_TQ_LEN_TABLE[SB_EXTEND_TQ_LEN_TABLE_SIZE] =
/*TDD*/ {
/*TDD*/     4,   //170 symbol SB
/*TDD*/    28,   //176 symbol SB
/*TDD*/    52,   //182 symbol SB
/*TDD*/ };
/*TDD*/
/*TDD*/ CONST signed short SB_BURST_SCALOR_TABLE[SB_EXTEND_TQ_LEN_TABLE_SIZE] =
/*TDD*/ {
/*TDD*/    24672,//386,   //170 symbol SB
/*TDD*/    23831,//372,   //176 symbol SB
/*TDD*/    23046,//360,   //182 symbol SB
/*TDD*/ };
/*TDD*/
/*TDD*/ CONST signed short SB_BURST_RESOLUTION_TABLE[SB_EXTEND_TQ_LEN_TABLE_SIZE] =
/*TDD*/ {
/*TDD*/    22,
/*TDD*/    22,
/*TDD*/    22,
/*TDD*/ };
      #else //IS_DSP_SHORT_FBSB_V1
/*TDD*/ CONST signed short FB_ENHANCE_TQ_LEN_TABLE[FB_ENHANCE_TQ_LEN_TABLE_SIZE] =
/*TDD*/ {
/*TDD*/     0*4,  //   156*N  symbol
/*TDD*/    36*4,  // 156*N+36 symbol
/*TDD*/    76*4,  // 156*N+76 symbol
/*TDD*/   116*4,  //156*N+116 symbol
/*TDD*/ };
/*TDD*/
/*TDD*/ CONST signed short FB_BURST_SCALOR_TABLE[FB_ENHANCE_TQ_LEN_TABLE_SIZE] =
/*TDD*/ {
/*TDD*/     420,  //   156*N  symbol
/*TDD*/    1820,  // 156*N+36 symbol
/*TDD*/     862,  // 156*N+76 symbol
/*TDD*/     565,  //156*N+116 symbol
/*TDD*/ };
/*TDD*/
/*TDD*/ CONST signed short SB_EXTEND_TQ_LEN_TABLE[SB_EXTEND_TQ_LEN_TABLE_SIZE] =
/*TDD*/ {
/*TDD*/      4,   //170 symbol SB
/*TDD*/     28,   //176 symbol SB
/*TDD*/     52,   //182 symbol SB
/*TDD*/ };
/*TDD*/
/*TDD*/ CONST signed short SB_BURST_SCALOR_TABLE[SB_EXTEND_TQ_LEN_TABLE_SIZE] =
/*TDD*/ {
/*TDD*/    386,   //170 symbol SB
/*TDD*/    372,   //176 symbol SB
/*TDD*/    360,   //182 symbol SB
/*TDD*/ };
      #endif
   #endif

   #if IS_TDD_DUAL_MODE_SUPPORT
/*TDD*/ const signed short TD_DM_PM_BEGIN_POINT_TABLE[8] =
/*TDD*/ {
/*TDD*/    TQ_AFC_READY,                                                                      /*  256 */
/*TDD*/    TQ_AFC_READY+(TQ_AFC_READY+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN)*1,     /*  648 */
/*TDD*/    TQ_AFC_READY+(TQ_AFC_READY+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN)*2,     /* 1040 */
/*TDD*/    TQ_AFC_READY+(TQ_AFC_READY+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN)*3,     /* 1432 */
/*TDD*/    TQ_AFC_READY+(TQ_AFC_READY+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN)*4,     /* 1824 */
/*TDD*/    TQ_AFC_READY+(TQ_AFC_READY+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN)*5,     /* 2216 */
/*TDD*/    TQ_AFC_READY+(TQ_AFC_READY+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN)*6,     /* 2608 */
/*TDD*/    TQ_AFC_READY+(TQ_AFC_READY+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN)*7,     /* 3000 */
/*TDD*/ };
/*TDD*/
/*TDD*/ const signed short TD_DM_PM_END_POINT_TABLE[8] =
/*TDD*/ {
/*TDD*/    (TQ_AFC_READY+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN)*1,                  /*  392 */
/*TDD*/    (TQ_AFC_READY+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN)*2,                  /*  784 */
/*TDD*/    (TQ_AFC_READY+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN)*3,                  /* 1176 */
/*TDD*/    (TQ_AFC_READY+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN)*4,                  /* 1568 */
/*TDD*/    (TQ_AFC_READY+TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PM_WIN_OFF_MARGIN)*5,                  /* 1960 */
/*TDD*/    TQ_MAXIMUM, //(TQ_AFC_READY+TQ_1R7PM_PMWIN_LEN_IN_IDLE+8)*6,
/*TDD*/    TQ_MAXIMUM, //(TQ_AFC_READY+TQ_1R7PM_PMWIN_LEN_IN_IDLE+8)*7,
/*TDD*/    TQ_MAXIMUM, //(TQ_AFC_READY+TQ_1R7PM_PMWIN_LEN_IN_IDLE+8)*8,
/*TDD*/ };
/*TDD*/
/*TDD*/ CONST signed short TD_DM_PM_TQ_TABLE[/*10:11*/] =
/*TDD*/ {
/*TDD*/   -TQ_SR1,                                      /* PM_CWIN_REG_TABLE[c][0] */
/*TDD*/   -TQ_PR1,                                      /* PM_CWIN_REG_TABLE[c][1] */
/*TDD*/   -TQ_PR2,                                      /* PM_CWIN_REG_TABLE[c][2] */
/*TDD*/   -TQ_PR2B,                                     /* PM_CWIN_REG_TABLE[c][3] */
/*TDD*/    TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_SR3,           /* PM_CWIN_REG_TABLE[c][4] */
/*TDD*/    TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PR3,           /* PM_CWIN_REG_TABLE[c][5] */
/*TDD*/    TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PR3A,          /* PM_CWIN_REG_TABLE[c][6] */
/*TDD*/   -TQ_SR2,                                      /* PM_RIDX_REG_TABLE[i][0] */
/*TDD*/   -TQ_BDLON,                                    /* PM_RIDX_REG_TABLE[i][1] */
/*TDD*/    TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_BDLOFF,        /* PM_RIDX_REG_TABLE[i][2] */
/*TDD*/ };
   #endif

   #if L1D_PM_1R7PM
const signed short PM_1R7PM_START_TQ_TABLE[6] =
{
   TQ_PM0_BEGIN_1R7PM,   //Null
   TQ_PM1_BEGIN_1R7PM,
   TQ_PM2_BEGIN_1R7PM,
   TQ_PM3_BEGIN_1R7PM,
   TQ_PM4_BEGIN_1R7PM,
   TQ_CTIRQ1_HF_MIN-100-TQ_1R7PM_PMWIN_LEN_IN_IDLE,
};
   #endif
#endif

/*...........................................................................*/

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
CONST signed short PM_TQ_TABLE[10] =
{
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR1,                                     /* PM_CWIN_REG_TABLE[c][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR1,                                     /* PM_CWIN_REG_TABLE[c][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2,                                     /* PM_CWIN_REG_TABLE[c][2] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2B,                                    /* PM_CWIN_REG_TABLE[c][3] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN+TQ_SR3,                  /* PM_CWIN_REG_TABLE[c][4] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN+TQ_PR3,                  /* PM_CWIN_REG_TABLE[c][5] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN+TQ_PR3A,                 /* PM_CWIN_REG_TABLE[c][6] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR2,                                     /* PM_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_BDLON,                                   /* PM_RIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN+TQ_BDLOFF,               /* PM_RIDX_REG_TABLE[i][2] */
};
   #if L1D_PM_ENHANCE
CONST signed short PM_IN_IDLE_TQ_TABLE[10] =
{
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR1,                                     /* PM_CWIN_REG_TABLE[c][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR1,                                     /* PM_CWIN_REG_TABLE[c][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2,                                     /* PM_CWIN_REG_TABLE[c][2] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2B,                                    /* PM_CWIN_REG_TABLE[c][3] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_SR3,          /* PM_CWIN_REG_TABLE[c][4] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_PR3,          /* PM_CWIN_REG_TABLE[c][5] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_PR3A,         /* PM_CWIN_REG_TABLE[c][6] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR2,                                     /* PM_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_BDLON,                                   /* PM_RIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_BDLOFF,       /* PM_RIDX_REG_TABLE[i][2] */
};
      #if L1D_PM_1R7PM
CONST signed short PM_1R7PM_TQ_TABLE[10] =
{
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR1,                                     /* PM_CWIN_REG_TABLE[c][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR1,                                     /* PM_CWIN_REG_TABLE[c][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2,                                     /* PM_CWIN_REG_TABLE[c][2] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2B,                                    /* PM_CWIN_REG_TABLE[c][3] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_SR3,          /* PM_CWIN_REG_TABLE[c][4] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PR3,          /* PM_CWIN_REG_TABLE[c][5] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PR3A,         /* PM_CWIN_REG_TABLE[c][6] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR2,                                     /* PM_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_BDLON,                                   /* PM_RIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_BDLOFF,       /* PM_RIDX_REG_TABLE[i][2] */
};
      #endif
   #endif

#else
CONST signed short PM_TQ_TABLE[8] =
{
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR1,                                     /* PM_CWIN_REG_TABLE[c][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR1,                                     /* PM_CWIN_REG_TABLE[c][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2,                                     /* PM_CWIN_REG_TABLE[c][2] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN+TQ_SR3,                  /* PM_CWIN_REG_TABLE[c][3] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN+TQ_PR3,                  /* PM_CWIN_REG_TABLE[c][4] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR2,                                     /* PM_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_BDLON,                                   /* PM_RIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN+TQ_BDLOFF,               /* PM_RIDX_REG_TABLE[i][2] */
};
   #if L1D_PM_ENHANCE
CONST signed short PM_IN_IDLE_TQ_TABLE[8] =
{
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR1,                                     /* PM_CWIN_REG_TABLE[c][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR1,                                     /* PM_CWIN_REG_TABLE[c][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2,                                     /* PM_CWIN_REG_TABLE[c][2] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_SR3,          /* PM_CWIN_REG_TABLE[c][3] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_PR3,          /* PM_CWIN_REG_TABLE[c][4] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR2,                                     /* PM_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_BDLON,                                   /* PM_RIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_SHORT_PMWIN_LEN_IN_IDLE+TQ_BDLOFF,       /* PM_RIDX_REG_TABLE[i][2] */
};
      #if L1D_PM_1R7PM
CONST signed short PM_1R7PM_TQ_TABLE[8] =
{
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR1,                                     /* PM_CWIN_REG_TABLE[c][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR1,                                     /* PM_CWIN_REG_TABLE[c][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_PR2,                                     /* PM_CWIN_REG_TABLE[c][2] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_SR3,          /* PM_CWIN_REG_TABLE[c][3] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_PR3,          /* PM_CWIN_REG_TABLE[c][4] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_SR2,                                     /* PM_RIDX_REG_TABLE[i][0] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */ -TQ_BDLON,                                   /* PM_RIDX_REG_TABLE[i][1] */
   /* TQ_SLOT_BEGIN(i) + TQ_AFC_READY + */  TQ_1R7PM_PMWIN_LEN_IN_IDLE+TQ_BDLOFF,       /* PM_RIDX_REG_TABLE[i][2] */
};
      #endif
   #endif

#endif

/*...........................................................................*/

const signed short FWIN_POS_TABLE[8] =
{
   TQ_SLOT0_BEGIN,
   TQ_SLOT1_BEGIN,
   TQ_SLOT2_BEGIN,
   TQ_SLOT3_BEGIN,
   TQ_SLOT4_BEGIN,
   TQ_SLOT5_BEGIN,
   TQ_SLOT6_BEGIN,
   TQ_SLOT7_BEGIN,
};

/*...........................................................................*/

CONST sint_P FSWIN_STOP_DATA_BPI_TABLE[2] =
{
   PDATA_IDLE,
   PDATA_IDLE,
};

const  APBADDR_P  FSWIN_STOP_REG_BPI_TABLE[2] =
{
   BPI_V(BPIRES1),
   BPI_V(BPIRES2),
};

const sint_S FSWIN_STOP_DATA_BSI_TABLE[2] =
{
   (sint_S)SCTRL_IDLE|AGCIDX(FS_RXWIN_IDX+0),
   (sint_S)SCTRL_IDLE|AGCIDX(FS_RXWIN_IDX+1),
};

const  APBADDR_S  FSWIN_STOP_REG_BSI_TABLE[2] =
{
   BSI_Dn_CON(AGCDTIDX(FS_RXWIN_IDX+0)),
   BSI_Dn_CON(AGCDTIDX(FS_RXWIN_IDX+1)),
};

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
CONST signed short FSWIN_STOP_DATA_TABLE[5] =
{
   TQ_FSWIN_STOP_FSYNC+TQ_SR3,
   TQ_FSWIN_STOP_FSYNC+TQ_PR3,
   TQ_FSWIN_STOP_FSYNC+TQ_PR3A,
   TQ_MAXIMUM,
   TQ_FSWIN_STOP_FSYNC+TQ_BDLOFF,
   //PDATA_IDLE, move to FSWIN_STOP_DATA_BPI_TABLE
   //PDATA_IDLE, move to FSWIN_STOP_DATA_BPI_TABLE
   //(signed short)SCTRL_IDLE|AGCIDX(FS_RXWIN_IDX+0), move to FSWIN_STOP_DATA_BSI_TABLE
   //(signed short)SCTRL_IDLE|AGCIDX(FS_RXWIN_IDX+1), move to FSWIN_STOP_DATA_BSI_TABLE
};

const  APBADDR  FSWIN_STOP_REG_TABLE[2][5] =
{
   {  TDMA_BSI(AGCIDX(FS_RXWIN_IDX+0)),
      TDMA_BPI(BPIRES1),
      TDMA_BPI(BPIRES2),
      TDMA_BDLON(FS_RXWIN_IDX+0),
      TDMA_BDLOFF(FS_RXWIN_IDX+0),
      //BPI_V(BPIRES1), move to FSWIN_STOP_REG_BPI_TABLE
      //BPI_V(BPIRES2), move to FSWIN_STOP_REG_BPI_TABLE
      //BSI_Dn_CON(AGCDTIDX(FS_RXWIN_IDX+0)), move to FSWIN_STOP_REG_BSI_TABLE
   },
   {  TDMA_BSI(AGCIDX(FS_RXWIN_IDX+1)),
      TDMA_BPI(BPIRES1),
      TDMA_BPI(BPIRES2),
      TDMA_BDLON(FS_RXWIN_IDX+1),
      TDMA_BDLOFF(FS_RXWIN_IDX+1),
      //BPI_V(BPIRES1), move to FSWIN_STOP_REG_BPI_TABLE
      //BPI_V(BPIRES2), move to FSWIN_STOP_REG_BPI_TABLE
      //BSI_Dn_CON(AGCDTIDX(FS_RXWIN_IDX+1)), move to FSWIN_STOP_REG_BSI_TABLE
   }
};
#else
CONST signed short FSWIN_STOP_DATA_TABLE[7] =
{
   TQ_FSWIN_STOP_FSYNC+TQ_SR3,
   TQ_FSWIN_STOP_FSYNC+TQ_PR3,
   TQ_MAXIMUM,
   TQ_FSWIN_STOP_FSYNC+TQ_BDLOFF,
   PDATA_IDLE,
   (signed short)SCTRL_IDLE|AGCIDX(FS_RXWIN_IDX+0),
   (signed short)SCTRL_IDLE|AGCIDX(FS_RXWIN_IDX+1),
};

const APBADDR FSWIN_STOP_REG_TABLE[2][6] =
{
   {  TDMA_BSI(AGCIDX(FS_RXWIN_IDX+0)),
      TDMA_BPI(BPIRES),
      TDMA_BDLON(FS_RXWIN_IDX+0),
      TDMA_BDLOFF(FS_RXWIN_IDX+0),
      BPI_V(BPIRES),
      BSI_Dn_CON(AGCDTIDX(FS_RXWIN_IDX+0))
   },
   {  TDMA_BSI(AGCIDX(FS_RXWIN_IDX+1)),
      TDMA_BPI(BPIRES),
      TDMA_BDLON(FS_RXWIN_IDX+1),
      TDMA_BDLOFF(FS_RXWIN_IDX+1),
      BPI_V(BPIRES),
      BSI_Dn_CON(AGCDTIDX(FS_RXWIN_IDX+1))
   }
};
#endif

#if IS_RF_MT6162 || IS_RF_MT6163
const unsigned long FSWIN_STOP_BSI_DATA_TABLE[2] =
{
   SDATA_IDLE,  SDATA_IDLE_1
};

const APBADDR FSWIN_STOP_BSI_REG_TABLE[4] =
{  (APBADDR)BSI_Dn_DAT(AGCDTIDX(FS_RXWIN_IDX+0)  ), /* the 1st data of SR3 */
   (APBADDR)BSI_Dn_DAT(AGCDTIDX(FS_RXWIN_IDX+1)  ), /* the 1st data of SR3 */
   (APBADDR)BSI_Dn_DAT(AGCDTIDX(FS_RXWIN_IDX+0)+1), /* the 2nd data of SR3 */
   (APBADDR)BSI_Dn_DAT(AGCDTIDX(FS_RXWIN_IDX+1)+1)  /* the 2nd data of SR3 */
};
#else
const unsigned long FSWIN_STOP_BSI_DATA_TABLE[1] =
{
   SDATA_IDLE,
};

const APBADDR FSWIN_STOP_BSI_REG_TABLE[2] =
{  (APBADDR)BSI_Dn_DAT(AGCDTIDX(FS_RXWIN_IDX+0)),
   (APBADDR)BSI_Dn_DAT(AGCDTIDX(FS_RXWIN_IDX+1))
};
#endif

/* ========================================================================= */

const unsigned char LOWEST_TX_POWER[5] =
{
   5,  /* FrequencyBand400  */
   5,  /* FrequencyBand850  */
   5,  /* FrequencyBand900  */
   0,  /* FrequencyBand1800 */
   0,  /* FrequencyBand1900 */
};

/*---------------------------------------------------------------------------*/

const unsigned char CONTISLOTMASK[5] =
{
   0x81, 0x3, 0x6, 0xC, 0x18
};

const unsigned char FIRSTSLOTMASK[5] =
{
   0x1, 0x3, 0x7, 0xF, 0x0
};

/*---------------------------------------------------------------------------*/

#if IS_CHIP_MT6208 || IS_FPGA_TARGET
/*FPGA,MT6208*/ const short  FIR_COEF[] =
/*FPGA,MT6208*/ {  19 /*count*/,
/*FPGA,MT6208*/    /*-----------------------------------*/
/*FPGA,MT6208*/    0x007F, 0x007E, 0x007E, 0x007E, 0x0000,
/*FPGA,MT6208*/    0x0002, 0x0006, 0x000A, 0x000C, 0x000D,
/*FPGA,MT6208*/    0x000C, 0x000A, 0x0006, 0x0002, 0x0000,
/*FPGA,MT6208*/    0x007E, 0x007E, 0x007E, 0x007F
/*FPGA,MT6208*/    /*-----------------------------------*/
/*FPGA,MT6208*/ };
#elif IS_CHIP_MT6205
/*MT6205*/ const short  FIR_COEF[] =
/*MT6205*/ {   16 /*count*/,
/*MT6205*/     /*-------------------------------------*/
/*MT6205*/     2,  4,  5,  3,  0, -6, -12, -16, -16, -8,
/*MT6205*/     7, 28, 52, 74, 90, 95
/*MT6205*/     /*-------------------------------------*/
/*MT6205*/ };
#elif IS_CHIP_MT6217 || IS_CHIP_MT6219 || IS_CHIP_MT6227 || IS_CHIP_MT6228
/*MT6217*/ const short  FIR_COEF[] =
/*MT6217*/ {   16 /*count*/,
/*MT6217*/     /*-------------------------------------*/
/*MT6217*/     2,  4,  5,  3,  0, -6, -12, -16, -16, -8,
/*MT6217*/     7, 28, 52, 74, 90, 95
/*MT6217*/     /*-------------------------------------*/
/*MT6217*/ };
#elif IS_CHIP_MT6218
/*MT6218*/ const short  FIR_COEF[] =
/*MT6218*/ {   16 /*count*/,
/*MT6218*/     /*-------------------------------------*/
/*MT6218*/     4,  8, 10,  6,  0,-12, -24, -32, -32,-16,
/*MT6218*/    14, 56,104,148,180,190
/*MT6218*/     /*-------------------------------------*/
/*MT6218*/ };
#elif IS_CHIP_MT6225_AND_LATTER_VERSION
/*MT6225*/ const short  FIR_COEF[] =    /* WB FIR, 0020h */ /* New WB FIR Coeffs as MT6229 */
/*MT6225*/ {   11 /*count*/,
/*MT6225*/     /*-------------------------------------*/
/*MT6225*/     2, 9, -4, -20, 5, 43, 1, -87, -35, 186,
/*MT6225*/     319
/*MT6225*/     /*-------------------------------------*/
/*MT6225*/ };
/*MT6225*/ const short  NB_FIR_COEF[] = /* NB FIR, 0070h */
/*MT6225*/ {   11 /*count*/,
/*MT6225*/     /*-------------------------------------*/
/*MT6225*/     -1, 1, 5, 7, -1, -18, -27, -2, 64, 139,
/*MT6225*/     172
/*MT6225*/     /*-------------------------------------*/
/*MT6225*/ };
/*MT6225*/ const short  NB_FIR_COEF_WIDER[] = /* NB FIR for TX auto Cal, 0070h */
/*MT6225*/ {   11 /*count*/,
/*MT6225*/     /*-------------------------------------*/
/*MT6225*/     -3,  -3,  3,  13,  10, -13, -37, -18, 58, 152,
/*MT6225*/     195
/*MT6225*/     /*-------------------------------------*/
/*MT6225*/ };
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_EDGE_SAIC_CHIP_MT6256_AND_LATTER_VERSION
/*MT6256*/ const short  FIR_COEF[] =    /* WB FIR, 0020h */
/*MT6256*/ {   11 /*count*/,
      #if (IS_CHIP_MT6256_S00 || IS_CHIP_MT6251_S00) && defined(L1D_TEST)
/*MT6256*/     /*-------------------------------------*/
/*MT6256*/     -3, 8, 6, -20, -11, 40, 19, -82, -51, 183,
/*MT6256*/     334
/*MT6256*/     /*-------------------------------------*/
      #else
/*MT6256*/     /*-------------------------------------*/
/*MT6256*/     -5, 7, 10, -20, -16, 44, 28, -87, -67, 187,   /* 120KHz */
/*MT6256*/     350
/*MT6256*/     /*-------------------------------------*/
      #endif
/*MT6256*/ };
/*MT6256*/ const short  NB_FIR_COEF[] = /* NB FIR, 0070h */
/*MT6256*/ {   11 /*count*/,
/*MT6256*/     /*-------------------------------------*/
/*MT6256*/     -1, -3, -3, 6, 15, 0, -36, -39, 40, 164,      /* 90KHz */
/*MT6256*/     226
/*MT6256*/     /*-------------------------------------*/
/*MT6256*/ };
/*MT6256*/ const short  NB_FIR_COEF_WIDER[] = /* NB FIR for TX auto Cal, 0070h */
/*MT6256*/ {   0 /*count*/,
/*MT6256*/     /*-------------------------------------*/
/*MT6256*/     /*-------------------------------------*/
/*MT6256*/ };
   #elif IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION && !IS_CHIP_MT6253T
      #ifdef L1D_TEST
/*MT6238*/ const short  FIR_COEF[] =    /* WB FIR, 0020h */
/*MT6238*/ {   11 /*count*/,
/*MT6238*/     /*-------------------------------------*/
/*MT6238*/     -3, 5, 7, -12, -11, 27, 17, -58, -29, 167,
/*MT6238*/     295
/*MT6238*/     /*-------------------------------------*/
/*MT6238*/ };
/*MT6238*/ const short  NB_FIR_COEF[] = /* NB FIR, 0070h */
/*MT6238*/ {   11 /*count*/,
/*MT6238*/     /*-------------------------------------*/
/*MT6238*/     0, -4, -4, 6, 15, 0, -32, -31, 44, 155,
/*MT6238*/     209
/*MT6238*/     /*-------------------------------------*/
/*MT6238*/ };
      #elif  IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION && (IS_RF_MT6162 || IS_RF_MT6163)
/*MT6270A~+OH*/ const short  FIR_COEF[] =    /* WB FIR, 0020h */
/*MT6270A~+OH*/ {   11 /*count*/,
/*MT6270A~+OH*/     /*-------------------------------------*/
/*MT6270A~+OH*/     -4, 6, 8, -14, -13, 30, 20, -63, -38, 170,
/*MT6270A~+OH*/     308
/*MT6270A~+OH*/     /*-------------------------------------*/
/*MT6270A~+OH*/ };
/*MT6270A~+OH*/ const short  NB_FIR_COEF[] = /* NB FIR, 0070h */
/*MT6270A~+OH*/ {   11 /*count*/,
/*MT6270A~+OH*/     /*-------------------------------------*/
/*MT6270A~+OH*/     -2, -5, -1, 11, 13, -8, -37, -25, 52, 156,
/*MT6270A~+OH*/     204
/*MT6270A~+OH*/     /*-------------------------------------*/
/*MT6270A~+OH*/ };
      #else
/*MT6238*/ const short  FIR_COEF[] =    /* WB FIR, 0020h */
/*MT6238*/ {   11 /*count*/,
/*MT6238*/     /*-------------------------------------*/
/*MT6238*/     -3, 5, 7, -12, -11, 27, 17, -58, -29, 167,
/*MT6238*/     295
/*MT6238*/     /*-------------------------------------*/
/*MT6238*/ };
/*MT6238*/ const short  NB_FIR_COEF[] = /* NB FIR, 0070h */
/*MT6238*/ {   11 /*count*/,
/*MT6238*/     /*-------------------------------------*/
/*MT6238*/     0, -4, -4, 6, 15, 0, -32, -31, 44, 155,
/*MT6238*/     209
/*MT6238*/     /*-------------------------------------*/
/*MT6238*/ };
      #endif
/*MT6238*/ const short  NB_FIR_COEF_WIDER[] = /* NB FIR for TX auto Cal, 0070h */
/*MT6238*/ {   11 /*count*/,
/*MT6238*/     /*-------------------------------------*/
/*MT6238*/     -3,  -3,  3,  13,  10, -13, -37, -18, 58, 152,
/*MT6238*/     195
/*MT6238*/     /*-------------------------------------*/
/*MT6238*/ };
   #elif IS_CHIP_MT6223 || IS_CHIP_MT6253T
/*MT6223*/ const short  FIR_COEF[] =    /* WB FIR, 0020h */
/*MT6223*/ {   11 /*count*/,
      #ifdef L1D_TEST
/*MT6223*/     /*-------------------------------------*/
/*MT6223*/     2, 9, -4, -20, 5, 43, 1, -87, -35, 186,
/*MT6223*/     319
/*MT6223*/     /*-------------------------------------*/
      #else
/*MT6223*/     /*-------------------------------------*/
/*MT6223*/     -1, 8, 3, -15, -6, 32, 11, -65, -29, 172,
/*MT6223*/     298
/*MT6223*/     /*-------------------------------------*/
      #endif
/*MT6223*/ };
/*MT6223*/ const short  NB_FIR_COEF[] = /* NB FIR, 0070h */
/*MT6223*/ {   11 /*count*/,
/*MT6223*/     /*-------------------------------------*/
/*MT6223*/     -1, 1, 5, 7, -1, -18, -27, -2, 64, 139,
/*MT6223*/     172
/*MT6223*/     /*-------------------------------------*/
/*MT6223*/ };
/*MT6223*/ const short  NB_FIR_COEF_WIDER[] = /* NB FIR for TX auto Cal, 0070h */
/*MT6223*/ {   11 /*count*/,
/*MT6223*/     /*-------------------------------------*/
/*MT6223*/     -3,  -3,  3,  13,  10, -13, -37, -18, 58, 152,
/*MT6223*/     195
/*MT6223*/     /*-------------------------------------*/
/*MT6223*/ };
   #elif IS_CHIP_MT6229 || IS_CHIP_MT6268T
/*MT6229*/ const short  FIR_COEF[] =    /* WB FIR, 0020h */
/*MT6229*/ {   11 /*count*/,
/*MT6229*/     /*-------------------------------------*/
/*MT6229*/     2, 9, -4, -20, 5, 43, 1, -87, -35, 186,
/*MT6229*/     319
/*MT6229*/     /*-------------------------------------*/
/*MT6229*/ };
/*MT6229*/ const short  NB_FIR_COEF[] = /* NB FIR, 0070h */
/*MT6229*/ {   11 /*count*/,
/*MT6229*/     /*-------------------------------------*/
/*MT6229*/     -1, 1, 5, 7, -1, -18, -27, -2, 64, 139,
/*MT6229*/     172
/*MT6229*/     /*-------------------------------------*/
/*MT6229*/ };
/*MT6229*/ const short  NB_FIR_COEF_WIDER[] = /* NB FIR for TX auto Cal, 0070h */
/*MT6229*/ {   11 /*count*/,
/*MT6229*/     /*-------------------------------------*/
/*MT6229*/     -3,  -3,  3,  13,  10, -13, -37, -18, 58, 152,
/*MT6229*/     195
/*MT6229*/     /*-------------------------------------*/
/*MT6229*/ };
   #endif

   #ifdef L1D_TEST
      #if IS_CHIP_MT6256_S00
/*MT6229,L1D_TEST~*/ const short  VCXO_NARROW_FB_FIR_COEF[] =  /* Narrow Band FIR for FB */
/*MT6229,L1D_TEST~*/ {   11 /*count*/,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/     -2, -3, -3, 0, 6, 16, 30, 46, 61, 71, 75,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/ };
/*MT6229,L1D_TEST~*/ const short  VCXO_WIDE_FB_FIR_COEF[] =    /* Wide Band  FIR for FB */
/*MT6229,L1D_TEST~*/ {   11 /*count*/,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/     1, -1, -5, -10, -12, -7, 12, 41, 75, 102, 113,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/ };
      #elif IS_CHIP_MT6256 || IS_CHIP_MT6255 || IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
/*MT6256,L1D_TEST~*/ const short  VCXO_NARROW_FB_FIR_COEF[] =  /* Narrow Band FIR for FB: 30KHz */
/*MT6256,L1D_TEST~*/ {   11 /*count*/,
/*MT6256,L1D_TEST~*/     /*-------------------------------------*/
/*MT6256,L1D_TEST~*/     -3, -6, -6, -1, 12, 32, 60, 91, 119, 140, 148,
/*MT6256,L1D_TEST~*/     /*-------------------------------------*/
/*MT6256,L1D_TEST~*/ };
/*MT6256,L1D_TEST~*/ const short  VCXO_WIDE_FB_FIR_COEF[] =    /* Wide Band  FIR for FB: 50KHz */
/*MT6256,L1D_TEST~*/ {   11 /*count*/,
/*MT6256,L1D_TEST~*/     /*-------------------------------------*/
/*MT6256,L1D_TEST~*/     1, -2, -10, -20, -25, -13, 24, 83, 152, 208, 228, /* WN:dummy pattern */
/*MT6256,L1D_TEST~*/     /*-------------------------------------*/
/*MT6256,L1D_TEST~*/ };
      #else
/*MT6229,L1D_TEST~*/ const short  VCXO_NARROW_FB_FIR_COEF[] =  /* Narrow Band FIR for FB */
/*MT6229,L1D_TEST~*/ {   11 /*count*/,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/     -2, -3, -3, 0, 6, 16, 30, 46, 61, 71, 75,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/ };
/*MT6229,L1D_TEST~*/ const short  VCXO_WIDE_FB_FIR_COEF[] =    /* Wide Band  FIR for FB */
/*MT6229,L1D_TEST~*/ {   11 /*count*/,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/     1, -1, -5, -10, -12, -7, 12, 41, 75, 102, 113,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/ };
      #endif
/*MT6229,L1D_TEST~*/ const short  TCVCXO_NARROW_FB_FIR_COEF[] =  /* Narrow Band FIR for FB: 15KHz */
/*MT6229,L1D_TEST~*/ {   11 /*count*/,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/     7, 8, 12, 16, 21, 26, 30, 34, 37, 39, 40,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/ };
/*MT6229,L1D_TEST~*/ const short  TCVCXO_WIDE_FB_FIR_COEF[] =    /* Wide Band FIR for FB: 65KHz */
/*MT6229,L1D_TEST~*/ {   11 /*count*/,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/     3, 5, 3, -4, -16, -21, -9, 26, 76, 121, 139,
/*MT6229,L1D_TEST~*/     /*-------------------------------------*/
/*MT6229,L1D_TEST~*/ };
   #endif

   #if defined(MT6229_FB_VCXO)
      #if IS_CHIP_MT6256_S00
/*MT6256 */ const short  NARROW_FB_FIR_COEF[] =  /* Narrow Band FIR for FB */
/*MT6256 */ {   11 /*count*/,
/*MT6256 */     /*-------------------------------------*/
/*MT6256 */     -2, -3, -3, 0, 6, 16, 30, 46, 61, 71, 75,
/*MT6256 */     /*-------------------------------------*/
/*MT6256 */ };
/*MT6256 */ const short  WIDE_FB_FIR_COEF[] =    /* Wide Band  FIR for FB */
/*MT6256 */ {   11 /*count*/,
/*MT6256 */     /*-------------------------------------*/
/*MT6256 */     1, -1, -5, -10, -12, -7, 12, 41, 75, 102, 113,
/*MT6256 */     /*-------------------------------------*/
/*MT6256 */ };
      #elif IS_CHIP_MT6256 || IS_CHIP_MT6255 || IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
/*MT6256~*/ const short  NARROW_FB_FIR_COEF[] =  /* Narrow Band FIR for FB */
/*MT6256~*/ {   11 /*count*/,
/*MT6256~*/     /*-------------------------------------*/
/*MT6256~*/     -3, -6, -6, -1, 12, 32, 60, 91, 119, 140, 148,
/*MT6256~*/     /*-------------------------------------*/
/*MT6256~*/ };
/*MT6256~*/ const short  WIDE_FB_FIR_COEF[] =    /* Wide Band  FIR for FB */
/*MT6256~*/ {   11 /*count*/,
/*MT6256~*/     /*-------------------------------------*/
/*MT6256~*/     1, -2, -10, -20, -25, -13, 24, 83, 152, 208, 228,
/*MT6256~*/     /*-------------------------------------*/
/*MT6256~*/ };
      #else
/*MT6229~*/ const short  NARROW_FB_FIR_COEF[] =  /* Narrow Band FIR for FB */
/*MT6229~*/ {   11 /*count*/,
/*MT6229~*/     /*-------------------------------------*/
/*MT6229~*/     -2, -3, -3, 0, 6, 16, 30, 46, 61, 71, 75,
/*MT6229~*/     /*-------------------------------------*/
/*MT6229~*/ };
/*MT6229~*/ const short  WIDE_FB_FIR_COEF[] =    /* Wide Band  FIR for FB */
/*MT6229~*/ {   11 /*count*/,
/*MT6229~*/     /*-------------------------------------*/
/*MT6229~*/     1, -1, -5, -10, -12, -7, 12, 41, 75, 102, 113,
/*MT6229~*/     /*-------------------------------------*/
/*MT6229~*/ };
      #endif
   #else
/*MT6229~*/ const short  NARROW_FB_FIR_COEF[] =  /* Narrow Band FIR for FB */
/*MT6229~*/ {   11 /*count*/,
/*MT6229~*/     /*-------------------------------------*/
/*MT6229~*/     7, 8, 12, 16, 21, 26, 30, 34, 37, 39, 40,
/*MT6229~*/     /*-------------------------------------*/
/*MT6229~*/ };
/*MT6229~*/ const short  WIDE_FB_FIR_COEF[] =    /* Wide Band FIR for FB */
/*MT6229~*/ {   11 /*count*/,
/*MT6229~*/     /*-------------------------------------*/
/*MT6229~*/     3, 5, 3, -4, -16, -21, -9, 26, 76, 121, 139,
/*MT6229~*/     /*-------------------------------------*/
/*MT6229~*/ };
   #endif
#endif

#if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT
unsigned char USE_3_SUBSTAGES_FB_STAGE1       = 0;  /* USE_3_SUBSTAGES_FB_STAGE1 should be set according to l1d_rf.is_lock_dcxo */
#elif !IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G)
const unsigned char USE_3_SUBSTAGES_FB_STAGE1 = 1;
   #else
const unsigned char USE_3_SUBSTAGES_FB_STAGE1 = 0;
   #endif
#endif

/*-----------------------------*/
/* define DSP power constance  */
/*-----------------------------*/
const int dsp_power_constance = (int)(DSP_MAGIC_VALUE*64);

#ifndef  DCS_TX_GAIN_SETTING
#define  DCS_TX_GAIN_SETTING    0
#endif
#ifndef  PCS_TX_GAIN_SETTING
#define  PCS_TX_GAIN_SETTING    0
#endif

#if (DCS_TX_GAIN_SETTING<=-1) || (PCS_TX_GAIN_SETTING<=-1) || (DCS_TX_GAIN_SETTING>=3) || (PCS_TX_GAIN_SETTING>=3)
#error "MT6139E TX gain setting out of range!"
#endif
const unsigned char dcs_tx_gain_setting=DCS_TX_GAIN_SETTING;
const unsigned char pcs_tx_gain_setting=PCS_TX_GAIN_SETTING;

/*---------------------------------*/
/* AFC Kalman filter coefficients  */
/*---------------------------------*/
#define  AFC_A0_G_SNR          (2560)      /*   a0=0.5, g=1, SNR=4  (0.625) * (2^12) */
#if  defined(AFC_VCXO) || defined(AFC_VCXO_2G)
#define  AFC_PAD               (5120)      /*   (1.2e-6)     * (2^24) */
   #if IS_TWO_STEP_AFC_TRACKING_SUPPORT
#define  AFC_PAD_SPEED         (10240)     /*   (1.2e-6)     * (2^25) */
   #endif
#else
#define  AFC_PAD               (640)       /*   (1.2e-6)     * (2^24) */
   #if IS_TWO_STEP_AFC_TRACKING_SUPPORT
#define  AFC_PAD_SPEED         (1280)
   #endif
#endif

#if IS_TWO_STEP_AFC_TRACKING_SUPPORT
const signed int AFC_KALMAN_FILTER_PAD_SPEED  = ( (AFC_PAD_SPEED <<12)/AFC_A0_G_SNR )>>4;     /* VCXO:512, TCVCXO:64 */
const signed int AFC_KALMAN_FILTER_PAD_NORMAL = ( (AFC_PAD<<12)/AFC_A0_G_SNR )>>4;            /* VCXO:512, TCVCXO:64 */
signed int AFC_KALMAN_FILTER_PAD              = ( (AFC_PAD<<12)/AFC_A0_G_SNR )>>4;            /* VCXO:512, TCVCXO:64 */
#else
const signed int AFC_KALMAN_FILTER_PAD        = ( (AFC_PAD<<12)/AFC_A0_G_SNR )>>4;            /* VCXO:512, TCVCXO:64 */
#endif

//AFC Thermal Tracking Parameter
unsigned char AFC_UPDATE_PERIOD          = 255;   //shall be the multiple of 51 frames

//#ifndef GSM_ERR_DET_ID
//#define  GSM_ERR_DET_ID          9  //<--temp use, each rf should define this in l1d_custom_rf.h
//#endif

//CONST unsigned char gsm_err_det_id = GSM_ERR_DET_ID;

#if IS_MPLL_FH_SUPPORT || IS_MT6276E1_TEMP_MPLL_FH_SUPPORT || IS_MT6276_FREERUN_SUPPORT
unsigned char MPLL_FLT = 1;
#endif

#if IS_SPLL_FH_SUPPORT
unsigned char SPLL_FLT = 1;
#endif

#if IS_32K_CRYSTAL_REMOVAL_SUPPORT
char l1d_ext_32k_exist = 0;
#endif

#if IS_RF_MT6140D
CONST unsigned long  TXCW[2][2][5]=
{  {     // High PCL
      {  0x0000000,  //450  /* GMSK */
         0x20A480B,  //850
         0x21A480B,  //900
         0x202400B,  //1800
         0x202400B,  //1900
      },
      {  0x0000000,  //450  /* EPSK */
         0x200F89B,  //850
         0x208F89B,  //900
         0x200F07B,  //1800
         0x200F07B,  //1900
      },
   },
   {     // Low PCL
      {  0x0000000,  //450  /* GMSK */
         0x20A480B,  //850
         0x21A480B,  //900
         0x202400B,  //1800
         0x202400B,  //1900
      },
      {  0x0000000,  //450  /* EPSK */
         0x214F89B,  //850
         0x21CF89B,  //900
         0x201E07B,  //1800
         0x201E07B,  //1900
      },
   },
};
#endif

/*...........................................................................*/
#if defined(__MTK_TARGET__) && defined(__ARMCC_VERSION)
#pragma arm section rwdata , rodata , zidata
#endif /* __MTK_TARGET__ */
/*...........................................................................*/

/*TX power rollback*/
#if IS_GPRS

/*GSM850*/
#ifndef GSM850_TX_ROLLBACK_2T_GMSK
#define GSM850_TX_ROLLBACK_2T_GMSK 8
#endif

#ifndef GSM850_TX_ROLLBACK_3T_GMSK
#define GSM850_TX_ROLLBACK_3T_GMSK 24
#endif

#ifndef GSM850_TX_ROLLBACK_4T_GMSK
#define GSM850_TX_ROLLBACK_4T_GMSK 32
#endif

#ifndef GSM850_TX_ROLLBACK_5T_GMSK
#define GSM850_TX_ROLLBACK_5T_GMSK 40
#endif

/*GSM*/
#ifndef GSM_TX_ROLLBACK_2T_GMSK
#define GSM_TX_ROLLBACK_2T_GMSK 8
#endif

#ifndef GSM_TX_ROLLBACK_3T_GMSK
#define GSM_TX_ROLLBACK_3T_GMSK 24
#endif

#ifndef GSM_TX_ROLLBACK_4T_GMSK
#define GSM_TX_ROLLBACK_4T_GMSK 32
#endif

#ifndef GSM_TX_ROLLBACK_5T_GMSK
#define GSM_TX_ROLLBACK_5T_GMSK 40
#endif

/*DCS*/
#ifndef DCS_TX_ROLLBACK_2T_GMSK
#define DCS_TX_ROLLBACK_2T_GMSK 8
#endif

#ifndef DCS_TX_ROLLBACK_3T_GMSK
#define DCS_TX_ROLLBACK_3T_GMSK 24
#endif

#ifndef DCS_TX_ROLLBACK_4T_GMSK
#define DCS_TX_ROLLBACK_4T_GMSK 32
#endif

#ifndef DCS_TX_ROLLBACK_5T_GMSK
#define DCS_TX_ROLLBACK_5T_GMSK 40
#endif

/*PCS*/
#ifndef PCS_TX_ROLLBACK_2T_GMSK
#define PCS_TX_ROLLBACK_2T_GMSK 8
#endif

#ifndef PCS_TX_ROLLBACK_3T_GMSK
#define PCS_TX_ROLLBACK_3T_GMSK 24
#endif

#ifndef PCS_TX_ROLLBACK_4T_GMSK
#define PCS_TX_ROLLBACK_4T_GMSK 32
#endif

#ifndef PCS_TX_ROLLBACK_5T_GMSK
#define PCS_TX_ROLLBACK_5T_GMSK 40
#endif

//sTX_POWER_ROLLBACK GSM_tx_power_rollback_gmsk = {GSM_TX_ROLLBACK_2T_GMSK, GSM_TX_ROLLBACK_3T_GMSK, GSM_TX_ROLLBACK_4T_GMSK, GSM_TX_ROLLBACK_5T_GMSK };

sTX_POWER_ROLLBACK GSM850_tx_power_rollback_gmsk = {GSM850_TX_ROLLBACK_2T_GMSK, GSM850_TX_ROLLBACK_3T_GMSK, GSM850_TX_ROLLBACK_4T_GMSK, GSM850_TX_ROLLBACK_5T_GMSK };
sTX_POWER_ROLLBACK GSM_tx_power_rollback_gmsk    = {GSM_TX_ROLLBACK_2T_GMSK, GSM_TX_ROLLBACK_3T_GMSK, GSM_TX_ROLLBACK_4T_GMSK, GSM_TX_ROLLBACK_5T_GMSK };
sTX_POWER_ROLLBACK DCS_tx_power_rollback_gmsk    = {DCS_TX_ROLLBACK_2T_GMSK, DCS_TX_ROLLBACK_3T_GMSK, DCS_TX_ROLLBACK_4T_GMSK, DCS_TX_ROLLBACK_5T_GMSK };
sTX_POWER_ROLLBACK PCS_tx_power_rollback_gmsk    = {PCS_TX_ROLLBACK_2T_GMSK, PCS_TX_ROLLBACK_3T_GMSK, PCS_TX_ROLLBACK_4T_GMSK, PCS_TX_ROLLBACK_5T_GMSK };

//If you want to turn off TX power rollback, please use below setting
/*
sTX_POWER_ROLLBACK GSM850_tx_power_rollback_gmsk = {0, 0, 0, 0};
sTX_POWER_ROLLBACK GSM_tx_power_rollback_gmsk    = {0, 0, 0, 0};
sTX_POWER_ROLLBACK DCS_tx_power_rollback_gmsk    = {0, 0, 0, 0};
sTX_POWER_ROLLBACK PCS_tx_power_rollback_gmsk    = {0, 0, 0, 0};
*/

sTX_POWER_ROLLBACK* tx_power_rollback_gmsk[]=
{
   0,                                               /* FrequencyBand400 (not support)  */
   &GSM850_tx_power_rollback_gmsk,                  /* FrequencyBand850 (not support)  */
   &GSM_tx_power_rollback_gmsk,                     /* FrequencyBand900                */
   &DCS_tx_power_rollback_gmsk,                     /* FrequencyBand1800               */
   &PCS_tx_power_rollback_gmsk,                     /* FrequencyBand1900               */
};

#endif /*IS_GPRS*/

#if IS_EGPRS

/*GSM850*/
#ifndef GSM850_TX_ROLLBACK_2T_EPSK
#define GSM850_TX_ROLLBACK_2T_EPSK 8
#endif

#ifndef GSM850_TX_ROLLBACK_3T_EPSK
#define GSM850_TX_ROLLBACK_3T_EPSK 24
#endif

#ifndef GSM850_TX_ROLLBACK_4T_EPSK
#define GSM850_TX_ROLLBACK_4T_EPSK 32
#endif

#ifndef GSM850_TX_ROLLBACK_5T_EPSK
#define GSM850_TX_ROLLBACK_5T_EPSK 40
#endif

/*GSM*/
#ifndef GSM_TX_ROLLBACK_2T_EPSK
#define GSM_TX_ROLLBACK_2T_EPSK 8
#endif

#ifndef GSM_TX_ROLLBACK_3T_EPSK
#define GSM_TX_ROLLBACK_3T_EPSK 24
#endif

#ifndef GSM_TX_ROLLBACK_4T_EPSK
#define GSM_TX_ROLLBACK_4T_EPSK 32
#endif

#ifndef GSM_TX_ROLLBACK_5T_EPSK
#define GSM_TX_ROLLBACK_5T_EPSK 40
#endif

/*DCS*/
#ifndef DCS_TX_ROLLBACK_2T_EPSK
#define DCS_TX_ROLLBACK_2T_EPSK 8
#endif

#ifndef DCS_TX_ROLLBACK_3T_EPSK
#define DCS_TX_ROLLBACK_3T_EPSK 24
#endif

#ifndef DCS_TX_ROLLBACK_4T_EPSK
#define DCS_TX_ROLLBACK_4T_EPSK 32
#endif

#ifndef DCS_TX_ROLLBACK_5T_EPSK
#define DCS_TX_ROLLBACK_5T_EPSK 40
#endif

/*PCS*/
#ifndef PCS_TX_ROLLBACK_2T_EPSK
#define PCS_TX_ROLLBACK_2T_EPSK 8
#endif

#ifndef PCS_TX_ROLLBACK_3T_EPSK
#define PCS_TX_ROLLBACK_3T_EPSK 24
#endif

#ifndef PCS_TX_ROLLBACK_4T_EPSK
#define PCS_TX_ROLLBACK_4T_EPSK 32
#endif

#ifndef PCS_TX_ROLLBACK_5T_EPSK
#define PCS_TX_ROLLBACK_5T_EPSK 40
#endif

//sTX_POWER_ROLLBACK GSM_tx_power_rollback_epsk = {GSM_TX_ROLLBACK_2T_EPSK, GSM_TX_ROLLBACK_3T_EPSK, GSM_TX_ROLLBACK_4T_EPSK, GSM_TX_ROLLBACK_5T_EPSK };
sTX_POWER_ROLLBACK GSM850_tx_power_rollback_epsk = {GSM850_TX_ROLLBACK_2T_EPSK, GSM850_TX_ROLLBACK_3T_EPSK, GSM850_TX_ROLLBACK_4T_EPSK, GSM850_TX_ROLLBACK_5T_EPSK };
sTX_POWER_ROLLBACK GSM_tx_power_rollback_epsk    = {GSM_TX_ROLLBACK_2T_EPSK, GSM_TX_ROLLBACK_3T_EPSK, GSM_TX_ROLLBACK_4T_EPSK, GSM_TX_ROLLBACK_5T_EPSK };
sTX_POWER_ROLLBACK DCS_tx_power_rollback_epsk    = {DCS_TX_ROLLBACK_2T_EPSK, DCS_TX_ROLLBACK_3T_EPSK, DCS_TX_ROLLBACK_4T_EPSK, DCS_TX_ROLLBACK_5T_EPSK };
sTX_POWER_ROLLBACK PCS_tx_power_rollback_epsk    = {PCS_TX_ROLLBACK_2T_EPSK, PCS_TX_ROLLBACK_3T_EPSK, PCS_TX_ROLLBACK_4T_EPSK, PCS_TX_ROLLBACK_5T_EPSK };

//If you want to turn off TX power rollback, please use below setting
/*
sTX_POWER_ROLLBACK GSM850_tx_power_rollback_epsk = {0, 0, 0, 0};
sTX_POWER_ROLLBACK GSM_tx_power_rollback_epsk    = {0, 0, 0, 0};
sTX_POWER_ROLLBACK DCS_tx_power_rollback_epsk    = {0, 0, 0, 0};
sTX_POWER_ROLLBACK PCS_tx_power_rollback_epsk    = {0, 0, 0, 0};
*/

sTX_POWER_ROLLBACK* tx_power_rollback_epsk[]=
{
   0,                                               /* FrequencyBand400 (not support)  */
   &GSM850_tx_power_rollback_epsk,                  /* FrequencyBand850 (not support)  */
   &GSM_tx_power_rollback_epsk,                     /* FrequencyBand900                */
   &DCS_tx_power_rollback_epsk,                     /* FrequencyBand1800               */
   &PCS_tx_power_rollback_epsk,                     /* FrequencyBand1900               */
};
#endif /*IS_EGPRS*/

/* TX power control */
#if IS_TX_POWER_CONTROL_SUPPORT
   #if IS_TXPC_CL_BSI_SUPPORT && IS_BSI_CLOSED_LOOP_TXPC_ON
char  closed_loop_txpc_type   = 2;
   #elif IS_TXPC_CL_AUXADC_SUPPORT && IS_AUXADC_CLOSED_LOOP_TXPC_ON
char  closed_loop_txpc_type   = 1;
   #else
char  closed_loop_txpc_type   = 0;
   #endif

   #if IS_TXPC_OL_AUXADC_SUPPORT && IS_EPSK_TX_SUPPORT
const char  open_loop_txpc_type     = 1;
   #elif IS_TXPC_OL_BSI_SUPPORT && IS_EPSK_TX_SUPPORT
const char  open_loop_txpc_type     = 2;
   #else
const char  open_loop_txpc_type     = 0;
   #endif

      char  is_txpc_calibrated      = 0; /* [1]: is AUXADC or BSI CL calibrated */
                                         /* [0]: is BSI OL calibrated           */

   #if !defined(__UMTS_RAT__) || !defined(__MTK_UL1_FDD__)|| defined(__MULTI_RAT_AFC_TADC_SHARE_SUPPORT__)
      #if IS_RF_MT6162 || IS_RF_MT6163
const char  temp_adc_cal_type       = 1; /* get the temperature info from AUXADC */
      #elif IS_RF_MT6256RF || IS_RF_MT6280RF || IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165
const char  temp_adc_cal_type       = 2; /* get the temperature info from BSI    */
      #else
const char  temp_adc_cal_type       = 0;
      #endif
   #else
const char  temp_adc_cal_type       = 0;
   #endif
#endif

#if IS_TXPC_CL_AUXADC_SUPPORT
CONST short TQ_TxSampleOffsetGMSK   = QB_TX_SAMPLE_OFFSET_GMSK;
   #if IS_EPSK_TX_SUPPORT
CONST short TQ_TxSampleOffsetEPSK   = QB_TX_SAMPLE_OFFSET_EPSK;
   #endif
      short scan_qb = -30; // for fine tune timing
#endif

#if IS_TXPC_OL_BSI_SUPPORT || IS_TXPC_OL_AUXADC_SUPPORT
   #if IS_CHIP_MT6256 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2 || IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION
CONST short txpc_epsk_tp_slope_lb   = TXPC_EPSK_TP_SLOPE_LB;
CONST short txpc_epsk_tp_slope_hb   = TXPC_EPSK_TP_SLOPE_HB;
      short ref_temperature         = TEMP_VALUE_DEFAULT;
   #endif
#endif

/* RX LNA calbiration */
#if IS_MULTI_LNA_MODE_CALIBRATION_SUPPORT
   #if IS_RF_MT6162 || IS_RF_MT6163 || IS_RF_MT6280RF || IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165
const char  is_lna_calibration      = 1;
   #else
const char  is_lna_calibration      = 0;
   #endif
#endif

#if IS_DECREASE_RF_TX_MAX_POWER_SUPPORT
/*------------------------------------------------------------------------------------*/
/*  Tx_Fine_Tune_Table      : Modifiable (used for fine tune tx power at build time)  */
/*  Tx_Power_Decrement_Table: Unmodifiable (keep all value equal zero)                */
/*------------------------------------------------------------------------------------*/
sTX_POWER_DECREMENT_TABLE Tx_Fine_Tune_Table=
{
   {
	  /* default value is rollback power accroding to multi-tx slots */
      /* unit: 1/8 dB */
      {  /* FrequencyBand850 */
         {  /* GMSK: 1T, 2T, 3T, 4T */
                      0,  24,  38,  48   //  0, 24, 38, 48
         },
         {  /* EPSK: 1T, 2T, 3T, 4T */
                      0,  24,  38,  48   //  0, 24, 38, 48
         }
      },
      {  /* FrequencyBand900 */
         {  /* GMSK: 1T, 2T, 3T, 4T */
                      0,  24,  38,  48   //  0, 24, 38, 48
         },
         {  /* EPSK: 1T, 2T, 3T, 4T */
                      0,  24,  38,  48   //  0, 24, 38, 48
         }
      },
      {  /* FrequencyBand1800 */
         {  /* GMSK: 1T, 2T, 3T, 4T */
                      0,  24,  38,  48   //  0, 24, 38, 48
         },
         {  /* EPSK: 1T, 2T, 3T, 4T */
                      0,  24,  38,  48   //  0, 24, 38, 48
         }
      },
      {  /* FrequencyBand1900 */
         {  /* GMSK: 1T, 2T, 3T, 4T */
                      0,  24,  38,  48   //  0, 24, 38, 48
         },
         {  /* EPSK: 1T, 2T, 3T, 4T */
                      0,  24,  38,  48   //  0, 24, 38, 48
         }
      },
   }
};

/* Tx_Power_Decrement_Table should be all zero. */
sTX_POWER_DECREMENT_TABLE Tx_Power_Decrement_Table={{{{0}}}};
#endif /* IS_DECREASE_RF_TX_MAX_POWER_SUPPORT */

/*----------------------------------------------*/
/*   BPI Check                                  */
/*----------------------------------------------*/
#if IS_RF_MTKSOC1 || IS_RF_MTKSOC1T
/*The BPI9 is the control of RFVCO. It should be set at PR1, PR2, PT1, PT2 and PT2B*/
   #if !(0x0200 & PDATA_GSM850_PR1 & PDATA_GSM850_PR2 & PDATA_GSM850_PT1 & PDATA_GSM850_PT2 & PDATA_GSM850_PT2B)
#error " Please set PDATA_RFDOO (BPI9) into GSM850 BPI data of PR1, PR2, PT1, PT2 and PT2B!!!"
   #endif

   #if !(0x0200 & PDATA_GSM_PR1 & PDATA_GSM_PR2 & PDATA_GSM_PT1 & PDATA_GSM_PT2 & PDATA_GSM_PT2B)
#error " Please set PDATA_RFDOO (BPI9) into GSM BPI data bit9 of PR1, PR2, PT1, PT2 and PT2B!!!"
   #endif

   #if !(0x0200 & PDATA_DCS_PR1 & PDATA_DCS_PR2 & PDATA_DCS_PT1 & PDATA_DCS_PT2 & PDATA_DCS_PT2B)
#error " Please set PDATA_RFDOO (BPI9) into DCS BPI data bit9 of PR1, PR2, PT1, PT2 and PT2B!!!"
   #endif

   #if !(0x0200 & PDATA_PCS_PR1 & PDATA_PCS_PR2 & PDATA_PCS_PT1 & PDATA_PCS_PT2 & PDATA_PCS_PT2B)
#error " Please set PDATA_RFDOO (BPI9) into PCS BPI data bit9 of PR1, PR2, PT1, PT2 and PT2B!!!"
   #endif
#endif /*IS_CHIP_MT6253*/

#if IS_AST_B2S_SUPPORT
   #if !(TQ_PR1 > TQ_AFC_READY_RX + 3) || !(TQ_PT1 > TQ_AFC_READY + 3)
#error " Please set (TQ_PR1 > TQ_AFC_READY_RX + 3) and (TQ_PT1 > TQ_AFC_READY + 3) for AST project!!!"
   #endif
#endif

#if IS_RF_MT6162 || IS_RF_MT6163
   #if ((PDATA_GSM850_PR3 |PDATA_GSM_PR3 |PDATA_DCS_PR3 |PDATA_PCS_PR3 ) & (1<<GSM_ERR_DET_ID))
#error "Bit[9] of PR3 should not be 1!"
   #endif
   #if ((PDATA_GSM850_PR3A|PDATA_GSM_PR3A|PDATA_DCS_PR3A|PDATA_PCS_PR3A) & (1<<GSM_ERR_DET_ID))
#error "Bit[9] of PR3A should not be 1!"
   #endif
   #if ((PDATA_GSM850_PT3 |PDATA_GSM_PT3 |PDATA_DCS_PT3 |PDATA_PCS_PT3 ) & (1<<GSM_ERR_DET_ID))
#error "Bit[9] of PT3 should not be 1!"
   #endif
   #if ((PDATA_GSM850_PT3A|PDATA_GSM_PT3A|PDATA_DCS_PT3A|PDATA_PCS_PT3A) & (1<<GSM_ERR_DET_ID))
#error "Bit[9] of PT3A should not be 1!"
   #endif
#endif

/*----------------------------------------------*/
/*   BSI Check                                  */
/*----------------------------------------------*/
#if IS_BSI_V2_SUPPORT
// ST2B/2M data count should be the same with Xn data count
   #if (SX2_DATA_COUNT != ST2B_ST2M_DATA_COUNT)
#error "BSI v2.0 only support Xn count == Yn count"
   #endif
#endif

// BSI event count should be less than chip support event count
#if (CWIN_BSI_EVENT_COUNT*CWIN_COUNT+RIDX_COUNT+YIDX_COUNT > BSI_EVENT_COUNT)
#error "BSI event counts should not exceed the hardware limit, please check BSI setting."
#endif

// BSI data count should be less than chip support data count
#if ((SX0_DATA_COUNT+SX1_DATA_COUNT+SX3_DATA_COUNT)*CWIN_COUNT+SX2_DATA_COUNT*RIDX_COUNT+ST2B_ST2M_DATA_COUNT*YIDX_COUNT > BSI_DATA_COUNT_SW_LIMIT)
#error "BSI data counts should not exceed the hardware limit, please check BSI setting."
#endif

/*...........................................................................*/

#if defined(L1_SIM)
#elif IS_CHIP_MT6256_S00
#elif IS_CHIP_MT6256 || IS_CHIP_MT6255 || IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
   #if (DCOC_QB_RX_FENA_2_FSYNC!=QB_RX_FENA_2_FSYNC)
#error "DCOC_QB_RX_FENA_2_FSYNC is not equal to QB_RX_FENA_2_FSYNC! "
   #endif
#endif

/*...........................................................................*/

#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT

   #if IS_RF_MT6140D
#define RF_TYPE      1
   #elif IS_RF_AD6548
#define RF_TYPE      2
   #elif IS_RF_AD6546
#define RF_TYPE      3
   #else
#define RF_TYPE      1
   #endif

sRF_TABLE l1_rf_table=
{
   0x12345678,                                                            // the special pattern of start position
   2,                                                                     // Struct Version ID
   RF_TYPE,                                                               // default set MT6140D_RF
   0,                                                                     // default is false, and will be changed  as true after tool update
  {   {  { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF },
         { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF },
      },
      {  { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF },
         { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF },
      },
      {  { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF },
         { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF },
      },
      {  { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF },
         { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF },
      },
      {  { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF },
         { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF },
      }
  },                                                                      //PDATA_TABLE[5][2][5]
  {   {  { RFDEF, RFDEF, RFDEF },
         { RFDEF, RFDEF, RFDEF },
         { RFDEF, RFDEF, RFDEF },
      },
      {  { RFDEF, RFDEF, RFDEF },
         { RFDEF, RFDEF, RFDEF },
         { RFDEF, RFDEF, RFDEF },
      },
      {  { RFDEF, RFDEF, RFDEF },
         { RFDEF, RFDEF, RFDEF },
         { RFDEF, RFDEF, RFDEF },
      },
      {  { RFDEF, RFDEF, RFDEF },
         { RFDEF, RFDEF, RFDEF },
         { RFDEF, RFDEF, RFDEF },
      },
      {  { RFDEF, RFDEF, RFDEF },
         { RFDEF, RFDEF, RFDEF },
         { RFDEF, RFDEF, RFDEF },
      }
   },                                                                     //PDATA_TABLE3[5][3][3]
  { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF, RFDEF,RFDEF, RFDEF },              //RX_START_TQ_TABLE[8]
  { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF },                                  //RX_END_TQ_TABLE[5]
  { RFDEF, RFDEF, RFDEF },                                                //RX_MIDDLE_TQ_TABLE
  { RFDEF, RFDEF },                                                       //RX_MIDDLE_TQ_TABLE2[2]
  { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF, RFDEF,RFDEF, RFDEF },              //TX_START_TQ_TABLE[8]
  { RFDEF },                                                              //TX_START_TQ_TABLE2[1]
  { RFDEF },                                                              //TX_START_TQ_TABLE3[1]
  { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF, RFDEF },                           //TX_END_TQ_TABLE[6]
  { RFDEF, RFDEF, RFDEF, RFDEF },                                         //TX_MIDDLE_TQ_TABLE[4]
  {   { RFDEF, RFDEF, RFDEF, RFDEF },
      { RFDEF, RFDEF, RFDEF, RFDEF }
  },                                                                      //TX_MIDDLE_TQ_TABLE2[2][4]
  { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF, RFDEF,RFDEF },                     //PM_START_TQ_TABLE[7]
  { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF, RFDEF,RFDEF, RFDEF,RFDEF, RFDEF }, //PM_TQ_TABLE[10]
  { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF, RFDEF,RFDEF, RFDEF,RFDEF, RFDEF }, //PM_IN_IDLE_TQ_TABLE[10]
  { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF, RFDEF,RFDEF, RFDEF,RFDEF, RFDEF }, //PM_1R7PM_TQ_TABLE[10]
  { RFDEF, RFDEF, RFDEF, RFDEF, RFDEF, RFDEF,RFDEF, RFDEF,RFDEF },        //FSWIN_STOP_DATA_TABLE[9]
  {   {   { URFDEF, URFDEF, URFDEF, URFDEF, URFDEF },
          { URFDEF, URFDEF, URFDEF, URFDEF, URFDEF },
      },
      {   { URFDEF, URFDEF, URFDEF, URFDEF, URFDEF },
          { URFDEF, URFDEF, URFDEF, URFDEF, URFDEF },
      },
   },                                                                    //txios_pcl_tab[2][2][5]
   {   {   { URFDEF, URFDEF, URFDEF, URFDEF, URFDEF },
           { URFDEF, URFDEF, URFDEF, URFDEF, URFDEF },
       },
       {   { URFDEF, URFDEF, URFDEF, URFDEF, URFDEF },
           { URFDEF, URFDEF, URFDEF, URFDEF, URFDEF },
       }
   },                                                                    //txitc_pcl_tab[2][2][5]
   {   {   { URFDEF, URFDEF, URFDEF, URFDEF, URFDEF },
           { URFDEF, URFDEF, URFDEF, URFDEF, URFDEF },
       },
       {   { URFDEF, URFDEF, URFDEF, URFDEF, URFDEF },
           { URFDEF, URFDEF, URFDEF, URFDEF, URFDEF },
       }
   },                                                                    //txmod_gc_tab[2][2][5]
   30,                                                                   //XCAPID
   0x87654321,                                                           //the special pattern of end1 position
   PDATA_GMSK,
   PDATA_8PSK,
   GSM850_GSM900_SWAP,
   DCS1800_PCS1900_SWAP,
   SECONDS2FRAME(180),                                                   //BAT_VOLTAGE_SAMPLE_PERIOD;
   1,                                                                    //BAT_VOLTAGE_AVERAGE_COUNT;
   SECONDS2FRAME(180),                                                   //BAT_TEMPERATURE_SAMPLE_PERIOD;
   1,                                                                    //BAT_TEMPERATURE_AVERAGE_COUNT;
   VOLT2UVOLT(3.5),                                                      //BAT_LOW_VOLTAGE;
   VOLT2UVOLT(4.0),                                                      //BAT_HIGH_VOLTAGE;
   TEMP2MTEMP(0),                                                        //BAT_LOW_TEMPERATURE;
   TEMP2MTEMP(50),                                                       //BAT_HIGH_TEMPERATURE;
   0x87654321,                                                           //the special pattern of end2 position
};
#endif

#if IS_TDD_DUAL_MODE_SUPPORT
   #if IS_CHIP_MT6575
      #if defined(__AST_MC1INS_WAKEUP__)
unsigned long TD_AFC_switch_GPIO_pin     =  103;
      #else
unsigned long TD_AFC_switch_GPIO_pin     =  24;
      #endif
   #else
unsigned long TD_AFC_switch_GPIO_pin     =  24;
   #endif
signed   long TD_AFC_switch_GPIO_status  =  0;
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if IS_EPSK_TX_SUPPORT
   #if IS_EPSK_TX_NOT_SUPPORT_RF
/*EPSK*/ sMIDRAMPDATA* GSM850_EPSK_InterRampData[] = { 0,0,0,0 };
/*EPSK*/ sMIDRAMPDATA* GSM_EPSK_InterRampData[] =    { 0,0,0,0 };
/*EPSK*/ sMIDRAMPDATA* DCS_EPSK_InterRampData[] =    { 0,0,0,0 };
/*EPSK*/ sMIDRAMPDATA* PCS_EPSK_InterRampData[] =    { 0,0,0,0 };
/*EPSK*/ sMIDRAMPDATA** EPSK_InterRampData[]    =    { 0,                         /* FrequencyBand400 (not support)  */
                                                       GSM850_EPSK_InterRampData, /* FrequencyBand850                */
                                                       GSM_EPSK_InterRampData,    /* FrequencyBand900                */
                                                       DCS_EPSK_InterRampData,    /* FrequencyBand1800               */
                                                       PCS_EPSK_InterRampData,    /* FrequencyBand1900               */
                                                     };
/*EPSK*/ sRAMPDATA*  RampData_EPSK[]            =    {0,0,0,0,0};
   #endif
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#if IS_2G_TAS_SUPPORT
   
sL1_TAS_CUSTOM_PARAMS L1_TAS_Custom_Params=
{
   L1D_FORCE_TX_ANTENNA_ENABLE,             /* 0: off 1: Don't change antenna                                             */
   L1D_FORCE_TX_ANTENNA_IDX,                /* The antenna which user forces to stay                                      */
   L1D_EN_TAS,                              /* 0: off   1: enable TS feature                                              */
   L1D_EN_TAS_WITH_TEST_SIM,                /* 0: off   1: enable TS feature with Test SIM                                */
   L1D_EN_BAND,                             /* b0:band 850,b1:band 900,b2:band 1800,b3:band 1900                          */
   L1D_ANT_SEL_INIT                         /* Default antenna                                                            */
};

sL1_TAS_CUSTOM_PDATA L1_TAS_Custom_PData=
{
   PDATA_L1D_TAS_MASK,
   {
      //GSM400 // Not support
      {  0, 0, 0, 0, 0, 0, 0  },
      //GSM850
      {  PDATA_L1D_GSM850_TAS1,
         PDATA_L1D_GSM850_TAS2,
         PDATA_L1D_GSM850_TAS3,
         PDATA_L1D_GSM850_TAS4,
         PDATA_L1D_GSM850_TAS5,
         PDATA_L1D_GSM850_TAS6,
         PDATA_L1D_GSM850_TAS7
      },
      //GSM900
      {  PDATA_L1D_GSM900_TAS1,
         PDATA_L1D_GSM900_TAS2,
         PDATA_L1D_GSM900_TAS3,
         PDATA_L1D_GSM900_TAS4,
         PDATA_L1D_GSM900_TAS5,
         PDATA_L1D_GSM900_TAS6,
         PDATA_L1D_GSM900_TAS7
      },      
      //DCS1800
      {  PDATA_L1D_DCS1800_TAS1,
         PDATA_L1D_DCS1800_TAS2,
         PDATA_L1D_DCS1800_TAS3,
         PDATA_L1D_DCS1800_TAS4,
         PDATA_L1D_DCS1800_TAS5,
         PDATA_L1D_DCS1800_TAS6,
         PDATA_L1D_DCS1800_TAS7
      },
      //PCS1900
      {  PDATA_L1D_PCS1900_TAS1,
         PDATA_L1D_PCS1900_TAS2,
         PDATA_L1D_PCS1900_TAS3,
         PDATA_L1D_PCS1900_TAS4,
         PDATA_L1D_PCS1900_TAS5,
         PDATA_L1D_PCS1900_TAS6,
         PDATA_L1D_PCS1900_TAS7
      }
   }
};
#endif

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
