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
 *   m12195.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Setup RF Ramp
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.35  $
 * $Modtime:   Jul 29 2005 13:47:24  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1/l1d/m12195.c-arc  $
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
 * 11 15 2013 ola.lee
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	[MT6290][2G RF driver] set 6169 E1/E1ECO CW114, SRX_VCO_I to "0".
 *
 * removed!
 * removed!
 * 	[MT6290][2G MT6169 E3 Change]
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
 * 	[MT6290][2G RF driver] update CW114 SRX_VCO_I from 4 to 0.
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
 * Add SR3 check for FSIWinOff
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
 * 12 22 2011 th.yeh
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * 11 30 2011 th.yeh
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
 * 10 21 2011 th.yeh
 * removed!
 * .
 *
 * 09 20 2011 th.yeh
 * removed!
 * .
 *
 * 08 09 2011 th.yeh
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
 * Remove compile warning of unreferenced variable
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
 * Add IS_EPSK_TX_SUPPORT compile option to maintain L1D_RF_SetPData_PT2M() for 8PSK/GMSK tx switching
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
 * < Triple850>
 * RF chip gets GSM900 signal from GSm850 input pins  to avoid getting GSM900 signal
 *
 * removed!
 * removed!
 *
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
 *    Rev 1.35   Jul 29 2005 14:02:18   mtk00773
 * [L1D][Enhence] Support RF SKY74117
 * Resolution for 12111: [L1D][Enhence] Support RF SKY74117
 *
 *    Rev 1.34   Jul 08 2005 16:53:06   mtk00939
 * [L1D][Modify]L1D add code for MT6139C and META related code
 *
 *    Rev 1.33   May 17 2005 00:34:38   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.32   May 16 2005 11:46:26   mtk00240
 * Support 22 BPI setting & current sense PA
 * Resolution for 11091: [L1D][New Feature] Support 22 BPI setting & current sense PA
 *
 *    Rev 1.31   Jan 18 2005 00:38:10   BM
 * append new line in W05.04
 *
 *    Rev 1.30   Jan 10 2005 12:19:26   mtk00939
 * Do some modify for MT6129D driver to support GSM850
 * Resolution for 9426: [L1D][modify] modified for MT6129D driver to support GSM850
 *
 *    Rev 1.29   Jan 10 2005 10:38:44   mtk00939
 * Do some modify for MT6129D driver to support GSM850
 * Resolution for 9426: [L1D][modify] modified for MT6129D driver to support GSM850
 *
 *    Rev 1.28   Jul 30 2004 17:37:08   mtk00240
 * L1D add code to support AERO1Plus RF chip
 * Resolution for 6925: [L1D][Enhance] L1D add code to support AERO1Plus RF chip
 *
 *    Rev 1.27   Jul 05 2004 15:53:12   mtk00773
 * Add RF POLARIS1 setting
 *
 *    Rev 1.26   Jun 07 2004 11:48:08   mtk00240
 * To improve DCS/PCS ORFS +-400KHz performance by performing TXICMP
 * Resolution for 5565: [L1D][Add Feature] Add code to support MT6129D
 *
 *    Rev 1.25   May 21 2004 19:01:58   mtk00240
 * Add code to support MT6129D
 * Resolution for 5565: [L1D][Add Feature] Add code to support MT6129D
 *
 *    Rev 1.24   Jan 27 2004 15:33:12   mtk00585
 * [L1D][Add] L1D Add code for MT6129C RF Driver.
 *
 *    Rev 1.23   Jan 12 2004 17:31:58   mtk00585
 * [L1D][Modify] In order of solving MT6119 synthesizer out of lock problem, we send Warm Up command before Set PLL command.
 * Resolution for 3724: [L1D][Modify] In order of solving MT6119 synthesizer out of lock problem, we send Warm Up command before Set PLL command.
 *
 *    Rev 1.22   Oct 23 2003 14:22:20   mtk00585
 * [L1D][Add] L1D Add code for MT6129B RF Driver.
 * Resolution for 3177: [L1D][Add] L1D Add code for MT6129B RF Driver.
 *
 *    Rev 1.21   Jul 11 2003 17:41:32   mtk00489
 * [L1D][Enhanced]L1D supports MT6129A
 * Resolution for 2241: [L1D][Enhanced]L1D supports MT6129A
 *
 *    Rev 1.20   Jun 06 2003 18:42:46   mtk00489
 * [L1D][Enhanced]L1D modify for custom folder/files. from now on, L1D only knows the RF chip name(not board name) 1.add l1d_custom_rf.h(from l1d_rf.h) 2.add 12196.c(from 12190.c) 3.move m12193.c to custom directory 4.modify l1s.lis 5.files include l1d_rf.h should also include l1d_custom_rf.h 6.change l1d_cid.h
 * Resolution for 1961: [L1D][Enhanced]L1D modify for custom folder/files. from now on, L1D only knows the RF chip name(not board name) 1.add l1d_custom_rf.h(from l1d_rf.h) 2.add 12196.c(from 12190.c) 3.move m12193.c to custom directory 4.modify l1s.lis 5.files
 *
 *    Rev 1.19   May 16 2003 13:09:24   mtk00489
 * [L1D][New Feature]L1D supports MT6119C
 * Resolution for 1794: [L1D][New Feature]L1D supports MT6119C
 *
 *    Rev 1.18   Nov 29 2002 15:42:08   mtk00474
 * Add ST1 event data for MT6119. So that the BSI will send two data when ST1 happens to improve the side band suppression
 * Resolution for 575: Add ST1 event data for MT6119
 *
 *    Rev 1.17   27 Aug 2002 12:04:22   admin
 * change file header
 *
 *    Rev 1.16   26 Aug 2002 14:34:16   admin
 * remove modification notice
 * add copyright statement.
 *
 *    Rev 1.15   24 Aug 2002 14:10:48   mtk00240
 *  L1D add code to support AERO RF Module
 * Resolution for 464:  L1D add code to support AERO RF Module
 *
 *    Rev 1.14   15 Aug 2002 08:28:38   mtk00240
 * Fix the bug of HWRITE_4_SDATA
 *
 *    Rev 1.13   23 Jul 2002 15:49:12   mtk00240
 * L1D add code to support MT6119 RF Module
 * Resolution for 439: L1D add code to support MT6119 RF Module
 *
 *    Rev 1.12   03 Jul 2002 21:43:48   mtk00240
 * L1D extrract RF setting code to let customer setup new RF module more easily
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.11   16 May 2002 15:05:10   mtk00240
 * disable APC power ramp while calibrate BFE or open long Tx window
 * Resolution for 396: L1D disable APC power ramp while calibrate BFE & open long Tx window
 *
 *    Rev 1.10   08 May 2002 22:19:30   mtk00240
 * L1D add functions to support RF Test Tool
 * Resolution for 387: L1D add functions to support RF Test Tool
 *
 *    Rev 1.9   02 May 2002 14:26:12   mtk00240
 * Reduce warnnings n compiling time for MT6205
 * Resolution for 384: Extract GSM code from L1D
 *
 *    Rev 1.8   01 May 2002 22:45:58   mtk00240
 * Extract GSM code from L1D
 * Resolution for 384: Extract GSM code from L1D
 *
 *    Rev 1.7   01 Apr 2002 12:24:14   mtk00240
 * L1D modified register's definition for DSP main v10
 * Resolution for 347: L1D modified register's definition for DSP F/W main v10
 *
 *    Rev 1.6   30 Mar 2002 13:04:18   mtk00240
 * 1) Modify L1D code to support both Bright2 & Bright4 RF board
 * 2) L1D add Audio interface to support Voice Memo & Melody
 * 3) Add L1D code to support RAM-based chip
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 * Resolution for 342: L1D add Audio interface to support Voice Memo & Melody
 * Resolution for 343: Add L1D code to support RAM-based chip
 *
 *    Rev 1.5   11 Mar 2002 13:36:30   mtk00240
 * instead TAB characters of Space characters in L1D code .
 * Resolution for 318: Shine change TAB character to Space charter
 *
 *    Rev 1.4   06 Mar 2002 19:28:36   mtk00240
 * L1D change the methode of setup APC ramp
 * Resolution for 311: L1D change the methode of setup APC ramp
 *
 *    Rev 1.3   03 Mar 2002 23:06:30   mtk00240
 * L1D add code to setup APC DC offset
 * Resolution for 305: L1D add code to setup APC DC offset
 *
 *    Rev 1.2   17 Feb 2002 20:15:42   mtk00240
 * Update L1D code for solving HandOver test item
 * Resolution for 275: Update L1D code for solving HandOver test item
 *
 *    Rev 1.1   03 Jan 2002 12:19:50   mtk00240
 * Merge B.L1.20011225 to Main V1.XX
 *
 *    Rev 1.0   Dec 25 2001 14:40:22   admin
 * Initial revision.
 *
 *    Rev 1.1   Dec 10 2001 16:43:56   mtk00240
 * Add copyright header of MediaTek
 *
 *******************************************************************************/

#include "l1d_cid.h"
#include "l1d_loc_def.h"
#include "l1d_reg.h"
#include "l1d_custom_rf.h"
#include "l1d_rf.h"
#include "l1d_data.h"
#include "m12190.h"

/*---------------------------------------------------------------------------*/

#if IS_BSI_SX0_SUPPORT
#define  SETUP_SR0()                                                          \
   int  event_idx;                                                            \
   int  data_idx;                                                             \
   event_idx = l1d_rf.cwin_idx*CWIN_BSI_EVENT_COUNT+0;                        \
   data_idx  = l1d_rf.cwin_idx*(SX0_DATA_COUNT+SX1_DATA_COUNT+SX3_DATA_COUNT)+BSI_DATA_OFFSET;
#endif

#define  SETUP_SR1()                                                          \
   int  event_idx;                                                            \
   int  data_idx;                                                             \
   event_idx = l1d_rf.cwin_idx*CWIN_BSI_EVENT_COUNT+SR1_EVENT_OFFSET;         \
   data_idx  = l1d_rf.cwin_idx*(SX0_DATA_COUNT+SX1_DATA_COUNT+SX3_DATA_COUNT)+SX0_DATA_COUNT+BSI_DATA_OFFSET;

#define  SETUP_SR3()                                                          \
   int  event_idx;                                                            \
   int  data_idx;                                                             \
   event_idx = l1d_rf.cwin_idx*CWIN_BSI_EVENT_COUNT+SR1_EVENT_OFFSET+1;       \
   data_idx  = l1d_rf.cwin_idx*(SX0_DATA_COUNT+SX1_DATA_COUNT+SX3_DATA_COUNT)+SX0_DATA_COUNT+SX1_DATA_COUNT+BSI_DATA_OFFSET;

#define  SETUP_SR2()                                                          \
   int  event_idx;                                                            \
   int  data_idx;                                                             \
   event_idx = AGCIDX( l1d_rf.rtxwin_idx );                                   \
   data_idx  = AGCDTIDX( l1d_rf.rtxwin_idx );

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_BSI_V2_SUPPORT
#define  SETUP_ST2B_ST2M()  SETUP_SR2()
   #else
#define  SETUP_ST2B_ST2M()                                                    \
   int  event_idx;                                                            \
   int  data_idx;                                                             \
   event_idx = l1d_rf.rtxwin_idx+ST2B_ST2M_EV0;                               \
   data_idx  = ST2B_ST2M_IDX( l1d_rf.rtxwin_idx );
   #endif
#endif

#define  SETUP_ST0()  SETUP_SR0()
#define  SETUP_ST1()  SETUP_SR1()
#define  SETUP_ST2()  SETUP_SR2()
#define  SETUP_ST3()  SETUP_SR3()

#if IS_CHIP_SER_AND_LATTER(CHIP_ID_MT6572)
#define  HWRITE_1_SDATA( ctrl1, data1 )                                       \
{  HW_WRITE_BSI_DATA_1( data_idx, ((ctrl1)), (data1) );                       \
}

#define  HWRITE_2_SDATA( ctrl1, data1, ctrl2, data2 )                         \
{  HW_WRITE_BSI_DATA_2( data_idx, ((ctrl1)), (data1),                         \
                                  ((ctrl2)), (data2) );                       \
}

#define  HWRITE_3_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3 )           \
{  HW_WRITE_BSI_DATA_3( data_idx, ((ctrl1)), (data1),                         \
                                  ((ctrl2)), (data2),                         \
                                  ((ctrl3)), (data3) );                       \
}

#define  HWRITE_4_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4 )  \
{  HW_WRITE_BSI_DATA_4( data_idx, ((ctrl1)), (data1),                         \
                                  ((ctrl2)), (data2),                         \
                                  ((ctrl3)), (data3),                         \
                                  ((ctrl4)), (data4) );                       \
}

#define  HWRITE_5_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5 )  \
{  HW_WRITE_BSI_DATA_5( data_idx, ((ctrl1)), (data1),                         \
                                  ((ctrl2)), (data2),                         \
                                  ((ctrl3)), (data3),                         \
                                  ((ctrl4)), (data4),                         \
                                  ((ctrl5)), (data5) );                       \
}

#define  HWRITE_6_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6 )  \
{  HW_WRITE_BSI_DATA_6( data_idx, ((ctrl1)), (data1),                         \
                                  ((ctrl2)), (data2),                         \
                                  ((ctrl3)), (data3),                         \
                                  ((ctrl4)), (data4),                         \
                                  ((ctrl5)), (data5),                         \
                                  ((ctrl6)), (data6) );                       \
}

#define  HWRITE_7_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6, ctrl7, data7 )  \
{  HW_WRITE_BSI_DATA_7( data_idx, ((ctrl1)), (data1),                         \
                                  ((ctrl2)), (data2),                         \
                                  ((ctrl3)), (data3),                         \
                                  ((ctrl4)), (data4),                         \
                                  ((ctrl5)), (data5),                         \
                                  ((ctrl6)), (data6),                         \
                                  ((ctrl7)), (data7) );                       \
}

#define  HWRITE_8_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6, ctrl7, data7, ctrl8, data8 )  \
{  HW_WRITE_BSI_DATA_8( data_idx, ((ctrl1)), (data1),                         \
                                  ((ctrl2)), (data2),                         \
                                  ((ctrl3)), (data3),                         \
                                  ((ctrl4)), (data4),                         \
                                  ((ctrl5)), (data5),                         \
                                  ((ctrl6)), (data6),                         \
                                  ((ctrl7)), (data7),                         \
                                  ((ctrl8)), (data8) );                       \
}

#define  HWRITE_9_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6, ctrl7, data7, ctrl8, data8, ctrl9, data9 )  \
{  HW_WRITE_BSI_DATA_9( data_idx, ((ctrl1)), (data1),                         \
                                  ((ctrl2)), (data2),                         \
                                  ((ctrl3)), (data3),                         \
                                  ((ctrl4)), (data4),                         \
                                  ((ctrl5)), (data5),                         \
                                  ((ctrl6)), (data6),                         \
                                  ((ctrl7)), (data7),                         \
                                  ((ctrl8)), (data8),                         \
                                  ((ctrl9)), (data9) );                       \
}

#define  HWRITE_10_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6, ctrl7, data7, ctrl8, data8, ctrl9, data9, ctrl10, data10 )  \
{  HW_WRITE_BSI_DATA_10( data_idx, ((ctrl1 )), (data1 ),                      \
                                   ((ctrl2 )), (data2 ),                      \
                                   ((ctrl3 )), (data3 ),                      \
                                   ((ctrl4 )), (data4 ),                      \
                                   ((ctrl5 )), (data5 ),                      \
                                   ((ctrl6 )), (data6 ),                      \
                                   ((ctrl7 )), (data7 ),                      \
                                   ((ctrl8 )), (data8 ),                      \
                                   ((ctrl9 )), (data9 ),                      \
                                   ((ctrl10)), (data10) );                    \
}

#define  HWRITE_11_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6, ctrl7, data7, ctrl8, data8, ctrl9, data9, ctrl10, data10, ctrl11, data11 )  \
{  HW_WRITE_BSI_DATA_11( data_idx, ((ctrl1 )), (data1 ),                      \
                                   ((ctrl2 )), (data2 ),                      \
                                   ((ctrl3 )), (data3 ),                      \
                                   ((ctrl4 )), (data4 ),                      \
                                   ((ctrl5 )), (data5 ),                      \
                                   ((ctrl6 )), (data6 ),                      \
                                   ((ctrl7 )), (data7 ),                      \
                                   ((ctrl8 )), (data8 ),                      \
                                   ((ctrl9 )), (data9 ),                      \
                                   ((ctrl10)), (data10),                      \
                                   ((ctrl11)), (data11) );                    \
}

#define  HWRITE_12_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6, ctrl7, data7, ctrl8, data8, ctrl9, data9, ctrl10, data10, ctrl11, data11, ctrl12, data12 )  \
{  HW_WRITE_BSI_DATA_12( data_idx, ((ctrl1 )), (data1 ),                      \
                                   ((ctrl2 )), (data2 ),                      \
                                   ((ctrl3 )), (data3 ),                      \
                                   ((ctrl4 )), (data4 ),                      \
                                   ((ctrl5 )), (data5 ),                      \
                                   ((ctrl6 )), (data6 ),                      \
                                   ((ctrl7 )), (data7 ),                      \
                                   ((ctrl8 )), (data8 ),                      \
                                   ((ctrl9 )), (data9 ),                      \
                                   ((ctrl10)), (data10),                      \
                                   ((ctrl11)), (data11),                      \
                                   ((ctrl12)), (data12) );                    \
}

#define  HWRITE_13_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6, ctrl7, data7, ctrl8, data8, ctrl9, data9, ctrl10, data10, ctrl11, data11, ctrl12, data12, ctrl13, data13 )  \
{  HW_WRITE_BSI_DATA_13( data_idx, ((ctrl1 )), (data1 ),                      \
                                   ((ctrl2 )), (data2 ),                      \
                                   ((ctrl3 )), (data3 ),                      \
                                   ((ctrl4 )), (data4 ),                      \
                                   ((ctrl5 )), (data5 ),                      \
                                   ((ctrl6 )), (data6 ),                      \
                                   ((ctrl7 )), (data7 ),                      \
                                   ((ctrl8 )), (data8 ),                      \
                                   ((ctrl9 )), (data9 ),                      \
                                   ((ctrl10)), (data10),                      \
                                   ((ctrl11)), (data11),                      \
                                   ((ctrl12)), (data12),                      \
                                   ((ctrl13)), (data13) );                    \
}

#define  HWRITE_14_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6, ctrl7, data7, ctrl8, data8, ctrl9, data9, ctrl10, data10, ctrl11, data11, ctrl12, data12, ctrl13, data13, ctrl14, data14 )  \
{  HW_WRITE_BSI_DATA_14( data_idx, ((ctrl1 )), (data1 ),                      \
                                   ((ctrl2 )), (data2 ),                      \
                                   ((ctrl3 )), (data3 ),                      \
                                   ((ctrl4 )), (data4 ),                      \
                                   ((ctrl5 )), (data5 ),                      \
                                   ((ctrl6 )), (data6 ),                      \
                                   ((ctrl7 )), (data7 ),                      \
                                   ((ctrl8 )), (data8 ),                      \
                                   ((ctrl9 )), (data9 ),                      \
                                   ((ctrl10)), (data10),                      \
                                   ((ctrl11)), (data11),                      \
                                   ((ctrl12)), (data12),                      \
                                   ((ctrl13)), (data13),                      \
                                   ((ctrl14)), (data14) );                    \
}
/*---------------------------------------------------------------------------*/
#else
#define  HWRITE_1_SDATA( ctrl1, data1 )                                       \
{  HW_WRITE_BSI_DATA_1( data_idx, ((ctrl1)|event_idx), (data1) );             \
}

#define  HWRITE_2_SDATA( ctrl1, data1, ctrl2, data2 )                         \
{  HW_WRITE_BSI_DATA_2( data_idx, ((ctrl1)|event_idx), (data1),               \
                                  ((ctrl2)|event_idx), (data2) );             \
}

#define  HWRITE_3_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3 )           \
{  HW_WRITE_BSI_DATA_3( data_idx, ((ctrl1)|event_idx), (data1),               \
                                  ((ctrl2)|event_idx), (data2),               \
                                  ((ctrl3)|event_idx), (data3) );             \
}

#define  HWRITE_4_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4 )  \
{  HW_WRITE_BSI_DATA_4( data_idx, ((ctrl1)|event_idx), (data1),               \
                                  ((ctrl2)|event_idx), (data2),               \
                                  ((ctrl3)|event_idx), (data3),               \
                                  ((ctrl4)|event_idx), (data4) );             \
}

#define  HWRITE_5_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5 )  \
{  HW_WRITE_BSI_DATA_5( data_idx, ((ctrl1)|event_idx), (data1),               \
                                  ((ctrl2)|event_idx), (data2),               \
                                  ((ctrl3)|event_idx), (data3),               \
                                  ((ctrl4)|event_idx), (data4),               \
                                  ((ctrl5)|event_idx), (data5) );             \
}

#define  HWRITE_6_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6 )  \
{  HW_WRITE_BSI_DATA_6( data_idx, ((ctrl1)|event_idx), (data1),               \
                                  ((ctrl2)|event_idx), (data2),               \
                                  ((ctrl3)|event_idx), (data3),               \
                                  ((ctrl4)|event_idx), (data4),               \
                                  ((ctrl5)|event_idx), (data5),               \
                                  ((ctrl6)|event_idx), (data6) );             \
}

#define  HWRITE_7_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6, ctrl7, data7 )  \
{  HW_WRITE_BSI_DATA_7( data_idx, ((ctrl1)|event_idx), (data1),               \
                                  ((ctrl2)|event_idx), (data2),               \
                                  ((ctrl3)|event_idx), (data3),               \
                                  ((ctrl4)|event_idx), (data4),               \
                                  ((ctrl5)|event_idx), (data5),               \
                                  ((ctrl6)|event_idx), (data6),               \
                                  ((ctrl7)|event_idx), (data7) );             \
}

#define  HWRITE_8_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6, ctrl7, data7, ctrl8, data8 )  \
{  HW_WRITE_BSI_DATA_8( data_idx, ((ctrl1)|event_idx), (data1),               \
                                  ((ctrl2)|event_idx), (data2),               \
                                  ((ctrl3)|event_idx), (data3),               \
                                  ((ctrl4)|event_idx), (data4),               \
                                  ((ctrl5)|event_idx), (data5),               \
                                  ((ctrl6)|event_idx), (data6),               \
                                  ((ctrl7)|event_idx), (data7),               \
                                  ((ctrl8)|event_idx), (data8) );             \
}

#define  HWRITE_9_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6, ctrl7, data7, ctrl8, data8, ctrl9, data9 )  \
{  HW_WRITE_BSI_DATA_9( data_idx, ((ctrl1)|event_idx), (data1),               \
                                  ((ctrl2)|event_idx), (data2),               \
                                  ((ctrl3)|event_idx), (data3),               \
                                  ((ctrl4)|event_idx), (data4),               \
                                  ((ctrl5)|event_idx), (data5),               \
                                  ((ctrl6)|event_idx), (data6),               \
                                  ((ctrl7)|event_idx), (data7),               \
                                  ((ctrl8)|event_idx), (data8),               \
                                  ((ctrl9)|event_idx), (data9) );             \
}

#define  HWRITE_10_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6, ctrl7, data7, ctrl8, data8, ctrl9, data9, ctrl10, data10 )  \
{  HW_WRITE_BSI_DATA_10( data_idx, ((ctrl1 )|event_idx), (data1 ),            \
                                   ((ctrl2 )|event_idx), (data2 ),            \
                                   ((ctrl3 )|event_idx), (data3 ),            \
                                   ((ctrl4 )|event_idx), (data4 ),            \
                                   ((ctrl5 )|event_idx), (data5 ),            \
                                   ((ctrl6 )|event_idx), (data6 ),            \
                                   ((ctrl7 )|event_idx), (data7 ),            \
                                   ((ctrl8 )|event_idx), (data8 ),            \
                                   ((ctrl9 )|event_idx), (data9 ),            \
                                   ((ctrl10)|event_idx), (data10) );          \
}

#define  HWRITE_11_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6, ctrl7, data7, ctrl8, data8, ctrl9, data9, ctrl10, data10, ctrl11, data11 )  \
{  HW_WRITE_BSI_DATA_11( data_idx, ((ctrl1 )|event_idx), (data1 ),            \
                                   ((ctrl2 )|event_idx), (data2 ),            \
                                   ((ctrl3 )|event_idx), (data3 ),            \
                                   ((ctrl4 )|event_idx), (data4 ),            \
                                   ((ctrl5 )|event_idx), (data5 ),            \
                                   ((ctrl6 )|event_idx), (data6 ),            \
                                   ((ctrl7 )|event_idx), (data7 ),            \
                                   ((ctrl8 )|event_idx), (data8 ),            \
                                   ((ctrl9 )|event_idx), (data9 ),            \
                                   ((ctrl10)|event_idx), (data10),            \
                                   ((ctrl11)|event_idx), (data11) );          \
}

#define  HWRITE_12_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6, ctrl7, data7, ctrl8, data8, ctrl9, data9, ctrl10, data10, ctrl11, data11, ctrl12, data12 )  \
{  HW_WRITE_BSI_DATA_12( data_idx, ((ctrl1 )|event_idx), (data1 ),            \
                                   ((ctrl2 )|event_idx), (data2 ),            \
                                   ((ctrl3 )|event_idx), (data3 ),            \
                                   ((ctrl4 )|event_idx), (data4 ),            \
                                   ((ctrl5 )|event_idx), (data5 ),            \
                                   ((ctrl6 )|event_idx), (data6 ),            \
                                   ((ctrl7 )|event_idx), (data7 ),            \
                                   ((ctrl8 )|event_idx), (data8 ),            \
                                   ((ctrl9 )|event_idx), (data9 ),            \
                                   ((ctrl10)|event_idx), (data10),            \
                                   ((ctrl11)|event_idx), (data11),            \
                                   ((ctrl12)|event_idx), (data12) );          \
}

#define  HWRITE_13_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6, ctrl7, data7, ctrl8, data8, ctrl9, data9, ctrl10, data10, ctrl11, data11, ctrl12, data12, ctrl13, data13 )  \
{  HW_WRITE_BSI_DATA_13( data_idx, ((ctrl1 )|event_idx), (data1 ),            \
                                   ((ctrl2 )|event_idx), (data2 ),            \
                                   ((ctrl3 )|event_idx), (data3 ),            \
                                   ((ctrl4 )|event_idx), (data4 ),            \
                                   ((ctrl5 )|event_idx), (data5 ),            \
                                   ((ctrl6 )|event_idx), (data6 ),            \
                                   ((ctrl7 )|event_idx), (data7 ),            \
                                   ((ctrl8 )|event_idx), (data8 ),            \
                                   ((ctrl9 )|event_idx), (data9 ),            \
                                   ((ctrl10)|event_idx), (data10),            \
                                   ((ctrl11)|event_idx), (data11),            \
                                   ((ctrl12)|event_idx), (data12),            \
                                   ((ctrl13)|event_idx), (data13) );          \
}

#define  HWRITE_14_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5, ctrl6, data6, ctrl7, data7, ctrl8, data8, ctrl9, data9, ctrl10, data10, ctrl11, data11, ctrl12, data12, ctrl13, data13, ctrl14, data14 )  \
{  HW_WRITE_BSI_DATA_14( data_idx, ((ctrl1 )|event_idx), (data1 ),            \
                                   ((ctrl2 )|event_idx), (data2 ),            \
                                   ((ctrl3 )|event_idx), (data3 ),            \
                                   ((ctrl4 )|event_idx), (data4 ),            \
                                   ((ctrl5 )|event_idx), (data5 ),            \
                                   ((ctrl6 )|event_idx), (data6 ),            \
                                   ((ctrl7 )|event_idx), (data7 ),            \
                                   ((ctrl8 )|event_idx), (data8 ),            \
                                   ((ctrl9 )|event_idx), (data9 ),            \
                                   ((ctrl10)|event_idx), (data10),            \
                                   ((ctrl11)|event_idx), (data11),            \
                                   ((ctrl12)|event_idx), (data12),            \
                                   ((ctrl13)|event_idx), (data13),            \
                                   ((ctrl14)|event_idx), (data14) );          \
}
/*---------------------------------------------------------------------------*/
#endif

#if SX3_DATA_COUNT > SX2_DATA_COUNT
#error "Suspected insufficient BSI SX2 data resource to run SR3 at FSIWinOff scenario"
#endif

void  L1D_RF_ResetSData_StopFSIWinOff( int idx )
{  int i, n=AGCDTIDX(FS_RXWIN_IDX+idx);

   for( i=0; i<SX2_DATA_COUNT; i++, n++ )
      HW_WRITE( BSI_Dn_CON(n), SCTRL_RESERVED );
}

void L1D_RF_SetSData_FSIWinOff( int idx )
{
#if IS_RF_MT6163
   /* For multiple SR3 CW setup, use the new coding-friendly API instead of ori FSIWIN_STOP_BSI tables */
   L1D_RF_SetSData_FSIWinOff_SR3( idx );
#elif IS_RF_MT6162
   /* For two SR3 CW setup */
   /* For setting control-part (BSI event) of the additional 2nd BSI data */
   HW_WRITE( BSI_Dn_CON(AGCDTIDX(FS_RXWIN_IDX+idx)+1), (signed short)SCTRL_IDLE|AGCIDX(FS_RXWIN_IDX+idx) );

   HW_WRITE_BSI_DATA( FSWIN_STOP_BSI_REG_TABLE[idx  ], FSWIN_STOP_BSI_DATA_TABLE[0] );
   HW_WRITE_BSI_DATA( FSWIN_STOP_BSI_REG_TABLE[idx+2], FSWIN_STOP_BSI_DATA_TABLE[1] );
#elif IS_RF_MT6140D || IS_RF_AD6548 || IS_RF_AD6546 || IS_RF_MT6280RF || IS_RF_MT6169 || IS_RF_MT6166 || IS_RF_MT6165
   /* For one SR3 CW setup */
   HW_WRITE_BSI_DATA( FSWIN_STOP_BSI_REG_TABLE[idx], FSWIN_STOP_BSI_DATA_TABLE[0] );
#else
#error "Please confirm the number of RF SR3 data for FSIWinOff"
#endif
}

#if IS_BPI_DATA_32_BIT_CHIP
#define  BPI_REG_IDX  1
#else
#define  BPI_REG_IDX  2
#endif

#if IS_2G_TAS_SUPPORT
#define GET_TAS_BPI     (((L1_TAS_Custom_Params.EN_TAS||L1_TAS_Custom_Params.FORCE_TX_ANTENNA_ENABLE) && (l1d_rf.tas_ant_sel>=1))?L1_TAS_Custom_PData.pdata_band_tas[l1d_rf.band][(l1d_rf.tas_ant_sel-1)]:0)
#else
#define GET_TAS_BPI     0
#endif
void  L1D_RF_SetPData_PR( void )
{
   APBADDRBPI    _reg;
   const intBPI *_d16p;
   long         tas_bpi = GET_TAS_BPI;

   _reg  = PDATA_REG_TABLE[ l1d_rf.cwin_idx ];
#if IS_DCS_NB_WB_SWITCH_SUPPORT
   if( L1D_RF_IS_DCS_Change_to_NB() )
   {  _d16p = PDATA_TABLE[ 0 ][ RF_RX ];            }
   else
#endif
   {  _d16p = PDATA_TABLE[ l1d_rf.band ][ RF_RX ];  }
   HW_WRITE( _reg, (*_d16p)|tas_bpi );   _reg+=BPI_REG_IDX;   _d16p++;
   HW_WRITE( _reg, (*_d16p)|tas_bpi );   _reg+=BPI_REG_IDX;   _d16p++;
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   HW_WRITE( _reg, (*_d16p)|tas_bpi );
#else
   HW_WRITE( _reg, *_d16p );
#endif
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   _reg+=BPI_REG_IDX;   _d16p++;
   HW_WRITE( _reg, *_d16p );
   _d16p++;
   _reg = PDATA_REG_TABLE2[ l1d_rf.cwin_idx ];
   HW_WRITE( _reg, *_d16p );
#endif
}

void  L1D_RF_SetPData_PT( void )
{
#if !IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   APBADDR      _reg;
   const short *_d16p;
   long        tas_bpi = GET_TAS_BPI;

   _reg  = PDATA_REG_TABLE[ l1d_rf.cwin_idx ];
   _d16p = PDATA_TABLE[ l1d_rf.band ][ RF_TX ];
   HW_WRITE( _reg, (*_d16p)|tas_bpi );   _reg+=2;   _d16p++;
   HW_WRITE( _reg, (*_d16p)|tas_bpi );   _reg+=2;   _d16p++;
   HW_WRITE( _reg, *_d16p );
   #if IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6218~*/ {  int idx = l1d_rf.rx_slots<=11 ? 0 : 1;
/*MT6218~*/    _reg  = PDATA_PT2B_REG_TABLE[idx][ l1d_rf.cwin_idx ];
/*MT6218~*/    _d16p = PDATA_TABLE2[ l1d_rf.band ][ RF_TX ];
/*MT6218~*/    HW_WRITE( _reg, *_d16p );
/*MT6218~*/ }
   #endif

#else

   APBADDRBPI    _reg;
   const intBPI *_d16p;   
   long tas_bpi = GET_TAS_BPI;
   #if IS_BPI_V2_PT3A_SUPPORT
   unsigned char pt3a_idx = (l1d_rf.modidx==0) ? (0) : (1); /* l1d_rf.modidx => 0: the 1st CWIN; 4: the 2nd CWIN */
   #endif
   #if IS_DSDA_DCS_TX_NOTCH_SWITCH_SUPPORT
   if( L1D_RF_IS_DCS_Change_to_TX_Notch() ) 
      PDATA_TABLE = PDATA_TABLE_DCS_TX_NOTCH;
   else
      PDATA_TABLE = PDATA_TABLE_DEFAULT;
   #endif

   _reg  = PDATA_REG_TABLE[ l1d_rf.cwin_idx ];
   _d16p = PDATA_TABLE[ l1d_rf.band ][ RF_TX ];
   if ( (l1d_rf.tx_mod_type) & (1<<l1d_rf.modidx) )
   {
      HW_WRITE( _reg, ((*_d16p)|(pdata_8psk)|tas_bpi) );   _reg+=BPI_REG_IDX;   _d16p++;
      HW_WRITE( _reg, ((*_d16p)|(pdata_8psk)|tas_bpi) );   _reg+=BPI_REG_IDX;   _d16p++;
      HW_WRITE( _reg, ((*_d16p)|(pdata_8psk)|tas_bpi) );   _reg+=BPI_REG_IDX;   _d16p++;
      HW_WRITE( _reg, (*_d16p) );//PT3 is end, doesn't need to | PDATA_8PSK
      /* PT3A */
      _d16p++;
   #if IS_BPI_V2_PT3A_SUPPORT
      _reg = PDATA_REG_TABLE3[ pt3a_idx ];
   #else
      _reg = PDATA_REG_TABLE2[ l1d_rf.cwin_idx ];
   #endif
      HW_WRITE( _reg, (*_d16p) );
   }
   else
   {
      HW_WRITE( _reg, ((*_d16p)|(pdata_gmsk)|tas_bpi) );   _reg+=BPI_REG_IDX;   _d16p++;
      HW_WRITE( _reg, ((*_d16p)|(pdata_gmsk)|tas_bpi) );   _reg+=BPI_REG_IDX;   _d16p++;
      HW_WRITE( _reg, ((*_d16p)|(pdata_gmsk)|tas_bpi) );   _reg+=BPI_REG_IDX;   _d16p++;
      HW_WRITE( _reg, (*_d16p) );//PT3 is end, doesn't need to | PDATA_GMSK
      /* PT3A */
      _d16p++;
   #if IS_BPI_V2_PT3A_SUPPORT
      _reg = PDATA_REG_TABLE3[ pt3a_idx ];
   #else
      _reg = PDATA_REG_TABLE2[ l1d_rf.cwin_idx ];
   #endif
      HW_WRITE( _reg, (*_d16p) );
   }

#endif
}

void  L1D_RF_SetPData_PR2M( void )
{
#if IS_BPI_V2_SUPPORT
/*BPI v2 */ /* PR2M is not supported on BPI v2.0. */
#elif IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6218~*/ APBADDR      _reg;
/*MT6218~*/ const short *_d16p;
/*MT6218~*/ long        tas_bpi = GET_TAS_BPI;
/*MT6218~*/ 
/*MT6218~*/ _reg  = PDATA_PR2M_REG_TABLE[ l1d_rf.rtxwin_idx ];
/*MT6218~*/ _d16p = PDATA_TABLE2[ l1d_rf.band ][ RF_RX ];
/*MT6218~*/ HW_WRITE( _reg, *_d16p|tas_bpi);   _reg+=2;   _d16p++;
/*MT6218~*/ HW_WRITE( _reg, *_d16p|tas_bpi);
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6229~*/ APBADDR      _reg;
/*MT6229~*/ const short *_d16p;
/*MT6229~*/ long        tas_bpi = GET_TAS_BPI;
/*MT6229~*/
/*MT6229~*/ _reg  = PDATA_PR2M_REG_TABLE[ l1d_rf.rtxwin_idx ];
/*MT6229~*/ _d16p = PDATA_TABLE3[ l1d_rf.band ][ RF_RX ];
/*MT6229~*/ HW_WRITE( _reg, *_d16p|tas_bpi);   _reg+=2;   _d16p++;
/*MT6229~*/ HW_WRITE( _reg, *_d16p|tas_bpi);
#endif
}

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_EPSK_TX_SUPPORT
/*MT6229~*//*EGPRS*/ void  L1D_RF_SetPData_PT2M( void )
/*MT6229~*//*EGPRS*/ {
/*MT6229~*//*EGPRS*/    APBADDRBPI    _reg;
/*MT6229~*//*EGPRS*/    const intBPI *_d16p;
/*MT6229~*//*EGPRS*/    intBPI  _d16p2;
/*MT6229~*//*EGPRS*/    long         tas_bpi = GET_TAS_BPI;
      #if IS_DSDA_DCS_TX_NOTCH_SWITCH_SUPPORT
/*MT6229~*//*EGPRS*/   if( L1D_RF_IS_DCS_Change_to_TX_Notch() ) 
/*MT6229~*//*EGPRS*/      PDATA_TABLE = PDATA_TABLE_DCS_TX_NOTCH;
/*MT6229~*//*EGPRS*/   else
/*MT6229~*//*EGPRS*/      PDATA_TABLE = PDATA_TABLE_DEFAULT;
      #endif
/*MT6229~*//*EGPRS*/
/*MT6229~*//*EGPRS*/    _reg  = PDATA_PT2M_REG_TABLE[ l1d_rf.rtxwin_idx ];
/*MT6229~*//*EGPRS*/    _d16p = PDATA_TABLE3[ l1d_rf.band ][ RF_TX ];
/*MT6229~*//*EGPRS*/    _d16p2 = PDATA_TABLE[ l1d_rf.band ][ RF_TX ][2]; //PDATA of PT2B, so PT2B must later than PT2
/*MT6229~*//*EGPRS*/    //now 8PSK
/*MT6229~*//*EGPRS*/    if ((l1d_rf.tx_mod_type)&(1<<l1d_rf.rtxwin_idx))
/*MT6229~*//*EGPRS*/    {  //change, g-->8
/*MT6229~*//*EGPRS*/       if ((l1d_rf.change)&(1<<l1d_rf.rtxwin_idx))
/*MT6229~*//*EGPRS*/       {
/*MT6229~*//*EGPRS*/          /*Set M1*/ HW_WRITE( _reg, *_d16p|tas_bpi);   _reg+=BPI_REG_IDX;   _d16p++;
/*MT6229~*//*EGPRS*/          /*Set M2*/ HW_WRITE( _reg, *_d16p|tas_bpi);   _reg+=BPI_REG_IDX;   _d16p++;
/*MT6229~*//*EGPRS*/          /*Set M3*/ HW_WRITE( _reg, *_d16p|tas_bpi);
/*MT6229~*//*EGPRS*/       }
/*MT6229~*//*EGPRS*/       //no change
/*MT6229~*//*EGPRS*/       else
/*MT6229~*//*EGPRS*/       {  HW_WRITE( _reg, ((_d16p2)|(pdata_8psk)|tas_bpi) );   _reg+=BPI_REG_IDX;
/*MT6229~*//*EGPRS*/          HW_WRITE( _reg, ((_d16p2)|(pdata_8psk)|tas_bpi) );   _reg+=BPI_REG_IDX;
/*MT6229~*//*EGPRS*/          HW_WRITE( _reg, ((_d16p2)|(pdata_8psk)|tas_bpi) );
/*MT6229~*//*EGPRS*/       }
/*MT6229~*//*EGPRS*/    }
/*MT6229~*//*EGPRS*/    //now GMSK
/*MT6229~*//*EGPRS*/    else
/*MT6229~*//*EGPRS*/    {  //change, 8-->g
/*MT6229~*//*EGPRS*/       _d16p = PDATA_TABLE3[ l1d_rf.band ][ RF_TX_8G];
/*MT6229~*//*EGPRS*/       if ((l1d_rf.change)&(1<<l1d_rf.rtxwin_idx))
/*MT6229~*//*EGPRS*/       {
/*MT6229~*//*EGPRS*/          /*Set M1*/ HW_WRITE( _reg, *_d16p|tas_bpi);   _reg+=BPI_REG_IDX;   _d16p++;
/*MT6229~*//*EGPRS*/          /*Set M2*/ HW_WRITE( _reg, *_d16p|tas_bpi);   _reg+=BPI_REG_IDX;   _d16p++;
/*MT6229~*//*EGPRS*/          /*Set M3*/ HW_WRITE( _reg, *_d16p|tas_bpi);
/*MT6229~*//*EGPRS*/       }
/*MT6229~*//*EGPRS*/       //no change
/*MT6229~*//*EGPRS*/       else
/*MT6229~*//*EGPRS*/       {  HW_WRITE( _reg, ((_d16p2)|(pdata_gmsk)|tas_bpi) );   _reg+=BPI_REG_IDX;
/*MT6229~*//*EGPRS*/          HW_WRITE( _reg, ((_d16p2)|(pdata_gmsk)|tas_bpi) );   _reg+=BPI_REG_IDX;
/*MT6229~*//*EGPRS*/          HW_WRITE( _reg, ((_d16p2)|(pdata_gmsk)|tas_bpi) );
/*MT6229~*//*EGPRS*/       }
/*MT6229~*//*EGPRS*/    }
/*MT6229~*//*EGPRS*/
/*MT6229~*//*EGPRS*/ }
   #else
/*MT6229~*/ void  L1D_RF_SetPData_PT2M( void )
/*MT6229~*/ {
/*MT6229~*/ }
   #endif /*End of IS_EPSK_TX_SUPPORT*/
#else
/*mt6218~*/ void  L1D_RF_SetPData_PT2M( void )
/*mt6218~*/ {
/*mt6218~*/ }
#endif

#if IS_RF_BRIGHT2
/*BRIGHT2*/
/*BRIGHT2*/ /*..........................................................*/
/*BRIGHT2*/ /*  Define Alias and Table                                  */
/*BRIGHT2*/ /*..........................................................*/
/*BRIGHT2*/
/*BRIGHT2*/ #if IS_FPGA_TARGET
/*BRIGHT2*/ /*FPGA*/   #define SCTRL_PLL         SCTRL_WORD(0,22)
/*BRIGHT2*/ /*FPGA*/   #define SCTRL_GAIN        SCTRL_WORD(1, 8)
/*BRIGHT2*/ #endif
/*BRIGHT2*/ #if IS_CHIP_TARGET
/*BRIGHT2*/ /*MT6208*/ #define SCTRL_PLL         SCTRL_WORD(1,22)
/*BRIGHT2*/ /*MT6208*/ #define SCTRL_GAIN        SCTRL_WORD(0, 8)
/*BRIGHT2*/ #endif
/*BRIGHT2*/
/*BRIGHT2*/ #define  SDATA_SYN_ON                ((0x0008<<4)|0)
/*BRIGHT2*/ #define  SDATA_SYN_OFF               ((0x0000<<4)|0)
/*BRIGHT2*/ #define  SDATA_IFN                   ((2700L<<4)|5)
/*BRIGHT2*/
/*BRIGHT2*/ /*..........................................................*/
/*BRIGHT2*/ /* Serial Interface Implement                               */
/*BRIGHT2*/ /*..........................................................*/
/*BRIGHT2*/
/*BRIGHT2*/ void  L1D_RF_SetSData_SR1( void )
/*BRIGHT2*/ {
/*BRIGHT2*/    SETUP_SR1();
/*BRIGHT2*/    HWRITE_3_SDATA( SCTRL_PLL, SDATA_SYN_ON,
/*BRIGHT2*/                    SCTRL_PLL, l1d_rf.RFN_data,
/*BRIGHT2*/                    SCTRL_PLL, l1d_rf.IFN_data );
/*BRIGHT2*/ }
/*BRIGHT2*/
/*BRIGHT2*/ void  L1D_RF_SetSData_SR2( void )
/*BRIGHT2*/ {
/*BRIGHT2*/    SETUP_SR2();
/*BRIGHT2*/    HWRITE_1_SDATA( SCTRL_GAIN, l1d_rf.AGC_data );
/*BRIGHT2*/ }
/*BRIGHT2*/
/*BRIGHT2*/ void  L1D_RF_SetSData_SR3( void )
/*BRIGHT2*/ {
/*BRIGHT2*/    SETUP_SR3();
/*BRIGHT2*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*BRIGHT2*/ }
/*BRIGHT2*/
/*BRIGHT2*/ void  L1D_RF_SetSData_ST1( void )
/*BRIGHT2*/ {
/*BRIGHT2*/    SETUP_ST1();
/*BRIGHT2*/    HWRITE_3_SDATA( SCTRL_PLL, SDATA_SYN_ON,
/*BRIGHT2*/                    SCTRL_PLL, l1d_rf.RFN_data,
/*BRIGHT2*/                    SCTRL_PLL, l1d_rf.IFN_data );
/*BRIGHT2*/ }
/*BRIGHT2*/
/*BRIGHT2*/ void  L1D_RF_SetSData_ST2( void )
/*BRIGHT2*/ {
/*BRIGHT2*/    SETUP_ST2();
/*BRIGHT2*/    HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*BRIGHT2*/ }
/*BRIGHT2*/
/*BRIGHT2*/ void  L1D_RF_SetSData_ST3( void )
/*BRIGHT2*/ {
/*BRIGHT2*/    SETUP_ST3();
/*BRIGHT2*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*BRIGHT2*/ }
/*BRIGHT2*/
#endif

#if IS_RF_BRIGHT4
/*BRIGHT4*/
/*BRIGHT4*/ /*..........................................................*/
/*BRIGHT4*/ /*  Define Alias and Table                                  */
/*BRIGHT4*/ /*..........................................................*/
/*BRIGHT4*/
/*BRIGHT4*/ #define  SCTRL_PLL                   SCTRL_WORD(0,24)
/*BRIGHT4*/ #define  SCTRL_GAIN                  SCTRL_WORD(0,16)
/*BRIGHT4*/ #define  SCTRL_TXBAND                SCTRL_WORD(0,12)
/*BRIGHT4*/
/*BRIGHT4*/ const unsigned long SDATA_TXBAND_TABLE[5] =
/*BRIGHT4*/ {
/*BRIGHT4*/         0L,   /* FrequencyBand400 (not support)  */
/*BRIGHT4*/         0L,   /* FrequencyBand850 (not support)  */
/*BRIGHT4*/    0x051BL,   /* FrequencyBand900                */
/*BRIGHT4*/    0x001BL,   /* FrequencyBand1800               */
/*BRIGHT4*/    0x0D1BL,   /* FrequencyBand1900               */
/*BRIGHT4*/ };
/*BRIGHT4*/
/*BRIGHT4*/ /*..........................................................*/
/*BRIGHT4*/ /* Serial Interface Implement                               */
/*BRIGHT4*/ /*..........................................................*/
/*BRIGHT4*/
/*BRIGHT4*/ void  L1D_RF_SetSData_SR1( void )
/*BRIGHT4*/ {
/*BRIGHT4*/    SETUP_SR1();
/*BRIGHT4*/    HWRITE_1_SDATA( SCTRL_PLL, l1d_rf.RFN_data );
/*BRIGHT4*/ }
/*BRIGHT4*/
/*BRIGHT4*/ void  L1D_RF_SetSData_SR2( void )
/*BRIGHT4*/ {
/*BRIGHT4*/    SETUP_SR2();
/*BRIGHT4*/    HWRITE_1_SDATA( SCTRL_GAIN, l1d_rf.AGC_data );
/*BRIGHT4*/ }
/*BRIGHT4*/
/*BRIGHT4*/ void  L1D_RF_SetSData_SR3( void )
/*BRIGHT4*/ {
/*BRIGHT4*/    SETUP_SR3();
/*BRIGHT4*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*BRIGHT4*/ }
/*BRIGHT4*/
/*BRIGHT4*/ void  L1D_RF_SetSData_ST1( void )
/*BRIGHT4*/ {
/*BRIGHT4*/    SETUP_ST1();
/*BRIGHT4*/    HWRITE_1_SDATA( SCTRL_PLL, l1d_rf.RFN_data );
/*BRIGHT4*/ }
/*BRIGHT4*/
/*BRIGHT4*/ void  L1D_RF_SetSData_ST2( void )
/*BRIGHT4*/ {
/*BRIGHT4*/    SETUP_ST2();
/*BRIGHT4*/    HWRITE_1_SDATA( SCTRL_TXBAND, SDATA_TXBAND_TABLE[l1d_rf.band] );
/*BRIGHT4*/ }
/*BRIGHT4*/
/*BRIGHT4*/ void  L1D_RF_SetSData_ST3( void )
/*BRIGHT4*/ {
/*BRIGHT4*/    SETUP_ST3();
/*BRIGHT4*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*BRIGHT4*/ }
/*BRIGHT4*/
#endif

#if IS_RF_BRIGHT5P
/*BRIGHT5P*/
/*BRIGHT5P*/ /*..........................................................*/
/*BRIGHT5P*/ /*  Define Alias and Table                                  */
/*BRIGHT5P*/ /*..........................................................*/
/*BRIGHT5P*/
/*BRIGHT5P*/ #define  SCTRL_PLL                   SCTRL_WORD(0,24)
/*BRIGHT5P*/ #define  SCTRL_GAIN                  SCTRL_WORD(0,24)
/*BRIGHT5P*/ #define  SCTRL_TXBAND                SCTRL_WORD(0,24)
/*BRIGHT5P*/
/*BRIGHT5P*/ /*barry const*/ unsigned long SDATA_TXBAND_TABLE[5] =
/*BRIGHT5P*/ {
/*BRIGHT5P*/           0L,   /* FrequencyBand400 (not support)  */
/*BRIGHT5P*/    0x07FF9BL,//8BL,   /* FrequencyBand850                */
/*BRIGHT5P*/    0x07FF9BL,//8BL,   /* FrequencyBand900                */
/*BRIGHT5P*/    0x07FF9BL,//8BL,   /* FrequencyBand1800               */
/*BRIGHT5P*/    0x07FF9BL,//8BL,   /* FrequencyBand1900               */
/*BRIGHT5P*/ };
/*BRIGHT5P*/
/*BRIGHT5P*/ /*barry const*/ unsigned long SDATA_TXBAND_TABLE_2[5][2] =
/*BRIGHT5P*/ {    // G0         E0
/*BRIGHT5P*/    {        0L, 0L         },  /* FrequencyBand400 (not support)  */
/*BRIGHT5P*/    { 0x07FF8BL, 0x07FF9BL  },//8BL,   /* FrequencyBand850                */
/*BRIGHT5P*/    { 0x07FF8BL, 0x07FF9BL  },//8BL,   /* FrequencyBand900                */
/*BRIGHT5P*/    { 0x07FF8BL, 0x07FF9BL  },//8BL,   /* FrequencyBand1800               */
/*BRIGHT5P*/    { 0x07FF8BL, 0x07FF9BL  } //8BL,   /* FrequencyBand1900               */
/*BRIGHT5P*/ };
/*BRIGHT5P*/
/*BRIGHT5P*/ /*barry const*/ unsigned long SDATA_TXBAND_TABLE_3[5][2] =
/*BRIGHT5P*/ {    //8-->G   //G-->8
/*BRIGHT5P*/    {       0L,          0L, },  /* FrequencyBand400 (not support)  */
/*BRIGHT5P*/    {0x07FFEBL,   0x07FFC3L, },//8BL,   /* FrequencyBand850                */
/*BRIGHT5P*/    {0x07FFEBL,   0x07FFC3L, },//8BL,   /* FrequencyBand900                */
/*BRIGHT5P*/    {0x07FFEBL,   0x07FFC3L, },//8BL,   /* FrequencyBand1800               */
/*BRIGHT5P*/    {0x07FFEBL,   0x07FFC3L, } //8BL,   /* FrequencyBand1900               */
/*BRIGHT5P*/ };
/*BRIGHT5P*/
/*BRIGHT5P*/ /*..........................................................*/
/*BRIGHT5P*/ /* Serial Interface Implement                               */
/*BRIGHT5P*/ /*..........................................................*/
/*BRIGHT5P*/
/*BRIGHT5P*/ void  L1D_RF_SetSData_SR1( void )
/*BRIGHT5P*/ {
/*BRIGHT5P*/    SETUP_SR1();
/*BRIGHT5P*/    HWRITE_1_SDATA( SCTRL_PLL, l1d_rf.RFN_data | 0x000000 );
/*BRIGHT5P*/ }
/*BRIGHT5P*/
/*BRIGHT5P*/ void  L1D_RF_SetSData_SR2( void )
/*BRIGHT5P*/ {
/*BRIGHT5P*/    SETUP_SR2();
/*BRIGHT5P*/    HWRITE_1_SDATA( SCTRL_GAIN, l1d_rf.AGC_data );
/*BRIGHT5P*/ }
/*BRIGHT5P*/
/*BRIGHT5P*/ void  L1D_RF_SetSData_SR3( void )
/*BRIGHT5P*/ {
/*BRIGHT5P*/    SETUP_SR3();
/*BRIGHT5P*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*BRIGHT5P*/ }
/*BRIGHT5P*/
/*BRIGHT5P*/ void  L1D_RF_SetSData_ST1( void )
/*BRIGHT5P*/ {
/*BRIGHT5P*/    SETUP_ST1();
/*BRIGHT5P*/    HWRITE_1_SDATA( SCTRL_PLL, l1d_rf.RFN_data );
/*BRIGHT5P*/ }
/*BRIGHT5P*/
/*BRIGHT5P*/ void  L1D_RF_SetSData_ST2( void )
/*BRIGHT5P*/ {
/*BRIGHT5P*/ }
/*BRIGHT5P*/
/*BRIGHT5P*/ void  L1D_RF_SetSData_ST3( void )
/*BRIGHT5P*/ {
/*BRIGHT5P*/    SETUP_ST3();
/*BRIGHT5P*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*BRIGHT5P*/ }
/*BRIGHT5P*/
/*BRIGHT5P*/ void  L1D_RF_SetSData_ST2B( void )
/*BRIGHT5P*/ {
/*BRIGHT5P*/    SETUP_ST2B_ST2M();
/*BRIGHT5P*/    // Meta calibration use
/*BRIGHT5P*/    if(RFSpecialCoef.tx.b5ptx.data.c3mode)
/*BRIGHT5P*/    {
/*BRIGHT5P*/       HWRITE_1_SDATA( SCTRL_TXBAND, RFSpecialCoef.tx.b5ptx.data.wordC3 );
/*BRIGHT5P*/    }
/*BRIGHT5P*/
/*BRIGHT5P*/    else if ( (l1d_rf.tx_mod_type) & (1<<l1d_rf.modidx) ) //8psk
/*BRIGHT5P*/    {
/*BRIGHT5P*/       HWRITE_1_SDATA(SCTRL_TXBAND,   SDATA_TXBAND_TABLE_2[l1d_rf.band][1]  );
/*BRIGHT5P*/    }
/*BRIGHT5P*/    else //gmsk
/*BRIGHT5P*/    {
/*BRIGHT5P*/       HWRITE_1_SDATA(SCTRL_TXBAND,   SDATA_TXBAND_TABLE_2[l1d_rf.band][0]  );
/*BRIGHT5P*/    }
/*BRIGHT5P*/ }
/*BRIGHT5P*/
/*BRIGHT5P*/ void  L1D_RF_SetSData_ST2M( void )
/*BRIGHT5P*/ {
/*BRIGHT5P*/    SETUP_ST2B_ST2M();
/*BRIGHT5P*/
/*BRIGHT5P*/    //now 8PSK
/*BRIGHT5P*/    if ((l1d_rf.tx_mod_type)&(1<<l1d_rf.rtxwin_idx))
/*BRIGHT5P*/    {  //change
/*BRIGHT5P*/       if ((l1d_rf.change)&(1<<l1d_rf.rtxwin_idx))
/*BRIGHT5P*/       {   HWRITE_1_SDATA(SCTRL_TXBAND,     SDATA_TXBAND_TABLE_3[l1d_rf.band][1] );    }
/*BRIGHT5P*/       else
/*BRIGHT5P*/       {   HWRITE_1_SDATA(SCTRL_RESERVED,     0 );    }
/*BRIGHT5P*/    }
/*BRIGHT5P*/    //now GMSK
/*BRIGHT5P*/    else
/*BRIGHT5P*/    {  //change
/*BRIGHT5P*/       if ((l1d_rf.change)&(1<<l1d_rf.rtxwin_idx))
/*BRIGHT5P*/       {   HWRITE_1_SDATA(SCTRL_TXBAND,     SDATA_TXBAND_TABLE_3[l1d_rf.band][0] );      }
/*BRIGHT5P*/       else
/*BRIGHT5P*/       {   HWRITE_1_SDATA(SCTRL_RESERVED,     0 );    }
/*BRIGHT5P*/    }
/*BRIGHT5P*/ }
/*BRIGHT5P*/
#endif

#if IS_RF_AERO
/*AERO*/
/*AERO*/ /*..........................................................*/
/*AERO*/ /*  Define Alias and Table                                  */
/*AERO*/ /*..........................................................*/
/*AERO*/
/*AERO*/ #define  SCTRL_PLL                   SCTRL_WORD(0,24)
/*AERO*/ #define  SCTRL_GAIN                  SCTRL_WORD(0,24)
/*AERO*/
/*AERO*/ /*..........................................................*/
/*AERO*/ /* Serial Interface Implement                               */
/*AERO*/ /*..........................................................*/
/*AERO*/
/*AERO*/ void  L1D_RF_SetSData_SR1( void )
/*AERO*/ {
/*AERO*/    SETUP_SR1();
/*AERO*/    HWRITE_2_SDATA( SCTRL_PLL     , l1d_rf.RFN_data,
/*AERO*/                    SCTRL_RESERVED, 0);
/*AERO*/ }
/*AERO*/
/*AERO*/ void  L1D_RF_SetSData_SR2( void )
/*AERO*/ {
/*AERO*/    SETUP_SR2();
/*AERO*/    HWRITE_1_SDATA( SCTRL_GAIN, l1d_rf.AGC_data );
/*AERO*/ }
/*AERO*/
/*AERO*/ void  L1D_RF_SetSData_SR3( void )
/*AERO*/ {
/*AERO*/    SETUP_SR3();
/*AERO*/    HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*AERO*/ }
/*AERO*/
/*AERO*/ void  L1D_RF_SetSData_ST1( void )
/*AERO*/ {
/*AERO*/    SETUP_ST1();
/*AERO*/    HWRITE_2_SDATA( SCTRL_PLL, l1d_rf.RFN_data,
/*AERO*/                    SCTRL_PLL, l1d_rf.IFN_data );
/*AERO*/ }
/*AERO*/
/*AERO*/ void  L1D_RF_SetSData_ST2( void )
/*AERO*/ {
/*AERO*/    SETUP_ST2();
/*AERO*/    HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*AERO*/ }
/*AERO*/
/*AERO*/ void  L1D_RF_SetSData_ST3( void )
/*AERO*/ {
/*AERO*/    SETUP_ST3();
/*AERO*/    HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*AERO*/ }
/*AERO*/
#endif

#if IS_RF_AERO1PLUS
/*AERO1+*/
/*AERO1+*/ /*..........................................................*/
/*AERO1+*/ /*  Define Alias and Table                                  */
/*AERO1+*/ /*..........................................................*/
/*AERO1+*/
/*AERO1+*/ #define  SCTRL_PLL                   SCTRL_WORD(0,24)
/*AERO1+*/ #define  SCTRL_GAIN                  SCTRL_WORD(0,24)
/*AERO1+*/
/*AERO1+*/ /*..........................................................*/
/*AERO1+*/ /* Serial Interface Implement                               */
/*AERO1+*/ /*..........................................................*/
/*AERO1+*/
/*AERO1+*/ void  L1D_RF_SetSData_SR1( void )
/*AERO1+*/ {
/*AERO1+*/    SETUP_SR1();
/*AERO1+*/    HWRITE_2_SDATA( SCTRL_PLL     , l1d_rf.RFN_data,
/*AERO1+*/                    SCTRL_RESERVED, 0);
/*AERO1+*/ }
/*AERO1+*/
/*AERO1+*/ void  L1D_RF_SetSData_SR2( void )
/*AERO1+*/ {
/*AERO1+*/    SETUP_SR2();
/*AERO1+*/    HWRITE_1_SDATA( SCTRL_GAIN, l1d_rf.AGC_data );
/*AERO1+*/ }
/*AERO1+*/
/*AERO1+*/ void  L1D_RF_SetSData_SR3( void )
/*AERO1+*/ {
/*AERO1+*/    SETUP_SR3();
/*AERO1+*/    HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*AERO1+*/ }
/*AERO1+*/
/*AERO1+*/ void  L1D_RF_SetSData_ST1( void )
/*AERO1+*/ {
/*AERO1+*/    SETUP_ST1();
/*AERO1+*/    HWRITE_2_SDATA( SCTRL_PLL, l1d_rf.RFN_data,
/*AERO1+*/                    SCTRL_PLL, l1d_rf.IFN_data );
/*AERO1+*/ }
/*AERO1+*/
/*AERO1+*/ void  L1D_RF_SetSData_ST2( void )
/*AERO1+*/ {
/*AERO1+*/    SETUP_ST2();
/*AERO1+*/    HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*AERO1+*/ }
/*AERO1+*/
/*AERO1+*/ void  L1D_RF_SetSData_ST3( void )
/*AERO1+*/ {
/*AERO1+*/    SETUP_ST3();
/*AERO1+*/    HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*AERO1+*/ }
/*AERO1+*/
#endif

#if IS_RF_POLARIS1
/*RFMD*/
/*RFMD*/ /*..........................................................*/
/*RFMD*/ /*  Define Alias and Table                                  */
/*RFMD*/ /*..........................................................*/
/*RFMD*/
/*RFMD*/ #define  SCTRL_CFG3        SCTRL_WORD(0,24)
/*RFMD*/ #define  SCTRL_OFFS        SCTRL_WORD(0,24)
/*RFMD*/ #define  SCTRL_CF          SCTRL_WORD(0,24)
/*RFMD*/ #define  SCTRL_CFG1        SCTRL_WORD(0,24)
/*RFMD*/
/*RFMD*/ const unsigned long SDATA_RXLNASEL_TABLE[5] =
/*RFMD*/ {
/*RFMD*/             0L,   /* FrequencyBand400 (not support)  */
/*RFMD*/             0L,   /* FrequencyBand850 (not support)  */
/*RFMD*/    //0x940002L,   /* FrequencyBand900                */
/*RFMD*/      0x940000L,   /* FrequencyBand900                */
/*RFMD*/    //0x947002L,   /* FrequencyBand1800               */
/*RFMD*/      0x947000L,   /* FrequencyBand1800               */
/*RFMD*/    //0x945002L    /* FrequencyBand1900               */
/*RFMD*/      0x945000L    /* FrequencyBand1900               */
/*RFMD*/ };
/*RFMD*/
/*RFMD*/ const unsigned long SDATA_TXPLLSEL_TABLE[5] =
/*RFMD*/ {
/*RFMD*/             0L,   /* FrequencyBand400 (not support)  */
/*RFMD*/             0L,   /* FrequencyBand850 (not support)  */
/*RFMD*/      0x0aa503L,   /* FrequencyBand900                */
/*RFMD*/      0x099800L,   /* FrequencyBand1800               */
/*RFMD*/      0x099c00L    /* FrequencyBand1900               */
/*RFMD*/ };
/*RFMD*/ const unsigned long SDATA_TXBUFFER_TABLE[5]=
/*RFMD*/ {
/*RFMD*/             0L,   /* FrequencyBand400 (not support)  */
/*RFMD*/             0L,   /* FrequencyBand850 (not support)  */
/*RFMD*/      0x940000L,   /* FrequencyBand900                */
/*RFMD*/      0x960000L,   /* FrequencyBand1800               */
/*RFMD*/      0x960000L    /* FrequencyBand1900               */
/*RFMD*/ };
/*RFMD*/
/*RFMD*/ /*..........................................................*/
/*RFMD*/ /* Serial Interface Implement                               */
/*RFMD*/ /*..........................................................*/
/*RFMD*/
/*RFMD*/ void  L1D_RF_SetSData_SR1( void )
/*RFMD*/ {
/*RFMD*/    SETUP_SR1();
/*RFMD*/    HWRITE_2_SDATA( SCTRL_CFG3, 0x080008,
/*RFMD*/                    SCTRL_OFFS, l1d_rf.RFN_data );
/*RFMD*/ }
/*RFMD*/
/*RFMD*/ void  L1D_RF_SetSData_SR2( void )
/*RFMD*/ {
/*RFMD*/    SETUP_SR2();
/*RFMD*/    HWRITE_2_SDATA( SCTRL_CFG3, 0x080000 | (l1d_rf.AGC_data & 0x000f),
/*RFMD*/                    SCTRL_CF,   SDATA_RXLNASEL_TABLE[l1d_rf.band] + ((l1d_rf.AGC_data & 0x0010)>>4) + ((l1d_rf.AGC_data & 0x7fe0)>>3) ) ;
/*RFMD*/ }
/*RFMD*/
/*RFMD*/ void  L1D_RF_SetSData_SR3( void )
/*RFMD*/ {  /*do nothing*/
/*RFMD*/ }
/*RFMD*/
/*RFMD*/ void  L1D_RF_SetSData_ST1( void )
/*RFMD*/ {
/*RFMD*/    SETUP_ST1();
/*RFMD*/    HWRITE_2_SDATA( SCTRL_CFG1, 0x000000,
/*RFMD*/                    SCTRL_CFG3, SDATA_TXPLLSEL_TABLE[l1d_rf.band] );
/*RFMD*/ }
/*RFMD*/
/*RFMD*/ void  L1D_RF_SetSData_ST2( void )
/*RFMD*/ {
/*RFMD*/    SETUP_ST2();
/*RFMD*/    HWRITE_2_SDATA( SCTRL_OFFS, l1d_rf.RFN_data,
/*RFMD*/                    SCTRL_CF  , SDATA_TXBUFFER_TABLE[l1d_rf.band] );
/*RFMD*/ }
/*RFMD*/
/*RFMD*/ void  L1D_RF_SetSData_ST3( void )
/*RFMD*/ {  /*do nothing*/
/*RFMD*/ }
/*RFMD*/
#endif

#if IS_RF_SKY74117
/*SKY74117*/
/*SKY74117*/ /*..........................................................*/
/*SKY74117*/ /*  Define Alias and Table                                  */
/*SKY74117*/ /*..........................................................*/
/*SKY74117*/
/*SKY74117*/ #define  SCTRL_SKY74117   SCTRL_WORD(0,24)
/*SKY74117*/
/*SKY74117*/ extern unsigned long  SKY74117_TxCtrl_Mask;
/*SKY74117*/ extern unsigned long  SKY74117_TxCtrl;
/*SKY74117*/ unsigned long  SKY74117_BANDINFO[5][2] =
/*SKY74117*/ {  /* LO Chain Test Register, Rx Test Register */
/*SKY74117*/    {                       0,        0         },
/*SKY74117*/    {                0x007F06, 0x18040E         },
/*SKY74117*/    {                0x007F06, 0x18040E         },
/*SKY74117*/    {                0x00FF06, 0x00040E         },
/*SKY74117*/    {                0x00FF06, 0x00040E         },
/*SKY74117*/ };
/*SKY74117*/
/*SKY74117*/ /*..........................................................*/
/*SKY74117*/ /* Serial Interface Implement                               */
/*SKY74117*/ /*..........................................................*/
/*SKY74117*/
/*SKY74117*/ void  L1D_RF_SetSData_SR1( void )
/*SKY74117*/ {
/*SKY74117*/    SETUP_SR1();
/*SKY74117*/    HWRITE_4_SDATA( SCTRL_SKY74117, SKY74117_BANDINFO[l1d_rf.band][0],
/*SKY74117*/                    SCTRL_SKY74117, SKY74117_BANDINFO[l1d_rf.band][1],
/*SKY74117*/                    SCTRL_SKY74117, l1d_rf.IFN_data,
/*SKY74117*/                    SCTRL_SKY74117, l1d_rf.RFN_data );
/*SKY74117*/ }
/*SKY74117*/
/*SKY74117*/ void  L1D_RF_SetSData_SR2( void )
/*SKY74117*/ {
/*SKY74117*/    SETUP_SR2();
/*SKY74117*/    HWRITE_1_SDATA( SCTRL_SKY74117, (l1d_rf.AGC_data|SKY74117_TxCtrl_Mask) );
/*SKY74117*/ }
/*SKY74117*/
/*SKY74117*/ void  L1D_RF_SetSData_SR3( void )
/*SKY74117*/ {
/*SKY74117*/ }
/*SKY74117*/
/*SKY74117*/ void  L1D_RF_SetSData_ST1( void )
/*SKY74117*/ {
/*SKY74117*/    SETUP_ST1();
/*SKY74117*/    HWRITE_4_SDATA( SCTRL_SKY74117, SKY74117_BANDINFO[l1d_rf.band][0],
/*SKY74117*/                    SCTRL_SKY74117, SKY74117_BANDINFO[l1d_rf.band][1],
/*SKY74117*/                    SCTRL_SKY74117, l1d_rf.IFN_data,
/*SKY74117*/                    SCTRL_SKY74117, l1d_rf.RFN_data );
/*SKY74117*/
/*SKY74117*/    if( l1d_rf.d2c_txiqswap==0 )
/*SKY74117*/    {  BFETXSET  bfetxset;
/*SKY74117*/       HW_READ_BFETXSET( bfetxset );
/*SKY74117*/       bfetxset.field.iqswap = l1d_rf.inj & 0x1;
/*SKY74117*/       HW_WRITE_BFETXSET( bfetxset );
/*SKY74117*/    }
/*SKY74117*/ }
/*SKY74117*/
/*SKY74117*/ void  L1D_RF_SetSData_ST2( void )
/*SKY74117*/ {  SETUP_ST2();
/*SKY74117*/    HWRITE_1_SDATA( SCTRL_SKY74117, SKY74117_TxCtrl );
/*SKY74117*/ }
/*SKY74117*/
/*SKY74117*/ void  L1D_RF_SetSData_ST3( void )
/*SKY74117*/ {
/*SKY74117*/ }
/*SKY74117*/
#endif

#if IS_RF_SKY74400
/*SKY74400*/
/*SKY74400*/ /*..........................................................*/
/*SKY74400*/ /*  Define Alias and Table                                  */
/*SKY74400*/ /*..........................................................*/
/*SKY74400*/
/*SKY74400*/ #define  SCTRL_SKY74400   SCTRL_WORD(0,24)
/*SKY74400*/
/*SKY74400*/ extern unsigned long  SKY74400_TxCtrl_Mask;
/*SKY74400*/ extern unsigned long  SKY74400_TxCtrl;
/*SKY74400*/ unsigned long  SKY74400_BANDINFO[5][2] =
/*SKY74400*/ {  /* LO Chain Test Register, Rx Test Register */
/*SKY74400*/    {                       0,        0         },
/*SKY74400*/    {                0x007F06, 0x18040E         },
/*SKY74400*/    {                0x007F06, 0x18040E         },
/*SKY74400*/    {                0x00FF06, 0x00040E         },
/*SKY74400*/    {                0x00FF06, 0x00040E         },
/*SKY74400*/ };
/*SKY74400*/
/*SKY74400*/ /*..........................................................*/
/*SKY74400*/ /* Serial Interface Implement                               */
/*SKY74400*/ /*..........................................................*/
/*SKY74400*/
/*SKY74400*/ void  L1D_RF_SetSData_SR1( void )
/*SKY74400*/ {
/*SKY74400*/    SETUP_SR1();
/*SKY74400*/    HWRITE_4_SDATA( SCTRL_SKY74400, SKY74400_BANDINFO[l1d_rf.band][0],
/*SKY74400*/                    SCTRL_SKY74400, SKY74400_BANDINFO[l1d_rf.band][1],
/*SKY74400*/                    SCTRL_SKY74400, l1d_rf.IFN_data,
/*SKY74400*/                    SCTRL_SKY74400, l1d_rf.RFN_data );
/*SKY74400*/ }
/*SKY74400*/
/*SKY74400*/ void  L1D_RF_SetSData_SR2( void )
/*SKY74400*/ {
/*SKY74400*/    SETUP_SR2();
/*SKY74400*/    HWRITE_1_SDATA( SCTRL_SKY74400, (l1d_rf.AGC_data|SKY74400_TxCtrl_Mask) );
/*SKY74400*/ }
/*SKY74400*/
/*SKY74400*/ void  L1D_RF_SetSData_SR3( void )
/*SKY74400*/ {
/*SKY74400*/ }
/*SKY74400*/
/*SKY74400*/ void  L1D_RF_SetSData_ST1( void )
/*SKY74400*/ {
/*SKY74400*/    SETUP_ST1();
/*SKY74400*/    HWRITE_4_SDATA( SCTRL_SKY74400, SKY74400_BANDINFO[l1d_rf.band][0],
/*SKY74400*/                    SCTRL_SKY74400, SKY74400_BANDINFO[l1d_rf.band][1],
/*SKY74400*/                    SCTRL_SKY74400, l1d_rf.IFN_data,
/*SKY74400*/                    SCTRL_SKY74400, l1d_rf.RFN_data );
/*SKY74400*/
/*SKY74400*/    if( l1d_rf.d2c_txiqswap==0 )
/*SKY74117*/    {  BFETXSET  bfetxset;
/*SKY74117*/       HW_READ_BFETXSET( bfetxset );
/*SKY74117*/       bfetxset.field.iqswap = l1d_rf.inj & 0x1;
/*SKY74117*/       HW_WRITE_BFETXSET( bfetxset );
/*SKY74117*/    }
/*SKY74400*/ }
/*SKY74400*/
/*SKY74400*/ void  L1D_RF_SetSData_ST2( void )
/*SKY74400*/ {  SETUP_ST2();
/*SKY74400*/    HWRITE_1_SDATA( SCTRL_SKY74400, SKY74400_TxCtrl );
/*SKY74400*/ }
/*SKY74400*/
/*SKY74400*/ void  L1D_RF_SetSData_ST3( void )
/*SKY74400*/ {
/*SKY74400*/ }
/*SKY74400*/
#endif

#if IS_RF_MT6119
/*MT6119*/
/*MT6119*/ /*..........................................................*/
/*MT6119*/ /*  Define Alias and Table                                  */
/*MT6119*/ /*..........................................................*/
/*MT6119*/
/*MT6119*/ #define  SCTRL_PLL                    SCTRL_WORD(0,23)
/*MT6119*/ #define  SCTRL_AGC                    SCTRL_WORD(0,23)
/*MT6119*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,23)
/*MT6119*/ #define  SCTRL_TXLPFGAIN              SCTRL_WORD(0,23) /* CW4 */
/*MT6119*/
/*MT6119*/ const unsigned long SDATA_TXBAND_TABLE[5][2] =
/*MT6119*/ {
/*MT6119*/    {       0L,       0L },  /* FrequencyBand400 (not support)  */
/*MT6119*/    {       0L,       0L },  /* FrequencyBand850 (not support)  */
/*MT6119*/    { 0x08802L, 0x18802L },  /* FrequencyBand900                */
/*MT6119*/    { 0x09002L, 0x19002L },  /* FrequencyBand1800               */
/*MT6119*/    { 0x09802L, 0x19802L },  /* FrequencyBand1900               */
/*MT6119*/ };
/*MT6119*/ const unsigned long SDATA_TXLPFGAIN_TABLE[5]=
/*MT6119*/ {
/*MT6119*/      0x13D504,  /* FrequencyBand400 (not support)  */
/*MT6119*/      0x13D504,  /* FrequencyBand850 (not support)  */
/*MT6119*/      0x13D504,  /* FrequencyBand900                */
/*MT6119*/      0x13DF04,  /* FrequencyBand1800               */
/*MT6119*/      0x13DF04   /* FrequencyBand1900               */
/*MT6119*/ };
/*MT6119*/
/*MT6119*/ /*..........................................................*/
/*MT6119*/ /* Serial Interface Implement                               */
/*MT6119*/ /*..........................................................*/
/*MT6119*/
/*MT6119*/ void  L1D_RF_SetSData_SR1( void )
/*MT6119*/ {
/*MT6119*/    SETUP_SR1();
/*MT6119*/    HWRITE_2_SDATA( SCTRL_PLL,      l1d_rf.RFN_data,
/*MT6119*/                    SCTRL_RESERVED, 0 );
/*MT6119*/ }
/*MT6119*/
/*MT6119*/ void  L1D_RF_SetSData_SR2( void )
/*MT6119*/ {
/*MT6119*/    SETUP_SR2();
/*MT6119*/    HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data );
/*MT6119*/ }
/*MT6119*/
/*MT6119*/ void  L1D_RF_SetSData_SR3( void )
/*MT6119*/ {
/*MT6119*/    SETUP_SR3();
/*MT6119*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6119*/ }
/*MT6119*/
/*MT6119*/ void  L1D_RF_SetSData_ST1( void )
/*MT6119*/ {
/*MT6119*/    SETUP_ST1();
/*MT6119*/    HWRITE_2_SDATA( SCTRL_PLL,       l1d_rf.RFN_data,
/*MT6119*/                    SCTRL_TXLPFGAIN, SDATA_TXLPFGAIN_TABLE[l1d_rf.band] );
/*MT6119*/ }
/*MT6119*/
/*MT6119*/ void  L1D_RF_SetSData_ST2( void )
/*MT6119*/ {  extern char mt6119_d_flag;
/*MT6119*/    SETUP_ST2();
/*MT6119*/    HWRITE_1_SDATA( SCTRL_TXBAND, SDATA_TXBAND_TABLE[l1d_rf.band][mt6119_d_flag] );
/*MT6119*/ }
/*MT6119*/
/*MT6119*/ void  L1D_RF_SetSData_ST3( void )
/*MT6119*/ {
/*MT6119*/    SETUP_ST3();
/*MT6119*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6119*/ }
/*MT6119*/
#endif

#if IS_RF_MT6119C
/*MT6119C*/
/*MT6119C*/ /*..........................................................*/
/*MT6119C*/ /*  Define Alias and Table                                  */
/*MT6119C*/ /*..........................................................*/
/*MT6119C*/
/*MT6119C*/ #define  SCTRL_PLL                    SCTRL_WORD(0,23)
/*MT6119C*/ #define  SCTRL_AGC                    SCTRL_WORD(0,23)
/*MT6119C*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,23)
/*MT6119C*/ #define  SCTRL_TXLPFGAIN              SCTRL_WORD(0,23) /* CW4 */
/*MT6119C*/
/*MT6119C*/ const unsigned long SDATA_TXBAND_TABLE[5][2] =
/*MT6119C*/ {
/*MT6119C*/    {       0L,       0L },  /* FrequencyBand400 (not support)  */
/*MT6119C*/    {       0L,       0L },  /* FrequencyBand850 (not support)  */
/*MT6119C*/    {0x128992L,0x138992L },  /* FrequencyBand900                */
/*MT6119C*/    {0x129192L,0x139192L },  /* FrequencyBand1800               */
/*MT6119C*/    {0x129992L,0x139992L },  /* FrequencyBand1900               */
/*MT6119C*/ };
/*MT6119C*/
/*MT6119C*/ const unsigned long SDATA_TXLPFGAIN_TABLE[5]=
/*MT6119C*/ {
/*MT6119C*/      0x13D504,  /* FrequencyBand400 (not support)  */
/*MT6119C*/      0x13D504,  /* FrequencyBand850 (not support)  */
/*MT6119C*/      0x13D504,  /* FrequencyBand900                */
/*MT6119C*/      0x13DF04,  /* FrequencyBand1800               */
/*MT6119C*/      0x13DF04   /* FrequencyBand1900               */
/*MT6119C*/ };
/*MT6119C*/
/*MT6119C*/ /*..........................................................*/
/*MT6119C*/ /* Serial Interface Implement                               */
/*MT6119C*/ /*..........................................................*/
/*MT6119C*/
/*MT6119C*/ void  L1D_RF_SetSData_SR1( void )
/*MT6119C*/ {
/*MT6119C*/    SETUP_SR1();
/*MT6119C*/    HWRITE_3_SDATA( SCTRL_WARM,     SDATA_WARM,
/*MT6119C*/                    SCTRL_PLL,      l1d_rf.RFN_data,
/*MT6119C*/                    SCTRL_RESERVED, 0 );
/*MT6119C*/ }
/*MT6119C*/
/*MT6119C*/ void  L1D_RF_SetSData_SR2( void )
/*MT6119C*/ {
/*MT6119C*/    SETUP_SR2();
/*MT6119C*/    HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data );
/*MT6119C*/ }
/*MT6119C*/
/*MT6119C*/ void  L1D_RF_SetSData_SR3( void )
/*MT6119C*/ {
/*MT6119C*/    SETUP_SR3();
/*MT6119C*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6119C*/ }
/*MT6119C*/
/*MT6119C*/ void  L1D_RF_SetSData_ST1( void )
/*MT6119C*/ {
/*MT6119C*/    SETUP_ST1();
/*MT6119C*/    HWRITE_3_SDATA( SCTRL_WARM,      SDATA_WARM,
/*MT6119C*/                    SCTRL_PLL,       l1d_rf.RFN_data,
/*MT6119C*/                    SCTRL_TXLPFGAIN, SDATA_TXLPFGAIN_TABLE[l1d_rf.band] );
/*MT6119C*/ }
/*MT6119C*/
/*MT6119C*/ void  L1D_RF_SetSData_ST2( void )
/*MT6119C*/ {  extern char mt6119_d_flag;
/*MT6119C*/    SETUP_ST2();
/*MT6119C*/    HWRITE_1_SDATA( SCTRL_TXBAND, SDATA_TXBAND_TABLE[l1d_rf.band][mt6119_d_flag] );
/*MT6119C*/ }
/*MT6119C*/
/*MT6119C*/ void  L1D_RF_SetSData_ST3( void )
/*MT6119C*/ {
/*MT6119C*/    SETUP_ST3();
/*MT6119C*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6119C*/ }
/*MT6119C*/
#endif

#if IS_RF_MT6129A
/*MT6129A*/
/*MT6129A*/ /*..........................................................*/
/*MT6129A*/ /*  Define Alias and Table                                  */
/*MT6129A*/ /*..........................................................*/
/*MT6129A*/
/*MT6129A*/ #define  SCTRL_PLL                    SCTRL_WORD(0,24)
/*MT6129A*/ #define  SCTRL_AGC                    SCTRL_WORD(0,24)
/*MT6129A*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,24)
/*MT6129A*/ #define  SCTRL_TXLPFGAIN              SCTRL_WORD(0,24) /* CW4 */
/*MT6129A*/
/*MT6129A*/ const unsigned long SDATA_TXBAND_TABLE[5][2] =
/*MT6129A*/ {
/*MT6129A*/    {       0L,       0L },  /* FrequencyBand400 (not support)  */
/*MT6129A*/    {       0L,       0L },  /* FrequencyBand850 (not support)  */
/*MT6129A*/    {0x128982L,0x138982L },  /* FrequencyBand900                */
/*MT6129A*/    {0x129182L,0x139182L },  /* FrequencyBand1800               */
/*MT6129A*/    {0x129982L,0x139982L },  /* FrequencyBand1900               */
/*MT6129A*/ };
/*MT6129A*/ const unsigned long SDATA_TXVCOBAND_TABLE[5]=
/*MT6129A*/ {
/*MT6129A*/           0x0,  /* FrequencyBand400 (not support)  */
/*MT6129A*/           0x0,  /* FrequencyBand850 (not support)  */
/*MT6129A*/      0x124982,  /* FrequencyBand900                */
/*MT6129A*/      0x125182,  /* FrequencyBand1800               */
/*MT6129A*/      0x125982   /* FrequencyBand1900               */
/*MT6129A*/ };
/*MT6129A*/
/*MT6129A*/ /*..........................................................*/
/*MT6129A*/ /* Serial Interface Implement                               */
/*MT6129A*/ /*..........................................................*/
/*MT6129A*/
/*MT6129A*/ void  L1D_RF_SetSData_SR1( void )
/*MT6129A*/ {
/*MT6129A*/    SETUP_SR1();
/*MT6129A*/    HWRITE_2_SDATA( SCTRL_PLL,      l1d_rf.RFN_data,
/*MT6129A*/                    SCTRL_RESERVED, 0 );
/*MT6129A*/ }
/*MT6129A*/
/*MT6129A*/ void  L1D_RF_SetSData_SR2( void )
/*MT6129A*/ {
/*MT6129A*/    SETUP_SR2();
/*MT6129A*/    HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data );
/*MT6129A*/ }
/*MT6129A*/
/*MT6129A*/ void  L1D_RF_SetSData_SR3( void )
/*MT6129A*/ {
/*MT6129A*/    SETUP_SR3();
/*MT6129A*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129A*/ }
/*MT6129A*/
/*MT6129A*/ void  L1D_RF_SetSData_ST1( void )
/*MT6129A*/ {
/*MT6129A*/    SETUP_ST1();
/*MT6129A*/    HWRITE_2_SDATA( SCTRL_TXBAND,   SDATA_TXVCOBAND_TABLE[l1d_rf.band],  /*Band information for TXVCO*/
/*MT6129A*/                    SCTRL_PLL,       l1d_rf.RFN_data);
/*MT6129A*/ }
/*MT6129A*/
/*MT6129A*/ void  L1D_RF_SetSData_ST2( void )
/*MT6129A*/ {  extern char mt6119_d_flag;
/*MT6129A*/    SETUP_ST2();
/*MT6129A*/    HWRITE_1_SDATA( SCTRL_TXBAND, SDATA_TXBAND_TABLE[l1d_rf.band][mt6119_d_flag] );
/*MT6129A*/ }
/*MT6129A*/
/*MT6129A*/ void  L1D_RF_SetSData_ST3( void )
/*MT6129A*/ {
/*MT6129A*/    SETUP_ST3();
/*MT6129A*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129A*/ }
/*MT6129A*/
#endif

#if IS_RF_MT6129B
/*MT6129B*/
/*MT6129B*/ /*..........................................................*/
/*MT6129B*/ /*  Define Alias and Table                                  */
/*MT6129B*/ /*..........................................................*/
/*MT6129B*/
/*MT6129B*/ #define  SCTRL_PLL                    SCTRL_WORD(0,24)
/*MT6129B*/ #define  SCTRL_AGC                    SCTRL_WORD(0,24)
/*MT6129B*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,24)
/*MT6129B*/ #define  SCTRL_TXLPFGAIN              SCTRL_WORD(0,24) /* CW4 */
/*MT6129B*/
/*MT6129B*/ const unsigned long SDATA_TXBAND_TABLE[5][2] =
/*MT6129B*/ {
/*MT6129B*/    {       0L,       0L },  /* FrequencyBand400 (not support)  */
/*MT6129B*/    {0x128182L,0x138182L },  /* FrequencyBand850                */
/*MT6129B*/    {0x128982L,0x138982L },  /* FrequencyBand900                */
/*MT6129B*/    {0x129182L,0x139182L },  /* FrequencyBand1800               */
/*MT6129B*/    {0x129982L,0x139982L },  /* FrequencyBand1900               */
/*MT6129B*/ };
/*MT6129B*/
/*MT6129B*/ const unsigned long SDATA_TXVCOBAND_TABLE[5]=
/*MT6129B*/ {
/*MT6129B*/           0x0,  /* FrequencyBand400 (not support)  */
/*MT6129B*/      0x124182,  /* FrequencyBand850                */
/*MT6129B*/      0x124982,  /* FrequencyBand900                */
/*MT6129B*/      0x125182,  /* FrequencyBand1800               */
/*MT6129B*/      0x125982   /* FrequencyBand1900               */
/*MT6129B*/ };
/*MT6129B*/
/*MT6129B*/ const unsigned long SDATA_TXLPFGAIN_TABLE[5]=
/*MT6129B*/ {
/*MT6129B*/           0x0,  /* FrequencyBand400 (not support)  */
/*MT6129B*/      0x2AA824,  /* FrequencyBand850                */
/*MT6129B*/      0x2AA824,  /* FrequencyBand900                */
/*MT6129B*/      0x22A824,  /* FrequencyBand1800               */
/*MT6129B*/      0x2AA824   /* FrequencyBand1900               */
/*MT6129B*/ };
/*MT6129B*/
/*MT6129B*/ /*..........................................................*/
/*MT6129B*/ /* Serial Interface Implement                               */
/*MT6129B*/ /*..........................................................*/
/*MT6129B*/
/*MT6129B*/ void  L1D_RF_SetSData_SR1( void )
/*MT6129B*/ {
/*MT6129B*/    SETUP_SR1();
/*MT6129B*/    HWRITE_3_SDATA( SCTRL_PLL,      l1d_rf.RFN_data,
/*MT6129B*/                    SCTRL_RESERVED, 0,
/*MT6129B*/                    SCTRL_RESERVED, 0 );
/*MT6129B*/ }
/*MT6129B*/
/*MT6129B*/ void  L1D_RF_SetSData_SR2( void )
/*MT6129B*/ {
/*MT6129B*/    SETUP_SR2();
/*MT6129B*/    HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data );
/*MT6129B*/ }
/*MT6129B*/
/*MT6129B*/ void  L1D_RF_SetSData_SR3( void )
/*MT6129B*/ {
/*MT6129B*/    SETUP_SR3();
/*MT6129B*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129B*/ }
/*MT6129B*/
/*MT6129B*/ void  L1D_RF_SetSData_ST1( void )
/*MT6129B*/ {
/*MT6129B*/    SETUP_ST1();
/*MT6129B*/    HWRITE_3_SDATA( SCTRL_TXBAND,    SDATA_TXVCOBAND_TABLE[l1d_rf.band],  /*Band information for TXVCO*/
/*MT6129B*/                    SCTRL_TXLPFGAIN, SDATA_TXLPFGAIN_TABLE[l1d_rf.band],
/*MT6129B*/                    SCTRL_PLL,       l1d_rf.RFN_data);
/*MT6129B*/ }
/*MT6129B*/
/*MT6129B*/ void  L1D_RF_SetSData_ST2( void )
/*MT6129B*/ {  extern char mt6119_d_flag;
/*MT6129B*/    SETUP_ST2();
/*MT6129B*/    HWRITE_1_SDATA( SCTRL_TXBAND, SDATA_TXBAND_TABLE[l1d_rf.band][mt6119_d_flag] );
/*MT6129B*/ }
/*MT6129B*/
/*MT6129B*/ void  L1D_RF_SetSData_ST3( void )
/*MT6129B*/ {
/*MT6129B*/    SETUP_ST3();
/*MT6129B*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129B*/ }
/*MT6129B*/
#endif

#if IS_RF_MT6129C
/*MT6129C*/
/*MT6129C*/ /*..........................................................*/
/*MT6129C*/ /*  Define Alias and Table                                  */
/*MT6129C*/ /*..........................................................*/
/*MT6129C*/
/*MT6129C*/ #define  SCTRL_WARM                   SCTRL_WORD(0,24)
/*MT6129C*/ #define  SCTRL_PLL                    SCTRL_WORD(0,24)
/*MT6129C*/ #define  SCTRL_AGC                    SCTRL_WORD(0,24)
/*MT6129C*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,24)
/*MT6129C*/ #define  SCTRL_TXLPFGAIN              SCTRL_WORD(0,24) /* CW4 */
/*MT6129C*/
/*MT6129C*/ const unsigned long SDATA_TXBAND_TABLE[5][2] =
/*MT6129C*/ {
/*MT6129C*/    {       0L,       0L },  /* FrequencyBand400 (not support)  */
/*MT6129C*/    {0x128182L,0x138182L },  /* FrequencyBand850                */
/*MT6129C*/    {0x128982L,0x138982L },  /* FrequencyBand900                */
/*MT6129C*/    {0x129182L,0x139182L },  /* FrequencyBand1800               */
/*MT6129C*/    {0x129982L,0x139982L },  /* FrequencyBand1900               */
/*MT6129C*/ };
/*MT6129C*/
/*MT6129C*/ const unsigned long SDATA_WARM_TABLE[5]=
/*MT6129C*/ {
/*MT6129C*/           0x0,  /* FrequencyBand400 (not support)  */
/*MT6129C*/      0x122182,  /* FrequencyBand850                */
/*MT6129C*/      0x122982,  /* FrequencyBand900                */
/*MT6129C*/      0x123182,  /* FrequencyBand1800               */
/*MT6129C*/      0x123982   /* FrequencyBand1900               */
/*MT6129C*/ };
/*MT6129C*/
/*MT6129C*/ /*..........................................................*/
/*MT6129C*/ /* Serial Interface Implement                               */
/*MT6129C*/ /*..........................................................*/
/*MT6129C*/
/*MT6129C*/ void  L1D_RF_SetSData_SR1( void )
/*MT6129C*/ {
/*MT6129C*/    SETUP_SR1();
/*MT6129C*/    HWRITE_3_SDATA( SCTRL_WARM,     SDATA_WARM_TABLE[l1d_rf.band],
/*MT6129C*/                    SCTRL_PLL,      l1d_rf.RFN_data,
/*MT6129C*/                    SCTRL_RESERVED, 0 );
/*MT6129C*/ }
/*MT6129C*/
/*MT6129C*/ void  L1D_RF_SetSData_SR2( void )
/*MT6129C*/ {
/*MT6129C*/    SETUP_SR2();
/*MT6129C*/    HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data );
/*MT6129C*/ }
/*MT6129C*/
/*MT6129C*/ void  L1D_RF_SetSData_SR3( void )
/*MT6129C*/ {
/*MT6129C*/    SETUP_SR3();
/*MT6129C*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129C*/ }
/*MT6129C*/
/*MT6129C*/ void  L1D_RF_SetSData_ST1( void )
/*MT6129C*/ {
/*MT6129C*/    SETUP_ST1();
/*MT6129C*/    HWRITE_3_SDATA( SCTRL_WARM,      SDATA_WARM_TABLE[l1d_rf.band],  /*Band information for TXVCO*/
/*MT6129C*/                    SCTRL_PLL,       l1d_rf.RFN_data,
/*MT6129C*/                    SCTRL_RESERVED, 0);
/*MT6129C*/ }
/*MT6129C*/
/*MT6129C*/ void  L1D_RF_SetSData_ST2( void )
/*MT6129C*/ {  extern char mt6119_d_flag;
/*MT6129C*/    SETUP_ST2();
/*MT6129C*/    HWRITE_1_SDATA( SCTRL_TXBAND, SDATA_TXBAND_TABLE[l1d_rf.band][mt6119_d_flag] );
/*MT6129C*/ }
/*MT6129C*/
/*MT6129C*/ void  L1D_RF_SetSData_ST3( void )
/*MT6129C*/ {
/*MT6129C*/    SETUP_ST3();
/*MT6129C*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129C*/ }
/*MT6129C*/
#endif

#if IS_RF_MT6129D
/*MT6129D*/
/*MT6129D*/ /*..........................................................*/
/*MT6129D*/ /*  Define Alias and Table                                  */
/*MT6129D*/ /*..........................................................*/
/*MT6129D*/
/*MT6129D*/ #define  SCTRL_WARM                   SCTRL_WORD(0,24)
/*MT6129D*/ #define  SCTRL_PLL                    SCTRL_WORD(0,24)
/*MT6129D*/ #define  SCTRL_AGC                    SCTRL_WORD(0,24)
/*MT6129D*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,24)
/*MT6129D*/ #define  SCTRL_TXIAC                  SCTRL_WORD(0,24) /* CW4 */
/*MT6129D*/
/*MT6129D*/ const unsigned long SDATA_TXBAND_TABLE[5][2] =
/*MT6129D*/ {
/*MT6129D*/    {       0L,       0L },  /* FrequencyBand400 (not support)  */
/*MT6129D*/    {0x128182L,0x138182L },  /* FrequencyBand850                */
/*MT6129D*/    {0x128982L,0x138982L },  /* FrequencyBand900                */
/*MT6129D*/    {0x129182L,0x139182L },  /* FrequencyBand1800               */
/*MT6129D*/    {0x129982L,0x139982L },  /* FrequencyBand1900               */
/*MT6129D*/ };
/*MT6129D*/
/*MT6129D*/ // For case of GSM850 in GSM900 path
/*MT6129D*/ const unsigned long SDATA_WARM_TABLE_RX_GSM850in900[5]=
/*MT6129D*/ {
/*MT6129D*/           0x0,  /* FrequencyBand400 (not support)  */
/*MT6129D*/      0x122982,  /* FrequencyBand850 (Get GSM850 signal from GSM900 input pins) */
/*MT6129D*/      0x122182,  /* FrequencyBand900 (Get GSM900 signal from GSM850 input pins, just avoid to camp on GSM900 network, not swap*/
/*MT6129D*/      0x123182,  /* FrequencyBand1800               */
/*MT6129D*/      0x123982   /* FrequencyBand1900               */
/*MT6129D*/ };
/*MT6129D*/
/*MT6129D*/ const unsigned long SDATA_WARM_TABLE[5]=
/*MT6129D*/ {
/*MT6129D*/           0x0,  /* FrequencyBand400 (not support)  */
/*MT6129D*/      0x122182,  /* FrequencyBand850                */
/*MT6129D*/      0x122982,  /* FrequencyBand900                */
/*MT6129D*/      0x123182,  /* FrequencyBand1800               */
/*MT6129D*/      0x123982   /* FrequencyBand1900               */
/*MT6129D*/ };
/*MT6129D*/
/*MT6129D*/ const unsigned long SDATA_TXIAC_TABLE[5]=
/*MT6129D*/ {
/*MT6129D*/           0x0,  /* FrequencyBand400 (not support)  */
/*MT6129D*/      0x342854,  /* FrequencyBand850                */
/*MT6129D*/      0x342854,  /* FrequencyBand900                */
/*MT6129D*/      0x14A854,  /* FrequencyBand1800               */
/*MT6129D*/      0x14A854   /* FrequencyBand1900               */
/*MT6129D*/ };
/*MT6129D*/
/*MT6129D*/ /*..........................................................*/
/*MT6129D*/ /* Serial Interface Implement                               */
/*MT6129D*/ /*..........................................................*/
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_SR1( void )
/*MT6129D*/ {  unsigned long sdata_warm;
/*MT6129D*/
/*MT6129D*/    SETUP_SR1();
/*MT6129D*/
/*MT6129D*/    if( BBTXParameters.bbrx_gsm850_gsm900_swap )
/*MT6129D*/    {  sdata_warm = SDATA_WARM_TABLE_RX_GSM850in900[l1d_rf.band];
/*MT6129D*/    }
/*MT6129D*/    else
/*MT6129D*/    {  sdata_warm = SDATA_WARM_TABLE[l1d_rf.band];
/*MT6129D*/    }
/*MT6129D*/
/*MT6129D*/    HWRITE_3_SDATA( SCTRL_WARM,     sdata_warm,
/*MT6129D*/                    SCTRL_PLL,      l1d_rf.RFN_data,
/*MT6129D*/                    SCTRL_RESERVED, 0 );
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_SR2( void )
/*MT6129D*/ {
/*MT6129D*/    SETUP_SR2();
/*MT6129D*/    HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data );
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_SR3( void )
/*MT6129D*/ {
/*MT6129D*/    SETUP_SR3();
/*MT6129D*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_ST1( void )
/*MT6129D*/ {
/*MT6129D*/    SETUP_ST1();
/*MT6129D*/    HWRITE_3_SDATA( SCTRL_WARM,      SDATA_WARM_TABLE[l1d_rf.band],  /*Band information for TXVCO*/
/*MT6129D*/                    SCTRL_PLL,       l1d_rf.RFN_data,
/*MT6129D*/                    SCTRL_TXIAC,     SDATA_TXIAC_TABLE[l1d_rf.band]);
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_ST2( void )
/*MT6129D*/ {  extern char mt6119_d_flag;
/*MT6129D*/    SETUP_ST2();
/*MT6129D*/    HWRITE_1_SDATA( SCTRL_TXBAND, SDATA_TXBAND_TABLE[l1d_rf.band][mt6119_d_flag] );
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_ST3( void )
/*MT6129D*/ {
/*MT6129D*/    SETUP_ST3();
/*MT6129D*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129D*/ }
/*MT6129D*/
#endif

#if IS_RF_MT6139B
/*MT6139B*/
/*MT6139B*/ /*..........................................................*/
/*MT6139B*/ /*  Define Alias and Table                                  */
/*MT6139B*/ /*..........................................................*/
/*MT6139B*/
/*MT6139B*/ #define  SCTRL_WARM                   SCTRL_WORD(0,25)
/*MT6139B*/ #define  SCTRL_PLL                    SCTRL_WORD(0,25)
/*MT6139B*/ #define  SCTRL_AGC                    SCTRL_WORD(0,25)
/*MT6139B*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,25)
/*MT6139B*/ #define  SCTRL_AMCODE                 SCTRL_WORD(0,25) /* CW10 */
/*MT6139B*/
/*MT6139B*/ const unsigned long SDATA_WARM = 0x0000402L;
/*MT6139B*/ const unsigned long SDATA_TXMODE = 0x0001002L;
/*MT6139B*/       unsigned long mode = 0x0001800;
/*MT6139B*//// const unsigned long SDATA_AMCODE = 0x008080AL;   /*temporarily*/
/*MT6139B*//// const unsigned long SDATA_ACODE   = 0x1040002L;   /*temporarily*/
/*MT6139B*//// const unsigned long SDATA_AMCODE_TABLE[5]=
/*MT6139B*//// {
/*MT6139B*////    {        0L},  /* FrequencyBand400 (not support)  */
/*MT6139B*////    {0x000042AL},  /* FrequencyBand850                */
/*MT6139B*////    {0x0000A4AL},  /* FrequencyBand900                */
/*MT6139B*////    {0x00FFFFAL},  /* FrequencyBand1800               */
/*MT6139B*////    {0x0080FFAL},  /* FrequencyBand1900               */
/*MT6139B*//// };
/*MT6139B*//// const unsigned long SDATA_ACODE_TABLE[5]=
/*MT6139B*//// {
/*MT6139B*////    {        0L},  /* FrequencyBand400 (not support)  */
/*MT6139B*////    {0x13C6002L},  /* FrequencyBand850                */
/*MT6139B*////    {0x133E002L},  /* FrequencyBand900                */
/*MT6139B*////    {0x0C36002L},  /* FrequencyBand1800               */
/*MT6139B*////    {0x0FB6002L},  /* FrequencyBand1900               */
/*MT6139B*//// };
/*MT6139B*/
/*MT6139B*/ /*..........................................................*/
/*MT6139B*/ /* Serial Interface Implement                               */
/*MT6139B*/ /*..........................................................*/
/*MT6139B*/
/*MT6139B*/ void  L1D_RF_SetSData_SR1( void )
/*MT6139B*/ {
/*MT6139B*/    SETUP_SR1();
/*MT6139B*/    HWRITE_3_SDATA(SCTRL_WARM,    SDATA_WARM,
/*MT6139B*/                   SCTRL_PLL,     l1d_rf.RFN_data,
/*MT6139B*/                   SCTRL_AMCODE,  RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].amcode<<4|(0x000000A));
/*MT6139B*/ }
/*MT6139B*/
/*MT6139B*/ void  L1D_RF_SetSData_SR2( void )                  /*MJ | rxamcalmode  |   mode description       */
/*MT6139B*/ {                                                  /*MJ |      0       |   mode(110) get A code   */
/*MT6139B*/    SETUP_SR2();                                    /*MJ |      1       |   mode(011) get B&C code */
/*MT6139B*/    if(!RFSpecialCoef.rx.mt6139ip2.rxamcalmode)     /*MJ |      2       |   mode(011) normal mode  */
/*MT6139B*/    {
/*MT6139B*/       HWRITE_1_SDATA( SCTRL_AGC,    ((l1d_rf.AGC_data & 0xFFFE3FF)|mode)|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<13) );
/*MT6139B*/    }
/*MT6139B*/    else
/*MT6139B*/    {
/*MT6139B*/       HWRITE_1_SDATA( SCTRL_AGC,    l1d_rf.AGC_data|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<13) );
/*MT6139B*/    }
/*MT6139B*/ }
/*MT6139B*/
/*MT6139B*/ void  L1D_RF_SetSData_SR3( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6139B*/ {                                                      /*MJ |      0       |   mode(110) get A code   */
/*MT6139B*/    SETUP_SR3();                                        /*MJ |      1       |   mode(011) get B&C code */
/*MT6139B*/    if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode !=0x0002 )/*MJ |      2       |   mode(011) normal mode  */
/*MT6139B*/    {
/*MT6139B*/       HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*MT6139B*/    }
/*MT6139B*/    else
/*MT6139B*/    {
/*MT6139B*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6139B*/    }
/*MT6139B*/ }
/*MT6139B*/
/*MT6139B*/ void  L1D_RF_SetSData_ST1( void )
/*MT6139B*/ {
/*MT6139B*/    SETUP_ST1();
/*MT6139B*/    HWRITE_3_SDATA(SCTRL_WARM, SDATA_WARM,
/*MT6139B*/                               SCTRL_PLL,      l1d_rf.RFN_data,
/*MT6139B*/                               SCTRL_RESERVED, 0               );
/*MT6139B*/ }
/*MT6139B*/
/*MT6139B*/ void  L1D_RF_SetSData_ST2( void )
/*MT6139B*/ {
/*MT6139B*/    SETUP_ST2();
/*MT6139B*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE );
/*MT6139B*/ }
/*MT6139B*/
/*MT6139B*/ void  L1D_RF_SetSData_ST3( void )
/*MT6139B*/ {
/*MT6139B*/    SETUP_ST3();
/*MT6139B*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6139B*/ }
/*MT6139B*/
#endif

#if IS_RF_MT6139C
/*MT6139C*/
/*MT6139C*/ /*..........................................................*/
/*MT6139C*/ /*  Define Alias and Table                                  */
/*MT6139C*/ /*..........................................................*/
/*MT6139C*/
/*MT6139C*/ #define  SCTRL_WARM                   SCTRL_WORD(0,26)
/*MT6139C*/ #define  SCTRL_PLL                    SCTRL_WORD(0,26)
/*MT6139C*/ #define  SCTRL_AGC                    SCTRL_WORD(0,26)
/*MT6139C*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,26)
/*MT6139C*/ #define  SCTRL_AMCODE                 SCTRL_WORD(0,26) /* CW10 */
/*MT6139C*/ #define  SCTRL_TXDIV_GC               SCTRL_WORD(0,26) /* CW11 */
/*MT6139C*/
/*MT6139C*/ const unsigned long SDATA_WARM   = 0x0000402L;
/*MT6139C*/ const unsigned long SDATA_TXMODE = 0x0003002L;
/*MT6139C*/ const unsigned long CW5_RF[5]= {   0x0,           //450
/*MT6139C*/                                    0x00103F5,     //850   0x00101F5,  //850
/*MT6139C*/                                    0x00103F5,     //900   0x00101F5,  //900
/*MT6139C*/                                    0x00101F5,     //1800
/*MT6139C*/                                    0x00101F5, };  //1900
/*MT6139C*/ unsigned long cali_mode = 0x0001800; //mode(110) for AM calibraton
/*MT6139C*/ unsigned long auto_cal  = 0x0002000; //turn on auto calibrate
/*MT6139C*/
/*MT6139C*/ /*..........................................................*/
/*MT6139C*/ /* Serial Interface Implement                               */
/*MT6139C*/ /*..........................................................*/
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_SetSData_SR1( void )
/*MT6139C*/ {
/*MT6139C*/    SETUP_SR1();
/*MT6139C*/    HWRITE_3_SDATA(SCTRL_WARM,    SDATA_WARM,
/*MT6139C*/                   SCTRL_PLL,     l1d_rf.RFN_data,
/*MT6139C*/                   SCTRL_AMCODE,  RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].amcode<<4|(0x000000A));
/*MT6139C*/ }
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_SetSData_SR2( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6139C*/ {                                                      /*MJ |        0     |   mode(110) get A code   */
/*MT6139C*/    SETUP_SR2();                                        /*MJ |        1     |   mode(011) Fix BC PM    */
/*MT6139C*/    if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 0)     /*MJ |        2     |   mode(011) normal mode  */
/*MT6139C*/    {
/*MT6139C*/       HWRITE_1_SDATA( SCTRL_AGC, ((l1d_rf.AGC_data&0xFFFE3FF)|cali_mode)|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6139C*/    }
/*MT6139C*/    else if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 1)
/*MT6139C*/    {
/*MT6139C*/       HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6139C*/    }
/*MT6139C*/    else
/*MT6139C*/    {
/*MT6139C*/       HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6139C*/    }
/*MT6139C*/ }
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_SetSData_SR3( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6139C*/ {                                                      /*MJ |        0     |   mode(110) get A code, not return IDLE */
/*MT6139C*/    SETUP_SR3();                                        /*MJ |        1     |   mode(011) Fix BC PM, return IDLE      */
/*MT6139C*/    if( RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 0 )   /*MJ |        2     |   mode(011) normal mode, return IDLE    */
/*MT6139C*/    {
/*MT6139C*/       HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*MT6139C*/    }
/*MT6139C*/    else
/*MT6139C*/    {
/*MT6139C*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6139C*/    }
/*MT6139C*/ }
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_SetSData_ST1( void )
/*MT6139C*/ {
/*MT6139C*/    SETUP_ST1();
/*MT6139C*/    HWRITE_3_SDATA(SCTRL_WARM,      SDATA_WARM,
/*MT6139C*/                   SCTRL_PLL,       l1d_rf.RFN_data,
/*MT6139C*/                   SCTRL_TXDIV_GC,  CW5_RF[l1d_rf.band]  );
/*MT6139C*/ }
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_SetSData_ST2( void )
/*MT6139C*/ {
/*MT6139C*/    SETUP_ST2();
/*MT6139C*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE );
/*MT6139C*/ }
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_SetSData_ST3( void )
/*MT6139C*/ {
/*MT6139C*/    SETUP_ST3();
/*MT6139C*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6139C*/ }
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6139C*/ {
/*MT6139C*/ }
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6139C*/ {
/*MT6139C*/ }
/*MT6139C*/
#endif

#if IS_RF_MT6139E
/*MT6139E*/
/*MT6139E*/ /*..........................................................*/
/*MT6139E*/ /*  Define Alias and Table                                  */
/*MT6139E*/ /*..........................................................*/
/*MT6139E*/
/*MT6139E*/ #define  SCTRL_WARM                   SCTRL_WORD(0,26)
/*MT6139E*/ #define  SCTRL_PLL                    SCTRL_WORD(0,26)
/*MT6139E*/ #define  SCTRL_AGC                    SCTRL_WORD(0,26)
/*MT6139E*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,26)
/*MT6139E*/ #define  SCTRL_AMCODE                 SCTRL_WORD(0,26) /* CW10 */
/*MT6139E*/ #define  SCTRL_TXDIV_GC               SCTRL_WORD(0,26) /* CW11 */
/*MT6139E*/
/*MT6139E*/ const unsigned long SDATA_WARM   = 0x0000402L;
/*MT6139E*/ const unsigned long SDATA_TXMODE = 0x0003002L;
/*MT6139E*/ unsigned long CW11_RF[5]={0x0000000,     //450   not support
/*MT6139E*/                           0x1B4C7FB,     //850   Low current DIV_GC=00 TXMODGAIN=000
/*MT6139E*/                           0x1B4C7FB,     //900   Low current DIV_GC=00 TXMODGAIN=000
/*MT6139E*/                           0x1B4E7FB,     //1800  Default DIV_GC=01 TXMODGAIN=100
/*MT6139E*/                           0x1B4E7FB };   //1900  Default DIV_GC=01 TXMODGAIN=100
/*MT6139E*/ unsigned long auto_cal  = 0x0002000; //turn on auto calibrate
/*MT6139E*/
/*MT6139E*/ /*..........................................................*/
/*MT6139E*/ /* Serial Interface Implement                               */
/*MT6139E*/ /*..........................................................*/
/*MT6139E*/
   #if IS_BSI_SX0_SUPPORT
/*MT6139E*/ void  L1D_RF_SetSData_SR0( void )
/*MT6139E*/ {
/*MT6139E*/ }
   #endif
/*MT6139E*/ void  L1D_RF_SetSData_SR1( void )
/*MT6139E*/ {
/*MT6139E*/    SETUP_SR1();
/*MT6139E*/    HWRITE_3_SDATA(SCTRL_WARM,    SDATA_WARM,
/*MT6139E*/                   SCTRL_PLL,     l1d_rf.RFN_data,
/*MT6139E*/                   SCTRL_RESERVED, 0);
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_SR2( void )
/*MT6139E*/ {
/*MT6139E*/    SETUP_SR2();
/*MT6139E*/    HWRITE_1_SDATA( SCTRL_AGC,    l1d_rf.AGC_data|auto_cal);
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_SR3( void )
/*MT6139E*/ {
/*MT6139E*/    SETUP_SR3();
/*MT6139E*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6139E*/ }
/*MT6139E*/
   #if IS_BSI_SX0_SUPPORT
/*MT6139E*/ void  L1D_RF_SetSData_ST0( void )
/*MT6139E*/ {
/*MT6139E*/ }
   #endif
/*MT6139E*/ void  L1D_RF_SetSData_ST1( void )
/*MT6139E*/ {
/*MT6139E*/    SETUP_ST1();
/*MT6139E*/    HWRITE_3_SDATA(SCTRL_WARM,      SDATA_WARM,
/*MT6139E*/                   SCTRL_PLL,       l1d_rf.RFN_data,
/*MT6139E*/                   SCTRL_TXDIV_GC,  CW11_RF[l1d_rf.band]  );
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_ST2( void )
/*MT6139E*/ {
/*MT6139E*/    SETUP_ST2();
/*MT6139E*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE );
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_ST3( void )
/*MT6139E*/ {
/*MT6139E*/    SETUP_ST3();
/*MT6139E*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6139E*/ {
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6139E*/ {
/*MT6139E*/ }
/*MT6139E*/
#endif

#if IS_RF_MT6140A
/*MT6140A*/
/*MT6140A*/ /*..........................................................*/
/*MT6140A*/ /*  Define Alias and Table                                  */
/*MT6140A*/ /*..........................................................*/
/*MT6140A*/
/*MT6140A*/ #define  SCTRL_WARM                   SCTRL_WORD(0,26)
/*MT6140A*/ #define  SCTRL_PLL                    SCTRL_WORD(0,26)
/*MT6140A*/ #define  SCTRL_AGC                    SCTRL_WORD(0,26)
/*MT6140A*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,26)
/*MT6140A*/ #define  SCTRL_AMCODE                 SCTRL_WORD(0,26) /* CW10 */
/*MT6140A*/ #define  SCTRL_TXDIV_GC               SCTRL_WORD(0,26) /* CW11 */
/*MT6140A*/
/*MT6140A*/ const unsigned long SDATA_WARM   = 0x0000402L;
/*MT6140A*/ const unsigned long SDATA_TXMODE = 0x0003002L;
/*MT6140A*/ const unsigned long CW11_TXDIV_GC[5]={0x0,        //450
/*MT6140A*/                                       0x3B4E7FB,  //850   0x2B4E7FB,  //850
/*MT6140A*/                                       0x3B4E7FB,  //900   0x2B4E7FB,  //900
/*MT6140A*/                                       0x1B4E7FB,  //1800
/*MT6140A*/                                       0x1B4E7FB };//1900
/*MT6140A*/ unsigned long cali_mode = 0x0001800; //mode(110) for AM calibraton
/*MT6140A*/ unsigned long auto_cal  = 0x0002000; //turn on auto calibrate
/*MT6140A*/
/*MT6140A*/ /*..........................................................*/
/*MT6140A*/ /* Serial Interface Implement                               */
/*MT6140A*/ /*..........................................................*/
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_SetSData_SR1( void )
/*MT6140A*/ {
/*MT6140A*/    SETUP_SR1();
/*MT6140A*/    HWRITE_3_SDATA(SCTRL_WARM,    SDATA_WARM,
/*MT6140A*/                   SCTRL_PLL,     l1d_rf.RFN_data,
/*MT6140A*/                   SCTRL_AMCODE,  RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].amcode<<4|(0x000000A));
/*MT6140A*/ }
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_SetSData_SR2( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6140A*/ {                                                      /*MJ |      0       |   mode(110) get A code   */
/*MT6140A*/    SETUP_SR2();                                        /*MJ |      1       |   mode(011) Fix BC PM    */
/*MT6140A*/    if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 0)     /*MJ |      2       |   mode(011) normal mode  */
/*MT6140A*/    {
/*MT6140A*/       HWRITE_1_SDATA( SCTRL_AGC, ((l1d_rf.AGC_data&0xFFFE3FF)|cali_mode)|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140A*/    }
/*MT6140A*/    else if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 1)
/*MT6140A*/    {
/*MT6140A*/       HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140A*/    }
/*MT6140A*/    else
/*MT6140A*/    {
/*MT6140A*/       HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140A*/    }
/*MT6140A*/ }
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_SetSData_SR3( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6140A*/ {                                                      /*MJ |      0       |   mode(110) get A code, not return IDLE */
/*MT6140A*/    SETUP_SR3();                                        /*MJ |      1       |   mode(011) Fix BC PM, return IDLE      */
/*MT6140A*/    if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 0)     /*MJ |      2       |   mode(011) normal mode, return IDLE    */
/*MT6140A*/    {
/*MT6140A*/       HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*MT6140A*/    }
/*MT6140A*/    else
/*MT6140A*/    {
/*MT6140A*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6140A*/    }
/*MT6140A*/ }
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_SetSData_ST1( void )
/*MT6140A*/ {
/*MT6140A*/    SETUP_ST1();
/*MT6140A*/    HWRITE_3_SDATA(SCTRL_WARM,      SDATA_WARM,
/*MT6140A*/                   SCTRL_PLL,       l1d_rf.RFN_data,
/*MT6140A*/                   SCTRL_TXDIV_GC,  CW11_TXDIV_GC[l1d_rf.band]  );
/*MT6140A*/ }
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_SetSData_ST2( void )
/*MT6140A*/ {
/*MT6140A*/    SETUP_ST2();
/*MT6140A*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE );
/*MT6140A*/ }
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_SetSData_ST3( void )
/*MT6140A*/ {
/*MT6140A*/    SETUP_ST3();
/*MT6140A*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6140A*/ }
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6140A*/ {
/*MT6140A*/ }
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6140A*/ {
/*MT6140A*/ }
/*MT6140A*/
#endif

#if IS_RF_MT6140B
/*MT6140B*/
/*MT6140B*/ /*..........................................................*/
/*MT6140B*/ /*  Define Alias and Table                                  */
/*MT6140B*/ /*..........................................................*/
/*MT6140B*/
/*MT6140B*/ #define  SCTRL_STANDBY                SCTRL_WORD(0,26)
/*MT6140B*/ #define  SCTRL_WARM                   SCTRL_WORD(0,26)
/*MT6140B*/ #define  SCTRL_PLL                    SCTRL_WORD(0,26)
/*MT6140B*/ #define  SCTRL_AGC                    SCTRL_WORD(0,26)
/*MT6140B*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,26)
/*MT6140B*/ #define  SCTRL_AMCODE                 SCTRL_WORD(0,26) /* CW10 */
/*MT6140B*/ #define  SCTRL_TXCW                   SCTRL_WORD(0,26) /* CW11 */
/*MT6140B*/
/*MT6140B*/ const unsigned long SDATA_SLEEP   = 0x0000002L; // Sleep mode
/*MT6140B*/ const unsigned long SDATA_WARM    = 0x20827E2L; // Warm up mode
/*MT6140B*/ const unsigned long SDATA_TXMODE  = 0x0003002L; // GMSK 0x0003002L;
/*MT6140B*/ const unsigned long SDATA_RXMODE  = 0x0000C02L; // RX mode
/*MT6140B*/ const unsigned long cali_mode     = 0x0001800L; //mode(110) for AM calibraton
/*MT6140B*/ const unsigned long auto_cal      = 0x0002000L; //turn on auto calibrate
/*MT6140B*/ const unsigned long CW11_TXCW[5]={0x0,        //450
/*MT6140B*/                                   0x101FFFB,  //850
/*MT6140B*/                                   0x101FFFB,  //900
/*MT6140B*/                                   0x105DFFB,  //1800
/*MT6140B*/                                   0x105DFFB };//1900
/*MT6140B*/ /*..........................................................*/
/*MT6140B*/ /* Serial Interface Implement                               */
/*MT6140B*/ /*..........................................................*/
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_SetSData_SR1( void )
/*MT6140B*/ {
/*MT6140B*/    SETUP_SR1();
/*MT6140B*/    HWRITE_3_SDATA(SCTRL_WARM,    SDATA_WARM,
/*MT6140B*/                   SCTRL_PLL,     l1d_rf.RFN_data,
/*MT6140B*/                   SCTRL_AMCODE,  RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].amcode<<4|(0x000000A));
/*MT6140B*/ }
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_SetSData_SR2( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6140B*/ {                                                      /*MJ |      0       |   mode(110) get A code   */
/*MT6140B*/    SETUP_SR2();                                        /*MJ |      1       |   mode(011) Fix BC PM    */
/*MT6140B*/    if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 0)     /*MJ |      2       |   mode(011) normal mode  */
/*MT6140B*/    {
/*MT6140B*/       HWRITE_1_SDATA( SCTRL_AGC, ((l1d_rf.AGC_data&0xFFFE3FF)|cali_mode)|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140B*/    }
/*MT6140B*/    else if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 1)
/*MT6140B*/    {
/*MT6140B*/       HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140B*/    }
/*MT6140B*/    else
/*MT6140B*/    {
/*MT6140B*/       HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140B*/    }
/*MT6140B*/ }
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_SetSData_SR3( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6140B*/ {                                                      /*MJ |      0       |   mode(110) get A code, not return IDLE */
/*MT6140B*/    SETUP_SR3();                                        /*MJ |      1       |   mode(011) Fix BC PM, return IDLE      */
/*MT6140B*/    if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 0)     /*MJ |      2       |   mode(011) normal mode, return IDLE    */
/*MT6140B*/    {
/*MT6140B*/       HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*MT6140B*/    }
/*MT6140B*/    else
/*MT6140B*/    {
/*MT6140B*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6140B*/    }
/*MT6140B*/ }
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_SetSData_ST1( void )
/*MT6140B*/ {
/*MT6140B*/    SETUP_ST1();
/*MT6140B*/    HWRITE_3_SDATA(
/*MT6140B*/                   SCTRL_WARM,         SDATA_WARM,
/*MT6140B*/                   SCTRL_PLL,          l1d_rf.RFN_data,
/*MT6140B*/                   SCTRL_TXCW,         CW11_TXCW[l1d_rf.band]);
/*MT6140B*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140B*/    if(l1d_rf.d2c_txiqconfig==0)
/*MT6140B*/    {
/*MT6140B*/       L1D_BFE_SetTxIQ_Config();
/*MT6140B*/    }
/*MT6140B*/ #endif
/*MT6140B*/ }
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_SetSData_ST2( void )
/*MT6140B*/ {
/*MT6140B*/    SETUP_ST2();
/*MT6140B*/    HWRITE_1_SDATA( SCTRL_RESERVED,   0 );
/*MT6140B*/ }
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_SetSData_ST3( void )
/*MT6140B*/ {
/*MT6140B*/    SETUP_ST3();
/*MT6140B*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );
/*MT6140B*/ }
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6140B*/ {
/*MT6140B*/    SETUP_ST2B_ST2M();
/*MT6140B*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE | (((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot ) & 0x1)<<10));
/*MT6140B*/ }
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6140B*/ {
/*MT6140B*/    SETUP_ST2B_ST2M();
/*MT6140B*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE | (((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot ) & 0x1)<<10));
/*MT6140B*/ }
/*MT6140B*/
#endif

#if IS_RF_MT6140C
/*MT6140C*/
/*MT6140C*/ /*..........................................................*/
/*MT6140C*/ /*  Define Alias and Table                                  */
/*MT6140C*/ /*..........................................................*/
/*MT6140C*/
/*MT6140C*/ #define  SCTRL_STANDBY                SCTRL_WORD(0,26)
/*MT6140C*/ #define  SCTRL_WARM                   SCTRL_WORD(0,26)
/*MT6140C*/ #define  SCTRL_PLL                    SCTRL_WORD(0,26)
/*MT6140C*/ #define  SCTRL_AGC                    SCTRL_WORD(0,26)
/*MT6140C*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,26)
/*MT6140C*/ #define  SCTRL_AMCODE                 SCTRL_WORD(0,26) /* CW10 */
/*MT6140C*/ #define  SCTRL_TXCW                   SCTRL_WORD(0,26) /* CW11 */
/*MT6140C*/
/*MT6140C*/ const unsigned long SDATA_SLEEP   = 0x0000002L; // Sleep mode
/*MT6140C*/ const unsigned long SDATA_WARM    = 0x20827E2L; // Warm up mode
/*MT6140C*/ const unsigned long SDATA_TXMODE  = 0x0003002L; // GMSK 0x0003002L;
/*MT6140C*/ const unsigned long SDATA_RXMODE  = 0x0000C02L; // RX mode
/*MT6140C*/ const unsigned long cali_mode = 0x0001800L; //mode(110) for AM calibraton
/*MT6140C*/  unsigned long auto_cal  = 0x0002000L; //turn on auto calibrate
/*MT6140C*/  unsigned  PA_DAC  = 0x0;
/*MT6140C*//*A2*/  unsigned long TXCW[2][5]={{0x0,         //450   /* GMSK */
/*MT6140C*//*A2*/                             0x200080B,   //850
/*MT6140C*//*A2*/                             0x200480B,   //900
/*MT6140C*//*A2*/                             0x200000B,   //1800
/*MT6140C*//*A2*/                             0x200000B }, //1900
/*MT6140C*//*A2*/                            {0x0,         //450  /* EPSK */
/*MT6140C*//*A2*/                             0x200B86B,   //850
/*MT6140C*//*A2*/                             0x200F86B,   //900
/*MT6140C*//*A2*/                             0x200B04B,   //1800
/*MT6140C*//*A2*/                             0x200B04B }};//1900
/*MT6140C*//*A6*///  unsigned long TXCW[2][5]={{0x0,         //450   /* GMSK */
/*MT6140C*//*A6*///                             0x200000B,   //850
/*MT6140C*//*A6*///                             0x200400B,   //900
/*MT6140C*//*A6*///                             0x200000B,   //1800
/*MT6140C*//*A6*///                             0x200000B }, //1900
/*MT6140C*//*A6*///                            {0x0,         //450  /* EPSK */
/*MT6140C*//*A6*///                             0x201307B,   //1800
/*MT6140C*//*A6*///                             0x201307B }};//1900
/*MT6140C*/
/*MT6140C*/ /*..........................................................*/
/*MT6140C*/ /* Serial Interface Implement                               */
/*MT6140C*/ /*..........................................................*/
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_SetSData_SR1( void )
/*MT6140C*/ {
/*MT6140C*/    SETUP_SR1();
/*MT6140C*/    HWRITE_3_SDATA(SCTRL_WARM,    SDATA_WARM,
/*MT6140C*/                   SCTRL_PLL,     l1d_rf.RFN_data,
/*MT6140C*/                   SCTRL_AMCODE,  RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].amcode<<4|(0x000000A));
/*MT6140C*/ }
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_SetSData_SR2( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6140C*/ {                                                      /*MJ |      0       |   mode(110) get A code   */
/*MT6140C*/    SETUP_SR2();                                        /*MJ |      1       |   mode(011) Fix BC PM    */
/*MT6140C*/    if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 0)     /*MJ |      2       |   mode(011) normal mode  */
/*MT6140C*/    {
/*MT6140C*/       HWRITE_1_SDATA( SCTRL_AGC,    SDATA_RXMODE|((l1d_rf.AGC_data&0xFFFE3FF)|cali_mode)|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140C*/    }
/*MT6140C*/    else if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 1)
/*MT6140C*/    {
/*MT6140C*/       HWRITE_1_SDATA( SCTRL_AGC,    SDATA_RXMODE|l1d_rf.AGC_data|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140C*/    }
/*MT6140C*/    else
/*MT6140C*/    {
/*MT6140C*/       HWRITE_1_SDATA( SCTRL_AGC,    SDATA_RXMODE|l1d_rf.AGC_data|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140C*/    }
/*MT6140C*/ }
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_SetSData_SR3( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6140C*/ {                                                      /*MJ |      0       |   mode(110) get A code, not return IDLE */
/*MT6140C*/    SETUP_SR3();                                        /*MJ |      1       |   mode(011) Fix BC PM, return IDLE      */
/*MT6140C*/    if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 0)     /*MJ |      2       |   mode(011) normal mode, return IDLE    */
/*MT6140C*/    {
/*MT6140C*/       HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*MT6140C*/    }
/*MT6140C*/    else
/*MT6140C*/    {
/*MT6140C*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP|l1d_rf.AGC_data|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140C*/    }
/*MT6140C*/ }
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_SetSData_ST1( void )
/*MT6140C*/ {
/*MT6140C*/    SETUP_ST1();
/*MT6140C*/    HWRITE_3_SDATA(
/*MT6140C*/                   SCTRL_WARM,         SDATA_WARM,
/*MT6140C*/                   SCTRL_PLL,          l1d_rf.RFN_data,
/*MT6140C*/                   SCTRL_RESERVED,         0);
/*MT6140C*/
/*MT6140C*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140C*/    if(l1d_rf.d2c_txiqconfig==0)
/*MT6140C*/    {
/*MT6140C*/       L1D_BFE_SetTxIQ_Config();
/*MT6140C*/    }
/*MT6140C*/ #endif
/*MT6140C*/ }
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_SetSData_ST2( void )
/*MT6140C*/ {
/*MT6140C*/    SETUP_ST2();
/*MT6140C*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE );
/*MT6140C*/ }
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_SetSData_ST3( void )
/*MT6140C*/ {
/*MT6140C*/    SETUP_ST3();
/*MT6140C*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );
/*MT6140C*/ }
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6140C*/ {
/*MT6140C*/    SETUP_ST2B_ST2M();
/*MT6140C*/    HWRITE_1_SDATA( SCTRL_TXBAND,   TXCW[((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)][l1d_rf.band]|(PA_DAC<<8));
/*MT6140C*/ }
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6140C*/ {
/*MT6140C*/    SETUP_ST2B_ST2M();
/*MT6140C*/    HWRITE_1_SDATA( SCTRL_TXBAND,   TXCW[((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)][l1d_rf.band]|(PA_DAC<<8));
/*MT6140C*/ }
/*MT6140C*/
#endif

#if IS_RF_MT6140D
/*MT6140D*/
/*MT6140D*/ /*..........................................................*/
/*MT6140D*/ /*  Define Alias and Table                                  */
/*MT6140D*/ /*..........................................................*/
/*MT6140D*/
/*MT6140D*/ #define  SCTRL_STANDBY                SCTRL_WORD(0,26)
/*MT6140D*/ #define  SCTRL_WARM                   SCTRL_WORD(0,26)
/*MT6140D*/ #define  SCTRL_PLL                    SCTRL_WORD(0,26)
/*MT6140D*/ #define  SCTRL_AGC                    SCTRL_WORD(0,26)
/*MT6140D*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,26)
/*MT6140D*/ #define  SCTRL_AMCODE                 SCTRL_WORD(0,26) /* CW10 */
/*MT6140D*/ #define  SCTRL_TXCW                   SCTRL_WORD(0,26) /* CW11 */
/*MT6140D*/
/*MT6140D*/ const unsigned long SDATA_SLEEP   = 0x0000002L; // Sleep mode
/*MT6140D*/ const unsigned long SDATA_WARM    = 0x20827E2L; // Warm up mode
/*MT6140D*/ const unsigned long SDATA_TXMODE  = 0x0003002L; // GMSK 0x0003002L;
/*MT6140D*/ const unsigned long SDATA_RXMODE  = 0x0000C02L; // RX mode
/*MT6140D*/ unsigned long auto_cal  = 0x0002000L; //turn on auto calibrate
/*MT6140D*/ unsigned short LB_CW_High_Idx  = (19-12);  //PCL12 =Idx(19-12)
/*MT6140D*/ unsigned short HB_CW_High_Idx  = (15- 6);  //PCL 6 =Idx(15- 6)
/*MT6140D*/
/*MT6140D*/ /*..........................................................*/
/*MT6140D*/ /* Serial Interface Implement                               */
/*MT6140D*/ /*..........................................................*/
/*MT6140D*/
   #if IS_BSI_SX0_SUPPORT
/*MT6140D*/ void  L1D_RF_SetSData_SR0( void )
/*MT6140D*/ {
/*MT6140D*/ }
   #endif
/*MT6140D*/ void  L1D_RF_SetSData_SR1( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_SR1();
/*MT6140D*/    HWRITE_3_SDATA(SCTRL_WARM,    SDATA_WARM,
/*MT6140D*/                   SCTRL_PLL,     l1d_rf.RFN_data,
/*MT6140D*/                   SCTRL_RESERVED, 0 );
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_SR2( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_SR2();
/*MT6140D*/    HWRITE_1_SDATA( SCTRL_AGC,    SDATA_RXMODE|l1d_rf.AGC_data|auto_cal);
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_SR3( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_SR3();
/*MT6140D*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP);
/*MT6140D*/ }
/*MT6140D*/
   #if IS_BSI_SX0_SUPPORT
/*MT6140D*/ void  L1D_RF_SetSData_ST0( void )
/*MT6140D*/ {
/*MT6140D*/ }
   #endif
/*MT6140D*/ void  L1D_RF_SetSData_ST1( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_ST1();
/*MT6140D*/    HWRITE_3_SDATA(
/*MT6140D*/                   SCTRL_WARM,         SDATA_WARM,
/*MT6140D*/                   SCTRL_PLL,          l1d_rf.RFN_data,
/*MT6140D*/                   SCTRL_RESERVED,         0);
/*MT6140D*/
/*MT6140D*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140D*/    if(l1d_rf.d2c_txiqconfig==0)
/*MT6140D*/    {
/*MT6140D*/       L1D_BFE_SetTxIQ_Config();
/*MT6140D*/    }
/*MT6140D*/ #endif
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_ST2( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_ST2();
/*MT6140D*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE );
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_ST3( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_ST3();
/*MT6140D*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_ST2B_ST2M();
/*MT6140D*/    {
/*MT6140D*/    #if IS_EPSK_TX_SUPPORT
/*MT6140D*/       if((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)
/*MT6140D*/       {
/*MT6140D*/          unsigned short   cw_idx;
/*MT6140D*/          cw_idx=L1D_RF_GetTxPAVBias_TxITC(LB_CW_High_Idx, HB_CW_High_Idx);
/*MT6140D*/          HWRITE_1_SDATA( SCTRL_TXBAND, TXCW[(cw_idx>>4)&0x1][1][l1d_rf.band]|((cw_idx&0x7)<<8));
/*MT6140D*/       }
/*MT6140D*/       else
/*MT6140D*/    #endif
/*MT6140D*/       {
/*MT6140D*/          HWRITE_1_SDATA( SCTRL_TXBAND, TXCW[0][0][l1d_rf.band]);
/*MT6140D*/       }
/*MT6140D*/    }
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_ST2B_ST2M();
/*MT6140D*/    {
/*MT6140D*/ #if IS_EPSK_TX_SUPPORT
/*MT6140D*/       if((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)
/*MT6140D*/       {
/*MT6140D*/          unsigned short   cw_idx;
/*MT6140D*/          cw_idx=L1D_RF_GetTxPAVBias_TxITC(LB_CW_High_Idx, HB_CW_High_Idx);
/*MT6140D*/          HWRITE_1_SDATA( SCTRL_TXBAND, TXCW[(cw_idx>>4)&0x1][1][l1d_rf.band]|((cw_idx&0x7)<<8));
/*MT6140D*/       }
/*MT6140D*/       else
/*MT6140D*/ #endif
/*MT6140D*/       {
/*MT6140D*/          HWRITE_1_SDATA( SCTRL_TXBAND, TXCW[0][0][l1d_rf.band]);
/*MT6140D*/       }
/*MT6140D*/    }
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ #endif
/*MT6140D*/
#endif

#if IS_RF_CMOSEDGE
/*CMOSEDGE*/
/*CMOSEDGE*/ /*..........................................................*/
/*CMOSEDGE*/ /*  Define Alias and Table                                  */
/*CMOSEDGE*/ /*..........................................................*/
/*CMOSEDGE*/
/*CMOSEDGE*/ #define  SCTRL_WARM                SCTRL_WORD(0,26)
/*CMOSEDGE*/ #define  SCTRL_PLL                 SCTRL_WORD(0,26)
/*CMOSEDGE*/ #define  SCTRL_DCXO                SCTRL_WORD(0,26)
/*CMOSEDGE*/ #define  SCTRL_AGC                 SCTRL_WORD(0,26)
/*CMOSEDGE*/ #define  SCTRL_TXBAND              SCTRL_WORD(0,26)
/*CMOSEDGE*/ #define  SCTRL_TXCW                SCTRL_WORD(0,26)
/*CMOSEDGE*/ #define  SCTRL_SDM                 SCTRL_WORD(0,26)
/*CMOSEDGE*/
/*CMOSEDGE*/ const unsigned long SDATA_SLEEP   = 0x0200000L; // Sleep mode
/*CMOSEDGE*/ const unsigned long SDATA_WARM    = 0x0202000L; // Warm up mode
/*CMOSEDGE*/ const unsigned long SDATA_TXMODE  = 0x0E00000L; //cw14
/*CMOSEDGE*/ const unsigned long SDATA_RXMODE  = 0x0400000L; //cw4
/*CMOSEDGE*/ const unsigned long SDATA_SXSDM   = 0x061CC88L; //cw6
/*CMOSEDGE*/ const unsigned long TXCW[2][5]=
/*CMOSEDGE*/ {  {  0x0000000,  //450   /* GMSK */
/*CMOSEDGE*/       0x0E01001,  //850
/*CMOSEDGE*/       0x0E01001,  //900
/*CMOSEDGE*/       0x0E03600,  //1800
/*CMOSEDGE*/       0x0E03600,  //1900
/*CMOSEDGE*/    },
/*CMOSEDGE*/    {  0x0000000,  //450   /* EPSK */
/*CMOSEDGE*/       0x0E05202,  //850
/*CMOSEDGE*/       0x0E05202,  //900
/*CMOSEDGE*/       0x0E05000,  //1800
/*CMOSEDGE*/       0x0E05000,  //1900
/*CMOSEDGE*/    },
/*CMOSEDGE*/ };
/*CMOSEDGE*/
/*CMOSEDGE*/ /*..........................................................*/
/*CMOSEDGE*/ /* Serial Interface Implement                               */
/*CMOSEDGE*/ /*..........................................................*/
/*CMOSEDGE*/
/*CMOSEDGE*/ void  L1D_RF_SetSData_SR1( void )
/*CMOSEDGE*/ {
/*CMOSEDGE*/    SETUP_SR1();
/*CMOSEDGE*/    if((l1d_rf.RFN_data&0x3FF)==0&&(l1d_rf.IFN_data&0x1FFF)==0)  //interger ch
/*CMOSEDGE*/    {
/*CMOSEDGE*/       HWRITE_4_SDATA(SCTRL_SDM,  (SDATA_SXSDM&~0x0004400),
/*CMOSEDGE*/                      SCTRL_WARM,  SDATA_WARM|(l1d_rf.IFN_data&0x00FFFFF),
/*CMOSEDGE*/                      SCTRL_PLL,   l1d_rf.RFN_data,
/*CMOSEDGE*/                      SCTRL_DCXO,((l1d_rf.AFC_data&0x1FFF)<<7)|0x0300000|XO_CapID );
/*CMOSEDGE*/    }
/*CMOSEDGE*/    else
/*CMOSEDGE*/    {
/*CMOSEDGE*/       HWRITE_4_SDATA(SCTRL_SDM,    SDATA_SXSDM,
/*CMOSEDGE*/                      SCTRL_WARM,   SDATA_WARM|(l1d_rf.IFN_data&0x00FFFFF),
/*CMOSEDGE*/                      SCTRL_PLL,    l1d_rf.RFN_data,
/*CMOSEDGE*/                      SCTRL_DCXO, ((l1d_rf.AFC_data&0x1FFF)<<7)|0x0300000|XO_CapID );
/*CMOSEDGE*/    }
/*CMOSEDGE*/ }
/*CMOSEDGE*/
/*CMOSEDGE*/ void  L1D_RF_SetSData_SR2( void )
/*CMOSEDGE*/ {
/*CMOSEDGE*/    SETUP_SR2();
/*CMOSEDGE*/    HWRITE_1_SDATA( SCTRL_AGC,    SDATA_RXMODE|(l1d_rf.AGC_data&0x3F));
/*CMOSEDGE*/ }
/*CMOSEDGE*/
/*CMOSEDGE*/ void  L1D_RF_SetSData_SR3( void )
/*CMOSEDGE*/ {
/*CMOSEDGE*/    SETUP_SR3();
/*CMOSEDGE*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP);
/*CMOSEDGE*/ }
/*CMOSEDGE*/
/*CMOSEDGE*/ void  L1D_RF_SetSData_ST1( void )
/*CMOSEDGE*/ {
/*CMOSEDGE*/    SETUP_ST1();
/*CMOSEDGE*/    if((l1d_rf.RFN_data&0x3FF)==0&&(l1d_rf.IFN_data&0x1FFF)==0)  //interger ch
/*CMOSEDGE*/    {
/*CMOSEDGE*/       HWRITE_4_SDATA(SCTRL_SDM,  (SDATA_SXSDM&~0x0004400),
/*CMOSEDGE*/                      SCTRL_WARM,  SDATA_WARM|(l1d_rf.IFN_data&0x00FFFFF),
/*CMOSEDGE*/                      SCTRL_PLL,   l1d_rf.RFN_data,
/*CMOSEDGE*/                      SCTRL_DCXO, ((l1d_rf.AFC_data&0x1FFF)<<7)|0x0300000|XO_CapID);
/*CMOSEDGE*/    }
/*CMOSEDGE*/    else
/*CMOSEDGE*/    {
/*CMOSEDGE*/       HWRITE_4_SDATA(SCTRL_SDM,  SDATA_SXSDM,
/*CMOSEDGE*/                      SCTRL_WARM, SDATA_WARM|(l1d_rf.IFN_data&0x00FFFFF),
/*CMOSEDGE*/                      SCTRL_PLL,  l1d_rf.RFN_data,
/*CMOSEDGE*/                      SCTRL_DCXO, ((l1d_rf.AFC_data&0x1FFF)<<7)|0x0300000|XO_CapID);
/*CMOSEDGE*/    }
/*CMOSEDGE*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*CMOSEDGE*/    if(l1d_rf.d2c_txiqconfig==0)
/*CMOSEDGE*/    {
/*CMOSEDGE*/       L1D_BFE_SetTxIQ_Config();
/*CMOSEDGE*/    }
/*CMOSEDGE*/ #endif
/*CMOSEDGE*/ }
/*CMOSEDGE*/
/*CMOSEDGE*/ void  L1D_RF_SetSData_ST2( void )
/*CMOSEDGE*/ {
/*CMOSEDGE*/    SETUP_ST2();
/*CMOSEDGE*/    {
/*CMOSEDGE*/ #if IS_EPSK_TX_SUPPORT
/*CMOSEDGE*/       if((l1d_rf.tx_mod_type2)&0x1)
/*CMOSEDGE*/       {
/*CMOSEDGE*/          if(l1d_rf.band<=2)
/*CMOSEDGE*/          {  HWRITE_1_SDATA( SCTRL_TXCW, 0x1012D4A);
/*CMOSEDGE*/          }
/*CMOSEDGE*/          else
/*CMOSEDGE*/          {  HWRITE_1_SDATA( SCTRL_TXCW, 0x102DDB5);
/*CMOSEDGE*/          }
/*CMOSEDGE*/       }
/*CMOSEDGE*/       else
/*CMOSEDGE*/ #endif
/*CMOSEDGE*/       {
/*CMOSEDGE*/          HWRITE_1_SDATA( SCTRL_RESERVED, 0);
/*CMOSEDGE*/       }
/*CMOSEDGE*/    }
/*CMOSEDGE*/ }
/*CMOSEDGE*/
/*CMOSEDGE*/ void  L1D_RF_SetSData_ST3( void )
/*CMOSEDGE*/ {
/*CMOSEDGE*/    SETUP_ST3();
/*CMOSEDGE*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP);
/*CMOSEDGE*/ }
/*CMOSEDGE*/
/*CMOSEDGE*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*CMOSEDGE*/ void  L1D_RF_SetSData_ST2B( void )
/*CMOSEDGE*/ {
/*CMOSEDGE*/    SETUP_ST2B_ST2M();
/*CMOSEDGE*/    {
/*CMOSEDGE*/    #if IS_EPSK_TX_SUPPORT
/*CMOSEDGE*/       if((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)
/*CMOSEDGE*/       {
/*CMOSEDGE*/          const   sRAMPDATA*       band_epsk;
/*CMOSEDGE*/          unsigned char    lowest_dbm, power_dbm, idx;
/*CMOSEDGE*/          short weight;
/*CMOSEDGE*/
/*CMOSEDGE*/          band_epsk = RampData_EPSK[l1d_rf.band];
/*CMOSEDGE*/          power_dbm=l1d_rf2.tx_power[l1d_rf.cur_slot];
/*CMOSEDGE*/          lowest_dbm=LOWEST_TX_POWER[l1d_rf.band];
/*CMOSEDGE*/          if(power_dbm > (lowest_dbm+2*15))
/*CMOSEDGE*/          {  power_dbm = lowest_dbm+2*15; }
/*CMOSEDGE*/          else if(power_dbm < lowest_dbm)
/*CMOSEDGE*/          {  power_dbm = lowest_dbm; }
/*CMOSEDGE*/
/*CMOSEDGE*/          idx = (power_dbm-lowest_dbm)/2;
/*CMOSEDGE*/
/*CMOSEDGE*/          weight=L1D_RF_SetPGASubBandWeight();
/*CMOSEDGE*/          if((band_epsk->power[idx]+weight)<0)  weight=0;
/*CMOSEDGE*/
/*CMOSEDGE*/          if(l1d_rf.band<=2)
/*CMOSEDGE*/          {  HWRITE_1_SDATA( SCTRL_TXBAND, TXCW[1][l1d_rf.band]|((((band_epsk->power[idx]+weight)&0x7F))<<2));
/*CMOSEDGE*/          }
/*CMOSEDGE*/          else
/*CMOSEDGE*/          {  HWRITE_1_SDATA( SCTRL_TXBAND, TXCW[1][l1d_rf.band]|((((band_epsk->power[idx]+weight)&0x7F))<<2));
/*CMOSEDGE*/          }
/*CMOSEDGE*/       }
/*CMOSEDGE*/       else
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/       {
/*CMOSEDGE*/          if(l1d_rf.band<=2)
/*CMOSEDGE*/          {  HWRITE_1_SDATA( SCTRL_TXBAND, TXCW[0][l1d_rf.band]|(RFSpecialCoef.tx.CMOSEDGEtx.LB_GMSK_TX_PGA_GC<<2));
/*CMOSEDGE*/          }
/*CMOSEDGE*/          else
/*CMOSEDGE*/          {  HWRITE_1_SDATA( SCTRL_TXBAND, TXCW[0][l1d_rf.band]|(RFSpecialCoef.tx.CMOSEDGEtx.HB_GMSK_TX_PGA_GC<<2));
/*CMOSEDGE*/          }
/*CMOSEDGE*/       }
/*CMOSEDGE*/    }
/*CMOSEDGE*/ }
/*CMOSEDGE*/
/*CMOSEDGE*/ void  L1D_RF_SetSData_ST2M( void )
/*CMOSEDGE*/ {
/*CMOSEDGE*/    SETUP_ST2B_ST2M();
/*CMOSEDGE*/    {
/*CMOSEDGE*/ #if IS_EPSK_TX_SUPPORT
/*CMOSEDGE*/       if((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)
/*CMOSEDGE*/       {
/*CMOSEDGE*/          const   sRAMPDATA*       band_epsk;
/*CMOSEDGE*/          unsigned char     lowest_dbm, power_dbm, idx;
/*CMOSEDGE*/          short weight;
/*CMOSEDGE*/
/*CMOSEDGE*/          band_epsk = RampData_EPSK[l1d_rf.band];
/*CMOSEDGE*/          power_dbm=l1d_rf2.tx_power[l1d_rf.cur_slot];
/*CMOSEDGE*/          lowest_dbm=LOWEST_TX_POWER[l1d_rf.band];
/*CMOSEDGE*/          if(power_dbm > (lowest_dbm+2*15))
/*CMOSEDGE*/          {  power_dbm = lowest_dbm+2*15; }
/*CMOSEDGE*/          else if(power_dbm < lowest_dbm)
/*CMOSEDGE*/          {  power_dbm = lowest_dbm; }
/*CMOSEDGE*/
/*CMOSEDGE*/          idx = (power_dbm-lowest_dbm)/2;
/*CMOSEDGE*/
/*CMOSEDGE*/          weight=L1D_RF_SetPGASubBandWeight();
/*CMOSEDGE*/          if((band_epsk->power[idx]+weight)<0)  weight=0;
/*CMOSEDGE*/
/*CMOSEDGE*/          if(l1d_rf.band<=2)
/*CMOSEDGE*/          {  HWRITE_1_SDATA( SCTRL_TXBAND, TXCW[1][l1d_rf.band]|((((band_epsk->power[idx]+weight)&0x7F))<<2));
/*CMOSEDGE*/          }
/*CMOSEDGE*/          else
/*CMOSEDGE*/          {  HWRITE_1_SDATA( SCTRL_TXBAND, TXCW[1][l1d_rf.band]|((((band_epsk->power[idx]+weight)&0x7F))<<2));
/*CMOSEDGE*/          }
/*CMOSEDGE*/       }
/*CMOSEDGE*/       else
/*CMOSEDGE*/ #endif
/*CMOSEDGE*/       {
/*CMOSEDGE*/          if(l1d_rf.band<=2)
/*CMOSEDGE*/          {  HWRITE_1_SDATA( SCTRL_TXBAND, TXCW[0][l1d_rf.band]|(RFSpecialCoef.tx.CMOSEDGEtx.LB_GMSK_TX_PGA_GC<<2));
/*CMOSEDGE*/          }
/*CMOSEDGE*/          else
/*CMOSEDGE*/          {  HWRITE_1_SDATA( SCTRL_TXBAND, TXCW[0][l1d_rf.band]|(RFSpecialCoef.tx.CMOSEDGEtx.HB_GMSK_TX_PGA_GC<<2));
/*CMOSEDGE*/          }
/*CMOSEDGE*/       }
/*CMOSEDGE*/    }
/*CMOSEDGE*/ }
/*CMOSEDGE*/
/*CMOSEDGE*/ #endif
/*CMOSEDGE*/
#endif

#if IS_RF_MTKSOC1T
/*MTKSOC1T*/
/*MTKSOC1T*//*..........................................................*/
/*MTKSOC1T*//*  Define Alias and Table                                  */
/*MTKSOC1T*//*..........................................................*/
/*MTKSOC1T*/
/*MTKSOC1T*/#define  SCTRL_WARM                    SCTRL_WORD(0,26)
/*MTKSOC1T*/#define  SCTRL_PLL                     SCTRL_WORD(0,26)
/*MTKSOC1T*/#define  SCTRL_DCXO                    SCTRL_WORD(0,26)
/*MTKSOC1T*/#define  SCTRL_AGC                     SCTRL_WORD(0,26)
/*MTKSOC1T*/#define  SCTRL_TXBAND                  SCTRL_WORD(0,26)
/*MTKSOC1T*/#define  SCTRL_TXCW                    SCTRL_WORD(0,26)
/*MTKSOC1T*/#define  SCTRL_TXDCOC                  SCTRL_WORD(0,26)
/*MTKSOC1T*/#define  SCTRL_CAPID                   SCTRL_WORD(0,26)
/*MTKSOC1T*/#define  SCTRL_RFVCO_K                 SCTRL_WORD(0,26)
/*MTKSOC1T*/#define  SDATA_SLEEP                   0x0200000L
/*MTKSOC1T*/#define  SCTRL_CW23                    SCTRL_WORD(0,26)
/*MTKSOC1T*/#if MTKSOC1_SX_CALSBA
/*MTKSOC1T*/#define  SCTRL_CW27                    SCTRL_RFVCO_K
/*MTKSOC1T*/#else
/*MTKSOC1T*/#define  SCTRL_CW27                    SCTRL_RESERVED
/*MTKSOC1T*/#endif
/*MTKSOC1T*/
/*MTKSOC1T*//*..........................................................*/
/*MTKSOC1T*//* Serial Interface Implement                               */
/*MTKSOC1T*//*..........................................................*/
/*MTKSOC1T*/
/*MTKSOC1T*/void  L1D_RF_SetSData_SR1( void )
/*MTKSOC1T*/{
/*MTKSOC1T*/   long cw23;
/*MTKSOC1T*/   SETUP_SR1();
/*MTKSOC1T*/
/*MTKSOC1T*/   if(  (l1d_rf.band == FrequencyBand1900) || (l1d_rf.band == FrequencyBand900) )
/*MTKSOC1T*/   {
/*MTKSOC1T*/      cw23 = 0x1784201L;
/*MTKSOC1T*/   }
/*MTKSOC1T*/   else
/*MTKSOC1T*/   {
/*MTKSOC1T*/      cw23 = 0x1784200L;
/*MTKSOC1T*/   }
/*MTKSOC1T*/   HWRITE_5_SDATA(
/*MTKSOC1T*/      SCTRL_DCXO,    (l1d_rf.AFC_data&0x1FFF)|0x0300000,
/*MTKSOC1T*/      SCTRL_CW27, ( ( (l1d_rf.RFN_data>>25)& 0x3F)<<7 ) | ( (l1d_rf.IFN_data>>25)& 0x7F) | 0x1b00000L,/*cw27*/
/*MTKSOC1T*/      SCTRL_WARM,         (l1d_rf.IFN_data & 0x1FFFFFF),
/*MTKSOC1T*/      SCTRL_PLL,          (l1d_rf.RFN_data & 0x1FFFFFF),
/*MTKSOC1T*/      SCTRL_CW23, cw23);
/*MTKSOC1T*/}
/*MTKSOC1T*/
/*MTKSOC1T*/void  L1D_RF_SetSData_SR2( void )
/*MTKSOC1T*/{
/*MTKSOC1T*/   SETUP_SR2();
/*MTKSOC1T*/   HWRITE_1_SDATA( SCTRL_AGC,    l1d_rf.AGC_data);  //CW4
/*MTKSOC1T*/}
/*MTKSOC1T*/
/*MTKSOC1T*/void  L1D_RF_SetSData_SR3( void )
/*MTKSOC1T*/{
/*MTKSOC1T*/   SETUP_SR3();
/*MTKSOC1T*/   HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP);
/*MTKSOC1T*/}
/*MTKSOC1T*/
/*MTKSOC1T*/void  L1D_RF_SetSData_ST1( void )
/*MTKSOC1T*/{
/*MTKSOC1T*/   SETUP_ST1();
/*MTKSOC1T*/
/*MTKSOC1T*/   HWRITE_5_SDATA(
/*MTKSOC1T*/      SCTRL_DCXO,    (l1d_rf.AFC_data&0x1FFF)|0x0300000,
/*MTKSOC1T*/      SCTRL_CW27, ( ( (l1d_rf.RFN_data>>25)& 0x3F)<<7 ) | ( (l1d_rf.IFN_data>>25)& 0x7F) | 0x1b00000L,/*cw27*/
/*MTKSOC1T*/      SCTRL_WARM,         (l1d_rf.IFN_data & 0x1FFFFFF),
/*MTKSOC1T*/      SCTRL_PLL,          (l1d_rf.RFN_data & 0x1FFFFFF),
/*MTKSOC1T*/      SCTRL_RESERVED, 0 );
/*MTKSOC1T*/
/*MTKSOC1T*/   L1D_SetTxIQSwap_NO_PCS1900();
/*MTKSOC1T*/}
/*MTKSOC1T*/
/*MTKSOC1T*/void  L1D_RF_SetSData_ST2( void )
/*MTKSOC1T*/{
/*MTKSOC1T*/   SETUP_ST2();
/*MTKSOC1T*/#if IS_RF_MTKSOC1_A5
/*MTKSOC1T*/   if( l1d_rf.band <= FrequencyBand900 )
/*MTKSOC1T*/   {  HWRITE_1_SDATA( SCTRL_TXCW, (0x0E0D0AB & ~( (0x1F<<13)|0x18 )) | (0x9<<13)|(0x1<<3) );} //CW14
/*MTKSOC1T*/   else
/*MTKSOC1T*/   {  HWRITE_1_SDATA( SCTRL_TXCW, (0x0E0D0AB & ~( (0x1F<<13)|0x18 )) | (0x8<<13)|(0x1<<3) );} //CW14
/*MTKSOC1T*/#else
/*MTKSOC1T*/   if( l1d_rf.band <= FrequencyBand900 )
/*MTKSOC1T*/   {  HWRITE_1_SDATA( SCTRL_TXCW, (0x0E19EBB & ~( (0x1F<<13)|0x18 )) | (0xC<<13)|(0x1<<3) );} //CW14
/*MTKSOC1T*/   else
/*MTKSOC1T*/   {  HWRITE_1_SDATA( SCTRL_TXCW, (0x0E19EBB & ~( (0x1F<<13)|0x18 )) | (0x8<<13)|(0x1<<3) );} //CW14
/*MTKSOC1T*/#endif
/*MTKSOC1T*/}
/*MTKSOC1T*/
/*MTKSOC1T*/void  L1D_RF_SetSData_ST3( void )
/*MTKSOC1T*/{
/*MTKSOC1T*/   SETUP_ST3();
/*MTKSOC1T*/   HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP);
/*MTKSOC1T*/}
/*MTKSOC1T*/
/*MTKSOC1T*/#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MTKSOC1T*/
/*MTKSOC1T*/void  L1D_RF_SetSData_ST2B( void )
/*MTKSOC1T*/{
/*MTKSOC1T*/}
/*MTKSOC1T*/
/*MTKSOC1T*/void  L1D_RF_SetSData_ST2M( void )
/*MTKSOC1T*/{
/*MTKSOC1T*/}
/*MTKSOC1T*/
/*MTKSOC1T*/#endif
/*MTKSOC1T*/
#endif

#if IS_RF_MTKSOC1
/*MTKSOC1*/
/*MTKSOC1*/ /*..........................................................*/
/*MTKSOC1*/ /*  Define Alias and Table                                  */
/*MTKSOC1*/ /*..........................................................*/
/*MTKSOC1*/
/*MTKSOC1*/ #define  SCTRL_WARM                    SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SCTRL_PLL                     SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SCTRL_DCXO                    SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SCTRL_AGC                     SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SCTRL_TXBAND                  SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SCTRL_TXCW                    SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SCTRL_TXDCOC                  SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SCTRL_CAPID                   SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SCTRL_RFVCO_K                 SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SDATA_SLEEP                   0x0200000L
/*MTKSOC1*/ #define  SCTRL_CW23                    SCTRL_RESERVED
/*MTKSOC1*/ #define  SCTRL_CW27                    SCTRL_RESERVED
/*MTKSOC1*/
/*MTKSOC1*/ /*..........................................................*/
/*MTKSOC1*/ /* Serial Interface Implement                               */
/*MTKSOC1*/ /*..........................................................*/
/*MTKSOC1*/
/*MTKSOC1*/ extern int L1D_Get_MT6253_SDATA_Index( void );
/*MTKSOC1*/
/*MTKSOC1*/ static unsigned long ST2_DATA_TABLE[2][3]=
/*MTKSOC1*/ {
/*MTKSOC1*/    {
/*MTKSOC1*/       (0x0E19EAB & ~(0x1FF<<9)) | (0x0EC<<9),
/*MTKSOC1*/       (0x0E19EAB & ~(0x1FF<<9)) | (0x08F<<9),
/*MTKSOC1*/       (0x0E19EAB & ~(0x1FF<<9)) | (0x07F<<9),
/*MTKSOC1*/    },
/*MTKSOC1*/    {
/*MTKSOC1*/       0x0E1CEB3,
/*MTKSOC1*/       0x0E12EB3,
/*MTKSOC1*/       0x0E10EB3,
/*MTKSOC1*/    },
/*MTKSOC1*/ };
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_SetSData_SR1( void )
/*MTKSOC1*/ {
/*MTKSOC1*/    long cw23;
/*MTKSOC1*/    SETUP_SR1();
/*MTKSOC1*/
/*MTKSOC1*/    if(  (l1d_rf.band == FrequencyBand1900) || (l1d_rf.band == FrequencyBand900) )
/*MTKSOC1*/    {
/*MTKSOC1*/       cw23 = 0x1784201L;
/*MTKSOC1*/    }
/*MTKSOC1*/    else
/*MTKSOC1*/    {
/*MTKSOC1*/       cw23 = 0x1784200L;
/*MTKSOC1*/    }
/*MTKSOC1*/    HWRITE_5_SDATA(
/*MTKSOC1*/       SCTRL_DCXO,    (l1d_rf.AFC_data&0x1FFF)|0x0300000,
/*MTKSOC1*/       SCTRL_CW27, ( ( (l1d_rf.RFN_data>>25)& 0x3F)<<7 ) | ( (l1d_rf.IFN_data>>25)& 0x7F) | 0x1b00000L,/*cw27*/
/*MTKSOC1*/       SCTRL_WARM,         (l1d_rf.IFN_data & 0x1FFFFFF),
/*MTKSOC1*/       SCTRL_PLL,          (l1d_rf.RFN_data & 0x1FFFFFF),
/*MTKSOC1*/       SCTRL_CW23, cw23);
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_SetSData_SR2( void )
/*MTKSOC1*/ {
/*MTKSOC1*/    SETUP_SR2();
/*MTKSOC1*/    HWRITE_1_SDATA( SCTRL_AGC,    l1d_rf.AGC_data);  //CW4
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_SetSData_SR3( void )
/*MTKSOC1*/ {
/*MTKSOC1*/    SETUP_SR3();
/*MTKSOC1*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP);
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_SetSData_ST1( void )
/*MTKSOC1*/ {
/*MTKSOC1*/    SETUP_ST1();
/*MTKSOC1*/
/*MTKSOC1*/    HWRITE_5_SDATA(
/*MTKSOC1*/       SCTRL_DCXO,    (l1d_rf.AFC_data&0x1FFF)|0x0300000,
/*MTKSOC1*/       SCTRL_CW27, ( ( (l1d_rf.RFN_data>>25)& 0x3F)<<7 ) | ( (l1d_rf.IFN_data>>25)& 0x7F) | 0x1b00000L,/*cw27*/
/*MTKSOC1*/       SCTRL_WARM,         (l1d_rf.IFN_data & 0x1FFFFFF),
/*MTKSOC1*/       SCTRL_PLL,          (l1d_rf.RFN_data & 0x1FFFFFF),
/*MTKSOC1*/       SCTRL_RESERVED, 0 );
/*MTKSOC1*/
/*MTKSOC1*/    L1D_SetTxIQSwap_NO_PCS1900();
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_SetSData_ST2( void )
/*MTKSOC1*/ {
/*MTKSOC1*/    unsigned long *ST2_DATA = L1D_Get_MT6253_SDATA_Index() ? ST2_DATA_TABLE[1] : ST2_DATA_TABLE[0];
/*MTKSOC1*/    SETUP_ST2();
/*MTKSOC1*/    if( l1d_rf.band <= FrequencyBand900 )
/*MTKSOC1*/    {  HWRITE_1_SDATA( SCTRL_TXCW, ST2_DATA[0] );  } //CW14
/*MTKSOC1*/    else
/*MTKSOC1*/    {
/*MTKSOC1*/       //CW14 : OPLL_LP[4:0]=00111 and APD_GC[3:0] = 1111 in DCS and PCS bands when OPLL_DIV4O5_DIV4 = 0.
/*MTKSOC1*/       //CW14 : OPLL_LP[4:0]=01000 and APD_GC[3:0] = 1111 in DCS and PCS bands when OPLL_DIV4O5_DIV4 = 1.
/*MTKSOC1*/       if(l1d_rf.IFN_data & 0x0080000) // in DCS and PCS bands when OPLL_DIV4O5_DIV4 = 1.
/*MTKSOC1*/       {  HWRITE_1_SDATA( SCTRL_TXCW, ST2_DATA[1] );  } //CW14
/*MTKSOC1*/       else                           //in DCS and PCS bands when OPLL_DIV4O5_DIV4 = 0
/*MTKSOC1*/       {  HWRITE_1_SDATA( SCTRL_TXCW, ST2_DATA[2] );  } //CW14
/*MTKSOC1*/    }
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_SetSData_ST3( void )
/*MTKSOC1*/ {
/*MTKSOC1*/    SETUP_ST3();
/*MTKSOC1*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP);
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_SetSData_ST2B( void )
/*MTKSOC1*/ {
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_SetSData_ST2M( void )
/*MTKSOC1*/ {
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ #endif
/*MTKSOC1*/
#endif

#if IS_RF_MT6252RF
/*MT6252RF*/
/*MT6252RF*/ /*..........................................................*/
/*MT6252RF*/ /*  Define Alias                                            */
/*MT6252RF*/ /*..........................................................*/
/*MT6252RF*/
/*MT6252RF*/ #define  SCTRL_STANDBY                 SCTRL_WORD(0,29)
/*MT6252RF*/ #define  SCTRL_PLL                     SCTRL_WORD(0,29)
/*MT6252RF*/ #define  SCTRL_DCXO                    SCTRL_WORD(0,29)
/*MT6252RF*/ #define  SCTRL_AGC                     SCTRL_WORD(0,29)
/*MT6252RF*/ #define  SCTRL_TXCW                    SCTRL_WORD(0,29)
/*MT6252RF*/ #define  SCTRL_CW4                     SCTRL_WORD(0,29)
/*MT6252RF*/ #define  SDATA_SLEEP                   0x0200000L
/*MT6252RF*/ #define  SDATA_STANDBY                 0x0244000L
/*MT6252RF*/ #define  SDATA_TXSLEEP                 0x0280000L
/*MT6252RF*/ #define  SDATA_CW96                    0x6072800L                            /* RX Gain (from 0x6013200L to 0x6072800L) */
/*MT6252RF*/
/*MT6252RF*/ /*..........................................................*/
/*MT6252RF*/ /* Serial Interface Implement                               */
/*MT6252RF*/ /*..........................................................*/
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_SR0( void )
/*MT6252RF*/ {
/*MT6252RF*/    SETUP_SR0();
/*MT6252RF*/    HWRITE_3_SDATA( SCTRL_DCXO,    (l1d_rf.AFC_data & 0x1FFF) | (0x3900000L), /* CW57 : set AFC DAC */
/*MT6252RF*/                    SCTRL_STANDBY,  l1d_rf.IFN_data                         , /* CW2  : set mode = standby */
/*MT6252RF*/                    SCTRL_RESERVED, 0 );                                      /* to prevent from missending */
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_SR1( void )
/*MT6252RF*/ {
/*MT6252RF*/    SETUP_SR1();
/*MT6252RF*/    HWRITE_1_SDATA( SCTRL_PLL,      l1d_rf.RFN_data  );                       /* CW1  : set PLL, RF will enter warmup state */
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_SR2( void )
/*MT6252RF*/ {
/*MT6252RF*/    SETUP_SR2();
/*MT6252RF*/    HWRITE_1_SDATA( SCTRL_AGC,      l1d_rf.AGC_data | (SDATA_CW96) );         /* CW96 : set gain */
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_SR3( void )
/*MT6252RF*/ {
/*MT6252RF*/    SETUP_SR3();
/*MT6252RF*/    #if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF
/*MT6252RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6252RF*/    {
/*MT6252RF*/       #if IS_RF_TX_SLEEP_MODE_SUPPORT
/*MT6252RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_TXSLEEP );                           /* CW2: set mode = TX sleep mode */
/*MT6252RF*/       #else
/*MT6252RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );         /* CW2: set mode = stand-by mode */
/*MT6252RF*/       #endif
/*MT6252RF*/    }
/*MT6252RF*/    else
/*MT6252RF*/    #endif
/*MT6252RF*/    {
/*MT6252RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP);                              /* CW2: set mode = sleep mode */
/*MT6252RF*/    }
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_ST0( void )
/*MT6252RF*/ {
/*MT6252RF*/    unsigned long CW4 = (l1d_rf.band & 0x0001) ? 0x04156A8 : 0x04155A8;
/*MT6252RF*/    SETUP_ST0();
/*MT6252RF*/    HWRITE_3_SDATA( SCTRL_STANDBY,  l1d_rf.IFN_data                         , /* CW2  : set mode = standby */
/*MT6252RF*/                    SCTRL_DCXO,    (l1d_rf.AFC_data & 0x1FFF) | (0x3900000L), /* CW57 : set AFC DAC */
/*MT6252RF*/                    SCTRL_CW4,      CW4 );                                    /* CW4  : optimize performance by band */
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_ST1( void )
/*MT6252RF*/ {
/*MT6252RF*/    SETUP_ST1();
/*MT6252RF*/    HWRITE_1_SDATA( SCTRL_PLL,      l1d_rf.RFN_data );                        /* CW1  : set PLL, RF will enter warmup state */
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_ST2( void )
/*MT6252RF*/ {
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_ST3( void )
/*MT6252RF*/ {
/*MT6252RF*/    SETUP_ST3();
/*MT6252RF*/    #if IS_RF_VCO_PARTIAL_DOO_ON
/*MT6252RF*/    if( l1d_rf2.dedicated_flag & SC_DEDICATED_2TX )
/*MT6252RF*/    {
/*MT6252RF*/       #if IS_RF_TX_SLEEP_MODE_SUPPORT
/*MT6252RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_TXSLEEP );                           /* CW2: set mode = TX sleep mode */
/*MT6252RF*/       #else
/*MT6252RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );         /* CW2: set mode = stand-by mode */
/*MT6252RF*/       #endif
/*MT6252RF*/    }
/*MT6252RF*/    else
/*MT6252RF*/    #elif IS_RF_VCO_DOO_OFF
/*MT6252RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6252RF*/    {
/*MT6252RF*/       #if IS_RF_TX_SLEEP_MODE_SUPPORT
/*MT6252RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_TXSLEEP );                           /* CW2: set mode = TX sleep mode */
/*MT6252RF*/       #else
/*MT6252RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );         /* CW2: set mode = stand-by mode */
/*MT6252RF*/       #endif
/*MT6252RF*/    }
/*MT6252RF*/    else
/*MT6252RF*/    #endif
/*MT6252RF*/    {
/*MT6252RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );                             /* CW2: set mode = sleep mode */
/*MT6252RF*/    }
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6252RF*/ {
/*MT6252RF*/    SETUP_ST2B_ST2M();
/*MT6252RF*/    HWRITE_1_SDATA( SCTRL_TXCW,     0x8500000L );                             /* CW133: to enter TX mode */
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6252RF*/ {
/*MT6252RF*/    SETUP_ST2B_ST2M();
/*MT6252RF*/    HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*MT6252RF*/ }
/*MT6252RF*/
#endif

#if IS_RF_MT6256RF
/*MT6256RF*/
/*MT6256RF*/ /*..........................................................*/
/*MT6256RF*/ /*  Define Alias and Table                                  */
/*MT6256RF*/ /*..........................................................*/
/*MT6256RF*/
/*MT6256RF*/ #define  SCTRL_STANDBY                 SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SCTRL_WARM                    SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SCTRL_PLL                     SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SCTRL_DCXO                    SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SCTRL_AGC                     SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SCTRL_TXCW                    SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SCTRL_RXCW                    SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SDATA_SLEEP                   BSI_CW(0x02, 0x10000)
/*MT6256RF*/ #define  SDATA_STANDBY                 BSI_CW(0x02, 0x44000)
/*MT6256RF*/
/*MT6256RF*/    #if IS_DYNAMIC_TC_GAIN_SUPPORT
/*MT6256RF*/ #define  SCTRL_HWTC                    SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SDATA_HWTC                    L1D_RF_Get_TC_Gain_CW()
/*MT6256RF*/    #else
/*MT6256RF*/ #define  SCTRL_HWTC                    SCTRL_RESERVED
/*MT6256RF*/ #define  SDATA_HWTC                    0
/*MT6256RF*/    #endif
/*MT6256RF*/
/*MT6256RF*/ /*..........................................................*/
/*MT6256RF*/ /* Serial Interface Implement                               */
/*MT6256RF*/ /*..........................................................*/
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_SR0( void )
/*MT6256RF*/ {
/*MT6256RF*/    unsigned long cw98;
/*MT6256RF*/    SETUP_SR0();
/*MT6256RF*/    #if IS_CHIP_MT6256_S00
/*MT6256RF*/    cw98 = l1d_rf.band < FrequencyBand1800 ? BSI_CW(0x62, 0xF6E4A) : BSI_CW(0x62, 0x1165A);
/*MT6256RF*/    #else
/*MT6256RF*/    cw98 = l1d_rf.band < FrequencyBand1800 ? BSI_CW(0x62, 0x11852) : BSI_CW(0x62, 0x11452);
/*MT6256RF*/    #endif
/*MT6256RF*/    HWRITE_3_SDATA( SCTRL_STANDBY,  l1d_rf.IFN_data,                       /* CW2: set mode = standby */
/*MT6256RF*/                    SCTRL_DCXO,     BSI_CW(0x39, l1d_rf.AFC_data&0x1FFF),  /* CW57: set AFC DAC */
/*MT6256RF*/                    SCTRL_RXCW,     cw98            );                     /* CW98: for RX LNA bias current */
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_SR1( void )
/*MT6256RF*/ {
/*MT6256RF*/    SETUP_SR1();
/*MT6256RF*/    HWRITE_1_SDATA( SCTRL_PLL,      l1d_rf.RFN_data );  /* CW1: set PLL, RF will enter warmup state */
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_SR2( void )
/*MT6256RF*/ {
/*MT6256RF*/    SETUP_SR2();
/*MT6256RF*/    #if IS_CHIP_MT6256_S00
/*MT6256RF*/    HWRITE_1_SDATA( SCTRL_AGC,      l1d_rf.AGC_data );  /* CW96: set gain */
/*MT6256RF*/    #else
/*MT6256RF*/    HWRITE_2_SDATA( SCTRL_AGC,      l1d_rf.AGC_data,    /* CW96: set gain */
/*MT6256RF*/                    SCTRL_RESERVED, 0               );
/*MT6256RF*/    #endif
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_SR3( void )
/*MT6256RF*/ {
/*MT6256RF*/    SETUP_SR3();
/*MT6256RF*/    #if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF
/*MT6256RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6256RF*/    {
/*MT6256RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );  /* CW2: set mode = stand-by mode */
/*MT6256RF*/    }
/*MT6256RF*/    else
/*MT6256RF*/    #endif
/*MT6256RF*/    {
/*MT6256RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );                      /* CW2: set mode = sleep mode */
/*MT6256RF*/    }
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_ST0( void )
/*MT6256RF*/ {
/*MT6256RF*/    #if IS_CHIP_MT6256_S00
/*MT6256RF*/    SETUP_ST0();
/*MT6256RF*/
/*MT6256RF*/    HWRITE_3_SDATA( SCTRL_STANDBY,  l1d_rf.IFN_data,                         /* CW2: set mode = standby */
/*MT6256RF*/                    SCTRL_DCXO,     BSI_CW(0x39, l1d_rf.AFC_data&0x1FFF),    /* CW57: set AFC DAC */
/*MT6256RF*/                    SCTRL_RESERVED, 0                                     );
/*MT6256RF*/    #else
/*MT6256RF*/    unsigned long cw2  = l1d_rf.IFN_data;
/*MT6256RF*/    SETUP_ST0();
/*MT6256RF*/
/*MT6256RF*/    if( (l1d_rf.RFN_data&0x3FF) || (l1d_rf.IFN_data&0x1FFF) )
/*MT6256RF*/    { /*Do nothing*/ }
/*MT6256RF*/    else
/*MT6256RF*/    {  cw2 |= (0x1<<6);  }
/*MT6256RF*/
/*MT6256RF*/    HWRITE_3_SDATA( SCTRL_HWTC,    SDATA_HWTC,                             /* CW63: set TC gain for freq. error compensation */
/*MT6256RF*/                    SCTRL_STANDBY, cw2,                                    /* CW2: set mode = standby */
/*MT6256RF*/                    SCTRL_DCXO,    BSI_CW(0x39, l1d_rf.AFC_data&0x1FFF) ); /* CW57: set AFC DAC */
/*MT6256RF*/    #endif
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_ST1( void )
/*MT6256RF*/ {
/*MT6256RF*/    SETUP_ST1();
/*MT6256RF*/    HWRITE_1_SDATA( SCTRL_PLL,      l1d_rf.RFN_data );  /* CW1: set PLL, RF will enter warmup state */
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_ST2( void )
/*MT6256RF*/ {
/*MT6256RF*/    SETUP_ST2();
/*MT6256RF*/    #if IS_CHIP_MT6256_S00
/*MT6256RF*/    HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*MT6256RF*/    #else
/*MT6256RF*/    HWRITE_2_SDATA( SCTRL_RESERVED, 0,
/*MT6256RF*/                    SCTRL_RESERVED, 0 );
/*MT6256RF*/    #endif
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_ST3( void )
/*MT6256RF*/ {
/*MT6256RF*/    SETUP_ST3();
/*MT6256RF*/    #if IS_RF_VCO_PARTIAL_DOO_ON
/*MT6256RF*/    if( l1d_rf2.dedicated_flag & SC_DEDICATED_2TX )
/*MT6256RF*/    {
/*MT6256RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );  /* CW2: set mode = stand-by mode */
/*MT6256RF*/    }
/*MT6256RF*/    else
/*MT6256RF*/    #elif IS_RF_VCO_DOO_OFF
/*MT6256RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6256RF*/    {
/*MT6256RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );  /* CW2: set mode = stand-by mode */
/*MT6256RF*/    }
/*MT6256RF*/    else
/*MT6256RF*/    #endif
/*MT6256RF*/    {
/*MT6256RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );                      /* CW2: set mode = sleep mode */
/*MT6256RF*/    }
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6256RF*/ {
/*MT6256RF*/    #if IS_CHIP_MT6256_S00
/*MT6256RF*/    unsigned long cw133;
/*MT6256RF*/    SETUP_ST2B_ST2M();
/*MT6256RF*/    cw133 = L1D_RF_GetSData_ST2();
/*MT6256RF*/    HWRITE_1_SDATA( SCTRL_TXCW,  cw133 );  /* CW133: set TX gain */
/*MT6256RF*/    #else
/*MT6256RF*/    unsigned long cw133;
/*MT6256RF*/    SETUP_ST2B_ST2M();
/*MT6256RF*/    cw133 = L1D_RF_GetSData_ST2();
/*MT6256RF*/    if( (l1d_rf.RFN_data&0x3FF) || (l1d_rf.IFN_data&0x1FFF) )
/*MT6256RF*/    {  HWRITE_2_SDATA( SCTRL_TXCW,     cw133,    /* CW133: set TX gain */
/*MT6256RF*/                       SCTRL_RESERVED, 0     );
/*MT6256RF*/    }
/*MT6256RF*/    else
/*MT6256RF*/    {  HWRITE_2_SDATA( SCTRL_TXCW, cw133,                                         /* CW133: set TX gain */
/*MT6256RF*/                       SCTRL_WARM, (l1d_rf.IFN_data & ~(0x7<<13)) | (0x4<<13) );  /* CW2: Restore NFrac, set mode = warm-up mode for int channel */
/*MT6256RF*/    }
/*MT6256RF*/    #endif
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6256RF*/ {
/*MT6256RF*/    #if IS_CHIP_MT6256_S00
/*MT6256RF*/    unsigned long cw133;
/*MT6256RF*/    SETUP_ST2B_ST2M();
/*MT6256RF*/    cw133 = L1D_RF_GetSData_ST2();
/*MT6256RF*/    HWRITE_1_SDATA( SCTRL_TXCW,  cw133 );  /* CW133: set TX gain */
/*MT6256RF*/    #else
/*MT6256RF*/    unsigned long cw133;
/*MT6256RF*/    SETUP_ST2B_ST2M();
/*MT6256RF*/    cw133 = L1D_RF_GetSData_ST2();
/*MT6256RF*/    HWRITE_2_SDATA( SCTRL_TXCW,     cw133,   /* CW133: set TX gain */
/*MT6256RF*/                    SCTRL_RESERVED, 0     );
/*MT6256RF*/    #endif
/*MT6256RF*/ }
/*MT6256RF*/
#endif

#if IS_RF_MT6255RF
/*MT6255RF*/
/*MT6255RF*/ /*..........................................................*/
/*MT6255RF*/ /*  Define Alias and Table                                  */
/*MT6255RF*/ /*..........................................................*/
/*MT6255RF*/
/*MT6255RF*/ #define  SCTRL_STANDBY                 SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SCTRL_WARM                    SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SCTRL_PLL                     SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SCTRL_DCXO                    SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SCTRL_AGC                     SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SCTRL_TXCW                    SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SCTRL_RXCW                    SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SDATA_SLEEP                   BSI_CW(0x02, 0x10000)
/*MT6255RF*/ #define  SDATA_STANDBY                 BSI_CW(0x02, 0x44000)
/*MT6255RF*/
/*MT6255RF*/ #if IS_DYNAMIC_TC_GAIN_SUPPORT
/*MT6255RF*/ #define  SCTRL_HWTC                    SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SDATA_HWTC                    L1D_RF_Get_TC_Gain_CW()
/*MT6255RF*/ #else
/*MT6255RF*/ #define  SCTRL_HWTC                    SCTRL_RESERVED
/*MT6255RF*/ #define  SDATA_HWTC                    0
/*MT6255RF*/ #endif
/*MT6255RF*/
/*MT6255RF*/ /*..........................................................*/
/*MT6255RF*/ /* Serial Interface Implement                               */
/*MT6255RF*/ /*..........................................................*/
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_SR0( void )
/*MT6255RF*/ {
/*MT6255RF*/    unsigned long cw57, cw98;
/*MT6255RF*/    SETUP_SR0();
/*MT6255RF*/    cw57 = BSI_CW( 0x39, (L1D_RF_Check_DCXO_LPM()&0x1FFF) );
/*MT6255RF*/    cw98 = l1d_rf.band < FrequencyBand1800 ? BSI_CW(0x62, 0x5066A) : BSI_CW(0x62, 0x5065A);
/*MT6255RF*/
/*MT6255RF*/    HWRITE_3_SDATA( SCTRL_RXCW,     cw98,                 /* CW98: for RX LNA bias current */
/*MT6255RF*/                    SCTRL_STANDBY,  l1d_rf.IFN_data,      /* CW2:  set mode = standby */
/*MT6255RF*/                    SCTRL_DCXO,     cw57 );               /* CW57: set AFC DAC */
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_SR1( void )
/*MT6255RF*/ {
/*MT6255RF*/    SETUP_SR1();
/*MT6255RF*/    HWRITE_1_SDATA( SCTRL_PLL,      l1d_rf.RFN_data );  /* CW1: set PLL, RF will enter warmup state */
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_SR2( void )
/*MT6255RF*/ {
/*MT6255RF*/    SETUP_SR2();
/*MT6255RF*/    HWRITE_2_SDATA( SCTRL_AGC,      l1d_rf.AGC_data,    /* CW96: set gain */
/*MT6255RF*/                    SCTRL_RESERVED, 0               );
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_SR3( void )
/*MT6255RF*/ {
/*MT6255RF*/    SETUP_SR3();
/*MT6255RF*/
/*MT6255RF*/ #if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF
/*MT6255RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6255RF*/    {
/*MT6255RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );  /* CW2: set mode = stand-by mode */
/*MT6255RF*/    }
/*MT6255RF*/    else
/*MT6255RF*/ #endif
/*MT6255RF*/    {
/*MT6255RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );                      /* CW2: set mode = sleep mode */
/*MT6255RF*/    }
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_ST0( void )
/*MT6255RF*/ {
/*MT6255RF*/    unsigned long cw2  = l1d_rf.IFN_data;
/*MT6255RF*/
/*MT6255RF*/    SETUP_ST0();
/*MT6255RF*/
/*MT6255RF*/    if( (l1d_rf.RFN_data&0x3FF) || (l1d_rf.IFN_data&0x1FFF) )
/*MT6255RF*/    {  /*Do nothing*/  }
/*MT6255RF*/    else
/*MT6255RF*/    {  cw2 |= (0x1<<7);  }
/*MT6255RF*/
/*MT6255RF*/    HWRITE_3_SDATA( SCTRL_HWTC,    SDATA_HWTC,                             /* CW63: set TC gain for freq. error compensation */
/*MT6255RF*/                    SCTRL_STANDBY, cw2,                                    /* CW2:  set mode = standby */
/*MT6255RF*/                    SCTRL_DCXO,    BSI_CW(0x39, l1d_rf.AFC_data&0x1FFF) ); /* CW57: set AFC DAC */
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_ST1( void )
/*MT6255RF*/ {
/*MT6255RF*/    SETUP_ST1();
/*MT6255RF*/    HWRITE_1_SDATA( SCTRL_PLL,     l1d_rf.RFN_data );                      /* CW1: set PLL, RF will enter warmup state */
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_ST2( void )
/*MT6255RF*/ {
/*MT6255RF*/    SETUP_ST2();
/*MT6255RF*/    HWRITE_2_SDATA( SCTRL_RESERVED, 0,
/*MT6255RF*/                    SCTRL_RESERVED, 0 );
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_ST3( void )
/*MT6255RF*/ {
/*MT6255RF*/    SETUP_ST3();
/*MT6255RF*/
/*MT6255RF*/ #if IS_RF_VCO_PARTIAL_DOO_ON
/*MT6255RF*/    if( l1d_rf2.dedicated_flag & SC_DEDICATED_2TX )
/*MT6255RF*/    {
/*MT6255RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );      /* CW2: set mode = stand-by mode */
/*MT6255RF*/    }
/*MT6255RF*/    else
/*MT6255RF*/ #elif IS_RF_VCO_DOO_OFF
/*MT6255RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6255RF*/    {
/*MT6255RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );      /* CW2: set mode = stand-by mode */
/*MT6255RF*/    }
/*MT6255RF*/    else
/*MT6255RF*/ #endif
/*MT6255RF*/    {
/*MT6255RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );                          /* CW2: set mode = sleep mode */
/*MT6255RF*/    }
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6255RF*/ {
/*MT6255RF*/    SETUP_ST2B_ST2M();
/*MT6255RF*/
/*MT6255RF*/    if( (l1d_rf.RFN_data&0x3FF) || (l1d_rf.IFN_data&0x1FFF) )
/*MT6255RF*/    {  HWRITE_2_SDATA( SCTRL_TXCW,     BSI_CW(0x85, 0x00003),              /* CW133: Trigger RF to enter TX mode */
/*MT6255RF*/                       SCTRL_RESERVED, 0     );
/*MT6255RF*/    }
/*MT6255RF*/    else
/*MT6255RF*/    {  HWRITE_2_SDATA( SCTRL_TXCW,     BSI_CW(0x85, 0x00003),              /* CW133: Trigger RF to enter TX mode */
/*MT6255RF*/                       SCTRL_WARM,     (l1d_rf.IFN_data & ~(0x7<<13)) | (0x4<<13) );  /* CW2: Restore NFrac, set mode = Tx mode for int channel */
/*MT6255RF*/    }
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6255RF*/ {
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#if IS_RF_MT6251RF
/*MT6251RF*/
/*MT6251RF*/ /*..........................................................*/
/*MT6251RF*/ /*  Define Alias and Table                                  */
/*MT6251RF*/ /*..........................................................*/
/*MT6251RF*/
/*MT6251RF*/ #define  SCTRL_STANDBY                 SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_WARM                    SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_PLL                     SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_DCXO                    SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_AGC                     SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_TXBAND                  SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_TXCW                    SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_TXDCOC                  SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_CAPID                   SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_RFVCO_K                 SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SDATA_SLEEP                   0x0210000L
/*MT6251RF*/ #define  SDATA_STANDBY                 0x0244000L
/*MT6251RF*/ #define  SDATA_SLIGHT_STANDBY          0x0284000L
/*MT6251RF*/
/*MT6251RF*/ #if IS_RF_TX_SLEEP_MODE_SUPPORT
/*MT6251RF*/ #undef   SDATA_STANDBY
/*MT6251RF*/ #define  SDATA_STANDBY                 SDATA_SLIGHT_STANDBY
/*MT6251RF*/ #endif
/*MT6251RF*/
/*MT6251RF*/ #define  SCTRL_CW66                    SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_CW27                    SCTRL_RESERVED
/*MT6251RF*/
/*MT6251RF*/ /*..........................................................*/
/*MT6251RF*/ /* Serial Interface Implement                               */
/*MT6251RF*/ /*..........................................................*/
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_SR0( void )
/*MT6251RF*/ {
/*MT6251RF*/    SETUP_SR0();
/*MT6251RF*/    HWRITE_2_SDATA( SCTRL_STANDBY,  l1d_rf.IFN_data,                             /* CW2:  set mode = stan*/
/*MT6251RF*/                    SCTRL_DCXO,    (l1d_rf.AFC_data & 0x1FFF) | (0x3900000L) );  /* CW57: set AFC DAC */
/*MT6251RF*/
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_SR1( void )
/*MT6251RF*/ {
/*MT6251RF*/    SETUP_SR1();
/*MT6251RF*/    HWRITE_1_SDATA( SCTRL_PLL,      l1d_rf.RFN_data );  /* CW1: set PLL, RF will enter warmup state */
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_SR2( void )
/*MT6251RF*/ {
/*MT6251RF*/    SETUP_SR2();
/*MT6251RF*/    HWRITE_1_SDATA( SCTRL_AGC,      l1d_rf.AGC_data );  /* CW96: set gain and enter RX mode */
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_SR3( void )
/*MT6251RF*/ {
/*MT6251RF*/    SETUP_SR3();
/*MT6251RF*/    #if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF
/*MT6251RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6251RF*/    {
/*MT6251RF*/       HWRITE_2_SDATA( SCTRL_IDLE, SDATA_SLEEP,
/*MT6251RF*/                       SCTRL_IDLE, ( l1d_rf.IFN_data & ~(0x00CE000L) ) | SDATA_STANDBY );   /* CW2: set mode = stand-by mode */
/*MT6251RF*/    }
/*MT6251RF*/    else
/*MT6251RF*/    #endif
/*MT6251RF*/    {
/*MT6251RF*/       HWRITE_2_SDATA( SCTRL_IDLE, SDATA_SLEEP,
/*MT6251RF*/                       SCTRL_RESERVED, 0 );   /* CW2: set mode = sleep mode */
/*MT6251RF*/    }
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_ST0( void )
/*MT6251RF*/ {
/*MT6251RF*/    unsigned long cw2 = l1d_rf.IFN_data;
/*MT6251RF*/
/*MT6251RF*/    SETUP_ST0();
/*MT6251RF*/
/*MT6251RF*/    if( (l1d_rf.RFN_data&0x3FF) || (l1d_rf.IFN_data&0xFFF) )
/*MT6251RF*/    {  /*None*/   }  /* The same as in SDATA_TABLE2 */
/*MT6251RF*/    else
/*MT6251RF*/    {  cw2 |= (1<<6);   }  /* If Nfrac[22:0]==0 */
/*MT6251RF*/
/*MT6251RF*/    HWRITE_2_SDATA( SCTRL_STANDBY, cw2,                                        /* CW2:  set mode = standby */
/*MT6251RF*/                    SCTRL_DCXO, (l1d_rf.AFC_data & 0x1FFF) | (0x3900000L) );   /* CW57: set AFC DAC */
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_ST1( void )
/*MT6251RF*/ {
/*MT6251RF*/    SETUP_ST1();
/*MT6251RF*/    HWRITE_1_SDATA( SCTRL_PLL, l1d_rf.RFN_data );  /* CW1: set PLL, RF will enter warmup state */
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_ST2( void )
/*MT6251RF*/ {
/*MT6251RF*/    SETUP_ST2();
   #if IS_CHIP_MT6251_S00
/*MT6251RF*/    HWRITE_1_SDATA( SCTRL_TXCW, 0x8500000L );
   #else
/*MT6251RF*/    HWRITE_1_SDATA( SCTRL_TXCW, 0x8580000L );   /*send CW133 to enter TX mode,[101231] 0x8580000*/
   #endif
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_ST3( void )
/*MT6251RF*/ {
/*MT6251RF*/    SETUP_ST3();
/*MT6251RF*/    #if IS_RF_VCO_PARTIAL_DOO_ON
/*MT6251RF*/    if( l1d_rf2.dedicated_flag & SC_DEDICATED_2TX )
/*MT6251RF*/    {
/*MT6251RF*/       HWRITE_2_SDATA( SCTRL_IDLE, ( l1d_rf.IFN_data & ~(0x00CE000L) ) | SDATA_STANDBY,
/*MT6251RF*/                       SCTRL_RESERVED, 0 );   /* CW2: set mode = stand-by mode */
/*MT6251RF*/    }
/*MT6251RF*/    else
/*MT6251RF*/    #elif IS_RF_VCO_DOO_OFF
/*MT6251RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6251RF*/    {
/*MT6251RF*/       HWRITE_2_SDATA( SCTRL_IDLE, ( l1d_rf.IFN_data & ~(0x00CE000L) ) | SDATA_STANDBY,
/*MT6251RF*/                       SCTRL_RESERVED, 0 );   /* CW2: set mode = stand-by mode */
/*MT6251RF*/    }
/*MT6251RF*/    else
/*MT6251RF*/    #endif
/*MT6251RF*/    {
/*MT6251RF*/       HWRITE_2_SDATA( SCTRL_IDLE, SDATA_SLEEP,
/*MT6251RF*/                       SCTRL_RESERVED, 0 );   /* CW2: set mode = sleep mode */
/*MT6251RF*/    }
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6251RF*/ {
/*MT6251RF*/    SETUP_ST2B_ST2M();
/*MT6251RF*/    if( (l1d_rf.RFN_data&0x3FF) || (l1d_rf.IFN_data&0xFFF) )
/*MT6251RF*/    {  HWRITE_1_SDATA( SCTRL_RESERVED, 0 );  }
/*MT6251RF*/    else
/*MT6251RF*/    {  HWRITE_1_SDATA( SCTRL_TXCW, (l1d_rf.IFN_data & ~(0x7<<13)) | (0x4<<13) );  }  /* If Nfrac[22:0]==0 */
/*MT6251RF*/
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6251RF*/ {
/*MT6251RF*/ }
/*MT6251RF*/
#endif

#if IS_RF_SKY74045
/*SKY74045*/
/*SKY74045*/ /*..........................................................*/
/*SKY74045*/ /*  Define Alias and Table                                  */
/*SKY74045*/ /*..........................................................*/
/*SKY74045*/
/*SKY74045*/ #define  SCTRL_SXR1                   SCTRL_WORD(0,24)
/*SKY74045*/ #define  SCTRL_SXR2                   SCTRL_WORD(0,24)
/*SKY74045*/ #define  SCTRL_RTXCTRL                SCTRL_WORD(0,24)
/*SKY74045*/ #define  SCTRL_IP2_COEF               SCTRL_WORD(0,24)
/*SKY74045*/
/*SKY74045*/ const unsigned long SDATA_TX_TABLE[5][2] =
/*SKY74045*/ {
/*SKY74045*/    /*for SKY version2*/{        0L,       0L }, //{        0L,       0L },  /* FrequencyBand400 (not support)  */
/*SKY74045*/    /*for SKY version2*/{ 0x404043L,0x404043L }, //{ 0x404043L,0x404043L },  /* FrequencyBand850                */
/*SKY74045*/    /*for SKY version2*/{ 0x404043L,0x404043L }, //{ 0x304043L,0x204043L },  /* FrequencyBand900                */
/*SKY74045*/    /*for SKY version2*/{ 0x788043L,0x788043L }, //{ 0x688043L,0x688043L },  /* FrequencyBand1800               */
/*SKY74045*/    /*for SKY version2*/{ 0x68C043L,0x58C043L }, //{ 0x58C043L,0x48C043L },  /* FrequencyBand1900               */
/*SKY74045*/ };
/*SKY74045*/
/*SKY74045*/ unsigned long SKY_TR3[5][2] =
/*SKY74045*/ {
/*SKY74045*/    {        0L,       0L },  /* FrequencyBand400 (not support)  */
/*SKY74045*/    { 0x3000CDL,0x30008DL },  /* FrequencyBand850                */
/*SKY74045*/    { 0x3000CDL,0x30008DL },  /* FrequencyBand900                */
/*SKY74045*/    { 0x3000CDL,0x30008DL },  /* FrequencyBand1800               */
/*SKY74045*/    { 0x3000CDL,0x30008DL },  /* FrequencyBand1900               */
/*SKY74045*/ };
/*SKY74045*/
/*SKY74045*/ unsigned long SKY_BAND[5] =
/*SKY74045*/ {
/*SKY74045*/           0L,/* FrequencyBand400 (not support)  */
/*SKY74045*/    0x004003L,/* FrequencyBand850                */
/*SKY74045*/    0x004003L,/* FrequencyBand900                */
/*SKY74045*/    0x008003L,/* FrequencyBand1800               */
/*SKY74045*/    0x00C003L,/* FrequencyBand1900               */
/*SKY74045*/ };
/*SKY74045*/
/*SKY74045*/ /*..........................................................*/
/*SKY74045*/ /* Serial Interface Implement                               */
/*SKY74045*/ /*..........................................................*/
/*SKY74045*/
/*SKY74045*/ #if IS_BSI_SX0_SUPPORT
/*SKY74045*/ void  L1D_RF_SetSData_SR0( void )
/*SKY74045*/ {
/*SKY74045*/ }
/*SKY74045*/ #endif
/*SKY74045*/
/*SKY74045*/ void  L1D_RF_SetSData_SR1( void )
/*SKY74045*/ {
/*SKY74045*/    SETUP_SR1();
/*SKY74045*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*SKY74045*/    HWRITE_5_SDATA( SCTRL_SXR1,     l1d_rf.RFN_data,
/*SKY74045*/                    SCTRL_SXR2,     l1d_rf.IFN_data,
/*SKY74045*/                    SCTRL_RTXCTRL,  SKY_BAND[l1d_rf.band],
/*SKY74045*/                    SCTRL_IP2_COEF, (SKY_TR3[l1d_rf.band][0] + (RFSpecialCoef.rx.skyip2.data[l1d_rf.band].icorrection<<8)),
/*SKY74045*/                    SCTRL_IP2_COEF, (SKY_TR3[l1d_rf.band][1] + (RFSpecialCoef.rx.skyip2.data[l1d_rf.band].qcorrection<<8)));
/*SKY74045*/ #else
/*SKY74045*/    HWRITE_2_SDATA( SCTRL_SXR1,     l1d_rf.RFN_data,
/*SKY74045*/                    SCTRL_SXR2,     l1d_rf.IFN_data );
/*SKY74045*/ #endif
/*SKY74045*/ }
/*SKY74045*/
/*SKY74045*/ void  L1D_RF_SetSData_SR2( void )
/*SKY74045*/ {
/*SKY74045*/    SETUP_SR2();
/*SKY74045*/    HWRITE_1_SDATA( SCTRL_RTXCTRL,  l1d_rf.AGC_data );
/*SKY74045*/ }
/*SKY74045*/
/*SKY74045*/ void  L1D_RF_SetSData_SR3( void )
/*SKY74045*/ {
/*SKY74045*/ }
/*SKY74045*/
/*SKY74045*/ #if IS_BSI_SX0_SUPPORT
/*SKY74045*/ void  L1D_RF_SetSData_ST0( void )
/*SKY74045*/ {
/*SKY74045*/ }
/*SKY74045*/ #endif
/*SKY74045*/
/*SKY74045*/ void  L1D_RF_SetSData_ST1( void )
/*SKY74045*/ {
/*SKY74045*/    extern char SKY_d_flag;
/*SKY74045*/    extern char SKY_TXCP;
/*SKY74045*/    SETUP_ST1();
/*SKY74045*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*SKY74045*/    HWRITE_5_SDATA( SCTRL_RTXCTRL, (SDATA_TX_TABLE[l1d_rf.band][SKY_TXCP] | (SKY_d_flag<<16)),
/*SKY74045*/                    SCTRL_SXR1,     l1d_rf.RFN_data,
/*SKY74045*/                    SCTRL_RESERVED,               0,
/*SKY74045*/                    SCTRL_RESERVED,               0,
/*SKY74045*/                    SCTRL_RESERVED,               0 );
/*SKY74045*/ #else
/*SKY74045*/    HWRITE_2_SDATA( SCTRL_RTXCTRL, (SDATA_TX_TABLE[l1d_rf.band][SKY_TXCP] | (SKY_d_flag<<16)),
/*SKY74045*/                    SCTRL_SXR1,     l1d_rf.RFN_data  );
/*SKY74045*/ #endif
/*SKY74045*/ }
/*SKY74045*/
/*SKY74045*/ void  L1D_RF_SetSData_ST2( void )
/*SKY74045*/ {
/*SKY74045*/    SETUP_ST2();
/*SKY74045*/    HWRITE_1_SDATA( SCTRL_SXR2,     l1d_rf.IFN_data );
/*SKY74045*/ }
/*SKY74045*/
/*SKY74045*/ void  L1D_RF_SetSData_ST3( void )
/*SKY74045*/ {
/*SKY74045*/ }
/*SKY74045*/
/*SKY74045*/ void  L1D_RF_SetSData_ST2B( void )
/*SKY74045*/ {
/*SKY74045*/ }
/*SKY74045*/
/*SKY74045*/ void  L1D_RF_SetSData_ST2M( void )
/*SKY74045*/ {
/*SKY74045*/ }
/*SKY74045*/
#endif

#if IS_RF_AERO2
/*AERO2*/
/*AERO2*/ /*..........................................................*/
/*AERO2*/ /*  Define Alias and Table                                  */
/*AERO2*/ /*..........................................................*/
/*AERO2*/
/*AERO2*/ #define  SCTRL_PLL                   SCTRL_WORD(0,21)
/*AERO2*/ #define  SCTRL_GAIN                  SCTRL_WORD(0,21)
/*AERO2*/
/*AERO2*/ const unsigned long TX_SETUP[5]=
/*AERO2*/ {  (0x0000<<6) | 0x23,     //450
/*AERO2*/    (0x000D<<6) | 0x23,     //850
/*AERO2*/    (0x01B0<<6) | 0x23,     //900
/*AERO2*/    (0x01D0<<6) | 0x23,     //1800
/*AERO2*/    (0x0193<<6) | 0x23,     //1900
/*AERO2*/ };
/*AERO2*/
/*AERO2*/ const unsigned long RX_LNASWAP[2] =
/*AERO2*/ {
/*AERO2*/ #ifdef RF_AERO2_4209
/*AERO2*/    (0x2E9A<<6) | 0x05,     //ALL band swap,    [900->850],                       ,[1800->1900]
/*AERO2*/    (0x2E98<<6) | 0x05,     //ALL band not swap,[850->850],                       ,[1900->1900]
/*AERO2*/ #else
/*AERO2*/    (0x2E98<<6) | 0x05,     //ALL band not swap, 850->850 ,[900->900],[1800->1800], 1900->1900
/*AERO2*/    (0x2E9A<<6) | 0x05,     //ALL band swap,     900->850 ,[850->900],[1900->1800], 1800->1900
/*AERO2*/ #endif
/*AERO2*/ };
/*AERO2*/
/*AERO2*/ /*..........................................................*/
/*AERO2*/ /* Serial Interface Implement                               */
/*AERO2*/ /*..........................................................*/
/*AERO2*/
/*AERO2*/ void  L1D_RF_SetSData_SR1( void )
/*AERO2*/ {  unsigned short on=0;
/*AERO2*/
/*AERO2*/    SETUP_SR1();
/*AERO2*/    if((l1d_rf.band-1)&0x2) // 0:400, 1:850, 2:900, 3:1800, 4:1900
/*AERO2*/       on = BBTXParameters.bbrx_dcs1800_pcs1900_swap & 0x1;
/*AERO2*/    else
/*AERO2*/       on = BBTXParameters.bbrx_gsm850_gsm900_swap   & 0x1;
/*AERO2*/
/*AERO2*/    HWRITE_3_SDATA( SCTRL_PLL, l1d_rf.RFN_data,
/*AERO2*/                    SCTRL_PLL, RX_LNASWAP[on],
/*AERO2*/                    SCTRL_PLL, ((l1d_rf.AFC_data&0x1FFF)<<6)|0x22 );
/*AERO2*/ }
/*AERO2*/
/*AERO2*/ void  L1D_RF_SetSData_SR2( void )
/*AERO2*/ {
/*AERO2*/    SETUP_SR2();
/*AERO2*/    HWRITE_1_SDATA( SCTRL_GAIN, l1d_rf.AGC_data );
/*AERO2*/ }
/*AERO2*/
/*AERO2*/ void  L1D_RF_SetSData_SR3( void )
/*AERO2*/ {
/*AERO2*/ }
/*AERO2*/
/*AERO2*/ void  L1D_RF_SetSData_ST1( void )
/*AERO2*/ {
/*AERO2*/    SETUP_ST1();
/*AERO2*/    HWRITE_3_SDATA( SCTRL_PLL, l1d_rf.RFN_data,
/*AERO2*/                    SCTRL_PLL, TX_SETUP[l1d_rf.band],
/*AERO2*/                    SCTRL_PLL, ((l1d_rf.AFC_data&0x1FFF)<<6)|0x22 );
/*AERO2*/ }
/*AERO2*/
/*AERO2*/ void  L1D_RF_SetSData_ST2( void )
/*AERO2*/ {
/*AERO2*/    SETUP_ST2();
/*AERO2*/    HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*AERO2*/ }
/*AERO2*/
/*AERO2*/ void  L1D_RF_SetSData_ST3( void )
/*AERO2*/ {
/*AERO2*/ }
/*AERO2*/
#endif

#if IS_RF_SKY74137
/*SKY74137*/
/*SKY74137*/ /*..........................................................*/
/*SKY74137*/ /*  Define Alias and Table                                  */
/*SKY74137*/ /*..........................................................*/
/*SKY74137*/
/*SKY74137*/ #define  SCTRL_SXR1                   SCTRL_WORD(0,24)
/*SKY74137*/ #define  SCTRL_SXR2                   SCTRL_WORD(0,24)
/*SKY74137*/ #define  SCTRL_RTXCTRL                SCTRL_WORD(0,24)
/*SKY74137*/
/*SKY74137*/
/*SKY74137*/ unsigned long SKY_AM_LOOP_GAIN[5] =
/*SKY74137*/ {
/*SKY74137*/           0L, /* FrequencyBand400 (not support)  */
/*SKY74137*/    0x180000L, /* FrequencyBand850                */
/*SKY74137*/    0x180000L, /* FrequencyBand900                */
/*SKY74137*/    0x180000L, /* FrequencyBand1800               */
/*SKY74137*/    0x180000L, /* FrequencyBand1900               */
/*SKY74137*/ };
/*SKY74137*/
/*SKY74137*/ unsigned long SKY_BAND_CP_CURRENT[5] =
/*SKY74137*/ {
/*SKY74137*/           0L, /* FrequencyBand400 (not support)  */
/*SKY74137*/    0xAC0004L, /* FrequencyBand850                */
/*SKY74137*/    0xAC4004L, /* FrequencyBand900                */
/*SKY74137*/    0xB08004L, /* FrequencyBand1800               */
/*SKY74137*/    0xB0C004L, /* FrequencyBand1900               */
/*SKY74137*/ };
/*SKY74137*/
/*SKY74137*/ /*..........................................................*/
/*SKY74137*/ /* Serial Interface Implement                               */
/*SKY74137*/ /*..........................................................*/
/*SKY74137*/
/*SKY74137*/ void  L1D_RF_SetSData_SR1( void )
/*SKY74137*/ {
/*SKY74137*/    SETUP_SR1();
/*SKY74137*/    HWRITE_2_SDATA( SCTRL_SXR2,     l1d_rf.IFN_data,
/*SKY74137*/                    SCTRL_SXR1,     (l1d_rf.RFN_data | SKY_AM_LOOP_GAIN[l1d_rf.band]) );
/*SKY74137*/ }
/*SKY74137*/
/*SKY74137*/ void  L1D_RF_SetSData_SR2( void )
/*SKY74137*/ {
/*SKY74137*/    SETUP_SR2();
/*SKY74137*/    if(IS_CONTINUOUS_RX_SLOT() && RFSpecialCoef.rx.sky74137.fixgain_enable == 0x1)
/*SKY74137*/    {
/*SKY74137*/       HWRITE_1_SDATA( SCTRL_RESERVED,  (l1d_rf.AGC_data | SKY_BAND_CP_CURRENT[l1d_rf.band]) );
/*SKY74137*/    }
/*SKY74137*/    else
/*SKY74137*/    {
/*SKY74137*/       HWRITE_1_SDATA( SCTRL_RTXCTRL,  (l1d_rf.AGC_data | SKY_BAND_CP_CURRENT[l1d_rf.band]) );
/*SKY74137*/    }
/*SKY74137*/ }
/*SKY74137*/
/*SKY74137*/ void  L1D_RF_SetSData_SR3( void )
/*SKY74137*/ {
/*SKY74137*/ }
/*SKY74137*/
/*SKY74137*/ void  L1D_RF_SetSData_ST1( void )
/*SKY74137*/ {
/*SKY74137*/ // extern char SKY_d_flag;
/*SKY74137*/ // extern char SKY_TXCP;
/*SKY74137*/    SETUP_ST1();
/*SKY74137*/    HWRITE_2_SDATA( SCTRL_RTXCTRL,  SKY_BAND_CP_CURRENT[l1d_rf.band],
/*SKY74137*/                    SCTRL_SXR2,     l1d_rf.IFN_data  );
/*SKY74137*/ }
/*SKY74137*/
/*SKY74137*/ void  L1D_RF_SetSData_ST2( void )
/*SKY74137*/ {
/*SKY74137*/    SETUP_ST2();
/*SKY74137*/    HWRITE_1_SDATA( SCTRL_SXR1,    (l1d_rf.RFN_data | SKY_AM_LOOP_GAIN[l1d_rf.band]) );
/*SKY74137*/ }
/*SKY74137*/
/*SKY74137*/ void  L1D_RF_SetSData_ST3( void )
/*SKY74137*/ {
/*SKY74137*/ }
/*SKY74137*/
/*SKY74137*/ void  L1D_RF_SetSData_ST2B( void )
/*SKY74137*/ {
/*SKY74137*/ }
/*SKY74137*/
/*SKY74137*/ void  L1D_RF_SetSData_ST2M( void )
/*SKY74137*/ {
/*SKY74137*/ }
/*SKY74137*/
#endif

#if IS_RF_GRF6201
/*GRF6201*/
/*GRF6201*/ /*..........................................................*/
/*GRF6201*/ /*  Define Alias and Table                                  */
/*GRF6201*/ /*..........................................................*/
/*GRF6201*/
/*GRF6201*/ #define  SCTRL_PLL_BAND_MODE          SCTRL_WORD(0,24)
/*GRF6201*/ #define  SCTRL_PLL                    SCTRL_WORD(0,24)
/*GRF6201*/ #define  SCTRL_AGC                    SCTRL_WORD(0,24)
/*GRF6201*/ #define  SCTRL_TXCURMAG               SCTRL_WORD(0,24)
/*GRF6201*/ #define  SCTRL_TXRF                   SCTRL_WORD(0,24)
/*GRF6201*/
/*GRF6201*/ #define  SDATA_TXCURMAG               (0xC62388 | ((l1d_rf.IFN_data&0x3000000L)>> 4))  //08h
/*GRF6201*/ #define  SDATA_TXRF                   (0x600010 | ((l1d_rf.IFN_data&0x4000000L)>>12))  //10h
/*GRF6201*/
/*GRF6201*/ /*..........................................................*/
/*GRF6201*/ /* Serial Interface Implement                               */
/*GRF6201*/ /*..........................................................*/
/*GRF6201*/
/*GRF6201*/ void  L1D_RF_SetSData_SR1( void )
/*GRF6201*/ {
/*GRF6201*/    SETUP_SR1();
/*GRF6201*/    HWRITE_3_SDATA( SCTRL_PLL_BAND_MODE, l1d_rf.RFN_data, //00h
/*GRF6201*/                    SCTRL_PLL,           l1d_rf.IFN_data, //01h
/*GRF6201*/                    SCTRL_RESERVED,      0 );
/*GRF6201*/ }
/*GRF6201*/
/*GRF6201*/ void  L1D_RF_SetSData_SR2( void )
/*GRF6201*/ {
/*GRF6201*/    SETUP_SR2();
/*GRF6201*/    HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data );   //02h
/*GRF6201*/ }
/*GRF6201*/
/*GRF6201*/ void  L1D_RF_SetSData_SR3( void )
/*GRF6201*/ {
/*GRF6201*/    SETUP_SR3();
/*GRF6201*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );       //00h
/*GRF6201*/ }
/*GRF6201*/
/*GRF6201*/ void  L1D_RF_SetSData_ST1( void )
/*GRF6201*/ {
/*GRF6201*/    SETUP_ST1();
/*GRF6201*/    HWRITE_3_SDATA( SCTRL_TXCURMAG,      SDATA_TXCURMAG,     //08h
/*GRF6201*/                    SCTRL_PLL_BAND_MODE, l1d_rf.RFN_data,    //00h
/*GRF6201*/                    SCTRL_PLL,           l1d_rf.IFN_data );  //01h
/*GRF6201*/ }
/*GRF6201*/
/*GRF6201*/ void  L1D_RF_SetSData_ST2( void )
/*GRF6201*/ {
/*GRF6201*/    SETUP_ST2();
/*GRF6201*/    HWRITE_1_SDATA( SCTRL_TXRF, SDATA_TXRF ); //10h
/*GRF6201*/ }
/*GRF6201*/
/*GRF6201*/ void  L1D_RF_SetSData_ST3( void )
/*GRF6201*/ {
/*GRF6201*/    SETUP_ST3();
/*GRF6201*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE ); //00h
/*GRF6201*/ }
/*GRF6201*/
/*GRF6201*/ void  L1D_RF_SetSData_ST2B( void )
/*GRF6201*/ {
/*GRF6201*/ }
/*GRF6201*/
/*GRF6201*/ void  L1D_RF_SetSData_ST2M( void )
/*GRF6201*/ {
/*GRF6201*/ }
/*GRF6201*/
#endif

#if IS_RF_IRFS3001
/*IRFS3001*/
/*IRFS3001*/ /*..........................................................*/
/*IRFS3001*/ /*  Define Alias and Table                                  */
/*IRFS3001*/ /*..........................................................*/
/*IRFS3001*/
/*IRFS3001*/ #define  SCTRL_BAND           SCTRL_WORD(0,24)
/*IRFS3001*/ #define  SCTRL_PLL            SCTRL_WORD(0,24)
/*IRFS3001*/ #define  SCTRL_AGC            SCTRL_WORD(0,24)
/*IRFS3001*/ #define  SCTRL_TXGAIN         SCTRL_WORD(0,24)
/*IRFS3001*/ #define  SCTRL_MODE           SCTRL_WORD(0,24)
/*IRFS3001*/
/*IRFS3001*/ const unsigned long SDATA_BAND[5] =
/*IRFS3001*/ {   0x0L,                   /* FrequencyBand400 (not support) */
/*IRFS3001*/     ( (0xFL<<6) | 0x03 ),   /* FrequencyBand850               */
/*IRFS3001*/     ( (0x0L<<6) | 0x03 ),   /* FrequencyBand900               */
/*IRFS3001*/     ( (0x5L<<6) | 0x03 ),   /* FrequencyBand1800              */
/*IRFS3001*/     ( (0xAL<<6) | 0x03 ),   /* FrequencyBand1900              */
/*IRFS3001*/ };
/*IRFS3001*/
/*IRFS3001*/ const unsigned long SDATA_RXMODE  = ( (0x105L<<6) | 0x02 | XOUT13M_MASK );
/*IRFS3001*/ const unsigned long SDATA_TXMODE  = ( (0x103L<<6) | 0x02 | XOUT13M_MASK );
/*IRFS3001*/ const unsigned long SDATA_TXGAIN  = ( (0x800L<<6) | 0x08 );
/*IRFS3001*/
/*IRFS3001*/ /*..........................................................*/
/*IRFS3001*/ /* Serial Interface Implement                               */
/*IRFS3001*/ /*..........................................................*/
/*IRFS3001*/
/*IRFS3001*/ void  L1D_RF_SetSData_SR1( void )
/*IRFS3001*/ {
/*IRFS3001*/    SETUP_SR1();
/*IRFS3001*/    HWRITE_3_SDATA( SCTRL_BAND,  SDATA_BAND[l1d_rf.band],/* Select band        */
/*IRFS3001*/                    SCTRL_PLL,   l1d_rf.RFN_data,        /* Set Synthesizer    */
/*IRFS3001*/                    SCTRL_MODE,  SDATA_RXMODE            /* Enter Receiver Mode*/
/*IRFS3001*/                   );
/*IRFS3001*/ }
/*IRFS3001*/
/*IRFS3001*/ void  L1D_RF_SetSData_SR2( void )
/*IRFS3001*/ {
/*IRFS3001*/    SETUP_SR2();
/*IRFS3001*/    HWRITE_1_SDATA( SCTRL_AGC,    l1d_rf.AGC_data  );    // Set Rx gain
/*IRFS3001*/ }
/*IRFS3001*/
/*IRFS3001*/ void  L1D_RF_SetSData_SR3( void )
/*IRFS3001*/ {
/*IRFS3001*/    SETUP_SR3();
/*IRFS3001*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );         // Enter Power-up Mode
/*IRFS3001*/ }
/*IRFS3001*/
/*IRFS3001*/ void  L1D_RF_SetSData_ST1( void )
/*IRFS3001*/ {
/*IRFS3001*/    SETUP_ST1();
/*IRFS3001*/    HWRITE_3_SDATA( SCTRL_BAND,  SDATA_BAND[l1d_rf.band],/* Select band           */
/*IRFS3001*/                    SCTRL_PLL,   l1d_rf.RFN_data,        /* Set Synthesizer       */
/*IRFS3001*/                    SCTRL_MODE,  SDATA_TXMODE            /* Enter Transmitter Mode*/
/*IRFS3001*/                   );
/*IRFS3001*/ }
/*IRFS3001*/
/*IRFS3001*/ void  L1D_RF_SetSData_ST2( void )
/*IRFS3001*/ {
/*IRFS3001*/    SETUP_ST2();
/*IRFS3001*/    HWRITE_1_SDATA( SCTRL_TXGAIN, SDATA_TXGAIN );        // Set Tx gain
/*IRFS3001*/ }
/*IRFS3001*/
/*IRFS3001*/ void  L1D_RF_SetSData_ST3( void )
/*IRFS3001*/ {
/*IRFS3001*/    SETUP_ST3();
/*IRFS3001*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );         // Enter Power-up Mode
/*IRFS3001*/ }
/*IRFS3001*/
/*IRFS3001*/ void  L1D_RF_SetSData_ST2B( void )
/*IRFS3001*/ {
/*IRFS3001*/ }
/*IRFS3001*/
/*IRFS3001*/ void  L1D_RF_SetSData_ST2M( void )
/*IRFS3001*/ {
/*IRFS3001*/ }
#endif

#if IS_RF_AD6548
/*AD6548*/
/*AD6548*/ /*..........................................................*/
/*AD6548*/ /*  Define Alias and Table                                  */
/*AD6548*/ /*..........................................................*/
/*AD6548*/
/*AD6548*/ #define  SCTRL_WARM        SCTRL_WORD(0,24)
/*AD6548*/ #define  SCTRL_PLL         SCTRL_WORD(0,24)
/*AD6548*/ #define  SCTRL_AGC         SCTRL_WORD(0,24)
/*AD6548*/ #define  SCTRL_RXON        SCTRL_WORD(0,24)
/*AD6548*/ #define  SCTRL_TXON        SCTRL_WORD(0,24)
/*AD6548*/
/*AD6548*/ #define  SDATA_PLLTX_MASK  0x008000L
/*AD6548*/ #define  SDATA_RXON_MASK   0x000200L
/*AD6548*/ #define  SDATA_TXON_MASK   0x008400L
/*AD6548*/
/*AD6548*/ #define  LNA_SET_IDX       (((BBTXParameters.bbrx_dcs1800_pcs1900_swap&0x1)<<1)|(BBTXParameters.bbrx_gsm850_gsm900_swap&0x1))
/*AD6548*/
/*AD6548*/ const unsigned long  SDATA_WARM_BSEL[5]=
/*AD6548*/ { /*Warm*/  /*Band sel*/
/*AD6548*/    0x000184,            /*GSM 450 no support*/
/*AD6548*/    0x006184 | 0x001800, /*GSM 850*/
/*AD6548*/    0x006184 | 0x000000, /*GSM 900*/
/*AD6548*/    0x006184 | 0x000800, /*DCS 1800*/
/*AD6548*/    0x006184 | 0x001000, /*PCS 1900*/
/*AD6548*/ };
/*AD6548*/
/*AD6548*/ const unsigned short LNA_SWAP_INDEX[4][5]=
/*AD6548*/ {
/*AD6548*/    { 0, 1, 2, 3, 4 }, /*No Swap*/
/*AD6548*/    { 0, 2, 1, 3, 4 }, /*Low Band Swap*/
/*AD6548*/    { 0, 1, 2, 4, 3 }, /*High Band Swap*/
/*AD6548*/    { 0, 2, 1, 4, 3 }, /*High&Low Band Swap*/
/*AD6548*/ };
/*AD6548*/
/*AD6548*/ /*..........................................................*/
/*AD6548*/ /* Serial Interface Implement                               */
/*AD6548*/ /*..........................................................*/
/*AD6548*/
   #if IS_BSI_SX0_SUPPORT
/*AD6548*/ void  L1D_RF_SetSData_SR0( void )
/*AD6548*/ {
/*AD6548*/ }
   #endif
/*AD6548*/ void  L1D_RF_SetSData_SR1( void )
/*AD6548*/ {
/*AD6548*/    unsigned short CW_WARM_IDX = LNA_SWAP_INDEX[LNA_SET_IDX][l1d_rf.band];
/*AD6548*/    SETUP_SR1();
/*AD6548*/
/*AD6548*/    HWRITE_2_SDATA(SCTRL_WARM, SDATA_WARM_BSEL[ CW_WARM_IDX ],
/*AD6548*/                   SCTRL_PLL,  l1d_rf.RFN_data);
/*AD6548*/ }
/*AD6548*/
/*AD6548*/ void  L1D_RF_SetSData_SR2( void )
/*AD6548*/ {
/*AD6548*/    SETUP_SR2();
/*AD6548*/
/*AD6548*/    if(IS_CONTINUOUS_RX_SLOT())
/*AD6548*/    {
/*AD6548*/       HWRITE_2_SDATA( SCTRL_AGC,      l1d_rf.AGC_data,
/*AD6548*/                       SCTRL_RESERVED, 0 );
/*AD6548*/    }
/*AD6548*/    else
/*AD6548*/    {
/*AD6548*/       unsigned short CW_WARM_IDX = LNA_SWAP_INDEX[LNA_SET_IDX][l1d_rf.band];
/*AD6548*/       HWRITE_2_SDATA( SCTRL_AGC,  l1d_rf.AGC_data,
/*AD6548*/                       SCTRL_RXON, SDATA_WARM_BSEL[CW_WARM_IDX]|SDATA_RXON_MASK );
/*AD6548*/    }
/*AD6548*/ }
/*AD6548*/
/*AD6548*/ void  L1D_RF_SetSData_SR3( void )
/*AD6548*/ {
/*AD6548*/    SETUP_SR3();
/*AD6548*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*AD6548*/ }
/*AD6548*/
   #if IS_BSI_SX0_SUPPORT
/*AD6548*/ void  L1D_RF_SetSData_ST0( void )
/*AD6548*/ {
/*AD6548*/ }
   #endif
/*AD6548*/ void  L1D_RF_SetSData_ST1( void )
/*AD6548*/ {
/*AD6548*/    unsigned short CW_WARM_IDX = LNA_SWAP_INDEX[LNA_SET_IDX][l1d_rf.band];
/*AD6548*/    SETUP_ST1();
/*AD6548*/
/*AD6548*/    HWRITE_2_SDATA(SCTRL_WARM, SDATA_WARM_BSEL[CW_WARM_IDX]|SDATA_PLLTX_MASK,
/*AD6548*/                   SCTRL_PLL,  l1d_rf.RFN_data);
/*AD6548*/
/*AD6548*/    if( l1d_rf.d2c_txiqswap==0 )
/*AD6548*/    {  BFETXSET  bfetxset;
/*AD6548*/       HW_READ_BFETXSET( bfetxset );
/*AD6548*/       bfetxset.field.iqswap = (l1d_rf.band >2 ? 0 : 1)& 0x1;
/*AD6548*/       HW_WRITE_BFETXSET( bfetxset );
/*AD6548*/    }
/*AD6548*/ }
/*AD6548*/
/*AD6548*/ void  L1D_RF_SetSData_ST2( void )
/*AD6548*/ {
/*AD6548*/    unsigned short CW_WARM_IDX = LNA_SWAP_INDEX[LNA_SET_IDX][l1d_rf.band];
/*AD6548*/    SETUP_ST2();
/*AD6548*/
/*AD6548*/    HWRITE_2_SDATA( SCTRL_TXON,    SDATA_WARM_BSEL[CW_WARM_IDX]|SDATA_TXON_MASK,
/*AD6548*/                    SCTRL_RESERVED,   0 );
/*AD6548*/ }
/*AD6548*/
/*AD6548*/ void  L1D_RF_SetSData_ST3( void )
/*AD6548*/ {
/*AD6548*/    SETUP_ST3();
/*AD6548*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*AD6548*/ }
/*AD6548*/
/*AD6548*/ void  L1D_RF_SetSData_ST2B( void )
/*AD6548*/ {
/*AD6548*/ }
/*AD6548*/
/*AD6548*/ void  L1D_RF_SetSData_ST2M( void )
/*AD6548*/ {
/*AD6548*/ }
/*AD6548*/
#endif

#if IS_RF_AD6546
/*AD6546*/
/*AD6546*/ /*..........................................................*/
/*AD6546*/ /*  Define Alias and Table                                  */
/*AD6546*/ /*..........................................................*/
/*AD6546*/
/*AD6546*/ #define  SCTRL_WARM              SCTRL_WORD(0,24)
/*AD6546*/ #define  SCTRL_PLL               SCTRL_WORD(0,24)
/*AD6546*/ #define  SCTRL_AGC               SCTRL_WORD(0,24)
/*AD6546*/ #define  SCTRL_RXON              SCTRL_WORD(0,24)
/*AD6546*/ #define  SCTRL_TXON              SCTRL_WORD(0,24)
/*AD6546*/ #define  SCTRL_TESTREG           SCTRL_WORD(0,24)
/*AD6546*/ #define  SCTRL_AMLOOP            SCTRL_WORD(0,24)
/*AD6546*/ #define  SCTRL_START_PCL_CAL     SCTRL_WORD(0,24)
/*AD6546*/ #define  SCTRL_MOD_CHANGE        SCTRL_WORD(0,24)
/*AD6546*/
/*AD6546*/ #define  SDATA_PLLTX_MASK        0x008000L
/*AD6546*/ #define  SDATA_RXON_MASK         0x000200L
/*AD6546*/ #define  SDATA_TXON_MASK         0x008400L  //(((l1d_rf.tx_mod_type)&(1<<l1d_rf.rtxwin_idx))<<16))
/*AD6546*/ #define  SDATA_START_PCL_CAL    (0x020024L|(((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)<<16))  // PCL_CAL + MOD_MODE 3 wire control
/*AD6546*/ #define  SDATA_MOD8              0x010024L
/*AD6546*/ #define  SDATA_MODG              0x010044L
/*AD6546*/ #define  SDATA_AMLOOP            0x800008L //Support GMSK TX only
/*AD6546*/ //#define  SDATA_WAIT5QB           0x000024L  replaced by sending register 8 because of there maybe different gama level between slots  Vito
/*AD6546*/ //#define  SDATA_AMLOOP_CAL_DATA ((RFSpecialCoef.tx.ad6546tx.RegData[l1d_rf.band-1])<<16)
/*AD6546*/ //         AM_FB_DAC + REFDET_SLOPE_SKEW
/*AD6546*/ //#define  SDATA_AMLOOP_CAL_DATA (((RFSpecialCoef.tx.ad6546tx.CalData[l1d_rf.band-1].REFDET_SLOPE_SKEW & 0x0F)|((RFSpecialCoef.tx.ad6546tx.CalData[l1d_rf.band-1].AM_FB_DAC<<4) & 0xF0))<<16)
/*AD6546*/
/*AD6546*/ const unsigned long  SDATA_WARM_BSEL[5]=
/*AD6546*/ { /*Warm*/ /*Band sel*/
/*AD6546*/    0x000184,            /*GSM 450 no support*/
/*AD6546*/    0x006184 | 0x001800, /*GSM 850*/
/*AD6546*/    0x006184 | 0x000000, /*GSM 900*/
/*AD6546*/    0x006184 | 0x000800, /*DCS 1800*/
/*AD6546*/    0x006184 | 0x001000, /*PCS 1900*/
/*AD6546*/ };
/*AD6546*/
/*AD6546*/ //const unsigned long  SDATA_AMLOOP[5]=    // Vito, this table for default reg8 value had been writen in RF_PowerOn
/*AD6546*/ //{ /*TX AM Loop Setting*/
/*AD6546*/ //   0x000008, /*GSM 450 no support*/
/*AD6546*/ //   0x009a08, //TriQ /*GSM 850*/   /* VGA setting 9,APC cap 36.63 pF*///0x009808 SKY
/*AD6546*/ //   0x009a08, //TriQ /*GSM 900*/   /* VGA setting 9,APC cap 36.63 pF*///0x009788 SKY
/*AD6546*/ //   0x009608, //TriQ /*DCS 1800*/  /* VGA setting 9,APC cap 23.3  pF*///0x009308 SKY
/*AD6546*/ //   0x009608, //TriQ /*PCS 1900*/  /* VGA setting 9,APC cap 23.3  pF*///0x009488 SKY
/*AD6546*/ //};
/*AD6546*/
/*AD6546*/ /*const*/unsigned long  SDATA_TESTREG1[4]=
/*AD6546*/ { /*Can be used to improve phase loop TX blocker immunity at low PCL*/
/*AD6546*/    0x080F9E,//0x080c9e, /*Used in CS service*/
/*AD6546*/    0x0C1F9E,//0x081c9e//0x080c1e  /*Used in PS service*/// 1st Reg30 for Internal PM loop locking
/*AD6546*/    0x081F9E,//0x081c9e//0x080c1e  /*Used in PS service*/
/*AD6546*/    0x84001E,//Support GMSK only
/*AD6546*/ };
/*AD6546*/
/*AD6546*/ unsigned int AM_Loop_Calculate( void );
/*AD6546*/
/*AD6546*/ /*..........................................................*/
/*AD6546*/ /* Serial Interface Implement                               */
/*AD6546*/ /*..........................................................*/
/*AD6546*/
   #if IS_BSI_SX0_SUPPORT
/*AD6546*/ void  L1D_RF_SetSData_SR0( void )
/*AD6546*/ {
/*AD6546*/ }
   #endif
/*AD6546*/
/*AD6546*/ void  L1D_RF_SetSData_SR1( void )
/*AD6546*/ {
/*AD6546*/    SETUP_SR1();
/*AD6546*/    HWRITE_2_SDATA( SCTRL_WARM,    SDATA_WARM_BSEL[l1d_rf.band],
/*AD6546*/                    SCTRL_PLL,     l1d_rf.RFN_data);
/*AD6546*/ }
/*AD6546*/
   #if IS_BSI_V2_SUPPORT
/*AD6546*/ void  L1D_RF_SetSData_SR2( void )
/*AD6546*/ {
/*AD6546*/    SETUP_SR2();
/*AD6546*/
/*AD6546*/    if(IS_CONTINUOUS_RX_SLOT())
/*AD6546*/    {
/*AD6546*/       HWRITE_3_SDATA( SCTRL_AGC,    l1d_rf.AGC_data,
/*AD6546*/                       SCTRL_RESERVED,   0,
/*AD6546*/                       SCTRL_RESERVED,   0 );
/*AD6546*/    }
/*AD6546*/    else
/*AD6546*/    {
/*AD6546*/       HWRITE_3_SDATA( SCTRL_AGC,    l1d_rf.AGC_data,
/*AD6546*/                       SCTRL_RXON,    SDATA_WARM_BSEL[l1d_rf.band]|SDATA_RXON_MASK,
/*AD6546*/                       SCTRL_RESERVED,   0 );
/*AD6546*/    }
/*AD6546*/ }
   #else
/*AD6546*/ void  L1D_RF_SetSData_SR2( void )
/*AD6546*/ {
/*AD6546*/    SETUP_SR2();
/*AD6546*/
/*AD6546*/    if(IS_CONTINUOUS_RX_SLOT())
/*AD6546*/    {
/*AD6546*/       HWRITE_2_SDATA( SCTRL_AGC,    l1d_rf.AGC_data,
/*AD6546*/                       SCTRL_RESERVED,   0 );
/*AD6546*/    }
/*AD6546*/    else
/*AD6546*/    {
/*AD6546*/       HWRITE_2_SDATA( SCTRL_AGC,    l1d_rf.AGC_data,
/*AD6546*/                       SCTRL_RXON,    SDATA_WARM_BSEL[l1d_rf.band]|SDATA_RXON_MASK );
/*AD6546*/    }
/*AD6546*/ }
   #endif
/*AD6546*/
/*AD6546*/ void  L1D_RF_SetSData_SR3( void )
/*AD6546*/ {
/*AD6546*/    SETUP_SR3();
/*AD6546*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*AD6546*/ }
/*AD6546*/
   #if IS_BSI_SX0_SUPPORT
/*AD6546*/ void  L1D_RF_SetSData_ST0( void )
/*AD6546*/ {
/*AD6546*/ }
   #endif
/*AD6546*/
/*AD6546*/ void  L1D_RF_SetSData_ST1( void )
/*AD6546*/ {
/*AD6546*/    SETUP_ST1();
/*AD6546*/    HWRITE_2_SDATA( SCTRL_WARM,    SDATA_WARM_BSEL[l1d_rf.band]|SDATA_PLLTX_MASK,
/*AD6546*/                    SCTRL_PLL,     l1d_rf.RFN_data);
/*AD6546*/
/*AD6546*/    if( l1d_rf.d2c_txiqswap==0 )
/*AD6546*/    {
/*AD6546*/       L1D_BFE_SET_TxIQSwapRegister( l1d_rf.band <= FrequencyBand900 );
/*AD6546*/    }
/*AD6546*/ }
/*AD6546*/
   #if IS_BSI_V2_SUPPORT
/*AD6546*/ void  L1D_RF_SetSData_ST2( void )
/*AD6546*/ {
/*AD6546*/    SETUP_ST2();
/*AD6546*/    HWRITE_3_SDATA( SCTRL_TXON,    SDATA_WARM_BSEL[l1d_rf.band]|SDATA_TXON_MASK,
/*AD6546*/                    SCTRL_RESERVED,   0,
/*AD6546*/                    SCTRL_RESERVED,   0 );
/*AD6546*/ }
   #else
/*AD6546*/ void  L1D_RF_SetSData_ST2( void )
/*AD6546*/ {
/*AD6546*/    SETUP_ST2();
/*AD6546*/    HWRITE_2_SDATA( SCTRL_TXON,    SDATA_WARM_BSEL[l1d_rf.band]|SDATA_TXON_MASK,
/*AD6546*/                    SCTRL_RESERVED,   0 );
/*AD6546*/ }
   #endif
/*AD6546*/
/*AD6546*/ void  L1D_RF_SetSData_ST3( void )
/*AD6546*/ {
/*AD6546*/    SETUP_ST3();
/*AD6546*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*AD6546*/ }
/*AD6546*/
   #if IS_HW_DISABLE_EPSK_TX_SUPPORT
/*AD6546*/
/*AD6546*/ void  L1D_RF_SetSData_ST2B( void )
/*AD6546*/ {
/*AD6546*/    SETUP_ST2B_ST2M();
/*AD6546*/    HWRITE_3_SDATA( SCTRL_TESTREG,        SDATA_TESTREG1[3],
/*AD6546*/                    SCTRL_AMLOOP,         SDATA_AMLOOP,
/*AD6546*/                    SCTRL_START_PCL_CAL,  SDATA_START_PCL_CAL );
/*AD6546*/ }
/*AD6546*/
/*AD6546*/ void  L1D_RF_SetSData_ST2M( void )
/*AD6546*/ {
/*AD6546*/    SETUP_ST2B_ST2M();
/*AD6546*/    HWRITE_3_SDATA( SCTRL_TESTREG,        SDATA_TESTREG1[3],
/*AD6546*/                    SCTRL_AMLOOP,         SDATA_AMLOOP,
/*AD6546*/                    SCTRL_MOD_CHANGE,     SDATA_MODG );
/*AD6546*/ }
/*AD6546*/
   #else
/*AD6546*/
/*AD6546*/ void  L1D_RF_SetSData_ST2B( void )
/*AD6546*/ {
/*AD6546*/    SETUP_ST2B_ST2M();
/*AD6546*/ // AM_Loop_Calculate();   //calculate register 8 value for different PCL (gama) level
/*AD6546*/
/*AD6546*/    if((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)  // 8PSK
/*AD6546*/    {
/*AD6546*/       HWRITE_3_SDATA( SCTRL_TESTREG,        SDATA_TESTREG1[2], /*Temporary Set PS service now*/
/*AD6546*/                       SCTRL_AMLOOP,         AM_Loop_Calculate(),
/*AD6546*/                       SCTRL_START_PCL_CAL,  SDATA_START_PCL_CAL );
/*AD6546*/    }
/*AD6546*/    else  // GMSK
/*AD6546*/    {
/*AD6546*/       HWRITE_3_SDATA( SCTRL_TESTREG,        SDATA_TESTREG1[1], /*Temporary Set PS service now*/
/*AD6546*/                       SCTRL_AMLOOP,         AM_Loop_Calculate(),
/*AD6546*/                       SCTRL_START_PCL_CAL,  SDATA_START_PCL_CAL );
/*AD6546*/    }
/*AD6546*/ }
/*AD6546*/
/*AD6546*/ void  L1D_RF_SetSData_ST2M( void )
/*AD6546*/ {
/*AD6546*/    SETUP_ST2B_ST2M();
/*AD6546*/ // AM_Loop_Calculate();  //calculate register 8 value for different PCL (gama) level
/*AD6546*/
/*AD6546*/    if((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)
/*AD6546*/    {
/*AD6546*/       HWRITE_3_SDATA( SCTRL_TESTREG,      SDATA_TESTREG1[2],
/*AD6546*/                       SCTRL_AMLOOP,       AM_Loop_Calculate(),//SCTRL_MOD_CHANGE,   SDATA_WAIT5QB,
/*AD6546*/                       SCTRL_MOD_CHANGE,   SDATA_MOD8     );
/*AD6546*/    }
/*AD6546*/    else
/*AD6546*/    {
/*AD6546*/       HWRITE_3_SDATA( SCTRL_TESTREG,      SDATA_TESTREG1[1],
/*AD6546*/                       SCTRL_AMLOOP,       AM_Loop_Calculate(),//SCTRL_MOD_CHANGE,   SDATA_WAIT5QB,
/*AD6546*/                       SCTRL_MOD_CHANGE,   SDATA_MODG     );
/*AD6546*/    }
/*AD6546*/ }
/*AD6546*/
   #endif
#endif

#if IS_RF_MT6162
/*MT6162*/
/*MT6162*/ /*..........................................................*/
/*MT6162*/ /* Serial Interface Implement                               */
/*MT6162*/ /*..........................................................*/
/*MT6162*/
/*MT6162*/ #define  SCTRL_DDC_RXEN               SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_RX_BAND                SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_RX_MODE_SRX            SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_SRX_FREQ               SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_RX_MODE_RXEN           SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_RX_OFFSET              SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_RX_GAIN                SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_RX_MODE_OFF            SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_DDC_RXOFF              SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_TX_BB_FILT_2G          SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_TX_CONFIG              SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_DDC_TXEN               SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_CW02_DFM_PLL           SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_TX_BAND_BSEL           SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_CW01_DFM_PLL           SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_CW43_DFM               SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_TXMODE_CTRL            SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_TX_GAINWRITE           SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_CW02_DFM_PLL_OFF       SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_TXMODE_CTRL_OFF        SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_DDC_TXOff              SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_INIT_DET_SETUP         SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_INIT_TIME              SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_INIT_GAINRF            SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_DCXO_CAFC_CTRL         SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_CW06                   SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_CW00                   SCTRL_WORD(0,30) /* for OH E2 */
/*MT6162*/ #define  SCTRL_CW10                   SCTRL_WORD(0,30) /* for OH E2 */
/*MT6162*/
/*MT6162*/ #define  SDATA_DDC_RXEN               0x0D177F01L
/*MT6162*/ #define  SDATA_DDC_RXEN_TXVCO_ON      0x0D177F07L
/*MT6162*/ #define  SDATA_RX_MODE_SRX            0x08100100L
/*MT6162*/ #define  SDATA_SRX_FREQ_MASK          0x06100000L
/*MT6162*/ #define  SDATA_RX_MODE_RXEN           0x081001E0L
/*MT6162*/ #define  SDATA_RX_Offset_MASK         0x08200000L
/*MT6162*/ #define  SDATA_RX_Gain_MASK           0x08300000L
/*MT6162*/ #define  SDATA_RX_MODE_OFF            0x08100000L
/*MT6162*/ #define  SDATA_DDC_RXOff              0x0D120001L
/*MT6162*/ #define  SDATA_DDC_RXOff_TXVCO_ON     0x0D120007L
/*MT6162*/ #define  SDATA_TX_BB_FILT_2G          0x0AC20948L
/*MT6162*/ #define  SDATA_TX_CONFIG_LB           0x0A900335L
/*MT6162*/ #define  SDATA_TX_CONFIG_HB           0x0A900365L
/*MT6162*/ #define  SDATA_DDC_TXEN               0x0D1B007FL
/*MT6162*/ #define  SDATA_CW01_DFM_PLL_MASK      0x00140000L
/*MT6162*/ #define  SDATA_CW43_DFM_GSM_E1        0x02B9C005L /* bit[19]=1, reset the compensation filter */
/*MT6162*/ #define  SDATA_CW43_DFM_EDGE_E1       0x02BDC005L /* bit[19]=1, reset the compensation filter */
/*MT6162*/ #define  SDATA_CW43_DFM_GSM_E2        0x02B9C00CL /* bit[4:0]=12, increase the SX bandgap fast-charge OFF delay time on E2 */
/*MT6162*/ #define  SDATA_CW43_DFM_EDGE_E2       0x02BDC00CL /* bit[4:0]=12, increase the SX bandgap fast-charge OFF delay time on E2 */
/*MT6162*/ #define  SDATA_TXMODE_CTRL_GSM        0x0A1000FCL
/*MT6162*/ #define  SDATA_TXMODE_CTRL_EDGE       0x0A1000FDL
/*MT6162*/ #define  SDATA_TXMODE_CTRL_2G         0x0A100000L
/*MT6162*/ #define  SDATA_TX_GAINWRITE_MASK      0x0A400001L
/*MT6162*/ #define  SDATA_TX_MEASURE_TRIGGER     0x0A400001L /* as long as MEAS_SEL[1:0] is not 0, a measurement will be triggered */
/*MT6162*/ #define  SDATA_TXMODE_CTRL_OFF        0x0A100000L
/*MT6162*/ #define  SDATA_DDC_TXOff              0x0D120001L
/*MT6162*/ #define  SDATA_DDC_TXOff_TXVCO_ON     0x0D120007L
/*MT6162*/ #define  SDATA_DDC_EN_TXCAL           0x0D1F7F7FL
/*MT6162*/ #define  SDATA_RX_MODE_SRX_TXCAL      0x08130102L /* RXVCO_CALBUF_EN[17]=1, TXCAL_BBPATH[16]=1, set to 3G RX_MODE (increase BW) */
/*MT6162*/ #define  SDATA_RX_MODE_RXEN_TXCAL     0x081301E2L /* RXVCO_CALBUF_EN[17]=1, TXCAL_BBPATH[16]=1, set to 3G RX_MODE (increase BW) */
/*MT6162*/ #define  SDATA_RX_DC_OFFSET_TXCAL     0x08200000L
/*MT6162*/ #define  SDATA_RX_GAIN_TXCAL          0x0830030CL
/*MT6162*/ #define  SDATA_TXMODE_CTRL_MASK_TXCAL 0x000BFF00L
/*MT6162*/ #define  SDATA_CW02_Standby_MASK      0x00040000L
/*MT6162*/ #define  SDATA_CW02_2G_MASK           0x00080000L
/*MT6162*/ #define  SDATA_INIT_DET_SETUP         0x0A200064L /* these three register values are different in 2G and 3G modes */
/*MT6162*/ #define  SDATA_INIT_TIME              0x0A301FC0L
/*MT6162*/ #define  SDATA_INIT_GAINRF            0x0C04A864L
/*MT6162*/ #define  SDATA_GAINRF_TXIQMMCAL       0x0C04A730L
/*MT6162*/ #define  SDATA_DCXO_CAFC_CTL_MASK     0x0E100000L
/*MT6162*/ #define  SDATA_CW00_2G                0x000402A8L /* set CP current to 40d to increase Loop BW for freq error */
/*MT6162*/ #define  SDATA_CW10_INIT              0x00A41150L /* LG_MODE[1:0]=0 */
/*MT6162*/ #define  SDATA_CW10_ISOTPOL_1         0x00A40116L /* set LG_DCI_TSEL[12:11]=0, LG_LCAL_TSEL[9:6]=4, DFM_LGCP_ISOTPOL[2]=1, LG_MODE[1:0]=2(2-step LG cal) */
/*MT6162*/ #define  SDATA_CW10_ISOTPOL_0         0x00A40112L /* set LG_DCI_TSEL[12:11]=0, LG_LCAL_TSEL[9:6]=4, DFM_LGCP_ISOTPOL[2]=0, LG_MODE[1:0]=2(2-step LG cal) */
/*MT6162*/ #define  SDATA_CW02_D7_PLUS           0x00000080L /* set N_FRAC[12:0]=0000010000000b, (D[7]=1), for +TRX offset */
/*MT6162*/ #define  SDATA_CW02_D7_MINUS          0x00001F80L /* set N_FRAC[12:0]=1111110000000b,           for -TRX offset */
/*MT6162*/ #define  SDATA_CW02_TXMODE_MASK       0x00080000L /* set MODE[19:17]=100b */
/*MT6162*/
/*MT6162*/ CONST unsigned long  SDATA_RX_BAND[5] =
/*MT6162*/ {  /* BAND[2:0] */
/*MT6162*/    0x08002800,                       /* GSM  450 no support */
/*MT6162*/    0x08002800|(GSM850_PATH_SEL&0xF), /* GSM  850, LNA8 */
/*MT6162*/    0x08002800|(   GSM_PATH_SEL&0xF), /* GSM  900, LNA7 */
/*MT6162*/    0x08002800|(   DCS_PATH_SEL&0xF), /* DCS 1800, LNA6 */
/*MT6162*/    0x08002800|(   PCS_PATH_SEL&0xF), /* PCS 1900, LNA5 */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_CW02_DFM_PLL_MASK[5] =
/*MT6162*/ {
/*MT6162*/    0x00208000, /* GSM  450 no support */
/*MT6162*/    0x00208000, /* GSM  850 */
/*MT6162*/    0x0020A000, /* GSM  900 */
/*MT6162*/    0x0020C000, /* DCS 1800 */
/*MT6162*/    0x0020E000, /* PCS 1900 */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_TX_BAND_BSEL[5] =
/*MT6162*/ {
/*MT6162*/    0x0A000001, /* GSM  450 no support */
/*MT6162*/    0x0A000001, /* GSM  850 */
/*MT6162*/    0x0A000001, /* GSM  900 */
/*MT6162*/    0x0A000044, /* DCS 1800, set TX_DRV_TUNE[7:6] to 1 */
/*MT6162*/    0x0A000004, /* PCS 1900 */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_CW02_DFM_PLL_OFF[5] =
/*MT6162*/ {
/*MT6162*/    0x00208000, /* GSM  450 no support */
/*MT6162*/    0x00208000, /* GSM  850 */
/*MT6162*/    0x0020A000, /* GSM  900 */
/*MT6162*/    0x0020C000, /* DCS 1800 */
/*MT6162*/    0x0020E000, /* PCS 1900 */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ #if IS_RF_RX_DCOC_SUPPORT || IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/ const unsigned long  SDATA_SRX_FREQ_RXCAL[5] =
/*MT6162*/ {
/*MT6162*/    0x06100000, /* GSM 450 no support */
/*MT6162*/    /* rfN = (N_FRAC&0xFFF) | ((N_INT&0x7F)<<12) */
/*MT6162*/    ( (1696&0xFFF)|((67&0x7F)<<12) ), /* GSM  850, ARFCN=190, f= 881.6MHz */
/*MT6162*/    ( (1056&0xFFF)|((72&0x7F)<<12) ), /* GSM  900, ARFCN= 38, f= 942.6MHz */
/*MT6162*/    ( (1808&0xFFF)|((70&0x7F)<<12) ), /* DCS 1800, ARFCN=699, f=1842.6MHz */
/*MT6162*/    ( ( 800&0xFFF)|((75&0x7F)<<12) ), /* PCS 1900, ARFCN=661, f=1960.0MHz */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_RX_GAIN_TABLE_RXCAL[4] =
/*MT6162*/ {
/*MT6162*/    /* RXGAIN_OW_EN[8], PGAGAIN_OW[6:4], BQGAIN_OW[1:0] */
/*MT6162*/    0x09031140,//0x09000140, /* [PGAGAIN_OW, BQGAIN_OW]=[4(5dB), 0( 0dB)], for the 1st slot */
/*MT6162*/    0x09031141,//0x09000141, /* [PGAGAIN_OW, BQGAIN_OW]=[4(5dB), 1( 6dB)], for the 2nd slot */
/*MT6162*/    0x09031142,//0x09000142, /* [PGAGAIN_OW, BQGAIN_OW]=[4(5dB), 2(12dB)], for the 3rd slot */
/*MT6162*/    0x09031143,//0x09000143, /* [PGAGAIN_OW, BQGAIN_OW]=[4(5dB), 3(18dB)], for the 4th slot */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_RX_DCOFFSET_RXCAL[2] =
/*MT6162*/ {
/*MT6162*/    0x08200000, /* [DC_Offset_i, DC_Offset_q]=[0, 0], for the 1st slot */
/*MT6162*/    0x08200808, /* [DC_Offset_i, DC_Offset_q]=[8, 8], for the 2nd slot */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_TX_BAND_TXCAL[5] =
/*MT6162*/ {
/*MT6162*/    0x0A000000, /* GSM  450 no support */
/*MT6162*/    /* TX_PDETVCO_SEL[5]=1, TX_CAL_EN[4]=1, and TX_FB_EN[3]=1 */
/*MT6162*/    0x0A000039, /* GSM  850 */
/*MT6162*/    0x0A000039, /* GSM  900 */
/*MT6162*/    0x0A00003C, /* DCS 1800 */
/*MT6162*/    0x0A00003C, /* PCS 1900 */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_SRX_FREQ_TXCAL[5] =
/*MT6162*/ {
/*MT6162*/    0x06100000, /* GSM 450 no support */
/*MT6162*/    /* rfN = (N_FRAC&0xFFF) | ((N_INT&0x7F)<<12) */
/*MT6162*/    ( ( 736&0xFFF)|((64&0x7F)<<12) ), /* GSM  850, ARFCN=190, f= 836.6MHz */
/*MT6162*/    ( ( 960&0xFFF)|((69&0x7F)<<12) ), /* GSM  900, ARFCN= 65, f= 903.0MHz */
/*MT6162*/    ( (1616&0xFFF)|((65&0x7F)<<12) ), /* DCS 1800, ARFCN=512, f=1710.2MHz */
/*MT6162*/    ( ( 336&0xFFF)|((71&0x7F)<<12) ), /* PCS 1900, ARFCN=512, f=1850.2MHz */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_CW01_DFM_PLL_TXCAL[5] =
/*MT6162*/ {
/*MT6162*/    0x00100000, /* GSM 450 no support */
/*MT6162*/    /* rfN = (N_FRAC&0x3FF) | ((N_INT&0xFF)<<10) */
/*MT6162*/    ( (6023923&0x3FF)|((128&0xFF)<<10) ), /* GSM  850, ARFCN=190, f= 836.6MHz+67.7kHz */
/*MT6162*/    ( (7830701&0x3FF)|((138&0xFF)<<10) ), /* GSM  900, ARFCN= 65, f= 903.0MHz+67.7kHz */
/*MT6162*/    ( (4689683&0x3FF)|((131&0xFF)<<10) ), /* DCS 1800, ARFCN=512, f=1710.2MHz+67.7kHz */
/*MT6162*/    ( (2753850&0x3FF)|((142&0xFF)<<10) ), /* PCS 1900, ARFCN=512, f=1850.2MHz+67.7kHz */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_CW02_DFM_PLL_TXCAL[5] =
/*MT6162*/ {
/*MT6162*/    0x00200000, /* GSM 450 no support */
/*MT6162*/    /* ifN = (N_FRAC>>10)&0x1FFF */
/*MT6162*/    ( (6023923>>10)&0x1FFF ), /* GSM  850, ARFCN=190, f= 836.6MHz+67.7kHz */
/*MT6162*/    ( (7830701>>10)&0x1FFF ), /* GSM  900, ARFCN= 65, f= 903.0MHz+67.7kHz */
/*MT6162*/    ( (4689683>>10)&0x1FFF ), /* DCS 1800, ARFCN=512, f=1710.2MHz+67.7kHz */
/*MT6162*/    ( (2753850>>10)&0x1FFF ), /* PCS 1900, ARFCN=512, f=1850.2MHz+67.7kHz */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ unsigned long SDATA_TX_GAIN_CAL_TABLE[5] =
/*MT6162*/ {
/*MT6162*/    /* gainDET[19:16], gainRF[15:12], gainBB[11:2] */
/*MT6162*/    ( 0<<16)|(3<<12)|( 300<<2), /* [gainDET, gainRF, gainBB]=[ 0,3, 300], for GCM_SETUP_BURST5 */
/*MT6162*/    ( 7<<16)|(3<<12)|(1000<<2), /* [gainDET, gainRF, gainBB]=[ 7,3,1000], for GCM_SETUP_BURST6 */
/*MT6162*/    ( 8<<16)|(4<<12)|(1000<<2), /* [gainDET, gainRF, gainBB]=[ 8,4,1000], for GCM_SETUP_BURST7 */
/*MT6162*/    ( 9<<16)|(5<<12)|(1000<<2), /* [gainDET, gainRF, gainBB]=[ 9,5,1000], for GCM_SETUP_BURST8 */
/*MT6162*/    (10<<16)|(6<<12)|(1000<<2)  /* [gainDET, gainRF, gainBB]=[10,6,1000], for GCM_SETUP_BURST9 */
/*MT6162*/ };
/*MT6162*/ #endif /* IS_RF_RX_DCOC_SUPPORT || IS_RF_TX_CALIBRATION_SUPPORT */
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_SR0( void )
/*MT6162*/ {
/*MT6162*/    unsigned long data_ddc_en;
/*MT6162*/
/*MT6162*/    SETUP_SR0();
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_tx_cal&0x10 )                                      /* TXIQMM Calibration is on-going */
/*MT6162*/    {  data_ddc_en   = SDATA_DDC_EN_TXCAL;  }                         /* enable all LDOs for RX and TX circuits when TXIQMM is on-going */
/*MT6162*/    else
/*MT6162*/ #endif
/*MT6162*/    {  /* normal RX */
/*MT6162*/ #if IS_RF_VCO_DOO_OFF || IS_RF_VCO_PARTIAL_DOO_ON
/*MT6162*/       if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6162*/       {  data_ddc_en = SDATA_DDC_RXEN_TXVCO_ON;  }                   /* enable all LDOs for RX and SRX circuits, and keep TXVCO on */
/*MT6162*/       else
/*MT6162*/ #endif
/*MT6162*/       {  data_ddc_en = SDATA_DDC_RXEN;           }                   /* enable all LDOs for RX and SRX circuits */
/*MT6162*/    }
/*MT6162*/
/*MT6162*/ #if IS_DCXO_ENABLE
/*MT6162*/    HWRITE_5_SDATA( SCTRL_DDC_RXEN, data_ddc_en,
/*MT6162*/                    SCTRL_TX_BB_FILT_2G, SDATA_TX_BB_FILT_2G,
/*MT6162*/                    SCTRL_DCXO_CAFC_CTRL, (l1d_rf.AFC_data&0x1FFF)|SDATA_DCXO_CAFC_CTL_MASK, /* set DCXO */
/*MT6162*/                    SCTRL_RESERVED, 0,                                /* reserved */
/*MT6162*/                    SCTRL_RESERVED, 0 );                              /* reserved */
/*MT6162*/ #else
/*MT6162*/    HWRITE_4_SDATA( SCTRL_DDC_RXEN, data_ddc_en,
/*MT6162*/                    SCTRL_TX_BB_FILT_2G, SDATA_TX_BB_FILT_2G,
/*MT6162*/                    SCTRL_RESERVED, 0,                                /* reserved */
/*MT6162*/                    SCTRL_RESERVED, 0 );                              /* reserved */
/*MT6162*/ #endif
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_SR1( void )
/*MT6162*/ {
/*MT6162*/    unsigned long data_rx_mode = SDATA_RX_MODE_SRX;
/*MT6162*/    unsigned long rfn_data;
/*MT6162*/
/*MT6162*/    SETUP_SR1();
/*MT6162*/ #if IS_RF_RX_DCOC_SUPPORT || IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_rx_cal )                                         /* RXDCOC is on-going */
/*MT6162*/    {  rfn_data = SDATA_SRX_FREQ_RXCAL[l1d_rf.band];  }
/*MT6162*/    else if( l1d_rf2.is_tx_cal&0x10 )                               /* TXIQMM calibration is on-going*/
/*MT6162*/    {
/*MT6162*/       data_rx_mode = SDATA_RX_MODE_SRX_TXCAL;
/*MT6162*/       rfn_data = SDATA_SRX_FREQ_TXCAL[l1d_rf.band];
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/ #endif
/*MT6162*/    {  rfn_data = l1d_rf.RFN_data;  }                               /* normal RX */
/*MT6162*/
/*MT6162*/    HWRITE_3_SDATA( SCTRL_RX_BAND, SDATA_RX_BAND[l1d_rf.band],      /* select correct LNA input */
/*MT6162*/                    SCTRL_RX_MODE_SRX, data_rx_mode,                /* enable SRX and select RX mode */
/*MT6162*/                    SCTRL_SRX_FREQ, rfn_data|SDATA_SRX_FREQ_MASK ); /* set synthesizer frequency */
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_SR2( void )
/*MT6162*/ {
/*MT6162*/    unsigned long ctrl_rx_dc_offset = SCTRL_RX_OFFSET;
/*MT6162*/    unsigned long ctrl_rx_agc = SCTRL_RX_GAIN;
/*MT6162*/    unsigned long data_rx_mode = SDATA_RX_MODE_RXEN;
/*MT6162*/    unsigned long data_rx_dc_offset;
/*MT6162*/    unsigned long data_rx_agc;
/*MT6162*/
/*MT6162*/    SETUP_SR2();
/*MT6162*/ #if IS_RF_RX_DCOC_SUPPORT || IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_rx_cal )
/*MT6162*/    {  /* RXDCOC is on-going*/
/*MT6162*/       if( l1d_rf.rx_slots==0x3 )
/*MT6162*/       {  /* calibrate the compensation voltage value per DAC */
/*MT6162*/          data_rx_dc_offset = SDATA_RX_DCOFFSET_RXCAL[l1d_rf.cur_slot];
/*MT6162*/          data_rx_agc = SDATA_RX_GAIN_TABLE_RXCAL[0];
/*MT6162*/       }
/*MT6162*/       else
/*MT6162*/       {
/*MT6162*/          data_rx_dc_offset = SDATA_RX_Offset_MASK;
/*MT6162*/          data_rx_agc = SDATA_RX_GAIN_TABLE_RXCAL[l1d_rf.cur_slot];
/*MT6162*/       }
/*MT6162*/    }
/*MT6162*/    else if( l1d_rf2.is_tx_cal&0x10 )
/*MT6162*/    {  /* TXIQMM calibration is on-going */
/*MT6162*/       ctrl_rx_dc_offset = SCTRL_RESERVED;
/*MT6162*/       ctrl_rx_agc = SCTRL_RESERVED;
/*MT6162*/       data_rx_mode = SDATA_RX_MODE_RXEN_TXCAL;
/*MT6162*/       data_rx_dc_offset = 0;
/*MT6162*/       data_rx_agc = 0;
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/ #endif
/*MT6162*/    {  /* normal RX */
/*MT6162*/       data_rx_dc_offset = l1d_rf2.rx_dc_offset|SDATA_RX_Offset_MASK;
/*MT6162*/       data_rx_agc = l1d_rf.AGC_data|SDATA_RX_Gain_MASK;
/*MT6162*/    }
/*MT6162*/
/*MT6162*/    if( IS_CONTINUOUS_RX_SLOT() )
/*MT6162*/    {
/*MT6162*/       HWRITE_4_SDATA( ctrl_rx_dc_offset, data_rx_dc_offset, /* set RX DC offset */
/*MT6162*/                       ctrl_rx_agc, data_rx_agc,             /* set RX gain */
/*MT6162*/                       SCTRL_RESERVED, 0,                    /* reserved */
/*MT6162*/                       SCTRL_RESERVED, 0 );                  /* reserved */
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/    {
/*MT6162*/       HWRITE_4_SDATA( SCTRL_RX_MODE_RXEN, data_rx_mode,     /* enable RX circuits */
/*MT6162*/                       ctrl_rx_dc_offset, data_rx_dc_offset, /* set RX DC offset */
/*MT6162*/                       ctrl_rx_agc, data_rx_agc,             /* set RX gain */
/*MT6162*/                       SCTRL_RESERVED, 0 );                  /* reserved */
/*MT6162*/    }
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_SR3( void )
/*MT6162*/ {
/*MT6162*/    unsigned long ctrl_cw02 = SCTRL_RESERVED;
/*MT6162*/    unsigned long data_ddc_off = SDATA_DDC_RXOff;         /* set LDOs to the idle+dig state */
/*MT6162*/    unsigned long data_cw02 = 0;
/*MT6162*/
/*MT6162*/    SETUP_SR3();
/*MT6162*/ #if IS_RF_VCO_DOO_OFF || IS_RF_VCO_PARTIAL_DOO_ON
/*MT6162*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6162*/    {
/*MT6162*/       data_ddc_off = SDATA_DDC_RXOff_TXVCO_ON;           /* keep TXVCO on */
/*MT6162*/       ctrl_cw02    = SCTRL_CW02_DFM_PLL;
/*MT6162*/       data_cw02    = (l1d_rf.IFN_data&0x1FFF)|SDATA_CW02_DFM_PLL_MASK[l1d_rf.band]|SDATA_CW02_Standby_MASK;
/*MT6162*/    }
/*MT6162*/ #endif
/*MT6162*/
/*MT6162*/    HWRITE_3_SDATA( SCTRL_RX_MODE_OFF, SDATA_RX_MODE_OFF, /* turn off RX circuits */
/*MT6162*/                    SCTRL_DDC_RXOFF, data_ddc_off,        /* set LDOs */
/*MT6162*/                    ctrl_cw02, data_cw02 );               /* set CW02 to the stand-by mode */
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_ST0( void )
/*MT6162*/ {
/*MT6162*/    unsigned long data_tx_config = (l1d_rf.band<=FrequencyBand900) ? (SDATA_TX_CONFIG_LB) : (SDATA_TX_CONFIG_HB);
/*MT6162*/    unsigned long data_ddc_en = SDATA_DDC_TXEN;      /* enable bandgap reference to DFM and enable LDOs for TX VCO and LO buffers */
/*MT6162*/
/*MT6162*/    unsigned long ctrl_cw00 = SCTRL_RESERVED;        /* for OH E2 */
/*MT6162*/    unsigned long ctrl_cw10 = SCTRL_RESERVED;
/*MT6162*/    unsigned long data_cw00 = 0;
/*MT6162*/    unsigned long data_cw10 = 0;
/*MT6162*/
/*MT6162*/    SETUP_ST0();
/*MT6162*/    if( L1D_RF_Get6162Version()==1 )
/*MT6162*/    {  /* for OH E1, do nothing */  }
/*MT6162*/    else
/*MT6162*/    {  /* for OH E2 */
/*MT6162*/       ctrl_cw00 = SCTRL_CW00;
/*MT6162*/       ctrl_cw10 = SCTRL_CW10;
/*MT6162*/       data_cw00 = SDATA_CW00_2G;
/*MT6162*/       data_cw10 = (l1d_rf2.is_isotpol==1) ? SDATA_CW10_ISOTPOL_1 : SDATA_CW10_ISOTPOL_0;
/*MT6162*/       l1d_rf2.is_isotpol = 0;
/*MT6162*/    }
/*MT6162*/
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_tx_cal&0x10 )                     /* TXIQMM Calibration is on-going*/
/*MT6162*/    {  data_ddc_en = SDATA_DDC_EN_TXCAL;  }          /* enable all LDOs for RX and TX circuits when TXIQMM is on-going */
/*MT6162*/ #endif
/*MT6162*/
/*MT6162*/ #if IS_DCXO_ENABLE
/*MT6162*/    HWRITE_5_SDATA( SCTRL_TX_CONFIG, data_tx_config, /* set TX configuration register for the high and low bands */
/*MT6162*/                    SCTRL_DDC_TXEN, data_ddc_en,                                             /* set LDOs */
/*MT6162*/                    SCTRL_DCXO_CAFC_CTRL, (l1d_rf.AFC_data&0x1FFF)|SDATA_DCXO_CAFC_CTL_MASK, /* set DCXO */
/*MT6162*/                    ctrl_cw00, data_cw00,           /* we need to set CW0 to the 2G value in OH E2 */
/*MT6162*/                    ctrl_cw10, data_cw10 );
/*MT6162*/ #else
/*MT6162*/    HWRITE_4_SDATA( SCTRL_TX_CONFIG, data_tx_config, /* set TX configuration register for the high and low bands */
/*MT6162*/                    SCTRL_DDC_TXEN, data_ddc_en,     /* set LDOs */
/*MT6162*/                    ctrl_cw00, data_cw00,            /* we need to set CW0 to the 2G value in OH E2 */
/*MT6162*/                    ctrl_cw10, data_cw10 );
/*MT6162*/ #endif
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_ST1( void )
/*MT6162*/ {
/*MT6162*/    unsigned long tx_band;
/*MT6162*/    unsigned long rfn_data;
/*MT6162*/
/*MT6162*/    SETUP_ST1();
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_tx_cal&0x10 )
/*MT6162*/    {  /* TXIQMM Calibration is on-going */
/*MT6162*/       tx_band  = SDATA_TX_BAND_TXCAL[l1d_rf.band];
/*MT6162*/       rfn_data = SDATA_CW01_DFM_PLL_TXCAL[l1d_rf.band];
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/ #endif
/*MT6162*/    {  /* normal TX */
/*MT6162*/       tx_band  = SDATA_TX_BAND_BSEL[l1d_rf.band];
/*MT6162*/       rfn_data = l1d_rf.RFN_data;
/*MT6162*/    }
/*MT6162*/
/*MT6162*/    HWRITE_3_SDATA( SCTRL_TX_BAND_BSEL, tx_band,                            /* set TX band */
/*MT6162*/                    SCTRL_CW01_DFM_PLL, rfn_data|SDATA_CW01_DFM_PLL_MASK,   /* set the synthesizer frequency */
/*MT6162*/                    SCTRL_INIT_DET_SETUP, SDATA_INIT_DET_SETUP );           /* set the GAINRAMP_T time, 50us */
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6162*/ {
/*MT6162*/    unsigned long  ctrl_cw02             = (l1d_rf2.is_integer==1) ? SCTRL_CW02_DFM_PLL : SCTRL_RESERVED;
/*MT6162*/    unsigned long  data_tx_gain_set;
/*MT6162*/    unsigned long  data_txmode_ctrl_gsm  = SDATA_TXMODE_CTRL_GSM;
/*MT6162*/    unsigned long  data_txmode_ctrl_edge = SDATA_TXMODE_CTRL_EDGE;
/*MT6162*/    unsigned long  data_cw43_dfm_edge    = (L1D_RF_Get6162Version() == 1) ? (SDATA_CW43_DFM_EDGE_E1) : (SDATA_CW43_DFM_EDGE_E2);
/*MT6162*/    unsigned long  data_cw43_dfm_gsm     = (L1D_RF_Get6162Version() == 1) ? (SDATA_CW43_DFM_GSM_E1)  : (SDATA_CW43_DFM_GSM_E2);
/*MT6162*/    unsigned long  data_cw02             = (l1d_rf2.is_integer==1) ? ((l1d_rf.IFN_data&0x1FFF)|SDATA_CW02_DFM_PLL_MASK[l1d_rf.band]|SDATA_CW02_TXMODE_MASK) : 0;
/*MT6162*/
/*MT6162*/    SETUP_ST2B_ST2M();
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_tx_cal&0x10 )
/*MT6162*/    {  /* TXIQMM Calibration is on-going */
/*MT6162*/       data_tx_gain_set  = SDATA_TX_GAIN_CAL_TABLE[(l1d_rf2.is_tx_cal&0x0F)];
/*MT6162*/       data_tx_gain_set |= SDATA_TX_GAINWRITE_MASK;
/*MT6162*/       data_txmode_ctrl_gsm |= SDATA_TXMODE_CTRL_MASK_TXCAL;
/*MT6162*/       data_txmode_ctrl_edge |= SDATA_TXMODE_CTRL_MASK_TXCAL;
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/ #endif
/*MT6162*/    {  /* normal TX */
/*MT6162*/       data_tx_gain_set  = L1D_RF_SetTxGainWrite( l1d_rf.tx_mod_type2, l1d_rf.cur_slot, l1d_rf2.tx_power[l1d_rf.cur_slot], (FrequencyBand)l1d_rf.band );
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 ) /* compensate TXIQ only in the EPSK mode */
/*MT6162*/       L1D_RF_SetEPSKTxIQ( (signed short)l1d_rf.cur_slot, data_tx_gain_set );
/*MT6162*/ #endif
/*MT6162*/       data_tx_gain_set |= SDATA_TX_MEASURE_TRIGGER; /* trigger the TX measurement in normal TX */
/*MT6162*/    }
/*MT6162*/
/*MT6162*/    if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6162*/    {  /* 8PSK */
/*MT6162*/       HWRITE_4_SDATA( SCTRL_CW43_DFM, data_cw43_dfm_edge,         /* set DFM to the EDGE mode */
/*MT6162*/                       SCTRL_TXMODE_CTRL, data_txmode_ctrl_edge,   /* set the TX mode to EDGE */
/*MT6162*/                       SCTRL_TX_GAINWRITE, data_tx_gain_set,       /* set the TX gain */
/*MT6162*/                       ctrl_cw02, data_cw02 );
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/    {  /* GMSK */
/*MT6162*/       HWRITE_4_SDATA( SCTRL_CW43_DFM, data_cw43_dfm_gsm,          /* set DFM to the GSM mode */
/*MT6162*/                       SCTRL_TXMODE_CTRL, data_txmode_ctrl_gsm,    /* set the TX mode to GSM */
/*MT6162*/                       SCTRL_TX_GAINWRITE, data_tx_gain_set,       /* set the TX gain */
/*MT6162*/                       ctrl_cw02, data_cw02 );
/*MT6162*/    }
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_ST3( void )
/*MT6162*/ {
/*MT6162*/    unsigned long  data_ddc_off;
/*MT6162*/    unsigned long  data_cw02;
/*MT6162*/
/*MT6162*/    SETUP_ST3();
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_tx_cal&0x10 )
/*MT6162*/    {  /* TXIQMM Calibration is on-going */
/*MT6162*/       data_ddc_off = SDATA_DDC_EN_TXCAL; /* keep LDOs on until RX windows are off */
/*MT6162*/       data_cw02 = SDATA_CW02_DFM_PLL_TXCAL[l1d_rf.band]|SDATA_CW02_DFM_PLL_OFF[l1d_rf.band];
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/ #endif
/*MT6162*/    {  /* normal TX */
/*MT6162*/       data_cw02 = (l1d_rf.IFN_data&0x1FFF)|SDATA_CW02_DFM_PLL_OFF[l1d_rf.band];
/*MT6162*/ #if IS_RF_VCO_PARTIAL_DOO_ON
/*MT6162*/       if( l1d_rf2.dedicated_flag & SC_DEDICATED_2TX )
/*MT6162*/       {  /* set TXVCO to stand-by in the end of the 1st TX */
/*MT6162*/          data_ddc_off = SDATA_DDC_TXOff_TXVCO_ON;
/*MT6162*/          data_cw02 |= SDATA_CW02_Standby_MASK;
/*MT6162*/       }
/*MT6162*/       else
/*MT6162*/ #elif IS_RF_VCO_DOO_OFF
/*MT6162*/       if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6162*/       {  /* set TXVCO to stand-by in the end of TX */
/*MT6162*/          data_ddc_off = SDATA_DDC_TXOff_TXVCO_ON;
/*MT6162*/          data_cw02 |= SDATA_CW02_Standby_MASK;
/*MT6162*/       }
/*MT6162*/       else
/*MT6162*/ #endif
/*MT6162*/       {
/*MT6162*/          data_ddc_off = SDATA_DDC_TXOff;
/*MT6162*/       }
/*MT6162*/    }
/*MT6162*/
/*MT6162*/    HWRITE_3_SDATA( SCTRL_CW02_DFM_PLL_OFF, data_cw02,            /* power down DFM */
/*MT6162*/                    SCTRL_TXMODE_CTRL_OFF, SDATA_TXMODE_CTRL_OFF, /* power down TX */
/*MT6162*/                    SCTRL_DDC_TXOff, data_ddc_off );              /* set LDOs  */
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_ST2( void )
/*MT6162*/ {
/*MT6162*/    unsigned long ctrl_cw02 = SCTRL_CW02_DFM_PLL;
/*MT6162*/    unsigned long data_cw02;
/*MT6162*/    unsigned long data_gainrf;
/*MT6162*/
/*MT6162*/    SETUP_ST2();
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_tx_cal&0x10 )
/*MT6162*/    {  /* TXIQMM Calibration is on-going */
/*MT6162*/       data_cw02 = SDATA_CW02_DFM_PLL_TXCAL[l1d_rf.band]|SDATA_CW02_DFM_PLL_MASK[l1d_rf.band]|SDATA_CW02_Standby_MASK;
/*MT6162*/       data_gainrf = SDATA_GAINRF_TXIQMMCAL;
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/ #endif
/*MT6162*/    {  /* normal TX */
/*MT6162*/       if( l1d_rf2.is_integer==1 )
/*MT6162*/       {
/*MT6162*/          data_cw02  = ((l1d_rf.IFN_data&0x1FFF)==0) ? SDATA_CW02_D7_PLUS : SDATA_CW02_D7_MINUS;
/*MT6162*/          data_cw02 |= (SDATA_CW02_DFM_PLL_MASK[l1d_rf.band]|SDATA_CW02_Standby_MASK);
/*MT6162*/       }
/*MT6162*/       else
/*MT6162*/       {  data_cw02  = (l1d_rf.IFN_data&0x1FFF)|SDATA_CW02_DFM_PLL_MASK[l1d_rf.band]|SDATA_CW02_Standby_MASK;  }
/*MT6162*/       data_gainrf = SDATA_INIT_GAINRF;
/*MT6162*/    }
/*MT6162*/
/*MT6162*/    HWRITE_4_SDATA( SCTRL_TXMODE_CTRL, SDATA_TXMODE_CTRL_2G, /* set the TX mode to 2G */
/*MT6162*/                    ctrl_cw02, data_cw02,                    /* set CW02 to the stand-by mode */
/*MT6162*/                    SCTRL_INIT_TIME, SDATA_INIT_TIME,        /* set the DETMEAS_T1 time, 63.5us */
/*MT6162*/                    SCTRL_INIT_GAINRF, data_gainrf );
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6162*/ {
/*MT6162*/    unsigned long  data_tx_gain_set;
/*MT6162*/    unsigned long  data_txmode_ctrl_gsm  = SDATA_TXMODE_CTRL_GSM;
/*MT6162*/    unsigned long  data_txmode_ctrl_edge = SDATA_TXMODE_CTRL_EDGE;
/*MT6162*/    unsigned long  data_cw43_dfm_edge    = (L1D_RF_Get6162Version() == 1) ? (SDATA_CW43_DFM_EDGE_E1) : (SDATA_CW43_DFM_EDGE_E2);
/*MT6162*/    unsigned long  data_cw43_dfm_gsm     = (L1D_RF_Get6162Version() == 1) ? (SDATA_CW43_DFM_GSM_E1)  : (SDATA_CW43_DFM_GSM_E2);
/*MT6162*/
/*MT6162*/    SETUP_ST2B_ST2M();
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_tx_cal&0x10 )
/*MT6162*/    {  /* TXIQMM Calibration is on-going*/
/*MT6162*/       data_tx_gain_set  = SDATA_TX_GAIN_CAL_TABLE[(l1d_rf2.is_tx_cal&0x0F)];
/*MT6162*/       data_tx_gain_set |= SDATA_TX_GAINWRITE_MASK; /* do not trigger the TX measurement in the calibration */
/*MT6162*/       data_txmode_ctrl_gsm |= SDATA_TXMODE_CTRL_MASK_TXCAL;
/*MT6162*/       data_txmode_ctrl_edge |= SDATA_TXMODE_CTRL_MASK_TXCAL;
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/ #endif
/*MT6162*/    {
/*MT6162*/       data_tx_gain_set = L1D_RF_SetTxGainWrite( l1d_rf.tx_mod_type2, l1d_rf.cur_slot, l1d_rf2.tx_power[l1d_rf.cur_slot], (FrequencyBand)l1d_rf.band );
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 ) /* compensate TXIQ only in the EPSK mode */
/*MT6162*/       L1D_RF_SetEPSKTxIQ( (signed short)l1d_rf.cur_slot, data_tx_gain_set );
/*MT6162*/ #endif
/*MT6162*/       data_tx_gain_set |= SDATA_TX_MEASURE_TRIGGER; /* trigger the TX measurement in normal TX */
/*MT6162*/    }
/*MT6162*/
/*MT6162*/    /* now change */
/*MT6162*/    if( (l1d_rf.change)&(1<<l1d_rf.cur_slot) )
/*MT6162*/    {  /* change g->8 */
/*MT6162*/       if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6162*/       {
/*MT6162*/          HWRITE_4_SDATA( SCTRL_CW43_DFM, data_cw43_dfm_edge,       /* set DFM to the EDGE mode */
/*MT6162*/                          SCTRL_TXMODE_CTRL, data_txmode_ctrl_edge, /* set the TX mode to EDGE */
/*MT6162*/                          SCTRL_TX_GAINWRITE, data_tx_gain_set,     /* set the TX gain */
/*MT6162*/                          SCTRL_RESERVED, 0 );                      /* reserved */
/*MT6162*/       }
/*MT6162*/       /* change 8->g */
/*MT6162*/       else
/*MT6162*/       {
/*MT6162*/          HWRITE_4_SDATA( SCTRL_CW43_DFM, data_cw43_dfm_gsm,        /* set DFM to the GSM mode */
/*MT6162*/                          SCTRL_TXMODE_CTRL, data_txmode_ctrl_gsm,  /* set the TX mode to GSM */
/*MT6162*/                          SCTRL_TX_GAINWRITE, data_tx_gain_set,     /* set the TX gain */
/*MT6162*/                          SCTRL_RESERVED, 0 );                      /* reserved */
/*MT6162*/       }
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/    {
/*MT6162*/       HWRITE_4_SDATA( SCTRL_TX_GAINWRITE, data_tx_gain_set,        /* set the TX gain */
/*MT6162*/                       SCTRL_RESERVED, 0,                           /* reserved */
/*MT6162*/                       SCTRL_RESERVED, 0,                           /* reserved */
/*MT6162*/                       SCTRL_RESERVED, 0 );                         /* reserved */
/*MT6162*/    }
/*MT6162*/ }
/*MT6162*/
#endif

#if IS_RF_MT6163
/*MT6163*/
/*MT6163*/  /*..........................................................*/
/*MT6163*/  /* Serial Interface Implement                               */
/*MT6163*/  /*..........................................................*/
/*MT6163*/
/*MT6163*/  #define CW1_DFM_LG_COE_ON     (0x1<<18)
/*MT6163*/  #define CW2_DFM_SLEEP         (0x0<<17)
/*MT6163*/  #define CW2_DFM_STANDBY       (0x2<<17)
/*MT6163*/  #define CW2_DFM_RX            (0x0<<16)
/*MT6163*/  #define CW2_DFM_TX            (0x1<<16)
/*MT6163*/  #define CW2_DFM_GSM850        (0x0<<14)
/*MT6163*/  #define CW2_DFM_GSM900        (0x1<<14)
/*MT6163*/  #define CW2_DFM_DCS1800       (0x2<<14)
/*MT6163*/  #define CW2_DFM_PCS1900       (0x3<<14)
/*MT6163*/  #define CW2_DFM_SDM_IFM_ON    (0x1<<13)
/*MT6163*/  #define CW19_DFM_SEL_GMSK     (0x0<<18)
/*MT6163*/  #define CW19_DFM_SEL_EPSK     (0x1<<18)
/*MT6163*/  #define A1_TX_TEST_ENA        (0x2C)
/*MT6163*/  #define A4_TX_MEAS_ENA        (0x1)
/*MT6163*/  #define A9_TX_CFG_LB          (0x325)
/*MT6163*/  #if IS_OT_2G_HB_HIGH_TX_GAIN_ON
/*MT6163*/  #define A9_TX_CFG_HB          (0x361|(0x1<<18)) /* Apply high gain GMSK to HB due to additional attenuator */
/*MT6163*/  #else
/*MT6163*/  #define A9_TX_CFG_HB          (0x361)
/*MT6163*/  #endif
/*MT6163*/  #define AA_TX_TEST_MODE       (0x60CF)
/*MT6163*/  #define AA_TX_TEST_OW_EN      (0x1)
/*MT6163*/  #define D1_TX_DRV_850         (0x3<<14)
/*MT6163*/  #define D1_TX_DRV_900         (0x2<<14)
/*MT6163*/  #define D1_TX_DRV_1800        (0x1<<14)
/*MT6163*/  #define D1_TX_DRV_1900        (0x0<<14)
/*MT6163*/  #define D1_TX_LB              (0x0<<11)
/*MT6163*/  #define D1_TX_HB              (0x4<<11)
/*MT6163*/  #define D1_TX_EN              (0x1<<7)
/*MT6163*/  #define D1_RX_EN              (0x1<<6)
/*MT6163*/  #define D1_PMT_OFF            (0x0<<3)
/*MT6163*/  #define D1_PMT_IDLE           (0x1<<3)
/*MT6163*/  #define D1_PMT_STANDBY        (0x2<<3)
/*MT6163*/  #define D1_PMT_RX_ON          (0x3<<3)
/*MT6163*/  #define D1_PMT_TX_ON          (0x4<<3)
/*MT6163*/  #define D1_PMT_TRX_ON         (0x5<<3)
/*MT6163*/  #define D1_TX_GSM             (0x0)
/*MT6163*/  #define D1_TX_EDGE            (0x1)
/*MT6163*/  #define F0_BSI_OWNER_2G       (0x1<<18)
/*MT6163*/  #define F0_BSI_OWNER_TD       (0x0<<18)
/*MT6163*/  #define F0_VRF18_ON           (0x1<<19)
/*MT6163*/
/*MT6163*/  #if IS_RF_RX_DCOC_SUPPORT || IS_RF_TX_CALIBRATION_SUPPORT
/*MT6163*/  const unsigned long SDATA_RXCAL_RFN[5] =
/*MT6163*/  {  /* For CW1, rfN = N_INT[7:0]<<10 | N_FRAC[9:0] */
/*MT6163*/     0,                   /* GSM  450, no support             */
/*MT6163*/     ( (135<<10) | 267 ), /* GSM  850, ARFCN=190, f= 881.6MHz */
/*MT6163*/     ( (145<<10) |  31 ), /* GSM  900, ARFCN= 38, f= 942.6MHz */
/*MT6163*/     ( (141<<10) | 488 ), /* DCS 1800, ARFCN=699, f=1842.6MHz */
/*MT6163*/     ( (150<<10) | 551 )  /* PCS 1900, ARFCN=661, f=1960.0MHz */
/*MT6163*/  };
/*MT6163*/
/*MT6163*/  const unsigned long SDATA_RXCAL_IFN[5] =
/*MT6163*/  {  /* For CW2, ifN = N_FRAC[22:10] */
/*MT6163*/        0, /* GSM  450, no support             */
/*MT6163*/     5167, /* GSM  850, ARFCN=190, f= 881.6MHz */
/*MT6163*/      126, /* GSM  900, ARFCN= 38, f= 942.6MHz */
/*MT6163*/     6049, /* DCS 1800, ARFCN=699, f=1842.6MHz */
/*MT6163*/     6301  /* PCS 1900, ARFCN=661, f=1960.0MHz */
/*MT6163*/  };
/*MT6163*/
/*MT6163*/  const unsigned long  SDATA_RX_DCOFFSET_RXCAL[2] =
/*MT6163*/  {
/*MT6163*/     0x08200000, /* [DC_Offset_i, DC_Offset_q]=[0, 0], for the 1st slot */
/*MT6163*/     0x08200808  /* [DC_Offset_i, DC_Offset_q]=[8, 8], for the 2nd slot */
/*MT6163*/  };
/*MT6163*/
/*MT6163*/  const unsigned long  SDATA_RX_GAIN_TABLE_RXCAL[4] =
/*MT6163*/  {
/*MT6163*/     /* RXGAIN_OW_EN[8], PGAGAIN_OW[6:4], BQGAIN_OW[1:0] */
/*MT6163*/     0x09031140, /* [PGAGAIN_OW, BQGAIN_OW]=[4(5dB), 0( 0dB)], for the 1st slot */
/*MT6163*/     0x09031141, /* [PGAGAIN_OW, BQGAIN_OW]=[4(5dB), 1( 6dB)], for the 2nd slot */
/*MT6163*/     0x09031142, /* [PGAGAIN_OW, BQGAIN_OW]=[4(5dB), 2(12dB)], for the 3rd slot */
/*MT6163*/     0x09031143  /* [PGAGAIN_OW, BQGAIN_OW]=[4(5dB), 3(18dB)], for the 4th slot */
/*MT6163*/  };
/*MT6163*/
/*MT6163*/  const unsigned long  SDATA_CW01_DFM_PLL_TXCAL[5] =
/*MT6163*/  {
/*MT6163*/     0x00100000, /* GSM 450 no support */
/*MT6163*/     /* rfN = (N_FRAC&0x3FF) | ((N_INT&0xFF)<<10) */
/*MT6163*/     ( (5936553&0x3FF)|((128&0xFF)<<10) ), /* GSM  850, ARFCN=190, f= 836.6MHz */
/*MT6163*/     ( (7743330&0x3FF)|((138&0xFF)<<10) ), /* GSM  900, ARFCN= 65, f= 903.0MHz */
/*MT6163*/     ( (4645998&0x3FF)|((131&0xFF)<<10) ), /* DCS 1800, ARFCN=512, f=1710.2MHz */
/*MT6163*/     ( (2710165&0x3FF)|((142&0xFF)<<10) ), /* PCS 1900, ARFCN=512, f=1850.2MHz */
/*MT6163*/  };
/*MT6163*/
/*MT6163*/  const unsigned long  SDATA_CW02_DFM_PLL_TXCAL[5] =
/*MT6163*/  {
/*MT6163*/     0x00200000, /* GSM 450 no support */
/*MT6163*/     /* ifN = (N_FRAC>>10)&0x1FFF */
/*MT6163*/     ( (5936553>>10)&0x1FFF ), /* GSM  850, ARFCN=190, f= 836.6MHz */
/*MT6163*/     ( (7743330>>10)&0x1FFF ), /* GSM  900, ARFCN= 65, f= 903.0MHz */
/*MT6163*/     ( (4645998>>10)&0x1FFF ), /* DCS 1800, ARFCN=512, f=1710.2MHz */
/*MT6163*/     ( (2710165>>10)&0x1FFF ), /* PCS 1900, ARFCN=512, f=1850.2MHz */
/*MT6163*/  };
/*MT6163*/
/*MT6163*/  const unsigned long SDATA_A4_GAIN_TABLE_TXCAL[3] =
/*MT6163*/  {
/*MT6163*/     /* gainDET[19:16], gainRF[15:12], gainBB[11:2] */
/*MT6163*/     ( 0<<16)|(3<<12)|( 300<<2), /* [gainDET, gainRF, gainBB]=[ 0,3, 300], for GCM_SETUP_BURST5/6    */
/*MT6163*/     ( 7<<16)|(3<<12)|(1000<<2), /* [gainDET, gainRF, gainBB]=[ 7,3,1000], for GCM_SETUP_BURST7      */
/*MT6163*/     ( 8<<16)|(4<<12)|(1000<<2), /* [gainDET, gainRF, gainBB]=[ 8,4,1000], for GCM_SETUP_BURST8 (HB) */
/*MT6163*/  };
/*MT6163*/  #endif /* IS_RF_RX_DCOC_SUPPORT || IS_RF_TX_CALIBRATION_SUPPORT */
/*MT6163*/
/*MT6163*/  CONST unsigned long SDATA_D1_BAND[5] =
/*MT6163*/  {
/*MT6163*/     0x0D100000,                                                    /* GSM  450 no support */
/*MT6163*/     0x0D100000|D1_TX_DRV_850 |D1_TX_LB|((GSM850_PATH_SEL&0x7)<<8), /* GSM  850, LNA8 */
/*MT6163*/     0x0D100000|D1_TX_DRV_900 |D1_TX_LB|((   GSM_PATH_SEL&0x7)<<8), /* GSM  900, LNA7 */
/*MT6163*/     0x0D100000|D1_TX_DRV_1800|D1_TX_HB|((   DCS_PATH_SEL&0x7)<<8), /* DCS 1800, LNA6 */
/*MT6163*/     0x0D100000|D1_TX_DRV_1900|D1_TX_HB|((   PCS_PATH_SEL&0x7)<<8)  /* PCS 1900, LNA5 */
/*MT6163*/  };
/*MT6163*/
/*MT6163*/  const unsigned long SDATA_CW02_DFM_BAND[5] =
/*MT6163*/  {
/*MT6163*/     0x00200000,                   /* GSM  450 no support */
/*MT6163*/     0x00200000|CW2_DFM_GSM850,    /* GSM  850 */
/*MT6163*/     0x00200000|CW2_DFM_GSM900,    /* GSM  900 */
/*MT6163*/     0x00200000|CW2_DFM_DCS1800,   /* DCS 1800 */
/*MT6163*/     0x00200000|CW2_DFM_PCS1900    /* PCS 1900 */
/*MT6163*/  };
/*MT6163*/
/*MT6163*/  const unsigned long SDATA_TX_GAIN_LUT[2][3] =
/*MT6163*/  {
/*MT6163*/     {  /* LB */
/*MT6163*/        0x0C516078,  /* 0xC5, LUT1, for gainrf = 2or3 */
/*MT6163*/        0x0C60C040,  /* 0xC6, LUT2, for gainrf = 4or5 */
/*MT6163*/        0x0C702018   /* 0xC7, LUT3, for gainrf = 6or7 */
/*MT6163*/     },
/*MT6163*/     {  /* HB */
/*MT6163*/        0x0C52E120,  /* 0xC5, LUT1, for gainrf = 2or3 */
/*MT6163*/        0x0C612070,  /* 0xC6, LUT2, for gainrf = 4or5 */
/*MT6163*/        0x0C700418   /* 0xC7, LUT3, for gainrf = 6or7 */
/*MT6163*/     }
/*MT6163*/  };
/*MT6163*/
/*MT6163*/  #define  SCTRL_MODE                    SCTRL_WORD(0,30)
/*MT6163*/  #define  SCTRL_DFM                     SCTRL_WORD(0,30)
/*MT6163*/  #define  SCTRL_DFM_G8                  SCTRL_WORD(0,30)
/*MT6163*///#define  SCTRL_TX_BB_FILT_2G           SCTRL_WORD(0,30)
/*MT6163*/  #define  SCTRL_DFM_INIT_2G             SCTRL_WORD(0,30)
/*MT6163*/  #define  SCTRL_DCXO_CAFC_CTRL          SCTRL_WORD(0,30)
/*MT6163*/  #define  SCTRL_AST                     SCTRL_WORD(0,30)
/*MT6163*/  #define  SCTRL_RX_OFFSET               SCTRL_WORD(0,30)
/*MT6163*/  #define  SCTRL_RX_GAIN                 SCTRL_WORD(0,30)
/*MT6163*/  #define  SCTRL_TX_GAINWRITE            SCTRL_WORD(0,30)
/*MT6163*/  #define  SCTRL_TX_GAIN_LUT             SCTRL_WORD(0,30)
/*MT6163*/  #define  SCTRL_TX_CONFIG               SCTRL_WORD(0,30)
/*MT6163*/  #define  SCTRL_TX_TEST                 SCTRL_WORD(0,30)
/*MT6163*/
/*MT6163*/  #define  SDATA_MODE_RX_ON( band )      (SDATA_D1_BAND[band]         |D1_PMT_RX_ON)
/*MT6163*/  #define  SDATA_MODE_TX_ON( band )      (SDATA_D1_BAND[band]         |D1_PMT_TRX_ON) /* TRX on for power detector */
/*MT6163*/  #define  SDATA_MODE_RXEN( band )       (SDATA_D1_BAND[band]|D1_RX_EN|D1_PMT_RX_ON)
/*MT6163*/  #define  SDATA_MODE_TXEN( band )       (SDATA_D1_BAND[band]|D1_TX_EN|D1_PMT_TRX_ON) /* TRX on for power detector */
/*MT6163*/  #define  SDATA_MODE_IDLE( band )       (SDATA_D1_BAND[band]         |D1_PMT_IDLE)
/*MT6163*/  #define  SDATA_DFM_STBY_RX( band )     (SDATA_CW02_DFM_BAND[band]|CW2_DFM_STANDBY|CW2_DFM_RX)
/*MT6163*/  #define  SDATA_DFM_STBY_TX( band )     (SDATA_CW02_DFM_BAND[band]|CW2_DFM_STANDBY|CW2_DFM_TX|CW2_DFM_SDM_IFM_ON)
/*MT6163*/  #define  SDATA_DFM_SLEEP( band )       (SDATA_CW02_DFM_BAND[band]|CW2_DFM_SLEEP  |CW2_DFM_RX|CW2_DFM_SDM_IFM_ON)
/*MT6163*/  #define  SDATA_DFM_SEL_GMSK            (0x01380000L|CW19_DFM_SEL_GMSK)
/*MT6163*/  #define  SDATA_DFM_SEL_EPSK            (0x01380000L|CW19_DFM_SEL_EPSK)
/*MT6163*/  #define  SDATA_TX_TEST_EN              (0x0A148000L|A1_TX_TEST_ENA)
/*MT6163*/  #define  SDATA_TX_GAIN_MASK            (0x0A400000L|A4_TX_MEAS_ENA)
/*MT6163*/  #define  SDATA_DFM_PLL_MASK            0x00100000L
/*MT6163*/  #define  SDATA_DFM_INIT_2G             0x00040462L
/*MT6163*/  #define  SDATA_RX_OFFSET_MASK          0x08200000L
/*MT6163*/  #define  SDATA_RX_GAIN_MASK            0x08300000L
/*MT6163*/  #define  SDATA_TX_TEST_MODE            0x0AA00000L
/*MT6163*///#define  SDATA_TX_BB_FILT_2G           0x0AC20948L /* 0xAC setting identical for both 2G/TDD */
/*MT6163*/  #define  SDATA_TX_CFG                  0x0A900000L
/*MT6163*/  #define  SDATA_TX_CFG2                 0x0C040002L
/*MT6163*/  #define  SDATA_DCXO_CAFC_CTL_MASK      0x0E100000L
/*MT6163*/  #define  SDATA_AST_MASK                0x0F000000L
/*MT6163*/
/*MT6163*/
/*MT6163*/  static unsigned long L1D_RF_SetPData_SX( char band, char is_tx, short idx )
/*MT6163*/  {
/*MT6163*/     unsigned long sdata = SDATA_AST_MASK;
/*MT6163*/
/*MT6163*/  #if IS_BSI_TRIG_OFFCHIP_BPI_SUPPORT
/*MT6163*/     sdata |= ((((unsigned long)PDATA_SX_TABLE[(unsigned char)band][(unsigned char)is_tx][idx])&0xFF)<<10); /* bit[17:10]: off-chip BPI setting */
/*MT6163*/  #endif
/*MT6163*/
/*MT6163*/  #if IS_BSI_TRIG_OFFCHIP_BSI_SWITCH_SUPPORT
/*MT6163*/     sdata |= idx==0 ? F0_BSI_OWNER_2G : F0_BSI_OWNER_TD;  /* idx: 0: SX0, 1: SX3 */
/*MT6163*/  #endif
/*MT6163*/
/*MT6163*/  #if IS_BSI_TRIG_OFFCHIP_VRF18_SUPPORT
/*MT6163*/     sdata |= F0_VRF18_ON;   /* VRF18 connecting to OT AVDD18_HF is for RFVCO */
/*MT6163*/  #endif
/*MT6163*/     return sdata;
/*MT6163*/  }
/*MT6163*/  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6163*/
/*MT6163*/  void  L1D_RF_SetSData_SR0( void )
/*MT6163*/  {
/*MT6163*/     unsigned long ifn_data; /* CW02 */
/*MT6163*/     //set this bit in L1D_RF_ComputeTxPLLFreq()
/*MT6163*/     //unsigned long sdm = (l1d_rf2.is_integer&0x2) ? 0 : CW2_DFM_SDM_IFM_ON;  /* turn off for integer channels */
/*MT6163*/     unsigned long ctrl_ast     = SCTRL_AST;
/*MT6163*/     unsigned long ctrl_tx_test = SCTRL_TX_TEST;
/*MT6163*/     unsigned long ctrl_mode    = SCTRL_MODE;
/*MT6163*/     unsigned long ctrl_dfm     = SCTRL_DFM;
/*MT6163*/     unsigned long ctrl_dcxo    = SCTRL_DCXO_CAFC_CTRL;
/*MT6163*/     unsigned long data_ast;
/*MT6163*/     unsigned long data_tx_test;
/*MT6163*/     unsigned long data_mode;
/*MT6163*/     unsigned long data_dfm;
/*MT6163*/     unsigned long data_dcxo;
/*MT6163*/
/*MT6163*/     SETUP_SR0();
/*MT6163*/
/*MT6163*/  #if IS_TDD_DUAL_MODE_SUPPORT && IS_DCXO_ENABLE
/*MT6163*/     ctrl_dcxo = l1d_rf2.is_bsi_afc_active ? SCTRL_DCXO_CAFC_CTRL : SCTRL_RESERVED;
/*MT6163*/  #endif
/*MT6163*/
/*MT6163*/  #if IS_RF_RX_DCOC_SUPPORT || IS_RF_TX_CALIBRATION_SUPPORT
/*MT6163*/     if( l1d_rf2.is_rx_cal )
/*MT6163*/     {  /* RXDCOC is on-going */
/*MT6163*/        ifn_data     = SDATA_RXCAL_IFN[l1d_rf.band]&0x1FFF;
/*MT6163*/        data_ast     = L1D_RF_SetPData_SX( l1d_rf.band, 0/*RX*/, 0/*SX0*/ );
/*MT6163*/        data_tx_test = SDATA_TX_TEST_MODE|AA_TX_TEST_OW_EN;
/*MT6163*/        data_mode    = SDATA_MODE_RX_ON( l1d_rf.band );
/*MT6163*/        data_dfm     = SDATA_DFM_STBY_RX( l1d_rf.band )|CW2_DFM_SDM_IFM_ON|ifn_data;  /* set bit[13] to 1 since it is not the integer channel */
/*MT6163*/        data_dcxo    = (l1d_rf.AFC_data&0x1FFF)|SDATA_DCXO_CAFC_CTL_MASK;
/*MT6163*/     }
/*MT6163*/     else if( l1d_rf2.is_tx_cal&0x10 )
/*MT6163*/     {  /* TXIQMM calibration is on-going */
/*MT6163*/        ctrl_ast     = SCTRL_RESERVED;
/*MT6163*/        ctrl_tx_test = SCTRL_RESERVED;
/*MT6163*/        ctrl_mode    = SCTRL_RESERVED;
/*MT6163*/        ctrl_dfm     = SCTRL_RESERVED;
/*MT6163*/        ctrl_dcxo    = SCTRL_RESERVED;
/*MT6163*/        ifn_data     = 0;
/*MT6163*/        data_ast     = 0;
/*MT6163*/        data_tx_test = 0;
/*MT6163*/        data_mode    = 0;
/*MT6163*/        data_dfm     = 0;
/*MT6163*/        data_dcxo    = 0;
/*MT6163*/     }
/*MT6163*/     else
/*MT6163*/  #endif
/*MT6163*/     {  /* normal RX */
/*MT6163*/        ifn_data     = l1d_rf.IFN_data&0x3FFF;  /* bit[13] is for DFM_SDM_IFM_ON, and bit[12:0] is for N_FRAC */
/*MT6163*/        data_ast     = L1D_RF_SetPData_SX( l1d_rf.band, 0/*RX*/, 0/*SX0*/ );
/*MT6163*/        data_tx_test = SDATA_TX_TEST_MODE|AA_TX_TEST_OW_EN;
/*MT6163*/        data_mode    = SDATA_MODE_RX_ON( l1d_rf.band );
/*MT6163*/        data_dfm     = SDATA_DFM_STBY_RX( l1d_rf.band )|ifn_data;
/*MT6163*/        data_dcxo    = (l1d_rf.AFC_data&0x1FFF)|SDATA_DCXO_CAFC_CTL_MASK;
/*MT6163*/     }
/*MT6163*/
/*MT6163*/  #if IS_DCXO_ENABLE
/*MT6163*/     #if IS_BSI_TRIG_OFFCHIP_BPI_SUPPORT || IS_BSI_TRIG_OFFCHIP_BSI_SWITCH_SUPPORT
/*MT6163*/     HWRITE_6_SDATA( ctrl_ast,           data_ast,            /* 0xF0, set partial BPI pins by sending BSI data */
/*MT6163*/                     ctrl_tx_test,       data_tx_test,        /* 0xAA, workaround for TX divider off */
/*MT6163*/                     ctrl_mode,          data_mode,           /* 0xD1 */
/*MT6163*/                     ctrl_dfm,           data_dfm,            /* 0x02 */
/*MT6163*/                     SCTRL_DFM_INIT_2G,  SDATA_DFM_INIT_2G,   /* 0x00 */
/*MT6163*/                     ctrl_dcxo,          data_dcxo );         /* 0xE1, set DCXO */
/*MT6163*/     #else
/*MT6163*/     HWRITE_5_SDATA( ctrl_tx_test,       data_tx_test,        /* 0xAA, workaround for TX divider off */
/*MT6163*/                     ctrl_mode,          data_mode,           /* 0xD1 */
/*MT6163*/                     ctrl_dfm,           data_dfm,            /* 0x02 */
/*MT6163*/                     SCTRL_DFM_INIT_2G,  SDATA_DFM_INIT_2G,   /* 0x00 */
/*MT6163*/                     ctrl_dcxo,          data_dcxo );         /* 0xE1, set DCXO */
/*MT6163*/     #endif
/*MT6163*/  #else /* VCTCXO */
/*MT6163*/     #if IS_BSI_TRIG_OFFCHIP_BPI_SUPPORT || IS_BSI_TRIG_OFFCHIP_BSI_SWITCH_SUPPORT
/*MT6163*/     HWRITE_5_SDATA( ctrl_ast,           data_ast,            /* 0xF0, set partial BPI pins by sending BSI data */
/*MT6163*/                     ctrl_tx_test,       data_tx_test,        /* 0xAA, workaround for TX divider off */
/*MT6163*/                     ctrl_mode,          data_mode,           /* 0xD1 */
/*MT6163*/                     ctrl_dfm,           data_dfm,            /* 0x02 */
/*MT6163*/                     SCTRL_DFM_INIT_2G,  SDATA_DFM_INIT_2G ); /* 0x00 */
/*MT6163*/     #else
/*MT6163*/     HWRITE_4_SDATA( ctrl_tx_test,       data_tx_test,        /* 0xAA, workaround for TX divider off */
/*MT6163*/                     ctrl_mode,          data_mode,           /* 0xD1 */
/*MT6163*/                     ctrl_dfm,           data_dfm,            /* 0x02 */
/*MT6163*/                     SCTRL_DFM_INIT_2G,  SDATA_DFM_INIT_2G ); /* 0x00 */
/*MT6163*/     #endif
/*MT6163*/  #endif
/*MT6163*/     (void)ctrl_dcxo; (void)data_dcxo; (void)ctrl_ast; (void)data_ast;
/*MT6163*/  }
/*MT6163*/  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6163*/
/*MT6163*/  void  L1D_RF_SetSData_SR1( void )
/*MT6163*/  {
/*MT6163*/     unsigned long rfn_data; /* CW01 */
/*MT6163*/     unsigned long ctrl_dfm = SCTRL_DFM;
/*MT6163*/     unsigned long data_dfm;
/*MT6163*/
/*MT6163*/     SETUP_SR1();
/*MT6163*/
/*MT6163*/  #if IS_RF_RX_DCOC_SUPPORT || IS_RF_TX_CALIBRATION_SUPPORT
/*MT6163*/     if( l1d_rf2.is_rx_cal )
/*MT6163*/     {  /* RXDCOC is on-going */
/*MT6163*/        rfn_data = SDATA_RXCAL_RFN[l1d_rf.band];
/*MT6163*/        data_dfm = SDATA_DFM_PLL_MASK|CW1_DFM_LG_COE_ON|rfn_data;
/*MT6163*/     }
/*MT6163*/     else if( l1d_rf2.is_tx_cal&0x10 )
/*MT6163*/     {  /* TXIQMM calibration is on-going */
/*MT6163*/        ctrl_dfm = SCTRL_RESERVED;
/*MT6163*/        rfn_data = 0;
/*MT6163*/        data_dfm = 0;
/*MT6163*/     }
/*MT6163*/     else
/*MT6163*/  #endif
/*MT6163*/     {  /* normal RX */
/*MT6163*/        rfn_data = l1d_rf.RFN_data;
/*MT6163*/        data_dfm = SDATA_DFM_PLL_MASK|CW1_DFM_LG_COE_ON|rfn_data;
/*MT6163*/     }
/*MT6163*/
/*MT6163*/     HWRITE_3_SDATA( ctrl_dfm,        data_dfm,  /* 0x01, select correct LNA input */
/*MT6163*/                     SCTRL_RESERVED,  0,         /* reserved */
/*MT6163*/                     SCTRL_RESERVED,  0 );       /* reserved */
/*MT6163*/  }
/*MT6163*/  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6163*/
/*MT6163*/  void  L1D_RF_SetSData_SR2( void )
/*MT6163*/  {
/*MT6163*/     unsigned long ctrl_mode         = SCTRL_MODE;
/*MT6163*/     unsigned long ctrl_rx_dc_offset = SCTRL_RX_OFFSET;
/*MT6163*/     unsigned long ctrl_rx_agc       = SCTRL_RX_GAIN;
/*MT6163*/     unsigned long data_mode;
/*MT6163*/     unsigned long data_rx_dc_offset;
/*MT6163*/     unsigned long data_rx_agc;
/*MT6163*/
/*MT6163*/     SETUP_SR2();
/*MT6163*/  #if IS_RF_RX_DCOC_SUPPORT || IS_RF_TX_CALIBRATION_SUPPORT
/*MT6163*/     if( l1d_rf2.is_rx_cal )
/*MT6163*/     {  /* RXDCOC is on-going*/
/*MT6163*/        data_mode            = SDATA_MODE_RXEN( l1d_rf.band );
/*MT6163*/        if( l1d_rf.rx_slots == 0x3 )
/*MT6163*/        {  /* calibrate the compensation voltage increment per DAC */
/*MT6163*/           data_rx_dc_offset = SDATA_RX_DCOFFSET_RXCAL[l1d_rf.cur_slot];
/*MT6163*/           data_rx_agc       = SDATA_RX_GAIN_TABLE_RXCAL[0];  /* Biquad gain=0dB, PGA gain=5dB */
/*MT6163*/        }
/*MT6163*/        else
/*MT6163*/        {
/*MT6163*/           data_rx_dc_offset = SDATA_RX_OFFSET_MASK;
/*MT6163*/           data_rx_agc       = SDATA_RX_GAIN_TABLE_RXCAL[l1d_rf.cur_slot];
/*MT6163*/        }
/*MT6163*/     }
/*MT6163*/     else if( l1d_rf2.is_tx_cal&0x10 )
/*MT6163*/     {  /* TXIQMM calibration is on-going */
/*MT6163*/        ctrl_mode         = SCTRL_RESERVED;
/*MT6163*/        ctrl_rx_dc_offset = SCTRL_RESERVED;
/*MT6163*/        ctrl_rx_agc       = SCTRL_RESERVED;
/*MT6163*/        data_mode         = 0;
/*MT6163*/        data_rx_dc_offset = 0;
/*MT6163*/        data_rx_agc       = 0;
/*MT6163*/     }
/*MT6163*/     else
/*MT6163*/  #endif
/*MT6163*/     {  /* normal RX */
/*MT6163*/        data_mode         = SDATA_MODE_RXEN( l1d_rf.band );
/*MT6163*/        data_rx_dc_offset = SDATA_RX_OFFSET_MASK|l1d_rf2.rx_dc_offset;
/*MT6163*/        data_rx_agc       = SDATA_RX_GAIN_MASK  |l1d_rf.AGC_data;
/*MT6163*/     }
/*MT6163*/
/*MT6163*/     if( IS_CONTINUOUS_RX_SLOT() )
/*MT6163*/     {
/*MT6163*/        HWRITE_4_SDATA( ctrl_rx_dc_offset,  data_rx_dc_offset,  /* 0x82, set RX DC offset */
/*MT6163*/                        ctrl_rx_agc,        data_rx_agc,        /* 0x83, set RX gain */
/*MT6163*/                        SCTRL_RESERVED,     0,                  /* reserved */
/*MT6163*/                        SCTRL_RESERVED,     0 );                /* reserved */
/*MT6163*/     }
/*MT6163*/     else
/*MT6163*/     {
/*MT6163*/        HWRITE_4_SDATA( ctrl_mode,          data_mode,          /* 0xD1, enable RX circuits */
/*MT6163*/                        ctrl_rx_dc_offset,  data_rx_dc_offset,  /* 0x82, set RX DC offset */
/*MT6163*/                        ctrl_rx_agc,        data_rx_agc,        /* 0x83, set RX gain */
/*MT6163*/                        SCTRL_RESERVED,     0 );                /* reserved */
/*MT6163*/     }
/*MT6163*/  }
/*MT6163*/  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6163*/
/*MT6163*/  void  L1D_RF_SetSData_SR3( void )
/*MT6163*/  {
/*MT6163*/     unsigned long ifn_data; /* CW02 */
/*MT6163*/     unsigned long ctrl_dfm  = SCTRL_DFM;
/*MT6163*/     unsigned long ctrl_mode = SCTRL_MODE;
/*MT6163*/     unsigned long ctrl_ast  = SCTRL_AST;
/*MT6163*/     unsigned long data_dfm;
/*MT6163*/     unsigned long data_mode;
/*MT6163*/     unsigned long data_ast;
/*MT6163*/
/*MT6163*/     SETUP_SR3();
/*MT6163*/
/*MT6163*/  #if IS_RF_RX_DCOC_SUPPORT || IS_RF_TX_CALIBRATION_SUPPORT
/*MT6163*/     if( l1d_rf2.is_rx_cal )
/*MT6163*/     {  /* RXDCOC is on-going */
/*MT6163*/        ifn_data  = SDATA_RXCAL_IFN[l1d_rf.band]&0x1FFF;
/*MT6163*/        data_dfm  = SDATA_DFM_SLEEP( l1d_rf.band )|ifn_data;
/*MT6163*/        data_mode = SDATA_MODE_IDLE( l1d_rf.band );
/*MT6163*/        data_ast  = L1D_RF_SetPData_SX( l1d_rf.band, 0/*RX*/, 1/*SX3*/ );
/*MT6163*/     }
/*MT6163*/     else if( l1d_rf2.is_tx_cal&0x10 )
/*MT6163*/     {  /* TXIQMM calibration is on-going */
/*MT6163*/        ctrl_dfm  = SCTRL_RESERVED;
/*MT6163*/        ctrl_mode = SCTRL_RESERVED;
/*MT6163*/        ctrl_ast  = SCTRL_RESERVED;
/*MT6163*/        data_dfm  = 0;
/*MT6163*/        data_mode = 0;
/*MT6163*/        data_ast  = 0;
/*MT6163*/     }
/*MT6163*/     else
/*MT6163*/  #endif
/*MT6163*/     {  /* normal RX */
/*MT6163*/        ifn_data  = l1d_rf.IFN_data&0x1FFF;
/*MT6163*/        data_dfm  = SDATA_DFM_SLEEP( l1d_rf.band )|ifn_data;
/*MT6163*/        data_mode = SDATA_MODE_IDLE( l1d_rf.band );
/*MT6163*/        data_ast  = L1D_RF_SetPData_SX( l1d_rf.band, 0/*RX*/, 1/*SX3*/ );
/*MT6163*/     }
/*MT6163*/
/*MT6163*/  #if IS_BSI_TRIG_OFFCHIP_BPI_SUPPORT || IS_BSI_TRIG_OFFCHIP_BSI_SWITCH_SUPPORT
/*MT6163*/     HWRITE_4_SDATA( ctrl_dfm,        data_dfm,   /* 0x02, turn off RX circuits */
/*MT6163*/                     ctrl_mode,       data_mode,  /* 0xD1, set to Idle */
/*MT6163*/                     ctrl_ast,        data_ast,   /* 0xF0, set partial BPI pins by sending BSI data */
/*MT6163*/                     SCTRL_RESERVED,  0 );        /* reserved */
/*MT6163*/  #else
/*MT6163*/     HWRITE_3_SDATA( ctrl_dfm,        data_dfm,   /* 0x02, turn off RX circuits */
/*MT6163*/                     ctrl_mode,       data_mode,  /* 0xD1, set to Idle */
/*MT6163*/                     SCTRL_RESERVED,  0 );        /* reserved */
/*MT6163*/     (void)ctrl_ast; (void)data_ast;
/*MT6163*/  #endif
/*MT6163*/  }
/*MT6163*/  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6163*/
/*MT6163*/  void  L1D_RF_SetSData_FSIWinOff_SR3( int idx )
/*MT6163*/  {
/*MT6163*/     int event_idx = AGCIDX( FS_RXWIN_IDX+idx );
/*MT6163*/     int data_idx  = AGCDTIDX( FS_RXWIN_IDX+idx );
/*MT6163*/
/*MT6163*/     /* Run the same BSI setup as normal SR3 except for different BSI resource allocation */
/*MT6163*/  #if IS_BSI_TRIG_OFFCHIP_BPI_SUPPORT || IS_BSI_TRIG_OFFCHIP_BSI_SWITCH_SUPPORT
/*MT6163*/     HWRITE_4_SDATA( SCTRL_DFM,       SDATA_DFM_SLEEP( l1d_rf.band )|(l1d_rf.IFN_data&0x1FFF),    /* 0x02, turn off RX circuits */
/*MT6163*/                     SCTRL_MODE,      SDATA_MODE_IDLE( l1d_rf.band ),                             /* 0xD1, set to Idle */
/*MT6163*/                     SCTRL_AST,       L1D_RF_SetPData_SX( l1d_rf.band, 0/*RX*/, 1/*SX3*/ ),       /* 0xF0, set partial BPI pins by sending BSI data */
/*MT6163*/                     SCTRL_RESERVED,  0 );                                                        /* reserved */
/*MT6163*/  #else
/*MT6163*/     HWRITE_3_SDATA( SCTRL_DFM,       SDATA_DFM_SLEEP( l1d_rf.band )|(l1d_rf.IFN_data&0x1FFF),    /* 0x02, turn off RX circuits */
/*MT6163*/                     SCTRL_MODE,      SDATA_MODE_IDLE( l1d_rf.band ),                             /* 0xD1, set to Idle */
/*MT6163*/                     SCTRL_RESERVED,  0 );                                                        /* reserved */
/*MT6163*/  #endif
/*MT6163*/  }
/*MT6163*/  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6163*/
/*MT6163*/  void  L1D_RF_SetSData_ST0( void )
/*MT6163*/  {
/*MT6163*/     unsigned long ctrl_dcxo = SCTRL_DCXO_CAFC_CTRL;
/*MT6163*/     unsigned long ifn_data  = l1d_rf.IFN_data&0x1FFF; /* CW02 */
/*MT6163*/     unsigned long data_ast  = L1D_RF_SetPData_SX( l1d_rf.band, 1/*TX*/, 0/*SX0*/ );
/*MT6163*/
/*MT6163*/     SETUP_ST0();
/*MT6163*/
/*MT6163*/  #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6163*/     if( l1d_rf2.is_tx_cal&0x10 )
/*MT6163*/     {  /* TXIQMM Calibration is on-going */
/*MT6163*/        ifn_data = SDATA_CW02_DFM_PLL_TXCAL[l1d_rf.band];
/*MT6163*/     }
/*MT6163*/  #endif
/*MT6163*/
/*MT6163*/  #if IS_TDD_DUAL_MODE_SUPPORT && IS_DCXO_ENABLE
/*MT6163*/     ctrl_dcxo = l1d_rf2.is_bsi_afc_active ? SCTRL_DCXO_CAFC_CTRL : SCTRL_RESERVED;
/*MT6163*/  #endif
/*MT6163*/
/*MT6163*/  #if IS_DCXO_ENABLE
/*MT6163*/     #if IS_BSI_TRIG_OFFCHIP_BPI_SUPPORT || IS_BSI_TRIG_OFFCHIP_BSI_SWITCH_SUPPORT
/*MT6163*/     HWRITE_6_SDATA( SCTRL_AST,             data_ast,                                             /* 0xF0, set partial BPI pins by sending BSI data */
/*MT6163*/                     SCTRL_MODE,            SDATA_MODE_TX_ON( l1d_rf.band ),                      /* 0xD1 */
/*MT6163*/                     SCTRL_DFM,             SDATA_DFM_STBY_TX( l1d_rf.band )|ifn_data,            /* 0x02 */
/*MT6163*/                     SCTRL_TX_CONFIG,       SDATA_TX_CFG2,                                        /* 0xC0, low power mode threshold */
/*MT6163*/                     ctrl_dcxo,             (l1d_rf.AFC_data&0x1FFF)|SDATA_DCXO_CAFC_CTL_MASK,    /* 0xE1, set DCXO */
/*MT6163*/                     SCTRL_RESERVED,        0 );
/*MT6163*/     #else
/*MT6163*/     HWRITE_5_SDATA( SCTRL_MODE,            SDATA_MODE_TX_ON( l1d_rf.band ),                      /* 0xD1 */
/*MT6163*/                     SCTRL_DFM,             SDATA_DFM_STBY_TX( l1d_rf.band )|ifn_data,            /* 0x02 */
/*MT6163*/                     SCTRL_TX_CONFIG,       SDATA_TX_CFG2,                                        /* 0xC0, low power mode threshold */
/*MT6163*/                     ctrl_dcxo,             (l1d_rf.AFC_data&0x1FFF)|SDATA_DCXO_CAFC_CTL_MASK,    /* 0xE1, set DCXO */
/*MT6163*/                     SCTRL_RESERVED,        0 );
/*MT6163*/     #endif
/*MT6163*/  #else /* VCTCXO */
/*MT6163*/     #if IS_BSI_TRIG_OFFCHIP_BPI_SUPPORT || IS_BSI_TRIG_OFFCHIP_BSI_SWITCH_SUPPORT
/*MT6163*/     HWRITE_5_SDATA( SCTRL_AST,             data_ast,                                             /* 0xF0, set partial BPI pins by sending BSI data */
/*MT6163*/                     SCTRL_MODE,            SDATA_MODE_TX_ON( l1d_rf.band ),                      /* 0xD1 */
/*MT6163*/                     SCTRL_DFM,             SDATA_DFM_STBY_TX( l1d_rf.band )|ifn_data,            /* 0x02 */
/*MT6163*/                     SCTRL_TX_CONFIG,       SDATA_TX_CFG2,                                        /* 0xC0, low power mode threshold */
/*MT6163*/                     SCTRL_RESERVED,        0 );
/*MT6163*/     #else
/*MT6163*/     HWRITE_4_SDATA( SCTRL_MODE,            SDATA_MODE_TX_ON( l1d_rf.band ),                      /* 0xD1 */
/*MT6163*/                     SCTRL_DFM,             SDATA_DFM_STBY_TX( l1d_rf.band )|ifn_data,            /* 0x02 */
/*MT6163*/                     SCTRL_TX_CONFIG,       SDATA_TX_CFG2,                                        /* 0xC0, low power mode threshold */
/*MT6163*/                     SCTRL_RESERVED,        0 );
/*MT6163*/     #endif
/*MT6163*/  #endif
/*MT6163*/  (void)ctrl_dcxo; (void)data_ast;
/*MT6163*/  }
/*MT6163*/  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6163*/
/*MT6163*/  void  L1D_RF_SetSData_ST1( void )
/*MT6163*/  {
/*MT6163*/     unsigned long rfn_data   = l1d_rf.RFN_data;
/*MT6163*/     unsigned long dfm_lg_coe = l1d_rf2.is_isotpol ? 0 : CW1_DFM_LG_COE_ON;
/*MT6163*/
/*MT6163*/     SETUP_ST1();
/*MT6163*/
/*MT6163*/  #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6163*/     if( l1d_rf2.is_tx_cal&0x10 )
/*MT6163*/     {  /* TXIQMM Calibration is on-going */
/*MT6163*/        rfn_data = SDATA_CW01_DFM_PLL_TXCAL[l1d_rf.band];
/*MT6163*/     }
/*MT6163*/  #endif
/*MT6163*/
/*MT6163*/     HWRITE_3_SDATA( SCTRL_DFM,             SDATA_DFM_PLL_MASK|dfm_lg_coe|rfn_data,      /* 0x01 */
/*MT6163*/                     SCTRL_TX_TEST,         SDATA_TX_TEST_EN,                            /* 0xA1, workaround for LB */
/*MT6163*/                     SCTRL_RESERVED,        0 );                                         /* reserved */
/*MT6163*/  }
/*MT6163*/  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6163*/
/*MT6163*/  void  L1D_RF_SetSData_ST2( void )
/*MT6163*/  {
/*MT6163*/     unsigned long tx_cfg = (l1d_rf.band <  FrequencyBand1800) ? A9_TX_CFG_LB : A9_TX_CFG_HB;
/*MT6163*/     unsigned char is_HB  = (l1d_rf.band >= FrequencyBand1800) ? 1 : 0;
/*MT6163*/
/*MT6163*/     SETUP_ST2();
/*MT6163*/
/*MT6163*/     HWRITE_4_SDATA( SCTRL_TX_CONFIG,       SDATA_TX_CFG|tx_cfg,                         /* 0xA9 */
/*MT6163*/                     SCTRL_TX_GAIN_LUT,     SDATA_TX_GAIN_LUT[is_HB][0],                 /* 0xC5, LUT1 */
/*MT6163*/                     SCTRL_TX_GAIN_LUT,     SDATA_TX_GAIN_LUT[is_HB][1],                 /* 0xC6, LUT2 */
/*MT6163*/                     SCTRL_TX_GAIN_LUT,     SDATA_TX_GAIN_LUT[is_HB][2] );               /* 0xC7, LUT3 */
/*MT6163*/  }
/*MT6163*/  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6163*/
/*MT6163*/  void  L1D_RF_SetSData_ST2B( void )
/*MT6163*/  {
/*MT6163*/     unsigned long sdata_dfm_sel_g8;
/*MT6163*/     unsigned long d1_tx_mode;
/*MT6163*/     unsigned long tx_gain;
/*MT6163*/     unsigned long test_mode = (l1d_rf.band<FrequencyBand1800) ? AA_TX_TEST_MODE : 0;
/*MT6163*/
/*MT6163*/     SETUP_ST2B_ST2M();
/*MT6163*/
/*MT6163*/     tx_gain = L1D_RF_SetTxGainWrite( l1d_rf.tx_mod_type2, l1d_rf.cur_slot, l1d_rf2.tx_power[l1d_rf.cur_slot], (FrequencyBand)l1d_rf.band );
/*MT6163*/
/*MT6163*/  #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6163*/     if( l1d_rf2.is_tx_cal&0x10 )
/*MT6163*/     {  /* TXIQMM Calibration is on-going */
/*MT6163*/        int idx = (l1d_rf2.is_tx_cal&0x0F)<2 ? 0 : (l1d_rf2.is_tx_cal&0x0F)-1;
/*MT6163*/     #if IS_BBTXRX_CHIP_DESIGN_VER_3
/*MT6163*/        tx_gain = (l1d_rf2.is_tx_cal&0x0F)<2 ? SDATA_A4_GAIN_TABLE_TXCAL[idx] : L1D_RF_SetTxGainWrite( 0x03 /*tx_mod_type2*/, 0 /*cur_slot*/, l1d_rf2.tx_cal_power_index, (FrequencyBand)l1d_rf.band );
/*MT6163*/     #else
/*MT6163*/        tx_gain = SDATA_A4_GAIN_TABLE_TXCAL[idx];
/*MT6163*/     #endif
/*MT6163*/     }
/*MT6163*/     else
/*MT6163*/     {  /* Normal: use original tx_gain */
/*MT6163*/        if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 ) /* Compensate TXIQ for EPSK slot */
/*MT6163*/        {  L1D_RF_SetEPSKTxIQ( (signed short)l1d_rf.cur_slot, tx_gain );  }
/*MT6163*/     }
/*MT6163*/  #endif
/*MT6163*/
/*MT6163*/     if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6163*/     {  /* 8PSK */
/*MT6163*/        sdata_dfm_sel_g8 = SDATA_DFM_SEL_EPSK;
/*MT6163*/        d1_tx_mode       = D1_TX_EDGE;
/*MT6163*/        /* test_mode setting are only on for LB EPSK TX bursts */
/*MT6163*/     }
/*MT6163*/     else
/*MT6163*/     {  /* GMSK */
/*MT6163*/        sdata_dfm_sel_g8 = SDATA_DFM_SEL_GMSK;
/*MT6163*/        d1_tx_mode       = D1_TX_GSM;
/*MT6163*/        test_mode        = 0;
/*MT6163*/     }
/*MT6163*/
/*MT6163*/     HWRITE_4_SDATA( SCTRL_TX_TEST,         SDATA_TX_TEST_MODE|test_mode,                /* 0xAA, workaround for LB */
/*MT6163*/                     SCTRL_DFM_G8,          sdata_dfm_sel_g8,                            /* 0x13, set DFM to GSM/EDGE mode */
/*MT6163*/                     SCTRL_MODE,            SDATA_MODE_TXEN( l1d_rf.band )|d1_tx_mode,   /* 0xD1, set TX mode to GSM/EDGE */
/*MT6163*/                     SCTRL_TX_GAINWRITE,    SDATA_TX_GAIN_MASK|tx_gain );                /* 0xA4, set TX gain & trigger detector */
/*MT6163*/  }
/*MT6163*/  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6163*/
/*MT6163*/  void  L1D_RF_SetSData_ST2M( void )
/*MT6163*/  {
/*MT6163*/     unsigned long sdata_dfm_sel_g8;
/*MT6163*/     unsigned long d1_tx_mode;
/*MT6163*/     unsigned long tx_gain;
/*MT6163*/     unsigned long test_mode = (l1d_rf.band<FrequencyBand1800) ? AA_TX_TEST_MODE : 0;
/*MT6163*/
/*MT6163*/     SETUP_ST2B_ST2M();
/*MT6163*/
/*MT6163*/     tx_gain = L1D_RF_SetTxGainWrite( l1d_rf.tx_mod_type2, l1d_rf.cur_slot, l1d_rf2.tx_power[l1d_rf.cur_slot], (FrequencyBand)l1d_rf.band );
/*MT6163*/
/*MT6163*/  #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6163*/     if( l1d_rf2.is_tx_cal&0x10 )
/*MT6163*/     {  /* TXIQMM Calibration is on-going */
/*MT6163*/        int idx = (l1d_rf2.is_tx_cal&0x0F)<2 ? 0 : (l1d_rf2.is_tx_cal&0x0F)-1;
/*MT6163*/     #if IS_BBTXRX_CHIP_DESIGN_VER_3
/*MT6163*/        tx_gain = (l1d_rf2.is_tx_cal&0x0F)<2 ? SDATA_A4_GAIN_TABLE_TXCAL[idx] : L1D_RF_SetTxGainWrite( 0x03 /*tx_mod_type2*/, 1 /*cur_slot*/, l1d_rf2.tx_cal_power_index, (FrequencyBand)l1d_rf.band );
/*MT6163*/     #else
/*MT6163*/        tx_gain = SDATA_A4_GAIN_TABLE_TXCAL[idx];
/*MT6163*/     #endif
/*MT6163*/     }
/*MT6163*/     else
/*MT6163*/     {  /* Normal: use original tx_gain */
/*MT6163*/        if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 ) /* Compensate TXIQ for EPSK slot */
/*MT6163*/        {  L1D_RF_SetEPSKTxIQ( (signed short)l1d_rf.cur_slot, tx_gain );  }
/*MT6163*/     }
/*MT6163*/  #endif
/*MT6163*/
/*MT6163*/     if( (l1d_rf.change)&(1<<l1d_rf.cur_slot) )
/*MT6163*/     {  /* modulation type changes */
/*MT6163*/        if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6163*/        {  /* change g->8 */
/*MT6163*/           sdata_dfm_sel_g8 = SDATA_DFM_SEL_EPSK;
/*MT6163*/           d1_tx_mode       = D1_TX_EDGE;
/*MT6163*/           /* test_mode setting are only on for LB EPSK TX bursts */
/*MT6163*/        }
/*MT6163*/        else
/*MT6163*/        {  /* change 8->g */
/*MT6163*/           sdata_dfm_sel_g8 = SDATA_DFM_SEL_GMSK;
/*MT6163*/           d1_tx_mode       = D1_TX_GSM;
/*MT6163*/           test_mode        = 0;
/*MT6163*/        }
/*MT6163*/
/*MT6163*/        HWRITE_4_SDATA( SCTRL_TX_TEST,      SDATA_TX_TEST_MODE|test_mode,                /* 0xAA, workaround for LB */
/*MT6163*/                        SCTRL_DFM_G8,       sdata_dfm_sel_g8,                            /* 0x13, set DFM to GSM/EDGE mode */
/*MT6163*/                        SCTRL_MODE,         SDATA_MODE_TXEN( l1d_rf.band )|d1_tx_mode,   /* 0xD1, set TX mode to GSM/EDGE */
/*MT6163*/                        SCTRL_TX_GAINWRITE, SDATA_TX_GAIN_MASK|tx_gain );                /* 0xA4, set TX gain & trigger detector */
/*MT6163*/     }
/*MT6163*/     else
/*MT6163*/     {  /* modulation type identical */
/*MT6163*/        HWRITE_4_SDATA( SCTRL_TX_GAINWRITE, SDATA_TX_GAIN_MASK|tx_gain,                  /* 0xA4, set TX gain & trigger detector */
/*MT6163*/                        SCTRL_RESERVED,     0,                                           /* reserved */
/*MT6163*/                        SCTRL_RESERVED,     0,                                           /* reserved */
/*MT6163*/                        SCTRL_RESERVED,     0 );                                         /* reserved */
/*MT6163*/     }
/*MT6163*/  }
/*MT6163*/  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6163*/
/*MT6163*/  void  L1D_RF_SetSData_ST3( void )
/*MT6163*/  {
/*MT6163*/     unsigned long data_ast = L1D_RF_SetPData_SX( l1d_rf.band, 1/*TX*/, 1/*SX3*/ );
/*MT6163*/
/*MT6163*/     SETUP_ST3();
/*MT6163*/
/*MT6163*/  #if IS_BSI_TRIG_OFFCHIP_BPI_SUPPORT || IS_BSI_TRIG_OFFCHIP_BSI_SWITCH_SUPPORT
/*MT6163*/     HWRITE_4_SDATA(    SCTRL_MODE,         SDATA_MODE_TX_ON( l1d_rf.band ),             /* 0xD1, disable TX */
/*MT6163*/                        SCTRL_DFM,          SDATA_DFM_SLEEP( l1d_rf.band ),              /* 0x02, power down DFM */
/*MT6163*/                        SCTRL_MODE,         SDATA_MODE_IDLE( l1d_rf.band ),              /* 0xD1, set to Idle */
/*MT6163*/                        SCTRL_AST,          data_ast );                                  /* 0xF0, set partial BPI pins by sending BSI data */
/*MT6163*/  #else
/*MT6163*/     HWRITE_3_SDATA(    SCTRL_MODE,         SDATA_MODE_TX_ON( l1d_rf.band ),             /* 0xD1, disable TX */
/*MT6163*/                        SCTRL_DFM,          SDATA_DFM_SLEEP( l1d_rf.band ),              /* 0x02, power down DFM */
/*MT6163*/                        SCTRL_MODE,         SDATA_MODE_IDLE( l1d_rf.band ) );            /* 0xD1, set to Idle */
/*MT6163*/  (void)data_ast;
/*MT6163*/  #endif
/*MT6163*/  }
/*MT6163*/  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#if IS_RF_MT6280RF
/*MT6280RF*/
/*MT6280RF*/ /*..........................................................*/
/*MT6280RF*/ /*  Define Alias and Table                                  */
/*MT6280RF*/ /*..........................................................*/
/*MT6280RF*/
/*MT6280RF*/ #define  SCTRL_SLEEP2STANDBY           SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_STANDBY2SLEEP           SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_RXCAL_MODE              SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_RXBURST_MODE            SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_RX2SLEEP                SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_TXCAL_MODE              SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_TXBURST_MODE            SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_TX2SLEEP                SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_TXPORT                  SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_PLL                     SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_LFBW                    SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_AGC_DCO                 SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_DCO_MAN                 SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_TXGAIN                  SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_TEMP_MEAS               SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SDATA_SLEEP2STANDBY           BSI_CW(0x01, 0x00000)  /* DYN_EN=0 */
/*MT6280RF*/ #define  SDATA_STANDBY2SLEEP           BSI_CW(0x01, 0x00200)  /* DYN_EN=1 */
/*MT6280RF*/ #define  SDATA_RXCAL_MODE              BSI_CW(0x01, 0x10200)  /* MODE=0001|LNA=Variable|DYN_EN=1|BAND=Variable */
/*MT6280RF*/ #define  SDATA_RXBURST_MODE            BSI_CW(0x01, 0x20200)  /* MODE=0010|LNA=Variable|DYN_EN=1|BAND=Variable */
/*MT6280RF*/ #define  SDATA_RX2SLEEP                BSI_CW(0x01, 0x00200)  /* MODE=0000|LNA=Variable|DYN_EN=1|BAND=Variable */
/*MT6280RF*/ #define  SDATA_TXCAL_MODE              BSI_CW(0x01, 0x30200)  /* MODE=0011|LNA=0       |DYN_EN=1|BAND=Variable */
/*MT6280RF*/ #define  SDATA_TXBURST_MODE            BSI_CW(0x01, 0x40200)  /* MODE=0100|LNA=0       |DYN_EN=1|BAND=Variable */
/*MT6280RF*/ #define  SDATA_TX2SLEEP                BSI_CW(0x01, 0x00200)  /* MODE=0000|LNA=0       |DYN_EN=1|BAND=Variable */
/*MT6280RF*/ #define  SDATA_DCO_MAN                 BSI_CW(0x17, 0x04000)  /* CW23 : RXIF_DCOC_MAN=1, DCO Manual mode */
/*MT6280RF*/ #if IS_USE_INTERNAL_TEMP_SENSOR
/*MT6280RF*/ #define  SDATA_TEMP_MEAS               BSI_CW(0x10, 0x002E4)  /* CW16 : THADC_EXT = 0 (Only Internal temp sensor measurement updates TXL_INIT_S bus for SX Calibration) */
/*MT6280RF*/ #else
/*MT6280RF*/ #define  SDATA_TEMP_MEAS               BSI_CW(0x10, 0x002E5)  /* CW16 : THADC_EXT = 1 (external temp sensor measurement */
/*MT6280RF*/ #endif
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/ #define  SCTRL_CLK_DIV2_EN             SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_CURRENT_CONTROL         SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_TEMP_E1_SW_WORKAROUND   SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_TXIFLDOC                SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_TXQPATH                 SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SDATA_CLK_DIV2_EN             BSI_CW(0x3C, 0x00C1F)  /* CW60 : CLK_DIV2_EN=1,   ADC to RXDYN clock correct freq. */
/*MT6280RF*/ #define  SDATA_CURRENT_CONTROL_ON      BSI_CW(0xF5, 0x80003)  /* CW245: Add always on current control */
/*MT6280RF*/ #define  SDATA_CURRENT_CONTROL_OFF     BSI_CW(0xF5, 0x80000)  /* CW245: Add always off current control */
/*MT6280RF*/ #define  SDATA_TEMP_CW37               BSI_CW(0x25, 0x20730)  /* CW37 : ADC reset issue */
/*MT6280RF*/ #define  SDATA_TXIFLDOC                BSI_CW(0x23, 0x1040F)  /* CW35 : ORFS degradation at LT sw workaround */
/*MT6280RF*/ #else
/*MT6280RF*/ #define  SDATA_TXIFLDOC                BSI_CW(0x23, 0x1058F)  /* CW35 : get more timing margin for both Q-path on/off option */
/*MT6280RF*/ #define  SCTRL_TXIFLDOC                SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_CKG_LDO_RCODE           SCTRL_WORD(0,29)
/*MT6280RF*/ #define  SCTRL_TXQPATH                 SCTRL_WORD(0,29)
/*MT6280RF*/ #endif
/*MT6280RF*/
/*MT6280RF*/ CONST unsigned long  SDATA_RX_LNA_BAND_SEL[5] =
/*MT6280RF*/ {  /* RX LNA & Band Selection */
/*MT6280RF*/    0,                      /* GSM  450 no support */
/*MT6280RF*/    (GSM850_PATH_SEL<<12)|0x0,  /* GSM  850, LNA4 */
/*MT6280RF*/    (   GSM_PATH_SEL<<12)|0x1,  /* GSM  900, LNA2 */
/*MT6280RF*/    (   DCS_PATH_SEL<<12)|0x2,  /* DCS 1800, LNA1 */
/*MT6280RF*/    (   PCS_PATH_SEL<<12)|0x3,  /* PCS 1900, LNA3 */
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ const unsigned long  SDATA_BAND_SEL[5] =
/*MT6280RF*/ {  /* TX Band Selection */
/*MT6280RF*/    0,    /* GSM  450 no support */
/*MT6280RF*/    0x0,  /* GSM  850 */
/*MT6280RF*/    0x1,  /* GSM  900 */
/*MT6280RF*/    0x2,  /* DCS 1800 */
/*MT6280RF*/    0x3,  /* PCS 1900 */
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ /*..........................................................*/
/*MT6280RF*/ /* Serial Interface Implement                               */
/*MT6280RF*/ /*..........................................................*/
/*MT6280RF*/
/*MT6280RF*/ void  L1D_RF_SetSData_SR0( void )
/*MT6280RF*/ {
/*MT6280RF*/ }
/*MT6280RF*/
/*MT6280RF*/ void  L1D_RF_SetSData_SR1( void )
/*MT6280RF*/ {
/*MT6280RF*/    #if IS_CHIP_MT6280_S00
/*MT6280RF*/    SETUP_SR1();
/*MT6280RF*/
/*MT6280RF*/    HWRITE_11_SDATA( SCTRL_DCO_MAN,                SDATA_DCO_MAN,                     /* CW23 : DC Offset Manual mode */
/*MT6280RF*/                     SCTRL_CLK_DIV2_EN,            SDATA_CLK_DIV2_EN,                 /* CW60 : CLK_DIV2_EN=1,   ADC to RXDYN clock correct freq. */
/*MT6280RF*/                     SCTRL_PLL,                    l1d_rf.RFN_data,                   /* CW99 : RX PLL, comb. w addr. in PLL setting */
/*MT6280RF*/                     SCTRL_PLL,                    l1d_rf.IFN_data,                   /* CW100: RX PLL, comb. w addr. in PLL setting */
/*MT6280RF*/                     SCTRL_RXCAL_MODE,             SDATA_RXCAL_MODE|SDATA_RX_LNA_BAND_SEL[l1d_rf.band], /* CW1  : 2GRX Cal. Mode | Band */
/*MT6280RF*/                     SCTRL_TEMP_E1_SW_WORKAROUND,  SDATA_TEMP_CW37,                   /* CW37 : ADC reset issue */
/*MT6280RF*/                     SCTRL_RESERVED,               0,                                 /* reserved */
/*MT6280RF*/                     SCTRL_RESERVED,               0,                                 /* reserved */
/*MT6280RF*/                     SCTRL_RESERVED,               0,                                 /* reserved */
/*MT6280RF*/                     SCTRL_RESERVED,               0,                                 /* reserved */
/*MT6280RF*/                     SCTRL_RESERVED,               0                               ); /* reserved */
/*MT6280RF*/    #else
/*MT6280RF*/    SETUP_SR1();
/*MT6280RF*/
/*MT6280RF*/    HWRITE_11_SDATA( SCTRL_DCO_MAN,                SDATA_DCO_MAN,                     /* CW23 : DC Offset Manual mode */
/*MT6280RF*/                     SCTRL_PLL,                    l1d_rf.RFN_data,                   /* CW99 : RX PLL, comb. w addr. in PLL setting */
/*MT6280RF*/                     SCTRL_PLL,                    l1d_rf.IFN_data,                   /* CW100: RX PLL, comb. w addr. in PLL setting */
/*MT6280RF*/                     SCTRL_RXCAL_MODE,             SDATA_RXCAL_MODE|SDATA_RX_LNA_BAND_SEL[l1d_rf.band], /* CW1  : 2GRX Cal. Mode | Band */
/*MT6280RF*/                     SCTRL_RESERVED,               0,                                 /* reserved */
/*MT6280RF*/                     SCTRL_RESERVED,               0,                                 /* reserved */
/*MT6280RF*/                     SCTRL_RESERVED,               0,                                 /* reserved */
/*MT6280RF*/                     SCTRL_RESERVED,               0,                                 /* reserved */
/*MT6280RF*/                     SCTRL_RESERVED,               0,                                 /* reserved */
/*MT6280RF*/                     SCTRL_RESERVED,               0,                                 /* reserved */
/*MT6280RF*/                     SCTRL_RESERVED,               0                               ); /* reserved */
/*MT6280RF*/    #endif
/*MT6280RF*/ }
/*MT6280RF*/
/*MT6280RF*/ void  L1D_RF_SetSData_SR2( void )
/*MT6280RF*/ {
/*MT6280RF*/    SETUP_SR2();
/*MT6280RF*/
/*MT6280RF*/    if(IS_CONTINUOUS_RX_SLOT())
/*MT6280RF*/    {
/*MT6280RF*/       HWRITE_4_SDATA( SCTRL_AGC_DCO,        l1d_rf.AGC_data,                 /* CW12 : RX Gain + DC Offset, comb. w addr. in gain setting*/
/*MT6280RF*/                       SCTRL_RESERVED,       0,                               /* reserved */
/*MT6280RF*/                       SCTRL_RESERVED,       0,                               /* reserved */
/*MT6280RF*/                       SCTRL_RESERVED,       0                              );/* reserved */
/*MT6280RF*/    }
/*MT6280RF*/    else
/*MT6280RF*/    {
/*MT6280RF*/       HWRITE_4_SDATA( SCTRL_AGC_DCO,        l1d_rf.AGC_data,                 /* CW12 : RX Gain + DC Offset, comb. w addr. in gain setting*/
/*MT6280RF*/                       SCTRL_RXBURST_MODE,   SDATA_RXBURST_MODE|SDATA_RX_LNA_BAND_SEL[l1d_rf.band],  /* CW1 : 2GRX Burst Mode | Band */
/*MT6280RF*/                       SCTRL_TEMP_MEAS,      SDATA_TEMP_MEAS,                 /* CW16 : trigger RF to measure temperature */
/*MT6280RF*/                       SCTRL_RESERVED,       0                              );/* reserved */
/*MT6280RF*/    }
/*MT6280RF*/ }
/*MT6280RF*/
/*MT6280RF*/ void  L1D_RF_SetSData_SR3( void )
/*MT6280RF*/ {
/*MT6280RF*/    #if IS_CHIP_MT6280_S00
/*MT6280RF*/    SETUP_SR3();
/*MT6280RF*/
/*MT6280RF*/    HWRITE_3_SDATA( SCTRL_IDLE,                  SDATA_RX2SLEEP|SDATA_BAND_SEL[l1d_rf.band],    /* CW1: Sleep Mode */
/*MT6280RF*/                    SCTRL_TEMP_E1_SW_WORKAROUND, POR_CW37,                                      /* CW37 */
/*MT6280RF*/                    SCTRL_RESERVED,              0                                           ); /* reserved */
/*MT6280RF*/    #else
/*MT6280RF*/    SETUP_SR3();
/*MT6280RF*/
/*MT6280RF*/    HWRITE_3_SDATA( SCTRL_IDLE,                  SDATA_RX2SLEEP|SDATA_BAND_SEL[l1d_rf.band],    /* CW1: Sleep Mode */
/*MT6280RF*/                    SCTRL_RESERVED,              0,                                             /* reserved */
/*MT6280RF*/                    SCTRL_RESERVED,              0                                           ); /* reserved */
/*MT6280RF*/    #endif
/*MT6280RF*/ }
/*MT6280RF*/
/*MT6280RF*/ void  L1D_RF_SetSData_ST0( void )
/*MT6280RF*/ {
/*MT6280RF*/ }
/*MT6280RF*/
/*MT6280RF*/ void  L1D_RF_SetSData_ST1( void )
/*MT6280RF*/ {
/*MT6280RF*/    unsigned short codetype     = 0;
/*MT6280RF*/    unsigned short Nint         = 0;
/*MT6280RF*/    unsigned long  Nfrac        = 0;
/*MT6280RF*/    long  cw34,cw80,cw97,cw98,cw75;
/*MT6280RF*/    #if IS_CHIP_MT6280_S00
/*MT6280RF*/    long  cw33;
/*MT6280RF*/    #else
/*MT6280RF*/    unsigned short qpath_on     = 0;
/*MT6280RF*/    long  cw117,cw9;
/*MT6280RF*/    #endif
/*MT6280RF*/
/*MT6280RF*/    SETUP_ST1();
/*MT6280RF*/
/*MT6280RF*/    /* l1d_rf.RFN_data = cw95, l1d_rf.band   */
/*MT6280RF*/    /* l1d_rf.IFN_data = cw96, l1d_rf2.arfcn */
/*MT6280RF*/    L1D_RF_GetTxKDCOCAL2ndSetting( l1d_rf.band, (l1d_rf2.arfcn&0x3FF), &cw97, &cw98);
/*MT6280RF*/
/*MT6280RF*/    Nint         = (l1d_rf.RFN_data&(0xFF<<12))>>12;
/*MT6280RF*/    Nfrac        = ( (l1d_rf.RFN_data&0xFFF)<<11 ) | ( (l1d_rf.IFN_data&(0x7FF<<9))>>9 );
/*MT6280RF*/
/*MT6280RF*/    codetype     = L1D_RF_GetTxDCOSCACodeTypeSetting( Nint, Nfrac );
/*MT6280RF*/
/*MT6280RF*/    #if IS_CHIP_MT6280_S00
/*MT6280RF*/    cw33 = ( l1d_rf.band<FrequencyBand1800 ) ? (POR_CW33|  (1<<2)  ) : (POR_CW33);
/*MT6280RF*/    #else
/*MT6280RF*/    if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6280RF*/    {
/*MT6280RF*/       qpath_on = ( l1d_rf.band<FrequencyBand1800 ) ? (IS_Q_PATH_ON<<5) : (0x0<<5);
/*MT6280RF*/    }
/*MT6280RF*/    cw117 = qpath_on ? POR_CW117 : POR_CW117;
/*MT6280RF*/    cw9  = (long) ((POR_CW9&0xFFFFFC7) | (0x3<<3));
/*MT6280RF*/    #endif
/*MT6280RF*/    cw34 = ( l1d_rf.band<FrequencyBand1800 ) ? (POR_CW34|TX_2GLB_EN) : (POR_CW34|TX_2GHB_EN);
/*MT6280RF*/    cw80 = (long) (POR_CW80 | (codetype&0xFFF)<<8);
/*MT6280RF*/    cw75 = (long) (POR_CW75);
/*MT6280RF*/
/*MT6280RF*/    #if IS_CHIP_MT6280_S00
/*MT6280RF*/    HWRITE_11_SDATA( SCTRL_CURRENT_CONTROL, SDATA_CURRENT_CONTROL_ON,  /* CW245: Add always on current control */
/*MT6280RF*/                     SCTRL_TXIFLDOC,        SDATA_TXIFLDOC,            /* CW35 : ORFS degradation at LT sw workaround */
/*MT6280RF*/                     SCTRL_TXQPATH,         BSI_CW(0x21, cw33),        /* CW33 : 2G TX qpath on */
/*MT6280RF*/                     SCTRL_TXPORT,          BSI_CW(0x22, cw34),        /* CW34 : Enable correct TX band output */
/*MT6280RF*/                     SCTRL_PLL,             l1d_rf.RFN_data,           /* CW95 : STX NMMD0: STX_MMD_SDM_NINT[7:0], STX_MMD_SDM_NFRAC[22:11] */
/*MT6280RF*/                     SCTRL_PLL,             l1d_rf.IFN_data,           /* CW96 : STX NMMD0, DA_OFFSET: STX_MMD_SDM_NFRAC[10:0], STX_MMD_DA_OFFSET[7:0] */
/*MT6280RF*/                     SCTRL_PLL,             BSI_CW(0x50, cw80),        /* CW80 : DCO SCA typ. Code: STX_DCO_SCAK_CODETYP[11:0] */
/*MT6280RF*/                     SCTRL_PLL,             BSI_CW(0x61, cw97),        /* CW97 : STX NMMD1 for KDCO cal.: STX_MMD_SDM_NINT1[7:0], STX_MMD_SDM_NFRAC1[22:11] */
/*MT6280RF*/                     SCTRL_PLL,             BSI_CW(0x62, cw98),        /* CW98 : STX NMMD1 for KDCO cal.: STX_MMD_SDM_NFRAC1[10:0]. */
/*MT6280RF*/                     SCTRL_LFBW,            BSI_CW(0x4B, cw75),        /* CW75 : STX_LF_BW[2:0]=3'b000(91KHz) for 2G mode. */
/*MT6280RF*/                     SCTRL_TXCAL_MODE,      SDATA_TXCAL_MODE|SDATA_BAND_SEL[l1d_rf.band] ); /* CW1  : 2GTX Cal. Mode | Band */
/*MT6280RF*/    #else
/*MT6280RF*/    HWRITE_11_SDATA( SCTRL_CKG_LDO_RCODE,   BSI_CW(0x9 , cw9  ),        /* CW9  : [D5:D3]=001,Changed it for spur improvement */
/*MT6280RF*/                     SCTRL_TXIFLDOC,        SDATA_TXIFLDOC,             /* CW35 : turn-on IFLDO and CKGOUT before TX burst to get more timing margin for both Q-path on/off option */
/*MT6280RF*/                     SCTRL_TXQPATH,         BSI_CW(0x75, cw117),        /* CW117: 2G TX qpath */
/*MT6280RF*/                     SCTRL_TXPORT,          BSI_CW(0x22, cw34 ),        /* CW34 : Enable correct TX band output */
/*MT6280RF*/                     SCTRL_PLL,             l1d_rf.RFN_data,            /* CW95 : STX NMMD0: STX_MMD_SDM_NINT[7:0], STX_MMD_SDM_NFRAC[22:11] */
/*MT6280RF*/                     SCTRL_PLL,             l1d_rf.IFN_data,            /* CW96 : STX NMMD0, DA_OFFSET: STX_MMD_SDM_NFRAC[10:0], STX_MMD_DA_OFFSET[7:0] */
/*MT6280RF*/                     SCTRL_PLL,             BSI_CW(0x50, cw80 ),        /* CW80 : DCO SCA typ. Code: STX_DCO_SCAK_CODETYP[11:0] */
/*MT6280RF*/                     SCTRL_PLL,             BSI_CW(0x61, cw97 ),        /* CW97 : STX NMMD1 for KDCO cal.: STX_MMD_SDM_NINT1[7:0], STX_MMD_SDM_NFRAC1[22:11] */
/*MT6280RF*/                     SCTRL_PLL,             BSI_CW(0x62, cw98 ),        /* CW98 : STX NMMD1 for KDCO cal.: STX_MMD_SDM_NFRAC1[10:0]. */
/*MT6280RF*/                     SCTRL_LFBW,            BSI_CW(0x4B, cw75 ),        /* CW75 : STX_LF_BW[2:0]=3'b000(91KHz) for 2G mode. */
/*MT6280RF*/                     SCTRL_TXCAL_MODE,      SDATA_TXCAL_MODE|qpath_on|SDATA_BAND_SEL[l1d_rf.band] ); /* CW1  : 2GTX Cal. Mode | qpath_on | Band */
/*MT6280RF*/    #endif
/*MT6280RF*/ }
/*MT6280RF*/
/*MT6280RF*/ void  L1D_RF_SetSData_ST2( void )
/*MT6280RF*/ {
/*MT6280RF*/    SETUP_ST2();
/*MT6280RF*/
/*MT6280RF*/    HWRITE_4_SDATA( SCTRL_RESERVED, 0,   /* reserved */
/*MT6280RF*/                    SCTRL_RESERVED, 0,   /* reserved */
/*MT6280RF*/                    SCTRL_RESERVED, 0,   /* reserved */
/*MT6280RF*/                    SCTRL_RESERVED, 0 ); /* reserved */
/*MT6280RF*/ }
/*MT6280RF*/
/*MT6280RF*/ void  L1D_RF_SetSData_ST3( void )
/*MT6280RF*/ {
/*MT6280RF*/    #if IS_CHIP_MT6280_S00
/*MT6280RF*/    SETUP_ST3();
/*MT6280RF*/
/*MT6280RF*/    HWRITE_3_SDATA( SCTRL_IDLE,            SDATA_TX2SLEEP|SDATA_BAND_SEL[l1d_rf.band], /* CW1  : Sleep Mode */
/*MT6280RF*/                    SCTRL_TXIFLDOC,        POR_CW35,                                   /* CW35 : POR */
/*MT6280RF*/                    SCTRL_CURRENT_CONTROL, SDATA_CURRENT_CONTROL_OFF);                 /* CW245: Add always off current control */
/*MT6280RF*/    #else
/*MT6280RF*/    SETUP_ST3();
/*MT6280RF*/
/*MT6280RF*/    HWRITE_3_SDATA( SCTRL_IDLE,            SDATA_TX2SLEEP|SDATA_BAND_SEL[l1d_rf.band], /* CW1  : Sleep Mode */
/*MT6280RF*/                    SCTRL_TXIFLDOC,        POR_CW35,                                   /* CW35 : POR */
/*MT6280RF*/                    SCTRL_CKG_LDO_RCODE,   POR_CW9);                                   /* CW9  : POR*/
/*MT6280RF*/    #endif
/*MT6280RF*/ }
/*MT6280RF*/
/*MT6280RF*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6280RF*/ {
/*MT6280RF*/    unsigned long cw41     = 0;
/*MT6280RF*/    unsigned long cw42     = 0;
/*MT6280RF*/    unsigned long tx_g8sel = 0;
/*MT6280RF*/    #if IS_CHIP_MT6280_S00
/*MT6280RF*/    #else
/*MT6280RF*/    unsigned short qpath_on= 0;
/*MT6280RF*/    #endif
/*MT6280RF*/
/*MT6280RF*/    SETUP_ST2B_ST2M();
/*MT6280RF*/
/*MT6280RF*/    L1D_RF_TxGainSetting( l1d_rf.tx_mod_type2, l1d_rf.cur_slot, l1d_rf2.tx_power[l1d_rf.cur_slot], (FrequencyBand)l1d_rf.band, &cw41, &cw42 );
/*MT6280RF*/
/*MT6280RF*/    if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6280RF*/       tx_g8sel = (0x1<<11);
/*MT6280RF*/    else
/*MT6280RF*/       tx_g8sel = (0x0<<11);
/*MT6280RF*/
/*MT6280RF*/    #if IS_CHIP_MT6280_S00
/*MT6280RF*/    HWRITE_4_SDATA( SCTRL_RXBURST_MODE, SDATA_TXBURST_MODE|tx_g8sel|SDATA_BAND_SEL[l1d_rf.band],      /* CW1  : 2GTX Burst Mode | G/8 change | Band */
/*MT6280RF*/                    SCTRL_TXGAIN,       BSI_CW(0x29, cw41),                                           /* CW41 : TX Gain */
/*MT6280RF*/                    SCTRL_TXGAIN,       BSI_CW(0x2A, cw42),                                           /* CW42 : TX Gain */
/*MT6280RF*/                    SCTRL_RESERVED,     0                                                          ); /* reserved */
/*MT6280RF*/    #else
/*MT6280RF*/    if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6280RF*/    {
/*MT6280RF*/       qpath_on = ( l1d_rf.band<FrequencyBand1800 ) ? (IS_Q_PATH_ON<<5) : (0x0<<5);
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    HWRITE_4_SDATA( SCTRL_RXBURST_MODE, SDATA_TXBURST_MODE|tx_g8sel|qpath_on|SDATA_BAND_SEL[l1d_rf.band], /* CW1  : 2GTX Burst Mode | G/8 change | qpath_on | Band */
/*MT6280RF*/                    SCTRL_TXGAIN,       BSI_CW(0x29, cw41),                                               /* CW41 : TX Gain */
/*MT6280RF*/                    SCTRL_TXGAIN,       BSI_CW(0x2A, cw42),                                               /* CW42 : TX Gain */
/*MT6280RF*/                    SCTRL_RESERVED,     0                                                          );     /* reserved */
/*MT6280RF*/    #endif
/*MT6280RF*/ }
/*MT6280RF*/
/*MT6280RF*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6280RF*/ {
/*MT6280RF*/    unsigned long cw41     = 0;
/*MT6280RF*/    unsigned long cw42     = 0;
/*MT6280RF*/    unsigned long tx_g8sel = 0;
/*MT6280RF*/    #if IS_CHIP_MT6280_S00
/*MT6280RF*/    #else
/*MT6280RF*/    unsigned short qpath_on= 0;
/*MT6280RF*/    #endif
/*MT6280RF*/
/*MT6280RF*/    SETUP_ST2B_ST2M();
/*MT6280RF*/
/*MT6280RF*/    L1D_RF_TxGainSetting( l1d_rf.tx_mod_type2, l1d_rf.cur_slot, l1d_rf2.tx_power[l1d_rf.cur_slot], (FrequencyBand)l1d_rf.band, &cw41, &cw42 );
/*MT6280RF*/
/*MT6280RF*/    if( (l1d_rf.change)&(1<<l1d_rf.cur_slot) )
/*MT6280RF*/    {  /* modulation type changes */
/*MT6280RF*/
/*MT6280RF*/       if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6280RF*/          tx_g8sel = (0x1<<11);   /* change g->8 CW1 D[11] */
/*MT6280RF*/       else
/*MT6280RF*/          tx_g8sel = (0x0<<11);   /* change 8->g CW1 D[11] */
/*MT6280RF*/
/*MT6280RF*/    #if IS_CHIP_MT6280_S00
/*MT6280RF*/       HWRITE_4_SDATA( SCTRL_RXBURST_MODE, SDATA_TXBURST_MODE|tx_g8sel|SDATA_BAND_SEL[l1d_rf.band],      /* CW1  : 2GTX Burst Mode | G/8 change | Band */
/*MT6280RF*/                       SCTRL_TXGAIN,       BSI_CW(0x29, cw41),                                           /* CW41 : TX Gain */
/*MT6280RF*/                       SCTRL_TXGAIN,       BSI_CW(0x2A, cw42),                                           /* CW42 : TX Gain */
/*MT6280RF*/                       SCTRL_RESERVED,     0                                                          ); /* reserved */
/*MT6280RF*/    #else
/*MT6280RF*/       if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6280RF*/       {
/*MT6280RF*/          qpath_on = ( l1d_rf.band<FrequencyBand1800 ) ? (IS_Q_PATH_ON<<5) : (0x0<<5);
/*MT6280RF*/       }
/*MT6280RF*/
/*MT6280RF*/       HWRITE_4_SDATA( SCTRL_RXBURST_MODE, SDATA_TXBURST_MODE|tx_g8sel|qpath_on|SDATA_BAND_SEL[l1d_rf.band], /* CW1  : 2GTX Burst Mode | G/8 change | qpath_on | Band */
/*MT6280RF*/                       SCTRL_TXGAIN,       BSI_CW(0x29, cw41),                                               /* CW41 : TX Gain */
/*MT6280RF*/                       SCTRL_TXGAIN,       BSI_CW(0x2A, cw42),                                               /* CW42 : TX Gain */
/*MT6280RF*/                       SCTRL_RESERVED,     0                                                          );     /* reserved */
/*MT6280RF*/    #endif
/*MT6280RF*/    }
/*MT6280RF*/    else
/*MT6280RF*/    {
/*MT6280RF*/       HWRITE_4_SDATA( SCTRL_TXGAIN,       BSI_CW(0x29, cw41),                                           /* CW41 : TX Gain */
/*MT6280RF*/                       SCTRL_TXGAIN,       BSI_CW(0x2A, cw42),                                           /* CW42 : TX Gain */
/*MT6280RF*/                       SCTRL_RESERVED,     0,                                                            /* reserved */
/*MT6280RF*/                       SCTRL_RESERVED,     0                                                          ); /* reserved */
/*MT6280RF*/    }
/*MT6280RF*/ }
/*MT6280RF*/
#endif

#if IS_RF_MT6169
/*MT6169*/
/*MT6169*/ /*..........................................................*/
/*MT6169*/ /*  Define Alias and Table                                  */
/*MT6169*/ /*..........................................................*/
/*MT6169*/
/*MT6169*/ #define  SCTRL_RXCAL_MODE              SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_RXBURST_MODE            SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_TXCAL_MODE              SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_TXBURST_MODE            SCTRL_WORD(0,30)
/*MT6169*/ #define  SDATA_RXCAL_MODE              BSI_CW(0x01, 0x08040)  /* MODE=00001|BAND=Variable|DYN_EN=1|Others=0 */
/*MT6169*/ #define  SDATA_RXBURST_MODE            BSI_CW(0x01, 0x10040)  /* MODE=00010|BAND=Variable|DYN_EN=1|Others=0 */
/*MT6169*/ #define  SDATA_TXCAL_MODE              BSI_CW(0x01, 0x18040)  /* MODE=00011|BAND=Variable|DYN_EN=1|Others=0 */
/*MT6169*/ #define  SDATA_TXBURST_MODE            BSI_CW(0x01, 0x20040)  /* MODE=00100|BAND=Variable|DYN_EN=1|Others=0 */
/*MT6169*/ #define  SDATA_RX2SLEEP                BSI_CW(0x01, 0x00040)  /* MODE=00000|BAND=Variable|DYN_EN=1|Others=0 */
/*MT6169*/ #define  SDATA_TX2SLEEP                BSI_CW(0x01, 0x00040)  /* MODE=00000|BAND=Variable|DYN_EN=1|Others=0 */
/*MT6169*/ /*..........................................................*/
/*MT6169*/ #define  SCTRL_PLL                     SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_AGC                     SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_AFCDAC                  SCTRL_WORD(0,30)
/*MT6169*/ #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G)
/*MT6169*/ #define  SDATA_AFCDAC                  BSI_CW(0xF7, 0x0003C)  /* CW247:DCXO_XO_CAFC[12:0] */
/*MT6169*/ #else
/*MT6169*/ #define  SDATA_AFCDAC                  BSI_CW(0xFE, 0x00000)  /* CW254:AFC_BUS[12:0] */
/*MT6169*/ #endif
/*MT6169*/ /*..........................................................*/
/*MT6169*/ #define  SCTRL_SRX_CFG                 SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_SRX_LOCFG_BIAS          SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_SRX_12_MISC             SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_RX_CFG                  SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_RX_BAND_BW              SCTRL_WORD(0,30)       /*        Variable                                                  */
/*MT6169*/ #define  SCTRL_RX_41                   SCTRL_WORD(0,30)       /* CW41                                                             */
/*MT6169*/ #define  SCTRL_RX_27                   SCTRL_WORD(0,30)       /* CW27                                                             */
/*MT6169*/ #define  SDATA_SRX_CFG                 BSI_CW(0x72, 0x46000)  /* CW114: LF_C1, LF_C2, SRX_VCO in manual mode, set to "0"                                              */
/*MT6169*/ #define  SDATA_SRX_CFG_E3              BSI_CW(0x72, 0x46000)  /* CW114_E3: SRX_VCO in manual mode, set to "0"                     */
/*MT6169*/ #define  SDATA_SRX_LOCFG_BIAS          BSI_CW(0x75, 0x501D8)  /* CW117: SRX_ACAL_TARGET, RXREP_LT1_DRIVER_EN, RXREP_LT2_DRIVER_EN */
/*MT6169*/ #define  SDATA_SRX_LOCFG_BIAS_E3       BSI_CW(0x75, 0x5001E)  /* CW117: SRX_ACAL_TARGET, RXREP_LT1_DRIVER_EN, RXREP_LT2_DRIVER_EN */
/*MT6169*/ #define  SDATA_RX_CFG                  BSI_CW(0x02, 0x0C020)  /* CW2  : IORX1, IORX2, RCK_RX1RX2                                  */
/*MT6169*/ #define  SDATA_RX_CFG_E3               BSI_CW(0x02, 0x0C000)  /* CW2  : IORX1, IORX2, RCK_RX1RX2                                  */
/*MT6169*/ #define  SDATA_RX_BAND_BW              BSI_CW(0x35, 0x42331)  /* CW53 : LNA_CUR                                                   */
/*MT6169*/ #define  SDATA_RX_BAND_BW_E3           BSI_CW(0x35, 0xC0211)  /* CW53 : LNA_CUR                                                   */
/*MT6169*/ #define  SDATA_RX_CW41                 BSI_CW(0x29, 0x00000)  /* CW72 : TXRCF_CSEL                                                */
/*MT6169*/ #define  SDATA_RX_CW27                 BSI_CW(0x1B, 0x00000)  /* CW157: LF_K0                                                     */
/*MT6169*/ /*..........................................................*/
/*MT6169*/ #define  SCTRL_CODETYPE                SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_DEM_CHUNK               SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_LOOP_FILTER             SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_TX_BAND                 SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_TX_CFG                  SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_TX_BIAS1                SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_TX_BIAS2                SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_TX_RCF                  SCTRL_WORD(0,30)       /*        Variable                                                                                     */
/*MT6169*/ #define  SCTRL_TX_MOD                  SCTRL_WORD(0,30)
/*MT6169*/ #define  SDATA_TX_CW68                 BSI_CW(0x44, 0x00000)  /* CW68 : CTUNE_FINE, IOTX, TXBAND, BSEL_CAP, CTUNE                                                    */
/*MT6169*/ #define  SDATA_TX_CW69                 BSI_CW(0x45, 0x01000)  /* CW69 : RFATT, TXRCF_REXT, TXRCF_C, TXRCF_R                                                          */
/*MT6169*/ #define  SDATA_TX_CW76                 BSI_CW(0x4C, 0x40120)  /* CW76 : TXRFMOD_VGSBM, TXLPF_HB_EN, TXRFMOD_VGS, TX_RF_MOD_VGS_Q_EN, TX_RF_MOD_VGS_I_EN, TXRFPGA_BMA */
/*MT6169*/ #define  SDATA_TX_CW72                 BSI_CW(0x48, 0x00000)  /* CW72 : TXRCF_CSEL                                                                                   */
/*MT6169*/ #define  SDATA_TX_CW72_E3              BSI_CW(0x48, 0x00008)  /* CW72 : TXRCF_CSEL, set RG_TXRFLDOO_ALWAYS_ON(D3) = 1. Sequence_CW_value_20130930.xlsx               */
/*MT6169*/ #define  SDATA_TX_CW78                 BSI_CW(0x4E, 0x01C64)  /* CW78                                                                                                */
/*MT6169*/ #define  SDATA_TX_CW157                BSI_CW(0x9D, 0x00060)  /* CW157: LF_K0                                                                                        */
/*MT6169*/ /*..........................................................*/
/*MT6169*/ #define  SCTRL_TXGAIN                  SCTRL_WORD(0,30)
/*MT6169*/ #define  SCTRL_TEMP_MEAS               SCTRL_WORD(0,30)
/*MT6169*/ #if IS_USE_INTERNAL_TEMP_SENSOR
/*MT6169*/ #define  SDATA_TEMP_MEAS               BSI_CW(0xD2, 0x00000)  /* CW210: THADC_EXT = 0 (Only Internal temp sensor measurement updates TXL_INIT_S bus for SX Calibration) */
/*MT6169*/ #else
/*MT6169*/ #define  SDATA_TEMP_MEAS               BSI_CW(0xD2, 0x40000)  /* CW210: THADC_EXT = 1 (external temp sensor measurement                                                 */
/*MT6169*/ #endif
/*MT6169*/ /*..........................................................*/
/*MT6169*/ #define  SCTRL_TXRFLDO_MAN             SCTRL_WORD(0,30)
/*MT6169*/ #define  SDATA_TX_CW70                 BSI_CW(0x46, 0x00024)  /* CW70 : TXRFLDO_M */
/*MT6169*/ /*..........................................................*/
/*MT6169*/
/*MT6169*/ const unsigned long  SDATA_BAND_SEL[5] =
/*MT6169*/ {  /* CW1: Band Selection */
/*MT6169*/    (0x0<<9),  /* GSM  450 no support */
/*MT6169*/    (0x5<<9),  /* GSM  850            */
/*MT6169*/    (0x8<<9),  /* GSM  900            */
/*MT6169*/    (0x3<<9),  /* DCS 1800            */
/*MT6169*/    (0x2<<9),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ CONST unsigned long  SDATA_IORX1[5] =
/*MT6169*/ {  /* CW28 : RX LNA Selection */
/*MT6169*/ #if IS_DCS_NB_WB_SWITCH_SUPPORT
/*MT6169*/    (DCS_NB_PATH_SEL<<16),  /* use this field to store the DCS NB path */
/*MT6169*/ #else
/*MT6169*/    0,                      /* GSM  450 no support                     */
/*MT6169*/ #endif
/*MT6169*/    (GSM850_PATH_SEL<<16),  /* GSM  850                                */
/*MT6169*/    (   GSM_PATH_SEL<<16),  /* GSM  900                                */
/*MT6169*/    (   DCS_PATH_SEL<<16),  /* DCS 1800                                */
/*MT6169*/    (   PCS_PATH_SEL<<16),  /* PCS 1900                                */
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ CONST unsigned long  SDATA_IORX2[5] =
/*MT6169*/ {  /* CW28 : RX LNA Selection */
/*MT6169*/ #if IS_DCS_NB_WB_SWITCH_SUPPORT
/*MT6169*/    (DCS_NB_PATH_SEL<<6),   /* use this field to store the DCS NB path */
/*MT6169*/ #else
/*MT6169*/    0,                      /* GSM  450 no support                     */
/*MT6169*/ #endif
/*MT6169*/    (GSM850_PATH_SEL<<6),   /* GSM  850                                */
/*MT6169*/    (   GSM_PATH_SEL<<6),   /* GSM  900                                */
/*MT6169*/    (   DCS_PATH_SEL<<6),   /* DCS 1800                                */
/*MT6169*/    (   PCS_PATH_SEL<<6),   /* PCS 1900                                */
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ const unsigned long  SDATA_CW117[5] =
/*MT6169*/ { /* SDATA_SRX_LOCFG_BIAS | SRX_ACAL_TARGET | RG_SRX_REF_SEL */
/*MT6169*/    0x0,                                                  /* GSM  450 no support */
/*MT6169*/    ( SDATA_SRX_LOCFG_BIAS |      (1<<11)    | (2<<0) ),  /* GSM  850            */
/*MT6169*/    ( SDATA_SRX_LOCFG_BIAS |      (1<<11)    | (2<<0) ),  /* GSM  900            */
/*MT6169*/    ( SDATA_SRX_LOCFG_BIAS |      (2<<11)    | (2<<0) ),  /* DCS 1800            */
/*MT6169*/    ( SDATA_SRX_LOCFG_BIAS |      (2<<11)    | (2<<0) ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/ const unsigned long  SDATA_CW117_E3[5] =
/*MT6169*/ { /* SDATA_SRX_LOCFG_BIAS | SRX_ACAL_TARGET | | RG_SRX_REF_SEL */
/*MT6169*/    0x0,                                                     /* GSM  450 no support */
/*MT6169*/    ( SDATA_SRX_LOCFG_BIAS_E3 |      (1<<11)    | (0<<0) ),  /* GSM  850            */
/*MT6169*/    ( SDATA_SRX_LOCFG_BIAS_E3 |      (1<<11)    | (0<<0) ),  /* GSM  900            */
/*MT6169*/    ( SDATA_SRX_LOCFG_BIAS_E3 |      (2<<11)    | (0<<0) ),  /* DCS 1800            */
/*MT6169*/    ( SDATA_SRX_LOCFG_BIAS_E3 |      (2<<11)    | (0<<0) ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/ const unsigned long  SDATA_CW2_E3[5] =
/*MT6169*/ { /*                    RG_RX_LNA_IBUMP[3:0] | RG_RX_LNA_G0_CTRL[0] */
/*MT6169*/    0x0,                                                   /* GSM  450 no support */
/*MT6169*/    ( SDATA_RX_CFG_E3 |        (6<<2)         | (1<<0) ),  /* GSM  850            */
/*MT6169*/    ( SDATA_RX_CFG_E3 |        (6<<2)         | (1<<0) ),  /* GSM  900            */
/*MT6169*/    ( SDATA_RX_CFG_E3 |        (5<<2)         | (0<<0) ),  /* DCS 1800            */
/*MT6169*/    ( SDATA_RX_CFG_E3 |        (5<<2)         | (0<<0) ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ const unsigned long  SDATA_CW118[5] =
/*MT6169*/ { /*  POR_CW118            | RG_SRX_VCOVAR_VBIAS */
/*MT6169*/    0x0,                                                /* GSM  450 no support */
/*MT6169*/    ( (POR_CW118&0xFFFFE3F) |         (3<<6)        ),  /* GSM  850            */
/*MT6169*/    ( (POR_CW118&0xFFFFE3F) |         (3<<6)        ),  /* GSM  900            */
/*MT6169*/    ( (POR_CW118&0xFFFFE3F) |         (3<<6)        ),  /* DCS 1800            */
/*MT6169*/    ( (POR_CW118&0xFFFFE3F) |         (3<<6)        ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ const unsigned long  SDATA_CW114[5] =
/*MT6169*/ { /* SDATA_SRX_CFG |SRX_LF_C1|SRX_LF_C2 */
/*MT6169*/    0x0,                                  /* GSM  450 no support */
/*MT6169*/    ( SDATA_SRX_CFG | (5<<8) | (5<<4) ),  /* GSM  850            */
/*MT6169*/    ( SDATA_SRX_CFG | (7<<8) | (6<<4) ),  /* GSM  900            */
/*MT6169*/    ( SDATA_SRX_CFG | (7<<8) | (7<<4) ),  /* DCS 1800            */
/*MT6169*/    ( SDATA_SRX_CFG | (8<<8) | (7<<4) ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ const unsigned long  SDATA_CW114_E3[5] =
/*MT6169*/ { /* SDATA_SRX_CFG |SRX_LF_C1|SRX_LF_C2 */
/*MT6169*/    0x0,                                     /* GSM  450 no support */
/*MT6169*/    ( SDATA_SRX_CFG_E3 | (5<<8) | (5<<4) ),  /* GSM  850            */
/*MT6169*/    ( SDATA_SRX_CFG_E3 | (7<<8) | (6<<4) ),  /* GSM  900            */
/*MT6169*/    ( SDATA_SRX_CFG_E3 | (7<<8) | (7<<4) ),  /* DCS 1800            */
/*MT6169*/    ( SDATA_SRX_CFG_E3 | (8<<8) | (7<<4) ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ const unsigned long  SDATA_CW53[5] =
/*MT6169*/ { /* SDATA_RX_BAND_BW |RX_LNA_CUR */
/*MT6169*/    0x0,                             /* GSM  450 no support */
/*MT6169*/    ( SDATA_RX_BAND_BW | (0<<14) ),  /* GSM  850            */
/*MT6169*/    ( SDATA_RX_BAND_BW | (0<<14) ),  /* GSM  900            */
/*MT6169*/    ( SDATA_RX_BAND_BW | (2<<14) ),  /* DCS 1800            */
/*MT6169*/    ( SDATA_RX_BAND_BW | (2<<14) ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/ const unsigned long  SDATA_CW53_E3[5] =
/*MT6169*/ { /* SDATA_RX_BAND_BW     |RX_LNA_CUR|  RG_RX_DIV_VOLTAGE[2:0]  */
/*MT6169*/    0x0,                                            /* GSM  450 no support */
/*MT6169*/    ( SDATA_RX_BAND_BW_E3  | (0<<14)  | (3<<11) ),  /* GSM  850            */
/*MT6169*/    ( SDATA_RX_BAND_BW_E3  | (0<<14)  | (3<<11) ),  /* GSM  900            */
/*MT6169*/    ( SDATA_RX_BAND_BW_E3  | (2<<14)  | (2<<11) ),  /* DCS 1800            */
/*MT6169*/    ( SDATA_RX_BAND_BW_E3  | (2<<14)  | (2<<11) ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ CONST unsigned long  SDATA_CW68[5] =
/*MT6169*/ { /* SDATA_TX_CW68 | CTUNE_FINE |        IOTX        | TXBAND | BSEL_CAP | CTUNE */
/*MT6169*/    0x0,                                                                                /* GSM  450 no support */
/*MT6169*/    ( SDATA_TX_CW68 | (0<<14) | (GSM850_PORT_SEL<<11) | (4<<8) |  (0<<6)  | ( 0<<0) ),  /* GSM  850            */
/*MT6169*/    ( SDATA_TX_CW68 | (0<<14) | (   GSM_PORT_SEL<<11) | (4<<8) |  (0<<6)  | ( 0<<0) ),  /* GSM  900            */
/*MT6169*/    ( SDATA_TX_CW68 | (0<<14) | (   DCS_PORT_SEL<<11) | (1<<8) |  (0<<6)  | (16<<0) ),  /* DCS 1800            */
/*MT6169*/    ( SDATA_TX_CW68 | (0<<14) | (   PCS_PORT_SEL<<11) | (1<<8) |  (0<<6)  | (12<<0) ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/ CONST unsigned long  SDATA_CW68_E3[5] =
/*MT6169*/ { /* SDATA_TX_CW68 | CTUNE_FINE |        IOTX        | TXBAND | BSEL_CAP | CTUNE */
/*MT6169*/    0x0,                                                                                /* GSM  450 no support */
/*MT6169*/    ( SDATA_TX_CW68 | (0<<14) | (GSM850_PORT_SEL<<11) | (4<<8) |  (0<<6)  | ( 0<<0) ),  /* GSM  850            */
/*MT6169*/    ( SDATA_TX_CW68 | (0<<14) | (   GSM_PORT_SEL<<11) | (4<<8) |  (0<<6)  | ( 0<<0) ),  /* GSM  900            */
/*MT6169*/    ( SDATA_TX_CW68 | (0<<14) | (   DCS_PORT_SEL<<11) | (1<<8) |  (0<<6)  | (18<<0) ),  /* DCS 1800            */
/*MT6169*/    ( SDATA_TX_CW68 | (0<<14) | (   PCS_PORT_SEL<<11) | (1<<8) |  (0<<6)  | (14<<0) ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ const unsigned long  SDATA_CW69[5] =
/*MT6169*/ { /* SDATA_TX_CW69 | TXRCF_REXT | RG_RFATT[4:4] | RG_RFATT[3:0] | TXRCF_C | TXRCF_R */
/*MT6169*/    0x0,                                                                                /* GSM  450 no support */
/*MT6169*/    ( SDATA_TX_CW69 |   (0<<16)  |    (0<<15)    |     (0<<8)    |  (0<<6) | (1<<3) ),  /* GSM  850            */
/*MT6169*/    ( SDATA_TX_CW69 |   (0<<16)  |    (0<<15)    |     (0<<8)    |  (0<<6) | (1<<3) ),  /* GSM  900            */
/*MT6169*/    ( SDATA_TX_CW69 |   (0<<16)  |    (0<<15)    |     (0<<8)    |  (0<<6) | (1<<3) ),  /* DCS 1800            */
/*MT6169*/    ( SDATA_TX_CW69 |   (0<<16)  |    (0<<15)    |     (0<<8)    |  (0<<6) | (1<<3) ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ const unsigned long  SDATA_CW69_ECO[5] =
/*MT6169*/ { /* SDATA_TX_CW69 | TXRCF_REXT | RG_RFATT[4:4] | RG_RFATT[3:0] | TXRCF_C | TXRCF_R */
/*MT6169*/    0x0,                                                                                /* GSM  450 no support */
/*MT6169*/    ( SDATA_TX_CW69 |   (0<<16)  |    (0<<15)    |     (0<<8)    |  (0<<6) | (1<<3) ),  /* GSM  850            */
/*MT6169*/    ( SDATA_TX_CW69 |   (0<<16)  |    (0<<15)    |     (0<<8)    |  (0<<6) | (1<<3) ),  /* GSM  900            */
/*MT6169*/    ( SDATA_TX_CW69 |   (0<<16)  |    (0<<15)    |     (0<<8)    |  (3<<6) | (1<<3) ),  /* DCS 1800            */
/*MT6169*/    ( SDATA_TX_CW69 |   (0<<16)  |    (0<<15)    |     (0<<8)    |  (3<<6) | (1<<3) ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/ const unsigned long  SDATA_CW69_E3[5] =
/*MT6169*/ { /* SDATA_TX_CW69 | TXRCF_REXT | RG_RFATT[4:4] | RG_RFATT[3:0] | TXRCF_C | TXRCF_R */
/*MT6169*/    0x0,                                                                                /* GSM  450 no support */
/*MT6169*/    ( SDATA_TX_CW69 |   (0<<16)  |    (0<<15)    |     (0<<8)    |  (3<<6) | (1<<3) ),  /* GSM  850            */
/*MT6169*/    ( SDATA_TX_CW69 |   (0<<16)  |    (0<<15)    |     (0<<8)    |  (3<<6) | (1<<3) ),  /* GSM  900            */
/*MT6169*/    ( SDATA_TX_CW69 |   (0<<16)  |    (0<<15)    |     (0<<8)    |  (0<<6) | (1<<3) ),  /* DCS 1800            */
/*MT6169*/    ( SDATA_TX_CW69 |   (0<<16)  |    (0<<15)    |     (0<<8)    |  (0<<6) | (1<<3) ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/ const unsigned long  SDATA_CW76[5] =
/*MT6169*/ { /* SDATA_TX_CW76 |TXRFMOD_VGSBM | TXLPF_HB_EN | TXRFMOD_VGS | TX_RF_MOD_VGS_Q_EN | TX_RF_MOD_VGS_I_EN | TXRFPGA_BMA */
/*MT6169*/    0x0,                                                                                                                   /* GSM  450 no support */
/*MT6169*/    ( SDATA_TX_CW76 |   (0<<19)    |   (0<<15)   |   (0<<12)   |       (1<<11)      |        (1<<10)     |    (4<<0)   ),  /* GSM  850            */
/*MT6169*/    ( SDATA_TX_CW76 |   (0<<19)    |   (0<<15)   |   (0<<12)   |       (1<<11)      |        (1<<10)     |    (4<<0)   ),  /* GSM  900            */
/*MT6169*/    ( SDATA_TX_CW76 |   (0<<19)    |   (1<<15)   |   (2<<12)   |       (0<<11)      |        (0<<10)     |    (6<<0)   ),  /* DCS 1800            */
/*MT6169*/    ( SDATA_TX_CW76 |   (0<<19)    |   (1<<15)   |   (2<<12)   |       (0<<11)      |        (0<<10)     |    (6<<0)   ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/ const unsigned long  SDATA_CW76_E3[5] =
/*MT6169*/ { /* SDATA_TX_CW76 |TXRFMOD_VGSBM | TXLPF_HB_EN | TXRFMOD_VGS | TX_RF_MOD_VGS_Q_EN | TX_RF_MOD_VGS_I_EN | TXRFPGA_BMA */
/*MT6169*/    0x0,                                                                                                                   /* GSM  450 no support */
/*MT6169*/    ( SDATA_TX_CW76 |   (0<<19)    |   (0<<15)   |   (0<<12)   |       (0<<11)      |        (1<<10)     |    (4<<0)   ),  /* GSM  850            */
/*MT6169*/    ( SDATA_TX_CW76 |   (0<<19)    |   (0<<15)   |   (0<<12)   |       (0<<11)      |        (1<<10)     |    (4<<0)   ),  /* GSM  900            */
/*MT6169*/    ( SDATA_TX_CW76 |   (0<<19)    |   (1<<15)   |   (2<<12)   |       (0<<11)      |        (1<<10)     |    (6<<0)   ),  /* DCS 1800            */
/*MT6169*/    ( SDATA_TX_CW76 |   (0<<19)    |   (1<<15)   |   (2<<12)   |       (0<<11)      |        (1<<10)     |    (6<<0)   ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ const unsigned long  SDATA_CW77[5] =
/*MT6169*/ { /*      POR_CW77        | RG_TX_LOHPM  */
/*MT6169*/    0x0,                                                   /* GSM  450 no support */
/*MT6169*/    ( (POR_CW77&0xFF83FFF) |   (1<<17)      |  (4<<14)),   /* GSM  850            */
/*MT6169*/    ( (POR_CW77&0xFF83FFF) |   (1<<17)      |  (4<<14)),   /* GSM  900            */
/*MT6169*/    ( (POR_CW77&0xFF83FFF) |   (2<<17)      |  (5<<14)),   /* DCS 1800            */
/*MT6169*/    ( (POR_CW77&0xFF83FFF) |   (2<<17)      |  (5<<14)),   /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/ const unsigned long  SDATA_CW77_ECO[5] =
/*MT6169*/ { /*      POR_CW77        | RG_TX_LOHPM  */
/*MT6169*/    0x0,                                      /* GSM  450 no support */
/*MT6169*/    ( (POR_CW77&0xFF9FFFF) |   (1<<17)    ),  /* GSM  850            */
/*MT6169*/    ( (POR_CW77&0xFF9FFFF) |   (1<<17)    ),  /* GSM  900            */
/*MT6169*/    ( (POR_CW77&0xFF9FFFF) |   (1<<17)    ),  /* DCS 1800            */
/*MT6169*/    ( (POR_CW77&0xFF9FFFF) |   (1<<17)    ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/ const unsigned long  SDATA_CW77_E3[5] =
/*MT6169*/ { /*      POR_CW77        | RG_TX_LOHPM  | RG_TX_TXRFLDO */
/*MT6169*/    0x0,                                              /* GSM  450 no support */
/*MT6169*/    ( (POR_CW77&0xFF9FFF0) |   (1<<17)    |(5<<1) ),  /* GSM  850            */
/*MT6169*/    ( (POR_CW77&0xFF9FFF0) |   (1<<17)    |(5<<1) ),  /* GSM  900            */
/*MT6169*/    ( (POR_CW77&0xFF9FFF0) |   (2<<17)    |(6<<1) ),  /* DCS 1800            */
/*MT6169*/    ( (POR_CW77&0xFF9FFF0) |   (2<<17)    |(6<<1) ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/ const unsigned long  SDATA_CW78[5] =
/*MT6169*/ {
/*MT6169*/    0x0,                                                                                                                   /* GSM  450 no support */
/*MT6169*/    ( (POR_CW78&0xFFFFE7FF) |  (3<<11)    ),  /* GSM  850 */
/*MT6169*/    ( (POR_CW78&0xFFFFE7FF) |  (3<<11)    ),  /* GSM  900 */
/*MT6169*/    ( (POR_CW78&0xFFFFE7FF) |  (2<<11)    ),  /* DCS 1800 */
/*MT6169*/    ( (POR_CW78&0xFFFFE7FF) |  (2<<11)    ),  /* PCS 1900 */
/*MT6169*/ };

/*MT6169*/ const unsigned long  SDATA_CW41[5] =
/*MT6169*/ { /* SDATA_TX_CW41 | RG_RX_LPF2_A1_STG1_CUR  | RG_RX_LPF2_A2_STG1_CUR | RX_LPF2_A1_STG2_CUR_M | RX_LPF2_A2_STG2_CUR_M |  */
/*MT6169*/    0x0,                                                                                                                     /* GSM  450 no support */
/*MT6169*/    ( SDATA_RX_CW41 |         (3<<17)         |         (0<<14)        |     (12<<10)          |          (12<<6)        ),  /* GSM  850            */
/*MT6169*/    ( SDATA_RX_CW41 |         (3<<17)         |         (0<<14)        |     (12<<10)          |          (12<<6)        ),  /* GSM  900            */
/*MT6169*/    ( SDATA_RX_CW41 |         (3<<17)         |         (0<<14)        |     (12<<10)          |          (12<<6)        ),  /* DCS 1800            */
/*MT6169*/    ( SDATA_RX_CW41 |         (3<<17)         |         (0<<14)        |     (12<<10)          |          (12<<6)        ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/ const unsigned long  SDATA_CW27[5] =
/*MT6169*/ { /* SDATA_TX_CW27 | RX_LPF2_A1_CCOMP_M | RX_LPF2_A2_CCOMP_M |  */
/*MT6169*/    0x0,                                                             /* GSM  450 no support */
/*MT6169*/    ( SDATA_RX_CW27 |       (16<<15)     |      (3<<10)          ),  /* GSM  850            */
/*MT6169*/    ( SDATA_RX_CW27 |       (16<<15)     |      (3<<10)          ),  /* GSM  900            */
/*MT6169*/    ( SDATA_RX_CW27 |       (16<<15)     |      (3<<10)          ),  /* DCS 1800            */
/*MT6169*/    ( SDATA_RX_CW27 |       (16<<15)     |      (3<<10)          ),  /* PCS 1900            */
/*MT6169*/ };
/*MT6169*/
/*MT6169*/ /*..........................................................*/
/*MT6169*/ /* Serial Interface Implement                               */
/*MT6169*/ /*..........................................................*/
/*MT6169*/
/*MT6169*/ void  L1D_RF_SetSData_SR0( void )
/*MT6169*/ {
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void  L1D_RF_SetSData_SR1( void )
/*MT6169*/ {
/*MT6169*/    unsigned short RXD = 0; //2G default RX1 single path
/*MT6169*/    unsigned short RXREP_LT1_DRIVER_EN = 0;
/*MT6169*/    unsigned short RXREP_LT2_DRIVER_EN = 0;
/*MT6169*/    unsigned short RXIF_RCK_RX1RX2     = 0;
/*MT6169*/    unsigned long  ctrl_dcxo           = SCTRL_AFCDAC;
/*MT6169*/    long  cw2,cw117;
/*MT6169*/    unsigned long  sdata_iorx_1 = SDATA_IORX1[l1d_rf.band];
/*MT6169*/    unsigned long  sdata_iorx_2 = SDATA_IORX2[l1d_rf.band];
/*MT6169*/
/*MT6169*/    SETUP_SR1();
/*MT6169*/
/*MT6169*/    switch( RXD )
/*MT6169*/    {
/*MT6169*/       case 0:  /* RX1 single path : IORX1 */
/*MT6169*/          RXREP_LT1_DRIVER_EN = 1; RXREP_LT2_DRIVER_EN = 0; RXIF_RCK_RX1RX2 = 0;
/*MT6169*/          break;
/*MT6169*/       case 1:  /* RX2 single path : IORX2 */
/*MT6169*/          RXREP_LT1_DRIVER_EN = 0; RXREP_LT2_DRIVER_EN = 1; RXIF_RCK_RX1RX2 = 1;
/*MT6169*/          break;
/*MT6169*/       case 2:  /* RX1 + RX2 dual path : IORX1+IORX2 */
/*MT6169*/          RXREP_LT1_DRIVER_EN = 1; RXREP_LT2_DRIVER_EN = 1; RXIF_RCK_RX1RX2 = 0;
/*MT6169*/          break;
/*MT6169*/       default: /* RX1 single path : IORX1 */
/*MT6169*/          RXREP_LT1_DRIVER_EN = 1; RXREP_LT2_DRIVER_EN = 0; RXIF_RCK_RX1RX2 = 0;
/*MT6169*/    }
/*MT6169*/
/*MT6169*/ #if IS_DCS_NB_WB_SWITCH_SUPPORT
/*MT6169*/    if( L1D_RF_IS_DCS_Change_to_NB() )
/*MT6169*/    {  /* change to the narrow band DCS setting */
/*MT6169*/       sdata_iorx_1 = SDATA_IORX1[0];
/*MT6169*/       sdata_iorx_2 = SDATA_IORX2[0];
/*MT6169*/    }
/*MT6169*/ #endif
/*MT6169*/
/*MT6169*/    if( ( MT6169_2G_CHIP_VER == MT6169_E3 ) )
/*MT6169*/    {
/*MT6169*/       cw117 = (long) ( SDATA_CW117_E3[l1d_rf.band] | (RXREP_LT1_DRIVER_EN<<10) | (RXREP_LT2_DRIVER_EN<<9) );
/*MT6169*/       cw2   = (long) ( SDATA_CW2_E3[l1d_rf.band] | sdata_iorx_1 | (RXD<<11) | sdata_iorx_2 | (RXIF_RCK_RX1RX2<<1) );
/*MT6169*/    }
/*MT6169*/    else
/*MT6169*/    {
/*MT6169*/       cw117 = (long) ( SDATA_CW117[l1d_rf.band] | (RXREP_LT1_DRIVER_EN<<10) | (RXREP_LT2_DRIVER_EN<<9) );
/*MT6169*/       cw2   = (long) ( SDATA_RX_CFG | sdata_iorx_1 | (RXD<<11) | sdata_iorx_2 | (RXIF_RCK_RX1RX2<<1) );
/*MT6169*/    }
/*MT6169*/
/*MT6169*/ #if IS_BSI_AFC_ACTIVE_SWITCH
/*MT6169*/    ctrl_dcxo = l1d_rf2.is_bsi_afc_active ? (SCTRL_AFCDAC|event_idx) : SCTRL_RESERVED;
/*MT6169*/ #endif
/*MT6169*/
/*MT6169*/    if( ( MT6169_2G_CHIP_VER == MT6169_E3 ) )
/*MT6169*/    {
/*MT6169*/       HWRITE_14_SDATA( SCTRL_SRX_CFG|event_idx,                SDATA_CW114_E3[l1d_rf.band],                        /* CW114: Set SRX Configuration             */
/*MT6169*/                        SCTRL_PLL|event_idx,                    l1d_rf.RFN_data,                                    /* CW115: Set SRX Frequency                 */
/*MT6169*/                        SCTRL_PLL|event_idx,                    l1d_rf.IFN_data,                                    /* CW116: Set SRX Frequency                 */
/*MT6169*/                        SCTRL_SRX_LOCFG_BIAS|event_idx,         BSI_CW(0x75, cw117),                                /* CW117: Set SRX LO configuration and bias */
/*MT6169*/                        SCTRL_SRX_12_MISC|event_idx,            SDATA_CW118[l1d_rf.band],                           /* CW118: RG_SRX_VCOVAR_VBIAS[2:0]          */
/*MT6169*/                        SCTRL_RX_CFG|event_idx,                 BSI_CW(0x02, cw2  ),                                /* CW2  : Set RX configuration              */
/*MT6169*/                        SCTRL_RX_BAND_BW|event_idx,             SDATA_CW53_E3[l1d_rf.band],                         /* CW53 : Set RX band/BW dependant setting  */
/*MT6169*/                        ctrl_dcxo,                              SDATA_AFCDAC|((l1d_rf.AFC_data&0x1FFF)<<7),         /* CW254: AFC DAC                           */
/*MT6169*/                        SCTRL_RXCAL_MODE|event_idx,             SDATA_RXCAL_MODE|SDATA_BAND_SEL[l1d_rf.band],       /* CW1  : 2G RX Cal Mode | Band             */
/*MT6169*/                        SCTRL_RESERVED,                         0,                                                  /* Reserved */
/*MT6169*/                        SCTRL_RESERVED,                         0,                                                  /* Reserved */
/*MT6169*/                        SCTRL_RESERVED,                         0,                                                  /* Reserved */
/*MT6169*/                        SCTRL_RESERVED,                         0,                                                  /* Reserved */
/*MT6169*/                        SCTRL_RESERVED,                         0                                                ); /* Reserved */
/*MT6169*/    }
/*MT6169*/    else
/*MT6169*/    {
/*MT6169*/       HWRITE_14_SDATA( SCTRL_SRX_CFG|event_idx,                SDATA_CW114[l1d_rf.band],                           /* CW114: Set SRX Configuration             */
/*MT6169*/                        SCTRL_PLL|event_idx,                    l1d_rf.RFN_data,                                    /* CW115: Set SRX Frequency                 */
/*MT6169*/                        SCTRL_PLL|event_idx,                    l1d_rf.IFN_data,                                    /* CW116: Set SRX Frequency                 */
/*MT6169*/                        SCTRL_SRX_LOCFG_BIAS|event_idx,         BSI_CW(0x75, cw117),                                /* CW117: Set SRX LO configuration and bias */
/*MT6169*/                        SCTRL_SRX_12_MISC|event_idx,            SDATA_CW118[l1d_rf.band],                           /* CW118: RG_SRX_VCOVAR_VBIAS[2:0]          */
/*MT6169*/                        SCTRL_RX_CFG|event_idx,                 BSI_CW(0x02, cw2  ),                                /* CW2  : Set RX configuration              */
/*MT6169*/                        SCTRL_RX_41|event_idx,                  SDATA_CW41[l1d_rf.band],                            /* CW41:           */
/*MT6169*/                        SCTRL_RX_27|event_idx,                  SDATA_CW27[l1d_rf.band],                            /* CW27  :               */
/*MT6169*/                        SCTRL_RX_BAND_BW|event_idx,             SDATA_CW53[l1d_rf.band],                            /* CW53 : Set RX band/BW dependant setting  */
/*MT6169*/                        ctrl_dcxo,                              SDATA_AFCDAC|((l1d_rf.AFC_data&0x1FFF)<<7),         /* CW254: AFC DAC                           */
/*MT6169*/                        SCTRL_RXCAL_MODE|event_idx,             SDATA_RXCAL_MODE|SDATA_BAND_SEL[l1d_rf.band],       /* CW1  : 2G RX Cal Mode | Band             */
/*MT6169*/                        SCTRL_RESERVED,                         0,                                                  /* Reserved */
/*MT6169*/                        SCTRL_RESERVED,                         0,                                                  /* Reserved */
/*MT6169*/                        SCTRL_RESERVED,                         0                                                ); /* Reserved */
/*MT6169*/    }
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void  L1D_RF_SetSData_SR2( void )
/*MT6169*/ {
/*MT6169*/    SETUP_SR2();
/*MT6169*/
/*MT6169*/    if(IS_CONTINUOUS_RX_SLOT())
/*MT6169*/    {
/*MT6169*/       HWRITE_5_SDATA( SCTRL_AGC|event_idx    ,        l1d_rf.AGC_data,                 /* CW54 : RX Gain */
/*MT6169*/                       SCTRL_RESERVED,                 0,                               /* reserved */
/*MT6169*/                       SCTRL_RESERVED,                 0,                               /* reserved */
/*MT6169*/                       SCTRL_RESERVED,                 0,                               /* reserved */
/*MT6169*/                       SCTRL_RESERVED,                 0                              );/* reserved */
/*MT6169*/    }
/*MT6169*/    else
/*MT6169*/    {
/*MT6169*/       HWRITE_5_SDATA( SCTRL_AGC|event_idx    ,        l1d_rf.AGC_data,                                  /* CW54 : RX Gain */
/*MT6169*/                       SCTRL_RXBURST_MODE|event_idx,   SDATA_RXBURST_MODE|SDATA_BAND_SEL[l1d_rf.band],   /* CW1  : 2GRX Burst Mode | Band */
/*MT6169*/                       SCTRL_TEMP_MEAS|event_idx,      SDATA_TEMP_MEAS,                                  /* CW210: trigger RF to measure temperature */
/*MT6169*/                       SCTRL_RESERVED,                 0,                                                /* reserved */
/*MT6169*/                       SCTRL_RESERVED,                 0                                               );/* reserved */
/*MT6169*/    }
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void  L1D_RF_SetSData_SR3( void )
/*MT6169*/ {
/*MT6169*/    SETUP_SR3();
/*MT6169*/
/*MT6169*/    HWRITE_4_SDATA( SCTRL_IDLE|event_idx,              SDATA_RX2SLEEP|SDATA_BAND_SEL[l1d_rf.band],  /* CW1: Sleep Mode */
/*MT6169*/                    SCTRL_RESERVED,                    0,                                           /* reserved */
/*MT6169*/                    SCTRL_RESERVED,                    0,                                           /* reserved */
/*MT6169*/                    SCTRL_RESERVED,                    0                                          );/* reserved */
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void  L1D_RF_SetSData_ST0( void )
/*MT6169*/ {
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void  L1D_RF_SetSData_ST1( void )
/*MT6169*/ {
/*MT6169*/    unsigned short codetype     = 0;
/*MT6169*/    unsigned short RFATT_idx_LB = 0; /* Still don't know how to set... */
/*MT6169*/    unsigned short RFATT_idx_HB = 0; /* Still don't know how to set... */
/*MT6169*/    unsigned short Nint         = 0;
/*MT6169*/    unsigned long  Nfrac        = 0;
/*MT6169*/    unsigned long  ctrl_dcxo    = SCTRL_AFCDAC;
/*MT6169*/    long  cw162,cw171,cw172,cw68,cw69,cw77;
/*MT6169*/    /* RFATT on LB :     Attenuation (dB)   = { 0, 1, 2, 3.5,  5,  6,  7, 8.5, 10, 11 }; */
/*MT6169*/    const unsigned short LB_TX_RFATT[10]    = { 1, 2, 3,   6, 10, 11, 15,  24, 29, 30 }; /* CW69 */
/*MT6169*/    const unsigned short LB_TX_BSEL_CAP[10] = { 3, 3, 3,   1,  1,  1,  1,   1,  1,  1 }; /* CW68 */
/*MT6169*/    const unsigned short LB_TX_CTUNE[10]    = { 0, 0, 0,   5,  5,  5,  5,   3,  3,  3 }; /* CW68 */
/*MT6169*/    /* RFATT on HB :     Attenuation (dB)   = { 0, 3, 9 }; */
/*MT6169*/    const unsigned short HB_TX_RFATT[3]     = { 0, 1, 1 }; /* CW69 */
/*MT6169*/    const unsigned short HB_TX_BSEL_CAP[3]  = { 3, 3, 2 }; /* CW68 */
/*MT6169*/    unsigned short TX_RFATT     = (l1d_rf.band<FrequencyBand1800) ? LB_TX_RFATT[RFATT_idx_LB] : HB_TX_RFATT[RFATT_idx_HB];
/*MT6169*/    unsigned short TX_BSEL_CAP  = (l1d_rf.band<FrequencyBand1800) ? LB_TX_BSEL_CAP[RFATT_idx_LB] : HB_TX_BSEL_CAP[RFATT_idx_HB];
/*MT6169*/    unsigned short TX_CTUNE     = (l1d_rf.band<FrequencyBand1800) ? LB_TX_CTUNE[RFATT_idx_LB] : 0;
/*MT6169*/
/*MT6169*/    SETUP_ST1();
/*MT6169*/
/*MT6169*/    L1D_RF_GetTxKDCOCAL2ndSetting( l1d_rf.band, (l1d_rf2.arfcn&0x3FF), &cw171, &cw172);
/*MT6169*/
/*MT6169*/    Nint         = (l1d_rf.RFN_data&(0xFF<<12))>>12;
/*MT6169*/    Nfrac        = ( (l1d_rf.RFN_data&0xFFF)<<11 ) | ( (l1d_rf.IFN_data&(0x7FF<<9))>>9 );
/*MT6169*/
/*MT6169*/    codetype     = L1D_RF_GetTxDCOSCACodeTypeSetting( Nint, Nfrac );
/*MT6169*/
/*MT6169*/
/*MT6169*/    if( ( MT6169_2G_CHIP_VER == MT6169_ECO) ) // E1_ECO
/*MT6169*/    {
/*MT6169*/       cw69  = (long) (SDATA_CW69_ECO[l1d_rf.band] | (((TX_RFATT&0x10)>>4)<<15) | ((TX_RFATT&0xF)<<8));
/*MT6169*/       cw77  = (long) (SDATA_CW77_ECO[l1d_rf.band]);
/*MT6169*/       TX_BSEL_CAP = 3;//for E1 ECO
/*MT6169*/       cw68  = (long) (SDATA_CW68[l1d_rf.band] | ((TX_BSEL_CAP&0x3)<<6) | (TX_CTUNE&0x1F));
/*MT6169*/    }
/*MT6169*/    else if( ( MT6169_2G_CHIP_VER == MT6169_E3) )// E3
/*MT6169*/    {
/*MT6169*/       cw69  = (long) (SDATA_CW69_E3[l1d_rf.band] | (((TX_RFATT&0x10)>>4)<<15) | ((TX_RFATT&0xF)<<8));
/*MT6169*/       cw77  = (long) (SDATA_CW77_E3[l1d_rf.band]);
/*MT6169*/       TX_BSEL_CAP = 3;//for E3
/*MT6169*/       cw68  = (long) (SDATA_CW68_E3[l1d_rf.band] | ((TX_BSEL_CAP&0x3)<<6) | (TX_CTUNE&0x1F));
/*MT6169*/    }
/*MT6169*/    else
/*MT6169*/    {
/*MT6169*/       cw69  = (long) (SDATA_CW69[l1d_rf.band] | (((TX_RFATT&0x10)>>4)<<15) | ((TX_RFATT&0xF)<<8));
/*MT6169*/       cw77  = (long) (SDATA_CW77[l1d_rf.band]);
/*MT6169*/       cw68  = (long) (SDATA_CW68[l1d_rf.band] | ((TX_BSEL_CAP&0x3)<<6) | (TX_CTUNE&0x1F));
/*MT6169*/    }
/*MT6169*/    cw162 = (long) (POR_CW162 | (codetype&0xFFF)<<8);
/*MT6169*/
/*MT6169*/ #if IS_BSI_AFC_ACTIVE_SWITCH
/*MT6169*/    ctrl_dcxo = l1d_rf2.is_bsi_afc_active ? (SCTRL_AFCDAC|event_idx) : SCTRL_RESERVED;
/*MT6169*/ #endif
/*MT6169*/
/*MT6169*/    if( ( MT6169_2G_CHIP_VER == MT6169_E3 ) )
/*MT6169*/    {
/*MT6169*/       HWRITE_14_SDATA( SCTRL_CODETYPE|event_idx,        BSI_CW(0xA2, cw162),                  /* CW162: DCO_SCAK_CODETYP[11:0]@Fdco_tx                                   */
/*MT6169*/                        SCTRL_PLL|event_idx,             l1d_rf.RFN_data,                      /* CW169: MMD_SDM_NINT[7:0], MMD_SDM_NFRAC[22:11]@Nmmd (add SW dithering)  */
/*MT6169*/                        SCTRL_PLL|event_idx,             l1d_rf.IFN_data,                      /* CW170: MMD_SDM_NFRAC[10:0]@Nmmd (add SW dithering)                      */
/*MT6169*/                        SCTRL_PLL|event_idx,             BSI_CW(0xAB, cw171),                  /* CW171: MMD_SDM_NINT1[7:0], MMD_SDM_NFRAC1[22:11]@Nmmd (add SW dithering */
/*MT6169*/                        SCTRL_PLL|event_idx,             BSI_CW(0xAC, cw172),                  /* CW172: MMD_SDM_NFRAC1[10:0]@Nmmd (add SW dithering)                     */
/*MT6169*/                        SCTRL_TX_BAND|event_idx,         BSI_CW(0x44, cw68 ),                  /* CW68 : Set TX BAND and IO                                               */
/*MT6169*/                        SCTRL_TX_CFG|event_idx,          BSI_CW(0x45, cw69 ),                  /* CW69 : SET TX configuration                                             */
/*MT6169*/                        SCTRL_TX_BIAS1|event_idx,        SDATA_CW76_E3[l1d_rf.band],           /* CW76 : Set TX_BIAS1                                                     */
/*MT6169*/                        SCTRL_TX_BIAS2|event_idx,        BSI_CW(0x4D, cw77 ),                  /* CW77 : Set TX_BIAS2                                                     */
/*MT6169*/                        SCTRL_TX_RCF|event_idx,          SDATA_TX_CW72_E3,                     /* CW72 : Apply TXRCF trim bits: RG_TXRCF_CSEL[5:0]                        */
/*MT6169*/                        ctrl_dcxo,                       SDATA_AFCDAC|((l1d_rf.AFC_data&0x1FFF)<<7),    /* CW254: AFC DAC                                                 */
/*MT6169*/                        SCTRL_TXCAL_MODE|event_idx,      SDATA_TXCAL_MODE|SDATA_BAND_SEL[l1d_rf.band],  /* CW1  : Enter 2G TX cal mode */
/*MT6169*/                        SCTRL_RESERVED,                  0                                           ,  /* reserved */
/*MT6169*/                        SCTRL_RESERVED,                  0                                           ); /* reserved */
/*MT6169*/    }
/*MT6169*/    else
/*MT6169*/    {
/*MT6169*/       HWRITE_14_SDATA( SCTRL_CODETYPE|event_idx,        BSI_CW(0xA2, cw162),                  /* CW162: DCO_SCAK_CODETYP[11:0]@Fdco_tx                                   */
/*MT6169*/                        SCTRL_PLL|event_idx,             l1d_rf.RFN_data,                      /* CW169: MMD_SDM_NINT[7:0], MMD_SDM_NFRAC[22:11]@Nmmd (add SW dithering)  */
/*MT6169*/                        SCTRL_PLL|event_idx,             l1d_rf.IFN_data,                      /* CW170: MMD_SDM_NFRAC[10:0]@Nmmd (add SW dithering)                      */
/*MT6169*/                        SCTRL_PLL|event_idx,             BSI_CW(0xAB, cw171),                  /* CW171: MMD_SDM_NINT1[7:0], MMD_SDM_NFRAC1[22:11]@Nmmd (add SW dithering */
/*MT6169*/                        SCTRL_PLL|event_idx,             BSI_CW(0xAC, cw172),                  /* CW172: MMD_SDM_NFRAC1[10:0]@Nmmd (add SW dithering)                     */
/*MT6169*/                        SCTRL_LOOP_FILTER|event_idx,     SDATA_TX_CW157|(0x1<<13),             /* CW157: LF_K0[1:]=01                                                     */
/*MT6169*/                        SCTRL_TX_BAND|event_idx,         BSI_CW(0x44, cw68 ),                  /* CW68 : Set TX BAND and IO                                               */
/*MT6169*/                        SCTRL_TX_CFG|event_idx,          BSI_CW(0x45, cw69 ),                  /* CW69 : SET TX configuration                                             */
/*MT6169*/                        SCTRL_TX_BIAS1|event_idx,        SDATA_CW76[l1d_rf.band],              /* CW76 : Set TX_BIAS1                                                     */
/*MT6169*/                        SCTRL_TX_BIAS2|event_idx,        BSI_CW(0x4D, cw77 ),                  /* CW77 : Set TX_BIAS2                                                     */
/*MT6169*/                        SCTRL_TX_MOD  |event_idx,        SDATA_CW78[l1d_rf.band],              /* CW78 : Be care for if CW78 POR setting is change                        */
/*MT6169*/                        SCTRL_TX_RCF|event_idx,          BSI_CW(0x48, SDATA_TX_CW72 ),               /* CW72 : Apply TXRCF trim bits: RG_TXRCF_CSEL[5:0]                        */
/*MT6169*/                        ctrl_dcxo,                       SDATA_AFCDAC|((l1d_rf.AFC_data&0x1FFF)<<7),    /* CW254: AFC DAC                                                 */
/*MT6169*/                        SCTRL_TXCAL_MODE|event_idx,      SDATA_TXCAL_MODE|SDATA_BAND_SEL[l1d_rf.band]); /* CW1  : Enter 2G TX cal mode */
/*MT6169*/    }
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void  L1D_RF_SetSData_ST2( void )
/*MT6169*/ {
/*MT6169*/    SETUP_ST2();
/*MT6169*/    (void) event_idx;
/*MT6169*/
/*MT6169*/    HWRITE_5_SDATA( SCTRL_RESERVED, 0,   /* reserved */
/*MT6169*/                    SCTRL_RESERVED, 0,   /* reserved */
/*MT6169*/                    SCTRL_RESERVED, 0,   /* reserved */
/*MT6169*/                    SCTRL_RESERVED, 0,   /* reserved */
/*MT6169*/                    SCTRL_RESERVED, 0  );/* reserved */
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void  L1D_RF_SetSData_ST3( void )
/*MT6169*/ {
/*MT6169*/    SETUP_ST3();
/*MT6169*/
/*MT6169*/    if( ( MT6169_2G_CHIP_VER == MT6169_E3 ) )
/*MT6169*/    {
/*MT6169*/       HWRITE_4_SDATA( SCTRL_IDLE|event_idx,            SDATA_TX2SLEEP|SDATA_BAND_SEL[l1d_rf.band], /* CW1  : Sleep Mode           */
/*MT6169*/                       SCTRL_RESERVED, 0,                                                           /* reserved */
/*MT6169*/                       SCTRL_RESERVED, 0,                                                           /* reserved */
/*MT6169*/                       SCTRL_RESERVED, 0                                                          );/* reserved */
/*MT6169*/    }
/*MT6169*/    else
/*MT6169*/    {
/*MT6169*/       HWRITE_4_SDATA( SCTRL_IDLE|event_idx,            SDATA_TX2SLEEP|SDATA_BAND_SEL[l1d_rf.band], /* CW1  : Sleep Mode          */
/*MT6169*/                       SCTRL_TXRFLDO_MAN|event_idx,     SDATA_TX_CW70,                              /* CW70 : RG_TX_TXRFLDO_MAN=0 */
/*MT6169*/                       SCTRL_LOOP_FILTER|event_idx,     SDATA_TX_CW157,                              /* CW157: LF_K0=00            */
/*MT6169*/                       SCTRL_TX_MOD|event_idx,          POR_CW78                                  );/* CW78 : POR value            */
/*MT6169*/    }
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6169*/ {
/*MT6169*/    unsigned long cw72     = 0;
/*MT6169*/    unsigned long cw74     = 0;
/*MT6169*/    unsigned long cw75     = 0;
/*MT6169*/    unsigned long tx_g8sel = 0;
/*MT6169*/    signed char   txrcf_c    = (signed char)(SDATA_CW69[l1d_rf.band]&(0x3<<6))>>6;
/*MT6169*/    signed char   txrcf_csel = (txrcf_c==0x0) ? l1d_rf2.txrcf_csel[1] : l1d_rf2.txrcf_csel[0];
/*MT6169*/
/*MT6169*/    SETUP_ST2B_ST2M();
/*MT6169*/
/*MT6169*/    L1D_RF_TxGainSetting( l1d_rf.tx_mod_type2, l1d_rf.cur_slot, l1d_rf2.tx_power[l1d_rf.cur_slot], (FrequencyBand)l1d_rf.band, &cw74, &cw75 );
/*MT6169*/
/*MT6169*/    if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6169*/    {
/*MT6169*/       tx_g8sel = (0x1<<4);   /* 8PSK */
/*MT6169*/       /*             SDATA_TX_CW72 |        TXRCF_CSEL[5:0]       | TXGMSKLDOO_EN_M  | TXRFLDOO_EN_M  | TXRFLDOC_EN_M  */
/*MT6169*/       cw72 = (long) (SDATA_TX_CW72 |((txrcf_csel&0x3F)<<4)|     (0x0<<2)     |    (0x1<<1)    |    (0x1<<0)   );
/*MT6169*/    }
/*MT6169*/    else
/*MT6169*/    {
/*MT6169*/       tx_g8sel = (0x0<<4);   /* GMSK */
/*MT6169*/       /*             SDATA_TX_CW72 |        TXRCF_CSEL[5:0]       | TXGMSKLDOO_EN_M  | TXRFLDOO_EN_M  | TXRFLDOC_EN_M  */
/*MT6169*/       cw72 = (long) (SDATA_TX_CW72 |((txrcf_csel&0x3F)<<4)|      (0x1<<2)    |    (0x0<<1)    |    (0x1<<0)   );
/*MT6169*/    }
/*MT6169*/
/*MT6169*/    if( ( MT6169_2G_CHIP_VER == MT6169_E3 ) )
/*MT6169*/    {
/*MT6169*/       HWRITE_5_SDATA( SCTRL_TXBURST_MODE|event_idx, SDATA_TXBURST_MODE|tx_g8sel|SDATA_BAND_SEL[l1d_rf.band], /* CW1  : 2GTX Burst Mode | G/8 change | Band */
/*MT6169*/                       SCTRL_TXGAIN|event_idx,       BSI_CW(0x4A, cw74),                                      /* CW74 : TX Gain */
/*MT6169*/                       SCTRL_TXGAIN|event_idx,       BSI_CW(0x4B, cw75),                                      /* CW75 : TX Gain */
/*MT6169*/                       SCTRL_RESERVED,               0,                                                       /* reserved */
/*MT6169*/                       SCTRL_RESERVED,               0                                                      );/* reserved */
/*MT6169*/    }
/*MT6169*/    else
/*MT6169*/    {
/*MT6169*/       HWRITE_5_SDATA( SCTRL_TXRFLDO_MAN|event_idx,  SDATA_TX_CW70|(0x1<<18),                                 /* CW70 : Set TX_MAN_M */
/*MT6169*/                       SCTRL_TX_RCF|event_idx,       BSI_CW(0x48, cw72),                                      /* CW72 : Apply TXRCF trim bits: RG_TXRCF_CSEL[5:0] */
/*MT6169*/                       SCTRL_TXBURST_MODE|event_idx, SDATA_TXBURST_MODE|tx_g8sel|SDATA_BAND_SEL[l1d_rf.band], /* CW1  : 2GTX Burst Mode | G/8 change | Band */
/*MT6169*/                       SCTRL_TXGAIN|event_idx,       BSI_CW(0x4A, cw74),                                      /* CW74 : TX Gain */
/*MT6169*/                       SCTRL_TXGAIN|event_idx,       BSI_CW(0x4B, cw75)                                     );/* CW75 : TX Gain */
/*MT6169*/    }
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6169*/ {
/*MT6169*/    unsigned long cw72     = 0;
/*MT6169*/    unsigned long cw74     = 0;
/*MT6169*/    unsigned long cw75     = 0;
/*MT6169*/    unsigned long tx_g8sel = 0;
/*MT6169*/    signed char   txrcf_c    = (signed char)(SDATA_CW69[l1d_rf.band]&(0x3<<6))>>6;
/*MT6169*/    signed char   txrcf_csel = (txrcf_c==0x0) ? l1d_rf2.txrcf_csel[1] : l1d_rf2.txrcf_csel[0];
/*MT6169*/
/*MT6169*/    SETUP_ST2B_ST2M();
/*MT6169*/
/*MT6169*/    L1D_RF_TxGainSetting( l1d_rf.tx_mod_type2, l1d_rf.cur_slot, l1d_rf2.tx_power[l1d_rf.cur_slot], (FrequencyBand)l1d_rf.band, &cw74, &cw75 );
/*MT6169*/
/*MT6169*/    if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6169*/    {
/*MT6169*/       tx_g8sel = (0x1<<4);   /* 8PSK */
/*MT6169*/       /*             SDATA_TX_CW72 |        TXRCF_CSEL[5:0]       | TXGMSKLDOO_EN_M  | TXRFLDOO_EN_M  | TXRFLDOC_EN_M  */
/*MT6169*/       cw72 = (long) (SDATA_TX_CW72 |((txrcf_csel&0x3F)<<4)|     (0x0<<2)     |    (0x1<<1)    |    (0x1<<0)   );
/*MT6169*/    }
/*MT6169*/    else
/*MT6169*/    {
/*MT6169*/       tx_g8sel = (0x0<<4);   /* GMSK */
/*MT6169*/       /*             SDATA_TX_CW72 |        TXRCF_CSEL[5:0]       | TXGMSKLDOO_EN_M  | TXRFLDOO_EN_M  | TXRFLDOC_EN_M  */
/*MT6169*/       cw72 = (long) (SDATA_TX_CW72 |((txrcf_csel&0x3F)<<4)|      (0x1<<2)    |    (0x0<<1)    |    (0x1<<0)   );
/*MT6169*/    }
/*MT6169*/
/*MT6169*/    if( ( MT6169_2G_CHIP_VER == MT6169_E3 ) )
/*MT6169*/    {
/*MT6169*/       if( (l1d_rf.change)&(1<<l1d_rf.cur_slot) )
/*MT6169*/       {  /* modulation type changes */
/*MT6169*/          HWRITE_5_SDATA( SCTRL_TXBURST_MODE|event_idx, SDATA_TXBURST_MODE|tx_g8sel|SDATA_BAND_SEL[l1d_rf.band], /* CW1  : 2GTX Burst Mode | G/8 change | Band */
/*MT6169*/                          SCTRL_TXGAIN|event_idx,       BSI_CW(0x4A, cw74),                                      /* CW74 : TX Gain */
/*MT6169*/                          SCTRL_TXGAIN|event_idx,       BSI_CW(0x4B, cw75),                                      /* CW75 : TX Gain */
/*MT6169*/                          SCTRL_RESERVED,               0,                                                       /* reserved */
/*MT6169*/                          SCTRL_RESERVED,               0                                                      );/* reserved */
/*MT6169*/       }
/*MT6169*/       else
/*MT6169*/       {
/*MT6169*/          HWRITE_5_SDATA( SCTRL_TXGAIN|event_idx,       BSI_CW(0x4A, cw74),                                      /* CW74 : TX Gain */
/*MT6169*/                          SCTRL_TXGAIN|event_idx,       BSI_CW(0x4B, cw75),                                      /* CW75 : TX Gain */
/*MT6169*/                          SCTRL_RESERVED,               0,                                                       /* reserved */
/*MT6169*/                          SCTRL_RESERVED,               0,                                                       /* reserved */
/*MT6169*/                          SCTRL_RESERVED,               0                                                      );/* reserved */
/*MT6169*/       }
/*MT6169*/    }
/*MT6169*/    else
/*MT6169*/    {
/*MT6169*/       if( (l1d_rf.change)&(1<<l1d_rf.cur_slot) )
/*MT6169*/       {  /* modulation type changes */
/*MT6169*/          HWRITE_5_SDATA( SCTRL_TXRFLDO_MAN|event_idx,  SDATA_TX_CW70|(0x1<<18),                                 /* CW70 : Set TX_MAN_M */
/*MT6169*/                          SCTRL_TX_RCF|event_idx,       BSI_CW(0x48, cw72),                                      /* CW72 : Apply TXRCF trim bits: RG_TXRCF_CSEL[5:0] */
/*MT6169*/                          SCTRL_TXBURST_MODE|event_idx, SDATA_TXBURST_MODE|tx_g8sel|SDATA_BAND_SEL[l1d_rf.band], /* CW1  : 2GTX Burst Mode | G/8 change | Band */
/*MT6169*/                          SCTRL_TXGAIN|event_idx,       BSI_CW(0x4A, cw74),                                      /* CW74 : TX Gain */
/*MT6169*/                          SCTRL_TXGAIN|event_idx,       BSI_CW(0x4B, cw75)                                     );/* CW75 : TX Gain */
/*MT6169*/       }
/*MT6169*/       else
/*MT6169*/       {
/*MT6169*/          HWRITE_5_SDATA( SCTRL_TXRFLDO_MAN|event_idx,  SDATA_TX_CW70|(0x1<<18),                                 /* CW70 : Set TX_MAN_M */
/*MT6169*/                          SCTRL_TX_RCF|event_idx,       BSI_CW(0x48, cw72),                                      /* CW72 : Apply TXRCF trim bits: RG_TXRCF_CSEL[5:0] */
/*MT6169*/                          SCTRL_TXGAIN|event_idx,       BSI_CW(0x4A, cw74),                                      /* CW74 : TX Gain */
/*MT6169*/                          SCTRL_TXGAIN|event_idx,       BSI_CW(0x4B, cw75),                                      /* CW75 : TX Gain */
/*MT6169*/                          SCTRL_RESERVED,               0                                                      );/* reserved */
/*MT6169*/       }
/*MT6169*/    }
/*MT6169*/ }
/*MT6169*/
#endif

#if IS_RF_MT6166
/*MT6166*/
/*MT6166*/ /*..........................................................*/
/*MT6166*/ /*  Define Alias and Table                                  */
/*MT6166*/ /*..........................................................*/
/*MT6166*/
/*MT6166*/ #define  SCTRL_RXCAL_MODE              SCTRL_WORD(0,30)
/*MT6166*/ #define  SCTRL_RXBURST_MODE            SCTRL_WORD(0,30)
/*MT6166*/ #define  SCTRL_TXCAL_MODE              SCTRL_WORD(0,30)
/*MT6166*/ #define  SCTRL_TXBURST_MODE            SCTRL_WORD(0,30)
/*MT6166*/ #define  SCTRL_DCXO_CAFC_CTRL          SCTRL_WORD(0,30)
/*MT6166*/ #define  SCTRL_TXPORT                  SCTRL_WORD(0,30)
/*MT6166*/ #define  SCTRL_PLL                     SCTRL_WORD(0,30)
/*MT6166*/ #define  SCTRL_AGC                     SCTRL_WORD(0,30)
/*MT6166*/ #define  SCTRL_DCOC_RESET              SCTRL_WORD(0,30)
/*MT6166*/ #define  SCTRL_RX_LNA                  SCTRL_WORD(0,30)
/*MT6166*/ #define  SCTRL_TXGAIN                  SCTRL_WORD(0,30)
/*MT6166*/ #define  SCTRL_TEMP_MEAS               SCTRL_WORD(0,30)
/*MT6166*/ #define  SCTRL_IQSDM                   SCTRL_WORD(0,30)
/*MT6166*/ #define  SCTRL_RXRCCAL                 SCTRL_WORD(0,30)
/*MT6166*/ #define  SDATA_DCOC_RESET              BSI_CW(0x95, 0x00000)  /* CW149 : Reset DCOC                 */
/*MT6166*/ #define  SDATA_RX_LNA_MASK             BSI_CW(0x81, 0x00050)  /* CW129 : RX RXIF, LNA, DUAL talk mode Selection */
/*MT6166*/ #define  SDATA_RXCAL_MODE              BSI_CW(0xC9, 0x08200)  /* MODE=00001|DYN_EN=1|BAND=Variable */
/*MT6166*/ #define  SDATA_RXBURST_MODE            BSI_CW(0xC9, 0x10200)  /* MODE=00010|DYN_EN=1|BAND=Variable */
/*MT6166*/ #define  SDATA_RX2SLEEP                BSI_CW(0xC9, 0x00200)  /* MODE=00000|DYN_EN=1|BAND=Variable */
/*MT6166*/ #define  SDATA_TXCAL_MODE              BSI_CW(0xC9, 0x18200)  /* MODE=00011|DYN_EN=1|BAND=Variable */
/*MT6166*/ #define  SDATA_TXBURST_MODE            BSI_CW(0xC9, 0x20200)  /* MODE=00100|DYN_EN=1|BAND=Variable */
/*MT6166*/ #define  SDATA_TX2SLEEP                BSI_CW(0xC9, 0x00200)  /* MODE=00000|DYN_EN=1|BAND=Variable */
/*MT6166*/ #define  SDATA_DCXO_CAFC_CTL_MASK      BSI_CW(0xF7, 0x0003C)  /* CW247 : set DCXO AFC DAC          */
/*MT6166*/ #if IS_USE_INTERNAL_TEMP_SENSOR
/*MT6166*/ #define  SDATA_TEMP_MEAS               BSI_CW(0x13, 0x01464)  /* CW19 : THADC_EXT = 0 (Only Internal temp sensor measurement updates TXL_INIT_S bus for SX Calibration) */
/*MT6166*/ #else
/*MT6166*/ #define  SDATA_TEMP_MEAS               BSI_CW(0x13, 0x01465)  /* CW19 : THADC_EXT = 1 (external temp sensor measurement */
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ const unsigned long  SDATA_BAND_SEL[5] =
/*MT6166*/ {  /* CW201: Band Selection */
/*MT6166*/    0,    /* GSM  450 no support */
/*MT6166*/    0x5,  /* GSM  850 */
/*MT6166*/    0x8,  /* GSM  900 */
/*MT6166*/    0x3,  /* DCS 1800 */
/*MT6166*/    0x2,  /* PCS 1900 */
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ #if IS_DUAL_TALK_RX_GAIN_TABLE_CO_BAND_SUPPORT
/*MT6166*/    #if ( GSM850_PATH_SEL > LNA_2 ) || ( GSM_PATH_SEL > LNA_2 ) || ( DCS_PATH_SEL > LNA_2 ) || ( PCS_PATH_SEL > LNA_2 )
/*MT6166*/ #define LNA_path_shift   8
/*MT6166*/    #else
/*MT6166*/ #define LNA_path_shift  11
/*MT6166*/    #endif
/*MT6166*/ #else
/*MT6166*/ #define LNA_path_shift  11
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ CONST unsigned long  SDATA_RX_LNA_SEL[5] =
/*MT6166*/ {  /* CW129 : RX LNA Selection */
/*MT6166*/ #if IS_DCS_NB_WB_SWITCH_SUPPORT
/*MT6166*/    (DCS_NB_PATH_SEL<<LNA_path_shift),  /* use this field to store the DCS NB path */
/*MT6166*/ #else
/*MT6166*/    0,                      /* GSM  450 no support                     */
/*MT6166*/ #endif
/*MT6166*/    (GSM850_PATH_SEL<<LNA_path_shift),  /* GSM  850                          */
/*MT6166*/    (   GSM_PATH_SEL<<LNA_path_shift),  /* GSM  900                          */
/*MT6166*/    (   DCS_PATH_SEL<<LNA_path_shift),  /* DCS 1800                          */
/*MT6166*/    (   PCS_PATH_SEL<<LNA_path_shift),  /* PCS 1900                          */
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ /*..........................................................*/
/*MT6166*/ /* Serial Interface Implement                               */
/*MT6166*/ /*..........................................................*/
/*MT6166*/
/*MT6166*/ void  L1D_RF_SetSData_SR0( void )
/*MT6166*/ {
/*MT6166*/ }
/*MT6166*/
/*MT6166*/ void  L1D_RF_SetSData_SR1( void )
/*MT6166*/ {
/*MT6166*/    int            l1_obb_flag = 0;
/*MT6166*/    unsigned long  cw250,cw144;
/*MT6166*/    unsigned long  data_rx_band = SDATA_RX_LNA_SEL[l1d_rf.band];
/*MT6166*/    unsigned long  ctrl_dcxo    = SCTRL_DCXO_CAFC_CTRL;
/*MT6166*/    unsigned short afc_data;
/*MT6166*/    SETUP_SR1();
/*MT6166*/ #if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT && IS_32K_CRYSTAL_REMOVAL_SUPPORT
/*MT6166*/    if( l1d_rf.is_lock_dcxo && l1d_rf.dcxo_frac_fpm!=0 )
/*MT6166*/    {  cw250 = (POR_CW250 & (~0x00000FFF)) | (l1d_rf.dcxo_frac_fpm & 0xFFF);  }
/*MT6166*/    else
/*MT6166*/ #endif
/*MT6166*/    {  cw250 = POR_CW250;  }
/*MT6166*/
/*MT6166*/ #if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
/*MT6166*/    if( l1d_rf.band < FrequencyBand1800 )
/*MT6166*/    {  l1_obb_flag = (l1d_rf.blk_flag & LB_OBB_FOUND) ? 1 : 0; }
/*MT6166*/    else
/*MT6166*/    {  l1_obb_flag = (l1d_rf.blk_flag & HB_OBB_FOUND) ? 1 : 0; }
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/    if( (l1d_rf2.is_power_on_cal)&(RXRC_CAL_DONE) )
/*MT6166*/    {  cw144 = ( POR_CW144 &(~(RXIF_RCK_MASK)) ) | ( (l1d_rf2.rxif_rck_m&RXIF_RCK_MASK) );  } /* Re-write RXRC Value */
/*MT6166*/    else
/*MT6166*/    {  cw144 = POR_CW144;  }
/*MT6166*/
/*MT6166*/    afc_data = (L1D_RF_Check_DCXO_LPM()&0x1FFF);
/*MT6166*/
/*MT6166*/ #if IS_DCS_NB_WB_SWITCH_SUPPORT
/*MT6166*/    if( L1D_RF_IS_DCS_Change_to_NB() )
/*MT6166*/    {  /* change to the narrow band DCS setting */
/*MT6166*/       data_rx_band = SDATA_RX_LNA_SEL[0];
/*MT6166*/    }
/*MT6166*/ #endif
/*MT6166*/ #if IS_BSI_AFC_ACTIVE_SWITCH
/*MT6166*/    ctrl_dcxo = l1d_rf2.is_bsi_afc_active ? (SCTRL_DCXO_CAFC_CTRL|event_idx) : SCTRL_RESERVED;
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/    HWRITE_9_SDATA(  ctrl_dcxo,                              ((afc_data<<AFC_SHIFT_PART)&AFC_MASK_PART)|(AFC_VALUE_PART),                                         /* CW247 : set DCXO AFC DAC  */
/*MT6166*/                     SCTRL_DCOC_RESET|event_idx,             SDATA_DCOC_RESET,                                                                                           /* CW149 : Reset DCOC=0      */
/*MT6166*/                     SCTRL_PLL|event_idx,                    l1d_rf.RFN_data,                                                                                            /* CW223 : Set SRX Frequency */
/*MT6166*/                     SCTRL_PLL|event_idx,                    l1d_rf.IFN_data,                                                                                            /* CW224 : Set SRX Frequency */
/*MT6166*/                     SCTRL_RX_LNA|event_idx,                 OBBDET_INBURST_EN|SDATA_RX_LNA_MASK|RXIF_MODE|(l1_obb_flag<<17)|data_rx_band|RXDTK_EN,                      /* CW129 : set RXIF mode, LNA mode, DUAL talk mode  */
/*MT6166*/                     SCTRL_RXCAL_MODE|event_idx,             SDATA_RXCAL_MODE|SDATA_BAND_SEL[l1d_rf.band],                                                               /* CW201 : 2G RX Cal Mode | Band */
/*MT6166*/                     SCTRL_PLL|event_idx,                    BSI_CW( 0xFA, cw250 ),                                                                                      /* CW250 : 32K FPM Divider */
/*MT6166*/                     SCTRL_RXRCCAL|event_idx,                cw144,                                                                                                      /* CW144: write back power on RXRC cal result  */
/*MT6166*/                     SCTRL_RESERVED,                         0                                          );                                                               /* reserved */
/*MT6166*/ }
/*MT6166*/
/*MT6166*/ void  L1D_RF_SetSData_SR2( void )
/*MT6166*/ {
/*MT6166*/    SETUP_SR2();
/*MT6166*/
/*MT6166*/    if(IS_CONTINUOUS_RX_SLOT())
/*MT6166*/    {
/*MT6166*/       HWRITE_4_SDATA( SCTRL_AGC|event_idx    ,        (l1d_rf.AGC_data & 0xFFFFFFFL),                   /* CW131 : RX Gain */
/*MT6166*/                       SCTRL_RXBURST_MODE|event_idx,   SDATA_RXBURST_MODE|SDATA_BAND_SEL[l1d_rf.band],   /* CW201 : 2GRX Burst Mode | Band */
/*MT6166*/                       SCTRL_RESERVED,                 0,                                                /* reserved */
/*MT6166*/                       SCTRL_RESERVED,                 0                              );                 /* reserved */
/*MT6166*/    }
/*MT6166*/    else
/*MT6166*/    {
/*MT6166*/       HWRITE_4_SDATA( SCTRL_AGC|event_idx    ,        (l1d_rf.AGC_data & 0xFFFFFFFL),                   /* CW131 : RX Gain */
/*MT6166*/                       SCTRL_RXBURST_MODE|event_idx,   SDATA_RXBURST_MODE|SDATA_BAND_SEL[l1d_rf.band],   /* CW201 : 2GRX Burst Mode | Band */
/*MT6166*/                       SCTRL_TEMP_MEAS|event_idx,      SDATA_TEMP_MEAS,                                  /* CW19  : trigger RF to measure temperature */
/*MT6166*/                       SCTRL_RESERVED,                 0                              );                 /* reserved */
/*MT6166*/    }
/*MT6166*/ }
/*MT6166*/
/*MT6166*/ void  L1D_RF_SetSData_SR3( void )
/*MT6166*/ {
/*MT6166*/    SETUP_SR3();
/*MT6166*/
/*MT6166*/    HWRITE_1_SDATA( SCTRL_IDLE|event_idx, SDATA_RX2SLEEP|SDATA_BAND_SEL[l1d_rf.band]    ); /* CW201: Sleep Mode */
/*MT6166*/ }
/*MT6166*/
/*MT6166*/ void  L1D_RF_SetSData_ST0( void )
/*MT6166*/ {
/*MT6166*/ }
/*MT6166*/
/*MT6166*/ void  L1D_RF_SetSData_ST1( void )
/*MT6166*/ {
/*MT6166*/    unsigned short codetype     = 0;
/*MT6166*/    unsigned short DEM_Chunk_L1 = 0;
/*MT6166*/    unsigned short Nint         = 0;
/*MT6166*/    unsigned long  Nfrac        = 0;
/*MT6166*/    unsigned long  ctrl_dcxo    = SCTRL_DCXO_CAFC_CTRL;
/*MT6166*/    long  cw34,cw87,cw98,cw99,cw144;
/*MT6166*/
/*MT6166*/    SETUP_ST1();
/*MT6166*/
/*MT6166*/    L1D_RF_GetTxKDCOCAL2ndSetting( l1d_rf.band, (l1d_rf2.arfcn&0x3FF), &cw98, &cw99);
/*MT6166*/
/*MT6166*/    Nint         = (l1d_rf.RFN_data&(0xFF<<12))>>12;
/*MT6166*/    Nfrac        = ( (l1d_rf.RFN_data&0xFFF)<<11 ) | ( (l1d_rf.IFN_data&(0x7FF<<9))>>9 );
/*MT6166*/
/*MT6166*/    codetype     = L1D_RF_GetTxDCOSCACodeTypeSetting( Nint, Nfrac );
/*MT6166*/    DEM_Chunk_L1 = 0x7E;//L1D_RF_GetTxDEMChunkSetting( l1d_rf.band, Nint );
/*MT6166*/
/*MT6166*/    cw34 = ( l1d_rf.band<FrequencyBand1800 ) ? (POR_CW34|TX_2GLB_EN) : (POR_CW34|TX_2GHB_EN);
/*MT6166*/    cw87 = (long) (POR_CW87 | (codetype&0xFFF)<<8 | (DEM_Chunk_L1&0x7F)<<1);
/*MT6166*/
/*MT6166*/    if( (l1d_rf2.is_power_on_cal)&(RXRC_CAL_DONE) )
/*MT6166*/       cw144  = ( POR_CW144 &(~(RXIF_RCK_MASK)) ) | ( (l1d_rf2.rxif_rck_m&RXIF_RCK_MASK) );  /* Re-write RXRC Value */
/*MT6166*/    else
/*MT6166*/       cw144  = POR_CW144;
/*MT6166*/
/*MT6166*/ #if IS_BSI_AFC_ACTIVE_SWITCH
/*MT6166*/    ctrl_dcxo = l1d_rf2.is_bsi_afc_active ? (SCTRL_DCXO_CAFC_CTRL|event_idx) : SCTRL_RESERVED;
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/    HWRITE_9_SDATA(  ctrl_dcxo,                       ((l1d_rf.AFC_data<<AFC_SHIFT_PART)&AFC_MASK_PART)|(AFC_VALUE_PART),     /* CW247 : set DCXO AFC DAC  */
/*MT6166*/                     SCTRL_TXPORT|event_idx,          BSI_CW(0x22, cw34),        /* CW34 : Enable correct TX band output */
/*MT6166*/                     SCTRL_PLL|event_idx,             l1d_rf.RFN_data,           /* CW96 : STX NMMD0: STX_MMD_SDM_NINT[7:0], STX_MMD_SDM_NFRAC[22:11] */
/*MT6166*/                     SCTRL_PLL|event_idx,             l1d_rf.IFN_data,           /* CW97 : STX NMMD0, DA_OFFSET: STX_MMD_SDM_NFRAC[10:0], STX_MMD_DA_OFFSET[4:0] */
/*MT6166*/                     SCTRL_PLL|event_idx,             BSI_CW(0x57, cw87),        /* CW87 : STX_DCO_SCAK_CODETYP[11:0],STX_DEM_chunk [6:0] */
/*MT6166*/                     SCTRL_PLL|event_idx,             BSI_CW(0x62, cw98),        /* CW98 : STX NMMD1 for KDCO cal.: STX_MMD_SDM_NINT1[7:0], STX_MMD_SDM_NFRAC1[22:11] */
/*MT6166*/                     SCTRL_PLL|event_idx,             BSI_CW(0x63, cw99),        /* CW99 : STX NMMD1 for KDCO cal.: STX_MMD_SDM_NFRAC1[10:0]. */
/*MT6166*/                     SCTRL_RXRCCAL|event_idx,         cw144,                     /* CW144: write back power on RXRC cal result  */
/*MT6166*/                     SCTRL_TXCAL_MODE|event_idx,      SDATA_TXCAL_MODE|SDATA_BAND_SEL[l1d_rf.band] ); /* CW201  : 2GTX Cal. Mode | Band */
/*MT6166*/ }
/*MT6166*/
/*MT6166*/ void  L1D_RF_SetSData_ST2( void )
/*MT6166*/ {
/*MT6166*/    SETUP_ST2();
/*MT6166*/    (void) event_idx;
/*MT6166*/    HWRITE_4_SDATA( SCTRL_RESERVED, 0,   /* reserved */
/*MT6166*/                    SCTRL_RESERVED, 0,   /* reserved */
/*MT6166*/                    SCTRL_RESERVED, 0,   /* reserved */
/*MT6166*/                    SCTRL_RESERVED, 0  );/* reserved */
/*MT6166*/ }
/*MT6166*/
/*MT6166*/ void  L1D_RF_SetSData_ST3( void )
/*MT6166*/ {
/*MT6166*/    SETUP_ST3();
/*MT6166*/
/*MT6166*/    HWRITE_1_SDATA( SCTRL_IDLE|event_idx, SDATA_TX2SLEEP|SDATA_BAND_SEL[l1d_rf.band]  );/* CW201: Sleep Mode */
/*MT6166*/ }
/*MT6166*/
/*MT6166*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6166*/ {
/*MT6166*/    unsigned long  cw41     = 0;
/*MT6166*/    unsigned long  cw42     = 0;
/*MT6166*/    unsigned long  cw117    = 0;
/*MT6166*/    unsigned short Nint     = 0;
/*MT6166*/    unsigned long  Nfrac    = 0;
/*MT6166*/    unsigned long  tx_g8sel = 0;
/*MT6166*/
/*MT6166*/    SETUP_ST2B_ST2M();
/*MT6166*/
/*MT6166*/    L1D_RF_TxGainSetting( l1d_rf.tx_mod_type2, l1d_rf.cur_slot, l1d_rf2.tx_power[l1d_rf.cur_slot], (FrequencyBand)l1d_rf.band, &cw41, &cw42 );
/*MT6166*/
/*MT6166*/    if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6166*/       tx_g8sel = (0x1<<11);   /* 8PSK */
/*MT6166*/    else
/*MT6166*/       tx_g8sel = (0x0<<11);   /* GMSK */
/*MT6166*/
/*MT6166*/    Nint         = (l1d_rf.RFN_data&(0xFF<<12))>>12;
/*MT6166*/    Nfrac        = ( (l1d_rf.RFN_data&0xFFF)<<11 ) | ( (l1d_rf.IFN_data&(0x7FF<<9))>>9 );
/*MT6166*/
/*MT6166*/    if((( (Nint==143) && (Nfrac==8259552))||( (Nint==144) && (Nfrac==129056))) && (!tx_g8sel))
/*MT6166*/       cw117 = (POR_CW117&0xDFFFF)| (1<<17);   /* PCS 620 or PCS 622 and GMSK modulation, set CW117 IQSDM_INT_ONLY_EN=1 */
/*MT6166*/    else
/*MT6166*/       cw117 = (POR_CW117&0xDFFFF)| (0<<17);
/*MT6166*/
/*MT6166*/    HWRITE_4_SDATA( SCTRL_IQSDM|event_idx,        BSI_CW(0x75, cw117),                                          /* CW117: Turn off am path SDM modulator to impromve ch620,622 GMSK ORFS*/
/*MT6166*/                    SCTRL_TXGAIN|event_idx,       BSI_CW(0x29, cw41 ),                                          /* CW41 : TX Gain */
/*MT6166*/                    SCTRL_TXGAIN|event_idx,       BSI_CW(0x2A, cw42 ),                                          /* CW42 : TX Gain */
/*MT6166*/                    SCTRL_TXBURST_MODE|event_idx, SDATA_TXBURST_MODE|tx_g8sel|SDATA_BAND_SEL[l1d_rf.band]    ); /* CW201: 2GTX Burst Mode | G/8 change | Band */
/*MT6166*/ }
/*MT6166*/
/*MT6166*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6166*/ {
/*MT6166*/    unsigned long  cw41     = 0;
/*MT6166*/    unsigned long  cw42     = 0;
/*MT6166*/    unsigned long  cw117    = 0;
/*MT6166*/    unsigned long  tx_g8sel = 0;
/*MT6166*/
/*MT6166*/    SETUP_ST2B_ST2M();
/*MT6166*/
/*MT6166*/    L1D_RF_TxGainSetting( l1d_rf.tx_mod_type2, l1d_rf.cur_slot, l1d_rf2.tx_power[l1d_rf.cur_slot], (FrequencyBand)l1d_rf.band, &cw41, &cw42 );
/*MT6166*/
/*MT6166*/    if( (l1d_rf.change)&(1<<l1d_rf.cur_slot) )
/*MT6166*/    {  /* modulation type changes */
/*MT6166*/
/*MT6166*/       if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6166*/          tx_g8sel = (0x1<<11);   /* change g->8 CW1 D[11] */
/*MT6166*/       else
/*MT6166*/          tx_g8sel = (0x0<<11);   /* change 8->g CW1 D[11] */
/*MT6166*/
/*MT6166*/       if(!tx_g8sel)
/*MT6166*/          cw117 = (POR_CW117&0xDFFFF)| (1<<17);   /* PCS 620 or PCS 622 and GMSK modulation, set CW117 IQSDM_INT_ONLY_EN=1 */
/*MT6166*/       else
/*MT6166*/          cw117 = (POR_CW117&0xDFFFF)| (0<<17);
/*MT6166*/
/*MT6166*/       HWRITE_4_SDATA( SCTRL_IQSDM|event_idx,        BSI_CW(0x75, cw117),                                          /* CW117: Turn off am path SDM modulator to impromve ch620,622 GMSK ORFS*/
/*MT6166*/                       SCTRL_TXGAIN|event_idx,       BSI_CW(0x29, cw41 ),                                          /* CW41 : TX Gain */
/*MT6166*/                       SCTRL_TXGAIN|event_idx,       BSI_CW(0x2A, cw42 ),                                          /* CW42 : TX Gain */
/*MT6166*/                       SCTRL_TXBURST_MODE|event_idx, SDATA_TXBURST_MODE|tx_g8sel|SDATA_BAND_SEL[l1d_rf.band]    ); /* CW201: 2GTX Burst Mode | G/8 change | Band */
/*MT6166*/    }
/*MT6166*/    else
/*MT6166*/    {
/*MT6166*/       HWRITE_4_SDATA( SCTRL_TXGAIN|event_idx,       BSI_CW(0x29, cw41),                                           /* CW41 : TX Gain */
/*MT6166*/                       SCTRL_TXGAIN|event_idx,       BSI_CW(0x2A, cw42),                                           /* CW42 : TX Gain */
/*MT6166*/                       SCTRL_RESERVED,               0,                                                            /* reserved */
/*MT6166*/                       SCTRL_RESERVED,               0                                                          ); /* reserved */
/*MT6166*/    }
/*MT6166*/ }
/*MT6166*/
#endif
#if IS_RF_MT6165
/*MT6165*/
/*MT6165*/ /*..........................................................*/
/*MT6165*/ /*  Define Alias and Table                                  */
/*MT6165*/ /*..........................................................*/
/*MT6165*/
/*MT6165*/ #define  SCTRL_RXCAL_MODE              SCTRL_WORD(0,30)
/*MT6165*/ #define  SCTRL_RXBURST_MODE            SCTRL_WORD(0,30)
/*MT6165*/ #define  SCTRL_TXCAL_MODE              SCTRL_WORD(0,30)
/*MT6165*/ #define  SCTRL_TXBURST_MODE            SCTRL_WORD(0,30)
/*MT6165*/ #define  SCTRL_DCXO_CAFC_CTRL          SCTRL_WORD(0,30)
/*MT6165*/ #define  SCTRL_TXPORT                  SCTRL_WORD(0,30)
/*MT6165*/ #define  SCTRL_PLL                     SCTRL_WORD(0,30)
/*MT6165*/ #define  SCTRL_AGC                     SCTRL_WORD(0,30)
/*MT6165*/ #define  SCTRL_TXGAIN                  SCTRL_WORD(0,30)
/*MT6165*/ #define  SCTRL_TEMP_MEAS               SCTRL_WORD(0,30)
/*MT6165*/ #define  SDATA_RXCAL_MODE              BSI_CW(0x01, 0x14000)  /* MODE=0001           |DYN_EN=1|LNA=Variable|BAND=Variable */
/*MT6165*/ #define  SDATA_RXBURST_MODE            BSI_CW(0x01, 0x24000)  /* MODE=0010           |DYN_EN=1|LNA=Variable|BAND=Variable */
/*MT6165*/ #define  SDATA_RX2SLEEP                BSI_CW(0x01, 0x04000)  /* MODE=0000           |DYN_EN=1|LNA=0       |BAND=Variable */
/*MT6165*/ #define  SDATA_TXCAL_MODE              BSI_CW(0x01, 0x3C000)  /* MODE=0011|TX_G8SEL=1|DYN_EN=1|LNA=0       |BAND=Variable */
/*MT6165*/ #define  SDATA_TXBURST_MODE            BSI_CW(0x01, 0x44000)  /* MODE=0100           |DYN_EN=1|LNA=0       |BAND=Variable */
/*MT6165*/ #define  SDATA_TX2SLEEP                BSI_CW(0x01, 0x04000)  /* MODE=0000           |DYN_EN=1|LNA=0       |BAND=Variable */
/*MT6165*/ #define  SDATA_TEMP_MEAS               BSI_CW(0x10, 0x0501E)  /* CW16 : Trigger THADC                          */
/*MT6165*/
/*MT6165*/ const unsigned long  SDATA_BAND_SEL[5] =
/*MT6165*/ {  /* CW1: Band Selection */
/*MT6165*/    0,    /* GSM  450 no support */
/*MT6165*/    0x0,  /* GSM  850 */
/*MT6165*/    0x1,  /* GSM  900 */
/*MT6165*/    0x2,  /* DCS 1800 */
/*MT6165*/    0x3,  /* PCS 1900 */
/*MT6165*/ };
/*MT6165*/
/*MT6165*/ CONST unsigned long  SDATA_RX_LNA_SEL[5] =
/*MT6165*/ {  /* CW1 : RX LNA Selection */
/*MT6165*/ #if IS_DCS_NB_WB_SWITCH_SUPPORT
/*MT6165*/    (DCS_NB_PATH_SEL<<4),  /* use this field to store the DCS NB path */
/*MT6165*/ #else
/*MT6165*/    0,                     /* GSM  450 no support                     */
/*MT6165*/ #endif
/*MT6165*/    (GSM850_PATH_SEL<<4),  /* GSM  850, LNA2                          */
/*MT6165*/    (   GSM_PATH_SEL<<4),  /* GSM  900, LNA2                          */
/*MT6165*/    (   DCS_PATH_SEL<<4),  /* DCS 1800, LNA1                          */
/*MT6165*/    (   PCS_PATH_SEL<<4),  /* PCS 1900, LNA1                          */
/*MT6165*/ };
/*MT6165*/
/*MT6165*/ /*..........................................................*/
/*MT6165*/ /* Serial Interface Implement                               */
/*MT6165*/ /*..........................................................*/
/*MT6165*/
/*MT6165*/ void  L1D_RF_SetSData_SR0( void )
/*MT6165*/ {
/*MT6165*/ }
/*MT6165*/
/*MT6165*/ void  L1D_RF_SetSData_SR1( void )
/*MT6165*/ {
/*MT6165*/    int            l1_obb_flag = 0;
/*MT6165*/    unsigned long  ctrl_dcxo   = SCTRL_DCXO_CAFC_CTRL;
/*MT6165*/    unsigned long  Nfrac,cw174,cw184,cw250,cw169,cw160,cw175,cw176,cw179;
/*MT6165*/    unsigned long  data_rx_band = SDATA_RX_LNA_SEL[l1d_rf.band];
/*MT6165*/    unsigned short Nint,daoffset,noffset,codetype,afc_data;
/*MT6165*/    SETUP_SR1();
/*MT6165*/ #if IS_DUAL_LOOP_AFC_CONTROL_SUPPORT && IS_32K_CRYSTAL_REMOVAL_SUPPORT
/*MT6165*/    if( l1d_rf.is_lock_dcxo && l1d_rf.dcxo_frac_fpm!=0 )
/*MT6165*/    {  cw250 = (POR_CW250 & (~0x00000FFF)) | (l1d_rf.dcxo_frac_fpm & 0xFFF);  }
/*MT6165*/    else
/*MT6165*/ #endif
/*MT6165*/    {  cw250 = POR_CW250;  }
/*MT6165*/
/*MT6165*/ #if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
/*MT6165*/    if( l1d_rf.band < FrequencyBand1800 )
/*MT6165*/    {  l1_obb_flag = (l1d_rf.blk_flag & LB_OBB_FOUND) ? 1 : 0; }
/*MT6165*/    else
/*MT6165*/    {  l1_obb_flag = (l1d_rf.blk_flag & HB_OBB_FOUND) ? 1 : 0; }
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/    Nint         = (l1d_rf.RFN_data&(0xFF<<12))>>12;
/*MT6165*/    Nfrac        = ( (l1d_rf.RFN_data&0xFFF)<<11 ) | ( (l1d_rf.IFN_data&(0x7FF<<9))>>9 );
/*MT6165*/
/*MT6165*/    codetype = L1D_RF_GetSxDCOSCACodeTypeSetting( Nint, Nfrac );
/*MT6165*/    daoffset = L1D_RF_GetSxDAoffsetSetting(l1d_rf.RFN_data);
/*MT6165*/    noffset  = L1D_RF_GetSCAKNoffsetSetting(Nint);
/*MT6165*/    afc_data = (L1D_RF_Check_DCXO_LPM()&0x1FFF);
/*MT6165*/
/*MT6165*/    cw174=((POR_CW174&(~0x000FFF00))|((codetype&0xFFF)<<8));
/*MT6165*/    cw184=((POR_CW184&(~0x0000003C))|((noffset&0xF)<<2));
/*MT6165*/    cw169=POR_CW169;
/*MT6165*/    cw160=0x1254A;
/*MT6165*/    cw175=0x03EC4;
/*MT6165*/    cw176=0x25054;
/*MT6165*/    cw179=0xFF34F;
/*MT6165*/
/*MT6165*/ #if IS_DCS_NB_WB_SWITCH_SUPPORT
/*MT6165*/    if( L1D_RF_IS_DCS_Change_to_NB() )
/*MT6165*/    {  /* change to the narrow band DCS setting */
/*MT6165*/       data_rx_band = SDATA_RX_LNA_SEL[0];
/*MT6165*/    }
/*MT6165*/ #endif
/*MT6165*/ #if IS_BSI_AFC_ACTIVE_SWITCH
/*MT6165*/    ctrl_dcxo = l1d_rf2.is_bsi_afc_active ? (SCTRL_DCXO_CAFC_CTRL|event_idx) : SCTRL_RESERVED;
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/    HWRITE_13_SDATA( ctrl_dcxo,                              ((afc_data<<AFC_SHIFT_PART)&AFC_MASK_PART)|(AFC_VALUE_PART),           /* CW247 : set DCXO AFC DAC  */
/*MT6165*/                     SCTRL_PLL|event_idx,                    l1d_rf.RFN_data,                                                               /* CW181 : Set SRX Frequency */
/*MT6165*/                     SCTRL_PLL|event_idx,                    l1d_rf.IFN_data|(0x1<<9)|((daoffset&0xFF)<<1),                                 /* CW182 : Set SRX Frequency */
/*MT6165*/                     SCTRL_PLL|event_idx,                    BSI_CW( 0xAE, cw174 ),                                                         /* CW174 : Set DCO Codetype */
/*MT6165*/                     SCTRL_PLL|event_idx,                    BSI_CW( 0xB8, cw184 ),                                                         /* CW184 : STX NMMD1 for KDCO cal. */
/*MT6165*/                     SCTRL_PLL|event_idx,                    BSI_CW( 0xA9, cw169 ),                                                         /* CW169 : PLL BW Setting */
/*MT6165*/                     SCTRL_PLL|event_idx,                    BSI_CW( 0xA0, cw160 ),                                                         /* CW160 : TX in RX Band Noise Improve. */
/*MT6165*/                     SCTRL_PLL|event_idx,                    BSI_CW( 0xAF, cw175 ),                                                         /* CW175 : TX in RX Band Noise Improve. */
/*MT6165*/                     SCTRL_PLL|event_idx,                    BSI_CW( 0xB0, cw176 ),                                                         /* CW176 : TX in RX Band Noise Improve. */
/*MT6165*/                     SCTRL_PLL|event_idx,                    BSI_CW( 0xB3, cw179 ),                                                         /* CW179 : TX in RX Band Noise Improve. */
/*MT6165*/                     SCTRL_RXCAL_MODE|event_idx,             SDATA_RXCAL_MODE|(l1_obb_flag<<12)|data_rx_band|SDATA_BAND_SEL[l1d_rf.band],   /* CW1   : 2GRX Cal. Mode | OBB Flag | LNA Port | Band */
/*MT6165*/                     SCTRL_PLL|event_idx,                    BSI_CW( 0xFA, cw250 ),                                                         /* CW250 : Set FPM Divider */
/*MT6165*/                     SCTRL_TEMP_MEAS|event_idx,              SDATA_TEMP_MEAS     );                                                         /* CW16  : Trigger THADC                          */
/*MT6165*/ }
/*MT6165*/
/*MT6165*/ void  L1D_RF_SetSData_SR2( void )
/*MT6165*/ {
/*MT6165*/    int            l1_obb_flag = 0;
/*MT6165*/    unsigned long  data_rx_band = SDATA_RX_LNA_SEL[l1d_rf.band];
/*MT6165*/    SETUP_SR2();
/*MT6165*/
/*MT6165*/ #if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
/*MT6165*/    if( l1d_rf.band < FrequencyBand1800 )
/*MT6165*/    {  l1_obb_flag = (l1d_rf.blk_flag & LB_OBB_FOUND) ? 1 : 0; }
/*MT6165*/    else
/*MT6165*/    {  l1_obb_flag = (l1d_rf.blk_flag & HB_OBB_FOUND) ? 1 : 0; }
/*MT6165*/ #endif
/*MT6165*/ #if IS_DCS_NB_WB_SWITCH_SUPPORT
/*MT6165*/    if( L1D_RF_IS_DCS_Change_to_NB() )
/*MT6165*/    {  /* change to the narrow band DCS setting */
/*MT6165*/       data_rx_band = SDATA_RX_LNA_SEL[0];
/*MT6165*/    }
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/    if(IS_CONTINUOUS_RX_SLOT())
/*MT6165*/    {
/*MT6165*/       HWRITE_3_SDATA( SCTRL_AGC|event_idx    ,        (l1d_rf.AGC_data & 0xFFFFFFFL),                                                                   /* CW66 : RX Gain */
/*MT6165*/                       SCTRL_RXBURST_MODE|event_idx,   SDATA_RXBURST_MODE|(l1_obb_flag<<12)|data_rx_band|SDATA_BAND_SEL[l1d_rf.band],   /* CW1   : 2GRX Burst Mode | OBB Flag | LNA Port | Band */
/*MT6165*/                       SCTRL_RESERVED,                 0                              );                                                                 /* reserved */
/*MT6165*/    }
/*MT6165*/    else
/*MT6165*/    {
/*MT6165*/       HWRITE_3_SDATA( SCTRL_AGC|event_idx    ,        (l1d_rf.AGC_data & 0xFFFFFFFL),                                                                   /* CW66 : RX Gain */
/*MT6165*/                       SCTRL_RXBURST_MODE|event_idx,   SDATA_RXBURST_MODE|(l1_obb_flag<<12)|data_rx_band|SDATA_BAND_SEL[l1d_rf.band],   /* CW1   : 2GRX Burst Mode | OBB Flag | LNA Port | Band */
/*MT6165*/                       SCTRL_RESERVED,                 0                              );                                                                 /* reserved */
/*MT6165*/    }
/*MT6165*/ }
/*MT6165*/
/*MT6165*/ void  L1D_RF_SetSData_SR3( void )
/*MT6165*/ {
/*MT6165*/    SETUP_SR3();
/*MT6165*/
/*MT6165*/    HWRITE_1_SDATA( SCTRL_IDLE|event_idx, SDATA_RX2SLEEP|SDATA_BAND_SEL[l1d_rf.band] );               /* CW1   : Sleep Mode */
/*MT6165*/ }
/*MT6165*/
/*MT6165*/ void  L1D_RF_SetSData_ST0( void )
/*MT6165*/ {
/*MT6165*/ }
/*MT6165*/
/*MT6165*/ void  L1D_RF_SetSData_ST1( void )
/*MT6165*/ {
/*MT6165*/    long           cw174,cw183,cw184,cw169,cw160,cw175,cw176,cw179;
/*MT6165*/    unsigned long  Nfrac;
/*MT6165*/    unsigned short Nint,daoffset,noffset,codetype;
/*MT6165*/    unsigned long  ctrl_dcxo = SCTRL_DCXO_CAFC_CTRL;
/*MT6165*/
/*MT6165*/    SETUP_ST1();
/*MT6165*/
/*MT6165*/    L1D_RF_GetTxKDCOCAL2ndSetting( l1d_rf.band, (l1d_rf2.arfcn&0x3FF), &cw183, &cw184);
/*MT6165*/
/*MT6165*/    Nint         = (l1d_rf.RFN_data&(0xFF<<12))>>12;
/*MT6165*/    Nfrac        = ( (l1d_rf.RFN_data&0xFFF)<<11 ) | ( (l1d_rf.IFN_data&(0x7FF<<9))>>9 );
/*MT6165*/
/*MT6165*/    codetype = L1D_RF_GetSxDCOSCACodeTypeSetting( Nint, Nfrac );
/*MT6165*/    daoffset = L1D_RF_GetSxDAoffsetSetting(l1d_rf.RFN_data);
/*MT6165*/    noffset  = L1D_RF_GetSCAKNoffsetSetting(Nint);
/*MT6165*/
/*MT6165*/    cw174=((POR_CW174&(~0x000FFF00))|((codetype&0xFFF)<<8));
/*MT6165*/    cw184=((cw184    &(~0x0000003C))|((noffset&0xF)<<2));
/*MT6165*/
/*MT6165*/    cw169=0x02060;
/*MT6165*/    cw160=0x1250A;
/*MT6165*/    cw175=0x03EC6;
/*MT6165*/    cw176=0x25040;
/*MT6165*/    cw179=0xFF10F;
/*MT6165*/
/*MT6165*/ #if IS_BSI_AFC_ACTIVE_SWITCH
/*MT6165*/    ctrl_dcxo = l1d_rf2.is_bsi_afc_active ? (SCTRL_DCXO_CAFC_CTRL|event_idx) : SCTRL_RESERVED;
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/    HWRITE_13_SDATA( ctrl_dcxo,                       ((l1d_rf.AFC_data<<AFC_SHIFT_PART)&AFC_MASK_PART)|(AFC_VALUE_PART),   /* CW247 : set DCXO AFC DAC  */
/*MT6165*/                     SCTRL_PLL|event_idx,             l1d_rf.RFN_data,                                                      /* CW181 : Set SRX Frequency */
/*MT6165*/                     SCTRL_PLL|event_idx,             l1d_rf.IFN_data|(0x1<<9)|((daoffset&0xFF)<<1),                        /* CW182 : Set SRX Frequency */
/*MT6165*/                     SCTRL_PLL|event_idx,             BSI_CW( 0xAE, cw174 ),                                                /* CW174 : Set DCO Codetype */
/*MT6165*/                     SCTRL_PLL|event_idx,             BSI_CW( 0xB7, cw183),                                                 /* CW183 : STX NMMD1 for KDCO cal. */
/*MT6165*/                     SCTRL_PLL|event_idx,             BSI_CW( 0xB8, cw184 ),                                                /* CW184 : STX NMMD1 for KDCO cal. */
/*MT6165*/                     SCTRL_PLL|event_idx,             BSI_CW( 0xA9, cw169 ),                                                /* CW169 : PLL BW Setting */
/*MT6165*/                     SCTRL_PLL|event_idx,             BSI_CW( 0xA0, cw160 ),                                                /* CW160 : TX in RX Band Noise Improve. */
/*MT6165*/                     SCTRL_PLL|event_idx,             BSI_CW( 0xAF, cw175 ),                                                /* CW175 : TX in RX Band Noise Improve. */
/*MT6165*/                     SCTRL_PLL|event_idx,             BSI_CW( 0xB0, cw176 ),                                                /* CW176 : TX in RX Band Noise Improve. */
/*MT6165*/                     SCTRL_PLL|event_idx,             BSI_CW( 0xB3, cw179 ),                                                /* CW179 : TX in RX Band Noise Improve. */
/*MT6165*/                     SCTRL_TXCAL_MODE|event_idx,      SDATA_TXCAL_MODE|SDATA_BAND_SEL[l1d_rf.band],                         /* CW1   : 2GTX Cal. Mode | Band */
/*MT6165*/                     SCTRL_RESERVED, 0                                                                       );             /* reserved */
/*MT6165*/ }
/*MT6165*/
/*MT6165*/ void  L1D_RF_SetSData_ST2( void )
/*MT6165*/ {
/*MT6165*/    SETUP_ST2();
/*MT6165*/    (void) event_idx;
/*MT6165*/    HWRITE_3_SDATA( SCTRL_RESERVED, 0,   /* reserved */
/*MT6165*/                    SCTRL_RESERVED, 0,   /* reserved */
/*MT6165*/                    SCTRL_RESERVED, 0  );/* reserved */
/*MT6165*/ }
/*MT6165*/
/*MT6165*/ void  L1D_RF_SetSData_ST3( void )
/*MT6165*/ {
/*MT6165*/    SETUP_ST3();
/*MT6165*/
/*MT6165*/    HWRITE_1_SDATA( SCTRL_IDLE|event_idx, SDATA_TX2SLEEP|SDATA_BAND_SEL[l1d_rf.band] );                 /* CW1   : Sleep Mode */
/*MT6165*/ }
/*MT6165*/
/*MT6165*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6165*/ {
/*MT6165*/    unsigned long  cw130    = 0;
/*MT6165*/    unsigned long  cw131    = 0;
/*MT6165*/    unsigned long  tx_g8sel = 0;
/*MT6165*/
/*MT6165*/    SETUP_ST2B_ST2M();
/*MT6165*/
/*MT6165*/    L1D_RF_TxGainSetting( l1d_rf.tx_mod_type2, l1d_rf.cur_slot, l1d_rf2.tx_power[l1d_rf.cur_slot], (FrequencyBand)l1d_rf.band, &cw130, &cw131 );
/*MT6165*/
/*MT6165*/    cw130 = ( l1d_rf.band<FrequencyBand1800 ) ? (cw130|TX_2GLB_EN) : (cw130|TX_2GHB_EN);
/*MT6165*/
/*MT6165*/    if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6165*/       tx_g8sel = (0x1<<15);   /* 8PSK */
/*MT6165*/    else
/*MT6165*/       tx_g8sel = (0x0<<15);   /* GMSK */
/*MT6165*/
/*MT6165*/    HWRITE_3_SDATA( SCTRL_TXGAIN|event_idx,       BSI_CW(0x82, cw130 ),                                             /* CW130 : TX Gain */
/*MT6165*/                    SCTRL_TXGAIN|event_idx,       BSI_CW(0x83, cw131 ),                                             /* CW131 : TX Gain */
/*MT6165*/                    SCTRL_TXBURST_MODE|event_idx, SDATA_TXBURST_MODE|tx_g8sel|SDATA_BAND_SEL[l1d_rf.band]    );     /* CW1   : 2GTX Burst Mode | G/8 change | Band */
/*MT6165*/ }
/*MT6165*/
/*MT6165*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6165*/ {
/*MT6165*/    unsigned long  cw130    = 0;
/*MT6165*/    unsigned long  cw131    = 0;
/*MT6165*/    unsigned long  tx_g8sel = 0;
/*MT6165*/
/*MT6165*/    SETUP_ST2B_ST2M();
/*MT6165*/
/*MT6165*/    L1D_RF_TxGainSetting( l1d_rf.tx_mod_type2, l1d_rf.cur_slot, l1d_rf2.tx_power[l1d_rf.cur_slot], (FrequencyBand)l1d_rf.band, &cw130, &cw131 );
/*MT6165*/
/*MT6165*/    cw130 = ( l1d_rf.band<FrequencyBand1800 ) ? (cw130|TX_2GLB_EN) : (cw130|TX_2GHB_EN);
/*MT6165*/
/*MT6165*/    if( (l1d_rf.change)&(1<<l1d_rf.cur_slot) )
/*MT6165*/    {  /* modulation type changes */
/*MT6165*/
/*MT6165*/       if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6165*/          tx_g8sel = (0x1<<15);   /* change g->8 CW1 D[11] */
/*MT6165*/       else
/*MT6165*/          tx_g8sel = (0x0<<15);   /* change 8->g CW1 D[11] */
/*MT6165*/
/*MT6165*/       HWRITE_3_SDATA( SCTRL_TXGAIN|event_idx,       BSI_CW(0x82, cw130 ),                                          /* CW130 : TX Gain */
/*MT6165*/                       SCTRL_TXGAIN|event_idx,       BSI_CW(0x83, cw131 ),                                          /* CW131 : TX Gain */
/*MT6165*/                       SCTRL_TXBURST_MODE|event_idx, SDATA_TXBURST_MODE|tx_g8sel|SDATA_BAND_SEL[l1d_rf.band]    );  /* CW1   : 2GTX Burst Mode | G/8 change | Band */
/*MT6165*/    }
/*MT6165*/    else
/*MT6165*/    {
/*MT6165*/       HWRITE_3_SDATA( SCTRL_TXGAIN|event_idx,       BSI_CW(0x82, cw130),                                           /* CW130 : TX Gain */
/*MT6165*/                       SCTRL_TXGAIN|event_idx,       BSI_CW(0x83, cw131),                                           /* CW131 : TX Gain */
/*MT6165*/                       SCTRL_RESERVED,               0                                                          );  /* reserved */
/*MT6165*/    }
/*MT6165*/ }
/*MT6165*/
#endif
