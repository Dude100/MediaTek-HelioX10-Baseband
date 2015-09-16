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
 *    drv_features_bmt.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for the BMT driver features
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
 
#ifndef __DRV_FEATURES_BMT_H__
#define __DRV_FEATURES_BMT_H__

/**************** BMT ******************/
#include "drv_features_chip_select.h"

#if defined(DRV_BMT_6205_SERIES)
   
#elif defined(DRV_BMT_6205B_SERIES)
   
#elif defined(DRV_BMT_6208_SERIES)
   
#elif defined(DRV_BMT_6217_SERIES)
   
#elif defined(DRV_BMT_6218B_SERIES)
   
#elif defined(DRV_BMT_6225_SERIES)
   
#elif defined(DRV_BMT_6226_SERIES)
   
#elif defined(DRV_BMT_6228_SERIES)
    
#elif defined(DRV_BMT_6229_SERIES)
    
#elif defined(DRV_BMT_6223_SERIES)
   
#elif defined(DRV_BMT_6235_SERIES)

#elif defined(DRV_BMT_6238_SERIES)

#elif defined(DRV_BMT_6268_SERIES)
#define __DRV_BMT_ULTRA_LOW_COST_CHARGER__

#elif defined(DRV_BMT_6253_SERIES)
#define __DRV_BMT_ULTRA_LOW_COST_CHARGER__

#elif defined(DRV_BMT_MT6516_AP_SERIES)

#elif defined(DRV_BMT_6236_SERIES)
#define DRV_BMT_PULSE_CHARGING
#define __DRV_BMT_ULTRA_LOW_COST_CHARGER__

#elif defined(DRV_BMT_6255_SERIES)
#ifdef DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT
	#define DRV_BMT_PULSE_CV_CHARGING
	#define __DRV_BMT_ULTRA_LOW_COST_CHARGER__
#else
	#define DRV_BMT_PULSE_CV_CHARGING
#endif //#ifdef DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT
#define __DRV_BMT_ISENSE_OFFSET_COMPENSATION__

#elif defined(DRV_BMT_6256_SERIES)
#define __BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY__
#ifdef DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT
	#define DRV_BMT_PULSE_CV_CHARGING
	#define __DRV_BMT_ULTRA_LOW_COST_CHARGER__
#else
	#define DRV_BMT_PULSE_CV_CHARGING
#endif //#ifdef DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT
#define __DRV_BMT_ISENSE_OFFSET_COMPENSATION__

#elif defined(DRV_BMT_6276_SERIES)
#define DRV_BMT_PULSE_CHARGING
#define DRV_BMT_HW_PRECC_WORKAROUND
#define __DRV_BMT_ULTRA_LOW_COST_CHARGER__
#define __DRV_BMT_BATTERY_LARGER_1600MA__
#define DRV_BMT_BOOTING_DELAY_EXTEND

#elif defined(DRV_BMT_6251_SERIES)
#define DRV_BMT_PULSE_CHARGING
#define __DRV_BMT_ULTRA_LOW_COST_CHARGER__

#elif defined(DRV_BMT_6252_SERIES)
#define DRV_BMT_PULSE_CHARGING
#define __DRV_BMT_ULTRA_LOW_COST_CHARGER__

#elif defined(DRV_BMT_6253EL_SERIES)
#define DRV_BMT_PULSE_CHARGING
#define __DRV_BMT_ULTRA_LOW_COST_CHARGER__

#elif defined(DRV_BMT_6573_SERIES)
#define DRV_BMT_PULSE_CHARGING
#define __DRV_BMT_ULTRA_LOW_COST_CHARGER__

#elif defined(DRV_BMT_6250_SERIES)
#ifdef DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT
	#define __BMT_ON_STATE_CHECK__
#endif 

#elif defined(DRV_BMT_6280_SERIES)

#elif defined(DRV_BMT_6583_SERIES)

#elif defined(DRV_BMT_NOT_EXIST)

#endif // BMT series

#define DCL_BMT_INTERFACE

#endif /*End __DRV_FEATURES_BMT_H__*/
