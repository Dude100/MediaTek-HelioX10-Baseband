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
 * hal_ul1_struct.h
 *
 * Project:
 * --------
 *   WCDMA_Software
 *
 * Description:
 * ------------
 *   Layer 1 and Protocol Stack message and callback function definition for MMI/Middleware
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _HAL_UL1_STRUCT_H
#define _HAL_UL1_STRUCT_H

#include "hal_ul1_def.h"
#include "kal_public_api.h"

#if defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__)
/* __GPS_FRAME_SYNC_SUPPORT__ */
/*****************************************************************************
Request from GPS Task
*****************************************************************************/
typedef struct _ul1_gps_time_sync_req_struct
{
   LOCAL_PARA_HDR

   ul1_agps_frame_sync_app_E     application_type; 
   
   kal_bool                      maintain_phase;     /* This flag is only useful when FRAME_TIME_AIDING_APP (Type3).
                                                      FALSE: The type3 request is aiding phase, and must check if timing is not accurate. 
                                                      TRUE: The type3 request is maintain phase, and do not check if timing is not accurate. */

   /* When application_type is FRAME_TIME_AIDING_APP, uarfcn and psc are unused. */
   kal_uint16                    uarfcn;  
   kal_uint16                    psc;              /* Primary scrambling code */   
} ul1_gps_time_sync_req_struct;

/*****************************************************************************
Confirm and indication to GPS Task
*****************************************************************************/
typedef struct _ul1_gps_time_sync_ind_struct
{
   LOCAL_PARA_HDR

   ul1_agps_frame_sync_app_E           application_type; 
   ul1_agps_frame_sync_fail_reason_E   fail_reason;

   /* result_valid, sfn adn echip are useful only when 
      application_type in CPHY_GPS_TIME_SYNC_REQ is not FRAME_TIME_AIDING_APP. */
   kal_bool          result_valid;
   kal_uint16        sfn;              /* sfn is valid only when result_valid is true. */
   kal_uint32        echip;            /* echip is valid only when result_valid is true. */
   
   kal_bool          local_time_valid;
   kal_uint64        local_time;       /* uint=1/104 us. 
                                          local_time is valid only when local_time_valid is true. */
} ul1_gps_time_sync_ind_struct;

#endif

/* ============================== Maintained by UL1D ==============================*/
typedef enum
{
   FDD_HSDPA_OFF,
   FDD_HSDPA_PHY_CAT1,
   FDD_HSDPA_PHY_CAT2,
   FDD_HSDPA_PHY_CAT3,
   FDD_HSDPA_PHY_CAT4,
   FDD_HSDPA_PHY_CAT5,
   FDD_HSDPA_PHY_CAT6,
   FDD_HSDPA_PHY_CAT7,
   FDD_HSDPA_PHY_CAT8,
   FDD_HSDPA_PHY_CAT9,
   FDD_HSDPA_PHY_CAT10,
   FDD_HSDPA_PHY_CAT11,
   FDD_HSDPA_PHY_CAT12,
#if defined(__UMTS_R8__)
   FDD_HSDPA_PHY_CAT13,   
   FDD_HSDPA_PHY_CAT14,   
   FDD_HSDPA_PHY_CAT15,
   FDD_HSDPA_PHY_CAT16,
   FDD_HSDPA_PHY_CAT17,
   FDD_HSDPA_PHY_CAT18,   
   FDD_HSDPA_PHY_CAT19,
   FDD_HSDPA_PHY_CAT20,
   FDD_HSDPA_PHY_CAT21,
   FDD_HSDPA_PHY_CAT22,
   FDD_HSDPA_PHY_CAT23,   
   FDD_HSDPA_PHY_CAT24  
#endif    
} FDD_HSDPA_CATEGORY_E;

typedef enum
{
   FDD_HSUPA_OFF,
   FDD_HSUPA_PHY_CAT1,
   FDD_HSUPA_PHY_CAT2,
   FDD_HSUPA_PHY_CAT3,
   FDD_HSUPA_PHY_CAT4,
   FDD_HSUPA_PHY_CAT5,
   FDD_HSUPA_PHY_CAT6,
   FDD_HSUPA_PHY_CAT7
} FDD_HSUPA_CATEGORY_E;

/* =================================================
API for querying the supported Cat. of target chip

hsdpa_cat: HSDPA PHY supported Cat.
hsupa_cat: HSUPA PHY supported Cat.

Return: Indicate whether the obtained HSDPA/HSUPA
        category is valid or not
===================================================*/
extern kal_bool UL1D_Get_FDD_HSPA_Phy_Category( FDD_HSDPA_CATEGORY_E *hsdpa_cat,
                                                FDD_HSUPA_CATEGORY_E *hsupa_cat);
extern kal_bool UL1D_Get_FDD_HSPA_Phy_Category_Extension( FDD_HSDPA_CATEGORY_E *hsdpa_cat,
                                         FDD_HSUPA_CATEGORY_E *hsupa_cat );
extern kal_bool UL1D_Get_FDD_HSPA_Phy_Category_Extension_2( FDD_HSDPA_CATEGORY_E *hsdpa_cat,
                                         FDD_HSUPA_CATEGORY_E *hsupa_cat );
extern kal_bool UL1_IS_3G_FDD_EXIST(void);
extern void UL1D_UeBandCapability(kal_uint16 *ue_cap);
/* ============================== Maintained by UL1D ==============================*/

/* =================================================
API for 3G USB LOGGING for HAL Rules
===================================================*/
#ifdef __MODEM_3G_LOGGING__
extern kal_uint16 USB_LOGGING_Get_3G_Status_HAL(kal_uint32 buf_index);
extern void USB_LOGGING_3G_Reset_HAL(void);
extern void USB_LOGGING_3G_Restart_HAL(void);
extern void USB_LOGGING_3G_Init_HAL(kal_uint8* add1, kal_uint8* add2, kal_uint8* add3, kal_uint8* add4);
extern void USB_LOGGING_3G_Start_HAL(void);
extern void USB_LOGGING_3G_Stop_HAL(void);
extern void USB_LOGGING_3G_LISR_HAL(void);
extern void USB_LOGGING_3G_Drv_Create_ISR_HAL(void);
extern void USB_LOGGING_3G_Clear_Buffer_HAL(kal_uint8 buf_idx, kal_uint8 idx);
#endif
/* ============================== Maintained by UL1D ==============================*/

#endif   /*_HAL_UL1_STRUCT_H*/

