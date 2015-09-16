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
 * Filename:
 * ---------
 * custom_nvram_config.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   The file contains nvram configuration default value.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef CUSTOM_NVRAM_INT_CONFIG_H
#define CUSTOM_NVRAM_INT_CONFIG_H

#include "kal_general_types.h"
#include "nvram_config.h"
#include "nvram_enums.h"
#include "nvram_defs.h"

#define __LOCKED__ 0
#define __UNLOCKED__ 1

//***************************************************************************
// max size for vendor is 100k
//***************************************************************************/
#ifdef __FLAVOR_VENDOR_SDK__
#define __NVRAM_VENDOR_SUPPORT__
#define NVRAM_MAX_VENDOR_LID_SIZE (100 * 1024)
#endif

//***************************************************************************
//  IMPORTANT!!
//  This value CANNOT be modified by customer.
//  This is the sector size on flash
//***************************************************************************
#define NVRAM_RECORD_SECTOR_SIZE (512)

//***************************************************************************
//  This value define the max record size in NVRAM,
//  The unit is sector, and each sector size is 512 bytes
//
//  We use this value to decide the maximum record size which
//  CANNOT be bigger than the biggest control buffer size
//  (normally is 2K, on WCDMA project is 8K)
//
//  We also reserve 2 * N + 1 sectors in FDM, in order to support PROTECTION_MODE_WRITE
//  Please define this value carefully, bigger value you set,
//  FAT size smaller
//***************************************************************************
#ifndef NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM
    #if defined(__LTE_RAT__)
        #define NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM    (128)
    #elif defined(__MA_L1__) || defined(__UMTS_RAT__)
        #define NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM    (16)
    #elif defined(__DHL_MODULE__)
        #define NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM    (8)
    #else
        #define NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM    (4)
    #endif
#endif

//***************************************************************************
//  Note:
//  Please do not motify this macro directly.
//  This value CANNOT be bigger than the biggest control buffer size
//  (normally is 2K, on WCDMA project is 8K)
//  If you want to support larger record size, ex: 4K, Please follow the steps below
//
//  Step 1: modify the NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM to 8 (4K),  12 (6K) ....
//
//  Step 2: Need to add 2 bigger control buffer. The size is same as NVRAM_CUSTOM_CFG_MAX_RECORD_SIZE
//      In < custom\system\{project}\custom_config.c >
//      ctrl_buff_pool_info_g[9].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE4096+2;
//
//  Step 3: entend the system memory pool size
//      In < custom\system\{project}\custom_config.c >
//      static kal_uint32 System_Mem_Pool[(GLOBAL_MEM_SIZE+4096*2)/sizeof(kal_uint32)];
//
//  Step 4: rebuild custom nvram
//
//***************************************************************************
#define NVRAM_CUSTOM_CFG_MAX_RECORD_SIZE (NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM * NVRAM_RECORD_SECTOR_SIZE)

//***************************************************************************
// Config the default nvram lock status
// ex: #define NVRAM_CUSTOM_CFG_DEFAULT_LOCK_STATUS     (__LOCKED__)
// ex: #define NVRAM_CUSTOM_CFG_DEFAULT_LOCK_STATUS     (__UNLOCKED__)
//***************************************************************************
#define NVRAM_CUSTOM_CFG_DEFAULT_LOCK_STATUS    (__UNLOCKED__)

//***************************************************************************
// Configuration by each Application or User.
// Only for protocol layer or library use. If your ap belongs to MMI
// please use the app_id in mmi_res_range_def.h directly.
//
// App_id   : Application id
// Name rule: NVRAM_APP_[applition name]
// Action   : Use to class the data item to relate application
//
//***************************************************************************

#endif
