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
 *    drv_features_rtc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for the rtc driver features
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __DRV_FEATURES_RTC_H__
#define __DRV_FEATURES_RTC_H__

/**************** RTC ******************/
#include "drv_features_chip_select.h"

#if defined(DRV_RTC_6205_SERIES)
   #define DRV_RTC_PWRON_BBPU_POLARITY
   #define DRV_RTC_NO_REG_COMM
   #define DRV_RTC_NO_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6205
#elif defined(DRV_RTC_6208_SERIES)
   #define DRV_RTC_PWRON_BBPU_POLARITY
   #define DRV_RTC_NO_REG_COMM
   #define DRV_RTC_NO_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6208
#elif defined(DRV_RTC_6205B_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_INFO_MASK
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_WRITE_ENABLE
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6205B
#elif defined(DRV_RTC_6217_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_WRITE_ENABLE
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6205B
#elif defined(DRV_RTC_6218_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6218
#elif defined(DRV_RTC_6218B_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_WRITE_ENABLE
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6205B
#elif defined(DRV_RTC_6226_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_W_FLAG
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_WRITE_ENABLE
   #define DRV_RTC_TC_BUSY_CHECK
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_COMM_REG1_SECURITY
   #define DRV_RTC_BBPU_AS_6205B
#elif defined(DRV_RTC_6228_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_W_FLAG
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_WRITE_ENABLE
   #define DRV_RTC_TC_BUSY_CHECK
   #define DRV_RTC_POWERKEY_BUSY_CHECK
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6205B
   #define DRV_RTC_XOSC_DEF_8
#elif defined(DRV_RTC_6235_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_WRITE_ENABLE
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6238
   #define DRV_RTC_XOSC_DEF_8
   #define DRV_RTC_HW_CALI
   #define DRV_RTC_DBING
   #define DRV_RTC_SHORTER_CBUSY_POLLING
#elif defined(DRV_RTC_6238_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_WRITE_ENABLE
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6238
   #define DRV_RTC_XOSC_DEF_8
   #define DRV_RTC_HW_CALI
   #define DRV_RTC_SHORTER_CBUSY_POLLING
#elif defined(DRV_RTC_6253_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_WRITE_ENABLE
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6238
   #define DRV_RTC_XOSC_DEF_10
   #define DRV_RTC_HW_CALI
   #define DRV_RTC_DBING
   #define DRV_RTC_PROTECT1
   #define DRV_RTC_PROTECT2
   //#define DRV_RTC_LOCK_PROTECT
#elif defined(DRV_RTC_6251_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6276
   #define DRV_RTC_XOSC_UPDATE   
   #define DRV_RTC_XOSC_DEF_7
   #define DRV_RTC_HW_CALI
   #define DRV_RTC_PROTECT1
   #define DRV_RTC_PROTECT2
   #define DRV_RTC_LOW_POWER_DETECT
   #define DRV_RTC_PDN_EXTEND
   #define DRV_RTC_GPIO
#elif defined(DRV_RTC_6268_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_WRITE_ENABLE
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6238
   #define DRV_RTC_XOSC_DEF_D
   #define DRV_RTC_HW_CALI
   #define DRV_RTC_DBING
   #define DRV_RTC_PROTECT2
   //#define DRV_RTC_LOCK_PROTECT
#elif defined(DRV_RTC_6236_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_WRITE_ENABLE
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6238
   #define DRV_RTC_XOSC_DEF_0
   #define DRV_RTC_HW_CALI
   #define DRV_RTC_DBING
   #define DRV_RTC_PROTECT2
   #define DRV_RTC_NOT_EMPTY_TRIGGER
#elif defined(DRV_RTC_6276_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6276
   #define DRV_RTC_XOSC_UPDATE   
   #define DRV_RTC_XOSC_DEF_10F
   #define DRV_RTC_HW_CALI
   #define DRV_RTC_PROTECT1
   #define DRV_RTC_PROTECT2
   #define DRV_RTC_LOW_POWER_DETECT
   #define DRV_RTC_PDN_EXTEND
   #define DRV_RTC_GPIO
   #define DRV_RTC_REG_SPAR
#elif defined(DRV_RTC_6256_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6276
   #define DRV_RTC_XOSC_UPDATE   
   #define DRV_RTC_XOSC_DEF_10F
   #define DRV_RTC_HW_CALI
   #define DRV_RTC_PROTECT1
   #define DRV_RTC_PROTECT2
   #define DRV_RTC_LOW_POWER_DETECT
   #define DRV_RTC_PDN_EXTEND
   #define DRV_RTC_GPIO
   #define DRV_RTC_REG_SPAR   
#elif defined(DRV_RTC_6255_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6276
   #define DRV_RTC_XOSC_UPDATE   
   #define DRV_RTC_XOSC_DEF_10F
   #define DRV_RTC_HW_CALI
   #define DRV_RTC_PROTECT1
   #define DRV_RTC_PROTECT2
   #define DRV_RTC_LOW_POWER_DETECT
   #define DRV_RTC_PDN_EXTEND
   #define DRV_RTC_GPIO
   #define DRV_RTC_REG_SPAR    
   #define DRV_RTC_INTERNAL_32K_AS_6255
   #define DRV_RTC_INTERNAL_32K_SWITCH_FAIL_DETECT
#elif defined(DRV_RTC_6250_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6276
   #define DRV_RTC_XOSC_UPDATE   
   #define DRV_RTC_XOSC_DEF_F
   #define DRV_RTC_HW_CALI
   #define DRV_RTC_PROTECT1
   #define DRV_RTC_PROTECT2
   #define DRV_RTC_LOW_POWER_DETECT
   #define DRV_RTC_PDN_EXTEND
   #define DRV_RTC_GPIO
   #define DRV_RTC_REG_SPAR    
   #define DRV_RTC_INTERNAL_32K_AS_6255
#elif defined(DRV_RTC_6573_SERIES)
   #define DRV_RTC_REG_COMM
   #define DRV_RTC_CII_HALF_SEC
   #define DRV_RTC_PWRON_BBPU_SW
   #define DRV_RTC_INIT_POLL
   #define DRV_RTC_LATCH_PWR_POLL
   #define DRV_RTC_BBPU_AS_6276
   #define DRV_RTC_XOSC_UPDATE
   #define DRV_RTC_XOSC_DEF_7
   #define DRV_RTC_HW_CALI
   #define DRV_RTC_PROTECT1
   #define DRV_RTC_PROTECT2
   #define DRV_RTC_LOW_POWER_DETECT
   #define DRV_RTC_PDN_EXTEND
   #define DRV_RTC_GPIO   
   #define DRV_RTC_32K_BETTER_QUALITY
   
#endif
// Sleep mode lockedup issue workaround
// The chip list which have the sleep mode locked up issue:
// MT6205, MT6217, MT6218, MT6219, MT6227, MT6227D, MT6228, MT6229, MT6230
// Just use chip list to decide the DRV_XXX feature
#if ( (defined(MT6205)) || (defined(MT6217)) || (defined(MT6218)) || (defined(MT6219)) || (defined(MT6227)) || (defined(MT6227D)) || (defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)) )
#define DRV_RTC_SLEEP_LOCKED_UP_WA		// The sleep mode locked up issue workaround (Implemented in RTC driver)
#endif // #if ( (defined(MT6205)) || (defined(MT6217)) || (defined(MT6218)) || (defined(MT6219)) || (defined(MT6227)) || (defined(MT6227D)) || (defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)) )

#if !defined(DRV_RTC_NOT_EXIST)
#define DCL_RTC_INTERFACE
#endif

#endif /*End __DRV_FEATURES_RTC_H__*/
