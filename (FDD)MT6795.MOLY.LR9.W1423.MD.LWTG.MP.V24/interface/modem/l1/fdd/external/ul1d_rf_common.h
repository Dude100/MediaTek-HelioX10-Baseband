/*******************************************************************************
*  Modification Notice :
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/


/*****************************************************************************
 *
 * Filename:
 * ---------
 * ul1d_rf_common.h
 *
 * Project:
 * --------
 *   3G Project Common File
 *
 * Description:
 * ------------
 *   Definition of some of customization setting not defined in ul1d_custom_rf.h
 *   And the stuff needs to be recognized by UL1D external module (wdata.c)
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef UL1D_RF_COMMON_H
#define UL1D_RF_COMMON_H

#include "ul1d_custom_rf.h"
#include "wcustomdata.h"

/*******************************************************************************
** Common setting for all RF
*******************************************************************************/
/* This part serves as default value of undefined macro constants in ul1d_custom_rf.h */
/* Aim to accommodate to those difference between RF chips */

#ifndef  PDATA_BAND1_PR1
   #define  PDATA_BAND1_PR1     0
   #define  PDATA_BAND1_PR2     0
   #define  PDATA_BAND1_PR3     0
   #define  PDATA_BAND1_PT1     0
   #define  PDATA_BAND1_PT2     0
   #define  PDATA_BAND1_PT3     0
#endif
#ifndef  PDATA_BAND2_PR1
   #define  PDATA_BAND2_PR1     0
   #define  PDATA_BAND2_PR2     0
   #define  PDATA_BAND2_PR3     0
   #define  PDATA_BAND2_PT1     0
   #define  PDATA_BAND2_PT2     0
   #define  PDATA_BAND2_PT3     0
#endif
#ifndef  PDATA_BAND3_PR1
   #define  PDATA_BAND3_PR1     0
   #define  PDATA_BAND3_PR2     0
   #define  PDATA_BAND3_PR3     0
   #define  PDATA_BAND3_PT1     0
   #define  PDATA_BAND3_PT2     0
   #define  PDATA_BAND3_PT3     0
#endif
#ifndef  PDATA_BAND4_PR1
   #define  PDATA_BAND4_PR1     0
   #define  PDATA_BAND4_PR2     0
   #define  PDATA_BAND4_PR3     0
   #define  PDATA_BAND4_PT1     0
   #define  PDATA_BAND4_PT2     0
   #define  PDATA_BAND4_PT3     0
#endif
#ifndef  PDATA_BAND5_PR1
   #define  PDATA_BAND5_PR1     0
   #define  PDATA_BAND5_PR2     0
   #define  PDATA_BAND5_PR3     0
   #define  PDATA_BAND5_PT1     0
   #define  PDATA_BAND5_PT2     0
   #define  PDATA_BAND5_PT3     0
#endif
#ifndef  PDATA_BAND6_PR1
   #define  PDATA_BAND6_PR1     0
   #define  PDATA_BAND6_PR2     0
   #define  PDATA_BAND6_PR3     0
   #define  PDATA_BAND6_PT1     0
   #define  PDATA_BAND6_PT2     0
   #define  PDATA_BAND6_PT3     0
#endif
#ifndef  PDATA_BAND7_PR1
   #define  PDATA_BAND7_PR1     0
   #define  PDATA_BAND7_PR2     0
   #define  PDATA_BAND7_PR3     0
   #define  PDATA_BAND7_PT1     0
   #define  PDATA_BAND7_PT2     0
   #define  PDATA_BAND7_PT3     0
#endif
#ifndef  PDATA_BAND8_PR1
   #define  PDATA_BAND8_PR1     0
   #define  PDATA_BAND8_PR2     0
   #define  PDATA_BAND8_PR3     0
   #define  PDATA_BAND8_PT1     0
   #define  PDATA_BAND8_PT2     0
   #define  PDATA_BAND8_PT3     0
#endif
#ifndef  PDATA_BAND9_PR1
   #define  PDATA_BAND9_PR1     0
   #define  PDATA_BAND9_PR2     0
   #define  PDATA_BAND9_PR3     0
   #define  PDATA_BAND9_PT1     0
   #define  PDATA_BAND9_PT2     0
   #define  PDATA_BAND9_PT3     0
#endif
#ifndef  PDATA_BAND10_PR1
   #define  PDATA_BAND10_PR1     0
   #define  PDATA_BAND10_PR2     0
   #define  PDATA_BAND10_PR3     0
   #define  PDATA_BAND10_PT1     0
   #define  PDATA_BAND10_PT2     0
   #define  PDATA_BAND10_PT3     0
#endif
#ifndef  PDATA_BAND11_PR1
   #define  PDATA_BAND11_PR1     0
   #define  PDATA_BAND11_PR2     0
   #define  PDATA_BAND11_PR3     0
   #define  PDATA_BAND11_PT1     0
   #define  PDATA_BAND11_PT2     0
   #define  PDATA_BAND11_PT3     0
#endif
#ifndef  PDATA_BAND19_PR1
   #define  PDATA_BAND19_PR1     0
   #define  PDATA_BAND19_PR2     0
   #define  PDATA_BAND19_PR3     0
   #define  PDATA_BAND19_PT1     0
   #define  PDATA_BAND19_PT2     0
   #define  PDATA_BAND19_PT3     0
#endif

#ifndef PDATA_BAND1_PR2B
   #define PDATA_BAND1_PR2B PDATA_BAND1_PR2
#endif
#ifndef PDATA_BAND1_PR3A
   #define PDATA_BAND1_PR3A PDATA_BAND1_PR3
#endif
#ifndef PDATA_BAND1_PT2B
   #define PDATA_BAND1_PT2B PDATA_BAND1_PT2
#endif
#ifndef PDATA_BAND1_PT3A
   #define PDATA_BAND1_PT3A PDATA_BAND1_PT3
#endif

#ifndef PDATA_BAND2_PR2B
   #define PDATA_BAND2_PR2B PDATA_BAND2_PR2
#endif
#ifndef PDATA_BAND2_PR3A
   #define PDATA_BAND2_PR3A PDATA_BAND2_PR3
#endif
#ifndef PDATA_BAND2_PT2B
   #define PDATA_BAND2_PT2B PDATA_BAND2_PT2
#endif
#ifndef PDATA_BAND2_PT3A
   #define PDATA_BAND2_PT3A PDATA_BAND2_PT3
#endif

#ifndef PDATA_BAND3_PR2B
   #define PDATA_BAND3_PR2B PDATA_BAND3_PR2
#endif
#ifndef PDATA_BAND3_PR3A
   #define PDATA_BAND3_PR3A PDATA_BAND3_PR3
#endif
#ifndef PDATA_BAND3_PT2B
   #define PDATA_BAND3_PT2B PDATA_BAND3_PT2
#endif
#ifndef PDATA_BAND3_PT3A
   #define PDATA_BAND3_PT3A PDATA_BAND3_PT3
#endif

#ifndef PDATA_BAND4_PR2B
   #define PDATA_BAND4_PR2B PDATA_BAND4_PR2
#endif
#ifndef PDATA_BAND4_PR3A
   #define PDATA_BAND4_PR3A PDATA_BAND4_PR3
#endif
#ifndef PDATA_BAND4_PT2B
   #define PDATA_BAND4_PT2B PDATA_BAND4_PT2
#endif
#ifndef PDATA_BAND4_PT3A
   #define PDATA_BAND4_PT3A PDATA_BAND4_PT3
#endif

#ifndef PDATA_BAND5_PR2B
   #define PDATA_BAND5_PR2B PDATA_BAND5_PR2
#endif
#ifndef PDATA_BAND5_PR3A
   #define PDATA_BAND5_PR3A PDATA_BAND5_PR3
#endif
#ifndef PDATA_BAND5_PT2B
   #define PDATA_BAND5_PT2B PDATA_BAND5_PT2
#endif
#ifndef PDATA_BAND5_PT3A
   #define PDATA_BAND5_PT3A PDATA_BAND5_PT3
#endif

#ifndef PDATA_BAND6_PR2B
   #define PDATA_BAND6_PR2B PDATA_BAND6_PR2
#endif
#ifndef PDATA_BAND6_PR3A
   #define PDATA_BAND6_PR3A PDATA_BAND6_PR3
#endif
#ifndef PDATA_BAND6_PT2B
   #define PDATA_BAND6_PT2B PDATA_BAND6_PT2
#endif
#ifndef PDATA_BAND6_PT3A
   #define PDATA_BAND6_PT3A PDATA_BAND6_PT3
#endif

#ifndef PDATA_BAND7_PR2B
   #define PDATA_BAND7_PR2B PDATA_BAND7_PR2
#endif
#ifndef PDATA_BAND7_PR3A
   #define PDATA_BAND7_PR3A PDATA_BAND7_PR3
#endif
#ifndef PDATA_BAND7_PT2B
   #define PDATA_BAND7_PT2B PDATA_BAND7_PT2
#endif
#ifndef PDATA_BAND7_PT3A
   #define PDATA_BAND7_PT3A PDATA_BAND7_PT3
#endif

#ifndef PDATA_BAND8_PR2B
   #define PDATA_BAND8_PR2B PDATA_BAND8_PR2
#endif
#ifndef PDATA_BAND8_PR3A
   #define PDATA_BAND8_PR3A PDATA_BAND8_PR3
#endif
#ifndef PDATA_BAND8_PT2B
   #define PDATA_BAND8_PT2B PDATA_BAND8_PT2
#endif
#ifndef PDATA_BAND8_PT3A
   #define PDATA_BAND8_PT3A PDATA_BAND8_PT3
#endif

#ifndef PDATA_BAND9_PR2B
   #define PDATA_BAND9_PR2B PDATA_BAND9_PR2
#endif
#ifndef PDATA_BAND9_PR3A
   #define PDATA_BAND9_PR3A PDATA_BAND9_PR3
#endif
#ifndef PDATA_BAND9_PT2B
   #define PDATA_BAND9_PT2B PDATA_BAND9_PT2
#endif
#ifndef PDATA_BAND9_PT3A
   #define PDATA_BAND9_PT3A PDATA_BAND9_PT3
#endif

#ifndef PDATA_BAND10_PR2B
   #define PDATA_BAND10_PR2B PDATA_BAND10_PR2
#endif
#ifndef PDATA_BAND10_PR3A
   #define PDATA_BAND10_PR3A PDATA_BAND10_PR3
#endif
#ifndef PDATA_BAND10_PT2B
   #define PDATA_BAND10_PT2B PDATA_BAND10_PT2
#endif
#ifndef PDATA_BAND10_PT3A
   #define PDATA_BAND10_PT3A PDATA_BAND10_PT3
#endif

#ifndef PDATA_BAND11_PR2B
   #define PDATA_BAND11_PR2B PDATA_BAND11_PR2
#endif
#ifndef PDATA_BAND11_PR3A
   #define PDATA_BAND11_PR3A PDATA_BAND11_PR3
#endif
#ifndef PDATA_BAND11_PT2B
   #define PDATA_BAND11_PT2B PDATA_BAND11_PT2
#endif
#ifndef PDATA_BAND11_PT3A
   #define PDATA_BAND11_PT3A PDATA_BAND11_PT3
#endif

#ifndef PDATA_BAND19_PR2B
   #define PDATA_BAND19_PR2B PDATA_BAND19_PR2
#endif
#ifndef PDATA_BAND19_PR3A
   #define PDATA_BAND19_PR3A PDATA_BAND19_PR3
#endif
#ifndef PDATA_BAND19_PT2B
   #define PDATA_BAND19_PT2B PDATA_BAND19_PT2
#endif
#ifndef PDATA_BAND19_PT3A
   #define PDATA_BAND19_PT3A PDATA_BAND19_PT3
#endif


#ifndef  TC_PR3A
   #define  TC_PR3A    TC_PR3+20
#endif
#ifndef  TC_PT3A
   #define  TC_PT3A    TC_PT3+20
#endif
#ifndef  TC_PR2B
   #define  TC_PR2B    TC_PR2+20
#endif
#ifndef  TC_PT2B
   #define  TC_PT2B    TC_PT2+20
#endif
#ifndef  TC_SR2
   #define  TC_SR2    TC_SR1
#endif
#ifndef  TC_SR2B
   #define  TC_SR2B    TC_SR2
#endif
#ifndef  TC_ST2
   #define  TC_ST2    TC_ST1
#endif
#ifndef  TC_ST2B
   #define  TC_ST2B    TC_ST2
#endif
#ifndef  TC_ST2C
   #define  TC_ST2C    TC_ST2B
#endif


//Add for RXD
#ifndef  PDATA2_BAND1_PR1
   #define  PDATA2_BAND1_PR1     0
   #define  PDATA2_BAND1_PR2     0
   #define  PDATA2_BAND1_PR3     0
#endif
#ifndef  PDATA2_BAND2_PR1
   #define  PDATA2_BAND2_PR1     0
   #define  PDATA2_BAND2_PR2     0
   #define  PDATA2_BAND2_PR3     0
#endif
#ifndef  PDATA2_BAND3_PR1
   #define  PDATA2_BAND3_PR1     0
   #define  PDATA2_BAND3_PR2     0
   #define  PDATA2_BAND3_PR3     0
#endif
#ifndef  PDATA2_BAND4_PR1
   #define  PDATA2_BAND4_PR1     0
   #define  PDATA2_BAND4_PR2     0
   #define  PDATA2_BAND4_PR3     0
#endif
#ifndef  PDATA2_BAND5_PR1
   #define  PDATA2_BAND5_PR1     0
   #define  PDATA2_BAND5_PR2     0
   #define  PDATA2_BAND5_PR3     0
#endif
#ifndef  PDATA2_BAND6_PR1
   #define  PDATA2_BAND6_PR1     0
   #define  PDATA2_BAND6_PR2     0
   #define  PDATA2_BAND6_PR3     0
#endif
#ifndef  PDATA2_BAND7_PR1
   #define  PDATA2_BAND7_PR1     0
   #define  PDATA2_BAND7_PR2     0
   #define  PDATA2_BAND7_PR3     0
#endif
#ifndef  PDATA2_BAND8_PR1
   #define  PDATA2_BAND8_PR1     0
   #define  PDATA2_BAND8_PR2     0
   #define  PDATA2_BAND8_PR3     0
#endif
#ifndef  PDATA2_BAND9_PR1
   #define  PDATA2_BAND9_PR1     0
   #define  PDATA2_BAND9_PR2     0
   #define  PDATA2_BAND9_PR3     0
#endif
#ifndef  PDATA2_BAND10_PR1
   #define  PDATA2_BAND10_PR1     0
   #define  PDATA2_BAND10_PR2     0
   #define  PDATA2_BAND10_PR3     0
#endif
#ifndef  PDATA2_BAND11_PR1
   #define  PDATA2_BAND11_PR1     0
   #define  PDATA2_BAND11_PR2     0
   #define  PDATA2_BAND11_PR3     0
#endif
#ifndef  PDATA2_BAND19_PR1
   #define  PDATA2_BAND19_PR1     0
   #define  PDATA2_BAND19_PR2     0
   #define  PDATA2_BAND19_PR3     0
#endif

/* Define PDATA2_BANDx_PRx */
#ifndef PDATA2_BAND1_PR2B
   #define PDATA2_BAND1_PR2B PDATA2_BAND1_PR2
#endif
#ifndef PDATA2_BAND1_PR3A
   #define PDATA2_BAND1_PR3A PDATA2_BAND1_PR3
#endif
#ifndef PDATA2_BAND2_PR2B
   #define PDATA2_BAND2_PR2B PDATA2_BAND2_PR2
#endif
#ifndef PDATA2_BAND2_PR3A
   #define PDATA2_BAND2_PR3A PDATA2_BAND2_PR3
#endif
#ifndef PDATA2_BAND3_PR2B
   #define PDATA2_BAND3_PR2B PDATA2_BAND3_PR2
#endif
#ifndef PDATA2_BAND3_PR3A
   #define PDATA2_BAND3_PR3A PDATA2_BAND3_PR3
#endif
#ifndef PDATA2_BAND4_PR2B
   #define PDATA2_BAND4_PR2B PDATA2_BAND4_PR2
#endif
#ifndef PDATA2_BAND4_PR3A
   #define PDATA2_BAND4_PR3A PDATA2_BAND4_PR3
#endif
#ifndef PDATA2_BAND5_PR2B
   #define PDATA2_BAND5_PR2B PDATA2_BAND5_PR2
#endif
#ifndef PDATA2_BAND5_PR3A
   #define PDATA2_BAND5_PR3A PDATA2_BAND5_PR3
#endif
#ifndef PDATA2_BAND6_PR2B
   #define PDATA2_BAND6_PR2B PDATA2_BAND6_PR2
#endif
#ifndef PDATA2_BAND6_PR3A
   #define PDATA2_BAND6_PR3A PDATA2_BAND6_PR3
#endif
#ifndef PDATA2_BAND7_PR2B
   #define PDATA2_BAND7_PR2B PDATA2_BAND7_PR2
#endif
#ifndef PDATA2_BAND7_PR3A
   #define PDATA2_BAND7_PR3A PDATA2_BAND7_PR3
#endif
#ifndef PDATA2_BAND8_PR2B
   #define PDATA2_BAND8_PR2B PDATA2_BAND8_PR2
#endif
#ifndef PDATA2_BAND8_PR3A
   #define PDATA2_BAND8_PR3A PDATA2_BAND8_PR3
#endif
#ifndef PDATA2_BAND9_PR2B
   #define PDATA2_BAND9_PR2B PDATA2_BAND9_PR2
#endif
#ifndef PDATA2_BAND9_PR3A
   #define PDATA2_BAND9_PR3A PDATA2_BAND9_PR3
#endif
#ifndef PDATA2_BAND10_PR2B
   #define PDATA2_BAND10_PR2B PDATA2_BAND10_PR2
#endif
#ifndef PDATA2_BAND10_PR3A
   #define PDATA2_BAND10_PR3A PDATA2_BAND10_PR3
#endif
#ifndef PDATA2_BAND11_PR2B
   #define PDATA2_BAND11_PR2B PDATA2_BAND11_PR2
#endif
#ifndef PDATA2_BAND11_PR3A
   #define PDATA2_BAND11_PR3A PDATA2_BAND11_PR3
#endif
#ifndef PDATA2_BAND19_PR2B
   #define PDATA2_BAND19_PR2B PDATA2_BAND19_PR2
#endif
#ifndef PDATA2_BAND19_PR3A
   #define PDATA2_BAND19_PR3A PDATA2_BAND19_PR3
#endif

/* Define BANDx_CHANNEL_SEL */
#ifndef BAND1_CHANNEL_SEL
   #define BAND1_CHANNEL_SEL NON_USED_BAND
#endif
#ifndef BAND2_CHANNEL_SEL
   #define BAND2_CHANNEL_SEL NON_USED_BAND
#endif
#ifndef BAND3_CHANNEL_SEL
   #define BAND3_CHANNEL_SEL NON_USED_BAND
#endif
#ifndef BAND4_CHANNEL_SEL
   #define BAND4_CHANNEL_SEL NON_USED_BAND
#endif
#ifndef BAND5_CHANNEL_SEL
   #define BAND5_CHANNEL_SEL NON_USED_BAND
#endif
#ifndef BAND6_CHANNEL_SEL
   #define BAND6_CHANNEL_SEL NON_USED_BAND
#endif
#ifndef BAND8_CHANNEL_SEL
   #define BAND8_CHANNEL_SEL NON_USED_BAND
#endif
#ifndef BAND9_CHANNEL_SEL
   #define BAND9_CHANNEL_SEL NON_USED_BAND
#endif
#ifndef BAND10_CHANNEL_SEL
   #define BAND10_CHANNEL_SEL NON_USED_BAND
#endif
#ifndef BAND11_CHANNEL_SEL
   #define BAND11_CHANNEL_SEL NON_USED_BAND
#endif
#ifndef BAND19_CHANNEL_SEL
   #define BAND19_CHANNEL_SEL NON_USED_BAND
#endif


/* Define BANDx_CHANNEL2_SEL */
#ifndef BAND1_CHANNEL2_SEL
   #define BAND1_CHANNEL2_SEL NON_USED_BAND
#endif
#ifndef BAND2_CHANNEL2_SEL
   #define BAND2_CHANNEL2_SEL NON_USED_BAND
#endif
#ifndef BAND3_CHANNEL2_SEL
   #define BAND3_CHANNEL2_SEL NON_USED_BAND
#endif
#ifndef BAND4_CHANNEL2_SEL
   #define BAND4_CHANNEL2_SEL NON_USED_BAND
#endif
#ifndef BAND5_CHANNEL2_SEL
   #define BAND5_CHANNEL2_SEL NON_USED_BAND
#endif
#ifndef BAND6_CHANNEL2_SEL
   #define BAND6_CHANNEL2_SEL NON_USED_BAND
#endif
#ifndef BAND8_CHANNEL2_SEL
   #define BAND8_CHANNEL2_SEL NON_USED_BAND
#endif
#ifndef BAND9_CHANNEL2_SEL
   #define BAND9_CHANNEL2_SEL NON_USED_BAND
#endif
#ifndef BAND10_CHANNEL2_SEL
   #define BAND10_CHANNEL2_SEL NON_USED_BAND
#endif
#ifndef BAND11_CHANNEL2_SEL
   #define BAND11_CHANNEL2_SEL NON_USED_BAND
#endif
#ifndef BAND19_CHANNEL2_SEL
   #define BAND19_CHANNEL2_SEL NON_USED_BAND
#endif

/* Define RX_HIGHBAND3_INDICATOR for 4-bands users (MT6572/82) */
#ifndef RX_HIGHBAND3_INDICATOR
   #define RX_HIGHBAND3_INDICATOR UMTSBandNone
#endif
/* Define RX_LOWBAND2_INDICATOR for 3-bands (MT6290 Dongle, HW limitation) */
#ifndef RX_LOWBAND2_INDICATOR
   #define RX_LOWBAND2_INDICATOR  UMTSBandNone
#endif


///////////

#ifndef  TC_PR1_2
   #define  TC_PR1_2    TC_PR1
#endif
#ifndef  TC_PR2_2
   #define  TC_PR2_2    TC_PR2
#endif
#ifndef  TC_PR2B_2
   #define  TC_PR2B_2   TC_PR2B
#endif
#ifndef  TC_PR3_2
   #define  TC_PR3_2    TC_PR3
#endif
#ifndef  TC_PR3A_2
   #define  TC_PR3A_2   TC_PR3A
#endif

//For Dual Cell
#ifndef TC_DC_SR1
   #define TC_DC_SR1    TC_SR2
#endif
#ifndef TC_DC_SR2
   #define TC_DC_SR2    TC_SR2B
#endif
#ifndef TC_RXD_SR1
   #define TC_RXD_SR1   TC_SR2B
#endif
#ifndef TC_RXD_SR3
   #define TC_RXD_SR3   TC_SR3
#endif

//For MPR Setting
#ifndef MPR_BACK_OFF_HSDPA_BAND1
   #define    MPR_BACK_OFF_HSDPA_BAND1  MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSDPA_BAND2
   #define    MPR_BACK_OFF_HSDPA_BAND2  MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSDPA_BAND3
   #define    MPR_BACK_OFF_HSDPA_BAND3  MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSDPA_BAND4
   #define    MPR_BACK_OFF_HSDPA_BAND4  MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSDPA_BAND5
   #define    MPR_BACK_OFF_HSDPA_BAND5  MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSDPA_BAND6
   #define    MPR_BACK_OFF_HSDPA_BAND6  MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSDPA_BAND8
   #define    MPR_BACK_OFF_HSDPA_BAND8  MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSDPA_BAND9
   #define    MPR_BACK_OFF_HSDPA_BAND9  MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSDPA_BAND10
   #define    MPR_BACK_OFF_HSDPA_BAND10 MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSDPA_BAND11
   #define    MPR_BACK_OFF_HSDPA_BAND11 MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSDPA_BAND19
   #define    MPR_BACK_OFF_HSDPA_BAND19 MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSUPA_BAND1
   #define    MPR_BACK_OFF_HSUPA_BAND1  MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSUPA_BAND2
   #define    MPR_BACK_OFF_HSUPA_BAND2  MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSUPA_BAND3
   #define    MPR_BACK_OFF_HSUPA_BAND3  MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSUPA_BAND4
   #define    MPR_BACK_OFF_HSUPA_BAND4  MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSUPA_BAND5
   #define    MPR_BACK_OFF_HSUPA_BAND5  MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSUPA_BAND6
   #define    MPR_BACK_OFF_HSUPA_BAND6  MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSUPA_BAND8
   #define    MPR_BACK_OFF_HSUPA_BAND8  MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSUPA_BAND9
   #define    MPR_BACK_OFF_HSUPA_BAND9  MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSUPA_BAND10
   #define    MPR_BACK_OFF_HSUPA_BAND10 MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSUPA_BAND11
   #define    MPR_BACK_OFF_HSUPA_BAND11 MPRSetting2
#endif
#ifndef MPR_BACK_OFF_HSUPA_BAND19
   #define    MPR_BACK_OFF_HSUPA_BAND19 MPRSetting2
#endif
#define    MPR_BACK_OFF_HSDPA_BAND7  MPRSetting2
#define    MPR_BACK_OFF_HSDPA_BAND12 MPRSetting2
#define    MPR_BACK_OFF_HSDPA_BAND13 MPRSetting2
#define    MPR_BACK_OFF_HSDPA_BAND14 MPRSetting2
#define    MPR_BACK_OFF_HSDPA_BAND15 MPRSetting2
#define    MPR_BACK_OFF_HSDPA_BAND16 MPRSetting2
#define    MPR_BACK_OFF_HSDPA_BAND17 MPRSetting2
#define    MPR_BACK_OFF_HSDPA_BAND18 MPRSetting2
#define    MPR_BACK_OFF_HSUPA_BAND7  MPRSetting2
#define    MPR_BACK_OFF_HSUPA_BAND12 MPRSetting2
#define    MPR_BACK_OFF_HSUPA_BAND13 MPRSetting2
#define    MPR_BACK_OFF_HSUPA_BAND14 MPRSetting2
#define    MPR_BACK_OFF_HSUPA_BAND15 MPRSetting2
#define    MPR_BACK_OFF_HSUPA_BAND16 MPRSetting2
#define    MPR_BACK_OFF_HSUPA_BAND17 MPRSetting2
#define    MPR_BACK_OFF_HSUPA_BAND18 MPRSetting2

#ifndef ULTRA_LOW_COST_EN
   #define ULTRA_LOW_COST_EN   KAL_FALSE
#endif

#ifndef TEAMPERATURE_MEAS_EN
   #define TEAMPERATURE_MEAS_EN   KAL_FALSE
#endif

#ifndef VPA_FPWM_MODE
   #define VPA_FPWM_MODE          KAL_FALSE
#endif

#ifndef IS_3G_DRDI_SUPPORT
   #define IS_3G_DRDI_SUPPORT  0 
#endif


#endif /* End of #ifndef UL1D_RF_COMMON_H */

