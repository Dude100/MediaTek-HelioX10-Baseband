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
 *   l1d_reg.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Definition of H/W register address used in L1D
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.46  $
 * $Modtime:   Aug 02 2005 13:45:22  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1/l1d/l1d_reg.h-arc  $
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
 * 02 14 2014 ola.lee
 * removed!
 * 	.
 *
 * 02 12 2014 ola.lee
 * removed!
 * 	.
 *
 * 01 22 2014 ola.lee
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
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
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
 * 12 05 2011 cs.wu
 * removed!
 * .
 *
 * 11 28 2011 cs.wu
 * removed!
 * .
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
 * 06 10 2011 cs.wu
 * removed!
 * .
 *
 * 05 20 2011 cs.wu
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
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
 * modify the AGPS register for MT6276_E2.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
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
 * 11 07 2010 cs.wu
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * 10 15 2010 cs.wu
 * removed!
 * .
 *
 * 10 10 2010 cs.wu
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Add  UL1D / L1D code modification for MT6276 AGPS support.
 *
 * removed!
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
 * All HW register read/write should use volatile
 *
 * removed!
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
 * Fix CLK_OUT address
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * [L1D][Modify] Check in #include  "m12171.h" for MT6253T MPLL FH Driver
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Increase TDMA_end for l1sim.
 *
 * removed!
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
 * First Check-in 2G/3G Dual Mode Sleep Mode
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Fix RTCCOUNT to APBADDR32
 *
 * removed!
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
 * Move SM registers definitions from l1dsm.h to l1_reg.h
 *
 * removed!
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
 * remove the interrupt controller related define
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Check in for the simulation environment
 *
 * removed!
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
 * Solve the TX_IQ_SWAP bug for MT6228 S02
 *
 * removed!
 * removed!
 * Add the compile option for MT6230
 *
 * removed!
 * removed!
 * Modify for the TX IQ swap of MT6229_S01
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Upgrade the MT6229 DBD algorithm
 *
 * removed!
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
 *    Rev 1.46   Aug 02 2005 13:49:00   mtk00939
 * Update TDMA register definition
 *
 *    Rev 1.45   Jul 08 2005 16:53:02   mtk00939
 * [L1D][Modify]L1D add code for MT6139C and META related code
 *
 *    Rev 1.44   May 17 2005 15:09:02   mtk00939
 * Update MT6228 register definition
 *
 *    Rev 1.43   May 17 2005 00:34:20   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.42   Jan 18 2005 00:37:58   BM
 * append new line in W05.04
 *
 *    Rev 1.41   Mar 04 2004 18:24:56   mtk00240
 * Add GPIO register address definition for mt6219
 * Resolution for 4107: [L1D] Add GPIO register address definition for mt6219
 *
 *    Rev 1.40   Oct 25 2003 15:48:20   mtk00240
 * Add GPIO related register definition
 * Resolution for 3196: [L1D][Enhance] Add code to support mt6218B
 *
 *    Rev 1.39   Oct 17 2003 17:29:40   mtk00489
 * [L1D][Enhanced]L1D split Sherif register definitions from l1d_reg.h to l1d_reg_dsp.h for customer release
 * Resolution for 3137: [L1D][Enhanced]L1D split Sherif register definitions from l1d_reg.h to l1d_reg_dsp.h for customer release
 *
 *    Rev 1.38   Oct 01 2003 15:17:32   mtk00585
 * [L1D][Modify]L1D modify code for MT6219
 * Resolution for 3037: [L1D][Modify]L1D modify code for MT6219
 *
 *    Rev 1.37   Jun 26 2003 15:22:16   mtk00240
 * L1D modify some code to support MT6218
 * Resolution for 2116: [L1D][Enhance] L1D modify some code to support MT6218
 *
 *    Rev 1.36   May 12 2003 21:36:56   mtk00489
 * [L1D][Enhanced]L1D modify L1D_RecordHwRegisters() / m12192.c(aero) / l1d_reg.h to make compiler happy.
 * Resolution for 1770: [L1D][Enhanced]L1D modify L1D_RecordHwRegisters() / m12192.c(aero) / l1d_reg.h to make compiler happy.
 *
 *    Rev 1.35   Feb 10 2003 17:13:26   mtk00489
 * L1D supports AMR and L1D_LP2 supports MT6218 cosim
 * Resolution for 639: L1D supports AMR and L1D_LP2 supports MT6218 cosim
 *
 *    Rev 1.34   13 Dec 2002 17:46:00   mtk00240
 * L1D add register defintion for MT6218
 * Resolution for 588: L1D add register defintion for MT6218
 *
 *    Rev 1.33   11 Dec 2002 11:10:08   mtk00240
 * L1D add register defintion for MT6218
 * Resolution for 588: L1D add register defintion for MT6218
 *
 *    Rev 1.32   09 Dec 2002 08:52:34   mtk00240
 * Modify the definition of APC registers for MT6218
 * Resolution for 581: L1D add code to support MT6218
 *
 *    Rev 1.31   05 Dec 2002 11:10:08   mtk00240
 * L1D modified some filed name for AMR
 * Resolution for 581: L1D add code to support MT6218
 *
 *    Rev 1.30   05 Dec 2002 10:50:28   mtk00240
 * L1D add code to support MT6218
 * Resolution for 581: L1D add code to support MT6218
 *
 *    Rev 1.29   07 Nov 2002 14:29:28   mtk00240
 * L1D set initial value of some registers to raise the performance of MT6205
 * Resolution for 553: L1D set initial value of some registers to raise the performance of MT6205
 *
 *    Rev 1.28   01 Nov 2002 11:16:58   mtk00240
 * L1D change registers definition for MT6218
 * Resolution for 545: L1D change registers definition for MT6218
 *
 *    Rev 1.27   26 Sep 2002 11:48:50   mtk00240
 * L1D fill 2 parameters on sherif for DSP patch of overcoming 200K adjacent
 * Resolution for 507: L1D fill 2 parameters on sherif for DSP patch of overcoming 200K adjacent
 *
 *    Rev 1.26   24 Aug 2002 14:10:46   mtk00240
 *  L1D add code to support AERO RF Module
 * Resolution for 464:  L1D add code to support AERO RF Module
 *
 *    Rev 1.25   24 Aug 2002 12:26:10   mtk00240
 * Change GPIO config for MT6205
 * Resolution for 460: L1D modifed GPRS related code to support MAUI
 *
 *    Rev 1.24   22 Aug 2002 11:06:24   mtk00240
 * Add 2 sherif registers:
 * DP_FB_THRE_IDLE,DP_FB_POW
 * Resolution for 456: L1D write  threshold of FCB stage1 algorithm to Sherif
 *
 *    Rev 1.23   29 Jul 2002 17:48:46   mtk00240
 * L1D remove code about initializing AFC data
 * Resolution for 442: L1D remove code about initializing AFC data
 *
 *    Rev 1.22   18 Jul 2002 22:46:20   mtk00240
 * Prevent the compile warnings in simulation environment
 * Resolution for 437: L1D modified code for MT6205
 *
 *    Rev 1.21   03 Jul 2002 21:43:46   mtk00240
 * L1D extrract RF setting code to let customer setup new RF module more easily
 * Resolution for 418: L1D extrract RF setting code to let customer setup new RF module more easily
 *
 *    Rev 1.20   06 Jun 2002 10:03:24   mtk00240
 * L1D add code to select FB detection algorithm in scan mode and normal mode
 * Resolution for 413: L1D add code to select FB detection algorithm in scan mode and normal mode
 *
 *    Rev 1.19   01 May 2002 22:45:54   mtk00240
 * Extract GSM code from L1D
 * Resolution for 384: Extract GSM code from L1D
 *
 *    Rev 1.18   18 Apr 2002 08:12:04   mtk00240
 * L1D fix the bug of filling wrong TSC address of Sherif in GPRS case
 * Resolution for 372: L1D fix the bug of filling wrong TSC address of Sherif in GPRS case
 *
 *    Rev 1.17   12 Apr 2002 21:31:46   mtk00240
 * L1D add code to fill audio filter coefficients to DSP by IDMA
 * Resolution for 360: L1D add code to fill audio filter coefficients to DSP by IDMA
 *
 *    Rev 1.16   03 Apr 2002 19:30:28   mtk00240
 * Fix some code to support Bright4 properly
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 *
 *    Rev 1.15   01 Apr 2002 12:24:12   mtk00240
 * L1D modified register's definition for DSP main v10
 * Resolution for 347: L1D modified register's definition for DSP F/W main v10
 *
 *    Rev 1.14   01 Apr 2002 08:14:00   mtk00240
 * Add MPLL and SLEEP_CON registers
 * Resolution for 345: Add some registers to hardware simulation for L1D testing
 *
 *    Rev 1.13   30 Mar 2002 13:04:10   mtk00240
 * 1) Modify L1D code to support both Bright2 & Bright4 RF board
 * 2) L1D add Audio interface to support Voice Memo & Melody
 * 3) Add L1D code to support RAM-based chip
 * Resolution for 341: Modify L1D code to support both Bright2 & Bright4 RF board
 * Resolution for 342: L1D add Audio interface to support Voice Memo & Melody
 * Resolution for 343: Add L1D code to support RAM-based chip
 *
 *    Rev 1.12   13 Mar 2002 11:15:34   mtk00240
 * Add code to set AFE register in DAI test mdoe
 * Resolution for 212: L1D supports DAI test mode
 *
 *    Rev 1.11   11 Mar 2002 13:35:40   mtk00240
 * instead TAB characters of Space characters in L1D code .
 * Resolution for 318: Shine change TAB character to Space charter
 *
 *    Rev 1.10   08 Mar 2002 16:50:38   mtk00240
 * L1D add code to fix the speech delay margin
 * Resolution for 315: L1D add code to fix the speech delay margin
 *
 *    Rev 1.9   22 Feb 2002 16:52:56   mtk00240
 * Modified some code for new Sherif register
 * Resolution for 296: Modified some code for new Sherif register
 *
 *    Rev 1.8   16 Jan 2002 22:59:54   mtk00240
 * Change Audio Front End Register's mapping
 * Resolution for 224: Change Audio Front End Register's mapping
 *
 *    Rev 1.7   08 Jan 2002 17:08:48   mtk00240
 * Chnage DP_TX_TEST_27 from 0x3BB*2 to 0x3BC*2
 * Resolution for 204: Fix the mapping of DP_TX_TEST_27 in Sherif
 *
 *    Rev 1.6   08 Jan 2002 08:19:46   mtk00240
 * Modified DP_TX_TEST_XX registers mapping
 * Resolution for 198: Change the mapping of DP_TX_TEST_XXX registers in DSP Sherif
 *
 *    Rev 1.5   04 Jan 2002 17:24:32   mtk00240
 * Merge B.L1.2001.1225 to Main V1.XX
 *
 *    Rev 1.3.1.1   04 Jan 2002 13:58:56   mtk00240
 * Change Melody registers mapping in Sherif
 *
 *    Rev 1.3.1.0   Dec 25 2001 14:32:50   mtk00210
 * Update for High resolution RSSI, multiband AFC,
 * update L1C/L1D interface for CSD
 *
 *******************************************************************************/

#ifndef _L1D_REG_H_
#define _L1D_REG_H_

#include "l1d_cid.h"

/*=======================================================================================================================*/
/* used for Simulation                                                                                                   */
/*-----------------------------------------------------------------------------------------------------------------------*/

typedef unsigned short  DPRAM_T;                                        /* Dual Port Ram is 16bit access (Thumb)         */
typedef unsigned long   REG_T;                                          /* Registers are 32bit access (SRM APB bus)      */

#define DIS_ALL_IRQ     0x0000                                          /* -----------------> flags in EVENT_ENABLE0     */
#define EN_DTIRQ        0x0001                                          /*                                               */
#define EN_CTIRQ1       0x0002                                          /*                                               */
#define EN_CTIRQ2       0x0004                                          /*                                               */
#define EN_CTIRQ3       0x0008                                          /*                                               */
#if IS_NEW_TDMA_CHIP
#define EN_BDL(n)       (1<<(6+(n)+(((n)/6)*4)))                        /* 0 <= n <=  5, 6, 7                            */
#else
#define EN_BDL(n)       (1<<(6+(n)))                                    /* 0 <= n <=  5                                  */
#endif
#define EN_APC(n)       (1<<(n))                                        /* 0 <= n <=  4 ----> flags in EVENT_ENABLE1     */
#define EN_GSM          0x0000                                          /*                                               */
#if IS_FPGA_TARGET || IS_CHIP_MT6208
#define EN_BSI(n)       (1<<(n))                                        /* 0 <= n <= 15 ----> flags in EVENT_ENABLE2     */
#define EN_BPI(n)       (1<<(n))                                        /* 0 <= n <= 15 ----> flags in EVENT_ENABLE3     */
#endif

#if IS_FPGA_TARGET || IS_CHIP_MT6208
#define EN_AFC3         0x8000                                          /*                                               */
#define EN_AFC(n)       (1<<(3+(n)))                                    /* 0 <= n <=  2                                  */
#endif

#if IS_CHIP_MT6205_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define EN_AFC3         0x8000                                          /*                                               */
#define EN_AFC(n)       (1<<(12+(n)))                                   /* 0 <= n <=  2                                  */
#endif

#if IS_FPGA_TARGET || IS_CHIP_MT6208 || IS_CHIP_MT6205
#define EN_BUL(n)       (1<<(6+(n)))                                    /* 0 <= n <=  3                                  */
#define EN_GPRS         0x0400                                          /*                                               */
#endif

#if IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_NEW_TDMA_CHIP
#define EN_BUL(n)       (1<<(8+(n)+(((n)/4)*4)))                        /* 0 <= n <=  3, 4, 5                            */
   #else
#define EN_BUL(n)       (1<<(8+(n)))                                    /* 0 <= n <=  3                                  */
   #endif
#define EN_GPRS         0x8000                                          /*                                               */
#endif

/*--------------------------------------------*/
/* define enable bit mask                     */
/*--------------------------------------------*/

#if IS_FD216_DSP_CHIP
#define DPRAM(offset)   ((DPRAMADDR)(DPRAM_CPU_base+(offset)*2))
#define DPRAM2(offset)  ((DPRAMADDR)(DPRAM2_CPU_base+(offset)*2))
#else
#define DPRAM(offset)   DPRAM_base(offset)
#endif

/*=======================================================================================================================*/

typedef volatile unsigned short* SRAMADDR;                              /* SRAM addr is 16 bits                          */
typedef volatile unsigned short  SRAMDATA;                              /* SRAM data is 16 bits                          */
typedef volatile unsigned short* APBADDR;                               /* APB addr is 32 bits                           */
typedef volatile unsigned short  APBDATA;                               /* APB data is 16 bits                           */
typedef volatile unsigned long*  APBADDR32;                             /* APB addr is 32 bits                           */
typedef volatile unsigned long   APBDATA32;                             /* APB data is 16 bits                           */
typedef volatile unsigned short* DPRAMADDR;                             /* DPRAM addr is 16 bits                         */
typedef volatile signed   short* DPRAMADDR_S;                           /* DPRAM addr is 16 bits                         */
typedef volatile unsigned short  DPRAMDATA;                             /* DPRAM data is 16 bits                         */

#if IS_NEW_TDMA_CHIP
typedef APBADDR32                APBADDX;                               /*32 bits*/
typedef APBDATA32                APBDATX;                               /*32 bits*/
typedef unsigned long            uintX;                                 /*32 bits*/
#else
typedef APBADDR                  APBADDX;                               /*16 bits*/
typedef APBDATA                  APBDATX;                               /*16 bits*/
typedef unsigned short           uintX;                                 /*16 bits*/
#endif

#if IS_BSI_REG_32_BIT_CHIP
typedef APBADDR32                APBADDS;                               /*32 bits; "S" means BSI*/
typedef APBDATA32                APBDATS;                               /*32 bits; "S" means BSI*/
typedef unsigned long            uintS;                                 /*32 bits; "S" means BSI*/
#else
typedef APBADDR                  APBADDS;                               /*16 bits; "S" means BSI*/
typedef APBDATA                  APBDATS;                               /*16 bits; "S" means BSI*/
typedef unsigned short           uintS;                                 /*16 bits; "S" means BSI*/
#endif

#if IS_BPI_REG_32_BIT_CHIP
typedef APBADDR32                APBADDP;                               /*32 bits; "P" means BPI*/
typedef APBDATA32                APBDATP;                               /*32 bits; "P" means BPI*/
typedef unsigned long            uintP;                                 /*32 bits; "P" means BPI*/
#else
typedef APBADDR                  APBADDP;                               /*16 bits; "P" means BPI*/
typedef APBDATA                  APBDATP;                               /*16 bits; "P" means BPI*/
typedef unsigned short           uintP;                                 /*16 bits; "P" means BPI*/
#endif

#if IS_BPI_DATA_32_BIT_CHIP
typedef APBADDR32                APBADDRBPI;                            /*32 bits*/
typedef long                     intBPI;                                /*32 bits*/
typedef signed long              sintBPI;                               /*32 bits*/
#else
typedef APBADDR                  APBADDRBPI;                            /*16 bits*/
typedef short                    intBPI;                                /*16 bits*/
typedef signed short             sintBPI;                               /*16 bits*/
#endif

#if IS_BSI_CON_32_BIT_CHIP
typedef APBADDR32                APBADDRBSI;                            /*32 bits*/
typedef long                     intBSI;                                /*32 bits*/
typedef signed long              sintBSI;                               /*32 bits*/
typedef unsigned long            uintBSI;                               /*32 bits*/
#else
typedef APBADDR                  APBADDRBSI;                            /*16 bits*/
typedef short                    intBSI;                                /*16 bits*/
typedef signed short             sintBSI;                               /*16 bits*/
typedef unsigned short           uintBSI;                               /*16 bits*/
#endif

/*-----------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------*/
/* Base address of MCU Peripherals */
/*---------------------------------*/
/* old base address maintained by L1 */
/*
#if IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
#define DPRAM_CPU_base           0xA0000000L                            // Host DSP Sherif Registers
#define DPRAM_CPU_end            0xA00007FEL
#define DPRAM2_CPU_base          0xA1000000L                            // Slave DSP Sherif Registers
#define DPRAM2_CPU_end           0xA10007FEL
#define CONFIG_base              0x80010000L                            // Config registers  (Clk, Power Down, Ver)
#define CONFIG_end               0x8001FFFFL
#define GPIO_base                0x80020000L                            // General Purpose Inputs/Outputs
#define GPIO_end                 0x800201FFL
#define RGU_base                 0x80030000L                            // Reset Generation Unit
#define RGU_end                  0x800300FFL
#define EMI_base                 0x81000000L                            // External Memory Interface
#define EMI_end                  0x8100FFFFL
#define CIRQ_base                0x81010000L                            // Interrupt Controller
#define CIRQ_end                 0x8101FFFFL
#define DMA_base                 0x81020000L                            // DMA Controller
#define DMA_end                  0x8102FFFFL
#define RTC_base                 0x810C0000L                            // Real Time Clock
#define RTC_end                  0x810C00FFL
#define TDMA_base                0x82000000L                            // TDMA Timer
#define TDMA_end                 0x82000300L
#define SM_base                  0x82000200L                            // Sleep Mode
#define SM_end                   0x820002FFL
#define BSI_base                 0x82010000L                            // Base-band Serial Interface
#define BSI_end                  0x820101FFL
#define BPI_base                 0x82020000L                            // Base-band Parallel Interface
#define BPI_end                  0x8202006FL
#define AFC_base                 0x82030000L                            // Automatic Frequency Control Unit
#define AFC_end                  0x8203001FL
#define APC_base                 0x82040000L                            // Automatic Power Control Unit
#define APC_end                  0x820401CFL
#define AUXADC_base              0x82050000L                            // Auxiliary ADC Unit
#define AUXADC_end               0x820500FFL
#define DIVIDER_base             0x82060000L                            // Divider/Modulus Coprocessor
#define DIVIDER_end              0x820600FFL
#define FCS_base                 0x82070000L                            // Frame Check Sequence
#define FCS_end                  0x820700FFL
#define GCU_base                 0x82080000L                            // GPRS Cipher Unit Unit
#define GCU_end                  0x820800FFL
#define CSD_ACC_base             0x82090000L                            // CSD Format Conversion Coprocessor
#define CSD_ACC_end              0x82090FFFL
#define SHARE_base               0x820A0000L                            // MCU-Host  DSP Shared Register
#define SHARE_end                0x820A00FFL
#define SHARE2_base              0x820C0000L                            // MCU-Slave DSP Shared Register
#define SHARE2_end               0x820C00FFL
#define PATCH_base               0x820E0000L                            // DSP Patch Unit
#define PATCH_end                0x820E01FFL
#define AFE_base                 0x820F0000L                            // Audio Front End
#define AFE_end                  0x820E00FFL
#define BFE_base                 0x82100000L                            // Base-band Front End
#define BFE_end                  0x821000FFL
#define PLL_base                 0x83000000L                            // PLL configuration
#define PLL_end                  0x83000FFFL
#define MIXED_base               0x83010000L                            // Analog Chip Interface Controller
#define MIXED_end                0x83010FFFL
#else
#define DPRAM_CPU_base           0x50000000L                            // DSP Sherif Registers
#define DPRAM_CPU_end            0x500007FEL
#define CONFIG_base              0x80000000L                            // Config registers  (Clk, Power Down, Ver)
#define CONFIG_end               0x8000FFFFL
#define EMI_base                 0x80010000L                            // External Memory Interface
#define EMI_end                  0x8001FFFFL
#define CIRQ_base                0x80020000L                            // Interrupt Controller
#define CIRQ_end                 0x8002FFFFL
#define DMA_base                 0x80030000L                            // DMA Controller
#define DMA_end                  0x8003FFFFL
#define RGU_base                 0x80040000L                            // Reset Generation Unit
#define RGU_end                  0x800400FFL
#define GCU_base                 0x80060000L                            // GPRS Cipher Unit Unit
#define GCU_end                  0x800600FFL
#define GPIO_base                0x80120000L                            // General Purpose Inputs/Outputs
#define GPIO_end                 0x801201FFL
#define TDMA_base                0x80200000L                            // TDMA Timer
#define TDMA_end                 0x80200300L
#define SM_base                  0x80200200L                            // Sleep Mode
#define SM_end                   0x802002FFL
   #if IS_CHIP_MT6229_FPGA3 || IS_CHIP_MT6229_FPGA2 || IS_CHIP_MT6229_FPGA1
#define BSI_base                 0x80210000L                            // Base-band Serial Interface
#define BSI_end                  0x802101FFL
#define BPI_base                 0x80220000L                            // Base-band Parallel Interface
#define BPI_end                  0x802200B8L
#define AFC_base                 0x80230000L                            // Automatic Frequency Control Unit
#define AFC_end                  0x8023001FL
#define APC_base                 0x80240000L                            // Automatic Power Control Unit
#define APC_end                  0x802401CFL
#define FCS_base                 0x80250000L                            // Frame Check Sequence
#define FCS_end                  0x802500FFL
#define DIVIDER_base             0x80260000L                            // Divider/Modulus Coprocessor
#define DIVIDER_end              0x802600FFL
#define CSD_ACC_base             0x80270000L                            // CSD Format Conversion Coprocessor
#define CSD_ACC_end              0x80270FFFL
#define SHARE_base               0x80300000L                            // MCU-DSP Shared Register
#define SHARE_end                0x803000FFL
#define PATCH_base               0x80310000L                            // DSP Patch Unit
#define PATCH_end                0x803101FFL
#define AFE_base                 0x80280000L                            // Audio Front End
#define AFE_end                  0x802800FFL
#define BFE_base                 0x80290000L                            // Base-band Front End
#define BFE_end                  0x802900FFL
#define MIXED_base               0x802A0000L                            // Analog Chip Interface Controller
#define MIXED_end                0x802A0FFFL
   #else
#define RTC_base                 0x80210000L                            // Real Time Clock
#define RTC_end                  0x802100FFL
#define BSI_base                 0x80220000L                            // Base-band Serial Interface
#define BSI_end                  0x802201FFL
#define BPI_base                 0x80230000L                            // Base-band Parallel Interface
#define BPI_end                  0x802300C0L
#define AFC_base                 0x80240000L                            // Automatic Frequency Control Unit
#define AFC_end                  0x8024001FL
#define APC_base                 0x80250000L                            // Automatic Power Control Unit
#define APC_end                  0x802501CFL
#define FCS_base                 0x80260000L                            // Frame Check Sequence
#define FCS_end                  0x802600FFL
#define AUXADC_base              0x80270000L                            // Auxiliary ADC Unit
#define AUXADC_end               0x802700FFL
#define DIVIDER_base             0x80280000L                            // Divider/Modulus Coprocessor
#define DIVIDER_end              0x802800FFL
#define CSD_ACC_base             0x80290000L                            // CSD Format Conversion Coprocessor
#define CSD_ACC_end              0x80290FFFL
#define SHARE_base               0x80300000L                            // MCU-DSP Shared Register
#define SHARE_end                0x803000FFL
#define PATCH_base               0x80310000L                            // DSP Patch Unit
#define PATCH_end                0x803101FFL
#define AFE_base                 0x80400000L                            // Audio Front End
#define AFE_end                  0x804000FFL
#define BFE_base                 0x80410000L                            // Base-band Front End
#define BFE_end                  0x804100FFL
#define MIXED_base               0x80500000L                            // Analog Chip Interface Controller
#define MIXED_end                0x80500FFFL
   #endif

   #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define DPRAM2_CPU_base          0x58000000L
#define DPRAM2_CPU_end           0x580007FEL
#define SHARE2_base              0x80320000L                            // MCU-DSP Shared Register
#define SHARE2_end               0x803200FFL
#define PATCH2_base              0x80330000L                            // MCU-DSP Shared Register
#define PATCH2_end               0x803301FFL
   #endif
#endif

#if IS_CHIP_MT6223 //MT6238 does not support SWDBG
#define SWDBG_base               0x80090000L                            // Software Debug Controller
#elif IS_CHIP_MT6228 || IS_CHIP_MT6229 || IS_CHIP_MT6225_AND_LATTER_VERSION || IS_CHIP_MT6268T
#define SWDBG_base               0x80070000L                            // Software Debug Controller
#endif
*/

/*---------------------------------*/
/* Base address of MCU Peripherals */
/*---------------------------------*/
/*--------------------------------------------------------------------------*/
/* L1 only maintain chips' base address which cannot be found in reg_base.h */
/*--------------------------------------------------------------------------*/
#if IS_FPGA_TARGET || IS_CHIP_MT6205A || IS_CHIP_MT6218
#define DPRAM_CPU_base           0x50000000L                            /* DSP Sherif Registers                          */
#define IDMA_base                0x60000000L                            /* IDMA                                          */
#define CONFIG_base              0x80000000L                            /* Config registers  (Clk, Power Down, Ver)      */
#define EMI_base                 0x80010000L                            /* External Memory Interface                     */
#define CIRQ_base                0x80020000L                            /* Interrupt Controller                          */
#define DMA_base                 0x80030000L                            /* DMA Controller                                */
#define RGU_base                 0x80040000L                            /* Reset Generation Unit                         */
#define GCU_base                 0x80060000L                            /* GPRS Cipher Unit                              */
#define GPIO_base                0x80120000L                            /* General Purpose Inputs/Outputs                */
#define TDMA_base                0x80200000L                            /* TDMA Timer                                    */
#define RTC_base                 0x80210000L                            /* Real Time Clock                               */
#define BSI_base                 0x80220000L                            /* Base-band Serial Interface                    */
#define BPI_base                 0x80230000L                            /* Base-band Parallel Interface                  */
#define AFC_base                 0x80240000L                            /* Automatic Frequency Control Unit              */
#define APC_base                 0x80250000L                            /* Automatic Power Control Unit                  */
#define FCS_base                 0x80260000L                            /* Frame Check Sequence                          */
#define AUXADC_base              0x80270000L                            /* Auxiliary ADC Unit                            */
#define DIVIDER_base             0x80280000L                            /* Divider/Modulus Coprocessor                   */
#define CSD_ACC_base             0x80290000L                            /* CSD Format Conversion Coprocessor             */
#define SHARE_base               0x80300000L                            /* MCU-DSP Shared Register                       */
#define PATCH_base               0x80310000L                            /* DSP Patch Unit                                */
#define AFE_base                 0x80400000L                            /* Audio Front End                               */
#define BFE_base                 0x80410000L                            /* Base-band Front End                           */
#define MIXED_base               0x80500000L                            /* Analog Chip Interface Controller              */
/* -------------------------------------------------------*/
/* other chips's base address is defined in reg_base.h    */
/* -------------------------------------------------------*/
#else
#include "reg_base.h"
#endif

/* -------------------------------------------------------*/
/* Replace MT6229 FPGA specific base address              */
/* -------------------------------------------------------*/
#if IS_CHIP_MT6229_FPGA1 || IS_CHIP_MT6229_FPGA2 || IS_CHIP_MT6229_FPGA3
#undef  RTC_base
#undef  BSI_base
#define BSI_base                 0x80210000L                            /* Base-band Serial Interface                    */
#undef  BPI_base
#define BPI_base                 0x80220000L                            /* Base-band Parallel Interface                  */
#undef  AFC_base
#define AFC_base                 0x80230000L                            /* Automatic Frequency Control Unit              */
#undef  APC_base
#define APC_base                 0x80240000L                            /* Automatic Power Control Unit                  */
#undef  FCS_base
#define FCS_base                 0x80250000L                            /* Frame Check Sequence                          */
#undef  AUXADC_base
#undef  DIVIDER_base
#define DIVIDER_base             0x80260000L                            /* Divider/Modulus Coprocessor                   */
#undef  CSD_ACC_base
#define CSD_ACC_base             0x80270000L                            /* CSD Format Conversion Coprocessor             */
#undef  AFE_base
#define AFE_base                 0x80280000L                            /* Audio Front End                               */
#undef  BFE_base
#define BFE_base                 0x80290000L                            /* Base-band Front End                           */
#undef  MIXED_base
#define MIXED_base               0x802A0000L                            /* Analog Chip Interface Controller              */
#endif

/* -------------------------------------------------------*/
/* Alias MT6268A base address                             */
/* -------------------------------------------------------*/
#if IS_EDGE_SAIC_CHIP_MT6268_AND_LATTER_VERSION && !IS_CHIP_MT6253 && IS_FD216_DSP_CHIP && !IS_CACHE_DSP_SUPPORT && !IS_DSP_ARCHITECTURE_V4_SUPPORT
#define SHARE_base               SHARE1_base
#define SHAREG_base              SHAREG1_base
#endif

/* -------------------------------------------------------*/
/* MT6268T Dual MAC DSP FPGA                              */
/* -------------------------------------------------------*/
#if IS_CHIP_MT6268T_DMAC
#undef  TDMA_base
#define TDMA_base                FPGA_TDMA_base
#endif

#if IS_CHIP_MT6268T_DMAC || IS_CHIP_MT6270A
#undef  MIXED_base
#define MIXED_base               ACIF_base
#define SHARE_T123_base          SHARE_T1T2T3_base
#define BFE_TXBUF_base           TX_LOCAL_base
#endif

#if IS_CHIP_TK6280               /* This is false address for MT6280 FPGA */
#define MDIF_base                (0x82000000)
#define BFMDIF_base              MDIF_base
#endif

/* -----------------------------------------------------------------*/
/* SM_base is the subset of TDMA_base, we define it for convenience */
/* -----------------------------------------------------------------*/
#if IS_CENTRALIZED_SMM_CHIP
   #if IS_CHIP_MT6276 || IS_CHIP_MT6573 || IS_CHIP_MT6575 || IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572
#define SM_base                  (TDMA_base      +0x0500)               /* 2G Sleep Controller                           */
   #else
/* For IS_CHIP_MT6290, IS_CHIP_MT6595 and later, SM_base has been declared in l1sm.h */
   #endif
#else
#define SM_base                  (TDMA_base      +0x0200)               /* 2G Sleep Controller                           */
#endif

#if IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1
#undef  BSI_base
#define BSI_base                 BSI2G_base

#undef  BPI_base
#define BPI_base                 BPI2G_base

#undef  AFC_base
#define AFC_base                 AFC2G_base
   #if IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1
#define AFC3G_base               BASE_MADDR_AFC
   #else
#define AFC3G_base               (BASE_ADDR_AFC|BASE_MEM_TYPE_STRONGLY_ORDER)
   #endif
#endif

#if IS_CHIP_MT6752_MD2
#define BSISPI_base              (BSI_base + 0x8000)
#endif

/*=======================================================================================================================*/

//Host DSP
#if IS_DUAL_MAC_DSP_CHIP
#define IDMA_LONG                DPRAM2_CPU_base
#define IDMA_SHORT               DPRAM2_CPU_base
#define IDMA_CM0                 DPRAM2_CPU_base
#define IDMA_PM0                 DPRAM2_CPU_base
#define IDMA_DM0                 DPRAM2_CPU_base
#else
   #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define IDMA_LONG                (IDMA_base +0x310000)
   #else
#define IDMA_LONG                (IDMA_base +0x300000)
   #endif
#define IDMA_SHORT               (IDMA_base +0x310000)
#define IDMA_CM0                 (IDMA_base +0x000000)
#define IDMA_PM0                 (IDMA_base +0x100000)
#define IDMA_DM0                 (IDMA_base +0x200000)
#endif

#if IS_DUAL_MAC_DSP_CHIP
#define TXBUFF_SLOT_OFFSET       (20)  // 156*(4 bit)/8=78 byte, 20*4 byte
#define TXBUFF_SIZE              (128) // 80*6=480,128*4=512 byte
#elif IS_DSP_ARCHITECTURE_V4_SUPPORT
#define DSP_DM_TXBUFF_SIZE       (148*4)
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define DSP_DM_TXBUFF_SIZE       (170+260*2)
#else
#define DSP_DM_TXBUFF_SIZE       (1023) //(148*4)
#endif
#define IDMA_LONG_ADDR           ((APBADDR32)IDMA_LONG)
#define IDMA_SHORT_ADDR          ((DPRAMADDR)IDMA_SHORT)
#define DSP_CM_ADDR(page,addr)   ((APBADDR32)(IDMA_CM0+((page)<<16)+((addr)<<2)))
#define DSP_PM_ADDR(page,addr)   ((DPRAMADDR)(IDMA_PM0+((page)<<16)+((addr)<<1)))
#define DSP_DM_ADDR(page,addr)   ((DPRAMADDR)(IDMA_DM0+((page)<<16)+((addr)<<1)))

#if IS_CACHE_DSP_SUPPORT || IS_DSP_ARCHITECTURE_V4_SUPPORT
#define IDMA2_LONG                IDMA_LONG
#define IDMA2_SHORT               IDMA_SHORT
#define IDMA2_CM0                 IDMA_CM0
#define IDMA2_PM0                 IDMA_PM0
#define IDMA2_DM0                 IDMA_DM0
#define IDMA2_LONG_ADDR           IDMA_LONG_ADDR
#define IDMA2_SHORT_ADDR          IDMA_SHORT_ADDR
#define DSP2_CM_ADDR(page,addr)   DSP_CM_ADDR(page,addr)
#define DSP2_PM_ADDR(page,addr)   DSP_PM_ADDR(page,addr)
#define DSP2_DM_ADDR(page,addr)   DSP_DM_ADDR(page,addr)
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
//Slave DSP
   #if IS_DUAL_MAC_DSP_CHIP
#define IDMA2_LONG               DPRAM2_CPU_base
#define IDMA2_SHORT              DPRAM2_CPU_base
#define IDMA2_CM0                DPRAM2_CPU_base
#define IDMA2_PM0                DPRAM2_CPU_base
#define IDMA2_DM0                DPRAM2_CPU_base
   #else
#define IDMA2_LONG               (IDMA2_base+0x310000)
#define IDMA2_SHORT              (IDMA2_base+0x310000)
#define IDMA2_CM0                (IDMA2_base+0x000000)
#define IDMA2_PM0                (IDMA2_base+0x100000)
#define IDMA2_DM0                (IDMA2_base+0x200000)
   #endif

#define IDMA2_LONG_ADDR          ((APBADDR32)IDMA2_LONG)
#define IDMA2_SHORT_ADDR         ((DPRAMADDR)IDMA2_SHORT)
#define DSP2_CM_ADDR(page,addr)  ((APBADDR32)(IDMA2_CM0+((page)<<16)+((addr)<<2)))
#define DSP2_PM_ADDR(page,addr)  ((DPRAMADDR)(IDMA2_PM0+((page)<<16)+((addr)<<1)))
#define DSP2_DM_ADDR(page,addr)  ((DPRAMADDR)(IDMA2_DM0+((page)<<16)+((addr)<<1)))

#endif

/*=======================================================================================================================*/

#define LO_BYTE( data )          ((unsigned char)((data)&0x00FF))
#define HI_BYTE( data )          ((unsigned char)(((data)>>8)&0x00FF))
#define LO_WORD( data )          ((unsigned short)((data)&0x0000FFFFL))
#define HI_WORD( data )          ((unsigned short)(((data)>>16)&0x0000FFFFL))
#if IS_BSI_CON_32_BIT_CHIP
#define TO_WORD( data )          ((unsigned long)(data))
#else
#define TO_WORD( data )          ((unsigned short)(data))
#endif

/*=======================================================================================================================*/

#if IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define SCTRL_WORD( dev_sel, bit_count )  ((unsigned long)(((dev_sel)<<15)|((bit_count-1)<<8)       |((BSI_PORT_SELECT&0x3)<<16)))
#define SCTRL_IMOD( dev_sel, bit_count )  ((unsigned long)(((dev_sel)<<15)|((bit_count-1)<<8)|(0xFF)|((BSI_PORT_SELECT&0x3)<<16)))
#elif IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572
#define SCTRL_WORD( dev_sel, bit_count )  ((unsigned short)(((dev_sel)<<15)|((bit_count-1)<<8)       |((BSI_PORT_SELECT&0x3)<<6)))
#define SCTRL_IMOD( dev_sel, bit_count )  ((unsigned short)(((dev_sel)<<15)|((bit_count-1)<<8)|(0x3F)|((BSI_PORT_SELECT&0x3)<<6)))
#elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H
#define SCTRL_WORD( dev_sel, bit_count )  ((unsigned short)(((dev_sel)<<15)|((bit_count-1)<<8)       |((BSI_PORT_SELECT&0x1)<<7)))
#define SCTRL_IMOD( dev_sel, bit_count )  ((unsigned short)(((dev_sel)<<15)|((bit_count-1)<<8)|(0x7F)|((BSI_PORT_SELECT&0x1)<<7)))
#elif  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define SCTRL_WORD( dev_sel, bit_count )  ((unsigned short)(((dev_sel)<<15)|((bit_count-1)<<8)))
#define SCTRL_IMOD( dev_sel, bit_count )  ((unsigned short)(((dev_sel)<<15)|((bit_count-1)<<8)|(0x7F)))
#else
#define SCTRL_WORD( dev_sel, bit_count )  ((unsigned short)(((dev_sel)<<15)|((bit_count-1)<<8)))
#define SCTRL_IMOD( dev_sel, bit_count )  ((unsigned short)(((dev_sel)<<15)|((bit_count-1)<<8)|(0x1F)))
#endif

#if IS_MIPI_SUPPORT
   #if IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1
#define MIPI_SCTRL_WORD( dev_sel, bit_count, port, event_id )  ((unsigned long)(((dev_sel)<<15)|((bit_count-1)<<8)|(event_id&0xFF)|((port&0x3)<<16)))
#define MIPI_SCTRL_IMOD( dev_sel, bit_count, port           )  ((unsigned long)(((dev_sel)<<15)|((bit_count-1)<<8)|(         0xFF)|((port&0x3)<<16)))
   #endif
#endif
/*=======================================================================================================================*/

#if IS_CHIP_MT6268T
#define HW_WRITE_TDMA_REGBIAS( tq )       {  HW_WRITE( TDMA_REGBIAS, tq );        \
                                             HW_WRITE( FPGA_TDMA_REGBIAS, tq );   \
                                          }
#else
#define HW_WRITE_TDMA_REGBIAS( tq )       {  HW_WRITE( TDMA_REGBIAS, tq );  }
#endif

/*=======================================================================================================================*/

#if IS_FPGA_TARGET || IS_CHIP_MT6208
/* ------------------------------------------------------------------------- */
/* FPGA,MT6208                                                               */
/* ------------------------------------------------------------------------- */
#define  HW_WRITE_BSI_DATA( addr, data )                  \
{  HW_WRITE( (APBADDR)((long)(addr)+0), LO_WORD(data) );  \
   HW_WRITE( (APBADDR)((long)(addr)+4), HI_WORD(data) );  \
}

#define  HW_WRITE_BSI_DATA_1( data_idx, ctrl,data )             \
{  long     _d32;                                               \
   APBADDR  _reg = BSI_Dn_CON( data_idx );                      \
   _d32 = ctrl;   HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;  \
   _d32 = data;   HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;  \
                  HW_WRITE( _reg, HI_WORD(_d32) );              \
}

#define  HW_WRITE_BSI_DATA_2( data_idx, ctrl1,data1, ctrl2,data2 )  \
{  long     _d32;                                                   \
   APBADDR  _reg = BSI_Dn_CON( data_idx );                          \
   _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;      \
   _d32 = data1;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;      \
                  HW_WRITE( _reg, HI_WORD(_d32) );  _reg += 2;      \
   _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;      \
   _d32 = data2;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;      \
                  HW_WRITE( _reg, HI_WORD(_d32) );                  \
}

#define  HW_WRITE_BSI_DATA_3( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3 )  \
{  long     _d32;                                                                \
   APBADDR  _reg = BSI_Dn_CON( data_idx );                                       \
   _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;                   \
   _d32 = data1;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;                   \
                  HW_WRITE( _reg, HI_WORD(_d32) );  _reg += 2;                   \
   _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;                   \
   _d32 = data2;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;                   \
                  HW_WRITE( _reg, HI_WORD(_d32) );  _reg += 2;                   \
   _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;                   \
   _d32 = data3;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;                   \
                  HW_WRITE( _reg, HI_WORD(_d32) );                               \
}

#define  HW_WRITE_BSI_DATA_4( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3, ctrl4,data4 )  \
{  long     _d32;                                                                             \
   APBADDR  _reg = BSI_Dn_CON( data_idx );                                                    \
   _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;                                \
   _d32 = data1;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;                                \
                  HW_WRITE( _reg, HI_WORD(_d32) );  _reg += 2;                                \
   _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;                                \
   _d32 = data2;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;                                \
                  HW_WRITE( _reg, HI_WORD(_d32) );  _reg += 2;                                \
   _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;                                \
   _d32 = data3;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;                                \
                  HW_WRITE( _reg, HI_WORD(_d32) );  _reg += 2;                                \
   _d32 = ctrl4;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;                                \
   _d32 = data4;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;                                \
                  HW_WRITE( _reg, HI_WORD(_d32) );                                            \
}
#endif

#if IS_CHIP_MT6205_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* ------------------------------------------------------------------------- */
/* MT6205~                                                                   */
/* ------------------------------------------------------------------------- */
   #if IS_BSI_CON_32_BIT_CHIP
#define BSI_REG_IDX 1
   #else
#define BSI_REG_IDX 2
   #endif

   #if IS_IMM_BSI_SEND_DUMMY_READ_ON
#define  HW_DUMMY_READ_BSI_DATA( addr )                            \
{  unsigned long  dummy_read;                                      \
   dummy_read = HW_READ( (APBADDR32)(addr) );                      \
   (void)dummy_read;                                               \
}
   #else
#define  HW_DUMMY_READ_BSI_DATA( addr )
   #endif

#define  HW_WRITE_BSI_DATA( addr, data )   \
{  HW_WRITE( (APBADDR32)(addr), (data) );  \
}

#define  HW_WRITE_BSI_DATA_1( data_idx, ctrl,data )                          \
{  long       _d32;                                                          \
   APBADDRBSI _reg = BSI_Dn_CON( data_idx );                                 \
   _d32 = ctrl;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;  \
   _d32 = data;  HW_WRITE( (APBADDR32)(_reg), _d32 );                        \
}

#define  HW_WRITE_BSI_DATA_2( data_idx, ctrl1,data1, ctrl2,data2 )            \
{  long       _d32, _d_idx=data_idx;                                          \
   APBADDRBSI _reg = BSI_Dn_CON( data_idx );                                  \
   _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;  \
   _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;             \
   _reg = BSI_Dn_CON( _d_idx );                                               \
   _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;  \
   _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );                        \
}

#define  HW_WRITE_BSI_DATA_3( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3 )  \
{  long       _d32, _d_idx=data_idx;                                             \
   APBADDRBSI _reg = BSI_Dn_CON( data_idx );                                     \
   _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;     \
   _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                \
   _reg = BSI_Dn_CON( _d_idx );                                                  \
   _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;     \
   _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                \
   _reg = BSI_Dn_CON( _d_idx );                                                  \
   _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;     \
   _d32 = data3;  HW_WRITE( (APBADDR32)(_reg), _d32 );                           \
}

#define  HW_WRITE_BSI_DATA_4( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3, ctrl4,data4 )  \
{  long       _d32, _d_idx=data_idx;                                                          \
   APBADDRBSI _reg = BSI_Dn_CON( data_idx );                                                  \
   _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                  \
   _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                             \
   _reg = BSI_Dn_CON( _d_idx );                                                               \
   _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                  \
   _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                             \
   _reg = BSI_Dn_CON( _d_idx );                                                               \
   _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                  \
   _d32 = data3;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                             \
   _reg = BSI_Dn_CON( _d_idx );                                                               \
   _d32 = ctrl4;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                  \
   _d32 = data4;  HW_WRITE( (APBADDR32)(_reg), _d32 );                                        \
}

#define  HW_WRITE_BSI_DATA_5( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3, ctrl4,data4, ctrl5,data5 )  \
{  long       _d32, _d_idx=data_idx;                                                                       \
   APBADDRBSI _reg = BSI_Dn_CON( data_idx );                                                               \
   _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                               \
   _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                          \
   _reg = BSI_Dn_CON( _d_idx );                                                                            \
   _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                               \
   _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                          \
   _reg = BSI_Dn_CON( _d_idx );                                                                            \
   _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                               \
   _d32 = data3;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                          \
   _reg = BSI_Dn_CON( _d_idx );                                                                            \
   _d32 = ctrl4;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                               \
   _d32 = data4;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                          \
   _reg = BSI_Dn_CON( _d_idx );                                                                            \
   _d32 = ctrl5;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                               \
   _d32 = data5;  HW_WRITE( (APBADDR32)(_reg), _d32 );                                                     \
}

#define  HW_WRITE_BSI_DATA_6( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3, ctrl4,data4, ctrl5,data5, ctrl6,data6 )  \
{  long       _d32, _d_idx=data_idx;                                                                                    \
   APBADDRBSI _reg = BSI_Dn_CON( data_idx );                                                                            \
   _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                            \
   _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                       \
   _reg = BSI_Dn_CON( _d_idx );                                                                                         \
   _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                            \
   _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                       \
   _reg = BSI_Dn_CON( _d_idx );                                                                                         \
   _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                            \
   _d32 = data3;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                       \
   _reg = BSI_Dn_CON( _d_idx );                                                                                         \
   _d32 = ctrl4;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                            \
   _d32 = data4;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                       \
   _reg = BSI_Dn_CON( _d_idx );                                                                                         \
   _d32 = ctrl5;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                            \
   _d32 = data5;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                       \
   _reg = BSI_Dn_CON( _d_idx );                                                                                         \
   _d32 = ctrl6;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                            \
   _d32 = data6;  HW_WRITE( (APBADDR32)(_reg), _d32 );                                                                  \
}

#define  HW_WRITE_BSI_DATA_7( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3, ctrl4,data4, ctrl5,data5, ctrl6,data6, ctrl7,data7 )  \
{  long       _d32, _d_idx=data_idx;                                                                                                 \
   APBADDRBSI _reg = BSI_Dn_CON( data_idx );                                                                                         \
   _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                         \
   _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                    \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                      \
   _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                         \
   _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                    \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                      \
   _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                         \
   _d32 = data3;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                    \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                      \
   _d32 = ctrl4;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                         \
   _d32 = data4;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                    \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                      \
   _d32 = ctrl5;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                         \
   _d32 = data5;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                    \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                      \
   _d32 = ctrl6;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                         \
   _d32 = data6;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                    \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                      \
   _d32 = ctrl7;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                         \
   _d32 = data7;  HW_WRITE( (APBADDR32)(_reg), _d32 );                                                                               \
}

#define  HW_WRITE_BSI_DATA_8( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3, ctrl4,data4, ctrl5,data5, ctrl6,data6, ctrl7,data7 , ctrl8,data8 )  \
{  long       _d32, _d_idx=data_idx;                                                                                                               \
   APBADDRBSI _reg = BSI_Dn_CON( data_idx );                                                                                                       \
   _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                       \
   _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                  \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                    \
   _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                       \
   _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                  \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                    \
   _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                       \
   _d32 = data3;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                  \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                    \
   _d32 = ctrl4;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                       \
   _d32 = data4;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                  \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                    \
   _d32 = ctrl5;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                       \
   _d32 = data5;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                  \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                    \
   _d32 = ctrl6;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                       \
   _d32 = data6;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                  \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                    \
   _d32 = ctrl7;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                       \
   _d32 = data7;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                  \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                    \
   _d32 = ctrl8;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                       \
   _d32 = data8;  HW_WRITE( (APBADDR32)(_reg), _d32 );                                                                                             \
}

#define  HW_WRITE_BSI_DATA_9( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3, ctrl4,data4, ctrl5,data5, ctrl6,data6, ctrl7,data7 , ctrl8,data8 , ctrl9,data9 )  \
{  long       _d32, _d_idx=data_idx;                                                                                                                             \
   APBADDRBSI _reg = BSI_Dn_CON( data_idx );                                                                                                                     \
   _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                     \
   _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                  \
   _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                     \
   _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                  \
   _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                     \
   _d32 = data3;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                  \
   _d32 = ctrl4;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                     \
   _d32 = data4;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                  \
   _d32 = ctrl5;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                     \
   _d32 = data5;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                  \
   _d32 = ctrl6;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                     \
   _d32 = data6;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                  \
   _d32 = ctrl7;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                     \
   _d32 = data7;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                  \
   _d32 = ctrl8;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                     \
   _d32 = data8;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                  \
   _d32 = ctrl9;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                     \
   _d32 = data9;  HW_WRITE( (APBADDR32)(_reg), _d32 );                                                                                                           \
}

#define  HW_WRITE_BSI_DATA_10( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3, ctrl4,data4, ctrl5,data5, ctrl6,data6, ctrl7,data7 , ctrl8,data8 , ctrl9,data9 , ctrl10,data10 )  \
{  long       _d32, _d_idx=data_idx;                                                                                                                                              \
   APBADDRBSI _reg = BSI_Dn_CON( data_idx );                                                                                                                                      \
   _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                      \
   _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                   \
   _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                      \
   _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                   \
   _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                      \
   _d32 = data3;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                   \
   _d32 = ctrl4;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                      \
   _d32 = data4;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                   \
   _d32 = ctrl5;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                      \
   _d32 = data5;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                   \
   _d32 = ctrl6;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                      \
   _d32 = data6;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                   \
   _d32 = ctrl7;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                      \
   _d32 = data7;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                   \
   _d32 = ctrl8;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                      \
   _d32 = data8;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                   \
   _d32 = ctrl9;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                      \
   _d32 = data9;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                   \
   _d32 = ctrl10; HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                      \
   _d32 = data10; HW_WRITE( (APBADDR32)(_reg), _d32 );                                                                                                                            \
}

#define  HW_WRITE_BSI_DATA_11( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3, ctrl4,data4, ctrl5,data5, ctrl6,data6, ctrl7,data7 , ctrl8,data8 , ctrl9,data9 , ctrl10,data10 , ctrl11,data11 )  \
{  long       _d32, _d_idx=data_idx;                                                                                                                                                              \
   APBADDRBSI _reg = BSI_Dn_CON( data_idx );                                                                                                                                                      \
   _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                      \
   _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                   \
   _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                      \
   _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                   \
   _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                      \
   _d32 = data3;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                   \
   _d32 = ctrl4;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                      \
   _d32 = data4;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                   \
   _d32 = ctrl5;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                      \
   _d32 = data5;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                   \
   _d32 = ctrl6;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                      \
   _d32 = data6;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                   \
   _d32 = ctrl7;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                      \
   _d32 = data7;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                   \
   _d32 = ctrl8;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                      \
   _d32 = data8;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                   \
   _d32 = ctrl9;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                      \
   _d32 = data9;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                   \
   _d32 = ctrl10; HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                      \
   _d32 = data10; HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                   \
   _d32 = ctrl11; HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                      \
   _d32 = data11; HW_WRITE( (APBADDR32)(_reg), _d32 );                                                                                                                                            \
}

#define  HW_WRITE_BSI_DATA_12( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3, ctrl4,data4, ctrl5,data5, ctrl6,data6, ctrl7,data7 , ctrl8,data8 , ctrl9,data9 , ctrl10,data10 , ctrl11,data11 , ctrl12,data12 )  \
{  long       _d32, _d_idx=data_idx;                                                                                                                                                                              \
   APBADDRBSI _reg = BSI_Dn_CON( data_idx );                                                                                                                                                                      \
   _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                      \
   _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                   \
   _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                      \
   _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                   \
   _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                      \
   _d32 = data3;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                   \
   _d32 = ctrl4;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                      \
   _d32 = data4;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                   \
   _d32 = ctrl5;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                      \
   _d32 = data5;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                   \
   _d32 = ctrl6;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                      \
   _d32 = data6;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                   \
   _d32 = ctrl7;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                      \
   _d32 = data7;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                   \
   _d32 = ctrl8;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                      \
   _d32 = data8;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                   \
   _d32 = ctrl9;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                      \
   _d32 = data9;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                   \
   _d32 = ctrl10; HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                      \
   _d32 = data10; HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                   \
   _d32 = ctrl11; HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                      \
   _d32 = data11; HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                   \
   _d32 = ctrl12; HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                      \
   _d32 = data12; HW_WRITE( (APBADDR32)(_reg), _d32 );                                                                                                                                                            \
}

#define  HW_WRITE_BSI_DATA_13( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3, ctrl4,data4, ctrl5,data5, ctrl6,data6, ctrl7,data7 , ctrl8,data8 , ctrl9,data9 , ctrl10,data10 , ctrl11,data11 , ctrl12,data12 , ctrl13,data13 )  \
{  long       _d32, _d_idx=data_idx;                                                                                                                                                                                              \
   APBADDRBSI _reg = BSI_Dn_CON( data_idx );                                                                                                                                                                                      \
   _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                      \
   _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                   \
   _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                      \
   _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                   \
   _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                      \
   _d32 = data3;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                   \
   _d32 = ctrl4;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                      \
   _d32 = data4;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                   \
   _d32 = ctrl5;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                      \
   _d32 = data5;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                   \
   _d32 = ctrl6;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                      \
   _d32 = data6;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                   \
   _d32 = ctrl7;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                      \
   _d32 = data7;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                   \
   _d32 = ctrl8;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                      \
   _d32 = data8;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                   \
   _d32 = ctrl9;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                      \
   _d32 = data9;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                   \
   _d32 = ctrl10; HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                      \
   _d32 = data10; HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                   \
   _d32 = ctrl11; HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                      \
   _d32 = data11; HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                   \
   _d32 = ctrl12; HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                      \
   _d32 = data12; HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                 \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                   \
   _d32 = ctrl13; HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                      \
   _d32 = data13; HW_WRITE( (APBADDR32)(_reg), _d32 );                                                                                                                                                                            \
}

#define  HW_WRITE_BSI_DATA_14( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3, ctrl4,data4, ctrl5,data5, ctrl6,data6, ctrl7,data7 , ctrl8,data8 , ctrl9,data9 , ctrl10,data10 , ctrl11,data11 , ctrl12,data12 , ctrl13,data13, ctrl14,data14 )  \
{  long       _d32, _d_idx=data_idx;                                                                                                                                                                                                             \
   APBADDRBSI _reg = BSI_Dn_CON( data_idx );                                                                                                                                                                                                     \
   _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                                     \
   _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                                  \
   _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                                     \
   _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                                  \
   _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                                     \
   _d32 = data3;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                                  \
   _d32 = ctrl4;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                                     \
   _d32 = data4;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                                  \
   _d32 = ctrl5;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                                     \
   _d32 = data5;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                                  \
   _d32 = ctrl6;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                                     \
   _d32 = data6;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                                  \
   _d32 = ctrl7;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                                     \
   _d32 = data7;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                                  \
   _d32 = ctrl8;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                                     \
   _d32 = data8;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                                  \
   _d32 = ctrl9;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                                     \
   _d32 = data9;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                                  \
   _d32 = ctrl10; HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                                     \
   _d32 = data10; HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                                  \
   _d32 = ctrl11; HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                                     \
   _d32 = data11; HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                                  \
   _d32 = ctrl12; HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                                     \
   _d32 = data12; HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                                  \
   _d32 = ctrl13; HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                                     \
   _d32 = data13; HW_WRITE( (APBADDR32)(_reg), _d32 );  _d_idx++;                                                                                                                                                                                \
   _reg = BSI_Dn_CON( _d_idx );                                                                                                                                                                                                                  \
   _d32 = ctrl14; HW_WRITE( _reg, TO_WORD(_d32) );      _reg += BSI_REG_IDX;                                                                                                                                                                     \
   _d32 = data14; HW_WRITE( (APBADDR32)(_reg), _d32 );                                                                                                                                                                                           \
}
#endif

/*=======================================================================================================================*/

#if IS_DLIF_CHIP || IS_DCR_IN_DLIF_CHIP
   #if IS_CHIP_MT6256_S00 || IS_CHIP_MT6251
/* ------------------------------------------------------------------------- */
/* MT6256_S00 and MT6251                                                     */
/* ------------------------------------------------------------------------- */
typedef  union
{  struct
   {  /*-----RX_CON0------*/
      int  lpbk_en      : 1;
      int  rx_iq_swp    : 1;
      int  rx_bypass    : 2;
      int  reserved1    : 3;
      int  rx_rst_en    : 1;
      int  rx_rpt_en    : 8;
      /*---RX_CON3--------*/
      int  itd_lock     : 1;
      int  itd_frc      : 1;
      int  itd_sel      : 1;
      int  idma_sel     : 1;
      int  itd_immdt    : 1;
      int  reserved2    : 3;
      int  thr_itd      : 8;
      /*---IREST_CON0-----*/
      int  p2x_scale    : 6;
      int  reserved3    :10;
      /*---BFE_CON1-------*/
      int  bfe_sor      : 1;
      int  reserved4    :15;
      /*---RX_MON---------*/
      int  fir3_mon_len :12;
      int  reserved5    : 4;
   } field;
   unsigned short  data[5];
} BFERXSET;

typedef  union
{  struct
   {  /*--TX_CON0----------*/
      int  mdsel         : 4;
      int  reserved1     : 4;
      int  all_10_gen    : 2;
      int  ramp_zero     : 1;
      int  bcien         : 1;
      int  reserved2     : 4;
      /*--TX_CON1----------*/
      int  tx_cnt_tgt    : 8;
      int  pm_dly        : 4;
      int  reserved3     : 4;
      /*--TX_PWR-----------*/
      int  pwr_sel0      : 2;
      int  pwr_sel1      : 2;
      int  pwr_sel2      : 2;
      int  pwr_sel3      : 2;
      int  tx_cnt_tgt_sw : 8;
   } field;
   unsigned short  data[3];
} BFETXSET;
   #elif IS_CHIP_MT6250
/* ------------------------------------------------------------------------- */
/* MT6250                                                                    */
/* ------------------------------------------------------------------------- */
typedef  union
{  struct
   {  /*-----RX_CON0-----------*/
      int  lpbk_en           : 1; // immediately
      int  rx_iq_swp         : 1; // immediately
      int  write_rx_dm_by_sw : 1; // immediately
      int  reserved1         : 3;
      int  rx_dc_notch_en    : 1; // immediately
      int  rx_rst_en         : 1; // immediately
      int  rx_rpt_en         : 8; // double buffer by slot
      /*---RX_TIME_CON0--------*/
      int  rx_null_str       : 7; // immediately
      int  rx_dcoc_str       : 7; // immediately
      int  reserved2         : 2;
      /*---RX_TIME_CON1--------*/
      int  rx_ircmpn_sw      : 7; // immediately
      int  reserved3         : 9;
   } field;
   unsigned short  data[3];
} BFERXSET;

typedef  union
{  struct
   {  /*--TX_CON0--------------*/
//    int  mdsel             : 4; // no epsk in MT6250
      int  reserved1         : 8;
      int  all_10_gen        : 2;
      int  reserved2         : 1;
      int  bcien             : 1;
      int  reserved3         : 4;
      /*--TX_CON1--------------*/
      int  tx_cnt_tgt        : 8; // timing alignment for the loopback use
//    int  pm_dly            : 4;
      int  reserved4         : 8;
   } field;
   unsigned short  data[2];
} BFETXSET;
   #elif IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
/* ------------------------------------------------------------------------- */
/* MT6572, MT6290, MT6595, MT6752_MD1 and MT6752_MD2                                       */
/* ------------------------------------------------------------------------- */
typedef  union
{  struct
   {  /*-----RX_CON0-----------*/
      int  lpbk_en           : 1;  // immediately
      int  rx_iq_swp         : 1;  // immediately
      int  write_rx_dm_by_sw : 1;  // immediately
      int  reserved1         : 3;
      int  rx_dc_notch_en    : 1;  // immediately
      int  rx_rst_en         : 1;  // immediately
      int  rx_rpt_en         : 8;  // double buffer by slot
      /*---RX_TIME_CON0--------*/
      int  rx_null_str_nb    : 7;  // immediately
      int  rx_dcoc_str_nb    : 7;  // immediately
      int  reserved2         : 2;
      /*---RX_TIME_CON1--------*/
      int  rx_ircmpn_sw      : 7;  // immediately
      int  reserved3         : 9;
      /*---RX_TIME_CON2--------*/
      int  rx_null_str       : 7;  // immediately
      int  rx_dcoc_str       : 7;  // immediately
      int  reserved4         : 2;
   } field;
   unsigned short  data[4];
} BFERXSET;

typedef  union
{  struct
   {  /*--TX_CON0-----------*/
      int  mdsel         :  6;  // double buffer and by slot
      int  reserved1     :  2;
      int  all_10_gen    :  2;  // double buffer
      int  reserved2     :  1;
      int  bcien         :  1;  // double buffer
      int  reserved3     :  4;
      /*--TX_CON1-----------*/
      int  tx_cnt_tgt    :  8;  // double buffer
      int  reserved4     :  8;
      /*--TX_CON2-----------*/
      int  reserved5     :  8;
      int  tx_cnt_tgt_sw :  8;  // double buffer
      /*--TX_PWR0-----------*/
      int  pwr_sel0      :  9;  // double buffer
      int  reserved6     :  7;
      /*--TX_PWR1-----------*/
      int  pwr_sel1      :  9;  // double buffer
      int  reserved7     :  7;
      /*--TX_PWR2-----------*/
      int  pwr_sel2      :  9;  // double buffer
      int  reserved8     :  7;
      /*--TX_PWR3-----------*/
      int  pwr_sel3      :  9;  // double buffer
      int  reserved9     :  7;
      /*--TX_PWR4-----------*/
      int  pwr_sel4      :  9;  // double buffer
      int  reserved10    :  7;
      /*--TX_PWR5-----------*/
      int  pwr_sel5      :  9;  // double buffer
      int  reserved11    :  7;
      /*--TX_DLY_CON--------*/
      int  pm_dly        :  2;  // double buffer
      int  am_dly        :  2;  // double buffer
      int  reserved12    :  9;
      int  crc_ampmiq    :  1;  // double buffer
      int  crc_txrx      :  1;  // double buffer
      int  crc_on        :  1;  // double buffer
   } field;
   unsigned short  data[10];
} BFETXSET;
   #elif IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2
/* ------------------------------------------------------------------------- */
/* MT6583                                                                    */
/* ------------------------------------------------------------------------- */
typedef  union
{  struct
   {  /*-----RX_CON0-----------*/
      int  lpbk_en           : 1;  // immediately
      int  rx_iq_swp         : 1;  // immediately
      int  write_rx_dm_by_sw : 1;  // immediately
      int  reserved1         : 3;
      int  rx_dc_notch_en    : 1;  // immediately
      int  rx_rst_en         : 1;  // immediately
      int  rx_rpt_en         : 8;  // double buffer by slot
      /*---RX_TIME_CON0--------*/
      int  rx_null_str       : 7;  // immediately
      int  rx_dcoc_str       : 7;  // immediately
      int  reserved2         : 2;
      /*---RX_TIME_CON1--------*/
      int  rx_ircmpn_sw      : 7;  // immediately
      int  reserved3         : 9;
   } field;
   unsigned short  data[3];
} BFERXSET;

typedef  union
{  struct
   {
      /*-TX_PH --------------*/
      int         phseli : 6;
      int      reserved1 : 2;
      int         phselq : 6;
      int      reserved2 : 2;
      /*-TX_OFF -------------*/
      int           offi : 8;
      int           offq : 8;
      /*-TX_GAIN ------------*/
      int      gain_comp : 7;
      int     iqgain_sel : 1;
      int      reserved4 :24;
   } field1;
   struct
   {
      int          tx_ph :16;
      int         tx_off :16;
      int        tx_gain : 8;
      int        tx_res1 : 8;
      int        tx_res2 :16;
   } field2;
   unsigned short  data[4];
} BFETXCON;

typedef  union
{  struct
   {  /*--TX_CON0-----------*/
      int  mdsel         :  6;  // double buffer and by slot
      int  reserved1     :  2;
      int  all_10_gen    :  2;  // double buffer
      int  reserved2     :  1;
      int  bcien         :  1;  // double buffer
      int  reserved3     :  4;
      /*--TX_CON1-----------*/
      int  tx_cnt_tgt    :  8;  // double buffer
      int  reserved4     :  8;
      /*--TX_CON2-----------*/
      int  reserved5     :  8;
      int  tx_cnt_tgt_sw :  8;  // double buffer
      /*--TX_PWR0-----------*/
      int  pwr_sel0      :  9;  // double buffer
      int  reserved6     :  7;
      /*--TX_PWR1-----------*/
      int  pwr_sel1      :  9;  // double buffer
      int  reserved7     :  7;
      /*--TX_PWR2-----------*/
      int  pwr_sel2      :  9;  // double buffer
      int  reserved8     :  7;
      /*--TX_PWR3-----------*/
      int  pwr_sel3      :  9;  // double buffer
      int  reserved9     :  7;
      /*--TX_PWR4-----------*/
      int  pwr_sel4      :  9;  // double buffer
      int  reserved10    :  7;
      /*--TX_PWR5-----------*/
      int  pwr_sel5      :  9;  // double buffer
      int  reserved11    :  7;
      /*--TX_DLY_CON--------*/
      int  pm_dly        :  2;  // double buffer
      int  am_dly        :  2;  // double buffer
      int  reserved12    :  9;
      int  crc_ampmiq    :  1;  // double buffer
      int  crc_txrx      :  1;  // double buffer
      int  crc_on        :  1;  // double buffer
      /*-TX_PH x 6----------*/
      int  phseli        :  6;
      int  reserved13    :  2;
      int  phselq        :  6;
      int  reserved14    :  2;
      /*-TX_GAIN x 3--------*/
      int  gain_comp     :  7;
      int  iqgain_sel    :  1;
      int  reserved15    :  8;
      /*-TX_OFF x 6---------*/
      int  offi          :  8;
      int  offq          :  8;
   } field;
   unsigned short  data[13];
} BFETXSET;
   #elif IS_CHIP_MT6280
/* ------------------------------------------------------------------------- */
/* MT6280                                                                    */
/* ------------------------------------------------------------------------- */
typedef  union
{  struct
   {  /*-----RX_CON0-----------*/
      int  lpbk_en           : 1;  // immediately
      int  rx_iq_swp         : 1;  // immediately
      int  write_rx_dm_by_sw : 1;  // immediately
      int  reserved1         : 3;
      int  rx_dc_notch_en    : 1;  // immediately
      int  rx_rst_en         : 1;  // immediately
      int  rx_rpt_en         : 8;  // double buffer by slot
      /*---RX_TIME_CON0--------*/
      int  rx_null_str       : 7;  // immediately
      int  rx_dcoc_str       : 7;  // immediately
      int  reserved2         : 2;
      /*---RX_TIME_CON1--------*/
      int  rx_ircmpn_sw      : 7;  // immediately
      int  reserved3         : 9;
   } field;
   unsigned short  data[3];
} BFERXSET;

typedef  union
{  struct
   {  /*--TX_CON0-----------*/
      int  mdsel         :  6;  // double buffer and by slot
      int  reserved1     :  2;
      int  all_10_gen    :  2;  // double buffer
      int  reserved2     :  1;
      int  bcien         :  1;  // double buffer
      int  reserved3     :  4;
      /*--TX_CON1-----------*/
      int  tx_cnt_tgt    :  8;  // double buffer
      int  reserved4     :  8;
      /*--TX_CON2-----------*/
      int  reserved5     :  8;
      int  tx_cnt_tgt_sw :  8;  // double buffer
      /*--TX_PWR0-----------*/
      int  pwr_sel0      :  9;  // double buffer
      int  reserved6     :  7;
      /*--TX_PWR1-----------*/
      int  pwr_sel1      :  9;  // double buffer
      int  reserved7     :  7;
      /*--TX_PWR2-----------*/
      int  pwr_sel2      :  9;  // double buffer
      int  reserved8     :  7;
      /*--TX_PWR3-----------*/
      int  pwr_sel3      :  9;  // double buffer
      int  reserved9     :  7;
      /*--TX_DLY_CON--------*/
      int  pm_dly        :  2;  // double buffer
      int  am_dly        :  2;  // double buffer
      int  reserved10    : 12;
   } field;
   unsigned short  data[8];
} BFETXSET;
   #else
/* ------------------------------------------------------------------------- */
/* MT6256_S01 and MT6255                                                     */
/* ------------------------------------------------------------------------- */
typedef  union
{  struct
   {  /*-----RX_CON0---------*/
      int  lpbk_en        :  1;
      int  rx_iq_swp      :  1;
      int  reserved1      :  4;
      int  rx_dc_notch_en :  1;
      int  rx_rst_en      :  1;
      int  rx_rpt_en      :  8;
      /*---RX_TIME_CON0------*/
      int  rx_null_str    :  7;
      int  rx_dcoc_str    :  7;
      int  reserved2      :  2;
      /*---RX_TIME_CON1------*/
      int  rx_ircmpn_sw   :  7;
      int  reserved3      :  9;
      /*---RX_MON------------*/
      int  fir3_mon_len   : 11;
      int  reserved4      :  5;
   } field;
   unsigned short  data[4];
} BFERXSET;

typedef  union
{  struct
   {  /*--TX_CON0----------*/
      int  mdsel         : 4;
      int  reserved1     : 4;
      int  all_10_gen    : 2;
      int  reserved2     : 1;
      int  bcien         : 1;
      int  reserved3     : 4;
      /*--TX_CON1----------*/
      int  tx_cnt_tgt    : 8;
      int  pm_dly        : 4;
      int  reserved4     : 4;
      /*--TX_CON2----------*/
      int  reserved5     : 8;
      int  tx_cnt_tgt_sw : 8;
      /*--TX_PWR-----------*/
      int  pwr_sel0      : 3;
      int  reserved6     : 1;
      int  pwr_sel1      : 3;
      int  reserved7     : 1;
      int  pwr_sel2      : 3;
      int  reserved8     : 1;
      int  pwr_sel3      : 3;
      int  reserved9     : 1;
   } field;
   unsigned short  data[4];
} BFETXSET;
   #endif
#elif IS_CHIP_MT6227
/* ------------------------------------------------------------------------- */
/* MT6227                                                                    */
/* ------------------------------------------------------------------------- */
typedef  union
{  struct
   {  /*-RX_CFG----------*/
      int      swap : 1;
      int   bypfltr : 1;
      int reserved1 : 10;
      int      lpdn : 4;
      /*-RX_CON----------*/
      int     blpen : 2;
      int reserved2 : 14;
      /*-BBRX_AC_CON-----*/
      int   calbias : 5;
      int      gain : 1;
      int    pdnchp : 1;
      int       rsv : 1;
      int      isel : 2;
      int      qsel : 2;
      int reserved3 : 4;
   } field;
   unsigned short  data[3];
} BFERXSET;

typedef  union
{  struct
   {  /*-TX_CFG----------*/
      int     apnden   : 1;
      int  reserved1   : 15;
      /*-TX_CON----------*/
      int       iqswap : 1;
      int      calrcen : 1;
      int iqswap_onfly : 1;
      int    reserved2 : 13;
      /*-TX_OFF----------*/
      int       offi   : 6;
      int  reserved3   : 2;
      int       offq   : 6;
      int  reserved4   : 2;
      /*-BBTX_AC_CON0----*/
      int      trimq   : 4;
      int      trimi   : 4;
      int   calrcsel   : 3;
      int       gain   : 3;
      int startcalrc   : 1;
      int  calrcdone   : 1;
      /*-BBTX_AC_CON1----*/
      int        cmv   : 3;
      int    calbias   : 5;
      int   calrccnt   : 4;
      int        flt   : 1;
      int   calrcout   : 3;
   } field;
   unsigned short  data[5];
} BFETXSET;

#elif IS_CHIP_MT6252
/* ------------------------------------------------------------------------- */
/* MT6252                                                                    */
/* ------------------------------------------------------------------------- */
typedef  union
{  struct
   {  /*-RX_CFG-----------*/
      int          swap : 1;
      int       bypfltr : 1;
      int     _2xfirsel : 1;
      int     reserved1 : 1;
      int       firtpno : 6;
      int     reserved2 : 6;
      /*-RX_CON-----------*/
      int         blpen : 2;
      int     ph_roen_w : 1;
      int     ph_roen_n : 1;
      int      igainsel : 4;
      int     pwrshftno : 4;
      int     reserved3 : 4;
      /*-BBRX_AC_CON------*/
      int       calbias : 4;
      int     reserved4 : 1;
      int          gain : 2;
      int     reserved5 : 1;
      int          isel : 2;
      int          qsel : 2;
      int       dithdis : 1;
      int     reserved6 : 3;
      /*-RX_PM_CON--------*/
      int  RXID_PWR_OFF : 8;
      int  RXID_PWR_PER : 8;
      /*-RX_FIR_CSID_CON--*/
      int ST_B_WCOF_SEL : 4;
      int ST_B_NCOF_SEL : 4;
      int     reserved7 : 4;
      int ST_A_NCOF_SEL : 4;
   } field;
   unsigned short  data[5];
} BFERXSET;

typedef  union
{  struct
   {  /*-TX_CFG-----------*/
      int        apnden : 1;
      int     reserved1 : 3;
      int         mdbyp : 1;
      int          sgen : 1;
      int     all_10_en : 2;
      int     reserved2 : 8;
      /*-TX_CON-----------*/
      int        iqswap : 1;
      int     reserved3 : 7;
      int         phsel : 3;
      int     reserved4 : 5;
      /*-TX_OFF-----------*/
      int          offi : 6;
      int     reserved5 : 2;
      int          offq : 6;
      int     reserved6 : 1;
      int       off_typ : 1;
   } field;
   unsigned short  data[3];
} BFETXSET;

#elif IS_CHIP_MT6225_AND_LATTER_VERSION || IS_CHIP_MT6223 || IS_CHIP_MT6253
/* ------------------------------------------------------------------------- */
/* MT6223,MT6225~                                                            */
/* ------------------------------------------------------------------------- */
typedef  union
{  struct
   {  /*-RX_CFG----------*/
      int      swap     : 1;
      int   bypfltr     : 1;
      int _2xfirsel     : 1;
      int reserved1     : 1;
      int   firtpno     : 6;
      int reserved2     : 6;
      /*-RX_CON----------*/
      int     blpen     : 2;
      int ph_roen_w     : 1;
      int ph_roen_n     : 1;
      int  igainsel     : 4;
      int pwrshftno     : 4;
      int reserved3     : 4;
      /*-BBRX_AC_CON-----*/
      int   calbias     : 5;
      int      gain     : 2;
      int       rsv     : 1;
      int      isel     : 2;
      int      qsel     : 2;
      int   dithdis     : 1;
      int reserved4     : 3;
      /*-RX_PWR_CON-------*/
      int  RXID_PWR_OFF : 8;
      int  RXID_PWR_PER : 8;
      /*-RX_CSSEEL_CON----*/
      int ST_B_WCOF_SEL : 4;
      int ST_B_NCOF_SEL : 4;
      int     reserved5 : 4;
      int ST_A_NCOF_SEL : 4;
   } field;
   unsigned short  data[5];
} BFERXSET;

typedef  union
{  struct
   {  /*-TX_CFG----------*/
      int     apnden : 1;
      int  reserved1 : 3;
      int      mdbyp : 1;
      int       sgen : 1;
      int  all_10_en : 2;
      int  reserved2 : 8;
      /*-TX_CON----------*/
      int     iqswap : 1;
      int  reserved3 : 7;
      int      phsel : 3;
      int  reserved4 : 5;
      /*-TX_OFF----------*/
      int       offi : 6;
      int  reserved5 : 2;
      int       offq : 6;
      int  reserved6 : 1;
      int    off_typ : 1;
      /*-BBTX_AC_CON0----*/
      int      trimq : 4;
      int      trimi : 4;
      int   calrcsel : 3;
      int       gain : 3;
      int startcalrc : 1;
      int  calrcdone : 1;
      /*-BBTX_AC_CON1----*/
      int        cmv : 3;
      int    calbias : 4;
      int   calrccnt : 5;
      int        flt : 1;
      int   calrcout : 3;
      /*-BBTX_AC_CON2----*/
      int  calrcopen : 1;
      int  calrcauto : 1;
      int     coarse : 2;
   #if IS_CHIP_MT6253
      int      dwaen : 1;
      int    dac_ptr : 4;
   #else
      int  reserved7 : 1;
      int      dwaen : 1;
      int    dac_ptr : 3;
   #endif
      int  dccoarsei : 2;
      int  dccoarseq : 2;
      int  reserved8 : 3;
   } field;
   unsigned short  data[6];
} BFETXSET;

#elif IS_CHIP_MT6218_AND_LATTER_VERSION
/* ------------------------------------------------------------------------- */
/* MT6218~                                                                   */
/* ------------------------------------------------------------------------- */
typedef  union
{  struct
   {  /*-RX_CFG----------*/
      int      swap : 1;
      int   bypfltr : 1;
      int reserved1 : 10;
      int      lpdn : 4;
      /*-RX_CON----------*/
      int     blpen : 2;
      int reserved2 : 14;
      /*-BBRX_AC_CON-----*/
      int   calbias : 5;
      int      gain : 1;
      int    pdnchp : 1;
      int       rsv : 1;
      int      isel : 2;
      int      qsel : 2;
      int reserved3 : 4;
   } field;
   unsigned short  data[3];
} BFERXSET;

typedef  union
{  struct
   {  /*-TX_CFG----------*/
      int     apnden : 1;
      int  reserved1 : 15;
      /*-TX_CON----------*/
      int     iqswap : 1;
      int    calrcen : 1;
      int  reserved2 : 14;
      /*-TX_OFF----------*/
      int       offi : 6;
      int  reserved3 : 2;
      int       offq : 6;
      int  reserved4 : 2;
      /*-BBTX_AC_CON0----*/
      int      trimq : 4;
      int      trimi : 4;
      int   calrcsel : 3;
      int       gain : 3;
      int startcalrc : 1;
      int  calrcdone : 1;
      /*-BBTX_AC_CON1----*/
      int        cmv : 3;
      int    calbias : 5;
      int   calrccnt : 4;
      int        flt : 1;
      int   calrcout : 3;
   } field;
   unsigned short  data[5];
} BFETXSET;

#elif IS_BBTXRX_CHIP_DESIGN_VER_2
/* ------------------------------------------------------------------------- */
/* MT6276~                                                                   */
/* ------------------------------------------------------------------------- */
typedef  union
{  struct
   {  /*-RX_CFG-------------*/
      int           swap : 1;
      int        bypfltr : 1;
      int      reserved1 : 2;
      int        firtpno : 6;
      int      reserved2 : 6;
      /*-RX_CON0 = RX_CON---*/
      int          blpen : 2;
      int      ph_roen_w : 1;
      int      ph_roen_n : 1;
      int       igainsel : 4;
      int      pwrshftno : 4;
      int      reserved3 : 4;
      /*-RX_CON1------------*/
      int      rx_pwr2en : 7;
      int      reserved4 : 9;
      /*-RX_PM_CON----------*/
      int   RXID_PWR_OFF : 8;
      int   RXID_PWR_PER : 8;
      /*-RX_FIR_CSID_CON----*/
      int  ST_B_WCOF_SEL : 4;
      int  ST_B_NCOF_SEL : 4;
      int      reserved5 : 4;
      int  ST_A_NCOF_SEL : 4;
   } field;
   unsigned short  data[5];
} BFERXSET;

typedef  union
{  struct
   {
      /*-TX_PH --------------*/
      int         phseli : 6;
      int      reserved1 : 2;
      int         phselq : 6;
      int      reserved2 : 2;
      /*-TX_OFF -------------*/
      int           offi : 8;
      int           offq : 8;
      /*-TX_GAIN ------------*/
   #if IS_CHIP_MT6575
      int      gain_comp : 7;
      int     iqgain_sel : 1;
   #else
      int      gain_comp : 6;
      int     iqgain_sel : 1;
      int      reserved3 : 1;
   #endif
      int      reserved4 :24;
   } field1;
   struct
   {
      int          tx_ph :16;
      int         tx_off :16;
      int        tx_gain : 8;
      int        tx_res1 : 8;
      int        tx_res2 :16;
   } field2;
   unsigned short  data[4];
} BFETXCON;

typedef  union
{  struct
   {  /*-TX_CFG0 = TX_CFG----*/
      int         apnden : 1;
      int          rpsel : 2;
      int          inten : 1;
      int          mdbyp : 1;
      int           sgen : 1;
      int      all_10_en : 2;
      int       sw_qbcnt : 5;
      int  gmsk_dtap_sym : 2;
      int      reserved1 : 1;
      /*-TX_CFG1-------------*/
      int      sgen_step : 5;
      int  epsk_dtap_sym : 2;
      int      reserved2 : 9;
      /*-TX_CON0 = TX_CON----*/
      int         iqswap : 1;
      int      reserved3 : 1;
      int         mdsel1 : 1;
      int         mdsel2 : 1;
      int         mdsel3 : 1;
      int         mdsel4 : 1;
      int         mdsel5 : 1;
      int         mdsel6 : 1;
      int      reserved4 : 2;
      int       txout_ph : 1;
      int   epsk_dtap_qb : 2;
      int   gmsk_dtap_qb : 2;
      int     gmsk_phrst : 1;
      /*-TX_CON1-------------*/
      int      tx_pwr2en : 7;
      int      reserved5 : 9;
      /*-TX_PH x 6-----------*/
      int         phseli : 6;
      int      reserved6 : 2;
      int         phselq : 6;
      int      reserved7 : 2;
      /*-TX_GAIN x 3---------*/
   #if IS_CHIP_MT6575
      int      gain_comp : 7;
      int     iqgain_sel : 1;
   #else
      int      gain_comp : 6;
      int     iqgain_sel : 1;
      int      reserved8 : 1;
   #endif
      int      reserved9 : 8;
      /*-TX_OFF x 6----------*/
      int           offi : 8;
      int           offq : 8;
      /*-BBTX_CON5-----------*/
      int     reserved10 : 12;
      int            cmv : 2;
      int     reserved11 : 2;
   } field;
   unsigned short  data[8];
} BFETXSET;

#elif IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
/* ------------------------------------------------------------------------- */
/* MT6238~                                                                   */
/* ------------------------------------------------------------------------- */
typedef  union
{  struct
   {  /*-RX_CFG-------------*/
      int      swap     : 1;
      int   bypfltr     : 1;
      int reserved1     : 2;
      int   firtpno     : 6;
      int reserved2     : 6;
      /*-RX_CON-------------*/
      int     blpen     : 2;
      int ph_roen_w     : 1;
      int ph_roen_n     : 1;
      int  igainsel     : 4;
      int pwrshftno     : 4;
      int reserved3     : 4;
      /*-BBRX_AC_CON--------*/
      int   calbias     : 5;
      int      gain     : 2;
      int       rsv     : 1;
      int      isel     : 2;
      int      qsel     : 2;
      int   dithdis     : 1;
      int reserved4     : 3;
      /*-RX_PM_CON----------*/
      int  RXID_PWR_OFF : 8;
      int  RXID_PWR_PER : 8;
      /*-RX_FIR_CSID_CON----*/
      int ST_B_WCOF_SEL : 4;
      int ST_B_NCOF_SEL : 4;
      int     reserved5 : 4;
      int ST_A_NCOF_SEL : 4;
   } field;
   unsigned short  data[5];
} BFERXSET;

typedef  union
{  struct
   {  /*-TX_CFG----------*/
      int     apnden     : 1;
      int      rpsel     : 2;
      int      inten     : 1;
      int      mdbyp     : 1;
      int       sgen     : 1;
      int  all_10_en     : 2;
      int   sw_qbcnt     : 5;
      int  gmsk_dtap_sym : 2;
      int  reserved1     : 1;
   #if IS_CHIP_MT6268T_DMAC || IS_CHIP_MT6270A
      /*-TX_CON----------*/
      int     iqswap     : 1;
      int  reserved2     : 1;
      int     mdsel1     : 1;
      int     mdsel2     : 1;
      int     mdsel3     : 1;
      int     mdsel4     : 1;
      int     mdsel5     : 1;
      int     mdsel6     : 1;
      int     mdsel7     : 1;
      int      phsel     : 4;
      int  gmsk_dtap_qb  : 2;
      int  reserved4     : 1;
   #else
      /*-TX_CON----------*/
      int     iqswap     : 1;
      int  reserved2     : 1;
      int     mdsel1     : 1;
      int     mdsel2     : 1;
      int     mdsel3     : 1;
      int     mdsel4     : 1;
      int  reserved3     : 2;
      int      phsel     : 4;
      int  gmsk_dtap_qb  : 2;
      int  reserved4     : 2;
   #endif
      /*-TX_OFF----------*/
      int       offi     : 6;
      int  reserved5     : 2;
      int       offq     : 6;
      int  reserved6     : 1;
      int    off_typ     : 1;
      /*-BBTX_AC_CON0----*/
      int      trimq     : 4;
      int      trimi     : 4;
      int   calrcsel     : 3;
      int       gain     : 3;
      int startcalrc     : 1;
      int  calrcdone     : 1;
      /*-BBTX_AC_CON1----*/
      int        cmv     : 3;
      int    calbias     : 4;
      int   calrccnt     : 5;
      int        flt     : 1;
      int   calrcout     : 3;
      /*-BBTX_AC_CON2----*/
      int  calrcopen     : 1;
      int  calrcauto     : 1;
      int     coarse     : 2;
      int      dwaen     : 1;
      int    dac_ptr     : 3;
      int  reserved7     : 1;
      int  dccoarsei     : 2;
      int  dccoarseq     : 2;
      int  reserved8     : 3;
   #if IS_CHIP_MT6268
      /*-BBTX_AC_CON3----*/
      int     wb_trimq   : 4;
      int     wb_trimi   : 4;
      int       wb_cmv   : 3;
      int      wb_gain   : 3;
      int         en2g   : 1;
      int      modesel   : 1;
      /*-BBTX_AC_CON4----*/
      int wb_dccoarsei   : 2;
      int wb_dccoarseq   : 2;
      int     reserved   :12;
   #endif
   } field;
   #if IS_CHIP_MT6268
   unsigned short  data[8];
   #else
   unsigned short  data[6];
   #endif
} BFETXSET;

#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION && !IS_CHIP_MT6223 && !IS_CHIP_MT6238 && !IS_CHIP_MT6253
/* ------------------------------------------------------------------------- */
/* MT6229~                                                                   */
/* ------------------------------------------------------------------------- */
typedef  union
{  struct
   {  /*-RX_CFG-------------*/
      int      swap     : 1;
      int   bypfltr     : 1;
      int _2xfirsel     : 1;
      int reserved1     : 1;
      int   firtpno     : 6;
      int reserved2     : 6;
      /*-RX_CON-------------*/
      int     blpen     : 2;
      int ph_roen_w     : 1;
      int ph_roen_n     : 1;
      int  igainsel     : 4;
      int pwrshftno     : 4;
      int reserved3     : 4;
      /*-BBRX_AC_CON--------*/
      int   calbias     : 5;
      int      gain     : 2;
      int       rsv     : 1;
      int      isel     : 2;
      int      qsel     : 2;
      int reserved4     : 4;
      /*-RX_PM_CON----------*/
      int  RXID_PWR_OFF : 8;
      int  RXID_PWR_PER : 8;
      /*-RX_FIR_CSID_CON----*/
      int ST_B_WCOF_SEL : 4;
      int ST_B_NCOF_SEL : 4;
      int     reserved5 : 4;
      int ST_A_NCOF_SEL : 4;
   } field;
   unsigned short  data[5];
} BFERXSET;

typedef  union
{  struct
   {  /*-TX_CFG----------*/
      int     apnden     : 1;
      int      rpsel     : 2;
      int      inten     : 1;
      int      mdbyp     : 1;
      int       sgen     : 1;
      int  all_10_en     : 2;
      int   sw_qbcnt     : 5;
      int  gmsk_dtap_sym : 2;
      int  reserved1     : 1;
      /*-TX_CON----------*/
      int     iqswap     : 1;
      int    calrcen     : 1;
      int     mdsel1     : 1;
      int     mdsel2     : 1;
      int     mdsel3     : 1;
      int     mdsel4     : 1;
      int  reserved2     : 2;
      int      phsel     : 3;
      int  reserved3     : 1;
      int  gmsk_dtap_qb  : 2;
      int  reserved4     : 2;
      /*-TX_OFF----------*/
      int       offi     : 6;
      int  reserved5     : 2;
      int       offq     : 6;
      int  reserved6     : 2;
      /*-BBTX_AC_CON0----*/
      int      trimq     : 4;
      int      trimi     : 4;
      int   calrcsel     : 3;
      int       gain     : 3;
      int startcalrc     : 1;
      int  calrcdone     : 1;
      /*-BBTX_AC_CON1----*/
      int        cmv     : 3;
      int    calbias     : 4;
      int   calrccnt     : 5;
      int        flt     : 1;
      int   calrcout     : 3;
   } field;
   unsigned short  data[5];
} BFETXSET;

#else
/* ------------------------------------------------------------------------- */
/* OTHERS                                                                    */
/* ------------------------------------------------------------------------- */
typedef  union
{  struct
   {  /*-RX_CFG----------*/
      int reserved1 : 1;
      int      swap : 1;
      int      chop : 1;
      int    offcal : 1;
      int      isel : 2;
      int      qsel : 2;
      int      gain : 1;
      int   bypflte : 1;
      int reserved2 : 6;
      /*-RX_CON----------*/
      int   calbias : 5;
      int     blpen : 2;
      int reserved3 : 9;
   } field;
   unsigned short  data[2];
} BFERXSET;

typedef  union
{  struct
   {  /*-TX_CFG----------*/
      int        cmv : 3;
      int       gain : 3;
      int        flt : 1;
      int     lpbkrx : 1;
      int      trimi : 4;
      int      trimq : 4;
      /*-TX_CON----------*/
      int    calbias : 5;
      int   calrcsel : 3;
      int    calrcen : 1;
      int     iqswap : 1;
      int  reserved1 : 2;
      int   calrccnt : 4;
      /*-TX_OFFI---------*/
      int       offi : 6;
      int  reserved2 : 10;
      /*-TX_OFFQ---------*/
      int       offq : 6;
      int  reserved3 : 10;
   } field;
   unsigned short  data[4];
} BFETXSET;
#endif

/*=======================================================================================================================*/

#include "l1_interface_reg.h"

#if IS_AFC_EVENT_SUPPORT_CHIP
#define AFC_EV0                  TDMA_AFC(0)
#endif
#define BDLON0                   TDMA_BDLON(0)
#define BDLOFF0                  TDMA_BDLOFF(0)
#define BULON0                   TDMA_BULON(0)
#define BULOFF0                  TDMA_BULOFF(0)
#define APC_EV0                  TDMA_APC(0)
#define BSI_EV0                  TDMA_BSI(0)
#define BPI_EV0                  TDMA_BPI(0)
#define EVENT_ENA0               TDMA_EVTENA(0)
#define EVENT_ENA1               TDMA_EVTENA(1)
#define EVENT_ENA2               TDMA_EVTENA(2)
#define EVENT_ENA3               TDMA_EVTENA(3)
#define EVENT_ENA4               TDMA_EVTENA(4)
#define EVENT_ENA5               TDMA_EVTENA(5)
#define EVENT_ENA6               TDMA_EVTENA(6)
#define EVENT_ENA7               TDMA_EVTENA(7)
#if IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define EVENT_ENA8               TDMA_EVTENA(8)
#define EVENT_ENA9               TDMA_EVTENA(9)
#endif
#define BSI_EN                   BSI_ENA
#define BSI_EN1                  BSI_ENA1
#if IS_CHIP_MT6256 || IS_CHIP_MT6251 || IS_CHIP_MT6255 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define BSI_EN2                  BSI_ENA2
#endif
#if IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define BSI_EN3                  BSI_ENA3
#endif
#define SHARE_DSPCTL             SHARE_DSPCON
#define SHARE_D2MCTL             SHARE_D2MCON
#define SW_RSTN                  SW_PERIPH_RSTN

/*=======================================================================================================================*/

#if IS_FD216_DSP_CHIP
/*==============*\
|* Patch Fields *|
\* ===================================================================================================================== */
/* for MT6208 & MT6205 & MT6218                                                                                          */
/* --------------------------------------------------------------------------------------------------------------------- */
#define PATCH_ENA                ((APBADDR)(PATCH_base+0x100))          /* patch enable register                         */
#define PATCH_P(n)               ((APBADDR)(PATCH_base+0x000+(n)*4))    /* the page number of patched instruction n      */
#define PATCH_A(n)               ((APBADDR)(PATCH_base+0x004+(n)*4))    /*     the address of patched instruction n      */
#define PATCH_IL(n)              ((APBADDR)(PATCH_base+0x008+(n)*4))    /*    low  16 bits of patched instruction n      */
#define PATCH_IH(n)              ((APBADDR)(PATCH_base+0x00C+(n)*4))    /*    high  8 bits of patched instruction n      */
   #if IS_CHIP_MT6229 || IS_CHIP_MT6268T
#define PATCH2_ENA               ((APBADDR)(PATCH2_base+0x100))         /* patch enable register                         */
#define PATCH2_P(n)              ((APBADDR)(PATCH2_base+0x000+(n)*4))   /* the page number of patched instruction n      */
#define PATCH2_A(n)              ((APBADDR)(PATCH2_base+0x004+(n)*4))   /*     the address of patched instruction n      */
#define PATCH2_IL(n)             ((APBADDR)(PATCH2_base+0x008+(n)*4))   /*    low  16 bits of patched instruction n      */
#define PATCH2_IH(n)             ((APBADDR)(PATCH2_base+0x00C+(n)*4))   /*    high  8 bits of patched instruction n      */
   #endif
/* ===================================================================================================================== */
#endif /*IS_FD216_DSP_CHIP*/

#if IS_FD216_DSP_CHIP || IS_CHIP_MT6268T_DMAC || IS_CHIP_MT6270A
/*==========================*\
|* Audio Front End Register *|
\* ===================================================================================================================== */
/* for MT6208                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define VCSR                     ((APBADDR)(AFE_base+0x0000))           /* Voice-band Common Status Register             */
#define VAGCR                    ((APBADDR)(AFE_base+0x0004))           /* Voice-band Gain Contol Register               */
#define VACCR0                   ((APBADDR)(AFE_base+0x0008))           /* Voice-band Analog-Circuit Control Register    */
#define VACCR1                   ((APBADDR)(AFE_base+0x000C))           /* Voice-band Analog-Circuit Control Register    */
#define VAPDNCR                  ((APBADDR)(AFE_base+0x0010))           /* Voice-band Power Down Control Register        */
#define VBTDAICR                 ((APBADDR)(AFE_base+0x0014))           /* Voice-band Blue Tooth and DAI Control Register*/
#define VLBCR                    ((APBADDR)(AFE_base+0x0018))           /* Voice-band Look_Back mode Control Register    */
/* ===================================================================================================================== */
/* for MT6205                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define AFE_MCU_CON              ((APBADDR)(AFE_base+0x0000))           /* AFE MCU Cpntrol Register                      */
#define AFE_AG_CON               ((APBADDR)(AFE_base+0x0004))           /* AFE Analog Gain Control Register              */
#define AFE_AC_CON0              ((APBADDR)(AFE_base+0x0008))           /* AFE Analog-Circuit Control Register 0         */
#define AFE_AC_CON1              ((APBADDR)(AFE_base+0x000C))           /* AFE Analog-Circuit Control Register 1         */
#define AFE_APDN_CON             ((APBADDR)(AFE_base+0x0010))           /* AFE Analog Power Down Control Register        */
#define AFE_DAI_CON              ((APBADDR)(AFE_base+0x0014))           /* AFE DAI Control Register                      */
#define AFE_LB_CON               ((APBADDR)(AFE_base+0x0018))           /* AFE Loop-back Mode Control Register           */
/* ===================================================================================================================== */
/* for MT6218                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define AFE_VMCU_CON             ((APBADDR)(AFE_base+0x0000))           /* AFE Voice MCU Control Register                */
#define AFE_VAC_DCON1            ((APBADDR)(AFE_base+0x000C))           /* AFE Voice Analog Circuit Control Register 1   */
#define AFE_VDB_CON              ((APBADDR)(AFE_base+0x0014))           /* AFE Voice DAI Blue Tooth Control Register     */
#define AFE_VLB_CON              ((APBADDR)(AFE_base+0x0018))           /* AFE Voice Loop-back Mode Control Register     */
#define AFE_AMCU_CON0            ((APBADDR)(AFE_base+0x0020))           /* AFE Audio MCU Control Register 0gister        */
#define AFE_AMCU_CON1            ((APBADDR)(AFE_base+0x0024))           /* AFE Audio Control Register 1                  */
/* ===================================================================================================================== */
#endif

/*====================*\
|* Baseband Front End *|
\*====================*/
#if IS_DLIF_CHIP || IS_DCR_IN_DLIF_CHIP
/* ===================================================================================================================== */
/* for MT6256/51                                                                                                         */
/* --------------------------------------------------------------------------------------------------------------------- */
   #if IS_CHIP_MT6256_S00 || IS_CHIP_MT6251
#define BFE_CON0                 ((APBADDR)(BFE_base+0x0000))/* This register is for control of BFE top                  */
#define BFE_CON1                 ((APBADDR)(BFE_base+0x0004))
#define TX_CON0                  ((APBADDR)(BFE_base+0x0400))/* This register is for control of uplink path              */
                                                             /* inclusive of control of TX mixed-signal                  */
                                                             /* module and TX path in Baseband Front End                 */
#define TX_CON1                  ((APBADDR)(BFE_base+0x0404))/* This register is for control of TX power and mode switching timing*/
#define TX_PWR                   ((APBADDR)(BFE_base+0x0408))/* This register is for control of uplink path power        */
#define RX_CON0                  ((APBADDR)(BFE_base+0x0800))/* [0]loopback mode enable,                                 */
                                                             /* [1]RX IQ SWAP                                            */
                                                             /* [7]Reset RX filter as slot change                        */
                                                             /* [8:15]repeat enable                                      */
#define RX_CON1                  ((APBADDR)(BFE_base+0x0804))/* inclusive of control of RX mixed-signal module           */
#define RX_CON2                  ((APBADDR)(BFE_base+0x0808))/* and RX path in Baseband Front End module                 */
#define RX_CON3                  ((APBADDR)(BFE_base+0x080C))
#define RX_TYPE_CON0             ((APBADDR)(BFE_base+0x0810))
#define RX_TYPE_CON1             ((APBADDR)(BFE_base+0x0814))
#define RX_W_RE(n)               ((APBADDR)(BFE_base+0x08B0+(n)*4))
#define RX_W_IM(n)               ((APBADDR)(BFE_base+0x08D0+(n)*4))
#define RX_W_FRC                 ((APBADDR)(BFE_base+0x0900))
#define RX_HW_W_RE(n)            ((APBADDR)(BFE_base+0x0A00+(n)*4))
#define RX_HW_W_IM(n)            ((APBADDR)(BFE_base+0x0A20+(n)*4))
/*      RX_BAND_SEL              ((APBADDR)(BFE_base+0x0830)) */
#define RX_NBFIR_COEF(n)         ((APBADDR)(BFE_base+0x0840+(n)*4))
#define RX_FIR_COEF(n)           ((APBADDR)(BFE_base+0x0870+(n)*4))
#define RX_NB_REG                ((APBADDR)(BFE_base+0x08A0))
#define RX_WB_REG                ((APBADDR)(BFE_base+0x08A4))
#define IREST_CON0               ((APBADDR)(BFE_base+0x08A8))
#define RX_MON                   ((APBADDR)(BFE_base+0x0904))
/* --------------------------------------------------------------------------------------------------------------------- */
#define HW_READ_BCIEN()          ((HW_READ(TX_CON0)&(0x1<<11))>>11)
#define HW_WRITE_BCIEN(d)         {HW_WRITE(TX_CON0, (d<<11)|L1D_WIN_TXMOD_TYPE());}
#define HW_WRITE_BFE_RX_RPT_EN(d) {HW_WRITE(RX_CON0, ((HW_READ(RX_CON0)&0xFF)|d));}
   #else
#define BFE_CON0                 ((APBADDR)(BFE_base+0x0000))       /* This register is for control of BFE top           */
#define BFE_CON1                 ((APBADDR)(BFE_base+0x0004))
#define TX_CON0                  ((APBADDR)(BFE_base+0x0400))       /* This register is for control of uplink path       */
                                                                    /* inclusive of control of TX mixed-signal           */
                                                                    /* module and TX path in Baseband Front End          */
#define TX_CON1                  ((APBADDR)(BFE_base+0x0404))       /* This register is for control of TX power and mode switching timing*/
      #if IS_CHIP_MT6250
      #elif IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define TX_CON2                  ((APBADDR)(BFE_base+0x0408))       /*                                                   */
#define TX_PWR0                  ((APBADDR)(BFE_base+0x0410))       /* This register is for control of uplink path power */
#define TX_PWR1                  ((APBADDR)(BFE_base+0x0414))       /* This register is for control of uplink path power */
#define TX_PWR2                  ((APBADDR)(BFE_base+0x0418))       /* This register is for control of uplink path power */
#define TX_PWR3                  ((APBADDR)(BFE_base+0x041C))       /* This register is for control of uplink path power */
#define TX_PWR4                  ((APBADDR)(BFE_base+0x0420))       /* This register is for control of uplink path power */
#define TX_PWR5                  ((APBADDR)(BFE_base+0x0424))       /* This register is for control of uplink path power */
#define TX_DLY_CON               ((APBADDR)(BFE_base+0x0428))       /* This register is for TX AM & PM delay             */
      #else
#define TX_CON2                  ((APBADDR)(BFE_base+0x0408))       /*                                                   */
#define TX_PWR                   ((APBADDR)(BFE_base+0x040C))       /* This register is for control of uplink path power */
      #endif
      #if IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2
#define TX_PH(n)                 ((APBADDR)(BFE_base+0x0434+(n)*4)) /* TX Phase Compensation Register 0~5            */
#define TX_GAIN(n)               ((APBADDR)(BFE_base+0x044C+(n)*4)) /* TX Gain Compensation Register 0~2             */
#define TX_OFFSET(n)             ((APBADDR)(BFE_base+0x0458+(n)*4)) /* TX I/Q Offset Compensation Register 0~5       */
      #endif
#define RX_CON0                  ((APBADDR)(BFE_base+0x0800))       /* [0]loopback mode enable,                          */
                                                                    /* [1]RX IQ SWAP                                     */
                                                                    /* [7]Reset RX filter as slot change                 */
                                                                    /* [8:15]repeat enable                               */
#define RX_CON1                  ((APBADDR)(BFE_base+0x0804))       /* inclusive of control of RX mixed-signal module    */
#define RX_CON2                  ((APBADDR)(BFE_base+0x0808))       /* and RX path in Baseband Front End module          */
#define RX_TYPE_CON0             ((APBADDR)(BFE_base+0x0810))
#define RX_TYPE_CON1             ((APBADDR)(BFE_base+0x0814))
#define RX_TIME_CON0             ((APBADDR)(BFE_base+0x0818))       /* RX DCOC NULL timing setting                       */
#define RX_TIME_CON1             ((APBADDR)(BFE_base+0x081C))       /* RX image rejection factor switch time             */
      #if IS_BFE_RX_TYPE_NB_EN_SUPPORT
#define RX_TIME_CON2             ((APBADDR)(BFE_base+0x0824))       /* RX non-NB DCOC NULL timing setting                */
      #endif
#define RX_ITD                   ((APBADDR)(BFE_base+0x0820))       /* Inter-frame ITD                                   */
#define RX_W_RE(n)               ((APBADDR)(BFE_base+0x08B0+(n)*4))
#define RX_W_IM(n)               ((APBADDR)(BFE_base+0x08D0+(n)*4))
#define RX_W_IMMDT               ((APBADDR)(BFE_base+0x08F0))       /* Immediately assign W for IR algorithm             */
#define RX_HW_W_RE(n)            ((APBADDR)(BFE_base+0x0A00+(n)*4))
#define RX_HW_W_IM(n)            ((APBADDR)(BFE_base+0x0A20+(n)*4))
#define RX_NBFIR_COEF(n)         ((APBADDR)(BFE_base+0x0840+(n)*4))
#define RX_FIR_COEF(n)           ((APBADDR)(BFE_base+0x0870+(n)*4))
      #if IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
      #else
#define RX_STR0                  ((APBADDR)(BFE_base+0x0900))       /* CSD monitor mode EM address                       */
#define RX_STR1                  ((APBADDR)(BFE_base+0x0904))       /* CSD monitor mode EM address                       */
#define RX_MON                   ((APBADDR)(BFE_base+0x0908))
      #endif
#define TX_BUFFER                ((APBADDR)(BFE_base+0x0A44))       /* E-fuse check bit                                  */
/* --------------------------------------------------------------------------------------------------------------------- */
#define HW_READ_BCIEN()          ((HW_READ(TX_CON0)&(0x1<<11)) >>11)
#define HW_WRITE_BCIEN(d)         {HW_WRITE(TX_CON0, (d<<11)|L1D_WIN_TXMOD_TYPE());}
#define HW_WRITE_BFE_RX_RPT_EN(d) {HW_WRITE(RX_CON0, ((HW_READ(RX_CON0)&0xFF)|d));}
   #endif
   #if IS_WC_IMM_MODE_ENABLE
      #if IS_CHIP_MT6251
#define W_IMMDT_REG              RX_W_FRC
      #elif IS_CHIP_MT6256 || IS_CHIP_MT6255 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define W_IMMDT_REG              RX_W_IMMDT
      #endif
   #endif
/* ===================================================================================================================== */
#elif IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* ===================================================================================================================== */
/* for MT6218                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define BFE_CON                  ((APBADDR)(BFE_base+0x0000))           /* Base-band Common Control Register             */
   #if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION
#define BFE_STA0                 ((APBADDR)(BFE_base+0x0004))           /* Base-band Common Status Register 0            */
#define BFE_STA1                 ((APBADDR)(BFE_base+0x0008))           /* Base-band Common Status Register 1            */
   #else
#define BFE_STA                  ((APBADDR)(BFE_base+0x0004))           /* Base-band Common Control Register             */
   #endif
   #if IS_CHIP_MT6276 || IS_CHIP_MT6573 || IS_CHIP_MT6575
#define TX_CFG0                  ((APBADDR)(BFE_base+0x0060))           /* TX Configuration Register                     */
#define TX_CFG1                  ((APBADDR)(BFE_base+0x01DC))           /* TX Configuration Register                     */
#define TX_CON0                  ((APBADDR)(BFE_base+0x0064))           /* TX Configuration Register 2                   */
#define TX_CON1                  ((APBADDR)(BFE_base+0x01E0))           /* TX Configuration Register 2                   */
#define TX_PH(n)                 ((APBADDR)(BFE_base+0x01A0+(n)*4))     /* TX Phase Compensation Register 0~5            */
#define TX_GAIN(n)               ((APBADDR)(BFE_base+0x01B8+(n)*4))     /* TX Gain Compensation Register 0~2             */
#define TX_OFFSET(n)             ((APBADDR)(BFE_base+0x01C4+(n)*4))     /* TX I/Q Offset Compensation Register 0~5       */
#define DCT_CHKSUM               ((APBADDR)(BFE_base+0x015C))           /* TX DCT Checksum                               */
#define DFM_CHKSUM               ((APBADDR)(BFE_base+0x0160))           /* TX DCT Checksum                               */
#define TX_CFG                   TX_CFG0                                /* Alias TX_CFG0 to TX_CFG                       */
#define TX_CON                   TX_CON0                                /* Alias TX_CON0 to TX_CON                       */
   #else
#define TX_CFG                   ((APBADDR)(BFE_base+0x0060))           /* TX Configuration Register                     */
#define TX_CON                   ((APBADDR)(BFE_base+0x0064))           /* TX Configuration Register 2                   */
#define TX_OFF                   ((APBADDR)(BFE_base+0x0068))           /* TX I Channel Offset Compensation Register     */
   #endif

   #if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION
#define RX_BUF_BASE              ((APBADDR)(BFE_base+0x00B4))           /* RXBUF Base Address                            */
#define RX_BUF_ADDR              ((APBADDR)(BFE_base+0x00BC))           /* RXBUF Starting Address                        */
#define RX_BUF_CURRENT_INDEX     ((APBADDR)(BFE_base+0x00B0))           /* RXBUF Current Index                           */
#define CSID_W_0                 ((APBADDR)(BFE_base+0x00D0))           /* RX Wideband Filter CSID 0                     */
#define CSID_W_1                 ((APBADDR)(BFE_base+0x00D4))           /* RX Wideband Filter CSID 1                     */
#define CSID_N_0                 ((APBADDR)(BFE_base+0x00D8))           /* RX Narrowband Filter CSID 0                   */
#define CSID_N_1                 ((APBADDR)(BFE_base+0x00DC))           /* RX Narrowband Filter CSID 1                   */
#define ITD_H_DATA(n)            ((APBADDR)(BFE_base+0x0100+(n)*4))     /* RX HPF ITD Power Register of Window n         */
#define ITD_B_DATA(n)            ((APBADDR)(BFE_base+0x0120+(n)*4))     /* RX BPF ITD Power Register of Window n         */
#define TXBUF_ADDR(n)            ((APBADDR32)(BFE_TXBUF_base+(n)*4))    /* TXBUF Base Address                            */
#define TXBUF_BxWy(x,y)          ((APBADDR32)(BFE_TXBUF_base+(x)*80+(y)*4))/* Word y of Test Burst x                     */
   #endif
#define RX_CFG                   ((APBADDR)(BFE_base+0x0010))           /* RX Configuration Register                     */
   #if IS_CHIP_MT6276 || IS_CHIP_MT6573 || IS_CHIP_MT6575
#define RX_CON0                  ((APBADDR)(BFE_base+0x0014))           /* RX Control Register                           */
#define RX_CON1                  ((APBADDR)(BFE_base+0x01E4))           /* RX Control Register                           */
#define RX_CON                   RX_CON0                                /* Alias RX_CON0 to RX_CON                       */
   #else
#define RX_CON                   ((APBADDR)(BFE_base+0x0014))           /* RX Control Register                           */
   #endif
#define RX_FIR_COEF(n)           ((APBADDR)(BFE_base+0x0020+(n)*4))     /* RX Digital FIR Filter Coefficient Register  n */
   #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define RX_NBFIR_COEF(n)         ((APBADDR)(BFE_base+0x0070+(n)*4))     /* RX Digital FIR Filter Coefficient Register  n */
#define RX_PM_CON                ((APBADDR)(BFE_base+0x0018))           /* RX Interference Detection Power Measurement Control Register */
#define RX_FIR_CSID_CON          ((APBADDR)(BFE_base+0x001c))           /* RX FIR Coefficient Set ID Control Register    */
   #endif
   #if IS_CHIP_MT6252
#define DIGI_RF                  ((APBADDR)(BFE_base+0x00C0))           /* Base-band Common Control Register             */
#define DFM_CHKSUM               ((APBADDR)(BFE_base+0x00C4))           /* Base-band Common Control Register             */
   #endif
#define BCCR                     BFE_CON                                /*                                               */
   #if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION
#define BCSR0                    BFE_STA0                               /*                                               */
#define BCSR1                    BFE_STA1                               /*                                               */
   #else
#define BCSR                     BFE_STA                                /*                                               */
   #endif
#define TX_CNTL                  TX_CON                                 /*                                               */
#define RX_CNTL                  RX_CON                                 /*                                               */
#define TX_OFFI                  TX_OFF                                 /*                                               */
#define TX_OFFQ                  TX_OFF                                 /*                                               */
#define BDLDFCR(n)               RX_FIR_COEF(n)                         /*                                               */
/* --------------------------------------------------------------------------------------------------------------------- */
#define HW_READ_BCIEN()          HW_READ( BCCR );
#define HW_WRITE_BCIEN(d)        HW_WRITE( BCCR, d );
/* ===================================================================================================================== */
#else
/* ===================================================================================================================== */
/* for MT6208                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define BCCR                     ((APBADDR)(BFE_base+0x00D0))           /* Base-band Common Control Register             */
#define BCSR                     ((APBADDR)(BFE_base+0x00D4))           /* Base-band Common Status Register              */
#define TX_CFG                   ((APBADDR)(BFE_base+0x0010))           /* TX Configuration Register                     */
#define TX_CNTL                  ((APBADDR)(BFE_base+0x00C0))           /* TX Configuration Register 2                   */
#define TX_OFFI                  ((APBADDR)(BFE_base+0x0014))           /* TX I Channel Offset Compensation Register     */
#define TX_OFFQ                  ((APBADDR)(BFE_base+0x0018))           /* TX Q Channel Offset Compensation Register     */
#define RX_CFG                   ((APBADDR)(BFE_base+0x0000))           /* RX Configuration Register 0                   */
#define RX_CNTL                  ((APBADDR)(BFE_base+0x0030))           /* RX Configuration Register 1                   */
#define BDLDFCR(n)               ((APBADDR)(BFE_base+0x0040+(n)*4))     /* Base-band DL Digital Filter Coeff. Reigster n */
/* ===================================================================================================================== */
/* for MT6205                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define BFE_CON                  ((APBADDR)(BFE_base+0x00D0))           /* Base-band Common Control Register             */
#define BFE_STA                  ((APBADDR)(BFE_base+0x00D4))           /* Base-band Common Status Register              */
/*      TX_CFG                   ((APBADDR)(BFE_base+0x0010))         *//* TX Configuration Register                     */
#define TX_CON                   ((APBADDR)(BFE_base+0x00C0))           /* TX Configuration Register 2                   */
/*      TX_OFFI                  ((APBADDR)(BFE_base+0x0014))         *//* TX I Channel Offset Compensation Register     */
/*      TX_OFFQ                  ((APBADDR)(BFE_base+0x0018))         *//* TX Q Channel Offset Compensation Register     */
/*      RX_CFG                   ((APBADDR)(BFE_base+0x0000))         *//* RX Configuration Register                     */
#define RX_CON                   ((APBADDR)(BFE_base+0x0030))           /* RX Control Register                           */
#define RX_FIR_COEF(n)           ((APBADDR)(BFE_base+0x0040+(n)*4))     /* RX Digital FIR Filter Coefficient Register  n */
/* --------------------------------------------------------------------------------------------------------------------- */
#define HW_WRITE_BFE_TX_OFFSET_IQ( _ofs_i, _ofs_q ) \
        {  HW_WRITE( TX_OFFI, _ofs_i );   HW_WRITE( TX_OFFQ, _ofs_q );  }
#define HW_READ_BCIEN()          HW_READ( BCCR );
#define HW_WRITE_BCIEN(d)        HW_WRITE( BCCR, d );
/* ===================================================================================================================== */
#endif

/*==============*\
|* ACIF control *|
\*==============*/
#if IS_EDGE_SAIC_CHIP_MT6256_AND_LATTER_VERSION
   #if IS_CHIP_MT6752_MD2
#define DIG_CON0                 ((APBADDR)(ABB_MIXEDSYS_base+0x000))        /* DIG Control Register 0                        */
#define DIG_CON4                 ((APBADDR)(ABB_MIXEDSYS_base+0x010))        /* DIG Control Register 4                        */
#define DIG_CON5                 ((APBADDR)(ABB_MIXEDSYS_base+0x014))        /* DIG Control Register 5                        */
#define DIG_CON90                ((APBADDR)(ABB_MIXEDSYS_base+0x240))        /* DIG Control Register 90                       */
#define DIG_CON91                ((APBADDR)(ABB_MIXEDSYS_base+0x244))        /* DIG Control Register 91                       */
#define DIG_CON93                ((APBADDR)(ABB_MIXEDSYS_base+0x24C))        /* DIG Control Register 93                       */
#define DIG_CON94                ((APBADDR)(ABB_MIXEDSYS_base+0x250))        /* DIG Control Register 94                       */
#define DIG_CON95                ((APBADDR)(ABB_MIXEDSYS_base+0x254))        /* DIG Control Register 95                       */
#define DIG_CON96                ((APBADDR)(ABB_MIXEDSYS_base+0x258))        /* DIG Control Register 96                       */
#define DIG_CON98                ((APBADDR)(ABB_MIXEDSYS_base+0x260))        /* DIG Control Register 98                       */
#define DIG_CON99                ((APBADDR)(ABB_MIXEDSYS_base+0x264))        /* DIG Control Register 99                       */
#define DIG_CON9B                ((APBADDR)(ABB_MIXEDSYS_base+0x26C))        /* DIG Control Register 9B                       */
#define DIG_CON9C                ((APBADDR)(ABB_MIXEDSYS_base+0x270))        /* DIG Control Register 9C                       */
#define DIG_CON9D                ((APBADDR)(ABB_MIXEDSYS_base+0x274))        /* DIG Control Register 9D                       */
#define DIG_CON9E                ((APBADDR)(ABB_MIXEDSYS_base+0x278))        /* DIG Control Register 9E                       */
#define LTEBBRX_CON61            ((APBADDR)(ABB_MIXEDSYS_base+0xB84))        /* LTEBBRX Control Register 61                   */
#define LTEBBRX_CON62            ((APBADDR)(ABB_MIXEDSYS_base+0xB88))        /* LTEBBRX Control Register 62                   */
#define LTEBBRX_CON63            ((APBADDR)(ABB_MIXEDSYS_base+0xB8C))        /* LTEBBRX Control Register 63                   */
#define LTEBBRX_CON71            ((APBADDR)(ABB_MIXEDSYS_base+0xBC4))        /* LTEBBRX Control Register 71                   */
#define LTEBBRX_CON72            ((APBADDR)(ABB_MIXEDSYS_base+0xBC8))        /* LTEBBRX Control Register 72                   */
#define LTEBBRX_CON73            ((APBADDR)(ABB_MIXEDSYS_base+0xBCC))        /* LTEBBRX Control Register 73                   */
#define LTEBBTX_CONA             ((APBADDR)(ABB_MIXEDSYS_base+0x728))        /* LTEBBTX Control Register A                    */
#define TDBBRX_CON41             ((APBADDR)(ABB_MIXEDSYS_base+0x904))        /* TDBBRX Control Register 41                    */
#define TDBBRX_CON42             ((APBADDR)(ABB_MIXEDSYS_base+0x908))        /* TDBBRX Control Register 42                    */
#define TDBBRX_CON43             ((APBADDR)(ABB_MIXEDSYS_base+0x90C))        /* TDBBRX Control Register 43                    */
#define TDBBTX_CONA              ((APBADDR)(ABB_MIXEDSYS_base+0x628))        /* TDBBTX Control Register A                     */
#define ETDAC_CONA               ((APBADDR)(ABB_MIXEDSYS_base+0x528))        /* ETDAC Control Register A                      */
   #elif IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1
#define DIG_CON0                 ((APBADDR)(MIX_ABB_base+0x000))        /* DIG Control Register 0                        */
#define DIG_CON4                 ((APBADDR)(MIX_ABB_base+0x010))        /* DIG Control Register 4                        */
#define DIG_CON5                 ((APBADDR)(MIX_ABB_base+0x014))        /* DIG Control Register 5                        */
#define DIG_CON90                ((APBADDR)(MIX_ABB_base+0x240))        /* DIG Control Register 90                       */
#define DIG_CON91                ((APBADDR)(MIX_ABB_base+0x244))        /* DIG Control Register 91                       */
#define DIG_CON93                ((APBADDR)(MIX_ABB_base+0x24C))        /* DIG Control Register 93                       */
#define DIG_CON94                ((APBADDR)(MIX_ABB_base+0x250))        /* DIG Control Register 94                       */
#define DIG_CON95                ((APBADDR)(MIX_ABB_base+0x254))        /* DIG Control Register 95                       */
#define DIG_CON96                ((APBADDR)(MIX_ABB_base+0x258))        /* DIG Control Register 96                       */
#define DIG_CON98                ((APBADDR)(MIX_ABB_base+0x260))        /* DIG Control Register 98                       */
#define DIG_CON99                ((APBADDR)(MIX_ABB_base+0x264))        /* DIG Control Register 99                       */
#define DIG_CON9B                ((APBADDR)(MIX_ABB_base+0x26C))        /* DIG Control Register 9B                       */
#define DIG_CON9C                ((APBADDR)(MIX_ABB_base+0x270))        /* DIG Control Register 9C                       */
#define DIG_CON9D                ((APBADDR)(MIX_ABB_base+0x274))        /* DIG Control Register 9D                       */
#define DIG_CON9E                ((APBADDR)(MIX_ABB_base+0x278))        /* DIG Control Register 9E                       */
#define LTEBBRX_CON61            ((APBADDR)(MIX_ABB_base+0xB84))        /* LTEBBRX Control Register 61                   */
#define LTEBBRX_CON62            ((APBADDR)(MIX_ABB_base+0xB88))        /* LTEBBRX Control Register 62                   */
#define LTEBBRX_CON63            ((APBADDR)(MIX_ABB_base+0xB8C))        /* LTEBBRX Control Register 63                   */
#define LTEBBRX_CON71            ((APBADDR)(MIX_ABB_base+0xBC4))        /* LTEBBRX Control Register 71                   */
#define LTEBBRX_CON72            ((APBADDR)(MIX_ABB_base+0xBC8))        /* LTEBBRX Control Register 72                   */
#define LTEBBRX_CON73            ((APBADDR)(MIX_ABB_base+0xBCC))        /* LTEBBRX Control Register 73                   */
#define LTEBBTX_CONA             ((APBADDR)(MIX_ABB_base+0x728))        /* LTEBBTX Control Register A                    */
#define TDBBRX_CON41             ((APBADDR)(MIX_ABB_base+0x904))        /* TDBBRX Control Register 41                    */
#define TDBBRX_CON42             ((APBADDR)(MIX_ABB_base+0x908))        /* TDBBRX Control Register 42                    */
#define TDBBRX_CON43             ((APBADDR)(MIX_ABB_base+0x90C))        /* TDBBRX Control Register 43                    */
#define TDBBTX_CONA              ((APBADDR)(MIX_ABB_base+0x628))        /* TDBBTX Control Register A                     */
#define ETDAC_CONA               ((APBADDR)(MIX_ABB_base+0x528))        /* ETDAC Control Register A                      */
   #elif IS_CHIP_MT6290
#define DIG_CON0                 ((APBADDR)(MIX_ABB_base+0x000))        /* DIG Control Register 0                        */
#define DIG_CON4                 ((APBADDR)(MIX_ABB_base+0x010))        /* DIG Control Register 4                        */
#define DIG_CON5                 ((APBADDR)(MIX_ABB_base+0x014))        /* DIG Control Register 5                        */
#define DIG_CON90                ((APBADDR)(MIX_ABB_base+0x240))        /* DIG Control Register 90                       */
#define DIG_CON91                ((APBADDR)(MIX_ABB_base+0x244))        /* DIG Control Register 91                       */
#define DIG_CON93                ((APBADDR)(MIX_ABB_base+0x24C))        /* DIG Control Register 93                       */
#define DIG_CON94                ((APBADDR)(MIX_ABB_base+0x250))        /* DIG Control Register 94                       */
#define DIG_CON95                ((APBADDR)(MIX_ABB_base+0x254))        /* DIG Control Register 95                       */
#define DIG_CON96                ((APBADDR)(MIX_ABB_base+0x258))        /* DIG Control Register 96                       */
#define DIG_CON98                ((APBADDR)(MIX_ABB_base+0x260))        /* DIG Control Register 98                       */
#define DIG_CON99                ((APBADDR)(MIX_ABB_base+0x264))        /* DIG Control Register 99                       */
#define DIG_CON9B                ((APBADDR)(MIX_ABB_base+0x26C))        /* DIG Control Register 9B                       */
#define DIG_CON9C                ((APBADDR)(MIX_ABB_base+0x270))        /* DIG Control Register 9C                       */
#define DIG_CON9D                ((APBADDR)(MIX_ABB_base+0x274))        /* DIG Control Register 9D                       */
#define DIG_CON9E                ((APBADDR)(MIX_ABB_base+0x278))        /* DIG Control Register 9E                       */
#define LTEBBRX_CON2A            ((APBADDR)(MIX_ABB_base+0x9A8))        /* LTEBBRX Control Register 2A                   */
#define LTEBBRX_CON4A            ((APBADDR)(MIX_ABB_base+0xA28))        /* LTEBBRX Control Register 4A                   */
#define LTEBBRX_CON53            ((APBADDR)(MIX_ABB_base+0xA4C))        /* LTEBBRX Control Register 53                   */
#define LTEBBRX_CON54            ((APBADDR)(MIX_ABB_base+0xA50))        /* LTEBBRX Control Register 54                   */
#define LTEBBRX_CON58            ((APBADDR)(MIX_ABB_base+0xA60))        /* LTEBBRX Control Register 58                   */
#define LTEBBRX_CON59            ((APBADDR)(MIX_ABB_base+0xA64))        /* LTEBBRX Control Register 59                   */
#define LTEBBTX_CON4             ((APBADDR)(MIX_ABB_base+0x710))        /* LTEBBTX Control Register 4                    */
#define LTEBBTX_CONA             ((APBADDR)(MIX_ABB_base+0x728))        /* LTEBBTX Control Register A                    */
#define TDBBRX_CON11             ((APBADDR)(MIX_ABB_base+0x844))        /* TDBBRX Control Register 11                    */
#define TDBBRX_CON26             ((APBADDR)(MIX_ABB_base+0x898))        /* TDBBRX Control Register 26                    */
#define TDBBRX_CON27             ((APBADDR)(MIX_ABB_base+0x89C))        /* TDBBRX Control Register 27                    */
#define TDBBTX_CON6              ((APBADDR)(MIX_ABB_base+0x618))        /* TDBBTX Control Register 6                     */
#define ETDAC_CONA               ((APBADDR)(MIX_ABB_base+0x528))        /* ETDAC Control Register A                      */
   #elif IS_CHIP_MT6572
#define BBRX_C_CON0              ((APBADDR)(ABB_MIXEDSYS_base+0x0000))  /* BBRX_C Control Register 0                     */
#define BBRX_C_CON2              ((APBADDR)(ABB_MIXEDSYS_base+0x0008))  /* BBRX_C Control Register 2                     */
#define BBRX_CON0                ((APBADDR)(ABB_MIXEDSYS_base+0x0020))  /* BBRX Control Register 0                       */
#define BBRX_CON1                ((APBADDR)(ABB_MIXEDSYS_base+0x0024))  /* BBRX Control Register 1                       */
#define BBRX_CON6                ((APBADDR)(ABB_MIXEDSYS_base+0x0038))  /* BBRX Control Register 6                       */
#define BBRX_CON9                ((APBADDR)(ABB_MIXEDSYS_base+0x0044))  /* BBRX Control Register 9                       */
#define BBRX_CONA                ((APBADDR)(ABB_MIXEDSYS_base+0x0048))  /* BBRX Control Register A                       */
#define BBRX_CONB                ((APBADDR)(ABB_MIXEDSYS_base+0x004C))  /* BBRX Control Register B                       */
#define BBRX_CONC                ((APBADDR)(ABB_MIXEDSYS_base+0x0050))  /* BBRX Control Register C                       */
#define BBTX_CON0                ((APBADDR)(ABB_MIXEDSYS_base+0x00A0))  /* BBTX Control Register 0                       */
#define BBTX_CON2                ((APBADDR)(ABB_MIXEDSYS_base+0x00A8))  /* BBTX Control Register 2                       */
#define SDAC_CON0                ((APBADDR)(ABB_MIXEDSYS_base+0x00C0))  /* SDAC Control Register 0                       */
#define DIG_CON3                 ((APBADDR)(ABB_MIXEDSYS_base+0x010C))  /* DIG Control Register 3                        */
#define DIG_CONA                 ((APBADDR)(ABB_MIXEDSYS_base+0x0128))  /* DIG Control Register A                        */
#define DIG_CONB                 ((APBADDR)(ABB_MIXEDSYS_base+0x012C))  /* DIG Control Register B                        */
#define DIG_CONC                 ((APBADDR)(ABB_MIXEDSYS_base+0x0130))  /* DIG Control Register C                        */
#define DIG_COND                 ((APBADDR)(ABB_MIXEDSYS_base+0x0134))  /* DIG Control Register D                        */
#define DIG_CONE                 ((APBADDR)(ABB_MIXEDSYS_base+0x0138))  /* DIG Control Register E                        */
#define DIG_CON10                ((APBADDR)(ABB_MIXEDSYS_base+0x0140))  /* DIG Control Register 10                       */
#define DIG_CON12                ((APBADDR)(ABB_MIXEDSYS_base+0x0148))  /* DIG Control Register 12                       */
#define DIG_CON13                ((APBADDR)(ABB_MIXEDSYS_base+0x014C))  /* DIG Control Register 13                       */
#define DIG_CON14                ((APBADDR)(ABB_MIXEDSYS_base+0x0150))  /* DIG Control Register 14                       */
#define DIG_CON15                ((APBADDR)(ABB_MIXEDSYS_base+0x0154))  /* DIG Control Register 15                       */
#define DIG_CON16                ((APBADDR)(ABB_MIXEDSYS_base+0x0158))  /* DIG Control Register 16                       */
#define DIG_CON19                ((APBADDR)(ABB_MIXEDSYS_base+0x0164))  /* DIG Control Register 19                       */
   #elif IS_CHIP_MT6583_MD2
#define BBRX2_CON0               ((APBADDR)(ABB_MIXEDSYS_base+0x0000))  /* BBRX2 Control Register 0                      */
#define BBRX2_CON2               ((APBADDR)(ABB_MIXEDSYS_base+0x0008))  /* BBRX2 Control Register 2                      */
#define BBRX2_2_CON0             ((APBADDR)(ABB_MIXEDSYS_base+0x0060))  /* BBRX2_2 Control Register 0                    */
#define BBRX2_2_CON1             ((APBADDR)(ABB_MIXEDSYS_base+0x0064))  /* BBRX2_2 Control Register 1                    */
#define BBRX2_2_CON2             ((APBADDR)(ABB_MIXEDSYS_base+0x0068))  /* BBRX2_2 Control Register 2                    */
#define BBRX2_2_CON3             ((APBADDR)(ABB_MIXEDSYS_base+0x006C))  /* BBRX2_2 Control Register 3                    */
#define BBRX2_2_CON4             ((APBADDR)(ABB_MIXEDSYS_base+0x0070))  /* BBRX2_2 Control Register 4                    */
#define BBRX2_2_CON6             ((APBADDR)(ABB_MIXEDSYS_base+0x0078))  /* BBRX2_2 Control Register 6                    */
#define BBRX2_2_CON9             ((APBADDR)(ABB_MIXEDSYS_base+0x0084))  /* BBRX2_2 Control Register 9                    */
#define BBRX2_2_CONA             ((APBADDR)(ABB_MIXEDSYS_base+0x0088))  /* BBRX2_2 Control Register A                    */
#define DIG2_CON2                ((APBADDR)(ABB_MIXEDSYS_base+0x0108))  /* DIG2 Control Register 2                       */
#define DIG2_CON4                ((APBADDR)(ABB_MIXEDSYS_base+0x0110))  /* DIG2 Control Register 4                       */
#define DIG2_CON10               ((APBADDR)(ABB_MIXEDSYS_base+0x0140))  /* DIG2 Control Register 10                      */
#define DIG2_CON12               ((APBADDR)(ABB_MIXEDSYS_base+0x0148))  /* DIG2 Control Register 12                      */
#define DIG2_CON13               ((APBADDR)(ABB_MIXEDSYS_base+0x014C))  /* DIG2 Control Register 13                      */
#define DIG2_CON14               ((APBADDR)(ABB_MIXEDSYS_base+0x0150))  /* DIG2 Control Register 14                      */
#define DIG2_CON17               ((APBADDR)(ABB_MIXEDSYS_base+0x015C))  /* DIG2 Control Register 17                      */
#define DIG2_CON18               ((APBADDR)(ABB_MIXEDSYS_base+0x0160))  /* DIG2 Control Register 18                      */
#define DIG2_CON34               ((APBADDR)(ABB_MIXEDSYS_base+0x01D0))  /* DIG2 Control Register 34                      */
#define DIG2_CON35               ((APBADDR)(ABB_MIXEDSYS_base+0x01D4))  /* DIG2 Control Register 34                      */
#define DIG2_CON36               ((APBADDR)(ABB_MIXEDSYS_base+0x01D8))  /* DIG2 Control Register 34                      */
#define DIG2_CON37               ((APBADDR)(ABB_MIXEDSYS_base+0x01DC))  /* DIG2 Control Register 34                      */
#define BBTX2_CON0               ((APBADDR)(ABB_MIXEDSYS_base+0x0300))  /* BBTX2 Control Register 0                      */
#define BBTX2_CON5               ((APBADDR)(ABB_MIXEDSYS_base+0x0314))  /* BBTX2 Control Register 5                      */
#define BBTX2_CON6               ((APBADDR)(ABB_MIXEDSYS_base+0x0318))  /* BBTX2 Control Register 6                      */
#define BBTX2_CON7               ((APBADDR)(ABB_MIXEDSYS_base+0x031C))  /* BBTX2 Control Register 7                      */
#define BBTX2_CON10              ((APBADDR)(ABB_MIXEDSYS_base+0x0340))  /* BBTX2 Control Register 10                     */
#define BBTX2_CON12              ((APBADDR)(ABB_MIXEDSYS_base+0x0348))  /* BBTX2 Control Register 12                     */
   #elif IS_CHIP_MT6583_MD1
#define BBRX1_CON0               ((APBADDR)(ABB_MIXEDSYS_base+0x0000))  /* BBRX1 Control Register 0                      */
#define BBRX1_CON2               ((APBADDR)(ABB_MIXEDSYS_base+0x0008))  /* BBRX1 Control Register 2                      */
#define BBRX1_1_CON0             ((APBADDR)(ABB_MIXEDSYS_base+0x0020))  /* BBRX1_1 Control Register 0                    */
#define BBRX1_1_CON1             ((APBADDR)(ABB_MIXEDSYS_base+0x0024))  /* BBRX1_1 Control Register 1                    */
#define BBRX1_1_CON2             ((APBADDR)(ABB_MIXEDSYS_base+0x0028))  /* BBRX1_1 Control Register 2                    */
#define BBRX1_1_CON4             ((APBADDR)(ABB_MIXEDSYS_base+0x0030))  /* BBRX1_1 Control Register 4                    */
#define BBRX1_1_CON6             ((APBADDR)(ABB_MIXEDSYS_base+0x0038))  /* BBRX1_1 Control Register 6                    */
#define BBRX1_1_CONA             ((APBADDR)(ABB_MIXEDSYS_base+0x0048))  /* BBRX1_1 Control Register A                    */
#define BBRX1_2_CON0             ((APBADDR)(ABB_MIXEDSYS_base+0x0060))  /* BBRX1_2 Control Register 0                    */
#define BBRX1_2_CON2             ((APBADDR)(ABB_MIXEDSYS_base+0x0068))  /* BBRX1_2 Control Register 2                    */
#define BBRX1_2_CON4             ((APBADDR)(ABB_MIXEDSYS_base+0x0070))  /* BBRX1_2 Control Register 4                    */
#define BBRX1_2_CON6             ((APBADDR)(ABB_MIXEDSYS_base+0x0078))  /* BBRX1_2 Control Register 6                    */
#define BBRX1_2_CONA             ((APBADDR)(ABB_MIXEDSYS_base+0x0088))  /* BBRX1_2 Control Register A                    */
#define BBTX_CON0                ((APBADDR)(ABB_MIXEDSYS_base+0x00A0))  /* BBTX Control Register 0                       */
#define BBTX_CON1                ((APBADDR)(ABB_MIXEDSYS_base+0x00A4))  /* BBTX Control Register 1                       */
#define BBTX_CON2                ((APBADDR)(ABB_MIXEDSYS_base+0x00A8))  /* BBTX Control Register 2                       */
#define DIG_CON2                 ((APBADDR)(ABB_MIXEDSYS_base+0x0108))  /* DIG Control Register 2                        */
#define DIG_CON10                ((APBADDR)(ABB_MIXEDSYS_base+0x0140))  /* DIG Control Register 10                       */
#define DIG_CON12                ((APBADDR)(ABB_MIXEDSYS_base+0x0148))  /* DIG Control Register 12                       */
#define DIG_CON13                ((APBADDR)(ABB_MIXEDSYS_base+0x014C))  /* DIG Control Register 13                       */
#define DIG_CON14                ((APBADDR)(ABB_MIXEDSYS_base+0x0150))  /* DIG Control Register 14                       */
#define DIG_CON15                ((APBADDR)(ABB_MIXEDSYS_base+0x0154))  /* DIG Control Register 15                       */
#define DIG_CON16                ((APBADDR)(ABB_MIXEDSYS_base+0x0158))  /* DIG Control Register 16                       */
#define DIG_CON17                ((APBADDR)(ABB_MIXEDSYS_base+0x015C))  /* DIG Control Register 17                       */
#define DIG_CON18                ((APBADDR)(ABB_MIXEDSYS_base+0x0160))  /* DIG Control Register 18                       */
#define DIG_CON19                ((APBADDR)(ABB_MIXEDSYS_base+0x0164))  /* DIG Control Register 19                       */
#define DIG_CON34                ((APBADDR)(ABB_MIXEDSYS_base+0x01D0))  /* DIG Control Register 34                       */
#define DIG_CON35                ((APBADDR)(ABB_MIXEDSYS_base+0x01D4))  /* DIG Control Register 34                       */
#define DIG_CON36                ((APBADDR)(ABB_MIXEDSYS_base+0x01D8))  /* DIG Control Register 34                       */
#define DIG_CON37                ((APBADDR)(ABB_MIXEDSYS_base+0x01DC))  /* DIG Control Register 34                       */
   #elif IS_CHIP_MT6280
   #elif IS_CHIP_MT6250
#define AC_ODS_CON               ((APBADDR)(MIXED_base+0x0000))         /* Analog Chip Output Driving Strength Control Register */
#define ACIF_AC_HW_VER           ((APBADDR)(MIXED_base+0x0004))         /* Mix-signal Chip Version Control               */
#define AFE_AAG_CON              ((APBADDR)(MIXED_base+0x0200))         /* AFE Audio Analog Gain Control Register        */
#define AFE_AAC_CON              ((APBADDR)(MIXED_base+0x0204))         /* AFE Audio Analog-Circuit Control Register     */
#define AFE_AAPDN_CON            ((APBADDR)(MIXED_base+0x0208))         /* AFE Audio Analog Power Down Control Register  */
#define APC_AC_CON               ((APBADDR)(PLL_base+0x0600))           /* APC DAC Analog-Circuit Control Register       */
#define AUX_AC_CON               ((APBADDR)(PLL_base+0x0700))           /* Auxiliary ADC Analog-Circuit Control Register */
   #else
#define AC_ODS_CON               ((APBADDR)(MIXED_base+0x0000))         /* Analog Chip Output Driving Strength Control Register */
#define ACIF_AC_HW_VER           ((APBADDR)(MIXED_base+0x0004))         /* Mix-signal Chip Version Control               */
#define AFE_VAG_CON              ((APBADDR)(MIXED_base+0x0100))         /* AFE Voice Analog Gain Control Register        */
#define AFE_VAC_CON0             ((APBADDR)(MIXED_base+0x0104))         /* AFE Voice Analog-Circuit Control Register 0   */
#define AFE_VAC_CON1             ((APBADDR)(MIXED_base+0x0108))         /* AFE Voice Analog-Circuit Control Register 1   */
#define AFE_VAPDN_CON            ((APBADDR)(MIXED_base+0x010C))         /* AFE Voice Analog Power Down Control Register  */
#define AFE_AAG_CON              ((APBADDR)(MIXED_base+0x0200))         /* AFE Audio Analog Gain Control Register        */
#define AFE_AAC_CON              ((APBADDR)(MIXED_base+0x0204))         /* AFE Audio Analog-Circuit Control Register     */
#define AFE_AAPDN_CON            ((APBADDR)(MIXED_base+0x0208))         /* AFE Audio Analog Power Down Control Register  */
#define APC_AC_CON               ((APBADDR)(PLL_base+0x0600))           /* APC DAC Analog-Circuit Control Register       */
#define AUX_AC_CON               ((APBADDR)(PLL_base+0x0700))           /* Auxiliary ADC Analog-Circuit Control Register */
   #endif
#elif IS_CHIP_MT6276 || IS_CHIP_MT6573 || IS_CHIP_MT6575
#define BBRX_CON0                ((APBADDR)(MIX_ABB_base+0x0A00))       /* BBRX ADC Analog-Circuit Control Register 0    */
#define BBRX_CON1                ((APBADDR)(MIX_ABB_base+0x0A04))       /* BBRX ADC Analog-Circuit Control Register 1    */
#define BBRX_CON2                ((APBADDR)(MIX_ABB_base+0x0A08))       /* BBRX ADC Analog-Circuit Control Register 2    */
#define BBRX_CON3                ((APBADDR)(MIX_ABB_base+0x0A0C))       /* BBRX ADC Analog-Circuit Control Register 3    */
#define BBRX_CON5                ((APBADDR)(MIX_ABB_base+0x0A14))       /* BBRX ADC Analog-Circuit Control Register 5    */
#define BBRX_CON6                ((APBADDR)(MIX_ABB_base+0x0A18))       /* BBRX ADC Analog-Circuit Control Register 6    */
#define BBRX_CON7                ((APBADDR)(MIX_ABB_base+0x0A1C))       /* BBRX ADC Analog-Circuit Control Register 7    */
#define BBRX_CON8                ((APBADDR)(MIX_ABB_base+0x0A20))       /* BBRX ADC Analog-Circuit Control Register 8    */
#define BBRX_CON9                ((APBADDR)(MIX_ABB_base+0x0A24))       /* BBRX ADC Analog-Circuit Control Register 9    */
#define BBRX_CON10               ((APBADDR)(MIX_ABB_base+0x0A28))       /* BBRX ADC Analog-Circuit Control Register 10   */
#define BBRX_CON11               ((APBADDR)(MIX_ABB_base+0x0A2C))       /* BBRX ADC Analog-Circuit Control Register 11   */
#define BBRX_CON12               ((APBADDR)(MIX_ABB_base+0x0A30))       /* BBRX ADC Analog-Circuit Control Register 12   */
#define BBRX_CON13               ((APBADDR)(MIX_ABB_base+0x0A34))       /* BBRX ADC Analog-Circuit Control Register 13   */
#define BBRX_CON14               ((APBADDR)(MIX_ABB_base+0x0A38))       /* BBRX ADC Analog-Circuit Control Register 14   */
#define BBRX_CON15               ((APBADDR)(MIX_ABB_base+0x0A3C))       /* BBRX ADC Analog-Circuit Control Register 15   */
#define BBRX_CON16               ((APBADDR)(MIX_ABB_base+0x0A40))       /* BBRX ADC Analog-Circuit Control Register 16   */
/* --------------------------------------------------------------------------------------------------------------------- */
#define BBTX_CON0                ((APBADDR)(MIX_ABB_base+0x0A80))       /* BBTX DAC Analog-Circuit Control Register 0    */
#define BBTX_CON1                ((APBADDR)(MIX_ABB_base+0x0A84))       /* BBTX DAC Analog-Circuit Control Register 1    */
#define BBTX_CON2                ((APBADDR)(MIX_ABB_base+0x0A88))       /* BBTX DAC Analog-Circuit Control Register 2    */
#define BBTX_CON3                ((APBADDR)(MIX_ABB_base+0x0A8C))       /* BBTX DAC Analog-Circuit Control Register 3    */
#define BBTX_CON4                ((APBADDR)(MIX_ABB_base+0x0A90))       /* BBTX DAC Analog-Circuit Control Register 4    */
#define BBTX_CON5                ((APBADDR)(MIX_ABB_base+0x0A94))       /* BBTX DAC Analog-Circuit Control Register 5    */
#define BBTX_CON6                ((APBADDR)(MIX_ABB_base+0x0A98))       /* BBTX DAC Analog-Circuit Control Register 6    */
#define BBTX_CON7                ((APBADDR)(MIX_ABB_base+0x0A9C))       /* BBTX DAC Analog-Circuit Control Register 7    */
#define BBTX_CON8                ((APBADDR)(MIX_ABB_base+0x0AA0))       /* BBTX DAC Analog-Circuit Control Register 8    */
#define BBTX_CON9                ((APBADDR)(MIX_ABB_base+0x0AA4))       /* BBTX DAC Analog-Circuit Control Register 9    */
#define BBTX_CON10               ((APBADDR)(MIX_ABB_base+0x0AA8))       /* BBTX DAC Analog-Circuit Control Register 10   */
#define BBTX_CON11               ((APBADDR)(MIX_ABB_base+0x0AAC))       /* BBTX DAC Analog-Circuit Control Register 11   */
#define BBTX_CON12               ((APBADDR)(MIX_ABB_base+0x0AB0))       /* BBTX DAC Analog-Circuit Control Register 12   */
#define BBTX_CON13               ((APBADDR)(MIX_ABB_base+0x0AB4))       /* BBTX DAC Analog-Circuit Control Register 12   */
/* --------------------------------------------------------------------------------------------------------------------- */
#define AFC_AC_CON               ((APBADDR)(MIX_ABB_base+0x0CC0))       /* AFC DAC Analog-Circuit Control Register       */
#define CLKSQ_CON                ((APBADDR)(MIX_ABB_base+0x0080))       /* Clock Square Control Register                 */
#define WPLL_CON0                ((APBADDR)(MIX_ABB_base+0x0240))       /* 3G PLL Control Register                       */
#define GPLL_CON0                ((APBADDR)(MIX_ABB_base+0x0280))       /* 2G PLL Control Register                       */
   #if IS_CHIP_MT6575
#define WR_PATH0                 ((APBADDR)(MIX_ABB_base+0x0100))       /* Switch Configuring Path Control Register 0    */
#define WR_PATH1                 ((APBADDR)(MIX_ABB_base+0x0104))       /* Switch Configuring Path Control Register 1    */
   #else
#define WR_PATH0                 ((APBADDR)(MIX_ABB_base+0x0800))       /* Switch Configuring Path Control Register 0    */
#define WR_PATH1                 ((APBADDR)(MIX_ABB_base+0x0804))       /* Switch Configuring Path Control Register 1    */
#define AUDIO_CON10              ((APBADDR)(MIX_ABB_base+0x0928))       /* BBTX/BBRX Control Register                    */
   #endif
   #if IS_CHIP_MT6573
#define PMIC_RESERVE_CON0        ((APBADDR)(MIX_PMU_base+0x0E80))       /* PMU reserved control register                 */
   #endif
#elif IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* ===================================================================================================================== */
/* for MT6218                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define AC_ODS_CON               ((APBADDR)(MIXED_base+0x0000))         /* Analog Chip Output Driving Strength Control Register */
#define ACIF_AC_HW_VER           ((APBADDR)(MIXED_base+0x0004))         /* Mix-signal Chip Version Control               */
#define AFE_VAG_CON              ((APBADDR)(MIXED_base+0x0100))         /* AFE Voice Analog Gain Control Register        */
#define AFE_VAC_CON0             ((APBADDR)(MIXED_base+0x0104))         /* AFE Voice Analog-Circuit Control Register 0   */
#define AFE_VAC_CON1             ((APBADDR)(MIXED_base+0x0108))         /* AFE Voice Analog-Circuit Control Register 1   */
#define AFE_VAPDN_CON            ((APBADDR)(MIXED_base+0x010C))         /* AFE Voice Analog Power Down Control Register  */
#define AFE_AAG_CON              ((APBADDR)(MIXED_base+0x0200))         /* AFE Audio Analog Gain Control Register        */
#define AFE_AAC_CON              ((APBADDR)(MIXED_base+0x0204))         /* AFE Audio Analog-Circuit Control Register     */
#define AFE_AAPDN_CON            ((APBADDR)(MIXED_base+0x0208))         /* AFE Audio Analog Power Down Control Register  */
#define BBRX_AC_CON              ((APBADDR)(MIXED_base+0x0300))         /* BBRX ADC Analog-Circuit Control Register      */
#define BBTX_AC_CON0             ((APBADDR)(MIXED_base+0x0400))         /* BBTX DAC Analog-Circuit Control Register 0    */
#define BBTX_AC_CON1             ((APBADDR)(MIXED_base+0x0404))         /* BBTX DAC Analog-Circuit Control Register 1    */
   #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
#define BBTX_AC_CON2             ((APBADDR)(MIXED_base+0x0408))         /* BBTX DAC Analog-Circuit Control Register 2    */
      #if IS_CHIP_MT6268
#define BBTX_AC_CON3             ((APBADDR)(MIXED_base+0x040C))         /* BBTX DAC Analog-Circuit Control Register 3    */
#define BBTX_AC_CON4             ((APBADDR)(MIXED_base+0x0410))         /* BBTX DAC Analog-Circuit Control Register 4    */
      #endif
   #endif
#define AFC_AC_CON               ((APBADDR)(MIXED_base+0x0500))         /* AFC DAC Analog-Circuit Control Register       */
#define APC_AC_CON               ((APBADDR)(MIXED_base+0x0600))         /* APC DAC Analog-Circuit Control Register       */
#define AUX_AC_CON               ((APBADDR)(MIXED_base+0x0700))         /* Auxiliary ADC Analog-Circuit Control Register */
#define RES_AC_CON(m,n)          ((APBADDR)(MIXED_base+0x0800+(m)*0x100+(n)*4)) /* Reserved                              */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif

/*====================*\
|* TDMA Timer events  *|
\* ===================================================================================================================== */
/* for MT6208                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define TQ_WRAP_IMMEDIATE        ((APBADDR)(TDMA_base+0x0008))          /*     direct Qbit counter reset position [13:0] */
#define DTIRQ                    ((APBADDR)(TDMA_base+0x0010))          /*                   DSP interrupt        [13:0] */
#define CTIRQ2                   ((APBADDR)(TDMA_base+0x0018))          /*                   CPU tdma interrupt 2 [13:0] */
#if IS_NEW_TDMA_CHIP
#define BDLON(n)                 ((APBADDR)(TDMA_base+0x0030+((n)*8)+(((n)/6)*736))) /*         RX window n start [13:0] */
#define BDLOFF(n)                ((APBADDR)(TDMA_base+0x0034+((n)*8)+(((n)/6)*736))) /*         RX window n end   [13:0] */
#define BULON(n)                 ((APBADDR)(TDMA_base+0x0060+((n)*8)+(((n)/4)*720))) /*         TX window n start [13:0] */
#define BULOFF(n)                ((APBADDR)(TDMA_base+0x0064+((n)*8)+(((n)/4)*720))) /*         TX window n end   [13:0] */
#else
#define BDLON(n)                 ((APBADDR)(TDMA_base+0x0030+((n)*8)))               /*         RX window n start [13:0] */
#define BDLOFF(n)                ((APBADDR)(TDMA_base+0x0034+((n)*8)))               /*         RX window n end   [13:0] */
#define BULON(n)                 ((APBADDR)(TDMA_base+0x0060+((n)*8)))               /*         TX window n start [13:0] */
#define BULOFF(n)                ((APBADDR)(TDMA_base+0x0064+((n)*8)))               /*         TX window n end   [13:0] */
#endif
#define APC_EV(n)                ((APBADDR)(TDMA_base+0x0090+((n)*4)))               /*      Power ramp control n [13:0] */

#if IS_CHIP_MT6268T
#define AFC_EV(n)                ((APBADDR)(FPGA_TDMA_base+0x0020+((n)*4)))                      /* AFC control n [13:0] */
#define BSI_EV(n)                ((APBADDR)(FPGA_TDMA_base+0x00B0+((n)*4)))                        /* BSI event n [13:0] */
#define BPI_EV(n)                ((APBADDR)(FPGA_TDMA_base+0x0100+((n)*4)+(((n)/20)*80)-(((n)/40)*80))) /* BPI evntn n   */
#else
   #if IS_AFC_EVENT_SUPPORT_CHIP || IS_HWCG_SUPPORT
#define AFC_EV(n)                ((APBADDR)(TDMA_base+0x0020+((n)*4)))                           /* AFC control n [13:0] */
   #endif
   #if IS_NEW_TDMA_CHIP
#define BSI_EV(n)                ((APBADDR)(TDMA_base+0x00B0+((n)*4)+(((n)/20)*624)+(((n)/36)*16)-(((n)/40)*624)+(((n)/42)*1064)-(((n)/60)*624)-(((n)/72)*16)-(((n)/84)*1064)-(((n)/100)*624)))
   #else
#define BSI_EV(n)                ((APBADDR)(TDMA_base+0x00B0+((n)*4)))                             /* BSI event n [13:0] */
   #endif
#define BPI_EV(n)                ((APBADDR)(TDMA_base+0x0100+((n)*4)+(((n)/20)*80)-(((n)/40)*80))) /* BPI evntn n [13:0] */
#endif

#if !IS_NEW_TDMA_CHIP
#undef  EVENT_ENA               /* The definition of EVENT_ENA (32bits) for new TDMA chip is moved to l1_interface_reg.h */
#define EVENT_ENA(n)             ((APBADDR)(TDMA_base+0x0150+((n)*4)))  /* event enable control n                        */
#endif
#if !IS_NEW_TDMA_CHIP || IS_CHIP_MT6252
#define TQ_OFFSET_CONT           ((APBADDR)(TDMA_base+0x0170))          /* Qbit Timer Control Register                   */
#endif
#define DTX_CONT                 ((APBADDR)(TDMA_base+0x0180))          /* disable BUL0/1/2/3                            */
#define RXINT_CONT               ((APBADDX)(TDMA_base+0x0184))          /* RXINT mode 1 period count & MODE0/1/2/3/4/5 setting */
#define BDL_CONT                 ((APBADDR)(TDMA_base+0x0188))          /* ADC ON to BDL_ON count [15:8] & ADC OFF to BDL_OFF count [7:0] */
#define BUL_CONT1                ((APBADDR)(TDMA_base+0x018C))          /* DAC OFF to BUL_ON count [5:0] & DAC ON  to BUL_OFF count [15:8]*/
#define BUL_CONT2                ((APBADDR)(TDMA_base+0x0190))          /* APCEN to BTXEV hysteresis time in Qbit unit   */
#if IS_TDMA_AD_DA_WINDOW_SUPPORT
#define BDL_CONT2                ((APBADDR)(TDMA_base+0x0604))          /* AD_EN to BRXEN [15:8], BRXFS to BRXEN [5:0]   */
#define BUL_CONT3                ((APBADDR)(TDMA_base+0x0600))          /* DA_EN to BTXEN [15:8], BTXFS to BTXEN [7:0]   */
#endif
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define FB_FLAG                  ((APBADDR)(TDMA_base+0x0194))          /* FB indicator                                  */
#define FB_CLRI                  ((APBADDR)(TDMA_base+0x0198))          /* FB clear of FB indicator                      */
#define TDMA_FB_FLAG             FB_FLAG
#define TDMA_FB_CLRI             FB_CLRI
#endif

#if IS_CHIP_MT6268T || IS_CHIP_MT6268 || IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define GSM2WCDMA_TQCNT          ((APBADDR)(TDMA_base+0x0300))
#define WCDMA2GSM_SYNC1_TQCNT    ((APBADDR)(TDMA_base+0x0304))
#define TDMA_SYNC0               GSM2WCDMA_TQCNT
#define TDMA_SYNC1               TDMA_EVTENA(1)
#endif
#if IS_TDMA_TDD_TIMER_SYNC_SUPPORT
#define GSM2TDD_TQCNT            ((APBADDR)(TDMA_base+0x0700))
#endif
#if IS_CENTRALIZED_SMM_CHIP
#define GSM2FRC_TQCNT            ((APBADDR)(TDMA_base+0x0308))
   #if L1D_AGPS_OLD_REGISTER
   #else
#define GSM2FRC_IMM              ((APBADDR)(TDMA_base+0x030C))          /* MT6276_E1 and MT6573 E1&E2 do NOT have this register */
   #endif
#endif
#if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define TDMA_SW_EVTVAL           ((APBADDR)(TDMA_base+0x03F0))
#define TDMA_BFE_EVTVAL          ((APBADDR)(TDMA_base+0x03F4))
#endif
#if IS_NEW_TDMA_CHIP
#define TDMA_GBL_CON             ((APBADDR)(TDMA_base+0x04F0))
#endif

#if IS_CHIP_MT6268T
#define FPGA_EVENT_ENA(n)        ((APBADDR)(FPGA_TDMA_base+0x0150+((n)*4)))  /* event enable control n                   */
#define TQ_BIAS_CONT2            ((APBADDR)(FPGA_TDMA_base+0x0174))          /* Qbit Timer Biasing Control Register      */
#define FPGA_TDMA_EVTENA(n)      FPGA_EVENT_ENA(n)                      /* event enable control n                        */
#define FPGA_TDMA_REGBIAS        TQ_BIAS_CONT2                          /* Qbit Timer Biasing Control Register           */
#endif

/* ===================================================================================================================== */
/* for MT6205 & MT6218                                                                                                   */
/* --------------------------------------------------------------------------------------------------------------------- */
#define TDMA_TQCNT               TQ_CURRENT_COUNT                       /* read quater bit counter [13:0]                */
#define TDMA_WRAP                TQ_WRAP                                /* latched Qbit counter reset position [13:0]    */
#define TDMA_WRAPIMD             TQ_WRAP_IMMEDIATE                      /*  direct Qbit counter reset position [13:0]    */
#define TDMA_EVTVAL              TQ_EVENT_VALID                         /* event latch position [13:0]                   */
#define TDMA_DTIRQ               DTIRQ                                  /* DSP interrupt        [13:0]                   */
#define TDMA_CTIRQ1              CTIRQ1                                 /* CPU tdma interrupt 1 [13:0]                   */
#define TDMA_CTIRQ2              CTIRQ2                                 /* CPU tdma interrupt 2 [13:0]                   */
#if IS_AFC_EVENT_SUPPORT_CHIP || IS_HWCG_SUPPORT
#define TDMA_AFC(n)              AFC_EV(n)                              /* AFC control n [13:0]                          */
#endif
#define TDMA_BDLON(n)            BDLON(n)                               /* RX window n start [13:0]                      */
#define TDMA_BDLOFF(n)           BDLOFF(n)                              /* RX window n end   [13:0]                      */
#define TDMA_BULON(n)            BULON(n)                               /* TX window n start [13:0]                      */
#define TDMA_BULOFF(n)           BULOFF(n)                              /* TX window n end   [13:0]                      */
#define TDMA_APC(n)              APC_EV(n)                              /* Power ramp control n [13:0]                   */
#define TDMA_BSI(n)              BSI_EV(n)                              /* BSI event n [13:0]                            */
#define TDMA_BPI(n)              BPI_EV(n)                              /* BPI evntn n [13:0]                            */
#define TDMA_EVTENA(n)           EVENT_ENA(n)                           /* event enable control n                        */
#if !IS_NEW_TDMA_CHIP || IS_CHIP_MT6252
#define TDMA_WRAPOFS             TQ_OFFSET_CONT                         /* Qbit Timer Control Register                   */
#endif
#define TDMA_REGBIAS             TQ_BIAS_CONT                           /* Qbit Timer Biasing Control Register           */
#define TDMA_DTXCON              DTX_CONT                               /* disable BUL0/1/2/3                            */
#define TDMA_RXCON               RXINT_CONT                             /* RXINT mode 1 period count & MODE0/1/2/3/4/5 setting */
#define TDMA_BDLCON              BDL_CONT                               /* ADC ON to BDL_ON count [15:8] & ADC OFF to BDL_OFF count [7:0] */
#define TDMA_BULCON1             BUL_CONT1                              /* DAC OFF to BUL_ON count [5:0] & DAC ON  to BUL_OFF count [15:8]*/
#define TDMA_BULCON2             BUL_CONT2                              /* APCEN to BTXEV hysteresis time in Qbit unit   */
#if IS_TDMA_AD_DA_WINDOW_SUPPORT
#define TDMA_BDLCON2             BDL_CONT2                              /* AD_EN to BRXEN [15:8], BRXFS to BRXEN [5:0]   */
#define TDMA_BULCON3             BUL_CONT3                              /* DA_EN to BTXEN [15:8], BTXFS to BTXEN [7:0]   */
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* The definition of TDMA_AUXEVxx is moved to l1_interface_reg.h                                                         */
#elif IS_CHIP_MT6227 || IS_CHIP_MT6225_AND_LATTER_VERSION
#define TDMA_AUXEV0              ((APBADDR)(TDMA_base+0x01C0))          /* Auxiliary ADC event                           */
#define TDMA_AUXEV1              ((APBADDR)(TDMA_base+0x01C4))          /* Auxiliary ADC event                           */
#define TDMA_AUXEVENA            EVENT_ENA(5)
#else
#define TDMA_AUXEV0              ((APBADDR)(TDMA_base+0x01B0))          /* Auxiliary ADC event                           */
#define TDMA_AUXEV1              ((APBADDR)(TDMA_base+0x01B4))          /* Auxiliary ADC event                           */
#define TDMA_AUXEVENA            EVENT_ENA(5)
#endif

#if IS_SOC_CHIP || IS_CHIP_MT6236 || IS_CHIP_MT6276_S01 || IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define TDMA_FHSTR0              ((APBADDR)(TDMA_base+0x0320))
#define TDMA_FHSTR1              ((APBADDR)(TDMA_base+0x0324))
#define TDMA_FHSTR2              ((APBADDR)(TDMA_base+0x0328))
#define TDMA_FHSTR3              ((APBADDR)(TDMA_base+0x032c))
#define TDMA_FHSTR4              ((APBADDR)(TDMA_base+0x0330))
#define TDMA_FHSTR5              ((APBADDR)(TDMA_base+0x0334))
#endif

#if IS_EDGE_SAIC_CHIP_MT6256_AND_LATTER_VERSION
#define TDMA_RD_BSI0             ((APBADDR)(TDMA_base+0x03B0))          /* BSI HW Read event                             */
#endif

#if IS_TXPC_CL_AUXADC_SUPPORT
#define TDMA_AUX_GSM_TX(n)       ((APBADDR)(TDMA_base+0x0408+((n)*4)))  /* Auxiliary ADC power readback event, n = 0~3   */
#define AUX_2GTX_CH              ((APBADDR)(AUXADC_base+0x00A0))        /* [3:0]:   AUXADC input channel number for 2G TX power (Vdet) */
                                                                        /* [15:14]: Both bits are for debugging                        */
#define AUX_2GTX_DAT(n)          ((APBADDR)(AUXADC_base+0x00B0+(4*(n))))/* [11:0]:  2GTX_DAT                                           */
                                                                        /* [12]:    Pending indication bit                             */
#define AUXADC_CON3              ((APBADDR)(AUXADC_base+0x000C))        /* [11]:    PUWAIT_EN, should be set to 0                      */
#endif
/* ===================================================================================================================== */

/*==================*\
|* BSISPI registers *|
\*==================*/
#if IS_BSISPI_SEPARATE_SUPPORT
   #if IS_CHIP_MT6752_MD2
#define BSISPI_CODA_VERSION_RFIC1 ((APBADDR32)(BSISPI_base+0x0000))
#define BSISPI_PORT_PARAM_RFIC1   ((APBADDR32)(BSISPI_base+0x0010))
#define BSISPI_SW_MODE_RFIC1      ((APBADDR32)(BSISPI_base+0x0014))
#define BSISPI_CLSNINT_RFIC1      ((APBADDR32)(BSISPI_base+0x0018))
#define BSISPI_IC0_PARAM1_RFIC1   ((APBADDR32)(BSISPI_base+0x0020))
#define BSISPI_IC0_PARAM2_RFIC1   ((APBADDR32)(BSISPI_base+0x0024))
#define BSISPI_IC1_PARAM1_RFIC1   ((APBADDR32)(BSISPI_base+0x0028))
#define BSISPI_IC1_PARAM2_RFIC1   ((APBADDR32)(BSISPI_base+0x002C))
#define BSISPI_LOG_WPTR_RFIC1     ((APBADDR32)(BSISPI_base+0x0030))
#define BSISPI_SRAM_DELSEL_RFIC1  ((APBADDR32)(BSISPI_base+0x0040))
   #else
#define BSISPI_CODA_VERSION_RFIC1 ((APBADDR32)(BSISPI_base+0x2000))
#define BSISPI_PORT_PARAM_RFIC1   ((APBADDR32)(BSISPI_base+0x2010))
#define BSISPI_SW_MODE_RFIC1      ((APBADDR32)(BSISPI_base+0x2014))
#define BSISPI_CLSNINT_RFIC1      ((APBADDR32)(BSISPI_base+0x2018))
#define BSISPI_IC0_PARAM1_RFIC1   ((APBADDR32)(BSISPI_base+0x2020))
#define BSISPI_IC0_PARAM2_RFIC1   ((APBADDR32)(BSISPI_base+0x2024))
#define BSISPI_IC1_PARAM1_RFIC1   ((APBADDR32)(BSISPI_base+0x2028))
#define BSISPI_IC1_PARAM2_RFIC1   ((APBADDR32)(BSISPI_base+0x202C))
#define BSISPI_LOG_WPTR_RFIC1     ((APBADDR32)(BSISPI_base+0x2030))
#define BSISPI_SRAM_DELSEL_RFIC1  ((APBADDR32)(BSISPI_base+0x2040))
#define BSISPI_CODA_VERSION_RFIC2 ((APBADDR32)(BSISPI_base+0x3000))
#define BSISPI_PORT_PARAM_RFIC2   ((APBADDR32)(BSISPI_base+0x3010))
#define BSISPI_SW_MODE_RFIC2      ((APBADDR32)(BSISPI_base+0x3014))
#define BSISPI_CLSNINT_RFIC2      ((APBADDR32)(BSISPI_base+0x3018))
#define BSISPI_IC0_PARAM1_RFIC2   ((APBADDR32)(BSISPI_base+0x3020))
#define BSISPI_IC0_PARAM2_RFIC2   ((APBADDR32)(BSISPI_base+0x3024))
#define BSISPI_IC1_PARAM1_RFIC2   ((APBADDR32)(BSISPI_base+0x3028))
#define BSISPI_IC1_PARAM2_RFIC2   ((APBADDR32)(BSISPI_base+0x302C))
#define BSISPI_LOG_WPTR_RFIC2     ((APBADDR32)(BSISPI_base+0x3030))
#define BSISPI_SRAM_DELSEL_RFIC2  ((APBADDR32)(BSISPI_base+0x3040))
#define BSISPI_CGEN               ((APBADDR32)(BSISPI_base+0xD204))
   #endif
   #if IS_MIPI_SUPPORT
#define BSISPI_CODA_VERSION_MIPI0 ((APBADDR32)(BSISPI_base+0x5000))
#define BSISPI_PORT_PARAM_MIPI0   ((APBADDR32)(BSISPI_base+0x5010))
#define BSISPI_SW_MODE_MIPI0      ((APBADDR32)(BSISPI_base+0x5014))
#define BSISPI_CLSNINT_MIPI0      ((APBADDR32)(BSISPI_base+0x5018))
#define BSISPI_IC0_PARAM1_MIPI0   ((APBADDR32)(BSISPI_base+0x5020))
#define BSISPI_IC0_PARAM2_MIPI0   ((APBADDR32)(BSISPI_base+0x5024))
#define BSISPI_IC1_PARAM1_MIPI0   ((APBADDR32)(BSISPI_base+0x5028))
#define BSISPI_IC1_PARAM2_MIPI0   ((APBADDR32)(BSISPI_base+0x502C))
#define BSISPI_LOG_WPTR_MIPI0     ((APBADDR32)(BSISPI_base+0x5030))
#define BSISPI_SRAM_DELSEL_MIPI0  ((APBADDR32)(BSISPI_base+0x5040))
#define BSISPI_CODA_VERSION_MIPI1 ((APBADDR32)(BSISPI_base+0x6000))
#define BSISPI_PORT_PARAM_MIPI1   ((APBADDR32)(BSISPI_base+0x6010))
#define BSISPI_SW_MODE_MIPI1      ((APBADDR32)(BSISPI_base+0x6014))
#define BSISPI_CLSNINT_MIPI1      ((APBADDR32)(BSISPI_base+0x6018))
#define BSISPI_IC0_PARAM1_MIPI1   ((APBADDR32)(BSISPI_base+0x6020))
#define BSISPI_IC0_PARAM2_MIPI1   ((APBADDR32)(BSISPI_base+0x6024))
#define BSISPI_IC1_PARAM1_MIPI1   ((APBADDR32)(BSISPI_base+0x6028))
#define BSISPI_IC1_PARAM2_MIPI1   ((APBADDR32)(BSISPI_base+0x602C))
#define BSISPI_LOG_WPTR_MIPI1     ((APBADDR32)(BSISPI_base+0x6030))
#define BSISPI_SRAM_DELSEL_MIPI1  ((APBADDR32)(BSISPI_base+0x6040))
   #endif
#endif

/*================*\
|* BSI  registers *|
\*================*/
#if IS_FPGA_TARGET || IS_CHIP_MT6208
/* ===================================================================================================================== */
/* for MT6208                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define BSI_CON                  ((APBADDR)(BSI_base+0x0000))           /* BSI control register                          */
#define BSI_ENA                  ((APBADDR)(BSI_base+0x0190))           /* BSI event enable register                     */
#define BSI_Dn_CON(n)            ((APBADDR)(BSI_base+0x0004+(12*(n))))  /* data n control                                */
#define BSI_Dn_LSB(n)            ((APBADDR)(BSI_base+0x0008+(12*(n))))  /* data [15: 0]                                  */
#define BSI_Dn_MSB(n)            ((APBADDR)(BSI_base+0x000C+(12*(n))))  /* data [31:16]                                  */
#define BSI_Dn_DAT(n)            BSI_Dn_LSB(n)                          /*                                               */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_CHIP_MT6205_AND_LATTER_VERSION
/* ===================================================================================================================== */
/* for MT6205 and MT6218                                                                                                 */
/* --------------------------------------------------------------------------------------------------------------------- */
#define BSI_CON                  ((APBADDR)  (BSI_base+0x0000))         /* BSI control register                          */
#define BSI_ENA                  ((APBADDR)  (BSI_base+0x0190))         /* BSI event enable register                     */
#define BSI_Dn_CON(n)            ((APBADDR)  (BSI_base+0x0004+(8*(n)))) /* data n control                                */
#define BSI_Dn_DAT(n)            ((APBADDR32)(BSI_base+0x0008+(8*(n)))) /* data [31:0]                                   */
   #if IS_CHIP_MT6227 || IS_CHIP_MT6228 || IS_CHIP_MT6225_AND_LATTER_VERSION
#define BSI_IO_CON               ((APBADDR)  (BSI_base+0x0194))         /* BSI IO mode control register                  */
#define BSI_DOUT                 ((APBADDR)  (BSI_base+0x0198))         /* Software programmed data out                  */
#define BSI_DINT                 ((APBADDR)  (BSI_base+0x019C))         /* input data from RF IC                         */
   #endif
/* --------------------------------------------------------------------------------------------------------------------- */
#endif

#if IS_EDGE_SAIC_CHIP_MT6256_AND_LATTER_VERSION
   #if IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
/* ===================================================================================================================== */
/* for MT6280 & MT6583 & MT6572                                                                                          */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GSM_BSI_CON              ((APBADDR32)(BSI_base+0x0000))         /* BSI control register                          */
#define GSM_BSI_Dn_CON(n)        ((APBADDRBSI)(BSI_base+0x0004+(8*(n))))/* data n control                                */
#define GSM_BSI_Dn_DAT(n)        ((APBADDR32)(BSI_base+0x0008+(8*(n)))) /* data [31:0]                                   */
      #if IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define GSM_BSI_ENA              ((APBADDR32)(BSI_base+0x0B00))         /* BSI event enable register                     */
#define GSM_BSI_ENA1             ((APBADDR32)(BSI_base+0x0B04))         /* BSI event enable register                     */
#define GSM_BSI_ENA2             ((APBADDR32)(BSI_base+0x0B08))         /* BSI event enable register                     */
#define GSM_BSI_ENA3             ((APBADDR32)(BSI_base+0x0B0C))         /* BSI event enable register                     */
#define GSM_BSI_ENA4             ((APBADDR32)(BSI_base+0x0B10))         /* BSI event enable register                     */
#define GSM_BSI_ACTUPT           ((APBADDR)  (BSI_base+0x0B20))         /* BSI active buffer update                      */
#define GSM_BSI_TXDATA_CON       ((APBADDR)  (BSI_base+0x0B24))         /* BSI active buffer update                      */
#define GSM_BSI_PORT_MODE        ((APBADDR)  (BSI_base+0x0B28))         /* BSI active buffer update                      */
         #if IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1
#define GSM_BSI_MODEM_TYPE       ((APBADDR32)(MD_CONFIG_BASE+0x0604))   /* dual mode modem type register                 */
         #elif IS_CHIP_MT6290
#define GSM_BSI_MODEM_TYPE       ((APBADDR32)(BASE_ADDR_MDCFGCTL+0x0058))/* dual mode modem type register                */
         #endif
      #elif IS_CHIP_MT6572
#define GSM_BSI_ENA              ((APBADDR32)(BSI_base+0x06A0))         /* BSI event enable register                     */
#define GSM_BSI_ENA1             ((APBADDR32)(BSI_base+0x06A4))         /* BSI event enable register                     */
#define GSM_BSI_ACTUPT           ((APBADDR)  (BSI_base+0x06A8))         /* BSI active buffer update                      */
#define GSM_BSI_TXDATA_CON       ((APBADDR)  (BSI_base+0x06AC))         /* BSI active buffer update                      */
      #else
#define GSM_BSI_ENA              ((APBADDR32)(BSI_base+0x0500))         /* BSI event enable register                     */
#define GSM_BSI_ENA1             ((APBADDR32)(BSI_base+0x0504))         /* BSI event enable register                     */
#define GSM_BSI_ACTUPT           ((APBADDR)  (BSI_base+0x0508))         /* BSI active buffer update                      */
#define GSM_BSI_TXDATA_CON       ((APBADDR)  (BSI_base+0x050C))         /* BSI active buffer update                      */
      #endif
      #if IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
/* --------------------------------------------------------------------------------------------------------------------- */
/* BSI Read Back Immediated Mode (shared by 2G/3G software)                                                              */
/* --------------------------------------------------------------------------------------------------------------------- */
#define UMTS_BSI_RDCON           ((APBADDR32)(BSI_base+0x1B1C))         /* BSI Timer Trigger Read Back Control           */
#define UMTS_BSI_RDADDR_CON      ((APBADDR)  (BSI_base+0x1B20))         /* control part of the read back address         */
#define UMTS_BSI_RDADDR          ((APBADDR32)(BSI_base+0x1B24))         /* BSI Read Back ADDR                            */
#define UMTS_BSI_RDDAT           ((APBADDR32)(BSI_base+0x1B28))         /* BSI Read Back Data                            */
#define UMTS_BSI_RDDAT_H         ((APBADDR32)(BSI_base+0x1B2C))         /* BSI Read Back Data                            */
/* --------------------------------------------------------------------------------------------------------------------- */
/* BSI Read Back TDMA Event Trigger Mode                                                                                 */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GSM_BSI_RDCON            ((APBADDR32)(BSI_base+0x1B44))         /* BSI Timer Trigger Read Back Control           */
#define GSM_BSI_RDADDR_CON       ((APBADDR)  (BSI_base+0x1B48))         /* control part of the read back address         */
#define GSM_BSI_RDADDR           ((APBADDR32)(BSI_base+0x1B4C))         /* BSI Read Back ADDR                            */
#define GSM_BSI_RDDAT            ((APBADDR32)(BSI_base+0x1B50))         /* BSI Read Back Data                            */
#define GSM_BSI_RDDAT_H          ((APBADDR32)(BSI_base+0x1B54))         /* BSI Read Back Data                            */
#define BSI_IMM_WD_RDY           ((APBADDR32)(BSI_base+0x1B58))         /* BSI IMM Write Status                          */
/* --------------------------------------------------------------------------------------------------------------------- */
      #else
#define UMTS_BSI_IO_CON          ((APBADDR)  (BSI_base+0x0C08))         /* BSI IO mode control register                  */
#define UMTS_BSI_DOUT            ((APBADDR)  (BSI_base+0x0C0C))         /* Software-programmed data out                  */
#define UMTS_BSI_DINT            ((APBADDR)  (BSI_base+0x0C10))         /* Input Data from RF Chip bit0                  */
#define UMTS_BSI_IDLE_CNT        ((APBADDR)  (BSI_base+0x0C30))         /* between two data words between two data words */
/* --------------------------------------------------------------------------------------------------------------------- */
/* BSI Read Back Immediated Mode (shared by 2G/3G software)                                                              */
/* --------------------------------------------------------------------------------------------------------------------- */
#define UMTS_BSI_RDCON           ((APBADDR32)(BSI_base+0x0C40))         /* BSI Timer Trigger Read Back Control           */
#define UMTS_BSI_RDADDR_CON      ((APBADDR)  (BSI_base+0x0C44))         /* control part of the read back address         */
#define UMTS_BSI_RDADDR          ((APBADDR32)(BSI_base+0x0C48))         /* BSI Read Back ADDR                            */
#define UMTS_BSI_RDCS_CON        ((APBADDR)  (BSI_base+0x0C4C))         /* BSI Read Back CS Waveform                     */
#define UMTS_BSI_RDDAT           ((APBADDR32)(BSI_base+0x0C50))         /* BSI Read Back Data                            */
#define UMTS_BSI_RDDAT_H         ((APBADDR32)(BSI_base+0x0C54))         /* BSI Read Back Data                            */
/* --------------------------------------------------------------------------------------------------------------------- */
/* BSI Read Back TDMA Event Trigger Mode                                                                                 */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GSM_BSI_RDCON            ((APBADDR32)(BSI_base+0x0C70))         /* BSI Timer Trigger Read Back Control           */
#define GSM_BSI_RDADDR_CON       ((APBADDR)  (BSI_base+0x0C74))         /* control part of the read back address         */
#define GSM_BSI_RDADDR           ((APBADDR32)(BSI_base+0x0C78))         /* BSI Read Back ADDR                            */
#define GSM_BSI_RDCS_CON         ((APBADDR)  (BSI_base+0x0C7C))         /* BSI Read Back CS Waveform                     */
#define GSM_BSI_RDDAT            ((APBADDR32)(BSI_base+0x0C80))         /* BSI Read Back Data                            */
#define GSM_BSI_RDDAT_H          ((APBADDR32)(BSI_base+0x0C84))         /* BSI Read Back Data                            */
#define BSI_IMM_WD_RDY           ((APBADDR32)(BSI_base+0x0C88))         /* BSI IMM Write Status                          */
/* --------------------------------------------------------------------------------------------------------------------- */
      #endif
      #if IS_MIPI_SUPPORT
/* --------------------------------------------------------------------------------------------------------------------- */
/* BSI MIPI Control                                                                                                      */
/* --------------------------------------------------------------------------------------------------------------------- */
#define UMTS_BSI_MIPI_CON        ((APBADDR)  (BSI_base+0x1BD4))         /* Dual BSI MIPI Control                         */
#define GSM_BSI_MIPI_BURST_EN0   ((APBADDR32)(BSI_base+0x1BD8))         /* GSM BSI MIPI burst write enable               */
#define GSM_BSI_MIPI_BURST_EN1   ((APBADDR32)(BSI_base+0x1BDC))         /* GSM BSI MIPI burst write enable               */
#define GSM_BSI_MIPI_BURST_EN2   ((APBADDR32)(BSI_base+0x1BE0))         /* GSM BSI MIPI burst write enable               */
#define GSM_BSI_MIPI_BURST_EN3   ((APBADDR32)(BSI_base+0x1BE4))         /* GSM BSI MIPI burst write enable               */
#define GSM_BSI_MIPI_BURST_EN4   ((APBADDR32)(BSI_base+0x1BE8))         /* GSM BSI MIPI burst write enable               */
/* --------------------------------------------------------------------------------------------------------------------- */
      #endif
#define BSI_CON                  GSM_BSI_CON
#define BSI_Dn_CON(n)            GSM_BSI_Dn_CON(n)
#define BSI_Dn_DAT(n)            GSM_BSI_Dn_DAT(n)
#define BSI_ENA                  GSM_BSI_ENA
#define BSI_ENA1                 GSM_BSI_ENA1
      #if IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define BSI_ENA2                 GSM_BSI_ENA2
#define BSI_ENA3                 GSM_BSI_ENA3
      #endif
#define BSI_IO_CON               UMTS_BSI_IO_CON
#define BSI_DOUT                 UMTS_BSI_DOUT
#define BSI_DINT                 UMTS_BSI_DINT
#define BSI_IDLE_CNT             UMTS_BSI_IDLE_CNT
#define BSI_RDCON                UMTS_BSI_RDCON
#define BSI_RDADDR_CON           UMTS_BSI_RDADDR_CON
#define BSI_RDADDR               UMTS_BSI_RDADDR
#define BSI_RDCS_CON             UMTS_BSI_RDCS_CON
#define BSI_RDDAT                UMTS_BSI_RDDAT
#define BSI_RDDAT_H              UMTS_BSI_RDDAT_H
#define BSI_TDMA_RDCON           GSM_BSI_RDCON
#define BSI_TDMA_RDADDR_CON      GSM_BSI_RDADDR_CON
#define BSI_TDMA_RDADDR          GSM_BSI_RDADDR
#define BSI_TDMA_RDCS_CON        GSM_BSI_RDCS_CON
#define BSI_TDMA_RDDAT           GSM_BSI_RDDAT
#define BSI_TDMA_RDDAT_H         GSM_BSI_RDDAT_H
#define HW_BSI_RDBACK_EN(d)      HW_WRITE(BSI_TDMA_RDCON, (HW_READ(BSI_TDMA_RDCON)& ~0x8000)|((d&0x1)<<15));
      #if IS_MIPI_SUPPORT
#define BSI_MIPI_CON             UMTS_BSI_MIPI_CON
#define BSI_MIPI_BURST_EN0       GSM_BSI_MIPI_BURST_EN0
#define BSI_MIPI_BURST_EN1       GSM_BSI_MIPI_BURST_EN1
#define BSI_MIPI_BURST_EN2       GSM_BSI_MIPI_BURST_EN2
#define BSI_MIPI_BURST_EN3       GSM_BSI_MIPI_BURST_EN3
#define BSI_MIPI_BURST_EN4       GSM_BSI_MIPI_BURST_EN4
      #endif
/* --------------------------------------------------------------------------------------------------------------------- */
   #elif IS_CHIP_MT6250
/* ===================================================================================================================== */
/* for MT6250                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define BSI_CON                  ((APBADDR32)(BSI_base+0x0000))         /* BSI control register                          */
#define BSI_Dn_CON(n)            ((APBADDR)  (BSI_base+0x0004+(8*(n)))) /* data n control                                */
#define BSI_Dn_DAT(n)            ((APBADDR32)(BSI_base+0x0008+(8*(n)))) /* data [31:0]                                   */
#define BSI_ENA                  ((APBADDR32)(BSI_base+0x0500))         /* BSI event enable register                     */
#define GSM_BSI_ACTUPT           ((APBADDR)  (BSI_base+0x0508))         /* BSI active buffer update                      */
#define GSM_BSI_TXDATA_CON       ((APBADDR)  (BSI_base+0x050C))         /* BSI active buffer update                      */
#define BSI_IO_CON               ((APBADDR)  (BSI_base+0x0C08))         /* BSI IO mode control register                  */
#define BSI_DOUT                 ((APBADDR)  (BSI_base+0x0C0C))         /* Software-programmed data out                  */
#define BSI_DINT                 ((APBADDR)  (BSI_base+0x0C10))         /* Input Data from RF Chip bit0                  */
#define BSI_IDLE_CNT             ((APBADDR)  (BSI_base+0x0C30))         /* between two data words between two data words */
#define BSI_RDCON                ((APBADDR32)(BSI_base+0x0C40))         /* BSI Timer Trigger Read Back Control           */
#define BSI_RDADDR_CON           ((APBADDR)  (BSI_base+0x0C44))         /* control part of the read-back address         */
#define BSI_RDADDR               ((APBADDR32)(BSI_base+0x0C48))         /* BSI Read Back ADDR                            */
#define BSI_RDCS_CON             ((APBADDR32)(BSI_base+0x0C4C))         /* BSI Read Back CS Waveform                     */
#define BSI_RDDAT                ((APBADDR32)(BSI_base+0x0C50))         /* BSI Read Back Data                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define HW_BSI_RDBACK_EN(d)      HW_WRITE(BSI_RDCON, (HW_READ(BSI_RDCON)& ~0x8000)|((d&0x1)<<15));
/* --------------------------------------------------------------------------------------------------------------------- */
   #else
/* ===================================================================================================================== */
/* for MT6256 & MT6251 & MT6255                                                                                          */
/* --------------------------------------------------------------------------------------------------------------------- */
#define BSI_CON                  ((APBADDR)  (BSI_base+0x0000))         /* BSI control register                          */
#define BSI_Dn_CON(n)            ((APBADDR)  (BSI_base+0x0004+(8*(n)))) /* data n control 0~63 for MT6251 & MT6256       */
#define BSI_Dn_DAT(n)            ((APBADDR32)(BSI_base+0x0008+(8*(n)))) /* data [31:0]    0~63 for MT6251 & MT6256       */
#define BSI_ENA                  ((APBADDR)  (BSI_base+0x0204))         /* BSI event enable register                     */
#define BSI_ENA1                 ((APBADDR)  (BSI_base+0x0208))         /* BSI event enable register 1                   */
#define BSI_ENA2                 ((APBADDR)  (BSI_base+0x020C))         /* BSI event enable register 2                   */
#define BSI_IO_CON               ((APBADDR)  (BSI_base+0x0210))         /* BSI IO mode control register                  */
#define BSI_DOUT                 ((APBADDR)  (BSI_base+0x0214))         /* Software-programmed data out                  */
#define BSI_DINT                 ((APBADDR)  (BSI_base+0x0218))         /* Input Data from RF Chip bit0                  */
#define BSI_PAIR_NUM             ((APBADDR)  (BSI_base+0x021C))         /* BSI pair number to be used                    */
#define BSI_RDCON                ((APBADDR32)(BSI_base+0x0220))         /* BSI timer trigger read back control           */
#define BSI_RDADDR_CON           ((APBADDR32)(BSI_base+0x0224))         /* BSI Read back address part                    */
#define BSI_RDDAT                ((APBADDR32)(BSI_base+0x0228))         /* BSI Read back data                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define HW_BSI_RDBACK_EN(d)      HW_WRITE(BSI_RDCON, (HW_READ(BSI_RDCON)& ~0x8000)|((d&0x1)<<15));
/* --------------------------------------------------------------------------------------------------------------------- */
   #endif
#elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H
/* ===================================================================================================================== */
/* for MT6270A                                                                                                           */
/* --------------------------------------------------------------------------------------------------------------------- */
#define BSI_CON                  ((APBADDR32)(BSI_base+0x0000))         /* BSI control register                          */
#define BSI_Dn_CON(n)            ((APBADDR)  (BSI_base+0x0004+(8*(n))+(((n)/44)*928)-(((n)/88)*928)))/*data control 0~103*/
#define BSI_Dn_DAT(n)            ((APBADDR32)(BSI_base+0x0008+(8*(n))+(((n)/44)*928)-(((n)/88)*928)))/*data [31:0]  0~103*/
#define BSI_ENA                  ((APBADDR32)(BSI_base+0x0190))         /* BSI event enable register                     */
#define BSI_ENA1                 ((APBADDR32)(BSI_base+0x0194))         /* BSI event enable register                     */
#define GSM_BSI_ACTUPT           ((APBADDR)  (BSI_base+0x0198))         /* BSI active buffer update                      */
#define GSM_BSI_TXDATA_CON       ((APBADDR)  (BSI_base+0x019C))         /* BSI active buffer update                      */
#define BSI_IO_CON               ((APBADDR)  (BSI_base+0x200+0x0198))   /* BSI IO mode control register                  */
#define BSI_DOUT                 ((APBADDR)  (BSI_base+0x200+0x019C))   /* Software-programmed data out                  */
#define BSI_DINT                 ((APBADDR)  (BSI_base+0x200+0x01A0))   /* Input Data from RF Chip bit0                  */
#define BSI_IDLE_CNT             ((APBADDR)  (BSI_base+0x200+0x01C0))   /* between two data words between two data words */
#define BSI_RDCON                ((APBADDR32)(BSI_base+0x200+0x01D0))   /* BSI Timer Trigger Read Back Control           */
#define BSI_RDADDR_CON           ((APBADDR)  (BSI_base+0x200+0x01D4))   /* control part of the read-back address         */
#define BSI_RDADDR               ((APBADDR32)(BSI_base+0x200+0x01D8))   /* BSI Read Back ADDR                            */
#define BSI_RDCS_CON             ((APBADDR32)(BSI_base+0x200+0x01DC))   /* BSI Read Back CS Waveform                     */
#define BSI_RDDAT                ((APBADDR32)(BSI_base+0x200+0x01E0))   /* BSI Read Back Data                            */
#define BSI_RDDAT_H              ((APBADDR32)(BSI_base+0x200+0x01E4))   /* BSI Read Back Data                            */
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* ===================================================================================================================== */
/* for MT6229                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define BSI_CON                  ((APBADDR)  (BSI_base+0x0000))         /* BSI control register                          */
#define BSI_Dn_CON(n)            ((APBADDR)  (BSI_base+0x0004+(8*(n)))) /* data n control 0~43 for MT6268T and 0~39  for others */
#define BSI_Dn_DAT(n)            ((APBADDR32)(BSI_base+0x0008+(8*(n)))) /* data [31:0]    0~43 for MT6268T and 0~39  for others */
   #if IS_CHIP_MT6268T || IS_CHIP_MT6268
#define BSI_ENA                  ((APBADDR32)(BSI_base+0x0190))         /* BSI event enable register                     */
#define BSI_IO_CON               ((APBADDR)  (BSI_base+0x200+0x0198))   /* BSI IO mode control register                  */
#define BSI_DOUT                 ((APBADDR)  (BSI_base+0x200+0x019C))   /* Software-programmed data out                  */
#define BSI_DINT                 ((APBADDR)  (BSI_base+0x200+0x01A0))   /* Input Data from RF Chip bit0                  */
#define BSI_PAIR_NUM             ((APBADDR)  (BSI_base+0x200+0x01A4))   /* BSI pair number to be used                    */
   #else
#define BSI_ENA                  ((APBADDR)  (BSI_base+0x0190))         /* BSI event enable register                     */
#define BSI_ENA1                 ((APBADDR)  (BSI_base+0x0194))         /* BSI event enable register 1                   */
#define BSI_Dn_CON_2(n)          ((APBADDR)  (BSI_base+0x0144+(16*(n))))/* data n control 40~44                          */
#define BSI_Dn_DAT_2(n)          ((APBADDR32)(BSI_base+0x0150+( 8*(n))))/* data [31:0]    40~44                          */
#define BSI_D43_DAT_0            ((APBADDR32)(BSI_base+0x0180))         /* data register LSB 32 bits                     */
#define BSI_IO_CON               ((APBADDR)  (BSI_base+0x0198))         /* BSI IO mode control register                  */
#define BSI_DOUT                 ((APBADDR)  (BSI_base+0x019C))         /* Software-programmed data out                  */
#define BSI_DINT                 ((APBADDR)  (BSI_base+0x01A0))         /* Input Data from RF Chip bit0                  */
#define BSI_PAIR_NUM             ((APBADDR)  (BSI_base+0x01A4))         /* BSI pair number to be used                    */
   #endif
/* --------------------------------------------------------------------------------------------------------------------- */
#endif

/*================*\
|* BPI registers  *|
\* ===================================================================================================================== */
/* for MT6208                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#if IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
/* BPI control register is split into two parts:              *
 *   a) BPI immediate mode setting is moved to GSM_BPI_ACTUPT *
 *   b) BPI driving capability setting is moved to            *
 *      GPIO_DRV2[15:8] and GPIO_DRV3[13:0] (MT6280)          *
 *      GPIO_DRV_CFG0[9:2]                  (MT6572)          */
#else
#define BPI_CTRL                 ((APBADDR)   (BPI_base+0x0000))          /* BPI control register                        */
#endif
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_CHIP_MT6256 || IS_CHIP_MT6255 || IS_CHIP_MT6250
#define BPI_AST                  ((APBADDR)   (BPI_base+0x00C0))          /* BPI AST Mode                                */
#define BPI_AST_CON              ((APBADDR)   (BPI_base+0x00C4))          /* BPI AST Control Register                    */
#define BPI_AX_SEL               ((APBADDR)   (BPI_base+0x00C8))          /* BPI AST Control Register                    */
#define BPI_MASK                 ((APBADDR32) (BPI_base+0x00F4))          /* BPI Mask Register                           */
#define BPI_VALUE                ((APBADDR32) (BPI_base+0x00F8))          /* BPI Replace Value                           */
#define BPI_EN                   ((APBADDR)   (BPI_base+/*0x0080*/0x00B0))/* BPI event enable register                   */
#define BPI_EN1                  ((APBADDR)   (BPI_base+/*0x0084*/0x00B4))/* BPI event enable register                   */
#define BPI_EN2                  ((APBADDR)   (BPI_base+/*0x0084*/0x00B8))/* BPI event enable register                   */
   #elif IS_CHIP_MT6268T || IS_CHIP_MT6268H || IS_CHIP_MT6268 || IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define BPI_EN                   ((APBADDR32) (BPI_base+/*0x0080*/0x00B0))/* BPI event enable register                   */
#define BPI_EN1                  ((APBADDR)   (BPI_base+/*0x0084*/0x00B4))/* BPI event enable register                   */
#define BPI_MASK                 ((APBADDRBPI)(BPI_base+/*0x0080*/0x00B8))/* Mask for GSM Bus shared output              */
      #if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define GSM_BPI_ACTUPT           ((APBADDR)   (BPI_base+/*0x0080*/0x00BC))/* Immediate update the active buffer          */
      #endif
   #else
#define BPI_EN                   ((APBADDR)   (BPI_base+/*0x0080*/0x00B0))/* BPI event enable register                   */
#define BPI_EN1                  ((APBADDR)   (BPI_base+/*0x0084*/0x00B4))/* BPI event enable register                   */
#define BPI_EN2                  ((APBADDR)   (BPI_base+/*0x0084*/0x00B8))/* BPI event enable register                   */
   #endif
#elif IS_CHIP_MT6227 || IS_CHIP_MT6225_AND_LATTER_VERSION
#define BPI_EN                   ((APBADDR)   (BPI_base+0x0094))          /* BPI event enable register                   */
#define BPI_EN1                  ((APBADDR)   (BPI_base+0x0098))          /* BPI event enable register                   */
#else
#define BPI_EN                   ((APBADDR)   (BPI_base+0x0060))          /* BPI event enable register                   */
#define BPI_EN1                  ((APBADDR)   (BPI_base+0x0064))          /* BPI event enable register                   */
#endif
#if IS_BPI_DATA_32_BIT_CHIP
#define BPI_V(n)                 ((APBADDR32) (BPI_base+0x0004+((n)*4)))  /* data for event n                            */
#else
#define BPI_V(n)                 ((APBADDR)   (BPI_base+0x0004+((n)*4)))  /* data for event n                            */
#endif
/* ===================================================================================================================== */
/* for MT6205 & MT6218                                                                                                   */
/* --------------------------------------------------------------------------------------------------------------------- */
#if IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#else
#define BPI_CON                  BPI_CTRL                               /* BPI control register                          */
#endif
#define BPI_ENA                  BPI_EN                                 /* BPI event enable register                     */
#define BPI_ENA1                 BPI_EN1                                /* BPI event enable register                     */
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION && !(IS_CHIP_MT6268T || IS_CHIP_MT6268H || IS_CHIP_MT6268 || IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION)
#define BPI_ENA2                 BPI_EN2                                /* BPI event enable register                     */
#endif
#define BPI_DAT(n)               BPI_V(n)                               /* data for event n                              */
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define BPI_DATIMM               ((APBADDRBPI)(BPI_base+/*0x007C*/0x00AC)) /* Force change the value of BPI output       */
#elif IS_CHIP_MT6227 || IS_CHIP_MT6225_AND_LATTER_VERSION
#define BPI_DATIMM               ((APBADDR)(BPI_base+0x0090))           /* Force change the value of BPI output          */
#else
#define BPI_DATIMM               ((APBADDR)(BPI_base+0x005C))           /* Force change the value of BPI output          */
#endif
/* ===================================================================================================================== */

#if IS_AFC_EVENT_SUPPORT_CHIP
   #if IS_AST_B2S_SUPPORT
/*================*\
|* AFC  registers *|
\* ===================================================================================================================== */
/* for MT6208                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define AFC_CTRL                 ((APBADDR)  (BPI_base+0x00E4))         /* AFC control register                          */
#define AFC_DATA(n)              ((APBADDR)  (BPI_base+0x00CC+((n)*4))) /* AFC data n [9:0]                              */
/* ===================================================================================================================== */
/* for MT6205 & MT6218                                                                                                   */
/* --------------------------------------------------------------------------------------------------------------------- */
#define AFC_CON                  AFC_CTRL                               /* AFC control register                          */
#define AFC_DAT(n)               AFC_DATA(n)                            /* AFC data n [9:0]                              */
#define AFC_BUF(n)               AFC_DATA(n)                            /* AFC data n [9:0]                              */
#define AFC_DAC                  ((APBADDR)  (BPI_base+0x00E8))         /* AFC power up period                           */
#define AFC_MASK                 ((APBADDR32)(BPI_base+0x00EC))         /* AFC Mask Register                             */
#define AFC_VALUE                ((APBADDR32)(BPI_base+0x00F0))         /* AFC Replace Value Register                    */
/* --------------------------------------------------------------------------------------------------------------------- */
   #else
/*================*\
|* AFC  registers *|
\* ===================================================================================================================== */
/* for MT6208                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define AFC_CTRL                 ((APBADDR)  (AFC_base+0x0000))         /* AFC control register                          */
#define AFC_DATA(n)              ((APBADDR)  (AFC_base+0x0004+((n)*4))) /* AFC data n [9:0]                              */
/* ===================================================================================================================== */
/* for MT6205 & MT6218                                                                                                   */
/* --------------------------------------------------------------------------------------------------------------------- */
#define AFC_CON                  AFC_CTRL                               /* AFC control register                          */
#define AFC_DAT(n)               AFC_DATA(n)                            /* AFC data n [9:0]                              */
#define AFC_PUPER                ((APBADDR)  (AFC_base+0x0014))         /* AFC power up period                           */
#define AFC_CALIBIAS             ((APBADDR)  (AFC_base+0x0028))         /* AFC programmable bias current                 */
      #if IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
         #if defined(L1_SIM)
#define AFC_UMTS_CON             ((APBADDR32)(AFC_base+0x0018))         /* UMTS AFC Control Register                     */
         #elif IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1
#define AFC_UMTS_CON             ((APBADDR)  (AFC3G_base+0x0018))       /* UMTS AFC Control Register                     */
         #else
#define AFC_UMTS_CON             ((APBADDR)  (AFC_base+0x0018))         /* UMTS AFC Control Register                     */
         #endif
#define AFC_UMTS_IM_DAT          ((APBADDR)  (AFC_base+0x001C))         /* UMTS AFC Immediate Data Register              */
#define AFC_FINAL_DAC            ((APBADDR)  (AFC_base+0x0020))         /* Final AFC Output Register. (updated by 2G or 3G events) */
         #if IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define AFC_BSI_SHIFT            ((APBADDR)  (BSI_base+0x1BC0))         /* AFC DAC value field shift                     */
#define AFC_MASK                 ((APBADDR32)(BSI_base+0x1BC4))         /* AFC replace mask                              */
#define AFC_VALUE                ((APBADDR32)(BSI_base+0x1BC8))         /* AFC replace value                             */
#define AFC_BSI_CON              ((APBADDR)  (BSI_base+0x1BCC))         /* Control part of AFC data register             */
         #else
#define AFC_BSI_SHIFT            ((APBADDR)  (BSI_base+0x0CD0))         /* AFC DAC value field shift                     */
#define AFC_MASK                 ((APBADDR32)(BSI_base+0x0CD4))         /* AFC replace mask                              */
#define AFC_VALUE                ((APBADDR32)(BSI_base+0x0CD8))         /* AFC replace value                             */
#define AFC_BSI_CON              ((APBADDR)  (BSI_base+0x0CDC))         /* Control part of AFC data register             */
         #endif
      #elif IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION
#define AFC_UMTS_CON             ((APBADDR)  (AFC_base+0x0018))         /* UMTS AFC Control Register                     */
#define AFC_UMTS_IM_DAT          ((APBADDR)  (AFC_base+0x001C))         /* UMTS AFC Immediate Data Register              */
#define AFC_FINAL_DAC            ((APBADDR)  (AFC_base+0x0020))         /* Final AFC Output Register. (updated by 2G or 3G events) */
#define AFC_BSI_SHIFT            ((APBADDR)  (BSI_base+0x200+0x0210))   /* AFC DAC value field shift                     */
#define AFC_MASK                 ((APBADDR32)(BSI_base+0x200+0x0214))   /* AFC replace mask                              */
#define AFC_VALUE                ((APBADDR32)(BSI_base+0x200+0x0218))   /* AFC replace value                             */
#define AFC_BSI_CON              ((APBADDR)  (BSI_base+0x200+0x021C))   /* Control part of AFC data register             */
      #endif
/* --------------------------------------------------------------------------------------------------------------------- */
   #endif
#endif

/*====================*\
|* APC data registers *|
\*====================*/
#if IS_FPGA_TARGET || IS_CHIP_MT6208
/* ===================================================================================================================== */
/* for MT6208                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define APC_A(n)                 ((APBADDR)(APC_base+0x0000+((n)*4)))   /* n'th word of APC_A                            */
#define APC_B(n)                 ((APBADDR)(APC_base+0x0040+((n)*4)))   /* n'th word of APC_B                            */
#define APC_C(n)                 ((APBADDR)(APC_base+0x0080+((n)*4)))   /* n'th word of APC_C                            */
#define APC_D(n)                 ((APBADDR)(APC_base+0x00C0+((n)*4)))   /* n'th word of APC_D                            */
#define APC_E(n)                 ((APBADDR)(APC_base+0x0100+((n)*4)))   /* n'th word of APC_E                            */
#define APC(m, n)                ((APBADDR)(APC_base+0x0000+((((m)*16)+(n))*4))) /* n'th word of APC_EVm                 */
#define APC_CTRL                 ((APBADDR)(APC_base+0x01C0))           /* APC control register                          */
#define APC_CON                  APC_CTRL                               /*                                               */
#define APC_OFFSET               ((APBADDR)(APC_base+0x01C4))           /* APC offset register                           */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_CHIP_MT6205
/* ===================================================================================================================== */
/* for MT6205                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define APC_RAMPUP(n)            ((APBADDR32)(APC_base+0x0000+((n)*4))) /* Rampup Profile #n                             */
#define APC_RAMPDN(n)            ((APBADDR32)(APC_base+0x0010+((n)*4))) /* Rampdown Profile #n                           */
#define APC_RAMPUP0              APC_RAMPUP(0)                          /* Rampup Profile #0                             */
#define APC_RAMPUP1              APC_RAMPUP(1)                          /* Rampup Profile #1                             */
#define APC_RAMPUP2              APC_RAMPUP(2)                          /* Rampup Profile #2                             */
#define APC_RAMPUP3              APC_RAMPUP(3)                          /* Rampup Profile #3                             */
#define APC_RAMPDN0              APC_RAMPDN(0)                          /* Rampdown Profile #0                           */
#define APC_RAMPDN1              APC_RAMPDN(1)                          /* Rampdown Profile #1                           */
#define APC_RAMPDN2              APC_RAMPDN(2)                          /* Rampdown Profile #2                           */
#define APC_RAMPDN3              APC_RAMPDN(3)                          /* Rampdown Profile #3                           */
#define APC_SCALE                ((APBADDR)(APC_base+0x01CC))           /* APC scalling factor                           */
#define APC_CTRL                 ((APBADDR)(APC_base+0x01C0))           /* APC control register                          */
#define APC_CON                  APC_CTRL                               /*                                               */
#define APC_OFFSET               ((APBADDR)(APC_base+0x01C4))           /* APC offset register                           */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* ===================================================================================================================== */
/* for MT6218                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define APC_RAMP(n,k)            ((APBADDR32)(APC_base+0x0000+((n)*32)+((k)*4))) /* Rampup Profile #n                    */
#define APC_SCALL(n)             ((APBADDR)(APC_base+0x0010+((n)*32)))  /* Rampdown Profile #n                           */
#define APC_SCALR(n)             ((APBADDR)(APC_base+0x0014+((n)*32)))  /* Rampdown Profile #n                           */
#define APC_OFS(n)               ((APBADDR)(APC_base+0x0018+((n)*32)))  /* Rampdown Profile #n                           */
   #if IS_CHIP_SER_AND_LATTER(CHIP_ID_MT6276) || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define APC_CTRL                 ((APBADDR)(APC_base+0x0100))           /* APC control register                          */
   #else
#define APC_CTRL                 ((APBADDR)(APC_base+0x00E0))           /* APC control register                          */
   #endif
#define APC_CON                  APC_CTRL                               /*                                               */
#define APC_OFFSET               APC_OFS(0)                             /* APC offset register                           */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif

/*====================*\
|*  SM data registers *|
\* ===================================================================================================================== */
/* for MT6208 & MT6205 & MT6218                                                                                          */
/* --------------------------------------------------------------------------------------------------------------------- */
#if IS_CENTRALIZED_SMM_CHIP
/* --------------------------------------------------------------------------------------------------------------------- */
   #if IS_CHIP_MT6276 || IS_CHIP_MT6573 || IS_CHIP_MT6575 || IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572
#define SM_CON                   ((APBADDR)  (SM_base+0x0000))          /* 2G Sleep Control register                     */
#define SM_PROT_TIME             ((APBADDR)  (SM_base+0x0004))          /* SW Protection Time after trigger Pause Start  */
#define SM_PAUSE_TIME            ((APBADDR32)(SM_base+0x0008))          /* 2G Sleep Duration                             */
#define SM_STA                   ((APBADDR)  (SM_base+0x000C))          /* 2G Sleep Controller Status                    */
#define SM_CNF                   ((APBADDR)  (SM_base+0x0010))          /* 2G Sleep Controller Interrupt Configuration   */
#define SM_SW_WAKE_CON           ((APBADDR)  (SM_base+0x0014))          /* Software Interrupt Control                    */
#define SM_SLEEP_WRAP            ((APBADDR)  (SM_base+0x0018))          /* Sleep Wrap Time                               */
#define SM_TQ_FRAC               ((APBADDR32)(SM_base+0x001C))          /* Sleep TQ Fraction                             */
#define SM_TQCOUNT_F32K_INT      ((APBADDR)  (SM_base+0x0020))          /* Sleep TQ Counter (Integer  part)              */
#define SM_TQCOUNT_F32K_FRAC     ((APBADDR32)(SM_base+0x0024))          /* Sleep TQ Counter (Fraction part)              */
#define SM_FRM_COUNT_F32K        ((APBADDR)  (SM_base+0x0028))          /* Sleep Frame Counter                           */
#define SM_QBIT_START            ((APBADDR)  (SM_base+0x002C))          /* QBIT Start at Entry of Sleep Mode             */
#define SM_FRM_QBIT_START        ((APBADDR)  (SM_base+0x0030))          /* QBIT Start Close to Frame Boundary            */
#define SM_INT_QBIT_START        ((APBADDR)  (SM_base+0x0034))          /* QBIT_32k     while SW/HW interrupts at sleep  */
#define SM_TQINIT                ((APBADDR)  (SM_base+0x0038))          /* Jump position of the first frame after sleep  */
#define SM_FINAL_PAUSE_DURATION  ((APBADDR32)(SM_base+0x003C))          /* 2G Final Pause Duration                       */
#define SM_PRESLP_CNT            ((APBADDR)  (SM_base+0x0040))          /* Pre-Sleep Counter                             */
#define SM_INT_FRM_START         ((APBADDR)  (SM_base+0x0044))          /* Frame Count  while SW/HW interrupts at sleep  */
#define SM_FRM_F32K_START        ((APBADDR32)(SM_base+0x0048))          /* F32K Counter Start Close to Frame Boundary    */
#define SM_INT_F32K_START        ((APBADDR32)(SM_base+0x004C))          /* F32K Counter while SW/HW interrupts at sleep  */
#define SM_DEBUG                 ((APBADDR)  (SM_base+0x00F0))          /* Sleep Debug Function                          */
/* --------------------------------------------------------------------------------------------------------------------- */
      #if IS_CHIP_MT6276 || IS_CHIP_MT6573 || IS_CHIP_MT6575
#define RM_CLK_SETTLE            ((APBADDR32)(TOPSM_base+0x0000))       /* Resource Manager Clock Settling Setting       */
#define RM_TMRPWR_SETTLE         ((APBADDR32)(TOPSM_base+0x0004))       /* Resource Manager Power Settling Setting       */
#define RM_TMR_TRG0              ((APBADDR32)(TOPSM_base+0x0010))       /* Resource Manager Timer Cross Trigger Setting  */
#define RM_TMR_PWR0              ((APBADDR32)(TOPSM_base+0x0014))       /* Resource Manager SUBSYS Power Setting         */
#define RM_PERI_CON              ((APBADDR32)(TOPSM_base+0x0030))       /* Resource Manager Peripheral Pause Control     */
#define RM_TMR_SSTA              ((APBADDR32)(TOPSM_base+0x0040))       /* Resource Manager Timer Sleep Control State    */
#define TOPSM_DBG                ((APBADDR32)(TOPSM_base+0x0050))       /* Sleep Manager Debug Control                   */
#define FRC_F32K_FM              ((APBADDR32)(TOPSM_base+0x0084))       /* F32K_CK Frequency Measurement Value           */
#define FRC_VAL_R                ((APBADDR32)(TOPSM_base+0x0088))       /* Free Running Counter Current Value            */
         #if L1D_AGPS_OLD_REGISTER
#define FRC_SYNC0                ((APBADDR32)(TOPSM_base+0x008C))       /* GPS strobe timing of Free Running Counter     */
         #else
#define FRC_SYNC1_STA            ((APBADDR32)(TOPSM_base+0x0070))       /* TQ_CNT to FRC sync status                     */
#define GPS_SYNC_CON0            ((APBADDR32)(TOPSM_base+0x0300))       /* GPS strobe timing value of Free Running Counter  */
#define GPS_SYNC_CON1            ((APBADDR32)(TOPSM_base+0x0304))       /* GPS strobe timing ENABLE of Free Running Counter */
         #endif
#define FRC_SYNC_1L              ((APBADDR32)(TOPSM_base+0x0090))       /* Free Running Counter sync result in 1/26 us   */
#define FRC_SYNC_1H              ((APBADDR32)(TOPSM_base+0x0094))       /* Free Running Counter sync result in us        */
#define RM_PWR_CON(n)            ((APBADDR)  (TOPSM_base+0x0800+(n)*4)) /* Power Control Register n                      */
#define RM_PWR_STA               ((APBADDR32)(TOPSM_base+0x0820))       /* Power Status Register                         */
#define RM_PLL_MASK              ((APBADDR)  (TOPSM_base+0x0830))       /* Power Status Register                         */
#define RM_PWR_CON0              RM_PWR_CON(0)                          /* MD2GSYS Power Control Register                */
#define RM_PWR_CON1              RM_PWR_CON(1)                          /* HSPASYS Power Control Register                */
/* --------------------------------------------------------------------------------------------------------------------- */
      #else /* MT6250 || MT6280 */
         #if IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define MCU_TOPSM_base           TOPSM_base
            #if IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1
#define MODEM2G_TOPSM_base       SLP_2G_CTRL_base
            #else
#define MODEM2G_TOPSM_base       SLP_CTRL_base
            #endif
         #endif
/* ----------------------------------------------------------------------------------------------------------------------------- */
         #if IS_CHIP_MT6290
#define RM_CLK_SETTLE            ((APBADDR32)(MCU_TOPSM_base+0x0004))           /* Resource Manager Clock Settling Setting       */
#define RM_TMR_TRG0              ((APBADDR32)(MCU_TOPSM_base+0x0010))           /* Resource Manager Timer Cross Trigger Setting  */
#define RM_TMR_TRG1              ((APBADDR32)(MCU_TOPSM_base+0x0014))           /* Resource Manager Timer Cross Trigger Setting  */
#define RM_TMR_PWR0              ((APBADDR32)(MCU_TOPSM_base+0x0018))           /* Resource Manager SUBSYS Power Setting         */
#define RM_TMR_PWR1              ((APBADDR32)(MCU_TOPSM_base+0x001C))           /* Resource Manager SUBSYS Power Setting         */
#define RM_PERI_CON              ((APBADDR32)(MCU_TOPSM_base+0x0030))           /* Resource Manager Peripheral Pause Control     */
#define RM_TMR_SSTA              ((APBADDR32)(MCU_TOPSM_base+0x0040))           /* Resource Manager Timer Sleep Control State    */
#define TOPSM_DBG                ((APBADDR32)(MCU_TOPSM_base+0x0050))           /* Sleep Manager Debug Control                   */
#define FRC_F32K_FM              ((APBADDR32)(MCU_TOPSM_base+0x0084))           /* F32K_CK Frequency Measurement Value           */
#define FRC_VAL_R                ((APBADDR32)(MCU_TOPSM_base+0x0088))           /* Free Running Counter Current Value            */
#define FRC_SYNC_VAL_2G_H        ((APBADDR32)(MCU_TOPSM_base+0x0090))           /* Free Running Counter sync result in us        */
#define FRC_SYNC_VAL_2G_MISC     ((APBADDR32)(MCU_TOPSM_base+0x0094))           /* Free Running Counter sync result in us        */
                                                                                /* FRC_SYNC0_STATUS_R[5]: Sync event from 2G Timer (Set by Design, read to clear this bit)                                            */
                                                                                /* SYSCLK_CNT_SYNC0[4:0]: Absolute time synchronized by 2G synchronization request (In unit of 26M clock cycle)                       */
#define GPS_SYNC_TIME            ((APBADDR32)(MCU_TOPSM_base+0x00C4))           /* GPS Sync Time (in unit of us), when free run counter match this value, HW will automatic send out gps_sync pulse longer than 120ns */
#define GPS_SYNC_CTL             ((APBADDR32)(MCU_TOPSM_base+0x00C8))           /* GPS_SYNC1[0], GPS Sync Start, Set by SW, clear by HW                                                                               */
#define RM_PLL_MASK_TIMER_REQ_0  ((APBADDR32)(MCU_TOPSM_base+0x0840))           /* Power Status Register                         */
#define RM_PLL_MASK_TIMER_REQ_1  ((APBADDR32)(MCU_TOPSM_base+0x0844))           /* Power Status Register                         */
#define RM_SM_TRG_MASK           ((APBADDR32)(MCU_TOPSM_base+0x0870))           /* Sleep Manager Cross Trigger Control           */
#define GPS_SYNC_CON0            GPS_SYNC_TIME
#define GPS_SYNC_CON1            GPS_SYNC_CTL
#define FRC_SYNC_1L              FRC_SYNC_VAL_2G_MISC                           /* SYSCLK_CNT_SYNC0[4:0] is the same as SYNC_1L  */
#define FRC_SYNC1_STA            FRC_SYNC_VAL_2G_MISC
#define FRC_SYNC_1H              FRC_SYNC_VAL_2G_H
#define RM_PLL_MASK0             RM_PLL_MASK_TIMER_REQ_0
#define RM_PLL_MASK1             RM_PLL_MASK_TIMER_REQ_1
         #else
#define RM_CLK_SETTLE            ((APBADDR32)(MCU_TOPSM_base+0x0000))           /* Resource Manager Clock Settling Setting       */
#define RM_TMR_TRG0              ((APBADDR32)(MCU_TOPSM_base+0x0010))           /* Resource Manager Timer Cross Trigger Setting  */
#define RM_TMR_TRG1              ((APBADDR32)(MCU_TOPSM_base+0x0014))           /* Resource Manager Timer Cross Trigger Setting  */
#define RM_TMR_PWR0              ((APBADDR32)(MCU_TOPSM_base+0x0018))           /* Resource Manager SUBSYS Power Setting         */
#define RM_TMR_PWR1              ((APBADDR32)(MCU_TOPSM_base+0x001C))           /* Resource Manager SUBSYS Power Setting         */
#define RM_PERI_CON              ((APBADDR32)(MCU_TOPSM_base+0x0030))           /* Resource Manager Peripheral Pause Control     */
#define RM_TMR_SSTA              ((APBADDR32)(MCU_TOPSM_base+0x0040))           /* Resource Manager Timer Sleep Control State    */
#define TOPSM_DBG                ((APBADDR32)(MCU_TOPSM_base+0x0050))           /* Sleep Manager Debug Control                   */
#define FRC_F32K_FM              ((APBADDR32)(MCU_TOPSM_base+0x0084))           /* F32K_CK Frequency Measurement Value           */
#define FRC_VAL_R                ((APBADDR32)(MCU_TOPSM_base+0x0088))           /* Free Running Counter Current Value            */
#define FRC_SYNC1_STA            ((APBADDR32)(MCU_TOPSM_base+0x0070))           /* TQ_CNT to FRC sync status                     */
#define GPS_SYNC_CON0            ((APBADDR32)(MCU_TOPSM_base+0x0300))           /* GPS strobe timing value of Free Running Counter  */
#define GPS_SYNC_CON1            ((APBADDR32)(MCU_TOPSM_base+0x0304))           /* GPS strobe timing ENABLE of Free Running Counter */
#define FRC_SYNC_1L              ((APBADDR32)(MCU_TOPSM_base+0x0090))           /* Free Running Counter sync result in 1/26 us   */
#define FRC_SYNC_1H              ((APBADDR32)(MCU_TOPSM_base+0x0094))           /* Free Running Counter sync result in us        */
#define RM_PLL_MASK0             ((APBADDR32)(MCU_TOPSM_base+0x0830))           /* Power Status Register                         */
#define RM_PLL_MASK1             ((APBADDR32)(MCU_TOPSM_base+0x0834))           /* Power Status Register                         */
#define RM_SM_TRG_MASK           ((APBADDR32)(MCU_TOPSM_base+0x0860))           /* Sleep Manager Cross Trigger Control           */
         #endif
/* ----------------------------------------------------------------------------------------------------------------------------- */
         #if IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define MODEM_RM_TMR_PWR0        ((APBADDR32)(MODEM2G_TOPSM_base+0x0018))       /* Resource Manager Timer Power Enable Control 0 */
#define MODEM_RM_TMR_PWR1        ((APBADDR32)(MODEM2G_TOPSM_base+0x001C))       /* Resource Manager Timer Power Enable Control 1 */
         #endif
#define MODEM_RM_TMR_SSTA        ((APBADDR32)(MODEM2G_TOPSM_base+0x0040))       /* Resource Manager Timer Sleep Control State    */
#define MODEM_CCF_CLK_CON        ((APBADDR32)(MODEM2G_TOPSM_base+0x0200))
#define MODEM_RM_PWR_CON(n)      ((APBADDR32)(MODEM2G_TOPSM_base+0x0800+(n)*4)) /* Power Control Register n                      */
#define MODEM_RM_PWR_STA         ((APBADDR32)(MODEM2G_TOPSM_base+0x0820))       /* Power Status Register                         */
#define MODEM_RM_SM_MASK         ((APBADDR32)(MODEM2G_TOPSM_base+0x0890))       /* Sleep Manager Enable Control                  */
#define MODEM_SM_REQ_MASK        ((APBADDR32)(MODEM2G_TOPSM_base+0x08B0))       /* Sleep Manager Request Source Mask             */
#define MODEM_RM_PWR_CON0        MODEM_RM_PWR_CON(0)                            /* MD2GSYS Power Control Register                */
#define MODEM_RM_PWR_CON1        MODEM_RM_PWR_CON(1)                            /* HSPASYS Power Control Register                */
/* ----------------------------------------------------------------------------------------------------------------------------- */
      #endif
   #else
/* For IS_CHIP_MT6290, IS_CHIP_MT6595 and later                                                  */
/* SM related register has been declared in l1sm.h, md_topsm_private.h and modem_topsm_private.h */
/* Only define registers which L1D and SM use different name.                                    */
#if IS_CHIP_MT6752_MD2
#define MODEM_RM_PWR_CON0   MODEM_TOPSM_RM_PWR_CON0
#define MODEM_CCF_CLK_CON   MODEM_TOPSM_CCF_CLK_CON
#define MODEM_RM_TMR_SSTA   MODEM_TOPSM_RM_TMR_SSTA
#else
#define MODEM_RM_PWR_CON0   MODEM2G_TOPSM_RM_PWR_CON0
#define MODEM_CCF_CLK_CON   MODEM2G_TOPSM_CCF_CLK_CON
#define MODEM_RM_TMR_SSTA   MODEM2G_TOPSM_RM_TMR_SSTA
#endif
/* --------------------------------------------------------------------------------------------------------------------- */
   #endif /* IS_CHIP_MT6276 || IS_CHIP_MT6573 || IS_CHIP_MT6575 || IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 */

#define TQINIT_SM                SM_TQINIT
#define SM_32K_FREE_RUN          RTCCOUNT

#else
/* --------------------------------------------------------------------------------------------------------------------- */
#define SM_PAUSE_M               ((APBADDR)  (SM_base+0x000))           /* msb of pause duration [0]                     */
#define SM_PAUSE_L               ((APBADDR)  (SM_base+0x004))           /* 16 lsb of pause duration [15:0]               */
#define SM_CLK_SETTLE            ((APBADDR)  (SM_base+0x008))           /* clock restart duration [13:0]                 */
#define SM_FINAL_PAUSE_M         ((APBADDR)  (SM_base+0x00C))           /* msb of final pause count [0]                  */
#define SM_FINAL_PAUSE_L         ((APBADDR)  (SM_base+0x010))           /* 16 lsb of final pause count [15:0]            */
#define SM_QBIT_START            ((APBADDR)  (SM_base+0x014))           /* TQ_CURRENT_COUNT value at start of the pause [13:0] */
#define SM_CON                   ((APBADDR)  (SM_base+0x018))           /* 0: SM_FM_START                                */
                                                                        /* 1: SM_PAUSE_START                             */
#define SM_STA                   ((APBADDR)  (SM_base+0x01C))           /* 0: SM_FM_REQUEST                              */
                                                                        /* 1: SM_FM_COMPLETE                             */
                                                                        /* 4: SM_PAUSE_COMPLETE                          */
                                                                        /* 5: SM_PAUSE_INTERRUPT                         */
                                                                        /* 6: SM_PAUSE_COMPLETE                          */
                                                                        /* 7: SM_SETTLING_COMPLETE                       */
                                                                        /* 8: SM_PAUSE_ABORT                             */
#define SM_FM_DURATION           ((APBADDR)  (SM_base+0x020))           /* 32KHz measuremnt duration [15:0]              */
#define SM_FM_RESULT_M           ((APBADDR)  (SM_base+0x024))           /* 10 msb of frequency measurement result [9:0]  */
#define SM_FM_RESULT_L           ((APBADDR)  (SM_base+0x028))           /* 16 lsb of frequency measurement result [15:0] */
#define SM_CNF                   ((APBADDR)  (SM_base+0x02C))           /* SM configuration Register                     */
#define SM_CONTROL1              ((APBADDR)  (SM_base+0x030))           /* 0: SW Wake Up                                 */
/* --------------------------------------------------------------------------------------------------------------------- */
   #if IS_CHIP_MT6238
#define TQ_WRAP_SM               ((APBADDR)  (SM_base+0x034))           /* latched Qbit counter reset position of SM     */
   #endif
/* --------------------------------------------------------------------------------------------------------------------- */
   #if IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
#define SM_WAKE_PLL_SETTING      ((APBADDR)  (SM_base+0x038))           /* PLL RST time in the clk settling time.        */
   #endif
   #if IS_HYPER_SLEEP_MODE_CHIP
#define TQINIT_SM                ((APBADDR)  (SM_base+0x03C))           /* Jump value of the first frame after sleep mode*/
   #endif
/* --------------------------------------------------------------------------------------------------------------------- */
#define TDMA_SM_WAKE_CON         ((APBADDR)  (SM_base+0x040))           /* Software interrupt trigger                    */
#define SM_CLK_FINAL_SETTLE      ((APBADDR)  (SM_base+0x044))           /* clock restart duration [13:0]                 */
/* --------------------------------------------------------------------------------------------------------------------- */
   #if IS_65NM_CHIP
#define TDMA_PDN_SEQ             ((APBADDR)  (SM_base+0x050))           /* Wait-time setting for PWDN strobe             */
#define TDMA_PDN_DURATION        ((APBADDR)  (SM_base+0x054))           /* Power down duration                           */
#define TDMA_RST_DURATION        ((APBADDR)  (SM_base+0x058))           /* Reset duration                                */
#define TDMA_PDN_CON             ((APBADDR)  (SM_base+0x05C))           /* Power down control                            */
#define TDMA_PDN_SEQ2            ((APBADDR)  (SM_base+0x060))           /* Wait-time setting for RESET strobe            */
   #endif
/* --------------------------------------------------------------------------------------------------------------------- */
   #if IS_EDGE_SAIC_CHIP_MT6268_AND_LATTER_VERSION && !IS_CHIP_MT6268A
      #if IS_CHIP_MT6268
#define TDMA_WRAP_CNT            ((APBADDR)  (SM_base+0x068))           /* Counts TDMA_TQCNT wrap-around times [13:0]    */
      #else
#define TDMA_WRAP_CNT            ((APBADDR)  (SM_base+0x064))           /* Counts TDMA_TQCNT wrap-around times [13:0]    */
      #endif
#define TQ_WRAP_CNT              TDMA_WRAP_CNT                          /* Counts TDMA_TQCNT wrap-around times [13:0]    */
   #endif
/* --------------------------------------------------------------------------------------------------------------------- */
/* MT6268,TK6516,MT6238,MT6235 don't have DSPROMPD */
   #if IS_CHIP_MT6228 || IS_CHIP_MT6229 // (defined(MT6228) || defined(MT6229) || defined(MT6230))
#define DSPROMPD                 ((APBADDR)  (SM_base+0x100))           /* Power-down indication of  DSP ROM             */
#define TDMA_DSPROMPD            DSPROMPD                               /* Via ROM Power Down [5:0]                      */
   #endif /*defined(MT6228) || defined(MT6229) */
   #if IS_CHIP_MT6253
#define TDMA_DSPSPROM_HWPD       ((APBADDR)  (SM_base+0x0110))          //(TDMA_base+0x0310)
#define TDMA_DSPSPROM_SWPD       ((APBADDR)  (SM_base+0x0114))          //(TDMA_base+0x0314)
   #endif
/* --------------------------------------------------------------------------------------------------------------------- */
#define SM_CONTROL               SM_CON                                 /*                                               */
#define SM_STATUS                SM_STA                                 /*                                               */
#define SM_CONFIG                SM_CNF                                 /* SM configuration register                     */
#define SM_32K_FREE_RUN          RTCCOUNT
/* --------------------------------------------------------------------------------------------------------------------- */
#endif

#ifdef __SWDBG_SUPPORT__
/* --------------------------------------------------------------------------------------------------------------------- */
#define SWDBG_STA                ((APBADDR32)(SWDBG_base+0x10))         /* Software Debug Controller Status Register  FOR  L1C USE   */
#define SWDBG_INT                ((APBADDR)  (SWDBG_base+0x14))         /* Software Debug Controller Interrupt Register              */
#define SWDBG_INTACK             ((APBADDR)  (SWDBG_base+0x18))         /* Software Debug Controller Interrupt Acknowledge Register  */
#define SWDBG_CONA               ((APBADDR32)(SWDBG_base+0x1C))         /* Software Debug Controller Control Register A              */
#define SWDBG_CONB               ((APBADDR32)(SWDBG_base+0x20))         /* Software Debug Controller Control Register B              */
#define SWDBG_CONC               ((APBADDR32)(SWDBG_base+0x24))         /* Software Debug Controller Control Register C              */
#define SWDBG_DDCONA             ((APBADDR32)(SWDBG_base+0x30))         /* Software Debug Controller DSP Debug Control Register A    */
#define SWDBG_DDCONB             ((APBADDR32)(SWDBG_base+0x34))         /* Software Debug Controller DSP Debug Control Register B    */
#define SWDBG_MDTXCONA           ((APBADDR32)(SWDBG_base+0x40))         /* Software Debug Controller MCU TX Debug Control Register A */
#define SWDBG_MDTXCONB           ((APBADDR32)(SWDBG_base+0x44))         /* Software Debug Controller MCU TX Debug Control Register B */
#define SWDBG_MDTXA              ((APBADDR)  (SWDBG_base+0x48))         /* Software Debug Controller MCU Debug TX Data Register A    */
#define SWDBG_MDTXB              ((APBADDR)  (SWDBG_base+0x4C))         /* Software Debug Controller MCU Debug TX Data Register B    */
#define SWDBG_MDRXCON            ((APBADDR32)(SWDBG_base+0x50))         /* Software Debug Controller MCU Debug Rx control Register   */
#define SWDBG_MDRXDAT            ((APBADDR)  (SWDBG_base+0x54))         /* Software Debug Controller MCU Debug RX Data Register      */
#define SWDBG_MPCFG              ((APBADDR32)(SWDBG_base+0x60))         /* Software Debug Controller MCU Profiling Control Register  */
#define SWDBG_MPCON              ((APBADDR32)(SWDBG_base+0x64))         /* Software Debug Controller MCU Profiling Control Register  */
#define SWDBG_MPTIMER            ((APBADDR32)(SWDBG_base+0x68))         /* Software Debug Controller MCU Profiling Timer Register    */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif /*__SWDBG_SUPPORT__*/

/*====================*\
|*  Reset Managerment *|
\* ===================================================================================================================== */
/* for MT6208 & MT6205 & MT6218                                                                                          */
/* --------------------------------------------------------------------------------------------------------------------- */
#if IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#elif IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2
#define WDT_MODE                 ((APBADDR32)(RGU_base+0x000))          /* Watchdog Timer Control Register               */
#define WDT_LENGTH               ((APBADDR32)(RGU_base+0x004))          /* Watchdog Time-out Interval Register           */
#define WDT_RESTART              ((APBADDR32)(RGU_base+0x008))          /* Watchdog Timer Restart Register               */
#define WDT_STA                  ((APBADDR32)(RGU_base+0x00C))          /* Watchdog Timer Status Register                */
#define SW_DSP_RSTN              ((APBADDR32)(RGU_base+0x014))          /* DSP Software Reset Register                   */
#define WDT_RSTINTERVAL          ((APBADDR32)(RGU_base+0x018))          /* Watchdog Timer Reset Signal Duration Register */
#else
#define WDT_MODE                 ((APBADDR)(RGU_base+0x000))            /* Watchdog Timer Control Register               */
#define WDT_LENGTH               ((APBADDR)(RGU_base+0x004))            /* Watchdog Time-out Interval Register           */
#define WDT_RESTART              ((APBADDR)(RGU_base+0x008))            /* Watchdog Timer Restart Register               */
#define WDT_STA                  ((APBADDR)(RGU_base+0x00C))            /* Watchdog Timer Status Register                */
#define SW_PERIPH_RSTN           ((APBADDR)(RGU_base+0x010))            /* CPU Peripheral Software Reset Register        */
#define SW_DSP_RSTN              ((APBADDR)(RGU_base+0x014))            /* DSP Software Reset Register                   */
#define WDT_RSTINTERVAL          ((APBADDR)(RGU_base+0x018))            /* Watchdog Timer Reset Signal Duration Register */
#endif
/* --------------------------------------------------------------------------------------------------------------------- */

/*========================*\
|* Power Down Managerment *|
\* ===================================================================================================================== */
#if IS_SMARTPHONE_CHIP_TK6516_AND_LATTER_VERSION

   #if IS_CHIP_TK6516
/*TK6516*/ #define PDN_CON1                 ((APBADDR32)(CONFIG_base+0x304))       /* Power Down Control 1 Register      */
/*TK6516*/ #define PDN_CON2                 ((APBADDR32)(CONFIG_base+0x308))       /* Power Down Control 2 Register      */
/*TK6516*/ #define PDN_CON4                 ((APBADDR32)(CONFIG_base+0x310))       /* Power Down Control 4 Register      */
/*TK6516*/ #define PDN_SET1                 ((APBADDR32)(CONFIG_base+0x324))       /* Power Down Set     1 Register      */
/*TK6516*/ #define PDN_SET2                 ((APBADDR32)(CONFIG_base+0x328))       /* Power Down Set     2 Register      */
/*TK6516*/ #define PDN_SET4                 ((APBADDR32)(CONFIG_base+0x330))       /* Power Down Set     4 Register      */
/*TK6516*/ #define PDN_CLR1                 ((APBADDR32)(CONFIG_base+0x344))       /* Power Down Clear   1 Register      */
/*TK6516*/ #define PDN_CLR2                 ((APBADDR32)(CONFIG_base+0x348))       /* Power Down Clear   2 Register      */
/*TK6516*/ #define PDN_CLR4                 ((APBADDR32)(CONFIG_base+0x350))       /* Power Down Clear   4 Register      */
   #else // MT6516~
/*MT6516*/ #define CG_CON0                  ((APBADDR32)(MDMCUSYS_base+0x000))     /* Power Down Control 0 Register      */
/*MT6516*/ #define CG_SET0                  ((APBADDR32)(MDMCUSYS_base+0x020))     /* Power Down Set     0 Register      */
/*MT6516*/ #define CG_CLR0                  ((APBADDR32)(MDMCUSYS_base+0x040))     /* Power Down Clear   0 Register      */
/*MT6516*/ #define CG_CON1                  ((APBADDR32)(MDMCUSYS_base+0x100))     /* Power Down Control 1 Register      */
/*MT6516*/ #define CG_SET1                  ((APBADDR32)(MDMCUSYS_base+0x120))     /* Power Down Set     1 Register      */
/*MT6516*/ #define CG_CLR1                  ((APBADDR32)(MDMCUSYS_base+0x140))     /* Power Down Clear   1 Register      */
/*MT6516*/ #define PDN_CON2                 CG_CON0                                /* Power Down Control 2 Register      */
/*MT6516*/ #define PDN_SET2                 CG_SET0                                /* Power Down Set     2 Register      */
/*MT6516*/ #define PDN_CLR2                 CG_CLR0                                /* Power Down Clear   2 Register      */
/*MT6516*/ #define PDN_CON4                 CG_CON1                                /* Power Down Control 4 Register      */
/*MT6516*/ #define PDN_SET4                 CG_SET1                                /* Power Down Set     4 Register      */
/*MT6516*/ #define PDN_CLR4                 CG_CLR1                                /* Power Down Clear   4 Register      */
   #endif
/*MT6516*/ #define PDN_CON_TDMA             0x0004
/*MT6516*/ #define PDN_CON_BSI              0x0008

#else // feature phone register map

   #if IS_CHIP_MT6276 || IS_CHIP_MT6575 || IS_CHIP_MT6573 || IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
/* The following settings are moved to l1_interface_reg.h */

   #elif IS_CHIP_MT6268
/*MT6268*/ #define CG_CON0                  ((APBADDR)(CONFIG_base+0x300))         /* Power Down Control 0 Register      */
/*MT6268*/ #define CG_CON1                  ((APBADDR)(CONFIG_base+0x304))         /* Power Down Control 1 Register      */
/*MT6268*/ #define CG_CON2                  ((APBADDR)(CONFIG_base+0x308))         /* Power Down Control 2 Register      */
/*MT6268*/ #define CG_CON4                  ((APBADDR)(CONFIG_base+0x330))         /* Power Down Control 4 Register      */
/*MT6268*/ #define CG_SET0                  ((APBADDR)(CONFIG_base+0x310))         /* Power Down Disable 0 Register      */
/*MT6268*/ #define CG_SET1                  ((APBADDR)(CONFIG_base+0x314))         /* Power Down Disable 1 Register      */
/*MT6268*/ #define CG_SET2                  ((APBADDR)(CONFIG_base+0x318))         /* Power Down Disable 2 Register      */
/*MT6268*/ #define CG_SET4                  ((APBADDR)(CONFIG_base+0x334))         /* Power Down Disable 4 Register      */
/*MT6268*/ #define CG_CLR0                  ((APBADDR)(CONFIG_base+0x320))         /* Power Down Enable  0 Register      */
/*MT6268*/ #define CG_CLR1                  ((APBADDR)(CONFIG_base+0x324))         /* Power Down Enable  1 Register      */
/*MT6268*/ #define CG_CLR2                  ((APBADDR)(CONFIG_base+0x328))         /* Power Down Enable  2 Register      */
/*MT6268*/ #define CG_CLR4                  ((APBADDR)(CONFIG_base+0x338))         /* Power Down Enable  4 Register      */
/*MT6268*/ #define PDN_CON0                 CG_CON0
/*MT6268*/ #define PDN_CON1                 CG_CON1
/*MT6268*/ #define PDN_CON2                 CG_CON2
/*MT6268*/ #define PDN_CON4                 CG_CON4
/*MT6268*/ #define PDN_SET0                 CG_SET0
/*MT6268*/ #define PDN_SET1                 CG_SET1
/*MT6268*/ #define PDN_SET2                 CG_SET2
/*MT6268*/ #define PDN_SET4                 CG_SET4
/*MT6268*/ #define PDN_CLR0                 CG_CLR0
/*MT6268*/ #define PDN_CLR1                 CG_CLR1
/*MT6268*/ #define PDN_CLR2                 CG_CLR2
/*MT6268*/ #define PDN_CLR4                 CG_CLR4
/*MT6268*/
/*MT6268*/ #define PDN_CON_TDMA             0x0001
/*MT6268*/ #define PDN_CON_BSI              0x0004

   #elif IS_CHIP_MT6236 || IS_CHIP_MT6256 || IS_CHIP_MT6255
/*MT6236~*/ #define MCUSYS_PDN_CON0         ((APBADDR32)(CONFIG_base+0x700))       /* Power Down Control 0 Register        */
/*MT6236~*/ #define MCUSYS_PDN_CON1         ((APBADDR)(CONFIG_base+0x704))         /* Power Down Control 1 Register        */
/*MT6236~*/ #define MCUSYS_PDN_CON2         ((APBADDR)(CONFIG_base+0x708))         /* Power Down Control 2 Register        */
/*MT6236~*/ #define MCUSYS_PDN_CON3         ((APBADDR)(CONFIG_base+0x70C))         /* Power Down Control 4 Register        */
/*MT6236~*/ #define MCUSYS_PDN_SET0         ((APBADDR)(CONFIG_base+0x710))         /* Power Down Disable 0 Register        */
/*MT6236~*/ #define MCUSYS_PDN_SET1         ((APBADDR)(CONFIG_base+0x714))         /* Power Down Disable 1 Register        */
/*MT6236~*/ #define MCUSYS_PDN_SET2         ((APBADDR)(CONFIG_base+0x718))         /* Power Down Disable 2 Register        */
/*MT6236~*/ #define MCUSYS_PDN_SET3         ((APBADDR)(CONFIG_base+0x71C))         /* Power Down Disable 4 Register        */
/*MT6236~*/ #define MCUSYS_PDN_CLR0         ((APBADDR)(CONFIG_base+0x720))         /* Power Down Enable  0 Register        */
/*MT6236~*/ #define MCUSYS_PDN_CLR1         ((APBADDR)(CONFIG_base+0x724))         /* Power Down Enable  1 Register        */
/*MT6236~*/ #define MCUSYS_PDN_CLR2         ((APBADDR)(CONFIG_base+0x728))         /* Power Down Enable  2 Register        */
/*MT6236~*/ #define MCUSYS_PDN_CLR3         ((APBADDR)(CONFIG_base+0x72C))         /* Power Down Enable  4 Register        */
/*MT6236~*/ #define PDN_CON0                MCUSYS_PDN_CON0                        /* not used                             */
/*MT6236~*/ #define PDN_CON1                MCUSYS_PDN_CON1
/*MT6236~*/ #define PDN_CON2                MCUSYS_PDN_CON2
/*MT6236~*/ #define PDN_CON4                MCUSYS_PDN_CON3
/*MT6236~*/ #define PDN_SET0                MCUSYS_PDN_SET0
/*MT6236~*/ #define PDN_SET1                MCUSYS_PDN_SET1
/*MT6236~*/ #define PDN_SET2                MCUSYS_PDN_SET2
/*MT6236~*/ #define PDN_SET4                MCUSYS_PDN_SET3
/*MT6236~*/ #define PDN_CLR0                MCUSYS_PDN_CLR0
/*MT6236~*/ #define PDN_CLR1                MCUSYS_PDN_CLR1
/*MT6236~*/ #define PDN_CLR2                MCUSYS_PDN_CLR2
/*MT6236~*/ #define PDN_CLR4                MCUSYS_PDN_CLR3
/*MT6236~*/
/*MT6236~*/ #define PDN_CON_TDMA            0x0001
/*MT6236~*/ #define PDN_CON_BSI             0x0004

   #else
/*MT6229~*/ #define PDN_CON0                ((APBADDR)(CONFIG_base+0x300))         /* Power Down Control 0 Register        */
/*MT6229~*/ #define PDN_CON1                ((APBADDR)(CONFIG_base+0x304))         /* Power Down Control 1 Register        */
/*MT6229~*/ #define PDN_CON2                ((APBADDR)(CONFIG_base+0x308))         /* Power Down Control 2 Register        */
/*MT6229~*/ #define PDN_CON3                ((APBADDR)(CONFIG_base+0x30C))         /* Power Down Control 3 Register        */
/*MT6229~*/ #define PDN_CON4                ((APBADDR)(CONFIG_base+0x330))         /* Power Down Control 4 Register        */
/*MT6229~*/ #define PDN_SET0                ((APBADDR)(CONFIG_base+0x310))         /* Power Down Disable 0 Register        */
/*MT6229~*/ #define PDN_SET1                ((APBADDR)(CONFIG_base+0x314))         /* Power Down Disable 1 Register        */
/*MT6229~*/ #define PDN_SET2                ((APBADDR)(CONFIG_base+0x318))         /* Power Down Disable 2 Register        */
/*MT6229~*/ #define PDN_SET3                ((APBADDR)(CONFIG_base+0x31C))         /* Power Down Disable 3 Register        */
/*MT6229~*/ #define PDN_SET4                ((APBADDR)(CONFIG_base+0x334))         /* Power Down Disable 4 Register        */
/*MT6229~*/ #define PDN_CLR0                ((APBADDR)(CONFIG_base+0x320))         /* Power Down Enable  0 Register        */
/*MT6229~*/ #define PDN_CLR1                ((APBADDR)(CONFIG_base+0x324))         /* Power Down Enable  1 Register        */
/*MT6229~*/ #define PDN_CLR2                ((APBADDR)(CONFIG_base+0x328))         /* Power Down Enable  2 Register        */
/*MT6229~*/ #define PDN_CLR3                ((APBADDR)(CONFIG_base+0x32C))         /* Power Down Enable  3 Register        */
/*MT6229~*/ #define PDN_CLR4                ((APBADDR)(CONFIG_base+0x338))         /* Power Down Enable  4 Register        */
/*MT6229~*/
/*MT6229~*/ #define PDN_CON_TDMA            0x0001
/*MT6229~*/ #define PDN_CON_BSI             0x0004
   #endif
#endif

#if IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#else
#define IDN_SEL                             ((APBADDR)(CONFIG_base+0x200))         /* Internal Debug Port Control Register */
#define MPLL                                ((APBADDR)(CONFIG_base+0x100))         /* MCU Clock Select (13MxN)             */
#endif

// 65 nm MD2G PDN_CON
#if IS_CHIP_MT6516
/*MT6516*/ #define GCG_CON0                 ((APBADDR32)(MD2GCONFG_base+0x000))    /* Power Down Control 0 Register        */
/*MT6516*/ #define GCG_CON1                 ((APBADDR32)(MD2GCONFG_base+0x004))    /* Power Down Control 1 Register        */
/*MT6516*/ #define GCG_SET0                 ((APBADDR32)(MD2GCONFG_base+0x010))    /* Power Down Disable 0 Register        */
/*MT6516*/ #define GCG_SET1                 ((APBADDR32)(MD2GCONFG_base+0x014))    /* Power Down Disable 1 Register        */
/*MT6516*/ #define GCG_CLR0                 ((APBADDR32)(MD2GCONFG_base+0x020))    /* Power Down Enable  0 Register        */
/*MT6516*/ #define GCG_CLR1                 ((APBADDR32)(MD2GCONFG_base+0x024))    /* Power Down Enable  1 Register        */
/*MT6516*/ #define MD2GSYS_DELSEL0          ((APBADDR32)(MD2GCONFG_base+0x100))    /* Memory delsel control register 0     */
/*MT6516*/ #define MD2GSYS_DELSEL1          ((APBADDR32)(MD2GCONFG_base+0x104))    /* Memory delsel control register 1     */
/*MT6516*/ #define MD2GSYS_DELSEL2          ((APBADDR32)(MD2GCONFG_base+0x108))    /* Memory delsel control register 2     */
/*MT6516*/ #define MD2G_PDN_CON2            GCG_CON0
/*MT6516*/ #define MD2G_PDN_CON4            GCG_CON1
/*MT6516*/ #define MD2G_PDN_SET2            GCG_SET0
/*MT6516*/ #define MD2G_PDN_SET4            GCG_SET1
/*MT6516*/ #define MD2G_PDN_CLR2            GCG_CLR0
/*MT6516*/ #define MD2G_PDN_CLR4            GCG_CLR1

#elif IS_CHIP_MT6268
/*MT6268*/ #define GCG_CON0                 ((APBADDR)(GCONFG_base+0x300))         /* Power Down Control 0 Register        */
/*MT6268*/ #define GCG_CON2                 ((APBADDR)(GCONFG_base+0x308))         /* Power Down Control 2 Register        */
/*MT6268*/ #define GCG_CON4                 ((APBADDR)(GCONFG_base+0x330))         /* Power Down Control 4 Register        */
/*MT6268*/ #define GCG_SET0                 ((APBADDR)(GCONFG_base+0x310))         /* Power Down Disable 0 Register        */
/*MT6268*/ #define GCG_SET2                 ((APBADDR)(GCONFG_base+0x318))         /* Power Down Disable 2 Register        */
/*MT6268*/ #define GCG_SET4                 ((APBADDR)(GCONFG_base+0x334))         /* Power Down Disable 4 Register        */
/*MT6268*/ #define GCG_CLR0                 ((APBADDR)(GCONFG_base+0x320))         /* Power Down Enable  0 Register        */
/*MT6268*/ #define GCG_CLR2                 ((APBADDR)(GCONFG_base+0x328))         /* Power Down Enable  2 Register        */
/*MT6268*/ #define GCG_CLR4                 ((APBADDR)(GCONFG_base+0x338))         /* Power Down Enable  4 Register        */
/*MT6268*/ #define GROM_DELSEL0             ((APBADDR)(GCONFG_base+0x600))         /* Delay Select for ROM Control0        */
/*MT6268*/ #define GROM_DELSEL1             ((APBADDR)(GCONFG_base+0x604))         /* Delay Select for ROM Control1        */
/*MT6268*/ #define GROM_DELSEL2             ((APBADDR)(GCONFG_base+0x608))         /* Delay Select for ROM Control2        */
/*MT6268*/ #define GROM_DELSEL3             ((APBADDR)(GCONFG_base+0x60C))         /* Delay Select for ROM Control3        */
/*MT6268*/ #define GROM_DELSEL4             ((APBADDR)(GCONFG_base+0x610))         /* Delay Select for ROM Control4        */
/*MT6268*/ #define GROM_DELSEL5             ((APBADDR)(GCONFG_base+0x614))         /* Delay Select for ROM Control5        */
/*MT6268*/ #define GROM_DELSEL6             ((APBADDR)(GCONFG_base+0x618))         /* Delay Select for ROM Control6        */
/*MT6268*/ #define MD2G_PDN_CON0            GCG_CON0
/*MT6268*/ #define MD2G_PDN_CON2            GCG_CON2
/*MT6268*/ #define MD2G_PDN_CON4            GCG_CON4
/*MT6268*/ #define MD2G_PDN_SET0            GCG_SET0
/*MT6268*/ #define MD2G_PDN_SET2            GCG_SET2
/*MT6268*/ #define MD2G_PDN_SET4            GCG_SET4
/*MT6268*/ #define MD2G_PDN_CLR0            GCG_CLR0
/*MT6268*/ #define MD2G_PDN_CLR2            GCG_CLR2
/*MT6268*/ #define MD2G_PDN_CLR4            GCG_CLR4
/*MT6268*/ #define WCG_CON0                 ((APBADDR)(WCONFG_base+0x000))         /* Power Down Control 0 Register        */
/*MT6268*/ #define WCG_SET0                 ((APBADDR)(WCONFG_base+0x010))         /* Power Down Disable 0 Register        */
/*MT6268*/ #define WCG_CLR0                 ((APBADDR)(WCONFG_base+0x020))         /* Power Down Enable  0 Register        */
/*MT6268*/ #define MD3G_PDN_CON0            WCG_CON0
/*MT6268*/ #define MD3G_PDN_SET0            WCG_SET0
/*MT6268*/ #define MD3G_PDN_CLR0            WCG_CLR0
/*MT6268*/ #define MMCG_SET0                ((APBADDR32)(MMCONFG_base+0x000))      /* Power Down Disable 0 Register        */
/*MT6268*/ #define MMCG_CLR0                ((APBADDR32)(MMCONFG_base+0x004))      /* Power Down Enable  0 Register        */
/*MT6268*/ #define MMCG_CON0                ((APBADDR32)(MMCONFG_base+0x008))      /* Power Down Control 0 Register        */
/*MT6268*/ #define MM_PDN_SET0              MMCG_SET0
/*MT6268*/ #define MM_PDN_CLR0              MMCG_CLR0
/*MT6268*/ #define MM_PDN_CON0              MMCG_CON0

#elif IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
/*MT6583*/ #define HWCG_BYPASS             ((APBADDR)(MD2GCONFG_base+0x058))
/* The other settings are moved to l1_interface_reg.h */

#elif IS_CHIP_MT6250 || IS_CHIP_MT6280
/* The following settings are moved to l1_interface_reg.h */

#elif IS_CHIP_MT6236 || IS_CHIP_MT6256 || IS_CHIP_MT6251 || IS_CHIP_MT6255
/*MT6236~*/ #define MD2GSYS_CG_CON0         ((APBADDR)(MD2GCONFG_base+0x000))      /* Power Down Control 0 Register        */
/*MT6236~*/ #define MD2GSYS_CG_CON2         ((APBADDR)(MD2GCONFG_base+0x008))      /* Power Down Control 2 Register        */
/*MT6236~*/ #define MD2GSYS_CG_CON4         ((APBADDR)(MD2GCONFG_base+0x030))      /* Power Down Control 4 Register        */
/*MT6236~*/ #define MD2GSYS_CG_SET0         ((APBADDR)(MD2GCONFG_base+0x010))      /* Power Down Disable 0 Register        */
/*MT6236~*/ #define MD2GSYS_CG_SET2         ((APBADDR)(MD2GCONFG_base+0x018))      /* Power Down Disable 2 Register        */
/*MT6236~*/ #define MD2GSYS_CG_SET4         ((APBADDR)(MD2GCONFG_base+0x034))      /* Power Down Disable 4 Register        */
/*MT6236~*/ #define MD2GSYS_CG_CLR0         ((APBADDR)(MD2GCONFG_base+0x020))      /* Power Down Enable  0 Register        */
/*MT6236~*/ #define MD2GSYS_CG_CLR2         ((APBADDR)(MD2GCONFG_base+0x028))      /* Power Down Enable  2 Register        */
/*MT6236~*/ #define MD2GSYS_CG_CLR4         ((APBADDR)(MD2GCONFG_base+0x038))      /* Power Down Enable  4 Register        */
/*MT6236~*/ #define MD2G_PDN_CON0           MD2GSYS_CG_CON0                        /* not used                             */
/*MT6236~*/ #define MD2G_PDN_CON2           MD2GSYS_CG_CON2                        /* not used                             */
/*MT6236~*/ #define MD2G_PDN_CON4           MD2GSYS_CG_CON4                        /* not used                             */
/*MT6236~*/ #define MD2G_PDN_SET0           MD2GSYS_CG_SET0
/*MT6236~*/ #define MD2G_PDN_SET2           MD2GSYS_CG_SET2
/*MT6236~*/ #define MD2G_PDN_SET4           MD2GSYS_CG_SET4
/*MT6236~*/ #define MD2G_PDN_CLR0           MD2GSYS_CG_CLR0
/*MT6236~*/ #define MD2G_PDN_CLR2           MD2GSYS_CG_CLR2
/*MT6236~*/ #define MD2G_PDN_CLR4           MD2GSYS_CG_CLR4

#elif IS_CHIP_MT6268T_DMAC || IS_CHIP_MT6270A
/*MT6268T*/ #define GCG_CON0                ((APBADDR)(FPGA_CONFIG_base+0x300))
/*MT6268T*/ #define GCG_CON2                ((APBADDR)(FPGA_CONFIG_base+0x308))
/*MT6268T*/ #define GCG_SET0                ((APBADDR)(FPGA_CONFIG_base+0x310))
/*MT6268T*/ #define GCG_SET2                ((APBADDR)(FPGA_CONFIG_base+0x318))
/*MT6268T*/ #define GCG_CLR0                ((APBADDR)(FPGA_CONFIG_base+0x320))
/*MT6268T*/ #define GCG_CLR2                ((APBADDR)(FPGA_CONFIG_base+0x328))
/*MT6268T*/ #define MD2G_PDN_CON2           GCG_CON0
/*MT6268T*/ #define MD2G_PDN_CON4           GCG_CON2
/*MT6268T*/ #define MD2G_PDN_SET2           GCG_SET0
/*MT6268T*/ #define MD2G_PDN_SET4           GCG_SET2
/*MT6268T*/ #define MD2G_PDN_CLR2           GCG_CLR0
/*MT6268T*/ #define MD2G_PDN_CLR4           GCG_CLR2

#elif IS_CHIP_MT6276 || IS_CHIP_MT6573 || IS_CHIP_MT6575
/* The following settings are moved to l1_interface_reg.h */
#endif

#if IS_CHIP_MT6516
/*MT6516*/ #define HW_IRDBG_CLK_ON()        HW_WRITE(MD2G_PDN_CLR2,0x18000)
/*MT6516*/ #define HW_IRDBG_CLK_OFF()       HW_WRITE(MD2G_PDN_SET2,0x18000)
/*MT6516*/ #define HW_IRDMA_CLK_ON()        HW_WRITE(MD2G_PDN_CLR2,0x0002)
/*MT6516*/ #define HW_IRDMA_CLK_OFF()       HW_WRITE(MD2G_PDN_SET2,0x0002)
/*MT6516*/ #define HW_DIVIDER_CLK_ON()      HW_WRITE(MD2G_PDN_CLR2,0x1000)
/*MT6516*/ #define HW_DIVIDER_CLK_OFF()     HW_WRITE(MD2G_PDN_SET2,0x1000)
/*MT6516*/ #define HW_FCS_CLK_ON()          HW_WRITE(MD2G_PDN_CLR2,0x0080)
/*MT6516*/ #define HW_FCS_CLK_OFF()         HW_WRITE(MD2G_PDN_SET2,0x0080)
#elif IS_CHIP_TK6516
/*TK6516*/ #define HW_IRDMA_CLK_ON()        HW_WRITE(PDN_CLR2     ,0x0002)
/*TK6516*/ #define HW_IRDMA_CLK_OFF()       HW_WRITE(PDN_SET2     ,0x0002)
/*TK6516*/ #define HW_DIVIDER_CLK_ON()      HW_WRITE(PDN_CLR2     ,0x1000)
/*TK6516*/ #define HW_DIVIDER_CLK_OFF()     HW_WRITE(PDN_SET2     ,0x1000)
/*TK6516*/ #define HW_FCS_CLK_ON()          HW_WRITE(PDN_CLR2     ,0x0080)
/*TK6516*/ #define HW_FCS_CLK_OFF()         HW_WRITE(PDN_SET2     ,0x0080)
#elif IS_CHIP_MT6575
/*MT6575*/ #define HW_IRDBG_CLK_ON()
/*MT6575*/ #define HW_IRDBG_CLK_OFF()
/*MT6575*/ #define HW_IRDMA_CLK_ON()
/*MT6575*/ #define HW_IRDMA_CLK_OFF()
/*MT6575*/ #define HW_DIVIDER_CLK_ON()      HW_WRITE(PDN_CLR2     ,0x0800)
/*MT6575*/ #define HW_DIVIDER_CLK_OFF()     HW_WRITE(PDN_SET2     ,0x0800)
/*MT6575*/ #define HW_FCS_CLK_ON()          HW_WRITE(PDN_CLR3     ,0x2000)
/*MT6575*/ #define HW_FCS_CLK_OFF()         HW_WRITE(PDN_SET3     ,0x2000)
#elif IS_CHIP_MT6573
/*MT6573*/ #define HW_IRDBG_CLK_ON()
/*MT6573*/ #define HW_IRDBG_CLK_OFF()
/*MT6573*/ #define HW_IRDMA_CLK_ON()
/*MT6573*/ #define HW_IRDMA_CLK_OFF()
/*MT6573*/ #define HW_DIVIDER_CLK_ON()      HW_WRITE(PDN_CLR4     ,0x0001)
/*MT6573*/ #define HW_DIVIDER_CLK_OFF()     HW_WRITE(PDN_SET4     ,0x0001)
/*MT6573*/ #define HW_FCS_CLK_ON()          HW_WRITE(MD2G_PDN_CLR1,0x0080)
/*MT6573*/ #define HW_FCS_CLK_OFF()         HW_WRITE(MD2G_PDN_SET1,0x0080)
#elif IS_CHIP_MT6276
/*MT6276*/ #define HW_IRDBG_CLK_ON()
/*MT6276*/ #define HW_IRDBG_CLK_OFF()
/*MT6276*/ #define HW_IRDMA_CLK_ON()
/*MT6276*/ #define HW_IRDMA_CLK_OFF()
/*MT6276*/ #define HW_DIVIDER_CLK_ON()      HW_WRITE(PDN_CLR2     ,0x0800)
/*MT6276*/ #define HW_DIVIDER_CLK_OFF()     HW_WRITE(PDN_SET2     ,0x0800)
/*MT6276*/ #define HW_FCS_CLK_ON()          HW_WRITE(MD2G_PDN_CLR1,0x0080)
/*MT6276*/ #define HW_FCS_CLK_OFF()         HW_WRITE(MD2G_PDN_SET1,0x0080)
#elif IS_CHIP_MT6268T_DMAC || IS_CHIP_MT6270A
/*MT6268T*/ #define HW_IRDBG_CLK_ON()
/*MT6268T*/ #define HW_IRDBG_CLK_OFF()
/*MT6268T*/ #define HW_IRDMA_CLK_ON()
/*MT6268T*/ #define HW_IRDMA_CLK_OFF()
/*MT6268T*/ #define HW_DIVIDER_CLK_ON()
/*MT6268T*/ #define HW_DIVIDER_CLK_OFF()
/*MT6268T*/ #define HW_FCS_CLK_ON()
/*MT6268T*/ #define HW_FCS_CLK_OFF()
#elif IS_CHIP_MT6268
/*MT6268*/ #define HW_IRDBG_CLK_ON()        HW_WRITE(MD2G_PDN_CLR0,0x3000)
/*MT6268*/ #define HW_IRDBG_CLK_OFF()       HW_WRITE(MD2G_PDN_SET0,0x3000)
/*MT6268*/ #define HW_IRDMA_CLK_ON()        HW_WRITE(MD2G_PDN_CLR0,0x0040)
/*MT6268*/ #define HW_IRDMA_CLK_OFF()       HW_WRITE(MD2G_PDN_SET0,0x0040)
/*MT6268*/ #define HW_DIVIDER_CLK_ON()      HW_WRITE(PDN_CLR2     ,0x0800)
/*MT6268*/ #define HW_DIVIDER_CLK_OFF()     HW_WRITE(PDN_SET2     ,0x0800)
/*MT6268*/ #define HW_FCS_CLK_ON()          HW_WRITE(MD2G_PDN_CLR2,0x0040)
/*MT6268*/ #define HW_FCS_CLK_OFF()         HW_WRITE(MD2G_PDN_SET2,0x0040)
#elif IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
/*MT6250*/ #define HW_IRDBG_CLK_ON()
/*MT6250*/ #define HW_IRDBG_CLK_OFF()
/*MT6250*/ #define HW_IRDMA_CLK_ON()        HW_WRITE(MD2G_PDN_CLR0,0x0040)
/*MT6250*/ #define HW_IRDMA_CLK_OFF()       HW_WRITE(MD2G_PDN_SET0,0x0040)
/*MT6250*/ #define HW_DIVIDER_CLK_ON()      HW_WRITE(PDN_CLR2     ,0x0800)
/*MT6250*/ #define HW_DIVIDER_CLK_OFF()     HW_WRITE(PDN_SET2     ,0x0800)
/*MT6250*/ #define HW_FCS_CLK_ON()          HW_WRITE(PDN_CLR2     ,0x1000)
/*MT6250*/ #define HW_FCS_CLK_OFF()         HW_WRITE(PDN_SET2     ,0x1000)
#elif IS_CHIP_MT6236 || IS_CHIP_MT6256 || IS_CHIP_MT6251 || IS_CHIP_MT6255
/*MT6236~*/ #define HW_IRDBG_CLK_ON()       HW_WRITE(MD2G_PDN_CLR0,0x3000)
/*MT6236~*/ #define HW_IRDBG_CLK_OFF()      HW_WRITE(MD2G_PDN_SET0,0x3000)
/*MT6236~*/ #define HW_IRDMA_CLK_ON()       HW_WRITE(MD2G_PDN_CLR0,0x0040)
/*MT6236~*/ #define HW_IRDMA_CLK_OFF()      HW_WRITE(MD2G_PDN_SET0,0x0040)
/*MT6236~*/ #define HW_DIVIDER_CLK_ON()     HW_WRITE(MD2G_PDN_CLR2,0x0800)
/*MT6236~*/ #define HW_DIVIDER_CLK_OFF()    HW_WRITE(MD2G_PDN_SET2,0x0800)
/*MT6236~*/ #define HW_FCS_CLK_ON()         HW_WRITE(MD2G_PDN_CLR2,0x0040)
/*MT6236~*/ #define HW_FCS_CLK_OFF()        HW_WRITE(MD2G_PDN_SET2,0x0040)
#else
/*MT6229~*/ #define HW_IRDMA_CLK_ON()       HW_WRITE(PDN_CLR0,     0x0040)
/*MT6229~*/ #define HW_IRDMA_CLK_OFF()      HW_WRITE(PDN_SET0,     0x0040)
/*MT6229~*/ #define HW_DIVIDER_CLK_ON()     HW_WRITE(PDN_CLR2,     0x0800)
/*MT6229~*/ #define HW_DIVIDER_CLK_OFF()    HW_WRITE(PDN_SET2,     0x0800)
/*MT6229~*/ #define HW_FCS_CLK_ON()         HW_WRITE(PDN_CLR2,     0x0040)
/*MT6229~*/ #define HW_FCS_CLK_OFF()        HW_WRITE(PDN_SET2,     0x0040)
#endif

#if IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define L1D_MODEMSYS_SET_APB_RD_LATENCY()   HW_WRITE(MPERI_APB_R2T , 0x00000000)
#define L1D_MODEMSYS_SET_APB_WT_LATENCY()   HW_WRITE(MPERI_APB_W2T , 0x00000000)
#define L1D_MODEMSYS_SET_APB_PROTOCOL()     HW_WRITE(MPERI_APB3_SEL, 0x00000080) // BSI needs APB 2.0 protocol
#endif

#if IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define L1D_MODEMSYS_BUS_CG_ENA()          {uint32 d32 = HW_READ(MPERI_PWR_AWARE );  HW_WRITE(MPERI_PWR_AWARE, (d32|(1<<2)));}
#define L1D_MD2GSYS_BUS_CG_ENA()           {uint16 d16 = HW_READ(MD2GSYS_AHB_CON0);  HW_WRITE(MD2GSYS_AHB_CON0,(d16|(1<<9)));}
#endif

#if IS_RTX_BUFFER_POWER_CTRL_SUPPORT
#define L1D_RX_BUF_POWER_ON()              {HW_WRITE(MD2G_PDN_CLR0,0x0100);  WAIT_TIME_QB(1);}
#define L1D_RX_BUF_POWER_OFF()             {HW_WRITE(MD2G_PDN_SET0,0x0100);                  }
#define L1D_TX_BUF_POWER_ON()              {HW_WRITE(MD2G_PDN_CLR0,0x0200);  WAIT_TIME_QB(1);}
#define L1D_TX_BUF_POWER_OFF()             {HW_WRITE(MD2G_PDN_SET0,0x0200);                  }
#else
#define L1D_RX_BUF_POWER_ON()
#define L1D_RX_BUF_POWER_OFF()
#define L1D_TX_BUF_POWER_ON()
#define L1D_TX_BUF_POWER_OFF()
#endif

#if IS_CHIP_MT6256_S00
#define L1D_CSD_BUS_POWER_ON()
#define L1D_CSD_BUS_POWER_OFF()
#elif IS_CHIP_MT6256
#define L1D_CSD_BUS_POWER_ON()   HW_WRITE(MD2G_PDN_CLR0,0x4000)
#define L1D_CSD_BUS_POWER_OFF()  HW_WRITE(MD2G_PDN_SET0,0x4000)
#else
#define L1D_CSD_BUS_POWER_ON()
#define L1D_CSD_BUS_POWER_OFF()
#endif

#if !IS_CHIP_MT6225_AND_LATTER_VERSION && !IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
#define DPLL                     ((APBADDR)  (CONFIG_base+0x0104))      /* DSP Clock Select (13MxN)                      */
#endif

#if IS_CHIP_MT6573
#define RG_CK_ALW_ON             ((APBADDR)  (APCONFIG_base+0x0124))    /* Global Con Clock Gated Control Register       */
#define WAY_CON0                 ((APBADDR32)(CONFIG_base+0x0420))      /* Way Control 0 Register                        */
#define MD_SLPPRT_BUS            ((APBADDR32)(CONFIG_base+0x0430))      /* MD Bus Sleep Protect Control Register         */

#elif IS_CHIP_MT6575
#define INFRA_BUS_CON0           ((APBADDR32)(CONFIG_base+0x0548))      /* INFRASYS Bus Configuration Register 0         */
#define INFRA_BUS_CON1           ((APBADDR32)(CONFIG_base+0x054C))      /* INFRASYS Bus Configuration Register 1         */
#define BUS_PROTECT_READY        ((APBADDR32)(CONFIG_base+0x0608))      /* Bus Protect Ready Register                    */
#define ACIF_CON0                ((APBADDR)  (CONFIG_base+0x0700))      /* IO Pad Output Control Register 0              */
#define RG_CK_ALW_ON             ((APBADDR)  (CONFIG_base+0x0824))      /* Global Con Clock Gated Control Register       */

#elif IS_CHIP_MT6276
#define INFRA_BUS_CON0           ((APBADDR32)(CONFIG_base+0x0548))      /* INFRASYS Bus Configuration Register 0         */
#define INFRA_BUS_CON1           ((APBADDR32)(CONFIG_base+0x054C))      /* INFRASYS Bus Configuration Register 1         */
#define BUS_PROTECT_READY        ((APBADDR32)(CONFIG_base+0x0608))      /* Bus Protect Ready Register                    */
#define ACIF_CON0                ((APBADDR)  (CONFIG_base+0x0700))      /* IO Pad Output Control Register 0              */
#define RG_CK_ALW_ON             ((APBADDR)  (CONFIG_base+0x0824))      /* Global Con Clock Gated Control Register       */
#define MPLL_CON0                ((APBADDR)  (MIX_ABB_base+0x0140))
#define MPLL_CON1                ((APBADDR)  (MIX_ABB_base+0x0144))
#define MPLL_CON2                ((APBADDR)  (MIX_ABB_base+0x0148))
#define MPLL_CON3                ((APBADDR)  (MIX_ABB_base+0x014C))
#define DPLL_CON0                ((APBADDR)  (MIX_ABB_base+0x0180))
#define DPLL_CON1                ((APBADDR)  (MIX_ABB_base+0x0184))
#define DPLL_CON2                ((APBADDR)  (MIX_ABB_base+0x0188))
#define DPLL_CON3                ((APBADDR)  (MIX_ABB_base+0x018C))
#define EPLL_CON0                ((APBADDR)  (MIX_ABB_base+0x01C0))
#define EPLL_CON1                ((APBADDR)  (MIX_ABB_base+0x01C4))
#define EPLL_CON2                ((APBADDR)  (MIX_ABB_base+0x01C8))
#define EPLL_CON3                ((APBADDR)  (MIX_ABB_base+0x01CC))
#define TDMA_FHCON0              ((APBADDR)  (MIX_ABB_base+0x0D00))
#define TDMA_FHCON1              ((APBADDR)  (MIX_ABB_base+0x0D04))
#define TDMA_FHCON2              ((APBADDR)  (MIX_ABB_base+0x0D08))
#define TDMA_FHCON3              ((APBADDR)  (MIX_ABB_base+0x0D0C))
#define TDMA_FHCON4              ((APBADDR)  (MIX_ABB_base+0x0D10))
#define TDMA_FHCON5              ((APBADDR)  (MIX_ABB_base+0x0D14))
#define TDMA_FHCON6              ((APBADDR)  (MIX_ABB_base+0x0D18))
#define TDMA_FHCON7              ((APBADDR)  (MIX_ABB_base+0x0D1C))
#define TDMA_FHCON10             ((APBADDR)  (MIX_ABB_base+0x0D28))
#define TDMA_FHCON11             ((APBADDR)  (MIX_ABB_base+0x0D2C))
#define TDMA_FHCON(m)            ((APBADDR)  (MIX_ABB_base+0x0D00+(m)*4))

#elif IS_CHIP_MT6516
#define DSPCLK_CON               ((APBADDR)(MD2GCONFG_base+0x040))      /* DSP Clock Control Register                    */
#define SLEEP_CON                ((APBADDR)(CONFIG_base+0x204))
#define MCUCLK_CON               ((APBADDR)(CONFIG_base+0x208))         /* MCU Clock Control Register                    */
#define ISO_CON                  ((APBADDR)(CONFIG_base+0x300))         /* MD2GSYS Isolation Control Register            */
#define PWR_CON                  ((APBADDR)(CONFIG_base+0x304))         /* MD2GSYS PDN Control Register                  */
#define MEM_PDN                  ((APBADDR)(CONFIG_base+0x308))         /* MD2GSYS Memory PDN Control Register           */
#define IN_ISO_EN                ((APBADDR)(CONFIG_base+0x30C))         /* MD2GSYS input Isolation Control Register      */
#define RGU_USRST2               ((APBADDR)(RGU_base   +0x028))         /* RGU user-defined reset 2 only for MD2G reset  */

#elif IS_CHIP_MT6268
#define PDN_CON                  ((APBADDR)(MIXED_base +0x010))         /* Power-down control                            */
#define CLK_CON                  ((APBADDR)(MIXED_base +0x014))         /* Clock Control Register                        */
#define SLEEP_CON                ((APBADDR)(CONFIG_base+0x114))
#define MCUCLK_CON               ((APBADDR)(CONFIG_base+0x118))         /* MCU Clock Control Register                    */
#define MCUCLK_CON2              ((APBADDR)(CONFIG_base+0x11C))         /* MCU Clock Control Register 2                  */
#define GCLOCK_CON               ((APBADDR)(CONFIG_base+0x120))         /* MCU Global Clock Control Register             */
#define PWR_CON                  ((APBADDR)(CONFIG_base+0x130))         /* MCU Power Down Control Register               */
#define GDSPCLK_CON              ((APBADDR)(GCONFG_base+0x11C))         /* DSP Clock Control Register                    */
#define DSPCLK_CON               GDSPCLK_CON

#elif IS_CHIP_TK6516
#define SLEEP_CON                ((APBADDR)(CONFIG_base+0x204))
#define MCUCLK_CON               ((APBADDR)(CONFIG_base+0x208))         /* MCU Clock Control Register                    */

#elif IS_CHIP_MT6238
#define PLL                      ((APBADDR)(PLL_base+0x000))            /* MPLL(DPLL, UPLL) Frequency Register1          */
#define PLL2                     ((APBADDR)(PLL_base+0x004))            /* MPLL(DPLL, UPLL) Frequency Register2          */
#define CPLL                     ((APBADDR)(PLL_base+0x008))            /* CPLL Control Register1                        */
#define CPLL2                    ((APBADDR)(PLL_base+0x00C))            /* CPLL Control Register2                        */
#define TPLL                     ((APBADDR)(PLL_base+0x010))            /* TPLL Control Register1                        */
#define TPLL2                    ((APBADDR)(PLL_base+0x014))            /* TPLL Control Register2                        */
#define CLK_CON                  ((APBADDR)(PLL_base+0x018))            /* Clock Control Register                        */
#define PDN_CON                  ((APBADDR)(PLL_base+0x01C))            /* Power-down control                            */
#define SLEEP_CON                ((APBADDR)(CONFIG_base+0x114))
#define MCUCLK_CON               ((APBADDR)(CONFIG_base+0x118))         /* MCU Clock Control Register                    */
#define DSPCLK_CON               ((APBADDR)(CONFIG_base+0x11C))         /* DSP Clock Control Register                    */

#elif IS_CHIP_MT6225_AND_LATTER_VERSION || IS_CHIP_MT6223
#define CLK_CON                  ((APBADDR)(CONFIG_base+0x110))
#define SLEEP_CON                ((APBADDR)(CONFIG_base+0x114))
#define MCUCLK_CON               ((APBADDR)(CONFIG_base+0x118))         /* MCU Clock Control Register                    */
#define DSPCLK_CON               ((APBADDR)(CONFIG_base+0x11C))

#elif IS_CHIP_MT6253
#define XOSC_CON                 ((APBADDR)(PLL_CLKSQ_base+0x000))
#define CLKSQ_CON                ((APBADDR)(PLL_CLKSQ_base+0x100))
#define PLL_CON0                 ((APBADDR)(PLL_CLKSQ_base+0x200))
#define PLL_CON1                 ((APBADDR)(PLL_CLKSQ_base+0x204))      /* PLL Control Register 1                        */
#define UPLL_CON0                ((APBADDR)(PLL_CLKSQ_base+0x208))
#define UPLL_CON1                ((APBADDR)(PLL_CLKSQ_base+0x20C))
#define MPLL_CON0                ((APBADDR)(PLL_CLKSQ_base+0x210))
#define MPLL_CON1                ((APBADDR)(PLL_CLKSQ_base+0x214))
#define MPLL_TDMAWB01            ((APBADDR)(PLL_CLKSQ_base+0x220))
#define MPLL_TDMAWB23            ((APBADDR)(PLL_CLKSQ_base+0x224))
#define MPLL_TDMAWB45            ((APBADDR)(PLL_CLKSQ_base+0x228))
#define HW_VER                   ((APBADDR)(CONFIG_base+0x000))
#define HW_CODE                  ((APBADDR)(CONFIG_base+0x008))
#define SLEEP_CON                ((APBADDR)(CONFIG_base+0x114))
#define MCUCLK_CON               ((APBADDR)(CONFIG_base+0x118))         /* MCU Clock Control Register                    */
#define DSPCLK_CON               ((APBADDR)(CONFIG_base+0x11C))

#define MPLL_TDMAWB(n)           ((APBADDR)(PLL_CLKSQ_base+0x220+(4*(n))))
#define TDMA_FHSTR(n)            ((APBADDR)(TDMA_base+0x0320+(4*(n))))

   #if IS_CHIP_MT6252_S00
//S00 version doesn't support SPLL FH
   #elif IS_CHIP_MT6252
#define SPLL_TDMAWB01            ((APBADDR)(PLL_CLKSQ_base+0x240))
#define SPLL_TDMAWB23            ((APBADDR)(PLL_CLKSQ_base+0x244))
#define SPLL_TDMAWB45            ((APBADDR)(PLL_CLKSQ_base+0x248))
#define SPLL_TDMAWB(n)           ((APBADDR)(PLL_CLKSQ_base+0x240+(4*(n))))
#define SPLL_CON1                ((APBADDR)(PLL_CLKSQ_base+0x234))
   #endif

#elif IS_CHIP_MT6236
#define PDN_CON                  ((APBADDR)(MIXED_base+0x010))          /* Power-down control                            */
#define CLK_CON                  ((APBADDR)(MIXED_base+0x014))          /* Clock Control Register                        */
#define CLKSQ_CON                ((APBADDR)(PLL_base+0x100))            /* CLKSQ Control Register                        */
#define PLL_CON1                 ((APBADDR)(PLL_base+0x204))            /* MPLL(DPLL, UPLL) Frequency Register1          */
#define UPLL_CON1                ((APBADDR)(PLL_base+0x304))            /* UPLL Control Register                         */
#define MPLL_CON1                ((APBADDR)(PLL_base+0x404))            /* MPLL Control Register                         */
#define SLEEP_CON                ((APBADDR)(CONFIG_base+0x200))
#define MCUCLK_CON               ((APBADDR)(CONFIG_base+0x204))         /* MCU Clock Control Register                    */
#define MCUCLK_CON2              ((APBADDR)(CONFIG_base+0x208))         /* MCU Clock Control Register                    */
#define GCLOCK_CON               ((APBADDR)(CONFIG_base+0x20C))         /* MCU Global Clock Control Register             */
#define PWR_CON                  ((APBADDR)(CONFIG_base+0x300))         /* MCU Power Down Control Register               */
#define PWR_CON2                 ((APBADDR)(CONFIG_base+0x304))         /* MCUSYS memory power down control              */
#define APB_CON                  ((APBADDR)(CONFIG_base+0x404))         /* APB Bus Control Register                      */
#define SLEEP_SPI                ((APBADDR)(CONFIG_base+0x408))         /* SLEEP SPI Register                            */
#define DSPCLK_CON               ((APBADDR)(MD2GCONFG_base+0x040))      /* DSP Clock Control Register                    */

// MPLL FH
#define FH_CON0                  ((APBADDR)(PLL_base+0x800))            /*MPLL FH Control Register*/
#define FH_SETA0                 ((APBADDR)(PLL_base+0x810))            /* GSM priority 1 frequency setting Register     */
#define FH_SETA1                 ((APBADDR)(PLL_base+0x814))            /* GSM priority 1 frequency setting Register     */
#define FH_SETA2                 ((APBADDR)(PLL_base+0x818))            /* GSM priority 1 frequency setting Register     */
#define FH_SETA3                 ((APBADDR)(PLL_base+0x81C))            /* GSM priority 1 frequency setting Register     */
#define FH_SETA4                 ((APBADDR)(PLL_base+0x820))            /* GSM priority 1 frequency setting Register     */
#define FH_SETA5                 ((APBADDR)(PLL_base+0x824))            /* GSM priority 1 frequency setting Register     */
#define FH_SETB0                 ((APBADDR)(PLL_base+0x830))            /* GSM priority 2 frequency setting Register     */
#define FH_SETB1                 ((APBADDR)(PLL_base+0x834))            /* GSM priority 2 frequency setting Register     */
#define FH_SETB2                 ((APBADDR)(PLL_base+0x838))            /* GSM priority 2 frequency setting Register     */
#define FH_SETB3                 ((APBADDR)(PLL_base+0x83C))            /* GSM priority 2 frequency setting Register     */
#define FH_SETB4                 ((APBADDR)(PLL_base+0x840))            /* GSM priority 2 frequency setting Register     */
#define FH_SETB5                 ((APBADDR)(PLL_base+0x844))            /* GSM priority 2 frequency setting Register     */

#define TDMA_FHSTR(n)            ((APBADDR)(TDMA_base+0x0320+(4*(n))))
#define MPLL_TDMAWB(n)           ((APBADDR)(PLL_base+0x220+(4*(n))))
#define FH_SETA(n)               ((APBADDR)(PLL_base+0x810+(4*(n))))
#define FH_SETB(n)               ((APBADDR)(PLL_base+0x830+(4*(n))))

#elif IS_CHIP_MT6228 || IS_CHIP_MT6229 || IS_CHIP_MT6268T
#define UPLL                     ((APBADDR)(CONFIG_base+0x108))
#define CLK_CON                  ((APBADDR)(CONFIG_base+0x110))
#define SLEEP_CON                ((APBADDR)(CONFIG_base+0x114))
#define MCUCLK_CON               ((APBADDR)(CONFIG_base+0x118))         /* MCU Clock Control Register                    */
#define DSPCLK_CON               ((APBADDR)(CONFIG_base+0x11C))

#elif IS_CHIP_MT6256 || IS_CHIP_MT6251 || IS_CHIP_MT6255 || IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define DSPCLK_CON               ((APBADDR)(MD2GCONFG_base+0x040))      /* DSP Clock Control Register                    */

   #if IS_CHIP_MT6250
#define CLK_CONDE                ((APBADDR32)(CONFIG_base+0x0110))      /* Clock swiching group/type                     */
#define SLEEP_COND               ((APBADDR32)(CONFIG_base+0x0200))
#define TDMA_FHCON0              ((APBADDR)(MIXED_base+0x0500))
#define TDMA_FHCON1              ((APBADDR)(MIXED_base+0x0504))
#define TDMA_FHCON2              ((APBADDR)(MIXED_base+0x0508))
#define TDMA_FHCON3              ((APBADDR)(MIXED_base+0x050C))
#define TDMA_FHCON4              ((APBADDR)(MIXED_base+0x0510))
#define TDMA_FHCON5              ((APBADDR)(MIXED_base+0x0514))

   #elif IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
// Frequency hopping is controled by System Service.

   #elif IS_CHIP_MT6572
#define MIXED_base               PLL_MIXEDSYS_base
#define PLL_CLKSW_CKSEL0         ((APBADDR)(MIXED_base+0x0060))
#define TDMA_FHCON0              ((APBADDR)(MIXED_base+0x0500))
#define TDMA_FHCON1              ((APBADDR)(MIXED_base+0x0504))          /* For debug, not used                          */
#define TDMA_FHCON2              ((APBADDR)(MIXED_base+0x0508))
#define TDMA_FHCON3              ((APBADDR)(MIXED_base+0x050C))
#define TDMA_FHCON4              ((APBADDR)(MIXED_base+0x0510))
#define TDMA_FHCON5              ((APBADDR)(MIXED_base+0x0514))
#define TDMA_FHCON6              ((APBADDR)(MIXED_base+0x0518))
#define TDMA_FHCON7              ((APBADDR)(MIXED_base+0x051C))

   #elif IS_CHIP_MT6583_MD2
//#define PLL_base                 PLL_MIXEDSYS_base
#define MIXED_base               PLL_MIXEDSYS_base
#define PLL_CLKSW_CKSEL2         ((APBADDR)(MIXED_base+0x0068))
#define PLL_CLKSW_FDIV2          ((APBADDR)(MIXED_base+0x0078))
#define PLL_CLKSW_FDIV6          ((APBADDR)(MIXED_base+0x0088))
#define TDMA_FHCON0              ((APBADDR)(MIXED_base+0x0500))
#define TDMA_FHCON1              ((APBADDR)(MIXED_base+0x0504))          /* For debug, not used                           */
#define TDMA_FHCON2              ((APBADDR)(MIXED_base+0x0508))
#define TDMA_FHCON3              ((APBADDR)(MIXED_base+0x050C))
#define TDMA_FHCON4              ((APBADDR)(MIXED_base+0x0510))
#define TDMA_FHCON5              ((APBADDR)(MIXED_base+0x0514))

   #elif IS_CHIP_MT6583_MD1
//#define PLL_base                 PLL_MIXEDSYS_base
#define MIXED_base               PLL_MIXEDSYS_base
#define PLL_CLKSW_CKSEL0         ((APBADDR)(MIXED_base+0x0060))
#define PLL_CLKSW_FDIV0          ((APBADDR)(MIXED_base+0x0070))
#define PLL_CLKSW_FDIV6          ((APBADDR)(MIXED_base+0x0088))
#define TDMA_FHCON0              ((APBADDR)(MIXED_base+0x0500))
#define TDMA_FHCON1              ((APBADDR)(MIXED_base+0x0504))          /* For debug, not used                           */
#define TDMA_FHCON2              ((APBADDR)(MIXED_base+0x0508))
#define TDMA_FHCON3              ((APBADDR)(MIXED_base+0x050C))
#define TDMA_FHCON4              ((APBADDR)(MIXED_base+0x0510))
#define TDMA_FHCON5              ((APBADDR)(MIXED_base+0x0514))

   #elif IS_CHIP_MT6280
#define PLL_base                 MIX_ABB_base
#define MIXED_base               MIX_ABB_base
#define HW_CODE                  ((APBADDR  )(CONFIG_base+0x0008))
#define MD_TOP_CON               ((APBADDR32)(CONFIG_base+0x001C))
#define PLL_CLKSW_CKSEL0         ((APBADDR)(MIXED_base+0x0060))
#define PLL_CLKSW_FDIV0          ((APBADDR)(MIXED_base+0x0070))
#define PLL_CLKSW_FDIV6          ((APBADDR)(MIXED_base+0x0088))
#define TDMA_FHCON0              ((APBADDR)(MIXED_base+0x0500))
#define TDMA_FHCON1              ((APBADDR)(MIXED_base+0x0504))          /* For debug, not used                           */
#define TDMA_FHCON2              ((APBADDR)(MIXED_base+0x0508))
#define TDMA_FHCON3              ((APBADDR)(MIXED_base+0x050C))
#define TDMA_FHCON4              ((APBADDR)(MIXED_base+0x0510))
#define TDMA_FHCON5              ((APBADDR)(MIXED_base+0x0514))
#define TDMA_FHCON6              ((APBADDR)(MIXED_base+0x0518))
#define TDMA_FHCON7              ((APBADDR)(MIXED_base+0x051C))

   #elif IS_CHIP_MT6256 || IS_CHIP_MT6255
#define TDMA_FHSTR(n)            ((APBADDR)(TDMA_base+0x0320+(4*(n))))
#define HW_CODE                  ((APBADDR)(CONFIG_base+0x008))
#define SLEEP_CON                ((APBADDR)(CONFIG_base+0x200))         /* Sleep control register                        */
#define PWR_CON                  ((APBADDR32)(CONFIG_base+0x300))       /* MCU Power Down Control Register               */
#define PWR_CON2                 ((APBADDR32)(CONFIG_base+0x304))       /* MCUSYS memory power down control              */
#define SYSBUS_CON               ((APBADDR32)(CONFIG_base+0x4A0))       /* System Bus Control Register                   */
#define PLL_CON1                 ((APBADDR)(PLL_base+0x0104))           /* MPLLSEL can select CLK source of MCU, bus and DSP */
#define TDMA_FHCON0              ((APBADDR)(PLL_base+0x0800))
#define TDMA_FHCON1              ((APBADDR)(PLL_base+0x0804))
#define TDMA_FHCON2              ((APBADDR)(PLL_base+0x0808))
#define TDMA_FHCON3              ((APBADDR)(PLL_base+0x080C))
#define TDMA_FHCON4              ((APBADDR)(PLL_base+0x0810))
#define TDMA_FHCON5              ((APBADDR)(PLL_base+0x0814))
#define TDMA_FHCON6              ((APBADDR)(PLL_base+0x0818))
#define TDMA_FHCON7              ((APBADDR)(PLL_base+0x081C))
#define TDMA_FHCON(m)            ((APBADDR)(PLL_base+0x0800+(m)*4))
#define MNPLL_FHSET(m,n)         ((APBADDR)(PLL_base+0x0900+(m)*16 +(n)*4 )) /* m:0~5, n:0~3 */
#define EFPLL_FHSET(m,n)         ((APBADDR)(PLL_base+0x0980+(m)*16 +(n)*4 )) /* m:0~5, n:0~3 */

   #elif IS_CHIP_MT6251
#define TDMA_FHSTR(n)            ((APBADDR)(TDMA_base+0x0320+(4*(n))))
#define SLEEP_CON                ((APBADDR)(CONFIG_base+0x114))
#define PWR_CON                  ((APBADDR)(CONFIG_base+0x360))
#define PWR_CON2                 ((APBADDR)(CONFIG_base+0x364))
#define CLKSQ_CON0               ((APBADDR)(PLL_base+0x0000))
#define PLL_CON1                 ((APBADDR)(PLL_base+0x0104))           /* MPLLSEL can select CLK source of MCU, bus and DSP */
#define MPLL_CON1                ((APBADDR)(PLL_base+0x0304))
#define TDMA_FHCON0              ((APBADDR)(PLL_base+0x0800))
#define TDMA_FHCON1              ((APBADDR)(PLL_base+0x0804))
#define TDMA_FHCON4              ((APBADDR)(PLL_base+0x0810))
#define TDMA_FHCON5              ((APBADDR)(PLL_base+0x0814))

#define MPLL_FHDDS0              ((APBADDR)(PLL_base+0x0830))
#define MPLL_FHDDS1              ((APBADDR)(PLL_base+0x0834))
#define MPLL_FHDDS2              ((APBADDR)(PLL_base+0x0838))
#define MPLL_FHDDS3              ((APBADDR)(PLL_base+0x083C))
#define MPLL_FHDDS4              ((APBADDR)(PLL_base+0x0840))
#define MPLL_FHDDS5              ((APBADDR)(PLL_base+0x0844))
#define MPLL_FHDDS(m)            ((APBADDR)(PLL_base+0x0830+(m)*4))     /* m: 0-5 */
#define CLKSQ_CON                CLKSQ_CON0
   #endif
#else
#define CLK_CON                  ((APBADDR)(CONFIG_base+0x108))         /* Clock Switch                                  */
                                                                        /* bit 0 : 2x clock divider                      */
                                                                        /* bit 1 : MCU clock switch                      */
                                                                        /* bit 2 : DSP clock switch                      */
                                                                        /* bit 3 : UART clock switch                     */
#define SLEEP_CON                ((APBADDR)(CONFIG_base+0x10C))         /* Sleep Control Register                        */
#define UPLL                     ((APBADDR)(CONFIG_base+0x110))         /*                                               */
   #if IS_CHIP_MT6217 || IS_CHIP_MT6227
#define MCUCLK_CON               ((APBADDR)(CONFIG_base+0x114))         /* MCU Clock Control */
   #endif
#endif

#ifndef DMA_TEST_ENABLE
#define DMA_GLBSTA               ((APBADDR32)(DMA_base+0x0000))         /* DMA Global Status Register                    */
#endif

// For LCDFH, should be removed !!!
#if IS_CHIP_MT6252
#define LCD_PCNF0                ((APBADDR32)(LCD_base+0x30))           /* LCD Clock Control Register                    */
#define LCD_WROICON              ((APBADDR32)(LCD_base+0x80))           /* LCD Clock Control Register                    */
#else
#define LCD_PCNF0                ((APBADDR32)(LCD_base+0x18))           /* LCD Clock Control Register                    */
#define LCD_WROICON              ((APBADDR32)(LCD_base+0x50))           /* LCD Clock Control Register                    */
#endif
/* --------------------------------------------------------------------------------------------------------------------- */

/*==========================================*\
|* General Purpose Inputs/Outputs Registers *|
\* =========================================*/
#if IS_FPGA_TARGET || IS_CHIP_MT6208
/* ===================================================================================================================== */
/* for MT6208                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GPIO_DIR                 ((APBADDR)(GPIO_base+0x0000*2*2))      /* GPIO Direction Register                       */
#define GPIO_DOUT                ((APBADDR)(GPIO_base+0x0001*2*2))      /* GPIO Data Output Register                     */
#define GPIO_DIN                 ((APBADDR)(GPIO_base+0x0002*2*2))      /* GPIO Data Input Register                      */
#define GPIO_MODE1               ((APBADDR)(GPIO_base+0x0003*2*2))      /* GPIO Mode 1 Register                          */
#define GPIO_MODE2               ((APBADDR)(GPIO_base+0x0004*2*2))      /* GPIO Mode 2 Register                          */
#define GPIO_DIO                 ((APBADDR)(GPIO_base+0x0006*2*2))      /* GPI Data Input & GPO Data Output Register     */
#define GPIO_MODE3               ((APBADDR)(GPIO_base+0x0007*2*2))      /* GPI & GPO Mode Register                       */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_CHIP_MT6205
/* ===================================================================================================================== */
/* for MT6205                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GPIO_DIR1                ((APBADDR)(GPIO_base+0x0000))          /* GPIO Direction Register 1                     */
#define GPIO_DIR2                ((APBADDR)(GPIO_base+0x0004))          /* GPIO Direction Register 2                     */
#define GPIO_PULLEN1             ((APBADDR)(GPIO_base+0x0008))          /* GPIO Pull-up/Pull-down Enable Register 1      */
#define GPIO_PULLEN2             ((APBADDR)(GPIO_base+0x000C))          /* GPIO Pull-up/Pull-down Enable Register 2      */
#define GPIO_DOUT1               ((APBADDR)(GPIO_base+0x0010))          /* GPIO Data Output Register 1                   */
#define GPIO_DOUT2               ((APBADDR)(GPIO_base+0x0014))          /* GPIO Data Output Register 2                   */
#define GPIO_DIN1                ((APBADDR)(GPIO_base+0x0018))          /* GPIO Data input Register 1                    */
#define GPIO_DIN2                ((APBADDR)(GPIO_base+0x001C))          /* GPIO Data input Register 2                    */
#define GPIO_DOUT                ((APBADDR)(GPIO_base+0x0020))          /* GPO  Data Output Register                     */
#define GPIO_MODE1               ((APBADDR)(GPIO_base+0x0024))          /* GPIO Mode Control Register 1                  */
#define GPIO_MODE2               ((APBADDR)(GPIO_base+0x0028))          /* GPIO Mode Control Register 2                  */
#define GPIO_MODE3               ((APBADDR)(GPIO_base+0x002C))          /* GPIO Mode Control Register 3                  */
#define GPIO_MODE4               ((APBADDR)(GPIO_base+0x0030))          /* GPIO Mode Control Register 4                  */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_CHIP_MT6218A
/* ===================================================================================================================== */
/* for MT6218A                                                                                                           */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GPIO_DIR1                ((APBADDR)(GPIO_base+0x0000))          /* GPIO Direction Register 1                     */
#define GPIO_DIR2                ((APBADDR)(GPIO_base+0x0010))          /* GPIO Direction Register 2                     */
#define GPIO_DIR3                ((APBADDR)(GPIO_base+0x0020))          /* GPIO Direction Register 3                     */
#define GPIO_PULLEN1             ((APBADDR)(GPIO_base+0x0030))          /* GPIO Pull-up/Pull-down Enable Register 1      */
#define GPIO_PULLEN2             ((APBADDR)(GPIO_base+0x0040))          /* GPIO Pull-up/Pull-down Enable Register 2      */
#define GPIO_PULLEN3             ((APBADDR)(GPIO_base+0x0050))          /* GPIO Pull-up/Pull-down Enable Register 3      */
#define GPIO_DOUT1               ((APBADDR)(GPIO_base+0x0060))          /* GPIO Data Output Register 1                   */
#define GPIO_DOUT2               ((APBADDR)(GPIO_base+0x0070))          /* GPIO Data Output Register 2                   */
#define GPIO_DOUT3               ((APBADDR)(GPIO_base+0x0080))          /* GPIO Data Output Register 3                   */
#define GPIO_DIN1                ((APBADDR)(GPIO_base+0x0090))          /* GPIO Data input Register 1                    */
#define GPIO_DIN2                ((APBADDR)(GPIO_base+0x0094))          /* GPIO Data input Register 2                    */
#define GPIO_DIN3                ((APBADDR)(GPIO_base+0x0098))          /* GPIO Data input Register 3                    */
#define GPO_DOUT                 ((APBADDR)(GPIO_base+0x00A0))          /* GPO  Data Output Register                     */
#define GPIO_MODE1               ((APBADDR)(GPIO_base+0x00B0))          /* GPIO Mode Control Register 1                  */
#define GPIO_MODE2               ((APBADDR)(GPIO_base+0x00C0))          /* GPIO Mode Control Register 2                  */
#define GPIO_MODE3               ((APBADDR)(GPIO_base+0x00D0))          /* GPIO Mode Control Register 3                  */
#define GPIO_MODE4               ((APBADDR)(GPIO_base+0x00E0))          /* GPIO Mode Control Register 4                  */
#define GPIO_MODE5               ((APBADDR)(GPIO_base+0x00F0))          /* GPIO Mode Control Register 5                  */
#define GPIO_MODE6               ((APBADDR)(GPIO_base+0x0100))          /* GPIO Mode Control Register 6                  */
#define GPO_MODE                 ((APBADDR)(GPIO_base+0x0110))          /* GPIO Mode Control Register 7                  */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_CHIP_MT6218B
/* ===================================================================================================================== */
/* for MT6218B                                                                                                           */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GPIO_DIR1                ((APBADDR)(GPIO_base+0x0000))          /* GPIO Direction Register 1                     */
#define GPIO_DIR2                ((APBADDR)(GPIO_base+0x0010))          /* GPIO Direction Register 2                     */
#define GPIO_DIR3                ((APBADDR)(GPIO_base+0x0020))          /* GPIO Direction Register 3                     */
#define GPIO_PULLEN1             ((APBADDR)(GPIO_base+0x0030))          /* GPIO Pull-up/Pull-down Enable Register 1      */
#define GPIO_PULLEN2             ((APBADDR)(GPIO_base+0x0040))          /* GPIO Pull-up/Pull-down Enable Register 2      */
#define GPIO_PULLEN3             ((APBADDR)(GPIO_base+0x0050))          /* GPIO Pull-up/Pull-down Enable Register 3      */
#define GPIO_DINV1               ((APBADDR)(GPIO_base+0x0060))          /* Register 1                                    */
#define GPIO_DINV2               ((APBADDR)(GPIO_base+0x0070))          /* Register 2                                    */
#define GPIO_DINV3               ((APBADDR)(GPIO_base+0x0080))          /* Register 3                                    */
#define GPIO_DOUT1               ((APBADDR)(GPIO_base+0x0090))          /* GPIO Data Output Register 1                   */
#define GPIO_DOUT2               ((APBADDR)(GPIO_base+0x00A0))          /* GPIO Data Output Register 2                   */
#define GPIO_DOUT3               ((APBADDR)(GPIO_base+0x00B0))          /* GPIO Data Output Register 3                   */
#define GPIO_DIN1                ((APBADDR)(GPIO_base+0x00C0))          /* GPIO Data input  Register 1                   */
#define GPIO_DIN2                ((APBADDR)(GPIO_base+0x00D0))          /* GPIO Data input  Register 2                   */
#define GPIO_DIN3                ((APBADDR)(GPIO_base+0x00E0))          /* GPIO Data input  Register 3                   */
#define GPO_DOUT                 ((APBADDR)(GPIO_base+0x00F0))          /* GPO  Data Output Register                     */
#define GPIO_MODE1               ((APBADDR)(GPIO_base+0x0100))          /* GPIO Mode Control Register 1                  */
#define GPIO_MODE2               ((APBADDR)(GPIO_base+0x0110))          /* GPIO Mode Control Register 2                  */
#define GPIO_MODE3               ((APBADDR)(GPIO_base+0x0120))          /* GPIO Mode Control Register 3                  */
#define GPIO_MODE4               ((APBADDR)(GPIO_base+0x0130))          /* GPIO Mode Control Register 4                  */
#define GPIO_MODE5               ((APBADDR)(GPIO_base+0x0140))          /* GPIO Mode Control Register 5                  */
#define GPIO_MODE6               ((APBADDR)(GPIO_base+0x0150))          /* GPIO Mode Control Register 6                  */
#define GPO_MODE                 ((APBADDR)(GPIO_base+0x0160))          /* GPIO Mode Control Register 7                  */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_CHIP_MT6219 || IS_CHIP_MT6227 || IS_CHIP_MT6225_AND_LATTER_VERSION || IS_CHIP_MT6223
/* ===================================================================================================================== */
/* for MT6219                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GPIO_DIR1                ((APBADDR)(GPIO_base+0x0000))          /* GPIO Direction Register 1                     */
#define GPIO_DIR2                ((APBADDR)(GPIO_base+0x0010))          /* GPIO Direction Register 2                     */
#define GPIO_DIR3                ((APBADDR)(GPIO_base+0x0020))          /* GPIO Direction Register 3                     */
#define GPIO_DIR4                ((APBADDR)(GPIO_base+0x0030))          /* GPIO Direction Register 4                     */
#define GPIO_PULLEN1             ((APBADDR)(GPIO_base+0x0040))          /* GPIO Pull-up/Pull-down Enable Register 1      */
#define GPIO_PULLEN2             ((APBADDR)(GPIO_base+0x0050))          /* GPIO Pull-up/Pull-down Enable Register 2      */
#define GPIO_PULLEN3             ((APBADDR)(GPIO_base+0x0060))          /* GPIO Pull-up/Pull-down Enable Register 3      */
#define GPIO_PULLEN4             ((APBADDR)(GPIO_base+0x0070))          /* GPIO Pull-up/Pull-down Enable Register 4      */
#define GPIO_DINV1               ((APBADDR)(GPIO_base+0x0080))          /* Register 1                                    */
#define GPIO_DINV2               ((APBADDR)(GPIO_base+0x0090))          /* Register 2                                    */
#define GPIO_DINV3               ((APBADDR)(GPIO_base+0x00A0))          /* Register 3                                    */
#define GPIO_DINV4               ((APBADDR)(GPIO_base+0x00B0))          /* Register 4                                    */
#define GPIO_DOUT1               ((APBADDR)(GPIO_base+0x00C0))          /* GPIO Data Output Register 1                   */
#define GPIO_DOUT2               ((APBADDR)(GPIO_base+0x00D0))          /* GPIO Data Output Register 2                   */
#define GPIO_DOUT3               ((APBADDR)(GPIO_base+0x00E0))          /* GPIO Data Output Register 3                   */
#define GPIO_DOUT4               ((APBADDR)(GPIO_base+0x00F0))          /* GPIO Data Output Register 4                   */
#define GPIO_DIN1                ((APBADDR)(GPIO_base+0x0100))          /* GPIO Data input Register 1                    */
#define GPIO_DIN2                ((APBADDR)(GPIO_base+0x0110))          /* GPIO Data input Register 2                    */
#define GPIO_DIN3                ((APBADDR)(GPIO_base+0x0120))          /* GPIO Data input Register 3                    */
#define GPIO_DIN4                ((APBADDR)(GPIO_base+0x0130))          /* GPIO Data input Register 4                    */
#define GPO_DOUT                 ((APBADDR)(GPIO_base+0x0140))          /* GPO  Data Output Register                     */
#define GPIO_MODE1               ((APBADDR)(GPIO_base+0x0150))          /* GPIO Mode Control Register 1                  */
#define GPIO_MODE2               ((APBADDR)(GPIO_base+0x0160))          /* GPIO Mode Control Register 2                  */
#define GPIO_MODE3               ((APBADDR)(GPIO_base+0x0170))          /* GPIO Mode Control Register 3                  */
#define GPIO_MODE4               ((APBADDR)(GPIO_base+0x0180))          /* GPIO Mode Control Register 4                  */
#define GPIO_MODE5               ((APBADDR)(GPIO_base+0x0190))          /* GPIO Mode Control Register 5                  */
#define GPIO_MODE6               ((APBADDR)(GPIO_base+0x01A0))          /* GPIO Mode Control Register 6                  */
#define GPIO_MODE7               ((APBADDR)(GPIO_base+0x01B0))          /* GPIO Mode Control Register 7                  */
#define GPO_MODE                 ((APBADDR)(GPIO_base+0x01C0))          /* GPO Mode Control Register                     */
   #if IS_CHIP_MT6223  /*GPO are removed in MT6223*/
#undef GPO_DOUT                                                         /* GPO  Data Output Register                     */
#undef GPO_MODE                                                         /* GPO Mode Control Register                     */
   #endif
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_CHIP_MT6228 || IS_CHIP_MT6229 || IS_CHIP_MT6268T || IS_CHIP_MT6268T_DMAC
/* ===================================================================================================================== */
/* for MT6218B                                                                                                           */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GPIO_DIR1                ((APBADDR)(GPIO_base+0x0000))          /* GPIO Direction Register 1                     */
#define GPIO_DIR2                ((APBADDR)(GPIO_base+0x0010))          /* GPIO Direction Register 2                     */
#define GPIO_DIR3                ((APBADDR)(GPIO_base+0x0020))          /* GPIO Direction Register 3                     */
#define GPIO_DIR4                ((APBADDR)(GPIO_base+0x0030))          /* GPIO Direction Register 4                     */
#define GPIO_DIR5                ((APBADDR)(GPIO_base+0x0040))          /* GPIO Direction Register 5                     */
#define GPIO_PULLEN1             ((APBADDR)(GPIO_base+0x0050))          /* GPIO Pull-up/Pull-down Enable Register 1      */
#define GPIO_PULLEN2             ((APBADDR)(GPIO_base+0x0060))          /* GPIO Pull-up/Pull-down Enable Register 2      */
#define GPIO_PULLEN3             ((APBADDR)(GPIO_base+0x0070))          /* GPIO Pull-up/Pull-down Enable Register 3      */
#define GPIO_PULLEN4             ((APBADDR)(GPIO_base+0x0080))          /* GPIO Pull-up/Pull-down Enable Register 4      */
#define GPIO_PULLEN5             ((APBADDR)(GPIO_base+0x0090))          /* GPIO Pull-up/Pull-down Enable Register 4      */
#define GPIO_DINV1               ((APBADDR)(GPIO_base+0x00A0))          /* Register 1                                    */
#define GPIO_DINV2               ((APBADDR)(GPIO_base+0x00B0))          /* Register 2                                    */
#define GPIO_DINV3               ((APBADDR)(GPIO_base+0x00C0))          /* Register 3                                    */
#define GPIO_DINV4               ((APBADDR)(GPIO_base+0x00D0))          /* Register 4                                    */
#define GPIO_DINV5               ((APBADDR)(GPIO_base+0x00E0))          /* Register 4                                    */
#define GPIO_DOUT1               ((APBADDR)(GPIO_base+0x00F0))          /* GPIO Data Output Register 1                   */
#define GPIO_DOUT2               ((APBADDR)(GPIO_base+0x0100))          /* GPIO Data Output Register 2                   */
#define GPIO_DOUT3               ((APBADDR)(GPIO_base+0x0110))          /* GPIO Data Output Register 3                   */
#define GPIO_DOUT4               ((APBADDR)(GPIO_base+0x0120))          /* GPIO Data Output Register 4                   */
#define GPIO_DOUT5               ((APBADDR)(GPIO_base+0x0130))          /* GPIO Data Output Register 4                   */
#define GPIO_DIN1                ((APBADDR)(GPIO_base+0x0140))          /* GPIO Data input Register 1                    */
#define GPIO_DIN2                ((APBADDR)(GPIO_base+0x0150))          /* GPIO Data input Register 2                    */
#define GPIO_DIN3                ((APBADDR)(GPIO_base+0x0160))          /* GPIO Data input Register 3                    */
#define GPIO_DIN4                ((APBADDR)(GPIO_base+0x0170))          /* GPIO Data input Register 4                    */
#define GPIO_DIN5                ((APBADDR)(GPIO_base+0x0180))          /* GPIO Data input Register 4                    */
#define GPO_DOUT                 ((APBADDR)(GPIO_base+0x0190))          /* GPO  Data Output Register                     */
#define GPIO_MODE1               ((APBADDR)(GPIO_base+0x01A0))          /* GPIO Mode Control Register 1                  */
#define GPIO_MODE2               ((APBADDR)(GPIO_base+0x01B0))          /* GPIO Mode Control Register 2                  */
#define GPIO_MODE3               ((APBADDR)(GPIO_base+0x01C0))          /* GPIO Mode Control Register 3                  */
#define GPIO_MODE4               ((APBADDR)(GPIO_base+0x01D0))          /* GPIO Mode Control Register 4                  */
#define GPIO_MODE5               ((APBADDR)(GPIO_base+0x01E0))          /* GPIO Mode Control Register 5                  */
#define GPIO_MODE6               ((APBADDR)(GPIO_base+0x01F0))          /* GPIO Mode Control Register 6                  */
#define GPIO_MODE7               ((APBADDR)(GPIO_base+0x0200))          /* GPIO Mode Control Register 6                  */
#define GPIO_MODE8               ((APBADDR)(GPIO_base+0x0210))          /* GPIO Mode Control Register 6                  */
#define GPIO_MODE9               ((APBADDR)(GPIO_base+0x0220))          /* GPIO Mode Control Register 6                  */
#define GPIO_MODE10              ((APBADDR)(GPIO_base+0x0230))          /* GPIO Mode Control Register 6                  */
#define GPO_MODE1                ((APBADDR)(GPIO_base+0x0240))          /* GPIO Mode Control Register 6                  */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_CHIP_MT6238 || IS_CHIP_MT6268
/* ===================================================================================================================== */
/* for MT6238                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GPIO_DIR1                ((APBADDR)(GPIO_base+0x0000))          /* GPIO Direction Register 1                     */
#define GPIO_DIR2                ((APBADDR)(GPIO_base+0x0040))          /* GPIO Direction Register 2                     */
#define GPIO_DIR3                ((APBADDR)(GPIO_base+0x0080))          /* GPIO Direction Register 3                     */
#define GPIO_DIR4                ((APBADDR)(GPIO_base+0x00C0))          /* GPIO Direction Register 4                     */
#define GPIO_DIR5                ((APBADDR)(GPIO_base+0x0100))          /* GPIO Direction Register 5                     */
#define GPIO_DIR6                ((APBADDR)(GPIO_base+0x0140))          /* GPIO Direction Register 6                     */
   #if IS_CHIP_MT6268
#define GPIO_DIR7                ((APBADDR)(GPIO_base+0x0180))          /* GPIO Direction Register 7                     */
   #endif
#define GPIO_PULLEN1             ((APBADDR)(GPIO_base+0x0200))          /* GPIO Pull-up/Pull-down Enable Register 1      */
#define GPIO_PULLEN2             ((APBADDR)(GPIO_base+0x0240))          /* GPIO Pull-up/Pull-down Enable Register 2      */
#define GPIO_PULLEN3             ((APBADDR)(GPIO_base+0x0280))          /* GPIO Pull-up/Pull-down Enable Register 3      */
#define GPIO_PULLEN4             ((APBADDR)(GPIO_base+0x02C0))          /* GPIO Pull-up/Pull-down Enable Register 4      */
#define GPIO_PULLEN5             ((APBADDR)(GPIO_base+0x0300))          /* GPIO Pull-up/Pull-down Enable Register 5      */
#define GPIO_PULLEN6             ((APBADDR)(GPIO_base+0x0340))          /* GPIO Pull-up/Pull-down Enable Register 6      */
   #if IS_CHIP_MT6268
#define GPIO_PULLEN7             ((APBADDR)(GPIO_base+0x0380))          /* GPIO Pull-up/Pull-down Enable Register 7      */
   #endif
#define GPIO_PULLSEL1            ((APBADDR)(GPIO_base+0x0400))          /* GPIO Pull-up/Pull-down Select Register 1      */
#define GPIO_PULLSEL2            ((APBADDR)(GPIO_base+0x0440))          /* GPIO Pull-up/Pull-down Select Register 2      */
#define GPIO_PULLSEL3            ((APBADDR)(GPIO_base+0x0480))          /* GPIO Pull-up/Pull-down Select Register 3      */
#define GPIO_PULLSEL4            ((APBADDR)(GPIO_base+0x04C0))          /* GPIO Pull-up/Pull-down Select Register 4      */
#define GPIO_PULLSEL5            ((APBADDR)(GPIO_base+0x0500))          /* GPIO Pull-up/Pull-down Select Register 5      */
#define GPIO_PULLSEL6            ((APBADDR)(GPIO_base+0x0540))          /* GPIO Pull-up/Pull-down Select Register 6      */
   #if IS_CHIP_MT6268
#define GPIO_PULLSEL7            ((APBADDR)(GPIO_base+0x0580))          /* GPIO Pull-up/Pull-down Select Register 7      */
   #endif
#define GPIO_DINV1               ((APBADDR)(GPIO_base+0x0600))          /* GPIO Data Inversion Control Register 1        */
#define GPIO_DINV2               ((APBADDR)(GPIO_base+0x0640))          /* GPIO Data Inversion Control Register 2        */
#define GPIO_DINV3               ((APBADDR)(GPIO_base+0x0680))          /* GPIO Data Inversion Control Register 3        */
#define GPIO_DINV4               ((APBADDR)(GPIO_base+0x06C0))          /* GPIO Data Inversion Control Register 4        */
#define GPIO_DINV5               ((APBADDR)(GPIO_base+0x0700))          /* GPIO Data Inversion Control Register 5        */
#define GPIO_DINV6               ((APBADDR)(GPIO_base+0x0740))          /* GPIO Data Inversion Control Register 6        */
   #if IS_CHIP_MT6268
#define GPIO_DINV7               ((APBADDR)(GPIO_base+0x0780))          /* GPIO Data Inversion Control Register 7        */
   #endif
#define GPIO_DOUT1               ((APBADDR)(GPIO_base+0x0800))          /* GPIO Data Output Register 1                   */
#define GPIO_DOUT2               ((APBADDR)(GPIO_base+0x0840))          /* GPIO Data Output Register 2                   */
#define GPIO_DOUT3               ((APBADDR)(GPIO_base+0x0880))          /* GPIO Data Output Register 3                   */
#define GPIO_DOUT4               ((APBADDR)(GPIO_base+0x08C0))          /* GPIO Data Output Register 4                   */
#define GPIO_DOUT5               ((APBADDR)(GPIO_base+0x0900))          /* GPIO Data Output Register 5                   */
#define GPIO_DOUT6               ((APBADDR)(GPIO_base+0x0940))          /* GPIO Data Output Register 6                   */
   #if IS_CHIP_MT6268
#define GPIO_DOUT7               ((APBADDR)(GPIO_base+0x0980))          /* GPIO Data Output Register 7                   */
   #endif
#define GPIO_DIN1                ((APBADDR)(GPIO_base+0x0A00))          /* GPIO Data input Register 1                    */
#define GPIO_DIN2                ((APBADDR)(GPIO_base+0x0A40))          /* GPIO Data input Register 2                    */
#define GPIO_DIN3                ((APBADDR)(GPIO_base+0x0A80))          /* GPIO Data input Register 3                    */
#define GPIO_DIN4                ((APBADDR)(GPIO_base+0x0AC0))          /* GPIO Data input Register 4                    */
#define GPIO_DIN5                ((APBADDR)(GPIO_base+0x0B00))          /* GPIO Data input Register 5                    */
#define GPIO_DIN6                ((APBADDR)(GPIO_base+0x0B40))          /* GPIO Data input Register 6                    */
   #if IS_CHIP_MT6268
#define GPIO_DIN7                ((APBADDR)(GPIO_base+0x0B80))          /* GPIO Data input Register 7                    */
   #endif
#define GPIO_MODE1               ((APBADDR)(GPIO_base+0x1000))          /* GPIO Mode Control Register 1                  */
#define GPIO_MODE2               ((APBADDR)(GPIO_base+0x1100))          /* GPIO Mode Control Register 2                  */
#define GPIO_MODE3               ((APBADDR)(GPIO_base+0x1200))          /* GPIO Mode Control Register 3                  */
#define GPIO_MODE4               ((APBADDR)(GPIO_base+0x1300))          /* GPIO Mode Control Register 4                  */
#define GPIO_MODE5               ((APBADDR)(GPIO_base+0x1400))          /* GPIO Mode Control Register 5                  */
#define GPIO_MODE6               ((APBADDR)(GPIO_base+0x1500))          /* GPIO Mode Control Register 6                  */
#define GPIO_MODE7               ((APBADDR)(GPIO_base+0x1600))          /* GPIO Mode Control Register 7                  */
#define GPIO_MODE8               ((APBADDR)(GPIO_base+0x1700))          /* GPIO Mode Control Register 8                  */
#define GPIO_MODE9               ((APBADDR)(GPIO_base+0x1800))          /* GPIO Mode Control Register 9                  */
#define GPIO_MODEA               ((APBADDR)(GPIO_base+0x1900))          /* GPIO Mode Control Register A                  */
#define GPIO_MODEB               ((APBADDR)(GPIO_base+0x1A00))          /* GPIO Mode Control Register B                  */
   #if IS_CHIP_MT6268
#define GPIO_MODEC               ((APBADDR)(GPIO_base+0x1B00))          /* GPIO Mode Control Register C                  */
#define GPIO_MODED               ((APBADDR)(GPIO_base+0x1C00))          /* GPIO Mode Control Register D                  */
   #endif
#define CLK_OUT0                 ((APBADDR)(GPIO_base+0x3000))          /* CLK_OUT0 Setting                              */
#define CLK_OUT1                 ((APBADDR)(GPIO_base+0x3100))          /* CLK_OUT1 Setting                              */
#define CLK_OUT2                 ((APBADDR)(GPIO_base+0x3200))          /* CLK_OUT2 Setting                              */
#define CLK_OUT3                 ((APBADDR)(GPIO_base+0x3300))          /* CLK_OUT3 Setting                              */
#define CLK_OUT4                 ((APBADDR)(GPIO_base+0x3400))          /* CLK_OUT4 Setting                              */
#define CLK_OUT5                 ((APBADDR)(GPIO_base+0x3500))          /* CLK_OUT5 Setting                              */
   #if IS_CHIP_MT6238
#define CLK_OUT6                 ((APBADDR)(GPIO_base+0x3600))          /* CLK_OUT6 Setting                              */
#define CLK_OUT7                 ((APBADDR)(GPIO_base+0x3700))          /* CLK_OUT7 Setting                              */
#define GPIO_TM                  ((APBADDR)(GPIO_base+0x4000))          /* OE read-back selection                        */
   #endif
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_CHIP_MT6253
/* ===================================================================================================================== */
/* for MT6253T                                                                                                           */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GPIO_DIR1                ((APBADDR)(GPIO_base+0x0000))          /* GPIO Direction Register 1                     */
#define GPIO_DIR2                ((APBADDR)(GPIO_base+0x0010))          /* GPIO Direction Register 2                     */
#define GPIO_DIR3                ((APBADDR)(GPIO_base+0x0020))          /* GPIO Direction Register 3                     */
#define GPIO_DIR4                ((APBADDR)(GPIO_base+0x0030))          /* GPIO Direction Register 4                     */
#define GPIO_DIR5                ((APBADDR)(GPIO_base+0x0040))          /* GPIO Direction Register 5                     */
#define GPIO_DIR6                ((APBADDR)(GPIO_base+0x0380))          /* GPIO Direction Register 6                     */
#define GPIO_PULLEN1             ((APBADDR)(GPIO_base+0x0050))          /* GPIO Pull-up/Pull-down Enable Register 1      */
#define GPIO_PULLEN2             ((APBADDR)(GPIO_base+0x0060))          /* GPIO Pull-up/Pull-down Enable Register 2      */
#define GPIO_PULLEN3             ((APBADDR)(GPIO_base+0x0070))          /* GPIO Pull-up/Pull-down Enable Register 3      */
#define GPIO_PULLEN4             ((APBADDR)(GPIO_base+0x0080))          /* GPIO Pull-up/Pull-down Enable Register 4      */
#define GPIO_PULLEN5             ((APBADDR)(GPIO_base+0x0090))          /* GPIO Pull-up/Pull-down Enable Register 5      */
#define GPIO_PULLEN6             ((APBADDR)(GPIO_base+0x0390))          /* GPIO Pull-up/Pull-down Enable Register 6      */
#define GPIO_DINV1               ((APBADDR)(GPIO_base+0x00A0))          /* Register 1                                    */
#define GPIO_DINV2               ((APBADDR)(GPIO_base+0x00B0))          /* Register 2                                    */
#define GPIO_DINV3               ((APBADDR)(GPIO_base+0x00C0))          /* Register 3                                    */
#define GPIO_DINV4               ((APBADDR)(GPIO_base+0x00D0))          /* Register 4                                    */
#define GPIO_DINV5               ((APBADDR)(GPIO_base+0x00E0))          /* Register 5                                    */
#define GPIO_DINV6               ((APBADDR)(GPIO_base+0x03A0))          /* Register 6                                    */
#define GPIO_DOUT1               ((APBADDR)(GPIO_base+0x00F0))          /* GPIO Data Output Register 1                   */
#define GPIO_DOUT2               ((APBADDR)(GPIO_base+0x0100))          /* GPIO Data Output Register 2                   */
#define GPIO_DOUT3               ((APBADDR)(GPIO_base+0x0110))          /* GPIO Data Output Register 3                   */
#define GPIO_DOUT4               ((APBADDR)(GPIO_base+0x0120))          /* GPIO Data Output Register 4                   */
#define GPIO_DOUT5               ((APBADDR)(GPIO_base+0x0130))          /* GPIO Data Output Register 5                   */
#define GPIO_DOUT6               ((APBADDR)(GPIO_base+0x03B0))          /* GPIO Data Output Register 6                   */
#define GPIO_DIN1                ((APBADDR)(GPIO_base+0x0140))          /* GPIO Data input Register 1                    */
#define GPIO_DIN2                ((APBADDR)(GPIO_base+0x0150))          /* GPIO Data input Register 2                    */
#define GPIO_DIN3                ((APBADDR)(GPIO_base+0x0160))          /* GPIO Data input Register 3                    */
#define GPIO_DIN4                ((APBADDR)(GPIO_base+0x0170))          /* GPIO Data input Register 4                    */
#define GPIO_DIN5                ((APBADDR)(GPIO_base+0x0180))          /* GPIO Data input Register 5                    */
#define GPIO_DIN6                ((APBADDR)(GPIO_base+0x03C0))          /* GPIO Data input Register 6                    */
#define GPIO_MODE1               ((APBADDR)(GPIO_base+0x0190))          /* GPIO Mode Control Register 1                  */
#define GPIO_MODE2               ((APBADDR)(GPIO_base+0x01A0))          /* GPIO Mode Control Register 2                  */
#define GPIO_MODE3               ((APBADDR)(GPIO_base+0x01B0))          /* GPIO Mode Control Register 3                  */
#define GPIO_MODE4               ((APBADDR)(GPIO_base+0x01C0))          /* GPIO Mode Control Register 4                  */
#define GPIO_MODE5               ((APBADDR)(GPIO_base+0x01D0))          /* GPIO Mode Control Register 5                  */
#define GPIO_MODE6               ((APBADDR)(GPIO_base+0x01E0))          /* GPIO Mode Control Register 6                  */
#define GPIO_MODE7               ((APBADDR)(GPIO_base+0x01F0))          /* GPIO Mode Control Register 7                  */
#define GPIO_MODE8               ((APBADDR)(GPIO_base+0x0200))          /* GPIO Mode Control Register 8                  */
#define GPIO_MODE9               ((APBADDR)(GPIO_base+0x0210))          /* GPIO Mode Control Register 9                  */
#define GPIO_MODE10              ((APBADDR)(GPIO_base+0x0220))          /* GPIO Mode Control Register 10                 */
#define GPIO_MODE11              ((APBADDR)(GPIO_base+0x03D0))          /* GPIO Mode Control Register 11                 */
#define GPIO_PULLSEL1            ((APBADDR)(GPIO_base+0x0240))          /* GPIO Pull-up/Pull-down Select Register 1      */
#define GPIO_BANK                ((APBADDR)(GPIO_base+0x0230))
#define GPIO_PULLSEL2            ((APBADDR)(GPIO_base+0x0250))          /* GPIO Pull-up/Pull-down Select Register 2      */
#define GPIO_PULLSEL3            ((APBADDR)(GPIO_base+0x0260))          /* GPIO Pull-up/Pull-down Select Register 3      */
#define GPIO_PULLSEL4            ((APBADDR)(GPIO_base+0x0270))          /* GPIO Pull-up/Pull-down Select Register 4      */
#define GPIO_PULLSEL5            ((APBADDR)(GPIO_base+0x0280))          /* GPIO Pull-up/Pull-down Select Register 5      */
#define CLK_OUT0                 ((APBADDR)(GPIO_base+0x0300))          /* CLKO_MODE1 Setting                            */
#define CLK_OUT1                 ((APBADDR)(GPIO_base+0x0310))          /* CLKO_MODE2 Setting                            */
#define CLK_OUT2                 ((APBADDR)(GPIO_base+0x0320))          /* CLKO_MODE3 Setting                            */
#define CLK_OUT3                 ((APBADDR)(GPIO_base+0x0330))          /* CLKO_MODE4 Setting                            */
#define CLK_OUT4                 ((APBADDR)(GPIO_base+0x0340))          /* CLKO_MODE5 Setting                            */
#define CLK_OUT5                 ((APBADDR)(GPIO_base+0x0350))          /* CLKO_MODE6 Setting                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_SMARTPHONE_CHIP_TK6516_AND_LATTER_VERSION
/* ===================================================================================================================== */
/* for TK6516                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GPIO_DIR1                ((APBADDR)(GPIO_base+0x0000))          /* GPIO Direction Register 1                     */
#define GPIO_PULLEN1             ((APBADDR)(GPIO_base+0x0100))          /* GPIO Pull-up/Pull-down Enable Register 1      */
#define GPIO_PULLSEL1            ((APBADDR)(GPIO_base+0x0200))          /* GPIO Pull-up/Pull-down Select Register 1      */
#define GPIO_DINV1               ((APBADDR)(GPIO_base+0x0300))          /* GPIO Data Inversion Control Register 1        */
#define GPIO_DOUT1               ((APBADDR)(GPIO_base+0x0400))          /* GPIO Data Output Register 1                   */
#define GPIO_DIN1                ((APBADDR)(GPIO_base+0x0500))          /* GPIO Data input Register 1                    */
#define GPIO_MODE1               ((APBADDR)(GPIO_base+0x0600))          /* GPIO Mode Control Register 1                  */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_CHIP_MT6236
/* ===================================================================================================================== */
/* for MT6236                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GPIO_DIR1                ((APBADDR)(GPIO_base+0x0000))          /* GPIO Direction Register 1                     */
#define GPIO_DIR2                ((APBADDR)(GPIO_base+0x0010))          /* GPIO Direction Register 2                     */
#define GPIO_DIR3                ((APBADDR)(GPIO_base+0x0020))          /* GPIO Direction Register 3                     */
#define GPIO_DIR4                ((APBADDR)(GPIO_base+0x0030))          /* GPIO Direction Register 4                     */
#define GPIO_DIR5                ((APBADDR)(GPIO_base+0x0040))          /* GPIO Direction Register 5                     */
#define GPIO_PULLEN1             ((APBADDR)(GPIO_base+0x0100))          /* GPIO Pull-up/Pull-down Enable Register 1      */
#define GPIO_PULLEN2             ((APBADDR)(GPIO_base+0x0110))          /* GPIO Pull-up/Pull-down Enable Register 2      */
#define GPIO_PULLEN3             ((APBADDR)(GPIO_base+0x0120))          /* GPIO Pull-up/Pull-down Enable Register 3      */
#define GPIO_PULLEN4             ((APBADDR)(GPIO_base+0x0130))          /* GPIO Pull-up/Pull-down Enable Register 4      */
#define GPIO_PULLEN5             ((APBADDR)(GPIO_base+0x0140))          /* GPIO Pull-up/Pull-down Enable Register 5      */
#define GPIO_PULLSEL1            ((APBADDR)(GPIO_base+0x0200))          /* GPIO Pull-up/Pull-down Select Register 1      */
#define GPIO_PULLSEL2            ((APBADDR)(GPIO_base+0x0210))          /* GPIO Pull-up/Pull-down Select Register 2      */
#define GPIO_PULLSEL3            ((APBADDR)(GPIO_base+0x0220))          /* GPIO Pull-up/Pull-down Select Register 3      */
#define GPIO_PULLSEL4            ((APBADDR)(GPIO_base+0x0230))          /* GPIO Pull-up/Pull-down Select Register 4      */
#define GPIO_PULLSEL5            ((APBADDR)(GPIO_base+0x0240))          /* GPIO Pull-up/Pull-down Select Register 5      */
#define GPIO_DINV1               ((APBADDR)(GPIO_base+0x0300))          /* Register 1                                    */
#define GPIO_DINV2               ((APBADDR)(GPIO_base+0x0310))          /* Register 2                                    */
#define GPIO_DINV3               ((APBADDR)(GPIO_base+0x0320))          /* Register 3                                    */
#define GPIO_DINV4               ((APBADDR)(GPIO_base+0x0330))          /* Register 4                                    */
#define GPIO_DINV5               ((APBADDR)(GPIO_base+0x0340))          /* Register 5                                    */
#define GPIO_DOUT1               ((APBADDR)(GPIO_base+0x0400))          /* GPIO Data Output Register 1                   */
#define GPIO_DOUT2               ((APBADDR)(GPIO_base+0x0410))          /* GPIO Data Output Register 2                   */
#define GPIO_DOUT3               ((APBADDR)(GPIO_base+0x0420))          /* GPIO Data Output Register 3                   */
#define GPIO_DOUT4               ((APBADDR)(GPIO_base+0x0430))          /* GPIO Data Output Register 4                   */
#define GPIO_DOUT5               ((APBADDR)(GPIO_base+0x0440))          /* GPIO Data Output Register 5                   */
#define GPIO_DIN1                ((APBADDR)(GPIO_base+0x0500))          /* GPIO Data input Register 1                    */
#define GPIO_DIN2                ((APBADDR)(GPIO_base+0x0510))          /* GPIO Data input Register 2                    */
#define GPIO_DIN3                ((APBADDR)(GPIO_base+0x0520))          /* GPIO Data input Register 3                    */
#define GPIO_DIN4                ((APBADDR)(GPIO_base+0x0530))          /* GPIO Data input Register 4                    */
#define GPIO_DIN5                ((APBADDR)(GPIO_base+0x0540))          /* GPIO Data input Register 5                    */
#define GPIO_MODE1               ((APBADDR)(GPIO_base+0x0600))          /* GPIO Mode Control Register 1                  */
#define GPIO_MODE2               ((APBADDR)(GPIO_base+0x0610))          /* GPIO Mode Control Register 2                  */
#define GPIO_MODE3               ((APBADDR)(GPIO_base+0x0620))          /* GPIO Mode Control Register 3                  */
#define GPIO_MODE4               ((APBADDR)(GPIO_base+0x0630))          /* GPIO Mode Control Register 4                  */
#define GPIO_MODE5               ((APBADDR)(GPIO_base+0x0640))          /* GPIO Mode Control Register 5                  */
#define GPIO_MODE6               ((APBADDR)(GPIO_base+0x0650))          /* GPIO Mode Control Register 6                  */
#define GPIO_MODE7               ((APBADDR)(GPIO_base+0x0660))          /* GPIO Mode Control Register 7                  */
#define GPIO_MODE8               ((APBADDR)(GPIO_base+0x0670))          /* GPIO Mode Control Register 8                  */
#define GPIO_MODE9               ((APBADDR)(GPIO_base+0x0680))          /* GPIO Mode Control Register 9                  */
#define CLK_OUT0                 ((APBADDR)(GPIO_base+0x0900))          /* CLK_OUT1 Setting                              */
#define CLK_OUT1                 ((APBADDR)(GPIO_base+0x0910))          /* CLK_OUT2 Setting                              */
#define CLK_OUT2                 ((APBADDR)(GPIO_base+0x0920))          /* CLK_OUT3 Setting                              */
#define CLK_OUT3                 ((APBADDR)(GPIO_base+0x0930))          /* CLK_OUT4 Setting                              */
#define CLK_OUT4                 ((APBADDR)(GPIO_base+0x0940))          /* CLK_OUT5 Setting                              */
#define CLK_OUT5                 ((APBADDR)(GPIO_base+0x0950))          /* CLK_OUT6 Setting                              */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_CHIP_MT6572
/* ===================================================================================================================== */
/* for MT6572                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GPIO_CFG_base            0xA0208000
#define GPIO_DRV_CFG0            ((APBADDR32)(GPIO_CFG_base+0x00D0))
#endif
#if IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2
/* ===================================================================================================================== */
/* for MT6583                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GPIO_base                AP_GPIO_base
#define GPIO_DIR0                ((APBADDR)(GPIO_base+0x0000))          /* GPIO Direction Register 0                     */
#define GPIO_DIR1                ((APBADDR)(GPIO_base+0x0010))          /* GPIO Direction Register 1                     */
#define GPIO_DIR2                ((APBADDR)(GPIO_base+0x0020))          /* GPIO Direction Register 2                     */
#define GPIO_DIR3                ((APBADDR)(GPIO_base+0x0030))          /* GPIO Direction Register 3                     */
#define GPIO_DIR4                ((APBADDR)(GPIO_base+0x0040))          /* GPIO Direction Register 4                     */
#define GPIO_DIR5                ((APBADDR)(GPIO_base+0x0050))          /* GPIO Direction Register 5                     */
#define GPIO_DIR6                ((APBADDR)(GPIO_base+0x0060))          /* GPIO Direction Register 6                     */
#define GPIO_DIR7                ((APBADDR)(GPIO_base+0x0070))          /* GPIO Direction Register 7                     */
#define GPIO_DIR8                ((APBADDR)(GPIO_base+0x0080))          /* GPIO Direction Register 8                     */
#define GPIO_DIR9                ((APBADDR)(GPIO_base+0x0090))          /* GPIO Direction Register 9                     */
#define GPIO_DIR10               ((APBADDR)(GPIO_base+0x00A0))          /* GPIO Direction Register 10                    */
#define GPIO_DIR11               ((APBADDR)(GPIO_base+0x00B0))          /* GPIO Direction Register 11                    */
#define GPIO_DIR12               ((APBADDR)(GPIO_base+0x00C0))          /* GPIO Direction Register 12                    */
#define GPIO_DIR13               ((APBADDR)(GPIO_base+0x00D0))          /* GPIO Direction Register 13                    */
#define GPIO_DIR14               ((APBADDR)(GPIO_base+0x00E0))          /* GPIO Direction Register 14                    */
#define GPIO_PULLEN0             ((APBADDR)(GPIO_base+0x0200))          /* GPIO Pull-up/Pull-down Enable Register 0      */
#define GPIO_PULLEN1             ((APBADDR)(GPIO_base+0x0210))          /* GPIO Pull-up/Pull-down Enable Register 1      */
#define GPIO_PULLEN2             ((APBADDR)(GPIO_base+0x0220))          /* GPIO Pull-up/Pull-down Enable Register 2      */
#define GPIO_PULLEN3             ((APBADDR)(GPIO_base+0x0230))          /* GPIO Pull-up/Pull-down Enable Register 3      */
#define GPIO_PULLEN4             ((APBADDR)(GPIO_base+0x0240))          /* GPIO Pull-up/Pull-down Enable Register 4      */
#define GPIO_PULLEN5             ((APBADDR)(GPIO_base+0x0250))          /* GPIO Pull-up/Pull-down Enable Register 5      */
#define GPIO_PULLEN6             ((APBADDR)(GPIO_base+0x0260))          /* GPIO Pull-up/Pull-down Enable Register 6      */
#define GPIO_PULLEN7             ((APBADDR)(GPIO_base+0x0270))          /* GPIO Pull-up/Pull-down Enable Register 7      */
#define GPIO_PULLEN8             ((APBADDR)(GPIO_base+0x0280))          /* GPIO Pull-up/Pull-down Enable Register 8      */
#define GPIO_PULLEN9             ((APBADDR)(GPIO_base+0x0290))          /* GPIO Pull-up/Pull-down Enable Register 9      */
#define GPIO_PULLEN10            ((APBADDR)(GPIO_base+0x02A0))          /* GPIO Pull-up/Pull-down Enable Register 10     */
#define GPIO_PULLEN11            ((APBADDR)(GPIO_base+0x02B0))          /* GPIO Pull-up/Pull-down Enable Register 11     */
#define GPIO_PULLEN12            ((APBADDR)(GPIO_base+0x02C0))          /* GPIO Pull-up/Pull-down Enable Register 12     */
#define GPIO_PULLEN13            ((APBADDR)(GPIO_base+0x02D0))          /* GPIO Pull-up/Pull-down Enable Register 13     */
#define GPIO_PULLEN14            ((APBADDR)(GPIO_base+0x02E0))          /* GPIO Pull-up/Pull-down Enable Register 14     */
#define GPIO_PULLSEL0            ((APBADDR)(GPIO_base+0x0400))          /* GPIO Pull-up/Pull-down Select Register 0      */
#define GPIO_PULLSEL1            ((APBADDR)(GPIO_base+0x0410))          /* GPIO Pull-up/Pull-down Select Register 1      */
#define GPIO_PULLSEL2            ((APBADDR)(GPIO_base+0x0420))          /* GPIO Pull-up/Pull-down Select Register 2      */
#define GPIO_PULLSEL3            ((APBADDR)(GPIO_base+0x0430))          /* GPIO Pull-up/Pull-down Select Register 3      */
#define GPIO_PULLSEL4            ((APBADDR)(GPIO_base+0x0440))          /* GPIO Pull-up/Pull-down Select Register 4      */
#define GPIO_PULLSEL5            ((APBADDR)(GPIO_base+0x0450))          /* GPIO Pull-up/Pull-down Select Register 5      */
#define GPIO_PULLSEL6            ((APBADDR)(GPIO_base+0x0460))          /* GPIO Pull-up/Pull-down Select Register 6      */
#define GPIO_PULLSEL7            ((APBADDR)(GPIO_base+0x0470))          /* GPIO Pull-up/Pull-down Select Register 7      */
#define GPIO_PULLSEL8            ((APBADDR)(GPIO_base+0x0480))          /* GPIO Pull-up/Pull-down Select Register 8      */
#define GPIO_PULLSEL9            ((APBADDR)(GPIO_base+0x0490))          /* GPIO Pull-up/Pull-down Select Register 9      */
#define GPIO_PULLSEL10           ((APBADDR)(GPIO_base+0x04A0))          /* GPIO Pull-up/Pull-down Select Register 10     */
#define GPIO_PULLSEL11           ((APBADDR)(GPIO_base+0x04B0))          /* GPIO Pull-up/Pull-down Select Register 11     */
#define GPIO_PULLSEL12           ((APBADDR)(GPIO_base+0x04C0))          /* GPIO Pull-up/Pull-down Select Register 12     */
#define GPIO_PULLSEL13           ((APBADDR)(GPIO_base+0x04D0))          /* GPIO Pull-up/Pull-down Select Register 13     */
#define GPIO_PULLSEL14           ((APBADDR)(GPIO_base+0x04E0))          /* GPIO Pull-up/Pull-down Select Register 14     */
#define GPIO_DINV0               ((APBADDR)(GPIO_base+0x0600))          /* GPIO Data Inversion Control Register 0        */
#define GPIO_DINV1               ((APBADDR)(GPIO_base+0x0610))          /* GPIO Data Inversion Control Register 1        */
#define GPIO_DINV2               ((APBADDR)(GPIO_base+0x0620))          /* GPIO Data Inversion Control Register 2        */
#define GPIO_DINV3               ((APBADDR)(GPIO_base+0x0630))          /* GPIO Data Inversion Control Register 3        */
#define GPIO_DINV4               ((APBADDR)(GPIO_base+0x0640))          /* GPIO Data Inversion Control Register 4        */
#define GPIO_DINV5               ((APBADDR)(GPIO_base+0x0650))          /* GPIO Data Inversion Control Register 5        */
#define GPIO_DINV6               ((APBADDR)(GPIO_base+0x0660))          /* GPIO Data Inversion Control Register 6        */
#define GPIO_DINV7               ((APBADDR)(GPIO_base+0x0670))          /* GPIO Data Inversion Control Register 7        */
#define GPIO_DINV8               ((APBADDR)(GPIO_base+0x0680))          /* GPIO Data Inversion Control Register 8        */
#define GPIO_DINV9               ((APBADDR)(GPIO_base+0x0690))          /* GPIO Data Inversion Control Register 9        */
#define GPIO_DINV10              ((APBADDR)(GPIO_base+0x06A0))          /* GPIO Data Inversion Control Register 10       */
#define GPIO_DINV11              ((APBADDR)(GPIO_base+0x06B0))          /* GPIO Data Inversion Control Register 11       */
#define GPIO_DINV12              ((APBADDR)(GPIO_base+0x06C0))          /* GPIO Data Inversion Control Register 12       */
#define GPIO_DINV13              ((APBADDR)(GPIO_base+0x06D0))          /* GPIO Data Inversion Control Register 13       */
#define GPIO_DINV14              ((APBADDR)(GPIO_base+0x06E0))          /* GPIO Data Inversion Control Register 14       */
#define GPIO_DOUT0               ((APBADDR)(GPIO_base+0x0800))          /* GPIO Data Output Register 0                   */
#define GPIO_DOUT1               ((APBADDR)(GPIO_base+0x0810))          /* GPIO Data Output Register 1                   */
#define GPIO_DOUT2               ((APBADDR)(GPIO_base+0x0820))          /* GPIO Data Output Register 2                   */
#define GPIO_DOUT3               ((APBADDR)(GPIO_base+0x0830))          /* GPIO Data Output Register 3                   */
#define GPIO_DOUT4               ((APBADDR)(GPIO_base+0x0840))          /* GPIO Data Output Register 4                   */
#define GPIO_DOUT5               ((APBADDR)(GPIO_base+0x0850))          /* GPIO Data Output Register 5                   */
#define GPIO_DOUT6               ((APBADDR)(GPIO_base+0x0860))          /* GPIO Data Output Register 6                   */
#define GPIO_DOUT7               ((APBADDR)(GPIO_base+0x0870))          /* GPIO Data Output Register 7                   */
#define GPIO_DOUT8               ((APBADDR)(GPIO_base+0x0880))          /* GPIO Data Output Register 8                   */
#define GPIO_DOUT9               ((APBADDR)(GPIO_base+0x0890))          /* GPIO Data Output Register 9                   */
#define GPIO_DOUT10              ((APBADDR)(GPIO_base+0x08A0))          /* GPIO Data Output Register 10                  */
#define GPIO_DOUT11              ((APBADDR)(GPIO_base+0x08B0))          /* GPIO Data Output Register 11                  */
#define GPIO_DOUT12              ((APBADDR)(GPIO_base+0x08C0))          /* GPIO Data Output Register 12                  */
#define GPIO_DOUT13              ((APBADDR)(GPIO_base+0x08D0))          /* GPIO Data Output Register 13                  */
#define GPIO_DOUT14              ((APBADDR)(GPIO_base+0x08E0))          /* GPIO Data Output Register 14                  */
#define GPIO_DIN0                ((APBADDR)(GPIO_base+0x0A00))          /* GPIO Data input Register 0                    */
#define GPIO_DIN1                ((APBADDR)(GPIO_base+0x0A10))          /* GPIO Data input Register 1                    */
#define GPIO_DIN2                ((APBADDR)(GPIO_base+0x0A20))          /* GPIO Data input Register 2                    */
#define GPIO_DIN3                ((APBADDR)(GPIO_base+0x0A30))          /* GPIO Data input Register 3                    */
#define GPIO_DIN4                ((APBADDR)(GPIO_base+0x0A40))          /* GPIO Data input Register 4                    */
#define GPIO_DIN5                ((APBADDR)(GPIO_base+0x0A50))          /* GPIO Data input Register 5                    */
#define GPIO_DIN6                ((APBADDR)(GPIO_base+0x0A60))          /* GPIO Data input Register 6                    */
#define GPIO_DIN7                ((APBADDR)(GPIO_base+0x0A70))          /* GPIO Data input Register 7                    */
#define GPIO_DIN8                ((APBADDR)(GPIO_base+0x0A80))          /* GPIO Data input Register 8                    */
#define GPIO_DIN9                ((APBADDR)(GPIO_base+0x0A90))          /* GPIO Data input Register 9                    */
#define GPIO_DIN10               ((APBADDR)(GPIO_base+0x0AA0))          /* GPIO Data input Register 10                   */
#define GPIO_DIN11               ((APBADDR)(GPIO_base+0x0AB0))          /* GPIO Data input Register 11                   */
#define GPIO_DIN12               ((APBADDR)(GPIO_base+0x0AC0))          /* GPIO Data input Register 12                   */
#define GPIO_DIN13               ((APBADDR)(GPIO_base+0x0AD0))          /* GPIO Data input Register 13                   */
#define GPIO_DIN14               ((APBADDR)(GPIO_base+0x0AE0))          /* GPIO Data input Register 14                   */
#define GPIO_MODE0               ((APBADDR)(GPIO_base+0x0C00))          /* GPIO Mode Control Register 0                  */
#define GPIO_MODE1               ((APBADDR)(GPIO_base+0x0C10))          /* GPIO Mode Control Register 1                  */
#define GPIO_MODE2               ((APBADDR)(GPIO_base+0x0C20))          /* GPIO Mode Control Register 2                  */
#define GPIO_MODE3               ((APBADDR)(GPIO_base+0x0C30))          /* GPIO Mode Control Register 3                  */
#define GPIO_MODE4               ((APBADDR)(GPIO_base+0x0C40))          /* GPIO Mode Control Register 4                  */
#define GPIO_MODE5               ((APBADDR)(GPIO_base+0x0C50))          /* GPIO Mode Control Register 5                  */
#define GPIO_MODE6               ((APBADDR)(GPIO_base+0x0C60))          /* GPIO Mode Control Register 6                  */
#define GPIO_MODE7               ((APBADDR)(GPIO_base+0x0C70))          /* GPIO Mode Control Register 7                  */
#define GPIO_MODE8               ((APBADDR)(GPIO_base+0x0C80))          /* GPIO Mode Control Register 8                  */
#define GPIO_MODE9               ((APBADDR)(GPIO_base+0x0C90))          /* GPIO Mode Control Register 9                  */
#define GPIO_MODEA               ((APBADDR)(GPIO_base+0x0CA0))          /* GPIO Mode Control Register A                  */
#define GPIO_MODEB               ((APBADDR)(GPIO_base+0x0CB0))          /* GPIO Mode Control Register B                  */
#define GPIO_MODEC               ((APBADDR)(GPIO_base+0x0CC0))          /* GPIO Mode Control Register C                  */
#define GPIO_MODED               ((APBADDR)(GPIO_base+0x0CD0))          /* GPIO Mode Control Register D                  */
#define GPIO_MODEE               ((APBADDR)(GPIO_base+0x0CE0))          /* GPIO Mode Control Register E                  */
#define GPIO_MODEF               ((APBADDR)(GPIO_base+0x0CF0))          /* GPIO Mode Control Register F                  */
#define GPIO_MODE10              ((APBADDR)(GPIO_base+0x0D00))          /* GPIO Mode Control Register 10                 */
#define GPIO_MODE11              ((APBADDR)(GPIO_base+0x0D10))          /* GPIO Mode Control Register 11                 */
#define GPIO_MODE12              ((APBADDR)(GPIO_base+0x0D20))          /* GPIO Mode Control Register 12                 */
#define GPIO_MODE13              ((APBADDR)(GPIO_base+0x0D30))          /* GPIO Mode Control Register 13                 */
#define GPIO_MODE14              ((APBADDR)(GPIO_base+0x0D40))          /* GPIO Mode Control Register 14                 */
#define GPIO_MODE15              ((APBADDR)(GPIO_base+0x0D50))          /* GPIO Mode Control Register 15                 */
#define GPIO_MODE16              ((APBADDR)(GPIO_base+0x0D60))          /* GPIO Mode Control Register 16                 */
#define GPIO_MODE17              ((APBADDR)(GPIO_base+0x0D70))          /* GPIO Mode Control Register 17                 */
#define GPIO_MODE18              ((APBADDR)(GPIO_base+0x0D80))          /* GPIO Mode Control Register 18                 */
#define GPIO_MODE19              ((APBADDR)(GPIO_base+0x0D90))          /* GPIO Mode Control Register 19                 */
#define GPIO_MODE1A              ((APBADDR)(GPIO_base+0x0DA0))          /* GPIO Mode Control Register 1A                 */
#define GPIO_MODE1B              ((APBADDR)(GPIO_base+0x0DB0))          /* GPIO Mode Control Register 1B                 */
#define GPIO_MODE1C              ((APBADDR)(GPIO_base+0x0DC0))          /* GPIO Mode Control Register 1C                 */
#define GPIO_MODE1D              ((APBADDR)(GPIO_base+0x0DD0))          /* GPIO Mode Control Register 1D                 */
#define GPIO_MODE1E              ((APBADDR)(GPIO_base+0x0DE0))          /* GPIO Mode Control Register 1E                 */
#define GPIO_MODE1F              ((APBADDR)(GPIO_base+0x0DF0))          /* GPIO Mode Control Register 1F                 */
#define GPIO_MODE20              ((APBADDR)(GPIO_base+0x0E00))          /* GPIO Mode Control Register 20                 */
#define GPIO_MODE21              ((APBADDR)(GPIO_base+0x0E10))          /* GPIO Mode Control Register 21                 */
#define GPIO_MODE22              ((APBADDR)(GPIO_base+0x0E20))          /* GPIO Mode Control Register 22                 */
#define GPIO_MODE23              ((APBADDR)(GPIO_base+0x0E30))          /* GPIO Mode Control Register 23                 */
#define GPIO_MODE24              ((APBADDR)(GPIO_base+0x0E40))          /* GPIO Mode Control Register 21                 */
#define GPIO_MODE25              ((APBADDR)(GPIO_base+0x0E50))          /* GPIO Mode Control Register 25                 */
#define GPIO_MODE26              ((APBADDR)(GPIO_base+0x0E60))          /* GPIO Mode Control Register 26                 */
#define GPIO_MODE27              ((APBADDR)(GPIO_base+0x0E70))          /* GPIO Mode Control Register 27                 */
#define GPIO_MODE28              ((APBADDR)(GPIO_base+0x0E80))          /* GPIO Mode Control Register 28                 */
#define GPIO_MODE29              ((APBADDR)(GPIO_base+0x0E90))          /* GPIO Mode Control Register 29                 */
#define GPIO_MODE2A              ((APBADDR)(GPIO_base+0x0EA0))          /* GPIO Mode Control Register 2A                 */
#define GPIO_MODE2B              ((APBADDR)(GPIO_base+0x0EB0))          /* GPIO Mode Control Register 2B                 */
#define GPIO_MODE2C              ((APBADDR)(GPIO_base+0x0EC0))          /* GPIO Mode Control Register 2C                 */
#define GPIO_MODE2D              ((APBADDR)(GPIO_base+0x0ED0))          /* GPIO Mode Control Register 2D                 */
#define GPIO_MODE2E              ((APBADDR)(GPIO_base+0x0EE0))          /* GPIO Mode Control Register 2E                 */
#define GPIO_DRV_CON5            ((APBADDR32)(GPIO_base+0x0550))        /* GPIO DRV Enable Register 5                    */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_CHIP_MT6280
/* ===================================================================================================================== */
/* for MT6280                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#if defined(__UE_SIMULATOR__) || defined(ESIM_BUILD_CONFIG) /* UESIM-MOLY and ESIM-MOLY*/
#define GPIO_base                0xFF870000   /* MT6290 GPIO address BASE_MADDR_MDGPIOMUX      */
   #if defined(ESIM_BUILD_CONFIG) /*  ESIM-MOLY*/
#define EFUSE_base               BASE_MADDR_EFUSE
   #endif
#endif

#define GPIO_DIR1                ((APBADDR)(GPIO_base+0x0000))          /* GPIO Direction Register 1                     */
#define GPIO_DIR2                ((APBADDR)(GPIO_base+0x0040))          /* GPIO Direction Register 2                     */
#define GPIO_DIR3                ((APBADDR)(GPIO_base+0x0080))          /* GPIO Direction Register 3                     */
#define GPIO_DIR4                ((APBADDR)(GPIO_base+0x00C0))          /* GPIO Direction Register 4                     */
#define GPIO_DIR5                ((APBADDR)(GPIO_base+0x0100))          /* GPIO Direction Register 5                     */
#define GPIO_DIR6                ((APBADDR)(GPIO_base+0x0140))          /* GPIO Direction Register 6                     */
#define GPIO_DIR7                ((APBADDR)(GPIO_base+0x0180))          /* GPIO Direction Register 7                     */
#define GPIO_PULLEN1             ((APBADDR)(GPIO_base+0x0200))          /* GPIO Pull-up/Pull-down Enable Register 1      */
#define GPIO_PULLEN2             ((APBADDR)(GPIO_base+0x0240))          /* GPIO Pull-up/Pull-down Enable Register 2      */
#define GPIO_PULLEN3             ((APBADDR)(GPIO_base+0x0280))          /* GPIO Pull-up/Pull-down Enable Register 3      */
#define GPIO_PULLEN4             ((APBADDR)(GPIO_base+0x02C0))          /* GPIO Pull-up/Pull-down Enable Register 4      */
#define GPIO_PULLEN5             ((APBADDR)(GPIO_base+0x0300))          /* GPIO Pull-up/Pull-down Enable Register 5      */
#define GPIO_PULLEN6             ((APBADDR)(GPIO_base+0x0340))          /* GPIO Pull-up/Pull-down Enable Register 6      */
#define GPIO_PULLEN7             ((APBADDR)(GPIO_base+0x0380))          /* GPIO Pull-up/Pull-down Enable Register 7      */
#define GPIO_PULLSEL1            ((APBADDR)(GPIO_base+0x0400))          /* GPIO Pull-up/Pull-down Select Register 1      */
#define GPIO_PULLSEL2            ((APBADDR)(GPIO_base+0x0440))          /* GPIO Pull-up/Pull-down Select Register 2      */
#define GPIO_PULLSEL3            ((APBADDR)(GPIO_base+0x0480))          /* GPIO Pull-up/Pull-down Select Register 3      */
#define GPIO_PULLSEL4            ((APBADDR)(GPIO_base+0x04C0))          /* GPIO Pull-up/Pull-down Select Register 4      */
#define GPIO_PULLSEL5            ((APBADDR)(GPIO_base+0x0500))          /* GPIO Pull-up/Pull-down Select Register 5      */
#define GPIO_PULLSEL6            ((APBADDR)(GPIO_base+0x0540))          /* GPIO Pull-up/Pull-down Select Register 6      */
#define GPIO_PULLSEL7            ((APBADDR)(GPIO_base+0x0580))          /* GPIO Pull-up/Pull-down Select Register 7      */
#define GPIO_DINV1               ((APBADDR)(GPIO_base+0x0600))          /* Register 1                                    */
#define GPIO_DINV2               ((APBADDR)(GPIO_base+0x0640))          /* Register 2                                    */
#define GPIO_DINV3               ((APBADDR)(GPIO_base+0x0680))          /* Register 3                                    */
#define GPIO_DINV4               ((APBADDR)(GPIO_base+0x06C0))          /* Register 4                                    */
#define GPIO_DINV5               ((APBADDR)(GPIO_base+0x0700))          /* Register 5                                    */
#define GPIO_DINV6               ((APBADDR)(GPIO_base+0x0740))          /* Register 6                                    */
#define GPIO_DINV7               ((APBADDR)(GPIO_base+0x0780))          /* Register 7                                    */
#define GPIO_DOUT1               ((APBADDR)(GPIO_base+0x0800))          /* GPIO Data Output Register 1                   */
#define GPIO_DOUT2               ((APBADDR)(GPIO_base+0x0840))          /* GPIO Data Output Register 2                   */
#define GPIO_DOUT3               ((APBADDR)(GPIO_base+0x0880))          /* GPIO Data Output Register 3                   */
#define GPIO_DOUT4               ((APBADDR)(GPIO_base+0x08C0))          /* GPIO Data Output Register 4                   */
#define GPIO_DOUT5               ((APBADDR)(GPIO_base+0x0900))          /* GPIO Data Output Register 5                   */
#define GPIO_DOUT6               ((APBADDR)(GPIO_base+0x0940))          /* GPIO Data Output Register 6                   */
#define GPIO_DOUT7               ((APBADDR)(GPIO_base+0x0980))          /* GPIO Data Output Register 7                   */
#define GPIO_DIN1                ((APBADDR)(GPIO_base+0x0A00))          /* GPIO Data input Register 1                    */
#define GPIO_DIN2                ((APBADDR)(GPIO_base+0x0A40))          /* GPIO Data input Register 2                    */
#define GPIO_DIN3                ((APBADDR)(GPIO_base+0x0A80))          /* GPIO Data input Register 3                    */
#define GPIO_DIN4                ((APBADDR)(GPIO_base+0x0AC0))          /* GPIO Data input Register 4                    */
#define GPIO_DIN5                ((APBADDR)(GPIO_base+0x0B00))          /* GPIO Data input Register 5                    */
#define GPIO_DIN6                ((APBADDR)(GPIO_base+0x0B40))          /* GPIO Data input Register 6                    */
#define GPIO_DIN7                ((APBADDR)(GPIO_base+0x0B80))          /* GPIO Data input Register 7                    */
#define GPIO_MODE1               ((APBADDR)(GPIO_base+0x1000))          /* GPIO Mode Control Register 1                  */
#define GPIO_MODE2               ((APBADDR)(GPIO_base+0x1100))          /* GPIO Mode Control Register 2                  */
#define GPIO_MODE3               ((APBADDR)(GPIO_base+0x1200))          /* GPIO Mode Control Register 3                  */
#define GPIO_MODE4               ((APBADDR)(GPIO_base+0x1300))          /* GPIO Mode Control Register 4                  */
#define GPIO_MODE5               ((APBADDR)(GPIO_base+0x1400))          /* GPIO Mode Control Register 5                  */
#define GPIO_MODE6               ((APBADDR)(GPIO_base+0x1500))          /* GPIO Mode Control Register 6                  */
#define GPIO_MODE7               ((APBADDR)(GPIO_base+0x1600))          /* GPIO Mode Control Register 7                  */
#define GPIO_MODE8               ((APBADDR)(GPIO_base+0x1700))          /* GPIO Mode Control Register 8                  */
#define GPIO_MODE9               ((APBADDR)(GPIO_base+0x1800))          /* GPIO Mode Control Register 9                  */
#define GPIO_MODEA               ((APBADDR)(GPIO_base+0x1900))          /* GPIO Mode Control Register A                  */
#define GPIO_MODEB               ((APBADDR)(GPIO_base+0x1A00))          /* GPIO Mode Control Register B                  */
#define GPIO_MODEC               ((APBADDR)(GPIO_base+0x1B00))          /* GPIO Mode Control Register C                  */
#define GPIO_MODED               ((APBADDR)(GPIO_base+0x1C00))          /* GPIO Mode Control Register D                  */
#define GPIO_MODEE               ((APBADDR)(GPIO_base+0x1D00))          /* GPIO Mode Control Register E                  */
#define GPIO_MODEF               ((APBADDR)(GPIO_base+0x1E00))          /* GPIO Mode Control Register F                  */
#define GPIO_MODE10              ((APBADDR)(GPIO_base+0x1F00))          /* GPIO Mode Control Register 10                 */
#define GPIO_MODE11              ((APBADDR)(GPIO_base+0x2000))          /* GPIO Mode Control Register 11                 */
#define GPIO_MODE12              ((APBADDR)(GPIO_base+0x2100))          /* GPIO Mode Control Register 12                 */
#define GPIO_MODE13              ((APBADDR)(GPIO_base+0x2200))          /* GPIO Mode Control Register 13                 */
#define GPIO_MODE14              ((APBADDR)(GPIO_base+0x2300))          /* GPIO Mode Control Register 14                 */
#define GPIO_MODE15              ((APBADDR)(GPIO_base+0x2400))          /* GPIO Mode Control Register 15                 */
#define GPIO_MODE16              ((APBADDR)(GPIO_base+0x2500))          /* GPIO Mode Control Register 16                 */
#define GPIO_MODE17              ((APBADDR)(GPIO_base+0x2600))          /* GPIO Mode Control Register 17                 */
#define GPIO_MODE18              ((APBADDR)(GPIO_base+0x2700))          /* GPIO Mode Control Register 18                 */
#define GPIO_MODE19              ((APBADDR)(GPIO_base+0x2800))          /* GPIO Mode Control Register 19                 */
#define GPIO_DRV1                ((APBADDR)(GPIO_base+0x3000))          /* IO Driving Control Register 1                 */
#define GPIO_DRV2                ((APBADDR)(GPIO_base+0x3100))          /* IO Driving Control Register 2                 */
#define GPIO_DRV3                ((APBADDR)(GPIO_base+0x3200))          /* IO Driving Control Register 3                 */
#define GPIO_DRV4                ((APBADDR)(GPIO_base+0x3300))          /* IO Driving Control Register 4                 */
#define GPIO_DRV5                ((APBADDR)(GPIO_base+0x3400))          /* IO Driving Control Register 5                 */
#define GPIO_DRV6                ((APBADDR)(GPIO_base+0x3500))          /* IO Driving Control Register 6                 */
#define GPIO_IES1                ((APBADDR)(GPIO_base+0x3C00))          /* IO Input Enable Control Register 1            */
#define GPIO_SR1                 ((APBADDR)(GPIO_base+0x4000))          /* IO Slew Rate Control Register 1               */
#define GPIO_SR2                 ((APBADDR)(GPIO_base+0x4100))          /* IO Slew Rate Control Register 2               */
#define GPIO_SR3                 ((APBADDR)(GPIO_base+0x4200))          /* IO Slew Rate Control Register 3               */
#define GPIO_SMT1                ((APBADDR)(GPIO_base+0x4400))          /* IO Schmitt Trigger Register 1                 */
#define GPIO_SMT2                ((APBADDR)(GPIO_base+0x4500))          /* IO Schmitt Trigger Register 2                 */
#define GPIO_SMT3                ((APBADDR)(GPIO_base+0x4600))          /* IO Schmitt Trigger Register 3                 */
#define GPIO_TDSEL1              ((APBADDR)(GPIO_base+0x4800))          /* IO TX Duty Register 1                         */
#define GPIO_TDSEL2              ((APBADDR)(GPIO_base+0x4900))          /* IO TX Duty Register 2                         */
#define GPIO_TDSEL3              ((APBADDR)(GPIO_base+0x4A00))          /* IO TX Duty Register 3                         */
#define GPIO_TDSEL4              ((APBADDR)(GPIO_base+0x4B00))          /* IO TX Duty Register 4                         */
#define GPIO_RDSEL1              ((APBADDR)(GPIO_base+0x4C00))          /* IO RX Duty Register 1                         */
#define GPIO_RDSEL2              ((APBADDR)(GPIO_base+0x4D00))          /* IO RX Duty Register 2                         */
#define GPIO_OTHER1              ((APBADDR)(GPIO_base+0x5C00))          /* IO Other Control Register 1                   */
#define CLK_OUT1                 ((APBADDR)(GPIO_base+0x7000))          /* CLK_OUT1 Setting                              */
#define CLK_OUT2                 ((APBADDR)(GPIO_base+0x7100))          /* CLK_OUT2 Setting                              */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_CHIP_MT6256 || IS_CHIP_MT6255 || IS_CHIP_MT6250
/* ===================================================================================================================== */
/* for MT6256                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GPIO_DIR1                ((APBADDR)(GPIO_base+0x0000))          /* GPIO Direction Register 1                     */
#define GPIO_DIR2                ((APBADDR)(GPIO_base+0x0010))          /* GPIO Direction Register 2                     */
#define GPIO_DIR3                ((APBADDR)(GPIO_base+0x0020))          /* GPIO Direction Register 3                     */
#define GPIO_DIR4                ((APBADDR)(GPIO_base+0x0030))          /* GPIO Direction Register 4                     */
#define GPIO_DIR5                ((APBADDR)(GPIO_base+0x0040))          /* GPIO Direction Register 5                     */
#define GPIO_DIR6                ((APBADDR)(GPIO_base+0x0050))          /* GPIO Direction Register 6                     */
#define GPIO_PULLEN1             ((APBADDR)(GPIO_base+0x0100))          /* GPIO Pull-up/Pull-down Enable Register 1      */
#define GPIO_PULLEN2             ((APBADDR)(GPIO_base+0x0110))          /* GPIO Pull-up/Pull-down Enable Register 2      */
#define GPIO_PULLEN3             ((APBADDR)(GPIO_base+0x0120))          /* GPIO Pull-up/Pull-down Enable Register 3      */
#define GPIO_PULLEN4             ((APBADDR)(GPIO_base+0x0130))          /* GPIO Pull-up/Pull-down Enable Register 4      */
#define GPIO_PULLEN5             ((APBADDR)(GPIO_base+0x0140))          /* GPIO Pull-up/Pull-down Enable Register 5      */
#define GPIO_PULLEN6             ((APBADDR)(GPIO_base+0x0150))          /* GPIO Pull-up/Pull-down Enable Register 6      */
#define GPIO_PULLSEL1            ((APBADDR)(GPIO_base+0x0200))          /* GPIO Pull-up/Pull-down Select Register 1      */
#define GPIO_PULLSEL2            ((APBADDR)(GPIO_base+0x0210))          /* GPIO Pull-up/Pull-down Select Register 2      */
#define GPIO_PULLSEL3            ((APBADDR)(GPIO_base+0x0220))          /* GPIO Pull-up/Pull-down Select Register 3      */
#define GPIO_PULLSEL4            ((APBADDR)(GPIO_base+0x0230))          /* GPIO Pull-up/Pull-down Select Register 4      */
#define GPIO_PULLSEL5            ((APBADDR)(GPIO_base+0x0240))          /* GPIO Pull-up/Pull-down Select Register 5      */
#define GPIO_PULLSEL6            ((APBADDR)(GPIO_base+0x0250))          /* GPIO Pull-up/Pull-down Select Register 6      */
#define GPIO_DINV1               ((APBADDR)(GPIO_base+0x0300))          /* Register 1                                    */
#define GPIO_DINV2               ((APBADDR)(GPIO_base+0x0310))          /* Register 2                                    */
#define GPIO_DINV3               ((APBADDR)(GPIO_base+0x0320))          /* Register 3                                    */
#define GPIO_DINV4               ((APBADDR)(GPIO_base+0x0330))          /* Register 4                                    */
#define GPIO_DINV5               ((APBADDR)(GPIO_base+0x0340))          /* Register 5                                    */
#define GPIO_DINV6               ((APBADDR)(GPIO_base+0x0350))          /* Register 6                                    */
#define GPIO_DOUT1               ((APBADDR)(GPIO_base+0x0400))          /* GPIO Data Output Register 1                   */
#define GPIO_DOUT2               ((APBADDR)(GPIO_base+0x0410))          /* GPIO Data Output Register 2                   */
#define GPIO_DOUT3               ((APBADDR)(GPIO_base+0x0420))          /* GPIO Data Output Register 3                   */
#define GPIO_DOUT4               ((APBADDR)(GPIO_base+0x0430))          /* GPIO Data Output Register 4                   */
#define GPIO_DOUT5               ((APBADDR)(GPIO_base+0x0440))          /* GPIO Data Output Register 5                   */
#define GPIO_DOUT6               ((APBADDR)(GPIO_base+0x0450))          /* GPIO Data Output Register 6                   */
#define GPIO_DIN1                ((APBADDR)(GPIO_base+0x0500))          /* GPIO Data input Register 1                    */
#define GPIO_DIN2                ((APBADDR)(GPIO_base+0x0510))          /* GPIO Data input Register 2                    */
#define GPIO_DIN3                ((APBADDR)(GPIO_base+0x0520))          /* GPIO Data input Register 3                    */
#define GPIO_DIN4                ((APBADDR)(GPIO_base+0x0530))          /* GPIO Data input Register 4                    */
#define GPIO_DIN5                ((APBADDR)(GPIO_base+0x0540))          /* GPIO Data input Register 5                    */
#define GPIO_DIN6                ((APBADDR)(GPIO_base+0x0550))          /* GPIO Data input Register 6                    */
#define GPIO_MODE1               ((APBADDR)(GPIO_base+0x0600))          /* GPIO Mode Control Register 1                  */
#define GPIO_MODE2               ((APBADDR)(GPIO_base+0x0610))          /* GPIO Mode Control Register 2                  */
#define GPIO_MODE3               ((APBADDR)(GPIO_base+0x0620))          /* GPIO Mode Control Register 3                  */
#define GPIO_MODE4               ((APBADDR)(GPIO_base+0x0630))          /* GPIO Mode Control Register 4                  */
#define GPIO_MODE5               ((APBADDR)(GPIO_base+0x0640))          /* GPIO Mode Control Register 5                  */
#define GPIO_MODE6               ((APBADDR)(GPIO_base+0x0650))          /* GPIO Mode Control Register 6                  */
#define GPIO_MODE7               ((APBADDR)(GPIO_base+0x0660))          /* GPIO Mode Control Register 7                  */
#define GPIO_MODE8               ((APBADDR)(GPIO_base+0x0670))          /* GPIO Mode Control Register 8                  */
#define GPIO_MODE9               ((APBADDR)(GPIO_base+0x0680))          /* GPIO Mode Control Register 9                  */
#define GPIO_MODE10              ((APBADDR)(GPIO_base+0x0690))          /* GPIO Mode Control Register 10                 */
#define GPIO_MODE11              ((APBADDR)(GPIO_base+0x06A0))          /* GPIO Mode Control Register 11                 */
#define GPIO_MODE12              ((APBADDR)(GPIO_base+0x06B0))          /* GPIO Mode Control Register 12                 */
#define GPIO_MODE13              ((APBADDR)(GPIO_base+0x06C0))          /* GPIO Mode Control Register 13                 */
#define GPIO_MODE14              ((APBADDR)(GPIO_base+0x06D0))          /* GPIO Mode Control Register 14                 */
#define GPIO_MODE15              ((APBADDR)(GPIO_base+0x06E0))          /* GPIO Mode Control Register 15                 */
#define GPIO_MODE16              ((APBADDR)(GPIO_base+0x06F0))          /* GPIO Mode Control Register 16                 */
#define GPIO_MODE17              ((APBADDR)(GPIO_base+0x0700))          /* GPIO Mode Control Register 17                 */
#define GPIO_MODE18              ((APBADDR)(GPIO_base+0x0710))          /* GPIO Mode Control Register 18                 */
#define GPIO_MODE19              ((APBADDR)(GPIO_base+0x0720))          /* GPIO Mode Control Register 19                 */
#define GPIO_MODE20              ((APBADDR)(GPIO_base+0x0730))          /* GPIO Mode Control Register 20                 */
#define GPIO_MODE21              ((APBADDR)(GPIO_base+0x0740))          /* GPIO Mode Control Register 21                 */
#define GPIO_MODE22              ((APBADDR)(GPIO_base+0x0750))          /* GPIO Mode Control Register 22                 */
#define GPIO_MODE23              ((APBADDR)(GPIO_base+0x0760))          /* GPIO Mode Control Register 23                 */
#define GPIO_MODE24              ((APBADDR)(GPIO_base+0x0770))          /* GPIO Mode Control Register 24                 */
#define CLK_OUT0                 ((APBADDR)(GPIO_base+0x0900))          /* CLK_OUT0 Setting                              */
#define CLK_OUT1                 ((APBADDR)(GPIO_base+0x0910))          /* CLK_OUT1 Setting                              */
#define CLK_OUT2                 ((APBADDR)(GPIO_base+0x0920))          /* CLK_OUT2 Setting                              */
#define CLK_OUT3                 ((APBADDR)(GPIO_base+0x0930))          /* CLK_OUT3 Setting                              */
#define CLK_OUT4                 ((APBADDR)(GPIO_base+0x0940))          /* CLK_OUT4 Setting                              */
#define CLK_OUT5                 ((APBADDR)(GPIO_base+0x0950))          /* CLK_OUT5 Setting                              */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_CHIP_MT6251
/* ===================================================================================================================== */
/* for MT6251                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GPIO_DIR1                ((APBADDR)(GPIO_base+0x0000))          /* GPIO Direction Register 1                     */
#define GPIO_DIR2                ((APBADDR)(GPIO_base+0x0010))          /* GPIO Direction Register 2                     */
#define GPIO_DIR3                ((APBADDR)(GPIO_base+0x0020))          /* GPIO Direction Register 3                     */
#define GPIO_PULLEN1             ((APBADDR)(GPIO_base+0x0050))          /* GPIO Pull-up/Pull-down Enable Register 1      */
#define GPIO_PULLEN2             ((APBADDR)(GPIO_base+0x0060))          /* GPIO Pull-up/Pull-down Enable Register 2      */
#define GPIO_PULLEN3             ((APBADDR)(GPIO_base+0x0070))          /* GPIO Pull-up/Pull-down Enable Register 3      */
#define GPIO_DINV1               ((APBADDR)(GPIO_base+0x00A0))          /* Register 1                                    */
#define GPIO_DINV2               ((APBADDR)(GPIO_base+0x00B0))          /* Register 2                                    */
#define GPIO_DINV3               ((APBADDR)(GPIO_base+0x00C0))          /* Register 3                                    */
#define GPIO_DOUT1               ((APBADDR)(GPIO_base+0x00F0))          /* GPIO Data Output Register 1                   */
#define GPIO_DOUT2               ((APBADDR)(GPIO_base+0x0100))          /* GPIO Data Output Register 2                   */
#define GPIO_DOUT3               ((APBADDR)(GPIO_base+0x0110))          /* GPIO Data Output Register 3                   */
#define GPIO_DIN1                ((APBADDR)(GPIO_base+0x0140))          /* GPIO Data input Register 1                    */
#define GPIO_DIN2                ((APBADDR)(GPIO_base+0x0150))          /* GPIO Data input Register 2                    */
#define GPIO_DIN3                ((APBADDR)(GPIO_base+0x0160))          /* GPIO Data input Register 3                    */
#define GPIO_MODE1               ((APBADDR)(GPIO_base+0x0190))          /* GPIO Mode Control Register 1                  */
#define GPIO_MODE2               ((APBADDR)(GPIO_base+0x01A0))          /* GPIO Mode Control Register 2                  */
#define GPIO_MODE3               ((APBADDR)(GPIO_base+0x01B0))          /* GPIO Mode Control Register 3                  */
#define GPIO_MODE4               ((APBADDR)(GPIO_base+0x01C0))          /* GPIO Mode Control Register 4                  */
#define GPIO_MODE5               ((APBADDR)(GPIO_base+0x01D0))          /* GPIO Mode Control Register 5                  */
#define GPIO_MODE6               ((APBADDR)(GPIO_base+0x01E0))          /* GPIO Mode Control Register 6                  */
#define GPIO_MODE7               ((APBADDR)(GPIO_base+0x01F0))          /* GPIO Mode Control Register 7                  */
#define GPIO_MODE8               ((APBADDR)(GPIO_base+0x0200))          /* GPIO Mode Control Register 8                  */
#define GPIO_PULLSEL1            ((APBADDR)(GPIO_base+0x0240))          /* GPIO Pull-up/Pull-down Select Register 1      */
#define GPIO_PULLSEL2            ((APBADDR)(GPIO_base+0x0250))          /* GPIO Pull-up/Pull-down Select Register 2      */
#define GPIO_PULLSEL3            ((APBADDR)(GPIO_base+0x0260))          /* GPIO Pull-up/Pull-down Select Register 3      */
#define CLK_OUT0                 ((APBADDR)(GPIO_base+0x0300))          /* CLK_OUT0 Setting                              */
#define CLK_OUT1                 ((APBADDR)(GPIO_base+0x0310))          /* CLK_OUT1 Setting                              */
#define CLK_OUT2                 ((APBADDR)(GPIO_base+0x0320))          /* CLK_OUT2 Setting                              */
#define CLK_OUT3                 ((APBADDR)(GPIO_base+0x0330))          /* CLK_OUT3 Setting                              */
#endif
#if IS_CHIP_MT6276
/* ===================================================================================================================== */
/* for MT6276                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GPIO_DIR1                ((APBADDR)(GPIO_base+0x0000))          /* GPIO Direction Register 1                     */
#define GPIO_DIR2                ((APBADDR)(GPIO_base+0x0040))          /* GPIO Direction Register 2                     */
#define GPIO_DIR3                ((APBADDR)(GPIO_base+0x0080))          /* GPIO Direction Register 3                     */
#define GPIO_DIR4                ((APBADDR)(GPIO_base+0x00C0))          /* GPIO Direction Register 4                     */
#define GPIO_DIR5                ((APBADDR)(GPIO_base+0x0100))          /* GPIO Direction Register 5                     */
#define GPIO_DIR6                ((APBADDR)(GPIO_base+0x0140))          /* GPIO Direction Register 6                     */
#define GPIO_DIR7                ((APBADDR)(GPIO_base+0x0180))          /* GPIO Direction Register 7                     */
#define GPIO_PULLEN1             ((APBADDR)(GPIO_base+0x0200))          /* GPIO Pull-up/Pull-down Enable Register 1      */
#define GPIO_PULLEN2             ((APBADDR)(GPIO_base+0x0240))          /* GPIO Pull-up/Pull-down Enable Register 2      */
#define GPIO_PULLEN3             ((APBADDR)(GPIO_base+0x0280))          /* GPIO Pull-up/Pull-down Enable Register 3      */
#define GPIO_PULLEN4             ((APBADDR)(GPIO_base+0x02C0))          /* GPIO Pull-up/Pull-down Enable Register 4      */
#define GPIO_PULLEN5             ((APBADDR)(GPIO_base+0x0300))          /* GPIO Pull-up/Pull-down Enable Register 5      */
#define GPIO_PULLEN6             ((APBADDR)(GPIO_base+0x0340))          /* GPIO Pull-up/Pull-down Enable Register 6      */
#define GPIO_PULLEN7             ((APBADDR)(GPIO_base+0x0380))          /* GPIO Pull-up/Pull-down Enable Register 7      */
#define GPIO_PULLSEL1            ((APBADDR)(GPIO_base+0x0400))          /* GPIO Pull-up/Pull-down Select Register 1      */
#define GPIO_PULLSEL2            ((APBADDR)(GPIO_base+0x0440))          /* GPIO Pull-up/Pull-down Select Register 2      */
#define GPIO_PULLSEL3            ((APBADDR)(GPIO_base+0x0480))          /* GPIO Pull-up/Pull-down Select Register 3      */
#define GPIO_PULLSEL4            ((APBADDR)(GPIO_base+0x04C0))          /* GPIO Pull-up/Pull-down Select Register 4      */
#define GPIO_PULLSEL5            ((APBADDR)(GPIO_base+0x0500))          /* GPIO Pull-up/Pull-down Select Register 5      */
#define GPIO_PULLSEL6            ((APBADDR)(GPIO_base+0x0540))          /* GPIO Pull-up/Pull-down Select Register 6      */
#define GPIO_PULLSEL7            ((APBADDR)(GPIO_base+0x0580))          /* GPIO Pull-up/Pull-down Select Register 7      */
#define GPIO_DINV1               ((APBADDR)(GPIO_base+0x0600))          /* Register 1                                    */
#define GPIO_DINV2               ((APBADDR)(GPIO_base+0x0640))          /* Register 2                                    */
#define GPIO_DINV3               ((APBADDR)(GPIO_base+0x0680))          /* Register 3                                    */
#define GPIO_DINV4               ((APBADDR)(GPIO_base+0x06C0))          /* Register 4                                    */
#define GPIO_DINV5               ((APBADDR)(GPIO_base+0x0700))          /* Register 5                                    */
#define GPIO_DINV6               ((APBADDR)(GPIO_base+0x0740))          /* Register 6                                    */
#define GPIO_DINV7               ((APBADDR)(GPIO_base+0x0780))          /* Register 7                                    */
#define GPIO_DOUT1               ((APBADDR)(GPIO_base+0x0800))          /* GPIO Data Output Register 1                   */
#define GPIO_DOUT2               ((APBADDR)(GPIO_base+0x0840))          /* GPIO Data Output Register 2                   */
#define GPIO_DOUT3               ((APBADDR)(GPIO_base+0x0880))          /* GPIO Data Output Register 3                   */
#define GPIO_DOUT4               ((APBADDR)(GPIO_base+0x08C0))          /* GPIO Data Output Register 4                   */
#define GPIO_DOUT5               ((APBADDR)(GPIO_base+0x0900))          /* GPIO Data Output Register 5                   */
#define GPIO_DOUT6               ((APBADDR)(GPIO_base+0x0940))          /* GPIO Data Output Register 6                   */
#define GPIO_DOUT7               ((APBADDR)(GPIO_base+0x0980))          /* GPIO Data Output Register 7                   */
#define GPIO_DIN1                ((APBADDR)(GPIO_base+0x0A00))          /* GPIO Data input Register 1                    */
#define GPIO_DIN2                ((APBADDR)(GPIO_base+0x0A40))          /* GPIO Data input Register 2                    */
#define GPIO_DIN3                ((APBADDR)(GPIO_base+0x0A80))          /* GPIO Data input Register 3                    */
#define GPIO_DIN4                ((APBADDR)(GPIO_base+0x0AC0))          /* GPIO Data input Register 4                    */
#define GPIO_DIN5                ((APBADDR)(GPIO_base+0x0B00))          /* GPIO Data input Register 5                    */
#define GPIO_DIN6                ((APBADDR)(GPIO_base+0x0B40))          /* GPIO Data input Register 6                    */
#define GPIO_DIN7                ((APBADDR)(GPIO_base+0x0B80))          /* GPIO Data input Register 7                    */
#define GPIO_MODE1               ((APBADDR)(GPIO_base+0x1000))          /* GPIO Mode Control Register 1                  */
#define GPIO_MODE2               ((APBADDR)(GPIO_base+0x1100))          /* GPIO Mode Control Register 2                  */
#define GPIO_MODE3               ((APBADDR)(GPIO_base+0x1200))          /* GPIO Mode Control Register 3                  */
#define GPIO_MODE4               ((APBADDR)(GPIO_base+0x1300))          /* GPIO Mode Control Register 4                  */
#define GPIO_MODE5               ((APBADDR)(GPIO_base+0x1400))          /* GPIO Mode Control Register 5                  */
#define GPIO_MODE6               ((APBADDR)(GPIO_base+0x1500))          /* GPIO Mode Control Register 6                  */
#define GPIO_MODE7               ((APBADDR)(GPIO_base+0x1600))          /* GPIO Mode Control Register 7                  */
#define GPIO_MODE8               ((APBADDR)(GPIO_base+0x1700))          /* GPIO Mode Control Register 8                  */
#define GPIO_MODE9               ((APBADDR)(GPIO_base+0x1800))          /* GPIO Mode Control Register 9                  */
#define GPIO_MODEA               ((APBADDR)(GPIO_base+0x1900))          /* GPIO Mode Control Register A                  */
#define GPIO_MODEB               ((APBADDR)(GPIO_base+0x1A00))          /* GPIO Mode Control Register B                  */
#define GPIO_MODEC               ((APBADDR)(GPIO_base+0x1B00))          /* GPIO Mode Control Register C                  */
#define GPIO_MODED               ((APBADDR)(GPIO_base+0x1C00))          /* GPIO Mode Control Register D                  */
#define GPIO_MODEE               ((APBADDR)(GPIO_base+0x1D00))          /* GPIO Mode Control Register E                  */
#define GPIO_BANK                ((APBADDR)(GPIO_base+0x2000))          /* GPIO bank register                            */
#define CLK_OUT1                 ((APBADDR)(GPIO_base+0x3000))          /* CLK_OUT1 Setting                              */
#define CLK_OUT2                 ((APBADDR)(GPIO_base+0x3100))          /* CLK_OUT2 Setting                              */
#define CLK_OUT3                 ((APBADDR)(GPIO_base+0x3200))          /* CLK_OUT3 Setting                              */
#define CLK_OUT4                 ((APBADDR)(GPIO_base+0x3300))          /* CLK_OUT4 Setting                              */
#define CLK_OUT5                 ((APBADDR)(GPIO_base+0x3400))          /* CLK_OUT5 Setting                              */
#define CLK_OUT6                 ((APBADDR)(GPIO_base+0x3500))          /* CLK_OUT6 Setting                              */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_CHIP_MT6573 || IS_CHIP_MT6575
/* ===================================================================================================================== */
/* for MT6573                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define GPIO_DIR0                ((APBADDR)(GPIO_base+0x0000))          /* GPIO Direction Select Register 0              */
#define GPIO_DIR1                ((APBADDR)(GPIO_base+0x0010))          /* GPIO Direction Select Register 1              */
#define GPIO_DIR2                ((APBADDR)(GPIO_base+0x0020))          /* GPIO Direction Select Register 2              */
#define GPIO_DIR3                ((APBADDR)(GPIO_base+0x0030))          /* GPIO Direction Select Register 3              */
#define GPIO_DIR4                ((APBADDR)(GPIO_base+0x0040))          /* GPIO Direction Select Register 4              */
#define GPIO_DIR5                ((APBADDR)(GPIO_base+0x0050))          /* GPIO Direction Select Register 5              */
#define GPIO_DIR6                ((APBADDR)(GPIO_base+0x0060))          /* GPIO Direction Select Register 6              */
#define GPIO_DIR7                ((APBADDR)(GPIO_base+0x0070))          /* GPIO Direction Select Register 7              */
#define GPIO_DIR8                ((APBADDR)(GPIO_base+0x0080))          /* GPIO Direction Select Register 8              */
#define GPIO_DIR9                ((APBADDR)(GPIO_base+0x0090))          /* GPIO Direction Select Register 9              */
#define GPIO_DIRA                ((APBADDR)(GPIO_base+0x00A0))          /* GPIO Direction Select Register A              */
#define GPIO_DIRB                ((APBADDR)(GPIO_base+0x00B0))          /* GPIO Direction Select Register B              */
#define GPIO_DIRC                ((APBADDR)(GPIO_base+0x00C0))          /* GPIO Direction Select Register C              */
#define GPIO_PULLEN0             ((APBADDR)(GPIO_base+0x0200))          /* GPIO Pull-up/Pull-down Enable Register 1      */
#define GPIO_PULLEN1             ((APBADDR)(GPIO_base+0x0210))          /* GPIO Pull-up/Pull-down Enable Register 2      */
#define GPIO_PULLEN2             ((APBADDR)(GPIO_base+0x0220))          /* GPIO Pull-up/Pull-down Enable Register 3      */
#define GPIO_PULLEN3             ((APBADDR)(GPIO_base+0x0230))          /* GPIO Pull-up/Pull-down Enable Register 4      */
#define GPIO_PULLEN4             ((APBADDR)(GPIO_base+0x0240))          /* GPIO Pull-up/Pull-down Enable Register 5      */
#define GPIO_PULLEN5             ((APBADDR)(GPIO_base+0x0250))          /* GPIO Pull-up/Pull-down Enable Register 6      */
#define GPIO_PULLEN6             ((APBADDR)(GPIO_base+0x0260))          /* GPIO Pull-up/Pull-down Enable Register 7      */
#define GPIO_PULLEN7             ((APBADDR)(GPIO_base+0x0270))          /* GPIO Pull-up/Pull-down Enable Register 1      */
#define GPIO_PULLEN8             ((APBADDR)(GPIO_base+0x0280))          /* GPIO Pull-up/Pull-down Enable Register 2      */
#define GPIO_PULLEN9             ((APBADDR)(GPIO_base+0x0290))          /* GPIO Pull-up/Pull-down Enable Register 3      */
#define GPIO_PULLENA             ((APBADDR)(GPIO_base+0x02A0))          /* GPIO Pull-up/Pull-down Enable Register 4      */
#define GPIO_PULLENB             ((APBADDR)(GPIO_base+0x02B0))          /* GPIO Pull-up/Pull-down Enable Register 5      */
#define GPIO_PULLENC             ((APBADDR)(GPIO_base+0x02C0))          /* GPIO Pull-up/Pull-down Enable Register 6      */
#define GPIO_PULLSEL0            ((APBADDR)(GPIO_base+0x0400))          /* GPIO Pull-up/Pull-down Select Register 1      */
#define GPIO_PULLSEL1            ((APBADDR)(GPIO_base+0x0410))          /* GPIO Pull-up/Pull-down Select Register 2      */
#define GPIO_PULLSEL2            ((APBADDR)(GPIO_base+0x0420))          /* GPIO Pull-up/Pull-down Select Register 3      */
#define GPIO_PULLSEL3            ((APBADDR)(GPIO_base+0x0430))          /* GPIO Pull-up/Pull-down Select Register 4      */
#define GPIO_PULLSEL4            ((APBADDR)(GPIO_base+0x0440))          /* GPIO Pull-up/Pull-down Select Register 5      */
#define GPIO_PULLSEL5            ((APBADDR)(GPIO_base+0x0450))          /* GPIO Pull-up/Pull-down Select Register 6      */
#define GPIO_PULLSEL6            ((APBADDR)(GPIO_base+0x0460))          /* GPIO Pull-up/Pull-down Select Register 7      */
#define GPIO_PULLSEL7            ((APBADDR)(GPIO_base+0x0470))          /* GPIO Pull-up/Pull-down Select Register 1      */
#define GPIO_PULLSEL8            ((APBADDR)(GPIO_base+0x0480))          /* GPIO Pull-up/Pull-down Select Register 2      */
#define GPIO_PULLSEL9            ((APBADDR)(GPIO_base+0x0490))          /* GPIO Pull-up/Pull-down Select Register 3      */
#define GPIO_PULLSELA            ((APBADDR)(GPIO_base+0x04A0))          /* GPIO Pull-up/Pull-down Select Register 4      */
#define GPIO_PULLSELB            ((APBADDR)(GPIO_base+0x04B0))          /* GPIO Pull-up/Pull-down Select Register 5      */
#define GPIO_PULLSELC            ((APBADDR)(GPIO_base+0x04C0))          /* GPIO Pull-up/Pull-down Select Register 6      */
#define GPIO_DINV0               ((APBADDR)(GPIO_base+0x0600))          /* GPI Invert Enable Register 0                  */
#define GPIO_DINV1               ((APBADDR)(GPIO_base+0x0610))          /* GPI Invert Enable Register 1                  */
#define GPIO_DINV2               ((APBADDR)(GPIO_base+0x0620))          /* GPI Invert Enable Register 2                  */
#define GPIO_DINV3               ((APBADDR)(GPIO_base+0x0630))          /* GPI Invert Enable Register 3                  */
#define GPIO_DINV4               ((APBADDR)(GPIO_base+0x0640))          /* GPI Invert Enable Register 4                  */
#define GPIO_DINV5               ((APBADDR)(GPIO_base+0x0650))          /* GPI Invert Enable Register 5                  */
#define GPIO_DINV6               ((APBADDR)(GPIO_base+0x0660))          /* GPI Invert Enable Register 6                  */
#define GPIO_DINV7               ((APBADDR)(GPIO_base+0x0670))          /* GPI Invert Enable Register 7                  */
#define GPIO_DINV8               ((APBADDR)(GPIO_base+0x0680))          /* GPI Invert Enable Register 8                  */
#define GPIO_DINV9               ((APBADDR)(GPIO_base+0x0690))          /* GPI Invert Enable Register 9                  */
#define GPIO_DINVA               ((APBADDR)(GPIO_base+0x06A0))          /* GPI Invert Enable Register A                  */
#define GPIO_DINVB               ((APBADDR)(GPIO_base+0x06B0))          /* GPI Invert Enable Register B                  */
#define GPIO_DINVC               ((APBADDR)(GPIO_base+0x06C0))          /* GPI Invert Enable Register C                  */
#define GPIO_DOUT0               ((APBADDR)(GPIO_base+0x0800))          /* GPIO Data Output Register 0                   */
#define GPIO_DOUT1               ((APBADDR)(GPIO_base+0x0810))          /* GPIO Data Output Register 1                   */
#define GPO0_SET                 ((APBADDR)(GPIO_base+0x0804))          /* GPIO Set Data Output Register 0               */
#define GPO0_RESET               ((APBADDR)(GPIO_base+0x0808))          /* GPIO Reset Data Output Register 0             */
#define GPO1_SET                 ((APBADDR)(GPIO_base+0x0814))          /* GPIO Set Data Output Register 1               */
#define GPO1_RESET               ((APBADDR)(GPIO_base+0x0818))          /* GPIO Reset Data Output Register 1             */
#define GPO2_SET                 ((APBADDR)(GPIO_base+0x0824))          /* GPIO Set Data Output Register 1               */
#define GPO2_RESET               ((APBADDR)(GPIO_base+0x0828))          /* GPIO Reset Data Output Register 1             */
#define GPO3_SET                 ((APBADDR)(GPIO_base+0x0834))          /* GPIO Set Data Output Register 1               */
#define GPO3_RESET               ((APBADDR)(GPIO_base+0x0838))          /* GPIO Reset Data Output Register 1             */
#define GPO4_SET                 ((APBADDR)(GPIO_base+0x0844))          /* GPIO Set Data Output Register 1               */
#define GPO4_RESET               ((APBADDR)(GPIO_base+0x0848))          /* GPIO Reset Data Output Register 1             */
#define GPO5_SET                 ((APBADDR)(GPIO_base+0x0854))          /* GPIO Set Data Output Register 1               */
#define GPO5_RESET               ((APBADDR)(GPIO_base+0x0858))          /* GPIO Reset Data Output Register 1             */
#define GPO6_SET                 ((APBADDR)(GPIO_base+0x0864))          /* GPIO Set Data Output Register 1               */
#define GPO6_RESET               ((APBADDR)(GPIO_base+0x0868))          /* GPIO Reset Data Output Register 1             */
#define GPO7_SET                 ((APBADDR)(GPIO_base+0x0874))          /* GPIO Set Data Output Register 1               */
#define GPO7_RESET               ((APBADDR)(GPIO_base+0x0878))          /* GPIO Reset Data Output Register 1             */
#define GPO8_SET                 ((APBADDR)(GPIO_base+0x0884))          /* GPIO Set Data Output Register 1               */
#define GPO8_RESET               ((APBADDR)(GPIO_base+0x0888))          /* GPIO Reset Data Output Register 1             */
#define GPO9_SET                 ((APBADDR)(GPIO_base+0x0894))          /* GPIO Set Data Output Register 1               */
#define GPO9_RESET               ((APBADDR)(GPIO_base+0x0898))          /* GPIO Reset Data Output Register 1             */
#define GPO10_SET                ((APBADDR)(GPIO_base+0x08A4))          /* GPIO Set Data Output Register 1               */
#define GPO10_RESET              ((APBADDR)(GPIO_base+0x08A8))          /* GPIO Reset Data Output Register 1             */
#define GPO11_SET                ((APBADDR)(GPIO_base+0x08B4))          /* GPIO Set Data Output Register 1               */
#define GPO11_RESET              ((APBADDR)(GPIO_base+0x08B8))          /* GPIO Reset Data Output Register 1             */
#define GPO12_SET                ((APBADDR)(GPIO_base+0x08C4))          /* GPIO Set Data Output Register 1               */
#define GPO12_RESET              ((APBADDR)(GPIO_base+0x08C8))          /* GPIO Reset Data Output Register 1             */
#define GPO_SET(m)               ((APBADDR)(GPIO_base+0x0804+(m)*0x10))
#define GPO_RESET(m)             ((APBADDR)(GPIO_base+0x0808+(m)*0x10))
#define GPIO_DOUT2               ((APBADDR)(GPIO_base+0x0820))          /* GPIO Data Output Register 2                   */
#define GPIO_DOUT3               ((APBADDR)(GPIO_base+0x0830))          /* GPIO Data Output Register 3                   */
#define GPIO_DOUT4               ((APBADDR)(GPIO_base+0x0840))          /* GPIO Data Output Register 4                   */
#define GPIO_DOUT5               ((APBADDR)(GPIO_base+0x0850))          /* GPIO Data Output Register 5                   */
#define GPIO_DOUT6               ((APBADDR)(GPIO_base+0x0860))          /* GPIO Data Output Register 6                   */
#define GPIO_DOUT7               ((APBADDR)(GPIO_base+0x0870))          /* GPIO Data Output Register 7                   */
#define GPIO_DOUT8               ((APBADDR)(GPIO_base+0x0880))          /* GPIO Data Output Register 8                   */
#define GPIO_DOUT9               ((APBADDR)(GPIO_base+0x0890))          /* GPIO Data Output Register 9                   */
#define GPIO_DOUTA               ((APBADDR)(GPIO_base+0x08A0))          /* GPIO Data Output Register A                   */
#define GPIO_DOUTB               ((APBADDR)(GPIO_base+0x08B0))          /* GPIO Data Output Register B                   */
#define GPIO_DOUTC               ((APBADDR)(GPIO_base+0x08C0))          /* GPIO Data Output Register C                   */
#define GPIO_DIN0                ((APBADDR)(GPIO_base+0x0A00))          /* GPIO Data Input Register 0                    */
#define GPIO_DIN1                ((APBADDR)(GPIO_base+0x0A10))          /* GPIO Data Input Register 1                    */
#define GPIO_DIN2                ((APBADDR)(GPIO_base+0x0A20))          /* GPIO Data Input Register 2                    */
#define GPIO_DIN3                ((APBADDR)(GPIO_base+0x0A30))          /* GPIO Data Input Register 3                    */
#define GPIO_DIN4                ((APBADDR)(GPIO_base+0x0A40))          /* GPIO Data Input Register 4                    */
#define GPIO_DIN5                ((APBADDR)(GPIO_base+0x0A50))          /* GPIO Data Input Register 5                    */
#define GPIO_DIN6                ((APBADDR)(GPIO_base+0x0A60))          /* GPIO Data Input Register 6                    */
#define GPIO_DIN7                ((APBADDR)(GPIO_base+0x0A70))          /* GPIO Data Input Register 7                    */
#define GPIO_DIN8                ((APBADDR)(GPIO_base+0x0A80))          /* GPIO Data Input Register 8                    */
#define GPIO_DIN9                ((APBADDR)(GPIO_base+0x0A90))          /* GPIO Data Input Register 9                    */
#define GPIO_DINA                ((APBADDR)(GPIO_base+0x0AA0))          /* GPIO Data Input Register A                    */
#define GPIO_DINB                ((APBADDR)(GPIO_base+0x0AB0))          /* GPIO Data Input Register B                    */
#define GPIO_DINC                ((APBADDR)(GPIO_base+0x0AC0))          /* GPIO Data Input Register C                    */
#define GPIO_MODE0               ((APBADDR)(GPIO_base+0x0C00))          /* GPIO Mode Control Register 0                  */
#define GPIO_MODE1               ((APBADDR)(GPIO_base+0x0C10))          /* GPIO Mode Control Register 1                  */
#define GPIO_MODE2               ((APBADDR)(GPIO_base+0x0C20))          /* GPIO Mode Control Register 2                  */
#define GPIO_MODE3               ((APBADDR)(GPIO_base+0x0C30))          /* GPIO Mode Control Register 3                  */
#define GPIO_MODE4               ((APBADDR)(GPIO_base+0x0C40))          /* GPIO Mode Control Register 4                  */
#define GPIO_MODE5               ((APBADDR)(GPIO_base+0x0C50))          /* GPIO Mode Control Register 5                  */
#define GPIO_MODE6               ((APBADDR)(GPIO_base+0x0C60))          /* GPIO Mode Control Register 6                  */
#define GPIO_MODE7               ((APBADDR)(GPIO_base+0x0C70))          /* GPIO Mode Control Register 7                  */
#define GPIO_MODE8               ((APBADDR)(GPIO_base+0x0C80))          /* GPIO Mode Control Register 8                  */
#define GPIO_MODE9               ((APBADDR)(GPIO_base+0x0C90))          /* GPIO Mode Control Register 9                  */
#define GPIO_MODEA               ((APBADDR)(GPIO_base+0x0CA0))          /* GPIO Mode Control Register 10                 */
#define GPIO_MODEB               ((APBADDR)(GPIO_base+0x0CB0))          /* GPIO Mode Control Register 11                 */
#define GPIO_MODEC               ((APBADDR)(GPIO_base+0x0CC0))          /* GPIO Mode Control Register 12                 */
#define GPIO_MODED               ((APBADDR)(GPIO_base+0x0CD0))          /* GPIO Mode Control Register 13                 */
#define GPIO_MODEE               ((APBADDR)(GPIO_base+0x0CE0))          /* GPIO Mode Control Register 14                 */
#define GPIO_MODEF               ((APBADDR)(GPIO_base+0x0CF0))          /* GPIO Mode Control Register 15                 */
#define GPIO_MODE10              ((APBADDR)(GPIO_base+0x0D00))          /* GPIO Mode Control Register 16                 */
#define GPIO_MODE11              ((APBADDR)(GPIO_base+0x0D10))          /* GPIO Mode Control Register 17                 */
#define GPIO_MODE12              ((APBADDR)(GPIO_base+0x0D20))          /* GPIO Mode Control Register 18                 */
#define GPIO_MODE13              ((APBADDR)(GPIO_base+0x0D30))          /* GPIO Mode Control Register 19                 */
#define GPIO_MODE14              ((APBADDR)(GPIO_base+0x0D40))          /* GPIO Mode Control Register 20                 */
#define GPIO_MODE15              ((APBADDR)(GPIO_base+0x0D50))          /* GPIO Mode Control Register 21                 */
#define GPIO_MODE16              ((APBADDR)(GPIO_base+0x0D60))          /* GPIO Mode Control Register 22                 */
#define GPIO_MODE17              ((APBADDR)(GPIO_base+0x0D70))          /* GPIO Mode Control Register 23                 */
#define GPIO_MODE18              ((APBADDR)(GPIO_base+0x0D80))          /* GPIO Mode Control Register 24                 */
#define GPIO_MODE19              ((APBADDR)(GPIO_base+0x0D90))          /* GPIO Mode Control Register 25                 */
#define GPIO_MODE1A              ((APBADDR)(GPIO_base+0x0DA0))          /* GPIO Mode Control Register 26                 */
#define GPIO_MODE1B              ((APBADDR)(GPIO_base+0x0DB0))          /* GPIO Mode Control Register 27                 */
#define GPIO_MODE1C              ((APBADDR)(GPIO_base+0x0DC0))          /* GPIO Mode Control Register 28                 */
#define GPIO_MODE1D              ((APBADDR)(GPIO_base+0x0DD0))          /* GPIO Mode Control Register 29                 */
#define GPIO_MODE1E              ((APBADDR)(GPIO_base+0x0DE0))          /* GPIO Mode Control Register 30                 */
#define GPIO_MODE1F              ((APBADDR)(GPIO_base+0x0DF0))          /* GPIO Mode Control Register 31                 */
#define GPIO_MODE20              ((APBADDR)(GPIO_base+0x0E00))          /* GPIO Mode Control Register 32                 */
#define GPIO_MODE21              ((APBADDR)(GPIO_base+0x0E10))          /* GPIO Mode Control Register 33                 */
#define GPIO_MODE22              ((APBADDR)(GPIO_base+0x0E20))          /* GPIO Mode Control Register 34                 */
#define GPIO_MODE23              ((APBADDR)(GPIO_base+0x0E30))          /* GPIO Mode Control Register 35                 */
#define GPIO_MODE24              ((APBADDR)(GPIO_base+0x0E40))          /* GPIO Mode Control Register 36                 */
#define GPIO_MODE25              ((APBADDR)(GPIO_base+0x0E50))          /* GPIO Mode Control Register 37                 */
#define GPIO_MODE26              ((APBADDR)(GPIO_base+0x0E60))          /* GPIO Mode Control Register 38                 */
#define GPIO_MODE27              ((APBADDR)(GPIO_base+0x0E70))          /* GPIO Mode Control Register 39                 */
#define GPIO_MODE28              ((APBADDR)(GPIO_base+0x0E80))          /* GPIO Mode Control Register 40                 */
/* --------------------------------------------------------------------------------------------------------------------- */
#endif

/*=================*\
|* IRDBG Registers *|
\*=================*/
#if IS_65NM_CHIP
/* ===================================================================================================================== */
/* for MT6268                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
   #if IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2

   #elif IS_CACHE_DSP_SUPPORT || IS_CHIP_MT6255
#define IRDBG_STA                ((APBADDR)(IRDBG_base+0x0000))         /* IRDBG status for MCU                          */
#define CMW_EM_ADDRU             ((APBADDR)(IRDBG_base+0x0004))         /* Start point of CMW of EMI, upper half address */
#define CMW_EM_ADDRL             ((APBADDR)(IRDBG_base+0x0008))         /* Start point of CMW of EMI, lower half address */
#define CMW_CM_ADDR              ((APBADDR)(IRDBG_base+0x000C))         /* Destination in CMW of CM                      */
#define CMW_CM_PAGE              ((APBADDR)(IRDBG_base+0x0010))         /* Page number of CM access                      */
#define CMW_QUE_STA              ((APBADDR)(IRDBG_base+0x0014))         /* Status of the command queue                   */
#define CMW_CMD_ID0_STA          ((APBADDR)(IRDBG_base+0x0018))         /* Status of the command ID0                     */
#define CMPU_CON0_R0             ((APBADDR)(IRDBG_base+0x001C))         /* Constraint  of EMI region 0                   */
#define CMPU_CON1_R0             ((APBADDR)(IRDBG_base+0x0020))         /* Setting of MPU for region 0                   */
#define CMPU_CON0_R1             ((APBADDR)(IRDBG_base+0x0024))         /* Constraint  of EMI region 1                   */
#define CMPU_CON1_R1             ((APBADDR)(IRDBG_base+0x0028))         /* Setting of MPU for region 1                   */
#define CMPU_CON0_R2             ((APBADDR)(IRDBG_base+0x002C))         /* Constraint  of EMI region 2                   */
#define CMPU_CON1_R2             ((APBADDR)(IRDBG_base+0x0030))         /* Setting of MPU for region 2                   */
#define CMPU_CON0_R3             ((APBADDR)(IRDBG_base+0x0034))         /* Constraint  of EMI region 3                   */
#define CMPU_CON1_R3             ((APBADDR)(IRDBG_base+0x0038))         /* Setting of MPU for region 3                   */
#define CMPU_EML                 ((APBADDR)(IRDBG_base+0x003C))         /* Feedback information when incorrect access    */
#define CMPU_EMU                 ((APBADDR)(IRDBG_base+0x0040))         /* Feedback information when incorrect access    */
#define CMPU_INT                 ((APBADDR)(IRDBG_base+0x0044))         /* IRDBG indication of incorrect memory access   */
#define CMW_IR_CMD               ((APBADDR)(IRDBG_base+0x0048))         /* CMW IR movement command                       */

   #else
#define IRDBG_STA                ((APBADDR)(IRDBG1_base+0x0000))        /* IRDBG status for MCU                          */
#define CMW_EM_ADDRU             ((APBADDR)(IRDBG1_base+0x0004))        /* Start point of CMW of EMI, upper half address */
#define CMW_EM_ADDRL             ((APBADDR)(IRDBG1_base+0x0008))        /* Start point of CMW of EMI, lower half address */
#define CMW_CM_ADDR              ((APBADDR)(IRDBG1_base+0x000C))        /* Destination in CMW of CM                      */
#define CMW_CM_PAGE              ((APBADDR)(IRDBG1_base+0x0010))        /* Page number of CM access                      */
#define CMW_QUE_STA              ((APBADDR)(IRDBG1_base+0x0014))        /* Status of the command queue                   */
#define CMW_CMD_ID0_STA          ((APBADDR)(IRDBG1_base+0x0018))        /* Status of the command ID0                     */
#define CMPU_CON0_R0             ((APBADDR)(IRDBG1_base+0x001C))        /* Constraint  of EMI region 0                   */
#define CMPU_CON1_R0             ((APBADDR)(IRDBG1_base+0x0020))        /* Setting of MPU for region 0                   */
#define CMPU_CON0_R1             ((APBADDR)(IRDBG1_base+0x0024))        /* Constraint  of EMI region 1                   */
#define CMPU_CON1_R1             ((APBADDR)(IRDBG1_base+0x0028))        /* Setting of MPU for region 1                   */
#define CMPU_CON0_R2             ((APBADDR)(IRDBG1_base+0x002C))        /* Constraint  of EMI region 2                   */
#define CMPU_CON1_R2             ((APBADDR)(IRDBG1_base+0x0030))        /* Setting of MPU for region 2                   */
#define CMPU_CON0_R3             ((APBADDR)(IRDBG1_base+0x0034))        /* Constraint  of EMI region 3                   */
#define CMPU_CON1_R3             ((APBADDR)(IRDBG1_base+0x0038))        /* Setting of MPU for region 3                   */
#define CMPU_EML                 ((APBADDR)(IRDBG1_base+0x003C))        /* Feedback information when incorrect access    */
#define CMPU_EMU                 ((APBADDR)(IRDBG1_base+0x0040))        /* Feedback information when incorrect access    */
#define CMPU_INT                 ((APBADDR)(IRDBG1_base+0x0044))        /* IRDBG indication of incorrect memory access   */
#define CMW_IR_CMD               ((APBADDR)(IRDBG1_base+0x0048))        /* CMW IR movement command                       */

#define IRDBG2_STA               ((APBADDR)(IRDBG2_base+0x0000))        /* IRDBG status for MCU                          */
#define CMW2_EM_ADDRU            ((APBADDR)(IRDBG2_base+0x0004))        /* Start point of CMW of EMI, upper half address */
#define CMW2_EM_ADDRL            ((APBADDR)(IRDBG2_base+0x0008))        /* Start point of CMW of EMI, lower half address */
#define CMW2_CM_ADDR             ((APBADDR)(IRDBG2_base+0x000C))        /* Destination in CMW of CM                      */
#define CMW2_CM_PAGE             ((APBADDR)(IRDBG2_base+0x0010))        /* Page number of CM access                      */
#define CMW2_QUE_STA             ((APBADDR)(IRDBG2_base+0x0014))        /* Status of the command queue                   */
#define CMW2_CMD_ID0_STA         ((APBADDR)(IRDBG2_base+0x0018))        /* Status of the command ID0                     */
#define CMPU2_CON0_R0            ((APBADDR)(IRDBG2_base+0x001C))        /* Constraint  of EMI region 0                   */
#define CMPU2_CON1_R0            ((APBADDR)(IRDBG2_base+0x0020))        /* Setting of MPU for region 0                   */
#define CMPU2_CON0_R1            ((APBADDR)(IRDBG2_base+0x0024))        /* Constraint  of EMI region 1                   */
#define CMPU2_CON1_R1            ((APBADDR)(IRDBG2_base+0x0028))        /* Setting of MPU for region 1                   */
#define CMPU2_CON0_R2            ((APBADDR)(IRDBG2_base+0x002C))        /* Constraint  of EMI region 2                   */
#define CMPU2_CON1_R2            ((APBADDR)(IRDBG2_base+0x0030))        /* Setting of MPU for region 2                   */
#define CMPU2_CON0_R3            ((APBADDR)(IRDBG2_base+0x0034))        /* Constraint  of EMI region 3                   */
#define CMPU2_CON1_R3            ((APBADDR)(IRDBG2_base+0x0038))        /* Setting of MPU for region 3                   */
#define CMPU2_EML                ((APBADDR)(IRDBG2_base+0x003C))        /* Feedback information when incorrect access    */
#define CMPU2_EMU                ((APBADDR)(IRDBG2_base+0x0040))        /* Feedback information when incorrect access    */
#define CMPU2_INT                ((APBADDR)(IRDBG2_base+0x0044))        /* IRDBG indication of incorrect memory access   */
#define CMW2_IR_CMD              ((APBADDR)(IRDBG2_base+0x0048))        /* CMW IR movement command                       */
/* --------------------------------------------------------------------------------------------------------------------- */
   #endif
#endif

/*================================*\
|* DSP interrupt glitch Registers *|
\*================================*/
#if IS_CHIP_MT6252
#define SHREG_D22MTID            ((APBADDR)(SHARE2_base+0x0014))        /* 52 E3 and later chips only   */
#define DSP_PIO_REG              SHREG_D22MTID
#define DSP_PIO_ENABLE           0x8000
#endif

#if IS_CHIP_MT6251
#define MD2GSYS_AHB_CON0         ((APBADDR)(MD2GCONFG_base+0x0214))     /* 51 E2 and later chips only   */
#define DSP_PIO_REG              MD2GSYS_AHB_CON0
#define DSP_PIO_ENABLE           0x0001
#endif

#if IS_CHIP_MT6250 || IS_CHIP_MT6280 || IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2 || IS_CHIP_MT6572 || IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1 || IS_CHIP_MT6752_MD2
#define MD2GSYS_AHB_CON0         ((APBADDR)(MD2GCONFG_base+0x0214))
#endif

#if IS_CACHE_DSP_SUPPORT
#define DSPC_CM_STA              ((APBADDR)(DSP_CACHE_base+0x0004))     /* CM Cache Status */
#define DSPC_PM_STA              ((APBADDR)(DSP_CACHE_base+0x0104))     /* PM Cache Status */
#define DSPC_DM_STA              ((APBADDR)(DSP_CACHE_base+0x0204))     /* DM Cache Status */
#endif
/* --------------------------------------------------------------------------------------------------------------------- */

/*=======================*\
|* HIF Based Registers *|
\*=======================*/
#if IS_CHIP_MT6583_MD2
#define SPI_STA               ((APBADDR)(0x2C))
#endif

/*=======================*\
|* EFUSE Based Registers *|
\*=======================*/
#if IS_CHIP_MT6280
#define RCAL_EFUSE               ((APBADDR)(EFUSE_base+0x0108))
#endif

#if IS_CHIP_MT6583_MD1 || IS_CHIP_MT6583_MD2
#define M_HW_RES2                ((APBADDR32)(EFUSE_base+0x0108))
#define M_HW_RES3                ((APBADDR32)(EFUSE_base+0x0170))
#endif

#if IS_CHIP_MT6572
#define TDD_FEATURE_OFF          ((APBADDR)(0xA0009170))                /* EFUSE_base 0xA0009000 */
#define Efuse_R8_DL              ((APBADDR32)(0xA0009000+0x0100))       /* efuse_R8_DL           */
#define Efuse_R8_UL              ((APBADDR32)(0xA0009000+0x0178))       /* efuse_R8_UL           */
#define Efuse_APC                ((APBADDR32)(0xA0009000+0x0180))       /* efuse_APC             */
#endif

#endif /* _L1D_REG_H_ */

