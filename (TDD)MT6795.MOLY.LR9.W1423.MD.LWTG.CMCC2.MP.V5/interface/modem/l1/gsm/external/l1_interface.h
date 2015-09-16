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
 *   l1_interface.h
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 *   Interface for system service.
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:     $
 * $Modtime:      $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/interface/l1interface/l1_interface.h-arc  $
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
 * 06 24 2013 sy.yeh
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 * 
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
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
 * Let L1D_FH_FM_TurnOn()/L1D_FH_FM_SetFreq() always as function
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Update HW_tdma_auxev_time_setup() as macro
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Add declaration of HW_wait_32k_start
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *******************************************************************************/

#ifndef  _L1_INTERFACE_H_
#define  _L1_INTERFACE_H_
/* ------------------------------------------------------------------------- */

#include "kal_general_types.h"

#if (defined L1_SIM) || (defined MT6268T) || (defined __UE_SIMULATOR__)
#include "tool.h"
#else
#define  HW_WRITE(ptr,data)         (*(ptr) = (data))
#define  HW_READ(ptr)               (*(ptr))
#define  LET_SIM_TIME_RUN_A_BIT()
#endif

extern kal_uint16    L1_ASSERT_BYPASS;
extern kal_uint16    L1D_MD2G_SLEEP_STATUS( void );
extern void          L1D_INFORM_DSP_WAKEUP( void );
extern void          L1D_INFORM_DSP_REENTER_SLEEP( void );
extern void          L1D_HW_TDMA_AUX_TIME_SETUP( kal_uint16 event0, kal_uint16 event1 );
extern kal_uint16    L1D_TDMA_GET_TQCNT( void );
extern kal_uint16    L1D_HW_TDMA_GET_TQWRAP( void );
extern kal_uint32    L1D_HW_TDMA_GET_32KCNT( void );
extern void          L1D_INFORM_DCXO_WAKEUP( void );
extern void          L1D_PMU_FIX_VRF1828SETTING( unsigned char is_fixed ); /* workaround for BT EVM performace due to VRF18/28 change */
extern kal_bool      MML1_RF_REPORT_CALDATA_DOWNLOAD_STATUS( void );
extern char          L1D_INFORM_WIFI_DEGRADE_POWER( void ); /* workaround for low GSM RX performace due to large wifi TX power. */
extern unsigned char L1D_Get_RX_Status( void );
extern unsigned char L1D_Get_BandCapability( void );

/*************************************************************************
 * API provided for other modules
 *************************************************************************/

#if (defined L1_NOT_PRESENT)
#define  L1_CHECK_ASSERT_BYPASS()           (0)
#define  MD2G_SLEEP_STATUS()                (1)
#define  INFORM_DSP_WAKEUP()                {}
#define  INFORM_DSP_REENTER_SLEEP()         {}
#define  L1D_DCXO_WAKEUP()                  {}
#define  L1D_FIX_VRF1828SETTING( is_fixed ) {}
#define  INFORM_WIFI_DEGRADE_POWER()        (0)
#define  L1D_GET_GGE_RX_STATUS()            (0)
#else
#define  L1_CHECK_ASSERT_BYPASS()           (L1_ASSERT_BYPASS & 0x3)
#define  MD2G_SLEEP_STATUS()                L1D_MD2G_SLEEP_STATUS()
#define  INFORM_DSP_WAKEUP()                L1D_INFORM_DSP_WAKEUP()
#define  INFORM_DSP_REENTER_SLEEP()         L1D_INFORM_DSP_REENTER_SLEEP()
#define  L1D_DCXO_WAKEUP()                  L1D_INFORM_DCXO_WAKEUP()
#define  L1D_FIX_VRF1828SETTING( is_fixed ) L1D_PMU_FIX_VRF1828SETTING( is_fixed )
#define  INFORM_WIFI_DEGRADE_POWER()        L1D_INFORM_WIFI_DEGRADE_POWER()
#define  L1D_GET_GGE_RX_STATUS()            L1D_Get_RX_Status()
#endif

#if (defined __MTK_TARGET__)
#define  L1D_REPORT_CALDATA_DOWNLOAD_STATUS()   MML1_RF_REPORT_CALDATA_DOWNLOAD_STATUS()
#else
#define  L1D_REPORT_CALDATA_DOWNLOAD_STATUS()   (1)
#endif

void  HW_TDMA_Start(void);         /* power on TDMA module               */
void  HW_TDMA_Enable_CTIRQ1(void); /* enable TDMA module CTIRQ1          */
void  HW_wait_32k_start(void);     /* use 13M/26M to calibrate 32k clock */

#define  HW_tdma_auxev_time_setup(event0,event1)  L1D_HW_TDMA_AUX_TIME_SETUP(event0, event1)

#define  HW_TDMA_GET_TQCNT()        L1D_TDMA_GET_TQCNT()
#define  HW_TDMA_GET_TQWRAP()       L1D_HW_TDMA_GET_TQWRAP()
#define  HW_TDMA_GET_32KCNT()       L1D_HW_TDMA_GET_32KCNT()

extern unsigned char L1D_IS_MT6162_DCXO( void );

/* APIs for audio */
extern kal_uint16 L1D_Get_Win_TQ_WRAP( void );
extern kal_int8   L1D_GetT2( void );
extern void       L1D_ENABLE_DTIRQ( void );
extern void       L1D_CCCDReset( void );
extern kal_bool   L1D_Get_Speech_Re_Sync_Flag( void );
/* ------------------------------------------------------------------------- */

extern void MD_DRV_L1D_Exit( void );
/* ------------------------------------------------------------------------- */

#if MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572 || MD_DRV_IS_CHIP_MT6290 || MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1 || MD_DRV_IS_CHIP_MT6752_MD2
   #if IS_DUAL_TALK_SUPPORT
#define L1D_WAKEUP_MARGIN                   (1300)
   #else
#define L1D_WAKEUP_MARGIN                   (1050)
   #endif
#define L1C_WAKEUP_MARGIN                   (660)
#endif
/* ------------------------------------------------------------------------- */
#if defined(ESIM_BUILD_CONFIG) && (ESIM_BUILD_CONFIG == ESIM_MULTI_MODE_ON_FIBERS)
#define L1D_WAKEUP_MARGIN                   (1050)
#define L1C_WAKEUP_MARGIN                   (660)
#endif
/* ------------------------------------------------------------------------- */
#endif

