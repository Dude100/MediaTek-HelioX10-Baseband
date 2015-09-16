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
 *   sleepdrv_interface.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for the public access for sleep mode operation.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 	.
 * 	Add 99T 32K period while OST struggle in SETTLE state
 *
 * removed!
 * removed!
 * Integration change.
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * Low Power Feature patch back from CBr
 *
 * removed!
 * reorg. header file.
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#ifndef __SLEEPDRV_INTERFACE_H__
#define __SLEEPDRV_INTERFACE_H__

#include "kal_public_api.h" //MSBB change #include "kal_release.h"

#if defined(__SMART_PHONE_MODEM__) && defined(__MODEM_CCCI_EXIST__) && defined(__HIF_SDIO_SUPPORT__)
#define PHONE_TYPE_FOR_HQA
#endif

kal_uint8 SleepDrv_GetHandle( void );
void SleepDrv_SleepDisable( kal_uint8 handleCount );
void SleepDrv_SleepEnable( kal_uint8 handleCount );

/* Enable FRC API for exception handling */
extern void MD_TOPSM_EnableFRC(void);

#include "reg_base.h"
#if defined(MT6290)
extern volatile kal_uint32 ostd_patch_us_timer_period;
#define GET_TOPSM_FRC_VAL_R()             (*(volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0x88)+ostd_patch_us_timer_period)
#define GET_TOPSM_FRC_SYNC_VAL_2G_US()    (*(volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0x90)+ostd_patch_us_timer_period)
#define GET_TOPSM_FRC_SYNC_VAL_2G_26M()   (*(volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0x94))
#define GET_TOPSM_FRC_SYNC_VAL_3G_US()    (*(volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0x98)+ostd_patch_us_timer_period)
#define GET_TOPSM_FRC_SYNC_VAL_3G_26M()   (*(volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0x9C))
#define GET_TOPSM_FRC_SYNC_VAL_TDD_US()   (*(volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0xA0)+ostd_patch_us_timer_period)
#define GET_TOPSM_FRC_SYNC_VAL_TDD_26M()  (*(volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0xA4))
#define SET_GPS_SYNC_TIME(_val)           (*(volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0xC4))=(_val - ostd_patch_us_timer_period)
#else /*not MT6290*/
#define GET_TOPSM_FRC_VAL_R()             (*(volatile kal_uint32 *)(MD_TOPSM_BASE+0x88))
#define GET_TOPSM_FRC_SYNC_VAL_2G_US()    (*(volatile kal_uint32 *)(MD_TOPSM_BASE+0x94))
#define GET_TOPSM_FRC_SYNC_VAL_2G_26M()   (*(volatile kal_uint32 *)(MD_TOPSM_BASE+0x90))
#define GET_TOPSM_FRC_SYNC_VAL_3G_US()    (*(volatile kal_uint32 *)(MD_TOPSM_BASE+0x9C))
#define GET_TOPSM_FRC_SYNC_VAL_3G_26M()   (*(volatile kal_uint32 *)(MD_TOPSM_BASE+0x98))
#define GET_TOPSM_FRC_SYNC_VAL_TDD_US()   (*(volatile kal_uint32 *)(MD_TOPSM_BASE+0x9C))
#define GET_TOPSM_FRC_SYNC_VAL_TDD_26M()  (*(volatile kal_uint32 *)(MD_TOPSM_BASE+0x98))
#define SET_GPS_SYNC_TIME(_val)           (*(volatile kal_uint32 *)(MD_TOPSM_BASE+0x300))=(_val)

#endif /*MT6290*/

#endif
