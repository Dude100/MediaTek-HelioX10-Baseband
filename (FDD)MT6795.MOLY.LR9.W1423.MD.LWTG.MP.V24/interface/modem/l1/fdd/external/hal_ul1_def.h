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
 * hal_ul1_def.h
 *
 * Project:
 * --------
 *   WCDMA_Software
 *
 * Description:
 * ------------
 *   This file contains common typedef, definition prototypes exported by L1 for MMI/Middleware
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef _HAL_UL1_DEF_H
#define _HAL_UL1_DEF_H

#if defined (__UMTS_FDD_MODE__)
#define UMTS_FDD_QUERY_UE_BAND_CAPABILITY(ADDR) UL1D_UeBandCapability(ADDR)
#else
#define UMTS_FDD_QUERY_UE_BAND_CAPABILITY(ADDR)
#endif

#ifdef __MODEM_3G_LOGGING__   // Modified to meet HAL requirement
#define USB_LOGGING_Get_3G_Status(buf_index)            USB_LOGGING_Get_3G_Status_HAL(buf_index)
#define USB_LOGGING_3G_Reset()                          USB_LOGGING_3G_Reset_HAL()
#define USB_LOGGING_3G_Restart()                        USB_LOGGING_3G_Restart_HAL()
#define USB_LOGGING_3G_Init(add1, add2, add3, add4)     USB_LOGGING_3G_Init_HAL(add1, add2, add3, add4)
#define USB_LOGGING_3G_Start()                          USB_LOGGING_3G_Start_HAL()
#define USB_LOGGING_3G_Stop()                           USB_LOGGING_3G_Stop_HAL()
#define USB_LOGGING_3G_LISR()                           USB_LOGGING_3G_LISR_HAL()
#define USB_LOGGING_3G_Drv_Create_ISR()                 USB_LOGGING_3G_Drv_Create_ISR_HAL()
#define USB_LOGGING_3G_Clear_Buffer(buf_idx,idx)        USB_LOGGING_3G_Clear_Buffer_HAL(buf_idx,idx)
#endif

#define UL1D_EXIT()                                     //Null function

#define RF_GET_CAL_DATA_ARRAY_BAND_IDX(BAND, NVRAM_INIT) UL1D_RF_CalDataGetBand(BAND, NVRAM_INIT)

#if defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__)
/* __GPS_FRAME_SYNC_SUPPORT__ */
/*-------------- A-GPS Related ----------------*/
typedef enum _ul1_agps_frame_sync_app_E
{
   UL1_AGPS_APP_FINE_TIME_ASSISTANCE = 0,
   UL1_AGPS_APP_EVENT7C_PERIODIC,
   UL1_AGPS_APP_FRAME_TIME_AIDING,
   UL1_AGPS_APP_END
} ul1_agps_frame_sync_app_E;

typedef enum _ul1_agps_frame_sync_fail_reason_E
{
   UL1_AGPS_FAIL_NO_FAILURE = 0,       /* No failure. */
   UL1_AGPS_FAIL_3G_NOT_ACTIVE,        /* 3G is not active. */
   UL1_AGPS_FAIL_NO_SERVING_CELL,      /* This fail reason means there is no serving cell. */
   UL1_AGPS_FAIL_CELL_NOT_FOUND,       /* Only for Type1/2, the fail reason means the cell indicated from the request is not in current BA list.*/
   UL1_AGPS_FAIL_TIMING_NOT_ACCURATE,  /* Timing result is not accurate due to some specific scenario. */
   UL1_AGPS_FAIL_LCT_IN_OTHER_RAT,     /* The fail reason is set by UL1D to indicate that LCT is currently controlled by other RAT. */
   UL1_AGPS_FAIL_END
} ul1_agps_frame_sync_fail_reason_E;
#endif

#endif
