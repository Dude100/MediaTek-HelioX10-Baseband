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
 * nvram_main.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is main() function of NVRAM module/task. Should be called by generic task main
 *   function: stack_generic_layer_task() in task_main_func.c
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

#ifndef _NVRAM_MAIN_H
#define _NVRAM_MAIN_H

/* dsiable some VC compile warning */
#ifdef WIN32
/* warning C4996: 'strncpy': This function or variable may be unsafe. Consider using strncpy_s instead. */
/* warning C4996: '_vsnprintf': This function or variable may be unsafe. Consider using _vsnprintf_s instead. */
#pragma warning(disable : 4996)
#endif

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /*****************************************************************************
     *  Include
     ****************************************************************************/

    #include "kal_general_types.h"
    #include "kal_public_defs.h"
#include "kal_public_defs.h" //MSBB change     #include "stack_config.h"

    #include "nvram_config.h"
    #include "nvram_defs.h"
    #include "nvram_ltable.h"
    #include "custom_nvram_sec.h"
    #include "nvram_sec.h"
    #include "nvram_util.h"
    #include "nvram_drval_fat.h"
    #include "nvram_data_items.h"
    #include "nvram_lid_statistics.h"
    #include "nvram_multi_folder.h"
    #include "nvram_trc.h"
    #include "nvram_io.h"
    #include "nvram_errcode.h"
    #include "nvram_interface.h"

    /* Add pseudo merge headfile */
    #ifdef __NVRAM_PSEUDO_MERGE__
    #include "nvram_pseudo_merge.h"
    #endif

    #ifdef __NVRAM_COMPRESS_SUPPORT__
    #include "nvram_unzip.h"
    #endif

    #include "nvram_handler_startup.h"
    #include "nvram_handler_reset.h"
    #include "nvram_handler_read.h"
    #include "nvram_handler_write.h"
    #include "nvram_handler_tst.h"
    #include "nvram_msg_handler.h"
    #include "nvram_ilm.h"


    #include "nvram_internal.h"
    extern kal_uint32 nvram_custom_max_record_size(void);
    /*****************************************************************************
     *  Define
     ****************************************************************************/

    #define NVRAM_INVALID_VALUE      ~0
    #define NVRAM_EF_ZERO_DEFAULT_VALUE  0x00

    #define MAX_NVRAM_RECORD_SIZE nvram_custom_max_record_size()

    #define NVRAM_IS_LID_VALID(LID)          nvram_util_get_data_item(NULL, LID)

    /*****************************************************************************
     *  Typedef
     ****************************************************************************/

    typedef struct
    {
        nvram_state_enum state;
        kal_bool dev_broken;
        kal_bool lock;
        kal_uint8 secret_key[KEY_STREAM_LEN];
        kal_uint8 coded_version[NVRAM_EF_SYS_SIZE + 1];
        kal_uint8 old_coded_version[NVRAM_EF_SYS_SIZE + 1];
        kal_uint8 branch_version[NVRAM_EF_BRANCH_VERNO_SIZE + 1];
        kal_uint8 flavor_version[NVRAM_EF_FLAVOR_VERNO_SIZE + 1];
        kal_uint8 custpack_version[NVRAM_EF_CUSTPACK_VERNO_SIZE + 1];
        kal_uint16 secupack_version;
        kal_uint32 sw_status;
        ltable_type ltable;
    }nvram_context_type;


    /*****************************************************************************
     *  Global Function
     ****************************************************************************/

    extern nvram_context_type *nvram_ptr;

    extern void nvram_task_main(task_entry_struct *task_entry_ptr);
    extern void nvram_write_imei_handler(ilm_struct *ilm_ptr);

    /* This function prototype is the sublayer entry function. */
    extern void nvram_main(ilm_struct *ilm_ptr);
    extern kal_bool nvram_init(void);
    extern kal_bool nvram_reset(void);

    extern void nvram_get_code_file_size(kal_uint32 *CodeFileSizeTotal);

    extern void nvram_create_first_bootup_log(kal_char *prefix);
    extern kal_bool nvram_check_first_bootup_log(kal_char *prefix);
    extern void nvram_delete_first_bootup_log(kal_char *prefix);

    /* This function is for unit test */
    extern kal_int32 nvram_unit_test_get_io_status(kal_int32 status);
    extern kal_int32 nvram_unit_test_get_drv_status(kal_int32 status);
    extern kal_bool nvram_unit_test(void);

    extern kal_bool nvram_write_system_record(nvram_lock_state_enum lock_state);
    extern kal_int32 nvram_access_sds(nvram_sds_access_enum access_mode);

    extern nvram_ltable_entry_struct *logical_data_item_table;
#ifdef __cplusplus
}
#endif

#endif /* _NVRAM_MAIN_H */

