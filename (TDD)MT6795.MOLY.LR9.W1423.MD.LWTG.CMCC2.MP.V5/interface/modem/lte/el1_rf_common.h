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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *	el1_rf_common.h
 *
 * Project:
 * --------
 * MT6290
 *
 * Description:
 * ------------
 * LTE RF Common define
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _EL1_RF_COMMON_H_
#define  _EL1_RF_COMMON_H_

#include "lte_custom_rf.h"
#include "lte_custom_mipi.h"
#include "lte_custom_drdi.h"

/*******************************************************************************/
/*                              Common RF Setting                              */
/*******************************************************************************/
/* This part serves as default value of undefined macro constants in lte_custom_rf.h */
/* Aim to accommodate to those difference between RF chips */

#define PDATA_LTE_BandNone_PR1           0
#define PDATA_LTE_BandNone_PR2           0
#define PDATA_LTE_BandNone_PR3           0
#define PDATA_LTE_BandNone_PT1           0
#define PDATA_LTE_BandNone_PT2           0
#define PDATA_LTE_BandNone_PT3           0
#define PDATA_LTE_BandNone_2_PR1         0
#define PDATA_LTE_BandNone_2_PR2         0
#define PDATA_LTE_BandNone_2_PR3         0
#define PDATA_LTE_BandNone_2_PT1         0
#define PDATA_LTE_BandNone_2_PT2         0
#define PDATA_LTE_BandNone_2_PT3         0
#define PDATA_LTE_BandNone_3_PR1         0
#define PDATA_LTE_BandNone_3_PR2         0
#define PDATA_LTE_BandNone_3_PR3         0
#define PDATA_LTE_BandNone_3_PT1         0
#define PDATA_LTE_BandNone_3_PT2         0
#define PDATA_LTE_BandNone_3_PT3         0
#define PDATA_LTE_BandNone_BYPASS_PR1    0
#define PDATA_LTE_BandNone_BYPASS_PR2    0
#define PDATA_LTE_BandNone_BYPASS_PR3    0
#define PDATA_LTE_BandNone_BYPASS_PT1    0
#define PDATA_LTE_BandNone_BYPASS_PT2    0
#define PDATA_LTE_BandNone_BYPASS_PT3    0
#define PDATA_LTE_BandNone_TAS1          0
#define PDATA_LTE_BandNone_TAS2          0
#define PDATA_LTE_BandNone_TAS3          0
#define PDATA_LTE_BandNone_TAS4          0
#define PDATA_LTE_BandNone_TAS5          0
#define PDATA_LTE_BandNone_TAS6          0
#define PDATA_LTE_BandNone_TAS7          0

#define LTE_BandNone_RX_IO_SEL           RX_IO_NON_USED
#define LTE_BandNone_RXD_IO_SEL          RXD_IO_NON_USED
#define LTE_BandNone_TX_IO_SEL           TX_IO_NON_USED
#define LTE_BandNone_2_RX_IO_SEL         RX_IO_NON_USED
#define LTE_BandNone_2_RXD_IO_SEL        RXD_IO_NON_USED
#define LTE_BandNone_2_TX_IO_SEL         TX_IO_NON_USED
#define LTE_BandNone_3_RX_IO_SEL         RX_IO_NON_USED
#define LTE_BandNone_3_RXD_IO_SEL        RXD_IO_NON_USED
#define LTE_BandNone_3_TX_IO_SEL         TX_IO_NON_USED
#define LTE_BandNone_BYPASS_RX_IO_SEL    RX_IO_NON_USED
#define LTE_BandNone_BYPASS_RXD_IO_SEL   RXD_IO_NON_USED
#define LTE_BandNone_BYPASS_TX_IO_SEL    TX_IO_NON_USED

//RF conflict check
#define LTE_RF_CFLT_PIN                 (28)
#define PDATA_LTE_RF_CONFLICT           (1<<LTE_RF_CFLT_PIN)

//PR0 & PT0 is used for RF conflict check
#define PDATA_LTE_BANDX_PR0              0x00000000
#define PDATA_LTE_BANDX_PT0              0x00000000

//PR3B is used for special scenario of TDD special subframe
#define PDATA_LTE_BANDX_PR3B             0x00000000

//PR3C is used for set RF conflict off
#define PDATA_LTE_BANDX_PR3C             0x00000000

//MPR default value
#define LTE_BandNone_MPR_QPSK1           0
#define LTE_BandNone_MPR_16QAM0          0
#define LTE_BandNone_MPR_16QAM1          0
#define LTE_BandNone_DELTA_TC0           0
#define LTE_BandNone_DELTA_TC1           0

/*******************************************************************************/

#define IO_NON_USED(tp,sb)          tp##_IO_##sb##1

/* Define BANDx_RX_IO_SEL */
#ifndef BAND1_RX_IO_SEL
   #define BAND1_RX_IO_SEL          IO_NON_USED(RX,MB)
#endif
#ifndef BAND2_RX_IO_SEL
   #define BAND2_RX_IO_SEL          IO_NON_USED(RX,MB)
#endif
#ifndef BAND3_RX_IO_SEL
   #define BAND3_RX_IO_SEL          IO_NON_USED(RX,MB)
#endif
#ifndef BAND4_RX_IO_SEL
   #define BAND4_RX_IO_SEL          IO_NON_USED(RX,MB)
#endif
#ifndef BAND5_RX_IO_SEL
   #define BAND5_RX_IO_SEL          IO_NON_USED(RX,LB)
#endif
#ifndef BAND6_RX_IO_SEL
   #define BAND6_RX_IO_SEL          IO_NON_USED(RX,LB)
#endif
#ifndef BAND7_RX_IO_SEL
   #define BAND7_RX_IO_SEL          IO_NON_USED(RX,HB)
#endif
#ifndef BAND8_RX_IO_SEL
   #define BAND8_RX_IO_SEL          IO_NON_USED(RX,LB)
#endif
#ifndef BAND9_RX_IO_SEL
   #define BAND9_RX_IO_SEL          IO_NON_USED(RX,MB)
#endif
#ifndef BAND11_RX_IO_SEL
   #define BAND11_RX_IO_SEL         IO_NON_USED(RX,MB)
#endif
#ifndef BAND12_RX_IO_SEL
   #define BAND12_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND13_RX_IO_SEL
   #define BAND13_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND14_RX_IO_SEL
   #define BAND14_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND17_RX_IO_SEL
   #define BAND17_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND18_RX_IO_SEL
   #define BAND18_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND19_RX_IO_SEL
   #define BAND19_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND20_RX_IO_SEL
   #define BAND20_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND21_RX_IO_SEL
   #define BAND21_RX_IO_SEL         IO_NON_USED(RX,MB)
#endif
#ifndef BAND26_RX_IO_SEL
   #define BAND26_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND28_RX_IO_SEL
   #define BAND28_RX_IO_SEL         IO_NON_USED(RX,LB)
#endif
#ifndef BAND34_RX_IO_SEL
   #define BAND34_RX_IO_SEL         IO_NON_USED(RX,MB)
#endif
#ifndef BAND38_RX_IO_SEL
   #define BAND38_RX_IO_SEL         IO_NON_USED(RX,HB)
#endif
#ifndef BAND39_RX_IO_SEL
   #define BAND39_RX_IO_SEL         IO_NON_USED(RX,MB)
#endif
#ifndef BAND40_RX_IO_SEL
   #define BAND40_RX_IO_SEL         IO_NON_USED(RX,HB)
#endif
#ifndef BAND41_RX_IO_SEL
   #define BAND41_RX_IO_SEL         IO_NON_USED(RX,HB)
#endif

/* Define BANDx_RXD_IO_SEL */
#ifndef BAND1_RXD_IO_SEL
   #define BAND1_RXD_IO_SEL         IO_NON_USED(RXD,MB)
#endif
#ifndef BAND2_RXD_IO_SEL
   #define BAND2_RXD_IO_SEL         IO_NON_USED(RXD,MB)
#endif
#ifndef BAND3_RXD_IO_SEL
   #define BAND3_RXD_IO_SEL         IO_NON_USED(RXD,MB)
#endif
#ifndef BAND4_RXD_IO_SEL
   #define BAND4_RXD_IO_SEL         IO_NON_USED(RXD,MB)
#endif
#ifndef BAND5_RXD_IO_SEL
   #define BAND5_RXD_IO_SEL         IO_NON_USED(RXD,LB)
#endif
#ifndef BAND6_RXD_IO_SEL
   #define BAND6_RXD_IO_SEL         IO_NON_USED(RXD,LB)
#endif
#ifndef BAND7_RXD_IO_SEL
   #define BAND7_RXD_IO_SEL         IO_NON_USED(RXD,HB)
#endif
#ifndef BAND8_RXD_IO_SEL
   #define BAND8_RXD_IO_SEL         IO_NON_USED(RXD,LB)
#endif
#ifndef BAND9_RXD_IO_SEL
   #define BAND9_RXD_IO_SEL         IO_NON_USED(RXD,MB)
#endif
#ifndef BAND11_RXD_IO_SEL
   #define BAND11_RXD_IO_SEL        IO_NON_USED(RXD,MB)
#endif
#ifndef BAND12_RXD_IO_SEL
   #define BAND12_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND13_RXD_IO_SEL
   #define BAND13_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND14_RXD_IO_SEL
   #define BAND14_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND17_RXD_IO_SEL
   #define BAND17_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND18_RXD_IO_SEL
   #define BAND18_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND19_RXD_IO_SEL
   #define BAND19_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND20_RXD_IO_SEL
   #define BAND20_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND21_RXD_IO_SEL
   #define BAND21_RXD_IO_SEL        IO_NON_USED(RXD,MB)
#endif
#ifndef BAND26_RXD_IO_SEL
   #define BAND26_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND28_RXD_IO_SEL
   #define BAND28_RXD_IO_SEL        IO_NON_USED(RXD,LB)
#endif
#ifndef BAND34_RXD_IO_SEL
   #define BAND34_RXD_IO_SEL        IO_NON_USED(RXD,MB)
#endif
#ifndef BAND38_RXD_IO_SEL
   #define BAND38_RXD_IO_SEL        IO_NON_USED(RXD,HB)
#endif
#ifndef BAND39_RXD_IO_SEL
   #define BAND39_RXD_IO_SEL        IO_NON_USED(RXD,MB)
#endif
#ifndef BAND40_RXD_IO_SEL
   #define BAND40_RXD_IO_SEL        IO_NON_USED(RXD,HB)
#endif
#ifndef BAND41_RXD_IO_SEL
   #define BAND41_RXD_IO_SEL        IO_NON_USED(RXD,HB)
#endif

/* Define BANDx_TX_IO_SEL */
#ifndef BAND1_TX_IO_SEL
   #define BAND1_TX_IO_SEL          IO_NON_USED(TX,MB)
#endif
#ifndef BAND2_TX_IO_SEL
   #define BAND2_TX_IO_SEL          IO_NON_USED(TX,MB)
#endif
#ifndef BAND3_TX_IO_SEL
   #define BAND3_TX_IO_SEL          IO_NON_USED(TX,MB)
#endif
#ifndef BAND4_TX_IO_SEL
   #define BAND4_TX_IO_SEL          IO_NON_USED(TX,MB)
#endif
#ifndef BAND5_TX_IO_SEL
   #define BAND5_TX_IO_SEL          IO_NON_USED(TX,LB)
#endif
#ifndef BAND6_TX_IO_SEL
   #define BAND6_TX_IO_SEL          IO_NON_USED(TX,LB)
#endif
#ifndef BAND7_TX_IO_SEL
   #define BAND7_TX_IO_SEL          IO_NON_USED(TX,HB)
#endif
#ifndef BAND8_TX_IO_SEL
   #define BAND8_TX_IO_SEL          IO_NON_USED(TX,LB)
#endif
#ifndef BAND9_TX_IO_SEL
   #define BAND9_TX_IO_SEL          IO_NON_USED(TX,MB)
#endif
#ifndef BAND11_TX_IO_SEL
   #define BAND11_TX_IO_SEL         IO_NON_USED(TX,MB)
#endif
#ifndef BAND12_TX_IO_SEL
   #define BAND12_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND13_TX_IO_SEL
   #define BAND13_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND14_TX_IO_SEL
   #define BAND14_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND17_TX_IO_SEL
   #define BAND17_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND18_TX_IO_SEL
   #define BAND18_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND19_TX_IO_SEL
   #define BAND19_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND20_TX_IO_SEL
   #define BAND20_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND21_TX_IO_SEL
   #define BAND21_TX_IO_SEL         IO_NON_USED(TX,MB)
#endif
#ifndef BAND26_TX_IO_SEL
   #define BAND26_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND28_TX_IO_SEL
   #define BAND28_TX_IO_SEL         IO_NON_USED(TX,LB)
#endif
#ifndef BAND34_TX_IO_SEL
   #define BAND34_TX_IO_SEL         IO_NON_USED(TX,MB)
#endif
#ifndef BAND38_TX_IO_SEL
   #define BAND38_TX_IO_SEL         IO_NON_USED(TX,HB)
#endif
#ifndef BAND39_TX_IO_SEL
   #define BAND39_TX_IO_SEL         IO_NON_USED(TX,MB)
#endif
#ifndef BAND40_TX_IO_SEL
   #define BAND40_TX_IO_SEL         IO_NON_USED(TX,HB)
#endif
#ifndef BAND41_TX_IO_SEL
   #define BAND41_TX_IO_SEL         IO_NON_USED(TX,HB)
#endif

/* Define LTE_Bandx_RX_IO_SEL */
#ifndef LTE_Band1_RX_IO_SEL
   #define LTE_Band1_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band2_RX_IO_SEL
   #define LTE_Band2_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band3_RX_IO_SEL
   #define LTE_Band3_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band4_RX_IO_SEL
   #define LTE_Band4_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band5_RX_IO_SEL
   #define LTE_Band5_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band6_RX_IO_SEL
   #define LTE_Band6_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band7_RX_IO_SEL
   #define LTE_Band7_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band8_RX_IO_SEL
   #define LTE_Band8_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band9_RX_IO_SEL
   #define LTE_Band9_RX_IO_SEL      LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band11_RX_IO_SEL
   #define LTE_Band11_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band12_RX_IO_SEL
   #define LTE_Band12_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band13_RX_IO_SEL
   #define LTE_Band13_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band14_RX_IO_SEL
   #define LTE_Band14_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band17_RX_IO_SEL
   #define LTE_Band17_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band18_RX_IO_SEL
   #define LTE_Band18_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band19_RX_IO_SEL
   #define LTE_Band19_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band20_RX_IO_SEL
   #define LTE_Band20_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band21_RX_IO_SEL
   #define LTE_Band21_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band26_RX_IO_SEL
   #define LTE_Band26_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band28_RX_IO_SEL
   #define LTE_Band28_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band34_RX_IO_SEL
   #define LTE_Band34_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band38_RX_IO_SEL
   #define LTE_Band38_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band39_RX_IO_SEL
   #define LTE_Band39_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band40_RX_IO_SEL
   #define LTE_Band40_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif
#ifndef LTE_Band41_RX_IO_SEL
   #define LTE_Band41_RX_IO_SEL     LTE_BandNone_RX_IO_SEL
#endif

/* Define LTE_Bandx_RXD_IO_SEL */
#ifndef LTE_Band1_RXD_IO_SEL
   #define LTE_Band1_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band2_RXD_IO_SEL
   #define LTE_Band2_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band3_RXD_IO_SEL
   #define LTE_Band3_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band4_RXD_IO_SEL
   #define LTE_Band4_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band5_RXD_IO_SEL
   #define LTE_Band5_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band6_RXD_IO_SEL
   #define LTE_Band6_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band7_RXD_IO_SEL
   #define LTE_Band7_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band8_RXD_IO_SEL
   #define LTE_Band8_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band9_RXD_IO_SEL
   #define LTE_Band9_RXD_IO_SEL     LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band11_RXD_IO_SEL
   #define LTE_Band11_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band12_RXD_IO_SEL
   #define LTE_Band12_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band13_RXD_IO_SEL
   #define LTE_Band13_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band14_RXD_IO_SEL
   #define LTE_Band14_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band17_RXD_IO_SEL
   #define LTE_Band17_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band18_RXD_IO_SEL
   #define LTE_Band18_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band19_RXD_IO_SEL
   #define LTE_Band19_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band20_RXD_IO_SEL
   #define LTE_Band20_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band21_RXD_IO_SEL
   #define LTE_Band21_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band26_RXD_IO_SEL
   #define LTE_Band26_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band28_RXD_IO_SEL
   #define LTE_Band28_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band34_RXD_IO_SEL
   #define LTE_Band34_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band38_RXD_IO_SEL
   #define LTE_Band38_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band39_RXD_IO_SEL
   #define LTE_Band39_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band40_RXD_IO_SEL
   #define LTE_Band40_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif
#ifndef LTE_Band41_RXD_IO_SEL
   #define LTE_Band41_RXD_IO_SEL    LTE_BandNone_RXD_IO_SEL
#endif

/* Define LTE_Bandx_TX_IO_SEL */
#ifndef LTE_Band1_TX_IO_SEL
   #define LTE_Band1_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band2_TX_IO_SEL
   #define LTE_Band2_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band3_TX_IO_SEL
   #define LTE_Band3_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band4_TX_IO_SEL
   #define LTE_Band4_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band5_TX_IO_SEL
   #define LTE_Band5_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band6_TX_IO_SEL
   #define LTE_Band6_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band7_TX_IO_SEL
   #define LTE_Band7_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band8_TX_IO_SEL
   #define LTE_Band8_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band9_TX_IO_SEL
   #define LTE_Band9_TX_IO_SEL      LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band11_TX_IO_SEL
   #define LTE_Band11_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band12_TX_IO_SEL
   #define LTE_Band12_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band13_TX_IO_SEL
   #define LTE_Band13_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band14_TX_IO_SEL
   #define LTE_Band14_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band17_TX_IO_SEL
   #define LTE_Band17_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band18_TX_IO_SEL
   #define LTE_Band18_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band19_TX_IO_SEL
   #define LTE_Band19_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band20_TX_IO_SEL
   #define LTE_Band20_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band21_TX_IO_SEL
   #define LTE_Band21_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band26_TX_IO_SEL
   #define LTE_Band26_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band28_TX_IO_SEL
   #define LTE_Band28_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band34_TX_IO_SEL
   #define LTE_Band34_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band38_TX_IO_SEL
   #define LTE_Band38_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band39_TX_IO_SEL
   #define LTE_Band39_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band40_TX_IO_SEL
   #define LTE_Band40_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif
#ifndef LTE_Band41_TX_IO_SEL
   #define LTE_Band41_TX_IO_SEL     LTE_BandNone_TX_IO_SEL
#endif

/* Define LTE_Bandx_MPR_QPSK1 */
#ifndef LTE_Band1_MPR_QPSK1
   #define LTE_Band1_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band2_MPR_QPSK1
   #define LTE_Band2_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band3_MPR_QPSK1
   #define LTE_Band3_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band4_MPR_QPSK1
   #define LTE_Band4_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band5_MPR_QPSK1
   #define LTE_Band5_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band6_MPR_QPSK1
   #define LTE_Band6_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band7_MPR_QPSK1
   #define LTE_Band7_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band8_MPR_QPSK1
   #define LTE_Band8_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band9_MPR_QPSK1
   #define LTE_Band9_MPR_QPSK1      LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band11_MPR_QPSK1
   #define LTE_Band11_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band12_MPR_QPSK1
   #define LTE_Band12_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band13_MPR_QPSK1
   #define LTE_Band13_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band14_MPR_QPSK1
   #define LTE_Band14_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band17_MPR_QPSK1
   #define LTE_Band17_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band18_MPR_QPSK1
   #define LTE_Band18_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band19_MPR_QPSK1
   #define LTE_Band19_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band20_MPR_QPSK1
   #define LTE_Band20_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band21_MPR_QPSK1
   #define LTE_Band21_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band26_MPR_QPSK1
   #define LTE_Band26_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band28_MPR_QPSK1
   #define LTE_Band28_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band34_MPR_QPSK1
   #define LTE_Band34_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band38_MPR_QPSK1
   #define LTE_Band38_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band39_MPR_QPSK1
   #define LTE_Band39_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band40_MPR_QPSK1
   #define LTE_Band40_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif
#ifndef LTE_Band41_MPR_QPSK1
   #define LTE_Band41_MPR_QPSK1     LTE_BandNone_MPR_QPSK1
#endif

/* Define LTE_Bandx_MPR_16QAM0 */
#ifndef LTE_Band1_MPR_16QAM0
   #define LTE_Band1_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band2_MPR_16QAM0
   #define LTE_Band2_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band3_MPR_16QAM0
   #define LTE_Band3_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band4_MPR_16QAM0
   #define LTE_Band4_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band5_MPR_16QAM0
   #define LTE_Band5_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band6_MPR_16QAM0
   #define LTE_Band6_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band7_MPR_16QAM0
   #define LTE_Band7_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band8_MPR_16QAM0
   #define LTE_Band8_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band9_MPR_16QAM0
   #define LTE_Band9_MPR_16QAM0     LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band11_MPR_16QAM0
   #define LTE_Band11_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band12_MPR_16QAM0
   #define LTE_Band12_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band13_MPR_16QAM0
   #define LTE_Band13_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band14_MPR_16QAM0
   #define LTE_Band14_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band17_MPR_16QAM0
   #define LTE_Band17_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band18_MPR_16QAM0
   #define LTE_Band18_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band19_MPR_16QAM0
   #define LTE_Band19_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band20_MPR_16QAM0
   #define LTE_Band20_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band21_MPR_16QAM0
   #define LTE_Band21_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band26_MPR_16QAM0
   #define LTE_Band26_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band28_MPR_16QAM0
   #define LTE_Band28_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band34_MPR_16QAM0
   #define LTE_Band34_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band38_MPR_16QAM0
   #define LTE_Band38_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band39_MPR_16QAM0
   #define LTE_Band39_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band40_MPR_16QAM0
   #define LTE_Band40_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif
#ifndef LTE_Band41_MPR_16QAM0
   #define LTE_Band41_MPR_16QAM0    LTE_BandNone_MPR_16QAM0
#endif

/* Define LTE_Bandx_MPR_16QAM1 */
#ifndef LTE_Band1_MPR_16QAM1
   #define LTE_Band1_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band2_MPR_16QAM1
   #define LTE_Band2_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band3_MPR_16QAM1
   #define LTE_Band3_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band4_MPR_16QAM1
   #define LTE_Band4_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band5_MPR_16QAM1
   #define LTE_Band5_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band6_MPR_16QAM1
   #define LTE_Band6_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band7_MPR_16QAM1
   #define LTE_Band7_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band8_MPR_16QAM1
   #define LTE_Band8_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band9_MPR_16QAM1
   #define LTE_Band9_MPR_16QAM1     LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band11_MPR_16QAM1
   #define LTE_Band11_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band12_MPR_16QAM1
   #define LTE_Band12_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band13_MPR_16QAM1
   #define LTE_Band13_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band14_MPR_16QAM1
   #define LTE_Band14_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band17_MPR_16QAM1
   #define LTE_Band17_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band18_MPR_16QAM1
   #define LTE_Band18_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band19_MPR_16QAM1
   #define LTE_Band19_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band20_MPR_16QAM1
   #define LTE_Band20_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band21_MPR_16QAM1
   #define LTE_Band21_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band26_MPR_16QAM1
   #define LTE_Band26_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band28_MPR_16QAM1
   #define LTE_Band28_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band34_MPR_16QAM1
   #define LTE_Band34_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band38_MPR_16QAM1
   #define LTE_Band38_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band39_MPR_16QAM1
   #define LTE_Band39_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band40_MPR_16QAM1
   #define LTE_Band40_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif
#ifndef LTE_Band41_MPR_16QAM1
   #define LTE_Band41_MPR_16QAM1    LTE_BandNone_MPR_16QAM1
#endif

/* Define LTE_Bandx_DELTA_TC0 */
#ifndef LTE_Band1_DELTA_TC0
   #define LTE_Band1_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band2_DELTA_TC0
   #define LTE_Band2_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band3_DELTA_TC0
   #define LTE_Band3_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band4_DELTA_TC0
   #define LTE_Band4_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band5_DELTA_TC0
   #define LTE_Band5_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band6_DELTA_TC0
   #define LTE_Band6_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band7_DELTA_TC0
   #define LTE_Band7_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band8_DELTA_TC0
   #define LTE_Band8_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band9_DELTA_TC0
   #define LTE_Band9_DELTA_TC0      LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band11_DELTA_TC0
   #define LTE_Band11_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band12_DELTA_TC0
   #define LTE_Band12_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band13_DELTA_TC0
   #define LTE_Band13_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band14_DELTA_TC0
   #define LTE_Band14_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band17_DELTA_TC0
   #define LTE_Band17_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band18_DELTA_TC0
   #define LTE_Band18_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band19_DELTA_TC0
   #define LTE_Band19_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band20_DELTA_TC0
   #define LTE_Band20_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band21_DELTA_TC0
   #define LTE_Band21_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band26_DELTA_TC0
   #define LTE_Band26_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band28_DELTA_TC0
   #define LTE_Band28_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band34_DELTA_TC0
   #define LTE_Band34_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band38_DELTA_TC0
   #define LTE_Band38_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band39_DELTA_TC0
   #define LTE_Band39_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band40_DELTA_TC0
   #define LTE_Band40_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif
#ifndef LTE_Band41_DELTA_TC0
   #define LTE_Band41_DELTA_TC0     LTE_BandNone_DELTA_TC0
#endif

/* Define LTE_Bandx_DELTA_TC1 */
#ifndef LTE_Band1_DELTA_TC1
   #define LTE_Band1_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band2_DELTA_TC1
   #define LTE_Band2_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band3_DELTA_TC1
   #define LTE_Band3_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band4_DELTA_TC1
   #define LTE_Band4_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band5_DELTA_TC1
   #define LTE_Band5_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band6_DELTA_TC1
   #define LTE_Band6_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band7_DELTA_TC1
   #define LTE_Band7_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band8_DELTA_TC1
   #define LTE_Band8_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band9_DELTA_TC1
   #define LTE_Band9_DELTA_TC1      LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band11_DELTA_TC1
   #define LTE_Band11_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band12_DELTA_TC1
   #define LTE_Band12_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band13_DELTA_TC1
   #define LTE_Band13_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band14_DELTA_TC1
   #define LTE_Band14_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band17_DELTA_TC1
   #define LTE_Band17_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band18_DELTA_TC1
   #define LTE_Band18_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band19_DELTA_TC1
   #define LTE_Band19_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band20_DELTA_TC1
   #define LTE_Band20_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band21_DELTA_TC1
   #define LTE_Band21_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band26_DELTA_TC1
   #define LTE_Band26_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band28_DELTA_TC1
   #define LTE_Band28_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band34_DELTA_TC1
   #define LTE_Band34_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band38_DELTA_TC1
   #define LTE_Band38_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band39_DELTA_TC1
   #define LTE_Band39_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band40_DELTA_TC1
   #define LTE_Band40_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif
#ifndef LTE_Band41_DELTA_TC1
   #define LTE_Band41_DELTA_TC1     LTE_BandNone_DELTA_TC1
#endif

/* Define LTE_AMPR */
#define LTE_AMPR_NS1                1
#define LTE_AMPR_NS2                2
#define LTE_AMPR_NS3                3
#define LTE_AMPR_NS4                4
#define LTE_AMPR_NS5                5
#define LTE_AMPR_NS6                6
#define LTE_AMPR_NS7                7
#define LTE_AMPR_NS8                8
#define LTE_AMPR_NS9                9
#define LTE_AMPR_NS10               10
#define LTE_AMPR_NS11               11
#define LTE_AMPR_NS121314           12
#define LTE_AMPR_NS15               15
#define LTE_AMPR_NS16               16
#define LTE_AMPR_NS17               17
#define LTE_AMPR_NS18               18
#define LTE_AMPR_NS19               19
#define LTE_AMPR_NS20               20
#define LTE_AMPR_NS21               21

#define LTE_BandX_AMPR_NS1          // null row
#define LTE_BandX_AMPR_NS6          // null row
#define LTE_BandX_AMPR_NS17         // null row
#ifndef LTE_Band1_NS5
#define LTE_Band1_AMPR_NS5          LTE_BandX_AMPR_NS1
#else
#define LTE_Band1_AMPR_NS5          { LTE_Band1 ,  LTE_AMPR_NS5      , { LTE_Band1_NS5      }  },
#define LTE_Band1_AMPR_NS_DEF       1
#endif
#ifndef LTE_Band2_NS3
#define LTE_Band2_AMPR_NS3          LTE_BandX_AMPR_NS1
#else
#define LTE_Band2_AMPR_NS3          { LTE_Band2 ,  LTE_AMPR_NS3      , { LTE_Band2_NS3      }  },
#define LTE_Band2_AMPR_NS_DEF       1
#endif
#ifndef LTE_Band4_NS3
#define LTE_Band4_AMPR_NS3          LTE_BandX_AMPR_NS1
#else
#define LTE_Band4_AMPR_NS3          { LTE_Band4 ,  LTE_AMPR_NS3      , { LTE_Band4_NS3      }  },
#define LTE_Band4_AMPR_NS_DEF       1
#endif
#ifndef LTE_Band10_NS3
#define LTE_Band10_AMPR_NS3         LTE_BandX_AMPR_NS1
#else
#define LTE_Band10_AMPR_NS3         { LTE_Band10,  LTE_AMPR_NS3      , { LTE_Band10_NS3     }  },
#define LTE_Band10_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band13_NS7
#define LTE_Band13_AMPR_NS7         LTE_BandX_AMPR_NS1
#else
#define LTE_Band13_AMPR_NS7         { LTE_Band13,  LTE_AMPR_NS7      , { LTE_Band13_NS7     }  },
#define LTE_Band13_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band19_NS8
#define LTE_Band19_AMPR_NS8         LTE_BandX_AMPR_NS1
#else
#define LTE_Band19_AMPR_NS8         { LTE_Band19,  LTE_AMPR_NS8      , { LTE_Band19_NS8     }  },
#define LTE_Band19_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band20_NS10
#define LTE_Band20_AMPR_NS10        LTE_BandX_AMPR_NS1
#else
#define LTE_Band20_AMPR_NS10        { LTE_Band20,  LTE_AMPR_NS10     , { LTE_Band20_NS10    }  },
#define LTE_Band20_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band21_NS9
#define LTE_Band21_AMPR_NS9         LTE_BandX_AMPR_NS1
#else
#define LTE_Band21_AMPR_NS9         { LTE_Band21,  LTE_AMPR_NS9      , { LTE_Band21_NS9     }  },
#define LTE_Band21_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band23_NS3
#define LTE_Band23_AMPR_NS3         LTE_BandX_AMPR_NS1
#else
#define LTE_Band23_AMPR_NS3         { LTE_Band23,  LTE_AMPR_NS3      , { LTE_Band23_NS3     }  },
#define LTE_Band23_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band23_NS11
#define LTE_Band23_AMPR_NS11        LTE_BandX_AMPR_NS1
#else
#define LTE_Band23_AMPR_NS11        { LTE_Band23,  LTE_AMPR_NS11     , { LTE_Band23_NS11    }  },
#define LTE_Band23_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band23_NS20
#define LTE_Band23_AMPR_NS20        LTE_BandX_AMPR_NS1
#else
#define LTE_Band23_AMPR_NS20        { LTE_Band23,  LTE_AMPR_NS20     , { LTE_Band23_NS20    }  },
#define LTE_Band23_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band25_NS3
#define LTE_Band25_AMPR_NS3         LTE_BandX_AMPR_NS1
#else
#define LTE_Band25_AMPR_NS3         { LTE_Band25,  LTE_AMPR_NS3      , { LTE_Band25_NS3     }  },
#define LTE_Band25_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band26_NS121314
#define LTE_Band26_AMPR_NS121314    LTE_BandX_AMPR_NS1
#else
#define LTE_Band26_AMPR_NS121314    { LTE_Band26,  LTE_AMPR_NS121314 , { LTE_Band26_NS121314}  },
#define LTE_Band26_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band26_NS15
#define LTE_Band26_AMPR_NS15        LTE_BandX_AMPR_NS1
#else
#define LTE_Band26_AMPR_NS15        { LTE_Band26,  LTE_AMPR_NS15     , { LTE_Band26_NS15    }  },
#define LTE_Band26_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band27_NS16
#define LTE_Band27_AMPR_NS16        LTE_BandX_AMPR_NS1
#else
#define LTE_Band27_AMPR_NS16        { LTE_Band27,  LTE_AMPR_NS16     , { LTE_Band27_NS16    }  },
#define LTE_Band27_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band28_NS18
#define LTE_Band28_AMPR_NS18        LTE_BandX_AMPR_NS1
#else
#define LTE_Band28_AMPR_NS18        { LTE_Band28,  LTE_AMPR_NS18     , { LTE_Band28_NS18    }  },
#define LTE_Band28_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band30_NS21
#define LTE_Band30_AMPR_NS21        LTE_BandX_AMPR_NS1
#else
#define LTE_Band30_AMPR_NS21        { LTE_Band30,  LTE_AMPR_NS21     , { LTE_Band30_NS21    }  },
#define LTE_Band30_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band35_NS3
#define LTE_Band35_AMPR_NS3         LTE_BandX_AMPR_NS1
#else
#define LTE_Band35_AMPR_NS3         { LTE_Band35,  LTE_AMPR_NS3      , { LTE_Band35_NS3     }  },
#define LTE_Band35_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band36_NS3
#define LTE_Band36_AMPR_NS3         LTE_BandX_AMPR_NS1
#else
#define LTE_Band36_AMPR_NS3         { LTE_Band36,  LTE_AMPR_NS3      , { LTE_Band36_NS3     }  },
#define LTE_Band36_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band41_NS4
#define LTE_Band41_AMPR_NS4         LTE_BandX_AMPR_NS1
#else
#define LTE_Band41_AMPR_NS4         { LTE_Band41,  LTE_AMPR_NS4      , { LTE_Band41_NS4     }  },
#define LTE_Band41_AMPR_NS_DEF      1
#endif
#ifndef LTE_Band44_NS19
#define LTE_Band44_AMPR_NS19        LTE_BandX_AMPR_NS1
#else
#define LTE_Band44_AMPR_NS19        { LTE_Band44,  LTE_AMPR_NS19     , { LTE_Band44_NS19    }  },
#define LTE_Band44_AMPR_NS_DEF      1
#endif

//AMPR band -> NS configuration
#define LTE_BandNone_AMPR_NS        LTE_BandX_AMPR_NS1
#define LTE_Band1_AMPR_NS           LTE_Band1_AMPR_NS5
#define LTE_Band2_AMPR_NS           LTE_Band2_AMPR_NS3
#define LTE_Band3_AMPR_NS           LTE_BandX_AMPR_NS1
#define LTE_Band4_AMPR_NS           LTE_Band4_AMPR_NS3
#define LTE_Band5_AMPR_NS           LTE_BandX_AMPR_NS1
#define LTE_Band6_AMPR_NS           LTE_BandX_AMPR_NS1
#define LTE_Band7_AMPR_NS           LTE_BandX_AMPR_NS1
#define LTE_Band8_AMPR_NS           LTE_BandX_AMPR_NS1
#define LTE_Band9_AMPR_NS           LTE_BandX_AMPR_NS1
#define LTE_Band10_AMPR_NS          LTE_Band10_AMPR_NS3
#define LTE_Band11_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band12_AMPR_NS          LTE_BandX_AMPR_NS6
#define LTE_Band13_AMPR_NS          LTE_Band13_AMPR_NS7
#define LTE_Band14_AMPR_NS          LTE_BandX_AMPR_NS6
#define LTE_Band15_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band16_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band17_AMPR_NS          LTE_BandX_AMPR_NS6
#define LTE_Band18_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band19_AMPR_NS          LTE_Band19_AMPR_NS8
#define LTE_Band20_AMPR_NS          LTE_Band20_AMPR_NS10
#define LTE_Band21_AMPR_NS          LTE_Band21_AMPR_NS9
#define LTE_Band22_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band23_AMPR_NS          LTE_Band23_AMPR_NS3      \
                                    LTE_Band23_AMPR_NS11     \
                                    LTE_Band23_AMPR_NS20
#define LTE_Band24_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band25_AMPR_NS          LTE_Band25_AMPR_NS3
#define LTE_Band26_AMPR_NS          LTE_Band26_AMPR_NS121314 \
                                    LTE_Band26_AMPR_NS15
#define LTE_Band27_AMPR_NS          LTE_Band27_AMPR_NS16
#define LTE_Band28_AMPR_NS          LTE_Band28_AMPR_NS18
#define LTE_Band29_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band30_AMPR_NS          LTE_Band30_AMPR_NS21
#define LTE_Band31_AMPR_NS          LTE_BandX_AMPR_NS1

#define LTE_Band33_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band34_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band35_AMPR_NS          LTE_Band35_AMPR_NS3
#define LTE_Band36_AMPR_NS          LTE_Band36_AMPR_NS3
#define LTE_Band37_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band38_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band39_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band40_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band41_AMPR_NS          LTE_Band41_AMPR_NS4
#define LTE_Band42_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band43_AMPR_NS          LTE_BandX_AMPR_NS1
#define LTE_Band44_AMPR_NS          LTE_Band44_AMPR_NS19

//DRDI use, in the end of LTE_AMPRAdjustTbl_All
#define LTE_BandMax_AMPR_NS        { LTE_BandMax, 0, {{0}} },

/*Define EL1_CUSTOM_DYNAMIC_INIT_ENABLE for DRDI feature (default DISABLE)*/
#ifndef EL1_CUSTOM_DYNAMIC_INIT_ENABLE
   #define EL1_CUSTOM_DYNAMIC_INIT_ENABLE        0
#endif

#endif /* End of #ifndef _EL1_RF_COMMON_H_ */

