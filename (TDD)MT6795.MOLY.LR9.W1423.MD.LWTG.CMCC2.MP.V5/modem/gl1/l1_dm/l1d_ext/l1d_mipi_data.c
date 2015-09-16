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
 *   l1d_mipi_data.c
 *
 * Project:
 * --------
 *   MT6290
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
 * $Revision:
 * $Modtime:
 * $Log:
 *
 *******************************************************************************/

#include  "l1d_cid.h"
#include  "l1d_reg.h"
#include  "l1d_data.h"
#include  "l1d_custom_rf.h"
#include  "l1d_rf.h"

#if IS_MIPI_SUPPORT
#include  "l1d_custom_mipi.h"
#include  "l1d_mipi_data.h"
#include  "l1d_mipi.h"
#endif
/*===============================================================================================*/

#if IS_MIPI_SUPPORT

   #if IS_CHIP_MT6290 || IS_CHIP_MT6595 || IS_CHIP_MT6752_MD1
#define GGE_MIPI_EVNET_TIMING_CHECK_MARGIN 5 /* (1/60MHz)*(304+N) ~= 5.6Qb , 304 Data table size */
   #else
#error "Please define mipi event gap (GGE_MIPI_EVNET_TIMING_CHECK_MARGIN) at l1d_mipi_data.c"
   #endif
   #if IS_MIPI_INTERSLOT_RAMPING_OPTIMIZE_SUPPORT
#define GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN 6 /* GGE_MIPI_EVNET_TIMING_CHECK_MARGIN + 1QB, since ST2M_G8/ST2M_8G has more BSI data */
   #endif

/* BSI Event Check */
   #if (GGE_MIPI_RTX_EVENT_NUM*(GGE_MIPI_RTX_EVENT_COUNT)+GGE_MIPI_TXMID_EVENT_NUM*(GGE_MIPI_TXMID_EVENT_COUNT)+GGE_MIPI_RF_EVENT_COUNT  > BSI_EVENT_COUNT)
#error "BSI_RTX_EVENT_MIPI_PLUS_RF_ is exceed BSI_EVENT_COUNT"
   #endif
   #if (GGE_MIPI_RTX_DATA_NUM*(GGE_MIPI_RTX_EVENT_COUNT)+GGE_MIPI_TXMID_DATA_NUM*(GGE_MIPI_TXMID_EVENT_COUNT)+GGE_MIPI_RF_DATA_COUNT  > BSI_DATA_COUNT)
#error "BSI_RTX_DATA_MIPI_PLUS_RF_ is exceed BSI_EVENT_COUNT"
   #endif

/* General timing check for slot 0 RX window */
   #if TQ_MIPI_RX_ON0>TQ_AFC_READY
#error "TQ_TQ_MIPI_RX_ON0 should not be larger than TQ_AFC_READY"
   #endif

   #if TQ_MIPI_RX_ON1>TQ_AFC_READY
#error "TQ_TQ_MIPI_RX_ON1 should not be larger than TQ_AFC_READY"
   #endif

   #if TQ_MIPI_RX_ON2>TQ_AFC_READY
#error "TQ_TQ_MIPI_RX_ON2 should not be larger than TQ_AFC_READY"
   #endif

   #if TQ_MIPI_RX_ON3>TQ_AFC_READY
#error "TQ_TQ_MIPI_RX_ON3 should not be larger than TQ_AFC_READY"
   #endif

   #if TQ_MIPI_RX_ON4>TQ_AFC_READY
#error "TQ_TQ_MIPI_RX_ON4 should not be larger than TQ_AFC_READY"
   #endif

   #if TQ_MIPI_RX_ON5>TQ_AFC_READY
#error "TQ_TQ_MIPI_RX_ON5 should not be larger than TQ_AFC_READY"
   #endif

   #if TQ_MIPI_RX_ON6>TQ_AFC_READY
#error "TQ_TQ_MIPI_RX_ON6 should not be larger than TQ_AFC_READY"
   #endif

   #if TQ_MIPI_RX_ON7>TQ_AFC_READY
#error "TQ_TQ_MIPI_RX_ON7 should not be larger than TQ_AFC_READY"
   #endif

#if L1D_PM_ENHANCE
   #if ( ( TQ_MIPI_RX_OFF0 >= TQ_PM_WIN_OFF_MARGIN )&&( QB_MIPI_RX_OFF0!= 10000 ) )
#warning "TQ_MIPI_RX_OFF0 = QB_MIPI_RX_OFF0-QB_FSYNC_2_ROFF suggest smaller than 8"
   #endif
   #if ( ( TQ_MIPI_RX_OFF1 >= TQ_PM_WIN_OFF_MARGIN )&&( QB_MIPI_RX_OFF1!= 10000 ) )
#warning "TQ_MIPI_RX_OFF1 = QB_MIPI_RX_OFF1-QB_FSYNC_2_ROFF suggest smaller than 8"
   #endif
   #if ( ( TQ_MIPI_RX_OFF2 >= TQ_PM_WIN_OFF_MARGIN )&&( QB_MIPI_RX_OFF2!= 10000 ) )
#warning "TQ_MIPI_RX_OFF2 = QB_MIPI_RX_OFF2-QB_FSYNC_2_ROFF suggest smaller than 8"
   #endif
   #if ( ( TQ_MIPI_RX_OFF3 >= TQ_PM_WIN_OFF_MARGIN )&&( QB_MIPI_RX_OFF3!= 10000 ) )
#warning "TQ_MIPI_RX_OFF3 = QB_MIPI_RX_OFF3-QB_FSYNC_2_ROFF suggest smaller than 8"
   #endif
   #if ( ( TQ_MIPI_RX_OFF4 >= TQ_PM_WIN_OFF_MARGIN )&&( QB_MIPI_RX_OFF4!= 10000 ) )
#warning "TQ_MIPI_RX_OFF4 = QB_MIPI_RX_OFF4-QB_FSYNC_2_ROFF suggest smaller than 8"
   #endif
#endif

//multievent - 5QB  detect RX on
   #if ( QB_MIPI_RX_ON0 != -10000 )
      #if ( ( ( QB_MIPI_RX_ON0 - QB_MIPI_RX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON0 - QB_MIPI_RX_ON1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON0 & QB_MIPI_RX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON0 - QB_MIPI_RX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON0 - QB_MIPI_RX_ON2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON0 & QB_MIPI_RX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON0 - QB_MIPI_RX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON0 - QB_MIPI_RX_ON3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON0 & QB_MIPI_RX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON0 - QB_MIPI_RX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON0 - QB_MIPI_RX_ON4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON0 & QB_MIPI_RX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON0 - QB_MIPI_RX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON0 - QB_MIPI_RX_ON5 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON0 & QB_MIPI_RX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON0 - QB_MIPI_RX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON0 - QB_MIPI_RX_ON6 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON0 & QB_MIPI_RX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON0 - QB_MIPI_RX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON0 - QB_MIPI_RX_ON7 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON0 & QB_MIPI_RX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON0 - QB_SR0) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON0 - QB_SR0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON0 & QB_SR0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON0 - QB_SR1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON0 - QB_SR1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON0 & QB_SR1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON0 - QB_SR2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON0 - QB_SR2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON0 & QB_SR2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_MIPI_RX_ON1 != -10000 )
      #if ( ( ( QB_MIPI_RX_ON1 - QB_MIPI_RX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON1 - QB_MIPI_RX_ON0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON1 & QB_MIPI_RX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON1 - QB_MIPI_RX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON1 - QB_MIPI_RX_ON2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON1 & QB_MIPI_RX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON1 - QB_MIPI_RX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON1 - QB_MIPI_RX_ON3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON1 & QB_MIPI_RX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON1 - QB_MIPI_RX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON1 - QB_MIPI_RX_ON4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON1 & QB_MIPI_RX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON1 - QB_MIPI_RX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON1 - QB_MIPI_RX_ON5 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON1 & QB_MIPI_RX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON1 - QB_MIPI_RX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON1 - QB_MIPI_RX_ON6 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON1 & QB_MIPI_RX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON1 - QB_MIPI_RX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON1 - QB_MIPI_RX_ON7 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON1 & QB_MIPI_RX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON1 - QB_SR0) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON1 - QB_SR0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON1 & QB_SR0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON1 - QB_SR1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON1 - QB_SR1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON1 & QB_SR1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON1 - QB_SR2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON1 - QB_SR2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON1 & QB_SR2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_MIPI_RX_ON2 != -10000 )
      #if ( ( ( QB_MIPI_RX_ON2 - QB_MIPI_RX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON2 - QB_MIPI_RX_ON0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON2 & QB_MIPI_RX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON2 - QB_MIPI_RX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON2 - QB_MIPI_RX_ON1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON2 & QB_MIPI_RX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON2 - QB_MIPI_RX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON2 - QB_MIPI_RX_ON3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON2 & QB_MIPI_RX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON2 - QB_MIPI_RX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON2 - QB_MIPI_RX_ON4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON2 & QB_MIPI_RX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON2 - QB_MIPI_RX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON2 - QB_MIPI_RX_ON5 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON2 & QB_MIPI_RX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON2 - QB_MIPI_RX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON2 - QB_MIPI_RX_ON6 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON2 & QB_MIPI_RX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON2 - QB_MIPI_RX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON2 - QB_MIPI_RX_ON7 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON2 & QB_MIPI_RX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON2 - QB_SR0) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON2 - QB_SR0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON2 & QB_SR0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON2 - QB_SR1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON2 - QB_SR1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON2 & QB_SR1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON2 - QB_SR2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON2 - QB_SR2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON2 & QB_SR2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif


   #if ( QB_MIPI_RX_ON3 != -10000 )
      #if ( ( ( QB_MIPI_RX_ON3 - QB_MIPI_RX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON3 - QB_MIPI_RX_ON0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON3 & QB_MIPI_RX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON3 - QB_MIPI_RX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON3 - QB_MIPI_RX_ON1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON3 & QB_MIPI_RX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON3 - QB_MIPI_RX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON3 - QB_MIPI_RX_ON2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON3 & QB_MIPI_RX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON3 - QB_MIPI_RX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON3 - QB_MIPI_RX_ON4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON3 & QB_MIPI_RX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON3 - QB_MIPI_RX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON3 - QB_MIPI_RX_ON5 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON3 & QB_MIPI_RX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON3 - QB_MIPI_RX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON3 - QB_MIPI_RX_ON6 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON3 & QB_MIPI_RX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON3 - QB_MIPI_RX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON3 - QB_MIPI_RX_ON7 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON3 & QB_MIPI_RX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON3 - QB_SR0) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON3 - QB_SR0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON3 & QB_SR0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON3 - QB_SR1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON3 - QB_SR1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON3 & QB_SR1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON3 - QB_SR2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON3 - QB_SR2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON3 & QB_SR2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_MIPI_RX_ON4 != -10000 )
      #if ( ( ( QB_MIPI_RX_ON4 - QB_MIPI_RX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON4 - QB_MIPI_RX_ON0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON4 & QB_MIPI_RX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON4 - QB_MIPI_RX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON4 - QB_MIPI_RX_ON1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON4 & QB_MIPI_RX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON4 - QB_MIPI_RX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON4 - QB_MIPI_RX_ON2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON4 & QB_MIPI_RX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON4 - QB_MIPI_RX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON4 - QB_MIPI_RX_ON3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON4 & QB_MIPI_RX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON4 - QB_MIPI_RX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON4 - QB_MIPI_RX_ON5 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON4 & QB_MIPI_RX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON4 - QB_MIPI_RX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON4 - QB_MIPI_RX_ON6 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON4 & QB_MIPI_RX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON4 - QB_MIPI_RX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON4 - QB_MIPI_RX_ON7 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON4 & QB_MIPI_RX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON4 - QB_SR0) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON4 - QB_SR0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON4 & QB_SR0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON4 - QB_SR1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON4 - QB_SR1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON4 & QB_SR1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON4 - QB_SR2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON4 - QB_SR2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON4 & QB_SR2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif


   #if ( QB_MIPI_RX_ON5 != -10000 )
      #if ( ( ( QB_MIPI_RX_ON5 - QB_MIPI_RX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON5 - QB_MIPI_RX_ON0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON5 & QB_MIPI_RX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON5 - QB_MIPI_RX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON5 - QB_MIPI_RX_ON1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON5 & QB_MIPI_RX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON5 - QB_MIPI_RX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON5 - QB_MIPI_RX_ON2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON5 & QB_MIPI_RX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON5 - QB_MIPI_RX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON5 - QB_MIPI_RX_ON3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON5 & QB_MIPI_RX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON5 - QB_MIPI_RX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON5 - QB_MIPI_RX_ON4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON5 & QB_MIPI_RX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON5 - QB_MIPI_RX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON5 - QB_MIPI_RX_ON6 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON5 & QB_MIPI_RX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON5 - QB_MIPI_RX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON5 - QB_MIPI_RX_ON7 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON5 & QB_MIPI_RX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON5 - QB_SR0) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON5 - QB_SR0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON5 & QB_SR0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON5 - QB_SR1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON5 - QB_SR1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON5 & QB_SR1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON5 - QB_SR2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON5 - QB_SR2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON5 & QB_SR2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif


   #if ( QB_MIPI_RX_ON6 != -10000 )
      #if ( ( ( QB_MIPI_RX_ON6 - QB_MIPI_RX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON6 - QB_MIPI_RX_ON0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON6 & QB_MIPI_RX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON6 - QB_MIPI_RX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON6 - QB_MIPI_RX_ON1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON6 & QB_MIPI_RX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON6 - QB_MIPI_RX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON6 - QB_MIPI_RX_ON2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON6 & QB_MIPI_RX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON6 - QB_MIPI_RX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON6 - QB_MIPI_RX_ON3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON6 & QB_MIPI_RX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON6 - QB_MIPI_RX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON6 - QB_MIPI_RX_ON4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON6 & QB_MIPI_RX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON6 - QB_MIPI_RX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON6 - QB_MIPI_RX_ON5 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON6 & QB_MIPI_RX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON6 - QB_MIPI_RX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON6 - QB_MIPI_RX_ON7 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON6 & QB_MIPI_RX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON6 - QB_SR0) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON6 - QB_SR0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON6 & QB_SR0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON6 - QB_SR1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON6 - QB_SR1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON6 & QB_SR1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON6 - QB_SR2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON6 - QB_SR2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON6 & QB_SR2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif


   #if ( QB_MIPI_RX_ON7 != -10000 )
      #if ( ( ( QB_MIPI_RX_ON7 - QB_MIPI_RX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON7 - QB_MIPI_RX_ON0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON7 & QB_MIPI_RX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON7 - QB_MIPI_RX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON7 - QB_MIPI_RX_ON1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON7 & QB_MIPI_RX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON7 - QB_MIPI_RX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON7 - QB_MIPI_RX_ON2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON7 & QB_MIPI_RX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON7 - QB_MIPI_RX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON7 - QB_MIPI_RX_ON3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON7 & QB_MIPI_RX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON7 - QB_MIPI_RX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON7 - QB_MIPI_RX_ON4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON7 & QB_MIPI_RX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON7 - QB_MIPI_RX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON7 - QB_MIPI_RX_ON5 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON7 & QB_MIPI_RX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON7 - QB_MIPI_RX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON7 - QB_MIPI_RX_ON6 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON7 & QB_MIPI_RX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON7 - QB_SR0) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON7 - QB_SR0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON7 & QB_SR0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON7 - QB_SR1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON7 - QB_SR1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON7 & QB_SR1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_ON7 - QB_SR2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_ON7 - QB_SR2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_ON7 & QB_SR2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_SR0 != -10000 )
      #if ( ( ( QB_SR0 - QB_MIPI_RX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR0 - QB_MIPI_RX_ON0 ) >= 0))
#error "The differece between Event Timing QB_SR0 & QB_MIPI_RX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR0 - QB_MIPI_RX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR0 - QB_MIPI_RX_ON1 ) >= 0))
#error "The differece between Event Timing QB_SR0 & QB_MIPI_RX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR0 - QB_MIPI_RX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR0 - QB_MIPI_RX_ON2 ) >= 0))
#error "The differece between Event Timing QB_SR0 & QB_MIPI_RX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR0 - QB_MIPI_RX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR0 - QB_MIPI_RX_ON3 ) >= 0))
#error "The differece between Event Timing QB_SR0 & QB_MIPI_RX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR0 - QB_MIPI_RX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR0 - QB_MIPI_RX_ON4 ) >= 0))
#error "The differece between Event Timing QB_SR0 & QB_MIPI_RX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR0 - QB_MIPI_RX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR0 - QB_MIPI_RX_ON5 ) >= 0))
#error "The differece between Event Timing QB_SR0 & QB_MIPI_RX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR0 - QB_MIPI_RX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR0 - QB_MIPI_RX_ON6 ) >= 0))
#error "The differece between Event Timing QB_SR0 & QB_MIPI_RX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR0 - QB_MIPI_RX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR0 - QB_MIPI_RX_ON7 ) >= 0))
#error "The differece between Event Timing QB_SR0 & QB_MIPI_RX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_SR1 != -10000 )
      #if ( ( ( QB_SR1 - QB_MIPI_RX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR1 - QB_MIPI_RX_ON0 ) >= 0))
#error "The differece between Event Timing QB_SR1 & QB_MIPI_RX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR1 - QB_MIPI_RX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR1 - QB_MIPI_RX_ON1 ) >= 0))
#error "The differece between Event Timing QB_SR1 & QB_MIPI_RX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR1 - QB_MIPI_RX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR1 - QB_MIPI_RX_ON2 ) >= 0))
#error "The differece between Event Timing QB_SR1 & QB_MIPI_RX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR1 - QB_MIPI_RX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR1 - QB_MIPI_RX_ON3 ) >= 0))
#error "The differece between Event Timing QB_SR1 & QB_MIPI_RX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR1 - QB_MIPI_RX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR1 - QB_MIPI_RX_ON4 ) >= 0))
#error "The differece between Event Timing QB_SR1 & QB_MIPI_RX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR1 - QB_MIPI_RX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR1 - QB_MIPI_RX_ON5 ) >= 0))
#error "The differece between Event Timing QB_SR1 & QB_MIPI_RX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR1 - QB_MIPI_RX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR1 - QB_MIPI_RX_ON6 ) >= 0))
#error "The differece between Event Timing QB_SR1 & QB_MIPI_RX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR1 - QB_MIPI_RX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR1 - QB_MIPI_RX_ON7 ) >= 0))
#error "The differece between Event Timing QB_SR1 & QB_MIPI_RX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif
   
   #if ( QB_SR2 != -10000 )
      #if ( ( ( QB_SR2 - QB_MIPI_RX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR2 - QB_MIPI_RX_ON0 ) >= 0))
#error "The differece between Event Timing QB_SR2 & QB_MIPI_RX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR2 - QB_MIPI_RX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR2 - QB_MIPI_RX_ON1 ) >= 0))
#error "The differece between Event Timing QB_SR2 & QB_MIPI_RX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR2 - QB_MIPI_RX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR2 - QB_MIPI_RX_ON2 ) >= 0))
#error "The differece between Event Timing QB_SR2 & QB_MIPI_RX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR2 - QB_MIPI_RX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR2 - QB_MIPI_RX_ON3 ) >= 0))
#error "The differece between Event Timing QB_SR2 & QB_MIPI_RX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR2 - QB_MIPI_RX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR2 - QB_MIPI_RX_ON4 ) >= 0))
#error "The differece between Event Timing QB_SR2 & QB_MIPI_RX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR2 - QB_MIPI_RX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR2 - QB_MIPI_RX_ON5 ) >= 0))
#error "The differece between Event Timing QB_SR2 & QB_MIPI_RX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR2 - QB_MIPI_RX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR2 - QB_MIPI_RX_ON6 ) >= 0))
#error "The differece between Event Timing QB_SR2 & QB_MIPI_RX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR2 - QB_MIPI_RX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR2 - QB_MIPI_RX_ON7 ) >= 0))
#error "The differece between Event Timing QB_SR2 & QB_MIPI_RX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

//multievent - 5QB  detect RX off
   #if ( QB_MIPI_RX_OFF0 != 10000 )
      #if   ( ( ( QB_MIPI_RX_OFF0 - QB_MIPI_RX_OFF1) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF0 - QB_MIPI_RX_OFF1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF0 & QB_MIPI_RX_OFF1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF0 - QB_MIPI_RX_OFF2) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF0 - QB_MIPI_RX_OFF2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF0 & QB_MIPI_RX_OFF2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF0 - QB_MIPI_RX_OFF3) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF0 - QB_MIPI_RX_OFF3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF0 & QB_MIPI_RX_OFF3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF0 - QB_MIPI_RX_OFF4) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF0 - QB_MIPI_RX_OFF4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF0 & QB_MIPI_RX_OFF4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF0 - QB_SR3) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF0 - QB_SR3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF0 & QB_SR3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_MIPI_RX_OFF1 != 10000 )
      #if   ( ( ( QB_MIPI_RX_OFF1 - QB_MIPI_RX_OFF0) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF1 - QB_MIPI_RX_OFF0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF1 & QB_MIPI_RX_OFF0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF1 - QB_MIPI_RX_OFF2) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF1 - QB_MIPI_RX_OFF2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF1 & QB_MIPI_RX_OFF2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF1 - QB_MIPI_RX_OFF3) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF1 - QB_MIPI_RX_OFF3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF1 & QB_MIPI_RX_OFF3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF1 - QB_MIPI_RX_OFF4) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF1 - QB_MIPI_RX_OFF4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF1 & QB_MIPI_RX_OFF4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF1 - QB_SR3) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF1 - QB_SR3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF1 & QB_SR3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_MIPI_RX_OFF2 != 10000 )
      #if   ( ( ( QB_MIPI_RX_OFF2 - QB_MIPI_RX_OFF0) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF2 - QB_MIPI_RX_OFF0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF2 & QB_MIPI_RX_OFF0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF2 - QB_MIPI_RX_OFF1) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF2 - QB_MIPI_RX_OFF1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF2 & QB_MIPI_RX_OFF1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF2 - QB_MIPI_RX_OFF3) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF2 - QB_MIPI_RX_OFF3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF2 & QB_MIPI_RX_OFF3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF2 - QB_MIPI_RX_OFF4) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF2 - QB_MIPI_RX_OFF4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF2 & QB_MIPI_RX_OFF4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF2 - QB_SR3) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF2 - QB_SR3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF2 & QB_SR3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_MIPI_RX_OFF3 != 10000 )
      #if   ( ( ( QB_MIPI_RX_OFF3 - QB_MIPI_RX_OFF0) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF3 - QB_MIPI_RX_OFF0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF3 & QB_MIPI_RX_OFF0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF3 - QB_MIPI_RX_OFF1) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF3 - QB_MIPI_RX_OFF1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF3 & QB_MIPI_RX_OFF1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF3 - QB_MIPI_RX_OFF2) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF3 - QB_MIPI_RX_OFF2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF3 & QB_MIPI_RX_OFF2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF3 - QB_MIPI_RX_OFF4) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF3 - QB_MIPI_RX_OFF4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF3 & QB_MIPI_RX_OFF4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF3 - QB_SR3) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF3 - QB_SR3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF3 & QB_SR3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_MIPI_RX_OFF4 != 10000 )
      #if   ( ( ( QB_MIPI_RX_OFF4 - QB_MIPI_RX_OFF0) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF4 - QB_MIPI_RX_OFF0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF4 & QB_MIPI_RX_OFF0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF4 - QB_MIPI_RX_OFF1) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF4 - QB_MIPI_RX_OFF1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF4 & QB_MIPI_RX_OFF1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF4 - QB_MIPI_RX_OFF2) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF4 - QB_MIPI_RX_OFF2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF4 & QB_MIPI_RX_OFF2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF4 - QB_MIPI_RX_OFF3) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF4 - QB_MIPI_RX_OFF3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF4 & QB_MIPI_RX_OFF3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_RX_OFF4 - QB_SR3) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_RX_OFF4 - QB_SR3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_RX_OFF4 & QB_SR3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_SR3 != 10000 )
      #if   ( ( ( QB_SR3 - QB_MIPI_RX_OFF0) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR3 - QB_MIPI_RX_OFF0 ) >= 0))
#error "The differece between Event Timing QB_SR3 & QB_MIPI_RX_OFF0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR3 - QB_MIPI_RX_OFF1) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR3 - QB_MIPI_RX_OFF1 ) >= 0))
#error "The differece between Event Timing QB_SR3 & QB_MIPI_RX_OFF1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR3 - QB_MIPI_RX_OFF2) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR3 - QB_MIPI_RX_OFF2 ) >= 0))
#error "The differece between Event Timing QB_SR3 & QB_MIPI_RX_OFF2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR3 - QB_MIPI_RX_OFF3) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR3 - QB_MIPI_RX_OFF3 ) >= 0))
#error "The differece between Event Timing QB_SR3 & QB_MIPI_RX_OFF3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_SR3 - QB_MIPI_RX_OFF4) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_SR3 - QB_MIPI_RX_OFF4 ) >= 0))
#error "The differece between Event Timing QB_SR3 & QB_MIPI_RX_OFF4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

//multievent - 5QB  detect TX on
   #if ( QB_MIPI_TX_ON0 != -10000 )
      #if   ( ( ( QB_MIPI_TX_ON0 - QB_MIPI_TX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON0 - QB_MIPI_TX_ON1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON0 & QB_MIPI_TX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON0 - QB_MIPI_TX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON0 - QB_MIPI_TX_ON2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON0 & QB_MIPI_TX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON0 - QB_MIPI_TX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON0 - QB_MIPI_TX_ON3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON0 & QB_MIPI_TX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON0 - QB_MIPI_TX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON0 - QB_MIPI_TX_ON4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON0 & QB_MIPI_TX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON0 - QB_MIPI_TX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON0 - QB_MIPI_TX_ON5 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON0 & QB_MIPI_TX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON0 - QB_MIPI_TX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON0 - QB_MIPI_TX_ON6 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON0 & QB_MIPI_TX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON0 - QB_MIPI_TX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON0 - QB_MIPI_TX_ON7 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON0 & QB_MIPI_TX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON0 - QB_ST0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON0 - QB_ST0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON0 & QB_ST0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON0 - QB_ST1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON0 - QB_ST1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON0 & QB_ST1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON0 - QB_ST2B ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON0 - QB_ST2B ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON0 & QB_ST2B is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_MIPI_TX_ON1 != -10000 )   
      #if   ( ( ( QB_MIPI_TX_ON1 - QB_MIPI_TX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON1 - QB_MIPI_TX_ON0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON1 & QB_MIPI_TX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON1 - QB_MIPI_TX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON1 - QB_MIPI_TX_ON2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON1 & QB_MIPI_TX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON1 - QB_MIPI_TX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON1 - QB_MIPI_TX_ON3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON1 & QB_MIPI_TX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON1 - QB_MIPI_TX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON1 - QB_MIPI_TX_ON4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON1 & QB_MIPI_TX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON1 - QB_MIPI_TX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON1 - QB_MIPI_TX_ON5 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON1 & QB_MIPI_TX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON1 - QB_MIPI_TX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON1 - QB_MIPI_TX_ON6 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON1 & QB_MIPI_TX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON1 - QB_MIPI_TX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON1 - QB_MIPI_TX_ON7 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON1 & QB_MIPI_TX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON1 - QB_ST0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON1 - QB_ST0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON1 & QB_ST0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON1 - QB_ST1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON1 - QB_ST1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON1 & QB_ST1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON1 - QB_ST2B ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON1 - QB_ST2B ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON1 & QB_ST2B is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_MIPI_TX_ON2 != -10000 )
      #if   ( ( ( QB_MIPI_TX_ON2 - QB_MIPI_TX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON2 - QB_MIPI_TX_ON0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON2 & QB_MIPI_TX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON2 - QB_MIPI_TX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON2 - QB_MIPI_TX_ON1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON2 & QB_MIPI_TX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON2 - QB_MIPI_TX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON2 - QB_MIPI_TX_ON3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON2 & QB_MIPI_TX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON2 - QB_MIPI_TX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON2 - QB_MIPI_TX_ON4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON2 & QB_MIPI_TX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON2 - QB_MIPI_TX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON2 - QB_MIPI_TX_ON5 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON2 & QB_MIPI_TX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON2 - QB_MIPI_TX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON2 - QB_MIPI_TX_ON6 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON2 & QB_MIPI_TX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON2 - QB_MIPI_TX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON2 - QB_MIPI_TX_ON7 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON2 & QB_MIPI_TX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON2 - QB_ST0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON2 - QB_ST0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON2 & QB_ST0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON2 - QB_ST1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON2 - QB_ST1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON2 & QB_ST1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON2 - QB_ST2B ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON2 - QB_ST2B ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON2 & QB_ST2B is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_MIPI_TX_ON3 != -10000 )
      #if   ( ( ( QB_MIPI_TX_ON3 - QB_MIPI_TX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON3 - QB_MIPI_TX_ON0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON3 & QB_MIPI_TX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON3 - QB_MIPI_TX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON3 - QB_MIPI_TX_ON1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON3 & QB_MIPI_TX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON3 - QB_MIPI_TX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON3 - QB_MIPI_TX_ON2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON3 & QB_MIPI_TX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON3 - QB_MIPI_TX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON3 - QB_MIPI_TX_ON4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON3 & QB_MIPI_TX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON3 - QB_MIPI_TX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON3 - QB_MIPI_TX_ON5 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON3 & QB_MIPI_TX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON3 - QB_MIPI_TX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON3 - QB_MIPI_TX_ON6 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON3 & QB_MIPI_TX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON3 - QB_MIPI_TX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON3 - QB_MIPI_TX_ON7 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON3 & QB_MIPI_TX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON3 - QB_ST0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON3 - QB_ST0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON3 & QB_ST0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON3 - QB_ST1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON3 - QB_ST1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON3 & QB_ST1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON3 - QB_ST2B ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON3 - QB_ST2B ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON3 & QB_ST2B is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_MIPI_TX_ON4 != -10000 )
      #if   ( ( ( QB_MIPI_TX_ON4 - QB_MIPI_TX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON4 - QB_MIPI_TX_ON0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON4 & QB_MIPI_TX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON4 - QB_MIPI_TX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON4 - QB_MIPI_TX_ON1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON4 & QB_MIPI_TX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON4 - QB_MIPI_TX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON4 - QB_MIPI_TX_ON2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON4 & QB_MIPI_TX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON4 - QB_MIPI_TX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON4 - QB_MIPI_TX_ON3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON4 & QB_MIPI_TX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON4 - QB_MIPI_TX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON4 - QB_MIPI_TX_ON5 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON4 & QB_MIPI_TX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON4 - QB_MIPI_TX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON4 - QB_MIPI_TX_ON6 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON4 & QB_MIPI_TX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON4 - QB_MIPI_TX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON4 - QB_MIPI_TX_ON7 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON4 & QB_MIPI_TX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON4 - QB_ST0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON4 - QB_ST0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON4 & QB_ST0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON4 - QB_ST1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON4 - QB_ST1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON4 & QB_ST1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON4 - QB_ST2B ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON4 - QB_ST2B ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON4 & QB_ST2B is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif
   
   #if ( QB_MIPI_TX_ON5 != -10000 )
      #if   ( ( ( QB_MIPI_TX_ON5 - QB_MIPI_TX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON5 - QB_MIPI_TX_ON0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON5 & QB_MIPI_TX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON5 - QB_MIPI_TX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON5 - QB_MIPI_TX_ON1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON5 & QB_MIPI_TX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON5 - QB_MIPI_TX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON5 - QB_MIPI_TX_ON2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON5 & QB_MIPI_TX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON5 - QB_MIPI_TX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON5 - QB_MIPI_TX_ON3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON5 & QB_MIPI_TX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON5 - QB_MIPI_TX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON5 - QB_MIPI_TX_ON4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON5 & QB_MIPI_TX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON5 - QB_MIPI_TX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON5 - QB_MIPI_TX_ON6 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON5 & QB_MIPI_TX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON5 - QB_MIPI_TX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON5 - QB_MIPI_TX_ON7 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON5 & QB_MIPI_TX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON5 - QB_ST0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON5 - QB_ST0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON5 & QB_ST0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON5 - QB_ST1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON5 - QB_ST1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON5 & QB_ST1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON5 - QB_ST2B ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON5 - QB_ST2B ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON5 & QB_ST2B is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_MIPI_TX_ON6 != -10000 )
      #if   ( ( ( QB_MIPI_TX_ON6 - QB_MIPI_TX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON6 - QB_MIPI_TX_ON0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON6 & QB_MIPI_TX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON6 - QB_MIPI_TX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON6 - QB_MIPI_TX_ON1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON6 & QB_MIPI_TX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON6 - QB_MIPI_TX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON6 - QB_MIPI_TX_ON2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON6 & QB_MIPI_TX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON6 - QB_MIPI_TX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON6 - QB_MIPI_TX_ON3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON6 & QB_MIPI_TX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON6 - QB_MIPI_TX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON6 - QB_MIPI_TX_ON4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON6 & QB_MIPI_TX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON6 - QB_MIPI_TX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON6 - QB_MIPI_TX_ON5 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON6 & QB_MIPI_TX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON6 - QB_MIPI_TX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON6 - QB_MIPI_TX_ON7 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON6 & QB_MIPI_TX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON6 - QB_ST0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON6 - QB_ST0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON6 & QB_ST0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON6 - QB_ST1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON6 - QB_ST1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON6 & QB_ST1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON6 - QB_ST2B ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON6 - QB_ST2B ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON6 & QB_ST2B is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_MIPI_TX_ON7 != -10000 )
      #if   ( ( ( QB_MIPI_TX_ON7 - QB_MIPI_TX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON7 - QB_MIPI_TX_ON0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON7 & QB_MIPI_TX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON7 - QB_MIPI_TX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON7 - QB_MIPI_TX_ON1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON7 & QB_MIPI_TX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON7 - QB_MIPI_TX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON7 - QB_MIPI_TX_ON2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON7 & QB_MIPI_TX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON7 - QB_MIPI_TX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON7 - QB_MIPI_TX_ON3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON7 & QB_MIPI_TX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON7 - QB_MIPI_TX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON7 - QB_MIPI_TX_ON4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON7 & QB_MIPI_TX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON7 - QB_MIPI_TX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON7 - QB_MIPI_TX_ON5 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON7 & QB_MIPI_TX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON7 - QB_MIPI_TX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON7 - QB_MIPI_TX_ON6 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON7 & QB_MIPI_TX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON7 - QB_ST0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON7 - QB_ST0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON7 & QB_ST0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON7 - QB_ST1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON7 - QB_ST1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON7 & QB_ST1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_ON7 - QB_ST2B ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_ON7 - QB_ST2B ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_ON7 & QB_ST2B is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif
   
   #if ( QB_ST0 != -10000 )
      #if   ( ( ( QB_ST0 - QB_MIPI_TX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST0 - QB_MIPI_TX_ON0 ) >= 0))
#error "The differece between Event Timing QB_ST0 & QB_MIPI_TX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST0 - QB_MIPI_TX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST0 - QB_MIPI_TX_ON1 ) >= 0))
#error "The differece between Event Timing QB_ST0 & QB_MIPI_TX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST0 - QB_MIPI_TX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST0 - QB_MIPI_TX_ON2 ) >= 0))
#error "The differece between Event Timing QB_ST0 & QB_MIPI_TX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST0 - QB_MIPI_TX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST0 - QB_MIPI_TX_ON3 ) >= 0))
#error "The differece between Event Timing QB_ST0 & QB_MIPI_TX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST0 - QB_MIPI_TX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST0 - QB_MIPI_TX_ON4 ) >= 0))
#error "The differece between Event Timing QB_ST0 & QB_MIPI_TX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST0 - QB_MIPI_TX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST0 - QB_MIPI_TX_ON5 ) >= 0))
#error "The differece between Event Timing QB_ST0 & QB_MIPI_TX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST0 - QB_MIPI_TX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST0 - QB_MIPI_TX_ON6 ) >= 0))
#error "The differece between Event Timing QB_ST0 & QB_MIPI_TX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST0 - QB_MIPI_TX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST0 - QB_MIPI_TX_ON7 ) >= 0))
#error "The differece between Event Timing QB_ST0 & QB_MIPI_TX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_ST1 != -10000 )
      #if   ( ( ( QB_ST1 - QB_MIPI_TX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST1 - QB_MIPI_TX_ON0 ) >= 0))
#error "The differece between Event Timing QB_ST1 & QB_MIPI_TX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST1 - QB_MIPI_TX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST1 - QB_MIPI_TX_ON1 ) >= 0))
#error "The differece between Event Timing QB_ST1 & QB_MIPI_TX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST1 - QB_MIPI_TX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST1 - QB_MIPI_TX_ON2 ) >= 0))
#error "The differece between Event Timing QB_ST1 & QB_MIPI_TX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST1 - QB_MIPI_TX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST1 - QB_MIPI_TX_ON3 ) >= 0))
#error "The differece between Event Timing QB_ST1 & QB_MIPI_TX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST1 - QB_MIPI_TX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST1 - QB_MIPI_TX_ON4 ) >= 0))
#error "The differece between Event Timing QB_ST1 & QB_MIPI_TX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST1 - QB_MIPI_TX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST1 - QB_MIPI_TX_ON5 ) >= 0))
#error "The differece between Event Timing QB_ST1 & QB_MIPI_TX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST1 - QB_MIPI_TX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST1 - QB_MIPI_TX_ON6 ) >= 0))
#error "The differece between Event Timing QB_ST1 & QB_MIPI_TX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST1 - QB_MIPI_TX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST1 - QB_MIPI_TX_ON7 ) >= 0))
#error "The differece between Event Timing QB_ST1 & QB_MIPI_TX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      //#elif ( ( ( QB_ST1 - QB_ST2B ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST1 - QB_ST2B ) >= 0))
//#error "The differece between Event Timing QB_ST1 & QB_ST2B is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_ST2B != -10000 )
      #if   ( ( ( QB_ST2B - QB_MIPI_TX_ON0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2B - QB_MIPI_TX_ON0 ) >= 0))
#error "The differece between Event Timing QB_ST2B & QB_MIPI_TX_ON0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST2B - QB_MIPI_TX_ON1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2B - QB_MIPI_TX_ON1 ) >= 0))
#error "The differece between Event Timing QB_ST2B & QB_MIPI_TX_ON1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST2B - QB_MIPI_TX_ON2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2B - QB_MIPI_TX_ON2 ) >= 0))
#error "The differece between Event Timing QB_ST2B & QB_MIPI_TX_ON2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST2B - QB_MIPI_TX_ON3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2B - QB_MIPI_TX_ON3 ) >= 0))
#error "The differece between Event Timing QB_ST2B & QB_MIPI_TX_ON3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST2B - QB_MIPI_TX_ON4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2B - QB_MIPI_TX_ON4 ) >= 0))
#error "The differece between Event Timing QB_ST2B & QB_MIPI_TX_ON4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST2B - QB_MIPI_TX_ON5 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2B - QB_MIPI_TX_ON5 ) >= 0))
#error "The differece between Event Timing QB_ST2B & QB_MIPI_TX_ON5 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST2B - QB_MIPI_TX_ON6 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2B - QB_MIPI_TX_ON6 ) >= 0))
#error "The differece between Event Timing QB_ST2B & QB_MIPI_TX_ON6 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST2B - QB_MIPI_TX_ON7 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2B - QB_MIPI_TX_ON7 ) >= 0))
#error "The differece between Event Timing QB_ST2B & QB_MIPI_TX_ON7 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      //#elif ( ( ( QB_ST2B - QB_ST1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2B - QB_ST1 ) >= 0))
//#error "The differece between Event Timing QB_ST2B & QB_ST1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

//multievent - 5QB  detect TX off
   #if ( QB_MIPI_TX_OFF0 != 10000 )
      #if   ( ( ( QB_MIPI_TX_OFF0 - QB_MIPI_TX_OFF1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF0 - QB_MIPI_TX_OFF1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF0 & QB_MIPI_TX_OFF1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF0 - QB_MIPI_TX_OFF2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF0 - QB_MIPI_TX_OFF2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF0 & QB_MIPI_TX_OFF2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF0 - QB_MIPI_TX_OFF3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF0 - QB_MIPI_TX_OFF3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF0 & QB_MIPI_TX_OFF3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF0 - QB_MIPI_TX_OFF4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF0 - QB_MIPI_TX_OFF4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF0 & QB_MIPI_TX_OFF4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF0 - QB_ST3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF0 - QB_ST3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF0 & QB_ST3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif   

   #if ( QB_MIPI_TX_OFF1 != 10000 )
      #if   ( ( ( QB_MIPI_TX_OFF1 - QB_MIPI_TX_OFF0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF1 - QB_MIPI_TX_OFF0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF1 & QB_MIPI_TX_OFF0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF1 - QB_MIPI_TX_OFF2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF1 - QB_MIPI_TX_OFF2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF1 & QB_MIPI_TX_OFF2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF1 - QB_MIPI_TX_OFF3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF1 - QB_MIPI_TX_OFF3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF1 & QB_MIPI_TX_OFF3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF1 - QB_MIPI_TX_OFF4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF1 - QB_MIPI_TX_OFF4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF1 & QB_MIPI_TX_OFF4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF1 - QB_ST3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF1 - QB_ST3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF1 & QB_ST3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif
   
   #if ( QB_MIPI_TX_OFF2 != 10000 )
      #if   ( ( ( QB_MIPI_TX_OFF2 - QB_MIPI_TX_OFF0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF2 - QB_MIPI_TX_OFF0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF2 & QB_MIPI_TX_OFF0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF2 - QB_MIPI_TX_OFF1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF2 - QB_MIPI_TX_OFF1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF2 & QB_MIPI_TX_OFF1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF2 - QB_MIPI_TX_OFF3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF2 - QB_MIPI_TX_OFF3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF2 & QB_MIPI_TX_OFF3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF2 - QB_MIPI_TX_OFF4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF2 - QB_MIPI_TX_OFF4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF2 & QB_MIPI_TX_OFF4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF2 - QB_ST3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF2 - QB_ST3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF2 & QB_ST3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif
   
   #if ( QB_MIPI_TX_OFF3 != 10000 )
      #if   ( ( ( QB_MIPI_TX_OFF3 - QB_MIPI_TX_OFF0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF3 - QB_MIPI_TX_OFF0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF3 & QB_MIPI_TX_OFF0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF3 - QB_MIPI_TX_OFF1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF3 - QB_MIPI_TX_OFF1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF3 & QB_MIPI_TX_OFF1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF3 - QB_MIPI_TX_OFF2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF3 - QB_MIPI_TX_OFF2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF3 & QB_MIPI_TX_OFF2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF3 - QB_MIPI_TX_OFF4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF3 - QB_MIPI_TX_OFF4 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF3 & QB_MIPI_TX_OFF4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF3 - QB_ST3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF3 - QB_ST3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF3 & QB_ST3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_MIPI_TX_OFF4 != 10000 )
      #if   ( ( ( QB_MIPI_TX_OFF4 - QB_MIPI_TX_OFF0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF4 - QB_MIPI_TX_OFF0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF4 & QB_MIPI_TX_OFF0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF4 - QB_MIPI_TX_OFF1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF4 - QB_MIPI_TX_OFF1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF4 & QB_MIPI_TX_OFF1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF4 - QB_MIPI_TX_OFF2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF4 - QB_MIPI_TX_OFF2 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF4 & QB_MIPI_TX_OFF2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF4 - QB_MIPI_TX_OFF3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF4 - QB_MIPI_TX_OFF3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF4 & QB_MIPI_TX_OFF3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_MIPI_TX_OFF4 - QB_ST3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TX_OFF4 - QB_ST3 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TX_OFF4 & QB_ST3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif

   #if ( QB_ST3 != 10000 )
      #if   ( ( ( QB_ST3 - QB_MIPI_TX_OFF0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST3 - QB_MIPI_TX_OFF0 ) >= 0))
#error "The differece between Event Timing QB_ST3 & QB_MIPI_TX_OFF0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST3 - QB_MIPI_TX_OFF1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST3 - QB_MIPI_TX_OFF1 ) >= 0))
#error "The differece between Event Timing QB_ST3 & QB_MIPI_TX_OFF1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST3 - QB_MIPI_TX_OFF2 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST3 - QB_MIPI_TX_OFF2 ) >= 0))
#error "The differece between Event Timing QB_ST3 & QB_MIPI_TX_OFF2 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST3 - QB_MIPI_TX_OFF3 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST3 - QB_MIPI_TX_OFF3 ) >= 0))
#error "The differece between Event Timing QB_ST3 & QB_MIPI_TX_OFF3 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST3 - QB_MIPI_TX_OFF4 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST3 - QB_MIPI_TX_OFF4 ) >= 0))
#error "The differece between Event Timing QB_ST3 & QB_MIPI_TX_OFF4 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   #endif   

//multievent - 5QB  detect TXMID
   #if   ( ( QB_MIPI_TXMID0 != -10000 ) && ( ( QB_MIPI_TXMID0 - QB_MIPI_TXMID1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TXMID0 - QB_MIPI_TXMID1 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TXMID0 & QB_MIPI_TXMID1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
   #elif ( ( QB_MIPI_TXMID1 != -10000 ) && ( ( QB_MIPI_TXMID1 - QB_MIPI_TXMID0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TXMID1 - QB_MIPI_TXMID0 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TXMID1 & QB_MIPI_TXMID0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
   #endif

   #if ( QB_ST2M_8G!= -10000 )
      #if   ( ( ( QB_ST2M_8G - QB_MIPI_TXMID0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2M_8G - QB_MIPI_TXMID0 ) >= 0))
#error "The differece between Event Timing QB_ST2M_8G & QB_MIPI_TXMID0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST2M_8G - QB_MIPI_TXMID1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2M_8G - QB_MIPI_TXMID1 ) >= 0))
#error "The differece between Event Timing QB_ST2M_8G & QB_MIPI_TXMID1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif  
   #endif

   #if ( QB_ST2M_G8!= -10000 )
      #if   ( ( ( QB_ST2M_G8 - QB_MIPI_TXMID0 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2M_G8 - QB_MIPI_TXMID0 ) >= 0))
#error "The differece between Event Timing QB_ST2M_G8 & QB_MIPI_TXMID0 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( ( QB_ST2M_G8 - QB_MIPI_TXMID1 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2M_G8 - QB_MIPI_TXMID1 ) >= 0))
#error "The differece between Event Timing QB_ST2M_G8 & QB_MIPI_TXMID1 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif   
   #endif
   
   #if IS_MIPI_INTERSLOT_RAMPING_OPTIMIZE_SUPPORT && IS_2G_MIPI_ENABLE
      #if ( (QB_MIPI_TXMID0_GG==(-10000)) || (QB_MIPI_TXMID0_88==(-10000)) || (QB_MIPI_TXMID0_8G==(-10000)) || (QB_MIPI_TXMID0_G8==(-10000)) )
#error "Please define QB_MIPI_TXMID0_GG, QB_MIPI_TXMID0_88, QB_MIPI_TXMID0_8G, QB_MIPI_TXMID0_G8 in l1d_custom_mipi.h"
      #endif
      
      #if   ( ( QB_MIPI_TXMID0_GG != -10000 ) && ( ( QB_MIPI_TXMID0_GG - QB_MIPI_TXMID1_GG ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TXMID0_GG - QB_MIPI_TXMID1_GG ) >= 0))
#error "The differece between Event Timing QB_MIPI_TXMID0_GG & QB_MIPI_TXMID1_GG is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( QB_MIPI_TXMID1_GG != -10000 ) && ( ( QB_MIPI_TXMID1_GG - QB_MIPI_TXMID0_GG ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TXMID1_GG - QB_MIPI_TXMID0_GG ) >= 0))
#error "The differece between Event Timing QB_MIPI_TXMID1_GG & QB_MIPI_TXMID0_GG is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( QB_MIPI_TXMID0_88 != -10000 ) && ( ( QB_MIPI_TXMID0_88 - QB_MIPI_TXMID1_88 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TXMID0_88 - QB_MIPI_TXMID1_88 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TXMID0_88 & QB_MIPI_TXMID1_88 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( QB_MIPI_TXMID1_88 != -10000 ) && ( ( QB_MIPI_TXMID1_88 - QB_MIPI_TXMID0_88 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TXMID1_88 - QB_MIPI_TXMID0_88 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TXMID1_88 & QB_MIPI_TXMID0_88 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( QB_MIPI_TXMID0_8G != -10000 ) && ( ( QB_MIPI_TXMID0_8G - QB_MIPI_TXMID1_8G ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TXMID0_8G - QB_MIPI_TXMID1_8G ) >= 0))
#error "The differece between Event Timing QB_MIPI_TXMID0_8G & QB_MIPI_TXMID1_8G is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( QB_MIPI_TXMID1_8G != -10000 ) && ( ( QB_MIPI_TXMID1_8G - QB_MIPI_TXMID0_8G ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TXMID1_8G - QB_MIPI_TXMID0_8G ) >= 0))
#error "The differece between Event Timing QB_MIPI_TXMID1_8G & QB_MIPI_TXMID0_8G is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( QB_MIPI_TXMID0_G8 != -10000 ) && ( ( QB_MIPI_TXMID0_G8 - QB_MIPI_TXMID1_G8 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TXMID0_G8 - QB_MIPI_TXMID1_G8 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TXMID0_G8 & QB_MIPI_TXMID1_G8 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #elif ( ( QB_MIPI_TXMID1_G8 != -10000 ) && ( ( QB_MIPI_TXMID1_G8 - QB_MIPI_TXMID0_G8 ) <= GGE_MIPI_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_MIPI_TXMID1_G8 - QB_MIPI_TXMID0_G8 ) >= 0))
#error "The differece between Event Timing QB_MIPI_TXMID1_G8 & QB_MIPI_TXMID0_G8 is less than GGE_MIPI_EVNET_TIMING_CHECK_MARGIN"
      #endif
   
      #if ( QB_ST2M_8G!= -10000 )
         #if   ( ( QB_MIPI_TXMID0_GG != -10000 ) && ( ( QB_ST2M_8G - QB_MIPI_TXMID0_GG ) <= GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2M_8G - QB_MIPI_TXMID0_GG ) >= -GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN ))
#error "The differece between Event Timing QB_ST2M_8G & QB_MIPI_TXMID0_GG is less than GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN"
         #elif ( ( QB_MIPI_TXMID1_GG != -10000 ) && ( ( QB_ST2M_8G - QB_MIPI_TXMID1_GG ) <= GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2M_8G - QB_MIPI_TXMID1_GG ) >= -GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN ))
#error "The differece between Event Timing QB_ST2M_8G & QB_MIPI_TXMID1_GG is less than GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN"
         #elif ( ( QB_MIPI_TXMID0_88 != -10000 ) && ( ( QB_ST2M_8G - QB_MIPI_TXMID0_88 ) <= GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2M_8G - QB_MIPI_TXMID0_88 ) >= -GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN ))
#error "The differece between Event Timing QB_ST2M_8G & QB_MIPI_TXMID0_88 is less than GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN"
         #elif ( ( QB_MIPI_TXMID1_88 != -10000 ) && ( ( QB_ST2M_8G - QB_MIPI_TXMID1_88 ) <= GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2M_8G - QB_MIPI_TXMID1_88 ) >= -GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN ))
#error "The differece between Event Timing QB_ST2M_8G & QB_MIPI_TXMID1_88 is less than GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN"
         #elif ( ( QB_MIPI_TXMID0_8G != -10000 ) && ( ( QB_ST2M_8G - QB_MIPI_TXMID0_8G ) <= GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2M_8G - QB_MIPI_TXMID0_8G ) >= -GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN ))
#error "The differece between Event Timing QB_ST2M_8G & QB_MIPI_TXMID0_8G is less than GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN"
         #elif ( ( QB_MIPI_TXMID1_8G != -10000 ) && ( ( QB_ST2M_8G - QB_MIPI_TXMID1_8G ) <= GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2M_8G - QB_MIPI_TXMID1_8G ) >= -GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN ))
#error "The differece between Event Timing QB_ST2M_8G & QB_MIPI_TXMID1_8G is less than GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN"
         #endif  
      #endif
   
      #if ( QB_ST2M_G8!= -10000 )
         #if   ( ( QB_MIPI_TXMID0_G8 != -10000 ) && ( ( QB_ST2M_G8 - QB_MIPI_TXMID0_G8 ) <= GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2M_G8 - QB_MIPI_TXMID0_G8 ) >= -GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN ))
#error "The differece between Event Timing QB_ST2M_G8 & QB_MIPI_TXMID0_G8 is less than GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN"
         #elif ( ( QB_MIPI_TXMID1_G8 != -10000 ) && ( ( QB_ST2M_G8 - QB_MIPI_TXMID1_G8 ) <= GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN ) && ( ( QB_ST2M_G8 - QB_MIPI_TXMID1_G8 ) >= -GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN ))
#error "The differece between Event Timing QB_ST2M_G8 & QB_MIPI_TXMID1_G8 is less than GGE_MIPI_TXMID_EVNET_TIMING_CHECK_MARGIN"
         #endif   
      #endif      
   #endif

const volatile unsigned short* GGE_MIPI_RTX_REG_TABLE[GGE_MIPI_RTX_EVENT_COUNT][GGE_MIPI_RTX_EVENT_NUM] =
{
   {/*              CWIN0            */
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(0, 0) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(0, 1) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(0, 2) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(0, 3) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(0, 4) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(0, 5) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(0, 6) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(0, 7) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(0, 8) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(0, 9) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(0,10) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(0,11) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(0,12) ),
   },
   {/*              CWIN1            */
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(1, 0) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(1, 1) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(1, 2) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(1, 3) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(1, 4) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(1, 5) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(1, 6) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(1, 7) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(1, 8) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(1, 9) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(1,10) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(1,11) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(1,12) ),
   },
   {/*              CWIN2            */
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(2, 0) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(2, 1) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(2, 2) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(2, 3) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(2, 4) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(2, 5) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(2, 6) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(2, 7) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(2, 8) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(2, 9) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(2,10) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(2,11) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(2,12) ),
   },
   {/*              CWIN3            */
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(3, 0) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(3, 1) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(3, 2) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(3, 3) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(3, 4) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(3, 5) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(3, 6) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(3, 7) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(3, 8) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(3, 9) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(3,10) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(3,11) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(3,12) ),
   },
   {/*              CWIN4            */
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(4, 0) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(4, 1) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(4, 2) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(4, 3) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(4, 4) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(4, 5) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(4, 6) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(4, 7) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(4, 8) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(4, 9) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(4,10) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(4,11) ),
      TDMA_BSI( GGE_MIPI_RTX_EVIDX(4,12) ),
   },
};

const volatile unsigned short* GGE_MIPI_TXMID_REG_TABLE[GGE_MIPI_TXMID_EVENT_COUNT][GGE_MIPI_TXMID_EVENT_NUM] =
{
   {/*               XWIN0            */
      TDMA_BSI( GGE_MIPI_TXMID_EVIDX(0, 0) ),
      TDMA_BSI( GGE_MIPI_TXMID_EVIDX(0, 1) ),
   },
   {/*               XWIN1           */
      TDMA_BSI( GGE_MIPI_TXMID_EVIDX(1, 0) ),
      TDMA_BSI( GGE_MIPI_TXMID_EVIDX(1, 1) ),
   },
   {/*               XWIN2            */
      TDMA_BSI( GGE_MIPI_TXMID_EVIDX(2, 0) ),
      TDMA_BSI( GGE_MIPI_TXMID_EVIDX(2, 1) ),
   },
   {/*               XWIN3            */
      TDMA_BSI( GGE_MIPI_TXMID_EVIDX(3, 0) ),
      TDMA_BSI( GGE_MIPI_TXMID_EVIDX(3, 1) ),
   },
};

#endif /* IS_MIPI_SUPPORT */

/*===============================================================================================*/

