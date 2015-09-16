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
#ifndef CUSTOM_NVRAM_CONFIG_H
#define CUSTOM_NVRAM_CONFIG_H

#include "kal_general_types.h"
#include "nvram_config.h"
#include "nvram_enums.h"
#include "nvram_defs.h"


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
#if !defined(EMPTY_MMI)
#if defined(NEPTUNE_MMI)

#define NVRAM_APP_PHNSET NVRAM_APP_RESERVED

typedef enum
{
    NVRAM_APP_START = NVRAM_APP_RESERVED,
    NVRAM_APP_CAMERAPP,
    /* Add applition id above this */
    NVRAM_APP_TOTAL,
    NVRAM_APP_MAX = 65535
} nvram_restore_app_id_enum;

#define NVRAM_CACHE_ID_RESERVED    256

#else

typedef enum
{
    NVRAM_APP_START = NVRAM_APP_RESERVED,
    /* Add applition id above this */
    NVRAM_APP_TOTAL,
    NVRAM_APP_MAX = 65535   /* kal_uint16 */
}nvram_restore_app_id_enum;

#endif
#else   /*EMPTY_MMI*/
#define NVRAM_APP_PHNSET NVRAM_APP_RESERVED

typedef enum
{
    NVRAM_APP_START = NVRAM_APP_RESERVED,
    /* Add applition id above this */
    NVRAM_APP_TOTAL,
    NVRAM_APP_MAX = 65535   /* kal_uint16 */
}nvram_restore_app_id_enum;

#define NVRAM_CACHE_ID_RESERVED    256
#endif  /*EMPTY_MMI*/


//***************************************************************************
// External function for custom.lib
//***************************************************************************
extern kal_uint32 nvram_custom_max_clean_folder_size(void);
extern kal_uint32 nvram_custom_max_record_size(void);

extern nvram_lid_enum nvram_get_first_cust_lid(void);
extern nvram_lid_enum nvram_get_first_core_lid(void);
extern nvram_lid_enum nvram_get_last_core_lid(void);
extern nvram_lid_enum nvram_get_first_comm_lid(void);
extern nvram_lid_enum nvram_get_last_comm_lid(void);

#ifdef NEPTUNE_MMI
extern kal_uint16 nvram_get_total_byte(void);
extern kal_uint16 nvram_get_total_short(void);
extern kal_uint16 nvram_get_total_double(void);
#endif

extern kal_bool nvram_custom_lock_status(void);

#endif
